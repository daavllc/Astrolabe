#pragma once

#include "Astrolabe/Core/PlatformDetection.h"

#ifdef AL_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <fstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Astrolabe/Core/Base.h"

#include "Astrolabe/Core/Log.h"

#include "Astrolabe/Debug/Instrumentor.h"