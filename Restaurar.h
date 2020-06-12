/*
* Proyecto brazo robotico
* Jesus Misael Resendiz Cruz
* A01706166
* 11/06/2020
* Esta clase define objeto de tipo Restaurar que son composicion de Robots, me permite crear
* posiciones para cada servo, esta se estara modificando con el tiempo por la temperatura
* adquirida por el mismo servo o modificadas por el usuario.
*/
# ifndef RESTAURAR_H_
# define  RESTAURAR_H_
// Creacion de la clase Restaurar
class Restaurar{ 
	//Atributos 
	private:
		int posicion[100][100];
		int posicionI[100][100]={{97,8,2},{3,0,9},{8,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24},{25,26,27}}; 
	public:
		// Prototipo del constructor por default
		Restaurar();  
		// Prototipo del constructor parametrizado
		Restaurar(int pos[100][100]);  
		//Prototipo de los metodos
		int particular_posicion(int nfila,int ncolumna);      
		void set_posicion(int sP1,int sP2,int sP3,int sP4);  
		void set_posicionCompleto(int posi[100][100]);
};

// Definicion del constructor por default
Restaurar::Restaurar(int pos[100][100]){ 
	int i,j;
	for(i = 0; i < 9; i++)     
		for (j = 0; j < 3; j++)
			posicion[i][j]=pos[i][j];
}
// Definicion del constructor parametrizado
Restaurar::Restaurar(){ 
	int i,j;
	for(i = 0; i < 9; i++)  
		for (j = 0; j < 3; j++)
			posicion[i][j]=posicionI[i][j];
}
// Funcion que extrae los valores y los añade en el atributo posicion
void Restaurar::set_posicionCompleto(int posi[100][100]){
	int i,j;
	for(i = 0; i < 9; i++)     
		for (j = 0; j < 3; j++)
			posicion[i][j]=posi[i][j];
}
// Funcion que me permite restablecer los angulos de mis servomotores.
void Restaurar::set_posicion(int sP1,int sP2,int sP3,int sP4){ 
	int i,j;                                              
	for(i = 0; i < 8; i++)                         
		for (j = 0; j < 3; j++){                       
			if (i==0){
				posicion[i][j]=sP1;
			}
			if (i>=1 and i<=3){
				posicion[i][j]=sP2;
			}
			if (i>=4 and i<=5){
				posicion[i][j]=sP3;
			}
			if (i>=6 and i<=7){
				posicion[i][j]=sP4;
			}
		}
}
// Funcion que una posicion particular
int Restaurar::particular_posicion(int nfila,int ncolumna){  
	return posicion[nfila][ncolumna];
}
# endif