#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> stringToChar;
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                stringToChar.push_back(tolower(s[i]));
            }
        } 

        int left = 0;
        int right = stringToChar.size() - 1;

        while (left < right) {
            if (stringToChar[left] == stringToChar[right]) {
                left += 1;
                right -=1;
            }
            else {
                return false;
            }

        }
        return true;
    }
};
