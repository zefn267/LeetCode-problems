class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for (int i = 0; i < wordList.size(); i++) {
            words.insert(wordList[i]);
        }

        if (words.find(endWord) == words.end()) {
            return 0;
        }

        auto answer = bfs(beginWord, words);

        return answer[endWord];
    }

    unordered_map<string, int> bfs(string beginWord, unordered_set<string>& words) {
        queue<string> q;
        unordered_set<string> used;
        unordered_map<string, int> d;
        q.push(beginWord);
        used.insert(beginWord);
        d[beginWord] = 1;
        
        while (!q.empty()) {
            string v = q.front();
            q.pop();
            for (auto to: getNeighbours(words, v)) {
                if (used.find(to) == used.end()) {
                    used.insert(to);
                    q.push(to);
                    d[to] = d[v] + 1;
                }
            }
        }

        return d;
    }

    vector<string> getNeighbours(unordered_set<string>& words, string word) {
        vector<string> neighbours;
        
        for (int i = 0; i < word.size(); i++) {
            char letter = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (words.find(word) != words.end()) {
                    neighbours.push_back(word);
                }
            }
            word[i] = letter;
        }

        return neighbours;
    }
};