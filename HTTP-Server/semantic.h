#ifndef GLOBAL_H
#define GLOBAL_H
#include "api/global.h"
#endif // !1


#ifndef SEMANTIC_H
#define SEMANTIC_H




void endConnexion(message* requete);

int verifRequete(message* requete);

void writeErrorResponse(message* requete, int code);

void makeResponse(int statusCode, unsigned int clientId);

int verifVersion();

int verifMethod();

int verifContentLength();

int verifHost();

int verifTransferEncoding();

int verifConnection();

int responseMethodGET(message* requete);

int responseMethodHEAD(message* requete);

int copieFichier(message* requete, FILE* file);

void url_decode(const char *src, char *dst);

void remove_dot_segments(char *input, char *output);

int getAbsolutePath(message* requete, char** url);

int getHost(char *name, char** url);

void loadHost(char *filename);

void writeHeader(message* requete, response* rep);

int verifAuth(message* requete);

int verifCookie(message* requete);

char* authUser(message* requete, char* token);

int isRessourceProtected(char* url);

int createUser(char* user, char* passwd, char* groups);

char* base64_decode(char* cipher);

#endif