#pragma once

#include "Enigma/Core/System.h"
#include "Enigma/Core/Logger.h"

#ifdef ENIGMA_ENABLE_ASSERTS
	#define ENIGMA_ASSERT(x, msg) { if(!(x)) { ENIGMA_LOG_ERROR("Error: {}, File: {}, Line: {}", msg, __FILE__, __LINE__); ENIGMA_DEBUGBREAK(); } }
#else
	#define ENIGMA_ASSERT(...)
#endif
