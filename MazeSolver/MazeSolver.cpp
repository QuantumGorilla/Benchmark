#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    cout << "Digite el nombre del laberinto con su extension (Nombre.extension): ";
    string image;
    cin >> image;
    Mat src = imread(image);
    if (!src.data) { 
        printf("Error al cargar el archivo. \n"); 
        system("pause");
        return -1; 
    }

    Mat bw;
    cvtColor(src, bw, COLOR_BGR2GRAY);
    threshold(bw, bw, 10, 255, THRESH_BINARY_INV);

    //Detecta el contorno de la imagen 
    vector<std::vector<cv::Point> > contours;
    findContours(bw, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    if (contours.size() != 2)
    {
        std::cout << "Laberino incompleto" << std::endl;
        return -1;
    }

    Mat path = Mat::zeros(src.size(), CV_8UC1);
    drawContours(path, contours, 0, CV_RGB(255, 255, 255), FILLED);

    Mat kernel = Mat::ones(21, 21, CV_8UC1);
    dilate(path, path, kernel);

    Mat path_erode;
    erode(path, path_erode, kernel);

    absdiff(path, path_erode, path);

    //Dibuja el camino rojo
    vector<Mat> channels;
    split(src, channels);
    channels[0] &= ~path;
    channels[1] &= ~path;
    channels[2] |= path;

    Mat dst;
    merge(channels, dst);
    imshow("Solución", dst);
    waitKey(0);
    system("pause");
    return 0;
}