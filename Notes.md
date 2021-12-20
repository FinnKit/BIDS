## 0. 基本情况
极简数据结构课程学习，其中主要使用C++语言，并结合阿里云服务器作为实验机（版本为CentOS 6.7(64位)）。通过服务器的配置，将gcc升级至gcc-6.1.0版本，可以使用C++17版本，正常实现课程中的C++代码。

## 1. 康奈尔(Cornell)笔记
建议使用方格本子，这样方便画线，讲解算法原理。

## 2. 开发环境
语言为C++，这里使用的是现代C++，接近于python。优势：STL（标准库），可以实现常见的数据结构和算法。
编译方式，采用命令行的形式
> Mac的clang：
```Linux
clang ++ -std=c++17 -stdlib=libc++ -O3 ds.cpp;
./a.out;
rm a.out;
```
> Linux的gcc：
```Linux
g++ -std=c++17 -O3 ds.cpp
./a.out;
rm a.out;
```

以上为无脑操作，直接看结果

> Windows的Visual Studio
> 2017社区版，安装c++模块，新建项目...

Win的方法下载的软件较大，这里使用云服务器Linux系统作为实验机

## 3. 课程大纲
第一章：语言基础
第二章：抽象之妙
第三章：性能分析
第四章：向量与链表
第五章：栈与队列
第六章：集合
第七章：字典
第八章：键值与映射
第九章：排序
第十章：优先级队列

参考书：课程讲义，BIDS代码
算法三部曲：《算法导论》（CLRS）《算法设计指南》（Skiena）《算法》（Sedgenick Wayne）

# 第1章 语言基础
## 4. C++输入与输出
采用C++原因：因为有STL，比C多了标准库，是学习数据结构和算法的利器

输出形式：
```c++
include <iostream> //输入输出流
using namespace std; 
int main()
{
	cout << "Hello World" << endl; //endl 换行
	return 0;
}
```
输入形式，a+b问题
```c++
include <iostream> //输入输出流
using namespace std; 
int main()
{
	int a, b;
	cin >> a >> b;
	cout << "a + b = " << a + b << endl; //endl 换行
	return 0;
}
```
## 5. string的简单使用
在C语言中，要建立字符串需要自身定义其长度，如`char s[10]`，对于不知道长度而言，C++语言的string更加方便。
string是一个类，定义方法`string name;`
定义后自身有相关的成员函数，如`name.size()`，获取变量name的长度。
> `.`表示调用该类的成员，相当于“的”，具有一定封装性
> 使用string，需要在开头引入头文件`#include <string>`
> 支持自动类型推导，auto

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name;
	cin >> name;
	cout << "hello, " << name << endl;
	cout << name.size() << endl;
	name = name + name;
	cout << name << endl;
	string a = "c";
	string b = "++";
	auto c = a + b;
	cout << c << endl;
	return 0;
}
```
## 6. 引用
C语言中利用形参与实参进行函数的参数的传递，传值。这样实际上也是利用指针的方法。
C++中也是这样的，引用主要有三种形式：复制、引用、常量引用。

复制，即只是单纯将变量的值复制过来，不改变本体。如复印一本书。
```c++
void FA(int x)
{
	x = 1;
}
```
引用，即将变量本体拿过来，将控制权交给函数。在函数中改变值，变量本体的值也改变。如把书借给他
> 若该变量是一个常量，则将无法修改。
```c++
void FB(int& x)
{
	x = 2;
}
```
常量引用：虽然把本体给拿过来，但是并不能改变本体。如，把书借给他，但不能涂改。
```c++
void FC(const int& x)
{
	cout << x << endl;
}
```
测试：
```c++
#include <iostream>
using namespace std;
void FA(int x)
{
	x = 1;
}
void FB(int& x)
{
	x = 2;
}
void FC(const int& x)
{
	cout << x << endl;
}
int main()
{
	int w = 0;
	FA(w);
    cout << w << endl;
    FB(w);
    cout << w << endl;
    FC(w);
    return 0;
}
```

## 7. 数组和向量
C语言中是数组，如`int A[10]`
而C++中为向量，动态数组，如 `vector<int> v(10)` （其为存放int数据类型的向量，相当于构造函数）。
> 对于没有赋值的，建议马上填充
> 空向量`vector<int> v`
> 在开头要引入头文件`#include <vector>`

向量的初始化
`vector<int> v(10,1)`
`vector<int> v = {1,2,3,4,5}`
向量的遍历
> 使用`[n]`来访问向量值，其中n的类型为size_t型
```c++
for(size_t i = 0; i < v.size(); ++i)
	cout << v[i] << ' ';
cout << endl;
```
向量的增删
增：`v.push_back(6)`，在后面增一个元素6。
删：`v.pop_back()`，将最后一个元素删除。
> 获取向量长度的方法，`v.size()`
> 获取向量第一个元素的方法，`v.front()`
> 获取向量最后一个元素的方法，`v.back()`
> 获取向量的首尾地址，`v.begin()`与`v.end()`，注意下标是左闭右开区间[0，N)

向量的迭代器（高级指针）
类型：`vector<int>::iterator`
```c++
for(auto iter = v.begin(); iter != v.end(); ++iter)
	cout << *iter << ' ';
cout << endl;
```

测试：
```c++
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
```
