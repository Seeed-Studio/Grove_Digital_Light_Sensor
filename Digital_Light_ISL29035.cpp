/*
 * Digital_Light_ISL29035.cpp
 * A library for ISL29035
 *
 * Copyright (c) 2017 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Jack
 * Create Time:
 * Change Log :  
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <Digital_Light_ISL29035.h>
#include <Wire.h>

DigitalLightISL29035::DigitalLightISL29035():
  _full_scale_lux_range(DEFAULT_LUX_RANGE_INDEX),
  _integration_time(DEFAULT_INTEGRATION_TIME_INDEX)
{
  _adc_count_max[0] = 65536;
  _adc_count_max[1] = 4096;
  _adc_count_max[2] = 256;
  _adc_count_max[3] = 16;

  _intg_time[0] = INTEGRATION_TIME0;
  _intg_time[1] = INTEGRATION_TIME1;
  _intg_time[2] = INTEGRATION_TIME2;
  _intg_time[4] = INTEGRATION_TIME3;

  _ranges[0] = FULL_SCALE_LUX_RANGE0;
  _ranges[1] = FULL_SCALE_LUX_RANGE1;
  _ranges[2] = FULL_SCALE_LUX_RANGE2;
  _ranges[3] = FULL_SCALE_LUX_RANGE3;
}

uint8_t DigitalLightISL29035::readRegister(int device_address, int reg_address)
{
  uint8_t value;
  Wire.beginTransmission(device_address);
  Wire.write(reg_address);
  Wire.endTransmission(false);
  Wire.requestFrom(device_address, 1);
  //while(!Wire.available());
  value = Wire.read();
  return value;
}

void DigitalLightISL29035::writeRegister(int device_address, int reg_address, uint8_t val)
{
  Wire.beginTransmission(device_address); 
  Wire.write(reg_address); 
  Wire.write(val);
  Wire.endTransmission();
}

int DigitalLightISL29035::init()
{
  uint8_t reg = readRegister(ISL29035_I2C_ADDRESS, CHIP_ID);
  //Serial.println(reg, HEX);
  uint8_t chip_id = (reg >> 3) & 0x7;
  if (chip_id != 0x5) return -1;

  //clear the BOUT bit
  writeRegister(ISL29035_I2C_ADDRESS, CHIP_ID, reg & 0x7f);

  //ensure the chip is under stop mode
  writeRegister(ISL29035_I2C_ADDRESS, COMMAND_I, 0);
  
  //set the default full scale lux range, and the integration time
  writeRegister(ISL29035_I2C_ADDRESS, COMMAND_II, _full_scale_lux_range|(_integration_time<<2));

  return 0;
}

int DigitalLightISL29035::setFullScaleLuxRangeIndex(int range_index)
{
  if(range_index < 0 || range_index > 3)
    return -1;
  _full_scale_lux_range = range_index;
  writeRegister(ISL29035_I2C_ADDRESS, COMMAND_II, _full_scale_lux_range|(_integration_time<<2));

  return 0;
}

int DigitalLightISL29035::setIntegrationTimeIndex(int intg_time_index)
{
  if(intg_time_index < 0 || intg_time_index > 3)
    return -1;
  _integration_time = intg_time_index;
  writeRegister(ISL29035_I2C_ADDRESS, COMMAND_II, _full_scale_lux_range|(_integration_time<<2));

  return 0;
}

void DigitalLightISL29035::test()
{
#if 0
  uint8_t value;
  Wire.beginTransmission(ISL29035_I2C_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(ISL29035_I2C_ADDRESS, 8);
  while(!Wire.available());
  for(int i=0;i<8;i++)
  {
    Serial.print("reg ");
    Serial.print(i);
    Serial.print(": 0x");    
    Serial.println(Wire.read(), HEX);
  }
  value = readRegister(ISL29035_I2C_ADDRESS, CHIP_ID);
  Serial.print("reg 0xf: 0x");    
  Serial.println(value, HEX);
#endif
}


uint16_t DigitalLightISL29035::readData()
{
  uint8_t l,h;
  Wire.beginTransmission(ISL29035_I2C_ADDRESS);
  Wire.write(DATA_L);
  Wire.endTransmission(false);
  Wire.requestFrom(ISL29035_I2C_ADDRESS, 2);
  while(Wire.available()<2);
  l = Wire.read();
  h = Wire.read();

  return (h << 8) | l; 
}

uint16_t DigitalLightISL29035::measure(uint8_t what)
{
  //start
  writeRegister(ISL29035_I2C_ADDRESS, COMMAND_I, what);
  float time = _intg_time[_integration_time];
  if(time < 1.0f)
  {
    delayMicroseconds((int)(time * 1000));
  }else
  {
    delay((int)(time+1.5f));
  }
  uint16_t data = readData();
  //stop
  writeRegister(ISL29035_I2C_ADDRESS, COMMAND_I, 0);
  return data;
}

uint32_t DigitalLightISL29035::readVisibleLux()
{
  uint16_t data = measure(OPMODE_ALS_ONCE);
  return ((uint32_t)_ranges[_full_scale_lux_range]) * (uint32_t)data / _adc_count_max[_integration_time];
}

uint32_t DigitalLightISL29035::readIRLux()
{
  uint16_t data = measure(OPMODE_IR_ONCE);
  return ((uint32_t)_ranges[_full_scale_lux_range]) * (uint32_t)data / _adc_count_max[_integration_time];
}

int32_t DigitalLightISL29035::readEV()
{
  uint16_t data1 = measure(OPMODE_ALS_ONCE);
  uint16_t data2 = measure(OPMODE_IR_ONCE);

  float k = 0.82;
  float beta = -11292.86f;
  if(_integration_time > 1) beta = 2137.14f;
  return (int32_t)(k*data1 + data2/beta);
}


DigitalLightISL29035 ISL29035;


