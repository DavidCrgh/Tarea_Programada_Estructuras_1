#include "ventanahorno.h"
#include "ui_ventanahorno.h"

VentanaHorno::VentanaHorno(QWidget *parent, Simulacion* pSimulacion) :
    QMainWindow(parent),
    ui(new Ui::VentanaHorno)
{
    ui->setupUi(this);
    simulacion = pSimulacion;
    horno = simulacion->horno;
    for(int i = 0; i < 6; i++){
        ventanasBandeja[i] = new VentanaBandeja(NULL, horno->bandejas[i]);
    }
}

VentanaHorno::~VentanaHorno()
{
    delete ui;
}

void VentanaHorno::actualizarVentana(){
    ui->encendido->setChecked(!(simulacion->hiloHorno->pause));
    ui->apagado->setChecked(simulacion->hiloHorno->pause);
    ui->checkBandeja1->setChecked(!(simulacion->hilosBandeja[0]->pause));
    ui->checkBandeja2->setChecked(!(simulacion->hilosBandeja[1]->pause));
    ui->checkBandeja3->setChecked(!(simulacion->hilosBandeja[2]->pause));
    ui->checkBandeja4->setChecked(!(simulacion->hilosBandeja[3]->pause));
    ui->checkBandeja5->setChecked(!(simulacion->hilosBandeja[4]->pause));
    ui->checkBandeja6->setChecked(!(simulacion->hilosBandeja[5]->pause));
}

void VentanaHorno::toggleVentana(bool encender){
    ui->checkBandeja3->setEnabled(encender);
    ui->checkBandeja4->setEnabled(encender);
    ui->checkBandeja5->setEnabled(encender);
    ui->checkBandeja6->setEnabled(encender);
    ui->checkBandeja1->setChecked(encender);
    ui->checkBandeja2->setChecked(encender);
    ui->checkBandeja3->setChecked(encender);
    ui->checkBandeja4->setChecked(encender);
    ui->checkBandeja5->setChecked(encender);
    ui->checkBandeja6->setChecked(encender);
    simulacion->hiloHorno->pause = !encender;
}

void VentanaHorno::on_encendido_clicked()
{
    toggleVentana(true);
}

void VentanaHorno::on_apagado_clicked()
{
    toggleVentana(false);
}

void VentanaHorno::on_configurarBandeja1_clicked()
{
    ventanasBandeja[0]->show();
}

void VentanaHorno::on_configurarBandeja2_clicked()
{
    ventanasBandeja[1]->show();
}

void VentanaHorno::on_configurarBandeja3_clicked()
{
    ventanasBandeja[2]->show();
}

void VentanaHorno::on_configurarBandeja4_clicked()
{
    ventanasBandeja[3]->show();
}

void VentanaHorno::on_configurarBandeja5_clicked()
{
    ventanasBandeja[4]->show();
}

void VentanaHorno::on_configurarBandeja6_clicked()
{
    ventanasBandeja[5]->show();
}

void VentanaHorno::on_checkBandeja1_toggled(bool checked)
{
    if(checked){
        horno->bandejas[0]->estaActiva = true;
        simulacion->hilosBandeja[0]->pause = false;
    }
   else{
        horno->bandejas[0]->estaActiva = false;
        simulacion->hilosBandeja[0]->pause = true;
    }
}

void VentanaHorno::on_checkBandeja2_toggled(bool checked)
{
    if(checked){
        horno->bandejas[1]->estaActiva = true;
        simulacion->hilosBandeja[1]->pause = false;
    }
   else{
        horno->bandejas[1]->estaActiva = false;
        simulacion->hilosBandeja[1]->pause = true;
    }
}

void VentanaHorno::on_checkBandeja3_toggled(bool checked)
{
    if(checked){
        horno->bandejas[2]->estaActiva = true;
        simulacion->hilosBandeja[2]->pause = false;
    }
   else{
        horno->bandejas[2]->estaActiva = false;
        simulacion->hilosBandeja[2]->pause = true;
    }
}

void VentanaHorno::on_checkBandeja4_toggled(bool checked)
{
    if(checked){
        horno->bandejas[3]->estaActiva = true;
        simulacion->hilosBandeja[3]->pause = false;
    }
   else{
        horno->bandejas[3]->estaActiva = false;
        simulacion->hilosBandeja[3]->pause = true;
    }
}

void VentanaHorno::on_checkBandeja5_toggled(bool checked)
{
    if(checked){
        horno->bandejas[4]->estaActiva = true;
        simulacion->hilosBandeja[4]->pause = false;
    }
   else{
        horno->bandejas[4]->estaActiva = false;
        simulacion->hilosBandeja[4]->pause = true;
    }
}

void VentanaHorno::on_checkBandeja6_toggled(bool checked)
{
    if(checked){
        horno->bandejas[5]->estaActiva = true;
        simulacion->hilosBandeja[5]->pause = false;
    }
   else{
        horno->bandejas[5]->estaActiva = false;
        simulacion->hilosBandeja[5]->pause = true;
    }
}

void VentanaHorno::resetearVentana(){
    ui->checkBandeja1->setEnabled(false);
    ui->checkBandeja2->setEnabled(false);
    ui->checkBandeja3->setEnabled(false);
    ui->checkBandeja4->setEnabled(false);
    ui->checkBandeja5->setEnabled(false);
    ui->checkBandeja6->setEnabled(false);
}
