/**
 * @file /include/DSO_GUI/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef DSO_GUI_QNODE_HPP_
#define DSO_GUI_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <sensor_msgs/Image.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace DSO_GUI {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
    QNode(int argc, char** argv );
    virtual ~QNode();
    bool init();
    bool init(const std::string &master_url, const std::string &host_url);
    void run();

    /*********************
        ** Logging
        **********************/
    enum LogLevel {
        Debug,
        Info,
        Warn,
        Error,
        Fatal
    };

    QStringListModel* loggingModel() { return &logging_model; }
    QImage updateImage(){ return qImage; }
    void log( const LogLevel &level, const std::string &msg);

Q_SIGNALS:
    void imageUpdated();
    void loggingUpdated();
    void rosShutdown();

private:
    int init_argc;
    char** init_argv;
    ros::Publisher chatter_publisher;
    ros::Subscriber chatter_subscriber;
    QStringListModel logging_model;
    QImage qImage;
    cv_bridge::CvImagePtr cv_ptr;
//    static void receiveImage(const sensor_msgs::ImageConstPtr img){
//        cv_ptr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::MONO8);
//    }
};

}  // namespace DSO_GUI

#endif /* DSO_GUI_QNODE_HPP_ */
