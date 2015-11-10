#include <opencv2/highgui/highgui.hpp>

using namespace cv;


/*
 * Modified version of OpenCV's brightness and contrast tutorial
 *
 * http://docs.opencv.org/2.4/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html#basic-linear-transform
 * James Lu
 */

int main(){
    /*
     *  Reads an image called "img.jpg"
     *  Refer to the OpenCV website to see which file types are supported
     *  Note: the image has to be in the same folder as your executable, not your source files
     */
    Mat image = imread("img.jpg");

    /*
     * There should be error checking here to see if the image file exists,
     *  but we are going to assume it exists
     */

    // Creates a new empty image that has the same size as the orginal image
    Mat new_image = Mat::zeros(image.size(), image.type());

    /// Create Windows
    namedWindow("Control", WINDOW_AUTOSIZE);
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    namedWindow("New Image", WINDOW_AUTOSIZE);

    /// Move Windows (not required, just QOL)
    moveWindow("New Image", 900, 0);
    moveWindow("Control", 1200, 800);

    /*
     * The OpenCV slider bar has a minimum value of 0, and is an integer
     * So if we want to have a negative number or a float, we have to find "tricks" to turn a positive
     *  integer into a negative integer or a float
     */

    /// Create the variables and control panels
    int ialpha = 100;   //random value of 100; can be anything from 0-300
    int ibeta = 100;    //random value of 100; can be all numbers, but we are limiting it to +- 100 just because

    /// Creates the slider bars on the Control window
    // The contrast slider goes from 0-300, and we will divide it by 100 to get a float from 0-3
    cvCreateTrackbar("Contrast", "Control", &ialpha, 300);
    // The brightness slider moves from 0-200, we will subtract 100 from it to get to -100-100
    cvCreateTrackbar("Brightness", "Control", &ibeta, 200);

    bool keepRunning = true;
    while (keepRunning){
        // Converts the integer alpha to the float alpha by diving it by 100
        float alpha = ialpha / 100.0f;
        // Converts 0-200 to -100-100
        int beta = ibeta - 100;

        /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
        for( int y = 0; y < image.rows; y++ ){
            for( int x = 0; x < image.cols; x++ ){
                for( int c = 0; c < 3; c++ ){
                    /*
                     * Gets the pixel at (y, x),
                     *  goes through each of the three color chanels (BGR)
                     *  and applies the transformation
                     */
                    new_image.at<Vec3b>(y,x)[c] =
                        /*
                         * saturate_cast is an OpenCV casting function
                         * Casting is when you turn one type into another (ie, int -> char)
                         * Saturate cast just "clips" the value if it exceeds the maximum
                         *  ie) saturate_cast<short>(33333) = 32767 (maximum value of a short)
                         */
                        saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
                }
            }
        }

        /// Show images on the windows created earlier
        imshow("Original Image", image);
        imshow("New Image", new_image);

        //wait for a key press every 33ms => ~30fps
        int key = waitKey(33);
        //if the key is esc, stop the program
        if (key == 27){
            keepRunning = false;
        }
    }
    return 0;
}
