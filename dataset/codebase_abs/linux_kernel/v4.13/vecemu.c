static unsigned int F_1 ( unsigned int V_1 )
{
int exp , V_2 ;
unsigned int V_3 , V_4 ;
exp = ( ( V_1 >> 23 ) & 0xff ) - 127 ;
if ( exp > 7 ) {
if ( exp == 128 && ( V_1 & 0x7fffff ) != 0 )
return V_1 | 0x400000 ;
return ( V_1 & 0x80000000 ) ? 0 : 0x7f800000 ;
}
if ( exp < - 23 )
return 0x3f800000 ;
V_2 = ( V_1 & 0x7fffff ) | 0x800000 ;
if ( exp > 0 )
V_2 <<= exp ;
else
V_2 >>= - exp ;
if ( V_1 & 0x80000000 )
V_2 = - V_2 ;
exp = ( V_2 >> 23 ) + 126 ;
if ( exp >= 254 )
return 0x7f800000 ;
if ( exp < - 23 )
return 0 ;
V_3 = V_5 [ ( V_2 >> 20 ) & 7 ] ;
asm("mulhwu %0,%1,%2" : "=r" (frac)
: "r" (pwr << 12), "r" (0x172b83ff));
asm("mulhwu %0,%1,%2" : "=r" (frac) : "r" (frac), "r" (mant));
V_3 += V_4 ;
if ( exp >= 0 )
return V_3 + ( exp << 23 ) ;
exp = - exp ;
V_3 += 1 << ( exp - 1 ) ;
return V_3 >> exp ;
}
static unsigned int F_2 ( unsigned int V_1 )
{
int exp , V_3 , V_6 , V_4 ;
exp = V_1 & 0x7f800000 ;
V_3 = V_1 & 0x7fffff ;
if ( exp == 0x7f800000 ) {
if ( V_3 != 0 )
V_1 |= 0x400000 ;
return V_1 ;
}
if ( ( exp | V_3 ) == 0 )
return 0xff800000 ;
if ( exp == 0 ) {
asm("cntlzw %0,%1" : "=r" (lz) : "r" (mant));
V_3 <<= V_6 - 8 ;
exp = ( - 118 - V_6 ) << 23 ;
} else {
V_3 |= 0x800000 ;
exp -= 127 << 23 ;
}
if ( V_3 >= 0xb504f3 ) {
exp |= 0x400000 ;
asm("mulhwu %0,%1,%2" : "=r" (mant)
: "r" (mant), "r" (0xb504f334));
}
if ( V_3 >= 0x9837f0 ) {
exp |= 0x200000 ;
asm("mulhwu %0,%1,%2" : "=r" (mant)
: "r" (mant), "r" (0xd744fccb));
}
if ( V_3 >= 0x8b95c2 ) {
exp |= 0x100000 ;
asm("mulhwu %0,%1,%2" : "=r" (mant)
: "r" (mant), "r" (0xeac0c6e8));
}
if ( V_3 > 0x800000 ) {
asm("mulhwu %0,%1,%2" : "=r" (frac)
: "r" ((mant - 0x800000) << 1), "r" (0xb0c7cd3a));
exp += V_4 ;
}
V_1 = exp & 0x80000000 ;
if ( exp != 0 ) {
if ( V_1 )
exp = - exp ;
asm("cntlzw %0,%1" : "=r" (lz) : "r" (exp));
V_6 = 8 - V_6 ;
if ( V_6 > 0 )
exp >>= V_6 ;
else if ( V_6 < 0 )
exp <<= - V_6 ;
V_1 += ( ( V_6 + 126 ) << 23 ) + exp ;
}
return V_1 ;
}
static int F_3 ( unsigned int V_7 , int V_8 , unsigned int * V_9 )
{
int exp , V_3 ;
exp = ( V_7 >> 23 ) & 0xff ;
V_3 = V_7 & 0x7fffff ;
if ( exp == 255 && V_3 != 0 )
return 0 ;
exp = exp - 127 + V_8 ;
if ( exp < 0 )
return 0 ;
if ( exp >= 31 ) {
if ( V_7 + ( V_8 << 23 ) != 0xcf000000 )
* V_9 |= V_10 ;
return ( V_7 & 0x80000000 ) ? 0x80000000 : 0x7fffffff ;
}
V_3 |= 0x800000 ;
V_3 = ( V_3 << 7 ) >> ( 30 - exp ) ;
return ( V_7 & 0x80000000 ) ? - V_3 : V_3 ;
}
static unsigned int F_4 ( unsigned int V_7 , int V_8 , unsigned int * V_9 )
{
int exp ;
unsigned int V_3 ;
exp = ( V_7 >> 23 ) & 0xff ;
V_3 = V_7 & 0x7fffff ;
if ( exp == 255 && V_3 != 0 )
return 0 ;
exp = exp - 127 + V_8 ;
if ( exp < 0 )
return 0 ;
if ( V_7 & 0x80000000 ) {
* V_9 |= V_10 ;
return 0 ;
}
if ( exp >= 32 ) {
* V_9 |= V_10 ;
return 0xffffffff ;
}
V_3 |= 0x800000 ;
V_3 = ( V_3 << 8 ) >> ( 31 - exp ) ;
return V_3 ;
}
static unsigned int F_5 ( unsigned int V_7 )
{
int exp ;
exp = ( ( V_7 >> 23 ) & 0xff ) - 127 ;
if ( exp == 128 && ( V_7 & 0x7fffff ) != 0 )
return V_7 | 0x400000 ;
if ( exp >= 23 )
return V_7 ;
if ( exp < 0 )
return V_7 & 0x80000000 ;
return V_7 & ~ ( 0x7fffff >> exp ) ;
}
static unsigned int F_6 ( unsigned int V_7 )
{
int exp , V_11 ;
exp = ( ( V_7 >> 23 ) & 0xff ) - 127 ;
if ( exp == 128 && ( V_7 & 0x7fffff ) != 0 )
return V_7 | 0x400000 ;
if ( exp >= 23 )
return V_7 ;
if ( ( V_7 & 0x7fffffff ) == 0 )
return V_7 ;
if ( exp < 0 )
return ( V_7 & 0x80000000 ) | 0x3f800000 ;
V_11 = 0x7fffff >> exp ;
return ( V_7 + V_11 ) & ~ V_11 ;
}
static unsigned int F_7 ( unsigned int V_7 )
{
int exp , V_12 ;
exp = ( ( V_7 >> 23 ) & 0xff ) - 127 ;
if ( exp == 128 && ( V_7 & 0x7fffff ) != 0 )
return V_7 | 0x400000 ;
if ( exp >= 23 )
return V_7 ;
if ( exp < - 1 )
return V_7 & 0x80000000 ;
if ( exp == - 1 )
return ( V_7 & 0x80000000 ) | 0x3f800000 ;
V_12 = 0x400000 >> exp ;
return ( V_7 + V_12 ) & ~ ( 0x7fffff >> exp ) ;
}
int F_8 ( struct V_13 * V_14 )
{
unsigned int V_15 , V_16 ;
unsigned int V_17 , V_18 , V_19 , V_20 ;
T_1 * V_21 ;
if ( F_9 ( V_15 , ( unsigned int V_22 * ) V_14 -> V_23 ) )
return - V_24 ;
if ( ( V_15 >> 26 ) != 4 )
return - V_25 ;
V_20 = ( V_15 >> 21 ) & 0x1f ;
V_17 = ( V_15 >> 16 ) & 0x1f ;
V_18 = ( V_15 >> 11 ) & 0x1f ;
V_19 = ( V_15 >> 6 ) & 0x1f ;
V_21 = V_26 -> V_27 . V_28 . V_29 ;
switch ( V_15 & 0x3f ) {
case 10 :
switch ( V_19 ) {
case 0 :
F_10 ( & V_21 [ V_20 ] , & V_21 [ V_17 ] , & V_21 [ V_18 ] ) ;
break;
case 1 :
F_11 ( & V_21 [ V_20 ] , & V_21 [ V_17 ] , & V_21 [ V_18 ] ) ;
break;
case 4 :
F_12 ( & V_21 [ V_20 ] , & V_21 [ V_18 ] ) ;
break;
case 5 :
F_13 ( & V_21 [ V_20 ] , & V_21 [ V_18 ] ) ;
break;
case 6 :
for ( V_16 = 0 ; V_16 < 4 ; ++ V_16 )
V_21 [ V_20 ] . V_30 [ V_16 ] = F_1 ( V_21 [ V_18 ] . V_30 [ V_16 ] ) ;
break;
case 7 :
for ( V_16 = 0 ; V_16 < 4 ; ++ V_16 )
V_21 [ V_20 ] . V_30 [ V_16 ] = F_2 ( V_21 [ V_18 ] . V_30 [ V_16 ] ) ;
break;
case 8 :
for ( V_16 = 0 ; V_16 < 4 ; ++ V_16 )
V_21 [ V_20 ] . V_30 [ V_16 ] = F_7 ( V_21 [ V_18 ] . V_30 [ V_16 ] ) ;
break;
case 9 :
for ( V_16 = 0 ; V_16 < 4 ; ++ V_16 )
V_21 [ V_20 ] . V_30 [ V_16 ] = F_5 ( V_21 [ V_18 ] . V_30 [ V_16 ] ) ;
break;
case 10 :
for ( V_16 = 0 ; V_16 < 4 ; ++ V_16 ) {
T_2 V_7 = V_21 [ V_18 ] . V_30 [ V_16 ] ;
V_7 = ( V_7 & 0x80000000 ) ? F_5 ( V_7 ) : F_6 ( V_7 ) ;
V_21 [ V_20 ] . V_30 [ V_16 ] = V_7 ;
}
break;
case 11 :
for ( V_16 = 0 ; V_16 < 4 ; ++ V_16 ) {
T_2 V_7 = V_21 [ V_18 ] . V_30 [ V_16 ] ;
V_7 = ( V_7 & 0x80000000 ) ? F_6 ( V_7 ) : F_5 ( V_7 ) ;
V_21 [ V_20 ] . V_30 [ V_16 ] = V_7 ;
}
break;
case 14 :
for ( V_16 = 0 ; V_16 < 4 ; ++ V_16 )
V_21 [ V_20 ] . V_30 [ V_16 ] = F_4 ( V_21 [ V_18 ] . V_30 [ V_16 ] , V_17 ,
& V_26 -> V_27 . V_28 . V_31 . V_30 [ 3 ] ) ;
break;
case 15 :
for ( V_16 = 0 ; V_16 < 4 ; ++ V_16 )
V_21 [ V_20 ] . V_30 [ V_16 ] = F_3 ( V_21 [ V_18 ] . V_30 [ V_16 ] , V_17 ,
& V_26 -> V_27 . V_28 . V_31 . V_30 [ 3 ] ) ;
break;
default:
return - V_25 ;
}
break;
case 46 :
F_14 ( & V_21 [ V_20 ] , & V_21 [ V_17 ] , & V_21 [ V_18 ] , & V_21 [ V_19 ] ) ;
break;
case 47 :
F_15 ( & V_21 [ V_20 ] , & V_21 [ V_17 ] , & V_21 [ V_18 ] , & V_21 [ V_19 ] ) ;
break;
default:
return - V_25 ;
}
return 0 ;
}
