#include "out.h"



int _init(EVP_PKEY_CTX* ctx)

{
    int iVar1;

    iVar1 = __gmon_start__();
    return iVar1;
}



void FUN_001007c0(void)

{
    // WARNING: Treating indirect jump as call
    (*(code*)(undefined*)0x0)();
    return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void free(void* __ptr)

{
    free(__ptr);
    return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char* __s)

{
    int iVar1;

    iVar1 = puts(__s);
    return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char* __s)

{
    size_t sVar1;

    sVar1 = strlen(__s);
    return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void* mmap(void* __addr, size_t __len, int __prot, int __flags, int __fd, __off_t __offset)

{
    void* pvVar1;

    pvVar1 = mmap(__addr, __len, __prot, __flags, __fd, __offset);
    return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char* __format, ...)

{
    int iVar1;

    iVar1 = printf(__format);
    return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
    int iVar1;

    iVar1 = close(__fd);
    return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int strcmp(char* __s1, char* __s2)

{
    int iVar1;

    iVar1 = strcmp(__s1, __s2);
    return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void* malloc(size_t __size)

{
    void* pvVar1;

    pvVar1 = malloc(__size);
    return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int __fxstat(int __ver, int __fildes, stat* __stat_buf)

{
    int iVar1;

    iVar1 = __fxstat(__ver, __fildes, __stat_buf);
    return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int open(char* __file, int __oflag, ...)

{
    int iVar1;

    iVar1 = open(__file, __oflag);
    return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void perror(char* __s)

{
    perror(__s);
    return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)

{
    // WARNING: Subroutine does not return
    exit(__status);
}



void __cxa_finalize(void)

{
    __cxa_finalize();
    return;
}



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



void _start(undefined8 param_1, undefined8 param_2, undefined8 param_3)

{
    undefined8 unaff_retaddr;
    undefined auStack_8[8];

    __libc_start_main(main, unaff_retaddr, &stack0x00000008, __libc_csu_init, __libc_csu_fini, param_3,
        auStack_8);
    do {
        // WARNING: Do nothing block with infinite loop
    } while (true);
}



// WARNING: Removing unreachable block (ram,0x00100b4b)
// WARNING: Removing unreachable block (ram,0x00100b57)

void deregister_tm_clones(void)

{
    return;
}



// WARNING: Removing unreachable block (ram,0x00100b98)
// WARNING: Removing unreachable block (ram,0x00100ba4)

void register_tm_clones(void)

{
    return;
}



void __do_global_dtors_aux(void)

{
    if (completed_6972 == '\0') {
        __cxa_finalize(&__dso_handle);
        deregister_tm_clones();
        completed_6972 = '\x01';
    }
    return;
}



// WARNING: Removing unreachable block (ram,0x00100c18)

void frame_dummy(void)

{
    register_tm_clones();
    return;
}



undefined8 __alpha(byte** param_1)

{
    byte* pbVar1;

    pbVar1 = *param_1;
    if (0x19 < (byte)((*pbVar1 & 0xdf) + 0xbf)) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__alpha", pbVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__alpha", pbVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __bit(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (1 < (byte)(*pcVar1 - 0x30U)) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__bit", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__bit", pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __char(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (*pcVar1 < '\x01') {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__char", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__char", pcVar1, 1);
        pcVar1 = *param_1;
    }
    *param_1 = pcVar1 + 1;
    return 1;
}



undefined8 __cr(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (*pcVar1 != '\r') {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, &__func___3882, pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, &__func___3882, pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __crlf(char** param_1)

{
    char* pcVar1;
    char* pcVar2;

    pcVar1 = *param_1;
    pcVar2 = pcVar1;
    if (*pcVar1 == '\r') {
        pcVar2 = pcVar1 + 1;
        *param_1 = pcVar2;
        if (pcVar1[1] == '\n') {
            *param_1 = pcVar1 + 2;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__crlf", pcVar1, 2);
            }
            return 1;
        }
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__crlf", pcVar1, (long)pcVar2 - (long)pcVar1);
    }
    *param_1 = pcVar1;
    return 0;
}



undefined8 __ctl(byte** param_1)

{
    byte* pbVar1;

    pbVar1 = *param_1;
    if ((0x1f < *pbVar1) && (*pbVar1 != 0x7f)) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__ctl", pbVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__ctl", pbVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __digit(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (9 < (byte)(*pcVar1 - 0x30U)) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__digit", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__digit", pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __dquote(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (*pcVar1 != '\"') {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__dquote", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__dquote", pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __hexdig(byte** param_1)

{
    code* pcVar1;
    byte* pbVar2;

    pbVar2 = *param_1;
    pcVar1 = (code*)param_1[1];
    if ((5 < (byte)((*pbVar2 & 0xdf) + 0xbf)) && (9 < (byte)(*pbVar2 - 0x30))) {
        if (pcVar1 != (code*)0x0) {
            (*pcVar1)(param_1, 0, "__hexdig", pbVar2, 1);
        }
        return 0;
    }
    if (pcVar1 != (code*)0x0) {
        (*pcVar1)(param_1, 1, "__hexdig", pbVar2, 1);
        pbVar2 = *param_1;
    }
    *param_1 = pbVar2 + 1;
    return 1;
}



undefined8 __htab(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (*pcVar1 != '\t') {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__htab", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__htab", pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __lf(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (*pcVar1 != '\n') {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, &__func___3918, pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, &__func___3918, pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __octet(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (*pcVar1 == '\0') {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__octet", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__octet", pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __sp(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (*pcVar1 != ' ') {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, &__func___3928, pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, &__func___3928, pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __vchar(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (0x5d < (byte)(*pcVar1 - 0x21U)) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__vchar", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__vchar", pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __wsp(char** param_1)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if ((*pcVar1 != ' ') && (*pcVar1 != '\t')) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__wsp", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "__wsp", pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __range(byte** param_1, byte param_2, byte param_3)

{
    byte* pbVar1;

    pbVar1 = *param_1;
    if ((param_2 <= *pbVar1) && (*pbVar1 <= param_3)) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "__range", pbVar1, 1);
        }
        *param_1 = *param_1 + 1;
        return 1;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__range", pbVar1, 1);
    }
    return 0;
}



undefined8 __istring(long* param_1, char* param_2)

{
    char cVar1;
    size_t sVar2;
    long lVar3;
    size_t sVar4;

    sVar2 = strlen(param_2);
    lVar3 = *param_1;
    sVar4 = 0;
    while (true) {
        if (sVar2 == sVar4) {
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "case_insensitive_string");
                lVar3 = *param_1;
                sVar2 = strlen(param_2);
            }
            *param_1 = lVar3 + sVar2;
            return 1;
        }
        cVar1 = *(char*)(lVar3 + sVar4);
        if ((cVar1 != param_2[sVar4]) &&
            ((0x19 < (byte)(cVar1 + 0x9fU) || (cVar1 + -0x20 != (int)param_2[sVar4])))) break;
        sVar4 = sVar4 + 1;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "case_insensitive_string");
    }
    return 0;
}



undefined8 __sstring(long* param_1, char* param_2)

{
    char* pcVar1;
    char* pcVar2;
    size_t sVar3;
    size_t sVar4;
    long lVar5;

    sVar3 = strlen(param_2);
    lVar5 = *param_1;
    sVar4 = 0;
    do {
        if (sVar3 == sVar4) {
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "case_sensitive_string", lVar5);
                lVar5 = *param_1;
                sVar3 = strlen(param_2);
            }
            *param_1 = lVar5 + sVar3;
            return 1;
        }
        pcVar1 = (char*)(lVar5 + sVar4);
        pcVar2 = param_2 + sVar4;
        sVar4 = sVar4 + 1;
    } while (*pcVar1 == *pcVar2);
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "case_sensitive_string", lVar5);
    }
    return 0;
}



undefined8 __icar(char** param_1, char param_2)

{
    char cVar1;
    char* pcVar2;

    pcVar2 = *param_1;
    cVar1 = *pcVar2;
    if ((cVar1 != param_2) && ((0x19 < (byte)(cVar1 + 0x9fU) || (cVar1 + -0x20 != (int)param_2)))) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "case_insensitive_string", pcVar2, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "case_insensitive_string", pcVar2, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __scar(char** param_1, char param_2)

{
    char* pcVar1;

    pcVar1 = *param_1;
    if (*pcVar1 != param_2) {
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "case_sensitive_string", pcVar1, 1);
        }
        return 0;
    }
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "case_sensitive_string", pcVar1, 1);
    }
    *param_1 = *param_1 + 1;
    return 1;
}



undefined8 __num(long* param_1, char* param_2)

{
    char* pcVar1;
    char* pcVar2;
    size_t sVar3;
    size_t sVar4;
    long lVar5;

    sVar3 = strlen(param_2);
    lVar5 = *param_1;
    sVar4 = 0;
    do {
        if (sVar3 == sVar4) {
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__num", lVar5);
                lVar5 = *param_1;
                sVar3 = strlen(param_2);
            }
            *param_1 = lVar5 + sVar3;
            return 1;
        }
        pcVar1 = (char*)(lVar5 + sVar4);
        pcVar2 = param_2 + sVar4;
        sVar4 = sVar4 + 1;
    } while (*pcVar1 == *pcVar2);
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__num", lVar5);
    }
    return 0;
}



void addElement(void** param_1, undefined8 param_2)

{
    void* pvVar1;
    undefined8* puVar2;

    puVar2 = (undefined8*)malloc(0x10);
    pvVar1 = *param_1;
    *puVar2 = param_2;
    *param_1 = puVar2;
    puVar2[1] = pvVar1;
    return;
}



long removeElement(long* param_1)

{
    long lVar1;

    if (param_1 == (long*)0x0) {
        lVar1 = 0;
    }
    else {
        lVar1 = *param_1;
        if (lVar1 != 0) {
            *param_1 = *(long*)(lVar1 + 8);
            return lVar1;
        }
    }
    return lVar1;
}



void purgeElement(void** param_1)

{
    void* __ptr;

    if (param_1 != (void**)0x0) {
        __ptr = *param_1;
        while (__ptr != (void*)0x0) {
            *param_1 = *(void**)((long)__ptr + 8);
            free(__ptr);
            __ptr = *param_1;
        }
    }
    return;
}



char* getElementTag(long param_1, undefined4* param_2)

{
    char* __s;
    size_t sVar1;

    if (param_2 != (undefined4*)0x0) {
        __s = *(char**)(param_1 + 8);
        sVar1 = strlen(__s);
        *param_2 = (int)sVar1;
        return __s;
    }
    return *(char**)(param_1 + 8);
}



undefined8 getElementValue(long param_1, undefined4* param_2)

{
    if (param_2 != (undefined4*)0x0) {
        *param_2 = *(undefined4*)(param_1 + 0x18);
    }
    return *(undefined8*)(param_1 + 0x10);
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



undefined8 scheme(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    int iVar6;
    code* pcVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __alpha();
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 != '\0') {
    LAB_00101800:
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __alpha(param_1);
        iVar6 = (int)cVar3;
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = __digit(param_1, iVar6);
            iVar6 = (int)cVar3;
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                cVar3 = __icar(param_1, 0x2b);
                iVar6 = (int)cVar3;
                if (cVar3 == '\0') {
                    *param_1 = lVar2;
                    cVar3 = __icar(param_1, 0x2d);
                    iVar6 = (int)cVar3;
                    if (cVar3 == '\0') {
                        *param_1 = lVar2;
                        cVar3 = __icar(param_1, 0x2e);
                        iVar6 = (int)cVar3;
                        if (cVar3 == '\0') goto code_r0x001018a3;
                    }
                }
            }
        }
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar6, "__group", lVar2);
            iVar4 = *(int*)(param_1 + 2);
        }
        goto LAB_00101800;
    }
    pcVar7 = (code*)param_1[1];
    uVar5 = 0;
LAB_001017b8:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar5, "scheme", lVar1, *param_1 - lVar1);
    }
    return uVar5;
code_r0x001018a3:
    pcVar7 = (code*)param_1[1];
    *param_1 = lVar2;
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, 0, "__group", lVar2, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
    }
    *param_1 = lVar2;
    uVar5 = 1;
    goto LAB_001017b8;
}



undefined8 port(long* param_1)

{
    long lVar1;
    char cVar2;
    long lVar3;

    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar3 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar3 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar3;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, &__func___2678, lVar1, lVar3 - lVar1);
    }
    return 1;
}



bool h16(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    bool bVar4;
    int iVar5;

    iVar5 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __hexdig(param_1);
    lVar2 = lVar1;
    do {
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            bVar4 = iVar5 - 1U < 4;
        LAB_001019ad:
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, bVar4, &__func___2895, lVar1, *param_1 - lVar1);
            }
            return bVar4;
        }
        iVar5 = iVar5 + 1;
        if (iVar5 == 4) {
            bVar4 = true;
            goto LAB_001019ad;
        }
        lVar2 = *param_1;
        cVar3 = __hexdig(param_1);
    } while (true);
}



int dec_octet(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, &DAT_00117638);
    if ((cVar2 == '\0') || (cVar2 = __range(param_1, 0x30, 0x35), cVar2 == '\0')) {
        *param_1 = lVar1;
        cVar2 = __icar(param_1, 0x32);
        if ((cVar2 == '\0') ||
            ((cVar2 = __range(param_1, 0x30, 0x34), cVar2 == '\0' ||
                (cVar2 = __digit(param_1), cVar2 == '\0')))) {
            *param_1 = lVar1;
            cVar2 = __icar(param_1, 0x31);
            if ((cVar2 != '\0') &&
                ((cVar2 = __digit(param_1), cVar2 != '\0' && (cVar2 = __digit(param_1), cVar2 != '\0')))) {
                iVar3 = 1;
                goto LAB_00101a8c;
            }
            *param_1 = lVar1;
            cVar2 = __range(param_1, 0x31, 0x39);
            if ((cVar2 == '\0') || (cVar2 = __digit(param_1), cVar2 == '\0')) {
                *param_1 = lVar1;
                cVar2 = __digit(param_1);
                iVar3 = (int)cVar2;
                goto LAB_00101a8c;
            }
        }
    }
    iVar3 = (int)cVar2;
LAB_00101a8c:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "dec_octet", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int IPv4address(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = dec_octet();
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x2e);
        if (cVar2 != '\0') {
            cVar2 = dec_octet(param_1);
            if (cVar2 != '\0') {
                cVar2 = __icar(param_1, 0x2e);
                if (cVar2 != '\0') {
                    cVar2 = dec_octet(param_1);
                    if (cVar2 != '\0') {
                        cVar2 = __icar(param_1, 0x2e);
                        if (cVar2 != '\0') {
                            cVar2 = dec_octet(param_1);
                            iVar3 = (int)cVar2;
                            goto LAB_00101b5b;
                        }
                    }
                }
            }
        }
    }
    iVar3 = 0;
LAB_00101b5b:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "IPv4address", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int ls32(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = h16();
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = h16(param_1);
            if (cVar2 != '\0') {
                iVar3 = *(int*)(param_1 + 2);
                iVar4 = (int)cVar2;
                *(int*)(param_1 + 2) = iVar3 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *(int*)(param_1 + 2) = iVar3 + -2;
                    return iVar4;
                }
                (*(code*)param_1[1])(param_1, iVar4, "__group", lVar1, 0);
                iVar3 = *(int*)(param_1 + 2);
                pcVar5 = (code*)param_1[1];
                goto LAB_00101c55;
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
    }
    *param_1 = lVar1;
    cVar2 = IPv4address(param_1);
    iVar3 = *(int*)(param_1 + 2);
    pcVar5 = (code*)param_1[1];
    iVar4 = (int)cVar2;
LAB_00101c55:
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, iVar4, &__func___2906, lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int IPv6address(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    long lVar7;

    iVar4 = 0;
    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar7 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = h16(param_1);
        if ((cVar2 == '\0') || (cVar2 = __icar(param_1, 0x3a), cVar2 == '\0')) break;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == 6) {
            cVar2 = ls32(param_1);
            goto LAB_00101d64;
        }
        lVar7 = *param_1;
        iVar3 = *(int*)(param_1 + 2);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar7;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
    }
    cVar2 = iVar4 == 6;
    *param_1 = lVar7;
LAB_00101d64:
    if (cVar2 != '\0') goto LAB_00101d6c;
    *param_1 = lVar1;
    cVar2 = __istring(param_1, &DAT_0011763b);
    if (cVar2 != '\0') {
        iVar3 = 0;
        do {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = h16(param_1);
            if ((cVar2 == '\0') || (cVar2 = __icar(param_1, 0x3a), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                *param_1 = lVar7;
                if ((code*)param_1[1] == (code*)0x0) goto LAB_00101e80;
                (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
                *param_1 = lVar7;
                if (iVar3 != 5) goto LAB_00101e80;
                break;
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 != 5);
        cVar2 = ls32(param_1);
        if (cVar2 != '\0') goto LAB_00101d6c;
    }
LAB_00101e80:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    *param_1 = lVar1;
    cVar2 = h16(param_1);
    if (cVar2 == '\0') {
        *param_1 = lVar1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, cVar2 != '\0', "__option", lVar1, 0);
    }
    cVar2 = __istring(param_1, &DAT_0011763b);
    if (cVar2 != '\0') {
        iVar3 = 0;
        do {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = h16(param_1);
            if ((cVar2 == '\0') || (cVar2 = __icar(param_1, 0x3a), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                *param_1 = lVar7;
                if ((code*)param_1[1] == (code*)0x0) goto LAB_00101f2a;
                (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
                *param_1 = lVar7;
                if (iVar3 != 4) goto LAB_00101f2a;
                break;
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 != 4);
        cVar2 = ls32(param_1);
        if (cVar2 != '\0') goto LAB_00101d6c;
    }
LAB_00101f2a:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    *param_1 = lVar1;
    cVar2 = h16(param_1);
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        uVar5 = 0;
        pcVar6 = (code*)param_1[1];
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar7 = *param_1;
        cVar2 = __icar(param_1, 0x3a);
        if ((cVar2 == '\0') || (cVar2 = h16(param_1), cVar2 == '\0')) {
            pcVar6 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            *param_1 = lVar7;
            if (pcVar6 != (code*)0x0) {
                (*pcVar6)(param_1, 0, "__group", lVar7, 0);
                pcVar6 = (code*)param_1[1];
            }
            *param_1 = lVar7;
        }
        else {
            pcVar6 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar6 != (code*)0x0) {
                (*pcVar6)(param_1, (int)cVar2, "__group", lVar7, 0);
                uVar5 = 1;
                pcVar6 = (code*)param_1[1];
                goto LAB_00101f94;
            }
        }
        uVar5 = 1;
    }
LAB_00101f94:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar5, "__option", lVar1, 0);
    }
    cVar2 = __istring(param_1, &DAT_0011763b);
    if (cVar2 != '\0') {
        iVar3 = 0;
        do {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = h16(param_1);
            if ((cVar2 == '\0') || (cVar2 = __icar(param_1, 0x3a), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                *param_1 = lVar7;
                if ((code*)param_1[1] == (code*)0x0) goto LAB_00101fcb;
                (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
                *param_1 = lVar7;
                if (iVar3 != 3) goto LAB_00101fcb;
                break;
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 != 3);
        cVar2 = ls32(param_1);
        if (cVar2 != '\0') goto LAB_00101d6c;
    }
LAB_00101fcb:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    *param_1 = lVar1;
    cVar2 = h16(param_1);
    if (cVar2 == '\0') {
        pcVar6 = (code*)param_1[1];
        *param_1 = lVar1;
        uVar5 = 0;
    }
    else {
        iVar3 = 2;
        do {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = __icar(param_1, 0x3a);
            if ((cVar2 == '\0') || (cVar2 = h16(param_1), cVar2 == '\0')) {
                pcVar6 = (code*)param_1[1];
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                *param_1 = lVar7;
                if (pcVar6 != (code*)0x0) {
                    (*pcVar6)(param_1, 0, "__group", lVar7, 0);
                    pcVar6 = (code*)param_1[1];
                }
                *param_1 = lVar7;
                uVar5 = 1;
                goto LAB_00101fed;
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
            }
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        uVar5 = 1;
        pcVar6 = (code*)param_1[1];
    }
LAB_00101fed:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar5, "__option", lVar1, 0);
    }
    cVar2 = __istring(param_1, &DAT_0011763b);
    if (cVar2 != '\0') {
        iVar3 = 0;
        do {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = h16(param_1);
            if ((cVar2 == '\0') || (cVar2 = __icar(param_1, 0x3a), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                *param_1 = lVar7;
                if ((code*)param_1[1] == (code*)0x0) goto LAB_00102024;
                (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
                *param_1 = lVar7;
                if (iVar3 != 2) goto LAB_00102024;
                break;
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 != 2);
        cVar2 = ls32(param_1);
        if (cVar2 != '\0') goto LAB_00101d6c;
    }
LAB_00102024:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    *param_1 = lVar1;
    cVar2 = h16(param_1);
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        uVar5 = 0;
        pcVar6 = (code*)param_1[1];
    }
    else {
        iVar3 = 3;
        do {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = __icar(param_1, 0x3a);
            if ((cVar2 == '\0') || (cVar2 = h16(param_1), cVar2 == '\0')) {
                pcVar6 = (code*)param_1[1];
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                *param_1 = lVar7;
                if (pcVar6 != (code*)0x0) {
                    (*pcVar6)(param_1, 0, "__group", lVar7, 0);
                    pcVar6 = (code*)param_1[1];
                }
                *param_1 = lVar7;
                uVar5 = 1;
                goto LAB_0010209b;
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
            }
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        uVar5 = 1;
        pcVar6 = (code*)param_1[1];
    }
LAB_0010209b:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar5, "__option", lVar1, 0);
    }
    cVar2 = __istring(param_1, &DAT_0011763b);
    if ((((cVar2 == '\0') || (cVar2 = h16(param_1), cVar2 == '\0')) ||
        (cVar2 = __icar(param_1, 0x3a), cVar2 == '\0')) || (cVar2 = ls32(param_1), cVar2 == '\0')) {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        *param_1 = lVar1;
        cVar2 = h16(param_1);
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            uVar5 = 0;
            pcVar6 = (code*)param_1[1];
        }
        else {
            iVar3 = 4;
            do {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar7 = *param_1;
                cVar2 = __icar(param_1, 0x3a);
                if ((cVar2 == '\0') || (cVar2 = h16(param_1), cVar2 == '\0')) {
                    pcVar6 = (code*)param_1[1];
                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                    *param_1 = lVar7;
                    if (pcVar6 != (code*)0x0) {
                        (*pcVar6)(param_1, 0, "__group", lVar7, 0);
                        pcVar6 = (code*)param_1[1];
                    }
                    *param_1 = lVar7;
                    uVar5 = 1;
                    goto LAB_00102149;
                }
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
                }
                iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            uVar5 = 1;
            pcVar6 = (code*)param_1[1];
        }
    LAB_00102149:
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar6 != (code*)0x0) {
            (*pcVar6)(param_1, uVar5, "__option", lVar1, 0);
        }
        cVar2 = __istring(param_1, &DAT_0011763b);
        if ((cVar2 == '\0') || (cVar2 = ls32(param_1), cVar2 == '\0')) {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar1;
            cVar2 = h16(param_1);
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                uVar5 = 0;
                pcVar6 = (code*)param_1[1];
            }
            else {
                iVar3 = 5;
                do {
                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                    lVar7 = *param_1;
                    cVar2 = __icar(param_1, 0x3a);
                    if ((cVar2 == '\0') || (cVar2 = h16(param_1), cVar2 == '\0')) {
                        pcVar6 = (code*)param_1[1];
                        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                        *param_1 = lVar7;
                        if (pcVar6 != (code*)0x0) {
                            (*pcVar6)(param_1, 0, "__group", lVar7, 0);
                            pcVar6 = (code*)param_1[1];
                        }
                        *param_1 = lVar7;
                        uVar5 = 1;
                        goto LAB_001021f7;
                    }
                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
                    }
                    iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
                uVar5 = 1;
                pcVar6 = (code*)param_1[1];
            }
        LAB_001021f7:
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar6 != (code*)0x0) {
                (*pcVar6)(param_1, uVar5, "__option", lVar1, 0);
            }
            cVar2 = __istring(param_1, &DAT_0011763b);
            if ((cVar2 == '\0') || (cVar2 = h16(param_1), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                *param_1 = lVar1;
                cVar2 = h16(param_1);
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    uVar5 = 0;
                    pcVar6 = (code*)param_1[1];
                }
                else {
                    iVar3 = 6;
                    do {
                        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                        lVar7 = *param_1;
                        cVar2 = __icar(param_1, 0x3a);
                        if ((cVar2 == '\0') || (cVar2 = h16(param_1), cVar2 == '\0')) {
                            pcVar6 = (code*)param_1[1];
                            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                            *param_1 = lVar7;
                            if (pcVar6 != (code*)0x0) {
                                (*pcVar6)(param_1, 0, "__group", lVar7, 0);
                                pcVar6 = (code*)param_1[1];
                            }
                            *param_1 = lVar7;
                            uVar5 = 1;
                            goto LAB_001022a5;
                        }
                        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                        if ((code*)param_1[1] != (code*)0x0) {
                            (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar7, 0);
                        }
                        iVar3 = iVar3 + -1;
                    } while (iVar3 != 0);
                    uVar5 = 1;
                    pcVar6 = (code*)param_1[1];
                }
            LAB_001022a5:
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if (pcVar6 != (code*)0x0) {
                    (*pcVar6)(param_1, uVar5, "__option", lVar1, 0);
                }
                cVar2 = __istring(param_1, &DAT_0011763b);
            }
        }
    }
LAB_00101d6c:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "IPv6address", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int path_empty(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "");
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "path_empty", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int pct_encoded(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __icar(param_1, 0x25);
    if (cVar2 != '\0') {
        cVar2 = __hexdig(param_1);
        if (cVar2 != '\0') {
            cVar2 = __hexdig(param_1);
            iVar3 = (int)cVar2;
            goto LAB_00102890;
        }
    }
    iVar3 = 0;
LAB_00102890:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "pct_encoded", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int unreserved(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __alpha();
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __digit(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __icar(param_1, 0x2d);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __icar(param_1, 0x2e);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __icar(param_1, 0x5f);
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __icar(param_1, 0x7e);
                        iVar3 = (int)cVar2;
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "unreserved", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int gen_delims(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __icar(param_1, 0x3a);
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __icar(param_1, 0x2f);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __icar(param_1, 0x3f);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __icar(param_1, 0x23);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __icar(param_1, 0x5b);
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __icar(param_1, 0x5d);
                        iVar3 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = __icar(param_1, 0x40);
                            iVar3 = (int)cVar2;
                        }
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "gen_delims", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int sub_delims(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __icar(param_1, 0x21);
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __icar(param_1, 0x24);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __icar(param_1, 0x26);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __icar(param_1, 0x27);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __icar(param_1, 0x28);
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __icar(param_1, 0x29);
                        iVar3 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = __icar(param_1, 0x2a);
                            iVar3 = (int)cVar2;
                            if (cVar2 == '\0') {
                                *param_1 = lVar1;
                                cVar2 = __icar(param_1, 0x2b);
                                iVar3 = (int)cVar2;
                                if (cVar2 == '\0') {
                                    *param_1 = lVar1;
                                    cVar2 = __icar(param_1, 0x2c);
                                    iVar3 = (int)cVar2;
                                    if (cVar2 == '\0') {
                                        *param_1 = lVar1;
                                        cVar2 = __icar(param_1, 0x3b);
                                        iVar3 = (int)cVar2;
                                        if (cVar2 == '\0') {
                                            *param_1 = lVar1;
                                            cVar2 = __icar(param_1, 0x3d);
                                            iVar3 = (int)cVar2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "sub_delims", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined8 userinfo(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = unreserved(param_1);
        if (cVar2 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar4;
            cVar2 = __icar(param_1, 0x25);
            if ((cVar2 == '\0') || (cVar2 = __hexdig(param_1), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "pct_encoded", lVar4, *param_1 - lVar4);
                }
            }
            else {
                cVar2 = __hexdig(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar2, "pct_encoded", lVar4, *param_1 - lVar4);
                }
                if (cVar2 != '\0') goto LAB_00102c20;
            }
            *param_1 = lVar4;
            cVar2 = sub_delims(param_1);
            if (cVar2 == '\0') {
                *param_1 = lVar4;
                cVar2 = __icar(param_1, 0x3a);
                if (cVar2 == '\0') {
                    iVar3 = *(int*)(param_1 + 2);
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = iVar3 + -1;
                    if ((code*)param_1[1] == (code*)0x0) {
                        *param_1 = lVar4;
                        *(int*)(param_1 + 2) = iVar3 + -2;
                    }
                    else {
                        (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                        *param_1 = lVar4;
                        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                        if ((code*)param_1[1] != (code*)0x0) {
                            (*(code*)param_1[1])(param_1, 1, "userinfo", lVar1, lVar4 - lVar1);
                        }
                    }
                    return 1;
                }
            }
        }
    LAB_00102c20:
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar4, 0);
            iVar3 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
    } while (true);
}



uint IPvFuture(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    uint uVar5;
    int iVar6;
    int iVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x56);
    if (cVar3 == '\0') {
        iVar4 = *(int*)(param_1 + 2);
    }
    else {
        uVar5 = 0;
        while (true) {
            lVar2 = *param_1;
            cVar3 = __hexdig(param_1);
            if (cVar3 == '\0') break;
            uVar5 = uVar5 + 1;
        }
        *param_1 = lVar2;
        if (uVar5 == 0) {
            iVar4 = *(int*)(param_1 + 2);
            pcVar8 = (code*)param_1[1];
            goto LAB_00102ee9;
        }
        cVar3 = __icar(param_1, 0x2e);
        iVar4 = *(int*)(param_1 + 2);
        if (cVar3 != '\0') {
            iVar6 = 0;
            do {
                lVar2 = *param_1;
                *(int*)(param_1 + 2) = iVar4 + 1;
                cVar3 = unreserved(param_1);
                iVar7 = (int)cVar3;
                if (cVar3 == '\0') {
                    *param_1 = lVar2;
                    cVar3 = sub_delims(param_1, iVar7);
                    iVar7 = (int)cVar3;
                    if (cVar3 == '\0') {
                        *param_1 = lVar2;
                        cVar3 = __icar(param_1, 0x3a);
                        iVar7 = (int)cVar3;
                        if (cVar3 == '\0') goto code_r0x00102e94;
                    }
                }
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, iVar7, "__group", lVar2, 0);
                    iVar4 = *(int*)(param_1 + 2);
                }
                iVar6 = iVar6 + 1;
            } while (true);
        }
    }
    pcVar8 = (code*)param_1[1];
    uVar5 = 0;
    goto LAB_00102ee9;
code_r0x00102e94:
    pcVar8 = (code*)param_1[1];
    *param_1 = lVar2;
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, 0, "__group", lVar2, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    *param_1 = lVar2;
    uVar5 = (uint)(0 < iVar6);
LAB_00102ee9:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, uVar5, "IPvFuture", lVar1, *param_1 - lVar1);
    }
    return uVar5;
}



int IP_literal(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x5b);
    iVar4 = *(int*)(param_1 + 2) + 1;
    *(int*)(param_1 + 2) = iVar4;
    if (cVar3 == '\0') {
    LAB_00102f57:
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return 0;
        }
        (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        iVar5 = 0;
    }
    else {
        lVar2 = *param_1;
        cVar3 = IPv6address(param_1);
        iVar4 = (int)cVar3;
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = IPvFuture(param_1, iVar4);
            iVar4 = (int)cVar3;
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                iVar4 = *(int*)(param_1 + 2);
                goto LAB_00102f57;
            }
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar4, "__group", lVar1, 0);
        }
        cVar3 = __icar(param_1, 0x5d);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        iVar5 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, iVar5, "IP_literal", lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



undefined8 reg_name(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = unreserved(param_1);
        if (cVar2 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar4;
            cVar2 = __icar(param_1, 0x25);
            if ((cVar2 == '\0') || (cVar2 = __hexdig(param_1), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "pct_encoded", lVar4, *param_1 - lVar4);
                }
            }
            else {
                cVar2 = __hexdig(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar2, "pct_encoded", lVar4, *param_1 - lVar4);
                }
                if (cVar2 != '\0') goto LAB_00103080;
            }
            *param_1 = lVar4;
            cVar2 = sub_delims(param_1);
            if (cVar2 == '\0') {
                iVar3 = *(int*)(param_1 + 2);
                *param_1 = lVar4;
                *(int*)(param_1 + 2) = iVar3 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = iVar3 + -2;
                }
                else {
                    (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "reg_name", lVar1, lVar4 - lVar1);
                    }
                }
                return 1;
            }
        }
    LAB_00103080:
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar4, 0);
            iVar3 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
    } while (true);
}



int host(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x5b);
    iVar4 = *(int*)(param_1 + 2) + 1;
    *(int*)(param_1 + 2) = iVar4;
    if (cVar3 == '\0') {
    LAB_0010322b:
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
        }
        else {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            iVar4 = 0;
            if (pcVar5 != (code*)0x0) goto LAB_00103268;
        }
    }
    else {
        lVar2 = *param_1;
        cVar3 = IPv6address(param_1);
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = IPvFuture(param_1);
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                iVar4 = *(int*)(param_1 + 2);
                goto LAB_0010322b;
            }
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar1, 0);
        }
        cVar3 = __icar(param_1, 0x5d);
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar4 = (int)cVar3;
        if (pcVar5 != (code*)0x0) {
        LAB_00103268:
            (*pcVar5)(param_1, (int)(char)iVar4, "IP_literal", lVar1, *param_1 - lVar1);
        }
        if ((char)iVar4 != '\0') goto LAB_0010328d;
    }
    *param_1 = lVar1;
    cVar3 = IPv4address(param_1);
    iVar4 = (int)cVar3;
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        cVar3 = reg_name(param_1);
        iVar4 = (int)cVar3;
    }
LAB_0010328d:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, &__func___2667, lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



undefined8 authority(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = userinfo();
    if ((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x40), cVar3 == '\0')) {
        *param_1 = lVar1;
        uVar7 = 0;
    }
    else {
        uVar7 = 1;
    }
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar7, "__option", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
    }
    lVar2 = *param_1;
    *(int*)(param_1 + 2) = iVar4 + 1;
    cVar3 = IP_literal(param_1);
    if (cVar3 == '\0') {
        *param_1 = lVar2;
        cVar3 = IPv4address(param_1);
        if (cVar3 != '\0') goto LAB_00103400;
        *param_1 = lVar2;
        cVar3 = reg_name(param_1);
        pcVar6 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar6 != (code*)0x0) goto LAB_00103412;
    LAB_00103431:
        if (cVar3 == '\0') {
            pcVar6 = (code*)param_1[1];
            uVar7 = 0;
            goto LAB_0010343d;
        }
    }
    else {
    LAB_00103400:
        pcVar6 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar6 != (code*)0x0) {
        LAB_00103412:
            (*pcVar6)(param_1, (int)cVar3, &__func___2667, lVar2, *param_1 - lVar2);
            iVar4 = *(int*)(param_1 + 2);
            goto LAB_00103431;
        }
    }
    *(int*)(param_1 + 2) = iVar4 + 1;
    lVar2 = *param_1;
    cVar3 = __icar(param_1, 0x3a);
    if ((cVar3 == '\0') || (cVar3 = port(param_1), cVar3 == '\0')) {
        *param_1 = lVar2;
        uVar5 = 0;
    }
    else {
        uVar5 = 1;
    }
    iVar4 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar4 + -2;
        return 1;
    }
    uVar7 = 1;
    (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
    iVar4 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
LAB_0010343d:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, "authority", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



bool segment_nz_nc(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;
    int iVar5;

    iVar5 = 0;
    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = unreserved(param_1);
        if (cVar2 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar4;
            cVar2 = __icar(param_1, 0x25);
            if ((cVar2 == '\0') || (cVar2 = __hexdig(param_1), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "pct_encoded", lVar4, *param_1 - lVar4);
                }
            }
            else {
                cVar2 = __hexdig(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar2, "pct_encoded", lVar4, *param_1 - lVar4);
                }
                if (cVar2 != '\0') goto LAB_001035c0;
            }
            *param_1 = lVar4;
            cVar2 = sub_delims(param_1);
            if (cVar2 == '\0') {
                *param_1 = lVar4;
                cVar2 = __icar(param_1, 0x40);
                if (cVar2 == '\0') {
                    iVar3 = *(int*)(param_1 + 2);
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = iVar3 + -1;
                    if ((code*)param_1[1] == (code*)0x0) {
                        *param_1 = lVar4;
                        *(int*)(param_1 + 2) = iVar3 + -2;
                    }
                    else {
                        (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                        *param_1 = lVar4;
                        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                        if ((code*)param_1[1] != (code*)0x0) {
                            (*(code*)param_1[1])(param_1, 0 < iVar5, "segment_nz_nc", lVar1, lVar4 - lVar1);
                        }
                    }
                    return 0 < iVar5;
                }
            }
        }
    LAB_001035c0:
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar4, 0);
            iVar3 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
        iVar5 = iVar5 + 1;
    } while (true);
}



int pchar(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = unreserved();
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = pct_encoded(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = sub_delims(param_1);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __icar(param_1, 0x3a);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __icar(param_1, 0x40);
                    iVar3 = (int)cVar2;
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "pchar", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined8 path_abempty(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;
    long lVar6;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar5 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2f);
        if (cVar3 == '\0') break;
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar6 = lVar2;
        while (true) {
            cVar3 = pchar(param_1);
            if (cVar3 == '\0') break;
            lVar6 = *param_1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *param_1 = lVar6;
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar4 = iVar4 + -2;
            *(int*)(param_1 + 2) = iVar4;
        }
        else {
            (*(code*)param_1[1])(param_1, 1, "segment", lVar2, lVar6 - lVar2);
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar5, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
        }
        lVar5 = *param_1;
    }
    iVar4 = *(int*)(param_1 + 2);
    *param_1 = lVar5;
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *param_1 = lVar5;
        *(int*)(param_1 + 2) = iVar4 + -2;
    }
    else {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar5, 0);
        *param_1 = lVar5;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "path_abempty", lVar1, lVar5 - lVar1);
        }
    }
    return 1;
}



int reserved(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar2 = *param_1;
    cVar3 = __icar(param_1, 0x3a);
    iVar4 = (int)cVar3;
    if (cVar3 == '\0') {
        *param_1 = lVar2;
        cVar3 = __icar(param_1, 0x2f);
        iVar4 = (int)cVar3;
        if (cVar3 != '\0') goto LAB_001039d5;
        *param_1 = lVar2;
        cVar3 = __icar(param_1, 0x3f);
        iVar4 = (int)cVar3;
        if (cVar3 != '\0') goto LAB_001039d5;
        *param_1 = lVar2;
        cVar3 = __icar(param_1, 0x23);
        iVar4 = (int)cVar3;
        if (cVar3 != '\0') goto LAB_001039d5;
        *param_1 = lVar2;
        cVar3 = __icar(param_1, 0x5b);
        iVar4 = (int)cVar3;
        if (cVar3 != '\0') goto LAB_001039d5;
        *param_1 = lVar2;
        cVar3 = __icar(param_1, 0x5d);
        iVar4 = (int)cVar3;
        if (cVar3 != '\0') goto LAB_001039d5;
        *param_1 = lVar2;
        cVar3 = __icar(param_1, 0x40);
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar4 = (int)cVar3;
        if (pcVar5 == (code*)0x0) goto LAB_00103a07;
    }
    else {
    LAB_001039d5:
        iVar1 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar1 + -1;
        if (pcVar5 == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar1 + -2;
            return iVar4;
        }
    }
    (*pcVar5)(param_1, (int)(char)iVar4, "gen_delims", lVar2, *param_1 - lVar2);
LAB_00103a07:
    if ((char)iVar4 == '\0') {
        *param_1 = lVar2;
        cVar3 = sub_delims(param_1);
        iVar4 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "reserved", lVar2, *param_1 - lVar2);
    }
    return iVar4;
}



