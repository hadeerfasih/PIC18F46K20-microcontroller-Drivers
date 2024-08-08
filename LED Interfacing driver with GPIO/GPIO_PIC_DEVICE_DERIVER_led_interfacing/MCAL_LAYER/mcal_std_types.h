/* 
 * File:   mcal_std_types.h
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 5:12 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/////////section : Includes///////////////////////////////
#include "std_libraries.h"
#include "compiler.h"

/////////section : Macro declarations ////////////////////
#define STD_HIGH        0x01
#define STD__LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK              (Std_ReturnType)0X01;
#define E_NOT_OK             (Std_ReturnType)0X00;



/////////section : Macro function declarations ///////////

/////////section : Data type declarations ///////////////
typedef unsigned char     uint8;
typedef unsigned short    uint16;
typedef unsigned int      uint32;

typedef signed char     sint8;
typedef signed short    sint16;
typedef signed int      sint32;
typedef uint8           Std_ReturnType;
/////////section : Function declarations ///////////////

#endif	/* MCAL_STD_TYPES_H */

