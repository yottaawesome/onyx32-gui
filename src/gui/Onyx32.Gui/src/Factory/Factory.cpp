#include "../h/stdafx.h"
#include "Factory.h"
#include "../Application/Application.h"
#include "../Window/Window.h"
#include "../Controls/Button/Button.h"
#include "../Controls/DateTime/DateTime.h"
#include "../Controls/TextInput/TextInput.h"

namespace Onyx32::Gui
{
	Factory::Factory() { }

	Factory::~Factory() { }

	IApplication* Factory::GetApplication()
	{
		return new Application();
	}

	IWindow* Factory::CreateDefaultWindow(std::wstring_view title, UINT width, UINT height)
	{
		if (width > 0 && height > 0)
			return new Window(WindowClassManager::GetDefaultWindowClass(), title, width, height);

		return new Window(WindowClassManager::GetDefaultWindowClass(), title);
	}

	IWindow* Factory::CreateStyledWindow(std::wstring_view title, const int styles, UINT width, UINT height)
	{
		if (width > 0 && height > 0)
			return new Window(WindowClassManager::GetDefaultWindowClass(), title, styles, width, height);

		return new Window(WindowClassManager::GetDefaultWindowClass(), title);
	}

	ITextInput* Factory::CreateTextInput(UINT controlId, std::wstring_view text, UINT width, UINT height, UINT xPos, UINT yPos)
	{
		return new TextInput(text, width, height, xPos, yPos, controlId);
	}

	IDateTime* Factory::CreateDateTime(UINT controlId, UINT width, UINT height, UINT xPos, UINT yPos)
	{
		return new DateTime(width, height, xPos, yPos, controlId);
	}

	IButton* Factory::CreateButton(IWindow* parent, UINT controlId, std::wstring_view text, UINT width, UINT height, UINT xPos, UINT yPos)
	{
		return Button::Create(parent, controlId, text, width, height, xPos, yPos);
	}
}
