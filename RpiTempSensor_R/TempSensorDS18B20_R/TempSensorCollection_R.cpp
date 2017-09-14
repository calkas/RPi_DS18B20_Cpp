#include "TempSensorCollection_R.h"


TempSensorCollection_R::TempSensorCollection_R()
{
	m_NumberOfSensors = 0;
}

TempSensorCollection_R::~TempSensorCollection_R()
{
	//cout<<"\n -> PROGRAM END's\n";
}

void TempSensorCollection_R::AddSensor(TempSensorDS18B20_R *pTempSensor)
{
	if(pTempSensor != NULL)
	{
		TempSensorVector.push_back(pTempSensor);
		++m_NumberOfSensors;		
	}

}

void TempSensorCollection_R::GetTemperatureFromSensors()
{
	cout<<"------------------ TEMPERATURE ------------------\n";
	for(It_tempSensorVector = TempSensorVector.begin(); It_tempSensorVector != TempSensorVector.end(); ++It_tempSensorVector)
	{
		(*It_tempSensorVector)->ReadData();
		(*It_tempSensorVector)->Presentation();
	}
	
	cout<<"-------------------------------------------------\n";
	
}

int TempSensorCollection_R::GetNumberOfSensors() const
{
	return m_NumberOfSensors;
}
