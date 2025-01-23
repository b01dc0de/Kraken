#include "Kraken.h" // NOTE(CKA): Math.h included

namespace Kraken
{
    v2f operator+(const v2f& Left, const v2f& Right)
    {
        return v2f{ Left.X + Right.X, Left.Y + Right.Y };
    }

    v2f operator-(const v2f& Left, const v2f& Right)
    {
        return v2f{ Left.X - Right.X, Left.Y - Right.Y };
    }

    v3f operator+(const v3f& Left, const v3f& Right)
    {
        return v3f{ Left.X + Right.X, Left.Y + Right.Y, Left.Z + Right.Z };
    }

    v3f operator-(const v3f& Left, const v3f& Right)
    {
        return v3f{ Left.X - Right.X, Left.Y - Right.Y, Left.Z - Right.Z };

    }

    v4f operator+(const v4f& Left, const v4f& Right)
    {
        return v4f{ Left.X + Right.X, Left.Y + Right.Y, Left.Z + Right.Z, Left.W + Right.W };

    }

    v4f operator-(const v4f& Left, const v4f& Right)
    {
        return v4f{ Left.X - Right.X, Left.Y - Right.Y, Left.Z - Right.Z, Left.W - Right.W };

    }

    float Length(const v2f& vIn)
    {
        return sqrtf(vIn.X * vIn.X + vIn.Y * vIn.Y);
    }

    float Length(const v3f& vIn)
    {
        return sqrtf(vIn.X * vIn.X + vIn.Y * vIn.Y + vIn.Z * vIn.Z);
    }

    v2f Norm(const v2f& vIn)
    {
        float fInLength = Length(vIn);
        // TODO(CKA): Protect against divide-by-zero
        return v2f{ vIn.X / fInLength, vIn.Y / fInLength };
    }

    v3f Norm(const v3f& vIn)
    {
        float fInLength = Length(vIn);
        // TODO(CKA): Protect against divide-by-zero
        return v3f{ vIn.X / fInLength, vIn.Y / fInLength, vIn.Z / fInLength };
    }

    float Dot(const v2f& Left, const v2f& Right)
    {
        return (Left.X * Right.X) + (Left.Y * Right.Y);
    }
    float Dot(const v3f& Left, const v3f& Right)
    {
        return (Left.X * Right.X) + (Left.Y * Right.Y) + (Left.Z * Right.Z);
    }
    float Dot(const v4f& Left, const v4f& Right)
    {
        return (Left.X * Right.X) + (Left.Y * Right.Y) + (Left.Z * Right.Z) + (Left.W * Right.W);
    }

    v3f Cross(const v3f& Left, const v3f& Right)
    {
        v3f Result;
        Result.X = (Left.Y * Right.Z) - (Left.Z * Right.Y);
        Result.Y = (Left.X * Right.Z) - (Left.Z * Right.X);
        Result.Z = (Left.X * Right.Y) - (Left.Y * Right.X);
        return Result;
    }

    m2f Mult(const m2f& Left, const m2f& Right)
    {
        m2f Result;
        Result.r0.X = Left.r0.X * Right.r0.X + Left.r0.Y * Right.r1.X;
        Result.r0.Y = Left.r0.X * Right.r0.Y + Left.r0.Y * Right.r1.Y;
        Result.r1.X = Left.r1.X * Right.r0.X + Left.r1.Y * Right.r1.X;
        Result.r1.Y = Left.r1.X * Right.r0.Y + Left.r1.Y * Right.r1.Y;
        return Result;
    }

