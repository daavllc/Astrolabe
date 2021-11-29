#pragma once

#include <memory>

#include "Astrolabe/Core/PlatformDetection.h"

#include "CoreConfig.h" //  includes Astrolabe defines
#include "Log.h"
#include "Assert.h"

namespace Astrolabe
{
    void InitalizeCore();
    void ShutdownCore();
}	//	END namespace Astrolabe

#ifndef AL_PLATFORM_WINDOWS
	#error Astrolabe only supports Windows!
#endif

#ifdef AL_DEBUG
    #if defined(AL_PLATFORM_WINDOWS)
        #define AL_DEBUGBREAK() __debugbreak()
    #elif defined(AL_PLATFORM_LINUX)
        #include <signal.h>
        #define AL_DEBUGBREAK() raise(SIGTRAP)
    #else
        #error "Platform doesn't support debugbreak!"
    #endif
    #define AL_ENABLE_ASSERTS
#else
    #define AL_DEBUGBREAK()
#endif

#define AL_EXPAND_MACRO(x) x
#define AL_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define AL_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }