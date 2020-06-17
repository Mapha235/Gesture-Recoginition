#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <vector>

using namespace std;

class Webcam {

public:
    Webcam(std::string t, unsigned int cam_id);
    virtual ~Webcam();
    void setGesture(std::vector<cv::Mat> other);
    std::vector<cv::Mat> getGesture(int number);

    void update();
    void capture();
    void showGesture(int number, int index);
private:
    std::string title;
    cv::VideoCapture stream;
    cv::Mat frame;
    std::vector<cv::Mat> gesture;
};