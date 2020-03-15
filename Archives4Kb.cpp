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
	file << "Una de las estrategias de incremento más importantes en los dispositivos de entrada/salida es la lectura o escritura de bloques continuos de disco. Dicha estrategia afecta a cómo el sistema de archivos en un modelo UNIX debe realizar ciertas operaciones. ¿Por qué la lectura de 2MB en varias operaciones de 4KB sobre la geometría del disco es menos eficiente que la lectura de esa misma cantidad de información en una misma región del disco? ¿Quién influye en esta diferencia de rendimiento (servidor de archivos, servidor de bloques o dispositivo de E/S)? La posibilidad de aplicar mejoras a este nivel está relacionada con la ubicación de los bloques asociados a un fichero sobre el layout del disco. ¿Qué estructuras de metainformación usa el servidor de archivos para realizar la ubicación de nuevos bloques? ¿Cuál es la política de actualización de estas estructuras de memoria a disco? Considerando la estructura de un i-nodo típico (10 punteros directos, 1 indirectos, simple, doble y triple, direcciones de i-nodo y de bloque de 4 bytes), se proponen dos alternativas diferentes para intentar conseguir que las operaciones sobre el disco se hagan sobre regiones continuas de mayor espacio: Dimensionamiento de la unidad mínima de asignación (agrupación o bloque lógico) a un tamaño mayor (de 4KB a 512KB). Modificación de la política de asignación de bloques a disco, de forma que cuando se tiene que reservar un bloque en el dispositivo se intente siempre hacerlo pegado al bloque anterior. Si tenemos 2048 ficheros de menos de 4KB, ¿cuánto espacio de disco se ocuparía en bloques de datos en cada alternativa? ¿Cuántas veces se deberán consultar las estructuras de metainformación para la ubicación de bloques de datos si queremos escribir un fichero de 100MB? (Determínelo para cada alternativa de diseño). En la segunda de las alternativas de diseño se plantean problemas cuando hay varios procesos escribiendo de forma simultánea diferentes ficheros. No tenemos la garantía de que la asignación de bloques a un fichero sea contigua, debido a que se van intercalando las peticiones de ubicación de bloques y que no sabemos, a priori, el tamaño final del fichero. Para manejar el problema anterior, en ciertos sistemas de ficheros (ext4, XFS o ZFS), se aplican estrategias de ubicación retrasada (delayed allocation) que implica que a un bloque de datos no se le asigna su posición en disco hasta que no se vuelca de la cache de bloques a disco. ¿En qué momento y bajo qué política se realiza el volcado de la cache de datos? ¿Cómo repercutiría la estrategia de delayed allocation en la mejor ubicación de los bloques de un mismo fichero. Esta política se complementa con un mecanismo de solicitud de ubicación multibloque (multiblock allocation). ¿Qué ventajas de eficiencia tiene poder solicitar la ubicación de varios bloques a la vez, respecto de la solicitud de ubicación de ellos uno a uno? ¿Dónde podría estar ganándose tiempo? Supongamos que se quiere hacer uso de la funcionalidad de multiblock allocation de otra forma, que sería sabiendo con antelación el tamaño del fichero (el caso de aplicaciones del tipo P2P). La opción alternativa a esa funcionalidad puede ser de dos tipos: Que la aplicación que sabe el tamaño del fichero reserve todo su espacio (creando un fichero del tamaño correspondiente lleno de bytes a cero), y según se vayan generando los datos, se van sobreescribiendo las partes del mismo. Que no se reserve espacio efectivo alguno, se anota sólo que el fichero es de un cierto tamaño y en cuanto llegue el primer bloque de datos (en una posición intermedia) se hace la reserva de los bloques datos y de los bloques de punteros";
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
