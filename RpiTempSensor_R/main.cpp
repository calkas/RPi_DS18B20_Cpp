#include <iostream>
#include "TempSensorDS18B20_R/TempSensorDS18B20_R.h"
#include "TempSensorDS18B20_R/TempSensorCollection_R.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	TempSensorDS18B20_R tempSensor("28-000005cafed4");
	TempSensorDS18B20_R tempSensor_2("28-0000062a8425");
	
	TempSensorCollection_R *pTempSensorObj = new TempSensorCollection_R();
	pTempSensorObj->AddSensor(&tempSensor);
	pTempSensorObj->AddSensor(&tempSensor_2);
	pTempSensorObj->GetTemperatureFromSensors();
	
	delete pTempSensorObj;

	return 0;
}
