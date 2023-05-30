#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "api/request.h"
#include "api/semantic.h"
#include <sys/mman.h>
#include <ctype.h>
#include <stdbool.h>
#include <crypt.h>
#include <time.h>


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
response* rep;

#define NB_HOST 8
char hostName[NB_HOST][64];
char hostPath[NB_HOST][128];
#define HTTP_CAT "https://http.cat/"

/*
    PDF r�gles a impl�menter /!\
    - traitement des champs methodes GET, POST (optionnel), et HEAD (voir exemple commentaire)

    - Request-target
    - HTTP-version
    - Ent�tes :
            Transfer-Encoding-header [rfc 7230 � 4]
            Cookie-header / [rfc6265]
            Referer-header [rfc7231 � 5.5.2]
            User-Agent-header [rfc7231 -5.5.3]
            Accept-header [rfc7231 � 5.3.2]
            Accept-Encoding-header [rfc 7231 � 5.3.4]

    En priorit� :
            Content-Length-header [rfc7230 � 3.3.2 et 3.3.3]
            Host-header [rfc7230 � 5.3 et 5.4]
            Connection-header [rfc7230 � 6]

    utilisation de la biblioth�que :

*/

/*
Verifier une requete : Je sais pas s'il faut tout faire, je pense pas

    METHOD METHOD = [GET,HEAD,POST] if not in METHOD => 501 Not Implemented

    HTTP-VERSION  : If version not in [0.9,1.0,1.1,2.0,3.0] (exist) => 400 Bad Request
    If version not in [0.9,1.0,1.1] (supported) => 505 HTTP Version Not Supported

    Request-target : G�rer le % encoding et le dot segment removal
    origin-form The most common form of request-target is the origin-form. origin-form = absolute-path [ "?" query ]
    absolute-form When making a request to a proxy, a client MUST send the target URI in absolute-form as the request-target. absolute-form = absolute-URI


    Transfer-Encoding-header
    Verify that the message body isn't chunked more than once
    Verify that the message body is chunked after the use of another transfer coding (not chunk)
    If it's a transfer-coding it doesn't understand => 501 Not Implemented
    If 1.0 and Transfer-Encoding header => 400 Bad Request

    Cookie-header : Je sais pas

    Referer header : If the URL contains a fragment (indicated by a '#' symbol) or userinfo (indicated by a '@' symbol) => 400 Bad Request

    User-Agent header : Je sais pas

    Accept header
    Verif quality is between 0 and 1 with at most 3 decimals after . Verif types/subtypes (peut �tre)

    Accept-encoding header
    Verif one of the content codings listed is the representation's content coding (si q!=0) or *|* else
    => 415 Unsupported Media Type Without Accept - encoding = > everything is considered as acceptable so do nothing 
    If representation has no content coding = > acceptable

    Content-Length header : max(Value = > 0) = > (Value < max) = > OK sinon 413 Content Too Large sinon 400 Bad Request

    Content-Length and Transfer-encoding headers can't be in the same request

    Host header

    Overlap with Request - target for URI
    If version 1.1 and no Host header = > 400 Bad Request
    If request - target include authority component and Host have a value different to this component = > 400 Bad Request
    If several Host header = > 400 Bad Request

    Connection header :
    If Version 1.0 and keep Alive option, must have Transfer - Encoding or Content - Length, if not 400 Bad Request
    If Version 1.1 and no close option, must have Transfer - Encoding or Content - Length, if not 400 Bad Request
    If is a proxy and Version 1.0 and keep Alive option or Version 1.1 and no close option = > 400 Bad Request
*/


/*
    Methodes :

    GET: Vous devrez r�cup�rer la ressource demand�e et retourner une r�ponse contenant les donn�es de la ressource et les en-t�tes appropri�s.
    [RFC 7231 4.3.1]
    Exemple de r�ponse :
        HTTP/1.1 200 OK
        Content-Type: text/html
        Content-Length: 1234

        <contenu de la ressource>



    HEAD: Semblable � GET, mais vous ne devez retourner que les en-t�tes de la r�ponse sans le corps.
    [RFC 7231 4.3.2]
    Exemple de r�ponse :
        HTTP/1.1 200 OK
        Content-Type: text/html
        Content-Length: 1234



    POST: Vous devrez traiter les donn�es soumises dans le corps de la requ�te, g�n�ralement pour cr�er ou mettre � jour une ressource,
    et retourner une r�ponse appropri�e avec un statusCode de statut et des en-t�tes.
    [RFC 7231 4.3.3]
    Exemple de r�ponse :
        HTTP/1.1 201 Created
        Location: /new_resource
        Content-Type: application/...
        Content-Length: 567

        <contenu de la nouvelle ressource>
*/

