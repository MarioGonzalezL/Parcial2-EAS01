#include <iostream>
#include <string>
#include <cstdlib>  // Función rand().
#include <ctime>    // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador{
    /*
        Agrega propiedades para guardar la vida(número entero), ataque(número entero) y nombre del jugador.
        Agrega una propiedad para guardar el jugador que lo atacó por última vez.
    */
public:
    int vida;
    int ataque;
    string name;

    Jugador* lastenemy;

    Jugador(); 
    Jugador(int hp, int attack, string nombre); 
    
    void atacar( Jugador &enemigo); 
};

int main()
{
    srand(time(0));  // Seed para generar valores aleatorios

    Jugador p1(100, 18, "Flyshok");
    Jugador p2(150, 14, "Cabezon");

    do
    {
       p1.atacar (p2);
       p2.atacar (p1);
    } while (p1.vida >=0 && p2.vida >= 0);

    if(p1.vida>p2.vida){
        cout << "EL ganador es " << p1.name << endl;
    }

    if(p1.vida<p2.vida){
        cout << "EL ganador es " << p2.name << endl;
    }
    
    
    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque. 
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina. 
        No importa quien ataca primero.
    */

    return 0;
}

Jugador::Jugador(){
    vida= 100;
    ataque = 5;
    name = "No definido";
    /*
        Asignar 100 a hp y 5 a attack como valores default.
        Asignar 'No definido' al nombre como default.
    */
}

Jugador::Jugador(int hp, int attack, string nombre){
    if (hp<=200 && hp>0){
    vida = hp;
    }
    if (attack<=20 && attack>0){
    ataque = attack;
    }

    name= nombre;
    /*
        Asignar los parámetros recibidos a las propiedades del objeto.
        No se pueden asignar valores negativos a hp y attack.
        Máximo 200 hp y 20 attack
    */
}

void Jugador::atacar(Jugador &enemigo){
    int x= rand() % 5;
    if(x == 0){
        cout << "ATAQUE FALLIDO" << endl;
        cout << name << " ataco a " << enemigo.name << " pero fallo, la vida restante de " << enemigo.name << " es " << enemigo.vida << endl;
    }else {
        enemigo.vida -= ataque;
        cout << name << " ataco a " << enemigo.name << " e hizo " << ataque << " de dano, la vida restante de " << enemigo.name << " es " << enemigo.vida << endl;
    }

    enemigo.lastenemy= this;

    /*
        El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
        Existe un 20% de probabilidad de que el ataque falle y no haga daño.
        Se debe mostrar lo que pasó en cada ataque:
        nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
        nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
        El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
    */
    /*
    Nota:
        int x = rand() % 1000; asigna un valor aleatorio entre 0 y 999 a x;
        Puedes usar esto para la probabilidad del ataque.
    */
}