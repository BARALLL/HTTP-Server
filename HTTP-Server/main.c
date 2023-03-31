#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <errno.h>

#include "utils.h"
#pragma warning(disable : 4996)

#ifdef _WIN32
/*
* Special thanks to klauspost for their windows version of the mman library
* https://github.com/klauspost/mman-win32
*/
#include "mman.h"

/*
* Special thanks to AShelly for their windows version of the unistd library
* https://stackoverflow.com/a/826027/1202830
*/
#include "winunistd.h"
#endif

#ifdef __linux__ 
#include <unistd.h>
#include <sys/mman.h>
#endif


#define true 1 
#define false 0 

/*
int main(int argc,char *argv[])
{
	int res,fi;
	char *p=NULL,*addr;
    struct stat st;

	if (argc < 2 ) { printf("Usage: httpparser <file> <search>\nAttention <search> is case sensitive\n");  return 0; }
	// ouverture du fichier contenant la requête
	if ((fi=_open(argv[1],O_RDWR)) == -1) {
                perror("open");
                return false;
        }
        if (fstat(fi, &st) == -1)           //To obtain file size
                return false;
        if ((addr=mmap(NULL,st.st_size,PROT_WRITE,MAP_PRIVATE, fi, 0)) == NULL )
                return false;

	// This is a special HACK since identificateur in C can't have character '-'

	if (argc == 3 ) { 
		p=argv[2]; 	
		printf("searching for %s\n",p); 
		while (*p) { 
			if (*p=='-') { *p='_'; }
			p++; 
		}
		p=argv[2]; 	
	}
	// call parser and get results. 
	if (res=parseur(addr,st.st_size)) {
		_Token *r,*tok; 
		void *root=NULL;
		root=getRootTree(); 
		r=searchTree(root,p); 
		tok=r; 
		while (tok) {
			int l; 
			char *s; 
			s=getElementValue(tok->node,&l); 
			printf("FOUND [%.*s]\n",l,s);
			tok=tok->next; 
		}
		purgeElement(&r);
		purgeTree(root);
	}
	_close(fi);
	return(res); 
}
*/


int main()
{
	//noeud* root = calloc(1, sizeof(noeud));
	//_treeNode* node = &(_treeNode){NULL, 0, NULL, 0, getRootTree(), NULL, NULL, NULL};


	noeud* parent = (noeud*)addNode("[1:header_field]", NULL, 0, getRootTree());
	//printf("parent%p prev%p next%p child%p\n", parent->parent, parent->prevSib, parent->nextSib, parent->child);
	
	noeud* child1 = (noeud*)addNode("[2:Connection_header]", NULL, 0, &parent);
	
	//addSibling(parent->child, child);
	//printf("parent%p prev%p next%p child%p\n", child->parent, child->prevSib, child->nextSib, child->child);

	noeud* child2 = (noeud*)addNode("[2:Accept_Encoding_header]", NULL, 0, &parent);
	noeud* childOfChild2 = (noeud*)addNode("[3:case_insensitive_string]", NULL, 0, &child2);
	noeud* child2OfChild2 = (noeud*)addNode("[1:header_field]", NULL, 0, &child2);


	
	//showTree(NULL);
	//showToken(getRoot());
	showTree(parent);
	showTree(child2);
	//deleteNode(getRootTree(), childSib);
	_Token* result = searchTree(parent, "[1:header_field]");
	purgeTree(child2);
	
	showTree(parent);
	
	//showToken(getRootTree());


	//char* req = "startWS-?7-t_?fin\n";
	//int ret = parseur(req, strlen(req));
	//printf("val retour %d", ret);
	//return ret;
	return 0;
}
