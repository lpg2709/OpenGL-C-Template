// System Headers
#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define mWidth 800
#define mHeight 600

int main(int argc, char * argv[]) {

    // Load GLFW and Create a Window
    if(!glfwInit()){
        printf("Failt to init GLFW!");
        return EXIT_FAILURE;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow  *mWindow = glfwCreateWindow(mWidth, mHeight, "opengl-c-template", NULL, NULL);

    // Check for Valid Context
    if (mWindow == NULL) {
        fprintf(stderr, "Failed to create Window!");
		glfwTerminate();
        return EXIT_FAILURE;
    }

    // Create Context and Load OpenGL Functions
    glfwMakeContextCurrent(mWindow);

	if(!gladLoadGL()) {
		printf("Failed to load OpenGL functions!");
        glfwDestroyWindow(mWindow);
        glfwTerminate();
		return EXIT_FAILURE;
	};

    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));

    // Rendering Loop
    while (!glfwWindowShouldClose(mWindow)) {
        if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mWindow, 1);

        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
	glfwTerminate();
    return EXIT_SUCCESS;
}
