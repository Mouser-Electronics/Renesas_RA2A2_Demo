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
#include "dialog_wifi_demo.h"
#include "da16200_AT.h"
#include "hal_data.h"
#include "http_server.h"
#include "common_utils.h"

demo_data_t g_demo_data;
static uint8_t http_ip_port[500];
static void dialog_wifi_demo_init(void);
/* here is my local HTML contents */

/************************************************************************************
* Name:       dialog_wifi_demo
* Function:   run dialog wifi demo
* Parameters: none
* Return:     none
************************************************************************************/
void dialog_wifi_demo(void)
{

    http_receive_status http_status;
    fsp_err_t err;
    /* Wi-Fi initializatoin */
    dialog_wifi_demo_init();
    /* Wi-Fi setting */
   err = wifi_set();
   if(err)
   {
       APP_PRINT("Wifi setting Error! \r\n");
   }
   APP_PRINT("Wifi setting OK, please connect Wi-Fi or open http client \r\n");
   while(1)
   {
       memset(http_ip_port, 0, 500);
       http_status = HTTP_ERROR;
       /* Wi-Fi server data receive */
       http_status = http_server_receive(http_ip_port);
       switch(http_status)
       {
           /* HTTP GET command received */
           case HTTP_GET:
               http_update(http_ip_port);
               APP_PRINT("HTTP GET received, update Success! \r\n");
           break;
           /* HTTP LED ON command received */
           case HTTP_LED_ON:
           g_demo_data.led_blink_flag = 0;
           g_demo_data.led_blink_count = 0;
           g_ioport.p_api->pinWrite(g_ioport.p_ctrl, LED, BSP_IO_LEVEL_HIGH);
           http_update(http_ip_port);
           APP_PRINT("HTTP LED ON received, update Success! \r\n");
           break;
           /* HTTP LED OFF command received */
           case HTTP_LED_OFF:
           g_demo_data.led_blink_flag = 0;
           g_demo_data.led_blink_count = 0;
           g_ioport.p_api->pinWrite(g_ioport.p_ctrl, LED, BSP_IO_LEVEL_LOW);
           http_update(http_ip_port);
           APP_PRINT("HTTP LED OFF received, update Success! \r\n");
           break;
           /* HTTP LED BLINK command received */
           case HTTP_LED_BLINK:
           g_demo_data.led_blink_flag = 1;
           g_demo_data.led_blink_count = 0;
           http_update(http_ip_port);
           APP_PRINT("HTTP LED BLINK received, update Success! \r\n");
           break;
           /* HTTP OHTER command received */
           case HTTP_OTHERS:
           http_update(http_ip_port);
           APP_PRINT("HTTP OTHERS received, update Success! \r\n");
           break;

           default:

           break;
       }


   }
}

/************************************************************************************
* Name:       dialog_wifi_demo_init
* Function:   initialize wifi demo
* Parameters: none
* Return:     none
************************************************************************************/
static void dialog_wifi_demo_init(void)
{
    fsp_err_t status;
    /* hs3001 intialize*/
    hs3001_init();

    /* Key initialize */
    g_external_sw1.p_api->open(g_external_sw1.p_ctrl, g_external_sw1.p_cfg);
    g_external_sw1.p_api->enable(g_external_sw1.p_ctrl);

    /* variable init*/
    g_demo_data.hs3001_data.humidity = 0;
    g_demo_data.hs3001_data.temprature = 0;
    g_demo_data.key_count = 0;
    g_demo_data.led_blink_flag = 0;
    g_demo_data.led_blink_count = 0;

    /* Wifi init*/
   status = wifi_init();
   if(status)
   {
       APP_PRINT("Wifi Initialize Error, please restart \r\n");
       while(1);
   }
   APP_PRINT("Wifi Initialize Success! \r\n");
}

/************************************************************************************
* Name:       sw1_callback
* Function:   button interrupt callback
* Parameters: p_args
* Return:     none
************************************************************************************/
void sw1_callback(external_irq_callback_args_t *p_args)
{
    bsp_io_level_t ioport_read_data;
    FSP_PARAMETER_NOT_USED(p_args);
    R_BSP_SoftwareDelay(10,BSP_DELAY_UNITS_MILLISECONDS);
    g_ioport.p_api->pinRead(g_ioport.p_ctrl, BUTTON, &ioport_read_data);
    if(BSP_IO_LEVEL_LOW == ioport_read_data)
    {
        g_demo_data.key_count++;
    }

}

