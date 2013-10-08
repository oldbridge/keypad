/*
 * keypad.cpp : Raspberry PI (bcm2835) compatible switching keypad library
 *
 *  Created on: Oct 8, 2013
 *      Author: X. Zubizarreta
 */
  #include "keypad.h"
  #include <stdio.h>
  
  char get_key(){
	  //pirform a tiny tiny riset
	  bcm2835_gpio_write(PIN24,  LOW);
	  bcm2835_gpio_write(PIN23,  LOW);
	  bcm2835_gpio_write(PIN21,  LOW);
	  bcm2835_gpio_write(PIN22,  LOW);
  char i,j;
  for (i=0;i<4;i++)
  {
    bcm2835_gpio_write(cols[i], HIGH) ;
    if(i-1==-1) bcm2835_gpio_write(cols[4-1],  LOW) ; //TODO: Avoid this chapuza
    else bcm2835_gpio_write(cols[i-1],  LOW) ; 
	for(j=0;j<4;j++)
	{
		if (bcm2835_gpio_lev(row[j])) return map[j][i];
	}
  }
  return 0;
}
char wait_key(){
	char tekla;
	while(1){
		bcm2835_delay(antibounce);
		tekla=get_key();
		if (tekla != 0) break;
	}
	return tekla;
}
init_keypad(){
	//Start bcm2835 library
	if (!bcm2835_init())
	return 1;

//set columns as outputs (pulses)
  bcm2835_gpio_fsel(PIN24, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(PIN23, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(PIN22, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(PIN21, BCM2835_GPIO_FSEL_OUTP);
  
  //set columns as outputs (pulses)
  bcm2835_gpio_fsel(PIN16, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(PIN15, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(PIN11, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(PIN12, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_set_pud(PIN16, BCM2835_GPIO_PUD_DOWN);
  bcm2835_gpio_set_pud(PIN15, BCM2835_GPIO_PUD_DOWN);
  bcm2835_gpio_set_pud(PIN12, BCM2835_GPIO_PUD_DOWN);
  bcm2835_gpio_set_pud(PIN11, BCM2835_GPIO_PUD_DOWN);
}
