#include "api.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


_Token* root = NULL;
//static char* rulenames[] = { "rulename", "inter", };//"term" };

static _Token* queue = NULL;

static noeud* rootNoeud = NULL;



void* getRootTree()
{
    return &root;
}

void* getQueueTree()
{
    return &queue;
}

void* getRootNoeud()
{
    return &rootNoeud;
}


void* addNode(char* tag, char* value, int taille, noeud** pere)
{
    noeud* node = (noeud*)calloc(1, sizeof(noeud));
    if (node)
    {
        node->tag = tag;
        node->value = value;
        node->taille = taille;
        node->nombrefils = 0;
        //node->fils = calloc(0, sizeof(noeud*));
        if (*pere)
        {
            node->pere = *pere;
            (*pere)->nombrefils++;
            (*pere)->fils = realloc((*pere)->fils, sizeof(noeud*) * (*pere)->nombrefils);
            /*
            noeud** filspere = malloc(sizeof(noeud*));
            noeud** newfilspere = realloc(filspere, (*pere)->nombrefils);
            if (newfilspere == NULL) // reallocated pointer ptr1
            {
                printf("Error S100: Problem during the realloc for adding a child\n");
                free(filspere);
            }
            else
                filspere = newfilspere;           // the reallocation succeeded, we can overwrite our original pointer now
            */
            if((*pere)->fils)
                (*pere)->fils[(*pere)->nombrefils - 1] = node;
        }
        else
        {
            _Token** r = getRootTree();
            *r = calloc(1, sizeof(_Token*));
            if(*r)
                (*r)->node = node;
        }
    }
    else
        printf("Error S100: Memory not allocated\n");
    addToken(getRootTree(), node);
    return node;
}



void addToken(_Token** _tList, void* node) {
    _Token* newToken = (_Token*)calloc(1, sizeof(_Token));
    if (newToken)
    {
        newToken->next = NULL;
        newToken->node = node;

        if (*_tList == NULL)
            *_tList = newToken;
        else
        {
            /*_Token* currToken = *_tList;
            
            while (currToken->next != NULL)
                currToken = currToken->next;
                */
            
            _Token** queue = getQueueTree();
            if (*queue != NULL)
            {
                //printf("%p %p %p\n", queue, (*queue), (*queue)->next);
                (*queue)->next = newToken;
                *queue = (*queue)->next;
            }
            else
                *queue = newToken;

            //showToken(*_tList);
        }
    }
    else
        printf("Error S100: Memory not allocated\n");
}



/*
void addSibling(noeud* _tSibList, noeud* node)
{
    addToken(root, node);

    if (_tSibList == NULL)
    {
        _tSibList = node;
        node->pere->fils = node; //says to pere 'hey i'm your child'
    }
    else
    {
        noeud* currToken = _tSibList;
        while (currToken->nextSib != NULL)
            currToken = currToken->nextSib;

        currToken->nextSib = node;

    }
}
*/

/*
void removeSibling(noeud** _tSibList, noeud* node)
{
    noeud* curr = *_tSibList;
    noeud* prev = NULL;
    while (curr->nextSib)
    {
        prev = curr;
        curr = curr->nextSib;
    }
    if (prev)
        prev->nextSib = NULL;
    free(curr);
}
*/

/*
void deleteNode(_Token** _tList, noeud* node)
{
    _Token* curr = *_tList;
    _Token* prev = NULL;

    if (curr != NULL && curr->node == node)
    {
        *_tList = curr->next;
        free(curr);
        return;
    }
    else
    {
        while (curr != NULL && curr->node != node) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            printf("Error S102: Node not found in Token list\n");
        }
        else
        {
            prev->next = curr->next;

            prev->next = curr->next;
            node->prevSib->nextSib = node->nextSib;
            purgeTree(node);            //del under recursively all child under this pere
            //free(node);                //del node and del in token list
            free(curr);
        }
    }
}
*/

/*
noeud* searchSibling(noeud** _tSibList, char* typeofsearch, void* elemofsearch)
{
    int found = 0, count = 0;
    noeud* sibling = *_tSibList;
    if (strcmp(typeofsearch, "tag") == 0)
    {
        while (sibling->nextSib != NULL && !found)
        {
            sibling = sibling->nextSib;
            if (sibling->tag == (char*)elemofsearch) found = 1;
        }
    }
    else if (strcmp(typeofsearch, "rulenameID") == 0)
    {
        while (sibling->nextSib != NULL && !found)
        {
            sibling = sibling->nextSib;
            if (sibling->rulenameID == (int)elemofsearch) found = 1;
        }
    }
    else if (strcmp(typeofsearch, "content") == 0)
    {
        while (sibling->nextSib != NULL && !found)
        {
            sibling = sibling->nextSib;
            int i = 0;
            char* ptr = sibling->start;
            char* ptrElem = (char*)elemofsearch;

            while (*(ptr) == *ptrElem)
            {
                ptr++;
                ptrElem++;
                count++;
            }
            if (count == sibling->taille) found = 1;
            else count = 0;
        }
    }
    else return NULL;


    return found ? sibling : NULL;
}
*/


/*
_Token* searchTree(void* start, char* name) {
    _Token* _tLFound = (_Token*)malloc(sizeof(_Token));
    _tLFound->node = NULL;
    _tLFound->next = NULL;

    noeud* startNode = NULL;
    if (start == NULL) startNode = (noeud*)root->node;
    else startNode = (noeud*)start;

    if (strcmp(startNode->tag, name) == 0)
        _tLFound->node = startNode;
    //else recursiveSearch(startNode, name, _tLFound);       // TODO

    if (_tLFound->node == NULL && _tLFound->next == NULL)
    {
        free(_tLFound);
        //printf("Error S110: No node containing %s found\n", name);
        return NULL;
    }
    return _tLFound;
}
*/


