void F_1 ( T_1 * V_1 , unsigned long V_2 , const unsigned char * V_3 ,
unsigned char * V_4 )
{
register T_2 * V_5 ;
register T_2 V_6 , V_7 , V_8 , V_9 ;
int V_10 ;
V_6 = V_1 -> V_6 ;
V_7 = V_1 -> V_7 ;
V_5 = V_1 -> V_11 ;
#if F_2 ( V_12 )
# define F_3 ( \
x=(x+1) &0xff, \
tx=d[x], \
y=(tx+y)&0xff, \
ty=d[y], \
d[y]=tx, \
d[x]=ty, \
(RC4_CHUNK)d[(tx+ty)&0xff]\
)
if ( ( ( ( unsigned long ) V_3 & ( sizeof( V_12 ) - 1 ) ) |
( ( unsigned long ) V_4 & ( sizeof( V_12 ) - 1 ) ) ) == 0 )
{
V_12 V_13 , V_14 ;
const union { long V_15 ; char V_16 ; } V_17 = { 1 } ;
if ( ! V_17 . V_16 )
{
# define F_4 ( T_3 ) (((sizeof(RC4_CHUNK)-(c)-1)*8)&(sizeof(RC4_CHUNK)*8-1))
for (; V_2 & ~ ( sizeof( V_12 ) - 1 ) ; V_2 -= sizeof( V_12 ) )
{
V_13 = * ( V_12 * ) V_3 ;
V_14 = F_3 << F_4 ( 0 ) ;
V_14 |= F_3 << F_4 ( 1 ) ;
V_14 |= F_3 << F_4 ( 2 ) ;
V_14 |= F_3 << F_4 ( 3 ) ;
if ( sizeof( V_12 ) == 8 )
{
V_14 |= F_3 << F_4 ( 4 ) ;
V_14 |= F_3 << F_4 ( 5 ) ;
V_14 |= F_3 << F_4 ( 6 ) ;
V_14 |= F_3 << F_4 ( 7 ) ;
}
* ( V_12 * ) V_4 = V_14 ^ V_13 ;
V_3 += sizeof( V_12 ) ;
V_4 += sizeof( V_12 ) ;
}
if ( V_2 )
{
V_12 V_18 = ( V_12 ) - 1 , V_19 ;
V_13 = * ( V_12 * ) V_3 ;
V_19 = * ( V_12 * ) V_4 ;
V_14 = 0 ;
V_10 = F_4 ( 0 ) ;
V_18 <<= ( sizeof( V_12 ) - V_2 ) << 3 ;
switch ( V_2 & ( sizeof( V_12 ) - 1 ) )
{
case 7 : V_14 = F_3 << V_10 , V_10 -= 8 ;
case 6 : V_14 |= F_3 << V_10 , V_10 -= 8 ;
case 5 : V_14 |= F_3 << V_10 , V_10 -= 8 ;
case 4 : V_14 |= F_3 << V_10 , V_10 -= 8 ;
case 3 : V_14 |= F_3 << V_10 , V_10 -= 8 ;
case 2 : V_14 |= F_3 << V_10 , V_10 -= 8 ;
case 1 : V_14 |= F_3 << V_10 , V_10 -= 8 ;
case 0 : ;
}
V_19 &= ~ V_18 ;
V_19 |= ( V_14 ^ V_13 ) & V_18 ;
* ( V_12 * ) V_4 = V_19 ;
}
V_1 -> V_6 = V_6 ;
V_1 -> V_7 = V_7 ;
return;
}
else
{
# define F_5 ( T_3 ) (((c)*8)&(sizeof(RC4_CHUNK)*8-1))
for (; V_2 & ~ ( sizeof( V_12 ) - 1 ) ; V_2 -= sizeof( V_12 ) )
{
V_13 = * ( V_12 * ) V_3 ;
V_14 = F_3 ;
V_14 |= F_3 << 8 ;
V_14 |= F_3 << 16 ;
V_14 |= F_3 << 24 ;
if ( sizeof( V_12 ) == 8 )
{
V_14 |= F_3 << F_5 ( 4 ) ;
V_14 |= F_3 << F_5 ( 5 ) ;
V_14 |= F_3 << F_5 ( 6 ) ;
V_14 |= F_3 << F_5 ( 7 ) ;
}
* ( V_12 * ) V_4 = V_14 ^ V_13 ;
V_3 += sizeof( V_12 ) ;
V_4 += sizeof( V_12 ) ;
}
if ( V_2 )
{
V_12 V_18 = ( V_12 ) - 1 , V_19 ;
V_13 = * ( V_12 * ) V_3 ;
V_19 = * ( V_12 * ) V_4 ;
V_14 = 0 ;
V_10 = 0 ;
V_18 >>= ( sizeof( V_12 ) - V_2 ) << 3 ;
switch ( V_2 & ( sizeof( V_12 ) - 1 ) )
{
case 7 : V_14 = F_3 , V_10 += 8 ;
case 6 : V_14 |= F_3 << V_10 , V_10 += 8 ;
case 5 : V_14 |= F_3 << V_10 , V_10 += 8 ;
case 4 : V_14 |= F_3 << V_10 , V_10 += 8 ;
case 3 : V_14 |= F_3 << V_10 , V_10 += 8 ;
case 2 : V_14 |= F_3 << V_10 , V_10 += 8 ;
case 1 : V_14 |= F_3 << V_10 , V_10 += 8 ;
case 0 : ;
}
V_19 &= ~ V_18 ;
V_19 |= ( V_14 ^ V_13 ) & V_18 ;
* ( V_12 * ) V_4 = V_19 ;
}
V_1 -> V_6 = V_6 ;
V_1 -> V_7 = V_7 ;
return;
}
}
#endif
#define F_6 ( T_4 , T_5 ) \
x=((x+1)&0xff); \
tx=d[x]; \
y=(tx+y)&0xff; \
d[x]=ty=d[y]; \
d[y]=tx; \
(out) = d[(tx+ty)&0xff]^ (in);
#ifndef F_7
#define F_8 ( T_6 , T_7 , V_10 ) LOOP(*((a)++),*((b)++))
#else
#define F_8 ( T_6 , T_7 , V_10 ) LOOP(a[i],b[i])
#endif
V_10 = ( int ) ( V_2 >> 3L ) ;
if ( V_10 )
{
for (; ; )
{
F_8 ( V_3 , V_4 , 0 ) ;
F_8 ( V_3 , V_4 , 1 ) ;
F_8 ( V_3 , V_4 , 2 ) ;
F_8 ( V_3 , V_4 , 3 ) ;
F_8 ( V_3 , V_4 , 4 ) ;
F_8 ( V_3 , V_4 , 5 ) ;
F_8 ( V_3 , V_4 , 6 ) ;
F_8 ( V_3 , V_4 , 7 ) ;
#ifdef F_7
V_3 += 8 ;
V_4 += 8 ;
#endif
if ( -- V_10 == 0 ) break;
}
}
V_10 = ( int ) V_2 & 0x07 ;
if ( V_10 )
{
for (; ; )
{
F_8 ( V_3 , V_4 , 0 ) ; if ( -- V_10 == 0 ) break;
F_8 ( V_3 , V_4 , 1 ) ; if ( -- V_10 == 0 ) break;
F_8 ( V_3 , V_4 , 2 ) ; if ( -- V_10 == 0 ) break;
F_8 ( V_3 , V_4 , 3 ) ; if ( -- V_10 == 0 ) break;
F_8 ( V_3 , V_4 , 4 ) ; if ( -- V_10 == 0 ) break;
F_8 ( V_3 , V_4 , 5 ) ; if ( -- V_10 == 0 ) break;
F_8 ( V_3 , V_4 , 6 ) ; if ( -- V_10 == 0 ) break;
}
}
V_1 -> V_6 = V_6 ;
V_1 -> V_7 = V_7 ;
}
