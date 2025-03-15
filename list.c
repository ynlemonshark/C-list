#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct list {
    int value;
    struct list* next;
};

struct list* node(int element, struct list* adress){
    struct list *a = malloc(sizeof(struct list));
    a->value = element;
    a->next = adress;
    return a;
}

struct list* ilist(int elements[], int size) {
    struct list *adress = NULL;
    for (int i=size-1; i>=0; i--){
        adress = node(elements[i], adress);
    }
    return adress;
}

int lindex(struct list *adress, int index){
    for (int i=0; i<index; i++){
        adress = adress->next;
    }
    return adress->value;
}

int len(struct list *adress){
    int length = 0;
    while (adress != NULL){
        length++;
        adress = adress->next;
    }
    return length;
}

struct list* last(struct list *adress){
    while (adress->next != NULL){
        adress = adress->next;
    }
    return adress;
}

void free_list(struct list *list){
    while (list->next != NULL){
        struct list *adress = list->next;
        free(list);
        list = adress;
    }
    free(list);
}

void append(struct list *list, int element){
    struct list *last_elem = last(list);
    struct list* newone = node(element, NULL);
    last_elem->next = newone;
}

void delind(struct list *list, int index){
    for (int i=1; i<index; i++){
        list = list->next;
    }
    struct list* adress = list->next;
    list->next = adress->next;
    free(adress);   
}

void insert(struct list *list, int element, int index){
    for (int i=1; i<index; i++){
        list = list->next;
    }
    struct list *newone = node(element, list->next);
    list->next = newone;
}

int pop(struct list *adress){
    while (adress->next->next != NULL){
        adress = adress->next;
    }
    int a = adress->next->value;
    free(adress->next);
    adress->next = NULL;
    return a;
}

void printall(struct list *list){
    printf("[ ");
    while(list->next != NULL){
        printf("%d, ", list->value);
        list = list->next;
    }
    printf("%d ]", list->value);
}

int main() {

    int arr[5] = {1, 2, 3, 4, 6};
    
    struct list* test = ilist(arr, 5);
    printf("%d", len(test));
    printf("%d", lindex(test, 2));
    delind(test, 2);
    append(test, 8);
    printf("%d", pop(test));
    printall(test);
    return 0;
}
