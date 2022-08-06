include "Dependencies.lua"

workspace "Enigma"
   architecture "x86"
   startproject "EnigmaGUI"
   configurations { "Debug", "Release" }

outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

group "Dependencies"
   include "Enigma/Dependencies/spdlog"
   include "Enigma/Dependencies/glfw"
   include "Enigma/Dependencies/glad"
   include "Enigma/Dependencies/imgui"
   include "Enigma/Dependencies/yaml-cpp"
group ""

include "Enigma"
include "EnigmaGUI"
