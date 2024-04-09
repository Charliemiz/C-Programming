/*
 * Auth: Charlie Misbach
 * Date: 11-15-23 (Due: 11-19-23)
 * Course: CSCI-2240 (Sec: 001)
 * Desc: PROG-07, Menu
 */

#include <stdio.h>
#include <stdbool.h>

void print_menu(void);
void view(void);
void copy(void);
void append(void);

int main(void) {

    /* Declaring necessary main() variables */
    int selection; 
    int r;
    bool do_exit = false; 

    /* Print starting banner */
    printf("**** File Operations Menu System ***\n");

    /* Main menu loop */
    while(!(do_exit)) {

        /* Print main menu */
        print_menu();

        /* After printing menu, acquire users input */
        /* r variable is used to test if the input is valid */
        r = scanf("%d", &selection);

        /* Catches non-integer selections entered by user, exits program*/
        if (r != 1) {
            printf("Exiting due to invalid entry.\n\n");
            break;
        }

        switch( selection ) {
            /* Case 1: Enter view function */
            case 1:
                view();
                break;
            /* Case 2: Enter copy function */
            case 2:
                copy();
                break;
            /* Case 3: Enter append function */
            case 3:
                append();
                break;
            /* Case 4: User quits */
            case 4:
                printf("Goodbye!\n\n");
                do_exit = true;
                break;
            /* Not a number 1-4, enter again */
            default:
                printf("Invalid selection!\n");
                break;

        } /* end switch() */
    
    } /* end while() */


    return 0;
} /* end main() */


void print_menu( void ) {

    printf( "\n" );
    printf( "File Operations:\n" );
    printf( "    [1] View                 [3] Append\n" );
    printf( "    [2] Copy                 [4] Quit\n\n" );
    printf( "Please a make selection and press [Enter]: " );

} /* end print_menu() */

void view( void ) {
    /* FILE stream pointers */
    FILE *fin;

    /* Variables to store file info and iterate over file */
    char filename[128];
    int ch;

    /* Ask user for file name and store in filename */
    printf("Please enter filename to view: ");
    scanf("%s", filename);

    /* Try to open file for reading in TEXT mode */
    fin = fopen(filename, "r");
    if (fin== NULL) {
        fprintf(stderr, "ERROR: Opening file: \"%s\"\n", filename);
        return;
    }

    /* Print viewing banner after opening file*/
    printf("\n>>> Viewing: \"%s\"\n", filename);

    /* Proceed to read all info from the file and print it out */
    while ( (ch = fgetc(fin)) != EOF ) {
        fputc(ch, stdout);
    }

    printf("\n<<<\n");

    /* Close file */
    fclose(fin);

} /* end view() */

void copy( void ) {
    /* FILE stream pointers */
    FILE *fin, *fout;

    /* Variables to store file info and iterate over file */
    char filename_in[128];
    char filename_out[128];
    int ch;

    /* Ask user for file name to read / write from and store file names */
    printf("Please enter filename to copy: ");
    scanf("%s", filename_in);
    printf("Please enter filename's destination: ");
    scanf("%s", filename_out);

    /* Open file to copy info from in ready binary mode */
    fin = fopen(filename_in, "rb");
    if (fin == NULL) {
        fprintf(stderr, "ERROR: Opening source file: \"%s\"\n", filename_in);
        return;
    }

    /* Open file to copy info to in write binary mode */
    fout = fopen(filename_out, "wb");
    if (fout == NULL) {
        fprintf(stderr, "ERROR: Opening destination file: \"%s\"\n", filename_out);
        /* Close input file just incase it properly opened */
        fclose(fin);
        return;
    }

    /* Print line to tell user whats happening, copying .. to ..*/
    printf("Copying: \"%s\" to \"%s\"...\n", filename_in, filename_out);

    /* Acquire contents of input file and print them into output file (copy) */
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch, fout);
    }

    /* Process completed, prints done and closes all used files */
    printf("Done!\n");
    fclose(fin);
    fclose(fout);
} /* end copy() */

void append( void ) {
        /* FILE stream pointers */
    FILE *fin, *fout;

    /* Variables to store file info and iterate over file */
    char filename_in[128];
    char filename_out[128];
    int ch;

    /* Ask user for file name to read / write from and store file names */
    printf("Please enter filename to append from: ");
    scanf("%s", filename_in);
    printf("Please enter filename to append to: ");
    scanf("%s", filename_out);

    /* Open file to copy info from in ready binary mode */
    fin = fopen(filename_in, "rb");
    if (fin == NULL) {
        fprintf(stderr, "ERROR: Opening source file: \"%s\"\n", filename_in);
        return;
    }

    /* Open file to copy info to in write binary mode */
    fout = fopen(filename_out, "ab");
    if (fout == NULL) {
        fprintf(stderr, "ERROR: Opening destination file: \"%s\"\n", filename_out);
        /* Close input file just incase it properly opened */
        fclose(fin);
        return;
    }

    /* Print line to tell user whats happening, copying .. to ..*/
    printf("Copying: \"%s\" to \"%s\"...\n", filename_in, filename_out);

    /* Acquire contents of input file and print them into output file (copy) */
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch, fout);
    }

    /* Process completed, prints done and closes all used files */
    printf("Done!\n");
    fclose(fin);
    fclose(fout);

} /* end append() */