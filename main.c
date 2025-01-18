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

void displayMenu(struct Application * app)
{
    printf("--%s--\n", app->nom);
    for (int i = 0; i < app->nb_menus; i++)
    {
        printf("  %d. %s\n", i + 1, app->menus[i].option);
    }
    printf("  Choissisez une option (0 pour quitter)");
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

    displayMenu(&Photos);

    return 0 ;
}