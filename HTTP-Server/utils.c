#include "utils.h"
#pragma warning(disable : 4996)


static _Token* queue = NULL;


void* getQueueTree()
{
    return &queue;
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
        insertNode(node, pere);
    }
    else
        printf("Error S100: Memory not allocated\n");
    return node;
}


void insertNode(noeud* node, noeud** pere)
{
    if (*pere)
    {
        node->pere = *pere;
        (*pere)->nombrefils++;
        (*pere)->fils = realloc((*pere)->fils, sizeof(noeud*) * (*pere)->nombrefils);

        if ((*pere)->fils)
            (*pere)->fils[(*pere)->nombrefils - 1] = node;
    }
    else
    {
        _Token** r = getRootTree();
        *r = calloc(1, sizeof(_Token*));
        if (*r)
            (*r)->node = node;
    }
    addToken(getRootTree(), node);
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
        {   //add token in queue; keep reference of the end of the linked list for performance purposes
            _Token** queue = getQueueTree();
            if (*queue != NULL)
            {
                (*queue)->next = newToken;
                *queue = (*queue)->next;
            }
            else
                *queue = newToken;
        }
    }
    else
        printf("Error S100: Memory not allocated\n");
}



// Recursive research in the tree
void _searchRecursive(void* node, char* name, _Token** result)
{
    int len;
    char* tag = getElementTag(node, &len);
    if (tag != NULL && len == (int)strlen(name) && strncmp(tag, name, len) == 0)
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
        while (ptr->next)
        {
            printNode(ptr->node);
            ptr = ptr->next;
        }
    }
    else
        showToken((*(_Token**)(getRootTree())));
}


void showTree(void* start)
{
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