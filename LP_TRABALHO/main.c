#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "admin.h"
#include "customer.h"
#include "files.h"

int main() {


    Customers *customer;
    Products *products;
    MaterialsList *materialsList;
    customer = (Customers*) malloc(sizeof (Customers)*1);
    customer-> customers = (Customer*) malloc(sizeof (Customer)*1);
    
    products = (Products*) malloc(sizeof (Products)*1);
    products-> product = (Product*) malloc(sizeof (Product)*1);
    products-> product->materials = (Materials*) malloc(sizeof (Materials)*1);
    
    
    materialsList = (MaterialsList*) malloc(sizeof (MaterialsList)*1);
    materialsList-> materialsLine = (MaterialsLine*) malloc(sizeof (MaterialsLine)*1);

   loadCustomers(customer);
   
    fflush(stdin);
    primaryMenu(customer,products,materialsList);
    fflush(stdin);


    return (EXIT_SUCCESS);



}
