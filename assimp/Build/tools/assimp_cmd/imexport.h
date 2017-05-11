#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class ImExport
{
public:
	bool load(const std::string& strInFile, const std::string& strFormat, const std::string& strContent, const std::string& strOutFile);
	void write(const std::string& strFile, const aiScene* pScene);
	void read(const std::string& strFile);

protected:
	bool getSDScene(void* pOutScene, const aiScene* pInScene);

private:
	//aiScene*	mpScene;
	//SDScene*	mpSDScene;
};
