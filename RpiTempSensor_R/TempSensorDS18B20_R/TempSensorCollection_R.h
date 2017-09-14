#ifndef TEMPSENSORCOLLECTION_R_H
#define TEMPSENSORCOLLECTION_R_H

#include <iostream>
#include <vector>
#include "TempSensorDS18B20_R.h"


using namespace std;

class TempSensorCollection_R
{
	public:
		TempSensorCollection_R();
		~TempSensorCollection_R();
		void AddSensor(TempSensorDS18B20_R *pTempSensor);
		void GetTemperatureFromSensors();
		int GetNumberOfSensors() const;
	private:
		int m_NumberOfSensors;
		vector <TempSensorDS18B20_R *> TempSensorVector;
		vector <TempSensorDS18B20_R *>::iterator It_tempSensorVector;
};

#endif
