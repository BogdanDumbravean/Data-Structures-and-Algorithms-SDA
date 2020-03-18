#include "pch.h"
#include "SortedBag.h"


SortedBag::SortedBag(Relation r) : r(r), root(-1), len(0), cap(10), firstFree(0)
{
	// theta(1)
	tree = new NodeBST[cap];
}

void SortedBag::add(TComp e)
{
	//	O(log n) 

	if (firstFree == cap) 
		resize();

	tree[firstFree].setValue(e);
	tree[firstFree].setFreq(1);
	tree[firstFree].setLeft(-1);
	tree[firstFree].setRight(-1);

	int pos = root, parent = -1;
	while (pos != -1) {
		parent = pos;
		if (e == tree[pos].getValue()) {
			tree[pos].setFreq(tree[pos].getFreq() + 1);
			len++;
			return;
		}
		else if (r(e, tree[pos].getValue())) 
			pos = tree[pos].getLeft();
		else                            
			pos = tree[pos].getRight();
	}


	if (root == -1) 
		root = firstFree;
	else if (r(e, tree[parent].getValue()))
		tree[parent].setLeft(firstFree);
	else               
		tree[parent].setRight(firstFree);
	
	++firstFree;
	while (firstFree < cap && !tree[firstFree].isNull())
		++firstFree;

	len++;
	return;
}

bool SortedBag::remove(TComp e)
{
	// O(log n)
	bool removed = false; 
	root = removeRecursively(root, e, removed);
	if (removed)
		len--;
	return removed;
}

bool SortedBag::search(TComp e) const {
	// O(log n)
	int pos = root;

	while (pos != -1) {
		if (tree[pos].getValue() == e)
			return true;
		if (r(e, tree[pos].getValue())) {
			pos = tree[pos].getLeft();
		}
		else {
			pos = tree[pos].getRight();
		}
	}
	return false;
}

int SortedBag::nrOccurrences(TComp e) const
{
	// O(log n)
	int pos = root;

	while (pos != -1) {
		if (tree[pos].getValue() == e)
			return tree[pos].getFreq();
		if (r(e, tree[pos].getValue())) {
			pos = tree[pos].getLeft();
		}
		else {
			pos = tree[pos].getRight();
		}
	}
	return 0;
}

int SortedBag::size() const
{
	// theta(1)
	return len;
}

SortedBagIterator SortedBag::iterator() const
{
	// theta(1)
	return SortedBagIterator(*this);
}

int SortedBag::removeRecursively(int node, TComp e, bool &removed) {
	// O(log n)
	if (node == -1)
		return -1;//node;

	if (e == tree[node].getValue()) {
		removed = true;
		if (tree[node].getFreq() > 1) {
			tree[node].setFreq(tree[node].getFreq() - 1);
			return node;
		}
		else if (tree[node].getLeft() == -1) { 
			int rightSon = tree[node].getRight();
			tree[node] = NodeBST();
			return rightSon;
		}
		else if (tree[node].getRight() == -1) {
			int leftSon = tree[node].getLeft();
			tree[node] = NodeBST();
			return leftSon;
		}

		int maxNode = findMax(tree[node].getLeft());
		tree[node].setValue(tree[maxNode].getValue());
		tree[node].setLeft(removeRecursively(tree[node].getLeft(), tree[maxNode].getValue(), removed));
	}
	else if (r(e, tree[node].getValue())) {
		tree[node].setLeft(removeRecursively(tree[node].getLeft(), e, removed));
	}
	else {
		tree[node].setRight(removeRecursively(tree[node].getRight(), e, removed));
	}
	return node;
}

TComp SortedBag::findMax(int root) {
	// O (log n)
	int currentNode = root, maxNode = root;
	TComp maximum;

	while (currentNode != -1) {
		maximum = tree[currentNode].getValue();
		maxNode = currentNode;
		currentNode = tree[currentNode].getRight();
	}
	return maxNode;
}

int count(NodeBST* tree, const int& node) {
	if (node == -1)
		return 0;
	int c = 0;
	c += count(tree, tree[node].getLeft());
	c += count(tree, tree[node].getRight());
	return c + 1;
}

int SortedBag::nrUniqueElements() const
{
	// O(n)
	return count(tree, root);
}

bool SortedBag::isEmpty() const
{
	// theta(1)
	return len == 0;
}

SortedBag::~SortedBag()
{
	// theta(1)
	delete[] tree;
}

void SortedBag::resize() {
	// theta(n)
	NodeBST *newTree = new NodeBST[cap * 2];
	for (int i = 0; i < cap; ++i) {
		newTree[i].setValue(tree[i].getValue());
		newTree[i].setFreq(tree[i].getFreq());
		newTree[i].setLeft(tree[i].getLeft());
		newTree[i].setRight(tree[i].getRight());
	}
	delete[] tree;
	tree = newTree;
	firstFree = cap;
	cap *= 2;
}

