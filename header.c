/**
 * \file header.c
 * \brief Towns of Seville.
 * Short description
 * \author José Javier Peleato Pradel
 * \version 1.0.0
 * \date 2020-09-20
 */

// Libraries and constants
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * \brief Do not execute when the MAX variable is less than 3 and more than 10.
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return int If the value is 0 the MAX constant is out of range, inversely, the value 1, it is fine.
 */
int checkMaxValue()
{
    if (MAX < 3 || MAX > 10) {
        return 0;
    }

    return 1;
}

/**
 * \brief Clear terminal according Operating System
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void commonClear()
{
    if (OS == "win") {
        system("cls");
    } else {
        system("clear");
    }
}

/**
 * \brief Common function to force a wait in the execution
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void commonAwait()
{
    int await;

    do {
        printf("\n\nPress 0 to continue with the application: ");
        fflush(stdin);
	    scanf("%d", &await);
	} while (await != 0);
}

/**
 * \brief Common function to force a sleep in the execution
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void commonSleep()
{
    sleep(1);
}

/**
 * \brief Function that displays a Splash Screen
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void drawSplashScreen()
{
    commonSleep();
	printf("\n__        __   _"); commonSleep();
	printf("\n\\ \\      / /__| | ___ ___  _ __ ___   ___"); commonSleep();
	printf("\n \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\"); commonSleep();
	printf("\n  \\ V  V /  __/ | (_| (_) | | | | | |  __/"); commonSleep();
	printf("\n   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|"); commonSleep();
	printf("\n\n"); commonSleep();
	printf("\nTowns of Seville"); commonSleep();
	printf("\nVersion 1.0.0"); commonSleep();
	printf("\nJose Javier Peleato Pradel"); commonSleep();
}

/**
 * \brief Function that displays a main menu
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return int Returns the number of the action
 */
int menu()
{
    int input;

    do {
        commonClear();
        printf("- Towns of Seville Software -");
        printf("\n\nMain menu.");
        printf("\n\n\t1 - Show distances table between towns.");
        printf("\n\t2 - Show the two most far towns.");
        printf("\n\t3 - Show far town by selected town.");
        printf("\n\t4 - Show middletown.");
        printf("\n\t5 - Calculate the number of kilometers the milkman trips.");
        printf("\n\t6 - Exit.");
        printf("\n\nInsert number: ");
        fflush(stdin);
        scanf("%d", &input);
	} while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6);

    return input;
}

/**
 * \brief Function that displays a towns menu
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return int Returns the number of the town
 */
int menuTowns()
{
    int select, i;

    do {
        commonClear();

        for (i = 0; i < MAX; i++) {
            printf("\n\t%d - %s", towns[i].id, towns[i].name);
        }

        printf("\n\nInsert number: ");
        fflush(stdin);
        scanf("%d", &select);
	} while (select < 0 || select > (MAX-1));

    return select;
}

