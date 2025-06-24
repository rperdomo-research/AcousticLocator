################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_DEPS += \
./Source/CommonTables/CommonTables.d \
./Source/CommonTables/CommonTablesF16.d \
./Source/CommonTables/arm_common_tables.d \
./Source/CommonTables/arm_common_tables_f16.d \
./Source/CommonTables/arm_const_structs.d \
./Source/CommonTables/arm_const_structs_f16.d \
./Source/CommonTables/arm_mve_tables.d \
./Source/CommonTables/arm_mve_tables_f16.d 

OBJS += \
./Source/CommonTables/CommonTables.o \
./Source/CommonTables/CommonTablesF16.o \
./Source/CommonTables/arm_common_tables.o \
./Source/CommonTables/arm_common_tables_f16.o \
./Source/CommonTables/arm_const_structs.o \
./Source/CommonTables/arm_const_structs_f16.o \
./Source/CommonTables/arm_mve_tables.o \
./Source/CommonTables/arm_mve_tables_f16.o 


# Each subdirectory must supply rules for building sources it contributes
Source/CommonTables/CommonTables.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/CommonTables/CommonTables.c Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Source/CommonTables/CommonTablesF16.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/CommonTables/CommonTablesF16.c Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Source/CommonTables/arm_common_tables.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/CommonTables/arm_common_tables.c Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Source/CommonTables/arm_common_tables_f16.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/CommonTables/arm_common_tables_f16.c Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Source/CommonTables/arm_const_structs.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/CommonTables/arm_const_structs.c Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Source/CommonTables/arm_const_structs_f16.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/CommonTables/arm_const_structs_f16.c Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Source/CommonTables/arm_mve_tables.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/CommonTables/arm_mve_tables.c Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Source/CommonTables/arm_mve_tables_f16.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/CommonTables/arm_mve_tables_f16.c Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Source-2f-CommonTables

clean-Source-2f-CommonTables:
	-$(RM) ./Source/CommonTables/CommonTables.cyclo ./Source/CommonTables/CommonTables.d ./Source/CommonTables/CommonTables.o ./Source/CommonTables/CommonTables.su ./Source/CommonTables/CommonTablesF16.cyclo ./Source/CommonTables/CommonTablesF16.d ./Source/CommonTables/CommonTablesF16.o ./Source/CommonTables/CommonTablesF16.su ./Source/CommonTables/arm_common_tables.cyclo ./Source/CommonTables/arm_common_tables.d ./Source/CommonTables/arm_common_tables.o ./Source/CommonTables/arm_common_tables.su ./Source/CommonTables/arm_common_tables_f16.cyclo ./Source/CommonTables/arm_common_tables_f16.d ./Source/CommonTables/arm_common_tables_f16.o ./Source/CommonTables/arm_common_tables_f16.su ./Source/CommonTables/arm_const_structs.cyclo ./Source/CommonTables/arm_const_structs.d ./Source/CommonTables/arm_const_structs.o ./Source/CommonTables/arm_const_structs.su ./Source/CommonTables/arm_const_structs_f16.cyclo ./Source/CommonTables/arm_const_structs_f16.d ./Source/CommonTables/arm_const_structs_f16.o ./Source/CommonTables/arm_const_structs_f16.su ./Source/CommonTables/arm_mve_tables.cyclo ./Source/CommonTables/arm_mve_tables.d ./Source/CommonTables/arm_mve_tables.o ./Source/CommonTables/arm_mve_tables.su ./Source/CommonTables/arm_mve_tables_f16.cyclo ./Source/CommonTables/arm_mve_tables_f16.d ./Source/CommonTables/arm_mve_tables_f16.o ./Source/CommonTables/arm_mve_tables_f16.su

.PHONY: clean-Source-2f-CommonTables

