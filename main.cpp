#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include<map>
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

/*
	Time Conversion
	La implementacion time_conversion_2 es mas eficiente que
	time_conversion_1 debido a que la primera tiene mas comparaciones
	a la hora de encontrar si hay que modificar el valor de la hora.En
	cambio la segunda implementacion usa la division entera para encontrar 
	el valor de las horas, lo cual es mas rapido.

*/
string time_conversion_1(string s){	
	int horas = stoi(s.substr(0,2));
	if(s.substr(8) == "AM"){
		if(horas == 12){
			horas = 0;
		}
		if(horas < 10){
			return "0"+ to_string(horas) + s.substr(2,6);
		}
		return to_string(horas) + s.substr(2,6);
	}
	else{
		if(horas != 12){
			horas +=12;
		}
		return to_string(horas) +s.substr(2,6);
	}
}

string time_conversion_2(string s){	
	int horas = stoi(s.substr(0,2));
	if(s.substr(8) == "AM"){
		horas = horas%12;
		if(horas < 10){
			return "0"+ to_string(horas) + s.substr(2,6);
		}
		return to_string(horas) + s.substr(2,6);
	}
	else{
		horas = horas%12 +12;
		return to_string(horas) +s.substr(2,6);
	}
}


/*	Subaaray division 
	Como en los casos anteriores la primera implementacion no es la mas eficiente.
	Esto se debe a que la primera implementacion hace uso de 2 ciclos, mientras
	que la segunda solo hace 1 ciclo, recorriendo menor cantidad de veces el vector.
*/

int subarray_division_1(vector<int> s, int d, int m) {
    int r = 0;
    int contador = 0;
    for (int i = 0; i < s.size(); i++) {
        contador = 0;
        for (int j = 0; j < m; j++) {
            contador += s[i+j];
        }
        if(contador == d){
            r++;
        }
    }
    return r;
}

int subarray_division_2(vector<int> s, int d, int m) {
    int r = 0;
    int suma = 0;
    int i = 0;
    int j = 0;
    while(j < s.size()){
    	if(j-i == m ){
    		if(suma == d){
    		 	r++;
			}
			suma -= s[i];
			i++;
		}
		else{
			suma+=s[j];
			j++;
		}
	}
    return r;
}

/*minio game */
void minion_game(string s){
	int Kevin = 0;
	int Stuart = 0;
	string letra= "";
	for(int i= 0; i<s.size(); i++){
		letra = s.substr(i,1);
		if(letra== "A" || letra== "E" || letra =="I" || letra=="O"|| letra=="U"){
			Kevin+= s.size()-i;
		}
		else{
			Stuart+= s.size()-i;
		}
	}
	if(Stuart<Kevin){
		cout<<"Kevin " + to_string(Kevin)<<endl;
	}
	else{
		if(Stuart>Kevin){
			cout<<"Stuart " + to_string(Stuart)<<endl;
		}
		else{
			cout<<"Draw"<<endl;
		}
	}
	
}



/*Pairs*/

int Pairs(vector<int> arr, int k){
	map <int, int> mapa;
	int respuesta = 0;
	
	for(int i = 0; i< arr.size();i++){
		if(mapa.find(arr[i]+k) != mapa.end()){
			respuesta++;
		}
		if(mapa.find(abs(arr[i]-k)) != mapa.end()){
			respuesta++;
		}
		mapa.insert({arr[i],i});
	}
	return respuesta;
}

/*Cipher*/

string Cipher(string s, int n){
	int suma =0;
	int temporal = 0;
	string resultado= "";
	map <int, int> mapa;
	for(int i = 0; i < s.length()-n+1;i++){
		if(i>=n){
			suma -= mapa.find(i-n)->second;
		}
		temporal = (stoi(s.substr(i,1)) + suma)%2;
		mapa.insert({i,temporal});
		suma += temporal;
		resultado += to_string(temporal);
	}
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
	cout<<"Compare the triplets"<<endl;
	cout<<"primera prueba "<<endl;
	cout <<"Entrada : [1,2,3] [3,2,1]"<<endl;
	
	respuesta =Compare_the_triples_1(a, b);
 	cout<< respuesta[0]<<endl;
	cout<< respuesta[1]<<endl;
	
	respuesta =Compare_the_triples_2(a, b);
 	cout<< respuesta[0]<<endl;
	cout<< respuesta[1]<<endl;
	
	
	cout<<"segunda prueba"<<endl;
	cout <<"Entrada : [3,3,3] [2,2,0]"<<endl;
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
	
	cout <<"Time conversion"<<endl;
	cout <<"Prueba 1"<<endl;
	cout <<"Entrada : 02:55:60PM"<<endl;
	cout <<time_conversion_1("02:55:60PM")<<endl;
	cout <<time_conversion_2("02:55:60PM")<<endl;
	
	cout <<"Prueba 2"<<endl;
	cout <<"Entrada : 12:55:60AM"<<endl;
	cout <<time_conversion_1("12:55:60AM")<<endl;
	cout <<time_conversion_2("12:55:60AM")<<endl;
	
	cout<<"subarray division"<<endl;
	vector<int> sb(5);
	sb[0] = 1;
	sb[1] = 2;
	sb[2] = 1;
	sb[3] = 3;
	sb[4] = 2;
	
	cout <<"Prueba 1"<<endl;
	cout <<"Entrada : [1,2,1,3,2]"<<endl;
	cout <<subarray_division_1(sb,3,2)<<endl;
	cout <<subarray_division_2(sb,3,2)<<endl;
	
	sb[0] = 1;
	sb[1] = 1;
	sb[2] = 1;
	sb[3] = 1;
	sb[4] = 1;
	cout <<"Prueba 2"<<endl;
	cout <<"Entrada : [1,1,1,1,1]"<<endl;
	cout <<subarray_division_1(sb,3,12)<<endl;
	cout <<subarray_division_2(sb,3,12)<<endl;
	
	cout<<"The minion gamne"<<endl;
	cout <<"Prueba 1"<<endl;
	cout <<"Entrada : BANANA"<<endl;
	minion_game("BANANA");
	
	cout<<"Prueba 2"<<endl;
	cout <<"Entrada : CAAAASA"<<endl;
	minion_game("CAAAASA");
	
	sb[0] = 1;
	sb[1] = 5;
	sb[2] = 3;
	sb[3] = 4;
	sb[4] = 2;
	
	cout <<"Pairs"<<endl;
	cout <<"Prueba 1"<<endl;
	cout <<"Entrada : [1,5,3,4,2] 2"<<endl;
	cout<< Pairs(sb,2)<<endl;
	
	
	sb[0] = 4;
	sb[1] = 7;
	sb[2] = 3;
	sb[3] = 8;
	sb[4] = 10;
	cout <<"Prueba 2"<<endl;
	cout <<"Entrada : [4,7,3,8,10] 3"<<endl;
	cout<< Pairs(sb,3)<<endl;
	
	cout<<"Cipher"<<endl;
	cout<<"Pruebas 1"<<endl;
	cout <<"Entrada : 1110100110 4"<<endl;
	cout<< Cipher("1110100110",4)<<endl;
	
	cout<<"Pruebas 2"<<endl;
	cout <<"Entrada : 1110001 2"<<endl;
	cout<< Cipher("1110001",2)<<endl;
	
	return 0;
}
