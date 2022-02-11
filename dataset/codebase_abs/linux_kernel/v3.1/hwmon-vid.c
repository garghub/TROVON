int F_1 ( int V_1 , T_1 V_2 )
{
int V_3 ;
switch( V_2 ) {
case 100 :
V_1 &= 0x3f ;
if( ( V_1 & 0x1f ) == 0x1f )
return 0 ;
if( ( V_1 & 0x1f ) <= 0x09 || V_1 == 0x0a )
V_3 = 1087500 - ( V_1 & 0x1f ) * 25000 ;
else
V_3 = 1862500 - ( V_1 & 0x1f ) * 25000 ;
if( V_1 & 0x20 )
V_3 -= 12500 ;
return ( ( V_3 + 500 ) / 1000 ) ;
case 110 :
V_1 &= 0xff ;
if ( V_1 < 0x02 || V_1 > 0xb2 )
return 0 ;
return ( ( 1600000 - ( V_1 - 2 ) * 6250 + 500 ) / 1000 ) ;
case 24 :
V_1 &= 0x1f ;
if ( V_1 == 0x1f )
return 0 ;
case 25 :
V_1 &= 0x3f ;
return ( V_1 < 32 ) ? 1550 - 25 * V_1
: 775 - ( 25 * ( V_1 - 31 ) ) / 2 ;
case 91 :
case 90 :
V_1 &= 0x1f ;
return ( V_1 == 0x1f ? 0 :
1850 - V_1 * 25 ) ;
case 85 :
V_1 &= 0x1f ;
return ( ( V_1 & 0x10 ? 25 : 0 ) +
( ( V_1 & 0x0f ) > 0x04 ? 2050 : 1250 ) -
( ( V_1 & 0x0f ) * 50 ) ) ;
case 84 :
V_1 &= 0x0f ;
case 82 :
V_1 &= 0x1f ;
return ( V_1 == 0x1f ? 0 :
V_1 & 0x10 ? 5100 - ( V_1 ) * 100 :
2050 - ( V_1 ) * 50 ) ;
case 17 :
V_1 &= 0x1f ;
return ( V_1 & 0x10 ? 975 - ( V_1 & 0xF ) * 25 :
1750 - V_1 * 50 ) ;
case 13 :
case 131 :
V_1 &= 0x3f ;
if ( V_2 == 131 && V_1 == 0x3f )
V_1 ++ ;
return ( 1708 - V_1 * 16 ) ;
case 14 :
V_1 &= 0x7f ;
return ( V_1 > 0x77 ? 0 : ( 1500000 - ( V_1 * 12500 ) + 500 ) / 1000 ) ;
default:
if ( V_2 )
F_2 ( L_1 ,
( unsigned int ) V_2 ) ;
return 0 ;
}
}
static T_1 F_3 ( void )
{
unsigned int V_3 , V_4 , V_5 ;
static const char * V_6 [ 4 ] = {
L_2 , L_3 , L_4 , L_5
} ;
F_4 ( 0x198 , V_5 , V_3 ) ;
V_3 &= 0xff ;
F_4 ( 0x1154 , V_4 , V_5 ) ;
V_4 = ( ( V_4 >> 4 ) ^ ( V_4 >> 2 ) ) & 0x03 ;
if ( V_3 > 0x3f ) {
F_5 ( L_6 ,
7 , V_6 [ V_4 ] ) ;
return 14 ;
} else {
F_5 ( L_6 ,
6 , V_6 [ V_4 ] ) ;
return V_4 == 2 ? 131 : 13 ;
}
}
static T_1 F_6 ( T_1 V_7 , T_1 V_8 , T_1 V_9 , T_1 V_10 )
{
int V_11 = 0 ;
while ( V_12 [ V_11 ] . V_10 != V_13 ) {
if ( V_12 [ V_11 ] . V_10 == V_10 )
if ( ( V_12 [ V_11 ] . V_7 == V_7 )
&& ( ( V_12 [ V_11 ] . V_8 == V_8 ) ||
( V_12 [ V_11 ] . V_8 >= 0x10 &&
V_8 <= V_12 [ V_11 ] . V_8 ) ||
( V_12 [ V_11 ] . V_8 == V_14 ) ) &&
( V_9 <= V_12 [ V_11 ] . V_9 ) )
return V_12 [ V_11 ] . V_15 ;
V_11 ++ ;
}
return 0 ;
}
T_1 F_7 ( void )
{
struct V_16 * V_17 = & F_8 ( 0 ) ;
T_2 V_18 ;
T_1 V_7 , V_8 , V_9 , V_19 ;
if ( V_17 -> V_20 < 6 )
return 0 ;
V_18 = F_9 ( 1 ) ;
V_7 = ( ( V_18 & 0x00000F00 ) >> 8 ) ;
V_8 = ( ( V_18 & 0x000000F0 ) >> 4 ) ;
V_9 = V_18 & 0xF ;
if ( V_7 == 0xF ) {
V_7 += ( ( V_18 & 0x00F00000 ) >> 20 ) ;
V_8 += ( ( V_18 & 0x000F0000 ) >> 16 ) << 4 ;
}
V_19 = F_6 ( V_7 , V_8 , V_9 , V_17 -> V_21 ) ;
if ( V_19 == 134 )
V_19 = F_3 () ;
if ( V_19 == 0 )
F_5 ( L_7 ) ;
return V_19 ;
}
T_1 F_7 ( void )
{
F_5 ( L_8 ) ;
return 0 ;
}
