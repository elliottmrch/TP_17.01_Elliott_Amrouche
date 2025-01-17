#include <stdio.h>

struct Menu
{
    const char * option;
};

struct Application
{
    const char * nom;
    struct Menu * menus;
    int nb_menus;
};

int main()
{
    struct Menu menusInstagram[] = {
        {"Message"},
        {"Photo"},
        {"Compte"},
        {"Parametres"},
        {"Deconnexion"}
    };
    struct Application Instragram = {
        "Instagram",
        menusInstagram,
        sizeof(menusInstagram) / sizeof(menusInstagram[0])
    };

    struct Menu menusFacebook[] = {
        {"Message"},
        {"Photo"},
        {"Compte"},
        {"Parametres"},
        {"Deconnexion"}
    };
    struct Application Facebook = {
        "Facebook",
        menusFacebook,
        sizeof(menusFacebook) / sizeof(menusFacebook[0])
    };

    printf("Application: %s\n", Instragram.nom);
    for (int i = 0; i < Instragram.nb_menus; i++)
    {
        printf("  %d. %s\n", i + 1, Instragram.menus[i].option);Etape 1
    }

    printf("Application: %s\n", Facebook.nom);
    for (int i = 0; i < Facebook.nb_menus; i++)
    {
        printf("  %d. %s\n", i + 1, Facebook.menus[i].option);
    }
    return 0 ;
}