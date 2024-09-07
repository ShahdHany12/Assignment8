// Array ADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template <class t>
class Array_Adt {
    t* arr;
    int size;
    int length;
public:
    Array_Adt(int size) {
        if (size <= 1) {
            cout << "invalid size" << endl;
            return;
        }
        else
        {
            arr = new t[size];
            this->size = size;
            length = 0;
        }
    }
    bool IsEmpty() {
        return (length == 0);
    }
    bool IsFull() {
        return(length == size);
    }
    void Append(t value) {
        if (IsFull()) {
            cout << "Sorry,Array is full" << endl;
            return;
        }
        else
        {
            arr[length] = value;
            length++;
        }
    }
    void print() {
        if (IsEmpty()) {
            cout << "Sorry, array is empty" << endl;
            return;
        }
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void PrintReverse() {
        if (IsEmpty()) {
            cout << "Sorry, array is empty" << endl;
            return;
        }
        for (int i = length - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void Reverse() {
        if (IsEmpty()) {
            cout << "Sorry, array is empty" << endl;
            return;
        }
        int end = length - 1, start = 0;

        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[temp] = arr[end];
            start++;
            end--;
        }
    }
    void Insert(int index, t item) {
        if (IsFull()) {
            cout << "Sorry,Array is full" << endl;
            return;
        }
        else {
            for (int i = length; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = item;
            length++;
        }
    }

            void  RotateToLeft(int position) {
                if (position < 0 || position >= length){
                    return;
            }
            t* temp = new t[size];
            for (int i = 0; i < length; i++) {
                temp[i] = arr[i];
            }
            for (int j = 0; j < length - position; j++) {
                arr[j] = arr[j + position];
            }
            for (int i = 0; i < position; i++) {
                arr[length - position + i] = temp[i];

            }
            delete[] temp;
        }
  
    void  RotateToRight(int position){
        if (position < 0 || position >= length) {
            return;
        }
    t* temp = new t[size];
    for (int i = 0; i < length; i++) {
        temp[i] = arr[i];
    }
    for (int j = length - 1; j < position; j--) {
        arr[j] = arr[j - position];
    }
    for (int i = 0; i < position; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
}

    void Duplicate() {
        vector <t>duplicate;
        for (int i = 0; i < length; i++) {
            for (int t = i; t < length; t++) {
                if (arr[i] == arr[t + 1])
                    duplicate.push_back(arr[t]);
            }
        }
        if (duplicate.empty()) {
            cout << "there are not duplicates" << endl;
        }
        else {
            for (int elem : duplicate)
                cout << "there are duplicates in : "<< elem << endl;
        }

    }
    void mergeWith(const Array_Adt& otherArray) {
        if (this == &otherArray )
            return;
       int meregedlength= this->length +otherArray.length;

       t* mergedarray = new t[meregedlength];

       for (int i = 0; i < this->length; i++) {
           mergedarray[i] = this->arr[i];
       }
       for (int i = 0; i < otherArray.length; i++) {
           mergedarray[i+this->length] = otherArray.arr[i];
       }
      
       delete []arr;
      this-> arr = mergedarray;
      this->size = meregedlength;
      this->length= meregedlength;
    }
    void ResizeArray(int newsize) {
        t* newarray = new t[newsize];
        if (size == newsize&& size<=1) {
            cout << "invalid size to resize array" << endl;
            return;
        }
        size = newsize;
        for (int i = 0; i < size; i++) {
            newarray[i] = arr[i];
        }
        delete[]arr;
        arr = newarray;
    }
};
int main()
{
    Array_Adt <int> arr(5),arr2(3);
    arr2.Append(15);
    arr2.Append(19);
    arr2.Append(27);
    arr.Append(10);
    arr.Append(20);
    arr.Append(30);
    arr.Append(30);
    arr.print();
    arr.PrintReverse();
    arr.Insert(2, 40);
   arr.print();
   arr.RotateToLeft(2);
   arr.print();
    arr.Duplicate();
    arr2.mergeWith(arr);
    arr2.print();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
