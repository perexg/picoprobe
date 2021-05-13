Picoprobe with the logic analyzer implementation based on the SUMP protocol
===========================================================================

Supported features:
    
- up to 16 probes (gpio 6-21 by default)
- 200kB RAM for samples
- RLE encoding
- test mode (external pattern)
  * probe 0 and 1 - 10Mhz PWM
  * probe 1 and 2 - 1Mhz PWM
  * probe 3 and 4 - 1kHz PWM
  * probe 8 and 9 - 1kHz PWM (swapped levels)
- test pin (gpio 22) - 5Mhz 50%/50% PWM for probe tests (activated only when sampling)
    
Limits:
    
- 50Mhz sampling rate when compiled with the TURBO_200MHZ define (otherwise 31.25Mhz)
- basic triggers are implemented (functional up to 10Mhz - TODO: PIO support)
    
This protocol is supported in sigrok as openbench-logic-sniffer:
    
```
  pulseview --driver=ols:conn=/dev/ttyACM1
    
  sigrok-cli --driver=ols:conn=/dev/ttyACM1 --config samplerate=50Mhz \
             --config pattern=External --samples 256 --channels 0-1
```

Compile:

```
  mkdir build
  cd build
  TURBO_200MHZ=1 PICO_SDK_PATH=/opt/pico-sdk cmake ..
```

Compile RAM code (debug):

```
  mkdir build
  cd build
  TURBO_200MHZ=1 PICO_SDK_PATH=/opt/pico-sdk cmake -DPICO_NO_FLASH=1 -DCMAKE_BUILD_TYPE=Debug ..
```
    
Misc:
    
- picoprobe reset pin is on gpio 28 (instead 6) now


[Link to protocol](https://www.sump.org/projects/analyzer/protocol) | 
[Link to libsigrok](https://github.com/sigrokproject/libsigrok/tree/master/src/hardware/openbench-logic-sniffer)
