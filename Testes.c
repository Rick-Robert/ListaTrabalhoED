#include <check.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"

//bateria de testes para lista
START_TEST(TesteCriarLista){
    lista* MyList = NULL;
    CriarLista(&MyList);
    ck_assert_ptr_ne(MyList, NULL);
} END_TEST

START_TEST(TesteDestruirLista){
    lista* MyList = NULL;
    CriarLista(&MyList);
    AddInicioLista(MyList, "Rick", "5324", "A13", "Veneza");
    AddInicioLista(MyList, "Alvaro", "5325", "A14", "Barcelona");
    AddInicioLista(MyList, "Edu", "5327", "A15", "Bahia");
    DestruirLista(&MyList);
    ck_assert_ptr_eq(MyList, NULL);
} END_TEST

START_TEST(TesteAddInicioLista){
    lista* MyList = NULL;
    CriarLista(&MyList);
    AddInicioLista(MyList, "Rick", "5324", "A13", "Veneza");
    char name[101]; strcpy(name, MyList->sentinela->prox->Nome);
    ck_assert_int_eq(strcmp(name, "Rick"), 0);
    AddInicioLista(MyList, "Alvaro", "5325", "A14", "Barcelona");
    strcpy(name, MyList->sentinela->prox->Nome);
    ck_assert_int_eq(strcmp(name, "Alvaro"), 0);
    AddInicioLista(MyList, "Edu", "5327", "A15", "Bahia");
    strcpy(name, MyList->sentinela->prox->Nome);
    ck_assert_int_eq(strcmp(name, "Edu"), 0);
} END_TEST

START_TEST(TesteAddFimLista){
    lista* MyList = NULL;
    CriarLista(&MyList);
    AddFimLista(MyList, "Rick", "5324", "A13", "Veneza");
    char name[101]; strcpy(name, MyList->sentinela->prev->Nome);
    ck_assert_int_eq(strcmp(name, "Rick"), 0);

    AddFimLista(MyList, "Alvaro", "5325", "A14", "Barcelona");
    strcpy(name, MyList->sentinela->prev->Nome);
    ck_assert_int_eq(strcmp(name, "Alvaro"), 0);

    AddFimLista(MyList, "Edu", "5327", "A15", "Bahia");
    strcpy(name, MyList->sentinela->prev->Nome);
    ck_assert_int_eq(strcmp(name, "Edu"), 0);
} END_TEST

START_TEST(TesteRemInicioLista){
    lista* MyList = NULL;
    CriarLista(&MyList);
    AddInicioLista(MyList, "Rick", "5324", "A13", "Veneza");
    AddInicioLista(MyList, "Alvaro", "5325", "A14", "Barcelona");
    AddInicioLista(MyList, "Edu", "5327", "A15", "Bahia");
    RemInicioLista(MyList);
    char name[101]; strcpy(name, MyList->sentinela->prox->Nome);
    ck_assert_int_eq(strcmp(name, "Alvaro"), 0);
    RemInicioLista(MyList);
    strcpy(name, MyList->sentinela->prox->Nome);
    ck_assert_int_eq(strcmp(name, "Rick"), 0);
} END_TEST

START_TEST(TesteRemFimLista){
    lista* MyList = NULL;
    CriarLista(&MyList);
    AddInicioLista(MyList, "Rick", "5324", "A13", "Veneza");
    AddInicioLista(MyList, "Alvaro", "5325", "A14", "Barcelona");
    AddInicioLista(MyList, "Edu", "5327", "A15", "Bahia");
    RemFimLista(MyList);
    char name[101]; strcpy(name, MyList->sentinela->prev->Nome);
    ck_assert_int_eq(strcmp(name, "Alvaro"), 0);
    RemFimLista(MyList);
    strcpy(name, MyList->sentinela->prev->Nome);
    ck_assert_int_eq(strcmp(name, "Edu"), 0);
} END_TEST

START_TEST(TesteVazioLista){
    lista* MyList = NULL;
    CriarLista(&MyList);
    ck_assert_int_eq(VazioLista(MyList), 1);
    AddInicioLista(MyList, "Rick", "5324", "A13", "Veneza");
    ck_assert_int_eq(VazioLista(MyList), 0);
    RemFimLista(MyList);
    ck_assert_int_eq(VazioLista(MyList), 1);
} END_TEST

//bateria de testes para fila
START_TEST(TesteCriarFila){
    fila* p = NULL;
    p = criarFila(100);
    ck_assert_ptr_ne(p,NULL);
    ck_assert_int_eq(p->capacidade == 100, 1);
} END_TEST

START_TEST(TesteInserirFila){
    fila* p = NULL;
    p = criarFila(100);
    inserir(p, 10);
    ck_assert_int_eq(p->dado[p->primeiro], 10);
} END_TEST
START_TEST(TesteRemoverFila){
    fila* p = NULL;
    p = criarFila(100);
    inserir(p, 10);
    remover(p);
    ck_assert_int_eq(tamanho(p), 0);
} END_TEST
START_TEST(TestePrimeiroFila){
    fila* p = NULL;
    p = criarFila(100);
    inserir(p, 10);
    ck_assert_int_eq(primeiro(p), 10);
} END_TEST
START_TEST(TesteUltimoFila){
    fila* p = NULL;
    p = criarFila(100);
    inserir(p, 10);
    ck_assert_int_eq(ultimo(p), 10);
} END_TEST
START_TEST(TesteVaziaFila){
    fila* p = NULL;
    p = criarFila(100);
    inserir(p, 10);
    remover(p);
    ck_assert_int_eq(vazia(p), 1);
} END_TEST
START_TEST(TesteCheiaFila){
    fila* p = NULL;
    p = criarFila(100);
    for(int i = 0; i < 100; i++)
        inserir(p, 50-i);
    ck_assert_int_eq(cheia(p), 1);
} END_TEST
START_TEST(TesteTamanhoFila){
    fila* p = NULL;
    p = criarFila(100);
    for(int i = 0; i < 50; i++)
        inserir(p, 50-i);
    ck_assert_int_eq(tamanho(p), 50);
} END_TEST

Suite *ListQSuite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("List and Queue");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, TesteCriarLista);
    tcase_add_test(tc_core, TesteDestruirLista);
    tcase_add_test(tc_core, TesteAddInicioLista);
    tcase_add_test(tc_core, TesteAddFimLista);
    tcase_add_test(tc_core, TesteRemInicioLista);
    tcase_add_test(tc_core, TesteRemFimLista);
    tcase_add_test(tc_core, TesteVazioLista);

    tcase_add_test(tc_core, TesteCriarFila);
    tcase_add_test(tc_core, TesteInserirFila);
    tcase_add_test(tc_core, TesteRemoverFila);
    tcase_add_test(tc_core, TestePrimeiroFila);
    tcase_add_test(tc_core, TesteUltimoFila);
    tcase_add_test(tc_core, TesteVaziaFila);
    tcase_add_test(tc_core, TesteCheiaFila);
    tcase_add_test(tc_core, TesteTamanhoFila);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void){
    int NumFailed;
    Suite *s;
    SRunner *sr;
    s = ListQSuite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    NumFailed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (NumFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
    return 0;
}