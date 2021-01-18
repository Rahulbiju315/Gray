#pragma once

#include "Gray/Graphics/Scene.h"

namespace Test
{
	class Test
	{
	public :
		virtual Gray::Scene* OnInit() = 0;
		virtual void OnUpdate(float dt) = 0;
		virtual void OnImguiRender(float dt) {}
	};
}