#pragma once

namespace Enigma
{
	class EImGui
	{
	public:
		bool Init();
		void Destroy();

		void BeginFrame();
		void EngFrame();

	private:
		bool m_Initialized = false;
	};
}
