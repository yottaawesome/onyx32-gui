#include "../h/Win32Callbacks.h"
#include "../Window/Window.h"

namespace Onyx32::Gui
{
	LRESULT CALLBACK WndProc(HWND hWnd, unsigned int message, WPARAM wParam, LPARAM lParam)
	{
		IWindow* pThis = nullptr;

		if (message == WM_NCCREATE)
		{
			CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
			Window* pThis = (Window*)pCreate->lpCreateParams;
			SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pThis);
			pThis->SetHwnd(hWnd);
		}
		// We need these cases to bounce back messages sent to the parent from
		// child controls.
		// See also: https://stackoverflow.com/questions/29442905/win32-api-process-wm-in-tab-controls-wndproc-instead-of-parents
		else if (message == WM_COMMAND)
		{
			return SendMessage((HWND)lParam, message, wParam, lParam);
		}
		else if (message == WM_NOTIFY)
		{
			// WARNING: never send the sub-message directly to the child window.
			// SendMessage() quietly blocks the message, probably due to security.
			NMHDR* nmh = (NMHDR*)lParam;
			return SendMessage(nmh->hwndFrom, message, wParam, lParam);
		}
		else
		{
			pThis = (IWindow*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		}

		return pThis ? pThis->Process(message, wParam, lParam) : DefWindowProc(hWnd, message, wParam, lParam);
	}

	LRESULT CALLBACK DefCtrlProc(HWND hWnd, unsigned int message, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
	{
		Onyx32::Gui::Controls::IControl* btn = (Onyx32::Gui::Controls::IControl*)dwRefData;

		if (btn)
			return btn->Process(message, wParam, lParam);

		return DefSubclassProc(hWnd, message, wParam, lParam);
	}
}