#include"products.h"
#include <string.h>

void productsManagementMenu(Products *products, MaterialsList *materialsList, unsigned short int menu) {
    do {
        menu = menuRead(MSG_ADMIN_PRODUCTS_MENU, 0, 6);

        switch (menu) {

            case 0:
                break;

            case 1:

                createProduct(*(&products), *(&materialsList));

                break;
            case 2:

                editProduct(*(&products), *(&materialsList), menu);
                break;

            case 3:
                //removeProduct(*(&products));
                break;

            case 4:

                listProducts(*(&products));
                break;

            case 5:
                //saveP(*(&products));
                break;

            case 6:
                materialsMenu(*(&materialsList), menu);
                break;
        }

    } while (menu != 0);


}

void createProduct(Products * products, MaterialsList *materialsList) {
    if (materialsList->counter == 0) {
        printf("\nCan't create a product without materials\n");

    } else {
        printf("%d", materialsList->counter);
        products->product = realloc(products->product, sizeof (Product)*(products->counter + 1));

        products->product[products->counter].productID = products->product[products->counter - 1].productID + 1;

        newProductName(products->product[products->counter].productName);

        useMaterials(*(&products), *(&materialsList), products->counter);

        newDimensions(products->product[products->counter].dimension);


        newPrice(&products->product[products->counter].price);

        products->counter++;
    }
}
int codeExists(MaterialsList *materialList, int code){
    int i, counter = 0;
    for (i = 0; i < materialList->counter; i++)
    {
            printf("Código na lista: %d\n", materialList->materialsLine[i].code);
        if (materialList->materialsLine[i].code == code){
            printf("Passei por aqui");
            counter ++;
        }
    }
    return (counter == 0);
}

void useMaterials(Products *products, MaterialsList *materialsList, int position) {

    int code;
    int i;
    unsigned short int aux;
    listMaterials(*(&materialsList));
    do {
        do{
        printf(USE_MATERIALS_MENU);
        scanf(" %d", &code);
        }while(codeExists(materialsList, code));
        printf(" %d", code);
        for (i = 0; i < products->product[position].usedMaterialsCounter; i++) {
            if (code == products->product[position].materials[i].code) {
                aux = code;
                break;
            }
        }
        if (code != 0 && code != aux) {
            products->product->materials = realloc(products->product->materials, sizeof (Materials)*(products->product->usedMaterialsCounter) + 1);

            products->product[position].materials[ products->product->usedMaterialsCounter].code = code;

            materialQuantity(products->product[position].materials[ products->product[position].usedMaterialsCounter].quantity);

            products->product[position].usedMaterialsCounter++;
        } else if (code == 0) {
            break;
        } else if (code == aux) {
            printf("Already using this material\n");
        }
    } while (code != 0);
}

void materialQuantity(int quantity) {
    do {
        printf("How many?\n");
        scanf("%d", &quantity);

        if (quantity < 0) {
            printf(INVALID_MSG);
        }
    } while (quantity < 0);
}

void newProductName(char name[PRODUCT_SIZE_NAME]) {

    char temp;
    printf("\n Insert produc's name:\n");
    scanf("%c", &temp);
    scanf("%[^\n]", name);
    fflush(stdin);
}

void newPrice(float *price) {
    do {
        printf("\n Insert product's price[€]:\n");
        scanf("%f", price);
        if (price < 0) {
            printf(INVALID_MSG);
        }
    } while (price < 0);
}

void newDimensions(float dimension[]) {
    do {
        printf("\n How high is it?[cm]\n");
        scanf("%f", &dimension[0]);
        if (dimension[0] < 0) {
            printf(INVALID_MSG);
        }
    } while (dimension[0] < 0);

    do {
        printf("\n How long is it?[cm]\n");
        scanf("%f", &dimension[1]);
        if (dimension[1] < 0) {
            printf(INVALID_MSG);
        }
    } while (dimension[1] < 0);

    do {
        printf("\n How wide is it?[cm]\n");
        scanf("%f", &dimension[2]);
        if (dimension[2] < 0) {
            printf(INVALID_MSG);
        }
    } while (dimension[2] < 0);
}