_Token* searchTree(void* start, char* name) {
    _Token* result = NULL;
    if (start == NULL) start = (*(_Token**)(getRootTree()))->node;
    _searchRecursive(start, name, &result);
    return result;
}

// Recherche récursive dans l'arbre
void _searchRecursive(void* node, char* name, _Token** result)
{
    int len;
    char* tag = getElementTag(node, &len);
    if (tag != NULL && len == strlen(name) && strncmp(tag, name, len) == 0)
    {
        _Token* token = (_Token*)malloc(sizeof(_Token));
        if (token)
        {
            token->node = node;
            token->next = *result;
            *result = token;
        }
    }

    for (int i = 0; i < ((noeud*)node)->nombrefils; i++)
        _searchRecursive(((noeud*)node)->fils[i], name, result);

    /*
    for (void* child = ((noeud*)node)->child; child != NULL; child = ((noeud*)child)->nextSib) {
        _searchRecursive(child, name, result);
    }
    */
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

/*
char* getElementValue(void* node, int* len) //pour get la rulename
{
    if (node == NULL)
        return NULL;

    noeud* _tNode = (noeud*)node;
    //char* str = copy_sub_str(_tNode->string, _tNode->start_string, _tNode->taille_string);
    char* ptr = _tNode->start;
    char* str = (char*)malloc((_tNode->taille) * sizeof(char));
    char* pstr = str;
    if (str)
    {
        while (*ptr)
        {
            *pstr = *ptr;
            ptr++;
            pstr++;
        }
        *pstr = '\0';
    }

    *len = _tNode->taille;
    return str;
}
*/


void purgeElement(_Token** r) //supprime toute la liste chainée de _Token
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
    /*
    //root = (noeud*)root;
    if (((noeud*)start)->nombrefils != 0)
    {
        purgeTree(*(((noeud*)start)->fils));
    }

    int i = 0;
    while (i != ((noeud*)start)->nombrefils)
    {
        //free(tmp);
        i++;
    }
    start = NULL;
    */

    short found = 0;
    noeud* currentNode = ((noeud*)current);
    noeud* pere = currentNode->pere;
    
    if (currentNode == NULL) return;
    while (currentNode->nombrefils > 0)
        purgeTree(currentNode->fils[0]);

    if (currentNode->pere && currentNode->pere->nombrefils > 0) {
        
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
    if (pere)
    {
        int i = 0;
        for (int i = 0; i < pere->nombrefils && !found; i++)
        {
            if (pere->fils[i] == currentNode)
                found = 1;
        }
        if (found)
        {
            pere->nombrefils--;
            for (int j = i; j < pere->nombrefils; j++)
                pere->fils[j] = pere->fils[j + 1];
            pere->fils = realloc(pere->fils, sizeof(noeud*) * pere->nombrefils);
        }
        else
            printf("Error S105: The node is not in his parent's child list, yet all child will be removed\n");
    }
    else
    {
        //_Token** r = getRootTree();
        //if (start == NULL) start = (*r)->node;
        printf("Error S105: No parent have been found for this node, yet all child will be removed\nDefault option: root set to NULL, can be modified later\n");
    }
        

    _purgeRecursive(current);
}
    */


void _purgeRecursive(void* current)
{
    noeud* currentNode = ((noeud*)current);
    for (int i = 0; i < currentNode->nombrefils; i++)
    {
        if (currentNode->fils[i] != NULL)
            _purgeRecursive(currentNode->fils[i]);
    }
    free(currentNode->fils);
    free(currentNode);
    currentNode = NULL;
}


void printNode(void* node)
{
    if(node)
        printf("%s\n", ((noeud*)node)->tag);
    else
        printf("Error S105: NULL node\n");
    /*
    char* ptr = ((noeud*)node)->tag;
    if (ptr != NULL)
    {
        for (; *ptr != '\0' && ptr != NULL; ptr++)
            printf("%c", *ptr);
    }
    else printf("null");

    printf(" - ");
    printf("%s", rulenames[((noeud*)node)->rulenameID]);
    printf(" - ");
    if ((ptr = ((noeud*)node)->start) != NULL)
    {
        for (; ptr != &((noeud*)node)->start[((noeud*)node)->taille]; ptr++)
            printf("%c", *ptr);                              // <=> ptr != start[taille]
    }
    else printf("null");
    printf("\n");
    */
}

void showToken(_Token* start)
{
    if (start)
    {
        printf("\n\n");
        _Token* ptr = start;
        while (ptr->next)
        {
            printNode(ptr->node);
            //printf("%p", ptr);
            ptr = ptr->next;
        }
    }
    else
        showToken((*(_Token**)(getRootTree())));
}

void showTree(void* start) {
    if (start == NULL) start = (*(_Token**)(getRootTree()))->node;
    printf("\n\n");
    printNode(start);
    _showRecursive(start, 1);
}

// recursive tree show
void _showRecursive(void* node, int count)
{
    if (node)
    {
        noeud* currentNode = ((noeud*)node);
        if (currentNode->nombrefils > 0)
        {
            for (int i = 0; i < currentNode->nombrefils; i++)
            {
                for (int j = 0; j < count; j++)
                    printf("|    ");
                printNode(currentNode->fils[i]);
                _showRecursive(currentNode->fils[i], count + 1);
            }
        }
    }
}

int parseur(char* req, int len)
{
    noeud* racine = malloc(sizeof(noeud));
    parseur(req, len, racine);
}