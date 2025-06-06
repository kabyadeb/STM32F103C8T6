# STM32F103C8T6

To Erase Flash stm32 series in debian(ubuntu) OS we have to istall stlink-tools package.(there are several methods we can use :p )

```
 sudo apt install stlink-tools
```

then we have to run

```
st-flash erase
```

## that's it.

the memory architecture for the ## STM32F103C8T6:

Key Memory Regions (4GB Address Space)
The Cortex-M3 processor has a 4GB (32-bit) address space, which is divided into several main regions, each serving a specific purpose:

Code Region (0x0000 0000 - 0x1FFF FFFF):

This is typically where your program's Flash memory (non-volatile program storage) is mapped.
For the STM32F103C8T6, the internal Flash memory is 64 KB. This is where your compiled firmware code resides.
This region is executable, meaning the CPU fetches instructions from here.
SRAM Region (0x2000 0000 - 0x3FFF FFFF):

This is for SRAM (Static Random Access Memory), which is used for data storage (variables, stack, heap). It's volatile, meaning data is lost when power is removed.
The STM32F103C8T6 has 20 KB of SRAM.
Bit-band region: The lowest 1MB of this SRAM region (0x2000 0000 to 0x200F FFFF) is designated as a bit-band region, allowing for atomic bit-level access via the SRAM alias region.
Peripheral Region (0x4000 0000 - 0x5FFF FFFF):

This is where all the on-chip peripheral registers (GPIOs, Timers, SPI, I2C, UART, ADC, etc.) are mapped.
Accessing these memory addresses directly controls the behavior of the hardware peripherals.
Bit-band region: The lowest 1MB of this peripheral region (0x4000 0000 to 0x400F FFFF) is also a bit-band region, enabling atomic bit manipulation of peripheral registers via the peripheral alias region.
External Device Region (0x6000 0000 - 0x9FFF FFFF):

This region is typically used for connecting external memory or devices (e.g., external SRAM, NOR Flash, parallel LCDs). The STM32F103C8T6 itself doesn't have an external memory controller to directly utilize this, but it's part of the general Cortex-M memory map.
External RAM Region (0xA000 0000 - 0xBFFF FFFF):

Similar to the external device region, for external RAM.
Private Peripheral Bus (PPB) Region (0xE000 0000 - 0xE00F FFFF):

This region is reserved for core-internal peripherals directly related to the Cortex-M3 CPU. This includes:
NVIC (Nested Vectored Interrupt Controller): Manages interrupts.
SysTick Timer: A simple 24-bit timer for operating system ticks or general delays.
System Control Block (SCB): Contains registers for system control, memory protection unit (MPU), debug features, etc.
Debug components: Such as ITM (Instrumentation Trace Macrocell), DWT (Data Watchpoint and Trace), FPB (Flash Patch and Breakpoint unit).
there are dedicated alias regions:

SRAM Alias Region (0x2200 0000 - 0x23FF FFFF): Provides bit-level access to the SRAM bit-band region.
Peripheral Alias Region (0x4200 0000 - 0x43FF FFFF): Provides bit-level access to the Peripheral bit-band region.
Bus Architecture
The Cortex-M3 core uses a `Harvard` architecture internally, meaning it has separate buses for instructions and data. This allows the CPU to fetch instructions and access data simultaneously, improving performance.

Within the STM32F103, there's a multi-bus matrix that connects the ARM Cortex-M3 core, DMA controllers, Flash memory, SRAM, and various peripherals. This intricate bus system allows for efficient data flow and concurrent operations between different modules. For instance, DMA can transfer data between peripherals and memory without CPU intervention.
