/*
# Projeto: Modelador de Banco de Dados PostgreSQL (pgModeler)
# Sub-projeto: Biblioteca libpgsqldbm_ui
# Classe: RestricaoWidget
# Descrição: Definição da classe que implementa o formulário de
#            edição dos atributos de índices.
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
#ifndef INDICE_WIDGET_H
#define INDICE_WIDGET_H

#include "objetobasewidget.h"
#include "ui_indicewidget.h"
#include "tabelaobjetoswidget.h"

/* Declarando a classe ElementoIndice como metatype para que esta
 possa ser usada em conjunto com a classe QVariant (vide documentação
 da classe QVariant e QMetaType). Esta declaração é uma macro específica
 do Qt e está sendo usada para facilitar o uso com classes que necessitam
 armazenar instancias de classes em seus containeres (TabelaObjetosWidget).
 Essa declaração não afeta o comportamento das demais classes que de algum
 modo referenciam a classe ElementoIndice.*/
#include <QMetaType>
Q_DECLARE_METATYPE(ElementoIndice);
//***********************************************************
class IndiceWidget: public ObjetoBaseWidget, public Ui::IndiceWidget {
 Q_OBJECT

 private:
   //Destaque de sintaxe do campo de expressão condicional
   DestaqueSintaxe *dest_exp_condicional,
                   *dest_exp_elemento;

   //Tabelas de objetos para controlar elementos do índice
   TabelaObjetosWidget *tab_elementos;

   //Seletor de classe de operadores dos elementos
   SeletorObjetoWidget *sel_classe_op;

   //Atualiza o combo de colunas com as existentes na tabela
   void atualizarComboColunas(void);

   //Exibe o dado de um elemento na linha especificada da tabela
   void exibirDadosElemento(ElementoIndice elem, int idx_elem);

 public:
   IndiceWidget(QWidget * parent = 0);
   void definirAtributos(ModeloBD *modelo, Tabela *tabela_pai, ListaOperacoes *lista_op, Indice *indice);

 private slots:
  void hideEvent(QHideEvent *);
  void selecionarObjetoElemento(void);

  //Métodos de manipulação dos elementos do índice
  void manipularElemento(int idx_elem);
  void editarElemento(int idx_elem);

 public slots:
   void aplicarConfiguracao(void);
};
//***********************************************************
#endif
