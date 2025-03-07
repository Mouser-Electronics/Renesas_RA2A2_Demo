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
#include "http_server.h"
#include "da16200_AT.h"
#include "hs3001.h"
#include "dialog_wifi_demo.h"
#include <stdio.h>
#include <stdlib.h>

static char my_get_contents_updated[] =
"<html>"
"<head><title> HTTP Server</title></head>"
"<body bgcolor=\"#0080FF\" >"
"<font color=\"Gold\">"

"<br>\r\n"
"<br>\r\n"
"<br>\r\n"

  "<H1 ALIGN=\"center\">"
     "<meta http-equiv=\"refresh\" content=\"3\">"
  "  Renesas Electronics "
  "</H1>\r\n"

  "<H1 ALIGN=\"center\">"
  "  Wi-Fi DA16xxx Application Demo "
  "</H1>\r\n"

  "<table ALIGN=\"center\" width=\"100\">\r\n"

    "<tr>"
      "<H1 ALIGN=\"center\"> "
      "<td> Temperature </td>"
      "<td><input type=text value=\"%02d\" readonly=\"readonly\" style=\"text-align:center\"></td>\r\n"
      "<td> C </td>"
      "</H1>\r\n"
    "</tr>"

    "<tr>"
      "<H1 ALIGN=\"center\"> "
      "<td> Humidity </td>"
      "<td><input type=text value=\"%2d\" readonly=\"readonly\" style=\"text-align:center\"></td>\r\n"
      "<td> &#37 </td>"
      "</H1>\r\n"
    "</tr>"
     "<tr>"
       "<H1 ALIGN=\"center\"> "
       "<td> Button Pushed Count </td>"
       "<td><input type=text value=\"%2d\" readonly=\"readonly\" style=\"text-align:center\"></td>\r\n"
       "</H1>\r\n"
     "</tr>"

  "</table>\r\n"

  "<br>\r\n"

    "<font color=\"Orange\">"

  "<form ALIGN=\"center\" method=\"POST\" action=\"index.html\">\r\n"
    "<H2 ALIGN=\"center\"> "
    " LED  CONTROL "
    "<br><input type=submit name=\"blink\" value=\"ON\"> \t  <input type=submit name=\"blink\" value=\"OFF\"> <input type=submit name=\"blink\" value=\"BLINK\"> \r\n \r\n"
    "</H2>\r\n"
 "</form>\r\n\r\n"

 "<H1 ALIGN=\"center\">"
 "  Powered By Renesas ARM MCU Series "
 "</H1>\r\n"

"<br><br>\r\n"
"</font>"
"</body>"
"</html>";


static uint8_t http_buffer[2048];
static uint8_t temp_buffer[2048];
static uint8_t user_buffer[2048];
static uint8_t resp_buff[2048] = {0};

static void http_ippt_get(uint8_t * buffer, uint8_t *ippt);

/************************************************************************************
* Name:       http_server_receive
* Function:   receive data and process receive message
* Parameters: http_ippt
* Return:     http receive status
************************************************************************************/
http_receive_status http_server_receive( uint8_t * http_ippt)
{
    fsp_err_t retval = HTTP_ERROR;
    uint16_t bytes_read = 2048U;
    memset(resp_buff, 0, 2048);
    wifi_serial_read(resp_buff, &bytes_read, 300);

    if(is_str_present((const char*)resp_buff, "/index.html") || is_str_present((const char*)resp_buff, "/"))
    {


        if(is_str_present((const char*)resp_buff, "GET")
                && !is_str_present((const char*)resp_buff,"blink=ON")
                && !is_str_present((const char*)resp_buff,"blink=OFF")
                && !is_str_present((const char*)resp_buff,"blink=BLINK"))
        {
            http_ippt_get(resp_buff,http_ippt);
            return HTTP_GET;
        }
        else
        {
            if(is_str_present((const char*)resp_buff,"blink=ON"))
            {
                       http_ippt_get(resp_buff,http_ippt);
                       if(http_ippt[0] !='1')
                       {
                           return HTTP_ERROR;
                       }
                       return HTTP_LED_ON;
             }
             else if(is_str_present((const char*)resp_buff,"blink=OFF"))
             {
                       http_ippt_get(resp_buff,http_ippt);
                       if(http_ippt[0] !='1')
                       {
                           return HTTP_ERROR;
                       }
                       return HTTP_LED_OFF;
              }
              else if(is_str_present((const char*)resp_buff,"blink=BLINK"))
              {
                       http_ippt_get(resp_buff,http_ippt);
                       if(http_ippt[0] !='1')
                       {
                           return HTTP_ERROR;
                       }
                       return HTTP_LED_BLINK;
              }
              else
              {

              }
        }


    }


    return retval;

}

/************************************************************************************
* Name:       http_server_send
* Function:   send http data
* Parameters: http_ippt, data, length
* Return:     none
************************************************************************************/
void http_server_send(uint8_t * http_ippt,uint8_t * data, uint16_t length)
{
    uint16_t length_num;
    uint16_t length_len;
    uint16_t head_len;
    uint16_t data_len;
    char lenth_str[10];
    memset(lenth_str,0, 10);
    length_num = length;

        memset(http_buffer, 0, 2048);
        length_len = length_num;
        sprintf((char *)http_buffer, "\eS0%d,",length_len);
        strcat((char *)http_buffer, (char *)http_ippt);
        head_len = (uint16_t)strlen((char *)http_buffer);
        strcpy((char *)(http_buffer+head_len), (char *)data);
        data_len = (uint16_t)strlen((char *)http_buffer);
        wifi_serial_write(http_buffer, data_len);



}

/************************************************************************************
* Name:       http_ippt_get
* Function:   get ip and port data
* Parameters: buffer, ippt
* Return:     none
************************************************************************************/
static void http_ippt_get(uint8_t * buffer, uint8_t *ippt)
{
    char * p;
    uint8_t ippt_count = 0;

    p = strstr((char *)buffer, "+TRDTS:0,");
    if(0U == p)
    {
        return ;
    }
    p = p + strlen("+TRDTS:0,");
    while(*p != ',')
    {
        *ippt =(uint8_t) *p;
        ippt++;
        p++;
        ippt_count++;
        if(ippt_count >= 30)
        {
            return;
        }
    }
    *ippt =(uint8_t) *p;
    ippt++;
    p++;
    while(*p != ',')
    {
        *ippt =(uint8_t) *p;
        ippt++;
        p++;
    }
    *ippt =(uint8_t) *p;
    ippt++;
    p++;
}

/************************************************************************************
* Name:       http_update
* Function:   update html page
* Parameters: http_ippt
* Return:     none
************************************************************************************/
void  http_update(uint8_t * http_ippt)
{
    uint16_t len;
    memset(user_buffer, 0 , 2048);
    hs3001_read(&g_demo_data.hs3001_data);
    sprintf((char *)user_buffer,(char *)my_get_contents_updated,(uint16_t)g_demo_data.hs3001_data.temprature,(uint16_t)g_demo_data.hs3001_data.humidity,g_demo_data.key_count);

    len = (uint16_t)strlen((char *)user_buffer);
    sprintf((char *)temp_buffer, "HTTP/1.1 200 \r\nContent-Length: %d\r\nContent-Type: text/html\r\n\r\n", len);

    http_server_send(http_ippt,temp_buffer, (uint16_t)strlen((char *)temp_buffer));
    R_BSP_SoftwareDelay(50,BSP_DELAY_UNITS_MILLISECONDS);
    http_server_send(http_ippt,user_buffer, len);
    R_BSP_SoftwareDelay(200,BSP_DELAY_UNITS_MILLISECONDS);
}
