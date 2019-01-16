/*
 * ContasBancarias.h
 *
 *  Created on: 20 de Fev de 2014
 *      Author: escarvalho
 */

#ifndef CONTASBANCARIAS_H_
#define CONTASBANCARIAS_H_

#include <iostream>
#include <ctime>
#include <list>
#include <cmath>

namespace std {

class ContasBancarias {
private:
	string cliente;
	int numConta;
	float saldo;
	struct tm *agora;
	struct extratos {
		int dia;
		int mes;
		int ano;
		float movimento;
		string tipo;
	};
	list<extratos> movimentos;
	list<extratos>::iterator it;
public:
	ContasBancarias();
	virtual ~ContasBancarias();
	string getCliente() { return cliente; };
	int getNumConta() { return numConta; };
	float getSaldo() { return saldo; };
	struct tm* getAgora() { return agora; };
	void setCliente(string c) { cliente = c; };
	void setNumConta(int n) { numConta = n; };
	void setSaldo(float s) { saldo = s; };
	void setAgora(struct tm* a) { agora = a; };
	virtual void sacar(float); // declarada como virtual, causa "late binding"
	void depositar(float);
	virtual void extrato(); // declarada como virtual, causa "late binding"
	void atualizaExtrato(float, string);
};

} /* namespace std */
#endif /* CONTASBANCARIAS_H_ */
