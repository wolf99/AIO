//#############################################################################
//
//! \file   f2802x_common/source/aio.c
//!
//! \brief  The functions in this file are used to configure the analog I/O 
//!         (AIO) registers
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//#############################################################################

// **************************************************************************
// the includes
#include "aio.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

uint16_t AIO_getData(GPIO_Handle gpioHandle, const AIO_Number_e aioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    if(aioNumber < GPIO_Number_32)
    {
        return ((gpio->AIODAT >> aioNumber) & 0x0001);
    }

} // end of GPIO_getData() function


uint16_t AIO_getPortData(GPIO_Handle gpioHandle)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

    return (gpio->AIODAT);

} // end of AIO_getPortData() function


void AIO_setDirection(GPIO_Handle gpioHandle, const AIO_Number_e aioNumber, const GPIO_Direction_e direction)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bit
    gpio->AIODIR &= (~((uint32_t)1 << aioNumber));

    // set the bit
    gpio->AIODIR |= (uint32_t)direction << aioNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of AIO_setDirection() function


void AIO_setHigh(GPIO_Handle gpioHandle, const AIO_Number_e aioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    gpio->GPASET = (uint32_t)1 << aioNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of AIO_setHigh() function


void AIO_setLow(GPIO_Handle gpioHandle, const AIO_Number_e aioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    gpio->AIOCLEAR = (uint32_t)1 << aioNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of AIO_setLow() function


void GPIO_setMode(GPIO_Handle gpioHandle, const AIO_Number_e aioNumber, const AIO_Mode_e mode)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    uint8_t lShift = aioNumber << 1;
    uint32_t clearBits = (uint32_t)AIO_AIOMUX_CONFIG_BITS << lShift;
    uint32_t setBits = (uint32_t)mode << lShift;
  
    // clear the bits
    gpio->AIOMUX1 &= (~clearBits);
  
    // set the bits
    gpio->AIOMUX1 |= setBits;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of AIO_setMode() function


void AIO_setPortData(GPIO_Handle gpioHandle, const uint16_t data)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    gpio->AIODAT = data;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of AIO_setPortData() function


void AIO_toggle(GPIO_Handle gpioHandle, const AIO_Number_e aioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    gpio->AIOTOGGLE = (uint32_t)1 << aioNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of AIO_toggle() function
