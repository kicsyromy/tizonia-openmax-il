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
 * @file   tizplex_c.cpp
 * @author Romeo Calota <romeo.calota@libertymail.net>
 *
 * @brief  Tizonia - Simple Plex Media Server client library (c wrapper)
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>
#include <assert.h>

#include "tizplex_c.h"
#include "tizplex.hpp"


extern "C" int tiz_plex_init (/*@null@ */ tiz_plex_ptr_t *app_plex,
                     const char *ap_user, const char *ap_pass)
{
  static_cast<void>(app_plex);
  static_cast<void>(ap_user);
  static_cast<void>(ap_pass);

  return -1;
}

extern "C" void tiz_plex_destroy (tiz_plex_t *ap_plex)
{
  static_cast<void>(ap_plex);
}