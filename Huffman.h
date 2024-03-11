#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <algorithm>

class HuffmanNode {
public:
	char symbol;
	unsigned long codeword, freq;
	unsigned int runLen, codewordLen;
	HuffmanNode* left, * right;

	HuffmanNode() : left(0), right(0) {}
	HuffmanNode(char s, unsigned long f, unsigned int r, HuffmanNode* lt = 0, HuffmanNode* rt = 0) {
		symbol = s;
		freq = f;
		runLen = r;
		left = lt;
		right = rt;
	}
};

class ListNode {
public:
	HuffmanNode* tree;
	ListNode* next, * prev;

	ListNode() : next(0), prev(0) {}
	ListNode(ListNode* n, ListNode *p) : next(n), prev(p) {}
};

class HuffmanCode {

};


#endif