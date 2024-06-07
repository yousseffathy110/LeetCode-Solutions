#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <memory>

using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  const string* word = nullptr;
  ~TrieNode() {
    for (auto& child : children) {
      delete child.second;
    }
  }
};

class Solution {
 public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    for (const string& word : dictionary)
      insert(word);

    string ans;
    istringstream iss(sentence);
    ans.reserve(sentence.size());

    bool firstWord = true;
    for (string s; iss >> s;) {
      if (!firstWord) {
        ans += ' ';
      }
      ans += search(s);
      firstWord = false;
    }

    return ans;
  }

  ~Solution() {
    delete root;
  }

 private:
  TrieNode* root = new TrieNode();

  void insert(const string& word) {
    TrieNode* node = root;
    for (const char c : word) {
      if (node->children.find(c) == node->children.end())
        node->children[c] = new TrieNode();
      node = node->children[c];
    }
    node->word = &word;
  }

  string search(const string& word) {
    TrieNode* node = root;
    for (const char c : word) {
      if (node->word)
        return *node->word;
      if (node->children.find(c) == node->children.end())
        return word;
      node = node->children[c];
    }
    return word;
  }
};
