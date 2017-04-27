################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../test/x64_256mc_add_n_test.c \
../test/x64_256mc_inv_n_speed.c \
../test/x64_256mc_inv_n_test.c \
../test/x64_256mc_mul_2_test.c \
../test/x64_256mc_mul_n_speed.c \
../test/x64_256mc_mul_n_test.c \
../test/x64_256mc_sqr_n_test.c \
../test/x64_256mc_sub_n_test.c 

OBJS += \
./test/x64_256mc_add_n_test.o \
./test/x64_256mc_inv_n_speed.o \
./test/x64_256mc_inv_n_test.o \
./test/x64_256mc_mul_2_test.o \
./test/x64_256mc_mul_n_speed.o \
./test/x64_256mc_mul_n_test.o \
./test/x64_256mc_sqr_n_test.o \
./test/x64_256mc_sub_n_test.o 

C_DEPS += \
./test/x64_256mc_add_n_test.d \
./test/x64_256mc_inv_n_speed.d \
./test/x64_256mc_inv_n_test.d \
./test/x64_256mc_mul_2_test.d \
./test/x64_256mc_mul_n_speed.d \
./test/x64_256mc_mul_n_test.d \
./test/x64_256mc_sqr_n_test.d \
./test/x64_256mc_sub_n_test.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


