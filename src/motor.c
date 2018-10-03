/*
 * motor.c
 *
 *  Created on: 12 de set. de 2018
 *      Author: grama
 */


#include <motor.h>
#include <board.h>

int cuentapasos;

void initMotores()
{
	motor[0].stepPort = M0STEPport;
	motor[0].stepPin = M0STEPpin;
	motor[0].dirPort = M0STEPport;
	motor[0].dirPin = M0STEPpin;

	motor[1].stepPort = M1STEPport;
	motor[1].stepPin = M1STEPpin;
	motor[1].dirPort = M1STEPport;
	motor[1].dirPin = M1STEPpin;

	Chip_GPIO_SetPinDIROutput(LPC_GPIO, motor[0].stepPort, motor[0].stepPin);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, motor[0].dirPort, motor[0].dirPin);

	Chip_GPIO_SetPinDIROutput(LPC_GPIO, motor[1].stepPort, motor[1].stepPin);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, motor[1].dirPort, motor[1].dirPin);
}

//ACA TE DAS CUENTA QUE ES MEJOR USAR UNA ESTRUCTURA DE PINES STEP Y DIR DE MOTOR
//PARA HACER UNA SOLA FUNCION DOSTEPS QUE LE MANDAS EL MOTOR QUE QUERES QUE SE MUEVA. SALU2

//ESTO PARA MI DEBERIA SER UNA TAREA PARA QUE SE PUEDA BLOQUEAR PARA PARAR EL GIRO
void doSteps(typedef_motor m, int dir, int n)
{
	Chip_GPIO_SetPinState(LPC_GPIO, m.dirPort, m.dirPin, dir);

}

//IMPLEMENTACIÓN DE FUNCIONES PARA EL MOTOR QUE REPARTE EN VASOS

void configVaso(int vasoColor, int grados, int dir)
{
	vaso[vasoColor].grados = grados;
	vaso[vasoColor].dir = dir;
}

void moverAvaso(int vasoColor)
{

}

//IMPLEMENTACIÓN DE FUNCIONES PARA EL MOTOR QUE SENSA PASTILLAS

void configPosSensor(int grados, int dir)
{
	sensor.grados = grados;
	sensor.dir = dir;
}

void moverAsensor()
{

}
