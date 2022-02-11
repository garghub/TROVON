static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_2 -> V_9 ) ;
V_8 = F_4 ( V_7 -> V_10 , V_3 , V_4 , V_5 ) ;
F_5 ( V_2 -> V_9 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_11 , unsigned int V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_2 -> V_9 ) ;
V_8 = F_7 ( V_7 -> V_10 , V_3 , V_11 , V_4 ) ;
F_5 ( V_2 -> V_9 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_2 -> V_9 ) ;
V_8 = F_9 ( V_7 -> V_10 , V_3 , V_4 , V_5 ) ;
F_5 ( V_2 -> V_9 ) ;
return V_8 ;
}
static int F_10 ( struct V_6 * V_7 , int V_3 , T_2 * V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 , V_12 ;
T_3 V_13 ;
T_4 V_14 , V_15 , V_16 [ 4 ] , V_17 ;
T_2 V_18 , V_11 ;
V_13 = V_19 [ V_3 ] . V_20 ;
V_14 = V_19 [ V_3 ] . V_14 ;
V_15 = V_19 [ V_3 ] . V_15 ;
V_17 = ( V_14 >> 3 ) + 1 ;
V_11 = F_11 ( V_14 - V_15 ) ;
V_8 = F_8 ( V_2 , V_13 , V_16 , V_17 ) ;
if ( V_8 )
goto V_21;
V_18 = 0 ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ )
V_18 |= V_16 [ V_12 ] << ( ( V_17 - 1 - V_12 ) * 8 ) ;
* V_4 = ( V_18 >> V_15 ) & V_11 ;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_13 ( struct V_6 * V_7 , int V_3 , T_2 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 , V_12 ;
T_3 V_13 ;
T_4 V_14 , V_15 , V_16 [ 4 ] , V_22 [ 4 ] , V_17 ;
T_2 V_18 , V_23 , V_11 ;
V_13 = V_19 [ V_3 ] . V_20 ;
V_14 = V_19 [ V_3 ] . V_14 ;
V_15 = V_19 [ V_3 ] . V_15 ;
V_17 = ( V_14 >> 3 ) + 1 ;
V_11 = F_11 ( V_14 - V_15 ) ;
V_8 = F_8 ( V_2 , V_13 , V_16 , V_17 ) ;
if ( V_8 )
goto V_21;
V_18 = 0 ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ )
V_18 |= V_16 [ V_12 ] << ( ( V_17 - 1 - V_12 ) * 8 ) ;
V_23 = V_18 & ~ ( V_11 << V_15 ) ;
V_23 |= ( ( V_4 & V_11 ) << V_15 ) ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ )
V_22 [ V_12 ] = ( V_23 >> ( ( V_17 - 1 - V_12 ) * 8 ) ) & 0xff ;
V_8 = F_1 ( V_2 , V_13 , V_22 , V_17 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_14 ( struct V_24 * V_25 , T_2 V_26 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
T_5 V_28 ;
T_4 V_29 = ( V_26 == 0 ? 0x1 : 0x0 ) ;
V_28 = V_26 % V_7 -> V_30 -> V_31 ;
V_28 *= 0x400000 ;
V_28 = F_15 ( V_28 , V_7 -> V_30 -> V_31 ) ;
V_28 = - V_28 ;
V_28 = V_28 & 0x3fffff ;
F_12 ( & V_2 -> V_7 , L_2 ,
V_26 , ( unsigned ) V_28 ) ;
V_8 = F_13 ( V_7 , V_32 , V_29 ) ;
if ( V_8 )
goto V_21;
V_8 = F_13 ( V_7 , V_33 , V_28 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_16 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_34 * V_35 = & V_7 -> V_25 . V_36 ;
const struct V_37 * V_38 ;
int V_12 , V_8 , V_17 ;
struct V_37 V_39 [] = {
{ V_40 , 0x1 } ,
{ V_41 , 0x1 } ,
{ V_42 , 0x2800 } ,
{ V_43 , 0x10 } ,
{ V_44 , 0x20 } ,
{ V_45 , 0x20 } ,
{ V_46 , 0x40 } ,
{ V_47 , 0x22 } ,
{ V_48 , 0x32 } ,
{ V_49 , 0x37 } ,
{ V_50 , 0x39 } ,
{ V_51 , 0x0 } ,
{ V_52 , 0x0 } ,
{ V_53 , 0x2a } ,
{ V_54 , 0x6 } ,
{ V_55 , 0x0 } ,
{ V_56 , 0x8 } ,
{ V_57 , 0x8 } ,
{ V_58 , 0x4 } ,
{ V_59 , 0xb0 } ,
{ V_60 , 0x78 } ,
{ V_61 , 0x28 } ,
{ V_62 , 0x59 } ,
{ V_63 , 0x83 } ,
{ V_64 , 0xd4 } ,
{ V_65 , 0x65 } ,
{ V_66 , 0x43 } ,
{ V_67 , 0x1 } ,
{ V_68 , 0x4 } ,
{ V_69 , 0x7 } ,
{ V_70 , 0xa } ,
{ V_71 , 0x1 } ,
{ V_72 , 0x0 } ,
{ V_56 , 0x9 } ,
{ V_57 , 0x9 } ,
{ V_73 , 0x0 } ,
{ V_74 , 0x0 } ,
{ V_75 , 0x4 } ,
{ V_76 , 0x7 } ,
{ V_77 , 0x6 } ,
{ V_78 , 0x5 } ,
{ V_79 , 0x1 } ,
} ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
for ( V_12 = 0 ; V_12 < F_17 ( V_39 ) ; V_12 ++ ) {
V_8 = F_13 ( V_7 , V_39 [ V_12 ] . V_3 ,
V_39 [ V_12 ] . V_80 ) ;
if ( V_8 )
goto V_21;
}
F_12 ( & V_2 -> V_7 , L_4 ,
V_7 -> V_30 -> V_81 ) ;
switch ( V_7 -> V_30 -> V_81 ) {
case V_82 :
case V_83 :
V_17 = F_17 ( V_84 ) ;
V_38 = V_84 ;
break;
case V_85 :
V_17 = F_17 ( V_86 ) ;
V_38 = V_86 ;
break;
case V_87 :
V_17 = F_17 ( V_88 ) ;
V_38 = V_88 ;
break;
case V_89 :
case V_90 :
V_17 = F_17 ( V_91 ) ;
V_38 = V_91 ;
break;
default:
V_8 = - V_92 ;
goto V_21;
}
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
V_8 = F_13 ( V_7 , V_38 [ V_12 ] . V_3 , V_38 [ V_12 ] . V_80 ) ;
if ( V_8 )
goto V_21;
}
V_35 -> V_93 . V_17 = 1 ;
V_35 -> V_93 . V_94 [ 0 ] . V_95 = V_96 ;
V_35 -> V_97 . V_17 = 1 ;
V_35 -> V_97 . V_94 [ 0 ] . V_95 = V_96 ;
V_35 -> V_98 . V_17 = 1 ;
V_35 -> V_98 . V_94 [ 0 ] . V_95 = V_96 ;
V_35 -> V_99 . V_17 = 1 ;
V_35 -> V_99 . V_94 [ 0 ] . V_95 = V_96 ;
F_18 ( & V_7 -> V_100 , F_19 ( 2000 ) ) ;
V_7 -> V_101 = false ;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_20 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
V_7 -> V_101 = true ;
F_21 ( & V_7 -> V_100 ) ;
V_7 -> V_102 = 0 ;
V_8 = F_13 ( V_7 , V_103 , 0x1 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_22 ( struct V_24 * V_25 ,
struct V_104 * V_105 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
V_105 -> V_106 = 1000 ;
V_105 -> V_107 = V_25 -> V_108 . V_109 . V_110 * 2 ;
V_105 -> V_111 = ( V_25 -> V_108 . V_109 . V_110 * 2 ) + 1 ;
return 0 ;
}
static int F_23 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_34 * V_35 = & V_25 -> V_36 ;
int V_8 , V_12 , V_112 ;
T_5 V_113 , V_114 , V_115 ;
T_2 V_116 , V_117 ;
static T_4 V_118 [ 3 ] [ 32 ] = {
{
0xf5 , 0xff , 0x15 , 0x38 , 0x5d , 0x6d , 0x52 , 0x07 , 0xfa , 0x2f ,
0x53 , 0xf5 , 0x3f , 0xca , 0x0b , 0x91 , 0xea , 0x30 , 0x63 , 0xb2 ,
0x13 , 0xda , 0x0b , 0xc4 , 0x18 , 0x7e , 0x16 , 0x66 , 0x08 , 0x67 ,
0x19 , 0xe0 ,
} ,
{
0xe7 , 0xcc , 0xb5 , 0xba , 0xe8 , 0x2f , 0x67 , 0x61 , 0x00 , 0xaf ,
0x86 , 0xf2 , 0xbf , 0x59 , 0x04 , 0x11 , 0xb6 , 0x33 , 0xa4 , 0x30 ,
0x15 , 0x10 , 0x0a , 0x42 , 0x18 , 0xf8 , 0x17 , 0xd9 , 0x07 , 0x22 ,
0x19 , 0x10 ,
} ,
{
0x09 , 0xf6 , 0xd2 , 0xa7 , 0x9a , 0xc9 , 0x27 , 0x77 , 0x06 , 0xbf ,
0xec , 0xf4 , 0x4f , 0x0b , 0xfc , 0x01 , 0x63 , 0x35 , 0x54 , 0xa7 ,
0x16 , 0x66 , 0x08 , 0xb4 , 0x19 , 0x6e , 0x19 , 0x65 , 0x05 , 0xc8 ,
0x19 , 0xe0 ,
} ,
} ;
F_12 ( & V_2 -> V_7 , L_5 ,
V_35 -> V_119 , V_35 -> V_120 , V_35 -> V_121 ) ;
if ( V_25 -> V_108 . V_122 . V_123 )
V_25 -> V_108 . V_122 . V_123 ( V_25 ) ;
V_8 = F_1 ( V_2 , 0x192 , L_6 , 3 ) ;
if ( V_8 )
goto V_21;
if ( V_25 -> V_108 . V_122 . V_124 ) {
T_2 V_26 ;
V_8 = V_25 -> V_108 . V_122 . V_124 ( V_25 , & V_26 ) ;
if ( V_8 )
goto V_21;
V_8 = F_14 ( V_25 , V_26 ) ;
if ( V_8 )
goto V_21;
}
switch ( V_35 -> V_120 ) {
case 6000000 :
V_12 = 0 ;
V_113 = 48000000 ;
break;
case 7000000 :
V_12 = 1 ;
V_113 = 56000000 ;
break;
case 8000000 :
V_12 = 2 ;
V_113 = 64000000 ;
break;
default:
F_24 ( & V_2 -> V_7 , L_7 ,
V_35 -> V_120 ) ;
V_8 = - V_92 ;
goto V_21;
}
for ( V_112 = 0 ; V_112 < sizeof( V_118 [ 0 ] ) ; V_112 ++ ) {
V_8 = F_1 ( V_2 , 0x11c + V_112 , & V_118 [ V_12 ] [ V_112 ] , 1 ) ;
if ( V_8 )
goto V_21;
}
V_114 = V_7 -> V_30 -> V_31 * 7 ;
V_114 *= 0x400000 ;
V_114 = F_15 ( V_114 , V_113 ) ;
V_116 = V_114 & 0x3ffffff ;
V_8 = F_13 ( V_7 , V_125 , V_116 ) ;
if ( V_8 )
goto V_21;
V_114 = V_113 << 20 ;
V_115 = V_7 -> V_30 -> V_31 * 7 ;
V_114 = F_15 ( V_114 , V_115 ) ;
V_114 = - V_114 ;
V_117 = V_114 & 0xfffff ;
V_8 = F_13 ( V_7 , V_126 , V_117 ) ;
if ( V_8 )
goto V_21;
V_8 = F_13 ( V_7 , V_103 , 0x1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_13 ( V_7 , V_103 , 0x0 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_25 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_34 * V_35 = & V_25 -> V_36 ;
int V_8 ;
T_4 V_127 [ 3 ] ;
if ( V_7 -> V_101 )
return 0 ;
V_8 = F_8 ( V_2 , 0x33c , V_127 , 2 ) ;
if ( V_8 )
goto V_21;
V_8 = F_8 ( V_2 , 0x351 , & V_127 [ 2 ] , 1 ) ;
if ( V_8 )
goto V_21;
F_12 ( & V_2 -> V_7 , L_8 , 3 , V_127 ) ;
switch ( ( V_127 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_35 -> V_128 = V_129 ;
break;
case 1 :
V_35 -> V_128 = V_130 ;
break;
case 2 :
V_35 -> V_128 = V_131 ;
break;
}
switch ( ( V_127 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_35 -> V_132 = V_133 ;
break;
case 1 :
V_35 -> V_132 = V_134 ;
}
switch ( ( V_127 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_35 -> V_135 = V_136 ;
break;
case 1 :
V_35 -> V_135 = V_137 ;
break;
case 2 :
V_35 -> V_135 = V_138 ;
break;
case 3 :
V_35 -> V_135 = V_139 ;
break;
}
switch ( ( V_127 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_35 -> V_140 = V_141 ;
break;
case 1 :
V_35 -> V_140 = V_142 ;
break;
case 2 :
V_35 -> V_140 = V_143 ;
break;
case 3 :
V_35 -> V_140 = V_144 ;
break;
}
switch ( ( V_127 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_35 -> V_145 = V_146 ;
break;
case 1 :
V_35 -> V_145 = V_147 ;
break;
case 2 :
V_35 -> V_145 = V_148 ;
break;
case 3 :
V_35 -> V_145 = V_149 ;
break;
case 4 :
V_35 -> V_145 = V_150 ;
break;
}
switch ( ( V_127 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_35 -> V_151 = V_146 ;
break;
case 1 :
V_35 -> V_151 = V_147 ;
break;
case 2 :
V_35 -> V_151 = V_148 ;
break;
case 3 :
V_35 -> V_151 = V_149 ;
break;
case 4 :
V_35 -> V_151 = V_150 ;
break;
}
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_26 ( struct V_24 * V_25 , T_6 * V_152 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
T_2 V_153 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
* V_152 = 0 ;
if ( V_7 -> V_101 )
return 0 ;
V_8 = F_10 ( V_7 , V_154 , & V_153 ) ;
if ( V_8 )
goto V_21;
if ( V_153 == 11 ) {
* V_152 |= V_155 | V_156 |
V_157 | V_158 | V_159 ;
} else if ( V_153 == 10 ) {
* V_152 |= V_155 | V_156 |
V_157 ;
}
V_7 -> V_102 = * V_152 ;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_27 ( struct V_24 * V_25 , T_3 * V_160 )
{
struct V_34 * V_35 = & V_25 -> V_36 ;
if ( V_35 -> V_97 . V_94 [ 0 ] . V_95 == V_161 )
* V_160 = F_28 ( V_35 -> V_97 . V_94 [ 0 ] . V_162 , 100 ) ;
else
* V_160 = 0 ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 , T_2 * V_163 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
* V_163 = ( V_7 -> V_98 - V_7 -> V_164 ) ;
V_7 -> V_164 = V_7 -> V_98 ;
return 0 ;
}
static void F_30 ( struct V_165 * V_166 )
{
struct V_6 * V_7 = F_31 ( V_166 , struct V_6 , V_100 . V_166 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_34 * V_35 = & V_7 -> V_25 . V_36 ;
int V_8 , V_153 ;
T_4 V_167 , V_127 [ 2 ] ;
T_3 V_168 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
if ( V_7 -> V_102 & V_155 ) {
V_8 = F_8 ( V_2 , 0x305 , & V_167 , 1 ) ;
if ( V_8 )
goto V_21;
F_12 ( & V_2 -> V_7 , L_9 , V_167 ) ;
V_167 = ~ V_167 ;
V_168 = V_167 << 8 | V_167 << 0 ;
V_35 -> V_93 . V_94 [ 0 ] . V_95 = V_169 ;
V_35 -> V_93 . V_94 [ 0 ] . V_170 = V_168 ;
} else {
V_35 -> V_93 . V_94 [ 0 ] . V_95 = V_96 ;
}
if ( V_7 -> V_102 & V_157 ) {
unsigned V_140 , V_171 ;
#define F_32 3
#define F_33 4
static const T_2 V_172 [ F_32 ] [ F_33 ] = {
{ 85387325 , 85387325 , 85387325 , 85387325 } ,
{ 86676178 , 86676178 , 87167949 , 87795660 } ,
{ 87659938 , 87659938 , 87885178 , 88241743 } ,
} ;
V_8 = F_8 ( V_2 , 0x33c , & V_167 , 1 ) ;
if ( V_8 )
goto V_21;
V_171 = ( V_167 >> 2 ) & 0x03 ;
if ( V_171 > F_32 - 1 )
goto V_173;
V_140 = ( V_167 >> 4 ) & 0x07 ;
if ( V_140 > F_33 - 1 )
goto V_173;
V_8 = F_8 ( V_2 , 0x40c , V_127 , 2 ) ;
if ( V_8 )
goto V_21;
V_168 = V_127 [ 0 ] << 8 | V_127 [ 1 ] << 0 ;
if ( V_168 )
V_153 = ( V_172 [ V_171 ] [ V_140 ] -
F_34 ( V_168 ) ) / ( ( 1 << 24 ) / 10000 ) ;
else
V_153 = 0 ;
F_12 ( & V_2 -> V_7 , L_10 , V_168 ) ;
V_35 -> V_97 . V_94 [ 0 ] . V_95 = V_161 ;
V_35 -> V_97 . V_94 [ 0 ] . V_162 = V_153 ;
} else {
V_35 -> V_97 . V_94 [ 0 ] . V_95 = V_96 ;
}
if ( V_7 -> V_102 & V_159 ) {
V_8 = F_8 ( V_2 , 0x34e , V_127 , 2 ) ;
if ( V_8 )
goto V_21;
V_168 = V_127 [ 0 ] << 8 | V_127 [ 1 ] << 0 ;
V_7 -> V_98 += V_168 ;
V_7 -> V_99 += 1000000 ;
F_12 ( & V_2 -> V_7 , L_11 , V_168 ) ;
V_35 -> V_98 . V_94 [ 0 ] . V_95 = V_174 ;
V_35 -> V_98 . V_94 [ 0 ] . V_170 = V_7 -> V_98 ;
V_35 -> V_99 . V_94 [ 0 ] . V_95 = V_174 ;
V_35 -> V_99 . V_94 [ 0 ] . V_170 = V_7 -> V_99 ;
} else {
V_35 -> V_98 . V_94 [ 0 ] . V_95 = V_96 ;
V_35 -> V_99 . V_94 [ 0 ] . V_95 = V_96 ;
}
V_173:
F_18 ( & V_7 -> V_100 , F_19 ( 2000 ) ) ;
return;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
}
static void F_35 ( struct V_165 * V_166 )
{
struct V_6 * V_7 = F_31 ( V_166 , struct V_6 , V_175 . V_166 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
V_8 = F_6 ( V_7 -> V_2 , 0x101 , 0x08 , 0x00 ) ;
if ( V_8 )
goto V_21;
return;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
}
static int F_36 ( struct V_176 * V_177 , void * V_178 , T_2 V_179 )
{
struct V_6 * V_7 = V_178 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
F_37 ( & V_7 -> V_175 ) ;
V_8 = F_7 ( V_7 -> V_10 , 0x101 , 0x08 , 0x08 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_38 ( struct V_176 * V_177 , void * V_178 ,
T_2 V_179 )
{
struct V_6 * V_7 = V_178 ;
F_18 ( & V_7 -> V_175 , F_39 ( 100 ) ) ;
return 0 ;
}
static bool F_40 ( struct V_180 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0x305 :
case 0x33c :
case 0x34e :
case 0x351 :
case 0x40c ... 0x40d :
return true ;
default:
break;
}
return false ;
}
static int F_41 ( void * V_181 , const void * V_182 ,
T_1 V_183 , void * V_184 , T_1 V_185 )
{
struct V_1 * V_2 = V_181 ;
int V_8 ;
struct V_186 V_187 [ 2 ] = {
{
. V_188 = V_2 -> V_188 ,
. V_189 = 0 ,
. V_17 = V_183 ,
. V_127 = ( T_4 * ) V_182 ,
} , {
. V_188 = V_2 -> V_188 ,
. V_189 = V_190 ,
. V_17 = V_185 ,
. V_127 = V_184 ,
}
} ;
V_8 = F_42 ( V_2 -> V_9 , V_187 , 2 ) ;
if ( V_8 != 2 ) {
F_43 ( & V_2 -> V_7 , L_12 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_191 ;
return V_8 ;
}
return 0 ;
}
static int F_44 ( void * V_181 , const void * V_192 , T_1 V_193 )
{
struct V_1 * V_2 = V_181 ;
int V_8 ;
struct V_186 V_187 [ 1 ] = {
{
. V_188 = V_2 -> V_188 ,
. V_189 = 0 ,
. V_17 = V_193 ,
. V_127 = ( T_4 * ) V_192 ,
}
} ;
V_8 = F_42 ( V_2 -> V_9 , V_187 , 1 ) ;
if ( V_8 != 1 ) {
F_43 ( & V_2 -> V_7 , L_13 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_191 ;
return V_8 ;
}
return 0 ;
}
static int F_45 ( void * V_181 , const void * V_3 ,
T_1 V_194 , const void * V_4 ,
T_1 V_195 )
{
struct V_1 * V_2 = V_181 ;
int V_8 ;
T_4 V_127 [ 256 ] ;
struct V_186 V_187 [ 1 ] = {
{
. V_188 = V_2 -> V_188 ,
. V_189 = 0 ,
. V_17 = 1 + V_195 ,
. V_127 = V_127 ,
}
} ;
V_127 [ 0 ] = * ( T_4 const * ) V_3 ;
memcpy ( & V_127 [ 1 ] , V_4 , V_195 ) ;
V_8 = F_42 ( V_2 -> V_9 , V_187 , 1 ) ;
if ( V_8 != 1 ) {
F_43 ( & V_2 -> V_7 , L_13 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_191 ;
return V_8 ;
}
return 0 ;
}
static void F_46 ( void * V_196 )
{
struct V_6 * V_7 = V_196 ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
F_47 ( & V_7 -> V_197 ) ;
}
static void F_48 ( void * V_196 )
{
struct V_6 * V_7 = V_196 ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
F_49 ( & V_7 -> V_197 ) ;
}
static struct V_24 * F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
return & V_7 -> V_25 ;
}
static struct V_176 * F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
return V_7 -> V_198 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
V_8 = F_1 ( V_2 , 0x10c , L_14 , 2 ) ;
if ( V_8 )
goto V_21;
V_8 = F_13 ( V_7 , V_55 , 0x1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , 0x0bc , L_15 , 1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , 0x022 , L_16 , 1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , 0x026 , L_17 , 1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , 0x027 , L_18 , 1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , 0x192 , L_19 , 3 ) ;
if ( V_8 )
goto V_21;
V_8 = F_13 ( V_7 , V_103 , 0x1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_13 ( V_7 , V_103 , 0x0 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_53 ( struct V_24 * V_25 , int V_199 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
T_4 V_167 ;
F_12 ( & V_2 -> V_7 , L_20 , V_199 ) ;
if ( V_199 )
V_167 = 0x80 ;
else
V_167 = 0x00 ;
V_8 = F_6 ( V_2 , 0x061 , 0xc0 , V_167 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_54 ( struct V_24 * V_25 , T_4 V_200 , T_3 V_201 ,
int V_199 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
T_4 V_127 [ 4 ] ;
F_12 ( & V_2 -> V_7 , L_21 ,
V_200 , V_201 , V_199 ) ;
if ( V_201 > 0x1fff || V_200 > 32 )
return 0 ;
if ( V_199 )
F_55 ( V_200 , & V_7 -> V_202 ) ;
else
F_56 ( V_200 , & V_7 -> V_202 ) ;
V_127 [ 0 ] = ( V_7 -> V_202 >> 0 ) & 0xff ;
V_127 [ 1 ] = ( V_7 -> V_202 >> 8 ) & 0xff ;
V_127 [ 2 ] = ( V_7 -> V_202 >> 16 ) & 0xff ;
V_127 [ 3 ] = ( V_7 -> V_202 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , 0x062 , V_127 , 4 ) ;
if ( V_8 )
goto V_21;
V_127 [ 0 ] = ( V_201 >> 8 ) & 0xff ;
V_127 [ 1 ] = ( V_201 >> 0 ) & 0xff ;
V_8 = F_1 ( V_2 , 0x066 + 2 * V_200 , V_127 , 2 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_57 ( struct V_1 * V_2 ,
const struct V_203 * V_204 )
{
struct V_205 * V_30 = V_2 -> V_7 . V_206 ;
struct V_176 * V_207 = V_2 -> V_9 ;
struct V_6 * V_7 ;
int V_8 ;
T_4 V_153 ;
static const struct V_208 V_208 = {
. V_209 = F_41 ,
. V_210 = F_44 ,
. V_211 = F_45 ,
. V_212 = V_213 ,
} ;
static const struct V_214 V_214 [] = {
{
. V_215 = 0x00 ,
. V_216 = 0xff ,
. V_217 = 0 ,
. V_218 = 0 ,
. V_219 = 0x100 ,
. V_220 = 0 * 0x100 ,
. V_221 = 5 * 0x100 ,
} ,
} ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
V_7 = F_58 ( sizeof( struct V_6 ) , V_222 ) ;
if ( V_7 == NULL ) {
V_8 = - V_223 ;
goto V_21;
}
F_59 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_30 = V_2 -> V_7 . V_206 ;
V_7 -> V_101 = true ;
F_60 ( & V_7 -> V_175 , F_35 ) ;
F_60 ( & V_7 -> V_100 , F_30 ) ;
F_61 ( & V_7 -> V_197 ) ;
V_7 -> V_224 . V_225 = 8 ,
V_7 -> V_224 . V_226 = 8 ,
V_7 -> V_224 . V_227 = F_46 ,
V_7 -> V_224 . V_228 = F_48 ,
V_7 -> V_224 . V_229 = V_7 ,
V_7 -> V_224 . V_230 = F_40 ,
V_7 -> V_224 . V_231 = 5 * 0x100 ,
V_7 -> V_224 . V_232 = V_214 ,
V_7 -> V_224 . V_233 = F_17 ( V_214 ) ,
V_7 -> V_224 . V_234 = V_235 ,
V_7 -> V_10 = F_62 ( & V_2 -> V_7 , & V_208 , V_2 ,
& V_7 -> V_224 ) ;
if ( F_63 ( V_7 -> V_10 ) ) {
V_8 = F_64 ( V_7 -> V_10 ) ;
goto V_236;
}
V_8 = F_8 ( V_2 , 0x000 , & V_153 , 1 ) ;
if ( V_8 )
goto V_237;
V_7 -> V_198 = F_65 ( V_207 , & V_207 -> V_7 , V_7 ,
0 , 0 , 0 , F_36 , F_38 ) ;
if ( V_7 -> V_198 == NULL ) {
V_8 = - V_238 ;
goto V_237;
}
memcpy ( & V_7 -> V_25 . V_108 , & V_239 , sizeof( struct V_240 ) ) ;
V_7 -> V_25 . V_27 = V_7 ;
V_30 -> V_241 = F_50 ;
V_30 -> V_242 = F_51 ;
V_30 -> V_243 = F_52 ;
V_30 -> V_244 = F_54 ;
V_30 -> V_245 = F_53 ;
V_30 -> V_246 = F_8 ;
V_30 -> V_247 = F_1 ;
V_30 -> V_248 = F_6 ;
F_66 ( & V_2 -> V_7 , L_22 ) ;
return 0 ;
V_237:
F_67 ( V_7 -> V_10 ) ;
V_236:
F_68 ( V_7 ) ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
F_21 ( & V_7 -> V_175 ) ;
F_70 ( V_7 -> V_198 ) ;
F_67 ( V_7 -> V_10 ) ;
F_68 ( V_7 ) ;
return 0 ;
}
