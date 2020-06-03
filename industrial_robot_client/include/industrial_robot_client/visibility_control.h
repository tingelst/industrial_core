#ifndef INDUSTRIAL_ROBOT_CLIENT__VISIBILITY_CONTROL_H_
#define INDUSTRIAL_ROBOT_CLIENT__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define INDUSTRIAL_ROBOT_CLIENT_EXPORT __attribute__ ((dllexport))
    #define INDUSTRIAL_ROBOT_CLIENT_IMPORT __attribute__ ((dllimport))
  #else
    #define INDUSTRIAL_ROBOT_CLIENT_EXPORT __declspec(dllexport)
    #define INDUSTRIAL_ROBOT_CLIENT_IMPORT __declspec(dllimport)
  #endif
  #ifdef INDUSTRIAL_ROBOT_CLIENT_BUILDING_LIBRARY
    #define INDUSTRIAL_ROBOT_CLIENT_PUBLIC INDUSTRIAL_ROBOT_CLIENT_EXPORT
  #else
    #define INDUSTRIAL_ROBOT_CLIENT_PUBLIC INDUSTRIAL_ROBOT_CLIENT_IMPORT
  #endif
  #define INDUSTRIAL_ROBOT_CLIENT_PUBLIC_TYPE INDUSTRIAL_ROBOT_CLIENT_PUBLIC
  #define INDUSTRIAL_ROBOT_CLIENT_LOCAL
#else
  #define INDUSTRIAL_ROBOT_CLIENT_EXPORT __attribute__ ((visibility("default")))
  #define INDUSTRIAL_ROBOT_CLIENT_IMPORT
  #if __GNUC__ >= 4
    #define INDUSTRIAL_ROBOT_CLIENT_PUBLIC __attribute__ ((visibility("default")))
    #define INDUSTRIAL_ROBOT_CLIENT_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define INDUSTRIAL_ROBOT_CLIENT_PUBLIC
    #define INDUSTRIAL_ROBOT_CLIENT_LOCAL
  #endif
  #define INDUSTRIAL_ROBOT_CLIENT_PUBLIC_TYPE
#endif

#endif  // INDUSTRIAL_ROBOT_CLIENT__VISIBILITY_CONTROL_H_
