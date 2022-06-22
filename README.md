## Integrantes
Rayana, Mateus Weber e Mateus de Souza

## Compilando
- Instalar dependências (usando Homebrew ou vcpkg, por exemplo):
    - glm
    - glfw
    - assimp

- Instalar Cmake

- Rodar o CMake para gerar os Makefiles:
    ```
    $ cmake .
    ```

- Compilar a aplicação:
    ```
    $ make
    ```

- Executar programa:
    ```
    $ ./app
    ```

## Controles

- Teclas W, S, A, D: Movimentam a câmera pra frente, para trás, para esquerda e direita, respectivamente.
- Teclas R, T: Selecionam o tipo de movimento (rotação ou translação).
- Tecla E: Altera escala do objeto.
- Teclas I, U: Para o movimento de translação, essas teclas alteram a direção do movimento. Para a escala, essas teclas aumentam ou diminuem o tamanho.
- Teclas X, Y, Z: Permitem a rotação ou translação do objeto nos eixos X, Y e Z.
- Arrastar com o mouse: Movimenta a câmera.
- Scroll do mouse: Aumenta ou diminui o zoom.
- Seta para direita: Muda o objeto selecionado.
