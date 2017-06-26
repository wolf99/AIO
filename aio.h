#ifndef _AIO_H_
#define _AIO_H_

//#############################################################################
//
//! \file   f2802x_common/include/aio.h
//!
//! \brief  Contains public interface to analog I/O (AIO) methods
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//#############################################################################

// **************************************************************************
// the includes

#include <stdint.h>
#include "gpio.h"


//!
//! \defgroup AIO

//!
//! \ingroup AIO
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines

//! \brief Defines the location of the CONFIG bits in the AIOMUX register
//!
#define  AIO_AIOMUX_CONFIG_BITS    (3 << 0)


// **************************************************************************
// the typedefs

//! \brief Enumeration to define the analog I/O (AIO) modes
//!
typedef enum
{
  AIO_Mode_IoEnabled=0,    //!< Denotes the IO function is enabled
  AIO_Mode_IoDisabled=3    //!< Denotes the IO function is disabled
} AIO_Mode_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) numbers
//!
typedef enum
{
	AIO_Rsvd_0=0,       //!< This AIO not present
	AIO_Rsvd_1,         //!< This AIO not present
    AIO_Number_2,       //!< Denotes AIO number 2
	AIO_Rsvd_3,         //!< This AIO not present
    AIO_Number_4,       //!< Denotes AIO number 4
	AIO_Rsvd_5,         //!< This AIO not present
    AIO_Number_6,       //!< Denotes AIO number 6
	AIO_Rsvd_7,         //!< This AIO not present
    AIO_Number_8,       //!< Denotes AIO number 8
	AIO_Rsvd_9,         //!< This AIO not present
    AIO_Number_10,      //!< Denotes AIO number 10
	AIO_Rsvd_11,        //!< This AIO not present
    AIO_Number_12,      //!< Denotes AIO number 12
	AIO_Rsvd_13,        //!< This AIO not present
    AIO_Number_14,      //!< Denotes AIO number 14
    AIO_Rsvd_15,         //!< This AIO not present
    AIO_numAios
} AIO_Number_e;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Returns the data value present on a pin (either input or output)
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] aioNumber   The AIO number
//! \return    The boolen state of a pin (high/low)
uint16_t AIO_getData(GPIO_Handle gpioHandle, const AIO_Number_e aioNumber);


//! \brief     Returns the data value present on the AIO port
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \return    The data values for the port
uint16_t AIO_getPortData(GPIO_Handle gpioHandle);


//! \brief     Sets the analog I/O (AIO) signal direction
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] aioNumber   The AIO number
//! \param[in] direction   The signal direction 
void AIO_setDirection(GPIO_Handle gpioHandle,const AIO_Number_e aioNumber,const GPIO_Direction_e direction);


//! \brief     Sets the specified analog I/O (AIO) signal low
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] aioNumber   The AIO number
void AIO_setLow(GPIO_Handle gpioHandle,const AIO_Number_e aioNumber);


//! \brief     Sets the mode for the specified analog I/O (AIO) signal
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] aioNumber   The AIO number
//! \param[in] mode        The mode
void AIO_setMode(GPIO_Handle gpioHandle,const AIO_Number_e aioNumber,const AIO_Mode_e mode);


//! \brief     Sets the specified analog I/O (AIO) signal high
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] aioNumber   The AIO number
// void AIO_setHigh(GPIO_Handle gpioHandle,const AIO_Number_e aioNumber);


//! \brief     Sets data output on the AIO port
//! \param[in] gpioHandle   The general purpose I/O (GPIO) object handle
//! \param[in] data         The data to write to the port
// void AIO_setPortData(GPIO_Handle gpioHandle, const uint16_t data);


//! \brief     Toggles the specified analog I/O (AIO) signal
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] aioNumber   The AIO number
// void AIO_toggle(GPIO_Handle gpioHandle,const AIO_Number_e aioNumber);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup

#endif // end of _AIO_H_ definition



