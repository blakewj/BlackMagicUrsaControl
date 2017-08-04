################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LINK_OBJ += \
./libraries/BlackMagicSdiLibrary/BMDSDIControl/BMDSDICameraControl.cpp.o \
./libraries/BlackMagicSdiLibrary/BMDSDIControl/BMDSDIControlShield.cpp.o \
./libraries/BlackMagicSdiLibrary/BMDSDIControl/BMDSDITallyControl.cpp.o 

CPP_DEPS += \
.\libraries\BlackMagicSdiLibrary\BMDSDIControl\BMDSDICameraControl.cpp.d \
.\libraries\BlackMagicSdiLibrary\BMDSDIControl\BMDSDIControlShield.cpp.d \
.\libraries\BlackMagicSdiLibrary\BMDSDIControl\BMDSDITallyControl.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/BlackMagicSdiLibrary/BMDSDIControl/BMDSDICameraControl.cpp.o: E:/GitRepository/BlackMagicUrsaControl/BlackMagicSdiLibrary/BMDSDIControl/BMDSDICameraControl.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\user\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\standard" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\SD\1.1.1" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\SD\1.1.1\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\SPI" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\SPI\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\Wire" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\Wire\src" -I"E:\GitRepository\BlackMagicUrsaControl\BlackMagicSdiLibrary" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/BlackMagicSdiLibrary/BMDSDIControl/BMDSDIControlShield.cpp.o: E:/GitRepository/BlackMagicUrsaControl/BlackMagicSdiLibrary/BMDSDIControl/BMDSDIControlShield.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\user\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\standard" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\SD\1.1.1" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\SD\1.1.1\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\SPI" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\SPI\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\Wire" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\Wire\src" -I"E:\GitRepository\BlackMagicUrsaControl\BlackMagicSdiLibrary" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/BlackMagicSdiLibrary/BMDSDIControl/BMDSDITallyControl.cpp.o: E:/GitRepository/BlackMagicUrsaControl/BlackMagicSdiLibrary/BMDSDIControl/BMDSDITallyControl.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\user\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\standard" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\SD\1.1.1" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\SD\1.1.1\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\SPI" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\SPI\src" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\Wire" -I"C:\Users\user\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\libraries\Wire\src" -I"E:\GitRepository\BlackMagicUrsaControl\BlackMagicSdiLibrary" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


