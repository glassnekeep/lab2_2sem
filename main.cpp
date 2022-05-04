#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"

using namespace std;

template<class T>
void input(T* a) {
    while (true) {
        cout << "Enter a value:";
        cin >> *a;
        break;
    }
}

void menu() {   int data_type=0;
    printf("Enter 1 for int, 2 for double\n");
    while (data_type != 1 && data_type != 2) {
        input(&data_type);
    }
    if (data_type == 1) {
        printf("Enter 1 for ListSequence, 2 for ArraySequence\n");
        int type = -1;
        while (type != 1 && type != 2) {
            input(&type);
        }
        Sequence<int> *seq;
        if (type == 1) {
            seq = new LinkedListSequence<int>();
        } else {
            seq = new ArraySequence<int>;
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
                    seq -> append(0);
                    printf("Enter append item\n");
                    input(&(*seq)[seq->getLength() - 1]);
                    break;
                case 2:
                    seq -> prepend(0);
                    printf("Enter prepend item\n");
                    break;
                case 3:
                    printf("Enter insert index\n");
                    input(&index);
                    try {
                        seq -> insertAt(0, index);
                        printf("Enter insert item\n");
                    } catch (Exception &abc) {
                        cout << "Process finished with error code = " << abc.number << endl;
                        exit(0);
                    }
                    break;
                case 4:
                    std::cout << "The length is: " << seq->getLength() << std::endl;
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
                    Sequence<int> *seq2 = seq->getSubsequence(startindex, endindex);
                    cout << "Subsequence : " << seq2 << endl;
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
