################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_r01lib_irq/irq.c 

C_DEPS += \
./_r01lib_irq/irq.d 

OBJS += \
./_r01lib_irq/irq.o 


# Each subdirectory must supply rules for building sources it contributes
_r01lib_irq/%.o: ../_r01lib_irq/%.c _r01lib_irq/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DPRINTF_FLOAT_ENABLE=1 -DSCANF_FLOAT_ENABLE=1 -DPRINTF_ADVANCED_ENABLE=1 -DSCANF_ADVANCED_ENABLE=1 -DCPU_MCXA156VLL -DCPU_MCXA156VLL_cm33 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -DTARGET_A156 -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/GPIO_PCAL9722HN-ARD_4_demo_FRDM_MCXA156" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/GPIO_PCAL9722HN-ARD_4_demo_FRDM_MCXA156/source" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/GPIO_PCAL9722HN-ARD_4_demo_FRDM_MCXA156/_r01lib_irq" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/source" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/source/r01lib" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/source/r01device" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/board" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/component/lists" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/drivers" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/CMSIS" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/device" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/component/serial_manager" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/utilities" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/component/uart" -I"/Users/tedd/dev/mcuxpresso/pca995x_blinker/_r01lib_frdm_mcxa156/startup" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-_r01lib_irq

clean-_r01lib_irq:
	-$(RM) ./_r01lib_irq/irq.d ./_r01lib_irq/irq.o

.PHONY: clean-_r01lib_irq

