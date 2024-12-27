/*

                TEAM 4
            DS Ass2 in C++
        organizing the library
         bookshelf 2022-2023

*/
#include <fstream>//using this library to create files
#include <iostream>
#include <string>
using namespace std;
#define size 100
class Queue {
private:
    string arr[size];
    int front, rear;
public:
    Queue() { rear = front = -1; }//constructor to intialize front & rear..
    string beak(int i) { return arr[i]; }//using this function to return the elements of array.
    bool isFull() //check if queue is full.
    {
        if (front == 0 && rear == size - 1) {

            return true;
        }
        return false;
    }
    bool is_Empty()//check if queue is empty.
    {

        return (front == -1);
    }
    int return_length() { return rear; }//function to calculate the lenght of the queue..
    void EnQueue(string num) //using this function to add elemenets to the queue..
    {
        if (isFull()) {
            cout << "Queue is full";
        }
        else {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = num;
        }
    }
    string DeQueue() {//using this function to remove elemenets from the queue..
        string elements;
        if (is_Empty()) {
            cout << "Queue is empty" << endl;
            return ("");
        }
        else {
            elements = arr[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }

            return (elements);
        }
    }

};
void namefile(string name_, string name__)//using this function to put the name of the file into it..
{
    fstream file1, file2, file3, file4;
    file1.open(name_, ios::in);//open file .
    Queue q1, q2, q3, q4;
    string x;
    getline(file1, x);//enter the name of books ..
    if (file1.is_open()) {
        while (x.find(',') != -1) {//check if theres comma to take the name before ..

            int y = x.find(',');
            string temp = x.substr(0, y);
            x.erase(x.begin(), x.begin() + y + 1);
            q1.EnQueue(temp);
        }
        if (x.find(',') == -1) {
            string temp = x;
            q1.EnQueue(temp);
        }
        getline(file1, x);
        while (x.find(',') != -1) {

            int y = x.find(',');
            string temp = x.substr(0, y);
            x.erase(x.begin(), x.begin() + y + 1);
            q2.EnQueue(temp);
        }
        if (x.find(',') == -1) {
            string temp = x;
            q2.EnQueue(temp);
        }
    }
    else
        cout << "file is not open";
    file1.close();//close file..
    int num = (q1.return_length() + 1) + (q2.return_length() + 1);//calculate the length of queues to know how much
    //books in it..
    for (int i = 0; i < num; i++) {

        if (i % 2 == 0 && !q1.is_Empty()) {//if q1 is not empty store the elements in string and dequeue it..
            string _temp = q1.DeQueue();

            if (_temp.find("compsci") != -1) {//search for the "compsci"in the books name and if we find it we
                //will enqueue it in queue4...& if we not find it we will enqueue it in queue3..
                q3.EnQueue(_temp);
            }
            else {
                q4.EnQueue(_temp);
            }
            continue;
        }
        else if (i % 2 == 0 && q1.is_Empty()) {//if q1 is empty store the elements in string and dequeue it..

            string _temp = q2.DeQueue();
            if (_temp.find("compsci") != -1) {//search for the "compsci"in the books name and if we find it we
                //will enqueue it in queue4...& if we not find it we will enqueue it in queue3..
                q3.EnQueue(_temp);
            }
            else {
                q4.EnQueue(_temp);
            }
            continue;
        }
        if (i % 2 != 0 && !q2.is_Empty()) {//if q2 is not empty store the elements in string and dequeue it..
            string _temp = q2.DeQueue();

            if (_temp.find("compsci") != -1) { // search for the "compsci"in the books name and if we find it we
                //will enqueue it in queue4...& if we not find it we will enqueue it in queue3..
                q3.EnQueue(_temp);
            }
            else {
                q4.EnQueue(_temp);
            }
            continue;
        }
        else if (i % 2 != 0 && q2.is_Empty()) {//if q2 is empty store the elements in string and dequeue it..
            string _temp = q1.DeQueue();

            if (_temp.find("compsci") != -1) {//search for the "compsci"in the books name and if we find it we
                //will enqueue it in queue4...& if we not find it we will enqueue it in queue3..
                q3.EnQueue(_temp);
            }
            else {
                q4.EnQueue(_temp);
            }
            continue;
        }
    }
    file2.open(name__, ios::out);//open the file output..

    file2 << ((q3.return_length() + 1) * 20) + ((q4.return_length() + 1) * 30) << endl;//calculate the time ..
    for (int i = 0; i < (q3.return_length() + 1); i++) {
        file2 << q3.beak(i) << " , ";
    }
    for (int i = 0; i < (q4.return_length() + 1); i++) {
        file2 << q4.beak(i) << " , ";
    }
    file2.close();
}
void main() 
{
    //using method thats name "namefile" to put the name of input & output files...
    namefile("input.txt", "output.txt");
    namefile("input2.txt", "output2.txt");
    namefile("input3.txt", "output3.txt");
}