/*
 * Ticker library - Arduino library to execute a function every X ticks.
 *
 * Copyright (c) 2013 Davide Alberani <da@erlug.linux.it>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 */


#include "Ticker.h"

Ticker::Ticker(void (*cb)(), unsigned long int runAt_, boolean autoStart) {
  runAt = runAt_;
  running = false;
  callback = cb;
  reset();
  if (autoStart) {
    start();
  }
}

void Ticker::reset() {
  ticks = 0;
}

void Ticker::start(boolean alsoReset) {
  if (alsoReset) {
    reset();
  }
  running = true;
}

void Ticker::stop() {
  running = false;
}

void Ticker::tick() {
  if (!running) {
    return;
  }
  ticks += 1;
  if (ticks >= runAt) {
    Serial.println("EEEEEEEEEE: " + ticks);
    ticks = 0;
    if (callback) {
      callback();
    }
  }
}


