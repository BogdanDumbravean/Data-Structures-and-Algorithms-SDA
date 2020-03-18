#pragma once
#include <utility>
#include "SortedBagIterator.h"
#include "NodeBST.h"

typedef int TComp;

typedef int TElem;

typedef bool(*Relation)(TComp, TComp);

class SortedBagIterator;

class SortedBag {
	friend class SortedBagIterator;

private:
	NodeBST *tree;
	int root, len, cap, firstFree;
	Relation r;
	
	void resize();
	int removeRecursively(int node, TComp e, bool &removed);
	TComp findMax(int root);
public:

	int nrUniqueElements() const;

	//constructor

	SortedBag(Relation r);



	//adds an element to the sorted bag

	void add(TComp e);



	//removes one occurrence of an element from a sorted bag

	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)

	bool remove(TComp e);



	//checks if an element appearch is the sorted bag

	bool search(TComp e) const;



	//returns the number of occurrences for an element in the sorted bag

	int nrOccurrences(TComp e) const;



	//returns the number of elements from the sorted bag

	int size() const;



	//returns an iterator for this sorted bag

	SortedBagIterator iterator() const;



	//checks if the sorted bag is empty

	bool isEmpty() const;



	//destructor

	~SortedBag();

};