/*
    int statusCode;
    int httpVersion;
    int method;
    int contentLength;
    char* host;
    char* encoding;
    int connection;
*/

void endConnexion(message* requete)
{
    purgeTree(getRootTree());
    endWriteDirectClient(requete->clientId);
    if (rep->connection == 0) requestShutdownSocket(requete->clientId);
    freeRequest(requete);
    requete = NULL;
}

int verifRequete(message* requete)
{
    int statusCode = 200;
    int httpVersion = 0;

    response* rep = calloc(1, sizeof(response));
    rep->headers = malloc(1, sizeof(_Token));

    statusCode = verifVersion();
    if (statusCode != 200)   //simplement pour faire passer l'info du statusCode et de la version utilise en mm temps
        return statusCode;
    else httpVersion -= 200;    //donc httpVersion == 1 correspond a 1.0 et == 2 correspond a 1.1
                                //(si besoin on peut changer la version par un float pour ecrire directement 1.0/1.1)

    int method = verifMethod();
    if (method == 501)
    {
        statusCode = 501;
        writeErrorResponse(requete, statusCode);
        return 501;
    }
    //else call
    statusCode = verifHost();
    if (statusCode != 200) {
        return statusCode;
    }

    statusCode = verifContentLength();
    if (statusCode != 200) {
        return statusCode;
    }

    statusCode = verifTransferEncoding();
    if (statusCode != 200) {
        return statusCode;
    }

    /*statusCode = verifConnection(httpVersion);
    if (statusCode != 200) {
        return statusCode;
    }*/

    if (statusCode != 200 && statusCode != 201) {
        writeErrorResponse(requete, statusCode);
        return statusCode;
    }

    if (method == 1)
    {
      statusCode = responseMethodGET(requete);
	    if(statusCode != 200)
	    {
            writeErrorResponse(requete, statusCode);
            return statusCode;
	    }
    }
    else if (method == 3)
    {
	    statusCode = responseMethodHEAD(requete);
        if(statusCode != 200)
	    {
            writeErrorResponse(requete, statusCode);
            return statusCode;
        }
	}

    free(rep);
    return statusCode;
}


void writeErrorResponse(message* requete, int code){
    /*
    char* url = calloc(21, sizeof(char));
    strcpy(url, HTTP_CAT, strlen(HTTP_CAT));
    sprintf(url+strlen(HTTP_CAT), "%d", code);
    */

    if (code == 400) {
        writeDirectClient(requete->clientId,"HTTP/1.1 400 BAD REQUEST\r\n", strlen("HTTP/1.0 400 BAD REQUEST\r\n"));
        writeDirectClient(requete->clientId, "Content-Length: 361\r\n\r\n", strlen("Content-Length: 361\r\n\r\n"));
        writeDirectClient(requete->clientId, "<!DOCTYPE html><html><head><title>400 Bad Request</title><style>body{background-color:#f8f8f8;font-family:Arial,sans-serif;text-align:center;padding:50px;}h1{font-size:48px;color:#333;margin-bottom:30px;}p{font-size:24px;color:#666;margin-bottom:30px;}</style></head><body><h1>400 Bad Request</h1><p>Sorry, your request could not be processed.</p></body></html>", strlen("<!DOCTYPE html><html><head><title>400 Bad Request</title><style>body{background-color:#f8f8f8;font-family:Arial,sans-serif;text-align:center;padding:50px;}h1{font-size:48px;color:#333;margin-bottom:30px;}p{font-size:24px;color:#666;margin-bottom:30px;}</style></head><body><h1>400 Bad Request</h1><p>Sorry, your request could not be processed.</p></body></html>"));
        writeDirectClient(requete->clientId, "\r\n\r\n", strlen("\r\n\r\n"));
    }

    else if (code == 404) {
        writeDirectClient(requete->clientId,"HTTP/1.1 404 NOT FOUND\r\n", strlen("HTTP/1.1 404 NOT FOUND\r\n"));
        writeDirectClient(requete->clientId, "Content-Length: 363\r\n\r\n", strlen("Content-Length: 363\r\n\r\n"));
        writeDirectClient(requete->clientId, "<!DOCTYPE html><html><head><title>404 Not Found</title><style>body{background-color:#f8f8f8;font-family:Arial,sans-serif;text-align:center;padding:50px;}h1{font-size:48px;color:#333;margin-bottom:30px;}p{font-size:24px;color:#666;margin-bottom:30px;}</style></head><body><h1>404 Not Found</h1><p>Sorry, the page you requested could not be found.</p></body></html>", strlen("<!DOCTYPE html><html><head><title>404 Not Found</title><style>body{background-color:#f8f8f8;font-family:Arial,sans-serif;text-align:center;padding:50px;}h1{font-size:48px;color:#333;margin-bottom:30px;}p{font-size:24px;color:#666;margin-bottom:30px;}</style></head><body><h1>404 Not Found</h1><p>Sorry, the page you requested could not be found.</p></body></html>"));
        writeDirectClient(requete->clientId, "\r\n\r\n", strlen("\r\n\r\n"));
    }
    else if (code == 414) {
        writeDirectClient(requete->clientId,"HTTP/1.1 414 URI TOO LONG\r\n\r\n", strlen("HTTP/1.1 414 URI TOO LONG\r\n\r\n"));
    }
    else if (code == 501) {
        writeDirectClient(requete->clientId,"HTTP/1.1 501 NOT IMPLEMENTED\r\n\r\n", strlen("HTTP/1.1 501 NOT IMPLEMENTED\r\n\r\n"));
    }
    endConnexion(requete, rep);
}


