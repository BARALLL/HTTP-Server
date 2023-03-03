#include "api.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


static _Token* root;
static char* rulenames[] = { "inter", "term" };

void* getRootTree()
{
    return root;
}

void addToken(_Token** _tList, void* node) {
    _Token* newToken = (_Token*)malloc(sizeof(_Token));
    if (newToken)
    {
        newToken->next = NULL;
        newToken->node = node;

        if (*_tList == NULL)
            *_tList = newToken;
        else 
        {
            _Token* currToken = *_tList;
            while (currToken->next != NULL)
                currToken = currToken->next;

            currToken->next = newToken;
        }
    }
    else
        printf("Error S100: Memory not allocated\n");
}



void addSibling(_treeNode** _tSibList, _treeNode* parent, char* tag, int rulenameID, char* start, int length) 
{
    _treeNode* newSibling = (_treeNode*)malloc(sizeof(_treeNode));
    if (newSibling)
    {
        newSibling->tag = tag;
        newSibling->rulenameID = rulenameID;
        newSibling->start = start;
        newSibling->length = length;
        newSibling->parent = parent;
        newSibling->child = NULL;

        if (*_tSibList == NULL)
            *_tSibList = newSibling;
        else
        {
            _treeNode* currToken = *_tSibList;
            while (currToken->nextSib != NULL)
                currToken = currToken->nextSib;

            currToken->nextSib = newSibling;

        }
    }
    else
        printf("Error S100: Memory not allocated\n");
}


void removeSibling(_treeNode** _tSibList, _treeNode* node) 
{
    _treeNode* curr = *_tSibList;
    _treeNode* prev = NULL;
    while (curr->nextSib)
    {
        prev = curr;
        curr = curr->nextSib;
    }
    if (prev)
        prev->nextSib = NULL;
    free(curr);
}


void deleteNode(_Token** _tList, _treeNode** _tSibList, _treeNode* node)
{  
    _Token* curr = *_tList;
    _Token* prev = NULL;
    while (curr->next)          //del in the token list
    {
        prev = curr;
        curr = curr->next;
    }
    if(prev)
        prev->next = NULL;

    _treeNode* currNode = curr->node;
    purgeTree(currNode);            //del under recursively all child under this parent
    currNode->prevSib->nextSib = currNode->nextSib;
    free(currNode);
    free(curr);
}


_treeNode* searchSibling(_treeNode** _tSibList, char* typeofsearch, void* elemofsearch)
{
    int found = 0, count = 0;
    _treeNode* sibling = *_tSibList;
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
            if (count == sibling->length) found = 1;
            else count = 0;
        }
    }
    else return NULL;


    return found ? sibling : NULL;
}



/*
_Token* searchTree(void* start, char* name) {
    _Token* _tLFound = (_Token*)malloc(sizeof(_Token));
    _tLFound->node = NULL;
    _tLFound->next = NULL;

    _treeNode* startNode = NULL;
    if (start == NULL) startNode = (_treeNode*)root->node;
    else startNode = (_treeNode*)start;

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
    if (start == NULL) start = getRootTree();
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
    for (void* child = ((_treeNode*)node)->child; child != NULL; child = ((_treeNode*)child)->nextSib) {
        _searchRecursive(child, name, result);
    }
}



void* getFirstChild(void* node)
{
    _treeNode* first = (_treeNode*)node;
    return first->parent->child;
}



char* getElementTag(void* node, int* len)
{
    if (node == NULL)
        return NULL;

    char* str = rulenames[((_treeNode*)node)->rulenameID];
    *len = strlen(str);
    return str;
}


char* getElementValue(void* node, int* len) //pour get la rulename
{
    if (node == NULL)
        return NULL;

    _treeNode* _tNode = (_treeNode*)node;
    //char* str = copy_sub_str(_tNode->string, _tNode->start_string, _tNode->length_string);
    char* ptr = _tNode->start;
    char* str = (char*)malloc((_tNode->length)*sizeof(char));
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

    *len = _tNode->length;
    return str;
}


void purgeElement(_Token** root) {
    
    _Token* currToken = *root;

    while (currToken != NULL) 
    {
        _Token* tmp = currToken;
        currToken = currToken->next;
        free(tmp);
    }
    *root = NULL;
}


void purgeTree(void* root)      //supprime tout l'arbre genealogique en partant du parent root 
{
    //root = (_treeNode*)root;
    if (((_treeNode*)root)->child != NULL)
    {
        purgeTree(((_treeNode*)root)->child);
    }
    _treeNode* tmp = (_treeNode*)root;
    while (root != NULL)
    {
        tmp = root;
        root = ((_treeNode*)root)->nextSib;
        free(tmp);
    }
    root = NULL;
}


/*
    _Token* tmp = root;
    while (root != NULL)
    {
        tmp = root;
        root = ((_Token*)root)->next;
        free(tmp);
    }
    root = NULL;
*/


int parseur(char* req, int len)
{
    return 0;
}


void* showTree(void* start) {
    if (start == NULL) start = getRootTree();
    char* chain = malloc(100 * sizeof(char));
    char* ptr = chain;
    _showRecursive(start, 0);
}

// recursive tree show
void _showRecursive(void* node, int count)
{
    for (void* child = ((_treeNode*)node)->child; child != NULL; child = ((_treeNode*)child)->nextSib) {
        _showRecursive(child, count++);
        for (int i = 0; i < count; i++)
            printf("|    ");
        for(char* ptr = ((_treeNode*)node)->tag; ptr != '\0'; ptr++)
            printf("%c", *ptr);
        for (char* ptr = ((_treeNode*)node)->start; ptr != ((_treeNode*)node)->start + ((_treeNode*)node)->start[((_treeNode*)node)->length]; ptr++)
            printf("%c", *ptr);                              // <=> ptr != start + start[length]
        printf("\n");
    }
}