/*
*	core_config.h
*	
*	06-23-2025
* 
*	grant.a
* 
*	This file is the core configuration header for
* 	the project. It defines macros for platforms and compilers
*   and any other core configurations.
*/
#ifndef INC_CORE_CONFIG_H_
#define INC_CORE_CONFIG_H_

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
#define MC_WINDOWS
#elif defined(__linux__)
#define MC_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
#define MC_MACOS
#endif

// Compiler detection
#if defined(_MSC_VER)
#define MC_COMPILER_MSVC
#elif defined(__GNUC__)
#define MC_COMPILER_GCC
#elif defined(__clang__)
#define MC_COMPILER_CLANG
#elif defined(__INTEL_COMPILER)
#define MC_COMPILER_INTEL
#endif

#endif // INC_CORE_CONFIG_H_