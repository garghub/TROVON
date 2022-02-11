static int F_1 ( unsigned char V_1 ,
struct V_2 * V_3 ,
unsigned int V_4 , int V_5 ,
T_1 * V_6 )
{
T_1 V_7 = V_3 -> V_8 ;
T_1 V_9 , type ;
T_1 V_10 ;
void * V_11 ;
int V_12 = F_2 ( V_4 ) ;
int V_13 = F_3 ( V_4 ) ;
int V_14 = V_5 & ~ 3 ;
if ( V_7 == 0 ) {
if ( V_12 > V_15 )
return - 1 ;
V_9 = ( 1 << ( V_12 + V_16 ) ) | ( V_13 << 8 ) | V_14 ;
type = 0 ;
} else {
V_9 = ( V_7 << 16 ) | ( V_12 << 11 ) | ( V_13 << 8 ) | V_14 ;
type = 0x10000 ;
}
V_17 |= V_18 | V_19 ;
V_20 = ( V_9 >> 16 ) | type ;
V_10 = V_20 ;
F_4 () ;
V_11 = F_5 ( V_9 & 0xffff ) ;
if ( V_1 == V_21 ) {
F_6 ( F_7 ( * V_6 ) , V_11 ) ;
while ( V_22 & 0xF ) ;
} else {
* V_6 = F_8 ( F_9 ( V_11 ) ) ;
}
if ( V_17 & ( V_18 |
V_19 ) ) {
V_17 |= ( V_18 |
V_19 ) ;
return - 1 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_23 , T_1 * V_24 )
{
T_1 V_6 = 0 ;
if ( ( V_23 == 2 ) && ( V_5 & 1 ) )
return V_25 ;
else if ( ( V_23 == 4 ) && ( V_5 & 3 ) )
return V_25 ;
if ( F_1 ( V_26 , V_3 , V_4 , V_5 ,
& V_6 ) )
return - 1 ;
if ( V_23 == 1 )
* V_24 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xff ;
else if ( V_23 == 2 )
* V_24 = ( V_6 >> ( ( V_5 & 3 ) << 3 ) ) & 0xffff ;
else
* V_24 = V_6 ;
return V_27 ;
}
static int F_11 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_5 , int V_23 , T_1 V_24 )
{
T_1 V_6 = 0 ;
if ( ( V_23 == 2 ) && ( V_5 & 1 ) )
return V_25 ;
else if ( ( V_23 == 4 ) && ( V_5 & 3 ) )
return V_25 ;
if ( V_23 == 4 )
V_6 = V_24 ;
else {
if ( F_1 ( V_26 , V_3 , V_4 ,
V_5 , & V_6 ) )
return - 1 ;
if ( V_23 == 1 )
V_6 = ( V_6 & ~ ( 0xff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_24 << ( ( V_5 & 3 ) << 3 ) ) ;
else if ( V_23 == 2 )
V_6 = ( V_6 & ~ ( 0xffff << ( ( V_5 & 3 ) << 3 ) ) ) |
( V_24 << ( ( V_5 & 3 ) << 3 ) ) ;
}
if ( F_1 ( V_21 , V_3 , V_4 , V_5 ,
& V_6 ) )
return - 1 ;
return V_27 ;
}
