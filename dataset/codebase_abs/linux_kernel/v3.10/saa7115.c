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
return V_8 != 0x14 && ( V_8 < 0x18 || V_8 > 0x1e ) && ( V_8 < 0x20 || V_8 > 0x3f ) &&
V_8 != 0x5d && V_8 < 0x63 ;
case V_16 :
return ( V_8 < 0x1a || V_8 > 0x1e ) && ( V_8 < 0x20 || V_8 > 0x2f ) &&
( V_8 < 0x63 || V_8 > 0x7f ) && V_8 != 0x33 && V_8 != 0x37 &&
V_8 != 0x81 && V_8 < 0xf0 ;
case V_17 :
return ( V_8 < 0x20 || V_8 > 0x2f ) && V_8 != 0x65 && ( V_8 < 0xfc || V_8 > 0xfe ) ;
case V_18 :
return ( V_8 < 0x1a || V_8 > 0x1d ) && ( V_8 < 0x20 || V_8 > 0x22 ) &&
( V_8 < 0x26 || V_8 > 0x28 ) && V_8 != 0x33 && V_8 != 0x37 &&
( V_8 < 0x63 || V_8 > 0x7f ) && V_8 != 0x81 && V_8 < 0xf0 ;
}
return 1 ;
}
static int F_9 ( struct V_2 * V_3 , const unsigned char * V_19 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
unsigned char V_8 , V_21 ;
while ( * V_19 != 0x00 ) {
V_8 = * ( V_19 ++ ) ;
V_21 = * ( V_19 ++ ) ;
if ( F_7 ( V_20 -> V_22 , V_8 ) ) {
if ( F_4 ( V_3 , V_8 , V_21 ) < 0 )
return - 1 ;
} else {
F_10 ( 1 , V_23 , V_3 , L_1 , V_8 ) ;
}
}
return 0 ;
}
static inline int F_11 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_12 ( V_11 , V_8 ) ;
}
static int F_13 ( T_1 V_24 )
{
V_24 ^= ( V_24 >> 4 ) ;
V_24 ^= ( V_24 >> 2 ) ;
V_24 ^= ( V_24 >> 1 ) ;
return V_24 & 1 ;
}
static int F_14 ( T_1 * V_25 , T_1 * V_26 )
{
static const T_1 V_27 [] = {
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
int V_28 ;
T_1 V_24 , V_29 = 0 ;
for ( V_28 = 0 ; V_28 < 2 * 13 ; V_28 += 2 ) {
V_29 |= V_27 [ V_26 [ V_28 ] ] | V_27 [ V_26 [ V_28 + 1 ] ] ;
V_24 = ( V_27 [ V_26 [ V_28 + 1 ] ] & 0xf ) | ( ( V_27 [ V_26 [ V_28 ] ] & 0xf ) << 4 ) ;
V_25 [ V_28 / 2 ] = V_24 ;
}
return V_29 & 0xf0 ;
}
static int F_15 ( T_1 * V_26 )
{
static const int V_30 [ 8 ] = {
0 , 0 , 0 , 1 , 0 , 1 , 1 , 1
} ;
unsigned char V_31 ;
int V_32 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ ) {
int V_33 = V_30 [ V_26 [ V_28 ] & 7 ] ;
int V_34 = V_30 [ ( V_26 [ V_28 ] >> 3 ) & 7 ] ;
if ( V_33 == V_34 )
return - 1 ;
V_32 |= V_34 << V_28 ;
}
V_31 = V_32 & 15 ;
V_31 ^= V_31 >> 2 ;
V_31 ^= V_31 >> 1 ;
if ( ! ( V_31 & 1 ) )
return - 1 ;
return V_32 ;
}
static int F_16 ( struct V_2 * V_3 , T_2 V_35 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_2 V_36 ;
T_2 V_37 ;
T_2 V_38 ;
T_3 V_39 ;
T_1 V_40 = 0 ;
if ( ! F_7 ( V_20 -> V_22 , V_41 ) )
return 0 ;
F_10 ( 1 , V_23 , V_3 , L_2 , V_35 ) ;
if ( V_35 < 32000 || V_35 > 48000 )
return - V_42 ;
V_38 = ( V_20 -> V_43 & V_44 ) ? 5994 : 5000 ;
V_36 = ( 25600 * V_35 ) / V_38 ;
V_39 = V_35 ;
V_39 = V_39 << 31 ;
F_17 ( V_39 , V_20 -> V_45 ) ;
V_37 = V_39 ;
if ( V_20 -> V_46 ) {
V_36 = V_36 * V_20 -> V_47 / 16 ;
V_37 = V_37 * V_20 -> V_47 / 16 ;
V_40 = 0x80 ;
if ( V_20 -> V_47 == 3 )
V_40 |= 0x40 ;
}
if ( V_20 -> V_48 )
V_40 |= 0x08 ;
if ( V_20 -> V_49 ) {
V_36 <<= 1 ;
V_37 <<= 1 ;
}
F_4 ( V_3 , V_50 , 0x03 ) ;
F_4 ( V_3 , V_51 , 0x10 << V_20 -> V_49 ) ;
F_4 ( V_3 , V_52 , V_40 ) ;
F_4 ( V_3 , V_41 , V_36 & 0xff ) ;
F_4 ( V_3 , V_41 + 1 ,
( V_36 >> 8 ) & 0xff ) ;
F_4 ( V_3 , V_41 + 2 ,
( V_36 >> 16 ) & 0x03 ) ;
F_4 ( V_3 , V_53 , V_37 & 0xff ) ;
F_4 ( V_3 , V_53 + 1 , ( V_37 >> 8 ) & 0xff ) ;
F_4 ( V_3 , V_53 + 2 , ( V_37 >> 16 ) & 0x3f ) ;
V_20 -> V_54 = V_35 ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
switch ( V_5 -> V_12 ) {
case V_55 :
if ( V_20 -> V_56 -> V_57 )
V_20 -> V_58 -> V_57 =
F_11 ( V_3 , V_59 ) & 0x7f ;
break;
}
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
switch ( V_5 -> V_12 ) {
case V_60 :
F_4 ( V_3 , V_61 , V_5 -> V_57 ) ;
break;
case V_62 :
F_4 ( V_3 , V_63 , V_5 -> V_57 ) ;
break;
case V_64 :
F_4 ( V_3 , V_65 , V_5 -> V_57 ) ;
break;
case V_66 :
F_4 ( V_3 , V_67 , V_5 -> V_57 ) ;
break;
case V_55 :
if ( V_20 -> V_56 -> V_57 )
F_4 ( V_3 , V_59 , V_20 -> V_58 -> V_57 ) ;
else
F_4 ( V_3 , V_59 , V_20 -> V_58 -> V_57 | 0x80 ) ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , int V_68 , int V_69 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
int V_70 , V_71 ;
int V_72 ;
int V_73 ;
int V_74 = V_20 -> V_43 & V_75 ;
int V_76 = V_74 ? 576 : 480 ;
F_10 ( 1 , V_23 , V_3 , L_3 , V_68 , V_69 ) ;
if ( ( V_68 < 1 ) || ( V_68 > 1440 ) )
return - V_42 ;
if ( ( V_69 < 1 ) || ( V_69 > V_76 ) )
return - V_42 ;
if ( ! F_7 ( V_20 -> V_22 , V_77 ) ) {
if ( V_68 != 720 )
return - V_42 ;
if ( V_69 != V_76 )
return - V_42 ;
}
V_20 -> V_68 = V_68 ;
V_20 -> V_69 = V_69 ;
if ( ! F_7 ( V_20 -> V_22 , V_78 ) )
return 0 ;
F_4 ( V_3 , V_78 ,
( T_1 ) ( V_68 & 0xff ) ) ;
F_4 ( V_3 , V_79 ,
( T_1 ) ( ( V_68 >> 8 ) & 0xff ) ) ;
V_73 = V_69 / 2 ;
if ( ! V_74 )
V_73 += ( V_80 - 480 ) >> 1 ;
F_4 ( V_3 , V_81 ,
( T_1 ) ( V_73 & 0xff ) ) ;
F_4 ( V_3 , V_82 ,
( T_1 ) ( ( V_73 >> 8 ) & 0xff ) ) ;
V_70 = ( int ) ( 720 / V_68 ) ;
V_70 = V_70 ? V_70 : 1 ;
V_71 = ( int ) ( ( 1024 * 720 ) / ( V_70 * V_68 ) ) ;
F_4 ( V_3 , V_77 ,
( T_1 ) ( V_70 & 0x3f ) ) ;
F_10 ( 1 , V_23 , V_3 , L_4 , V_70 , V_71 ) ;
F_4 ( V_3 , V_83 ,
( T_1 ) ( V_71 & 0xff ) ) ;
F_4 ( V_3 , V_84 ,
( T_1 ) ( ( V_71 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 , V_85 ,
( T_1 ) ( ( V_71 >> 1 ) & 0xff ) ) ;
F_4 ( V_3 , V_86 ,
( T_1 ) ( ( V_71 >> 9 ) & 0xff ) ) ;
V_72 = ( int ) ( ( 1024 * V_76 ) / V_69 ) ;
F_10 ( 1 , V_23 , V_3 , L_5 , V_76 , V_72 ) ;
F_4 ( V_3 , V_87 ,
( T_1 ) ( 64 * 1024 / V_72 ) ) ;
F_4 ( V_3 , V_88 ,
( T_1 ) ( 64 * 1024 / V_72 ) ) ;
F_4 ( V_3 , V_89 ,
( T_1 ) ( V_72 & 0xff ) ) ;
F_4 ( V_3 , V_90 ,
( T_1 ) ( ( V_72 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 , V_91 ,
( T_1 ) ( V_72 & 0xff ) ) ;
F_4 ( V_3 , V_92 ,
( T_1 ) ( ( V_72 >> 8 ) & 0xff ) ) ;
F_9 ( V_3 , V_93 ) ;
F_4 ( V_3 , V_94 ,
F_11 ( V_3 , V_94 ) | 0x20 ) ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 , T_4 V_43 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
if ( V_43 == V_20 -> V_43 )
return;
V_20 -> V_43 = V_43 ;
if ( V_43 & V_44 ) {
F_10 ( 1 , V_23 , V_3 , L_6 ) ;
F_9 ( V_3 , V_95 ) ;
F_20 ( V_3 , 720 , 480 ) ;
} else {
F_10 ( 1 , V_23 , V_3 , L_7 ) ;
F_9 ( V_3 , V_96 ) ;
F_20 ( V_3 , 720 , 576 ) ;
}
if ( V_20 -> V_22 <= V_15 ) {
T_1 V_8 = F_11 ( V_3 , V_97 ) & 0x8f ;
if ( V_43 == V_98 ) {
V_8 |= 0x30 ;
} else if ( V_43 == V_99 ) {
V_8 |= 0x20 ;
} else if ( V_43 == V_100 ) {
V_8 |= 0x10 ;
} else if ( V_43 == V_101 ) {
V_8 |= 0x40 ;
} else if ( V_43 & V_102 ) {
V_8 |= 0x50 ;
}
F_4 ( V_3 , V_97 , V_8 ) ;
} else {
int V_103 = F_11 ( V_3 , V_94 ) & 0x10 ;
if ( V_103 && V_20 -> V_22 == V_16 ) {
F_9 ( V_3 , V_104 ) ;
}
F_16 ( V_3 , V_20 -> V_54 ) ;
}
}
static void F_22 ( struct V_2 * V_3 , struct V_105 * V_106 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
int V_74 = ( V_20 -> V_43 & V_75 ) ;
T_1 V_107 [ 24 ] ;
int V_28 , V_108 ;
#if 1
if ( ! F_7 ( V_20 -> V_22 , V_109 ) )
return;
#else
if ( V_20 -> V_22 != V_17 )
return;
#endif
for ( V_28 = 0 ; V_28 <= 23 ; V_28 ++ )
V_107 [ V_28 ] = 0xff ;
if ( V_106 == NULL ) {
if ( V_74 )
for ( V_28 = 6 ; V_28 <= 23 ; V_28 ++ )
V_107 [ V_28 ] = 0xdd ;
else
for ( V_28 = 10 ; V_28 <= 21 ; V_28 ++ )
V_107 [ V_28 ] = 0xdd ;
} else {
if ( V_74 ) {
for ( V_28 = 0 ; V_28 <= 5 ; V_28 ++ )
V_106 -> V_110 [ 0 ] [ V_28 ] =
V_106 -> V_110 [ 1 ] [ V_28 ] = 0 ;
}
else {
for ( V_28 = 0 ; V_28 <= 9 ; V_28 ++ )
V_106 -> V_110 [ 0 ] [ V_28 ] =
V_106 -> V_110 [ 1 ] [ V_28 ] = 0 ;
for ( V_28 = 22 ; V_28 <= 23 ; V_28 ++ )
V_106 -> V_110 [ 0 ] [ V_28 ] =
V_106 -> V_110 [ 1 ] [ V_28 ] = 0 ;
}
for ( V_28 = 6 ; V_28 <= 23 ; V_28 ++ ) {
V_107 [ V_28 ] = 0 ;
for ( V_108 = 0 ; V_108 <= 1 ; V_108 ++ ) {
switch ( V_106 -> V_110 [ 1 - V_108 ] [ V_28 ] ) {
case 0 :
V_107 [ V_28 ] |= 0xf << ( 4 * V_108 ) ;
break;
case V_111 :
V_107 [ V_28 ] |= 1 << ( 4 * V_108 ) ;
break;
case V_112 :
V_107 [ V_28 ] |= 4 << ( 4 * V_108 ) ;
break;
case V_113 :
V_107 [ V_28 ] |= 5 << ( 4 * V_108 ) ;
break;
case V_114 :
V_107 [ V_28 ] |= 7 << ( 4 * V_108 ) ;
break;
}
}
}
}
for ( V_28 = 2 ; V_28 <= 23 ; V_28 ++ ) {
F_4 ( V_3 , V_28 - 2 + V_109 , V_107 [ V_28 ] ) ;
}
F_9 ( V_3 , V_106 == NULL ?
V_104 :
V_115 ) ;
}
static int F_23 ( struct V_2 * V_3 , struct V_105 * V_116 )
{
static T_5 V_117 [] = {
0 , V_111 , 0 ,
0 , V_112 ,
V_113 , 0 ,
V_114 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0
} ;
int V_28 ;
memset ( V_116 -> V_110 , 0 , sizeof( V_116 -> V_110 ) ) ;
V_116 -> V_118 = 0 ;
if ( F_11 ( V_3 , V_94 ) & 0x10 )
return 0 ;
for ( V_28 = 2 ; V_28 <= 23 ; V_28 ++ ) {
T_1 V_119 = F_11 ( V_3 , V_28 - 2 + V_109 ) ;
V_116 -> V_110 [ 0 ] [ V_28 ] = V_117 [ V_119 >> 4 ] ;
V_116 -> V_110 [ 1 ] [ V_28 ] = V_117 [ V_119 & 0xf ] ;
V_116 -> V_118 |=
V_116 -> V_110 [ 0 ] [ V_28 ] | V_116 -> V_110 [ 1 ] [ V_28 ] ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_120 * V_106 )
{
F_22 ( V_3 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_105 * V_106 )
{
F_22 ( V_3 , V_106 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_121 * V_106 )
{
if ( V_106 -> V_122 != V_123 )
return - V_42 ;
V_106 -> V_124 = V_125 ;
V_106 -> V_126 = V_127 ;
return F_20 ( V_3 , V_106 -> V_68 , V_106 -> V_69 ) ;
}
static int F_27 ( struct V_2 * V_3 , struct V_128 * V_129 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
static const char V_130 [] = {
0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0 , 0xa0
} ;
T_1 * V_26 = V_129 -> V_26 ;
T_2 V_32 ;
int V_131 , V_132 ;
V_129 -> type = 0 ;
V_131 = V_26 [ 2 ] ;
V_132 = V_26 [ 3 ] ;
if ( V_20 -> V_43 & V_44 )
V_131 ^= 0x40 ;
V_26 += 4 ;
V_129 -> V_26 = V_26 ;
V_129 -> V_133 = ( ( V_131 & 0x40 ) != 0 ) ;
V_129 -> line = ( V_131 & 0x3f ) << 3 ;
V_129 -> line |= ( V_132 & 0x70 ) >> 4 ;
V_132 &= 0xf ;
if ( ! memcmp ( V_26 , V_130 , sizeof( V_130 ) ) )
return 0 ;
switch ( V_132 ) {
case 1 :
V_129 -> type = V_111 ;
break;
case 4 :
if ( ! F_13 ( V_26 [ 0 ] ) || ! F_13 ( V_26 [ 1 ] ) )
return 0 ;
V_129 -> type = V_112 ;
break;
case 5 :
V_32 = F_15 ( V_26 ) ;
if ( V_32 == - 1 )
return 0 ;
V_26 [ 0 ] = V_32 & 0xff ;
V_26 [ 1 ] = V_32 >> 8 ;
V_129 -> type = V_113 ;
break;
case 7 :
if ( F_14 ( V_26 , V_26 ) != 0 )
return 0 ;
V_129 -> type = V_114 ;
break;
default:
break;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_134 * V_135 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
int V_136 ;
if ( V_20 -> V_137 )
return 0 ;
V_136 = F_11 ( V_3 , V_138 ) ;
F_10 ( 1 , V_23 , V_3 , L_8 , V_136 ) ;
V_135 -> signal = ( ( V_136 & ( 1 << 6 ) ) == 0 ) ? 0xffff : 0x0 ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , T_4 V_43 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
V_20 -> V_137 = 0 ;
F_21 ( V_3 , V_43 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
V_20 -> V_137 = 1 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
T_2 V_139 , T_2 V_140 , T_2 V_141 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_142 = ( V_20 -> V_22 <= V_14 ) ? 0xf8 : 0xf0 ;
F_10 ( 1 , V_23 , V_3 , L_9 ,
V_139 , V_140 ) ;
if ( V_20 -> V_22 <= V_15 &&
( V_139 == V_143 ||
V_139 == V_144 ) ) {
return - V_42 ;
}
if ( V_139 > V_145 )
return - V_42 ;
if ( V_20 -> V_139 == V_139 && V_20 -> V_140 == V_140 )
return 0 ;
F_10 ( 1 , V_23 , V_3 , L_10 ,
( V_139 >= V_146 ) ? L_11 : L_12 ,
( V_140 == V_147 ) ? L_13 : L_14 ) ;
V_20 -> V_139 = V_139 ;
if ( V_20 -> V_22 <= V_14 ) {
if ( V_139 >= V_143 )
V_139 -= 2 ;
F_4 ( V_3 , V_148 ,
( F_11 ( V_3 , V_148 ) & 0x3f ) |
( ( V_140 & 0xc0 ) ^ 0x40 ) ) ;
F_4 ( V_3 , V_149 ,
( F_11 ( V_3 , V_149 ) & 0xf0 ) |
( ( V_140 & 2 ) ? 0x0a : 0 ) ) ;
}
F_4 ( V_3 , V_150 ,
( F_11 ( V_3 , V_150 ) & V_142 ) |
V_139 ) ;
F_4 ( V_3 , V_151 ,
( F_11 ( V_3 , V_151 ) & 0x7f ) |
( V_20 -> V_139 >= V_146 ? 0x80 : 0x0 ) ) ;
V_20 -> V_140 = V_140 ;
if ( V_20 -> V_22 == V_16 ||
V_20 -> V_22 == V_17 ) {
F_4 ( V_3 , V_152 ,
( F_11 ( V_3 , V_152 ) & 0xfe ) |
( V_20 -> V_140 & 0x01 ) ) ;
}
if ( V_20 -> V_22 > V_14 ) {
if ( V_141 & V_153 )
F_4 ( V_3 , V_154 , 0x20 ) ;
else
F_4 ( V_3 , V_154 , 0x21 ) ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , T_2 V_57 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
if ( V_20 -> V_22 > V_14 )
return - V_42 ;
F_4 ( V_3 , 0x11 , ( F_11 ( V_3 , 0x11 ) & 0x7f ) |
( V_57 ? 0x80 : 0 ) ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , int V_155 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
F_10 ( 1 , V_23 , V_3 , L_15 ,
V_155 ? L_16 : L_17 ) ;
if ( V_20 -> V_155 == V_155 )
return 0 ;
V_20 -> V_155 = V_155 ;
if ( ! F_7 ( V_20 -> V_22 , V_156 ) )
return 0 ;
F_4 ( V_3 , V_156 , V_20 -> V_155 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , T_2 V_35 , T_2 V_157 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
if ( V_35 != V_158 && V_35 != V_159 )
return - V_42 ;
V_20 -> V_45 = V_35 ;
V_20 -> V_49 = V_157 & V_160 ;
V_20 -> V_47 = ( V_157 & V_161 ) ? 3 : 4 ;
V_20 -> V_46 = V_157 & V_162 ;
V_20 -> V_48 = V_157 & V_163 ;
F_16 ( V_3 , V_20 -> V_54 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , T_2 V_57 )
{
F_10 ( 1 , V_23 , V_3 , L_18 ) ;
F_9 ( V_3 , V_93 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_164 * V_21 )
{
switch ( V_21 -> V_12 ) {
case V_113 :
if ( F_11 ( V_3 , 0x6b ) & 0xc0 )
return - V_165 ;
V_21 -> V_21 [ 0 ] = F_11 ( V_3 , 0x6c ) ;
V_21 -> V_21 [ 1 ] = F_11 ( V_3 , 0x6d ) ;
return 0 ;
case V_112 :
if ( V_21 -> V_124 == 0 ) {
if ( F_11 ( V_3 , 0x66 ) & 0x30 )
return - V_165 ;
V_21 -> V_21 [ 0 ] = F_11 ( V_3 , 0x69 ) ;
V_21 -> V_21 [ 1 ] = F_11 ( V_3 , 0x6a ) ;
return 0 ;
}
if ( F_11 ( V_3 , 0x66 ) & 0xc0 )
return - V_165 ;
V_21 -> V_21 [ 0 ] = F_11 ( V_3 , 0x67 ) ;
V_21 -> V_21 [ 1 ] = F_11 ( V_3 , 0x68 ) ;
return 0 ;
default:
return - V_42 ;
}
}
static int F_37 ( struct V_2 * V_3 , T_4 * V_43 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
int V_166 , V_167 ;
V_166 = F_11 ( V_3 , V_138 ) ;
if ( V_20 -> V_22 == V_17 ) {
V_167 = F_11 ( V_3 , V_168 ) ;
F_10 ( 1 , V_23 , V_3 , L_19 , V_167 ) ;
switch ( V_167 & 0x03 ) {
case 1 :
* V_43 &= V_169 ;
break;
case 2 :
* V_43 &= V_170 | V_171 | V_99 |
V_98 | V_100 ;
break;
case 3 :
* V_43 &= V_102 ;
break;
default:
break;
}
}
F_10 ( 1 , V_23 , V_3 , L_20 , V_166 ) ;
if ( V_166 & 0x40 )
goto V_172;
if ( V_166 & 0x20 )
* V_43 &= V_44 ;
else
* V_43 &= V_75 ;
V_172:
F_10 ( 1 , V_23 , V_3 , L_21 , * V_43 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , T_2 * V_136 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
int V_167 = 0x80 ;
int V_166 ;
* V_136 = V_173 ;
if ( V_20 -> V_22 == V_17 )
V_167 = F_11 ( V_3 , V_168 ) ;
V_166 = F_11 ( V_3 , V_138 ) ;
if ( ( V_166 & 0xc1 ) == 0x81 && ( V_167 & 0xc0 ) == 0x80 )
* V_136 = 0 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_174 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
if ( ! F_40 ( V_11 , & V_8 -> V_175 ) )
return - V_42 ;
if ( ! F_41 ( V_176 ) )
return - V_177 ;
V_8 -> V_57 = F_11 ( V_3 , V_8 -> V_8 & 0xff ) ;
V_8 -> V_178 = 1 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , const struct V_174 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
if ( ! F_40 ( V_11 , & V_8 -> V_175 ) )
return - V_42 ;
if ( ! F_41 ( V_176 ) )
return - V_177 ;
F_4 ( V_3 , V_8 -> V_8 & 0xff , V_8 -> V_57 & 0xff ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_179 * V_180 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_44 ( V_11 , V_180 , V_20 -> V_22 , 0 ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
int V_167 , V_166 ;
int V_181 ;
int V_182 ;
F_46 ( V_3 , L_22 , V_20 -> V_54 ) ;
if ( V_20 -> V_22 != V_17 ) {
V_166 = F_11 ( V_3 , V_138 ) ;
V_181 = ( V_166 & 0xc1 ) == 0x81 ;
F_46 ( V_3 , L_23 , V_181 ? L_24 : L_25 ) ;
F_46 ( V_3 , L_26 , ( V_166 & 0x20 ) ? L_27 : L_28 ) ;
return 0 ;
}
V_167 = F_11 ( V_3 , V_168 ) ;
V_166 = F_11 ( V_3 , V_138 ) ;
V_181 = ( V_166 & 0xc1 ) == 0x81 && ( V_167 & 0xc0 ) == 0x80 ;
V_182 = ! ( V_166 & 0x10 ) ;
if ( V_20 -> V_139 >= 6 )
F_46 ( V_3 , L_29 , V_20 -> V_139 - 6 ) ;
else
F_46 ( V_3 , L_30 , V_20 -> V_139 ) ;
F_46 ( V_3 , L_23 , V_181 ? ( V_182 ? L_31 : L_32 ) : L_25 ) ;
F_46 ( V_3 , L_26 , ( V_166 & 0x20 ) ? L_27 : L_28 ) ;
switch ( V_167 & 0x03 ) {
case 1 :
F_46 ( V_3 , L_33 ) ;
break;
case 2 :
F_46 ( V_3 , L_34 ) ;
break;
case 3 :
F_46 ( V_3 , L_35 ) ;
break;
default:
F_46 ( V_3 , L_36 ) ;
break;
}
F_46 ( V_3 , L_37 , V_20 -> V_68 , V_20 -> V_69 ) ;
F_47 ( & V_20 -> V_7 , V_3 -> V_183 ) ;
return 0 ;
}
static int F_48 ( struct V_10 * V_11 ,
const struct V_184 * V_12 )
{
struct V_1 * V_20 ;
struct V_2 * V_3 ;
struct V_185 * V_7 ;
int V_28 ;
char V_183 [ 17 ] ;
char V_186 ;
int V_187 = ! V_12 || V_12 -> V_188 == 1 ;
if ( ! F_49 ( V_11 -> V_189 , V_190 ) )
return - V_165 ;
for ( V_28 = 0 ; V_28 < 0x0f ; V_28 ++ ) {
F_6 ( V_11 , 0 , V_28 ) ;
V_183 [ V_28 ] = ( F_12 ( V_11 , 0 ) & 0x0f ) + '0' ;
if ( V_183 [ V_28 ] > '9' )
V_183 [ V_28 ] += 'a' - '9' - 1 ;
}
V_183 [ V_28 ] = '\0' ;
V_186 = V_183 [ 5 ] ;
if ( memcmp ( V_183 + 1 , L_38 , 4 ) ) {
F_50 ( 1 , V_23 , V_11 , L_39 ,
V_11 -> V_191 << 1 , V_183 ) ;
return - V_192 ;
}
if ( ! V_187 && V_12 -> V_183 [ 6 ] != V_186 ) {
F_51 ( V_11 , L_40 ,
V_186 , V_12 -> V_183 ) ;
}
snprintf ( V_11 -> V_183 , sizeof( V_11 -> V_183 ) , L_41 , V_186 ) ;
F_52 ( V_11 , L_42 , V_186 , V_183 ,
V_11 -> V_191 << 1 , V_11 -> V_189 -> V_183 ) ;
V_20 = F_53 ( sizeof( struct V_1 ) , V_193 ) ;
if ( V_20 == NULL )
return - V_194 ;
V_3 = & V_20 -> V_3 ;
F_54 ( V_3 , V_11 , & V_195 ) ;
V_7 = & V_20 -> V_7 ;
F_55 ( V_7 , 6 ) ;
F_56 ( V_7 , & V_196 ,
V_60 , 0 , 255 , 1 , 128 ) ;
F_56 ( V_7 , & V_196 ,
V_62 , 0 , 127 , 1 , 64 ) ;
F_56 ( V_7 , & V_196 ,
V_64 , 0 , 127 , 1 , 64 ) ;
F_56 ( V_7 , & V_196 ,
V_66 , - 128 , 127 , 1 , 0 ) ;
V_20 -> V_56 = F_56 ( V_7 , & V_196 ,
V_55 , 0 , 1 , 1 , 1 ) ;
V_20 -> V_58 = F_56 ( V_7 , & V_196 ,
V_197 , 0 , 127 , 1 , 40 ) ;
V_3 -> V_198 = V_7 ;
if ( V_7 -> error ) {
int V_29 = V_7 -> error ;
F_57 ( V_7 ) ;
F_58 ( V_20 ) ;
return V_29 ;
}
F_59 ( 2 , & V_20 -> V_56 , 0 , true ) ;
V_20 -> V_139 = - 1 ;
V_20 -> V_140 = V_147 ;
V_20 -> V_155 = 1 ;
V_20 -> V_137 = 0 ;
switch ( V_186 ) {
case '1' :
V_20 -> V_22 = V_13 ;
if ( F_11 ( V_3 , V_199 ) & 0xf0 ) {
F_52 ( V_11 , L_43 ) ;
V_20 -> V_22 = V_14 ;
}
break;
case '3' :
V_20 -> V_22 = V_15 ;
break;
case '4' :
V_20 -> V_22 = V_16 ;
break;
case '5' :
V_20 -> V_22 = V_17 ;
break;
case '8' :
V_20 -> V_22 = V_18 ;
break;
default:
V_20 -> V_22 = V_13 ;
F_46 ( V_3 , L_44 ) ;
break;
}
V_20 -> V_54 = 48000 ;
F_10 ( 1 , V_23 , V_3 , L_45 ) ;
V_20 -> V_45 = V_159 ;
switch ( V_20 -> V_22 ) {
case V_13 :
case V_14 :
F_9 ( V_3 , V_200 ) ;
break;
case V_15 :
F_9 ( V_3 , V_201 ) ;
break;
default:
V_20 -> V_45 = V_158 ;
F_9 ( V_3 , V_202 ) ;
}
if ( V_20 -> V_22 > V_14 )
F_9 ( V_3 , V_203 ) ;
F_21 ( V_3 , V_169 ) ;
F_60 ( V_7 ) ;
F_10 ( 1 , V_23 , V_3 , L_46 ,
F_11 ( V_3 , V_168 ) ,
F_11 ( V_3 , V_138 ) ) ;
return 0 ;
}
static int F_61 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_62 ( V_11 ) ;
F_63 ( V_3 ) ;
F_57 ( V_3 -> V_198 ) ;
F_58 ( F_1 ( V_3 ) ) ;
return 0 ;
}
