#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#ifdef _WIN32 || _WIN64
// Windows Includes Here
#include <QtWidgets>
#endif

#ifdef __linux__
  // Linux Includes Here
#endif

#include <QtGui>
#include <opencv2/opencv.hpp>
#include <vector>
#include "my_algorithm.h"


using std::vector;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void showImage(cv::Mat a);
    void showImage(cv::Mat a,QLabel* label);


    void showVideo(cv::VideoCapture& video);
    void loadVideo(QString s);
    void loadVideo(int s=0);
    void keyPressEvent(QKeyEvent *);
    void processVideo(cv::VideoCapture& video);

private slots:
    void processImage();
private:
    Ui::MainWidget *ui;

    cv::Mat m_show_frame;
    cv::VideoCapture m_video;
    MyAlgorithm m_algorithm;
    int m_cycle;
};

#endif // MAIN_WIDGET_H
