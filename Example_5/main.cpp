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

int main() {

    Mat img=imread("mona.jpg");
    if(img.empty()){
        cout<<"resim yuklenemedi" <<endl;
        system("pause");
        return -1;
    }
    namedWindow("deneme",CV_WINDOW_AUTOSIZE);
    cv2.imshow("deneme",img);
    waitKey(0);
    destroyWindow("deneme");
    return 0;
}