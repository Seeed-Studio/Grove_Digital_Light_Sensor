/*
 * Digital_Light_Sensor_v2.ino
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

#include <Wire.h>
#include "Digital_Light_ISL29035.h"

void setup() {
  Wire.begin();
  Serial.begin(9600);

  if(ISL29035.init() < 0)
    Serial.println("ISL29035 init failed!");

  /**
   * Set the full scale range for lux measurement.
   * A lower range offers better resolution, it's suitable in a dim env,
   * while in light env, a higher range should be selected.
   * 0: 1000 lux, 1: 4000 lux, 2: 16000 lux, 3: 64000 lux
   * default index is 0.
   */
//  ISL29035.setFullScaleLuxRangeIndex(DEFAULT_LUX_RANGE_INDEX);
  /**
   * Set the integration time.
   * 0: 105ms, 1: 6.5ms, 2: 0.41ms, 3: 0.0256
   * default index is 0.
   */
//  ISL29035.setIntegrationTimeIndex(DEFAULT_INTEGRATION_TIME_INDEX);

  /**
   * The integration time is a trade-off between speed and accuracy.
   * Fast integration however gains lower resolution of ADC.
   */
}

void loop() {
  Serial.println("----");
  Serial.print("Ambient light intensity: ");
  Serial.println(ISL29035.readVisibleLux());

  Serial.print("IR intensity: ");
  Serial.println(ISL29035.readIRLux());

  Serial.print("Exposure value: ");
  Serial.println(ISL29035.readEV());

  delay(1000);
}



