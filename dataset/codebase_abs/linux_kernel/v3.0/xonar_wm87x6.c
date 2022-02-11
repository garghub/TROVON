static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
F_2 ( V_2 , V_5 |
V_6 |
V_7 |
( 1 << V_8 ) |
V_9 ,
( V_3 << 9 ) | V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
F_4 ( V_2 , V_10 ,
( V_3 << 1 ) | ( V_4 >> 8 ) , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( ( V_2 -> V_14 . V_15 & V_16 ) ==
V_17 )
F_1 ( V_2 , V_3 , V_4 ) ;
else
F_3 ( V_2 , V_3 , V_4 ) ;
if ( V_3 < F_6 ( V_12 -> V_18 ) ) {
if ( V_3 >= V_19 && V_3 <= V_20 )
V_4 &= ~ V_21 ;
V_12 -> V_18 [ V_3 ] = V_4 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( V_3 >= F_6 ( V_12 -> V_18 ) ||
V_4 != V_12 -> V_18 [ V_3 ] )
F_5 ( V_2 , V_3 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_2 ( V_2 , V_5 |
V_6 |
V_7 |
( 0 << V_8 ) |
V_9 ,
( V_3 << 9 ) | V_4 ) ;
if ( V_3 < F_6 ( V_12 -> V_22 ) ) {
if ( ( V_3 >= V_23 && V_3 <= V_24 ) ||
( V_3 >= V_25 && V_3 <= V_26 ) )
V_4 &= ~ V_27 ;
V_12 -> V_22 [ V_3 ] = V_4 ;
}
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( V_3 >= F_6 ( V_12 -> V_22 ) ||
V_4 != V_12 -> V_22 [ V_3 ] )
F_8 ( V_2 , V_3 , V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_5 ( V_2 , V_28 , 0 ) ;
F_5 ( V_2 , V_29 , V_30 |
V_31 | V_32 ) ;
F_5 ( V_2 , V_33 , V_2 -> V_34 ? V_35 : 0 ) ;
F_5 ( V_2 , V_36 ,
V_37 | V_38 ) ;
F_5 ( V_2 , V_39 ,
V_12 -> V_18 [ V_39 ] ) ;
F_5 ( V_2 , V_40 , V_12 -> V_18 [ V_40 ] ) ;
F_5 ( V_2 , V_41 , V_12 -> V_18 [ V_41 ] ) ;
F_5 ( V_2 , V_19 , V_12 -> V_18 [ V_19 ] ) ;
F_5 ( V_2 , V_42 , V_12 -> V_18 [ V_42 ] |
V_21 ) ;
F_5 ( V_2 , V_43 , V_12 -> V_18 [ V_43 ] ) ;
F_5 ( V_2 , V_44 , V_12 -> V_18 [ V_44 ] ) ;
F_5 ( V_2 , V_45 , V_12 -> V_18 [ V_45 ] ) ;
F_5 ( V_2 , V_46 , V_2 -> V_47 [ 0 ] ) ;
F_5 ( V_2 , V_48 , V_2 -> V_47 [ 1 ] | V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_8 ( V_2 , V_49 , 0 ) ;
F_8 ( V_2 , V_50 , V_12 -> V_22 [ V_50 ] ) ;
F_8 ( V_2 , V_51 , V_52 | V_53 ) ;
F_8 ( V_2 , V_54 ,
V_55 | ( V_2 -> V_34 ? V_56 : 0 ) ) ;
F_8 ( V_2 , V_23 , V_2 -> V_47 [ 2 ] ) ;
F_8 ( V_2 , V_24 , V_2 -> V_47 [ 3 ] ) ;
F_8 ( V_2 , V_25 , V_2 -> V_47 [ 4 ] ) ;
F_8 ( V_2 , V_57 , V_2 -> V_47 [ 5 ] ) ;
F_8 ( V_2 , V_58 , V_2 -> V_47 [ 6 ] ) ;
F_8 ( V_2 , V_59 , V_2 -> V_47 [ 7 ] | V_27 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_18 [ V_19 ] = ( 0x79 - 60 ) | V_60 ;
V_12 -> V_18 [ V_42 ] = ( 0x79 - 60 ) | V_60 ;
V_12 -> V_18 [ V_39 ] =
V_61 | V_62 | V_63 ;
V_12 -> V_18 [ V_40 ] =
V_64 | V_65 ;
V_12 -> V_18 [ V_41 ] = V_66 ;
V_12 -> V_18 [ V_43 ] = 0xa5 | V_67 ;
V_12 -> V_18 [ V_44 ] = 0xa5 | V_67 ;
V_12 -> V_18 [ V_45 ] = 0x001 ;
F_10 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_22 [ V_50 ] =
V_68 | V_69 ;
F_11 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
bool V_70 ;
unsigned int V_3 ;
F_15 ( & V_2 -> V_71 ) ;
V_70 = ! ( F_16 ( V_2 , V_72 ) &
V_73 ) ;
F_17 ( V_2 , V_72 ,
V_70 ? 0 : V_74 ,
V_74 ) ;
V_3 = V_12 -> V_22 [ V_50 ] & ~ V_75 ;
if ( V_70 )
V_3 |= V_75 ;
F_9 ( V_2 , V_50 , V_3 ) ;
F_18 ( V_12 -> V_76 , V_70 ? V_77 : 0 ) ;
F_19 ( & V_2 -> V_71 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_78 . V_79 = 300 ;
V_12 -> V_78 . V_80 = V_81 ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_21 ( V_2 , V_82 ,
V_83 | V_74 ) ;
F_22 ( V_2 , V_82 ,
V_73 ) ;
F_21 ( V_2 , V_72 , V_83 ) ;
F_21 ( V_2 , V_84 , V_73 ) ;
V_2 -> V_85 |= V_86 ;
F_23 ( V_2 ) ;
F_24 ( V_2 -> V_87 , L_1 ,
V_77 , & V_12 -> V_76 ) ;
F_14 ( V_2 ) ;
F_25 ( V_2 -> V_87 , L_2 ) ;
F_25 ( V_2 -> V_87 , L_3 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_78 . V_79 = 300 ;
V_12 -> V_78 . V_80 = V_88 ;
F_12 ( V_2 ) ;
F_21 ( V_2 , V_82 ,
V_89 |
V_90 |
V_91 ) ;
F_27 ( V_2 , & V_12 -> V_92 ) ;
F_23 ( V_2 ) ;
F_25 ( V_2 -> V_87 , L_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_5 ( V_2 , V_28 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
F_29 ( V_2 ) ;
F_5 ( V_2 , V_28 , 0 ) ;
F_32 ( 2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_23 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_10 ( V_2 ) ;
F_37 ( V_2 , & V_12 -> V_92 ) ;
F_23 ( V_2 ) ;
}
static void F_38 ( unsigned int V_93 ,
struct V_94 * V_95 )
{
if ( V_93 == V_96 ) {
V_95 -> V_97 = V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 ;
V_95 -> V_104 = 96000 ;
}
}
static void F_39 ( unsigned int V_93 ,
struct V_94 * V_95 )
{
F_38 ( V_93 , V_95 ) ;
F_40 ( V_93 , V_95 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
}
static void F_42 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
T_1 V_3 ;
V_3 = V_64 | V_65 ;
if ( F_43 ( V_106 ) > 48000 )
V_3 |= V_107 ;
F_7 ( V_2 , V_40 , V_3 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_45 ( V_2 , & V_12 -> V_92 , V_106 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_2 V_108 ;
if ( V_2 -> V_47 [ 0 ] == V_2 -> V_47 [ 1 ] ) {
if ( V_2 -> V_47 [ 0 ] != V_12 -> V_18 [ V_46 ] ||
V_2 -> V_47 [ 1 ] != V_12 -> V_18 [ V_48 ] ) {
F_5 ( V_2 , V_20 ,
V_2 -> V_47 [ 0 ] | V_21 ) ;
V_12 -> V_18 [ V_46 ] = V_2 -> V_47 [ 0 ] ;
V_12 -> V_18 [ V_48 ] = V_2 -> V_47 [ 0 ] ;
}
} else {
V_108 = ( V_2 -> V_47 [ 0 ] !=
V_12 -> V_18 [ V_46 ] ) << 0 ;
V_108 |= ( V_2 -> V_47 [ 1 ] !=
V_12 -> V_18 [ V_46 ] ) << 1 ;
if ( V_108 & 1 )
F_5 ( V_2 , V_46 , V_2 -> V_47 [ 0 ] |
( ( V_108 & 2 ) ? 0 : V_21 ) ) ;
if ( V_108 & 2 )
F_5 ( V_2 , V_48 ,
V_2 -> V_47 [ 1 ] | V_21 ) ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
static const T_2 V_22 [ 6 ] = {
V_23 , V_24 ,
V_25 , V_57 ,
V_58 , V_59 ,
} ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_109 ;
T_2 V_108 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_47 [ 2 ] == V_2 -> V_47 [ 3 ] &&
V_2 -> V_47 [ 2 ] == V_2 -> V_47 [ 4 ] &&
V_2 -> V_47 [ 2 ] == V_2 -> V_47 [ 5 ] &&
V_2 -> V_47 [ 2 ] == V_2 -> V_47 [ 6 ] &&
V_2 -> V_47 [ 2 ] == V_2 -> V_47 [ 7 ] ) {
V_108 = 0 ;
for ( V_109 = 0 ; V_109 < 6 ; ++ V_109 )
if ( V_2 -> V_47 [ 2 ] !=
V_12 -> V_22 [ V_22 [ V_109 ] ] )
V_108 = 1 ;
if ( V_108 ) {
F_8 ( V_2 , V_26 ,
V_2 -> V_47 [ 2 ] | V_27 ) ;
for ( V_109 = 0 ; V_109 < 6 ; ++ V_109 )
V_12 -> V_22 [ V_22 [ V_109 ] ] =
V_2 -> V_47 [ 2 ] ;
}
} else {
V_108 = 0 ;
for ( V_109 = 0 ; V_109 < 6 ; ++ V_109 )
V_108 |= ( V_2 -> V_47 [ 2 + V_109 ] !=
V_12 -> V_22 [ V_22 [ V_109 ] ] ) << V_109 ;
for ( V_109 = 0 ; V_109 < 6 ; ++ V_109 )
if ( V_108 & ( 1 << V_109 ) )
F_8 ( V_2 , V_22 [ V_109 ] ,
V_2 -> V_47 [ 2 + V_109 ] |
( ( V_108 & ( 0x3e << V_109 ) )
? 0 : V_27 ) ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_33 ,
V_2 -> V_34 ? V_35 : 0 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
F_9 ( V_2 , V_54 , V_55 |
( V_2 -> V_34 ? V_56 : 0 ) ) ;
}
static void F_50 ( struct V_1 * V_2 , bool V_110 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_3 ;
V_3 = V_12 -> V_22 [ V_50 ] &
~ ( V_111 | V_112 ) ;
if ( V_110 )
V_3 |= V_113 | V_114 ;
else
V_3 |= V_68 | V_69 ;
F_9 ( V_2 , V_50 , V_3 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
}
static int F_52 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
T_1 V_119 = V_116 -> V_120 & 0xffff ;
unsigned int V_121 = ( V_116 -> V_120 >> 16 ) & 0xff ;
bool V_122 = ( V_116 -> V_120 >> 24 ) & 1 ;
V_4 -> V_4 . integer . V_4 [ 0 ] =
( ( V_12 -> V_18 [ V_121 ] & V_119 ) != 0 ) ^ V_122 ;
return 0 ;
}
static int F_53 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
T_1 V_119 = V_116 -> V_120 & 0xffff ;
T_1 V_123 ;
unsigned int V_121 = ( V_116 -> V_120 >> 16 ) & 0xff ;
bool V_122 = ( V_116 -> V_120 >> 24 ) & 1 ;
int V_124 ;
F_15 ( & V_2 -> V_71 ) ;
V_123 = V_12 -> V_18 [ V_121 ] & ~ V_119 ;
if ( V_4 -> V_4 . integer . V_4 [ 0 ] ^ V_122 )
V_123 |= V_119 ;
V_124 = V_123 != V_12 -> V_18 [ V_121 ] ;
if ( V_124 )
F_5 ( V_2 , V_121 , V_123 ) ;
F_19 ( & V_2 -> V_71 ) ;
return V_124 ;
}
static int F_54 ( struct V_115 * V_116 ,
struct V_125 * V_126 )
{
static const char * const V_127 [ 16 ] = {
L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 , L_11 ,
L_12 , L_13 , L_14 , L_15 ,
L_16 , L_17 , L_18 , L_19 ,
} ;
static const char * const V_128 [ 11 ] = {
L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 ,
} ;
static const char * const V_129 [ 11 ] = {
L_31 , L_32 , L_33 , L_34 ,
L_35 , L_36 , L_37 , L_38 ,
L_39 , L_40 , L_41 ,
} ;
static const char * const V_130 [ 11 ] = {
L_42 , L_43 , L_44 , L_45 ,
L_46 , L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 ,
} ;
static const char * const V_131 [ 11 ] = {
L_53 , L_54 , L_35 , L_55 ,
L_56 , L_57 , L_58 , L_59 ,
L_60 , L_61 , L_62 ,
} ;
static const char * const V_132 [ 8 ] = {
L_63 , L_64 , L_65 , L_66 ,
L_67 , L_22 , L_23 , L_24 ,
} ;
T_2 V_133 ;
const char * const * V_134 ;
V_133 = ( V_116 -> V_120 >> 12 ) & 0xf ;
switch ( ( V_116 -> V_120 >> 24 ) & 0x1f ) {
case V_135 :
V_134 = V_127 ;
break;
case V_136 :
if ( ( ( V_116 -> V_120 >> 20 ) & 0xf ) == 0 ) {
if ( V_116 -> V_120 & V_137 )
V_134 = V_128 ;
else
V_134 = V_129 ;
} else {
if ( V_116 -> V_120 & V_137 )
V_134 = V_130 ;
else
V_134 = V_131 ;
}
break;
case V_138 :
V_134 = V_132 ;
break;
default:
return - V_139 ;
}
return F_55 ( V_126 , 1 , V_133 + 1 , V_134 ) ;
}
static int F_56 ( struct V_115 * V_116 ,
struct V_125 * V_126 )
{
V_126 -> type = V_140 ;
V_126 -> V_141 = 1 ;
V_126 -> V_4 . integer . V_142 = ( V_116 -> V_120 >> 8 ) & 0xf ;
V_126 -> V_4 . integer . V_133 = ( V_116 -> V_120 >> 12 ) & 0xf ;
return 0 ;
}
static void F_57 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_4 , V_121 , V_143 ;
T_2 V_142 , V_133 , V_144 ;
T_1 V_145 , V_123 ;
bool V_122 ;
if ( ( V_12 -> V_18 [ V_146 ] & V_147 ) ==
V_148 )
V_143 = V_137 ;
else
V_143 = V_149 ;
if ( ! ( V_116 -> V_120 & V_143 ) )
return;
V_4 = V_116 -> V_120 & 0xf ;
V_142 = ( V_116 -> V_120 >> 8 ) & 0xf ;
V_133 = ( V_116 -> V_120 >> 12 ) & 0xf ;
V_145 = ( V_116 -> V_120 >> 16 ) & 0xf ;
V_144 = ( V_116 -> V_120 >> 20 ) & 0xf ;
V_121 = ( V_116 -> V_120 >> 24 ) & 0x1f ;
V_122 = ( V_116 -> V_120 >> 29 ) & 0x1 ;
if ( V_122 )
V_4 = V_133 - ( V_4 - V_142 ) ;
V_123 = V_12 -> V_18 [ V_121 ] ;
V_123 &= ~ ( V_145 << V_144 ) ;
V_123 |= V_4 << V_144 ;
F_7 ( V_2 , V_121 , V_123 ) ;
}
static int F_58 ( struct V_115 * V_116 , unsigned int V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
T_2 V_142 , V_133 ;
int V_124 ;
V_142 = ( V_116 -> V_120 >> 8 ) & 0xf ;
V_133 = ( V_116 -> V_120 >> 12 ) & 0xf ;
if ( V_4 < V_142 || V_4 > V_133 )
return - V_150 ;
F_15 ( & V_2 -> V_71 ) ;
V_124 = V_4 != ( V_116 -> V_120 & 0xf ) ;
if ( V_124 ) {
V_116 -> V_120 = ( V_116 -> V_120 & ~ 0xf ) | V_4 ;
F_57 ( V_116 ) ;
}
F_19 ( & V_2 -> V_71 ) ;
return V_124 ;
}
static int F_59 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
V_4 -> V_4 . V_151 . V_152 [ 0 ] = V_116 -> V_120 & 0xf ;
return 0 ;
}
static int F_60 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
V_4 -> V_4 . integer . V_4 [ 0 ] = V_116 -> V_120 & 0xf ;
return 0 ;
}
static int F_61 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
return F_58 ( V_116 , V_4 -> V_4 . V_151 . V_152 [ 0 ] ) ;
}
static int F_62 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
return F_58 ( V_116 , V_4 -> V_4 . integer . V_4 [ 0 ] ) ;
}
static int F_63 ( struct V_115 * V_116 ,
struct V_125 * V_126 )
{
V_126 -> type = V_140 ;
V_126 -> V_141 = 2 ;
V_126 -> V_4 . integer . V_142 = 0x79 - 60 ;
V_126 -> V_4 . integer . V_133 = 0x7f ;
return 0 ;
}
static int F_64 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_15 ( & V_2 -> V_71 ) ;
V_4 -> V_4 . integer . V_4 [ 0 ] =
V_12 -> V_18 [ V_19 ] & V_153 ;
V_4 -> V_4 . integer . V_4 [ 1 ] =
V_12 -> V_18 [ V_42 ] & V_153 ;
F_19 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_65 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
T_2 V_154 ;
F_15 ( & V_2 -> V_71 ) ;
V_154 = ( V_4 -> V_4 . integer . V_4 [ 0 ] !=
( V_12 -> V_18 [ V_19 ] & V_153 ) )
<< 0 ;
V_154 |= ( V_4 -> V_4 . integer . V_4 [ 1 ] !=
( V_12 -> V_18 [ V_42 ] & V_153 ) )
<< 1 ;
if ( V_4 -> V_4 . integer . V_4 [ 0 ] == V_4 -> V_4 . integer . V_4 [ 1 ] ) {
if ( V_154 ) {
F_5 ( V_2 , V_155 ,
V_4 -> V_4 . integer . V_4 [ 0 ] |
V_60 | V_21 ) ;
V_12 -> V_18 [ V_19 ] =
V_4 -> V_4 . integer . V_4 [ 0 ] | V_60 ;
V_12 -> V_18 [ V_42 ] =
V_4 -> V_4 . integer . V_4 [ 0 ] | V_60 ;
}
} else {
if ( V_154 & 1 )
F_5 ( V_2 , V_19 ,
V_4 -> V_4 . integer . V_4 [ 0 ] |
V_60 |
( ( V_154 & 2 ) ? 0 : V_21 ) ) ;
if ( V_154 & 2 )
F_5 ( V_2 , V_42 ,
V_4 -> V_4 . integer . V_4 [ 1 ] |
V_60 | V_21 ) ;
}
F_19 ( & V_2 -> V_71 ) ;
return V_154 != 0 ;
}
static int F_66 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_156 = V_116 -> V_120 ;
V_4 -> V_4 . integer . V_4 [ 0 ] =
! ! ( V_12 -> V_18 [ V_45 ] & V_156 ) ;
return 0 ;
}
static int F_67 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_115 * V_157 ;
unsigned int V_156 = V_116 -> V_120 ;
T_1 V_3 ;
int V_124 ;
F_15 ( & V_2 -> V_71 ) ;
V_3 = V_12 -> V_18 [ V_45 ] ;
if ( V_4 -> V_4 . integer . V_4 [ 0 ] ) {
V_3 |= V_156 ;
V_156 ^= 3 ;
if ( V_3 & V_156 ) {
V_3 &= ~ V_156 ;
if ( V_156 == 1 )
V_157 = V_12 -> V_158 ;
else
V_157 = V_12 -> V_159 ;
F_68 ( V_2 -> V_87 , V_160 ,
& V_157 -> V_161 ) ;
}
} else
V_3 &= ~ V_156 ;
V_124 = V_3 != V_12 -> V_18 [ V_45 ] ;
if ( V_124 ) {
F_17 ( V_2 , V_72 ,
V_3 & 1 ? V_83 : 0 ,
V_83 ) ;
F_5 ( V_2 , V_45 , V_3 ) ;
}
F_19 ( & V_2 -> V_71 ) ;
return V_124 ;
}
static int F_69 ( struct V_115 * V_116 ,
struct V_125 * V_126 )
{
V_126 -> type = V_140 ;
V_126 -> V_141 = 2 ;
V_126 -> V_4 . integer . V_142 = 0xa5 ;
V_126 -> V_4 . integer . V_133 = 0xff ;
return 0 ;
}
static int F_70 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_15 ( & V_2 -> V_71 ) ;
V_4 -> V_4 . integer . V_4 [ 0 ] =
V_12 -> V_18 [ V_43 ] & V_162 ;
V_4 -> V_4 . integer . V_4 [ 1 ] =
V_12 -> V_18 [ V_44 ] & V_162 ;
F_19 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_71 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
int V_124 = 0 ;
F_15 ( & V_2 -> V_71 ) ;
V_124 = ( V_4 -> V_4 . integer . V_4 [ 0 ] !=
( V_12 -> V_18 [ V_43 ] & V_162 ) ) ||
( V_4 -> V_4 . integer . V_4 [ 1 ] !=
( V_12 -> V_18 [ V_44 ] & V_162 ) ) ;
F_7 ( V_2 , V_43 ,
V_4 -> V_4 . integer . V_4 [ 0 ] | V_67 ) ;
F_7 ( V_2 , V_44 ,
V_4 -> V_4 . integer . V_4 [ 1 ] | V_67 ) ;
F_19 ( & V_2 -> V_71 ) ;
return V_124 ;
}
static int F_72 ( struct V_115 * V_116 ,
struct V_125 * V_126 )
{
static const char * const V_134 [ 3 ] = {
L_68 , L_69 , L_70
} ;
return F_55 ( V_126 , 1 , 3 , V_134 ) ;
}
static int F_73 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
if ( ! ( V_12 -> V_18 [ V_135 ] & V_163 ) )
V_4 -> V_4 . V_151 . V_152 [ 0 ] = 0 ;
else if ( ( V_12 -> V_18 [ V_146 ] & V_147 ) ==
V_148 )
V_4 -> V_4 . V_151 . V_152 [ 0 ] = 1 ;
else
V_4 -> V_4 . V_151 . V_152 [ 0 ] = 2 ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_115 * V_116 , unsigned int V_143 )
{
unsigned int V_164 ;
if ( V_116 -> V_120 & V_143 )
V_164 = 0 ;
else
V_164 = V_165 ;
if ( ( V_116 -> V_166 [ 0 ] . V_164 & V_165 ) != V_164 ) {
V_116 -> V_166 [ 0 ] . V_164 ^= V_165 ;
F_68 ( V_2 -> V_87 , V_167 , & V_116 -> V_161 ) ;
}
}
static int F_75 ( struct V_115 * V_116 ,
struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_143 = 0 , V_109 ;
T_1 V_168 , V_169 ;
int V_124 ;
if ( V_4 -> V_4 . V_151 . V_152 [ 0 ] >= 3 )
return - V_150 ;
F_15 ( & V_2 -> V_71 ) ;
V_124 = V_4 -> V_4 . V_151 . V_152 [ 0 ] != V_116 -> V_120 ;
if ( V_124 ) {
V_116 -> V_120 = V_4 -> V_4 . V_151 . V_152 [ 0 ] ;
V_168 = V_12 -> V_18 [ V_146 ] ;
V_169 = V_12 -> V_18 [ V_135 ] ;
switch ( V_4 -> V_4 . V_151 . V_152 [ 0 ] ) {
default:
F_7 ( V_2 , V_135 ,
V_169 & ~ V_163 ) ;
break;
case 1 :
F_7 ( V_2 , V_146 ,
( V_168 & ~ V_147 ) |
V_148 ) ;
F_7 ( V_2 , V_135 ,
V_169 | V_163 ) ;
V_143 = V_137 ;
break;
case 2 :
F_7 ( V_2 , V_146 ,
( V_168 & ~ V_147 ) |
V_170 ) ;
F_7 ( V_2 , V_135 ,
V_169 | V_163 ) ;
V_143 = V_149 ;
break;
}
for ( V_109 = 0 ; V_109 < F_6 ( V_12 -> V_171 ) ; ++ V_109 )
F_74 ( V_2 , V_12 -> V_171 [ V_109 ] , V_143 ) ;
}
F_19 ( & V_2 -> V_71 ) ;
return V_124 ;
}
static int F_76 ( struct V_115 * V_116 , struct V_125 * V_126 )
{
static const char * const V_134 [ 2 ] = {
L_68 , L_71
} ;
return F_55 ( V_126 , 1 , 2 , V_134 ) ;
}
static int F_77 ( struct V_115 * V_116 , struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
V_4 -> V_4 . V_151 . V_152 [ 0 ] =
! ( V_12 -> V_18 [ V_39 ] & V_172 ) ;
return 0 ;
}
static int F_78 ( struct V_115 * V_116 , struct V_117 * V_4 )
{
struct V_1 * V_2 = V_116 -> V_118 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_3 ;
int V_124 ;
F_15 ( & V_2 -> V_71 ) ;
V_3 = V_12 -> V_18 [ V_39 ] & ~ V_172 ;
if ( ! V_4 -> V_4 . V_151 . V_152 [ 0 ] )
V_3 |= V_172 ;
V_124 = V_3 != V_12 -> V_18 [ V_39 ] ;
if ( V_124 )
F_5 ( V_2 , V_39 , V_3 ) ;
F_19 ( & V_2 -> V_71 ) ;
return V_124 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_109 ;
struct V_115 * V_116 ;
int V_173 ;
F_80 ( F_6 ( V_171 ) != F_6 ( V_12 -> V_171 ) ) ;
for ( V_109 = 0 ; V_109 < F_6 ( V_171 ) ; ++ V_109 ) {
V_116 = F_81 ( & V_171 [ V_109 ] , V_2 ) ;
if ( ! V_116 )
return - V_174 ;
V_173 = F_82 ( V_2 -> V_87 , V_116 ) ;
if ( V_173 < 0 )
return V_173 ;
V_12 -> V_171 [ V_109 ] = V_116 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_109 ;
struct V_115 * V_116 ;
int V_173 ;
for ( V_109 = 0 ; V_109 < F_6 ( V_175 ) ; ++ V_109 ) {
V_116 = F_81 ( & V_175 [ V_109 ] , V_2 ) ;
if ( ! V_116 )
return - V_174 ;
V_173 = F_82 ( V_2 -> V_87 , V_116 ) ;
if ( V_173 < 0 )
return V_173 ;
if ( ! strcmp ( V_116 -> V_161 . V_176 , L_72 ) )
V_12 -> V_158 = V_116 ;
else if ( ! strcmp ( V_116 -> V_161 . V_176 , L_73 ) )
V_12 -> V_159 = V_116 ;
}
if ( ! V_12 -> V_158 || ! V_12 -> V_159 )
return - V_139 ;
return F_79 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
unsigned int V_109 ;
struct V_115 * V_116 ;
int V_173 ;
for ( V_109 = 0 ; V_109 < F_6 ( V_177 ) ; ++ V_109 ) {
V_116 = F_81 ( & V_177 [ V_109 ] , V_2 ) ;
if ( ! V_116 )
return - V_174 ;
V_173 = F_82 ( V_2 -> V_87 , V_116 ) ;
if ( V_173 < 0 )
return V_173 ;
}
return F_79 ( V_2 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_178 * V_179 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_109 ;
F_86 ( V_179 , L_74 ) ;
for ( V_109 = 0 ; V_109 < 0x10 ; ++ V_109 )
F_86 ( V_179 , L_75 , V_12 -> V_18 [ V_109 ] ) ;
F_86 ( V_179 , L_76 ) ;
for ( V_109 = 0x10 ; V_109 < 0x17 ; ++ V_109 )
F_86 ( V_179 , L_75 , V_12 -> V_18 [ V_109 ] ) ;
F_86 ( V_179 , L_77 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_178 * V_179 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_109 ;
F_85 ( V_2 , V_179 ) ;
F_86 ( V_179 , L_78 ) ;
for ( V_109 = 0 ; V_109 < 0x10 ; ++ V_109 )
F_86 ( V_179 , L_75 , V_12 -> V_22 [ V_109 ] ) ;
F_86 ( V_179 , L_77 ) ;
}
int T_3 F_88 ( struct V_1 * V_2 ,
const struct V_180 * V_161 )
{
switch ( V_161 -> V_181 ) {
case 0x838e :
V_2 -> V_14 = V_182 ;
break;
case 0x835e :
V_2 -> V_14 = V_183 ;
break;
default:
return - V_150 ;
}
return 0 ;
}
