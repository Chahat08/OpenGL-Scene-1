#pragma once

#include <glad/glad.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

#include "Mesh.h"
#include "Shader.h"
#include "stb_image.h"

class Model
{
public:
    Model(char* path)
    {
        loadModel(path);
    }
    void Draw(Shader& shader);
private:
    // model data
    std::vector<Texture> textures_loaded;
    std::vector<Mesh> meshes;
    std::string directory;

    void loadModel(std::string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
        std::string typeName);
};