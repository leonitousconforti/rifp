/*
C++ library for calculating the fps/time for an event to run
https://github.com/leonitousconforti/cpp-fps-counter

MIT License

Copyright (c) 2020 leo Conforti

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <chrono>
#include <ctime>

namespace modules
{

class Interval
{
  private:
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::duration<float> fsec;
    std::time_t initial_;

  public:
    inline Interval() : initial_(std::time(0)) {}
    virtual ~Interval() {}
    inline unsigned int value() const
    {
        return std::time(0) - initial_;
    }
};

class fps_counter_module
{
  protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    Interval m_fpsinterval;

  public:
    fps_counter_module() : m_fps(0), m_fpscount(0) {}

    void update()
    {
        // increase the counter by one
        m_fpscount++;

        // one second elapsed?
        if (m_fpsinterval.value() >= 1)
        {
            // save the current counter value to m_fps
            m_fps = m_fpscount;

            // reset the counter and the interval
            m_fpscount = 0;
            m_fpsinterval = Interval();
        }
    }

    unsigned int get() const
    {
        return m_fps;
    }

    unsigned int getFrameCount() const
    {
        return m_fpscount;
    }
};

} // namespace modules
