# Programmation fine et complexité empirique : TP3

Teacher in charge : *Christophe Papazian* - [papazian@i3s.unice.fr](mailto:papazian@i3s.unice.fr)

## Useful links

## Groupe

* Alexis COUVREUR
* Ivan PICARD-MARCHETTO

## Compile

`gcc -o main main.cpp -lglut -lGLU -lGL -lm -lstdc++`

## Rebonds élastiques

Conservation de l'énergie cinétique (1/2)m2 + (1/2) Ico2
Avec I = L2 / 12 
On simplifie : V2 + (L2co2)/12
Ensuite inversion de la vitesse du point d'impact

Solution simple : co' = -1/2co - 3sig/2L
sig = Vy.cos alpha - Vx.sin alpha 
^nous donne la nouvelle vitesse angulaire