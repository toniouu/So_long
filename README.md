🐉 so_long

🎮 Description du Projet

so_long est le tout premier projet graphique à l'école 42. L'objectif est de créer un petit jeu en 2D où le joueur doit naviguer à travers un labyrinthe pour atteindre une destination finale. Pour gagner, le joueur doit collecter tous les objets disséminés dans le labyrinthe avant de pouvoir sortir.

🚀 Fonctionnalités

Contrôles du Joueur : Utilisez les touches du clavier pour déplacer votre personnage à travers le labyrinthe.

  W ou Flèche haut : Se déplacer vers le haut.
  
  S ou Flèche bas : Se déplacer vers le bas.
  
  A ou Flèche droit : Se déplacer vers la droite.
  
  D ou Flèche gauche : Se déplacer vers la gauche.
  
Collecte d'Objets : Ramassez tous les objets pour pouvoir accéder à la sortie.

Carte Personnalisée : Chargez et jouez sur différentes cartes créées à partir de fichiers texte (.ber).


🛠️ Technologies Utilisées

C Language : Programmation en C pour une gestion efficace de la mémoire et des performances.
MiniLibX : Une bibliothèque graphique simple pour gérer les fenêtres et les événements.
Makefile : Automatisation de la compilation avec un Makefile.

📦 Lancement

1. Cloner le dépôts :
   
       git clone https://github.com/toniouu/So_long.git
   
       cd So_long

3. Compiler le projet :

       make

5. Lancer le jeu :
   
       ./so_long Map/my_map.ber


Si la compilation ne marche pas correctement, essayer d'installer les packages nécéssaires pour pouvoir compiler le Minilibx:

    sudo apt install libx11-dev libxext-dev libxpm-dev libxrandr-dev

Puis relancer le jeu.

🗺️ Format des Cartes

Les cartes sont des fichiers texte (.ber) contenant des caractères spécifiques pour définir les murs, le joueur, les objets, et la sortie. Voici un exemple de carte :

111111

1P0CE1

111111

1 : Murs

P : Joueur

C : Collectible

E : Sortie

0 : Vide


Remarque : J'étais trop proche du blackhole quand j'ai fait ce projet, donc c'est normal si ce n'est pas encore trop top, mais je vais essayer de l'ameliorer petit à petit pour que ça soit agréable. Merci pour votre compréhension...



