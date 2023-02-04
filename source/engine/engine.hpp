#pragma once
#if defined(_MSC_VER)
     //  Microsoft
#ifdef Engine_EXPORTS
     #define ENGINE_API __declspec(dllexport)
#else
     #define ENGINE_API __declspec(dllimport)
#endif
#elif defined(__GNUC__)
     //  GCC
#ifdef Engine_EXPORTS
     #define ENGINE_API __attribute__((visibility("default")))
#else
     #define ENGINE_API
#endif
 #else
     //  do nothing and hope for the best?
#ifdef Engine_EXPORTS
     #define ENGINE_API
#else
     #define ENGINE_API
     #pragma warning Unknown dynamic link import/export semantics.
#endif
#endif
 extern "C" ENGINE_API void HelloEngine();
//extern void HelloEngine();
