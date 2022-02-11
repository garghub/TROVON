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
else if ( V_3 == 6 )
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
if ( V_1 & V_17 )
V_7 = 1 << 28 ;
else
V_7 = 6 << 24 ;
break;
case V_18 :
V_7 = 0x083dff00 ;
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
V_22 = ( V_2 - 1 ) * 2 ;
V_7 |= 2 << V_22 ;
V_23 |= 1 << V_22 ;
V_24 = ( ( V_2 - 1 ) >> 1 ) & 1 ;
}
V_4 = ( V_1 >> V_14 ) & V_15 ;
V_5 = ( V_1 >> V_12 ) & V_13 ;
if ( V_4 ) {
V_21 = ( V_1 >> V_25 ) & V_26 ;
if ( ! V_2 )
V_24 = V_5 & 1 ;
if ( ! V_27 [ V_4 ] . V_4 )
return - 1 ;
V_7 |= V_27 [ V_4 ] . V_7 ;
V_23 |= V_27 [ V_4 ] . V_23 ;
V_22 = V_27 [ V_4 ] . V_28 ;
if ( V_22 > 1 )
V_23 |= ( unsigned long ) V_21 << V_22 ;
else if ( V_21 != V_22 )
return - 1 ;
V_4 = V_27 [ V_4 ] . V_4 ;
V_7 |= 0xfULL << ( 28 - 4 * V_5 ) ;
V_23 |= ( unsigned long ) V_4 << ( 28 - 4 * V_5 ) ;
}
if ( V_24 == 0 ) {
V_7 |= 0x8000000000ull ;
V_23 |= 0x1000000000ull ;
} else {
V_7 |= 0x800000000ull ;
V_23 |= 0x100000000ull ;
}
if ( F_1 ( V_1 ) ) {
V_7 |= 1ull << 56 ;
V_23 |= 1ull << 56 ;
}
if ( V_2 && ( V_1 & V_10 ) == 6 && V_5 == 2 )
V_7 |= 1ull << 56 ;
* V_19 = V_7 ;
* V_20 = V_23 ;
return 0 ;
}
static int F_3 ( T_1 V_1 , unsigned int V_29 , T_1 V_30 [] )
{
int V_31 , V_32 , V_33 ;
V_30 [ 0 ] = V_1 ;
V_33 = 1 ;
if ( V_1 == 0x8003 || V_1 == 0x0224 ) {
V_30 [ 1 ] = V_1 ^ ( 0x8003 ^ 0x0224 ) ;
return 2 ;
}
if ( V_1 == 0x0c13 || V_1 == 0x0c23 ) {
V_30 [ 1 ] = V_1 ^ ( 0x0c13 ^ 0x0c23 ) ;
return 2 ;
}
for ( V_31 = 0 ; V_31 < F_4 ( V_34 ) ; ++ V_31 ) {
if ( V_1 == V_34 [ V_31 ] ) {
for ( V_32 = 0 ; V_32 < F_4 ( V_34 ) ; ++ V_32 )
if ( V_32 != V_31 )
V_30 [ V_33 ++ ] = V_34 [ V_32 ] ;
break;
}
}
return V_33 ;
}
static int F_5 ( T_1 V_1 [] , int V_35 ,
unsigned int V_36 [] , unsigned long V_37 [] , struct V_38 * V_39 [] )
{
unsigned long V_40 = 0 , V_41 = 0 , V_42 = 0 ;
unsigned int V_2 , V_4 , V_5 , V_3 , V_21 ;
unsigned int V_43 , V_24 ;
unsigned int V_44 = 0 ;
unsigned int V_45 [ 2 ] ;
unsigned char V_46 [ 4 ] ;
unsigned char V_47 [ 16 ] ;
unsigned int V_48 = 0 ;
int V_31 ;
if ( V_35 > 8 )
return - 1 ;
V_45 [ 0 ] = V_45 [ 1 ] = 0 ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 ) {
V_2 = ( V_1 [ V_31 ] >> V_8 ) & V_9 ;
if ( V_2 ) {
if ( V_44 & ( 1 << ( V_2 - 1 ) ) )
return - 1 ;
V_44 |= 1 << ( V_2 - 1 ) ;
++ V_45 [ ( ( V_2 - 1 ) >> 1 ) & 1 ] ;
}
V_4 = ( V_1 [ V_31 ] >> V_14 ) & V_15 ;
V_5 = ( V_1 [ V_31 ] >> V_12 ) & V_13 ;
V_21 = ( V_1 [ V_31 ] >> V_25 ) & V_26 ;
if ( V_4 ) {
if ( ! V_2 )
++ V_45 [ V_5 & 1 ] ;
if ( V_4 == 6 || V_4 == 8 )
V_4 = ( V_4 >> 1 ) - 1 ;
if ( V_46 [ V_5 ] && V_46 [ V_5 ] != V_4 )
return - 1 ;
V_46 [ V_5 ] = V_4 ;
V_21 <<= V_4 ;
if ( V_47 [ V_4 ] && V_21 != ( V_48 & V_21 ) )
return - 1 ;
V_47 [ V_4 ] = 1 ;
V_48 |= V_21 ;
}
}
if ( V_45 [ 0 ] > 4 || V_45 [ 1 ] > 4 )
return - 1 ;
if ( V_47 [ 2 ] & ( V_47 [ 1 ] | ( V_47 [ 3 ] & V_47 [ 9 ] ) ) ) {
V_47 [ 6 ] = 1 ;
V_47 [ 2 ] = 0 ;
}
if ( V_47 [ 3 ] & ( V_47 [ 1 ] | V_47 [ 2 ] ) ) {
V_47 [ 8 ] = 1 ;
V_47 [ 3 ] = 0 ;
V_48 = ( V_48 & ~ 8 ) | ( ( V_48 & 8 ) << 5 ) ;
}
if ( V_47 [ 1 ] + V_47 [ 2 ] + V_47 [ 3 ] > 1 ||
V_47 [ 4 ] + V_47 [ 6 ] + V_47 [ 7 ] > 1 ||
V_47 [ 8 ] + V_47 [ 9 ] > 1 ||
( V_47 [ 5 ] | V_47 [ 10 ] | V_47 [ 11 ] |
V_47 [ 13 ] | V_47 [ 14 ] ) )
return - 1 ;
V_41 |= ( unsigned long ) ( V_47 [ 3 ] * 2 + V_47 [ 2 ] )
<< V_49 ;
V_41 |= ( unsigned long ) ( V_47 [ 7 ] * 3 + V_47 [ 6 ] * 2 )
<< V_50 ;
V_41 |= ( unsigned long ) V_47 [ 9 ] << V_51 ;
if ( V_48 & 0xe )
V_41 |= 1ull << V_52 ;
if ( V_48 & 0xf0 )
V_41 |= 1ull << V_53 ;
if ( V_48 & 0xf00 )
V_41 |= 1ull << V_54 ;
if ( V_48 & 0x7000 )
V_41 |= 1ull << V_55 ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
V_4 = V_46 [ V_5 ] ;
if ( ! V_4 )
continue;
if ( V_4 == 0xf ) {
V_41 |= 1ull << ( V_56 - V_5 ) ;
} else {
if ( ! V_47 [ V_4 ] )
V_43 = V_4 - 1 ;
else
V_43 = V_4 >> 2 ;
V_41 |= ( unsigned long ) V_43
<< ( V_57 - 2 * V_5 ) ;
}
}
for ( V_31 = 0 ; V_31 < V_35 ; ++ V_31 ) {
V_2 = ( V_1 [ V_31 ] >> V_8 ) & V_9 ;
V_4 = ( V_1 [ V_31 ] >> V_14 ) & V_15 ;
V_5 = ( V_1 [ V_31 ] >> V_12 ) & V_13 ;
V_3 = V_1 [ V_31 ] & V_10 ;
if ( ! V_2 ) {
if ( V_4 )
V_3 |= 0x10 | ( ( V_5 & 2 ) << 2 ) ;
for ( V_2 = 0 ; V_2 < 8 ; ++ V_2 ) {
if ( V_44 & ( 1 << V_2 ) )
continue;
V_24 = ( V_2 >> 1 ) & 1 ;
if ( V_4 ) {
if ( V_24 == ( V_5 & 1 ) )
break;
} else if ( V_45 [ V_24 ] < 4 ) {
++ V_45 [ V_24 ] ;
break;
}
}
V_44 |= 1 << V_2 ;
} else {
-- V_2 ;
if ( V_3 == 0 && ( V_5 & 2 ) )
V_41 |= 1ull << V_58 [ V_2 ] ;
else if ( V_3 == 6 && V_5 == 3 )
V_42 |= V_59 ;
V_3 |= 8 ;
}
if ( V_2 <= 1 )
V_40 |= V_3 << ( V_60 - 7 * V_2 ) ;
else
V_41 |= V_3 << ( V_61 - 5 * ( V_2 - 2 ) ) ;
if ( V_2 == 7 )
V_42 |= ( V_3 & 1 ) << V_62 ;
V_36 [ V_31 ] = V_2 ;
if ( F_1 ( V_1 [ V_31 ] ) )
V_42 |= V_59 ;
}
if ( V_44 & 1 )
V_40 |= V_63 ;
if ( V_44 & 0xfe )
V_40 |= V_64 ;
V_42 |= 0x2000 ;
V_37 [ 0 ] = V_40 ;
V_37 [ 1 ] = V_41 ;
V_37 [ 2 ] = V_42 ;
return 0 ;
}
static void F_6 ( unsigned int V_2 , unsigned long V_37 [] )
{
if ( V_2 <= 1 ) {
V_37 [ 0 ] &= ~ ( 0x1fUL << ( V_60 - 7 * V_2 ) ) ;
} else {
V_37 [ 1 ] &= ~ ( 0x1fUL << ( V_61 - 5 * ( V_2 - 2 ) ) ) ;
if ( V_2 == 7 )
V_37 [ 2 ] &= ~ ( 1UL << V_62 ) ;
}
}
static int T_2 F_7 ( void )
{
if ( ! V_65 -> V_66 ||
strcmp ( V_65 -> V_66 , L_1 ) )
return - V_67 ;
return F_8 ( & V_68 ) ;
}
