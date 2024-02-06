#include "stdafx.h"
#define BEGIN '|'

namespace PolishNotation
{
	//добавление элемента в стек литералов
	bool Stack::push(LT::Entry input) {
		if (this->currentSize < this->maxCount) {
			lexEntry* temp = new lexEntry(input, this->head);  // Выделение памяти для нового элемента стека
			this->head = temp; // Обновление указателя на вершину стека
			this->currentSize++; // Увеличение текущего размера стека
		}
		else return false;
	}

	// Перегруженный метод добавления элемента в стек литералов
	bool Stack::push(PolishNotation::lexEntry input) {
		if (this->currentSize < this->maxCount) {
			lexEntry* temp = new lexEntry(input, this->head);
			this->head = temp;
			this->currentSize++;
		}
		else return false;
	}

	// Метод извлечения элемента из стека
	lexEntry* Stack::pop() {
		if (this->currentSize != 0) {
			lexEntry temp(*this->head); // Создание временной копии вершины стека
			delete this->head;
			this->head = temp.next; // Обновление указателя на вершину стека
			this->currentSize--;
			return &temp; // Возвращение указателя на извлеченный элемент
		}
		else return 0;
	}

	// Метод возвращает последний элемент стека литералов
	char Stack::lastElement(IT::IdTable idTable) {
		if (this->head->lexema == 'v')
			//возвращаем операцию, связанную с переменной из таблицы идентификаторов
			return idTable.table[this->head->idInTI].value.operation;
		return this->head->lexema;  // Если вершина не является переменной, возвращаем саму лексему
	}

