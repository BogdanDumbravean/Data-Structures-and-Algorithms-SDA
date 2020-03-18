#pragma once
#include "SortedBag.h"
#include <stack>

typedef int TComp;
typedef int TElem;

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;
private:
	const SortedBag& sb;
	int node, freq;
	std::stack<int> stack;
	
public:
	SortedBagIterator(const SortedBag& sb);
	void first();
	void next();
	bool valid() const;
	TComp getCurrent() const;
};

