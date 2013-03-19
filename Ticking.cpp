/*
 * Ticking library - Arduino library to execute a function every X ticks.
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

#include "Ticking.h"

/**
 * Initialize a Ticking instance, with a callback and the number of ticks
 * on which it's called. If autoStart is set to true (default), the object
 * is active and any call to its 'tick' method will increment the 'ticks' counter.
 */
Ticking::Ticking(void (*cb)(), unsigned long int runAt_, boolean autoStart) {
  runAt = runAt_;
  running = false;
  callback = cb;
  reset();
  if (autoStart) {
    start();
  }
}


/**
 * Reset the ticks.
 */
void Ticking::reset() {
  ticks = 0;
}


/**
 * From now on, consider any following
 * call to the 'tick' method.
 */
void Ticking::start(boolean alsoReset) {
  if (alsoReset) {
    reset();
  }
  running = true;
}


/**
 * Stop incrementing the 'ticks' counter.
 */
void Ticking::stop() {
  running = false;
}


/**
 * Increment the 'ticks' counter; if the value
 * specified at initialization is reached, run
 * the given callback.
 */
void Ticking::tick() {
  if (!running) {
    return;
  }
  ticks += 1;
  if (ticks >= runAt) {
    ticks = 0;
    if (callback) {
      callback();
    }
  }
}

