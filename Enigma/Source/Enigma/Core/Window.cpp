#include "enigmapch.h"
#include "Enigma/Core/Window.h"
#include "Enigma/Core/Logger.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Enigma
{
	static void APIENTRY DebugMessageCallback(GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam)
	{
		ENIGMA_LOG_ERROR("[OpenGL Error]({}) {}", type, message);
	}

	bool Window::Init(const WindowProps& props)
	{
		m_WinProps = props;
		if (!InitContext()) return false;
		return m_Initialized = true;
	}

	void Window::Destroy()
	{
		if (m_Initialized)
		{
			glfwSetErrorCallback(nullptr);
			glfwDestroyWindow(m_NativeWindow);
			glfwTerminate();
			m_Initialized = false;
		}
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_NativeWindow);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_NativeWindow);
	}

	bool Window::InitContext()
	{
		if (!glfwInit())
		{
			ENIGMA_LOG_ERROR("FAILED glfwInit");
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ENIGMA_DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

		m_NativeWindow = glfwCreateWindow(m_WinProps.Width, m_WinProps.Height, m_WinProps.Name.c_str(), nullptr, nullptr);
		if (!m_NativeWindow)
		{
			ENIGMA_LOG_ERROR("FAILED glfwCreateWindow for {}", m_WinProps.Name);
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(m_NativeWindow);
		glfwSwapInterval(0);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			ENIGMA_LOG_ERROR("FAILED gladLoadGLLoader");
			glfwTerminate();
			return false;
		}

		glDebugMessageCallback(DebugMessageCallback, nullptr);

		ENIGMA_LOG_INFO("OpenGL: Version({}), Renderer({}), Vendor({}) ", glGetString(GL_VERSION), glGetString(GL_RENDERER), glGetString(GL_VENDOR));

		glfwShowWindow(m_NativeWindow);

		ENIGMA_LOG_DEBUG("Initialized Context");
		return true;
	}
}
