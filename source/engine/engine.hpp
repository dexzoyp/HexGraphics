#pragma once
#ifdef Engine_EXPORTS
    #define ENGINE_API __declspec(dllexport)
#else
    #define ENGINE_API __declspec(dllimport)
#endif
extern "C" ENGINE_API void HelloEngine();
