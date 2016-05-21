// 实现各种编码方式转换的头文件
// 把非ANSI的编码方式改成ANSI 的编码方便就行字符处理
#ifndef TEXTCODECONVERT_H_INCLUDED
#define TEXTCODECONVERT_H_INCLUDED

#include <locale.h>
#include <windows.h>
#define BUFF_SIZE 1024

char *_T(const char *str);
char* _U(const char* str);

char * UnicodeToANSI( const wchar_t* str )
{
     char* result;
     int textlen;
     textlen = WideCharToMultiByte( CP_ACP, 0, str, -1, NULL, 0, NULL, NULL );
     result =(char *)malloc((textlen+1)*sizeof(char));
     memset( result, 0, sizeof(char) * ( textlen + 1 ) );
     WideCharToMultiByte( CP_ACP, 0, str, -1, result, textlen, NULL, NULL );
     return result;
}
wchar_t * UTF8ToUnicode( const char* str )
{
     int textlen ;
     wchar_t * result;
     textlen = MultiByteToWideChar( CP_UTF8, 0, str,-1, NULL,0 );
     result = (wchar_t *)malloc((textlen+1)*sizeof(wchar_t));
     memset(result,0,(textlen+1)*sizeof(wchar_t));
     MultiByteToWideChar(CP_UTF8, 0,str,-1,(LPWSTR)result,textlen );
     return result;
}



#endif // TEXTCODECONVERT_H_INCLUDED