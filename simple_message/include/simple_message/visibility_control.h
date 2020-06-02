#ifndef SIMPLE_MESSAGE__VISIBILITY_CONTROL_H_
#define SIMPLE_MESSAGE__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SIMPLE_MESSAGE_EXPORT __attribute__ ((dllexport))
    #define SIMPLE_MESSAGE_IMPORT __attribute__ ((dllimport))
  #else
    #define SIMPLE_MESSAGE_EXPORT __declspec(dllexport)
    #define SIMPLE_MESSAGE_IMPORT __declspec(dllimport)
  #endif
  #ifdef SIMPLE_MESSAGE_BUILDING_LIBRARY
    #define SIMPLE_MESSAGE_PUBLIC SIMPLE_MESSAGE_EXPORT
  #else
    #define SIMPLE_MESSAGE_PUBLIC SIMPLE_MESSAGE_IMPORT
  #endif
  #define SIMPLE_MESSAGE_PUBLIC_TYPE SIMPLE_MESSAGE_PUBLIC
  #define SIMPLE_MESSAGE_LOCAL
#else
  #define SIMPLE_MESSAGE_EXPORT __attribute__ ((visibility("default")))
  #define SIMPLE_MESSAGE_IMPORT
  #if __GNUC__ >= 4
    #define SIMPLE_MESSAGE_PUBLIC __attribute__ ((visibility("default")))
    #define SIMPLE_MESSAGE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SIMPLE_MESSAGE_PUBLIC
    #define SIMPLE_MESSAGE_LOCAL
  #endif
  #define SIMPLE_MESSAGE_PUBLIC_TYPE
#endif

#endif  // SIMPLE_MESSAGE__VISIBILITY_CONTROL_H_
