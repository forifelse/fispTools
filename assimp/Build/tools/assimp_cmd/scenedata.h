#pragma once
#include <fstream>

struct SDCamera
{
	float	tx,ty,tz;
	float	rx,ry,rz;

	SDCamera() { memset(this, 0, sizeof(SDCamera)); }
};

struct SDLitPoint
{
	std::string	strName;
	float	x,y,z;
	float	r,g,b;
	float	radius;
	float	intensity;

	SDLitPoint() { memset(this, 0, sizeof(SDLitPoint)); }
};

struct SDLitSpot : public SDLitPoint
{
	float	toward;
	float	inner, outer;

	SDLitSpot() { memset(this, 0, sizeof(SDLitSpot)); }
};

struct SDLitDire
{
	SDLitDire() { memset(this, 0, sizeof(SDLitDire)); }
};

struct SDMaterial
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

	SDMaterial() { memset(this, 0, sizeof(SDMaterial)); }
};

struct SDTexture
{

};

struct SDGeometry
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

	SDGeometry() { memset(this, 0, sizeof(SDGeometry)); }
};

struct SDSubMesh
{
	unsigned int	uGeomIdx;
	unsigned int	uMateIdx;
	unsigned int	uSubIndex;
	bool			bCollision;

	SDSubMesh() { memset(this, 0, sizeof(SDSubMesh)); }
};

struct SDMesh
{
	std::string		strName;
	bool			bVisible;
	SDSubMesh		subFirst;
	unsigned int	uNumSubOther;
	SDSubMesh*		pSubOther;
	//
	float			trans[16];
	//float			tx, ty, tz, rx, ry, rz, sx, sy, sz;
	bool			bCastShadow;
	bool			bReceiveShadow;
	bool			bSimulate;
	float			mass;
	bool			bDamage;
	//
	unsigned int	uParent;	// 0xffff or -1 means parent is null
	unsigned int	uNumChild;
	unsigned int*	pChildren;
	// instance ?

	SDMesh() { memset(this, 0, sizeof(SDMesh)); }
};

struct SDRoot
{
	unsigned int	uNumChild;
	unsigned int*	pChildren;

	SDRoot() { memset(this, 0, sizeof(SDRoot)); }
};

struct SDBlob
{
	// Blob data
	SDMesh*			pMesh;
	SDGeometry*		pGeom;
	SDMaterial*		pMate;
	SDLitPoint*		pLitPoint;
	SDLitSpot*		pLitSpot;
	SDLitDire*		pLitDire;

	SDBlob() { memset(this, 0, sizeof(SDBlob)); }
};

struct SDScene
{
	// Blob data
	SDBlob*			pBlob;
	unsigned int	uNumMesh;
	unsigned int	uNumGeom;
	unsigned int	uNumMate;
	unsigned int	uNumLitPoint;
	unsigned int	uNumLitSpot;
	unsigned int	uNumLitDire;
	// scene data
	std::string		strName;
	SDCamera		camera;
	SDRoot*			pRoot;

	SDScene() { memset(this, 0, sizeof(SDScene)); }
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
	void sceneWrite(const SDScene* pScene, const std::string& strFile)
	{
		write<SDScene>(pScene, strFile);
	}

	void sceneRead(SDScene& scene, const std::string& strFile)
	{
		read<SDScene>(scene, strFile);
	}
};
