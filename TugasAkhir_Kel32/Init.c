/*************************************************************
 * @file      : Init.c
 * @brief     : Peripheral Init Functions
 * @version   : 1.2.3
 * @date      : 05/16/2019  15:04 
 * @author    : Created by CoSmart 1.2.3
**************************************************************/
#include "DrvGPIO.h"
#include "DrvSPI.h"

/*************************************************************
 * GPIOE Initialization
**************************************************************/
void GPIOE_Init()
{
   //
   // Set PE0 Pin Mode
   //
   DrvGPIO_Open(E_GPE, 0, E_IO_OUTPUT);
   //
   // Set PE1 Pin Mode
   //
   DrvGPIO_Open(E_GPE, 1, E_IO_OUTPUT);
   //
   // Set PE2 Pin Mode
   //
   DrvGPIO_Open(E_GPE, 2, E_IO_OUTPUT);
   //
   // Set PE3 Pin Mode
   //
   DrvGPIO_Open(E_GPE, 3, E_IO_OUTPUT);
   //
   // Set PE4 Pin Mode
   //
   DrvGPIO_Open(E_GPE, 4, E_IO_OUTPUT);
   //
   // Set PE5 Pin Mode
   //
   DrvGPIO_Open(E_GPE, 5, E_IO_OUTPUT);
   //
   // Set PE6 Pin Mode
   //
   DrvGPIO_Open(E_GPE, 6, E_IO_OUTPUT);
   //
   // Set PE7 Pin Mode
   //
   DrvGPIO_Open(E_GPE, 7, E_IO_OUTPUT);

}

/*************************************************************
 * GPIOA Initialization
**************************************************************/
void GPIOB_Init()
{
   //
   // Set PB11 Pin Mode
   //
   DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT);

}

/*************************************************************
 * GPIOA Initialization
**************************************************************/
void GPIOA_Init()
{
   //
   // Set PA0 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 0, E_IO_QUASI);
   //
   // Set PA1 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 1, E_IO_QUASI);
   //
   // Set PA2 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 2, E_IO_QUASI);
   //
   // Set PA3 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 3, E_IO_QUASI);
   //
   // Set PA4 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 4, E_IO_QUASI);
   //
   // Set PA5 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 5, E_IO_QUASI);
   //
   // Set PA12 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT);
   //
   // Set PA13 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 13, E_IO_OUTPUT);
   //
   // Set PA14 Pin Mode
   //
   DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT);

}

/*************************************************************
 * GPIOD Initialization
**************************************************************/
void GPIOD_Init()
{
   //
   // Set PD14 Pin Mode
   //
   DrvGPIO_Open(E_GPD, 14, E_IO_OUTPUT);

}

/*************************************************************
 * GPIOC Initialization
**************************************************************/
void GPIOC_Init()
{
   //
   // Set PC4 Pin Mode
   //
   DrvGPIO_Open(E_GPC, 4, E_IO_OUTPUT);
   //
   // Set PC5 Pin Mode
   //
   DrvGPIO_Open(E_GPC, 5, E_IO_OUTPUT);
   //
   // Set PC6 Pin Mode
   //
   DrvGPIO_Open(E_GPC, 6, E_IO_OUTPUT);
   //
   // Set PC7 Pin Mode
   //
   DrvGPIO_Open(E_GPC, 7, E_IO_OUTPUT);

}

/* SPI CallBack function declaration */
void SPI3_Callback(uint32_t u32UserData);

/*************************************************************
 * SPI Initialization Code Template
**************************************************************/
void SPI3_Init()
{
    E_DRVSPI_PORT eSpiPort;

    /* Get which port to be used */
    eSpiPort = eDRVSPI_PORT3;
    DrvGPIO_InitFunction(E_FUNC_SPI2);

    /* Slave mode; clock parity, transmit and receive edge(eType) */
    DrvSPI_Open(eSpiPort, eDRVSPI_SLAVE, eDRVSPI_TYPE0, 32);

    /* Slave Select Trigger Mode */
    DrvSPI_SetTriggerMode(eSpiPort, eDRVSPI_EDGE_TRIGGER);

    /* Slave Selcet Active Level */
    DrvSPI_SetSlaveSelectActiveLevel(eSpiPort, eDRVSPI_ACTIVE_LOW_FALLING);

    /* LSB or MSB */
    DrvSPI_SetEndian(eSpiPort, eDRVSPI_MSB_FIRST);
}

void Init()
{
    GPIOE_Init();
    GPIOA_Init();
    GPIOB_Init();
    GPIOD_Init();
    GPIOC_Init();
    SPI3_Init();
}
