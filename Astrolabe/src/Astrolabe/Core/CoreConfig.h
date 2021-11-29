#pragma once

//  ---------------------------------------------------------------------------------------------------------------------  //
//  ----------------------------------------------    PROFILING DEFINES    ----------------------------------------------  //
//  ---------------------------------------------------------------------------------------------------------------------  //
#ifdef AL_DEBUG
	#define AL_PROFILE 1
	#define AL_PROFILE_RENDERER 1
#endif
#if AL_PROFILE
	// Resolve which function signature macro will be used. Note that this only
	// is resolved when the (pre)compiler starts, so the syntax highlighting
	// could mark the wrong one in your editor!
	#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
		#define AL_FUNC_SIG __PRETTY_FUNCTION__
	#elif defined(__DMC__) && (__DMC__ >= 0x810)
		#define AL_FUNC_SIG __PRETTY_FUNCTION__
	#elif (defined(__FUNCSIG__) || (_MSC_VER))
		#define AL_FUNC_SIG __FUNCSIG__
	#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
		#define AL_FUNC_SIG __FUNCTION__
	#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
		#define AL_FUNC_SIG __FUNC__
	#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
		#define AL_FUNC_SIG __func__
	#elif defined(__cplusplus) && (__cplusplus >= 201103)
		#define AL_FUNC_SIG __func__
	#else
		#define AL_FUNC_SIG "AL_FUNC_SIG unknown!"
	#endif

	#define AL_PROFILE_BEGIN_SESSION(name, filepath) ::Astrolabe::Instrumentor::Get().BeginSession(name, filepath)
	#define AL_PROFILE_END_SESSION() ::Astrolabe::Instrumentor::Get().EndSession()
	#define AL_PROFILE_SCOPE(name) constexpr auto fixedName = ::Astrolabe::InstrumentorUtils::CleanupOutputString(name, "__cdecl ");\
												::Astrolabe::InstrumentationTimer timer##__LINE__(fixedName.Data)
	#define AL_PROFILE_FUNCTION() AL_PROFILE_SCOPE(AL_FUNC_SIG)
	#ifdef AL_PROFILE_RENDERER	//  ----------------------------------  RENDERER PROFILING -----------------------------------  //
		#define AL_PROFILE_RENDERER_SCOPE(name) constexpr auto fixedName = ::Astrolabe::InstrumentorUtils::CleanupOutputString(name, "__cdecl ");\
													::Astrolabe::InstrumentationTimer timer##__LINE__(fixedName.Data)
		#define AL_PROFILE_RENDERER_FUNCTION() AL_PROFILE_RENDERER_SCOPE(AL_FUNC_SIG)
	#endif
#else
	#define AL_PROFILE_BEGIN_SESSION(name, filepath)
	#define AL_PROFILE_END_SESSION()
	#define AL_PROFILE_SCOPE(name)
	#define AL_PROFILE_FUNCTION()
	#define AL_PROFILE_RENDERER_SCOPE(name)
	#define AL_PROFILE_RENDERER_FUNCTION()
#endif	//  END PROFILING DEFINES