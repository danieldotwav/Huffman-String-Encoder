#include "Huffman.h"

// Function to build the Huffman tree and return its root
void HuffmanTree::buildHuffmanTree(map<char, int>& freq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> heap;

    for (auto& pair : freq) {
        heap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (heap.size() > 1) {
        HuffmanNode* left = heap.top(); heap.pop();
        HuffmanNode* right = heap.top(); heap.pop();
        HuffmanNode* merge = new HuffmanNode('\0', left->frequency + right->frequency);
        merge->left = left;
        merge->right = right;
        heap.push(merge);
    }

    root = heap.top();
    
}

// Recursive function to build the encoding map
void HuffmanTree::buildEncodingMap(HuffmanNode* node, std::string str, std::map<char, std::string>& huffmanCode) {
    if (node == nullptr) return;

    if (node->symbol != '\0') {
        huffmanCode[node->symbol] = str;
    }

    buildEncodingMap(node->left, str + "0", huffmanCode);
    buildEncodingMap(node->right, str + "1", huffmanCode);
}

map<char, std::string> HuffmanTree::getEncodingMap() {
    map<char, string> huffmanCode;
    buildEncodingMap(root, "", huffmanCode);
    return huffmanCode;
}

// Helper function to delete the tree
void HuffmanTree::deleteTree(HuffmanNode* node) {
    if (node == nullptr) return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

void HuffmanTree::buildTreeFromFrequencyMap(const map<char, int>& freq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> heap;

    for (auto& pair : freq) {
        heap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (heap.size() > 1) {
        HuffmanNode* left = heap.top(); heap.pop();
        HuffmanNode* right = heap.top(); heap.pop();
        HuffmanNode* merge = new HuffmanNode('\0', left->frequency + right->frequency);
        merge->left = left;
        merge->right = right;
        heap.push(merge);
    }

    root = heap.top();
}

// Encode the input data using the Huffman tree
string HuffmanTree::encode(const string& data) {
    map<char, string> huffmanCode = getEncodingMap();
    string encodedString;
    for (char c : data) {
        encodedString += huffmanCode[c];
    }
    return encodedString;
}

// Decode the encoded string using the Huffman tree
string HuffmanTree::decode(const string& encodedString) {
    string decodedString;
    HuffmanNode* currentNode = root;
    for (char bit : encodedString) {
        currentNode = bit == '0' ? currentNode->left : currentNode->right;
        if (!currentNode->left && !currentNode->right) {
            decodedString += currentNode->symbol;
            currentNode = root;
        }
    }
    return decodedString;
}