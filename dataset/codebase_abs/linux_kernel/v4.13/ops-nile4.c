static int F_1 ( unsigned char V_1 ,
struct V_2 * V_3 , unsigned int V_4 , int V_5 , T_1 * V_6 )
{
unsigned char V_7 = V_3 -> V_8 ;
T_1 V_9 , V_10 , V_11 ;
if ( ( V_7 == 0 ) && ( F_2 ( V_4 ) > 8 ) )
return V_12 ;
if ( ( V_7 == 0 ) && ( V_4 == F_3 ( 0 , 0 ) ) ) {
if ( V_1 == V_13 ) {
V_14 [ ( 0x200 + V_5 ) >> 2 ] = * V_6 ;
} else {
* V_6 = V_14 [ ( 0x200 + V_5 ) >> 2 ] ;
}
return V_15 ;
}
V_10 = V_14 [ F_4 ( V_16 ) ] ;
V_14 [ F_4 ( V_16 ) ] = 0x0000001a | ( V_7 ? 0x200 : 0 ) ;
V_14 [ F_4 ( V_17 ) ] = 0 ;
V_14 [ F_5 ( V_17 ) ] = 0 ;
if ( V_7 == 0 )
V_9 =
F_6 ( V_18 ) +
( ( 1 << ( F_2 ( V_4 ) + 15 ) ) | ( F_7 ( V_4 ) << 8 )
| ( V_5 & ~ 3 ) ) ;
else
V_9 = F_6 ( V_18 ) | ( V_7 << 16 ) | ( V_4 << 8 ) |
( V_5 & ~ 3 ) ;
if ( V_1 == V_13 )
* ( T_1 * ) V_9 = * V_6 ;
else
* V_6 = * ( T_1 * ) V_9 ;
V_11 = ( V_14 [ F_5 ( V_19 ) ] >> 5 ) & 0x7 ;
V_14 [ F_4 ( V_16 ) ] = V_10 ;
if ( V_11 )
return V_12 ;
return V_15 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_20 , T_1 * V_6 )
{
T_1 V_21 = 0 ;
int V_11 ;
if ( ( V_20 == 2 ) && ( V_5 & 1 ) )
return V_22 ;
else if ( ( V_20 == 4 ) && ( V_5 & 3 ) )
return V_22 ;
V_11 = F_1 ( V_23 , V_3 , V_4 , V_5 ,
& V_21 ) ;
if ( V_11 )
return V_11 ;
if ( V_20 == 1 )
* V_6 = ( V_21 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
else if ( V_20 == 2 )
* V_6 = ( V_21 >> ( ( V_5 & 3 ) << 3 ) ) & 0xffff ;
else
* V_6 = V_21 ;
return V_15 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_20 , T_1 V_6 )
{
T_1 V_21 = 0 ;
int V_11 ;
if ( ( V_20 == 2 ) && ( V_5 & 1 ) )
return V_22 ;
else if ( ( V_20 == 4 ) && ( V_5 & 3 ) )
return V_22 ;
V_11 = F_1 ( V_23 , V_3 , V_4 , V_5 ,
& V_21 ) ;
if ( V_11 )
return V_11 ;
if ( V_20 == 1 )
V_21 = ( V_21 & ~ ( 0xff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_6 << ( ( V_5 & 3 ) << 3 ) ) ;
else if ( V_20 == 2 )
V_21 = ( V_21 & ~ ( 0xffff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_6 << ( ( V_5 & 3 ) << 3 ) ) ;
else
V_21 = V_6 ;
if ( F_1
( V_13 , V_3 , V_4 , V_5 , & V_21 ) )
return - 1 ;
return V_15 ;
}
