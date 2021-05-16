//Blocks that we will need on this program
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
// declaring the namespaces
using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    //Declaring variables to store the colored,gray scale and HSV images
    Mat colorimage;
    Mat grayimage;
    Mat hsvimage;
    //Read the color image from your PC.
    //Change the argument of the imread function to your image's path.
    colorimage = imread("/home/masumpanda/Masaüstü/clion-2019.1.2/resim-uzerine-transparan-resim-ekleme.jpg");
    //Resize function to resize your image
    resize(colorimage, colorimage, Size(640, 480));
    //Convert Color function.
    //cvtColor(source image , converted image , type of conversion )
    //You can check a list of possible convertions on the opencv website
    // The third argument will define the conversion.
    // COLOR TO GRAY (CV_BGR2GRAY)
    cvtColor(colorimage, grayimage, CV_BGR2GRAY);
    //COLOR TO HSV  ( CV_BGR2HSV)
    cvtColor(colorimage, hsvimage, CV_BGR2HSV);
    //Function to create windows to display your image. The type of the window
    //can be defined on the second argument
    //Can be omitted ( just use imshow ) if you want to use the default window properties.
    namedWindow("Color Image", CV_WINDOW_NORMAL);
    namedWindow("GrayScale Image", CV_WINDOW_NORMAL);
    namedWindow("HSV Image", CV_WINDOW_NORMAL);
    //function to show the image on the specified window (first argument)
    imshow("Color Image", colorimage);
    imshow("GrayScale Image", grayimage);
    imshow("HSV image", hsvimage);
    //Press any key to end the program
    waitKey(0);
    return 0;
}