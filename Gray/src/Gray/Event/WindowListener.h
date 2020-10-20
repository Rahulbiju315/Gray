#pragma once

#include "EventListener.h"
#include "WindowEvent.h"

namespace Gray
{
	class GRAY_API WindowListener : public EventListener
	{
	public:
		void OnEvent(const Event& e) override
		{
			if (e.GetType() == EventType::WindowClosed)
				OnWindowClosed((WindowClosedEvent&)e);

			else if (e.GetType() == EventType::WindowResized)
				OnWindowResized((WindowResizedEvent&)e);
		}

		virtual void OnWindowClosed(const WindowClosedEvent& e)  { }
		virtual void OnWindowResized(const WindowResizedEvent& e) { }
	};
}