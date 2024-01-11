#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>

using namespace std;

void combineArrays(const int array1[], int s1, const int array2[], int s2, int result[]) {
    int i = 0, j = 0, k = 0;


    while (i < s1 && j < s2) {
        if (array1[i] < array2[j]) {
            result[k++] = array1[i++];
        }
        else {
            result[k++] = array2[j++];
        }
    }


    while (i < s1) {
        result[k++] = array1[i++];
    }


    while (j < s2) {
        result[k++] = array2[j++];
    }


    for (int m = 0; m < s1 + s2 - 1; ++m) {
        for (int n = 0; n < s1 + s2 - m - 1; ++n) {
            if (result[n] > result[n + 1]) {
                int temp = result[n];
                result[n] = result[n + 1];
                result[n + 1] = temp;
            }
        }
    }
}
void SameElements(const int array1[], int s1, const int array2[], int s2) {
    int i = 0, j = 0;

    cout << "Same Elements: ";

    while (i < s1 && j < s2) {
        if (array1[i] == array2[j]) {
            cout << array1[i] << " ";
            ++i;
            ++j;
        }
        else if (array1[i] < array2[j]) {
            ++i;
        }
        else {
            ++j;
        }
    }

    cout << "\n";
}



bool isPalindrome(const string& str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        while (start < end && !isalpha(str[start])) {
            ++start;
        }

        while (start < end && !isalpha(str[end])) {
            --end;
        }

        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }

        ++start;
        --end;
    }

    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int array1[5];
    int array2[7];


    cout << "Enter 5 integers for array1: " << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> array1[i];
    }


    cout << "Array2 with random values: " << endl;
    for (int i = 0; i < 7; ++i) {
        array2[i] = rand() % 10 + 1;
        cout << array2[i] << " ";
    }
    cout << "\n";

    const int size1 = 5;
    const int size2 = 7;
    int mergedArray[size1 + size2];


    combineArrays(array1, size1, array2, size2, mergedArray);


    cout << "Merged Array in ascending order: ";
    for (int i = 0; i < size1 + size2; ++i) {
        cout << mergedArray[i] << " ";
    }
    cout << "\n";


    SameElements(array1, size1, array2, size2);


    cout << "Palindrome checker" << endl;
    string userSentence;
    cout << "Enter a sentence: ";
    cin.ignore();
    getline(cin, userSentence);

    if (isPalindrome(userSentence)) {
        cout << "The sentence is a palindrome.\n";
    }
    else {
        cout << "The sentence is not a palindrome.\n";
    }

    return 0;
}