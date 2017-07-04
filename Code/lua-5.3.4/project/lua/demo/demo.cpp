// demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>  
#include <string.h> 

extern "C"       //�����־����Ҫ����Ϊlua����C����д�ģ�������������־���ᵼ��ʹ��C++��������ʽ�������еĺ���������lib��ȴ�Ҳ�����  
{  
#include <lua.h>  
#include <lualib.h>  
#include <lauxlib.h>  
}  

int _tmain(int argc, _TCHAR* argv[])
{
	lua_State *L = luaL_newstate();  
	luaL_openlibs(L);  
	luaL_dofile(L,"test.lua");  

	const char *buf = "print('Hello World')";  
	luaL_dostring(L,buf);  

	lua_close(L);  

	getchar();

	return 0;  
}

