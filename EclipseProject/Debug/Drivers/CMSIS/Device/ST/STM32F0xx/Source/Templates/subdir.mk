################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspace/eclipse/MetalDetector/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c 

OBJS += \
./Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.o 

C_DEPS += \
./Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.o: D:/workspace/eclipse/MetalDetector/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F030x8 -DUSE_HAL_DRIVER -I"D:\workspace\eclipse\MetalDetector\Inc" -I"D:\workspace\eclipse\MetalDetector\Drivers\STM32F0xx_HAL_Driver\Inc" -I"D:\workspace\eclipse\MetalDetector\Drivers\CMSIS\Include" -I"D:\workspace\eclipse\MetalDetector\Drivers\CMSIS\Device\ST\STM32F0xx\Include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


