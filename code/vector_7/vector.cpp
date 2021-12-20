#include <iostream>
#include <vector>
using namespace std;
int main()
{
	const int N = 6;
    const int c = 8;
    int A[N];    //定义一个数组
    for(int i = 0; i < N; ++i)
    	A[i] = c;
    vector<int> v(N,c);    //定义一个向量
    for(size_t i = 0; i < v.size(); ++i) //遍历
    	cout << v[i] << ' ';
    cout << endl;
    vector<int> v1 = {1,2,3,4,5};    //定义另一个向量
    v1.push_back(6);//增加
    v1.pop_back();//删除
    cout << v1.front() << ' ' << v1.back() << endl;
    for(auto iter = v1.begin(); iter != v1.end(); ++iter)
    	cout << *iter << ' ';
    cout << endl;
    return 0;
}