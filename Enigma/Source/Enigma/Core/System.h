#pragma once

#ifdef _WIN32
	#ifdef _WIN64
		#error "x64 platforms are not supported"
	#else
		#define ENIGMA_PLATFORM_WINDOWS
	#endif
#else
		#error "unsupported platform"
#endif

#ifdef ENIGMA_DEBUG
	#ifdef ENIGMA_PLATFORM_WINDOWS
		#define ENIGMA_DEBUGBREAK() __debugbreak()	
	#else
		#error "platform doesnt support debugbreak"
	#endif

	#define ENIGMA_ENABLE_ASSERTS
#else
	#define ENIGMA_DEBUGBREAK()
#endif