undefined8 segment(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    long lVar4;
    code* pcVar5;

    lVar2 = *param_1;
    iVar1 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar2;
    do {
        *(int*)(param_1 + 2) = iVar1 + 1;
        cVar3 = unreserved(param_1);
        if (cVar3 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x25);
            if ((cVar3 == '\0') || (cVar3 = __hexdig(param_1), cVar3 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "pct_encoded", lVar4, *param_1 - lVar4);
                }
            }
            else {
                cVar3 = __hexdig(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "pct_encoded", lVar4, *param_1 - lVar4);
                }
                if (cVar3 != '\0') goto LAB_00103b50;
            }
            *param_1 = lVar4;
            cVar3 = sub_delims(param_1);
            if (cVar3 != '\0') goto LAB_00103b50;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x3a);
            if (cVar3 != '\0') goto LAB_00103b50;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x40);
            pcVar5 = (code*)param_1[1];
            iVar1 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar1;
            if (pcVar5 != (code*)0x0) goto LAB_00103b62;
        LAB_00103b7d:
            if (cVar3 == '\0') {
                *param_1 = lVar4;
                *(int*)(param_1 + 2) = iVar1 + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "segment", lVar2, lVar4 - lVar2);
                }
                return 1;
            }
        }
        else {
        LAB_00103b50:
            pcVar5 = (code*)param_1[1];
            iVar1 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar1;
            if (pcVar5 != (code*)0x0) {
            LAB_00103b62:
                (*pcVar5)(param_1, (int)cVar3, "pchar", lVar4, *param_1 - lVar4);
                iVar1 = *(int*)(param_1 + 2);
                goto LAB_00103b7d;
            }
        }
        lVar4 = *param_1;
    } while (true);
}



undefined8 path_noscheme(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    undefined8 uVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = segment_nz_nc();
    if (cVar3 == '\0') {
        iVar4 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        iVar4 = *(int*)(param_1 + 2);
        while (true) {
            lVar2 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = __icar(param_1, 0x2f);
            if (cVar3 == '\0') break;
            cVar3 = segment(param_1);
            if (cVar3 == '\0') break;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
        }
        pcVar5 = (code*)param_1[1];
        *param_1 = lVar2;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar5 != (code*)0x0) {
            (*pcVar5)(param_1, 0, "__group", lVar2, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
        }
        *param_1 = lVar2;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar6, "path_noscheme", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



bool segment_nz(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    long lVar6;

    iVar4 = 0;
    lVar2 = *param_1;
    iVar1 = *(int*)(param_1 + 2) + 1;
    lVar6 = lVar2;
    do {
        *(int*)(param_1 + 2) = iVar1 + 1;
        cVar3 = unreserved(param_1);
        if (cVar3 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar6;
            cVar3 = __icar(param_1, 0x25);
            if ((cVar3 == '\0') || (cVar3 = __hexdig(param_1), cVar3 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "pct_encoded", lVar6, *param_1 - lVar6);
                }
            }
            else {
                cVar3 = __hexdig(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "pct_encoded", lVar6, *param_1 - lVar6);
                }
                if (cVar3 != '\0') goto LAB_00103e30;
            }
            *param_1 = lVar6;
            cVar3 = sub_delims(param_1);
            if (cVar3 != '\0') goto LAB_00103e30;
            *param_1 = lVar6;
            cVar3 = __icar(param_1, 0x3a);
            if (cVar3 != '\0') goto LAB_00103e30;
            *param_1 = lVar6;
            cVar3 = __icar(param_1, 0x40);
            pcVar5 = (code*)param_1[1];
            iVar1 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar1;
            if (pcVar5 != (code*)0x0) goto LAB_00103e42;
        LAB_00103e5d:
            if (cVar3 == '\0') {
                *param_1 = lVar6;
                *(int*)(param_1 + 2) = iVar1 + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0 < iVar4, "segment_nz", lVar2, lVar6 - lVar2);
                }
                return 0 < iVar4;
            }
        }
        else {
        LAB_00103e30:
            pcVar5 = (code*)param_1[1];
            iVar1 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar1;
            if (pcVar5 != (code*)0x0) {
            LAB_00103e42:
                (*pcVar5)(param_1, (int)cVar3, "pchar", lVar6, *param_1 - lVar6);
                iVar1 = *(int*)(param_1 + 2);
                goto LAB_00103e5d;
            }
        }
        lVar6 = *param_1;
        iVar4 = iVar4 + 1;
    } while (true);
}



undefined8 path_absolute(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    undefined8 uVar6;
    code* pcVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x2f);
    if (cVar3 == '\0') {
        iVar4 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
        uVar5 = 0;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = segment_nz(param_1);
        if (cVar3 == '\0') {
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
            uVar6 = 0;
            *param_1 = lVar2;
            *(int*)(param_1 + 2) = iVar4 + -1;
        }
        else {
            iVar4 = *(int*)(param_1 + 2);
            while (true) {
                lVar2 = *param_1;
                *(int*)(param_1 + 2) = iVar4 + 1;
                cVar3 = __icar(param_1, 0x2f);
                if ((cVar3 == '\0') || (cVar3 = segment(param_1), cVar3 == '\0')) break;
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar2, 0);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
            pcVar7 = (code*)param_1[1];
            *param_1 = lVar2;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar7 != (code*)0x0) {
                (*pcVar7)(param_1, 0, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar7 = (code*)param_1[1];
            }
            *param_1 = lVar2;
            uVar6 = 1;
            *(int*)(param_1 + 2) = iVar4 + -1;
        }
        if (pcVar7 == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return 1;
        }
        uVar5 = 1;
        (*pcVar7)(param_1, uVar6, "__option", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar5, "path_absolute", lVar1, *param_1 - lVar1);
    }
    return uVar5;
}



int relative_part(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, &DAT_0011772b);
    if ((cVar2 != '\0') && (cVar2 = authority(param_1), cVar2 != '\0')) {
        cVar2 = path_abempty(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 != '\0') goto LAB_001041b4;
    }
    *param_1 = lVar1;
    cVar2 = path_absolute(param_1);
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = path_noscheme(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = path_empty(param_1);
            iVar3 = (int)cVar2;
        }
    }
LAB_001041b4:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "relative_part", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



bool path_rootless(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    code* pcVar5;
    long lVar6;

    iVar4 = 0;
    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 2;
    lVar6 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = unreserved(param_1);
        if (cVar2 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar6;
            cVar2 = __icar(param_1, 0x25);
            if ((cVar2 == '\0') || (cVar2 = __hexdig(param_1), cVar2 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "pct_encoded", lVar6, *param_1 - lVar6);
                }
            }
            else {
                cVar2 = __hexdig(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar2, "pct_encoded", lVar6, *param_1 - lVar6);
                }
                if (cVar2 != '\0') goto LAB_00104270;
            }
            *param_1 = lVar6;
            cVar2 = sub_delims(param_1);
            if (cVar2 != '\0') goto LAB_00104270;
            *param_1 = lVar6;
            cVar2 = __icar(param_1, 0x3a);
            if (cVar2 != '\0') goto LAB_00104270;
            *param_1 = lVar6;
            cVar2 = __icar(param_1, 0x40);
            pcVar5 = (code*)param_1[1];
            iVar3 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar3;
            if (pcVar5 != (code*)0x0) goto LAB_00104282;
        LAB_0010429d:
            if (cVar2 == '\0') break;
        }
        else {
        LAB_00104270:
            pcVar5 = (code*)param_1[1];
            iVar3 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar3;
            if (pcVar5 != (code*)0x0) {
            LAB_00104282:
                (*pcVar5)(param_1, (int)cVar2, "pchar", lVar6, *param_1 - lVar6);
                iVar3 = *(int*)(param_1 + 2);
                goto LAB_0010429d;
            }
        }
        lVar6 = *param_1;
        iVar4 = iVar4 + 1;
    } while (true);
    *param_1 = lVar6;
    cVar2 = 0 < iVar4;
    iVar3 = iVar3 + -1;
    *(int*)(param_1 + 2) = iVar3;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, cVar2, "segment_nz", lVar1, lVar6 - lVar1);
        iVar3 = *(int*)(param_1 + 2);
    }
    if (iVar4 == 0) {
        pcVar5 = (code*)param_1[1];
    }
    else {
        while (true) {
            iVar3 = iVar3 + 1;
            lVar6 = *param_1;
            *(int*)(param_1 + 2) = iVar3;
            if (cVar2 == '\0') break;
            cVar2 = __icar(param_1, 0x2f);
            if ((cVar2 == '\0') || (cVar2 = segment(param_1), cVar2 == '\0')) {
                *param_1 = lVar6;
                iVar3 = *(int*)(param_1 + 2);
                break;
            }
            iVar3 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar3;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar2, "__group", lVar6, 0);
                iVar3 = *(int*)(param_1 + 2);
            }
        }
        pcVar5 = (code*)param_1[1];
        iVar3 = iVar3 + -1;
        *(int*)(param_1 + 2) = iVar3;
        if (pcVar5 != (code*)0x0) {
            (*pcVar5)(param_1, 0, "__group", lVar6, 0);
            iVar3 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
        }
        *param_1 = lVar6;
        cVar2 = true;
    }
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, cVar2, "path_rootless", lVar1, *param_1 - lVar1);
    }
    return (bool)cVar2;
}



int hier_part(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, &DAT_0011772b);
    if ((cVar2 != '\0') && (cVar2 = authority(param_1), cVar2 != '\0')) {
        cVar2 = path_abempty(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 != '\0') goto LAB_00104544;
    }
    *param_1 = lVar1;
    cVar2 = path_absolute(param_1);
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = path_rootless(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = path_empty(param_1);
            iVar3 = (int)cVar2;
        }
    }
LAB_00104544:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "hier_part", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int path(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = path_abempty();
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = path_absolute(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = path_noscheme(param_1);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = path_rootless(param_1);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = path_empty(param_1);
                    iVar3 = (int)cVar2;
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, &__func___2970, lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined8 query(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    long lVar4;
    code* pcVar5;

    lVar2 = *param_1;
    iVar1 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar2;
    do {
        *(int*)(param_1 + 2) = iVar1 + 2;
        cVar3 = unreserved(param_1);
        if (cVar3 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x25);
            if ((cVar3 == '\0') || (cVar3 = __hexdig(param_1), cVar3 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "pct_encoded", lVar4, *param_1 - lVar4);
                }
            }
            else {
                cVar3 = __hexdig(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "pct_encoded", lVar4, *param_1 - lVar4);
                }
                if (cVar3 != '\0') goto LAB_001046a0;
            }
            *param_1 = lVar4;
            cVar3 = sub_delims(param_1);
            if (cVar3 != '\0') goto LAB_001046a0;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x3a);
            if (cVar3 != '\0') goto LAB_001046a0;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x40);
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 != (code*)0x0) goto LAB_001046ad;
        LAB_001046c5:
            if (cVar3 == '\0') {
                *param_1 = lVar4;
                cVar3 = __icar(param_1, 0x2f);
                if (cVar3 == '\0') {
                    *param_1 = lVar4;
                    cVar3 = __icar(param_1, 0x3f);
                    if (cVar3 == '\0') {
                        iVar1 = *(int*)(param_1 + 2);
                        *param_1 = lVar4;
                        *(int*)(param_1 + 2) = iVar1 + -1;
                        if ((code*)param_1[1] == (code*)0x0) {
                            *param_1 = lVar4;
                            *(int*)(param_1 + 2) = iVar1 + -2;
                        }
                        else {
                            (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                            *param_1 = lVar4;
                            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                            if ((code*)param_1[1] != (code*)0x0) {
                                (*(code*)param_1[1])(param_1, 1, "query", lVar2, lVar4 - lVar2);
                            }
                        }
                        return 1;
                    }
                }
            }
            pcVar5 = (code*)param_1[1];
        }
        else {
        LAB_001046a0:
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 != (code*)0x0) {
            LAB_001046ad:
                (*pcVar5)(param_1, (int)cVar3, "pchar", lVar4, *param_1 - lVar4);
                goto LAB_001046c5;
            }
        }
        iVar1 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar1;
        if (pcVar5 != (code*)0x0) {
            (*pcVar5)(param_1, (int)cVar3, "__group", lVar4);
            iVar1 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
    } while (true);
}



undefined8 absolute_URI(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    undefined8 uVar6;
    code* pcVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = scheme();
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = hier_part(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = __icar(param_1, 0x3f);
                if (cVar3 == '\0') {
                LAB_00104969:
                    *param_1 = lVar2;
                    uVar6 = 0;
                }
                else {
                    cVar3 = query(param_1);
                    if (cVar3 == '\0') goto LAB_00104969;
                    uVar6 = 1;
                }
                iVar4 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar4 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *(int*)(param_1 + 2) = iVar4 + -2;
                    return 1;
                }
                uVar5 = 1;
                (*(code*)param_1[1])(param_1, uVar6, "__option", lVar1, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar7 = (code*)param_1[1];
                goto LAB_00104902;
            }
        }
    }
    iVar4 = *(int*)(param_1 + 2);
    pcVar7 = (code*)param_1[1];
    uVar5 = 0;
LAB_00104902:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar5, "absolute_URI", lVar1, *param_1 - lVar1);
    }
    return uVar5;
}



undefined8 fragment(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    long lVar4;
    code* pcVar5;

    lVar2 = *param_1;
    iVar1 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar2;
    do {
        *(int*)(param_1 + 2) = iVar1 + 2;
        cVar3 = unreserved(param_1);
        if (cVar3 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x25);
            if ((cVar3 == '\0') || (cVar3 = __hexdig(param_1), cVar3 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "pct_encoded", lVar4, *param_1 - lVar4);
                }
            }
            else {
                cVar3 = __hexdig(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "pct_encoded", lVar4, *param_1 - lVar4);
                }
                if (cVar3 != '\0') goto LAB_00104a10;
            }
            *param_1 = lVar4;
            cVar3 = sub_delims(param_1);
            if (cVar3 != '\0') goto LAB_00104a10;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x3a);
            if (cVar3 != '\0') goto LAB_00104a10;
            *param_1 = lVar4;
            cVar3 = __icar(param_1, 0x40);
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 != (code*)0x0) goto LAB_00104a1d;
        LAB_00104a35:
            if (cVar3 == '\0') {
                *param_1 = lVar4;
                cVar3 = __icar(param_1, 0x2f);
                if (cVar3 == '\0') {
                    *param_1 = lVar4;
                    cVar3 = __icar(param_1, 0x3f);
                    if (cVar3 == '\0') {
                        iVar1 = *(int*)(param_1 + 2);
                        *param_1 = lVar4;
                        *(int*)(param_1 + 2) = iVar1 + -1;
                        if ((code*)param_1[1] == (code*)0x0) {
                            *param_1 = lVar4;
                            *(int*)(param_1 + 2) = iVar1 + -2;
                        }
                        else {
                            (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                            *param_1 = lVar4;
                            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                            if ((code*)param_1[1] != (code*)0x0) {
                                (*(code*)param_1[1])(param_1, 1, "fragment", lVar2, lVar4 - lVar2);
                            }
                        }
                        return 1;
                    }
                }
            }
            pcVar5 = (code*)param_1[1];
        }
        else {
        LAB_00104a10:
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 != (code*)0x0) {
            LAB_00104a1d:
                (*pcVar5)(param_1, (int)cVar3, "pchar", lVar4, *param_1 - lVar4);
                goto LAB_00104a35;
            }
        }
        iVar1 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar1;
        if (pcVar5 != (code*)0x0) {
            (*pcVar5)(param_1, (int)cVar3, "__group", lVar4);
            iVar1 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
    } while (true);
}



undefined8 URI(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = scheme();
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = hier_part(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = __icar(param_1, 0x3f);
                if (cVar3 == '\0') {
                LAB_00104ce7:
                    *param_1 = lVar2;
                    uVar5 = 0;
                }
                else {
                    cVar3 = query(param_1);
                    if (cVar3 == '\0') goto LAB_00104ce7;
                    uVar5 = 1;
                }
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
                    iVar4 = *(int*)(param_1 + 2);
                }
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar2 = *param_1;
                cVar3 = __icar(param_1, 0x23);
                if (cVar3 == '\0') {
                LAB_00104d32:
                    *param_1 = lVar2;
                    uVar5 = 0;
                }
                else {
                    cVar3 = fragment(param_1);
                    if (cVar3 == '\0') goto LAB_00104d32;
                    uVar5 = 1;
                }
                iVar4 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar4 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *(int*)(param_1 + 2) = iVar4 + -2;
                    return 1;
                }
                uVar7 = 1;
                (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
                goto LAB_00104c73;
            }
        }
    }
    iVar4 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
    uVar7 = 0;
LAB_00104c73:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, &__func___2512, lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



undefined8 relative_ref(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, &DAT_0011772b);
    if (((cVar3 == '\0') || (cVar3 = authority(param_1), cVar3 == '\0')) ||
        (cVar3 = path_abempty(param_1), cVar3 == '\0')) {
        *param_1 = lVar1;
        cVar3 = path_absolute(param_1);
        if (cVar3 != '\0') goto LAB_00104dfc;
        *param_1 = lVar1;
        cVar3 = path_noscheme(param_1);
        if (cVar3 != '\0') goto LAB_00104dfc;
        *param_1 = lVar1;
        cVar3 = path_empty(param_1);
        pcVar6 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar6 != (code*)0x0) goto LAB_00104e0e;
    LAB_00104e2d:
        if (cVar3 == '\0') {
            pcVar6 = (code*)param_1[1];
            uVar7 = 0;
            goto LAB_00104e39;
        }
    }
    else {
    LAB_00104dfc:
        pcVar6 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar6 != (code*)0x0) {
        LAB_00104e0e:
            (*pcVar6)(param_1, (int)cVar3, "relative_part", lVar1, *param_1 - lVar1);
            iVar4 = *(int*)(param_1 + 2);
            goto LAB_00104e2d;
        }
    }
    *(int*)(param_1 + 2) = iVar4 + 1;
    lVar2 = *param_1;
    cVar3 = __icar(param_1, 0x3f);
    if ((cVar3 == '\0') || (cVar3 = query(param_1), cVar3 == '\0')) {
        *param_1 = lVar2;
        uVar7 = 0;
    }
    else {
        uVar7 = 1;
    }
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar7, "__option", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
    }
    *(int*)(param_1 + 2) = iVar4 + 1;
    lVar2 = *param_1;
    cVar3 = __icar(param_1, 0x23);
    if ((cVar3 == '\0') || (cVar3 = fragment(param_1), cVar3 == '\0')) {
        *param_1 = lVar2;
        uVar5 = 0;
    }
    else {
        uVar5 = 1;
    }
    iVar4 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar4 + -2;
        return 1;
    }
    uVar7 = 1;
    (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
    iVar4 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
LAB_00104e39:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, "relative_ref", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



int URI_reference(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = URI();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = relative_ref(param_1);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "URI_reference", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int language_range(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    long lVar5;
    code* pcVar6;
    long lVar7;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar5 = lVar1;
    while (cVar2 = __alpha(param_1), cVar2 != '\0') {
        iVar3 = iVar3 + 1;
        if (iVar3 == 8) goto LAB_0010508d;
        lVar5 = *param_1;
    }
    if (iVar3 - 1U < 8) {
        *param_1 = lVar5;
    LAB_0010508d:
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar5 = *param_1;
        while (cVar2 = __icar(param_1, 0x2d), cVar2 != '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = __alpha(param_1);
            if (cVar2 == '\0') {
                *param_1 = lVar7;
                cVar2 = __digit(param_1);
                pcVar6 = (code*)param_1[1];
                iVar3 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar3;
                if (pcVar6 != (code*)0x0) goto LAB_0010518e;
            LAB_001051a9:
                if (cVar2 == '\0') {
                    pcVar6 = (code*)param_1[1];
                    goto LAB_001050be;
                }
            }
            else {
                pcVar6 = (code*)param_1[1];
                iVar3 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar3;
                if (pcVar6 != (code*)0x0) {
                LAB_0010518e:
                    (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
                    iVar3 = *(int*)(param_1 + 2);
                    goto LAB_001051a9;
                }
            }
            *(int*)(param_1 + 2) = iVar3 + 1;
            lVar7 = *param_1;
            cVar2 = __alpha(param_1);
            if (cVar2 == '\0') {
                *param_1 = lVar7;
                cVar2 = __digit(param_1);
                pcVar6 = (code*)param_1[1];
                iVar3 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar3;
                if (pcVar6 != (code*)0x0) goto LAB_001051e2;
            LAB_001051fd:
                if (cVar2 != '\0') goto LAB_00105206;
            LAB_001054e8:
                pcVar6 = (code*)param_1[1];
            LAB_001054ec:
                *param_1 = lVar7;
            LAB_00105402:
                *(int*)(param_1 + 2) = iVar3 + -1;
                if (pcVar6 == (code*)0x0) goto LAB_0010540d;
                (*pcVar6)(param_1, 1, "__group", lVar5, 0);
                lVar5 = *param_1;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            }
            else {
                pcVar6 = (code*)param_1[1];
                iVar3 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar3;
                if (pcVar6 != (code*)0x0) {
                LAB_001051e2:
                    (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
                    iVar3 = *(int*)(param_1 + 2);
                    goto LAB_001051fd;
                }
            LAB_00105206:
                *(int*)(param_1 + 2) = iVar3 + 1;
                lVar7 = *param_1;
                cVar2 = __alpha(param_1);
                if (cVar2 == '\0') {
                    *param_1 = lVar7;
                    cVar2 = __digit(param_1);
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) goto LAB_00105236;
                LAB_00105251:
                    if (cVar2 == '\0') goto LAB_001054e8;
                }
                else {
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) {
                    LAB_00105236:
                        (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
                        iVar3 = *(int*)(param_1 + 2);
                        goto LAB_00105251;
                    }
                }
                *(int*)(param_1 + 2) = iVar3 + 1;
                lVar7 = *param_1;
                cVar2 = __alpha(param_1);
                if (cVar2 == '\0') {
                    *param_1 = lVar7;
                    cVar2 = __digit(param_1);
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) goto LAB_0010528a;
                LAB_001052a5:
                    if (cVar2 == '\0') goto LAB_001054e8;
                }
                else {
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) {
                    LAB_0010528a:
                        (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
                        iVar3 = *(int*)(param_1 + 2);
                        goto LAB_001052a5;
                    }
                }
                *(int*)(param_1 + 2) = iVar3 + 1;
                lVar7 = *param_1;
                cVar2 = __alpha(param_1);
                if (cVar2 == '\0') {
                    *param_1 = lVar7;
                    cVar2 = __digit(param_1);
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) goto LAB_001052de;
                LAB_001052f9:
                    if (cVar2 == '\0') goto LAB_001054e8;
                }
                else {
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) {
                    LAB_001052de:
                        (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
                        iVar3 = *(int*)(param_1 + 2);
                        goto LAB_001052f9;
                    }
                }
                *(int*)(param_1 + 2) = iVar3 + 1;
                lVar7 = *param_1;
                cVar2 = __alpha(param_1);
                if (cVar2 == '\0') {
                    *param_1 = lVar7;
                    cVar2 = __digit(param_1);
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) goto LAB_00105332;
                LAB_0010534d:
                    if (cVar2 == '\0') goto LAB_001054e8;
                }
                else {
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) {
                    LAB_00105332:
                        (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
                        iVar3 = *(int*)(param_1 + 2);
                        goto LAB_0010534d;
                    }
                }
                *(int*)(param_1 + 2) = iVar3 + 1;
                lVar7 = *param_1;
                cVar2 = __alpha(param_1);
                if (cVar2 == '\0') {
                    *param_1 = lVar7;
                    cVar2 = __digit(param_1);
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) goto LAB_00105386;
                LAB_001053a1:
                    if (cVar2 == '\0') goto LAB_001054e8;
                }
                else {
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) {
                    LAB_00105386:
                        (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
                        iVar3 = *(int*)(param_1 + 2);
                        goto LAB_001053a1;
                    }
                }
                *(int*)(param_1 + 2) = iVar3 + 1;
                lVar7 = *param_1;
                cVar2 = __alpha(param_1);
                if (cVar2 == '\0') {
                    *param_1 = lVar7;
                    cVar2 = __digit(param_1);
                    pcVar6 = (code*)param_1[1];
                    iVar3 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar3;
                    if (pcVar6 != (code*)0x0) goto LAB_001053da;
                LAB_001053f9:
                    if (cVar2 == '\0') goto LAB_001054ec;
                    goto LAB_00105402;
                }
                pcVar6 = (code*)param_1[1];
                iVar3 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar3;
                if (pcVar6 != (code*)0x0) {
                LAB_001053da:
                    (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
                    iVar3 = *(int*)(param_1 + 2);
                    pcVar6 = (code*)param_1[1];
                    goto LAB_001053f9;
                }
            LAB_0010540d:
                lVar5 = *param_1;
                *(int*)(param_1 + 2) = iVar3;
            }
        }
        iVar3 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
    LAB_001050be:
        *param_1 = lVar5;
        *(int*)(param_1 + 2) = iVar3 + -1;
        if (pcVar6 == (code*)0x0) {
            *param_1 = lVar5;
            *(int*)(param_1 + 2) = iVar3 + -3;
            return 1;
        }
        (*pcVar6)(param_1, 0, "__group", lVar5, 0);
        iVar3 = *(int*)(param_1 + 2);
        *param_1 = lVar5;
        *(int*)(param_1 + 2) = iVar3 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar3 + -2;
            return 1;
        }
        (*(code*)param_1[1])(param_1, 1, "__group", lVar1, 0);
        iVar3 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        iVar4 = 1;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        *param_1 = lVar1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
        }
        *param_1 = lVar1;
        cVar2 = __icar(param_1, 0x2a);
        iVar3 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        iVar4 = (int)cVar2;
    }
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, iVar4, "language_range", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int alphanum(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __alpha();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __digit(param_1);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "alphanum", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined8 extlang(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    long lVar7;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar7 = lVar1;
    do {
        cVar2 = __alpha(param_1);
        if (cVar2 == '\0') {
            *param_1 = lVar7;
            iVar3 = *(int*)(param_1 + 2);
            uVar5 = 0;
            pcVar6 = (code*)param_1[1];
            goto LAB_001057c0;
        }
        iVar3 = iVar3 + 1;
        lVar7 = *param_1;
    } while (iVar3 != 3);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    iVar4 = 2;
    while (true) {
        cVar2 = __icar(param_1, 0x2d);
        if (cVar2 == '\0') break;
        cVar2 = __alpha(param_1);
        if (cVar2 == '\0') break;
        cVar2 = __alpha(param_1);
        if (cVar2 == '\0') break;
        cVar2 = __alpha(param_1);
        if (cVar2 == '\0') break;
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "__group", lVar7);
            iVar3 = *(int*)(param_1 + 2);
        }
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
            pcVar6 = (code*)param_1[1];
            uVar5 = 1;
            goto LAB_001057c0;
        }
        lVar7 = *param_1;
        *(int*)(param_1 + 2) = iVar3 + 1;
    }
    pcVar6 = (code*)param_1[1];
    *param_1 = lVar7;
    iVar3 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar3;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, 0, "__group", lVar7, 0);
        iVar3 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
    }
    *param_1 = lVar7;
    uVar5 = 1;
LAB_001057c0:
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar5, "extlang", lVar1, *param_1 - lVar1);
    }
    return uVar5;
}



bool language(long* param_1)

{
    long lVar1;
    char cVar2;
    bool bVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    long lVar7;

    iVar4 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __alpha(param_1);
    lVar7 = lVar1;
    while (cVar2 != '\0') {
        iVar4 = iVar4 + 1;
        if (iVar4 == 3) goto LAB_001058b0;
        lVar7 = *param_1;
        cVar2 = __alpha(param_1);
    }
    if (iVar4 - 2U < 2) {
        *param_1 = lVar7;
    LAB_001058b0:
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar7 = *param_1;
        cVar2 = __icar(param_1, 0x2d);
        if ((cVar2 == '\0') || (cVar2 = extlang(param_1), cVar2 == '\0')) {
            *param_1 = lVar7;
            uVar5 = 0;
        }
        else {
            uVar5 = 1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return true;
        }
        bVar3 = true;
        (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
    }
    else {
        *param_1 = lVar1;
        iVar4 = 4;
        do {
            cVar2 = __alpha(param_1);
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                iVar4 = 0;
                lVar7 = lVar1;
                goto LAB_0010596b;
            }
            iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        bVar3 = true;
    }
    goto LAB_00105910;
LAB_0010596b:
    cVar2 = __alpha(param_1);
    if (cVar2 == '\0') goto LAB_00105990;
    iVar4 = iVar4 + 1;
    if (iVar4 == 8) {
        bVar3 = true;
        goto LAB_00105986;
    }
    lVar7 = *param_1;
    goto LAB_0010596b;
LAB_00105990:
    *param_1 = lVar7;
    bVar3 = iVar4 - 5U < 4;
LAB_00105986:
    iVar4 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
LAB_00105910:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, bVar3, "language", lVar1, *param_1 - lVar1);
    }
    return bVar3;
}



undefined4 script(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined4 uVar5;

    iVar4 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __alpha(param_1);
    lVar2 = lVar1;
    do {
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            uVar5 = 0;
        LAB_00105a25:
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, uVar5, "script", lVar1, *param_1 - lVar1);
            }
            return uVar5;
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == 4) {
            uVar5 = 1;
            goto LAB_00105a25;
        }
        lVar2 = *param_1;
        cVar3 = __alpha(param_1);
    } while (true);
}



undefined8 region(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __alpha();
    if (cVar3 != '\0') {
        uVar5 = 1;
        cVar3 = __alpha(param_1);
        if (cVar3 != '\0') goto LAB_00105a92;
    }
    *param_1 = lVar1;
    iVar4 = 0;
    cVar3 = __digit(param_1);
    lVar2 = lVar1;
    while (cVar3 != '\0') {
        iVar4 = iVar4 + 1;
        if (iVar4 == 3) {
            uVar5 = 1;
            goto LAB_00105a92;
        }
        lVar2 = *param_1;
        cVar3 = __digit(param_1);
    }
    *param_1 = lVar2;
    uVar5 = 0;
LAB_00105a92:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar5, "region", lVar1, *param_1 - lVar1);
    }
    return uVar5;
}



undefined4 variant(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    undefined4 uVar5;
    code* pcVar6;
    long lVar7;

    iVar3 = 0;
    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar7 = lVar1;
LAB_00105b91:
    *(int*)(param_1 + 2) = iVar4 + 1;
    cVar2 = __alpha(param_1);
    if (cVar2 != '\0') {
        pcVar6 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar6 != (code*)0x0) goto LAB_00105b62;
    LAB_00105b82:
        iVar3 = iVar3 + 1;
        if (iVar3 == 8) goto LAB_00105c10;
        lVar7 = *param_1;
        goto LAB_00105b91;
    }
    *param_1 = lVar7;
    cVar2 = __digit(param_1);
    pcVar6 = (code*)param_1[1];
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if (pcVar6 != (code*)0x0) {
    LAB_00105b62:
        (*pcVar6)(param_1, (int)cVar2, "alphanum", lVar7, *param_1 - lVar7);
        iVar4 = *(int*)(param_1 + 2);
    }
    if (cVar2 != '\0') goto LAB_00105b82;
    *param_1 = lVar7;
    if (3 < iVar3 - 5U) {
        *param_1 = lVar1;
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') goto LAB_00105c50;
        iVar4 = 0;
        goto LAB_00105bf4;
    }
LAB_00105c10:
    pcVar6 = (code*)param_1[1];
    uVar5 = 1;
    goto LAB_00105c19;
LAB_00105c50:
    *param_1 = lVar1;
    uVar5 = 0;
    goto LAB_00105c55;
    while (iVar4 = iVar4 + 1, iVar4 != 3) {
    LAB_00105bf4:
        cVar2 = alphanum(param_1);
        if (cVar2 == '\0') goto LAB_00105c50;
    }
    uVar5 = 1;
LAB_00105c55:
    iVar4 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar4 + -2;
    }
    else {
        (*(code*)param_1[1])(param_1, uVar5, "__group", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
    LAB_00105c19:
        *(int*)(param_1 + 2) = iVar4 + -1;
        if (pcVar6 != (code*)0x0) {
            (*pcVar6)(param_1, uVar5, "variant", lVar1, *param_1 - lVar1);
        }
    }
    return uVar5;
}



int singleton(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __digit();
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __range(param_1, 0x41, 0x57);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __range(param_1, 0x59, 0x5a);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __range(param_1, 0x61, 0x77);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __range(param_1, 0x79, 0x7a);
                    iVar3 = (int)cVar2;
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "singleton", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



bool extension(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    bool bVar6;
    int iVar7;
    code* pcVar8;
    long lVar9;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = singleton();
    if (cVar4 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        bVar6 = false;
    }
    else {
        iVar5 = *(int*)(param_1 + 2);
        iVar7 = 0;
        while (true) {
            *(int*)(param_1 + 2) = iVar5 + 1;
            lVar2 = *param_1;
            cVar4 = __icar(param_1, 0x2d);
            iVar5 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar5 + 1;
            if (cVar4 == '\0') break;
            *(int*)(param_1 + 2) = iVar5 + 2;
            lVar9 = *param_1;
            cVar4 = __alpha(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar9;
                cVar4 = __digit(param_1);
                pcVar8 = (code*)param_1[1];
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if (pcVar8 != (code*)0x0) goto LAB_00105e01;
            LAB_00105e22:
                if (cVar4 != '\0') goto LAB_00105e2b;
            LAB_001061d8:
                pcVar8 = (code*)param_1[1];
                iVar5 = iVar5 + -1;
                *param_1 = lVar9;
                *(int*)(param_1 + 2) = iVar5;
                goto joined_r0x0010612b;
            }
            pcVar8 = (code*)param_1[1];
            iVar5 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar5;
            if (pcVar8 != (code*)0x0) {
            LAB_00105e01:
                (*pcVar8)(param_1, (int)cVar4, "alphanum", lVar9, *param_1 - lVar9);
                iVar5 = *(int*)(param_1 + 2);
                goto LAB_00105e22;
            }
        LAB_00105e2b:
            *(int*)(param_1 + 2) = iVar5 + 1;
            lVar3 = *param_1;
            cVar4 = __alpha(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                cVar4 = __digit(param_1);
                pcVar8 = (code*)param_1[1];
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if (pcVar8 != (code*)0x0) goto LAB_00105e5f;
            LAB_00105e8b:
                if (cVar4 == '\0') goto LAB_001061d8;
            }
            else {
                pcVar8 = (code*)param_1[1];
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if (pcVar8 != (code*)0x0) {
                LAB_00105e5f:
                    (*pcVar8)(param_1, (int)cVar4, "alphanum", lVar3, *param_1 - lVar3);
                    iVar5 = *(int*)(param_1 + 2);
                    goto LAB_00105e8b;
                }
            }
            *(int*)(param_1 + 2) = iVar5 + 1;
            lVar9 = *param_1;
            cVar4 = __alpha(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar9;
                cVar4 = __digit(param_1);
                pcVar8 = (code*)param_1[1];
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if (pcVar8 != (code*)0x0) goto LAB_00105ec8;
            LAB_00105ee9:
                if (cVar4 != '\0') goto LAB_00105ef2;
            LAB_00106280:
                pcVar8 = (code*)param_1[1];
            LAB_00106284:
                *param_1 = lVar9;
            LAB_001060d0:
                iVar5 = iVar5 + -1;
                *(int*)(param_1 + 2) = iVar5;
                if (pcVar8 == (code*)0x0) {
                LAB_00106238:
                    iVar5 = iVar5 + -1;
                    *(int*)(param_1 + 2) = iVar5;
                }
                else {
                    (*pcVar8)(param_1, 1, "__group", lVar2);
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar2);
                        iVar5 = *(int*)(param_1 + 2);
                    }
                }
            }
            else {
                pcVar8 = (code*)param_1[1];
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if (pcVar8 != (code*)0x0) {
                LAB_00105ec8:
                    (*pcVar8)(param_1, (int)cVar4, "alphanum", lVar9);
                    iVar5 = *(int*)(param_1 + 2);
                    goto LAB_00105ee9;
                }
            LAB_00105ef2:
                *(int*)(param_1 + 2) = iVar5 + 1;
                lVar9 = *param_1;
                cVar4 = __alpha(param_1);
                if (cVar4 == '\0') {
                    *param_1 = lVar9;
                    cVar4 = __digit(param_1);
                    pcVar8 = (code*)param_1[1];
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if (pcVar8 != (code*)0x0) goto LAB_00105f26;
                LAB_00105f47:
                    if (cVar4 == '\0') goto LAB_00106280;
                }
                else {
                    pcVar8 = (code*)param_1[1];
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if (pcVar8 != (code*)0x0) {
                    LAB_00105f26:
                        (*pcVar8)(param_1, (int)cVar4, "alphanum", lVar9);
                        iVar5 = *(int*)(param_1 + 2);
                        goto LAB_00105f47;
                    }
                }
                *(int*)(param_1 + 2) = iVar5 + 1;
                lVar9 = *param_1;
                cVar4 = __alpha(param_1);
                if (cVar4 == '\0') {
                    *param_1 = lVar9;
                    cVar4 = __digit(param_1);
                    pcVar8 = (code*)param_1[1];
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if (pcVar8 != (code*)0x0) goto LAB_00105f84;
                LAB_00105fa5:
                    if (cVar4 == '\0') goto LAB_00106280;
                }
                else {
                    pcVar8 = (code*)param_1[1];
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if (pcVar8 != (code*)0x0) {
                    LAB_00105f84:
                        (*pcVar8)(param_1, (int)cVar4, "alphanum", lVar9);
                        iVar5 = *(int*)(param_1 + 2);
                        goto LAB_00105fa5;
                    }
                }
                *(int*)(param_1 + 2) = iVar5 + 1;
                lVar9 = *param_1;
                cVar4 = __alpha(param_1);
                if (cVar4 == '\0') {
                    *param_1 = lVar9;
                    cVar4 = __digit(param_1);
                    pcVar8 = (code*)param_1[1];
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if (pcVar8 != (code*)0x0) goto LAB_00105fe2;
                LAB_00106003:
                    if (cVar4 == '\0') goto LAB_00106280;
                }
                else {
                    pcVar8 = (code*)param_1[1];
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if (pcVar8 != (code*)0x0) {
                    LAB_00105fe2:
                        (*pcVar8)(param_1, (int)cVar4, "alphanum", lVar9);
                        iVar5 = *(int*)(param_1 + 2);
                        goto LAB_00106003;
                    }
                }
                *(int*)(param_1 + 2) = iVar5 + 1;
                lVar9 = *param_1;
                cVar4 = __alpha(param_1);
                if (cVar4 == '\0') {
                    *param_1 = lVar9;
                    cVar4 = __digit(param_1);
                    pcVar8 = (code*)param_1[1];
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if (pcVar8 != (code*)0x0) goto LAB_00106040;
                LAB_00106061:
                    if (cVar4 == '\0') goto LAB_00106280;
                }
                else {
                    pcVar8 = (code*)param_1[1];
                    iVar5 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar5;
                    if (pcVar8 != (code*)0x0) {
                    LAB_00106040:
                        (*pcVar8)(param_1, (int)cVar4, "alphanum", lVar9);
                        iVar5 = *(int*)(param_1 + 2);
                        goto LAB_00106061;
                    }
                }
                *(int*)(param_1 + 2) = iVar5 + 1;
                lVar9 = *param_1;
                cVar4 = __alpha(param_1);
                if (cVar4 == '\0') {
                    *param_1 = lVar9;
                    cVar4 = __digit(param_1);
                    iVar5 = *(int*)(param_1 + 2);
                    pcVar8 = (code*)param_1[1];
                    *(int*)(param_1 + 2) = iVar5 + -1;
                    if (pcVar8 != (code*)0x0) goto LAB_001060a2;
                    if (cVar4 == '\0') {
                        *param_1 = lVar9;
                    }
                    iVar5 = iVar5 + -2;
                    goto LAB_00106238;
                }
                iVar5 = *(int*)(param_1 + 2);
                pcVar8 = (code*)param_1[1];
                *(int*)(param_1 + 2) = iVar5 + -1;
                if (pcVar8 != (code*)0x0) {
                LAB_001060a2:
                    (*pcVar8)(param_1, (int)cVar4, "alphanum", lVar9);
                    iVar5 = *(int*)(param_1 + 2);
                    pcVar8 = (code*)param_1[1];
                    if (cVar4 == '\0') goto LAB_00106284;
                    goto LAB_001060d0;
                }
                iVar5 = iVar5 + -3;
                *(int*)(param_1 + 2) = iVar5;
            }
            iVar7 = iVar7 + 1;
        }
        pcVar8 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar5;
    joined_r0x0010612b:
        if (pcVar8 == (code*)0x0) {
            iVar5 = iVar5 + -1;
            pcVar8 = (code*)0x0;
        }
        else {
            (*pcVar8)(param_1, 0, "__group", lVar2, 0);
            pcVar8 = (code*)param_1[1];
            *param_1 = lVar2;
            iVar5 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar5;
            if (pcVar8 != (code*)0x0) {
                (*pcVar8)(param_1, 0, "__group", lVar2, 0);
                iVar5 = *(int*)(param_1 + 2);
                pcVar8 = (code*)param_1[1];
            }
        }
        *param_1 = lVar2;
        bVar6 = 0 < iVar7;
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, bVar6, "extension", lVar1, *param_1 - lVar1);
    }
    return bVar6;
}



