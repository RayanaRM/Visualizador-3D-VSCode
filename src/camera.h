#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

enum KEY_INPUTS {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    X,
    Y,
    Z,
    TRANSLACAO,
    ROTACAO,
    I,
    U,
    ESCALA
};

// Default para camera
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 20.0f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


class Camera
{
public:
    // camera Attributes for object One
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    glm::vec3 axis = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 positionTranslate = glm::vec3(0.0f, 0.0f, 0.0f);
    float angle = 1.0f;

    // camera Attributes for object Two
    glm::vec3 Position1;
    glm::vec3 Front1;
    glm::vec3 Up1;
    glm::vec3 Right1;
    glm::vec3 WorldUp1;
    glm::vec3 axis1 = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 positionTranslate1 = glm::vec3(0.0f, 0.0f, 0.0f);
    float angle1 = 1.0f;

    // euler Angles for 
    float Yaw;
    float Pitch;

    // euler Angles
    float Yaw1;
    float Pitch1;

    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // variaveis de controle
    float escala = 0.1f;

    float escala1 = 0.1f;

    float type;
    float inc;

    // constructor with vectors
    Camera(glm::vec3 position, glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), Front1(glm::vec3(0.0f, 0.0f, 1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;

        Position1 = glm::vec3(10.0f, 0.0f, 15.0f);
        WorldUp1 = up;
        Yaw1 = yaw;
        Pitch1 = pitch;
        updateCameraVectors();
    }

    glm::mat4 GetViewMatrix()
    {     
        return glm::lookAt(Position, Position + Front, Up);
    }

    glm::mat4 GetModelMatrix(glm::mat4 model)
    {
        model = glm::rotate(model, angle, axis);
        model = glm::translate(model, positionTranslate);
        model = glm::scale(model, glm::vec3(escala, escala, escala));
        return model;
    }

    glm::mat4 GetViewMatrix2()
    {     
        return glm::lookAt(Position1, Position1 + Front1, Up1);
    }

    glm::mat4 GetModelMatrix2(glm::mat4 model)
    {
        model = glm::rotate(model, angle1, axis1);
        model = glm::translate(model, positionTranslate1);
        model = glm::scale(model, glm::vec3(escala1, escala1, escala1));
        return model;
    }

    void ProcessKeyboard(KEY_INPUTS key, float deltaTime, bool isSelected1, bool isSelected2)
    {
        float velocity = MovementSpeed * deltaTime;

        // Teclas de controle (rota��o/ transla��o)
        if (key == TRANSLACAO) {
            type = 1;
        }
        if (key == ROTACAO) {
            type = 2;
        }

        // Teclas de controle (incrementa/ decrementa)
        if (key == I) {
            inc = 1;
        }
        if (key == U) {
            inc = 0;
        }

        // movimentacao da camera
        if (key == FORWARD){
            if(isSelected1)
                Position += Front * velocity;
            if(isSelected2)
                Position1 += Front1 * velocity;
        }
        if (key == BACKWARD){
            if(isSelected1)
                Position -= Front * velocity;
            if(isSelected2)
                Position1 -= Front1 * velocity;
        }
        if (key == LEFT){
            if(isSelected1)
                Position -= Right * velocity;
            if(isSelected2)
                Position1 -= Right1 * velocity;
        }
        if (key == RIGHT){
            if(isSelected1)
                Position += Right * velocity;
            if(isSelected2)
                Position1 += Right1 * velocity;
        }
        // Rota��o
        if (key == X  && type == 2) {
            if(isSelected1){
                angle = (GLfloat)glfwGetTime();
                axis = glm::vec3(1.0f, 0.0f, 0.0f);
            }
            if(isSelected2){
                angle1 = (GLfloat)glfwGetTime();
                axis1 = glm::vec3(1.0f, 0.0f, 0.0f);
            }
        }
        if (key == Y && type == 2) {
            if(isSelected1){
                angle = (GLfloat)glfwGetTime();
                axis = glm::vec3(0.0f, 1.0f, 0.0f);
            }
            if(isSelected2){
                angle1 = (GLfloat)glfwGetTime();
                axis1 = glm::vec3(0.0f, 1.0f, 0.0f);
            }
        }
        if (key == Z && type == 2) {
            if(isSelected1){
                angle = (GLfloat)glfwGetTime();
                axis = glm::vec3(0.0f, 0.0f, 1.0f);
            }
            if(isSelected2){
                angle1 = (GLfloat)glfwGetTime();
                axis1 = glm::vec3(0.0f, 0.0f, 1.0f);
            }

        }

        // Transla��o
        if (key == X && type == 1) {
            positionTranslate[0] += inc == 1 ? 0.01 : -0.01;
        }
        if (key == Y && type == 1) {
            positionTranslate[1] += inc == 1 ? 0.01 : -0.01;
        }
        if (key == Z && type == 1) {
            positionTranslate[2] += inc == 1 ? 0.01 : -0.01;
        }

        // escala
        if (key == ESCALA) {
            escala += inc == 1 ? 0.0005f : -0.0005f;
            if (escala > 1.0f)  
                escala = 1.0f;
            else if (escala < 0.01f)
                escala = 0.01f;
        }
    }

    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;

        // faz update nos vetores Front, Right e Up
        updateCameraVectors();
    }

    // controle de zoom com scroll
    void ProcessMouseScroll(float yoffset)
    {
        Zoom -= (float)yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }

private:
    void updateCameraVectors()
    {
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

        Front = glm::normalize(front);
        Right = glm::normalize(glm::cross(Front, WorldUp));
        Up = glm::normalize(glm::cross(Right, Front));

        Front1 = glm::normalize(front);
        Right1 = glm::normalize(glm::cross(Front1, WorldUp));
        Up1 = glm::normalize(glm::cross(Right1, Front1));
    }
};
#endif