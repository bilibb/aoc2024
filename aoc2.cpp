#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

using namespace std;

void printList(list<int> &list){
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << '\n';
}

bool isSafe(list<int> list){
    if(list.size() == 1){
        return true;
    }

    int firstElement = list.front();
    int secoundElement = *next(list.begin());
    int distance = abs(secoundElement - firstElement);
    if(distance < 1 || distance > 3){
        return false;
    }

    list.pop_front();
    return isSafe(list);
}

int main() {
    ifstream infile("../input/test2.txt");

    int numSafe = 0;

    string line;
    while(getline(infile, line)){

        std::list<int> intList;
        std::istringstream stream(line);

        int number;

        while (stream >> number) {
            intList.push_back(number);
        }

        int firstElement = intList.front();
        int secoundElement = *next(intList.begin());

        int distance = secoundElement - firstElement;

        // Abwärts
        if(distance < 0 || distance <= -3){
            list<int> sorted(intList);
            sorted.sort(greater<int>());

            if(intList == sorted){
                if(isSafe(sorted)){
                    numSafe++;
                }
            }
        }

        // Aufwärts
        if(distance > 0 || distance <= 3){
            list<int> sorted(intList);
            sorted.sort();

            if(intList == sorted){
                if(isSafe(sorted)){
                    numSafe++;
                }
            }
        }
    }

    cout << "Num of safe lists: " << numSafe;
}