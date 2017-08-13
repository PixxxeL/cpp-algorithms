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
		for (byte idx = 0; idx <= high - lBound && iniTable[idx]; idx++) {
			array[idx] = iniTable[idx];
		}
	}
}

CodeTable::CodeTable(const CodeTable &src) {
	array = new byte[(hBound=src.hBound) - (lBound=src.lBound) + 1];
	for (byte idx = lBound; ; idx++) {
		array[idx - lBound] = src.array[idx - lBound];
		if (idx == hBound) break;
	}
}

CodeTable::~CodeTable() {
	delete[] array;
}

byte& CodeTable::operator[] (byte i) {
	if (i < lBound || i > hBound) {
		throw std::out_of_range("Index is out of range");
	}
	return array[i - lBound];
}
