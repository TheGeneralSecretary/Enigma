#include "enigmapch.h"
#include "Enigma/Utils/DateTime.h"

#include <GLFW/glfw3.h>

namespace Enigma
{
	double DateTime::GetTimeSeconds()
	{
		return glfwGetTime();
	}
}
