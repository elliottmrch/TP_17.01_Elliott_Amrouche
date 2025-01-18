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

void updateMenu(struct Application * app, int menuIndex, const char * newOption)
{
    if (menuIndex >= 0 && menuIndex < app->nb_menus)
    {
        app->menus[menuIndex].option = newOption;
        printf("L'option %d a ete mise a jour avec succes.\n", menuIndex + 1);
    }
    else
    {
        printf("Index de menu invalide.\n");
    }
}

void updateApplication(struct Application * app, const char * newName, struct Menu * newMenus, int newMenuCount)
{
    app->nom = newName;
    app->menus = newMenus;
    app->nb_menus = newMenuCount;
    printf("L'application a ete mise a jour avec succes.\n");
}

void runPhone(struct Application * app1, struct Application * app2)
{
    int choix = -1;
    while (choix != 0)
    {
        printf("--- Applications ---\n");
        printf("1. %s\n", app1->nom);
        printf("2. %s\n", app2->nom);
        printf("3. Modifier le menu de '%s'\n", app1->nom);
        printf("4. Modifier l'application '%s'\n", app2->nom);
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
            case 3:
                {
                    int menuIndex;
                    char newOption[100];
                    printf("Entrez l'index du menu a modifier (1 a %d) : ", app1->nb_menus);
                    scanf_s("%d", &menuIndex);
                    printf("Entrez la nouvelle option : ");
                    scanf_s("%99s", newOption, 100);
                    updateMenu(app1, menuIndex - 1, newOption);
                }
                break;
            case 4:
                {
                    char newName[100];
                    struct Menu newMenus[10];
                    int newMenuCount;
                    printf("Entrez le nouveau nom de l'application : ");
                    scanf_s("%99s", newName, 100);
                    printf("Entrez le nombre de nouvelles options de menu : ");
                    scanf_s("%d", &newMenuCount);
                    for (int i = 0; i < newMenuCount; i++)
                    {
                        char newOption[10][100];
                        printf("Entrez la nouvelle option %d : ", i + 1);
                        scanf_s("%99s", newOption[i], 100);
                        newMenus[i].option = newOption[i];
                    }
                    updateApplication(app2, newName, newMenus, newMenuCount);
                }
                break;
            case 0:
                printf("Exit\n");
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

    runPhone(&Photos, &Messages);

    return 0 ;
}