#include "FST.h"
#include <iostream>

FST::RELATION::RELATION(unsigned char c, short nn)
{
	symbol = c; // символ перехода
	nnode = nn; // номер смежной вершины
}

FST::NODE::NODE() {
	n_relation = 0; // количество инцидентных ребер
	RELATION* relations = NULL;
}

FST::NODE::NODE(short n, RELATION rel, ...)
{
	n_relation = n;
	RELATION* p = &rel;
	relations = new RELATION[n];
	for (short i = 0; i < n; i++) relations[i] = p[i];
}

FST::FST::FST(const char* s, short ns, NODE n, ...) {
	string = s;  // цепочка (строка)
	nstates = ns; // количество состояний конечного автомата
	nodes = new NODE[ns]; // граф переходов: [0] - начальное состояние, [nstate-1] - конечное
	NODE* p = &n;
	for (int k = 0; k < ns; k++) nodes[k] = p[k];
	rstates = new short[nstates];
	memset(rstates, 0xff, sizeof(short) * nstates);
	rstates[0] = 0;
	position = -1;
}

bool step(FST::FST& fst, short*& rstates)
{
	bool rc = false;      // Изначально считаем, что переход не был выполнен
	std::swap(rstates, fst.rstates);   // Меняем местами указатели на состояния автомата
	for (short i = 0; i < fst.nstates; i++) { 
		if (rstates[i] == fst.position) 
			for (short j = 0; j < fst.nodes[i].n_relation; j++) 
			{
				if (fst.nodes[i].relations[j].symbol == fst.string[fst.position]) 
				{
					fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1; 
					rc = true;  
				};
			};
	};
	return rc;
};


bool FST::execute(FST& fst)
{
	short* rstates = new short[fst.nstates]; 
	memset(rstates, 0xff, sizeof(short) * fst.nstates);
	short lstring = strlen(fst.string); 
	bool rc = true; 
	for (short i = 0; i < lstring && rc; i++) 
	{
		fst.position++;
		rc = step(fst, rstates);
	};
	delete[] rstates;
	return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc); 
};