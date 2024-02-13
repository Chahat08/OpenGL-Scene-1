#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <random>
#include <vector>

#include "Shader.h"
#include "Texture.h"
#include "VertexData.h"
#include "Constants.h"
#include "Camera.h"
#include "Model.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

int CURSOR_XPOS = INT_MIN;
int CURSOR_YPOS = INT_MIN;

int NUM_CUBES = 16;

const float IPD = 0.5f;

float deltaTime = 1.0f;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {

	if (CURSOR_XPOS == INT_MIN) {
		// set initial values
		CURSOR_XPOS = xpos;
		CURSOR_YPOS = ypos;
	}

	float xoffset = xpos - CURSOR_XPOS;
	float yoffset = CURSOR_YPOS - ypos;

	CURSOR_XPOS = xpos;
	CURSOR_YPOS = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);

	//if (CURSOR_XPOS != xpos || CURSOR_YPOS != ypos)
	//	glfwSetWindowShouldClose(window, GL_TRUE);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	// camera movement
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		camera.ProcessKeyboard(UP, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, deltaTime);
	
}

void createModelMatrices(Shader& shader, std::vector<glm::vec3> positions, std::vector<glm::vec3> axes) {
	for (int i = 0; i < NUM_CUBES; ++i) {
		glm::mat4 model(1.0f);
		model = glm::translate(model, positions[i]);
		model = glm::rotate(model, (float)glfwGetTime(), axes[i]);

		shader.setUniformMatrix4float("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

void createViewMatrix(Shader& shader, float ipd, bool rightEye = false) {
	/*const float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;
	glm::mat4 view(1.0f);
	view = glm::lookAt(
		glm::vec3((rightEye ? camX += ipd / 2.0 : camX -= ipd / 2.0), 0.0f, camZ),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);*/

	glm::mat4 view = camera.GetViewMatrix();

	shader.setUniformMatrix4float("view", view);
}

void createProjectionMatrix(Shader& shader, float near = 0.1f, float far = 100.0f) {
	glm::mat4 projection(1.0f);

	projection = glm::perspective(
		glm::radians(camera.zoom),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		0.1f,
		100.0f
	);

	shader.setUniformMatrix4float("projection", projection);
}

void createAllTransformationsAndEnableQuadBuffer(Shader& shader, float ipd, float near, float far, float fovDeg, std::vector<glm::vec3> positions, std::vector<glm::vec3> axes) {
	createProjectionMatrix(shader, near, far);

	// LEFT EYE
	glDrawBuffer(GL_BACK_LEFT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	createViewMatrix(shader, ipd, false);
	createModelMatrices(shader, positions, axes);

	glFlush();

	// RIGHT EYE
	glDrawBuffer(GL_BACK_RIGHT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	createViewMatrix(shader, ipd, true);
	createModelMatrices(shader, positions, axes);

	glFlush();
}

int main() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfwWindowHint(GLFW_DECORATED, NULL); // to remove border and titlebar

	//glfwWindowHint(GLFW_STEREO, GLFW_TRUE);

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	SCREEN_WIDTH = mode->width;
	SCREEN_HEIGHT = mode->height;

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Title", monitor, NULL);
	//GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Title", NULL, NULL);
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); // hide the cursor


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDERER);
	std::cout << "vendor: " << vendor << std::endl;
	std::cout << "renderer: " << renderer << std::endl;

	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetScrollCallback(window, scroll_callback);
	//glfwSetKeyCallback(window, key_callback);

	// SHADERS
	Shader shader("shaders/vertexShaderSource.vert", "shaders/fragmentShaderSource.frag");

	// TEXTURES
	Texture texture0("textures/purple_stars.jpg", "jpg", false);
	texture0.setTextureParams(GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

	Texture texture1("textures/green_lines.jpg", "jpg", false);
	texture1.setTextureParams(GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

	shader.use();
	shader.setIntUniform("purpleStars", 0);
	shader.setIntUniform("greenLines", 1);


	// VERTEX DATA
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), &vertexData, GL_DYNAMIC_DRAW);

	// for vertex positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// for vertex colors
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// for textures
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glEnable(GL_DEPTH_TEST);

	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_real_distribution<> distribution_xy(-5.0, 5.0);
	std::uniform_real_distribution<> distribution_z(-5.0, 5.0);
	std::uniform_real_distribution<> distribution_axes(-2, 2);

	std::vector<glm::vec3> positions, axes;

	for (int i = 0; i < NUM_CUBES; ++i) {
		positions.push_back(glm::vec3(distribution_xy(engine), distribution_xy(engine), distribution_z(engine)));
		axes.push_back(glm::vec3(distribution_axes(engine), distribution_axes(engine), distribution_axes(engine)));
	}


	int frame = 0;
	float lastTime = glfwGetTime();
	float lastFrame = 0.0;// time for the last frame
	while (!glfwWindowShouldClose(window)) {
		float currTime = glfwGetTime();
		deltaTime = currTime - lastTime;
		lastTime = currTime;

		processInput(window);

		glClearColor(0.0f, 0.027f, 0.212f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		texture0.setTextureUnit(0);
		texture1.setTextureUnit(1);

		shader.use();
		glBindVertexArray(VAO);

		createAllTransformationsAndEnableQuadBuffer(shader, IPD, 0.1f, 100.0f, 45.0, positions, axes);

		glfwSwapBuffers(window);
		glfwPollEvents();

		frame++;
		if (glfwGetTime() - lastTime > 1.0f) {
			std::cout << "Current FPS: " << frame << std::endl;
			frame = 0;
			lastTime += 1.0;
		}
	}

	glfwTerminate();

	return 0;
}