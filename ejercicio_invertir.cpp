/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -------------------------------------------------------
// Definición de nodo y helpers
// -------------------------------------------------------
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* fromVec(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int x : v) {
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return dummy.next;
}

vector<int> toVec(ListNode* head) {
    vector<int> out;
    for (ListNode* p = head; p; p = p->next) out.push_back(p->val);
    return out;
}

void destroy(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

bool equalVec(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) return false;
    return true;
}

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ",";
        cout << v[i];
    }
    cout << "]";
}

// -------------------------------------------------------
// Solución: Invertir lista recursivamente
// -------------------------------------------------------

ListNode* invertir(ListNode* anterior, ListNode* head) {
    if(head->next == nullptr) {
        head->next = anterior;
        head->next = nullptr;
        return anterior;
    }

    head = invertir(head, head->next);

    head->next = anterior;
    head->next = nullptr;

    return head;
}

ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;

    invertir(head, head->next);


    /*
    ListNode* temp1;
    ListNode* temp2;
    temp1 = head->next;
    temp2 = temp1->next;
    head->next = nullptr;
    if(temp2 == nullptr) {
        head->next = nullptr;
        temp1->next = head;
        head = temp1;
        return head;
    }

    while(temp2 != nullptr) {
        temp1->next = head;
        head = temp1;
        temp1 = temp2;
        if(temp2->next == nullptr) {
            temp1->next = head;
            head = temp1;
            break;
        }
        temp2 = temp2->next;
    }

    */
    return head;
}

// -------------------------------------------------------
// Testing
// -------------------------------------------------------
void runTest(const vector<int>& in, const vector<int>& expected, int idx) {
    ListNode* h = fromVec(in);
    ListNode* r = reverseList(h);
    vector<int> got = toVec(r);

    cout << "Caso #" << idx << ": ";
    if (equalVec(got, expected)) {
        cout << "OK\n";
    } else {
        cout << "FAIL\n  Entrada: ";
        printVec(in);
        cout << "\n  Salida obtenida: ";
        printVec(got);
        cout << "\n  Esperada: ";
        printVec(expected);
        cout << "\n";
    }
    destroy(r);
}

int main() {
    vector<pair<vector<int>, vector<int>>> cases = {
        {{}, {}},
        {{1}, {1}},
        {{1,2}, {2,1}},
        {{1,2,3}, {3,2,1}},
        {{5,5,5}, {5,5,5}},
        {{-1,0,1}, {1,0,-1}},
        {{1,2,3,4,5}, {5,4,3,2,1}},
        {{10,9,8,7}, {7,8,9,10}},
        {{2,2,3,3,4}, {4,3,3,2,2}},
        {{100,-100,50,50,0}, {0,50,50,-100,100}}
    };

    for (size_t i = 0; i < cases.size(); ++i) {
        runTest(cases[i].first, cases[i].second, i+1);
    }

    return 0;
}