void makeResponse(int statusCode, unsigned int clientId)
{
    //TODO
    /*construire le char* reponse */

    /*
    writeDirectClient(clientId, reponse, strlen(reponse));      //fonctions surement utile
    endWriteDirectClient(clientId);
    requestShutdownSocket(clientId);
    */
}


void writeHeader(message* requete)
{
    //if connection == 1 write  Connection: keep-alive else if == 0 Connection: close
    char* content_length = calloc(16, sizeof(char));
    char connection[] = rep->connection == 0 ? "Connection: close\n" : "Connection: keep-alive\n";
    sprintf(content_length, "%d", rep->contentLength);
    writeDirectClient(requete->clientId, "Content-Length: ", strlen("Content-Length: "));
    writeDirectClient(requete->clientId, content_length, strlen(content_length));
    writeDirectClient(requete->clientId, "\n", 1);
    writeDirectClient(requete->clientId, connection, strlen(connection));
    
    //writeDirectClient(requete->clientId, rep->buf, strlen(rep->buf));

    //rm previous auth cookie
    _Token* header = rep->headers;
    for (; header != NULL; header = header->next)
    {
        writeDirectClient(requete->clientId, (char*)header->node, strlen((char*)header->node));
    }

    
    writeDirectClient(requete->clientId, "\r\n", strlen("\r\n"));
    writeDirectClient(requete->clientId, "\r\n", strlen("\r\n"));
}


int verifVersion()
{
    _Token* versionToken = searchTree(getRootTree(), "HTTP_version");
    int len = 0;
    int statusCode;

    char* version = NULL;
    if (versionToken)
    {
        version = getElementValue(versionToken->node, &len);

        if (version)
        {
            if (strcmp(version, "HTTP/1.0") == 0)   //str to maj car version pas sensible a la casse
                rep->httpVersion = 1;
            else if (strcmp(version, "HTTP/1.1") == 0)      //0.9 peut-etre supporte ?
                rep->httpVersion = 2;
            else if (strcmp(version, "HTTP/0.9") == 0 || strcmp(version, "HTTP/2.0") == 0 || strcmp(version, "HTTP/3.0") == 0)
                statusCode = 505; //version not implemented
            else
                statusCode = 400; //bad request
        }
    }
    else
        return 0;

    //if (version != NULL) free(version);
    purgeElement(&versionToken);
    return statusCode;
}


int verifMethod()
{
    _Token* methodToken = searchTree(getRootTree(), "method");
    int len = 0;
    int statusCode = 0;
    char* method = NULL;

    if (methodToken)
    {
        method = getElementValue(methodToken->node, &len);

        if (method)
        {
            method[len] = '\0';
            if (strcmp(method, "GET") == 0) {
                rep->method = 1;
            }
            else if (strcmp(method, "POST") == 0) {
                rep->method = 2;
            }
            else if (strcmp(method, "HEAD") == 0) {
                rep->method = 3;
            }
            else
                statusCode = 501;  //501 Not Implemented
        }
    }
    else
        return 0;

    //if (method != NULL) free(method);
    purgeElement(&methodToken);
    return statusCode;
}


