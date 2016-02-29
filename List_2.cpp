#include <iostream>

using namespace std;

struct Letter{
    char l;
    Letter *next = NULL;
};
struct LincedList{
    Letter *first = NULL;
    Letter *last = NULL;
};



void AddToEnd(LincedList *list ,char c){
    if (list->first == NULL){
        Letter *letter = new Letter;
        letter->l = c;
        list->first = letter;
        letter->next = NULL;
        list->last = letter;
    } else {
        Letter *letter = new Letter;
        letter->l = c;
        list->last->next = letter;
        list->last = letter;
        letter->next = NULL;
    }
}

void MakeList(LincedList *list,int &n,string s){
    for (int i = 0; i < s.length(); i++) {
        AddToEnd(list, s[i]);
        n++;
    }
}

bool IsLetter(char c){
    return (( c  >= 'a' )&&(c  <= 'z')) || ( ( c  >= 'A' )&&(c <= 'Z')) ;
}

bool CheckChars(char c, char m){
    if (IsLetter(c) && IsLetter(m)){
        return  ((c == m) ||  (c - 32 == m) || (m - 32 == c)) ;
    }
    else {
        return (c == m);
    }
}


void DeleteWord(LincedList *str,int s, int n){
    Letter *x = str->first;

    for (int i = 0; i < s - 1; i++) {
        x = x->next;
    }

    Letter *y = x;

    for (int i = 0; i < n; i++) {
        y = y->next;
    }
    if (x != str->first) {
        x->next = y->next;
    }
    else{
        str->first = y;
    }
}

LincedList ChangeListKMP(LincedList *str, LincedList *word, int List_n, int Word_n){

    Letter *c =  str->first;
    Letter *m = word->first;

    int f = 1;

    int k = 0;
    int j;
    for ( j = 0; j < List_n; j++) {
        if (m != NULL) {
            if (CheckChars(c->l, m->l)) {
                k++;
                m = m->next;
            }
            else {
                if (k == Word_n) {
                    DeleteWord(str, j  - (f * Word_n), Word_n);
                    f++;
                }
                k = 0;
                m = word->first;
            }
        }
        else {
            if (k == Word_n) {
                DeleteWord(str, j -(f * Word_n), Word_n);
                f++;
            }
            k = 0;
            m = word->first;
        }
        c = c->next;
    }

    if (k == Word_n){
        DeleteWord(str, j - (f * Word_n), Word_n);
    }

    return *str;
}

void InPut(LincedList *list, int &n ){

    string s;
    getline(cin, s);

    MakeList(list, n, s);
}

void OutPut(LincedList *list){
    cout << "Your  changed line is '" ;
    Letter *letter = list -> first;
    while(letter != NULL) {
        cout << letter -> l;
        letter = letter -> next;
    }
    cout << "'" << endl;
}

int main() {
    LincedList word;
    LincedList list;
    int word_n = 0, list_n = 0;

    cout << "Enter Line" << endl;
    InPut(&list, list_n);

    cout << "Enter word that you want to delete" << endl;
    InPut(&word, word_n);

    LincedList NewList = ChangeListKMP(&list, &word, list_n, word_n);

    OutPut(&NewList);

}