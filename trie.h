#include <string>
#include <iostream>

using namespace std;
const int ALPHABET_SIZE = 26;//it is all lowercase 
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord;
};
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		pNode->children[i] = NULL;
	}

	return pNode;
}

class Trie
{
 public:
    Trie()
    {
        // TODO: Your code here.
    }

    void insert(string word)
    {
		struct TrieNode *temp = root;
		for (int i = 0; i < word.length(); i++)
			{
				int index = word[i] - 'a';//its distance to 'a'
				if (!temp->children[index])
				{
					temp->children[index] = getNode();
				}

				temp = temp ->children[index];
			}
			temp ->isEndOfWord = true;
		
    }

    bool search(string word)
    {
		struct TrieNode *temp = root;
		for (int i = 0; i < word.length(); i++)
		{
				int index = word[i] - 'a';
				if (!temp->children[index])
				{
					return false;
				}

				temp = temp->children[index];
		}
		return (temp != NULL && temp->isEndOfWord);
		
        
    }
	bool isendofword(string word)//if there is no more branch below it, return true
	{

		struct TrieNode *temp = root;
		for (int i = 0; i < word.length(); i++)
		{
			int index = word[i] - 'a';
			//std::cout << word << endl;
		
			if (temp == NULL)
			{
				return true;
			}
			if (temp->children[index]==NULL)
			{
				return true;
			}

			temp = temp->children[index];
		}
		return false;
	}
private:
	TrieNode* root= getNode();
};
