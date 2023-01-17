/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   products.h
 * Author: RP
 *
 * Created on 8 de janeiro de 2023, 14:32
 */

#ifndef PRODUCTS_H
#define PRODUCTS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "admin.h"
#include <stdio.h>
#include <stdlib.h>
#include "auxi.h"
  
void productsManagementMenu(Products *products, MaterialsList *materialsList, unsigned short int menu);
void removeProduct(Products *products);
void createProduct(Products * products, MaterialsList *materialsList);
void useMaterials(Products *products, MaterialsList *materialsList,int position);
int askCode(MaterialsList *materialsList, short int code);
void materialQuantity(int quantity);
void removeUsedMaterial(Products *products, int position);
void newProductName(char name[PRODUCT_SIZE_NAME]);
void newDimensions(float dimension[2]) ;
void newPrice(float *price);
void editProduct(Products *products, MaterialsList *materialsList, unsigned short int menu);
int askProductID(Products *products, int productID);
void editProductsMaterials(Products *products, MaterialsList *materialsList, short int productID);
int askUsedCode(Products *products, short int code);
void removeMaterial(MaterialsList *materialsList);
void removeProduct(Products * products);
void listProducts(Products *products);
void materialsMenu(MaterialsList *materialsList, unsigned short int menu) ;
void createMaterial(MaterialsList *materialsList) ;
void newType(Type *type);
void newDescription(char description[DESCRIPTION_SIZE]);
void editMaterial(MaterialsList *materialsList, unsigned short int menu);
void removeMaterial(MaterialsList *materialsList);
void listMaterials(MaterialsList *materialsList);
#ifdef __cplusplus
}
#endif

#endif /* PRODUCTS_H */

