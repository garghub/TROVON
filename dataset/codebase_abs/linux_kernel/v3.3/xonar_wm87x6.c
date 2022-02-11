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
F_5 ( V_2 , V_29 , V_30 ) ;
F_5 ( V_2 , V_31 , V_32 |
V_33 | V_34 ) ;
F_5 ( V_2 , V_35 , V_2 -> V_36 ? V_37 : 0 ) ;
F_5 ( V_2 , V_38 ,
V_39 | V_40 ) ;
F_5 ( V_2 , V_41 ,
V_12 -> V_18 [ V_41 ] ) ;
F_5 ( V_2 , V_42 , V_12 -> V_18 [ V_42 ] ) ;
F_5 ( V_2 , V_43 , V_12 -> V_18 [ V_43 ] ) ;
F_5 ( V_2 , V_19 , V_12 -> V_18 [ V_19 ] ) ;
F_5 ( V_2 , V_44 , V_12 -> V_18 [ V_44 ] |
V_21 ) ;
F_5 ( V_2 , V_45 , V_12 -> V_18 [ V_45 ] ) ;
F_5 ( V_2 , V_46 , V_12 -> V_18 [ V_46 ] ) ;
F_5 ( V_2 , V_47 , V_12 -> V_18 [ V_47 ] ) ;
F_5 ( V_2 , V_48 , V_2 -> V_49 [ 0 ] ) ;
F_5 ( V_2 , V_50 , V_2 -> V_49 [ 1 ] | V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_8 ( V_2 , V_51 , 0 ) ;
F_8 ( V_2 , V_52 , V_12 -> V_22 [ V_52 ] ) ;
F_8 ( V_2 , V_53 , V_54 | V_55 ) ;
F_8 ( V_2 , V_56 ,
V_57 | ( V_2 -> V_36 ? V_58 : 0 ) ) ;
F_8 ( V_2 , V_23 , V_2 -> V_49 [ 2 ] ) ;
F_8 ( V_2 , V_24 , V_2 -> V_49 [ 3 ] ) ;
F_8 ( V_2 , V_25 , V_2 -> V_49 [ 4 ] ) ;
F_8 ( V_2 , V_59 , V_2 -> V_49 [ 5 ] ) ;
F_8 ( V_2 , V_60 , V_2 -> V_49 [ 6 ] ) ;
F_8 ( V_2 , V_61 , V_2 -> V_49 [ 7 ] | V_27 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_18 [ V_19 ] = ( 0x79 - 60 ) | V_62 ;
V_12 -> V_18 [ V_44 ] = ( 0x79 - 60 ) | V_62 ;
V_12 -> V_18 [ V_41 ] =
V_63 | V_64 | V_65 ;
V_12 -> V_18 [ V_42 ] =
V_66 | V_67 ;
V_12 -> V_18 [ V_43 ] = V_68 ;
V_12 -> V_18 [ V_45 ] = 0xa5 | V_69 ;
V_12 -> V_18 [ V_46 ] = 0xa5 | V_69 ;
V_12 -> V_18 [ V_47 ] = 0x001 ;
F_10 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_22 [ V_52 ] =
V_70 | V_71 ;
F_11 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
bool V_72 ;
unsigned int V_3 ;
F_15 ( & V_2 -> V_73 ) ;
V_72 = ! ( F_16 ( V_2 , V_74 ) &
V_75 ) ;
F_17 ( V_2 , V_74 ,
V_72 ? 0 : V_76 ,
V_76 ) ;
V_3 = V_12 -> V_22 [ V_52 ] & ~ V_77 ;
if ( V_72 )
V_3 |= V_77 ;
F_9 ( V_2 , V_52 , V_3 ) ;
F_18 ( V_12 -> V_78 , V_72 ? V_79 : 0 ) ;
F_19 ( & V_2 -> V_73 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_80 . V_81 = 300 ;
V_12 -> V_80 . V_82 = V_83 ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_21 ( V_2 , V_84 ,
V_85 | V_76 ) ;
F_22 ( V_2 , V_84 ,
V_75 ) ;
F_21 ( V_2 , V_74 , V_85 ) ;
F_21 ( V_2 , V_86 , V_75 ) ;
V_2 -> V_87 |= V_88 ;
F_23 ( V_2 ) ;
F_24 ( V_2 -> V_89 , L_1 ,
V_79 , & V_12 -> V_78 ) ;
F_14 ( V_2 ) ;
F_25 ( V_2 -> V_89 , L_2 ) ;
F_25 ( V_2 -> V_89 , L_3 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_80 . V_81 = 300 ;
V_12 -> V_80 . V_82 = V_90 ;
F_12 ( V_2 ) ;
F_21 ( V_2 , V_84 ,
V_91 |
V_92 |
V_93 ) ;
F_27 ( V_2 , & V_12 -> V_94 ) ;
F_23 ( V_2 ) ;
F_25 ( V_2 -> V_89 , L_2 ) ;
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
F_37 ( V_2 , & V_12 -> V_94 ) ;
F_23 ( V_2 ) ;
}
static void F_38 ( unsigned int V_95 ,
struct V_96 * V_97 )
{
if ( V_95 == V_98 ) {
V_97 -> V_99 = V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 ;
V_97 -> V_106 = 96000 ;
}
}
static void F_39 ( unsigned int V_95 ,
struct V_96 * V_97 )
{
F_38 ( V_95 , V_97 ) ;
F_40 ( V_95 , V_97 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
}
static void F_42 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
T_1 V_3 ;
V_3 = V_66 | V_67 ;
if ( F_43 ( V_108 ) > 48000 )
V_3 |= V_109 ;
F_7 ( V_2 , V_42 , V_3 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_45 ( V_2 , & V_12 -> V_94 , V_108 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_2 V_110 ;
if ( V_2 -> V_49 [ 0 ] == V_2 -> V_49 [ 1 ] ) {
if ( V_2 -> V_49 [ 0 ] != V_12 -> V_18 [ V_48 ] ||
V_2 -> V_49 [ 1 ] != V_12 -> V_18 [ V_50 ] ) {
F_5 ( V_2 , V_20 ,
V_2 -> V_49 [ 0 ] | V_21 ) ;
V_12 -> V_18 [ V_48 ] = V_2 -> V_49 [ 0 ] ;
V_12 -> V_18 [ V_50 ] = V_2 -> V_49 [ 0 ] ;
}
} else {
V_110 = ( V_2 -> V_49 [ 0 ] !=
V_12 -> V_18 [ V_48 ] ) << 0 ;
V_110 |= ( V_2 -> V_49 [ 1 ] !=
V_12 -> V_18 [ V_48 ] ) << 1 ;
if ( V_110 & 1 )
F_5 ( V_2 , V_48 , V_2 -> V_49 [ 0 ] |
( ( V_110 & 2 ) ? 0 : V_21 ) ) ;
if ( V_110 & 2 )
F_5 ( V_2 , V_50 ,
V_2 -> V_49 [ 1 ] | V_21 ) ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
static const T_2 V_22 [ 6 ] = {
V_23 , V_24 ,
V_25 , V_59 ,
V_60 , V_61 ,
} ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_111 ;
T_2 V_110 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_49 [ 2 ] == V_2 -> V_49 [ 3 ] &&
V_2 -> V_49 [ 2 ] == V_2 -> V_49 [ 4 ] &&
V_2 -> V_49 [ 2 ] == V_2 -> V_49 [ 5 ] &&
V_2 -> V_49 [ 2 ] == V_2 -> V_49 [ 6 ] &&
V_2 -> V_49 [ 2 ] == V_2 -> V_49 [ 7 ] ) {
V_110 = 0 ;
for ( V_111 = 0 ; V_111 < 6 ; ++ V_111 )
if ( V_2 -> V_49 [ 2 ] !=
V_12 -> V_22 [ V_22 [ V_111 ] ] )
V_110 = 1 ;
if ( V_110 ) {
F_8 ( V_2 , V_26 ,
V_2 -> V_49 [ 2 ] | V_27 ) ;
for ( V_111 = 0 ; V_111 < 6 ; ++ V_111 )
V_12 -> V_22 [ V_22 [ V_111 ] ] =
V_2 -> V_49 [ 2 ] ;
}
} else {
V_110 = 0 ;
for ( V_111 = 0 ; V_111 < 6 ; ++ V_111 )
V_110 |= ( V_2 -> V_49 [ 2 + V_111 ] !=
V_12 -> V_22 [ V_22 [ V_111 ] ] ) << V_111 ;
for ( V_111 = 0 ; V_111 < 6 ; ++ V_111 )
if ( V_110 & ( 1 << V_111 ) )
F_8 ( V_2 , V_22 [ V_111 ] ,
V_2 -> V_49 [ 2 + V_111 ] |
( ( V_110 & ( 0x3e << V_111 ) )
? 0 : V_27 ) ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_35 ,
V_2 -> V_36 ? V_37 : 0 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
F_9 ( V_2 , V_56 , V_57 |
( V_2 -> V_36 ? V_58 : 0 ) ) ;
}
static void F_50 ( struct V_1 * V_2 , bool V_112 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_3 ;
V_3 = V_12 -> V_22 [ V_52 ] &
~ ( V_113 | V_114 ) ;
if ( V_112 )
V_3 |= V_115 | V_116 ;
else
V_3 |= V_70 | V_71 ;
F_9 ( V_2 , V_52 , V_3 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
}
static int F_52 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
T_1 V_121 = V_118 -> V_122 & 0xffff ;
unsigned int V_123 = ( V_118 -> V_122 >> 16 ) & 0xff ;
bool V_124 = ( V_118 -> V_122 >> 24 ) & 1 ;
V_4 -> V_4 . integer . V_4 [ 0 ] =
( ( V_12 -> V_18 [ V_123 ] & V_121 ) != 0 ) ^ V_124 ;
return 0 ;
}
static int F_53 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
T_1 V_121 = V_118 -> V_122 & 0xffff ;
T_1 V_125 ;
unsigned int V_123 = ( V_118 -> V_122 >> 16 ) & 0xff ;
bool V_124 = ( V_118 -> V_122 >> 24 ) & 1 ;
int V_126 ;
F_15 ( & V_2 -> V_73 ) ;
V_125 = V_12 -> V_18 [ V_123 ] & ~ V_121 ;
if ( V_4 -> V_4 . integer . V_4 [ 0 ] ^ V_124 )
V_125 |= V_121 ;
V_126 = V_125 != V_12 -> V_18 [ V_123 ] ;
if ( V_126 )
F_5 ( V_2 , V_123 , V_125 ) ;
F_19 ( & V_2 -> V_73 ) ;
return V_126 ;
}
static int F_54 ( struct V_117 * V_118 ,
struct V_127 * V_128 )
{
static const char * const V_129 [ 16 ] = {
L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 , L_11 ,
L_12 , L_13 , L_14 , L_15 ,
L_16 , L_17 , L_18 , L_19 ,
} ;
static const char * const V_130 [ 11 ] = {
L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 ,
} ;
static const char * const V_131 [ 11 ] = {
L_31 , L_32 , L_33 , L_34 ,
L_35 , L_36 , L_37 , L_38 ,
L_39 , L_40 , L_41 ,
} ;
static const char * const V_132 [ 11 ] = {
L_42 , L_43 , L_44 , L_45 ,
L_46 , L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 ,
} ;
static const char * const V_133 [ 11 ] = {
L_53 , L_54 , L_35 , L_55 ,
L_56 , L_57 , L_58 , L_59 ,
L_60 , L_61 , L_62 ,
} ;
static const char * const V_134 [ 8 ] = {
L_63 , L_64 , L_65 , L_66 ,
L_67 , L_22 , L_23 , L_24 ,
} ;
T_2 V_135 ;
const char * const * V_136 ;
V_135 = ( V_118 -> V_122 >> 12 ) & 0xf ;
switch ( ( V_118 -> V_122 >> 24 ) & 0x1f ) {
case V_137 :
V_136 = V_129 ;
break;
case V_138 :
if ( ( ( V_118 -> V_122 >> 20 ) & 0xf ) == 0 ) {
if ( V_118 -> V_122 & V_139 )
V_136 = V_130 ;
else
V_136 = V_131 ;
} else {
if ( V_118 -> V_122 & V_139 )
V_136 = V_132 ;
else
V_136 = V_133 ;
}
break;
case V_140 :
V_136 = V_134 ;
break;
default:
return - V_141 ;
}
return F_55 ( V_128 , 1 , V_135 + 1 , V_136 ) ;
}
static int F_56 ( struct V_117 * V_118 ,
struct V_127 * V_128 )
{
V_128 -> type = V_142 ;
V_128 -> V_143 = 1 ;
V_128 -> V_4 . integer . V_144 = ( V_118 -> V_122 >> 8 ) & 0xf ;
V_128 -> V_4 . integer . V_135 = ( V_118 -> V_122 >> 12 ) & 0xf ;
return 0 ;
}
static void F_57 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_4 , V_123 , V_145 ;
T_2 V_144 , V_135 , V_146 ;
T_1 V_147 , V_125 ;
bool V_124 ;
if ( ( V_12 -> V_18 [ V_148 ] & V_149 ) ==
V_150 )
V_145 = V_139 ;
else
V_145 = V_151 ;
if ( ! ( V_118 -> V_122 & V_145 ) )
return;
V_4 = V_118 -> V_122 & 0xf ;
V_144 = ( V_118 -> V_122 >> 8 ) & 0xf ;
V_135 = ( V_118 -> V_122 >> 12 ) & 0xf ;
V_147 = ( V_118 -> V_122 >> 16 ) & 0xf ;
V_146 = ( V_118 -> V_122 >> 20 ) & 0xf ;
V_123 = ( V_118 -> V_122 >> 24 ) & 0x1f ;
V_124 = ( V_118 -> V_122 >> 29 ) & 0x1 ;
if ( V_124 )
V_4 = V_135 - ( V_4 - V_144 ) ;
V_125 = V_12 -> V_18 [ V_123 ] ;
V_125 &= ~ ( V_147 << V_146 ) ;
V_125 |= V_4 << V_146 ;
F_7 ( V_2 , V_123 , V_125 ) ;
}
static int F_58 ( struct V_117 * V_118 , unsigned int V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
T_2 V_144 , V_135 ;
int V_126 ;
V_144 = ( V_118 -> V_122 >> 8 ) & 0xf ;
V_135 = ( V_118 -> V_122 >> 12 ) & 0xf ;
if ( V_4 < V_144 || V_4 > V_135 )
return - V_152 ;
F_15 ( & V_2 -> V_73 ) ;
V_126 = V_4 != ( V_118 -> V_122 & 0xf ) ;
if ( V_126 ) {
V_118 -> V_122 = ( V_118 -> V_122 & ~ 0xf ) | V_4 ;
F_57 ( V_118 ) ;
}
F_19 ( & V_2 -> V_73 ) ;
return V_126 ;
}
static int F_59 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
V_4 -> V_4 . V_153 . V_154 [ 0 ] = V_118 -> V_122 & 0xf ;
return 0 ;
}
static int F_60 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
V_4 -> V_4 . integer . V_4 [ 0 ] = V_118 -> V_122 & 0xf ;
return 0 ;
}
static int F_61 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
return F_58 ( V_118 , V_4 -> V_4 . V_153 . V_154 [ 0 ] ) ;
}
static int F_62 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
return F_58 ( V_118 , V_4 -> V_4 . integer . V_4 [ 0 ] ) ;
}
static int F_63 ( struct V_117 * V_118 ,
struct V_127 * V_128 )
{
V_128 -> type = V_142 ;
V_128 -> V_143 = 2 ;
V_128 -> V_4 . integer . V_144 = 0x79 - 60 ;
V_128 -> V_4 . integer . V_135 = 0x7f ;
return 0 ;
}
static int F_64 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_15 ( & V_2 -> V_73 ) ;
V_4 -> V_4 . integer . V_4 [ 0 ] =
V_12 -> V_18 [ V_19 ] & V_155 ;
V_4 -> V_4 . integer . V_4 [ 1 ] =
V_12 -> V_18 [ V_44 ] & V_155 ;
F_19 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_65 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
T_2 V_156 ;
F_15 ( & V_2 -> V_73 ) ;
V_156 = ( V_4 -> V_4 . integer . V_4 [ 0 ] !=
( V_12 -> V_18 [ V_19 ] & V_155 ) )
<< 0 ;
V_156 |= ( V_4 -> V_4 . integer . V_4 [ 1 ] !=
( V_12 -> V_18 [ V_44 ] & V_155 ) )
<< 1 ;
if ( V_4 -> V_4 . integer . V_4 [ 0 ] == V_4 -> V_4 . integer . V_4 [ 1 ] ) {
if ( V_156 ) {
F_5 ( V_2 , V_157 ,
V_4 -> V_4 . integer . V_4 [ 0 ] |
V_62 | V_21 ) ;
V_12 -> V_18 [ V_19 ] =
V_4 -> V_4 . integer . V_4 [ 0 ] | V_62 ;
V_12 -> V_18 [ V_44 ] =
V_4 -> V_4 . integer . V_4 [ 0 ] | V_62 ;
}
} else {
if ( V_156 & 1 )
F_5 ( V_2 , V_19 ,
V_4 -> V_4 . integer . V_4 [ 0 ] |
V_62 |
( ( V_156 & 2 ) ? 0 : V_21 ) ) ;
if ( V_156 & 2 )
F_5 ( V_2 , V_44 ,
V_4 -> V_4 . integer . V_4 [ 1 ] |
V_62 | V_21 ) ;
}
F_19 ( & V_2 -> V_73 ) ;
return V_156 != 0 ;
}
static int F_66 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_158 = V_118 -> V_122 ;
V_4 -> V_4 . integer . V_4 [ 0 ] =
! ! ( V_12 -> V_18 [ V_47 ] & V_158 ) ;
return 0 ;
}
static int F_67 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_117 * V_159 ;
unsigned int V_158 = V_118 -> V_122 ;
T_1 V_3 ;
int V_126 ;
F_15 ( & V_2 -> V_73 ) ;
V_3 = V_12 -> V_18 [ V_47 ] ;
if ( V_4 -> V_4 . integer . V_4 [ 0 ] ) {
V_3 |= V_158 ;
V_158 ^= 3 ;
if ( V_3 & V_158 ) {
V_3 &= ~ V_158 ;
if ( V_158 == 1 )
V_159 = V_12 -> V_160 ;
else
V_159 = V_12 -> V_161 ;
F_68 ( V_2 -> V_89 , V_162 ,
& V_159 -> V_163 ) ;
}
} else
V_3 &= ~ V_158 ;
V_126 = V_3 != V_12 -> V_18 [ V_47 ] ;
if ( V_126 ) {
F_17 ( V_2 , V_74 ,
V_3 & 1 ? V_85 : 0 ,
V_85 ) ;
F_5 ( V_2 , V_47 , V_3 ) ;
}
F_19 ( & V_2 -> V_73 ) ;
return V_126 ;
}
static int F_69 ( struct V_117 * V_118 ,
struct V_127 * V_128 )
{
V_128 -> type = V_142 ;
V_128 -> V_143 = 2 ;
V_128 -> V_4 . integer . V_144 = 0xa5 ;
V_128 -> V_4 . integer . V_135 = 0xff ;
return 0 ;
}
static int F_70 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_15 ( & V_2 -> V_73 ) ;
V_4 -> V_4 . integer . V_4 [ 0 ] =
V_12 -> V_18 [ V_45 ] & V_164 ;
V_4 -> V_4 . integer . V_4 [ 1 ] =
V_12 -> V_18 [ V_46 ] & V_164 ;
F_19 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_71 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
int V_126 = 0 ;
F_15 ( & V_2 -> V_73 ) ;
V_126 = ( V_4 -> V_4 . integer . V_4 [ 0 ] !=
( V_12 -> V_18 [ V_45 ] & V_164 ) ) ||
( V_4 -> V_4 . integer . V_4 [ 1 ] !=
( V_12 -> V_18 [ V_46 ] & V_164 ) ) ;
F_7 ( V_2 , V_45 ,
V_4 -> V_4 . integer . V_4 [ 0 ] | V_69 ) ;
F_7 ( V_2 , V_46 ,
V_4 -> V_4 . integer . V_4 [ 1 ] | V_69 ) ;
F_19 ( & V_2 -> V_73 ) ;
return V_126 ;
}
static int F_72 ( struct V_117 * V_118 ,
struct V_127 * V_128 )
{
static const char * const V_136 [ 3 ] = {
L_68 , L_69 , L_70
} ;
return F_55 ( V_128 , 1 , 3 , V_136 ) ;
}
static int F_73 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
if ( ! ( V_12 -> V_18 [ V_137 ] & V_165 ) )
V_4 -> V_4 . V_153 . V_154 [ 0 ] = 0 ;
else if ( ( V_12 -> V_18 [ V_148 ] & V_149 ) ==
V_150 )
V_4 -> V_4 . V_153 . V_154 [ 0 ] = 1 ;
else
V_4 -> V_4 . V_153 . V_154 [ 0 ] = 2 ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned int V_145 )
{
unsigned int V_166 ;
if ( V_118 -> V_122 & V_145 )
V_166 = 0 ;
else
V_166 = V_167 ;
if ( ( V_118 -> V_168 [ 0 ] . V_166 & V_167 ) != V_166 ) {
V_118 -> V_168 [ 0 ] . V_166 ^= V_167 ;
F_68 ( V_2 -> V_89 , V_169 , & V_118 -> V_163 ) ;
}
}
static int F_75 ( struct V_117 * V_118 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_145 = 0 , V_111 ;
T_1 V_170 , V_171 ;
int V_126 ;
if ( V_4 -> V_4 . V_153 . V_154 [ 0 ] >= 3 )
return - V_152 ;
F_15 ( & V_2 -> V_73 ) ;
V_126 = V_4 -> V_4 . V_153 . V_154 [ 0 ] != V_118 -> V_122 ;
if ( V_126 ) {
V_118 -> V_122 = V_4 -> V_4 . V_153 . V_154 [ 0 ] ;
V_170 = V_12 -> V_18 [ V_148 ] ;
V_171 = V_12 -> V_18 [ V_137 ] ;
switch ( V_4 -> V_4 . V_153 . V_154 [ 0 ] ) {
default:
F_7 ( V_2 , V_137 ,
V_171 & ~ V_165 ) ;
break;
case 1 :
F_7 ( V_2 , V_148 ,
( V_170 & ~ V_149 ) |
V_150 ) ;
F_7 ( V_2 , V_137 ,
V_171 | V_165 ) ;
V_145 = V_139 ;
break;
case 2 :
F_7 ( V_2 , V_148 ,
( V_170 & ~ V_149 ) |
V_172 ) ;
F_7 ( V_2 , V_137 ,
V_171 | V_165 ) ;
V_145 = V_151 ;
break;
}
for ( V_111 = 0 ; V_111 < F_6 ( V_12 -> V_173 ) ; ++ V_111 )
F_74 ( V_2 , V_12 -> V_173 [ V_111 ] , V_145 ) ;
}
F_19 ( & V_2 -> V_73 ) ;
return V_126 ;
}
static int F_76 ( struct V_117 * V_118 , struct V_127 * V_128 )
{
static const char * const V_136 [ 2 ] = {
L_68 , L_71
} ;
return F_55 ( V_128 , 1 , 2 , V_136 ) ;
}
static int F_77 ( struct V_117 * V_118 , struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
V_4 -> V_4 . V_153 . V_154 [ 0 ] =
! ( V_12 -> V_18 [ V_41 ] & V_174 ) ;
return 0 ;
}
static int F_78 ( struct V_117 * V_118 , struct V_119 * V_4 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_3 ;
int V_126 ;
F_15 ( & V_2 -> V_73 ) ;
V_3 = V_12 -> V_18 [ V_41 ] & ~ V_174 ;
if ( ! V_4 -> V_4 . V_153 . V_154 [ 0 ] )
V_3 |= V_174 ;
V_126 = V_3 != V_12 -> V_18 [ V_41 ] ;
if ( V_126 )
F_5 ( V_2 , V_41 , V_3 ) ;
F_19 ( & V_2 -> V_73 ) ;
return V_126 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_111 ;
struct V_117 * V_118 ;
int V_175 ;
F_80 ( F_6 ( V_173 ) != F_6 ( V_12 -> V_173 ) ) ;
for ( V_111 = 0 ; V_111 < F_6 ( V_173 ) ; ++ V_111 ) {
V_118 = F_81 ( & V_173 [ V_111 ] , V_2 ) ;
if ( ! V_118 )
return - V_176 ;
V_175 = F_82 ( V_2 -> V_89 , V_118 ) ;
if ( V_175 < 0 )
return V_175 ;
V_12 -> V_173 [ V_111 ] = V_118 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_111 ;
struct V_117 * V_118 ;
int V_175 ;
for ( V_111 = 0 ; V_111 < F_6 ( V_177 ) ; ++ V_111 ) {
V_118 = F_81 ( & V_177 [ V_111 ] , V_2 ) ;
if ( ! V_118 )
return - V_176 ;
V_175 = F_82 ( V_2 -> V_89 , V_118 ) ;
if ( V_175 < 0 )
return V_175 ;
if ( ! strcmp ( V_118 -> V_163 . V_178 , L_72 ) )
V_12 -> V_160 = V_118 ;
else if ( ! strcmp ( V_118 -> V_163 . V_178 , L_73 ) )
V_12 -> V_161 = V_118 ;
}
if ( ! V_12 -> V_160 || ! V_12 -> V_161 )
return - V_141 ;
return F_79 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
unsigned int V_111 ;
struct V_117 * V_118 ;
int V_175 ;
for ( V_111 = 0 ; V_111 < F_6 ( V_179 ) ; ++ V_111 ) {
V_118 = F_81 ( & V_179 [ V_111 ] , V_2 ) ;
if ( ! V_118 )
return - V_176 ;
V_175 = F_82 ( V_2 -> V_89 , V_118 ) ;
if ( V_175 < 0 )
return V_175 ;
}
return F_79 ( V_2 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_111 ;
F_86 ( V_181 , L_74 ) ;
for ( V_111 = 0 ; V_111 < 0x10 ; ++ V_111 )
F_86 ( V_181 , L_75 , V_12 -> V_18 [ V_111 ] ) ;
F_86 ( V_181 , L_76 ) ;
for ( V_111 = 0x10 ; V_111 < 0x17 ; ++ V_111 )
F_86 ( V_181 , L_75 , V_12 -> V_18 [ V_111 ] ) ;
F_86 ( V_181 , L_77 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_111 ;
F_85 ( V_2 , V_181 ) ;
F_86 ( V_181 , L_78 ) ;
for ( V_111 = 0 ; V_111 < 0x10 ; ++ V_111 )
F_86 ( V_181 , L_75 , V_12 -> V_22 [ V_111 ] ) ;
F_86 ( V_181 , L_77 ) ;
}
int T_3 F_88 ( struct V_1 * V_2 ,
const struct V_182 * V_163 )
{
switch ( V_163 -> V_183 ) {
case 0x838e :
V_2 -> V_14 = V_184 ;
break;
case 0x835e :
V_2 -> V_14 = V_185 ;
break;
default:
return - V_152 ;
}
return 0 ;
}
