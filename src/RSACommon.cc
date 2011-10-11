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

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

#include <stdlib.h>

#include "RSACommon.hh"

#include "RSAPrivateHalf.hh"
#include "RSAPublicHalf.hh"

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

std::map<String, String> * getHeaderFile( String fpath ) {
	String s;

	String line;
	std::map<String, String>  * ret = new std::map<String, String>();
	std::ifstream myfile(fpath.c_str());
	if (myfile.is_open()) {
		while ( myfile.good() ) {
			getline (myfile,line);
			std::stringstream ss(line);
			
			getline(ss, s, ':');
			String key = s;
			
			getline(ss, s, ':');
			String val = s;
			
			std::pair<String, String> p(key, val);
			ret->insert(p);
			
		}
		myfile.close();
	} else {
		std::cerr << "File not found" << std::endl;
	}
	return ret;
}

RSAPublicHalf  * getRSAPublicHalfFromFile( String fpath ) {
	std::map<String, String> * toks = getHeaderFile(fpath);
	
	int M  = atoi(toks->find("M")->second.c_str() );
	int pq = atoi(toks->find("pq")->second.c_str());
	/* XXX: ERROR CHECKING */
		
	RSAPublicHalf * ret = new RSAPublicHalf(M, pq);
	
	return ret;
}

RSAPrivateHalf * getRSAPrivateHalfFromFile( String fpath ) {
	std::map<String, String> * toks = getHeaderFile(fpath);
	
	int M  = atoi(toks->find("M")->second.c_str() );
	int N  = atoi(toks->find("N")->second.c_str() );
	int p  = atoi(toks->find("P")->second.c_str() );
	int q  = atoi(toks->find("Q")->second.c_str() );
	/* XXX: ERROR CHECKING */
	
	RSAPrivateHalf * ret = new RSAPrivateHalf(M, N, p, q);
	
	return ret;
}

