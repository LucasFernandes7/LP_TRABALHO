#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "admin.h"
#include "customer.h"
#include "files.h"
#include "products.h"

unsigned short int menuRead(char message[], unsigned short int min, unsigned short int max) {
    short int option;
    do {
        puts(message);
        printf("Insert Option \n");
        scanf("%hu", &option);
        if (option < min || option > max) {
            printf(INVALID_MSG);
        }
    } while (option < min || option > max);

    return option;

}

void primaryMenu(Customers *customer, Products *products, MaterialsList *materialsList, Orders * orders) {

    unsigned short int menu;


    do {
        menu = menuRead(MSG_PRIMARY_MENU, 0, 3);
        switch (menu) {

            case 1:
                buy(products, customer, orders);
                break;

            case 2:
                adminMenu(customer, &(*products), &(*materialsList), menu);
                break;
            case 3:
                loadMenu(customer, &(*products), &(*materialsList), menu);
        }
    } while (menu != 0);

}

void adminMenu(Customers *customer, Products *products, MaterialsList *materialsList, unsigned short int menu) {

    fflush(stdin);
    do {
        menu = menuRead(MSG_ADMIN_MENU, 0, 3);
        switch (menu) {

            case 1:

                customerManagementMenu(customer, menu);
                break;

            case 2:
                productsManagementMenu(*(&products), *(&materialsList), menu);
                break;
        }

    } while (menu != 0);


}

void customerManagementMenu(Customers *customer, unsigned short int menu) {

    do {
        menu = menuRead(MSG_ADMIN_CUSTOMER_MENU, 0, 5);

        switch (menu) {

            case 0:
                break;

            case 1:
                //criar cliente          
                createCustomer(*(&customer), menu);

                break;
            case 2:
                //editar clientes
                editCustomer(*(&customer), menu);
                break;

            case 3:
                removeCustomer(*(&customer));
                break;

            case 4:
                //listar clientes
                listCustomer(customer);
                break;

            case 5:
                saveCustomers(customer);
                break;
        }

    } while (menu != 0);


}

void newNameCustomer(char name[COSTUMER_NAME_SIZE]) {
    char temp;
    printf("\n Insert customer's name\n");
    //So para de gravar quando clicar enter
    scanf("%c", &temp);
    scanf("%[^\n]", name);
    fflush(stdin);

}

void newNifCustomer(int *nif) {
    do {
        printf("\n Insert customer's NIF\n");
        scanf(" %d", nif);
        if (*nif <= 0) {
            printf(INVALID_MSG);
        }
    } while (*nif <= 0);
}

void newAgeCustomer(int *age) {
    do {
        printf("\n Insert customer's age\n");
        scanf(" %d", age);
        fflush(stdin);
        if (*age < 16 || *age > 110) {
            printf(INVALID_MSG);
            printf(AGE_GAP);
        }
    } while (*age < 16 || *age > 110);

}

void newAddressCustomer(char address[COSTUMER_ADDRESS_SIZE]) {
    char temp;
    printf("\n Insert customer's address\n");
    scanf("%c", &temp);
    scanf("%[^\n]", address);
    fflush(stdin);
}

void newCountryCustomer(char country[COSTUMER_COUNTRY_SIZE]) {
    char temp;
    printf("\n Insert customer's country\n");
    scanf("%c", &temp);
    scanf("%[^\n]", country);
    fflush(stdin);
}

int askID(Customers *customer, short int id) {
    int i;
    do {
        printf("Insert the customer's ID:\n");
        scanf("%hu", &id);

        if (id < 0 || id > (customer->customers[customer->userCounter - 1 ].id)) {
            printf(INVALID_MSG);
            printf("Valid options:\n");

            for (i = 0; i < (customer->customers[customer->userCounter - 1 ].id); i++) {
                printf("ID: %d \n", customer->customers[i].id);
            }
            printf("\n");
        }

    } while (id < 0 || id > customer->customers[customer->userCounter - 1 ].id);

    return id;
}

void createCustomer(Customers *customer, unsigned short int menu) {

    customer->customers = realloc(customer->customers, sizeof (Customer) * ((customer->userCounter) + 1));

    newNameCustomer(customer->customers[customer->userCounter].name);

    newNifCustomer(&customer->customers[customer->userCounter].nif);

    newAgeCustomer(&customer->customers[customer->userCounter].age);

    newAddressCustomer(customer->customers[customer->userCounter].address);

    newCountryCustomer(customer->customers[customer->userCounter].country);
    if (customer->userCounter != 0) {
        customer->customers[customer->userCounter].id = customer->customers[ customer->userCounter - 1].id + 1;
    } else {
        customer->customers[customer->userCounter].id = 1;
    }
    customer->userCounter++;


}

void editCustomer(Customers *customer, unsigned short int menu) {
    short int id;
    char temp;
    int i;

    if (customer->userCounter == 0) {
        puts(NO_CUSTOMERS_MSG);
    } else {

        id = askID(*(&customer), id);

        do {
            menu = menuRead(MSG_ADMIN_CUSTOMER_EDIT, 0, 5);
            switch (menu) {

                case 0:

                    break;

                case 1:
                    newNameCustomer(customer->customers[id - 1].name);
                    break;

                case 2:
                    newNifCustomer(&customer->customers[id - 1].nif);
                    break;

                case 3:
                    newAgeCustomer(&customer->customers[id - 1].age);
                    break;

                case 4:
                    newAddressCustomer(customer->customers[id - 1].address);
                    break;
                case 5:
                    newCountryCustomer(customer->customers[id - 1].country);
                    break;
            }
        } while (menu != 0);
    }
}

void removeCustomer(Customers *customer) {
    short int id;
    int i;
    if (customer->userCounter == 0) {
        printf(NO_CUSTOMERS_MSG);
    } else {

        id = askID(*(&customer), id);

        for (i = 0; i < (customer->userCounter); i++) {

            customer->customers[id - 1 + i].id = customer->customers[id + i].id;
            strcpy(customer->customers[id - 1 + i].name, customer->customers[id + i].name);
            customer->customers[id - 1 + i].nif = customer->customers[id + i].nif;
            customer->customers[id - 1 + i].age = customer->customers[id + i].age;
            strcpy(customer->customers[id - 1 + i].address, customer->customers[id + i].address);
            strcpy(customer->customers[id - 1 + i].country, customer->customers[id + i].country);
            //printf("%d, %d", i, i + 1);

        }
        customer->userCounter--;
        customer = (Customers *) realloc(customer, sizeof (Customers) * (customer->userCounter));
        printf(REMOVED_MSG);
    }
}

void listCustomer(Customers *customer) {

    int i;

    for (i = 0; i < customer->userCounter; i++) {
        fflush(stdin);
        printf("\nID: %d \n \
Nome: %s \n \
NIF: %d \n \
Age: %d \n \
Address: %s \n \
Country: %s \n\n", customer->customers[i].id,
                customer->customers[i].name,
                customer->customers[i].nif,
                customer->customers[i].age,
                customer->customers[i].address,
                customer->customers[i].country);
        fflush(stdin);
    }
    if (customer->userCounter == 0) {
        printf("There are no customers\n");
    } else if (customer->userCounter == 1) {
        printf("There is 1 custumer\n");
    } else if (customer->userCounter > 1) {
        printf("There are %d custumers\n", customer->userCounter);
    }

}
