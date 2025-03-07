################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/da16200_AT.c \
../src/dialog_wifi_demo.c \
../src/hal_entry.c \
../src/hs3001.c \
../src/http_server.c 

C_DEPS += \
./src/da16200_AT.d \
./src/dialog_wifi_demo.d \
./src/hal_entry.d \
./src/hs3001.d \
./src/http_server.d 

OBJS += \
./src/da16200_AT.o \
./src/dialog_wifi_demo.o \
./src/hal_entry.o \
./src/hs3001.o \
./src/http_server.o 

SREC += \
Renesas_RA2A2_Demo.srec 

MAP += \
Renesas_RA2A2_Demo.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -DARM_DSP_ATTRIBUTE=__WEAK -D_RA_CORE=CM23 -D_RA_ORDINAL=1 -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/src" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra/fsp/inc" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra/fsp/inc/api" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra/fsp/inc/instances" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra_gen" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra_cfg/fsp_cfg/bsp" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra_cfg/fsp_cfg" -I"." -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra/arm/CMSIS_6/CMSIS/Core/Include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

