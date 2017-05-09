#include "imexport.h"

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
	const aiScene* pScene = importer.ReadFile(strInFile, flags);
											  
	if (!pScene)
	{
		return false;
	}
	write(strOutFile, pScene);
	return true;
}

void ImExport::write(const std::string& strFile, const aiScene* pScene)
{

}