bool privateuse(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    bool bVar5;
    int iVar6;
    code* pcVar7;
    long lVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x58);
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 == '\0') {
        pcVar7 = (code*)param_1[1];
        bVar5 = false;
    }
    else {
        iVar6 = 0;
        while (true) {
            *(int*)(param_1 + 2) = iVar4 + 1;
            lVar2 = *param_1;
            cVar3 = __icar(param_1, 0x2d);
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + 1;
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = iVar4 + 2;
            lVar8 = *param_1;
            cVar3 = __alpha(param_1);
            if (cVar3 == '\0') {
                *param_1 = lVar8;
                cVar3 = __digit(param_1);
                pcVar7 = (code*)param_1[1];
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if (pcVar7 != (code*)0x0) goto LAB_00106489;
            LAB_001064af:
                if (cVar3 == '\0') {
                    pcVar7 = (code*)param_1[1];
                    iVar4 = iVar4 + -1;
                    *param_1 = lVar8;
                    *(int*)(param_1 + 2) = iVar4;
                    goto joined_r0x001067aa;
                }
            }
            else {
                pcVar7 = (code*)param_1[1];
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if (pcVar7 != (code*)0x0) {
                LAB_00106489:
                    (*pcVar7)(param_1, (int)cVar3, "alphanum", lVar8, *param_1 - lVar8);
                    iVar4 = *(int*)(param_1 + 2);
                    goto LAB_001064af;
                }
            }
            *(int*)(param_1 + 2) = iVar4 + 1;
            lVar8 = *param_1;
            cVar3 = __alpha(param_1);
            if (cVar3 == '\0') {
                *param_1 = lVar8;
                cVar3 = __digit(param_1);
                pcVar7 = (code*)param_1[1];
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if (pcVar7 != (code*)0x0) goto LAB_001064e8;
            LAB_0010650e:
                if (cVar3 != '\0') goto LAB_00106517;
            LAB_00106870:
                pcVar7 = (code*)param_1[1];
            LAB_00106874:
                iVar4 = iVar4 + -1;
                *param_1 = lVar8;
                *(int*)(param_1 + 2) = iVar4;
                if (pcVar7 == (code*)0x0) {
                LAB_00106886:
                    iVar4 = iVar4 + -1;
                    *(int*)(param_1 + 2) = iVar4;
                }
                else {
                LAB_00106768:
                    (*pcVar7)(param_1, 1, "__group", lVar2);
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar2);
                        iVar4 = *(int*)(param_1 + 2);
                    }
                }
            }
            else {
                pcVar7 = (code*)param_1[1];
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if (pcVar7 != (code*)0x0) {
                LAB_001064e8:
                    (*pcVar7)(param_1, (int)cVar3, "alphanum", lVar8);
                    iVar4 = *(int*)(param_1 + 2);
                    goto LAB_0010650e;
                }
            LAB_00106517:
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar8 = *param_1;
                cVar3 = __alpha(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar8;
                    cVar3 = __digit(param_1);
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) goto LAB_00106547;
                LAB_0010656d:
                    if (cVar3 == '\0') goto LAB_00106870;
                }
                else {
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) {
                    LAB_00106547:
                        (*pcVar7)(param_1, (int)cVar3, "alphanum", lVar8);
                        iVar4 = *(int*)(param_1 + 2);
                        goto LAB_0010656d;
                    }
                }
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar8 = *param_1;
                cVar3 = __alpha(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar8;
                    cVar3 = __digit(param_1);
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) goto LAB_001065a6;
                LAB_001065cc:
                    if (cVar3 == '\0') goto LAB_00106870;
                }
                else {
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) {
                    LAB_001065a6:
                        (*pcVar7)(param_1, (int)cVar3, "alphanum", lVar8);
                        iVar4 = *(int*)(param_1 + 2);
                        goto LAB_001065cc;
                    }
                }
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar8 = *param_1;
                cVar3 = __alpha(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar8;
                    cVar3 = __digit(param_1);
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) goto LAB_00106605;
                LAB_0010662b:
                    if (cVar3 == '\0') goto LAB_00106870;
                }
                else {
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) {
                    LAB_00106605:
                        (*pcVar7)(param_1, (int)cVar3, "alphanum", lVar8);
                        iVar4 = *(int*)(param_1 + 2);
                        goto LAB_0010662b;
                    }
                }
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar8 = *param_1;
                cVar3 = __alpha(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar8;
                    cVar3 = __digit(param_1);
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) goto LAB_00106664;
                LAB_0010668a:
                    if (cVar3 == '\0') goto LAB_00106870;
                }
                else {
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) {
                    LAB_00106664:
                        (*pcVar7)(param_1, (int)cVar3, "alphanum", lVar8);
                        iVar4 = *(int*)(param_1 + 2);
                        goto LAB_0010668a;
                    }
                }
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar8 = *param_1;
                cVar3 = __alpha(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar8;
                    cVar3 = __digit(param_1);
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) goto LAB_001066c3;
                LAB_001066e9:
                    if (cVar3 == '\0') goto LAB_00106870;
                }
                else {
                    pcVar7 = (code*)param_1[1];
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 != (code*)0x0) {
                    LAB_001066c3:
                        (*pcVar7)(param_1, (int)cVar3, "alphanum", lVar8);
                        iVar4 = *(int*)(param_1 + 2);
                        goto LAB_001066e9;
                    }
                }
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar8 = *param_1;
                cVar3 = __alpha(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar8;
                    cVar3 = __digit(param_1);
                    iVar4 = *(int*)(param_1 + 2);
                    pcVar7 = (code*)param_1[1];
                    *(int*)(param_1 + 2) = iVar4 + -1;
                    if (pcVar7 != (code*)0x0) goto LAB_00106726;
                    if (cVar3 == '\0') {
                        *param_1 = lVar8;
                    }
                    iVar4 = iVar4 + -2;
                    goto LAB_00106886;
                }
                iVar4 = *(int*)(param_1 + 2);
                pcVar7 = (code*)param_1[1];
                *(int*)(param_1 + 2) = iVar4 + -1;
                if (pcVar7 != (code*)0x0) {
                LAB_00106726:
                    (*pcVar7)(param_1, (int)cVar3, "alphanum", lVar8);
                    iVar4 = *(int*)(param_1 + 2);
                    pcVar7 = (code*)param_1[1];
                    if (cVar3 == '\0') goto LAB_00106874;
                    iVar4 = iVar4 + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar7 == (code*)0x0) goto LAB_00106886;
                    goto LAB_00106768;
                }
                iVar4 = iVar4 + -3;
                *(int*)(param_1 + 2) = iVar4;
            }
            iVar6 = iVar6 + 1;
        }
        pcVar7 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar4;
    joined_r0x001067aa:
        if (pcVar7 == (code*)0x0) {
            iVar4 = iVar4 + -1;
            pcVar7 = (code*)0x0;
        }
        else {
            (*pcVar7)(param_1, 0, "__group", lVar2, 0);
            pcVar7 = (code*)param_1[1];
            *param_1 = lVar2;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar7 != (code*)0x0) {
                (*pcVar7)(param_1, 0, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar7 = (code*)param_1[1];
            }
        }
        *param_1 = lVar2;
        bVar5 = 0 < iVar6;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, bVar5, "privateuse", lVar1, *param_1 - lVar1);
    }
    return bVar5;
}



undefined4 langtag(long* param_1)

{
    long lVar1;
    long lVar2;
    bool bVar3;
    char cVar4;
    int iVar5;
    undefined4 uVar6;
    long lVar7;
    undefined8 uVar8;
    code* pcVar9;
    long lVar10;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = language();
    if (cVar4 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar9 = (code*)param_1[1];
        uVar6 = 0;
        goto LAB_00106a8c;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar7 = *param_1;
    cVar4 = __icar(param_1, 0x2d);
    if (cVar4 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar9 = (code*)param_1[1];
        goto LAB_00106aed;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar2 = *param_1;
    cVar4 = __alpha(param_1);
    lVar10 = lVar2;
    if (cVar4 == '\0') {
    LAB_00106e07:
        pcVar9 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        uVar8 = 0;
        bVar3 = false;
        *param_1 = lVar10;
        if (pcVar9 == (code*)0x0) {
            iVar5 = *(int*)(param_1 + 2);
        LAB_00106aed:
            *param_1 = lVar7;
            uVar8 = 0;
        }
        else {
        LAB_00106d74:
            (*pcVar9)(param_1, uVar8, "script", lVar2, lVar10 - lVar2);
            iVar5 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            if (!bVar3) goto LAB_00106aed;
            uVar8 = 1;
        }
        iVar5 = iVar5 + -1;
        *(int*)(param_1 + 2) = iVar5;
        if (pcVar9 != (code*)0x0) {
            (*pcVar9)(param_1, uVar8, "__option", lVar1, 0);
            iVar5 = *(int*)(param_1 + 2);
        }
    }
    else {
        lVar10 = *param_1;
        cVar4 = __alpha(param_1);
        if (cVar4 == '\0') goto LAB_00106e07;
        lVar10 = *param_1;
        cVar4 = __alpha(param_1);
        if (cVar4 == '\0') goto LAB_00106e07;
        lVar10 = *param_1;
        cVar4 = __alpha(param_1);
        if (cVar4 == '\0') goto LAB_00106e07;
        iVar5 = *(int*)(param_1 + 2);
        pcVar9 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar5 + -1;
        if (pcVar9 != (code*)0x0) {
            lVar10 = *param_1;
            uVar8 = 1;
            bVar3 = true;
            goto LAB_00106d74;
        }
        iVar5 = iVar5 + -2;
    }
    *(int*)(param_1 + 2) = iVar5 + 1;
    lVar7 = *param_1;
    cVar4 = __icar(param_1, 0x2d);
    if ((cVar4 == '\0') || (cVar4 = region(param_1), cVar4 == '\0')) {
        *param_1 = lVar7;
        uVar8 = 0;
    }
    else {
        uVar8 = 1;
    }
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar8, "__option", lVar1, 0);
        iVar5 = *(int*)(param_1 + 2);
    }
    while (true) {
        lVar7 = *param_1;
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = __icar(param_1, 0x2d);
        if ((cVar4 == '\0') || (cVar4 = variant(param_1), cVar4 == '\0')) break;
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar7, 0);
            iVar5 = *(int*)(param_1 + 2);
        }
    }
    *param_1 = lVar7;
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
        iVar5 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar7;
    while (true) {
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = __icar(param_1, 0x2d);
        if ((cVar4 == '\0') || (cVar4 = extension(param_1), cVar4 == '\0')) break;
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar7, 0);
            iVar5 = *(int*)(param_1 + 2);
        }
        lVar7 = *param_1;
    }
    *param_1 = lVar7;
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
        iVar5 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar7;
    *(int*)(param_1 + 2) = iVar5 + 1;
    cVar4 = __icar(param_1, 0x2d);
    if ((cVar4 == '\0') || (cVar4 = privateuse(param_1), cVar4 == '\0')) {
        *param_1 = lVar7;
        uVar8 = 0;
    }
    else {
        uVar8 = 1;
    }
    iVar5 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar5 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar5 + -2;
        return 1;
    }
    uVar6 = 1;
    (*(code*)param_1[1])(param_1, uVar8, "__option", lVar1, 0);
    iVar5 = *(int*)(param_1 + 2);
    pcVar9 = (code*)param_1[1];
LAB_00106a8c:
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar9 != (code*)0x0) {
        (*pcVar9)(param_1, uVar6, "langtag", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int irregular(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "EN-GB-OED");
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __istring(param_1, "I-AMI");
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __istring(param_1, "I-BNN");
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __istring(param_1, "I-DEFAULT");
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __istring(param_1, "I-ENOCHIAN");
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __istring(param_1, "I-HAK");
                        iVar3 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = __istring(param_1, "I-KLINGON");
                            iVar3 = (int)cVar2;
                            if (cVar2 == '\0') {
                                *param_1 = lVar1;
                                cVar2 = __istring(param_1, "I-LUX");
                                iVar3 = (int)cVar2;
                                if (cVar2 == '\0') {
                                    *param_1 = lVar1;
                                    cVar2 = __istring(param_1, "I-MINGO");
                                    iVar3 = (int)cVar2;
                                    if (cVar2 == '\0') {
                                        *param_1 = lVar1;
                                        cVar2 = __istring(param_1, "I-NAVAJO");
                                        iVar3 = (int)cVar2;
                                        if (cVar2 == '\0') {
                                            *param_1 = lVar1;
                                            cVar2 = __istring(param_1, "I-PWN");
                                            iVar3 = (int)cVar2;
                                            if (cVar2 == '\0') {
                                                *param_1 = lVar1;
                                                cVar2 = __istring(param_1, "I-TAO");
                                                iVar3 = (int)cVar2;
                                                if (cVar2 == '\0') {
                                                    *param_1 = lVar1;
                                                    cVar2 = __istring(param_1, "I-TAY");
                                                    iVar3 = (int)cVar2;
                                                    if (cVar2 == '\0') {
                                                        *param_1 = lVar1;
                                                        cVar2 = __istring(param_1, "I-TSU");
                                                        iVar3 = (int)cVar2;
                                                        if (cVar2 == '\0') {
                                                            *param_1 = lVar1;
                                                            cVar2 = __istring(param_1, "SGN-BE-FR");
                                                            iVar3 = (int)cVar2;
                                                            if (cVar2 == '\0') {
                                                                *param_1 = lVar1;
                                                                cVar2 = __istring(param_1, "SGN-BE-NL");
                                                                iVar3 = (int)cVar2;
                                                                if (cVar2 == '\0') {
                                                                    *param_1 = lVar1;
                                                                    cVar2 = __istring(param_1, "SGN-CH-DE");
                                                                    iVar3 = (int)cVar2;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "irregular", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int regular(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "ART-LOJBAN");
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __istring(param_1, "CEL-GAULISH");
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __istring(param_1, "NO-BOK");
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __istring(param_1, "NO-NYN");
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __istring(param_1, "ZH-GUOYU");
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __istring(param_1, "ZH-HAKKA");
                        iVar3 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = __istring(param_1, "ZH-MIN");
                            iVar3 = (int)cVar2;
                            if (cVar2 == '\0') {
                                *param_1 = lVar1;
                                cVar2 = __istring(param_1, "ZH-MIN-NAN");
                                iVar3 = (int)cVar2;
                                if (cVar2 == '\0') {
                                    *param_1 = lVar1;
                                    cVar2 = __istring(param_1, "ZH-XIANG");
                                    iVar3 = (int)cVar2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "regular", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int grandfathered(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = irregular();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = regular(param_1);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "grandfathered", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int Language_Tag(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = langtag();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = privateuse(param_1);
        if (cVar2 == '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            *param_1 = lVar1;
            cVar2 = irregular(param_1);
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = regular(param_1);
            }
            iVar4 = (int)cVar2;
            iVar3 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar3 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar3 + -2;
                return iVar4;
            }
            (*(code*)param_1[1])(param_1, iVar4, "grandfathered", lVar1, *param_1 - lVar1);
            iVar3 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
            goto LAB_00107233;
        }
    }
    iVar3 = *(int*)(param_1 + 2);
    pcVar5 = (code*)param_1[1];
    iVar4 = (int)cVar2;
LAB_00107233:
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, iVar4, "Language_Tag", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



bool Content_Length(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "Content_Length", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



int HTTP_name(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __num(param_1, &DAT_00117721);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "HTTP_name", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int HTTP_version(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = __num(param_1, &DAT_00117721);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "HTTP_name", lVar1, *param_1 - lVar1);
    }
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x2f);
        if (cVar2 != '\0') {
            cVar2 = __digit(param_1);
            if (cVar2 != '\0') {
                cVar2 = __icar(param_1, 0x2e);
                if (cVar2 != '\0') {
                    cVar2 = __digit(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_0010740f;
                }
            }
        }
    }
    iVar3 = 0;
LAB_0010740f:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "HTTP_version", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined8 Host(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 4;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x5b);
    iVar4 = *(int*)(param_1 + 2) + 1;
    *(int*)(param_1 + 2) = iVar4;
    if (cVar3 == '\0') {
    LAB_001074c1:
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
        }
        else {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
            pcVar6 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            cVar3 = '\0';
            if (pcVar6 != (code*)0x0) goto LAB_001074ff;
        }
    }
    else {
        lVar2 = *param_1;
        cVar3 = IPv6address(param_1);
        iVar4 = (int)cVar3;
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = IPvFuture(param_1, iVar4);
            iVar4 = (int)cVar3;
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                iVar4 = *(int*)(param_1 + 2);
                goto LAB_001074c1;
            }
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar4, "__group", lVar1, 0);
        }
        cVar3 = __icar(param_1, 0x5d);
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar6 != (code*)0x0) {
        LAB_001074ff:
            (*pcVar6)(param_1, (int)cVar3, "IP_literal", lVar1, *param_1 - lVar1);
        }
        if (cVar3 != '\0') goto LAB_00107524;
    }
    *param_1 = lVar1;
    cVar3 = IPv4address(param_1);
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        cVar3 = reg_name(param_1);
    }
LAB_00107524:
    iVar4 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        iVar4 = iVar4 + -2;
        *(int*)(param_1 + 2) = iVar4;
    }
    else {
        (*(code*)param_1[1])(param_1, (int)cVar3, &__func___2667, lVar1, *param_1 - lVar1);
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "uri_host", lVar1, *param_1 - lVar1);
            iVar4 = *(int*)(param_1 + 2);
        }
    }
    if (cVar3 == '\0') {
        pcVar6 = (code*)param_1[1];
        uVar7 = 0;
    }
    else {
        *(int*)(param_1 + 2) = iVar4 + 1;
        lVar2 = *param_1;
        cVar3 = __icar(param_1, 0x3a);
        if ((cVar3 == '\0') || (cVar3 = port(param_1), cVar3 == '\0')) {
            *param_1 = lVar2;
            uVar5 = 0;
        }
        else {
            uVar5 = 1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return 1;
        }
        uVar7 = 1;
        (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, &__func___3613, lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



undefined8 OWS(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;
    int iVar5;

    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = __sp(param_1);
        iVar5 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar4;
            cVar2 = __htab(param_1, iVar5);
            iVar5 = (int)cVar2;
            if (cVar2 == '\0') {
                iVar3 = *(int*)(param_1 + 2);
                *param_1 = lVar4;
                *(int*)(param_1 + 2) = iVar3 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = iVar3 + -2;
                }
                else {
                    (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, &__func___3629, lVar1, lVar4 - lVar1);
                    }
                }
                return 1;
            }
        }
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "__group", lVar4, 0);
            iVar3 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
    } while (true);
}



int BWS(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = OWS();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, &__func___3513, lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



bool RWS(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;
    int iVar5;
    int iVar6;

    iVar6 = 0;
    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = __sp(param_1);
        iVar5 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar4;
            cVar2 = __htab(param_1, iVar5);
            iVar5 = (int)cVar2;
            if (cVar2 == '\0') {
                iVar3 = *(int*)(param_1 + 2);
                *param_1 = lVar4;
                *(int*)(param_1 + 2) = iVar3 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = iVar3 + -2;
                }
                else {
                    (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 0 < iVar6, &__func___3643, lVar1, lVar4 - lVar1);
                        return 0 < iVar6;
                    }
                }
                return 0 < iVar6;
            }
        }
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "__group", lVar4, 0);
            iVar3 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
        iVar6 = iVar6 + 1;
    } while (true);
}



int absolute_form(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = absolute_URI();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "absolute_form", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



bool absolute_path(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    long lVar6;
    long lVar7;

    iVar5 = 0;
    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar6 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2f);
        if (cVar3 == '\0') break;
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar7 = lVar2;
        while (cVar3 = pchar(param_1), cVar3 != '\0') {
            lVar7 = *param_1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *param_1 = lVar7;
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar4 = iVar4 + -2;
            *(int*)(param_1 + 2) = iVar4;
        }
        else {
            (*(code*)param_1[1])(param_1, 1, "segment", lVar2, lVar7 - lVar2);
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
        }
        iVar5 = iVar5 + 1;
        lVar6 = *param_1;
    }
    iVar4 = *(int*)(param_1 + 2);
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *param_1 = lVar6;
        *(int*)(param_1 + 2) = iVar4 + -2;
    }
    else {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        *param_1 = lVar6;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0 < iVar5, "absolute_path", lVar1, lVar6 - lVar1);
        }
    }
    return 0 < iVar5;
}



int asterisk_form(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __icar(param_1, 0x2a);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "asterisk_form", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int authority_form(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = authority();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "authority_form", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



bool chunk_data(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __octet(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "chunk_data", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



bool chunk_size(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __hexdig(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "chunk_size", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



int field_vchar(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __vchar();
    if (cVar2 == '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        *param_1 = lVar1;
        cVar2 = __range(param_1, 0x80, 0xff);
        iVar3 = *(int*)(param_1 + 2);
        iVar4 = (int)cVar2;
        *(int*)(param_1 + 2) = iVar3 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar3 + -2;
            return iVar4;
        }
        (*(code*)param_1[1])(param_1, iVar4, "obs_text", lVar1, *param_1 - lVar1);
        iVar3 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
    }
    else {
        iVar3 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
        iVar4 = (int)cVar2;
    }
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, iVar4, "field_vchar", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



undefined8 http_URI(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, &DAT_00117726);
    if (cVar3 != '\0') {
        cVar3 = authority(param_1);
        if (cVar3 != '\0') {
            cVar3 = path_abempty(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = __icar(param_1, 0x3f);
                if (cVar3 == '\0') {
                LAB_00107e76:
                    *param_1 = lVar2;
                    uVar5 = 0;
                }
                else {
                    cVar3 = query(param_1);
                    if (cVar3 == '\0') goto LAB_00107e76;
                    uVar5 = 1;
                }
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
                    iVar4 = *(int*)(param_1 + 2);
                }
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar2 = *param_1;
                cVar3 = __icar(param_1, 0x23);
                if (cVar3 == '\0') {
                LAB_00107ec1:
                    *param_1 = lVar2;
                    uVar5 = 0;
                }
                else {
                    cVar3 = fragment(param_1);
                    if (cVar3 == '\0') goto LAB_00107ec1;
                    uVar5 = 1;
                }
                iVar4 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar4 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *(int*)(param_1 + 2) = iVar4 + -2;
                    return 1;
                }
                uVar7 = 1;
                (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
                goto LAB_00107e0a;
            }
        }
    }
    iVar4 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
    uVar7 = 0;
LAB_00107e0a:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, "http_URI", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



undefined8 https_URI(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "HTTPS://");
    if (cVar3 != '\0') {
        cVar3 = authority(param_1);
        if (cVar3 != '\0') {
            cVar3 = path_abempty(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = __icar(param_1, 0x3f);
                if (cVar3 == '\0') {
                LAB_00107fe6:
                    *param_1 = lVar2;
                    uVar5 = 0;
                }
                else {
                    cVar3 = query(param_1);
                    if (cVar3 == '\0') goto LAB_00107fe6;
                    uVar5 = 1;
                }
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
                    iVar4 = *(int*)(param_1 + 2);
                }
                *(int*)(param_1 + 2) = iVar4 + 1;
                lVar2 = *param_1;
                cVar3 = __icar(param_1, 0x23);
                if (cVar3 == '\0') {
                LAB_00108031:
                    *param_1 = lVar2;
                    uVar5 = 0;
                }
                else {
                    cVar3 = fragment(param_1);
                    if (cVar3 == '\0') goto LAB_00108031;
                    uVar5 = 1;
                }
                iVar4 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar4 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *(int*)(param_1 + 2) = iVar4 + -2;
                    return 1;
                }
                uVar7 = 1;
                (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
                goto LAB_00107f7a;
            }
        }
    }
    iVar4 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
    uVar7 = 0;
LAB_00107f7a:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, "https_URI", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



undefined8 message_body(long* param_1)

{
    long lVar1;
    char cVar2;
    long lVar3;

    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar3 = lVar1;
    while (true) {
        cVar2 = __octet(param_1);
        if (cVar2 == '\0') break;
        lVar3 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar3;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "message_body", lVar1, lVar3 - lVar1);
    }
    return 1;
}



bool obs_fold(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    bool bVar5;
    int iVar6;
    int iVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __crlf();
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 != '\0') {
        iVar6 = 0;
        do {
            lVar2 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = __sp(param_1);
            iVar7 = (int)cVar3;
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                cVar3 = __htab(param_1, iVar7);
                iVar7 = (int)cVar3;
                if (cVar3 == '\0') goto code_r0x001081a5;
            }
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, iVar7, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
            iVar6 = iVar6 + 1;
        } while (true);
    }
    pcVar8 = (code*)param_1[1];
    bVar5 = false;
LAB_001081f6:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, bVar5, "obs_fold", lVar1, *param_1 - lVar1);
    }
    return bVar5;
code_r0x001081a5:
    pcVar8 = (code*)param_1[1];
    *param_1 = lVar2;
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, 0, "__group", lVar2, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    *param_1 = lVar2;
    bVar5 = 0 < iVar6;
    goto LAB_001081f6;
}



int obs_text(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __range(param_1, 0x80, 0xff);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "obs_text", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int ctext(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __htab();
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __sp(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __range(param_1, 0x21, 0x27);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __range(param_1, 0x2a, 0x5b);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __range(param_1, 0x5d, 0x7e);
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = obs_text(param_1);
                        iVar3 = (int)cVar2;
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "ctext", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined8 field_content(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    undefined8 uVar6;
    code* pcVar7;
    int iVar8;
    undefined8 uVar9;
    long lVar10;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __vchar();
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        cVar3 = obs_text(param_1);
        pcVar7 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) goto LAB_0010838c;
    }
    else {
        pcVar7 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 == (code*)0x0) goto LAB_001083f0;
    LAB_0010838c:
        (*pcVar7)(param_1, (int)cVar3, "field_vchar", lVar1, *param_1 - lVar1);
        iVar4 = *(int*)(param_1 + 2);
    }
    if (cVar3 != '\0') {
    LAB_001083f0:
        lVar2 = *param_1;
        iVar4 = iVar4 + 1;
        iVar8 = 0;
        lVar10 = lVar2;
        do {
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = __sp(param_1);
            iVar5 = (int)cVar3;
            if (cVar3 == '\0') {
                *param_1 = lVar10;
                cVar3 = __htab(param_1, iVar5);
                iVar5 = (int)cVar3;
                if (cVar3 == '\0') goto code_r0x0010845e;
            }
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, iVar5, "__group", lVar10, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
            lVar10 = *param_1;
            iVar8 = iVar8 + 1;
        } while (true);
    }
    pcVar7 = (code*)param_1[1];
    uVar9 = 0;
LAB_001083b7:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar9, "field_content", lVar1, *param_1 - lVar1);
    }
    return uVar9;
code_r0x0010845e:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar10;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar10, 0);
    }
    *param_1 = lVar10;
    if ((iVar8 == 0) || (cVar3 = field_vchar(param_1), cVar3 == '\0')) {
        *param_1 = lVar2;
        uVar6 = 0;
    }
    else {
        uVar6 = 1;
    }
    iVar4 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar4 + -2;
        return 1;
    }
    uVar9 = 1;
    (*(code*)param_1[1])(param_1, uVar6, "__option", lVar1, 0);
    iVar4 = *(int*)(param_1 + 2);
    pcVar7 = (code*)param_1[1];
    goto LAB_001083b7;
}



undefined8 field_value(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;
    int iVar5;

    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = field_content(param_1);
        iVar5 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar4;
            cVar2 = obs_fold(param_1, iVar5);
            iVar5 = (int)cVar2;
            if (cVar2 == '\0') {
                iVar3 = *(int*)(param_1 + 2);
                *param_1 = lVar4;
                *(int*)(param_1 + 2) = iVar3 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = iVar3 + -2;
                }
                else {
                    (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                    *param_1 = lVar4;
                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "field_value", lVar1, lVar4 - lVar1);
                    }
                }
                return 1;
            }
        }
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "__group", lVar4, 0);
            iVar3 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
    } while (true);
}



int origin_form(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    long lVar6;
    undefined8 uVar7;
    code* pcVar8;
    long lVar9;

    iVar5 = 0;
    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 2;
    lVar6 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2f);
        if (cVar3 == '\0') break;
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar9 = lVar2;
        while (cVar3 = pchar(param_1), cVar3 != '\0') {
            lVar9 = *param_1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *param_1 = lVar9;
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar4 = iVar4 + -2;
            *(int*)(param_1 + 2) = iVar4;
        }
        else {
            (*(code*)param_1[1])(param_1, 1, "segment", lVar2, lVar9 - lVar2);
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
        }
        iVar5 = iVar5 + 1;
        lVar6 = *param_1;
    }
    iVar4 = *(int*)(param_1 + 2);
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        iVar4 = iVar4 + -2;
        *param_1 = lVar6;
        *(int*)(param_1 + 2) = iVar4;
    }
    else {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        *param_1 = lVar6;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0 < iVar5, "absolute_path", lVar1, lVar6 - lVar1);
            iVar4 = *(int*)(param_1 + 2);
        }
    }
    if (iVar5 == 0) {
        pcVar8 = (code*)param_1[1];
    }
    else {
        *(int*)(param_1 + 2) = iVar4 + 1;
        lVar6 = *param_1;
        cVar3 = __icar(param_1, 0x3f);
        if ((cVar3 == '\0') || (cVar3 = query(param_1), cVar3 == '\0')) {
            *param_1 = lVar6;
            uVar7 = 0;
        }
        else {
            uVar7 = 1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return 1;
        }
        iVar5 = 1;
        (*(code*)param_1[1])(param_1, uVar7, "__option", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, iVar5, "origin_form", lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



undefined8 partial_URI(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, &DAT_0011772b);
    if (((cVar3 == '\0') || (cVar3 = authority(param_1), cVar3 == '\0')) ||
        (cVar3 = path_abempty(param_1), cVar3 == '\0')) {
        *param_1 = lVar1;
        cVar3 = path_absolute(param_1);
        if (cVar3 != '\0') goto LAB_001088bc;
        *param_1 = lVar1;
        cVar3 = path_noscheme(param_1);
        if (cVar3 != '\0') goto LAB_001088bc;
        *param_1 = lVar1;
        cVar3 = path_empty(param_1);
        pcVar6 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar6 != (code*)0x0) goto LAB_001088ce;
    LAB_001088ed:
        if (cVar3 == '\0') {
            pcVar6 = (code*)param_1[1];
            uVar7 = 0;
            goto LAB_001088f9;
        }
    }
    else {
    LAB_001088bc:
        pcVar6 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar6 != (code*)0x0) {
        LAB_001088ce:
            (*pcVar6)(param_1, (int)cVar3, "relative_part", lVar1, *param_1 - lVar1);
            iVar4 = *(int*)(param_1 + 2);
            goto LAB_001088ed;
        }
    }
    *(int*)(param_1 + 2) = iVar4 + 1;
    lVar2 = *param_1;
    cVar3 = __icar(param_1, 0x3f);
    if ((cVar3 == '\0') || (cVar3 = query(param_1), cVar3 == '\0')) {
        *param_1 = lVar2;
        uVar5 = 0;
    }
    else {
        uVar5 = 1;
    }
    iVar4 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar4 + -2;
        return 1;
    }
    uVar7 = 1;
    (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
    iVar4 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
LAB_001088f9:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, "partial_URI", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



int qdtext(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __htab();
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __sp(param_1);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __icar(param_1, 0x21);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __range(param_1, 0x23, 0x5b);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __range(param_1, 0x5d, 0x7e);
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = obs_text(param_1);
                        iVar3 = (int)cVar2;
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "qdtext", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int quoted_pair(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;

    iVar5 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x5c);
    iVar4 = *(int*)(param_1 + 2) + 1;
    *(int*)(param_1 + 2) = iVar4;
    if (cVar3 != '\0') {
        lVar2 = *param_1;
        cVar3 = __htab(param_1);
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = __sp(param_1);
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                cVar3 = __vchar(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar2;
                    cVar3 = obs_text(param_1);
                    if (cVar3 == '\0') {
                        *param_1 = lVar2;
                        iVar4 = *(int*)(param_1 + 2);
                        goto LAB_00108b3f;
                    }
                }
            }
        }
        iVar4 = *(int*)(param_1 + 2);
        iVar5 = (int)cVar3;
    }
LAB_00108b3f:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "__group", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "quoted_pair", lVar1, *param_1 - lVar1);
        }
        return iVar5;
    }
    *(int*)(param_1 + 2) = iVar4 + -2;
    return iVar5;
}



int comment(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;

    iVar4 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x28);
    if (cVar3 != '\0') {
        iVar4 = *(int*)(param_1 + 2);
    LAB_00108c58:
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = ctext(param_1);
        iVar5 = (int)cVar3;
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = quoted_pair(param_1, iVar5);
            iVar5 = (int)cVar3;
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                cVar3 = comment(param_1, iVar5);
                iVar5 = (int)cVar3;
                if (cVar3 == '\0') goto code_r0x00108cc4;
            }
        }
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "__group", lVar2);
            iVar4 = *(int*)(param_1 + 2);
        }
        goto LAB_00108c58;
    }
LAB_00108cfe:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "comment", lVar1, *param_1 - lVar1);
    }
    return iVar4;
code_r0x00108cc4:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar2;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar2, 0);
    }
    *param_1 = lVar2;
    cVar3 = __icar(param_1, 0x29);
    iVar4 = (int)cVar3;
    goto LAB_00108cfe;
}



int quoted_string(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;

    iVar4 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __dquote();
    if (cVar3 != '\0') {
        iVar4 = *(int*)(param_1 + 2);
    LAB_00108d70:
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = qdtext(param_1);
        iVar5 = (int)cVar3;
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = quoted_pair(param_1, iVar5);
            iVar5 = (int)cVar3;
            if (cVar3 == '\0') goto code_r0x00108dc2;
        }
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "__group", lVar2);
            iVar4 = *(int*)(param_1 + 2);
        }
        goto LAB_00108d70;
    }
LAB_00108df7:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "quoted_string", lVar1, *param_1 - lVar1);
    }
    return iVar4;
code_r0x00108dc2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar2;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar2, 0);
    }
    *param_1 = lVar2;
    cVar3 = __dquote(param_1);
    iVar4 = (int)cVar3;
    goto LAB_00108df7;
}



undefined8 rank(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    undefined8 uVar4;
    undefined8 uVar5;
    code* pcVar6;
    long lVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = __icar(param_1, 0x30);
    if (cVar2 == '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        *param_1 = lVar1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        *param_1 = lVar1;
        cVar2 = __icar(param_1, 0x31);
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            iVar3 = *(int*)(param_1 + 2);
            uVar4 = 0;
            pcVar6 = (code*)param_1[1];
        }
        else {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = __icar(param_1, 0x2e);
            if (cVar2 == '\0') {
                *param_1 = lVar7;
                uVar5 = 0;
            }
            else {
                lVar7 = *param_1;
                cVar2 = __icar(param_1, 0x30);
                if (cVar2 != '\0') {
                    lVar7 = *param_1;
                    cVar2 = __icar(param_1, 0x30);
                    if (cVar2 != '\0') {
                        lVar7 = *param_1;
                        cVar2 = __icar(param_1, 0x30);
                        uVar5 = 1;
                        if (cVar2 != '\0') goto LAB_00109006;
                    }
                }
                *param_1 = lVar7;
                uVar5 = 1;
            }
        LAB_00109006:
            iVar3 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar3 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar3 + -3;
                return 1;
            }
            uVar4 = 1;
            (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
            iVar3 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
        }
        iVar3 = iVar3 + -1;
        *(int*)(param_1 + 2) = iVar3;
        if (pcVar6 != (code*)0x0) {
            (*pcVar6)(param_1, uVar4, "__group", lVar1, 0);
            iVar3 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
            goto LAB_00108f1c;
        }
        goto LAB_00109089;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar7 = *param_1;
    cVar2 = __icar(param_1, 0x2e);
    if (cVar2 == '\0') {
        *param_1 = lVar7;
        uVar4 = 0;
    }
    else {
        lVar7 = *param_1;
        cVar2 = __digit(param_1);
        if (cVar2 != '\0') {
            lVar7 = *param_1;
            cVar2 = __digit(param_1);
            if (cVar2 != '\0') {
                lVar7 = *param_1;
                cVar2 = __digit(param_1);
                uVar4 = 1;
                if (cVar2 != '\0') goto LAB_00108eb4;
            }
        }
        *param_1 = lVar7;
        uVar4 = 1;
    }
LAB_00108eb4:
    iVar3 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar3 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        iVar3 = iVar3 + -2;
    }
    else {
        (*(code*)param_1[1])(param_1, uVar4, "__option", lVar1, 0);
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "__group", lVar1, 0);
            iVar3 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
            uVar4 = 1;
        LAB_00108f1c:
            *(int*)(param_1 + 2) = iVar3 + -1;
            if (pcVar6 != (code*)0x0) {
                (*pcVar6)(param_1, uVar4, &__func___4258, lVar1, *param_1 - lVar1);
            }
            return uVar4;
        }
    }
    uVar4 = 1;
