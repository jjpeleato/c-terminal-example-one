/**
 * \file main.c
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \version 1.0.0
 * \date 2020-09-20
 */

// Libraries and constants
#ifdef _WIN32
    #include <windows.h>
    #define OS "win32"
#elseif _WIN64
    #include <windows.h>
    #define OS "win64"
#else
    #include <unistd.h>
    #define OS "unix"
#endif
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

// Prototypes
void commonClear();
void commonAwait();
void commonSleep();
void drawSplashScreen();
void addData();
int menu();

// Structs
struct town
{
    int id;
    char name[50];
    float kilometers[MAX][MAX];
};
struct town towns[MAX];

/**
 * \brief Main function
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 */
int main ()
{
    // STEP 1: Splash screen
    drawSplashScreen();
    commonAwait();

    // STEP 2: Insert kilometer data
    addData();

    // STEP 3: Start menu
    int action;
    while (action != 6){
		action = menu();
		
        commonClear();
        switch (action) {
            case 1:
                printf ("Show distances table between towns.");
                commonAwait();
                break;
            case 2:
                printf ("Show the two most far towns.");
                commonAwait();
                break;
            case 3:
                printf ("Show far town by selected town.");
                commonAwait();
                break;
            case 4:
                printf ("Show middletown.");
                commonAwait();
                break;
            case 5:
                printf ("Calculate the number of kilometers the milkman trips.");
                commonAwait();
                break;
            default:
                break;
        }
	}

    return 0;
}

/**
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns void
 */
void commonClear()
{
    if (OS == "win32" || OS == "win64") {
        system("cls");
    } else {
        system("clear");
    }
}

/**
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns void
 */
void commonAwait()
{
    int await;

    do {
        printf ("\n\nPress 0 to continue with the application: ");
        fflush(stdin);
	    scanf("%d", &await);
	} while (await != 0);
}

/**
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns void
 */
void commonSleep()
{
    sleep(0.500);
}

/**
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns void
 */
void drawSplashScreen()
{
    commonSleep();
    printf ("\n"); commonSleep();
	printf ("\n__        __   _"); commonSleep();
	printf ("\n\\ \\      / /__| | ___ ___  _ __ ___   ___"); commonSleep();
	printf ("\n \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\"); commonSleep();
	printf ("\n  \\ V  V /  __/ | (_| (_) | | | | | |  __/"); commonSleep();
	printf ("\n   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|"); commonSleep();
	printf ("\n\n"); commonSleep();
	printf ("\nTowns of Seville"); commonSleep();
	printf ("\nVersion 1.0.0"); commonSleep();
	printf ("\nJose Javier Peleato Pradel"); commonSleep();
}

/**
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns int
 */
int menu()
{
    int input;

    do {
        commonClear();
        printf ("- Towns of Seville Software -");
        printf ("\n\nMain menu.");
		printf ("\n\n\t1 - Show distances table between towns.");
		printf ("\n\t2 - Show the two most far towns.");
        printf ("\n\t3 - Show far town by selected town.");
        printf ("\n\t4 - Show middletown.");
        printf ("\n\t5 - Calculate the number of kilometers the milkman trips.");
		printf ("\n\t6 - Exit.");
		printf ("\n\nInsert number: ");
        fflush(stdin);
        scanf ("%d", &input);
	} while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6);

    return input;
}

/**
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns void
 */
void addData()
{
    // STEP 1: Add names
    for(int i = 0; i < MAX; i++)
    {
        commonClear();
        printf ("\n- Towns of Seville Software -");
        printf("\n\nEnter details of town %d", i + 1);

        // To assign id
        towns[i].id = i;

        // To assign name
        printf("\nName: ");
        scanf("%s", towns[i].name);
    }

    // STEP 2: Add kilometers
    for(int i = 0; i < MAX; i++)
    {
        commonClear();
        printf ("\n- Towns of Seville Software -");
        printf("\n\nEnter kilometers of town %s", towns[i].name);

        for(int j = 0; j < MAX; j++) {
            if (i == j) {
                continue;
            }

            printf("\nEnter from %s to %s: ", towns[i].name, towns[j].name);
            scanf("%f", &towns[i].kilometers[i][j]);
        }
    }
}
