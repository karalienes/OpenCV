#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;
Point anchor=Point(-1,-1);
int kernel_size;
int ddepth=-1;
double delta=0;
Mat kernel;
Mat  dst;
int main()
{

   Mat  img=imread("/home/CLionProjects/odev/white-line.jpg");
   Mat gimg;
   cvtColor(img,gimg,CV_BGR2GRAY);
   Mat gausimg;
   GaussianBlur(gimg,gausimg,Size(3,3),0,0);
   imshow("gaus",gausimg);
   imshow("gray",gimg);


    const char* window_name = "filter2D Demo";

    kernel=Mat::ones(3,3,CV_32F);
    kernel.at<float>(0,0)=-1;
    kernel.at<float>(0,1)=0;
    kernel.at<float>(0,2)=+1;
    kernel.at<float>(1,0)=-2;
    kernel.at<float>(1,1)=0;
    kernel.at<float>(1,2)=1;
    kernel.at<float>(2,2)=1;
    kernel.at<float>(2,2)=-1;
    kernel.at<float>(2,2)=2;
    kernel=kernel/(float)(3*3);
    filter2D(gimg, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
    imshow( window_name, dst );



    waitKey('27');
}