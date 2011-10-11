/* RSA Encryption Class
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

#include "RSAPublicHalf.hh"

#ifndef RSAENCRYPTER_HH_
#define RSAENCRYPTER_HH_ FOO

class RSAEncrypter {
	private:
		RSAPublicHalf * pub;
		
	public:
		RSAEncrypter(RSAPublicHalf * pub);
		int encrypt( int X );
		int encrypt( int X, int off );
};

#endif
