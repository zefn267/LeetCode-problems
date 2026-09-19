class Solution {
public:
    string shortestPalindrome(string s) {
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());

        vector<int> pi = prefix_function(s + "#" + s_rev);

        string sub_s = s.substr(pi[pi.size() - 1]);
        reverse(sub_s.begin(), sub_s.end());

        return sub_s + s;
    }

    vector<int> prefix_function (string s) {
        int n = s.size();
        vector<int> pi (n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]){
                    j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            pi[i] = j;
        }

        return pi;
}
};