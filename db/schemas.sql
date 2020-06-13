
CREATE TABLE Streamer (
    id_streamer SERIAL PRIMARY KEY, 
    id_twitch INT UNIQUE NOT NULL,
    nom_affiche TEXT,
    /* On stocke les chemins des fichiers suivants: */
    avatar TEXT, 
    son_victoire TEXT,
    son_defaite TEXT
);
/* INSERT INTO Streamer(id_twitch, nom_affiche, avatar, son_victoire, son_defaite)
 VALUES (
    1234,
    'Supercon',
    'serveur/dossier/supercon.jpg',
    'serveur/dossier/youjustgotassaded.mp3',
    'serveur/dossier/supercon_loser.wav'
    ); */

CREATE TABLE Duel (
    id_duel SERIAL PRIMARY KEY,
    theme TEXT NOT NULL,
    type_propositions TEXT NOT NULL,
    participant1 SERIAL REFERENCES Streamer(id_streamer) NOT NULL,
    participant2 SERIAL REFERENCES Streamer(id_streamer) NOT NULL
);

CREATE TABLE Resultat (
    id_duel SERIAL REFERENCES Duel(id_duel), 
    vainqueur SERIAL REFERENCES Streamer(id_streamer) NOT NULL
);

CREATE TABLE Proposition (
    id_duel SERIAL REFERENCES Duel(id_duel) NOT NULL,
    id_auteur SERIAL REFERENCES Streamer(id_streamer) NOT NULL,
    /* data peut etre une URL YouTube, un texte ou 
    une image - dans ce dernier cas on stocke un chemin. */
    data TEXT,
    PRIMARY KEY (id_duel, id_auteur)
);
