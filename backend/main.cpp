#include <iostream>
#include "database_connector.h"
#include "logger.h"
/* TODO: Connect to DB and test CRUD */

int main(int argc, char** argv) {
    // OBJECTIF: connecteur DB et ajouter un streamer puis le recuperer et l'afficher en console
    /*
        ouvrir fichier db.conf
        lire valeurs
        connectiondb avec libPQ++
        tentative de read des DB
        create streamer
        read
        exit
    */
    logger::error("texte ici");
    database_connector dbc;
    return 0;
}