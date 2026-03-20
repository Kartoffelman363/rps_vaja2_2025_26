#include <fstream>
#include <vector>

using namespace std;

bool ReadNumbers(vector<unsigned char> &vec, const char s[]) {
	ifstream input(s);
	int num;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> num;
		vec.push_back(num);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void OutputNumbers(const unsigned char* numbers, const unsigned int size) {
	ofstream output("out.txt");

	for (int i = 0; i<size; i++)
		output << static_cast<int>(numbers[i]) << ' ';
}

void NThBitCount(vector<int> &C, const vector<unsigned char> &input, const int n) {
	const unsigned char mask = 1 << n;
	for (const unsigned char i : input) {
		C[i & mask >> n]++;
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
}

int main(const int argc, const char* argv[]) {
	vector<unsigned char> I;
	if (argc != 2) {
		return 0;
	}
	if (!ReadNumbers(I, argv[1])) {
		return 0;
	}

	OutputNumbers(&I[0],I.size());
	return 0;
}