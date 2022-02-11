static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 , V_8 ;
T_2 V_9 ;
T_3 V_10 , V_11 , V_12 [ 4 ] , V_13 ;
T_1 V_14 , V_15 ;
V_9 = V_16 [ V_3 ] . V_17 ;
V_10 = V_16 [ V_3 ] . V_10 ;
V_11 = V_16 [ V_3 ] . V_11 ;
V_13 = ( V_10 >> 3 ) + 1 ;
V_15 = F_2 ( V_10 - V_11 ) ;
V_7 = F_3 ( V_2 -> V_18 , V_9 , V_12 , V_13 ) ;
if ( V_7 )
goto V_19;
V_14 = 0 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
V_14 |= V_12 [ V_8 ] << ( ( V_13 - 1 - V_8 ) * 8 ) ;
* V_4 = ( V_14 >> V_11 ) & V_15 ;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 , V_8 ;
T_2 V_9 ;
T_3 V_10 , V_11 , V_12 [ 4 ] , V_20 [ 4 ] , V_13 ;
T_1 V_14 , V_21 , V_15 ;
V_9 = V_16 [ V_3 ] . V_17 ;
V_10 = V_16 [ V_3 ] . V_10 ;
V_11 = V_16 [ V_3 ] . V_11 ;
V_13 = ( V_10 >> 3 ) + 1 ;
V_15 = F_2 ( V_10 - V_11 ) ;
V_7 = F_3 ( V_2 -> V_18 , V_9 , V_12 , V_13 ) ;
if ( V_7 )
goto V_19;
V_14 = 0 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
V_14 |= V_12 [ V_8 ] << ( ( V_13 - 1 - V_8 ) * 8 ) ;
V_21 = V_14 & ~ ( V_15 << V_11 ) ;
V_21 |= ( ( V_4 & V_15 ) << V_11 ) ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
V_20 [ V_8 ] = ( V_21 >> ( ( V_13 - 1 - V_8 ) * 8 ) ) & 0xff ;
V_7 = F_6 ( V_2 -> V_18 , V_9 , V_20 , V_13 ) ;
if ( V_7 )
goto V_19;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_7 ( struct V_22 * V_23 , T_1 V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
T_4 V_26 ;
T_3 V_27 = ( V_24 == 0 ? 0x1 : 0x0 ) ;
V_26 = V_24 % V_2 -> V_28 -> V_29 ;
V_26 *= 0x400000 ;
V_26 = F_8 ( V_26 , V_2 -> V_28 -> V_29 ) ;
V_26 = - V_26 ;
V_26 = V_26 & 0x3fffff ;
F_4 ( & V_6 -> V_2 , L_2 ,
V_24 , ( unsigned ) V_26 ) ;
V_7 = F_5 ( V_2 , V_30 , V_27 ) ;
if ( V_7 )
goto V_19;
V_7 = F_5 ( V_2 , V_31 , V_26 ) ;
if ( V_7 )
goto V_19;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_9 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_32 * V_33 = & V_2 -> V_23 . V_34 ;
const struct V_35 * V_36 ;
int V_8 , V_7 , V_13 ;
struct V_35 V_37 [] = {
{ V_38 , 0x1 } ,
{ V_39 , 0x1 } ,
{ V_40 , 0x2800 } ,
{ V_41 , 0x10 } ,
{ V_42 , 0x20 } ,
{ V_43 , 0x20 } ,
{ V_44 , 0x40 } ,
{ V_45 , 0x22 } ,
{ V_46 , 0x32 } ,
{ V_47 , 0x37 } ,
{ V_48 , 0x39 } ,
{ V_49 , 0x0 } ,
{ V_50 , 0x0 } ,
{ V_51 , 0x2a } ,
{ V_52 , 0x6 } ,
{ V_53 , 0x0 } ,
{ V_54 , 0x8 } ,
{ V_55 , 0x8 } ,
{ V_56 , 0x4 } ,
{ V_57 , 0xb0 } ,
{ V_58 , 0x78 } ,
{ V_59 , 0x28 } ,
{ V_60 , 0x59 } ,
{ V_61 , 0x83 } ,
{ V_62 , 0xd4 } ,
{ V_63 , 0x65 } ,
{ V_64 , 0x43 } ,
{ V_65 , 0x1 } ,
{ V_66 , 0x4 } ,
{ V_67 , 0x7 } ,
{ V_68 , 0xa } ,
{ V_69 , 0x1 } ,
{ V_70 , 0x0 } ,
{ V_54 , 0x9 } ,
{ V_55 , 0x9 } ,
{ V_71 , 0x0 } ,
{ V_72 , 0x0 } ,
{ V_73 , 0x4 } ,
{ V_74 , 0x7 } ,
{ V_75 , 0x6 } ,
{ V_76 , 0x5 } ,
{ V_77 , 0x1 } ,
} ;
F_4 ( & V_6 -> V_2 , L_3 ) ;
V_7 = F_5 ( V_2 , V_78 , 0x0 ) ;
if ( V_7 )
goto V_19;
for ( V_8 = 0 ; V_8 < F_10 ( V_37 ) ; V_8 ++ ) {
V_7 = F_5 ( V_2 , V_37 [ V_8 ] . V_3 ,
V_37 [ V_8 ] . V_79 ) ;
if ( V_7 )
goto V_19;
}
F_4 ( & V_6 -> V_2 , L_4 ,
V_2 -> V_28 -> V_80 ) ;
switch ( V_2 -> V_28 -> V_80 ) {
case V_81 :
V_13 = F_10 ( V_82 ) ;
V_36 = V_82 ;
break;
case V_83 :
case V_84 :
V_13 = F_10 ( V_85 ) ;
V_36 = V_85 ;
break;
case V_86 :
V_13 = F_10 ( V_87 ) ;
V_36 = V_87 ;
break;
case V_88 :
V_13 = F_10 ( V_89 ) ;
V_36 = V_89 ;
break;
case V_90 :
case V_91 :
V_13 = F_10 ( V_92 ) ;
V_36 = V_92 ;
break;
case V_93 :
V_13 = F_10 ( V_94 ) ;
V_36 = V_94 ;
break;
default:
V_7 = - V_95 ;
goto V_19;
}
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ ) {
V_7 = F_5 ( V_2 , V_36 [ V_8 ] . V_3 , V_36 [ V_8 ] . V_79 ) ;
if ( V_7 )
goto V_19;
}
V_33 -> V_96 . V_13 = 1 ;
V_33 -> V_96 . V_97 [ 0 ] . V_98 = V_99 ;
V_33 -> V_100 . V_13 = 1 ;
V_33 -> V_100 . V_97 [ 0 ] . V_98 = V_99 ;
V_33 -> V_101 . V_13 = 1 ;
V_33 -> V_101 . V_97 [ 0 ] . V_98 = V_99 ;
V_33 -> V_102 . V_13 = 1 ;
V_33 -> V_102 . V_97 [ 0 ] . V_98 = V_99 ;
V_2 -> V_103 = false ;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
F_4 ( & V_6 -> V_2 , L_3 ) ;
V_2 -> V_103 = true ;
V_2 -> V_104 = 0 ;
V_7 = F_5 ( V_2 , V_78 , 0x1 ) ;
if ( V_7 )
goto V_19;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_4 ( & V_6 -> V_2 , L_3 ) ;
V_106 -> V_107 = 1000 ;
V_106 -> V_108 = V_23 -> V_109 . V_110 . V_111 * 2 ;
V_106 -> V_112 = ( V_23 -> V_109 . V_110 . V_111 * 2 ) + 1 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_32 * V_33 = & V_23 -> V_34 ;
int V_7 , V_8 , V_113 ;
T_4 V_114 , V_115 , V_116 ;
T_1 V_117 , V_118 ;
static T_3 V_119 [ 3 ] [ 32 ] = {
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
F_4 ( & V_6 -> V_2 , L_5 ,
V_33 -> V_120 , V_33 -> V_121 , V_33 -> V_122 ) ;
if ( V_23 -> V_109 . V_123 . V_124 )
V_23 -> V_109 . V_123 . V_124 ( V_23 ) ;
if ( V_23 -> V_109 . V_123 . V_125 ) {
T_1 V_24 ;
V_7 = V_23 -> V_109 . V_123 . V_125 ( V_23 , & V_24 ) ;
if ( V_7 )
goto V_19;
V_7 = F_7 ( V_23 , V_24 ) ;
if ( V_7 )
goto V_19;
}
switch ( V_33 -> V_121 ) {
case 6000000 :
V_8 = 0 ;
V_114 = 48000000 ;
break;
case 7000000 :
V_8 = 1 ;
V_114 = 56000000 ;
break;
case 8000000 :
V_8 = 2 ;
V_114 = 64000000 ;
break;
default:
F_14 ( & V_6 -> V_2 , L_6 ,
V_33 -> V_121 ) ;
V_7 = - V_95 ;
goto V_19;
}
for ( V_113 = 0 ; V_113 < sizeof( V_119 [ 0 ] ) ; V_113 ++ ) {
V_7 = F_6 ( V_2 -> V_18 ,
0x11c + V_113 , & V_119 [ V_8 ] [ V_113 ] , 1 ) ;
if ( V_7 )
goto V_19;
}
V_115 = V_2 -> V_28 -> V_29 * 7 ;
V_115 *= 0x400000 ;
V_115 = F_8 ( V_115 , V_114 ) ;
V_117 = V_115 & 0x3ffffff ;
V_7 = F_5 ( V_2 , V_126 , V_117 ) ;
if ( V_7 )
goto V_19;
V_115 = V_114 << 20 ;
V_116 = V_2 -> V_28 -> V_29 * 7 ;
V_115 = F_8 ( V_115 , V_116 ) ;
V_115 = - V_115 ;
V_118 = V_115 & 0xfffff ;
V_7 = F_5 ( V_2 , V_127 , V_118 ) ;
if ( V_7 )
goto V_19;
V_7 = F_5 ( V_2 , V_78 , 0x1 ) ;
if ( V_7 )
goto V_19;
V_7 = F_5 ( V_2 , V_78 , 0x0 ) ;
if ( V_7 )
goto V_19;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_15 ( struct V_22 * V_23 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
T_3 V_128 [ 3 ] ;
if ( V_2 -> V_103 )
return 0 ;
V_7 = F_3 ( V_2 -> V_18 , 0x33c , V_128 , 2 ) ;
if ( V_7 )
goto V_19;
V_7 = F_3 ( V_2 -> V_18 , 0x351 , & V_128 [ 2 ] , 1 ) ;
if ( V_7 )
goto V_19;
F_4 ( & V_6 -> V_2 , L_7 , 3 , V_128 ) ;
switch ( ( V_128 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_33 -> V_129 = V_130 ;
break;
case 1 :
V_33 -> V_129 = V_131 ;
break;
case 2 :
V_33 -> V_129 = V_132 ;
break;
}
switch ( ( V_128 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_33 -> V_133 = V_134 ;
break;
case 1 :
V_33 -> V_133 = V_135 ;
}
switch ( ( V_128 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_33 -> V_136 = V_137 ;
break;
case 1 :
V_33 -> V_136 = V_138 ;
break;
case 2 :
V_33 -> V_136 = V_139 ;
break;
case 3 :
V_33 -> V_136 = V_140 ;
break;
}
switch ( ( V_128 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_33 -> V_141 = V_142 ;
break;
case 1 :
V_33 -> V_141 = V_143 ;
break;
case 2 :
V_33 -> V_141 = V_144 ;
break;
case 3 :
V_33 -> V_141 = V_145 ;
break;
}
switch ( ( V_128 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_33 -> V_146 = V_147 ;
break;
case 1 :
V_33 -> V_146 = V_148 ;
break;
case 2 :
V_33 -> V_146 = V_149 ;
break;
case 3 :
V_33 -> V_146 = V_150 ;
break;
case 4 :
V_33 -> V_146 = V_151 ;
break;
}
switch ( ( V_128 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_33 -> V_152 = V_147 ;
break;
case 1 :
V_33 -> V_152 = V_148 ;
break;
case 2 :
V_33 -> V_152 = V_149 ;
break;
case 3 :
V_33 -> V_152 = V_150 ;
break;
case 4 :
V_33 -> V_152 = V_151 ;
break;
}
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_16 ( struct V_22 * V_23 , enum V_104 * V_153 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_32 * V_33 = & V_23 -> V_34 ;
int V_7 ;
T_1 V_154 ( V_155 ) ;
T_3 V_156 , V_128 [ 2 ] ;
T_2 V_157 ;
F_4 ( & V_6 -> V_2 , L_3 ) ;
* V_153 = 0 ;
if ( V_2 -> V_103 )
return 0 ;
V_7 = F_1 ( V_2 , V_158 , & V_155 ) ;
if ( V_7 )
goto V_19;
if ( V_155 == 11 ) {
* V_153 |= V_159 | V_160 |
V_161 | V_162 | V_163 ;
} else if ( V_155 == 10 ) {
* V_153 |= V_159 | V_160 |
V_161 ;
}
V_2 -> V_104 = * V_153 ;
if ( V_2 -> V_104 & V_159 ) {
V_7 = F_3 ( V_2 -> V_18 , 0x305 , & V_156 , 1 ) ;
if ( V_7 )
goto V_19;
F_4 ( & V_6 -> V_2 , L_8 , V_156 ) ;
V_156 = ~ V_156 ;
V_157 = V_156 << 8 | V_156 << 0 ;
V_33 -> V_96 . V_97 [ 0 ] . V_98 = V_164 ;
V_33 -> V_96 . V_97 [ 0 ] . V_165 = V_157 ;
} else {
V_33 -> V_96 . V_97 [ 0 ] . V_98 = V_99 ;
}
if ( V_2 -> V_104 & V_161 ) {
unsigned V_141 , V_166 ;
#define F_17 3
#define F_18 4
static const T_1 V_167 [ F_17 ] [ F_18 ] = {
{ 85387325 , 85387325 , 85387325 , 85387325 } ,
{ 86676178 , 86676178 , 87167949 , 87795660 } ,
{ 87659938 , 87659938 , 87885178 , 88241743 } ,
} ;
V_7 = F_3 ( V_2 -> V_18 , 0x33c , & V_156 , 1 ) ;
if ( V_7 )
goto V_19;
V_166 = ( V_156 >> 2 ) & 0x03 ;
if ( V_166 > F_17 - 1 )
goto V_19;
V_141 = ( V_156 >> 4 ) & 0x07 ;
if ( V_141 > F_18 - 1 )
goto V_19;
V_7 = F_3 ( V_2 -> V_18 , 0x40c , V_128 , 2 ) ;
if ( V_7 )
goto V_19;
V_157 = V_128 [ 0 ] << 8 | V_128 [ 1 ] << 0 ;
if ( V_157 )
V_155 = ( V_167 [ V_166 ] [ V_141 ] -
F_19 ( V_157 ) ) / ( ( 1 << 24 ) / 10000 ) ;
else
V_155 = 0 ;
F_4 ( & V_6 -> V_2 , L_9 , V_157 ) ;
V_33 -> V_100 . V_97 [ 0 ] . V_98 = V_168 ;
V_33 -> V_100 . V_97 [ 0 ] . V_169 = V_155 ;
} else {
V_33 -> V_100 . V_97 [ 0 ] . V_98 = V_99 ;
}
if ( V_2 -> V_104 & V_163 ) {
V_7 = F_3 ( V_2 -> V_18 , 0x34e , V_128 , 2 ) ;
if ( V_7 )
goto V_19;
V_157 = V_128 [ 0 ] << 8 | V_128 [ 1 ] << 0 ;
V_2 -> V_101 += V_157 ;
V_2 -> V_102 += 1000000 ;
F_4 ( & V_6 -> V_2 , L_10 , V_157 ) ;
V_33 -> V_101 . V_97 [ 0 ] . V_98 = V_170 ;
V_33 -> V_101 . V_97 [ 0 ] . V_165 = V_2 -> V_101 ;
V_33 -> V_102 . V_97 [ 0 ] . V_98 = V_170 ;
V_33 -> V_102 . V_97 [ 0 ] . V_165 = V_2 -> V_102 ;
} else {
V_33 -> V_101 . V_97 [ 0 ] . V_98 = V_99 ;
V_33 -> V_102 . V_97 [ 0 ] . V_98 = V_99 ;
}
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_20 ( struct V_22 * V_23 , T_2 * V_171 )
{
struct V_32 * V_33 = & V_23 -> V_34 ;
if ( V_33 -> V_100 . V_97 [ 0 ] . V_98 == V_168 )
* V_171 = F_21 ( V_33 -> V_100 . V_97 [ 0 ] . V_169 , 100 ) ;
else
* V_171 = 0 ;
return 0 ;
}
static int F_22 ( struct V_22 * V_23 , T_1 * V_172 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
* V_172 = ( V_2 -> V_101 - V_2 -> V_173 ) ;
V_2 -> V_173 = V_2 -> V_101 ;
return 0 ;
}
static void F_23 ( struct V_174 * V_175 )
{
struct V_1 * V_2 = F_24 ( V_175 , struct V_1 , V_176 . V_175 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_25 ( V_2 -> V_18 , 0x101 , 0x08 , 0x00 ) ;
if ( V_7 )
goto V_19;
return;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
}
static int F_26 ( struct V_177 * V_178 , T_1 V_179 )
{
struct V_1 * V_2 = F_27 ( V_178 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
F_28 ( & V_2 -> V_176 ) ;
V_7 = F_25 ( V_2 -> V_18 , 0x101 , 0x08 , 0x08 ) ;
if ( V_7 )
goto V_19;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_29 ( struct V_177 * V_178 , T_1 V_179 )
{
struct V_1 * V_2 = F_27 ( V_178 ) ;
F_30 ( & V_2 -> V_176 , F_31 ( 100 ) ) ;
return 0 ;
}
static bool F_32 ( struct V_180 * V_2 , unsigned int V_3 )
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
static struct V_22 * F_33 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_34 ( V_6 ) ;
F_4 ( & V_6 -> V_2 , L_3 ) ;
return & V_2 -> V_23 ;
}
static struct V_181 * F_35 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_34 ( V_6 ) ;
F_4 ( & V_6 -> V_2 , L_3 ) ;
return V_2 -> V_178 -> V_182 [ 0 ] ;
}
static int F_36 ( struct V_5 * V_6 , bool V_183 )
{
struct V_1 * V_2 = F_34 ( V_6 ) ;
int V_7 ;
F_4 ( & V_6 -> V_2 , L_11 , V_183 ) ;
if ( V_183 ) {
V_7 = F_5 ( V_2 , V_78 , 0x0 ) ;
if ( V_7 )
goto V_19;
V_7 = F_6 ( V_2 -> V_18 , 0x10c , L_12 , 2 ) ;
if ( V_7 )
goto V_19;
V_7 = F_5 ( V_2 , V_53 , 0x1 ) ;
if ( V_7 )
goto V_19;
V_7 = F_6 ( V_2 -> V_18 , 0x0bc , L_13 , 1 ) ;
if ( V_7 )
goto V_19;
V_7 = F_6 ( V_2 -> V_18 , 0x192 , L_14 , 3 ) ;
if ( V_7 )
goto V_19;
} else {
V_7 = F_6 ( V_2 -> V_18 , 0x192 , L_15 , 3 ) ;
if ( V_7 )
goto V_19;
V_7 = F_6 ( V_2 -> V_18 , 0x0bc , L_16 , 1 ) ;
if ( V_7 )
goto V_19;
V_7 = F_5 ( V_2 , V_53 , 0x0 ) ;
if ( V_7 )
goto V_19;
V_7 = F_6 ( V_2 -> V_18 , 0x10c , L_17 , 2 ) ;
if ( V_7 )
goto V_19;
V_7 = F_5 ( V_2 , V_78 , 0x1 ) ;
if ( V_7 )
goto V_19;
}
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_37 ( struct V_22 * V_23 , int V_184 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
T_3 V_156 ;
F_4 ( & V_6 -> V_2 , L_18 , V_184 ) ;
if ( V_184 )
V_156 = 0x80 ;
else
V_156 = 0x00 ;
V_7 = F_25 ( V_2 -> V_18 , 0x061 , 0xc0 , V_156 ) ;
if ( V_7 )
goto V_19;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_38 ( struct V_22 * V_23 , T_3 V_185 , T_2 V_186 ,
int V_184 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
T_3 V_128 [ 4 ] ;
F_4 ( & V_6 -> V_2 , L_19 ,
V_185 , V_186 , V_184 ) ;
if ( V_186 > 0x1fff || V_185 > 32 )
return 0 ;
if ( V_184 )
F_39 ( V_185 , & V_2 -> V_187 ) ;
else
F_40 ( V_185 , & V_2 -> V_187 ) ;
V_128 [ 0 ] = ( V_2 -> V_187 >> 0 ) & 0xff ;
V_128 [ 1 ] = ( V_2 -> V_187 >> 8 ) & 0xff ;
V_128 [ 2 ] = ( V_2 -> V_187 >> 16 ) & 0xff ;
V_128 [ 3 ] = ( V_2 -> V_187 >> 24 ) & 0xff ;
V_7 = F_6 ( V_2 -> V_18 , 0x062 , V_128 , 4 ) ;
if ( V_7 )
goto V_19;
V_128 [ 0 ] = ( V_186 >> 8 ) & 0xff ;
V_128 [ 1 ] = ( V_186 >> 0 ) & 0xff ;
V_7 = F_6 ( V_2 -> V_18 , 0x066 + 2 * V_185 , V_128 , 2 ) ;
if ( V_7 )
goto V_19;
return 0 ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_41 ( struct V_5 * V_6 ,
const struct V_188 * V_189 )
{
struct V_190 * V_28 = V_6 -> V_2 . V_191 ;
struct V_181 * V_192 = V_6 -> V_182 ;
struct V_1 * V_2 ;
int V_7 ;
T_3 V_155 ;
static const struct V_193 V_193 [] = {
{
. V_194 = 0x00 ,
. V_195 = 0xff ,
. V_196 = 0 ,
. V_197 = 0 ,
. V_198 = 0x100 ,
. V_199 = 0 * 0x100 ,
. V_200 = 5 * 0x100 ,
} ,
} ;
F_4 ( & V_6 -> V_2 , L_3 ) ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_201 ) ;
if ( V_2 == NULL ) {
V_7 = - V_202 ;
goto V_19;
}
F_43 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_28 = V_6 -> V_2 . V_191 ;
V_2 -> V_103 = true ;
F_44 ( & V_2 -> V_176 , F_23 ) ;
V_2 -> V_203 . V_204 = 8 ,
V_2 -> V_203 . V_205 = 8 ,
V_2 -> V_203 . V_206 = F_32 ,
V_2 -> V_203 . V_207 = 5 * 0x100 ,
V_2 -> V_203 . V_208 = V_193 ,
V_2 -> V_203 . V_209 = F_10 ( V_193 ) ,
V_2 -> V_203 . V_210 = V_211 ,
V_2 -> V_18 = F_45 ( V_6 , & V_2 -> V_203 ) ;
if ( F_46 ( V_2 -> V_18 ) ) {
V_7 = F_47 ( V_2 -> V_18 ) ;
goto V_212;
}
V_7 = F_3 ( V_2 -> V_18 , 0x000 , & V_155 , 1 ) ;
if ( V_7 )
goto V_213;
V_2 -> V_178 = F_48 ( V_192 , & V_192 -> V_2 , 1 , 0 , V_214 ,
F_26 , F_29 ) ;
if ( ! V_2 -> V_178 ) {
V_7 = - V_202 ;
goto V_213;
}
V_2 -> V_178 -> V_215 = V_2 ;
V_7 = F_49 ( V_2 -> V_178 , 0 , 0 , 0 ) ;
if ( V_7 )
goto V_213;
memcpy ( & V_2 -> V_23 . V_109 , & V_216 , sizeof( struct V_217 ) ) ;
V_2 -> V_23 . V_25 = V_2 ;
V_28 -> V_218 = F_33 ;
V_28 -> V_219 = F_35 ;
V_28 -> V_220 = F_36 ;
V_28 -> V_221 = F_38 ;
V_28 -> V_222 = F_37 ;
V_28 -> V_18 = V_2 -> V_18 ;
F_50 ( & V_6 -> V_2 , L_20 ) ;
return 0 ;
V_213:
F_51 ( V_2 -> V_18 ) ;
V_212:
F_52 ( V_2 ) ;
V_19:
F_4 ( & V_6 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_34 ( V_6 ) ;
F_4 ( & V_6 -> V_2 , L_3 ) ;
F_54 ( & V_2 -> V_176 ) ;
F_55 ( V_2 -> V_178 ) ;
F_51 ( V_2 -> V_18 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
