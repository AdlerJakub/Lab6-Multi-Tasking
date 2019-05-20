#pragma once
#include <cstdint>
#include <Windows.h>
#include <vector>

using namespace std;

class CProducent
{
private:
	vector<double> data;
	bool threadIsRunning;
	HANDLE dataMutex;
	HANDLE thread;
	static DWORD CALLBACK ThreadMain(void *CProducentPtr);
public:
	CProducent(); //tworzy w�tek
	~CProducent(); //zamyka w�tek
	void CProducent::StopThread(); // zamyka watek v2
	void GetDataCopy(vector<double> &data); //zwraca synchronicznie skopiowan� kolekcj�
};

