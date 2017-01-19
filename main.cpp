#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
  VideoCapture cap{1};
  if (!cap.isOpened()) return -1;

  string win_name = "Lab 0";
  namedWindow(win_name);

  Mat previous;
  int frameNo = 0;
  for (;;)
  {
    Mat frame;
    cap >> frame;

    Mat gray, processed1, processed2;

    int minHessian = 400;

    cvtColor(frame, gray, CV_RGB2GRAY);

    std::vector<KeyPoint> keypoints_1;
    FAST(gray, keypoints_1, 25);

    //-- Draw keypoints
    Mat img_keypoints_1;

    drawKeypoints(frame, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );

  // blur(frame, processed1, Size(5,5));
//    Canny(processed1, processed2, 50, 80);

//    if (frameNo > 0) {
//      absdiff(frame, previous, processed1);
    //Laplacian(processed1,processed2,CV_16S,11);
      imshow(win_name, img_keypoints_1);
//    }
    if (waitKey(30) >= 0) break;

    frameNo++;
    frame.copyTo(previous);

    cout << "Another frame:" << frame.cols << "x" << frame.rows << endl;
  }
}
