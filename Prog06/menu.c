/*
 * Auth: Charlie Misbach
 * Date: 10-26-23 (Due: 11-05-23)
 * Course: CSCI-2240 (Sec: 001)
 * Desc: PROG-06, Menu
 */

#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZES 32

void print_menu(void);

int main(void) {

    /* Declaring all character arrays with the pre defined array size */
    char first_name[ARRAY_SIZES];
    char last_name[ARRAY_SIZES];
    char home_city[ARRAY_SIZES];
    char home_state[ARRAY_SIZES];

    /* Declaring all necessary bool variables (as false until entered)*/
    bool got_first = false;
    bool got_last = false;
    bool got_city = false;
    bool got_state = false;
    bool got_everything = false;
    bool allow_exit = false;

    /* Declaring variable for exit attempts for an exit constraint */
    int exit_attempts = 0;

    /* Declaring variable for user's selection */
    int selection;

    /* Print starting banner */
    printf("*** User Information Menu System ***\n");

    /* Enter while loop IFF allow_exit is true (false by default) */
    while(!allow_exit) {

        /* After entering while loop call print menu function */
        print_menu();

        /* If given valid input enter if and switch statement */
        if(scanf("%d", &selection) == 1) {
            /* Enter switch statement with number provided by user */
            switch(selection) {
                /* Option 1: Enter a first name */
                case 1: 
                    if(got_first) {
                        printf("\nAlready have a first name.\n");
                    } else {
                        printf("\nEnter your first name: ");
                        scanf("%s", first_name);
                        got_first = true;
                        printf("Thank You.\n");
                    }
                    break;
                /* Option 2: Enter a last name */
                case 2: 
                    if(got_last) {
                        printf("\nAlready have a last name.\n");
                    } else {
                        printf("\nEnter your last name: ");
                        scanf("%s", last_name);
                        got_last = true;
                        printf("Thank You.\n");
                    }
                    break;
                /* Option 3: Enter your home city */
                case 3: 
                    if(got_city) {
                        printf("\nAlready have a city.\n");
                    } else {
                        printf("\nEnter your Home City: ");
                        scanf("%s", home_city);
                        got_city = true;
                        printf("Thank You.\n");
                    }
                    break;
                /* Option 4: Enter your home state */
                case 4: 
                    if(got_state) {
                        printf("\nAlready have a state.\n");
                    } else {
                        printf("\nEnter your Home State: ");
                        scanf("%s", home_state);
                        got_state = true;
                        printf("Thank You!\n");
                    }
                    break;
                /* Enter if user chooses to exit */
                case 5:
                    /* Variable that is true only if all info has been collected */
                    got_everything = got_first && got_last && got_city && got_state;

                    /* If everything was collected enter if and print info in clean format*/
                    if(got_everything) {
                        printf("\nThat's everything, Thanks!\n");
                        printf("\nUser Info Summary:\n");
                        printf("    First Name: %s\n", got_first ? first_name : "(Not Given)");
                        printf("    Last Name: %s\n", got_last ? last_name : "(Not Given)");
                        printf("    Home City: %s\n", got_city ? home_city : "(Not Given)");
                        printf("    Home State: %s\n\n", got_state ? home_state : "(Not Given)");
                        allow_exit = true;
                    /* Enter else if user hasn't entered all data but wants to exit */
                    } else {
                        /* Increment exit attempts until 2 then allow user to exit to CONFIRM */
                        exit_attempts += 1;
                        if(exit_attempts == 2) {
                            allow_exit = true;
                            printf("\nOk, if you insist!\n");
                            printf("\nUser Info Summary:\n");
                            printf("    First Name: %s\n", got_first ? first_name : "(Not Given)");
                            printf("    Last Name: %s\n", got_last ? last_name : "(Not Given)");
                            printf("    Home City: %s\n", got_city ? home_city : "(Not Given)");
                            printf("    Home State: %s\n\n", got_state ? home_state : "(Not Given)");
                        } else {
                            printf("\nYou still have some info to provide!\n");
                        }

                    }
                    break;
                /* If a number other than 1-5 is provided, it is invalid */
                default:
                    printf("\nInvalid selection!\n");
                    break;
            }
        } else {
            /* Handles non-numeric input, clears buffer as well and exits while loop */
            while (getchar() != '\n');
            allow_exit = true;
            printf("\nUser Info Summary:\n");
            printf("    First Name: %s\n", got_first ? first_name : "(Not Given)");
            printf("    Last Name: %s\n", got_last ? last_name : "(Not Given)");
            printf("    Home City: %s\n", got_city ? home_city : "(Not Given)");
            printf("    Home State: %s\n\n", got_state ? home_state : "(Not Given)");

        } /* end if else*/

    } /* end while */

    return 0;
} /* end main function */


/* Function to print the menu*/
void print_menu( void ) {

    printf( "\n" );
    printf( "[1] Provide your First Name.\n" );
    printf( "[2] Provide your Last Name.\n" );
    printf( "[3] Provide Home City.\n" );
    printf( "[4] Provide Home State.\n" );
    printf( "[5] Exit\n\n" );
    printf( "Please make a selection and press [ENTER]: " );

} /* end print_menu() */


