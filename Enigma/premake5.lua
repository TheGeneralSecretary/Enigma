project "Enigma"
kind "StaticLib"
language "C++"
cppdialect "C++17"
staticruntime "off"

targetdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")
objdir ("%{wks.location}/build/intermediates/" .. outputdir .. "/%{prj.name}")

pchheader "enigmapch.h"
pchsource "Source/enigmapch.cpp"

files
{
	"Source/**.h",
	"Source/**.cpp",
	
	"Dependencies/glm/glm/**.hpp",
	"Dependencies/glm/glm/**.inl",
}

excludes "Source/Enigma/Platform/**.cpp"

defines
{
	"ENIGMA_ENGINE",
	"GLFW_INCLUDE_NONE",
}

includedirs
{
	"Source",
	"%{IncludeDir.spdlog}",
	"%{IncludeDir.glfw}",
	"%{IncludeDir.glad}",
	"%{IncludeDir.glm}",
	"%{IncludeDir.imgui}",
	"%{IncludeDir.yaml_cpp}",
}

links
{
	"spdlog",
	"glfw",
	"glad",
	"imgui",
	"yaml-cpp",
	"opengl32.lib",
}

filter "system:windows"
	systemversion "latest"

	defines
	{
		"ENIGMA_PLATFORM_WINDOWS",
	}

	files
	{
		"Source/Enigma/Platform/Win32/**.cpp"
	}

filter "configurations:Debug"
	defines "ENIGMA_DEBUG"
	runtime "Debug"
	symbols "On"

filter "configurations:Release"
	defines "ENIGMA_RELEASE"
	runtime "Release"
	optimize "On"