int verifContentLength()
{
    _Token* CLToken = searchTree(getRootTree(), "Content-Length");  //pas de tag content length dans le parseur ?
    int len;
    int statusCode = 200;
    char* contentLength = NULL;

    if (CLToken != NULL)
    {
        contentLength = getElementValue(CLToken->node, &len);
        contentLength[len] = '\0';

        if (atoi(contentLength) < 0)
        {
            free(contentLength);
            purgeElement(&CLToken);
            return 400; //400 Bad Request
        }
        if (rep->method == 3)    //POST
            rep->contentLength = atoi(contentLength);
    }
    //if (contentLength != NULL) free(contentLength);
    purgeElement(&CLToken);
    return statusCode;
}


int verifHost()
{
    _Token* hostToken;
    int len;
    int statusCode = 200;
    char* host = NULL;

    if (rep->httpVersion == 2) { //Si on est en HTTP/1.1
        hostToken = searchTree(getRootTree(), "Host");
        if (hostToken == NULL || hostToken->next != NULL)
        {
            statusCode = 400;
        }
        else
        {
            host = getElementValue(hostToken->node, &len);
            if (host)
            {
                rep->host = calloc(len, sizeof(char));
                strncpy(rep->host, host, len + 1);
                rep->host[len] = '\0';
            }
        }
    }

    //if(host != NULL) free(host);
    purgeElement(&hostToken);
    return statusCode;
}


int verifTransferEncoding()
{
    _Token* encodingToken = searchTree(getRootTree(), "Transfer_Encoding_header");
    int statusCode = 200;
    int len = 0;
    char* transferEncoding = NULL;

    if (encodingToken != NULL) {
        // If 1.0 and Transfer-Encoding header => 400 Bad Request
        if (rep->httpVersion == 1)
        {
            purgeElement(&encodingToken);
            return 400;
        }

        if (searchTree(getRootTree(), "Content-Length") != NULL)
        {
            purgeElement(&encodingToken);      //MUST not have Content-Length header && Transfer-Encoding header
            return 400;
        }

        purgeElement(&encodingToken);
        encodingToken = searchTree(getRootTree(), "transfert_coding");
        // Parcourir la liste chainee de transfert_coding et verifier que chaque element est chunked gzip compress deflate
        _Token* current;
        for (current = encodingToken; current != NULL; current = current->next)
        {
            transferEncoding = getElementValue(current->node, &len);
            transferEncoding[len] = '\0';
            if (strcmp(transferEncoding, "chunked") != 0 && strcmp(transferEncoding, "gzip") != 0 &&
                strcmp(transferEncoding, "compress") != 0 && strcmp(transferEncoding, "deflate") != 0)
            {
                //free(transferEncoding);
                purgeElement(&encodingToken);
                return 501; // If it's a transfer-coding it doesn't understand => 501 Not Implemented
            }
            //free(transferEncoding);
        }

        // If chunked more than once => 400 Bad Request
        int count = 0;
        for (current = encodingToken; current != NULL && count < 2; current = current->next) {

            transferEncoding = getElementValue(current->node, &len);
            transferEncoding[len] = '\0';
            if (strcmp(transferEncoding, "chunked") == 0)
                count++;
            //free(transferEncoding);
        }
        if (count > 1)
        {
            purgeElement(&encodingToken);
            return 400;
        }

        // If the last transfer coding is not chunked => 400 Bad Request
        for (current = encodingToken; current != NULL; current = current->next) { ; }

        transferEncoding = getElementValue(current->node, &len);
        transferEncoding[len] = '\0';
        if (strcmp(transferEncoding, "chunked") != 0)
        {
            //free(transferEncoding);
            purgeElement(&encodingToken);
            return 400;
        }
    }
    //if(transferEncoding != NULL) free(transferEncoding);
    purgeElement(&encodingToken);
    return 200;
}


