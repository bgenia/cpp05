#pragma once

#include <iostream>

#include <termutils.hpp>

#define LOG_FUNCTION \
    do { std::cout << __PRETTY_FUNCTION__ << std::endl; } while (false)

#define LOG_FUNCTION_A(ARG) \
    do { std::cout << __PRETTY_FUNCTION__ << ": " << ARG << std::endl; } while (false)

#define LOG_FUNCTION_S(STYLE) \
    do { std::cout << STYLE << __PRETTY_FUNCTION__ << TERM_RESET << std::endl; } while (false)

#define LOG_FUNCTION_SA(STYLE, ARG) \
    do { std::cout << STYLE << __PRETTY_FUNCTION__ << ": " << ARG << TERM_RESET << std::endl; } while (false)

#define LOG_STYLE_CTOR          TERM_FAINT TERM_F_RGB(0, 255, 0)
#define LOG_STYLE_DTOR          TERM_FAINT TERM_F_RGB(255, 0, 0)
#define LOG_STYLE_COPY_CTOR     TERM_FAINT TERM_F_RGB(0, 132, 255)
#define LOG_STYLE_COPY_ASGN     TERM_ITALIC TERM_FAINT TERM_F_RGB(0, 132, 255)
#define LOG_STYLE_METHOD        TERM_UNDERLINE

#define LOG_CTOR                LOG_FUNCTION_S(LOG_STYLE_CTOR)
#define LOG_DTOR                LOG_FUNCTION_S(LOG_STYLE_DTOR)
#define LOG_COPY_CTOR           LOG_FUNCTION_S(LOG_STYLE_COPY_CTOR)
#define LOG_COPY_ASGN           LOG_FUNCTION_S(LOG_STYLE_COPY_ASGN)
#define LOG_METHOD              LOG_FUNCTION_S(LOG_STYLE_METHOD)

#define LOG_CTOR_A(ARG)         LOG_FUNCTION_SA(LOG_STYLE_CTOR, ARG)
#define LOG_DTOR_A(ARG)         LOG_FUNCTION_SA(LOG_STYLE_DTOR, ARG)
#define LOG_COPY_CTOR_A(ARG)    LOG_FUNCTION_SA(LOG_STYLE_COPY_CTOR, ARG)
#define LOG_COPY_ASGN_A(ARG)    LOG_FUNCTION_SA(LOG_STYLE_COPY_ASGN, ARG)
#define LOG_METHOD_A(ARG)       LOG_FUNCTION_SA(LOG_STYLE_METHOD, ARG)
