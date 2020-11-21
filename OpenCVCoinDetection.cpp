#include <iostream>
#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main()
{
    Mat image;
    vector<Vec3f> coins;

    image = imread("coins.jpg", IMREAD_GRAYSCALE);
    HoughCircles(image, coins, HOUGH_GRADIENT, 1, 100, 100, 30, 60, 80);

    int l = coins.size();

    cout << "The number of coins: " << l << "\n\n";

    for (size_t i = 0; i < coins.size(); i++) {
        Point center(cvRound(coins[i][0]), cvRound(coins[i][1]));
        int radius = cvRound(coins[i][2]);

        circle(image, center, 3, Scalar(0, 255, 0), 3, LINE_AA);
        circle(image, center, radius, Scalar(0, 0, 255), 3, LINE_AA);

        cout << "Center location for circle " << i + 1 << ": " << center << "\n"
            << "Diameter: " << radius * 2 << endl;
    }

    cout << "\n";

    namedWindow("Coin counter", WINDOW_AUTOSIZE);
    imshow("Coin counter", image);

    waitKey(0);

    return 0;
}
