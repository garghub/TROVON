int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
T_3 V_5 = 0xc40000 + ( V_3 & ~ 3 ) ;
T_3 V_6 = 0xff ;
int V_7 = ( V_3 & 3 ) * 8 ;
T_3 V_8 = F_2 ( V_2 , V_5 ) ;
V_8 = ( V_8 & ~ ( V_6 << V_7 ) ) | ( ( T_3 ) V_4 << V_7 ) ;
F_3 ( V_2 , V_8 , V_5 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_9 , T_2 V_6 )
{
T_3 V_5 = 0xc40000 + ( V_3 & ~ 3 ) ;
int V_7 = ( V_3 & 3 ) * 8 ;
T_3 V_8 = F_2 ( V_2 , V_5 ) ;
V_8 = ( V_8 & ~ ( ( T_3 ) 0xff << V_7 ) ) | ( ( T_3 ) V_4 << V_7 ) ;
F_5 ( V_2 , V_8 , V_5 ,
( ( T_3 ) V_9 << V_7 ) , ( ( T_3 ) V_6 << V_7 ) ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_4 )
{
F_3 ( V_2 , V_4 , 0xc40000 + V_3 ) ;
return 0 ;
}
int
F_7 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_4 , T_3 V_9 , T_3 V_6 )
{
F_5 ( V_2 , V_4 , 0xc40000 + V_3 , V_9 , V_6 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_4 )
{
F_9 ( V_2 , V_4 , 0xc40000 + V_3 ) ;
return 0 ;
}
T_2 F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
T_3 V_8 = F_2 ( V_2 , 0xc40000 + ( V_3 & ~ 3 ) ) ;
int V_7 = ( V_3 & 3 ) * 8 ;
return ( V_8 >> V_7 ) & 0xff ;
}
T_3 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , 0xc40000 + V_3 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 , unsigned V_10 ,
T_2 V_11 )
{
return F_1 ( V_2 , V_3 ,
( F_10 ( V_2 , V_3 ) & V_10 ) |
V_11 ) ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_10 ,
T_3 V_11 )
{
return F_6 ( V_2 , V_3 ,
( F_11 ( V_2 , V_3 ) & V_10 ) |
V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_12 , 0x160e040f ) ;
F_6 ( V_2 , V_13 , 0x002be2fe ) ;
F_6 ( V_2 , V_14 , 0x005227ad ) ;
F_1 ( V_2 , V_15 , 0x56 ) ;
}
static void F_15 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
struct V_1 * V_2 = F_17 ( V_17 ) ;
int V_20 ;
T_3 V_21 ;
F_18 ( V_2 ) ;
F_7 ( V_2 , V_22 , 0x03000000 ,
0x03000000 , 0x13000000 ) ;
V_21 = F_11 ( V_2 , V_23 ) ;
F_7 ( V_2 , V_23 , V_21 | 1 , V_21 , 0xfffe ) ;
F_7 ( V_2 , V_23 , V_21 & 0xfffe ,
V_21 & 0xfffe , 0xffff ) ;
V_21 = F_11 ( V_2 , V_24 ) & 0xE1FFFEFF ;
F_6 ( V_2 , V_24 , V_21 ) ;
F_6 ( V_2 , V_24 , V_21 | 0x10000100 ) ;
V_21 = F_11 ( V_2 , V_25 ) & 0xE1FFFEFF ;
F_6 ( V_2 , V_25 , V_21 ) ;
F_6 ( V_2 , V_25 , V_21 | 0x06000100 ) ;
F_6 ( V_2 , V_26 , 0x000A1802 ) ;
V_21 = F_11 ( V_2 , V_27 ) | 1 ;
F_7 ( V_2 , V_27 , V_21 , V_21 , 0x03009F0F ) ;
F_7 ( V_2 , V_27 ,
V_21 & 0xFFFFFFFE , V_21 & 0xFFFFFFFE , 0x03009F0F ) ;
F_13 ( V_2 , V_28 , ~ 0 , 0x040C00 ) ;
F_13 ( V_2 , V_29 , ~ 0 , 0x2 ) ;
F_6 ( V_2 , V_30 , 0x8000 ) ;
F_6 ( V_2 , V_30 , 0 ) ;
F_13 ( V_2 , V_31 , 0xFFFBFFFF , 0x00120000 ) ;
F_14 ( V_2 ) ;
F_13 ( V_2 , V_32 , 0xFFF7E7F0 , 0x02040800 ) ;
F_13 ( V_2 , V_33 , ~ 0 , 0x00500000 ) ;
F_13 ( V_2 , V_34 , 0xFFFF00FF , 0x00002000 ) ;
F_6 ( V_2 , V_35 , 0x4013252e ) ;
F_13 ( V_2 , V_36 , 0xFF000000 , 0x00005D00 ) ;
F_6 ( V_2 , V_37 , 0x6628021F ) ;
V_20 = F_10 ( V_2 , 0x8d4 ) ;
if ( V_20 > 228 ) {
V_20 = 228 ;
F_1 ( V_2 , 0x8d4 , 228 ) ;
} else if ( V_20 < 20 ) {
V_20 = 20 ;
F_1 ( V_2 , 0x8d4 , 20 ) ;
}
V_20 = ( ( ( 228 - V_20 ) >> 1 ) + 23 ) << 9 ;
V_19 -> V_38 -> V_39 . V_40 = V_19 -> V_38 -> V_41 = V_20 ;
F_19 ( & V_19 -> V_42 ) ;
}
static int F_20 ( struct V_16 * V_17 , T_3 V_40 )
{
F_15 ( V_17 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
if ( ! V_19 -> V_43 ) {
V_19 -> V_43 = 1 ;
F_15 ( V_17 ) ;
}
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_44 ;
struct V_16 * V_17 = & V_19 -> V_17 ;
T_4 V_45 = V_19 -> V_45 ;
const int V_46 = 0x21f ;
int V_47 , V_48 , V_49 , V_50 , V_51 , V_52 ;
int V_53 ;
int V_54 , V_55 , V_56 ;
T_3 V_57 , V_58 , V_59 ;
if ( V_45 & ~ V_60 )
F_1 ( V_2 , 0x49f , 0x11 ) ;
else
F_1 ( V_2 , 0x49f , 0x14 ) ;
if ( V_45 & V_61 ) {
V_53 = 48 ;
V_50 = 38 ;
V_51 = 579 ;
V_47 = 132 ;
V_48 = 720 ;
V_49 = 93 ;
V_54 = 2 ;
if ( V_45 & V_62 ) {
V_55 = 1 ;
V_56 = 0x20 ;
V_52 = 688700 ;
} else if ( V_45 == V_63 ) {
V_55 = 1 ;
V_56 = 0x20 ;
V_52 = 556422 ;
} else {
V_55 = 0 ;
V_56 = 0 ;
V_52 = 672314 ;
}
} else {
V_53 = 38 ;
V_50 = 26 ;
V_51 = 481 ;
V_48 = 720 ;
V_47 = 122 ;
V_54 = 1 ;
V_55 = 1 ;
if ( V_45 == V_64 ) {
V_49 = 90 ;
V_54 = 2 ;
V_56 = 0x20 ;
V_52 = 688700 ;
} else if ( V_45 == V_65 ) {
V_49 = 97 ;
V_56 = 0x20 ;
V_52 = 555421 ;
} else {
V_49 = 90 ;
V_56 = 0x66 ;
V_52 = 556032 ;
}
}
V_57 = F_10 ( V_2 , 0x108 ) ;
V_58 = F_11 ( V_2 , 0x10c ) & 0x1ffffff ;
V_59 = F_10 ( V_2 , 0x109 ) ;
F_23 ( V_17 , L_1 ,
V_57 , V_58 , V_59 ) ;
if ( V_59 ) {
int V_66 , V_67 ;
T_5 V_68 ;
V_67 = ( 28636360L * ( ( ( ( T_5 ) V_57 ) << 25 ) + V_58 ) ) >> 25 ;
V_67 /= V_59 ;
F_23 ( V_17 , L_2 ,
V_67 / 1000000 , V_67 % 1000000 ) ;
F_23 ( V_17 , L_3 ,
V_67 / 8000000 , ( V_67 / 8 ) % 1000000 ) ;
F_23 ( V_17 , L_4
L_5 , V_46 / 256 ,
( ( V_46 % 256 ) * 1000 ) / 256 ) ;
V_68 = 28636360 * ( T_5 ) V_52 ;
F_24 ( V_68 , V_46 ) ;
V_66 = V_68 >> 13 ;
F_23 ( V_17 ,
L_6
L_7 , V_66 / 1000000 , V_66 % 1000000 ) ;
F_23 ( V_17 , L_8
L_9
L_10
L_11 ,
V_47 , V_48 , V_50 , V_51 , V_53 ,
V_46 , V_49 , V_54 , V_55 ,
V_56 , V_52 ) ;
}
F_1 ( V_2 , 0x470 , V_47 ) ;
F_1 ( V_2 , 0x471 ,
( ( ( V_47 >> 8 ) & 0x3 ) | ( V_48 << 4 ) ) & 0xff ) ;
F_1 ( V_2 , 0x472 , V_48 >> 4 ) ;
F_1 ( V_2 , 0x473 , V_49 ) ;
F_1 ( V_2 , 0x474 , V_50 ) ;
F_1 ( V_2 , 0x475 ,
( ( ( V_50 >> 8 ) & 0x3 ) | ( V_51 << 4 ) ) & 0xff ) ;
F_1 ( V_2 , 0x476 , V_51 >> 4 ) ;
F_1 ( V_2 , 0x477 , V_53 ) ;
F_1 ( V_2 , 0x478 , V_46 & 0xff ) ;
F_1 ( V_2 , 0x479 , ( V_46 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x47a , V_54 << 6 | ( ( V_55 << 4 ) & 0x30 ) ) ;
F_1 ( V_2 , 0x47b , V_56 ) ;
F_1 ( V_2 , 0x47c , V_52 ) ;
F_1 ( V_2 , 0x47d , ( V_52 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x47e , ( V_52 >> 16 ) & 0xff ) ;
if ( V_45 & V_61 ) {
V_19 -> V_69 = 1 ;
V_19 -> V_70 = ( 6 + V_19 -> V_69 - 2 ) ;
} else {
V_19 -> V_69 = 0 ;
V_19 -> V_70 = ( 10 + V_19 -> V_69 - 2 ) ;
}
F_1 ( V_2 , 0x47f , V_19 -> V_69 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_44 ;
T_4 V_45 = V_19 -> V_45 ;
T_2 V_21 ;
F_1 ( V_2 , 0x49f , ( V_45 & V_60 ) ? 0x14 : 0x11 ) ;
F_12 ( V_2 , 0x401 , ~ 0x60 , 0 ) ;
F_12 ( V_2 , 0x401 , ~ 0x60 , 0x60 ) ;
if ( V_45 & V_71 ) {
if ( V_45 == V_72 ) {
F_4 ( V_2 , 0x808 , 0xf7 , 0xf7 , 0xff ) ;
F_4 ( V_2 , 0x80b , 0x02 , 0x02 , 0x3f ) ;
} else if ( V_45 == V_73 ) {
F_4 ( V_2 , 0x808 , 0xf8 , 0xf8 , 0xff ) ;
F_4 ( V_2 , 0x80b , 0x03 , 0x03 , 0x3f ) ;
} else {
F_4 ( V_2 , 0x808 , 0xf6 , 0xf6 , 0xff ) ;
F_4 ( V_2 , 0x80b , 0x01 , 0x01 , 0x3f ) ;
}
} else if ( V_45 & V_62 ) {
F_4 ( V_2 , 0x808 , 0xff , 0xff , 0xff ) ;
F_4 ( V_2 , 0x80b , 0x03 , 0x03 , 0x3f ) ;
} else if ( V_45 & V_74 ) {
F_4 ( V_2 , 0x808 , 0xff , 0xff , 0xff ) ;
F_4 ( V_2 , 0x80b , 0x03 , 0x03 , 0x3f ) ;
}
V_21 = F_10 ( V_2 , 0x803 ) ;
if ( V_21 & 0x10 ) {
V_21 &= ~ 0x10 ;
F_4 ( V_2 , 0x803 , V_21 , V_21 , 0x1f ) ;
V_21 |= 0x10 ;
F_4 ( V_2 , 0x803 , V_21 , V_21 , 0x1f ) ;
}
}
static int F_26 ( struct V_16 * V_17 ,
const struct V_75 * V_76 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , enum V_77 V_78 ,
enum V_79 V_80 )
{
struct V_18 * V_19 = & V_2 -> V_44 ;
struct V_16 * V_17 = & V_19 -> V_17 ;
enum T_6 {
V_81 , V_82 , V_83 , V_84 , V_85 , V_86 , V_87
} V_88 [ 3 ] = { V_81 , V_81 , V_81 } ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_3 V_92 ;
int V_93 ;
F_23 ( V_17 , L_12 ,
V_78 , V_80 ) ;
if ( V_78 >= V_94 &&
V_78 <= V_95 ) {
V_89 = 0xf0 + ( V_78 - V_94 ) ;
V_88 [ 0 ] = V_82 ;
V_91 = 0x0 ;
} else if ( V_78 >= V_96 ) {
int V_97 = V_78 & 0xf000 ;
int V_98 = V_78 & 0xf0000 ;
int V_99 = V_78 & 0xf00000 ;
if ( ( V_78 & ~ 0xfff000 ) ||
V_97 < V_96 ||
V_97 > V_100 ||
V_98 < V_101 ||
V_98 > V_102 ||
V_99 < V_103 ||
V_99 > V_104 ) {
F_28 ( V_17 , L_13 ,
V_78 ) ;
return - V_105 ;
}
V_89 = ( V_97 - V_96 ) >> 12 ;
V_88 [ 0 ] = V_83 ;
V_89 |= ( V_98 - V_101 ) >> 12 ;
V_88 [ 1 ] = V_87 ;
V_89 |= ( V_99 - V_103 ) >> 14 ;
V_88 [ 2 ] = V_86 ;
V_91 = 0x6 ;
} else {
int V_97 = V_78 & 0xf0 ;
int V_106 = V_78 & 0xf00 ;
if ( ( V_78 & ~ 0xff0 ) ||
V_97 < V_107 ||
V_97 > V_108 ||
V_106 < V_109 ||
V_106 > V_110 ) {
F_28 ( V_17 , L_13 ,
V_78 ) ;
return - V_105 ;
}
V_89 = 0xf0 + ( ( V_97 - V_107 ) >> 4 ) ;
V_88 [ 0 ] = V_83 ;
if ( V_106 >= V_111 ) {
V_89 &= 0x3f ;
V_89 |= ( V_106 - V_111 ) >> 2 ;
V_88 [ 2 ] = V_84 ;
} else {
V_89 &= 0xcf ;
V_89 |= ( V_106 - V_109 ) >> 4 ;
V_88 [ 1 ] = V_84 ;
}
V_91 = 0x2 ;
}
switch ( V_80 ) {
case V_112 :
case V_113 :
break;
case V_114 :
V_89 &= ~ 0x30 ;
V_88 [ 1 ] = V_85 ;
break;
case V_115 :
V_89 = ( V_89 & ~ 0x30 ) | 0x10 ;
V_88 [ 1 ] = V_85 ;
break;
case V_116 :
V_89 = ( V_89 & ~ 0x30 ) | 0x20 ;
V_88 [ 1 ] = V_85 ;
break;
case V_117 :
V_89 &= ~ 0xc0 ;
V_88 [ 2 ] = V_85 ;
break;
case V_118 :
V_89 = ( V_89 & ~ 0xc0 ) | 0x40 ;
V_88 [ 2 ] = V_85 ;
break;
default:
F_28 ( V_17 , L_14 ,
V_80 ) ;
return - V_105 ;
}
F_4 ( V_2 , 0x103 , V_89 , V_89 , 0xf7 ) ;
F_12 ( V_2 , 0x401 , ~ 0x6 , V_91 ) ;
V_90 = F_10 ( V_2 , 0x102 ) ;
if ( V_88 [ 2 ] == V_81 )
V_90 &= ~ 0x2 ;
else
V_90 |= 0x2 ;
if ( V_88 [ 1 ] != V_81 && V_88 [ 2 ] != V_81 )
V_90 |= 0x4 ;
else
V_90 &= ~ 0x4 ;
F_4 ( V_2 , 0x102 , V_90 , V_90 , 0x17 ) ;
V_92 = F_11 ( V_2 , V_36 ) ;
V_92 &= 0xff000000 ;
V_92 |= 0x00005000 ;
if ( V_88 [ 1 ] != V_81 && V_88 [ 2 ] != V_81 )
V_92 |= 0x00000030 ;
for ( V_93 = 0 ; V_93 < 3 ; V_93 ++ ) {
switch ( V_88 [ V_93 ] ) {
default:
case V_81 :
V_92 |= ( 0x00000200 << V_93 ) ;
break;
case V_82 :
case V_83 :
if ( V_93 > 0 )
V_92 |= 0x00002000 ;
break;
case V_84 :
case V_86 :
case V_87 :
V_92 |= ( 0x00000200 << V_93 ) ;
if ( V_93 == 0 && V_88 [ V_93 ] == V_84 )
V_92 &= ~ 0x00001000 ;
break;
case V_85 :
V_92 |= ( 0x00000240 << V_93 ) ;
if ( V_93 == 0 )
V_92 &= ~ 0x00004000 ;
break;
}
}
F_6 ( V_2 , V_36 , V_92 ) ;
V_19 -> V_78 = V_78 ;
V_19 -> V_80 = V_80 ;
F_29 ( V_2 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_16 * V_17 ,
T_3 V_119 , T_3 V_120 , T_3 V_121 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
struct V_1 * V_2 = F_17 ( V_17 ) ;
return F_27 ( V_2 , V_119 , V_19 -> V_80 ) ;
}
static int F_31 ( struct V_16 * V_17 ,
T_3 V_119 , T_3 V_120 , T_3 V_121 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
struct V_1 * V_2 = F_17 ( V_17 ) ;
return F_27 ( V_2 , V_19 -> V_78 , V_119 ) ;
}
static int F_32 ( struct V_16 * V_17 , struct V_122 * V_123 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
struct V_1 * V_2 = F_17 ( V_17 ) ;
T_2 V_124 ;
T_2 V_125 ;
int V_40 = 0 ;
if ( V_19 -> V_126 )
return 0 ;
V_124 = F_10 ( V_2 , 0x40e ) & 0x20 ;
V_123 -> signal = V_124 ? 0xffff : 0x0 ;
V_123 -> V_127 |=
V_128 | V_129 |
V_130 | V_131 ;
V_125 = F_10 ( V_2 , 0x804 ) ;
if ( ( V_125 & 0xf ) == 1 )
V_40 |= V_132 ;
else
V_40 |= V_133 ;
if ( V_125 == 2 || V_125 == 4 )
V_40 = V_134 | V_135 ;
if ( V_125 & 0x10 )
V_40 |= V_136 ;
V_123 -> V_137 = V_40 ;
V_123 -> V_138 = V_19 -> V_138 ;
return 0 ;
}
static int F_33 ( struct V_16 * V_17 , const struct V_122 * V_123 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
struct V_1 * V_2 = F_17 ( V_17 ) ;
T_2 V_21 ;
if ( V_19 -> V_126 )
return 0 ;
V_21 = F_10 ( V_2 , 0x809 ) ;
V_21 &= ~ 0xf ;
switch ( V_123 -> V_138 ) {
case V_139 :
break;
case V_140 :
case V_141 :
V_21 |= 0x4 ;
break;
case V_142 :
V_21 |= 0x7 ;
break;
case V_143 :
V_21 |= 0x1 ;
break;
default:
return - V_105 ;
}
F_4 ( V_2 , 0x809 , V_21 , V_21 , 0xff ) ;
V_19 -> V_138 = V_123 -> V_138 ;
return 0 ;
}
static int F_34 ( struct V_16 * V_17 , T_4 V_144 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
struct V_1 * V_2 = F_17 ( V_17 ) ;
T_2 V_145 = 0 ;
T_2 V_146 = 0 ;
if ( V_19 -> V_126 == 0 && V_19 -> V_45 == V_144 )
return 0 ;
V_19 -> V_126 = 0 ;
V_19 -> V_45 = V_144 ;
if ( V_19 -> V_45 == V_72 ) {
V_145 = 0x2 ;
} else if ( V_19 -> V_45 == V_147 ) {
V_145 = 0x3 ;
} else if ( V_19 -> V_45 == V_65 ) {
V_146 = 1 ;
V_145 = 0x5 ;
} else if ( V_19 -> V_45 == V_148 ) {
V_145 = 0x6 ;
} else if ( V_19 -> V_45 == V_63 ) {
V_145 = 0x7 ;
} else if ( V_19 -> V_45 == V_64 ) {
V_145 = 0x8 ;
} else {
if ( V_19 -> V_45 & V_60 )
V_145 = 0x1 ;
else if ( V_19 -> V_45 & V_62 )
V_145 = 0x4 ;
else if ( V_19 -> V_45 & V_74 )
V_145 = 0xc ;
}
F_23 ( V_17 , L_15 , V_145 ) ;
if ( V_145 >= 4 && V_145 < 8 ) {
F_12 ( V_2 , 0x400 , ~ 0xf , 1 ) ;
F_12 ( V_2 , 0x47b , ~ 6 , 0 ) ;
}
F_12 ( V_2 , 0x400 , ~ 0x2f , V_145 | 0x20 ) ;
F_12 ( V_2 , 0x403 , ~ 0x3 , V_146 ) ;
F_22 ( V_2 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
V_19 -> V_126 = 1 ;
return 0 ;
}
static int F_36 ( struct V_149 * V_150 )
{
struct V_16 * V_17 = F_37 ( V_150 ) ;
struct V_1 * V_2 = F_17 ( V_17 ) ;
switch ( V_150 -> V_151 ) {
case V_152 :
F_1 ( V_2 , 0x414 , V_150 -> V_40 - 128 ) ;
break;
case V_153 :
F_1 ( V_2 , 0x415 , V_150 -> V_40 << 1 ) ;
break;
case V_154 :
F_1 ( V_2 , 0x420 , V_150 -> V_40 << 1 ) ;
F_1 ( V_2 , 0x421 , V_150 -> V_40 << 1 ) ;
break;
case V_155 :
F_1 ( V_2 , 0x422 , V_150 -> V_40 ) ;
break;
default:
return - V_105 ;
}
return 0 ;
}
static int F_38 ( struct V_16 * V_17 , struct V_156 * V_145 )
{
struct V_18 * V_19 = F_16 ( V_17 ) ;
struct V_1 * V_2 = F_17 ( V_17 ) ;
int V_157 , V_158 , V_159 , V_160 , V_161 , V_162 ;
int V_163 = ! ( V_19 -> V_45 & V_71 ) ;
if ( V_145 -> V_164 != V_165 )
return - V_105 ;
V_145 -> V_166 = V_167 ;
V_145 -> V_168 = V_169 ;
V_159 = ( F_10 ( V_2 , 0x476 ) & 0x3f ) << 4 ;
V_159 |= ( F_10 ( V_2 , 0x475 ) & 0xf0 ) >> 4 ;
V_160 = ( F_10 ( V_2 , 0x472 ) & 0x3f ) << 4 ;
V_160 |= ( F_10 ( V_2 , 0x471 ) & 0xf0 ) >> 4 ;
V_162 = V_145 -> V_170 + ( V_163 ? 3 : 1 ) ;
if ( ( V_145 -> V_171 * 16 < V_160 ) || ( V_160 < V_145 -> V_171 ) ||
( V_162 * 8 < V_159 ) || ( V_159 < V_162 ) ) {
F_28 ( V_17 , L_16 ,
V_145 -> V_171 , V_145 -> V_170 ) ;
return - V_172 ;
}
V_157 = ( V_160 * ( 1 << 20 ) ) / V_145 -> V_171 - ( 1 << 20 ) ;
V_158 = ( 1 << 16 ) - ( V_159 * ( 1 << 9 ) / V_162 - ( 1 << 9 ) ) ;
V_158 &= 0x1fff ;
if ( V_145 -> V_171 >= 385 )
V_161 = 0 ;
else if ( V_145 -> V_171 > 192 )
V_161 = 1 ;
else if ( V_145 -> V_171 > 96 )
V_161 = 2 ;
else
V_161 = 3 ;
F_23 ( V_17 ,
L_17 ,
V_145 -> V_171 , V_145 -> V_170 , V_157 , V_158 ) ;
F_1 ( V_2 , 0x418 , V_157 & 0xff ) ;
F_1 ( V_2 , 0x419 , ( V_157 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x41a , V_157 >> 16 ) ;
F_1 ( V_2 , 0x41c , V_158 & 0xff ) ;
F_1 ( V_2 , 0x41d , V_158 >> 8 ) ;
F_1 ( V_2 , 0x41e , 0x8 | V_161 ) ;
return 0 ;
}
static int F_39 ( struct V_16 * V_17 , int V_173 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
F_23 ( V_17 , L_18 , V_173 ? L_19 : L_20 ) ;
if ( V_173 ) {
F_1 ( V_2 , 0x115 , 0x8c ) ;
F_1 ( V_2 , 0x116 , 0x07 ) ;
} else {
F_1 ( V_2 , 0x115 , 0x00 ) ;
F_1 ( V_2 , 0x116 , 0x00 ) ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
static const char * const V_174 [] = {
L_21 ,
L_22 , L_23 , L_24 ,
L_25 , L_26 , L_27 , L_28 , L_29 ,
L_30 , L_31 , L_32 ,
L_33 ,
L_34 , L_35 , L_36
} ;
struct V_18 * V_19 = & V_2 -> V_44 ;
struct V_16 * V_17 = & V_19 -> V_17 ;
T_2 V_175 = F_10 ( V_2 , 0x400 ) & 0xf ;
T_2 V_176 = F_10 ( V_2 , 0x40d ) ;
T_2 V_177 = F_10 ( V_2 , 0x40e ) ;
int V_78 = V_19 -> V_78 ;
F_41 ( V_17 , L_37 ,
( V_177 & 0x20 ) ? L_38 : L_39 ) ;
F_41 ( V_17 , L_40 ,
V_174 [ V_176 & 0xf ] ) ;
F_41 ( V_17 , L_41 ,
V_175 ? V_174 [ V_175 ]
: L_42 ) ;
if ( V_78 >= V_94 &&
V_78 <= V_95 ) {
F_41 ( V_17 , L_43 ,
V_78 - V_94 + 1 ) ;
} else {
F_41 ( V_17 , L_44
L_45 ,
( V_78 & 0xf0 ) >> 4 ,
( V_78 & 0xf00 ) >> 8 ) ;
}
F_41 ( V_17 , L_46 ,
V_19 -> V_178 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_44 ;
struct V_16 * V_17 = & V_19 -> V_17 ;
T_2 V_179 = F_10 ( V_2 , 0x803 ) ;
T_2 V_180 = F_10 ( V_2 , 0x804 ) ;
T_2 V_181 = F_10 ( V_2 , 0x805 ) ;
T_2 V_182 = F_10 ( V_2 , 0x808 ) ;
T_2 V_183 = F_10 ( V_2 , 0x809 ) ;
T_2 V_184 = F_10 ( V_2 , 0x80b ) ;
T_2 V_185 = F_10 ( V_2 , 0x8d3 ) ;
int V_80 = V_19 -> V_80 ;
char * V_186 ;
switch ( V_180 ) {
case 0x00 : V_186 = L_47 ; break;
case 0x01 : V_186 = L_48 ; break;
case 0x02 : V_186 = L_49 ; break;
case 0x04 : V_186 = L_50 ; break;
case 0x10 : V_186 = L_51 ; break;
case 0x11 : V_186 = L_52 ; break;
case 0x12 : V_186 = L_53 ; break;
case 0x14 : V_186 = L_54 ; break;
case 0xfe : V_186 = L_55 ; break;
default: V_186 = L_56 ; break;
}
F_41 ( V_17 , L_57 , V_186 ) ;
switch ( V_181 ) {
case 0x00 : V_186 = L_56 ; break;
case 0x01 : V_186 = L_58 ; break;
case 0x02 : V_186 = L_59 ; break;
case 0x03 : V_186 = L_60 ; break;
case 0x04 : V_186 = L_61 ; break;
case 0x05 : V_186 = L_62 ; break;
case 0x06 : V_186 = L_63 ; break;
case 0x07 : V_186 = L_64 ; break;
case 0x08 : V_186 = L_65 ; break;
case 0x09 : V_186 = L_66 ; break;
case 0x0a : V_186 = L_67 ; break;
case 0x0b : V_186 = L_68 ; break;
case 0x0c : V_186 = L_69 ; break;
case 0x0d : V_186 = L_70 ; break;
case 0x0e : V_186 = L_71 ; break;
case 0x0f : V_186 = L_72 ; break;
case 0x10 : V_186 = L_73 ; break;
case 0xfd : V_186 = L_74 ; break;
case 0xfe : V_186 = L_75 ; break;
case 0xff : V_186 = L_76 ; break;
default: V_186 = L_56 ; break;
}
F_41 ( V_17 , L_77 , V_186 ) ;
F_41 ( V_17 , L_78 ,
( V_185 & 0x2 ) ? L_79 : L_80 ) ;
F_41 ( V_17 , L_81 ,
( V_179 & 0x10 ) ? L_82 : L_83 ) ;
switch ( V_182 >> 4 ) {
case 0x00 : V_186 = L_84 ; break;
case 0x01 : V_186 = L_72 ; break;
case 0x02 : V_186 = L_58 ; break;
case 0x03 : V_186 = L_59 ; break;
case 0x04 : V_186 = L_60 ; break;
case 0x05 : V_186 = L_61 ; break;
case 0x06 : V_186 = L_62 ; break;
case 0x07 : V_186 = L_63 ; break;
case 0x08 : V_186 = L_64 ; break;
case 0x09 : V_186 = L_65 ; break;
case 0x0a : V_186 = L_66 ; break;
case 0x0b : V_186 = L_67 ; break;
case 0x0c : V_186 = L_68 ; break;
case 0x0d : V_186 = L_69 ; break;
case 0x0e : V_186 = L_85 ; break;
case 0x0f : V_186 = L_42 ; break;
default: V_186 = L_84 ; break;
}
F_41 ( V_17 , L_86 , V_186 ) ;
if ( ( V_182 >> 4 ) < 0xF ) {
switch ( V_182 & 0xF ) {
case 0x00 : V_186 = L_87 ; break;
case 0x01 : V_186 = L_88 ; break;
case 0x02 : V_186 = L_89 ; break;
case 0x03 : V_186 = L_90 ; break;
case 0x04 : V_186 = L_91 ; break;
case 0x05 : V_186 = L_92 ; break;
case 0x06 : V_186 = L_93 ; break;
case 0x07 : V_186 = L_94 ; break;
default: V_186 = L_84 ;
}
F_41 ( V_17 , L_95 , V_186 ) ;
} else {
switch ( V_182 & 0xF ) {
case 0x00 : V_186 = L_96 ; break;
case 0x01 : V_186 = L_97 ; break;
case 0x02 : V_186 = L_98 ; break;
case 0x03 : V_186 = L_99 ; break;
case 0x04 : V_186 = L_100 ; break;
case 0x05 : V_186 = L_101 ; break;
case 0x06 : V_186 = L_72 ; break;
case 0x07 : V_186 = L_58 ; break;
case 0x08 : V_186 = L_59 ; break;
case 0x09 : V_186 = L_102 ; break;
case 0x0a : V_186 = L_103 ; break;
case 0x0b : V_186 = L_104 ; break;
case 0x0f : V_186 = L_105 ; break;
default: V_186 = L_84 ; break;
}
F_41 ( V_17 , L_106 , V_186 ) ;
}
if ( V_80 )
F_41 ( V_17 , L_107 ,
V_80 ) ;
else
F_41 ( V_17 , L_108 ) ;
switch ( V_183 & 0xf ) {
case 0 : V_186 = L_109 ; break;
case 1 : V_186 = L_110 ; break;
case 2 : V_186 = L_111 ; break;
case 3 : V_186 = L_112 ; break;
case 4 : V_186 = L_48 ; break;
case 5 : V_186 = L_113 ; break;
case 6 : V_186 = L_114 ; break;
case 7 : V_186 = L_115 ; break;
default: V_186 = L_84 ; break;
}
F_41 ( V_17 , L_116 , V_186 ) ;
if ( ( V_182 & 0xf ) == 0xf ) {
switch ( ( V_184 >> 3 ) & 0x1 ) {
case 0 : V_186 = L_117 ; break;
case 1 : V_186 = L_118 ; break;
}
F_41 ( V_17 , L_119 , V_186 ) ;
switch ( V_184 & 0x7 ) {
case 0 : V_186 = L_120 ; break;
case 1 : V_186 = L_72 ; break;
case 2 : V_186 = L_58 ; break;
case 3 : V_186 = L_59 ; break;
case 4 : V_186 = L_121 ; break;
default: V_186 = L_84 ; break;
}
F_41 ( V_17 , L_122 , V_186 ) ;
}
}
static int F_43 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_16 * V_17 ,
struct V_187 * V_5 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
if ( ( V_5 -> V_5 & 0x3 ) != 0 )
return - V_105 ;
V_5 -> V_188 = 4 ;
V_5 -> V_40 = F_11 ( V_2 , V_5 -> V_5 & 0x00000ffc ) ;
return 0 ;
}
static int F_45 ( struct V_16 * V_17 ,
const struct V_187 * V_5 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
if ( ( V_5 -> V_5 & 0x3 ) != 0 )
return - V_105 ;
F_6 ( V_2 , V_5 -> V_5 & 0x00000ffc , V_5 -> V_40 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_44 ;
struct V_16 * V_17 ;
int V_189 ;
V_19 -> V_190 = F_11 ( V_2 , V_31 ) & 0xffff ;
V_19 -> V_78 = V_191 ;
V_19 -> V_80 = V_118 ;
V_19 -> V_178 = 48000 ;
V_19 -> V_138 = V_141 ;
V_19 -> V_69 = 0 ;
V_19 -> V_70 = ( 10 + V_19 -> V_69 - 2 ) ;
V_17 = & V_19 -> V_17 ;
F_47 ( V_17 , & V_192 ) ;
F_48 ( V_17 , V_2 ) ;
snprintf ( V_17 -> V_193 , sizeof( V_17 -> V_193 ) ,
L_123 , V_2 -> V_194 . V_193 , ( V_19 -> V_190 >> 4 ) ) ;
V_17 -> V_195 = V_196 ;
F_49 ( & V_19 -> V_42 , 9 ) ;
F_50 ( & V_19 -> V_42 , & V_197 ,
V_152 , 0 , 255 , 1 , 128 ) ;
F_50 ( & V_19 -> V_42 , & V_197 ,
V_153 , 0 , 127 , 1 , 64 ) ;
F_50 ( & V_19 -> V_42 , & V_197 ,
V_154 , 0 , 127 , 1 , 64 ) ;
F_50 ( & V_19 -> V_42 , & V_197 ,
V_155 , - 128 , 127 , 1 , 0 ) ;
V_19 -> V_38 = F_50 ( & V_19 -> V_42 ,
& V_198 , V_199 ,
0 , 65535 , 65535 / 100 , 0 ) ;
F_50 ( & V_19 -> V_42 ,
& V_198 , V_200 ,
0 , 1 , 1 , 0 ) ;
F_50 ( & V_19 -> V_42 , & V_198 ,
V_201 ,
0 , 65535 , 65535 / 100 , 32768 ) ;
F_50 ( & V_19 -> V_42 , & V_198 ,
V_202 ,
0 , 65535 , 65535 / 100 , 32768 ) ;
F_50 ( & V_19 -> V_42 , & V_198 ,
V_203 ,
0 , 65535 , 65535 / 100 , 32768 ) ;
V_17 -> V_204 = & V_19 -> V_42 ;
if ( V_19 -> V_42 . error ) {
int V_189 = V_19 -> V_42 . error ;
F_51 ( & V_19 -> V_42 ) ;
return V_189 ;
}
V_189 = F_52 ( & V_2 -> V_194 , V_17 ) ;
if ( V_189 )
F_51 ( & V_19 -> V_42 ) ;
else
F_14 ( V_2 ) ;
return V_189 ;
}
