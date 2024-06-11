// System Headers
#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int G_EXIT_STATUS = 0;
int mWidth 800
int mHeight 600

void error_callback(int code, const char* description) {
	fprintf(stderr, "[GLFW ERROR] (%d): %s\n", code, description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char * argv[]) {
    // Load GLFW and Create a Window
    if(!glfwInit()){
        fprintf(stderr, "Failt to init GLFW!\n");
        G_EXIT_STATUS = 1;
        goto end;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwSetErrorCallback(error_callback);

    GLFWwindow  *mWindow = glfwCreateWindow(mWidth, mHeight, "opengl-c-template", NULL, NULL);
    if (mWindow == NULL) {
        fprintf(stderr, "Failed to create Window!");
        G_EXIT_STATUS = 1;
        goto end_glfw;
    }

    glfwSetKeyCallback(window, key_callback);

    // Create Context and Load OpenGL Functions
    glfwMakeContextCurrent(mWindow);

	if(!gladLoadGL()) {
		fprintf(stderr, "Failed to load OpenGL functions!\n");
        G_EXIT_STATUS = 1;
        goto end_window;
	};

    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));

    // Rendering Loop
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
    while (!glfwWindowShouldClose(mWindow)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
end_window:
    glfwDestroyWindow(mWindow);
end_glfw:
    glfwTerminate();
end:
    return EXIT_SUCCESS;
}
