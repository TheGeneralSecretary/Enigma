#include "enigmaguipch.h"
#include "PanelManager.h"
#include <Enigma/Core/Logger.h>

namespace Enigma
{
	std::unordered_map<std::string, Ref<Panel>> PanelManager::m_Panels;

	void PanelManager::AddPanel(const std::string& name, const Ref<Panel>& panel)
	{
		if (m_Panels.find(name) == m_Panels.end())
			m_Panels[name] = panel;
	}

	Ref<Panel> PanelManager::GetPanel(const std::string& name)
	{
		if (m_Panels.find(name) == m_Panels.end())
		{
			ENIGMA_LOG_CRITICAL("GetPanel Not Found: {}", name);
			return nullptr;
		}

		return m_Panels[name];
	}

	void PanelManager::RenderAll()
	{
		for (auto& panel : m_Panels)
			panel.second->OnImGuiRender();
	}
}
