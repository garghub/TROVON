int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( F_2 ( & V_2 -> V_4 -> V_5 ) )
V_3 = 0x010a ;
else {
if ( V_2 -> V_4 -> V_5 . V_6 -> V_7 == V_8 )
V_3 = 0x105 ;
else
V_3 = 0x104 ;
}
return F_3 ( V_2 , V_9 , V_3 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_10 , V_11 ;
if ( F_5 ( & V_2 -> V_4 -> V_5 ) ) {
V_10 = 0x1da ;
V_11 = 0x10a ;
} else {
if ( V_2 -> V_4 -> V_5 . V_6 -> V_7 == V_8 ) {
V_10 = 033 ;
V_11 = 003 ;
} else {
V_10 = 0x1bb ;
V_11 = 0x10b ;
}
}
return F_3 ( V_2 , V_12 ,
V_10 | ( V_11 ) << 16 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
T_1 V_15 = 20 ;
F_7 () ;
V_14 = F_8 ( V_2 ) ;
if ( ! V_14 ) {
F_9 () ;
return 0 ;
}
if ( ( V_2 -> V_4 -> V_5 . V_6 -> V_7 == V_16 ) ||
V_14 -> V_17 . V_18 )
V_15 = 9 ;
F_9 () ;
return F_3 ( V_2 , V_19 ,
V_15 << 10 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
T_1 V_20 , V_21 ;
F_7 () ;
V_14 = F_8 ( V_2 ) ;
if ( ! V_14 ) {
F_9 () ;
return 0 ;
}
V_20 = ( V_14 -> V_17 . V_22 & 0xf ) ;
V_20 |= ( V_14 -> V_17 . V_22 & 0xff0 ) << 4 ;
F_9 () ;
if ( V_2 -> V_4 -> V_5 . V_6 -> V_7 == V_16 )
V_21 = 0xff00 ;
else
V_21 = 0xff0f ;
F_11 ( V_2 ) ;
F_12 ( V_23 , V_20 ) ;
F_12 ( V_24 , V_21 ) ;
F_13 () ;
return F_14 () ;
}
int F_15 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_12 ( V_25 , V_2 -> V_26 [ 0 ] . V_27 |
( V_2 -> V_26 [ 0 ] . V_28 << 16 ) ) ;
F_12 ( V_29 , V_2 -> V_26 [ 1 ] . V_27 |
( V_2 -> V_26 [ 1 ] . V_28 << 16 ) ) ;
F_12 ( V_30 , V_2 -> V_26 [ 2 ] . V_27 |
( V_2 -> V_26 [ 2 ] . V_28 << 16 ) ) ;
F_12 ( V_31 , V_2 -> V_26 [ 3 ] . V_27 |
( V_2 -> V_26 [ 3 ] . V_28 << 16 ) ) ;
F_12 ( V_32 , V_2 -> V_26 [ 4 ] . V_27 |
( V_2 -> V_26 [ 4 ] . V_28 << 16 ) ) ;
F_12 ( V_33 ,
( ( V_2 -> V_26 [ 0 ] . V_34 * 9 + 10 ) ) |
( ( V_2 -> V_26 [ 1 ] . V_34 * 9 + 10 ) << 12 ) |
( ( V_2 -> V_26 [ 2 ] . V_34 * 9 + 10 ) << 24 ) ) ;
F_12 ( V_35 ,
( ( V_2 -> V_26 [ 2 ] . V_34 * 9 + 10 ) >> 8 ) |
( ( V_2 -> V_26 [ 3 ] . V_34 * 9 + 10 ) << 4 ) |
( ( V_2 -> V_26 [ 4 ] . V_34 * 9 + 10 ) << 16 ) ) ;
F_12 ( V_36 ,
V_2 -> V_26 [ 0 ] . V_37 | V_2 -> V_26 [ 1 ] . V_37 << 16 ) ;
F_12 ( V_38 ,
V_2 -> V_26 [ 2 ] . V_37 | V_2 -> V_26 [ 3 ] . V_37 << 16 |
V_2 -> V_26 [ 4 ] . V_37 << 24 ) ;
F_13 () ;
return F_14 () ;
}
int F_16 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_12 ( 0x1c3600 , 0x3 ) ;
F_12 ( V_39 , 0x40 ) ;
F_12 ( V_40 , 0x0 ) ;
F_12 ( V_41 ,
V_42 ) ;
F_12 ( V_43 ,
V_44 ) ;
F_12 ( V_45 , 0xc1f80 ) ;
F_12 ( V_46 , 0x70 ) ;
F_12 ( V_47 , 0xa144000 ) ;
F_12 ( V_19 , 9 << 10 ) ;
F_12 ( V_48 , 0x59900000 ) ;
F_12 ( V_49 , 0x201 ) ;
F_12 ( V_50 , 0x8000170 ) ;
F_12 ( V_51 , 0x105 ) ;
F_12 ( V_52 , 0x8000a ) ;
F_12 ( V_53 , 0x140a07 ) ;
F_12 ( V_41 ,
V_54 ) ;
F_12 ( V_55 ,
V_56 |
V_57 ) ;
F_12 ( V_23 , 0x150f ) ;
F_12 ( V_24 , 0x150f ) ;
F_12 ( V_12 , 0x0030033 ) ;
F_12 ( V_58 , 0x4003c1e ) ;
F_12 ( V_59 , 0xffff ) ;
F_12 ( V_60 , 0xf00008 ) ;
F_12 ( V_61 , 0x0 ) ;
F_12 ( V_62 , 0x110011 ) ;
F_12 ( V_63 ,
V_64 ) ;
F_12 ( V_65 ,
0x141e0f48 ) ;
F_12 ( V_66 , 0xffffffff ) ;
F_12 ( V_67 , 0xffffffff ) ;
F_12 ( V_68 , 0x0 ) ;
F_12 ( V_69 , 0x0 ) ;
F_13 () ;
return F_14 () ;
}
static int F_17 ( struct V_1 * V_2 ,
const T_1 V_70 , const T_2 * V_71 )
{
static const T_2 V_72 [ V_73 ] = { 0 } ;
if ( ! V_71 )
V_71 = V_72 ;
F_11 ( V_2 ) ;
F_12 ( V_70 , F_18 ( V_71 ) ) ;
F_12 ( V_70 + 4 , F_19 ( V_71 + 4 ) ) ;
F_13 () ;
return F_14 () ;
}
int F_20 ( struct V_1 * V_2 , const unsigned int V_74 ,
const T_2 * V_71 )
{
if ( F_21 ( V_74 >= V_2 -> V_75 . V_76 ) )
return - V_77 ;
return F_17 ( V_2 ,
V_78 + ( V_74 - 1 ) * 8 , V_71 ) ;
}
int F_22 ( struct V_1 * V_2 , const T_3 V_79 )
{
int V_80 ;
F_11 ( V_2 ) ;
F_12 ( V_67 , V_79 >> 32 ) ;
F_12 ( V_66 , V_79 ) ;
F_13 () ;
V_80 = F_14 () ;
if ( V_80 )
return V_80 ;
V_2 -> V_81 = V_79 ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_82 * V_83 = & V_2 -> V_83 ;
T_2 * V_84 , * V_85 ;
T_1 V_86 = V_87 ;
T_1 V_88 = V_89 |
V_90 ;
T_1 V_91 = V_56 |
V_57 ;
T_1 V_92 = V_44 ;
int V_80 = 0 ;
F_7 () ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 ) {
V_84 = V_83 -> V_93 ;
V_85 = V_83 -> V_94 ;
switch ( V_14 -> type ) {
case V_95 :
V_86 |= V_96 ;
break;
case V_97 :
case V_98 :
V_86 |= V_99 ;
V_91 |= V_100 ;
break;
case V_101 :
V_86 |= V_102 ;
V_91 |= V_100 ;
break;
case V_103 :
V_86 |= V_104 ;
V_91 |= V_100 ;
break;
default:
F_24 ( 1 , L_1 , V_14 -> type ) ;
V_80 = - V_105 ;
break;
}
} else {
V_86 |= V_104 ;
V_91 |= V_100 ;
V_84 = V_83 -> V_93 ;
V_85 = NULL ;
}
F_9 () ;
if ( V_80 )
return V_80 ;
if ( V_2 -> V_106 )
V_88 |= V_107 ;
if ( V_2 -> V_108 ) {
V_88 |= V_107 ;
}
V_80 = F_17 ( V_2 , V_109 , V_84 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_17 ( V_2 , V_110 , V_85 ) ;
if ( V_80 )
return V_80 ;
F_11 ( V_2 ) ;
F_12 ( V_43 , V_92 ) ;
F_12 ( V_111 , V_86 ) ;
F_12 ( V_112 , V_88 ) ;
F_12 ( V_55 , V_91 ) ;
F_13 () ;
return F_14 () ;
}
int F_25 ( struct V_1 * V_2 , const unsigned int V_113 )
{
T_1 V_114 = F_26 ( T_1 , 0x33333 , V_113 * 0x11111 ) ;
return F_3 ( V_2 , V_40 , V_114 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
T_1 V_115 = 0 ;
T_1 V_116 = 0 ;
F_7 () ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 ) {
struct V_117 * V_118 ;
V_118 = ( void * ) V_14 -> V_119 ;
if ( V_118 -> V_120 && ! F_21 ( ! V_2 -> V_121 ) ) {
V_2 -> V_122 = V_14 -> V_17 . V_123 /
V_2 -> V_121 ;
F_28 ( V_124 , V_115 ,
V_14 -> V_17 . V_125 ) ;
switch ( V_14 -> type ) {
case V_97 :
case V_95 :
V_115 |= V_126 ;
break;
case V_98 :
V_115 |= V_127 ;
break;
default:
F_29 ( 1 ) ;
break;
}
} else if ( V_14 -> type == V_103 ) {
V_2 -> V_122 = V_14 -> V_17 . V_123 ;
F_28 ( V_124 , V_115 ,
V_2 -> V_4 -> V_5 . V_128 ) ;
V_115 |= V_129 |
V_130 ;
}
if ( V_2 -> V_122 ) {
if ( V_2 -> V_122 < 15 ) {
F_9 () ;
return - V_131 ;
}
V_2 -> V_132 = V_2 -> V_122 -
V_133 ;
} else {
V_2 -> V_132 = 0 ;
}
} else {
V_2 -> V_122 = 0 ;
V_2 -> V_132 = 0 ;
}
F_9 () ;
F_28 ( V_134 , V_115 , V_2 -> V_122 ) ;
F_28 ( V_135 , V_116 , V_2 -> V_132 ) ;
F_28 ( V_136 , V_116 , V_2 -> V_132 ) ;
F_11 ( V_2 ) ;
F_12 ( V_68 , V_116 ) ;
F_12 ( V_69 , V_115 ) ;
F_13 () ;
return F_14 () ;
}
int F_30 ( struct V_1 * V_2 , const T_2 V_74 , const T_2 * V_71 ,
const T_2 V_137 , const T_2 V_138 , const T_2 * V_139 ,
const int V_140 )
{
struct V_141 V_142 = { } ;
static const T_2 V_143 [ V_73 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_71 = V_71 ? : V_143 ;
V_142 . V_144 = F_31 ( V_74 ) ;
V_142 . V_145 = F_31 ( V_138 ) ;
V_142 . type = F_31 ( V_137 ) ;
memcpy ( & V_142 . V_146 , V_71 , V_73 ) ;
if ( V_139 )
memcpy ( & V_142 . V_142 , V_139 , V_140 ) ;
return F_32 ( V_2 , V_147 ,
sizeof( V_142 ) , ( T_2 * ) & V_142 , 0 , NULL ) ;
}
int F_33 ( struct V_1 * V_2 , const T_2 V_74 )
{
struct V_148 V_142 = { } ;
V_142 . V_144 = F_31 ( V_74 ) ;
return F_32 ( V_2 , V_149 ,
sizeof( V_142 ) , ( T_2 * ) & V_142 , 0 , NULL ) ;
}
int F_34 ( struct V_1 * V_2 , struct V_150 * V_6 )
{
unsigned int V_151 , V_152 ;
if ( V_2 -> V_153 . V_154 != 1 )
V_152 = V_155 ;
else
V_152 = V_156 ;
switch ( V_6 -> V_7 ) {
case V_8 :
V_151 = V_2 -> V_157 [ 0 ] & 0x3f ;
break;
case V_16 :
V_151 = V_2 -> V_158 [ 0 ] & 0x3f ;
break;
default:
F_35 ( 1 ) ;
}
V_151 = F_26 (unsigned int, power, ar->hw->conf.power_level * 2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_58 ,
0x3c1e | V_151 << 20 | V_152 << 26 ) ;
F_12 ( V_159 ,
V_151 << 5 | V_152 << 11 |
V_151 << 21 | V_152 << 27 ) ;
F_12 ( V_160 ,
V_151 << 5 | V_152 << 11 |
V_151 << 21 | V_152 << 27 ) ;
F_13 () ;
return F_14 () ;
}