	bool PolishNotation(int lex_position, LT::LexTable& lexTable, IT::IdTable& idTable)
	{
		// Создание стеков литералов и операторов
		PolishNotation::Stack* literals = new PolishNotation::Stack;
		PolishNotation::Stack* operators = new PolishNotation::Stack;

		// Помещение в стек операторов начального символа
		operators->push({ BEGIN, -1, -1 });

		bool flag = true;
		bool is_complete = false;
		LT::Entry temp; // переменная для хранения текущей лексемы
		In::IN in_ex; //для работы со входными символами

		for (int i = lex_position; flag;)
		{
			temp = lexTable.GetEntry(i);

			if (idTable.GetEntry(temp.idInTI).idtype == IT::IDTYPE::F)
			{
				LT::Entry temp_1;
				temp_1 = lexTable.GetEntry(i);
				temp_1.lexema = '\@';
				//Создает буфер для хранения строки (последовательности символов), который будет представлять количество параметров функции.
				char buffer[ID_MAXSIZE];
				int parm_quantity = 0;
				i++;//Увеличивает индекс, чтобы начать анализ следующей лексемы после открывающей скобки '(' функции.
				for (; lexTable.GetEntry(i).lexema != ')'; i++)
				{
					//является ли текущая лексема не цифрой
					if (in_ex.code[lexTable.GetEntry(i).lexema] != in_ex.D)
					{
						parm_quantity++;
						temp = lexTable.GetEntry(i);
						literals->push(temp);
					}
				}
				//Преобразует значение переменной parm_quantity (количество параметров) в строку и сохраняет результат в буфер buffer.
				_itoa_s(parm_quantity, buffer, 10);
				literals->push(temp_1);
				//Добавляет в стек literals первую лексему с измененной лексемой '@' и лексему, представляющую количество параметров функции.
				literals->push({ buffer[0],temp_1.numberOfString,temp_1.idInTI });
				i++;
				continue;
			}
			if (temp.lexema == LEX_ID || temp.lexema == LEX_LITERAL)
			{
				literals->push(temp);
				i++;
				continue;
			}

			switch (operators->lastElement(idTable))
			{
			case BEGIN: //текущий оператор - начало выражения
			{
				if (temp.idInTI != -1)
					//Если idInTI не равен -1, то это означает, что текущая лексема - идентификатор.
				{
					if (idTable.table[temp.idInTI].value.operation == PLUS ||
						idTable.table[temp.idInTI].value.operation == MINUS ||
						idTable.table[temp.idInTI].value.operation == STAR ||
						idTable.table[temp.idInTI].value.operation == DIRSLASH)
					{
						operators->push(temp);
						i++;
						break;
					}
				}
				else
				{
					if (temp.lexema == LEX_LEFTHESIS)
					{
						operators->push(temp);
						i++;
						break;
					}
				}
				if (temp.lexema == LEX_RIGHTHESIS) { flag = false; }
				if (temp.lexema == LEX_SEMICOLON) { is_complete = true; flag = false; }
				break;
			}
			case PLUS:
			case MINUS:
			{
				if (temp.idInTI != -1)
				{
					if (idTable.table[temp.idInTI].value.operation == PLUS ||
						idTable.table[temp.idInTI].value.operation == MINUS)
					{
						literals->push(*operators->pop());
						break;
					}
				}
				else
				{
					if (temp.lexema == LEX_LEFTHESIS ||
						temp.lexema == LEX_SEMICOLON)
					{
						literals->push(*operators->pop());
						break;
					}
				}

				if (temp.idInTI != -1)
				{
					if (idTable.table[temp.idInTI].value.operation == STAR ||
						idTable.table[temp.idInTI].value.operation == DIRSLASH)
					{
						operators->push(temp);
						i++;
						break;
					}
				}
				else
				{
					if (temp.lexema == LEX_LEFTHESIS)
					{
						operators->push(temp);
						i++;
						break;
					}
				}
			}

			case STAR:
			case DIRSLASH:
			{
				if (temp.idInTI != -1)
				{
					if (idTable.table[temp.idInTI].value.operation == PLUS ||
						idTable.table[temp.idInTI].value.operation == MINUS ||
						idTable.table[temp.idInTI].value.operation == STAR ||
						idTable.table[temp.idInTI].value.operation == DIRSLASH)
					{
						literals->push(*operators->pop());
						break;
					}
				}
				else
				{
					if (temp.lexema == LEX_RIGHTHESIS ||
						temp.lexema == LEX_SEMICOLON)
					{
						literals->push(*operators->pop());
						break;
					}
				}
				if (temp.lexema == LEX_LEFTHESIS)
				{
					operators->push(temp);
					i++;
					break;
				}
			}
			case LEX_LEFTHESIS:
			{
				if (temp.lexema == LEX_SEMICOLON) flag = false;

				if (temp.idInTI != -1)
				{
					if (idTable.table[temp.idInTI].value.operation == PLUS ||
						idTable.table[temp.idInTI].value.operation == MINUS ||
						idTable.table[temp.idInTI].value.operation == STAR ||
						idTable.table[temp.idInTI].value.operation == DIRSLASH)
					{
						operators->push(temp);
						i++;
						break;
					}
				}
				else
				{
					if (temp.lexema == LEX_LEFTHESIS)
					{
						operators->push(temp);
						i++;
						break;
					}
				}
				if (temp.lexema == LEX_RIGHTHESIS)
				{
					operators->pop();
					i++;
					break;
				}
			}
			default:
				flag = false;
			}
		}

		if (is_complete)
		{
			PolishNotation::lexEntry* temp;
			int count = literals->getCount();
			LT::Entry* temp_array = new LT::Entry[count];

			for (int i = count - 1; i >= 0; i--)
			{
				temp = literals->pop();
				if (temp)
				{
					temp_array[i] = *temp;
				}
			}

			for (int i = lex_position, j = 0; lexTable.table[i].lexema != LEX_SEMICOLON; i++)
			{
				if ((i - count) < lex_position)
					lexTable.table[i] = temp_array[j++];
				else
					lexTable.table[i] = { '~', lexTable.table[i].numberOfString, -1 };
			}

			delete[] temp_array;
			delete literals;
			delete operators;
			return true;
		}
		else
		{
			delete literals;
			delete operators;
			return false;
		}
	}
}