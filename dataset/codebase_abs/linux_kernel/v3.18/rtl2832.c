static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ V_8 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = 1 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( 1 + V_5 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_1 ,
V_17 , V_3 , V_5 ) ;
return - V_18 ;
}
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_19 , V_10 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_2 ,
V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_20 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = V_21 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_3 ( V_2 -> V_19 , V_10 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_3 ,
V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_20 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_22 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
if ( V_22 != V_2 -> V_22 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_22 = V_22 ;
}
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_22 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
if ( V_22 != V_2 -> V_22 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_22 = V_22 ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_22 , T_1 * V_4 )
{
return F_6 ( V_2 , V_3 , V_22 , V_4 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
T_1 V_23 ;
T_1 V_24 , V_25 ;
T_1 V_22 ;
T_1 V_26 [ 4 ] ;
T_2 V_27 ;
int V_28 ;
T_1 V_5 ;
T_2 V_29 ;
V_23 = V_30 [ V_3 ] . V_31 ;
V_24 = V_30 [ V_3 ] . V_24 ;
V_25 = V_30 [ V_3 ] . V_25 ;
V_22 = V_30 [ V_3 ] . V_22 ;
V_5 = ( V_24 >> 3 ) + 1 ;
V_29 = F_9 ( V_24 - V_25 ) ;
V_6 = F_6 ( V_2 , V_23 , V_22 , & V_26 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_32;
V_27 = 0 ;
for ( V_28 = 0 ; V_28 < V_5 ; V_28 ++ )
V_27 |= V_26 [ V_28 ] << ( ( V_5 - 1 - V_28 ) * 8 ) ;
* V_4 = ( V_27 >> V_25 ) & V_29 ;
return V_6 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
int V_6 , V_28 ;
T_1 V_5 ;
T_1 V_23 ;
T_1 V_24 , V_25 ;
T_1 V_22 ;
T_2 V_29 ;
T_1 V_26 [ 4 ] ;
T_1 V_34 [ 4 ] ;
T_2 V_27 ;
T_2 V_35 ;
V_23 = V_30 [ V_3 ] . V_31 ;
V_24 = V_30 [ V_3 ] . V_24 ;
V_25 = V_30 [ V_3 ] . V_25 ;
V_22 = V_30 [ V_3 ] . V_22 ;
V_5 = ( V_24 >> 3 ) + 1 ;
V_29 = F_9 ( V_24 - V_25 ) ;
V_6 = F_6 ( V_2 , V_23 , V_22 , & V_26 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_32;
V_27 = 0 ;
for ( V_28 = 0 ; V_28 < V_5 ; V_28 ++ )
V_27 |= V_26 [ V_28 ] << ( ( V_5 - 1 - V_28 ) * 8 ) ;
V_35 = V_27 & ~ ( V_29 << V_25 ) ;
V_35 |= ( ( V_4 & V_29 ) << V_25 ) ;
for ( V_28 = 0 ; V_28 < V_5 ; V_28 ++ )
V_34 [ V_28 ] = ( V_35 >> ( ( V_5 - 1 - V_28 ) * 8 ) ) & 0xff ;
V_6 = F_5 ( V_2 , V_23 , V_22 , & V_34 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_32;
return V_6 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_36 * V_37 , int V_38 )
{
int V_6 ;
struct V_1 * V_2 = V_37 -> V_39 ;
F_10 ( & V_2 -> V_15 -> V_16 , L_5 , V_33 , V_38 ) ;
if ( V_2 -> V_40 == V_38 )
return 0 ;
V_6 = F_11 ( V_2 , V_41 , ( V_38 ? 0x1 : 0x0 ) ) ;
if ( V_6 )
goto V_32;
V_2 -> V_40 = V_38 ;
return V_6 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_36 * V_37 , T_2 V_42 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
int V_6 ;
T_3 V_43 ;
T_1 V_44 = ( V_42 == 0 ? 0x1 : 0x0 ) ;
V_43 = V_42 % V_2 -> V_12 . V_45 ;
V_43 *= 0x400000 ;
V_43 = F_14 ( V_43 , V_2 -> V_12 . V_45 ) ;
V_43 = - V_43 ;
V_43 = V_43 & 0x3fffff ;
F_10 ( & V_2 -> V_15 -> V_16 , L_6 ,
V_33 , V_42 , ( unsigned ) V_43 ) ;
V_6 = F_11 ( V_2 , V_46 , V_44 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_11 ( V_2 , V_47 , V_43 ) ;
return V_6 ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
const struct V_48 * V_49 ;
int V_28 , V_6 , V_5 ;
struct V_48 V_50 [] = {
{ V_51 , 0x1 } ,
{ V_52 , 0x1 } ,
{ V_53 , 0x2800 } ,
{ V_54 , 0x10 } ,
{ V_55 , 0x20 } ,
{ V_56 , 0x20 } ,
{ V_57 , 0x40 } ,
{ V_58 , 0x22 } ,
{ V_59 , 0x32 } ,
{ V_60 , 0x37 } ,
{ V_61 , 0x39 } ,
{ V_62 , 0x0 } ,
{ V_63 , 0x0 } ,
{ V_64 , 0x2a } ,
{ V_65 , 0x6 } ,
{ V_66 , 0x0 } ,
{ V_67 , 0x8 } ,
{ V_68 , 0x8 } ,
{ V_69 , 0x4 } ,
{ V_70 , 0xb0 } ,
{ V_71 , 0x78 } ,
{ V_72 , 0x28 } ,
{ V_73 , 0x59 } ,
{ V_74 , 0x83 } ,
{ V_75 , 0xd4 } ,
{ V_76 , 0x65 } ,
{ V_77 , 0x43 } ,
{ V_78 , 0x1 } ,
{ V_79 , 0x4 } ,
{ V_80 , 0x7 } ,
{ V_81 , 0xa } ,
{ V_82 , 0x1 } ,
{ V_83 , 0x0 } ,
{ V_67 , 0x9 } ,
{ V_68 , 0x9 } ,
{ V_84 , 0x0 } ,
{ V_85 , 0x0 } ,
{ V_86 , 0x4 } ,
{ V_87 , 0x7 } ,
{ V_88 , 0x6 } ,
{ V_89 , 0x5 } ,
{ V_90 , 0x1 } ,
} ;
F_10 ( & V_2 -> V_15 -> V_16 , L_7 , V_33 ) ;
for ( V_28 = 0 ; V_28 < F_16 ( V_50 ) ; V_28 ++ ) {
V_6 = F_11 ( V_2 , V_50 [ V_28 ] . V_3 ,
V_50 [ V_28 ] . V_91 ) ;
if ( V_6 )
goto V_32;
}
F_10 ( & V_2 -> V_15 -> V_16 , L_8 ,
V_33 , V_2 -> V_12 . V_92 ) ;
switch ( V_2 -> V_12 . V_92 ) {
case V_93 :
case V_94 :
V_5 = F_16 ( V_95 ) ;
V_49 = V_95 ;
break;
case V_96 :
V_5 = F_16 ( V_97 ) ;
V_49 = V_97 ;
break;
case V_98 :
V_5 = F_16 ( V_99 ) ;
V_49 = V_99 ;
break;
case V_100 :
case V_101 :
V_5 = F_16 ( V_102 ) ;
V_49 = V_102 ;
break;
default:
V_6 = - V_18 ;
goto V_32;
}
for ( V_28 = 0 ; V_28 < V_5 ; V_28 ++ ) {
V_6 = F_11 ( V_2 , V_49 [ V_28 ] . V_3 , V_49 [ V_28 ] . V_91 ) ;
if ( V_6 )
goto V_32;
}
#if 1
V_6 = F_11 ( V_2 , V_103 , 0x1 ) ;
if ( V_6 )
goto V_32;
V_6 = F_11 ( V_2 , V_103 , 0x0 ) ;
if ( V_6 )
goto V_32;
#endif
V_2 -> V_104 = false ;
return V_6 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
F_10 ( & V_2 -> V_15 -> V_16 , L_7 , V_33 ) ;
V_2 -> V_104 = true ;
return 0 ;
}
static int F_18 ( struct V_36 * V_37 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
F_10 ( & V_2 -> V_15 -> V_16 , L_7 , V_33 ) ;
V_106 -> V_107 = 1000 ;
V_106 -> V_108 = V_37 -> V_109 . V_110 . V_111 * 2 ;
V_106 -> V_112 = ( V_37 -> V_109 . V_110 . V_111 * 2 ) + 1 ;
return 0 ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_113 * V_114 = & V_37 -> V_115 ;
int V_6 , V_28 , V_116 ;
T_3 V_117 , V_118 , V_119 ;
T_2 V_120 , V_121 ;
static T_1 V_122 [ 3 ] [ 32 ] = {
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
F_10 ( & V_2 -> V_15 -> V_16 ,
L_9 ,
V_33 , V_114 -> V_123 , V_114 -> V_124 , V_114 -> V_125 ) ;
if ( V_37 -> V_109 . V_126 . V_127 )
V_37 -> V_109 . V_126 . V_127 ( V_37 ) ;
if ( V_37 -> V_109 . V_126 . V_128 ) {
T_2 V_42 ;
V_6 = V_37 -> V_109 . V_126 . V_128 ( V_37 , & V_42 ) ;
if ( V_6 )
goto V_32;
V_6 = F_13 ( V_37 , V_42 ) ;
if ( V_6 )
goto V_32;
}
switch ( V_114 -> V_124 ) {
case 6000000 :
V_28 = 0 ;
V_117 = 48000000 ;
break;
case 7000000 :
V_28 = 1 ;
V_117 = 56000000 ;
break;
case 8000000 :
V_28 = 2 ;
V_117 = 64000000 ;
break;
default:
F_10 ( & V_2 -> V_15 -> V_16 , L_10 , V_33 ) ;
return - V_18 ;
}
for ( V_116 = 0 ; V_116 < sizeof( V_122 [ 0 ] ) ; V_116 ++ ) {
V_6 = F_5 ( V_2 , 0x1c + V_116 , 1 , & V_122 [ V_28 ] [ V_116 ] , 1 ) ;
if ( V_6 )
goto V_32;
}
V_118 = V_2 -> V_12 . V_45 * 7 ;
V_118 *= 0x400000 ;
V_118 = F_14 ( V_118 , V_117 ) ;
V_120 = V_118 & 0x3ffffff ;
V_6 = F_11 ( V_2 , V_129 , V_120 ) ;
if ( V_6 )
goto V_32;
V_118 = V_117 << 20 ;
V_119 = V_2 -> V_12 . V_45 * 7 ;
V_118 = F_14 ( V_118 , V_119 ) ;
V_118 = - V_118 ;
V_121 = V_118 & 0xfffff ;
V_6 = F_11 ( V_2 , V_130 , V_121 ) ;
if ( V_6 )
goto V_32;
V_6 = F_11 ( V_2 , V_103 , 0x1 ) ;
if ( V_6 )
goto V_32;
V_6 = F_11 ( V_2 , V_103 , 0x0 ) ;
if ( V_6 )
goto V_32;
return V_6 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_113 * V_114 = & V_37 -> V_115 ;
int V_6 ;
T_1 V_7 [ 3 ] ;
if ( V_2 -> V_104 )
return 0 ;
V_6 = F_6 ( V_2 , 0x3c , 3 , V_7 , 2 ) ;
if ( V_6 )
goto V_32;
V_6 = F_7 ( V_2 , 0x51 , 3 , & V_7 [ 2 ] ) ;
if ( V_6 )
goto V_32;
F_10 ( & V_2 -> V_15 -> V_16 , L_11 , V_33 , 3 , V_7 ) ;
switch ( ( V_7 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_114 -> V_131 = V_132 ;
break;
case 1 :
V_114 -> V_131 = V_133 ;
break;
case 2 :
V_114 -> V_131 = V_134 ;
break;
}
switch ( ( V_7 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_114 -> V_135 = V_136 ;
break;
case 1 :
V_114 -> V_135 = V_137 ;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_114 -> V_138 = V_139 ;
break;
case 1 :
V_114 -> V_138 = V_140 ;
break;
case 2 :
V_114 -> V_138 = V_141 ;
break;
case 3 :
V_114 -> V_138 = V_142 ;
break;
}
switch ( ( V_7 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_114 -> V_143 = V_144 ;
break;
case 1 :
V_114 -> V_143 = V_145 ;
break;
case 2 :
V_114 -> V_143 = V_146 ;
break;
case 3 :
V_114 -> V_143 = V_147 ;
break;
}
switch ( ( V_7 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_114 -> V_148 = V_149 ;
break;
case 1 :
V_114 -> V_148 = V_150 ;
break;
case 2 :
V_114 -> V_148 = V_151 ;
break;
case 3 :
V_114 -> V_148 = V_152 ;
break;
case 4 :
V_114 -> V_148 = V_153 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_114 -> V_154 = V_149 ;
break;
case 1 :
V_114 -> V_154 = V_150 ;
break;
case 2 :
V_114 -> V_154 = V_151 ;
break;
case 3 :
V_114 -> V_154 = V_152 ;
break;
case 4 :
V_114 -> V_154 = V_153 ;
break;
}
return 0 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_36 * V_37 , T_4 * V_155 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
int V_6 ;
T_2 V_156 ;
* V_155 = 0 ;
F_10 ( & V_2 -> V_15 -> V_16 , L_7 , V_33 ) ;
if ( V_2 -> V_104 )
return 0 ;
V_6 = F_8 ( V_2 , V_157 , & V_156 ) ;
if ( V_6 )
goto V_32;
if ( V_156 == 11 ) {
* V_155 |= V_158 | V_159 |
V_160 | V_161 | V_162 ;
}
return V_6 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_36 * V_37 , T_5 * V_163 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
int V_6 , V_143 , V_164 ;
T_1 V_7 [ 2 ] , V_156 ;
T_5 V_165 ;
#define F_23 3
#define F_24 4
static const T_2 V_166 [ F_23 ] [ F_24 ] = {
{ 85387325 , 85387325 , 85387325 , 85387325 } ,
{ 86676178 , 86676178 , 87167949 , 87795660 } ,
{ 87659938 , 87659938 , 87885178 , 88241743 } ,
} ;
V_6 = F_7 ( V_2 , 0x3c , 3 , & V_156 ) ;
if ( V_6 )
goto V_32;
V_164 = ( V_156 >> 2 ) & 0x03 ;
if ( V_164 > F_23 - 1 )
goto V_32;
V_143 = ( V_156 >> 4 ) & 0x07 ;
if ( V_143 > F_24 - 1 )
goto V_32;
V_6 = F_6 ( V_2 , 0x0c , 4 , V_7 , 2 ) ;
if ( V_6 )
goto V_32;
V_165 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
if ( V_165 )
* V_163 = ( V_166 [ V_164 ] [ V_143 ] -
F_25 ( V_165 ) ) / ( ( 1 << 24 ) / 100 ) ;
else
* V_163 = 0 ;
return 0 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static int F_26 ( struct V_36 * V_37 , T_2 * V_167 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
V_6 = F_6 ( V_2 , 0x4e , 3 , V_7 , 2 ) ;
if ( V_6 )
goto V_32;
* V_167 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return 0 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return V_6 ;
}
static void F_27 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
F_10 ( & V_2 -> V_15 -> V_16 , L_7 , V_33 ) ;
F_28 ( & V_2 -> V_168 ) ;
F_29 ( V_2 -> V_169 ) ;
F_29 ( V_2 -> V_19 ) ;
F_30 ( V_2 ) ;
}
static void F_31 ( struct V_170 * V_171 )
{
struct V_1 * V_2 = F_32 ( V_171 ,
struct V_1 , V_168 . V_171 ) ;
struct V_19 * V_172 = V_2 -> V_15 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_7 [ 0 ] = 0x00 ;
V_7 [ 1 ] = 0x01 ;
V_6 = F_33 ( V_172 , V_10 , 1 ) ;
if ( V_6 != 1 )
goto V_32;
V_2 -> V_22 = 1 ;
V_7 [ 0 ] = 0x01 ;
V_7 [ 1 ] = 0x10 ;
V_6 = F_33 ( V_172 , V_10 , 1 ) ;
if ( V_6 != 1 )
goto V_32;
V_2 -> V_40 = false ;
return;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return;
}
static int F_34 ( struct V_19 * V_172 , void * V_173 , T_2 V_174 )
{
struct V_1 * V_2 = V_173 ;
int V_6 ;
T_1 V_7 [ 2 ] , V_4 ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
struct V_9 V_175 [ 2 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = 1 ,
. V_7 = L_12 ,
} , {
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = V_21 ,
. V_5 = 1 ,
. V_7 = & V_4 ,
}
} ;
F_28 ( & V_2 -> V_168 ) ;
if ( V_2 -> V_40 == V_174 )
return 0 ;
V_7 [ 0 ] = 0x00 ;
V_7 [ 1 ] = 0x01 ;
V_6 = F_33 ( V_172 , V_10 , 1 ) ;
if ( V_6 != 1 )
goto V_32;
V_2 -> V_22 = 1 ;
V_6 = F_33 ( V_172 , V_175 , 2 ) ;
if ( V_6 != 2 )
goto V_32;
V_7 [ 0 ] = 0x01 ;
if ( V_174 == 1 )
V_7 [ 1 ] = 0x18 ;
else
V_7 [ 1 ] = 0x10 ;
V_6 = F_33 ( V_172 , V_10 , 1 ) ;
if ( V_6 != 1 )
goto V_32;
V_2 -> V_40 = V_174 ;
return 0 ;
V_32:
F_10 ( & V_2 -> V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
return - V_20 ;
}
static int F_35 ( struct V_19 * V_172 , void * V_173 ,
T_2 V_174 )
{
struct V_1 * V_2 = V_173 ;
F_36 ( & V_2 -> V_168 , F_37 ( 100 ) ) ;
return 0 ;
}
struct V_19 * F_38 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
return V_2 -> V_169 ;
}
struct V_19 * F_39 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
return V_2 -> V_19 ;
}
struct V_36 * F_40 ( const struct V_176 * V_12 ,
struct V_19 * V_15 )
{
struct V_1 * V_2 = NULL ;
int V_6 = 0 ;
T_1 V_156 ;
F_10 ( & V_15 -> V_16 , L_7 , V_33 ) ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_177 ) ;
if ( V_2 == NULL )
goto V_32;
V_2 -> V_15 = V_15 ;
V_2 -> V_92 = V_12 -> V_92 ;
memcpy ( & V_2 -> V_12 , V_12 , sizeof( struct V_176 ) ) ;
F_42 ( & V_2 -> V_168 , F_31 ) ;
V_2 -> V_19 = F_43 ( V_15 , & V_15 -> V_16 , V_2 , 0 , 0 , 0 ,
F_34 , NULL ) ;
if ( V_2 -> V_19 == NULL )
goto V_32;
V_6 = F_7 ( V_2 , 0x00 , 0x0 , & V_156 ) ;
if ( V_6 )
goto V_32;
V_2 -> V_169 = F_43 ( V_15 , & V_15 -> V_16 , V_2 ,
0 , 1 , 0 , F_34 , F_35 ) ;
if ( V_2 -> V_169 == NULL )
goto V_32;
memcpy ( & V_2 -> V_37 . V_109 , & V_178 , sizeof( struct V_179 ) ) ;
V_2 -> V_37 . V_39 = V_2 ;
V_2 -> V_104 = true ;
return & V_2 -> V_37 ;
V_32:
F_10 ( & V_15 -> V_16 , L_4 , V_33 , V_6 ) ;
if ( V_2 && V_2 -> V_19 )
F_29 ( V_2 -> V_19 ) ;
F_30 ( V_2 ) ;
return NULL ;
}
