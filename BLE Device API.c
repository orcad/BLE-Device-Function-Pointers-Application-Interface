//
// BLE Device Function Pointers Application Interface
// By: Firas Faham
//

#include <stdio.h>
#include <stdlib.h>

 static inline void send() {
 printf(" Send Data Function \n ");
 // Do other things in here.
}

 static inline void receive() {
 printf(" Receive Data Function \n ");
 // Do other things in here.
}

//
// Struct Prototype of BLE Interface Function Pointer
 typedef struct  iRN487X_FunctionPtrs_t // You may implement more functions
{
    void  (*Write) ();  // BLE sends Data to Mobile Phone
    void  (*Read) () ;  // BLE receives Data from Mobile Phone

} iRN487X_FunctionPtrs_t;


/*****************************************************
*   Driver Instance Declaration(s) API(s)
*   BLE_interface.c
******************************************************/
    iRN487X_FunctionPtrs_t  BLE = {  .Write = send,
                                     .Read = receive
                                  };

// Packet components of BLE device
typedef enum
{
    PROTOCOL_VERSION_ID    = 'V',
    LED_STATE_ID           = 3744,
    BUTTON_STATE_ID        = 'P',
    ERROR_ID               = 0xE3,
    UI_CONFIG_DATA_ID      = 'U'
}PROTOCOL_PACKET_TYPES_t;

char PVID =  PROTOCOL_VERSION_ID;


int main()
{
printf(" Calling with API interface... \n ");

// Write your own code in here
// Use the following API Interface to send and received data.
BLE.Write();
BLE.Read();
printf(" %i, %c, %c, %X", LED_STATE_ID, BUTTON_STATE_ID,  PVID, ERROR_ID );
    return 0;
}

