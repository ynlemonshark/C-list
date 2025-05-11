#include <stdio.h>
#include <stdlib.h>

struct linked_list{
    int value;
    struct linked_list* prvs;
    struct linked_list* next;
}
typedef struct linked_list LL;

LL* generate(int n){
    LL* lnklst = (LL*)malloc(sizeof(LL));
    lnklst->prvs = NULL;
    scanf("%d", &(*lnklst).value);
    LL* lst1 = lnklst;
    LL* lst2;
    for (int i=1; i<n; i++){
        lst2 = (LL*)malloc(sizeof(LL));
        scanf("%d", &(*lst2).value);
        lst1->next = lst2;
        lst2->prvs = lst1;
        lst1 = lst2;
    }
    lst1->next = NULL;
    return lnklst;
}

LL* move(LL* lnklst, int n){
    if (n < 0){
        n *= -1;
        for (int i=0; i<n; i++) if (lnklst->prvs!=NULL) lnklst=lnklst->prvs;
    }
    else for (int i=0; i<n; i++) if (lnklst->next!=NULL) lnklst=lnklst->next;
    return lnklst;
}

LL* frst(LL* lnklst){
    while (lnklst->prvs!=NULL) lnklst=lnklst->prvs;
    return lnklst;
}
LL* last(LL* lnklst){
    while (lnklst->next!=NULL) lnklst=lnklst->next;
    return lnklst;
}
void insert(LL* lnklst, int idx, int val){
    lnklst = move(lnklst, idx);
    LL* newlst = (LL*)malloc(sizeof(LL));
    newlst->value = val;
    newlst->next = lnklst->next;
    newlst->next->prvs = newlst;
    newlst->prvs = lnklst;
    lnklst->next = newlst;
}
void deleteLL(LL* lnklst, int idx){
    lnklst = move(lnklst, idx);
    lnklst->prvs->next = lnklst->next;
    lnklst->next->prvs = lnklst->prvs;
    free(lnklst);
}



int main() {
    return 0;
}
