/*
 Linked List
 assg 3 data structure
 Team 4
*/
#include <iostream>
#include <string>
using namespace std;
/*
    creating the node of linkenlist
    that make linkedlist
*/
class Node {
public:
    string number;
    Node* next;
    Node* prev;

public:
    Node() {
        next = NULL;
        prev = NULL;
    }
};
// creating DoubleLinkedlist
class DoubleLinkedList {
public:
    Node* first;
    int counter;
    DoubleLinkedList() { // constructor
        first = NULL;
        counter = 0;
    }
    ~DoubleLinkedList() { // destructor to remove the values after
        while (first != NULL)
            first = first->next;
        first = NULL;
    }
    int getcounter() { return counter; }// get number of nodes of Doublelinkedlist
    void AddFirst(string data) {   //  function to add  in the first node;
        Node* newnode = new Node();
        newnode->number = data;
        if (first == NULL)
            first = newnode;
        else {
            newnode->next = first;
            first->prev = newnode;
            first = newnode;
        }
        counter++;
    }
    void AddLast(string data) {   //function to add  in the last node;
        Node* newnode = new Node();
        newnode->number = data;
        if (first == NULL)
            first = newnode;
        else {
            Node* temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = NULL;
        }
        counter++;
    }
    string DeleteFirst() {  //function to delete the first node in  Doublelinkedlist
        string data = first->number;
        if (first == NULL) {
            cout << "no items in linkedlist to delete.\n";
            return "";
        }
        else {
            Node* temp = first;
            first = first->next;
            first->prev = NULL;
            delete temp;
        }
        counter--;
        return data;
    }
    string DeleteLast() {  //function to delete the last node in  Doublelinkedlist
        string data;
        if (first == NULL) {
            cout << "no items in linkedlist to delete.\n";
            return "";
        }
        else if (first->next == NULL) {
            data = first->number;
            delete first;
            first = NULL;
        }
        else {
            Node* temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            data = temp->number;
            temp->prev->next = NULL;
            delete temp;
        }
        counter--;
        return data;
    }
    DoubleLinkedList operator+(DoubleLinkedList num) { // ooperator + to get sum of two numbers in linkedlist
        string temp;// var to store the s
        int sum; // var make th operation of sum
        int carry = 0;//  var to store the carry if there is carry
        DoubleLinkedList sums; // sum linkedlist
        while (num.first != NULL || first != NULL) { // while loop to traverse linkedlist
            if (num.first != NULL && first != NULL) { // check if two linkedlist not empty

                sum = (stoi(num.first->number) + stoi(first->number) + carry) % 1000; //to get the sum number
                carry = (stoi(num.first->number) + stoi(first->number) + carry) / 1000; //to get carry if there is carry
                num.first = num.first->next;
                first = first->next;
            }
            else if (num.first == NULL && first != NULL) { // check if first linkedlist not empty
                // and the second linkedlist empty

                sum = (stoi(first->number) + carry) % 1000;
                carry = (stoi(first->number) + carry) / 1000;
                first = first->next;
            }
            else if (num.first != NULL && first == NULL) {// check if first linkedlist  empty
                // and the second linkedlist not empty

                sum = (stoi(num.first->number) + carry) % 1000;
                carry = (stoi(num.first->number) + carry) / 1000;
                num.first = num.first->next;
            }
            temp = to_string(sum);// casting into string
            if (temp.length() == 3) {
                sums.AddFirst(temp);
            }
            else if (temp.length() == 2) {
                sums.AddFirst("0" + temp);
            }
            else if (temp.length() == 1) {
                sums.AddFirst("00" + temp);
            }
        }
        // how mang digits in carry

        if (carry != 0) {
            temp = to_string(carry);
            //add the number in the linked list
            if (temp.length() == 3) {
                sums.AddFirst(temp);
            }
            else if (temp.length() == 2) {
                sums.AddFirst("0" + temp);
            }
            else if (temp.length() == 1) {
                sums.AddFirst("00" + temp);
            }
        }
        return (sums);
    }
    bool operator>=(DoubleLinkedList num) {// operator overloading >=
        /*
          checking that two numbers not NULL
        */
        //check first number is grater than the another number  and return true

        DoubleLinkedList a = *this;
        DoubleLinkedList borrow = num;
        while (borrow.first != NULL || a.first != NULL) {
            if (((stoi(a.first->number) > stoi(borrow.first->number)) &&
                (counter == borrow.getcounter())) ||
                counter > borrow.getcounter()) {
                return true;
            }
            // if number less than from the ither number return false
            else if ((stoi(a.first->number) < stoi(borrow.first->number)) ||//stoi to casting string to integer
                a.counter < borrow.getcounter()) {
                return false;
            }
            // if they equal return false
            else if ((stoi(borrow.first->number) == stoi(a.first->number)) &&
                (a.counter == borrow.getcounter())) {
                a.first = a.first->next;
                borrow.first = borrow.first->next;
            }
        }
        return true;
    }
    bool operator<=(DoubleLinkedList num) {// operator overloading >= to know if the num is gratter than
        /*
          checking that two number not NULL
        */
        DoubleLinkedList a = *this;
        DoubleLinkedList borrow = num;
        while (borrow.first != NULL || a.first != NULL) {
            if (((stoi(a.first->number) < stoi(borrow.first->number)) &&
                (counter == borrow.getcounter())) ||
                counter > borrow.getcounter()) {
                return true;
            }
            // if number less than from the ither number return false
            else if ((stoi(a.first->number) > stoi(borrow.first->number)) ||//stoi to casting string to integer
                a.counter < borrow.getcounter()) {
                return false;
            }
            // if they equal return false
            else if ((stoi(borrow.first->number) == stoi(a.first->number)) &&//stoi to casting string to integer
                (a.counter == borrow.getcounter())) {
                a.first = a.first->next;
                borrow.first = borrow.first->next;
            }
        }
        return true;
    }
    bool operator==(DoubleLinkedList num) {//  operator overloading == checking two numbers not equal null
        DoubleLinkedList a = *this;
        DoubleLinkedList borrow = num;
        while (borrow.first != NULL || a.first != NULL) {
            if (((stoi(a.first->number) > stoi(borrow.first->number)) && (a.counter == borrow.getcounter())) || a.counter > borrow.getcounter())
            {
                return false;
            }
            else if ((stoi(a.first->number) < stoi(borrow.first->number)) ||
                a.counter < borrow.getcounter()) {
                return false;
            }
            else if ((stoi(borrow.first->number) == stoi(a.first->number)) &&
                (a.counter == borrow.getcounter())) {

                a.first = a.first->next;
                borrow.first = borrow.first->next;
            }
        }
        return true;
    }

