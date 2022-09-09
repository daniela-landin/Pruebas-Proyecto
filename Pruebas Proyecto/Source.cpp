#include <iostream>
#include<string>
#include <stdio.h>
#include <cstdio>
using namespace std;

struct admin {
	string usuario;
	string contraseña;
	string comercio;
	string nombre;
	string alias;
	admin* siguiente;
	admin* anterior;
};
admin* auxiliar_adm = nullptr;
admin* raiz_adm = nullptr;

struct cajero {
	string usuario;
	string contraseña;
	string comercio;
	string nombre;
	string alias;
	cajero* siguiente = nullptr;
	cajero* anterior = nullptr;
};
cajero* auxiliar_caj = nullptr;
cajero* raiz_caj = nullptr;

struct clientes {
	string nombre;
	string alias;
	string telefono;
	string email;
	string comercio;
	clientes* siguiente = nullptr;
	clientes* anterior = nullptr;
};
clientes* auxiliar_cli = nullptr;
clientes* raiz_cli = nullptr;

struct promos {
	string nombre;
	int monto;
	int porcentaje;
	bool estatus=false;
	promos* siguiente = nullptr;
	promos* anterior = nullptr;
};
promos* auxiliar_pro = nullptr;
promos* raiz_pro = nullptr;

struct consumos {
	string cliente;
	int monto;
	int subtotal;
	int descuento;
	int total;
	consumos* siguiente = nullptr;
	consumos* anterior = nullptr;
};
consumos* auxiliar_con = nullptr;
consumos* raiz_con = nullptr;

void agregar_adm(string, string, string, string, string);
void agregar_caj(string, string, string, string, string);
void agregar_cli(string, string, string, string, string);
void agregar_pro(string, int, int, bool);
void agregar_con(string, int, int, int, int);
admin* buscar_admin(string);
cajero* buscar_cajero(string);

void imprimir_adm(admin* auxiliar_adm)
{
	for (; auxiliar_adm; auxiliar_adm = auxiliar_adm->siguiente)
	{
		cout << auxiliar_adm->usuario << endl;
		cout << auxiliar_adm->contraseña << endl;
		cout << auxiliar_adm->comercio << endl;
		cout << auxiliar_adm->nombre << endl;
		cout << auxiliar_adm->alias << endl;
	}
}

void main() {
	string usuario_i, contraseña_i, comercio_i, nombre_i, alias_i;
	cout << "Usuario:" << endl;
	cin >> usuario_i;
	cout << "Contraseña:" << endl;
	cin >> contraseña_i;
	cout << "Comercio:" << endl;
	cin >> comercio_i;
	cout << "Alias:" << endl;
	cin >> alias_i;
	
	agregar_adm(usuario_i, contraseña_i, comercio_i, nombre_i, alias_i);
	imprimir_adm(auxiliar_adm);
	system("pause");
}

void agregar_adm(string usuario, string contraseña, string comercio, string nombre, string alias) {
	if (raiz_adm == nullptr) {
		raiz_adm = new admin;
		raiz_adm->usuario = usuario;
		raiz_adm->contraseña = contraseña;
		raiz_adm->comercio = comercio;
		raiz_adm->nombre = nombre;
		raiz_adm->alias = alias;
		raiz_caj->siguiente = nullptr;
		raiz_caj->anterior = nullptr;
		auxiliar_adm = raiz_adm;
	}
	else {
		auxiliar_adm = raiz_adm;
		while (auxiliar_adm->siguiente != nullptr) {
			auxiliar_adm = auxiliar_adm->siguiente;
		}
		auxiliar_adm->siguiente = new admin;
		auxiliar_adm->siguiente->siguiente = nullptr;
		auxiliar_adm = auxiliar_adm->siguiente;
		auxiliar_adm->usuario = usuario;
		auxiliar_adm->contraseña = contraseña;
		auxiliar_adm->comercio = comercio;
		auxiliar_adm->nombre = nombre;
		auxiliar_adm->alias = alias;
		
	}
}

void agregar_caj(string usuario, string contraseña, string comercio, string nombre, string alias) {
	if (raiz_caj == nullptr) {
		raiz_caj = new cajero;
		raiz_caj->usuario = usuario;
		raiz_caj->contraseña = contraseña;
		raiz_caj->comercio = comercio;
		raiz_caj->nombre = nombre;
		raiz_caj->alias = alias;
		raiz_caj->siguiente = nullptr;
		raiz_caj->anterior = nullptr;
		auxiliar_caj = raiz_caj;
	}
	else {
		auxiliar_caj = raiz_caj;
		while (auxiliar_caj->siguiente != nullptr) {
			auxiliar_caj = auxiliar_caj->siguiente;
		}
		auxiliar_caj->siguiente = new cajero;
		auxiliar_caj->siguiente->siguiente = nullptr;
		auxiliar_caj->siguiente->anterior = auxiliar_caj;
		auxiliar_caj = auxiliar_caj->siguiente;
		auxiliar_caj->usuario = usuario;
		auxiliar_caj->contraseña = contraseña;
		auxiliar_caj->comercio = comercio;
		auxiliar_caj->nombre = nombre;
		auxiliar_caj->alias = alias;
	}
}

