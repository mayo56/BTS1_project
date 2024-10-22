# Convertisseur de base

> Énoncé :
>
> Faire un convertisseur entre les bases. Demande à l'utilisateur
> une base de départ puis si son nombre est signé ou non signé.
>
> Affiche ce même nombre convertit dans les autres bases.

----
Convertit un nombre donné dans les deux autres bases (2, 10 ou 16).

### Issues - problèmes
Ne vérifie pas le nombre entré. S'il est invalide, le code
s'exécute quand même.

Ça ne pose pas trop de problème pour les nombres
non signés qui sont négatif. Mais pour les différences
de base ça génère une erreur.

#### Tentative: Vérifier les données:
J'ai fait des switch case et des vérifications caractères par
caractères.
#### Problème rencontré:
Lorsqu'il y a une erreur de saisie, les suivantes (même si
elles sont correctes) sont marqués comme invalide.
----
# Compatibilité
- Code testé sous l'environnement MacOS.
- Il devrait fonctionner sous l'environnement Linux. (car MacOS a un noyaux Unix)
- Aucuns test fait sur Windows.