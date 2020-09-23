class Solution {
public:
    void CombLetter(const map<int, string> &phoneMap, const string &dig, int index, string &oneLetterComb, vector<string> &letterComb)
    {
        if(index == dig.size())
        {
            letterComb.push_back(oneLetterComb);
            return ;
        }
        else
        {
            int num = dig[index] - '0';
            auto iter = phoneMap.find(num);
            if(iter == phoneMap.end())
                return ;
            string Temp = iter->second;
            for(int i = 0; i < Temp.size(); i++)
            {
                oneLetterComb.push_back(Temp[i]);
                CombLetter(phoneMap, dig, index + 1, oneLetterComb, letterComb);
                oneLetterComb.pop_back();
            }
        }
        return ;
    }
    
    vector<string> letterCombinations(string digits) {
        map<int, string> phoneMap;
        phoneMap[2] = "abc";
        phoneMap[3] = "def";
        phoneMap[4] = "ghi";
        phoneMap[5] = "jkl";
        phoneMap[6] = "mno";
        phoneMap[7] = "pqrs";
        phoneMap[8] = "tuv";
        phoneMap[9] = "wxyz";
        vector<string> letterComb;
        string oneLetterComb;
        if(digits.empty())
        {
            
        }
        else
        {
            CombLetter(phoneMap, digits, 0, oneLetterComb, letterComb);
        }
        return letterComb;
    }
};