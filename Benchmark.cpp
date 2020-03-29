#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <iostream>
#include <thread>
#define debug(x) std::cout << #x << " = " << x << std::endl;
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <sstream>
#include <direct.h>
#include <fstream>

using namespace cv;
using namespace std;

//*********************************************************************************+
void prime(int from, int to) {
	int i = 0, num;
	for (num = from; num <= to; num++) {
		for (i = 2; i <= (num / 2); i++) {
			if (num % i == 0) {
				i = num;
				break;
			}
		}
		if (i != num) {
			cout << num << " ";
		}
	}
}

void primes() {
	int n;
	cout << "Digite el valor de n: ";
	cin >> n;

	thread first(prime, 2, n / 10);
	thread second(prime, n / 10, n / 9);
	thread third(prime, n / 9, n / 8);
	thread fourth(prime, n / 8, n / 7);
	thread fifth(prime, n / 7, n / 6);
	thread sixth(prime, n / 6, n / 5);
	thread seventh(prime, n / 5, n / 4);
	thread eighth(prime, n / 4, n / 3);
	thread nineth(prime, n / 3, n / 2);
	thread tenth(prime, n / 2, n);

	first.join();
	second.join();
	third.join();
	fourth.join();
	fifth.join();
	sixth.join();
	seventh.join();
	eighth.join();
	nineth.join();
	tenth.join();
	system("pause");
}

//*********************************************************************************+
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v)
{
	os << "[";
	if (!v.empty())
	{
		auto iter = std::begin(v);
		os << *iter;
		iter++;
		while (iter != std::end(v))
		{
			os << ", " << *iter;
			iter++;
		}
	}
	os << "]";
	return os;
}

void PI() {
	int n; // Numero de digitos después de la coma
	cout << "Digite el numero de decimales que quiere mostrar: ";
	cin >> n;
	n++;

	std::string digits;

	std::vector<int> v(10 * n / 3 + 10);
	std::fill(std::begin(v), std::end(v), 2);

	for (int iteration = 0; iteration < n; iteration++)
	{
		std::for_each(std::begin(v), std::end(v), [](int& d) { d *= 10; });
		for (int i = v.size() - 1; i > 0; i--)
		{
			const int numerator = i;
			const int denominator = 2 * (i + 1) - 1;

			const int quotient = v.at(i) / denominator;
			const int remainder = v.at(i) % denominator;

			v.at(i) = remainder;
			v.at(i - 1) += numerator * quotient;
		}

		v.at(0) %= 100;
		const int digit = v.at(0) / 10;
		v.at(0) %= 10;

		digits.push_back('0' + digit);
	}

	std::cout << digits << std::endl;

	system("pause");
}
//*********************************************************************************+
int mazeSolver() {
	cout << "Digite el nombre del laberinto con su extension (Nombre.extension): ";
	string image;
	cin >> image;
	Mat src = imread(image);
	if (!src.data) {
		printf("Error al cargar el archivo. \n");
		system("pause");
		return -1;
	}

	Mat bw;
	cvtColor(src, bw, COLOR_BGR2GRAY);
	threshold(bw, bw, 10, 255, THRESH_BINARY_INV);

	//Detecta el contorno de la imagen 
	vector<std::vector<cv::Point> > contours;
	findContours(bw, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	if (contours.size() != 2)
	{
		std::cout << "Laberino incompleto" << std::endl;
		return -1;
	}

	Mat path = Mat::zeros(src.size(), CV_8UC1);
	drawContours(path, contours, 0, CV_RGB(255, 255, 255), FILLED);

	Mat kernel = Mat::ones(21, 21, CV_8UC1);
	dilate(path, path, kernel);

	Mat path_erode;
	erode(path, path_erode, kernel);

	absdiff(path, path_erode, path);

	//Dibuja el camino rojo
	vector<Mat> channels;
	split(src, channels);
	channels[0] &= ~path;
	channels[1] &= ~path;
	channels[2] |= path;

	Mat dst;
	merge(channels, dst);
	imshow("Solución", dst);
	waitKey(0);
	system("pause");
	return 0;
}


//*********************************************************************************+

FILE* MB5, * MB10, * MB100, * MB500, * MB1000;

void archive5MB() {
	const int FILE_SIZE = 5000; //size in KB
	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE + 1];
	int i;
	for (i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = (char)(i % 8 + 'a');
	buffer[BUFFER_SIZE] = '\0';

	errno_t er = fopen_s(&MB5, "5MB.txt", "w");
	for (i = 0; i < FILE_SIZE; i++)
		fprintf(MB5, buffer);

	er = fclose(MB5);
}

void archive10MB() {
	const int FILE_SIZE = 10000; //size in KB
	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE + 1];
	int i;
	for (i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = (char)(i % 8 + 'a');
	buffer[BUFFER_SIZE] = '\0';

	errno_t er = fopen_s(&MB10, "10MB.txt", "w");
	for (i = 0; i < FILE_SIZE; i++)
		fprintf(MB10, buffer);

	er = fclose(MB10);
}

void archive100MB() {
	const int FILE_SIZE = 100000; //size in KB
	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE + 1];
	int i;
	for (i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = (char)(i % 8 + 'a');
	buffer[BUFFER_SIZE] = '\0';

	errno_t er = fopen_s(&MB100, "100MB.txt", "w");
	for (i = 0; i < FILE_SIZE; i++)
		fprintf(MB100, buffer);

	er = fclose(MB100);
}

void archive500MB() {
	const int FILE_SIZE = 500000; //size in KB
	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE + 1];
	int i;
	for (i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = (char)(i % 8 + 'a');
	buffer[BUFFER_SIZE] = '\0';

	errno_t er = fopen_s(&MB500, "500MB.txt", "w");
	for (i = 0; i < FILE_SIZE; i++)
		fprintf(MB500, buffer);

	er = fclose(MB500);
}

void archive1000MB() {
	const int FILE_SIZE = 1000000; //size in KB
	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE + 1];
	int i;
	for (i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = (char)(i % 8 + 'a');
	buffer[BUFFER_SIZE] = '\0';

	errno_t er = fopen_s(&MB1000, "1000MB.txt", "w");
	for (i = 0; i < FILE_SIZE; i++)
		fprintf(MB1000, buffer);

	er = fclose(MB1000);
}

void archivesMB() {
	printf("Generando archivo de 5MB...\n");
	archive5MB();
	printf("Generando archivo de 10MB...\n");
	archive10MB();
	printf("Generando archivo de 100MB...\n");
	archive100MB();
	printf("Generando archivo de 500MB...\n");
	archive500MB();
	printf("Generando archivo de 1000MB...\n");
	archive1000MB();
	printf("Archivos generados exitosamente.\n");
}

//*********************************************************************************+
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
		fclose(archivo);
	}
	else
	{
		cout << "El archivo no existe" << endl;
	}
}

