/*
 * codetable.h
 *
 *  Created on: 13 авг. 2017 г.
 *      Author: pix
 */

#ifndef CODETABLE_H_
#define CODETABLE_H_

typedef unsigned char byte;

class CodeTable {
	byte lBound;
	byte hBound;
	byte *array;

public:
	CodeTable(byte low, byte high, byte* iniTable=0);
	CodeTable(const CodeTable &src);
	~CodeTable();
	byte& operator[](byte i);
};

#endif /* CODETABLE_H_ */
