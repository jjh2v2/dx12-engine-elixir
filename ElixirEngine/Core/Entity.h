#pragma once
#include "../stdafx.h"
#include "Mesh.h"
#include "../Material.h"

class Entity
{
protected:
	uint32_t	entityID;
	XMFLOAT4X4	worldMatrix;
	XMFLOAT3	position;
	XMFLOAT3	scale;
	XMFLOAT3	rotation;
	Mesh*		mesh;
	Material*	material;
	bool		bCastsShadow = false;
	XMFLOAT3	boxCenter;
	XMFLOAT3	sphereCenter;

	BoundingOrientedBox boundingBox;
	BoundingSphere		boundingSphere;
	void				CalculateWorldMatrix();
public:
	Entity();
	Material*	GetMaterial();
	Mesh*		GetMesh();
	XMFLOAT4X4	GetWorldViewProjectionTransposed(XMFLOAT4X4 projection, XMFLOAT4X4 view);
	XMFLOAT4X4	GetWorldMatrix();
	XMFLOAT4X4	GetWorldMatrixTransposed();
	XMFLOAT3	GetPosition();
	uint32_t	GetID();


	void		SetMesh(Mesh* m);
	void		SetMaterial(Material* mat);
	void		SetPosition(const XMFLOAT3& pos);
	void		SetRotation(const XMFLOAT3& rot);
	void		SetScale(const XMFLOAT3& scale);
	void		SetX(float x);
	void		SetY(float y);
	void		SetZ(float z);
	void		SetID(uint32_t id);

	const bool& CastsShadow() { return bCastsShadow; }
	void		SetCastsShadow(bool enable) { bCastsShadow = enable; }

	inline const BoundingOrientedBox&	GetBoundingBox() { return boundingBox; };
	inline const BoundingSphere&		GetBoundingSphere() { return boundingSphere; };
	~Entity();
};