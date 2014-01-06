#include"textCodeConvert.h"
#include"CreatDic.h"
#include<time.h>
#include<string>
#include<cstring>
#define MaxWordLength 10


using namespace std;
using namespace stdext;

string ReverseSegment(string s1);    // 反向分割函数
string Segment(string s1);           // 正向分割函数
string SegmentSentence (string s1 ,int type);  

int main()
{
	// 主程序执行
	clock_t start ,finish;
	double totaltime;
	start=clock();
	printf("******************************************\n");
	printf("中文分词程序实现的功能：\n");
	printf("1. 选择分词词典  2.选取正向或者逆向分词\n");
	printf("3. 选取不同数据结构遍历字典\n");
	printf("4. 显示分词程序的运行时间\n");
	printf("******************************************\n");
	CreatDic();
	string tmp;
	string line;
	int type;
	printf("请选择分词匹配的方向：\n");
	printf("1.正向匹配 2.逆向匹配\n");
	scanf("%d",&type);
	printf("程序loading…………\n");
	if(type==1)
	{
		string output;
		output ="SegmentOutput.txt";
		ifstream testfile("test.txt");
		ofstream outfile1(output);
	     while(getline(testfile,tmp, '\n'))
		{
			line= tmp;
			line= SegmentSentence(line, type);
			outfile1 << line << endl;
		}
	    
	}
	else if(type==2)
	{
	  string output;
	  output ="ReverseSegmentOutput.txt";
	  ifstream testfile("test.txt");
	  ofstream outfile1(output);
	  while(getline(testfile,tmp, '\n'))
		{
			line= tmp;
			line= SegmentSentence(line, type);
			outfile1 << line << endl;
		}
	}
	finish=clock();
	totaltime=(double)(finish- start)/CLOCKS_PER_SEC;
	cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;
	system("pause");
	return 0 ;
}

string ReverseSegment(string s1)
{
     string s2 = ""; 
     while(!s1.empty())
     {
		int len =(int) s1.length(); 
		if (len > MaxWordLength)
		{
			len = MaxWordLength; 
		}
		string w = s1.substr(s1.length() - len, len); 
		bool flag = Find(w);
		while(len > 2 &&flag==false) // 如果没有找到
		{
			len -= 2; // 从候选词右边减掉一个汉字，将剩下的部分作为候选词
			w = s1.substr(s1.length() - len, len); 
			flag = Find(w);
		}
		w = w + '/';
		s2 = w + s2 ;
		s1 = s1.substr(0, s1.length() - len); 
	}
     return s2;
}

string Segment(string s1){
	string s2 = ""; 
     while(!s1.empty())
     {
		int len =(int) s1.length(); 
		if (len > MaxWordLength)
		{
			len = MaxWordLength; 
		}
		string w = s1.substr(0, len); 
		bool flag = Find(w);
		while(len > 2 && flag== false) // 如果不是词
		{
			len -= 2; 
			w = w.substr(0, len); 
			flag = Find(w);
		}
		s2 += w + '/'; //将匹配得到的词连同词界标记加到输出串末尾
		s1 = s1.substr(w.length(), s1.length()); //从s1-w处开始
	}
     return s2;
}

string SegmentSentence (string s1 ,int type)
{
	string s2 = ""; //用s2存放分词结果
	int i;
	int dd;
	while(!s1.empty()){
		i = 2;
		dd = (int)s1.length();
		while(i < dd && (unsigned char)s1[i] >= 176)
		{
		i += 2;
		}
		if(type==1)
		{
		s2 += Segment(s1.substr(0, i));
		s1 = s1.substr(i,dd);
		}
		else if(type==2)
		{
			s2 += ReverseSegment(s1.substr(0, i));
		    s1 = s1.substr(i,dd);
		}
	  }
     return s2;
}
