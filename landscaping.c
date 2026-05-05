#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {

    // Variables
    char businessName[100];
    char customerName[100];
    char sizeChoice[5];

    int numServices;
    int services[10];
    int i;
    int scheduleChoice;
    float lawnSize;
    float distance;

    // Pricing Constants
    float mowingRatePerSqFt = 0.015;
    float edgingRatePerSqFt = 0.008;
    float mulchRatePerSqFt = 0.024;
    float leafBlowingRatePerSqFt = 0.006;
    float hedgeTrimmingRatePerSqFt = 0.010;
    float fuelRatePerMile = 0.75;

    // Calculated Totals
    float serviceSubtotal = 0.0;
    float fuelSurcharge = 0.0;
    float total = 0.0;

    float mowingCost = 0.0;
    float edgingCost = 0.0;
    float mulchCost = 0.0;
    float leafCost = 0.0;
    float hedgeCost = 0.0;

    int hasMowing = 0;
    int hasEdging = 0;
    int hasMulch = 0;
    int hasLeaf = 0;
    int hasHedge = 0;
    int j = 0;

    printf("\n");
    printf("  -------------------------------------------- \n");
    printf(" |                                            |\n");
    printf(" |    GRASS GONE LANDSCAPING ESTIMATES CO.    |\n");
    printf(" |                                            |\n");
    printf("  -------------------------------------------- \n\n");
    Sleep(400);

    // Business and Customer Names
    printf("Enter your business name:\n> ");
    fgets(businessName, sizeof(businessName), stdin);
    businessName[strcspn(businessName, "\n")] = '\0';

    printf("\nEnter the customer's name:\n> ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = '\0';

    //Service #
    printf("\nHow many services would the client like to add?\n");
    printf("  (1) Mowing\n");
    printf("  (2) Edging\n");
    printf("  (3) Mulch Spreading\n");
    printf("  (4) Leaf Blowing\n");
    printf("  (5) Hedge Trimming\n");
    printf("\nEnter the number of services (1-5): ");
    scanf_s("%d", &numServices);

    printf("Enter the service numbers separated by spaces (e.g. 1 2 3):\n> ");
    for (i = 0; i < numServices; i++) {
        scanf_s("%d", &services[i]);
    }

    for (i = 0; i < numServices; i++) {
        if (services[i] == 1) hasMowing = 1;
        if (services[i] == 2) hasEdging = 1;
        if (services[i] == 3) hasMulch = 1;
        if (services[i] == 4) hasLeaf = 1;
        if (services[i] == 5) hasHedge = 1;
    }

    // Lawn Size
    printf("\nEnter the size of the client's lawn:\n");
    printf("  [S] Small  (~1,500 sq ft)\n");
    printf("  [M] Medium (~5,000 sq ft)\n");
    printf("  [L] Large  (~10,000 sq ft)\n");
    printf("  [C] Custom - enter your own square footage\n");
    printf("\nEnter S, M, L, or C:\n> ");
    scanf_s("%4s", sizeChoice, (unsigned)sizeof(sizeChoice));

    if (sizeChoice[0] == 'S' || sizeChoice[0] == 's') {
        lawnSize = 1500.0;
    }
    else if (sizeChoice[0] == 'M' || sizeChoice[0] == 'm') {
        lawnSize = 5000.0;
    }
    else if (sizeChoice[0] == 'L' || sizeChoice[0] == 'l') {
        lawnSize = 10000.0;
    }
    else {
        printf("Enter your custom lawn size in square feet:\n> ");
        scanf_s("%f", &lawnSize);
    }

    // Job Distance
    printf("\nHow far is the client from the job site? (in miles)\n> ");
    scanf_s("%f", &distance);

    // Schedule Discount
    printf("\nDo you want to apply a recurring schedule discount?\n");
    printf("  [1] One-time visit  (no discount)\n");
    printf("  [2] Weekly          (10%% discount)\n");
    printf("  [3] Bi-weekly       (7%% discount)\n");
    printf("  [4] Monthly         (3%% discount)\n");
    printf("\n> ");
    scanf_s("%d", &scheduleChoice);

    // Custom Rates
    int customRates;
    printf("\nDo you want to enter custom pricing rates?\n");
    printf("[1] Yes\n[2] No (use default rates)\n> ");
    scanf_s("%d", &customRates);

    if (customRates == 1) {
        printf("\nEnter mowing rate per sq ft: ");
        scanf_s("%f", &mowingRatePerSqFt);

        printf("Enter edging rate per sq ft: ");
        scanf_s("%f", &edgingRatePerSqFt);

        printf("Enter mulch rate per sq ft: ");
        scanf_s("%f", &mulchRatePerSqFt);

        printf("Enter leaf blowing rate per sq ft: ");
        scanf_s("%f", &leafBlowingRatePerSqFt);

        printf("Enter hedge trimming rate per sq ft: ");
        scanf_s("%f", &hedgeTrimmingRatePerSqFt);

        printf("Enter fuel rate per mile (Average is 0.15): ");
        scanf_s("%f", &fuelRatePerMile);
    }


    // Calculations 

    if (hasMowing) mowingCost = mowingRatePerSqFt * lawnSize;
    if (hasEdging) edgingCost = edgingRatePerSqFt * lawnSize;
    if (hasMulch)  mulchCost = mulchRatePerSqFt * lawnSize;
    if (hasLeaf)   leafCost = leafBlowingRatePerSqFt * lawnSize;
    if (hasHedge)  hedgeCost = hedgeTrimmingRatePerSqFt * lawnSize;

    serviceSubtotal = mowingCost + edgingCost + mulchCost + leafCost + hedgeCost;

    fuelSurcharge = distance * fuelRatePerMile;

    total = serviceSubtotal + fuelSurcharge;

    if (scheduleChoice == 2) total = total - (serviceSubtotal * 0.10);
    if (scheduleChoice == 3) total = total - (serviceSubtotal * 0.07);
    if (scheduleChoice == 4) total = total - (serviceSubtotal * 0.03);



    //Invoice Output
    printf("\nPreparing invoice");
    for (i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout);
        Sleep(400);
    }
    printf("\n\n");

    // Banner
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("*                                               *\n");
    printf("*           GRASS GONE LANDSCAPING CO.          *\n");
    printf("*                                               *\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n");

    // Business and Customer Names
    printf("  Business  : %s\n", businessName);
    printf("  Client    : %s\n", customerName);
    printf("  Date      : May 2025\n");
    printf("\n");
    printf("  -------------------------------------------------\n");

    // Services
    printf("\n  SERVICES RENDERED:\n\n");
    if (hasMowing) printf("    [x] Mowing          (%.0f sq ft)     $%.2f\n", lawnSize, mowingCost);
    if (hasEdging) printf("    [x] Edging          (%.0f sq ft)     $%.2f\n", lawnSize, edgingCost);
    if (hasMulch)  printf("    [x] Mulch Spreading (%.0f sq ft)     $%.2f\n", lawnSize, mulchCost);
    if (hasLeaf)   printf("    [x] Leaf Blowing    (%.0f sq ft)     $%.2f\n", lawnSize, leafCost);
    if (hasHedge)  printf("    [x] Hedge Trimming  (%.0f sq ft)     $%.2f\n", lawnSize, hedgeCost);
    printf("\n");
    printf("  -------------------------------------------------\n");
    printf("    Services Subtotal:                   $%.2f\n", serviceSubtotal);
    printf("  -------------------------------------------------\n");

    // Fuel
    printf("\nFUEL SURCHARGE:\n");
    printf("  %.1f miles x $%.2f/mi            $%.2f\n", distance, fuelRatePerMile, fuelSurcharge);

    // Schedule 
    printf("\n  SCHEDULE DISCOUNT:\n");
    if (scheduleChoice == 1) printf("    One-time visit                       $0.00\n");
    if (scheduleChoice == 2) printf("    Weekly         (-10%%)               -$%.2f\n", serviceSubtotal * 0.10f);
    if (scheduleChoice == 3) printf("    Bi-weekly      (-7%%)                -$%.2f\n", serviceSubtotal * 0.07f);
    if (scheduleChoice == 4) printf("    Monthly        (-3%%)                -$%.2f\n", serviceSubtotal * 0.03f);

    printf("\n");
    printf("  =================================================\n");

    // Total reveal animation 
    printf("  Calculating total");
    for (i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout);
        Sleep(300);
    }
    printf("\n\n");

    printf("  >>> TOTAL DUE:                          $%.2f <<<\n", total);
    printf("  =================================================\n");
    printf("\n");

    // Animation for Thank You Screen
    printf("  Thank you for choosing %s", businessName);
    for (i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        Sleep(400);
    }
    printf("\n");
    printf("  Payment due upon completion.\n");
    printf("\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("*          Have a great day!  (^_^)             *\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");

    return 0;
}