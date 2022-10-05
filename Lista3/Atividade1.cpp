#include<Windows.h>
#include <GLFW/glfw3.h>
#include<gl/GLU.h>
#include<iostream>
#include "cores.h"



void redimensiona(int w, int h)
{
	glViewport(0, 0, w, h);

	float aspect = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);
}

void rect(float p1[3], float p2[3], float p3[3], float p4[3], color cor)
{
	glColor3fv(cor);
	glBegin(GL_QUADS);
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);
	glVertex3fv(p4);
	glEnd();

}
void desenhaCubo(float s) {
	float d = s / 2.0;
	float v1[3] = { -d,d,d };
	float v2[3] = { -d,-d,d };
	float v3[3] = { d,-d,d };
	float v4[3] = { d,d,d };



	//frente
	rect(v1, v2, v3, v4, vermelho);



}
void desenha()
{
	glLoadIdentity();
	glTranslated(0.0, 0.0, -50.0);
	glTranslated(0.0, 0.0, 0.0);
	glRotated(6.0, 1.0, 1.0, 1.0);
	glScaled(2.0, 1.0, 2.0);

	desenhaCubo(8.0);

	glLoadIdentity();
	glTranslated(0.0, 0.0, -50.0);
	glTranslated(20.0, 0.0, 0.0);
	desenhaCubo(8.0);


	glLoadIdentity();
	glTranslated(0.0, 0.0, -50.0);
	glTranslated(-20.0, 0.0, 0.0);
	glRotated(3.0, 1.0, 1.0, 1.0);
	glScaled(2.0, 3.0, 2.0);

	desenhaCubo(8.0);


	//glRotated(30.0,0.0,1.0,0.0);
	//glScaled(2.0,1.0,2.0);


}


int main(void)
{

	const int LARGURA = 800;
	const int ALTURA = 600;

	/* Initialize the library */
	glfwInit();

	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* window = glfwCreateWindow(LARGURA, ALTURA, "Desenha Quadrado", NULL, NULL);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// -- inicio
	glClearColor(0.0, 0.15, 0.25, 1.0); // cor de fundo
	glEnable(GL_DEPTH_TEST);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Poll for and process events */
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		int largura, altura;
		glfwGetFramebufferSize(window, &largura, &altura);

		redimensiona(largura, altura);

		desenha();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}