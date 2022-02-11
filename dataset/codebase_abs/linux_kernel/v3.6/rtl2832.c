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
F_3 ( L_1 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
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
. V_13 = V_16 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_3 ( L_2 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
if ( V_17 != V_2 -> V_17 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_17 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_17 = V_17 ;
}
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
if ( V_17 != V_2 -> V_17 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_17 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_17 = V_17 ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 , T_1 * V_4 )
{
return F_6 ( V_2 , V_3 , V_17 , V_4 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
T_1 V_18 ;
T_1 V_19 , V_20 ;
T_1 V_17 ;
T_1 V_21 [ 4 ] ;
T_2 V_22 ;
int V_23 ;
T_1 V_5 ;
T_2 V_24 ;
V_18 = V_25 [ V_3 ] . V_26 ;
V_19 = V_25 [ V_3 ] . V_19 ;
V_20 = V_25 [ V_3 ] . V_20 ;
V_17 = V_25 [ V_3 ] . V_17 ;
V_5 = ( V_19 >> 3 ) + 1 ;
V_24 = F_9 ( V_19 - V_20 ) ;
V_6 = F_6 ( V_2 , V_18 , V_17 , & V_21 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_27;
V_22 = 0 ;
for ( V_23 = 0 ; V_23 < V_5 ; V_23 ++ )
V_22 |= V_21 [ V_23 ] << ( ( V_5 - 1 - V_23 ) * 8 ) ;
* V_4 = ( V_22 >> V_20 ) & V_24 ;
return V_6 ;
V_27:
F_10 ( L_3 , V_28 , V_6 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
int V_6 , V_23 ;
T_1 V_5 ;
T_1 V_18 ;
T_1 V_19 , V_20 ;
T_1 V_17 ;
T_2 V_24 ;
T_1 V_21 [ 4 ] ;
T_1 V_29 [ 4 ] ;
T_2 V_22 ;
T_2 V_30 ;
V_18 = V_25 [ V_3 ] . V_26 ;
V_19 = V_25 [ V_3 ] . V_19 ;
V_20 = V_25 [ V_3 ] . V_20 ;
V_17 = V_25 [ V_3 ] . V_17 ;
V_5 = ( V_19 >> 3 ) + 1 ;
V_24 = F_9 ( V_19 - V_20 ) ;
V_6 = F_6 ( V_2 , V_18 , V_17 , & V_21 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_27;
V_22 = 0 ;
for ( V_23 = 0 ; V_23 < V_5 ; V_23 ++ )
V_22 |= V_21 [ V_23 ] << ( ( V_5 - 1 - V_23 ) * 8 ) ;
V_30 = V_22 & ~ ( V_24 << V_20 ) ;
V_30 |= ( ( V_4 & V_24 ) << V_20 ) ;
for ( V_23 = 0 ; V_23 < V_5 ; V_23 ++ )
V_29 [ V_23 ] = ( V_30 >> ( ( V_5 - 1 - V_23 ) * 8 ) ) & 0xff ;
V_6 = F_5 ( V_2 , V_18 , V_17 , & V_29 [ 0 ] , V_5 ) ;
if ( V_6 )
goto V_27;
return V_6 ;
V_27:
F_10 ( L_3 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_31 * V_32 , int V_33 )
{
int V_6 ;
struct V_1 * V_2 = V_32 -> V_34 ;
F_10 ( L_4 , V_28 , V_33 ) ;
if ( V_2 -> V_35 == V_33 )
return 0 ;
V_6 = F_11 ( V_2 , V_36 , ( V_33 ? 0x1 : 0x0 ) ) ;
if ( V_6 )
goto V_27;
V_2 -> V_35 = V_33 ;
return V_6 ;
V_27:
F_10 ( L_3 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_23 , V_6 ;
T_1 V_37 ;
T_3 V_38 ;
struct V_39 V_40 [] = {
{ V_41 , 0x1 } ,
{ V_42 , 0x1 } ,
{ V_43 , 0x2800 } ,
{ V_44 , 0x10 } ,
{ V_45 , 0x20 } ,
{ V_46 , 0x20 } ,
{ V_47 , 0x40 } ,
{ V_48 , 0x22 } ,
{ V_49 , 0x32 } ,
{ V_50 , 0x37 } ,
{ V_51 , 0x39 } ,
{ V_52 , 0x0 } ,
{ V_53 , 0x0 } ,
{ V_54 , 0x2a } ,
{ V_55 , 0x6 } ,
{ V_56 , 0x0 } ,
{ V_57 , 0x8 } ,
{ V_58 , 0x8 } ,
{ V_59 , 0x4 } ,
{ V_60 , 0xb0 } ,
{ V_61 , 0x78 } ,
{ V_62 , 0x28 } ,
{ V_63 , 0x59 } ,
{ V_64 , 0x83 } ,
{ V_65 , 0xd4 } ,
{ V_66 , 0x65 } ,
{ V_67 , 0x43 } ,
{ V_68 , 0x1 } ,
{ V_69 , 0x4 } ,
{ V_70 , 0x7 } ,
{ V_71 , 0xa } ,
{ V_72 , 0x1 } ,
{ V_73 , 0x0 } ,
{ V_57 , 0x9 } ,
{ V_58 , 0x9 } ,
{ V_74 , 0x0 } ,
{ V_75 , 0x0 } ,
{ V_76 , 0x4 } ,
{ V_77 , 0x7 } ,
{ V_78 , 0x6 } ,
{ V_79 , 0x5 } ,
{ V_80 , 0x1 } ,
{ V_81 , 0x0 } ,
{ V_82 , 0x5a } ,
{ V_83 , 0x0 } ,
{ V_84 , 0x5a } ,
{ V_85 , 0x16 } ,
{ V_86 , 0x6 } ,
{ V_87 , 0x1 } ,
{ V_88 , 0x16 } ,
{ V_89 , 0x35 } ,
{ V_90 , 0x21 } ,
{ V_91 , 0x21 } ,
{ V_92 , 0x0 } ,
{ V_93 , 0x40 } ,
{ V_94 , 0x10 } ,
{ V_95 , 0x10 } ,
{ V_96 , 0x80 } ,
{ V_97 , 0x7f } ,
{ V_98 , 0x80 } ,
{ V_99 , 0x7f } ,
{ V_100 , 0x0 } ,
{ V_101 , 0x0 } ,
{ V_102 , 0xe9bf } ,
{ V_103 , 0x0 } ,
{ V_104 , 0x0 } ,
{ V_105 , 0x0 } ,
{ V_106 , 0x11 } ,
{ V_107 , 0xef } ,
{ V_108 , 0xc } ,
{ V_109 , 0x0 } ,
{ V_110 , 0x1 } ,
{ V_111 , 0x0 } ,
} ;
F_10 ( L_5 , V_28 ) ;
V_37 = ( V_2 -> V_11 . V_112 == 0 ? 0x1 : 0x0 ) ;
V_38 = V_2 -> V_11 . V_112 % V_2 -> V_11 . V_113 ;
V_38 *= 0x400000 ;
V_38 = F_14 ( V_38 , V_2 -> V_11 . V_113 ) ;
V_38 = V_38 & 0x3fffff ;
for ( V_23 = 0 ; V_23 < F_15 ( V_40 ) ; V_23 ++ ) {
V_6 = F_11 ( V_2 , V_40 [ V_23 ] . V_3 ,
V_40 [ V_23 ] . V_114 ) ;
if ( V_6 )
goto V_27;
}
V_6 = F_11 ( V_2 , V_115 , V_37 ) ;
if ( V_6 )
goto V_27;
V_6 = F_11 ( V_2 , V_116 , V_38 ) ;
if ( V_6 )
goto V_27;
V_2 -> V_117 = false ;
return V_6 ;
V_27:
F_10 ( L_3 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
F_10 ( L_5 , V_28 ) ;
V_2 -> V_117 = true ;
return 0 ;
}
int F_17 ( struct V_31 * V_32 ,
struct V_118 * V_119 )
{
F_10 ( L_5 , V_28 ) ;
V_119 -> V_120 = 1000 ;
V_119 -> V_121 = V_32 -> V_122 . V_123 . V_124 * 2 ;
V_119 -> V_125 = ( V_32 -> V_122 . V_123 . V_124 * 2 ) + 1 ;
return 0 ;
}
static int F_18 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_126 * V_127 = & V_32 -> V_128 ;
int V_6 , V_23 , V_129 ;
T_3 V_130 , V_131 , V_132 ;
T_2 V_133 , V_134 ;
static T_1 V_135 [ 3 ] [ 32 ] = {
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
F_10 ( L_6 , V_28 ,
V_127 -> V_136 , V_127 -> V_137 , V_127 -> V_138 ) ;
if ( V_32 -> V_122 . V_139 . V_140 )
V_32 -> V_122 . V_139 . V_140 ( V_32 ) ;
switch ( V_127 -> V_137 ) {
case 6000000 :
V_23 = 0 ;
V_130 = 48000000 ;
break;
case 7000000 :
V_23 = 1 ;
V_130 = 56000000 ;
break;
case 8000000 :
V_23 = 2 ;
V_130 = 64000000 ;
break;
default:
F_10 ( L_7 ) ;
return - V_141 ;
}
for ( V_129 = 0 ; V_129 < sizeof( V_135 [ 0 ] ) ; V_129 ++ ) {
V_6 = F_5 ( V_2 , 0x1c + V_129 , 1 , & V_135 [ V_23 ] [ V_129 ] , 1 ) ;
if ( V_6 )
goto V_27;
}
V_131 = V_2 -> V_11 . V_113 * 7 ;
V_131 *= 0x400000 ;
V_131 = F_14 ( V_131 , V_130 ) ;
V_133 = V_131 & 0x3ffffff ;
V_6 = F_11 ( V_2 , V_142 , V_133 ) ;
if ( V_6 )
goto V_27;
V_131 = V_130 << 20 ;
V_132 = V_2 -> V_11 . V_113 * 7 ;
V_131 = F_14 ( V_131 , V_132 ) ;
V_131 = - V_131 ;
V_134 = V_131 & 0xfffff ;
V_6 = F_11 ( V_2 , V_143 , V_134 ) ;
if ( V_6 )
goto V_27;
V_6 = F_11 ( V_2 , V_144 , 0x1 ) ;
if ( V_6 )
goto V_27;
V_6 = F_11 ( V_2 , V_144 , 0x0 ) ;
if ( V_6 )
goto V_27;
return V_6 ;
V_27:
V_123 ( L_3 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_31 * V_32 , T_4 * V_145 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
T_2 V_146 ;
* V_145 = 0 ;
F_10 ( L_5 , V_28 ) ;
if ( V_2 -> V_117 )
return 0 ;
V_6 = F_8 ( V_2 , V_147 , & V_146 ) ;
if ( V_6 )
goto V_27;
if ( V_146 == 11 ) {
* V_145 |= V_148 | V_149 |
V_150 | V_151 | V_152 ;
}
return V_6 ;
V_27:
V_123 ( L_3 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_31 * V_32 , T_5 * V_153 )
{
* V_153 = 0 ;
return 0 ;
}
static int F_21 ( struct V_31 * V_32 , T_2 * V_154 )
{
* V_154 = 0 ;
return 0 ;
}
static int F_22 ( struct V_31 * V_32 , T_2 * V_155 )
{
* V_155 = 0 ;
return 0 ;
}
static int F_23 ( struct V_31 * V_32 , T_5 * V_156 )
{
* V_156 = 0 ;
return 0 ;
}
static void F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
F_10 ( L_5 , V_28 ) ;
F_25 ( V_2 ) ;
}
struct V_31 * F_26 ( const struct V_157 * V_11 ,
struct V_158 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_6 = 0 ;
T_1 V_146 ;
F_10 ( L_5 , V_28 ) ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_159 ) ;
if ( V_2 == NULL )
goto V_27;
V_2 -> V_14 = V_14 ;
V_2 -> V_160 = V_11 -> V_160 ;
memcpy ( & V_2 -> V_11 , V_11 , sizeof( struct V_157 ) ) ;
V_6 = F_7 ( V_2 , 0x00 , 0x0 , & V_146 ) ;
if ( V_6 )
goto V_27;
memcpy ( & V_2 -> V_32 . V_122 , & V_161 , sizeof( struct V_162 ) ) ;
V_2 -> V_32 . V_34 = V_2 ;
V_2 -> V_117 = true ;
return & V_2 -> V_32 ;
V_27:
F_10 ( L_3 , V_28 , V_6 ) ;
F_25 ( V_2 ) ;
return NULL ;
}