LAB_00109089:
    *(int*)(param_1 + 2) = iVar3 + -1;
    return uVar4;
}



undefined8 reason_phrase(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;
    int iVar5;

    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = __htab(param_1);
        iVar5 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar4;
            cVar2 = __sp(param_1, iVar5);
            iVar5 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar4;
                cVar2 = __vchar(param_1, iVar5);
                iVar5 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar4;
                    cVar2 = obs_text(param_1, iVar5);
                    iVar5 = (int)cVar2;
                    if (cVar2 == '\0') {
                        iVar3 = *(int*)(param_1 + 2);
                        *param_1 = lVar4;
                        *(int*)(param_1 + 2) = iVar3 + -1;
                        if ((code*)param_1[1] == (code*)0x0) {
                            *param_1 = lVar4;
                            *(int*)(param_1 + 2) = iVar3 + -2;
                        }
                        else {
                            (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                            *param_1 = lVar4;
                            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                            if ((code*)param_1[1] != (code*)0x0) {
                                (*(code*)param_1[1])(param_1, 1, "reason_phrase", lVar1, lVar4 - lVar1);
                            }
                        }
                        return 1;
                    }
                }
            }
        }
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "__group", lVar4, 0);
            iVar3 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
    } while (true);
}



int request_target(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = origin_form();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "request_target", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined4 status_code(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined4 uVar5;

    iVar4 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __digit(param_1);
    lVar2 = lVar1;
    do {
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            uVar5 = 0;
        LAB_001092b5:
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, uVar5, "status_code", lVar1, *param_1 - lVar1);
            }
            return uVar5;
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == 3) {
            uVar5 = 1;
            goto LAB_001092b5;
        }
        lVar2 = *param_1;
        cVar3 = __digit(param_1);
    } while (true);
}



int status_line(long* param_1)

{
    long lVar1;
    long lVar2;
    bool bVar3;
    char cVar4;
    undefined8 uVar5;
    code* pcVar6;
    int iVar7;
    int iVar8;
    long lVar9;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar4 = __num(param_1, &DAT_00117721);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar4, "HTTP_name", lVar1, *param_1 - lVar1);
    }
    if ((((cVar4 == '\0') || (cVar4 = __icar(param_1, 0x2f), cVar4 == '\0')) ||
        (cVar4 = __digit(param_1), cVar4 == '\0')) || (cVar4 = __icar(param_1, 0x2e), cVar4 == '\0')) {
        iVar8 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        iVar7 = 0;
        cVar4 = '\0';
        *(int*)(param_1 + 2) = iVar8 + -1;
        if (pcVar6 == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar8 + -2;
            return 0;
        }
    LAB_0010935f:
        (*pcVar6)(param_1, iVar7, "HTTP_version", lVar1, *param_1 - lVar1);
    }
    else {
        cVar4 = __digit(param_1);
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar6 != (code*)0x0) {
            iVar7 = (int)cVar4;
            goto LAB_0010935f;
        }
    }
    if ((cVar4 == '\0') || (cVar4 = __sp(param_1), cVar4 == '\0')) {
    LAB_00109380:
        iVar7 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        iVar8 = 0;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        iVar7 = 0;
        cVar4 = __digit(param_1);
        lVar9 = lVar2;
        while (cVar4 != '\0') {
            iVar7 = iVar7 + 1;
            if (iVar7 == 3) {
                pcVar6 = (code*)param_1[1];
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if (pcVar6 == (code*)0x0) goto LAB_001094d8;
                lVar9 = *param_1;
                uVar5 = 1;
                bVar3 = true;
                goto LAB_001094bb;
            }
            lVar9 = *param_1;
            cVar4 = __digit(param_1);
        }
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        uVar5 = 0;
        bVar3 = false;
        *param_1 = lVar9;
        if (pcVar6 != (code*)0x0) {
        LAB_001094bb:
            (*pcVar6)(param_1, uVar5, "status_code", lVar2, lVar9 - lVar2);
            if (bVar3) {
            LAB_001094d8:
                cVar4 = __sp(param_1);
                if ((cVar4 != '\0') && (cVar4 = reason_phrase(param_1), cVar4 != '\0')) {
                    cVar4 = __crlf(param_1);
                    iVar7 = *(int*)(param_1 + 2);
                    pcVar6 = (code*)param_1[1];
                    iVar8 = (int)cVar4;
                    goto LAB_0010938a;
                }
                goto LAB_00109380;
            }
            pcVar6 = (code*)param_1[1];
        }
        iVar7 = *(int*)(param_1 + 2);
        iVar8 = 0;
    }
LAB_0010938a:
    *(int*)(param_1 + 2) = iVar7 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, iVar8, "status_line", lVar1, *param_1 - lVar1);
    }
    return iVar8;
}



int t_ranking(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = OWS();
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3b);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = __istring(param_1, &DAT_00117737);
                if (cVar2 != '\0') {
                    cVar2 = rank(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00109559;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00109559:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "t_ranking", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int tchar(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __icar(param_1, 0x21);
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __icar(param_1, 0x23);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __icar(param_1, 0x24);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __icar(param_1, 0x25);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __icar(param_1, 0x26);
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __icar(param_1, 0x27);
                        iVar3 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = __icar(param_1, 0x2a);
                            iVar3 = (int)cVar2;
                            if (cVar2 == '\0') {
                                *param_1 = lVar1;
                                cVar2 = __icar(param_1, 0x2b);
                                iVar3 = (int)cVar2;
                                if (cVar2 == '\0') {
                                    *param_1 = lVar1;
                                    cVar2 = __icar(param_1, 0x2d);
                                    iVar3 = (int)cVar2;
                                    if (cVar2 == '\0') {
                                        *param_1 = lVar1;
                                        cVar2 = __icar(param_1, 0x2e);
                                        iVar3 = (int)cVar2;
                                        if (cVar2 == '\0') {
                                            *param_1 = lVar1;
                                            cVar2 = __icar(param_1, 0x5e);
                                            iVar3 = (int)cVar2;
                                            if (cVar2 == '\0') {
                                                *param_1 = lVar1;
                                                cVar2 = __icar(param_1, 0x5f);
                                                iVar3 = (int)cVar2;
                                                if (cVar2 == '\0') {
                                                    *param_1 = lVar1;
                                                    cVar2 = __icar(param_1, 0x60);
                                                    iVar3 = (int)cVar2;
                                                    if (cVar2 == '\0') {
                                                        *param_1 = lVar1;
                                                        cVar2 = __icar(param_1, 0x7c);
                                                        iVar3 = (int)cVar2;
                                                        if (cVar2 == '\0') {
                                                            *param_1 = lVar1;
                                                            cVar2 = __icar(param_1, 0x7e);
                                                            iVar3 = (int)cVar2;
                                                            if (cVar2 == '\0') {
                                                                *param_1 = lVar1;
                                                                cVar2 = __digit(param_1);
                                                                iVar3 = (int)cVar2;
                                                                if (cVar2 == '\0') {
                                                                    *param_1 = lVar1;
                                                                    cVar2 = __alpha(param_1);
                                                                    iVar3 = (int)cVar2;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "tchar", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



bool field_name(long* param_1)

{
    int iVar1;
    long lVar2;
    bool bVar3;
    char cVar4;
    int iVar5;
    long lVar6;

    iVar5 = 0;
    lVar2 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar6 = lVar2;
    while (true) {
        cVar4 = tchar(param_1);
        if (cVar4 == '\0') break;
        lVar6 = *param_1;
        iVar5 = iVar5 + 1;
    }
    iVar1 = *(int*)(param_1 + 2);
    bVar3 = 0 < iVar5;
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar1 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, bVar3, "token", lVar2, lVar6 - lVar2);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, bVar3, "field_name", lVar2, *param_1 - lVar2);
        }
        return bVar3;
    }
    *(int*)(param_1 + 2) = iVar1 + -2;
    return bVar3;
}



bool method(long* param_1)

{
    int iVar1;
    long lVar2;
    bool bVar3;
    char cVar4;
    int iVar5;
    long lVar6;

    iVar5 = 0;
    lVar2 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar6 = lVar2;
    while (true) {
        cVar4 = tchar(param_1);
        if (cVar4 == '\0') break;
        lVar6 = *param_1;
        iVar5 = iVar5 + 1;
    }
    iVar1 = *(int*)(param_1 + 2);
    bVar3 = 0 < iVar5;
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar1 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, bVar3, "token", lVar2, lVar6 - lVar2);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, bVar3, "method", lVar2, *param_1 - lVar2);
        }
        return bVar3;
    }
    *(int*)(param_1 + 2) = iVar1 + -2;
    return bVar3;
}



bool token(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = tchar(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "token", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



int chunk_ext_name(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "chunk_ext_name", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int chunk_ext_val(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = quoted_string(param_1);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "chunk_ext_val", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int connection_option(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "connection_option", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int protocol_name(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "protocol_name", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int protocol_version(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "protocol_version", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int pseudonym(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "pseudonym", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int request_line(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "method", lVar1, *param_1 - lVar1);
    }
    if (cVar3 != '\0') {
        cVar3 = __sp(param_1);
        if (cVar3 != '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = origin_form(param_1);
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar3, "request_target", lVar2, *param_1 - lVar2);
            }
            if (cVar3 != '\0') {
                cVar3 = __sp(param_1);
                if (cVar3 != '\0') {
                    cVar3 = HTTP_version(param_1);
                    if (cVar3 != '\0') {
                        cVar3 = __crlf(param_1);
                        iVar4 = (int)cVar3;
                        goto LAB_00109c0e;
                    }
                }
            }
        }
    }
    iVar4 = 0;
LAB_00109c0e:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "request_line", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int received_protocol(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    undefined8 uVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar3 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "protocol_name", lVar1, *param_1 - lVar1);
    }
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x2f);
        if (cVar3 != '\0') {
            uVar6 = 1;
            goto LAB_00109d23;
        }
    }
    *param_1 = lVar1;
    uVar6 = 0;
LAB_00109d23:
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar6, "__option", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
    }
    lVar2 = *param_1;
    *(int*)(param_1 + 2) = iVar4 + 1;
    cVar3 = token(param_1);
    iVar4 = *(int*)(param_1 + 2);
    iVar5 = (int)cVar3;
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "protocol_version", lVar2, *param_1 - lVar2);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "received_protocol", lVar1, *param_1 - lVar1);
        }
        return iVar5;
    }
    *(int*)(param_1 + 2) = iVar4 + -2;
    return iVar5;
}



undefined8 chunk_ext(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    int iVar6;
    long lVar7;
    undefined8 uVar8;
    code* pcVar9;

    lVar1 = *param_1;
    iVar5 = *(int*)(param_1 + 2) + 1;
    lVar7 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = __icar(param_1, 0x3b);
        if (cVar4 == '\0') break;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar4 = token(param_1);
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar4, "chunk_ext_name", lVar2, *param_1 - lVar2);
            iVar5 = *(int*)(param_1 + 2);
        }
        if (cVar4 == '\0') goto LAB_00109e54;
        *(int*)(param_1 + 2) = iVar5 + 1;
        lVar2 = *param_1;
        cVar4 = __icar(param_1, 0x3d);
        if (cVar4 == '\0') {
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
        LAB_00109f41:
            *param_1 = lVar2;
            uVar8 = 0;
        LAB_00109f50:
            iVar5 = iVar6 + -1;
            *(int*)(param_1 + 2) = iVar5;
            if (pcVar9 == (code*)0x0) {
            LAB_0010a058:
                iVar5 = iVar5 + -1;
                *(int*)(param_1 + 2) = iVar5;
            }
            else {
                (*pcVar9)(param_1, uVar8, "__option", lVar7, 0);
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar7);
                    iVar5 = *(int*)(param_1 + 2);
                }
            }
        }
        else {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar3 = *param_1;
            cVar4 = token(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                cVar4 = quoted_string(param_1);
                iVar5 = *(int*)(param_1 + 2);
                pcVar9 = (code*)param_1[1];
                iVar6 = iVar5 + -1;
                *(int*)(param_1 + 2) = iVar6;
                if (pcVar9 != (code*)0x0) goto LAB_00109fea;
                if (cVar4 == '\0') goto LAB_00109f41;
                iVar5 = iVar5 + -2;
                goto LAB_0010a058;
            }
            iVar5 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            *(int*)(param_1 + 2) = iVar5 + -1;
            if (pcVar9 != (code*)0x0) {
            LAB_00109fea:
                (*pcVar9)(param_1, (int)cVar4, "chunk_ext_val", lVar3, *param_1 - lVar3);
                iVar6 = *(int*)(param_1 + 2);
                pcVar9 = (code*)param_1[1];
                if (cVar4 == '\0') goto LAB_00109f41;
                uVar8 = 1;
                goto LAB_00109f50;
            }
            iVar5 = iVar5 + -3;
            *(int*)(param_1 + 2) = iVar5;
        }
        lVar7 = *param_1;
    }
    iVar5 = *(int*)(param_1 + 2);
LAB_00109e54:
    *param_1 = lVar7;
    *(int*)(param_1 + 2) = iVar5 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *param_1 = lVar7;
        *(int*)(param_1 + 2) = iVar5 + -2;
    }
    else {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
        *param_1 = lVar7;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "chunk_ext", lVar1, lVar7 - lVar1);
        }
    }
    return 1;
}



int chunk(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;
    long lVar5;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __hexdig(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "chunk_size", lVar1, lVar4 - lVar1);
    }
    if (iVar3 != 0) {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar4 = *param_1;
        cVar2 = chunk_ext(param_1);
        if (cVar2 == '\0') {
            *param_1 = lVar4;
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, cVar2 != '\0', "__option", lVar1, 0);
        }
        cVar2 = __crlf(param_1);
        if (cVar2 != '\0') {
            lVar4 = *param_1;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            iVar3 = 0;
            lVar5 = lVar4;
            while (true) {
                cVar2 = __octet(param_1);
                if (cVar2 == '\0') break;
                lVar5 = *param_1;
                iVar3 = iVar3 + 1;
            }
            *param_1 = lVar5;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 0 < iVar3, "chunk_data", lVar4, lVar5 - lVar4);
            }
            if (0 < iVar3) {
                cVar2 = __crlf(param_1);
                iVar3 = (int)cVar2;
                goto LAB_0010a1a2;
            }
        }
    }
    iVar3 = 0;
LAB_0010a1a2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "chunk", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int last_chunk(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __icar(param_1, 0x30);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    if (iVar3 != 0) {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        cVar2 = chunk_ext(param_1);
        if (cVar2 == '\0') {
            *param_1 = lVar4;
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, cVar2 != '\0', "__option", lVar1, 0);
        }
        cVar2 = __crlf(param_1);
        iVar3 = (int)cVar2;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "last_chunk", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined8 protocol(long* param_1)

{
    int iVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    undefined8 uVar7;
    code* pcVar8;
    undefined8 uVar9;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar2 = *param_1;
    cVar5 = token();
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar5, "protocol_name", lVar2, *param_1 - lVar2);
        iVar6 = *(int*)(param_1 + 2);
    }
    if (cVar5 == '\0') {
        pcVar8 = (code*)param_1[1];
        uVar9 = 0;
        goto LAB_0010a2f9;
    }
    *(int*)(param_1 + 2) = iVar6 + 1;
    lVar3 = *param_1;
    cVar5 = __icar(param_1, 0x2f);
    if (cVar5 == '\0') {
        iVar6 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    LAB_0010a353:
        iVar6 = iVar6 + -1;
        uVar7 = 0;
        *param_1 = lVar3;
        *(int*)(param_1 + 2) = iVar6;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar4 = *param_1;
        cVar5 = token(param_1);
        iVar1 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        iVar6 = iVar1 + -1;
        *(int*)(param_1 + 2) = iVar6;
        if (pcVar8 == (code*)0x0) {
            if (cVar5 != '\0') {
                iVar6 = iVar1 + -2;
                goto LAB_0010a3f6;
            }
            goto LAB_0010a353;
        }
        (*pcVar8)(param_1, (int)cVar5, "protocol_version", lVar4, *param_1 - lVar4);
        iVar6 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        if (cVar5 == '\0') goto LAB_0010a353;
        iVar6 = iVar6 + -1;
        uVar7 = 1;
        *(int*)(param_1 + 2) = iVar6;
    }
    if (pcVar8 == (code*)0x0) {
    LAB_0010a3f6:
        *(int*)(param_1 + 2) = iVar6 + -1;
        return 1;
    }
    uVar9 = 1;
    (*pcVar8)(param_1, uVar7, "__option", lVar2, 0);
    iVar6 = *(int*)(param_1 + 2);
    pcVar8 = (code*)param_1[1];
LAB_0010a2f9:
    *(int*)(param_1 + 2) = iVar6 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, uVar9, "protocol", lVar2, *param_1 - lVar2);
    }
    return uVar9;
}



undefined8 Upgrade(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;
    undefined8 uVar6;
    code* pcVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar5 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar5 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar5, 0);
    }
    *param_1 = lVar5;
    cVar3 = protocol(param_1);
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 == '\0') {
        pcVar7 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        while (true) {
            lVar5 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_0010a516:
                *param_1 = lVar2;
                uVar6 = 0;
            }
            else {
                cVar3 = protocol(param_1);
                if (cVar3 == '\0') goto LAB_0010a516;
                uVar6 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar6, "__option", lVar5, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar5);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar7 = (code*)param_1[1];
        *param_1 = lVar5;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar5;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar6, "Upgrade", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int start_line(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar3 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "method", lVar1, *param_1 - lVar1);
    }
    if (cVar3 == '\0') {
    LAB_0010a68a:
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar5 = 0;
        iVar4 = 0;
        if (pcVar6 != (code*)0x0) {
        LAB_0010a69f:
            (*pcVar6)(param_1, iVar5, "request_line", lVar1, *param_1 - lVar1);
            goto LAB_0010a6b7;
        }
    }
    else {
        cVar3 = __sp(param_1);
        if (cVar3 == '\0') goto LAB_0010a68a;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = origin_form(param_1);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "request_target", lVar2, *param_1 - lVar2);
        }
        if (cVar3 == '\0') goto LAB_0010a68a;
        cVar3 = __sp(param_1);
        if (cVar3 == '\0') goto LAB_0010a68a;
        cVar3 = HTTP_version(param_1);
        if (cVar3 == '\0') goto LAB_0010a68a;
        cVar3 = __crlf(param_1);
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar4 = (int)cVar3;
        if (pcVar6 != (code*)0x0) {
            iVar5 = (int)cVar3;
            goto LAB_0010a69f;
        }
    LAB_0010a6b7:
        if ((char)iVar4 != '\0') goto LAB_0010a6c0;
    }
    *param_1 = lVar1;
    cVar3 = status_line(param_1);
    iVar4 = (int)cVar3;
LAB_0010a6c0:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "start_line", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



undefined8 Trailer(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    long lVar6;
    undefined8 uVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar6 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar6, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar6 = *param_1;
    }
    *param_1 = lVar6;
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        iVar4 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar4 + 1;
    cVar3 = token(param_1);
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "field_name", lVar6, *param_1 - lVar6);
        iVar4 = *(int*)(param_1 + 2);
    }
    if (cVar3 == '\0') {
        pcVar5 = (code*)param_1[1];
        uVar7 = 0;
    }
    else {
        while (true) {
            lVar6 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_0010a8de:
                *param_1 = lVar2;
                uVar7 = 0;
            }
            else {
                cVar3 = field_name(param_1);
                if (cVar3 == '\0') goto LAB_0010a8de;
                uVar7 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar7, "__option", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar6);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar5 = (code*)param_1[1];
        *param_1 = lVar6;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar5 != (code*)0x0) {
            (*pcVar5)(param_1, 0, "__group", lVar6, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
        }
        *param_1 = lVar6;
        uVar7 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar7, "Trailer", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



undefined8 Connection(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    int iVar6;
    code* pcVar7;
    long lVar8;
    undefined8 uVar9;

    lVar1 = *param_1;
    iVar5 = *(int*)(param_1 + 2) + 1;
    lVar8 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = __icar(param_1, 0x2c);
        if ((cVar4 == '\0') || (cVar4 = OWS(param_1), cVar4 == '\0')) break;
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar8, 0);
            iVar5 = *(int*)(param_1 + 2);
        }
        lVar8 = *param_1;
    }
    *param_1 = lVar8;
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar8, 0);
        iVar5 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar8;
    *(int*)(param_1 + 2) = iVar5 + 1;
    cVar4 = token(param_1);
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar4, "connection_option", lVar8, *param_1 - lVar8);
        iVar5 = *(int*)(param_1 + 2);
    }
    if (cVar4 == '\0') {
        pcVar7 = (code*)param_1[1];
        uVar9 = 0;
    }
    else {
        while (true) {
            lVar8 = *param_1;
            *(int*)(param_1 + 2) = iVar5 + 1;
            cVar4 = OWS(param_1);
            if ((cVar4 == '\0') || (cVar4 = __icar(param_1, 0x2c), cVar4 == '\0')) break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar4 = OWS(param_1);
            if (cVar4 == '\0') {
                iVar6 = *(int*)(param_1 + 2);
                pcVar7 = (code*)param_1[1];
            LAB_0010abff:
                *param_1 = lVar2;
                uVar9 = 0;
            LAB_0010ac04:
                iVar5 = iVar6 + -1;
                *(int*)(param_1 + 2) = iVar5;
                if (pcVar7 == (code*)0x0) goto LAB_0010accb;
                (*pcVar7)(param_1, uVar9, "__option", lVar8, 0);
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar8);
                    iVar5 = *(int*)(param_1 + 2);
                }
            }
            else {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar3 = *param_1;
                cVar4 = token(param_1);
                iVar5 = *(int*)(param_1 + 2);
                pcVar7 = (code*)param_1[1];
                iVar6 = iVar5 + -1;
                *(int*)(param_1 + 2) = iVar6;
                if (pcVar7 != (code*)0x0) {
                    (*pcVar7)(param_1, (int)cVar4, "connection_option", lVar3, *param_1 - lVar3);
                    iVar6 = *(int*)(param_1 + 2);
                    pcVar7 = (code*)param_1[1];
                    if (cVar4 == '\0') goto LAB_0010abff;
                    uVar9 = 1;
                    goto LAB_0010ac04;
                }
                iVar5 = iVar5 + -2;
                if (cVar4 == '\0') goto LAB_0010abff;
            LAB_0010accb:
                iVar5 = iVar5 + -1;
                *(int*)(param_1 + 2) = iVar5;
            }
        }
        pcVar7 = (code*)param_1[1];
        *param_1 = lVar8;
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar8, 0);
            iVar5 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar8;
        uVar9 = 1;
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar9, "Connection", lVar1, *param_1 - lVar1);
    }
    return uVar9;
}



int transfer_parameter(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = token();
    if (cVar3 != '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = OWS(param_1);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, &__func___3513, lVar2, *param_1 - lVar2);
        }
        if (cVar3 != '\0') {
            cVar3 = __icar(param_1, 0x3d);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = OWS(param_1);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, &__func___3513, lVar2, *param_1 - lVar2);
                    iVar4 = *(int*)(param_1 + 2);
                }
                iVar4 = iVar4 + 1;
                *(int*)(param_1 + 2) = iVar4;
                if (cVar3 == '\0') {
                    iVar5 = 0;
                }
                else {
                    lVar2 = *param_1;
                    cVar3 = token(param_1);
                    if (cVar3 == '\0') {
                        *param_1 = lVar2;
                        cVar3 = quoted_string(param_1);
                        if (cVar3 == '\0') {
                            *param_1 = lVar2;
                            iVar4 = *(int*)(param_1 + 2);
                            iVar5 = 0;
                            goto LAB_0010ad05;
                        }
                    }
                    iVar4 = *(int*)(param_1 + 2);
                    iVar5 = (int)cVar3;
                }
                goto LAB_0010ad05;
            }
        }
    }
    iVar5 = 0;
    iVar4 = *(int*)(param_1 + 2) + 1;
LAB_0010ad05:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "__group", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "transfer_parameter", lVar1, *param_1 - lVar1);
        }
        return iVar5;
    }
    *(int*)(param_1 + 2) = iVar4 + -2;
    return iVar5;
}



undefined8 transfer_extension(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    undefined8 uVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = token();
    if (cVar3 == '\0') {
        iVar4 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        iVar4 = *(int*)(param_1 + 2);
        while (true) {
            lVar2 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x3b);
            if (cVar3 == '\0') break;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = transfer_parameter(param_1);
            if (cVar3 == '\0') break;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
        }
        pcVar5 = (code*)param_1[1];
        *param_1 = lVar2;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar5 != (code*)0x0) {
            (*pcVar5)(param_1, 0, "__group", lVar2, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
        }
        *param_1 = lVar2;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar6, "transfer_extension", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int transfer_coding(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "CHUNKED");
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __istring(param_1, "COMPRESS");
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __istring(param_1, "DEFLATE");
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __istring(param_1, &DAT_00117753);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = transfer_extension(param_1);
                    iVar3 = (int)cVar2;
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "transfer_coding", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined8 Transfer_Encoding(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;
    undefined8 uVar6;
    code* pcVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar5 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar5 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar5, 0);
    }
    *param_1 = lVar5;
    cVar3 = transfer_coding(param_1);
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 == '\0') {
        pcVar7 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        while (true) {
            lVar5 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_0010b136:
                *param_1 = lVar2;
                uVar6 = 0;
            }
            else {
                cVar3 = transfer_coding(param_1);
                if (cVar3 == '\0') goto LAB_0010b136;
                uVar6 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar6, "__option", lVar5, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar5);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar7 = (code*)param_1[1];
        *param_1 = lVar5;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar5;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar6, "Transfer_Encoding", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int t_codings(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "TRAILERS");
    if (cVar3 == '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        *param_1 = lVar1;
        cVar3 = transfer_coding(param_1);
        if (cVar3 == '\0') {
            *param_1 = lVar1;
            iVar4 = *(int*)(param_1 + 2);
            iVar5 = 0;
            pcVar6 = (code*)param_1[1];
        }
        else {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = t_ranking(param_1);
            if (cVar3 == '\0') {
                *param_1 = lVar2;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar4 + -3;
                return 1;
            }
            iVar5 = 1;
            (*(code*)param_1[1])(param_1, cVar3 != '\0', "__option", lVar1, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
        }
        *(int*)(param_1 + 2) = iVar4 + -1;
        if (pcVar6 == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return iVar5;
        }
        (*pcVar6)(param_1, iVar5, "__group", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
    }
    else {
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        iVar5 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, iVar5, "t_codings", lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



undefined8 TE(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    int iVar6;
    undefined8 uVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar4 = __icar(param_1, 0x2c);
    iVar6 = (int)cVar4;
    if (cVar4 == '\0') {
        *param_1 = lVar1;
        cVar4 = t_codings(param_1, iVar6);
        iVar6 = (int)cVar4;
        if (cVar4 == '\0') {
            pcVar8 = (code*)param_1[1];
            *param_1 = lVar1;
            iVar6 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar6;
            if (pcVar8 != (code*)0x0) {
                (*pcVar8)(param_1, 0, "__group", lVar1, 0);
                iVar6 = *(int*)(param_1 + 2);
                pcVar8 = (code*)param_1[1];
            }
            *param_1 = lVar1;
            uVar7 = 0;
            goto LAB_0010b435;
        }
    }
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar6, "__group", lVar1, 0);
        iVar5 = *(int*)(param_1 + 2);
    }
    while (true) {
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = OWS(param_1);
        if (cVar4 == '\0') break;
        cVar4 = __icar(param_1, 0x2c);
        if (cVar4 == '\0') break;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar3 = *param_1;
        cVar4 = OWS(param_1);
        if (cVar4 == '\0') {
        LAB_0010b4fe:
            *param_1 = lVar3;
            uVar7 = 0;
        }
        else {
            cVar4 = t_codings(param_1);
            if (cVar4 == '\0') goto LAB_0010b4fe;
            uVar7 = 1;
        }
        iVar5 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar5 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar5 = iVar5 + -2;
            *(int*)(param_1 + 2) = iVar5;
        }
        else {
            (*(code*)param_1[1])(param_1, uVar7, "__option", lVar2, 0);
            iVar5 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar5;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar2);
                iVar5 = *(int*)(param_1 + 2);
            }
        }
    }
    pcVar8 = (code*)param_1[1];
    *param_1 = lVar2;
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, 0, "__group", lVar2, 0);
        iVar6 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    *param_1 = lVar2;
    uVar7 = 1;
LAB_0010b435:
    *(int*)(param_1 + 2) = iVar6 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, uVar7, "__option", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, &__func___3672, lVar1, *param_1 - lVar1);
        }
        return 1;
    }
    *(int*)(param_1 + 2) = iVar6 + -2;
    return 1;
}



int uri_host(long* param_1)

{
    int iVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar2 = *param_1;
    cVar4 = __icar(param_1, 0x5b);
    iVar5 = *(int*)(param_1 + 2) + 1;
    *(int*)(param_1 + 2) = iVar5;
    if (cVar4 == '\0') {
    LAB_0010b62b:
        *(int*)(param_1 + 2) = iVar5 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar5 + -2;
        }
        else {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar2, 0);
            pcVar6 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            iVar5 = 0;
            if (pcVar6 != (code*)0x0) goto LAB_0010b668;
        }
    }
    else {
        lVar3 = *param_1;
        cVar4 = IPv6address(param_1);
        iVar5 = (int)cVar4;
        if (cVar4 == '\0') {
            *param_1 = lVar3;
            cVar4 = IPvFuture(param_1, iVar5);
            iVar5 = (int)cVar4;
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                iVar5 = *(int*)(param_1 + 2);
                goto LAB_0010b62b;
            }
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "__group", lVar2, 0);
        }
        cVar4 = __icar(param_1, 0x5d);
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar5 = (int)cVar4;
        if (pcVar6 != (code*)0x0) {
        LAB_0010b668:
            (*pcVar6)(param_1, (int)(char)iVar5, "IP_literal", lVar2, *param_1 - lVar2);
        }
        if ((char)iVar5 != '\0') goto LAB_0010b689;
    }
    *param_1 = lVar2;
    cVar4 = IPv4address(param_1);
    iVar5 = (int)cVar4;
    if (cVar4 == '\0') {
        *param_1 = lVar2;
        cVar4 = reg_name(param_1);
        iVar5 = (int)cVar4;
    }
LAB_0010b689:
    iVar1 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar1 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar1 + -2;
        return iVar5;
    }
    (*(code*)param_1[1])(param_1, iVar5, &__func___2667, lVar2, *param_1 - lVar2);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "uri_host", lVar2, *param_1 - lVar2);
    }
    return iVar5;
}



int received_by(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    int iVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = uri_host();
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        *param_1 = lVar1;
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = token(param_1);
        iVar7 = (int)cVar3;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar7, "pseudonym", lVar1, *param_1 - lVar1);
            iVar4 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
        LAB_0010b868:
            *(int*)(param_1 + 2) = iVar4 + -1;
            if (pcVar6 == (code*)0x0) {
                return iVar7;
            }
            (*pcVar6)(param_1, iVar7, "received_by", lVar1, *param_1 - lVar1);
            return iVar7;
        }
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = __icar(param_1, 0x3a);
        if ((cVar3 == '\0') || (cVar3 = port(param_1), cVar3 == '\0')) {
            *param_1 = lVar2;
            uVar5 = 0;
        }
        else {
            uVar5 = 1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar4 = iVar4 + -2;
        }
        else {
            (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar1, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
                iVar7 = 1;
                goto LAB_0010b868;
            }
        }
        iVar7 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    return iVar7;
}



undefined8 Via(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    long lVar7;
    undefined8 uVar8;
    code* pcVar9;

    lVar1 = *param_1;
    iVar6 = *(int*)(param_1 + 2) + 1;
    lVar7 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar6 + 1;
        cVar5 = __icar(param_1, 0x2c);
        if ((cVar5 == '\0') || (cVar5 = OWS(param_1), cVar5 == '\0')) break;
        iVar6 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar6;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar5, "__group", lVar7, 0);
            iVar6 = *(int*)(param_1 + 2);
        }
        lVar7 = *param_1;
    }
    *param_1 = lVar7;
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar7, 0);
        iVar6 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar7;
    *(int*)(param_1 + 2) = iVar6 + 1;
    cVar5 = received_protocol(param_1);
    if (((cVar5 != '\0') && (cVar5 = RWS(param_1), cVar5 != '\0')) &&
        (cVar5 = received_by(param_1), cVar5 != '\0')) {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar5 = RWS(param_1);
        if ((cVar5 == '\0') || (cVar5 = comment(param_1), cVar5 == '\0')) {
            *param_1 = lVar2;
            uVar8 = 0;
        }
        else {
            uVar8 = 1;
        }
        iVar6 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar6 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar6 = iVar6 + -2;
        }
        else {
            (*(code*)param_1[1])(param_1, uVar8, "__option", lVar7, 0);
            iVar6 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar6;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar1, 0);
                iVar6 = *(int*)(param_1 + 2);
            }
        }
        lVar7 = *param_1;
    LAB_0010bb20:
        do {
            while (true) {
                *(int*)(param_1 + 2) = iVar6 + 1;
                cVar5 = OWS(param_1);
                if ((cVar5 == '\0') || (cVar5 = __icar(param_1, 0x2c), cVar5 == '\0')) goto LAB_0010bb33;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar5 = OWS(param_1);
                iVar6 = *(int*)(param_1 + 2) + 1;
                *(int*)(param_1 + 2) = iVar6;
                if (cVar5 == '\0') break;
                lVar3 = *param_1;
                cVar5 = received_protocol(param_1);
                if (((cVar5 == '\0') || (cVar5 = RWS(param_1), cVar5 == '\0')) ||
                    (cVar5 = received_by(param_1), cVar5 == '\0')) {
                    *param_1 = lVar3;
                    iVar6 = *(int*)(param_1 + 2);
                    break;
                }
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar4 = *param_1;
                cVar5 = RWS(param_1);
                if ((cVar5 == '\0') || (cVar5 = comment(param_1), cVar5 == '\0')) {
                    uVar8 = 0;
                    *param_1 = lVar4;
                }
                else {
                    uVar8 = 1;
                }
                iVar6 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar6 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    iVar6 = iVar6 + -4;
                    lVar7 = *param_1;
                    *(int*)(param_1 + 2) = iVar6;
                }
                else {
                    (*(code*)param_1[1])(param_1, uVar8, "__option", lVar3, 0);
                    iVar6 = *(int*)(param_1 + 2);
                    *(int*)(param_1 + 2) = iVar6 + -1;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar2);
                        iVar6 = *(int*)(param_1 + 2);
                        pcVar9 = (code*)param_1[1];
                        uVar8 = 1;
                        goto LAB_0010bc1e;
                    }
                    iVar6 = iVar6 + -3;
                    lVar7 = *param_1;
                    *(int*)(param_1 + 2) = iVar6;
                }
            }
            *(int*)(param_1 + 2) = iVar6 + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 0, "__group", lVar2);
                iVar6 = *(int*)(param_1 + 2);
                pcVar9 = (code*)param_1[1];
                uVar8 = 0;
                *param_1 = lVar2;
            LAB_0010bc1e:
                *(int*)(param_1 + 2) = iVar6 + -1;
                if (pcVar9 == (code*)0x0) {
                    iVar6 = iVar6 + -2;
                    *(int*)(param_1 + 2) = iVar6;
                }
                else {
                    (*pcVar9)(param_1, uVar8, "__option", lVar7);
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar7);
                        iVar6 = *(int*)(param_1 + 2);
                        lVar7 = *param_1;
                        goto LAB_0010bb20;
                    }
                }
                lVar7 = *param_1;
                goto LAB_0010bb20;
            }
            iVar6 = iVar6 + -3;
            *param_1 = lVar2;
            *(int*)(param_1 + 2) = iVar6;
            lVar7 = lVar2;
        } while (true);
    }
    iVar6 = *(int*)(param_1 + 2);
    *param_1 = lVar7;
    *(int*)(param_1 + 2) = iVar6 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar6 + -2;
        return 0;
    }
    uVar8 = 0;
    (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
    iVar6 = *(int*)(param_1 + 2);
    pcVar9 = (code*)param_1[1];
LAB_0010bb78:
    *(int*)(param_1 + 2) = iVar6 + -1;
    if (pcVar9 != (code*)0x0) {
        (*pcVar9)(param_1, uVar8, &__func___3804, lVar1, *param_1 - lVar1);
    }
    return uVar8;
LAB_0010bb33:
    pcVar9 = (code*)param_1[1];
    *param_1 = lVar7;
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if (pcVar9 != (code*)0x0) {
        (*pcVar9)(param_1, 0, "__group", lVar7, 0);
        iVar6 = *(int*)(param_1 + 2);
        pcVar9 = (code*)param_1[1];
    }
    *param_1 = lVar7;
    uVar8 = 1;
    goto LAB_0010bb78;
}



undefined8 Allow(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    int iVar6;
    undefined8 uVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar4 = __icar(param_1, 0x2c);
    iVar6 = (int)cVar4;
    if (cVar4 == '\0') {
        *param_1 = lVar1;
        cVar4 = method(param_1, iVar6);
        iVar6 = (int)cVar4;
        if (cVar4 == '\0') {
            pcVar8 = (code*)param_1[1];
            *param_1 = lVar1;
            iVar6 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar6;
            if (pcVar8 != (code*)0x0) {
                (*pcVar8)(param_1, 0, "__group", lVar1, 0);
                iVar6 = *(int*)(param_1 + 2);
                pcVar8 = (code*)param_1[1];
            }
            *param_1 = lVar1;
            uVar7 = 0;
            goto LAB_0010be75;
        }
    }
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar6, "__group", lVar1, 0);
        iVar5 = *(int*)(param_1 + 2);
    }
    while (true) {
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = OWS(param_1);
        if (cVar4 == '\0') break;
        cVar4 = __icar(param_1, 0x2c);
        if (cVar4 == '\0') break;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar3 = *param_1;
        cVar4 = OWS(param_1);
        if (cVar4 == '\0') {
        LAB_0010bf3e:
            *param_1 = lVar3;
            uVar7 = 0;
        }
        else {
            cVar4 = method(param_1);
            if (cVar4 == '\0') goto LAB_0010bf3e;
            uVar7 = 1;
        }
        iVar5 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar5 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar5 = iVar5 + -2;
            *(int*)(param_1 + 2) = iVar5;
        }
        else {
            (*(code*)param_1[1])(param_1, uVar7, "__option", lVar2, 0);
            iVar5 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar5;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar2);
                iVar5 = *(int*)(param_1 + 2);
            }
        }
    }
    pcVar8 = (code*)param_1[1];
    *param_1 = lVar2;
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, 0, "__group", lVar2, 0);
        iVar6 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    *param_1 = lVar2;
    uVar7 = 1;
