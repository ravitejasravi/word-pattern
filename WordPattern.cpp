class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char, string> mp;
        int j = -1;

        for(int i = 0; i < pattern.length(); i++) {
            
            string temp = "";

            for(j = ++j; j < s.length(); j++) {

                if(s[j] == ' ')
                    break;

                temp += s[j];

            }
            
            if(mp[pattern[i]] != temp && mp[pattern[i]].length() != 0)
                return false;

            mp[pattern[i]] = temp;
            
        }

        unordered_map<string, string> duplicate;

        for(auto i = mp.begin(); i != mp.end(); i++) {

            if(duplicate[i->second].length() != 0)
                return false;

            duplicate[i->second] = i->first;

        }

        if(j != s.length()) return false;

        return true;
    }
};