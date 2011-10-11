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
#include <sstream>
#include <stdlib.h>
#include <string.h>

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

void printDecodedMessage( RSADecrypter * d, String msg ) {
	std::stringstream ss(msg);
	String s;
	String output = "";
	while (getline(ss, s, '|')) {
		int i = atoi(s.c_str());
		if ( i != -1 )
			output += (char)d->decrypt(i);
		else
			break;
	}
	std::cout << output << std::endl;
}

String readStdin() {
	String ret = "";
	String input_line;
	
	while(std::cin) {
		getline(std::cin, input_line);
		ret += input_line;
	}
	
	return ret;
}

int main ( int argc, char ** argv ) {
	RSAPrivateHalf   privateHalf( 7193, 113, 109, 107 );
	RSAPublicHalf *  publicHalf = privateHalf.getPublicHalf();

	RSAEncrypter     encrip(publicHalf);
	RSADecrypter     decrip(&privateHalf);

	String action = "";

	if ( argc > 1 ) {
		if ( strcmp(argv[1], "-d") == 0 ) {
			action = "decode";
		} else if ( strcmp(argv[1], "-e") == 0 ) {
			action = "encode";
		}
	} else {
		std::cout << "Error in usage" << std::endl;
	}
	
	if ( action != "" ) {
		String message = readStdin();
		if ( strcmp(action.c_str(), "encode") == 0 ) {
			printEncodedMessage(&encrip, message);
		}
		if ( strcmp(action.c_str(), "decode") == 0 ) { // Fix this crap
			printDecodedMessage(&decrip, message);
		}
	}
	
	//printEncodedMessage(&encrip, message);
	//printDecodedMessage(&decrip, message);

	/*String message = "Hello, World!";
	printEncodedMessage(&encrip, message);
	
	String ehlo =
	"8605|4183|108|108|3402|6298|3599|3617|3402|2447|108|3331|11369|-1";
	printDecodedMessage(&decrip, ehlo);*/
	
	return 0;
}
