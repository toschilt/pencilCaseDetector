#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char *argv[])
{
    cv::VideoCapture webcam(0, cv::CAP_V4L2);
    cv::namedWindow("originalVideo", cv::WINDOW_AUTOSIZE);

    double fps;
    fps = webcam.get(cv::CAP_PROP_FPS);

    if(!webcam.isOpened())
    {
        std::cout << "Erro em abrir o vídeo!" << std::endl;
        return -1;
    }

    while(true)
    {
        cv::Mat frame;
        webcam.read(frame);

        std::cout << "FPS = " << fps << std::endl;

        cv::imshow("originalVideo", frame);

        if(cv::waitKey(10) == 'q')
        {
            std::cout << "Vídeo finalizado!" << std::endl;
            break;
        }
    }

    cv::destroyAllWindows();
    
    return 0;
}