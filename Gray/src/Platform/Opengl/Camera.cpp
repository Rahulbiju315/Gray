#include "grpch.h"
#include "Camera.h"

namespace Gray
{
	Camera::Camera(glm::vec3 pos, glm::vec2 dir)
	{
		this->pos = pos;
		this->dir = dir;

		aspectRatio = 4.0f / 3.0f;
		zLim = glm::vec2(0.1f, 100.0f);

		speed = 0.01f;
		sensitivity = 1 / 20.0f;

		SetZoom(45.0f);

		
		mX = -1;
		mY = -1;
	}

	Camera::~Camera()
	{
	}

	void Camera::SetAspectRatio(float aspectRatio)
	{
		this->aspectRatio = aspectRatio;
	}

	void Camera::SetZLimits(glm::vec2 zLim)
	{
		this->zLim = zLim;
	}

	void Camera::SetPos(glm::vec3 pos)
	{
		this->pos = pos;
	}

	void Camera::SetPos(float x, float y, float z)
	{
		this->pos.x = x;
		this->pos.y = y;
		this->pos.z = z;
	}

	void Camera::UpdatePos(float dx, float dy, float dz)
	{
		this->pos.x += dx;
		this->pos.y += dy;
		this->pos.z += dz;
	}

	void Camera::SetDir(glm::vec2 dir)
	{
		this->dir = dir;
	}

	void Camera::SetDir(float yaw, float pitch)
	{
		this->dir.x = yaw;
		this->dir.y = pitch;
	}

	void Camera::UpdateDir(float dyaw, float dpitch)
	{
		this->dir.x += dyaw;
		this->dir.y += dpitch;
	}

	float Camera::GetSpeed()
	{
		return speed;
	}

	float Camera::GetSensitivity()
	{
		return sensitivity;
	}

	void Camera::SetSpeed(float speed)
	{
		this->speed = speed;
	}

	void Camera::SetSensitivity(float sensitivity)
	{
		this->sensitivity = sensitivity;
	}

	const glm::vec3& Camera::GetPos()
	{
		return pos;
	}

	const glm::vec2& Camera::GetDir()
	{
		return dir;
	}

	float Camera::GetAspectRatio()
	{
		return aspectRatio;
	}

	const glm::vec2& Camera::GetZLimits()
	{
		return zLim;
	}

	void Camera::SetZoom(float alpha)
	{
		this->alpha = alpha;
		proj = glm::perspective(glm::radians(alpha), aspectRatio, zLim.x, zLim.y);

	}

	const glm::mat4& Camera::GetProjection()
	{
		return proj;
	}

	const glm::mat4& Camera::GetView()
	{

		float yaw = glm::radians(dir.x);
		float pitch = glm::radians(dir.y);

		glm::vec3 x_ = glm::vec3(cos(yaw), sin(pitch), sin(yaw));
		glm::vec3 z_ = glm::vec3(-sin(yaw), sin(pitch), cos(yaw));

		view = glm::lookAt(pos, pos - z_, Y_AXIS);

		return view;
	}

	void Camera::UpdateLook()
	{
		const glm::vec2& dir = GetDir();
		
		float mXn = Input::GetMouseX();
		float mYn = Input::GetMouseY();

		if (mX == -1)
		{
			mX = mXn;
			mY = mYn;
		}

		else
		{
			UpdateDir((mXn - mX) * sensitivity , 0.0f);
		}

		mX = mXn;
		mY = mYn;

	}

	void Camera::UpdatePos(float dt)
	{
		const glm::vec2& dir = GetDir();
		const glm::vec3& pos = GetPos();

		float yaw = glm::radians(dir.x);
		float pitch = glm::radians(dir.y);

		float k = dt * speed;

		glm::vec3 x_ = k * glm::vec3(cos(yaw), sin(pitch), sin(yaw));
		glm::vec3 z_ = k * glm::vec3(-sin(yaw), sin(pitch), cos(yaw));

		if (Gray::Input::IsKeyPressed(TO_INT(Gray::KeyCodes::Key_W)))
		{
			SetPos(pos - z_);
		}

		if (Gray::Input::IsKeyPressed(TO_INT(Gray::KeyCodes::Key_A)))
		{
			SetPos(pos - x_);
		}

		else if (Gray::Input::IsKeyPressed(TO_INT(Gray::KeyCodes::Key_S)))
		{
			SetPos(pos + z_);
		}

		else if (Gray::Input::IsKeyPressed(TO_INT(Gray::KeyCodes::Key_D)))
		{
			SetPos(pos + x_);
		}
	}
}