void agregar_cli(string nombre, string alias, string telefono, string email, string comercio) {
	if (raiz_cli == nullptr) {
		raiz_cli = new clientes;
		raiz_cli->nombre = nombre;
		raiz_cli->alias = alias;
		raiz_cli->telefono = telefono;
		raiz_cli->email = email;
		raiz_cli->comercio = comercio;
		raiz_cli->siguiente = nullptr;
		raiz_cli->anterior = nullptr;
		auxiliar_cli = raiz_cli;
	}
	else {
		auxiliar_cli = raiz_cli;
		while (auxiliar_cli->siguiente != nullptr) {
			auxiliar_cli = auxiliar_cli->siguiente;
		}
		auxiliar_cli->siguiente = new clientes;
		auxiliar_cli->siguiente->siguiente = nullptr;
		auxiliar_cli->siguiente->anterior = auxiliar_cli;
		auxiliar_cli = auxiliar_cli->siguiente;
		auxiliar_cli->nombre = nombre;
		auxiliar_cli->alias = alias;
		auxiliar_cli->telefono = telefono;
		auxiliar_cli->email = email;
		auxiliar_cli->comercio = comercio;

	}
}

void agregar_pro(string nombre, int monto, int porcentaje, bool estatus) {
	if (raiz_pro == nullptr) {
		raiz_pro = new promos;
		raiz_pro->nombre = nombre;
		raiz_pro->monto = monto;
		raiz_pro->porcentaje = porcentaje;
		raiz_pro->estatus = estatus;
		raiz_pro->siguiente = nullptr;
		raiz_pro->anterior = nullptr;
		auxiliar_pro = raiz_pro;
	}
	else {
		auxiliar_pro = raiz_pro;
		while (auxiliar_pro->siguiente != nullptr) {
			auxiliar_pro = auxiliar_pro->siguiente;
		}
		auxiliar_pro->siguiente = new promos;
		auxiliar_pro->siguiente->siguiente = nullptr;
		auxiliar_pro->siguiente->anterior = auxiliar_pro;
		auxiliar_pro = auxiliar_pro->siguiente;
		auxiliar_pro->nombre = nombre;
		auxiliar_pro->monto = monto;
		auxiliar_pro->porcentaje = porcentaje;
		auxiliar_pro->estatus = estatus;
	}
}

void agregar_con(string cliente, int monto, int subtotal, int descuento, int total) {
	if (raiz_con == nullptr) {
		raiz_con = new consumos;
		raiz_con->cliente = cliente;
		raiz_con->monto = monto;
		raiz_con->subtotal = subtotal;
		raiz_con->descuento = descuento;
		raiz_con->total = total;
		raiz_con->siguiente = nullptr;
		raiz_con->anterior = nullptr;
		auxiliar_con = raiz_con;
	}
	else {
		auxiliar_con = raiz_con;
		while (auxiliar_con->siguiente != nullptr) {
			auxiliar_con = auxiliar_con->siguiente;
		}
		auxiliar_con->siguiente = new consumos;
		auxiliar_con->siguiente->siguiente = nullptr;
		auxiliar_con->siguiente->anterior = auxiliar_con;
		auxiliar_con = auxiliar_con->siguiente;
		auxiliar_con->cliente = cliente;
		auxiliar_con->monto = monto;
		auxiliar_con->subtotal = subtotal;
		auxiliar_con->descuento = descuento;
		auxiliar_con->total = total;
	}
}



/*
admin* buscar_admin(string buscar_usuario)
{
	if (raiz_adm == nullptr)
	{
		return;
	}

	auxiliar_adm = raiz_adm;
	if (auxiliar_adm->usuario == buscar_usuario)
	{
		raiz_adm = raiz_adm->siguiente;
		raiz_adm->anterior = nullptr;
		return auxiliar_adm;
	}
	else
	{
		while (auxiliar_adm != nullptr && auxiliar_adm->usuario != buscar_usuario)
		{
			auxiliar_adm = auxiliar_adm->siguiente;
		}

		if (auxiliar_adm != nullptr)
		{
			if (auxiliar_adm->usuario == buscar_usuario)
			{

				admin* temporal = auxiliar_adm;
				temporal->anterior->siguiente = temporal->siguiente;
				if (temporal->siguiente != nullptr)
				{
					temporal->siguiente->anterior = temporal->anterior;
				}
				return temporal;
			}
		}
	}
}

cajero* buscar_cajero(string buscar_usuario)
{
	if (raiz_caj == nullptr)
	{
		return;
	}

	auxiliar_caj = raiz_caj;
	if (auxiliar_caj->usuario == buscar_usuario)
	{
		raiz_caj = raiz_caj->siguiente;
		raiz_caj->anterior = nullptr;
		return auxiliar_caj;
	}
	else
	{
		while (auxiliar_caj != nullptr && auxiliar_caj->usuario != buscar_usuario)
		{
			auxiliar_caj = auxiliar_caj->siguiente;
		}

		if (auxiliar_caj != nullptr)
		{
			if (auxiliar_caj->usuario == buscar_usuario)
			{

				cajero* temporal = auxiliar_caj;
				temporal->anterior->siguiente = temporal->siguiente;
				if (temporal->siguiente != nullptr)
				{
					temporal->siguiente->anterior = temporal->anterior;
				}
				return temporal;
			}
		}
	}
}

*/







