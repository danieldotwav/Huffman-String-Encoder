#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include "Huffman.h"
using namespace std;

const int WIDTH = 12;

// Custom operator for the priority queue
struct Compare {
	// This creates a max heap based on frequency
	bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
		return a.second < b.second;
	}

	// For a min heap, simply reverse the comparison 
	/*
	bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
		return a.second > b.second;
	}
	*/
};

unordered_map<char, int> buildSortedFrequencyTable(const string word);
void printMap(unordered_map<char, int> map);

int main() {
	string decoded; // Word to be encoded

	cout << "Enter the string to be encoded:\n";
	getline(cin, decoded);
	cout << endl;

	unordered_map<char, int> sortedFrequencyTable = buildSortedFrequencyTable(decoded);
	//printMap(sortedFrequencyTable);

	return 0;
}

// Constructs a map of characters and their frequencies based on the string parameter
unordered_map<char, int> buildSortedFrequencyTable(const string word) {
	unordered_map<char, int> map; // <character, frequecy>

	// Build the frequency table
	for (char letter : word) {
		++map[letter]; // If the current letter already exists, it simply increments its frequency. Otherwise, it creates a new element with that key and initializes its value using the default constructor of the value type - in our case 'int'. After this implicit initialization, the value is incremented to 1.
	}

	// Use a priority queue to sort the characters by frequency
	priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;

	// Insert elements in to the priority queue
	for (const auto& pair : map) {
		pq.push(pair);
	}

	// Print characters and frequencies in order of decreasing frequency (if max heap)
	cout << left << setw(WIDTH) << "Character" << setw(WIDTH) << "Frequency" << endl;
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		cout << setw(WIDTH) << top.first << setw(WIDTH) << top.second << endl;
	}

	return map;
}

void printMap(unordered_map<char, int> map) {
	if (map.empty()) {
		cout << "\n\nEMPTY MAP - NO LETTERS FOUND\n\n";
	}
	else {
		cout << left << setw(WIDTH) << "Character" << setw(WIDTH) << "Frequency" << endl;
		for (const auto& pair : map) {
			cout << setw(WIDTH) << pair.first << setw(WIDTH) << pair.second << endl;
		}
	}
}