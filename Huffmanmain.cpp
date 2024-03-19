#include "Huffman.h"
#include <unordered_map>
using namespace std;

const int WIDTH = 12;

map<char, int> buildFrequencyTable(const string word);
void printMap(map<char, int> map);

int main() {
	string data; // Word to be encoded

	cout << "Enter the string to be encoded:\n";
	getline(cin, data);
	cout << endl;

	// Create a container to store the frequency of characters
	map<char, int> frequencyTable = buildFrequencyTable(data);
	printMap(frequencyTable); // For testing purposes
	cout << endl;

	HuffmanTree huffmanTree;
	huffmanTree.buildHuffmanTree(frequencyTable);

	// 
	map<char, string> huffmanCode = huffmanTree.getEncodingMap();

	// Display the Huffman Codes
	cout << "Huffman Codes are:\n\n";
	for (const auto& pair : huffmanCode) {
		cout << pair.first << " " << pair.second << endl;
	}

	// Encode then print data
	string encodedString = huffmanTree.encode(data);
	cout << "\nThe encoded string is:\n" << encodedString << endl;
	cout << "\n**BITS REQUIRED: " << encodedString.length() << endl;

	// Decode then print data
	string decodedString = huffmanTree.decode(encodedString);
	cout << "\nThe decoded string is:\n" << decodedString << endl;

	return 0;
}

// Constructs a map of characters and their frequencies based on the string parameter
map<char, int> buildFrequencyTable(const string word) {
	map<char, int> map; // <character, frequecy>

	// Build the frequency table
	for (char letter : word) {
		++map[letter]; // If the current letter already exists, it simply increments its frequency. Otherwise, it creates a new element with that key and initializes its value using the default constructor of the value type - in our case 'int'. After this implicit initialization, the value is incremented to 1.
	}

	return map;
}

void printMap(map<char, int> map) {
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