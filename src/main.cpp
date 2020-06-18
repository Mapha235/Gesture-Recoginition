#include "common.hpp"
using namespace cv;
using namespace std;


int main()
{
    int i = 0;
    bool running = true;
    bool aKeyPressed = false;

    Webcam webcam("Webcam", 0);

    while (running) {
        webcam.update();
        auto key = waitKey(30);

        switch (key) {
        case static_cast<int>('a'):
            aKeyPressed = true;
            cout << "KEY A" << endl;
            break;
        case static_cast<int>('s'):
            aKeyPressed = false;
            cout << "KEY S" << endl;
            break;
        case static_cast<int>('x'):
            running = false;
            break;
        default:        
            auto gesture = webcam.getGesture(0);
            if(gesture.size() != 0 && i < gesture.size())
                webcam.showGesture(0, i);
            if(i < gesture.size())
                i++;
            else
                i = 0;
            break;
        }

        if (aKeyPressed)
            webcam.capture();
    }

    return 0;
}