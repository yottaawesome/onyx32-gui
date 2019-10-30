#pragma once
#include "../h/stdafx.h"
#include "../h/Onyx32.Gui.internal.h"

namespace Onyx32::Gui
{
	Win32ParentWindowCreationArgs::Win32ParentWindowCreationArgs(
		const DWORD extendedStyles,
		std::wstring_view windowName,
		const DWORD styles,
		const int x,
		const int y,
		const int width,
		const int height,
		const HWND parentOrOwner,
		const HMENU menu,
		const IWindow* window,
		const WNDCLASSEX& wndClass
	)
		: ExtendedStyles(extendedStyles),
		WindowName(windowName),
		Styles(styles),
		X(x),
		Y(y),
		Width(width),
		Height(height),
		ParentOrOwner(parentOrOwner),
		Menu(menu),
		Window(window),
		WndClass(wndClass)
	{ }

	Onyx32::Gui::Controls::Win32ChildWindowCreationArgs::Win32ChildWindowCreationArgs(
		const DWORD extendedStyles,
		std::wstring_view className,
		std::wstring_view windowName,
		const DWORD styles,
		const int x,
		const int y,
		const int width,
		const int height,
		const HWND parent,
		const HMENU menuOrId,
		const IControl* control,
		const SUBCLASSPROC subclassProc
	)
		: ExtendedStyles(extendedStyles),
		ClassName(className),
		WindowName(windowName),
		Styles(styles),
		X(x),
		Y(y),
		Width(width),
		Height(height),
		Parent(parent),
		MenuOrId(menuOrId),
		Control(control),
		SubclassProc(subclassProc)
	{ }
}