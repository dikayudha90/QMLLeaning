/**
 * @file /include/DSO_GUI/main_window.hpp
 *
 * @brief Qt based gui for DSO_GUI.
 *
 * @date November 2010
 **/
#ifndef DSO_GUI_MAIN_WINDOW_H
#define DSO_GUI_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include <QImage>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
/*****************************************************************************
** Namespace
*****************************************************************************/

namespace DSO_GUI {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget *parent = 0);
    ~MainWindow();

    void ReadSettings(); // Load up qt program settings at startup
    void WriteSettings(); // Save qt program settings when closing

    void closeEvent(QCloseEvent *event); // Overloaded function
    void showNoMasterMessage();

public Q_SLOTS:
    /******************************************
        ** Auto-connections (connectSlotsByName())
        *******************************************/
    void on_actionAbout_triggered();
    void on_button_connect_clicked(bool check );
    void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically

    void UpdateGUIFrame();


private:
    Ui::MainWindowDesign ui;
    QNode qnode;

    //cv::VideoCapture cap;
    //cv::Mat matOriginal;
    QImage qimgOriginal;
    QTimer *timer;
};

}  // namespace DSO_GUI

#endif // DSO_GUI_MAIN_WINDOW_H
