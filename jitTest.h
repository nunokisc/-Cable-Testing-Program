#include <string>
using namespace std;
class jitTest{
    string _shift;
    string _operatorNumber;
    string _cableRef;
    int _amostra;
    // total counters
    int totalQtyNIO;
    int totalQtyIO;
    int totalCounter;
    // operator/shift counters
    int operatorCounter;
    int qtyNIO;
    int qtyIO;
    int partialCounter;
    int fiveOutOfFive;
    int qtyIOFive;
    int qtyNIOFive;
    int cablePartial;

public:


    jitTest(int amostra);
    void setShift(string shift);
    void setOperatorNumber(string operatorNumber);
    void setCableRef(string cableRef);
    void changeShift(string shift);
    void changeOperatorNumber(string operatorNumber);
    void changeCableRef(string cableRef);
    string getShift();
    string getOperatorNumber();
    string getCableRef();
    int getPartialCounter();
    int getTotalCounter();
    int getTotalQtyIO();
    int getTotalQtyNIO();
    int getOperatorQtyIO();
    int getOperatorQtyNIO();
    void cableTest(int input, bool option, bool option1);
    bool bubbleTest(bool option);
    bool spliceTest(bool option1);
    void printChangeOperator();
    void printFiveOutOfFive();
};
