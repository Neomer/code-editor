#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/menubar.h>
#include <gtkmm/statusbar.h>
#include <gtkmm/treeview.h>
#include <gtkmm/listbox.h>

#include "CodeEditor.h"

namespace ce {

class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    virtual ~MainWindow() override;

private:
    void createMainMenu();
    void createStatusBar();
    void createContent();

    Gtk::Box _mainLayout, _contentLayout;
    Gtk::MenuBar _menuBar;
    Gtk::Statusbar _statusBar;
    Gtk::MenuItem _fileMenuItem, _viewMenuItem, _settingsMenuItem, _aboutMenuItem;
    CodeEditor _codeEditor;
};

}


#endif // MAINWINDOW_H
