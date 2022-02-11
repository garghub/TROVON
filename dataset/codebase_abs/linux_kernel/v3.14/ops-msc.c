static int F_1 ( unsigned char V_1 ,
struct V_2 * V_3 , unsigned int V_4 , int V_5 , T_1 * V_6 )
{
unsigned char V_7 = V_3 -> V_8 ;
T_1 V_9 ;
F_2 ( V_10 ,
( V_11 | V_12 ) ) ;
F_2 ( V_13 ,
( ( V_7 << V_14 ) |
( F_3 ( V_4 ) << V_15 ) |
( F_4 ( V_4 ) << V_16 ) |
( ( V_5 / 4 ) << V_17 ) ) ) ;
if ( V_1 == V_18 )
F_2 ( V_19 , * V_6 ) ;
else
F_5 ( V_19 , * V_6 ) ;
F_5 ( V_10 , V_9 ) ;
if ( V_9 & ( V_11 | V_12 ) ) {
F_2 ( V_10 ,
( V_11 | V_12 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_20 , T_1 * V_21 )
{
T_1 V_6 = 0 ;
if ( ( V_20 == 2 ) && ( V_5 & 1 ) )
return V_22 ;
else if ( ( V_20 == 4 ) && ( V_5 & 3 ) )
return V_22 ;
if ( F_1 ( V_23 , V_3 , V_4 , V_5 ,
& V_6 ) )
return - 1 ;
if ( V_20 == 1 )
* V_21 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
else if ( V_20 == 2 )
* V_21 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xffff ;
else
* V_21 = V_6 ;
return V_24 ;
}
static int F_7 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_20 , T_1 V_21 )
{
T_1 V_6 = 0 ;
if ( ( V_20 == 2 ) && ( V_5 & 1 ) )
return V_22 ;
else if ( ( V_20 == 4 ) && ( V_5 & 3 ) )
return V_22 ;
if ( V_20 == 4 )
V_6 = V_21 ;
else {
if ( F_1 ( V_23 , V_3 , V_4 ,
V_5 , & V_6 ) )
return - 1 ;
if ( V_20 == 1 )
V_6 = ( V_6 & ~ ( 0xff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_21 << ( ( V_5 & 3 ) << 3 ) ) ;
else if ( V_20 == 2 )
V_6 = ( V_6 & ~ ( 0xffff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_21 << ( ( V_5 & 3 ) << 3 ) ) ;
}
if ( F_1 ( V_18 , V_3 , V_4 , V_5 ,
& V_6 ) )
return - 1 ;
return V_24 ;
}
