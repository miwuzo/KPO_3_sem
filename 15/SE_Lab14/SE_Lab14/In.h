#pragma once
#define IN_MAX_LEN_TEXT 1024*1024
#define MAX_LEN_LINE 1000
#define IN_CODE_ENDL '\n'

#define IN_CODE_TABLE {\
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, '|',/* \n* на | */ IN::F, IN::F, IN::I, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::T,/*   */ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T,/* - */ IN::F, IN::F, \
	IN::T,/* 0 */ IN::F, IN::T,/* 2 */ IN::F, IN::F, IN::T,/*5*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::T,/*C*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I, IN::T,/* Y */ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::T,/* a */ IN::F, IN::F, IN::F, IN::T,/* e */ IN::F, IN::F, IN::T,/*h*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::T,/* n */ IN::F, \
	IN::F, IN::F, IN::T,/* r */ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
																													\
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	  '-', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T,/*Ч*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T,/* Я */ \
	IN::T,/* а */ IN::F, IN::F, IN::F, IN::F, IN::T,/* е */ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T,/* н */ IN::F, IN::F, \
	IN::T,/* р */ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T  \
}

namespace In
{
	void dell_in(char* str, int index);
	struct IN
	{
		enum { T = 1024, F = 2048, I = 4096 };
		int size;
		int lines;
		int ignor;
		unsigned char* text;
		int code[256] = IN_CODE_TABLE;
	};
	IN getin(wchar_t infile[]);
};