class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Step 1: Count vowels & mark positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
                lower[s[i] - 'a']++;
                s[i] = '#';
            } 
            else if (s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        // Step 2: Create sorted vowel string
        string ans;

        // Uppercase vowels A-Z
        for (int i = 0; i < 26; i++) {
            char c = 'A' + i;
            while (upper[i]--) ans += c;
        }

        // Lowercase vowels a-z
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while (lower[i]--) ans += c;
        }

        // Step 3: Insert sorted vowels back
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                s[i] = ans[pos++];
            }
        }

        return s;
    }
};