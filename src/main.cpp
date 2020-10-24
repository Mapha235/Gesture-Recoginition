#include "Webcam.hpp"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

#include "common.hpp"
using namespace cv;
using namespace std;

cv::Mat getSkin(cv::Mat input)
{
    int Y_MIN  = 0;
    int Y_MAX  = 255;
    int Cr_MIN = 133;
    int Cr_MAX = 173;
    int Cb_MIN = 77;
    int Cb_MAX = 127;
    cv::Mat skin;
    //first convert our RGB image to YCrCb
    cv::cvtColor(input,skin,cv::COLOR_BGR2YCrCb);

    //uncomment the following line to see the image in YCrCb Color Space
    //cv::imshow("YCrCb Color Space",skin);

    //filter the image in YCrCb color space
    cv::inRange(skin,cv::Scalar(Y_MIN,Cr_MIN,Cb_MIN),cv::Scalar(Y_MAX,Cr_MAX,Cb_MAX),skin);

    return skin;
}

int main()
{
    int i = 0;
    int j = 0;
    bool running = true;
    bool aKeyPressed = false;

    cv::Mat bg, diffImage, hand, foregroundMask, skinMask;
    float threshold, dist;

    Webcam webcam("Webcam", 0);

    while (running) {
        cv::Ptr<cv::BackgroundSubtractor> pBackSub;
        webcam.update();
        auto key = waitKey(30);
        switch (key) {
        case static_cast<int>('a'):
            aKeyPressed = true;
            cout << "KEY A" << endl;
            break;
        case static_cast<int>('s'):
            cout << "KEY S" << endl;
            if (aKeyPressed) {
                webcam.addGesture();
                j++;
            }
            webcam.getGesture(j).saveBackground(webcam.getFrame());
            aKeyPressed = false;
            break;
        case static_cast<int>('x'):
            running = false;
            break;
        case static_cast<int>('y'):
            webcam.generateBgModel();
            webcam.showBgModel();
            break;
        default:
            auto gesture = webcam.getGesture(j); // deep copy 
            if (gesture.getSize() != 0 && i < gesture.getSize()) 
                webcam.showGesture(j, i);
            if (i < gesture.getSize())
                i++;
            else
                i = 0;
            break;
        }

        if (aKeyPressed)
            webcam.record();
    }

    return 0;
}