int verifConnection()
{
    _Token* connectionToken = searchTree(getRootTree(), "Connection");
    int len;
    char* connection = NULL;

    if (connectionToken)
    {
        connection = getElementValue(connectionToken->node, &len);
        connection[len] = '\0';

        if (strcmp(connection, "close") == 0)
            rep->connection = 0;
        else if (rep->httpVersion == 1 && (strcmp(connection, "keep-alive") == 0 || strcmp(connection, "Keep-Alive") == 0)) //&& not proxy
            rep->connection = 1;
        else if (rep->httpVersion == 2)
            rep->connection = 1;
        else rep->connection = 0;


        if (rep->httpVersion == 1)
        {
            if (strcmp(connection, "close") != 0)
            {
                if (searchTree(getRootTree(), "Transfer-Encoding") == NULL && searchTree(getRootTree(), "Content-Length") == NULL)
                {
                    //free(connection);
                    purgeElement(&connectionToken);
                    return 400;
                }
            }                
        }
        else if (rep->httpVersion == 2)
        {
            if (strcmp(connection, "keep-alive") == 0 || strcmp(connection, "Keep-Alive") == 0)
            {
                if (searchTree(getRootTree(), "Transfer-Encoding") == NULL && searchTree(getRootTree(), "Content-Length") == NULL)
                {
                    //free(connection);
                    purgeElement(&connectionToken);
                    return 400;
                }
            }
        }
    }

    //if (connection != NULL) free(connection);
    purgeElement(&connectionToken);
    return 200;
}


int verifReferer()
{
    _Token* refererToken = searchTree(getRootTree(), "Referer");
    int len = 0;
    int statusCode = 200;

    char* refererValue = NULL;
    if (refererToken)
    {
        refererValue = getElementValue(refererToken->node, &len);

        if (refererValue)
        {
            if (strchr(refererValue, '#') != NULL || strchr(refererValue, '@') != NULL)
            {
                statusCode = 400;
            }
        }
    }
    else
        return 0;

    //if (version != NULL) free(version);
    purgeElement(&refererToken);
    return statusCode;
}


int verifAuth(message* requete)
{
    _Token* authToken;
    int len;
    int statusCode = 200;
    char* authValue = NULL;
    char* buf = NULL;
    char* cpy = NULL;

    authToken = searchTree(getRootTree(), "Authorization");

    if (authToken)
    {
        authValue = getElementValue(authToken->node, &len);
        if (authValue)
        {
            cpy = calloc(strlen(authValue), sizeof(char));
            strcpy(cpy, authValue);
            buf = strtok(cpy, ":");     //what is return value ? need free() ?
            buf += buf[0] == " " ? 1 : 0;
            if (strcomp(buf, "Basic") == 0)
            {
                buf = strtok(NULL, " ");
                free(cpy);
                cpy = base64_decode(buf);
                buf = calloc(116, sizeof(char)); //size of set-cookie.... = 84 + size of sessionID = 32
                strcpy(buf, "Set-Cookie: sessionID =");
                char* sessionID = authUser(requete, cpy);
                if (sessionID != NULL)
                {
                    rep->sessionID = sessionID;
                    strcat(buf, sessionID);
                    strcat(buf, "; Max-Age = 3600; HttpOnly; SameSite=Strict; Path=\r\n");
                    strcat(buf, rep->host);

                    addToken(rep->headers, buf);
                }
                else
                    statusCode = 401;
            }
        }
    }

    //if(host != NULL) free(host);
    purgeElement(&authToken);
    return statusCode;
}

/*
int writeBuf(response* rep, char* str)
{
    rep->buf = realloc(rep->buf, strlen(rep->buf) + strlen(str));
    strcat(rep->buf, str);
}
*/

int verifCookie(message* requete)
{
    _Token* cookieToken;
    int len;
    int statusCode = 200;
    char* cookieValue = NULL;
    char* buf = NULL;
    _Token* current;


    cookieToken = searchTree(getRootTree(), "Cookie");

    if (cookieToken)
    {
        for (current = cookieToken; current != NULL; current = current->next)
        {
            cookieValue = getElementValue(current->node, &len);
            if (buf == strstr(cookieValue, "sessionID"))
            {
                if(atoi(++buf) == requete->clientId)
                    rep->sessionID = strtok(buf,":");   //time_t rawtime; time(&rawtime); //401 if client send a sessionID not valid anymore
            }       //file restriction: file like shadow in hostpath with which group have access to it?
        }
    }
    else
    {
        for (_Token* current = sessionIDs; current != NULL; current = current->next)
        {
            if (atoi(++buf) == requete->clientId)
                removeToken(sessionIDs, current);
        }
    }

    purgeElement(&cookieToken);
    return statusCode;
}