LAB_0010be75:
    *(int*)(param_1 + 2) = iVar6 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, uVar7, "__option", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "Allow", lVar1, *param_1 - lVar1);
        }
        return 1;
    }
    *(int*)(param_1 + 2) = iVar6 + -2;
    return 1;
}



undefined8 Content_Language(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;
    undefined8 uVar6;
    code* pcVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar5 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar5 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar5, 0);
    }
    *param_1 = lVar5;
    cVar3 = Language_Tag(param_1);
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 == '\0') {
        pcVar7 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        while (true) {
            lVar5 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_0010c126:
                *param_1 = lVar2;
                uVar6 = 0;
            }
            else {
                cVar3 = Language_Tag(param_1);
                if (cVar3 == '\0') goto LAB_0010c126;
                uVar6 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar6, "__option", lVar5, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar5);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar7 = (code*)param_1[1];
        *param_1 = lVar5;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar5;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar6, "Content_Language", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int Content_Location(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = absolute_URI();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = partial_URI(param_1);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "Content_Location", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int Expect(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "100-CONTINUE");
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "Expect", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int GMT(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __num(param_1, &DAT_0011776e);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, &__func___4764, lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int Location(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar2 = *param_1;
    cVar3 = URI();
    if (cVar3 == '\0') {
        *param_1 = lVar2;
        cVar3 = relative_ref(param_1);
    }
    iVar4 = (int)cVar3;
    iVar1 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar1 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "URI_reference", lVar2, *param_1 - lVar2);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar4, "Location", lVar2, *param_1 - lVar2);
        }
        return iVar4;
    }
    *(int*)(param_1 + 2) = iVar1 + -2;
    return iVar4;
}



bool Max_Forwards(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "Max_Forwards", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



int Referer(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = absolute_URI();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = partial_URI(param_1);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "Referer", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int Vary(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    long lVar6;
    undefined8 uVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x2a);
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        iVar4 = *(int*)(param_1 + 2) + 1;
        lVar6 = lVar1;
        while (true) {
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
            lVar6 = *param_1;
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        *param_1 = lVar6;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        }
        *param_1 = lVar6;
        cVar3 = field_name(param_1);
        if (cVar3 == '\0') {
            iVar4 = *(int*)(param_1 + 2);
            pcVar8 = (code*)param_1[1];
            iVar5 = 0;
            *param_1 = lVar1;
        }
        else {
            iVar4 = *(int*)(param_1 + 2);
            while (true) {
                lVar6 = *param_1;
                *(int*)(param_1 + 2) = iVar4 + 1;
                cVar3 = OWS(param_1);
                if (cVar3 == '\0') break;
                cVar3 = __icar(param_1, 0x2c);
                if (cVar3 == '\0') break;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = OWS(param_1);
                if (cVar3 == '\0') {
                LAB_0010c6c6:
                    *param_1 = lVar2;
                    uVar7 = 0;
                }
                else {
                    cVar3 = field_name(param_1);
                    if (cVar3 == '\0') goto LAB_0010c6c6;
                    uVar7 = 1;
                }
                iVar4 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar4 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    iVar4 = iVar4 + -2;
                    *(int*)(param_1 + 2) = iVar4;
                }
                else {
                    (*(code*)param_1[1])(param_1, uVar7, "__option", lVar6, 0);
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar6);
                        iVar4 = *(int*)(param_1 + 2);
                    }
                }
            }
            pcVar8 = (code*)param_1[1];
            *param_1 = lVar6;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar8 != (code*)0x0) {
                (*pcVar8)(param_1, 0, "__group", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar8 = (code*)param_1[1];
            }
            *param_1 = lVar6;
            iVar5 = 1;
        }
        *(int*)(param_1 + 2) = iVar4 + -1;
        if (pcVar8 == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return iVar5;
        }
        (*pcVar8)(param_1, iVar5, "__group", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    else {
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        iVar5 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, iVar5, &__func___4886, lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



undefined8 accept_ext(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    undefined8 uVar6;
    code* pcVar7;
    undefined8 uVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = OWS();
    if ((((cVar4 == '\0') || (cVar4 = __icar(param_1, 0x3b), cVar4 == '\0')) ||
        (cVar4 = OWS(param_1), cVar4 == '\0')) || (cVar4 = token(param_1), cVar4 == '\0')) {
        iVar5 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
        uVar8 = 0;
        goto LAB_0010c777;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar2 = *param_1;
    cVar4 = __icar(param_1, 0x3d);
    iVar5 = *(int*)(param_1 + 2) + 1;
    *(int*)(param_1 + 2) = iVar5;
    if (cVar4 == '\0') {
    LAB_0010c7fe:
        pcVar7 = (code*)param_1[1];
        iVar5 = iVar5 + -1;
        *(int*)(param_1 + 2) = iVar5;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar2, 0);
            iVar5 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar2;
        uVar6 = 0;
    }
    else {
        lVar3 = *param_1;
        cVar4 = token(param_1);
        if (cVar4 == '\0') {
            *param_1 = lVar3;
            cVar4 = quoted_string(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                iVar5 = *(int*)(param_1 + 2);
                goto LAB_0010c7fe;
            }
        }
        iVar5 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar5 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar5 + -3;
            return 1;
        }
        (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2, 0);
        iVar5 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar7 == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar5 + -2;
        return 1;
    }
    uVar8 = 1;
    (*pcVar7)(param_1, uVar6, "__option", lVar1, 0);
    iVar5 = *(int*)(param_1 + 2);
    pcVar7 = (code*)param_1[1];
LAB_0010c777:
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar8, "accept_ext", lVar1, *param_1 - lVar1);
    }
    return uVar8;
}



int charset(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "charset", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int codings(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    iVar3 = (int)cVar2;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "content_coding", lVar1, *param_1 - lVar1);
    }
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __istring(param_1, "IDENTITY");
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __icar(param_1, 0x2a);
            iVar3 = (int)cVar2;
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "codings", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int content_coding(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "content_coding", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined8 Content_Encoding(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    long lVar6;
    undefined8 uVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar6 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar6, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar6 = *param_1;
    }
    *param_1 = lVar6;
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        iVar4 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar4 + 1;
    cVar3 = token(param_1);
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "content_coding", lVar6, *param_1 - lVar6);
        iVar4 = *(int*)(param_1 + 2);
    }
    if (cVar3 == '\0') {
        pcVar5 = (code*)param_1[1];
        uVar7 = 0;
    }
    else {
        while (true) {
            lVar6 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_0010cb86:
                *param_1 = lVar2;
                uVar7 = 0;
            }
            else {
                cVar3 = content_coding(param_1);
                if (cVar3 == '\0') goto LAB_0010cb86;
                uVar7 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar7, "__option", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar6);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar5 = (code*)param_1[1];
        *param_1 = lVar6;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar5 != (code*)0x0) {
            (*pcVar5)(param_1, 0, "__group", lVar6, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
        }
        *param_1 = lVar6;
        uVar7 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar7, "Content_Encoding", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



undefined8 day(long* param_1)

{
    long lVar1;
    char cVar2;
    undefined8 uVar3;
    long lVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __digit();
    lVar4 = lVar1;
    if (cVar2 != '\0') {
        lVar4 = *param_1;
        cVar2 = __digit(param_1);
        uVar3 = 1;
        if (cVar2 != '\0') goto LAB_0010ccf5;
    }
    *param_1 = lVar4;
    uVar3 = 0;
LAB_0010ccf5:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar3, &__func___5010, lVar1, *param_1 - lVar1);
    }
    return uVar3;
}



int day_name(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __num(param_1, &DAT_0011777b);
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __num(param_1, &DAT_0011777f);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __num(param_1, &DAT_00117783);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __num(param_1, &DAT_00117787);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __num(param_1, &DAT_0011778b);
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __num(param_1, &DAT_0011778f);
                        iVar3 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = __num(param_1, &DAT_00117793);
                            iVar3 = (int)cVar2;
                        }
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "day_name", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int day_name_l(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __num(param_1, "Monday");
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __num(param_1, "Tuesday");
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __num(param_1, "Wednesday");
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __num(param_1, "Thursday");
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __num(param_1, "Friday");
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __num(param_1, "Saturday");
                        iVar3 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = __num(param_1, "Sunday");
                            iVar3 = (int)cVar2;
                        }
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "day_name_l", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



bool delay_seconds(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "delay_seconds", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



undefined8 hour(long* param_1)

{
    long lVar1;
    char cVar2;
    undefined8 uVar3;
    long lVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __digit();
    lVar4 = lVar1;
    if (cVar2 != '\0') {
        lVar4 = *param_1;
        cVar2 = __digit(param_1);
        uVar3 = 1;
        if (cVar2 != '\0') goto LAB_0010cff5;
    }
    *param_1 = lVar4;
    uVar3 = 0;
LAB_0010cff5:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar3, &__func___5061, lVar1, *param_1 - lVar1);
    }
    return uVar3;
}



undefined8 minute(long* param_1)

{
    long lVar1;
    char cVar2;
    undefined8 uVar3;
    long lVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __digit();
    lVar4 = lVar1;
    if (cVar2 != '\0') {
        lVar4 = *param_1;
        cVar2 = __digit(param_1);
        uVar3 = 1;
        if (cVar2 != '\0') goto LAB_0010d075;
    }
    *param_1 = lVar4;
    uVar3 = 0;
LAB_0010d075:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar3, "minute", lVar1, *param_1 - lVar1);
    }
    return uVar3;
}



int month(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __num(param_1, &DAT_001177d0);
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __num(param_1, &DAT_001177d4);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __num(param_1, &DAT_001177d8);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __num(param_1, &DAT_001177dc);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __num(param_1, &DAT_001177e0);
                    iVar3 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = __num(param_1, &DAT_001177e4);
                        iVar3 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = __num(param_1, &DAT_001177e8);
                            iVar3 = (int)cVar2;
                            if (cVar2 == '\0') {
                                *param_1 = lVar1;
                                cVar2 = __num(param_1, &DAT_001177ec);
                                iVar3 = (int)cVar2;
                                if (cVar2 == '\0') {
                                    *param_1 = lVar1;
                                    cVar2 = __num(param_1, &DAT_001177f0);
                                    iVar3 = (int)cVar2;
                                    if (cVar2 == '\0') {
                                        *param_1 = lVar1;
                                        cVar2 = __num(param_1, &DAT_001177f4);
                                        iVar3 = (int)cVar2;
                                        if (cVar2 == '\0') {
                                            *param_1 = lVar1;
                                            cVar2 = __num(param_1, &DAT_001177f8);
                                            iVar3 = (int)cVar2;
                                            if (cVar2 == '\0') {
                                                *param_1 = lVar1;
                                                cVar2 = __num(param_1, &DAT_001177fc);
                                                iVar3 = (int)cVar2;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "month", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined4 date2(long* param_1)

{
    long lVar1;
    char cVar2;
    undefined8 uVar3;
    code* pcVar4;
    int iVar5;
    undefined4 uVar6;
    long lVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = __digit();
    if (cVar2 == '\0') {
        iVar5 = 0;
        lVar7 = lVar1;
    LAB_0010d36e:
        pcVar4 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        uVar3 = 0;
        *param_1 = lVar7;
        if (pcVar4 != (code*)0x0) {
        LAB_0010d2a6:
            (*pcVar4)(param_1, uVar3, &__func___5010, lVar1, *param_1 - lVar1);
            if (iVar5 == 2) goto LAB_0010d300;
            goto LAB_0010d2c4;
        }
    }
    else {
        lVar7 = *param_1;
        cVar2 = __digit(param_1);
        iVar5 = 1;
        if (cVar2 == '\0') goto LAB_0010d36e;
        pcVar4 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar4 != (code*)0x0) {
            iVar5 = 2;
            uVar3 = 1;
            goto LAB_0010d2a6;
        }
    LAB_0010d300:
        cVar2 = __icar(param_1, 0x2d);
        if (((cVar2 != '\0') && (cVar2 = month(param_1), cVar2 != '\0')) &&
            (cVar2 = __icar(param_1, 0x2d), cVar2 != '\0')) {
            lVar7 = *param_1;
            cVar2 = __digit(param_1);
            if (cVar2 != '\0') {
                lVar7 = *param_1;
                cVar2 = __digit(param_1);
                if (cVar2 != '\0') {
                    uVar6 = 1;
                    pcVar4 = (code*)param_1[1];
                    goto LAB_0010d2cb;
                }
            }
            *param_1 = lVar7;
            pcVar4 = (code*)param_1[1];
            uVar6 = 0;
            goto LAB_0010d2cb;
        }
    LAB_0010d2c4:
        pcVar4 = (code*)param_1[1];
    }
    uVar6 = 0;
LAB_0010d2cb:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if (pcVar4 != (code*)0x0) {
        (*pcVar4)(param_1, uVar6, "date2", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int date3(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = month();
    if (cVar3 == '\0') {
        iVar4 = *(int*)(param_1 + 2) + 1;
    }
    else {
        cVar3 = __sp(param_1);
        iVar4 = *(int*)(param_1 + 2) + 1;
        *(int*)(param_1 + 2) = iVar4;
        if (cVar3 != '\0') {
            lVar2 = *param_1;
            cVar3 = __digit(param_1);
            if ((cVar3 == '\0') || (cVar3 = __digit(param_1), cVar3 == '\0')) {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                *param_1 = lVar2;
                cVar3 = __sp(param_1);
                if ((cVar3 == '\0') || (cVar3 = __digit(param_1), cVar3 == '\0')) {
                    pcVar6 = (code*)param_1[1];
                    *param_1 = lVar2;
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if (pcVar6 != (code*)0x0) {
                        (*pcVar6)(param_1, 0, "__group", lVar2, 0);
                        iVar4 = *(int*)(param_1 + 2);
                        pcVar6 = (code*)param_1[1];
                    }
                    *param_1 = lVar2;
                    iVar5 = 0;
                }
                else {
                    iVar4 = *(int*)(param_1 + 2);
                    iVar5 = (int)cVar3;
                    *(int*)(param_1 + 2) = iVar4 + -1;
                    if ((code*)param_1[1] == (code*)0x0) {
                        *(int*)(param_1 + 2) = iVar4 + -3;
                        return iVar5;
                    }
                    (*(code*)param_1[1])(param_1, iVar5, "__group", lVar2, 0);
                    iVar4 = *(int*)(param_1 + 2);
                    pcVar6 = (code*)param_1[1];
                }
            }
            else {
                iVar4 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
                iVar5 = 1;
            }
            goto LAB_0010d3cf;
        }
    }
    pcVar6 = (code*)param_1[1];
    iVar5 = 0;
LAB_0010d3cf:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, iVar5, "__group", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "date3", lVar1, *param_1 - lVar1);
        }
        return iVar5;
    }
    *(int*)(param_1 + 2) = iVar4 + -2;
    return iVar5;
}



undefined4 date1(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    undefined8 uVar4;
    code* pcVar5;
    undefined4 uVar6;
    int iVar7;
    long lVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __digit();
    if (cVar3 == '\0') {
        iVar7 = 0;
        lVar8 = lVar1;
    LAB_0010d6be:
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        uVar4 = 0;
        *param_1 = lVar8;
        if (pcVar5 != (code*)0x0) {
        LAB_0010d594:
            (*pcVar5)(param_1, uVar4, &__func___5010, lVar1, *param_1 - lVar1);
            if (iVar7 == 2) goto LAB_0010d5f0;
            pcVar5 = (code*)param_1[1];
        }
        iVar7 = *(int*)(param_1 + 2);
        uVar6 = 0;
    }
    else {
        lVar8 = *param_1;
        cVar3 = __digit(param_1);
        iVar7 = 1;
        if (cVar3 == '\0') goto LAB_0010d6be;
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar5 != (code*)0x0) {
            iVar7 = 2;
            uVar4 = 1;
            goto LAB_0010d594;
        }
    LAB_0010d5f0:
        cVar3 = __sp(param_1);
        if (((cVar3 == '\0') || (cVar3 = month(param_1), cVar3 == '\0')) ||
            (cVar3 = __sp(param_1), cVar3 == '\0')) {
            iVar7 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
            uVar6 = 0;
        }
        else {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar8 = *param_1;
            iVar7 = 0;
            cVar3 = __digit(param_1);
            lVar2 = lVar8;
            while (cVar3 != '\0') {
                iVar7 = iVar7 + 1;
                if (iVar7 == 4) {
                    uVar6 = 1;
                    uVar4 = 1;
                    goto LAB_0010d67b;
                }
                lVar2 = *param_1;
                cVar3 = __digit(param_1);
            }
            *param_1 = lVar2;
            uVar6 = 0;
            uVar4 = 0;
        LAB_0010d67b:
            iVar7 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar7 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar7 + -2;
                return uVar6;
            }
            (*(code*)param_1[1])(param_1, uVar4, &__func___5276, lVar8, *param_1 - lVar8);
            iVar7 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
        }
    }
    *(int*)(param_1 + 2) = iVar7 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar6, "date1", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int parameter(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = token();
    if (cVar3 == '\0') {
        iVar5 = 0;
        iVar4 = *(int*)(param_1 + 2) + 1;
    }
    else {
        cVar3 = __icar(param_1, 0x3d);
        iVar4 = *(int*)(param_1 + 2) + 1;
        *(int*)(param_1 + 2) = iVar4;
        if (cVar3 == '\0') {
            iVar5 = 0;
        }
        else {
            lVar2 = *param_1;
            cVar3 = token(param_1);
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                cVar3 = quoted_string(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar2;
                    iVar4 = *(int*)(param_1 + 2);
                    iVar5 = 0;
                    goto LAB_0010d725;
                }
            }
            iVar4 = *(int*)(param_1 + 2);
            iVar5 = (int)cVar3;
        }
    }
LAB_0010d725:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "__group", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "parameter", lVar1, *param_1 - lVar1);
        }
        return iVar5;
    }
    *(int*)(param_1 + 2) = iVar4 + -2;
    return iVar5;
}



undefined8 media_type(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    undefined8 uVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, &__func___5256, lVar1, *param_1 - lVar1);
    }
    if ((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x2f), cVar3 == '\0')) {
        iVar4 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = token(param_1);
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "subtype", lVar2, *param_1 - lVar2);
            iVar4 = *(int*)(param_1 + 2);
        }
        if (cVar3 == '\0') {
            pcVar5 = (code*)param_1[1];
            uVar6 = 0;
        }
        else {
            while (true) {
                lVar2 = *param_1;
                *(int*)(param_1 + 2) = iVar4 + 1;
                cVar3 = OWS(param_1);
                if ((((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x3b), cVar3 == '\0')) ||
                    (cVar3 = OWS(param_1), cVar3 == '\0')) || (cVar3 = parameter(param_1), cVar3 == '\0'))
                    break;
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar2, 0);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
            pcVar5 = (code*)param_1[1];
            *param_1 = lVar2;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar5 != (code*)0x0) {
                (*pcVar5)(param_1, 0, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar5 = (code*)param_1[1];
            }
            *param_1 = lVar2;
            uVar6 = 1;
        }
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar6, "media_type", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



undefined4 Content_Type(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined4 uVar5;
    undefined4 uVar6;
    code* pcVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar3 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, &__func___5256, lVar1, *param_1 - lVar1);
    }
    if ((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x2f), cVar3 == '\0')) {
        iVar4 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = token(param_1);
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "subtype", lVar2, *param_1 - lVar2);
            iVar4 = *(int*)(param_1 + 2);
        }
        if (cVar3 != '\0') {
            while (true) {
                lVar2 = *param_1;
                *(int*)(param_1 + 2) = iVar4 + 1;
                cVar3 = OWS(param_1);
                if ((((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x3b), cVar3 == '\0')) ||
                    (cVar3 = OWS(param_1), cVar3 == '\0')) || (cVar3 = parameter(param_1), cVar3 == '\0'))
                    break;
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar2, 0);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
            pcVar7 = (code*)param_1[1];
            *param_1 = lVar2;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar7 != (code*)0x0) {
                (*pcVar7)(param_1, 0, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar7 = (code*)param_1[1];
            }
            *param_1 = lVar2;
            uVar6 = 1;
            uVar5 = 1;
            *(int*)(param_1 + 2) = iVar4 + -1;
            goto joined_r0x0010db2e;
        }
        pcVar7 = (code*)param_1[1];
    }
    uVar6 = 0;
    uVar5 = 0;
    *(int*)(param_1 + 2) = iVar4 + -1;
joined_r0x0010db2e:
    if (pcVar7 == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar4 + -2;
        return uVar6;
    }
    (*pcVar7)(param_1, uVar5, "media_type", lVar1, *param_1 - lVar1);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar5, "Content_Type", lVar1, *param_1 - lVar1);
    }
    return uVar5;
}



undefined8 product(long* param_1)

{
    int iVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    undefined8 uVar7;
    code* pcVar8;
    undefined8 uVar9;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar2 = *param_1;
    cVar5 = token();
    if (cVar5 == '\0') {
        iVar6 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        uVar9 = 0;
        goto LAB_0010dbf5;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar3 = *param_1;
    cVar5 = __icar(param_1, 0x2f);
    if (cVar5 == '\0') {
        iVar6 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    LAB_0010dc51:
        iVar6 = iVar6 + -1;
        uVar7 = 0;
        *param_1 = lVar3;
        *(int*)(param_1 + 2) = iVar6;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar4 = *param_1;
        cVar5 = token(param_1);
        iVar1 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        iVar6 = iVar1 + -1;
        *(int*)(param_1 + 2) = iVar6;
        if (pcVar8 == (code*)0x0) {
            if (cVar5 != '\0') {
                iVar6 = iVar1 + -2;
                goto LAB_0010dcf4;
            }
            goto LAB_0010dc51;
        }
        (*pcVar8)(param_1, (int)cVar5, "product_version", lVar4, *param_1 - lVar4);
        iVar6 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        if (cVar5 == '\0') goto LAB_0010dc51;
        iVar6 = iVar6 + -1;
        uVar7 = 1;
        *(int*)(param_1 + 2) = iVar6;
    }
    if (pcVar8 == (code*)0x0) {
    LAB_0010dcf4:
        *(int*)(param_1 + 2) = iVar6 + -1;
        return 1;
    }
    uVar9 = 1;
    (*pcVar8)(param_1, uVar7, "__option", lVar2, 0);
    iVar6 = *(int*)(param_1 + 2);
    pcVar8 = (code*)param_1[1];
LAB_0010dbf5:
    *(int*)(param_1 + 2) = iVar6 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, uVar9, "product", lVar2, *param_1 - lVar2);
    }
    return uVar9;
}



undefined8 Server(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = product();
    if (cVar4 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        uVar7 = 0;
    }
    else {
        iVar5 = *(int*)(param_1 + 2);
        while (true) {
            lVar2 = *param_1;
            *(int*)(param_1 + 2) = iVar5 + 1;
            cVar4 = RWS(param_1);
            iVar5 = *(int*)(param_1 + 2) + 1;
            *(int*)(param_1 + 2) = iVar5;
            if (cVar4 == '\0') break;
            lVar3 = *param_1;
            cVar4 = product(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                cVar4 = comment(param_1);
                if (cVar4 == '\0') {
                    *param_1 = lVar3;
                    iVar5 = *(int*)(param_1 + 2);
                    break;
                }
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
            }
            else {
                (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2, 0);
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2);
                    iVar5 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar5 + -1;
        if (pcVar6 == (code*)0x0) {
            iVar5 = iVar5 + -2;
        }
        else {
            (*pcVar6)(param_1, 0, "__group", lVar2, 0);
            pcVar6 = (code*)param_1[1];
            *param_1 = lVar2;
            iVar5 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar5;
            if (pcVar6 != (code*)0x0) {
                (*pcVar6)(param_1, 0, "__group", lVar2, 0);
                iVar5 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
            }
        }
        *param_1 = lVar2;
        uVar7 = 1;
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, "Server", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



undefined8 User_Agent(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    code* pcVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = product();
    if (cVar4 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        uVar7 = 0;
    }
    else {
        iVar5 = *(int*)(param_1 + 2);
        while (true) {
            lVar2 = *param_1;
            *(int*)(param_1 + 2) = iVar5 + 1;
            cVar4 = RWS(param_1);
            iVar5 = *(int*)(param_1 + 2) + 1;
            *(int*)(param_1 + 2) = iVar5;
            if (cVar4 == '\0') break;
            lVar3 = *param_1;
            cVar4 = product(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                cVar4 = comment(param_1);
                if (cVar4 == '\0') {
                    *param_1 = lVar3;
                    iVar5 = *(int*)(param_1 + 2);
                    break;
                }
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
            }
            else {
                (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2, 0);
                iVar5 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar5;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2);
                    iVar5 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar5 + -1;
        if (pcVar6 == (code*)0x0) {
            iVar5 = iVar5 + -2;
        }
        else {
            (*pcVar6)(param_1, 0, "__group", lVar2, 0);
            pcVar6 = (code*)param_1[1];
            *param_1 = lVar2;
            iVar5 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar5;
            if (pcVar6 != (code*)0x0) {
                (*pcVar6)(param_1, 0, "__group", lVar2, 0);
                iVar5 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
            }
        }
        *param_1 = lVar2;
        uVar7 = 1;
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, "User_Agent", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



int product_version(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "product_version", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined8 qvalue(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    undefined8 uVar4;
    undefined8 uVar5;
    code* pcVar6;
    long lVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = __icar(param_1, 0x30);
    if (cVar2 == '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        *param_1 = lVar1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        *param_1 = lVar1;
        cVar2 = __icar(param_1, 0x31);
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            iVar3 = *(int*)(param_1 + 2);
            uVar4 = 0;
            pcVar6 = (code*)param_1[1];
        }
        else {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar7 = *param_1;
            cVar2 = __icar(param_1, 0x2e);
            if (cVar2 == '\0') {
                *param_1 = lVar7;
                uVar5 = 0;
            }
            else {
                lVar7 = *param_1;
                cVar2 = __icar(param_1, 0x30);
                if (cVar2 != '\0') {
                    lVar7 = *param_1;
                    cVar2 = __icar(param_1, 0x30);
                    if (cVar2 != '\0') {
                        lVar7 = *param_1;
                        cVar2 = __icar(param_1, 0x30);
                        uVar5 = 1;
                        if (cVar2 != '\0') goto LAB_0010e296;
                    }
                }
                *param_1 = lVar7;
                uVar5 = 1;
            }
        LAB_0010e296:
            iVar3 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar3 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar3 + -3;
                return 1;
            }
            uVar4 = 1;
            (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
            iVar3 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
        }
        iVar3 = iVar3 + -1;
        *(int*)(param_1 + 2) = iVar3;
        if (pcVar6 != (code*)0x0) {
            (*pcVar6)(param_1, uVar4, "__group", lVar1, 0);
            iVar3 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
            goto LAB_0010e1ac;
        }
        goto LAB_0010e319;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar7 = *param_1;
    cVar2 = __icar(param_1, 0x2e);
    if (cVar2 == '\0') {
        *param_1 = lVar7;
        uVar4 = 0;
    }
    else {
        lVar7 = *param_1;
        cVar2 = __digit(param_1);
        if (cVar2 != '\0') {
            lVar7 = *param_1;
            cVar2 = __digit(param_1);
            if (cVar2 != '\0') {
                lVar7 = *param_1;
                cVar2 = __digit(param_1);
                uVar4 = 1;
                if (cVar2 != '\0') goto LAB_0010e144;
            }
        }
        *param_1 = lVar7;
        uVar4 = 1;
    }
LAB_0010e144:
    iVar3 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar3 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        iVar3 = iVar3 + -2;
    }
    else {
        (*(code*)param_1[1])(param_1, uVar4, "__option", lVar1, 0);
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "__group", lVar1, 0);
            iVar3 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
            uVar4 = 1;
        LAB_0010e1ac:
            *(int*)(param_1 + 2) = iVar3 + -1;
            if (pcVar6 != (code*)0x0) {
                (*pcVar6)(param_1, uVar4, "qvalue", lVar1, *param_1 - lVar1);
            }
            return uVar4;
        }
    }
    uVar4 = 1;
LAB_0010e319:
    *(int*)(param_1 + 2) = iVar3 + -1;
    return uVar4;
}



undefined8 second(long* param_1)

{
    long lVar1;
    char cVar2;
    undefined8 uVar3;
    long lVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __digit();
    lVar4 = lVar1;
    if (cVar2 != '\0') {
        lVar4 = *param_1;
        cVar2 = __digit(param_1);
        uVar3 = 1;
        if (cVar2 != '\0') goto LAB_0010e3b5;
    }
    *param_1 = lVar4;
    uVar3 = 0;
LAB_0010e3b5:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, uVar3, "second", lVar1, *param_1 - lVar1);
    }
    return uVar3;
}



int subtype(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "subtype", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined8 time_of_day(long* param_1)

{
    long lVar1;
    bool bVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    undefined8 uVar6;
    code* pcVar7;
    long lVar8;
    long lVar9;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __digit();
    if (cVar3 == '\0') {
        iVar4 = 0;
        lVar9 = lVar1;
    LAB_0010e616:
        pcVar7 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        uVar5 = 0;
        *param_1 = lVar9;
        if (pcVar7 != (code*)0x0) {
        LAB_0010e4a4:
            (*pcVar7)(param_1, uVar5, &__func___5061, lVar1, *param_1 - lVar1);
            if (iVar4 == 2) goto LAB_0010e500;
        LAB_0010e4c2:
            pcVar7 = (code*)param_1[1];
        }
    LAB_0010e4c6:
        iVar4 = *(int*)(param_1 + 2);
        uVar5 = 0;
        goto LAB_0010e4cc;
    }
    lVar9 = *param_1;
    cVar3 = __digit(param_1);
    iVar4 = 1;
    if (cVar3 == '\0') goto LAB_0010e616;
    pcVar7 = (code*)param_1[1];
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if (pcVar7 != (code*)0x0) {
        uVar5 = 1;
        iVar4 = 2;
        goto LAB_0010e4a4;
    }
LAB_0010e500:
    cVar3 = __icar(param_1, 0x3a);
    if (cVar3 != '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar9 = *param_1;
        cVar3 = __digit(param_1);
        lVar8 = lVar9;
        if (cVar3 == '\0') {
        LAB_0010e64b:
            pcVar7 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            *param_1 = lVar8;
            if (pcVar7 == (code*)0x0) goto LAB_0010e4c6;
            uVar5 = 0;
            bVar2 = false;
        LAB_0010e560:
            (*pcVar7)(param_1, uVar5, "minute", lVar9, lVar8 - lVar9);
            if (!bVar2) goto LAB_0010e4c2;
        }
        else {
            lVar8 = *param_1;
            cVar3 = __digit(param_1);
            if (cVar3 == '\0') goto LAB_0010e64b;
            pcVar7 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar7 != (code*)0x0) {
                lVar8 = *param_1;
                uVar5 = 1;
                bVar2 = true;
                goto LAB_0010e560;
            }
        }
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar9 = *param_1;
            cVar3 = __digit(param_1);
            lVar8 = lVar9;
            if (cVar3 == '\0') {
            LAB_0010e673:
                *param_1 = lVar8;
                uVar5 = 0;
                uVar6 = 0;
            }
            else {
                lVar8 = *param_1;
                cVar3 = __digit(param_1);
                uVar5 = 1;
                uVar6 = 1;
                if (cVar3 == '\0') goto LAB_0010e673;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar4 + -2;
                return uVar5;
            }
            (*(code*)param_1[1])(param_1, uVar6, "second", lVar9, *param_1 - lVar9);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
            goto LAB_0010e4cc;
        }
    }
    iVar4 = *(int*)(param_1 + 2);
    pcVar7 = (code*)param_1[1];
    uVar5 = 0;
LAB_0010e4cc:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar5, "time_of_day", lVar1, *param_1 - lVar1);
    }
    return uVar5;
}



int rfc850_date(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    int iVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __num(param_1, "Monday");
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Tuesday");
        if (cVar3 != '\0') goto LAB_0010e6b9;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Wednesday");
        if (cVar3 != '\0') goto LAB_0010e6b9;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Thursday");
        if (cVar3 != '\0') goto LAB_0010e6b9;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Friday");
        if (cVar3 != '\0') goto LAB_0010e6b9;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Saturday");
        if (cVar3 != '\0') goto LAB_0010e6b9;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Sunday");
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar5 != (code*)0x0) goto LAB_0010e6ca;
    LAB_0010e6e6:
        if (cVar3 != '\0') goto LAB_0010e7f0;
    }
    else {
    LAB_0010e6b9:
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar5 != (code*)0x0) {
        LAB_0010e6ca:
            (*pcVar5)(param_1, (int)cVar3, "day_name_l", lVar1, *param_1 - lVar1);
            goto LAB_0010e6e6;
        }
    LAB_0010e7f0:
        cVar3 = __icar(param_1, 0x2c);
        if ((((cVar3 != '\0') && (cVar3 = __sp(param_1), cVar3 != '\0')) &&
            (cVar3 = date2(param_1), cVar3 != '\0')) &&
            (((cVar3 = __sp(param_1), cVar3 != '\0' && (cVar3 = time_of_day(param_1), cVar3 != '\0')) &&
                (cVar3 = __sp(param_1), cVar3 != '\0')))) {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = __num(param_1, &DAT_0011776e);
            iVar4 = *(int*)(param_1 + 2);
            iVar6 = (int)cVar3;
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar4 + -2;
                return iVar6;
            }
            (*(code*)param_1[1])(param_1, iVar6, &__func___4764, lVar2, *param_1 - lVar2);
            iVar4 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
            goto LAB_0010e6f9;
        }
    }
    iVar4 = *(int*)(param_1 + 2);
    pcVar5 = (code*)param_1[1];
    iVar6 = 0;
LAB_0010e6f9:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, iVar6, "rfc850_date", lVar1, *param_1 - lVar1);
    }
    return iVar6;
}



undefined4 asctime_date(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    undefined4 uVar6;
    undefined8 uVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = day_name();
    if ((((cVar4 == '\0') || (cVar4 = __sp(param_1), cVar4 == '\0')) ||
        (cVar4 = date3(param_1), cVar4 == '\0')) ||
        (((cVar4 = __sp(param_1), cVar4 == '\0' || (cVar4 = time_of_day(param_1), cVar4 == '\0')) ||
            (cVar4 = __sp(param_1), cVar4 == '\0')))) {
        iVar5 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        iVar5 = 0;
        cVar4 = __digit(param_1);
        lVar3 = lVar2;
        while (cVar4 != '\0') {
            iVar5 = iVar5 + 1;
            if (iVar5 == 4) {
                uVar6 = 1;
                uVar7 = 1;
                goto LAB_0010e9ca;
            }
            lVar3 = *param_1;
            cVar4 = __digit(param_1);
        }
        *param_1 = lVar3;
        uVar6 = 0;
        uVar7 = 0;
    LAB_0010e9ca:
        iVar5 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar5 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar5 + -2;
            return uVar6;
        }
        (*(code*)param_1[1])(param_1, uVar7, &__func___5276, lVar2, *param_1 - lVar2);
        iVar5 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, uVar6, "asctime_date", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int IMF_fixdate(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = day_name();
    if ((((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x2c), cVar3 == '\0')) ||
        (cVar3 = __sp(param_1), cVar3 == '\0')) ||
        (((cVar3 = date1(param_1), cVar3 == '\0' || (cVar3 = __sp(param_1), cVar3 == '\0')) ||
            ((cVar3 = time_of_day(param_1), cVar3 == '\0' || (cVar3 = __sp(param_1), cVar3 == '\0')))))) {
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        iVar5 = 0;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = __num(param_1, &DAT_0011776e);
        iVar4 = *(int*)(param_1 + 2);
        iVar5 = (int)cVar3;
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return iVar5;
        }
        (*(code*)param_1[1])(param_1, iVar5, &__func___4764, lVar2, *param_1 - lVar2);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, iVar5, "IMF_fixdate", lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



int HTTP_date(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    int iVar6;
    int iVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = day_name();
    if ((((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x2c), cVar3 == '\0')) ||
        (cVar3 = __sp(param_1), cVar3 == '\0')) ||
        (((cVar3 = date1(param_1), cVar3 == '\0' || (cVar3 = __sp(param_1), cVar3 == '\0')) ||
            ((cVar3 = time_of_day(param_1), cVar3 == '\0' || (cVar3 = __sp(param_1), cVar3 == '\0')))))) {
        pcVar5 = (code*)param_1[1];
        iVar7 = 0;
        iVar6 = 0;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar5 != (code*)0x0) {
        LAB_0010eb78:
            (*pcVar5)(param_1, iVar7, "IMF_fixdate", lVar1, *param_1 - lVar1);
            iVar4 = *(int*)(param_1 + 2);
            goto LAB_0010eb93;
        }
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = __num(param_1, &DAT_0011776e);
        iVar4 = *(int*)(param_1 + 2);
        iVar6 = (int)cVar3;
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar4 = iVar4 + -2;
            *(int*)(param_1 + 2) = iVar4;
        }
        else {
            iVar7 = (int)cVar3;
            (*(code*)param_1[1])(param_1, iVar7, &__func___4764, lVar2, *param_1 - lVar2);
            pcVar5 = (code*)param_1[1];
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar5 != (code*)0x0) goto LAB_0010eb78;
        }
    LAB_0010eb93:
        if ((char)iVar6 != '\0') goto LAB_0010eb9c;
    }
    *param_1 = lVar1;
    *(int*)(param_1 + 2) = iVar4 + 1;
    cVar3 = rfc850_date(param_1);
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        cVar3 = asctime_date(param_1);
    }
    iVar6 = (int)cVar3;
    iVar4 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar4 + -2;
        return iVar6;
    }
    (*(code*)param_1[1])(param_1, iVar6, "obs_date", lVar1, *param_1 - lVar1);
    iVar4 = *(int*)(param_1 + 2);
LAB_0010eb9c:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar6, "HTTP_date", lVar1, *param_1 - lVar1);
    }
    return iVar6;
}



