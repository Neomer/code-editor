#include "MainWindow.h"

#include <glibmm/i18n.h>

using namespace ce;

MainWindow::MainWindow() :
    _mainLayout{Gtk::ORIENTATION_VERTICAL}, _contentLayout{},
    _menuBar{},
    _statusBar{},
    _fileMenuItem{_("File")}, _viewMenuItem{_("View")}, _settingsMenuItem{_("Settings")}, _aboutMenuItem{_("About")},
    _codeEditor{}
{
    set_border_width(0);
    set_default_size(800, 600);
    set_title(_("code-editor v.0.0.1"));

    createMainMenu();
    createStatusBar();
    createContent();

    _mainLayout.pack_start(_menuBar, Gtk::PACK_SHRINK);
    _mainLayout.pack_start(_contentLayout);
    _mainLayout.pack_start(_statusBar, Gtk::PACK_SHRINK);

    add(_mainLayout);
    show_all();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMainMenu()
{
    _menuBar.append(_fileMenuItem);
    _menuBar.append(_viewMenuItem);
    _menuBar.append(_settingsMenuItem);
    _menuBar.append(_aboutMenuItem);
    _menuBar.show_all();
}

void MainWindow::createStatusBar()
{
    _statusBar.push("Some text in the statusbar");
}

void MainWindow::createContent()
{
    _contentLayout.pack_start(_codeEditor);
}
