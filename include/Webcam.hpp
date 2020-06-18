#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <vector>

#include "Gesture.hpp"

class Webcam {

public:
    Webcam(std::string t, unsigned int cam_id);
    virtual ~Webcam();
    // void setGesture(std::vector<cv::Mat> other);
    void addGesture();
    Gesture getGesture(int number);
    std::vector<Gesture> getGestures();

    cv::Mat getFrame();


    void update();
    void record();
    void showGesture(int number, int index);
private:
    std::string title;
    cv::VideoCapture stream;
    cv::Mat frame;
    Gesture temp;
    std::vector<Gesture> gestures;
};