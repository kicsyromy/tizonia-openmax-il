/**
 * Copyright (C) 2011-2017 Aratelia Limited - Juan A. Rubio
 *
 * This file is part of Tizonia
 *
 * Tizonia is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Tizonia is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Tizonia.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file   tizplex.cpp
 * @author Romeo Calota <romeo.calota@libertymail.net>
 *
 * @brief  Tizonia - Simple Plex Media Server client library (c wrapper)
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <boost/lexical_cast.hpp>

#include "tizplex.hpp"

namespace bp = boost::python;

/* This macro assumes the existence of an "int rc" local variable */
#define try_catch_wrapper(expr)                                  \
  do                                                             \
    {                                                            \
      try                                                        \
        {                                                        \
          if (!rc)                                               \
            {                                                    \
              (expr);                                            \
            }                                                    \
        }                                                        \
      catch (bp::error_already_set & e)                          \
        {                                                        \
          PyErr_PrintEx (0);                                     \
          rc = 1;                                                \
        }                                                        \
      catch (const std::exception &e)                            \
        {                                                        \
          std::cerr << e.what ();                                \
          rc = 1;                                                \
        }                                                        \
      catch (...)                                                \
        {                                                        \
          std::cerr << std::string ("Unknown exception caught"); \
          rc = 1;                                                \
        }                                                        \
    }                                                            \
  while (0)

namespace
{
  void init_plex (boost::python::object &py_main,
                    boost::python::object &py_global)
  {
    // Import the Plex Media Server proxy module
    py_main = bp::import ("tizplexproxy");

    // Retrieve the main module's namespace
    py_global = py_main.attr ("__dict__");
  }

  void start_plex (boost::python::object &py_global,
                     boost::python::object &py_plex_proxy,
                     const std::string &user, const std::string &pass)
  {
    bp::object pyplexproxy = py_global["tizplexproxy"];
    py_plex_proxy
      = pyplexproxy (user.c_str (), pass.c_str ());
  }
}
