#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class ImExport
{
public:
	bool load(const std::string& strInFile, const std::string& strOutFile, const std::string& opts);
	void write(const std::string& strFile, const aiScene* pScene);
private:
	aiScene*	mpScene;
};
