
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat src_gray;
int thresh = 100;
RNG rng(0);
const int max_thresh = 250;
const char* source_window = "Canndy";
void thresh_callback(int, void* );
int main(  )
{

    Mat src=imread("/home/masumpanda/CLionProjects/odev/white-line.jpg");
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );
    namedWindow( source_window );
    imshow( source_window, src );
    createTrackbar( "C1", source_window, &thresh, max_thresh, thresh_callback );
    thresh_callback( 0, 0 );
    waitKey();
    return 0;
}
void thresh_callback(int, void* )
{
    Mat canny_output;
    Canny( src_gray, canny_output, thresh, thresh*2 );
    imshow("canny",canny_output);
    vector<vector<Point> > contours;
    findContours( canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE );
    vector<vector<Point> > contours_poly( contours.size() );
    vector<Point2f>centers( contours.size() );
    vector<float>radius( contours.size() );
    for( size_t i = 0; i < contours.size(); i++ )
    {
        approxPolyDP( contours[i], contours_poly[i], 3, true );
        minEnclosingCircle( contours_poly[i], centers[i], radius[i] );
    }
    Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ )
    {

        Scalar color = Scalar( rng.uniform(0, 175), rng.uniform(210,256), rng.uniform(22,256) );
        drawContours( drawing, contours_poly, (int)i, color );
        circle( drawing, centers[i], 6, color, 1 );
    }
    imshow( "Contours", drawing );
}