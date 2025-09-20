#include "c_wrapper/wrapper_mygui_helpers.h"

#include <windows.h>

#include "mygui/MyGUI.h"

#include "Kenshi/Kenshi.h"

MyGUI::WidgetPtr Wrappers::MyGUI_Helper_FindWidget(const char* name, bool waitForWidget)
{
    MyGUI::Gui* gui = nullptr;
    while (gui == nullptr)
    {
        gui = MyGUI::Gui::getInstancePtr();
        if (waitForWidget)
            Sleep(10);
        else
            return nullptr;
    }

    auto enumerator = gui->getEnumerator();

    MyGUI::WidgetPtr widget = nullptr;
    while (widget == nullptr)
    {
        widget = Kenshi::FindWidget(gui->getEnumerator(), std::string(name));
        if (waitForWidget)
            Sleep(10);
        else
            return nullptr;
    }

    return widget;
}

MyGUI::RotatingSkin* Wrappers::MyGUI_Helper_GetRotatingSkin(MyGUI::Widget* widget)
{
    MyGUI::ISubWidget* main = widget->getSubWidgetMain();
    return main->castType<MyGUI::RotatingSkin>();
}
