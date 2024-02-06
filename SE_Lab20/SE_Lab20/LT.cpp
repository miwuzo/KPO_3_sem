#include "stdafx.h"
#include <fstream>
namespace LT
{
	LT::LexTable::LexTable()
	{
		maxsize = LT_MAXSIZE;
		size = 0;
		table = new Entry[LT_MAXSIZE];
	}

	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size < lextable.maxsize)
			lextable.table[lextable.size++] = entry;
		else
			throw ERROR_THROW(120);
	}
	Entry LexTable::GetEntry(int n)
	{
		if (n < maxsize && n >= 0)
			return table[n];
	}
	void Delete(LexTable& lextable)
	{
		delete[] lextable.table;
		lextable.table = nullptr;
	}
	void LexTable::PrintLexTable(const wchar_t* in)
	{ 
		ofstream* streamToLexem = new ofstream;
		streamToLexem->open(in);
		if (streamToLexem->is_open())
		{
			(*streamToLexem) << "--------- Таблица лексем ---------";
			int num_string = 0;
			for (int i = 0; i < size; i++)
			{
				if (num_string == table[i].numberOfString)
					(*streamToLexem) << table[i].lexema;
				else
				{
					(*streamToLexem) << '\n' << num_string << ".\t";
					while (num_string != table[i].numberOfString)
						num_string++;
					(*streamToLexem) << table[i].lexema;
				}
			}
		}
		else
			throw ERROR_THROW(128);
		streamToLexem->close();
		delete streamToLexem;

	}
	LT::Entry::Entry()
	{
		lexema = '\0';
		numberOfString = LT_TI_NULLIDX;
		idInTI = LT_TI_NULLIDX;
	}

	LT::Entry::Entry(const char lex, int stringNumber, int idInTI)
	{
		lexema = lex;
		numberOfString = stringNumber;
		this->idInTI = idInTI;
	}
}