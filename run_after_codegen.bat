@echo off
del Drivers\CMSIS\Include\core_cm0plus.h
del Drivers\CMSIS\Include\core_cm3.h
del Drivers\CMSIS\Include\core_cm4.h
del Drivers\CMSIS\Include\core_cm7.h
del Drivers\CMSIS\Include\core_sc000.h
del Drivers\CMSIS\Include\core_sc300.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f030x6.h
rem del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f030x8.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f030xc.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f031x6.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f038xx.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f042x6.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f048xx.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f051x8.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f058xx.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f070x6.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f070xb.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f071xb.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f072xb.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f078xx.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f091xc.h
del Drivers\CMSIS\Device\ST\STM32F0xx\Include\stm32f098xx.h
del .cproject
del .project
del MetalDetector.xml
ren Drivers\CMSIS\Device\ST\STM32F0xx\Source\Templates\gcc\startup_stm32f030x8.s startup_stm32f030x8.S
move STM32F030C8Tx_FLASH.ld Src
ren EclipseProject\.project.bak .project
ren EclipseProject\.cproject.bak .cproject
echo DONE
echo.
echo [PRESS ANY KEY TO EXIT]
pause >nul
