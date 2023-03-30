#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


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
#include <fcntl.h>
#include <errno.h>
#pragma warning(disable : 4996)

#define false 0

typedef struct noeud {
	struct noeud *pere;
    char *tag;
	char *value;
    int taille;
    int nombrefils;
    struct noeud **fils;
  } noeud;

//Pour printf le champ tag ou value d'un fils : (**((*racine).fils+i)).value
/*
int parseur(char* addr,int taille, noeud* racine){
  int index = 0;
  if((*racine).pere==NULL){
      (*racine).tag = "[0:HTTP_message]";
      for (int i = 0; *(addr+i)!= ' ' && *(addr+i)!='\n' && *(addr+i)!='\r' && *(addr+i)!='\0'; i++) {
        index++;
      }
      (*racine).value = addr;
      (*racine).taille = taille;
			printf("[0:HTTP_message] = %c%c%c%c..%c%c%c%c\n",'"',*(addr),*(addr+1),*(addr+2),*(addr+(*racine).taille-3),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
    int nombreenfant=2;
    index = 0;
    while(*(addr+index)!='\r' || *(addr+1+index)!='\n' || *(addr+2+index)!='\r' || *(addr+3+index)!='\n' ){
      if(*(addr+index)=='\r' && *(addr+1+index)=='\n'){
        nombreenfant+=2;
      }
      index++;
    }
    (*racine).nombrefils = nombreenfant;
    (*racine).fils = malloc(sizeof(noeud*)*nombreenfant);
    for (int i = 0; i < nombreenfant; i++) {
      *((*racine).fils+i)=malloc(sizeof(noeud));
      (**((*racine).fils+i)).pere=racine;
    }
    index = 0;
		while(*(addr+index)!= '\r' || *(addr+index+1)!='\n'){
			index++;
		}
		index+=2;
		(**(*racine).fils).tag="[1:start_line]";
		(**(*racine).fils).taille=index;
		(**(*racine).fils).value=addr;
		int index2;
    for(int numeroenfant=1;index<taille;numeroenfant++){
      if(*(addr+index)!='\r'){
				for(index2=0;*(addr+index+index2)!= '\r' && *(addr+index+index2+1)!='\n';index2++)
				(**((*racine).fils+numeroenfant)).tag="[1:header_field]";
				(**((*racine).fils+numeroenfant)).value=addr+index;
				(**((*racine).fils+numeroenfant)).taille=index2;
				index=index+index2;
			}
			else{
				(**((*racine).fils+numeroenfant)).tag="[1:__crlf]";
				(**((*racine).fils+numeroenfant)).value=addr+index;
				(**((*racine).fils+numeroenfant)).taille=2;
				index+=2;
			}
		}
		for(int i = 0; i<(*racine).nombrefils;i++){
			if(parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ))==0)return(0);
		}}
	if(strcmp((*racine).tag,"[1:__crlf]")==0){
		printf("    %s = %c%c%c%c\n",(*racine).tag,'"',*addr,*(addr+1),'"');
		if (*addr != '\r' && *(addr+1)!='\n') {
			printf("Erreur format __crlf\n" );
			return(0);
		}}
	if(strcmp((*racine).tag,"[1:start_line]")==0){
		printf("    %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).fils = malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**(*racine).fils).pere=racine;
		(**(*racine).fils).tag="[2:request_line]";
		(**(*racine).fils).value=(*racine).value;
		(**(*racine).fils).taille=(*racine).taille;
		if(parseur((*racine).value,(*racine).taille,*((*racine).fils))==0)return(0);
	}
	if(strcmp((*racine).tag,"[1:header_field]")==0){
		printf("    %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).nombrefils=1;
		(*racine).fils = malloc(sizeof(noeud*));
		*((*racine).fils) = malloc(sizeof(noeud));
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).value = addr;
		(**((*racine).fils)).taille = (*racine).taille;
		(**((*racine).fils)).tag="[2:Rien]";
		if(strncmp((*racine).value,"Host:",sizeof("Host:")-1)==0){
			(**((*racine).fils)).tag = "[2:Host_header]";
		}
		if(strncmp((*racine).value,"User-Agent:",sizeof("User_Agent:")-1)==0){
			(**((*racine).fils)).tag = "[2:User_Agent_header]";
		}
		if(strncmp((*racine).value,"Accept:",sizeof("Accept:")-1)==0){
			(**((*racine).fils)).tag = "[2:Accept_header]";
		}
		if(strncmp((*racine).value,"Accept-Language:",sizeof("Accept_Language:")-1)==0){
			(**((*racine).fils)).tag = "[2:Accept_Language_header]";
		}
		if(strncmp((*racine).value,"Accept-Encoding:",sizeof("Accept_Encoding:")-1)==0){
			(**((*racine).fils)).tag = "[2:Accept_Encoding_header]";
		}
		if(strncmp((*racine).value,"Connection:",sizeof("Connection:")-1)==0){
			(**((*racine).fils)).tag = "[2:Connection_header]";}
		parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[2:Host_header]")==0){
		printf("        %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).fils = malloc(sizeof(noeud*)*4);
		(*racine).nombrefils = 4;
		int index = 0;
		for(index;*(addr+index)!= ':';index++)
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).value = addr;
		(**((*racine).fils)).taille = index;
		(**((*racine).fils)).tag = "[3:case_insensitive_string]";
		*((*racine).fils+1)=malloc(sizeof(noeud));
		(**((*racine).fils+1)).pere=racine;
		(**((*racine).fils+1)).value=addr+index;
		(**((*racine).fils+1)).taille=1;
		(**((*racine).fils+1)).tag="[3:case_insensitive_string]";
		index++;
		*((*racine).fils+2)=malloc(sizeof(noeud));
		(**((*racine).fils+2)).pere=racine;
		(**((*racine).fils+2)).tag="[3:OWS]";
		(**((*racine).fils+2)).taille=1;
		(**((*racine).fils+2)).value=addr+index;
		index++;
		*((*racine).fils+3)=malloc(sizeof(noeud));
		(**((*racine).fils+3)).pere=racine;
		(**((*racine).fils+3)).tag="[3:Host]";
		(**((*racine).fils+3)).value = addr + index;
		for(int index2=0;*(addr+index+index2)!='\r';index2++)
		(**((*racine).fils+3)).taille = index2;
		for(int i = 0; i <(*racine).nombrefils;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}

	}
	if(strcmp((*racine).tag,"[2:User_Agent_header]")==0){
		printf("        %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),*(addr+(*racine).taille),'"' );
		(*racine).fils = malloc(sizeof(noeud*)*5);
		(*racine).nombrefils = 5;
		int index = 0;
		for(index;*(addr+index)!= ':';index++)
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).value = addr;
		(**((*racine).fils)).taille = index;
		(**((*racine).fils)).tag = "[3:case_insensitive_string]";
		*((*racine).fils+1)=malloc(sizeof(noeud));
		(**((*racine).fils+1)).pere=racine;
		(**((*racine).fils+1)).value=addr+index;
		(**((*racine).fils+1)).taille=1;
		(**((*racine).fils+1)).tag="[3:case_insensitive_string]";
		index++;
		*((*racine).fils+2)=malloc(sizeof(noeud));
		(**((*racine).fils+2)).pere=racine;
		(**((*racine).fils+2)).tag="[3:OWS]";
		(**((*racine).fils+2)).taille=1;
		(**((*racine).fils+2)).value=addr+index;
		index++;
		*((*racine).fils+3)=malloc(sizeof(noeud));
		(**((*racine).fils+3)).pere=racine;
		(**((*racine).fils+3)).tag="[3:User_Agent]";
		(**((*racine).fils+3)).value = addr + index;
		for(int index2=0;*(addr+index+index2)!='\r';index2++)
		(**((*racine).fils+3)).taille = index2-1;
		*((*racine).fils+4)=malloc(sizeof(noeud));
		(**((*racine).fils+4)).pere=racine;
		(**((*racine).fils+4)).tag="[3:OWS]";
		(**((*racine).fils+4)).taille=1;
		(**((*racine).fils+4)).value=addr+index-1;
		for(int i = 0; i <(*racine).nombrefils;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[2:Accept_header]")==0){
		printf("        %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).fils = malloc(sizeof(noeud*)*4);
		(*racine).nombrefils = 4;
		int index = 0;
		for(index;*(addr+index)!= ':';index++)
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).value = addr;
		(**((*racine).fils)).taille = index;
		(**((*racine).fils)).tag = "[3:case_insensitive_string]";
		*((*racine).fils+1)=malloc(sizeof(noeud));
		(**((*racine).fils+1)).pere=racine;
		(**((*racine).fils+1)).value=addr+index;
		(**((*racine).fils+1)).taille=1;
		(**((*racine).fils+1)).tag="[3:case_insensitive_string]";
		index++;
		*((*racine).fils+2)=malloc(sizeof(noeud));
		(**((*racine).fils+2)).pere=racine;
		(**((*racine).fils+2)).tag="[3:OWS]";
		(**((*racine).fils+2)).taille=1;
		(**((*racine).fils+2)).value=addr+index;
		for (int i = 0; *(addr+index+i) == '	' || *(addr+index+i) == ' ' ; i++)
		{
			(**((*racine).fils+2)).taille=i+1;
		}
		index=index+(**((*racine).fils+2)).taille;
		*((*racine).fils+3)=malloc(sizeof(noeud));
		(**((*racine).fils+3)).pere=racine;
		(**((*racine).fils+3)).tag="[3:Accept]";
		(**((*racine).fils+3)).value = addr + index;
		for(int index2=0;*(addr+index+index2)!='\r';index2++)
		(**((*racine).fils+3)).taille = index2;
		for(int i = 0; i <(*racine).nombrefils;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[2:Accept_Language_header]")==0){
			printf("        %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),*(addr+(*racine).taille),'"' );
			(*racine).fils = malloc(sizeof(noeud*)*5);
			(*racine).nombrefils = 5;
			int index = 0;
			for(index;*(addr+index)!= ':';index++)
			*((*racine).fils)=malloc(sizeof(noeud));
			(**((*racine).fils)).pere=racine;
			(**((*racine).fils)).value = addr;
			(**((*racine).fils)).taille = index;
			(**((*racine).fils)).tag = "[3:case_insensitive_string]";
			*((*racine).fils+1)=malloc(sizeof(noeud));
			(**((*racine).fils+1)).pere=racine;
			(**((*racine).fils+1)).value=addr+index;
			(**((*racine).fils+1)).taille=1;
			(**((*racine).fils+1)).tag="[3:case_insensitive_string]";
			index++;
			*((*racine).fils+2)=malloc(sizeof(noeud));
			(**((*racine).fils+2)).pere=racine;
			(**((*racine).fils+2)).tag="[3:OWS]";
			(**((*racine).fils+2)).taille=1;
			(**((*racine).fils+2)).value=addr+index;
			index++;
			*((*racine).fils+3)=malloc(sizeof(noeud));
			(**((*racine).fils+3)).pere=racine;
			(**((*racine).fils+3)).tag="[3:Accept_Language]";
			(**((*racine).fils+3)).value = addr + index;
			for(int index2=0;*(addr+index+index2)!='\r';index2++)
			(**((*racine).fils+3)).taille = index2;
			*((*racine).fils+4)=malloc(sizeof(noeud));
			(**((*racine).fils+4)).pere=racine;
			(**((*racine).fils+4)).tag="[3:OWS]";
			(**((*racine).fils+4)).taille=1;
			(**((*racine).fils+4)).value=addr+index-1;
			for(int i = 0; i <(*racine).nombrefils;i++){
				parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
			}
		}
	if(strcmp((*racine).tag,"[2:Accept_Encoding_header]")==0){
		printf("        %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).fils = malloc(sizeof(noeud*)*4);
		(*racine).nombrefils = 4;
		int index = 0;
		for(index;*(addr+index)!= ':';index++)
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).value = addr;
		(**((*racine).fils)).taille = index;
		(**((*racine).fils)).tag = "[3:case_insensitive_string]";
		*((*racine).fils+1)=malloc(sizeof(noeud));
		(**((*racine).fils+1)).pere=racine;
		(**((*racine).fils+1)).value=addr+index;
		(**((*racine).fils+1)).taille=1;
		(**((*racine).fils+1)).tag="[3:case_insensitive_string]";
		index++;
		*((*racine).fils+2)=malloc(sizeof(noeud));
		(**((*racine).fils+2)).pere=racine;
		(**((*racine).fils+2)).tag="[3:OWS]";
		(**((*racine).fils+2)).taille=1;
		(**((*racine).fils+2)).value=addr+index;
		for (int i = 0; *(addr+index+i) == '	' || *(addr+index+i) == ' ' ; i++)
		{
			(**((*racine).fils+2)).taille=i+1;
		}
		index=index+(**((*racine).fils+2)).taille;
		*((*racine).fils+3)=malloc(sizeof(noeud));
		(**((*racine).fils+3)).pere=racine;
		(**((*racine).fils+3)).tag="[3:Accept_Encoding]";
		(**((*racine).fils+3)).value = addr + index;
		for(int index2=0;*(addr+index+index2)!='\r';index2++)
		(**((*racine).fils+3)).taille = index2;
		for(int i = 0; i <(*racine).nombrefils;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[2:Connection_header]")==0){
		printf("        %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).fils = malloc(sizeof(noeud*)*4);
		(*racine).nombrefils = 4;
		int index = 0;
		for(index;*(addr+index)!= ':';index++)
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).value = addr;
		(**((*racine).fils)).taille = index;
		(**((*racine).fils)).tag = "[3:case_insensitive_string]";
		*((*racine).fils+1)=malloc(sizeof(noeud));
		(**((*racine).fils+1)).pere=racine;
		(**((*racine).fils+1)).value=addr+index;
		(**((*racine).fils+1)).taille=1;
		(**((*racine).fils+1)).tag="[3:case_insensitive_string]";
		index++;
		*((*racine).fils+2)=malloc(sizeof(noeud));
		(**((*racine).fils+2)).pere=racine;
		(**((*racine).fils+2)).tag="[3:OWS]";
		(**((*racine).fils+2)).taille=1;
		(**((*racine).fils+2)).value=addr+index;
		for (int i = 0; *(addr+index+i) == '	' || *(addr+index+i) == ' ' ; i++)
		{
			(**((*racine).fils+2)).taille=i+1;
		}
		index=index+(**((*racine).fils+2)).taille;
		*((*racine).fils+3)=malloc(sizeof(noeud));
		(**((*racine).fils+3)).pere=racine;
		(**((*racine).fils+3)).tag="[3:Connection]";
		(**((*racine).fils+3)).value = addr + index;
		for(int index2=0;*(addr+index+index2)!='\r';index2++)
		(**((*racine).fils+3)).taille = index2;
		for(int i = 0; i <(*racine).nombrefils;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[2:request_line]")==0){
		printf("        %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).fils=malloc(sizeof(noeud*)*6);
		int index;
		{//method
			*((*racine).fils)=malloc(sizeof(noeud));
			(**((*racine).fils)).value=addr;
			for(index=0;*(addr+index)!=' ';index++) (**((*racine).fils)).taille=index;
			(**((*racine).fils)).tag="[3:method]";
			(**((*racine).fils)).pere=racine;
			if(parseur((**(*racine).fils).value,(**(*racine).fils).taille,*((*racine).fils))==0)return(0);
		}
		{//SP
			*((*racine).fils+1)=malloc(sizeof(noeud));
			(**((*racine).fils+1)).value=addr+index;
			for(int index2=1;*(addr-1+index+index2)==' ';index2++) (**((*racine).fils+1)).taille=index2;
			index=index+(**((*racine).fils+1)).taille;
			(**((*racine).fils+1)).tag="[3:__sp]";
			(**((*racine).fils+1)).pere=racine;
			if(parseur((**((*racine).fils+1)).value,(**((*racine).fils+1)).taille,*((*racine).fils +1 ))==0)return(0);
		}
		{//request_target
			*((*racine).fils+2)=malloc(sizeof(noeud));
			(**((*racine).fils+2)).value=addr+index;
			for(int index2=1;*(addr-1+index+index2)!=' ';index2++) (**((*racine).fils+2)).taille=index2;
			index=index+(**((*racine).fils+2)).taille;
			(**((*racine).fils+2)).tag="[3:request_target]";
			(**((*racine).fils+2)).pere=racine;
			if(parseur((**((*racine).fils+2)).value,(**((*racine).fils+2)).taille,*((*racine).fils +2 ))==0)return(0);
		}
		{//SP
			*((*racine).fils+3)=malloc(sizeof(noeud));
			(**((*racine).fils+3)).value=addr+index;
			for(int index2=1;*(addr-1+index+index2)==' ';index2++) (**((*racine).fils+3)).taille=index2;
			index=index+(**((*racine).fils+3)).taille;
			(**((*racine).fils+3)).tag="[3:__sp]";
			(**((*racine).fils+3)).pere=racine;
			if(parseur((**((*racine).fils+3)).value,(**((*racine).fils+3)).taille,*((*racine).fils +3 ))==0)return(0);
		}
		{//HTTP_version
			*((*racine).fils+4)=malloc(sizeof(noeud));
			(**((*racine).fils+4)).value=addr+index;
			for(int index2=1;*(addr-1+index+index2)!='\r';index2++) (**((*racine).fils+4)).taille=index2;
			index=index+(**((*racine).fils+4)).taille;
			(**((*racine).fils+4)).tag="[3:HTTP_version]";
			(**((*racine).fils+4)).pere=racine;
			if(parseur((**((*racine).fils+4)).value,(**((*racine).fils+4)).taille,*((*racine).fils +4 ))==0)return(0);
		}
		{//__crlf
			*((*racine).fils+5)=malloc(sizeof(noeud));
			(**((*racine).fils+5)).value=addr+index;
			for(int index2=1;index+index2-1<(*racine).taille;index2++) (**((*racine).fils+5)).taille=index2;
			index=index+(**((*racine).fils+5)).taille;
			(**((*racine).fils+5)).tag="[3:__crlf]";
			(**((*racine).fils+5)).pere=racine;
			if(parseur((**((*racine).fils+5)).value,(**((*racine).fils+5)).taille,*((*racine).fils +5 ))==0)return(0);
		}

	}
	if(strcmp((*racine).tag,"[3:method]")==0){
		printf("            %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).fils = malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**(*racine).fils).pere=racine;
		(**(*racine).fils).tag="[4:token]";
		(**(*racine).fils).value=(*racine).value;
		(**(*racine).fils).taille=(*racine).taille;
		if(parseur((*racine).value,(*racine).taille,*((*racine).fils))==0)return(0);
	}
	if(strcmp((*racine).tag,"[3:Host]")==0){
		printf("            %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),*(addr+(*racine).taille),'"' );
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[4:uri_host]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=(*racine).taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[3:User_Agent]")==0){
		printf("            %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),*(addr+(*racine).taille),'"' );
		int nombreenfant=1;
		for (int i = 0; i<taille; i++) {
			if(*(addr+i)==' '){
				nombreenfant+=2;
				while(*(addr+i)==' ')i++;
			}
			if(*(addr+i)=='('){
				while (*(addr+i)!=')') {
					i++;
				}
			}

		}
		(*racine).nombrefils=nombreenfant;
		(*racine).fils=malloc(sizeof(noeud*)*nombreenfant);
		int index=0;
		int index2=0;
		for(int i=0;i<nombreenfant;i++){
				index2=0;
				if(*(addr+index)=='('){
					while (*(addr+index+index2)!=')') {
						index2++;
					}
					index2++;
					*((*racine).fils+i)=malloc(sizeof(noeud));
					(**((*racine).fils+i)).value=addr+index;
					(**((*racine).fils+i)).pere=racine;
					(**((*racine).fils+i)).taille=index2;
					(**((*racine).fils+i)).tag="[4:comment]";
					index=index+index2;
				}else{
				for(index2;*(addr+index+index2)!=' '&&index+index2<taille;index2++){}
				*((*racine).fils+i)=malloc(sizeof(noeud));
				(**((*racine).fils+i)).value=addr+index;
				(**((*racine).fils+i)).pere=racine;
				(**((*racine).fils+i)).taille=index2;
				if (index2==0) {
					(**((*racine).fils+i)).taille=1;
					index2++;
					(**((*racine).fils+i)).tag="[4:RWS]";
				}
				else{(**((*racine).fils+i)).tag="[4:product]";}
				index=index+index2;
		}}
			for(int i = 0; i<nombreenfant;i++){
				parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
			}
	}
	if(strcmp((*racine).tag,"[3:case_insensitive_string]")==0){
		printf("            %s = %c",(*racine).tag,'"');
		for (int i = 0; i < (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		if((*addr != 'H' || *(addr+1) != 'o' || *(addr+2) != 's' || *(addr+3) != 't') && *addr != ':' && (*(addr)!='U' ||*(addr+1)!='s' ||*(addr+2)!='e' ||*(addr+3)!='r' ||*(addr+4)!='-' ||*(addr+5)!='A' ||*(addr+6)!='g' ||*(addr+7)!='e' ||*(addr+8)!='n' ||*(addr+9)!='t' ) && (*addr!='A' || *(addr+1)!= 'c' || *(addr+2)!= 'c' || *(addr+3)!= 'e' || *(addr+4)!= 'p' || *(addr+5)!= 't')&&( *(addr)!= 'C' || *(addr+1)!= 'o' || *(addr+2)!= 'n' || *(addr+3)!= 'n' || *(addr+4)!= 'e' || *(addr+5)!= 'c' || *(addr+6)!= 't'|| *(addr+7)!= 'i'|| *(addr+8)!= 'o'|| *(addr+9)!= 'n')) {
			printf("Erreur format [3:case_insensitive_string]\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[3:OWS]")==0){
		printf("            %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		for(int i=0;i<taille;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).tag="[4:__sp]";
			if(*(addr+i)=='	')(**((*racine).fils+i)).tag="[4:__htab]";
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));

		}
	}
	if(strcmp((*racine).tag,"[3:__sp]")==0){
		printf("            %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		if(*addr != ' '){
			printf("Erreur format __sp\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[3:__crlf]")==0){
		printf("            %s = %c%c%c%c\n",(*racine).tag,'"',*addr,*(addr+1),'"');
		if (*addr != '\r' && *(addr+1)!='\n') {
			printf("Erreur format __crlf\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[3:request_target]")==0){
		printf("            %s = %c",(*racine).tag,'"');
		int encore=1;
		for (int i = 0; i < 3; i++) {
			if(i==(*racine).taille)
			{
				encore = 0;
				i=3;
			}
			else{
				printf("%c",*(addr+i));
			}
		}
		if(encore == 1){
			printf("..");
			for(int i = 0;i<2;i++){
				printf("%c",*(addr+i+(*racine).taille-2) );
			}
		}
		printf("%c\n",'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[4:origin_form]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=(*racine).taille;
		(**((*racine).fils)).pere=racine;
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils ))==0)return(0);
	}
	if(strcmp((*racine).tag,"[3:Accept]")==0){
		printf("            %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),*(addr+(*racine).taille),'"' );
		int nombreenfant=1;
		for(int i =0;i<taille;i++){
			if(*(addr+i)==',')nombreenfant+=2;
		}
		(*racine).nombrefils=nombreenfant;
		(*racine).fils=malloc(sizeof(noeud*)*nombreenfant);
		int index=0;
		int index2=0;
		for(int i = 0;i<nombreenfant;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).pere = racine;
			(**((*racine).fils+i)).value = addr+index;
			if(*(addr+index)==','){
				(**((*racine).fils+i)).taille = 1;
				(**((*racine).fils+i)).tag = "[4:case_insensitive_string]";
				index++;
			}
			else{
				for(index2=0; *(addr+index+index2) !=',' && *(addr+index+index2)!='\r' ; index2++)
				(**((*racine).fils+i)).taille=index2+1;
				(**((*racine).fils+i)).tag = "[4:media_range]";
				index=index+index2;
			}

		}
		for(int i = 0; i <(*racine).nombrefils;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[3:Accept_Language]")==0){
		printf("            %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		int nombreenfant=1;
		int index=0;
		int index2=0;
		for(index;index<taille;index++){
			if(*(addr+index)==','){
				nombreenfant+=3;
			}
		}
		index=0;
		for(index;(*(addr+index)<'a'||*(addr+index)>'z')&&(*(addr+index)<'A'||*(addr+index)>'Z');index++){}
		(*racine).nombrefils=nombreenfant;
		(*racine).fils=malloc(sizeof(noeud*)*nombreenfant);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).value=addr+index;
		(**((*racine).fils)).tag="[4:language_range]";
		for(index2=0;*(addr+index+index2)!=',';index2++)
		(**((*racine).fils)).taille=index2;
		(**((*racine).fils)).pere=racine;
		index=index+index2;
		for(int i = 1;i<nombreenfant;i+=3){
			index2=0;
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).value=addr+index;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).tag="[4:case_insensitive_string]";
			(**((*racine).fils+i)).pere=racine;
			index++;
			*((*racine).fils+i+1)=malloc(sizeof(noeud));
			(**((*racine).fils+i+1)).value=addr+index;
			(**((*racine).fils+i+1)).tag="[4:language_range]";
			(**((*racine).fils+i+1)).pere=racine;
			while(*(addr+index+index2)!=';')index2++;
			(**((*racine).fils+i+1)).taille=index2-1;
			index=index2+index;
			index2=0;
			*((*racine).fils+i+2)=malloc(sizeof(noeud));
			(**((*racine).fils+i+2)).value=addr+index;
			(**((*racine).fils+i+2)).tag="[4:weight]";
			(**((*racine).fils+i+2)).pere=racine;
			while(*(addr+index+index2)!=','&&index+index2<taille)index2++;
			(**((*racine).fils+i+2)).taille=index2-1;
			index=index+index2;
		}
		for (int i = 0; i < nombreenfant; i++) {
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}

	}
	if(strcmp((*racine).tag,"[3:Accept_Encoding]")==0){
		(*racine).nombrefils=2;
		int index=0;
		(*racine).fils=malloc(sizeof(noeud*)*2);
		*((*racine).fils)= malloc(sizeof(noeud));
		*((*racine).fils+1)= malloc(sizeof(noeud));
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).tag="[4:codings]";
		for(index = 0;*(addr+index)!=' '&&*(addr+index)!='	';index++)
		(**((*racine).fils)).taille=index;
		(**((*racine).fils+1)).value=addr+index;
		(**((*racine).fils+1)).tag="[4:weight]";
		(**((*racine).fils+1)).pere=racine;
		(**((*racine).fils+1)).taille=taille-index;
		for(int i =0;i<2;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[3:HTTP_version]")==0){
		{
		printf("            %s = %c",(*racine).tag,'"');
		for (int i = 0; i < (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
	}//print
		(*racine).fils=malloc(sizeof(noeud*)*5);
		int index = 0;
		{//HTTP_name
			*((*racine).fils)=malloc(sizeof(noeud));
			(**((*racine).fils)).value=addr;
			for(index=0;*(addr+index)!='/';index++) (**((*racine).fils)).taille=index;
			(**((*racine).fils)).tag="[4:HTTP_name]";
			(**((*racine).fils)).pere=racine;
			if(parseur((**(*racine).fils).value,(**(*racine).fils).taille,*((*racine).fils))==0)return(0);
		}
		{//case_insensitive_string
			*((*racine).fils+1)=malloc(sizeof(noeud));
			(**((*racine).fils+1)).value=addr+index;
			for(int index2=1;*(addr-1+index+index2)=='/';index2++) (**((*racine).fils+1)).taille=index2;
			index=index+(**((*racine).fils+1)).taille;
			(**((*racine).fils+1)).tag="[4:case_insensitive_string]";
			(**((*racine).fils+1)).pere=racine;
			if(parseur((**((*racine).fils+1)).value,(**((*racine).fils+1)).taille,*((*racine).fils +1 ))==0)return(0);
		}
		{//digit
			*((*racine).fils+2)=malloc(sizeof(noeud));
			(**((*racine).fils+2)).value=addr+index;
			for(int index2=1;*(addr-1+index+index2)!='.';index2++) (**((*racine).fils+2)).taille=index2;
			index=index+(**((*racine).fils+2)).taille;
			(**((*racine).fils+2)).tag="[4:__digit]";
			(**((*racine).fils+2)).pere=racine;
			if(parseur((**((*racine).fils+2)).value,(**((*racine).fils+2)).taille,*((*racine).fils +2 ))==0)return(0);
		}
		{//case_insensitive_string
			*((*racine).fils+3)=malloc(sizeof(noeud));
			(**((*racine).fils+3)).value=addr+index;
			for(int index2=1;*(addr-1+index+index2)=='.';index2++) (**((*racine).fils+3)).taille=index2;
			index=index+(**((*racine).fils+3)).taille;
			(**((*racine).fils+3)).tag="[4:case_insensitive_string]";
			(**((*racine).fils+3)).pere=racine;
			if(parseur((**((*racine).fils+3)).value,(**((*racine).fils+3)).taille,*((*racine).fils +3 ))==0)return(0);
		}
		{//digit
			*((*racine).fils+4)=malloc(sizeof(noeud));
			(**((*racine).fils+4)).value=addr+index;
			for(int index2=1;*(addr-1+index+index2)!='\r';index2++) (**((*racine).fils+4)).taille=index2;
			index=index+(**((*racine).fils+4)).taille;
			(**((*racine).fils+4)).tag="[4:__digit]";
			(**((*racine).fils+4)).pere=racine;
			if(parseur((**((*racine).fils+4)).value,(**((*racine).fils+4)).taille,*((*racine).fils +4 ))==0)return(0);
		}

	}
	if(strcmp((*racine).tag,"[3:Connection]")==0){
		printf("            %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[4:connection_option]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=(*racine).taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[4:uri_host]")==0){
		printf("                %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),*(addr+(*racine).taille),'"' );
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[5:host]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=(*racine).taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[4:connection_option]")==0){
		printf("                %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[5:token]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=(*racine).taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[4:__sp]")==0){
		printf("                %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		if(*addr != ' '){
			printf("%d %d\n",*addr,' ' );
			printf("Erreur format __sp\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[4:__htab]")==0){
		printf("                %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		if(*addr != '	'){
			printf("%d %d\n",*addr,' ' );
			printf("Erreur format __htab\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[4:RWS]")==0){
		printf("                %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[5:__sp]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[4:codings]")==0){
		printf("                %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[5:content_codings]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[4:product]")==0){
		printf("                %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).nombrefils=3;
		(*racine).fils=malloc(sizeof(noeud*)*3);
		index=0;
		for(index;*(addr+index)!='/';index++)
		*((*racine).fils)=malloc(sizeof(noeud));
		(**(*racine).fils).taille=index-1;
		(**(*racine).fils).pere=racine;
		(**(*racine).fils).value=addr;
		(**(*racine).fils).tag = "[5:token]";
		*((*racine).fils+1)=malloc(sizeof(noeud));
		(**((*racine).fils+1)).value=addr+index;
		(**((*racine).fils+1)).pere=racine;
		(**((*racine).fils+1)).tag="[5:case_insensitive_string]";
		(**((*racine).fils+1)).taille=1;
		*((*racine).fils+2)=malloc(sizeof(noeud));
		(**((*racine).fils+2)).value=addr+index+1;
		(**((*racine).fils+2)).pere=racine;
		(**((*racine).fils+2)).tag="[5:product_version]";
		(**((*racine).fils+2)).taille=taille-index-2;
		for (int i = 0; i < 3; i++) {
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[4:token]")==0){
		printf("                %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		for(int i=0;i<=(*racine).taille;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).tag="[5:tchar]";
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			if(parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ))==0)return(0);

		}
	}
	if(strcmp((*racine).tag,"[4:language_range]")==0){
		printf("                %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		for(int i=0;i<=taille;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).tag="[5:__alpha]";
			if(*(addr+i)=='-'){(**((*racine).fils+i)).tag="[5:case_insensitive_string]";}
			if(*(addr+i)>='A'&&*(addr+i)<='Z'){(**((*racine).fils+i)).tag="[5:alphanum]";}
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));

		}
	}
	if(strcmp((*racine).tag,"[4:media_range]")==0){
		{
		printf("                %s = %c",(*racine).tag,'"');
		for (int i = 0; i < (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );}
		int nombreenfant = 0;
		int index=0;
		int index2=0;
		{
		if(*addr=='*' && *(addr+1)=='/'&&*(addr+2)=='*'){
			nombreenfant = 1;
		}
		if(*addr!='*'){
			while(*(addr+index)!='/')index++;
			if(*(addr+index+1)=='*')nombreenfant=2;
			else nombreenfant=3;
		}
		while(*(addr+index)!=';'&&index!=taille)index++;
		if(*(addr+index)==';')nombreenfant+=2;
		(*racine).nombrefils=nombreenfant;
		(*racine).fils=malloc(sizeof(noeud*)*nombreenfant);
	}
		index=0;
		if(*addr=='*'){
			*((*racine).fils)=malloc(sizeof(noeud));
			(**((*racine).fils)).value=addr;
			(**((*racine).fils)).tag="[5:case_insensitive_string]";
			(**((*racine).fils)).taille=3;
			index=3;
			(**((*racine).fils)).pere=racine;
		}
		else{
			while(*(addr+index)!='/')index++;
			*((*racine).fils)=malloc(sizeof(noeud));
			(**((*racine).fils)).value=addr;
			(**((*racine).fils)).tag="[5:type]";
			(**((*racine).fils)).taille=index-1;
			(**((*racine).fils)).pere=racine;
			if(*(addr+index+1)=='*'){
				*((*racine).fils+1)=malloc(sizeof(noeud));
				(**((*racine).fils+1)).value=addr+index;
				(**((*racine).fils+1)).tag="[5:case_insensitive_string]";
				(**((*racine).fils+1)).pere=racine;
				(**((*racine).fils+1)).taille=2;
				index+=2;
			}
			else{
				*((*racine).fils+1)=malloc(sizeof(noeud));
				(**((*racine).fils+1)).value=addr+index;
				(**((*racine).fils+1)).tag="[5:case_insensitive_string]";
				(**((*racine).fils+1)).pere=racine;
				(**((*racine).fils+1)).taille=1;
				index++;
				*((*racine).fils+2)=malloc(sizeof(noeud));
				(**((*racine).fils+2)).value=addr+index;
				(**((*racine).fils+2)).tag="[5:subtype]";
				(**((*racine).fils+2)).pere=racine;
				while(*(addr+index+index2)!=';'&&index+index2<taille)index2++;
				(**((*racine).fils+2)).taille=index2-1;
				index=index+index2;
			}
		}
		if(*(addr+index)==';'){
			*((*racine).fils+nombreenfant-2)=malloc(sizeof(noeud));
			(**((*racine).fils+nombreenfant-2)).value=addr+index;
			(**((*racine).fils+nombreenfant-2)).tag="[5:case_insensitive_string]";
			(**((*racine).fils+nombreenfant-2)).pere=racine;
			(**((*racine).fils+nombreenfant-2)).taille=1;
			index++;
			*((*racine).fils+nombreenfant-1)=malloc(sizeof(noeud));
			(**((*racine).fils+nombreenfant-1)).value=addr+index;
			(**((*racine).fils+nombreenfant-1)).tag="[5:parameter]";
			(**((*racine).fils+nombreenfant-1)).pere=racine;
			(**((*racine).fils+nombreenfant-1)).taille=taille-index-1;
		}
		for(int i = 0;i< nombreenfant;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[4:HTTP_name]")==0){
		{
			printf("                %s = %c",(*racine).tag,'"');
			for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
			printf("%c\n",'"' );
		}//print
		(*racine).fils = malloc(sizeof(noeud*));
		*((*racine).fils) = malloc(sizeof(noeud));
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=4;
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).tag="[5:__num]";
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils))==0)return(0);
	}
	if(strcmp((*racine).tag,"[4:comment]")==0){
		printf("                %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-3+(*racine).taille),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		for(int i=0;i<taille;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).tag="[5:ctext]";
			if(*(addr+i)=='('||*(addr+i)==')')(**((*racine).fils+i)).tag="[5:case_insensitive_string]";
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));

		}
	}
	if(strcmp((*racine).tag,"[4:__digit]")==0){
		printf("                %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*(addr)<'0'||*(addr)>'9'){
			printf("Erreur format case_insensitive_string\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[4:case_insensitive_string]")==0){
		printf("                %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*(addr)!='/'&&*(addr)!='.'&&*addr!=','){
			printf("Erreur format case_insensitive_string\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[4:origin_form]")==0){
		{
			printf("                %s = %c",(*racine).tag,'"');
		int encore=1;
		for (int i = 0; i < 3; i++) {
			if(i==(*racine).taille)
			{
				encore = 0;
				i=3;
			}
			else{
				printf("%c",*(addr+i));
			}
		}
		if(encore == 1){
			printf("..");
			for(int i = 0;i<2;i++){
				printf("%c",*(addr+i+(*racine).taille-2) );
			}
		}
		printf("%c\n",'"' );}
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[5:absolute_path]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=1;
		(**((*racine).fils)).pere=racine;
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils ))==0)return(0);
	}
	if(strcmp((*racine).tag,"[4:weight]")==0){
		printf("                %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		int nombreenfant=0;
		for(int i=0;i<taille;i++){
			if(*(addr+i)==' '|| *(addr+i)=='	'||*(addr+i)==';'||*(addr+i)=='q'||*(addr+i)=='=' )nombreenfant++;
			if(*(addr+i)==' ' || *(addr+i)=='	'){
				while(*(addr+i+1)==' '||*(addr+i+1)=='	'){
					i++;
				}
			}
		}
		(*racine).nombrefils=nombreenfant;
		(*racine).fils=malloc(sizeof(noeud*)*nombreenfant);
		int index = 0;
		int index2=0;
		for(int i = 0;i<nombreenfant;i++){
			index2=0;
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).value=addr+index;
			(**((*racine).fils+i)).pere=racine;
			if(*(addr+index)==' '){
				(**((*racine).fils+i)).tag="[5:OWS]";
				while(*(addr+index+index2)==' ')index2++;
				(**((*racine).fils+i)).taille=index2;
			}
			if(*(addr+index)==';'){
				(**((*racine).fils+i)).tag="[5:case_insensitive_string]";
				(**((*racine).fils+i)).taille=1;
				index2=1;
			}
			if(*(addr+index)=='q'){
				(**((*racine).fils+i)).tag="[5:case_insensitive_string]";
				(**((*racine).fils+i)).taille=2;
				index2=2;
			}
			if(*(addr+index)!='q' && *(addr+index)!=';'&& *(addr+index)!=' '){
				(**((*racine).fils+i)).tag="[5:qvalue]";
				while(*(addr+index+index2)!=' '&&index+index2<taille)index2++;
				(**((*racine).fils+i)).taille=index2;
			}
			index=index+index2;
		}
		for (int i = 0; i < nombreenfant; i++) {
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[5:host]")==0){
		printf("                    %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),*(addr+(*racine).taille),'"' );
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:reg_name]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=(*racine).taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[5:OWS]")==0){
		printf("                    %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		for(int i=0;i<taille;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).tag="[6:__sp]";
			if(*(addr+i)=='	')(**((*racine).fils+i)).tag="[6:__htab]";
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));

		}
	}
	if(strcmp((*racine).tag,"[5:content_codings]")==0){
		printf("                    %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:token]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[5:__alpha]")==0){
		printf("                    %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*addr >= 'a' && *addr <= 'z'){
			return(1);
		}
		else{
			printf("Erreur format __alpha\n" );
			return(0);
		 }
	}
	if(strcmp((*racine).tag,"[5:__sp]")==0){
		printf("                    %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		if(*addr != ' '){
			printf("Erreur format __sp\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[5:alphanum]")==0){
		printf("                    %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:__alpha]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=1;
		(**((*racine).fils)).pere=racine;
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils ))==0)return(0);
	}
	if(strcmp((*racine).tag,"[5:token]")==0){
		printf("                    %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		for(int i=0;i<=(*racine).taille;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).tag="[6:tchar]";
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			if(parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ))==0)return(0);

		}
	}
	if(strcmp((*racine).tag,"[5:type]")==0){
		printf("                    %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:token]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[5:subtype]")==0){
		printf("                    %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:token]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[5:parameter]")==0){
		printf("                    %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		int index=0;
		(*racine).nombrefils = 3;
		(*racine).fils=malloc(sizeof(noeud*)*3);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:token]";
		(**((*racine).fils)).value=addr;
		while(*(addr+index)!='=')index++;
		(**((*racine).fils)).taille=index-1;
		(**((*racine).fils)).pere = racine;
		*((*racine).fils+1)=malloc(sizeof(noeud));
		(**((*racine).fils+1)).value=addr+index;
		(**((*racine).fils+1)).pere=racine;
		(**((*racine).fils+1)).taille=1;
		(**((*racine).fils+1)).tag="[6:case_insensitive_string]";
		*((*racine).fils+2)=malloc(sizeof(noeud));
		(**((*racine).fils+2)).value=addr+index+1;
		(**((*racine).fils+2)).pere=racine;
		(**((*racine).fils+2)).taille=taille-index-1;
		(**((*racine).fils+2)).tag="[6:token]";
		for(int i = 0;i< 3;i++){
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));
		}
	}
	if(strcmp((*racine).tag,"[5:product_version]")==0){
		printf("                    %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).nombrefils = 1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:token]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=taille;
		(**((*racine).fils)).pere = racine;
		parseur((*racine).value,(*racine).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[5:__num]")==0){
		{
			printf("                    %s = %c",(*racine).tag,'"');
			for (int i = 0; i < (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
			printf("%c\n",'"' );}//print
		if(*addr!='H' || *(addr+1)!= 'T' || *(addr+2)!='T' || *(addr+3)!='P'){
			printf("Erreur format __num\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[5:qvalue]")==0){
		printf("                    %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		for(int i=0;i<=taille;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).tag="[6:__digit]";
			if(*(addr+i)=='.')(**((*racine).fils+i)).tag="[6:case_insensitive_string]";
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));

		}
	}
	if(strcmp((*racine).tag,"[5:case_insensitive_string]")==0){
		if(taille==1){
			printf("                    %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
			if(*(addr)!='/' && *(addr)!='(' && *(addr)!=')'&& *addr!=';'&& *addr!='*'&& *addr!='/'&& *addr!=','&&*addr!='-'){
			printf("Erreur format case_insensitive_string\n" );
			return(0);
			}
		}
		else{
			printf("                    %s = %c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),'"' );
			if((*(addr)!='q' || *(addr+1)!='=' )&&( *(addr)!='*' || *(addr+1)!='/')){
			printf("Erreur format case_insensitive_string\n" );
			return(0);
			}
		}
	}
	if(strcmp((*racine).tag,"[5:tchar]")==0){
		printf("                    %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:__alpha]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=1;
		(**((*racine).fils)).pere=racine;
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils ))==0)return(0);
	}
	if(strcmp((*racine).tag,"[5:ctext]")==0){
		printf("                    %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[6:__range]";
		if(*addr==' ')(**((*racine).fils)).tag="[6:__sp]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=1;
		(**((*racine).fils)).pere=racine;
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils ))==0)return(0);
	}
	if(strcmp((*racine).tag,"[5:absolute_path]")==0){
		{
			printf("                    %s = %c",(*racine).tag,'"');
			int encore=1;
			for (int i = 0; i < 3; i++) {
				if(i==(*racine).taille)
				{
					encore = 0;
					i=3;
				}
				else{
					printf("%c",*(addr+i));
				}
			}
			if(encore == 1){
				printf("..");
				for(int i = 0;i<2;i++){
					printf("%c",*(addr+i+(*racine).taille-2) );
				}
			}
			printf("%c\n",'"' );} //print
		int compteur = 1;
		for (int i = 1; i < (*racine).taille; i++) {
			if(*(addr+i)='/')compteur+=2;
			if(compteur == 1 && i==2)compteur = 2;
		}
		int index = 1;
		int index2 = 0;
		(*racine).fils=malloc(sizeof(noeud*)*compteur);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).pere=racine;
		(**((*racine).fils)).taille=1;
		(**((*racine).fils)).tag="[6:case_insensitive_string]";
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils))==0)return(0);
		for(int i = 1;i<compteur;i++){
			for(index2 = 0;*(addr+index+index2)!='/';index2++)
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).value=addr+index;
			(**((*racine).fils+i)).pere=racine;
			if(index2==0){
				(**((*racine).fils+i)).taille=1;
				(**((*racine).fils+i)).tag="[6:case_insensitive_string]";
			}
			else{
				(**((*racine).fils+i)).taille=index2;
				(**((*racine).fils+i)).tag="[6:segment]";
			}
			index=index+index2+1;
			if(parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils+i))==0)return(0);
		}
	}
	if(strcmp((*racine).tag,"[6:case_insensitive_string]")==0){
		printf("                        %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*(addr)!='/'&&*(addr)!='='&&*addr!='.'){
			printf("Erreur format case_insensitive_string\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[6:__sp]")==0){
		printf("                        %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		if(*addr != ' '){
			printf("Erreur format __sp\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[6:__htab]")==0){
		printf("                        %s = %c%c%c\n",(*racine).tag,'"',*addr,'"');
		if(*addr != '	'){
			printf("%d %d\n",*addr,' ' );
			printf("Erreur format __htab\n" );
			return(0);
		}
	}
	if(strcmp((*racine).tag,"[6:tchar]")==0){
		printf("                        %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[7:__alpha]";
		if(*addr=='-')(**((*racine).fils)).tag="[7:case_insensitive_string]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=1;
		(**((*racine).fils)).pere=racine;
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils ))==0)return(0);
	}
	if(strcmp((*racine).tag,"[6:token]")==0){
		printf("                        %s = %c",(*racine).tag,'"');
		for (int i = 0; i <= (*racine).taille; i++) {
			printf("%c",*(addr+i) );
		}
		printf("%c\n",'"' );
		(*racine).fils=malloc(sizeof(noeud*)*(*racine).taille);
		for(int i=0;i<=taille;i++){
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).tag="[7:tchar]";
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils +i ));

		}
	}
	if(strcmp((*racine).tag,"[6:reg_name]")==0){
		printf("                        %s = %c%c%c%c..%c%c%c%c\n",(*racine).tag,'"',*(addr),*(addr+1),*(addr+2),*(addr-2+(*racine).taille),*(addr-1+(*racine).taille),*(addr+(*racine).taille),'"' );
		(*racine).nombrefils=taille;
		(*racine).fils=malloc(sizeof(noeud*)*taille);
		for (int i = 0; i <= taille; i++) {
			*((*racine).fils+i)=malloc(sizeof(noeud));
			(**((*racine).fils+i)).value=addr+i;
			(**((*racine).fils+i)).taille=1;
			(**((*racine).fils+i)).pere=racine;
			(**((*racine).fils+i)).tag="[7:unreserved]";
			parseur((**((*racine).fils+i)).value,(**((*racine).fils+i)).taille,*((*racine).fils+i));
		}
	}
	if(strcmp((*racine).tag,"[6:__digit]")==0){
		printf("                        %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*addr >= '0' && *addr <= '9'){
			return(1);
		}
		else{
			printf("Erreur format __alpha\n" );
			return(0);
		 }
	}
	if(strcmp((*racine).tag,"[6:__alpha]")==0){
		printf("                        %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*addr >= 'A' && *addr <= 'Z'){
			return(1);
		}
		else{
			printf("Erreur format __alpha\n" );
			return(0);
		 }
	}
	if(strcmp((*racine).tag,"[6:__range]")==0){
		printf("                        %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*addr >= 'A' && *addr <= 'Z'||*addr >= 'a' && *addr <= 'z' || *addr == ';' ||*addr == '_'||*addr==':' || *addr=='"' || *addr >= '0' && *addr <= '9' || *addr == '.'|| *addr=='-'){
			return(1);
		}
		else{
			printf("Erreur format __range\n" );
			return(0);
		 }
	}
	if(strcmp((*racine).tag,"[7:tchar]")==0){
		printf("                            %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).tag="[8:__digit]";
		if(*(addr)=='.' || *(addr)=='+'||*addr == '*')(**((*racine).fils)).tag="[8:case_insensitive_string]";
		if(*addr >= 'a' && *addr <= 'z')(**((*racine).fils)).tag="[8:__alpha]";
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=1;
		(**((*racine).fils)).pere=racine;
		if(parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils ))==0)return(0);
	}
	if(strcmp((*racine).tag,"[7:__alpha]")==0){
		printf("                            %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*addr >= 'A' && *addr <= 'Z' || *addr >= 'a' && *addr <= 'z' ){
			return(1);
		}
		else{
			printf("Erreur format __alpha\n" );
			return(0);
		 }
	}
	if(strcmp((*racine).tag,"[7:unreserved]")==0){
		printf("                            %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		(*racine).nombrefils=1;
		(*racine).fils=malloc(sizeof(noeud*));
		*((*racine).fils)=malloc(sizeof(noeud));
		(**((*racine).fils)).value=addr;
		(**((*racine).fils)).taille=1;
		(**((*racine).fils)).pere=racine;
		if(*(addr)=='.'||*addr=='~'||*addr=='-'||*addr=='_'){
			(**((*racine).fils)).tag="[8:case_insensitive_string]";
		}
		else{
			(**((*racine).fils)).tag="[8:__alpha]";
		}
		parseur((**((*racine).fils)).value,(**((*racine).fils)).taille,*((*racine).fils));
	}
	if(strcmp((*racine).tag,"[8:case_insensitive_string]")==0){
		printf("                                %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*addr != '.' && *addr != '+'&&*addr!='*'&&*addr!='~'&&*addr!='_'&& *addr!='-')printf("Erreur Format [8:case_insensitive_string]\n" );return(0);
	}
	if(strcmp((*racine).tag,"[8:__alpha]")==0){
		printf("                                %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*addr >= 'A' && *addr <= 'Z' || *addr >= 'a' && *addr <= 'z'){
			return(1);
		}
		else{
			printf("Erreur format __alpha\n" );
			return(0);
		 }
	}
	if(strcmp((*racine).tag,"[8:__digit]")==0){
		printf("                                %s = %c%c%c\n",(*racine).tag,'"',*(addr),'"' );
		if(*addr >= '0' && *addr <= '9'){
			return(1);
		}
		else{
			printf("Erreur format __alpha\n" );
			return(0);
		 }
	}
	return(1);
}

*/


/*
int main(int argc,char *argv[])
{
	noeud *racine = malloc(sizeof(noeud));
	int res = 0;
	int fi;
	char *p=NULL,*addr;


        struct stat st;

	if (argc < 2 ) { printf("Usage: httpparser <file> <search>\nAttention <search> is case sensitive\n");  return 0; }
	/* ouverture du fichier contenant la requête
	if ((fi=_open(argv[1],O_RDWR)) == -1) {
                perror("open");
                return false;
        }
        if (fstat(fi, &st) == -1)           // To obtain file size
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
	parseur(addr,st.st_size,racine);
	_close(fi);
	return(res);
}
*/