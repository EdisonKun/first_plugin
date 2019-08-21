#include <rqt_my_first_plugin/rqt_my_first_plugin_widget.h>
#include "ui_rqt_my_first_plugin_widget.h"
#include "iostream"
rqt_my_first_plugin_widget::rqt_my_first_plugin_widget(const ros::NodeHandle& nodehandle,QWidget *parent) :
  QWidget(parent),
  ui(new Ui::rqt_my_first_plugin_widget),
  nodehandle_(nodehandle)
{
  ui->setupUi(this);

  ui->controllers->setTabText(0,"controller_1");
  ui->controllers->setTabText(1,"controller_2");

  listControllerClient_ = nodehandle_.serviceClient<controller_manager_msgs::ListControllers>
      ("/controller_manager/list_controllers",false);
  loadControllerClient_ = nodehandle_.serviceClient<controller_manager_msgs::LoadController>
      ("/controller_manager/load_controller",false);
  switchControllerClient_ = nodehandle_.serviceClient<controller_manager_msgs::SwitchController>
      ("/controller_manager/switch_controller",false);
  unloadcontrollerclient_ = nodehandle_.serviceClient<controller_manager_msgs::UnloadController>
      ("/controller_manager/unload_controller",false);

}

rqt_my_first_plugin_widget::~rqt_my_first_plugin_widget()
{
  delete ui;
}

void rqt_my_first_plugin_widget::on_pushButton_clicked()//just stop controllers, ok button
{
    std::cout<<"prepare to unload controller"<<std::endl;
    controller_manager_msgs::UnloadController unload_controllers;
    unload_controllers.request.name == "single_joint_controller";
    unloadcontrollerclient_.call(unload_controllers.request, unload_controllers.response);
    if(unload_controllers.response.ok)
      std::cout <<"success"<< std::endl;
    else {
      std::cout << "failed" << std::endl;
    }
}

void rqt_my_first_plugin_widget::on_pushButton_2_clicked()//list controllers, no button
{
    controller_manager_msgs::ListControllers list_controllers;
    listControllerClient_.call(list_controllers.request, list_controllers.response);
    auto& controller=list_controllers.response.controller;
    if(controller.size() > 0)
    {
      std::cout << "the name of controller is " << controller.begin()->name << std::endl;
    }
    else {
      std::cout << "nothing~~~ is loaded;" <<std::endl;
    }
}

void rqt_my_first_plugin_widget::displayOutputInfos(const std::string &color,
                                                const QString &context)
{

//  if(color == "red")
//    {
//      ui->InfoOutputs->setTextColor(QColor(255,0,0));
//      ui->InfoOutputs->insertPlainText(QString("ERROR : ") + context + QString("\n"));
//    }
//  if(color == "green")
//    {
//      ui->InfoOutputs->setTextColor(QColor(0,255,0));
//      ui->InfoOutputs->insertPlainText(QString("INFO : ") + context + QString("\n"));
//    }
//  if(color == "yellow")
//    {
//      ui->InfoOutputs->setTextColor(QColor(255,255,0));
//      ui->InfoOutputs->insertPlainText(QString("WARN : ") + context + QString("\n"));
//    }

//  ui->info_display->insertPlainText(context + QString("\n"));
}

void rqt_my_first_plugin_widget::on_what_clicked()//load controller
{

  std::cout << "what?" << std::endl;
  controller_manager_msgs::SwitchController controller_switch;
  std::cout << "2" << std::endl;
  std::string current_controller;
  std::cout << "3" << std::endl;


}

void rqt_my_first_plugin_widget::on_pushButton_3_clicked()
{
    std::cout << "what_2" << std::endl;
}

void rqt_my_first_plugin_widget::on_controllers_currentChanged(int index)
{
  controller_manager_msgs::ListControllers list_controllers;
  listControllerClient_.call(list_controllers.request, list_controllers.response);
  std::string current_controller;
  for(auto& controller:list_controllers.response.controller)//load controller from parameter server, load all controllers
  {
    if(controller.name == "single_joint_controler" && controller.state == "running")
    {
      current_controller = "single_joint_controller";
      std::cout << "the cuttent controller is" << current_controller << std::endl;
      break;
    }
  }
  controller_manager_msgs::SwitchController controller_switch;
  controller_manager_msgs::LoadController controller_load;
  QString tab_name = ui->controllers->tabText(index);//jump to specific page to load controller
  std::cout << current_controller << std::endl;
  if(tab_name == "controller_1")
  {
//    std::cout << "controller_1" <<std::endl;
//    controller_load.request.name = "single_joint_controller";
//    loadControllerClient_.call(controller_load.request, controller_load.response);
//    if(controller_load.response.ok)
//    {
//      std::cout << "success load the single_joint_controller" << std::endl;
//    }
//    else {
//      std::cout << "failed" << std::endl;
//    }
    controller_switch.request.start_controllers.push_back("single_joint_controller");
//    controller_switch.request.stop_controllers.push_back(current_controller.c_str());
    controller_switch.request.strictness = controller_switch.request.STRICT;
    switchControllerClient_.call(controller_switch.request, controller_switch.response);

    if(controller_switch.response.ok)
    {
      std::cout << "success load the single_joint_controller" << std::endl;
    }else
    {
      std::cout << "nothing is load" << std::endl;
    }
  }
  else if(tab_name == "controller_2")
  {
    std::cout << "controller_2" << std::endl;
    controller_switch.request.stop_controllers.push_back("single_joint_controller");
    controller_switch.request.strictness = controller_switch.request.STRICT;
    switchControllerClient_.call(controller_switch.request, controller_switch.response);
    if(controller_switch.response.ok)
    {
      std::cout << "success unload the single_joint_controller" << std::endl;
    }else
    {
      std::cout << "nothing is load" << std::endl;
    }

  }
}


