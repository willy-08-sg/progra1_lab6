#include "stdafx.h"
#include "lab6.h"
#include <QPushButton> 
#include <QString> 

lab6::lab6(QWidget *parent)
    : QMainWindow(parent)
{


    ui.setupUi(this);

    connect(ui.btnCalcular, &QPushButton::clicked,
        this, &lab6::calcularTotal);

    connect(ui.btnLimpiar, &QPushButton::clicked,
        this, &lab6::limpiarFormulario);
}

lab6::~lab6()
{}

void lab6::calcularTotal()
{
    double precio = ui.spnPrecio->value();
    int cantidad = ui.spnCantidad->value();
    double total = precio * cantidad;

    ui.lblTotal->setText(
        QString("Total: CRC %1").arg(total, 0, 'f', 2)
    );
}

void lab6::limpiarFormulario()
{
    ui.spnPrecio->setValue(0);
    ui.spnCantidad->setValue(1);
    ui.lblTotal->setText("Total: CRC 0.00");
    ui.spnPrecio->setFocus();

}