int Date(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = HTTP_date();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, &__func___4750, lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int Retry_After(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    code* pcVar4;
    long lVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = HTTP_date();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        iVar3 = 0;
        lVar5 = lVar1;
        while (true) {
            cVar2 = __digit(param_1);
            if (cVar2 == '\0') break;
            lVar5 = *param_1;
            iVar3 = iVar3 + 1;
        }
        pcVar4 = (code*)param_1[1];
        cVar2 = 0 < iVar3;
        *param_1 = lVar5;
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if (pcVar4 != (code*)0x0) {
            (*pcVar4)(param_1, cVar2, "delay_seconds", lVar1, lVar5 - lVar1);
            iVar3 = *(int*)(param_1 + 2);
            pcVar4 = (code*)param_1[1];
        }
    }
    else {
        pcVar4 = (code*)param_1[1];
        iVar3 = *(int*)(param_1 + 2);
    }
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar4 != (code*)0x0) {
        (*pcVar4)(param_1, (int)cVar2, "Retry_After", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int obs_date(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    int iVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar3 = __num(param_1, "Monday");
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Tuesday");
        if (cVar3 != '\0') goto LAB_0010ee9a;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Wednesday");
        if (cVar3 != '\0') goto LAB_0010ee9a;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Thursday");
        if (cVar3 != '\0') goto LAB_0010ee9a;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Friday");
        if (cVar3 != '\0') goto LAB_0010ee9a;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Saturday");
        if (cVar3 != '\0') goto LAB_0010ee9a;
        *param_1 = lVar1;
        cVar3 = __num(param_1, "Sunday");
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar5 != (code*)0x0) goto LAB_0010eeab;
    LAB_0010eec7:
        if (cVar3 != '\0') goto LAB_0010f018;
    LAB_0010eed0:
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar6 = 0;
        iVar4 = 0;
        if (pcVar5 != (code*)0x0) {
        LAB_0010eee5:
            (*pcVar5)(param_1, iVar6, "rfc850_date", lVar1, *param_1 - lVar1);
            goto LAB_0010eefd;
        }
    }
    else {
    LAB_0010ee9a:
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar5 != (code*)0x0) {
        LAB_0010eeab:
            (*pcVar5)(param_1, (int)cVar3, "day_name_l", lVar1, *param_1 - lVar1);
            goto LAB_0010eec7;
        }
    LAB_0010f018:
        cVar3 = __icar(param_1, 0x2c);
        if ((((cVar3 == '\0') || (cVar3 = __sp(param_1), cVar3 == '\0')) ||
            (cVar3 = date2(param_1), cVar3 == '\0')) ||
            (((cVar3 = __sp(param_1), cVar3 == '\0' || (cVar3 = time_of_day(param_1), cVar3 == '\0')) ||
                (cVar3 = __sp(param_1), cVar3 == '\0')))) goto LAB_0010eed0;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = __num(param_1, &DAT_0011776e);
        iVar6 = *(int*)(param_1 + 2);
        iVar4 = (int)cVar3;
        *(int*)(param_1 + 2) = iVar6 + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            iVar6 = (int)cVar3;
            (*(code*)param_1[1])(param_1, iVar6, &__func___4764, lVar2, *param_1 - lVar2);
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 == (code*)0x0) goto LAB_0010eefd;
            goto LAB_0010eee5;
        }
        *(int*)(param_1 + 2) = iVar6 + -2;
    LAB_0010eefd:
        if ((char)iVar4 != '\0') goto LAB_0010ef06;
    }
    *param_1 = lVar1;
    cVar3 = asctime_date(param_1);
    iVar4 = (int)cVar3;
LAB_0010ef06:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "obs_date", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int type(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, &__func___5256, lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined8 media_range(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    char cVar4;
    int iVar5;
    code* pcVar6;
    undefined8 uVar7;
    int iVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, &DAT_00117800);
    if (cVar3 == '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
        *param_1 = lVar1;
        cVar4 = token(param_1);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar4, &__func___5256, lVar1, *param_1 - lVar1);
        }
        if ((cVar4 != '\0') && (cVar4 = __icar(param_1, 0x2f), cVar4 != '\0')) {
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar4 = token(param_1);
            iVar8 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
            iVar5 = iVar8 + -1;
            *(int*)(param_1 + 2) = iVar5;
            if (pcVar6 != (code*)0x0) {
                iVar8 = (int)cVar4;
                (*pcVar6)(param_1, iVar8, "subtype", lVar2, *param_1 - lVar2);
                iVar5 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
                if (cVar4 == '\0') goto LAB_0010f2ed;
                iVar5 = iVar5 + -1;
                *(int*)(param_1 + 2) = iVar5;
                if (pcVar6 == (code*)0x0) goto LAB_0010f321;
                goto LAB_0010f300;
            }
            if (cVar4 == '\0') goto LAB_0010f2ed;
            iVar5 = iVar8 + -2;
        LAB_0010f321:
            iVar5 = iVar5 + -1;
            *(int*)(param_1 + 2) = iVar5;
            goto joined_r0x0010f32d;
        }
        pcVar6 = (code*)param_1[1];
        iVar5 = *(int*)(param_1 + 2);
    LAB_0010f2ed:
        iVar5 = iVar5 + -1;
        iVar8 = 0;
        *param_1 = lVar1;
        *(int*)(param_1 + 2) = iVar5;
        cVar4 = cVar3;
        if (pcVar6 != (code*)0x0) {
        LAB_0010f300:
            (*pcVar6)(param_1, iVar8, "__group", lVar1, 0);
            iVar5 = *(int*)(param_1 + 2);
            if (cVar4 != '\0') {
                pcVar6 = (code*)param_1[1];
                goto LAB_0010f321;
            }
        }
        *param_1 = lVar1;
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = type(param_1);
        if ((cVar4 == '\0') || (cVar4 = __istring(param_1, &DAT_00117801), cVar4 == '\0')) {
            iVar8 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
            iVar5 = 0;
            *param_1 = lVar1;
            *(int*)(param_1 + 2) = iVar8 + -1;
            cVar4 = cVar3;
            if (pcVar6 == (code*)0x0) {
                *param_1 = lVar1;
                *(int*)(param_1 + 2) = iVar8 + -3;
                return 0;
            }
        LAB_0010f38e:
            (*pcVar6)(param_1, iVar5, "__group", lVar1, 0);
            iVar5 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
            if (cVar4 == '\0') {
                *param_1 = lVar1;
                *(int*)(param_1 + 2) = iVar5 + -1;
                if (pcVar6 == (code*)0x0) {
                    *(int*)(param_1 + 2) = iVar5 + -2;
                    return 0;
                }
                uVar7 = 0;
                (*pcVar6)(param_1, 0, "__group", lVar1, 0);
                iVar5 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
                goto LAB_0010f1ef;
            }
            goto LAB_0010f188;
        }
        iVar5 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar5 + -1;
        if (pcVar6 != (code*)0x0) {
            iVar5 = (int)cVar4;
            goto LAB_0010f38e;
        }
        iVar5 = iVar5 + -2;
    }
    else {
        iVar5 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        cVar4 = cVar3;
    LAB_0010f188:
        iVar5 = iVar5 + -1;
        *(int*)(param_1 + 2) = iVar5;
    joined_r0x0010f32d:
        if (pcVar6 != (code*)0x0) {
            (*pcVar6)(param_1, (int)cVar4, "__group", lVar1, 0);
            iVar5 = *(int*)(param_1 + 2);
        }
    }
    while (true) {
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar3 = OWS(param_1);
        if ((((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x3b), cVar3 == '\0')) ||
            (cVar3 = OWS(param_1), cVar3 == '\0')) || (cVar3 = parameter(param_1), cVar3 == '\0'))
            break;
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar2, 0);
            iVar5 = *(int*)(param_1 + 2);
        }
    }
    pcVar6 = (code*)param_1[1];
    *param_1 = lVar2;
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, 0, "__group", lVar2, 0);
        iVar5 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
    }
    *param_1 = lVar2;
    uVar7 = 1;
LAB_0010f1ef:
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar7, "media_range", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



int weight(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = OWS();
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3b);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = __istring(param_1, &DAT_00117737);
                if (cVar2 != '\0') {
                    cVar2 = qvalue(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_0010f519;
                }
            }
        }
    }
    iVar3 = 0;
LAB_0010f519:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "weight", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined4 Accept_Charset(long* param_1)

{
    int iVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    long lVar5;
    char cVar6;
    int iVar7;
    undefined4 uVar8;
    long lVar9;
    undefined8 uVar10;
    code* pcVar11;

    lVar2 = *param_1;
    iVar7 = *(int*)(param_1 + 2) + 1;
    lVar9 = lVar2;
    while (true) {
        *(int*)(param_1 + 2) = iVar7 + 1;
        cVar6 = __icar(param_1, 0x2c);
        if ((cVar6 == '\0') || (cVar6 = OWS(param_1), cVar6 == '\0')) break;
        iVar7 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar7;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar6, "__group", lVar9, 0);
            iVar7 = *(int*)(param_1 + 2);
        }
        lVar9 = *param_1;
    }
    *param_1 = lVar9;
    iVar7 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar7;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar9, 0);
        iVar7 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar9;
    *(int*)(param_1 + 2) = iVar7 + 2;
    uVar8 = charset(param_1);
    if ((char)uVar8 == '\0') {
        *param_1 = lVar9;
        uVar8 = __icar(param_1, 0x2a, uVar8);
        if ((char)uVar8 == '\0') {
            iVar7 = *(int*)(param_1 + 2);
            *param_1 = lVar9;
            *(int*)(param_1 + 2) = iVar7 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *param_1 = lVar9;
                iVar7 = iVar7 + -2;
            LAB_0010f923:
                *(int*)(param_1 + 2) = iVar7 + -1;
                return 0;
            }
            (*(code*)param_1[1])(param_1, 0, "__group", lVar9, 0);
            *param_1 = lVar9;
            iVar7 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar7;
            if ((code*)param_1[1] == (code*)0x0) goto LAB_0010f923;
            uVar8 = 0;
            (*(code*)param_1[1])(param_1, 0, "__group", lVar2, 0);
            iVar7 = *(int*)(param_1 + 2);
            pcVar11 = (code*)param_1[1];
            goto LAB_0010f720;
        }
    }
    iVar7 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar7;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)(char)uVar8, "__group", lVar9, 0);
        iVar7 = *(int*)(param_1 + 2);
    }
    lVar3 = *param_1;
    *(int*)(param_1 + 2) = iVar7 + 1;
    cVar6 = weight(param_1);
    if (cVar6 == '\0') {
        *param_1 = lVar3;
    }
    iVar7 = *(int*)(param_1 + 2);
    *(int*)(param_1 + 2) = iVar7 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        iVar7 = iVar7 + -2;
    }
    else {
        (*(code*)param_1[1])(param_1, cVar6 != '\0', "__option", lVar9, 0);
        iVar7 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar7;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "__group", lVar2, 0);
            iVar7 = *(int*)(param_1 + 2);
        }
    }
    lVar9 = *param_1;
    while (true) {
        *(int*)(param_1 + 2) = iVar7 + 1;
        cVar6 = OWS(param_1);
        if ((cVar6 == '\0') || (cVar6 = __icar(param_1, 0x2c), cVar6 == '\0')) break;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar3 = *param_1;
        cVar6 = OWS(param_1);
        iVar1 = *(int*)(param_1 + 2);
        iVar7 = iVar1 + 1;
        *(int*)(param_1 + 2) = iVar7;
        if (cVar6 == '\0') {
            pcVar11 = (code*)param_1[1];
        LAB_0010f813:
            *(int*)(param_1 + 2) = iVar7 + -1;
            if (pcVar11 == (code*)0x0) {
                iVar7 = iVar7 + -3;
                *param_1 = lVar3;
                *(int*)(param_1 + 2) = iVar7;
                lVar9 = lVar3;
            }
            else {
                (*pcVar11)(param_1, 0, "__group", lVar3);
                iVar7 = *(int*)(param_1 + 2);
                pcVar11 = (code*)param_1[1];
                uVar10 = 0;
                *param_1 = lVar3;
            LAB_0010f841:
                iVar7 = iVar7 + -1;
                *(int*)(param_1 + 2) = iVar7;
                if (pcVar11 == (code*)0x0) goto LAB_0010f8ab;
                (*pcVar11)(param_1, uVar10, "__option", lVar9);
                iVar7 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar7;
                if ((code*)param_1[1] == (code*)0x0) goto LAB_0010f8b1;
                (*(code*)param_1[1])(param_1, 1, "__group", lVar9);
                iVar7 = *(int*)(param_1 + 2);
                lVar9 = *param_1;
            }
        }
        else {
            *(int*)(param_1 + 2) = iVar1 + 2;
            lVar4 = *param_1;
            uVar8 = charset(param_1);
            if ((char)uVar8 == '\0') {
                *param_1 = lVar4;
                uVar8 = __icar(param_1, 0x2a, uVar8);
                if ((char)uVar8 != '\0') goto LAB_0010f94d;
                iVar7 = *(int*)(param_1 + 2);
                *param_1 = lVar4;
                *(int*)(param_1 + 2) = iVar7 + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
                    iVar7 = *(int*)(param_1 + 2);
                    pcVar11 = (code*)param_1[1];
                    *param_1 = lVar4;
                    goto LAB_0010f813;
                }
                *param_1 = lVar3;
                iVar7 = iVar7 + -3;
            LAB_0010f8ab:
                iVar7 = iVar7 + -1;
                *(int*)(param_1 + 2) = iVar7;
            LAB_0010f8b1:
                lVar9 = *param_1;
            }
            else {
            LAB_0010f94d:
                iVar7 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar7;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)(char)uVar8, "__group", lVar4);
                    iVar7 = *(int*)(param_1 + 2);
                }
                lVar5 = *param_1;
                *(int*)(param_1 + 2) = iVar7 + 1;
                cVar6 = weight(param_1);
                if (cVar6 == '\0') {
                    *param_1 = lVar5;
                }
                iVar7 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar7 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    iVar7 = iVar7 + -4;
                    lVar9 = *param_1;
                    *(int*)(param_1 + 2) = iVar7;
                }
                else {
                    (*(code*)param_1[1])(param_1, cVar6 != '\0', "__option", lVar4);
                    iVar7 = *(int*)(param_1 + 2);
                    *(int*)(param_1 + 2) = iVar7 + -1;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar3);
                        iVar7 = *(int*)(param_1 + 2);
                        pcVar11 = (code*)param_1[1];
                        uVar10 = 1;
                        goto LAB_0010f841;
                    }
                    iVar7 = iVar7 + -3;
                    lVar9 = *param_1;
                    *(int*)(param_1 + 2) = iVar7;
                }
            }
        }
    }
    pcVar11 = (code*)param_1[1];
    *param_1 = lVar9;
    iVar7 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar7;
    if (pcVar11 != (code*)0x0) {
        (*pcVar11)(param_1, 0, "__group", lVar9, 0);
        iVar7 = *(int*)(param_1 + 2);
        pcVar11 = (code*)param_1[1];
    }
    *param_1 = lVar9;
    uVar8 = 1;
LAB_0010f720:
    *(int*)(param_1 + 2) = iVar7 + -1;
    if (pcVar11 != (code*)0x0) {
        (*pcVar11)(param_1, uVar8, "Accept_Charset", lVar2, *param_1 - lVar2);
    }
    return uVar8;
}



undefined8 Accept_Encoding(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    long lVar7;
    undefined8 uVar8;
    code* pcVar9;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar5 = __icar(param_1, 0x2c);
    if (cVar5 == '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        *param_1 = lVar1;
        cVar5 = codings(param_1);
        if (cVar5 == '\0') {
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            uVar8 = 0;
            *param_1 = lVar1;
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar9 != (code*)0x0) goto LAB_0010fd88;
            iVar6 = iVar6 + -2;
        LAB_0010fddb:
            *param_1 = lVar1;
            uVar8 = 0;
        LAB_0010fba0:
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar9 == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar6 + -2;
            }
            else {
                (*pcVar9)(param_1, uVar8, "__option", lVar1, 0);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "Accept_Encoding", lVar1, *param_1 - lVar1);
                }
            }
            return 1;
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar7 = *param_1;
        cVar5 = weight(param_1);
        if (cVar5 == '\0') {
            *param_1 = lVar7;
        }
        iVar6 = *(int*)(param_1 + 2);
        pcVar9 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar6 + -1;
        if (pcVar9 == (code*)0x0) {
            iVar6 = iVar6 + -2;
            cVar5 = '\x01';
        }
        else {
            (*pcVar9)(param_1, cVar5 != '\0', "__option", lVar1, 0);
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar9 == (code*)0x0) {
                iVar6 = iVar6 + -2;
                goto LAB_0010fb3e;
            }
            uVar8 = 1;
            cVar5 = '\x01';
        LAB_0010fd88:
            (*pcVar9)(param_1, uVar8, "__group", lVar1, 0);
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            if (cVar5 == '\0') {
                iVar6 = iVar6 + -1;
                *param_1 = lVar1;
                *(int*)(param_1 + 2) = iVar6;
                if (pcVar9 != (code*)0x0) {
                    (*pcVar9)(param_1, 0, "__group", lVar1, 0);
                    iVar6 = *(int*)(param_1 + 2);
                    pcVar9 = (code*)param_1[1];
                }
                goto LAB_0010fddb;
            }
        }
    }
    else {
        pcVar9 = (code*)param_1[1];
        iVar6 = *(int*)(param_1 + 2);
    }
    iVar6 = iVar6 + -1;
    *(int*)(param_1 + 2) = iVar6;
    if (pcVar9 != (code*)0x0) {
        (*pcVar9)(param_1, (int)cVar5, "__group", lVar1, 0);
        iVar6 = *(int*)(param_1 + 2);
    }
LAB_0010fb3e:
    lVar7 = *param_1;
LAB_0010fb48:
    do {
        while (true) {
            *(int*)(param_1 + 2) = iVar6 + 1;
            cVar5 = OWS(param_1);
            if ((cVar5 == '\0') || (cVar5 = __icar(param_1, 0x2c), cVar5 == '\0')) goto LAB_0010fb5f;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar5 = OWS(param_1);
            iVar6 = *(int*)(param_1 + 2) + 1;
            *(int*)(param_1 + 2) = iVar6;
            if (cVar5 == '\0') break;
            lVar3 = *param_1;
            cVar5 = codings(param_1);
            if (cVar5 == '\0') {
                *param_1 = lVar3;
                iVar6 = *(int*)(param_1 + 2);
                break;
            }
            lVar4 = *param_1;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            cVar5 = weight(param_1);
            if (cVar5 == '\0') {
                *param_1 = lVar4;
            }
            iVar6 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar6 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar6 = iVar6 + -4;
                lVar7 = *param_1;
                *(int*)(param_1 + 2) = iVar6;
            }
            else {
                (*(code*)param_1[1])(param_1, cVar5 != '\0', "__option", lVar3, 0);
                iVar6 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar6 + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar2);
                    iVar6 = *(int*)(param_1 + 2);
                    pcVar9 = (code*)param_1[1];
                    uVar8 = 1;
                    goto LAB_0010fc7e;
                }
                iVar6 = iVar6 + -3;
                lVar7 = *param_1;
                *(int*)(param_1 + 2) = iVar6;
            }
        }
        *(int*)(param_1 + 2) = iVar6 + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar2);
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            uVar8 = 0;
            *param_1 = lVar2;
        LAB_0010fc7e:
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar9 == (code*)0x0) {
                iVar6 = iVar6 + -2;
                *(int*)(param_1 + 2) = iVar6;
            }
            else {
                (*pcVar9)(param_1, uVar8, "__option", lVar7);
                iVar6 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar6;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar7);
                    iVar6 = *(int*)(param_1 + 2);
                    lVar7 = *param_1;
                    goto LAB_0010fb48;
                }
            }
            lVar7 = *param_1;
            goto LAB_0010fb48;
        }
        iVar6 = iVar6 + -3;
        *param_1 = lVar2;
        *(int*)(param_1 + 2) = iVar6;
        lVar7 = lVar2;
    } while (true);
LAB_0010fb5f:
    pcVar9 = (code*)param_1[1];
    *param_1 = lVar7;
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if (pcVar9 != (code*)0x0) {
        (*pcVar9)(param_1, 0, "__group", lVar7, 0);
        iVar6 = *(int*)(param_1 + 2);
        pcVar9 = (code*)param_1[1];
    }
    *param_1 = lVar7;
    uVar8 = 1;
    goto LAB_0010fba0;
}



undefined4 Accept_Language(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    undefined4 uVar7;
    long lVar8;
    undefined8 uVar9;
    code* pcVar10;

    lVar1 = *param_1;
    iVar6 = *(int*)(param_1 + 2) + 1;
    lVar8 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar6 + 1;
        cVar5 = __icar(param_1, 0x2c);
        if ((cVar5 == '\0') || (cVar5 = OWS(param_1), cVar5 == '\0')) break;
        iVar6 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar6;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar5, "__group", lVar8, 0);
            iVar6 = *(int*)(param_1 + 2);
        }
        lVar8 = *param_1;
    }
    *param_1 = lVar8;
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar8, 0);
        iVar6 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar8;
    *(int*)(param_1 + 2) = iVar6 + 1;
    cVar5 = language_range(param_1);
    if (cVar5 != '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar5 = weight(param_1);
        if (cVar5 == '\0') {
            *param_1 = lVar2;
        }
        iVar6 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar6 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar6 = iVar6 + -2;
        }
        else {
            (*(code*)param_1[1])(param_1, cVar5 != '\0', "__option", lVar8, 0);
            iVar6 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar6;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar1, 0);
                iVar6 = *(int*)(param_1 + 2);
            }
        }
        lVar8 = *param_1;
    LAB_0011001f:
        do {
            while (true) {
                *(int*)(param_1 + 2) = iVar6 + 1;
                cVar5 = OWS(param_1);
                if ((cVar5 == '\0') || (cVar5 = __icar(param_1, 0x2c), cVar5 == '\0')) goto LAB_00110035;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar5 = OWS(param_1);
                iVar6 = *(int*)(param_1 + 2) + 1;
                *(int*)(param_1 + 2) = iVar6;
                if (cVar5 != '\0') break;
            LAB_00110137:
                *(int*)(param_1 + 2) = iVar6 + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0, "__group", lVar2);
                    iVar6 = *(int*)(param_1 + 2);
                    pcVar10 = (code*)param_1[1];
                    uVar9 = 0;
                    *param_1 = lVar2;
                    goto LAB_00110169;
                }
                iVar6 = iVar6 + -3;
                *param_1 = lVar2;
                *(int*)(param_1 + 2) = iVar6;
                lVar8 = lVar2;
            }
            lVar3 = *param_1;
            cVar5 = language_range(param_1);
            if (cVar5 == '\0') {
                *param_1 = lVar3;
                iVar6 = *(int*)(param_1 + 2);
                goto LAB_00110137;
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar4 = *param_1;
            cVar5 = weight(param_1);
            if (cVar5 == '\0') {
                *param_1 = lVar4;
            }
            iVar6 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar6 + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, cVar5 != '\0', "__option", lVar3, 0);
                iVar6 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar6 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    iVar6 = iVar6 + -3;
                    lVar8 = *param_1;
                    *(int*)(param_1 + 2) = iVar6;
                    goto LAB_0011001f;
                }
                (*(code*)param_1[1])(param_1, 1, "__group", lVar2);
                iVar6 = *(int*)(param_1 + 2);
                pcVar10 = (code*)param_1[1];
                uVar9 = 1;
            LAB_00110169:
                *(int*)(param_1 + 2) = iVar6 + -1;
                if (pcVar10 == (code*)0x0) {
                    iVar6 = iVar6 + -2;
                    *(int*)(param_1 + 2) = iVar6;
                }
                else {
                    (*pcVar10)(param_1, uVar9, "__option", lVar8);
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar8);
                        iVar6 = *(int*)(param_1 + 2);
                        lVar8 = *param_1;
                        goto LAB_0011001f;
                    }
                }
                lVar8 = *param_1;
                goto LAB_0011001f;
            }
            iVar6 = iVar6 + -4;
            lVar8 = *param_1;
            *(int*)(param_1 + 2) = iVar6;
        } while (true);
    }
    iVar6 = *(int*)(param_1 + 2);
    *param_1 = lVar8;
    *(int*)(param_1 + 2) = iVar6 + -1;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar6 + -2;
        return 0;
    }
    uVar7 = 0;
    (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
    iVar6 = *(int*)(param_1 + 2);
    pcVar10 = (code*)param_1[1];
LAB_00110078:
    *(int*)(param_1 + 2) = iVar6 + -1;
    if (pcVar10 != (code*)0x0) {
        (*pcVar10)(param_1, uVar7, "Accept_Language", lVar1, *param_1 - lVar1);
    }
    return uVar7;
LAB_00110035:
    pcVar10 = (code*)param_1[1];
    *param_1 = lVar8;
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if (pcVar10 != (code*)0x0) {
        (*pcVar10)(param_1, 0, "__group", lVar8, 0);
        iVar6 = *(int*)(param_1 + 2);
        pcVar10 = (code*)param_1[1];
    }
    *param_1 = lVar8;
    uVar7 = 1;
    goto LAB_00110078;
}



undefined8 accept_params(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    long lVar6;
    undefined8 uVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = weight();
    if (cVar4 == '\0') {
        uVar7 = 0;
        pcVar8 = (code*)param_1[1];
    LAB_0011038d:
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar8 != (code*)0x0) {
            (*pcVar8)(param_1, uVar7, "accept_params", lVar1, *param_1 - lVar1);
        }
        return uVar7;
    }
    iVar5 = *(int*)(param_1 + 2);
LAB_00110341:
    lVar6 = *param_1;
LAB_00110348:
    do {
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = OWS(param_1);
        if (cVar4 == '\0') {
        LAB_0011035a:
            pcVar8 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar8 != (code*)0x0) {
                (*pcVar8)(param_1, 0, "accept_ext", lVar6, *param_1 - lVar6);
                pcVar8 = (code*)param_1[1];
            }
            *param_1 = lVar6;
            uVar7 = 1;
            goto LAB_0011038d;
        }
        cVar4 = __icar(param_1, 0x3b);
        if (cVar4 == '\0') goto LAB_0011035a;
        cVar4 = OWS(param_1);
        if (cVar4 == '\0') goto LAB_0011035a;
        cVar4 = token(param_1);
        if (cVar4 == '\0') goto LAB_0011035a;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar4 = __icar(param_1, 0x3d);
        iVar5 = *(int*)(param_1 + 2) + 1;
        *(int*)(param_1 + 2) = iVar5;
        if (cVar4 == '\0') {
        LAB_0011042e:
            *(int*)(param_1 + 2) = iVar5 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar5 = iVar5 + -3;
                *param_1 = lVar2;
                *(int*)(param_1 + 2) = iVar5;
                lVar6 = lVar2;
                goto LAB_00110348;
            }
            (*(code*)param_1[1])(param_1, 0, "__group", lVar2);
            iVar5 = *(int*)(param_1 + 2);
            pcVar8 = (code*)param_1[1];
            uVar7 = 0;
            *param_1 = lVar2;
        LAB_00110464:
            *(int*)(param_1 + 2) = iVar5 + -1;
            if (pcVar8 == (code*)0x0) {
                iVar5 = iVar5 + -2;
                *(int*)(param_1 + 2) = iVar5;
                lVar6 = *param_1;
                goto LAB_00110348;
            }
            (*pcVar8)(param_1, uVar7, "__option", lVar6);
            iVar5 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar5;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "accept_ext", lVar6);
                iVar5 = *(int*)(param_1 + 2);
                lVar6 = *param_1;
                goto LAB_00110348;
            }
            goto LAB_00110341;
        }
        lVar3 = *param_1;
        cVar4 = token(param_1);
        if (cVar4 == '\0') {
            *param_1 = lVar3;
            cVar4 = quoted_string(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                iVar5 = *(int*)(param_1 + 2);
                goto LAB_0011042e;
            }
        }
        iVar5 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar5 + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2, 0);
            iVar5 = *(int*)(param_1 + 2);
            pcVar8 = (code*)param_1[1];
            uVar7 = 1;
            goto LAB_00110464;
        }
        iVar5 = iVar5 + -3;
        lVar6 = *param_1;
        *(int*)(param_1 + 2) = iVar5;
    } while (true);
}



undefined8 Accept(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    long lVar7;
    undefined8 uVar8;
    code* pcVar9;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar5 = __icar(param_1, 0x2c);
    if (cVar5 == '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        *param_1 = lVar1;
        cVar5 = media_range(param_1);
        if (cVar5 == '\0') {
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            uVar8 = 0;
            *param_1 = lVar1;
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar9 != (code*)0x0) goto LAB_00110818;
            iVar6 = iVar6 + -2;
        LAB_0011086b:
            *param_1 = lVar1;
            uVar8 = 0;
        LAB_00110630:
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar9 == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar6 + -2;
            }
            else {
                (*pcVar9)(param_1, uVar8, "__option", lVar1, 0);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "Accept", lVar1, *param_1 - lVar1);
                }
            }
            return 1;
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar7 = *param_1;
        cVar5 = accept_params(param_1);
        if (cVar5 == '\0') {
            *param_1 = lVar7;
        }
        iVar6 = *(int*)(param_1 + 2);
        pcVar9 = (code*)param_1[1];
        *(int*)(param_1 + 2) = iVar6 + -1;
        if (pcVar9 == (code*)0x0) {
            iVar6 = iVar6 + -2;
            cVar5 = '\x01';
        }
        else {
            (*pcVar9)(param_1, cVar5 != '\0', "__option", lVar1, 0);
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar9 == (code*)0x0) {
                iVar6 = iVar6 + -2;
                goto LAB_001105ce;
            }
            uVar8 = 1;
            cVar5 = '\x01';
        LAB_00110818:
            (*pcVar9)(param_1, uVar8, "__group", lVar1, 0);
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            if (cVar5 == '\0') {
                iVar6 = iVar6 + -1;
                *param_1 = lVar1;
                *(int*)(param_1 + 2) = iVar6;
                if (pcVar9 != (code*)0x0) {
                    (*pcVar9)(param_1, 0, "__group", lVar1, 0);
                    iVar6 = *(int*)(param_1 + 2);
                    pcVar9 = (code*)param_1[1];
                }
                goto LAB_0011086b;
            }
        }
    }
    else {
        pcVar9 = (code*)param_1[1];
        iVar6 = *(int*)(param_1 + 2);
    }
    iVar6 = iVar6 + -1;
    *(int*)(param_1 + 2) = iVar6;
    if (pcVar9 != (code*)0x0) {
        (*pcVar9)(param_1, (int)cVar5, "__group", lVar1, 0);
        iVar6 = *(int*)(param_1 + 2);
    }
LAB_001105ce:
    lVar7 = *param_1;
LAB_001105d8:
    do {
        while (true) {
            *(int*)(param_1 + 2) = iVar6 + 1;
            cVar5 = OWS(param_1);
            if ((cVar5 == '\0') || (cVar5 = __icar(param_1, 0x2c), cVar5 == '\0')) goto LAB_001105ef;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar5 = OWS(param_1);
            iVar6 = *(int*)(param_1 + 2) + 1;
            *(int*)(param_1 + 2) = iVar6;
            if (cVar5 == '\0') break;
            lVar3 = *param_1;
            cVar5 = media_range(param_1);
            if (cVar5 == '\0') {
                *param_1 = lVar3;
                iVar6 = *(int*)(param_1 + 2);
                break;
            }
            lVar4 = *param_1;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            cVar5 = accept_params(param_1);
            if (cVar5 == '\0') {
                *param_1 = lVar4;
            }
            iVar6 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar6 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar6 = iVar6 + -4;
                lVar7 = *param_1;
                *(int*)(param_1 + 2) = iVar6;
            }
            else {
                (*(code*)param_1[1])(param_1, cVar5 != '\0', "__option", lVar3, 0);
                iVar6 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar6 + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar2);
                    iVar6 = *(int*)(param_1 + 2);
                    pcVar9 = (code*)param_1[1];
                    uVar8 = 1;
                    goto LAB_0011070e;
                }
                iVar6 = iVar6 + -3;
                lVar7 = *param_1;
                *(int*)(param_1 + 2) = iVar6;
            }
        }
        *(int*)(param_1 + 2) = iVar6 + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar2);
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            uVar8 = 0;
            *param_1 = lVar2;
        LAB_0011070e:
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar9 == (code*)0x0) {
                iVar6 = iVar6 + -2;
                *(int*)(param_1 + 2) = iVar6;
            }
            else {
                (*pcVar9)(param_1, uVar8, "__option", lVar7);
                iVar6 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar6;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar7);
                    iVar6 = *(int*)(param_1 + 2);
                    lVar7 = *param_1;
                    goto LAB_001105d8;
                }
            }
            lVar7 = *param_1;
            goto LAB_001105d8;
        }
        iVar6 = iVar6 + -3;
        *param_1 = lVar2;
        *(int*)(param_1 + 2) = iVar6;
        lVar7 = lVar2;
    } while (true);
LAB_001105ef:
    pcVar9 = (code*)param_1[1];
    *param_1 = lVar7;
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if (pcVar9 != (code*)0x0) {
        (*pcVar9)(param_1, 0, "__group", lVar7, 0);
        iVar6 = *(int*)(param_1 + 2);
        pcVar9 = (code*)param_1[1];
    }
    *param_1 = lVar7;
    uVar8 = 1;
    goto LAB_00110630;
}



undefined4 year(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined4 uVar5;

    iVar4 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __digit(param_1);
    lVar2 = lVar1;
    do {
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            uVar5 = 0;
        LAB_001109f5:
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, uVar5, &__func___5276, lVar1, *param_1 - lVar1);
            }
            return uVar5;
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == 4) {
            uVar5 = 1;
            goto LAB_001109f5;
        }
        lVar2 = *param_1;
        cVar3 = __digit(param_1);
    } while (true);
}



int If_Modified_Since(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = HTTP_date();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "If_Modified_Since", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int If_Unmodified_Since(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = HTTP_date();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "If_Unmodified_Since", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int Last_Modified(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = HTTP_date();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "Last_Modified", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int etagc(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __icar(param_1, 0x21);
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __range(param_1, 0x23, 0x7e);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "etagc", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int opaque_tag(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;

    iVar4 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __dquote();
    if (cVar3 != '\0') {
        iVar4 = *(int*)(param_1 + 2);
    LAB_00110bc0:
        *(int*)(param_1 + 2) = iVar4 + 1;
        lVar2 = *param_1;
        cVar3 = __icar(param_1, 0x21);
        if (cVar3 != '\0') goto code_r0x00110be3;
        *param_1 = lVar2;
        cVar3 = __range(param_1, 0x23, 0x7e);
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar5 != (code*)0x0) goto LAB_00110bf5;
        goto LAB_00110c0d;
    }
LAB_00110c30:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "opaque_tag", lVar1, *param_1 - lVar1);
    }
    return iVar4;
code_r0x00110be3:
    pcVar5 = (code*)param_1[1];
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if (pcVar5 == (code*)0x0) goto LAB_00110bc0;
LAB_00110bf5:
    (*pcVar5)(param_1, (int)cVar3, "etagc", lVar2, *param_1 - lVar2);
LAB_00110c0d:
    if (cVar3 != '\0') {
        iVar4 = *(int*)(param_1 + 2);
        goto LAB_00110bc0;
    }
    *param_1 = lVar2;
    cVar3 = __dquote(param_1);
    iVar4 = (int)cVar3;
    goto LAB_00110c30;
}



int entity_tag(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar2 = *param_1;
    cVar3 = __num(param_1, &DAT_00117804);
    iVar1 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
    iVar4 = iVar1 + -1;
    *(int*)(param_1 + 2) = iVar4;
    if (pcVar6 == (code*)0x0) {
        if (cVar3 != '\0') {
            *(int*)(param_1 + 2) = iVar1 + -2;
            goto LAB_00110d22;
        }
    LAB_00110d70:
        *param_1 = lVar2;
        uVar5 = 0;
    }
    else {
        (*pcVar6)(param_1, (int)cVar3, &__func___5407, lVar2, *param_1 - lVar2);
        iVar4 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        uVar5 = 1;
        if (cVar3 == '\0') goto LAB_00110d70;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, uVar5, "__option", lVar2, 0);
    }
LAB_00110d22:
    cVar3 = opaque_tag(param_1);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "entity_tag", lVar2, *param_1 - lVar2);
    }
    return (int)cVar3;
}



int ETag(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = entity_tag();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, &__func___5284, lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int If_Match(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    long lVar6;
    undefined8 uVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x2a);
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        iVar4 = *(int*)(param_1 + 2) + 1;
        lVar6 = lVar1;
        while (true) {
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
            lVar6 = *param_1;
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        *param_1 = lVar6;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        }
        *param_1 = lVar6;
        cVar3 = entity_tag(param_1);
        if (cVar3 == '\0') {
            iVar4 = *(int*)(param_1 + 2);
            pcVar8 = (code*)param_1[1];
            iVar5 = 0;
            *param_1 = lVar1;
        }
        else {
            iVar4 = *(int*)(param_1 + 2);
            while (true) {
                lVar6 = *param_1;
                *(int*)(param_1 + 2) = iVar4 + 1;
                cVar3 = OWS(param_1);
                if (cVar3 == '\0') break;
                cVar3 = __icar(param_1, 0x2c);
                if (cVar3 == '\0') break;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = OWS(param_1);
                if (cVar3 == '\0') {
                LAB_00110fc6:
                    *param_1 = lVar2;
                    uVar7 = 0;
                }
                else {
                    cVar3 = entity_tag(param_1);
                    if (cVar3 == '\0') goto LAB_00110fc6;
                    uVar7 = 1;
                }
                iVar4 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar4 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    iVar4 = iVar4 + -2;
                    *(int*)(param_1 + 2) = iVar4;
                }
                else {
                    (*(code*)param_1[1])(param_1, uVar7, "__option", lVar6, 0);
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar6);
                        iVar4 = *(int*)(param_1 + 2);
                    }
                }
            }
            pcVar8 = (code*)param_1[1];
            *param_1 = lVar6;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar8 != (code*)0x0) {
                (*pcVar8)(param_1, 0, "__group", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar8 = (code*)param_1[1];
            }
            *param_1 = lVar6;
            iVar5 = 1;
        }
        *(int*)(param_1 + 2) = iVar4 + -1;
        if (pcVar8 == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return iVar5;
        }
        (*pcVar8)(param_1, iVar5, "__group", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    else {
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        iVar5 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, iVar5, "If_Match", lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



int If_None_Match(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    long lVar6;
    undefined8 uVar7;
    code* pcVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x2a);
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        iVar4 = *(int*)(param_1 + 2) + 1;
        lVar6 = lVar1;
        while (true) {
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
            lVar6 = *param_1;
        }
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        *param_1 = lVar6;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        }
        *param_1 = lVar6;
        cVar3 = entity_tag(param_1);
        if (cVar3 == '\0') {
            iVar4 = *(int*)(param_1 + 2);
            pcVar8 = (code*)param_1[1];
            iVar5 = 0;
            *param_1 = lVar1;
        }
        else {
            iVar4 = *(int*)(param_1 + 2);
            while (true) {
                lVar6 = *param_1;
                *(int*)(param_1 + 2) = iVar4 + 1;
                cVar3 = OWS(param_1);
                if (cVar3 == '\0') break;
                cVar3 = __icar(param_1, 0x2c);
                if (cVar3 == '\0') break;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = OWS(param_1);
                if (cVar3 == '\0') {
                LAB_00111246:
                    *param_1 = lVar2;
                    uVar7 = 0;
                }
                else {
                    cVar3 = entity_tag(param_1);
                    if (cVar3 == '\0') goto LAB_00111246;
                    uVar7 = 1;
                }
                iVar4 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar4 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    iVar4 = iVar4 + -2;
                    *(int*)(param_1 + 2) = iVar4;
                }
                else {
                    (*(code*)param_1[1])(param_1, uVar7, "__option", lVar6, 0);
                    iVar4 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar4;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar6);
                        iVar4 = *(int*)(param_1 + 2);
                    }
                }
            }
            pcVar8 = (code*)param_1[1];
            *param_1 = lVar6;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar8 != (code*)0x0) {
                (*pcVar8)(param_1, 0, "__group", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar8 = (code*)param_1[1];
            }
            *param_1 = lVar6;
            iVar5 = 1;
        }
        *(int*)(param_1 + 2) = iVar4 + -1;
        if (pcVar8 == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return iVar5;
        }
        (*pcVar8)(param_1, iVar5, "__group", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    else {
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        iVar5 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, iVar5, "If_None_Match", lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



int weak(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __num(param_1, &DAT_00117804);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, &__func___5407, lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int If_Range(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = entity_tag();
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = HTTP_date(param_1);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "If_Range", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



bool byte_range(long* param_1)

{
    long lVar1;
    char cVar2;
    bool bVar3;
    int iVar4;
    code* pcVar5;
    long lVar6;
    long lVar7;

    iVar4 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar6 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar6 = *param_1;
        iVar4 = iVar4 + 1;
    }
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar4, "first_byte_pos", lVar1, lVar6 - lVar1);
    }
    if (iVar4 != 0) {
        cVar2 = __icar(param_1, 0x2d);
        if (cVar2 != '\0') {
            lVar6 = *param_1;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            iVar4 = 0;
            lVar7 = lVar6;
            while (true) {
                cVar2 = __digit(param_1);
                if (cVar2 == '\0') break;
                lVar7 = *param_1;
                iVar4 = iVar4 + 1;
            }
            pcVar5 = (code*)param_1[1];
            bVar3 = 0 < iVar4;
            *param_1 = lVar7;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar5 != (code*)0x0) {
                (*pcVar5)(param_1, bVar3, "last_byte_pos", lVar6, lVar7 - lVar6);
                iVar4 = *(int*)(param_1 + 2);
                pcVar5 = (code*)param_1[1];
            }
            goto LAB_001113f3;
        }
    }
    iVar4 = *(int*)(param_1 + 2);
    pcVar5 = (code*)param_1[1];
    bVar3 = false;
LAB_001113f3:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, bVar3, "byte_range", lVar1, *param_1 - lVar1);
    }
    return bVar3;
}



