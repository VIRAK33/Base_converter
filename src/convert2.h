#ifndef HEADER.H
#define HEADER.H

int str2int(char *str)
{
  int result;
  int puiss;

  result = 0;
  puiss = 1;
  while (('-' == (*str)) || ((*str) == '+'))
  {
      if (*str == '-')
        puiss = puiss * -1;
      str++;
  }
  while ((*str >= '0') && (*str <= '9'))
  {
      result = (result * 10) + ((*str) - '0');
      str++;
  }
  return (result * puiss);
}

char* decToBinary(int n)
{
	char *bin = calloc(5, sizeof(char));
	//char bin[32];
	char str[32];
	int binaryNum[32];
	//char bin[32];
	char num[10];
	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	int j;
	for(j=i-1; j>=0; j--){ 
		sprintf(str, "%d", binaryNum[j]);
		strcat(bin,str);
	}
	return bin;
		
}
char* decToOcta(int quotient){
	char *bin = calloc(5, sizeof(char));
	char str[32];
	long decimalnum, remainder;
    	int octalNumber[100], i = 1, j;
	while (quotient != 0)
	{
        	octalNumber[i++] = quotient % 8;
        	quotient = quotient / 8;
	}
	for (j = i - 1; j > 0; j--){
	//printf("%d", octalNumber[j]);
		sprintf(str, "%d", octalNumber[j]);
		strcat(bin,str);
	}
	return bin;
}

char* decToHexa(int n) 
{   
	char *bin = calloc(5, sizeof(char));
	char str[32];
	char hexaDeciNum[100]; 
    int i = 0; 
    while(n!=0) 
    {    
        int temp  = 0; 
        temp = n % 16; 
        if(temp < 10) 
        { 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = temp + 55; 
            i++; 
        } 
        n = n/16; 
    }
    int j;
    for(j=i-1; j>=0; j--){
    	//printf("%c",hexaDeciNum[j]); 
    	sprintf(str, "%c", hexaDeciNum[j]);
	strcat(bin,str);
	}
	return bin;
}
char* binaryToDec(int value)
{
	int re =0;
	int dec = 0;
	int b = 1;
	char* str;
	while(value>0)
		{
			re = (value%10);
			dec += re * b;
			b *= 2;
			value/=10;
		}
	//printf("%d", dec);
	//snprintf(str, "%d", dec);
	asprintf (&str, "%i", dec);
	//itoa(dec, str, 10);
	return str;
}
char* binaryToOctal(int binarynum){
	long int octalnum = 0, j = 1, remainder;
	char* str;
    while (binarynum != 0)
    {
        remainder = binarynum % 10;
        octalnum = octalnum + remainder * j;
        j = j * 2;
        binarynum = binarynum / 10;
    }
    //printf("%lo", octalnum);
	asprintf (&str, "%lo", octalnum);
	return str;
	
}
char* binaryToHex(binaryval){
	long int hexadecimalval = 0, i = 1, remainder;
	char* str;
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    //printf("%lX", hexadecimalval);
	asprintf (&str, "%lx", hexadecimalval);
	return str;
}


char* octalToBinary(int value)
{
	int re =0;
	int dec = 0;
	int b = 1;
	//base8 to dec
	while(value>0)
		{
			re = (value%10);
			dec += re * b;
			b *= 8;
			value/=10;
		}
	//base10 to binary
	re = 0;
	decToBinary(dec);
}

char* octalToDec(int value)
{
	int re =0;
	int dec = 0;
	int b = 1;
	char* str;
	//base8 to dec
	while(value>0)
		{
			re = (value%10);
			dec += re * b;
			b *= 8;
			value/=10;
		}
	//printf("%d", dec);
	asprintf(&str, "%d", dec);
	return str;
}

char* octalToHex(int value)
{
	int re =0;
	int dec = 0;
	int b = 1;
	char* str;
	//base8 to dec
	while(value>0)
		{
			re = (value%10);
			dec += re * b;
			b *= 8;
			value/=10;
		}
	decToHexa(dec);
	
}

// C++ program to convert hexadecimal to decimal 


// Function to convert hexadecimal to decimal 
char* hexadecimalToDecimal(char hexVal[]) 
{ 
	int len = strlen(hexVal); 
	char* str;
	// Initializing base value to 1, i.e 16^0 
	int base = 1; 
	
	int dec_val = 0; 
	int i;
	// Extracting characters as digits from last character 
	for (i=len-1; i>=0; i--) 
	{ 
		// if character lies in '0'-'9', converting 
		// it to integral 0-9 by subtracting 48 from 
		// ASCII value. 
		if (hexVal[i]>='0' && hexVal[i]<='9') 
		{ 
			dec_val += (hexVal[i] - 48)*base; 
				
			// incrementing base by power 
			base = base * 16; 
		} 

		// if character lies in 'A'-'F' , converting 
		// it to integral 10 - 15 by subtracting 55 
		// from ASCII value 
		else if (hexVal[i]>='A' && hexVal[i]<='F') 
		{ 
			dec_val += (hexVal[i] - 55)*base; 
		
			// incrementing base by power 
			base = base*16; 
		} 
	} 
	
	//return dec_val; 
	asprintf(&str,"%d",dec_val);
	return str;
} 
char* hexadecimalToBinary(char hexVal[]) 
{ 
	int len = strlen(hexVal); 
	char* str;
	// Initializing base value to 1, i.e 16^0 
	int base = 1; 
	
	int dec_val = 0; 
	int i;
	// Extracting characters as digits from last character 
	for (i=len-1; i>=0; i--) 
	{ 
		// if character lies in '0'-'9', converting 
		// it to integral 0-9 by subtracting 48 from 
		// ASCII value. 
		if (hexVal[i]>='0' && hexVal[i]<='9') 
		{ 
			dec_val += (hexVal[i] - 48)*base; 
				
			// incrementing base by power 
			base = base * 16; 
		} 

		// if character lies in 'A'-'F' , converting 
		// it to integral 10 - 15 by subtracting 55 
		// from ASCII value 
		else if (hexVal[i]>='A' && hexVal[i]<='F') 
		{ 
			dec_val += (hexVal[i] - 55)*base; 
		
			// incrementing base by power 
			base = base*16; 
		} 
	} 
	
	//return dec_val; 
	decToBinary(dec_val);
} 
char* hexadecimalToOcta(char hexVal[]) 
{ 
	int len = strlen(hexVal); 
	char* str;
	// Initializing base value to 1, i.e 16^0 
	int base = 1; 
	
	int dec_val = 0; 
	int i;
	// Extracting characters as digits from last character 
	for (i=len-1; i>=0; i--) 
	{ 
		// if character lies in '0'-'9', converting 
		// it to integral 0-9 by subtracting 48 from 
		// ASCII value. 
		if (hexVal[i]>='0' && hexVal[i]<='9') 
		{ 
			dec_val += (hexVal[i] - 48)*base; 
				
			// incrementing base by power 
			base = base * 16; 
		} 

		// if character lies in 'A'-'F' , converting 
		// it to integral 10 - 15 by subtracting 55 
		// from ASCII value 
		else if (hexVal[i]>='A' && hexVal[i]<='F') 
		{ 
			dec_val += (hexVal[i] - 55)*base; 
		
			// incrementing base by power 
			base = base*16; 
		} 
	} 
	
	//return dec_val; 
	decToOcta(dec_val);
} 






#endif
