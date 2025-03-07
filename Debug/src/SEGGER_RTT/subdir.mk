################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SEGGER_RTT/SEGGER_RTT.c \
../src/SEGGER_RTT/SEGGER_RTT_printf.c 

C_DEPS += \
./src/SEGGER_RTT/SEGGER_RTT.d \
./src/SEGGER_RTT/SEGGER_RTT_printf.d 

OBJS += \
./src/SEGGER_RTT/SEGGER_RTT.o \
./src/SEGGER_RTT/SEGGER_RTT_printf.o 

SREC += \
Renesas_RA2A2_Demo.srec 

MAP += \
Renesas_RA2A2_Demo.map 


# Each subdirectory must supply rules for building sources it contributes
src/SEGGER_RTT/%.o: ../src/SEGGER_RTT/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -DARM_DSP_ATTRIBUTE=__WEAK -D_RA_CORE=CM23 -D_RA_ORDINAL=1 -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/src" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra/fsp/inc" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra/fsp/inc/api" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra/fsp/inc/instances" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra_gen" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra_cfg/fsp_cfg/bsp" -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra_cfg/fsp_cfg" -I"." -I"D:/Downloads/Renesas_Wifi_DA16200_RA6M4_Cloud_IoT_Solution/Renesas_Wifi_DA16200_RA6M4_Demo/ra/arm/CMSIS_6/CMSIS/Core/Include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

