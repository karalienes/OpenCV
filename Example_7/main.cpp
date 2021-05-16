#include <iostream>
#include"opencv2/imgproc.hpp"
#include"opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;

void Morphology_Operations(int, void*);
int main(){

    Mat img=imread("/home/masumpanda/CLionProjects/odev/white-line.jpg");



    waitKey('27');

}