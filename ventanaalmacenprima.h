#ifndef VENTANAALMACENPRIMA_H
#define VENTANAALMACENPRIMA_H

#include <QMainWindow>

#include "almacenprima.h"

namespace Ui {
class VentanaAlmacenPrima;
}

class VentanaAlmacenPrima : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaAlmacenPrima(QWidget *parent = 0, AlmacenPrima* pAlmacen = 0);
    ~VentanaAlmacenPrima();

public slots:
    void actualizarVentana(QStringList pMensaje);

public:
    Ui::VentanaAlmacenPrima *ui;
    AlmacenPrima* almacen;
};

#endif // VENTANAALMACENPRIMA_H
