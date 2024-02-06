#include "stdafx.h"
#include "iostream"
#include"Error.h"
#include"In.h"
#include"Log.h"
#include"Parm.h"
#include"Out.h"
#include"FST.h"
#include"LA.h"
#include"LT.h"
#include<cwchar>
#include<time.h>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	Parm::PARM parm = Parm::getparm(argc, argv);
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	try
	{
		out = Out::GetOut(parm.out);
		log = Log::getlog(parm.log);
		In::IN in_result = In::getin(parm.in);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		Out::WriteText(out, in_result);
		Log::WriteIn(log, in_result);
		LA::LA(parm, in_result);
		Log::Close(log);
		Out::Close(out);
	}
	catch (Error::ERROR e)
	{
		cout << "Îøèáêà" << e.id << ':' << e.message << endl << endl;
		if (e.inext.line)
			Log::WriteError(log, e);
		Out::WriteError(out, e);
		Log::Close(log);
		Out::Close(out);
	}

	return 0;
};