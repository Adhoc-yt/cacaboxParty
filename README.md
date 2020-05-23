# Projet en cours de developpement - Cacabox Party Games

## Description du projet (en version Alpha)

### Choix des langages
BackEnd C++, FrontEnd JS

### Description
Le but est de creer une application de duel entre amis, ou le vainqueur est designe par vote du public (Integration Chat Twitch)

Les participants ont rempli une base donnees de reponses avant le lancement du jeu (TODO - Schemas)

La duree du vote est uniforme et definie a l'avance.

L'affichage des pseudos sur les realisations au moment du vote ou apres le vote, est decide a l'avance.

### Roles
- Streamer
- Host
- Viewer

Un Streamer peut diffuser les questions et les reponses (role passif)
Le Host est le Streamer qui a rejoint le site en premier, et peut definir les options (petite couronne devant son pseudo)
Un Viewer peut, via le chat Twitch, voter pour la reponse de son choix

Une fois le jeu lance, tous les Streamers voient les reponses et les votes au meme moment - s'ils actualisent la page ou quittent/reviennent, ils voient tous la meme chose.

Lorsque suffisamment de Streamers sont "Ready", une alerte sonne et un timeur demarre avant que le jeu ne se lance.

Si tous les Streamers sont prets, le jeu demarre immediatement.

## Vues

- Accueil - Montre une liste des Streamers connectes, ainsi qu'une liste d'options:
    - Duree du vote
    - Affichage des pseudos
    - Affichage des scores
    - Un bouton "Ready" qui active ou desactive l'etat "Ready" d'un Streamer.

- Duel texte/image - Montre le Theme du Duel en haut, diffuse les deux propositions en meme temps, separees par une animation d'eclair/VS/explosion/etc.
- Duel video - Joue la premiere video, puis la seconde, puis oppose les deux miniatures, separees par une animation d'eclair/VS/explosion/etc.


- Classement - Affiche les scores par Duel et par Vote

## Score

Types de score:
- par Duel: Chaque duel gagne rapporte un point de Duel au Streamer elu.
- par Vote: Chaque vote rapporte un point de Vote au Streamer elu.

Le Streamer qui a le plus haut score par Duel gagne la partie.

Le Streamer qui a le plus de votes obtient une mention honorable "le plus aime".