static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 ,
T_1 V_6 )
{
F_2 ( V_2 , V_7 , V_3 ) ;
F_3 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_9 , V_4 ) ;
F_3 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_9 , V_5 ) ;
F_3 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_9 , V_6 ) ;
F_3 ( V_2 , V_8 ) ;
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_14 * V_14 = F_5 ( V_11 ) ;
int V_15 ;
if ( ! V_11 -> V_16 )
return;
for ( V_15 = 0 ; V_15 < 256 ; V_15 ++ )
F_1 ( V_2 , V_15 , V_14 -> V_17 [ V_15 ] ,
V_14 -> V_18 [ V_15 ] , V_14 -> V_19 [ V_15 ] ) ;
}
static bool F_6 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_20 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_2 V_25 = 0 , V_26 , V_27 , V_28 ;
T_2 V_29 , V_30 ;
switch ( V_11 -> V_31 -> V_32 -> V_33 ) {
case 8 :
V_24 -> V_34 = & V_35 [ V_36 ] ;
V_27 = V_36 - 1 ;
break;
case 16 :
V_24 -> V_34 = & V_35 [ V_37 ] ;
V_27 = V_37 ;
break;
case 24 :
case 32 :
V_24 -> V_34 = & V_35 [ V_38 ] ;
V_27 = V_38 ;
break;
default:
return false ;
}
switch ( V_11 -> V_21 . V_39 ) {
case 640 :
V_24 -> V_40 = & V_41 [ V_25 ] ;
break;
case 800 :
V_24 -> V_40 = & V_42 [ V_25 ] ;
break;
case 1024 :
V_24 -> V_40 = & V_43 [ V_25 ] ;
break;
case 1280 :
if ( V_11 -> V_21 . V_44 == 800 )
V_24 -> V_40 = & V_45 [ V_25 ] ;
else
V_24 -> V_40 = & V_46 [ V_25 ] ;
break;
case 1360 :
V_24 -> V_40 = & V_47 [ V_25 ] ;
break;
case 1440 :
V_24 -> V_40 = & V_48 [ V_25 ] ;
break;
case 1600 :
if ( V_11 -> V_21 . V_44 == 900 )
V_24 -> V_40 = & V_49 [ V_25 ] ;
else
V_24 -> V_40 = & V_50 [ V_25 ] ;
break;
case 1680 :
V_24 -> V_40 = & V_51 [ V_25 ] ;
break;
case 1920 :
if ( V_11 -> V_21 . V_44 == 1080 )
V_24 -> V_40 = & V_52 [ V_25 ] ;
else
V_24 -> V_40 = & V_53 [ V_25 ] ;
break;
default:
return false ;
}
V_28 = F_7 ( V_21 ) ;
while ( V_24 -> V_40 -> V_28 < V_28 ) {
V_24 -> V_40 ++ ;
if ( ( V_24 -> V_40 -> V_28 > V_28 ) ||
( V_24 -> V_40 -> V_28 == 0xff ) ) {
V_24 -> V_40 -- ;
break;
}
}
V_29 = ( V_24 -> V_40 -> V_54 & V_55 ) ? 8 : 0 ;
V_30 = ( V_24 -> V_40 -> V_54 & V_56 ) ? 8 : 0 ;
V_22 -> V_57 = V_24 -> V_40 -> V_58 ;
V_22 -> V_59 = V_24 -> V_40 -> V_60 + V_29 ;
V_22 -> V_61 = V_24 -> V_40 -> V_58 - V_29 ;
V_22 -> V_62 = V_24 -> V_40 -> V_60 + V_29 +
V_24 -> V_40 -> V_63 ;
V_22 -> V_64 = ( V_24 -> V_40 -> V_60 + V_29 +
V_24 -> V_40 -> V_63 +
V_24 -> V_40 -> V_65 ) ;
V_22 -> V_66 = V_24 -> V_40 -> V_67 ;
V_22 -> V_68 = V_24 -> V_40 -> V_69 + V_30 ;
V_22 -> V_70 = V_24 -> V_40 -> V_67 - V_30 ;
V_22 -> V_71 = V_24 -> V_40 -> V_69 + V_30 +
V_24 -> V_40 -> V_72 ;
V_22 -> V_73 = ( V_24 -> V_40 -> V_69 + V_30 +
V_24 -> V_40 -> V_72 +
V_24 -> V_40 -> V_74 ) ;
V_25 = V_24 -> V_40 -> V_25 ;
V_26 = V_24 -> V_40 -> V_26 ;
if ( V_2 -> V_75 == V_76 ) {
} else {
F_8 ( V_2 , V_77 , 0x8c , ( T_1 ) ( ( V_27 & 0xf ) << 4 ) ) ;
F_8 ( V_2 , V_77 , 0x8d , V_25 & 0xff ) ;
F_8 ( V_2 , V_77 , 0x8e , V_26 & 0xff ) ;
F_8 ( V_2 , V_77 , 0x91 , 0x00 ) ;
if ( V_24 -> V_40 -> V_54 & V_78 ) {
F_8 ( V_2 , V_77 , 0x91 , 0xa8 ) ;
F_8 ( V_2 , V_77 , 0x92 , V_11 -> V_31 -> V_32 -> V_33 ) ;
F_8 ( V_2 , V_77 , 0x93 , V_22 -> clock / 1000 ) ;
F_8 ( V_2 , V_77 , 0x94 , V_22 -> V_39 ) ;
F_8 ( V_2 , V_77 , 0x95 , V_22 -> V_39 >> 8 ) ;
F_8 ( V_2 , V_77 , 0x96 , V_22 -> V_44 ) ;
F_8 ( V_2 , V_77 , 0x97 , V_22 -> V_44 >> 8 ) ;
}
}
return true ;
}
static void F_9 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_79 * V_80 ;
T_2 V_15 ;
T_1 V_81 ;
V_80 = V_24 -> V_34 ;
V_81 = V_80 -> V_82 ;
F_2 ( V_2 , V_83 , V_81 ) ;
F_8 ( V_2 , V_8 , 0x00 , 0x03 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_81 = V_80 -> V_84 [ V_15 ] ;
if ( ! V_15 )
V_81 |= 0x20 ;
F_8 ( V_2 , V_8 , ( V_15 + 1 ) , V_81 ) ;
}
F_10 ( V_2 , V_77 , 0x11 , 0x7f , 0x00 ) ;
for ( V_15 = 0 ; V_15 < 25 ; V_15 ++ )
F_8 ( V_2 , V_77 , V_15 , V_80 -> V_11 [ V_15 ] ) ;
V_81 = F_3 ( V_2 , V_85 ) ;
for ( V_15 = 0 ; V_15 < 20 ; V_15 ++ ) {
V_81 = V_80 -> V_86 [ V_15 ] ;
F_2 ( V_2 , V_87 , ( T_1 ) V_15 ) ;
F_2 ( V_2 , V_87 , V_81 ) ;
}
F_2 ( V_2 , V_87 , 0x14 ) ;
F_2 ( V_2 , V_87 , 0x00 ) ;
V_81 = F_3 ( V_2 , V_85 ) ;
F_2 ( V_2 , V_87 , 0x20 ) ;
for ( V_15 = 0 ; V_15 < 9 ; V_15 ++ )
F_8 ( V_2 , V_88 , V_15 , V_80 -> V_89 [ V_15 ] ) ;
}
static void F_11 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_90 = 0 , V_91 = 0 , V_92 = 0 , V_93 = 0 , V_94 = 0 , V_95 = 0 ;
T_3 V_96 ;
F_10 ( V_2 , V_77 , 0x11 , 0x7f , 0x00 ) ;
V_96 = ( V_21 -> V_57 >> 3 ) - 5 ;
if ( V_96 & 0x100 )
V_93 |= 0x01 ;
F_10 ( V_2 , V_77 , 0x00 , 0x00 , V_96 ) ;
V_96 = ( V_21 -> V_39 >> 3 ) - 1 ;
if ( V_96 & 0x100 )
V_93 |= 0x04 ;
F_10 ( V_2 , V_77 , 0x01 , 0x00 , V_96 ) ;
V_96 = ( V_21 -> V_59 >> 3 ) - 1 ;
if ( V_96 & 0x100 )
V_93 |= 0x10 ;
F_10 ( V_2 , V_77 , 0x02 , 0x00 , V_96 ) ;
V_96 = ( ( V_21 -> V_61 >> 3 ) - 1 ) & 0x7f ;
if ( V_96 & 0x20 )
V_90 |= 0x80 ;
if ( V_96 & 0x40 )
V_94 |= 0x01 ;
F_10 ( V_2 , V_77 , 0x03 , 0xE0 , ( V_96 & 0x1f ) ) ;
V_96 = ( V_21 -> V_62 >> 3 ) - 1 ;
if ( V_96 & 0x100 )
V_93 |= 0x40 ;
F_10 ( V_2 , V_77 , 0x04 , 0x00 , V_96 ) ;
V_96 = ( ( V_21 -> V_64 >> 3 ) - 1 ) & 0x3f ;
if ( V_96 & 0x20 )
V_94 |= 0x04 ;
F_10 ( V_2 , V_77 , 0x05 , 0x60 , ( T_1 ) ( ( V_96 & 0x1f ) | V_90 ) ) ;
F_10 ( V_2 , V_77 , 0xAC , 0x00 , V_93 ) ;
F_10 ( V_2 , V_77 , 0xAD , 0x00 , V_94 ) ;
V_96 = ( V_21 -> V_66 ) - 2 ;
if ( V_96 & 0x100 )
V_91 |= 0x01 ;
if ( V_96 & 0x200 )
V_91 |= 0x20 ;
if ( V_96 & 0x400 )
V_95 |= 0x01 ;
F_10 ( V_2 , V_77 , 0x06 , 0x00 , V_96 ) ;
V_96 = ( V_21 -> V_71 ) - 1 ;
if ( V_96 & 0x100 )
V_91 |= 0x04 ;
if ( V_96 & 0x200 )
V_91 |= 0x80 ;
if ( V_96 & 0x400 )
V_95 |= 0x08 ;
F_10 ( V_2 , V_77 , 0x10 , 0x00 , V_96 ) ;
V_96 = ( V_21 -> V_73 - 1 ) & 0x3f ;
if ( V_96 & 0x10 )
V_95 |= 0x20 ;
if ( V_96 & 0x20 )
V_95 |= 0x40 ;
F_10 ( V_2 , V_77 , 0x11 , 0x70 , V_96 & 0xf ) ;
V_96 = V_21 -> V_44 - 1 ;
if ( V_96 & 0x100 )
V_91 |= 0x02 ;
if ( V_96 & 0x200 )
V_91 |= 0x40 ;
if ( V_96 & 0x400 )
V_95 |= 0x02 ;
F_10 ( V_2 , V_77 , 0x12 , 0x00 , V_96 ) ;
V_96 = V_21 -> V_68 - 1 ;
if ( V_96 & 0x100 )
V_91 |= 0x08 ;
if ( V_96 & 0x200 )
V_92 |= 0x20 ;
if ( V_96 & 0x400 )
V_95 |= 0x04 ;
F_10 ( V_2 , V_77 , 0x15 , 0x00 , V_96 ) ;
V_96 = V_21 -> V_70 - 1 ;
if ( V_96 & 0x100 )
V_95 |= 0x10 ;
F_10 ( V_2 , V_77 , 0x16 , 0x00 , V_96 ) ;
F_10 ( V_2 , V_77 , 0x07 , 0x00 , V_91 ) ;
F_10 ( V_2 , V_77 , 0x09 , 0xdf , V_92 ) ;
F_10 ( V_2 , V_77 , 0xAE , 0x00 , ( V_95 | 0x80 ) ) ;
F_10 ( V_2 , V_77 , 0x11 , 0x7f , 0x80 ) ;
}
static void F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_3 V_97 ;
V_97 = V_11 -> V_31 -> V_32 -> V_98 [ 0 ] >> 3 ;
F_8 ( V_2 , V_77 , 0x13 , ( V_97 & 0xff ) ) ;
F_8 ( V_2 , V_77 , 0xb0 , ( V_97 >> 8 ) & 0x3f ) ;
}
static void F_13 ( struct V_99 * V_12 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_100 * V_101 ;
V_101 = & V_102 [ V_24 -> V_40 -> V_103 ] ;
F_10 ( V_2 , V_77 , 0xc0 , 0x00 , V_101 -> V_104 ) ;
F_10 ( V_2 , V_77 , 0xc1 , 0x00 , V_101 -> V_105 ) ;
F_10 ( V_2 , V_77 , 0xbb , 0x0f ,
( V_101 -> V_106 & 0x80 ) | ( ( V_101 -> V_106 & 0x3 ) << 4 ) ) ;
}
static void F_14 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_107 = 0 , V_108 = 0 , V_109 = 0 ;
switch ( V_11 -> V_31 -> V_32 -> V_33 ) {
case 8 :
V_107 = 0x70 ;
V_108 = 0x01 ;
V_109 = 0x00 ;
break;
case 15 :
case 16 :
V_107 = 0x70 ;
V_108 = 0x04 ;
V_109 = 0x02 ;
break;
case 32 :
V_107 = 0x70 ;
V_108 = 0x08 ;
V_109 = 0x02 ;
break;
}
F_10 ( V_2 , V_77 , 0xa0 , 0x8f , V_107 ) ;
F_10 ( V_2 , V_77 , 0xa3 , 0xf0 , V_108 ) ;
F_10 ( V_2 , V_77 , 0xa8 , 0xfd , V_109 ) ;
if ( V_2 -> V_75 == V_110 || V_2 -> V_75 == V_111 ) {
F_8 ( V_2 , V_77 , 0xa7 , 0x78 ) ;
F_8 ( V_2 , V_77 , 0xa6 , 0x60 ) ;
} else if ( V_2 -> V_75 == V_112 ||
V_2 -> V_75 == V_113 ||
V_2 -> V_75 == V_114 ||
V_2 -> V_75 == V_115 ) {
F_8 ( V_2 , V_77 , 0xa7 , 0x3f ) ;
F_8 ( V_2 , V_77 , 0xa6 , 0x2f ) ;
} else {
F_8 ( V_2 , V_77 , 0xa7 , 0x2f ) ;
F_8 ( V_2 , V_77 , 0xa6 , 0x1f ) ;
}
}
static void F_15 ( struct V_99 * V_12 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
T_1 V_81 ;
V_81 = F_3 ( V_2 , V_116 ) ;
V_81 |= ( V_24 -> V_40 -> V_54 & V_117 ) ;
F_2 ( V_2 , V_83 , V_81 ) ;
}
static bool F_16 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
switch ( V_11 -> V_31 -> V_32 -> V_33 ) {
case 8 :
break;
default:
return false ;
}
return true ;
}
static void F_17 ( struct V_10 * V_11 , unsigned V_97 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_2 V_118 ;
V_118 = V_97 >> 2 ;
F_8 ( V_2 , V_77 , 0x0d , ( T_1 ) ( V_118 & 0xff ) ) ;
F_8 ( V_2 , V_77 , 0x0c , ( T_1 ) ( ( V_118 >> 8 ) & 0xff ) ) ;
F_8 ( V_2 , V_77 , 0xaf , ( T_1 ) ( ( V_118 >> 16 ) & 0xff ) ) ;
}
static void F_18 ( struct V_10 * V_11 , int V_21 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
if ( V_2 -> V_75 == V_76 )
return;
switch ( V_21 ) {
case V_119 :
case V_120 :
case V_121 :
F_10 ( V_2 , V_8 , 0x1 , 0xdf , 0 ) ;
if ( V_2 -> V_122 == V_123 )
F_19 ( V_11 -> V_12 , 1 ) ;
F_4 ( V_11 ) ;
break;
case V_124 :
if ( V_2 -> V_122 == V_123 )
F_19 ( V_11 -> V_12 , 0 ) ;
F_10 ( V_2 , V_8 , 0x1 , 0xdf , 0x20 ) ;
break;
}
}
static bool F_20 ( struct V_10 * V_11 ,
const struct V_20 * V_21 ,
struct V_20 * V_22 )
{
return true ;
}
static int F_21 ( struct V_10 * V_11 ,
struct V_125 * V_32 ,
int V_126 , int V_127 , int V_128 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
int V_135 ;
T_4 V_136 ;
if ( ! V_128 && V_32 ) {
V_132 = F_22 ( V_32 ) ;
V_130 = V_132 -> V_130 ;
V_134 = F_23 ( V_130 ) ;
V_135 = F_24 ( V_134 , false ) ;
if ( V_135 )
return V_135 ;
F_25 ( V_134 ) ;
F_26 ( V_134 ) ;
}
V_132 = F_22 ( V_11 -> V_31 -> V_32 ) ;
V_130 = V_132 -> V_130 ;
V_134 = F_23 ( V_130 ) ;
V_135 = F_24 ( V_134 , false ) ;
if ( V_135 )
return V_135 ;
V_135 = F_27 ( V_134 , V_137 , & V_136 ) ;
if ( V_135 ) {
F_26 ( V_134 ) ;
return V_135 ;
}
if ( & V_2 -> V_138 -> V_139 == V_132 ) {
V_135 = F_28 ( & V_134 -> V_134 , 0 , V_134 -> V_134 . V_140 , & V_134 -> V_141 ) ;
if ( V_135 )
F_29 ( L_1 ) ;
}
F_26 ( V_134 ) ;
F_17 ( V_11 , ( T_2 ) V_136 ) ;
return 0 ;
}
static int F_30 ( struct V_10 * V_11 , int V_126 , int V_127 ,
struct V_125 * V_142 )
{
return F_21 ( V_11 , V_142 , V_126 , V_127 , 0 ) ;
}
static int F_31 ( struct V_10 * V_11 ,
struct V_20 * V_21 ,
struct V_20 * V_22 ,
int V_126 , int V_127 ,
struct V_125 * V_142 )
{
struct V_99 * V_12 = V_11 -> V_12 ;
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_23 V_24 ;
bool V_135 ;
if ( V_2 -> V_75 == V_76 ) {
F_29 ( L_2 ) ;
return - V_143 ;
}
V_135 = F_6 ( V_11 , V_21 , V_22 , & V_24 ) ;
if ( V_135 == false )
return - V_143 ;
F_32 ( V_2 ) ;
F_10 ( V_2 , V_77 , 0xa1 , 0xff , 0x04 ) ;
F_9 ( V_11 , V_22 , & V_24 ) ;
F_11 ( V_11 , V_22 , & V_24 ) ;
F_12 ( V_11 ) ;
F_13 ( V_12 , V_22 , & V_24 ) ;
F_14 ( V_11 , V_22 , & V_24 ) ;
F_15 ( V_12 , V_22 , & V_24 ) ;
F_16 ( V_11 , V_22 , & V_24 ) ;
F_30 ( V_11 , V_126 , V_127 , V_142 ) ;
return 0 ;
}
static void F_33 ( struct V_10 * V_11 )
{
}
static void F_34 ( struct V_10 * V_11 )
{
}
static void F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
F_10 ( V_2 , V_8 , 0x1 , 0xdf , 0 ) ;
}
static void F_36 ( struct V_10 * V_11 )
{
}
static void F_37 ( struct V_10 * V_11 , T_3 * V_4 , T_3 * V_5 ,
T_3 * V_6 , T_5 V_144 , T_5 V_145 )
{
struct V_14 * V_14 = F_5 ( V_11 ) ;
int V_146 = ( V_144 + V_145 > 256 ) ? 256 : V_144 + V_145 , V_15 ;
for ( V_15 = V_144 ; V_15 < V_146 ; V_15 ++ ) {
V_14 -> V_17 [ V_15 ] = V_4 [ V_15 ] >> 8 ;
V_14 -> V_18 [ V_15 ] = V_5 [ V_15 ] >> 8 ;
V_14 -> V_19 [ V_15 ] = V_6 [ V_15 ] >> 8 ;
}
F_4 ( V_11 ) ;
}
static void F_38 ( struct V_10 * V_11 )
{
F_39 ( V_11 ) ;
F_40 ( V_11 ) ;
}
static int F_41 ( struct V_99 * V_12 )
{
struct V_14 * V_11 ;
int V_15 ;
V_11 = F_42 ( sizeof( struct V_14 ) , V_147 ) ;
if ( ! V_11 )
return - V_148 ;
F_43 ( V_12 , & V_11 -> V_149 , & V_150 ) ;
F_44 ( & V_11 -> V_149 , 256 ) ;
F_45 ( & V_11 -> V_149 , & V_151 ) ;
for ( V_15 = 0 ; V_15 < 256 ; V_15 ++ ) {
V_11 -> V_17 [ V_15 ] = V_15 ;
V_11 -> V_18 [ V_15 ] = V_15 ;
V_11 -> V_19 [ V_15 ] = V_15 ;
}
return 0 ;
}
static void F_46 ( struct V_152 * V_153 )
{
F_47 ( V_153 ) ;
F_40 ( V_153 ) ;
}
static struct V_152 * F_48 ( struct V_154 * V_155 )
{
int V_156 = V_155 -> V_157 [ 0 ] ;
struct V_158 * V_130 ;
struct V_152 * V_153 ;
if ( V_156 ) {
V_130 = F_49 ( V_155 -> V_12 , V_156 , V_159 ) ;
if ( ! V_130 )
return NULL ;
V_153 = F_50 ( V_130 ) ;
return V_153 ;
}
return NULL ;
}
static void F_51 ( struct V_152 * V_153 , int V_21 )
{
}
static bool F_52 ( struct V_152 * V_153 ,
const struct V_20 * V_21 ,
struct V_20 * V_22 )
{
return true ;
}
static void F_53 ( struct V_152 * V_153 ,
struct V_20 * V_21 ,
struct V_20 * V_22 )
{
}
static void F_54 ( struct V_152 * V_153 )
{
}
static void F_55 ( struct V_152 * V_153 )
{
}
static int F_56 ( struct V_99 * V_12 )
{
struct V_160 * V_160 ;
V_160 = F_42 ( sizeof( struct V_160 ) , V_147 ) ;
if ( ! V_160 )
return - V_148 ;
F_57 ( V_12 , & V_160 -> V_149 , & V_161 ,
V_162 ) ;
F_58 ( & V_160 -> V_149 , & V_163 ) ;
V_160 -> V_149 . V_164 = 1 ;
return 0 ;
}
static int F_59 ( struct V_154 * V_155 )
{
struct V_165 * V_165 = F_60 ( V_155 ) ;
struct V_1 * V_2 = V_155 -> V_12 -> V_13 ;
struct V_166 * V_166 ;
int V_135 ;
bool V_54 = false ;
if ( V_2 -> V_122 == V_123 ) {
V_2 -> V_167 = 0xff ;
V_166 = F_61 ( 128 , V_147 ) ;
if ( ! V_166 )
return - V_148 ;
V_54 = F_62 ( V_155 -> V_12 , ( T_1 * ) V_166 ) ;
if ( V_54 )
V_2 -> V_167 = F_63 ( V_155 -> V_12 ) ;
else
F_40 ( V_166 ) ;
}
if ( ! V_54 )
V_166 = F_64 ( V_155 , & V_165 -> V_168 -> V_169 ) ;
if ( V_166 ) {
F_65 ( & V_165 -> V_149 , V_166 ) ;
V_135 = F_66 ( V_155 , V_166 ) ;
F_40 ( V_166 ) ;
return V_135 ;
} else
F_65 ( & V_165 -> V_149 , NULL ) ;
return 0 ;
}
static int F_67 ( struct V_154 * V_155 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_155 -> V_12 -> V_13 ;
int V_54 = V_170 ;
T_5 V_171 ;
if ( V_2 -> V_172 ) {
if ( ( V_21 -> V_173 == 1680 ) && ( V_21 -> V_174 == 1050 ) )
return V_175 ;
if ( ( V_21 -> V_173 == 1280 ) && ( V_21 -> V_174 == 800 ) )
return V_175 ;
if ( ( V_21 -> V_173 == 1440 ) && ( V_21 -> V_174 == 900 ) )
return V_175 ;
if ( ( V_21 -> V_173 == 1360 ) && ( V_21 -> V_174 == 768 ) )
return V_175 ;
if ( ( V_21 -> V_173 == 1600 ) && ( V_21 -> V_174 == 900 ) )
return V_175 ;
if ( ( V_2 -> V_75 == V_112 ) || ( V_2 -> V_75 == V_114 ) || ( V_2 -> V_75 == V_110 ) || ( V_2 -> V_75 == V_111 ) || ( V_2 -> V_75 == V_76 ) ) {
if ( ( V_21 -> V_173 == 1920 ) && ( V_21 -> V_174 == 1080 ) )
return V_175 ;
if ( ( V_21 -> V_173 == 1920 ) && ( V_21 -> V_174 == 1200 ) ) {
V_171 = F_68 ( V_2 , V_77 , 0xd1 , 0xff ) ;
if ( V_171 & 0x01 )
return V_170 ;
else
return V_175 ;
}
}
}
switch ( V_21 -> V_173 ) {
case 640 :
if ( V_21 -> V_174 == 480 ) V_54 = V_175 ;
break;
case 800 :
if ( V_21 -> V_174 == 600 ) V_54 = V_175 ;
break;
case 1024 :
if ( V_21 -> V_174 == 768 ) V_54 = V_175 ;
break;
case 1280 :
if ( V_21 -> V_174 == 1024 ) V_54 = V_175 ;
break;
case 1600 :
if ( V_21 -> V_174 == 1200 ) V_54 = V_175 ;
break;
default:
return V_54 ;
}
return V_54 ;
}
static void F_69 ( struct V_154 * V_155 )
{
struct V_165 * V_165 = F_60 ( V_155 ) ;
F_70 ( V_165 -> V_168 ) ;
F_71 ( V_155 ) ;
F_72 ( V_155 ) ;
F_40 ( V_155 ) ;
}
static enum V_176
F_73 ( struct V_154 * V_155 , bool V_177 )
{
return V_178 ;
}
static int F_74 ( struct V_99 * V_12 )
{
struct V_165 * V_165 ;
struct V_154 * V_155 ;
struct V_152 * V_153 ;
V_165 = F_42 ( sizeof( struct V_165 ) , V_147 ) ;
if ( ! V_165 )
return - V_148 ;
V_155 = & V_165 -> V_149 ;
F_75 ( V_12 , V_155 , & V_179 , V_180 ) ;
F_76 ( V_155 , & V_181 ) ;
V_155 -> V_182 = 0 ;
V_155 -> V_183 = 0 ;
F_77 ( V_155 ) ;
V_155 -> V_184 = V_185 ;
V_153 = F_78 ( & V_12 -> V_186 . V_187 , struct V_152 , V_188 ) ;
F_79 ( V_155 , V_153 ) ;
V_165 -> V_168 = F_80 ( V_12 ) ;
if ( ! V_165 -> V_168 )
F_29 ( L_3 ) ;
return 0 ;
}
static int F_81 ( struct V_99 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
int V_145 ;
int V_135 ;
struct V_129 * V_130 ;
struct V_133 * V_134 ;
T_6 V_136 ;
V_145 = ( V_189 + V_190 ) * V_191 ;
V_135 = F_82 ( V_12 , V_145 , true , & V_130 ) ;
if ( V_135 )
return V_135 ;
V_134 = F_23 ( V_130 ) ;
V_135 = F_24 ( V_134 , false ) ;
if ( F_83 ( V_135 != 0 ) )
goto V_192;
V_135 = F_27 ( V_134 , V_137 , & V_136 ) ;
F_26 ( V_134 ) ;
if ( V_135 )
goto V_192;
V_135 = F_28 ( & V_134 -> V_134 , 0 , V_134 -> V_134 . V_140 , & V_2 -> V_193 ) ;
if ( V_135 )
goto V_192;
V_2 -> V_194 = V_130 ;
V_2 -> V_195 = V_136 ;
F_84 ( L_4 , V_2 -> V_195 ) ;
return 0 ;
V_192:
return V_135 ;
}
static void F_85 ( struct V_99 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
F_86 ( & V_2 -> V_193 ) ;
F_87 ( V_2 -> V_194 ) ;
}
int F_88 ( struct V_99 * V_12 )
{
F_81 ( V_12 ) ;
F_41 ( V_12 ) ;
F_56 ( V_12 ) ;
F_74 ( V_12 ) ;
return 0 ;
}
void F_89 ( struct V_99 * V_12 )
{
F_85 ( V_12 ) ;
}
static int F_90 ( void * V_196 )
{
struct V_197 * V_168 = V_196 ;
struct V_1 * V_2 = V_168 -> V_12 -> V_13 ;
T_5 V_198 ;
V_198 = F_68 ( V_2 , V_77 , 0xb7 , 0x10 ) >> 4 ;
return V_198 & 1 ? 1 : 0 ;
}
static int F_91 ( void * V_196 )
{
struct V_197 * V_168 = V_196 ;
struct V_1 * V_2 = V_168 -> V_12 -> V_13 ;
T_5 V_198 ;
V_198 = F_68 ( V_2 , V_77 , 0xb7 , 0x20 ) >> 5 ;
return V_198 & 1 ? 1 : 0 ;
}
static void F_92 ( void * V_196 , int clock )
{
struct V_197 * V_168 = V_196 ;
struct V_1 * V_2 = V_168 -> V_12 -> V_13 ;
int V_15 ;
T_1 V_199 , V_171 ;
for ( V_15 = 0 ; V_15 < 0x10000 ; V_15 ++ ) {
V_199 = ( ( clock & 0x01 ) ? 0 : 1 ) ;
F_10 ( V_2 , V_77 , 0xb7 , 0xfe , V_199 ) ;
V_171 = F_68 ( V_2 , V_77 , 0xb7 , 0x01 ) ;
if ( V_199 == V_171 )
break;
}
}
static void F_93 ( void * V_196 , int V_200 )
{
struct V_197 * V_168 = V_196 ;
struct V_1 * V_2 = V_168 -> V_12 -> V_13 ;
int V_15 ;
T_1 V_199 , V_171 ;
for ( V_15 = 0 ; V_15 < 0x10000 ; V_15 ++ ) {
V_199 = ( ( V_200 & 0x01 ) ? 0 : 1 ) << 2 ;
F_10 ( V_2 , V_77 , 0xb7 , 0xfb , V_199 ) ;
V_171 = F_68 ( V_2 , V_77 , 0xb7 , 0x04 ) ;
if ( V_199 == V_171 )
break;
}
}
static struct V_197 * F_80 ( struct V_99 * V_12 )
{
struct V_197 * V_168 ;
int V_135 ;
V_168 = F_42 ( sizeof( struct V_197 ) , V_147 ) ;
if ( ! V_168 )
return NULL ;
V_168 -> V_169 . V_201 = V_202 ;
V_168 -> V_169 . V_203 = V_204 ;
V_168 -> V_169 . V_12 . V_205 = & V_12 -> V_206 -> V_12 ;
V_168 -> V_12 = V_12 ;
F_94 ( & V_168 -> V_169 , V_168 ) ;
snprintf ( V_168 -> V_169 . V_207 , sizeof( V_168 -> V_169 . V_207 ) ,
L_5 ) ;
V_168 -> V_169 . V_208 = & V_168 -> V_209 ;
V_168 -> V_209 . V_210 = 20 ;
V_168 -> V_209 . V_211 = 2 ;
V_168 -> V_209 . V_200 = V_168 ;
V_168 -> V_209 . V_212 = F_93 ;
V_168 -> V_209 . V_213 = F_92 ;
V_168 -> V_209 . V_214 = F_91 ;
V_168 -> V_209 . V_215 = F_90 ;
V_135 = F_95 ( & V_168 -> V_169 ) ;
if ( V_135 ) {
F_29 ( L_6 ) ;
goto V_216;
}
return V_168 ;
V_216:
F_40 ( V_168 ) ;
return NULL ;
}
static void F_70 ( struct V_197 * V_168 )
{
if ( ! V_168 )
return;
F_96 ( & V_168 -> V_169 ) ;
F_40 ( V_168 ) ;
}
static void F_97 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_81 ;
V_81 = 0x2 ;
V_81 |= 1 ;
F_10 ( V_2 , V_77 , 0xcb , 0xfc , V_81 ) ;
}
static void F_98 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
F_10 ( V_2 , V_77 , 0xcb , 0xfc , 0x00 ) ;
}
static T_2 F_99 ( T_1 * V_217 , T_1 * V_218 , int V_219 , int V_220 )
{
union {
T_2 V_221 ;
T_1 V_222 [ 4 ] ;
} V_223 [ 2 ] , V_224 ;
union {
T_3 V_225 ;
T_1 V_222 [ 2 ] ;
} V_226 ;
T_2 V_227 = 0 ;
T_7 V_228 , V_229 ;
T_1 * V_230 , * V_231 ;
int V_15 , V_232 ;
T_2 V_233 , V_234 ;
V_228 = V_235 << 1 ;
V_229 = V_228 - ( V_219 << 1 ) ;
V_230 = V_217 ;
V_231 = ( T_1 * ) V_218 + V_229 + ( V_236 - V_220 ) * V_228 ;
V_233 = V_219 & 1 ;
V_234 = V_219 >> 1 ;
for ( V_232 = 0 ; V_232 < V_220 ; V_232 ++ ) {
for ( V_15 = 0 ; V_15 < V_234 ; V_15 ++ ) {
V_223 [ 0 ] . V_221 = * ( ( T_2 * ) V_230 ) & 0xf0f0f0f0 ;
V_223 [ 1 ] . V_221 = * ( ( T_2 * ) ( V_230 + 4 ) ) & 0xf0f0f0f0 ;
V_224 . V_222 [ 0 ] = V_223 [ 0 ] . V_222 [ 1 ] | ( V_223 [ 0 ] . V_222 [ 0 ] >> 4 ) ;
V_224 . V_222 [ 1 ] = V_223 [ 0 ] . V_222 [ 3 ] | ( V_223 [ 0 ] . V_222 [ 2 ] >> 4 ) ;
V_224 . V_222 [ 2 ] = V_223 [ 0 ] . V_222 [ 1 ] | ( V_223 [ 1 ] . V_222 [ 0 ] >> 4 ) ;
V_224 . V_222 [ 3 ] = V_223 [ 0 ] . V_222 [ 3 ] | ( V_223 [ 1 ] . V_222 [ 2 ] >> 4 ) ;
F_100 ( V_224 . V_221 , V_231 ) ;
V_227 += V_224 . V_221 ;
V_231 += 4 ;
V_230 += 8 ;
}
for ( V_15 = 0 ; V_15 < V_233 ; V_15 ++ ) {
V_223 [ 0 ] . V_221 = * ( ( T_2 * ) V_230 ) & 0xf0f0f0f0 ;
V_226 . V_222 [ 0 ] = V_223 [ 0 ] . V_222 [ 1 ] | ( V_223 [ 0 ] . V_222 [ 0 ] >> 4 ) ;
V_226 . V_222 [ 1 ] = V_223 [ 0 ] . V_222 [ 3 ] | ( V_223 [ 0 ] . V_222 [ 2 ] >> 4 ) ;
F_101 ( V_226 . V_225 , V_231 ) ;
V_227 += ( T_2 ) V_226 . V_225 ;
V_231 += 2 ;
V_230 += 4 ;
}
V_231 += V_229 ;
}
return V_227 ;
}
static int F_102 ( struct V_10 * V_11 ,
struct V_237 * V_238 ,
T_5 V_239 ,
T_5 V_219 ,
T_5 V_220 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_14 * V_14 = F_5 ( V_11 ) ;
struct V_129 * V_130 ;
struct V_133 * V_134 ;
T_6 V_136 ;
T_2 V_227 ;
int V_135 ;
struct V_240 V_241 ;
T_1 * V_217 , * V_218 ;
bool V_242 , V_243 ;
if ( ! V_239 ) {
F_98 ( V_11 ) ;
return 0 ;
}
if ( V_219 > V_235 || V_220 > V_236 )
return - V_143 ;
V_130 = F_103 ( V_11 -> V_12 , V_238 , V_239 ) ;
if ( ! V_130 ) {
F_29 ( L_7 , V_239 ) ;
return - V_244 ;
}
V_134 = F_23 ( V_130 ) ;
V_135 = F_24 ( V_134 , false ) ;
if ( V_135 )
goto V_192;
V_135 = F_28 ( & V_134 -> V_134 , 0 , V_134 -> V_134 . V_140 , & V_241 ) ;
V_217 = F_104 ( & V_241 , & V_242 ) ;
V_218 = F_104 ( & V_2 -> V_193 , & V_243 ) ;
if ( V_242 == true )
F_29 ( L_8 ) ;
if ( V_243 == false )
F_29 ( L_9 ) ;
V_218 += ( V_189 + V_190 ) * V_2 -> V_245 ;
V_227 = F_99 ( V_217 , V_218 , V_219 , V_220 ) ;
F_86 ( & V_241 ) ;
F_26 ( V_134 ) ;
{
T_1 * V_218 = ( T_1 * ) V_2 -> V_193 . V_246 + ( V_189 + V_190 ) * V_2 -> V_245 + V_189 ;
F_100 ( V_227 , V_218 ) ;
F_100 ( V_219 , V_218 + V_247 ) ;
F_100 ( V_220 , V_218 + V_248 ) ;
F_100 ( 0 , V_218 + V_249 ) ;
F_100 ( 0 , V_218 + V_250 ) ;
V_136 = V_2 -> V_195 ;
V_136 += ( V_189 + V_190 ) * V_2 -> V_245 ;
V_136 >>= 3 ;
F_8 ( V_2 , V_77 , 0xc8 , V_136 & 0xff ) ;
F_8 ( V_2 , V_77 , 0xc9 , ( V_136 >> 8 ) & 0xff ) ;
F_8 ( V_2 , V_77 , 0xca , ( V_136 >> 16 ) & 0xff ) ;
}
V_14 -> V_251 = V_219 ;
V_14 -> V_252 = V_220 ;
V_14 -> V_253 = V_235 - V_219 ;
V_14 -> V_254 = V_235 - V_220 ;
V_2 -> V_245 = ( V_2 -> V_245 + 1 ) % V_191 ;
F_97 ( V_11 ) ;
F_87 ( V_130 ) ;
return 0 ;
V_192:
F_87 ( V_130 ) ;
return V_135 ;
}
static int F_105 ( struct V_10 * V_11 ,
int V_126 , int V_127 )
{
struct V_14 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
int V_255 , V_256 ;
T_1 * V_257 ;
V_257 = ( T_1 * ) V_2 -> V_193 . V_246 + ( V_189 + V_190 ) * V_2 -> V_245 + V_189 ;
F_100 ( V_126 , V_257 + V_258 ) ;
F_100 ( V_127 , V_257 + V_259 ) ;
V_255 = V_14 -> V_253 ;
V_256 = V_14 -> V_254 ;
if ( V_126 < 0 ) {
V_255 = ( - V_126 ) + V_14 -> V_253 ;
V_126 = 0 ;
}
if ( V_127 < 0 ) {
V_256 = ( - V_127 ) + V_14 -> V_254 ;
V_127 = 0 ;
}
F_8 ( V_2 , V_77 , 0xc2 , V_255 ) ;
F_8 ( V_2 , V_77 , 0xc3 , V_256 ) ;
F_8 ( V_2 , V_77 , 0xc4 , ( V_126 & 0xff ) ) ;
F_8 ( V_2 , V_77 , 0xc5 , ( ( V_126 >> 8 ) & 0x0f ) ) ;
F_8 ( V_2 , V_77 , 0xc6 , ( V_127 & 0xff ) ) ;
F_8 ( V_2 , V_77 , 0xc7 , ( ( V_127 >> 8 ) & 0x07 ) ) ;
F_10 ( V_2 , V_77 , 0xCB , 0xFF , 0x00 ) ;
return 0 ;
}
