DES_LONG des_quad_cksum(const unsigned char *input, des_cblock output[],
long length, int out_count, des_cblock *seed)
{
DES_LONG z0,z1,t0,t1;
int i;
long l;
const unsigned char *cp;
#ifdef _CRAY
struct lp_st { int a:32; int b:32; } *lp;
#else
DES_LONG *lp;
#endif
if (out_count < 1) out_count=1;
#ifdef _CRAY
lp = (struct lp_st *) &(output[0])[0];
#else
lp = (DES_LONG *) &(output[0])[0];
#endif
z0=Q_B0((*seed)[0])|Q_B1((*seed)[1])|Q_B2((*seed)[2])|Q_B3((*seed)[3]);
z1=Q_B0((*seed)[4])|Q_B1((*seed)[5])|Q_B2((*seed)[6])|Q_B3((*seed)[7]);
for (i=0; ((i<4)&&(i<out_count)); i++)
{
cp=input;
l=length;
while (l > 0)
{
if (l > 1)
{
t0= (DES_LONG)(*(cp++));
t0|=(DES_LONG)Q_B1(*(cp++));
l--;
}
else
t0= (DES_LONG)(*(cp++));
l--;
t0+=z0;
t0&=0xffffffffL;
t1=z1;
z0=((((t0*t0)&0xffffffffL)+((t1*t1)&0xffffffffL))
&0xffffffffL)%0x7fffffffL;
z1=((t0*((t1+NOISE)&0xffffffffL))&0xffffffffL)%0x7fffffffL;
}
if (lp != NULL)
{
#ifdef _CRAY
(*lp).a = z0;
(*lp).b = z1;
lp++;
#else
*lp++ = z0;
*lp++ = z1;
#endif
}
}
return(z0);
}
