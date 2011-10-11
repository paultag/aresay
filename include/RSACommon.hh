/* RSA Common Routines
 * Copyright (c) 2011, Paul Tagliamonte <tag@pault.ag>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string>

#ifndef RSACOMMON_HH_
#define RSACOMMON_HH_ FOO

#include "RSAPrivateHalf.hh"
#include "RSAPublicHalf.hh"
#include "RSAEncrypter.hh"
#include "RSADecrypter.hh"

#define String std::string

int powerMod( int x, int n, int mod );
RSAPrivateHalf * getRSAPrivateHalfFromFile( String fpath );
RSAPublicHalf  * getRSAPublicHalfFromFile(  String fpath );
String           readStdin();

int * encryptString( RSAEncrypter * e,   String s );
String decryptString(RSADecrypter * dec, String input);

#endif
