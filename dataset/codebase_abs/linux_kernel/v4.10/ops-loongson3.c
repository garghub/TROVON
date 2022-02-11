static int F_1 ( unsigned char V_1 ,
struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , T_1 * V_6 )
{
unsigned char V_7 = V_3 -> V_8 ;
T_2 V_9 , type ;
void * V_10 ;
int V_11 = F_2 ( V_4 ) ;
int V_12 = F_3 ( V_4 ) ;
int V_13 = V_5 & ~ 3 ;
V_9 = ( V_7 << 16 ) | ( V_11 << 11 ) | ( V_12 << 8 ) | V_13 ;
if ( V_7 == 0 ) {
if ( V_11 > 31 )
return V_14 ;
V_10 = ( void * ) ( F_4 ( V_15 ) | ( V_9 & 0xffff ) ) ;
type = 0 ;
} else {
V_10 = ( void * ) ( F_4 ( V_16 ) | ( V_9 ) ) ;
type = 0x10000 ;
}
if ( V_1 == V_17 )
F_5 ( * V_6 , V_10 ) ;
else {
* V_6 = F_6 ( V_10 ) ;
if ( * V_6 == 0xffffffff ) {
* V_6 = - 1 ;
return V_14 ;
}
}
return V_18 ;
}
static int F_7 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_19 , T_1 * V_20 )
{
T_1 V_6 = 0 ;
int V_21 = F_1 ( V_22 ,
V_3 , V_4 , V_5 , & V_6 ) ;
if ( V_21 != V_18 )
return V_21 ;
if ( V_19 == 1 )
* V_20 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
else if ( V_19 == 2 )
* V_20 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xffff ;
else
* V_20 = V_6 ;
return V_18 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_19 , T_1 V_20 )
{
T_1 V_6 = 0 ;
int V_21 ;
if ( V_19 == 4 )
V_6 = V_20 ;
else {
V_21 = F_1 ( V_22 ,
V_3 , V_4 , V_5 , & V_6 ) ;
if ( V_21 != V_18 )
return V_21 ;
if ( V_19 == 1 )
V_6 = ( V_6 & ~ ( 0xff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_20 << ( ( V_5 & 3 ) << 3 ) ) ;
else if ( V_19 == 2 )
V_6 = ( V_6 & ~ ( 0xffff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_20 << ( ( V_5 & 3 ) << 3 ) ) ;
}
V_21 = F_1 ( V_17 ,
V_3 , V_4 , V_5 , & V_6 ) ;
return V_21 ;
}