    string  get()//get the whole string char by char..
    {
        DoubleLinkedList temp = *this;
        while (temp.first->next != NULL)
        {
            temp.first = temp.first->next;

        }

        string temp_str = "";
        while (temp.first != NULL)
        {
            temp_str += temp.first->number;
            temp.first = temp.first->prev;
        }


        return  temp_str;

    }


    DoubleLinkedList operator- (DoubleLinkedList num)//operator overloading to subtruct to string ..
    {
        DoubleLinkedList a = *this;//string 1
        DoubleLinkedList b1 = num;//string 2
        DoubleLinkedList a2 = a;// backup to the string
        DoubleLinkedList b2 = b1;// backup to the string
        DoubleLinkedList ret_sub;
        int borrow = 0;
        int subtruction;
        bool negative_num = false;//default to know the negative number..
        string number1;
        string number2;
        string substr = "";   // store number
        int i;  // num1 length
        int j;   // num2 length

        if (a2 >= b2)
        {
            number1 = a.get();
            number2 = b1.get();
            i = (number1.length() - 1);  // num1 length
            j = number2.length() - 1;   // num2 length

        }

        else {//if the number 2 grater than number 1 we equal the negative number as (true)..
            number2 = a.get();
            number1 = b1.get();
            j = (number1.length() - 1);  // num1 length
            i = number2.length() - 1;   // num2 length
            negative_num = true;

        }

        while (i >= 0 || j >= 0)//check if the 2 numbers not NULL..
        {
            if (i >= 0 && j >= 0)
            {
                if (((number1[i] - '0') + borrow) >= number2[j] - '0') {
                    subtruction = (number1[i] - '0') + borrow - (number2[j] - '0');
                    borrow = 0;
                    i--;
                    j--;

                }
                else if ((number1[i] - '0' + borrow) < number2[j] - '0')
                {
                    subtruction = (number1[i] - '0') + borrow + 10 - (number2[j] - '0');
                    borrow = -1;
                    i--;
                    j--;
                }
            }
            else if (i >= 0 && !(j >= 0))
            {
                if ((number1[i] - '0') >= 1)
                {
                    subtruction = (number1[i] - '0') + borrow;
                    borrow = 0;
                }
                else
                {
                    if (borrow != 0)
                    {
                        subtruction = ((number1[i] - '0') + 10 + borrow);
                        borrow = -1;
                    }
                    else
                    {
                        subtruction = number1[i] - '0';
                    }
                }
                i--;

            }
            substr.insert(substr.begin(), (subtruction + '0'));
        }
        for (int i = substr.length(); i > 0; i -= 3) {// for loop for inputs
            string temp;
            //check how many digits to add zero in left of number
            if (i >= 3) {
                temp.push_back(substr[i - 3]);
                temp.push_back(substr[i - 2]);
                temp.push_back(substr[i - 1]);
            }
            else if (i == 2) {
                temp.push_back('0');
                temp.push_back(substr[i - 2]);
                temp.push_back(substr[i - 1]);
            }
            else if (i == 1) {
                temp.push_back('0');
                temp.push_back('0');
                temp.push_back(substr[i - 1]);
            }
            ret_sub.AddLast((temp));
        }
        if (negative_num) ret_sub.AddFirst("\-");
        return ret_sub;

    }
    void print() {
        if (first == NULL) {
            cout << "No item in linkedlist to show.\n";
            return;
        }
        else {
            Node* temp = first;
            while (temp != NULL) {
                cout << temp->number << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};
int main() {
    string s1, s2;
    cout << "enter the first number : " << endl;
    getline(cin, s1);
    cout << "enter the second number : " << endl;
    getline(cin, s2);
    DoubleLinkedList num1, num2, sum, sub;//
    for (int i = s1.length(); i > 0; i -= 4) {// for loop for inputs
        string temp;
        //check how many digits to add zero in left of number
        if (i >= 3) {
            temp.push_back(s1[i - 3]);
            temp.push_back(s1[i - 2]);
            temp.push_back(s1[i - 1]);
        }
        else if (i == 2) {
            temp.push_back('0');
            temp.push_back(s1[i - 2]);
            temp.push_back(s1[i - 1]);
        }
        else if (i == 1) {
            temp.push_back('0');
            temp.push_back('0');
            temp.push_back(s1[i - 1]);
        }
        num1.AddLast((temp));
    }
    for (int i = s2.length(); i > 0; i -= 4) {
        // for loop for inputs
        string temp;
        //check how many digits to add zero in left of number
        if (i >= 3) {
            temp.push_back(s2[i - 3]);
            temp.push_back(s2[i - 2]);
            temp.push_back(s2[i - 1]);
        }
        else if (i == 2) {
            temp.push_back('0');
            temp.push_back(s2[i - 2]);
            temp.push_back(s2[i - 1]);
        }
        else if (i == 1) {
            temp.push_back('0');
            temp.push_back('0');
            temp.push_back(s2[i - 1]);
        }
        num2.AddLast((temp));
    }
    if (num1 == num2)
    {
        cout << "num1 = num 2 \n";
    }
    else if (num1 >= num2)
    {
        cout << " num1 grater than num2 \n";
    }
    else if (num1 <= num2)
    {
        cout << " num 1 smaller than num 2  \n";
    }
    cout << "first num is : " << num1.get() << endl;
    cout << "second num is : " << num2.get() << endl;
    sub = num1 - num2;
    cout << "subtruction is : ";
    sub.print();
    cout << "\n";
    sum = num1 + num2;
    cout << "summition is : ";
    sum.print();
    return 0;
}
