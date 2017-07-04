// demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>  
#include <string.h> 

extern "C"       //这个标志必须要，因为lua是用C语言写的，如果不加这个标志将会导致使用C++的命名方式解释其中的函数名，而lib中却找不到。  
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

