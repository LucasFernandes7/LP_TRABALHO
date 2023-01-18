/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   auxi.h
 * Author: RP
 *
 * Created on 9 de janeiro de 2023, 19:26
 */

#ifndef AUXI_H
#define AUXI_H

#ifdef __cplusplus
extern "C" {
#endif

#define MSG_PRIMARY_MENU "\n Welcome to Móveis para Todos \n"\
                         "1 - Customer \n"\
                         "2 - Admin \n"\
                         "3 - Load\n"\
                         "0 - Exit \n"

#define MSG_ADMIN_MENU "\n ADMIN PANEL \n"\
                         "1 - Manage Customers \n"\
                         "2 - Manage Products \n"\
                         "3 - Manage Production \n"\
                         "0 - Back"

#define MSG_ADMIN_CUSTOMER_MENU "\n Customers Management \n"\
                                 "1 - Create \n"\
                                 "2 - Edit \n"\
                                 "3 - Remove \n"\
                                 "4 - List \n"\
                                 "5 - Save \n"\
                                 "0 - Back"

#define MSG_ADMIN_CUSTOMER_EDIT "\n Select which one you wnat to edit \n"\
                                 "1 - name \n"\
                                 "2 - NIF \n"\
                                 "3 - age \n"\
                                 "4 - adress\n"\
                                 "5 - country\n"\
                                 "0 - Back"

#define MSG_ADMIN_PRODUCTS_MENU "\n Products Management \n"\
                                 "1 - Create \n"\
                                 "2 - Edit \n"\
                                 "3 - Remove \n"\
                                 "4 - List \n"\
                                 "5 - Save \n"\
                                 "6 - Materials \n"\
                                 "0 - Back"
#define MSG_PRODUCTS_MATERIALS_MENU "\n Materials Management \n"\
                                 "1 - Create \n"\
                                 "2 - Edit \n"\
                                 "3 - Remove \n"\
                                 "4 - List \n"\
                                 "5 - Save \n"\
                                 "0 - Back"
#define MSG_PRODUCTS_MATERIALS_MENU "\n Materials Management \n"\
                                 "1 - Create \n"\
                                 "2 - Edit \n"\
                                 "3 - Remove \n"\
                                 "4 - List \n"\
                                 "5 - Save \n"\
                                 "0 - Back"
#define MSG_PRODUCTS_EDIT_MENU "\n Select which one you wnat to edit \n"\
                                 "1 - Materials \n"\
                                 "2 - Name \n"\
                                 "3 - Dimensions \n"\
                                 "4 - Price\n"\
                                 "0 - Back"
#define MSG_ADMIN_CUSTOMER_EDIT "\n Select which one you wnat to edit \n"\
                                 "1 - name \n"\
                                 "2 - NIF \n"\
                                 "3 - age \n"\
                                 "4 - adress\n"\
                                 "5 - country\n"\
                                 "0 - Back"
#define MSG_CUSTOMER_MENU "\n Select your article \n"\
                         "1 - WC Cabinet \n"\
                         "2 - Dresser (3 Drawers) \n"\
                         "3 - Bedside table \n"\
                         "0 - Back"

#define MSG_LOAD_MENU "\n LOAD MENU\n"\
                         "1 - Customers \n"\
                         "2 - Materials \n"\
                         "3 - Products \n"\
                         "0 - Back"

#define FILE_NAME_MATERIALS "materials.bin"

#define FILE_NAME_PRODUCTS "products.bin"

 #define INVALID_SHOP "Can't buy anything whtout customers or products"

#define REMOVED_MSG "Successfully Removed\n"

#define NO_CUSTOMERS_MSG "No customers\n"

#define NO_MATERIALS_MSG "No materials\n"

#define NO_PRODUCTS_MSG "No products\n"

#define AGE_GAP "[16-110]\n"

#define FILE_NAME_CUSTOMERS "customers.bin"

#define COSTUMER_NAME_SIZE 50

#define USE_MATERIALS_MENU "\nwhich material do you want to use?\n[0-Exit]\n"

    #define USE_PRODUCTS_MENU "\nwhich product do you want to buy?\n[0-Exit]\n"

#define COSTUMER_ADDRESS_SIZE 50

#define COSTUMER_COUNTRY_SIZE 20

#define INVALID_MSG "Invalid Option\n"
#define SAVED_MSG "Successfully Saved\n"
#define LOAD_MSG "Successfully Loaded\n"

#define DESCRIPTION_SIZE 20

#define PRODUCT_SIZE_NAME 20

#define MSG_TYPE "\nInsert type\n"\
                   "0-Single\n"\
                   "1-Pair"

#define EDIT_MATERIALS_MENU "\nISelect which one you wnat to edit\n"\
                    "1-Description\n"\
                    "2-Type\n"\
                    "0-Sair"
#define EXIT_MSG "\nDo you want to continue?\n"\
                    "1-yes\n"\
                    "0-no\n"

    typedef struct {
        int id;
        char name[COSTUMER_NAME_SIZE];
        int nif;
        int age;
        char address[COSTUMER_ADDRESS_SIZE];
        char country[COSTUMER_COUNTRY_SIZE];

    } Customer;

    typedef struct {
        Customer *customers;
        int userCounter;
    } Customers;

    typedef enum {
        Single, Pair
    } Type;

    typedef struct {
        Type type;
        int code;
        char description[DESCRIPTION_SIZE];
    } MaterialsLine;

    typedef struct {
        MaterialsLine * materialsLine;
        int counter;
    } MaterialsList;

    typedef struct {
        int code;
        int quantity;
    } Materials;

    typedef struct {
        Materials *materials;
        int usedMaterialsCounter;
        int productID;
        char productName[PRODUCT_SIZE_NAME];
        float price;
        float dimension[2];
    } Product;

    typedef struct {
        Product *product;
        int counter;
    } Products;

    typedef struct {
        int productID;
        int quantity;
    } OrderedProduct;
 typedef enum {
        ToDo, Ready, delivered
    } State;

    typedef struct {
    int day, month, year;
    }Date;
    typedef struct {
        int IDcustomer;
        OrderedProduct * orderedProduct;
        State state;
        int orderedProductsCounter;
        Date orderDate;    
    } Order;

    typedef struct {
        Order * order;
        int ordersConter;

    } Orders;

    

#ifdef __cplusplus
}
#endif

#endif /* AUXI_H */

