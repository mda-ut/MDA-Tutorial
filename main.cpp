#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(){
    Mat image = imread("img.jpg");
    Mat new_image = Mat::zeros(image.size(), image.type());

    /// Create Windows
    namedWindow("Control", WINDOW_AUTOSIZE); //create a window called "Control"
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    namedWindow("New Image", WINDOW_AUTOSIZE);

    /// Move Windows, not required
    moveWindow("New Image", 900, 0);
    moveWindow("Control", 1200, 800);

    /// Create the variables and control panels
    int ialpha = 100;   //random value of 100; can be anything from 0-300
    int beta = 50;      //random value of 50

    //creates the slider bars on the Control window
    cvCreateTrackbar("Contrast", "Control", &ialpha, 300); //alpha from 0-300
    cvCreateTrackbar("Brightness", "Control", &beta, 100); //beta from 0-100

    bool run = true;
    while (run){
        //converts the intger alpha to the float alpha; convert 0-300 to 0-3
        float alpha = ialpha / 100.0f;

        /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
        for( int y = 0; y < image.rows; y++ ){
            for( int x = 0; x < image.cols; x++ ){
                for( int c = 0; c < 3; c++ ){
                    new_image.at<Vec3b>(y,x)[c] =
                        saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
                }
            }
        }

        /// Show stuff
        imshow("Original Image", image);
        imshow("New Image", new_image);
        //wait for a key press every 33ms -> ~30fps
        int key = waitKey(33);
        //if the key is esc, stop the program
        if (key == 27){
            run = false;
        }
    }
    return 0;
}
