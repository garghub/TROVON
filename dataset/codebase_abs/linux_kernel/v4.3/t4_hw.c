static int F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 ,
int V_4 , int V_5 , int V_6 , T_1 * V_7 )
{
while ( 1 ) {
T_1 V_8 = F_2 ( V_1 , V_2 ) ;
if ( ! ! ( V_8 & V_3 ) == V_4 ) {
if ( V_7 )
* V_7 = V_8 ;
return 0 ;
}
if ( -- V_5 == 0 )
return - V_9 ;
if ( V_6 )
F_3 ( V_6 ) ;
}
}
static inline int F_4 ( struct V_1 * V_1 , int V_2 , T_1 V_3 ,
int V_4 , int V_5 , int V_6 )
{
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , NULL ) ;
}
void F_5 ( struct V_1 * V_1 , unsigned int V_10 , T_1 V_3 ,
T_1 V_8 )
{
T_1 V_11 = F_2 ( V_1 , V_10 ) & ~ V_3 ;
F_6 ( V_1 , V_10 , V_11 | V_8 ) ;
( void ) F_2 ( V_1 , V_10 ) ;
}
void F_7 ( struct V_1 * V_12 , unsigned int V_13 ,
unsigned int V_14 , T_1 * V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
while ( V_16 -- ) {
F_6 ( V_12 , V_13 , V_17 ) ;
* V_15 ++ = F_2 ( V_12 , V_14 ) ;
V_17 ++ ;
}
}
void F_8 ( struct V_1 * V_12 , unsigned int V_13 ,
unsigned int V_14 , const T_1 * V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
while ( V_16 -- ) {
F_6 ( V_12 , V_13 , V_17 ++ ) ;
F_6 ( V_12 , V_14 , * V_15 ++ ) ;
}
}
void F_9 ( struct V_1 * V_12 , int V_2 , T_1 * V_8 )
{
T_1 V_18 = F_10 ( V_12 -> V_19 ) | F_11 ( V_2 ) ;
if ( F_12 ( V_12 -> V_20 . V_21 ) <= V_22 )
V_18 |= V_23 ;
else
V_18 |= V_24 ;
if ( F_13 ( V_12 -> V_20 . V_21 ) )
V_18 |= V_25 ;
F_6 ( V_12 , V_26 , V_18 ) ;
* V_8 = F_2 ( V_12 , V_27 ) ;
F_6 ( V_12 , V_26 , 0 ) ;
}
static void F_14 ( struct V_1 * V_12 )
{
static const char * const V_28 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
} ;
T_1 V_29 ;
V_29 = F_2 ( V_12 , V_30 ) ;
if ( V_29 & V_31 )
F_15 ( V_12 -> V_32 , L_9 ,
V_28 [ F_16 ( V_29 ) ] ) ;
}
static void F_17 ( struct V_1 * V_12 , T_2 * V_33 , int V_34 ,
T_1 V_35 )
{
for ( ; V_34 ; V_34 -- , V_35 += 8 )
* V_33 ++ = F_18 ( F_19 ( V_12 , V_35 ) ) ;
}
static void F_20 ( struct V_1 * V_12 , T_1 V_35 )
{
struct V_36 V_37 ;
F_17 ( V_12 , ( T_2 * ) & V_37 , sizeof( V_37 ) / 8 , V_35 ) ;
F_21 ( V_12 -> V_32 ,
L_10 ,
V_37 . V_38 . assert . V_39 , F_22 ( V_37 . V_38 . assert . line ) ,
F_22 ( V_37 . V_38 . assert . V_40 ) , F_22 ( V_37 . V_38 . assert . V_41 ) ) ;
}
static void F_23 ( struct V_1 * V_12 , int V_42 , T_1 V_14 )
{
F_15 ( V_12 -> V_32 ,
L_11 , V_42 ,
( unsigned long long ) F_19 ( V_12 , V_14 ) ,
( unsigned long long ) F_19 ( V_12 , V_14 + 8 ) ,
( unsigned long long ) F_19 ( V_12 , V_14 + 16 ) ,
( unsigned long long ) F_19 ( V_12 , V_14 + 24 ) ,
( unsigned long long ) F_19 ( V_12 , V_14 + 32 ) ,
( unsigned long long ) F_19 ( V_12 , V_14 + 40 ) ,
( unsigned long long ) F_19 ( V_12 , V_14 + 48 ) ,
( unsigned long long ) F_19 ( V_12 , V_14 + 56 ) ) ;
}
int F_24 ( struct V_1 * V_12 , int V_42 , const void * V_43 ,
int V_44 , void * V_33 , bool V_45 , int V_46 )
{
static const int V_6 [] = {
1 , 1 , 3 , 5 , 10 , 10 , 20 , 50 , 100 , 200
} ;
T_1 V_11 ;
T_3 V_47 ;
int V_48 , V_49 , V_50 ;
const T_2 * V_51 = V_43 ;
T_1 V_14 = F_25 ( V_42 , V_52 ) ;
T_1 V_53 = F_25 ( V_42 , V_54 ) ;
if ( ( V_44 & 15 ) || V_44 > V_55 )
return - V_56 ;
if ( V_12 -> V_57 -> V_58 != V_59 )
return - V_60 ;
V_11 = F_26 ( F_2 ( V_12 , V_53 ) ) ;
for ( V_48 = 0 ; V_11 == V_61 && V_48 < 3 ; V_48 ++ )
V_11 = F_26 ( F_2 ( V_12 , V_53 ) ) ;
if ( V_11 != V_62 )
return V_11 ? - V_63 : - V_64 ;
for ( V_48 = 0 ; V_48 < V_44 ; V_48 += 8 )
F_27 ( V_12 , V_14 + V_48 , F_28 ( * V_51 ++ ) ) ;
F_6 ( V_12 , V_53 , V_65 | F_29 ( V_66 ) ) ;
F_2 ( V_12 , V_53 ) ;
V_50 = 0 ;
V_49 = V_6 [ 0 ] ;
for ( V_48 = 0 ; V_48 < V_46 ; V_48 += V_49 ) {
if ( V_45 ) {
V_49 = V_6 [ V_50 ] ;
if ( V_50 < F_30 ( V_6 ) - 1 )
V_50 ++ ;
F_31 ( V_49 ) ;
} else
F_32 ( V_49 ) ;
V_11 = F_2 ( V_12 , V_53 ) ;
if ( F_26 ( V_11 ) == V_62 ) {
if ( ! ( V_11 & V_65 ) ) {
F_6 ( V_12 , V_53 , 0 ) ;
continue;
}
V_47 = F_19 ( V_12 , V_14 ) ;
if ( F_33 ( V_47 >> 32 ) == V_67 ) {
F_20 ( V_12 , V_14 ) ;
V_47 = F_34 ( V_60 ) ;
} else if ( V_33 ) {
F_17 ( V_12 , V_33 , V_44 / 8 , V_14 ) ;
}
if ( F_35 ( ( int ) V_47 ) )
F_23 ( V_12 , V_42 , V_14 ) ;
F_6 ( V_12 , V_53 , 0 ) ;
return - F_35 ( ( int ) V_47 ) ;
}
}
F_23 ( V_12 , V_42 , V_14 ) ;
F_15 ( V_12 -> V_32 , L_12 ,
* ( const V_68 * ) V_43 , V_42 ) ;
F_14 ( V_12 ) ;
return - V_64 ;
}
int F_36 ( struct V_1 * V_12 , int V_42 , const void * V_43 , int V_44 ,
void * V_33 , bool V_45 )
{
return F_24 ( V_12 , V_42 , V_43 , V_44 , V_33 , V_45 ,
V_69 ) ;
}
static int F_37 ( struct V_1 * V_12 , int V_70 )
{
T_1 V_71 ;
T_1 V_72 ;
if ( F_13 ( V_12 -> V_20 . V_21 ) ) {
F_38 ( V_12 , L_13 , V_73 ) ;
return 0 ;
}
if ( V_70 != 0 && V_70 != 1 ) {
F_38 ( V_12 , L_14 , V_73 , V_70 ) ;
return 0 ;
}
V_71 = F_39 ( V_74 , V_70 ) ;
V_72 = F_39 ( V_75 , V_70 ) ;
F_38 ( V_12 ,
L_15 ,
V_70 , V_71 ,
F_2 ( V_12 , V_71 ) ) ;
F_38 ( V_12 ,
L_16 ,
V_72 ,
( unsigned long long ) F_19 ( V_12 , V_72 ) ,
( unsigned long long ) F_19 ( V_12 , V_72 + 8 ) ,
( unsigned long long ) F_19 ( V_12 , V_72 + 16 ) ,
( unsigned long long ) F_19 ( V_12 , V_72 + 24 ) ,
( unsigned long long ) F_19 ( V_12 , V_72 + 32 ) ,
( unsigned long long ) F_19 ( V_12 , V_72 + 40 ) ,
( unsigned long long ) F_19 ( V_12 , V_72 + 48 ) ,
( unsigned long long ) F_19 ( V_12 , V_72 + 56 ) ,
( unsigned long long ) F_19 ( V_12 , V_72 + 64 ) ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_12 , int V_76 , int V_77 , T_1 V_10 ,
T_1 V_78 , void * V_79 , int V_80 )
{
T_1 V_81 , V_82 , V_83 , V_84 ;
T_1 V_85 , V_86 , V_87 , V_88 , V_89 , V_90 ;
T_1 * V_91 ;
if ( V_10 & 0x3 || ( V_92 ) V_79 & 0x3 )
return - V_56 ;
V_91 = ( T_1 * ) V_79 ;
V_83 = V_78 & 0x3 ;
V_78 -= V_83 ;
V_85 = F_41 ( F_2 ( V_12 , V_93 ) ) ;
if ( V_77 != V_94 )
V_84 = ( V_77 * ( V_85 * 1024 * 1024 ) ) ;
else {
V_86 = F_42 ( F_2 ( V_12 ,
V_95 ) ) ;
V_84 = ( V_96 * V_85 + V_86 ) * 1024 * 1024 ;
}
V_10 = V_10 + V_84 ;
V_88 = F_2 ( V_12 ,
F_43 ( V_97 ,
V_76 ) ) ;
V_89 = 1 << ( F_44 ( V_88 ) + V_98 ) ;
V_90 = F_45 ( V_88 ) << V_99 ;
if ( F_13 ( V_12 -> V_20 . V_21 ) )
V_90 -= V_12 -> V_100 ;
V_87 = F_13 ( V_12 -> V_20 . V_21 ) ? 0 : F_46 ( V_12 -> V_19 ) ;
V_81 = V_10 & ~ ( V_89 - 1 ) ;
V_82 = V_10 - V_81 ;
F_6 ( V_12 ,
F_43 ( V_101 , V_76 ) ,
V_81 | V_87 ) ;
F_2 ( V_12 ,
F_43 ( V_101 , V_76 ) ) ;
while ( V_78 > 0 ) {
if ( V_80 == V_102 )
* V_91 ++ = F_47 ( ( V_103 V_104 ) F_2 ( V_12 ,
V_90 + V_82 ) ) ;
else
F_6 ( V_12 , V_90 + V_82 ,
( V_103 T_1 ) F_48 ( * V_91 ++ ) ) ;
V_82 += sizeof( V_105 ) ;
V_78 -= sizeof( V_105 ) ;
if ( V_82 == V_89 ) {
V_81 += V_89 ;
V_82 = 0 ;
F_6 ( V_12 ,
F_43 ( V_101 ,
V_76 ) , V_81 | V_87 ) ;
F_2 ( V_12 ,
F_43 ( V_101 ,
V_76 ) ) ;
}
}
if ( V_83 ) {
union {
T_1 V_106 ;
char V_107 [ 4 ] ;
} V_108 ;
unsigned char * V_109 ;
int V_48 ;
if ( V_80 == V_102 ) {
V_108 . V_106 = F_47 (
( V_103 V_104 ) F_2 ( V_12 ,
V_90 + V_82 ) ) ;
for ( V_109 = ( unsigned char * ) V_91 , V_48 = V_83 ; V_48 < 4 ; V_48 ++ )
V_109 [ V_48 ] = V_108 . V_107 [ V_48 ] ;
} else {
V_108 . V_106 = * V_91 ;
for ( V_48 = V_83 ; V_48 < 4 ; V_48 ++ )
V_108 . V_107 [ V_48 ] = 0 ;
F_6 ( V_12 , V_90 + V_82 ,
( V_103 T_1 ) F_48 ( V_108 . V_106 ) ) ;
}
}
return 0 ;
}
T_1 F_49 ( struct V_1 * V_12 , int V_2 )
{
T_1 V_8 , V_110 ;
struct V_111 V_112 ;
int V_113 ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
V_110 = F_50 ( V_114 ) ;
V_112 . V_115 = F_51 ( F_52 ( V_116 ) |
V_117 |
V_118 |
V_110 ) ;
V_112 . V_119 = F_51 ( F_53 ( V_112 ) ) ;
V_112 . V_38 . V_120 . V_121 = F_54 ( 1 ) ;
V_112 . V_38 . V_120 . V_122 =
( V_123 | F_55 ( V_12 -> V_19 ) ) ;
V_112 . V_38 . V_120 . V_124 = V_2 ;
V_113 = F_56 ( V_12 , V_12 -> V_42 , & V_112 , sizeof( V_112 ) ,
& V_112 ) ;
if ( V_113 == 0 )
V_8 = F_22 ( V_112 . V_38 . V_120 . V_125 [ 0 ] ) ;
else
F_9 ( V_12 , V_2 , & V_8 ) ;
return V_8 ;
}
static T_1 F_57 ( struct V_1 * V_12 , T_1 V_126 , T_3 V_127 ,
T_1 V_128 )
{
T_1 V_113 ;
if ( F_13 ( V_12 -> V_20 . V_21 ) ) {
T_1 V_129 ;
V_129 = F_49 ( V_12 , V_126 ) ;
V_129 &= V_127 ;
V_12 -> V_100 = V_129 ;
V_113 = V_129 + V_128 ;
} else {
V_113 = V_128 ;
}
return V_113 ;
}
T_1 F_58 ( struct V_1 * V_12 )
{
return F_57 ( V_12 , V_130 ,
V_131 , V_132 ) ;
}
void F_59 ( struct V_1 * V_12 , T_1 V_128 , T_1 V_133 )
{
F_6 ( V_12 ,
F_43 ( V_97 , V_133 ) ,
V_128 | F_60 ( 0 ) |
F_61 ( F_62 ( V_134 ) - V_98 ) ) ;
F_2 ( V_12 ,
F_43 ( V_97 , V_133 ) ) ;
}
unsigned int F_63 ( struct V_1 * V_1 )
{
unsigned int V_135 = F_12 ( V_1 -> V_20 . V_21 ) ;
switch ( V_135 ) {
case V_136 :
return V_137 ;
case V_22 :
case V_138 :
return V_139 ;
}
F_15 ( V_1 -> V_32 ,
L_17 , V_135 ) ;
return 0 ;
}
void F_64 ( struct V_1 * V_12 , void * V_91 , T_4 V_140 )
{
static const unsigned int V_141 [] = {
0x1008 , 0x1108 ,
0x1180 , 0x11b4 ,
0x11fc , 0x123c ,
0x1300 , 0x173c ,
0x1800 , 0x18fc ,
0x3000 , 0x305c ,
0x3068 , 0x30d8 ,
0x30e0 , 0x5924 ,
0x5960 , 0x59d4 ,
0x5a00 , 0x5af8 ,
0x6000 , 0x6098 ,
0x6100 , 0x6150 ,
0x6200 , 0x6208 ,
0x6240 , 0x6248 ,
0x6280 , 0x6338 ,
0x6370 , 0x638c ,
0x6400 , 0x643c ,
0x6500 , 0x6524 ,
0x6a00 , 0x6a38 ,
0x6a60 , 0x6a78 ,
0x6b00 , 0x6b84 ,
0x6bf0 , 0x6c84 ,
0x6cf0 , 0x6d84 ,
0x6df0 , 0x6e84 ,
0x6ef0 , 0x6f84 ,
0x6ff0 , 0x7084 ,
0x70f0 , 0x7184 ,
0x71f0 , 0x7284 ,
0x72f0 , 0x7384 ,
0x73f0 , 0x7450 ,
0x7500 , 0x7530 ,
0x7600 , 0x761c ,
0x7680 , 0x76cc ,
0x7700 , 0x7798 ,
0x77c0 , 0x77fc ,
0x7900 , 0x79fc ,
0x7b00 , 0x7c38 ,
0x7d00 , 0x7efc ,
0x8dc0 , 0x8e1c ,
0x8e30 , 0x8e78 ,
0x8ea0 , 0x8f6c ,
0x8fc0 , 0x9074 ,
0x90fc , 0x90fc ,
0x9400 , 0x9458 ,
0x9600 , 0x96bc ,
0x9800 , 0x9808 ,
0x9820 , 0x983c ,
0x9850 , 0x9864 ,
0x9c00 , 0x9c6c ,
0x9c80 , 0x9cec ,
0x9d00 , 0x9d6c ,
0x9d80 , 0x9dec ,
0x9e00 , 0x9e6c ,
0x9e80 , 0x9eec ,
0x9f00 , 0x9f6c ,
0x9f80 , 0x9fec ,
0xd004 , 0xd03c ,
0xdfc0 , 0xdfe0 ,
0xe000 , 0xea7c ,
0xf000 , 0x11110 ,
0x11118 , 0x11190 ,
0x19040 , 0x1906c ,
0x19078 , 0x19080 ,
0x1908c , 0x19124 ,
0x19150 , 0x191b0 ,
0x191d0 , 0x191e8 ,
0x19238 , 0x1924c ,
0x193f8 , 0x19474 ,
0x19490 , 0x194f8 ,
0x19800 , 0x19f4c ,
0x1a000 , 0x1a06c ,
0x1a0b0 , 0x1a120 ,
0x1a128 , 0x1a138 ,
0x1a190 , 0x1a1c4 ,
0x1a1fc , 0x1a1fc ,
0x1e040 , 0x1e04c ,
0x1e284 , 0x1e28c ,
0x1e2c0 , 0x1e2c0 ,
0x1e2e0 , 0x1e2e0 ,
0x1e300 , 0x1e384 ,
0x1e3c0 , 0x1e3c8 ,
0x1e440 , 0x1e44c ,
0x1e684 , 0x1e68c ,
0x1e6c0 , 0x1e6c0 ,
0x1e6e0 , 0x1e6e0 ,
0x1e700 , 0x1e784 ,
0x1e7c0 , 0x1e7c8 ,
0x1e840 , 0x1e84c ,
0x1ea84 , 0x1ea8c ,
0x1eac0 , 0x1eac0 ,
0x1eae0 , 0x1eae0 ,
0x1eb00 , 0x1eb84 ,
0x1ebc0 , 0x1ebc8 ,
0x1ec40 , 0x1ec4c ,
0x1ee84 , 0x1ee8c ,
0x1eec0 , 0x1eec0 ,
0x1eee0 , 0x1eee0 ,
0x1ef00 , 0x1ef84 ,
0x1efc0 , 0x1efc8 ,
0x1f040 , 0x1f04c ,
0x1f284 , 0x1f28c ,
0x1f2c0 , 0x1f2c0 ,
0x1f2e0 , 0x1f2e0 ,
0x1f300 , 0x1f384 ,
0x1f3c0 , 0x1f3c8 ,
0x1f440 , 0x1f44c ,
0x1f684 , 0x1f68c ,
0x1f6c0 , 0x1f6c0 ,
0x1f6e0 , 0x1f6e0 ,
0x1f700 , 0x1f784 ,
0x1f7c0 , 0x1f7c8 ,
0x1f840 , 0x1f84c ,
0x1fa84 , 0x1fa8c ,
0x1fac0 , 0x1fac0 ,
0x1fae0 , 0x1fae0 ,
0x1fb00 , 0x1fb84 ,
0x1fbc0 , 0x1fbc8 ,
0x1fc40 , 0x1fc4c ,
0x1fe84 , 0x1fe8c ,
0x1fec0 , 0x1fec0 ,
0x1fee0 , 0x1fee0 ,
0x1ff00 , 0x1ff84 ,
0x1ffc0 , 0x1ffc8 ,
0x20000 , 0x2002c ,
0x20100 , 0x2013c ,
0x20190 , 0x201c8 ,
0x20200 , 0x20318 ,
0x20400 , 0x20528 ,
0x20540 , 0x20614 ,
0x21000 , 0x21040 ,
0x2104c , 0x21060 ,
0x210c0 , 0x210ec ,
0x21200 , 0x21268 ,
0x21270 , 0x21284 ,
0x212fc , 0x21388 ,
0x21400 , 0x21404 ,
0x21500 , 0x21518 ,
0x2152c , 0x2153c ,
0x21550 , 0x21554 ,
0x21600 , 0x21600 ,
0x21608 , 0x21628 ,
0x21630 , 0x2163c ,
0x21700 , 0x2171c ,
0x21780 , 0x2178c ,
0x21800 , 0x21c38 ,
0x21c80 , 0x21d7c ,
0x21e00 , 0x21e04 ,
0x22000 , 0x2202c ,
0x22100 , 0x2213c ,
0x22190 , 0x221c8 ,
0x22200 , 0x22318 ,
0x22400 , 0x22528 ,
0x22540 , 0x22614 ,
0x23000 , 0x23040 ,
0x2304c , 0x23060 ,
0x230c0 , 0x230ec ,
0x23200 , 0x23268 ,
0x23270 , 0x23284 ,
0x232fc , 0x23388 ,
0x23400 , 0x23404 ,
0x23500 , 0x23518 ,
0x2352c , 0x2353c ,
0x23550 , 0x23554 ,
0x23600 , 0x23600 ,
0x23608 , 0x23628 ,
0x23630 , 0x2363c ,
0x23700 , 0x2371c ,
0x23780 , 0x2378c ,
0x23800 , 0x23c38 ,
0x23c80 , 0x23d7c ,
0x23e00 , 0x23e04 ,
0x24000 , 0x2402c ,
0x24100 , 0x2413c ,
0x24190 , 0x241c8 ,
0x24200 , 0x24318 ,
0x24400 , 0x24528 ,
0x24540 , 0x24614 ,
0x25000 , 0x25040 ,
0x2504c , 0x25060 ,
0x250c0 , 0x250ec ,
0x25200 , 0x25268 ,
0x25270 , 0x25284 ,
0x252fc , 0x25388 ,
0x25400 , 0x25404 ,
0x25500 , 0x25518 ,
0x2552c , 0x2553c ,
0x25550 , 0x25554 ,
0x25600 , 0x25600 ,
0x25608 , 0x25628 ,
0x25630 , 0x2563c ,
0x25700 , 0x2571c ,
0x25780 , 0x2578c ,
0x25800 , 0x25c38 ,
0x25c80 , 0x25d7c ,
0x25e00 , 0x25e04 ,
0x26000 , 0x2602c ,
0x26100 , 0x2613c ,
0x26190 , 0x261c8 ,
0x26200 , 0x26318 ,
0x26400 , 0x26528 ,
0x26540 , 0x26614 ,
0x27000 , 0x27040 ,
0x2704c , 0x27060 ,
0x270c0 , 0x270ec ,
0x27200 , 0x27268 ,
0x27270 , 0x27284 ,
0x272fc , 0x27388 ,
0x27400 , 0x27404 ,
0x27500 , 0x27518 ,
0x2752c , 0x2753c ,
0x27550 , 0x27554 ,
0x27600 , 0x27600 ,
0x27608 , 0x27628 ,
0x27630 , 0x2763c ,
0x27700 , 0x2771c ,
0x27780 , 0x2778c ,
0x27800 , 0x27c38 ,
0x27c80 , 0x27d7c ,
0x27e00 , 0x27e04 ,
} ;
static const unsigned int V_142 [] = {
0x1008 , 0x1148 ,
0x1180 , 0x11b4 ,
0x11fc , 0x123c ,
0x1280 , 0x173c ,
0x1800 , 0x18fc ,
0x3000 , 0x3028 ,
0x3068 , 0x30d8 ,
0x30e0 , 0x30fc ,
0x3140 , 0x357c ,
0x35a8 , 0x35cc ,
0x35ec , 0x35ec ,
0x3600 , 0x5624 ,
0x56cc , 0x575c ,
0x580c , 0x5814 ,
0x5890 , 0x58bc ,
0x5940 , 0x59dc ,
0x59fc , 0x5a18 ,
0x5a60 , 0x5a9c ,
0x5b94 , 0x5bfc ,
0x6000 , 0x6040 ,
0x6058 , 0x614c ,
0x7700 , 0x7798 ,
0x77c0 , 0x78fc ,
0x7b00 , 0x7c54 ,
0x7d00 , 0x7efc ,
0x8dc0 , 0x8de0 ,
0x8df8 , 0x8e84 ,
0x8ea0 , 0x8f84 ,
0x8fc0 , 0x90f8 ,
0x9400 , 0x9470 ,
0x9600 , 0x96f4 ,
0x9800 , 0x9808 ,
0x9820 , 0x983c ,
0x9850 , 0x9864 ,
0x9c00 , 0x9c6c ,
0x9c80 , 0x9cec ,
0x9d00 , 0x9d6c ,
0x9d80 , 0x9dec ,
0x9e00 , 0x9e6c ,
0x9e80 , 0x9eec ,
0x9f00 , 0x9f6c ,
0x9f80 , 0xa020 ,
0xd004 , 0xd03c ,
0xdfc0 , 0xdfe0 ,
0xe000 , 0x11088 ,
0x1109c , 0x11110 ,
0x11118 , 0x1117c ,
0x11190 , 0x11204 ,
0x19040 , 0x1906c ,
0x19078 , 0x19080 ,
0x1908c , 0x19124 ,
0x19150 , 0x191b0 ,
0x191d0 , 0x191e8 ,
0x19238 , 0x19290 ,
0x193f8 , 0x19474 ,
0x19490 , 0x194cc ,
0x194f0 , 0x194f8 ,
0x19c00 , 0x19c60 ,
0x19c94 , 0x19e10 ,
0x19e50 , 0x19f34 ,
0x19f40 , 0x19f50 ,
0x19f90 , 0x19fe4 ,
0x1a000 , 0x1a06c ,
0x1a0b0 , 0x1a120 ,
0x1a128 , 0x1a138 ,
0x1a190 , 0x1a1c4 ,
0x1a1fc , 0x1a1fc ,
0x1e008 , 0x1e00c ,
0x1e040 , 0x1e04c ,
0x1e284 , 0x1e290 ,
0x1e2c0 , 0x1e2c0 ,
0x1e2e0 , 0x1e2e0 ,
0x1e300 , 0x1e384 ,
0x1e3c0 , 0x1e3c8 ,
0x1e408 , 0x1e40c ,
0x1e440 , 0x1e44c ,
0x1e684 , 0x1e690 ,
0x1e6c0 , 0x1e6c0 ,
0x1e6e0 , 0x1e6e0 ,
0x1e700 , 0x1e784 ,
0x1e7c0 , 0x1e7c8 ,
0x1e808 , 0x1e80c ,
0x1e840 , 0x1e84c ,
0x1ea84 , 0x1ea90 ,
0x1eac0 , 0x1eac0 ,
0x1eae0 , 0x1eae0 ,
0x1eb00 , 0x1eb84 ,
0x1ebc0 , 0x1ebc8 ,
0x1ec08 , 0x1ec0c ,
0x1ec40 , 0x1ec4c ,
0x1ee84 , 0x1ee90 ,
0x1eec0 , 0x1eec0 ,
0x1eee0 , 0x1eee0 ,
0x1ef00 , 0x1ef84 ,
0x1efc0 , 0x1efc8 ,
0x1f008 , 0x1f00c ,
0x1f040 , 0x1f04c ,
0x1f284 , 0x1f290 ,
0x1f2c0 , 0x1f2c0 ,
0x1f2e0 , 0x1f2e0 ,
0x1f300 , 0x1f384 ,
0x1f3c0 , 0x1f3c8 ,
0x1f408 , 0x1f40c ,
0x1f440 , 0x1f44c ,
0x1f684 , 0x1f690 ,
0x1f6c0 , 0x1f6c0 ,
0x1f6e0 , 0x1f6e0 ,
0x1f700 , 0x1f784 ,
0x1f7c0 , 0x1f7c8 ,
0x1f808 , 0x1f80c ,
0x1f840 , 0x1f84c ,
0x1fa84 , 0x1fa90 ,
0x1fac0 , 0x1fac0 ,
0x1fae0 , 0x1fae0 ,
0x1fb00 , 0x1fb84 ,
0x1fbc0 , 0x1fbc8 ,
0x1fc08 , 0x1fc0c ,
0x1fc40 , 0x1fc4c ,
0x1fe84 , 0x1fe90 ,
0x1fec0 , 0x1fec0 ,
0x1fee0 , 0x1fee0 ,
0x1ff00 , 0x1ff84 ,
0x1ffc0 , 0x1ffc8 ,
0x30000 , 0x30030 ,
0x30100 , 0x30144 ,
0x30190 , 0x301d0 ,
0x30200 , 0x30318 ,
0x30400 , 0x3052c ,
0x30540 , 0x3061c ,
0x30800 , 0x30834 ,
0x308c0 , 0x30908 ,
0x30910 , 0x309ac ,
0x30a00 , 0x30a2c ,
0x30a44 , 0x30a50 ,
0x30a74 , 0x30c24 ,
0x30d00 , 0x30d00 ,
0x30d08 , 0x30d14 ,
0x30d1c , 0x30d20 ,
0x30d3c , 0x30d50 ,
0x31200 , 0x3120c ,
0x31220 , 0x31220 ,
0x31240 , 0x31240 ,
0x31600 , 0x3160c ,
0x31a00 , 0x31a1c ,
0x31e00 , 0x31e20 ,
0x31e38 , 0x31e3c ,
0x31e80 , 0x31e80 ,
0x31e88 , 0x31ea8 ,
0x31eb0 , 0x31eb4 ,
0x31ec8 , 0x31ed4 ,
0x31fb8 , 0x32004 ,
0x32200 , 0x32200 ,
0x32208 , 0x32240 ,
0x32248 , 0x32280 ,
0x32288 , 0x322c0 ,
0x322c8 , 0x322fc ,
0x32600 , 0x32630 ,
0x32a00 , 0x32abc ,
0x32b00 , 0x32b70 ,
0x33000 , 0x33048 ,
0x33060 , 0x3309c ,
0x330f0 , 0x33148 ,
0x33160 , 0x3319c ,
0x331f0 , 0x332e4 ,
0x332f8 , 0x333e4 ,
0x333f8 , 0x33448 ,
0x33460 , 0x3349c ,
0x334f0 , 0x33548 ,
0x33560 , 0x3359c ,
0x335f0 , 0x336e4 ,
0x336f8 , 0x337e4 ,
0x337f8 , 0x337fc ,
0x33814 , 0x33814 ,
0x3382c , 0x3382c ,
0x33880 , 0x3388c ,
0x338e8 , 0x338ec ,
0x33900 , 0x33948 ,
0x33960 , 0x3399c ,
0x339f0 , 0x33ae4 ,
0x33af8 , 0x33b10 ,
0x33b28 , 0x33b28 ,
0x33b3c , 0x33b50 ,
0x33bf0 , 0x33c10 ,
0x33c28 , 0x33c28 ,
0x33c3c , 0x33c50 ,
0x33cf0 , 0x33cfc ,
0x34000 , 0x34030 ,
0x34100 , 0x34144 ,
0x34190 , 0x341d0 ,
0x34200 , 0x34318 ,
0x34400 , 0x3452c ,
0x34540 , 0x3461c ,
0x34800 , 0x34834 ,
0x348c0 , 0x34908 ,
0x34910 , 0x349ac ,
0x34a00 , 0x34a2c ,
0x34a44 , 0x34a50 ,
0x34a74 , 0x34c24 ,
0x34d00 , 0x34d00 ,
0x34d08 , 0x34d14 ,
0x34d1c , 0x34d20 ,
0x34d3c , 0x34d50 ,
0x35200 , 0x3520c ,
0x35220 , 0x35220 ,
0x35240 , 0x35240 ,
0x35600 , 0x3560c ,
0x35a00 , 0x35a1c ,
0x35e00 , 0x35e20 ,
0x35e38 , 0x35e3c ,
0x35e80 , 0x35e80 ,
0x35e88 , 0x35ea8 ,
0x35eb0 , 0x35eb4 ,
0x35ec8 , 0x35ed4 ,
0x35fb8 , 0x36004 ,
0x36200 , 0x36200 ,
0x36208 , 0x36240 ,
0x36248 , 0x36280 ,
0x36288 , 0x362c0 ,
0x362c8 , 0x362fc ,
0x36600 , 0x36630 ,
0x36a00 , 0x36abc ,
0x36b00 , 0x36b70 ,
0x37000 , 0x37048 ,
0x37060 , 0x3709c ,
0x370f0 , 0x37148 ,
0x37160 , 0x3719c ,
0x371f0 , 0x372e4 ,
0x372f8 , 0x373e4 ,
0x373f8 , 0x37448 ,
0x37460 , 0x3749c ,
0x374f0 , 0x37548 ,
0x37560 , 0x3759c ,
0x375f0 , 0x376e4 ,
0x376f8 , 0x377e4 ,
0x377f8 , 0x377fc ,
0x37814 , 0x37814 ,
0x3782c , 0x3782c ,
0x37880 , 0x3788c ,
0x378e8 , 0x378ec ,
0x37900 , 0x37948 ,
0x37960 , 0x3799c ,
0x379f0 , 0x37ae4 ,
0x37af8 , 0x37b10 ,
0x37b28 , 0x37b28 ,
0x37b3c , 0x37b50 ,
0x37bf0 , 0x37c10 ,
0x37c28 , 0x37c28 ,
0x37c3c , 0x37c50 ,
0x37cf0 , 0x37cfc ,
0x38000 , 0x38030 ,
0x38100 , 0x38144 ,
0x38190 , 0x381d0 ,
0x38200 , 0x38318 ,
0x38400 , 0x3852c ,
0x38540 , 0x3861c ,
0x38800 , 0x38834 ,
0x388c0 , 0x38908 ,
0x38910 , 0x389ac ,
0x38a00 , 0x38a2c ,
0x38a44 , 0x38a50 ,
0x38a74 , 0x38c24 ,
0x38d00 , 0x38d00 ,
0x38d08 , 0x38d14 ,
0x38d1c , 0x38d20 ,
0x38d3c , 0x38d50 ,
0x39200 , 0x3920c ,
0x39220 , 0x39220 ,
0x39240 , 0x39240 ,
0x39600 , 0x3960c ,
0x39a00 , 0x39a1c ,
0x39e00 , 0x39e20 ,
0x39e38 , 0x39e3c ,
0x39e80 , 0x39e80 ,
0x39e88 , 0x39ea8 ,
0x39eb0 , 0x39eb4 ,
0x39ec8 , 0x39ed4 ,
0x39fb8 , 0x3a004 ,
0x3a200 , 0x3a200 ,
0x3a208 , 0x3a240 ,
0x3a248 , 0x3a280 ,
0x3a288 , 0x3a2c0 ,
0x3a2c8 , 0x3a2fc ,
0x3a600 , 0x3a630 ,
0x3aa00 , 0x3aabc ,
0x3ab00 , 0x3ab70 ,
0x3b000 , 0x3b048 ,
0x3b060 , 0x3b09c ,
0x3b0f0 , 0x3b148 ,
0x3b160 , 0x3b19c ,
0x3b1f0 , 0x3b2e4 ,
0x3b2f8 , 0x3b3e4 ,
0x3b3f8 , 0x3b448 ,
0x3b460 , 0x3b49c ,
0x3b4f0 , 0x3b548 ,
0x3b560 , 0x3b59c ,
0x3b5f0 , 0x3b6e4 ,
0x3b6f8 , 0x3b7e4 ,
0x3b7f8 , 0x3b7fc ,
0x3b814 , 0x3b814 ,
0x3b82c , 0x3b82c ,
0x3b880 , 0x3b88c ,
0x3b8e8 , 0x3b8ec ,
0x3b900 , 0x3b948 ,
0x3b960 , 0x3b99c ,
0x3b9f0 , 0x3bae4 ,
0x3baf8 , 0x3bb10 ,
0x3bb28 , 0x3bb28 ,
0x3bb3c , 0x3bb50 ,
0x3bbf0 , 0x3bc10 ,
0x3bc28 , 0x3bc28 ,
0x3bc3c , 0x3bc50 ,
0x3bcf0 , 0x3bcfc ,
0x3c000 , 0x3c030 ,
0x3c100 , 0x3c144 ,
0x3c190 , 0x3c1d0 ,
0x3c200 , 0x3c318 ,
0x3c400 , 0x3c52c ,
0x3c540 , 0x3c61c ,
0x3c800 , 0x3c834 ,
0x3c8c0 , 0x3c908 ,
0x3c910 , 0x3c9ac ,
0x3ca00 , 0x3ca2c ,
0x3ca44 , 0x3ca50 ,
0x3ca74 , 0x3cc24 ,
0x3cd00 , 0x3cd00 ,
0x3cd08 , 0x3cd14 ,
0x3cd1c , 0x3cd20 ,
0x3cd3c , 0x3cd50 ,
0x3d200 , 0x3d20c ,
0x3d220 , 0x3d220 ,
0x3d240 , 0x3d240 ,
0x3d600 , 0x3d60c ,
0x3da00 , 0x3da1c ,
0x3de00 , 0x3de20 ,
0x3de38 , 0x3de3c ,
0x3de80 , 0x3de80 ,
0x3de88 , 0x3dea8 ,
0x3deb0 , 0x3deb4 ,
0x3dec8 , 0x3ded4 ,
0x3dfb8 , 0x3e004 ,
0x3e200 , 0x3e200 ,
0x3e208 , 0x3e240 ,
0x3e248 , 0x3e280 ,
0x3e288 , 0x3e2c0 ,
0x3e2c8 , 0x3e2fc ,
0x3e600 , 0x3e630 ,
0x3ea00 , 0x3eabc ,
0x3eb00 , 0x3eb70 ,
0x3f000 , 0x3f048 ,
0x3f060 , 0x3f09c ,
0x3f0f0 , 0x3f148 ,
0x3f160 , 0x3f19c ,
0x3f1f0 , 0x3f2e4 ,
0x3f2f8 , 0x3f3e4 ,
0x3f3f8 , 0x3f448 ,
0x3f460 , 0x3f49c ,
0x3f4f0 , 0x3f548 ,
0x3f560 , 0x3f59c ,
0x3f5f0 , 0x3f6e4 ,
0x3f6f8 , 0x3f7e4 ,
0x3f7f8 , 0x3f7fc ,
0x3f814 , 0x3f814 ,
0x3f82c , 0x3f82c ,
0x3f880 , 0x3f88c ,
0x3f8e8 , 0x3f8ec ,
0x3f900 , 0x3f948 ,
0x3f960 , 0x3f99c ,
0x3f9f0 , 0x3fae4 ,
0x3faf8 , 0x3fb10 ,
0x3fb28 , 0x3fb28 ,
0x3fb3c , 0x3fb50 ,
0x3fbf0 , 0x3fc10 ,
0x3fc28 , 0x3fc28 ,
0x3fc3c , 0x3fc50 ,
0x3fcf0 , 0x3fcfc ,
0x40000 , 0x4000c ,
0x40040 , 0x40068 ,
0x4007c , 0x40144 ,
0x40180 , 0x4018c ,
0x40200 , 0x40298 ,
0x402ac , 0x4033c ,
0x403f8 , 0x403fc ,
0x41304 , 0x413c4 ,
0x41400 , 0x4141c ,
0x41480 , 0x414d0 ,
0x44000 , 0x44078 ,
0x440c0 , 0x44278 ,
0x442c0 , 0x44478 ,
0x444c0 , 0x44678 ,
0x446c0 , 0x44878 ,
0x448c0 , 0x449fc ,
0x45000 , 0x45068 ,
0x45080 , 0x45084 ,
0x450a0 , 0x450b0 ,
0x45200 , 0x45268 ,
0x45280 , 0x45284 ,
0x452a0 , 0x452b0 ,
0x460c0 , 0x460e4 ,
0x47000 , 0x4708c ,
0x47200 , 0x47250 ,
0x47400 , 0x47420 ,
0x47600 , 0x47618 ,
0x47800 , 0x47814 ,
0x48000 , 0x4800c ,
0x48040 , 0x48068 ,
0x4807c , 0x48144 ,
0x48180 , 0x4818c ,
0x48200 , 0x48298 ,
0x482ac , 0x4833c ,
0x483f8 , 0x483fc ,
0x49304 , 0x493c4 ,
0x49400 , 0x4941c ,
0x49480 , 0x494d0 ,
0x4c000 , 0x4c078 ,
0x4c0c0 , 0x4c278 ,
0x4c2c0 , 0x4c478 ,
0x4c4c0 , 0x4c678 ,
0x4c6c0 , 0x4c878 ,
0x4c8c0 , 0x4c9fc ,
0x4d000 , 0x4d068 ,
0x4d080 , 0x4d084 ,
0x4d0a0 , 0x4d0b0 ,
0x4d200 , 0x4d268 ,
0x4d280 , 0x4d284 ,
0x4d2a0 , 0x4d2b0 ,
0x4e0c0 , 0x4e0e4 ,
0x4f000 , 0x4f08c ,
0x4f200 , 0x4f250 ,
0x4f400 , 0x4f420 ,
0x4f600 , 0x4f618 ,
0x4f800 , 0x4f814 ,
0x50000 , 0x500cc ,
0x50400 , 0x50400 ,
0x50800 , 0x508cc ,
0x50c00 , 0x50c00 ,
0x51000 , 0x5101c ,
0x51300 , 0x51308 ,
} ;
static const unsigned int V_143 [] = {
0x1008 , 0x1124 ,
0x1138 , 0x114c ,
0x1180 , 0x11b4 ,
0x11fc , 0x1254 ,
0x1280 , 0x133c ,
0x1800 , 0x18fc ,
0x3000 , 0x302c ,
0x3060 , 0x30d8 ,
0x30e0 , 0x30fc ,
0x3140 , 0x357c ,
0x35a8 , 0x35cc ,
0x35ec , 0x35ec ,
0x3600 , 0x5624 ,
0x56cc , 0x575c ,
0x580c , 0x5814 ,
0x5890 , 0x58bc ,
0x5940 , 0x595c ,
0x5980 , 0x598c ,
0x59b0 , 0x59dc ,
0x59fc , 0x5a18 ,
0x5a60 , 0x5a6c ,
0x5a80 , 0x5a9c ,
0x5b94 , 0x5bfc ,
0x5c10 , 0x5ec0 ,
0x5ec8 , 0x5ecc ,
0x6000 , 0x6040 ,
0x6058 , 0x619c ,
0x7700 , 0x7798 ,
0x77c0 , 0x7880 ,
0x78cc , 0x78fc ,
0x7b00 , 0x7c54 ,
0x7d00 , 0x7efc ,
0x8dc0 , 0x8de4 ,
0x8df8 , 0x8e84 ,
0x8ea0 , 0x8f88 ,
0x8fb8 , 0x9124 ,
0x9400 , 0x9470 ,
0x9600 , 0x971c ,
0x9800 , 0x9808 ,
0x9820 , 0x983c ,
0x9850 , 0x9864 ,
0x9c00 , 0x9c6c ,
0x9c80 , 0x9cec ,
0x9d00 , 0x9d6c ,
0x9d80 , 0x9dec ,
0x9e00 , 0x9e6c ,
0x9e80 , 0x9eec ,
0x9f00 , 0x9f6c ,
0x9f80 , 0xa020 ,
0xd004 , 0xd03c ,
0xd100 , 0xd118 ,
0xd200 , 0xd31c ,
0xdfc0 , 0xdfe0 ,
0xe000 , 0xf008 ,
0x11000 , 0x11014 ,
0x11048 , 0x1117c ,
0x11190 , 0x11270 ,
0x11300 , 0x1130c ,
0x12000 , 0x1206c ,
0x19040 , 0x1906c ,
0x19078 , 0x19080 ,
0x1908c , 0x19124 ,
0x19150 , 0x191b0 ,
0x191d0 , 0x191e8 ,
0x19238 , 0x192bc ,
0x193f8 , 0x19474 ,
0x19490 , 0x194cc ,
0x194f0 , 0x194f8 ,
0x19c00 , 0x19c80 ,
0x19c94 , 0x19cbc ,
0x19ce4 , 0x19d28 ,
0x19d50 , 0x19d78 ,
0x19d94 , 0x19dc8 ,
0x19df0 , 0x19e10 ,
0x19e50 , 0x19e6c ,
0x19ea0 , 0x19f34 ,
0x19f40 , 0x19f50 ,
0x19f90 , 0x19fac ,
0x19fc4 , 0x19fe4 ,
0x1a000 , 0x1a06c ,
0x1a0b0 , 0x1a120 ,
0x1a128 , 0x1a138 ,
0x1a190 , 0x1a1c4 ,
0x1a1fc , 0x1a1fc ,
0x1e008 , 0x1e00c ,
0x1e040 , 0x1e04c ,
0x1e284 , 0x1e290 ,
0x1e2c0 , 0x1e2c0 ,
0x1e2e0 , 0x1e2e0 ,
0x1e300 , 0x1e384 ,
0x1e3c0 , 0x1e3c8 ,
0x1e408 , 0x1e40c ,
0x1e440 , 0x1e44c ,
0x1e684 , 0x1e690 ,
0x1e6c0 , 0x1e6c0 ,
0x1e6e0 , 0x1e6e0 ,
0x1e700 , 0x1e784 ,
0x1e7c0 , 0x1e7c8 ,
0x1e808 , 0x1e80c ,
0x1e840 , 0x1e84c ,
0x1ea84 , 0x1ea90 ,
0x1eac0 , 0x1eac0 ,
0x1eae0 , 0x1eae0 ,
0x1eb00 , 0x1eb84 ,
0x1ebc0 , 0x1ebc8 ,
0x1ec08 , 0x1ec0c ,
0x1ec40 , 0x1ec4c ,
0x1ee84 , 0x1ee90 ,
0x1eec0 , 0x1eec0 ,
0x1eee0 , 0x1eee0 ,
0x1ef00 , 0x1ef84 ,
0x1efc0 , 0x1efc8 ,
0x1f008 , 0x1f00c ,
0x1f040 , 0x1f04c ,
0x1f284 , 0x1f290 ,
0x1f2c0 , 0x1f2c0 ,
0x1f2e0 , 0x1f2e0 ,
0x1f300 , 0x1f384 ,
0x1f3c0 , 0x1f3c8 ,
0x1f408 , 0x1f40c ,
0x1f440 , 0x1f44c ,
0x1f684 , 0x1f690 ,
0x1f6c0 , 0x1f6c0 ,
0x1f6e0 , 0x1f6e0 ,
0x1f700 , 0x1f784 ,
0x1f7c0 , 0x1f7c8 ,
0x1f808 , 0x1f80c ,
0x1f840 , 0x1f84c ,
0x1fa84 , 0x1fa90 ,
0x1fac0 , 0x1fac0 ,
0x1fae0 , 0x1fae0 ,
0x1fb00 , 0x1fb84 ,
0x1fbc0 , 0x1fbc8 ,
0x1fc08 , 0x1fc0c ,
0x1fc40 , 0x1fc4c ,
0x1fe84 , 0x1fe90 ,
0x1fec0 , 0x1fec0 ,
0x1fee0 , 0x1fee0 ,
0x1ff00 , 0x1ff84 ,
0x1ffc0 , 0x1ffc8 ,
0x30000 , 0x30070 ,
0x30100 , 0x301d0 ,
0x30200 , 0x30320 ,
0x30400 , 0x3052c ,
0x30540 , 0x3061c ,
0x30800 , 0x30890 ,
0x308c0 , 0x30908 ,
0x30910 , 0x309b8 ,
0x30a00 , 0x30a04 ,
0x30a0c , 0x30a2c ,
0x30a44 , 0x30a50 ,
0x30a74 , 0x30c24 ,
0x30d00 , 0x30d3c ,
0x30d44 , 0x30d7c ,
0x30de0 , 0x30de0 ,
0x30e00 , 0x30ed4 ,
0x30f00 , 0x30fa4 ,
0x30fc0 , 0x30fc4 ,
0x31000 , 0x31004 ,
0x31080 , 0x310fc ,
0x31208 , 0x31220 ,
0x3123c , 0x31254 ,
0x31300 , 0x31300 ,
0x31308 , 0x3131c ,
0x31338 , 0x3133c ,
0x31380 , 0x31380 ,
0x31388 , 0x313a8 ,
0x313b4 , 0x313b4 ,
0x31400 , 0x31420 ,
0x31438 , 0x3143c ,
0x31480 , 0x31480 ,
0x314a8 , 0x314a8 ,
0x314b0 , 0x314b4 ,
0x314c8 , 0x314d4 ,
0x31a40 , 0x31a4c ,
0x31af0 , 0x31b20 ,
0x31b38 , 0x31b3c ,
0x31b80 , 0x31b80 ,
0x31ba8 , 0x31ba8 ,
0x31bb0 , 0x31bb4 ,
0x31bc8 , 0x31bd4 ,
0x32140 , 0x3218c ,
0x321f0 , 0x32200 ,
0x32218 , 0x32218 ,
0x32400 , 0x32400 ,
0x32408 , 0x3241c ,
0x32618 , 0x32620 ,
0x32664 , 0x32664 ,
0x326a8 , 0x326a8 ,
0x326ec , 0x326ec ,
0x32a00 , 0x32abc ,
0x32b00 , 0x32b78 ,
0x32c00 , 0x32c00 ,
0x32c08 , 0x32c3c ,
0x32e00 , 0x32e2c ,
0x32f00 , 0x32f2c ,
0x33000 , 0x330ac ,
0x330c0 , 0x331ac ,
0x331c0 , 0x332c4 ,
0x332e4 , 0x333c4 ,
0x333e4 , 0x334ac ,
0x334c0 , 0x335ac ,
0x335c0 , 0x336c4 ,
0x336e4 , 0x337c4 ,
0x337e4 , 0x337fc ,
0x33814 , 0x33814 ,
0x33854 , 0x33868 ,
0x33880 , 0x3388c ,
0x338c0 , 0x338d0 ,
0x338e8 , 0x338ec ,
0x33900 , 0x339ac ,
0x339c0 , 0x33ac4 ,
0x33ae4 , 0x33b10 ,
0x33b24 , 0x33b50 ,
0x33bf0 , 0x33c10 ,
0x33c24 , 0x33c50 ,
0x33cf0 , 0x33cfc ,
0x34000 , 0x34070 ,
0x34100 , 0x341d0 ,
0x34200 , 0x34320 ,
0x34400 , 0x3452c ,
0x34540 , 0x3461c ,
0x34800 , 0x34890 ,
0x348c0 , 0x34908 ,
0x34910 , 0x349b8 ,
0x34a00 , 0x34a04 ,
0x34a0c , 0x34a2c ,
0x34a44 , 0x34a50 ,
0x34a74 , 0x34c24 ,
0x34d00 , 0x34d3c ,
0x34d44 , 0x34d7c ,
0x34de0 , 0x34de0 ,
0x34e00 , 0x34ed4 ,
0x34f00 , 0x34fa4 ,
0x34fc0 , 0x34fc4 ,
0x35000 , 0x35004 ,
0x35080 , 0x350fc ,
0x35208 , 0x35220 ,
0x3523c , 0x35254 ,
0x35300 , 0x35300 ,
0x35308 , 0x3531c ,
0x35338 , 0x3533c ,
0x35380 , 0x35380 ,
0x35388 , 0x353a8 ,
0x353b4 , 0x353b4 ,
0x35400 , 0x35420 ,
0x35438 , 0x3543c ,
0x35480 , 0x35480 ,
0x354a8 , 0x354a8 ,
0x354b0 , 0x354b4 ,
0x354c8 , 0x354d4 ,
0x35a40 , 0x35a4c ,
0x35af0 , 0x35b20 ,
0x35b38 , 0x35b3c ,
0x35b80 , 0x35b80 ,
0x35ba8 , 0x35ba8 ,
0x35bb0 , 0x35bb4 ,
0x35bc8 , 0x35bd4 ,
0x36140 , 0x3618c ,
0x361f0 , 0x36200 ,
0x36218 , 0x36218 ,
0x36400 , 0x36400 ,
0x36408 , 0x3641c ,
0x36618 , 0x36620 ,
0x36664 , 0x36664 ,
0x366a8 , 0x366a8 ,
0x366ec , 0x366ec ,
0x36a00 , 0x36abc ,
0x36b00 , 0x36b78 ,
0x36c00 , 0x36c00 ,
0x36c08 , 0x36c3c ,
0x36e00 , 0x36e2c ,
0x36f00 , 0x36f2c ,
0x37000 , 0x370ac ,
0x370c0 , 0x371ac ,
0x371c0 , 0x372c4 ,
0x372e4 , 0x373c4 ,
0x373e4 , 0x374ac ,
0x374c0 , 0x375ac ,
0x375c0 , 0x376c4 ,
0x376e4 , 0x377c4 ,
0x377e4 , 0x377fc ,
0x37814 , 0x37814 ,
0x37854 , 0x37868 ,
0x37880 , 0x3788c ,
0x378c0 , 0x378d0 ,
0x378e8 , 0x378ec ,
0x37900 , 0x379ac ,
0x379c0 , 0x37ac4 ,
0x37ae4 , 0x37b10 ,
0x37b24 , 0x37b50 ,
0x37bf0 , 0x37c10 ,
0x37c24 , 0x37c50 ,
0x37cf0 , 0x37cfc ,
0x40040 , 0x40040 ,
0x40080 , 0x40084 ,
0x40100 , 0x40100 ,
0x40140 , 0x401bc ,
0x40200 , 0x40214 ,
0x40228 , 0x40228 ,
0x40240 , 0x40258 ,
0x40280 , 0x40280 ,
0x40304 , 0x40304 ,
0x40330 , 0x4033c ,
0x41304 , 0x413dc ,
0x41400 , 0x4141c ,
0x41480 , 0x414d0 ,
0x44000 , 0x4407c ,
0x440c0 , 0x4427c ,
0x442c0 , 0x4447c ,
0x444c0 , 0x4467c ,
0x446c0 , 0x4487c ,
0x448c0 , 0x44a7c ,
0x44ac0 , 0x44c7c ,
0x44cc0 , 0x44e7c ,
0x44ec0 , 0x4507c ,
0x450c0 , 0x451fc ,
0x45800 , 0x45868 ,
0x45880 , 0x45884 ,
0x458a0 , 0x458b0 ,
0x45a00 , 0x45a68 ,
0x45a80 , 0x45a84 ,
0x45aa0 , 0x45ab0 ,
0x460c0 , 0x460e4 ,
0x47000 , 0x4708c ,
0x47200 , 0x47250 ,
0x47400 , 0x47420 ,
0x47600 , 0x47618 ,
0x47800 , 0x4782c ,
0x50000 , 0x500cc ,
0x50400 , 0x50400 ,
0x50800 , 0x508cc ,
0x50c00 , 0x50c00 ,
0x51000 , 0x510b0 ,
0x51300 , 0x51324 ,
} ;
T_1 * V_144 = ( T_1 * ) ( ( char * ) V_91 + V_140 ) ;
const unsigned int * V_145 ;
int V_146 , V_147 ;
unsigned int V_135 = F_12 ( V_12 -> V_20 . V_21 ) ;
switch ( V_135 ) {
case V_136 :
V_145 = V_141 ;
V_146 = F_30 ( V_141 ) ;
break;
case V_22 :
V_145 = V_142 ;
V_146 = F_30 ( V_142 ) ;
break;
case V_138 :
V_145 = V_143 ;
V_146 = F_30 ( V_143 ) ;
break;
default:
F_15 ( V_12 -> V_32 ,
L_17 , V_135 ) ;
return;
}
memset ( V_91 , 0 , V_140 ) ;
for ( V_147 = 0 ; V_147 < V_146 ; V_147 += 2 ) {
unsigned int V_2 = V_145 [ V_147 ] ;
unsigned int V_148 = V_145 [ V_147 + 1 ] ;
T_1 * V_149 = ( T_1 * ) ( ( char * ) V_91 + V_2 ) ;
while ( V_2 <= V_148 && V_149 < V_144 ) {
* V_149 ++ = F_2 ( V_12 , V_2 ) ;
V_2 += sizeof( T_1 ) ;
}
}
}
int F_65 ( struct V_1 * V_1 , bool V_150 )
{
unsigned int V_11 = V_150 ? 0xc : 0 ;
int V_113 = F_66 ( V_1 -> V_57 , V_151 , 4 , & V_11 ) ;
return V_113 < 0 ? V_113 : 0 ;
}
int F_67 ( struct V_1 * V_1 , struct V_152 * V_51 )
{
int V_48 , V_113 = 0 , V_10 ;
int V_153 , V_154 , V_155 , V_156 ;
V_68 * V_157 , V_158 ;
unsigned int V_159 , V_160 , V_161 ;
V_157 = F_68 ( V_162 ) ;
if ( ! V_157 )
return - V_163 ;
V_113 = F_69 ( V_1 -> V_57 , V_164 , sizeof( T_1 ) , V_157 ) ;
if ( V_113 < 0 )
goto V_165;
V_10 = * V_157 == V_166 ? V_164 : V_167 ;
V_113 = F_69 ( V_1 -> V_57 , V_10 , V_162 , V_157 ) ;
if ( V_113 < 0 )
goto V_165;
if ( V_157 [ 0 ] != V_168 ) {
F_15 ( V_1 -> V_32 , L_18 ) ;
V_113 = - V_56 ;
goto V_165;
}
V_161 = F_70 ( V_157 ) ;
if ( V_161 > V_169 )
V_161 = V_169 ;
V_48 = F_71 ( V_157 , 0 , V_162 , V_170 ) ;
if ( V_48 < 0 ) {
F_15 ( V_1 -> V_32 , L_19 ) ;
V_113 = - V_56 ;
goto V_165;
}
V_159 = F_70 ( & V_157 [ V_48 ] ) ;
V_160 = V_48 + V_171 ;
if ( V_159 + V_160 > V_162 ) {
F_15 ( V_1 -> V_32 , L_20 , V_159 ) ;
V_113 = - V_56 ;
goto V_165;
}
#define F_72 ( T_5 , T_6 ) do { \
var = pci_vpd_find_info_keyword(vpd, kw_offset, vpdr_len, name); \
if (var < 0) { \
dev_err(adapter->pdev_dev, "missing VPD keyword " name "\n"); \
ret = -EINVAL; \
goto out; \
} \
var += PCI_VPD_INFO_FLD_HDR_SIZE; \
} while (0)
F_72 ( V_48 , L_21 ) ;
for ( V_158 = 0 ; V_48 >= 0 ; V_48 -- )
V_158 += V_157 [ V_48 ] ;
if ( V_158 ) {
F_15 ( V_1 -> V_32 ,
L_22 , V_158 ) ;
V_113 = - V_56 ;
goto V_165;
}
F_72 ( V_153 , L_23 ) ;
F_72 ( V_154 , L_24 ) ;
F_72 ( V_155 , L_25 ) ;
F_72 ( V_156 , L_26 ) ;
#undef F_72
memcpy ( V_51 -> V_172 , V_157 + V_171 , V_161 ) ;
F_73 ( V_51 -> V_172 ) ;
memcpy ( V_51 -> V_153 , V_157 + V_153 , V_173 ) ;
F_73 ( V_51 -> V_153 ) ;
V_48 = F_74 ( V_157 + V_154 - V_174 ) ;
memcpy ( V_51 -> V_154 , V_157 + V_154 , F_75 ( V_48 , V_175 ) ) ;
F_73 ( V_51 -> V_154 ) ;
V_48 = F_74 ( V_157 + V_155 - V_174 ) ;
memcpy ( V_51 -> V_155 , V_157 + V_155 , F_75 ( V_48 , V_176 ) ) ;
F_73 ( V_51 -> V_155 ) ;
memcpy ( V_51 -> V_156 , V_157 + V_156 , F_75 ( V_48 , V_177 ) ) ;
F_73 ( ( char * ) V_51 -> V_156 ) ;
V_165:
F_76 ( V_157 ) ;
return V_113 ;
}
int F_77 ( struct V_1 * V_1 , struct V_152 * V_51 )
{
T_1 V_178 , V_179 ;
int V_113 ;
V_113 = F_67 ( V_1 , V_51 ) ;
if ( V_113 )
return V_113 ;
V_178 = ( F_78 ( V_180 ) |
F_79 ( V_181 ) ) ;
V_113 = F_80 ( V_1 , V_1 -> V_42 , V_1 -> V_19 , 0 ,
1 , & V_178 , & V_179 ) ;
if ( V_113 )
return V_113 ;
V_51 -> V_182 = V_179 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_1 , unsigned int V_183 , int V_184 ,
int V_185 , T_1 * V_7 )
{
int V_113 ;
if ( ! V_183 || V_183 > 4 )
return - V_56 ;
if ( F_2 ( V_1 , V_186 ) & V_187 )
return - V_63 ;
F_6 ( V_1 , V_186 , F_82 ( V_185 ) |
F_83 ( V_184 ) | F_84 ( V_183 - 1 ) ) ;
V_113 = F_4 ( V_1 , V_186 , V_187 , 0 , V_188 , 5 ) ;
if ( ! V_113 )
* V_7 = F_2 ( V_1 , V_189 ) ;
return V_113 ;
}
static int F_85 ( struct V_1 * V_1 , unsigned int V_183 , int V_184 ,
int V_185 , T_1 V_8 )
{
if ( ! V_183 || V_183 > 4 )
return - V_56 ;
if ( F_2 ( V_1 , V_186 ) & V_187 )
return - V_63 ;
F_6 ( V_1 , V_189 , V_8 ) ;
F_6 ( V_1 , V_186 , F_82 ( V_185 ) |
F_83 ( V_184 ) | F_84 ( V_183 - 1 ) | F_86 ( 1 ) ) ;
return F_4 ( V_1 , V_186 , V_187 , 0 , V_188 , 5 ) ;
}
static int F_87 ( struct V_1 * V_1 , int V_5 , int V_6 )
{
int V_113 ;
T_1 V_190 ;
while ( 1 ) {
if ( ( V_113 = F_85 ( V_1 , 1 , 1 , 1 , V_191 ) ) != 0 ||
( V_113 = F_81 ( V_1 , 1 , 0 , 1 , & V_190 ) ) != 0 )
return V_113 ;
if ( ! ( V_190 & 1 ) )
return 0 ;
if ( -- V_5 == 0 )
return - V_9 ;
if ( V_6 )
F_31 ( V_6 ) ;
}
}
int F_88 ( struct V_1 * V_1 , unsigned int V_10 ,
unsigned int V_192 , T_1 * V_125 , int V_193 )
{
int V_113 ;
if ( V_10 + V_192 * sizeof( T_1 ) > V_1 -> V_20 . V_194 || ( V_10 & 3 ) )
return - V_56 ;
V_10 = F_89 ( V_10 ) | V_195 ;
if ( ( V_113 = F_85 ( V_1 , 4 , 1 , 0 , V_10 ) ) != 0 ||
( V_113 = F_81 ( V_1 , 1 , 1 , 0 , V_125 ) ) != 0 )
return V_113 ;
for ( ; V_192 ; V_192 -- , V_125 ++ ) {
V_113 = F_81 ( V_1 , 4 , V_192 > 1 , V_192 == 1 , V_125 ) ;
if ( V_192 == 1 )
F_6 ( V_1 , V_186 , 0 ) ;
if ( V_113 )
return V_113 ;
if ( V_193 )
* V_125 = ( V_103 V_196 ) ( F_51 ( * V_125 ) ) ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_1 , unsigned int V_10 ,
unsigned int V_197 , const V_68 * V_125 )
{
int V_113 ;
T_1 V_91 [ 64 ] ;
unsigned int V_48 , V_198 , V_199 , V_8 , V_82 = V_10 & 0xff ;
if ( V_10 >= V_1 -> V_20 . V_194 || V_82 + V_197 > V_200 )
return - V_56 ;
V_8 = F_89 ( V_10 ) | V_201 ;
if ( ( V_113 = F_85 ( V_1 , 1 , 0 , 1 , V_202 ) ) != 0 ||
( V_113 = F_85 ( V_1 , 4 , 1 , 1 , V_8 ) ) != 0 )
goto V_203;
for ( V_199 = V_197 ; V_199 ; V_199 -= V_198 ) {
V_198 = F_75 ( V_199 , 4U ) ;
for ( V_8 = 0 , V_48 = 0 ; V_48 < V_198 ; ++ V_48 )
V_8 = ( V_8 << 8 ) + * V_125 ++ ;
V_113 = F_85 ( V_1 , V_198 , V_198 != V_199 , 1 , V_8 ) ;
if ( V_113 )
goto V_203;
}
V_113 = F_87 ( V_1 , 8 , 1 ) ;
if ( V_113 )
goto V_203;
F_6 ( V_1 , V_186 , 0 ) ;
V_113 = F_88 ( V_1 , V_10 & ~ 0xff , F_30 ( V_91 ) , V_91 , 1 ) ;
if ( V_113 )
return V_113 ;
if ( memcmp ( V_125 - V_197 , ( V_68 * ) V_91 + V_82 , V_197 ) ) {
F_15 ( V_1 -> V_32 ,
L_27 ,
V_10 ) ;
return - V_60 ;
}
return 0 ;
V_203:
F_6 ( V_1 , V_186 , 0 ) ;
return V_113 ;
}
int F_91 ( struct V_1 * V_1 , T_1 * V_204 )
{
return F_88 ( V_1 , V_205 +
F_92 ( struct V_206 , V_207 ) , 1 ,
V_204 , 0 ) ;
}
int F_93 ( struct V_1 * V_1 , T_1 * V_204 )
{
return F_88 ( V_1 , V_205 +
F_92 ( struct V_206 , V_208 ) ,
1 , V_204 , 0 ) ;
}
int F_94 ( struct V_1 * V_12 , T_1 * V_204 )
{
struct V_209 {
unsigned char V_210 [ 16 ] ;
unsigned char V_211 [ 4 ] ;
} * V_212 ;
T_1 V_213 [ F_95 ( sizeof( struct V_209 ) ,
sizeof( T_1 ) ) ] ;
int V_113 ;
V_113 = F_88 ( V_12 , V_214 ,
F_30 ( V_213 ) , V_213 ,
0 ) ;
if ( V_113 )
return V_113 ;
V_212 = (struct V_209 * ) V_213 ;
if ( V_212 -> V_210 [ 0 ] != 0x55 || V_212 -> V_210 [ 1 ] != 0xaa )
return - V_215 ;
* V_204 = ( F_96 ( V_212 -> V_211 [ 0 ] ) |
F_97 ( V_212 -> V_211 [ 1 ] ) |
F_98 ( V_212 -> V_211 [ 2 ] ) |
F_99 ( V_212 -> V_211 [ 3 ] ) ) ;
return 0 ;
}
int F_100 ( struct V_1 * V_12 )
{
int V_113 , V_216 , V_217 , V_218 ;
int V_219 , V_220 , V_221 ;
unsigned int V_135 = F_12 ( V_12 -> V_20 . V_21 ) ;
V_113 = F_91 ( V_12 , & V_12 -> V_20 . V_222 ) ;
if ( V_113 )
return V_113 ;
V_216 = F_101 ( V_12 -> V_20 . V_222 ) ;
V_217 = F_102 ( V_12 -> V_20 . V_222 ) ;
V_218 = F_103 ( V_12 -> V_20 . V_222 ) ;
switch ( V_135 ) {
case V_136 :
V_219 = V_223 ;
V_220 = V_224 ;
V_221 = V_225 ;
break;
case V_22 :
V_219 = V_226 ;
V_220 = V_227 ;
V_221 = V_228 ;
break;
case V_138 :
V_219 = V_229 ;
V_220 = V_230 ;
V_221 = V_231 ;
break;
default:
F_15 ( V_12 -> V_32 , L_28 ,
V_12 -> V_21 ) ;
return - V_56 ;
}
if ( V_216 < V_219 || ( V_216 == V_219 && V_217 < V_220 ) ||
( V_216 == V_219 && V_217 == V_220 && V_218 < V_221 ) ) {
F_15 ( V_12 -> V_32 ,
L_29
L_30 , V_216 , V_217 ,
V_218 , V_219 , V_220 , V_221 ) ;
return - V_232 ;
}
return 0 ;
}
static int F_104 ( const struct V_206 * V_233 , const struct V_206 * V_234 )
{
if ( V_233 -> V_21 == V_234 -> V_21 && V_233 -> V_207 == V_234 -> V_207 )
return 1 ;
#define F_105 ( V_40 ) (hdr1->intfver_##x == hdr2->intfver_##x)
if ( V_233 -> V_21 == V_234 -> V_21 && F_105 ( V_235 ) && F_105 ( V_236 ) &&
F_105 ( V_237 ) && F_105 ( V_238 ) && F_105 ( V_239 ) )
return 1 ;
#undef F_105
return 0 ;
}
static int F_106 ( struct V_1 * V_12 , int V_240 ,
int V_241 , int V_198 )
{
const char * V_28 ;
if ( ! V_240 ) {
V_28 = L_31 ;
goto V_242;
}
if ( V_241 > V_198 ) {
V_28 = L_32 ;
goto V_242;
}
return 0 ;
V_242:
F_15 ( V_12 -> V_32 , L_33
L_34 ,
F_101 ( V_198 ) , F_102 ( V_198 ) ,
F_103 ( V_198 ) , F_107 ( V_198 ) , V_28 ,
F_101 ( V_241 ) , F_102 ( V_241 ) ,
F_103 ( V_241 ) , F_107 ( V_241 ) ) ;
return 1 ;
}
int F_108 ( struct V_1 * V_12 , struct V_243 * V_243 ,
const V_68 * V_244 , unsigned int V_245 ,
struct V_206 * V_246 , enum V_247 V_248 ,
int * V_249 )
{
int V_113 , V_240 , V_250 ;
const struct V_206 * V_251 ;
const struct V_206 * V_252 ;
V_252 = & V_243 -> V_206 ;
V_113 = - F_88 ( V_12 , V_205 ,
sizeof( * V_246 ) / sizeof( V_253 ) ,
( V_253 * ) V_246 , 1 ) ;
if ( V_113 == 0 ) {
V_240 = F_104 ( V_252 , ( const void * ) V_246 ) ;
} else {
F_15 ( V_12 -> V_32 ,
L_35 , V_113 ) ;
V_240 = 0 ;
}
if ( V_244 != NULL ) {
V_251 = ( const void * ) V_244 ;
V_250 = F_104 ( V_252 , V_251 ) ;
} else {
V_251 = NULL ;
V_250 = 0 ;
}
if ( V_240 && V_246 -> V_207 == V_252 -> V_207 &&
( ! V_250 || V_251 -> V_207 == V_252 -> V_207 ) ) {
} else if ( V_250 && V_248 == V_254 &&
F_106 ( V_12 , V_240 ,
F_22 ( V_251 -> V_207 ) ,
F_22 ( V_246 -> V_207 ) ) ) {
V_113 = - F_109 ( V_12 , V_12 -> V_42 , V_244 ,
V_245 , 0 ) ;
if ( V_113 != 0 ) {
F_15 ( V_12 -> V_32 ,
L_36 , V_113 ) ;
goto V_255;
}
* V_246 = * V_251 ;
V_240 = 1 ;
* V_249 = 0 ;
}
if ( ! V_240 ) {
V_253 V_256 , V_198 , V_241 ;
V_256 = F_22 ( V_252 -> V_207 ) ;
V_198 = F_22 ( V_246 -> V_207 ) ;
V_241 = V_251 ? F_22 ( V_251 -> V_207 ) : 0 ;
F_15 ( V_12 -> V_32 , L_37
L_38
L_39
L_40 ,
V_248 ,
F_101 ( V_256 ) , F_102 ( V_256 ) ,
F_103 ( V_256 ) , F_107 ( V_256 ) ,
F_101 ( V_198 ) , F_102 ( V_198 ) ,
F_103 ( V_198 ) , F_107 ( V_198 ) ,
F_101 ( V_241 ) , F_102 ( V_241 ) ,
F_103 ( V_241 ) , F_107 ( V_241 ) ) ;
V_113 = V_56 ;
goto V_255;
}
V_12 -> V_20 . V_222 = F_22 ( V_246 -> V_207 ) ;
V_12 -> V_20 . V_257 = F_22 ( V_246 -> V_208 ) ;
V_255:
return V_113 ;
}
static int F_110 ( struct V_1 * V_1 , int V_258 , int V_259 )
{
int V_113 = 0 ;
if ( V_259 >= V_1 -> V_20 . V_260 )
return - V_56 ;
while ( V_258 <= V_259 ) {
if ( ( V_113 = F_85 ( V_1 , 1 , 0 , 1 , V_202 ) ) != 0 ||
( V_113 = F_85 ( V_1 , 4 , 0 , 1 ,
V_261 | ( V_258 << 8 ) ) ) != 0 ||
( V_113 = F_87 ( V_1 , 14 , 500 ) ) != 0 ) {
F_15 ( V_1 -> V_32 ,
L_41 ,
V_258 , V_113 ) ;
break;
}
V_258 ++ ;
}
F_6 ( V_1 , V_186 , 0 ) ;
return V_113 ;
}
unsigned int F_111 ( struct V_1 * V_1 )
{
if ( V_1 -> V_20 . V_194 == 0x100000 )
return V_262 ;
else
return V_263 ;
}
static bool F_112 ( const struct V_1 * V_12 ,
const struct V_206 * V_212 )
{
if ( ( F_13 ( V_12 -> V_20 . V_21 ) && V_212 -> V_21 == V_264 ) ||
( F_113 ( V_12 -> V_20 . V_21 ) && V_212 -> V_21 == V_265 ) ||
( F_114 ( V_12 -> V_20 . V_21 ) && V_212 -> V_21 == V_266 ) )
return true ;
F_15 ( V_12 -> V_32 ,
L_42 ,
V_212 -> V_21 , F_12 ( V_12 -> V_20 . V_21 ) ) ;
return false ;
}
int F_115 ( struct V_1 * V_12 , const V_68 * V_244 , unsigned int V_44 )
{
T_1 V_158 ;
int V_113 , V_10 ;
unsigned int V_48 ;
V_68 V_267 [ V_200 ] ;
const V_105 * V_51 = ( const V_105 * ) V_244 ;
const struct V_206 * V_212 = ( const struct V_206 * ) V_244 ;
unsigned int V_268 = V_12 -> V_20 . V_194 / V_12 -> V_20 . V_260 ;
unsigned int V_269 = V_12 -> V_20 . V_270 ;
unsigned int V_271 = V_269 / V_268 ;
if ( ! V_44 ) {
F_15 ( V_12 -> V_32 , L_43 ) ;
return - V_56 ;
}
if ( V_44 & 511 ) {
F_15 ( V_12 -> V_32 ,
L_44 ) ;
return - V_56 ;
}
if ( ( unsigned int ) F_116 ( V_212 -> V_272 ) * 512 != V_44 ) {
F_15 ( V_12 -> V_32 ,
L_45 ) ;
return - V_56 ;
}
if ( V_44 > V_273 ) {
F_15 ( V_12 -> V_32 , L_46 ,
V_273 ) ;
return - V_274 ;
}
if ( ! F_112 ( V_12 , V_212 ) )
return - V_56 ;
for ( V_158 = 0 , V_48 = 0 ; V_48 < V_44 / sizeof( V_158 ) ; V_48 ++ )
V_158 += F_22 ( V_51 [ V_48 ] ) ;
if ( V_158 != 0xffffffff ) {
F_15 ( V_12 -> V_32 ,
L_47 , V_158 ) ;
return - V_56 ;
}
V_48 = F_95 ( V_44 , V_268 ) ;
V_113 = F_110 ( V_12 , V_271 , V_271 + V_48 - 1 ) ;
if ( V_113 )
goto V_165;
memcpy ( V_267 , V_244 , V_200 ) ;
( (struct V_206 * ) V_267 ) -> V_207 = F_51 ( 0xffffffff ) ;
V_113 = F_90 ( V_12 , V_269 , V_200 , V_267 ) ;
if ( V_113 )
goto V_165;
V_10 = V_269 ;
for ( V_44 -= V_200 ; V_44 ; V_44 -= V_200 ) {
V_10 += V_200 ;
V_244 += V_200 ;
V_113 = F_90 ( V_12 , V_10 , V_200 , V_244 ) ;
if ( V_113 )
goto V_165;
}
V_113 = F_90 ( V_12 ,
V_269 + F_92 ( struct V_206 , V_207 ) ,
sizeof( V_212 -> V_207 ) , ( const V_68 * ) & V_212 -> V_207 ) ;
V_165:
if ( V_113 )
F_15 ( V_12 -> V_32 , L_48 ,
V_113 ) ;
else
V_113 = F_91 ( V_12 , & V_12 -> V_20 . V_222 ) ;
return V_113 ;
}
int F_117 ( struct V_1 * V_12 , int * V_275 )
{
T_1 V_276 , V_8 ;
int V_113 ;
V_276 = ( F_78 ( V_180 ) |
F_79 ( V_277 ) |
F_118 ( V_12 -> V_20 . V_278 ) |
F_119 ( V_279 ) ) ;
V_113 = F_80 ( V_12 , V_12 -> V_42 , V_12 -> V_19 , 0 , 1 ,
& V_276 , & V_8 ) ;
if ( V_113 < 0 )
return V_113 ;
* V_275 = V_8 ;
return 0 ;
}
int F_120 ( struct V_1 * V_12 ,
int V_76 , T_7 * V_280 ,
int (* F_121)( const V_68 * , T_4 ) ,
const V_68 * V_281 , T_4 V_282 )
{
unsigned long V_77 = 0 , V_283 = 0 ;
T_1 V_276 , V_8 ;
int V_284 = 0 , V_285 = 0 ;
int V_113 ;
if ( F_121 ) {
V_285 = F_121 ( V_281 , V_282 ) ;
V_113 = F_117 ( V_12 , & V_284 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_284 >= V_285 ) {
F_38 ( V_12 , L_49
L_50 , V_284 ) ;
return 0 ;
}
}
V_276 = ( F_78 ( V_180 ) |
F_79 ( V_277 ) |
F_118 ( V_12 -> V_20 . V_278 ) |
F_119 ( V_286 ) ) ;
V_8 = V_282 ;
V_113 = F_122 ( V_12 , V_12 -> V_42 , V_12 -> V_19 , 0 , 1 ,
& V_276 , & V_8 , 1 ) ;
if ( V_113 < 0 )
return V_113 ;
V_77 = V_8 >> 8 ;
V_283 = ( V_8 & 0xff ) << 16 ;
if ( V_280 )
F_123 ( V_280 ) ;
V_113 = F_40 ( V_12 , V_76 , V_77 , V_283 ,
V_282 , ( V_105 * ) V_281 ,
V_287 ) ;
if ( V_280 )
F_124 ( V_280 ) ;
if ( V_113 )
return V_113 ;
V_276 = ( F_78 ( V_180 ) |
F_79 ( V_277 ) |
F_118 ( V_12 -> V_20 . V_278 ) |
F_119 ( V_286 ) ) ;
V_113 = F_125 ( V_12 , V_12 -> V_42 , V_12 -> V_19 , 0 , 1 ,
& V_276 , & V_8 , 30000 ) ;
if ( F_121 ) {
V_113 = F_117 ( V_12 , & V_284 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_284 != V_285 ) {
F_38 ( V_12 , L_51
L_52
L_53 ,
V_284 , V_285 ) ;
return - V_288 ;
}
}
return 1 ;
}
int F_126 ( struct V_1 * V_12 , enum V_289 V_290 )
{
struct V_291 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 =
F_51 ( F_52 ( V_293 ) |
V_117 | V_294 |
F_127 ( V_12 -> V_19 ) |
F_128 ( 0 ) ) ;
V_198 . V_295 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_276 [ 0 ] . V_296 =
F_51 ( F_78 ( V_180 ) |
F_79 ( V_297 ) ) ;
V_198 . V_276 [ 0 ] . V_8 = ( V_103 V_105 ) V_290 ;
return F_56 ( V_12 , V_12 -> V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
void F_129 ( struct V_1 * V_12 , T_1 * V_298 , T_1 * V_299 ,
unsigned int * V_300 ,
unsigned int * V_301 )
{
int V_48 , V_302 ;
T_1 V_303 , V_8 , V_18 , V_304 ;
V_303 = F_2 ( V_12 , V_305 ) ;
if ( V_303 & V_306 )
F_6 ( V_12 , V_305 , V_303 ^ V_306 ) ;
V_8 = F_2 ( V_12 , V_307 ) ;
V_18 = F_130 ( V_8 ) ;
V_304 = F_131 ( V_8 ) ;
if ( V_300 )
* V_300 = V_18 ;
if ( V_301 )
* V_301 = V_304 ;
for ( V_48 = 0 ; V_48 < V_308 ; V_48 ++ ) {
for ( V_302 = 0 ; V_302 < 6 ; V_302 ++ ) {
F_6 ( V_12 , V_305 , F_132 ( V_18 ) |
F_133 ( V_304 ) ) ;
* V_298 ++ = F_2 ( V_12 , V_309 ) ;
* V_299 ++ = F_2 ( V_12 , V_310 ) ;
V_18 ++ ;
V_304 ++ ;
}
V_18 = ( V_18 + 2 ) & V_311 ;
V_304 = ( V_304 + 2 ) & V_312 ;
}
F_6 ( V_12 , V_305 , V_303 ) ;
}
void F_134 ( struct V_1 * V_12 , T_1 * V_313 , T_1 * V_314 )
{
T_1 V_303 ;
int V_48 , V_302 , V_70 ;
V_303 = F_2 ( V_12 , V_305 ) ;
if ( V_303 & V_306 )
F_6 ( V_12 , V_305 , V_303 ^ V_306 ) ;
for ( V_48 = 0 ; V_48 < V_315 ; V_48 ++ ) {
for ( V_302 = 0 ; V_302 < 5 ; V_302 ++ ) {
V_70 = 8 * V_48 + V_302 ;
F_6 ( V_12 , V_305 , F_132 ( V_70 ) |
F_133 ( V_70 ) ) ;
* V_313 ++ = F_2 ( V_12 , V_316 ) ;
* V_314 ++ = F_2 ( V_12 , V_317 ) ;
}
}
F_6 ( V_12 , V_305 , V_303 ) ;
}
void F_135 ( struct V_1 * V_12 , T_1 * V_318 )
{
unsigned int V_48 , V_302 ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
T_1 * V_51 = V_318 + V_48 ;
F_6 ( V_12 , V_319 , V_48 ) ;
V_302 = F_2 ( V_12 , V_320 ) ;
F_6 ( V_12 , V_321 , V_302 ) ;
for ( V_302 = 0 ; V_302 < V_322 ; V_302 ++ , V_51 += 8 )
* V_51 = F_2 ( V_12 , V_323 ) ;
}
}
int F_136 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_324 ,
struct V_325 * V_326 )
{
struct V_327 V_198 ;
unsigned int V_328 = 0 , V_329 = F_137 ( V_330 ) ;
V_326 -> V_331 = 0 ;
if ( V_326 -> V_332 & V_333 )
V_328 |= V_334 ;
if ( V_326 -> V_332 & V_335 )
V_328 |= V_336 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_337 = F_51 ( F_52 ( V_338 ) |
V_117 | V_339 |
F_138 ( V_324 ) ) ;
V_198 . V_340 =
F_51 ( F_139 ( V_341 ) |
F_53 ( V_198 ) ) ;
if ( ! ( V_326 -> V_342 & V_343 ) ) {
V_198 . V_38 . V_344 . V_345 = F_51 ( ( V_326 -> V_342 & V_346 ) |
V_328 ) ;
V_326 -> V_328 = V_326 -> V_332 & ( V_333 | V_335 ) ;
} else if ( V_326 -> V_347 == V_348 ) {
V_198 . V_38 . V_344 . V_345 = F_51 ( V_326 -> V_349 | V_328 | V_329 ) ;
V_326 -> V_328 = V_326 -> V_332 & ( V_333 | V_335 ) ;
} else
V_198 . V_38 . V_344 . V_345 = F_51 ( V_326 -> V_350 | V_328 | V_329 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_140 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_324 )
{
struct V_327 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_337 = F_51 ( F_52 ( V_338 ) |
V_117 | V_339 |
F_138 ( V_324 ) ) ;
V_198 . V_340 =
F_51 ( F_139 ( V_341 ) |
F_53 ( V_198 ) ) ;
V_198 . V_38 . V_344 . V_345 = F_51 ( V_343 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
static int F_141 ( struct V_1 * V_1 , unsigned int V_2 ,
const struct V_351 * V_352 )
{
int V_353 = 0 ;
unsigned int V_3 = 0 ;
unsigned int V_190 = F_2 ( V_1 , V_2 ) ;
for ( ; V_352 -> V_3 ; ++ V_352 ) {
if ( ! ( V_190 & V_352 -> V_3 ) )
continue;
if ( V_352 -> V_353 ) {
V_353 ++ ;
F_21 ( V_1 -> V_32 , L_54 , V_352 -> V_354 ,
V_190 & V_352 -> V_3 ) ;
} else if ( V_352 -> V_354 && F_142 () )
F_143 ( V_1 -> V_32 , L_54 , V_352 -> V_354 ,
V_190 & V_352 -> V_3 ) ;
if ( V_352 -> V_355 )
V_352 -> V_355 ( V_1 ) ;
V_3 |= V_352 -> V_3 ;
}
V_190 &= V_3 ;
if ( V_190 )
F_6 ( V_1 , V_2 , V_190 ) ;
return V_353 ;
}
static void F_144 ( struct V_1 * V_1 )
{
static const struct V_351 V_356 [] = {
{ V_357 , L_55 , - 1 , 1 } ,
{ V_358 , L_56 , - 1 , 1 } ,
{ V_359 , L_57 , - 1 , 1 } ,
{ V_360 , L_58 , - 1 , 1 } ,
{ V_361 , L_59 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_362 [] = {
{ V_363 , L_60 , - 1 , 1 } ,
{ V_364 , L_61 , - 1 , 1 } ,
{ V_365 , L_62 , - 1 , 1 } ,
{ V_366 , L_63 , - 1 , 1 } ,
{ V_367 , L_64 , - 1 , 1 } ,
{ V_368 , L_65 , - 1 , 1 } ,
{ V_369 , L_66 , - 1 , 1 } ,
{ V_370 , L_67 , - 1 , 1 } ,
{ V_371 , L_68 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_372 [] = {
{ V_373 , L_69 , - 1 , 1 } ,
{ V_374 , L_70 , - 1 , 1 } ,
{ V_375 , L_71 , - 1 , 1 } ,
{ V_376 , L_72 , - 1 , 1 } ,
{ V_377 , L_73 , - 1 , 1 } ,
{ V_378 , L_74 , - 1 , 1 } ,
{ V_379 , L_75 , - 1 , 1 } ,
{ V_380 , L_76 , - 1 , 1 } ,
{ V_381 , L_77 , - 1 , 1 } ,
{ V_382 , L_78 , - 1 , 1 } ,
{ V_383 , L_79 , - 1 , 1 } ,
{ V_384 , L_80 , - 1 , 1 } ,
{ V_385 , L_81 , - 1 , 1 } ,
{ V_386 , L_82 , - 1 , 1 } ,
{ V_387 , L_83 , - 1 , 1 } ,
{ V_388 , L_84 , - 1 , 1 } ,
{ V_389 , L_85 , - 1 , 1 } ,
{ V_390 , L_86 , - 1 , 1 } ,
{ V_391 , L_87 , - 1 , 1 } ,
{ V_392 , L_88 , - 1 , 1 } ,
{ V_393 , L_89 , - 1 , 1 } ,
{ V_394 , L_90 , - 1 , 1 } ,
{ V_395 , L_91 , - 1 , 1 } ,
{ V_396 , L_92 , - 1 , 1 } ,
{ V_397 , L_93 , - 1 , 1 } ,
{ V_398 , L_94 , - 1 , 1 } ,
{ V_399 , L_95 , - 1 , 1 } ,
{ V_400 , L_96 , - 1 , 1 } ,
{ V_401 , L_97 , - 1 , 1 } ,
{ V_402 , L_98 ,
- 1 , 0 } ,
{ 0 }
} ;
static struct V_351 V_403 [] = {
{ V_404 , L_99 ,
- 1 , 1 } ,
{ V_405 , L_100 , - 1 , 1 } ,
{ V_406 , L_101 , - 1 , 1 } ,
{ V_376 , L_72 , - 1 , 1 } ,
{ V_377 , L_73 , - 1 , 1 } ,
{ V_378 , L_74 , - 1 , 1 } ,
{ V_379 , L_75 , - 1 , 1 } ,
{ V_407 , L_102 ,
- 1 , 1 } ,
{ V_408 , L_103 ,
- 1 , 1 } ,
{ V_382 , L_78 , - 1 , 1 } ,
{ V_409 , L_104 , - 1 , 1 } ,
{ V_384 , L_80 , - 1 , 1 } ,
{ V_385 , L_81 , - 1 , 1 } ,
{ V_410 , L_105 ,
- 1 , 1 } ,
{ V_387 , L_83 , - 1 , 1 } ,
{ V_388 , L_84 , - 1 , 1 } ,
{ V_411 , L_85 , - 1 , 1 } ,
{ V_390 , L_86 , - 1 , 1 } ,
{ V_391 , L_87 , - 1 , 1 } ,
{ V_392 , L_88 , - 1 , 1 } ,
{ V_393 , L_89 , - 1 , 1 } ,
{ V_412 , L_90 , - 1 , 1 } ,
{ V_413 , L_106 , - 1 , 1 } ,
{ V_396 , L_92 , - 1 , 1 } ,
{ V_414 , L_107 ,
- 1 , 1 } ,
{ V_415 , L_108 ,
- 1 , 1 } ,
{ V_399 , L_109 , - 1 , 1 } ,
{ V_416 , L_110 , - 1 , 1 } ,
{ V_417 , L_111 , - 1 , 1 } ,
{ V_418 , L_112 , - 1 , 0 } ,
{ 0 }
} ;
int V_419 ;
if ( F_13 ( V_1 -> V_20 . V_21 ) )
V_419 = F_141 ( V_1 ,
V_420 ,
V_356 ) +
F_141 ( V_1 ,
V_421 ,
V_362 ) +
F_141 ( V_1 , V_422 ,
V_372 ) ;
else
V_419 = F_141 ( V_1 , V_422 ,
V_403 ) ;
if ( V_419 )
F_145 ( V_1 ) ;
}
static void F_146 ( struct V_1 * V_1 )
{
static const struct V_351 V_423 [] = {
{ 0x3fffffff , L_113 , - 1 , 1 } ,
{ V_424 , L_114 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_1 , V_425 , V_423 ) )
F_145 ( V_1 ) ;
}
static void F_147 ( struct V_1 * V_1 )
{
T_3 V_11 ;
T_1 V_426 ;
static const struct V_351 V_427 [] = {
{ V_428 ,
L_115 , - 1 , 1 } ,
{ V_429 ,
L_116 , - 1 , 0 } ,
{ V_430 , L_117 , - 1 , 0 } ,
{ V_431 , NULL , - 1 , 0 , V_432 } ,
{ V_433 | V_434 ,
L_118 , - 1 , 0 } ,
{ V_435 , L_119 , - 1 ,
0 } ,
{ V_436 , L_120 , - 1 ,
0 } ,
{ V_437 , L_121 , - 1 ,
0 } ,
{ V_438 , L_122 , - 1 ,
0 } ,
{ V_439 ,
L_123 , - 1 , 0 } ,
{ V_440 , L_124 , - 1 , 0 } ,
{ V_441 , L_125 , - 1 , 0 } ,
{ 0 }
} ;
static struct V_351 V_442 [] = {
{ V_443 , NULL , - 1 , 0 , V_444 } ,
{ V_445 , NULL , - 1 , 0 , V_432 } ,
{ V_446 ,
L_126 , - 1 , 0 } ,
{ 0 }
} ;
V_11 = ( T_3 ) F_2 ( V_1 , V_447 ) |
( ( T_3 ) F_2 ( V_1 , V_448 ) << 32 ) ;
if ( V_11 ) {
F_21 ( V_1 -> V_32 , L_127 ,
( unsigned long long ) V_11 ) ;
F_6 ( V_1 , V_447 , V_11 ) ;
F_6 ( V_1 , V_448 , V_11 >> 32 ) ;
}
V_11 |= F_141 ( V_1 , V_449 , V_427 ) ;
if ( F_12 ( V_1 -> V_20 . V_21 ) <= V_22 )
V_11 |= F_141 ( V_1 , V_449 ,
V_442 ) ;
V_426 = F_2 ( V_1 , V_450 ) ;
if ( V_426 & V_451 ) {
F_15 ( V_1 -> V_32 , L_128 ,
F_148 ( V_426 ) ) ;
if ( V_426 & V_452 )
F_15 ( V_1 -> V_32 ,
L_129 ) ;
F_6 ( V_1 , V_450 , V_451 |
V_452 ) ;
}
if ( V_11 != 0 )
F_145 ( V_1 ) ;
}
static void F_149 ( struct V_1 * V_1 )
{
static const struct V_351 V_453 [] = {
{ V_454 , L_130 , - 1 , 1 } ,
{ V_455 , L_131 , - 1 , 1 } ,
{ V_456 , L_132 , - 1 , 1 } ,
{ V_457 , L_133 , - 1 , 1 } ,
{ V_458 , L_134 , - 1 , 1 } ,
{ V_459 , L_135 , - 1 , 1 } ,
{ V_460 , L_136 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_461 [] = {
{ V_462 , L_137 , - 1 , 1 } ,
{ V_463 , L_138 , - 1 , 1 } ,
{ V_464 , L_139 , - 1 , 1 } ,
{ V_465 , L_140 , - 1 , 1 } ,
{ V_466 , L_141 , - 1 , 1 } ,
{ V_467 , L_142 , - 1 , 1 } ,
{ V_468 , L_143 , - 1 , 1 } ,
{ V_469 , L_144 , - 1 , 1 } ,
{ V_470 , L_145 , - 1 , 1 } ,
{ V_471 , L_146 , - 1 , 1 } ,
{ V_472 , L_147 , - 1 , 1 } ,
{ V_473 , L_148 , - 1 , 1 } ,
{ V_474 , L_149 , - 1 , 1 } ,
{ V_475 , L_150 , - 1 , 1 } ,
{ V_476 , L_151 , - 1 , 1 } ,
{ V_477 , L_152 , - 1 , 1 } ,
{ V_478 , L_153 , - 1 , 1 } ,
{ V_479 , L_154 , - 1 , 1 } ,
{ V_480 , L_155 , - 1 , 1 } ,
{ V_481 , L_156 , - 1 , 1 } ,
{ V_482 , L_157 , - 1 , 1 } ,
{ V_483 , L_158 , - 1 , 1 } ,
{ V_484 , L_159 , - 1 , 1 } ,
{ V_485 , L_160 , - 1 , 1 } ,
{ V_486 , L_161 , - 1 , 1 } ,
{ V_487 , L_162 , - 1 , 1 } ,
{ V_488 , L_163 , - 1 , 1 } ,
{ V_489 , L_164 , - 1 , 1 } ,
{ 0 }
} ;
int V_419 ;
if ( F_2 ( V_1 , V_30 ) & V_31 )
F_14 ( V_1 ) ;
V_419 = F_141 ( V_1 , V_490 ,
V_453 ) +
F_141 ( V_1 , V_491 ,
V_461 ) ;
if ( V_419 )
F_145 ( V_1 ) ;
}
static void F_150 ( struct V_1 * V_1 )
{
static const struct V_351 V_492 [] = {
{ 0x1800000 , L_165 , - 1 , 1 } ,
{ 0x7fffff , L_166 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_1 , V_493 , V_492 ) )
F_145 ( V_1 ) ;
}
static void F_151 ( struct V_1 * V_1 )
{
static const struct V_351 V_494 [] = {
{ V_495 , L_167 , - 1 ,
0 } ,
{ V_496 , L_168 , - 1 ,
0 } ,
{ V_497 , L_169 , - 1 ,
0 } ,
{ V_498 , L_170 , - 1 ,
0 } ,
{ 0xfffffff , L_171 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_1 , V_499 , V_494 ) )
F_145 ( V_1 ) ;
}
static void F_152 ( struct V_1 * V_1 )
{
static const struct V_351 V_500 [] = {
{ V_501 , L_172 , - 1 , 1 } ,
{ V_502 , L_173 , - 1 , 1 } ,
{ V_503 , L_174 , - 1 , 1 } ,
{ V_504 , L_175 , - 1 , 1 } ,
{ V_505 , L_176 , - 1 , 1 } ,
{ V_506 , L_177 , - 1 , 1 } ,
{ V_507 , L_178 ,
- 1 , 1 } ,
{ V_508 , L_179 , - 1 , 1 } ,
{ V_509 , L_180 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_1 , V_510 , V_500 ) )
F_145 ( V_1 ) ;
}
static void F_153 ( struct V_1 * V_1 )
{
static const struct V_351 V_511 [] = {
{ V_512 , L_181 , - 1 , 1 } ,
{ V_513 , L_182 , - 1 , 1 } ,
{ V_514 , L_183 , - 1 , 1 } ,
{ V_507 , L_184 ,
- 1 , 1 } ,
{ V_515 , L_185 , - 1 , 1 } ,
{ V_516 , L_186 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_1 , V_517 , V_511 ) )
F_145 ( V_1 ) ;
}
static void F_154 ( struct V_1 * V_1 )
{
static const struct V_351 V_518 [] = {
{ V_519 , L_187 , - 1 , 1 } ,
{ V_520 , L_188 , - 1 , 1 } ,
{ V_521 , L_189 , - 1 , 1 } ,
{ V_522 , L_190 , - 1 , 1 } ,
{ V_523 , L_191 , - 1 , 1 } ,
{ V_524 , L_192 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_1 , V_525 , V_518 ) )
F_145 ( V_1 ) ;
}
static void F_155 ( struct V_1 * V_12 )
{
enum V_526 V_21 = F_12 ( V_12 -> V_20 . V_21 ) ;
static const struct V_351 V_527 [] = {
{ V_528 , L_193 , - 1 , 0 } ,
{ V_529 , L_194 , - 1 , 0 } ,
{ V_530 , L_195 , - 1 , 1 } ,
{ V_531 , L_196 , - 1 , 1 } ,
{ V_532 , L_197 , - 1 , 1 } ,
{ 0 }
} ;
static struct V_351 V_533 [] = {
{ V_534 , L_193 , - 1 , 0 } ,
{ V_535 , L_194 , - 1 , 0 } ,
{ V_536 , L_195 , - 1 , 1 } ,
{ V_537 , L_196 , - 1 , 1 } ,
{ V_538 , L_197 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_12 , V_539 ,
( V_21 <= V_22 ) ?
V_527 : V_533 ) )
F_145 ( V_12 ) ;
}
static void F_156 ( struct V_1 * V_1 )
{
static const struct V_351 V_540 [] = {
{ 0xffffff , L_198 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_541 [] = {
{ F_157 ( V_542 ) , L_199 , - 1 , 1 } ,
{ V_543 , L_200 , - 1 , 1 } ,
{ F_158 ( V_544 ) , L_201 ,
- 1 , 1 } ,
{ F_159 ( V_545 ) , L_202 ,
- 1 , 1 } ,
{ V_546 , L_203 , - 1 , 1 } ,
{ V_547 , L_204 , - 1 , 1 } ,
{ V_548 , L_205 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_549 [] = {
{ F_160 ( V_550 ) , L_206 , - 1 , 1 } ,
{ F_161 ( V_551 ) , L_207 ,
- 1 , 1 } ,
{ V_552 , L_208 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_553 [] = {
{ 0x1fffff , L_209 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_554 [] = {
{ 0xfffff , L_210 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_555 [] = {
{ 0xffffff , L_211 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_351 V_556 [] = {
{ V_557 , L_212 , - 1 , 1 } ,
{ V_558 , L_213 , - 1 , 1 } ,
{ V_559 , L_214 , - 1 , 1 } ,
{ 0 }
} ;
int V_419 ;
V_419 = F_141 ( V_1 , V_560 ,
V_540 ) +
F_141 ( V_1 , V_561 ,
V_541 ) +
F_141 ( V_1 , V_562 ,
V_549 ) +
F_141 ( V_1 , V_563 ,
V_553 ) +
F_141 ( V_1 , V_564 ,
V_554 ) +
F_141 ( V_1 , V_565 ,
V_555 ) +
F_141 ( V_1 , V_566 ,
V_556 ) ;
F_6 ( V_1 , V_567 , 0 ) ;
F_2 ( V_1 , V_567 ) ;
if ( V_419 )
F_145 ( V_1 ) ;
}
static void F_162 ( struct V_1 * V_1 , int V_70 )
{
static const char T_6 [ 4 ] [ 7 ] = { L_215 , L_216 , L_217 , L_218 } ;
unsigned int V_10 , V_568 , V_11 ;
if ( V_70 <= V_569 ) {
V_10 = F_163 ( V_570 , V_70 ) ;
V_568 = F_163 ( V_571 , V_70 ) ;
} else if ( V_70 == V_572 ) {
if ( F_13 ( V_1 -> V_20 . V_21 ) ) {
V_10 = V_573 ;
V_568 = V_574 ;
} else {
V_10 = V_575 ;
V_568 = V_576 ;
}
} else {
V_10 = F_164 ( V_575 , 1 ) ;
V_568 = F_164 ( V_576 , 1 ) ;
}
V_11 = F_2 ( V_1 , V_10 ) & V_577 ;
if ( V_11 & V_578 )
F_21 ( V_1 -> V_32 , L_219 ,
T_6 [ V_70 ] ) ;
if ( V_11 & V_579 ) {
T_1 V_580 = F_165 ( F_2 ( V_1 , V_568 ) ) ;
F_37 ( V_1 , V_70 ) ;
F_6 ( V_1 , V_568 , F_166 ( V_581 ) ) ;
if ( F_142 () )
F_143 ( V_1 -> V_32 ,
L_220 ,
V_580 , T_6 [ V_70 ] , V_580 > 1 ? L_221 : L_222 ) ;
}
if ( V_11 & V_582 )
F_21 ( V_1 -> V_32 ,
L_223 , T_6 [ V_70 ] ) ;
F_6 ( V_1 , V_10 , V_11 ) ;
if ( V_11 & ( V_578 | V_582 ) )
F_145 ( V_1 ) ;
}
static void F_167 ( struct V_1 * V_12 )
{
T_1 V_11 , V_190 = F_2 ( V_12 , V_583 ) ;
if ( V_190 & V_584 ) {
F_21 ( V_12 -> V_32 ,
L_224 ,
F_2 ( V_12 , V_585 ) ) ;
if ( F_113 ( V_12 -> V_20 . V_21 ) )
F_21 ( V_12 -> V_32 ,
L_224 ,
F_2 ( V_12 ,
V_586 ) ) ;
}
if ( V_190 & V_587 ) {
V_11 = F_2 ( V_12 , V_588 ) ;
F_21 ( V_12 -> V_32 , L_225
L_226 ,
F_168 ( V_11 ) ,
F_169 ( V_11 ) << 4 ) ;
}
F_6 ( V_12 , V_583 , V_190 ) ;
F_145 ( V_12 ) ;
}
static void F_170 ( struct V_1 * V_12 )
{
static const struct V_351 V_589 [] = {
{ V_590 , L_227 , - 1 , 1 } ,
{ V_591 , L_228 , - 1 , 1 } ,
{ V_592 , L_229 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_12 , V_593 , V_589 ) )
F_145 ( V_12 ) ;
}
static void F_171 ( struct V_1 * V_12 )
{
static const struct V_351 V_594 [] = {
{ V_595 , L_230 , - 1 , 1 } ,
{ V_596 , L_231 , - 1 , 1 } ,
{ V_597 , L_232 , - 1 , 1 } ,
{ V_598 , L_233 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_12 , V_599 , V_594 ) )
F_145 ( V_12 ) ;
}
static void F_172 ( struct V_1 * V_12 , int V_324 )
{
T_1 V_11 , V_600 ;
if ( F_13 ( V_12 -> V_20 . V_21 ) )
V_600 = F_173 ( V_324 , V_601 ) ;
else
V_600 = F_174 ( V_324 , V_602 ) ;
V_11 = F_2 ( V_12 , V_600 ) ;
V_11 &= V_597 | V_598 ;
if ( ! V_11 )
return;
if ( V_11 & V_597 )
F_21 ( V_12 -> V_32 , L_234 ,
V_324 ) ;
if ( V_11 & V_598 )
F_21 ( V_12 -> V_32 , L_235 ,
V_324 ) ;
F_6 ( V_12 , F_173 ( V_324 , V_601 ) , V_11 ) ;
F_145 ( V_12 ) ;
}
static void F_175 ( struct V_1 * V_12 )
{
static const struct V_351 V_603 [] = {
{ V_604 , L_236 , - 1 , 1 } ,
{ V_605 , L_237 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_141 ( V_12 , V_606 , V_603 ) )
F_145 ( V_12 ) ;
}
int F_176 ( struct V_1 * V_1 )
{
T_1 V_607 = F_2 ( V_1 , V_608 ) ;
if ( ! ( V_607 & V_609 ) )
return 0 ;
if ( V_607 & V_610 )
F_149 ( V_1 ) ;
if ( V_607 & V_611 )
F_156 ( V_1 ) ;
if ( V_607 & V_612 )
F_171 ( V_1 ) ;
if ( V_607 & V_613 )
F_175 ( V_1 ) ;
if ( V_607 & V_614 )
F_170 ( V_1 ) ;
if ( V_607 & V_615 )
F_172 ( V_1 , 0 ) ;
if ( V_607 & V_616 )
F_172 ( V_1 , 1 ) ;
if ( V_607 & V_617 )
F_172 ( V_1 , 2 ) ;
if ( V_607 & V_618 )
F_172 ( V_1 , 3 ) ;
if ( V_607 & V_619 )
F_144 ( V_1 ) ;
if ( V_607 & V_620 )
F_162 ( V_1 , V_572 ) ;
if ( F_113 ( V_1 -> V_20 . V_21 ) && ( V_607 & V_621 ) )
F_162 ( V_1 , V_94 ) ;
if ( V_607 & V_622 )
F_162 ( V_1 , V_623 ) ;
if ( V_607 & V_624 )
F_162 ( V_1 , V_569 ) ;
if ( V_607 & V_625 )
F_155 ( V_1 ) ;
if ( V_607 & V_626 )
F_146 ( V_1 ) ;
if ( V_607 & V_627 )
F_167 ( V_1 ) ;
if ( V_607 & V_628 )
F_152 ( V_1 ) ;
if ( V_607 & V_629 )
F_153 ( V_1 ) ;
if ( V_607 & V_630 )
F_150 ( V_1 ) ;
if ( V_607 & V_631 )
F_154 ( V_1 ) ;
if ( V_607 & V_632 )
F_147 ( V_1 ) ;
if ( V_607 & V_633 )
F_151 ( V_1 ) ;
F_6 ( V_1 , V_608 , V_607 & V_609 ) ;
( void ) F_2 ( V_1 , V_608 ) ;
return 1 ;
}
void F_177 ( struct V_1 * V_1 )
{
T_1 V_8 = 0 ;
T_1 V_634 = F_2 ( V_1 , V_635 ) ;
T_1 V_19 = F_12 ( V_1 -> V_20 . V_21 ) <= V_22 ?
F_178 ( V_634 ) : F_179 ( V_634 ) ;
if ( F_12 ( V_1 -> V_20 . V_21 ) <= V_22 )
V_8 = V_443 | V_446 | V_445 ;
F_6 ( V_1 , V_636 , V_428 |
V_429 | V_430 |
V_433 | V_440 |
V_434 | V_435 |
V_436 | V_437 |
V_438 | V_439 |
V_431 | V_441 | V_8 ) ;
F_6 ( V_1 , F_180 ( V_637 ) , V_638 ) ;
F_5 ( V_1 , V_639 , 0 , 1 << V_19 ) ;
}
void F_181 ( struct V_1 * V_1 )
{
T_1 V_634 = F_2 ( V_1 , V_635 ) ;
T_1 V_19 = F_12 ( V_1 -> V_20 . V_21 ) <= V_22 ?
F_178 ( V_634 ) : F_179 ( V_634 ) ;
F_6 ( V_1 , F_180 ( V_637 ) , 0 ) ;
F_5 ( V_1 , V_639 , 1 << V_19 , 0 ) ;
}
static int F_182 ( const V_68 * V_10 )
{
T_1 V_640 = ( ( T_1 ) V_10 [ 0 ] << 16 ) | ( ( T_1 ) V_10 [ 1 ] << 8 ) | V_10 [ 2 ] ;
T_1 V_641 = ( ( T_1 ) V_10 [ 3 ] << 16 ) | ( ( T_1 ) V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ;
V_640 ^= V_641 ;
V_640 ^= ( V_640 >> 12 ) ;
V_640 ^= ( V_640 >> 6 ) ;
return V_640 & 0x3f ;
}
int F_183 ( struct V_1 * V_1 , int V_42 , unsigned int V_642 ,
int V_258 , int V_197 , const T_8 * V_643 , unsigned int V_644 )
{
int V_113 ;
const T_8 * V_304 = V_643 ;
const T_8 * V_645 = V_643 + V_644 ;
struct V_646 V_43 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_647 = F_51 ( F_52 ( V_648 ) |
V_117 | V_294 |
F_184 ( V_642 ) ) ;
V_43 . V_295 = F_51 ( F_53 ( V_43 ) ) ;
while ( V_197 > 0 ) {
int V_649 = F_75 ( V_197 , 32 ) ;
V_105 * V_650 = & V_43 . V_651 ;
V_43 . V_652 = F_185 ( V_649 ) ;
V_43 . V_653 = F_185 ( V_258 ) ;
V_258 += V_649 ;
V_197 -= V_649 ;
while ( V_649 > 0 ) {
unsigned int V_11 ;
V_11 = F_186 ( * V_304 ) ;
if ( ++ V_304 >= V_645 )
V_304 = V_643 ;
V_11 |= F_187 ( * V_304 ) ;
if ( ++ V_304 >= V_645 )
V_304 = V_643 ;
V_11 |= F_188 ( * V_304 ) ;
if ( ++ V_304 >= V_645 )
V_304 = V_643 ;
* V_650 ++ = F_51 ( V_11 ) ;
V_649 -= 3 ;
}
V_113 = F_56 ( V_1 , V_42 , & V_43 , sizeof( V_43 ) , NULL ) ;
if ( V_113 )
return V_113 ;
}
return 0 ;
}
int F_189 ( struct V_1 * V_1 , int V_42 , unsigned int V_654 ,
unsigned int V_655 )
{
struct V_656 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_657 = F_51 ( F_52 ( V_658 ) |
V_117 | V_294 ) ;
V_198 . V_295 = F_51 ( F_53 ( V_198 ) ) ;
if ( V_654 == V_659 ) {
V_198 . V_38 . V_660 . V_661 =
F_51 ( F_190 ( V_654 ) ) ;
} else if ( V_654 == V_662 ) {
V_198 . V_38 . V_663 . V_661 =
F_51 ( F_190 ( V_654 ) ) ;
V_198 . V_38 . V_663 . V_664 = F_51 ( V_655 ) ;
} else
return - V_56 ;
return F_56 ( V_1 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_191 ( struct V_1 * V_1 , int V_42 , unsigned int V_642 ,
unsigned int V_655 , unsigned int V_665 )
{
struct V_666 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_647 = F_51 ( F_52 ( V_667 ) |
V_117 | V_294 |
F_192 ( V_642 ) ) ;
V_198 . V_295 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_38 . V_663 . V_668 = F_51 ( V_655 |
F_193 ( V_665 ) ) ;
return F_56 ( V_1 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
static int F_194 ( struct V_1 * V_12 , int V_669 , T_1 * V_8 )
{
F_6 ( V_12 , V_670 , 0xfff00000 | V_669 ) ;
return F_1 ( V_12 , V_670 , V_671 , 1 ,
5 , 0 , V_8 ) ;
}
int F_195 ( struct V_1 * V_1 , T_8 * V_672 )
{
T_1 V_8 ;
int V_48 , V_113 ;
for ( V_48 = 0 ; V_48 < V_673 / 2 ; ++ V_48 ) {
V_113 = F_194 ( V_1 , V_48 , & V_8 ) ;
if ( V_113 )
return V_113 ;
* V_672 ++ = F_196 ( V_8 ) ;
* V_672 ++ = F_197 ( V_8 ) ;
}
return 0 ;
}
static unsigned int F_198 ( struct V_1 * V_12 )
{
return ( V_12 -> V_655 & V_674 ) || ! V_12 -> V_675 ;
}
static void F_199 ( struct V_1 * V_12 , T_1 * V_15 , unsigned int V_16 ,
unsigned int V_676 , unsigned int V_677 )
{
int V_113 , V_48 ;
int V_43 = V_678 ;
struct V_111 V_198 ;
for ( V_48 = 0 ; V_48 < V_16 ; V_48 ++ ) {
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_115 = F_51 ( F_52 ( V_116 ) |
V_117 |
( V_677 ? V_118 :
V_294 ) |
F_50 ( V_43 ) ) ;
V_198 . V_119 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_38 . V_679 . V_10 = F_51 ( V_676 + V_48 ) ;
V_198 . V_38 . V_679 . V_8 = V_677 ? 0 : F_51 ( V_15 [ V_48 ] ) ;
V_113 = F_56 ( V_12 , V_12 -> V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
if ( ! V_113 && V_677 )
V_15 [ V_48 ] = F_22 ( V_198 . V_38 . V_679 . V_8 ) ;
}
}
void F_200 ( struct V_1 * V_12 , T_1 * V_680 )
{
if ( F_198 ( V_12 ) )
F_199 ( V_12 , V_680 , 10 , V_681 , 1 ) ;
else
F_7 ( V_12 , V_682 , V_683 , V_680 , 10 ,
V_681 ) ;
}
void F_201 ( struct V_1 * V_12 , const T_1 * V_680 , int V_70 )
{
V_68 V_684 = 16 ;
T_1 V_685 = F_2 ( V_12 , V_686 ) ;
if ( ( F_12 ( V_12 -> V_20 . V_21 ) > V_22 ) &&
( V_685 & V_687 ) && ( F_202 ( V_685 ) == 3 ) )
V_684 = 32 ;
if ( F_198 ( V_12 ) )
F_199 ( V_12 , ( void * ) V_680 , 10 , V_681 , 0 ) ;
else
F_8 ( V_12 , V_682 , V_683 , V_680 , 10 ,
V_681 ) ;
if ( V_70 >= 0 && V_70 < V_684 ) {
if ( V_684 > 16 )
F_6 ( V_12 , V_686 ,
F_203 ( V_70 >> 4 ) |
F_204 ( V_70 ) | V_688 ) ;
else
F_6 ( V_12 , V_686 ,
F_205 ( V_70 ) | V_688 ) ;
}
}
void F_206 ( struct V_1 * V_1 , unsigned int V_689 ,
T_1 * V_7 )
{
if ( F_198 ( V_1 ) )
F_199 ( V_1 , V_7 , 1 ,
V_690 + V_689 , 1 ) ;
else
F_7 ( V_1 , V_682 , V_683 ,
V_7 , 1 , V_690 + V_689 ) ;
}
void F_207 ( struct V_1 * V_1 , unsigned int V_689 ,
T_1 * V_691 , T_1 * V_692 )
{
T_1 V_685 , V_3 , V_125 ;
if ( F_12 ( V_1 -> V_20 . V_21 ) <= V_22 ) {
V_3 = F_208 ( V_693 ) ;
V_125 = F_208 ( V_689 ) ;
} else {
V_3 = F_204 ( V_694 ) ;
V_125 = F_204 ( V_689 ) ;
}
V_685 = F_2 ( V_1 , V_686 ) ;
V_685 &= ~ ( V_695 | V_696 | V_688 | V_3 ) ;
V_685 |= V_125 | V_697 ;
F_6 ( V_1 , V_686 , V_685 ) ;
if ( F_198 ( V_1 ) ) {
F_199 ( V_1 , V_691 , 1 , V_698 , 1 ) ;
F_199 ( V_1 , V_692 , 1 , V_699 , 1 ) ;
} else {
F_7 ( V_1 , V_682 , V_683 ,
V_691 , 1 , V_698 ) ;
F_7 ( V_1 , V_682 , V_683 ,
V_692 , 1 , V_699 ) ;
}
}
T_1 F_209 ( struct V_1 * V_1 )
{
T_1 V_700 ;
if ( F_198 ( V_1 ) )
F_199 ( V_1 , & V_700 , 1 , V_701 , 1 ) ;
else
F_7 ( V_1 , V_682 , V_683 ,
& V_700 , 1 , V_701 ) ;
return V_700 ;
}
T_1 F_210 ( struct V_1 * V_1 )
{
T_1 V_702 ;
if ( F_198 ( V_1 ) )
F_199 ( V_1 , & V_702 , 1 , V_703 , 1 ) ;
else
F_7 ( V_1 , V_682 , V_683 ,
& V_702 , 1 , V_703 ) ;
return V_702 ;
}
void F_211 ( struct V_1 * V_12 , struct V_704 * V_705 ,
struct V_704 * V_706 )
{
T_1 V_8 [ V_707 - V_708 + 1 ] ;
#define F_212 ( V_40 ) ((TP_MIB_TCP_##x##_A) - TP_MIB_TCP_OUT_RST_A)
#define F_213 ( V_40 ) val[STAT_IDX(x)]
#define F_214 ( V_40 ) (((u64)STAT(x##_HI) << 32) | STAT(x##_LO))
if ( V_705 ) {
F_7 ( V_12 , V_709 , V_710 , V_8 ,
F_30 ( V_8 ) , V_708 ) ;
V_705 -> V_711 = F_213 ( V_712 ) ;
V_705 -> V_713 = F_214 ( V_714 ) ;
V_705 -> V_715 = F_214 ( V_716 ) ;
V_705 -> V_717 = F_214 ( V_718 ) ;
}
if ( V_706 ) {
F_7 ( V_12 , V_709 , V_710 , V_8 ,
F_30 ( V_8 ) , V_719 ) ;
V_706 -> V_711 = F_213 ( V_712 ) ;
V_706 -> V_713 = F_214 ( V_714 ) ;
V_706 -> V_715 = F_214 ( V_716 ) ;
V_706 -> V_717 = F_214 ( V_718 ) ;
}
#undef F_214
#undef F_213
#undef F_212
}
void F_215 ( struct V_1 * V_12 , struct V_720 * V_721 )
{
int V_722 = V_12 -> V_20 . V_723 . V_722 ;
F_7 ( V_12 , V_709 , V_710 ,
V_721 -> V_724 , V_722 , V_725 ) ;
F_7 ( V_12 , V_709 , V_710 ,
V_721 -> V_726 , V_722 , V_727 ) ;
F_7 ( V_12 , V_709 , V_710 ,
V_721 -> V_728 , V_722 , V_729 ) ;
F_7 ( V_12 , V_709 , V_710 ,
V_721 -> V_730 , V_722 , V_731 ) ;
F_7 ( V_12 , V_709 , V_710 ,
V_721 -> V_732 , V_722 , V_733 ) ;
F_7 ( V_12 , V_709 , V_710 ,
V_721 -> V_734 , V_722 , V_735 ) ;
F_7 ( V_12 , V_709 , V_710 ,
V_721 -> V_736 , V_722 , V_737 ) ;
F_7 ( V_12 , V_709 , V_710 ,
V_721 -> V_738 , V_722 , V_739 ) ;
F_7 ( V_12 , V_709 , V_710 ,
& V_721 -> V_740 , 2 , V_741 ) ;
}
void F_216 ( struct V_1 * V_12 , struct V_742 * V_721 )
{
int V_722 = V_12 -> V_20 . V_723 . V_722 ;
F_7 ( V_12 , V_709 , V_710 , V_721 -> V_18 ,
V_722 , V_743 ) ;
F_7 ( V_12 , V_709 , V_710 , V_721 -> V_304 ,
V_722 , V_744 ) ;
}
void F_217 ( struct V_1 * V_12 , struct V_745 * V_721 )
{
F_7 ( V_12 , V_709 , V_710 , & V_721 -> V_746 ,
2 , V_747 ) ;
}
void F_218 ( struct V_1 * V_12 , unsigned int V_70 ,
struct V_748 * V_721 )
{
T_1 V_8 [ 2 ] ;
F_7 ( V_12 , V_709 , V_710 , & V_721 -> V_749 ,
1 , V_750 + V_70 ) ;
F_7 ( V_12 , V_709 , V_710 , & V_721 -> V_751 ,
1 , V_752 + V_70 ) ;
F_7 ( V_12 , V_709 , V_710 , V_8 ,
2 , V_753 + 2 * V_70 ) ;
V_721 -> V_754 = ( ( T_3 ) V_8 [ 0 ] << 32 ) | V_8 [ 1 ] ;
}
void F_219 ( struct V_1 * V_12 , struct V_755 * V_721 )
{
T_1 V_8 [ 4 ] ;
F_7 ( V_12 , V_709 , V_710 , V_8 , 4 ,
V_756 ) ;
V_721 -> V_757 = V_8 [ 0 ] ;
V_721 -> V_758 = V_8 [ 1 ] ;
V_721 -> V_759 = ( ( T_3 ) V_8 [ 2 ] << 32 ) | V_8 [ 3 ] ;
}
void F_220 ( struct V_1 * V_12 , T_8 * V_760 , V_68 * V_761 )
{
T_1 V_11 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_762 ; ++ V_48 ) {
F_6 ( V_12 , V_763 ,
F_221 ( 0xff ) | F_222 ( V_48 ) ) ;
V_11 = F_2 ( V_12 , V_763 ) ;
V_760 [ V_48 ] = F_223 ( V_11 ) ;
if ( V_761 )
V_761 [ V_48 ] = F_224 ( V_11 ) ;
}
}
void F_225 ( struct V_1 * V_12 , T_8 V_764 [ V_762 ] [ V_765 ] )
{
unsigned int V_766 , V_767 ;
for ( V_766 = 0 ; V_766 < V_762 ; ++ V_766 )
for ( V_767 = 0 ; V_767 < V_765 ; ++ V_767 ) {
F_6 ( V_12 , V_768 ,
F_226 ( 0xffff ) | ( V_766 << 5 ) | V_767 ) ;
V_764 [ V_766 ] [ V_767 ] = ( T_8 ) F_2 ( V_12 ,
V_768 ) & 0x1fff ;
}
}
void F_227 ( struct V_1 * V_12 , unsigned int V_10 ,
unsigned int V_3 , unsigned int V_8 )
{
F_6 ( V_12 , V_682 , V_10 ) ;
V_8 |= F_2 ( V_12 , V_683 ) & ~ V_3 ;
F_6 ( V_12 , V_683 , V_8 ) ;
}
static void F_228 ( unsigned short * V_640 , unsigned short * V_641 )
{
V_640 [ 0 ] = V_640 [ 1 ] = V_640 [ 2 ] = V_640 [ 3 ] = V_640 [ 4 ] = V_640 [ 5 ] = V_640 [ 6 ] = V_640 [ 7 ] = V_640 [ 8 ] = 1 ;
V_640 [ 9 ] = 2 ;
V_640 [ 10 ] = 3 ;
V_640 [ 11 ] = 4 ;
V_640 [ 12 ] = 5 ;
V_640 [ 13 ] = 6 ;
V_640 [ 14 ] = 7 ;
V_640 [ 15 ] = 8 ;
V_640 [ 16 ] = 9 ;
V_640 [ 17 ] = 10 ;
V_640 [ 18 ] = 14 ;
V_640 [ 19 ] = 17 ;
V_640 [ 20 ] = 21 ;
V_640 [ 21 ] = 25 ;
V_640 [ 22 ] = 30 ;
V_640 [ 23 ] = 35 ;
V_640 [ 24 ] = 45 ;
V_640 [ 25 ] = 60 ;
V_640 [ 26 ] = 80 ;
V_640 [ 27 ] = 100 ;
V_640 [ 28 ] = 200 ;
V_640 [ 29 ] = 300 ;
V_640 [ 30 ] = 400 ;
V_640 [ 31 ] = 500 ;
V_641 [ 0 ] = V_641 [ 1 ] = V_641 [ 2 ] = V_641 [ 3 ] = V_641 [ 4 ] = V_641 [ 5 ] = V_641 [ 6 ] = V_641 [ 7 ] = V_641 [ 8 ] = 0 ;
V_641 [ 9 ] = V_641 [ 10 ] = 1 ;
V_641 [ 11 ] = V_641 [ 12 ] = 2 ;
V_641 [ 13 ] = V_641 [ 14 ] = V_641 [ 15 ] = V_641 [ 16 ] = 3 ;
V_641 [ 17 ] = V_641 [ 18 ] = V_641 [ 19 ] = V_641 [ 20 ] = V_641 [ 21 ] = 4 ;
V_641 [ 22 ] = V_641 [ 23 ] = V_641 [ 24 ] = V_641 [ 25 ] = V_641 [ 26 ] = V_641 [ 27 ] = 5 ;
V_641 [ 28 ] = V_641 [ 29 ] = 6 ;
V_641 [ 30 ] = V_641 [ 31 ] = 7 ;
}
void F_229 ( struct V_1 * V_12 , const unsigned short * V_760 ,
const unsigned short * V_769 , const unsigned short * V_770 )
{
static const unsigned int V_771 [ V_765 ] = {
2 , 6 , 10 , 14 , 20 , 28 , 40 , 56 , 80 , 112 , 160 , 224 , 320 , 448 , 640 ,
896 , 1281 , 1792 , 2560 , 3584 , 5120 , 7168 , 10240 , 14336 , 20480 ,
28672 , 40960 , 57344 , 81920 , 114688 , 163840 , 229376
} ;
unsigned int V_48 , V_767 ;
for ( V_48 = 0 ; V_48 < V_762 ; ++ V_48 ) {
unsigned int V_766 = V_760 [ V_48 ] ;
unsigned int V_772 = F_230 ( V_766 ) ;
if ( ! ( V_766 & ( ( 1 << V_772 ) >> 2 ) ) )
V_772 -- ;
F_6 ( V_12 , V_763 , F_221 ( V_48 ) |
F_231 ( V_772 ) | F_222 ( V_766 ) ) ;
for ( V_767 = 0 ; V_767 < V_765 ; ++ V_767 ) {
unsigned int V_773 ;
V_773 = F_232 ( ( ( V_766 - 40 ) * V_769 [ V_767 ] ) / V_771 [ V_767 ] ,
V_774 ) ;
F_6 ( V_12 , V_768 , ( V_48 << 21 ) |
( V_767 << 16 ) | ( V_770 [ V_767 ] << 13 ) | V_773 ) ;
}
}
}
static T_3 F_233 ( struct V_1 * V_12 , unsigned int V_775 )
{
T_3 V_11 = V_775 * V_12 -> V_20 . V_157 . V_182 ;
return V_11 * 62 + V_11 / 2 ;
}
void F_234 ( struct V_1 * V_12 , T_3 * V_776 , T_3 * V_777 )
{
T_1 V_11 ;
V_11 = F_2 ( V_12 , V_778 ) ;
V_776 [ 0 ] = F_233 ( V_12 , F_235 ( V_11 ) ) ;
V_776 [ 1 ] = F_233 ( V_12 , F_236 ( V_11 ) ) ;
if ( V_12 -> V_20 . V_723 . V_722 == V_779 ) {
V_776 [ 2 ] = F_233 ( V_12 , F_237 ( V_11 ) ) ;
V_776 [ 3 ] = F_233 ( V_12 , F_238 ( V_11 ) ) ;
}
V_11 = F_2 ( V_12 , V_780 ) ;
V_777 [ 0 ] = F_233 ( V_12 , F_239 ( V_11 ) ) ;
V_777 [ 1 ] = F_233 ( V_12 , F_240 ( V_11 ) ) ;
if ( V_12 -> V_20 . V_723 . V_722 == V_779 ) {
V_777 [ 2 ] = F_233 ( V_12 , F_241 ( V_11 ) ) ;
V_777 [ 3 ] = F_233 ( V_12 , F_242 ( V_11 ) ) ;
}
}
int F_243 ( struct V_1 * V_12 , const struct V_781 * V_782 ,
int V_70 , int V_150 )
{
int V_48 , V_783 = V_70 * 4 ;
T_1 V_14 , V_784 , V_303 ;
T_1 V_785 = V_786 ;
if ( ! V_150 ) {
F_6 ( V_12 , V_787 + V_783 , 0 ) ;
return 0 ;
}
V_303 = F_2 ( V_12 , V_788 ) ;
if ( V_303 & V_786 ) {
if ( V_782 -> V_789 > ( ( 10 * 1024 / 4 ) - ( 2 * 8 ) ) )
return - V_56 ;
} else {
V_785 = 0 ;
if ( V_782 -> V_789 > 9600 || V_70 )
return - V_56 ;
}
if ( V_782 -> V_324 > ( F_13 ( V_12 -> V_20 . V_21 ) ? 11 : 19 ) || V_782 -> V_790 > 1 ||
V_782 -> V_791 > V_792 || V_782 -> V_793 > V_794 ||
V_782 -> V_795 > V_796 )
return - V_56 ;
F_6 ( V_12 , V_787 + V_783 , 0 ) ;
V_70 *= ( V_797 - V_798 ) ;
V_14 = V_798 + V_70 ;
V_784 = V_799 + V_70 ;
for ( V_48 = 0 ; V_48 < V_800 / 4 ; V_48 ++ , V_14 += 4 , V_784 += 4 ) {
F_6 ( V_12 , V_14 , V_782 -> V_125 [ V_48 ] ) ;
F_6 ( V_12 , V_784 , ~ V_782 -> V_3 [ V_48 ] ) ;
}
F_6 ( V_12 , V_801 + V_783 ,
F_244 ( V_782 -> V_789 ) |
F_245 ( V_782 -> V_795 ) ) ;
F_6 ( V_12 , V_787 + V_783 ,
F_246 ( V_782 -> V_793 ) | F_247 ( V_782 -> V_791 ) |
( F_13 ( V_12 -> V_20 . V_21 ) ?
F_248 ( V_782 -> V_324 ) | V_802 | F_249 ( V_782 -> V_790 ) :
F_250 ( V_782 -> V_324 ) | V_803 |
F_251 ( V_782 -> V_790 ) ) ) ;
return 0 ;
}
void F_252 ( struct V_1 * V_12 , struct V_781 * V_782 , int V_70 ,
int * V_804 )
{
T_1 V_805 , V_806 ;
int V_48 , V_783 = V_70 * 4 ;
T_1 V_14 , V_784 ;
V_805 = F_2 ( V_12 , V_787 + V_783 ) ;
V_806 = F_2 ( V_12 , V_801 + V_783 ) ;
if ( F_13 ( V_12 -> V_20 . V_21 ) ) {
* V_804 = ! ! ( V_805 & V_802 ) ;
V_782 -> V_324 = F_253 ( V_805 ) ;
V_782 -> V_790 = ! ! ( V_805 & V_807 ) ;
} else {
* V_804 = ! ! ( V_805 & V_803 ) ;
V_782 -> V_324 = F_254 ( V_805 ) ;
V_782 -> V_790 = ! ! ( V_805 & V_808 ) ;
}
V_782 -> V_789 = F_255 ( V_806 ) ;
V_782 -> V_795 = F_256 ( V_806 ) ;
V_782 -> V_793 = F_257 ( V_805 ) ;
V_782 -> V_791 = F_258 ( V_805 ) ;
V_783 = ( V_797 - V_798 ) * V_70 ;
V_14 = V_798 + V_783 ;
V_784 = V_799 + V_783 ;
for ( V_48 = 0 ; V_48 < V_800 / 4 ; V_48 ++ , V_14 += 4 , V_784 += 4 ) {
V_782 -> V_3 [ V_48 ] = ~ F_2 ( V_12 , V_784 ) ;
V_782 -> V_125 [ V_48 ] = F_2 ( V_12 , V_14 ) & V_782 -> V_3 [ V_48 ] ;
}
}
void F_259 ( struct V_1 * V_12 , T_1 V_580 [] , T_3 V_809 [] )
{
int V_48 ;
T_1 V_125 [ 2 ] ;
for ( V_48 = 0 ; V_48 < V_810 ; V_48 ++ ) {
F_6 ( V_12 , V_811 , V_48 + 1 ) ;
V_580 [ V_48 ] = F_2 ( V_12 , V_812 ) ;
if ( F_13 ( V_12 -> V_20 . V_21 ) ) {
V_809 [ V_48 ] = F_19 ( V_12 , V_813 ) ;
} else {
F_7 ( V_12 , V_814 ,
V_815 , V_125 , 2 ,
V_816 ) ;
V_809 [ V_48 ] = ( ( ( T_3 ) V_125 [ 0 ] << 32 ) | V_125 [ 1 ] ) ;
}
}
}
void F_260 ( struct V_1 * V_12 , T_1 V_580 [] , T_3 V_809 [] )
{
int V_48 ;
T_1 V_125 [ 2 ] ;
for ( V_48 = 0 ; V_48 < V_810 ; V_48 ++ ) {
F_6 ( V_12 , V_817 , V_48 + 1 ) ;
V_580 [ V_48 ] = F_2 ( V_12 , V_818 ) ;
if ( F_13 ( V_12 -> V_20 . V_21 ) ) {
V_809 [ V_48 ] = F_19 ( V_12 , V_819 ) ;
} else {
F_7 ( V_12 , V_820 ,
V_821 , V_125 , 2 ,
V_822 ) ;
V_809 [ V_48 ] = ( ( ( T_3 ) V_125 [ 0 ] << 32 ) | V_125 [ 1 ] ) ;
}
}
}
unsigned int F_261 ( struct V_1 * V_12 , int V_70 )
{
T_1 V_197 = F_262 ( F_2 ( V_12 , V_823 ) ) ;
if ( V_197 == 0 )
return V_70 == 0 ? 0xf : 0 ;
if ( V_197 == 1 )
return V_70 < 2 ? ( 3 << ( 2 * V_70 ) ) : 0 ;
return 1 << V_70 ;
}
const char * F_263 ( enum V_824 V_825 )
{
static const char * const V_826 [] = {
L_238 ,
L_239 ,
L_240 ,
L_241 ,
L_242 ,
L_243 ,
L_244 ,
L_245 ,
L_246 ,
L_247 ,
L_248 ,
L_249 ,
L_250 ,
L_251 ,
L_252 ,
L_253 ,
} ;
if ( V_825 < F_30 ( V_826 ) )
return V_826 [ V_825 ] ;
return L_254 ;
}
void F_264 ( struct V_1 * V_12 , int V_70 ,
struct V_827 * V_828 ,
struct V_827 * V_82 )
{
T_3 * V_829 , * V_830 ;
int V_48 ;
F_265 ( V_12 , V_70 , V_828 ) ;
for ( V_48 = 0 , V_829 = ( T_3 * ) V_828 , V_830 = ( T_3 * ) V_82 ;
V_48 < ( sizeof( struct V_827 ) / sizeof( T_3 ) ) ;
V_48 ++ , V_829 ++ , V_830 ++ )
* V_829 -= * V_830 ;
}
void F_265 ( struct V_1 * V_12 , int V_70 , struct V_827 * V_51 )
{
T_1 V_831 = F_261 ( V_12 , V_70 ) ;
#define F_266 ( T_6 ) \
t4_read_reg64(adap, \
(is_t4(adap->params.chip) ? PORT_REG(idx, MPS_PORT_STAT_##name##_L) : \
T5_PORT_REG(idx, MPS_PORT_STAT_##name##_L)))
#define F_267 ( T_6 ) t4_read_reg64(adap, MPS_STAT_##name##_L)
V_51 -> V_832 = F_266 ( V_833 ) ;
V_51 -> V_834 = F_266 ( V_835 ) ;
V_51 -> V_836 = F_266 ( V_837 ) ;
V_51 -> V_838 = F_266 ( V_839 ) ;
V_51 -> V_840 = F_266 ( V_841 ) ;
V_51 -> V_842 = F_266 ( V_843 ) ;
V_51 -> V_844 = F_266 ( V_845 ) ;
V_51 -> V_846 = F_266 ( V_847 ) ;
V_51 -> V_848 = F_266 ( V_849 ) ;
V_51 -> V_850 = F_266 ( V_851 ) ;
V_51 -> V_852 = F_266 ( V_853 ) ;
V_51 -> V_854 = F_266 ( V_855 ) ;
V_51 -> V_856 = F_266 ( V_857 ) ;
V_51 -> V_858 = F_266 ( V_859 ) ;
V_51 -> V_860 = F_266 ( V_861 ) ;
V_51 -> V_862 = F_266 ( V_863 ) ;
V_51 -> V_864 = F_266 ( V_865 ) ;
V_51 -> V_866 = F_266 ( V_867 ) ;
V_51 -> V_868 = F_266 ( V_869 ) ;
V_51 -> V_870 = F_266 ( V_871 ) ;
V_51 -> V_872 = F_266 ( V_873 ) ;
V_51 -> V_874 = F_266 ( V_875 ) ;
V_51 -> V_876 = F_266 ( V_877 ) ;
V_51 -> V_878 = F_266 ( V_879 ) ;
V_51 -> V_880 = F_266 ( V_881 ) ;
V_51 -> V_882 = F_266 ( V_883 ) ;
V_51 -> V_884 = F_266 ( V_885 ) ;
V_51 -> V_886 = F_266 ( V_887 ) ;
V_51 -> V_888 = F_266 ( V_889 ) ;
V_51 -> V_890 = F_266 ( V_891 ) ;
V_51 -> V_892 = F_266 ( V_893 ) ;
V_51 -> V_894 = F_266 ( V_895 ) ;
V_51 -> V_896 = F_266 ( V_897 ) ;
V_51 -> V_898 = F_266 ( V_899 ) ;
V_51 -> V_900 = F_266 ( V_901 ) ;
V_51 -> V_902 = F_266 ( V_903 ) ;
V_51 -> V_904 = F_266 ( V_905 ) ;
V_51 -> V_906 = F_266 ( V_907 ) ;
V_51 -> V_908 = F_266 ( V_909 ) ;
V_51 -> V_910 = F_266 ( V_911 ) ;
V_51 -> V_912 = F_266 ( V_913 ) ;
V_51 -> V_914 = F_266 ( V_915 ) ;
V_51 -> V_916 = F_266 ( V_917 ) ;
V_51 -> V_918 = F_266 ( V_919 ) ;
V_51 -> V_920 = F_266 ( V_921 ) ;
V_51 -> V_922 = F_266 ( V_923 ) ;
V_51 -> V_924 = F_266 ( V_925 ) ;
V_51 -> V_926 = F_266 ( V_927 ) ;
V_51 -> V_928 = F_266 ( V_929 ) ;
V_51 -> V_930 = F_266 ( V_931 ) ;
V_51 -> V_932 = ( V_831 & 1 ) ? F_267 ( V_933 ) : 0 ;
V_51 -> V_934 = ( V_831 & 2 ) ? F_267 ( V_935 ) : 0 ;
V_51 -> V_936 = ( V_831 & 4 ) ? F_267 ( V_937 ) : 0 ;
V_51 -> V_938 = ( V_831 & 8 ) ? F_267 ( V_939 ) : 0 ;
V_51 -> V_940 = ( V_831 & 1 ) ? F_267 ( V_941 ) : 0 ;
V_51 -> V_942 = ( V_831 & 2 ) ? F_267 ( V_943 ) : 0 ;
V_51 -> V_944 = ( V_831 & 4 ) ? F_267 ( V_945 ) : 0 ;
V_51 -> V_946 = ( V_831 & 8 ) ? F_267 ( V_947 ) : 0 ;
#undef F_266
#undef F_267
}
void F_268 ( struct V_1 * V_12 , int V_70 , struct V_948 * V_51 )
{
T_1 V_831 = F_261 ( V_12 , V_70 ) ;
#define F_266 ( T_6 ) \
t4_read_reg64(adap, \
(is_t4(adap->params.chip) ? \
PORT_REG(idx, MPS_PORT_STAT_LB_PORT_##name##_L) : \
T5_PORT_REG(idx, MPS_PORT_STAT_LB_PORT_##name##_L)))
#define F_267 ( T_6 ) t4_read_reg64(adap, MPS_STAT_##name##_L)
V_51 -> V_759 = F_266 ( V_949 ) ;
V_51 -> V_757 = F_266 ( V_950 ) ;
V_51 -> V_951 = F_266 ( V_952 ) ;
V_51 -> V_953 = F_266 ( V_954 ) ;
V_51 -> V_955 = F_266 ( V_956 ) ;
V_51 -> V_957 = F_266 ( ERROR ) ;
V_51 -> V_958 = F_266 ( 64B ) ;
V_51 -> V_959 = F_266 ( 65B_127B ) ;
V_51 -> V_960 = F_266 ( 128B_255B ) ;
V_51 -> V_961 = F_266 ( 256B_511B ) ;
V_51 -> V_962 = F_266 ( 512B_1023B ) ;
V_51 -> V_963 = F_266 ( 1024B_1518B ) ;
V_51 -> V_964 = F_266 ( 1519B_MAX ) ;
V_51 -> V_965 = F_266 ( V_966 ) ;
V_51 -> V_967 = ( V_831 & 1 ) ? F_267 ( V_968 ) : 0 ;
V_51 -> V_969 = ( V_831 & 2 ) ? F_267 ( V_970 ) : 0 ;
V_51 -> V_971 = ( V_831 & 4 ) ? F_267 ( V_972 ) : 0 ;
V_51 -> V_973 = ( V_831 & 8 ) ? F_267 ( V_974 ) : 0 ;
V_51 -> V_975 = ( V_831 & 1 ) ? F_267 ( V_976 ) : 0 ;
V_51 -> V_977 = ( V_831 & 2 ) ? F_267 ( V_978 ) : 0 ;
V_51 -> V_979 = ( V_831 & 4 ) ? F_267 ( V_980 ) : 0 ;
V_51 -> V_981 = ( V_831 & 8 ) ? F_267 ( V_982 ) : 0 ;
#undef F_266
#undef F_267
}
void F_269 ( unsigned int V_983 , struct V_984 * V_985 , int V_986 )
{
memset ( V_985 , 0 , sizeof( * V_985 ) ) ;
V_985 -> V_987 = F_51 ( F_270 ( V_988 ) ) ;
V_985 -> V_989 = F_51 ( F_271 ( sizeof( * V_985 ) / 16 ) ) ;
V_985 -> V_990 = F_51 ( F_272 ( V_983 ) |
F_273 ( V_986 < 0 ) ) ;
V_985 -> V_991 = F_51 ( V_992 ) ;
if ( V_986 >= 0 )
V_985 -> V_993 =
F_185 ( F_274 ( V_986 ) ) ;
}
int F_275 ( struct V_1 * V_12 , unsigned int V_42 ,
T_1 V_10 , T_1 V_8 )
{
T_1 V_110 ;
struct V_111 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_110 = F_50 ( V_994 ) ;
V_198 . V_115 = F_51 ( F_52 ( V_116 ) |
V_117 |
V_294 |
V_110 ) ;
V_198 . V_119 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_38 . V_679 . V_10 = F_51 ( V_10 ) ;
V_198 . V_38 . V_679 . V_8 = F_51 ( V_8 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_276 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_995 ,
unsigned int V_996 , unsigned int V_2 , T_8 * V_7 )
{
int V_113 ;
T_1 V_110 ;
struct V_111 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_110 = F_50 ( V_997 ) ;
V_198 . V_115 = F_51 ( F_52 ( V_116 ) |
V_117 | V_118 |
V_110 ) ;
V_198 . V_119 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_38 . V_998 . V_999 = F_185 ( F_277 ( V_995 ) |
F_278 ( V_996 ) ) ;
V_198 . V_38 . V_998 . V_1000 = F_185 ( V_2 ) ;
V_113 = F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
if ( V_113 == 0 )
* V_7 = F_116 ( V_198 . V_38 . V_998 . V_1001 ) ;
return V_113 ;
}
int F_279 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_995 ,
unsigned int V_996 , unsigned int V_2 , T_8 V_8 )
{
T_1 V_110 ;
struct V_111 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_110 = F_50 ( V_997 ) ;
V_198 . V_115 = F_51 ( F_52 ( V_116 ) |
V_117 | V_294 |
V_110 ) ;
V_198 . V_119 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_38 . V_998 . V_999 = F_185 ( F_277 ( V_995 ) |
F_278 ( V_996 ) ) ;
V_198 . V_38 . V_998 . V_1000 = F_185 ( V_2 ) ;
V_198 . V_38 . V_998 . V_1001 = F_185 ( V_8 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
void F_280 ( struct V_1 * V_1 , int V_248 )
{
static const char * const V_1002 [] = {
L_255 ,
L_256 ,
L_257 ,
L_258 ,
L_259 ,
L_260 ,
L_261 ,
L_262 ,
L_263 ,
L_264 ,
L_265 ,
L_266 ,
L_267 ,
L_268 ,
L_269 ,
L_270 ,
L_271 ,
L_272 ,
L_273 ,
L_274 ,
L_275 ,
L_276 ,
L_277 ,
L_278 ,
L_279 ,
L_280 ,
L_281 ,
L_282 ,
L_283 ,
L_284 ,
L_285 ,
L_286 ,
L_287 ,
L_288 ,
L_289 ,
} ;
static const char * const V_1003 [] = {
L_255 ,
L_290 ,
L_256 ,
L_257 ,
L_291 ,
L_259 ,
L_260 ,
L_261 ,
L_262 ,
L_264 ,
L_265 ,
L_292 ,
L_266 ,
L_267 ,
L_268 ,
L_269 ,
L_270 ,
L_271 ,
L_272 ,
L_273 ,
L_274 ,
L_275 ,
L_276 ,
L_277 ,
L_278 ,
L_279 ,
L_280 ,
L_281 ,
L_282 ,
L_283 ,
L_284 ,
L_285 ,
L_286 ,
} ;
static const T_1 V_1004 [] = {
V_1005 ,
V_1006 ,
V_1007 ,
} ;
const char * * V_1008 ;
int V_1009 ;
int V_48 ;
if ( F_13 ( V_1 -> V_20 . V_21 ) ) {
V_1008 = ( const char * * ) V_1002 ;
V_1009 = F_30 ( V_1002 ) ;
} else {
V_1008 = ( const char * * ) V_1003 ;
V_1009 = F_30 ( V_1003 ) ;
}
if ( V_248 < V_1009 )
F_38 ( V_1 , L_293 , V_1008 [ V_248 ] ) ;
else
F_38 ( V_1 , L_294 , V_248 ) ;
for ( V_48 = 0 ; V_48 < F_30 ( V_1004 ) ; V_48 ++ )
F_38 ( V_1 , L_295 ,
V_1004 [ V_48 ] , F_2 ( V_1 , V_1004 [ V_48 ] ) ) ;
}
int F_281 ( struct V_1 * V_12 , unsigned int V_42 )
{
int V_113 ;
T_1 V_110 ;
struct V_111 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_110 = F_50 ( V_1010 ) ;
V_198 . V_115 = F_51 ( F_52 ( V_116 ) |
V_117 | V_118 |
V_110 ) ;
V_198 . V_119 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_38 . V_1011 . V_1012 = F_51 ( V_1013 ) ;
V_113 = F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
return V_113 ;
}
int F_282 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_1014 ,
enum V_1015 V_1016 , enum V_247 * V_248 )
{
int V_113 ;
struct V_1017 V_198 ;
T_1 V_11 ;
unsigned int V_1018 ;
int V_1019 = V_1020 ;
V_1021:
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_283 ( V_198 , V_1022 , V_1023 ) ;
V_198 . V_1024 = F_51 (
F_284 ( V_1016 == V_1025 ) |
F_285 ( V_1016 == V_1026 ) |
F_286 ( V_1016 == V_1026 ?
V_42 : V_1027 ) |
F_287 ( V_1014 ) |
F_288 ( V_1028 ) |
V_1029 ) ;
V_113 = F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
if ( V_113 < 0 ) {
if ( ( V_113 == - V_63 || V_113 == - V_64 ) && V_1019 -- > 0 )
goto V_1021;
if ( F_2 ( V_12 , V_30 ) & V_31 )
F_14 ( V_12 ) ;
return V_113 ;
}
V_11 = F_22 ( V_198 . V_1024 ) ;
V_1018 = F_289 ( V_11 ) ;
if ( V_248 ) {
if ( V_11 & V_1030 )
* V_248 = V_1031 ;
else if ( V_11 & V_1032 )
* V_248 = V_1033 ;
else
* V_248 = V_254 ;
}
if ( ( V_11 & ( V_1030 | V_1032 ) ) == 0 &&
V_1018 != V_42 ) {
int V_1034 = V_1035 ;
for (; ; ) {
T_1 V_29 ;
F_31 ( 50 ) ;
V_1034 -= 50 ;
V_29 = F_2 ( V_12 , V_30 ) ;
if ( ! ( V_29 & ( V_31 | V_1036 ) ) ) {
if ( V_1034 <= 0 ) {
if ( V_1019 -- > 0 )
goto V_1021;
return - V_64 ;
}
continue;
}
if ( V_248 ) {
if ( V_29 & V_31 )
* V_248 = V_1031 ;
else if ( V_29 & V_1036 )
* V_248 = V_1033 ;
}
if ( V_1018 == V_1037 &&
( V_29 & V_1038 ) )
V_1018 = F_290 ( V_29 ) ;
break;
}
}
return V_1018 ;
}
int F_291 ( struct V_1 * V_12 , unsigned int V_42 )
{
struct V_1039 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_283 ( V_198 , V_1040 , V_1023 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_292 ( struct V_1 * V_12 , unsigned int V_42 )
{
struct V_1041 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_283 ( V_198 , V_1042 , V_1023 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_293 ( struct V_1 * V_12 , unsigned int V_42 , int V_249 )
{
struct V_1043 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_283 ( V_198 , V_1044 , V_1023 ) ;
V_198 . V_8 = F_51 ( V_249 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
static int F_294 ( struct V_1 * V_12 , unsigned int V_42 , int V_1045 )
{
int V_113 = 0 ;
if ( V_42 <= V_1037 ) {
struct V_1043 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_283 ( V_198 , V_1044 , V_1023 ) ;
V_198 . V_8 = F_51 ( V_1046 | V_1047 ) ;
V_198 . V_1048 = F_51 ( V_1049 ) ;
V_113 = F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
if ( V_113 == 0 || V_1045 ) {
F_5 ( V_12 , V_1050 , V_1051 , V_1051 ) ;
F_5 ( V_12 , V_30 , V_1052 ,
V_1052 ) ;
}
return V_113 ;
}
static int F_295 ( struct V_1 * V_12 , unsigned int V_42 , int V_249 )
{
if ( V_249 ) {
F_5 ( V_12 , V_30 , V_1052 , 0 ) ;
if ( V_42 <= V_1037 ) {
F_5 ( V_12 , V_1050 , V_1051 , 0 ) ;
F_31 ( 100 ) ;
if ( F_293 ( V_12 , V_42 ,
V_1046 | V_1047 ) == 0 )
return 0 ;
}
F_6 ( V_12 , V_1053 , V_1046 | V_1047 ) ;
F_31 ( 2000 ) ;
} else {
int V_49 ;
F_5 ( V_12 , V_1050 , V_1051 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_69 ; ) {
if ( ! ( F_2 ( V_12 , V_30 ) & V_1052 ) )
return 0 ;
F_31 ( 100 ) ;
V_49 += 100 ;
}
return - V_64 ;
}
return 0 ;
}
int F_109 ( struct V_1 * V_12 , unsigned int V_42 ,
const V_68 * V_244 , unsigned int V_44 , int V_1045 )
{
const struct V_206 * V_206 = ( const struct V_206 * ) V_244 ;
int V_249 , V_113 ;
if ( ! F_112 ( V_12 , V_206 ) )
return - V_56 ;
V_113 = F_294 ( V_12 , V_42 , V_1045 ) ;
if ( V_113 < 0 && ! V_1045 )
return V_113 ;
V_113 = F_115 ( V_12 , V_244 , V_44 ) ;
if ( V_113 < 0 )
return V_113 ;
V_249 = ( ( F_22 ( V_206 -> V_655 ) & V_1054 ) == 0 ) ;
return F_295 ( V_12 , V_42 , V_249 ) ;
}
int F_296 ( struct V_1 * V_12 , unsigned int V_1055 ,
unsigned int V_1056 )
{
unsigned int V_1057 = F_230 ( V_1055 ) - 1 ;
unsigned int V_1058 = V_1057 - 10 ;
unsigned int V_1059 = V_1056 > 64 ? 128 : 64 ;
unsigned int V_1060 = V_1056 < 32 ? 32 : V_1056 ;
unsigned int V_1061 = F_230 ( V_1060 ) - 1 ;
F_6 ( V_12 , V_1062 ,
F_297 ( V_1058 ) |
F_298 ( V_1058 ) |
F_299 ( V_1058 ) |
F_300 ( V_1058 ) |
F_301 ( V_1058 ) |
F_302 ( V_1058 ) |
F_303 ( V_1058 ) |
F_304 ( V_1058 ) ) ;
if ( F_13 ( V_12 -> V_20 . V_21 ) ) {
F_5 ( V_12 , V_1063 ,
F_305 ( V_1064 ) |
V_1065 ,
F_305 ( V_1061 -
V_1066 ) |
F_306 ( V_1059 != 64 ) ) ;
} else {
if ( V_1060 <= 32 ) {
V_1060 = 64 ;
V_1061 = 6 ;
}
F_5 ( V_12 , V_1063 ,
F_305 ( V_1064 ) |
V_1065 ,
F_305 ( V_1067 ) |
F_306 ( V_1059 != 64 ) ) ;
F_5 ( V_12 , V_1068 ,
F_307 ( V_1069 ) ,
F_307 ( V_1061 -
V_1070 ) ) ;
}
F_6 ( V_12 , V_1071 , V_1055 ) ;
F_6 ( V_12 , V_1072 ,
( F_2 ( V_12 , V_1072 ) + V_1060 - 1 )
& ~ ( V_1060 - 1 ) ) ;
F_6 ( V_12 , V_1073 ,
( F_2 ( V_12 , V_1073 ) + V_1060 - 1 )
& ~ ( V_1060 - 1 ) ) ;
F_6 ( V_12 , V_1074 , F_308 ( V_1057 - 12 ) ) ;
return 0 ;
}
int F_309 ( struct V_1 * V_12 , unsigned int V_42 )
{
struct V_1041 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_283 ( V_198 , V_1042 , V_1023 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_122 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_1076 , const T_1 * V_20 ,
T_1 * V_8 , int V_677 )
{
int V_48 , V_113 ;
struct V_291 V_198 ;
V_105 * V_51 = & V_198 . V_276 [ 0 ] . V_296 ;
if ( V_1076 > 7 )
return - V_56 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_293 ) |
V_117 | V_118 |
F_127 ( V_19 ) |
F_128 ( V_1075 ) ) ;
V_198 . V_295 = F_51 ( F_53 ( V_198 ) ) ;
for ( V_48 = 0 ; V_48 < V_1076 ; V_48 ++ ) {
* V_51 ++ = F_51 ( * V_20 ++ ) ;
if ( V_677 )
* V_51 = F_51 ( * ( V_8 + V_48 ) ) ;
V_51 ++ ;
}
V_113 = F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
if ( V_113 == 0 )
for ( V_48 = 0 , V_51 = & V_198 . V_276 [ 0 ] . V_8 ; V_48 < V_1076 ; V_48 ++ , V_51 += 2 )
* V_8 ++ = F_22 ( * V_51 ) ;
return V_113 ;
}
int F_80 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_1076 , const T_1 * V_20 ,
T_1 * V_8 )
{
return F_122 ( V_12 , V_42 , V_19 , V_1075 , V_1076 , V_20 , V_8 , 0 ) ;
}
int F_125 ( struct V_1 * V_12 , unsigned int V_42 ,
unsigned int V_19 , unsigned int V_1075 ,
unsigned int V_1076 , const T_1 * V_20 ,
const T_1 * V_8 , int V_46 )
{
struct V_291 V_198 ;
V_105 * V_51 = & V_198 . V_276 [ 0 ] . V_296 ;
if ( V_1076 > 7 )
return - V_56 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_293 ) |
V_117 | V_294 |
F_127 ( V_19 ) |
F_128 ( V_1075 ) ) ;
V_198 . V_295 = F_51 ( F_53 ( V_198 ) ) ;
while ( V_1076 -- ) {
* V_51 ++ = F_51 ( * V_20 ++ ) ;
* V_51 ++ = F_51 ( * V_8 ++ ) ;
}
return F_310 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL , V_46 ) ;
}
int F_311 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_1076 , const T_1 * V_20 ,
const T_1 * V_8 )
{
return F_125 ( V_12 , V_42 , V_19 , V_1075 , V_1076 , V_20 , V_8 ,
V_69 ) ;
}
int F_312 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_1077 , unsigned int V_1078 ,
unsigned int V_1079 , unsigned int V_1080 , unsigned int V_1081 ,
unsigned int V_1082 , unsigned int V_1083 , unsigned int V_1084 ,
unsigned int V_1085 , unsigned int V_1086 , unsigned int V_1087 )
{
struct V_1088 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_1089 ) | V_117 |
V_294 | F_313 ( V_19 ) |
F_314 ( V_1075 ) ) ;
V_198 . V_295 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_1090 = F_51 ( F_315 ( V_1079 ) |
F_316 ( V_1080 ) ) ;
V_198 . V_1091 = F_51 ( F_317 ( V_1083 ) |
F_318 ( V_1084 ) |
F_319 ( V_1077 ) ) ;
V_198 . V_1092 = F_51 ( F_320 ( V_1081 ) |
F_321 ( V_1082 ) |
F_322 ( V_1085 ) ) ;
V_198 . V_1093 = F_51 ( F_323 ( V_1086 ) |
F_324 ( V_1087 ) |
F_325 ( V_1078 ) ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_326 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_324 ,
unsigned int V_19 , unsigned int V_1075 , unsigned int V_1094 , V_68 * V_1095 ,
unsigned int * V_1096 )
{
int V_113 ;
struct V_1097 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_1098 ) | V_117 |
V_294 | V_339 |
F_327 ( V_19 ) | F_328 ( V_1075 ) ) ;
V_198 . V_1099 = F_51 ( V_1100 | F_53 ( V_198 ) ) ;
V_198 . V_1101 = F_329 ( V_324 ) ;
V_198 . V_1094 = V_1094 - 1 ;
V_113 = F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
if ( V_113 )
return V_113 ;
if ( V_1095 ) {
memcpy ( V_1095 , V_198 . V_1095 , sizeof( V_198 . V_1095 ) ) ;
switch ( V_1094 ) {
case 5 :
memcpy ( V_1095 + 24 , V_198 . V_1102 , sizeof( V_198 . V_1102 ) ) ;
case 4 :
memcpy ( V_1095 + 18 , V_198 . V_1103 , sizeof( V_198 . V_1103 ) ) ;
case 3 :
memcpy ( V_1095 + 12 , V_198 . V_1104 , sizeof( V_198 . V_1104 ) ) ;
case 2 :
memcpy ( V_1095 + 6 , V_198 . V_1105 , sizeof( V_198 . V_1105 ) ) ;
}
}
if ( V_1096 )
* V_1096 = F_330 ( F_116 ( V_198 . V_1106 ) ) ;
return F_331 ( F_116 ( V_198 . V_1107 ) ) ;
}
int F_332 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_642 )
{
struct V_1097 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_1098 ) |
V_117 |
V_339 |
F_327 ( V_19 ) |
F_328 ( V_1075 ) ) ;
V_198 . V_1099 = F_51 ( V_1108 | F_53 ( V_198 ) ) ;
V_198 . V_1107 = F_185 ( F_333 ( V_642 ) ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
}
int F_334 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_642 ,
int V_766 , int V_1109 , int V_1110 , int V_1111 , int V_1112 ,
bool V_45 )
{
struct V_1113 V_198 ;
if ( V_766 < 0 )
V_766 = V_1114 ;
if ( V_1109 < 0 )
V_1109 = V_1115 ;
if ( V_1110 < 0 )
V_1110 = V_1116 ;
if ( V_1111 < 0 )
V_1111 = V_1117 ;
if ( V_1112 < 0 )
V_1112 = V_1118 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_647 = F_51 ( F_52 ( V_1119 ) |
V_117 | V_294 |
F_335 ( V_642 ) ) ;
V_198 . V_295 = F_51 ( F_53 ( V_198 ) ) ;
V_198 . V_1120 =
F_51 ( F_336 ( V_766 ) |
F_337 ( V_1109 ) |
F_338 ( V_1110 ) |
F_339 ( V_1111 ) |
F_340 ( V_1112 ) ) ;
return F_36 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL , V_45 ) ;
}
int F_341 ( struct V_1 * V_12 , unsigned int V_42 ,
unsigned int V_642 , bool free , unsigned int V_1121 ,
const V_68 * * V_10 , T_8 * V_70 , T_3 * V_1122 , bool V_45 )
{
int V_82 , V_113 = 0 ;
struct V_1123 V_198 ;
unsigned int V_1124 = 0 ;
unsigned int V_1125 = V_12 -> V_20 . V_723 . V_1126 ;
unsigned int V_1127 = V_1121 ;
if ( V_1121 > V_1125 )
return - V_56 ;
for ( V_82 = 0 ; V_82 < V_1121 ; ) {
unsigned int V_1128 = ( V_1127 < F_30 ( V_198 . V_38 . V_1129 ) ?
V_1127 : F_30 ( V_198 . V_38 . V_1129 ) ) ;
T_4 V_1130 = F_95 ( F_92 ( struct V_1123 ,
V_38 . V_1129 [ V_1128 ] ) , 16 ) ;
struct V_1131 * V_51 ;
int V_48 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_647 = F_51 ( F_52 ( V_1132 ) |
V_117 |
V_294 |
F_342 ( free ) |
F_343 ( V_642 ) ) ;
V_198 . V_1133 =
F_51 ( F_344 ( free ) |
F_345 ( V_1130 ) ) ;
for ( V_48 = 0 , V_51 = V_198 . V_38 . V_1129 ; V_48 < V_1128 ; V_48 ++ , V_51 ++ ) {
V_51 -> V_1134 =
F_185 ( V_1135 |
F_346 (
V_1136 ) ) ;
memcpy ( V_51 -> V_1137 , V_10 [ V_82 + V_48 ] ,
sizeof( V_51 -> V_1137 ) ) ;
}
V_113 = F_36 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 , V_45 ) ;
if ( V_113 && V_113 != - V_1138 )
break;
for ( V_48 = 0 , V_51 = V_198 . V_38 . V_1129 ; V_48 < V_1128 ; V_48 ++ , V_51 ++ ) {
T_8 V_689 = F_347 (
F_116 ( V_51 -> V_1134 ) ) ;
if ( V_70 )
V_70 [ V_82 + V_48 ] = ( V_689 >= V_1125 ?
0xffff : V_689 ) ;
if ( V_689 < V_1125 )
V_1124 ++ ;
else if ( V_1122 )
* V_1122 |= ( 1ULL <<
F_182 ( V_10 [ V_82 + V_48 ] ) ) ;
}
free = false ;
V_82 += V_1128 ;
V_1127 -= V_1128 ;
}
if ( V_113 == 0 || V_113 == - V_1138 )
V_113 = V_1124 ;
return V_113 ;
}
int F_348 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_642 ,
int V_70 , const V_68 * V_10 , bool V_1139 , bool V_1140 )
{
int V_113 , V_654 ;
struct V_1123 V_198 ;
struct V_1131 * V_51 = V_198 . V_38 . V_1129 ;
unsigned int V_1141 = V_12 -> V_20 . V_723 . V_1126 ;
if ( V_70 < 0 )
V_70 = V_1139 ? V_1142 : V_1136 ;
V_654 = V_1140 ? V_1143 : V_1144 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_647 = F_51 ( F_52 ( V_1132 ) |
V_117 | V_294 |
F_343 ( V_642 ) ) ;
V_198 . V_1133 = F_51 ( F_345 ( 1 ) ) ;
V_51 -> V_1134 = F_185 ( V_1135 |
F_349 ( V_654 ) |
F_346 ( V_70 ) ) ;
memcpy ( V_51 -> V_1137 , V_10 , sizeof( V_51 -> V_1137 ) ) ;
V_113 = F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
if ( V_113 == 0 ) {
V_113 = F_347 ( F_116 ( V_51 -> V_1134 ) ) ;
if ( V_113 >= V_1141 )
V_113 = - V_163 ;
}
return V_113 ;
}
int F_350 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_642 ,
bool V_1145 , T_3 V_1146 , bool V_45 )
{
struct V_1123 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_647 = F_51 ( F_52 ( V_1132 ) |
V_117 | V_294 |
F_351 ( V_642 ) ) ;
V_198 . V_1133 = F_51 ( V_1147 |
F_352 ( V_1145 ) |
F_345 ( 1 ) ) ;
V_198 . V_38 . V_1122 . V_1148 = F_18 ( V_1146 ) ;
return F_36 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL , V_45 ) ;
}
int F_353 ( struct V_1 * V_12 , unsigned int V_42 ,
unsigned int V_642 , bool V_1149 , bool V_1150 , bool V_1151 )
{
struct V_1152 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_647 = F_51 ( F_52 ( V_1153 ) |
V_117 | V_339 |
F_351 ( V_642 ) ) ;
V_198 . V_1154 = F_51 ( F_354 ( V_1149 ) |
F_355 ( V_1150 ) |
F_356 ( V_1151 ) |
F_53 ( V_198 ) ) ;
return F_357 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_358 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_642 ,
bool V_1149 , bool V_1150 )
{
return F_353 ( V_12 , V_42 , V_642 , V_1149 , V_1150 , 0 ) ;
}
int F_359 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_642 ,
unsigned int V_1155 )
{
struct V_1152 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_647 = F_51 ( F_52 ( V_1153 ) |
V_117 | V_339 |
F_351 ( V_642 ) ) ;
V_198 . V_1154 = F_51 ( V_1156 | F_53 ( V_198 ) ) ;
V_198 . V_1157 = F_185 ( V_1155 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_360 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_1158 , unsigned int V_1159 ,
unsigned int V_1160 , unsigned int V_1161 )
{
struct V_1162 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_1163 ) | V_117 |
V_339 | F_361 ( V_19 ) |
F_362 ( V_1075 ) ) ;
V_198 . V_1099 = F_51 ( V_1164 | F_53 ( V_198 ) ) ;
V_198 . V_1165 = F_51 ( F_363 ( V_1158 ) ) ;
V_198 . V_1159 = F_185 ( V_1159 ) ;
V_198 . V_1160 = F_185 ( V_1160 ) ;
V_198 . V_1161 = F_185 ( V_1161 ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_364 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_1166 )
{
struct V_1167 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_1168 ) |
V_117 | V_339 |
F_365 ( V_19 ) |
F_366 ( V_1075 ) ) ;
V_198 . V_1099 = F_51 ( V_1169 | F_53 ( V_198 ) ) ;
V_198 . V_1170 = F_51 ( F_367 ( V_1166 ) ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_368 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_1166 )
{
struct V_1171 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_1172 ) |
V_117 | V_339 |
F_369 ( V_19 ) |
F_370 ( V_1075 ) ) ;
V_198 . V_1099 = F_51 ( V_1173 | F_53 ( V_198 ) ) ;
V_198 . V_1174 = F_51 ( F_371 ( V_1166 ) ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_372 ( struct V_1 * V_12 , unsigned int V_42 , unsigned int V_19 ,
unsigned int V_1075 , unsigned int V_1166 )
{
struct V_1175 V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_198 . V_292 = F_51 ( F_52 ( V_1176 ) |
V_117 | V_339 |
F_373 ( V_19 ) |
F_374 ( V_1075 ) ) ;
V_198 . V_1099 = F_51 ( V_1177 | F_53 ( V_198 ) ) ;
V_198 . V_1170 = F_51 ( F_375 ( V_1166 ) ) ;
return F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , NULL ) ;
}
int F_376 ( struct V_1 * V_12 , const T_2 * V_33 )
{
V_68 V_1178 = * ( const V_68 * ) V_33 ;
if ( V_1178 == V_338 ) {
int V_1179 = 0 , V_328 = 0 ;
const struct V_327 * V_51 = ( void * ) V_33 ;
int V_1180 = F_377 ( F_22 ( V_51 -> V_337 ) ) ;
int V_324 = V_12 -> V_1181 [ V_1180 ] ;
struct V_1182 * V_1183 = F_378 ( V_12 , V_324 ) ;
struct V_325 * V_326 = & V_1183 -> V_1184 ;
T_1 V_1185 = F_22 ( V_51 -> V_38 . V_1186 . V_1187 ) ;
int V_331 = ( V_1185 & V_1188 ) != 0 ;
T_1 V_1189 = F_379 ( V_1185 ) ;
if ( V_1185 & V_1190 )
V_328 |= V_333 ;
if ( V_1185 & V_1191 )
V_328 |= V_335 ;
if ( V_1185 & F_380 ( V_1192 ) )
V_1179 = 100 ;
else if ( V_1185 & F_380 ( V_1193 ) )
V_1179 = 1000 ;
else if ( V_1185 & F_380 ( V_1194 ) )
V_1179 = 10000 ;
else if ( V_1185 & F_380 ( V_1195 ) )
V_1179 = 40000 ;
if ( V_331 != V_326 -> V_331 || V_1179 != V_326 -> V_1179 ||
V_328 != V_326 -> V_328 ) {
V_326 -> V_331 = V_331 ;
V_326 -> V_1179 = V_1179 ;
V_326 -> V_328 = V_328 ;
V_326 -> V_342 = F_116 ( V_51 -> V_38 . V_1186 . V_1196 ) ;
F_381 ( V_12 , V_324 , V_331 ) ;
}
if ( V_1189 != V_1183 -> V_1197 ) {
V_1183 -> V_1197 = V_1189 ;
F_382 ( V_12 , V_324 ) ;
}
}
return 0 ;
}
static void F_383 ( struct V_1 * V_1 , struct V_1198 * V_51 )
{
T_8 V_8 ;
if ( F_384 ( V_1 -> V_57 ) ) {
F_385 ( V_1 -> V_57 , V_1199 , & V_8 ) ;
V_51 -> V_1179 = V_8 & V_1200 ;
V_51 -> V_1201 = ( V_8 & V_1202 ) >> 4 ;
}
}
static void F_386 ( struct V_325 * V_326 , unsigned int V_1203 )
{
V_326 -> V_342 = V_1203 ;
V_326 -> V_349 = 0 ;
V_326 -> V_1179 = 0 ;
V_326 -> V_332 = V_326 -> V_328 = V_333 | V_335 ;
if ( V_326 -> V_342 & V_343 ) {
V_326 -> V_350 = V_326 -> V_342 & V_346 ;
V_326 -> V_347 = V_1204 ;
V_326 -> V_332 |= V_1205 ;
} else {
V_326 -> V_350 = 0 ;
V_326 -> V_347 = V_348 ;
}
}
int F_387 ( void T_9 * V_1206 )
{
T_1 V_634 ;
V_634 = F_388 ( V_1206 + V_635 ) ;
if ( V_634 != 0xffffffff && V_634 != V_1207 )
return 0 ;
F_31 ( 500 ) ;
V_634 = F_388 ( V_1206 + V_635 ) ;
return ( V_634 != 0xffffffff && V_634 != V_1207 ? 0 : - V_60 ) ;
}
static int F_389 ( struct V_1 * V_12 )
{
static struct V_1208 V_1209 [] = {
{ 0x150201 , 4 << 20 } ,
} ;
int V_113 ;
T_1 V_1186 ;
V_113 = F_85 ( V_12 , 1 , 1 , 0 , V_1210 ) ;
if ( ! V_113 )
V_113 = F_81 ( V_12 , 3 , 0 , 1 , & V_1186 ) ;
F_6 ( V_12 , V_186 , 0 ) ;
if ( V_113 )
return V_113 ;
for ( V_113 = 0 ; V_113 < F_30 ( V_1209 ) ; ++ V_113 )
if ( V_1209 [ V_113 ] . V_1211 == V_1186 ) {
V_12 -> V_20 . V_194 = V_1209 [ V_113 ] . V_1212 ;
V_12 -> V_20 . V_260 =
V_12 -> V_20 . V_194 / V_1213 ;
return 0 ;
}
if ( ( V_1186 & 0xff ) != 0x20 )
return - V_56 ;
V_1186 >>= 16 ;
if ( V_1186 >= 0x14 && V_1186 < 0x18 )
V_12 -> V_20 . V_260 = 1 << ( V_1186 - 16 ) ;
else if ( V_1186 == 0x18 )
V_12 -> V_20 . V_260 = 64 ;
else
return - V_56 ;
V_12 -> V_20 . V_194 = 1 << V_1186 ;
V_12 -> V_20 . V_270 =
F_2 ( V_12 , V_1050 ) & V_1214 ;
if ( V_12 -> V_20 . V_194 < V_1215 )
F_143 ( V_12 -> V_32 , L_296 ,
V_12 -> V_20 . V_194 , V_1215 ) ;
return 0 ;
}
static void F_390 ( struct V_1 * V_1 , V_68 V_147 )
{
T_8 V_8 ;
T_1 V_1216 ;
V_1216 = F_391 ( V_1 -> V_57 , V_1217 ) ;
if ( V_1216 ) {
F_392 ( V_1 -> V_57 ,
V_1216 + V_1218 , & V_8 ) ;
V_8 &= ~ V_1219 ;
V_8 |= V_147 ;
F_393 ( V_1 -> V_57 ,
V_1216 + V_1218 , V_8 ) ;
}
}
int F_394 ( struct V_1 * V_1 )
{
int V_113 , V_1220 ;
T_10 V_1221 ;
T_1 V_1222 ;
F_383 ( V_1 , & V_1 -> V_20 . V_1223 ) ;
V_1222 = F_395 ( F_2 ( V_1 , V_1224 ) ) ;
V_113 = F_389 ( V_1 ) ;
if ( V_113 < 0 ) {
F_15 ( V_1 -> V_32 , L_297 , V_113 ) ;
return V_113 ;
}
F_392 ( V_1 -> V_57 , V_1225 , & V_1221 ) ;
V_1220 = V_1221 >> 12 ;
V_1 -> V_20 . V_21 = 0 ;
switch ( V_1220 ) {
case V_136 :
V_1 -> V_20 . V_21 |= F_396 ( V_136 , V_1222 ) ;
V_1 -> V_20 . V_723 . V_1226 = V_1227 ;
V_1 -> V_20 . V_723 . V_1126 =
V_1228 ;
V_1 -> V_20 . V_723 . V_1229 = 128 ;
V_1 -> V_20 . V_723 . V_722 = V_779 ;
V_1 -> V_20 . V_723 . V_1230 = 128 ;
break;
case V_22 :
V_1 -> V_20 . V_21 |= F_396 ( V_22 , V_1222 ) ;
V_1 -> V_20 . V_723 . V_1226 = V_1227 | V_1231 ;
V_1 -> V_20 . V_723 . V_1126 =
V_1232 ;
V_1 -> V_20 . V_723 . V_1229 = 128 ;
V_1 -> V_20 . V_723 . V_722 = V_779 ;
V_1 -> V_20 . V_723 . V_1230 = 128 ;
break;
case V_138 :
V_1 -> V_20 . V_21 |= F_396 ( V_138 , V_1222 ) ;
V_1 -> V_20 . V_723 . V_1226 = 0 ;
V_1 -> V_20 . V_723 . V_1126 =
V_1232 ;
V_1 -> V_20 . V_723 . V_1229 = 256 ;
V_1 -> V_20 . V_723 . V_722 = 2 ;
V_1 -> V_20 . V_723 . V_1230 = 256 ;
break;
default:
F_15 ( V_1 -> V_32 , L_298 ,
V_1221 ) ;
return - V_56 ;
}
V_1 -> V_20 . V_1233 = V_1234 ;
F_228 ( V_1 -> V_20 . V_1235 , V_1 -> V_20 . V_1236 ) ;
V_1 -> V_20 . V_1237 = 1 ;
V_1 -> V_20 . V_278 = 1 ;
V_1 -> V_20 . V_157 . V_182 = 50000 ;
F_390 ( V_1 , 0xd ) ;
return 0 ;
}
int F_397 ( struct V_1 * V_1 ,
unsigned int V_986 ,
enum V_1238 V_1239 ,
int V_1240 ,
T_3 * V_1241 ,
unsigned int * V_1242 )
{
unsigned int V_1057 , V_1055 , V_1243 , V_1244 ;
T_3 V_1245 , V_1246 ;
unsigned int V_1247 , V_1248 , V_1249 ;
if ( ! V_1240 && F_13 ( V_1 -> V_20 . V_21 ) )
return - V_56 ;
V_1057 = V_1 -> V_20 . V_1250 . V_1251 + 10 ;
V_1055 = 1 << V_1057 ;
V_1243 = ( V_1239 == V_1252
? V_1 -> V_20 . V_1250 . V_1253
: V_1 -> V_20 . V_1250 . V_1254 ) ;
V_1244 = ( 1 << V_1243 ) - 1 ;
V_1245 = ( ( T_3 ) ( V_986 >> V_1243 ) << V_1057 ) ;
V_1247 = V_986 & V_1244 ;
V_1248 = V_1247 * V_1255 ;
V_1246 = V_1245 ;
V_1249 = ( V_1248 < V_1055 ) ;
if ( V_1249 ) {
V_1246 += V_1248 ;
V_1247 = 0 ;
}
* V_1241 = V_1246 ;
* V_1242 = V_1247 ;
return 0 ;
}
int F_398 ( struct V_1 * V_12 )
{
struct V_1256 * V_1257 = & V_12 -> V_20 . V_1258 ;
T_1 V_1259 ;
unsigned int V_1260 ;
struct V_1261 V_1262 ;
int V_113 ;
V_1259 =
F_2 ( V_12 , F_399 ( V_1263 , V_1264 ) ) ;
if ( V_1259 ) {
unsigned int V_1265 , V_1266 ;
V_1257 -> V_1267 = F_400 ( V_1259 ) ;
V_1257 -> V_258 = F_401 ( V_1259 ) << 4 ;
V_1266 = F_402 ( V_1259 ) ;
V_1265 = ( V_1266 + 1 ) * 128 ;
V_1257 -> V_44 = V_1265 * sizeof( struct V_1268 ) ;
return 0 ;
}
memset ( & V_1262 , 0 , sizeof( V_1262 ) ) ;
V_1262 . V_657 = F_51 ( F_52 ( V_1269 ) |
V_117 | V_118 ) ;
V_1262 . V_295 = F_51 ( F_53 ( V_1262 ) ) ;
V_113 = F_56 ( V_12 , V_12 -> V_42 , & V_1262 , sizeof( V_1262 ) ,
& V_1262 ) ;
if ( V_113 )
return V_113 ;
V_1260 =
F_22 ( V_1262 . V_1270 ) ;
V_1257 -> V_1267 = F_403 ( V_1260 ) ;
V_1257 -> V_258 = F_404 ( V_1260 ) << 4 ;
V_1257 -> V_44 = F_22 ( V_1262 . V_1271 ) ;
return 0 ;
}
int F_405 ( struct V_1 * V_1 )
{
struct V_1272 * V_1272 = & V_1 -> V_20 . V_1250 ;
T_1 V_1251 , V_1273 ;
unsigned int V_1274 , V_1275 ;
V_1251 = F_2 ( V_1 , V_1062 ) ;
V_1274 = ( V_1276 +
( V_1277 - V_1276 ) * V_1 -> V_19 ) ;
V_1272 -> V_1251 = ( ( V_1251 >> V_1274 ) & V_1278 ) ;
V_1275 = ( V_1279 +
( V_1280 - V_1279 ) * V_1 -> V_19 ) ;
V_1273 = F_2 ( V_1 , V_1281 ) ;
V_1272 -> V_1253 = ( ( V_1273 >> V_1275 ) & V_1282 ) ;
V_1273 = F_2 ( V_1 , V_1283 ) ;
V_1272 -> V_1254 = ( ( V_1273 >> V_1275 ) & V_1282 ) ;
return 0 ;
}
int F_406 ( struct V_1 * V_12 )
{
int V_1180 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 , V_1284 ) ;
V_12 -> V_20 . V_782 . V_1285 = F_407 ( V_11 ) ;
V_12 -> V_20 . V_782 . V_1286 = F_408 ( V_11 ) ;
for ( V_1180 = 0 ; V_1180 < V_779 ; V_1180 ++ )
V_12 -> V_20 . V_782 . V_1287 [ V_1180 ] = V_1180 ;
if ( F_198 ( V_12 ) ) {
F_199 ( V_12 , & V_12 -> V_20 . V_782 . V_1288 , 1 ,
V_1289 , 1 ) ;
F_199 ( V_12 , & V_12 -> V_20 . V_782 . V_1290 , 1 ,
V_1291 , 1 ) ;
} else {
F_7 ( V_12 , V_682 , V_683 ,
& V_12 -> V_20 . V_782 . V_1288 , 1 ,
V_1289 ) ;
F_7 ( V_12 , V_682 , V_683 ,
& V_12 -> V_20 . V_782 . V_1290 , 1 ,
V_1291 ) ;
}
V_12 -> V_20 . V_782 . V_1292 = F_409 ( V_12 , V_1293 ) ;
V_12 -> V_20 . V_782 . V_1294 = F_409 ( V_12 , V_1295 ) ;
V_12 -> V_20 . V_782 . V_1296 = F_409 ( V_12 , V_1297 ) ;
V_12 -> V_20 . V_782 . V_1298 = F_409 ( V_12 ,
V_1299 ) ;
if ( ( V_12 -> V_20 . V_782 . V_1290 & V_1300 ) == 0 )
V_12 -> V_20 . V_782 . V_1294 = - 1 ;
return 0 ;
}
int F_409 ( const struct V_1 * V_12 , int V_1301 )
{
unsigned int V_1302 = V_12 -> V_20 . V_782 . V_1288 ;
unsigned int V_1303 ;
int V_1304 ;
if ( ( V_1302 & V_1301 ) == 0 )
return - 1 ;
for ( V_1303 = 1 , V_1304 = 0 ; V_1303 < V_1301 ; V_1303 <<= 1 ) {
switch ( V_1302 & V_1303 ) {
case V_1305 :
V_1304 += V_1306 ;
break;
case V_1297 :
V_1304 += V_1307 ;
break;
case V_1295 :
V_1304 += V_1308 ;
break;
case V_1293 :
V_1304 += V_1309 ;
break;
case V_1310 :
V_1304 += V_1311 ;
break;
case V_1299 :
V_1304 += V_1312 ;
break;
case V_1313 :
V_1304 += V_1314 ;
break;
case V_1315 :
V_1304 += V_1316 ;
break;
case V_1317 :
V_1304 += V_1318 ;
break;
case V_1319 :
V_1304 += V_1320 ;
break;
}
}
return V_1304 ;
}
int F_410 ( struct V_1 * V_12 , int V_42 )
{
int V_48 , V_113 ;
struct V_666 V_1321 ;
memset ( & V_1321 , 0 , sizeof( V_1321 ) ) ;
F_411 (adap, i) {
struct V_1182 * V_51 = F_378 ( V_12 , V_48 ) ;
V_1321 . V_647 =
F_51 ( F_52 ( V_667 ) |
V_117 | V_118 |
F_192 ( V_51 -> V_642 ) ) ;
V_1321 . V_295 = F_51 ( F_53 ( V_1321 ) ) ;
V_113 = F_56 ( V_12 , V_42 , & V_1321 , sizeof( V_1321 ) , & V_1321 ) ;
if ( V_113 )
return V_113 ;
V_51 -> V_1322 = F_22 ( V_1321 . V_38 . V_663 . V_668 ) ;
}
return 0 ;
}
int F_412 ( struct V_1 * V_12 , int V_42 , int V_19 , int V_1075 )
{
V_68 V_10 [ 6 ] ;
int V_113 , V_48 , V_302 = 0 ;
struct V_327 V_198 ;
struct V_666 V_1321 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
memset ( & V_1321 , 0 , sizeof( V_1321 ) ) ;
F_411 (adap, i) {
unsigned int V_1096 ;
struct V_1182 * V_51 = F_378 ( V_12 , V_48 ) ;
while ( ( V_12 -> V_20 . V_278 & ( 1 << V_302 ) ) == 0 )
V_302 ++ ;
V_198 . V_337 = F_51 ( F_52 ( V_338 ) |
V_117 | V_118 |
F_138 ( V_302 ) ) ;
V_198 . V_340 = F_51 (
F_139 ( V_1323 ) |
F_53 ( V_198 ) ) ;
V_113 = F_56 ( V_12 , V_42 , & V_198 , sizeof( V_198 ) , & V_198 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_326 ( V_12 , V_42 , V_302 , V_19 , V_1075 , 1 , V_10 , & V_1096 ) ;
if ( V_113 < 0 )
return V_113 ;
V_51 -> V_642 = V_113 ;
V_51 -> V_1324 = V_302 ;
V_51 -> V_1325 = V_302 ;
V_51 -> V_1096 = V_1096 ;
memcpy ( V_12 -> V_324 [ V_48 ] -> V_1326 , V_10 , V_1327 ) ;
V_12 -> V_324 [ V_48 ] -> V_1328 = V_302 ;
V_113 = F_22 ( V_198 . V_38 . V_1186 . V_1187 ) ;
V_51 -> V_1329 = ( V_113 & V_1330 ) ?
F_413 ( V_113 ) : - 1 ;
V_51 -> V_825 = F_414 ( V_113 ) ;
V_51 -> V_1197 = V_1331 ;
V_1321 . V_647 =
F_51 ( F_52 ( V_667 ) |
V_117 | V_118 |
F_415 ( V_51 -> V_642 ) ) ;
V_1321 . V_295 = F_51 ( F_53 ( V_1321 ) ) ;
V_113 = F_56 ( V_12 , V_42 , & V_1321 , sizeof( V_1321 ) , & V_1321 ) ;
if ( V_113 )
return V_113 ;
V_51 -> V_1322 = F_22 ( V_1321 . V_38 . V_663 . V_668 ) ;
F_386 ( & V_51 -> V_1184 , F_116 ( V_198 . V_38 . V_1186 . V_1196 ) ) ;
V_302 ++ ;
}
return 0 ;
}
void F_416 ( struct V_1 * V_12 , T_8 * V_1332 , T_8 * V_44 , T_8 * V_1333 )
{
unsigned int V_48 , V_11 ;
int V_1334 = F_13 ( V_12 -> V_20 . V_21 ) ?
V_1335 : V_1336 ;
for ( V_48 = 0 ; V_48 < V_1337 ; V_48 ++ ) {
F_6 ( V_12 , V_1338 , V_1339 |
F_417 ( V_48 ) ) ;
V_11 = F_2 ( V_12 , V_1340 ) ;
* V_1332 ++ = F_418 ( V_11 ) * 256 ;
* V_44 ++ = F_419 ( V_11 ) * 256 ;
* V_1333 ++ = F_420 ( V_11 ) * 8 ;
}
for ( V_48 = 0 ; V_48 < V_1334 ; V_48 ++ ) {
F_6 ( V_12 , V_1338 , V_1341 |
F_417 ( V_48 ) ) ;
V_11 = F_2 ( V_12 , V_1340 ) ;
* V_1332 ++ = F_418 ( V_11 ) * 256 ;
* V_44 ++ = F_419 ( V_11 ) * 256 ;
}
}
int F_421 ( struct V_1 * V_12 , unsigned int V_986 , T_1 * V_125 , T_4 V_197 )
{
int V_48 , V_426 , V_5 ;
unsigned int V_10 ;
const unsigned int V_192 = V_1342 * 4 ;
if ( V_986 > 5 || ( V_197 & 3 ) )
return - V_56 ;
V_10 = V_986 * V_192 ;
if ( V_197 > V_192 )
V_197 = V_192 ;
V_5 = 1000000 ;
for ( V_48 = 0 ; V_48 < V_197 ; V_48 ++ , V_10 ++ ) {
F_6 ( V_12 , V_1343 , F_422 ( V_10 ) |
V_1344 ) ;
V_426 = F_4 ( V_12 , V_1343 , V_1345 , 0 ,
V_5 , 1 ) ;
if ( V_426 )
return V_426 ;
* V_125 ++ = F_2 ( V_12 , V_1346 ) ;
}
F_6 ( V_12 , V_1343 , 0 ) ;
return V_48 ;
}
int F_423 ( struct V_1 * V_12 , unsigned int V_986 , T_1 * V_125 , T_4 V_197 )
{
int V_48 , V_426 ;
unsigned int V_10 , V_11 , V_192 ;
int V_1334 = F_13 ( V_12 -> V_20 . V_21 ) ?
V_1335 : V_1336 ;
if ( ( V_986 > ( V_1334 - 1 ) ) || ( V_197 & 3 ) )
return - V_56 ;
F_6 ( V_12 , V_1338 , V_1341 |
F_417 ( V_986 ) ) ;
V_11 = F_2 ( V_12 , V_1340 ) ;
V_10 = F_418 ( V_11 ) * 64 ;
V_192 = F_419 ( V_11 ) * 64 ;
if ( V_197 > V_192 )
V_197 = V_192 ;
for ( V_48 = 0 ; V_48 < V_197 ; V_48 ++ , V_10 ++ ) {
F_6 ( V_12 , V_1347 , F_424 ( V_10 ) |
V_1348 ) ;
V_426 = F_4 ( V_12 , V_1347 , V_1349 , 0 ,
2 , 1 ) ;
if ( V_426 )
return V_426 ;
* V_125 ++ = F_2 ( V_12 , V_1350 ) ;
}
F_6 ( V_12 , V_1347 , 0 ) ;
return V_48 ;
}
int F_425 ( struct V_1 * V_12 , unsigned int V_10 , unsigned int V_197 ,
unsigned int * V_7 )
{
int V_113 = 0 ;
if ( F_2 ( V_12 , V_1351 ) & V_1352 )
return - V_63 ;
for ( ; ! V_113 && V_197 -- ; V_10 += 4 ) {
F_6 ( V_12 , V_1351 , V_10 ) ;
V_113 = F_4 ( V_12 , V_1351 , V_1352 ,
0 , 5 , 2 ) ;
if ( ! V_113 )
* V_7 ++ = F_2 ( V_12 , V_1353 ) ;
}
return V_113 ;
}
int F_426 ( struct V_1 * V_12 , unsigned int V_10 , unsigned int V_197 ,
const unsigned int * V_7 )
{
int V_113 = 0 ;
if ( F_2 ( V_12 , V_1351 ) & V_1352 )
return - V_63 ;
for ( ; ! V_113 && V_197 -- ; V_10 += 4 ) {
F_6 ( V_12 , V_1353 , * V_7 ++ ) ;
F_6 ( V_12 , V_1351 , V_10 | V_1354 ) ;
V_113 = F_4 ( V_12 , V_1351 , V_1352 ,
0 , 5 , 2 ) ;
}
return V_113 ;
}
static int F_427 ( struct V_1 * V_12 , unsigned int V_10 ,
unsigned int V_8 )
{
return F_426 ( V_12 , V_10 , 1 , & V_8 ) ;
}
int F_428 ( struct V_1 * V_12 , T_1 * V_318 , unsigned int * V_1355 )
{
int V_48 , V_113 ;
unsigned int V_303 , V_8 , V_70 ;
V_113 = F_425 ( V_12 , V_1356 , 1 , & V_303 ) ;
if ( V_113 )
return V_113 ;
if ( V_303 & V_1357 ) {
V_113 = F_427 ( V_12 , V_1356 , 0 ) ;
if ( V_113 )
return V_113 ;
}
V_113 = F_425 ( V_12 , V_1356 , 1 , & V_8 ) ;
if ( V_113 )
goto V_1358;
V_70 = F_429 ( V_8 ) ;
if ( V_1355 )
* V_1355 = V_70 ;
for ( V_48 = 0 ; V_48 < V_12 -> V_20 . V_1233 ; V_48 ++ ) {
V_113 = F_427 ( V_12 , V_1356 ,
F_430 ( V_70 ) | V_1359 ) ;
if ( V_113 )
break;
V_113 = F_425 ( V_12 , V_1356 , 1 , & V_8 ) ;
if ( V_113 )
break;
if ( V_8 & V_1359 ) {
V_113 = - V_64 ;
break;
}
V_113 = F_425 ( V_12 , V_1360 , 1 , & V_318 [ V_48 ] ) ;
if ( V_113 )
break;
V_70 = ( V_70 + 1 ) & V_1361 ;
}
V_1358:
if ( V_303 & V_1357 ) {
int V_124 = F_427 ( V_12 , V_1356 ,
V_303 & ~ V_1359 ) ;
if ( ! V_113 )
V_113 = V_124 ;
}
return V_113 ;
}
void F_431 ( struct V_1 * V_12 , T_3 * V_318 , unsigned int * V_1355 )
{
bool V_1362 ;
unsigned int V_48 , V_303 , V_8 , V_70 ;
V_303 = F_2 ( V_12 , V_1363 ) & 0xffff ;
if ( V_303 & V_1364 )
F_6 ( V_12 , V_1363 ,
V_12 -> V_20 . V_782 . V_1365 | ( V_303 ^ V_1364 ) ) ;
V_8 = F_2 ( V_12 , V_1363 ) ;
V_70 = F_432 ( V_8 ) ;
V_1362 = F_433 ( V_8 ) >= 2 && ( V_8 & V_1366 ) == 0 ;
if ( V_1362 )
V_70 = ( V_70 + 1 ) & V_1367 ;
if ( V_1355 )
* V_1355 = V_70 ;
V_8 &= 0xffff ;
V_8 &= ~ F_434 ( V_1367 ) ;
V_8 |= V_12 -> V_20 . V_782 . V_1365 ;
for ( V_48 = 0 ; V_48 < V_1368 ; V_48 ++ ) {
F_6 ( V_12 , V_1363 , F_434 ( V_70 ) | V_8 ) ;
V_318 [ V_48 ] = F_19 ( V_12 , V_1369 ) ;
V_70 = ( V_70 + 1 ) & V_1367 ;
}
if ( V_1362 )
V_318 [ V_1368 - 1 ] = ~ 0ULL ;
if ( V_303 & V_1364 )
F_6 ( V_12 , V_1363 ,
V_303 | V_12 -> V_20 . V_782 . V_1365 ) ;
}
void F_435 ( struct V_1 * V_1 ,
struct V_1370 * V_1371 )
{
V_1371 -> V_1372 = F_436 ( V_1 ) * 1000000 ;
V_1371 -> V_1373 [ 0 ] = 0 ;
V_1371 -> V_1373 [ 1 ] = 0 ;
}
void F_437 ( struct V_1 * V_1 ,
struct V_1370 * V_1371 ,
int V_1374 , int V_1375 )
{
int V_48 , V_1376 [ 2 ] ;
F_6 ( V_1 , V_1377 , 13 ) ;
V_1376 [ 0 ] = F_2 ( V_1 , V_1378 ) ;
V_1376 [ 1 ] = F_2 ( V_1 , V_1379 ) ;
for ( V_48 = 0 ; V_48 < 2 ; V_48 ++ ) {
T_1 V_1380 , V_1381 ;
if ( V_1376 [ V_48 ] < V_1371 -> V_1372 ) {
if ( V_1371 -> V_1373 [ V_48 ] >= V_1382 * V_1374 )
F_143 ( V_1 -> V_32 , L_299
L_300 ,
V_48 , V_1371 -> V_1383 [ V_48 ] ,
V_1371 -> V_1373 [ V_48 ] / V_1374 ) ;
V_1371 -> V_1373 [ V_48 ] = 0 ;
continue;
}
if ( V_1371 -> V_1373 [ V_48 ] == 0 ) {
V_1371 -> V_1373 [ V_48 ] = V_1374 ;
V_1371 -> V_1384 [ V_48 ] = 0 ;
} else {
V_1371 -> V_1373 [ V_48 ] += V_1375 ;
V_1371 -> V_1384 [ V_48 ] -= V_1375 ;
}
if ( V_1371 -> V_1373 [ V_48 ] < V_1382 * V_1374 )
continue;
if ( V_1371 -> V_1384 [ V_48 ] > 0 )
continue;
V_1371 -> V_1384 [ V_48 ] = V_1385 * V_1374 ;
F_6 ( V_1 , V_1377 , 0 ) ;
V_1380 = F_2 ( V_1 , V_1379 ) ;
V_1371 -> V_1386 [ V_48 ] = ( V_1380 >> ( V_48 * 9 ) ) & 0x3f ;
F_6 ( V_1 , V_1377 , 11 ) ;
V_1381 = F_2 ( V_1 , V_1379 ) ;
V_1371 -> V_1383 [ V_48 ] = ( V_1381 >> ( V_48 * 16 ) ) & 0xffff ;
F_143 ( V_1 -> V_32 , L_301
L_302 ,
V_48 , V_1371 -> V_1383 [ V_48 ] , V_1371 -> V_1386 [ V_48 ] ,
V_1371 -> V_1373 [ V_48 ] / V_1374 ,
V_1380 , V_1381 ) ;
F_280 ( V_1 , V_1371 -> V_1386 [ V_48 ] ) ;
}
}
