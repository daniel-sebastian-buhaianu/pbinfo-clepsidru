#include <fstream>
#define MAX_CLEPSIDRE 1000
#define MAX_POZITII 2
using namespace std;
int clepsidra[MAX_CLEPSIDRE][MAX_POZITII];
int main()
{
	ifstream citeste("clepsidru.in");
	int nrClepsidre, nrBoabe, nrStari;
	citeste >> nrClepsidre >> nrBoabe;
	ofstream scrie("clepsidru.out");
	scrie << nrClepsidre + nrBoabe -1 << '\n'; // rezultatul primului experiment
	clepsidra[0][0] = nrBoabe;
	int pozitiaInitiala = 1;
	citeste >> nrStari;
	while (nrStari > 0)
	{
		int nrSecunde, pozitie, i, j;
		citeste >> nrSecunde >> pozitie;
		if (pozitie != pozitiaInitiala)
		{
			// rastorn clepsidrele
			if (pozitiaInitiala == 1)
			{
				for (i = 0; i < nrClepsidre-1; i++)
				{
					clepsidra[i][1] += clepsidra[i+1][0];
					clepsidra[i+1][0] = 0;
				}
			}
			else
			{
				for (i = nrClepsidre-1; i > 0; i--)
				{
					clepsidra[i][0] += clepsidra[i-1][1];
					clepsidra[i-1][1] = 0;
				}
			}
		}
		for (i = 0; i < nrSecunde; i++)
		{
			// simulez trecerea timpului in clepsidru
			// in functie de pozitie
			if (pozitie == 1)
			{
				for (j = nrClepsidre-1; j >= 0; j--)
					if (clepsidra[j][0])
					{
						clepsidra[j][0]--;
						if (j == nrClepsidre-1)
							clepsidra[j][1]++;
						else
							clepsidra[j+1][0]++;
					}
			}
			else
			{
				for (j = 0; j < nrClepsidre; j++)
					if (clepsidra[j][1])
					{
						clepsidra[j][1]--;
						if (j == 0)
							clepsidra[j][0]++;
						else
							clepsidra[j-1][1]++;
					}
			}
		}
		pozitiaInitiala = pozitie;
		nrStari--;
	}
	citeste.close();
	for (int i = 0; i < nrClepsidre; i++)
		scrie << clepsidra[i][0] << ' ' << clepsidra[i][1] << '\n';
	scrie.close();
	return 0;
}
