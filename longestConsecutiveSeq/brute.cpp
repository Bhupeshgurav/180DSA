// sort the array and run a for loop to find the longest consecutive sequence

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> nums)
{
    // edge case
    if (nums.size() == 0)
    {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int prev = nums[0];
    int cur = 1;
    int ans = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == prev + 1)
        {
            cur++;
        }
        else if (nums[i] != prev)
        {
            cur = 1;
        }
        prev = nums[i];
        ans = max(ans, cur);
    }
    return ans;
}

int main()
{
    vector<int> arr{100, 200, 1, 2, 3, 4, 5, 6, 7}; // Output: 4
    int lon = longestConsecutive(arr);
    cout << lon << endl;
}
