class Solution {
public:
    string minWindow(string s, string t) {
        int required = 0;
        map<char, int> letters;
        for (int i = 0; i < t.size(); i++) {
            if (letters.count(t[i])){
                letters[t[i]] += 1;
                continue;
            }
            letters[t[i]] = 1;
            required++;
        }       
        
        int left = 0, right = -1, len = 0, min_len = 1e9;
        pair<int, int> answer;
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            right++;
            len = right - left + 1;
            if (letters.find(s[right]) != letters.end()) {
                letters[s[right]]--;
                if (letters[s[right]] == 0) {
                    required--;
                }
            }

            while (required == 0) {
                len = right - left + 1;
                if (len < min_len) {
                    min_len = len;
                    answer.first = left;
                    answer.second = min_len;
                }
                if (letters.find(s[left]) != letters.end()) {
                    letters[s[left]]++;
                    if (letters[s[left]] > 0) {
                        required++;
                    }
                }
                left++;
            }
        }

        return s.substr(answer.first, answer.second);
    }
};