#include "common.hpp"
#include "Webcam.hpp"
using namespace cv;
using namespace std;


int main()
{
    int i = 0;
    int j = 0;
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
            webcam.addGesture();
            j++;
            break;
        case static_cast<int>('x'):
            running = false;
            break;
        default:
            auto gesture = webcam.getGesture(j);
            if(gesture.getSize() != 0 && i < gesture.getSize())
                webcam.showGesture(j, i);
            if(i < gesture.getSize())
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