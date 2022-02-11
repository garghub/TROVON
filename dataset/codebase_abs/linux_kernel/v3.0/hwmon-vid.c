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
V_1 &= 0x3f ;
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
static T_1 F_3 ( T_1 V_4 , T_1 V_5 , T_1 V_6 , T_1 V_7 )
{
int V_8 = 0 ;
while ( V_9 [ V_8 ] . V_7 != V_10 ) {
if ( V_9 [ V_8 ] . V_7 == V_7 )
if ( ( V_9 [ V_8 ] . V_4 == V_4 )
&& ( ( V_9 [ V_8 ] . V_5 == V_5 ) ||
( V_9 [ V_8 ] . V_5 >= 0x10 &&
V_5 <= V_9 [ V_8 ] . V_5 ) ||
( V_9 [ V_8 ] . V_5 == V_11 ) ) &&
( V_6 <= V_9 [ V_8 ] . V_6 ) )
return V_9 [ V_8 ] . V_12 ;
V_8 ++ ;
}
return 0 ;
}
T_1 F_4 ( void )
{
struct V_13 * V_14 = & F_5 ( 0 ) ;
T_2 V_15 ;
T_1 V_4 , V_5 , V_6 , V_16 ;
if ( V_14 -> V_17 < 6 )
return 0 ;
V_15 = F_6 ( 1 ) ;
V_4 = ( ( V_15 & 0x00000F00 ) >> 8 ) ;
V_5 = ( ( V_15 & 0x000000F0 ) >> 4 ) ;
V_6 = V_15 & 0xF ;
if ( V_4 == 0xF ) {
V_4 += ( ( V_15 & 0x00F00000 ) >> 20 ) ;
V_5 += ( ( V_15 & 0x000F0000 ) >> 16 ) << 4 ;
}
V_16 = F_3 ( V_4 , V_5 , V_6 , V_14 -> V_18 ) ;
if ( V_16 == 0 )
F_7 ( L_2 ) ;
return V_16 ;
}
T_1 F_4 ( void )
{
F_7 ( L_3 ) ;
return 0 ;
}
