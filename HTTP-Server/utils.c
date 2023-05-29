#include "utils.h"
#include "string.h"

static _Token* queue = NULL;


void* getQueueTree()
{
    return queue;
}


void init()
{
    _Token* r = calloc(1, sizeof(_Token));
    if (r)
    {
        noeud* nodeR = calloc(1, sizeof(noeud));
        if (nodeR)
        {
            nodeR->pere = NULL;
            nodeR->tag = calloc(1, sizeof(char));
            nodeR->value = calloc(1, sizeof(char));
            nodeR->taille = 0;
            nodeR->nombrefils = 0;
            nodeR->fils = calloc(0, sizeof(noeud));
            r->node = nodeR;      //no field needs to be initialized as calloc already do it
        }
        globalroot = r;
        globalroot->node = nodeR;
    }
}


void* addNode(char* tag, char* value, int taille, noeud* pere)
{
    if (pere == NULL)
        pere = (noeud*)(globalroot->node);
    noeud* node = (noeud*)calloc(1, sizeof(noeud));
    if (node)
    {
        node->tag = tag;
        node->value = value;
        node->taille = taille;
        node->nombrefils = 0;
        //node->fils = calloc(0, sizeof(noeud*));
        insertNode(node, pere);
    }
    else
        printf("Error S100: Memory not allocated\n");
    return node;
}


void insertNode(noeud* node, noeud* pere)
{
    if (!node) return;
    if (pere == NULL)
        pere = (noeud*)(globalroot->node);
    if (pere)
    {
        node->pere = pere;
        pere->nombrefils++;
        pere->fils = realloc(pere->fils, sizeof(noeud*) * pere->nombrefils);
        if (!pere->fils) { printf("Error S101 in realloc, abording"); exit(EXIT_FAILURE); }

        if (pere->fils)
            pere->fils[pere->nombrefils - 1] = node;
    }
    else
    {
        _Token* r = getRootTree();
        r = calloc(1, sizeof(_Token*));
        if (r)
        {
            noeud* nodeR = (noeud*)calloc(1, sizeof(noeud));
            if (nodeR)
            {
                nodeR->tag = NULL;
                nodeR->value = NULL;
                nodeR->taille = 0;
                nodeR->nombrefils = 1;
                nodeR->fils = calloc(1, sizeof(noeud*));
                if (nodeR->fils) { node->pere = nodeR; nodeR->fils[0] = node; }
                (r)->node = nodeR;
            }
        }
    }

    addToken(getRootTree(), node);
}

//marche pas pour le moment et fonction surement pas utile
/*
void changeParent(noeud** current, noeud** newParent)
{

    short found = 0;
    noeud* pere = (*current)->pere;


    int indexFoundAt = 0;
    for (int ii = 0; ii < pere->nombrefils && !found; ii++)
    {
        if (pere->fils[ii] == (*current))
        {
            found = 1;
            indexFoundAt = ii;
        }
    }

    for (int j = indexFoundAt; j < pere->nombrefils - 1; j++)
        pere->fils[j] = pere->fils[j + 1];

    (*current)->pere->nombrefils--;
    (*current)->pere->fils = realloc((*newParent)->fils, sizeof(noeud*) * (*newParent)->nombrefils);
    if (!(*current)->pere->fils) { printf("Error S101 in realloc, abording"); exit(EXIT_FAILURE); }
    (*current)->pere = *newParent;

    (*newParent)->nombrefils++;
    (*newParent)->fils = realloc((*newParent)->fils, sizeof(noeud*) * (*newParent)->nombrefils);
    if (!(*newParent)->fils) { printf("Error S101 in realloc, abording"); exit(EXIT_FAILURE); }
}
*/

void addToken(_Token* _tList, void* node) {
    _Token* newToken = (_Token*)calloc(1, sizeof(_Token));
    if (newToken)
    {
        newToken->next = NULL;
        newToken->node = node;

        if (_tList == NULL)
            _tList = newToken;
        else
        {   //add token in queue; keep reference of the end of the linked list for performance purposes
            _Token* queue = _tList;
            for (; queue->next != NULL; queue->next) { ; }
            if (queue != NULL)
            {
                queue->next = newToken;
                queue = queue->next;
            }
            else
                queue = newToken;
        }
    }
    else
        printf("Error S100: Memory not allocated\n");
}


void removeToken(_Token* _tList, _Token* token) {
    _Token* current = _tList;
    _Token* prev = NULL;

    while (current != NULL && current != token) {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    if (prev == NULL)
        _tList = current->next;
    else
        prev->next = current->next;

    free(current);
}


// Recursive research in the tree
void _searchRecursive(void* node, char* name, _Token** result)
{
  if(node && name && result)
  {
    int len;
    char* tag = getElementTag(node, &len);
    if (tag != NULL && len-4 == (int)strlen(name) && strncmp(tag+3, name, len-4) == 0)
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
  }
}



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
    if (node)
        printf("%s\n", ((noeud*)node)->tag);
    else
        printf("Error S105: NULL node\n");
}


void showToken(_Token* start)
{
    if (start)
    {
        printf("\n\n");
        _Token* ptr = start;
        printNode(ptr->node);
        while (ptr->next)
        {
            printNode(ptr->node);
            ptr = ptr->next;
        }
    }
    else
        showToken((_Token*)(getRootTree()));
}


void showTree(void* start)
{
    int count = 0;
    printf("\n\n");
    if (start == NULL || (((_Token*)start) == globalroot)) start = (noeud*)(globalroot->node);
    else {
        start = (noeud*)(((_Token*)start)->node);
        printNode(start);
        count++;
    }
    _showRecursive(start, count);
}

// recursive tree show
void _showRecursive(void* node, int count)
{
    if (node)
    {
        noeud* currentNode = ((noeud*)node);
        for (int i = 0; i < currentNode->nombrefils; i++)
        {
            for (int j = 0; j < count; j++)
                printf("|    ");
            printNode(currentNode->fils[i]);
            _showRecursive(currentNode->fils[i], count + 1);
        }
    }
}
