static void F_1 ( T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_1 -> V_5 , F_3 ( V_2 ) ) ;
V_4 = ( V_4 & 0xfe ) | ( V_3 & 1 ) ;
F_4 ( V_1 -> V_5 , F_3 ( V_2 ) , V_4 ) ;
}
static void F_5 ( T_1 * V_1 , T_2 V_2 , int V_6 )
{
int V_4 ;
V_4 = F_2 ( V_1 -> V_5 , F_6 ( ( V_2 >= 0x20 ) ? 1 : 0 ) ) ;
if ( V_6 )
V_4 |= ( 1 << ( V_2 & 0x1f ) ) ;
else
V_4 &= ~ ( 1 << ( V_2 & 0x1f ) ) ;
F_4 ( V_1 -> V_5 , F_6 ( ( V_2 >= 0x20 ) ? 1 : 0 ) , V_4 ) ;
}
static int F_7 ( T_1 * V_1 , int V_2 , int V_7 )
{
T_3 * V_8 = & ( V_1 -> V_9 [ V_2 ] ) ;
int V_4 ;
if ( V_7 ) {
F_8 ( V_1 , V_2 , 1 ) ;
F_9 ( V_1 , V_2 , 1 ) ;
F_1 ( V_1 , V_2 , V_7 - 1 ) ;
} else
F_9 ( V_1 , V_2 , 0 ) ;
F_5 ( V_1 , V_2 , 1 ) ;
F_4 ( V_1 -> V_5 , F_10 ( 0 ) , 0x880000 ) ;
#ifdef F_11
F_4 ( V_1 -> V_5 , F_10 ( 1 ) , 0x880000 ) ;
#endif
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 0 ) , 0 ) ;
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 1 ) , 0 ) ;
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 2 ) , 0 ) ;
V_4 = F_2 ( V_1 -> V_5 , F_12 ( V_2 , 3 ) ) ;
F_13 ( V_10 L_1 , V_4 ) ;
F_4 ( V_1 -> V_5 , F_14 ( V_2 , 0 ) , 0 ) ;
F_4 ( V_1 -> V_5 , F_14 ( V_2 , 1 ) , 0 ) ;
F_4 ( V_1 -> V_5 , F_14 ( V_2 , 2 ) , 0 ) ;
F_4 ( V_1 -> V_5 , F_14 ( V_2 , 3 ) , 0 ) ;
F_13 ( V_10 L_2 , F_2 ( V_1 -> V_5 , F_15 ( V_2 ) ) ) ;
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 2 ) , 0xffffffff ) ;
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 3 ) , 0xcff1c810 ) ;
V_8 -> V_11 = V_8 -> V_12 = 0xcfb23e2f ;
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 0 ) , V_8 -> V_11 ) ;
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 1 ) , V_8 -> V_12 ) ;
F_13 ( V_10 L_3 , F_2 ( V_1 -> V_5 , F_15 ( V_2 ) ) ) ;
return 0 ;
}
static void F_16 ( T_1 * V_1 , int V_6 )
{
int V_13 , V_14 , V_15 ;
#define F_17 6
#ifdef F_11
#define F_18 2
#else
#define F_18 1
#endif
for ( V_13 = 0 ; V_13 < F_18 ; V_13 ++ ) {
for ( V_14 = 0 ; V_14 < F_17 ; V_14 ++ ) {
V_15 =
F_19 ( V_1 ,
V_1 -> V_16 , V_6 ,
V_17 ) ;
V_1 -> V_18 [ ( V_13 * F_17 ) + V_14 ] = V_15 ;
F_20 ( V_1 , V_6 , 0x11 ,
F_21 ( V_13 , V_14 + 0x20 ) , F_22 ( V_15 ) ) ;
F_23 ( V_1 , V_6 , V_15 ,
V_1 -> V_19 [ V_14 % 2 ] , 0 ) ;
if ( F_24 ( V_1 ) )
F_23 ( V_1 , V_6 ,
V_15 ,
V_1 -> V_19 [ 2 +
( V_14 % 2 ) ] , 0 ) ;
}
}
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
F_4 ( V_1 -> V_5 , F_25 ( V_13 ) , 1 ) ;
}
}
static int
F_26 ( T_1 * V_1 , unsigned char V_21 , int V_2 ,
T_2 V_22 )
{
int V_23 ;
if ( ( V_21 == 5 ) || ( ( V_21 >= 7 ) && ( V_21 <= 10 ) ) || ( V_21 == 0xc ) ) {
if ( V_2 >= ( V_20 / V_24 ) ) {
F_13
( L_4 ,
V_21 , V_2 ) ;
return 0 ;
}
} else {
if ( V_2 >= V_20 ) {
F_13 ( V_25 L_5 ) ;
return 0 ;
}
}
if ( V_21 > 0xc )
return 0 ;
switch ( V_21 ) {
case 0 :
F_4 ( V_1 -> V_5 , F_25 ( V_2 ) , V_22 ) ;
return 0xc ;
case 1 :
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 0 ) , V_22 ) ;
return 0xc ;
case 2 :
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 1 ) , V_22 ) ;
return 0xc ;
case 3 :
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 2 ) , V_22 ) ;
return 0xc ;
case 4 :
F_4 ( V_1 -> V_5 , F_12 ( V_2 , 3 ) , V_22 ) ;
return 0xc ;
case 6 :
F_4 ( V_1 -> V_5 , F_27 ( V_2 ) , V_22 ) ;
return 0xc ;
case 0xb :
F_4 ( V_1 -> V_5 , F_14 ( V_2 , 3 ) , V_22 ) ;
F_4 ( V_1 -> V_5 , F_14 ( V_2 , 2 ) , V_22 ) ;
F_4 ( V_1 -> V_5 , F_14 ( V_2 , 1 ) , V_22 ) ;
F_4 ( V_1 -> V_5 , F_14 ( V_2 , 0 ) , V_22 ) ;
return 0xc ;
case 5 :
V_23 = F_10 ( V_2 ) ;
break;
case 8 :
V_23 = F_28 ( V_2 ) ;
break;
case 9 :
V_23 = F_29 ( V_2 ) ;
break;
case 0xa :
V_23 = F_30 ( V_2 ) ;
break;
case 0xc :
V_23 = F_6 ( V_2 ) ;
break;
default:
return 0 ;
}
F_4 ( V_1 -> V_5 , V_23 , V_22 ) ;
return 1 ;
}
static void F_31 ( T_1 * V_1 )
{
T_2 V_26 , V_27 , V_28 , V_29 = 0 , V_30 ;
V_29 &= 0xFFFFFFE3 ;
V_29 |= 0x22 ;
V_29 &= 0xFFFFFEBF ;
V_29 |= 0x80 ;
V_29 |= 0x200 ;
V_29 &= 0xfffffffe ;
V_29 &= 0xfffffbff ;
V_29 |= 0x1800 ;
V_26 = 0x10000000 ;
V_28 = 0x00830000 ;
V_27 = 0x00830000 ;
for ( V_30 = 0 ; V_30 < ( V_20 / V_24 ) ; V_30 ++ ) {
F_26 ( V_1 , 0xc , V_30 , 0 ) ;
F_26 ( V_1 , 0xa , V_30 , V_29 ) ;
F_26 ( V_1 , 0x9 , V_30 , V_26 ) ;
F_26 ( V_1 , 0x8 , V_30 , V_28 ) ;
F_26 ( V_1 , 0x5 , V_30 , V_27 ) ;
}
for ( V_30 = 0 ; V_30 < V_20 ; V_30 ++ ) {
F_26 ( V_1 , 0x4 , V_30 , 0 ) ;
F_26 ( V_1 , 0x3 , V_30 , 0 ) ;
F_26 ( V_1 , 0x2 , V_30 , 0 ) ;
F_26 ( V_1 , 0x1 , V_30 , 0 ) ;
F_26 ( V_1 , 0xb , V_30 , 0 ) ;
}
V_29 |= 1 ;
for ( V_30 = 0 ; V_30 < ( V_20 / V_24 ) ; V_30 ++ )
F_26 ( V_1 , 0xa , V_30 , V_29 ) ;
}
