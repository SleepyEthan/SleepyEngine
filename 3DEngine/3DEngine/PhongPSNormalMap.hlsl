#include "ShaderOps.hlsl"
#include "LightVectorData.hlsl"
#include "PointLight.hlsl"

cbuffer ObjectCBuf
{
    float specularIntensity;
    float specularPower;
    bool normalMapEnabled;
    float padding[1];
};

Texture2D tex;
Texture2D nmap : register(t2);

SamplerState splr;

struct PixelOutputType
{
    float4 color : SV_Target0;
    float4 normal : SV_Target1;
};

PixelOutputType main(float3 viewFragPos : Position, float3 viewNormal : Normal, float3 viewTan : Tangent, float3 viewBitan : Bitangent, float2 tc : Texcoord) : SV_Target
{
 //   // normalize the mesh normal
 //   viewNormal = normalize(viewNormal);
 //   // replace normal with mapped if normal mapping enabled
 //   if (normalMapEnabled)
 //   {
 //       viewNormal = MapNormal(normalize(viewTan), normalize(viewBitan), viewNormal, tc, nmap, splr);
 //   }
	//// fragment to light vector data
 //   const LightVectorData lv = CalculateLightVectorData(viewLightPos, viewFragPos);
	//// attenuation
 //   const float att = Attenuate(attConst, attLin, attQuad, lv.distToL);
	//// diffuse
 //   const float3 diffuse = Diffuse(diffuseColor, diffuseIntensity, att, lv.dirToL, viewNormal);
 //   // specular
 //   const float3 specular = Speculate(
 //       diffuseColor, diffuseIntensity, viewNormal,
 //       lv.vToL, viewFragPos, att, specularPower
 //   );
	//// final color
 //   return float4(saturate((diffuse + ambient) * tex.Sample(splr, tc).rgb + specular), 1.0f);
    
    PixelOutputType output;


    // Sample the color from the texture and store it for output to the render target.
    output.color = tex.Sample(splr, tc);
	
    // Store the normal for output to the render target.
    output.normal = float4(viewNormal, 1.0f);

    return output;
}