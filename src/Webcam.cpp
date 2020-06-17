#include "Webcam.hpp"

using namespace cv;
using namespace std;

Webcam::Webcam(std::string t, unsigned int cam_id) : title(t)
{
    stream = VideoCapture(cam_id);
}

Webcam::~Webcam()
{
}

void Webcam::setGesture(std::vector<Mat> other){
    gesture = other;
}
std::vector<Mat> Webcam::getGesture(int number){
    return gesture;
}

void Webcam::update()
{
    stream >> frame;
    // stream.read(frame);
    imshow(title, frame);
}

void Webcam::capture()
{
    // Make a deep copy of the frame 
    Mat copy = frame.clone();
    gesture.push_back(copy);
}

void Webcam::showGesture(int number, int index) {
    imshow("Gesture", gesture[index]);
}