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

#include "RSAEncrypter.hh"
#include "RSACommon.hh"

/**
 * Constructor for the Encrypter class
 * 
 * @param pub Public half of the goodies we're sending to
 */
RSAEncrypter::RSAEncrypter(RSAPublicHalf * pub) {
		this->pub = pub;
}

/**
 * Encrypt an int for transport!
 * 
 * @param X Thing to encrypt
 * @return well, the encrypted int
 */
int RSAEncrypter::encrypt( int X ) {	
	int crypt = powerMod( X, this->pub->getM(), this->pub->getPQ() );
	return crypt;
}

/**
 * Encrypt an int out
 * 
 * @param X Thing to encrypt
 * @param off Offset to use
 * @return encrypted thing
 */
int RSAEncrypter::encrypt( int X, int off ) {
	X = X + off;
	return this->encrypt(X);
}
