#pragma once
#include <fstream>

struct SCamera
{
	float	tx,ty,tz;
	float	rx,ry,rz;
};

struct SLitPoint
{
	std::string	strName;
	float	x,y,z;
	float	r,g,b;
	float	radius;
	float	intensity;
};

struct SLitSpot : public SLitPoint
{
	float	toward;
	float	inner, outer;
};

struct SLitDire
{

};

struct SMaterial
{
	std::string	strName;
	std::string	strColorTexture;
	std::string	strNormalMap;
	std::string	strSpecularMap;
	float	ambientR, ambientG, ambientB;
	float	diffuseR, diffuseG, diffuseB;
	float	specularR, specularG, specularB;
	float	emmissiveR, emmissiveG, emmissiveB;
	float	metallic;
	float	roughness;
	float	shinness;
	bool	bTwoSided;

	SMaterial() { memset(this, 0, sizeof(SMaterial)); }
};

struct STexture
{

};

struct SGeometry
{
	unsigned int	uNumVertex;
	float*			pVertices;
	unsigned int	uNumFace;
	float*			pTriangles;
	unsigned int	uNumUV;
	float*			pUV;
	unsigned int	uNumNor;
	float*			pNormal;
	unsigned int	uNumTang;
	float*			pTangent;
	unsigned int	uNumVerClr;
	float*			pVerClr;

	SGeometry() { memset(this, 0, sizeof(SGeometry)); }
};

struct SSubMesh
{
	unsigned int	uGeomIdx;
	unsigned int	uMateIdx;
	unsigned int	uSubIndex;
	bool			bCollision;

	SSubMesh() { memset(this, 0, sizeof(SSubMesh)); }
};

struct SMesh
{
	std::string		strName;
	bool			bVisible;
	unsigned int	uNumSub;
	SSubMesh*		pSub;
};

struct SScene
{
	std::string		strName;
	SCamera			camera;
	unsigned int	uNumMesh;
	SMesh*			pMesh;
};

struct SceneRW
{
private:
	template<class T>
	void write(const T* pData, const std::string& strFile, unsigned int uFrom = 0)
	{
		std::ofstream ofs(strFile, std::ios::binary);
		ofs.seekp(uFrom);
		ofs.write((char*)pData, sizeof(T));
		ofs.close();

		//ofs << pScene->mFlags << " , " << pScene->mNumMeshes << std::endl;
	}

	template<class T>
	void read(T& data, const std::string& strFile, unsigned int uFrom = 0)
	{
		std::ifstream ifs(strFile, std::ios::binary);
		ifs.seekg(uFrom);
		ifs.read((char*)&data, sizeof(T));
		ifs.close();

		//unsigned int uFlags, uNumMeshes;
		//char sz[2];
		//ifs >> uFlags >> sz >> uNumMeshes;
	}

public:
	void sceneWrite(const SScene* pScene, const std::string& strFile)
	{

	}

	void sceneRead(SScene& scene, const std::string& strFile)
	{

	}
};
