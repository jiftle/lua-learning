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


//待Lua调用的C注册函数。
static int add2(lua_State* L)
{
    //检查栈中的参数是否合法，1表示Lua调用时的第一个参数(从左到右)，依此类推。
    //如果Lua代码在调用时传递的参数不为number，该函数将报错并终止程序的执行。
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    //将函数的结果压入栈中。如果有多个返回值，可以在这里多次压入栈中。
    lua_pushnumber(L,op1 + op2);
    //返回值用于提示该C函数的返回值数量，即压入栈中的返回值数量。
    return 1;
}

//另一个待Lua调用的C注册函数。
static int sub2(lua_State* L)
{
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    lua_pushnumber(L,op1 - op2);
    return 1;
}


const char* testfunc = "print(add2(1.0,2.0)) print(sub2(20.1,19))";

int _tmain(int argc, _TCHAR* argv[])
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    //将指定的函数注册为Lua的全局函数变量，其中第一个字符串参数为Lua代码
    //在调用C函数时使用的全局函数名，第二个参数为实际C函数的指针。
    lua_register(L, "add2", add2);
    lua_register(L, "sub2", sub2);
    //在注册完所有的C函数之后，即可在Lua的代码块中使用这些已经注册的C函数了。
    if (luaL_dostring(L,testfunc))
        printf("Failed to invoke.\n");
    lua_close(L);

	getchar();

    return 0;
}



//int _tmain(int argc, _TCHAR* argv[])
//{
//	lua_State *L = luaL_newstate();  
//	luaL_openlibs(L);  
//	luaL_dofile(L,"test.lua");  
//
//	const char *buf = "print('Hello World')";  
//	luaL_dostring(L,buf);  
//
//	lua_close(L);  
//
//	getchar();
//
//	return 0;  
//}

