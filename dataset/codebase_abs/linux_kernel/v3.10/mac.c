int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( F_2 ( & V_2 -> V_4 -> V_5 ) )
V_3 = 0x010a ;
else {
if ( V_2 -> V_4 -> V_5 . V_6 . V_7 -> V_8 == V_9 )
V_3 = 0x105 ;
else
V_3 = 0x104 ;
}
return F_3 ( V_2 , V_10 , V_3 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 ;
if ( F_5 ( & V_2 -> V_4 -> V_5 ) ) {
V_11 = 0x1da ;
V_12 = 0x10a ;
} else {
if ( V_2 -> V_4 -> V_5 . V_6 . V_7 -> V_8 == V_9 ) {
V_11 = 033 ;
V_12 = 003 ;
} else {
V_11 = 0x1bb ;
V_12 = 0x10b ;
}
}
return F_3 ( V_2 , V_13 ,
V_11 | ( V_12 ) << 16 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
T_1 V_16 = 20 ;
F_7 () ;
V_15 = F_8 ( V_2 ) ;
if ( ! V_15 ) {
F_9 () ;
return 0 ;
}
if ( ( V_2 -> V_4 -> V_5 . V_6 . V_7 -> V_8 == V_17 ) ||
V_15 -> V_18 . V_19 )
V_16 = 9 ;
F_9 () ;
return F_3 ( V_2 , V_20 ,
V_16 << 10 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
T_1 V_21 , V_22 ;
F_7 () ;
V_15 = F_8 ( V_2 ) ;
if ( ! V_15 ) {
F_9 () ;
return 0 ;
}
V_21 = ( V_15 -> V_18 . V_23 & 0xf ) ;
V_21 |= ( V_15 -> V_18 . V_23 & 0xff0 ) << 4 ;
F_9 () ;
if ( V_2 -> V_4 -> V_5 . V_6 . V_7 -> V_8 == V_17 )
V_22 = 0xff00 ;
else
V_22 = 0xff0f ;
F_11 ( V_2 ) ;
F_12 ( V_24 , V_21 ) ;
F_12 ( V_25 , V_22 ) ;
F_13 () ;
return F_14 () ;
}
int F_15 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_12 ( V_26 , V_2 -> V_27 [ 0 ] . V_28 |
( V_2 -> V_27 [ 0 ] . V_29 << 16 ) ) ;
F_12 ( V_30 , V_2 -> V_27 [ 1 ] . V_28 |
( V_2 -> V_27 [ 1 ] . V_29 << 16 ) ) ;
F_12 ( V_31 , V_2 -> V_27 [ 2 ] . V_28 |
( V_2 -> V_27 [ 2 ] . V_29 << 16 ) ) ;
F_12 ( V_32 , V_2 -> V_27 [ 3 ] . V_28 |
( V_2 -> V_27 [ 3 ] . V_29 << 16 ) ) ;
F_12 ( V_33 , V_2 -> V_27 [ 4 ] . V_28 |
( V_2 -> V_27 [ 4 ] . V_29 << 16 ) ) ;
F_12 ( V_34 ,
( ( V_2 -> V_27 [ 0 ] . V_35 * 9 + 10 ) ) |
( ( V_2 -> V_27 [ 1 ] . V_35 * 9 + 10 ) << 12 ) |
( ( V_2 -> V_27 [ 2 ] . V_35 * 9 + 10 ) << 24 ) ) ;
F_12 ( V_36 ,
( ( V_2 -> V_27 [ 2 ] . V_35 * 9 + 10 ) >> 8 ) |
( ( V_2 -> V_27 [ 3 ] . V_35 * 9 + 10 ) << 4 ) |
( ( V_2 -> V_27 [ 4 ] . V_35 * 9 + 10 ) << 16 ) ) ;
F_12 ( V_37 ,
V_2 -> V_27 [ 0 ] . V_38 | V_2 -> V_27 [ 1 ] . V_38 << 16 ) ;
F_12 ( V_39 ,
V_2 -> V_27 [ 2 ] . V_38 | V_2 -> V_27 [ 3 ] . V_38 << 16 |
V_2 -> V_27 [ 4 ] . V_38 << 24 ) ;
F_13 () ;
return F_14 () ;
}
int F_16 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_12 ( 0x1c3600 , 0x3 ) ;
F_12 ( V_40 , 0x40 ) ;
F_12 ( V_41 , 0x0 ) ;
F_12 ( V_42 ,
V_43 ) ;
F_12 ( V_44 ,
V_45 ) ;
F_12 ( V_46 , 0xc1f80 ) ;
F_12 ( V_47 , 0x70 ) ;
F_12 ( V_48 , 0xa144000 ) ;
F_12 ( V_20 , 9 << 10 ) ;
F_12 ( V_49 , 0x59900000 ) ;
F_12 ( V_50 , 0x201 ) ;
F_12 ( V_51 , 0x8000170 ) ;
F_12 ( V_52 , 0x105 ) ;
F_12 ( V_53 , 0x8000a ) ;
F_12 ( V_54 , 0x140a07 ) ;
F_12 ( V_42 ,
V_55 ) ;
F_12 ( V_56 ,
V_57 |
V_58 ) ;
F_12 ( V_24 , 0x150f ) ;
F_12 ( V_25 , 0x150f ) ;
F_12 ( V_13 , 0x0030033 ) ;
F_12 ( V_59 , 0x4003c1e ) ;
F_12 ( V_60 , 0xffff ) ;
F_12 ( V_61 , 0xf00008 ) ;
F_12 ( V_62 , 0x0 ) ;
F_12 ( V_63 , 0x110011 ) ;
F_12 ( V_64 ,
V_65 ) ;
F_12 ( V_66 ,
0x141e0f48 ) ;
F_12 ( V_67 , 0xffffffff ) ;
F_12 ( V_68 , 0xffffffff ) ;
F_12 ( V_69 , 0x0 ) ;
F_12 ( V_70 , 0x0 ) ;
F_13 () ;
return F_14 () ;
}
static int F_17 ( struct V_1 * V_2 ,
const T_1 V_71 , const T_2 * V_72 )
{
static const T_2 V_73 [ V_74 ] = { 0 } ;
if ( ! V_72 )
V_72 = V_73 ;
F_11 ( V_2 ) ;
F_12 ( V_71 , F_18 ( V_72 ) ) ;
F_12 ( V_71 + 4 , F_19 ( V_72 + 4 ) ) ;
F_13 () ;
return F_14 () ;
}
int F_20 ( struct V_1 * V_2 , const unsigned int V_75 ,
const T_2 * V_72 )
{
if ( F_21 ( V_75 >= V_2 -> V_76 . V_77 ) )
return - V_78 ;
return F_17 ( V_2 ,
V_79 + ( V_75 - 1 ) * 8 , V_72 ) ;
}
int F_22 ( struct V_1 * V_2 , const T_3 V_80 )
{
int V_81 ;
F_11 ( V_2 ) ;
F_12 ( V_68 , V_80 >> 32 ) ;
F_12 ( V_67 , V_80 ) ;
F_13 () ;
V_81 = F_14 () ;
if ( V_81 )
return V_81 ;
V_2 -> V_82 = V_80 ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_83 * V_84 = & V_2 -> V_84 ;
T_2 * V_85 , * V_86 ;
T_1 V_87 = V_88 ;
T_1 V_89 = V_90 |
V_91 ;
T_1 V_92 = V_57 |
V_58 ;
T_1 V_93 = V_45 ;
int V_81 = 0 ;
F_7 () ;
V_15 = F_8 ( V_2 ) ;
if ( V_15 ) {
V_85 = V_84 -> V_94 ;
V_86 = V_84 -> V_95 ;
switch ( V_15 -> type ) {
case V_96 :
V_87 |= V_97 ;
break;
case V_98 :
case V_99 :
V_87 |= V_100 ;
V_92 |= V_101 ;
break;
case V_102 :
V_87 |= V_103 ;
V_92 |= V_101 ;
break;
case V_104 :
V_87 |= V_105 ;
V_92 |= V_101 ;
break;
default:
F_24 ( 1 , L_1 , V_15 -> type ) ;
V_81 = - V_106 ;
break;
}
} else {
V_87 |= V_105 ;
V_92 |= V_101 ;
V_85 = V_84 -> V_94 ;
V_86 = NULL ;
}
F_9 () ;
if ( V_81 )
return V_81 ;
if ( V_2 -> V_107 )
V_89 |= V_108 ;
if ( V_2 -> V_109 ) {
V_89 |= V_108 ;
}
V_81 = F_17 ( V_2 , V_110 , V_85 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_17 ( V_2 , V_111 , V_86 ) ;
if ( V_81 )
return V_81 ;
F_11 ( V_2 ) ;
F_12 ( V_44 , V_93 ) ;
F_12 ( V_112 , V_87 ) ;
F_12 ( V_113 , V_89 ) ;
F_12 ( V_56 , V_92 ) ;
F_13 () ;
return F_14 () ;
}
int F_25 ( struct V_1 * V_2 , const unsigned int V_114 )
{
T_1 V_115 = F_26 ( T_1 , 0x33333 , V_114 * 0x11111 ) ;
return F_3 ( V_2 , V_41 , V_115 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
T_1 V_116 = 0 ;
T_1 V_117 = 0 ;
F_7 () ;
V_15 = F_8 ( V_2 ) ;
if ( V_15 ) {
struct V_118 * V_119 ;
V_119 = ( void * ) V_15 -> V_120 ;
if ( V_119 -> V_121 && ! F_21 ( ! V_2 -> V_122 ) ) {
V_2 -> V_123 = V_15 -> V_18 . V_124 /
V_2 -> V_122 ;
F_28 ( V_125 , V_116 ,
V_15 -> V_18 . V_126 ) ;
switch ( V_15 -> type ) {
case V_98 :
case V_96 :
V_116 |= V_127 ;
break;
case V_99 :
V_116 |= V_128 ;
break;
default:
F_29 ( 1 ) ;
break;
}
} else if ( V_15 -> type == V_104 ) {
V_2 -> V_123 = V_15 -> V_18 . V_124 ;
F_28 ( V_125 , V_116 ,
V_2 -> V_4 -> V_5 . V_129 ) ;
V_116 |= V_130 |
V_131 ;
}
if ( V_2 -> V_123 ) {
if ( V_2 -> V_123 < 15 ) {
F_9 () ;
return - V_132 ;
}
V_2 -> V_133 = V_2 -> V_123 -
V_134 ;
} else {
V_2 -> V_133 = 0 ;
}
} else {
V_2 -> V_123 = 0 ;
V_2 -> V_133 = 0 ;
}
F_9 () ;
F_28 ( V_135 , V_116 , V_2 -> V_123 ) ;
F_28 ( V_136 , V_117 , V_2 -> V_133 ) ;
F_28 ( V_137 , V_117 , V_2 -> V_133 ) ;
F_11 ( V_2 ) ;
F_12 ( V_69 , V_117 ) ;
F_12 ( V_70 , V_116 ) ;
F_13 () ;
return F_14 () ;
}
int F_30 ( struct V_1 * V_2 , const T_2 V_75 , const T_2 * V_72 ,
const T_2 V_138 , const T_2 V_139 , const T_2 * V_140 ,
const int V_141 )
{
struct V_142 V_143 = { } ;
static const T_2 V_144 [ V_74 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_72 = V_72 ? : V_144 ;
V_143 . V_145 = F_31 ( V_75 ) ;
V_143 . V_146 = F_31 ( V_139 ) ;
V_143 . type = F_31 ( V_138 ) ;
memcpy ( & V_143 . V_147 , V_72 , V_74 ) ;
if ( V_140 )
memcpy ( & V_143 . V_143 , V_140 , V_141 ) ;
return F_32 ( V_2 , V_148 ,
sizeof( V_143 ) , ( T_2 * ) & V_143 , 0 , NULL ) ;
}
int F_33 ( struct V_1 * V_2 , const T_2 V_75 )
{
struct V_149 V_143 = { } ;
V_143 . V_145 = F_31 ( V_75 ) ;
return F_32 ( V_2 , V_150 ,
sizeof( V_143 ) , ( T_2 * ) & V_143 , 0 , NULL ) ;
}
int F_34 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
unsigned int V_153 , V_154 ;
if ( V_2 -> V_155 . V_156 != 1 )
V_154 = V_157 ;
else
V_154 = V_158 ;
switch ( V_152 -> V_8 ) {
case V_9 :
V_153 = V_2 -> V_159 [ 0 ] & 0x3f ;
break;
case V_17 :
V_153 = V_2 -> V_160 [ 0 ] & 0x3f ;
break;
default:
F_35 ( 1 ) ;
}
V_153 = F_26 (unsigned int, power, ar->hw->conf.power_level * 2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_59 ,
0x3c1e | V_153 << 20 | V_154 << 26 ) ;
F_12 ( V_161 ,
V_153 << 5 | V_154 << 11 |
V_153 << 21 | V_154 << 27 ) ;
F_12 ( V_162 ,
V_153 << 5 | V_154 << 11 |
V_153 << 21 | V_154 << 27 ) ;
F_13 () ;
return F_14 () ;
}
