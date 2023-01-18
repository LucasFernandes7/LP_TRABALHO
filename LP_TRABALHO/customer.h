/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   customer.h
 * Author: RP
 *
 * Created on 27 de dezembro de 2022, 18:00
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H


#ifdef __cplusplus
extern "C" {
#endif
#include "admin.h"
#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include "auxi.h"


void buy(Products * products, Customers * customer, Orders * orders);

void listProductsNames(Products * products);

void choseProducts(Products * products, Orders * orders);







#ifdef __cplusplus
}
#endif

#endif /* CUSTOMER_H */

