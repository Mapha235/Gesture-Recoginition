#include "Webcam.hpp"

using namespace cv;
using namespace std;

Webcam::Webcam(std::string t, unsigned int cam_id) : title(t)
{
    stream = VideoCapture(cam_id);
    gestures.push_back(Gesture());
}

Webcam::~Webcam()
{
}

// void Webcam::setGesture(std::vector<Mat> other){
//     gestures = other;
// }

void Webcam::addGesture(){
    gestures.push_back(temp);
    temp = Gesture();
}

Gesture Webcam::getGesture(int number){
    try
    {
        return gestures.at(number);
        
    }
    catch(const std::exception& e)
    {
        std::vector<cv::Mat> temp = {frame};
        return Gesture(temp);
    }
    
}

std::vector<Gesture> Webcam::getGestures(){
    return gestures;
}

cv::Mat Webcam::getFrame(){
    return frame;
}


void Webcam::update()
{
    stream >> frame;
    imshow(title, frame);
}

void Webcam::record()
{
    temp.push_frame(frame);
    // gestures.at(number).push_frame(frame);
}

void Webcam::showGesture(int number, int index) {
    imshow("Gesture", gestures[number].getFrame(index));
}