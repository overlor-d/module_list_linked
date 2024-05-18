# MiniProjet 1 - Listes, Piles, Files

## Description
Projet de programmation en C centré sur les listes chaînées, les piles et les files. Implémentation et manipulation de ces structures de données.

## Fonctionnalités
- Implémentation de listes chaînées, piles, et files en C.
- Bibliothèques statiques et dynamiques pour la gestion des structures.

## Commandes Makefile
- `make` : Compile les bibliothèques statiques et dynamiques.
- `make clean` : Nettoie le projet en supprimant les fichiers compilés.
- `make dist` : Crée une archive du projet.
- `make distclean` : Nettoie tout, y compris l'archive.
- `make compil_all` : Compile tout et prépare les tests.
- `make check` : Exécute tous les tests.
- `make list`, `make queue`, `make stack` : Exécute les tests pour les listes, files, et piles respectivement.

## Utilisation
Pour utiliser la bibliothèque du module, exécutez les commandes suivantes :

    ./configure
    make

Cela générera la bibliothèque libmylpf.a, que vous pourrez ensuite utiliser pour accéder aux fonctions de manipulation des listes chaînées, des piles et des files en C.
