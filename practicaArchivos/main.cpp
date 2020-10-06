#include <iostream>
#include <fstream>
#define TAM 100
using namespace std;


//EJERCICIO 1
 //EJERCICIO 2
  void guardarDatos(string nombre[TAM],int sueldo[TAM],int horasTrabajadas[TAM])
  {

   fstream file;
   int i=0;

   file.open("E:/clases +/SEM II/PROGRA1/Trabajos/PRACTICA ARCHIVOS/practicaArchivos/datos.txt");
while (!file.eof()){
    file>>nombre[i]>>sueldo[i]>>horasTrabajadas[i];
    i++;

}
file.close();

 }
 //ejercicio 3

 typedef struct {
int day;
int month;
int year;

}tipoFecha;
typedef struct {
int hour;
int minute;
int sec;

}tipoHora;

typedef struct {
string  descripcion;
tipoFecha fecha;
tipoHora horaInicial;
tipoHora horaFinal;
char estado ; // P o R

}tipoActividad;

void leerFecha(tipoFecha &date){
    cout<<"fecha "<<endl;

cin>>date.day>>date.month>>date.year;
}
void leerFechas(tipoFecha date[TAM],int tam){
for(int i=0;i<tam;i++){

leerFecha(date[i]);

}
}
void mostrarFecha(tipoFecha date){
cout<<date.day<<" / "<<date.month<<" / "<<date.year<<endl;
}
void mostrarFechas(tipoFecha date[TAM],int tam){
for(int i=0;i<tam;i++){

mostrarFecha(date[i]);

}
}
bool esFechaValida(tipoFecha fecha)
{
int dias_mes[] = {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
    //Comprobar si el ano es bisiesto y anadir dia en febrero en caso afirmativo
    if((fecha.year%4 == 0 and fecha.year%100 != 0) or fecha.year%400 == 0)
        dias_mes[1]++;

    //Comprobar que el mes sea valido
    if(fecha.month < 1 or fecha.month > 12)
        return false;

    //Comprobar que el dia sea valido
    fecha.month = fecha.month-1;
    if(fecha.day <= 0 or fecha.day > dias_mes[fecha.month])
        return false;

    //Si ha pasado todas estas condiciones, la fecha es valida
    return true;
}
bool esFechaMayor(tipoFecha f1,tipoFecha f2){
bool esMayor=false;
if((f1.year>f2.year) or (f1.year==f2.year and f1.month>f2.month) or (f1.year==f2.year and f1.month==f2.month and f1.day>f2.day))
esMayor=true;

    return esMayor;

}

void ordenarFechas(tipoFecha fecha[TAM] ,int nfechas){
    tipoFecha fechaMayor={0,0,0};
    for(int i = 0;i<nfechas;i++){
             for(int j = i+1;j<nfechas;j++){
                if(esFechaMayor(fecha[i],fecha[j])){
            fechaMayor=fecha[i];
            fecha[i]=fecha[j];
            fecha[j]=fechaMayor;
            }

        }


    }
}


void leerHora(tipoHora &hora){
cout<<"hora "<<endl;
cin>>hora.hour>>hora.minute>>hora.sec;
}
void mostrarHora(tipoHora hora){
cout<<hora.hour<<" : "<<hora.minute<<" : "<<hora.sec<<endl;
}

 void leerActividad(tipoActividad &actividad){
 cout<<" descripcion "<<endl;
 cin>>actividad.descripcion;
  cout<<" fecha "<<endl;
 leerFecha(actividad.fecha);
  cout<<" hora de inicio  "<<endl;
 leerHora(actividad.horaInicial);
  cout<<" hora de conlusion  "<<endl;
 leerHora(actividad.horaFinal);
  cout<<" estado  "<<endl;
 cin>>actividad.estado;
 }

 void leerActividades(tipoActividad actividad[TAM],int tam){
for(int i=0;i<tam;i++){

leerActividad(actividad[i]);

}
}
 void mostrarActividad(tipoActividad actividad){

     cout<<" descripcion "<<endl;
 cout<<actividad.descripcion;
  cout<<" fecha "<<endl;
 mostrarFecha(actividad.fecha);
  cout<<" hora de inicio  "<<endl;
 mostrarHora(actividad.horaInicial);
  cout<<" hora de conlusion  "<<endl;
mostrarHora(actividad.horaFinal);
  cout<<" estado  "<<endl;
 cout<<actividad.estado;


}
void mostrarActividades(tipoActividad actividad[TAM],int tam){
for(int i=0;i<tam;i++){

mostrarActividad(actividad[i]);

}
}


void ordenarListaPorFecha(tipoActividad listaActividades[TAM],int n){
tipoActividad menor;
int posMenor;
for(int d=0;d<n;d++){
menor=listaActividades[d];
posMenor=d;
for(int i=d+1;i<n-1;i++){
    if(esFechaMayor(menor.fecha,listaActividades[i].fecha))
        {
        menor=listaActividades[i];
        posMenor=i;
    }
    listaActividades[posMenor]=listaActividades[d];
    listaActividades[d]=menor;
}

}

}
void ordenarListaPorDescripcion(tipoActividad listaActividades[TAM],int n){
tipoActividad menor;
int posMenor;
for(int d=0;d<n;d++){
menor=listaActividades[d];
posMenor=d;
for(int i=d+1;i<n-1;i++){
    if(listaActividades[i].descripcion<menor.descripcion)
        {
        menor=listaActividades[i];
        posMenor=i;
    }
    listaActividades[posMenor]=listaActividades[d];
    listaActividades[d]=menor;
}

}

}


///////////////////4
typedef struct{
tipoFecha fechaNacimiento;
tipoFecha fechaIngreso;
string nombre;
char sexo; // H,M

}tipoEmpleado;

void leerEmpleado(tipoEmpleado &empleado){
cout<<"fecha de nacimiento "; leerFecha(empleado.fechaNacimiento);
cout<<"fecha de ingreso "; leerFecha(empleado.fechaIngreso);
cout<<"nombre ";cin>>empleado.nombre;
cout<<"sexo: ";cin>>empleado.sexo;
}
void leerEmpleados(tipoEmpleado empleado[TAM],int n){

for (int i=0;i<n;i++){

    leerEmpleado(empleado[i]);

}
}
void mostrarEmpleado(tipoEmpleado empleado){
cout<<"\nfecha de nacimiento ";mostrarFecha(empleado.fechaNacimiento);
cout<<"\nfecha de ingreso "; mostrarFecha(empleado.fechaIngreso);
cout<<"\nnombre ";cout<<empleado.nombre;
cout<<"\nsexo: ";cout<<empleado.sexo;
cout<<endl;

}

void mostrarEmpleados(tipoEmpleado empleado[TAM],int n){

    for(int i=0;i<n;i++)
mostrarEmpleado(empleado[i]);
}

bool esMasJoven(tipoEmpleado empleado1,tipoEmpleado empleado2){

    if(esFechaMayor(empleado1.fechaNacimiento,empleado2.fechaNacimiento))
return true;
else
    return false;
}

bool esMasAntiguo(tipoEmpleado empleado1,tipoEmpleado empleado2){

    if(esFechaMayor(empleado1.fechaNacimiento,empleado2.fechaNacimiento))
return false;
else
    return true;
}
void mostrarMujeres(tipoEmpleado empleado[TAM],int n){
     int total=0;
for(int i=0;i<n;i++){

    if(empleado[i].sexo=='m' or empleado[i].sexo=='M'){
        mostrarEmpleado(empleado[i]);
        total++;

        }
}

cout<<" total "<<total<<endl;
}
void mostrarHombres(tipoEmpleado empleado[TAM],int n){
    int total=0;
for(int i=0;i<n;i++){

    if(empleado[i].sexo=='h' or empleado[i].sexo=='H'){
        mostrarEmpleado(empleado[i]);
        total++;
        }
}
cout<<" total "<<total<<endl;
}

void hallarEpleadaMasJoven(tipoEmpleado empleados[TAM],int nEmpleados){
tipoEmpleado menor;
int posMenor;
int total=0;
tipoEmpleado mujeres[TAM];
for(int i=0;i<nEmpleados;i++){

    if(empleados[i].sexo=='m' or empleados[i].sexo=='M'){
        mujeres[i]=empleados[i];
        total++;
        }
}

for(int d=0;d<total;d++){
menor=mujeres[d];
posMenor=d;
for(int i=d+1;i<total-1;i++){
    if(esMasJoven(mujeres[i],menor))
        {
        menor=mujeres[i];
        posMenor=i;
    }
    mujeres[posMenor]=mujeres[d];
    mujeres[d]=menor;
}

}
mostrarEmpleado(mujeres[total-1]);

}

void hallarEpleadoMasJoven(tipoEmpleado empleados[TAM],int nEmpleados){
tipoEmpleado menor;
int posMenor;
int total=0;
tipoEmpleado hombres[TAM];
for(int i=0;i<nEmpleados;i++){

    if(empleados[i].sexo=='h' or empleados[i].sexo=='H'){
        hombres[i]=empleados[i];
        total++;
        }
}

for(int d=0;d<total;d++){
menor=hombres[d];
posMenor=d;
for(int i=d+1;i<total-1;i++){
    if(esMasJoven(hombres[i],menor))
        {
        menor=hombres[i];
        posMenor=i;
    }
    hombres[posMenor]=hombres[d];
    hombres[d]=menor;
}

}
mostrarEmpleado(hombres[total-1]);

}





void hallarEmpleadoMasAntiguo(tipoEmpleado empleados[TAM],int nEmpleados){
tipoEmpleado menor;
int posMenor;

for(int d=0;d<nEmpleados;d++){
menor=empleados[d];
posMenor=d;
for(int i=d+1;i<nEmpleados-1;i++){
    if(esMasAntiguo(empleados[i],menor))
        {
        menor=empleados[i];
        posMenor=i;
    }
    empleados[posMenor]=empleados[d];
    empleados[d]=menor;
}

}
mostrarEmpleado(empleados[nEmpleados-1]);

}


int main()
{
    //EJERCICIO 1
    string nombre[TAM];
    int sueldo[TAM],horasTrabajadas[TAM];
    guardarDatos(nombre,sueldo,horasTrabajadas);
        for(int i =0;i<3;i++){
     cout<<nombre[i]<<" gana "<<sueldo[i]*horasTrabajadas[i]<<"$"<<endl;

    }


    //EJERCICIO 2

      ofstream output;
    output.open("E:/clases +/SEM II/PROGRA1/Trabajos/PRACTICA ARCHIVOS/practicaArchivos/datosProcesados.txt",ios::app);

     guardarDatos(nombre,sueldo,horasTrabajadas);
    for(int i =0;i<3;i++){
     output<<nombre[i]<<" gana "<<sueldo[i]*horasTrabajadas[i]<<"$"<<endl;

    }
    output.close();
    //EJERCICIO 3
        int nfechas,nactividades;
    tipoFecha fechas[TAM];
    tipoActividad actividades[TAM];


    //// 1
    /*
    cout<<"cuantas fechas desea ingresar "; cin>>nfechas;
    leerFechas(fechas,nfechas);
    cout<<"fechas : "<<endl;
    mostrarFechas(fechas,nfechas);
    ordenarFechas(fechas,nfechas);
    cout<<"fechas ordenadas: "<<endl;
    mostrarFechas(fechas,nfechas);
    ///////////////2
    cout<<"cuantas Actividades desea ingresar "; cin>>nactividades;
    leerActividades(actividades,nactividades);
        cout<<"Actividades : "<<endl;
    mostrarActividades(actividades,nactividades);
    //cout<<"actividades ordenadas por fecha "<<endl;
    //ordenarListaPorFecha(actividades,nactividades);
    //mostrarActividades(actividades,nactividades);
       cout<<"actividades ordenadas por descripcion "<<endl;
    ordenarListaPorDescripcion(actividades,nactividades);
    mostrarActividades(actividades,nactividades);
*/

       //////////3

       /*
    tipoEmpleado empleados[TAM];
    int nempleados;
        cout<<"cuantos empleados desea ingresar "; cin>>nempleados;
    leerEmpleados(empleados,nempleados);
        cout<<"Empleados : "<<endl;
    //mostrarEmpleados(empleados,nempleados);
    cout<<"Hombres : "<<endl;
    mostrarHombres(empleados,nempleados);
    cout<<"mujeres : "<<endl;
    mostrarMujeres(empleados,nempleados);

    cout<<"el empleado mas joven es "<<endl;
    //hallarEpleadoMasJoven(empleados,nempleados);

    cout<<"La empleada mas joven es "<<endl;
    //hallarEpleadaMasJoven(empleados,nempleados);

    cout<<"La el empleado con mas antiguedad es "<<endl;
    hallarEmpleadoMasAntiguo(empleados,nempleados);

*/





    return 0;
}
