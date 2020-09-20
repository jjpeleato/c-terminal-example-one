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
int checkMaxValue();
void commonClear();
void commonAwait();
void commonSleep();
void drawSplashScreen();
void addData();
int menu();
void showDistancesBetweenTowns();
void showTwoMostFarTowns();

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
    // STEP 0: Not run
    int isCheckMaxValue = checkMaxValue();
    if (isCheckMaxValue == 0) {
        printf ("\nFor security reasons the program has been stopped.");
        printf ("\nPlease check the MAX constant. It must have a value between 3 and 10, inclusive.\n");

        return 0;
    }

    // STEP 1: Splash screen
    drawSplashScreen();
    commonAwait();

    // STEP 2: Insert kilometer data
    addData();
    commonClear();

    // STEP 3: Start menu
    int action;
    while (action != 6){
		action = menu();
        commonClear();

        switch (action) {
            case 1:
                printf ("Show distances table between towns.");
                showDistancesBetweenTowns();
                commonAwait();
                break;
            case 2:
                printf ("Show the two most far towns.");
                showTwoMostFarTowns();
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
 * \brief Do not execute when the MAX variable is less than 3 and more than 10
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns int
 */
int checkMaxValue()
{
    if (MAX < 3 || MAX > 10) {
        return 0;
    }

    return 1;
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
        printf("\n\nAdd kilometers of town %s", towns[i].name);

        for(int j = 0; j < MAX; j++) {
            if (i == j) {
                continue;
            }

            if (j < i) {
                towns[i].kilometers[i][j] = towns[j].kilometers[j][i];
            } else {
                printf("\nInsert from %s to %s: ", towns[i].name, towns[j].name);
                scanf("%f", &towns[i].kilometers[i][j]);
            }
        }
    }
}

/**
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns void
 */
void showDistancesBetweenTowns()
{
    // STEP 1: Print header
    printf("\n\n");
    for (int i = 0; i < MAX; i++) {
        if (i == 0) {
            printf("%10s | ", "");
        }

        printf("%10s | ", towns[i].name);
    }

    // STEP 2: Print data
    for (int i = 0; i < MAX; i++) {
        printf("\n%10s | ", towns[i].name);

        for(int j = 0; j < MAX; j++) {
            printf("%10.2f | ", towns[i].kilometers[i][j]);
        }
    }
}

/**
 * \brief Short description
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \returns void
 */
void showTwoMostFarTowns()
{
    struct town firstTown;
    struct town lastTown;
    float value = 0.0;

    for(int i = 0; i < MAX; i++) {
        float kilometer = towns[0].kilometers[0][i];
        if (value < kilometer) {
            value = kilometer;
            firstTown = towns[0];
            lastTown = towns[i];
        }
    }

    printf("\n\nThe most far towns are %s and %s with %.2f kilometers", firstTown.name, lastTown.name, value);
}
