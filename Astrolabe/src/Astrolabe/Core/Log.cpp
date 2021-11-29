#include "Astrolabe/Core/Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/sinks/basic_file_sink.h>

namespace Astrolabe
{

	std::shared_ptr<spdlog::logger> Log::s_BackendLogger;
	std::shared_ptr<spdlog::logger> Log::s_FrontendLogger;

	void Log::Init()
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Astrolabe.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		s_BackendLogger = std::make_shared<spdlog::logger>("AL Backend", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_BackendLogger);
		s_BackendLogger->set_level(spdlog::level::trace);
		s_BackendLogger->flush_on(spdlog::level::trace);

		s_FrontendLogger = std::make_shared<spdlog::logger>("AL Frontend", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_FrontendLogger);
		s_FrontendLogger->set_level(spdlog::level::trace);
		s_FrontendLogger->flush_on(spdlog::level::trace);
	}

}	//	END namespace Astrolabe