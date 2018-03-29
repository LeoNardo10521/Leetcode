#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map <string, int> record;
		vector <int> ans;
		for (string word : words) {
			record[word]++;
		}
		int ls = s.length(), lw = words[0].length(), num = words.size();
		for (int i = 0; i + num*lw <= ls; i++) {
			int j = i;
			unordered_map<string, int> observe;
			int k;
			for (k = 0; k<num && j + k*lw <= ls; k++) {
				string tmp = s.substr(j + k*lw, lw);
				auto ind = record.find(tmp);
				if (ind == record.end()) break;
				if (ind->second == observe[tmp]) break;
				observe[tmp]++;

			}
			if (k == num) ans.push_back(i);
		}
		return ans;
	}
};


void main() {
	Solution s1;
	vector<string>words{ "word", "good", "best", "good" };
	vector<int> v1 = s1.findSubstring("wordgoodgoodgoodbestword", words);
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << endl;
}