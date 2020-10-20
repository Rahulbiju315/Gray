#pragma once

#include "Event.h"
#include "Gray/Log.h"

namespace Gray
{
	class GRAY_API EventListener
	{
	public:
		virtual void OnEvent(const Event& e) = 0;
	};
}