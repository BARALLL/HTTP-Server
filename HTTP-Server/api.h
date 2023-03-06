// defini un type pour la liste chainee renvoyée en réponse de la requete de recherche dans l'arbre. 

typedef struct _token {
		void *node;  		// node type opaque pointant vers un noeud de votre structure de données. 
		struct _token *next; 	// next pointe vers le prochain token.
		} _Token;



//char* tag;
//int rulenameID;	//might not be useful
//char* start;		//value of rulename
//int length;		//length of char* start
//struct treeNode* parent, prevSib, nextSib, child;
typedef struct treeNode
{
	char* tag;
	int rulenameID;
	char* start;
	int length;		//length of char* start
	struct treeNode* parent;
	struct treeNode* prevSib;
	struct treeNode* nextSib;
	struct treeNode* child;
} _treeNode;

// Fonction qui retourne un pointeur (type opaque) vers la racine de l'arbre construit. 
void *getRootTree();

void getRoot();

// Fonction qui recherche dans l'arbre tous les noeuds dont l'etiquette est egale à la chaine de caractères en argument.   
// Par convention si start == NULL alors on commence à la racine 
// sinon on effectue une recherche dans le sous-arbre à partir du noeud start 
_Token *searchTree(void *start,char *name);

// fonction qui renvoie un pointeur vers char indiquant l'etiquette du noeud. (le nom de la rulename, intermediaire ou terminal) 
// et indique (si len!=NULL) dans *len la longueur de cette chaine.
char *getElementTag(void *node,int *len);

// fonction qui renvoie un pointeur vers char indiquant la valeur du noeud. (la partie correspondant à la rulename dans la requete HTTP)
// et indique (si len!=NULL) dans *len la longueur de cette chaine.
char *getElementValue(void *node,int *len);

// Fonction qui supprime et libere la liste chainée de réponse.
void purgeElement(_Token **r);

// Fonction qui supprime et libere toute la mémoire associée à l'arbre. 
void purgeTree(void *root);

// L'appel à votre parser un char* et une longueur à parser.  
int parseur(char *req, int len);




//add token to list of _Token
void addToken(_Token** _tList, void* node);


// recursive research in tree, util function for searchTree
void _searchRecursive(void* node, char* name, _Token** result);


//Unused, replaced by toNode()
//Add a sibling to node list. Make sure to add it to _Token List as well
//can add child to node by giving node->child as _tSibList parameter
void addSibling(_treeNode* _tSibList, _treeNode* node);

//Remove sibling from sibling node list and from _Token list. Remove recursively all child of node
void deleteNode(_Token** _tList, _treeNode* node);

//Unused
//Remove sibling from sibling node list
void removeSibling(_treeNode** _tSibList, _treeNode* node);


//Unused
//get the first sibling from anywhere in the sibling list
void* getFirstChild(void* node);


//util function to print a node
void printNode(void* node);

//show _Token linked list (linked list of nodes)
void showToken(_Token* start);

// recursive show of node in tree, util function for showTree
void _showRecursive(void* node, int count);

//show the tree from start node
void showTree(void* start);


//create and add node to _Token list and to the tree given the parent and the node datas
void* toNode(char* tag, int rulenameID, char* start, int length, _treeNode** parent);
