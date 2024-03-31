#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "src/list.h"

int main(void) {
    // Création d'une liste de test contenant un seul élément avec la valeur 8
    struct element *test_list = create_list(8);

    // Affichage de la liste de test
    printf("Liste de test : ");
    print_list(test_list); // DEVRAIT AFFICHER [8]

    // Test si la liste de test est vide
    printf("La liste de test est vide ? %d\n", list_is_empty(test_list)); // DEVRAIT AFFICHER 0 (false)

    // Test si NULL est vide
    printf("NULL est vide ? %d\n", list_is_empty(NULL)); // DEVRAIT AFFICHER 1 (true)

    // Affichage de la longueur de la liste de test
    printf("Longueur de la liste de test : %d\n", list_length(test_list)); // DEVRAIT AFFICHER 1

    // Accès à l'élément d'index 0 dans la liste de test et affichage de sa valeur
    printf("Valeur de l'élément d'index 0 dans la liste de test : %d\n", get_element(test_list, 0)->value); // DEVRAIT AFFICHER 8

    // Affichage de la liste de test
    printf("Liste de test après accès à l'élément : ");
    print_list(test_list); // DEVRAIT AFFICHER [8]

    // Ajout de l'élément 3 au début de la liste de test
    printf("-> Ajout de l'élément 3 au début de la liste\n");
    prepend_list(&test_list, 3);

    // Affichage de la liste de test après l'ajout
    printf("Liste de test après ajout au début : ");
    print_list(test_list); // DEVRAIT AFFICHER [3, 8]

    // Ajout des éléments 7 et 45 à la fin de la liste de test
    printf("-> Ajout des éléments 7 et 45 à la fin de la liste\n");
    append_list(test_list, 7);
    append_list(test_list, 45);

    // Affichage de la liste de test après l'ajout
    printf("Liste de test après ajout à la fin : ");
    print_list(test_list); // DEVRAIT AFFICHER [3, 8, 7, 45]

    // Ajout de l'élément 9 à l'index 2 dans la liste de test
    printf("-> Ajout de l'élément 9 à l'index 2 dans la liste\n");
    add_element(test_list, 2, 9);

    // Affichage de la liste de test après l'ajout
    printf("Liste de test après ajout à l'index 2 : ");
    print_list(test_list); // DEVRAIT AFFICHER [3, 8, 9, 7, 45]

    // Suppression du premier élément de la liste de test
    printf("-> Suppression du premier élément de la liste\n");
    delete_first(&test_list);

    // Affichage de la liste de test après la suppression
    printf("Liste de test après suppression du premier élément : ");
    print_list(test_list); // DEVRAIT AFFICHER [8, 9, 7, 45]

    // Suppression du dernier élément de la liste de test
    printf("-> Suppression du dernier élément de la liste\n");
    delete_last(test_list);

    // Affichage de la liste de test après la suppression
    printf("Liste de test après suppression du dernier élément : ");
    print_list(test_list); // DEVRAIT AFFICHER [8, 9, 7]

    // Suppression de l'élément d'index 1 dans la liste de test
    printf("-> Suppression de l'élément d'index 1 dans la liste\n");
    remove_element(test_list, 1);

    // Affichage de la liste de test après la suppression
    printf("Liste de test après suppression de l'élément d'index 1 : ");
    print_list(test_list); // DEVRAIT AFFICHER [8, 7]

    return 0;
}
