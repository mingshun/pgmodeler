/*
# Projeto: Modelador de Banco de Dados PostgreSQL (pgModeler)
# Sub-projeto: Biblioteca libpgsqldbm_ui
# Classe: ConversaoCodificacaoWidget
# Descrição: Definição da classe que implementa o formulário de
#            edição dos atributos de conversão de codificação.
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
#ifndef CONVERSAOCODIFICACAO_WIDGET_H
#define CONVERSAOCODIFICACAO_WIDGET_H

#include "objetobasewidget.h"
#include "ui_conversaocodificacaowidget.h"
//***********************************************************
class ConversaoCodificacaoWidget: public ObjetoBaseWidget, public Ui::ConversaoCodificacaoWidget {
 Q_OBJECT

 private:
   //Widget seletor da função de conversão
   SeletorObjetoWidget *sel_funcao_conv;

 public:
   ConversaoCodificacaoWidget(QWidget * parent = 0);
   void definirAtributos(ModeloBD *modelo, ListaOperacoes *lista_op, ConversaoCodificacao *conv_cod);

 private slots:
   void hideEvent(QHideEvent *);

 public slots:
   void aplicarConfiguracao(void);
};
//***********************************************************
#endif
