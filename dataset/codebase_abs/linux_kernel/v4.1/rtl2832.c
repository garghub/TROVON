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
T_2 V_153 ( V_154 ) ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
* V_152 = 0 ;
if ( V_7 -> V_101 )
return 0 ;
V_8 = F_10 ( V_7 , V_155 , & V_154 ) ;
if ( V_8 )
goto V_21;
if ( V_154 == 11 ) {
* V_152 |= V_156 | V_157 |
V_158 | V_159 | V_160 ;
} else if ( V_154 == 10 ) {
* V_152 |= V_156 | V_157 |
V_158 ;
}
V_7 -> V_102 = * V_152 ;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_27 ( struct V_24 * V_25 , T_3 * V_161 )
{
struct V_34 * V_35 = & V_25 -> V_36 ;
if ( V_35 -> V_97 . V_94 [ 0 ] . V_95 == V_162 )
* V_161 = F_28 ( V_35 -> V_97 . V_94 [ 0 ] . V_163 , 100 ) ;
else
* V_161 = 0 ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 , T_2 * V_164 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
* V_164 = ( V_7 -> V_98 - V_7 -> V_165 ) ;
V_7 -> V_165 = V_7 -> V_98 ;
return 0 ;
}
static void F_30 ( struct V_166 * V_167 )
{
struct V_6 * V_7 = F_31 ( V_167 , struct V_6 , V_100 . V_167 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_34 * V_35 = & V_7 -> V_25 . V_36 ;
int V_8 , V_154 ;
T_4 V_168 , V_127 [ 2 ] ;
T_3 V_169 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
if ( V_7 -> V_102 & V_156 ) {
V_8 = F_8 ( V_2 , 0x305 , & V_168 , 1 ) ;
if ( V_8 )
goto V_21;
F_12 ( & V_2 -> V_7 , L_9 , V_168 ) ;
V_168 = ~ V_168 ;
V_169 = V_168 << 8 | V_168 << 0 ;
V_35 -> V_93 . V_94 [ 0 ] . V_95 = V_170 ;
V_35 -> V_93 . V_94 [ 0 ] . V_171 = V_169 ;
} else {
V_35 -> V_93 . V_94 [ 0 ] . V_95 = V_96 ;
}
if ( V_7 -> V_102 & V_158 ) {
unsigned V_140 , V_172 ;
#define F_32 3
#define F_33 4
static const T_2 V_173 [ F_32 ] [ F_33 ] = {
{ 85387325 , 85387325 , 85387325 , 85387325 } ,
{ 86676178 , 86676178 , 87167949 , 87795660 } ,
{ 87659938 , 87659938 , 87885178 , 88241743 } ,
} ;
V_8 = F_8 ( V_2 , 0x33c , & V_168 , 1 ) ;
if ( V_8 )
goto V_21;
V_172 = ( V_168 >> 2 ) & 0x03 ;
if ( V_172 > F_32 - 1 )
goto V_174;
V_140 = ( V_168 >> 4 ) & 0x07 ;
if ( V_140 > F_33 - 1 )
goto V_174;
V_8 = F_8 ( V_2 , 0x40c , V_127 , 2 ) ;
if ( V_8 )
goto V_21;
V_169 = V_127 [ 0 ] << 8 | V_127 [ 1 ] << 0 ;
if ( V_169 )
V_154 = ( V_173 [ V_172 ] [ V_140 ] -
F_34 ( V_169 ) ) / ( ( 1 << 24 ) / 10000 ) ;
else
V_154 = 0 ;
F_12 ( & V_2 -> V_7 , L_10 , V_169 ) ;
V_35 -> V_97 . V_94 [ 0 ] . V_95 = V_162 ;
V_35 -> V_97 . V_94 [ 0 ] . V_163 = V_154 ;
} else {
V_35 -> V_97 . V_94 [ 0 ] . V_95 = V_96 ;
}
if ( V_7 -> V_102 & V_160 ) {
V_8 = F_8 ( V_2 , 0x34e , V_127 , 2 ) ;
if ( V_8 )
goto V_21;
V_169 = V_127 [ 0 ] << 8 | V_127 [ 1 ] << 0 ;
V_7 -> V_98 += V_169 ;
V_7 -> V_99 += 1000000 ;
F_12 ( & V_2 -> V_7 , L_11 , V_169 ) ;
V_35 -> V_98 . V_94 [ 0 ] . V_95 = V_175 ;
V_35 -> V_98 . V_94 [ 0 ] . V_171 = V_7 -> V_98 ;
V_35 -> V_99 . V_94 [ 0 ] . V_95 = V_175 ;
V_35 -> V_99 . V_94 [ 0 ] . V_171 = V_7 -> V_99 ;
} else {
V_35 -> V_98 . V_94 [ 0 ] . V_95 = V_96 ;
V_35 -> V_99 . V_94 [ 0 ] . V_95 = V_96 ;
}
V_174:
F_18 ( & V_7 -> V_100 , F_19 ( 2000 ) ) ;
return;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
}
static void F_35 ( struct V_166 * V_167 )
{
struct V_6 * V_7 = F_31 ( V_167 , struct V_6 , V_176 . V_167 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
V_8 = F_6 ( V_7 -> V_2 , 0x101 , 0x08 , 0x00 ) ;
if ( V_8 )
goto V_21;
return;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
}
static int F_36 ( struct V_177 * V_178 , void * V_179 , T_2 V_180 )
{
struct V_6 * V_7 = V_179 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
F_37 ( & V_7 -> V_176 ) ;
V_8 = F_7 ( V_7 -> V_10 , 0x101 , 0x08 , 0x08 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_38 ( struct V_177 * V_178 , void * V_179 ,
T_2 V_180 )
{
struct V_6 * V_7 = V_179 ;
F_18 ( & V_7 -> V_176 , F_39 ( 100 ) ) ;
return 0 ;
}
static bool F_40 ( struct V_181 * V_7 , unsigned int V_3 )
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
static int F_41 ( void * V_182 , const void * V_183 ,
T_1 V_184 , void * V_185 , T_1 V_186 )
{
struct V_1 * V_2 = V_182 ;
int V_8 ;
struct V_187 V_188 [ 2 ] = {
{
. V_189 = V_2 -> V_189 ,
. V_190 = 0 ,
. V_17 = V_184 ,
. V_127 = ( T_4 * ) V_183 ,
} , {
. V_189 = V_2 -> V_189 ,
. V_190 = V_191 ,
. V_17 = V_186 ,
. V_127 = V_185 ,
}
} ;
V_8 = F_42 ( V_2 -> V_9 , V_188 , 2 ) ;
if ( V_8 != 2 ) {
F_43 ( & V_2 -> V_7 , L_12 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_192 ;
return V_8 ;
}
return 0 ;
}
static int F_44 ( void * V_182 , const void * V_193 , T_1 V_194 )
{
struct V_1 * V_2 = V_182 ;
int V_8 ;
struct V_187 V_188 [ 1 ] = {
{
. V_189 = V_2 -> V_189 ,
. V_190 = 0 ,
. V_17 = V_194 ,
. V_127 = ( T_4 * ) V_193 ,
}
} ;
V_8 = F_42 ( V_2 -> V_9 , V_188 , 1 ) ;
if ( V_8 != 1 ) {
F_43 ( & V_2 -> V_7 , L_13 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_192 ;
return V_8 ;
}
return 0 ;
}
static int F_45 ( void * V_182 , const void * V_3 ,
T_1 V_195 , const void * V_4 ,
T_1 V_196 )
{
struct V_1 * V_2 = V_182 ;
int V_8 ;
T_4 V_127 [ 256 ] ;
struct V_187 V_188 [ 1 ] = {
{
. V_189 = V_2 -> V_189 ,
. V_190 = 0 ,
. V_17 = 1 + V_196 ,
. V_127 = V_127 ,
}
} ;
V_127 [ 0 ] = * ( T_4 const * ) V_3 ;
memcpy ( & V_127 [ 1 ] , V_4 , V_196 ) ;
V_8 = F_42 ( V_2 -> V_9 , V_188 , 1 ) ;
if ( V_8 != 1 ) {
F_43 ( & V_2 -> V_7 , L_13 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_192 ;
return V_8 ;
}
return 0 ;
}
static void F_46 ( void * V_197 )
{
struct V_6 * V_7 = V_197 ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
F_47 ( & V_7 -> V_198 ) ;
}
static void F_48 ( void * V_197 )
{
struct V_6 * V_7 = V_197 ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
F_49 ( & V_7 -> V_198 ) ;
}
static struct V_24 * F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
return & V_7 -> V_25 ;
}
static struct V_177 * F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
return V_7 -> V_199 ;
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
static int F_53 ( struct V_24 * V_25 , int V_200 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
T_4 V_168 ;
F_12 ( & V_2 -> V_7 , L_20 , V_200 ) ;
if ( V_200 )
V_168 = 0x80 ;
else
V_168 = 0x00 ;
V_8 = F_6 ( V_2 , 0x061 , 0xc0 , V_168 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_54 ( struct V_24 * V_25 , T_4 V_201 , T_3 V_202 ,
int V_200 )
{
struct V_6 * V_7 = V_25 -> V_27 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
T_4 V_127 [ 4 ] ;
F_12 ( & V_2 -> V_7 , L_21 ,
V_201 , V_202 , V_200 ) ;
if ( V_202 > 0x1fff || V_201 > 32 )
return 0 ;
if ( V_200 )
F_55 ( V_201 , & V_7 -> V_203 ) ;
else
F_56 ( V_201 , & V_7 -> V_203 ) ;
V_127 [ 0 ] = ( V_7 -> V_203 >> 0 ) & 0xff ;
V_127 [ 1 ] = ( V_7 -> V_203 >> 8 ) & 0xff ;
V_127 [ 2 ] = ( V_7 -> V_203 >> 16 ) & 0xff ;
V_127 [ 3 ] = ( V_7 -> V_203 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , 0x062 , V_127 , 4 ) ;
if ( V_8 )
goto V_21;
V_127 [ 0 ] = ( V_202 >> 8 ) & 0xff ;
V_127 [ 1 ] = ( V_202 >> 0 ) & 0xff ;
V_8 = F_1 ( V_2 , 0x066 + 2 * V_201 , V_127 , 2 ) ;
if ( V_8 )
goto V_21;
return 0 ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_57 ( struct V_1 * V_2 ,
const struct V_204 * V_205 )
{
struct V_206 * V_30 = V_2 -> V_7 . V_207 ;
struct V_177 * V_208 = V_2 -> V_9 ;
struct V_6 * V_7 ;
int V_8 ;
T_4 V_154 ;
static const struct V_209 V_209 = {
. V_210 = F_41 ,
. V_211 = F_44 ,
. V_212 = F_45 ,
. V_213 = V_214 ,
} ;
static const struct V_215 V_215 [] = {
{
. V_216 = 0x00 ,
. V_217 = 0xff ,
. V_218 = 0 ,
. V_219 = 0 ,
. V_220 = 0x100 ,
. V_221 = 0 * 0x100 ,
. V_222 = 5 * 0x100 ,
} ,
} ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
V_7 = F_58 ( sizeof( struct V_6 ) , V_223 ) ;
if ( V_7 == NULL ) {
V_8 = - V_224 ;
goto V_21;
}
F_59 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_30 = V_2 -> V_7 . V_207 ;
V_7 -> V_101 = true ;
F_60 ( & V_7 -> V_176 , F_35 ) ;
F_60 ( & V_7 -> V_100 , F_30 ) ;
F_61 ( & V_7 -> V_198 ) ;
V_7 -> V_225 . V_226 = 8 ,
V_7 -> V_225 . V_227 = 8 ,
V_7 -> V_225 . V_228 = F_46 ,
V_7 -> V_225 . V_229 = F_48 ,
V_7 -> V_225 . V_230 = V_7 ,
V_7 -> V_225 . V_231 = F_40 ,
V_7 -> V_225 . V_232 = 5 * 0x100 ,
V_7 -> V_225 . V_233 = V_215 ,
V_7 -> V_225 . V_234 = F_17 ( V_215 ) ,
V_7 -> V_225 . V_235 = V_236 ,
V_7 -> V_10 = F_62 ( & V_2 -> V_7 , & V_209 , V_2 ,
& V_7 -> V_225 ) ;
if ( F_63 ( V_7 -> V_10 ) ) {
V_8 = F_64 ( V_7 -> V_10 ) ;
goto V_237;
}
V_8 = F_8 ( V_2 , 0x000 , & V_154 , 1 ) ;
if ( V_8 )
goto V_238;
V_7 -> V_199 = F_65 ( V_208 , & V_208 -> V_7 , V_7 ,
0 , 0 , 0 , F_36 , F_38 ) ;
if ( V_7 -> V_199 == NULL ) {
V_8 = - V_239 ;
goto V_238;
}
memcpy ( & V_7 -> V_25 . V_108 , & V_240 , sizeof( struct V_241 ) ) ;
V_7 -> V_25 . V_27 = V_7 ;
V_30 -> V_242 = F_50 ;
V_30 -> V_243 = F_51 ;
V_30 -> V_244 = F_52 ;
V_30 -> V_245 = F_54 ;
V_30 -> V_246 = F_53 ;
V_30 -> V_247 = F_8 ;
V_30 -> V_248 = F_1 ;
V_30 -> V_249 = F_6 ;
F_66 ( & V_2 -> V_7 , L_22 ) ;
return 0 ;
V_238:
F_67 ( V_7 -> V_10 ) ;
V_237:
F_68 ( V_7 ) ;
V_21:
F_12 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_3 ) ;
F_21 ( & V_7 -> V_176 ) ;
F_70 ( V_7 -> V_199 ) ;
F_67 ( V_7 -> V_10 ) ;
F_68 ( V_7 ) ;
return 0 ;
}
