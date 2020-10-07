#ifndef EXPANDER_H
#define EXPANDER_H

#include <stdint.h>
#include "matrix.h"

#define MCP23017
#define MCP23017_A0 0
#define MCP23017_A1 0
#define MCP23017_A2 0

#ifdef MCP23017
#define EXPANDER_ADDR ((0x20|(MCP23017_A0<<0)|(MCP23017_A1<<1)|(MCP23017_A2<<2)) << 1)
enum EXPANDER_REG_BANK0 {  //These are all the registers used to control the MCP23017
  EXPANDER_REG_IODIRA = 0, //Used to set the GPA pins as either input (1) or output (0)
  EXPANDER_REG_IODIRB,     //Used to set the GPB pins as either input (1) or output (0)
  EXPANDER_REG_IPOLA,      
  EXPANDER_REG_IPOLB,
  EXPANDER_REG_GPINTENA,
  EXPANDER_REG_GPINTENB,
  EXPANDER_REG_DEFVALA,
  EXPANDER_REG_DEFVALB,
  EXPANDER_REG_INTCONA,
  EXPANDER_REG_INTCONB,
  EXPANDER_REG_IOCONA,
  EXPANDER_REG_IOCONB,
  EXPANDER_REG_GPPUA,
  EXPANDER_REG_GPPUB,
  EXPANDER_REG_INTFA,
  EXPANDER_REG_INTFB,  
  EXPANDER_REG_INTCAPA,  
  EXPANDER_REG_INTCAPB,  
  EXPANDER_REG_GPIOA,    //Used to read input from the GPA pins
  EXPANDER_REG_GPIOB,    //Used to read input from the GPB pins
  EXPANDER_REG_OLATA,    //Used to set the output of the GPA pins 
  EXPANDER_REG_OLATB     //Used to set the output of the GPB pins
};
#endif

void expander_init(void);
void expander_scan(void);
void expander_read_cols(void);
uint8_t expander_get_col(uint8_t col);
matrix_row_t expander_read_row(void);
void expander_unselect_rows(void);
void expander_select_row(uint8_t row);

#endif
