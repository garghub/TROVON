void des_ede3_cfb64_encrypt(const unsigned char *in, unsigned char *out,
long length, des_key_schedule ks1, des_key_schedule ks2,
des_key_schedule ks3, des_cblock *ivec, int *num, int enc)
{
register DES_LONG v0,v1;
register long l=length;
register int n= *num;
DES_LONG ti[2];
unsigned char *iv,c,cc;
iv=&(*ivec)[0];
if (enc)
{
while (l--)
{
if (n == 0)
{
c2l(iv,v0);
c2l(iv,v1);
ti[0]=v0;
ti[1]=v1;
des_encrypt3(ti,ks1,ks2,ks3);
v0=ti[0];
v1=ti[1];
iv = &(*ivec)[0];
l2c(v0,iv);
l2c(v1,iv);
iv = &(*ivec)[0];
}
c= *(in++)^iv[n];
*(out++)=c;
iv[n]=c;
n=(n+1)&0x07;
}
}
else
{
while (l--)
{
if (n == 0)
{
c2l(iv,v0);
c2l(iv,v1);
ti[0]=v0;
ti[1]=v1;
des_encrypt3(ti,ks1,ks2,ks3);
v0=ti[0];
v1=ti[1];
iv = &(*ivec)[0];
l2c(v0,iv);
l2c(v1,iv);
iv = &(*ivec)[0];
}
cc= *(in++);
c=iv[n];
iv[n]=cc;
*(out++)=c^cc;
n=(n+1)&0x07;
}
}
v0=v1=ti[0]=ti[1]=c=cc=0;
*num=n;
}
