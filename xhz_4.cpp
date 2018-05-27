
#include<iostream>
#include<vector>
using namespace std;

class Vector2D {
vector<vector<int> > ::iterator i, iEnd;
int j = 0;
public:
Vector2D(vector<vector<int> >& vec2d) {
i = vec2d.begin();
iEnd = vec2d.end();
}
int next() {
return (*i)[j++];
}
bool hasNext() {
while (i != iEnd&&j == (*i).size()) {
++ i;
j = 0;
}
return i != iEnd;
}
};

int main()
{
int control=0;
while (control != 999) {
int row=0,col=0,data=0;
int count = 0;
cout << "输入向量个数：" << endl;
cin >> row;
vector<vector<int> > a(row);
for (int i = 0; i < row; i++) {
cout << "输入第"<<i+1<<"个向量数字个数：" << endl;
cin >> col;
a[i].resize(col);
cout << "请依次输入第"<<i+1<<"个向量的"<<col<<"个数：" << endl;
for (int k = 0; k < col; k++) {
cin >> data;
a[i][k] = data;
}
}
cout << "转化前：" << endl;
cout << "["<<endl;
for (int i = 0; i < a.size(); i++) {
cout << "  [";
for (int m = 0; m < a[i].size(); m++) {
cout << a[i][m]<<" ";
}
cout << "  ]"<<endl;
}
cout << "]" << endl;
Vector2D test = Vector2D(a);
int result[999];
while (test.hasNext()) {
result[count] = test.next();
count++;
}
cout << "转化后" << endl;
cout << "[";
for (int i = 0; i < count; i++) {
cout << result[i]<<" ";
}
cout << "]"<<endl;
cout << "请输入向量个数，输入999退出程序" << endl;
cin >> control;
}
    return 0;
}


