#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
/// <summary>
/// ����һ������
/// </summary>
typedef bool wire;
/// <summary>
/// �����ڴ�������
/// </summary>
typedef struct {
	bool value;
	wire* in;
	wire* out;
}reg; 
//�����
#define NAND(X,Y) (!((X)&&(Y)))
//����
#define NOT(X) (NAND(X,1))
//����
#define AND(X,Y) (NOT(NAND(X,Y)))
//����
#define OR(X,Y) (NAND(NOT(X),NOT(Y)))

#define CLOCK_CYCLE while (1)