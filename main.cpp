#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include "jitTest.h"
#include "njitTest.h"
using namespace std;
int main()
{
    srand(time(0));
    int randomval;
    int randomval1;
    int i;

//  TESTE JIT

//    jitTest *p1 = new jitTest(1);
//
//    cout << "set shift PRIMEIRO \n";
//    p1->setShift("primeiro");
//
//    cout << "set Operator op1 \n";
//    p1->setOperatorNumber("op1");
//
//    cout << "set Cable ref123 \n";
//    p1->setCableRef("ref123");
//
//    for(i = 0;i < 10;i++)
//    {
//        randomval = rand() % 2;
//        randomval1 = rand() % 2;
//        cout << "Test cable \n";
//        p1->cableTest(0, randomval, randomval1);
//    }
//
//    cout << "change Operator op2 \n";
//    p1->changeOperatorNumber("op2");
//
//    cout << "change Cable ref1234 \n";
//    p1->changeCableRef("ref1234");
//
//    for(i = 0;i < 10;i++)
//    {
//        randomval = rand() % 2;
//        randomval1 = rand() % 2;
//        cout << "Test cable \n";
//        p1->cableTest(0, randomval, randomval1);
//    }
//
//    cout << "change shift SEGUNDO \n";
//    p1->changeShift("segundo");
//
//    cout << "change Operator op3 \n";
//    p1->changeOperatorNumber("op3");
//
//    cout << "change Cable ref12345 \n";
//    p1->changeCableRef("ref12345");
//
//    for(i = 0;i < 10;i++)
//    {
//        randomval = rand() % 2;
//        randomval1 = rand() % 2;
//        cout << "Test cable \n";
//        p1->cableTest(0, randomval, randomval1);
//    }
//
//    cout << "change Operator op4 \n";
//    p1->changeOperatorNumber("op4");
//
//    p1->changeCableRef("ref123456");
//
//    cout << "Shift: " << p1->getShift() << "\n";
//    cout << "Operator: " << p1->getOperatorNumber() << "\n";
//    cout << "Partial: " << p1->getPartialCounter() << "\n";
//    cout << "Total: " << p1->getTotalCounter() << "\n";
//    cout << "Total NIO: " << p1->getTotalQtyNIO() << "\n";
//    cout << "Total IO: " << p1->getTotalQtyIO() << "\n";

//  TESTE NJIT

    njitTest *p1 = new njitTest(1);

    cout << "set shift PRIMEIRO \n";
    p1->setShift("primeiro");

    cout << "set Operator op1 \n";
    p1->setOperatorNumber("op1");

    cout << "set Cable ref123 \n";
    p1->setCableRef("ref123", 99);

    for(i = 0;i < 10;i++)
    {
        randomval = rand() % 2;
        randomval1 = rand() % 2;
        cout << "Test cable \n";
        p1->cableTest(0, randomval, randomval1);
    }

    cout << "change Operator op2 \n";
    p1->changeOperatorNumber("op2");

    p1->changeCableRef("ref1234", 99);
    return 0;
}
