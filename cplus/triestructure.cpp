#include<bits/stdc++.h>
using namespace std;


struct trienode
{
    bool isEndofWord;
    struct trienode* children[26];
};

trienode * getnode()
{
    trienode* pnode = new trienode;
    pnode->isEndofWord = false;
    for(int i=0;i<26;i++)
    pnode->children[i] = NULL;
    return pnode;
}

void insert(trienode *root, string key)
{
    int level = key.length();
    struct trienode *pCrawl = root;

    for(int i = 0; i < level ; i++)
    {
        int index = key[i] - 'a';
        if(pCrawl->children[index] == NULL)
        pCrawl->children[index] = getnode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndofWord = true;
}


bool search(trienode* root, string key)
{
     int level = key.length();
    struct trienode *pCrawl = root;

    for(int i = 0; i < level ; i++)
    {
        int index = key[i] - 'a';
        if(pCrawl->children[index] == NULL)
        return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndofWord);
}
int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
  
    struct trienode *root = getnode();
  
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
  
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}