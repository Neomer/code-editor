#include "cxx_reserved.h"

#include "CodeEditor.h"
#include <iostream>

using namespace ce;

bool is_navigation_key(uint32_t sym) {
    return (sym >= 65361 && sym <= 65364);
}

bool is_name_symbol(uint32_t sym) {
    return (sym >= 65 && sym <= 90) ||
            (sym >= 97 && sym <= 122);
}


CodeEditor::CodeEditor() :
    Gtk::TextView()
{
    set_border_width(10);

    auto buffer = get_buffer().get();
    auto defaultTag = buffer->create_tag("default");
    defaultTag->property_size() = 16;
    buffer->apply_tag(defaultTag, buffer->begin(), buffer->end());

    _wordBeginIter = buffer->begin();
    _wordEndIter = buffer->end();

    _cxxReservedTag = buffer->create_tag();
    _cxxReservedTag->property_foreground() = "blue";
    _cxxReservedTag->property_weight() = 800;
}

CodeEditor::~CodeEditor()
{

}

bool CodeEditor::on_key_press_event(GdkEventKey *key_event)
{
    std::cout << "key [pressed] " << key_event->keyval << " is_modifier: " << key_event->is_modifier << std::endl;

    if (!key_event->is_modifier && !is_navigation_key(key_event->keyval))
    {
        auto cursorPosition = get_buffer()->property_cursor_position().get_value();
        auto it = get_buffer()->get_iter_at_offset(cursorPosition - 1),
                endIt = get_buffer()->get_iter_at_offset(cursorPosition);
        while (it != get_buffer()->begin() && is_name_symbol(*it))
        {
            --it;
        }
        std::string name{ it, endIt };
        if (std::find_if(dict_cxx_reserved.begin(), dict_cxx_reserved.end(), [&name](const char *item) { return name == item; }) != dict_cxx_reserved.end())
        {
            get_buffer()->apply_tag(_cxxReservedTag, it, endIt);
        }
    }
    return Gtk::TextView::on_key_press_event(key_event);
}

bool CodeEditor::on_key_release_event(GdkEventKey *key_event)
{
    std::cout << "key [released] " << key_event->keyval << " is_modifier: " << key_event->is_modifier << std::endl;
    return Gtk::TextView::on_key_release_event(key_event);
}
