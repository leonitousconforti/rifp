// Opencv header file
#include <opencv2/opencv.hpp>

// Our header files
#include "utils.hpp"

int main(int argc, char **argv)
{
    // Init objects
    utils::FpsCounter fps;
    utils::GstreamerPipeline GSpipeline("nvarguscamerasrc");
    utils::MJPEGStreamer MjpegStreamer(8080);

    // Setup pipeline
    GSpipeline.setStreamerSettings(utils::streamerSourceParams);
    // Add nvvidconv source and sink and videoconvert source and sink
    GSpipeline.addElement(utils::nvvidconvSink, utils::nvvidconvSource);
    GSpipeline.addElement(utils::videoconvertSink, utils::videoconvertSource);
    GSpipeline.addSink("queue ! appsink");

    // Init opencv capture
    cv::VideoCapture cap(GSpipeline.getPipelineString(), cv::CAP_GSTREAMER);

    // Start streamer
    MjpegStreamer.start();

    if (!cap.isOpened())
    {
        std::cerr << "Failed to open camera" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Local variables
    cv::Mat frame;
    unsigned int lastFrameEncodingTime = 0;
    std::vector<uchar> buff_bgr;
    std::vector<int> params = {cv::IMWRITE_JPEG_QUALITY, 60};

    // Image processing loop
    while (true)
    {
        // Read a frame
        cap >> frame;
        if (frame.empty())
        {
            std::cerr << "Frame not grabbed" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Calculate fps
        fps.update();

        // Do this one time a second
        if (fps.getFrameCount() % 20 == 0)
        {
            // Draw a smaller rectangle overlay
            frame = utils::drawingOverlays::drawRect(
                frame, utils::capture_width * 0.25,
                utils::capture_height * 0.25, utils::capture_width * 0.5,
                utils::capture_height * 0.5);

            // Add marker at center
            frame = utils::drawingOverlays::addCross(
                frame, utils::capture_width / 2, utils::capture_height / 2, 20);

            // Display fps
            std::string t_fps = "FPS: " + std::to_string(fps.get()) + ", " +
                                std::to_string(1000 / fps.get()) + "ms";
            frame = utils::drawingOverlays::drawText(frame, 30, 30, t_fps);

            // Display frame encoding time
            std::string t_fet =
                "FET: " + std::to_string(lastFrameEncodingTime) +
                "ms, QUALITY: " + std::to_string(params[1]) + "%";
            frame = utils::drawingOverlays::drawText(frame, 30, 53, t_fet);

            // Time the encoding process
            utils::Interval encodingInterval;

            // Encode image for streamer
            cv::imencode(".jpg", frame, buff_bgr, params);
            lastFrameEncodingTime = encodingInterval.value();

            // Publish frame after processing
            MjpegStreamer.publish(
                "/", std::string(buff_bgr.begin(), buff_bgr.end()));

            // Visit /shutdown to break from the loop and graceful shutdown
            if (MjpegStreamer.shutdownFromBrowser())
            {
                MjpegStreamer.stop();
                break;
            }
        }
    }

    // Cleanup
    cap.release();
    return 0;
}
