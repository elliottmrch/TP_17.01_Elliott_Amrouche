#include <stdio.h>
#include <stdlib.h>

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

void displayMenu(struct Application * app)
{
    printf("--%s--\n", app->nom);
    for (int i = 0; i < app->nb_menus; i++)
    {
        printf("%d. %s\n", i + 1, app->menus[i].option);
    }
    printf("Choissisez une option (0 pour quitter) :");
}

void runApplication(struct Application * app)
{
    int choix = -1;
    while (choix != 0)
    {
        displayMenu(app);
        scanf_s("%d", &choix);
        if (choix > 0 && choix <= app->nb_menus)
        {
            printf("Vous avez selectionne %s\n", app->menus[choix - 1].option);
        }
        else if (choix != 0)
        {
            printf("Option invalide\n");
        }
    }
}

void runPhone(struct Application * app1, struct Application * app2)
{
    int choix = -1;
    while (choix != 0)
    {
        printf("--- Applications ---\n");
        printf("1. %s\n", app1->nom);
        printf("2. %s\n", app2->nom);
        printf("0. Quitter\n");
        scanf_s("%d", &choix);

        switch (choix)
        {
            case 1:
                runApplication(app1);
                break;
            case 2:
                runApplication(app2);
                break;
            default:
                printf("Option invalide\n");
                break;
        }
    }
}


int main()
{
    struct Menu MenusPhotos[] = {
        {"Regarder une photo"},
        {"Prendre une photo"},
        {"Prendre une video"},
        {"Activer/Desactiver le flache"}
    };

    struct Application Photos = {
        "Photos",
        MenusPhotos,
        sizeof(MenusPhotos) / sizeof(MenusPhotos[0])
    };

    struct Menu MenusMessages[] = {
        {"Lire un message"},
        {"Envoyer un message"},
        {"Supprimer un message"},
        {"Bloquer un contact"}
    };

    struct Application Messages = {
        "Messages",
        MenusMessages,
        sizeof(MenusMessages) / sizeof(MenusMessages[0])
    };

    //displayMenu(&Photos);
    //runApplication(&Photos);
    runPhone(&Photos, &Messages);

    return 0 ;
}