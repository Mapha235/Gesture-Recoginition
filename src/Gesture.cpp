#include "Gesture.hpp"
#include <iostream>

Gesture::Gesture() {}

Gesture::Gesture(std::vector<cv::Mat> ges)
    : gesture(ges)
{
}

Gesture::~Gesture()
{
}

void Gesture::setGesture(std::vector<cv::Mat> other)
{
    gesture = other;
}

std::vector<cv::Mat> Gesture::getGesture()
{
    return gesture;
}

cv::Mat Gesture::getFrame(unsigned int index)
{
    return gesture[index];
}

void Gesture::pushFrame(cv::Mat frame)
{
    // Make a deep copy of the frame
    cv::Mat copy = frame.clone();
    gesture.push_back(copy);
}

int Gesture::getSize()
{
    return gesture.size();
}

void Gesture::detectEdges(int index)
{
    for (auto it = gesture.begin(); it != gesture.end(); ++it) {
        cv::cvtColor(*it, *it, cv::COLOR_BGR2GRAY);
        blur(*it, *it, cv::Size(3, 3));
        double threshold = 10;
        cv::Canny(*it, *it, threshold, 3 * threshold);
    }
}