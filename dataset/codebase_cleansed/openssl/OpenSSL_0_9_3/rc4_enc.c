void RC4(RC4_KEY *key, unsigned long len, unsigned char *indata,
unsigned char *outdata)
{
register RC4_INT *d;
register RC4_INT x,y,tx,ty;
int i;
x=key->x;
y=key->y;
d=key->data;
#define LOOP(in,out) \
x=((x+1)&0xff); \
tx=d[x]; \
y=(tx+y)&0xff; \
d[x]=ty=d[y]; \
d[y]=tx; \
(out) = d[(tx+ty)&0xff]^ (in);
#ifndef RC4_INDEX
#define RC4_LOOP(a,b,i) LOOP(*((a)++),*((b)++))
#else
#define RC4_LOOP(a,b,i) LOOP(a[i],b[i])
#endif
i=(int)(len>>3L);
if (i)
{
for (;;)
{
RC4_LOOP(indata,outdata,0);
RC4_LOOP(indata,outdata,1);
RC4_LOOP(indata,outdata,2);
RC4_LOOP(indata,outdata,3);
RC4_LOOP(indata,outdata,4);
RC4_LOOP(indata,outdata,5);
RC4_LOOP(indata,outdata,6);
RC4_LOOP(indata,outdata,7);
#ifdef RC4_INDEX
indata+=8;
outdata+=8;
#endif
if (--i == 0) break;
}
}
i=(int)len&0x07;
if (i)
{
for (;;)
{
RC4_LOOP(indata,outdata,0); if (--i == 0) break;
RC4_LOOP(indata,outdata,1); if (--i == 0) break;
RC4_LOOP(indata,outdata,2); if (--i == 0) break;
RC4_LOOP(indata,outdata,3); if (--i == 0) break;
RC4_LOOP(indata,outdata,4); if (--i == 0) break;
RC4_LOOP(indata,outdata,5); if (--i == 0) break;
RC4_LOOP(indata,outdata,6); if (--i == 0) break;
}
}
key->x=x;
key->y=y;
}
