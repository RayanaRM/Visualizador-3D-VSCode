#ifndef OBJETO_H
#define OBJETO_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "camera.h"
#include <vector>


class Objeto
{
public:
    bool isSelected;
    int id;
    bool hasCurves;
    float escala;

    // constructor with vectors
    Objeto(int id, bool isSelected, bool hasCurves, float escala)
    {
        this->id = id;
        this->isSelected = isSelected;
        this->hasCurves = hasCurves;
        this->escala = escala;
    }
};
#endif