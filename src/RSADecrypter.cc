/* RSA Decryption Class
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

#include "RSADecrypter.hh"
#include "RSACommon.hh"

/**
 * Basic constructor for the RSADecrypter class.
 * 
 * @param priv Private goodies to use
 */
RSADecrypter::RSADecrypter(RSAPrivateHalf * priv) {
		this->priv = priv;
}

/**
 * Decrypt an int to, well, another int. Most of the time this should
 * return a char, but it can be anything, really.
 * 
 * @param Y thing to decrypt
 * @return cleartext thinger
 */
int RSADecrypter::decrypt( int Y ) {	
	int crypt = powerMod( Y, this->priv->getN(), this->priv->getPQ() );
	return crypt;
}

/**
 * Thing to decrypt, using the offset given.
 * 
 * @param Y   Thing to decrypt
 * @param off offset to use
 * @return cleartext thinger
 */
int RSADecrypter::decrypt( int Y, int off ) {
	int ret = this->decrypt(Y);
	ret = ret - off;
	return ret;
}

