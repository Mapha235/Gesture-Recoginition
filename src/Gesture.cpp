#include "Gesture.hpp"


Gesture::Gesture(){}

Gesture::Gesture(std::vector<cv::Mat> ges) : gesture(ges){

}

Gesture::~Gesture() {

}

void Gesture::setGesture(std::vector<cv::Mat> other) {
    gesture = other;
}

std::vector<cv::Mat> Gesture::getGesture(){
    return gesture;
}

cv::Mat Gesture::getFrame(unsigned int index) {
    return gesture[index];
}

void Gesture::push_frame(cv::Mat frame) {
    // Make a deep copy of the frame 
    cv::Mat copy = frame.clone();
    gesture.push_back(copy);    
}

int Gesture::getSize(){
    return gesture.size();
}