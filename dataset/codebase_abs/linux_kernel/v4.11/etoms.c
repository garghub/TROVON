static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
if ( V_3 > V_6 ) {
F_2 ( L_1 ) ;
return;
}
F_3 ( V_5 ,
F_4 ( V_5 , 0 ) ,
0 ,
V_7 | V_8 | V_9 ,
0 ,
V_2 , V_1 -> V_10 , V_3 , 500 ) ;
F_5 ( V_11 , L_2 ,
V_2 , V_1 -> V_10 [ 0 ] ) ;
}
static void F_6 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_12 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
V_1 -> V_10 [ 0 ] = V_12 ;
F_3 ( V_5 ,
F_7 ( V_5 , 0 ) ,
0 ,
V_13 | V_8 | V_9 ,
0 ,
V_2 , V_1 -> V_10 , 1 , 500 ) ;
}
static void F_8 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_14 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
if ( V_3 > V_6 ) {
F_9 ( L_3 ) ;
return;
}
F_5 ( V_15 , L_4 , V_2 , * V_14 ) ;
memcpy ( V_1 -> V_10 , V_14 , V_3 ) ;
F_3 ( V_5 ,
F_7 ( V_5 , 0 ) ,
0 ,
V_13 | V_8 | V_9 ,
0 , V_2 , V_1 -> V_10 , V_3 , 500 ) ;
}
static int F_10 ( struct V_1 * V_1 ,
T_2 V_16 ,
const T_2 * V_14 ,
int V_3 , T_2 V_17 )
{
T_2 V_18 ;
F_6 ( V_1 , V_19 , 0x40 ) ;
V_18 = ( ( V_3 & 0x07 ) << 4 ) | ( V_17 & 0x03 ) ;
F_6 ( V_1 , V_20 , V_18 ) ;
F_6 ( V_1 , V_21 , V_16 ) ;
while ( -- V_3 >= 0 )
F_6 ( V_1 , V_22 + V_3 , V_14 [ V_3 ] ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 ,
T_2 V_16 )
{
F_6 ( V_1 , V_19 , 0x40 ) ;
F_6 ( V_1 , V_20 , 0x11 ) ;
F_6 ( V_1 , V_21 , V_16 ) ;
F_6 ( V_1 , V_23 , 0x02 ) ;
F_6 ( V_1 , V_23 , 0x00 ) ;
F_1 ( V_1 , V_22 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
int V_24 = 10 ;
while ( V_24 -- ) {
F_1 ( V_1 , V_25 , 1 ) ;
if ( V_1 -> V_10 [ 0 ] != 0 )
return 1 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_1 ,
int V_26 )
{
int V_27 ;
F_6 ( V_1 , V_28 ,
V_26 ? 0x10
: 0 ) ;
V_27 = F_12 ( V_1 ) ;
if ( V_27 != 0 )
F_2 ( L_5 ) ;
return V_27 ;
}
static void F_14 ( struct V_1 * V_1 )
{
T_2 V_29 ;
static const T_2 V_30 [] = { 0x84 , 0x03 , 0x14 , 0xf4 , 0x01 , 0x05 } ;
F_5 ( V_31 , L_6 ) ;
F_6 ( V_1 , V_32 , 0x2f ) ;
F_6 ( V_1 , V_28 , 0x10 ) ;
F_1 ( V_1 , V_33 , 1 ) ;
F_6 ( V_1 , V_25 , 0x14 ) ;
F_6 ( V_1 , V_34 , 0x1b ) ;
if ( V_1 -> V_35 . V_36 [ ( int ) V_1 -> V_37 ] . V_38 )
V_29 = V_39 ;
else
V_29 = V_40 ;
F_6 ( V_1 , V_41 , V_29 ) ;
F_6 ( V_1 , V_42 , 0x1f ) ;
F_6 ( V_1 , V_43 , 0x04 ) ;
F_6 ( V_1 , V_44 , 0xff ) ;
F_6 ( V_1 , V_45 , 0xff ) ;
F_6 ( V_1 , V_46 , 0xff ) ;
F_6 ( V_1 , V_47 , 0x35 ) ;
F_6 ( V_1 , V_48 , 0x01 ) ;
F_6 ( V_1 , V_49 , 0x00 ) ;
F_6 ( V_1 , V_50 , 0xff ) ;
F_6 ( V_1 , V_51 , 0xff ) ;
F_6 ( V_1 , V_52 , 0x0f ) ;
F_6 ( V_1 , 0x30 , 0x11 ) ;
F_6 ( V_1 , 0x31 , 0x40 ) ;
F_6 ( V_1 , 0x32 , 0x00 ) ;
F_6 ( V_1 , V_53 , 0x00 ) ;
F_6 ( V_1 , V_54 , 0x00 ) ;
F_6 ( V_1 , V_55 , 0x00 ) ;
F_6 ( V_1 , V_56 , 0x00 ) ;
F_6 ( V_1 , V_57 , 0x80 ) ;
F_6 ( V_1 , V_58 , 0x80 ) ;
F_6 ( V_1 , V_59 , 0x80 ) ;
F_6 ( V_1 , V_60 , 0x80 ) ;
F_6 ( V_1 , V_61 , 0x00 ) ;
F_6 ( V_1 , V_62 , 0x00 ) ;
F_6 ( V_1 , 0x61 , 0x80 ) ;
F_6 ( V_1 , 0x62 , 0x02 ) ;
F_6 ( V_1 , 0x63 , 0x03 ) ;
F_6 ( V_1 , 0x64 , 0x14 ) ;
F_6 ( V_1 , 0x65 , 0x0e ) ;
F_6 ( V_1 , 0x66 , 0x02 ) ;
F_6 ( V_1 , 0x67 , 0x02 ) ;
F_6 ( V_1 , V_63 , 0x8f ) ;
F_6 ( V_1 , V_64 , 0x69 ) ;
F_6 ( V_1 , V_65 , 0x0d ) ;
F_6 ( V_1 , V_66 , 0x80 ) ;
F_6 ( V_1 , V_67 , 0xe0 ) ;
F_6 ( V_1 , V_68 , 0x60 ) ;
F_6 ( V_1 , V_69 , 0x86 ) ;
F_6 ( V_1 , V_70 , 0x01 ) ;
F_6 ( V_1 , V_71 , 0x26 ) ;
F_6 ( V_1 , V_72 , 0x7a ) ;
F_6 ( V_1 , V_73 , 0x01 ) ;
F_6 ( V_1 , V_74 , 0x00 ) ;
F_6 ( V_1 , V_75 , 0x18 ) ;
F_6 ( V_1 , V_76 , 0x0f ) ;
F_6 ( V_1 , 0x8a , 0x20 ) ;
F_6 ( V_1 , 0x8d , 0x0f ) ;
F_6 ( V_1 , 0x8e , 0x08 ) ;
F_6 ( V_1 , 0x03 , 0x08 ) ;
F_6 ( V_1 , V_77 , 0x03 ) ;
F_6 ( V_1 , 0x81 , 0xff ) ;
F_6 ( V_1 , 0x80 , 0x00 ) ;
F_6 ( V_1 , 0x81 , 0xff ) ;
F_6 ( V_1 , 0x80 , 0x20 ) ;
F_6 ( V_1 , 0x03 , 0x01 ) ;
F_6 ( V_1 , 0x03 , 0x00 ) ;
F_6 ( V_1 , 0x03 , 0x08 ) ;
if ( V_1 -> V_35 . V_36 [ ( int ) V_1 -> V_37 ] . V_38 )
V_29 = 0x04 ;
else
V_29 = 0x1e ;
F_6 ( V_1 , V_77 , V_29 ) ;
F_8 ( V_1 , 0x62 , V_30 , 6 ) ;
F_6 ( V_1 , 0x81 , 0x47 ) ;
F_6 ( V_1 , 0x80 , 0x40 ) ;
F_6 ( V_1 , 0x81 , 0x30 ) ;
F_6 ( V_1 , 0x80 , 0x20 ) ;
}
static void F_15 ( struct V_1 * V_1 , T_3 V_12 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ )
F_6 ( V_1 , V_53 + V_78 , V_12 ) ;
}
static void F_16 ( struct V_1 * V_1 , T_3 V_12 )
{
T_2 V_79 [] = { 0x80 , 0x80 , 0x80 , 0x80 , 0x00 , 0x00 } ;
memset ( V_79 , V_12 , sizeof( V_79 ) - 2 ) ;
F_8 ( V_1 , V_57 , V_79 , 6 ) ;
}
static void F_17 ( struct V_1 * V_1 , T_3 V_12 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
T_2 V_81 [] = { 0x05 , 0x02 , 0x02 , 0x05 , 0x0d } ;
T_2 V_82 = 0x01 ;
V_81 [ 3 ] = V_12 ;
V_81 [ 0 ] = 15 - V_12 ;
if ( V_80 -> V_83 == V_84 ) {
F_10 ( V_1 , V_85 , & V_82 , 1 , 3 ) ;
F_10 ( V_1 , V_86 , V_81 , sizeof V_81 , 1 ) ;
}
}
static T_3 F_18 ( struct V_1 * V_1 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
if ( V_80 -> V_83 == V_84 ) {
F_11 ( V_1 , V_86 + 3 ) ;
return V_1 -> V_10 [ 0 ] & 0x0f ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
if ( V_80 -> V_87 )
V_80 -> V_88 = V_89 ;
else
V_80 -> V_88 = - 1 ;
}
static void F_20 ( struct V_1 * V_1 )
{
T_2 V_29 ;
T_2 V_90 [] = { 0x0a , 0x12 , 0x05 , 0x6d , 0xcd , 0x00 , 0x01 , 0x00 } ;
F_5 ( V_31 , L_7 ) ;
F_6 ( V_1 , V_32 , 7 ) ;
F_1 ( V_1 , V_33 , 1 ) ;
F_6 ( V_1 , V_91 , 1 ) ;
F_6 ( V_1 , V_91 , 0 ) ;
F_6 ( V_1 , V_25 , 0x10 ) ;
F_6 ( V_1 , V_34 , 0x19 ) ;
if ( V_1 -> V_35 . V_36 [ ( int ) V_1 -> V_37 ] . V_38 )
V_29 = V_39 ;
else
V_29 = V_40 ;
F_5 ( V_31 , L_8 ,
V_1 -> V_35 . V_36 [ ( int ) V_1 -> V_37 ] . V_38 ,
V_29 ) ;
F_6 ( V_1 , V_41 , V_29 ) ;
F_6 ( V_1 , V_42 , 0x1d ) ;
F_6 ( V_1 , V_43 , 0x02 ) ;
F_6 ( V_1 , V_44 , 0xff ) ;
F_6 ( V_1 , V_45 , 0xff ) ;
F_6 ( V_1 , V_46 , 0xff ) ;
F_6 ( V_1 , V_47 , 0x35 ) ;
F_6 ( V_1 , V_48 , 0x01 ) ;
F_6 ( V_1 , V_49 , 0x00 ) ;
F_6 ( V_1 , V_50 , 0xf7 ) ;
F_6 ( V_1 , V_51 , 0xff ) ;
F_6 ( V_1 , V_52 , 0x07 ) ;
F_6 ( V_1 , V_57 , 0x80 ) ;
F_6 ( V_1 , V_58 , 0x80 ) ;
F_6 ( V_1 , V_59 , 0x80 ) ;
F_6 ( V_1 , V_60 , 0x80 ) ;
F_6 ( V_1 , V_61 , 0x00 ) ;
F_6 ( V_1 , V_62 , 0x00 ) ;
F_6 ( V_1 , V_63 , 0xf0 ) ;
F_6 ( V_1 , V_64 , 0x56 ) ;
F_6 ( V_1 , V_65 , 0x05 ) ;
F_6 ( V_1 , V_66 , 0x60 ) ;
F_6 ( V_1 , V_67 , 0x20 ) ;
F_6 ( V_1 , V_68 , 0x50 ) ;
F_6 ( V_1 , V_69 , 0x86 ) ;
F_6 ( V_1 , V_70 , 0x01 ) ;
F_6 ( V_1 , V_71 , 0x86 ) ;
F_6 ( V_1 , V_72 , 0x14 ) ;
F_6 ( V_1 , V_73 , 0x00 ) ;
F_6 ( V_1 , V_74 , 0x00 ) ;
F_6 ( V_1 , V_75 , 0x00 ) ;
F_6 ( V_1 , V_76 , 0x0a ) ;
F_6 ( V_1 , V_92 , 0x04 ) ;
F_6 ( V_1 , V_77 , 0x01 ) ;
if ( V_1 -> V_35 . V_36 [ ( int ) V_1 -> V_37 ] . V_38 ) {
V_90 [ 0 ] = 0x06 ;
F_10 ( V_1 , V_93 , V_90 , sizeof V_90 , 1 ) ;
F_10 ( V_1 , V_86 , V_94 , sizeof V_94 , 1 ) ;
V_29 = 0x06 ;
F_10 ( V_1 , V_93 , & V_29 , 1 , 1 ) ;
F_10 ( V_1 , V_95 , V_96 , sizeof V_96 , 1 ) ;
V_29 = 0x04 ;
F_10 ( V_1 , V_97 , & V_29 , 1 , 1 ) ;
} else {
V_90 [ 0 ] = 0x0a ;
F_10 ( V_1 , V_93 , V_90 , sizeof V_90 , 1 ) ;
F_10 ( V_1 , V_86 , V_94 , sizeof V_94 , 1 ) ;
V_29 = 0x0a ;
F_10 ( V_1 , V_93 , & V_29 , 1 , 1 ) ;
F_10 ( V_1 , V_95 , V_96 , sizeof V_96 , 1 ) ;
V_29 = 0x04 ;
F_10 ( V_1 , V_97 , & V_29 , 1 , 1 ) ;
}
F_10 ( V_1 , V_98 , V_99 , sizeof V_99 , 1 ) ;
F_8 ( V_1 , V_57 , V_100 , 6 ) ;
F_17 ( V_1 , F_18 ( V_1 ) ) ;
}
static int F_21 ( struct V_1 * V_1 ,
const struct V_101 * V_102 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
struct V_35 * V_35 ;
V_35 = & V_1 -> V_35 ;
V_80 -> V_83 = V_102 -> V_103 ;
if ( V_80 -> V_83 == V_84 ) {
V_35 -> V_36 = V_104 ;
V_35 -> V_105 = F_22 ( V_104 ) ;
} else {
V_35 -> V_36 = V_106 ;
V_35 -> V_105 = F_22 ( V_106 ) ;
}
V_80 -> V_88 = - 1 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
if ( V_80 -> V_83 == V_84 )
F_20 ( V_1 ) ;
else
F_14 ( V_1 ) ;
F_6 ( V_1 , V_91 , 0x08 ) ;
F_13 ( V_1 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
if ( V_80 -> V_83 == V_84 )
F_20 ( V_1 ) ;
else
F_14 ( V_1 ) ;
F_19 ( V_1 ) ;
F_6 ( V_1 , V_91 , 0x08 ) ;
F_13 ( V_1 , 1 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_13 ( V_1 , 0 ) ;
}
static T_2 F_26 ( struct V_1 * V_1 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
if ( V_80 -> V_83 == V_84 ) {
F_11 ( V_1 , V_97 ) ;
F_5 ( V_107 , L_9 , V_1 -> V_10 [ 0 ] ) ;
return V_1 -> V_10 [ 0 ] ;
}
return 0x1f ;
}
static void F_27 ( struct V_1 * V_1 , T_2 V_108 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
if ( V_80 -> V_83 == V_84 ) {
T_2 V_82 = 0x01 ;
F_10 ( V_1 , V_85 , & V_82 , 1 , 3 ) ;
F_10 ( V_1 , V_97 , & V_108 , 1 , 1 ) ;
}
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
T_2 V_109 ;
T_2 V_110 = 128 ;
T_2 V_111 = 20 ;
T_2 V_112 = 4 ;
int V_113 ;
T_2 V_114 , V_115 , V_116 ;
if ( V_80 -> V_88 < 0 )
return;
if ( -- V_80 -> V_88 >= 0 )
return;
V_80 -> V_88 = V_89 ;
V_113 = F_26 ( V_1 ) ;
F_1 ( V_1 , V_117 , 4 ) ;
V_115 = ( V_1 -> V_10 [ 0 ] + V_1 -> V_10 [ 3 ] ) >> 1 ;
V_114 = V_1 -> V_10 [ 1 ] ;
V_116 = V_1 -> V_10 [ 2 ] ;
V_114 = ( ( V_114 << 8 ) - ( V_114 << 4 ) - ( V_114 << 3 ) ) >> 10 ;
V_116 = ( ( V_116 << 7 ) >> 10 ) ;
V_115 = ( ( V_115 << 9 ) + ( V_115 << 7 ) + ( V_115 << 5 ) ) >> 10 ;
V_109 = F_29 ( V_114 + V_115 + V_116 ) ;
F_5 ( V_118 , L_10 , V_109 ) ;
if ( V_109 < V_110 - V_111 || V_109 > V_110 + V_111 ) {
V_113 += ( V_110 - V_109 ) >> V_112 ;
V_113 = F_30 ( V_113 ) ;
F_5 ( V_118 , L_11 , V_113 ) ;
F_27 ( V_1 , ( T_2 ) V_113 ) ;
}
}
static void F_31 ( struct V_1 * V_1 ,
T_4 * V_119 ,
int V_3 )
{
int V_120 ;
V_120 = V_119 [ 0 ] & 0x3f ;
V_3 = ( int ) ( ( ( V_119 [ 0 ] & 0xc0 ) << 2 ) | V_119 [ 1 ] ) ;
if ( V_120 == 0x3f ) {
F_5 ( V_118 ,
L_12 , V_3 ) ;
F_5 ( V_118 , L_13 ,
V_119 [ 2 ] , V_119 [ 3 ] , V_119 [ 4 ] , V_119 [ 5 ] ) ;
V_119 += 30 ;
F_32 ( V_1 , V_121 , NULL , 0 ) ;
F_32 ( V_1 , V_122 , V_119 , V_3 ) ;
return;
}
if ( V_3 ) {
V_119 += 8 ;
F_32 ( V_1 , V_123 , V_119 , V_3 ) ;
} else {
V_1 -> V_124 = V_125 ;
}
}
static int F_33 ( struct V_126 * V_127 )
{
struct V_1 * V_1 =
F_34 ( V_127 -> V_128 , struct V_1 , V_129 ) ;
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
V_1 -> V_130 = 0 ;
if ( ! V_1 -> V_131 )
return 0 ;
switch ( V_127 -> V_102 ) {
case V_132 :
F_15 ( V_1 , V_127 -> V_12 ) ;
break;
case V_133 :
F_16 ( V_1 , V_127 -> V_12 ) ;
break;
case V_134 :
F_17 ( V_1 , V_127 -> V_12 ) ;
break;
case V_135 :
V_80 -> V_87 = V_127 -> V_12 ;
F_19 ( V_1 ) ;
break;
}
return V_1 -> V_130 ;
}
static int F_35 ( struct V_1 * V_1 )
{
struct V_80 * V_80 = (struct V_80 * ) V_1 ;
struct V_136 * V_137 = & V_1 -> V_129 ;
V_1 -> V_138 . V_129 = V_137 ;
F_36 ( V_137 , 4 ) ;
F_37 ( V_137 , & V_139 ,
V_132 , 1 , 127 , 1 , 63 ) ;
F_37 ( V_137 , & V_139 ,
V_133 , 0 , 255 , 1 , 127 ) ;
if ( V_80 -> V_83 == V_84 )
F_37 ( V_137 , & V_139 ,
V_134 , 0 , 15 , 1 , 7 ) ;
F_37 ( V_137 , & V_139 ,
V_135 , 0 , 1 , 1 , 1 ) ;
if ( V_137 -> error ) {
F_9 ( L_14 ) ;
return V_137 -> error ;
}
return 0 ;
}
static int F_38 ( struct V_140 * V_141 ,
const struct V_101 * V_102 )
{
return F_39 ( V_141 , V_102 , & V_142 , sizeof( struct V_80 ) ,
V_143 ) ;
}
