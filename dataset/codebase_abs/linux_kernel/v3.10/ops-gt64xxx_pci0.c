static int F_1 ( unsigned char V_1 ,
struct V_2 * V_3 , unsigned int V_4 , int V_5 , T_1 * V_6 )
{
unsigned char V_7 = V_3 -> V_8 ;
T_1 V_9 ;
if ( ( V_7 == 0 ) && ( V_4 >= F_2 ( 31 , 0 ) ) )
return - 1 ;
F_3 ( V_10 , ~ ( V_11 |
V_12 ) ) ;
F_3 ( V_13 ,
( V_7 << V_14 ) |
( V_4 << V_15 ) |
( ( V_5 / 4 ) << V_16 ) |
V_17 ) ;
if ( V_1 == V_18 ) {
if ( V_7 == 0 && F_4 ( V_4 ) == 0 ) {
F_3 ( V_19 , * V_6 ) ;
} else
F_5 ( V_19 , * V_6 ) ;
} else {
if ( V_7 == 0 && F_4 ( V_4 ) == 0 ) {
* V_6 = F_6 ( V_19 ) ;
} else
* V_6 = F_7 ( V_19 ) ;
}
V_9 = F_6 ( V_10 ) ;
if ( V_9 & ( V_11 | V_12 ) ) {
F_3 ( V_10 , ~ ( V_11 |
V_12 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_20 , T_1 * V_21 )
{
T_1 V_6 = 0 ;
if ( F_1 ( V_22 , V_3 , V_4 ,
V_5 , & V_6 ) )
return V_23 ;
if ( V_20 == 1 )
* V_21 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
else if ( V_20 == 2 )
* V_21 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xffff ;
else
* V_21 = V_6 ;
return V_24 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_20 , T_1 V_21 )
{
T_1 V_6 = 0 ;
if ( V_20 == 4 )
V_6 = V_21 ;
else {
if ( F_1 ( V_22 , V_3 ,
V_4 , V_5 , & V_6 ) )
return V_23 ;
if ( V_20 == 1 )
V_6 = ( V_6 & ~ ( 0xff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_21 << ( ( V_5 & 3 ) << 3 ) ) ;
else if ( V_20 == 2 )
V_6 = ( V_6 & ~ ( 0xffff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_21 << ( ( V_5 & 3 ) << 3 ) ) ;
}
if ( F_1 ( V_18 , V_3 , V_4 ,
V_5 , & V_6 ) )
return V_23 ;
return V_24 ;
}
