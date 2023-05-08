﻿<a name="br1"></a>BUT1 – SAE` S1.02

Comparaison d’approches algorithmiques

– Le quart de singe –

` `Le but du projet est de d´evelopper un logiciel permettant `a un ensemble de joueurs de disputer une partie de quart

1 R`egles du jeu

Les joueurs annoncent `a tour de rˆole une lettre qui vient compl´eter un mot. Un joueur donnant une lettre terminant

` `Admettons que, lors des tours pr´ec´edents d’une manche, les lettres ’A’, ’B’, ’A’ et ’C’ ont ´e t´e annonc´ees dans

Les mots retenus sont ceux accept´es au Scrabble, les accents sont ignor´es et les verbes peuvent ˆetre conjugu´es.

2 Cahier des charges

L’application que vous devez d´evelopper doit permettre a` au moins deux joueurs de jouer une partie dans sa totalit´e.

` `Dans les aﬃchages, les joueurs sont d´esign´es par leur num´ero d’ordre (1, 2, etc) et leur nature (H pour les humains

` `Vous disposez d’un dictionnaire de la langue fran¸caise. Il est compos´e de 369085 mots. Seuls les mots de plus de

` `Les robots jouent automatiquement. Les lettres jou´ees par ce type de joueurs ne sont pas saisies mais aﬃch´ees.

`

A la ﬁn de chaque manche, le nombre de quarts de singe de chaque joueur est aﬃch´e (”1H : 0.25; 2R : 0; 3H : 0.75; 4R : 0” par exemple). Si aucun joueur n’a rec¸u quatre quarts de singe, le joueur ayant perdu la derni`ere

Un extrait d’une trace d’ex´ecution est donn´e en annexe.

1




<a name="br2"></a>3 Qui, quoi et quand?

` `Votre projet doit ˆetre fait en binˆome. Les groupes de 3 ne seront pas accept´es. E´vitez de faire votre projet tout seul

` `Vous pouvez employer les structures de donn´ees vues en cours ou d´eveloppez les vˆotres. Par contre l’usage des

Vous devez porter une attention particuli`ere `a la r´edaction de votre dossier. Sa qualit´e est d´eterminante pour l’´evaluation de votre travail. Votre dossier doit ˆetre un unique document pdf dont la composition est la suivante :

• Une page de garde indiquant le nom et le groupe des membres du binˆome, l’objet du dossier.

• Une br`eve introduction du projet.

• Le graphe de d´ependance des ﬁchiers sources de vos applications. Tous les composants (qu’ils soient r´eutilis´es

• Le code source des tests unitaires que vous aurez ´ecrits (pr´ecisez quels tests passent et lesquels ´echouent).

` `Nous vous rappelons que le crit`ere principal de notation est la structuration de votre code. Votre rapport doit

Tous les ´el´ements (constantes, types et fonctions) d´eclar´es au sein d’un ﬁchier .h doivent ˆetre document´es.

` `Vous devez d´eposer une archive zip contenant votre rapport ainsi que l’ensemble des ﬁchiers sources de vos appli-

Annexe

1H, () > A

2R, (A) > B 3H, (AB) > A

4R, saisir le mot > ABACUS

le mot ABACUS existe, 1H prend un quart de singe

3H, (AB) > A

le mot ABACA existe, 1H prend un quart de singe

2R, (A) > B

3H, saisir le mot > ABACADABRA

le mot ABACADABRA n’existe pas, 3H prend un quart de singe

3H, () > ...

le mot XYZ n’existe pas, 3H prend un quart de singe

Figure 1: Exemple de session – en rouge, les donn´ees saisies par les joueurs humains, en bleu, les messages aﬃch´es par

2