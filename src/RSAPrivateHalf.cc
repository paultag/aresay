/* RSA Private Half of the pimes and such
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

#include "RSAPrivateHalf.hh"

#include <malloc.h>
#include <iostream>

RSAPrivateHalf::RSAPrivateHalf(int M, int N, int p, int q) {
	this->setM(M);
	this->setN(N);
	this->setP(p);
	this->setQ(q);
}

void RSAPrivateHalf::setM( int M ) {
	this->M = M;
}

void RSAPrivateHalf::setN( int N ) {
	this->N = N;
}

void RSAPrivateHalf::setP( int p ) {
	this->p = p;
}

void RSAPrivateHalf::setQ( int q ) {
	this->q = q;
}

int RSAPrivateHalf::getM() {
	return this->M;
}

int RSAPrivateHalf::getN() {
	return this->N;
}

int RSAPrivateHalf::getP() {
	return this->p;
}

int RSAPrivateHalf::getQ() {
	return this->q;
}

int RSAPrivateHalf::getPQ() {
	return ( this->p * this->q );
}

RSAPublicHalf * RSAPrivateHalf::getPublicHalf() {
	RSAPublicHalf * pubHalf = new RSAPublicHalf(
		this->getM(), this->getPQ() );
	return pubHalf;
}
