#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

struct SuffixCmp {
	SuffixCmp(const string &_text) : text(_text) {}

	bool operator()(int i, int j) const
	{
		return text.substr(i) < text.substr(j);
	}

	const string &text;
};

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
static vector<int> BuildSuffixArray(const string &text)
{
	vector<int> result;
	int n = (int)text.size();

	for (int i = 0; i < n; i++) {
		result.push_back(i);
	}

	sort(result.begin(), result.end(), SuffixCmp(text));

	return result;
}

int main()
{
	string text;
	cin >> text;
	vector<int> suffix_array = BuildSuffixArray(text);
	for (int i = 0; i < suffix_array.size(); ++i) {
		cout << suffix_array[i] << ' ';
	}
	cout << endl;

	return 0;
}
