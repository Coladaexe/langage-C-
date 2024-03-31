#include <stdbool.h>

struct element {
    int value;
    struct element *pointer;
};

// Crée une liste contenant un élément avec la valeur "val"
struct element *create_list(int val);

// Teste si une liste est vide ou non, renvoie un booléen
bool list_is_empty(struct element *list);

// Renvoie le nombre d'éléments dans une liste
int list_length(struct element *list);

// Affiche le contenu de la liste
void print_list(struct element *list);

// Affiche le contenu de la liste de manière détaillée
void debug_list(struct element *list);

// Renvoie l'élément ayant pour index "idx"
struct element *get_element(struct element *list, int idx);

// Ajoute un élément ayant pour valeur "val" au début de la liste
void prepend_list(struct element **list, int val);

// Ajoute un élément ayant pour valeur "val" à la fin de la liste
void append_list(struct element *list, int val);

// Supprime le premier élément de la liste
void delete_first(struct element **list);

// Supprime le dernier élément de la liste
void delete_last(struct element *list);

// Ajoute un élément ayant pour valeur "val" à l'index "idx" de la liste
void add_element(struct element *list, int idx, int val);

// Supprime l'élément ayant pour index "idx" de la liste
void remove_element(struct element *list, int idx);
