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
switch ( V_11 -> V_31 -> V_32 ) {
case 8 :
V_24 -> V_33 = & V_34 [ V_35 ] ;
V_27 = V_35 - 1 ;
break;
case 16 :
V_24 -> V_33 = & V_34 [ V_36 ] ;
V_27 = V_36 ;
break;
case 24 :
case 32 :
V_24 -> V_33 = & V_34 [ V_37 ] ;
V_27 = V_37 ;
break;
default:
return false ;
}
switch ( V_11 -> V_21 . V_38 ) {
case 640 :
V_24 -> V_39 = & V_40 [ V_25 ] ;
break;
case 800 :
V_24 -> V_39 = & V_41 [ V_25 ] ;
break;
case 1024 :
V_24 -> V_39 = & V_42 [ V_25 ] ;
break;
case 1280 :
if ( V_11 -> V_21 . V_43 == 800 )
V_24 -> V_39 = & V_44 [ V_25 ] ;
else
V_24 -> V_39 = & V_45 [ V_25 ] ;
break;
case 1440 :
V_24 -> V_39 = & V_46 [ V_25 ] ;
break;
case 1600 :
V_24 -> V_39 = & V_47 [ V_25 ] ;
break;
case 1680 :
V_24 -> V_39 = & V_48 [ V_25 ] ;
break;
case 1920 :
if ( V_11 -> V_21 . V_43 == 1080 )
V_24 -> V_39 = & V_49 [ V_25 ] ;
else
V_24 -> V_39 = & V_50 [ V_25 ] ;
break;
default:
return false ;
}
V_28 = F_7 ( V_21 ) ;
while ( V_24 -> V_39 -> V_28 < V_28 ) {
V_24 -> V_39 ++ ;
if ( ( V_24 -> V_39 -> V_28 > V_28 ) ||
( V_24 -> V_39 -> V_28 == 0xff ) ) {
V_24 -> V_39 -- ;
break;
}
}
V_29 = ( V_24 -> V_39 -> V_51 & V_52 ) ? 8 : 0 ;
V_30 = ( V_24 -> V_39 -> V_51 & V_53 ) ? 8 : 0 ;
V_22 -> V_54 = V_24 -> V_39 -> V_55 ;
V_22 -> V_56 = V_24 -> V_39 -> V_57 + V_29 ;
V_22 -> V_58 = V_24 -> V_39 -> V_55 - V_29 ;
V_22 -> V_59 = V_24 -> V_39 -> V_57 + V_29 +
V_24 -> V_39 -> V_60 ;
V_22 -> V_61 = ( V_24 -> V_39 -> V_57 + V_29 +
V_24 -> V_39 -> V_60 +
V_24 -> V_39 -> V_62 ) ;
V_22 -> V_63 = V_24 -> V_39 -> V_64 ;
V_22 -> V_65 = V_24 -> V_39 -> V_66 + V_30 ;
V_22 -> V_67 = V_24 -> V_39 -> V_64 - V_30 ;
V_22 -> V_68 = V_24 -> V_39 -> V_66 + V_30 +
V_24 -> V_39 -> V_69 ;
V_22 -> V_70 = ( V_24 -> V_39 -> V_66 + V_30 +
V_24 -> V_39 -> V_69 +
V_24 -> V_39 -> V_71 ) ;
V_25 = V_24 -> V_39 -> V_25 ;
V_26 = V_24 -> V_39 -> V_26 ;
if ( V_2 -> V_72 == V_73 ) {
} else {
F_8 ( V_2 , V_74 , 0x8c , ( T_1 ) ( ( V_27 & 0xf ) << 4 ) ) ;
F_8 ( V_2 , V_74 , 0x8d , V_25 & 0xff ) ;
F_8 ( V_2 , V_74 , 0x8e , V_26 & 0xff ) ;
F_8 ( V_2 , V_74 , 0x91 , 0xa8 ) ;
F_8 ( V_2 , V_74 , 0x92 , V_11 -> V_31 -> V_32 ) ;
F_8 ( V_2 , V_74 , 0x93 , V_22 -> clock / 1000 ) ;
F_8 ( V_2 , V_74 , 0x94 , V_22 -> V_38 ) ;
F_8 ( V_2 , V_74 , 0x95 , V_22 -> V_38 >> 8 ) ;
F_8 ( V_2 , V_74 , 0x96 , V_22 -> V_43 ) ;
F_8 ( V_2 , V_74 , 0x97 , V_22 -> V_43 >> 8 ) ;
}
return true ;
}
static void F_9 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_75 * V_76 ;
T_2 V_15 ;
T_1 V_77 ;
V_76 = V_24 -> V_33 ;
V_77 = V_76 -> V_78 ;
F_2 ( V_2 , V_79 , V_77 ) ;
F_8 ( V_2 , V_8 , 0x00 , 0x03 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
V_77 = V_76 -> V_80 [ V_15 ] ;
if ( ! V_15 )
V_77 |= 0x20 ;
F_8 ( V_2 , V_8 , ( V_15 + 1 ) , V_77 ) ;
}
F_10 ( V_2 , V_74 , 0x11 , 0x7f , 0x00 ) ;
for ( V_15 = 0 ; V_15 < 25 ; V_15 ++ )
F_8 ( V_2 , V_74 , V_15 , V_76 -> V_11 [ V_15 ] ) ;
V_77 = F_3 ( V_2 , V_81 ) ;
for ( V_15 = 0 ; V_15 < 20 ; V_15 ++ ) {
V_77 = V_76 -> V_82 [ V_15 ] ;
F_2 ( V_2 , V_83 , ( T_1 ) V_15 ) ;
F_2 ( V_2 , V_83 , V_77 ) ;
}
F_2 ( V_2 , V_83 , 0x14 ) ;
F_2 ( V_2 , V_83 , 0x00 ) ;
V_77 = F_3 ( V_2 , V_81 ) ;
F_2 ( V_2 , V_83 , 0x20 ) ;
for ( V_15 = 0 ; V_15 < 9 ; V_15 ++ )
F_8 ( V_2 , V_84 , V_15 , V_76 -> V_85 [ V_15 ] ) ;
}
static void F_11 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_86 = 0 , V_87 = 0 , V_88 = 0 , V_89 = 0 , V_90 = 0 , V_91 = 0 ;
T_3 V_92 ;
F_10 ( V_2 , V_74 , 0x11 , 0x7f , 0x00 ) ;
V_92 = ( V_21 -> V_54 >> 3 ) - 5 ;
if ( V_92 & 0x100 )
V_89 |= 0x01 ;
F_10 ( V_2 , V_74 , 0x00 , 0x00 , V_92 ) ;
V_92 = ( V_21 -> V_38 >> 3 ) - 1 ;
if ( V_92 & 0x100 )
V_89 |= 0x04 ;
F_10 ( V_2 , V_74 , 0x01 , 0x00 , V_92 ) ;
V_92 = ( V_21 -> V_56 >> 3 ) - 1 ;
if ( V_92 & 0x100 )
V_89 |= 0x10 ;
F_10 ( V_2 , V_74 , 0x02 , 0x00 , V_92 ) ;
V_92 = ( ( V_21 -> V_58 >> 3 ) - 1 ) & 0x7f ;
if ( V_92 & 0x20 )
V_86 |= 0x80 ;
if ( V_92 & 0x40 )
V_90 |= 0x01 ;
F_10 ( V_2 , V_74 , 0x03 , 0xE0 , ( V_92 & 0x1f ) ) ;
V_92 = ( V_21 -> V_59 >> 3 ) - 1 ;
if ( V_92 & 0x100 )
V_89 |= 0x40 ;
F_10 ( V_2 , V_74 , 0x04 , 0x00 , V_92 ) ;
V_92 = ( ( V_21 -> V_61 >> 3 ) - 1 ) & 0x3f ;
if ( V_92 & 0x20 )
V_90 |= 0x04 ;
F_10 ( V_2 , V_74 , 0x05 , 0x60 , ( T_1 ) ( ( V_92 & 0x1f ) | V_86 ) ) ;
F_10 ( V_2 , V_74 , 0xAC , 0x00 , V_89 ) ;
F_10 ( V_2 , V_74 , 0xAD , 0x00 , V_90 ) ;
V_92 = ( V_21 -> V_63 ) - 2 ;
if ( V_92 & 0x100 )
V_87 |= 0x01 ;
if ( V_92 & 0x200 )
V_87 |= 0x20 ;
if ( V_92 & 0x400 )
V_91 |= 0x01 ;
F_10 ( V_2 , V_74 , 0x06 , 0x00 , V_92 ) ;
V_92 = ( V_21 -> V_68 ) - 1 ;
if ( V_92 & 0x100 )
V_87 |= 0x04 ;
if ( V_92 & 0x200 )
V_87 |= 0x80 ;
if ( V_92 & 0x400 )
V_91 |= 0x08 ;
F_10 ( V_2 , V_74 , 0x10 , 0x00 , V_92 ) ;
V_92 = ( V_21 -> V_70 - 1 ) & 0x3f ;
if ( V_92 & 0x10 )
V_91 |= 0x20 ;
if ( V_92 & 0x20 )
V_91 |= 0x40 ;
F_10 ( V_2 , V_74 , 0x11 , 0x70 , V_92 & 0xf ) ;
V_92 = V_21 -> V_43 - 1 ;
if ( V_92 & 0x100 )
V_87 |= 0x02 ;
if ( V_92 & 0x200 )
V_87 |= 0x40 ;
if ( V_92 & 0x400 )
V_91 |= 0x02 ;
F_10 ( V_2 , V_74 , 0x12 , 0x00 , V_92 ) ;
V_92 = V_21 -> V_65 - 1 ;
if ( V_92 & 0x100 )
V_87 |= 0x08 ;
if ( V_92 & 0x200 )
V_88 |= 0x20 ;
if ( V_92 & 0x400 )
V_91 |= 0x04 ;
F_10 ( V_2 , V_74 , 0x15 , 0x00 , V_92 ) ;
V_92 = V_21 -> V_67 - 1 ;
if ( V_92 & 0x100 )
V_91 |= 0x10 ;
F_10 ( V_2 , V_74 , 0x16 , 0x00 , V_92 ) ;
F_10 ( V_2 , V_74 , 0x07 , 0x00 , V_87 ) ;
F_10 ( V_2 , V_74 , 0x09 , 0xdf , V_88 ) ;
F_10 ( V_2 , V_74 , 0xAE , 0x00 , ( V_91 | 0x80 ) ) ;
F_10 ( V_2 , V_74 , 0x11 , 0x7f , 0x80 ) ;
}
static void F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_3 V_93 ;
V_93 = V_11 -> V_31 -> V_94 [ 0 ] >> 3 ;
F_8 ( V_2 , V_74 , 0x13 , ( V_93 & 0xff ) ) ;
F_8 ( V_2 , V_74 , 0xb0 , ( V_93 >> 8 ) & 0x3f ) ;
}
static void F_13 ( struct V_95 * V_12 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_96 * V_97 ;
V_97 = & V_98 [ V_24 -> V_39 -> V_99 ] ;
F_10 ( V_2 , V_74 , 0xc0 , 0x00 , V_97 -> V_100 ) ;
F_10 ( V_2 , V_74 , 0xc1 , 0x00 , V_97 -> V_101 ) ;
F_10 ( V_2 , V_74 , 0xbb , 0x0f ,
( V_97 -> V_102 & 0x80 ) | ( ( V_97 -> V_102 & 0x3 ) << 4 ) ) ;
}
static void F_14 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_103 = 0 , V_104 = 0 , V_105 = 0 ;
switch ( V_11 -> V_31 -> V_32 ) {
case 8 :
V_103 = 0x70 ;
V_104 = 0x01 ;
V_105 = 0x00 ;
break;
case 15 :
case 16 :
V_103 = 0x70 ;
V_104 = 0x04 ;
V_105 = 0x02 ;
break;
case 32 :
V_103 = 0x70 ;
V_104 = 0x08 ;
V_105 = 0x02 ;
break;
}
F_10 ( V_2 , V_74 , 0xa0 , 0x8f , V_103 ) ;
F_10 ( V_2 , V_74 , 0xa3 , 0xf0 , V_104 ) ;
F_10 ( V_2 , V_74 , 0xa8 , 0xfd , V_105 ) ;
if ( V_2 -> V_72 == V_106 ) {
F_8 ( V_2 , V_74 , 0xa7 , 0x78 ) ;
F_8 ( V_2 , V_74 , 0xa6 , 0x60 ) ;
} else if ( V_2 -> V_72 == V_107 ||
V_2 -> V_72 == V_108 ||
V_2 -> V_72 == V_109 ||
V_2 -> V_72 == V_110 ) {
F_8 ( V_2 , V_74 , 0xa7 , 0x3f ) ;
F_8 ( V_2 , V_74 , 0xa6 , 0x2f ) ;
} else {
F_8 ( V_2 , V_74 , 0xa7 , 0x2f ) ;
F_8 ( V_2 , V_74 , 0xa6 , 0x1f ) ;
}
}
void F_15 ( struct V_95 * V_12 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
T_1 V_77 ;
V_77 = F_3 ( V_2 , V_111 ) ;
V_77 |= ( V_24 -> V_39 -> V_51 & V_112 ) ;
F_2 ( V_2 , V_79 , V_77 ) ;
}
bool F_16 ( struct V_10 * V_11 , struct V_20 * V_21 ,
struct V_23 * V_24 )
{
switch ( V_11 -> V_31 -> V_32 ) {
case 8 :
break;
default:
return false ;
}
return true ;
}
void F_17 ( struct V_10 * V_11 , unsigned V_93 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_2 V_113 ;
V_113 = V_93 >> 2 ;
F_8 ( V_2 , V_74 , 0x0d , ( T_1 ) ( V_113 & 0xff ) ) ;
F_8 ( V_2 , V_74 , 0x0c , ( T_1 ) ( ( V_113 >> 8 ) & 0xff ) ) ;
F_8 ( V_2 , V_74 , 0xaf , ( T_1 ) ( ( V_113 >> 16 ) & 0xff ) ) ;
}
static void F_18 ( struct V_10 * V_11 , int V_21 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
if ( V_2 -> V_72 == V_73 )
return;
switch ( V_21 ) {
case V_114 :
case V_115 :
case V_116 :
F_10 ( V_2 , V_8 , 0x1 , 0xdf , 0 ) ;
F_4 ( V_11 ) ;
break;
case V_117 :
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
struct V_118 * V_31 ,
int V_119 , int V_120 , int V_121 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
int V_128 ;
T_4 V_129 ;
if ( ! V_121 && V_31 ) {
V_125 = F_21 ( V_31 ) ;
V_123 = V_125 -> V_123 ;
V_127 = F_22 ( V_123 ) ;
V_128 = F_23 ( V_127 , false ) ;
if ( V_128 )
return V_128 ;
F_24 ( V_127 ) ;
F_25 ( V_127 ) ;
}
V_125 = F_21 ( V_11 -> V_31 ) ;
V_123 = V_125 -> V_123 ;
V_127 = F_22 ( V_123 ) ;
V_128 = F_23 ( V_127 , false ) ;
if ( V_128 )
return V_128 ;
V_128 = F_26 ( V_127 , V_130 , & V_129 ) ;
if ( V_128 ) {
F_25 ( V_127 ) ;
return V_128 ;
}
if ( & V_2 -> V_131 -> V_132 == V_125 ) {
V_128 = F_27 ( & V_127 -> V_127 , 0 , V_127 -> V_127 . V_133 , & V_127 -> V_134 ) ;
if ( V_128 )
F_28 ( L_1 ) ;
}
F_25 ( V_127 ) ;
F_17 ( V_11 , ( T_2 ) V_129 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 , int V_119 , int V_120 ,
struct V_118 * V_135 )
{
return F_20 ( V_11 , V_135 , V_119 , V_120 , 0 ) ;
}
static int F_30 ( struct V_10 * V_11 ,
struct V_20 * V_21 ,
struct V_20 * V_22 ,
int V_119 , int V_120 ,
struct V_118 * V_135 )
{
struct V_95 * V_12 = V_11 -> V_12 ;
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_23 V_24 ;
bool V_128 ;
if ( V_2 -> V_72 == V_73 ) {
F_28 ( L_2 ) ;
return - V_136 ;
}
V_128 = F_6 ( V_11 , V_21 , V_22 , & V_24 ) ;
if ( V_128 == false )
return - V_136 ;
F_31 ( V_2 ) ;
F_10 ( V_2 , V_74 , 0xa1 , 0xff , 0x04 ) ;
F_9 ( V_11 , V_22 , & V_24 ) ;
F_11 ( V_11 , V_22 , & V_24 ) ;
F_12 ( V_11 ) ;
F_13 ( V_12 , V_22 , & V_24 ) ;
F_14 ( V_11 , V_22 , & V_24 ) ;
F_15 ( V_12 , V_22 , & V_24 ) ;
F_16 ( V_11 , V_22 , & V_24 ) ;
F_29 ( V_11 , V_119 , V_120 , V_135 ) ;
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
T_3 * V_6 , T_5 V_137 , T_5 V_138 )
{
struct V_14 * V_14 = F_5 ( V_11 ) ;
int V_139 = ( V_137 + V_138 > 256 ) ? 256 : V_137 + V_138 , V_15 ;
for ( V_15 = V_137 ; V_15 < V_139 ; V_15 ++ ) {
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
int F_40 ( struct V_95 * V_12 )
{
struct V_14 * V_11 ;
int V_15 ;
V_11 = F_41 ( sizeof( struct V_14 ) , V_140 ) ;
if ( ! V_11 )
return - V_141 ;
F_42 ( V_12 , & V_11 -> V_142 , & V_143 ) ;
F_43 ( & V_11 -> V_142 , 256 ) ;
F_44 ( & V_11 -> V_142 , & V_144 ) ;
for ( V_15 = 0 ; V_15 < 256 ; V_15 ++ ) {
V_11 -> V_17 [ V_15 ] = V_15 ;
V_11 -> V_18 [ V_15 ] = V_15 ;
V_11 -> V_19 [ V_15 ] = V_15 ;
}
return 0 ;
}
static void F_45 ( struct V_145 * V_146 )
{
F_46 ( V_146 ) ;
F_39 ( V_146 ) ;
}
static struct V_145 * F_47 ( struct V_147 * V_148 )
{
int V_149 = V_148 -> V_150 [ 0 ] ;
struct V_151 * V_123 ;
struct V_145 * V_146 ;
if ( V_149 ) {
V_123 = F_48 ( V_148 -> V_12 , V_149 , V_152 ) ;
if ( ! V_123 )
return NULL ;
V_146 = F_49 ( V_123 ) ;
return V_146 ;
}
return NULL ;
}
static void F_50 ( struct V_145 * V_146 , int V_21 )
{
}
static bool F_51 ( struct V_145 * V_146 ,
const struct V_20 * V_21 ,
struct V_20 * V_22 )
{
return true ;
}
static void F_52 ( struct V_145 * V_146 ,
struct V_20 * V_21 ,
struct V_20 * V_22 )
{
}
static void F_53 ( struct V_145 * V_146 )
{
}
static void F_54 ( struct V_145 * V_146 )
{
}
int F_55 ( struct V_95 * V_12 )
{
struct V_153 * V_153 ;
V_153 = F_41 ( sizeof( struct V_153 ) , V_140 ) ;
if ( ! V_153 )
return - V_141 ;
F_56 ( V_12 , & V_153 -> V_142 , & V_154 ,
V_155 ) ;
F_57 ( & V_153 -> V_142 , & V_156 ) ;
V_153 -> V_142 . V_157 = 1 ;
return 0 ;
}
static int F_58 ( struct V_147 * V_148 )
{
struct V_158 * V_158 = F_59 ( V_148 ) ;
struct V_159 * V_159 ;
int V_128 ;
V_159 = F_60 ( V_148 , & V_158 -> V_160 -> V_161 ) ;
if ( V_159 ) {
F_61 ( & V_158 -> V_142 , V_159 ) ;
V_128 = F_62 ( V_148 , V_159 ) ;
return V_128 ;
} else
F_61 ( & V_158 -> V_142 , NULL ) ;
return 0 ;
}
static int F_63 ( struct V_147 * V_148 ,
struct V_20 * V_21 )
{
return V_162 ;
}
static void F_64 ( struct V_147 * V_148 )
{
struct V_158 * V_158 = F_59 ( V_148 ) ;
F_65 ( V_158 -> V_160 ) ;
F_66 ( V_148 ) ;
F_67 ( V_148 ) ;
F_39 ( V_148 ) ;
}
static enum V_163
F_68 ( struct V_147 * V_148 , bool V_164 )
{
return V_165 ;
}
int F_69 ( struct V_95 * V_12 )
{
struct V_158 * V_158 ;
struct V_147 * V_148 ;
struct V_145 * V_146 ;
V_158 = F_41 ( sizeof( struct V_158 ) , V_140 ) ;
if ( ! V_158 )
return - V_141 ;
V_148 = & V_158 -> V_142 ;
F_70 ( V_12 , V_148 , & V_166 , V_167 ) ;
F_71 ( V_148 , & V_168 ) ;
V_148 -> V_169 = 0 ;
V_148 -> V_170 = 0 ;
F_72 ( V_148 ) ;
V_148 -> V_171 = V_172 ;
V_146 = F_73 ( & V_12 -> V_173 . V_174 , struct V_145 , V_175 ) ;
F_74 ( V_148 , V_146 ) ;
V_158 -> V_160 = F_75 ( V_12 ) ;
if ( ! V_158 -> V_160 )
F_28 ( L_3 ) ;
return 0 ;
}
int F_76 ( struct V_95 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
int V_138 ;
int V_128 ;
struct V_122 * V_123 ;
struct V_126 * V_127 ;
T_6 V_129 ;
V_138 = ( V_176 + V_177 ) * V_178 ;
V_128 = F_77 ( V_12 , V_138 , true , & V_123 ) ;
if ( V_128 )
return V_128 ;
V_127 = F_22 ( V_123 ) ;
V_128 = F_23 ( V_127 , false ) ;
if ( F_78 ( V_128 != 0 ) )
goto V_179;
V_128 = F_26 ( V_127 , V_130 , & V_129 ) ;
F_25 ( V_127 ) ;
if ( V_128 )
goto V_179;
V_128 = F_27 ( & V_127 -> V_127 , 0 , V_127 -> V_127 . V_133 , & V_2 -> V_180 ) ;
if ( V_128 )
goto V_179;
V_2 -> V_181 = V_123 ;
V_2 -> V_182 = V_129 ;
F_79 ( L_4 , V_2 -> V_182 ) ;
return 0 ;
V_179:
return V_128 ;
}
void F_80 ( struct V_95 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
F_81 ( & V_2 -> V_180 ) ;
F_82 ( V_2 -> V_181 ) ;
}
int F_83 ( struct V_95 * V_12 )
{
F_76 ( V_12 ) ;
F_40 ( V_12 ) ;
F_55 ( V_12 ) ;
F_69 ( V_12 ) ;
return 0 ;
}
void F_84 ( struct V_95 * V_12 )
{
F_80 ( V_12 ) ;
}
static int F_85 ( void * V_183 )
{
struct V_184 * V_160 = V_183 ;
struct V_1 * V_2 = V_160 -> V_12 -> V_13 ;
T_5 V_185 ;
V_185 = F_86 ( V_2 , V_74 , 0xb7 , 0x10 ) >> 4 ;
return V_185 & 1 ? 1 : 0 ;
}
static int F_87 ( void * V_183 )
{
struct V_184 * V_160 = V_183 ;
struct V_1 * V_2 = V_160 -> V_12 -> V_13 ;
T_5 V_185 ;
V_185 = F_86 ( V_2 , V_74 , 0xb7 , 0x20 ) >> 5 ;
return V_185 & 1 ? 1 : 0 ;
}
static void F_88 ( void * V_183 , int clock )
{
struct V_184 * V_160 = V_183 ;
struct V_1 * V_2 = V_160 -> V_12 -> V_13 ;
int V_15 ;
T_1 V_186 , V_187 ;
for ( V_15 = 0 ; V_15 < 0x10000 ; V_15 ++ ) {
V_186 = ( ( clock & 0x01 ) ? 0 : 1 ) ;
F_10 ( V_2 , V_74 , 0xb7 , 0xfe , V_186 ) ;
V_187 = F_86 ( V_2 , V_74 , 0xb7 , 0x01 ) ;
if ( V_186 == V_187 )
break;
}
}
static void F_89 ( void * V_183 , int V_188 )
{
struct V_184 * V_160 = V_183 ;
struct V_1 * V_2 = V_160 -> V_12 -> V_13 ;
int V_15 ;
T_1 V_186 , V_187 ;
for ( V_15 = 0 ; V_15 < 0x10000 ; V_15 ++ ) {
V_186 = ( ( V_188 & 0x01 ) ? 0 : 1 ) << 2 ;
F_10 ( V_2 , V_74 , 0xb7 , 0xfb , V_186 ) ;
V_187 = F_86 ( V_2 , V_74 , 0xb7 , 0x04 ) ;
if ( V_186 == V_187 )
break;
}
}
static struct V_184 * F_75 ( struct V_95 * V_12 )
{
struct V_184 * V_160 ;
int V_128 ;
V_160 = F_41 ( sizeof( struct V_184 ) , V_140 ) ;
if ( ! V_160 )
return NULL ;
V_160 -> V_161 . V_189 = V_190 ;
V_160 -> V_161 . V_191 = V_192 ;
V_160 -> V_161 . V_12 . V_193 = & V_12 -> V_194 -> V_12 ;
V_160 -> V_12 = V_12 ;
F_90 ( & V_160 -> V_161 , V_160 ) ;
snprintf ( V_160 -> V_161 . V_195 , sizeof( V_160 -> V_161 . V_195 ) ,
L_5 ) ;
V_160 -> V_161 . V_196 = & V_160 -> V_197 ;
V_160 -> V_197 . V_198 = 20 ;
V_160 -> V_197 . V_199 = 2 ;
V_160 -> V_197 . V_188 = V_160 ;
V_160 -> V_197 . V_200 = F_89 ;
V_160 -> V_197 . V_201 = F_88 ;
V_160 -> V_197 . V_202 = F_87 ;
V_160 -> V_197 . V_203 = F_85 ;
V_128 = F_91 ( & V_160 -> V_161 ) ;
if ( V_128 ) {
F_28 ( L_6 ) ;
goto V_204;
}
return V_160 ;
V_204:
F_39 ( V_160 ) ;
return NULL ;
}
static void F_65 ( struct V_184 * V_160 )
{
if ( ! V_160 )
return;
F_92 ( & V_160 -> V_161 ) ;
F_39 ( V_160 ) ;
}
void F_93 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
T_1 V_77 ;
V_77 = 0x2 ;
V_77 |= 1 ;
F_10 ( V_2 , V_74 , 0xcb , 0xfc , V_77 ) ;
}
void F_94 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
F_10 ( V_2 , V_74 , 0xcb , 0xfc , 0x00 ) ;
}
static T_2 F_95 ( T_1 * V_205 , T_1 * V_206 , int V_207 , int V_208 )
{
union {
T_2 V_209 ;
T_1 V_210 [ 4 ] ;
} V_211 [ 2 ] , V_212 ;
union {
T_3 V_213 ;
T_1 V_210 [ 2 ] ;
} V_214 ;
T_2 V_215 = 0 ;
T_7 V_216 , V_217 ;
T_1 * V_218 , * V_219 ;
int V_15 , V_220 ;
T_2 V_221 , V_222 ;
V_216 = V_223 << 1 ;
V_217 = V_216 - ( V_207 << 1 ) ;
V_218 = V_205 ;
V_219 = ( T_1 * ) V_206 + V_217 + ( V_224 - V_208 ) * V_216 ;
V_221 = V_207 & 1 ;
V_222 = V_207 >> 1 ;
for ( V_220 = 0 ; V_220 < V_208 ; V_220 ++ ) {
for ( V_15 = 0 ; V_15 < V_222 ; V_15 ++ ) {
V_211 [ 0 ] . V_209 = * ( ( T_2 * ) V_218 ) & 0xf0f0f0f0 ;
V_211 [ 1 ] . V_209 = * ( ( T_2 * ) ( V_218 + 4 ) ) & 0xf0f0f0f0 ;
V_212 . V_210 [ 0 ] = V_211 [ 0 ] . V_210 [ 1 ] | ( V_211 [ 0 ] . V_210 [ 0 ] >> 4 ) ;
V_212 . V_210 [ 1 ] = V_211 [ 0 ] . V_210 [ 3 ] | ( V_211 [ 0 ] . V_210 [ 2 ] >> 4 ) ;
V_212 . V_210 [ 2 ] = V_211 [ 0 ] . V_210 [ 1 ] | ( V_211 [ 1 ] . V_210 [ 0 ] >> 4 ) ;
V_212 . V_210 [ 3 ] = V_211 [ 0 ] . V_210 [ 3 ] | ( V_211 [ 1 ] . V_210 [ 2 ] >> 4 ) ;
F_96 ( V_212 . V_209 , V_219 ) ;
V_215 += V_212 . V_209 ;
V_219 += 4 ;
V_218 += 8 ;
}
for ( V_15 = 0 ; V_15 < V_221 ; V_15 ++ ) {
V_211 [ 0 ] . V_209 = * ( ( T_2 * ) V_218 ) & 0xf0f0f0f0 ;
V_214 . V_210 [ 0 ] = V_211 [ 0 ] . V_210 [ 1 ] | ( V_211 [ 0 ] . V_210 [ 0 ] >> 4 ) ;
V_214 . V_210 [ 1 ] = V_211 [ 0 ] . V_210 [ 3 ] | ( V_211 [ 0 ] . V_210 [ 2 ] >> 4 ) ;
F_97 ( V_214 . V_213 , V_219 ) ;
V_215 += ( T_2 ) V_214 . V_213 ;
V_219 += 2 ;
V_218 += 4 ;
}
V_219 += V_217 ;
}
return V_215 ;
}
static int F_98 ( struct V_10 * V_11 ,
struct V_225 * V_226 ,
T_5 V_227 ,
T_5 V_207 ,
T_5 V_208 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
struct V_14 * V_14 = F_5 ( V_11 ) ;
struct V_122 * V_123 ;
struct V_126 * V_127 ;
T_6 V_129 ;
T_2 V_215 ;
int V_128 ;
struct V_228 V_229 ;
T_1 * V_205 , * V_206 ;
bool V_230 , V_231 ;
if ( ! V_227 ) {
F_94 ( V_11 ) ;
return 0 ;
}
if ( V_207 > V_223 || V_208 > V_224 )
return - V_136 ;
V_123 = F_99 ( V_11 -> V_12 , V_226 , V_227 ) ;
if ( ! V_123 ) {
F_28 ( L_7 , V_227 ) ;
return - V_232 ;
}
V_127 = F_22 ( V_123 ) ;
V_128 = F_23 ( V_127 , false ) ;
if ( V_128 )
goto V_179;
V_128 = F_27 ( & V_127 -> V_127 , 0 , V_127 -> V_127 . V_133 , & V_229 ) ;
V_205 = F_100 ( & V_229 , & V_230 ) ;
V_206 = F_100 ( & V_2 -> V_180 , & V_231 ) ;
if ( V_230 == true )
F_28 ( L_8 ) ;
if ( V_231 == false )
F_28 ( L_9 ) ;
V_206 += ( V_176 + V_177 ) * V_2 -> V_233 ;
V_215 = F_95 ( V_205 , V_206 , V_207 , V_208 ) ;
F_81 ( & V_229 ) ;
F_25 ( V_127 ) ;
{
T_1 * V_206 = ( T_1 * ) V_2 -> V_180 . V_234 + ( V_176 + V_177 ) * V_2 -> V_233 + V_176 ;
F_96 ( V_215 , V_206 ) ;
F_96 ( V_207 , V_206 + V_235 ) ;
F_96 ( V_208 , V_206 + V_236 ) ;
F_96 ( 0 , V_206 + V_237 ) ;
F_96 ( 0 , V_206 + V_238 ) ;
V_129 = V_2 -> V_182 ;
V_129 += ( V_176 + V_177 ) * V_2 -> V_233 ;
V_129 >>= 3 ;
F_8 ( V_2 , V_74 , 0xc8 , V_129 & 0xff ) ;
F_8 ( V_2 , V_74 , 0xc9 , ( V_129 >> 8 ) & 0xff ) ;
F_8 ( V_2 , V_74 , 0xca , ( V_129 >> 16 ) & 0xff ) ;
}
V_14 -> V_239 = V_207 ;
V_14 -> V_240 = V_208 ;
V_14 -> V_241 = V_223 - V_207 ;
V_14 -> V_242 = V_223 - V_208 ;
V_2 -> V_233 = ( V_2 -> V_233 + 1 ) % V_178 ;
F_93 ( V_11 ) ;
F_82 ( V_123 ) ;
return 0 ;
V_179:
F_82 ( V_123 ) ;
return V_128 ;
}
static int F_101 ( struct V_10 * V_11 ,
int V_119 , int V_120 )
{
struct V_14 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_12 -> V_13 ;
int V_243 , V_244 ;
T_1 * V_245 ;
V_245 = ( T_1 * ) V_2 -> V_180 . V_234 + ( V_176 + V_177 ) * V_2 -> V_233 + V_176 ;
F_96 ( V_119 , V_245 + V_246 ) ;
F_96 ( V_120 , V_245 + V_247 ) ;
V_243 = V_14 -> V_241 ;
V_244 = V_14 -> V_242 ;
if ( V_119 < 0 ) {
V_243 = ( - V_119 ) + V_14 -> V_241 ;
V_119 = 0 ;
}
if ( V_120 < 0 ) {
V_244 = ( - V_120 ) + V_14 -> V_242 ;
V_120 = 0 ;
}
F_8 ( V_2 , V_74 , 0xc2 , V_243 ) ;
F_8 ( V_2 , V_74 , 0xc3 , V_244 ) ;
F_8 ( V_2 , V_74 , 0xc4 , ( V_119 & 0xff ) ) ;
F_8 ( V_2 , V_74 , 0xc5 , ( ( V_119 >> 8 ) & 0x0f ) ) ;
F_8 ( V_2 , V_74 , 0xc6 , ( V_120 & 0xff ) ) ;
F_8 ( V_2 , V_74 , 0xc7 , ( ( V_120 >> 8 ) & 0x07 ) ) ;
F_10 ( V_2 , V_74 , 0xCB , 0xFF , 0x00 ) ;
return 0 ;
}
