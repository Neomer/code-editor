#include <iostream>
#include <gtkmm.h>
#include "MainWindow.h"

using namespace std;
using namespace ce;

int main(int argc, char **argv)
{
    auto app = Gtk::Application::create(argc, argv);
    MainWindow wnd;
    return app->run(wnd);
}
