#include "request.h"   
#include "utils.h"
#include "global.h"
#include "api.h"



/*
    PDF règles a implémenter /!\
    - traitement des champs methodes GET, POST (optionnel), et HEAD (voir exemple commentaire)

    - Request-target
    - HTTP-version
    - Entêtes :
            Transfer-Encoding-header [rfc 7230 – 4]
            Cookie-header / [rfc6265]
            Referer-header [rfc7231 – 5.5.2]
            User-Agent-header [rfc7231 -5.5.3]
            Accept-header [rfc7231 – 5.3.2]
            Accept-Encoding-header [rfc 7231 – 5.3.4]
    
    En priorité :
            Content-Length-header [rfc7230 – 3.3.2 et 3.3.3]
            Host-header [rfc7230 – 5.3 et 5.4]
            Connection-header [rfc7230 – 6]

    utilisation de la bibliothèque :

*/

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
    [RFC 7231 4.3.1]
    Exemple de réponse :
        HTTP/1.1 200 OK
        Content-Type: text/html
        Content-Length: 1234

        <contenu de la ressource>



    HEAD: Semblable à GET, mais vous ne devez retourner que les en-têtes de la réponse sans le corps.
    [RFC 7231 4.3.2]
    Exemple de réponse :
        HTTP/1.1 200 OK
        Content-Type: text/html
        Content-Length: 1234



    POST: Vous devrez traiter les données soumises dans le corps de la requête, généralement pour créer ou mettre à jour une ressource, 
    et retourner une réponse appropriée avec un statusCode de statut et des en-têtes.
    [RFC 7231 4.3.3]
    Exemple de réponse :
        HTTP/1.1 201 Created
        Location: /new_resource
        Content-Type: application/...
        Content-Length: 567

        <contenu de la nouvelle ressource>
*/



void endConnexion(message* requete)
{
    purgeTree(getRootTree());
    requestShutdownSocket(requete->clientId);
    freeRequest(requete);
    requete = NULL;
}

int verifRequete(message* requete)
{   
    int statusCode = 200;
    int httpVersion = 0;

    httpVersion = verifVersion();
    if (httpVersion != 201 && httpVersion != 202)   //simplement pour faire passer l'info du statusCode et de la version utilisé en mm temps
        return statusCode;
    else httpVersion -= 200;    //donc httpVersion == 1 correspond a 1.0 et == 2 correspond a 1.1 
                                //(si besoin on peut changer la version par un float pour ecrire directement 1.0/1.1)
    
    int method = VerifMethod();
    if (method == 0)
    {
        statusCode == 501;
        sendReponse(statusCode, requete->clientId);
        return 1;
    }
    //else call 
    statusCode = verifHost(httpVersion);
    if (statusCode != 200) {
        return statusCode;
    }

    statusCode = verifContentLength();
    if (statusCode != 200) {
        return statusCode;
    }

    statusCode = verifEncoding(httpVersion);
    if (statusCode != 200) {
        return statusCode;
    }

    statusCode = verifConnection(httpVersion);
    if (statusCode != 200) {
        return statusCode;
    }

    return statusCode;
}


void sendReponse(int statusCode, unsigned int clientId)
{
    //TODO
    /*construire le char* reponse */

    /*
    writeDirectClient(clientId, reponse, strlen(reponse));      //fonctions surement utile
    endWriteDirectClient(clientId);
    requestShutdownSocket(clientId);
    */
}




int verifVersion() 
{
    _Token* versionToken = searchTree(getRootTree(), "HTTP_version");
    int len = 0;
    int statusCode = 0;
    
    char* version = NULL;
    if (versionToken)
    {
        version = getElementValue(versionToken->node, &len);
        if (version)
        {
            if (strcmp(version, "HTTP/1.0") == 0)
                statusCode = 201;
            else if (strcmp(version, "HTTP/1.1") == 0)      //0.9 peut-etre supporté ?
                statusCode = 201;
            else if (strcmp(version, "HTTP/0.9") == 0 || strcmp(version, "HTTP/2.0") == 0 || strcmp(version, "HTTP/3.0") == 0)
                statusCode = 505; //version not implemented
            else
                statusCode = 400; //bad request
        }
    }
    else
        return 0;

    if (version != NULL) free(version);
    purgeElement(&versionToken);
    return statusCode;
}


