// BSTSortedBag.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedBag.h"
#include <assert.h>

bool relation(TComp e1, TComp e2) {
	return e1 <= e2;
}

void testNew() {
	SortedBag sb(relation);
	sb.add(5);
	sb.add(6);
	sb.add(0);
	sb.add(5);
	sb.add(10);
	sb.add(8);

	assert(sb.nrUniqueElements() == 5);
}

int main()
{
	testAll();
	testAllExtended();
	testNew();
	return 0;
}
