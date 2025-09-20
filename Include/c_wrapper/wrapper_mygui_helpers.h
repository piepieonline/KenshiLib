#pragma once

#include "mygui/MyGUI.h"

namespace Wrappers
{
	extern "C" __declspec(dllexport) MyGUI::WidgetPtr MyGUI_Helper_FindWidget(const char* name, bool waitForWidget);
	extern "C" __declspec(dllexport) MyGUI::RotatingSkin* MyGUI_Helper_GetRotatingSkin(MyGUI::Widget* widget);
}

