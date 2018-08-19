#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int> Edges;
typedef vector<Edges> Trie;

static Trie build_trie(vector<string> &patterns)
{
	Trie t(1);

	for (size_t i = 0; i < patterns.size(); i++) {
		string &pattern = patterns[i];
		int	current_node = 0;

		for (size_t j = 0; j < pattern.size(); j++) {
			char c = pattern[j];
			Edges::iterator it = t[current_node].find(c);

			if (it != t[current_node].end()) {
				current_node = it->second;
			} else {
				int new_node = t.size();

				t.push_back(Edges());
				t[current_node].insert(make_pair(c, new_node));
				current_node = new_node;
			}
		}
	}

	return t;
}

int main()
{
	size_t n;
	cin >> n;
	vector<string> patterns;

	for (size_t i = 0; i < n; i++) {
		string s;
		cin >> s;
		patterns.push_back(s);
	}

	Trie t = build_trie(patterns);

	for (size_t i = 0; i < t.size(); ++i) {
		for (const auto & j : t[i]) {
			cout << i << "->" << j.second << ":" << j.first << "\n";
		}
	}

	return 0;
}
