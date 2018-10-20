#include <iostream>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

typedef struct IndicePrimario {
	
	string chavePrim;
	int ende;
	
} IndPrim;


/*Lê o arquivo de dados e gera em memóriga um vetor de indices*/
bool LerSeqArq(vector <IndPrim> *registro, ifstream *inFile)
{
	
/* Variáveis auxiliares e de contagem */
	int i,j=0;
	char vetChar[30];
	char charAux;
	IndPrim registroAux;   // Os campos de cada registro do vetor não podem ser diretamente inseridos usando push_back
	
	if (!inFile) 
	{  
		cout<<"Arquivo não pode ser aberto"<<endl;
		return(false);
	} 
	
	while(!inFile->eof())
	{
		for(i=0;i<31;i++)                // le os 30 char que vão estar no primeiro campo de um registro do indice
		{
			 inFile->seekg(j);
			 if (i!=6)                   // No arq de dados, a MAT tem 6 char, para concatenar MAT e NOME, devemos pular o  'Espaço'
			 {
				 inFile->get(charAux); 
				if(i<6)
					vetChar[i] = charAux;
				else
					vetChar[i-1] = charAux;
		     }
		     j++;
		 }
		 registroAux.chavePrim = vetChar;
		 registroAux.ende = j; 
		 registro->push_back(registroAux);
		 j = j + 33;                        // endereço do começo do novo registro = endereço da nova linha             
		 inFile->seekg(j);
		 inFile->get(charAux);
		        
	}
	
			

return (true);	
}


void teste()
{

	
	
}




int main ()
{
	
	vector <IndPrim> regInd1;                     // Armazena os índices primários do primeiro arquivo
	vector <IndPrim> regInd2;                     // Armazena os índices primários do segundo arquivo
	
	bool resul;          		                  // Indica se foi possível ler o arquivo 
	IndPrim registroAux; 
	
	ifstream inFile;
	inFile.open("listas/lista1.txt", ios::in); 
	
	
	resul = LerSeqArq(&regInd1,&inFile);         // Armazena os indices do arquivo 1
	inFile.close();
	
	inFile.open("listas/lista2.txt", ios::in); 
	
	resul = LerSeqArq(&regInd2,&inFile);         // Armazena os indices do arquivo 2
	inFile.close();
	
	
	
	
return(0);	
}
