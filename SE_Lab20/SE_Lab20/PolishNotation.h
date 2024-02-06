#pragma once
#include "stdafx.h"


namespace PolishNotation
{
	bool PolishNotation(int  lex_position, LT::LexTable& lextTable, IT::IdTable& idTable);

	struct lexEntry : LT::Entry
	{
		lexEntry* next; //дополнительное поле next, представляющее указатель на следующий элемент. 

		lexEntry() //"нет следующего элемента" или "список пуст".
		{
			this->next = nullptr;
		}

		lexEntry(LT::Entry input, lexEntry* next)
		{
			this->lexema = input.lexema;
			this->idInTI = input.idInTI;
			this->numberOfString = input.numberOfString;
			this->next = next;
		}

		operator LT::Entry()
		{
			return LT::Entry(this->lexema, this->numberOfString, this->idInTI);
		}
	};

	struct Stack
	{
		lexEntry* head;//указателем на первый элемент 
		int currentSize;
		const int maxCount = 200;//максимально допустимый размер стека

		Stack()// начальные значения
		{
			this->currentSize = 0;
			this->head = nullptr;
		}
		~Stack()//деструктор
		{
			while (this->currentSize != 0)
			{
				this->pop();
			}
		}

		bool push(LT::Entry input);
		bool push(PolishNotation::lexEntry input);
		lexEntry* pop();
		char lastElement(IT::IdTable idTable);
		int getCount()
		{
			return this->currentSize;
		}
	};
}
