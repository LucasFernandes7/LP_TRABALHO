/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */
#include "admin.h"
#include "customer.h"
#include <stdlib.h>
#include <stdio.h>



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
}