int VerifMethod() 
{
    _Token* methodToken = searchTree(getRootTree(), "method");
    int len = 0;
    int res = 0;
    char* method = NULL;

    if (methodToken)
    {
        method = getElementValue(methodToken->node, &len);
        if (method)
        {
            method = getElementValue(methodToken->node, &len);

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
    }
    else
        return 0;

    if (method != NULL) free(method);
    purgeElement(&methodToken);
    return res;
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
        if (atoi(contentLength) < 0) 
        {
            free(contentLength);
            purgeElement(&CLToken);
            return 400; //400 Bad Request
        }
    }
    if (contentLength != NULL) free(contentLength);
    purgeElement(&CLToken);
    return statusCode;
}


int verifHost(int httpVersion) 
{
    _Token* hostToken = searchTree(getRootTree(), "Host");
    int len;
    int statusCode = 200;
    char* host = NULL;

    if (hostToken != NULL)
    {
        host = getElementValue(hostToken->node, &len);
        if (httpVersion == 2)
        {
            if (host == NULL) {
                statusCode = 400;
            }
        }
    }
    if(host != NULL) free(host);
    purgeElement(&hostToken);
    return statusCode;
}


int verifEncoding(int httpVersion)
{
    _Token* encodingToken = searchTree(getRootTree(), "Transfer_Encoding_header");
    int statusCode = 200;
    int len = 0;
    char* transferEncoding = NULL;

    if (encodingToken != NULL) {
        // If 1.0 and Transfer-Encoding header => 400 Bad Request
        if (httpVersion == 1)
        {
            purgeElement(&encodingToken);
            return 400;
        }

        purgeElement(&encodingToken);
        encodingToken = searchTree(getRootTree(), "transfert_coding");
        // Parcourir la liste chainée de transfert_coding et vérifier que chaque élément est chunked gzip compress deflate
        _Token* current;
        for (current = encodingToken; current != NULL; current = current->next)
        {
            transferEncoding = getElementValue(current->node, &len);
            if (strcmp(transferEncoding, "chunked") != 0 && strcmp(transferEncoding, "gzip") != 0 &&
                strcmp(transferEncoding, "compress") != 0 && strcmp(transferEncoding, "deflate") != 0)
            {
                free(transferEncoding);
                purgeElement(&encodingToken);
                return 501; // If it's a transfer-coding it doesn't understand => 501 Not Implemented
            }
            free(transferEncoding);
        }

        // If chunked more than once => 400 Bad Request
        int count = 0;
        for (current = encodingToken; current != NULL && count < 2; current = current->next) {

            transferEncoding = getElementValue(current->node, &len);
            if (strcmp(transferEncoding, "chunked") == 0)
                count++;
            free(transferEncoding);
        }
        if (count > 1)
        {
            purgeElement(&encodingToken);
            return 400;
        }
            
        // If the last transfer coding is not chunked => 400 Bad Request
        for (current = encodingToken; current != NULL; current = current->next) { ; }

        transferEncoding = getElementValue(current->node, &len);
        if (strcmp(transferEncoding, "chunked") != 0)
        {
            free(transferEncoding);
            purgeElement(&encodingToken);
            return 400;
        }
            
    }
    if(transferEncoding != NULL) free(transferEncoding);
    purgeElement(&encodingToken);
    return 200;
}


int verifConnection(int httpVersion)
{
    _Token* connectionToken = searchTree(getRootTree(), "Connection");
    int len;
    char* connection = NULL;

    if (connectionToken)
    {
        connection = getElementValue(connectionToken->node, &len);

        if (httpVersion == 1)
        {
            if (strcmp(connection, "close") != 0)
            {
                if (searchTree(getRootTree(), "Transfer-Encoding") == NULL && searchTree(getRootTree(), "Content-Length") == NULL)
                {
                    free(connection);
                    purgeElement(connectionToken);
                    return 400;
                }

            }

        }

        else if (httpVersion == 2)
        {
            if (strcmp(connection, "keep-alive") == 0 || strcmp(connection, "Keep-Alive") == 0)
            {
                if (searchTree(getRootTree(), "Transfer-Encoding") == NULL && searchTree(getRootTree(), "Content-Length") == NULL)
                {
                    free(connection);
                    purgeElement(connectionToken);
                    return 400;
                }
            }
        }
    }

    if (connection != NULL) free(connection);
    purgeElement(&connectionToken);
    return 200;
}