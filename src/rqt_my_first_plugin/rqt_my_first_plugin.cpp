#include <rqt_my_first_plugin/rqt_my_first_plugin.h>

#include <pluginlib/class_list_macros.h>
#include <ros/master.h>

namespace rqt_my_first_plugin {


my_first_plugin::my_first_plugin() :
  rqt_gui_cpp::Plugin()
{
  setObjectName("my_first_plugin");
}

void rqt_my_first_plugin::my_first_plugin::initPlugin(qt_gui_cpp::PluginContext &context)
{
  widget = new rqt_my_first_plugin_widget(getNodeHandle());
  context.addWidget(widget);
}

void rqt_my_first_plugin::my_first_plugin::shutdownPlugin()
{

}

void rqt_my_first_plugin::my_first_plugin::saveSettings(qt_gui_cpp::Settings &plugin_settings, qt_gui_cpp::Settings &instance_settings) const
{

}

void rqt_my_first_plugin::my_first_plugin::restoreSettings(const qt_gui_cpp::Settings &plugin_settings, const qt_gui_cpp::Settings &instance_settings)
{

}

} // end namespace rqt_my_first_plugin

PLUGINLIB_EXPORT_CLASS(rqt_my_first_plugin::my_first_plugin, rqt_gui_cpp::Plugin)
