#ifndef GRAPHICS_DX11_H
#define GRAPHICS_DX11_H

#include "Kraken.h"

namespace Kraken
{
	struct VertexColor
	{
		v4f Position;
		v4f Color;
	};

	struct VertexTexture
	{
		v4f Position;
		v2f TexUV;
	};

	struct WVPData
	{
		m4f World;
		m4f View;
		m4f Proj;
	};

	struct Camera
	{
		m4f View;
		m4f Proj;
		void Ortho(float FrameResX, float FrameResY, float fDepth = 1.0f)
		{
			View = m4f::Identity();
			Proj = m4f::Identity();
			Proj.r0.X = +2.0f / FrameResX;
			Proj.r1.Y = +2.0f / FrameResY;
			View.r2.Z = -2.0f / fDepth;
		}
	};
	
	int CompileShaderHelper(LPCWSTR SourceFileName, LPCSTR EntryPointFunction, LPCSTR Profile, ID3DBlob** ShaderBlob, const D3D_SHADER_MACRO* Defines = nullptr);
    int InitGraphics();
	void UpdateAndDraw();
	void Draw();
}

#endif // GRAPHICS_DX11_H