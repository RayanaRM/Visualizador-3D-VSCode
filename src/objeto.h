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
    glm::vec3 positionTranslate;
    float lightColor[3];
    float lightPosition[3];
    std::string path;

    // constructor with vectors
    Objeto(int id, bool isSelected, bool hasCurves, float escala, glm::vec3 positionTranslate, std::string path, float lightColor[], float lightPosition[])
    {
        this->id = id;
        this->isSelected = isSelected;
        this->hasCurves = hasCurves;
        this->escala = escala;
        this->positionTranslate = positionTranslate;
        this->path = path;

        this->lightColor[0] = lightColor[0];
        this->lightColor[1] = lightColor[1];
        this->lightColor[2] = lightColor[2];
        
        this->lightPosition[0] = lightPosition[0];
        this->lightPosition[1] = lightPosition[1];
        this->lightPosition[2] = lightPosition[2];

    }
};
#endif