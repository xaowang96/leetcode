
/**
 * @brief 先有两层循环，确定第一个和第二个数，然后使用双指针法确定剩下两个数
*/
class Solution {
public:
    map<vector<int>, int> resultMap;
    bool findSameVector(const vector<int> &oneNums)
    {
        int ret = false;
        map<vector<int>, int>::iterator iter = resultMap.find(oneNums);
        if(iter != resultMap.end())
            return true;
        resultMap.insert(pair<vector<int>, int>(oneNums, 1));
        return false;
    }
    
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> selectNums;
        // for(int x : nums)
        //     cout << x << " ";
        // cout << endl;
        /**空数组或者数组长度小于4直接返回*/
        if(nums.empty() || (nums.size() < 4))
            return selectNums;
        vector<int> oneNums;
        int sum = 0;
        for(int i = 0; i != nums.size(); i++)
        {
            oneNums.push_back(nums[i]);
            sum += nums[i];
            for(int j = i + 1; j != nums.size(); j++)
            {
                oneNums.push_back(nums[j]);
                sum += nums[j];
                vector<int>::iterator begin = nums.begin() + j + 1;
                vector<int>::iterator end = nums.begin() + nums.size() - 1;
                while(begin != nums.end() && end != nums.end() && begin < end)
                {
                    int tempSum  = *begin + *end;
                    int beginVal = *begin;
                    int endVal = *end;
                    if((sum + tempSum) == target)
                    {
                        oneNums.push_back(*begin);
                        oneNums.push_back(*end);
                        selectNums.push_back(oneNums);
                        oneNums.erase(oneNums.begin() + 2, oneNums.begin() + 4);
                        //cout << "begin ++" << begin - nums.begin()  << endl;
                        while(*begin == beginVal && begin < end)begin ++;
                        //cout << "end --" << endl;
                        while(*end == endVal && end > begin)end --;
                    }
                    else if((sum + tempSum) > target)
                    {
                        while(*end == endVal && end > begin)end --;
                    }
                    else
                    {
                        while(*begin == beginVal && begin < end)begin ++;
                    }
                }
                oneNums.pop_back();
                sum -= nums[j];
                while(j < (nums.size() - 1) && nums[j] == nums[j + 1])
                    j++;
            }
            
            sum = 0;
            oneNums.clear();
            while(i < (nums.size() - 1) && nums[i] == nums[i + 1])
                i++;            
        }
        return selectNums;
    }
};



/**
 * @brief K个数求和为target的通用计算方法，首先需要递归k-2层，然后使用双指针的办法计算两个数和
 * */
class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        int lo = start;
        int hi = nums.size() - 1;
        while(lo < hi)
        {
            int sum = nums[lo] + nums[hi];
            if(sum < target || (lo > start && nums[lo] == nums[lo - 1]))
            {
                lo ++;
            }
            else if(sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
            {
                hi --;
            }
            else if(sum == target)
            {
                res.push_back({nums[lo++], nums[hi--]});
            }
        }
        return res;
    }
    
    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        if(start == nums.size() || (nums[start] * k) > target || target > (nums.back() * k))
            return res;
        if(k == 2)
        {
            return twoSum(nums, target, start);
        }
        for(int i = start; i < nums.size(); i++)
        {
            if(i == start || nums[i - 1] != nums[i])
            {
                for(auto &set : kSum(nums, target - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(res.back().end(), set.begin(), set.end());
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
};