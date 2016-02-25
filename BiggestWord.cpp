#include <iostream>

using namespace std;

struct Letter{
    char l;
    Letter *next = NULL;
};
struct LincedList{
    Letter *first = NULL;
    Letter *last = NULL;
    void AddToEnd(char c){
        if (first == NULL){
            Letter *letter = new Letter;
            letter -> l = c;
            first = letter;
            last = letter;
            letter -> next = NULL;
        }
        else {
            Letter *letter = new Letter;
            letter -> l = c;
            last -> next = letter;
            last = letter;
            letter -> next = NULL;
        }
    }

    void MakeList(){
        cout << "Enter line" << endl;
        string s;
        getline(cin, s);

        for (int i = 0; i < s.length(); i++) {
            AddToEnd(s[i]);
        }
    }
};





LincedList *FindMinWord(LincedList *list, int &k){
    Letter *c = list->first;
    LincedList *MaxWord = new LincedList();
    int leng = 0;
    while(c != NULL)  {
        if ((( c -> l >= 'a' )&&(c -> l <= 'z')) || ( ( c -> l >= 'A' )&&(c -> l <= 'Z')) ) {
            LincedList *word = new LincedList();
            while ((c != NULL) &&(((c->l >= 'a') && (c->l <= 'z')) || ((c->l >= 'A') && (c->l <= 'Z')))) {
                leng++;
                word->AddToEnd(c->l);
                c = c->next;

            }
            if (leng > k) {
                k = leng;
                MaxWord = word;
            }
            //c = c->next;
            leng = 0;
        }
        else {
            c = c -> next;
        }
    }
    return MaxWord;
}

void OutPut(LincedList *list, int n){
    cout << "Your word is '" ;
    Letter *letter = list->first;
    while(letter != NULL) {
        cout << letter->l;
        letter = letter->next;
    }
    cout << "' and it has " << n << " letters" << endl;
}

int main() {

    LincedList list;

    list.MakeList();
    int k = 0;
    LincedList *word = FindMinWord(&list, k);

    OutPut(word, k);
}