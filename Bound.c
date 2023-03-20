#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIDE 4

//(ง︡'-'︠)ง definicion de estructuras 

struct Result {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    int position;
};

struct Result compara(int arr[], int value) {
    struct Result res;
    res.is_upperbound = false;
    res.is_lowerbound = false;
    res.position = -1;
    res.exists = false;

    for (int i = 0; i < ARRAY_SIDE; i++) {
        if (arr[i] == value) {
            res.position = i;
        } else { res.exists = true;

        }

        if (arr[i] > value) {
            res.is_upperbound = true;
        }

        if (arr[i] < value) {
            res.is_lowerbound = true;
        }
    }

    return res;
}

int main(void) {
    int arr[ARRAY_SIDE];
    int value;

    // Pedimos al usuario que ingrese los valores del arreglo
    printf("Ingrese %d valores para el arreglo:\n", ARRAY_SIDE);
    for (int i = 0; i < ARRAY_SIDE; i++) {
        scanf("%d", &arr[i]);
    }

    // Imprimimos los valores ingresados
    printf("Valores ingresados: ");
    for (int i = 0; i < ARRAY_SIDE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Pedimos al usuario que ingrese el valor a buscar
    printf("Ingrese el valor a buscar: ");
    scanf("%d", &value);

    struct Result res = compara(arr, value);

    if (res.position != -1) {
        printf("El valor %d se encuentra en la posicion %d del arreglo.\n", value, res.position);
    } else {
        printf("El valor %d no se encuentra en el arreglo.\n", value);

    }

    if (res.is_upperbound) {
        printf("El valor %d no es el maximo del arreglo.\n", value);
    } else {
        printf("El valor %d es el maximo del arreglo.\n", value);
    }

    if (res.is_lowerbound) {
        printf("El valor %d no es el minimo del arreglo.\n", value);
    } else {
        printf("El valor %d es el minimo del arreglo.\n", value);
    }

    printf("El programa finalizo correctamente.\n");

printf("          ██╗░░░██╗██╗░░░██╗███╗░░██╗░██████╗░\n");
printf("          ╚██╗░██╔╝██║░░░██║████╗░██║██╔════╝░\n");
printf("          ░░╚██╔╝░░██║░░░██║██║╚████║██║░░╚██╗\n");
printf("          ░░░██║░░░╚██████╔╝██║░╚███║╚██████╔╝\n");


printf("                       _..gggggppppp.._                       \n");                      
printf("                  _.gd$$$$$$$$$$$$$$$$$$bp._                  \n");                 
printf("               .g$$$$$$P^^""j$$b""""^^T$$$$$$p.               \n");               
printf("            .g$$$P^T$$b    d$P T;       ""^^T$$$p.            \n");            
printf("          .d$$P^`  :$;    :$;                ^T$$b.           \n");          
printf("        .d$$P'      T$b.   T$b                  `T$$b.        \n");        
printf("       d$$P'      .gg$$$$bpd$$$p.d$bpp.           `T$$b.      \n");       
printf("      d$$P      .d$$$$$$$$$$$$$$$$$$$$bp.           T$$b.     \n");      
printf("     d$$P      d$$$$$$$$$$$$$$$$$$$$$$$$$b.          T$$b.    \n");     
printf("    d$$P      d$$$$$$$$$$$$$$$$$$P^^T$$$$P            T$$b.   \n");    
printf("   d$$P    '-'T$$$$$$$$$$$$$$$$$$bggpd$$$$b.           T$$b.  \n");   
printf("  :$$$      .d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$p._.g.     $$$;  \n");  
printf("  $$$;     d$$$$$$$$$$$$$$$$$$$$$$$P^^^T$$$$P^^T$$$;    :$$$  \n");  
printf(" :$$$     :$$$$$$$$$$$$$$:$$$$$$$$$_    ´^T$bpd$$$$,     $$$; \n"); 
printf(" $$$;     :$$$$$$$$$$$$$$bT$$$$$P^^T$p.    `T$$$$$$;     :$$$ \n");
printf(":$$$      :$$$$$$$$$$$$$$P `^^^'    ´^T$p.    lb`TP       $$$;\n");
printf(":$$$      $$$$$$$$$$$$$$$              `T$$p._;$b         $$$;\n");
printf("$$$;      $$$$$$$$$$$$$$;                `T$$$$:Tb        :$$$\n");
printf("$$$;      $$$$$$$$$$$$$$$                        Tb    _  :$$$\n");
printf(":$$$     d$$$$$$$$$$$$$$$.                        $b.__Tb $$$;\n");
printf(":$$$  .g$$$$$$$$$$$$$$$$$$$p...______...gp._      :$`^^^' $$$;\n");
printf(" $$$;  `^^'T$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$p.    Tb._, :$$$ \n");
printf(" :$$$       T$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$b.   `^´  $$$; \n");
printf("  $$$;       `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$b      :$$$  \n");
printf("  :$$$        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$;     $$$;  \n");
printf("   T$$b    _  :$$`$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$;   d$$P   \n");
printf("    T$$b   T$g$$; :$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  d$$P    \n");
printf("     T$$b   `^^'  :$$ ^T$$$$$$$$$$$$$$$$$$$$$$$$$$$  d$$P     \n");
printf("      T$$b        $P     T$$$$$$$$$$$$$$$$$$$$$$$$$;d$$P      \n");
printf("       T$$b.      '       $$$$$$$$$$$$$$$$$$$$$$$$$$$$P       \n");
printf("        `T$$$p.   bug    d$$$$$$$$$$$$$$$$$$$$$$$$$$P'        \n");
printf("          `T$$$$p..__..g$$$$$$$$$$$$$$$$$$$$$$$$$$P'          \n");
printf("            ´^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^´            \n");
printf("               ´^T$$$$$$$$$$$$$$$$$$$$$$$$$$P^´               \n");
printf("                   ```^^^T$$$$$$$$$$P^^^´´                    \n");

printf(" ████████╗██╗░░██╗██████╗░███████╗███████╗░██████╗██╗██╗░░██╗\n");
printf(" ╚══██╔══╝██║░░██║██╔══██╗██╔════╝██╔════╝██╔════╝██║╚██╗██╔╝\n");
printf(" ░░░██║░░░███████║██████╔╝█████╗░░█████╗░░╚█████╗░██║░╚███╔╝░\n");
printf(" ░░░██║░░░██╔══██║██╔══██╗██╔══╝░░██╔══╝░░░╚═══██╗██║░██╔██╗░\n");
printf(" ░░░██║░░░██║░░██║██║░░██║███████╗███████╗██████╔╝██║██╔╝╚██╗\n");
printf(" ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚══════╝╚═════╝░╚═╝╚═╝░░╚═╝\n");


            printf("El programa finalizo correctamente.\n");
    return 0;
}




