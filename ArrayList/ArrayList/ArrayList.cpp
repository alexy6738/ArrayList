//No HW, however review past projects 

#include <iostream>
using namespace std;
class ArrayList {
    int* data;
    int capacity;
    int size;
    void copy() {
        int* ndata = new int[capacity];
        for (int i = 0; i < size; i++) {
            ndata[i] = data[i];
        }
        delete[] data;
        data = ndata;
    }
    void check() {
        if (size == capacity) {
            capacity = capacity * 2;
            copy();
        }
    }

public:
    ArrayList() :capacity{ 10 }, size{ 0 } {
        data = new int[capacity];
    }
    ~ArrayList() {
        delete[] data;
    }
    int rsize () {
        return size;
    }
    
    void add (int add) {
        check();
        data[size] = add;
        size++;
    }
    int get(int index) {
        if (index >= size) {
            cout << "Not Found" << endl;
            return -1;
        }
        else {
            return data[index];
        }

    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << ", ";
        }
        cout << endl;
    }
    int remove(int x) {
        int y = data[x];
        for (int i = x; i <= size; i++) {
            data[i] = data[i + 1];
        }
        size -= 1;
        return y;
    }
};

int main()
{
    ArrayList arr;
    arr.add(3);
    arr.add(1);
    arr.add(4);
    arr.add(1);
    arr.add(5);
    arr.add(9);
    arr.add(2);
    arr.add(6);
    arr.add(5);
    arr.add(3);
    arr.add(5);

    arr.print();
    arr.add(8);
    arr.print();

    arr.get(5);
    arr.get(25);

    cout << arr.remove(6) << endl;
    arr.print();
}