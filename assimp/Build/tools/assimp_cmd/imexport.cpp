#include "imexport.h"

bool ImExport::load(const std::string& strInFile, const std::string& strOutFile, const std::string& opts)
{
	Assimp::Importer importer;

	const aiScene* pScene = importer.ReadFile(strInFile,
		aiProcess_CalcTangentSpace | 
		aiProcess_Triangulate |  
		aiProcess_JoinIdenticalVertices | 
		aiProcess_SortByPType);  
											  
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