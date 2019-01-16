/*
 * ContasPoupanca.h
 *
 *  Created on: 20 de Fev de 2014
 *      Author: escarvalho
 */

#ifndef CONTASPOUPANCA_H_
#define CONTASPOUPANCA_H_

#include "ContasBancarias.h"

namespace std {

class ContasPoupanca: public std::ContasBancarias {
private:
	int diaJuros; // atributo para conter o dia dos juros
public:
	ContasPoupanca();
	virtual ~ContasPoupanca();
	int getDiaJuros() { return diaJuros; };
	void setDiaJuros(int d) { diaJuros = d; };
	void rendimentoMensal(float);
};

} /* namespace std */
#endif /* CONTASPOUPANCA_H_ */
