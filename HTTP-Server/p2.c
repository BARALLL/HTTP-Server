/*
HTTP_message 
arrangeArbre
nettoieArbre
searchTree
getElementValue
getElementTag
purgeElement
*/


int main(int param_1, long param_2)

{
    char cVar1;
    long lVar2;
    uint uVar3;
    int __fildes;
    int iVar4;
    char* pcVar5;
    undefined8* puVar6;
    undefined8 uVar7;
    undefined8 uVar8;
    char* pcVar9;
    uint local_f4;
    undefined8* local_f0;
    char* local_e8;
    code* local_e0;
    undefined4 local_d8;
    undefined8 local_d0;
    stat local_c8;

    if (param_1 < 2) {
        puts("Usage: httpparser <file> [search]\nAttention <search> is case sensitive");
        // WARNING: Subroutine does not return
        exit(1);
    }
    local_d8 = 0;
    local_d0 = 0;
    local_e0 = call;
    __fildes = open(*(char**)(param_2 + 8), 2);
    if (__fildes == -1) {
        perror("open");
        return 0;
    }
    iVar4 = __fxstat(1, __fildes, &local_c8);
    if ((iVar4 == -1) ||
        (pcVar5 = (char*)mmap((void*)0x0, local_c8.st_size, 2, 2, __fildes, 0), pcVar5 == (char*)0x0)) {
        return 0;
    }
    local_e8 = pcVar5;
    if (param_1 == 3) {
        pcVar9 = *(char**)(param_2 + 0x10);
        printf("searching for %s\n", pcVar9);
        cVar1 = *pcVar9;
        while (cVar1 != '\0') {
            if (cVar1 == '-') {
                *pcVar9 = '_';
            }
            pcVar9 = pcVar9 + 1;
            cVar1 = *pcVar9;
        }
        lVar2 = *(long*)(param_2 + 0x10);
        iVar4 = HTTP_message(&local_e8);
        if (iVar4 == 0) goto LAB_0010095c;
        arrangeArbre(local_d0, 0);
        nettoieArbre(local_d0);
        if (lVar2 == 0) goto LAB_001009c1;
        puVar6 = (undefined8*)searchTree(local_d0, lVar2);
        local_f0 = puVar6;
        for (; puVar6 != (undefined8*)0x0; puVar6 = (undefined8*)puVar6[1]) {
            uVar7 = getElementValue(*puVar6, &local_f4);
            uVar3 = local_f4;
            uVar8 = getElementTag(*puVar6, 0);
            printf("%s --> FOUND [%.*s]\n", uVar8, (ulong)uVar3, uVar7);
        }
        purgeElement(&local_f0);
    }
    else {
        iVar4 = HTTP_message(&local_e8);
        if (iVar4 == 0) {
        LAB_0010095c:
            iVar4 = 0;
            puts("NOK");
            goto LAB_0010096b;
        }
        arrangeArbre(local_d0, 0);
        nettoieArbre(local_d0);
    LAB_001009c1:
        for (; cVar1 = *pcVar5, cVar1 != '\0'; pcVar5 = pcVar5 + 1) {
            if ((cVar1 == '\n') || (cVar1 == '\r')) {
                *pcVar5 = '_';
            }
        }
        afficheArbre(local_d0);
    }
    videArbre(&local_d0);
LAB_0010096b:
    close(__fildes);
    return iVar4;
}

/*
request_line
status_line
header_field
*/

undefined4 HTTP_message(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined4 uVar5;
    long lVar6;
    code* pcVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = request_line();
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        cVar3 = status_line(param_1);
        pcVar7 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) goto LAB_00116d45;
    LAB_00116d64:
        if (cVar3 != '\0') goto LAB_00116daf;
    }
    else {
        pcVar7 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) {
        LAB_00116d45:
            (*pcVar7)(param_1, (int)cVar3, "start_line", lVar1, *param_1 - lVar1);
            iVar4 = *(int*)(param_1 + 2);
            goto LAB_00116d64;
        }
    LAB_00116daf:
        while (true) {
            *(int*)(param_1 + 2) = iVar4 + 1;
            lVar2 = *param_1;
            cVar3 = header_field(param_1);
            if ((cVar3 == '\0') || (cVar3 = __crlf(param_1), cVar3 == '\0')) break;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        *param_1 = lVar2;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar2, 0);
        }
        *param_1 = lVar2;
        cVar3 = __crlf(param_1);
        if (cVar3 != '\0') {
            lVar2 = *param_1;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
            lVar6 = lVar2;
            while (cVar3 = __octet(param_1), cVar3 != '\0') {
                lVar6 = *param_1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *param_1 = lVar6;
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar4 + -3;
                return 1;
            }
            (*(code*)param_1[1])(param_1, 1, "message_body", lVar2, lVar6 - lVar2);
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar4 + -2;
                return 1;
            }
            uVar5 = 1;
            (*(code*)param_1[1])(param_1, 1, "__option", lVar1, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
            goto LAB_00116d6f;
        }
        iVar4 = *(int*)(param_1 + 2);
    }
    pcVar7 = (code*)param_1[1];
    uVar5 = 0;
