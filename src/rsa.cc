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

#include <iostream>

/**
 * Output a message to stdout, in our cute little format.
 * 
 * @param e   The encrypter object to use
 * @param msg Message to output
 */
void printEncodedMessage( RSAEncrypter * e, String msg ) {
	for ( unsigned int i = 0; i < msg.length(); ++i ) {
		std::cout << e->encrypt(msg[i]) << "|";
	}
	std::cout << "-1" << std::endl;
}

int main ( int argc, char ** argv ) {
	RSAPrivateHalf   privateHalf( 7193, 113, 109, 107 );
	RSAPublicHalf *  publicHalf = privateHalf.getPublicHalf();

	RSAEncrypter     encrip(publicHalf);
	RSADecrypter     decrip(&privateHalf);

	String message = "Hello, World!";
	
	printEncodedMessage(&encrip, message);
	
	return 0;
}
