#pragma once

#include "Astrolabe/Core/Base.h"

//	This ignores warnings in external headers
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

namespace Astrolabe
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetBackendLogger() { return s_BackendLogger; }
		static std::shared_ptr<spdlog::logger>& GetFrontendLogger() { return s_FrontendLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_BackendLogger;
		static std::shared_ptr<spdlog::logger> s_FrontendLogger;

	};
}	//	END namespace Astrolabe

#ifdef AL_DEBUG	//	DEBUG
	// Core Log Defines
	#define AL_CORE_TRACE(...)		::Astrolabe::Log::GetBackendLogger()->trace(__VA_ARGS__)
	#define AL_CORE_INFO(...)		::Astrolabe::Log::GetBackendLogger()->info(__VA_ARGS__)
	#define AL_CORE_WARN(...)		::Astrolabe::Log::GetBackendLogger()->warn(__VA_ARGS__)
	#define AL_CORE_ERROR(...)		::Astrolabe::Log::GetBackendLogger()->error(__VA_ARGS__)
	#define AL_CORE_CRITICAL(...)	::Astrolabe::Log::GetBackendLogger()->critical(__VA_ARGS__)
	
	//	Client Log Defines
	#define AL_TRACE(...)			::Astrolabe::Log::GetFrontendLogger()->trace(__VA_ARGS__)
	#define AL_INFO(...)			::Astrolabe::Log::GetFrontendLogger()->info(__VA_ARGS__)
	#define AL_WARN(...)			::Astrolabe::Log::GetFrontendLogger()->warn(__VA_ARGS__)
	#define AL_ERROR(...)			::Astrolabe::Log::GetFrontendLogger()->error(__VA_ARGS__)
	#define AL_CRITICAL(...)		::Astrolabe::Log::GetFrontendLogger()->critical(__VA_ARGS__)
#endif

#ifdef AL_RELEASE	//	RFELEASE
			//	Don't Log Engine Messages
	#define AL_CORE_TRACE
	#define AL_CORE_INFO
	#define AL_CORE_WARN
	#define AL_CORE_ERROR
	#define AL_CORE_CRITICAL
	//	Client Log Defines
	#define AL_TRACE(...)			::Astrolabe::Log::GetFrontendLogger()->trace(__VA_ARGS__)
	#define AL_INFO(...)			::Astrolabe::Log::GetFrontendLogger()->info(__VA_ARGS__)
	#define AL_WARN(...)			::Astrolabe::Log::GetFrontendLogger()->warn(__VA_ARGS__)
	#define AL_ERROR(...)			::Astrolabe::Log::GetFrontendLogger()->error(__VA_ARGS__)
	#define AL_CRITICAL(...)		::Astrolabe::Log::GetFrontendLogger()->critical(__VA_ARGS__)
#endif

#ifdef AL_DISTRIBUTION	//	DISTRIBUTION
			//	Don't Log Engine Messages
	#define AL_CORE_TRACE
	#define AL_CORE_INFO
	#define AL_CORE_WARN
	#define AL_CORE_ERROR
	#define AL_CORE_CRITICAL
		//	Don't Log Client Messages
	#define AL_TRACE
	#define AL_INFO
	#define AL_WARN
	#define AL_ERROR
	#define AL_CRITICAL
#endif	//	END LOGGING DEFINES