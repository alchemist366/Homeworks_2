#include <iostream>
using namespace std;

struct drobi{
    int p, q;
    drobi *next = NULL;
};
struct LinkedList {
    drobi *first = NULL;
};

LinkedList *Faray(int n){
    LinkedList *list = new LinkedList();
    drobi *drob1 = new drobi();
    (*drob1).p = 0;
    drob1 -> q = 1;
    list -> first = drob1;

    drobi *drob2 = new drobi();
    drob2 -> p = 1;
    drob2 -> q = 1;
    list -> first -> next = drob2;

    for (int i = 0; i < n + 1; ++i) {
        drob1 = list -> first;
        drob2 = list -> first -> next;

        while(drob2 != NULL){
            if (drob1 -> q + drob2 -> q == i){
                drobi *drob = new drobi();
                drob -> p = drob1 -> p + drob2 -> p;
                drob -> q = drob1 -> q + drob2 -> q;
                drob1 -> next = drob;
                drob -> next = drob2;
                drob1 = drob;
            }
            else{
                drob1 = drob2;
                drob2 = drob2 -> next;
            }
        }
    }
    return list;
}



int main() {
    cout << "Enter max value of n" << endl;
    int n;
    cin >> n;
    LinkedList *List = Faray(n);
    drobi *en = List->first;
    while (en != NULL){
        cout << en -> p << '/' << en -> q << endl;
        en = en -> next;
    }
    return 0;
}