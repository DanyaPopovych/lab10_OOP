#include "CMultiSet.h"
#include <map>
#include <unordered_set>
#include <stack>
#include <list>
#include <algorithm> // ?????? ??? ????????? ??? ???????????? ??????? max_element

using namespace std;

class CStudent {
public:
    string name;
    int height;

    CStudent(const string& n, int h) : name(n), height(h) {}

    friend ostream& operator<<(ostream& os, const CStudent& student) {
        os << "Name: " << student.name << ", Height: " << student.height;
        return os;
    }
};

bool operator<(const CStudent& lhs, const CStudent& rhs) {
    return lhs.height < rhs.height;
}

int main() {
    /*CMultiSet<int> obj;

    cin >> obj;
    cout << "Values in object: " << obj << endl;

    CMultiSet<int> obj2;

    cin >> obj2;
    cout << "Values in object 2: " << obj2 << endl;

    CMultiSet<int> sum;
    sum = obj + obj2;
    cout << "Sum multiset: " << sum;

    CMultiSet<int> difference;
    difference = obj - obj2;
    cout << "Difference multiset: " << difference;

    CMultiSet<int> intersection;
    intersection = obj / obj2;
    cout << "Intersection multiset: " << intersection;*/

    // MULTIMAP
    multimap<int, string> objMap {
        {1, "Cristiano"},
        { 2, "Lionel" },
        { 3, "Kevin" }
    };

    auto add = pair<int, string>(4, "Ira");
    objMap.insert(add);
    add = pair<int, string>(3, "Orest");
    objMap.insert(add);

    auto ptr = objMap.find(4);
    if (ptr != objMap.cend()) {
        cout << ptr->second << endl;
    }
    else {
        cout << "no such key" << endl;
    }

    ptr = objMap.find(3);
    if (ptr != objMap.cend()) {
        cout << ptr->second << endl;
    }
    else {
        cout << "no such key" << endl;
    }

    objMap.erase(2);
    objMap.erase(5);

    for (auto iter = objMap.begin(); iter != objMap.end(); ++iter) {
        cout << "Key: " << iter->first << "\tValue: " << iter->second << endl;
    }
    cout << endl;

    unordered_multiset<int> order {2, 5, 7, 3, 7, 8, 4};
    order.insert(34);
    cout << order.size() << endl;
    order.insert(3);
    cout << order.size() << endl;
    cout << *order.find(3) << endl;
    order.erase(3);
    cout << order.size() << endl;

    cout << "Values:";
    for (auto iter = order.begin(); iter != order.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    // stack
    stack<int> mystack;
    for (size_t i = 0; i < 5; i++) {
        mystack.push(i);
    }
    cout << mystack.top() << endl;
    mystack.pop();

    cout << "\n" << "Stack:" << endl;
    for (size_t i = 0; !mystack.empty(); i++) {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout << "\n" << "Stack is empty" << endl;

    list<string> list1;
    for (const auto& pair : objMap) {
        list1.push_back(pair.second);
    }
    for (const auto& value : list1) {
        cout << value << endl;
    }

    CStudent Kolya("Kolya", 190);
    CStudent Danya("Danya", 176);
    CStudent Dima("Dima", 193);
    list<CStudent> listOfClass;
    listOfClass.push_back(Kolya);
    listOfClass.push_back(Danya);
    listOfClass.push_back(Dima);
    auto max = max_element(listOfClass.begin(), listOfClass.end());
    cout << *max << endl;

    return 0;
}
