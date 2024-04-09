/*
 * Auth: Charlie Misbach
 * Date: 12-08-23 (Due: 12-10-23)
 * Course: CSCI-2240 (Sec: 001)
 * Desc: PROG-08, Matrices
 */

#include <stdio.h>
#include <stdbool.h>

/* define numbers for rows and cols */
#define ROWS 3
#define COLS 3

/* Functions that implement matrix operations */
void scalar_mult3x3( const float k, const float A[ROWS][COLS], float R[ROWS][COLS] );
void matrix_add3x3( const float A[ROWS][COLS], const float B[ROWS][COLS], float R[ROWS][COLS] );
void matrix_sub3x3( const float A[ROWS][COLS], const float B[ROWS][COLS], float R[ROWS][COLS] );

/* Functions which perform I/O operations and Display */
void ask_matrix3x3( const char *msg, float M[ROWS][COLS] );
void ask_scalar( const char *msg, float *k );
int print_menu_and_get_choice( void );
void print_matrix3x3( const char *msg, const float M[ROWS][COLS] );
void flush_linebuffer(void);

int main( void ) {                                                              
                                                                                
    float A[ROWS][COLS], B[ROWS][COLS], R[ROWS][COLS];                          
    float k;                                                                    
    int choice;                                                                 
                                                                                
    printf( "*** Matrix Ops, ver. 0.1 ***\n" );                                 
                                                                                
    while( ( choice = print_menu_and_get_choice()) != 4 ) {                     
                                                                                
        /* Take action based on selection */                                    
        switch( choice ) {                                                      
                                                                                
            case 1: /* Scalar Multiplication */     
                /* Ask for a scalar to multiply a user given matrix by and print the result */                            
                ask_scalar("Please enter scalar: ", &k);
                ask_matrix3x3("Please enter matrix: ", A);
                scalar_mult3x3(k, A, R);
                print_matrix3x3("Result =\n", R);
                break;                                                          
                                                                                
            case 2: /* Matrix Addition */                 
                /* Ask for a matrix A and B, use that info to add them and print the result */                      
                ask_matrix3x3("Please enter matrix A: ", A);
                ask_matrix3x3("Please enter matrix B: ", B);
                matrix_add3x3(A, B, R);
                print_matrix3x3("Result =\n", R);
                break;                                                          
                                                                                
            case 3: /* Matrix Subtraction */     
                /* Ask for a matrix A and B, use that info to subtract them and print the result*/                               
                ask_matrix3x3("Please enter matrix A: ", A);
                ask_matrix3x3("Please enter matrix B: ", B);
                matrix_sub3x3(A, B, R);
                print_matrix3x3("Result =\n", R);
                break;                                                          
                                                                                
            default:                                                            
                printf( "ERROR: Whoops! Unrecognized choice.\n\n" );            
                                                                                
        } /* end switch() */                                                    
                                                                                
    } /* end while() */                                                         
                                                                                
    printf( "\nThank you for playing.\n\n" );                                   
                                                                                
    return 0;                                                                   
                                                                                
} /* end main() */

int print_menu_and_get_choice( void ) {                                         
                                                                                
    int selection;                                                              
                                                                                
    printf( "\n" );                                                             
    printf( "Matrix Operations Menu:\n\n" );                                    
    printf( "\t[1] Scalar Multiplication\n" );                                  
    printf( "\t[2] Matrix Addition\n" );                                        
    printf( "\t[3] Matrix Subtraction\n" );                                     
    printf( "\t[4] Exit\n\n" );                                                 
    printf( "Please make a selection and press [Enter]: " );                    
                                                                                
    /* Grab the selection */                                                    
    while (scanf("%d", &selection) != 1 || selection < 1 || selection > 4) {
        printf("Invalid selection. Try again!\n\n");
        flush_linebuffer(); 
        printf("Please make a selection and press [Enter]:");
        continue;
    }                                          
                                                                                
    return selection;                                                           
                                                                                
} /* end print_menu_and_get_choice() */

void flush_linebuffer( void ) {                                                 
                                                                                
    /* Clear the input line buffer upto, and including, the newline. */         
    while( getchar() != '\n' )                                                  
        continue;                                                               
                                                                                
} /* end flush_linebuffer() */

void ask_scalar( const char *msg, float *k ) {
    /* print message */
    printf("%s", msg);

    /* If valid scalar isnt received, show error and ask again, and flush buffer */
    while (scanf("%f", k) != 1) {
        printf("ERROR: Scalar entry. Try again!\n");
        flush_linebuffer();
        printf("%s", msg);
    }
    /* Flush once again */
    flush_linebuffer();
}

void ask_matrix3x3(const char *msg, float M[ROWS][COLS]) {
    int readCount;
    char startBracket, endBracket;

    do {
        printf("%s", msg);

        /* Read and check the opening bracket */ 
        if (scanf(" %c", &startBracket) != 1 || startBracket != '[') {
            printf("ERROR: Matrix entry. Try again!\n");
            flush_linebuffer();
            continue;
        }

        /* Reset read count for matrix elements */ 
        readCount = 0;

        /* Read each matrix element */ 
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (scanf("%f", &M[i][j]) == 1) {
                    readCount++;
                } else {
                    /* Handle incorrect matrix entry */
                    printf("ERROR: Matrix entry. Try again!\n");
                    flush_linebuffer();
                    break;
                }
            }
            if (readCount != (i + 1) * COLS) {
                /* Break out of outer loop if error occurred or count mismatch */
                break;
            }
        }

        /* Check if all matrix elements were read correctly and expect the closing bracket */
        if (readCount == ROWS * COLS && scanf(" %c", &endBracket) == 1 && endBracket == ']') {
            /* Correct format and all elements read, exit the loop */
            break;
        } else {
            /* Incorrect number of elements or missing/incorrect closing bracket */
            printf("ERROR: Matrix entry. Try again!\n");
            flush_linebuffer();
        }

    } while (true);

    /* Matrix successfully read */
}

void scalar_mult3x3( const float k, const float A[ROWS][COLS], float R[ROWS][COLS] ) {
    /* iterate over elements of A multiplying them by k and storing the result in R*/
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; j++) {
            R[i][j] = k * A[i][j];
        }
    }
}

void print_matrix3x3( const char *msg, const float M[ROWS][COLS] ) {
    printf("%s", msg);
    /* iterate over the matrix and print it in a nice format*/
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%6.2f ", M[i][j]);
        }
        printf("\n");
    }
}

void matrix_add3x3( const float A[ROWS][COLS], const float B[ROWS][COLS], float R[ROWS][COLS] ) {
    /* iterate over the matrix and add elements of matrix A and B and store in R */
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_sub3x3 ( const float A[ROWS][COLS], const float B[ROWS][COLS], float R[ROWS][COLS] ) {
    /* iterate over the matrix and subtract elements of matrix A and B and store in R */
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            R[i][j] = A[i][j] - B[i][j];
        }
    }
}