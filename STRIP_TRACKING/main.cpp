#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;
void thresh_callback(int, void* );
Mat Griimg;
Mat Binary;
Mat img=imread("/home/masumpanda/CLionProjects/odev/white-line.jpg");
RNG rng(0);
int main(){


   if(img.empty())
       cout<<"Resim acilamadi"<<endl;


       cvtColor(img,Griimg,CV_BGR2GRAY);

       threshold(img,Binary,240,255,THRESH_BINARY);
       imshow("1",Binary);


       namedWindow("Orginal Resim",CV_WINDOW_AUTOSIZE);
     namedWindow("Gri Resim",CV_WINDOW_AUTOSIZE);
       imshow("Orginal Resim",img);
     imshow("Gri Resim",Griimg);
    thresh_callback( 0, 0 );
       waitKey(0);


}
void thresh_callback(int, void* )
{
    Mat canny_output;
    Canny( src_gray, canny_output, thresh, thresh*2 );
    vector<vector<Point> > contours;
    findContours( canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE );
    vector<vector<Point> > contours_poly( contours.size() );
    vector<Rect> boundRect( contours.size() );
    vector<Point2f>centers( contours.size() );
    vector<float>radius( contours.size() );
    for( size_t i = 0; i < contours.size(); i++ )
    {
        approxPolyDP( contours[i], contours_poly[i], 3, true );
        boundRect[i] = boundingRect( contours_poly[i] );
        minEnclosingCircle( contours_poly[i], centers[i], radius[i] );
    }
    Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
        drawContours( drawing, contours_poly, (int)i, color );
        rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2 );
        circle( drawing, centers[i], (int)radius[i], color, 2 );
    }
    imshow( "Contours", drawing );
}
