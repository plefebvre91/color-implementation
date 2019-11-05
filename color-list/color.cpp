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


color::color()
{
  // Initialize red channel
  red.value = 0;

  // Initialize green channel
  red.next_channel = new channel();
  red.next_channel->value = 0;

  // Initialize blue channel
  red.next_channel->next_channel = new channel();
  red.next_channel->next_channel->value = 0;

  // Initialize alpha channel
  red.next_channel->next_channel->next_channel = new channel();
  red.next_channel->next_channel->next_channel->value = 0;
}


void color::to_greyscale()
{
  // Compute the mean color
  unsigned int grey = red.value;
  grey += red.next_channel->value;
  grey += red.next_channel->next_channel->value;
  grey /= 3;

  // Update all channels
  red.value = grey;
  red.next_channel->value = grey;
  red.next_channel->next_channel->value = grey;
}


color::~color()
{
  delete red.next_channel->next_channel->next_channel;
  delete red.next_channel->next_channel;
  delete red.next_channel;
}
