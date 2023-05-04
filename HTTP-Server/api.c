#include "api.h"
#include "utils.h"
#pragma warning(disable : 4996)



void* getRootTree()
{
    return globalroot;
}



_Token* searchTree(void* start, char* name) {
    _Token* result = NULL;
    if (start == getRootTree()) start = (noeud*)globalroot->node;
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
    noeud* currentNode = (noeud*)(((_Token*)current)->node);
    if (currentNode == NULL) return;


    noeud* pere = currentNode->pere;
    while (currentNode->nombrefils > 0)
        purgeTree(currentNode->fils[0]);

    if (pere && pere->nombrefils > 0) {

        int indexFoundAt = 0;
        for (int ii = 0; ii < pere->nombrefils && !found; ii++)
        {
            if (pere->fils[ii] == currentNode)
            {
                found = 1;
                indexFoundAt = ii;
            }
        }

        free(pere->fils[indexFoundAt]);

        for (int j = indexFoundAt; j < pere->nombrefils - 1; j++)
            pere->fils[j] = pere->fils[j + 1];

        pere->nombrefils--;
        if (pere->nombrefils == 0)
        {
            free(pere->fils);
            pere->fils = NULL;
        }
        else
        {
            pere->fils = realloc(pere->fils, sizeof(noeud) * pere->nombrefils);
            if (!pere->fils) { printf("Error S101 in realloc, abording"); exit(EXIT_FAILURE); }
        }
            
    }
    else
    {
        if (currentNode == globalroot->node)
            globalroot->node = NULL;

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
