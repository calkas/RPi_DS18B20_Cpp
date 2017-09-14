#include "TempSensorDS18B20_R.h"
#include <cstdlib>


const string TempSensorDS18B20_R::BUS_PATH = "/sys/bus/w1/devices/";
const string TempSensorDS18B20_R::TEMPFILE = "/w1_slave";

TempSensorDS18B20_R::TempSensorDS18B20_R(string senName)
{
	/* ----------- SENSOR DATA ----------- */
	m_SensorName      = senName;
	m_RawSensorValue  = 0;
	m_TempSensorValue = 0.0;
	m_SensorPath      = BUS_PATH + m_SensorName + TEMPFILE;
}

TempSensorDS18B20_R::~TempSensorDS18B20_R()
{
}

string TempSensorDS18B20_R::GetSensorName() const
{
	return m_SensorName;
}


void TempSensorDS18B20_R::SetSensorName(string senName)
{
	m_SensorName = senName;
}

void TempSensorDS18B20_R::ReadData()
{
	string tempString;
	string dataValue;
	size_t pos;
		
	m_Sensorfile.open(m_SensorPath.c_str());
	if(m_Sensorfile.is_open())
	{

		getline(m_Sensorfile,tempString);
		getline(m_Sensorfile,tempString);
		
		pos = tempString.find("t=");
		pos = pos + 2;
		
		dataValue = tempString.substr(pos);
		m_RawSensorValue = atoi(dataValue.c_str());

		m_Sensorfile.close();
	}
	else
	{
		cout<<"Error Cannot open the sensor data file !"<<endl;
	}
	
}

int TempSensorDS18B20_R::GetRawSensorValue() const
{
	return m_RawSensorValue;
}

float TempSensorDS18B20_R::GetTemperature()
{
	float temp;
	temp = static_cast<float>(m_RawSensorValue) / 1000.0;
	return temp;
}

void TempSensorDS18B20_R::Presentation()
{
	cout<<"SEN["<<m_SensorName<<"] = "<<GetTemperature()<<"[C]"<<endl;
}

