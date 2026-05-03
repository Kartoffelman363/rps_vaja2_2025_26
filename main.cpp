#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool ReadNumbers(vector<unsigned char> &vec, const char s[]) {
	ifstream input(s);
	int num;

	if (!input.is_open()) {
		return false;
	}

	while (input >> num) {
		vec.push_back(num);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void OutputNumbers(const unsigned char* numbers, const unsigned int size, ofstream &output) {
	for (int i = 0; i<size; i++)
		output << static_cast<int>(numbers[i]) << ' ';
}

void NThBitCount(vector<int> &C, const vector<unsigned char> &input, const int n) {
	const unsigned char mask = 1 << n;
	for (const unsigned char i : input) {
		C[(i & mask) >> n]++;
	}
}

void NThBitCountingSort(const vector<unsigned char> &input, vector<unsigned char> &output, const int n) {
	// fewer than 2 elements don't need to be sorted
	if (input.size() < 2) {
		output = input;
		return;
	}
	vector C = {0, 0};
	NThBitCount(C, input, n);
	C[1] += C[0];

	const unsigned char mask = 1 << n;
	unsigned int i = input.size();
	do {
		i--;
		output[--C[(input[i] & mask) >> n]] = input[i];
	} while (i > 0);
}

void BinaryRadixSort(vector<unsigned char> &input, vector<unsigned char> &output) {
	for (int i = 0; i < 8; i++) {
		NThBitCountingSort(input, output, i);
		input = output;
	}
}

int main(const int argc, const char* argv[]) {
	vector<unsigned char> A, B;
	if (argc != 2) {
		return 1;
	}
	if (!ReadNumbers(A, argv[1])) {
		return 1;
	}
	ofstream output("out.txt");
	if (A.empty()) {
		return 0;
	}
	B.resize(A.size());

	BinaryRadixSort(A, B);

	OutputNumbers(&B[0],B.size(), output);
	return 0;
}