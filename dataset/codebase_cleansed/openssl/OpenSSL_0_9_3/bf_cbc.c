void BF_cbc_encrypt(unsigned char *in, unsigned char *out, long length,
BF_KEY *ks, unsigned char *iv, int encrypt)
{
register BF_LONG tin0,tin1;
register BF_LONG tout0,tout1,xor0,xor1;
register long l=length;
BF_LONG tin[2];
if (encrypt)
{
n2l(iv,tout0);
n2l(iv,tout1);
iv-=8;
for (l-=8; l>=0; l-=8)
{
n2l(in,tin0);
n2l(in,tin1);
tin0^=tout0;
tin1^=tout1;
tin[0]=tin0;
tin[1]=tin1;
BF_encrypt(tin,ks);
tout0=tin[0];
tout1=tin[1];
l2n(tout0,out);
l2n(tout1,out);
}
if (l != -8)
{
n2ln(in,tin0,tin1,l+8);
tin0^=tout0;
tin1^=tout1;
tin[0]=tin0;
tin[1]=tin1;
BF_encrypt(tin,ks);
tout0=tin[0];
tout1=tin[1];
l2n(tout0,out);
l2n(tout1,out);
}
l2n(tout0,iv);
l2n(tout1,iv);
}
else
{
n2l(iv,xor0);
n2l(iv,xor1);
iv-=8;
for (l-=8; l>=0; l-=8)
{
n2l(in,tin0);
n2l(in,tin1);
tin[0]=tin0;
tin[1]=tin1;
BF_decrypt(tin,ks);
tout0=tin[0]^xor0;
tout1=tin[1]^xor1;
l2n(tout0,out);
l2n(tout1,out);
xor0=tin0;
xor1=tin1;
}
if (l != -8)
{
n2l(in,tin0);
n2l(in,tin1);
tin[0]=tin0;
tin[1]=tin1;
BF_decrypt(tin,ks);
tout0=tin[0]^xor0;
tout1=tin[1]^xor1;
l2nn(tout0,tout1,out,l+8);
xor0=tin0;
xor1=tin1;
}
l2n(xor0,iv);
l2n(xor1,iv);
}
tin0=tin1=tout0=tout1=xor0=xor1=0;
tin[0]=tin[1]=0;
}