int responseMethodGET(message* requete)
{
  char* url = NULL;
  int statusCode = getAbsolutePath(requete, &url);
  if(statusCode != 200) return statusCode;
  if (statusCode != 200) return statusCode;

  FILE* file = fopen(url, "rb"); //+1 to rm first '/'
  free(url);

  if(file)
	{
    fseek(file, 0, SEEK_END);
    rep->contentLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    writeDirectClient(requete->clientId,"HTTP/1.1 200 OK\r\n", strlen("HTTP/1.0 200 OK\r\n"));
    writeHeader(requete, rep);
    copieFichier(requete, file);
    writeDirectClient(requete->clientId, "\r\n\r\n", strlen("\r\n\r\n"));
    endConnexion(requete);
    //ATTENTION A LA CONNEXION
  }
  else
  {
  	return 404;
  }

  return 200;
}

/*
void getHostPath(message* requete)
{

  _Token host_token = seachTree(getRootTree(), "Host");
  int len_host;
  char* host_get = getElementValue(host_token ->node, &len_host);
  if(host = "toto.com")
}
*/

int responseMethodHEAD(message* requete){

  char* url = NULL;
  int statusCode = getAbsolutePath(requete, &url);
  if(statusCode != 200) return statusCode;

  FILE* file = fopen(url, "rb"); //+1 to rm first '/'
  free(url);
  char* content_length = calloc(16, sizeof(char));

  if(file)
	{
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    writeDirectClient(requete->clientId,"HTTP/1.1 200 OK\r\n", strlen("HTTP/1.0 200 OK\r\n"));
    sprintf(content_length, "%d", size);
    writeDirectClient(requete->clientId,"Content-Length: ", strlen("Content-Length: "));
    writeDirectClient(requete->clientId, content_length, strlen(content_length));
    writeDirectClient(requete->clientId, "\r\n", strlen("\r\n"));
    writeDirectClient(requete->clientId, "\r\n", strlen("\r\n"));

    endConnexion(requete);
    //ATTENTION A LA CONNEXION
  }
  else
  {
  	return 404;
  }

  return 200;
}


int getAbsolutePath(message* requete, char** url)
{
  _Token* absolute_pathToken = searchTree(getRootTree(), "absolute_path");
  int len_absolute_path;
  char* absolute_path_get = getElementValue(absolute_pathToken->node, &len_absolute_path);

  if(len_absolute_path > 8000)
  {
    purgeElement(&absolute_pathToken);
    free(absolute_path_get);
    return 414;
  }
  //PENSEZ A CHECK LA TAILLE DE L'URI et le .. (retour en arriere)
  //changer len_absolute_path en len_absolute_path
  char* absolute_path = malloc(len_absolute_path+1);
  if(!absolute_path) return 500;
  strncpy(absolute_path, absolute_path_get, len_absolute_path);
  absolute_path[len_absolute_path] = '\0';

  char* url_decoded = malloc(strlen(absolute_path)+1);
  if(!url_decoded) return 500;
  url_decode(absolute_path, url_decoded);

  char* real_absolute_path = malloc(strlen(url_decoded)+1);
  if(!real_absolute_path) return 500;
  remove_dot_segments(url_decoded, real_absolute_path);

  _Token* hostToken = searchTree(getRootTree(), "Host");
  int len_host;
  if (hostToken != NULL)
  {
      char* hostValue = getElementValue(hostToken->node, &len_host);
      char* host = calloc(len_host, sizeof(char));
      strncpy(host, hostValue, len_host);
      host[len_host] = '\0';
      char* path = NULL;

      int statusCode = getHost(host, &path);
      *url = calloc(strlen(path)+strlen(real_absolute_path)+1, sizeof(char));
      rep->host = path;

      statusCode = isRessourceProtected(url);
      if (statusCode != 200) return statusCode;

      strcpy(*url, path);
      strcat(*url, real_absolute_path);
      (*url)[strlen(path)+strlen(real_absolute_path)] = '\0';
  }
  else  {
    *url = calloc(strlen(real_absolute_path), sizeof(char));
    strcpy(*url, real_absolute_path+1);
    free(real_absolute_path);
  }

  //free(absolute_path_get);
  free(absolute_path);
  free(url_decoded);

  purgeElement(&absolute_pathToken);
  return 200;
}

/*
char* copieFichier(FILE *file){
    char *buffer;
    int size;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = calloc(size + 1, sizeof(char));
    if(buffer){
      fread(buffer, sizeof(char), size, file);
      buffer[size] = '\0';
    }

    fclose(file);
    return buffer;
}
*/

#define BUFFER_SIZE 1024