void editProduct(Products *products, MaterialsList *materialsList, unsigned short int menu) {
    int productID, position;
    char temp;
    int i;

    if (products->counter == 0) {
        puts(NO_PRODUCTS_MSG);
    } else {

        productID = askProductID((*(&products)), productID);
        for (i = 0; i < products->product[products->counter].productID; i++) {
            if (products->product[i].productID == productID) {
                position = i;
            }
        }
        do {
            menu = menuRead(MSG_PRODUCTS_EDIT_MENU, 0, 4);
            switch (menu) {
                case 1:
                    editProductsMaterials(*(&products), *(&materialsList), position);
                    break;

                case 2:
                    newProductName(products->product[products->counter].productName);
                    break;

                case 3:
                    newDimensions(products->product[products->counter].dimension);
                    break;

                case 4:
                    newPrice(&products->product[products->counter].price);
                    break;
            }
        } while (menu != 0);
    }
}

void editProductsMaterials(Products *products, MaterialsList *materialsList, short int position) {

    unsigned short int menu, code, materialPosition;
    int i;

    do {
        menu = menuRead(MSG_PRODUCTS_MATERIALS_MENU, 0, 5);

        switch (menu) {

            case 0:
                break;

            case 1:
                //adicionar Materiais         
                useMaterials((*(&products)), (*(&materialsList)), position);
                break;
            case 2:
                //editar quantidade
                code = askUsedCode((*(&products)), code);


                //funcao que verifica a posicao desse codigo
                for (i = 0; i < products->product[position].materials[products->product[position].usedMaterialsCounter - 1].code; i++) {
                    if (products->product[position].materials[i].code == code) {
                        materialPosition = i;
                    }
                }

                materialQuantity(products->product[position].materials[position].quantity);
                break;

            case 3:
                //remove um material
                removeUsedMaterial(*(&products), position);
                break;
        }
    } while (menu != 0);
}

void removeUsedMaterial(Products *products, int position) {
    unsigned short int code;
    int i;
    if (products->product[position].usedMaterialsCounter == 0) {
        puts(NO_MATERIALS_MSG);

    } else {

        code = askUsedCode((*(&products)), code);


        for (i = 0; i < products->product[position].usedMaterialsCounter; i++) {
            products->product[position].materials[code - 1 + i].code = products->product[position].materials[code + i].code;

            products->product[position].materials[code - 1 + i].quantity = products->product[position].materials[code + i].quantity;
        }
        products->product[position].usedMaterialsCounter--;
        products->product[position].materials = realloc(products->product[position].materials, sizeof (Materials)*(products->product[position].usedMaterialsCounter));
        printf(REMOVED_MSG);
    }
}

int askProductID(Products *products, int productID) {
    int i;
    do {
        printf("Insert the product's ID:\n");
        scanf(" %d", &productID);

        if (productID < 0 || productID > products->product[products->counter - 1].productID) {
            printf(INVALID_MSG);
            printf("Valid options:\n");

            for (i = 0; i < products->counter; i++) {
                printf("Product ID: %d \n", products->product[i].productID);
            }
            printf("\n");
        }
    } while (productID < 0 || productID > (products->product[products->counter - 1].productID));
    return productID;
}

void listProducts(Products *products) {

    int i, j;

    for (i = 0; i < products->counter; i++) {
        fflush(stdin);
        printf("\nProduct ID: %d \n \
        Product Name: %s \n \
        Dimensions: %f x %f x %f\n \
        Price: %f \n \
        Materials Used: %d", products->product[i].productID,
                products->product[i].productName,
                products->product[i].dimension[0],
                products->product[i].dimension[1],
                products->product[i].dimension[2],
                products->product[i].price,
                products->product[i].usedMaterialsCounter);

        for (j = 0; j < products->product->usedMaterialsCounter; j++) {
            printf("\nCode: %d \n \
Quantity: %d \n", products->product[i].materials[j].code,
                    products->product[i].materials[j].quantity);
        }
        printf("\n");
    }
    if (products->counter == 0) {
        printf(NO_PRODUCTS_MSG);
    } else if (products->counter == 1) {
        printf("There is 1 product\n");
    } else if (products->counter > 1) {

        printf("There are %d products\n", products->counter);
    }

}

void materialsMenu(MaterialsList *materialsList, unsigned short int menu) {
    do {
        menu = menuRead(MSG_PRODUCTS_MATERIALS_MENU, 0, 5);

        switch (menu) {

            case 0:
                break;

            case 1:

                createMaterial(*(&materialsList));

                break;
            case 2:

                editMaterial(*(&materialsList), menu);
                break;

            case 3:
                removeMaterial(*(&materialsList));
                break;

            case 4:

                listMaterials(*(&materialsList));
                break;

            case 5:
                saveMaterials(*(&materialsList));
                break;
        }

    } while (menu != 0);


}

