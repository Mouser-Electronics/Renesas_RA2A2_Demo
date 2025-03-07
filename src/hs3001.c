/***********************************************************************************************************************
 * Copyright [2020-2021] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/
#include "hal_data.h"
#include "hs3001.h"

static     unsigned char data[4];

/************************************************************************************
* Name:       hs3001_init
* Function:   initialize HS3001
* Parameters: none
* Return:     none
************************************************************************************/
void hs3001_init(void)
{
    g_i2c_hs3001.p_api->open(g_i2c_hs3001.p_ctrl, g_i2c_hs3001.p_cfg);

}

/************************************************************************************
* Name:       hs3001_read
* Function:   read data from HS3001
* Parameters: none
* Return:     none
************************************************************************************/
void hs3001_read(hs3001_data_t* hs3001_data)
{
    fsp_err_t status;
    unsigned int tem_data = 0;
    unsigned int hum_data = 0;


    status = g_i2c_hs3001.p_api->write(g_i2c_hs3001.p_ctrl, data, 0, false); /* send address for data request */
    R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);  /* ready for 50ms for measure */
    status = g_i2c_hs3001.p_api->read(g_i2c_hs3001.p_ctrl, data, sizeof(data),false); /* start i2c then read data */

    /* calculate temperature data */
    tem_data = (unsigned int)data[2];
    tem_data = (tem_data << 8) + data[3];
    tem_data = tem_data >> 2;       /* Clear status bit: bit 15, bit 14*/
    hs3001_data->temprature = (float)tem_data;
    hs3001_data->temprature = (hs3001_data->temprature/(16384 - 1)) * 165 - 40;

    /* calculate humidity data */
    hum_data = (unsigned int)data[0];
    hum_data = (hum_data << 8 )+ data[1];
    hum_data = hum_data & 0x3FFFF;    /* get the data D13-D0*/
    hs3001_data->humidity = (float)hum_data;
    hs3001_data->humidity = (hs3001_data->humidity/(16384 - 1)) * 100;
}

/************************************************************************************
* Name:       sci_i2c_master_callback
* Function:   i2c callbalck routine
* Parameters: p_args
* Return:     none
************************************************************************************/
void sci_i2c_master_callback(i2c_master_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
}
