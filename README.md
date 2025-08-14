# My Sokoban - Projet Epitech

## Description

Ce projet est une implémentation du jeu classique **Sokoban** développée dans le cadre du cursus Epitech. Le Sokoban est un jeu de puzzle où le joueur doit pousser des caisses sur des emplacements cibles dans un entrepôt.

## Fonctionnalités

### ✅ Fonctionnalités implémentées

- **Interface graphique** : Utilisation de la bibliothèque ncurses pour l'affichage
- **Gestion des cartes** : Lecture et affichage de cartes depuis des fichiers texte
- **Contrôles** : Déplacement du joueur avec les touches directionnelles
- **Logique de jeu** : 
  - Déplacement du joueur (P)
  - Poussée des caisses (X)
  - Détection des emplacements cibles (O)
  - Conditions de victoire et de défaite
- **Gestion d'erreurs** : Validation des cartes et gestion des cas d'erreur
- **Compilation** : Makefile complet avec règles de nettoyage

### 🎮 Comment jouer

1. Compilez le projet : `make`
2. Lancez le jeu : `./my_sokoban map1.txt`
3. Utilisez les touches directionnelles pour déplacer le joueur
4. Poussez toutes les caisses (X) sur les emplacements cibles (O) pour gagner
5. Appuyez sur 'q' pour quitter

### 📁 Structure du projet

```
├── src/                    # Code source principal
│   ├── screen.c           # Gestion de l'écran ncurses
│   ├── screen_fonctions.c # Fonctions d'affichage
│   ├── move.c             # Gestion des déplacements
│   ├── move2.c            # Fonctions de mouvement avancées
│   ├── array.c            # Manipulation des tableaux
│   ├── fill_tab.c         # Remplissage des structures
│   ├── open.c             # Ouverture des fichiers
│   ├── manage_errors.c    # Gestion des erreurs
│   ├── end_victory.c      # Conditions de victoire
│   ├── end_defeat.c       # Conditions de défaite
│   └── ...
├── lib/my/                # Bibliothèque personnelle
├── main.c                 # Point d'entrée du programme
├── my.h                   # Header principal
├── Makefile              # Fichier de compilation
└── map1.txt              # Carte d'exemple
```

### 🗺️ Format des cartes

Les cartes sont des fichiers texte utilisant les caractères suivants :
- `#` : Mur
- `P` : Joueur
- `X` : Caisse
- `O` : Emplacement cible
- ` ` : Espace vide

## Compilation et utilisation

### Prérequis
- GCC
- Bibliothèque ncurses (`sudo apt-get install libncurses5-dev` sur Ubuntu/Debian)
- Make

### Commandes

```bash
# Compilation
make

# Nettoyage des fichiers objets
make clean

# Nettoyage complet
make fclean

# Recompilation complète
make re

# Exécution
./my_sokoban <fichier_carte>
```

## État du projet

### ✅ Fonctionnalités de base complètes

Ce projet implémente toutes les fonctionnalités de base requises pour un Sokoban fonctionnel :
- Affichage correct des cartes
- Déplacements fluides du joueur
- Logique de poussée des caisses
- Détection des conditions de fin de jeu
- Gestion robuste des erreurs

### 🚀 Améliorations possibles

Bien que le projet soit fonctionnel, plusieurs améliorations peuvent être apportées :

#### Interface utilisateur
- [ ] Menu principal avec sélection de niveaux
- [ ] Affichage du nombre de mouvements
- [ ] Système de score
- [ ] Animation des déplacements
- [ ] Sons et effets visuels

#### Gameplay
- [ ] Fonction "undo" (annuler le dernier mouvement)
- [ ] Sauvegarde/chargement de parties
- [ ] Niveaux de difficulté progressive
- [ ] Éditeur de niveaux intégré
- [ ] Mode multijoueur

#### Technique
- [ ] Optimisation des performances
- [ ] Support de cartes de taille variable
- [ ] Amélioration de la gestion mémoire
- [ ] Tests unitaires
- [ ] Documentation du code

## Coding Style Epitech

⚠️ **Important** : Ce projet suit les normes de codage Epitech. Avant de contribuer ou de modifier le code, assurez-vous de :

1. Respecter la norme Epitech (indentation, nommage, etc.)
2. Vérifier le coding style avec l'outil officiel Epitech
3. Maintenir la cohérence du code existant
4. Documenter les nouvelles fonctions selon les standards Epitech

### Vérification du coding style

```bash
# Utilisez l'outil de vérification Epitech
coding-style . .
```

## Auteur

Projet développé dans le cadre du cursus Epitech.

## Licence

Ce projet est développé à des fins éducatives dans le cadre d'Epitech.

---

**Note** : Ce projet constitue une base solide pour un jeu Sokoban. Bien que toutes les fonctionnalités essentielles soient implémentées, il reste de nombreuses possibilités d'amélioration pour enrichir l'expérience de jeu.