void init(int i)
{
	_mkdir("C:\\CarpetaA");
	_mkdir("C:\\CarpetaB");
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
	struct tm newtime;
	time_t now = time(0);
	char timebuf[26];
	errno_t err;

	err = _localtime64_s(&newtime, &now);

	if (err)
	{
		printf("Argumento invalido para _localtime64_s");
		return -1;
	}

	int segs = newtime.tm_hour * 3600 + newtime.tm_min * 60 + newtime.tm_sec;
	return segs;
}

void archive4KB()
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
}
//*********************************************************************************+

void main() {
	//CPU: Encontrar los primeros 50000 números primos con 10 hilos.
	cout << "*********************************************************************************\nEjecutando programa de los primos...\n";
	primes();
	cout << "*********************************************************************************\n";

	//CPU: Encontrar los primeros 250000 dígitos de pi
	cout << "*********************************************************************************\nEjecutando programa de PI...\n";
	PI();
	cout << "*********************************************************************************\n";
	//CPU: Encontrar la salida del siguiente laberinto con X hilos
	cout << "*********************************************************************************\nEjecutando resolvedor de laberintos...\n";
	mazeSolver();
	cout << "*********************************************************************************\n";

	//Disco: Duración de escritura (archivo generado) y lectura y de archivos de 1, 10, 100, 500 y 1000 megas.
	cout << "*********************************************************************************\nEjecutando escritura de archivos...\n";
	archivesMB();
	cout << "*********************************************************************************\n";

	//Disco: Medición de cuantos archivos de 4 Kb puede copiar de una carpeta a otra en X segundos
	cout << "*********************************************************************************\nEjecutando copia de archivos...\n";
	archive4KB();
	cout << "*********************************************************************************\n";

	system("pause");
}