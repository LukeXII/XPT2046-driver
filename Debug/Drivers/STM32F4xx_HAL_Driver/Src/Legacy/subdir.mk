################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Src/Legacy/%.o Drivers/STM32F4xx_HAL_Driver/Src/Legacy/%.su: ../Drivers/STM32F4xx_HAL_Driver/Src/Legacy/%.c Drivers/STM32F4xx_HAL_Driver/Src/Legacy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/CMSIS/Include" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/BSP/STM32F4xx_Nucleo_144" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/Core/Inc" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/API" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/API/src" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/API/inc" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/XPT2046" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/XPT2046/inc" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/XPT2046/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy

clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy:
	-$(RM) ./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d ./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o ./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.su

.PHONY: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy

