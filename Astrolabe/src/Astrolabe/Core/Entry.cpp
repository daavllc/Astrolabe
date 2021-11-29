#include "Astrolabe/Core/Base.h"
//#include "Astrolabe/Core/Application.h"

#ifdef AL_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	Astrolabe::InitalizeCore();

	AL_PROFILE_BEGIN_SESSION("Startup", "AstrolabeProfile-Startup.json");
	//auto app = Astrolabe::CreateApplication({ argc, argv });
	AL_PROFILE_END_SESSION();

	AL_PROFILE_BEGIN_SESSION("Runtime", "AstrolabeProfile-Runtime.json");
	//app->Run();
	AL_PROFILE_END_SESSION();

	AL_PROFILE_BEGIN_SESSION("Shutdown", "AstrolabeProfile-Shutdown.json");
	//delete app;
	Astrolabe::ShutdownCore();
	AL_PROFILE_END_SESSION();
}

#endif
