# Projet en cours de développement - Cacabox Party Games

## Description du projet (en version Alpha)

### Choix des langages
BackEnd C++, FrontEnd JS

### Description
Le but est de créer une application de duel entre amis, où le vainqueur est designé par vote du public (Integration Chat Twitch)

Un Duel a un thème, et deux participants à qui on demande d'envoyer une Proposition d'un certain type : un texte, une image, ou une video.

Les participants ont rempli une base données de réponses avant le lancement du jeu (TODO - Schemas).

La durée du vote est uniforme et définie à l'avance.

L'affichage des pseudos sur les Propositions au moment du vote, ou après le vote, ainsi que la mention d'un score, sont optionnels.

### Rôles
- Host
- Streamer
- Viewer

Le Host est le Streamer qui a rejoint le site en premier, et peut définir les options (petite couronne devant son pseudo).

Un Streamer peut diffuser les questions et les réponses (rôle passif)

Un Viewer peut, via le chat Twitch, voter pour la réponse de son choix.

Une fois le jeu lancé, tous les Streamers voient les réponses et les votes au même moment - s'ils actualisent la page ou quittent/reviennent, ils voient tous la même chose.

Lorsque suffisamment de Streamers sont "Ready", une alerte sonne et un chronomètre démarre avant que le jeu ne se lance.

Si tous les Streamers sont prêts, le jeu démarre immédiatement.

## Vues

- Accueil - Montre une liste des Streamers connectés, ainsi qu'une liste d'options :
    - Durée du vote en secondes
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

Le Streamer qui a le plus de votes obtient une mention honorable "le plus aimé du public".