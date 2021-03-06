/*
# Projeto: Modelador de Banco de Dados PostgreSQL (pgModeler)
# Sub-projeto: Biblioteca núcleo libpgsqldbm
# Descrição:  Definição da classe domínio que é usada para
#             gerar os códigos SQL pertinentes a estes.
# Data de Criação: 07/04/2008
#
# Copyright 2006-2012 - Raphael Araújo e Silva <rkhaotix@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/
#ifndef DOMINIO_H
#define DOMINIO_H

#include "objetobase.h"
#include "esquema.h"
//***********************************************************
class Dominio: public ObjetoBase{
 private:
  //Nome da constraint usada no domínio
  QString nome_rest,
         //Expressão de validação (check) da constraint
         expressao,
         //Valor padrão do domínio
         valor_padrao;

  /* Indica se o domínio tem seu valor de
     preenchimento obrigatório */
  bool nao_nulo;

  //Tipo do domínio
  TipoPgSQL tipo;

 public:
  Dominio(void);
  ~Dominio(void);

  //Define o nome da constraint do domínio
  void definirNomeRestricao(const QString &nome_constr);

  //Define a expressão de checagem do domínio
  void definirExpressao(const QString &expressao);

  //Define o valor padrão do domínio
  void definirValorPadrao(const QString &valor_padrao);

  //Define se o domínio aceita valores nulos
  void definirNaoNulo(bool valor);

  //Define o tipo do domínio
  void definirTipo(TipoPgSQL tipo);

  void definirNome(const QString &nome);
  void definirEsquema(ObjetoBase *esquema);

  //Métodos de obtenção dos valores dos atributos
  QString obterNomeRestricao(void);
  QString obterExpressao(void);
  QString obterValorPadrao(void);
  bool naoNulo(void);
  TipoPgSQL obterTipo(void);

  //Retorna a definição SQL ou XML do objeto
  QString obterDefinicaoObjeto(unsigned tipo_def);

  void operator = (Dominio &dominio);
};
//***********************************************************
#endif
