#ifndef CreatDic_H_INCLUDED
#define CreatDic_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <hash_map>
using namespace std;
using namespace stdext;

string wordfile;
string strtmp;
string word ;
hash_map<string, int> wordhash; // 用于读取词典后的哈希
hash_map<string, int >::iterator worditer; //
typedef pair<string, int> sipair;

void CreatDic(void)
{
	printf("请输入所选的词典\n");
    cin>>wordfile; 
	ifstream dic(wordfile);
	 if (!dic.is_open()) // 打开词典失败则退出程序
     {
      cerr << "Unable to open input file: " << "wordlexicon"<< " -- bailing out!" << endl;
	  exit(-1);
     }
	while (getline(dic, strtmp, '\n')) // 读入词典的每一行并将其添加入哈希中
    {
     istringstream istr(strtmp);
     istr >> word; 
     wordhash.insert(sipair(word, 1)); 
    }
}

bool Find(string s)
{
	if(wordhash.find(s)!=wordhash.end())
		return true ;
	else 
		return false;
}

#define  sigma_size  26    //代表字符集的大小

//字母表全是小写字母的Tri树

struct Trie {
    int ch[maxnode][sigma_size]; //ch[i][j]代表节点i 的那个编号为j 的子节点
	int val[maxnode];
	int sz;                      //节点个数
	Trie()
    {
	 sz=1;
	 memeset(ch[0],0 ,sizeof(ch[O]));  // 初始化只有一个根节点
	}
	int idx(char c) 
	{
	  returne c-'a';
	}
}

// 插入字符串s ,附加信息为v，代表 本节点不是单词节点
void insert (char *s , int v)
{
   int u= 0,  n=strlen(s);
   for(int i=0;i<n,i++)
   {
	  int c = idx(s[i]);
	  if(!ch[u][c]){       //节点不存在
	   　memset(ch[sz],0,sizeof(ch[sz])); 
	     val[sz]=0;
	     ch[u][c]= sz++;
	  }
	  u= ch[u][c];        //往下走
   }
   val[u]=v;
}
#endif // CraetDic_H_INCLUDED
