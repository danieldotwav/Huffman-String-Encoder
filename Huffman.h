#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

struct HuffmanNode {
	char symbol;
	int frequency;
	HuffmanNode* left, * right;

	HuffmanNode() : left(nullptr), right(nullptr) {}
	HuffmanNode(char d, int f) : symbol(d), frequency(f), left(nullptr), right(nullptr) {}
};

// Custom operator for the priority queue
struct Compare {
	bool operator()(HuffmanNode* left, HuffmanNode* right) {
		return left->frequency > right->frequency;
	}
};

class HuffmanTree {
private:
	HuffmanNode* root;

	void deleteTree(HuffmanNode* node);
	void buildEncodingMap(HuffmanNode* node, string str, map<char, string>& huffmanCode);

public:
	HuffmanTree() : root(nullptr) {}

	// Destructor to clean up memory
	~HuffmanTree() { deleteTree(root); }

	void buildHuffmanTree(map<char, int>& freq);
	map<char, std::string> getEncodingMap();
	void buildTreeFromFrequencyMap(const map<char, int>& freq);
	string encode(const string& data);
	string decode(const string& encodedString);
};


#endif