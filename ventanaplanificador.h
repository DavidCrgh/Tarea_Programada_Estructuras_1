#ifndef VENTANAPLANIFICADOR_H
#define VENTANAPLANIFICADOR_H

#include <QWidget>

#include "empacadora.h"
#include "almacenterminal.h"
#include "ventanapaquete.h"

namespace Ui {
class VentanaPlanificador;
}

class VentanaPlanificador : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaPlanificador(QWidget *parent = 0, ListaGalletas* pLista = 0, Empacadora* pEmpacadora = 0,
                                 AlmacenTerminal* pAlmacen = 0);
    ~VentanaPlanificador();


signals:
    void inicializarCarritos();

public slots:
    void on_agregar_clicked();

    void actualizarVentana();

    void on_cancelar_clicked();

    void resetearVentana();

private slots:
    void on_barraProbabilidades_valueChanged(int value);

    void on_limpiar_clicked();

    void on_aceptar_clicked();

private:
    Ui::VentanaPlanificador *ui;
    ListaGalletas* listaGalletas;
    Empacadora* empacadora;
    AlmacenTerminal* almacen;
    VentanaPaquete* ventanaPaquete;
};

#endif // VENTANAPLANIFICADOR_H
