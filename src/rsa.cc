/* RSA Application entry point
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
#include "RSAPublicHalf.hh"
#include "RSAPrivateHalf.hh"
#include "RSAEncrypter.hh"
#include "RSADecrypter.hh"

#include <fstream>
#include <iostream>

int main ( int argc, char ** argv ) {

	if ( argc <= 1 ) {
		std::cerr << "Usage error :(" << std::endl;
		return 1;
	}

	RSAPublicHalf  * publicHalf  = getRSAPublicHalfFromFile(
		"/home/tag/rsa.pub");
	RSAEncrypter  * enc        = new RSAEncrypter(publicHalf);

	RSAPrivateHalf * privateHalf = getRSAPrivateHalfFromFile(
		"/home/tag/rsa.priv");
	RSADecrypter  * dec        = new RSADecrypter(privateHalf);

	

	return 0;
}
