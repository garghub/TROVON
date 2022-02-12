DES_LONG des_cbc_cksum(const unsigned char *in, des_cblock *output,
long length,
des_key_schedule schedule, const_des_cblock *ivec)
{
register DES_LONG tout0,tout1,tin0,tin1;
register long l=length;
DES_LONG tin[2];
unsigned char *out = &(*output)[0];
const unsigned char *iv = &(*ivec)[0];
c2l(iv,tout0);
c2l(iv,tout1);
for (; l>0; l-=8)
{
if (l >= 8)
{
c2l(in,tin0);
c2l(in,tin1);
}
else
c2ln(in,tin0,tin1,l);
tin0^=tout0; tin[0]=tin0;
tin1^=tout1; tin[1]=tin1;
des_encrypt((DES_LONG *)tin,schedule,DES_ENCRYPT);
tout0=tin[0];
tout1=tin[1];
}
if (out != NULL)
{
l2c(tout0,out);
l2c(tout1,out);
}
tout0=tin0=tin1=tin[0]=tin[1]=0;
return(tout1);
}
