void CAST_ofb64_encrypt(const unsigned char *in, unsigned char *out,
long length, CAST_KEY *schedule, unsigned char *ivec,
int *num)
{
register CAST_LONG v0,v1,t;
register int n= *num;
register long l=length;
unsigned char d[8];
register char *dp;
CAST_LONG ti[2];
unsigned char *iv;
int save=0;
iv=ivec;
n2l(iv,v0);
n2l(iv,v1);
ti[0]=v0;
ti[1]=v1;
dp=(char *)d;
l2n(v0,dp);
l2n(v1,dp);
while (l--)
{
if (n == 0)
{
CAST_encrypt((CAST_LONG *)ti,schedule);
dp=(char *)d;
t=ti[0]; l2n(t,dp);
t=ti[1]; l2n(t,dp);
save++;
}
*(out++)= *(in++)^d[n];
n=(n+1)&0x07;
}
if (save)
{
v0=ti[0];
v1=ti[1];
iv=ivec;
l2n(v0,iv);
l2n(v1,iv);
}
t=v0=v1=ti[0]=ti[1]=0;
*num=n;
}
