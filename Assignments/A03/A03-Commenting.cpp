/*****************************************************************************
*
*  Author:           Trey Taylor
*  Email:            Tbtaylor0816@my.msutexas.edu
*  Label:            A03
*  Title:            Commenting Proper
*  Course:           2143-OOP
*  Semester:         Spring 2023
*
*  Description:
*        This program with create a Circular array based que with either fixed
*        or variable size for the user.
*
*  Files:            
*       Source.cpp
*****************************************************************************/
#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 *
 * Description:
 *      This class will create an array based queue with either a fixed size or modular size
 *      depending on need.
 *
 * Public Methods:
 * - CircularArrayQue()
 * - CircularArrayQue(int size)
 * - void Push(int item)
 * - int Pop()
 *
 * Private Methods:
 * - void init(int)
 * - bool Full()
 *
 * Usage:
 *
 * - CircularArrayQue Q();      //Create an instance of the class with size 10
 * - CircularArrayQue(int size) //Create an instance of the class with custom size
 * - void Push(int item)        //Push any int onto the class array
 * - int Pop()                  //Take the int first put onto the array
 *
 */
class CircularArrayQue {
private:
    int* Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        }
        else {
            cout << "FULL!!!!" << endl;
        }
    }

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream& operator<<(ostream& os, const CircularArrayQue& other);
};

/**
 * Private : Ostream&
 *
 * Description:
 *      Overloads the << operator to allow the printing of an object of 
 *      a CircularArrayQue
 *
 * Params:
 *      - ostream&
 *      - const CircularArrayQue&
 *
 * Returns:
 *      - ostream&
 */
ostream& operator<<(ostream& os, const CircularArrayQue& other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}


/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
    CircularArrayQue C1(5);     //Creates an object of a CircularArrayQue

     C1.Push(34);
     C1.Push(38);
     C1.Push(44);
     C1.Push(22);
     C1.Push(99);
     C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
