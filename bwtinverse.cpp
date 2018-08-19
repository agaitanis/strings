#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static string InverseBWT(const string &bwt)
{
	if (bwt.empty()) return "";

	string text;
	vector<pair<char, int> > bwt_and_index;

	for (size_t i = 0; i < bwt.size(); i++) {
		bwt_and_index.push_back(make_pair(bwt[i], i));
	}

	sort(bwt_and_index.begin(), bwt_and_index.end());

	int j = bwt_and_index[0].second;

	while (j != 0) {
		j = bwt_and_index[j].second;
		text += bwt[j];
	}
	text += "$";

	return text;
}

int main()
{
	string bwt;
	cin >> bwt;
	cout << InverseBWT(bwt) << endl;

	return 0;
}
