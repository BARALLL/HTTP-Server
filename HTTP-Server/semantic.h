#ifndef GLOBAL_H
#define GLOBAL_H
#include "api/global.h"
#endif // !1


#ifndef SEMANTIC_H
#define SEMANTIC_H

typedef struct {
    int statusCode;
    int httpVersion;
    int method;
    int contentLength;
    char* host;
    //char* buf;
    int connection;
    char* sessionID;
    _Token* headers;
} response;

_Token* sessionIDs;

#define NB_HOST 8
char hostName[NB_HOST][64];
char hostPath[NB_HOST][128];
#define HTTP_CAT "https://http.cat/"


void endConnexion(message* requete);

int verifRequete(message* requete);

void writeErrorResponse(message* requete, int code);

void makeResponse(int statusCode, unsigned int clientId);

int verifVersion();

int VerifMethod();

int verifContentLength();

int verifHost(int httpVersion);

int verifEncoding(int httpVersion);

int verifConnection(int httpVersion);

int responseMethodGET(message* requete);

int responseMethodHEAD(message* requete);

int copieFichier(message* requete, FILE* file);

void url_decode(const char *src, char *dst);

void remove_dot_segments(char *input, char *output);

int getAbsolutePath(message* requete, char** url);

int getHost(char *name, char** url);

void loadHost(char *filename);

void writeHeader(message* requete, response* rep);

int verifAuth(message* requete, response* rep);

int verifCookie(message* requete, response* rep);

char* authUser(message* requete, response* rep, char* token);

int isRessourceProtected(response* rep, char* url);

int createUser(response* rep, char* user, char* passwd, char* groups);

char base46_map[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                     'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };
char* base64_decode(char* cipher);

#endif