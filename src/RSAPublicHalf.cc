/* RSA Public Half
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

RSAPublicHalf::RSAPublicHalf(int M, int pq) {
	this->setM(M);
	this->setPQ(pq);
}

void RSAPublicHalf::setM(int M) {
	this->M = M;
}

void RSAPublicHalf::setPQ(int pq) {
	this->pq = pq;
}

int RSAPublicHalf::getPQ() {
	return this->pq;
}

int RSAPublicHalf::getM() {
	return this->M;
}
