#include "api.h"

#include "api.h"
#include <stdio.h> 



void addElement(_Token** head, void* node) {
    _Token* newToken = (_Token*)malloc(sizeof(_Token));
    newToken->node = node;
    newToken->next = NULL;

    if (*head == NULL)
        *head = newToken;
    else {
        _Token* currToken = *head;
        while (currToken->next != NULL)
            currToken = currToken->next;

        currToken->next = newToken;
    }
}

long removeElement(long* param_1)
{
    long lVar1;
    if (param_1 == (long*)0x0) {
        lVar1 = 0;
    }
    else {
        lVar1 = *param_1;
        if (lVar1 != 0) {
            *param_1 = *(long*)(lVar1 + 8);
            return lVar1;
        }
    }
    return lVar1;
}


_Token* searchTree(void* start, char* name) {
    _Token* list = (_Token*)malloc(sizeof(_Token));
    list->node = NULL;
    list->next = NULL;

    derivation_tree* start_node = NULL;
    if (start == NULL) start_node = root;
    else start_node = (derivation_tree*)start;

    if (strcmp(start_node->tag, name) == 0 && start_node->value_length != NOT_VALID) list->node = start_node;
    else recursif_search_tree(start_node, name, list);
    if (list->node == NULL && list->next == NULL)
    {
        free(list);
        //printf("Didn't Find any %s !\n", name);
        return NULL;
    }
    return list;
}


char* getElementTag(void* node, int* len)
{
    if (node == NULL)
        return NULL;

    char* str = tree_node_string[((tree_node*)node)->type];
    *len = strlen(str);
    return str;
}


char* getElementValue(void* node, int* len)
{
    if (node == NULL)
        return NULL;

    tree_node* tnode = (tree_node*)node;
    char* str = copy_sub_str(tnode->string, tnode->start_string, tnode->length_string);
    *len = strlen(str);
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


void purgeTree(void* root) 
{
    if (root == NULL) return;
    tree_node_free(root);
    root = NULL;
}