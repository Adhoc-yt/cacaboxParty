# Projet en cours de développement - Cacabox Party Games

## Description du projet (en version Alpha)

### Choix des langages
BackEnd C++, DBMS PostreSQL, FrontEnd JS

### Description
Le but est de créer une application de duel entre amis, où le vainqueur est designé par vote du public (Integration Chat Twitch)

Un Duel a un thème, et deux participants à qui on demande d'envoyer une Proposition d'un certain type : un texte, une image, ou une video.

Les participants ont rempli une base données de réponses avant le lancement du jeu (TODO - Schemas).

La durée du vote est uniforme et définie à l'avance.

L'affichage des pseudos sur les Propositions au moment du vote, ou après le vote, ainsi que la mention d'un score, sont optionnels.

### Rôles
- Host : Streamer qui a rejoint le site en premier
- Streamer : peut diffuser les questions et les réponses, et vote a la souris sur le site (Son vote vaut 1)
- Viewer : peut, via le chat Twitch, voter pour la réponse de son choix. 

Le Host peut définir les options (petite couronne devant son pseudo).

Si tous les Streamers sont prêts, le jeu démarre immédiatement.

Une fois le jeu lancé, tous les Streamers voient les réponses et les votes au même moment - s'ils actualisent la page ou quittent/reviennent, ils voient tous la même chose.

Le vote des Viewers est comptabilisé séparément du vote des Streamers (50% Streamers - 50% Viewers). Par exemple, s'il y a 7 Streamers, le vote du public peut apporter jusqu'à 7 points.

Lorsque le vote est terminé, il y a une animation de victoire ainsi qu'un effet sonore.

A la fin d'un Duel, c'est le Host qui décide de lancer le Duel suivant en cliquant sur "NEXT".

## Vues

- Accueil - Montre une liste des Streamers connectés, ainsi qu'une liste d'options :
    - Durée du vote en secondes (par défaut 120)
    - Affichage des pseudos avant le vote
    - Affichage des scores
    - Un bouton "Ready" qui active ou désactive l'etat "Ready" d'un Streamer.

- Duel - Montre le Thème du Duel en haut, montre la première Proposition, puis la seconde, puis oppose les deux, separées par une animation d'éclair/VS/explosion/etc. Ensuite, le vote demarre, et les votes sont affichés en direct sur une "Barre de vie" en bas.

- Classement - Affiche les scores par Duel et par Vote

### Widgets

Widget = un module présent sur toutes les vues.
- Liste des Streamers connectés au jeu
- Nombre de duels restants

## Score

Types de score :
- par Duel : Chaque duel gagne rapporte un point de Duel au Streamer élu.
- par Vote : Chaque vote rapporte un point de Vote au Streamer élu.

Le Streamer qui a le plus haut score par Duel gagne la partie.

Le Streamer qui a le plus de votes de Viewers obtient une mention honorable "le plus aimé du public".