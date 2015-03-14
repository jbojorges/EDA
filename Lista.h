/*
	Encabezado de una Lista
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Elem.h"

//Definición del tipo de dato Lista
typedef struct Nodo{
	Elem dato;
    struct Nodo *sig;
}*Lista;

//Prototipos de las funciones
Lista vacia();
Lista cons(Elem, Lista);
int esVacia(Lista);
Elem cabeza(Lista);
Lista resto(Lista);
int numElem(Lista);
Lista pega(Lista, Lista);
Lista invierte(Lista);
Lista insOrd(Elem, Lista);
Lista ordena(Lista);
char imprime(Lista);
/*
void fImprime(FILE*, Lista);
Lista fcons(FILE*, Lista);
*/

//Crea una Lista vacía
Lista vacia(){

	return NULL;
}

//Agrega un elemento a la Lista
Lista cons(Elem e, Lista l){
	Lista temp=(Lista)malloc(sizeof(struct Nodo));
	temp->dato=e;
	temp->sig=l;
	return temp;
}

//Verifica si la lista está vacía
int esVacia(Lista l){

	return l==NULL;
}

//Extrae el primer elemento de la Lista
Elem cabeza(Lista l){
	return l->dato;
}

//Regresa la Lista sin el primer elemento
Lista resto(Lista l){
	return l->sig;
}

//Verifica el Numero de Elementos que tiene la Lista
int numElem(Lista l){
	if (esVacia(l)) 
		return 0; 
	else 
		return 1+numElem(resto(l)); 
}

//Pega dos Listas, la primera frente a la segunda
Lista pega(Lista l, Lista l1){
	if (esVacia(l))
		return l1;
	else
		return cons(cabeza(l),pega(resto(l),l1));

 }

//Invierte los datos de la Lista
Lista invierte(Lista l){
	if (esVacia(l))
		return l;
	else 
		return pega(invierte(resto(l)),cons(cabeza(l),vacia()));
}

//Inserta un elemento a la Lista de forma ordenada
Lista insOrd(Elem e, Lista l){
	if (esVacia(l))
		return cons(e,l);
	else{
		if (esMenor(e,cabeza(l)))
			return cons(e,l);
		else
			return cons(cabeza(l),insOrd(e,resto(l))); 
	}
}

//Ordena una Lista
Lista ordena(Lista l){ 
	if (esVacia(l))
		return l;
	else
		return insOrd(cabeza(l),ordena(resto(l)));
}


//Imprime una Lista
char imprime(Lista l){
	if(!esVacia(l)){
		impElem(cabeza(l));
		imprime(resto(l));

	}
}

/*
void fImprime(FILE* out, Lista l){
	
	while (!esvacia(l)){
  	
           fprintf(out,"%s\n",cabeza(l));
           l=resto(l);
  }

}


Lista fcons(FILE *ict, Lista t)
{
   char cadena[80],*c2;
   while(fscanf(ict, "%s",cadena)!=EOF){
	         c2=(char *)malloc(80);
	         strcpy(c2,cadena);
	          t = cons(c2,t);
	   }
 return t;
}

*/
