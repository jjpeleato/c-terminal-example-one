/**
 * \file main.c
 * \brief Towns of Huesca.
 * The Aragón government has explained that there are 10 towns in Huesca and that it is going to provide us with the distances in kilometers between each of the towns.
 * 
 * Build a software that saved, showed and calculate the kilometers between towns.
 * \author José Javier Peleato Pradel
 * \version 1.0.0
 * \date 2020-09-20
 */

// Libraries
#include <stdio.h>
#include "header.h"

/**
 * \brief Main function.
 * Software that saved, showed and calculate the kilometers between towns.
 * \author José Javier Peleato Pradel
 * \since 1.0.0
 * \date 2020-09-20
 * \return int Returns zero if successful. Any other number an error has occurred
 */
int main ()
{
    // STEP 0: Not run
    int isCheckMaxValue = checkMaxValue();
    if (isCheckMaxValue == 0) {
        printf("\nFor security reasons the program has been stopped.");
        printf("\nPlease check the MAX constant. It must have a value between 3 and 10, inclusive.\n");

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
                showDistancesBetweenTowns();
                commonAwait();
                break;
            case 2:
                showTwoMostFarTowns();
                commonAwait();
                break;
            case 3:
                showFarTownByTown();
                commonAwait();
                break;
            case 4:
                showMiddletown();
                commonAwait();
                break;
            case 5:
                showMilkman();
                commonAwait();
                break;
            default:
                break;
        }
    }
    
    return 0;
}
