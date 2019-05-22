#include <iostream>

using namespace std;

#define NULL 0

/*void CopyString(char pcSource[], char pcDestination[]) {
	
	unsigned char ucLicznikPozycji = NULL;
	
	do
	{
		pcDestination[ucLicznikPozycji] = pcSource[ucLicznikPozycji];
		ucLicznikPozycji ++;	
	} while (pcSource[ucLicznikPozycji] != NULL);
}*/

void CopyString(char pcSource[], char pcDestination[]) {
		
	unsigned char ucLicznikPozycji;
	
	for(ucLicznikPozycji = 0;ucLicznikPozycji != NULL ;ucLicznikPozycji ++){
		pcDestination[ucLicznikPozycji] = pcSource[ucLicznikPozycji];
	}
	pcDestination[ucLicznikPozycji] = pcSource[ucLicznikPozycji];
}

enum CompResult { DIFFERENT , EQUAL };
enum CompResult eCompareString(char pcStr1[], char pcStr2[]) {
	
	unsigned char ucLicznik;
	
	for(ucLicznik = 0;pcStr1[ucLicznik] != NULL; ucLicznik ++){
		if (pcStr1[ucLicznik] != pcStr2[ucLicznik]) return DIFFERENT;
	}		
	if(pcStr1[ucLicznik] == pcStr2[ucLicznik]) return EQUAL;
	else return DIFFERENT;
}
		
void AppendString (char pcSourceStr[],char pcDestinationStr[]){
	
	unsigned char ucMiejsceNull;
	
	for(ucMiejsceNull = 0;pcDestinationStr[ucMiejsceNull] != NULL ;ucMiejsceNull++){}
	CopyString(pcSourceStr, pcDestinationStr + ucMiejsceNull);
}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){
	
	unsigned char ucMiejsce;
	
	for(ucMiejsce = 0 ;pcString[ucMiejsce] != NULL ;ucMiejsce ++){
		if (pcString[ucMiejsce] == cOldChar) 
			pcString[ucMiejsce] = cNewChar;
	}
}
		
int main() {
	char cTabela1[20] = "test1" ;
	char cTabela2[10] = "test2" ;
	char cTabela3[15] = "test1";
	char cTabela4[11] = "tab";
	int z, y, x;
	
	cout << "Numer funkcji (1-4):  ";
	cin >> z;
	if (z == 1){
		cout << "CopyString" << endl << "Przed " << cTabela1<< " & " << cTabela4 << endl;
		CopyString(cTabela1, cTabela4);
		cout << "Po " << cTabela1 << " & " << cTabela4 << endl;
}
	if (z == 2){
		cout << "eCompareString" << endl;
		x = eCompareString(cTabela1, cTabela2);
		y = eCompareString(cTabela1, cTabela3);
		cout << cTabela1 << " z " << cTabela2 << " wynik = " << x << endl << cTabela1 << " z " << cTabela3 << " wynik " << y << endl;
}
	if (z == 3){
		cout << cTabela4 << " " << cTabela2 << endl;
		AppendString(cTabela4, cTabela2);
		cout << "tabela x + y = " << cTabela2 << endl;
}
	if (z == 4){
		cout << "ReplaceCharactersInString" << endl << "zamiana t na x cTabeli1 = " << cTabela1 << endl;
		ReplaceCharactersInString(cTabela1,'t' ,'x');
		cout << "efekt " << cTabela1;
	}
	
	if (z > 4) { cout << "1-Kopiowanie, 2-Porownywanie, 3-Dodawanie, 4-Zmiana znaku"; 
	}
}
