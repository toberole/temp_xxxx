#ifndef NATIVEOPENGLDEMO_WLFILTERTHREE_H
#define NATIVEOPENGLDEMO_WLFILTERTHREE_H

#include "WlBaseOpengl.h"
#include "GLES2/gl2.h"

class WlFilterThree: public WlBaseOpengl {
public:
    GLint vPosition;
    GLint u_matrix;
    GLint u_Color;

    int w;
    int h;
    float matrix[16];

    GLuint *v_shader;
    GLuint *f_shader;

public:

    WlFilterThree();
    ~WlFilterThree();

    void onCreate();

    void onChange(int w, int h);

    void draw();

    void destroy();

    void destorySorce();

    void setMatrix(int width, int height);

    void setPilex(void *data, int width, int height, int length);
    virtual void setYuvData(void *y, void *u, void *v, int width, int height);


};


#endif //NATIVEOPENGLDEMO_WLFILTERTHREE_H
