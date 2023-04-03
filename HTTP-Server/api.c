#include "api.h"
#pragma warning(disable : 4996)



void* getRootTree()
{
    return &root;
}



_Token* searchTree(void* start, char* name) {
    _Token* result = NULL;
    if (start == NULL) start = (*(_Token**)(getRootTree()))->node;
    _searchRecursive(start, name, &result);
    showToken(result);
    return result;
}



char* getElementTag(void* node, int* len)
{
    if (node == NULL)
        return NULL;

    noeud* n = ((noeud*)node);

    char* str = (char*)malloc(strlen(n->tag));
    if (str) 
    {
        strcpy(str, n->tag);
        *len = strlen(str);
    }
    return str;
}


char* getElementValue(void* node, int* len)
{
    if (node == NULL)
        return NULL;

    char* str = (char*)malloc(((noeud*)node)->taille);
    if(str)
        strcpy(str, ((noeud*)node)->value);
    *len = ((noeud*)node)->taille;
    return str;
}



void purgeElement(_Token** r) //supprime toute la liste chain�e de _Token
{
    _Token* currToken = *r;

    while (currToken != NULL)
    {
        _Token* tmp = currToken;
        currToken = currToken->next;
        free(tmp);
    }
    *r = NULL;
}



void purgeTree(void* current)      //supprime tout l'arbre genealogique en partant du current 
{
    short found = 0;
    noeud* currentNode = ((noeud*)current);
    if (currentNode == NULL) return;

    
    noeud* pere = currentNode->pere;
    while (currentNode->nombrefils > 0)
        purgeTree(currentNode->fils[0]);

    if (pere && pere->nombrefils > 0) {
        
        noeud* pere = currentNode->pere;

        int i = 0;
        for (int ii = 0; i < pere->nombrefils && !found; ii++)
        {
            if (pere->fils[ii] == currentNode) 
            {
                found = 1;
                i = ii;
            }
        }

        free(pere->fils[i]);

        for (int j = i; j < pere->nombrefils - 1; j++)
            pere->fils[j] = pere->fils[j + 1];

        pere->nombrefils--;
        if (pere->nombrefils == 0) 
        {
            free(pere->fils);
            pere->fils = NULL;
        }
        else
            pere->fils = realloc(pere->fils, sizeof(noeud) * pere->nombrefils);
    }
    else 
    {
        if (currentNode == (*(_Token**)(getRootTree()))->node)
            (*(_Token**)(getRootTree()))->node = NULL;

        free(currentNode);
    }
}


/*
int parseur(char* req, int len)
{
    noeud* racine = malloc(sizeof(noeud));
    return parseur(req, len, racine);
}
*/