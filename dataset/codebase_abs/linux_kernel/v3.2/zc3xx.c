static T_1 F_1 ( struct V_1 * V_1 ,
T_2 V_2 )
{
int V_3 ;
if ( V_1 -> V_4 < 0 )
return 0 ;
V_3 = F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
0xa1 ,
V_6 | V_7 | V_8 ,
0x01 ,
V_2 , V_1 -> V_9 , 1 ,
500 ) ;
if ( V_3 < 0 ) {
F_4 ( L_1 , V_3 ) ;
V_1 -> V_4 = V_3 ;
return 0 ;
}
return V_1 -> V_9 [ 0 ] ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
T_2 V_2 )
{
T_1 V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
F_6 ( V_10 , L_2 , V_2 , V_3 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_1 ,
T_1 V_11 ,
T_2 V_2 )
{
int V_3 ;
if ( V_1 -> V_4 < 0 )
return;
V_3 = F_2 ( V_1 -> V_5 ,
F_8 ( V_1 -> V_5 , 0 ) ,
0xa0 ,
V_12 | V_7 | V_8 ,
V_11 , V_2 , NULL , 0 ,
500 ) ;
if ( V_3 < 0 ) {
F_4 ( L_3 , V_3 ) ;
V_1 -> V_4 = V_3 ;
}
}
static void F_9 ( struct V_1 * V_1 ,
T_1 V_11 ,
T_2 V_2 )
{
F_6 ( V_13 , L_4 , V_2 , V_11 ) ;
F_7 ( V_1 , V_11 , V_2 ) ;
}
static T_2 F_10 ( struct V_1 * V_1 ,
T_1 V_14 )
{
T_1 V_15 ;
T_2 V_16 ;
if ( V_1 -> V_4 < 0 )
return 0 ;
F_7 ( V_1 , V_14 , 0x0092 ) ;
F_7 ( V_1 , 0x02 , 0x0090 ) ;
F_11 ( 20 ) ;
V_15 = F_1 ( V_1 , 0x0091 ) ;
if ( V_15 != 0x00 )
F_4 ( L_5 , V_15 ) ;
V_16 = F_1 ( V_1 , 0x0095 ) ;
V_16 |= F_1 ( V_1 , 0x0096 ) << 8 ;
F_6 ( V_10 , L_6 ,
V_14 , V_16 , V_15 ) ;
return V_16 ;
}
static T_1 F_12 ( struct V_1 * V_1 ,
T_1 V_14 ,
T_1 V_17 ,
T_1 V_18 )
{
T_1 V_15 ;
if ( V_1 -> V_4 < 0 )
return 0 ;
F_7 ( V_1 , V_14 , 0x92 ) ;
F_7 ( V_1 , V_17 , 0x93 ) ;
F_7 ( V_1 , V_18 , 0x94 ) ;
F_7 ( V_1 , 0x01 , 0x90 ) ;
F_11 ( 1 ) ;
V_15 = F_1 ( V_1 , 0x0091 ) ;
if ( V_15 != 0x00 )
F_4 ( L_7 , V_15 ) ;
F_6 ( V_13 , L_8 ,
V_14 , V_18 , V_17 , V_15 ) ;
return V_15 ;
}
static void F_13 ( struct V_1 * V_1 ,
const struct V_19 * V_20 )
{
while ( V_20 -> V_21 ) {
switch ( V_20 -> V_21 ) {
case 0xa0 :
F_9 ( V_1 , V_20 -> V_22 , V_20 -> V_23 ) ;
break;
case 0xa1 :
F_5 ( V_1 , V_20 -> V_23 ) ;
break;
case 0xaa :
F_12 ( V_1 ,
V_20 -> V_22 ,
V_20 -> V_23 & 0xff ,
V_20 -> V_23 >> 8 ) ;
break;
case 0xbb :
F_12 ( V_1 ,
V_20 -> V_23 >> 8 ,
V_20 -> V_23 & 0xff ,
V_20 -> V_22 ) ;
break;
default:
F_11 ( V_20 -> V_23 ) ;
break;
}
V_20 ++ ;
F_11 ( 1 ) ;
}
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
int V_25 ;
const T_1 * V_26 ;
static const T_1 V_27 [ 9 ] =
{ 0x74 , 0xed , 0xed , 0xed , 0x74 , 0xed , 0xed , 0xed , 0x74 } ;
static const T_1 V_28 [ 9 ] =
{ 0x50 , 0xf8 , 0xf8 , 0xf8 , 0x50 , 0xf8 , 0xf8 , 0xf8 , 0x50 } ;
static const T_1 V_29 [ 9 ] =
{ 0x58 , 0xf4 , 0xf4 , 0xf4 , 0x58 , 0xf4 , 0xf4 , 0xf4 , 0x58 } ;
static const T_1 V_30 [ 9 ] =
{ 0x4c , 0xf5 , 0xff , 0xf9 , 0x51 , 0xf5 , 0xfb , 0xed , 0x5f } ;
static const T_1 V_31 [ 9 ] =
{ 0x60 , 0xf0 , 0xf0 , 0xf0 , 0x60 , 0xf0 , 0xf0 , 0xf0 , 0x60 } ;
static const T_1 V_32 [ 9 ] =
{ 0x68 , 0xec , 0xec , 0xec , 0x68 , 0xec , 0xec , 0xec , 0x68 } ;
static const T_1 V_33 [ 9 ] =
{ 0x7b , 0xea , 0xea , 0xea , 0x7b , 0xea , 0xea , 0xea , 0x7b } ;
static const T_1 * V_34 [ V_35 ] = {
[ V_36 ] = V_27 ,
[ V_37 ] = V_29 ,
[ V_38 ] = NULL ,
[ V_39 ] = V_33 ,
[ V_40 ] = V_28 ,
[ V_41 ] = NULL ,
[ V_42 ] = NULL ,
[ V_43 ] = V_31 ,
[ V_44 ] = V_31 ,
[ V_45 ] = NULL ,
[ V_46 ] = V_28 ,
[ V_47 ] = V_28 ,
[ V_48 ] = V_29 ,
[ V_49 ] = NULL ,
[ V_50 ] = NULL ,
[ V_51 ] = V_30 ,
[ V_52 ] = V_28 ,
[ V_53 ] = V_31 ,
[ V_54 ] = V_32 ,
} ;
V_26 = V_34 [ V_24 -> V_55 ] ;
if ( V_26 == NULL )
return;
for ( V_25 = 0 ; V_25 < F_15 ( V_29 ) ; V_25 ++ )
F_9 ( V_1 , V_26 [ V_25 ] , 0x010a + V_25 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
int V_56 ;
static const T_1 V_57 [] [ 2 ] = {
{ 0x02 , 0x03 } ,
{ 0x04 , 0x07 } ,
{ 0x08 , 0x0f } ,
{ 0x10 , 0x1e }
} ;
V_56 = V_24 -> V_58 [ V_59 ] . V_22 ;
F_9 ( V_1 , V_57 [ V_56 ] [ 0 ] , 0x01c6 ) ;
F_5 ( V_1 , 0x01c8 ) ;
F_5 ( V_1 , 0x01c9 ) ;
F_5 ( V_1 , 0x01ca ) ;
F_9 ( V_1 , V_57 [ V_56 ] [ 1 ] , 0x01cb ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
const T_1 * V_60 ;
int V_61 , V_25 , V_62 , V_63 , V_64 , V_65 , V_66 ;
T_1 V_67 [ 16 ] ;
static const T_1 V_68 [ 16 ] =
{ 0x50 , 0x38 , 0x2d , 0x28 , 0x24 , 0x21 , 0x1e , 0x1d ,
0x1d , 0x1b , 0x1b , 0x1b , 0x19 , 0x18 , 0x18 , 0x18 } ;
static const T_1 V_69 [ 16 ] =
{ 0x2c , 0x1a , 0x12 , 0x0c , 0x0a , 0x06 , 0x06 , 0x06 ,
0x04 , 0x06 , 0x04 , 0x04 , 0x03 , 0x03 , 0x02 , 0x02 } ;
static const T_1 V_70 [ 6 ] [ 16 ] = {
{ 0x00 , 0x00 , 0x03 , 0x0d , 0x1b , 0x2e , 0x45 , 0x5f ,
0x79 , 0x93 , 0xab , 0xc1 , 0xd4 , 0xe5 , 0xf3 , 0xff } ,
{ 0x01 , 0x0c , 0x1f , 0x3a , 0x53 , 0x6d , 0x85 , 0x9c ,
0xb0 , 0xc2 , 0xd1 , 0xde , 0xe9 , 0xf2 , 0xf9 , 0xff } ,
{ 0x04 , 0x16 , 0x30 , 0x4e , 0x68 , 0x81 , 0x98 , 0xac ,
0xbe , 0xcd , 0xda , 0xe4 , 0xed , 0xf5 , 0xfb , 0xff } ,
{ 0x13 , 0x38 , 0x59 , 0x79 , 0x92 , 0xa7 , 0xb9 , 0xc8 ,
0xd4 , 0xdf , 0xe7 , 0xee , 0xf4 , 0xf9 , 0xfc , 0xff } ,
{ 0x20 , 0x4b , 0x6e , 0x8d , 0xa3 , 0xb5 , 0xc5 , 0xd2 ,
0xdc , 0xe5 , 0xec , 0xf2 , 0xf6 , 0xfa , 0xfd , 0xff } ,
{ 0x24 , 0x44 , 0x64 , 0x84 , 0x9d , 0xb2 , 0xc4 , 0xd3 ,
0xe0 , 0xeb , 0xf4 , 0xff , 0xff , 0xff , 0xff , 0xff } ,
} ;
V_60 = V_70 [ V_24 -> V_58 [ GAMMA ] . V_22 - 1 ] ;
V_63 = ( ( int ) V_24 -> V_58 [ V_71 ] . V_22 - 128 ) ;
V_62 = ( ( int ) V_24 -> V_58 [ V_72 ] . V_22 - 128 ) ;
V_64 = 0 ;
V_65 = V_66 = 0 ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
V_61 = V_60 [ V_25 ] + V_68 [ V_25 ] * V_62 / 256
- V_69 [ V_25 ] * V_63 / 256 - V_64 / 2 ;
if ( V_61 > 0xff )
V_61 = 0xff ;
else if ( V_61 < 0 )
V_61 = 0 ;
F_9 ( V_1 , V_61 , 0x0120 + V_25 ) ;
if ( V_63 > 0 )
V_64 -- ;
else if ( V_63 < 0 )
V_64 ++ ;
if ( V_25 > 1 )
V_67 [ V_25 - 1 ] = ( V_61 - V_66 ) / 2 ;
else if ( V_25 != 0 )
V_67 [ 0 ] = V_65 == 0 ? 0 : ( V_61 - V_65 ) ;
V_66 = V_65 ;
V_65 = V_61 ;
}
V_67 [ 15 ] = ( 0xff - V_66 ) / 2 ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
F_9 ( V_1 , V_67 [ V_25 ] , 0x0130 + V_25 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
V_24 -> V_58 [ V_73 ] . V_22 = ( F_10 ( V_1 , 0x25 ) << 9 )
| ( F_10 ( V_1 , 0x26 ) << 1 )
| ( F_10 ( V_1 , 0x27 ) >> 7 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
int V_22 ;
V_22 = V_24 -> V_58 [ V_73 ] . V_22 ;
F_12 ( V_1 , 0x25 , V_22 >> 9 , 0x00 ) ;
F_12 ( V_1 , 0x26 , V_22 >> 1 , 0x00 ) ;
F_12 ( V_1 , 0x27 , V_22 << 7 , 0x00 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
T_1 V_74 ;
switch ( V_24 -> V_55 ) {
case V_36 :
case V_40 :
case V_42 :
case V_43 :
case V_48 :
case V_51 :
case V_53 :
return;
}
F_9 ( V_1 , V_75 , 0x0008 ) ;
V_74 = 0x30 ;
F_9 ( V_1 , V_74 , 0x0007 ) ;
#if V_75 == 0 || V_75 == 1 || V_75 == 2
V_74 = 0xff ;
#elif V_75 == 3
V_74 = 0xf0 ;
#elif V_75 == 4
V_74 = 0xe0 ;
#else
V_74 = 0x20 ;
#endif
F_9 ( V_1 , V_74 , 0x0018 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
int V_25 , V_76 ;
const struct V_19 * V_77 ;
static const struct V_19 * V_78 [ V_35 ] [ 6 ] = {
[ V_36 ] =
{ V_79 , V_79 ,
V_80 , V_80 ,
V_81 , V_81 } ,
[ V_37 ] =
{ V_82 , V_83 ,
V_84 , V_85 ,
V_86 , V_87 } ,
[ V_38 ] =
{ V_82 , V_83 ,
NULL , NULL ,
NULL , NULL } ,
[ V_39 ] =
{ V_88 , V_89 ,
V_90 , V_91 ,
V_92 , V_93 } ,
[ V_40 ] =
{ V_94 , V_94 ,
V_95 , V_95 ,
V_96 , V_96 } ,
[ V_41 ] =
{ V_97 , V_97 ,
V_98 , V_98 ,
V_99 , V_99 } ,
[ V_42 ] =
{ V_100 , V_101 ,
V_102 , V_103 ,
V_104 , V_105 } ,
[ V_43 ] =
{ V_106 , V_107 ,
V_108 , V_109 ,
V_110 , V_111 } ,
[ V_44 ] =
{ V_112 , V_113 ,
V_114 , V_115 ,
V_116 , V_117 } ,
[ V_45 ] =
{ V_118 , V_119 ,
V_120 , V_121 ,
V_122 , V_123 } ,
[ V_46 ] =
{ V_124 , V_125 ,
V_126 , V_127 ,
V_128 , V_129 } ,
[ V_47 ] =
{ V_130 , V_131 ,
V_132 , V_133 ,
V_134 , V_135 } ,
[ V_48 ] =
{ V_136 , V_136 ,
V_137 , V_137 ,
V_138 , V_138 } ,
[ V_49 ] =
{ NULL , NULL ,
NULL , NULL ,
NULL , NULL } ,
[ V_50 ] =
{ V_139 , V_139 ,
V_140 , V_140 ,
V_141 , V_141 } ,
[ V_51 ] =
{ V_142 , V_143 ,
V_144 , V_145 ,
V_146 , V_147 } ,
[ V_52 ] =
{ V_148 , V_149 ,
V_150 , V_151 ,
V_152 , V_153 } ,
[ V_53 ] =
{ V_154 , V_154 ,
V_155 , V_155 ,
V_156 , V_156 } ,
[ V_54 ] =
{ V_157 , V_158 ,
V_159 , V_160 ,
V_161 , V_162 } ,
} ;
V_25 = V_24 -> V_58 [ V_163 ] . V_22 * 2 ;
V_76 = V_1 -> V_164 . V_165 [ V_1 -> V_166 ] . V_167 ;
if ( V_76 )
V_25 ++ ;
V_77 = V_78 [ V_24 -> V_55 ] [ V_25 ] ;
if ( V_77 == NULL )
return;
F_13 ( V_1 , V_77 ) ;
switch ( V_24 -> V_55 ) {
case V_40 :
if ( V_76
&& V_24 -> V_58 [ V_163 ] . V_22 == 1 )
F_9 ( V_1 , 0x85 , 0x018d ) ;
break;
case V_48 :
if ( ! V_76 ) {
if ( V_24 -> V_58 [ V_163 ] . V_22 != 0 )
F_9 ( V_1 , 0x40 , 0x0002 ) ;
else
F_9 ( V_1 , 0x44 , 0x0002 ) ;
}
break;
case V_51 :
F_9 ( V_1 , 0x00 , 0x01a7 ) ;
break;
}
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
T_1 V_168 ;
if ( V_24 -> V_58 [ V_169 ] . V_22 )
V_168 = 0x42 ;
else
V_168 = 0x02 ;
F_9 ( V_1 , V_168 , 0x0180 ) ;
}
static void F_23 ( struct V_1 * V_1 , int V_55 )
{
F_9 ( V_1 , 0x01 , 0x0000 ) ;
switch ( V_55 ) {
case V_50 :
F_9 ( V_1 , 0x03 , 0x003a ) ;
F_9 ( V_1 , 0x0c , 0x003b ) ;
F_9 ( V_1 , 0x08 , 0x0038 ) ;
break;
case V_36 :
case V_40 :
case V_48 :
case V_46 :
case V_47 :
case V_52 :
case V_53 :
F_9 ( V_1 , 0x0d , 0x003a ) ;
F_9 ( V_1 , 0x02 , 0x003b ) ;
F_9 ( V_1 , 0x00 , 0x0038 ) ;
break;
case V_43 :
case V_51 :
F_9 ( V_1 , 0x03 , 0x003b ) ;
F_9 ( V_1 , 0x0c , 0x003a ) ;
F_9 ( V_1 , 0x0b , 0x0039 ) ;
if ( V_55 == V_51 )
F_9 ( V_1 , 0x0b , 0x0038 ) ;
break;
}
}
static void F_24 ( struct V_1 * V_1 , int V_55 )
{
F_9 ( V_1 , 0x01 , 0x0000 ) ;
F_9 ( V_1 , V_55 , 0x0010 ) ;
F_9 ( V_1 , 0x01 , 0x0001 ) ;
F_9 ( V_1 , 0x03 , 0x0012 ) ;
F_9 ( V_1 , 0x01 , 0x0012 ) ;
}
static int F_25 ( struct V_1 * V_1 )
{
T_2 V_170 ;
F_24 ( V_1 , 0x0f ) ;
F_9 ( V_1 , 0x08 , 0x008d ) ;
F_11 ( 150 ) ;
V_170 = ( ( F_10 ( V_1 , 0x00 ) & 0x0f ) << 4 )
| ( ( F_10 ( V_1 , 0x01 ) & 0xf0 ) >> 4 ) ;
F_6 ( V_171 , L_9 , V_170 ) ;
if ( V_170 == 0x0007 ) {
F_23 ( V_1 , V_50 ) ;
return 0x0f ;
}
return - 1 ;
}
static int F_26 ( struct V_1 * V_1 )
{
T_2 V_172 ;
F_24 ( V_1 , 0x00 ) ;
F_12 ( V_1 , 0x01 , 0xaa , 0x00 ) ;
V_172 = F_10 ( V_1 , 0x01 ) ;
if ( V_172 != 0 )
return 0x00 ;
F_24 ( V_1 , 0x04 ) ;
F_12 ( V_1 , 0x01 , 0xaa , 0x00 ) ;
V_172 = F_10 ( V_1 , 0x01 ) ;
if ( V_172 != 0 )
return 0x04 ;
F_24 ( V_1 , 0x06 ) ;
F_9 ( V_1 , 0x08 , 0x008d ) ;
F_12 ( V_1 , 0x11 , 0xaa , 0x00 ) ;
V_172 = F_10 ( V_1 , 0x11 ) ;
if ( V_172 != 0 ) {
goto V_173;
}
F_24 ( V_1 , 0x08 ) ;
F_12 ( V_1 , 0x1c , 0x00 , 0x00 ) ;
F_12 ( V_1 , 0x15 , 0xaa , 0x00 ) ;
V_172 = F_10 ( V_1 , 0x15 ) ;
if ( V_172 != 0 )
return 0x08 ;
F_24 ( V_1 , 0x0a ) ;
F_12 ( V_1 , 0x07 , 0xaa , 0xaa ) ;
V_172 = F_10 ( V_1 , 0x07 ) ;
if ( V_172 != 0 )
return 0x0a ;
V_172 = F_10 ( V_1 , 0x03 ) ;
if ( V_172 != 0 )
return 0x0a ;
V_172 = F_10 ( V_1 , 0x04 ) ;
if ( V_172 != 0 )
return 0x0a ;
F_24 ( V_1 , 0x0c ) ;
F_12 ( V_1 , 0x01 , 0x11 , 0x00 ) ;
V_172 = F_10 ( V_1 , 0x01 ) ;
if ( V_172 != 0 )
return 0x0c ;
F_24 ( V_1 , 0x0e ) ;
F_9 ( V_1 , 0x08 , 0x008d ) ;
F_12 ( V_1 , 0x03 , 0xaa , 0x00 ) ;
F_11 ( 50 ) ;
V_172 = F_10 ( V_1 , 0x03 ) ;
if ( V_172 != 0 ) {
F_23 ( V_1 , V_51 ) ;
return 0x0e ;
}
F_24 ( V_1 , 0x02 ) ;
F_12 ( V_1 , 0x01 , 0xaa , 0x00 ) ;
V_172 = F_10 ( V_1 , 0x01 ) ;
if ( V_172 != 0 )
return 0x02 ;
V_173:
F_5 ( V_1 , 0x0010 ) ;
F_5 ( V_1 , 0x0010 ) ;
F_9 ( V_1 , 0x01 , 0x0000 ) ;
F_9 ( V_1 , 0x01 , 0x0001 ) ;
F_9 ( V_1 , 0x06 , 0x0010 ) ;
F_9 ( V_1 , 0xa1 , 0x008b ) ;
F_9 ( V_1 , 0x08 , 0x008d ) ;
F_11 ( 500 ) ;
F_9 ( V_1 , 0x01 , 0x0012 ) ;
F_12 ( V_1 , 0x12 , 0x80 , 0x00 ) ;
V_172 = F_10 ( V_1 , 0x0a ) << 8 ;
V_172 |= F_10 ( V_1 , 0x0b ) ;
F_6 ( V_171 , L_10 , V_172 ) ;
switch ( V_172 ) {
case 0x7631 :
F_9 ( V_1 , 0x06 , 0x0010 ) ;
break;
case 0x7620 :
case 0x7648 :
break;
default:
return - 1 ;
}
return V_172 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
int V_25 ;
T_2 V_172 ;
F_9 ( V_1 , 0x02 , 0x0010 ) ;
F_5 ( V_1 , 0x0010 ) ;
F_9 ( V_1 , 0x01 , 0x0000 ) ;
F_9 ( V_1 , 0x00 , 0x0010 ) ;
F_9 ( V_1 , 0x01 , 0x0001 ) ;
F_9 ( V_1 , 0x91 , 0x008b ) ;
F_9 ( V_1 , 0x03 , 0x0012 ) ;
F_9 ( V_1 , 0x01 , 0x0012 ) ;
F_9 ( V_1 , 0x05 , 0x0012 ) ;
V_172 = F_10 ( V_1 , 0x14 ) ;
if ( V_172 != 0 )
return 0x11 ;
V_172 = F_10 ( V_1 , 0x15 ) ;
if ( V_172 != 0 )
return 0x11 ;
V_172 = F_10 ( V_1 , 0x16 ) ;
if ( V_172 != 0 )
return 0x11 ;
F_9 ( V_1 , 0x02 , 0x0010 ) ;
V_172 = F_5 ( V_1 , 0x000b ) << 8 ;
V_172 |= F_5 ( V_1 , 0x000a ) ;
F_6 ( V_171 , L_11 , V_172 ) ;
F_5 ( V_1 , 0x0010 ) ;
if ( ( V_172 & 0xff00 ) == 0x6400 )
return 0x02 ;
for ( V_25 = 0 ; V_25 < F_15 ( V_174 ) ; V_25 ++ ) {
if ( V_174 [ V_25 ] . V_175 == V_172 ) {
V_24 -> V_176 = V_172 ;
F_23 ( V_1 , V_52 ) ;
return V_174 [ V_25 ] . V_177 ;
}
}
F_9 ( V_1 , 0x01 , 0x0000 ) ;
F_9 ( V_1 , 0x01 , 0x0001 ) ;
F_9 ( V_1 , 0xdd , 0x008b ) ;
F_9 ( V_1 , 0x0a , 0x0010 ) ;
F_9 ( V_1 , 0x03 , 0x0012 ) ;
F_9 ( V_1 , 0x01 , 0x0012 ) ;
V_172 = F_10 ( V_1 , 0x00 ) ;
if ( V_172 != 0 ) {
F_6 ( V_171 , L_12 ) ;
return 0x0a ;
}
F_9 ( V_1 , 0x01 , 0x0000 ) ;
F_9 ( V_1 , 0x01 , 0x0001 ) ;
F_9 ( V_1 , 0x98 , 0x008b ) ;
F_9 ( V_1 , 0x01 , 0x0010 ) ;
F_9 ( V_1 , 0x03 , 0x0012 ) ;
F_11 ( 2 ) ;
F_9 ( V_1 , 0x01 , 0x0012 ) ;
V_172 = F_10 ( V_1 , 0x00 ) ;
if ( V_172 != 0 ) {
F_6 ( V_171 , L_13 , V_172 ) ;
if ( V_172 == 0x0011 )
return 0x0303 ;
if ( V_172 == 0x0029 )
F_23 ( V_1 , V_40 ) ;
return V_172 ;
}
F_9 ( V_1 , 0x01 , 0x0000 ) ;
F_9 ( V_1 , 0x01 , 0x0001 ) ;
F_9 ( V_1 , 0xa1 , 0x008b ) ;
F_9 ( V_1 , 0x08 , 0x008d ) ;
F_9 ( V_1 , 0x06 , 0x0010 ) ;
F_9 ( V_1 , 0x01 , 0x0012 ) ;
F_9 ( V_1 , 0x05 , 0x0012 ) ;
if ( F_10 ( V_1 , 0x1c ) == 0x007f
&& F_10 ( V_1 , 0x1d ) == 0x00a2 ) {
F_23 ( V_1 , V_48 ) ;
return 0x06 ;
}
F_9 ( V_1 , 0x01 , 0x0000 ) ;
F_9 ( V_1 , 0x00 , 0x0002 ) ;
F_9 ( V_1 , 0x01 , 0x0010 ) ;
F_9 ( V_1 , 0x01 , 0x0001 ) ;
F_9 ( V_1 , 0xee , 0x008b ) ;
F_9 ( V_1 , 0x03 , 0x0012 ) ;
F_9 ( V_1 , 0x01 , 0x0012 ) ;
F_9 ( V_1 , 0x05 , 0x0012 ) ;
V_172 = F_10 ( V_1 , 0x00 ) << 8 ;
V_172 |= F_10 ( V_1 , 0x01 ) ;
F_6 ( V_171 , L_14 , V_172 ) ;
if ( V_172 == 0x2030 ) {
#ifdef F_28
T_1 V_15 ;
V_15 = F_10 ( V_1 , 0x02 ) ;
F_6 ( V_171 , L_15 , V_15 ) ;
#endif
F_23 ( V_1 , V_53 ) ;
return V_172 ;
}
F_9 ( V_1 , 0x01 , 0x0000 ) ;
F_9 ( V_1 , 0x0a , 0x0010 ) ;
F_9 ( V_1 , 0xd3 , 0x008b ) ;
F_9 ( V_1 , 0x01 , 0x0001 ) ;
F_9 ( V_1 , 0x03 , 0x0012 ) ;
F_9 ( V_1 , 0x01 , 0x0012 ) ;
F_9 ( V_1 , 0x05 , 0x0012 ) ;
F_9 ( V_1 , 0xd3 , 0x008b ) ;
V_172 = F_10 ( V_1 , 0x01 ) ;
if ( V_172 != 0 ) {
F_6 ( V_171 , L_16 , V_172 ) ;
return 0x16 ;
}
return - 1 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
int V_55 ;
switch ( V_24 -> V_55 ) {
case V_45 :
return - 1 ;
case V_39 :
return - 1 ;
case V_50 :
V_55 = F_25 ( V_1 ) ;
if ( V_55 >= 0 )
return V_55 ;
break;
}
V_55 = F_26 ( V_1 ) ;
if ( V_55 >= 0 )
return V_55 ;
return F_27 ( V_1 ) ;
}
static int F_30 ( struct V_1 * V_1 ,
const struct V_178 * V_179 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
if ( V_179 -> V_180 == 0x301b )
V_24 -> V_181 = V_182 ;
else
V_24 -> V_181 = V_183 ;
V_24 -> V_55 = V_179 -> V_184 ;
V_1 -> V_164 . V_58 = V_24 -> V_58 ;
V_24 -> V_185 = V_186 ;
if ( V_1 -> V_187 && V_1 -> V_5 -> V_188 < V_189 )
V_1 -> V_190 -- ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
struct V_164 * V_164 ;
int V_55 ;
static const T_1 gamma [ V_35 ] = {
[ V_36 ] = 4 ,
[ V_37 ] = 4 ,
[ V_38 ] = 5 ,
[ V_39 ] = 3 ,
[ V_40 ] = 4 ,
[ V_41 ] = 4 ,
[ V_42 ] = 4 ,
[ V_43 ] = 4 ,
[ V_44 ] = 4 ,
[ V_45 ] = 4 ,
[ V_46 ] = 4 ,
[ V_47 ] = 4 ,
[ V_48 ] = 3 ,
[ V_49 ] = 4 ,
[ V_50 ] = 4 ,
[ V_51 ] = 4 ,
[ V_52 ] = 4 ,
[ V_53 ] = 4 ,
[ V_54 ] = 3 ,
} ;
static const T_1 V_191 [ V_35 ] = {
[ V_36 ] = 2 ,
[ V_37 ] = 1 ,
[ V_38 ] = 1 ,
[ V_39 ] = 1 ,
[ V_40 ] = 1 ,
[ V_41 ] = 1 ,
[ V_42 ] = 1 ,
[ V_43 ] = 1 ,
[ V_44 ] = 1 ,
[ V_45 ] = 2 ,
[ V_46 ] = 1 ,
[ V_47 ] = 1 ,
[ V_48 ] = 2 ,
[ V_49 ] = 1 ,
[ V_50 ] = 0 ,
[ V_51 ] = 1 ,
[ V_52 ] = 1 ,
[ V_53 ] = 1 ,
[ V_54 ] = 1 ,
} ;
V_55 = F_29 ( V_1 ) ;
if ( V_55 >= 0 )
F_6 ( V_171 , L_17 , V_55 ) ;
if ( ( unsigned ) V_192 < V_35 ) {
V_24 -> V_55 = V_192 ;
F_6 ( V_171 , L_18 , V_192 ) ;
} else {
switch ( V_55 ) {
case - 1 :
switch ( V_24 -> V_55 ) {
case V_45 :
F_6 ( V_171 , L_19 ) ;
break;
case V_39 :
F_6 ( V_171 , L_20 ) ;
break;
default:
F_32 ( L_21 ) ;
V_24 -> V_55 = V_54 ;
}
break;
case 0 :
V_55 = F_10 ( V_1 , 0x00 ) ;
F_6 ( V_171 , L_22 , V_55 ) ;
switch ( V_55 ) {
case 0 :
case 1 :
F_6 ( V_171 , L_23 ) ;
V_24 -> V_55 = V_42 ;
break;
default:
F_6 ( V_171 , L_24 ) ;
V_24 -> V_55 = V_43 ;
break;
}
break;
case 0x02 :
F_6 ( V_171 , L_25 ) ;
V_24 -> V_55 = V_54 ;
break;
case 0x04 :
F_6 ( V_171 , L_26 ) ;
V_24 -> V_55 = V_37 ;
break;
case 0x08 :
F_6 ( V_171 , L_27 ) ;
V_24 -> V_55 = V_41 ;
break;
case 0x0a :
F_6 ( V_171 ,
L_28 ,
V_24 -> V_176 ) ;
V_24 -> V_55 = V_52 ;
break;
case 0x0c :
F_6 ( V_171 , L_29 ) ;
V_24 -> V_55 = V_44 ;
break;
case 0x0e :
F_6 ( V_171 , L_30 ) ;
V_24 -> V_55 = V_51 ;
break;
case 0x0f :
F_6 ( V_171 , L_31 ) ;
V_24 -> V_55 = V_50 ;
break;
case 0x10 :
case 0x12 :
F_6 ( V_171 , L_32 ) ;
V_24 -> V_55 = V_54 ;
break;
case 0x11 :
F_6 ( V_171 , L_24 ) ;
V_24 -> V_55 = V_43 ;
break;
case 0x13 :
case 0x15 :
F_6 ( V_171 ,
L_33 ,
V_24 -> V_176 ) ;
V_24 -> V_55 = V_24 -> V_181 == V_182
? V_46
: V_47 ;
break;
case 0x14 :
F_6 ( V_171 ,
L_34 ,
V_24 -> V_176 ) ;
V_24 -> V_55 = V_38 ;
break;
case 0x16 :
F_6 ( V_171 , L_35 ) ;
V_24 -> V_55 = V_36 ;
break;
case 0x29 :
F_6 ( V_171 , L_36 ) ;
V_24 -> V_55 = V_40 ;
break;
case 0x0303 :
F_6 ( V_171 , L_20 ) ;
V_24 -> V_55 = V_39 ;
break;
case 0x2030 :
F_6 ( V_171 , L_37 ) ;
V_24 -> V_55 = V_53 ;
V_24 -> V_58 [ V_59 ] . V_193 = 0 ;
break;
case 0x7620 :
F_6 ( V_171 , L_38 ) ;
V_24 -> V_55 = V_48 ;
break;
case 0x7631 :
F_6 ( V_171 , L_39 ) ;
V_24 -> V_55 = V_49 ;
break;
case 0x7648 :
F_6 ( V_171 , L_40 ) ;
V_24 -> V_55 = V_48 ;
break;
default:
F_4 ( L_41 , V_55 ) ;
return - V_194 ;
}
}
if ( V_55 < 0x20 ) {
if ( V_55 == - 1 || V_55 == 0x10 || V_55 == 0x12 )
F_9 ( V_1 , 0x02 , 0x0010 ) ;
F_5 ( V_1 , 0x0010 ) ;
}
V_164 = & V_1 -> V_164 ;
switch ( V_191 [ V_24 -> V_55 ] ) {
case 0 :
V_164 -> V_165 = V_195 ;
V_164 -> V_196 = F_15 ( V_195 ) ;
break;
case 1 :
V_164 -> V_165 = V_197 ;
V_164 -> V_196 = F_15 ( V_197 ) ;
break;
default:
V_164 -> V_165 = V_198 ;
V_164 -> V_196 = F_15 ( V_198 ) ;
break;
}
V_24 -> V_58 [ GAMMA ] . V_193 = gamma [ V_24 -> V_55 ] ;
switch ( V_24 -> V_55 ) {
case V_43 :
break;
case V_49 :
V_1 -> V_199 = ( 1 << V_163 ) | ( 1 << V_73 ) ;
break;
default:
V_1 -> V_199 = ( 1 << V_73 ) ;
break;
}
#if V_200
if ( V_24 -> V_58 [ V_169 ] . V_22 )
V_1 -> V_201 = ( 1 << V_73 ) ;
#endif
F_9 ( V_1 , 0x01 , 0x0000 ) ;
return V_1 -> V_4 ;
}
static int F_33 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
int V_76 ;
static const struct V_19 * V_202 [ V_35 ] [ 2 ] = {
[ V_36 ] =
{ V_203 , V_204 } ,
[ V_37 ] =
{ V_205 , V_206 } ,
[ V_38 ] =
{ V_207 , V_208 } ,
[ V_39 ] =
{ V_209 , V_210 } ,
[ V_40 ] =
{ V_211 , V_212 } ,
[ V_41 ] =
{ V_213 , V_214 } ,
[ V_42 ] =
{ V_215 , V_216 } ,
[ V_43 ] =
{ V_217 , V_218 } ,
[ V_44 ] =
{ V_219 , V_220 } ,
[ V_45 ] =
{ V_221 , V_222 } ,
[ V_46 ] =
{ V_223 , V_224 } ,
[ V_47 ] =
{ V_225 , V_226 } ,
[ V_48 ] =
{ V_227 , V_228 } ,
[ V_49 ] =
{ V_229 , V_230 } ,
[ V_50 ] =
{ V_231 , V_232 } ,
[ V_51 ] =
{ V_233 , V_234 } ,
[ V_52 ] =
{ V_235 , V_236 } ,
[ V_53 ] =
{ V_237 , V_238 } ,
[ V_54 ] =
{ V_239 , V_240 } ,
} ;
F_34 ( V_24 -> V_241 , V_1 -> V_242 , V_1 -> V_243 ,
0x21 ) ;
F_35 ( V_24 -> V_241 , V_24 -> V_185 ) ;
V_76 = V_1 -> V_164 . V_165 [ V_1 -> V_166 ] . V_167 ;
switch ( V_24 -> V_55 ) {
case V_43 :
F_29 ( V_1 ) ;
break;
case V_50 :
F_13 ( V_1 , V_244 ) ;
break;
}
F_13 ( V_1 , V_202 [ V_24 -> V_55 ] [ V_76 ] ) ;
switch ( V_24 -> V_55 ) {
case V_36 :
case V_40 :
case V_48 :
case V_53 :
case V_54 :
case V_39 :
F_5 ( V_1 , 0x0002 ) ;
F_9 ( V_1 , 0x09 , 0x01ad ) ;
F_9 ( V_1 , 0x15 , 0x01ae ) ;
if ( V_24 -> V_55 == V_54 )
break;
F_9 ( V_1 , 0x0d , 0x003a ) ;
F_9 ( V_1 , 0x02 , 0x003b ) ;
F_9 ( V_1 , 0x00 , 0x0038 ) ;
break;
case V_43 :
case V_51 :
F_9 ( V_1 , 0x03 , 0x003b ) ;
F_9 ( V_1 , 0x0c , 0x003a ) ;
F_9 ( V_1 , 0x0b , 0x0039 ) ;
if ( V_24 -> V_55 == V_43 )
F_9 ( V_1 , 0x50 , V_245 ) ;
break;
}
F_14 ( V_1 ) ;
switch ( V_24 -> V_55 ) {
case V_36 :
case V_48 :
F_5 ( V_1 , 0x0008 ) ;
F_9 ( V_1 , 0x00 , 0x0008 ) ;
break;
case V_51 :
case V_40 :
case V_43 :
case V_54 :
F_5 ( V_1 , 0x0008 ) ;
case V_53 :
F_9 ( V_1 , 0x03 , 0x0008 ) ;
break;
}
F_16 ( V_1 ) ;
switch ( V_24 -> V_55 ) {
case V_38 :
case V_41 :
case V_49 :
break;
default:
F_17 ( V_1 ) ;
break;
}
F_14 ( V_1 ) ;
switch ( V_24 -> V_55 ) {
case V_48 :
case V_51 :
F_5 ( V_1 , 0x0180 ) ;
F_9 ( V_1 , 0x00 , 0x0180 ) ;
break;
default:
F_20 ( V_1 ) ;
break;
}
F_21 ( V_1 ) ;
switch ( V_24 -> V_55 ) {
case V_36 :
F_9 ( V_1 , 0x09 , 0x01ad ) ;
F_9 ( V_1 , 0x15 , 0x01ae ) ;
F_9 ( V_1 , 0x02 , 0x0180 ) ;
F_9 ( V_1 , 0x40 , 0x0117 ) ;
break;
case V_43 :
if ( ! V_24 -> V_58 [ V_169 ] . V_22 )
F_19 ( V_1 ) ;
F_9 ( V_1 , 0x00 , V_246 ) ;
break;
case V_40 :
case V_54 :
F_9 ( V_1 , 0x09 , 0x01ad ) ;
F_9 ( V_1 , 0x15 , 0x01ae ) ;
case V_51 :
case V_53 :
F_5 ( V_1 , 0x0180 ) ;
break;
case V_48 :
F_9 ( V_1 , 0x09 , 0x01ad ) ;
F_9 ( V_1 , 0x15 , 0x01ae ) ;
F_10 ( V_1 , 0x13 ) ;
F_12 ( V_1 , 0x13 , 0xa3 , 0x00 ) ;
F_9 ( V_1 , 0x40 , 0x0117 ) ;
F_5 ( V_1 , 0x0180 ) ;
break;
}
F_22 ( V_1 ) ;
switch ( V_24 -> V_55 ) {
case V_53 :
F_11 ( 50 ) ;
F_9 ( V_1 , 0x00 , 0x0007 ) ;
F_9 ( V_1 , 0x02 , V_247 ) ;
break;
}
return V_1 -> V_4 ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
if ( ! V_1 -> V_248 )
return;
F_23 ( V_1 , V_24 -> V_55 ) ;
}
static void F_37 ( struct V_1 * V_1 ,
T_1 * V_249 ,
int V_250 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
if ( V_250 >= 3
&& V_249 [ V_250 - 3 ] == 0xff && V_249 [ V_250 - 2 ] == 0xd9 ) {
F_38 ( V_1 , V_251 ,
V_249 , V_250 - 1 ) ;
return;
}
if ( V_249 [ 0 ] == 0xff && V_249 [ 1 ] == 0xd8 ) {
F_38 ( V_1 , V_252 ,
V_24 -> V_241 , V_253 ) ;
V_249 += 18 ;
V_250 -= 18 ;
}
F_38 ( V_1 , V_254 , V_249 , V_250 ) ;
}
static int F_39 ( struct V_1 * V_1 , T_3 V_22 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
V_24 -> V_58 [ V_169 ] . V_22 = V_22 ;
if ( V_22 ) {
V_1 -> V_201 |= ( 1 << V_73 ) ;
} else {
V_1 -> V_201 &= ~ ( 1 << V_73 ) ;
if ( V_1 -> V_255 )
F_18 ( V_1 ) ;
}
if ( V_1 -> V_255 )
F_22 ( V_1 ) ;
return V_1 -> V_4 ;
}
static int F_40 ( struct V_1 * V_1 ,
struct V_256 * V_257 )
{
switch ( V_257 -> V_179 ) {
case V_258 :
switch ( V_257 -> V_2 ) {
case 0 :
strcpy ( ( char * ) V_257 -> V_259 , L_42 ) ;
return 0 ;
case 1 :
strcpy ( ( char * ) V_257 -> V_259 , L_43 ) ;
return 0 ;
case 2 :
strcpy ( ( char * ) V_257 -> V_259 , L_44 ) ;
return 0 ;
}
break;
}
return - V_194 ;
}
static int F_41 ( struct V_1 * V_1 ,
struct V_260 * V_261 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
if ( V_261 -> V_185 < V_262 )
V_24 -> V_185 = V_262 ;
else if ( V_261 -> V_185 > V_263 )
V_24 -> V_185 = V_263 ;
else
V_24 -> V_185 = V_261 -> V_185 ;
if ( V_1 -> V_255 )
F_35 ( V_24 -> V_241 , V_24 -> V_185 ) ;
return V_1 -> V_4 ;
}
static int F_42 ( struct V_1 * V_1 ,
struct V_260 * V_261 )
{
struct V_24 * V_24 = (struct V_24 * ) V_1 ;
memset ( V_261 , 0 , sizeof *V_261 ) ;
V_261 -> V_185 = V_24 -> V_185 ;
V_261 -> V_264 = V_265
| V_266 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 ,
T_1 * V_249 ,
int V_250 )
{
if ( V_250 == 8 && V_249 [ 4 ] == 1 ) {
F_44 ( V_1 -> V_267 , V_268 , 1 ) ;
F_45 ( V_1 -> V_267 ) ;
F_44 ( V_1 -> V_267 , V_268 , 0 ) ;
F_45 ( V_1 -> V_267 ) ;
}
return 0 ;
}
static int F_46 ( struct V_269 * V_270 ,
const struct V_178 * V_179 )
{
return F_47 ( V_270 , V_179 , & V_271 , sizeof( struct V_24 ) ,
V_272 ) ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_273 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_273 ) ;
}
