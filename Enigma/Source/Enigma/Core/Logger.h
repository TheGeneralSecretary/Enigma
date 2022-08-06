#pragma once

#include <string>
#include <spdlog/spdlog.h>

namespace Enigma
{
	class Logger
	{
	public:
		static void Init(const std::string& name = "EnigmaLogger");
		inline static std::shared_ptr<spdlog::logger> GetLogger() { return s_Logger; }

	private:
		inline static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

#define ENIGMA_LOG_INFO(...)		Enigma::Logger::GetLogger()->info(__VA_ARGS__)
#define ENIGMA_LOG_WARN(...)		Enigma::Logger::GetLogger()->warn(__VA_ARGS__)
#ifdef ENIGMA_DEBUG
	#define ENIGMA_LOG_DEBUG(...)	Enigma::Logger::GetLogger()->debug(__VA_ARGS__)
#else
	#define ENIGMA_LOG_DEBUG(...)
#endif
#define ENIGMA_LOG_ERROR(...)		Enigma::Logger::GetLogger()->error(__VA_ARGS__)
#define ENIGMA_LOG_CRITICAL(...)	Enigma::Logger::GetLogger()->critical(__VA_ARGS__)
#define ENIGMA_LOG_TRACE(...)		Enigma::Logger::GetLogger()->trace(__VA_ARGS__)
