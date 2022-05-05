#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"

using namespace std;

template<class T>
void input(T* value) {
    while (true) {
        //cout << "Enter a value:";
        cin >> *value;
        break;
    }
}

void menu() {
    int data_type = 0;
    //printf("Enter 1 for int, 2 for double\n");
    cout << "1. int" << endl << "2. double" << endl;
    do {
        input(&data_type);
    } while (data_type != 2 && data_type != 1);
    /*while (data_type != 1 && data_type != 2) {
        input(&data_type);
    }*/
    if (data_type == 1) {
        //printf("Enter 1 for ListSequence, 2 for ArraySequence\n");
        cout << "1. ListSequence" << endl << "2. ArraySequence" << endl;
        int type = -1;
        /*while (type != 1 && type != 2) {
            input(&type);
        }*/
        do {
            input(&type);
        } while (type != 1 && type != 2);
        Sequence<int> *seq;
        if (type == 1) {
            seq = new LinkedListSequence<int>();
        } else {
            seq = new ArraySequence<int>;
        }
        //printf("Enter 1 for append, 2 for prepend, 3 for insertAt,  4 for getLength, 5 for print,6 for get subseq 0 for exit program\n");
        cout << "1. Append" << endl << "2. Prepend" << endl << "3. Insert at" << endl << "4. Get length" << endl << "5. Print" << endl << "6. Subsequence" << endl << "0. Exit";
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                cout << "Choose option" << endl;
                //printf("Choose option: \n");
                input(&type);
            }
            int item;
            switch (type) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    //seq -> append(0);
                    //printf("Enter append item\n");
                    cout << "Enter appending item" << endl;
                    //input(&(*seq)[seq -> getLength() - 1]);
                    input(&item);
                    seq -> append(item);
                    break;
                case 2:
                    //seq -> prepend(0);
                    //printf("Enter prepend item\n");
                    cout << "Enter prepend item" << endl;
                    input(&item);
                    seq -> prepend(item);
                    break;
                case 3:
                    //printf("Enter insert index\n");
                    cout << "Enter insert index" << endl;
                    input(&index);
                    try {
                        //seq -> insertAt(0, index);
                        //printf("Enter insert item\n");
                        cout << "Enter insert item" << endl;
                        input(&item);
                        seq -> insertAt(item, index);

                    } catch (Exception& exception) {
                        cout << "Process finished with error code = " << exception.number << endl;
                        exit(0);
                    }
                    break;
                case 4:
                    cout << "The length is: " << seq -> getLength() << endl;
                    break;
                case 5:
                    cout << seq << endl;
                    break;
                case 6:
                    int fromIndex;
                    int toIndex;
                    //printf("Enter start index\n");
                    cout << "Enter start index" << endl;
                    input(&fromIndex);
                    //printf("Enter insert index\n");
                    cout << "Enter end index" << endl;
                    input(&toIndex);
                    Sequence<int> *seq2 = seq -> getSubsequence(fromIndex, toIndex);
                    cout << "Subsequence : " << seq2 << endl;
            }
        }
    } else {
        //printf("Enter 1 for ListSequence, 2 for ArraySequence\n");
        cout << "1. ListSequence" << endl << "2. ArraySequence" << endl;
        int type = -1;
        /*while (type != 1 && type != 2) {
            input(&type);
        }*/
        do {
            input(&type);
        } while (type != 1 && type != 2);
        Sequence<double> *seq;
        if (type == 1) {
            seq = new LinkedListSequence<double>();
        } else {
            seq = new ArraySequence<double>;
        }
        //printf("Enter 1 for append, 2 for prepend, 3 for insertAt,  4 for getLength, 5 for print,6 for get subseq 0 for exit program\n");
        cout << "1. Append" << endl << "2. Prepend" << endl << "3. Insert at" << endl << "4. Get length" << endl << "5. Print" << endl << "6. Subsequence" << endl << "0. Exit";
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                cout << "Choose option" << endl;
                //printf("Choose option: \n");
                input(&type);
            }
            double item;
            switch (type) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    //seq -> append(0);
                    //printf("Enter append item\n");
                    cout << "Enter appending item" << endl;
                    //input(&(*seq)[seq -> getLength() - 1]);
                    input(&item);
                    seq -> append(item);
                    break;
                case 2:
                    //seq -> prepend(0);
                    //printf("Enter prepend item\n");
                    cout << "Enter prepend item" << endl;
                    input(&item);
                    seq -> prepend(item);
                    break;
                case 3:
                    //printf("Enter insert index\n");
                    cout << "Enter insert index" << endl;
                    input(&index);
                    try {
                        //seq -> insertAt(0, index);
                        //printf("Enter insert item\n");
                        cout << "Enter insert item" << endl;
                        input(&item);
                        seq -> insertAt(item, index);
                    } catch (Exception& exception) {
                        cout << "Process finished with error code = " << exception.number << endl;
                        exit(0);
                    }
                    break;
                case 4:
                    cout << "The length is: " << seq -> getLength() << endl;
                    break;
                case 5:
                    cout << seq << endl;
                    break;
                case 6:
                    int fromIndex;
                    int toIndex;
                    //printf("Enter start index\n");
                    cout << "Enter start index" << endl;
                    input(&fromIndex);
                    //printf("Enter insert index\n");
                    cout << "Enter end index" << endl;
                    input(&toIndex);
                    Sequence<double> *seq2 = seq -> getSubsequence(fromIndex, toIndex);
                    cout << "Subsequence : " << seq2 << endl;
            }
        }
    }
}

int main() {
    menu();
    return 0;
}
