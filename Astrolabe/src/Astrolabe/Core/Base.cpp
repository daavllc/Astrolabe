#include "alpch.h"
#include "Base.h"

#include "Log.h"

namespace Astrolabe
{
	void InitalizeCore()
	{
		Astrolabe::Log::Init();

		AL_CORE_INFO("Astrolabe {}", "v0.0.1");
		AL_CORE_INFO("Initalizing...");
	}

	void ShutdownCore()
	{
		AL_CORE_TRACE("Shuting down...");
	}
}	//	END namespace Astrolabe