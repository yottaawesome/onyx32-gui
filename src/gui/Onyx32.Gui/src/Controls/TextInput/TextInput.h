#pragma once
#include "../../h/Onyx32.Gui.internal.h"
#include "../../Window/Window.h"
#include <string>

namespace Onyx32::Gui::Controls
{
	class TextInput : public BaseControl<ITextInput>
	{
		public:
			TextInput() = delete;
			virtual ~TextInput();

			virtual void Initialize() override;
			virtual LRESULT Process(unsigned int message, WPARAM wParam, LPARAM lParam) override;
			virtual const std::wstring GetText() override;
			virtual void SetText(std::wstring_view str) override;

			static ITextInput* Create(IWindow* parent, unsigned int controlId, std::wstring_view text, unsigned int width, unsigned int height, unsigned int xPos, unsigned int yPos);

		protected:
			TextInput(
				std::wstring_view text = L"",
				const unsigned int width = 100,
				const unsigned int height = 100,
				const unsigned int xPos = 100,
				const unsigned int yPos = 100,
				const unsigned int controlId = 0);

			std::wstring _text;
	};
}