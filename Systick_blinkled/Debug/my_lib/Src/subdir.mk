################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../my_lib/Src/led_struct.c 

OBJS += \
./my_lib/Src/led_struct.o 

C_DEPS += \
./my_lib/Src/led_struct.d 


# Each subdirectory must supply rules for building sources it contributes
my_lib/Src/%.o my_lib/Src/%.su: ../my_lib/Src/%.c my_lib/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L496xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/home/thedao1999/STM32CubeIDE/workspace_1.11.0/Systick_blinkled/my_lib/Inc" -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-my_lib-2f-Src

clean-my_lib-2f-Src:
	-$(RM) ./my_lib/Src/led_struct.d ./my_lib/Src/led_struct.o ./my_lib/Src/led_struct.su

.PHONY: clean-my_lib-2f-Src

