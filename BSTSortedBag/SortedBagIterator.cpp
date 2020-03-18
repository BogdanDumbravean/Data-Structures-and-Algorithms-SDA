#include "pch.h"
#include "SortedBagIterator.h"
#include <iostream>

using namespace std;


SortedBagIterator::SortedBagIterator(const SortedBag& sb) : sb(sb)
{
	first();
}

void SortedBagIterator::first()
{
	node = sb.root;
	while (node != -1) {
		stack.push(node);
		node = sb.tree[node].getLeft();
	}

	if (stack.empty() == false) {
		node = stack.top();
		freq = 1;
	}
	else {
		node = -1;
		freq = -1;
	}
}

void SortedBagIterator::next()
{
	if (!valid()) {
		throw std::runtime_error{ "" };
	}
	//cout << node << ' ' << sb.tree[node].getValue() << ' ' << getCurrent() << '\n';
	if (freq < sb.tree[node].getFreq()) {
		freq++;
		return;
	}

	node = stack.top(); 
	stack.pop();

	if (sb.tree[node].getRight() != -1) {
		node = sb.tree[node].getRight();
		while (node != -1) {
			stack.push(node);
			node = sb.tree[node].getLeft();
		}
	}

	if (stack.empty() == false) {
		
		node = stack.top();
		//cout << node << ' ' << sb.tree[node].getValue() << '\n';
		freq = 1;
	}
	else {
		node = -1;
		freq = -1;
	}
}

bool SortedBagIterator::valid() const
{
	return node != -1 && freq != -1;
}

TComp SortedBagIterator::getCurrent() const
{
	if (!valid()) {
		throw std::runtime_error{ "" };
	}
	return sb.tree[node].getValue();
}


