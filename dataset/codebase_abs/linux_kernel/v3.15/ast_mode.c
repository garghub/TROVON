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
case 1440 :
V_24 -> V_40 = & V_47 [ V_25 ] ;
break;
case 1600 :
V_24 -> V_40 = & V_48 [ V_25 ] ;
break;
case 1680 :
V_24 -> V_40 = & V_49 [ V_25 ] ;
break;
case 1920 :
if ( V_11 -> V_21 . V_44 == 1080 )
V_24 -> V_40 = & V_50 [ V_25 ] ;
else
V_24 -> V_40 = & V_51 [ V_25 ] ;
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
V_29 = ( V_24 -> V_40 -> V_52 & V_53 ) ? 8 : 0 ;
V_30 = ( V_24 -> V_40 -> V_52 & V_54 ) ? 8 : 0 ;
V_22 -> V_55 = V_24 -> V_40 -> V_56 ;
V_22 -> V_57 = V_24 -> V_40 -> V_58 + V_29 ;
V_22 -> V_59 = V_24 -> V_40 -> V_56 - V_29 ;
V_22 -> V_60 = V_24 -> V_40 -> V_58 + V_29 +
V_24 -> V_40 -> V_61 ;
V_22 -> V_62 = ( V_24 -> V_40 -> V_58 + V_29 +
V_24 -> V_40 -> V_61 +
V_24 -> V_40 -> V_63 ) ;
V_22 -> V_64 = V_24 -> V_40 -> V_65 ;
V_22 -> V_66 = V_24 -> V_40 -> V_67 + V_30 ;
V_22 -> V_68 = V_24 -> V_40 -> V_65 - V_30 ;
V_22 -> V_69 = V_24 -> V_40 -> V_67 + V_30 +
V_24 -> V_40 -> V_70 ;
V_22 -> V_71 = ( V_24 -> V_40 -> V_67 + V_30 +
V_24 -> V_40 -> V_70 +
V_24 -> V_40 -> V_72 ) ;
V_25 = V_24 -> V_40 -> V_25 ;
V_26 = V_24 -> V_40 -> V_26 ;
if ( V_2 -> V_73 == V_74 ) {
} else {
F_8 ( V_2 , V_75 , 0x8c , ( T_1 ) ( ( V_27 & 0xf ) << 4 ) ) ;
F_8 ( V_2 , V_75 , 0x8d , V_25 & 0xff ) ;
F_8 ( V_2 , V_75 , 0x8e , V_26 & 0xff ) ;
F_8 ( V_2 , V_75 , 0x91 , 0xa8 ) ;
F_8 ( V_2 , V_75 , 0x92 , V_11 -> V_31 -> V_32 -> V_33 ) ;
F_8 ( V_2 , V_75 , 0x93 , V_22 -> clock / 1000 ) ;
F_8 ( V_2 , V_75 , 0x94 , V_22 -> V_39 ) ;
F_8 ( V_2 , V_75 , 0x95 , V_22 -> V_39 >> 8 ) ;
F_8 ( V_2 , V_75 , 0x96 , V_22 -> V_44 ) ;
F_8 ( V_2 , V_75 , 0x97 , V_22 -> V_44 >> 8 ) ;
}
return true ;
}
static void F_9 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_76 * V_77 ;
T_2 V_15 ;
T_1 V_78 ;
V_77 = V_24 -> V_34 ;
V_78 = V_77 -> V_79 ;
F_2 ( V_2 , V_80 , V_78 ) ;
F_8 ( V_2 , V_8 , 0x00 , 0x03 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_78 = V_77 -> V_81 [ V_15 ] ;
if ( ! V_15 )
V_78 |= 0x20 ;
F_8 ( V_2 , V_8 , ( V_15 + 1 ) , V_78 ) ;
}
F_10 ( V_2 , V_75 , 0x11 , 0x7f , 0x00 ) ;
for ( V_15 = 0 ; V_15 < 25 ; V_15 ++ )
F_8 ( V_2 , V_75 , V_15 , V_77 -> V_11 [ V_15 ] ) ;
V_78 = F_3 ( V_2 , V_82 ) ;
for ( V_15 = 0 ; V_15 < 20 ; V_15 ++ ) {
V_78 = V_77 -> V_83 [ V_15 ] ;
F_2 ( V_2 , V_84 , ( T_1 ) V_15 ) ;
F_2 ( V_2 , V_84 , V_78 ) ;
}
F_2 ( V_2 , V_84 , 0x14 ) ;
F_2 ( V_2 , V_84 , 0x00 ) ;
V_78 = F_3 ( V_2 , V_82 ) ;
F_2 ( V_2 , V_84 , 0x20 ) ;
for ( V_15 = 0 ; V_15 < 9 ; V_15 ++ )
F_8 ( V_2 , V_85 , V_15 , V_77 -> V_86 [ V_15 ] ) ;
}
static void F_11 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_87 = 0 , V_88 = 0 , V_89 = 0 , V_90 = 0 , V_91 = 0 , V_92 = 0 ;
T_3 V_93 ;
F_10 ( V_2 , V_75 , 0x11 , 0x7f , 0x00 ) ;
V_93 = ( V_21 -> V_55 >> 3 ) - 5 ;
if ( V_93 & 0x100 )
V_90 |= 0x01 ;
F_10 ( V_2 , V_75 , 0x00 , 0x00 , V_93 ) ;
V_93 = ( V_21 -> V_39 >> 3 ) - 1 ;
if ( V_93 & 0x100 )
V_90 |= 0x04 ;
F_10 ( V_2 , V_75 , 0x01 , 0x00 , V_93 ) ;
V_93 = ( V_21 -> V_57 >> 3 ) - 1 ;
if ( V_93 & 0x100 )
V_90 |= 0x10 ;
F_10 ( V_2 , V_75 , 0x02 , 0x00 , V_93 ) ;
V_93 = ( ( V_21 -> V_59 >> 3 ) - 1 ) & 0x7f ;
if ( V_93 & 0x20 )
V_87 |= 0x80 ;
if ( V_93 & 0x40 )
V_91 |= 0x01 ;
F_10 ( V_2 , V_75 , 0x03 , 0xE0 , ( V_93 & 0x1f ) ) ;
V_93 = ( V_21 -> V_60 >> 3 ) - 1 ;
if ( V_93 & 0x100 )
V_90 |= 0x40 ;
F_10 ( V_2 , V_75 , 0x04 , 0x00 , V_93 ) ;
V_93 = ( ( V_21 -> V_62 >> 3 ) - 1 ) & 0x3f ;
if ( V_93 & 0x20 )
V_91 |= 0x04 ;
F_10 ( V_2 , V_75 , 0x05 , 0x60 , ( T_1 ) ( ( V_93 & 0x1f ) | V_87 ) ) ;
F_10 ( V_2 , V_75 , 0xAC , 0x00 , V_90 ) ;
F_10 ( V_2 , V_75 , 0xAD , 0x00 , V_91 ) ;
V_93 = ( V_21 -> V_64 ) - 2 ;
if ( V_93 & 0x100 )
V_88 |= 0x01 ;
if ( V_93 & 0x200 )
V_88 |= 0x20 ;
if ( V_93 & 0x400 )
V_92 |= 0x01 ;
F_10 ( V_2 , V_75 , 0x06 , 0x00 , V_93 ) ;
V_93 = ( V_21 -> V_69 ) - 1 ;
if ( V_93 & 0x100 )
V_88 |= 0x04 ;
if ( V_93 & 0x200 )
V_88 |= 0x80 ;
if ( V_93 & 0x400 )
V_92 |= 0x08 ;
F_10 ( V_2 , V_75 , 0x10 , 0x00 , V_93 ) ;
V_93 = ( V_21 -> V_71 - 1 ) & 0x3f ;
if ( V_93 & 0x10 )
V_92 |= 0x20 ;
if ( V_93 & 0x20 )
V_92 |= 0x40 ;
F_10 ( V_2 , V_75 , 0x11 , 0x70 , V_93 & 0xf ) ;
V_93 = V_21 -> V_44 - 1 ;
if ( V_93 & 0x100 )
V_88 |= 0x02 ;
if ( V_93 & 0x200 )
V_88 |= 0x40 ;
if ( V_93 & 0x400 )
V_92 |= 0x02 ;
F_10 ( V_2 , V_75 , 0x12 , 0x00 , V_93 ) ;
V_93 = V_21 -> V_66 - 1 ;
if ( V_93 & 0x100 )
V_88 |= 0x08 ;
if ( V_93 & 0x200 )
V_89 |= 0x20 ;
if ( V_93 & 0x400 )
V_92 |= 0x04 ;
F_10 ( V_2 , V_75 , 0x15 , 0x00 , V_93 ) ;
V_93 = V_21 -> V_68 - 1 ;
if ( V_93 & 0x100 )
V_92 |= 0x10 ;
F_10 ( V_2 , V_75 , 0x16 , 0x00 , V_93 ) ;
F_10 ( V_2 , V_75 , 0x07 , 0x00 , V_88 ) ;
F_10 ( V_2 , V_75 , 0x09 , 0xdf , V_89 ) ;
F_10 ( V_2 , V_75 , 0xAE , 0x00 , ( V_92 | 0x80 ) ) ;
F_10 ( V_2 , V_75 , 0x11 , 0x7f , 0x80 ) ;
}
static void F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_3 V_94 ;
V_94 = V_11 -> V_31 -> V_32 -> V_95 [ 0 ] >> 3 ;
F_8 ( V_2 , V_75 , 0x13 , ( V_94 & 0xff ) ) ;
F_8 ( V_2 , V_75 , 0xb0 , ( V_94 >> 8 ) & 0x3f ) ;
}
static void F_13 ( struct V_96 * V_12 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_97 * V_98 ;
V_98 = & V_99 [ V_24 -> V_40 -> V_100 ] ;
F_10 ( V_2 , V_75 , 0xc0 , 0x00 , V_98 -> V_101 ) ;
F_10 ( V_2 , V_75 , 0xc1 , 0x00 , V_98 -> V_102 ) ;
F_10 ( V_2 , V_75 , 0xbb , 0x0f ,
( V_98 -> V_103 & 0x80 ) | ( ( V_98 -> V_103 & 0x3 ) << 4 ) ) ;
}
static void F_14 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_104 = 0 , V_105 = 0 , V_106 = 0 ;
switch ( V_11 -> V_31 -> V_32 -> V_33 ) {
case 8 :
V_104 = 0x70 ;
V_105 = 0x01 ;
V_106 = 0x00 ;
break;
case 15 :
case 16 :
V_104 = 0x70 ;
V_105 = 0x04 ;
V_106 = 0x02 ;
break;
case 32 :
V_104 = 0x70 ;
V_105 = 0x08 ;
V_106 = 0x02 ;
break;
}
F_10 ( V_2 , V_75 , 0xa0 , 0x8f , V_104 ) ;
F_10 ( V_2 , V_75 , 0xa3 , 0xf0 , V_105 ) ;
F_10 ( V_2 , V_75 , 0xa8 , 0xfd , V_106 ) ;
if ( V_2 -> V_73 == V_107 ) {
F_8 ( V_2 , V_75 , 0xa7 , 0x78 ) ;
F_8 ( V_2 , V_75 , 0xa6 , 0x60 ) ;
} else if ( V_2 -> V_73 == V_108 ||
V_2 -> V_73 == V_109 ||
V_2 -> V_73 == V_110 ||
V_2 -> V_73 == V_111 ) {
F_8 ( V_2 , V_75 , 0xa7 , 0x3f ) ;
F_8 ( V_2 , V_75 , 0xa6 , 0x2f ) ;
} else {
F_8 ( V_2 , V_75 , 0xa7 , 0x2f ) ;
F_8 ( V_2 , V_75 , 0xa6 , 0x1f ) ;
}
}
static void F_15 ( struct V_96 * V_12 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
T_1 V_78 ;
V_78 = F_3 ( V_2 , V_112 ) ;
V_78 |= ( V_24 -> V_40 -> V_52 & V_113 ) ;
F_2 ( V_2 , V_80 , V_78 ) ;
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
static void F_17 ( struct V_10 * V_11 , unsigned V_94 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_2 V_114 ;
V_114 = V_94 >> 2 ;
F_8 ( V_2 , V_75 , 0x0d , ( T_1 ) ( V_114 & 0xff ) ) ;
F_8 ( V_2 , V_75 , 0x0c , ( T_1 ) ( ( V_114 >> 8 ) & 0xff ) ) ;
F_8 ( V_2 , V_75 , 0xaf , ( T_1 ) ( ( V_114 >> 16 ) & 0xff ) ) ;
}
static void F_18 ( struct V_10 * V_11 , int V_21 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
if ( V_2 -> V_73 == V_74 )
return;
switch ( V_21 ) {
case V_115 :
case V_116 :
case V_117 :
F_10 ( V_2 , V_8 , 0x1 , 0xdf , 0 ) ;
F_4 ( V_11 ) ;
break;
case V_118 :
F_10 ( V_2 , V_8 , 0x1 , 0xdf , 0x20 ) ;
break;
}
}
static bool F_19 ( struct V_10 * V_11 ,
const struct V_20 * V_21 ,
struct V_20 * V_22 )
{
return true ;
}
static int F_20 ( struct V_10 * V_11 ,
struct V_119 * V_32 ,
int V_120 , int V_121 , int V_122 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
int V_129 ;
T_4 V_130 ;
if ( ! V_122 && V_32 ) {
V_126 = F_21 ( V_32 ) ;
V_124 = V_126 -> V_124 ;
V_128 = F_22 ( V_124 ) ;
V_129 = F_23 ( V_128 , false ) ;
if ( V_129 )
return V_129 ;
F_24 ( V_128 ) ;
F_25 ( V_128 ) ;
}
V_126 = F_21 ( V_11 -> V_31 -> V_32 ) ;
V_124 = V_126 -> V_124 ;
V_128 = F_22 ( V_124 ) ;
V_129 = F_23 ( V_128 , false ) ;
if ( V_129 )
return V_129 ;
V_129 = F_26 ( V_128 , V_131 , & V_130 ) ;
if ( V_129 ) {
F_25 ( V_128 ) ;
return V_129 ;
}
if ( & V_2 -> V_132 -> V_133 == V_126 ) {
V_129 = F_27 ( & V_128 -> V_128 , 0 , V_128 -> V_128 . V_134 , & V_128 -> V_135 ) ;
if ( V_129 )
F_28 ( L_1 ) ;
}
F_25 ( V_128 ) ;
F_17 ( V_11 , ( T_2 ) V_130 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 , int V_120 , int V_121 ,
struct V_119 * V_136 )
{
return F_20 ( V_11 , V_136 , V_120 , V_121 , 0 ) ;
}
static int F_30 ( struct V_10 * V_11 ,
struct V_20 * V_21 ,
struct V_20 * V_22 ,
int V_120 , int V_121 ,
struct V_119 * V_136 )
{
struct V_96 * V_12 = V_11 -> V_12 ;
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_23 V_24 ;
bool V_129 ;
if ( V_2 -> V_73 == V_74 ) {
F_28 ( L_2 ) ;
return - V_137 ;
}
V_129 = F_6 ( V_11 , V_21 , V_22 , & V_24 ) ;
if ( V_129 == false )
return - V_137 ;
F_31 ( V_2 ) ;
F_10 ( V_2 , V_75 , 0xa1 , 0xff , 0x04 ) ;
F_9 ( V_11 , V_22 , & V_24 ) ;
F_11 ( V_11 , V_22 , & V_24 ) ;
F_12 ( V_11 ) ;
F_13 ( V_12 , V_22 , & V_24 ) ;
F_14 ( V_11 , V_22 , & V_24 ) ;
F_15 ( V_12 , V_22 , & V_24 ) ;
F_16 ( V_11 , V_22 , & V_24 ) ;
F_29 ( V_11 , V_120 , V_121 , V_136 ) ;
return 0 ;
}
static void F_32 ( struct V_10 * V_11 )
{
}
static void F_33 ( struct V_10 * V_11 )
{
}
static void F_34 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
F_10 ( V_2 , V_8 , 0x1 , 0xdf , 0 ) ;
}
static void F_35 ( struct V_10 * V_11 )
{
}
static void F_36 ( struct V_10 * V_11 , T_3 * V_4 , T_3 * V_5 ,
T_3 * V_6 , T_5 V_138 , T_5 V_139 )
{
struct V_14 * V_14 = F_5 ( V_11 ) ;
int V_140 = ( V_138 + V_139 > 256 ) ? 256 : V_138 + V_139 , V_15 ;
for ( V_15 = V_138 ; V_15 < V_140 ; V_15 ++ ) {
V_14 -> V_17 [ V_15 ] = V_4 [ V_15 ] >> 8 ;
V_14 -> V_18 [ V_15 ] = V_5 [ V_15 ] >> 8 ;
V_14 -> V_19 [ V_15 ] = V_6 [ V_15 ] >> 8 ;
}
F_4 ( V_11 ) ;
}
static void F_37 ( struct V_10 * V_11 )
{
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
}
static int F_40 ( struct V_96 * V_12 )
{
struct V_14 * V_11 ;
int V_15 ;
V_11 = F_41 ( sizeof( struct V_14 ) , V_141 ) ;
if ( ! V_11 )
return - V_142 ;
F_42 ( V_12 , & V_11 -> V_143 , & V_144 ) ;
F_43 ( & V_11 -> V_143 , 256 ) ;
F_44 ( & V_11 -> V_143 , & V_145 ) ;
for ( V_15 = 0 ; V_15 < 256 ; V_15 ++ ) {
V_11 -> V_17 [ V_15 ] = V_15 ;
V_11 -> V_18 [ V_15 ] = V_15 ;
V_11 -> V_19 [ V_15 ] = V_15 ;
}
return 0 ;
}
static void F_45 ( struct V_146 * V_147 )
{
F_46 ( V_147 ) ;
F_39 ( V_147 ) ;
}
static struct V_146 * F_47 ( struct V_148 * V_149 )
{
int V_150 = V_149 -> V_151 [ 0 ] ;
struct V_152 * V_124 ;
struct V_146 * V_147 ;
if ( V_150 ) {
V_124 = F_48 ( V_149 -> V_12 , V_150 , V_153 ) ;
if ( ! V_124 )
return NULL ;
V_147 = F_49 ( V_124 ) ;
return V_147 ;
}
return NULL ;
}
static void F_50 ( struct V_146 * V_147 , int V_21 )
{
}
static bool F_51 ( struct V_146 * V_147 ,
const struct V_20 * V_21 ,
struct V_20 * V_22 )
{
return true ;
}
static void F_52 ( struct V_146 * V_147 ,
struct V_20 * V_21 ,
struct V_20 * V_22 )
{
}
static void F_53 ( struct V_146 * V_147 )
{
}
static void F_54 ( struct V_146 * V_147 )
{
}
static int F_55 ( struct V_96 * V_12 )
{
struct V_154 * V_154 ;
V_154 = F_41 ( sizeof( struct V_154 ) , V_141 ) ;
if ( ! V_154 )
return - V_142 ;
F_56 ( V_12 , & V_154 -> V_143 , & V_155 ,
V_156 ) ;
F_57 ( & V_154 -> V_143 , & V_157 ) ;
V_154 -> V_143 . V_158 = 1 ;
return 0 ;
}
static int F_58 ( struct V_148 * V_149 )
{
struct V_159 * V_159 = F_59 ( V_149 ) ;
struct V_160 * V_160 ;
int V_129 ;
V_160 = F_60 ( V_149 , & V_159 -> V_161 -> V_162 ) ;
if ( V_160 ) {
F_61 ( & V_159 -> V_143 , V_160 ) ;
V_129 = F_62 ( V_149 , V_160 ) ;
F_39 ( V_160 ) ;
return V_129 ;
} else
F_61 ( & V_159 -> V_143 , NULL ) ;
return 0 ;
}
static int F_63 ( struct V_148 * V_149 ,
struct V_20 * V_21 )
{
return V_163 ;
}
static void F_64 ( struct V_148 * V_149 )
{
struct V_159 * V_159 = F_59 ( V_149 ) ;
F_65 ( V_159 -> V_161 ) ;
F_66 ( V_149 ) ;
F_67 ( V_149 ) ;
F_39 ( V_149 ) ;
}
static enum V_164
F_68 ( struct V_148 * V_149 , bool V_165 )
{
return V_166 ;
}
static int F_69 ( struct V_96 * V_12 )
{
struct V_159 * V_159 ;
struct V_148 * V_149 ;
struct V_146 * V_147 ;
V_159 = F_41 ( sizeof( struct V_159 ) , V_141 ) ;
if ( ! V_159 )
return - V_142 ;
V_149 = & V_159 -> V_143 ;
F_70 ( V_12 , V_149 , & V_167 , V_168 ) ;
F_71 ( V_149 , & V_169 ) ;
V_149 -> V_170 = 0 ;
V_149 -> V_171 = 0 ;
F_72 ( V_149 ) ;
V_149 -> V_172 = V_173 ;
V_147 = F_73 ( & V_12 -> V_174 . V_175 , struct V_146 , V_176 ) ;
F_74 ( V_149 , V_147 ) ;
V_159 -> V_161 = F_75 ( V_12 ) ;
if ( ! V_159 -> V_161 )
F_28 ( L_3 ) ;
return 0 ;
}
static int F_76 ( struct V_96 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
int V_139 ;
int V_129 ;
struct V_123 * V_124 ;
struct V_127 * V_128 ;
T_6 V_130 ;
V_139 = ( V_177 + V_178 ) * V_179 ;
V_129 = F_77 ( V_12 , V_139 , true , & V_124 ) ;
if ( V_129 )
return V_129 ;
V_128 = F_22 ( V_124 ) ;
V_129 = F_23 ( V_128 , false ) ;
if ( F_78 ( V_129 != 0 ) )
goto V_180;
V_129 = F_26 ( V_128 , V_131 , & V_130 ) ;
F_25 ( V_128 ) ;
if ( V_129 )
goto V_180;
V_129 = F_27 ( & V_128 -> V_128 , 0 , V_128 -> V_128 . V_134 , & V_2 -> V_181 ) ;
if ( V_129 )
goto V_180;
V_2 -> V_182 = V_124 ;
V_2 -> V_183 = V_130 ;
F_79 ( L_4 , V_2 -> V_183 ) ;
return 0 ;
V_180:
return V_129 ;
}
static void F_80 ( struct V_96 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
F_81 ( & V_2 -> V_181 ) ;
F_82 ( V_2 -> V_182 ) ;
}
int F_83 ( struct V_96 * V_12 )
{
F_76 ( V_12 ) ;
F_40 ( V_12 ) ;
F_55 ( V_12 ) ;
F_69 ( V_12 ) ;
return 0 ;
}
void F_84 ( struct V_96 * V_12 )
{
F_80 ( V_12 ) ;
}
static int F_85 ( void * V_184 )
{
struct V_185 * V_161 = V_184 ;
struct V_1 * V_2 = V_161 -> V_12 -> V_13 ;
T_5 V_186 ;
V_186 = F_86 ( V_2 , V_75 , 0xb7 , 0x10 ) >> 4 ;
return V_186 & 1 ? 1 : 0 ;
}
static int F_87 ( void * V_184 )
{
struct V_185 * V_161 = V_184 ;
struct V_1 * V_2 = V_161 -> V_12 -> V_13 ;
T_5 V_186 ;
V_186 = F_86 ( V_2 , V_75 , 0xb7 , 0x20 ) >> 5 ;
return V_186 & 1 ? 1 : 0 ;
}
static void F_88 ( void * V_184 , int clock )
{
struct V_185 * V_161 = V_184 ;
struct V_1 * V_2 = V_161 -> V_12 -> V_13 ;
int V_15 ;
T_1 V_187 , V_188 ;
for ( V_15 = 0 ; V_15 < 0x10000 ; V_15 ++ ) {
V_187 = ( ( clock & 0x01 ) ? 0 : 1 ) ;
F_10 ( V_2 , V_75 , 0xb7 , 0xfe , V_187 ) ;
V_188 = F_86 ( V_2 , V_75 , 0xb7 , 0x01 ) ;
if ( V_187 == V_188 )
break;
}
}
static void F_89 ( void * V_184 , int V_189 )
{
struct V_185 * V_161 = V_184 ;
struct V_1 * V_2 = V_161 -> V_12 -> V_13 ;
int V_15 ;
T_1 V_187 , V_188 ;
for ( V_15 = 0 ; V_15 < 0x10000 ; V_15 ++ ) {
V_187 = ( ( V_189 & 0x01 ) ? 0 : 1 ) << 2 ;
F_10 ( V_2 , V_75 , 0xb7 , 0xfb , V_187 ) ;
V_188 = F_86 ( V_2 , V_75 , 0xb7 , 0x04 ) ;
if ( V_187 == V_188 )
break;
}
}
static struct V_185 * F_75 ( struct V_96 * V_12 )
{
struct V_185 * V_161 ;
int V_129 ;
V_161 = F_41 ( sizeof( struct V_185 ) , V_141 ) ;
if ( ! V_161 )
return NULL ;
V_161 -> V_162 . V_190 = V_191 ;
V_161 -> V_162 . V_192 = V_193 ;
V_161 -> V_162 . V_12 . V_194 = & V_12 -> V_195 -> V_12 ;
V_161 -> V_12 = V_12 ;
F_90 ( & V_161 -> V_162 , V_161 ) ;
snprintf ( V_161 -> V_162 . V_196 , sizeof( V_161 -> V_162 . V_196 ) ,
L_5 ) ;
V_161 -> V_162 . V_197 = & V_161 -> V_198 ;
V_161 -> V_198 . V_199 = 20 ;
V_161 -> V_198 . V_200 = 2 ;
V_161 -> V_198 . V_189 = V_161 ;
V_161 -> V_198 . V_201 = F_89 ;
V_161 -> V_198 . V_202 = F_88 ;
V_161 -> V_198 . V_203 = F_87 ;
V_161 -> V_198 . V_204 = F_85 ;
V_129 = F_91 ( & V_161 -> V_162 ) ;
if ( V_129 ) {
F_28 ( L_6 ) ;
goto V_205;
}
return V_161 ;
V_205:
F_39 ( V_161 ) ;
return NULL ;
}
static void F_65 ( struct V_185 * V_161 )
{
if ( ! V_161 )
return;
F_92 ( & V_161 -> V_162 ) ;
F_39 ( V_161 ) ;
}
static void F_93 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_78 ;
V_78 = 0x2 ;
V_78 |= 1 ;
F_10 ( V_2 , V_75 , 0xcb , 0xfc , V_78 ) ;
}
static void F_94 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
F_10 ( V_2 , V_75 , 0xcb , 0xfc , 0x00 ) ;
}
static T_2 F_95 ( T_1 * V_206 , T_1 * V_207 , int V_208 , int V_209 )
{
union {
T_2 V_210 ;
T_1 V_211 [ 4 ] ;
} V_212 [ 2 ] , V_213 ;
union {
T_3 V_214 ;
T_1 V_211 [ 2 ] ;
} V_215 ;
T_2 V_216 = 0 ;
T_7 V_217 , V_218 ;
T_1 * V_219 , * V_220 ;
int V_15 , V_221 ;
T_2 V_222 , V_223 ;
V_217 = V_224 << 1 ;
V_218 = V_217 - ( V_208 << 1 ) ;
V_219 = V_206 ;
V_220 = ( T_1 * ) V_207 + V_218 + ( V_225 - V_209 ) * V_217 ;
V_222 = V_208 & 1 ;
V_223 = V_208 >> 1 ;
for ( V_221 = 0 ; V_221 < V_209 ; V_221 ++ ) {
for ( V_15 = 0 ; V_15 < V_223 ; V_15 ++ ) {
V_212 [ 0 ] . V_210 = * ( ( T_2 * ) V_219 ) & 0xf0f0f0f0 ;
V_212 [ 1 ] . V_210 = * ( ( T_2 * ) ( V_219 + 4 ) ) & 0xf0f0f0f0 ;
V_213 . V_211 [ 0 ] = V_212 [ 0 ] . V_211 [ 1 ] | ( V_212 [ 0 ] . V_211 [ 0 ] >> 4 ) ;
V_213 . V_211 [ 1 ] = V_212 [ 0 ] . V_211 [ 3 ] | ( V_212 [ 0 ] . V_211 [ 2 ] >> 4 ) ;
V_213 . V_211 [ 2 ] = V_212 [ 0 ] . V_211 [ 1 ] | ( V_212 [ 1 ] . V_211 [ 0 ] >> 4 ) ;
V_213 . V_211 [ 3 ] = V_212 [ 0 ] . V_211 [ 3 ] | ( V_212 [ 1 ] . V_211 [ 2 ] >> 4 ) ;
F_96 ( V_213 . V_210 , V_220 ) ;
V_216 += V_213 . V_210 ;
V_220 += 4 ;
V_219 += 8 ;
}
for ( V_15 = 0 ; V_15 < V_222 ; V_15 ++ ) {
V_212 [ 0 ] . V_210 = * ( ( T_2 * ) V_219 ) & 0xf0f0f0f0 ;
V_215 . V_211 [ 0 ] = V_212 [ 0 ] . V_211 [ 1 ] | ( V_212 [ 0 ] . V_211 [ 0 ] >> 4 ) ;
V_215 . V_211 [ 1 ] = V_212 [ 0 ] . V_211 [ 3 ] | ( V_212 [ 0 ] . V_211 [ 2 ] >> 4 ) ;
F_97 ( V_215 . V_214 , V_220 ) ;
V_216 += ( T_2 ) V_215 . V_214 ;
V_220 += 2 ;
V_219 += 4 ;
}
V_220 += V_218 ;
}
return V_216 ;
}
static int F_98 ( struct V_10 * V_11 ,
struct V_226 * V_227 ,
T_5 V_228 ,
T_5 V_208 ,
T_5 V_209 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_14 * V_14 = F_5 ( V_11 ) ;
struct V_123 * V_124 ;
struct V_127 * V_128 ;
T_6 V_130 ;
T_2 V_216 ;
int V_129 ;
struct V_229 V_230 ;
T_1 * V_206 , * V_207 ;
bool V_231 , V_232 ;
if ( ! V_228 ) {
F_94 ( V_11 ) ;
return 0 ;
}
if ( V_208 > V_224 || V_209 > V_225 )
return - V_137 ;
V_124 = F_99 ( V_11 -> V_12 , V_227 , V_228 ) ;
if ( ! V_124 ) {
F_28 ( L_7 , V_228 ) ;
return - V_233 ;
}
V_128 = F_22 ( V_124 ) ;
V_129 = F_23 ( V_128 , false ) ;
if ( V_129 )
goto V_180;
V_129 = F_27 ( & V_128 -> V_128 , 0 , V_128 -> V_128 . V_134 , & V_230 ) ;
V_206 = F_100 ( & V_230 , & V_231 ) ;
V_207 = F_100 ( & V_2 -> V_181 , & V_232 ) ;
if ( V_231 == true )
F_28 ( L_8 ) ;
if ( V_232 == false )
F_28 ( L_9 ) ;
V_207 += ( V_177 + V_178 ) * V_2 -> V_234 ;
V_216 = F_95 ( V_206 , V_207 , V_208 , V_209 ) ;
F_81 ( & V_230 ) ;
F_25 ( V_128 ) ;
{
T_1 * V_207 = ( T_1 * ) V_2 -> V_181 . V_235 + ( V_177 + V_178 ) * V_2 -> V_234 + V_177 ;
F_96 ( V_216 , V_207 ) ;
F_96 ( V_208 , V_207 + V_236 ) ;
F_96 ( V_209 , V_207 + V_237 ) ;
F_96 ( 0 , V_207 + V_238 ) ;
F_96 ( 0 , V_207 + V_239 ) ;
V_130 = V_2 -> V_183 ;
V_130 += ( V_177 + V_178 ) * V_2 -> V_234 ;
V_130 >>= 3 ;
F_8 ( V_2 , V_75 , 0xc8 , V_130 & 0xff ) ;
F_8 ( V_2 , V_75 , 0xc9 , ( V_130 >> 8 ) & 0xff ) ;
F_8 ( V_2 , V_75 , 0xca , ( V_130 >> 16 ) & 0xff ) ;
}
V_14 -> V_240 = V_208 ;
V_14 -> V_241 = V_209 ;
V_14 -> V_242 = V_224 - V_208 ;
V_14 -> V_243 = V_224 - V_209 ;
V_2 -> V_234 = ( V_2 -> V_234 + 1 ) % V_179 ;
F_93 ( V_11 ) ;
F_82 ( V_124 ) ;
return 0 ;
V_180:
F_82 ( V_124 ) ;
return V_129 ;
}
static int F_101 ( struct V_10 * V_11 ,
int V_120 , int V_121 )
{
struct V_14 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
int V_244 , V_245 ;
T_1 * V_246 ;
V_246 = ( T_1 * ) V_2 -> V_181 . V_235 + ( V_177 + V_178 ) * V_2 -> V_234 + V_177 ;
F_96 ( V_120 , V_246 + V_247 ) ;
F_96 ( V_121 , V_246 + V_248 ) ;
V_244 = V_14 -> V_242 ;
V_245 = V_14 -> V_243 ;
if ( V_120 < 0 ) {
V_244 = ( - V_120 ) + V_14 -> V_242 ;
V_120 = 0 ;
}
if ( V_121 < 0 ) {
V_245 = ( - V_121 ) + V_14 -> V_243 ;
V_121 = 0 ;
}
F_8 ( V_2 , V_75 , 0xc2 , V_244 ) ;
F_8 ( V_2 , V_75 , 0xc3 , V_245 ) ;
F_8 ( V_2 , V_75 , 0xc4 , ( V_120 & 0xff ) ) ;
F_8 ( V_2 , V_75 , 0xc5 , ( ( V_120 >> 8 ) & 0x0f ) ) ;
F_8 ( V_2 , V_75 , 0xc6 , ( V_121 & 0xff ) ) ;
F_8 ( V_2 , V_75 , 0xc7 , ( ( V_121 >> 8 ) & 0x07 ) ) ;
F_10 ( V_2 , V_75 , 0xCB , 0xFF , 0x00 ) ;
return 0 ;
}
