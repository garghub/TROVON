static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ 1 + V_5 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = 1 + V_5 ,
. V_7 = V_7 ,
}
} ;
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_1 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = V_18 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_3 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_19 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
if ( V_19 != V_2 -> V_19 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_19 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_19 = V_19 ;
}
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_19 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
if ( V_19 != V_2 -> V_19 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_19 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_19 = V_19 ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_19 , T_1 * V_4 )
{
return F_6 ( V_2 , V_3 , V_19 , V_4 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
T_1 V_20 ;
T_1 V_21 , V_22 ;
T_1 V_19 ;
T_1 V_23 [ 4 ] ;
T_2 V_24 ;
int V_25 ;
T_1 V_5 ;
T_2 V_26 ;
V_20 = V_27 [ V_3 ] . V_28 ;
V_21 = V_27 [ V_3 ] . V_21 ;
V_22 = V_27 [ V_3 ] . V_22 ;
V_19 = V_27 [ V_3 ] . V_19 ;
V_5 = ( V_21 >> 3 ) + 1 ;
V_26 = F_9 ( V_21 - V_22 ) ;
V_6 = F_6 ( V_2 , V_20 , V_19 , & V_23 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_29;
V_24 = 0 ;
for ( V_25 = 0 ; V_25 < V_5 ; V_25 ++ )
V_24 |= V_23 [ V_25 ] << ( ( V_5 - 1 - V_25 ) * 8 ) ;
* V_4 = ( V_24 >> V_22 ) & V_26 ;
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
int V_6 , V_25 ;
T_1 V_5 ;
T_1 V_20 ;
T_1 V_21 , V_22 ;
T_1 V_19 ;
T_2 V_26 ;
T_1 V_23 [ 4 ] ;
T_1 V_31 [ 4 ] ;
T_2 V_24 ;
T_2 V_32 ;
V_20 = V_27 [ V_3 ] . V_28 ;
V_21 = V_27 [ V_3 ] . V_21 ;
V_22 = V_27 [ V_3 ] . V_22 ;
V_19 = V_27 [ V_3 ] . V_19 ;
V_5 = ( V_21 >> 3 ) + 1 ;
V_26 = F_9 ( V_21 - V_22 ) ;
V_6 = F_6 ( V_2 , V_20 , V_19 , & V_23 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_29;
V_24 = 0 ;
for ( V_25 = 0 ; V_25 < V_5 ; V_25 ++ )
V_24 |= V_23 [ V_25 ] << ( ( V_5 - 1 - V_25 ) * 8 ) ;
V_32 = V_24 & ~ ( V_26 << V_22 ) ;
V_32 |= ( ( V_4 & V_26 ) << V_22 ) ;
for ( V_25 = 0 ; V_25 < V_5 ; V_25 ++ )
V_31 [ V_25 ] = ( V_32 >> ( ( V_5 - 1 - V_25 ) * 8 ) ) & 0xff ;
V_6 = F_5 ( V_2 , V_20 , V_19 , & V_31 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_29;
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_33 * V_34 , int V_35 )
{
int V_6 ;
struct V_1 * V_2 = V_34 -> V_36 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_30 , V_35 ) ;
if ( V_2 -> V_37 == V_35 )
return 0 ;
V_6 = F_11 ( V_2 , V_38 , ( V_35 ? 0x1 : 0x0 ) ) ;
if ( V_6 )
goto V_29;
V_2 -> V_37 = V_35 ;
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
int V_25 , V_6 , V_5 ;
T_1 V_39 ;
T_3 V_40 ;
const struct V_41 * V_42 ;
struct V_41 V_43 [] = {
{ V_44 , 0x1 } ,
{ V_45 , 0x1 } ,
{ V_46 , 0x2800 } ,
{ V_47 , 0x10 } ,
{ V_48 , 0x20 } ,
{ V_49 , 0x20 } ,
{ V_50 , 0x40 } ,
{ V_51 , 0x22 } ,
{ V_52 , 0x32 } ,
{ V_53 , 0x37 } ,
{ V_54 , 0x39 } ,
{ V_55 , 0x0 } ,
{ V_56 , 0x0 } ,
{ V_57 , 0x2a } ,
{ V_58 , 0x6 } ,
{ V_59 , 0x0 } ,
{ V_60 , 0x8 } ,
{ V_61 , 0x8 } ,
{ V_62 , 0x4 } ,
{ V_63 , 0xb0 } ,
{ V_64 , 0x78 } ,
{ V_65 , 0x28 } ,
{ V_66 , 0x59 } ,
{ V_67 , 0x83 } ,
{ V_68 , 0xd4 } ,
{ V_69 , 0x65 } ,
{ V_70 , 0x43 } ,
{ V_71 , 0x1 } ,
{ V_72 , 0x4 } ,
{ V_73 , 0x7 } ,
{ V_74 , 0xa } ,
{ V_75 , 0x1 } ,
{ V_76 , 0x0 } ,
{ V_60 , 0x9 } ,
{ V_61 , 0x9 } ,
{ V_77 , 0x0 } ,
{ V_78 , 0x0 } ,
{ V_79 , 0x4 } ,
{ V_80 , 0x7 } ,
{ V_81 , 0x6 } ,
{ V_82 , 0x5 } ,
{ V_83 , 0x1 } ,
{ V_84 , 0x0 } ,
} ;
F_10 ( & V_2 -> V_14 -> V_15 , L_6 , V_30 ) ;
V_39 = ( V_2 -> V_11 . V_85 == 0 ? 0x1 : 0x0 ) ;
V_40 = V_2 -> V_11 . V_85 % V_2 -> V_11 . V_86 ;
V_40 *= 0x400000 ;
V_40 = F_14 ( V_40 , V_2 -> V_11 . V_86 ) ;
V_40 = V_40 & 0x3fffff ;
for ( V_25 = 0 ; V_25 < F_15 ( V_43 ) ; V_25 ++ ) {
V_6 = F_11 ( V_2 , V_43 [ V_25 ] . V_3 ,
V_43 [ V_25 ] . V_87 ) ;
if ( V_6 )
goto V_29;
}
F_10 ( & V_2 -> V_14 -> V_15 , L_7 ,
V_30 , V_2 -> V_11 . V_88 ) ;
switch ( V_2 -> V_11 . V_88 ) {
case V_89 :
case V_90 :
V_5 = F_15 ( V_91 ) ;
V_42 = V_91 ;
break;
case V_92 :
V_5 = F_15 ( V_93 ) ;
V_42 = V_93 ;
break;
case V_94 :
V_5 = F_15 ( V_95 ) ;
V_42 = V_95 ;
break;
default:
V_6 = - V_96 ;
goto V_29;
}
for ( V_25 = 0 ; V_25 < V_5 ; V_25 ++ ) {
V_6 = F_11 ( V_2 , V_42 [ V_25 ] . V_3 , V_42 [ V_25 ] . V_87 ) ;
if ( V_6 )
goto V_29;
}
V_6 = F_11 ( V_2 , V_97 , V_39 ) ;
if ( V_6 )
goto V_29;
V_6 = F_11 ( V_2 , V_98 , V_40 ) ;
if ( V_6 )
goto V_29;
V_2 -> V_99 = false ;
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_6 , V_30 ) ;
V_2 -> V_99 = true ;
return 0 ;
}
static int F_17 ( struct V_33 * V_34 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_6 , V_30 ) ;
V_101 -> V_102 = 1000 ;
V_101 -> V_103 = V_34 -> V_104 . V_105 . V_106 * 2 ;
V_101 -> V_107 = ( V_34 -> V_104 . V_105 . V_106 * 2 ) + 1 ;
return 0 ;
}
static int F_18 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
struct V_108 * V_109 = & V_34 -> V_110 ;
int V_6 , V_25 , V_111 ;
T_3 V_112 , V_113 , V_114 ;
T_2 V_115 , V_116 ;
static T_1 V_117 [ 3 ] [ 32 ] = {
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
F_10 ( & V_2 -> V_14 -> V_15 , L_8 \
L_9 , V_30 , V_109 -> V_118 ,
V_109 -> V_119 , V_109 -> V_120 ) ;
if ( V_34 -> V_104 . V_121 . V_122 )
V_34 -> V_104 . V_121 . V_122 ( V_34 ) ;
switch ( V_109 -> V_119 ) {
case 6000000 :
V_25 = 0 ;
V_112 = 48000000 ;
break;
case 7000000 :
V_25 = 1 ;
V_112 = 56000000 ;
break;
case 8000000 :
V_25 = 2 ;
V_112 = 64000000 ;
break;
default:
F_10 ( & V_2 -> V_14 -> V_15 , L_10 , V_30 ) ;
return - V_96 ;
}
for ( V_111 = 0 ; V_111 < sizeof( V_117 [ 0 ] ) ; V_111 ++ ) {
V_6 = F_5 ( V_2 , 0x1c + V_111 , 1 , & V_117 [ V_25 ] [ V_111 ] , 1 ) ;
if ( V_6 )
goto V_29;
}
V_113 = V_2 -> V_11 . V_86 * 7 ;
V_113 *= 0x400000 ;
V_113 = F_14 ( V_113 , V_112 ) ;
V_115 = V_113 & 0x3ffffff ;
V_6 = F_11 ( V_2 , V_123 , V_115 ) ;
if ( V_6 )
goto V_29;
V_113 = V_112 << 20 ;
V_114 = V_2 -> V_11 . V_86 * 7 ;
V_113 = F_14 ( V_113 , V_114 ) ;
V_113 = - V_113 ;
V_116 = V_113 & 0xfffff ;
V_6 = F_11 ( V_2 , V_124 , V_116 ) ;
if ( V_6 )
goto V_29;
V_6 = F_11 ( V_2 , V_125 , 0x1 ) ;
if ( V_6 )
goto V_29;
V_6 = F_11 ( V_2 , V_125 , 0x0 ) ;
if ( V_6 )
goto V_29;
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
struct V_108 * V_109 = & V_34 -> V_110 ;
int V_6 ;
T_1 V_7 [ 3 ] ;
if ( V_2 -> V_99 )
return 0 ;
V_6 = F_6 ( V_2 , 0x3c , 3 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_6 = F_7 ( V_2 , 0x51 , 3 , & V_7 [ 2 ] ) ;
if ( V_6 )
goto V_29;
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_30 , 3 , V_7 ) ;
switch ( ( V_7 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_109 -> V_126 = V_127 ;
break;
case 1 :
V_109 -> V_126 = V_128 ;
break;
case 2 :
V_109 -> V_126 = V_129 ;
break;
}
switch ( ( V_7 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_109 -> V_130 = V_131 ;
break;
case 1 :
V_109 -> V_130 = V_132 ;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_109 -> V_133 = V_134 ;
break;
case 1 :
V_109 -> V_133 = V_135 ;
break;
case 2 :
V_109 -> V_133 = V_136 ;
break;
case 3 :
V_109 -> V_133 = V_137 ;
break;
}
switch ( ( V_7 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_109 -> V_138 = V_139 ;
break;
case 1 :
V_109 -> V_138 = V_140 ;
break;
case 2 :
V_109 -> V_138 = V_141 ;
break;
case 3 :
V_109 -> V_138 = V_142 ;
break;
}
switch ( ( V_7 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_109 -> V_143 = V_144 ;
break;
case 1 :
V_109 -> V_143 = V_145 ;
break;
case 2 :
V_109 -> V_143 = V_146 ;
break;
case 3 :
V_109 -> V_143 = V_147 ;
break;
case 4 :
V_109 -> V_143 = V_148 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_109 -> V_149 = V_144 ;
break;
case 1 :
V_109 -> V_149 = V_145 ;
break;
case 2 :
V_109 -> V_149 = V_146 ;
break;
case 3 :
V_109 -> V_149 = V_147 ;
break;
case 4 :
V_109 -> V_149 = V_148 ;
break;
}
return 0 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_33 * V_34 , T_4 * V_150 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
int V_6 ;
T_2 V_151 ;
* V_150 = 0 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_6 , V_30 ) ;
if ( V_2 -> V_99 )
return 0 ;
V_6 = F_8 ( V_2 , V_152 , & V_151 ) ;
if ( V_6 )
goto V_29;
if ( V_151 == 11 ) {
* V_150 |= V_153 | V_154 |
V_155 | V_156 | V_157 ;
}
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_33 * V_34 , T_5 * V_158 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
int V_6 , V_138 , V_159 ;
T_1 V_7 [ 2 ] , V_151 ;
T_5 V_160 ;
#define F_22 3
#define F_23 4
static const T_2 V_161 [ F_22 ] [ F_23 ] = {
{ 85387325 , 85387325 , 85387325 , 85387325 } ,
{ 86676178 , 86676178 , 87167949 , 87795660 } ,
{ 87659938 , 87659938 , 87885178 , 88241743 } ,
} ;
V_6 = F_7 ( V_2 , 0x3c , 3 , & V_151 ) ;
if ( V_6 )
goto V_29;
V_159 = ( V_151 >> 2 ) & 0x03 ;
if ( V_159 > F_22 - 1 )
goto V_29;
V_138 = ( V_151 >> 4 ) & 0x07 ;
if ( V_138 > F_23 - 1 )
goto V_29;
V_6 = F_6 ( V_2 , 0x0c , 4 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_160 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
if ( V_160 )
* V_158 = ( V_161 [ V_159 ] [ V_138 ] -
F_24 ( V_160 ) ) / ( ( 1 << 24 ) / 100 ) ;
else
* V_158 = 0 ;
return 0 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_25 ( struct V_33 * V_34 , T_2 * V_162 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
V_6 = F_6 ( V_2 , 0x4e , 3 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
* V_162 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return 0 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static void F_26 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_6 , V_30 ) ;
F_27 ( V_2 ) ;
}
struct V_33 * F_28 ( const struct V_163 * V_11 ,
struct V_164 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_6 = 0 ;
T_1 V_151 ;
F_10 ( & V_14 -> V_15 , L_6 , V_30 ) ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_165 ) ;
if ( V_2 == NULL )
goto V_29;
V_2 -> V_14 = V_14 ;
V_2 -> V_88 = V_11 -> V_88 ;
memcpy ( & V_2 -> V_11 , V_11 , sizeof( struct V_163 ) ) ;
V_6 = F_7 ( V_2 , 0x00 , 0x0 , & V_151 ) ;
if ( V_6 )
goto V_29;
memcpy ( & V_2 -> V_34 . V_104 , & V_166 , sizeof( struct V_167 ) ) ;
V_2 -> V_34 . V_36 = V_2 ;
V_2 -> V_99 = true ;
return & V_2 -> V_34 ;
V_29:
F_10 ( & V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
F_27 ( V_2 ) ;
return NULL ;
}
