/*
 * codetable.cpp
 *
 *  Created on: 13 авг. 2017 г.
 *      Author: pix
 */
#include <stdexcept>
#include "codetable.h"

CodeTable::CodeTable(byte low, byte high, byte* iniTable) {
	if ((hBound = high) < (lBound = low)) {
		throw std::out_of_range("Lower bound is higher than upperone");
	}
	array = new byte[high - low + 1];
	for (byte code = lBound; ; code++) {
		array[code - lBound] = code;
		if (code == hBound) break;
	}
	if (iniTable) {
		//
	}
}


