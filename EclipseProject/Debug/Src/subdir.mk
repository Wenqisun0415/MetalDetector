################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspace/eclipse/MetalDetector/Src/main.c \
D:/workspace/eclipse/MetalDetector/Src/stm32f0xx_hal_msp.c \
D:/workspace/eclipse/MetalDetector/Src/stm32f0xx_it.c 

OBJS += \
./Src/main.o \
./Src/stm32f0xx_hal_msp.o \
./Src/stm32f0xx_it.o 

C_DEPS += \
./Src/main.d \
./Src/stm32f0xx_hal_msp.d \
./Src/stm32f0xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: D:/workspace/eclipse/MetalDetector/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F030x8 -DUSE_HAL_DRIVER -I"D:\workspace\eclipse\MetalDetector\Inc" -I"D:\workspace\eclipse\MetalDetector\Drivers\STM32F0xx_HAL_Driver\Inc" -I"D:\workspace\eclipse\MetalDetector\Drivers\CMSIS\Include" -I"D:\workspace\eclipse\MetalDetector\Drivers\CMSIS\Device\ST\STM32F0xx\Include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/stm32f0xx_hal_msp.o: D:/workspace/eclipse/MetalDetector/Src/stm32f0xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F030x8 -DUSE_HAL_DRIVER -I"D:\workspace\eclipse\MetalDetector\Inc" -I"D:\workspace\eclipse\MetalDetector\Drivers\STM32F0xx_HAL_Driver\Inc" -I"D:\workspace\eclipse\MetalDetector\Drivers\CMSIS\Include" -I"D:\workspace\eclipse\MetalDetector\Drivers\CMSIS\Device\ST\STM32F0xx\Include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/stm32f0xx_it.o: D:/workspace/eclipse/MetalDetector/Src/stm32f0xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F030x8 -DUSE_HAL_DRIVER -I"D:\workspace\eclipse\MetalDetector\Inc" -I"D:\workspace\eclipse\MetalDetector\Drivers\STM32F0xx_HAL_Driver\Inc" -I"D:\workspace\eclipse\MetalDetector\Drivers\CMSIS\Include" -I"D:\workspace\eclipse\MetalDetector\Drivers\CMSIS\Device\ST\STM32F0xx\Include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


