#include <iostream>
#include <fstream>

using namespace std;

void crear_HORARIO(int filas, int columnas,int aux,char HORARIO[][8]);
void separar_horaio_materia(char horario_materia[6],char &columna, char &fila,char HORARIO[][8],int filas, int columnas);

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
    archivo.close();

    char HORARIO[][8] = {
        'H', 'L', 'M', 'W', 'J', 'V', 'S', 'D',
        '6', '-', '-', '-', '-', '-', '-', '-',
        '7', '-', '-', '-', '-', '-', '-', '-',
        '8', '-', '-', '-', '-', '-', '-', '-',
        '9', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '1', '-', '-', '-', '-', '-', '-', '-',
        '2', '-', '-', '-', '-', '-', '-', '-',
        '2', '-', '-', '-', '-', '-', '-', '-'
    };

    int filas = (sizeof(HORARIO)/sizeof(HORARIO[0]));
    int columnas = (sizeof(HORARIO[0])/sizeof(HORARIO[0][0]));
    int aux=0;

    //crear_HORARIO(filas,columnas,aux,HORARIO);

    // Ubicar la materia en la matriz
    char columna,fila;
    char horario_materia[6];

    cin >> horario_materia;
    //cout << horario_materia<< endl;

    separar_horaio_materia(horario_materia,columna,fila,HORARIO,filas,columnas);

    aux=0;
    crear_HORARIO(filas,columnas,aux,HORARIO);
    return 0;
}

void crear_HORARIO(int filas, int columnas,int aux,char HORARIO[][8]){
for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
        if (i>=5 && i<=14 && j==0){
            cout<<HORARIO[i][j]<< aux <<" | ";
            aux++;
            continue;
        }
        if (aux==10){
            aux=0;
        }
        if (i>=14 && i<=17 && j==0){
            cout<<HORARIO[i][j]<< aux <<" | ";
            aux++;
            continue;
        }
        cout<<HORARIO[i][j]<<"  | ";
    }//cierra for columna
    cout << endl;
}//cierra for fila

}
void separar_horaio_materia(char horario_materia[6],char &columna, char &fila,char HORARIO[][8],int filas, int columnas){
    char a_columnas[6]={'L','M','W','J','V','S'};
    char a_filas[10]={'0','1','2','3','4','5','6','7','8','9'};
    int hora1;
    for (char var = 0; var < 6; var++) {
        if (horario_materia[0]==a_columnas[var])
            columna=var+1;//COLUMNA +1 Por que la columna 0 es la de el horario
    }
    for (char var = 0; var < 10; var++) {
        if (horario_materia[1]==a_filas[0]){
            for (char i = 0; i < 4; i++) { // 4 por que es solo  6 - 7 - 8 - 9
                if (horario_materia[2]==a_filas[i+6]){ // +6 por que i esta ubicado en la posicion 0 de a_filas y el horario empieza a las 6am
                    fila=i+1; // +1 por que la fila 0 es la de el horario
                    hora1=fila;
                    HORARIO[fila][columna]='Y';
                    break;
                }
            }
        }
        if (horario_materia[1]==a_filas[1]){
            for (char i = 0; i < 10; i++) { // 4 por que es solo  6 - 7 - 8 - 9
                if (horario_materia[2]==a_filas[i]){ // +6 por que i esta ubicado en la posicion 0 de a_filas y el horario empieza a las 6am
                    fila=i+5; // +5 por que la fila 0 es la de el horario y te la 1 a la 4 son de 6am a 9am, las 10am esta es la posicion 5
                    hora1=fila;
                    HORARIO[fila][columna]='Y';
                    break;
                }
            }
        }
        if (horario_materia[1]==a_filas[2]){
            for (char i = 0; i < 2; i++) { // 4 por que es solo  6 - 7 - 8 - 9
                if (horario_materia[2]==a_filas[i]){ // +6 por que i esta ubicado en la posicion 0 de a_filas y el horario empieza a las 6am
                    fila=i+15; // +15 por que las 20pm esta es la posicion 15
                    hora1=fila;
                    HORARIO[fila][columna]='Y';
                    break;
                }
            }
        }
        /*int aux=0;
        crear_HORARIO(filas,columnas,aux,HORARIO);*/
        if (horario_materia[4]==a_filas[0]){
            for (char i = 0; i < 4; i++) { // 4 por que es solo  6 - 7 - 8 - 9
                if (horario_materia[5]==a_filas[i+6]){ // +6 por que i esta ubicado en la posicion 0 de a_filas y el horario empieza a las 6am
                    fila=i+1; // +1 por que la fila 0 es la de el horario
                    while (fila>hora1){
                        HORARIO[fila][columna]='Y';
                        fila--;
                    }
                    break;
                }
            }
        }
        if (horario_materia[4]==a_filas[1]){
            for (char i = 0; i < 10; i++) { // 4 por que es solo  6 - 7 - 8 - 9
                if (horario_materia[5]==a_filas[i]){ // +6 por que i esta ubicado en la posicion 0 de a_filas y el horario empieza a las 6am
                    fila=i+5; // +5 por que la fila 0 es la de el horario y te la 1 a la 4 son de 6am a 9am, las 10am esta es la posicion 5
                    while (fila>hora1){
                        HORARIO[fila][columna]='Y';
                        fila--;
                    }
                    break;
                }
            }
        }
        if (horario_materia[4]==a_filas[2]){
            for (char i = 0; i < 2; i++) { // 4 por que es solo  6 - 7 - 8 - 9
                if (horario_materia[5]==a_filas[i]){ // +6 por que i esta ubicado en la posicion 0 de a_filas y el horario empieza a las 6am
                    fila=i+15; // +15 por que las 20pm esta es la posicion 15
                    while (fila>hora1){
                        HORARIO[fila][columna]='Y';
                        fila--;
                    }
                    break;
                }
            }
        }
        /*aux=0;
        crear_HORARIO(filas,columnas,aux,HORARIO);*/
    }
}