uint byte_range_resp(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    char cVar4;
    int iVar5;
    uint uVar6;
    bool bVar7;
    code* pcVar8;
    long lVar9;
    long lVar10;

    iVar5 = 0;
    lVar2 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar10 = lVar2;
    while (cVar3 = __digit(param_1), cVar3 != '\0') {
        lVar10 = *param_1;
        iVar5 = iVar5 + 1;
    }
    *param_1 = lVar10;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar5, "first_byte_pos", lVar2, lVar10 - lVar2);
    }
    if ((iVar5 == 0) || (cVar4 = __icar(param_1, 0x2d), cVar4 == '\0')) {
        pcVar8 = (code*)param_1[1];
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        bVar7 = false;
        if (pcVar8 != (code*)0x0) {
        LAB_00111535:
            (*pcVar8)(param_1, bVar7, "byte_range", lVar2, *param_1 - lVar2);
            goto LAB_0011154d;
        }
    }
    else {
        lVar10 = *param_1;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        iVar5 = 0;
        lVar9 = lVar10;
        while (cVar3 = __digit(param_1), cVar3 != '\0') {
            lVar9 = *param_1;
            iVar5 = iVar5 + 1;
        }
        iVar1 = *(int*)(param_1 + 2);
        cVar3 = 0 < iVar5;
        *param_1 = lVar9;
        *(int*)(param_1 + 2) = iVar1 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar1 + -2;
        }
        else {
            (*(code*)param_1[1])(param_1, cVar3, "last_byte_pos", lVar10, lVar9 - lVar10);
            pcVar8 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            bVar7 = (bool)cVar3;
            if (pcVar8 != (code*)0x0) goto LAB_00111535;
        }
    LAB_0011154d:
        if (cVar3 != '\0') {
            cVar3 = __icar(param_1, 0x2f);
            iVar1 = *(int*)(param_1 + 2);
            iVar5 = iVar1 + 1;
            *(int*)(param_1 + 2) = iVar5;
            if (cVar3 == '\0') {
                pcVar8 = (code*)param_1[1];
                uVar6 = 0;
            }
            else {
                lVar10 = *param_1;
                uVar6 = 0;
                *(int*)(param_1 + 2) = iVar1 + 2;
                lVar9 = lVar10;
                while (cVar3 = __digit(param_1), cVar3 != '\0') {
                    lVar9 = *param_1;
                    uVar6 = uVar6 + 1;
                }
                *param_1 = lVar9;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0 < (int)uVar6, "complete_length", lVar10, lVar9 - lVar10);
                }
                if (uVar6 == 0) {
                    *param_1 = lVar10;
                    cVar3 = __icar(param_1, 0x2a);
                    if (cVar3 == '\0') {
                        *param_1 = lVar10;
                        iVar5 = *(int*)(param_1 + 2);
                        pcVar8 = (code*)param_1[1];
                    }
                    else {
                        iVar5 = *(int*)(param_1 + 2);
                        pcVar8 = (code*)param_1[1];
                        uVar6 = (uint)cVar3;
                    }
                }
                else {
                    iVar5 = *(int*)(param_1 + 2);
                    pcVar8 = (code*)param_1[1];
                    uVar6 = (uint)(0 < (int)uVar6);
                }
            }
            goto LAB_0011155e;
        }
        iVar5 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    iVar5 = iVar5 + 1;
    uVar6 = 0;
LAB_0011155e:
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar8 == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar5 + -2;
    }
    else {
        (*pcVar8)(param_1, uVar6, "__group", lVar2, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, uVar6, "byte_range_resp", lVar2, *param_1 - lVar2);
        }
    }
    return uVar6;
}



undefined4 byte_range_spec(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined4 uVar5;
    int iVar6;
    undefined8 uVar7;
    code* pcVar8;
    long lVar9;
    long lVar10;

    iVar6 = 0;
    lVar2 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar9 = lVar2;
    while (true) {
        cVar3 = __digit(param_1);
        if (cVar3 == '\0') break;
        lVar9 = *param_1;
        iVar6 = iVar6 + 1;
    }
    *param_1 = lVar9;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar6, "first_byte_pos", lVar2, lVar9 - lVar2);
    }
    if (iVar6 != 0) {
        cVar3 = __icar(param_1, 0x2d);
        if (cVar3 != '\0') {
            lVar9 = *param_1;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
            iVar6 = 0;
            lVar10 = lVar9;
            while (true) {
                cVar3 = __digit(param_1);
                if (cVar3 == '\0') break;
                lVar10 = *param_1;
                iVar6 = iVar6 + 1;
            }
            iVar1 = *(int*)(param_1 + 2);
            pcVar8 = (code*)param_1[1];
            *param_1 = lVar10;
            iVar4 = iVar1 + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar8 == (code*)0x0) {
                if (iVar6 != 0) {
                    iVar4 = iVar1 + -2;
                    goto LAB_001118a3;
                }
            LAB_001118b9:
                *param_1 = lVar9;
                uVar7 = 0;
            }
            else {
                (*pcVar8)(param_1, 0 < iVar6, "last_byte_pos", lVar9, lVar10 - lVar9);
                iVar4 = *(int*)(param_1 + 2);
                pcVar8 = (code*)param_1[1];
                uVar7 = 1;
                if (iVar6 == 0) goto LAB_001118b9;
            }
            iVar4 = iVar4 + -1;
            *(int*)(param_1 + 2) = iVar4;
            if (pcVar8 == (code*)0x0) {
            LAB_001118a3:
                *(int*)(param_1 + 2) = iVar4 + -1;
                return 1;
            }
            uVar5 = 1;
            (*pcVar8)(param_1, uVar7, "__option", lVar2, 0);
            iVar6 = *(int*)(param_1 + 2);
            pcVar8 = (code*)param_1[1];
            goto LAB_001117b3;
        }
    }
    iVar6 = *(int*)(param_1 + 2);
    pcVar8 = (code*)param_1[1];
    uVar5 = 0;
LAB_001117b3:
    *(int*)(param_1 + 2) = iVar6 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, uVar5, "byte_range_spec", lVar2, *param_1 - lVar2);
    }
    return uVar5;
}



int bytes_unit(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "BYTES");
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "bytes_unit", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



bool complete_length(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "complete_length", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



bool first_byte_pos(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "first_byte_pos", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



bool last_byte_pos(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "last_byte_pos", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



undefined8 other_content_range(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    long lVar6;
    undefined8 uVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "other_range_unit", lVar1, *param_1 - lVar1);
    }
    if ((cVar3 == '\0') || (cVar3 = __sp(param_1), cVar3 == '\0')) {
        iVar4 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
        uVar7 = 0;
    }
    else {
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar6 = lVar2;
        while (cVar3 = __char(param_1), cVar3 != '\0') {
            lVar6 = *param_1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *param_1 = lVar6;
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return 1;
        }
        uVar7 = 1;
        (*(code*)param_1[1])(param_1, 1, "other_range_resp", lVar2, lVar6 - lVar2);
        iVar4 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar7, "other_content_range", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



undefined8 other_range_resp(long* param_1)

{
    long lVar1;
    char cVar2;
    long lVar3;

    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar3 = lVar1;
    while (true) {
        cVar2 = __char(param_1);
        if (cVar2 == '\0') break;
        lVar3 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar3;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 1, "other_range_resp", lVar1, lVar3 - lVar1);
    }
    return 1;
}



bool other_range_set(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __vchar(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "other_range_set", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



int other_range_unit(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "other_range_unit", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



bool other_ranges_specifier(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    bool bVar4;
    int iVar5;
    code* pcVar6;
    long lVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "other_range_unit", lVar1, *param_1 - lVar1);
    }
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3d);
        if (cVar3 != '\0') {
            lVar2 = *param_1;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            iVar5 = 0;
            lVar7 = lVar2;
            while (true) {
                cVar3 = __vchar(param_1);
                if (cVar3 == '\0') break;
                lVar7 = *param_1;
                iVar5 = iVar5 + 1;
            }
            pcVar6 = (code*)param_1[1];
            bVar4 = 0 < iVar5;
            *param_1 = lVar7;
            iVar5 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar5;
            if (pcVar6 != (code*)0x0) {
                (*pcVar6)(param_1, bVar4, "other_range_set", lVar2, lVar7 - lVar2);
                iVar5 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
            }
            goto LAB_00111d2f;
        }
    }
    iVar5 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
    bVar4 = false;
LAB_00111d2f:
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, bVar4, "other_ranges_specifier", lVar1, *param_1 - lVar1);
    }
    return bVar4;
}



int range_unit(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "BYTES");
    iVar3 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar3;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "bytes_unit", lVar1, *param_1 - lVar1);
        iVar3 = *(int*)(param_1 + 2);
    }
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = token(param_1);
        iVar3 = *(int*)(param_1 + 2);
        iVar4 = (int)cVar2;
        *(int*)(param_1 + 2) = iVar3 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar3 + -2;
            return iVar4;
        }
        (*(code*)param_1[1])(param_1, iVar4, "other_range_unit", lVar1, *param_1 - lVar1);
        iVar3 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
    }
    else {
        pcVar5 = (code*)param_1[1];
        iVar4 = (int)cVar2;
    }
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, iVar4, "range_unit", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int acceptable_ranges(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    long lVar6;
    undefined8 uVar7;
    code* pcVar8;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 2;
    lVar6 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if ((cVar3 == '\0') || (cVar3 = OWS(param_1), cVar3 == '\0')) break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar6, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar6 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar6;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
    }
    *param_1 = lVar6;
    cVar3 = range_unit(param_1);
    if (cVar3 == '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        *param_1 = lVar1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
        }
        *param_1 = lVar1;
        cVar3 = __istring(param_1, &DAT_0011780d);
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
        iVar5 = (int)cVar3;
    }
    else {
        iVar4 = *(int*)(param_1 + 2);
        while (true) {
            lVar6 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if ((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x2c), cVar3 == '\0')) break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if ((cVar3 == '\0') || (cVar3 = range_unit(param_1), cVar3 == '\0')) {
                *param_1 = lVar2;
                uVar7 = 0;
            }
            else {
                uVar7 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar7, "__option", lVar6, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar6);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        iVar4 = *(int*)(param_1 + 2);
        *param_1 = lVar6;
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *param_1 = lVar6;
            *(int*)(param_1 + 2) = iVar4 + -3;
            return 1;
        }
        (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        iVar4 = *(int*)(param_1 + 2);
        *param_1 = lVar6;
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar4 + -2;
            return 1;
        }
        iVar5 = 1;
        (*(code*)param_1[1])(param_1, 1, "__group", lVar1, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar8 = (code*)param_1[1];
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar8 != (code*)0x0) {
        (*pcVar8)(param_1, iVar5, "acceptable_ranges", lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



int Accept_Ranges(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = acceptable_ranges();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "Accept_Ranges", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



bool suffix_byte_range_spec(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    bool bVar4;
    int iVar5;
    code* pcVar6;
    long lVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __icar(param_1, 0x2d);
    if (cVar3 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        bVar4 = false;
    }
    else {
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        iVar5 = 0;
        lVar7 = lVar2;
        while (true) {
            cVar3 = __digit(param_1);
            if (cVar3 == '\0') break;
            lVar7 = *param_1;
            iVar5 = iVar5 + 1;
        }
        pcVar6 = (code*)param_1[1];
        bVar4 = 0 < iVar5;
        *param_1 = lVar7;
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if (pcVar6 != (code*)0x0) {
            (*pcVar6)(param_1, bVar4, "suffix_length", lVar2, lVar7 - lVar2);
            iVar5 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
        }
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, bVar4, "suffix_byte_range_spec", lVar1, *param_1 - lVar1);
    }
    return bVar4;
}



undefined4 byte_range_set(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    int iVar6;
    undefined4 uVar7;
    long lVar8;
    undefined8 uVar9;
    code* pcVar10;

    lVar1 = *param_1;
    iVar5 = *(int*)(param_1 + 2) + 1;
    lVar8 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar5 + 1;
        cVar4 = __icar(param_1, 0x2c);
        if ((cVar4 == '\0') || (cVar4 = OWS(param_1), cVar4 == '\0')) break;
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar8, 0);
            iVar5 = *(int*)(param_1 + 2);
        }
        lVar8 = *param_1;
    }
    *param_1 = lVar8;
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar8, 0);
        iVar5 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar8;
    *(int*)(param_1 + 2) = iVar5 + 1;
    cVar4 = byte_range_spec(param_1);
    iVar5 = (int)cVar4;
    if (cVar4 == '\0') {
        *param_1 = lVar8;
        cVar4 = suffix_byte_range_spec(param_1, iVar5);
        iVar5 = (int)cVar4;
        if (cVar4 == '\0') {
            iVar5 = *(int*)(param_1 + 2);
            *param_1 = lVar8;
            *(int*)(param_1 + 2) = iVar5 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                *(int*)(param_1 + 2) = iVar5 + -2;
                return 0;
            }
            uVar7 = 0;
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
            iVar5 = *(int*)(param_1 + 2);
            pcVar10 = (code*)param_1[1];
            goto LAB_001123c8;
        }
    }
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "__group", lVar1, 0);
        iVar6 = *(int*)(param_1 + 2);
    }
    lVar8 = *param_1;
    while (true) {
        *(int*)(param_1 + 2) = iVar6 + 1;
        cVar4 = OWS(param_1);
        if ((cVar4 == '\0') || (cVar4 = __icar(param_1, 0x2c), cVar4 == '\0')) break;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar4 = OWS(param_1);
        iVar6 = *(int*)(param_1 + 2) + 1;
        *(int*)(param_1 + 2) = iVar6;
        if (cVar4 == '\0') {
        LAB_001124bf:
            *(int*)(param_1 + 2) = iVar6 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar6 = iVar6 + -3;
                *param_1 = lVar2;
                *(int*)(param_1 + 2) = iVar6;
                lVar8 = lVar2;
            }
            else {
                (*(code*)param_1[1])(param_1, 0, "__group", lVar2);
                iVar6 = *(int*)(param_1 + 2);
                pcVar10 = (code*)param_1[1];
                uVar9 = 0;
                *param_1 = lVar2;
            LAB_001124f1:
                *(int*)(param_1 + 2) = iVar6 + -1;
                if (pcVar10 == (code*)0x0) {
                    iVar6 = iVar6 + -2;
                    *(int*)(param_1 + 2) = iVar6;
                    lVar8 = *param_1;
                }
                else {
                    (*pcVar10)(param_1, uVar9, "__option", lVar8);
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, 1, "__group", lVar8);
                        iVar6 = *(int*)(param_1 + 2);
                    }
                    lVar8 = *param_1;
                }
            }
        }
        else {
            lVar3 = *param_1;
            cVar4 = byte_range_spec(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                cVar4 = suffix_byte_range_spec(param_1);
                if (cVar4 == '\0') {
                    *param_1 = lVar3;
                    iVar6 = *(int*)(param_1 + 2);
                    goto LAB_001124bf;
                }
            }
            iVar6 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar6 + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2, 0);
                iVar6 = *(int*)(param_1 + 2);
                pcVar10 = (code*)param_1[1];
                uVar9 = 1;
                goto LAB_001124f1;
            }
            iVar6 = iVar6 + -3;
            lVar8 = *param_1;
            *(int*)(param_1 + 2) = iVar6;
        }
    }
    pcVar10 = (code*)param_1[1];
    *param_1 = lVar8;
    iVar5 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar5;
    if (pcVar10 != (code*)0x0) {
        (*pcVar10)(param_1, 0, "__group", lVar8, 0);
        iVar5 = *(int*)(param_1 + 2);
        pcVar10 = (code*)param_1[1];
    }
    *param_1 = lVar8;
    uVar7 = 1;
LAB_001123c8:
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar10 != (code*)0x0) {
        (*pcVar10)(param_1, uVar7, "byte_range_set", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



int byte_ranges_specifier(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "BYTES");
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "bytes_unit", lVar1, *param_1 - lVar1);
    }
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3d);
        if (cVar2 != '\0') {
            cVar2 = byte_range_set(param_1);
            iVar3 = (int)cVar2;
            goto LAB_0011265f;
        }
    }
    iVar3 = 0;
LAB_0011265f:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "byte_ranges_specifier", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Range(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "BYTES");
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "bytes_unit", lVar1, *param_1 - lVar1);
    }
    if (cVar2 == '\0') {
    LAB_0011270b:
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar4 = 0;
        iVar3 = 0;
        if (pcVar5 != (code*)0x0) {
        LAB_00112720:
            (*pcVar5)(param_1, iVar4, "byte_ranges_specifier", lVar1, *param_1 - lVar1);
            goto LAB_00112738;
        }
    }
    else {
        cVar2 = __icar(param_1, 0x3d);
        if (cVar2 == '\0') goto LAB_0011270b;
        cVar2 = byte_range_set(param_1);
        pcVar5 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar3 = (int)cVar2;
        if (pcVar5 != (code*)0x0) {
            iVar4 = (int)cVar2;
            goto LAB_00112720;
        }
    LAB_00112738:
        if ((char)iVar3 != '\0') goto LAB_0011273d;
    }
    *param_1 = lVar1;
    cVar2 = other_ranges_specifier(param_1);
    iVar3 = (int)cVar2;
LAB_0011273d:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Range", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



bool suffix_length(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "suffix_length", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



bool unsatisfied_range(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    bool bVar4;
    int iVar5;
    code* pcVar6;
    long lVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, &DAT_00117812);
    if (cVar3 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        bVar4 = false;
    }
    else {
        lVar2 = *param_1;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        iVar5 = 0;
        lVar7 = lVar2;
        while (true) {
            cVar3 = __digit(param_1);
            if (cVar3 == '\0') break;
            lVar7 = *param_1;
            iVar5 = iVar5 + 1;
        }
        pcVar6 = (code*)param_1[1];
        bVar4 = 0 < iVar5;
        *param_1 = lVar7;
        iVar5 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar5;
        if (pcVar6 != (code*)0x0) {
            (*pcVar6)(param_1, bVar4, "complete_length", lVar2, lVar7 - lVar2);
            iVar5 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
        }
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, bVar4, "unsatisfied_range", lVar1, *param_1 - lVar1);
    }
    return bVar4;
}



int byte_content_range(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "BYTES");
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "bytes_unit", lVar1, *param_1 - lVar1);
    }
    if (cVar3 == '\0') {
        iVar5 = 0;
        iVar4 = *(int*)(param_1 + 2) + 1;
    }
    else {
        cVar3 = __sp(param_1);
        iVar4 = *(int*)(param_1 + 2) + 1;
        *(int*)(param_1 + 2) = iVar4;
        if (cVar3 == '\0') {
            iVar5 = 0;
        }
        else {
            lVar2 = *param_1;
            cVar3 = byte_range_resp(param_1);
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                cVar3 = unsatisfied_range(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar2;
                    iVar4 = *(int*)(param_1 + 2);
                    iVar5 = 0;
                    goto LAB_0011296f;
                }
            }
            iVar4 = *(int*)(param_1 + 2);
            iVar5 = (int)cVar3;
        }
    }
LAB_0011296f:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "__group", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "byte_content_range", lVar1, *param_1 - lVar1);
        }
        return iVar5;
    }
    *(int*)(param_1 + 2) = iVar4 + -2;
    return iVar5;
}



int Content_Range(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 3;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "BYTES");
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    iVar5 = (int)cVar3;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar3, "bytes_unit", lVar1, *param_1 - lVar1);
    }
    if (cVar3 == '\0') {
        iVar4 = *(int*)(param_1 + 2) + 1;
    }
    else {
        cVar3 = __sp(param_1);
        iVar5 = (int)cVar3;
        iVar4 = *(int*)(param_1 + 2) + 1;
        *(int*)(param_1 + 2) = iVar4;
        if (cVar3 != '\0') {
            lVar2 = *param_1;
            cVar3 = byte_range_resp(param_1);
            iVar5 = (int)cVar3;
            if (cVar3 == '\0') {
                *param_1 = lVar2;
                cVar3 = unsatisfied_range(param_1);
                iVar5 = (int)cVar3;
                if (cVar3 == '\0') {
                    *param_1 = lVar2;
                }
            }
            iVar4 = *(int*)(param_1 + 2);
        }
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    cVar3 = (char)iVar5;
    if ((code*)param_1[1] == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar4 + -2;
    }
    else {
        (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "byte_content_range", lVar1, *param_1 - lVar1);
        }
    }
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        cVar3 = other_content_range(param_1);
        iVar5 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "Content_Range", lVar1, *param_1 - lVar1);
    }
    return iVar5;
}



bool Age(long* param_1)

{
    int iVar1;
    long lVar2;
    bool bVar3;
    char cVar4;
    int iVar5;
    long lVar6;

    iVar5 = 0;
    lVar2 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar6 = lVar2;
    while (true) {
        cVar4 = __digit(param_1);
        if (cVar4 == '\0') break;
        lVar6 = *param_1;
        iVar5 = iVar5 + 1;
    }
    iVar1 = *(int*)(param_1 + 2);
    bVar3 = 0 < iVar5;
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar1 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, bVar3, "delta_seconds", lVar2, lVar6 - lVar2);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, bVar3, &__func___5700, lVar2, *param_1 - lVar2);
        }
        return bVar3;
    }
    *(int*)(param_1 + 2) = iVar1 + -2;
    return bVar3;
}



int Expires(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = HTTP_date();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "Expires", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined8 cache_directive(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    undefined8 uVar6;
    code* pcVar7;
    undefined8 uVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = token();
    if (cVar4 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
        uVar8 = 0;
        goto LAB_00112cf7;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar2 = *param_1;
    cVar4 = __icar(param_1, 0x3d);
    iVar5 = *(int*)(param_1 + 2) + 1;
    *(int*)(param_1 + 2) = iVar5;
    if (cVar4 == '\0') {
    LAB_00112d53:
        pcVar7 = (code*)param_1[1];
        iVar5 = iVar5 + -1;
        *(int*)(param_1 + 2) = iVar5;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar2, 0);
            iVar5 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar2;
        uVar6 = 0;
    }
    else {
        lVar3 = *param_1;
        cVar4 = token(param_1);
        if (cVar4 == '\0') {
            *param_1 = lVar3;
            cVar4 = quoted_string(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                iVar5 = *(int*)(param_1 + 2);
                goto LAB_00112d53;
            }
        }
        iVar5 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar5 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar5 + -3;
            return 1;
        }
        (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2, 0);
        iVar5 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar7 == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar5 + -2;
        return 1;
    }
    uVar8 = 1;
    (*pcVar7)(param_1, uVar6, "__option", lVar1, 0);
    iVar5 = *(int*)(param_1 + 2);
    pcVar7 = (code*)param_1[1];
LAB_00112cf7:
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar8, "cache_directive", lVar1, *param_1 - lVar1);
    }
    return uVar8;
}



undefined8 Cache_Control(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;
    undefined8 uVar6;
    code* pcVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar5 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar5 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar5, 0);
    }
    *param_1 = lVar5;
    cVar3 = cache_directive(param_1);
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 == '\0') {
        pcVar7 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        while (true) {
            lVar5 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_00112f46:
                *param_1 = lVar2;
                uVar6 = 0;
            }
            else {
                cVar3 = cache_directive(param_1);
                if (cVar3 == '\0') goto LAB_00112f46;
                uVar6 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar6, "__option", lVar5, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar5);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar7 = (code*)param_1[1];
        *param_1 = lVar5;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar5;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar6, "Cache_Control", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



bool delta_seconds(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    iVar3 = 0;
    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = __digit(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
        iVar3 = iVar3 + 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0 < iVar3, "delta_seconds", lVar1, lVar4 - lVar1);
    }
    return 0 < iVar3;
}



undefined8 extension_pragma(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    char cVar4;
    int iVar5;
    undefined8 uVar6;
    code* pcVar7;
    undefined8 uVar8;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar4 = token();
    if (cVar4 == '\0') {
        iVar5 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
        uVar8 = 0;
        goto LAB_00113117;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar2 = *param_1;
    cVar4 = __icar(param_1, 0x3d);
    iVar5 = *(int*)(param_1 + 2) + 1;
    *(int*)(param_1 + 2) = iVar5;
    if (cVar4 == '\0') {
    LAB_00113173:
        pcVar7 = (code*)param_1[1];
        iVar5 = iVar5 + -1;
        *(int*)(param_1 + 2) = iVar5;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar2, 0);
            iVar5 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar2;
        uVar6 = 0;
    }
    else {
        lVar3 = *param_1;
        cVar4 = token(param_1);
        if (cVar4 == '\0') {
            *param_1 = lVar3;
            cVar4 = quoted_string(param_1);
            if (cVar4 == '\0') {
                *param_1 = lVar3;
                iVar5 = *(int*)(param_1 + 2);
                goto LAB_00113173;
            }
        }
        iVar5 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar5 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar5 + -3;
            return 1;
        }
        (*(code*)param_1[1])(param_1, (int)cVar4, "__group", lVar2, 0);
        iVar5 = *(int*)(param_1 + 2);
        pcVar7 = (code*)param_1[1];
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar7 == (code*)0x0) {
        *(int*)(param_1 + 2) = iVar5 + -2;
        return 1;
    }
    uVar8 = 1;
    (*pcVar7)(param_1, uVar6, "__option", lVar1, 0);
    iVar5 = *(int*)(param_1 + 2);
    pcVar7 = (code*)param_1[1];
LAB_00113117:
    *(int*)(param_1 + 2) = iVar5 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar8, "extension_pragma", lVar1, *param_1 - lVar1);
    }
    return uVar8;
}



int pragma_directive(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "NO-CACHE");
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = extension_pragma(param_1);
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "pragma_directive", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined8 Pragma(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    long lVar6;
    undefined8 uVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar6 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if ((cVar3 == '\0') || (cVar3 = OWS(param_1), cVar3 == '\0')) break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar6, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar6 = *param_1;
    }
    *param_1 = lVar6;
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar6, 0);
        iVar4 = *(int*)(param_1 + 2);
    }
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar4 + 1;
    cVar3 = __istring(param_1, "NO-CACHE");
    if (cVar3 == '\0') {
        *param_1 = lVar6;
        cVar3 = extension_pragma(param_1);
        pcVar5 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar5 != (code*)0x0) goto LAB_00113397;
    LAB_001133b6:
        if (cVar3 == '\0') {
            pcVar5 = (code*)param_1[1];
            uVar7 = 0;
            goto LAB_001134b9;
        }
    }
    else {
        pcVar5 = (code*)param_1[1];
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar5 != (code*)0x0) {
        LAB_00113397:
            (*pcVar5)(param_1, (int)cVar3, "pragma_directive", lVar6, *param_1 - lVar6);
            iVar4 = *(int*)(param_1 + 2);
            goto LAB_001133b6;
        }
    }
    while (true) {
        lVar6 = *param_1;
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = OWS(param_1);
        if ((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x2c), cVar3 == '\0')) break;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = OWS(param_1);
        if ((cVar3 == '\0') || (cVar3 = pragma_directive(param_1), cVar3 == '\0')) {
            *param_1 = lVar2;
            uVar7 = 0;
        }
        else {
            uVar7 = 1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar4 = iVar4 + -2;
            *(int*)(param_1 + 2) = iVar4;
        }
        else {
            (*(code*)param_1[1])(param_1, uVar7, "__option", lVar6, 0);
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar6);
                iVar4 = *(int*)(param_1 + 2);
            }
        }
    }
    pcVar5 = (code*)param_1[1];
    *param_1 = lVar6;
    iVar4 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar4;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, 0, "__group", lVar6, 0);
        iVar4 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
    }
    *param_1 = lVar6;
    uVar7 = 1;
LAB_001134b9:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar7, "Pragma", lVar1, *param_1 - lVar1);
    }
    return uVar7;
}



int warn_agent(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined8 uVar5;
    code* pcVar6;
    int iVar7;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar3 = uri_host();
    if (cVar3 == '\0') {
        *param_1 = lVar1;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        *param_1 = lVar1;
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = token(param_1);
        iVar7 = (int)cVar3;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar7, "pseudonym", lVar1, *param_1 - lVar1);
            iVar4 = *(int*)(param_1 + 2);
            pcVar6 = (code*)param_1[1];
        LAB_00113636:
            *(int*)(param_1 + 2) = iVar4 + -1;
            if (pcVar6 == (code*)0x0) {
                return iVar7;
            }
            (*pcVar6)(param_1, iVar7, "warn_agent", lVar1, *param_1 - lVar1);
            return iVar7;
        }
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = __icar(param_1, 0x3a);
        if ((cVar3 == '\0') || (cVar3 = port(param_1), cVar3 == '\0')) {
            *param_1 = lVar2;
            uVar5 = 0;
        }
        else {
            uVar5 = 1;
        }
        iVar4 = *(int*)(param_1 + 2);
        *(int*)(param_1 + 2) = iVar4 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            iVar4 = iVar4 + -2;
        }
        else {
            (*(code*)param_1[1])(param_1, uVar5, "__option", lVar1, 0);
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, 1, "__group", lVar1, 0);
                iVar4 = *(int*)(param_1 + 2);
                pcVar6 = (code*)param_1[1];
                iVar7 = 1;
                goto LAB_00113636;
            }
        }
        iVar7 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    return iVar7;
}



undefined4 warn_code(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    undefined4 uVar5;

    iVar4 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __digit(param_1);
    lVar2 = lVar1;
    do {
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            uVar5 = 0;
        LAB_00113785:
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, uVar5, "warn_code", lVar1, *param_1 - lVar1);
            }
            return uVar5;
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == 3) {
            uVar5 = 1;
            goto LAB_00113785;
        }
        lVar2 = *param_1;
        cVar3 = __digit(param_1);
    } while (true);
}



int warn_date(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __dquote();
    if (cVar2 != '\0') {
        cVar2 = HTTP_date(param_1);
        if (cVar2 != '\0') {
            cVar2 = __dquote(param_1);
            iVar3 = (int)cVar2;
            goto LAB_001137db;
        }
    }
    iVar3 = 0;
LAB_001137db:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "warn_date", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int warn_text(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = quoted_string();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "warn_text", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



undefined4 warning_value(long* param_1)

{
    int iVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    undefined4 uVar7;
    undefined8 uVar8;
    code* pcVar9;

    iVar6 = 0;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar2 = *param_1;
    cVar5 = __digit(param_1);
    lVar3 = lVar2;
    while (cVar5 != '\0') {
        iVar6 = iVar6 + 1;
        if (iVar6 == 3) {
            pcVar9 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            uVar8 = 1;
            if (pcVar9 != (code*)0x0) goto LAB_001138ea;
            goto LAB_00113940;
        }
        lVar3 = *param_1;
        cVar5 = __digit(param_1);
    }
    pcVar9 = (code*)param_1[1];
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    uVar8 = 0;
    *param_1 = lVar3;
    if (pcVar9 != (code*)0x0) {
    LAB_001138ea:
        (*pcVar9)(param_1, uVar8, "warn_code", lVar2, *param_1 - lVar2);
        if (iVar6 == 3) {
        LAB_00113940:
            cVar5 = __sp(param_1);
            if (((cVar5 == '\0') || (cVar5 = warn_agent(param_1), cVar5 == '\0')) ||
                (cVar5 = __sp(param_1), cVar5 == '\0')) {
                iVar6 = *(int*)(param_1 + 2);
                pcVar9 = (code*)param_1[1];
                uVar7 = 0;
                goto LAB_00113910;
            }
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar3 = *param_1;
            cVar5 = quoted_string(param_1);
            iVar6 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar6;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar5, "warn_text", lVar3, *param_1 - lVar3);
                iVar6 = *(int*)(param_1 + 2);
            }
            if (cVar5 == '\0') {
                pcVar9 = (code*)param_1[1];
                uVar7 = 0;
                goto LAB_00113910;
            }
            lVar3 = *param_1;
            *(int*)(param_1 + 2) = iVar6 + 1;
            cVar5 = __sp(param_1);
            if (cVar5 == '\0') {
                pcVar9 = (code*)param_1[1];
                iVar6 = *(int*)(param_1 + 2);
            LAB_001139e1:
                *param_1 = lVar3;
                uVar8 = 0;
            }
            else {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar4 = *param_1;
                cVar5 = __dquote(param_1);
                if ((cVar5 != '\0') && (cVar5 = HTTP_date(param_1), cVar5 != '\0')) {
                    cVar5 = __dquote(param_1);
                    iVar1 = *(int*)(param_1 + 2);
                    pcVar9 = (code*)param_1[1];
                    iVar6 = iVar1 + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if (pcVar9 != (code*)0x0) {
                        iVar6 = (int)cVar5;
                        goto LAB_00113a97;
                    }
                    if (cVar5 != '\0') {
                        iVar6 = iVar1 + -2;
                        goto LAB_00113a56;
                    }
                    goto LAB_001139e1;
                }
                pcVar9 = (code*)param_1[1];
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if (pcVar9 == (code*)0x0) {
                    iVar6 = *(int*)(param_1 + 2);
                    goto LAB_001139e1;
                }
                iVar6 = 0;
                cVar5 = '\0';
            LAB_00113a97:
                (*pcVar9)(param_1, iVar6, "warn_date", lVar4, *param_1 - lVar4);
                iVar6 = *(int*)(param_1 + 2);
                pcVar9 = (code*)param_1[1];
                if (cVar5 == '\0') goto LAB_001139e1;
                uVar8 = 1;
            }
            iVar6 = iVar6 + -1;
            *(int*)(param_1 + 2) = iVar6;
            if (pcVar9 == (code*)0x0) {
            LAB_00113a56:
                *(int*)(param_1 + 2) = iVar6 + -1;
                return 1;
            }
            uVar7 = 1;
            (*pcVar9)(param_1, uVar8, "__option", lVar2, 0);
            iVar6 = *(int*)(param_1 + 2);
            pcVar9 = (code*)param_1[1];
            goto LAB_00113910;
        }
        pcVar9 = (code*)param_1[1];
    }
    iVar6 = *(int*)(param_1 + 2);
    uVar7 = 0;
LAB_00113910:
    *(int*)(param_1 + 2) = iVar6 + -1;
    if (pcVar9 != (code*)0x0) {
        (*pcVar9)(param_1, uVar7, "warning_value", lVar2, *param_1 - lVar2);
    }
    return uVar7;
}



undefined8 Warning(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;
    undefined8 uVar6;
    code* pcVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar5 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar5 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar5, 0);
    }
    *param_1 = lVar5;
    cVar3 = warning_value(param_1);
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 == '\0') {
        pcVar7 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        while (true) {
            lVar5 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_00113be6:
                *param_1 = lVar2;
                uVar6 = 0;
            }
            else {
                cVar3 = warning_value(param_1);
                if (cVar3 == '\0') goto LAB_00113be6;
                uVar6 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar6, "__option", lVar5, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar5);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar7 = (code*)param_1[1];
        *param_1 = lVar5;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar5;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar6, "Warning", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int auth_param(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    int iVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = token();
    if (cVar3 != '\0') {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = OWS(param_1);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, &__func___3513, lVar2, *param_1 - lVar2);
        }
        if (cVar3 != '\0') {
            cVar3 = __icar(param_1, 0x3d);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = OWS(param_1);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, &__func___3513, lVar2, *param_1 - lVar2);
                    iVar4 = *(int*)(param_1 + 2);
                }
                iVar4 = iVar4 + 1;
                *(int*)(param_1 + 2) = iVar4;
                if (cVar3 == '\0') {
                    iVar5 = 0;
                }
                else {
                    lVar2 = *param_1;
                    cVar3 = token(param_1);
                    if (cVar3 == '\0') {
                        *param_1 = lVar2;
                        cVar3 = quoted_string(param_1);
                        if (cVar3 == '\0') {
                            *param_1 = lVar2;
                            iVar4 = *(int*)(param_1 + 2);
                            iVar5 = 0;
                            goto LAB_00113d35;
                        }
                    }
                    iVar4 = *(int*)(param_1 + 2);
                    iVar5 = (int)cVar3;
                }
                goto LAB_00113d35;
            }
        }
    }
    iVar5 = 0;
    iVar4 = *(int*)(param_1 + 2) + 1;
LAB_00113d35:
    *(int*)(param_1 + 2) = iVar4 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar5, "__group", lVar1, 0);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "auth_param", lVar1, *param_1 - lVar1);
        }
        return iVar5;
    }
    *(int*)(param_1 + 2) = iVar4 + -2;
    return iVar5;
}



int auth_scheme(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "auth_scheme", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



bool token68(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;
    int iVar5;
    int iVar6;

    iVar6 = 0;
    lVar1 = *param_1;
    iVar3 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    do {
        *(int*)(param_1 + 2) = iVar3 + 1;
        cVar2 = __alpha(param_1);
        iVar5 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar4;
            cVar2 = __digit(param_1, iVar5);
            iVar5 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar4;
                cVar2 = __icar(param_1, 0x2d);
                iVar5 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar4;
                    cVar2 = __icar(param_1, 0x2e);
                    iVar5 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar4;
                        cVar2 = __icar(param_1, 0x5f);
                        iVar5 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar4;
                            cVar2 = __icar(param_1, 0x7e);
                            iVar5 = (int)cVar2;
                            if (cVar2 == '\0') {
                                *param_1 = lVar4;
                                cVar2 = __icar(param_1, 0x2b);
                                iVar5 = (int)cVar2;
                                if (cVar2 == '\0') {
                                    *param_1 = lVar4;
                                    cVar2 = __icar(param_1, 0x2f);
                                    iVar5 = (int)cVar2;
                                    if (cVar2 == '\0') break;
                                }
                            }
                        }
                    }
                }
            }
        }
        iVar3 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar3;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, iVar5, "__group", lVar4, 0);
            iVar3 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
        iVar6 = iVar6 + 1;
    } while (true);
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar4;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
    }
    *param_1 = lVar4;
    cVar2 = 0 < iVar6;
    if (iVar6 != 0) {
        while (cVar2 != '\0') {
            cVar2 = __icar(param_1, 0x3d);
            if (cVar2 == '\0') break;
            lVar4 = *param_1;
        }
        *param_1 = lVar4;
        cVar2 = true;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, cVar2, "token68", lVar1, lVar4 - lVar1);
    }
    return (bool)cVar2;
}



