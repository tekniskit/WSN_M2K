#include "Application.h"
 
 configuration ApplicationAppC {
 }
 implementation {
   components MainC;
   components LedsC;
   components ApplicationC as App;
   components ActiveMessageC;
   components new AMSenderC(AM_APPLICATION);
   components new AMReceiverC(AM_APPLICATION);
   components UserButtonC;
   components new TimerMilliC() as Timer0;
  
   App.Boot -> MainC;
   App.Leds -> LedsC;
   App.Packet -> AMSenderC;
   App.AMPacket -> AMSenderC;
   App.AMSend -> AMSenderC;
   App.AMControl -> ActiveMessageC;
   App.Receive -> AMReceiverC;
   App.Get -> UserButtonC;
   App.Notify -> UserButtonC;
   App.Timer0 -> Timer0;
 }