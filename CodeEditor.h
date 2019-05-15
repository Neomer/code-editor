#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <gtkmm/textview.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/texttag.h>

namespace ce {

class CodeEditor : public Gtk::TextView
{
public:
    CodeEditor();
    virtual ~CodeEditor() override;

    // Widget interface
protected:
    virtual bool on_key_press_event(GdkEventKey *key_event) override;
    virtual bool on_key_release_event(GdkEventKey *key_event) override;

private:
    Glib::RefPtr<Gtk::TextTag> _cxxReservedTag;
    Gtk::TextIter _wordBeginIter, _wordEndIter;
};

}


#endif // CODEEDITOR_H
