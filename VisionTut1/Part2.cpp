/**
 * MDA Vision Tutorial 1: Brightness and Contrast controls
 * Part 1: Showing an image
 *
 * This series is based off of OpenCV's own tutorial
 *      http://docs.opencv.org/2.4/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html
 *
 * James Lu
 */

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main()
{
    //The image is the cat image
    Mat image = imread("cat.jpg");
    /*
     * We make a new Mat to hold the modified image
     * The Mat::zeros() function makes a black image (r = 0, g = 0, b = 0)
     * We want the new image to have the same size and type as the orginal
     */
    Mat modifiedImage = Mat::zeros(image.size(), image.type());

    //make the windows to show the image on
    namedWindow("Image", WINDOW_AUTOSIZE);
    namedWindow("Modified Image", WINDOW_AUTOSIZE);


    /// These values are from the formula in the OpenCV's tutorial (see above for link)
    //the alpha value corresponds to the contrast value, it ranges from 0.0-3.0
    float alpha = 2;
    //the beta value corresponds to the brightness value, it can be all real numbers
    int beta = 50;

    //In this example, we look through the image and modify individual pixels
    for (int y = 0; y < image.rows; y++){
        for (int x = 0; x < image.cols; x++){
            for (int c = 0; c < 3; c++){
                /*
                 * Here, we get the pixel at (y,x)
                 * We also have to modify the pixel's chanels individually
                 *      (red, green and blue)
                 */
                modifiedImage.at<Vec3b>(y,x)[c] =
                    /*
                     * saturate_cast is an OpenCV casting function
                     * Casting is when you turn one type into another (ie, int -> char)
                     * Saturate cast just "clips" the value if it exceeds the maximum
                     *  ie) saturate_cast<short>(33333) = 32767 (maximum value of a short)
                     */
                   saturate_cast<uchar>(
                      /*
                       * This is the main "meat" of the program
                       * It uses the formula:
                       *    a * I(y,x) + b
                       *    where
                       *        a is alpha; the contrast term
                       *        I(y,x) is the pixel at position (y,x)
                       *        b is beta; the brightness term
                       */
                      alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }

    //Now we show the two images side by side
    imshow("Image", image);
    imshow("Modified Image", modifiedImage);

    /*
     * We now pause the program using the waitKey() function
     *      waitKey() waits the user for a key press, so it effectively "pauses" the program until the user presses something
     * This is used because we dont want the program to terminate imeditely after rendering the image
     */
    waitKey();
    return 0;
}
