#include <iostream>
#include "Producent.h"
#include <cstdint>
#include <Windows.h>
#include <conio.h>
using namespace std;


int main()
{

	CProducent producencik;

	char klawisz = 0;

	vector<double> dane;

	while (klawisz != 27)
	{
		double sum=0.0;

		producencik.GetDataCopy(dane);

		for (int i = 0; i < dane.size(); i++)
		{
		sum += dane[i];
		}
		
		if (klawisz == 13)
		{
			if (dane.size() != 0)
			{
				cout << "Elementy:" << dane.size() << "Srednia:" << sum / dane.size() << endl;
			}
		}
		klawisz = _getch();
	}
	producencik.StopThread();
	return 0;
}