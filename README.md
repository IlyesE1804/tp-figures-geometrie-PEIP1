# tp-figures-geometrie-PEIP1
Projet de groupe consistant à réaliser des figures géométriques à l'aide d'un turtle version c++

# TP - Figures Géométriques (C++)

Projet réalisé dans le cadre du TP d'informatique numérique de spécialité en PEIP 1 à Polytech Paris-Saclay.

## Structure

- `include/` : fichiers d'en-tête (.h/.hpp)
- `src/` : fichiers source (.cpp)
- `main.cpp` : programme principal
- `Makefile` : compilation
- `tests/` : fichiers de test

## Organisation

- Chef de projet : [Ilyes ECHAOUI]
  - Création du dépôt
  - Écriture des tests (et de certaines méthodes concerant les figures)
  - Suivi des contributions
- Collaborateurs :
  - Reda BOULARBAH : forme cercle
  - Berson BOUKONO : forme carré
  - la forme triangle a été travaillé un peu par tout le monde

## Commande pour cloner le dossier du dépôt GitHub

```bash
git clone https://github.com/IlyesE1804/tp-figures-geometrie-PEIP1
cd tp-figures-geometrie-PEIP1
```

## Pour modifier le dépot sur github (partir du dossier)

## Exemple : J'ai modifier les ficheirs cercle.h et cercle .hpp je fais :

```bash
git add .
git commit -m "Implémentation de la classe Cercle"
git push origin main
```

## Compilation

```bash
make
./main
