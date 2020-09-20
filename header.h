#ifndef _HEADER_H
    #define _HEADER_H
    #ifdef _WIN32
        #define OS "win32"
    #elseif _WIN64
        #define OS "win64"
    #else
        #define OS "unix"
    #endif
    #define MAX 10
    #define ROUTE 50

    // Prototypes
    int checkMaxValue();
    void commonClear();
    void commonAwait();
    void commonSleep();
    void drawSplashScreen();
    int menu();
    int menuTowns();
    void addData();
    void showDistancesBetweenTowns();
    void showTwoMostFarTowns();
    void showFarTownByTown();
    void showMiddletown();
    void showMilkman();

    /**
     * \struct town
     * \brief Represents a structure of a town.
     */
    struct town
    {
        int id;
        char name[50];
        float kilometers[MAX][MAX];
    };
    struct town towns[MAX];
#endif
