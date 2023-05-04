#pragma once
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


typedef struct _token {
	void* node;  		// node type opaque pointant vers un noeud de votre structure de données. 
	struct _token* next; 	// next pointe vers le prochain token.
} _Token;


typedef struct noeud {
	struct noeud* pere;
	char* tag;
	char* value;
	int taille;
	int nombrefils;
	struct noeud** fils;
} noeud;

_Token* globalroot;