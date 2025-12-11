// main.c
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    int choice = -1;

    while (1) {
        show_main_menu();
        choice = get_int("Enter your choice: ");

        if (choice == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        handle_main_menu_choice(choice);

        printf("\nPress ENTER to continue...");
        getchar();  
        getchar();  
    }

    return 0;
}
