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
static void F_5 ( struct V_1 * V_1 ,
T_1 V_10 ,
T_2 V_2 )
{
int V_3 ;
if ( V_1 -> V_4 < 0 )
return;
V_3 = F_2 ( V_1 -> V_5 ,
F_6 ( V_1 -> V_5 , 0 ) ,
0xa0 ,
V_11 | V_7 | V_8 ,
V_10 , V_2 , NULL , 0 ,
500 ) ;
if ( V_3 < 0 ) {
F_4 ( L_2 , V_3 ) ;
V_1 -> V_4 = V_3 ;
}
}
static T_2 F_7 ( struct V_1 * V_1 ,
T_1 V_12 )
{
T_1 V_13 ;
T_2 V_14 ;
if ( V_1 -> V_4 < 0 )
return 0 ;
F_5 ( V_1 , V_12 , 0x0092 ) ;
F_5 ( V_1 , 0x02 , 0x0090 ) ;
F_8 ( 20 ) ;
V_13 = F_1 ( V_1 , 0x0091 ) ;
if ( V_13 != 0x00 )
F_4 ( L_3 , V_13 ) ;
V_14 = F_1 ( V_1 , 0x0095 ) ;
V_14 |= F_1 ( V_1 , 0x0096 ) << 8 ;
return V_14 ;
}
static T_1 F_9 ( struct V_1 * V_1 ,
T_1 V_12 ,
T_1 V_15 ,
T_1 V_16 )
{
T_1 V_13 ;
if ( V_1 -> V_4 < 0 )
return 0 ;
F_5 ( V_1 , V_12 , 0x92 ) ;
F_5 ( V_1 , V_15 , 0x93 ) ;
F_5 ( V_1 , V_16 , 0x94 ) ;
F_5 ( V_1 , 0x01 , 0x90 ) ;
F_8 ( 1 ) ;
V_13 = F_1 ( V_1 , 0x0091 ) ;
if ( V_13 != 0x00 )
F_4 ( L_4 , V_13 ) ;
return V_13 ;
}
static void F_10 ( struct V_1 * V_1 ,
const struct V_17 * V_18 )
{
while ( V_18 -> V_19 ) {
switch ( V_18 -> V_19 ) {
case 0xa0 :
F_5 ( V_1 , V_18 -> V_20 , V_18 -> V_21 ) ;
break;
case 0xa1 :
F_1 ( V_1 , V_18 -> V_21 ) ;
break;
case 0xaa :
F_9 ( V_1 ,
V_18 -> V_20 ,
V_18 -> V_21 & 0xff ,
V_18 -> V_21 >> 8 ) ;
break;
case 0xbb :
F_9 ( V_1 ,
V_18 -> V_21 >> 8 ,
V_18 -> V_21 & 0xff ,
V_18 -> V_20 ) ;
break;
default:
F_8 ( V_18 -> V_21 ) ;
break;
}
V_18 ++ ;
F_8 ( 1 ) ;
}
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
int V_23 ;
const T_1 * V_24 ;
static const T_1 V_25 [ 9 ] =
{ 0x74 , 0xed , 0xed , 0xed , 0x74 , 0xed , 0xed , 0xed , 0x74 } ;
static const T_1 V_26 [ 9 ] =
{ 0x50 , 0xf8 , 0xf8 , 0xf8 , 0x50 , 0xf8 , 0xf8 , 0xf8 , 0x50 } ;
static const T_1 V_27 [ 9 ] =
{ 0x58 , 0xf4 , 0xf4 , 0xf4 , 0x58 , 0xf4 , 0xf4 , 0xf4 , 0x58 } ;
static const T_1 V_28 [ 9 ] =
{ 0x4c , 0xf5 , 0xff , 0xf9 , 0x51 , 0xf5 , 0xfb , 0xed , 0x5f } ;
static const T_1 V_29 [ 9 ] =
{ 0x60 , 0xf0 , 0xf0 , 0xf0 , 0x60 , 0xf0 , 0xf0 , 0xf0 , 0x60 } ;
static const T_1 V_30 [ 9 ] =
{ 0x68 , 0xec , 0xec , 0xec , 0x68 , 0xec , 0xec , 0xec , 0x68 } ;
static const T_1 V_31 [ 9 ] =
{ 0x6c , 0xea , 0xea , 0xea , 0x6c , 0xea , 0xea , 0xea , 0x6c } ;
static const T_1 * V_32 [ V_33 ] = {
[ V_34 ] = V_25 ,
[ V_35 ] = V_27 ,
[ V_36 ] = NULL ,
[ V_37 ] = V_31 ,
[ V_38 ] = V_26 ,
[ V_39 ] = NULL ,
[ V_40 ] = NULL ,
[ V_41 ] = V_29 ,
[ V_42 ] = V_29 ,
[ V_43 ] = NULL ,
[ V_44 ] = V_26 ,
[ V_45 ] = V_26 ,
[ V_46 ] = V_27 ,
[ V_47 ] = NULL ,
[ V_48 ] = NULL ,
[ V_49 ] = V_28 ,
[ V_50 ] = V_26 ,
[ V_51 ] = V_29 ,
[ V_52 ] = V_30 ,
} ;
V_24 = V_32 [ V_22 -> V_53 ] ;
if ( V_24 == NULL )
return;
for ( V_23 = 0 ; V_23 < F_12 ( V_27 ) ; V_23 ++ )
F_5 ( V_1 , V_24 [ V_23 ] , 0x010a + V_23 ) ;
}
static void F_13 ( struct V_1 * V_1 , T_3 V_20 )
{
static const T_1 V_54 [] [ 2 ] = {
{ 0x02 , 0x03 } ,
{ 0x04 , 0x07 } ,
{ 0x08 , 0x0f } ,
{ 0x10 , 0x1e }
} ;
F_5 ( V_1 , V_54 [ V_20 ] [ 0 ] , 0x01c6 ) ;
F_1 ( V_1 , 0x01c8 ) ;
F_1 ( V_1 , 0x01c9 ) ;
F_1 ( V_1 , 0x01ca ) ;
F_5 ( V_1 , V_54 [ V_20 ] [ 1 ] , 0x01cb ) ;
}
static void F_14 ( struct V_1 * V_1 ,
T_3 gamma , T_3 V_55 , T_3 V_56 )
{
const T_1 * V_57 ;
int V_58 , V_23 , V_59 , V_60 , V_61 ;
T_1 V_62 [ 16 ] ;
static const T_1 V_63 [ 16 ] =
{ 0x50 , 0x38 , 0x2d , 0x28 , 0x24 , 0x21 , 0x1e , 0x1d ,
0x1d , 0x1b , 0x1b , 0x1b , 0x19 , 0x18 , 0x18 , 0x18 } ;
static const T_1 V_64 [ 16 ] =
{ 0x2c , 0x1a , 0x12 , 0x0c , 0x0a , 0x06 , 0x06 , 0x06 ,
0x04 , 0x06 , 0x04 , 0x04 , 0x03 , 0x03 , 0x02 , 0x02 } ;
static const T_1 V_65 [ 6 ] [ 16 ] = {
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
V_57 = V_65 [ gamma - 1 ] ;
V_56 -= 128 ;
V_55 -= 128 ;
V_59 = 0 ;
V_60 = V_61 = 0 ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ ) {
V_58 = V_57 [ V_23 ] + V_63 [ V_23 ] * V_55 / 256
- V_64 [ V_23 ] * V_56 / 256 - V_59 / 2 ;
if ( V_58 > 0xff )
V_58 = 0xff ;
else if ( V_58 < 0 )
V_58 = 0 ;
F_5 ( V_1 , V_58 , 0x0120 + V_23 ) ;
if ( V_56 > 0 )
V_59 -- ;
else if ( V_56 < 0 )
V_59 ++ ;
if ( V_23 > 1 )
V_62 [ V_23 - 1 ] = ( V_58 - V_61 ) / 2 ;
else if ( V_23 != 0 )
V_62 [ 0 ] = V_60 == 0 ? 0 : ( V_58 - V_60 ) ;
V_61 = V_60 ;
V_60 = V_58 ;
}
V_62 [ 15 ] = ( 0xff - V_61 ) / 2 ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ )
F_5 ( V_1 , V_62 [ V_23 ] , 0x0130 + V_23 ) ;
}
static T_3 F_15 ( struct V_1 * V_1 )
{
return ( F_7 ( V_1 , 0x25 ) << 9 )
| ( F_7 ( V_1 , 0x26 ) << 1 )
| ( F_7 ( V_1 , 0x27 ) >> 7 ) ;
}
static void F_16 ( struct V_1 * V_1 , T_3 V_20 )
{
F_9 ( V_1 , 0x25 , V_20 >> 9 , 0x00 ) ;
F_9 ( V_1 , 0x26 , V_20 >> 1 , 0x00 ) ;
F_9 ( V_1 , 0x27 , V_20 << 7 , 0x00 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
F_18 ( V_22 -> V_66 , V_67 [ V_22 -> V_68 >> 1 ] ) ;
F_5 ( V_1 , V_22 -> V_68 , V_69 ) ;
}
static void F_19 ( struct V_1 * V_1 , T_3 V_20 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
int V_23 , V_70 ;
const struct V_17 * V_71 ;
static const struct V_17 * V_72 [ V_33 ] [ 6 ] = {
[ V_34 ] =
{ V_73 , V_73 ,
V_74 , V_74 ,
V_75 , V_75 } ,
[ V_35 ] =
{ V_76 , V_77 ,
V_78 , V_79 ,
V_80 , V_81 } ,
[ V_36 ] =
{ V_76 , V_77 ,
NULL , NULL ,
NULL , NULL } ,
[ V_37 ] =
{ V_82 , V_83 ,
V_84 , V_85 ,
V_86 , V_87 } ,
[ V_38 ] =
{ V_88 , V_88 ,
V_89 , V_89 ,
V_90 , V_90 } ,
[ V_39 ] =
{ V_91 , V_91 ,
V_92 , V_92 ,
V_93 , V_93 } ,
[ V_40 ] =
{ V_94 , V_95 ,
V_96 , V_97 ,
V_98 , V_99 } ,
[ V_41 ] =
{ V_100 , V_101 ,
V_102 , V_103 ,
V_104 , V_105 } ,
[ V_42 ] =
{ V_106 , V_107 ,
V_108 , V_109 ,
V_110 , V_111 } ,
[ V_43 ] =
{ V_112 , V_113 ,
V_114 , V_115 ,
V_116 , V_117 } ,
[ V_44 ] =
{ V_118 , V_119 ,
V_120 , V_121 ,
V_122 , V_123 } ,
[ V_45 ] =
{ V_124 , V_125 ,
V_126 , V_127 ,
V_128 , V_129 } ,
[ V_46 ] =
{ V_130 , V_130 ,
V_131 , V_131 ,
V_132 , V_132 } ,
[ V_47 ] =
{ NULL , NULL ,
NULL , NULL ,
NULL , NULL } ,
[ V_48 ] =
{ V_133 , V_133 ,
V_134 , V_134 ,
V_135 , V_135 } ,
[ V_49 ] =
{ V_136 , V_137 ,
V_138 , V_139 ,
V_140 , V_141 } ,
[ V_50 ] =
{ V_142 , V_143 ,
V_144 , V_145 ,
V_146 , V_147 } ,
[ V_51 ] =
{ V_148 , V_148 ,
V_149 , V_149 ,
V_150 , V_150 } ,
[ V_52 ] =
{ V_151 , V_152 ,
V_153 , V_154 ,
V_155 , V_156 } ,
} ;
V_23 = V_20 * 2 ;
V_70 = V_1 -> V_157 . V_158 [ V_1 -> V_159 ] . V_160 ;
if ( V_70 )
V_23 ++ ;
V_71 = V_72 [ V_22 -> V_53 ] [ V_23 ] ;
if ( V_71 == NULL )
return;
F_10 ( V_1 , V_71 ) ;
switch ( V_22 -> V_53 ) {
case V_38 :
if ( V_70
&& V_20 == 1 )
F_5 ( V_1 , 0x85 , 0x018d ) ;
break;
case V_46 :
if ( ! V_70 ) {
if ( V_20 != 0 )
F_5 ( V_1 , 0x40 , 0x0002 ) ;
else
F_5 ( V_1 , 0x44 , 0x0002 ) ;
}
break;
case V_49 :
F_5 ( V_1 , 0x00 , 0x01a7 ) ;
break;
}
}
static void F_20 ( struct V_1 * V_1 , T_3 V_20 )
{
F_5 ( V_1 , V_20 ? 0x42 : 0x02 , 0x0180 ) ;
}
static void F_21 ( struct V_161 * V_162 )
{
struct V_22 * V_22 = F_22 ( V_162 , struct V_22 , V_162 ) ;
struct V_1 * V_1 = & V_22 -> V_1 ;
int V_163 , V_164 ;
T_1 V_165 , V_166 ;
V_165 = 0 ;
V_164 = 0 ;
for (; ; ) {
F_8 ( 100 ) ;
F_23 ( & V_1 -> V_167 ) ;
#ifdef F_24
if ( V_1 -> V_168 )
goto V_169;
#endif
if ( ! V_1 -> V_170 || ! V_1 -> V_171 )
goto V_169;
V_1 -> V_4 = 0 ;
V_166 = F_1 ( V_1 , 0x0011 ) ;
if ( V_1 -> V_4 )
goto V_169;
V_163 = V_166 & 0x01 ;
if ( V_163 ) {
V_164 = 0 ;
if ( V_165 == 0 )
V_165 = 0x32 ;
else if ( V_165 > 2 )
V_165 -= 2 ;
else
V_163 = 0 ;
} else {
V_164 ++ ;
if ( V_164 >= 10 ) {
V_164 = 0 ;
if ( V_165 ) {
V_163 = 1 ;
if ( V_165 < 0x32 )
V_165 += 2 ;
else
V_165 = 0 ;
}
}
}
if ( V_163 ) {
V_1 -> V_4 = 0 ;
F_5 ( V_1 , V_165 , 0x0007 ) ;
if ( V_1 -> V_4 )
goto V_169;
}
F_25 ( & V_1 -> V_167 ) ;
}
return;
V_169:
F_25 ( & V_1 -> V_167 ) ;
}
static void F_26 ( struct V_1 * V_1 , int V_53 )
{
F_5 ( V_1 , 0x01 , 0x0000 ) ;
switch ( V_53 ) {
case V_48 :
F_5 ( V_1 , 0x03 , 0x003a ) ;
F_5 ( V_1 , 0x0c , 0x003b ) ;
F_5 ( V_1 , 0x08 , 0x0038 ) ;
break;
case V_34 :
case V_38 :
case V_46 :
case V_44 :
case V_45 :
case V_50 :
case V_51 :
F_5 ( V_1 , 0x0d , 0x003a ) ;
F_5 ( V_1 , 0x02 , 0x003b ) ;
F_5 ( V_1 , 0x00 , 0x0038 ) ;
break;
case V_41 :
case V_49 :
F_5 ( V_1 , 0x03 , 0x003b ) ;
F_5 ( V_1 , 0x0c , 0x003a ) ;
F_5 ( V_1 , 0x0b , 0x0039 ) ;
if ( V_53 == V_49 )
F_5 ( V_1 , 0x0b , 0x0038 ) ;
break;
}
}
static void F_27 ( struct V_1 * V_1 , int V_53 )
{
F_5 ( V_1 , 0x01 , 0x0000 ) ;
F_5 ( V_1 , V_53 , 0x0010 ) ;
F_5 ( V_1 , 0x01 , 0x0001 ) ;
F_5 ( V_1 , 0x03 , 0x0012 ) ;
F_5 ( V_1 , 0x01 , 0x0012 ) ;
}
static int F_28 ( struct V_1 * V_1 )
{
T_2 V_172 ;
F_27 ( V_1 , 0x0f ) ;
F_5 ( V_1 , 0x08 , 0x008d ) ;
F_8 ( 150 ) ;
V_172 = ( ( F_7 ( V_1 , 0x00 ) & 0x0f ) << 4 )
| ( ( F_7 ( V_1 , 0x01 ) & 0xf0 ) >> 4 ) ;
F_29 ( V_173 , L_5 , V_172 ) ;
if ( V_172 == 0x0007 ) {
F_26 ( V_1 , V_48 ) ;
return 0x0f ;
}
return - 1 ;
}
static int F_30 ( struct V_1 * V_1 )
{
T_2 V_174 ;
F_27 ( V_1 , 0x00 ) ;
F_9 ( V_1 , 0x01 , 0xaa , 0x00 ) ;
V_174 = F_7 ( V_1 , 0x01 ) ;
if ( V_174 != 0 )
return 0x00 ;
F_27 ( V_1 , 0x04 ) ;
F_9 ( V_1 , 0x01 , 0xaa , 0x00 ) ;
V_174 = F_7 ( V_1 , 0x01 ) ;
if ( V_174 != 0 )
return 0x04 ;
F_27 ( V_1 , 0x06 ) ;
F_5 ( V_1 , 0x08 , 0x008d ) ;
F_9 ( V_1 , 0x11 , 0xaa , 0x00 ) ;
V_174 = F_7 ( V_1 , 0x11 ) ;
if ( V_174 != 0 ) {
goto V_175;
}
F_27 ( V_1 , 0x08 ) ;
F_9 ( V_1 , 0x1c , 0x00 , 0x00 ) ;
F_9 ( V_1 , 0x15 , 0xaa , 0x00 ) ;
V_174 = F_7 ( V_1 , 0x15 ) ;
if ( V_174 != 0 )
return 0x08 ;
F_27 ( V_1 , 0x0a ) ;
F_9 ( V_1 , 0x07 , 0xaa , 0xaa ) ;
V_174 = F_7 ( V_1 , 0x07 ) ;
if ( V_174 != 0 )
return 0x0a ;
V_174 = F_7 ( V_1 , 0x03 ) ;
if ( V_174 != 0 )
return 0x0a ;
V_174 = F_7 ( V_1 , 0x04 ) ;
if ( V_174 != 0 )
return 0x0a ;
F_27 ( V_1 , 0x0c ) ;
F_9 ( V_1 , 0x01 , 0x11 , 0x00 ) ;
V_174 = F_7 ( V_1 , 0x01 ) ;
if ( V_174 != 0 )
return 0x0c ;
F_27 ( V_1 , 0x0e ) ;
F_5 ( V_1 , 0x08 , 0x008d ) ;
F_9 ( V_1 , 0x03 , 0xaa , 0x00 ) ;
F_8 ( 50 ) ;
V_174 = F_7 ( V_1 , 0x03 ) ;
if ( V_174 != 0 ) {
F_26 ( V_1 , V_49 ) ;
return 0x0e ;
}
F_27 ( V_1 , 0x02 ) ;
F_9 ( V_1 , 0x01 , 0xaa , 0x00 ) ;
V_174 = F_7 ( V_1 , 0x01 ) ;
if ( V_174 != 0 )
return 0x02 ;
V_175:
F_1 ( V_1 , 0x0010 ) ;
F_1 ( V_1 , 0x0010 ) ;
F_5 ( V_1 , 0x01 , 0x0000 ) ;
F_5 ( V_1 , 0x01 , 0x0001 ) ;
F_5 ( V_1 , 0x06 , 0x0010 ) ;
F_5 ( V_1 , 0xa1 , 0x008b ) ;
F_5 ( V_1 , 0x08 , 0x008d ) ;
F_8 ( 500 ) ;
F_5 ( V_1 , 0x01 , 0x0012 ) ;
F_9 ( V_1 , 0x12 , 0x80 , 0x00 ) ;
V_174 = F_7 ( V_1 , 0x0a ) << 8 ;
V_174 |= F_7 ( V_1 , 0x0b ) ;
F_29 ( V_173 , L_6 , V_174 ) ;
switch ( V_174 ) {
case 0x7631 :
F_5 ( V_1 , 0x06 , 0x0010 ) ;
break;
case 0x7620 :
case 0x7648 :
break;
default:
return - 1 ;
}
return V_174 ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
int V_23 ;
T_2 V_174 ;
F_5 ( V_1 , 0x02 , 0x0010 ) ;
F_1 ( V_1 , 0x0010 ) ;
F_5 ( V_1 , 0x01 , 0x0000 ) ;
F_5 ( V_1 , 0x00 , 0x0010 ) ;
F_5 ( V_1 , 0x01 , 0x0001 ) ;
F_5 ( V_1 , 0x91 , 0x008b ) ;
F_5 ( V_1 , 0x03 , 0x0012 ) ;
F_5 ( V_1 , 0x01 , 0x0012 ) ;
F_5 ( V_1 , 0x05 , 0x0012 ) ;
V_174 = F_7 ( V_1 , 0x14 ) ;
if ( V_174 != 0 )
return 0x11 ;
V_174 = F_7 ( V_1 , 0x15 ) ;
if ( V_174 != 0 )
return 0x11 ;
V_174 = F_7 ( V_1 , 0x16 ) ;
if ( V_174 != 0 )
return 0x11 ;
F_5 ( V_1 , 0x02 , 0x0010 ) ;
V_174 = F_1 ( V_1 , 0x000b ) << 8 ;
V_174 |= F_1 ( V_1 , 0x000a ) ;
F_29 ( V_173 , L_7 , V_174 ) ;
F_1 ( V_1 , 0x0010 ) ;
if ( ( V_174 & 0xff00 ) == 0x6400 )
return 0x02 ;
for ( V_23 = 0 ; V_23 < F_12 ( V_176 ) ; V_23 ++ ) {
if ( V_176 [ V_23 ] . V_177 == V_174 ) {
V_22 -> V_178 = V_174 ;
F_26 ( V_1 , V_50 ) ;
return V_176 [ V_23 ] . V_179 ;
}
}
F_5 ( V_1 , 0x01 , 0x0000 ) ;
F_5 ( V_1 , 0x01 , 0x0001 ) ;
F_5 ( V_1 , 0xdd , 0x008b ) ;
F_5 ( V_1 , 0x0a , 0x0010 ) ;
F_5 ( V_1 , 0x03 , 0x0012 ) ;
F_5 ( V_1 , 0x01 , 0x0012 ) ;
V_174 = F_7 ( V_1 , 0x00 ) ;
if ( V_174 != 0 ) {
F_29 ( V_173 , L_8 ) ;
return 0x0a ;
}
F_5 ( V_1 , 0x01 , 0x0000 ) ;
F_5 ( V_1 , 0x01 , 0x0001 ) ;
F_5 ( V_1 , 0x98 , 0x008b ) ;
F_5 ( V_1 , 0x01 , 0x0010 ) ;
F_5 ( V_1 , 0x03 , 0x0012 ) ;
F_8 ( 2 ) ;
F_5 ( V_1 , 0x01 , 0x0012 ) ;
V_174 = F_7 ( V_1 , 0x00 ) ;
if ( V_174 != 0 ) {
F_29 ( V_173 , L_9 , V_174 ) ;
if ( V_174 == 0x0011 )
return 0x0303 ;
if ( V_174 == 0x0029 )
F_26 ( V_1 , V_38 ) ;
return V_174 ;
}
F_5 ( V_1 , 0x01 , 0x0000 ) ;
F_5 ( V_1 , 0x01 , 0x0001 ) ;
F_5 ( V_1 , 0xa1 , 0x008b ) ;
F_5 ( V_1 , 0x08 , 0x008d ) ;
F_5 ( V_1 , 0x06 , 0x0010 ) ;
F_5 ( V_1 , 0x01 , 0x0012 ) ;
F_5 ( V_1 , 0x05 , 0x0012 ) ;
if ( F_7 ( V_1 , 0x1c ) == 0x007f
&& F_7 ( V_1 , 0x1d ) == 0x00a2 ) {
F_26 ( V_1 , V_46 ) ;
return 0x06 ;
}
F_5 ( V_1 , 0x01 , 0x0000 ) ;
F_5 ( V_1 , 0x00 , 0x0002 ) ;
F_5 ( V_1 , 0x01 , 0x0010 ) ;
F_5 ( V_1 , 0x01 , 0x0001 ) ;
F_5 ( V_1 , 0xee , 0x008b ) ;
F_5 ( V_1 , 0x03 , 0x0012 ) ;
F_5 ( V_1 , 0x01 , 0x0012 ) ;
F_5 ( V_1 , 0x05 , 0x0012 ) ;
V_174 = F_7 ( V_1 , 0x00 ) << 8 ;
V_174 |= F_7 ( V_1 , 0x01 ) ;
F_29 ( V_173 , L_10 , V_174 ) ;
if ( V_174 == 0x2030 ) {
T_1 V_13 ;
V_13 = F_7 ( V_1 , 0x02 ) ;
F_29 ( V_173 , L_11 , V_13 ) ;
F_26 ( V_1 , V_51 ) ;
return V_174 ;
}
F_5 ( V_1 , 0x01 , 0x0000 ) ;
F_5 ( V_1 , 0x0a , 0x0010 ) ;
F_5 ( V_1 , 0xd3 , 0x008b ) ;
F_5 ( V_1 , 0x01 , 0x0001 ) ;
F_5 ( V_1 , 0x03 , 0x0012 ) ;
F_5 ( V_1 , 0x01 , 0x0012 ) ;
F_5 ( V_1 , 0x05 , 0x0012 ) ;
F_5 ( V_1 , 0xd3 , 0x008b ) ;
V_174 = F_7 ( V_1 , 0x01 ) ;
if ( V_174 != 0 ) {
F_29 ( V_173 , L_12 , V_174 ) ;
return 0x16 ;
}
return - 1 ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
int V_53 ;
switch ( V_22 -> V_53 ) {
case V_43 :
return - 1 ;
case V_37 :
return - 1 ;
case V_48 :
V_53 = F_28 ( V_1 ) ;
if ( V_53 >= 0 )
return V_53 ;
break;
}
V_53 = F_30 ( V_1 ) ;
if ( V_53 >= 0 )
return V_53 ;
return F_31 ( V_1 ) ;
}
static int F_33 ( struct V_1 * V_1 ,
const struct V_180 * V_181 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( V_181 -> V_182 == 0x301b )
V_22 -> V_183 = V_184 ;
else
V_22 -> V_183 = V_185 ;
V_22 -> V_53 = V_181 -> V_186 ;
V_22 -> V_68 = V_187 ;
F_34 ( & V_22 -> V_162 , F_21 ) ;
return 0 ;
}
static int F_35 ( struct V_188 * V_189 )
{
struct V_1 * V_1 =
F_22 ( V_189 -> V_190 , struct V_1 , V_191 ) ;
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
switch ( V_189 -> V_181 ) {
case V_192 :
V_1 -> V_4 = 0 ;
if ( V_189 -> V_20 && V_22 -> V_193 && V_1 -> V_171 )
V_22 -> V_193 -> V_20 = F_15 ( V_1 ) ;
return V_1 -> V_4 ;
}
return - V_194 ;
}
static int F_36 ( struct V_188 * V_189 )
{
struct V_1 * V_1 =
F_22 ( V_189 -> V_190 , struct V_1 , V_191 ) ;
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
int V_23 , V_195 ;
V_1 -> V_4 = 0 ;
if ( V_189 -> V_181 == V_196 ) {
V_195 = V_22 -> V_68 >> 1 ;
for ( V_23 = 0 ; V_23 < F_12 ( V_67 ) ; V_23 ++ ) {
if ( V_189 -> V_20 <= V_67 [ V_23 ] )
break;
}
if ( V_23 > 0 && V_23 == V_195 && V_189 -> V_20 < V_67 [ V_23 ] )
V_23 -- ;
if ( V_23 >= 2 && V_1 -> V_171 &&
! V_1 -> V_157 . V_197 )
return - V_198 ;
V_22 -> V_68 = ( V_23 << 1 ) | 1 ;
V_189 -> V_20 = V_67 [ V_23 ] ;
}
if ( ! V_1 -> V_171 )
return 0 ;
switch ( V_189 -> V_181 ) {
case V_199 :
F_14 ( V_1 , V_22 -> gamma -> V_20 ,
V_22 -> V_55 -> V_20 , V_22 -> V_56 -> V_20 ) ;
break;
case V_192 :
F_20 ( V_1 , V_189 -> V_20 ) ;
if ( ! V_1 -> V_4 && ! V_189 -> V_20 && V_22 -> V_193 )
F_16 ( V_1 , V_22 -> V_193 -> V_20 ) ;
break;
case V_200 :
F_19 ( V_1 , V_189 -> V_20 ) ;
break;
case V_201 :
F_13 ( V_1 , V_189 -> V_20 ) ;
break;
case V_196 :
F_17 ( V_1 ) ;
break;
}
return V_1 -> V_4 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
struct V_202 * V_203 = & V_1 -> V_191 ;
static const T_1 gamma [ V_33 ] = {
[ V_34 ] = 4 ,
[ V_35 ] = 4 ,
[ V_36 ] = 5 ,
[ V_37 ] = 3 ,
[ V_38 ] = 4 ,
[ V_39 ] = 4 ,
[ V_40 ] = 4 ,
[ V_41 ] = 4 ,
[ V_42 ] = 4 ,
[ V_43 ] = 4 ,
[ V_44 ] = 4 ,
[ V_45 ] = 4 ,
[ V_46 ] = 3 ,
[ V_47 ] = 4 ,
[ V_48 ] = 4 ,
[ V_49 ] = 4 ,
[ V_50 ] = 4 ,
[ V_51 ] = 4 ,
[ V_52 ] = 3 ,
} ;
V_1 -> V_204 . V_191 = V_203 ;
F_38 ( V_203 , 8 ) ;
V_22 -> V_55 = F_39 ( V_203 , & V_205 ,
V_206 , 0 , 255 , 1 , 128 ) ;
V_22 -> V_56 = F_39 ( V_203 , & V_205 ,
V_207 , 0 , 255 , 1 , 128 ) ;
V_22 -> gamma = F_39 ( V_203 , & V_205 ,
V_199 , 1 , 6 , 1 , gamma [ V_22 -> V_53 ] ) ;
if ( V_22 -> V_53 == V_41 )
V_22 -> V_193 = F_39 ( V_203 , & V_205 ,
V_208 , 0x30d , 0x493e , 1 , 0x927 ) ;
V_22 -> V_209 = F_39 ( V_203 , & V_205 ,
V_192 , 0 , 1 , 1 , 1 ) ;
if ( V_22 -> V_53 != V_47 )
V_22 -> V_210 = F_40 ( V_203 , & V_205 ,
V_200 ,
V_211 , 0 ,
V_212 ) ;
V_22 -> V_213 = F_39 ( V_203 , & V_205 ,
V_201 , 0 , 3 , 1 ,
V_22 -> V_53 == V_51 ? 0 : 2 ) ;
V_22 -> V_214 = F_39 ( V_203 , & V_205 ,
V_196 ,
V_67 [ 0 ] , V_67 [ F_12 ( V_67 ) - 1 ] , 1 ,
V_67 [ V_187 >> 1 ] ) ;
if ( V_203 -> error ) {
F_4 ( L_13 ) ;
return V_203 -> error ;
}
F_41 ( 3 , & V_22 -> gamma ) ;
if ( V_22 -> V_53 == V_41 )
F_42 ( 2 , & V_22 -> V_209 , 0 , true ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
struct V_157 * V_157 ;
int V_53 ;
static const T_1 V_215 [ V_33 ] = {
[ V_34 ] = 2 ,
[ V_35 ] = 1 ,
[ V_36 ] = 1 ,
[ V_37 ] = 1 ,
[ V_38 ] = 1 ,
[ V_39 ] = 1 ,
[ V_40 ] = 1 ,
[ V_41 ] = 1 ,
[ V_42 ] = 1 ,
[ V_43 ] = 2 ,
[ V_44 ] = 1 ,
[ V_45 ] = 1 ,
[ V_46 ] = 2 ,
[ V_47 ] = 1 ,
[ V_48 ] = 0 ,
[ V_49 ] = 1 ,
[ V_50 ] = 1 ,
[ V_51 ] = 1 ,
[ V_52 ] = 1 ,
} ;
V_53 = F_32 ( V_1 ) ;
if ( V_53 >= 0 )
F_29 ( V_173 , L_14 , V_53 ) ;
if ( ( unsigned ) V_216 < V_33 ) {
V_22 -> V_53 = V_216 ;
F_29 ( V_173 , L_15 , V_216 ) ;
} else {
switch ( V_53 ) {
case - 1 :
switch ( V_22 -> V_53 ) {
case V_43 :
F_29 ( V_173 , L_16 ) ;
break;
case V_37 :
F_29 ( V_173 , L_17 ) ;
break;
default:
F_44 ( L_18 ) ;
V_22 -> V_53 = V_52 ;
}
break;
case 0 :
V_53 = F_7 ( V_1 , 0x00 ) ;
F_29 ( V_173 , L_19 , V_53 ) ;
switch ( V_53 ) {
case 0 :
case 1 :
F_29 ( V_173 , L_20 ) ;
V_22 -> V_53 = V_40 ;
break;
default:
F_29 ( V_173 , L_21 ) ;
V_22 -> V_53 = V_41 ;
break;
}
break;
case 0x02 :
F_29 ( V_173 , L_22 ) ;
V_22 -> V_53 = V_52 ;
break;
case 0x04 :
F_29 ( V_173 , L_23 ) ;
V_22 -> V_53 = V_35 ;
break;
case 0x08 :
F_29 ( V_173 , L_24 ) ;
V_22 -> V_53 = V_39 ;
break;
case 0x0a :
F_29 ( V_173 ,
L_25 ,
V_22 -> V_178 ) ;
V_22 -> V_53 = V_50 ;
break;
case 0x0c :
F_29 ( V_173 , L_26 ) ;
V_22 -> V_53 = V_42 ;
break;
case 0x0e :
F_29 ( V_173 , L_27 ) ;
V_22 -> V_53 = V_49 ;
break;
case 0x0f :
F_29 ( V_173 , L_28 ) ;
V_22 -> V_53 = V_48 ;
break;
case 0x10 :
case 0x12 :
F_29 ( V_173 , L_29 ) ;
V_22 -> V_53 = V_52 ;
break;
case 0x11 :
F_29 ( V_173 , L_21 ) ;
V_22 -> V_53 = V_41 ;
break;
case 0x13 :
case 0x15 :
F_29 ( V_173 ,
L_30 ,
V_22 -> V_178 ) ;
V_22 -> V_53 = V_22 -> V_183 == V_184
? V_44
: V_45 ;
break;
case 0x14 :
F_29 ( V_173 ,
L_31 ,
V_22 -> V_178 ) ;
V_22 -> V_53 = V_36 ;
break;
case 0x16 :
F_29 ( V_173 , L_32 ) ;
V_22 -> V_53 = V_34 ;
break;
case 0x29 :
F_29 ( V_173 , L_33 ) ;
V_22 -> V_53 = V_38 ;
break;
case 0x0303 :
F_29 ( V_173 , L_17 ) ;
V_22 -> V_53 = V_37 ;
break;
case 0x2030 :
F_29 ( V_173 , L_34 ) ;
V_22 -> V_53 = V_51 ;
break;
case 0x7620 :
F_29 ( V_173 , L_35 ) ;
V_22 -> V_53 = V_46 ;
break;
case 0x7631 :
F_29 ( V_173 , L_36 ) ;
V_22 -> V_53 = V_47 ;
break;
case 0x7648 :
F_29 ( V_173 , L_37 ) ;
V_22 -> V_53 = V_46 ;
break;
default:
F_4 ( L_38 , V_53 ) ;
return - V_194 ;
}
}
if ( V_53 < 0x20 ) {
if ( V_53 == - 1 || V_53 == 0x10 || V_53 == 0x12 )
F_5 ( V_1 , 0x02 , 0x0010 ) ;
F_1 ( V_1 , 0x0010 ) ;
}
V_157 = & V_1 -> V_157 ;
switch ( V_215 [ V_22 -> V_53 ] ) {
case 0 :
V_157 -> V_158 = V_217 ;
V_157 -> V_218 = F_12 ( V_217 ) ;
break;
case 1 :
V_157 -> V_158 = V_219 ;
V_157 -> V_218 = F_12 ( V_219 ) ;
break;
default:
V_157 -> V_158 = V_220 ;
V_157 -> V_218 = F_12 ( V_220 ) ;
break;
}
F_5 ( V_1 , 0x01 , 0x0000 ) ;
return V_1 -> V_4 ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_1 -> V_157 . V_197 = ( V_22 -> V_68 >= 4 ) ? 1 : 0 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
int V_70 ;
static const struct V_17 * V_221 [ V_33 ] [ 2 ] = {
[ V_34 ] =
{ V_222 , V_223 } ,
[ V_35 ] =
{ V_224 , V_225 } ,
[ V_36 ] =
{ V_226 , V_227 } ,
[ V_37 ] =
{ V_228 , V_229 } ,
[ V_38 ] =
{ V_230 , V_231 } ,
[ V_39 ] =
{ V_232 , V_233 } ,
[ V_40 ] =
{ V_234 , V_235 } ,
[ V_41 ] =
{ V_236 , V_237 } ,
[ V_42 ] =
{ V_238 , V_239 } ,
[ V_43 ] =
{ V_240 , V_241 } ,
[ V_44 ] =
{ V_242 , V_243 } ,
[ V_45 ] =
{ V_244 , V_245 } ,
[ V_46 ] =
{ V_246 , V_247 } ,
[ V_47 ] =
{ V_248 , V_249 } ,
[ V_48 ] =
{ V_250 , V_251 } ,
[ V_49 ] =
{ V_252 , V_253 } ,
[ V_50 ] =
{ V_254 , V_255 } ,
[ V_51 ] =
{ V_256 , V_257 } ,
[ V_52 ] =
{ V_258 , V_259 } ,
} ;
F_47 ( V_22 -> V_66 , V_1 -> V_260 . V_261 ,
V_1 -> V_260 . V_262 ,
0x21 ) ;
V_70 = V_1 -> V_157 . V_158 [ V_1 -> V_159 ] . V_160 ;
switch ( V_22 -> V_53 ) {
case V_41 :
F_32 ( V_1 ) ;
break;
case V_48 :
F_10 ( V_1 , V_263 ) ;
break;
}
F_10 ( V_1 , V_221 [ V_22 -> V_53 ] [ V_70 ] ) ;
switch ( V_22 -> V_53 ) {
case V_34 :
case V_38 :
case V_46 :
case V_51 :
case V_52 :
case V_37 :
F_1 ( V_1 , 0x0002 ) ;
F_5 ( V_1 , 0x09 , 0x01ad ) ;
F_5 ( V_1 , 0x15 , 0x01ae ) ;
if ( V_22 -> V_53 == V_52 )
break;
F_5 ( V_1 , 0x0d , 0x003a ) ;
F_5 ( V_1 , 0x02 , 0x003b ) ;
F_5 ( V_1 , 0x00 , 0x0038 ) ;
break;
case V_41 :
case V_49 :
F_5 ( V_1 , 0x03 , 0x003b ) ;
F_5 ( V_1 , 0x0c , 0x003a ) ;
F_5 ( V_1 , 0x0b , 0x0039 ) ;
if ( V_22 -> V_53 == V_41 )
F_5 ( V_1 , 0x50 , V_264 ) ;
break;
}
F_11 ( V_1 ) ;
switch ( V_22 -> V_53 ) {
case V_34 :
case V_46 :
F_1 ( V_1 , 0x0008 ) ;
F_5 ( V_1 , 0x00 , 0x0008 ) ;
break;
case V_49 :
case V_38 :
case V_41 :
case V_52 :
F_1 ( V_1 , 0x0008 ) ;
case V_51 :
F_5 ( V_1 , 0x03 , 0x0008 ) ;
break;
}
F_13 ( V_1 , F_48 ( V_22 -> V_213 ) ) ;
switch ( V_22 -> V_53 ) {
case V_36 :
case V_39 :
case V_47 :
break;
default:
F_14 ( V_1 , F_48 ( V_22 -> gamma ) ,
F_48 ( V_22 -> V_55 ) ,
F_48 ( V_22 -> V_56 ) ) ;
break;
}
F_11 ( V_1 ) ;
switch ( V_22 -> V_53 ) {
case V_46 :
case V_49 :
F_1 ( V_1 , 0x0180 ) ;
F_5 ( V_1 , 0x00 , 0x0180 ) ;
break;
}
F_17 ( V_1 ) ;
F_5 ( V_1 , 0x00 , 0x0007 ) ;
if ( V_22 -> V_210 )
F_19 ( V_1 , F_48 ( V_22 -> V_210 ) ) ;
switch ( V_22 -> V_53 ) {
case V_34 :
F_5 ( V_1 , 0x09 , 0x01ad ) ;
F_5 ( V_1 , 0x15 , 0x01ae ) ;
F_5 ( V_1 , 0x02 , 0x0180 ) ;
F_5 ( V_1 , 0x40 , 0x0117 ) ;
break;
case V_41 :
F_16 ( V_1 , F_48 ( V_22 -> V_193 ) ) ;
F_5 ( V_1 , 0x00 , V_265 ) ;
break;
case V_38 :
case V_52 :
F_5 ( V_1 , 0x09 , 0x01ad ) ;
F_5 ( V_1 , 0x15 , 0x01ae ) ;
case V_49 :
case V_51 :
F_1 ( V_1 , 0x0180 ) ;
break;
case V_46 :
F_5 ( V_1 , 0x09 , 0x01ad ) ;
F_5 ( V_1 , 0x15 , 0x01ae ) ;
F_7 ( V_1 , 0x13 ) ;
F_9 ( V_1 , 0x13 , 0xa3 , 0x00 ) ;
F_5 ( V_1 , 0x40 , 0x0117 ) ;
F_1 ( V_1 , 0x0180 ) ;
break;
}
F_20 ( V_1 , F_48 ( V_22 -> V_209 ) ) ;
if ( V_1 -> V_4 < 0 )
return V_1 -> V_4 ;
V_22 -> V_266 = F_49 ( V_267 ) ;
F_50 ( V_22 -> V_266 , & V_22 -> V_162 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( V_22 -> V_266 != NULL ) {
F_25 ( & V_1 -> V_167 ) ;
F_52 ( V_22 -> V_266 ) ;
F_23 ( & V_1 -> V_167 ) ;
V_22 -> V_266 = NULL ;
}
if ( ! V_1 -> V_170 )
return;
F_26 ( V_1 , V_22 -> V_53 ) ;
}
static void F_53 ( struct V_1 * V_1 ,
T_1 * V_268 ,
int V_269 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( V_269 >= 3
&& V_268 [ V_269 - 3 ] == 0xff && V_268 [ V_269 - 2 ] == 0xd9 ) {
F_54 ( V_1 , V_270 ,
V_268 , V_269 - 1 ) ;
return;
}
if ( V_268 [ 0 ] == 0xff && V_268 [ 1 ] == 0xd8 ) {
F_54 ( V_1 , V_271 ,
V_22 -> V_66 , V_272 ) ;
V_268 += 18 ;
V_269 -= 18 ;
}
F_54 ( V_1 , V_273 , V_268 , V_269 ) ;
}
static int F_55 ( struct V_1 * V_1 ,
const struct V_274 * V_275 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
return F_56 ( V_22 -> V_214 , V_275 -> V_276 ) ;
}
static int F_57 ( struct V_1 * V_1 ,
struct V_274 * V_275 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
memset ( V_275 , 0 , sizeof *V_275 ) ;
V_275 -> V_276 = F_48 ( V_22 -> V_214 ) ;
V_275 -> V_277 = V_278
| V_279 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_1 ,
T_1 * V_268 ,
int V_269 )
{
if ( V_269 == 8 && V_268 [ 4 ] == 1 ) {
F_59 ( V_1 -> V_280 , V_281 , 1 ) ;
F_60 ( V_1 -> V_280 ) ;
F_59 ( V_1 -> V_280 , V_281 , 0 ) ;
F_60 ( V_1 -> V_280 ) ;
}
return 0 ;
}
static int F_61 ( struct V_282 * V_283 ,
const struct V_180 * V_181 )
{
return F_62 ( V_283 , V_181 , & V_284 , sizeof( struct V_22 ) ,
V_285 ) ;
}
