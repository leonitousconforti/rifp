/*
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

#include <opencv2/core/mat.hpp>
#include <string>

#pragma once

namespace modules
{

namespace drawing_overlays_module
{

cv::Mat drawRect(cv::Mat img, int x, int y, int w, int h)
{
    cv::Rect rect(x, y, w, h);
    cv::rectangle(img, rect, cv::Scalar(0, 255, 0));
    return img;
}

cv::Mat drawText(cv::Mat img, int x, int y, std::string msg)
{
    cv::Point pt_loc(x, y);
    cv::putText(img, msg, pt_loc, cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8,
                cv::Scalar(0, 200, 250), 1, cv::LINE_AA);
    return img;
}

cv::Mat addCross(cv::Mat img, int x, int y, int m_size)
{
    cv::Point pt_loc(x, y);
    cv::drawMarker(img, pt_loc, cv::Scalar(255, 255, 255), cv::MARKER_CROSS,
                   m_size, 1, 8);
    return img;
}

} // namespace drawing_overlays_module

} // namespace modules
