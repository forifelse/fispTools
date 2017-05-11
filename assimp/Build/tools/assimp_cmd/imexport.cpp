#include "imexport.h"
#include <fstream>
#include "scenedata.h"

bool ImExport::load(const std::string& strInFile, const std::string& strFormat, const std::string& strContent, const std::string& strOutFile)
{
	Assimp::Importer importer;
	unsigned flags =
		aiProcess_ConvertToLeftHanded |
		aiProcess_JoinIdenticalVertices |
		aiProcess_Triangulate |
		aiProcess_GenSmoothNormals |
		aiProcess_LimitBoneWeights |
		aiProcess_ImproveCacheLocality |
		aiProcess_RemoveRedundantMaterials |
		aiProcess_FixInfacingNormals |
		aiProcess_FindInvalidData |
		aiProcess_GenUVCoords |
		aiProcess_FindInstances |
		aiProcess_OptimizeMeshes;
	//flags |= aiProcess_GenNormals;
	//flags |= aiProcess_CalcTangentSpace;
	const aiScene* pInScene = importer.ReadFile(strInFile, flags);
											  
	if (!pInScene)
	{
		return false;
	}
	SDScene outScene;
	getSDScene(&outScene, pInScene);
	SceneRW::sceneWrite(&outScene, "outSceneFile.dat");
	//write(strOutFile, pInScene);
	//read("out");
	return true;
}

bool ImExport::getSDScene(void* pOutScene, const aiScene* pInScene)
{
	if (nullptr == pOutScene || nullptr == pInScene)
		return false;
	SDScene* pScene = (SDScene*)pOutScene;
	if (pInScene->mNumMeshes <= 0 || nullptr == pInScene->mMeshes)
		return false;
	pScene->uNumMesh = pInScene->mNumMeshes;
	pScene->pBlob = new SDBlob;
	pScene->pBlob->pMesh = new SDMesh[pScene->uNumMesh];
	for (unsigned int i = 0; i < pScene->uNumMesh; i++)
	{
		;
	}
	return true;
}

void ImExport::write(const std::string& strFile, const aiScene* pScene)
{
	std::ofstream ofs(strFile, std::ios::binary);
	//ofs << pScene->mFlags << " , " << pScene->mNumMeshes << std::endl;
	ofs.write((char*)pScene, sizeof(aiScene));
	ofs.close();
}

void ImExport::read(const std::string& strFile)
{
	std::ifstream ifs(strFile, std::ios::binary);
	//unsigned int uFlags, uNumMeshes;
	//char sz[2];
	//ifs >> uFlags >> sz >> uNumMeshes;
	aiScene scene;
	ifs.read((char*)&scene, sizeof(aiScene));
	ifs.close();
	memset(&scene, 0, sizeof(aiScene));
}
