#include <stdio.h>
#include <logisim.h>
/// <summary>
/// 定义八根导线实现信号显示
/// </summary>
wire X, Y, X1, Y1, A, B, C, D, E, F, G;
/// <summary>
/// 定义两个触发器
/// </summary>
reg b1 = { .in = &X1, .out = &X };
reg b0 = { .in = &Y1, .out = &Y };

int main() {
	CLOCK_CYCLE{
		X1 = AND(NOT(X),Y);
		Y1 = NOT(OR(X, Y));
		A = D = E = NOT(Y);
		B = 1;
		F = Y1;
		G = X;
		C = NOT(X);

		b0.value = *b0.in;
		b1.value = *b1.in;
		*b0.out = b0.value;
		*b1.out = b1.value;

#define PRINT(X) printf(#X" = %d;",X)
		PRINT(X);
		PRINT(Y);
		PRINT(A);
		PRINT(B);
		PRINT(C);
		PRINT(D);
		PRINT(E);
		PRINT(F);
		PRINT(G);
		printf("\n");
		fflush(stdout);
		Sleep(1000);
	}
	return 0;
}