int copieFichier(message* requete, FILE* file)
{
    //unsigned char buffer[BUFFER_SIZE];
    unsigned char* buffer = calloc(BUFFER_SIZE, sizeof(unsigned char));
    if (buffer == NULL) return 500;
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        // Envoyez buffer comme corps de message de la réponse HTTP
        // Exemple: send(socket, buffer, bytesRead, 0);
        writeDirectClient(requete->clientId, buffer, bytesRead);
    }
    free(buffer);
    return 0;
}
//MMAP ?


void url_decode(const char *src, char *dst) {
    char a, b;
    while (*src) {
        if ((*src == '%') &&
            ((a = src[1]) && (b = src[2])) &&
            (isxdigit(a) && isxdigit(b))) {
            if (a >= 'a')
                a -= 'a'-'A';
            if (a >= 'A')
                a -= ('A' - 10);
            else
                a -= '0';
            if (b >= 'a')
                b -= 'a'-'A';
            if (b >= 'A')
                b -= ('A' - 10);
            else
                b -= '0';
            *dst++ = 16*a+b;
            src+=3;
        } else if (*src == '+') {
            *dst++ = ' ';
            src++;
        } else {
            *dst++ = *src++;
        }
    }
    *dst++ = '\0';
}


void remove_dot_segments(char *input, char *output) {
    char *segment_start = input;
    char *output_end = output;

    while (*segment_start) {
        if (!strncmp(segment_start, "../", 3) || !strncmp(segment_start, "./", 2)) {
            segment_start += (*segment_start == '.') ? 2 : 3;
        } else if (!strncmp(segment_start, "/./", 3) || !strcmp(segment_start, "/.")) {
            segment_start += 2;
        } else if (!strncmp(segment_start, "/../", 4) || !strcmp(segment_start, "/..")) {
            segment_start += 3;
            if (output_end != output) {
                output_end--;
                while (output_end > output && *output_end != '/') {
                    output_end--;
                }
            }
        } else if (!strcmp(segment_start, ".") || !strcmp(segment_start, "..")) {
            break;
        } else {
            if (*segment_start == '/') {
                *output_end++ = *segment_start++;
            }
            while (*segment_start && *segment_start != '/') {
                *output_end++ = *segment_start++;
            }
        }
    }

    *output_end = '\0';
}


void loadHost(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier host.conf");
        exit(EXIT_FAILURE);
    }
    char line[200];
    for (int i = 0; i < NB_HOST && fgets(line, sizeof(line), file) != NULL; i++)
    {
        sscanf(line, "%[^;]; %s", hostName[i], hostPath[i]);
    }

    fclose(file);
}

// Fonction verif()
int getHost(char *name, char** url)
{
    if(strcmp(hostName[0], "") == 0) loadHost("host.conf");
    for (int i = 0; i < NB_HOST; i++)
    {
        if (strcmp(hostName[i], name) == 0) {
            *url = hostPath[i];

            return 200;
        }
    }
    return 400; //host header contient une valeur incorrecte
}


char* authUser(message* requete, char* token)
{
    char* user = strtok(token, ":");
    char* passwd = strtok(NULL, ":");
    if (rep->host == NULL || rep->host == "")   //if client use HTTP/1.1 but no host, it sends ""
    {
        perror("User authentification cookie in a non valid context: no host in request");
        return 0;
    }
    
    char* shadow = malloc(strlen(rep->host) + strlen(".shadw"), sizeof(char));
    strcpy(shadow, rep->host);
    strcat(shadow, ".shadw");
    FILE* fp = fopen(shadow, "r");
    free(shadow);

    if (fp == NULL) return 0;

    char line[256];
    char* currUser, *currPass;
    char* encrypted = NULL;
    char *salt;
    


    while (fgets(line, sizeof(line), fp) != NULL)
    {
        currUser = strtok(line, ":");
        currPass = strtok(NULL, ":");

        if (strcmp(user, currUser) == 0 && strcmp(passwd, currPass) == 0)   //user found in db, create sessionID
        {
            salt = crypt_gensalt("$5$", 15, NULL, 0);
            if (salt == NULL) {
                perror("crypt_gensalt");
                return NULL;
            }

            encrypted = crypt(currPass, salt);
            if (encrypted == NULL) {
                perror("crypt_gensalt");
                return NULL;
            }
            currPass = strtok(NULL, ":");   //user was found, reuse for groups
            char* clID = calloc(16, sizeof(char));
            sprintf(clID, "%d", requete->clientId);
            char* token = calloc(strlen(clID) + strlen(encrypted) + 1 + strlen(currPass), sizeof(char));
            strcpy(token, clID);
            strcat(token, ":");
            strcat(token, encrypted);
            strcat(token, ":");
            strcat(token, currPass);
            addToken(sessionIDs, token);
        }
    }
    fclose(fp);

    return encrypted;
}


