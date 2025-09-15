# Led-Animations
Practice Lab 1 of MCP-MCU course

Add only one 7 led segment to the schematic in Exercise3. This component can be found in Proteus by the keyword 7SEG-COM-ANODE. For this device, the common pin should be connected to the power supply and other pins are supposed to connected to PB0 to PB6. Therefore, to turn-on a segment in this 7SEG, the STM32 pin should be in logic 0 (0V).
 
Implement a function named display7SEG(int num). The input for this function is from 0 to 9andtheoutputsarelisted as following:

<img width="550" height="350" alt="Ex4" src="https://github.com/user-attachments/assets/7ab0ecdf-bed3-497b-a82a-6109d8280263" />

