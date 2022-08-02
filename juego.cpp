#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
    lienzo = QPixmap(500,500);
    ui->outMovements->setPixmap(lienzo);
    QPoint centro = ui->outMovements->geometry().center();
    m_Pacman = new PacMan();
    this->dibujar();
    mMediaPlayer->setMedia(QUrl("qrc:/PacMan/PacMan/Pac-man theme remix - By Arsenic1987.mp3"));
    ui->horizontalSlider->setValue(10);
    mMediaPlayer->play();
}

Juego::~Juego()
{
    delete ui;
}
void Juego::dibujar()
{
    lienzo.fill(Qt::black);
    QPainter painter(&lienzo);
    painter.drawImage(m_Pacman->getX(),m_Pacman->getY(),m_Pacman->getPacMa());
}

void Juego::paintEvent(QPaintEvent *event)
{
    ui->outMovements->setPixmap(lienzo);
}


void Juego::on_horizontalSlider_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}

void Juego::on_btnArriba_released()
{
    m_Pacman->setY(m_Pacman->subir());
    dibujar();
}


void Juego::on_btnAbajo_released()
{
    m_Pacman->setY(m_Pacman->bajar());
    dibujar();
}

void Juego::on_btnIzqueirda_released()
{
    m_Pacman->setX(m_Pacman->izquierda());
    dibujar();
}


void Juego::on_btnDerecha_released()
{
    m_Pacman->setX(m_Pacman->derecha());
    dibujar();
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::keyPressEvent(QKeyEvent *e)
{
    if(e->key()=='8'){
        on_btnArriba_released();
    }else if(e->key()=='4'){
        on_btnIzqueirda_released();
    }else if(e->key()=='6'){
        on_btnDerecha_released();
    }else if(e->key()=='5'){
        on_btnAbajo_released();
    }
}

