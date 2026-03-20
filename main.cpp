#include <fstream>
#include <vector>

using namespace std;

bool ReadNumbers(vector<unsigned char> &vec, const char s[]) {
	ifstream input(s);
	unsigned char num;

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

/*
void OutputNumbers(const int* numbers, const unsigned int size) {
	ofstream output("out.txt");

	for (int i = 0; i<size; i++)
		output << numbers[i] << ' ';
}
*/

int main(const int argc, const char* argv[]) {
	return 0;
}