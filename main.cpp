// ESTRUCTURA DE DATOS II
// SIMULADOR CLIENTE DE CORREO ELECTRÓNICO

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "Emails.h"

#define MAIL_FILE_NAME "emails"
#define DATETIME 10

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix) || defined(__unix__) || defined(__unix) || defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#else
#error "OS is not supported to clear the screen properly"
#endif

using namespace std;

// Prototipos de funciones
void showMenu(void);

// Elaborar menú
enum MENU_OPTIONS
{
    EXIT = 0,
    CREATE_MAIL,
    READ_MAIL,
    UPDATE_MAIL,
    DELETE_MAIL,
    CREATE_BACKUP,
    READ_BACKUP
};

MENU_OPTIONS getMenuOption()
{
    int option;
    cout << "What do you want to do? ";
    cin >> option;
    cin.ignore();
    return static_cast<MENU_OPTIONS>(option);
}

int main()
{
    Emails newEmail;
    bool exit = false;
    ofstream file;

    while (!exit)
    {
        showMenu();
        MENU_OPTIONS optionSelected = getMenuOption();
        switch (optionSelected)
        {
        case EXIT:
            exit = true;
            break;
        case CREATE_MAIL:
            system(CLEAR);
            cout << "=============================================" << endl
                 << "|            WRITE A NEW E-MAIL             |" << endl
                 << "=============================================" << endl;
            file.open(MAIL_FILE_NAME, ios::binary | ios::app);
            if (file.is_open())
            {
                newEmail.readFromUser();
                file.write(reinterpret_cast<const char *>(&newEmail), sizeof(Emails));
                file.close();
            }
            else
            {
                cout << "ERROR: FILE COULD NOT BE OPENED" << endl;
            }
            cin.get();

            break;
        case READ_MAIL:
            char option;
            system(CLEAR);
            cout << "=============================================" << endl
                 << "|              READ AN E-MAIL               |" << endl
                 << "=============================================" << endl
                 << "I. Seek an read by Id                        " << endl
                 << "T. Seek an read by To                        " << endl
                 << "A. Read all                                  " << endl
                 << "Choose an option (I/T/A): ";
            cin >> option;
            cin.ignore();

            if (option == 'I' || option == 'i')
            {

            }else if (option == 'T' || option == 't')
            {
            
            }else if (option == 'A' || option == 'a')
            {

            }else
            {
                cout << "ERROR: OPTION DOES NOT EXITS, CHOOSE ANOTHER" << endl
                     << "PRESS INTRO TO CONTINUE..." << endl;
                cin.get();
            }                
            break;
        case UPDATE_MAIL:
            system(CLEAR);
            cout << "=============================================" << endl
                 << "|             UPDATE AN E-MAIL              |" << endl
                 << "=============================================" << endl;
            cin.get();
            break;
        case DELETE:
            system(CLEAR);
            cout << "=============================================" << endl
                 << "|             DELETE AN E-MAIL              |" << endl
                 << "=============================================" << endl;
            cin.get();
            break;
        case CREATE_BACKUP:
            system(CLEAR);
            cout << "=============================================" << endl
                 << "|             CREATE A BACK-UP              |" << endl
                 << "=============================================" << endl;
            cin.get();
            break;
        case READ_BACKUP:
            system(CLEAR);
            cout << "=============================================" << endl
                 << "|              READ A BACK-UP               |" << endl
                 << "=============================================" << endl;
            cin.get();
            break;
        default:
            system(CLEAR);
            cout << "ERROR: OPTION DOES NOT EXITS, CHOOSE ANOTHER" << endl
                 << "PRESS INTRO TO CONTINUE..." << endl;
            cin.get();
            break;
        }
        file.close();
    }

    return 0;
}


void showMenu(void)
{
    system(CLEAR);
    cout << "==================================================" << endl
         << "|                                 _________      |" << endl
         << "|                               .`.        `.    |" << endl
         << "|                              /   \\ .======.\\   |" << endl
         << "|   E-MAIL CLIENT SIMULATOR    |   | |______||   |" << endl
         << "|   ESTRUCTURAS DE DATOS II    |   |   _____ |   |" << endl
         << "|   PROF. CESAR ASCENCIO       |   |  /    / |   |" << endl
         << "|   EST. ERICK ROMERO          |   | /____/  |   |" << endl
         << "|                              | _ |         |   |" << endl
         << "|                              |/ \\|.-\"```\"-.|   |" << endl
         << "|                              `` |||      |||   |   " << endl
         << "|                                  `\"`      `\"   | " << endl
         << "==================================================   " << endl
         << "1. Create" << endl
         << "2. Read" << endl
         << "3. Update" << endl
         << "4. Delete" << endl
         << "5. Make a backup (Export to CSV!)" << endl
         << "6. Load a backup (Import from CSV!)" << endl
         << "0. Salir" << endl;
}