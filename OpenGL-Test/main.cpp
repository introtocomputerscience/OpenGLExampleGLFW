#include <GLFW\glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(480, 480, "OpenGL Example", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	const float DEG2RAD = 3.14159 / 180;
	float radius = 0.2;
	float r = 0.0;
	float g = 0.3;
	float b = 0.6;
	float x = 0.5;
	float y = -0.33;
	bool ballLeft = true;
	bool ballDown = true;
	float speed = 0.03;
	while (!glfwWindowShouldClose(window)) {
		//Setup View
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		//Movement
		if (ballLeft) {
			if (x > -1 + radius) {
				x -= speed;
			}
			else {
				ballLeft = false;
			}
		}
		else {
			if (x < 1 - radius) {
				x += speed;
			}
			else {
				ballLeft = true;
			}
		}

		if (ballDown) {
			if (y > -1 + radius) {
				y -= speed;
			}
			else {
				ballDown = false;
			}
		}
		else {
			if (y < 1 - radius) {
				y += speed;
			}
			else {
				ballDown = true;
			}
		}
		//Color
		r = fmod(r + 0.01, 1);
		g = fmod(g + 0.02, 1);
		b = fmod(b + 0.03, 1);
		//Drawing
		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2f((cos(degInRad)*radius) + x, (sin(degInRad)*radius) + y);
		}
		glEnd();
		//Swap buffer and check for events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate;
	exit(EXIT_SUCCESS);
}