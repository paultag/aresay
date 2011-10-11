/* RSA common routines
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

#include "RSACommon.hh"

/**
 * Preform a exponent operation, working in modulo `mod`.
 * 
 * In the form of: X ^ N % mod
 * 
 * @param x   base to push to an exponent
 * @param n   exponent to rasie the base to
 * @param mod modulo env to work in
 */
int powerMod( int x, int n, int mod ) {
    long y = x;
    int ret = 1;
    while ( n > 0 ) {
        if ( ( n & 1 ) == 1 )
            ret = (int) ((ret * y) % mod);
        n = n >> 1;
        y = ((y * y) % mod);
    }
    return ret;
}

