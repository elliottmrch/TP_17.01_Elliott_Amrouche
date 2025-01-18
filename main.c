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
        //system("cls");
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

    //displayMenu(&Photos);
    runApplication(&Photos);

    return 0 ;
}