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
static int F_13 ( struct V_33 * V_34 , T_2 V_39 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
int V_6 ;
T_3 V_40 ;
T_1 V_41 = ( V_39 == 0 ? 0x1 : 0x0 ) ;
V_40 = V_39 % V_2 -> V_11 . V_42 ;
V_40 *= 0x400000 ;
V_40 = F_14 ( V_40 , V_2 -> V_11 . V_42 ) ;
V_40 = - V_40 ;
V_40 = V_40 & 0x3fffff ;
F_10 ( & V_2 -> V_14 -> V_15 , L_6 ,
V_30 , V_39 , ( unsigned ) V_40 ) ;
V_6 = F_11 ( V_2 , V_43 , V_41 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_11 ( V_2 , V_44 , V_40 ) ;
return ( V_6 ) ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
const struct V_45 * V_46 ;
int V_25 , V_6 , V_5 ;
struct V_45 V_47 [] = {
{ V_48 , 0x1 } ,
{ V_49 , 0x1 } ,
{ V_50 , 0x2800 } ,
{ V_51 , 0x10 } ,
{ V_52 , 0x20 } ,
{ V_53 , 0x20 } ,
{ V_54 , 0x40 } ,
{ V_55 , 0x22 } ,
{ V_56 , 0x32 } ,
{ V_57 , 0x37 } ,
{ V_58 , 0x39 } ,
{ V_59 , 0x0 } ,
{ V_60 , 0x0 } ,
{ V_61 , 0x2a } ,
{ V_62 , 0x6 } ,
{ V_63 , 0x0 } ,
{ V_64 , 0x8 } ,
{ V_65 , 0x8 } ,
{ V_66 , 0x4 } ,
{ V_67 , 0xb0 } ,
{ V_68 , 0x78 } ,
{ V_69 , 0x28 } ,
{ V_70 , 0x59 } ,
{ V_71 , 0x83 } ,
{ V_72 , 0xd4 } ,
{ V_73 , 0x65 } ,
{ V_74 , 0x43 } ,
{ V_75 , 0x1 } ,
{ V_76 , 0x4 } ,
{ V_77 , 0x7 } ,
{ V_78 , 0xa } ,
{ V_79 , 0x1 } ,
{ V_80 , 0x0 } ,
{ V_64 , 0x9 } ,
{ V_65 , 0x9 } ,
{ V_81 , 0x0 } ,
{ V_82 , 0x0 } ,
{ V_83 , 0x4 } ,
{ V_84 , 0x7 } ,
{ V_85 , 0x6 } ,
{ V_86 , 0x5 } ,
{ V_87 , 0x1 } ,
} ;
F_10 ( & V_2 -> V_14 -> V_15 , L_7 , V_30 ) ;
for ( V_25 = 0 ; V_25 < F_16 ( V_47 ) ; V_25 ++ ) {
V_6 = F_11 ( V_2 , V_47 [ V_25 ] . V_3 ,
V_47 [ V_25 ] . V_88 ) ;
if ( V_6 )
goto V_29;
}
F_10 ( & V_2 -> V_14 -> V_15 , L_8 ,
V_30 , V_2 -> V_11 . V_89 ) ;
switch ( V_2 -> V_11 . V_89 ) {
case V_90 :
case V_91 :
V_5 = F_16 ( V_92 ) ;
V_46 = V_92 ;
break;
case V_93 :
V_5 = F_16 ( V_94 ) ;
V_46 = V_94 ;
break;
case V_95 :
V_5 = F_16 ( V_96 ) ;
V_46 = V_96 ;
break;
case V_97 :
V_5 = F_16 ( V_98 ) ;
V_46 = V_98 ;
break;
default:
V_6 = - V_99 ;
goto V_29;
}
for ( V_25 = 0 ; V_25 < V_5 ; V_25 ++ ) {
V_6 = F_11 ( V_2 , V_46 [ V_25 ] . V_3 , V_46 [ V_25 ] . V_88 ) ;
if ( V_6 )
goto V_29;
}
if ( ! V_34 -> V_100 . V_101 . V_102 ) {
V_6 = F_13 ( V_34 , V_2 -> V_11 . V_103 ) ;
if ( V_6 )
goto V_29;
}
#if 1
V_6 = F_11 ( V_2 , V_104 , 0x1 ) ;
if ( V_6 )
goto V_29;
V_6 = F_11 ( V_2 , V_104 , 0x0 ) ;
if ( V_6 )
goto V_29;
#endif
V_2 -> V_105 = false ;
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_7 , V_30 ) ;
V_2 -> V_105 = true ;
return 0 ;
}
static int F_18 ( struct V_33 * V_34 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_7 , V_30 ) ;
V_107 -> V_108 = 1000 ;
V_107 -> V_109 = V_34 -> V_100 . V_110 . V_111 * 2 ;
V_107 -> V_112 = ( V_34 -> V_100 . V_110 . V_111 * 2 ) + 1 ;
return 0 ;
}
static int F_19 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
struct V_113 * V_114 = & V_34 -> V_115 ;
int V_6 , V_25 , V_116 ;
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
F_10 ( & V_2 -> V_14 -> V_15 , L_9 \
L_10 , V_30 , V_114 -> V_123 ,
V_114 -> V_124 , V_114 -> V_125 ) ;
if ( V_34 -> V_100 . V_101 . V_126 )
V_34 -> V_100 . V_101 . V_126 ( V_34 ) ;
if ( V_34 -> V_100 . V_101 . V_102 ) {
T_2 V_39 ;
V_6 = V_34 -> V_100 . V_101 . V_102 ( V_34 , & V_39 ) ;
if ( V_6 )
goto V_29;
V_6 = F_13 ( V_34 , V_39 ) ;
if ( V_6 )
goto V_29;
}
switch ( V_114 -> V_124 ) {
case 6000000 :
V_25 = 0 ;
V_117 = 48000000 ;
break;
case 7000000 :
V_25 = 1 ;
V_117 = 56000000 ;
break;
case 8000000 :
V_25 = 2 ;
V_117 = 64000000 ;
break;
default:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_30 ) ;
return - V_99 ;
}
for ( V_116 = 0 ; V_116 < sizeof( V_122 [ 0 ] ) ; V_116 ++ ) {
V_6 = F_5 ( V_2 , 0x1c + V_116 , 1 , & V_122 [ V_25 ] [ V_116 ] , 1 ) ;
if ( V_6 )
goto V_29;
}
V_118 = V_2 -> V_11 . V_42 * 7 ;
V_118 *= 0x400000 ;
V_118 = F_14 ( V_118 , V_117 ) ;
V_120 = V_118 & 0x3ffffff ;
V_6 = F_11 ( V_2 , V_127 , V_120 ) ;
if ( V_6 )
goto V_29;
V_118 = V_117 << 20 ;
V_119 = V_2 -> V_11 . V_42 * 7 ;
V_118 = F_14 ( V_118 , V_119 ) ;
V_118 = - V_118 ;
V_121 = V_118 & 0xfffff ;
V_6 = F_11 ( V_2 , V_128 , V_121 ) ;
if ( V_6 )
goto V_29;
V_6 = F_11 ( V_2 , V_104 , 0x1 ) ;
if ( V_6 )
goto V_29;
V_6 = F_11 ( V_2 , V_104 , 0x0 ) ;
if ( V_6 )
goto V_29;
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
struct V_113 * V_114 = & V_34 -> V_115 ;
int V_6 ;
T_1 V_7 [ 3 ] ;
if ( V_2 -> V_105 )
return 0 ;
V_6 = F_6 ( V_2 , 0x3c , 3 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_6 = F_7 ( V_2 , 0x51 , 3 , & V_7 [ 2 ] ) ;
if ( V_6 )
goto V_29;
F_10 ( & V_2 -> V_14 -> V_15 , L_12 , V_30 , 3 , V_7 ) ;
switch ( ( V_7 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_114 -> V_129 = V_130 ;
break;
case 1 :
V_114 -> V_129 = V_131 ;
break;
case 2 :
V_114 -> V_129 = V_132 ;
break;
}
switch ( ( V_7 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_114 -> V_133 = V_134 ;
break;
case 1 :
V_114 -> V_133 = V_135 ;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_114 -> V_136 = V_137 ;
break;
case 1 :
V_114 -> V_136 = V_138 ;
break;
case 2 :
V_114 -> V_136 = V_139 ;
break;
case 3 :
V_114 -> V_136 = V_140 ;
break;
}
switch ( ( V_7 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_114 -> V_141 = V_142 ;
break;
case 1 :
V_114 -> V_141 = V_143 ;
break;
case 2 :
V_114 -> V_141 = V_144 ;
break;
case 3 :
V_114 -> V_141 = V_145 ;
break;
}
switch ( ( V_7 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_114 -> V_146 = V_147 ;
break;
case 1 :
V_114 -> V_146 = V_148 ;
break;
case 2 :
V_114 -> V_146 = V_149 ;
break;
case 3 :
V_114 -> V_146 = V_150 ;
break;
case 4 :
V_114 -> V_146 = V_151 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_114 -> V_152 = V_147 ;
break;
case 1 :
V_114 -> V_152 = V_148 ;
break;
case 2 :
V_114 -> V_152 = V_149 ;
break;
case 3 :
V_114 -> V_152 = V_150 ;
break;
case 4 :
V_114 -> V_152 = V_151 ;
break;
}
return 0 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_33 * V_34 , T_4 * V_153 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
int V_6 ;
T_2 V_154 ;
* V_153 = 0 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_7 , V_30 ) ;
if ( V_2 -> V_105 )
return 0 ;
V_6 = F_8 ( V_2 , V_155 , & V_154 ) ;
if ( V_6 )
goto V_29;
if ( V_154 == 11 ) {
* V_153 |= V_156 | V_157 |
V_158 | V_159 | V_160 ;
}
return V_6 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_33 * V_34 , T_5 * V_161 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
int V_6 , V_141 , V_162 ;
T_1 V_7 [ 2 ] , V_154 ;
T_5 V_163 ;
#define F_23 3
#define F_24 4
static const T_2 V_164 [ F_23 ] [ F_24 ] = {
{ 85387325 , 85387325 , 85387325 , 85387325 } ,
{ 86676178 , 86676178 , 87167949 , 87795660 } ,
{ 87659938 , 87659938 , 87885178 , 88241743 } ,
} ;
V_6 = F_7 ( V_2 , 0x3c , 3 , & V_154 ) ;
if ( V_6 )
goto V_29;
V_162 = ( V_154 >> 2 ) & 0x03 ;
if ( V_162 > F_23 - 1 )
goto V_29;
V_141 = ( V_154 >> 4 ) & 0x07 ;
if ( V_141 > F_24 - 1 )
goto V_29;
V_6 = F_6 ( V_2 , 0x0c , 4 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_163 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
if ( V_163 )
* V_161 = ( V_164 [ V_162 ] [ V_141 ] -
F_25 ( V_163 ) ) / ( ( 1 << 24 ) / 100 ) ;
else
* V_161 = 0 ;
return 0 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static int F_26 ( struct V_33 * V_34 , T_2 * V_165 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
V_6 = F_6 ( V_2 , 0x4e , 3 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
* V_165 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return 0 ;
V_29:
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
return V_6 ;
}
static void F_27 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_36 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_7 , V_30 ) ;
F_28 ( V_2 ) ;
}
struct V_33 * F_29 ( const struct V_166 * V_11 ,
struct V_167 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_6 = 0 ;
T_1 V_154 ;
F_10 ( & V_14 -> V_15 , L_7 , V_30 ) ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_168 ) ;
if ( V_2 == NULL )
goto V_29;
V_2 -> V_14 = V_14 ;
V_2 -> V_89 = V_11 -> V_89 ;
memcpy ( & V_2 -> V_11 , V_11 , sizeof( struct V_166 ) ) ;
V_6 = F_7 ( V_2 , 0x00 , 0x0 , & V_154 ) ;
if ( V_6 )
goto V_29;
memcpy ( & V_2 -> V_34 . V_100 , & V_169 , sizeof( struct V_170 ) ) ;
V_2 -> V_34 . V_36 = V_2 ;
V_2 -> V_105 = true ;
return & V_2 -> V_34 ;
V_29:
F_10 ( & V_14 -> V_15 , L_4 , V_30 , V_6 ) ;
F_28 ( V_2 ) ;
return NULL ;
}
