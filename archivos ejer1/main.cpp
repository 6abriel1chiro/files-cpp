#include <iostream>
#include <fstream>
#define TAM 100

using namespace std;
/*
    char direccion[TAM] ="C:/Users/Gabriel Ichiro/Desktop/";
    char name[TAM] ="elnombre";
      strcat(name,".txt");
     strcat(direccion,name);

     cout<<direccion<<endl;
     */
void llenarAlumnos(string alumnos[TAM],int n)
{

        for(int i = 0 ;i<n;i++)
        {
        cout<<"ingrese el alumno "<<i+1<<" : ";
        cin>>alumnos[i];
        }

}

void comprobar(bool flag){

}
int main()
{
    //declaraciones
    int nalumnos;
    string alumnos [TAM];
    string file_name;
    ofstream file;
    char value;
    bool flag=true;


        cout<<"ingrese nombre del archivo : ";
        cin>>file_name;
    while(flag)
    {
        cout<<"cuantos alummos va a ingresar "<<endl;cin>>nalumnos;
           llenarAlumnos(alumnos,nalumnos);


        file.open("C:/Users/Gabriel Ichiro/Desktop/" + file_name + ".txt",ios::app);
        for(int i = 0 ;i<nalumnos;i++)
        {
            file<<i+1<<" "<<alumnos[i]<<endl;
        }
        file.close();

        comprobar(flag);
        cout<<"va a ingresar mas alumnos? (S/N)"; cin>>value;
        if(value=='n' or value=='N')
        flag=false;

    }


}



