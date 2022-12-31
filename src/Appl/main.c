


#include "../Mcal/Port/Incl/Port.h"

extern const Port_ConfigType STR_PortsConfig[PORT_PINS_NUM];


int main(void){
	Port_Init(STR_PortsConfig);
	
}

