#pragma once
#include "Drawable.h"

class DirectionalLight : public Drawable
{
public:
	DirectionalLight( Graphics& gfx, float size );
	void SetDirection( DirectX::XMFLOAT3 direction ) noexcept;
	void SpawnControlWindow( Graphics& gfx ) noexcept;
private:
	struct LightBufferType
	{
		DirectX::XMFLOAT3 lightDirection;
		float padding;
	};
private:
	DirectX::XMFLOAT3 lightDirection;
	ID3D11Buffer* m_lightBuffer;
};
