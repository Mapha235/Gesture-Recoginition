#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <vector>

class Gesture {

public:
    Gesture();
    Gesture(std::vector<cv::Mat> ges);
    ~Gesture();
    void setGesture(std::vector<cv::Mat> other);

    // @return current frame
    cv::Mat getFrame(unsigned int index);

    std::vector<cv::Mat> getGesture();
    void pushFrame(cv::Mat frame);
    int getSize();

    void saveBackground(cv::Mat frame);

    void detectEdges();
private:
    std::vector<cv::Mat> gesture;
    cv::Mat bg;
};