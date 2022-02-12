void RC4(RC4_KEY *key, unsigned long len, const unsigned char *indata,
unsigned char *outdata)
{
register RC4_INT *d;
register RC4_INT x,y,tx,ty;
int i;
x=key->x;
y=key->y;
d=key->data;
#if defined(RC4_CHUNK)
# define RC4_STEP ( \
x=(x+1) &0xff, \
tx=d[x], \
y=(tx+y)&0xff, \
ty=d[y], \
d[y]=tx, \
d[x]=ty, \
(RC4_CHUNK)d[(tx+ty)&0xff]\
)
if ( ( ((unsigned long)indata & (sizeof(RC4_CHUNK)-1)) |
((unsigned long)outdata & (sizeof(RC4_CHUNK)-1)) ) == 0 )
{
RC4_CHUNK ichunk,otp;
const union { long one; char little; } is_endian = {1};
if (!is_endian.little)
{
# define BESHFT(c) (((sizeof(RC4_CHUNK)-(c)-1)*8)&(sizeof(RC4_CHUNK)*8-1))
for (;len&~(sizeof(RC4_CHUNK)-1);len-=sizeof(RC4_CHUNK))
{
ichunk = *(RC4_CHUNK *)indata;
otp = RC4_STEP<<BESHFT(0);
otp |= RC4_STEP<<BESHFT(1);
otp |= RC4_STEP<<BESHFT(2);
otp |= RC4_STEP<<BESHFT(3);
if (sizeof(RC4_CHUNK)==8)
{
otp |= RC4_STEP<<BESHFT(4);
otp |= RC4_STEP<<BESHFT(5);
otp |= RC4_STEP<<BESHFT(6);
otp |= RC4_STEP<<BESHFT(7);
}
*(RC4_CHUNK *)outdata = otp^ichunk;
indata += sizeof(RC4_CHUNK);
outdata += sizeof(RC4_CHUNK);
}
if (len)
{
RC4_CHUNK mask=(RC4_CHUNK)-1, ochunk;
ichunk = *(RC4_CHUNK *)indata;
ochunk = *(RC4_CHUNK *)outdata;
otp = 0;
i = BESHFT(0);
mask <<= (sizeof(RC4_CHUNK)-len)<<3;
switch (len&(sizeof(RC4_CHUNK)-1))
{
case 7: otp = RC4_STEP<<i, i-=8;
case 6: otp |= RC4_STEP<<i, i-=8;
case 5: otp |= RC4_STEP<<i, i-=8;
case 4: otp |= RC4_STEP<<i, i-=8;
case 3: otp |= RC4_STEP<<i, i-=8;
case 2: otp |= RC4_STEP<<i, i-=8;
case 1: otp |= RC4_STEP<<i, i-=8;
case 0: ;
}
ochunk &= ~mask;
ochunk |= (otp^ichunk) & mask;
*(RC4_CHUNK *)outdata = ochunk;
}
key->x=x;
key->y=y;
return;
}
else
{
# define LESHFT(c) (((c)*8)&(sizeof(RC4_CHUNK)*8-1))
for (;len&~(sizeof(RC4_CHUNK)-1);len-=sizeof(RC4_CHUNK))
{
ichunk = *(RC4_CHUNK *)indata;
otp = RC4_STEP;
otp |= RC4_STEP<<8;
otp |= RC4_STEP<<16;
otp |= RC4_STEP<<24;
if (sizeof(RC4_CHUNK)==8)
{
otp |= RC4_STEP<<LESHFT(4);
otp |= RC4_STEP<<LESHFT(5);
otp |= RC4_STEP<<LESHFT(6);
otp |= RC4_STEP<<LESHFT(7);
}
*(RC4_CHUNK *)outdata = otp^ichunk;
indata += sizeof(RC4_CHUNK);
outdata += sizeof(RC4_CHUNK);
}
if (len)
{
RC4_CHUNK mask=(RC4_CHUNK)-1, ochunk;
ichunk = *(RC4_CHUNK *)indata;
ochunk = *(RC4_CHUNK *)outdata;
otp = 0;
i = 0;
mask >>= (sizeof(RC4_CHUNK)-len)<<3;
switch (len&(sizeof(RC4_CHUNK)-1))
{
case 7: otp = RC4_STEP, i+=8;
case 6: otp |= RC4_STEP<<i, i+=8;
case 5: otp |= RC4_STEP<<i, i+=8;
case 4: otp |= RC4_STEP<<i, i+=8;
case 3: otp |= RC4_STEP<<i, i+=8;
case 2: otp |= RC4_STEP<<i, i+=8;
case 1: otp |= RC4_STEP<<i, i+=8;
case 0: ;
}
ochunk &= ~mask;
ochunk |= (otp^ichunk) & mask;
*(RC4_CHUNK *)outdata = ochunk;
}
key->x=x;
key->y=y;
return;
}
}
#endif
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
