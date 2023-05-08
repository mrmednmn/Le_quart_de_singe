<a name="br1"></a>BUT1 – SAE` S1.02

Comparaison d’approches algorithmiques

– Le quart de singe
–
I use oop and diffrent c++ standard containers for this solution.

- COMPLIE WITH G++ :
_
1. cd build
2. g++ -c ../main.cpp ../qgame_src/*.cpp 
3. g++ *.o -o qgame



- Run:

. qgame H R H R



-PROJECT:



`Le but du projet est de d´evelopper un logiciel permettant `a un ensemble de joueurs de disputer une partie de quart
de singe. L’application doit veiller au respect des r`egles du jeu et g´erer la totalit´e du d´eroulement de la partie jusqu’`a
l’annonce du perdant.

1 R`egles du jeu

Les joueurs annoncent `a tour de rˆole une lettre qui vient compl´eter un mot. Un joueur donnant une lettre terminant
un mot existant (de plus de deux lettres) perd la manche et est gratiﬁ´e d’un quart de singe. Le joueur courant devant
annoncer une lettre peut pr´ef´erer demander au joueur pr´ec´edant `a quel mot il pense. Si ce dernier est incapable de
donner un mot existant et qui soit coh´erent avec les lettres d´ej`a annonc´ees, il perd la manche. Dans le cas contraire,
c’est le joueur qui a pos´e la question qui perd la manche. Le premier joueur ayant r´ecolt´e quatre quarts de singe perd
la partie.

` `Admettons que, lors des tours pr´ec´edents d’une manche, les lettres ’A’, ’B’, ’A’ et ’C’ ont ´e t´e annonc´ees dans
cet ordre. Si le joueur courant annonce ’A’, il perd la manche car le mot ”ABACA” est un mot existant (c’est une
mati`ere textile). Si par contre, il joue ’U’ et que le joueur suivant lui demande `a quel mot il pense, il pourra r´epondre
”ABACULE” (c’est un petit ´el´ement cubique d’une mosa¨ıque) et ce joueur ´ecopera d’un quart de singe.

Les mots retenus sont ceux accept´es au Scrabble, les accents sont ignor´es et les verbes peuvent ˆetre conjugu´es.

2 Cahier des charges

L’application que vous devez d´evelopper doit permettre a` au moins deux joueurs de jouer une partie dans sa totalit´e.
Pour qu’un joueur seul puisse s’exercer, votre application doit impl´ementer des joueurs robots qui joueront automa-
tiquement. Le nombre de joueurs, leur nature (humain ou robot) et l’ordre dans lequel les joueurs prendront leur tour
sont sp´eciﬁ´es par une chaˆıne de caract`ere pass´ee sur la ligne de commande. Par exemple, si votre ﬁchier ex´ecutable
est nomm´e singe.exe, alors la commande singe HRHR lance une partie ou` 4 joueurs s’aﬀrontent. Le premier et le
 troisi`eme sont des humains alors que le deuxi`eme et le quatri`eme sont des robots.

` `Dans les aﬃchages, les joueurs sont d´esign´es par leur num´ero d’ordre (1, 2, etc) et leur nature (H pour les humains
et R pour les robots). A chaque tour de jeu, le num´ero du joueur courant, sa nature ainsi que les lettres d´ej`a annonc´ees
sont aﬃch´es (”1H (ABAC) > ” par exemple). Le joueur saisit soit une lettre de l’alphabet (non accentu´ee et en
majuscule ou en minuscule) s’il veut compl´eter la chaˆıne de lettre, soit le caract`ere ’?’ s’il veut demander au joueur
pr´ec´edent `a quel mot qu’il pense, soit le caract`ere ’ !’ s’il veut abandonner la manche (et prendre un quart de singe).
 Si la lettre jou´ee vient ﬁnir un mot existant du dictionnaire, votre application aﬃche ”le mot XXX existe, le
joueur X prend un quart de singe” (ou` XXX est remplac´e par le mot ainsi form´e et X par le num´ero du joueur
courant). Si le caract`ere ’?’ a ´e t´e saisi, le joueur pr´ec´edent est invit´e a` saisir le mot auquel il pense. Si les premi`eres
 lettres de ce mot ne correspondent pas `a celles d´ej`a jou´ees, votre application aﬃche ”le mot XXX ne commence pas
par les lettres attendues, le joueur X prend un quart de singe” (ou` XXX est remplac´e par le mot saisi).
Si le mot saisi n’appartient pas au dictionnaire, votre application aﬃche ”le mot XXX n’existe pas, le joueur
X prend un quart de singe”. Dans le cas contraire, votre application aﬃche ”le mot XXX existe, le joueur
X prend un quart de singe”. Dans le cas o u` le caract`ere ’!’ est saisi, votre application aﬃche "le joueur X
abandonne la manche et prend un quart de singe".

