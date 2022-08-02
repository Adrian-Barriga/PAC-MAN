#ifndef PACMAN_H
#define PACMAN_H

#include <QPoint>
#include <QPainter>

class PacMan : public QPoint
{
public:
    PacMan();
    PacMan(int xpos, int ypos);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int subir();
    int bajar();
    int derecha();
    int izquierda();

    const QImage &getPacMa() const;
    void setPacMa(const QImage &newSkin);

private:
    int X;
    int Y;
    QImage PacMa;
};

#endif // PACMAN_H
