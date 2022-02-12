void DES_xwhite_in2out(const_DES_cblock *des_key, const_DES_cblock *in_white,
DES_cblock *out_white)
{
int out0,out1;
int i;
const unsigned char *key = &(*des_key)[0];
const unsigned char *in = &(*in_white)[0];
unsigned char *out = &(*out_white)[0];
out[0]=out[1]=out[2]=out[3]=out[4]=out[5]=out[6]=out[7]=0;
out0=out1=0;
for (i=0; i<8; i++)
{
out[i]=key[i]^desx_white_in2out[out0^out1];
out0=out1;
out1=(int)out[i&0x07];
}
out0=out[0];
out1=out[i];
for (i=0; i<8; i++)
{
out[i]=in[i]^desx_white_in2out[out0^out1];
out0=out1;
out1=(int)out[i&0x07];
}
}
void DES_xcbc_encrypt(const unsigned char *in, unsigned char *out,
long length, DES_key_schedule *schedule,
DES_cblock *ivec, const_DES_cblock *inw,
const_DES_cblock *outw, int enc)
{
register DES_LONG tin0,tin1;
register DES_LONG tout0,tout1,xor0,xor1;
register DES_LONG inW0,inW1,outW0,outW1;
register const unsigned char *in2;
register long l=length;
DES_LONG tin[2];
unsigned char *iv;
in2 = &(*inw)[0];
c2l(in2,inW0);
c2l(in2,inW1);
in2 = &(*outw)[0];
c2l(in2,outW0);
c2l(in2,outW1);
iv = &(*ivec)[0];
if (enc)
{
c2l(iv,tout0);
c2l(iv,tout1);
for (l-=8; l>=0; l-=8)
{
c2l(in,tin0);
c2l(in,tin1);
tin0^=tout0^inW0; tin[0]=tin0;
tin1^=tout1^inW1; tin[1]=tin1;
DES_encrypt1(tin,schedule,DES_ENCRYPT);
tout0=tin[0]^outW0; l2c(tout0,out);
tout1=tin[1]^outW1; l2c(tout1,out);
}
if (l != -8)
{
c2ln(in,tin0,tin1,l+8);
tin0^=tout0^inW0; tin[0]=tin0;
tin1^=tout1^inW1; tin[1]=tin1;
DES_encrypt1(tin,schedule,DES_ENCRYPT);
tout0=tin[0]^outW0; l2c(tout0,out);
tout1=tin[1]^outW1; l2c(tout1,out);
}
iv = &(*ivec)[0];
l2c(tout0,iv);
l2c(tout1,iv);
}
else
{
c2l(iv,xor0);
c2l(iv,xor1);
for (l-=8; l>0; l-=8)
{
c2l(in,tin0); tin[0]=tin0^outW0;
c2l(in,tin1); tin[1]=tin1^outW1;
DES_encrypt1(tin,schedule,DES_DECRYPT);
tout0=tin[0]^xor0^inW0;
tout1=tin[1]^xor1^inW1;
l2c(tout0,out);
l2c(tout1,out);
xor0=tin0;
xor1=tin1;
}
if (l != -8)
{
c2l(in,tin0); tin[0]=tin0^outW0;
c2l(in,tin1); tin[1]=tin1^outW1;
DES_encrypt1(tin,schedule,DES_DECRYPT);
tout0=tin[0]^xor0^inW0;
tout1=tin[1]^xor1^inW1;
l2cn(tout0,tout1,out,l+8);
xor0=tin0;
xor1=tin1;
}
iv = &(*ivec)[0];
l2c(xor0,iv);
l2c(xor1,iv);
}
tin0=tin1=tout0=tout1=xor0=xor1=0;
inW0=inW1=outW0=outW1=0;
tin[0]=tin[1]=0;
}
