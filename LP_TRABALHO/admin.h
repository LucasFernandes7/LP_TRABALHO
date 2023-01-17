/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   admin.h
 * Author: RP
 *
 * Created on 27 de dezembro de 2022, 17:58
 */

#ifndef ADMIN_H
#define ADMIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "auxi.h"
#include "products.h"   
    unsigned short int menuRead(char message[], unsigned short int min, unsigned short int max);

    void primaryMenu(Customers *customer,Products *products, MaterialsList *materialsList);

    void adminMenu(Customers *customer,Products *products, MaterialsList *materialsList, unsigned short int menu);

    void customerManagementMenu(Customers *customer, unsigned short int menu);

    void createCustomer(Customers *customer, unsigned short int menu);
    void newNameCustomer(char name[COSTUMER_NAME_SIZE]);
    void newNifCustomer(int *nif);
    void newAgeCustomer(int *age);
    void newCountryCustomer(char country[COSTUMER_COUNTRY_SIZE]);

    int askID(Customers *customer, short int);

    void editCustomer(Customers *customer, unsigned short int menu);
    void removeCustomer(Customers *customer);
    void listCustomer(Customers *customer);







#ifdef __cplusplus
}
#endif

#endif /* ADMIN_H */

