#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
    Mat image = imread("cat.jpg");
    Mat modifiedImage = Mat::zeros(image.size(), image.type());

    namedWindow("Image", WINDOW_AUTOSIZE);
    namedWindow("Modified Image", WINDOW_AUTOSIZE);

    float alpha = 2;
    int beta = 50;

    for (int y = 0; y < image.rows; y++){
        for (int x = 0; x < image.cols; x++){
            for (int c = 0; c < 3; c++){
                modifiedImage.at<Vec3b>(y,x)[c] =
                   saturate_cast<uchar>(
                      alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }

    imshow("Image", image);
    imshow("Modified Image", modifiedImage);



    waitKey();
    return 0;
}
