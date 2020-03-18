#pragma once

typedef int TComp;
#define INF -(1<<30)

class NodeBST
{
private:
	TComp value;
	int freq;
	int left, right;
public:
	NodeBST(TComp val = INF, int freq = 0, int left = -1, int right = -1) :value(val), left(left), right(right) {}
	TComp getValue() const;
	void setValue(TComp value);
	int getFreq() const;
	void setFreq(int frequency);
	int getLeft() const;
	void setLeft(int left);
	int getRight() const;
	void setRight(int right);
	bool isNull();
};

