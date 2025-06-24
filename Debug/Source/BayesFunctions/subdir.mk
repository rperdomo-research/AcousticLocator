################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_DEPS += \
./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.d \
./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.d 

OBJS += \
./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.o \
./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.o 


# Each subdirectory must supply rules for building sources it contributes
Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.c Source/BayesFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.o: C:/Users/Richard/Desktop/Embedded\ Project/Final\ Project/Drivers/CMSIS/CMSIS_DSP/Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.c Source/BayesFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H7xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/PrivateInclude" -I"C:/Users/Richard/Desktop/Embedded Project/Final Project/Drivers/CMSIS/CMSIS_DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Source-2f-BayesFunctions

clean-Source-2f-BayesFunctions:
	-$(RM) ./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.cyclo ./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.d ./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.o ./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.su ./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.cyclo ./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.d ./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.o ./Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.su

.PHONY: clean-Source-2f-BayesFunctions

