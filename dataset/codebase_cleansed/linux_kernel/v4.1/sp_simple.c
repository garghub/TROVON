union ieee754sp ieee754sp_neg(union ieee754sp x)
{
unsigned int oldrm;
union ieee754sp y;
oldrm = ieee754_csr.rm;
ieee754_csr.rm = FPU_CSR_RD;
y = ieee754sp_sub(ieee754sp_zero(0), x);
ieee754_csr.rm = oldrm;
return y;
}
union ieee754sp ieee754sp_abs(union ieee754sp x)
{
unsigned int oldrm;
union ieee754sp y;
oldrm = ieee754_csr.rm;
ieee754_csr.rm = FPU_CSR_RD;
if (SPSIGN(x))
y = ieee754sp_sub(ieee754sp_zero(0), x);
else
y = ieee754sp_add(ieee754sp_zero(0), x);
ieee754_csr.rm = oldrm;
return y;
}
