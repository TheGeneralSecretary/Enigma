#pragma once

#include "Panel.h"
#include <Enigma/Utils/Memory.h>

#include <unordered_map>
#include <string>

namespace Enigma
{
	class PanelManager
	{
	public:
		static void AddPanel(const std::string& name, const Ref<Panel>& panel);
		static Ref<Panel> GetPanel(const std::string& name);
		static void RenderAll();

		template<typename T>
		static Ref<T> GetPanel(const std::string& name)
		{
			return std::dynamic_pointer_cast<T>(GetPanel(name));
		}

	private:
		static std::unordered_map<std::string, Ref<Panel>> m_Panels;
	};
}
