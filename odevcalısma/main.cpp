#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <stdio.h>
#include <stdlib.h>


using namespace cv;
Mat src, src_gray , src_gray2;
Mat dst, detected_edges;
int lowThreshold = 0;
const int max_lowThreshold = 120;
const int ratio = 3;// 2:1 ile 3:1 arasında olması gerektıgı ıcın 3 secıyoruz
const int kernel_size = 3;//uygun kernel degeri
const char* window_name = "Canny";
RNG rng(0);
void thresh_callback(int, void* );
static void CannyThreshold(int, void*);

int main(  )
{
    Mat src2=imread("/home/masumpanda/CLionProjects/odev/white-line.jpg");
    src = imread("/home/masumpanda/CLionProjects/odev/white-line.jpg"); // Load an image
    dst.create( src.size(), src.type() );//aynı boyutta bir matris olusturduk
    cvtColor( src, src_gray, COLOR_BGR2GRAY );//resimi gri ediyoruz
    cvtColor( src2, src_gray2, COLOR_BGR2GRAY );
    namedWindow( window_name, WINDOW_AUTOSIZE );
    createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );
    createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, thresh_callback );
    CannyThreshold(0, 0);
    thresh_callback( 0, 0 );
    waitKey(0);
    return 0;
}
void thresh_callback(int, void* )
{
    Mat canny_output;
    Canny( src_gray, canny_output, lowThreshold, lowThreshold*2 );
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );
    Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
        drawContours( drawing, contours, (int)i, color, 2, LINE_8, hierarchy, 0 );
    }
    imshow( "Contours", drawing );
}
static void CannyThreshold(int, void*) {
    blur(src_gray, detected_edges, Size(3, 3));//bulanıklık işlemi ediyordur
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
    dst = Scalar::all(0);//matris bütün pixsellerini 0 yapıyoruz
    src.copyTo(dst, detected_edges);//dst degerleri detected edges kayıt ediyoruz
    imshow(window_name, dst);

}