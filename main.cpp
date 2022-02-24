#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* Compare the triples 
	La implementacion de Compare_the_triples_2 es mucho mas eficiente que
	Compare_the_triples_1 debido a que la primera tiene muchas comparaciones
	3 del for y 2 por cada ciclo del for en el peor de los casos, en cambio 
	la segunda implementacion solo tiene 3 comparaciones y el resultado se obtiene
	con operaciones aritmeticas
*/
vector <int> Compare_the_triples_1(vector<int> a, vector<int> b){
	vector<int> resultado(2);
	resultado[0]=0;
	resultado[1]=0;
	
	for(int i; i<3; i++){
		if(a[i]>b[i]){
			resultado[0]++;
		}
		else{
			if(a[i] < b[i]){
				resultado[1] ++;
			}
		}
	}
	return resultado;
}

vector <int> Compare_the_triples_2(vector<int> a, vector<int> b){
	vector<int> resultado(2);
	resultado[0]=0;
	resultado[1]=0;	
	if(a[0]-b[0] != 0){
		resultado[0] += (a[0]-b[0])/abs(a[0]-b[0]) + 1;
		resultado[1] += (b[0]-a[0])/abs(b[0]-a[0]) +1;
	}
	if(a[1]-b[1] != 0){
		resultado[0] += (a[1]-b[1])/abs(a[1]-b[1]) + 1;
		resultado[1] += (b[1]-a[1])/abs(b[1]-a[1]) +1;
	}	
	if(a[2]-b[2] != 0){
		resultado[0] += (a[2]-b[2])/abs(a[2]-b[2]) + 1;
		resultado[1] += (b[2]-a[2])/abs(b[2]-a[2]) +1;
	}
	resultado[0] = resultado[0]/2;
	resultado[1] = resultado[1]/2;
	
	return resultado;
}



int main(int argc, char** argv) {
	vector<int> respuesta;
	vector <int>  a(3);
	vector <int>  b(3);
	
	//pruebas
	a[0]=1;
	a[1]=2;
	a[2]=3;
	
	b[0]=3;
	b[1]=2;
	b[2]=1;
	cout<<"primera prueba"<<endl;
	respuesta =Compare_the_triples_1(a, b);
	
 	cout<< respuesta[0]<<endl;
	cout<< respuesta[1]<<endl;
	
	respuesta =Compare_the_triples_2(a, b);
	
 	cout<< respuesta[0]<<endl;
	cout<< respuesta[1]<<endl;
	
	
	cout<<"segunda prueba"<<endl;
	a[0]=3;
	a[1]=3;
	a[2]=3;
	
	b[0]=2;
	b[1]=2;
	b[2]=0;
	
	respuesta =Compare_the_triples_1(a, b);
	
 	cout<< respuesta[0]<<endl;
	cout<< respuesta[1]<<endl;
	
	respuesta =Compare_the_triples_2(a, b);
	
 	cout<< respuesta[0]<<endl;
	cout<< respuesta[1]<<endl;
	
	
	return 0;
}
