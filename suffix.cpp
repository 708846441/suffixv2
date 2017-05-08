#include<string>
#include<vector>
#include<iostream>
#include <fstream>
using namespace std;

int main()
{
	cout << "please input the number of letters of suffix" << endl;
	int number;
	cin >> number;
	ifstream fin("dictionary.txt");
	string word;
	vector<string> suffix_v;
	vector<vector<string>> words_v;
	int flag = 0;
	while (getline(fin, word))
	{
		if (word.size() < number)continue;
		int size = word.size();
		string suf = word.substr(size - number);
		if (suffix_v.size() == 0)
		{
			suffix_v.push_back(suf);
			vector<string>word_v;
			word_v.push_back(word);
			words_v.push_back(word_v);
		}
		else
		{
			for (int i = 0; i < suffix_v.size(); ++i)
			{
				if (suffix_v[i] == suf)
				{
					words_v[i].push_back(word);
					flag = 1;
				}
			}
			if (flag == 0)
			{
				suffix_v.push_back(suf);
				vector<string>word_v;
				word_v.push_back(word);
				words_v.push_back(word_v);
			}
		}
	}
	vector<int> cnt_v(suffix_v.size());
	for (int i = 0; i < suffix_v.size(); ++i)
	{
		cnt_v[i] = words_v[i].size();
	}
	int suffix_number = 10;
	while (suffix_number)
	{
		int max_index = 0;
		for (int i = 0; i < cnt_v.size(); ++i)
		{
			if (cnt_v[i] > cnt_v[max_index])
			{
				max_index = i;
			}
		}
		string max_suffix = suffix_v[max_index];
		int max_cnt = cnt_v[max_index];
		cout << max_suffix << "\t" << max_cnt << endl;
		cnt_v[max_index] = 0;
		--suffix_number;
	}
	cout << "please enter a suffix to query" << endl;
	string query;
	cin >> query;
	ifstream Fin("dictionary.txt");
	vector<string> words;
	while (getline(Fin, word))
	{
		if (word.size() > query.size() && word.substr(word.size() - query.size()) == query)
			words.push_back(word);
	}
	int words_number = words.size();
	while (words_number)
	{
		int max_index = 0;
		for (int i = 0; i < words.size(); ++i)
		{
			if (words[i] > words[max_index])
			{
				max_index = i;
			}
		}
		string max_word = words[max_index];
		cout << max_word << endl;
		words[max_index] = "";
		--words_number;
	}
	system("pause");
	return 0;
}