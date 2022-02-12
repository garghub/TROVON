union ieee754dp ieee754dp_neg(union ieee754dp x)
{
unsigned int oldrm;
union ieee754dp y;
oldrm = ieee754_csr.rm;
ieee754_csr.rm = FPU_CSR_RD;
y = ieee754dp_sub(ieee754dp_zero(0), x);
ieee754_csr.rm = oldrm;
return y;
}
union ieee754dp ieee754dp_abs(union ieee754dp x)
{
unsigned int oldrm;
union ieee754dp y;
oldrm = ieee754_csr.rm;
ieee754_csr.rm = FPU_CSR_RD;
if (DPSIGN(x))
y = ieee754dp_sub(ieee754dp_zero(0), x);
else
y = ieee754dp_add(ieee754dp_zero(0), x);
ieee754_csr.rm = oldrm;
return y;
}
