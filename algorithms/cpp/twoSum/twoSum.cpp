#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++){
			if (m.find(target-nums[i]) == m.end()){
				m[nums[i]] = i;
			}else{
				result.push_back(m[target-nums[i]]);
				result.push_back(i);
			}
		}  
		return result;
    }
};

int main(){
	vector<int> nums,result;
	int target = 9;
	Solution solution;
	
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	result = solution.twoSum(nums,target);
	vector<int>::iterator  it;
	for (it = result.begin(); it != result.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
