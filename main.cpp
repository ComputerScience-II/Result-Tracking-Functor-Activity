#include <iostream>
#include <vector>
#include <functional>
#include <cassert>
using namespace std;

template<typename A, typename B, typename Result>

class functionMaker {

private:

    function<Result(A,B)> func;

    int callCount = 0;

    Result lastResult;


public:

    functionMaker(function<Result(A,B)> func) : func(func), callCount(0), lastResult() {}

    Result operator()(A a, B b) {

        callCount++;

        lastResult = func(a, b);

        return lastResult;

    }

    int getCallCount() const {

        return callCount;
    }

    Result getLastResult() const {

        return lastResult;
    }


};

int add(int x, int y) {

        return x + y;
}

int multiply(int x, int y) {

        return x * y;
}

int subtract(int x, int y) {

        return x - y;
}





int main() {

    functionMaker<int, int, int> addFunc(add);
    functionMaker<int, int, int> multiplyFunc(multiply);
    functionMaker<int, int, int> subtractFunc(subtract);
    
    assert(addFunc(2, 3) == 5);
    assert(addFunc.getCallCount() == 1);
    assert(addFunc.getLastResult() == 5);
    
    assert(multiplyFunc(2, 3) == 6);
    assert(multiplyFunc.getCallCount() == 1);
    assert(multiplyFunc.getLastResult() == 6);

    assert(subtractFunc(2, 3) == -1);
    assert(subtractFunc.getCallCount() == 1);
    assert(subtractFunc.getLastResult() == -1);

    assert (addFunc(5, 5) == 10);
    assert (addFunc.getCallCount() == 2);
    assert (addFunc.getLastResult() == 10);

    assert (multiplyFunc(5, 5) == 25);
    assert (multiplyFunc.getCallCount() == 2);
    assert (multiplyFunc.getLastResult() == 25);

    assert (subtractFunc(5, 5) == 0);
    assert (subtractFunc.getCallCount() == 2);
    assert (subtractFunc.getLastResult() == 0);
    
    cout << "The code is correct" << endl;

    return 0;
}