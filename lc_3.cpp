class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        string substring = "";
        int longestLength = 0;
        int index = 0;
        
        while(index != s.length()){
            
            if(substring.find(s.at(index)) < substring.length())
            {
                longestLength = (substring.length() > longestLength) ? substring.length() : longestLength; 
                substring = substring.substr(substring.find(s.at(index))+1, substring.length()-substring.find(s.at(index))+1);
        
                substring += s.at(index);
            }
            
            else
            {
                substring += s.at(index);
            }
            
            ++index;
        }

        return substring.length()>=longestLength ? substring.length() : longestLength;
    }
};