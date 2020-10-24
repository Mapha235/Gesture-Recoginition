#include "Webcam.hpp"

using namespace cv;
using namespace std;

Webcam::Webcam(std::string t, unsigned int cam_id)
    : title(t)
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

void Webcam::addGesture()
{
    // current_gesture.detectEdges();
    gestures.push_back(current_gesture);
    current_gesture = Gesture();
}

Gesture Webcam::getGesture(int number)
{
    try {
        return gestures.at(number);

    } catch (const std::exception& e) {
        std::vector<cv::Mat> current_gesture = { current_frame };
        return Gesture(current_gesture);
    }
}

std::vector<Gesture> Webcam::getGestures()
{
    return gestures;
}

cv::Mat Webcam::getFrame()
{
    return current_frame.clone();
}

void Webcam::update()
{
    stream >> current_frame;
    imshow(title, current_frame);
}

void Webcam::record()
{
    current_gesture.pushFrame(current_frame);
    // gestures.at(number).push_frame(current_frame);
}

void Webcam::showGesture(int number, int index)
{
    Gesture current;

    for (int i = 1; i <= number; i++) {
        std::string title = "Gesture";
        title.append(std::to_string(i));
        current = gestures[i];
        if (index < current.getSize()) {
            // current.detectEdges(index);
            imshow(title, current.getFrame(index));
        }
    }
}

void Webcam::recordBg(){
    
}

void Webcam::showBgModel(){
    imshow("BG Model", bg_model);
}

void Webcam::generateBgModel(){
    Gesture bg_video = gestures.at(1);
    std::vector<unsigned char> mean;
    for(int frame_nr = 0; frame_nr < bg_video.getSize(); frame_nr++){
        auto frame = bg_video.getFrame(frame_nr);

        for(int row = 0; row < frame.rows; row++){
            for(int col = 0; col < frame.cols; col++){
                mean.push_back(frame.at<unsigned char>(row,col));
            }
        }
    }
}
