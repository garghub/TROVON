void des_cfb_encrypt(const unsigned char *in, unsigned char *out, int numbits,
long length, des_key_schedule schedule, des_cblock *ivec, int enc)
{
register DES_LONG d0,d1,v0,v1,n=(numbits+7)/8;
register DES_LONG mask0,mask1;
register unsigned long l=length;
register int num=numbits;
DES_LONG ti[2];
unsigned char *iv;
if (num > 64) return;
if (num > 32)
{
mask0=0xffffffffL;
if (num == 64)
mask1=mask0;
else mask1=(1L<<(num-32))-1;
}
else
{
if (num == 32)
mask0=0xffffffffL;
else mask0=(1L<<num)-1;
mask1=0x00000000L;
}
iv = &(*ivec)[0];
c2l(iv,v0);
c2l(iv,v1);
if (enc)
{
while (l >= n)
{
l-=n;
ti[0]=v0;
ti[1]=v1;
des_encrypt((DES_LONG *)ti,schedule,DES_ENCRYPT);
c2ln(in,d0,d1,n);
in+=n;
d0=(d0^ti[0])&mask0;
d1=(d1^ti[1])&mask1;
l2cn(d0,d1,out,n);
out+=n;
if (num == 32)
{ v0=v1; v1=d0; }
else if (num == 64)
{ v0=d0; v1=d1; }
else if (num > 32)
{
v0=((v1>>(num-32))|(d0<<(64-num)))&0xffffffffL;
v1=((d0>>(num-32))|(d1<<(64-num)))&0xffffffffL;
}
else
{
v0=((v0>>num)|(v1<<(32-num)))&0xffffffffL;
v1=((v1>>num)|(d0<<(32-num)))&0xffffffffL;
}
}
}
else
{
while (l >= n)
{
l-=n;
ti[0]=v0;
ti[1]=v1;
des_encrypt((DES_LONG *)ti,schedule,DES_ENCRYPT);
c2ln(in,d0,d1,n);
in+=n;
if (num == 32)
{ v0=v1; v1=d0; }
else if (num == 64)
{ v0=d0; v1=d1; }
else if (num > 32)
{
v0=((v1>>(num-32))|(d0<<(64-num)))&0xffffffffL;
v1=((d0>>(num-32))|(d1<<(64-num)))&0xffffffffL;
}
else
{
v0=((v0>>num)|(v1<<(32-num)))&0xffffffffL;
v1=((v1>>num)|(d0<<(32-num)))&0xffffffffL;
}
d0=(d0^ti[0])&mask0;
d1=(d1^ti[1])&mask1;
l2cn(d0,d1,out,n);
out+=n;
}
}
iv = &(*ivec)[0];
l2c(v0,iv);
l2c(v1,iv);
v0=v1=d0=d1=ti[0]=ti[1]=0;
}
