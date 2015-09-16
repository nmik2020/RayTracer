#pragma once
#include "xmlload.h"
#include "scene.h"
#include "objects.h"
#include <stdlib.h>
#include "GL\glut.h"
#include <time.h>

extern Node rootNode;
extern Camera camera;
extern RenderImage renderImage;
//-------------------------------------------------------------------------------
void showDefault();
void BeginRender();	// Called to start rendering (renderer must run in a separate thread)
void StopRender();	// Called to end rendering (if it is not already finished)
//-------------------------------------------------------------------------------
void GlutDisplay();
void GlutReshape(int w, int h);
void GlutIdle();
void GlutKeyboard(unsigned char key, int x, int y);
void GlutMouse(int button, int state, int x, int y);
void GlutMotion(int x, int y);
