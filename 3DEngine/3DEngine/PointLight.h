#pragma once
#include "Drawable.h"
#include "ConstantBuffers.h"

class PointLight : public Drawable
{
public:
	PointLight( Graphics& gfx,float radius );
	void SetDirection( DirectX::XMFLOAT3 direction ) noexcept;
	void SpawnControlWindow( Graphics& gfx ) noexcept;
	DirectX::XMMATRIX GetTransformXM() const noexcept override;
	void DrawPointLight( Graphics& gfx, DirectX::FXMMATRIX view, DirectX::XMFLOAT3 camPos );
	void SetPos( DirectX::XMFLOAT3 vec );
private:
	//DirectX::XMFLOAT3 lightDirection;
	ID3D11Buffer* m_lightBuffer;
	struct PSColorConstant
	{
		DirectX::XMFLOAT3 color = { 1.0f,1.0f,1.0f };
		float padding;
		DirectX::XMMATRIX cameraMatrix;
		DirectX::XMMATRIX projInvMatrix;
	} colorConst;
	std::shared_ptr<Bind::PixelConstantBuffer<PSColorConstant>> pcs;

	struct PSPositionConstant
	{
		DirectX::XMFLOAT3 lightPosition = { 1.0f,1.0f,1.0f };
		float padding;
	} posConst;
	std::shared_ptr<Bind::PixelConstantBuffer<PSPositionConstant>> pcs2;

	struct CamPosBuffer
	{
		DirectX::XMFLOAT3 camPos;
		float padding2;
	} cambuf;
	std::shared_ptr<Bind::PixelConstantBuffer<CamPosBuffer>> pcs3;
};