int isRessourceProtected(char* url)
{
    if (rep->host == NULL || rep->host == "")   //if client use HTTP/1.1 but no host, it'll sends ""
    {
        perror("User authentification cookie in a non valid context: no host in request");
        return 0;
    }

    char* prtctd = malloc(strlen(rep->host) + strlen(".prtctd") + 1, sizeof(char));
    strcpy(prtctd, rep->host);
    if (rep->host[strlen(rep->host) - 1] != '/') strcat(prtctd, "/.prtctd"); // .../google/api/ or .../google/api
    else strcat(prtctd, ".prtctd");                       //might be already threated by dot segment removal
    FILE* fp = fopen(prtctd, "r");
    free(prtctd);


    if (fp == NULL) return 0;

    char line[256];

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strcmp(line, url) == 0)
        {
            if (rep->sessionID == 0) //protected and user is not authentified
            {
                char* auth = calloc(strlen("WWW - Authenticate: Basic realm=\"example\"\r\n"), sizeof(char));
                strcpy(auth, "WWW-Authenticate: Basic realm=\"example\"\r\n");
                addToken(rep->headers, auth);
                return 401;
            }  
        }
    }
    return 200;
}

/*no c lib, implementation from https://github.com/elzoughby/Base64 */
char base46_map[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                     'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };
char* base64_decode(char* cipher) 
{

    char counts = 0;
    char buffer[4];
    char* plain = malloc(strlen(cipher) * 3 / 4);
    int i = 0, p = 0;

    for (i = 0; cipher[i] != '\0'; i++) {
        char k;
        for (k = 0; k < 64 && base46_map[k] != cipher[i]; k++);
        buffer[counts++] = k;
        if (counts == 4) {
            plain[p++] = (buffer[0] << 2) + (buffer[1] >> 4);
            if (buffer[2] != 64)
                plain[p++] = (buffer[1] << 4) + (buffer[2] >> 2);
            if (buffer[3] != 64)
                plain[p++] = (buffer[2] << 6) + buffer[3];
            counts = 0;
        }
    }

    plain[p] = '\0';
    return plain;
}


/*
            fclose(fp);
            FILE* gp = fopen(group_file, "r");
            if (gp == NULL) {
                return 0;
            }
            while (fgets(line, sizeof(line), gp) != NULL) {
                char* group = strtok(line, ":");
                char* members = strtok(NULL, ":");
                if (strcmp(group, "admin") == 0) {
                    char* member = strtok(members, " ");
                    while (member != NULL) {
                        if (strcmp(user, member) == 0) {
                            fclose(gp);
                            return 1;
                        }
                        member = strtok(NULL, " ");
                    }
                }
            }
            fclose(gp);
            return 0;

*/

//MIME
//Multi-sites (define tableau correspondance) OK
//Sentinelle envoie fichier OK
//Connection OK?
//Pas forcément lire le fichier en une fois OK?
//2 algos au dessus OK

int createUser(char* user, char* passwd, char* groups) {
    char* encrypted, * salt;

    salt = crypt_gensalt("$5$", 15, NULL, 0);
    if (salt == NULL) {
        perror("crypt_gensalt");
        exit(EXIT_FAILURE);
    }

    encrypted = crypt(passwd, salt);
    if (encrypted == NULL) {
        perror("crypt_gensalt");
        exit(EXIT_FAILURE);
    }

    //printf("Encrypted: %s", encrypted);

    if (rep->host == NULL || rep->host == "")   //if client use HTTP/1.1 but no host, it sends ""
    {
        perror("User authentification cookie in a non valid context: no host in request");
        return 0;
    }

    char* shadow = malloc(strlen(rep->host) + strlen(".shadw")+1, sizeof(char));
    strcpy(shadow, rep->host);
    if(rep->host[strlen(rep->host)-1] != '/') strcat(shadow, "/.shadw"); // .../google/api/ or .../google/api
    else strcat(shadow, ".shadw");                       //might be already threated by dot segment removal
    FILE* fp = fopen(shadow, "a");
    free(shadow);

    fprintf(fp, "%c", '\n');
    fprintf(fp, "%s", user);
    fprintf(fp, "%s", ":");
    fprintf(fp, "%s", encrypted);
    fprintf(fp, "%s", ":");
    fprintf(fp, "%s", groups);
    close(fp);
}