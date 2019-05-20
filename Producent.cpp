#include "Producent.h"


CProducent::CProducent()
{

	threadIsRunning = true;

	dataMutex = CreateMutex(NULL, false, NULL);

	thread = CreateThread(NULL, 0, ThreadMain, (LPVOID)this, 0, 0);
	SetThreadPriority(thread, THREAD_PRIORITY_NORMAL);
}

CProducent::~CProducent()
{
	threadIsRunning = false;
	WaitForSingleObject(thread, INFINITE);

	CloseHandle(thread);
	CloseHandle(dataMutex);

}

void CProducent::StopThread()
{
	threadIsRunning = false;
}

void CProducent::GetDataCopy(vector<double> &data)
{
	WaitForSingleObject(dataMutex, INFINITE);
	data = this->data;
	ReleaseMutex(dataMutex);
	}

DWORD CALLBACK CProducent::ThreadMain(void *CProducentPtr)
{
	CProducent *_this = (CProducent *)CProducentPtr;
	CProducent &ja = *_this;

	while (ja.threadIsRunning)
	{
		WaitForSingleObject(ja.dataMutex, INFINITE);
		ja.data.push_back(rand() % 1000);
		ReleaseMutex(ja.dataMutex);
	}
		
	return 0;
}