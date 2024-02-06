#include <tchar.h>
#include <iostream>
#include <locale>
#include <cwchar>
#include "FSt.h"

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    FST::FST fst11(
        "rc;s;se",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(4, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5), FST::RELATION(';', 9)),//7
        FST::NODE(3, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst11))
        std::cout << fst11.string << " распознана\n";
    else
        std::cout << fst11.string << " не распознана\n";
    FST::FST fst12(
        "rspss;se",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst12))
        std::cout << fst12.string << " распознана\n";
    else
        std::cout << fst12.string << " не распознана\n";
    FST::FST fst13(
        "rssspsssssss;sssse",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst13))
        std::cout << fst13.string << " распознана\n";
    else
        std::cout << fst13.string << " не распознана\n";
    FST::FST fst14(
        "rsc;s;c;s;sse",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst14))
        std::cout << fst14.string << " распознана\n";
    else
        std::cout << fst14.string << " не распознана\n";
    FST::FST fst15(
        "rsspsss;se",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst15))
        std::cout << fst15.string << " распознана\n";
    else
        std::cout << fst15.string << " не распознана\n";
    FST::FST fst16(
        "rssps;pss",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst16))
        std::cout << fst16.string << " распознана\n";
    else
        std::cout << fst16.string << " не распознана\n";
    FST::FST fst17(
        "rsc;s;s",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst17))
        std::cout << fst17.string << " распознана\n";
    else
        std::cout << fst17.string << " не распознана\n";
    FST::FST fst18(
        "rssssssasdf",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst18))
        std::cout << fst18.string << " распознана\n";
    else
        std::cout << fst18.string << " не распознана\n";
    FST::FST fst19(
        "rsppesr",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10
    );
    if (FST::execute(fst19))
        std::cout << fst19.string << " распознана\n";
    else
        std::cout << fst19.string << " не распознана\n";
    FST::FST fst110(
        "rspsps;",
        11,
        FST::NODE(2, FST::RELATION('r', 1), FST::RELATION('r', 2)),//0
        FST::NODE(3, FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('s', 5)),//1
        FST::NODE(1, FST::RELATION('c', 3)),//2
        FST::NODE(1, FST::RELATION(';', 4)),//3
        FST::NODE(3, FST::RELATION('s', 4), FST::RELATION('s', 5), FST::RELATION('s', 7)), //4
        FST::NODE(1, FST::RELATION('p', 6)), //5
        FST::NODE(2, FST::RELATION('s', 6), FST::RELATION('s', 7)),//6
        FST::NODE(3, FST::RELATION(';', 8), FST::RELATION(';', 2), FST::RELATION(';', 5)),//7
        FST::NODE(2, FST::RELATION('s', 8), FST::RELATION('s', 9)),//8
        FST::NODE(1, FST::RELATION('e', 10)),//9
        FST::NODE()//10

    );

    if (FST::execute(fst110))
        std::cout << "Цепочка " << fst110.string << " распознана";
    else std::cout << "Цепочка " << fst110.string << " не распознана";
}