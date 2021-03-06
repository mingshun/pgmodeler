#include "dummyplugin.h"
#include "excecao.h"
#include "caixamensagem.h"
//***********************************************************
DummyPlugin::DummyPlugin(void)
{
 QTranslator *tradutor=new QTranslator;

 tradutor->load(QString("dummyplugin.") + QLocale::system().name(),
                AtributosGlobais::DIR_PLUGINS +
                AtributosGlobais::SEP_DIRETORIO +
                QString("dummyplugin") +
                AtributosGlobais::SEP_DIRETORIO +
                QString("lang"));

 QCoreApplication::installTranslator(tradutor);
}
//-----------------------------------------------------------
QString DummyPlugin::obterRotuloPlugin(void)
{
 return(trUtf8("Dummy Plugin"));
}
//-----------------------------------------------------------
void DummyPlugin::executarPlugin(ModeloWidget *modelo)
{
 CaixaMensagem caixa_msg;
 caixa_msg.show(trUtf8("Plugin Carregado!"),
                trUtf8("Plugin carregado com sucesso! Para detalhes de como criar seus próprios plugins consulte o arquivo PLUGINS.md"),
                CaixaMensagem::ICONE_INFO);
}
//***********************************************************
Q_EXPORT_PLUGIN2(dummyplugin, DummyPlugin)
