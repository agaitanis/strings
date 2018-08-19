#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	int next[4];

	Node ()
	{
		fill(next, next + 4, -1);
	}

	bool isLeaf () const
	{
		return (next[0] == -1 && next[1] == -1 && next[2] == -1 && next[3] == -1);
	}
};

static int letterToIndex(char letter)
{
	switch (letter) {
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		case 'T':
			return 3;
		default:
			assert(false);
			return -1;
	}
}

static vector<Node> create_trie(const vector <string> &patterns)
{
	vector<Node> trie(1);

	for (size_t i = 0; i < patterns.size(); i++) {
		const string &pattern = patterns[i];
		int v = 0;

		for (size_t j = 0; j < pattern.size(); j++) {
			char c = pattern[j];
			int c_i = letterToIndex(c);
			int w = trie[v].next[c_i];

			if (w != -1) {
				v = w;
			} else {
				w = trie.size();
				trie.push_back(Node());
				trie[v].next[c_i] = w;
				v = w;
			}
		}
	}

	return trie;
}

static vector <int> solve(const string &text, const vector <string> &patterns)
{
	vector <int> result;
	vector<Node> trie;

	trie = create_trie(patterns);

	for (size_t i = 0; i < text.size(); i++) {
		int v = 0;
		size_t j = i;

		while (true) {
			if (trie[v].isLeaf()) {
				result.push_back(i);
				break;
			}
			if (j >= text.size()) break;

			char c = text[j++];
			int c_i = letterToIndex(c);

			v = trie[v].next[c_i];
			if (v == -1) break;
		}
	}

	return result;
}

int main(void)
{
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++) {
		cin >> patterns[i];
	}

	vector <int> ans = solve(text, patterns);

	for (int i = 0; i < (int) ans.size (); i++) {
		cout << ans[i];
		if (i + 1 < (int) ans.size ()) {
			cout << " ";
		} else {
			cout << endl;
		}
	}

	return 0;
}
