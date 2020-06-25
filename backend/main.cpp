#include <iostream>
#include "database_connector.h"
#include "logger.h"
/* TODO: Connect to DB and test CRUD */

template<class TupType, size_t... I>
void print_helper(const TupType& _tup, std::index_sequence<I...>)
{
    std::cout << "(";
    (..., (std::cout << (I == 0? "" : ", ") << std::get<I>(_tup)));
    std::cout << ")\n";
}

template<class... T>
void print (const std::tuple<T...>& _tup)
{
    
    print_helper(_tup, std::make_index_sequence<sizeof...(T)>());
}

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
    logger::info("Connection db");
    database_connector dbc;
            //for (const auto& val : db.query<int, std::string>("SELECT blabal")) {
            //do things
        //}
    logger::info("debut requete");
    for (const auto& val : dbc.query<int, 
    int, 
    std::string_view, 
    std::string_view, 
    std::string_view, 
    std::string_view>("SELECT * FROM Streamer")){
        print(val);
    };
    logger::info("fin pgm");
    return 0;
}