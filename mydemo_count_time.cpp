#include <iostream>
#include <fstream>
#include <cv.h>
#include <highgui.h>
#include <math.h>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture("G://test.mp4");
	if (!capture.isOpened())
	{
		cout << "file open failed!" << endl;
		return -1;
	}

	ofstream time("time.txt");
	time.is_open();
	Mat frame;
	int frame_count = 0;
	namedWindow("current",CV_WINDOW_AUTOSIZE);

	while (1)
	{
		double t = (double)getTickCount();

		capture >> frame;
		if (frame.empty())
			break;


		
		
		
		
		imshow("current", frame);
		cvWaitKey(10);                // delay 10ms
		t = ((double)getTickCount()-t)/getTickFrequency();
		cout << t << endl;
		frame_count++;
		time << left << setw(10) << frame_count << setw(10) << t << endl;
	}

	time.close();
	return 1;
	
}
