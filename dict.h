#include <string>
#include<vector>
using namespace std;
class Dictionary
{
  public:
    Dictionary()
    {
        // TODO: Your code here.
    }

    void insert(string word)
    {
		
		
			trie.insert(word);
		
    }

    bool search(string word)
    {
		vector<string> temp;
		findallstrings(temp, word,trie);//all possible solution
		for (int i = 0; i < temp.size(); i++)
		{
			if (trie.search(temp[i]))
			{
				return true;
			}
		}
		return false;
    }
private:

	void findallstrings(vector<string> &temp,string word,Trie &trie)
	{
		bool flag = true;
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == '*')
			{
				flag = false;
				for (int j = 0; j < 26; j++)
				{
					string temp1 = word;
					temp1[i] = 'a' + j;
					string temp2 = temp1.substr(0, i+1);
					if (!trie.isendofword(temp2))//if there is branches below it
					{
						findallstrings(temp, temp1,trie);
					}
				}
				break;
			}
		}
		if (flag)//in temp,there is no'*' anymore
		{
			temp.push_back(word);
		}

	}
	Trie trie;
};
