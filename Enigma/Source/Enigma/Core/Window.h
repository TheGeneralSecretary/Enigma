#pragma once

#include <string>

struct GLFWwindow;

namespace Enigma
{
	struct WindowProps
	{
		std::string Name;
		int Width;
		int Height;
	};

	class Window
	{
	public:
		bool Init(const WindowProps& props);
		void Destroy();
		void Update();
		bool ShouldClose();

		inline const auto& GetNativeWindow() const { return m_NativeWindow; }
		inline int GetWidth() const { return m_WinProps.Width; }
		inline int GetHeight() const { return m_WinProps.Height; }
		
	private:
		bool InitContext();

	private:
		bool m_Initialized = false;
		WindowProps m_WinProps;
		GLFWwindow* m_NativeWindow;
	};
}
