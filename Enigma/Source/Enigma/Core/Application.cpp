#include "enigmapch.h"
#include "Enigma/Core/Application.h"
#include "Enigma/Core/Logger.h"

namespace Enigma
{
	Application* Application::s_Instance = nullptr;

	Application::~Application()
	{
		m_ImGui->Destroy();
		m_Window->Destroy();
	}

	Application::Application(const ApplicationProps& props)
		: m_AppProps(props), m_Running(true)
	{
		s_Instance = this;
		Logger::Init();

		m_Window = std::make_unique<Window>();
		m_Window->Init({ props.Name, props.Width, props.Height });

		m_ImGui = std::make_unique<EImGui>();
		m_ImGui->Init();
	}

	void Application::Run()
	{
		while (!m_Window->ShouldClose() && m_Running)
		{
			OnUpdate();

			m_ImGui->BeginFrame();
			OnImGuiRender();
			m_ImGui->EngFrame();

			m_Window->Update();
		}
	}
}
