#include <iostream>
#include <vector> 
using namespace std;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int result = 0, index = 0;
        // currSum标记了当前数组nums可累加到的最大范围[1, currSum)
        for (int currSum = 1; currSum <= n; )
        {
            // 数组内元素小于currSum时，可累加的sum上限增加为
            // currSum + nums[index]，然后数组索引值加1
            if (index < nums.size() && nums[index] <= currSum)
                currSum += nums[index++];
            else
            {   
                currSum <<= 1; // 添入元素后，可累加的sum范围加倍
                ++result;
            }
        }
        return result;
    }
};
int main()
{
	int n;
	cout<<"请输入n"<<endl;
	cin>>n;
	vector<int> vec;
	 int temp=0;
	 cout << "请按按顺序输入整数，以任意字母结束：" << endl;
	 while(cin >> temp)           //如果不确定输入数字个数，可以用这种方式
	 {
	  vec.push_back(temp);   //填充数据
	 }
	int m;
	Solution solu;
	m=solu.minPatches(vec,n);
	cout<<""<<m<<""<<endl;
	 return 0;
}
