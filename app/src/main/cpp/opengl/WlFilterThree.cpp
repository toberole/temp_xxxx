#include "WlFilterThree.h"
#include "../shaderutil/WlShaderUtil.h"
#include "../matrix/MatrixUtil.h"

WlFilterThree::WlFilterThree() {

}

WlFilterThree::~WlFilterThree() {

}

void WlFilterThree::setPilex(void *data, int width, int height, int length) {

}

void WlFilterThree::setYuvData(void *y, void *u, void *v, int width, int height) {}


void WlFilterThree::destorySorce() {

}

void WlFilterThree::onChange(int width, int height) {
    surface_width = width;
    surface_height = height;
    glViewport(0, 0, width, height);
    setMatrix(width, height);
}

void WlFilterThree::onCreate() {
    // uniform 变量不使用可能被优化掉
    vertex = "attribute vec4 a_Position;\n"
             "void main(){\n"
             "    gl_Position = a_Position;\n"
             "}";

    // 坐标值加f有问题 坑爹啊
    fragment = "void main() {\n"
               "    gl_FragColor = vec4(1.0, 0.0, 0.0, 0.0);\n"
               "}";

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    program = createProgrm(vertex, fragment, &vShader, &fShader);
    LOGE("opengl WlFilterThree program is %d %d %d", program, vShader, fShader);
    vPosition = glGetAttribLocation(program, "a_Position");//顶点坐标
    LOGE("opengl WlFilterThree vPosition: %d,u_matrix: %d,u_Color: %d", vPosition, u_matrix,
         u_Color);
//    GLfloat color_data[] = {1.0f, 0.0f, 0.0f, 1.0f};
//    glUniform4fv(u_Color, 1, color_data);

}

void WlFilterThree::draw() {
    glUseProgram(program);

//    glUniformMatrix4fv(u_matrix, 1, GL_FALSE, matrix);

    GLfloat vert_data[] = {
            -1.0f, -1.0f,
            0.0f, 1.0f,
            1.0f, -1.0f
    };
    vertexs = vert_data;

    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, false, 0, vertexs);

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void WlFilterThree::setMatrix(int width, int height) {
    initMatrix(matrix);
    float screen_r = 1.0 * width / height;
    float picture_r = 1.0 * w / h;
    if (screen_r > picture_r) //图片宽度缩放
    {
        float r = width / (1.0 * height / h * w);
        orthoM(-r, r, -1, 1, matrix);
    } else {//图片高度缩放
        float r = height / (1.0 * width / w * h);
        orthoM(-1, 1, -r, r, matrix);
    }
}


void WlFilterThree::destroy() {}