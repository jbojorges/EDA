/*
	Encabezado Elementos
*/
//Definición del tipo de dato Elemento
typedef int Elem;	

//Prototipos de las funciones
int esMenor(Elem, Elem);
void impElem(Elem);
int esMayor(Elem, Elem);

//Verifica si el primer elemento es menor al segundo
int esMenor(Elem e1, Elem e2){ 
	return  e1<e2; 
}

//Verifica si el primer elemento es mayor al segundo
int esMayor(Elem e1, Elem e2){ 
	return  e1>e2; 
}
	
//Imprime el elemento
void impElem(Elem e){ 
	printf("%d",e); 
}

