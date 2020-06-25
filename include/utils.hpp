#pragma once

#include <string>
#include <vector>

#include "modules/cam_fps_module.hpp"
#include "modules/gstreamer_pipelines_module.hpp"
#include "modules/mjpeg_streamer_module.hpp"

namespace utils
{

// Global recording variables
constexpr int capture_width{1280};
constexpr int capture_height{720};
constexpr int framerate{120};
constexpr int flip_method{0};

// GStreamer pipeline settings
const std::vector<std::string> streamerSourceParams =
{
    "video/x-raw(memory:NVMM)",
    "width=(int)" + std::to_string(capture_width),
    "height=(int)" + std::to_string(capture_height),
    "format=(string)NV12",
    "framerate=(fraction)" + std::to_string(framerate) + "/1"
};
const std::string nvvidconvSink = "nvvidconv flip-method=" + std::to_string(flip_method);
const std::string nvvidconvSource = "video/x-raw, format=(string)BGRx";
const std::string videoconvertSink = "videoconvert";
const std::string videoconvertSource = "video/x-raw, format=(string)BGR";

// Using declaractions
using FpsCounter = modules::fps_counter_module;
using GstreamerPipeline = modules::gstreamer_pipelines_module;
using MJPEGStreamer = modules::MJPEG_streamer_module;

} // namespace utils
