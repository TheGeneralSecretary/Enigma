#pragma once

#include "Enigma/Core/Window.h"
#include "Enigma/ImGui/EImGui.h"

#include <string>
#include <memory>

namespace Enigma
{
	struct ApplicationProps
	{
		std::string Name;
		int Width;
		int Height;
	};

	class Application
	{
	public:
		virtual ~Application();
		Application(const Application&) = delete;
		void operator=(const Application&) = delete;

		Application(const ApplicationProps& props);
		virtual void OnUpdate() = 0;
		virtual void OnImGuiRender() = 0;

		inline static Application* Get() { return s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
		inline void Shutdown() { m_Running = false; }

	public:
		void Run();

	private:
		static Application* s_Instance;
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<EImGui> m_ImGui;
		bool m_Running;

	protected:
		ApplicationProps m_AppProps;
	};
}
