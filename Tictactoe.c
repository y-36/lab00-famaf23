#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <assert.h>  /* assert() */

#define TABLERO_TAMAÑO 3 // Aca podemos definir el tamaño que queramos (ง︡'-'︠)ง

#define CELL_MAX (TABLERO_TAMAÑO * TABLERO_TAMAÑO - 1)
//Esto imprime la lineas horizontales del tablero
void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀");
    printf("\n");

}
/* Aca genere el tablero con un blucle para que dependiendo del 
tamaño que posee el tabero se impriman las columnas y se coloquen
los numero del tamaño igual a CELL_MAX
*/
void print_board(char board[TABLERO_TAMAÑO][TABLERO_TAMAÑO])
{
    int cell = 0;

    print_sep(TABLERO_TAMAÑO);
    for (int fila = 0; fila < TABLERO_TAMAÑO; ++fila) {
        for (int column = 0; column < TABLERO_TAMAÑO; ++column) {
            printf("\t ██ %d=> %c ", cell, board[fila][column]);
            ++cell;
        }
        printf("\t ██ \n");
        print_sep(TABLERO_TAMAÑO);
    }
}

/* gent_winnir va a buscar en la matriz un ganador; "X" ò "O" ; por filas,
columnas o diagnonales, si no hay aganador va devolver "-" */

char get_winner(char board[TABLERO_TAMAÑO][TABLERO_TAMAÑO]) 
{
    //char winner va decir que simbolo es el ganador, si no devuelve "-"
    char winner = '-';

    // Verificar cada filas con un bucle buscando que se encuentre una "X" o un "O" consecutivas si es asi activa el break
    for (int fila = 0; fila < TABLERO_TAMAÑO; ++fila) {
        int i;
        for (i = 0; i < TABLERO_TAMAÑO - 1; ++i) {
            if (board[fila][i] != board[fila][i+1]) {
                break;
            }
        }

        if (i == TABLERO_TAMAÑO - 1 && board[fila][0] != '-') {
            winner = board[fila][0];
            //comprueba si hay una fila ganadora con algun sibolo, si no toma - = empate
            return winner;
        }
    }

    // Verificar columnas con un bucle buscando que se encuentre una "X" o un "O" consecutivas si es asi activa el break
    for (int columna = 0; columna < TABLERO_TAMAÑO; ++columna) {
        int i;
        for (i = 0; i < TABLERO_TAMAÑO - 1; ++i) {
            if (board[i][columna] != board[i+1][columna]) {
                break;
            }
        }

        if (i == TABLERO_TAMAÑO - 1 && board[0][columna] != '-') {
            winner = board[0][columna];
            //comprueba si hay una fila ganadora con algun sibolo, si no toma - = empate
            return winner;
        }
    }
    //Verificar diagonales y comprueba si hay una de las diagonales tenga 
    //signo iguales y distintos a " - " (vacio) 
    //(para tableros de tamaño variable)
    int diag1 = 1, diag2 = 1;
    for (int i = 0; i < TABLERO_TAMAÑO - 1; ++i) {
    diag1 &= (board[i][i] == board[i+1][i+1] && board[i][i] != '-');
    diag2 &= (board[i][TABLERO_TAMAÑO - i - 1] == board[i+1][TABLERO_TAMAÑO - i - 2] && board[i][TABLERO_TAMAÑO - i - 1] != '-');
    }
// se toma el que se encuentre en la casilla central si es que encontro una diagonal completa

    if (diag1 || diag2) {
    winner = board[TABLERO_TAMAÑO/2][TABLERO_TAMAÑO/2];
    // toma el simbolo ganador y lo guarda, si no es asi toma - que es igual a empate
    return winner;
    }
return winner;
}

// has_free_cell recorre la matriz verigicando si lugares vacios (" - ") 
//mientraas se mantenga en true seguira pidiendo
// al usuario que ingrese un numero en el tablero 
bool has_free_cell(char board[TABLERO_TAMAÑO][TABLERO_TAMAÑO]) 
{
    bool free_cell = false;
    for (int fila = 0; fila < TABLERO_TAMAÑO ; ++fila) {
        for (int column = 0; column < TABLERO_TAMAÑO ; ++column) {
            if (board[fila][column] == '-') {
                free_cell = true;
                break;
            }
        }
        if (free_cell) {
            break;
        }
    }
    return free_cell;
}

// Aca imprimimos un cartel para iniciar el juego y
// la matriz llamando a board con un for anidado
// para recorrer las celdas del tablero e iniciarlas vacias = "-"

