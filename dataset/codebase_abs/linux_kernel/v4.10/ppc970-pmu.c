static int F_1 ( T_1 V_1 )
{
int V_2 , V_3 , V_4 , V_5 , V_6 ;
unsigned int V_7 ;
V_2 = ( V_1 >> V_8 ) & V_9 ;
V_3 = V_1 & V_10 ;
if ( V_2 ) {
if ( V_11 [ V_2 - 1 ] & ( 1 << V_3 ) )
return 1 ;
if ( V_3 == 0 )
V_6 = ( V_2 <= 4 ) ? V_2 - 1 : 8 - V_2 ;
else if ( V_3 == 7 || V_3 == 13 )
V_6 = 4 ;
else
return 0 ;
} else
V_6 = V_3 ;
V_5 = ( V_1 >> V_12 ) & V_13 ;
V_4 = ( V_1 >> V_14 ) & V_15 ;
V_7 = 0 ;
switch ( V_4 ) {
case V_16 :
V_7 = 0x4c ;
break;
case V_17 :
V_7 = 0x085dff00 ;
break;
case V_18 :
V_7 = 0x50 << 24 ;
break;
}
return ( V_7 >> ( V_5 * 8 + V_6 ) ) & 1 ;
}
static int F_2 ( T_1 V_1 , unsigned long * V_19 ,
unsigned long * V_20 )
{
int V_2 , V_5 , V_4 , V_21 , V_22 ;
unsigned long V_7 = 0 , V_23 = 0 ;
int V_24 = - 1 ;
V_2 = ( V_1 >> V_8 ) & V_9 ;
if ( V_2 ) {
if ( V_2 > 8 )
return - 1 ;
V_21 = ( V_2 - 1 ) * 2 ;
V_7 |= 2 << V_21 ;
V_23 |= 1 << V_21 ;
V_24 = ( ( V_2 - 1 ) >> 1 ) & 1 ;
}
V_4 = ( V_1 >> V_14 ) & V_15 ;
if ( V_4 ) {
if ( V_4 > V_25 )
return - 1 ;
V_7 |= V_26 [ V_4 ] [ 0 ] ;
V_23 |= V_26 [ V_4 ] [ 1 ] ;
V_5 = ( V_1 >> V_12 ) & V_13 ;
if ( ! V_2 )
V_24 = V_5 & 1 ;
V_7 |= 0xfULL << ( 28 - 4 * V_5 ) ;
V_23 |= ( unsigned long ) V_4 << ( 28 - 4 * V_5 ) ;
}
if ( V_24 == 0 ) {
V_7 |= 0x8000000000ull ;
V_23 |= 0x1000000000ull ;
} else if ( V_24 == 1 ) {
V_7 |= 0x800000000ull ;
V_23 |= 0x100000000ull ;
}
V_22 = ( V_1 >> V_27 ) & V_28 ;
if ( V_22 ) {
V_7 |= 3ull << 48 ;
V_23 |= ( unsigned long ) V_22 << 48 ;
}
* V_19 = V_7 ;
* V_20 = V_23 ;
return 0 ;
}
static int F_3 ( T_1 V_1 , unsigned int V_29 , T_1 V_30 [] )
{
V_30 [ 0 ] = V_1 ;
if ( V_1 == 0x2002 || V_1 == 0x3002 ) {
V_30 [ 1 ] = V_1 ^ 0x1000 ;
return 2 ;
}
return 1 ;
}
static int F_4 ( T_1 V_1 [] , int V_31 ,
unsigned int V_32 [] , unsigned long V_33 [] , struct V_34 * V_35 [] )
{
unsigned long V_36 = 0 , V_37 = 0 , V_38 = 0 ;
unsigned int V_2 , V_4 , V_5 , V_3 ;
unsigned int V_39 , V_24 ;
unsigned int V_40 = 0 ;
unsigned int V_41 [ 2 ] ;
unsigned char V_42 [ 4 ] ;
unsigned char V_43 [ 16 ] ;
unsigned char V_44 [] = { 0 , 0 << 3 , 3 << 3 , 1 << 3 , 2 << 3 , 0 | 4 , 3 | 4 } ;
unsigned char V_45 [ 2 ] ;
unsigned char V_46 [ 8 ] ;
int V_47 ;
int V_22 ;
if ( V_31 > 8 )
return - 1 ;
V_41 [ 0 ] = V_41 [ 1 ] = 0 ;
memset ( V_42 , 0 , sizeof( V_42 ) ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
for ( V_47 = 0 ; V_47 < V_31 ; ++ V_47 ) {
V_2 = ( V_1 [ V_47 ] >> V_8 ) & V_9 ;
if ( V_2 ) {
if ( V_40 & ( 1 << ( V_2 - 1 ) ) )
return - 1 ;
V_40 |= 1 << ( V_2 - 1 ) ;
++ V_41 [ ( ( V_2 - 1 ) >> 1 ) & 1 ] ;
}
V_4 = ( V_1 [ V_47 ] >> V_14 ) & V_15 ;
V_5 = ( V_1 [ V_47 ] >> V_12 ) & V_13 ;
if ( V_4 ) {
if ( V_4 > V_25 )
return - 1 ;
if ( ! V_2 )
++ V_41 [ V_5 & 1 ] ;
if ( V_42 [ V_5 ] && V_42 [ V_5 ] != V_4 )
return - 1 ;
V_42 [ V_5 ] = V_4 ;
V_43 [ V_4 ] = 1 ;
}
}
if ( V_41 [ 0 ] > 4 || V_41 [ 1 ] > 4 )
return - 1 ;
if ( V_43 [ V_48 ] &
( V_43 [ V_49 ] | V_43 [ V_50 ] | V_43 [ V_16 ] ) )
V_44 [ V_48 ] = 2 | 4 ;
V_45 [ 0 ] = V_45 [ 1 ] = 0 ;
for ( V_47 = V_49 ; V_47 <= V_51 ; ++ V_47 ) {
if ( ! V_43 [ V_47 ] )
continue;
V_39 = V_44 [ V_47 ] ;
++ V_45 [ ( V_39 >> 2 ) & 1 ] ;
V_37 |= ( unsigned long ) ( V_39 & ~ 4 ) << V_52 ;
}
if ( V_45 [ 0 ] > 1 || V_45 [ 1 ] > 1 )
return - 1 ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
V_4 = V_42 [ V_5 ] ;
if ( ! V_4 )
continue;
if ( V_4 <= V_51 )
V_39 = ( V_44 [ V_4 ] >> 2 ) & 1 ;
else if ( V_4 == V_17 )
V_39 = 2 ;
else {
V_39 = 3 ;
if ( V_4 == V_18 && V_5 >= 2 )
V_37 |= 1ull << ( V_53 + 3 - V_5 ) ;
}
V_37 |= ( unsigned long ) V_39
<< ( V_54 - 2 * V_5 ) ;
}
memset ( V_46 , 0x8 , sizeof( V_46 ) ) ;
for ( V_47 = 0 ; V_47 < V_31 ; ++ V_47 ) {
V_2 = ( V_1 [ V_47 ] >> V_8 ) & V_9 ;
V_4 = ( V_1 [ V_47 ] >> V_14 ) & V_15 ;
V_5 = ( V_1 [ V_47 ] >> V_12 ) & V_13 ;
V_3 = V_1 [ V_47 ] & V_10 ;
if ( ! V_2 ) {
if ( V_4 )
V_3 |= 0x10 | ( ( V_5 & 2 ) << 2 ) ;
else
V_3 |= 8 ;
for ( V_2 = 0 ; V_2 < 8 ; ++ V_2 ) {
if ( V_40 & ( 1 << V_2 ) )
continue;
V_24 = ( V_2 >> 1 ) & 1 ;
if ( V_4 ) {
if ( V_24 == ( V_5 & 1 ) )
break;
} else if ( V_41 [ V_24 ] < 4 ) {
++ V_41 [ V_24 ] ;
break;
}
}
V_40 |= 1 << V_2 ;
} else {
-- V_2 ;
if ( V_3 == 0 && ( V_5 & 2 ) )
V_37 |= 1ull << V_55 [ V_2 ] ;
}
V_46 [ V_2 ] = V_3 ;
V_32 [ V_47 ] = V_2 ;
V_22 = ( V_1 [ V_47 ] >> V_27 ) & V_28 ;
V_37 |= V_22 ;
if ( F_1 ( V_1 [ V_47 ] ) )
V_38 |= V_56 ;
}
for ( V_2 = 0 ; V_2 < 2 ; ++ V_2 )
V_36 |= V_46 [ V_2 ] << ( V_57 - 7 * V_2 ) ;
for (; V_2 < 8 ; ++ V_2 )
V_37 |= ( unsigned long ) V_46 [ V_2 ]
<< ( V_58 - 5 * ( V_2 - 2 ) ) ;
if ( V_40 & 1 )
V_36 |= V_59 ;
if ( V_40 & 0xfe )
V_36 |= V_60 ;
V_38 |= 0x2000 ;
V_33 [ 0 ] = V_36 ;
V_33 [ 1 ] = V_37 ;
V_33 [ 2 ] = V_38 ;
return 0 ;
}
static void F_5 ( unsigned int V_2 , unsigned long V_33 [] )
{
int V_61 , V_47 ;
if ( V_2 <= 1 ) {
V_61 = V_57 - 7 * V_2 ;
V_47 = 0 ;
} else {
V_61 = V_58 - 5 * ( V_2 - 2 ) ;
V_47 = 1 ;
}
V_33 [ V_47 ] = ( V_33 [ V_47 ] & ~ ( 0x1fUL << V_61 ) ) | ( 0x08UL << V_61 ) ;
}
static int T_2 F_6 ( void )
{
if ( ! V_62 -> V_63 ||
( strcmp ( V_62 -> V_63 , L_1 )
&& strcmp ( V_62 -> V_63 , L_2 ) ) )
return - V_64 ;
return F_7 ( & V_65 ) ;
}
