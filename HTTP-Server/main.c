#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <errno.h>

#include "utils.h"
#include "global.h"
#include "api.h"
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


int main(int argc, char* argv[])
{
	int res, fi;
	char* p = NULL, * addr;
	struct stat st;

	//if (argc < 2) { printf("Usage: httpparser <file> <search>\nAttention <search> is case sensitive\n");  return 0; }
	// ouverture du fichier contenant la requête
	if ((fi = open("fuzzer/testFile/test0.txt", O_RDWR)) == -1) {
		perror("open");
		return false;
	}
	if (fstat(fi, &st) == -1)           //To obtain file size
		return false;
	if ((addr = mmap(NULL, st.st_size, PROT_WRITE, MAP_PRIVATE, fi, 0)) == NULL)
		return false;

	// This is a special HACK since identificateur in C can't have character '-'

	if (argc == 3) {
		p = argv[2];
		printf("searching for %s\n", p);
		while (*p) {
			if (*p == '-') { *p = '_'; }
			p++;
		}
		p = argv[2];
	}
	// call parser and get results.
	if (res = parseur(addr, st.st_size)) {
		_Token* r, * tok;
		void* root = NULL;
		root = getRootTree();
		r = searchTree(root, p);
		tok = r;
		while (tok) {
			int l;
			char* s;
			s = getElementValue(tok->node, &l);
			printf("FOUND [%.*s]\n", l, s);
			tok = tok->next;
		}
		// showTree(root2);
		purgeElement(&r);
		purgeTree(&root);
	}
	close(fi);
	printf("res = %d\n", res);
	return(res);
}



/*
int main(int argc, char* argv[])
{

	argc = 2;
	int num = 321;
	char snum[10];
	char* buf[20] = calloc(2, sizeof(char*));
	// Convert 123 to string [buf]
	itoa(num, snum, 10);
	for (int i = 0; i < 10000; i++)
	{
		itoa(i, snum, 10);
		strcat(snum, ".txt");
		strcat(strcpy(buf[1], "test"), snum);
		main2(2, buf);
	}
	main2();
}
*/
