#include <stdio.h>
#include <assert.h>

struct Frame {
	/// <summary>
	/// ջ֡pc
	/// </summary>
	int pc;
	/// <summary>
	/// ����
	/// </summary>
	int n;
	char from, to, via;
	/// <summary>
	/// �ֲ�����
	/// </summary>
	int c1, c2;
};

typedef struct Frame Frame;
int hanoi(int n, char from, char via, char to) {
	//����һ������ջ
	Frame stack[64];
	//����ջΪ��
	Frame* top = stack - 1;
	//�궨�� ...��ʾ���Դ����������
	//VAARGS��ʾ���������ĳ�Ա��ʼ��ֵ���磬��� Frame ��������Ա���� int a; int b;��������ͨ�� call(.a=1, .b=2) ����ʼ����Щ��Ա��
	#define call(...) do { \
		*(++top) = (Frame){.pc=0, __VA_ARGS__}; \
	} while (0)
	#define ret(val) do { \
			top--; \
			retval = (val); \
		} while (0)

	int retval = 0;
	//�������ʼ��ջ
	call(n, from ,to, via);
	
	while (1) {
		Frame* f = top;
		if (top < stack) {
			return;
		}
		int next_pc = f->pc + 1;
		int n = f->n, from = f->from, to = f->to, via = f->via, c1 = f->c1, c2 = f->c2;
		switch (f->pc) {
			case 0:
				if (n == 1) {
					printf(" % c-- > % c\n", from, to);
					ret(1);
				}
				break;
			case 1:call(n - 1, from, via, to); break;
			case 2:f->c1 = retval; break;
			case 3:call(1, from, to, via); break;
			case 4:call(n-1, via, to, from); break;
			case 5:f->c2 = retval; break;
			case 6:ret(f->c1 + f->c2 + 1); break;
			default:assert(0);
		}
		f->pc = next_pc;
	}
	return retval;
}