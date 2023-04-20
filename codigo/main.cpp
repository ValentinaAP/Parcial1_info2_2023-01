#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream archivo;
    archivo.open("pensum.txt");

    if (!archivo) {
        cout << "No se pudo abrir el archivo cursos.txt" << endl;
        return 1;
    }

    char linea[100];

    while (archivo.getline(linea, 100)) {
           char codigo[5]="";
           char nombre[50]="";
           char credito;
           char ti;
           char horario[20];

           int i = 0; // itera en linea
           int j = 0; // itera en codigo y en nombre
           int k = 0; // itera en horario

           {// extrae codigo curso
           for(i,j;linea[i] != ',';i++,j++){ // extrae codigo curso
               codigo[j] = linea[i];
           }
           codigo[j] = '\0'; // convierte j en nulo para indicar final de la cadena
           i++;
           j = 0;
           }// extrae codigo curso

           {
           for(i,j;linea[i] != ',';i++,j++){ // extrae nombre curso
               nombre[j] = linea[i];
           }
           nombre[j] = '\0';  // convierte j en nulo para indicar final de la cadena
           i++;
           j = 0;
           }// extrae nombre curso

           {
           for(i;linea[i] != ',';i++){ // extrae  credito
               credito = linea[i];
           }

           i++;
           j = 0;
           }//extrae credito

           {
           for(i;linea[i] != ',';i++){ // extrae horas trabajo independiente
               ti = linea[i];
           }

           i++;
           j = 0;
           }// extrae horas trabajo independiente

           cout << "Codigo: " << codigo << endl;
           cout << "Nombre: " << nombre << endl;
           cout << "Creditos: " <<  credito << endl;
           cout << "Trabajo independiente en horas: " <<  ti << endl;

            {
                   while (linea[i] != '\0') {
                       horario[j] = linea[i];
                       j++;
                       i++;
                   }
                   horario[j] = '\0';

           cout << "Horario: " << horario << endl;
            } //extrae horario
    }
    char HORARIO[][10] = {
        "Hora/Dia", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo",
        "06:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "07:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "08:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "09:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "10:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "11:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "12:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "13:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "14:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "15:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "16:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "17:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "18:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "19:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "20:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------",
        "21:00", "--------", "--------", "--------", "--------", "--------", "--------", "--------"
    };

    // Recorrer la matriz e imprimir su contenido
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 8; j++) {
            cout << HORARIO[i * 8 + j] << " ";
        }
        cout << endl;
    }

    // Ubicar la materia en la matriz
    char columna;
    char horario_materia[6];

    cin >> horario_materia;
    //cout << horario_materia<< endl;

    if (horario_materia[0]=='L')
        columna=1;
    if (horario_materia[0]=='M')
        columna=2;
    if (horario_materia[0]=='W')
        columna=3;
    if (horario_materia[0]=='J')
        columna=4;
    if (horario_materia[0]=='V')
        columna=5;
    if (horario_materia[0]=='S')
        columna=6;

    HORARIO[1][columna]='I';

    // Recorrer la matriz e imprimir su contenido
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 8; j++) {
            cout << HORARIO[i * 8 + j] << " ";
        }
        cout << endl;
    }

    archivo.close();

    return 0;
}