void createMaterial(MaterialsList *materialsList) {

    materialsList->materialsLine = realloc(materialsList->materialsLine, sizeof (MaterialsLine)*(materialsList->counter + 1));

    materialsList->materialsLine[materialsList->counter].code = materialsList->materialsLine[materialsList->counter - 1].code + 1;

    newDescription(materialsList->materialsLine[materialsList->counter].description);

    newType(&materialsList->materialsLine[materialsList->counter].type);

    materialsList->counter++;

}

void newType(Type *type) {

    *type = menuRead(MSG_TYPE, 0, 1);
}

void newDescription(char description[DESCRIPTION_SIZE]) {

    char temp;
    printf("\n Insert Description\n");
    scanf("%c", &temp);
    scanf("%[^\n]", description);
    fflush(stdin);
}

void editMaterial(MaterialsList *materialsList, unsigned short int menu) {
    short int code;
    char temp;
    int i;

    if (materialsList->counter == 0) {
        puts(NO_MATERIALS_MSG);
    } else {

        code = askCode((*(&materialsList)), code);

        do {
            menu = menuRead(EDIT_MATERIALS_MENU, 0, 2);
            switch (menu) {

                case 1:
                    newDescription(materialsList->materialsLine[code - 1].description);
                    break;

                case 2:
                    newType(&materialsList->materialsLine[code - 1].type);
                    break;

            }
        } while (menu != 0);
    }
}

int askUsedCode(Products *products, short int code) {
    int i;
    int continua = 0;
    do {
        printf("Insert the material's Code:\n");
        scanf("%hu", &code);
        for (i = 0; i < products->product->usedMaterialsCounter; i++) {
            if (code = products->product->materials->code) {
                continua = 1;
                break;
            }
        }
        if (continua = 0) {
            printf(INVALID_MSG);
            printf("Valid options:\n");

            for (i = 0; i < products->product->usedMaterialsCounter; i++) {
                printf("Code: %d \n", products->product->materials[i].code);
            }
            printf("\n");
        }
    } while (continua = 0);
    return code;
}

int askCode(MaterialsList *materialsList, short int code) {
    int i;
    do {
        printf("Insert the material's Code:\n");
        scanf("%hu", &code);

        if (code < 0 || code > materialsList->materialsLine[materialsList->counter - 1 ].code) {
            printf(INVALID_MSG);
            printf("Valid options:\n");

            for (i = 0; i < materialsList->materialsLine[materialsList->counter - 1 ].code; i++) {
                printf("Code: %d \n", materialsList->materialsLine[i].code);
            }
            printf("\n");
        }
    } while (code < 0 || code > materialsList->materialsLine[materialsList->counter - 1 ].code);

    return code;
}

void removeMaterial(MaterialsList *materialsList) {
    short int code;
    char temp;
    int i;

    if (materialsList->counter == 0) {
        puts(NO_MATERIALS_MSG);
    } else {

        code = askCode((*(&materialsList)), code);


        for (i = 0; i < (materialsList->counter); i++) {
            materialsList->materialsLine[code - 1 + i].code = materialsList->materialsLine[code + i].code;

            strcpy(materialsList->materialsLine[code - 1 + i].description, materialsList->materialsLine[code + i].description);

            materialsList->materialsLine[code - 1 + i].type = materialsList->materialsLine[code + i].type;
        }
        materialsList->counter--;
        materialsList->materialsLine = realloc(materialsList->materialsLine, sizeof (MaterialsLine)*(materialsList->counter));
        printf(REMOVED_MSG);
    }
}

void listMaterials(MaterialsList *materialsList) {

    int i;


    for (i = 0; i < materialsList->counter; i++) {
        fflush(stdin);
        printf("\nCode: %d \n \
Description: %s \n ", materialsList->materialsLine[i].code,
                materialsList->materialsLine[i].description);
        fflush(stdin);
        if (materialsList->materialsLine[i].type == Single) {
            printf("Type: Single\n\n");
        } else if (materialsList->materialsLine[i].type == Pair) {
            printf("Type: Pair\n\n");
        }
    }
    if (materialsList->counter == 0) {
        printf("There are no materials\n");
    } else if (materialsList->counter == 1) {
        printf("There is 1 material\n");
    } else if (materialsList->counter > 1) {
        printf("There are %d materials\n", materialsList->counter);
    }

}
