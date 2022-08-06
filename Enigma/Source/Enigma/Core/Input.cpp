#include "enigmapch.h"
#include "Enigma/Core/Input.h"
#include "Enigma/Core/Application.h"

#include <GLFW/glfw3.h>

namespace Enigma
{
	bool Input::IsKeyPressed(KeyCode key)
	{
		auto state = glfwGetKey(Application::Get()->GetWindow().GetNativeWindow(), static_cast<int>(key));
		return state == GLFW_PRESS;
	}

	bool Input::IsMousePressed(MouseCode button)
	{
		auto state = glfwGetMouseButton(Application::Get()->GetWindow().GetNativeWindow(), static_cast<int>(button));
		return state == GLFW_PRESS;
	}
}
