/*
 * keypad.h : Raspberry PI (bcm2835) compatible switching keypad library
 *
 *  Created on: Oct 8, 2013
 *      Author: X. Zubizarreta
 */
#include <bcm2835.h>
 #include <stdio.h>
 
//Define the conencted pins
#define PIN24 RPI_GPIO_P1_24
#define PIN23 RPI_GPIO_P1_23
#define PIN22 RPI_GPIO_P1_22
#define PIN21 RPI_GPIO_P1_21

#define PIN11 RPI_GPIO_P1_11
#define PIN12 RPI_GPIO_P1_12
#define PIN15 RPI_GPIO_P1_15
#define PIN16 RPI_GPIO_P1_16

//Define the size of the keypad
#define ROWS 4
#define COLS 4

//define the column positions to pins
  char cols[4]={PIN24,PIN23,PIN21,PIN22};
//define the row position to pins
  char row[4]={PIN16,PIN15,PIN11,PIN12};
//setup the character mapping
  char map[4][4]={{'1','2','3','A'},
				  {'4','5','6','B'},
				  {'7','8','9','C'},
				  {'*','0','#','D'}};
  
  #define antibounce 100

//Initializes the driver for the GPIO and configures the keypad
init_keypad();
//Polls for a key (returns 0 if none is currently pushed)
char get_key();
//Waits until a key is pressed
char wait_key();
