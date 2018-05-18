#include <iostream> 
#include <vector>
#include <string>
#include<fstream>
#include<sstream>  
using namespace std;
class Solution {
private:
    bool m_res;
public:
    long long str2num(string str){
        stringstream ss(str);//定义了一个字符串流，并用一个字符串初始化
        long long n;
        ss >> n;//输入n
        return n;
    }
    string num2str(long long num){
        stringstream ss;
        ss << num;//输出num
        return ss.str();
    }
    void DFS(int len,string num,string s1){
        if(s1 == "") s1 = num.substr(0,len);//从0复制一个子串复制
        if(s1.length() > 1 && s1[0] == '0') return;
        string left = num.substr(len);
        int leftLen = left.length();
        for(int i = 1; i < leftLen; i++){
            string s2 = left.substr(0,i);
            if(s2.length() > 1 && s2[0] =='0') return;
            string sum = num2str(str2num(s1) + str2num(s2));
            string subleft = left.substr(i);
            int subpos = subleft.find(sum);
            if(subpos == 0){
                string finalLeft = subleft.substr(sum.length());
                int subLen = finalLeft.length();
                if(subLen == 0){
                   m_res = true;
                   return;
                }
                DFS(0,subleft,s2);
            }
        }
    }
    bool isAdditiveNumber(string num) {
        vector<string> res;
        int len = num.length();
        m_res = false;
        for(int i = 1; i < len - 1;i++){
            DFS(i,num,"");
            if(m_res) return true;
        }
        return false;
    }
};
int main()
{	
	string num;
	cout<<"请输入一串数字"<<endl;
	cin>>num;
	Solution solu1;
	bool a;
	a=solu1.isAdditiveNumber(num);
	if(a) cout<<"True"<<endl;
	else cout<<"false"<<endl;
	return 0; 
}