LAB_00116d6f:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar5, "HTTP_message", lVar1, *param_1 - lVar1);
    }
    return uVar5;
}


//arbre
void arrangeArbre(int* param_1, int param_2)

{
    int* piVar1;
    long lVar2;
    int iVar3;
    char* pcVar4;
    char* pcVar5;
    bool bVar6;

    bVar6 = param_1 == (int*)0x0;
    if (!bVar6) {
        param_1[7] = 1;
        lVar2 = 8;
        pcVar4 = *(char**)(param_1 + 2);
        pcVar5 = "__group";
        do {
            if (lVar2 == 0) break;
            lVar2 = lVar2 + -1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (!bVar6) {
            lVar2 = 9;
            pcVar4 = *(char**)(param_1 + 2);
            pcVar5 = "__option";
            do {
                if (lVar2 == 0) break;
                lVar2 = lVar2 + -1;
                bVar6 = *pcVar4 == *pcVar5;
                pcVar4 = pcVar4 + 1;
                pcVar5 = pcVar5 + 1;
            } while (bVar6);
            if (!bVar6) {
                iVar3 = *param_1;
                for (piVar1 = *(int**)(param_1 + 8); piVar1 != (int*)0x0; piVar1 = *(int**)(piVar1 + 8))
                {
                    if (piVar1[7] == 0) {
                        if (*piVar1 <= iVar3) break;
                        if (*piVar1 == iVar3 + 1) {
                            arrangeArbre(piVar1, param_2);
                            iVar3 = *param_1;
                        }
                    }
                }
                *param_1 = iVar3 - param_2;
                return;
            }
        }
        for (piVar1 = *(int**)(param_1 + 8); piVar1 != (int*)0x0; piVar1 = *(int**)(piVar1 + 8)) {
            if (piVar1[7] == 0) {
                if (*piVar1 <= *param_1) {
                    return;
                }
                if (*param_1 + 1 == *piVar1) {
                    arrangeArbre(piVar1, param_2 + 1);
                }
            }
        }
    }
    return;
}

void nettoieArbre(long param_1)

{
    for (; param_1 != 0; param_1 = *(long*)(param_1 + 0x20)) {
        *(undefined4*)(param_1 + 0x1c) = 0;
    }
    return;
}

void videArbre(void** param_1)

{
    void* __ptr;

    __ptr = *param_1;
    while (__ptr != (void*)0x0) {
        *param_1 = *(void**)((long)__ptr + 0x20);
        free(__ptr);
        __ptr = *param_1;
    }
    return;
}

void afficheArbre(uint* param_1)

{
    uint uVar1;
    uint uVar2;
    char* pcVar3;
    bool bVar4;
    int* piVar5;
    int iVar6;
    int* piVar7;

    if (param_1 == (uint*)0x0) {
        return;
    }
    uVar1 = param_1[6];
    param_1[7] = 1;
    if (uVar1 != 0) {
        uVar2 = *param_1;
        iVar6 = 1;
        if (0 < (int)uVar2) {
            do {
                printf("    ");
                uVar2 = *param_1;
                bVar4 = iVar6 < (int)uVar2;
                iVar6 = iVar6 + 1;
            } while (bVar4);
            uVar1 = param_1[6];
        }
        if ((int)uVar1 < 10) {
            printf("[%d:%s] = \"%.*s\"\n", (ulong)uVar2, *(undefined8*)(param_1 + 2), (ulong)uVar1,
                *(undefined8*)(param_1 + 4));
        }
        else {
            pcVar3 = *(char**)(param_1 + 4);
            printf("[%d:%s] = \"%c%c%c..%c%c%c\"\n", (ulong)uVar2, *(undefined8*)(param_1 + 2),
                (ulong)(uint)(int)*pcVar3, (ulong)(uint)(int)pcVar3[1], (ulong)(uint)(int)pcVar3[2],
                (ulong)(uint)(int)pcVar3[(long)(int)uVar1 + -3],
                (ulong)(uint)(int)pcVar3[(long)(int)uVar1 + -2],
                (ulong)(uint)(int)pcVar3[(long)(int)uVar1 + -1]);
        }
    }
    while (true) {
        piVar5 = *(int**)(param_1 + 8);
        if (piVar5 == (int*)0x0) {
            return;
        }
        iVar6 = *piVar5;
        uVar1 = *param_1;
        if (iVar6 <= (int)uVar1) {
            return;
        }
        if (piVar5[7] != 0) {
            return;
        }
        piVar7 = (int*)0x0;
        do {
            if (iVar6 == uVar1 + 1) {
                piVar7 = piVar5;
            }
            piVar5 = *(int**)(piVar5 + 8);
        } while (((piVar5 != (int*)0x0) && (iVar6 = *piVar5, (int)uVar1 < iVar6)) && (piVar5[7] == 0));
        if (piVar7 == (int*)0x0) break;
        afficheArbre();
    }
    return;
}

int** searchTree(int* param_1, char* param_2)

{
    int iVar1;
    int iVar2;
    int** ppiVar3;
    int* piVar4;
    int** ppiVar5;

    if (((param_1 != (int*)0x0) && (piVar4 = *(int**)(param_1 + 8), piVar4 != (int*)0x0)) &&
        (iVar1 = *param_1, *piVar4 != iVar1 && iVar1 <= *piVar4)) {
        ppiVar5 = (int**)0x0;
        do {
            iVar2 = strcmp(*(char**)(piVar4 + 2), param_2);
            if (iVar2 == 0) {
                ppiVar3 = (int**)malloc(0x10);
                *ppiVar3 = piVar4;
                piVar4 = *(int**)(piVar4 + 8);
                ppiVar3[1] = (int*)ppiVar5;
                ppiVar5 = ppiVar3;
            }
            else {
                piVar4 = *(int**)(piVar4 + 8);
            }
        } while ((piVar4 != (int*)0x0) && (*piVar4 != iVar1 && iVar1 <= *piVar4));
        return ppiVar5;
    }
    return (int**)0x0;
}




// memoire
void empiler(void** param_1, undefined4 param_2, undefined8 param_3, undefined8 param_4,
    undefined4 param_5)

{
    void* pvVar1;
    undefined4* puVar2;

    puVar2 = (undefined4*)malloc(0x28);
    pvVar1 = *param_1;
    *puVar2 = param_2;
    *(undefined8*)(puVar2 + 2) = param_3;
    *(undefined8*)(puVar2 + 4) = param_4;
    puVar2[6] = param_5;
    puVar2[7] = 0;
    *(void**)(puVar2 + 8) = pvVar1;
    *param_1 = puVar2;
    return;
}


void depiler(long* param_1)

{
    if (*param_1 != 0) {
        *param_1 = *(long*)(*param_1 + 0x20);
    }
    return;
}





undefined8 getElementValue(long param_1, undefined4* param_2)

{
    if (param_2 != (undefined4*)0x0) {
        *param_2 = *(undefined4*)(param_1 + 0x18);
    }
    return *(undefined8*)(param_1 + 0x10);
}


/*
authority line 2200
path_absolute line 2736

query
path
host

absolute_URI 3137
URI 3291
URI_reference 3462
Content_Length 5131
HTTP_name 5159
HTTP_version 5177
Host 5216
OWS 5330 BWS 5381 RWS 5399
absolute_form 5454
absolute_path 5472

asterisk_form 5536
authority_form  |
chunk_data      |
chunk_size 5600

http_URI 5669
https_URI 5747
message_body 5825

field_content 5976
field_value     |
origin_form     |
partial_URI 6222

request_target 6701
status_code 6719
status_line 6756
field_name 6995
method 7033

chunk_ext_name 7099
chunk_ext_val 7117

request_line 7211
chunk_ext  7313
chunk       |
last_chunk  |
start_line 7714

transfer_extension 8007
transfer_coding     |
transfer_Encoding   |
t_codings 8279

uri_host 8447
*/



/*
* Network Related:

IPv4adress/IPv6adress/IPvFuture
IP_literal
path_empty
path_abempty
path_noscheme
path_rootless 2849
fragment
token 7071
connection_option
protocol_name
protocol_version
received_protocol
protocol
received_by
*/
