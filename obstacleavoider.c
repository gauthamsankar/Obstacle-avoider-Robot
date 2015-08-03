#include<avr/io.h>


main()
{
	DDRC = 0;				//Declare PortC as Input port
	PORTC = 0b1111111;		//Pull up all the pins of PORTC
	DDRB = 0xFF;			//Declare PortB as output port
	int x;
	while(1)
	{
		x = (PINC & 0b0000011);		//Capture input from both the sensors in to x
		
		if(x == 0b11)				//In case of no obstacle
		
			PORTB = 0b00001010;		//Move forward
			
			
		else if(x == 0b01)			//In case of obstacle on the right
		
			PORTB = 0b00001001;		//Turn left
			
		else if(x == 0b10)			//In case of obstacle onthe left
		
			PORTB = 0b00000110;		//Turn right
			
		else						//Incase of a big obstacle in front
		
		{
			while(x!= 0b11)			//Keep turning right until both sensors are clear
			{
				
				PORTB = 0b00000110;
				x = (PINC & 0b0000011);
			}
		}
	}

}