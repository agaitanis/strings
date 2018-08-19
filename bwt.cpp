#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static string BWT(const string &text)
{
	int len = text.size();
	vector<string> matrix(len);

	for (int i = 0, j = len - 1; j >= 0; i++, j--) {
		matrix[i] = text.substr(j) + text.substr(0, j);
	}

	sort(matrix.begin(), matrix.end());

	string result;

	for (size_t i = 0; i < matrix.size(); i++) {
		result += matrix[i].back();
	}

	return result;
}

int main()
{
	string text;
	cin >> text;
	cout << BWT(text) << endl;

	return 0;
}
