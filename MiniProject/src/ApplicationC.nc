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

	
	event void Timer0.fired()
  {
    
    		if(counter < 5000){
    			if (!busy) {
					ApplicationMsg112* msg = (ApplicationMsg112*)(call Packet.getPayload(&pkt, sizeof (ApplicationMsg112)));
					msg->nodeid = TOS_NODE_ID;
				}			
				if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof(ApplicationMsg112)) == SUCCESS) {
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