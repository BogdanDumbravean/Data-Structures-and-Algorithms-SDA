#include "pch.h"
#include "NodeBST.h"


TComp NodeBST::getValue() const
{
	return value;
}

void NodeBST::setValue(TComp value)
{
	this->value = value;
}

int NodeBST::getFreq() const
{
	return freq;
}

void NodeBST::setFreq(int frequency)
{
	freq = frequency;
}

int NodeBST::getLeft() const
{
	return left;
}

void NodeBST::setLeft(int left)
{
	this->left = left;
}

int NodeBST::getRight() const
{
	return right;
}

void NodeBST::setRight(int right)
{
	this->right = right;
}

bool NodeBST::isNull()
{
	return value == INF;
}
