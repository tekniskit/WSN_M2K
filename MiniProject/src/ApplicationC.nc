#include <UserButton.h>
#include <Timer.h>
#include "Application.h"
 
module ApplicationC {
	uses interface Boot;
	uses interface Leds;
	uses interface Packet;
	uses interface AMPacket;
	uses interface AMSend;
	uses interface SplitControl as AMControl;
	uses interface Receive;
	uses interface Get<button_state_t>;
	uses interface Notify<button_state_t>;
	uses interface Timer<TMilli> as Timer0;
	
}
implementation {
	bool busy = FALSE;
	message_t pkt;
	uint16_t counter = 0;
 
	event void Boot.booted() {
		call AMControl.start();
		call Notify.enable();		
	}
	
	event void Notify.notify(button_state_t state){
		if(state == BUTTON_PRESSED){
			call Timer0.startPeriodic( 1 );
			call Leds.led0On();
		}		
	}
	
 
	event void AMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			// Something
		}
		else {
			call AMControl.start();
		}
	}

	event void AMControl.stopDone(error_t err) {
	}
 
	
	event void AMSend.sendDone(message_t* msg, error_t error) {
		if (&pkt == msg) {
			busy = FALSE;
		}
	}
	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		call Leds.led2Toggle();
		if (len == sizeof(ApplicationMsg)) {
			ApplicationMsg* message = (ApplicationMsg*)payload;
//			if(message->nodeid == 1){
//				call Leds.led1Toggle();
//			}
//			else if (message->nodeid == 2){
//				call Leds.led2Toggle();
//			}
			call Leds.led1Toggle();
		}
		return msg;
	}
	
	event void Timer0.fired()
  {
    
    		if(counter < 5000){
    			if (!busy) {
					ApplicationMsg* msg = (ApplicationMsg*)(call Packet.getPayload(&pkt, sizeof (ApplicationMsg)));
					msg->nodeid = TOS_NODE_ID;
					msg->size = sizeof(ApplicationMsg);
					msg->test = 23;
				}			
				if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof(ApplicationMsg)) == SUCCESS) {
					busy = TRUE;
					counter++;
				}
    		}
    		else{
    			call Timer0.stop();
    			call Leds.led0Off();
    		}
    		
			
  }
	
	
 
}