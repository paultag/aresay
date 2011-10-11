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
#include <string.h>

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

	if ( strcmp(argv[1], "encode") == 0 ) {
		std::cout << "Type your message..." << std::endl;
		String input = readStdin();
		int * code = encryptString(enc, input);
		for ( unsigned int i = 0; i < input.length(); ++i )
			std::cout << code[i] << "|";
		std::cout << -1 << std::endl;
	}

	if ( strcmp(argv[1], "decode") == 0 ) {
		std::cout << "Type your message..." << std::endl;
		String input = readStdin();
		String s = decryptString(dec, input);
		std::cout << s << std::endl;
	}

	return 0;
}
