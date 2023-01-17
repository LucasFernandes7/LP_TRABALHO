#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "customer.h"
#include "admin.h"


void customerMenu(unsigned short int menu) {


    do {
        menu = menuRead(MSG_CUSTOMER_MENU, 0, 3);
        switch (menu) {

            case 1:

               break;
        }

    } while (menu != 0);


}