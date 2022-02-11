static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
#ifdef F_2
if ( V_3 > V_6 ) {
F_3 ( L_1 ) ;
return;
}
#endif
F_4 ( V_5 ,
F_5 ( V_5 , 0 ) ,
0 ,
V_7 | V_8 | V_9 ,
0 ,
V_2 , V_1 -> V_10 , V_3 , 500 ) ;
F_6 ( V_11 , L_2 ,
V_2 , V_1 -> V_10 [ 0 ] ) ;
}
static void F_7 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_12 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
V_1 -> V_10 [ 0 ] = V_12 ;
F_4 ( V_5 ,
F_8 ( V_5 , 0 ) ,
0 ,
V_13 | V_8 | V_9 ,
0 ,
V_2 , V_1 -> V_10 , 1 , 500 ) ;
}
static void F_9 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_14 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
#ifdef F_2
if ( V_3 > V_6 ) {
F_3 ( L_3 ) ;
return;
}
F_6 ( V_15 , L_4 , V_2 , * V_14 ) ;
#endif
memcpy ( V_1 -> V_10 , V_14 , V_3 ) ;
F_4 ( V_5 ,
F_8 ( V_5 , 0 ) ,
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
F_7 ( V_1 , V_19 , 0x40 ) ;
V_18 = ( ( V_3 & 0x07 ) << 4 ) | ( V_17 & 0x03 ) ;
F_7 ( V_1 , V_20 , V_18 ) ;
F_7 ( V_1 , V_21 , V_16 ) ;
while ( -- V_3 >= 0 )
F_7 ( V_1 , V_22 + V_3 , V_14 [ V_3 ] ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 ,
T_2 V_16 )
{
F_7 ( V_1 , V_19 , 0x40 ) ;
F_7 ( V_1 , V_20 , 0x11 ) ;
F_7 ( V_1 , V_21 , V_16 ) ;
F_7 ( V_1 , V_23 , 0x02 ) ;
F_7 ( V_1 , V_23 , 0x00 ) ;
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
F_7 ( V_1 , V_28 ,
V_26 ? 0x10
: 0 ) ;
V_27 = F_12 ( V_1 ) ;
if ( V_27 != 0 )
F_6 ( V_29 , L_5 ) ;
return V_27 ;
}
static void F_14 ( struct V_1 * V_1 )
{
T_2 V_30 ;
static const T_2 V_31 [] = { 0x84 , 0x03 , 0x14 , 0xf4 , 0x01 , 0x05 } ;
F_6 ( V_32 , L_6 ) ;
F_7 ( V_1 , V_33 , 0x2f ) ;
F_7 ( V_1 , V_28 , 0x10 ) ;
F_1 ( V_1 , V_34 , 1 ) ;
F_7 ( V_1 , V_25 , 0x14 ) ;
F_7 ( V_1 , V_35 , 0x1b ) ;
if ( V_1 -> V_36 . V_37 [ ( int ) V_1 -> V_38 ] . V_39 )
V_30 = V_40 ;
else
V_30 = V_41 ;
F_7 ( V_1 , V_42 , V_30 ) ;
F_7 ( V_1 , V_43 , 0x1f ) ;
F_7 ( V_1 , V_44 , 0x04 ) ;
F_7 ( V_1 , V_45 , 0xff ) ;
F_7 ( V_1 , V_46 , 0xff ) ;
F_7 ( V_1 , V_47 , 0xff ) ;
F_7 ( V_1 , V_48 , 0x35 ) ;
F_7 ( V_1 , V_49 , 0x01 ) ;
F_7 ( V_1 , V_50 , 0x00 ) ;
F_7 ( V_1 , V_51 , 0xff ) ;
F_7 ( V_1 , V_52 , 0xff ) ;
F_7 ( V_1 , V_53 , 0x0f ) ;
F_7 ( V_1 , 0x30 , 0x11 ) ;
F_7 ( V_1 , 0x31 , 0x40 ) ;
F_7 ( V_1 , 0x32 , 0x00 ) ;
F_7 ( V_1 , V_54 , 0x00 ) ;
F_7 ( V_1 , V_55 , 0x00 ) ;
F_7 ( V_1 , V_56 , 0x00 ) ;
F_7 ( V_1 , V_57 , 0x00 ) ;
F_7 ( V_1 , V_58 , 0x80 ) ;
F_7 ( V_1 , V_59 , 0x80 ) ;
F_7 ( V_1 , V_60 , 0x80 ) ;
F_7 ( V_1 , V_61 , 0x80 ) ;
F_7 ( V_1 , V_62 , 0x00 ) ;
F_7 ( V_1 , V_63 , 0x00 ) ;
F_7 ( V_1 , 0x61 , 0x80 ) ;
F_7 ( V_1 , 0x62 , 0x02 ) ;
F_7 ( V_1 , 0x63 , 0x03 ) ;
F_7 ( V_1 , 0x64 , 0x14 ) ;
F_7 ( V_1 , 0x65 , 0x0e ) ;
F_7 ( V_1 , 0x66 , 0x02 ) ;
F_7 ( V_1 , 0x67 , 0x02 ) ;
F_7 ( V_1 , V_64 , 0x8f ) ;
F_7 ( V_1 , V_65 , 0x69 ) ;
F_7 ( V_1 , V_66 , 0x0d ) ;
F_7 ( V_1 , V_67 , 0x80 ) ;
F_7 ( V_1 , V_68 , 0xe0 ) ;
F_7 ( V_1 , V_69 , 0x60 ) ;
F_7 ( V_1 , V_70 , 0x86 ) ;
F_7 ( V_1 , V_71 , 0x01 ) ;
F_7 ( V_1 , V_72 , 0x26 ) ;
F_7 ( V_1 , V_73 , 0x7a ) ;
F_7 ( V_1 , V_74 , 0x01 ) ;
F_7 ( V_1 , V_75 , 0x00 ) ;
F_7 ( V_1 , V_76 , 0x18 ) ;
F_7 ( V_1 , V_77 , 0x0f ) ;
F_7 ( V_1 , 0x8a , 0x20 ) ;
F_7 ( V_1 , 0x8d , 0x0f ) ;
F_7 ( V_1 , 0x8e , 0x08 ) ;
F_7 ( V_1 , 0x03 , 0x08 ) ;
F_7 ( V_1 , V_78 , 0x03 ) ;
F_7 ( V_1 , 0x81 , 0xff ) ;
F_7 ( V_1 , 0x80 , 0x00 ) ;
F_7 ( V_1 , 0x81 , 0xff ) ;
F_7 ( V_1 , 0x80 , 0x20 ) ;
F_7 ( V_1 , 0x03 , 0x01 ) ;
F_7 ( V_1 , 0x03 , 0x00 ) ;
F_7 ( V_1 , 0x03 , 0x08 ) ;
if ( V_1 -> V_36 . V_37 [ ( int ) V_1 -> V_38 ] . V_39 )
V_30 = 0x04 ;
else
V_30 = 0x1e ;
F_7 ( V_1 , V_78 , V_30 ) ;
F_9 ( V_1 , 0x62 , V_31 , 6 ) ;
F_7 ( V_1 , 0x81 , 0x47 ) ;
F_7 ( V_1 , 0x80 , 0x40 ) ;
F_7 ( V_1 , 0x81 , 0x30 ) ;
F_7 ( V_1 , 0x80 , 0x20 ) ;
}
static void F_15 ( struct V_1 * V_1 , T_3 V_12 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ )
F_7 ( V_1 , V_54 + V_79 , V_12 ) ;
}
static void F_16 ( struct V_1 * V_1 , T_3 V_12 )
{
T_2 V_80 [] = { 0x80 , 0x80 , 0x80 , 0x80 , 0x00 , 0x00 } ;
memset ( V_80 , V_12 , sizeof( V_80 ) - 2 ) ;
F_9 ( V_1 , V_58 , V_80 , 6 ) ;
}
static void F_17 ( struct V_1 * V_1 , T_3 V_12 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
T_2 V_82 [] = { 0x05 , 0x02 , 0x02 , 0x05 , 0x0d } ;
T_2 V_83 = 0x01 ;
V_82 [ 3 ] = V_12 ;
V_82 [ 0 ] = 15 - V_12 ;
if ( V_81 -> V_84 == V_85 ) {
F_10 ( V_1 , V_86 , & V_83 , 1 , 3 ) ;
F_10 ( V_1 , V_87 , V_82 , sizeof V_82 , 1 ) ;
}
}
static T_3 F_18 ( struct V_1 * V_1 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
if ( V_81 -> V_84 == V_85 ) {
F_11 ( V_1 , V_87 + 3 ) ;
return V_1 -> V_10 [ 0 ] & 0x0f ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
if ( V_81 -> V_88 )
V_81 -> V_89 = V_90 ;
else
V_81 -> V_89 = - 1 ;
}
static void F_20 ( struct V_1 * V_1 )
{
T_2 V_30 ;
T_2 V_91 [] = { 0x0a , 0x12 , 0x05 , 0x6d , 0xcd , 0x00 , 0x01 , 0x00 } ;
F_6 ( V_32 , L_7 ) ;
F_7 ( V_1 , V_33 , 7 ) ;
F_1 ( V_1 , V_34 , 1 ) ;
F_7 ( V_1 , V_92 , 1 ) ;
F_7 ( V_1 , V_92 , 0 ) ;
F_7 ( V_1 , V_25 , 0x10 ) ;
F_7 ( V_1 , V_35 , 0x19 ) ;
if ( V_1 -> V_36 . V_37 [ ( int ) V_1 -> V_38 ] . V_39 )
V_30 = V_40 ;
else
V_30 = V_41 ;
F_6 ( V_32 , L_8 ,
V_1 -> V_36 . V_37 [ ( int ) V_1 -> V_38 ] . V_39 ,
V_30 ) ;
F_7 ( V_1 , V_42 , V_30 ) ;
F_7 ( V_1 , V_43 , 0x1d ) ;
F_7 ( V_1 , V_44 , 0x02 ) ;
F_7 ( V_1 , V_45 , 0xff ) ;
F_7 ( V_1 , V_46 , 0xff ) ;
F_7 ( V_1 , V_47 , 0xff ) ;
F_7 ( V_1 , V_48 , 0x35 ) ;
F_7 ( V_1 , V_49 , 0x01 ) ;
F_7 ( V_1 , V_50 , 0x00 ) ;
F_7 ( V_1 , V_51 , 0xf7 ) ;
F_7 ( V_1 , V_52 , 0xff ) ;
F_7 ( V_1 , V_53 , 0x07 ) ;
F_7 ( V_1 , V_58 , 0x80 ) ;
F_7 ( V_1 , V_59 , 0x80 ) ;
F_7 ( V_1 , V_60 , 0x80 ) ;
F_7 ( V_1 , V_61 , 0x80 ) ;
F_7 ( V_1 , V_62 , 0x00 ) ;
F_7 ( V_1 , V_63 , 0x00 ) ;
F_7 ( V_1 , V_64 , 0xf0 ) ;
F_7 ( V_1 , V_65 , 0x56 ) ;
F_7 ( V_1 , V_66 , 0x05 ) ;
F_7 ( V_1 , V_67 , 0x60 ) ;
F_7 ( V_1 , V_68 , 0x20 ) ;
F_7 ( V_1 , V_69 , 0x50 ) ;
F_7 ( V_1 , V_70 , 0x86 ) ;
F_7 ( V_1 , V_71 , 0x01 ) ;
F_7 ( V_1 , V_72 , 0x86 ) ;
F_7 ( V_1 , V_73 , 0x14 ) ;
F_7 ( V_1 , V_74 , 0x00 ) ;
F_7 ( V_1 , V_75 , 0x00 ) ;
F_7 ( V_1 , V_76 , 0x00 ) ;
F_7 ( V_1 , V_77 , 0x0a ) ;
F_7 ( V_1 , V_93 , 0x04 ) ;
F_7 ( V_1 , V_78 , 0x01 ) ;
if ( V_1 -> V_36 . V_37 [ ( int ) V_1 -> V_38 ] . V_39 ) {
V_91 [ 0 ] = 0x06 ;
F_10 ( V_1 , V_94 , V_91 , sizeof V_91 , 1 ) ;
F_10 ( V_1 , V_87 , V_95 , sizeof V_95 , 1 ) ;
V_30 = 0x06 ;
F_10 ( V_1 , V_94 , & V_30 , 1 , 1 ) ;
F_10 ( V_1 , V_96 , V_97 , sizeof V_97 , 1 ) ;
V_30 = 0x04 ;
F_10 ( V_1 , V_98 , & V_30 , 1 , 1 ) ;
} else {
V_91 [ 0 ] = 0x0a ;
F_10 ( V_1 , V_94 , V_91 , sizeof V_91 , 1 ) ;
F_10 ( V_1 , V_87 , V_95 , sizeof V_95 , 1 ) ;
V_30 = 0x0a ;
F_10 ( V_1 , V_94 , & V_30 , 1 , 1 ) ;
F_10 ( V_1 , V_96 , V_97 , sizeof V_97 , 1 ) ;
V_30 = 0x04 ;
F_10 ( V_1 , V_98 , & V_30 , 1 , 1 ) ;
}
F_10 ( V_1 , V_99 , V_100 , sizeof V_100 , 1 ) ;
F_9 ( V_1 , V_58 , V_101 , 6 ) ;
F_17 ( V_1 , F_18 ( V_1 ) ) ;
}
static int F_21 ( struct V_1 * V_1 ,
const struct V_102 * V_103 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
struct V_36 * V_36 ;
V_36 = & V_1 -> V_36 ;
V_81 -> V_84 = V_103 -> V_104 ;
if ( V_81 -> V_84 == V_85 ) {
V_36 -> V_37 = V_105 ;
V_36 -> V_106 = F_22 ( V_105 ) ;
} else {
V_36 -> V_37 = V_107 ;
V_36 -> V_106 = F_22 ( V_107 ) ;
}
V_81 -> V_89 = - 1 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
if ( V_81 -> V_84 == V_85 )
F_20 ( V_1 ) ;
else
F_14 ( V_1 ) ;
F_7 ( V_1 , V_92 , 0x08 ) ;
F_13 ( V_1 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
if ( V_81 -> V_84 == V_85 )
F_20 ( V_1 ) ;
else
F_14 ( V_1 ) ;
F_19 ( V_1 ) ;
F_7 ( V_1 , V_92 , 0x08 ) ;
F_13 ( V_1 , 1 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_13 ( V_1 , 0 ) ;
}
static T_2 F_26 ( struct V_1 * V_1 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
if ( V_81 -> V_84 == V_85 ) {
F_11 ( V_1 , V_98 ) ;
F_6 ( V_108 , L_9 , V_1 -> V_10 [ 0 ] ) ;
return V_1 -> V_10 [ 0 ] ;
}
return 0x1f ;
}
static void F_27 ( struct V_1 * V_1 , T_2 V_109 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
if ( V_81 -> V_84 == V_85 ) {
T_2 V_83 = 0x01 ;
F_10 ( V_1 , V_86 , & V_83 , 1 , 3 ) ;
F_10 ( V_1 , V_98 , & V_109 , 1 , 1 ) ;
}
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
T_2 V_110 ;
T_2 V_111 = 128 ;
T_2 V_112 = 20 ;
T_2 V_113 = 4 ;
int V_114 ;
T_2 V_115 , V_116 , V_117 ;
if ( V_81 -> V_89 < 0 )
return;
if ( -- V_81 -> V_89 >= 0 )
return;
V_81 -> V_89 = V_90 ;
V_114 = F_26 ( V_1 ) ;
F_1 ( V_1 , V_118 , 4 ) ;
V_116 = ( V_1 -> V_10 [ 0 ] + V_1 -> V_10 [ 3 ] ) >> 1 ;
V_115 = V_1 -> V_10 [ 1 ] ;
V_117 = V_1 -> V_10 [ 2 ] ;
V_115 = ( ( V_115 << 8 ) - ( V_115 << 4 ) - ( V_115 << 3 ) ) >> 10 ;
V_117 = ( ( V_117 << 7 ) >> 10 ) ;
V_116 = ( ( V_116 << 9 ) + ( V_116 << 7 ) + ( V_116 << 5 ) ) >> 10 ;
V_110 = F_29 ( V_115 + V_116 + V_117 ) ;
F_6 ( V_119 , L_10 , V_110 ) ;
if ( V_110 < V_111 - V_112 || V_110 > V_111 + V_112 ) {
V_114 += ( V_111 - V_110 ) >> V_113 ;
V_114 = F_30 ( V_114 ) ;
F_6 ( V_119 , L_11 , V_114 ) ;
F_27 ( V_1 , ( T_2 ) V_114 ) ;
}
}
static void F_31 ( struct V_1 * V_1 ,
T_4 * V_120 ,
int V_3 )
{
int V_121 ;
V_121 = V_120 [ 0 ] & 0x3f ;
V_3 = ( int ) ( ( ( V_120 [ 0 ] & 0xc0 ) << 2 ) | V_120 [ 1 ] ) ;
if ( V_121 == 0x3f ) {
F_6 ( V_119 ,
L_12 , V_3 ) ;
F_6 ( V_119 , L_13 ,
V_120 [ 2 ] , V_120 [ 3 ] , V_120 [ 4 ] , V_120 [ 5 ] ) ;
V_120 += 30 ;
F_32 ( V_1 , V_122 , NULL , 0 ) ;
F_32 ( V_1 , V_123 , V_120 , V_3 ) ;
return;
}
if ( V_3 ) {
V_120 += 8 ;
F_32 ( V_1 , V_124 , V_120 , V_3 ) ;
} else {
V_1 -> V_125 = V_126 ;
}
}
static int F_33 ( struct V_127 * V_128 )
{
struct V_1 * V_1 =
F_34 ( V_128 -> V_129 , struct V_1 , V_130 ) ;
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
V_1 -> V_131 = 0 ;
if ( ! V_1 -> V_132 )
return 0 ;
switch ( V_128 -> V_103 ) {
case V_133 :
F_15 ( V_1 , V_128 -> V_12 ) ;
break;
case V_134 :
F_16 ( V_1 , V_128 -> V_12 ) ;
break;
case V_135 :
F_17 ( V_1 , V_128 -> V_12 ) ;
break;
case V_136 :
V_81 -> V_88 = V_128 -> V_12 ;
F_19 ( V_1 ) ;
break;
}
return V_1 -> V_131 ;
}
static int F_35 ( struct V_1 * V_1 )
{
struct V_81 * V_81 = (struct V_81 * ) V_1 ;
struct V_137 * V_138 = & V_1 -> V_130 ;
V_1 -> V_139 . V_130 = V_138 ;
F_36 ( V_138 , 4 ) ;
F_37 ( V_138 , & V_140 ,
V_133 , 1 , 127 , 1 , 63 ) ;
F_37 ( V_138 , & V_140 ,
V_134 , 0 , 255 , 1 , 127 ) ;
if ( V_81 -> V_84 == V_85 )
F_37 ( V_138 , & V_140 ,
V_135 , 0 , 15 , 1 , 7 ) ;
F_37 ( V_138 , & V_140 ,
V_136 , 0 , 1 , 1 , 1 ) ;
if ( V_138 -> error ) {
F_3 ( L_14 ) ;
return V_138 -> error ;
}
return 0 ;
}
static int F_38 ( struct V_141 * V_142 ,
const struct V_102 * V_103 )
{
return F_39 ( V_142 , V_103 , & V_143 , sizeof( struct V_81 ) ,
V_144 ) ;
}
