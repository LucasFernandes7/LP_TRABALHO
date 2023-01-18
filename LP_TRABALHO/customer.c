
#include "customer.h"

void buy(Products * products, Customers * customer, Orders * orders) {
    int id;
    if (products->counter == 0 || customer->userCounter == 0) {
        printf(INVALID_SHOP);
    } else {

        id = askID(*(&customer), id);
        orders->order[orders->ordersConter].IDcustomer = id;

                choseProducts(products, orders);
        
        //DATA(ESCOLHER, ETC)
        
        
        orders->ordersConter++;
    }
}

void listProductsNames(Products * products) {
    int i;
    for (i = 0; i < products->counter; i++) {
        printf(" %d - %s\n", products->product[i].productID, products->product[i].productName);
    }

}

void choseProducts(Products * products, Orders * orders) {
    int productID;
    listProductsNames(products);

    do {
        printf(USE_PRODUCTS_MENU);

        productID = askProductID(products,  productID);

        orders->order[orders->ordersConter].orderedProduct[orders->order[orders->ordersConter].orderedProductsCounter].productID = productID;

        quantity(& orders->order[orders->ordersConter].orderedProduct[orders->order[orders->ordersConter].orderedProductsCounter].quantity);

        orders->order[orders->ordersConter].state = 0;

        orders->order[orders->ordersConter].orderedProductsCounter++;


    } while (productID != 0);
}
