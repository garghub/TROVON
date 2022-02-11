static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_6 ( V_11 , V_8 , V_9 ) ;
}
static int F_7 ( const int V_12 , const T_1 V_8 )
{
if ( V_12 == V_13 )
return V_8 < 0x20 && V_8 != 0x01 && V_8 != 0x0f &&
( V_8 < 0x13 || V_8 > 0x19 ) && V_8 != 0x1d && V_8 != 0x1e ;
if ( V_12 == V_14 )
return V_8 < 0x20 && V_8 != 0x01 && V_8 != 0x0f &&
V_8 != 0x14 && V_8 != 0x18 && V_8 != 0x19 &&
V_8 != 0x1d && V_8 != 0x1e ;
if ( F_8 ( ( V_8 >= 0x3b && V_8 <= 0x3f ) || V_8 == 0x5c || V_8 == 0x5f ||
V_8 == 0xa3 || V_8 == 0xa7 || V_8 == 0xab || V_8 == 0xaf || ( V_8 >= 0xb5 && V_8 <= 0xb7 ) ||
V_8 == 0xd3 || V_8 == 0xd7 || V_8 == 0xdb || V_8 == 0xdf || ( V_8 >= 0xe5 && V_8 <= 0xe7 ) ||
V_8 == 0x82 || ( V_8 >= 0x89 && V_8 <= 0x8e ) ) )
return 0 ;
switch ( V_12 ) {
case V_15 :
return V_8 != 0x14 && ( V_8 < 0x18 || V_8 > 0x1e ) && V_8 < 0x20 ;
case V_16 :
return V_8 != 0x14 && ( V_8 < 0x18 || V_8 > 0x1e ) && ( V_8 < 0x20 || V_8 > 0x3f ) &&
V_8 != 0x5d && V_8 < 0x63 ;
case V_17 :
return ( V_8 < 0x1a || V_8 > 0x1e ) && ( V_8 < 0x20 || V_8 > 0x2f ) &&
( V_8 < 0x63 || V_8 > 0x7f ) && V_8 != 0x33 && V_8 != 0x37 &&
V_8 != 0x81 && V_8 < 0xf0 ;
case V_18 :
return ( V_8 < 0x20 || V_8 > 0x2f ) && V_8 != 0x65 && ( V_8 < 0xfc || V_8 > 0xfe ) ;
case V_19 :
return ( V_8 < 0x1a || V_8 > 0x1d ) && ( V_8 < 0x20 || V_8 > 0x22 ) &&
( V_8 < 0x26 || V_8 > 0x28 ) && V_8 != 0x33 && V_8 != 0x37 &&
( V_8 < 0x63 || V_8 > 0x7f ) && V_8 != 0x81 && V_8 < 0xf0 ;
}
return 1 ;
}
static int F_9 ( struct V_2 * V_3 , const unsigned char * V_20 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
unsigned char V_8 , V_22 ;
while ( * V_20 != 0x00 ) {
V_8 = * ( V_20 ++ ) ;
V_22 = * ( V_20 ++ ) ;
if ( F_7 ( V_21 -> V_23 , V_8 ) ) {
if ( F_4 ( V_3 , V_8 , V_22 ) < 0 )
return - 1 ;
} else {
F_10 ( 1 , V_24 , V_3 , L_1 , V_8 ) ;
}
}
return 0 ;
}
static inline int F_11 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_12 ( V_11 , V_8 ) ;
}
static int F_13 ( T_1 V_25 )
{
V_25 ^= ( V_25 >> 4 ) ;
V_25 ^= ( V_25 >> 2 ) ;
V_25 ^= ( V_25 >> 1 ) ;
return V_25 & 1 ;
}
static int F_14 ( T_1 * V_26 , T_1 * V_27 )
{
static const T_1 V_28 [] = {
0xf0 , 0x78 , 0x70 , 0xf0 , 0xb4 , 0x3c , 0x34 , 0xb4 ,
0xb0 , 0x38 , 0x30 , 0xb0 , 0xf0 , 0x78 , 0x70 , 0xf0 ,
0xd2 , 0x5a , 0x52 , 0xd2 , 0x96 , 0x1e , 0x16 , 0x96 ,
0x92 , 0x1a , 0x12 , 0x92 , 0xd2 , 0x5a , 0x52 , 0xd2 ,
0xd0 , 0x58 , 0x50 , 0xd0 , 0x94 , 0x1c , 0x14 , 0x94 ,
0x90 , 0x18 , 0x10 , 0x90 , 0xd0 , 0x58 , 0x50 , 0xd0 ,
0xf0 , 0x78 , 0x70 , 0xf0 , 0xb4 , 0x3c , 0x34 , 0xb4 ,
0xb0 , 0x38 , 0x30 , 0xb0 , 0xf0 , 0x78 , 0x70 , 0xf0 ,
0xe1 , 0x69 , 0x61 , 0xe1 , 0xa5 , 0x2d , 0x25 , 0xa5 ,
0xa1 , 0x29 , 0x21 , 0xa1 , 0xe1 , 0x69 , 0x61 , 0xe1 ,
0xc3 , 0x4b , 0x43 , 0xc3 , 0x87 , 0x0f , 0x07 , 0x87 ,
0x83 , 0x0b , 0x03 , 0x83 , 0xc3 , 0x4b , 0x43 , 0xc3 ,
0xc1 , 0x49 , 0x41 , 0xc1 , 0x85 , 0x0d , 0x05 , 0x85 ,
0x81 , 0x09 , 0x01 , 0x81 , 0xc1 , 0x49 , 0x41 , 0xc1 ,
0xe1 , 0x69 , 0x61 , 0xe1 , 0xa5 , 0x2d , 0x25 , 0xa5 ,
0xa1 , 0x29 , 0x21 , 0xa1 , 0xe1 , 0x69 , 0x61 , 0xe1 ,
0xe0 , 0x68 , 0x60 , 0xe0 , 0xa4 , 0x2c , 0x24 , 0xa4 ,
0xa0 , 0x28 , 0x20 , 0xa0 , 0xe0 , 0x68 , 0x60 , 0xe0 ,
0xc2 , 0x4a , 0x42 , 0xc2 , 0x86 , 0x0e , 0x06 , 0x86 ,
0x82 , 0x0a , 0x02 , 0x82 , 0xc2 , 0x4a , 0x42 , 0xc2 ,
0xc0 , 0x48 , 0x40 , 0xc0 , 0x84 , 0x0c , 0x04 , 0x84 ,
0x80 , 0x08 , 0x00 , 0x80 , 0xc0 , 0x48 , 0x40 , 0xc0 ,
0xe0 , 0x68 , 0x60 , 0xe0 , 0xa4 , 0x2c , 0x24 , 0xa4 ,
0xa0 , 0x28 , 0x20 , 0xa0 , 0xe0 , 0x68 , 0x60 , 0xe0 ,
0xf0 , 0x78 , 0x70 , 0xf0 , 0xb4 , 0x3c , 0x34 , 0xb4 ,
0xb0 , 0x38 , 0x30 , 0xb0 , 0xf0 , 0x78 , 0x70 , 0xf0 ,
0xd2 , 0x5a , 0x52 , 0xd2 , 0x96 , 0x1e , 0x16 , 0x96 ,
0x92 , 0x1a , 0x12 , 0x92 , 0xd2 , 0x5a , 0x52 , 0xd2 ,
0xd0 , 0x58 , 0x50 , 0xd0 , 0x94 , 0x1c , 0x14 , 0x94 ,
0x90 , 0x18 , 0x10 , 0x90 , 0xd0 , 0x58 , 0x50 , 0xd0 ,
0xf0 , 0x78 , 0x70 , 0xf0 , 0xb4 , 0x3c , 0x34 , 0xb4 ,
0xb0 , 0x38 , 0x30 , 0xb0 , 0xf0 , 0x78 , 0x70 , 0xf0 ,
} ;
int V_29 ;
T_1 V_25 , V_30 = 0 ;
for ( V_29 = 0 ; V_29 < 2 * 13 ; V_29 += 2 ) {
V_30 |= V_28 [ V_27 [ V_29 ] ] | V_28 [ V_27 [ V_29 + 1 ] ] ;
V_25 = ( V_28 [ V_27 [ V_29 + 1 ] ] & 0xf ) | ( ( V_28 [ V_27 [ V_29 ] ] & 0xf ) << 4 ) ;
V_26 [ V_29 / 2 ] = V_25 ;
}
return V_30 & 0xf0 ;
}
static int F_15 ( T_1 * V_27 )
{
static const int V_31 [ 8 ] = {
0 , 0 , 0 , 1 , 0 , 1 , 1 , 1
} ;
unsigned char V_32 ;
int V_33 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
int V_34 = V_31 [ V_27 [ V_29 ] & 7 ] ;
int V_35 = V_31 [ ( V_27 [ V_29 ] >> 3 ) & 7 ] ;
if ( V_34 == V_35 )
return - 1 ;
V_33 |= V_35 << V_29 ;
}
V_32 = V_33 & 15 ;
V_32 ^= V_32 >> 2 ;
V_32 ^= V_32 >> 1 ;
if ( ! ( V_32 & 1 ) )
return - 1 ;
return V_33 ;
}
static int F_16 ( struct V_2 * V_3 , T_2 V_36 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
T_2 V_37 ;
T_2 V_38 ;
T_2 V_39 ;
T_3 V_40 ;
T_1 V_41 = 0 ;
if ( ! F_7 ( V_21 -> V_23 , V_42 ) )
return 0 ;
F_10 ( 1 , V_24 , V_3 , L_2 , V_36 ) ;
if ( V_36 < 32000 || V_36 > 48000 )
return - V_43 ;
V_39 = ( V_21 -> V_44 & V_45 ) ? 5994 : 5000 ;
V_37 = ( 25600 * V_36 ) / V_39 ;
V_40 = V_36 ;
V_40 = V_40 << 31 ;
F_17 ( V_40 , V_21 -> V_46 ) ;
V_38 = V_40 ;
if ( V_21 -> V_47 ) {
V_37 = V_37 * V_21 -> V_48 / 16 ;
V_38 = V_38 * V_21 -> V_48 / 16 ;
V_41 = 0x80 ;
if ( V_21 -> V_48 == 3 )
V_41 |= 0x40 ;
}
if ( V_21 -> V_49 )
V_41 |= 0x08 ;
if ( V_21 -> V_50 ) {
V_37 <<= 1 ;
V_38 <<= 1 ;
}
F_4 ( V_3 , V_51 , 0x03 ) ;
F_4 ( V_3 , V_52 , 0x10 << V_21 -> V_50 ) ;
F_4 ( V_3 , V_53 , V_41 ) ;
F_4 ( V_3 , V_42 , V_37 & 0xff ) ;
F_4 ( V_3 , V_42 + 1 ,
( V_37 >> 8 ) & 0xff ) ;
F_4 ( V_3 , V_42 + 2 ,
( V_37 >> 16 ) & 0x03 ) ;
F_4 ( V_3 , V_54 , V_38 & 0xff ) ;
F_4 ( V_3 , V_54 + 1 , ( V_38 >> 8 ) & 0xff ) ;
F_4 ( V_3 , V_54 + 2 , ( V_38 >> 16 ) & 0x3f ) ;
V_21 -> V_55 = V_36 ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
switch ( V_5 -> V_12 ) {
case V_56 :
if ( V_21 -> V_57 -> V_58 )
V_21 -> V_59 -> V_58 =
F_11 ( V_3 , V_60 ) & 0x7f ;
break;
}
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
switch ( V_5 -> V_12 ) {
case V_61 :
F_4 ( V_3 , V_62 , V_5 -> V_58 ) ;
break;
case V_63 :
F_4 ( V_3 , V_64 , V_5 -> V_58 ) ;
break;
case V_65 :
F_4 ( V_3 , V_66 , V_5 -> V_58 ) ;
break;
case V_67 :
F_4 ( V_3 , V_68 , V_5 -> V_58 ) ;
break;
case V_56 :
if ( V_21 -> V_57 -> V_58 )
F_4 ( V_3 , V_60 , V_21 -> V_59 -> V_58 ) ;
else
F_4 ( V_3 , V_60 , V_21 -> V_59 -> V_58 | 0x80 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , int V_69 , int V_70 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_71 , V_72 ;
int V_73 ;
int V_74 ;
int V_75 = V_21 -> V_44 & V_76 ;
int V_77 = V_75 ? 576 : 480 ;
F_10 ( 1 , V_24 , V_3 , L_3 , V_69 , V_70 ) ;
if ( ( V_69 < 1 ) || ( V_69 > 1440 ) )
return - V_43 ;
if ( ( V_70 < 1 ) || ( V_70 > V_77 ) )
return - V_43 ;
if ( ! F_7 ( V_21 -> V_23 , V_78 ) ) {
if ( V_69 != 720 )
return - V_43 ;
if ( V_70 != V_77 )
return - V_43 ;
}
V_21 -> V_69 = V_69 ;
V_21 -> V_70 = V_70 ;
if ( ! F_7 ( V_21 -> V_23 , V_79 ) )
return 0 ;
F_4 ( V_3 , V_79 ,
( T_1 ) ( V_69 & 0xff ) ) ;
F_4 ( V_3 , V_80 ,
( T_1 ) ( ( V_69 >> 8 ) & 0xff ) ) ;
V_74 = V_70 / 2 ;
if ( ! V_75 )
V_74 += ( V_81 - 480 ) >> 1 ;
F_4 ( V_3 , V_82 ,
( T_1 ) ( V_74 & 0xff ) ) ;
F_4 ( V_3 , V_83 ,
( T_1 ) ( ( V_74 >> 8 ) & 0xff ) ) ;
V_71 = ( int ) ( 720 / V_69 ) ;
V_71 = V_71 ? V_71 : 1 ;
V_72 = ( int ) ( ( 1024 * 720 ) / ( V_71 * V_69 ) ) ;
F_4 ( V_3 , V_78 ,
( T_1 ) ( V_71 & 0x3f ) ) ;
F_10 ( 1 , V_24 , V_3 , L_4 , V_71 , V_72 ) ;
F_4 ( V_3 , V_84 ,
( T_1 ) ( V_72 & 0xff ) ) ;
F_4 ( V_3 , V_85 ,
( T_1 ) ( ( V_72 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 , V_86 ,
( T_1 ) ( ( V_72 >> 1 ) & 0xff ) ) ;
F_4 ( V_3 , V_87 ,
( T_1 ) ( ( V_72 >> 9 ) & 0xff ) ) ;
V_73 = ( int ) ( ( 1024 * V_77 ) / V_70 ) ;
F_10 ( 1 , V_24 , V_3 , L_5 , V_77 , V_73 ) ;
F_4 ( V_3 , V_88 ,
( T_1 ) ( 64 * 1024 / V_73 ) ) ;
F_4 ( V_3 , V_89 ,
( T_1 ) ( 64 * 1024 / V_73 ) ) ;
F_4 ( V_3 , V_90 ,
( T_1 ) ( V_73 & 0xff ) ) ;
F_4 ( V_3 , V_91 ,
( T_1 ) ( ( V_73 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 , V_92 ,
( T_1 ) ( V_73 & 0xff ) ) ;
F_4 ( V_3 , V_93 ,
( T_1 ) ( ( V_73 >> 8 ) & 0xff ) ) ;
F_9 ( V_3 , V_94 ) ;
F_4 ( V_3 , V_95 ,
F_11 ( V_3 , V_95 ) | 0x20 ) ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 , T_4 V_44 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_44 == V_21 -> V_44 )
return;
V_21 -> V_44 = V_44 ;
if ( V_44 & V_45 ) {
F_10 ( 1 , V_24 , V_3 , L_6 ) ;
if ( V_21 -> V_23 == V_15 ) {
T_1 V_8 = F_11 ( V_3 , V_96 ) ;
V_8 &= ~ ( V_97 | V_98 ) ;
V_8 |= V_97 ;
F_4 ( V_3 , V_96 , V_8 ) ;
} else {
F_9 ( V_3 , V_99 ) ;
}
F_20 ( V_3 , 720 , 480 ) ;
} else {
F_10 ( 1 , V_24 , V_3 , L_7 ) ;
if ( V_21 -> V_23 == V_15 ) {
T_1 V_8 = F_11 ( V_3 , V_96 ) ;
V_8 &= ~ ( V_97 | V_98 ) ;
F_4 ( V_3 , V_96 , V_8 ) ;
} else {
F_9 ( V_3 , V_100 ) ;
}
F_20 ( V_3 , 720 , 576 ) ;
}
if ( V_21 -> V_23 <= V_16 ||
V_21 -> V_23 == V_15 ) {
T_1 V_8 = F_11 ( V_3 , V_101 ) & 0x8f ;
if ( V_44 == V_102 ) {
V_8 |= 0x30 ;
} else if ( V_44 == V_103 ) {
V_8 |= 0x20 ;
} else if ( V_44 == V_104 ) {
V_8 |= 0x10 ;
} else if ( V_44 == V_105 ) {
V_8 |= 0x40 ;
} else if ( V_44 & V_106 ) {
V_8 |= 0x50 ;
}
F_4 ( V_3 , V_101 , V_8 ) ;
} else {
int V_107 = F_11 ( V_3 , V_95 ) & 0x10 ;
if ( V_107 && V_21 -> V_23 == V_17 )
F_9 ( V_3 , V_108 ) ;
F_16 ( V_3 , V_21 -> V_55 ) ;
}
}
static void F_22 ( struct V_2 * V_3 , struct V_109 * V_110 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_75 = ( V_21 -> V_44 & V_76 ) ;
T_1 V_111 [ 24 ] ;
int V_29 , V_112 ;
#if 1
if ( ! F_7 ( V_21 -> V_23 , V_113 ) )
return;
#else
if ( V_21 -> V_23 != V_18 )
return;
#endif
for ( V_29 = 0 ; V_29 <= 23 ; V_29 ++ )
V_111 [ V_29 ] = 0xff ;
if ( V_110 == NULL ) {
if ( V_75 )
for ( V_29 = 6 ; V_29 <= 23 ; V_29 ++ )
V_111 [ V_29 ] = 0xdd ;
else
for ( V_29 = 10 ; V_29 <= 21 ; V_29 ++ )
V_111 [ V_29 ] = 0xdd ;
} else {
if ( V_75 ) {
for ( V_29 = 0 ; V_29 <= 5 ; V_29 ++ )
V_110 -> V_114 [ 0 ] [ V_29 ] =
V_110 -> V_114 [ 1 ] [ V_29 ] = 0 ;
}
else {
for ( V_29 = 0 ; V_29 <= 9 ; V_29 ++ )
V_110 -> V_114 [ 0 ] [ V_29 ] =
V_110 -> V_114 [ 1 ] [ V_29 ] = 0 ;
for ( V_29 = 22 ; V_29 <= 23 ; V_29 ++ )
V_110 -> V_114 [ 0 ] [ V_29 ] =
V_110 -> V_114 [ 1 ] [ V_29 ] = 0 ;
}
for ( V_29 = 6 ; V_29 <= 23 ; V_29 ++ ) {
V_111 [ V_29 ] = 0 ;
for ( V_112 = 0 ; V_112 <= 1 ; V_112 ++ ) {
switch ( V_110 -> V_114 [ 1 - V_112 ] [ V_29 ] ) {
case 0 :
V_111 [ V_29 ] |= 0xf << ( 4 * V_112 ) ;
break;
case V_115 :
V_111 [ V_29 ] |= 1 << ( 4 * V_112 ) ;
break;
case V_116 :
V_111 [ V_29 ] |= 4 << ( 4 * V_112 ) ;
break;
case V_117 :
V_111 [ V_29 ] |= 5 << ( 4 * V_112 ) ;
break;
case V_118 :
V_111 [ V_29 ] |= 7 << ( 4 * V_112 ) ;
break;
}
}
}
}
for ( V_29 = 2 ; V_29 <= 23 ; V_29 ++ ) {
F_4 ( V_3 , V_29 - 2 + V_113 , V_111 [ V_29 ] ) ;
}
F_9 ( V_3 , V_110 == NULL ?
V_108 :
V_119 ) ;
}
static int F_23 ( struct V_2 * V_3 , struct V_109 * V_120 )
{
static T_5 V_121 [] = {
0 , V_115 , 0 ,
0 , V_116 ,
V_117 , 0 ,
V_118 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0
} ;
int V_29 ;
memset ( V_120 -> V_114 , 0 , sizeof( V_120 -> V_114 ) ) ;
V_120 -> V_122 = 0 ;
if ( F_11 ( V_3 , V_95 ) & 0x10 )
return 0 ;
for ( V_29 = 2 ; V_29 <= 23 ; V_29 ++ ) {
T_1 V_123 = F_11 ( V_3 , V_29 - 2 + V_113 ) ;
V_120 -> V_114 [ 0 ] [ V_29 ] = V_121 [ V_123 >> 4 ] ;
V_120 -> V_114 [ 1 ] [ V_29 ] = V_121 [ V_123 & 0xf ] ;
V_120 -> V_122 |=
V_120 -> V_114 [ 0 ] [ V_29 ] | V_120 -> V_114 [ 1 ] [ V_29 ] ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_124 * V_110 )
{
F_22 ( V_3 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_109 * V_110 )
{
F_22 ( V_3 , V_110 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_125 * V_110 )
{
if ( V_110 -> V_126 != V_127 )
return - V_43 ;
V_110 -> V_128 = V_129 ;
V_110 -> V_130 = V_131 ;
return F_20 ( V_3 , V_110 -> V_69 , V_110 -> V_70 ) ;
}
static int F_27 ( struct V_2 * V_3 , struct V_132 * V_133 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
static const char V_134 [] = {
0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0
} ;
T_1 * V_27 = V_133 -> V_27 ;
T_2 V_33 ;
int V_135 , V_136 ;
V_133 -> type = 0 ;
V_135 = V_27 [ 2 ] ;
V_136 = V_27 [ 3 ] ;
if ( V_21 -> V_44 & V_45 )
V_135 ^= 0x40 ;
V_27 += 4 ;
V_133 -> V_27 = V_27 ;
V_133 -> V_137 = ( ( V_135 & 0x40 ) != 0 ) ;
V_133 -> line = ( V_135 & 0x3f ) << 3 ;
V_133 -> line |= ( V_136 & 0x70 ) >> 4 ;
V_136 &= 0xf ;
if ( ! memcmp ( V_27 , V_134 , sizeof( V_134 ) ) )
return 0 ;
switch ( V_136 ) {
case 1 :
V_133 -> type = V_115 ;
break;
case 4 :
if ( ! F_13 ( V_27 [ 0 ] ) || ! F_13 ( V_27 [ 1 ] ) )
return 0 ;
V_133 -> type = V_116 ;
break;
case 5 :
V_33 = F_15 ( V_27 ) ;
if ( V_33 == - 1 )
return 0 ;
V_27 [ 0 ] = V_33 & 0xff ;
V_27 [ 1 ] = V_33 >> 8 ;
V_133 -> type = V_117 ;
break;
case 7 :
if ( F_14 ( V_27 , V_27 ) != 0 )
return 0 ;
V_133 -> type = V_118 ;
break;
default:
break;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_138 * V_139 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_140 ;
if ( V_21 -> V_141 )
return 0 ;
V_140 = F_11 ( V_3 , V_142 ) ;
F_10 ( 1 , V_24 , V_3 , L_8 , V_140 ) ;
V_139 -> signal = ( ( V_140 & ( 1 << 6 ) ) == 0 ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , T_4 V_44 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
V_21 -> V_141 = 0 ;
F_21 ( V_3 , V_44 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
V_21 -> V_141 = 1 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
T_2 V_143 , T_2 V_144 , T_2 V_145 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
T_1 V_146 = ( V_21 -> V_23 <= V_14 ) ? 0xf8 : 0xf0 ;
F_10 ( 1 , V_24 , V_3 , L_9 ,
V_143 , V_144 ) ;
if ( ( V_21 -> V_23 <= V_16 ||
V_21 -> V_23 == V_15 ) &&
( V_143 == V_147 ||
V_143 == V_148 ) ) {
return - V_43 ;
}
if ( V_143 > V_149 )
return - V_43 ;
if ( V_21 -> V_143 == V_143 && V_21 -> V_144 == V_144 )
return 0 ;
F_10 ( 1 , V_24 , V_3 , L_10 ,
( V_143 >= V_150 ) ? L_11 : L_12 ,
( V_144 == V_151 ) ? L_13 : L_14 ) ;
V_21 -> V_143 = V_143 ;
if ( V_21 -> V_23 <= V_14 ) {
if ( V_143 >= V_147 )
V_143 -= 2 ;
F_4 ( V_3 , V_152 ,
( F_11 ( V_3 , V_152 ) & 0x3f ) |
( ( V_144 & 0xc0 ) ^ 0x40 ) ) ;
F_4 ( V_3 , V_153 ,
( F_11 ( V_3 , V_153 ) & 0xf0 ) |
( ( V_144 & 2 ) ? 0x0a : 0 ) ) ;
}
F_4 ( V_3 , V_154 ,
( F_11 ( V_3 , V_154 ) & V_146 ) |
V_143 ) ;
F_4 ( V_3 , V_155 ,
( F_11 ( V_3 , V_155 ) & 0x7f ) |
( V_21 -> V_143 >= V_150 ? 0x80 : 0x0 ) ) ;
V_21 -> V_144 = V_144 ;
if ( V_21 -> V_23 == V_17 ||
V_21 -> V_23 == V_18 ) {
F_4 ( V_3 , V_156 ,
( F_11 ( V_3 , V_156 ) & 0xfe ) |
( V_21 -> V_144 & 0x01 ) ) ;
}
if ( V_21 -> V_23 > V_14 ) {
if ( V_145 & V_157 )
F_4 ( V_3 , V_158 , 0x20 ) ;
else
F_4 ( V_3 , V_158 , 0x21 ) ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , T_2 V_58 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_21 -> V_23 > V_14 )
return - V_43 ;
F_4 ( V_3 , 0x11 , ( F_11 ( V_3 , 0x11 ) & 0x7f ) |
( V_58 ? 0x80 : 0 ) ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , int V_159 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
F_10 ( 1 , V_24 , V_3 , L_15 ,
V_159 ? L_16 : L_17 ) ;
if ( V_21 -> V_159 == V_159 )
return 0 ;
V_21 -> V_159 = V_159 ;
if ( ! F_7 ( V_21 -> V_23 , V_160 ) )
return 0 ;
F_4 ( V_3 , V_160 , V_21 -> V_159 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , T_2 V_36 , T_2 V_161 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_36 != V_162 && V_36 != V_163 )
return - V_43 ;
V_21 -> V_46 = V_36 ;
V_21 -> V_50 = V_161 & V_164 ;
V_21 -> V_48 = ( V_161 & V_165 ) ? 3 : 4 ;
V_21 -> V_47 = V_161 & V_166 ;
V_21 -> V_49 = V_161 & V_167 ;
F_16 ( V_3 , V_21 -> V_55 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , T_2 V_58 )
{
F_10 ( 1 , V_24 , V_3 , L_18 ) ;
F_9 ( V_3 , V_94 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_168 * V_22 )
{
switch ( V_22 -> V_12 ) {
case V_117 :
if ( F_11 ( V_3 , 0x6b ) & 0xc0 )
return - V_169 ;
V_22 -> V_22 [ 0 ] = F_11 ( V_3 , 0x6c ) ;
V_22 -> V_22 [ 1 ] = F_11 ( V_3 , 0x6d ) ;
return 0 ;
case V_116 :
if ( V_22 -> V_128 == 0 ) {
if ( F_11 ( V_3 , 0x66 ) & 0x30 )
return - V_169 ;
V_22 -> V_22 [ 0 ] = F_11 ( V_3 , 0x69 ) ;
V_22 -> V_22 [ 1 ] = F_11 ( V_3 , 0x6a ) ;
return 0 ;
}
if ( F_11 ( V_3 , 0x66 ) & 0xc0 )
return - V_169 ;
V_22 -> V_22 [ 0 ] = F_11 ( V_3 , 0x67 ) ;
V_22 -> V_22 [ 1 ] = F_11 ( V_3 , 0x68 ) ;
return 0 ;
default:
return - V_43 ;
}
}
static int F_37 ( struct V_2 * V_3 , T_4 * V_44 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_170 , V_171 ;
V_170 = F_11 ( V_3 , V_142 ) ;
if ( V_21 -> V_23 == V_18 ) {
V_171 = F_11 ( V_3 , V_172 ) ;
F_10 ( 1 , V_24 , V_3 , L_19 , V_171 ) ;
switch ( V_171 & 0x03 ) {
case 1 :
* V_44 &= V_173 ;
break;
case 2 :
* V_44 &= V_174 | V_175 | V_103 |
V_102 | V_104 ;
break;
case 3 :
* V_44 &= V_106 ;
break;
default:
* V_44 = V_176 ;
break;
}
}
F_10 ( 1 , V_24 , V_3 , L_20 , V_170 ) ;
if ( V_170 & 0x40 ) {
* V_44 = V_176 ;
goto V_177;
}
if ( V_170 & 0x20 )
* V_44 &= V_45 ;
else
* V_44 &= V_76 ;
V_177:
F_10 ( 1 , V_24 , V_3 , L_21 , * V_44 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , T_2 * V_140 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_171 = 0x80 ;
int V_170 ;
* V_140 = V_178 ;
if ( V_21 -> V_23 == V_18 )
V_171 = F_11 ( V_3 , V_172 ) ;
V_170 = F_11 ( V_3 , V_142 ) ;
if ( ( V_170 & 0xc1 ) == 0x81 && ( V_171 & 0xc0 ) == 0x80 )
* V_140 = 0 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_179 * V_8 )
{
V_8 -> V_58 = F_11 ( V_3 , V_8 -> V_8 & 0xff ) ;
V_8 -> V_180 = 1 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , const struct V_179 * V_8 )
{
F_4 ( V_3 , V_8 -> V_8 & 0xff , V_8 -> V_58 & 0xff ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
int V_171 , V_170 ;
int V_181 ;
int V_182 ;
F_42 ( V_3 , L_22 , V_21 -> V_55 ) ;
if ( V_21 -> V_23 != V_18 ) {
V_170 = F_11 ( V_3 , V_142 ) ;
V_181 = ( V_170 & 0xc1 ) == 0x81 ;
F_42 ( V_3 , L_23 , V_181 ? L_24 : L_25 ) ;
F_42 ( V_3 , L_26 , ( V_170 & 0x20 ) ? L_27 : L_28 ) ;
return 0 ;
}
V_171 = F_11 ( V_3 , V_172 ) ;
V_170 = F_11 ( V_3 , V_142 ) ;
V_181 = ( V_170 & 0xc1 ) == 0x81 && ( V_171 & 0xc0 ) == 0x80 ;
V_182 = ! ( V_170 & 0x10 ) ;
if ( V_21 -> V_143 >= 6 )
F_42 ( V_3 , L_29 , V_21 -> V_143 - 6 ) ;
else
F_42 ( V_3 , L_30 , V_21 -> V_143 ) ;
F_42 ( V_3 , L_23 , V_181 ? ( V_182 ? L_31 : L_32 ) : L_25 ) ;
F_42 ( V_3 , L_26 , ( V_170 & 0x20 ) ? L_27 : L_28 ) ;
switch ( V_171 & 0x03 ) {
case 1 :
F_42 ( V_3 , L_33 ) ;
break;
case 2 :
F_42 ( V_3 , L_34 ) ;
break;
case 3 :
F_42 ( V_3 , L_35 ) ;
break;
default:
F_42 ( V_3 , L_36 ) ;
break;
}
F_42 ( V_3 , L_37 , V_21 -> V_69 , V_21 -> V_70 ) ;
F_43 ( & V_21 -> V_7 , V_3 -> V_183 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_21 ,
struct V_184 * V_22 )
{
struct V_2 * V_3 = & V_21 -> V_3 ;
T_1 V_185 ;
if ( V_21 -> V_23 != V_15 &&
V_21 -> V_23 != V_16 )
return;
if ( V_22 -> V_186 ) {
V_185 = F_11 ( V_3 , V_96 ) ;
V_185 &= ~ V_187 ;
V_185 |= ( ( * V_22 -> V_186 ) << V_188 ) ;
F_4 ( V_3 , V_96 , V_185 ) ;
}
if ( V_22 -> V_189 ) {
V_185 = F_11 ( V_3 , V_152 ) ;
V_185 &= ~ V_190 ;
if ( * V_22 -> V_189 )
V_185 |= ( 1 << V_191 ) ;
F_4 ( V_3 , V_152 , V_185 ) ;
}
if ( V_22 -> V_192 ) {
V_185 = F_11 ( V_3 , V_152 ) ;
V_185 &= ~ V_193 ;
V_185 |= ( * V_22 -> V_192 << V_194 ) ;
F_4 ( V_3 , V_152 , V_185 ) ;
}
if ( V_22 -> V_195 ) {
V_185 = F_11 ( V_3 , V_196 ) ;
V_185 &= ~ V_197 ;
V_185 |= ( * V_22 -> V_195 << V_198 ) ;
F_45 ( * V_22 -> V_195 == V_199 ) ;
F_4 ( V_3 , V_196 , V_185 ) ;
}
if ( V_22 -> V_200 ) {
V_185 = F_11 ( V_3 , V_196 ) ;
V_185 &= ~ V_201 ;
V_185 |= ( * V_22 -> V_200 << V_202 ) ;
F_4 ( V_3 , V_196 , V_185 ) ;
}
if ( V_22 -> V_203 ) {
V_185 = F_11 ( V_3 , V_153 ) ;
V_185 &= ~ V_204 ;
if ( * V_22 -> V_203 )
V_185 |= ( 1 << V_205 ) ;
F_4 ( V_3 , V_153 , V_185 ) ;
}
}
static int F_46 ( struct V_10 * V_11 ,
const struct V_206 * V_12 ,
char * V_183 )
{
char V_207 [ V_208 ] ;
char V_209 ;
int V_29 ;
int V_210 ;
V_210 = ! V_12 || V_12 -> V_211 == 1 ;
for ( V_29 = 0 ; V_29 < V_208 ; V_29 ++ ) {
F_6 ( V_11 , 0 , V_29 ) ;
V_207 [ V_29 ] = F_12 ( V_11 , 0 ) ;
V_183 [ V_29 ] = ( V_207 [ V_29 ] & 0x0f ) + '0' ;
if ( V_183 [ V_29 ] > '9' )
V_183 [ V_29 ] += 'a' - '9' - 1 ;
}
V_183 [ V_29 ] = '\0' ;
if ( ! memcmp ( V_183 + 1 , L_38 , 4 ) ) {
V_209 = V_183 [ 5 ] ;
snprintf ( V_183 , V_208 , L_39 , V_209 ) ;
if ( ! V_210 && strcmp ( V_183 , V_12 -> V_183 ) )
return - V_43 ;
switch ( V_209 ) {
case '1' :
if ( V_207 [ 0 ] & 0xf0 ) {
snprintf ( V_183 , V_208 , L_40 , V_209 ) ;
F_47 ( V_11 , L_41 ) ;
return V_14 ;
}
return V_13 ;
case '3' :
return V_16 ;
case '4' :
return V_17 ;
case '5' :
return V_18 ;
case '8' :
return V_19 ;
default:
F_42 ( V_11 ,
L_42 ) ;
return V_13 ;
}
}
if ( ! memcmp ( V_183 , L_43 , 4 ) ) {
V_209 = 0 ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
V_209 = V_209 << 1 ;
V_209 |= ( V_207 [ V_29 ] & 0x80 ) ? 1 : 0 ;
}
F_48 ( V_183 , L_44 , V_208 ) ;
if ( ! V_210 && strcmp ( V_183 , V_12 -> V_183 ) )
return - V_43 ;
F_49 ( 1 , V_24 , V_11 ,
L_45 ,
V_183 , 16 , V_207 , V_11 -> V_212 << 1 ) ;
return V_15 ;
}
F_49 ( 1 , V_24 , V_11 , L_46 ,
16 , V_207 , V_11 -> V_212 << 1 ) ;
return - V_213 ;
}
static int F_50 ( struct V_10 * V_11 ,
const struct V_206 * V_12 )
{
struct V_1 * V_21 ;
struct V_2 * V_3 ;
struct V_214 * V_7 ;
struct V_184 * V_215 ;
int V_23 ;
char V_183 [ V_208 + 1 ] ;
if ( ! F_51 ( V_11 -> V_216 , V_217 ) )
return - V_169 ;
V_23 = F_46 ( V_11 , V_12 , V_183 ) ;
if ( V_23 == - V_43 ) {
F_52 ( V_11 , L_47 ,
V_183 , V_12 -> V_183 ) ;
return - V_213 ;
}
if ( V_23 < 0 )
return V_23 ;
F_48 ( V_11 -> V_183 , V_183 , sizeof( V_11 -> V_183 ) ) ;
V_21 = F_53 ( & V_11 -> V_218 , sizeof( * V_21 ) , V_219 ) ;
if ( V_21 == NULL )
return - V_220 ;
V_3 = & V_21 -> V_3 ;
F_54 ( V_3 , V_11 , & V_221 ) ;
F_47 ( V_11 , L_48 , V_183 ,
V_11 -> V_212 << 1 , V_11 -> V_216 -> V_183 ) ;
V_7 = & V_21 -> V_7 ;
F_55 ( V_7 , 6 ) ;
F_56 ( V_7 , & V_222 ,
V_61 , 0 , 255 , 1 , 128 ) ;
F_56 ( V_7 , & V_222 ,
V_63 , 0 , 127 , 1 , 64 ) ;
F_56 ( V_7 , & V_222 ,
V_65 , 0 , 127 , 1 , 64 ) ;
F_56 ( V_7 , & V_222 ,
V_67 , - 128 , 127 , 1 , 0 ) ;
V_21 -> V_57 = F_56 ( V_7 , & V_222 ,
V_56 , 0 , 1 , 1 , 1 ) ;
V_21 -> V_59 = F_56 ( V_7 , & V_222 ,
V_223 , 0 , 127 , 1 , 40 ) ;
V_3 -> V_224 = V_7 ;
if ( V_7 -> error ) {
int V_30 = V_7 -> error ;
F_57 ( V_7 ) ;
return V_30 ;
}
F_58 ( 2 , & V_21 -> V_57 , 0 , true ) ;
V_21 -> V_143 = - 1 ;
V_21 -> V_144 = V_151 ;
V_21 -> V_159 = 1 ;
V_21 -> V_141 = 0 ;
V_21 -> V_23 = V_23 ;
V_21 -> V_55 = 48000 ;
F_10 ( 1 , V_24 , V_3 , L_49 ) ;
V_21 -> V_46 = V_163 ;
V_215 = V_11 -> V_218 . V_225 ;
switch ( V_21 -> V_23 ) {
case V_13 :
case V_14 :
F_9 ( V_3 , V_226 ) ;
break;
case V_15 :
F_9 ( V_3 , V_227 ) ;
break;
case V_16 :
if ( V_215 && V_215 -> V_228 )
F_9 ( V_3 , V_227 ) ;
else
F_9 ( V_3 , V_229 ) ;
break;
default:
V_21 -> V_46 = V_162 ;
F_9 ( V_3 , V_230 ) ;
}
if ( V_21 -> V_23 > V_14 && V_21 -> V_23 != V_15 )
F_9 ( V_3 , V_231 ) ;
if ( V_215 )
F_44 ( V_21 , V_215 ) ;
F_21 ( V_3 , V_173 ) ;
F_59 ( V_7 ) ;
F_10 ( 1 , V_24 , V_3 , L_50 ,
F_11 ( V_3 , V_172 ) ,
F_11 ( V_3 , V_142 ) ) ;
return 0 ;
}
static int F_60 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_61 ( V_11 ) ;
F_62 ( V_3 ) ;
F_57 ( V_3 -> V_224 ) ;
return 0 ;
}
