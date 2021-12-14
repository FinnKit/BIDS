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