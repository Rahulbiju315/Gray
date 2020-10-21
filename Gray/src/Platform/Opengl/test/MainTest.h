#pragma once

#include "Test.h"
#include "Util.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Gray
{
	namespace test
	{
		class MainTest : public Test
		{
		private:
			VertexBuffer* vb;
			IndexBuffer* ib;
			IndexBuffer* debug;
			VertexArray* va;
			Shader* shader;
			Renderer* renderer;
			Texture* tex;

			glm::mat4 model;
			glm::mat4 view;
			glm::mat4 projection;

			glm::vec3 camPos;
			glm::vec3 objPos;
			glm::vec3 axisPos;
			glm::vec3 objRotation;

		public:
			MainTest();
			~MainTest();

			void onUpdate(float dt) override;
			void onRender() override;
			void onImGUIRender() override;
		};
	}
}