#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"

using namespace std;

template<class T>
void input(T* a) {
    while (true) {
        //cout << "Enter a value:" << endl;
        cin >> *a;
        break;
    }
}

void menu() {   
    int dataType=0;
    do {
        cout << "1. int\n2. double\n";
        input(&dataType);
    } while (dataType != 1 && dataType != 2);
    /*printf("Enter 1 for int, 2 for double\n");
    while (dataType != 1 && dataType != 2) {
        input(&dataType);
    }*/
    if (dataType == 1) {
        //printf("Enter 1 for ListSequence, 2 for ArraySequence\n");
        cout << "1. ListSequence\n2. ArraySequence\n";
        int type = -1;
        do {
            input(&type);
        } while (type != 1 && type != 2);
        /*cout << "1. ListSequence\n2. ArraySequence\n";
        int type = -1;
        while (type != 1 && type != 2) {
            input(&type);
        }*/
        Sequence<int> *seq;
        switch (type) {
            case 1:
                seq = new LinkedListSequence<int>();
                break;
            case 2:
                seq = new ArraySequence<int>;
                break;
            default:
                break;
        }
        /*if (type == 1) {
            seq = new LinkedListSequence<int>();
        } else {
            seq = new ArraySequence<int>;
        }*/
        //printf("Enter 1 for append, 2 for prepend, 3 for insertAt,  4 for getLength, 5 for print,6 for get subseq 0 for exit program\n");
        cout << "0. Exit\n1. Append\n2. Prepend\n3.Insert at\n4. Get length\n5. Print\n6. Subsequence\n";
        while (true) {
            type = -1;
            int index;
            /*while (type < 0 || type > 6) {
                printf("Enter a command: \n");
                input(&type);
            }*/
            do {
                cout << "Choose option\n";
                input(&type);
            } while (type < 0 || type > 6);
            switch (type) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    seq -> append(0);
                    printf("Enter append item\n");
                    input(&(*seq)[seq->getLength() - 1]);
                    break;
                case 2:
                    seq -> prepend(0);
                    //printf("Enter prepend item\n");
                    cout << "Enter prepend item" << endl;
                    break;
                case 3:
                    //printf("Enter insert index\n");
                    cout << "Enter insert index" << endl;
                    input(&index);
                    try {
                        seq -> insertAt(0, index);
                        //printf("Enter insert item\n");
                        cout << "Enter insert item" << endl;
                    } catch (Exception &abc) {
                        cout << "Process finished with error code = " << abc.number << endl;
                        exit(0);
                    }
                    break;
                case 4:
                    std::cout << "The length is: " << seq -> getLength() << std::endl;
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
                    break;
            }
        }
    } else {
        printf("Enter 1 for ListSequence, 2 for ArraySequence\n");
        int type = -1;
        while (type != 1 && type != 2) {
            input(&type);
        }
        Sequence<double> *seq;
        if (type == 1) {
            seq = new LinkedListSequence<double>;
        } else {
            seq = new ArraySequence<double>;
        }
        printf("Enter 1 for append, 2 for prepend, 3 for insertAt,  4 for getLength, 5 for print,6 for get subseq 0 for exit program\n");
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                printf("Enter a command: \n");
                input(&type);
            }
            switch (type) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    seq->append(0);
                    printf("Enter append item\n");
                    break;
                case 2:
                    seq->prepend(0);
                    printf("Enter prepend item\n");
                    break;
                case 3:
                    printf("Enter insert index\n");
                    input(&index);
                    try {
                        seq->insertAt(0, index);
                        printf("Enter insert item\n");
                    } catch (Exception &ex) {
                        cout << "Process finished with error code = " << ex.number << endl;
                        exit(0);
                    }
                    break;
                case 4:
                    cout << "The length is: " << seq->getLength() << std::endl;
                    break;
                case 5:
                    cout << seq << endl;
                    break;
                case 6:
                    int startindex;
                    int endindex;
                    printf("Enter start index\n");
                    input(&startindex);
                    printf("Enter insert index\n");
                    input(&endindex);
                    try {
                        Sequence<double> *seq2 = seq->getSubsequence(startindex, endindex);
                        cout << "Subsequence : " << seq2 << endl;
                    } catch (Exception &ex) {
                        cout << "Process finished with error code = " << ex.number << endl;
                        exit(0);
                    }
            }
        }
    }
}

int main() {
    menu();
    return 0;
}