/**
 * \brief Data insert process
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void addData()
{
    int i, j;

    // STEP 1: Add names
    for(i = 0; i < MAX; i++)
    {
        commonClear();
        printf("\n- Towns of Seville Software -");
        printf("\n\nEnter details of town %d", i + 1);

        // To assign id
        towns[i].id = i;

        // To assign name
        printf("\n\nWhat is the town's name?: ");
        fflush(stdin);
        scanf("%s", towns[i].name);
    }

    // STEP 2: Add kilometers
    for(i = 0; i < MAX; i++)
    {
        commonClear();
        printf("\n- Towns of Seville Software -");
        printf("\n\nAdd kilometers of town %s\n", towns[i].name);

        for(j = 0; j < MAX; j++) {
            if (i == j) {
                continue;
            }

            if (j < i) {
                towns[i].kilometers[i][j] = towns[j].kilometers[j][i];
            } else {
                printf("\nInsert from %s to %s: ", towns[i].name, towns[j].name);
                fflush(stdin);
                scanf("%f", &towns[i].kilometers[i][j]);
            }
        }

        commonClear();
    }
}

/**
 * \brief Show distances table between towns
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void showDistancesBetweenTowns()
{
    int i, j;

    // STEP 1: Print header
    printf("Show distances table between towns.");
    printf("\n\n");

    for (i = 0; i < MAX; i++) {
        if (i == 0) {
            printf("%10s | ", "");
        }

        printf("%10s | ", towns[i].name);
    }

    // STEP 2: Print data
    for (i = 0; i < MAX; i++) {
        printf("\n%10s | ", towns[i].name);

        for(j = 0; j < MAX; j++) {
            printf("%10.2f | ", towns[i].kilometers[i][j]);
        }
    }
}

/**
 * \brief Show the two most far towns
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void showTwoMostFarTowns()
{
    int i, j;
    struct town firstTown;
    struct town lastTown;
    float value = 0.0;
    
    printf("Show the two most far towns.");

    for(i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            float kilometer = towns[i].kilometers[i][j];

            if (value < kilometer) {
                value = kilometer;
                firstTown = towns[i];
                lastTown = towns[j];
            }
        }
    }
    
    printf("\n\nThe most far towns are %s and %s with %.2f kilometers", firstTown.name, lastTown.name, value);
}

/**
 * \brief Show furthest town by selected town
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void showFarTownByTown()
{
    int townId, i;
    townId = menuTowns();
    struct town currentTown;
    currentTown = towns[townId];
    struct town lastTown;
    float value = 0.0;

    printf("Show far town by selected town.\n");

    for(i = 0; i < MAX; i++) {
        float kilometer = currentTown.kilometers[townId][i];

        if (value < kilometer) {
            value = kilometer;
            lastTown = towns[i];
        }
    }

    printf("\nThe furthest town from %s is %s with %.2f kilometers", currentTown.name, lastTown.name, value);
}

/**
 * \brief Show middletown
 * The most central town is calculated by adding the distances from that town to all others, the town have a smaller value.
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void showMiddletown()
{
    int i, j;
    struct town middleTown;
    float value = 12000.0;

    printf("Show middletown.");

    for(i = 0; i < MAX; i++) {
        float sum = 0.0;
        for(j = 0; j < MAX; j++) {
            sum += towns[i].kilometers[i][j];
        }

        if (sum < value) {
            middleTown = towns[i];
            value = sum;
        }
    }

    printf("\n\nThe most central town is %s with total %.2f kilometers", middleTown.name, value);
}

/**
 * \brief Calculate the number of kilometers the milkman trips
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return void Does not return anything
 */
void showMilkman()
{
    int current, trip, counter, auxiliar, i;
    int trips[ROUTE];
    counter = 0;
    auxiliar = 0;

    // STEP 1: Starting city
    do {
        commonClear();
        printf("Calculate the number of kilometers the milkman trips.");
        printf("\n\nWhere is the milkman?\n");

        for (i = 0; i < MAX; i++) {
            printf("\n\t%d - %s", towns[i].id, towns[i].name);
        }
        
        printf("\n\nInsert number: ");
        fflush(stdin);
        scanf("%d", &current);
    } while (current < 0 || current > (MAX-1));

    trips[counter] = current;
    auxiliar = current;
    
    // STEP 2: Create the route
    do {
        commonClear();
        printf("Calculate the number of kilometers the milkman trips.");
        printf("\n\nWhat is the next town?");
        printf("\n\n\t-1 - Exit");
        
        for (i = 0; i < MAX; i++) {
            if (i == auxiliar) {
                continue;
            }

            printf("\n\t%d - %s", towns[i].id, towns[i].name);
        }

        printf("\n\nInsert number: ");
        fflush(stdin);
        scanf("%d", &trip);
        
        if (trip >= 0 && trip < MAX && auxiliar != trip) {
            counter++;
            trips[counter] = trip;
            auxiliar = trip;
        }
    } while (trip != -1 && counter < ROUTE);

    // STEP 3: Calculate the route
    commonClear();
    printf("Calculate the number of kilometers the milkman trips.\n");

    float kilometers = 0.0;
    for (i = 0; i < counter; i++) {
        int currentIndex = trips[i];
        int nextIndex = trips[i+1];

        struct town currentTown = towns[currentIndex];
        struct town nextTown = towns[nextIndex];
        float value = currentTown.kilometers[currentIndex][nextIndex];
        kilometers += value;

        printf("\nThe milkman has traveled %.2f kilometers from %s to %s", value, currentTown.name, nextTown.name);
    }

    printf("\n\nThe milkman total trip is: %.2f kilometers", kilometers);
}
