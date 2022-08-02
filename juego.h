/*Universidad Politécnica Salesiana
 * Nombre: Adrian Fernando Barriga Castillo
 * Asignatura: Programacion Orientada a Objetos
 * Actividad de recuperacion*/

#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <QDebug>
#include <QPen>
#include <QPoint>
#include <QPainter>
#include <QKeyEvent>
#include <QMediaPlayer>
#include "PacMan.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Juego; }
QT_END_NAMESPACE

class QMediaPlayer;

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    Juego(QWidget *parent = nullptr);
    ~Juego();

private slots:
    void on_btnArriba_released();

    void on_btnAbajo_released();

    void on_btnIzqueirda_released();

    void on_btnDerecha_released();

    void on_actionSalir_triggered();

    void on_horizontalSlider_valueChanged(int value);

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::Juego *ui;
    QPainter painter;
    QImage *mImagen;
    QPixmap lienzo;
    PacMan *m_Pacman;
    QMediaPlayer  *mMediaPlayer;
    void dibujar();
    void paintEvent(QPaintEvent *event) override;
};
#endif // JUEGO_H
