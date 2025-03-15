#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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

int sum_list(struct list* list){
    int sum = 0;
    for (int i=0; i<3000; i++){
        sum += lindex(list, i);
    }
    return sum;
}
int sum_array(int *array){
    int sum = 0;
    for (int i=0; i<3000; i++){
        sum += array[i];
    }
    return sum;
}
int sum_list2(struct list* list){
    int sum = 0;
    for (int i=0; i<3000; i++){
        sum += list->value;
        list = list->next;
    }
    return sum;
}



int main() {
    
    int arr[3000];
    for (int i=0; i<3000; i++){
        arr[i] = i;
    }
    struct list* test = ilist(arr, 3000);

    clock_t start_t = clock();
    int sum = sum_array(arr);
    clock_t end_t = clock();
    printf("Array 시간 : %lld  답 : %d\n", (long long int)(end_t - start_t), sum);
    
    start_t = clock();
    sum = sum_list(test);
    end_t = clock();
    printf("IList 시간 : %lld  답 : %d\n", (long long int)(end_t - start_t), sum);
    
    start_t = clock();
    sum = sum_list2(test);
    end_t = clock();
    printf("IList 최적화 시간 : %lld  답 : %d\n", (long long int)(end_t - start_t), sum);

    free_list(test);

    return 0;
}
