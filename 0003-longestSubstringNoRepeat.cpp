#include <string>

using namespace std;

class Solution {
public:
    /**
     * @brief returns the length of the longest substring without repeating characters
     * time complexity: O(n)
     * memory complexity: O(1)
     */
    int lengthOfLongestSubstring(string s) {
        short strt = 0, len = 1;
        short best_l = 1;
        
        if (s.size() == 0)
            return 0;

        while (len + strt < s.size()){
            if (s.substr(strt, len).find(s[len + strt]) == string::npos){
                len += 1;
                if (len > best_l)
                    best_l = len;
            }
            else {
                strt += 1;
                len -= 1;
            }
        }
        return best_l;
    }
};