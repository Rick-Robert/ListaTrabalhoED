#include <check.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

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

Suite *ListSuite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("List");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, TesteCriarLista);
    tcase_add_test(tc_core, TesteDestruirLista);
    tcase_add_test(tc_core, TesteAddInicioLista);
    tcase_add_test(tc_core, TesteAddFimLista);
    tcase_add_test(tc_core, TesteRemInicioLista);
    tcase_add_test(tc_core, TesteRemFimLista);
    tcase_add_test(tc_core, TesteVazioLista);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void){
    int NumFailed;
    Suite *s;
    SRunner *sr;
    s = ListSuite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    NumFailed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (NumFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
    return 0;
}