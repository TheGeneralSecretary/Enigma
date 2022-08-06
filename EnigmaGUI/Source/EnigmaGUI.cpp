#include "enigmaguipch.h"
#include "Panels/PanelManager.h"
#include <Enigma/Core/Application.h>
#include <Enigma/Core/Logger.h>
#include <Enigma/Core/Input.h>

#include <imgui.h>

namespace Enigma
{
	class EnigmaApp : public Application
	{
	public:
		EnigmaApp(const ApplicationProps& props)
			: Application(props)
		{
		}

		~EnigmaApp()
		{
		}

		virtual void OnUpdate() override
		{
			OnInput();			
		}

		void OnInput()
		{
		}

		virtual void OnImGuiRender() override
		{
			static bool dockspace_open = true;
			static bool opt_fullscreen = true;
			static bool opt_padding = false;
			static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

			ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
			if (opt_fullscreen)
			{
				const ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::SetNextWindowPos(viewport->WorkPos);
				ImGui::SetNextWindowSize(viewport->WorkSize);
				ImGui::SetNextWindowViewport(viewport->ID);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
				window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
				window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
			}
			else
			{
				dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
			}

			if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
				window_flags |= ImGuiWindowFlags_NoBackground;

			if (!opt_padding)
				ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

			ImGui::Begin("DockSpace", &dockspace_open, window_flags);

			if (!opt_padding)
				ImGui::PopStyleVar();

			if (opt_fullscreen)
				ImGui::PopStyleVar(2);

			ImGuiIO& io = ImGui::GetIO();
			if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
			{
				ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
				ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
			}

			if (ImGui::BeginMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if (ImGui::MenuItem("Exit"))
						Shutdown();

					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
			}

			PanelManager::RenderAll();
			ImGui::End();
		}
	};
}

int main(int argc, char** argv)
{
	Enigma::EnigmaApp* enigma = new Enigma::EnigmaApp({ "Enigma", 1024, 768 });
	enigma->Run();
	delete enigma;
	return 0;
}
