#include "FreeRTOS.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "clock_config.h"
#include "board.h"

#include "Motor_Control_Component.h"
#include "RC_Receiver_Component.h"
#include "Terminal_Component.h"
#include "LED_Component.h"
#include "Accelerometer_Component.h"


int main(void)
{
    /* Init board hardware. */
	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    //
    setupMotorComponent();
    setupRCReceiverComponent();
//    setupTerminalComponent();
    setupLEDComponent();
//    setupAccelerometerComponent();

    xTaskCreate(rcTask, "producer", 200, NULL, 2, NULL);


    vTaskStartScheduler();

    while(1)
    {}
}

