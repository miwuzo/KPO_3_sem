#pragma once
#include <iostream>

namespace FST
{
	struct RELATION        //ребро:символ -> вершина графа переходов КА
	{
		char symbol; // символ перехода
		short nnode; // номер смежной вершины
		RELATION(unsigned char c = 0x00, short ns = NULL); // символ перехода и  новое состояние
	};

	struct NODE       // вершина графа переходов
	{
		short n_relation;      // количество инцидентных ребер
		RELATION* relations;   // количество инцидентных ребер
		NODE();
		NODE(short n, RELATION rel, ...); // количество инцидентных ребер и список ребер
	};

	struct FST {               // недетерминированный конечный автомат
		const char* string;    // цепочка (строка, завершатся 0x00 )
		short position;        // текущая позиция в цепочке
		short nstates;         // количество состояний конечного автомата
		NODE* nodes;           // граф переходов: [0] - начальное состояние, [nstate-1] - конечное
		short* rstates;        // возможные состояние автомата на данной позиции
		FST(const char* s, short ns, NODE n, ...); // цепочка (строка, завершается 0x00 ), количество состояний автомата, список состояний (граф переходов)
	};

	bool execute(FST& fst); // выполнить распознование цепочки (недетерминированный конечный автомат)
}