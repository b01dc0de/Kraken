#ifndef MATH_H
#define MATH_H

namespace Kraken
{
	struct v2f
	{
		float X = 0.0f;
		float Y = 0.0f;
	};
	struct v3f
	{
		float X = 0.0f;
		float Y = 0.0f;
		float Z = 0.0f;
	};
	struct v4f
	{
		float X = 0.0f;
		float Y = 0.0f;
		float Z = 0.0f;
		float W = 0.0f;
	};

	v2f operator+(const v2f& Left, const v2f& Right);
	v2f operator-(const v2f& Left, const v2f& Right);
	v3f operator+(const v3f& Left, const v3f& Right);
	v3f operator-(const v3f& Left, const v3f& Right);
	v4f operator+(const v4f& Left, const v4f& Right);
	v4f operator-(const v4f& Left, const v4f& Right);
	float Length(const v2f& vIn);
	float Length(const v3f& vIn);
	v2f Norm(const v2f& vIn);
	v3f Norm(const v3f& vIn);
	float Dot(const v2f& Left, const v2f& Right);
	float Dot(const v3f& Left, const v3f& Right);
	float Dot(const v4f& Left, const v4f& Right);
	v3f Cross(const v3f& Left, const v3f& Right);

	struct m2f
	{
		v2f r0;
		v2f r1;
		static m2f Identity()
		{
			m2f Result;
			Result.r0 = v2f{ 1.0f, 0.0f };
			Result.r1 = v2f{ 0.0f, 1.0f };
			return Result;
		}
	};
	struct m3f
	{
		v3f r0;
		v3f r1;
		v3f r2;
		static m3f Identity()
		{
			m3f Result;
			Result.r0 = v3f{ 1.0f, 0.0f, 0.0f };
			Result.r1 = v3f{ 0.0f, 1.0f, 0.0f };
			Result.r2 = v3f{ 0.0f, 0.0f, 1.0f };
			return Result;
		}
	};
	struct m4f
	{
		v4f r0;
		v4f r1;
		v4f r2;
		v4f r3;
		static m4f Identity()
		{
			m4f Result;
			Result.r0 = v4f{ 1.0f, 0.0f, 0.0f, 0.0f };
			Result.r1 = v4f{ 0.0f, 1.0f, 0.0f, 0.0f };
			Result.r2 = v4f{ 0.0f, 0.0f, 1.0f, 0.0f };
			Result.r3 = v4f{ 0.0f, 0.0f, 0.0f, 1.0f };
			return Result;
		}
		static m4f Trans(const v3f& Pos)
		{
			m4f Result = m4f::Identity();
			Result.r3 = v4f{ Pos.X, Pos.Y, Pos.Z, 1.0f };
			return Result;
		}
		static m4f Scale(const v3f& vScale)
		{
			m4f Result;
            Result.r0 = v4f{ vScale.X, 0.0f, 0.0f, 0.0f };
            Result.r1 = v4f{ 0.0f, vScale.Y, 0.0f, 0.0f };
            Result.r2 = v4f{ 0.0f, 0.0f, vScale.Z, 0.0f };
            Result.r3 = v4f{ 0.0f, 0.0f, 0.0f, 1.0f };
			return Result;
		}
		static m4f Scale(float uScale)
		{
			v3f vScale{ uScale, uScale, uScale };
			return Scale(vScale);
		}
	};

	m2f Mult(const m2f& Left, const m2f& Right);
	m3f Mult(const m3f& Left, const m3f& Right);
	m4f Mult(const m4f& Left, const m4f& Right);
}

#endif // MATH_H
