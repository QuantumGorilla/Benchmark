#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <sstream>
#include <direct.h>
#include <fstream>

using namespace std;
static int n_archivos = 0;
void copy_file(string ruta, string destino)
{
	FILE* archivo;
	string cadena;
	if (archivo = fopen(ruta.c_str(), "r"))
	{
		cadena = "copy " + ruta + " " + destino;
		system(cadena.c_str());
		n_archivos++;
	}
	else
	{
		cout << "El archivo no existe" << endl;
	}
}
void init(int i)
{
	mkdir("C:\\CarpetaA");
	mkdir("C:\\CarpetaB");	
	ofstream file;
	file.open("C:\\CarpetaA\\Archivo4K.txt");
	file << "Una de las estrategias de incremento m�s importantes en los dispositivos de entrada/salida es la lectura o escritura de bloques continuos de disco. Dicha estrategia afecta a c�mo el sistema de archivos en un modelo UNIX debe realizar ciertas operaciones. �Por qu� la lectura de 2MB en varias operaciones de 4KB sobre la geometr�a del disco es menos eficiente que la lectura de esa misma cantidad de informaci�n en una misma regi�n del disco? �Qui�n influye en esta diferencia de rendimiento (servidor de archivos, servidor de bloques o dispositivo de E/S)? La posibilidad de aplicar mejoras a este nivel est� relacionada con la ubicaci�n de los bloques asociados a un fichero sobre el layout del disco. �Qu� estructuras de metainformaci�n usa el servidor de archivos para realizar la ubicaci�n de nuevos bloques? �Cu�l es la pol�tica de actualizaci�n de estas estructuras de memoria a disco? Considerando la estructura de un i-nodo t�pico (10 punteros directos, 1 indirectos, simple, doble y triple, direcciones de i-nodo y de bloque de 4 bytes), se proponen dos alternativas diferentes para intentar conseguir que las operaciones sobre el disco se hagan sobre regiones continuas de mayor espacio: Dimensionamiento de la unidad m�nima de asignaci�n (agrupaci�n o bloque l�gico) a un tama�o mayor (de 4KB a 512KB). Modificaci�n de la pol�tica de asignaci�n de bloques a disco, de forma que cuando se tiene que reservar un bloque en el dispositivo se intente siempre hacerlo pegado al bloque anterior. Si tenemos 2048 ficheros de menos de 4KB, �cu�nto espacio de disco se ocupar�a en bloques de datos en cada alternativa? �Cu�ntas veces se deber�n consultar las estructuras de metainformaci�n para la ubicaci�n de bloques de datos si queremos escribir un fichero de 100MB? (Determ�nelo para cada alternativa de dise�o). En la segunda de las alternativas de dise�o se plantean problemas cuando hay varios procesos escribiendo de forma simult�nea diferentes ficheros. No tenemos la garant�a de que la asignaci�n de bloques a un fichero sea contigua, debido a que se van intercalando las peticiones de ubicaci�n de bloques y que no sabemos, a priori, el tama�o final del fichero. Para manejar el problema anterior, en ciertos sistemas de ficheros (ext4, XFS o ZFS), se aplican estrategias de ubicaci�n retrasada (delayed allocation) que implica que a un bloque de datos no se le asigna su posici�n en disco hasta que no se vuelca de la cache de bloques a disco. �En qu� momento y bajo qu� pol�tica se realiza el volcado de la cache de datos? �C�mo repercutir�a la estrategia de delayed allocation en la mejor ubicaci�n de los bloques de un mismo fichero. Esta pol�tica se complementa con un mecanismo de solicitud de ubicaci�n multibloque (multiblock allocation). �Qu� ventajas de eficiencia tiene poder solicitar la ubicaci�n de varios bloques a la vez, respecto de la solicitud de ubicaci�n de ellos uno a uno? �D�nde podr�a estar gan�ndose tiempo? Supongamos que se quiere hacer uso de la funcionalidad de multiblock allocation de otra forma, que ser�a sabiendo con antelaci�n el tama�o del fichero (el caso de aplicaciones del tipo P2P). La opci�n alternativa a esa funcionalidad puede ser de dos tipos: Que la aplicaci�n que sabe el tama�o del fichero reserve todo su espacio (creando un fichero del tama�o correspondiente lleno de bytes a cero), y seg�n se vayan generando los datos, se van sobreescribiendo las partes del mismo. Que no se reserve espacio efectivo alguno, se anota s�lo que el fichero es de un cierto tama�o y en cuanto llegue el primer bloque de datos (en una posici�n intermedia) se hace la reserva de los bloques datos y de los bloques de punteros";
	file.close();
	string ruta = "C:\\CarpetaA\\Archivo4K.txt";
	string destino = "C:\\CarpetaB";
	string out_string;
	stringstream ss;
	ss << i;
	out_string = ss.str();
	string reni = "C:\\CarpetaB\\_" + out_string + ".txt";
	copy_file(ruta, destino);
	string newfile = "C:\\CarpetaB\\Archivo4K.txt";
	rename(newfile.c_str(), reni.c_str());
}


int getime()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	int segs = time->tm_hour * 3600 + time->tm_min * 60 + time->tm_sec;
	return segs;
}
int main(int argc, char* argv[])
{
	cout << "Digite el tiempo en segundos: ";
	int s;
	cin >> s;
	int comienzo = getime();
	int i = 0;
	while (s > (getime() - comienzo))
	{
		cout << "segundo " << getime() - comienzo + 1 << endl;
		init(i);
		i++;
	}
	cout << "se copiaron " << n_archivos << " Archivos de 4KB en " << s << " segundos" << endl;
	system("Pause");
	cin.ignore();
	cin.get();
	return 0;
}
