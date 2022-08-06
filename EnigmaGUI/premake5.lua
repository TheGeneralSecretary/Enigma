project "EnigmaGUI"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"
staticruntime "off"

targetdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")
objdir ("%{wks.location}/build/intermediates/" .. outputdir .. "/%{prj.name}")

pchheader "enigmaguipch.h"
pchsource "Source/enigmaguipch.cpp"

files
{
	"Source/**.h",
	"Source/**.cpp",
}

includedirs
{
	"Source",
	"%{wks.location}/Enigma/Source",
	"%{IncludeDir.spdlog}",
	"%{IncludeDir.imgui}",
	"%{IncludeDir.glm}",
}

links
{
	"Enigma"
}

filter "system:windows"
	systemversion "latest"

filter "configurations:Debug"
	defines "ENIGMA_DEBUG"
	runtime "Debug"
	symbols "On"

filter "configurations:Release"
	defines "ENIGMA_RELEASE"
	runtime "Release"
	optimize "On"
