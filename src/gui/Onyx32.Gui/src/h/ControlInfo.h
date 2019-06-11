#pragma once
#include "../../include/Onyx32.Gui.h"

namespace Onyx32::Gui
{
	class ControlInfo
	{
		public:
			ControlInfo(const IControl& control)
				: control(control) {}

			const IControl& control;
	};
}