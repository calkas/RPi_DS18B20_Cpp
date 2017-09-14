#ifndef TEMPSENSORDS18B20_R_H
#define TEMPSENSORDS18B20_R_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class TempSensorDS18B20_R
{
	public:
		TempSensorDS18B20_R(string senName);
		~TempSensorDS18B20_R();
		string GetSensorName() const;
		void SetSensorName(string senName);
		void ReadData();
		int GetRawSensorValue() const;
		float GetTemperature();
		void Presentation();
		
	private:
		string m_SensorPath;
		string m_SensorName;
		int m_RawSensorValue;
		float m_TempSensorValue;
		ifstream m_Sensorfile;
		
		static const string BUS_PATH; 
		static const string TEMPFILE; 
};

#endif
