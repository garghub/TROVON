static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
if ( V_2 -> V_5 != NULL ) {
* V_4 = V_2 -> V_6 ;
F_2 ( V_4 != NULL ) ;
} else
* V_4 = 0 ;
if ( * V_4 == 0 ) {
if ( F_3 ( V_3 ) >= 10 )
return V_7 ;
} else {
if ( ( * V_4 >= 64 ) || ( F_3 ( V_3 ) >= 16 ) )
return V_7 ;
}
return 0 ;
}
static inline int F_4 ( unsigned char V_4 ,
unsigned int V_3 , int V_8 )
{
T_1 V_9 ;
F_5 ( V_10 , ~ V_11 ) ;
if ( V_4 == 0 )
V_9 = ( 1 << ( 22 + F_3 ( V_3 ) ) ) | ( 5 << 9 ) ;
else
V_9 = ( V_4 << 26 ) | ( F_3 ( V_3 ) << 22 ) |
( 1 << 15 ) | ( 5 << 9 ) ;
F_5 ( V_12 , V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 , int V_8 ,
int V_13 , T_2 * V_14 )
{
T_1 V_4 ;
T_1 V_15 = F_7 ( V_16 ) ;
T_1 V_17 ;
T_1 V_18 ;
* V_14 = 0xffffffffU ;
if ( F_1 ( V_2 , V_3 , & V_4 ) == V_7 )
return V_7 ;
V_17 = F_8 ( V_12 ) ;
if ( F_4 ( V_4 , V_3 , V_8 ) < 0 )
return V_7 ;
V_18 =
* ( volatile T_1 * ) ( V_15 + ( F_9 ( V_3 ) << 8 ) +
( V_8 & 0xfffffffc ) ) ;
switch ( V_13 ) {
case 1 :
* V_14 = ( V_18 >> ( ( V_8 & 3 ) << 3 ) ) & 0xffU ;
break;
case 2 :
* V_14 = ( V_18 >> ( ( V_8 & 2 ) << 3 ) ) & 0xffffU ;
break;
case 4 :
* V_14 = V_18 ;
break;
default:
F_5 ( V_12 , V_17 ) ;
return V_19 ;
}
F_5 ( V_12 , V_17 ) ;
if ( F_8 ( V_10 ) & V_11 )
return V_7 ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 , int V_8 ,
int V_13 , T_1 V_14 )
{
T_1 V_4 ;
T_1 V_15 = F_7 ( V_16 ) ;
T_1 V_17 ;
T_1 V_18 ;
int V_21 ;
if ( F_1 ( V_2 , V_3 , & V_4 ) == V_7 )
return V_7 ;
V_17 = F_8 ( V_12 ) ;
if ( F_4 ( V_4 , V_3 , V_8 ) < 0 )
return V_7 ;
V_18 =
* ( volatile T_1 * ) ( V_15 + ( F_9 ( V_3 ) << 8 ) +
( V_8 & 0xfffffffc ) ) ;
switch ( V_13 ) {
case 1 :
V_21 = ( V_8 & 3 ) << 3 ;
V_18 &= ~ ( 0xffU << V_21 ) ;
V_18 |= ( ( V_14 & 0xffU ) << V_21 ) ;
break;
case 2 :
V_21 = ( V_8 & 2 ) << 3 ;
V_18 &= ~ ( 0xffffU << V_21 ) ;
V_18 |= ( ( V_14 & 0xffffU ) << V_21 ) ;
break;
case 4 :
V_18 = V_14 ;
break;
default:
F_5 ( V_12 , V_17 ) ;
return V_19 ;
}
* ( volatile T_1 * ) ( V_15 + ( F_9 ( V_3 ) << 8 ) +
( V_8 & 0xfffffffc ) ) = V_18 ;
F_5 ( V_12 , V_17 ) ;
if ( F_8 ( V_10 ) & V_11 )
return V_7 ;
return V_20 ;
}
