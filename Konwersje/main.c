#define NULL 0
char OutStr[10] = "0xDEF4";
char TooLong[10] = "0xDEFC2";
char NoChar[10] = "0x";
char NoPrefix[10] = "DEF2";
unsigned int InValue;

enum Result { OK, ERROR };

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue)
{
	unsigned char ucLicznikZnak;
	
	if((pcStr[0] != '0') | (pcStr[1] != 'x') | (pcStr[2] == NULL) | (pcStr[6] != NULL)){
		return ERROR;
	}
	*puiValue = 0;
	for(ucLicznikZnak=2;pcStr[ucLicznikZnak] != NULL; ucLicznikZnak++){
	  *puiValue = *puiValue << 4;
		if(pcStr[ucLicznikZnak] >= 'A'){ 
			*puiValue = *puiValue | (pcStr[ucLicznikZnak] - ('A' - 10)); 
		}
		else {
			*puiValue = *puiValue | (pcStr[ucLicznikZnak] - '0');
		}
	}
	return OK;
}

int main() {
	
	enum Result Poprawna = eHexStringToUInt(OutStr, &InValue);
	enum Result ZaDlugi = eHexStringToUInt(TooLong, &InValue);
	enum Result ZaKrotki = eHexStringToUInt(NoChar, &InValue);
	enum Result BrakPrzedrostka = eHexStringToUInt(NoPrefix, &InValue);
 }