int main(void) {


    printf("    ▀▀█▀▀ ▀█▀ ▒█▀▀█ 　 ▀▀█▀▀ ░█▀▀█ ▒█▀▀█ 　 ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀▀\n");
    printf("    ░▒█░░ ▒█░ ▒█░░░ 　 ░▒█░░ ▒█▄▄█ ▒█░░░ 　 ░▒█░░ ▒█░░▒█ ▒█▀▀▀\n");
    printf("    ░▒█░░ ▄█▄ ▒█▄▄█ 　 ░▒█░░ ▒█░▒█ ▒█▄▄█ 　 ░▒█░░ ▒█▄▄▄█ ▒█▄▄▄█\n");

    char board[TABLERO_TAMAÑO][TABLERO_TAMAÑO];

    // Inicia todas las celdas con '-'
    for (int fila = 0; fila < TABLERO_TAMAÑO; ++fila) {
        for (int columna = 0; columna < TABLERO_TAMAÑO; ++columna) {
            board[fila][columna] = '-';
        }
    }
    // Aca definimos los Turnos
    char turn = 'X';
    char winner = '-';
    int cell = 0;
    //verificamos si hay casillas vacias para seguir jugando o determinar un empante
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al  leer un número desde teclado\n");
exit(EXIT_FAILURE);
}
if (cell >= 0 && cell <= CELL_MAX) {
int fila = cell / TABLERO_TAMAÑO;
int column = cell % TABLERO_TAMAÑO;
if (board[fila][column] == '-') {
board[fila][column] = turn;
turn = turn == 'X' ? 'O' : 'X';
/* se llama a winner que con get_winner chekean el tablero para verificar 
si winner != "-" ya hay un ganador en el tablero actualizado.
*/
winner = get_winner(board);
} else {
printf("\nCelda ocupada!\n");
}
} else {
printf("\nCelda inválida!\n");
}
}
print_board(board);
// si no hay casiilas vascias, y winner == "-" termina en empante y se imprime en pantalla 
if (winner == '-') {
    printf("                         \n");
    printf("                         \n");
    printf("                         \n");
printf("                    █▀▀ █▀▄▀█ █▀█ ▄▀█ ▀█▀ █▀▀\n");
printf("                    ██▄ █░▀░█ █▀▀ █▀█ ░█░ ██▄\n");
printf("                         \n");
printf("                         \n");
printf("                         \n");
printf("                         \n");
} else {
    printf("                         \n");
    printf("                         \n");
    printf("                         \n");
    printf("                         \n");
    // en el caso contrario se toma al ganador y se imprime el cartel ganador 
printf("                              Ganó %c\n", winner);

printf("                         █▀▀ ▄▀█ █▄░█ █▀█\n");
printf("                         █▄█ █▀█ █░▀█ █▄█\n");
printf("                         ↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅↓̅\n");
printf("                          %c %c %c %c %c %c %c %c\n", winner, winner, winner, winner, winner, winner, winner, winner);
}

printf("                         \n");
printf("                         \n");
printf("                         \n");
printf("                         \n");

// un dibijuto que hice para marcar al creador del codigo ( ͠▀̿ ̿ ͜ʖ͠▀̿ ̿  )

printf("               ██╗░░░██╗██╗░░░██╗███╗░░██╗░██████╗░\n");
printf("               ╚██╗░██╔╝██║░░░██║████╗░██║██╔════╝░\n");
printf("               ░░╚██╔╝░░██║░░░██║██║╚████║██║░░╚██╗\n");
printf("               ░░░██║░░░╚██████╔╝██║░╚███║╚██████╔╝\n");

printf("     ████████╗██╗░░██╗██████╗░███████╗███████╗░██████╗██╗██╗░░██╗\n");
printf("     ╚══██╔══╝██║░░██║██╔══██╗██╔════╝██╔════╝██╔════╝██║╚██╗██╔╝\n");
printf("     ░░░██║░░░███████║██████╔╝█████╗░░█████╗░░╚█████╗░██║░╚███╔╝░\n");
printf("     ░░░██║░░░██╔══██║██╔══██╗██╔══╝░░██╔══╝░░░╚═══██╗██║░██╔██╗░\n");
printf("     ░░░██║░░░██║░░██║██║░░██║███████╗███████╗██████╔╝██║██╔╝╚██╗\n");
printf("     ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚══════╝╚═════╝░╚═╝╚═╝░░╚═╝\n");

return 0;
}