undefined4 challenge(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    undefined4 uVar7;
    int iVar8;
    undefined8 uVar9;
    code* pcVar10;
    long lVar11;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar5 = token();
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar5, "auth_scheme", lVar1, *param_1 - lVar1);
        iVar6 = *(int*)(param_1 + 2);
    }
    if (cVar5 == '\0') {
        pcVar10 = (code*)param_1[1];
        uVar7 = 0;
    LAB_0011410b:
        *(int*)(param_1 + 2) = iVar6 + -1;
        if (pcVar10 != (code*)0x0) {
            (*pcVar10)(param_1, uVar7, "challenge", lVar1, *param_1 - lVar1);
        }
    }
    else {
        lVar2 = *param_1;
        iVar8 = 0;
        *(int*)(param_1 + 2) = iVar6 + 1;
        lVar11 = lVar2;
        while (true) {
            cVar5 = __sp(param_1);
            if (cVar5 == '\0') break;
            lVar11 = *param_1;
            iVar8 = iVar8 + 1;
        }
        iVar6 = *(int*)(param_1 + 2);
        *param_1 = lVar11;
        *(int*)(param_1 + 2) = iVar6 + 1;
        if (iVar8 == 0) {
            pcVar10 = (code*)param_1[1];
            *(int*)(param_1 + 2) = iVar6;
            if (pcVar10 != (code*)0x0) {
                (*pcVar10)(param_1, 0, "__group", lVar2, 0);
                iVar6 = *(int*)(param_1 + 2);
                pcVar10 = (code*)param_1[1];
            }
            *param_1 = lVar2;
        LAB_001141b1:
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar10 != (code*)0x0) {
                uVar7 = 1;
                (*pcVar10)(param_1, iVar8, "__option", lVar1, 0);
                iVar6 = *(int*)(param_1 + 2);
                pcVar10 = (code*)param_1[1];
                goto LAB_0011410b;
            }
        }
        else {
            uVar7 = token68(param_1);
            if ((char)uVar7 == '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
                *param_1 = lVar11;
                cVar5 = __icar(param_1, 0x2c, uVar7);
                if (cVar5 == '\0') {
                    *param_1 = lVar11;
                    cVar5 = auth_param(param_1);
                    if (cVar5 != '\0') goto LAB_00114232;
                    pcVar10 = (code*)param_1[1];
                    *param_1 = lVar11;
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if (pcVar10 != (code*)0x0) {
                        (*pcVar10)(param_1, 0, "__group", lVar11, 0);
                        iVar6 = *(int*)(param_1 + 2);
                        pcVar10 = (code*)param_1[1];
                    }
                    *param_1 = lVar11;
                    uVar9 = 0;
                }
                else {
                LAB_00114232:
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, (int)cVar5, "__group", lVar11, 0);
                        iVar6 = *(int*)(param_1 + 2);
                    }
                    while (true) {
                        lVar3 = *param_1;
                        *(int*)(param_1 + 2) = iVar6 + 1;
                        cVar5 = OWS(param_1);
                        if (cVar5 == '\0') break;
                        cVar5 = __icar(param_1, 0x2c);
                        if (cVar5 == '\0') break;
                        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                        lVar4 = *param_1;
                        cVar5 = OWS(param_1);
                        if (cVar5 == '\0') {
                        LAB_0011436e:
                            *param_1 = lVar4;
                            uVar9 = 0;
                        }
                        else {
                            cVar5 = auth_param(param_1);
                            if (cVar5 == '\0') goto LAB_0011436e;
                            uVar9 = 1;
                        }
                        iVar6 = *(int*)(param_1 + 2);
                        *(int*)(param_1 + 2) = iVar6 + -1;
                        if ((code*)param_1[1] == (code*)0x0) {
                            iVar6 = iVar6 + -2;
                            *(int*)(param_1 + 2) = iVar6;
                        }
                        else {
                            (*(code*)param_1[1])(param_1, uVar9, "__option", lVar3, 0);
                            iVar6 = *(int*)(param_1 + 2) + -1;
                            *(int*)(param_1 + 2) = iVar6;
                            if ((code*)param_1[1] != (code*)0x0) {
                                (*(code*)param_1[1])(param_1, 1, "__group", lVar3);
                                iVar6 = *(int*)(param_1 + 2);
                            }
                        }
                    }
                    pcVar10 = (code*)param_1[1];
                    *param_1 = lVar3;
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if (pcVar10 != (code*)0x0) {
                        (*pcVar10)(param_1, 0, "__group", lVar3, 0);
                        iVar6 = *(int*)(param_1 + 2);
                        pcVar10 = (code*)param_1[1];
                    }
                    *param_1 = lVar3;
                    uVar9 = 1;
                }
                *(int*)(param_1 + 2) = iVar6 + -1;
                if (pcVar10 != (code*)0x0) {
                    (*pcVar10)(param_1, uVar9, "__option", lVar11, 0);
                    pcVar10 = (code*)param_1[1];
                    iVar6 = *(int*)(param_1 + 2);
                    uVar7 = 1;
                    goto LAB_001142d0;
                }
                iVar6 = iVar6 + -2;
            }
            else {
                pcVar10 = (code*)param_1[1];
                iVar6 = *(int*)(param_1 + 2);
            LAB_001142d0:
                iVar6 = iVar6 + -1;
                *(int*)(param_1 + 2) = iVar6;
                if (pcVar10 != (code*)0x0) {
                    iVar8 = 1;
                    (*pcVar10)(param_1, (int)(char)uVar7, "__group", lVar2, 0);
                    iVar6 = *(int*)(param_1 + 2);
                    pcVar10 = (code*)param_1[1];
                    goto LAB_001141b1;
                }
            }
        }
        uVar7 = 1;
        *(int*)(param_1 + 2) = iVar6 + -2;
    }
    return uVar7;
}



undefined8 Proxy_Authenticate(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;
    undefined8 uVar6;
    code* pcVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar5 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar5 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar5, 0);
    }
    *param_1 = lVar5;
    cVar3 = challenge(param_1);
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 == '\0') {
        pcVar7 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        while (true) {
            lVar5 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_00114536:
                *param_1 = lVar2;
                uVar6 = 0;
            }
            else {
                cVar3 = challenge(param_1);
                if (cVar3 == '\0') goto LAB_00114536;
                uVar6 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar6, "__option", lVar5, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar5);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar7 = (code*)param_1[1];
        *param_1 = lVar5;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar5;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar6, "Proxy_Authenticate", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



undefined8 WWW_Authenticate(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;
    undefined8 uVar6;
    code* pcVar7;

    lVar1 = *param_1;
    iVar4 = *(int*)(param_1 + 2) + 1;
    lVar5 = lVar1;
    while (true) {
        *(int*)(param_1 + 2) = iVar4 + 1;
        cVar3 = __icar(param_1, 0x2c);
        if (cVar3 == '\0') break;
        cVar3 = OWS(param_1);
        if (cVar3 == '\0') break;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
        }
        lVar5 = *param_1;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar5;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar5, 0);
    }
    *param_1 = lVar5;
    cVar3 = challenge(param_1);
    iVar4 = *(int*)(param_1 + 2);
    if (cVar3 == '\0') {
        pcVar7 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        while (true) {
            lVar5 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') break;
            cVar3 = __icar(param_1, 0x2c);
            if (cVar3 == '\0') break;
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
            lVar2 = *param_1;
            cVar3 = OWS(param_1);
            if (cVar3 == '\0') {
            LAB_00114746:
                *param_1 = lVar2;
                uVar6 = 0;
            }
            else {
                cVar3 = challenge(param_1);
                if (cVar3 == '\0') goto LAB_00114746;
                uVar6 = 1;
            }
            iVar4 = *(int*)(param_1 + 2);
            *(int*)(param_1 + 2) = iVar4 + -1;
            if ((code*)param_1[1] == (code*)0x0) {
                iVar4 = iVar4 + -2;
                *(int*)(param_1 + 2) = iVar4;
            }
            else {
                (*(code*)param_1[1])(param_1, uVar6, "__option", lVar5, 0);
                iVar4 = *(int*)(param_1 + 2) + -1;
                *(int*)(param_1 + 2) = iVar4;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 1, "__group", lVar5);
                    iVar4 = *(int*)(param_1 + 2);
                }
            }
        }
        pcVar7 = (code*)param_1[1];
        *param_1 = lVar5;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar7 != (code*)0x0) {
            (*pcVar7)(param_1, 0, "__group", lVar5, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar7 = (code*)param_1[1];
        }
        *param_1 = lVar5;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar7 != (code*)0x0) {
        (*pcVar7)(param_1, uVar6, "WWW_Authenticate", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



undefined4 credentials(long* param_1)

{
    long lVar1;
    long lVar2;
    long lVar3;
    long lVar4;
    char cVar5;
    int iVar6;
    undefined4 uVar7;
    int iVar8;
    undefined8 uVar9;
    code* pcVar10;
    long lVar11;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar5 = token();
    iVar6 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar6;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar5, "auth_scheme", lVar1, *param_1 - lVar1);
        iVar6 = *(int*)(param_1 + 2);
    }
    if (cVar5 == '\0') {
        pcVar10 = (code*)param_1[1];
        uVar7 = 0;
    LAB_001148cb:
        *(int*)(param_1 + 2) = iVar6 + -1;
        if (pcVar10 != (code*)0x0) {
            (*pcVar10)(param_1, uVar7, "credentials", lVar1, *param_1 - lVar1);
        }
    }
    else {
        lVar2 = *param_1;
        iVar8 = 0;
        *(int*)(param_1 + 2) = iVar6 + 1;
        lVar11 = lVar2;
        while (true) {
            cVar5 = __sp(param_1);
            if (cVar5 == '\0') break;
            lVar11 = *param_1;
            iVar8 = iVar8 + 1;
        }
        iVar6 = *(int*)(param_1 + 2);
        *param_1 = lVar11;
        *(int*)(param_1 + 2) = iVar6 + 1;
        if (iVar8 == 0) {
            pcVar10 = (code*)param_1[1];
            *(int*)(param_1 + 2) = iVar6;
            if (pcVar10 != (code*)0x0) {
                (*pcVar10)(param_1, 0, "__group", lVar2, 0);
                iVar6 = *(int*)(param_1 + 2);
                pcVar10 = (code*)param_1[1];
            }
            *param_1 = lVar2;
        LAB_00114971:
            *(int*)(param_1 + 2) = iVar6 + -1;
            if (pcVar10 != (code*)0x0) {
                uVar7 = 1;
                (*pcVar10)(param_1, iVar8, "__option", lVar1, 0);
                iVar6 = *(int*)(param_1 + 2);
                pcVar10 = (code*)param_1[1];
                goto LAB_001148cb;
            }
        }
        else {
            uVar7 = token68(param_1);
            if ((char)uVar7 == '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
                *param_1 = lVar11;
                cVar5 = __icar(param_1, 0x2c, uVar7);
                if (cVar5 == '\0') {
                    *param_1 = lVar11;
                    cVar5 = auth_param(param_1);
                    if (cVar5 != '\0') goto LAB_001149f2;
                    pcVar10 = (code*)param_1[1];
                    *param_1 = lVar11;
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if (pcVar10 != (code*)0x0) {
                        (*pcVar10)(param_1, 0, "__group", lVar11, 0);
                        iVar6 = *(int*)(param_1 + 2);
                        pcVar10 = (code*)param_1[1];
                    }
                    *param_1 = lVar11;
                    uVar9 = 0;
                }
                else {
                LAB_001149f2:
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, (int)cVar5, "__group", lVar11, 0);
                        iVar6 = *(int*)(param_1 + 2);
                    }
                    while (true) {
                        lVar3 = *param_1;
                        *(int*)(param_1 + 2) = iVar6 + 1;
                        cVar5 = OWS(param_1);
                        if (cVar5 == '\0') break;
                        cVar5 = __icar(param_1, 0x2c);
                        if (cVar5 == '\0') break;
                        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                        lVar4 = *param_1;
                        cVar5 = OWS(param_1);
                        if (cVar5 == '\0') {
                        LAB_00114b2e:
                            *param_1 = lVar4;
                            uVar9 = 0;
                        }
                        else {
                            cVar5 = auth_param(param_1);
                            if (cVar5 == '\0') goto LAB_00114b2e;
                            uVar9 = 1;
                        }
                        iVar6 = *(int*)(param_1 + 2);
                        *(int*)(param_1 + 2) = iVar6 + -1;
                        if ((code*)param_1[1] == (code*)0x0) {
                            iVar6 = iVar6 + -2;
                            *(int*)(param_1 + 2) = iVar6;
                        }
                        else {
                            (*(code*)param_1[1])(param_1, uVar9, "__option", lVar3, 0);
                            iVar6 = *(int*)(param_1 + 2) + -1;
                            *(int*)(param_1 + 2) = iVar6;
                            if ((code*)param_1[1] != (code*)0x0) {
                                (*(code*)param_1[1])(param_1, 1, "__group", lVar3);
                                iVar6 = *(int*)(param_1 + 2);
                            }
                        }
                    }
                    pcVar10 = (code*)param_1[1];
                    *param_1 = lVar3;
                    iVar6 = *(int*)(param_1 + 2) + -1;
                    *(int*)(param_1 + 2) = iVar6;
                    if (pcVar10 != (code*)0x0) {
                        (*pcVar10)(param_1, 0, "__group", lVar3, 0);
                        iVar6 = *(int*)(param_1 + 2);
                        pcVar10 = (code*)param_1[1];
                    }
                    *param_1 = lVar3;
                    uVar9 = 1;
                }
                *(int*)(param_1 + 2) = iVar6 + -1;
                if (pcVar10 != (code*)0x0) {
                    (*pcVar10)(param_1, uVar9, "__option", lVar11, 0);
                    pcVar10 = (code*)param_1[1];
                    iVar6 = *(int*)(param_1 + 2);
                    uVar7 = 1;
                    goto LAB_00114a90;
                }
                iVar6 = iVar6 + -2;
            }
            else {
                pcVar10 = (code*)param_1[1];
                iVar6 = *(int*)(param_1 + 2);
            LAB_00114a90:
                iVar6 = iVar6 + -1;
                *(int*)(param_1 + 2) = iVar6;
                if (pcVar10 != (code*)0x0) {
                    iVar8 = 1;
                    (*pcVar10)(param_1, (int)(char)uVar7, "__group", lVar2, 0);
                    iVar6 = *(int*)(param_1 + 2);
                    pcVar10 = (code*)param_1[1];
                    goto LAB_00114971;
                }
            }
        }
        uVar7 = 1;
        *(int*)(param_1 + 2) = iVar6 + -2;
    }
    return uVar7;
}



int Proxy_Authorization(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = credentials();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "Proxy_Authorization", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int Authorization(long* param_1)

{
    long lVar1;
    char cVar2;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = credentials();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "Authorization", lVar1, *param_1 - lVar1);
    }
    return (int)cVar2;
}



int Connection_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "CONNECTION");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Connection(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00114cd2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00114cd2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Connection_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Content_Length_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "CONTENT-LENGTH");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                lVar2 = *param_1;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                iVar4 = 0;
                lVar5 = lVar2;
                while (true) {
                    cVar3 = __digit(param_1);
                    if (cVar3 == '\0') break;
                    lVar5 = *param_1;
                    iVar4 = iVar4 + 1;
                }
                *param_1 = lVar5;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0 < iVar4, "Content_Length", lVar2, lVar5 - lVar2);
                }
                if (0 < iVar4) {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_00114d66;
                }
            }
        }
    }
    iVar4 = 0;
LAB_00114d66:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Content_Length_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Content_Type_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "CONTENT-TYPE");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = media_type(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "Content_Type", lVar2, *param_1 - lVar2);
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_00114e58;
                }
            }
        }
    }
    iVar4 = 0;
LAB_00114e58:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Content_Type_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Trailer_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "TRAILER");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Trailer(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00114f32;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00114f32:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Trailer_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Transfer_Encoding_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "TRANSFER-ENCODING");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Transfer_Encoding(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00114fc2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00114fc2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Transfer_Encoding_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Upgrade_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "UPGRADE");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Upgrade(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115052;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115052:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Upgrade_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Via_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, &DAT_00117867);
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Via(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_001150e2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_001150e2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Via_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Age_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "AGE");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Age(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115172;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115172:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Age_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Expires_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "EXPIRES");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = HTTP_date(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "Expires", lVar2, *param_1 - lVar2);
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_00115208;
                }
            }
        }
    }
    iVar4 = 0;
LAB_00115208:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Expires_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Date_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, &DAT_00117873);
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = HTTP_date(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, &__func___4750, lVar2, *param_1 - lVar2);
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_001152e8;
                }
            }
        }
    }
    iVar4 = 0;
LAB_001152e8:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Date_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Location_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "LOCATION");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
                lVar2 = *param_1;
                cVar3 = URI(param_1);
                if (cVar3 == '\0') {
                    *param_1 = lVar2;
                    cVar3 = relative_ref(param_1);
                }
                iVar4 = *(int*)(param_1 + 2);
                *(int*)(param_1 + 2) = iVar4 + -1;
                if ((code*)param_1[1] == (code*)0x0) {
                    *(int*)(param_1 + 2) = iVar4 + -2;
                }
                else {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "URI_reference", lVar2, *param_1 - lVar2);
                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                    if ((code*)param_1[1] != (code*)0x0) {
                        (*(code*)param_1[1])(param_1, (int)cVar3, "Location", lVar2, *param_1 - lVar2);
                    }
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_001153c6;
                }
            }
        }
    }
    iVar4 = 0;
LAB_001153c6:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Location_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Retry_After_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "RETRY-AFTER");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Retry_After(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_001154f2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_001154f2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Retry_After_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Vary_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, &DAT_0011788d);
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Vary(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115582;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115582:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Vary_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Warning_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "WARNING");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Warning(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115612;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115612:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Warning_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Cache_Control_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "CACHE-CONTROL");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Cache_Control(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_001156a2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_001156a2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Cache_Control_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Expect_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "EXPECT");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = __istring(param_1, "100-CONTINUE");
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "Expect", lVar2, *param_1 - lVar2);
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_00115738;
                }
            }
        }
    }
    iVar4 = 0;
LAB_00115738:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Expect_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Host_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, &DAT_001178af);
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Host(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115812;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115812:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Host_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Max_Forwards_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    long lVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "MAX-FORWARDS");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                lVar2 = *param_1;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                iVar4 = 0;
                lVar5 = lVar2;
                while (true) {
                    cVar3 = __digit(param_1);
                    if (cVar3 == '\0') break;
                    lVar5 = *param_1;
                    iVar4 = iVar4 + 1;
                }
                *param_1 = lVar5;
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, 0 < iVar4, "Max_Forwards", lVar2, lVar5 - lVar2);
                }
                if (0 < iVar4) {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_001158a6;
                }
            }
        }
    }
    iVar4 = 0;
LAB_001158a6:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Max_Forwards_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Pragma_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "PRAGMA");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Pragma(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115992;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115992:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Pragma_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Range_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "RANGE");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Range(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115a22;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115a22:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Range_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int TE_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, &DAT_00117875);
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = TE(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115ab2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115ab2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "TE_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int If_Match_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "IF-MATCH");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = If_Match(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115b42;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115b42:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "If_Match_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int If_None_Match_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "IF-NONE-MATCH");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = If_None_Match(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115bd2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115bd2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "If_None_Match_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int If_Modified_Since_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "IF-MODIFIED-SINCE");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = HTTP_date(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "If_Modified_Since", lVar2, *param_1 - lVar2);
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_00115c68;
                }
            }
        }
    }
    iVar4 = 0;
LAB_00115c68:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "If_Modified_Since_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int If_Unmodified_Since_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "IF-UNMODIFIED-SINCE");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = HTTP_date(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "If_Unmodified_Since", lVar2, *param_1 - lVar2);
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_00115d48;
                }
            }
        }
    }
    iVar4 = 0;
LAB_00115d48:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "If_Unmodified_Since_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int If_Range_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "IF-RANGE");
    if (((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x3a), cVar3 == '\0')) ||
        (cVar3 = OWS(param_1), cVar3 == '\0')) {
    LAB_00115e26:
        iVar4 = 0;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = entity_tag(param_1);
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = HTTP_date(param_1);
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 != (code*)0x0) goto LAB_00115ea1;
        LAB_00115ebd:
            if (cVar3 == '\0') goto LAB_00115e26;
        }
        else {
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 != (code*)0x0) {
            LAB_00115ea1:
                (*pcVar5)(param_1, (int)cVar3, "If_Range", lVar2, *param_1 - lVar2);
                goto LAB_00115ebd;
            }
        }
        cVar3 = OWS(param_1);
        iVar4 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "If_Range_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Accept_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "ACCEPT");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Accept(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115f22;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115f22:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Accept_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Accept_Charset_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "ACCEPT-CHARSET");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Accept_Charset(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00115fb2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00115fb2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Accept_Charset_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Accept_Encoding_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "ACCEPT-ENCODING");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Accept_Encoding(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00116042;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00116042:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Accept_Encoding_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Accept_Language_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "ACCEPT-LANGUAGE");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = Accept_Language(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_001160d2;
                }
            }
        }
    }
    iVar3 = 0;
LAB_001160d2:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Accept_Language_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int Authorization_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "AUTHORIZATION");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = credentials(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "Authorization", lVar2, *param_1 - lVar2);
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_00116168;
                }
            }
        }
    }
    iVar4 = 0;
LAB_00116168:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Authorization_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Proxy_Authorization_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "PROXY-AUTHORIZATION");
    if (cVar3 != '\0') {
        cVar3 = __icar(param_1, 0x3a);
        if (cVar3 != '\0') {
            cVar3 = OWS(param_1);
            if (cVar3 != '\0') {
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                lVar2 = *param_1;
                cVar3 = credentials(param_1);
                *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                if ((code*)param_1[1] != (code*)0x0) {
                    (*(code*)param_1[1])(param_1, (int)cVar3, "Proxy_Authorization", lVar2, *param_1 - lVar2);
                }
                if (cVar3 != '\0') {
                    cVar3 = OWS(param_1);
                    iVar4 = (int)cVar3;
                    goto LAB_00116248;
                }
            }
        }
    }
    iVar4 = 0;
LAB_00116248:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Proxy_Authorization_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int Referer_header(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = __istring(param_1, "REFERER");
    if (((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x3a), cVar3 == '\0')) ||
        (cVar3 = OWS(param_1), cVar3 == '\0')) {
    LAB_00116326:
        iVar4 = 0;
    }
    else {
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
        lVar2 = *param_1;
        cVar3 = absolute_URI(param_1);
        if (cVar3 == '\0') {
            *param_1 = lVar2;
            cVar3 = partial_URI(param_1);
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 != (code*)0x0) goto LAB_001163a1;
        LAB_001163bd:
            if (cVar3 == '\0') goto LAB_00116326;
        }
        else {
            pcVar5 = (code*)param_1[1];
            *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
            if (pcVar5 != (code*)0x0) {
            LAB_001163a1:
                (*pcVar5)(param_1, (int)cVar3, "Referer", lVar2, *param_1 - lVar2);
                goto LAB_001163bd;
            }
        }
        cVar3 = OWS(param_1);
        iVar4 = (int)cVar3;
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar4, "Referer_header", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



int User_Agent_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "USER-AGENT");
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3a);
        if (cVar2 != '\0') {
            cVar2 = OWS(param_1);
            if (cVar2 != '\0') {
                cVar2 = User_Agent(param_1);
                if (cVar2 != '\0') {
                    cVar2 = OWS(param_1);
                    iVar3 = (int)cVar2;
                    goto LAB_00116422;
                }
            }
        }
    }
    iVar3 = 0;
LAB_00116422:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "User_Agent_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



bool cookie_name(long* param_1)

{
    int iVar1;
    long lVar2;
    bool bVar3;
    char cVar4;
    int iVar5;
    long lVar6;

    iVar5 = 0;
    lVar2 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar6 = lVar2;
    while (true) {
        cVar4 = tchar(param_1);
        if (cVar4 == '\0') break;
        lVar6 = *param_1;
        iVar5 = iVar5 + 1;
    }
    iVar1 = *(int*)(param_1 + 2);
    bVar3 = 0 < iVar5;
    *param_1 = lVar6;
    *(int*)(param_1 + 2) = iVar1 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, bVar3, "token", lVar2, lVar6 - lVar2);
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, bVar3, "cookie_name", lVar2, *param_1 - lVar2);
        }
        return bVar3;
    }
    *(int*)(param_1 + 2) = iVar1 + -2;
    return bVar3;
}



int cookie_octet(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __num(param_1, &DAT_0011796b);
    iVar3 = (int)cVar2;
    if (cVar2 == '\0') {
        *param_1 = lVar1;
        cVar2 = __range(param_1, 0x23, 0x2b);
        iVar3 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = __range(param_1, 0x2d, 0x3a);
            iVar3 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = __range(param_1, 0x3c, 0x5b);
                iVar3 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = __range(param_1, 0x5d, 0x7e);
                    iVar3 = (int)cVar2;
                }
            }
        }
    }
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "cookie_octet", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int cookie_value(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    long lVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = __dquote();
    if (cVar2 != '\0') {
        iVar3 = *(int*)(param_1 + 2);
    LAB_001166d0:
        *(int*)(param_1 + 2) = iVar3 + 1;
        lVar5 = *param_1;
        cVar2 = __num(param_1, &DAT_0011796b);
        if (cVar2 != '\0') goto LAB_001166f1;
        *param_1 = lVar5;
        cVar2 = __range(param_1, 0x23, 0x2b);
        if (cVar2 != '\0') goto LAB_001166f1;
        *param_1 = lVar5;
        cVar2 = __range(param_1, 0x2d, 0x3a);
        if (cVar2 != '\0') goto LAB_001166f1;
        *param_1 = lVar5;
        cVar2 = __range(param_1, 0x3c, 0x5b);
        if (cVar2 != '\0') goto LAB_001166f1;
        *param_1 = lVar5;
        cVar2 = __range(param_1, 0x5d, 0x7e);
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if (pcVar6 != (code*)0x0) goto LAB_00116703;
        goto LAB_0011671f;
    }
LAB_00116641:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    *param_1 = lVar1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar1, 0);
    }
    *param_1 = lVar1;
    lVar5 = lVar1;
    while (cVar2 = cookie_octet(param_1), cVar2 != '\0') {
        lVar5 = *param_1;
    }
    iVar3 = *(int*)(param_1 + 2);
    pcVar6 = (code*)param_1[1];
    *param_1 = lVar5;
    iVar4 = 1;
LAB_00116690:
    *(int*)(param_1 + 2) = iVar3 + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, iVar4, "cookie_value", lVar1, *param_1 - lVar1);
    }
    return iVar4;
LAB_001166f1:
    pcVar6 = (code*)param_1[1];
    iVar3 = *(int*)(param_1 + 2) + -1;
    *(int*)(param_1 + 2) = iVar3;
    if (pcVar6 == (code*)0x0) goto LAB_001166d0;
LAB_00116703:
    (*pcVar6)(param_1, (int)cVar2, "cookie_octet", lVar5, *param_1 - lVar5);
LAB_0011671f:
    if (cVar2 != '\0') {
        iVar3 = *(int*)(param_1 + 2);
        goto LAB_001166d0;
    }
    *param_1 = lVar5;
    cVar2 = __dquote(param_1);
    if (cVar2 != '\0') {
        iVar3 = *(int*)(param_1 + 2);
        iVar4 = (int)cVar2;
        *(int*)(param_1 + 2) = iVar3 + -1;
        if ((code*)param_1[1] == (code*)0x0) {
            *(int*)(param_1 + 2) = iVar3 + -2;
            return iVar4;
        }
        (*(code*)param_1[1])(param_1, iVar4, "__group", lVar1, 0);
        iVar3 = *(int*)(param_1 + 2);
        pcVar6 = (code*)param_1[1];
        goto LAB_00116690;
    }
    goto LAB_00116641;
}



int cookie_pair(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = token();
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, (int)cVar2, "cookie_name", lVar1, *param_1 - lVar1);
    }
    if (cVar2 != '\0') {
        cVar2 = __icar(param_1, 0x3d);
        if (cVar2 != '\0') {
            cVar2 = cookie_value(param_1);
            iVar3 = (int)cVar2;
            goto LAB_00116876;
        }
    }
    iVar3 = 0;
LAB_00116876:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "cookie_pair", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



undefined8 cookie_string(long* param_1)

{
    long lVar1;
    long lVar2;
    char cVar3;
    int iVar4;
    code* pcVar5;
    undefined8 uVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar3 = cookie_pair();
    if (cVar3 == '\0') {
        iVar4 = *(int*)(param_1 + 2);
        pcVar5 = (code*)param_1[1];
        uVar6 = 0;
    }
    else {
        iVar4 = *(int*)(param_1 + 2);
        while (true) {
            lVar2 = *param_1;
            *(int*)(param_1 + 2) = iVar4 + 1;
            cVar3 = __icar(param_1, 0x3b);
            if (cVar3 == '\0') break;
            cVar3 = __sp(param_1);
            if (cVar3 == '\0') break;
            cVar3 = cookie_pair(param_1);
            if (cVar3 == '\0') break;
            iVar4 = *(int*)(param_1 + 2) + -1;
            *(int*)(param_1 + 2) = iVar4;
            if ((code*)param_1[1] != (code*)0x0) {
                (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar2, 0);
                iVar4 = *(int*)(param_1 + 2);
            }
        }
        pcVar5 = (code*)param_1[1];
        *param_1 = lVar2;
        iVar4 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar4;
        if (pcVar5 != (code*)0x0) {
            (*pcVar5)(param_1, 0, "__group", lVar2, 0);
            iVar4 = *(int*)(param_1 + 2);
            pcVar5 = (code*)param_1[1];
        }
        *param_1 = lVar2;
        uVar6 = 1;
    }
    *(int*)(param_1 + 2) = iVar4 + -1;
    if (pcVar5 != (code*)0x0) {
        (*pcVar5)(param_1, uVar6, "cookie_string", lVar1, *param_1 - lVar1);
    }
    return uVar6;
}



int Cookie_header(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "COOKIE:");
    if (cVar2 != '\0') {
        cVar2 = OWS(param_1);
        if (cVar2 != '\0') {
            cVar2 = cookie_string(param_1);
            if (cVar2 != '\0') {
                cVar2 = OWS(param_1);
                iVar3 = (int)cVar2;
                goto LAB_00116a22;
            }
        }
    }
    iVar3 = 0;
LAB_00116a22:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "Cookie_header", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



int header_field(long* param_1)

{
    long lVar1;
    char cVar2;
    char cVar3;
    int iVar4;
    int iVar5;
    code* pcVar6;

    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 2;
    lVar1 = *param_1;
    cVar2 = __istring(param_1, "CONNECTION");
    if ((((cVar2 == '\0') || (cVar2 = __icar(param_1, 0x3a), cVar2 == '\0')) ||
        (cVar2 = OWS(param_1), cVar2 == '\0')) || (cVar2 = Connection(param_1), cVar2 == '\0')) {
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar5 = 0;
        iVar4 = 0;
        if (pcVar6 != (code*)0x0) {
        LAB_00116abb:
            (*pcVar6)(param_1, iVar5, "Connection_header", lVar1, *param_1 - lVar1);
            goto LAB_00116ad3;
        }
    LAB_00116b70:
        *param_1 = lVar1;
        cVar2 = Content_Length_header(param_1);
        iVar4 = (int)cVar2;
        if (cVar2 == '\0') {
            *param_1 = lVar1;
            cVar2 = Content_Type_header(param_1);
            iVar4 = (int)cVar2;
            if (cVar2 == '\0') {
                *param_1 = lVar1;
                cVar2 = Cookie_header(param_1);
                iVar4 = (int)cVar2;
                if (cVar2 == '\0') {
                    *param_1 = lVar1;
                    cVar2 = Transfer_Encoding_header(param_1);
                    iVar4 = (int)cVar2;
                    if (cVar2 == '\0') {
                        *param_1 = lVar1;
                        cVar2 = Expect_header(param_1);
                        iVar4 = (int)cVar2;
                        if (cVar2 == '\0') {
                            *param_1 = lVar1;
                            cVar2 = Host_header(param_1);
                            iVar4 = (int)cVar2;
                            if (cVar2 == '\0') {
                                *param_1 = lVar1;
                                cVar2 = Accept_header(param_1);
                                iVar4 = (int)cVar2;
                                if (cVar2 == '\0') {
                                    *param_1 = lVar1;
                                    cVar2 = Accept_Charset_header(param_1);
                                    iVar4 = (int)cVar2;
                                    if (cVar2 == '\0') {
                                        *param_1 = lVar1;
                                        cVar2 = Accept_Encoding_header(param_1);
                                        iVar4 = (int)cVar2;
                                        if (cVar2 == '\0') {
                                            *param_1 = lVar1;
                                            cVar2 = Accept_Language_header(param_1);
                                            iVar4 = (int)cVar2;
                                            if (cVar2 == '\0') {
                                                *param_1 = lVar1;
                                                cVar2 = Referer_header(param_1);
                                                iVar4 = (int)cVar2;
                                                if (cVar2 == '\0') {
                                                    *param_1 = lVar1;
                                                    cVar2 = User_Agent_header(param_1);
                                                    if (cVar2 != '\0') {
                                                        pcVar6 = (code*)param_1[1];
                                                        iVar4 = (int)cVar2;
                                                        goto LAB_00116ae0;
                                                    }
                                                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
                                                    *param_1 = lVar1;
                                                    cVar3 = field_name(param_1);
                                                    if (((cVar3 == '\0') || (cVar3 = __icar(param_1, 0x3a), cVar3 == '\0')) ||
                                                        ((cVar3 = OWS(param_1), cVar3 == '\0' ||
                                                            ((cVar3 = field_value(param_1), cVar3 == '\0' ||
                                                                (cVar3 = OWS(param_1), cVar3 == '\0')))))) {
                                                        *param_1 = lVar1;
                                                        cVar3 = cVar2;
                                                    }
                                                    iVar4 = (int)cVar3;
                                                    pcVar6 = (code*)param_1[1];
                                                    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
                                                    if (pcVar6 == (code*)0x0) goto LAB_00116ae0;
                                                    (*pcVar6)(param_1, iVar4, "__group", lVar1, 0);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        cVar2 = OWS(param_1);
        pcVar6 = (code*)param_1[1];
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        iVar4 = (int)cVar2;
        if (pcVar6 != (code*)0x0) {
            iVar5 = (int)cVar2;
            goto LAB_00116abb;
        }
    LAB_00116ad3:
        if ((char)iVar4 == '\0') goto LAB_00116b70;
    }
    pcVar6 = (code*)param_1[1];
LAB_00116ae0:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if (pcVar6 != (code*)0x0) {
        (*pcVar6)(param_1, iVar4, "header_field", lVar1, *param_1 - lVar1);
    }
    return iVar4;
}



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



undefined8 trailer_part(long* param_1)

{
    int iVar1;
    long lVar2;
    char cVar3;
    long lVar4;

    lVar2 = *param_1;
    iVar1 = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar2;
    while (true) {
        *(int*)(param_1 + 2) = iVar1 + 1;
        cVar3 = header_field(param_1);
        if (cVar3 == '\0') break;
        cVar3 = __crlf(param_1);
        if (cVar3 == '\0') break;
        iVar1 = *(int*)(param_1 + 2) + -1;
        *(int*)(param_1 + 2) = iVar1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, (int)cVar3, "__group", lVar4, 0);
            iVar1 = *(int*)(param_1 + 2);
        }
        lVar4 = *param_1;
    }
    iVar1 = *(int*)(param_1 + 2);
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = iVar1 + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, 0, "__group", lVar4, 0);
        *param_1 = lVar4;
        *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
        if ((code*)param_1[1] != (code*)0x0) {
            (*(code*)param_1[1])(param_1, 1, "trailer_part", lVar2, lVar4 - lVar2);
        }
        return 1;
    }
    *param_1 = lVar4;
    *(int*)(param_1 + 2) = iVar1 + -2;
    return 1;
}



int chunked_body(long* param_1)

{
    long lVar1;
    char cVar2;
    int iVar3;
    long lVar4;

    lVar1 = *param_1;
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + 1;
    lVar4 = lVar1;
    while (true) {
        cVar2 = chunk(param_1);
        if (cVar2 == '\0') break;
        lVar4 = *param_1;
    }
    *param_1 = lVar4;
    cVar2 = last_chunk(param_1);
    if (cVar2 != '\0') {
        cVar2 = trailer_part(param_1);
        if (cVar2 != '\0') {
            cVar2 = __crlf(param_1);
            iVar3 = (int)cVar2;
            goto LAB_0011709a;
        }
    }
    iVar3 = 0;
LAB_0011709a:
    *(int*)(param_1 + 2) = *(int*)(param_1 + 2) + -1;
    if ((code*)param_1[1] != (code*)0x0) {
        (*(code*)param_1[1])(param_1, iVar3, "chunked_body", lVar1, *param_1 - lVar1);
    }
    return iVar3;
}



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



void FUN_00117253(long param_1)

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



undefined8 call(long param_1, char param_2, undefined8 param_3, undefined8 param_4, undefined4 param_5)

{
    undefined4 uVar1;
    undefined4* puVar2;
    int* __ptr;

    __ptr = *(int**)(param_1 + 0x18);
    if (param_2 != '\0') {
        uVar1 = *(undefined4*)(param_1 + 0x10);
        puVar2 = (undefined4*)malloc(0x28);
        *puVar2 = uVar1;
        *(int**)(puVar2 + 8) = __ptr;
        puVar2[7] = 0;
        *(undefined8*)(puVar2 + 2) = param_3;
        *(undefined8*)(puVar2 + 4) = param_4;
        puVar2[6] = param_5;
        *(undefined4**)(param_1 + 0x18) = puVar2;
        return 1;
    }
    if ((__ptr != (int*)0x0) && (*(int*)(param_1 + 0x10) < *__ptr)) {
        do {
            *(undefined8*)(param_1 + 0x18) = *(undefined8*)(__ptr + 8);
            free(__ptr);
            __ptr = *(int**)(param_1 + 0x18);
            if (__ptr == (int*)0x0) {
                return 0;
            }
        } while (*__ptr != *(int*)(param_1 + 0x10) && *(int*)(param_1 + 0x10) <= *__ptr);
    }
    return 0;
}



void __libc_csu_init(EVP_PKEY_CTX* param_1, undefined8 param_2, undefined8 param_3)

{
    long lVar1;

    _init(param_1);
    lVar1 = 0;
    do {
        (*(code*)(&__frame_dummy_init_array_entry)[lVar1])((ulong)param_1 & 0xffffffff, param_2, param_3)
            ;
        lVar1 = lVar1 + 1;
    } while (lVar1 != 1);
    return;
}



void __libc_csu_fini(void)

{
    return;
}



void _fini(void)

{
    return;
}