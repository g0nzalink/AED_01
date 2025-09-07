
/*#include <bits/stdc++.h>
using namespace std;

}struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Renombrado: oddEvenList -> solucion
    // Reordena por posición: 1,3,5,... luego 2,4,6,... (índices 1-basados)
    ListNode* solucion(ListNode* head) {
        if(head == nullptr || head->next == nullptr){return head;}

        int n = 0;
        ListNode* cabeza = head;
        ListNode* temp1;
        ListNode* temp2;
        temp1 = cabeza->next;
        temp2 = temp1->next;

        while(temp2 != nullptr) {
            //Ordenar en tiempo O(n)
            temp1->next = temp2->next;
            temp2->next = cabeza->next;
            cabeza->next = temp2;

            //Avanzar para seguir ordenando
            cabeza = cabeza->next;
            temp1 = cabeza->next;
            temp2 = temp1->next;

            //Avanza mas dependiendo de la iteracion
            n++;
            for(int i = 0; i < n; i++) {
                if(temp2 == nullptr) {break;}
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return head;
    }
};

ListNode* buildList(const vector<int>& a) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : a) { tail->next = new ListNode(v); tail = tail->next; }
    return dummy.next;
}
vector<int> listToVec(ListNode* head) {
    vector<int> v; for (auto* p = head; p; p = p->next) v.push_back(p->val);
    return v;
}
void freeList(ListNode* head) {
    while (head) { auto* q = head->next; delete head; head = q; }
}

// Construye el resultado esperado: primero posiciones impares (1,3,5,...), luego pares (2,4,6,...)
vector<int> expectedOddEven(const vector<int>& a) {
    vector<int> odds, evens;
    for (size_t i = 0; i < a.size(); ++i) {
        if (i % 2 == 0) odds.push_back(a[i]);  // i=0 -> pos 1 (impar)
        else evens.push_back(a[i]);            // i=1 -> pos 2 (par)
    }
    odds.insert(odds.end(), evens.begin(), evens.end());
    return odds;
}

// Valida que la salida coincida con expected y que se cumpla la propiedad odd-even
void validate_odd_even(const vector<int>& original, ListNode* out) {
    vector<int> got = listToVec(out);
    vector<int> exp = expectedOddEven(original);
    assert(got == exp);

    // Chequeo adicional: todo el bloque inicial debe ser de posiciones impares originales, en el mismo orden
    // y luego las pares en su mismo orden.
    vector<int> origOdds, origEvens;
    for (size_t i = 0; i < original.size(); ++i)
        (i % 2 == 0 ? origOdds : origEvens).push_back(original[i]);

    // Split de got en dos bloques según tamaños esperados
    size_t k = origOdds.size();
    vector<int> gotOdds(got.begin(), got.begin() + (got.size() >= k ? k : 0));
    vector<int> gotEvens(got.begin() + (got.size() >= k ? k : 0), got.end());
    assert(gotOdds == origOdds);
    assert(gotEvens == origEvens);
}

void run_test(int id, const vector<int>& input) {
    ListNode* head = buildList(input);
    Solution sol;
    ListNode* out = sol.solucion(head);
    cout << "Test " << id << " ... ";
    validate_odd_even(input, out);
    cout << "OK\n";
    freeList(out);
}

int main() {
    // 1) Caso clásico
    run_test(1, {1,2,3,4,5});               // -> {1,3,5,2,4}

    // 2) Otro clásico (LeetCode)
    run_test(2, {2,1,3,5,6,4,7});           // -> {2,3,6,7,1,5,4}

    // 3) Lista vacía
    run_test(3, {});                         // -> {}

    // 4) Un solo nodo
    run_test(4, {42});                       // -> {42}

    // 5) Dos nodos
    run_test(5, {1,2});                      // -> {1,2}

    // 6) Tres nodos
    run_test(6, {1,2,3});                    // -> {1,3,2}

    // 7) Valores negativos
    run_test(7, {-1,-2,-3,-4,-5,-6});        // -> {-1,-3,-5,-2,-4,-6}

    // 8) Secuencia creciente larga
    run_test(8, {10,20,30,40,50,60,70,80,90,100}); // -> {10,30,50,70,90,20,40,60,80,100}

    // 9) Repetidos (verifica estabilidad por grupos)
    run_test(9, {5,5,5,5,5});                // -> {5,5,5,5,5}

    // 10) Ya "casi" odd-even
    run_test(10, {1,3,5,2,4,6});             // -> {1,5,4,3,2,6}

    cout << "Todos los tests pasaron. \n";
    return 0;
}
*/