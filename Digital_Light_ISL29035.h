/*
 * Digital_Light_ISL29035.h
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
#ifndef Digital_Light_ISL29035_H
#define Digital_Light_ISL29035_H

#include <Arduino.h>

#define ISL29035_I2C_ADDRESS    0x44   //the 7bits i2c address

#define COMMAND_I               0x00
#define COMMAND_II              0x01
#define DATA_L                  0x02
#define DATA_H                  0x03
#define INT_LT_L                0x04
#define INT_LT_H                0x05
#define INT_HT_L                0x06
#define INT_HT_H                0x07
#define CHIP_ID                 0x0f

#define OPMODE_ALS_ONCE         ((0x1)<<5)
#define OPMODE_IR_ONCE          ((0x2)<<5)
#define OPMODE_ALS_CONTI        ((0x5)<<5)
#define OPMODE_IR_CONTI         ((0x6)<<5)

#define FULL_SCALE_LUX_RANGE0   1000
#define FULL_SCALE_LUX_RANGE1   4000
#define FULL_SCALE_LUX_RANGE2   16000
#define FULL_SCALE_LUX_RANGE3   64000
#define DEFAULT_LUX_RANGE_INDEX 1       //should be [0,3]

#define INTEGRATION_TIME3       0.0256  //ms, this also configure the ADC to 4bits
#define INTEGRATION_TIME2       0.41  //ms, this also configure the ADC to 8bits
#define INTEGRATION_TIME1       6.5  //ms, this also configure the ADC to 12bits
#define INTEGRATION_TIME0       105  //ms, this also configure the ADC to 16bits
#define DEFAULT_INTEGRATION_TIME_INDEX 1  //should be [0,3]

class DigitalLightISL29035
{
public:
  DigitalLightISL29035();

  int init(void);
  /**
   * Set the full scale range for lux measurement.
   * A lower range offers better resolution, it's suitable in a dim env,
   * while in light env, a higher range should be selected.
   * 0: 1000 lux, 1: 4000 lux, 2: 16000 lux, 3: 64000 lux
   * default index is 0.
   */
  int setFullScaleLuxRangeIndex(int range_index);

  /**
   * Set the integration time.
   * 0: 105ms, 1: 6.5ms, 2: 0.41ms, 3: 0.0256
   * default index is 0.
   */
  int setIntegrationTimeIndex(int intg_time_index);

  /**
   * This sensor has builtin IR rejection when measuring ambient light.
   */
  uint32_t readVisibleLux();
  uint32_t readIRLux();
  int32_t readEV();

  void test();
  
private:
  uint8_t _full_scale_lux_range;
  uint8_t _integration_time;
  uint32_t _adc_count_max[4];
  float   _intg_time[4];
  uint32_t _ranges[4];

  uint8_t readRegister(int deviceAddress, int address);
  void writeRegister(int deviceAddress, int address, uint8_t val);
  uint16_t readData();
  uint16_t measure(uint8_t what);

 };
extern DigitalLightISL29035  ISL29035;
#endif


