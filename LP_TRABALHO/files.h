/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   files.h
 * Author: RP
 *
 * Created on 7 de janeiro de 2023, 16:36
 */

#ifndef FILES_H
#define FILES_H
#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "auxi.h"
void saveCustomers(Customers *customer);
void loadCustomers(Customers *customer);
void saveMaterials(MaterialsList * materialsList);
void loadMaterials(MaterialsList * materialsList);



#ifdef __cplusplus
}
#endif

#endif /* FILES_H */

