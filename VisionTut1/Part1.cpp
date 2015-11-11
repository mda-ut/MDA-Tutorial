
/**
 * MDA Vision Tutorial 1: Brightness and Contrast controls
 * Part 1: Showing an image
 *
 * This series is based off of OpenCV's own tutorial 
 *      http://docs.opencv.org/2.4/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html
 *
 * James Lu
 */


/*
 * We want to include the OpenCV libaries that we are going to use
 */
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>


//We want to use the namespace cv so we dont have to type out cv::func() every time
using namespace cv;

int main()
{
	/*
	 * OpenCV uses soemthing called "Mat" to store images
	 * They describe it as "an n-dimensional dense numerical single-channel or multi-channel array"
	 * We make a Mat called image, and we use the imread() function to load an image called "cat.jpg"
	 * 		you can change this to whatever your image file is called
     * Note: Your image file has to be in the same folder as your EXECUTABLE, not your source file
	 */
    Mat image = imread("cat.jpg");


    /*
     * We use the namedWindow() function to make a window to show the image
     *  	We call the window "Image", and tell it to auto size according to the image shown
     */
    namedWindow("Image", WINDOW_AUTOSIZE);

    /*
     * We now show the image using the imshow() function
     *		We tell it to show the image to the window called "Image"
     */
    imshow("Image", image);

    /*
     * We now pause the program using the waitKey() function
     *      waitKey() waits the user for a key press, so it effectively "pauses" the program until the user presses something
     * This is used because we dont want the program to terminate imeditely after rendering the image
     */
    waitKey();
    return 0;
}
