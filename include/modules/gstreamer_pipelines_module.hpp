/*
C++ library for creating opencv compatible gstreamer pipelines
https://github.com/leonitousconforti/cpp-gstreamer-pipelines

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

#include <string>
#include <vector>

namespace modules
{

// Class for creating gstreamer pipelines
class gstreamer_pipelines_module
{
  public:
    gstreamer_pipelines_module(std::string inputSource);
    virtual ~gstreamer_pipelines_module();
    std::string getPipelineString();

    void setStreamerSettings(std::vector<std::string> settings);
    void addSink(std::string sink);
    void addSource(std::string source);
    void addElement(std::string sink, std::string source);

  private:
    std::string pipeline = "";
};

gstreamer_pipelines_module::gstreamer_pipelines_module(std::string inputSource)
{
    pipeline.append(inputSource);
}

gstreamer_pipelines_module::~gstreamer_pipelines_module() {}

std::string gstreamer_pipelines_module::getPipelineString()
{
    return pipeline;
}

void gstreamer_pipelines_module::setStreamerSettings(
    std::vector<std::string> settings)
{
    std::string params = "";
    for (const auto &piece : settings)
        params += (piece + ", ");

    params.pop_back();
    params.pop_back();
    addSource(params);
}

void gstreamer_pipelines_module::addSink(std::string sink)
{
    // pipeline.append((const char[4]) " ! ");
    pipeline.append(" ! ");
    pipeline.append(sink);
}

void gstreamer_pipelines_module::addSource(std::string source)
{
    // pipeline.append((const char[4]) " ! ");
    pipeline.append(" ! ");
    pipeline.append(source);
}

void gstreamer_pipelines_module::addElement(std::string sink,
                                            std::string source)
{
    addSink(sink);
    addSource(source);
}

} // namespace modules
