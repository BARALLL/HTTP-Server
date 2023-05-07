#include "request.h"   
#include "global.h"



/*
Verifier une requete : Je sais pas s'il faut tout faire, je pense pas

    METHOD METHOD = [GET,HEAD,POST] if not in METHOD => 501 Not Implemented

    HTTP-VERSION  : If version not in [0.9,1.0,1.1,2.0,3.0] (exist) => 400 Bad Request
    If version not in [0.9,1.0,1.1] (supported) => 505 HTTP Version Not Supported

    Request-target : Gérer le % encoding et le dot segment removal
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
    Verif quality is between 0 and 1 with at most 3 decimals after . Verif types/subtypes (peut être)

    Accept-encoding header
    Verif one of the content codings listed is the representation's content coding (si q!=0) or *|* else 
    => 415 Unsupported Media Type Without Accept - encoding = > everything is considered as acceptable so do nothing If representation has no content coding = > acceptable

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

    GET: Vous devrez récupérer la ressource demandée et retourner une réponse contenant les données de la ressource et les en-têtes appropriés.

    Exemple de réponse :
        HTTP/1.1 200 OK
        Content-Type: text/html
        Content-Length: 1234

        <contenu de la ressource>



    HEAD: Semblable à GET, mais vous ne devez retourner que les en-têtes de la réponse sans le corps.

    Exemple de réponse :
        HTTP/1.1 200 OK
        Content-Type: text/html
        Content-Length: 1234



    POST: Vous devrez traiter les données soumises dans le corps de la requête, généralement pour créer ou mettre à jour une ressource, 
    et retourner une réponse appropriée avec un code de statut et des en-têtes.

    Exemple de réponse :
        HTTP/1.1 201 Created
        Location: /new_resource
        Content-Type: application/...
        Content-Length: 567

        <contenu de la nouvelle ressource>
*/



void finConnexion(message** requete) 
{
    purgeTree(globalroot);
    requestShutdownSocket((*requete)->clientId);
    freeRequest(*requete);
    *requete = NULL;
}

int verifRequete()
{   
    int code = 200;

    int method = VerifMethod();
    if (method == 0)
    {
        code == 501;
        sendReponse(code);
        return 1;
    }
    code = verifVersion();

    return code;
}


void sendReponse(int code)
{
    //TODO
}




int verifVersion() {
    _Token* versionToken = searchTree(getRootTree(), "HTTP_version");
    int len;
    char* version;
    int code = 200;
    
    getElementValue(versionToken->node, &len);
    version = calloc(len+1, sizeof(char));
    if (version)
    {
        strncpy(version, getElementValue(versionToken->node, &len), len);

        version[len] = '\0';

        if (strcmp(version, "HTTP/0.9") == 0 || strcmp(version, "HTTP/1.0") == 0 || strcmp(version, "HTTP/1.1") == 0) {
            code = 200;
        }
        else if (strcmp(version, "HTTP/2.0") != 0 || strcmp(version, "HTTP/3.0") != 0) {
            code = 400; //bad request
        }
        else
            code = 505; //version not implemented

        free(version);
    }
    else
        return 0;

    return code;
}


int VerifMethod() {
    _Token* methodToken = searchTree(getRootTree(), "method");
    int len = 0;
    char* method;
    int res = 0;

    if (methodToken)
    {
        getElementValue(methodToken->node, &len);
        method = calloc(len + 1, sizeof(char));
        if (method)
        {
            strncpy(method, getElementValue(methodToken->node, &len), len);
            method[len] = '\0';

            if (strcmp(method, "GET") == 0) {
                res = 1;
            }
            else if (strcmp(method, "POST") == 0) {
                res = 2;
            }
            else if (strcmp(method, "HEAD") == 0) {
                res = 3;
            }
            else
                res = 501;  //501 Not Implemented
        }
        free(method);
    }
    return res;
}


int verifContentLength()
{
    _Token* CLToken = searchTree(getRootTree(), "Content-Length");  //pas de tag content length dans le parseur ?
    int len;
    int code = 200;
    if (CLToken != NULL) {
        char* contentLength = getElementValue(CLToken->node, &len);
        if (atoi(contentLength) < 0) 
        {
            return 400; //400 Bad Request
        }
    }
    return code;
}


int checkHostHeader(const char* httpVersion) 
{
    _Token* hostToken = searchTree(getRootTree(), "Host");
    int len;
    int code = 200;

    char* host = hostToken != NULL ? getElementValue(hostToken->node, &len) : NULL;
    if (strcmp(httpVersion, "HTTP/1.1") == 0) 
    {
        if (host == NULL) {
            code = 400;
        }
    }
    return code;
}