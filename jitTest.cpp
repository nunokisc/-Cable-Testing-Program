#include "jitTest.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
// construtor confirma se existe datan no txt caso nao exista define todos os valores a 0
jitTest::jitTest(int amostra)
{
    _amostra = amostra;
    totalCounter = 0;
    qtyIO = 0;
    qtyNIO = 0;
    totalQtyIO = 0;
    totalQtyNIO = 0;
    partialCounter = 0;
    operatorCounter = 0;
    fiveOutOfFive = 0;
    qtyIOFive = 0;
    qtyNIOFive = 0;
    cablePartial = 0;
}
// TESTE DE SPLICE
void jitTest::cableTest(int input, bool option, bool option1)
{
    if(totalCounter < _amostra)
    {
        if(bubbleTest(option) && spliceTest(option1))
        {
            totalCounter ++;
            partialCounter ++;
            totalQtyIO ++;
            qtyIO ++;
            operatorCounter ++;
            cablePartial ++;
        }
        else
        {
            totalCounter = 0;
            partialCounter ++;
            totalQtyNIO ++;
            qtyNIO ++;
            operatorCounter ++;
            cablePartial ++;
        }
    }
    else
    {
        if(fiveOutOfFive == 0)
            cout << "Já foi atingida a amostra \n";
        if(fiveOutOfFive < 5)
        {
            if(bubbleTest(option) && spliceTest(option1))
            {
                qtyIOFive ++;
                qtyIO ++;
                operatorCounter ++;
                totalQtyIO ++;
                partialCounter ++;
                cablePartial ++;
            }
            else
            {
                qtyNIOFive ++;
                qtyNIO ++;
                operatorCounter ++;
                totalQtyNIO ++;
                partialCounter ++;
                cablePartial ++;
            }
            fiveOutOfFive ++;
        }
        else
        {
            printFiveOutOfFive();
            qtyIOFive = 0;
            qtyNIOFive = 0;
        }
    }
}
// SIMULA BUBBLE TEST
bool jitTest::bubbleTest(bool option)
{
    return option;
}
// SIMULA SPLICE TEST
bool jitTest::spliceTest(bool option)
{
    return option;
}
// SET SHIFT
void jitTest::setShift(string shift)
{
    _shift = shift;
    _operatorNumber = "";
}
// SET OPERATOR
void jitTest::setOperatorNumber(string operatorNumber)
{
    _operatorNumber = operatorNumber;
    operatorCounter = 0;
}
// SET CABLE REF
void jitTest::setCableRef(string cableRef)
{
    _cableRef = cableRef;
    ifstream infile("filePath.txt");
    int a=0;
    string refer;
    int partial,total;
    while (infile >> refer >> partial >> total)
    {
        a++;
    }
    infile.clear();
    infile.seekg(0, ios::beg);
    string aRefer[a];
    int aPartial[a],aTotal[a], i=0;
    while (infile >> refer >> partial >> total)
    {
        aRefer[i] = refer;
        aPartial[i] = partial;
        aTotal[i] = total;
        i++;
    }
    for(int l=0; l < i; l++){
        if(aRefer[l] == cableRef)
        {
            totalCounter = aTotal[l];
            partialCounter = aPartial[l];
            cablePartial = aPartial[l];
        }
    }
}
// GET SHIFT
string jitTest::getShift()
{
    return _shift;
}
// GET OPERATOR
string jitTest::getOperatorNumber()
{
    return _operatorNumber;
}
// GET CABLE REF
string jitTest::getCableRef()
{
    return _cableRef;
}
// GET PARTIAL COUNTER
int jitTest::getPartialCounter()
{
    return partialCounter;
}
// GET TOTAL COUNTER
int jitTest::getTotalCounter()
{
    return totalCounter;
}
// GET TOTAL QTY IO
int jitTest::getTotalQtyIO()
{
    return totalQtyIO;
}
// GET TOTAL QTY NIO
int jitTest::getTotalQtyNIO()
{
    return totalQtyNIO;
}
// GET OPERATOR QTY IO
int jitTest::getOperatorQtyIO()
{
    return qtyIO;
}
// GET OPERATOR QTY NIO
int jitTest::getOperatorQtyNIO()
{
    return qtyNIO;
}
// CHANGE SHIFT
void jitTest::changeShift(string shift)
{
    printChangeOperator();
    _shift = shift;
    _operatorNumber = "";
    operatorCounter = 0;
    partialCounter = 0;
//    if(totalCounter == _amostra)
//    {
//        _shift = shift;
//        _operatorNumber = "";
//        operatorCounter = 0;
//        partialCounter = 0;
//    }
//    else
//    {
//        printChangeOperator();
//        _shift = shift;
//        _operatorNumber = "";
//        operatorCounter = 0;
//        partialCounter = 0;
//    }
}
// CHANGE OPERATOR
void jitTest::changeOperatorNumber(string operatorNumber)
{
        if(_operatorNumber != "")
        {
            printChangeOperator();
        }
        _operatorNumber = operatorNumber;
        operatorCounter = 0;
        qtyIO = 0;
        qtyNIO = 0;
}
// CHANGE CABLEREF
void jitTest::changeCableRef(string cableRef)
{
    ifstream infile("filePath.txt");
    int a=0;
    string refer;
    int partial,total;
    while (infile >> refer >> partial >> total)
    {
        a++;
    }
    infile.clear();
    infile.seekg(0, ios::beg);
    string aRefer[a];
    int aPartial[a],aTotal[a], i=0;
    while (infile >> refer >> partial >> total)
    {
        aRefer[i] = refer;
        aPartial[i] = partial;
        aTotal[i] = total;
        i++;
    }
    bool notExist = true;
    for(int l=0; l < i; l++)
    {
        if(aRefer[l] == _cableRef)
        {
            notExist = false;
            aTotal[l] = totalCounter;
            aPartial[l] = cablePartial;
            break;
        }
    }
    if(notExist)
    {
        //cout << "nao existe!";
        ofstream myfile;
        myfile.open("filePath.txt", std::ios_base::app);
        myfile  << _cableRef << " " << partialCounter << " " << totalCounter << "\n";
        myfile.close();
    }
    else
    {
        //cout << "existe";
        ofstream myfile;
        myfile.open("filePath.txt");
            for(int l=0; l < i; l++){
                myfile << aRefer[l] << " " << aPartial[l] << " " << aTotal[l] << "\n";
            }
        myfile.close();
    }
    _cableRef = cableRef;
    for(int l=0; l < i; l++)
    {
        if(aRefer[l] == cableRef)
        {
            totalCounter = aTotal[l];
            partialCounter = aPartial[l];
            cablePartial = aPartial[l];
            break;
        }else{
            totalCounter = 0;
        }
    }
    fiveOutOfFive = 0;
    qtyNIOFive = 0;
    qtyIOFive = 0;
}
void jitTest::printChangeOperator()
{
    time_t rawtime;
    time (&rawtime);
    cout << "----------------------------------- \n";
    cout << "PRINTED LABEL - Operator \n";
    cout << "Date/Time: " << ctime (&rawtime);
    cout << "OperatorNumber: " << _operatorNumber << "\n";
    cout << "Total of test: " << operatorCounter << "/" << partialCounter <<"\n";
    cout << "QTY NIO: " << qtyNIO << "\n";
    cout << "QTY IO: " << qtyIO << "\n";
    cout << "----------------------------------- \n";
}
void jitTest::printFiveOutOfFive()
{
    time_t rawtime;
    time (&rawtime);
    cout << "----------------------------------- \n";
    cout << "PRINTED LABEL - FiveOutOfFive \n";
    cout << "Date/Time: " << ctime (&rawtime);
    if(qtyIOFive == 5)
    {
        cout << "TESTE IO" << "\n";
    }
    else
    {
        cout << "TESTE NIO" << "\n";
    }
    cout << "QTY NIO: " << qtyNIOFive << "\n";
    cout << "QTY IO: " << qtyIOFive << "\n";
    cout << "----------------------------------- \n";
    fiveOutOfFive = 0;
}
