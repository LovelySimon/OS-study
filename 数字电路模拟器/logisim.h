#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
/// <summary>
/// 定义一个导线
/// </summary>
typedef bool wire;
/// <summary>
/// 类似于触发器？
/// </summary>
typedef struct {
	bool value;
	wire* in;
	wire* out;
}reg; 
//与非门
#define NAND(X,Y) (!((X)&&(Y)))
//非门
#define NOT(X) (NAND(X,1))
//与门
#define AND(X,Y) (NOT(NAND(X,Y)))
//或门
#define OR(X,Y) (NAND(NOT(X),NOT(Y)))

#define CLOCK_CYCLE while (1)