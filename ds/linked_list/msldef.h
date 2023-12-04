#ifndef MSLDEF_H
#define MSLDEF_H


#include <iostream>


#define _MSL_BEGIN namespace msl {
#define _MSL_END   }
#define _MSL       ::msl::
#define _STD       ::std::

// STL like verifying
// #define _MSL_REPORT_ERROR (mesg)        \
//     do {}                               \
//     while (false)                       


// #define _MSL_VERIFY (cond, mesg)        \ 
//     do {                                \
//         if (cond) { /* do nothing */    \
//         } else {                        \
//             _MSL_REPORT_ERROR(mesg);    \
//         }                               \
//     } while (false)                      

_MSL_BEGIN
inline void _MSL_REPORT_ERROR_f (const char* mesg) noexcept {
    std::cerr << "\n" << mesg << "\n"; std::exit(134);
}

inline void _MSL_VERIFY_f (bool cond, const char* mesg) noexcept {
    if (!cond) return _MSL_REPORT_ERROR_f(mesg);
}

_MSL_END
#endif // MSLDEF_H
