#include <stdbool.h>

struct element {
    int value;
    struct element *pointer;
};


struct element *create_list(int val);


bool list_is_empty(struct element *list);


int list_length(struct element *list);


void print_list(struct element *list);


void debug_list(struct element *list);


struct element *get_element(struct element *list, int idx);


void prepend_list(struct element **list, int val);


void append_list(struct element *list, int val);


void delete_first(struct element **list);


void delete_last(struct element *list);


void add_element(struct element *list, int idx, int val);


void remove_element(struct element *list, int idx);
