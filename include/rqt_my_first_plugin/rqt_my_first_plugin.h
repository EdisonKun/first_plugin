#ifndef MY_FIRST_PLUGIN
#define MY_FIRST_PLUGIN

#include <rqt_gui_cpp/plugin.h>
#include <std_msgs/String.h>

#include <rqt_my_first_plugin/rqt_my_first_plugin_widget.h>

namespace rqt_my_first_plugin {

class my_first_plugin : public rqt_gui_cpp::Plugin
{
public:
  my_first_plugin();

  void initPlugin(qt_gui_cpp::PluginContext& context) override;
  void shutdownPlugin() override;

  void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const override;
  void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings) override;

private:
  rqt_my_first_plugin_widget *widget = nullptr;
};

}

#endif // MY_FIRST_PLUGIN

