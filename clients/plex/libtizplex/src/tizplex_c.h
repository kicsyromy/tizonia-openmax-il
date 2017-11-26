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
 * @file   tizplex_c.h
 * @author Romeo Calota <romeo.calota@libertymail.net>
 *
 * @brief  Tizonia - Simple Plex Media Server client library (c wrapper)
 *
 *
 */

#ifndef TIZPLEX_C_H
#define TIZPLEX_C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
* @defgroup libtizplex 'libtizplex' : A Plex Media Server client library
*
* A C library to access a Plex Media Server.
*
* @ingroup Tizonia
*/

/**
 * The plex opaque structure
 * @ingroup libtizplex
 */
typedef struct tiz_plex tiz_plex_t;
typedef /*@null@ */ tiz_plex_t *tiz_plex_ptr_t;


/**
 * Initialize the gmusic handle.
 *
 * @ingroup libtizgmusic
 *
 * @param app_plex A pointer to the plex handle which will be initialised.
 * @param ap_user A Plex Media Server account.
 * @param ap_pass The password associated to the account.
 *
 * @return 0 on success.
 */
int tiz_plex_init (/*@null@ */ tiz_plex_ptr_t *app_plex,
                     const char *ap_user, const char *ap_pass);

/**
 * Destroy the plex handle.
 *
 * @ingroup libtizplex
 *
 * @param ap_plex The plex handle.
 */
void tiz_plex_destroy (tiz_plex_t *ap_plex);

#ifdef __cplusplus
}
#endif

#endif  // TIZPLEX_C_H
