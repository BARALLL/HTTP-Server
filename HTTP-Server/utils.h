#pragma once

#ifndef API_H
#define API_H
#include "api.h"
#endif

#ifndef GLOBAL_H
#define GLOBAL_H
#include "global.h"
#endif

//get queue pointer of _Token linked list
void* getQueueTree();

//create and add node to _Token list and to the tree given the parent and the node datas
void* addNode(char* tag, char* value, int taille, noeud** pere);

//add token to list of _Token
void addToken(_Token** _tList, void* node);

// recursive research in tree, util function for searchTree
void _searchRecursive(void* node, char* name, _Token** result);

// recursive purge in tree, util function for purgeTree
void _purgeRecursive(void* current);

//util function to print a node
void printNode(void* node);

//show _Token linked list (linked list of nodes)
void showToken(_Token* start);

//show the tree from start node
void showTree(void* start);

// recursive show of node in tree, util function for showTree
void _showRecursive(void* node, int count);