#include "PacMan.h"

PacMan::PacMan()
    :QPoint(0,0)
{
    setX(225);
    setY(225);
    char *Format=nullptr;
    setPacMa(QImage(":/PacMan/PacMan/Pacman/Pacman_Arriba.png",Format));
}

PacMan::PacMan(int x, int y)
    :QPoint(x, y)
{

}

int PacMan::getX() const
{
    return X;
}

void PacMan::setX(int value)
{
    X = value;
}

int PacMan::getY() const
{
    return Y;
}

void PacMan::setY(int value)
{
    Y = value;
}

int PacMan::subir()
{
    if(getY()>5 || getY()>6){
        char *Format=nullptr;
        setPacMa(QImage(":/PacMan/PacMan/Pacman/Pacman_Arriba.png",Format));
        return getY()-15;
    }
}

int PacMan::bajar()
{
    char *formato=nullptr;
    setPacMa(QImage(":/PacMan/PacMan/Pacman/Pacman_Frente.png",formato));

    if(getY()<400){
        return getY()+15;
    }else{
        return getY();
    }
}

int PacMan::derecha()
{
    char *formato=nullptr;
    setPacMa(QImage(":/PacMan/PacMan/Pacman/Pacman_Derecha.png",formato));
    if(getX()<400){
      return getX()+15;
    }else{
        return getX();
    }
}

int PacMan::izquierda()
{
    char *formato=nullptr;
    setPacMa(QImage(":/PacMan/PacMan/Pacman/Pacman_Izquierda.png",formato));
    if(getX()>6 || getX()>5){
        return getX()-15;
    }
}

const QImage &PacMan::getPacMa() const
{
    return PacMa;
}

void PacMan::setPacMa(const QImage &newSkin)
{
    PacMa = newSkin;
}

