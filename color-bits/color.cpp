/* Copyright 2019 Pierre Lefebvre

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */


#include "color.hpp"


void color::to_greyscale()
{
  // Compute the mean color
  unsigned int grey =
    (((channels >> 24) & 0xFF) +
     ((channels >> 16) & 0xFF) +
     ((channels >> 8 ) & 0xFF)) / 3;

  // Zero all channels but alpha value
  channels &= 0x000000FF;

  // Update all channels
  channels |= (grey << 24); // red
  channels |= (grey << 16); // green
  channels |= (grey << 8);  //  blue
}
