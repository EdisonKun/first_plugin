#ifndef MY_FIRST_PLUGIN_WIDGET
#define MY_FIRST_PLUGIN_WIDGET

#include <QWidget>
#include <ros/ros.h>
#include <iostream>

#include <controller_manager/controller_manager.h>
#include <controller_manager_msgs/ListControllers.h>
#include <controller_manager_msgs/SwitchController.h>
#include "std_srvs/SetBool.h"

namespace Ui {
class rqt_my_first_plugin_widget;
}

class rqt_my_first_plugin_widget : public QWidget
{
  Q_OBJECT

public:
  explicit rqt_my_first_plugin_widget(const ros::NodeHandle& nodehandle, QWidget *parent = nullptr);
  ~rqt_my_first_plugin_widget();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_what_clicked();

  void on_pushButton_3_clicked();

  void on_controllers_currentChanged(int index);

  void on_textBrowser_highlighted(const QUrl &arg1);

private:
  Ui::rqt_my_first_plugin_widget *ui;

  ros::NodeHandle nodehandle_;
  ros::ServiceClient listControllerClient_;
  ros::ServiceClient loadControllerClient_;
  ros::ServiceClient switchControllerClient_;
  ros::ServiceClient unloadcontrollerclient_;

  void displayOutputInfos(const std::string &color, const QString &context);
};

#endif // MY_FIRST_PLUGIN_WIDGET
