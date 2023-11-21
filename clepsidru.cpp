#include <fstream>
#define MAX_CLEPSIDRE 1000
#define MAX_POZITII 2
using namespace std;
int clepsidra[MAX_CLEPSIDRE][MAX_POZITII];
int main()
{
	ifstream citeste("clepsidru.in");
	int nrClepsidre, nrBoabe, nrStari, nrBoabeSus,
	    nrBoabeJos, nrClepsidraPrimulBob, nrClepsidraUltimulBob,
	    pozitiaPrecedenta;
	citeste >> nrClepsidre >> nrBoabe;
	ofstream scrie("clepsidru.out");
	scrie << nrClepsidre + nrBoabe -1 << '\n'; // rezultatul primului experiment
	nrBoabeSus = nrBoabe, nrBoabeJos = 0;
	nrClepsidraPrimulBob = nrClepsidraUltimulBob = 0;
	pozitiaPrecedenta = 1;
	citeste >> nrStari;
	while (nrStari > 0)
	{
		int nrSecunde, pozitiaCurenta;
		citeste >> nrSecunde >> pozitiaCurenta;
		if (pozitiaCurenta != pozitiaPrecedenta)
		{
			swap(nrBoabeSus, nrBoabeJos);
			if (nrClepsidraPrimulBob == 0
			    && nrClepsidraUltimulBob < nrClepsidre
			    && nrClepsidraUltimulBob > 0)
			{
				nrClepsidraPrimulBob = nrClepsidre - nrClepsidraUltimulBob;
				nrClepsidraUltimulBob = nrClepsidre;
			}
			else if (nrClepsidraPrimulBob > 0
				 && nrClepsidraUltimulBob >= nrClepsidraPrimulBob
				 && nrClepsidraUltimulBob < nrClepsidre)
			{
				nrClepsidraPrimulBob = nrClepsidre - nrClepsidraUltimulBob;
				nrClepsidraUltimulBob = nrClepsidraPrimulBob + 1;
			}
			else if (nrClepsidraPrimulBob > 0
				 && nrClepsidraUltimulBob == nrClepsidre)
			{
				nrClepsidraUltimulBob = nrClepsidre - nrClepsidraPrimulBob;
				nrClepsidraPrimulBob = 0;
			}
		}
		while (nrSecunde > 0)
		{
			if (nrClepsidraUltimulBob > 0
			    && nrClepsidraUltimulBob < nrClepsidre)
				nrClepsidraUltimulBob++;
			if (nrClepsidraUltimulBob == nrClepsidre)
				nrBoabeJos++;
			if (nrClepsidraPrimulBob > 0
			    && nrClepsidraPrimulBob < nrClepsidre)
				nrClepsidraPrimulBob++;
			if (nrClepsidraPrimulBob == nrClepsidre)
				nrClepsidraPrimulBob = nrClepsidraUltimulBob = 0;
			if (nrBoabeSus > 0)
			{
				nrBoabeSus--;
				if (nrBoabeSus == 0)
					nrClepsidraPrimulBob = 1;
				if (nrClepsidraUltimulBob == 0)
					nrClepsidraUltimulBob = 1;
			}
			nrSecunde--;
		}
		pozitiaPrecedenta = pozitiaCurenta;
		nrStari--;
	}
	citeste.close();
	int i;
	for (i = nrClepsidraPrimulBob; i <= nrClepsidraUltimulBob; i++)
		if (pozitiaPrecedenta == 1)
			clepsidra[i][0] = 1;
		else
			clepsidra[nrClepsidre-i-1][1] = 1;
	if (pozitiaPrecedenta == 1)
	{
		clepsidra[0][0] = nrBoabeSus;
		clepsidra[nrClepsidre-1][1] = nrBoabeJos;
	}
	else
	{
		clepsidra[0][0] = nrBoabeJos;
		clepsidra[nrClepsidre-1][1] = nrBoabeSus;
	}
	for (i = 0; i < nrClepsidre; i++)
		scrie << clepsidra[i][0] << ' ' << clepsidra[i][1] << '\n';
	scrie.close();
	return 0;
}
