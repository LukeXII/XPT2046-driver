################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/XPT2046/src/XPT2046.c \
../Drivers/XPT2046/src/port.c 

OBJS += \
./Drivers/XPT2046/src/XPT2046.o \
./Drivers/XPT2046/src/port.o 

C_DEPS += \
./Drivers/XPT2046/src/XPT2046.d \
./Drivers/XPT2046/src/port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/XPT2046/src/%.o Drivers/XPT2046/src/%.su: ../Drivers/XPT2046/src/%.c Drivers/XPT2046/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/CMSIS/Include" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/BSP/STM32F4xx_Nucleo_144" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/Core/Inc" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/API" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/API/src" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/API/inc" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/XPT2046" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/XPT2046/inc" -I"C:/Users/Lucas/Desktop/Repo CESE/XPT2046-driver/Drivers/XPT2046/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-XPT2046-2f-src

clean-Drivers-2f-XPT2046-2f-src:
	-$(RM) ./Drivers/XPT2046/src/XPT2046.d ./Drivers/XPT2046/src/XPT2046.o ./Drivers/XPT2046/src/XPT2046.su ./Drivers/XPT2046/src/port.d ./Drivers/XPT2046/src/port.o ./Drivers/XPT2046/src/port.su

.PHONY: clean-Drivers-2f-XPT2046-2f-src