` `Vous disposez d’un dictionnaire de la langue fran¸caise. Il est compos´e de 369085 mots. Seuls les mots de plus de
deux lettres participent au jeu. Votre application devra faire l’hypoth`ese que le ﬁchier texte correspondant se trouve
dans le r´epertoire courant o u` est lanc´e l’application (surtout ne pas mettre de chemin absolu pour d´esigner le ﬁchier).

` `Les robots jouent automatiquement. Les lettres jou´ees par ce type de joueurs ne sont pas saisies mais aﬃch´ees.
Bien entendu, ils ont acc`es au dictionnaire et vous devez les programmer de sorte qu’ils jouent le mieux possible.

`

A la ﬁn de chaque manche, le nombre de quarts de singe de chaque joueur est aﬃch´e (”1H : 0.25; 2R : 0; 3H : 0.75; 4R : 0” par exemple). Si aucun joueur n’a rec¸u quatre quarts de singe, le joueur ayant perdu la derni`ere
manche d´ebute la suivante. Dans le cas contraire, l’application aﬃche ”La partie est finie”.

Un extrait d’une trace d’ex´ecution est donn´e en annexe.

1




<a name="br2"></a>3 Qui, quoi et quand?

` `Votre projet doit ˆetre fait en binˆome. Les groupes de 3 ne seront pas accept´es. E´vitez de faire votre projet tout seul
(soit vous ˆetes tr`es fort et des personnes ont besoin de votre aide, soit vous avez des diﬃcult´es et il faut vous faire
aider).

` `Vous pouvez employer les structures de donn´ees vues en cours ou d´eveloppez les vˆotres. Par contre l’usage des
chaˆınes de caract`ere du C++ (le type string) ainsi que les conteneurs de la biblioth`eque standard (vector, list,
map, stack, etc) est strictement interdit. En cas de doute, contactez moi.

Vous devez porter une attention particuli`ere `a la r´edaction de votre dossier. Sa qualit´e est d´eterminante pour l’´evaluation de votre travail. Votre dossier doit ˆetre un unique document pdf dont la composition est la suivante :

• Une page de garde indiquant le nom et le groupe des membres du binˆome, l’objet du dossier.
 • Une table des mati`eres de l’ensemble du dossier.

• Une br`eve introduction du projet.

• Le graphe de d´ependance des ﬁchiers sources de vos applications. Tous les composants (qu’ils soient r´eutilis´es
 ou d´evelopp´es) de vos applications devront ﬁgurer sur le graphe (cf. Cours 4).

• Le code source des tests unitaires que vous aurez ´ecrits (pr´ecisez quels tests passent et lesquels ´echouent).
• Un bilan du projet (les diﬃcult´es rencontr´ees, ce qui est r´eussi, ce qui peut ˆetre am´elior´e).
• En annexe, le code complet de vos sources (triez les ﬁchiers selon un ordre logique).

` `Nous vous rappelons que le crit`ere principal de notation est la structuration de votre code. Votre rapport doit
mettre en avant la qualit´e de celle-ci.

Tous les ´el´ements (constantes, types et fonctions) d´eclar´es au sein d’un ﬁchier .h doivent ˆetre document´es.

` `Vous devez d´eposer une archive zip contenant votre rapport ainsi que l’ensemble des ﬁchiers sources de vos appli-
cations, le mardi 3 janvier 2023.

Annexe

1H, () > A

2R, (A) > B 3H, (AB) > A
4R, (ABA) > C
1H, (ABAC) > ?

4R, saisir le mot > ABACUS

le mot ABACUS existe, 1H prend un quart de singe
1H : 0.25; 2R : 0; 3H : 0; 4R : 0
1H, () > A 2R, (A) > B

3H, (AB) > A
4R, (ABA) > C
1H, (ABAC) > A

le mot ABACA existe, 1H prend un quart de singe
1H : 0.5; 2R : 0; 3H : 0; 4R : 0
1H, () > A

2R, (A) > B
3H, (AB) > A
4R, (ABA) > ?

3H, saisir le mot > ABACADABRA

le mot ABACADABRA n’existe pas, 3H prend un quart de singe
1H : 0.5; 2R : 0; 3H : 0.25; 4R : 0

3H, () > ...
...

le mot XYZ n’existe pas, 3H prend un quart de singe
1H : 0.5; 2R : 0; 3H : 1; 4R : 0
La partie est finie

Figure 1: Exemple de session – en rouge, les donn´ees saisies par les joueurs humains, en bleu, les messages aﬃch´es par
le programme.

2
