#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <windows.h>
using namespace cv;
using namespace std;

int main()
{
    VideoCapture webcamStream(0); //0 is the id of video device.0 if you have only one camera.

    if (!webcamStream.isOpened()) { //check if video device has been initialised
        cout << "cannot open camera";
    }

    //HMMMMMMMMMmmmmm
    Mat frame;
    webcamStream >> frame;

    vector<Mat> gesture;
    gesture.push_back(frame);

    int i = 0;
    bool running = true;
    bool aKeyPressed = false;
    while (running) {
        Mat cameraFrame;
        webcamStream.read(cameraFrame);
        imshow("Webcam", cameraFrame);
        auto key = waitKey(30);

        switch (key) {
        case 97: // A-key
            aKeyPressed = true;
            break;
        case 115: // S-key
            aKeyPressed = false;
            break;
        case 120: // X-key
            cout << gesture.size() << endl;
            running = false;
            break;
        default:
            if (gesture.size() != 0)
                imshow("Gesture", gesture.at(i));
            if (i < gesture.size() - 1)
                i++;
            else
                i = 0;
            break;
        }
        // 122
        // z y x w v t s
        if (aKeyPressed)
            gesture.push_back(cameraFrame);
    }
    return 0;
}