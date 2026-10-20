#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

bool isEmpty(List L) {
    return L.First == Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

/* ================= INSERT ================= */

void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        L.First = P;
        L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec == Nil) return;
    if (Prec == L.Last) {
        insertLast(L, P);
    } else {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    }
}

void insertBefore(List &L, address Succ, address P) {
    if (Succ == Nil) return;
    if (Succ == L.First) {
        insertFirst(L, P);
    } else {
        P->prev = Succ->prev;
        P->next = Succ;
        Succ->prev->next = P;
        Succ->prev = P;
    }
}

/* ================= DELETE ================= */

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P == Nil) return;
    if (L.First == L.Last) {         
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = L.First->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P == Nil) return;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = L.Last->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    if (P == Nil) return;
    Prec->next = P->next;
    if (P->next != Nil) {
        P->next->prev = Prec;
    }
    P->next = Nil;
    P->prev = Nil;
}

void deleteBefore(address Succ, address &P) {
    P = Succ->prev;
    if (P == Nil) return;
    Succ->prev = P->prev;
    if (P->prev != Nil) {
        P->prev->next = Succ;
    }
    P->next = Nil;
    P->prev = Nil;
}

/* ============== SEARCH & VIEW ============== */

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}