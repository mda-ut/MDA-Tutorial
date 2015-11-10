#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;

int main()
{

	/*
	 * OpenCV uses soemthing called "Mat" to store images
	 * They describe it as "an n-dimensional dense numerical single-channel or multi-channel array"
	 * We make a Mat called image, and we use the imread() function to load an image called "cat.jpg"
	 * 		you can change this to whatever your image file is called
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
