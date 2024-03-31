#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

struct element *create_list(int val) {
    struct element *new_list = malloc(sizeof(struct element));
    if (new_list == NULL) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }
    new_list->value = val;
    new_list->pointer = NULL;
    return new_list;
}

bool list_is_empty(struct element *list) {
    return list == NULL;
}

int len_list(struct element *list) {
    int len = 0;
    while (!list_is_empty(list)) {
        list = list->pointer;
        len++;
    }
    return len;
}

void print_list(struct element *list) {
    printf("--- MY LIST ---\n");
    while (!list_is_empty(list)) {
        printf("%d\n", list->value);
        list = list->pointer;
    }
    printf("--- END ---\n");
}

void debug_list(struct element *list) {
    int i = 0;
    printf("--- DEBUGGING LIST ---\n");
    printf("--- LEN LIST --\n");
    printf("%d\n", len_list(list));
    while (!list_is_empty(list)) {
        printf("--- INDEX %d ---\n", i);
        printf("Value : %d\n", list->value);
        if (list->pointer != NULL) {
            printf("Pointing on : %d\n", list->pointer->value);
        }
        i++;
        list = list->pointer;
    }
}

struct element *index_list(struct element *list, int idx) {
    assert(idx >= 0 && idx < len_list(list));
    for (int i = 0; i < idx; i++) {
        list = list->pointer;
    }
    return list;
}

void prepend_list(struct element **list, int val) {
    struct element *new_list = create_list(val);
    new_list->pointer = *list;
    *list = new_list;
}

void append_list(struct element *list, int val) {
    struct element *new_list = create_list(val);
    while (list->pointer != NULL) {
        list = list->pointer;
    }
    list->pointer = new_list;
}

void delete_first(struct element **list) {
    if (*list != NULL) {
        struct element *tmp = *list;
        *list = (*list)->pointer;
        free(tmp);
    }
}

void delete_last(struct element *list) {
    if (list == NULL) return;
    if (list->pointer == NULL) {
        free(list);
        return;
    }
    struct element *prev = NULL;
    while (list->pointer != NULL) {
        prev = list;
        list = list->pointer;
    }
    free(prev->pointer);
    prev->pointer = NULL;
}

void add_element(struct element *list, int idx, int val) {
    if (idx == 0) {
        prepend_list(&list, val);
    } else if (idx > 0 && idx < (len_list(list) - 1)) {
        struct element *new_element = create_list(val);
        new_element->pointer = index_list(list, idx);
        index_list(list, idx - 1)->pointer = new_element;
    } else if (idx == (len_list(list) - 1)) {
        append_list(list, val);
    } else {
        assert(1 != 1);
    }
}

void remove_element(struct element *list, int idx) {
    if (idx == 0) {
        delete_first(&list);
    } else if (idx > 0 && idx < (len_list(list) - 1)) {
        struct element *tmp = index_list(list, idx - 1);
        struct element *to_delete = tmp->pointer;
        tmp->pointer = to_delete->pointer;
        free(to_delete);
    } else if (idx == (len_list(list) - 1)) {
        delete_last(list);
    } else {
        assert(1 != 1);
    }
}
