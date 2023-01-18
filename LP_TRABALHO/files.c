/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */
#include "admin.h"
#include "customer.h"
#include "auxi.h"
#include "products.h"
#include <stdlib.h>
#include <stdio.h>

void loadMenu(Customers *customer, Products *products, MaterialsList *materialsList, unsigned short int menu) {
    do {
        menu = menuRead(MSG_LOAD_MENU, 0, 3);
        switch (menu) {
            case 1:
                loadCustomers(customer);
                break;
            case 2:
                loadMaterials(materialsList);
                break;
            case 3 :
                loadProducts(*(&products));
                break;
        }
    } while (menu != 0);
    printf(LOAD_MSG);
}

void saveCustomers(Customers *customer) {
    int i;
    FILE *fp;
    fp = fopen(FILE_NAME_CUSTOMERS, "wb+");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    fwrite(&customer->userCounter, sizeof (int), 1, fp);
    for (i = 0; i < customer->userCounter; i++) {
        fwrite(&customer->customers[i].id, sizeof (int), 1, fp);
        fwrite(&customer->customers[i].name, sizeof (char)*COSTUMER_NAME_SIZE, 1, fp);
        fwrite(&customer->customers[i].nif, sizeof (int), 1, fp);
        fwrite(&customer->customers[i].age, sizeof (int), 1, fp);
        fwrite(&customer->customers[i].address, sizeof (char)*COSTUMER_ADDRESS_SIZE, 1, fp);
        fwrite(&customer->customers[i].country, sizeof (char)*COSTUMER_COUNTRY_SIZE, 1, fp);
    }
    fclose(fp);
    printf(SAVED_MSG);
}

void loadCustomers(Customers *customer) {

    int i;
    FILE *fp;
    fp = fopen(FILE_NAME_CUSTOMERS, "rb+");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    fread(&customer->userCounter, sizeof (int), 1, fp);

    customer->customers = (Customer*) realloc(customer->customers, sizeof (Customer) * customer->userCounter);

    for (i = 0; i < customer->userCounter; i++) {
        fread(&customer->customers[i].id, sizeof (int), 1, fp);
        fread(&customer->customers[i].name, sizeof (char)*COSTUMER_NAME_SIZE, 1, fp);
        fread(&customer->customers[i].nif, sizeof (int), 1, fp);
        fread(&customer->customers[i].age, sizeof (int), 1, fp);
        fread(&customer->customers[i].address, sizeof (char)*COSTUMER_ADDRESS_SIZE, 1, fp);
        fread(&customer->customers[i].country, sizeof (char)*COSTUMER_COUNTRY_SIZE, 1, fp);
    }
    fclose(fp);
    printf(LOAD_MSG);
}

void saveMaterials(MaterialsList * materialsList) {
    int i;
    FILE *fp;
    fp = fopen(FILE_NAME_MATERIALS, "wb+");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    fwrite(&materialsList->counter, sizeof (int), 1, fp);
    for (i = 0; i < materialsList->counter; i++) {
        fwrite(&materialsList->materialsLine[i].code, sizeof (int), 1, fp);
        fwrite(&materialsList->materialsLine[i].description, sizeof (char)*DESCRIPTION_SIZE, 1, fp);
        fwrite(&materialsList->materialsLine[i].type, sizeof (Type), 1, fp);
    }
    fclose(fp);

    printf(SAVED_MSG);
}

void loadMaterials(MaterialsList * materialsList) {

    int i;
    FILE *fp;
    fp = fopen(FILE_NAME_MATERIALS, "rb+");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    fread(&materialsList->counter, sizeof (int), 1, fp);
    for (i = 0; i < materialsList->counter; i++) {
        fread(&materialsList->materialsLine[i].code, sizeof (int), 1, fp);
        fread(&materialsList->materialsLine[i].description, sizeof (char)*DESCRIPTION_SIZE, 1, fp);
        fread(&materialsList->materialsLine[i].type, sizeof (Type), 1, fp);
    }
    fclose(fp);
    printf(LOAD_MSG);
}

void saveProducts(Products * products) {
    int i, j;
    FILE *fp;
    fp = fopen(FILE_NAME_PRODUCTS, "wb+");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    fwrite(&products->counter, sizeof (int), 1, fp);
    for (i = 0; i < products->counter; i++) {
        fwrite(&products->product[i].dimension[0], sizeof (float), 1, fp);
        fwrite(&products->product[i].dimension[1], sizeof (float), 1, fp);
        fwrite(&products->product[i].dimension[2], sizeof (float), 1, fp);
        fwrite(&products->product[i].productName, sizeof (char)*PRODUCT_SIZE_NAME, 1, fp);
        fwrite(&products->product[i].price, sizeof (float), 1, fp);
        fwrite(&products->product[i].productID, sizeof (int), 1, fp);

        fwrite(&products->product[i].usedMaterialsCounter, sizeof (int), 1, fp);

        for (j = 0; j < products->product[i].usedMaterialsCounter; j++) {
            fwrite(&products->product[i].materials[j].code, sizeof (int), 1, fp);
            fwrite(&products->product[i].materials[j].quantity, sizeof (int), 1, fp);

        }
        fclose(fp);

        printf(SAVED_MSG);
    }
}

void loadProducts(Products * products) {

    int i, j;
    FILE *fp;
    fp = fopen(FILE_NAME_PRODUCTS, "rb+");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    fread(&products->counter, sizeof (int), 1, fp);
    for (i = 0; i < products->counter; i++) {
        fread(&products->product[i].dimension[0], sizeof (float), 1, fp);
        fread(&products->product[i].dimension[1], sizeof (float), 1, fp);
        fread(&products->product[i].dimension[2], sizeof (float), 1, fp);
        fread(&products->product[i].productName, sizeof (char)*PRODUCT_SIZE_NAME, 1, fp);
        fread(&products->product[i].price, sizeof (float), 1, fp);
        fread(&products->product[i].productID, sizeof (int), 1, fp);

        fread(&products->product[i].usedMaterialsCounter, sizeof (int), 1, fp);
        products->product[i].materials = (Materials *)realloc(products->product[i].materials, sizeof(Materials) * products->product[i].usedMaterialsCounter);
        for (j = 0; j < products->product[i].usedMaterialsCounter; j++) {
            fread(&products->product[i].materials[j].code, sizeof (int), 1, fp);
            fread(&products->product[i].materials[j].quantity, sizeof (int), 1, fp);
        }
        fclose(fp);
        printf(LOAD_MSG);
    }
}



