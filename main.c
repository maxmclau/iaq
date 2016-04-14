/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <uart.h>
#include <i2c_master.h>

#define LED PB5

#define IAQ_ADDR 0x5A
#define IAQ_READ 0xB5

char buffer[10];

uint16_t pred = 0;
uint16_t status = 0;
uint32_t resistance = 0;
uint16_t tvoc = 0;


void getVal()
{
  if(!i2c_start(IAQ_ADDR))
	{
    
    uart_puts("Error");
    
    i2c_stop();
    

	} else
  {
    
    uart_puts("Start ");
    
    i2c_start((IAQ_ADDR << 1) + 1);
    
    pred = ((uint16_t)i2c_read_ack())<<8;
    pred |= i2c_read_ack();
    
    status = ((uint16_t)i2c_read_ack())<<8;
    status |= i2c_read_ack();
    
    resistance = ((uint32_t)i2c_read_ack())<<8;
    resistance |= i2c_read_ack();
    
    tvoc = ((uint16_t)i2c_read_ack())<<8;
    tvoc |= i2c_read_nack();
    
    i2c_stop();
	}
}

int main(void)
{
  init_uart(57600);
  i2c_init();

  DDRB = _BV(5);

    for(;;)
    {

      getVal();
      
      itoa(pred, buffer, 10); //convert decimal to string base 10
      uart_puts(buffer);
      uart_puts(":pred ");
      
			itoa(status, buffer, 10); 
      uart_puts(buffer);
      uart_puts(":status ");
      
      itoa(resistance, buffer, 10);
      uart_puts(buffer);
      uart_puts(":resistance ");
      
      itoa(tvoc, buffer, 10);
      uart_puts(buffer);
      uart_puts(":tvoc ");
      uart_puts("\n\r");

      PORTB = 0xFF;
      _delay_ms(500);
      PORTB = 0x00;
      _delay_ms(500);
    }
    return 0;   /* never reached */
}
