static int F_1 ( T_1 * V_1 ,
const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
int V_6 ;
if ( V_4 )
V_6 = F_3 ( V_2 , V_1 -> V_7 * 8 , & V_5 -> V_8 ) ;
else
V_6 = F_4 ( V_2 , V_1 -> V_7 * 8 , & V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = V_5 -> V_9 ;
V_5 -> V_11 = V_5 -> V_9 ;
V_5 -> V_12 = V_13 ;
return V_6 < 0 ? 0 : 1 ;
}
static void F_6 ( T_3 * V_14 , const void * F_2 , T_4 V_15 )
{
const unsigned char * V_16 = F_2 ;
T_4 V_17 ;
if ( ( V_17 = V_14 -> V_18 ) ) {
V_17 = V_19 - V_17 ;
if ( V_15 < V_17 )
V_17 = V_15 ;
F_7 ( V_14 , V_16 , V_17 ) ;
V_16 += V_17 ;
V_15 -= V_17 ;
}
V_17 = V_15 % V_19 ;
V_15 -= V_17 ;
if ( V_15 ) {
F_8 ( V_14 , V_16 , V_15 / V_19 ) ;
V_16 += V_15 ;
V_14 -> V_20 += V_15 >> 29 ;
V_14 -> V_21 += V_15 <<= 3 ;
if ( V_14 -> V_21 < ( unsigned int ) V_15 )
V_14 -> V_20 ++ ;
}
if ( V_17 )
F_7 ( V_14 , V_16 , V_17 ) ;
}
static T_4 F_9 ( T_2 * V_5 ,
unsigned char * V_22 ,
const unsigned char * V_23 ,
T_4 V_24 , int V_25 )
{
T_5 V_26 [ 8 ] , V_27 [ 8 ] ;
T_6 V_28 [ 8 ] ;
unsigned char V_29 [ sizeof( V_30 ) + 32 ] ;
union {
T_7 V_31 [ 16 ] ;
T_8 V_32 [ 32 ] ;
T_9 V_14 [ 128 ] ;
} V_33 [ 8 ] ;
V_30 * V_1 ;
unsigned int V_34 , V_35 , V_36 , V_37 , V_38 = 4 * V_25 , V_39 , V_40 =
0 ;
T_4 V_6 = 0 ;
T_9 * V_41 ;
# if F_10 ( V_42 )
T_7 V_43 ;
# endif
if ( F_11 ( ( V_41 = V_33 [ 0 ] . V_14 ) , 16 * V_38 ) <= 0 )
return 0 ;
V_1 = ( V_30 * ) ( V_29 + 32 - ( ( T_4 ) V_29 % 32 ) ) ;
V_34 = ( unsigned int ) V_24 >> ( 1 + V_25 ) ;
V_35 = ( unsigned int ) V_24 + V_34 - ( V_34 << ( 1 + V_25 ) ) ;
if ( V_35 > V_34 && ( ( V_35 + 13 + 9 ) % 64 ) < ( V_38 - 1 ) ) {
V_34 ++ ;
V_35 -= V_38 - 1 ;
}
V_36 = 5 + 16 + ( ( V_34 + 20 + 16 ) & - 16 ) ;
V_26 [ 0 ] . V_16 = V_23 ;
V_28 [ 0 ] . V_23 = V_23 ;
V_28 [ 0 ] . V_22 = V_22 + 5 + 16 ;
memcpy ( V_28 [ 0 ] . V_22 - 16 , V_41 , 16 ) ;
memcpy ( V_28 [ 0 ] . V_3 , V_41 , 16 ) ;
V_41 += 16 ;
for ( V_37 = 1 ; V_37 < V_38 ; V_37 ++ ) {
V_28 [ V_37 ] . V_23 = V_26 [ V_37 ] . V_16 = V_26 [ V_37 - 1 ] . V_16 + V_34 ;
V_28 [ V_37 ] . V_22 = V_28 [ V_37 - 1 ] . V_22 + V_36 ;
memcpy ( V_28 [ V_37 ] . V_22 - 16 , V_41 , 16 ) ;
memcpy ( V_28 [ V_37 ] . V_3 , V_41 , 16 ) ;
V_41 += 16 ;
}
# if F_10 ( V_42 )
memcpy ( V_33 [ 0 ] . V_14 , V_5 -> V_11 . F_2 , 8 ) ;
V_43 = V_42 ( V_33 [ 0 ] . V_31 [ 0 ] ) ;
# endif
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
unsigned int V_15 = ( V_37 == ( V_38 - 1 ) ? V_35 : V_34 ) ;
# if ! F_10 ( V_42 )
unsigned int V_44 , V_45 ;
# endif
V_1 -> V_46 [ V_37 ] = V_5 -> V_11 . V_47 ;
V_1 -> V_48 [ V_37 ] = V_5 -> V_11 . V_49 ;
V_1 -> V_50 [ V_37 ] = V_5 -> V_11 . V_51 ;
V_1 -> V_52 [ V_37 ] = V_5 -> V_11 . V_53 ;
V_1 -> V_54 [ V_37 ] = V_5 -> V_11 . V_55 ;
# if F_10 ( V_42 )
V_33 [ V_37 ] . V_31 [ 0 ] = V_42 ( V_43 + V_37 ) ;
# else
for ( V_44 = V_37 , V_45 = 8 ; V_45 -- ; ) {
V_33 [ V_37 ] . V_14 [ V_45 ] = ( ( T_9 * ) V_5 -> V_11 . F_2 ) [ V_45 ] + V_44 ;
V_44 = ( V_33 [ V_37 ] . V_14 [ V_45 ] - V_44 ) >> ( sizeof( V_44 ) * 8 - 1 ) ;
}
# endif
V_33 [ V_37 ] . V_14 [ 8 ] = ( ( T_9 * ) V_5 -> V_11 . F_2 ) [ 8 ] ;
V_33 [ V_37 ] . V_14 [ 9 ] = ( ( T_9 * ) V_5 -> V_11 . F_2 ) [ 9 ] ;
V_33 [ V_37 ] . V_14 [ 10 ] = ( ( T_9 * ) V_5 -> V_11 . F_2 ) [ 10 ] ;
V_33 [ V_37 ] . V_14 [ 11 ] = ( T_9 ) ( V_15 >> 8 ) ;
V_33 [ V_37 ] . V_14 [ 12 ] = ( T_9 ) ( V_15 ) ;
memcpy ( V_33 [ V_37 ] . V_14 + 13 , V_26 [ V_37 ] . V_16 , 64 - 13 ) ;
V_26 [ V_37 ] . V_16 += 64 - 13 ;
V_26 [ V_37 ] . V_33 = ( V_15 - ( 64 - 13 ) ) / 64 ;
V_27 [ V_37 ] . V_16 = V_33 [ V_37 ] . V_14 ;
V_27 [ V_37 ] . V_33 = 1 ;
}
F_12 ( V_1 , V_27 , V_25 ) ;
# define F_13 2048
# if F_13 % 64
# error "MAXCHUNKSIZE is not divisible by 64"
# elif F_13
V_39 = ( ( V_34 <= V_35 ? V_34 : V_35 ) - ( 64 - 13 ) ) / 64 ;
if ( V_39 > F_13 / 64 ) {
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_27 [ V_37 ] . V_16 = V_26 [ V_37 ] . V_16 ;
V_27 [ V_37 ] . V_33 = F_13 / 64 ;
V_28 [ V_37 ] . V_33 = F_13 / 16 ;
}
do {
F_12 ( V_1 , V_27 , V_25 ) ;
F_14 ( V_28 , & V_5 -> V_8 , V_25 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_27 [ V_37 ] . V_16 = V_26 [ V_37 ] . V_16 += F_13 ;
V_26 [ V_37 ] . V_33 -= F_13 / 64 ;
V_27 [ V_37 ] . V_33 = F_13 / 64 ;
V_28 [ V_37 ] . V_23 += F_13 ;
V_28 [ V_37 ] . V_22 += F_13 ;
V_28 [ V_37 ] . V_33 = F_13 / 16 ;
memcpy ( V_28 [ V_37 ] . V_3 , V_28 [ V_37 ] . V_22 - 16 , 16 ) ;
}
V_40 += F_13 ;
V_39 -= F_13 / 64 ;
} while ( V_39 > F_13 / 64 );
}
# endif
# undef F_13
F_12 ( V_1 , V_26 , V_25 ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
unsigned int V_15 = ( V_37 == ( V_38 - 1 ) ? V_35 : V_34 ) ,
V_56 = V_26 [ V_37 ] . V_33 * 64 ;
const unsigned char * V_16 = V_26 [ V_37 ] . V_16 + V_56 ;
V_56 = ( V_15 - V_40 ) - ( 64 - 13 ) - V_56 ;
memcpy ( V_33 [ V_37 ] . V_14 , V_16 , V_56 ) ;
V_33 [ V_37 ] . V_14 [ V_56 ] = 0x80 ;
V_15 += 64 + 13 ;
V_15 *= 8 ;
if ( V_56 < ( 64 - 8 ) ) {
# ifdef F_15
V_33 [ V_37 ] . V_32 [ 15 ] = F_15 ( V_15 ) ;
# else
F_16 ( V_33 [ V_37 ] . V_14 + 60 , V_15 ) ;
# endif
V_27 [ V_37 ] . V_33 = 1 ;
} else {
# ifdef F_15
V_33 [ V_37 ] . V_32 [ 31 ] = F_15 ( V_15 ) ;
# else
F_16 ( V_33 [ V_37 ] . V_14 + 124 , V_15 ) ;
# endif
V_27 [ V_37 ] . V_33 = 2 ;
}
V_27 [ V_37 ] . V_16 = V_33 [ V_37 ] . V_14 ;
}
F_12 ( V_1 , V_27 , V_25 ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
# ifdef F_15
V_33 [ V_37 ] . V_32 [ 0 ] = F_15 ( V_1 -> V_46 [ V_37 ] ) ;
V_1 -> V_46 [ V_37 ] = V_5 -> V_10 . V_47 ;
V_33 [ V_37 ] . V_32 [ 1 ] = F_15 ( V_1 -> V_48 [ V_37 ] ) ;
V_1 -> V_48 [ V_37 ] = V_5 -> V_10 . V_49 ;
V_33 [ V_37 ] . V_32 [ 2 ] = F_15 ( V_1 -> V_50 [ V_37 ] ) ;
V_1 -> V_50 [ V_37 ] = V_5 -> V_10 . V_51 ;
V_33 [ V_37 ] . V_32 [ 3 ] = F_15 ( V_1 -> V_52 [ V_37 ] ) ;
V_1 -> V_52 [ V_37 ] = V_5 -> V_10 . V_53 ;
V_33 [ V_37 ] . V_32 [ 4 ] = F_15 ( V_1 -> V_54 [ V_37 ] ) ;
V_1 -> V_54 [ V_37 ] = V_5 -> V_10 . V_55 ;
V_33 [ V_37 ] . V_14 [ 20 ] = 0x80 ;
V_33 [ V_37 ] . V_32 [ 15 ] = F_15 ( ( 64 + 20 ) * 8 ) ;
# else
F_16 ( V_33 [ V_37 ] . V_14 + 0 , V_1 -> V_46 [ V_37 ] ) ;
V_1 -> V_46 [ V_37 ] = V_5 -> V_10 . V_47 ;
F_16 ( V_33 [ V_37 ] . V_14 + 4 , V_1 -> V_48 [ V_37 ] ) ;
V_1 -> V_48 [ V_37 ] = V_5 -> V_10 . V_49 ;
F_16 ( V_33 [ V_37 ] . V_14 + 8 , V_1 -> V_50 [ V_37 ] ) ;
V_1 -> V_50 [ V_37 ] = V_5 -> V_10 . V_51 ;
F_16 ( V_33 [ V_37 ] . V_14 + 12 , V_1 -> V_52 [ V_37 ] ) ;
V_1 -> V_52 [ V_37 ] = V_5 -> V_10 . V_53 ;
F_16 ( V_33 [ V_37 ] . V_14 + 16 , V_1 -> V_54 [ V_37 ] ) ;
V_1 -> V_54 [ V_37 ] = V_5 -> V_10 . V_55 ;
V_33 [ V_37 ] . V_14 [ 20 ] = 0x80 ;
F_16 ( V_33 [ V_37 ] . V_14 + 60 , ( 64 + 20 ) * 8 ) ;
# endif
V_27 [ V_37 ] . V_16 = V_33 [ V_37 ] . V_14 ;
V_27 [ V_37 ] . V_33 = 1 ;
}
F_12 ( V_1 , V_27 , V_25 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
unsigned int V_15 = ( V_37 == ( V_38 - 1 ) ? V_35 : V_34 ) , V_57 , V_45 ;
unsigned char * V_58 = V_22 ;
memcpy ( V_28 [ V_37 ] . V_22 , V_28 [ V_37 ] . V_23 , V_15 - V_40 ) ;
V_28 [ V_37 ] . V_23 = V_28 [ V_37 ] . V_22 ;
V_22 += 5 + 16 + V_15 ;
F_16 ( V_22 + 0 , V_1 -> V_46 [ V_37 ] ) ;
F_16 ( V_22 + 4 , V_1 -> V_48 [ V_37 ] ) ;
F_16 ( V_22 + 8 , V_1 -> V_50 [ V_37 ] ) ;
F_16 ( V_22 + 12 , V_1 -> V_52 [ V_37 ] ) ;
F_16 ( V_22 + 16 , V_1 -> V_54 [ V_37 ] ) ;
V_22 += 20 ;
V_15 += 20 ;
V_57 = 15 - V_15 % 16 ;
for ( V_45 = 0 ; V_45 <= V_57 ; V_45 ++ )
* ( V_22 ++ ) = V_57 ;
V_15 += V_57 + 1 ;
V_28 [ V_37 ] . V_33 = ( V_15 - V_40 ) / 16 ;
V_15 += 16 ;
V_58 [ 0 ] = ( ( T_9 * ) V_5 -> V_11 . F_2 ) [ 8 ] ;
V_58 [ 1 ] = ( ( T_9 * ) V_5 -> V_11 . F_2 ) [ 9 ] ;
V_58 [ 2 ] = ( ( T_9 * ) V_5 -> V_11 . F_2 ) [ 10 ] ;
V_58 [ 3 ] = ( T_9 ) ( V_15 >> 8 ) ;
V_58 [ 4 ] = ( T_9 ) ( V_15 ) ;
V_6 += V_15 + 5 ;
V_23 += V_34 ;
}
F_14 ( V_28 , & V_5 -> V_8 , V_25 ) ;
F_17 ( V_33 , sizeof( V_33 ) ) ;
F_17 ( V_1 , sizeof( * V_1 ) ) ;
return V_6 ;
}
static int F_18 ( T_1 * V_1 , unsigned char * V_22 ,
const unsigned char * V_59 , T_4 V_15 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
unsigned int V_60 ;
T_4 V_61 = V_5 -> V_12 , V_3 = 0 ,
V_62 = 0 ;
# if F_10 ( V_63 )
T_4 V_64 = 0 , V_33 ;
V_62 = V_19 - V_5 -> V_11 . V_18 ;
# endif
V_5 -> V_12 = V_13 ;
if ( V_15 % V_65 )
return 0 ;
if ( V_1 -> V_66 ) {
if ( V_61 == V_13 )
V_61 = V_15 ;
else if ( V_15 !=
( ( V_61 + V_67 +
V_65 ) & - V_65 ) )
return 0 ;
else if ( V_5 -> V_68 . V_69 >= V_70 )
V_3 = V_65 ;
# if F_10 ( V_63 )
if ( V_61 > ( V_62 + V_3 )
&& ( V_33 = ( V_61 - ( V_62 + V_3 ) ) / V_19 ) ) {
F_7 ( & V_5 -> V_11 , V_59 + V_3 , V_62 ) ;
F_19 ( V_59 , V_22 , V_33 , & V_5 -> V_8 ,
V_1 -> V_3 , & V_5 -> V_11 , V_59 + V_3 + V_62 ) ;
V_33 *= V_19 ;
V_64 += V_33 ;
V_62 += V_33 ;
V_5 -> V_11 . V_20 += V_33 >> 29 ;
V_5 -> V_11 . V_21 += V_33 <<= 3 ;
if ( V_5 -> V_11 . V_21 < ( unsigned int ) V_33 )
V_5 -> V_11 . V_20 ++ ;
} else {
V_62 = 0 ;
}
# endif
V_62 += V_3 ;
F_7 ( & V_5 -> V_11 , V_59 + V_62 , V_61 - V_62 ) ;
if ( V_61 != V_15 ) {
if ( V_59 != V_22 )
memcpy ( V_22 + V_64 , V_59 + V_64 , V_61 - V_64 ) ;
F_20 ( V_22 + V_61 , & V_5 -> V_11 ) ;
V_5 -> V_11 = V_5 -> V_10 ;
F_7 ( & V_5 -> V_11 , V_22 + V_61 , V_67 ) ;
F_20 ( V_22 + V_61 , & V_5 -> V_11 ) ;
V_61 += V_67 ;
for ( V_60 = V_15 - V_61 - 1 ; V_61 < V_15 ; V_61 ++ )
V_22 [ V_61 ] = V_60 ;
F_21 ( V_22 + V_64 , V_22 + V_64 , V_15 - V_64 ,
& V_5 -> V_8 , V_1 -> V_3 , 1 ) ;
} else {
F_21 ( V_59 + V_64 , V_22 + V_64 , V_15 - V_64 ,
& V_5 -> V_8 , V_1 -> V_3 , 1 ) ;
}
} else {
union {
unsigned int V_71 [ V_67 / sizeof( unsigned int )];
unsigned char V_14 [ 32 + V_67 ] ;
} V_72 , * V_73 ;
V_73 = ( void * ) ( ( ( T_4 ) V_72 . V_14 + 31 ) & ( ( T_4 ) 0 - 32 ) ) ;
if ( V_61 != V_13 ) {
T_4 V_24 , V_74 , V_45 , V_37 ;
unsigned int V_17 , V_75 , V_57 , V_76 ;
int V_6 = 1 ;
union {
unsigned int V_71 [ V_77 ] ;
unsigned char V_14 [ V_19 ] ;
} * F_2 = ( void * ) V_5 -> V_11 . F_2 ;
# if F_10 ( V_78 )
unsigned char V_79 [ V_65 ] ;
int V_80 = 0 ;
# endif
if ( ( V_5 -> V_68 . V_81 [ V_61 - 4 ] << 8 | V_5 -> V_68 . V_81 [ V_61 - 3 ] )
>= V_70 ) {
if ( V_15 < ( V_65 + V_67 + 1 ) )
return 0 ;
memcpy ( V_1 -> V_3 , V_59 , V_65 ) ;
V_59 += V_65 ;
V_22 += V_65 ;
V_15 -= V_65 ;
} else if ( V_15 < ( V_67 + 1 ) )
return 0 ;
# if F_10 ( V_78 )
if ( V_15 >= 1024 && V_1 -> V_7 == 32 ) {
memcpy ( V_79 , V_59 + V_15 - 2 * V_65 ,
V_65 ) ;
F_21 ( V_59 + V_15 - V_65 ,
V_22 + V_15 - V_65 , V_65 ,
& V_5 -> V_8 , V_79 , 0 ) ;
V_80 = 1 ;
} else
# endif
F_21 ( V_59 , V_22 , V_15 , & V_5 -> V_8 , V_1 -> V_3 , 0 ) ;
V_57 = V_22 [ V_15 - 1 ] ;
V_75 = V_15 - ( V_67 + 1 ) ;
V_75 |= ( 255 - V_75 ) >> ( sizeof( V_75 ) * 8 - 8 ) ;
V_75 &= 255 ;
V_24 = V_15 - ( V_67 + V_57 + 1 ) ;
V_74 = ( 0 - ( ( V_24 - V_15 ) >> ( sizeof( V_24 ) * 8 - 1 ) ) ) ;
V_24 &= V_74 ;
V_6 &= ( int ) V_74 ;
V_5 -> V_68 . V_81 [ V_61 - 2 ] = V_24 >> 8 ;
V_5 -> V_68 . V_81 [ V_61 - 1 ] = V_24 ;
V_5 -> V_11 = V_5 -> V_9 ;
F_7 ( & V_5 -> V_11 , V_5 -> V_68 . V_81 , V_61 ) ;
# if F_10 ( V_78 )
if ( V_80 ) {
V_33 = ( V_15 - ( 256 + 32 + V_19 ) ) / V_19 ;
V_64 = V_15 - V_65 - V_33 * V_19 ;
V_62 = V_19 - V_61 ;
F_21 ( V_59 , V_22 , V_64 , & V_5 -> V_8 , V_1 -> V_3 , 0 ) ;
F_7 ( & V_5 -> V_11 , V_22 , V_62 ) ;
F_22 ( V_59 + V_64 ,
V_22 + V_64 , V_33 , & V_5 -> V_8 ,
V_1 -> V_3 , & V_5 -> V_11 , V_22 + V_62 ) ;
V_62 += V_33 *= V_19 ;
V_22 += V_62 ;
V_15 -= V_62 ;
V_24 -= V_62 ;
V_5 -> V_11 . V_21 += ( V_33 << 3 ) ;
memcpy ( V_1 -> V_3 , V_79 , V_65 ) ;
}
# endif
# if 1
V_15 -= V_67 ;
if ( V_15 >= ( 256 + V_19 ) ) {
V_45 = ( V_15 - ( 256 + V_19 ) ) & ( 0 - V_19 ) ;
V_45 += V_19 - V_5 -> V_11 . V_18 ;
F_7 ( & V_5 -> V_11 , V_22 , V_45 ) ;
V_22 += V_45 ;
V_15 -= V_45 ;
V_24 -= V_45 ;
}
V_76 = V_5 -> V_11 . V_21 + ( V_24 << 3 ) ;
# ifdef F_15
V_76 = F_15 ( V_76 ) ;
# else
V_72 . V_14 [ 0 ] = 0 ;
V_72 . V_14 [ 1 ] = ( unsigned char ) ( V_76 >> 16 ) ;
V_72 . V_14 [ 2 ] = ( unsigned char ) ( V_76 >> 8 ) ;
V_72 . V_14 [ 3 ] = ( unsigned char ) V_76 ;
V_76 = V_72 . V_71 [ 0 ] ;
# endif
V_73 -> V_71 [ 0 ] = 0 ;
V_73 -> V_71 [ 1 ] = 0 ;
V_73 -> V_71 [ 2 ] = 0 ;
V_73 -> V_71 [ 3 ] = 0 ;
V_73 -> V_71 [ 4 ] = 0 ;
for ( V_17 = V_5 -> V_11 . V_18 , V_45 = 0 ; V_45 < V_15 ; V_45 ++ ) {
T_4 V_14 = V_22 [ V_45 ] ;
V_74 = ( V_45 - V_24 ) >> ( sizeof( V_45 ) * 8 - 8 ) ;
V_14 &= V_74 ;
V_14 |= 0x80 & ~ V_74 & ~ ( ( V_24 - V_45 ) >> ( sizeof( V_45 ) * 8 - 8 ) ) ;
F_2 -> V_14 [ V_17 ++ ] = ( unsigned char ) V_14 ;
if ( V_17 != V_19 )
continue;
V_74 = 0 - ( ( V_24 + 7 - V_45 ) >> ( sizeof( V_45 ) * 8 - 1 ) ) ;
F_2 -> V_71 [ V_77 - 1 ] |= V_76 & V_74 ;
F_8 ( & V_5 -> V_11 , F_2 , 1 ) ;
V_74 &= 0 - ( ( V_45 - V_24 - 72 ) >> ( sizeof( V_45 ) * 8 - 1 ) ) ;
V_73 -> V_71 [ 0 ] |= V_5 -> V_11 . V_47 & V_74 ;
V_73 -> V_71 [ 1 ] |= V_5 -> V_11 . V_49 & V_74 ;
V_73 -> V_71 [ 2 ] |= V_5 -> V_11 . V_51 & V_74 ;
V_73 -> V_71 [ 3 ] |= V_5 -> V_11 . V_53 & V_74 ;
V_73 -> V_71 [ 4 ] |= V_5 -> V_11 . V_55 & V_74 ;
V_17 = 0 ;
}
for ( V_37 = V_17 ; V_37 < V_19 ; V_37 ++ , V_45 ++ )
F_2 -> V_14 [ V_37 ] = 0 ;
if ( V_17 > V_19 - 8 ) {
V_74 = 0 - ( ( V_24 + 8 - V_45 ) >> ( sizeof( V_45 ) * 8 - 1 ) ) ;
F_2 -> V_71 [ V_77 - 1 ] |= V_76 & V_74 ;
F_8 ( & V_5 -> V_11 , F_2 , 1 ) ;
V_74 &= 0 - ( ( V_45 - V_24 - 73 ) >> ( sizeof( V_45 ) * 8 - 1 ) ) ;
V_73 -> V_71 [ 0 ] |= V_5 -> V_11 . V_47 & V_74 ;
V_73 -> V_71 [ 1 ] |= V_5 -> V_11 . V_49 & V_74 ;
V_73 -> V_71 [ 2 ] |= V_5 -> V_11 . V_51 & V_74 ;
V_73 -> V_71 [ 3 ] |= V_5 -> V_11 . V_53 & V_74 ;
V_73 -> V_71 [ 4 ] |= V_5 -> V_11 . V_55 & V_74 ;
memset ( F_2 , 0 , V_19 ) ;
V_45 += 64 ;
}
F_2 -> V_71 [ V_77 - 1 ] = V_76 ;
F_8 ( & V_5 -> V_11 , F_2 , 1 ) ;
V_74 = 0 - ( ( V_45 - V_24 - 73 ) >> ( sizeof( V_45 ) * 8 - 1 ) ) ;
V_73 -> V_71 [ 0 ] |= V_5 -> V_11 . V_47 & V_74 ;
V_73 -> V_71 [ 1 ] |= V_5 -> V_11 . V_49 & V_74 ;
V_73 -> V_71 [ 2 ] |= V_5 -> V_11 . V_51 & V_74 ;
V_73 -> V_71 [ 3 ] |= V_5 -> V_11 . V_53 & V_74 ;
V_73 -> V_71 [ 4 ] |= V_5 -> V_11 . V_55 & V_74 ;
# ifdef F_15
V_73 -> V_71 [ 0 ] = F_15 ( V_73 -> V_71 [ 0 ] ) ;
V_73 -> V_71 [ 1 ] = F_15 ( V_73 -> V_71 [ 1 ] ) ;
V_73 -> V_71 [ 2 ] = F_15 ( V_73 -> V_71 [ 2 ] ) ;
V_73 -> V_71 [ 3 ] = F_15 ( V_73 -> V_71 [ 3 ] ) ;
V_73 -> V_71 [ 4 ] = F_15 ( V_73 -> V_71 [ 4 ] ) ;
# else
for ( V_37 = 0 ; V_37 < 5 ; V_37 ++ ) {
V_17 = V_73 -> V_71 [ V_37 ] ;
V_73 -> V_14 [ 4 * V_37 + 0 ] = ( unsigned char ) ( V_17 >> 24 ) ;
V_73 -> V_14 [ 4 * V_37 + 1 ] = ( unsigned char ) ( V_17 >> 16 ) ;
V_73 -> V_14 [ 4 * V_37 + 2 ] = ( unsigned char ) ( V_17 >> 8 ) ;
V_73 -> V_14 [ 4 * V_37 + 3 ] = ( unsigned char ) V_17 ;
}
# endif
V_15 += V_67 ;
# else
F_7 ( & V_5 -> V_11 , V_22 , V_24 ) ;
V_17 = V_5 -> V_11 . V_18 ;
F_20 ( V_73 -> V_14 , & V_5 -> V_11 ) ;
{
unsigned int V_82 , V_83 ;
V_82 =
1 + ( ( V_19 - 9 - V_17 ) >> ( sizeof( V_17 ) * 8 - 1 ) ) ;
V_17 += ( unsigned int ) ( V_15 - V_24 ) ;
V_83 = V_17 / V_19 ;
V_17 %= V_19 ;
V_83 +=
1 + ( ( V_19 - 9 - V_17 ) >> ( sizeof( V_17 ) * 8 - 1 ) ) ;
for (; V_82 < V_83 ; V_82 ++ )
F_8 ( & V_5 -> V_11 , F_2 , 1 ) ;
}
# endif
V_5 -> V_11 = V_5 -> V_10 ;
F_7 ( & V_5 -> V_11 , V_73 -> V_14 , V_67 ) ;
F_20 ( V_73 -> V_14 , & V_5 -> V_11 ) ;
V_22 += V_24 ;
V_15 -= V_24 ;
# if 1
{
unsigned char * V_84 = V_22 + V_15 - 1 - V_75 - V_67 ;
T_4 V_56 = V_22 - V_84 ;
unsigned int V_14 , V_85 ;
V_75 += V_67 ;
for ( V_17 = 0 , V_37 = 0 , V_45 = 0 ; V_45 < V_75 ; V_45 ++ ) {
V_14 = V_84 [ V_45 ] ;
V_85 =
( ( int ) ( V_45 - V_56 - V_67 ) ) >> ( sizeof( int ) *
8 - 1 ) ;
V_17 |= ( V_14 ^ V_57 ) & ~ V_85 ;
V_85 &= ( ( int ) ( V_56 - 1 - V_45 ) ) >> ( sizeof( int ) * 8 - 1 ) ;
V_17 |= ( V_14 ^ V_73 -> V_14 [ V_37 ] ) & V_85 ;
V_37 += 1 & V_85 ;
}
V_75 -= V_67 ;
V_17 = 0 - ( ( 0 - V_17 ) >> ( sizeof( V_17 ) * 8 - 1 ) ) ;
V_6 &= ( int ) ~ V_17 ;
}
# else
for ( V_17 = 0 , V_37 = 0 ; V_37 < V_67 ; V_37 ++ )
V_17 |= V_22 [ V_37 ] ^ V_73 -> V_14 [ V_37 ] ;
V_17 = 0 - ( ( 0 - V_17 ) >> ( sizeof( V_17 ) * 8 - 1 ) ) ;
V_6 &= ( int ) ~ V_17 ;
V_57 = ( V_57 & ~ V_17 ) | ( V_75 & V_17 ) ;
V_22 = V_22 + V_15 - 1 - V_57 ;
for ( V_17 = 0 , V_37 = 0 ; V_37 < V_57 ; V_37 ++ )
V_17 |= V_22 [ V_37 ] ^ V_57 ;
V_17 = ( 0 - V_17 ) >> ( sizeof( V_17 ) * 8 - 1 ) ;
V_6 &= ( int ) ~ V_17 ;
# endif
return V_6 ;
} else {
# if F_10 ( V_78 )
if ( V_15 >= 1024 && V_1 -> V_7 == 32 ) {
if ( V_62 %= V_19 )
V_33 = ( V_15 - 3 * V_19 ) / V_19 ;
else
V_33 = ( V_15 - 2 * V_19 ) / V_19 ;
V_64 = V_15 - V_33 * V_19 ;
F_21 ( V_59 , V_22 , V_64 , & V_5 -> V_8 , V_1 -> V_3 , 0 ) ;
F_7 ( & V_5 -> V_11 , V_22 , V_62 ) ;
F_22 ( V_59 + V_64 ,
V_22 + V_64 , V_33 , & V_5 -> V_8 ,
V_1 -> V_3 , & V_5 -> V_11 , V_22 + V_62 ) ;
V_62 += V_33 *= V_19 ;
V_22 += V_62 ;
V_15 -= V_62 ;
V_5 -> V_11 . V_20 += V_33 >> 29 ;
V_5 -> V_11 . V_21 += V_33 <<= 3 ;
if ( V_5 -> V_11 . V_21 < ( unsigned int ) V_33 )
V_5 -> V_11 . V_20 ++ ;
} else
# endif
F_21 ( V_59 , V_22 , V_15 , & V_5 -> V_8 , V_1 -> V_3 , 0 ) ;
F_7 ( & V_5 -> V_11 , V_22 , V_15 ) ;
}
}
return 1 ;
}
static int F_23 ( T_1 * V_1 , int type , int V_86 ,
void * V_16 )
{
T_2 * V_5 = F_2 ( V_1 ) ;
switch ( type ) {
case V_87 :
{
unsigned int V_37 ;
unsigned char V_88 [ 64 ] ;
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
if ( V_86 > ( int ) sizeof( V_88 ) ) {
F_5 ( & V_5 -> V_9 ) ;
F_7 ( & V_5 -> V_9 , V_16 , V_86 ) ;
F_20 ( V_88 , & V_5 -> V_9 ) ;
} else {
memcpy ( V_88 , V_16 , V_86 ) ;
}
for ( V_37 = 0 ; V_37 < sizeof( V_88 ) ; V_37 ++ )
V_88 [ V_37 ] ^= 0x36 ;
F_5 ( & V_5 -> V_9 ) ;
F_7 ( & V_5 -> V_9 , V_88 , sizeof( V_88 ) ) ;
for ( V_37 = 0 ; V_37 < sizeof( V_88 ) ; V_37 ++ )
V_88 [ V_37 ] ^= 0x36 ^ 0x5c ;
F_5 ( & V_5 -> V_10 ) ;
F_7 ( & V_5 -> V_10 , V_88 , sizeof( V_88 ) ) ;
F_17 ( V_88 , sizeof( V_88 ) ) ;
return 1 ;
}
case V_89 :
{
unsigned char * V_84 = V_16 ;
unsigned int V_15 = V_84 [ V_86 - 2 ] << 8 | V_84 [ V_86 - 1 ] ;
if ( V_1 -> V_66 ) {
V_5 -> V_12 = V_15 ;
if ( ( V_5 -> V_68 . V_69 =
V_84 [ V_86 - 4 ] << 8 | V_84 [ V_86 - 3 ] ) >= V_70 ) {
V_15 -= V_65 ;
V_84 [ V_86 - 2 ] = V_15 >> 8 ;
V_84 [ V_86 - 1 ] = V_15 ;
}
V_5 -> V_11 = V_5 -> V_9 ;
F_7 ( & V_5 -> V_11 , V_84 , V_86 ) ;
return ( int ) ( ( ( V_15 + V_67 +
V_65 ) & - V_65 )
- V_15 ) ;
} else {
if ( V_86 > 13 )
V_86 = 13 ;
memcpy ( V_5 -> V_68 . V_81 , V_16 , V_86 ) ;
V_5 -> V_12 = V_86 ;
return V_67 ;
}
}
# if ! F_10 ( V_90 ) && V_91
case V_92 :
return ( int ) ( 5 + 16 + ( ( V_86 + 20 + 16 ) & - 16 ) ) ;
case V_93 :
{
T_10 * V_94 =
( T_10 * ) V_16 ;
unsigned int V_25 = 1 , V_38 ;
unsigned int V_34 , V_35 , V_36 , V_24 ;
if ( V_86 < ( int ) sizeof( T_10 ) )
return - 1 ;
V_24 = V_94 -> V_23 [ 11 ] << 8 | V_94 -> V_23 [ 12 ] ;
if ( V_1 -> V_66 ) {
if ( ( V_94 -> V_23 [ 9 ] << 8 | V_94 -> V_23 [ 10 ] ) < V_70 )
return - 1 ;
if ( V_24 ) {
if ( V_24 < 4096 )
return 0 ;
if ( V_24 >= 8192 && V_95 [ 2 ] & ( 1 << 5 ) )
V_25 = 2 ;
} else if ( ( V_25 = V_94 -> V_96 / 4 ) && V_25 <= 2 )
V_24 = V_94 -> V_15 ;
else
return - 1 ;
V_5 -> V_11 = V_5 -> V_9 ;
F_7 ( & V_5 -> V_11 , V_94 -> V_23 , 13 ) ;
V_38 = 4 * V_25 ;
V_25 += 1 ;
V_34 = V_24 >> V_25 ;
V_35 = V_24 + V_34 - ( V_34 << V_25 ) ;
if ( V_35 > V_34 && ( ( V_35 + 13 + 9 ) % 64 < ( V_38 - 1 ) ) ) {
V_34 ++ ;
V_35 -= V_38 - 1 ;
}
V_36 = 5 + 16 + ( ( V_34 + 20 + 16 ) & - 16 ) ;
V_36 = ( V_36 << V_25 ) - V_36 ;
V_36 += 5 + 16 + ( ( V_35 + 20 + 16 ) & - 16 ) ;
V_94 -> V_96 = V_38 ;
return ( int ) V_36 ;
} else
return - 1 ;
}
case V_97 :
{
T_10 * V_94 =
( T_10 * ) V_16 ;
return ( int ) F_9 ( V_5 , V_94 -> V_22 ,
V_94 -> V_23 , V_94 -> V_15 ,
V_94 -> V_96 / 4 ) ;
}
case V_98 :
# endif
default:
return - 1 ;
}
}
const T_11 * F_24 ( void )
{
return ( V_95 [ 1 ] & V_99 ?
& V_100 : NULL ) ;
}
const T_11 * F_25 ( void )
{
return ( V_95 [ 1 ] & V_99 ?
& V_101 : NULL ) ;
}
const T_11 * F_24 ( void )
{
return NULL ;
}
const T_11 * F_25 ( void )
{
return NULL ;
}
