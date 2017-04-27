################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/x64_256mc_inv_n-swinexp.c 

S_UPPER_SRCS += \
../src/x64_256mc_add_n.S \
../src/x64_256mc_mul_2-addc.S \
../src/x64_256mc_mul_n.S \
../src/x64_256mc_sqr_n.S \
../src/x64_256mc_sub_n.S 

OBJS += \
./src/x64_256mc_add_n.o \
./src/x64_256mc_inv_n-swinexp.o \
./src/x64_256mc_mul_2-addc.o \
./src/x64_256mc_mul_n.o \
./src/x64_256mc_sqr_n.o \
./src/x64_256mc_sub_n.o 

C_DEPS += \
./src/x64_256mc_inv_n-swinexp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


