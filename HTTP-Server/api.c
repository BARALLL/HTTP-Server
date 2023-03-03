#include "api.h"
#include <stdio.h> 
#include <string.h>

static _Token* root;
static char* rulename[] = { "inter", "term" };

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

void addSibling(_treeNode** _tSibList, long tag, int rulenameID, char* start, char* length) {
    _treeNode* newSibling = (_treeNode*)malloc(sizeof(_treeNode));
    if (newSibling)
    {
        newSibling->tag = tag;
        newSibling->rulenameID = rulenameID;
        newSibling->start = start;
        newSibling->length = length;

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
    _treeNode* curr = _tSibList;
    _treeNode* prev = NULL;
    while (curr->nextSib)
    {
        prev = curr;
        curr = curr->nextSib;
    }
    prev->nextSib = NULL;
    free(curr);
}


void deleteNode(_Token** _tList, _treeNode** _tSibList, _treeNode* node)
{  
    _Token* curr = _tList;
    _Token* prev = NULL;
    while (curr->next)          //del in the token list
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    _treeNode* currNode = curr->node;
    purgeTree(currNode);            //del under recursively all child under this parent
    //removeSibling((currNode->parent)->child, currNode);
    currNode->prevSib->nextSib = currNode->nextSib;

    free(curr);
}


_treeNode* searchSibling(_treeNode** _tSibList, char* typeofsearch, void* elemofsearch)
{
    int found = 0;
    _treeNode* sibling = _tSibList;
    if (strcmp(typeofsearch, "tag") == 0)
    {
        while (sibling->nextSib != NULL && !found)
        {
            sibling = sibling->nextSib;
            if (sibling->tag == elemofsearch) found = 1;
        }
    }
    else if (strcmp(typeofsearch, "rulenameID") == 0)
    {
        while (sibling->nextSib != NULL && !found)
        {
            sibling = sibling->nextSib;
            if (sibling->rulenameID == elemofsearch) found = 1;
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
            }
            if (*ptr == sibling->length) found = 1;
        }
    }
    else return NULL;


    return found ? sibling : NULL;
}




_Token* searchTree(void* start, char* name) {
    _Token* _tLFound = (_Token*)malloc(sizeof(_Token));
    _tLFound->node = NULL;
    _tLFound->next = NULL;

    _treeNode* startNode = NULL;
    if (start == NULL) startNode = root;
    else startNode = (_treeNode*)start;

    if (strcmp(startNode->tag, name) == 0) 
        _tLFound->node = startNode;
    else recursiveSearch(startNode, name, _tLFound);       // TODO

    if (_tLFound->node == NULL && _tLFound->next == NULL)
    {
        free(_tLFound);
        //printf("Error S110: No node containing %s found\n", name);
        return NULL;
    }
    return _tLFound;
}


void recursiveSearch(void* startNode, char* name, _Token* _tLFound) 
{

}



char* getElementTag(void* node, int* len)
{
    if (node == NULL)
        return NULL;

    char* str = rulename[((_treeNode*)node)->rulenameID];
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
    char* str = calloc(_tNode->length, sizeof(char));
    char* pstr = *str;
    while (*ptr)
    {
        *pstr = *ptr;
        ptr++;
        pstr++;
    }
    *pstr = '\0';

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

}