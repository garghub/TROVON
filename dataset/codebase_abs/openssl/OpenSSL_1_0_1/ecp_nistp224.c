const T_1 * F_1 ( void )
{
static const T_1 V_1 = {
V_2 ,
V_3 ,
V_4 ,
V_5 ,
V_6 ,
V_7 ,
V_8 ,
V_9 ,
V_10 ,
V_11 ,
V_12 ,
V_13 ,
V_14 ,
V_15 ,
V_16 ,
V_17 ,
V_18 ,
V_19 ,
V_20 ,
0 ,
0 ,
0 ,
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_28 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ,
V_33 ,
0 ,
0 ,
0 ,
0 } ;
return & V_1 ;
}
static void F_2 ( T_2 V_34 , const T_3 V_35 [ 28 ] )
{
V_34 [ 0 ] = * ( ( const V_36 * ) ( V_35 ) ) & 0x00ffffffffffffff ;
V_34 [ 1 ] = ( * ( ( const V_36 * ) ( V_35 + 7 ) ) ) & 0x00ffffffffffffff ;
V_34 [ 2 ] = ( * ( ( const V_36 * ) ( V_35 + 14 ) ) ) & 0x00ffffffffffffff ;
V_34 [ 3 ] = ( * ( ( const V_36 * ) ( V_35 + 21 ) ) ) & 0x00ffffffffffffff ;
}
static void F_3 ( T_3 V_34 [ 28 ] , const T_2 V_35 )
{
unsigned V_37 ;
for ( V_37 = 0 ; V_37 < 7 ; ++ V_37 )
{
V_34 [ V_37 ] = V_35 [ 0 ] >> ( 8 * V_37 ) ;
V_34 [ V_37 + 7 ] = V_35 [ 1 ] >> ( 8 * V_37 ) ;
V_34 [ V_37 + 14 ] = V_35 [ 2 ] >> ( 8 * V_37 ) ;
V_34 [ V_37 + 21 ] = V_35 [ 3 ] >> ( 8 * V_37 ) ;
}
}
static void F_4 ( T_3 * V_34 , const T_3 * V_35 , unsigned V_38 )
{
unsigned V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 )
V_34 [ V_37 ] = V_35 [ V_38 - 1 - V_37 ] ;
}
static int F_5 ( T_2 V_34 , const T_4 * V_39 )
{
T_5 V_40 ;
T_5 V_41 ;
unsigned V_42 ;
memset ( V_41 , 0 , sizeof V_41 ) ;
V_42 = F_6 ( V_39 ) ;
if ( V_42 > sizeof V_41 )
{
F_7 ( V_43 , V_44 ) ;
return 0 ;
}
if ( F_8 ( V_39 ) )
{
F_7 ( V_43 , V_44 ) ;
return 0 ;
}
V_42 = F_9 ( V_39 , V_40 ) ;
F_4 ( V_41 , V_40 , V_42 ) ;
F_2 ( V_34 , V_41 ) ;
return 1 ;
}
static T_4 * F_10 ( T_4 * V_34 , const T_2 V_35 )
{
T_5 V_40 , V_41 ;
F_3 ( V_40 , V_35 ) ;
F_4 ( V_41 , V_40 , sizeof V_41 ) ;
return F_11 ( V_41 , sizeof V_41 , V_34 ) ;
}
static void F_12 ( T_2 V_34 )
{
V_34 [ 0 ] = 1 ;
V_34 [ 1 ] = 0 ;
V_34 [ 2 ] = 0 ;
V_34 [ 3 ] = 0 ;
}
static void F_13 ( T_2 V_34 , const T_2 V_35 )
{
V_34 [ 0 ] = V_35 [ 0 ] ;
V_34 [ 1 ] = V_35 [ 1 ] ;
V_34 [ 2 ] = V_35 [ 2 ] ;
V_34 [ 3 ] = V_35 [ 3 ] ;
}
static void F_14 ( T_2 V_34 , const T_2 V_35 )
{
V_34 [ 0 ] += V_35 [ 0 ] ;
V_34 [ 1 ] += V_35 [ 1 ] ;
V_34 [ 2 ] += V_35 [ 2 ] ;
V_34 [ 3 ] += V_35 [ 3 ] ;
}
static void F_15 ( T_2 V_34 , const T_2 V_35 )
{
static const T_6 V_45 = ( ( ( T_6 ) 1 ) << 58 ) + ( ( ( T_6 ) 1 ) << 2 ) ;
static const T_6 V_46 = ( ( ( T_6 ) 1 ) << 58 ) - ( ( ( T_6 ) 1 ) << 2 ) ;
static const T_6 V_47 = ( ( ( T_6 ) 1 ) << 58 ) -
( ( ( T_6 ) 1 ) << 42 ) - ( ( ( T_6 ) 1 ) << 2 ) ;
V_34 [ 0 ] = V_45 - V_35 [ 0 ] ;
V_34 [ 1 ] = V_47 - V_35 [ 1 ] ;
V_34 [ 2 ] = V_46 - V_35 [ 2 ] ;
V_34 [ 3 ] = V_46 - V_35 [ 3 ] ;
}
static void F_16 ( T_2 V_34 , const T_2 V_35 )
{
static const T_6 V_45 = ( ( ( T_6 ) 1 ) << 58 ) + ( ( ( T_6 ) 1 ) << 2 ) ;
static const T_6 V_46 = ( ( ( T_6 ) 1 ) << 58 ) - ( ( ( T_6 ) 1 ) << 2 ) ;
static const T_6 V_47 = ( ( ( T_6 ) 1 ) << 58 ) -
( ( ( T_6 ) 1 ) << 42 ) - ( ( ( T_6 ) 1 ) << 2 ) ;
V_34 [ 0 ] += V_45 ;
V_34 [ 1 ] += V_47 ;
V_34 [ 2 ] += V_46 ;
V_34 [ 3 ] += V_46 ;
V_34 [ 0 ] -= V_35 [ 0 ] ;
V_34 [ 1 ] -= V_35 [ 1 ] ;
V_34 [ 2 ] -= V_35 [ 2 ] ;
V_34 [ 3 ] -= V_35 [ 3 ] ;
}
static void F_17 ( T_7 V_34 , const T_7 V_35 )
{
static const T_8 V_48 = ( ( T_8 ) 1 ) << 120 ;
static const T_8 V_49 = ( ( ( T_8 ) 1 ) << 120 ) -
( ( ( T_8 ) 1 ) << 64 ) ;
static const T_8 V_50 = ( ( ( T_8 ) 1 ) << 120 ) -
( ( ( T_8 ) 1 ) << 104 ) - ( ( ( T_8 ) 1 ) << 64 ) ;
V_34 [ 0 ] += V_48 ;
V_34 [ 1 ] += V_49 ;
V_34 [ 2 ] += V_49 ;
V_34 [ 3 ] += V_48 ;
V_34 [ 4 ] += V_50 ;
V_34 [ 5 ] += V_49 ;
V_34 [ 6 ] += V_49 ;
V_34 [ 0 ] -= V_35 [ 0 ] ;
V_34 [ 1 ] -= V_35 [ 1 ] ;
V_34 [ 2 ] -= V_35 [ 2 ] ;
V_34 [ 3 ] -= V_35 [ 3 ] ;
V_34 [ 4 ] -= V_35 [ 4 ] ;
V_34 [ 5 ] -= V_35 [ 5 ] ;
V_34 [ 6 ] -= V_35 [ 6 ] ;
}
static void F_18 ( T_7 V_34 , const T_2 V_35 )
{
static const T_8 V_51 = ( ( ( T_8 ) 1 ) << 64 ) +
( ( ( T_8 ) 1 ) << 8 ) ;
static const T_8 V_52 = ( ( ( T_8 ) 1 ) << 64 ) -
( ( ( T_8 ) 1 ) << 8 ) ;
static const T_8 V_53 = ( ( ( T_8 ) 1 ) << 64 ) -
( ( ( T_8 ) 1 ) << 48 ) - ( ( ( T_8 ) 1 ) << 8 ) ;
V_34 [ 0 ] += V_51 ;
V_34 [ 1 ] += V_53 ;
V_34 [ 2 ] += V_52 ;
V_34 [ 3 ] += V_52 ;
V_34 [ 0 ] -= V_35 [ 0 ] ;
V_34 [ 1 ] -= V_35 [ 1 ] ;
V_34 [ 2 ] -= V_35 [ 2 ] ;
V_34 [ 3 ] -= V_35 [ 3 ] ;
}
static void F_19 ( T_2 V_34 , const T_6 V_54 )
{
V_34 [ 0 ] *= V_54 ;
V_34 [ 1 ] *= V_54 ;
V_34 [ 2 ] *= V_54 ;
V_34 [ 3 ] *= V_54 ;
}
static void F_20 ( T_7 V_34 , const T_8 V_54 )
{
V_34 [ 0 ] *= V_54 ;
V_34 [ 1 ] *= V_54 ;
V_34 [ 2 ] *= V_54 ;
V_34 [ 3 ] *= V_54 ;
V_34 [ 4 ] *= V_54 ;
V_34 [ 5 ] *= V_54 ;
V_34 [ 6 ] *= V_54 ;
}
static void F_21 ( T_7 V_34 , const T_2 V_35 )
{
T_6 V_55 , V_56 , V_57 ;
V_55 = 2 * V_35 [ 0 ] ; V_56 = 2 * V_35 [ 1 ] ; V_57 = 2 * V_35 [ 2 ] ;
V_34 [ 0 ] = ( ( T_8 ) V_35 [ 0 ] ) * V_35 [ 0 ] ;
V_34 [ 1 ] = ( ( T_8 ) V_35 [ 0 ] ) * V_56 ;
V_34 [ 2 ] = ( ( T_8 ) V_35 [ 0 ] ) * V_57 + ( ( T_8 ) V_35 [ 1 ] ) * V_35 [ 1 ] ;
V_34 [ 3 ] = ( ( T_8 ) V_35 [ 3 ] ) * V_55 +
( ( T_8 ) V_35 [ 1 ] ) * V_57 ;
V_34 [ 4 ] = ( ( T_8 ) V_35 [ 3 ] ) * V_56 + ( ( T_8 ) V_35 [ 2 ] ) * V_35 [ 2 ] ;
V_34 [ 5 ] = ( ( T_8 ) V_35 [ 3 ] ) * V_57 ;
V_34 [ 6 ] = ( ( T_8 ) V_35 [ 3 ] ) * V_35 [ 3 ] ;
}
static void F_22 ( T_7 V_34 , const T_2 V_58 , const T_2 V_59 )
{
V_34 [ 0 ] = ( ( T_8 ) V_58 [ 0 ] ) * V_59 [ 0 ] ;
V_34 [ 1 ] = ( ( T_8 ) V_58 [ 0 ] ) * V_59 [ 1 ] + ( ( T_8 ) V_58 [ 1 ] ) * V_59 [ 0 ] ;
V_34 [ 2 ] = ( ( T_8 ) V_58 [ 0 ] ) * V_59 [ 2 ] + ( ( T_8 ) V_58 [ 1 ] ) * V_59 [ 1 ] +
( ( T_8 ) V_58 [ 2 ] ) * V_59 [ 0 ] ;
V_34 [ 3 ] = ( ( T_8 ) V_58 [ 0 ] ) * V_59 [ 3 ] + ( ( T_8 ) V_58 [ 1 ] ) * V_59 [ 2 ] +
( ( T_8 ) V_58 [ 2 ] ) * V_59 [ 1 ] + ( ( T_8 ) V_58 [ 3 ] ) * V_59 [ 0 ] ;
V_34 [ 4 ] = ( ( T_8 ) V_58 [ 1 ] ) * V_59 [ 3 ] + ( ( T_8 ) V_58 [ 2 ] ) * V_59 [ 2 ] +
( ( T_8 ) V_58 [ 3 ] ) * V_59 [ 1 ] ;
V_34 [ 5 ] = ( ( T_8 ) V_58 [ 2 ] ) * V_59 [ 3 ] + ( ( T_8 ) V_58 [ 3 ] ) * V_59 [ 2 ] ;
V_34 [ 6 ] = ( ( T_8 ) V_58 [ 3 ] ) * V_59 [ 3 ] ;
}
static void F_23 ( T_2 V_34 , const T_7 V_35 )
{
static const T_8 V_60 = ( ( ( T_8 ) 1 ) << 127 ) +
( ( ( T_8 ) 1 ) << 15 ) ;
static const T_8 V_61 = ( ( ( T_8 ) 1 ) << 127 ) -
( ( ( T_8 ) 1 ) << 71 ) ;
static const T_8 V_62 = ( ( ( T_8 ) 1 ) << 127 ) -
( ( ( T_8 ) 1 ) << 71 ) - ( ( ( T_8 ) 1 ) << 55 ) ;
T_8 V_63 [ 5 ] ;
V_63 [ 0 ] = V_35 [ 0 ] + V_60 ;
V_63 [ 1 ] = V_35 [ 1 ] + V_62 ;
V_63 [ 2 ] = V_35 [ 2 ] + V_61 ;
V_63 [ 3 ] = V_35 [ 3 ] ;
V_63 [ 4 ] = V_35 [ 4 ] ;
V_63 [ 4 ] += V_35 [ 6 ] >> 16 ;
V_63 [ 3 ] += ( V_35 [ 6 ] & 0xffff ) << 40 ;
V_63 [ 2 ] -= V_35 [ 6 ] ;
V_63 [ 3 ] += V_35 [ 5 ] >> 16 ;
V_63 [ 2 ] += ( V_35 [ 5 ] & 0xffff ) << 40 ;
V_63 [ 1 ] -= V_35 [ 5 ] ;
V_63 [ 2 ] += V_63 [ 4 ] >> 16 ;
V_63 [ 1 ] += ( V_63 [ 4 ] & 0xffff ) << 40 ;
V_63 [ 0 ] -= V_63 [ 4 ] ;
V_63 [ 3 ] += V_63 [ 2 ] >> 56 ;
V_63 [ 2 ] &= 0x00ffffffffffffff ;
V_63 [ 4 ] = V_63 [ 3 ] >> 56 ;
V_63 [ 3 ] &= 0x00ffffffffffffff ;
V_63 [ 2 ] += V_63 [ 4 ] >> 16 ;
V_63 [ 1 ] += ( V_63 [ 4 ] & 0xffff ) << 40 ;
V_63 [ 0 ] -= V_63 [ 4 ] ;
V_63 [ 1 ] += V_63 [ 0 ] >> 56 ;
V_34 [ 0 ] = V_63 [ 0 ] & 0x00ffffffffffffff ;
V_63 [ 2 ] += V_63 [ 1 ] >> 56 ;
V_34 [ 1 ] = V_63 [ 1 ] & 0x00ffffffffffffff ;
V_63 [ 3 ] += V_63 [ 2 ] >> 56 ;
V_34 [ 2 ] = V_63 [ 2 ] & 0x00ffffffffffffff ;
V_34 [ 3 ] = V_63 [ 3 ] ;
}
static void F_24 ( T_2 V_34 , const T_2 V_35 )
{
T_7 V_64 ;
F_21 ( V_64 , V_35 ) ;
F_23 ( V_34 , V_64 ) ;
}
static void F_25 ( T_2 V_34 , const T_2 V_58 , const T_2 V_59 )
{
T_7 V_64 ;
F_22 ( V_64 , V_58 , V_59 ) ;
F_23 ( V_34 , V_64 ) ;
}
static void F_26 ( T_2 V_34 , const T_2 V_35 )
{
static const T_9 V_65 = ( ( T_6 ) 1 ) << 56 ;
T_9 V_64 [ 4 ] , V_66 ;
V_64 [ 0 ] = V_35 [ 0 ] ;
V_64 [ 1 ] = V_35 [ 1 ] ;
V_64 [ 2 ] = V_35 [ 2 ] ;
V_64 [ 3 ] = V_35 [ 3 ] ;
V_66 = ( V_35 [ 3 ] >> 56 ) ;
V_64 [ 0 ] -= V_66 ;
V_64 [ 1 ] += V_66 << 40 ;
V_64 [ 3 ] &= 0x00ffffffffffffff ;
V_66 = ( ( V_35 [ 3 ] & V_35 [ 2 ] & ( V_35 [ 1 ] | 0x000000ffffffffff ) ) + 1 ) |
( ( ( T_9 ) ( V_35 [ 0 ] + ( V_35 [ 1 ] & 0x000000ffffffffff ) ) - 1 ) >> 63 ) ;
V_66 &= 0x00ffffffffffffff ;
V_66 = ( V_66 - 1 ) >> 63 ;
V_64 [ 3 ] &= V_66 ^ 0xffffffffffffffff ;
V_64 [ 2 ] &= V_66 ^ 0xffffffffffffffff ;
V_64 [ 1 ] &= ( V_66 ^ 0xffffffffffffffff ) | 0x000000ffffffffff ;
V_64 [ 0 ] -= 1 & V_66 ;
V_66 = V_64 [ 0 ] >> 63 ;
V_64 [ 0 ] += V_65 & V_66 ;
V_64 [ 1 ] -= 1 & V_66 ;
V_64 [ 2 ] += V_64 [ 1 ] >> 56 ;
V_64 [ 1 ] &= 0x00ffffffffffffff ;
V_64 [ 3 ] += V_64 [ 2 ] >> 56 ;
V_64 [ 2 ] &= 0x00ffffffffffffff ;
V_34 [ 0 ] = V_64 [ 0 ] ;
V_34 [ 1 ] = V_64 [ 1 ] ;
V_34 [ 2 ] = V_64 [ 2 ] ;
V_34 [ 3 ] = V_64 [ 3 ] ;
}
static T_6 F_27 ( const T_2 V_35 )
{
T_6 V_67 , V_68 , V_69 ;
V_67 = V_35 [ 0 ] | V_35 [ 1 ] | V_35 [ 2 ] | V_35 [ 3 ] ;
V_67 = ( ( ( T_9 ) ( V_67 ) - 1 ) >> 63 ) & 1 ;
V_68 = ( V_35 [ 0 ] ^ 1 ) | ( V_35 [ 1 ] ^ 0x00ffff0000000000 )
| ( V_35 [ 2 ] ^ 0x00ffffffffffffff ) | ( V_35 [ 3 ] ^ 0x00ffffffffffffff ) ;
V_68 = ( ( ( T_9 ) ( V_68 ) - 1 ) >> 63 ) & 1 ;
V_69 = ( V_35 [ 0 ] ^ 2 ) | ( V_35 [ 1 ] ^ 0x00fffe0000000000 )
| ( V_35 [ 2 ] ^ 0x00ffffffffffffff ) | ( V_35 [ 3 ] ^ 0x01ffffffffffffff ) ;
V_69 = ( ( ( T_9 ) ( V_69 ) - 1 ) >> 63 ) & 1 ;
return ( V_67 | V_68 | V_69 ) ;
}
static T_6 F_28 ( const T_2 V_35 )
{
return ( int ) ( F_27 ( V_35 ) & ( ( T_6 ) 1 ) ) ;
}
static void F_29 ( T_2 V_34 , const T_2 V_35 )
{
T_2 V_70 , V_71 , V_72 , V_73 ;
T_7 V_64 ;
unsigned V_37 ;
F_21 ( V_64 , V_35 ) ; F_23 ( V_70 , V_64 ) ;
F_22 ( V_64 , V_35 , V_70 ) ; F_23 ( V_70 , V_64 ) ;
F_21 ( V_64 , V_70 ) ; F_23 ( V_70 , V_64 ) ;
F_22 ( V_64 , V_35 , V_70 ) ; F_23 ( V_70 , V_64 ) ;
F_21 ( V_64 , V_70 ) ; F_23 ( V_71 , V_64 ) ;
F_21 ( V_64 , V_71 ) ; F_23 ( V_71 , V_64 ) ;
F_21 ( V_64 , V_71 ) ; F_23 ( V_71 , V_64 ) ;
F_22 ( V_64 , V_71 , V_70 ) ; F_23 ( V_70 , V_64 ) ;
F_21 ( V_64 , V_70 ) ; F_23 ( V_71 , V_64 ) ;
for ( V_37 = 0 ; V_37 < 5 ; ++ V_37 )
{
F_21 ( V_64 , V_71 ) ; F_23 ( V_71 , V_64 ) ;
}
F_22 ( V_64 , V_71 , V_70 ) ; F_23 ( V_71 , V_64 ) ;
F_21 ( V_64 , V_71 ) ; F_23 ( V_72 , V_64 ) ;
for ( V_37 = 0 ; V_37 < 11 ; ++ V_37 )
{
F_21 ( V_64 , V_72 ) ; F_23 ( V_72 , V_64 ) ;
}
F_22 ( V_64 , V_72 , V_71 ) ; F_23 ( V_71 , V_64 ) ;
F_21 ( V_64 , V_71 ) ; F_23 ( V_72 , V_64 ) ;
for ( V_37 = 0 ; V_37 < 23 ; ++ V_37 )
{
F_21 ( V_64 , V_72 ) ; F_23 ( V_72 , V_64 ) ;
}
F_22 ( V_64 , V_72 , V_71 ) ; F_23 ( V_72 , V_64 ) ;
F_21 ( V_64 , V_72 ) ; F_23 ( V_73 , V_64 ) ;
for ( V_37 = 0 ; V_37 < 47 ; ++ V_37 )
{
F_21 ( V_64 , V_73 ) ; F_23 ( V_73 , V_64 ) ;
}
F_22 ( V_64 , V_72 , V_73 ) ; F_23 ( V_72 , V_64 ) ;
F_21 ( V_64 , V_72 ) ; F_23 ( V_73 , V_64 ) ;
for ( V_37 = 0 ; V_37 < 23 ; ++ V_37 )
{
F_21 ( V_64 , V_73 ) ; F_23 ( V_73 , V_64 ) ;
}
F_22 ( V_64 , V_71 , V_73 ) ; F_23 ( V_71 , V_64 ) ;
for ( V_37 = 0 ; V_37 < 6 ; ++ V_37 )
{
F_21 ( V_64 , V_71 ) ; F_23 ( V_71 , V_64 ) ;
}
F_22 ( V_64 , V_71 , V_70 ) ; F_23 ( V_70 , V_64 ) ;
F_21 ( V_64 , V_70 ) ; F_23 ( V_70 , V_64 ) ;
F_22 ( V_64 , V_70 , V_35 ) ; F_23 ( V_70 , V_64 ) ;
for ( V_37 = 0 ; V_37 < 97 ; ++ V_37 )
{
F_21 ( V_64 , V_70 ) ; F_23 ( V_70 , V_64 ) ;
}
F_22 ( V_64 , V_70 , V_72 ) ; F_23 ( V_34 , V_64 ) ;
}
static void
F_30 ( T_2 V_34 , const T_2 V_35 , T_6 V_74 )
{
unsigned V_37 ;
const T_6 V_75 = - V_74 ;
for ( V_37 = 0 ; V_37 < 4 ; ++ V_37 )
{
const T_6 V_64 = V_75 & ( V_35 [ V_37 ] ^ V_34 [ V_37 ] ) ;
V_34 [ V_37 ] ^= V_64 ;
}
}
static void
F_31 ( T_2 V_76 , T_2 V_77 , T_2 V_78 ,
const T_2 V_79 , const T_2 V_80 , const T_2 V_81 )
{
T_7 V_64 , V_57 ;
T_2 V_82 , gamma , V_83 , V_84 , V_70 , V_71 ;
F_13 ( V_70 , V_79 ) ;
F_13 ( V_71 , V_79 ) ;
F_21 ( V_64 , V_81 ) ;
F_23 ( V_82 , V_64 ) ;
F_21 ( V_64 , V_80 ) ;
F_23 ( gamma , V_64 ) ;
F_22 ( V_64 , V_79 , gamma ) ;
F_23 ( V_83 , V_64 ) ;
F_16 ( V_70 , V_82 ) ;
F_14 ( V_71 , V_82 ) ;
F_19 ( V_71 , 3 ) ;
F_22 ( V_64 , V_70 , V_71 ) ;
F_23 ( V_84 , V_64 ) ;
F_21 ( V_64 , V_84 ) ;
F_13 ( V_70 , V_83 ) ;
F_19 ( V_70 , 8 ) ;
F_18 ( V_64 , V_70 ) ;
F_23 ( V_76 , V_64 ) ;
F_14 ( V_82 , gamma ) ;
F_13 ( V_70 , V_80 ) ;
F_14 ( V_70 , V_81 ) ;
F_21 ( V_64 , V_70 ) ;
F_18 ( V_64 , V_82 ) ;
F_23 ( V_78 , V_64 ) ;
F_19 ( V_83 , 4 ) ;
F_16 ( V_83 , V_76 ) ;
F_22 ( V_64 , V_84 , V_83 ) ;
F_21 ( V_57 , gamma ) ;
F_20 ( V_57 , 8 ) ;
F_17 ( V_64 , V_57 ) ;
F_23 ( V_77 , V_64 ) ;
}
static void F_32 ( T_2 V_85 , T_2 V_86 , T_2 V_87 ,
const T_2 V_88 , const T_2 y1 , const T_2 V_89 ,
const int V_90 , const T_2 V_91 , const T_2 V_92 , const T_2 V_93 )
{
T_2 V_70 , V_71 , V_72 , V_73 , V_94 , V_76 , V_77 , V_78 ;
T_7 V_64 , V_57 ;
T_6 V_95 , V_96 , V_97 , V_98 ;
if ( ! V_90 )
{
F_21 ( V_64 , V_93 ) ;
F_23 ( V_71 , V_64 ) ;
F_22 ( V_64 , V_71 , V_93 ) ;
F_23 ( V_73 , V_64 ) ;
F_22 ( V_57 , V_73 , y1 ) ;
F_23 ( V_73 , V_57 ) ;
F_22 ( V_57 , V_71 , V_88 ) ;
F_23 ( V_71 , V_57 ) ;
}
else
{
F_13 ( V_73 , y1 ) ;
F_13 ( V_71 , V_88 ) ;
}
F_21 ( V_64 , V_89 ) ;
F_23 ( V_70 , V_64 ) ;
F_22 ( V_64 , V_70 , V_89 ) ;
F_23 ( V_72 , V_64 ) ;
F_22 ( V_64 , V_72 , V_92 ) ;
F_18 ( V_64 , V_73 ) ;
F_23 ( V_72 , V_64 ) ;
F_22 ( V_64 , V_70 , V_91 ) ;
F_18 ( V_64 , V_71 ) ;
F_23 ( V_70 , V_64 ) ;
V_97 = F_27 ( V_70 ) ;
V_98 = F_27 ( V_72 ) ;
V_95 = F_27 ( V_89 ) ;
V_96 = F_27 ( V_93 ) ;
if ( V_97 && V_98 && ! V_95 && ! V_96 )
{
F_31 ( V_85 , V_86 , V_87 , V_88 , y1 , V_89 ) ;
return;
}
if ( ! V_90 )
{
F_22 ( V_64 , V_89 , V_93 ) ;
F_23 ( V_94 , V_64 ) ;
}
else
{
F_13 ( V_94 , V_89 ) ;
}
F_22 ( V_64 , V_70 , V_94 ) ;
F_23 ( V_78 , V_64 ) ;
F_13 ( V_94 , V_70 ) ;
F_21 ( V_64 , V_70 ) ;
F_23 ( V_70 , V_64 ) ;
F_22 ( V_64 , V_70 , V_94 ) ;
F_23 ( V_94 , V_64 ) ;
F_22 ( V_64 , V_71 , V_70 ) ;
F_23 ( V_71 , V_64 ) ;
F_22 ( V_64 , V_73 , V_94 ) ;
F_21 ( V_57 , V_72 ) ;
F_18 ( V_57 , V_94 ) ;
F_13 ( V_94 , V_71 ) ;
F_19 ( V_94 , 2 ) ;
F_18 ( V_57 , V_94 ) ;
F_23 ( V_76 , V_57 ) ;
F_16 ( V_71 , V_76 ) ;
F_22 ( V_57 , V_72 , V_71 ) ;
F_17 ( V_57 , V_64 ) ;
F_23 ( V_77 , V_57 ) ;
F_30 ( V_76 , V_91 , V_95 ) ;
F_30 ( V_76 , V_88 , V_96 ) ;
F_30 ( V_77 , V_92 , V_95 ) ;
F_30 ( V_77 , y1 , V_96 ) ;
F_30 ( V_78 , V_93 , V_95 ) ;
F_30 ( V_78 , V_89 , V_96 ) ;
F_13 ( V_85 , V_76 ) ;
F_13 ( V_86 , V_77 ) ;
F_13 ( V_87 , V_78 ) ;
}
static void F_33 ( const T_10 V_99 , unsigned int V_100 , const T_2 V_101 [] [ 3 ] , T_2 V_34 [ 3 ] )
{
unsigned V_37 , V_102 ;
T_6 * V_103 = & V_34 [ 0 ] [ 0 ] ;
memset ( V_103 , 0 , 3 * sizeof( T_2 ) ) ;
for ( V_37 = 0 ; V_37 < V_100 ; V_37 ++ )
{
const T_6 * V_104 = & V_101 [ V_37 ] [ 0 ] [ 0 ] ;
T_10 V_105 = V_37 ^ V_99 ;
V_105 |= V_105 >> 4 ;
V_105 |= V_105 >> 2 ;
V_105 |= V_105 >> 1 ;
V_105 &= 1 ;
V_105 -- ;
for ( V_102 = 0 ; V_102 < 4 * 3 ; V_102 ++ )
V_103 [ V_102 ] |= V_104 [ V_102 ] & V_105 ;
}
}
static char F_34 ( const T_5 V_35 , unsigned V_37 )
{
if ( V_37 >= 224 )
return 0 ;
return ( V_35 [ V_37 >> 3 ] >> ( V_37 & 7 ) ) & 1 ;
}
static void F_35 ( T_2 V_76 , T_2 V_77 , T_2 V_78 ,
const T_5 V_106 [] , const unsigned V_107 , const T_3 * V_108 ,
const int V_90 , const T_2 V_101 [] [ 17 ] [ 3 ] , const T_2 V_109 [ 2 ] [ 16 ] [ 3 ] )
{
int V_37 , V_110 ;
unsigned V_111 ;
unsigned V_112 = ( V_108 != NULL ) ;
T_2 V_113 [ 3 ] , V_64 [ 4 ] ;
T_10 V_114 ;
T_3 V_115 , V_116 ;
memset ( V_113 , 0 , 3 * sizeof( T_2 ) ) ;
V_110 = 1 ;
for ( V_37 = ( V_107 ? 220 : 27 ) ; V_37 >= 0 ; -- V_37 )
{
if ( ! V_110 )
F_31 ( V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] , V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ) ;
if ( V_112 && ( V_37 <= 27 ) )
{
V_114 = F_34 ( V_108 , V_37 + 196 ) << 3 ;
V_114 |= F_34 ( V_108 , V_37 + 140 ) << 2 ;
V_114 |= F_34 ( V_108 , V_37 + 84 ) << 1 ;
V_114 |= F_34 ( V_108 , V_37 + 28 ) ;
F_33 ( V_114 , 16 , V_109 [ 1 ] , V_64 ) ;
if ( ! V_110 )
{
F_32 ( V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ,
V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ,
1 , V_64 [ 0 ] , V_64 [ 1 ] , V_64 [ 2 ] ) ;
}
else
{
memcpy ( V_113 , V_64 , 3 * sizeof( T_2 ) ) ;
V_110 = 0 ;
}
V_114 = F_34 ( V_108 , V_37 + 168 ) << 3 ;
V_114 |= F_34 ( V_108 , V_37 + 112 ) << 2 ;
V_114 |= F_34 ( V_108 , V_37 + 56 ) << 1 ;
V_114 |= F_34 ( V_108 , V_37 ) ;
F_33 ( V_114 , 16 , V_109 [ 0 ] , V_64 ) ;
F_32 ( V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ,
V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ,
1 , V_64 [ 0 ] , V_64 [ 1 ] , V_64 [ 2 ] ) ;
}
if ( V_107 && ( V_37 % 5 == 0 ) )
{
for ( V_111 = 0 ; V_111 < V_107 ; ++ V_111 )
{
V_114 = F_34 ( V_106 [ V_111 ] , V_37 + 4 ) << 5 ;
V_114 |= F_34 ( V_106 [ V_111 ] , V_37 + 3 ) << 4 ;
V_114 |= F_34 ( V_106 [ V_111 ] , V_37 + 2 ) << 3 ;
V_114 |= F_34 ( V_106 [ V_111 ] , V_37 + 1 ) << 2 ;
V_114 |= F_34 ( V_106 [ V_111 ] , V_37 ) << 1 ;
V_114 |= F_34 ( V_106 [ V_111 ] , V_37 - 1 ) ;
F_36 ( & V_115 , & V_116 , V_114 ) ;
F_33 ( V_116 , 17 , V_101 [ V_111 ] , V_64 ) ;
F_15 ( V_64 [ 3 ] , V_64 [ 1 ] ) ;
F_30 ( V_64 [ 1 ] , V_64 [ 3 ] , V_115 ) ;
if ( ! V_110 )
{
F_32 ( V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ,
V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ,
V_90 , V_64 [ 0 ] , V_64 [ 1 ] , V_64 [ 2 ] ) ;
}
else
{
memcpy ( V_113 , V_64 , 3 * sizeof( T_2 ) ) ;
V_110 = 0 ;
}
}
}
}
F_13 ( V_76 , V_113 [ 0 ] ) ;
F_13 ( V_77 , V_113 [ 1 ] ) ;
F_13 ( V_78 , V_113 [ 2 ] ) ;
}
static T_11 * F_37 ()
{
T_11 * V_1 = NULL ;
V_1 = ( T_11 * ) F_38 ( sizeof *V_1 ) ;
if ( ! V_1 )
{
F_7 ( V_117 , V_118 ) ;
return V_1 ;
}
memset ( V_1 -> V_109 , 0 , sizeof( V_1 -> V_109 ) ) ;
V_1 -> V_119 = 1 ;
return V_1 ;
}
static void * F_39 ( void * V_120 )
{
T_11 * V_121 = V_120 ;
F_40 ( & V_121 -> V_119 , 1 , V_122 ) ;
return V_120 ;
}
static void F_41 ( void * V_123 )
{
int V_37 ;
T_11 * V_124 = V_123 ;
if ( ! V_124 )
return;
V_37 = F_40 ( & V_124 -> V_119 , - 1 , V_122 ) ;
if ( V_37 > 0 )
return;
F_42 ( V_124 ) ;
}
static void F_43 ( void * V_123 )
{
int V_37 ;
T_11 * V_124 = V_123 ;
if ( ! V_124 )
return;
V_37 = F_40 ( & V_124 -> V_119 , - 1 , V_122 ) ;
if ( V_37 > 0 )
return;
F_44 ( V_124 , sizeof *V_124 ) ;
F_42 ( V_124 ) ;
}
int V_4 ( T_12 * V_125 )
{
int V_1 ;
V_1 = F_45 ( V_125 ) ;
V_125 -> V_126 = 1 ;
return V_1 ;
}
int V_8 ( T_12 * V_125 , const T_4 * V_127 ,
const T_4 * V_66 , const T_4 * V_128 , T_13 * V_129 )
{
int V_1 = 0 ;
T_13 * V_130 = NULL ;
T_4 * V_131 , * V_132 , * V_133 ;
if ( V_129 == NULL )
if ( ( V_129 = V_130 = F_46 () ) == NULL ) return 0 ;
F_47 ( V_129 ) ;
if ( ( ( V_131 = F_48 ( V_129 ) ) == NULL ) ||
( ( V_132 = F_48 ( V_129 ) ) == NULL ) ||
( ( V_133 = F_48 ( V_129 ) ) == NULL ) ) goto V_134;
F_11 ( V_135 [ 0 ] , sizeof( T_5 ) , V_131 ) ;
F_11 ( V_135 [ 1 ] , sizeof( T_5 ) , V_132 ) ;
F_11 ( V_135 [ 2 ] , sizeof( T_5 ) , V_133 ) ;
if ( ( F_49 ( V_131 , V_127 ) ) || ( F_49 ( V_132 , V_66 ) ) ||
( F_49 ( V_133 , V_128 ) ) )
{
F_7 ( V_136 ,
V_137 ) ;
goto V_134;
}
V_125 -> V_138 = V_139 ;
V_1 = F_50 ( V_125 , V_127 , V_66 , V_128 , V_129 ) ;
V_134:
F_51 ( V_129 ) ;
if ( V_130 != NULL )
F_52 ( V_130 ) ;
return V_1 ;
}
int V_20 ( const T_12 * V_125 ,
const T_14 * V_140 , T_4 * V_141 , T_4 * V_142 , T_13 * V_129 )
{
T_2 V_89 , V_93 , V_79 , V_80 , V_76 , V_77 ;
T_7 V_64 ;
if ( F_53 ( V_125 , V_140 ) )
{
F_7 ( V_143 ,
V_144 ) ;
return 0 ;
}
if ( ( ! F_5 ( V_79 , & V_140 -> V_145 ) ) || ( ! F_5 ( V_80 , & V_140 -> V_146 ) ) ||
( ! F_5 ( V_89 , & V_140 -> V_147 ) ) ) return 0 ;
F_29 ( V_93 , V_89 ) ;
F_21 ( V_64 , V_93 ) ; F_23 ( V_89 , V_64 ) ;
F_22 ( V_64 , V_79 , V_89 ) ; F_23 ( V_79 , V_64 ) ;
F_26 ( V_76 , V_79 ) ;
if ( V_141 != NULL )
{
if ( ! F_10 ( V_141 , V_76 ) ) {
F_7 ( V_143 ,
V_148 ) ;
return 0 ;
}
}
F_22 ( V_64 , V_89 , V_93 ) ; F_23 ( V_89 , V_64 ) ;
F_22 ( V_64 , V_80 , V_89 ) ; F_23 ( V_80 , V_64 ) ;
F_26 ( V_77 , V_80 ) ;
if ( V_142 != NULL )
{
if ( ! F_10 ( V_142 , V_77 ) ) {
F_7 ( V_143 ,
V_148 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_54 ( T_15 V_111 , T_2 V_149 [] [ 3 ] , T_2 V_150 [] )
{
F_55 (
V_111 ,
V_149 ,
sizeof( T_2 ) ,
V_150 ,
( void ( * ) ( void * ) ) F_12 ,
( int ( * ) ( const void * ) ) F_28 ,
( void ( * ) ( void * , const void * ) ) F_13 ,
( void ( * ) ( void * , const void * ) ) F_24 ,
( void ( * ) ( void * , const void * , const void * ) ) F_25 ,
( void ( * ) ( void * , const void * ) ) F_29 ,
( void ( * ) ( void * , const void * ) ) F_26 ) ;
}
int V_29 ( const T_12 * V_125 , T_14 * V_151 ,
const T_4 * V_54 , T_15 V_111 , const T_14 * V_149 [] ,
const T_4 * V_106 [] , T_13 * V_129 )
{
int V_1 = 0 ;
int V_102 ;
unsigned V_37 ;
int V_90 = 0 ;
T_13 * V_130 = NULL ;
T_4 * V_141 , * V_142 , * V_152 , * V_153 ;
T_5 V_154 ;
T_5 * V_155 = NULL ;
T_2 ( * V_101 ) [ 17 ] [ 3 ] = NULL ;
T_2 * V_150 = NULL ;
T_5 V_64 ;
unsigned V_42 ;
int V_156 = 0 ;
T_15 V_107 = V_111 ;
T_2 V_79 , V_80 , V_81 , V_76 , V_77 , V_78 ;
T_11 * V_124 = NULL ;
const T_2 ( * V_109 ) [ 16 ] [ 3 ] = NULL ;
T_14 * V_157 = NULL ;
const T_14 * V_127 = NULL ;
const T_4 * V_158 = NULL ;
if ( V_129 == NULL )
if ( ( V_129 = V_130 = F_46 () ) == NULL ) return 0 ;
F_47 ( V_129 ) ;
if ( ( ( V_141 = F_48 ( V_129 ) ) == NULL ) ||
( ( V_142 = F_48 ( V_129 ) ) == NULL ) ||
( ( V_152 = F_48 ( V_129 ) ) == NULL ) ||
( ( V_153 = F_48 ( V_129 ) ) == NULL ) )
goto V_134;
if ( V_54 != NULL )
{
V_124 = F_56 ( V_125 -> V_159 ,
F_39 , F_41 ,
F_43 ) ;
if ( V_124 )
V_109 = ( const T_2 ( * ) [ 16 ] [ 3 ] ) V_124 -> V_109 ;
else
V_109 = & V_160 [ 0 ] ;
V_157 = F_57 ( V_125 ) ;
if ( V_157 == NULL )
goto V_134;
if ( ! F_10 ( V_141 , V_109 [ 0 ] [ 1 ] [ 0 ] ) ||
! F_10 ( V_142 , V_109 [ 0 ] [ 1 ] [ 1 ] ) ||
! F_10 ( V_152 , V_109 [ 0 ] [ 1 ] [ 2 ] ) )
{
F_7 ( V_161 , V_148 ) ;
goto V_134;
}
if ( ! F_58 ( V_125 ,
V_157 , V_141 , V_142 , V_152 , V_129 ) )
goto V_134;
if ( 0 == F_59 ( V_125 , V_157 , V_125 -> V_157 , V_129 ) )
V_156 = 1 ;
else
V_107 = V_107 + 1 ;
}
if ( V_107 > 0 )
{
if ( V_107 >= 3 )
{
V_90 = 1 ;
}
V_155 = F_38 ( V_107 * sizeof( T_5 ) ) ;
V_101 = F_38 ( V_107 * 17 * 3 * sizeof( T_2 ) ) ;
if ( V_90 )
V_150 = F_38 ( ( V_107 * 17 + 1 ) * sizeof( T_2 ) ) ;
if ( ( V_155 == NULL ) || ( V_101 == NULL ) || ( V_90 && ( V_150 == NULL ) ) )
{
F_7 ( V_161 , V_118 ) ;
goto V_134;
}
memset ( V_155 , 0 , V_107 * sizeof( T_5 ) ) ;
memset ( V_101 , 0 , V_107 * 17 * 3 * sizeof( T_2 ) ) ;
for ( V_37 = 0 ; V_37 < V_107 ; ++ V_37 )
{
if ( V_37 == V_111 )
{
V_127 = F_60 ( V_125 ) ;
V_158 = V_54 ;
}
else
{
V_127 = V_149 [ V_37 ] ;
V_158 = V_106 [ V_37 ] ;
}
if ( ( V_158 != NULL ) && ( V_127 != NULL ) )
{
if ( ( F_61 ( V_158 ) > 224 ) || ( F_8 ( V_158 ) ) )
{
if ( ! F_62 ( V_153 , V_158 , & V_125 -> V_162 , V_129 ) )
{
F_7 ( V_161 , V_148 ) ;
goto V_134;
}
V_42 = F_9 ( V_153 , V_64 ) ;
}
else
V_42 = F_9 ( V_158 , V_64 ) ;
F_4 ( V_155 [ V_37 ] , V_64 , V_42 ) ;
if ( ( ! F_5 ( V_76 , & V_127 -> V_145 ) ) ||
( ! F_5 ( V_77 , & V_127 -> V_146 ) ) ||
( ! F_5 ( V_78 , & V_127 -> V_147 ) ) ) goto V_134;
F_13 ( V_101 [ V_37 ] [ 1 ] [ 0 ] , V_76 ) ;
F_13 ( V_101 [ V_37 ] [ 1 ] [ 1 ] , V_77 ) ;
F_13 ( V_101 [ V_37 ] [ 1 ] [ 2 ] , V_78 ) ;
for ( V_102 = 2 ; V_102 <= 16 ; ++ V_102 )
{
if ( V_102 & 1 )
{
F_32 (
V_101 [ V_37 ] [ V_102 ] [ 0 ] , V_101 [ V_37 ] [ V_102 ] [ 1 ] , V_101 [ V_37 ] [ V_102 ] [ 2 ] ,
V_101 [ V_37 ] [ 1 ] [ 0 ] , V_101 [ V_37 ] [ 1 ] [ 1 ] , V_101 [ V_37 ] [ 1 ] [ 2 ] ,
0 , V_101 [ V_37 ] [ V_102 - 1 ] [ 0 ] , V_101 [ V_37 ] [ V_102 - 1 ] [ 1 ] , V_101 [ V_37 ] [ V_102 - 1 ] [ 2 ] ) ;
}
else
{
F_31 (
V_101 [ V_37 ] [ V_102 ] [ 0 ] , V_101 [ V_37 ] [ V_102 ] [ 1 ] , V_101 [ V_37 ] [ V_102 ] [ 2 ] ,
V_101 [ V_37 ] [ V_102 / 2 ] [ 0 ] , V_101 [ V_37 ] [ V_102 / 2 ] [ 1 ] , V_101 [ V_37 ] [ V_102 / 2 ] [ 2 ] ) ;
}
}
}
}
if ( V_90 )
F_54 ( V_107 * 17 , V_101 [ 0 ] , V_150 ) ;
}
if ( ( V_54 != NULL ) && ( V_156 ) )
{
memset ( V_154 , 0 , sizeof V_154 ) ;
if ( ( F_61 ( V_54 ) > 224 ) || ( F_8 ( V_54 ) ) )
{
if ( ! F_62 ( V_153 , V_54 , & V_125 -> V_162 , V_129 ) )
{
F_7 ( V_161 , V_148 ) ;
goto V_134;
}
V_42 = F_9 ( V_153 , V_64 ) ;
}
else
V_42 = F_9 ( V_54 , V_64 ) ;
F_4 ( V_154 , V_64 , V_42 ) ;
F_35 ( V_76 , V_77 , V_78 ,
( const T_5 ( * ) ) V_155 , V_107 ,
V_154 ,
V_90 , ( const T_2 ( * ) [ 17 ] [ 3 ] ) V_101 ,
V_109 ) ;
}
else
F_35 ( V_76 , V_77 , V_78 ,
( const T_5 ( * ) ) V_155 , V_107 ,
NULL , V_90 , ( const T_2 ( * ) [ 17 ] [ 3 ] ) V_101 , NULL ) ;
F_26 ( V_79 , V_76 ) ;
F_26 ( V_80 , V_77 ) ;
F_26 ( V_81 , V_78 ) ;
if ( ( ! F_10 ( V_141 , V_79 ) ) || ( ! F_10 ( V_142 , V_80 ) ) ||
( ! F_10 ( V_152 , V_81 ) ) )
{
F_7 ( V_161 , V_148 ) ;
goto V_134;
}
V_1 = F_58 ( V_125 , V_151 , V_141 , V_142 , V_152 , V_129 ) ;
V_134:
F_51 ( V_129 ) ;
if ( V_157 != NULL )
F_63 ( V_157 ) ;
if ( V_130 != NULL )
F_52 ( V_130 ) ;
if ( V_155 != NULL )
F_42 ( V_155 ) ;
if ( V_101 != NULL )
F_42 ( V_101 ) ;
if ( V_150 != NULL )
F_42 ( V_150 ) ;
return V_1 ;
}
int V_30 ( T_12 * V_125 , T_13 * V_129 )
{
int V_1 = 0 ;
T_11 * V_124 = NULL ;
int V_37 , V_102 ;
T_13 * V_130 = NULL ;
T_4 * V_141 , * V_142 ;
T_14 * V_157 = NULL ;
T_2 V_150 [ 32 ] ;
F_64 ( & V_125 -> V_159 , F_39 ,
F_41 , F_43 ) ;
if ( V_129 == NULL )
if ( ( V_129 = V_130 = F_46 () ) == NULL ) return 0 ;
F_47 ( V_129 ) ;
if ( ( ( V_141 = F_48 ( V_129 ) ) == NULL ) ||
( ( V_142 = F_48 ( V_129 ) ) == NULL ) )
goto V_134;
if ( V_125 -> V_157 == NULL ) goto V_134;
V_157 = F_57 ( V_125 ) ;
if ( V_157 == NULL )
goto V_134;
F_11 ( V_135 [ 3 ] , sizeof ( T_5 ) , V_141 ) ;
F_11 ( V_135 [ 4 ] , sizeof ( T_5 ) , V_142 ) ;
if ( ! F_65 ( V_125 , V_157 , V_141 , V_142 , V_129 ) )
goto V_134;
if ( ( V_124 = F_37 () ) == NULL )
goto V_134;
if ( 0 == F_59 ( V_125 , V_157 , V_125 -> V_157 , V_129 ) )
{
memcpy ( V_124 -> V_109 , V_160 , sizeof( V_124 -> V_109 ) ) ;
V_1 = 1 ;
goto V_134;
}
if ( ( ! F_5 ( V_124 -> V_109 [ 0 ] [ 1 ] [ 0 ] , & V_125 -> V_157 -> V_145 ) ) ||
( ! F_5 ( V_124 -> V_109 [ 0 ] [ 1 ] [ 1 ] , & V_125 -> V_157 -> V_146 ) ) ||
( ! F_5 ( V_124 -> V_109 [ 0 ] [ 1 ] [ 2 ] , & V_125 -> V_157 -> V_147 ) ) )
goto V_134;
for ( V_37 = 1 ; V_37 <= 8 ; V_37 <<= 1 )
{
F_31 (
V_124 -> V_109 [ 1 ] [ V_37 ] [ 0 ] , V_124 -> V_109 [ 1 ] [ V_37 ] [ 1 ] , V_124 -> V_109 [ 1 ] [ V_37 ] [ 2 ] ,
V_124 -> V_109 [ 0 ] [ V_37 ] [ 0 ] , V_124 -> V_109 [ 0 ] [ V_37 ] [ 1 ] , V_124 -> V_109 [ 0 ] [ V_37 ] [ 2 ] ) ;
for ( V_102 = 0 ; V_102 < 27 ; ++ V_102 )
{
F_31 (
V_124 -> V_109 [ 1 ] [ V_37 ] [ 0 ] , V_124 -> V_109 [ 1 ] [ V_37 ] [ 1 ] , V_124 -> V_109 [ 1 ] [ V_37 ] [ 2 ] ,
V_124 -> V_109 [ 1 ] [ V_37 ] [ 0 ] , V_124 -> V_109 [ 1 ] [ V_37 ] [ 1 ] , V_124 -> V_109 [ 1 ] [ V_37 ] [ 2 ] ) ;
}
if ( V_37 == 8 )
break;
F_31 (
V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 0 ] , V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 1 ] , V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 2 ] ,
V_124 -> V_109 [ 1 ] [ V_37 ] [ 0 ] , V_124 -> V_109 [ 1 ] [ V_37 ] [ 1 ] , V_124 -> V_109 [ 1 ] [ V_37 ] [ 2 ] ) ;
for ( V_102 = 0 ; V_102 < 27 ; ++ V_102 )
{
F_31 (
V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 0 ] , V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 1 ] , V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 2 ] ,
V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 0 ] , V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 1 ] , V_124 -> V_109 [ 0 ] [ 2 * V_37 ] [ 2 ] ) ;
}
}
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ )
{
memset ( V_124 -> V_109 [ V_37 ] [ 0 ] , 0 , sizeof( V_124 -> V_109 [ V_37 ] [ 0 ] ) ) ;
F_32 (
V_124 -> V_109 [ V_37 ] [ 6 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 6 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 6 ] [ 2 ] , V_124 -> V_109 [ V_37 ] [ 4 ] [ 0 ] ,
V_124 -> V_109 [ V_37 ] [ 4 ] [ 1 ] , V_124 -> V_109 [ V_37 ] [ 4 ] [ 2 ] ,
0 , V_124 -> V_109 [ V_37 ] [ 2 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 2 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 2 ] [ 2 ] ) ;
F_32 (
V_124 -> V_109 [ V_37 ] [ 10 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 10 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 10 ] [ 2 ] , V_124 -> V_109 [ V_37 ] [ 8 ] [ 0 ] ,
V_124 -> V_109 [ V_37 ] [ 8 ] [ 1 ] , V_124 -> V_109 [ V_37 ] [ 8 ] [ 2 ] ,
0 , V_124 -> V_109 [ V_37 ] [ 2 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 2 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 2 ] [ 2 ] ) ;
F_32 (
V_124 -> V_109 [ V_37 ] [ 12 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 12 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 12 ] [ 2 ] , V_124 -> V_109 [ V_37 ] [ 8 ] [ 0 ] ,
V_124 -> V_109 [ V_37 ] [ 8 ] [ 1 ] , V_124 -> V_109 [ V_37 ] [ 8 ] [ 2 ] ,
0 , V_124 -> V_109 [ V_37 ] [ 4 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 4 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 4 ] [ 2 ] ) ;
F_32 (
V_124 -> V_109 [ V_37 ] [ 14 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 14 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 14 ] [ 2 ] , V_124 -> V_109 [ V_37 ] [ 12 ] [ 0 ] ,
V_124 -> V_109 [ V_37 ] [ 12 ] [ 1 ] , V_124 -> V_109 [ V_37 ] [ 12 ] [ 2 ] ,
0 , V_124 -> V_109 [ V_37 ] [ 2 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 2 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 2 ] [ 2 ] ) ;
for ( V_102 = 1 ; V_102 < 8 ; ++ V_102 )
{
F_32 (
V_124 -> V_109 [ V_37 ] [ 2 * V_102 + 1 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 2 * V_102 + 1 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 2 * V_102 + 1 ] [ 2 ] , V_124 -> V_109 [ V_37 ] [ 2 * V_102 ] [ 0 ] ,
V_124 -> V_109 [ V_37 ] [ 2 * V_102 ] [ 1 ] , V_124 -> V_109 [ V_37 ] [ 2 * V_102 ] [ 2 ] ,
0 , V_124 -> V_109 [ V_37 ] [ 1 ] [ 0 ] , V_124 -> V_109 [ V_37 ] [ 1 ] [ 1 ] ,
V_124 -> V_109 [ V_37 ] [ 1 ] [ 2 ] ) ;
}
}
F_54 ( 31 , & ( V_124 -> V_109 [ 0 ] [ 1 ] ) , V_150 ) ;
if ( ! F_66 ( & V_125 -> V_159 , V_124 , F_39 ,
F_41 , F_43 ) )
goto V_134;
V_1 = 1 ;
V_124 = NULL ;
V_134:
F_51 ( V_129 ) ;
if ( V_157 != NULL )
F_63 ( V_157 ) ;
if ( V_130 != NULL )
F_52 ( V_130 ) ;
if ( V_124 )
F_41 ( V_124 ) ;
return V_1 ;
}
int V_31 ( const T_12 * V_125 )
{
if ( F_56 ( V_125 -> V_159 , F_39 ,
F_41 , F_43 )
!= NULL )
return 1 ;
else
return 0 ;
}
