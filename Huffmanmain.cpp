#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int WIDTH = 12;

unordered_map<char, int> buildFrequencyTable(const string);
void printMap(unordered_map<char, int> map);

int main() {
	string decoded; // Word to be encoded

	cout << "Enter the string to be encoded:\n";
	getline(cin, decoded);
	cout << endl;

	unordered_map<char, int> frequencyTable = buildFrequencyTable(decoded);
	printMap(frequencyTable);

	return 0;
}

// Constructs a map of characters and their frequencies based on the string parameter
unordered_map<char, int> buildFrequencyTable(const string word) {
	unordered_map<char, int> map; // <character, frequecy>

	for (char letter : word) {
		++map[letter]; // If the current letter already exists, it simply increments its frequency. Otherwise, it creates a new element with that key and initializes its value using the default constructor of the value type - in our case 'int'. After this implicit initialization, the value is incremented to 1.
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