    m3f Mult(const m3f& Left, const m3f& Right)
    {
        m3f Result;
        Result.r0.X = Left.r0.X * Right.r0.X + Left.r0.Y * Right.r1.X + Left.r0.Z * Right.r2.X;
        Result.r0.Y = Left.r0.X * Right.r0.Y + Left.r0.Y * Right.r1.Y + Left.r0.Z * Right.r2.Y;
        Result.r0.Z = Left.r0.X * Right.r0.Z + Left.r0.Y * Right.r1.Z + Left.r0.Z * Right.r2.Z;
        Result.r1.X = Left.r1.X * Right.r0.X + Left.r1.Y * Right.r1.X + Left.r1.Z * Right.r2.X;
        Result.r1.Y = Left.r1.X * Right.r0.Y + Left.r1.Y * Right.r1.Y + Left.r1.Z * Right.r2.Y;
        Result.r1.Z = Left.r1.X * Right.r0.Z + Left.r1.Y * Right.r1.Z + Left.r1.Z + Right.r2.Z;
        Result.r2.X = Left.r2.X * Right.r0.X + Left.r2.Y * Right.r1.X + Left.r2.Z * Right.r2.X;
        Result.r2.Y = Left.r2.X * Right.r0.Y + Left.r2.Y * Right.r1.Y + Left.r2.Z * Right.r2.Y;
        Result.r2.Z = Left.r2.X * Right.r0.Z + Left.r2.Y * Right.r1.Z + Left.r2.Z * Right.r2.Z;
        return Result;
    }

    m4f Mult(const m4f& Left, const m4f& Right)
    {
        m4f Result;
        Result.r0.X = Left.r0.X * Right.r0.X + Left.r0.Y * Right.r1.X + Left.r0.Z * Right.r2.X + Left.r0.W * Right.r3.X;
        Result.r0.Y = Left.r0.X * Right.r0.Y + Left.r0.Y * Right.r1.Y + Left.r0.Z * Right.r2.Y + Left.r0.W * Right.r3.Y;
        Result.r0.Z = Left.r0.X * Right.r0.Z + Left.r0.Y * Right.r1.Z + Left.r0.Z * Right.r2.Z + Left.r0.W * Right.r3.Z;
        Result.r0.W = Left.r0.X * Right.r0.W + Left.r0.Y * Right.r1.W + Left.r0.Z * Right.r2.W + Left.r0.W * Right.r3.W;

        Result.r1.X = Left.r1.X * Right.r0.X + Left.r1.Y * Right.r1.X + Left.r1.Z * Right.r2.X + Left.r1.W * Right.r3.X;
        Result.r1.Y = Left.r1.X * Right.r0.Y + Left.r1.Y * Right.r1.Y + Left.r1.Z * Right.r2.Y + Left.r1.W * Right.r3.Y;
        Result.r1.Z = Left.r1.X * Right.r0.Z + Left.r1.Y * Right.r1.Z + Left.r1.Z + Right.r2.Z + Left.r1.W * Right.r3.Z;
        Result.r1.W = Left.r1.X * Right.r0.W + Left.r1.Y * Right.r1.W + Left.r1.Z * Right.r2.W + Left.r1.W * Right.r3.W;

        Result.r2.X = Left.r2.X * Right.r0.X + Left.r2.Y * Right.r1.X + Left.r2.Z * Right.r2.X + Left.r2.W * Right.r3.X;
        Result.r2.Y = Left.r2.X * Right.r0.Y + Left.r2.Y * Right.r1.Y + Left.r2.Z * Right.r2.Y + Left.r2.W * Right.r3.Y;
        Result.r2.Z = Left.r2.X * Right.r0.Z + Left.r2.Y * Right.r1.Z + Left.r2.Z * Right.r2.Z + Left.r2.W * Right.r3.Z;
        Result.r2.W = Left.r2.X * Right.r0.W + Left.r2.Y * Right.r2.W + Left.r2.Z * Right.r2.W + Left.r2.W * Right.r3.W;

        Result.r3.X = Left.r3.X * Right.r0.X + Left.r3.Y * Right.r1.X + Left.r3.Z * Right.r2.X + Left.r3.W * Right.r3.X;
        Result.r3.Y = Left.r3.X * Right.r0.Y + Left.r3.Y * Right.r1.Y + Left.r3.Z * Right.r2.Y + Left.r3.W * Right.r3.Y;
        Result.r3.Z = Left.r3.X * Right.r0.Z + Left.r3.Y * Right.r1.Z + Left.r3.Z * Right.r2.Z + Left.r3.W * Right.r3.Z;
        Result.r3.W = Left.r3.X * Right.r0.W + Left.r3.Y * Right.r2.W + Left.r3.Z * Right.r2.W + Left.r3.W * Right.r3.W;
        return Result;
    }
}
