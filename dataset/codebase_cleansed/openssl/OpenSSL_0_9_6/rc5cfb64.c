void RC5_32_cfb64_encrypt(const unsigned char *in, unsigned char *out,
long length, RC5_32_KEY *schedule,
unsigned char *ivec, int *num, int encrypt)
{
register unsigned long v0,v1,t;
register int n= *num;
register long l=length;
unsigned long ti[2];
unsigned char *iv,c,cc;
iv=(unsigned char *)ivec;
if (encrypt)
{
while (l--)
{
if (n == 0)
{
c2l(iv,v0); ti[0]=v0;
c2l(iv,v1); ti[1]=v1;
RC5_32_encrypt((unsigned long *)ti,schedule);
iv=(unsigned char *)ivec;
t=ti[0]; l2c(t,iv);
t=ti[1]; l2c(t,iv);
iv=(unsigned char *)ivec;
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
c2l(iv,v0); ti[0]=v0;
c2l(iv,v1); ti[1]=v1;
RC5_32_encrypt((unsigned long *)ti,schedule);
iv=(unsigned char *)ivec;
t=ti[0]; l2c(t,iv);
t=ti[1]; l2c(t,iv);
iv=(unsigned char *)ivec;
}
cc= *(in++);
c=iv[n];
iv[n]=cc;
*(out++)=c^cc;
n=(n+1)&0x07;
}
}
v0=v1=ti[0]=ti[1]=t=c=cc=0;
*num=n;
}
