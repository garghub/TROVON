static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_4 -> V_7 -> V_8 ) {
case V_9 :
F_3 ( V_2 , V_10 ,
V_11 ,
V_4 -> V_7 -> V_12 ) ;
F_4 ( V_2 , V_13 , V_14 ) ;
F_5 ( V_6 , V_15 ,
L_1 ) ;
F_6 ( V_2 , V_10 , V_16 ) ;
break;
default:
F_7 ( V_6 , L_2 ) ;
break;
}
}
static bool F_8 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
T_1 V_19 ,
struct V_3 * V_4 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
bool V_22 = false ;
if ( V_4 -> V_23 == V_24 ) {
if ( ! ( F_9 ( V_2 , V_10 ) & V_16 ) ) {
V_4 -> V_7 -> V_25 ( V_2 ) ;
V_2 -> V_26 ++ ;
if ( V_2 -> V_26 >=
V_4 -> V_7 -> V_27 ) {
unsigned int V_28 , V_29 = 0 ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( V_19 & ( 1 << V_28 ) )
V_29 ++ ;
}
V_4 -> V_7 -> V_31 ( V_2 , V_29 ) ;
V_21 -> V_32 |= V_4 -> V_7 -> V_8 ;
V_4 -> V_23 = V_33 ;
V_22 = true ;
} else {
F_1 ( V_2 , V_4 ) ;
}
}
} else if ( ! ( V_21 -> V_32 & V_4 -> V_7 -> V_8 ) ) {
F_10 ( V_2 , V_4 ) ;
}
return V_22 ;
}
static bool F_11 ( struct V_1 * V_2 ,
struct V_17 * V_34 ,
T_1 V_19 ,
bool V_35 )
{
bool V_22 = true ;
struct V_3 * V_4 = V_2 -> V_36 ;
if ( V_4 &&
( V_4 -> V_23 == V_24 ||
V_4 -> V_23 == V_37 ) ) {
V_22 = F_8 ( V_2 , V_34 ,
V_19 , V_4 ) ;
if ( V_22 ) {
V_2 -> V_36 = V_4 = V_4 -> V_38 ;
if ( V_4 -> V_23 == V_37 ) {
V_22 = false ;
F_10 ( V_2 , V_4 ) ;
}
}
}
if ( V_35 && F_12 ( V_2 , V_34 ) ) {
F_13 ( V_2 , V_2 -> V_39 ) ;
F_14 ( V_2 , false ) ;
}
return V_22 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
if ( V_2 -> V_41 & F_16 ( V_28 ) ) {
V_2 -> V_42 [ V_28 ] +=
F_9 ( V_2 , F_17 ( V_28 ) ) ;
V_2 -> V_43 [ V_28 ] +=
F_9 ( V_2 , F_18 ( V_28 ) ) ;
V_2 -> V_44 [ V_28 ] +=
( V_45 ) F_9 ( V_2 , F_19 ( V_28 ) ) ;
F_5 ( F_2 ( V_2 ) , V_15 ,
L_3 ,
V_2 -> V_26 , V_28 , V_2 -> V_42 [ V_28 ] ,
V_2 -> V_43 [ V_28 ] ,
V_2 -> V_44 [ V_28 ] ) ;
}
}
}
static void F_20 ( struct V_1 * V_2 , T_1 V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_46 , V_47 , V_48 ;
T_2 V_49 , V_50 ;
V_45 V_51 , V_52 ;
int V_53 , V_28 ;
static const T_3 V_54 [ 3 ] = {
V_55 ,
V_56 ,
V_57 ,
} ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_47 = V_2 -> V_42 [ V_28 ] ;
V_46 = V_2 -> V_43 [ V_28 ] ;
V_48 = V_2 -> V_44 [ V_28 ] ;
F_5 ( V_6 , V_15 ,
L_4 , V_28 ) ;
F_5 ( V_6 , V_15 ,
L_5 ,
V_28 , V_2 -> V_44 [ V_28 ] ) ;
V_53 = 0 ;
if ( V_48 > 0x80000000 ) {
V_48 = ( 0xffffffff - V_48 ) + 1 ;
V_53 = 1 ;
}
F_5 ( V_6 , V_15 , L_6 ,
V_28 , V_47 ) ;
F_5 ( V_6 , V_15 , L_7 ,
V_28 , V_46 ) ;
F_5 ( V_6 , V_15 , L_8 , V_53 ) ;
V_50 = ( V_47 / 2 + V_46 / 2 ) / 256 ;
V_49 = V_46 / 64 ;
if ( ( V_50 != 0 ) && ( V_49 != 0 ) ) {
V_52 = V_48 / V_50 ;
V_51 = V_47 / V_49 - 64 ;
F_5 ( V_6 , V_15 , L_9 ,
V_28 , V_52 ) ;
F_5 ( V_6 , V_15 , L_10 ,
V_28 , V_51 ) ;
if ( V_52 >= 63 )
V_52 = 63 ;
else if ( V_52 <= - 63 )
V_52 = - 63 ;
if ( V_53 == 0x0 )
V_52 = - V_52 ;
if ( V_51 >= 63 )
V_51 = 63 ;
else if ( V_51 <= - 63 )
V_51 = - 63 ;
V_52 = V_52 & 0x7f ;
V_51 = V_51 & 0x7f ;
F_5 ( V_6 , V_15 ,
L_11 ,
V_28 , V_52 , V_51 ) ;
F_5 ( V_6 , V_15 ,
L_12 ,
V_54 [ V_28 ] ,
F_9 ( V_2 , V_54 [ V_28 ] ) ) ;
if ( F_21 ( V_2 ) &&
( V_52 == 63 || V_51 == 63 ||
V_52 == - 63 || V_51 == - 63 ) )
return;
F_3 ( V_2 , V_54 [ V_28 ] ,
V_58 ,
V_52 ) ;
F_3 ( V_2 , V_54 [ V_28 ] ,
V_59 ,
V_51 ) ;
F_5 ( V_6 , V_15 ,
L_13 ,
V_54 [ V_28 ] ,
V_58 ,
F_9 ( V_2 , V_54 [ V_28 ] ) ) ;
F_5 ( V_6 , V_15 ,
L_14 ,
V_54 [ V_28 ] ,
V_59 ,
F_9 ( V_2 , V_54 [ V_28 ] ) ) ;
F_5 ( V_6 , V_15 ,
L_15 , V_28 ) ;
}
}
F_6 ( V_2 , V_55 ,
V_60 ) ;
F_5 ( V_6 , V_15 ,
L_16 ,
( unsigned ) ( V_55 ) ,
V_60 ,
F_9 ( V_2 , V_55 ) ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_61 . V_7 = & V_62 ;
if ( F_23 ( V_2 ) ) {
V_2 -> V_63 |= V_64 ;
if ( F_24 ( V_2 ) && ! F_25 ( V_2 ) )
V_2 -> V_63 |= V_65 ;
}
V_2 -> V_66 = V_9 ;
}
static bool F_26 ( struct V_1 * V_2 ,
bool V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_68 , V_69 , V_70 , V_71 , V_72 ,
V_73 , V_74 , V_75 ;
int V_76 , V_77 , V_78 , V_79 , V_80 ,
V_81 , V_82 , V_83 ;
int V_84 , V_85 , V_86 , V_87 , V_88 ,
V_89 , V_90 , V_91 ;
bool V_92 ;
T_2 V_93 , V_94 ;
F_27 ( V_2 , V_95 ,
V_96 ) ;
F_27 ( V_2 , V_97 ,
V_98 ) ;
F_4 ( V_2 , V_95 ,
F_9 ( V_2 , V_95 ) | V_99 ) ;
V_92 = F_28 ( V_2 , V_95 ,
V_99 ,
0 , V_100 ) ;
if ( ! V_92 ) {
F_5 ( V_6 , V_15 ,
L_17 ) ;
return false ;
}
F_6 ( V_2 , V_95 ,
V_96 ) ;
F_27 ( V_2 , V_101 ,
V_102 ) ;
F_27 ( V_2 , V_95 ,
V_103 ) ;
F_27 ( V_2 , V_95 ,
V_104 ) ;
V_68 = 0 ;
V_76 = 0 ;
V_84 = 0 ;
while ( ( V_68 == 0 ) || ( V_76 == 0 ) || ( V_84 == 0 ) ) {
V_69 = ( F_9 ( V_2 , V_105 ) >> 30 ) & 0x3 ;
V_77 = ( F_9 ( V_2 , V_106 ) >> 30 ) & 0x3 ;
V_85 = ( F_9 ( V_2 , V_107 ) >> 30 ) & 0x3 ;
F_6 ( V_2 , V_108 , V_109 ) ;
F_4 ( V_2 , V_95 ,
F_9 ( V_2 , V_95 ) | V_99 ) ;
V_92 = F_28 ( V_2 , V_95 ,
V_99 ,
0 , V_100 ) ;
if ( ! V_92 ) {
F_5 ( V_6 , V_15 ,
L_18 ) ;
return false ;
}
F_27 ( V_2 , V_108 , V_109 ) ;
F_4 ( V_2 , V_110 ,
( ( F_9 ( V_2 , V_110 ) & 0xfffffcff ) | ( 1 << 8 ) ) ) ;
F_4 ( V_2 , V_111 ,
( ( F_9 ( V_2 , V_111 ) & 0xfffffcff ) | ( 1 << 8 ) ) ) ;
F_4 ( V_2 , V_112 ,
( ( F_9 ( V_2 , V_112 ) & 0xfffffcff ) | ( 1 << 8 ) ) ) ;
V_93 = F_9 ( V_2 , V_110 ) ;
V_70 = ( V_93 >> 26 ) & 0x1f ;
V_71 = ( V_93 >> 21 ) & 0x1f ;
V_93 = F_9 ( V_2 , V_111 ) ;
V_78 = ( V_93 >> 26 ) & 0x1f ;
V_79 = ( V_93 >> 21 ) & 0x1f ;
V_93 = F_9 ( V_2 , V_112 ) ;
V_86 = ( V_93 >> 26 ) & 0x1f ;
V_87 = ( V_93 >> 21 ) & 0x1f ;
F_4 ( V_2 , V_110 ,
( ( F_9 ( V_2 , V_110 ) & 0xfffffcff ) | ( 2 << 8 ) ) ) ;
F_4 ( V_2 , V_111 ,
( ( F_9 ( V_2 , V_111 ) & 0xfffffcff ) | ( 2 << 8 ) ) ) ;
F_4 ( V_2 , V_112 ,
( ( F_9 ( V_2 , V_112 ) & 0xfffffcff ) | ( 2 << 8 ) ) ) ;
V_93 = F_9 ( V_2 , V_110 ) ;
V_72 = ( V_93 >> 26 ) & 0x1f ;
V_73 = ( V_93 >> 21 ) & 0x1f ;
V_93 = F_9 ( V_2 , V_111 ) ;
V_80 = ( V_93 >> 26 ) & 0x1f ;
V_81 = ( V_93 >> 21 ) & 0x1f ;
V_93 = F_9 ( V_2 , V_112 ) ;
V_88 = ( V_93 >> 26 ) & 0x1f ;
V_89 = ( V_93 >> 21 ) & 0x1f ;
F_4 ( V_2 , V_110 ,
( ( F_9 ( V_2 , V_110 ) & 0xfffffcff ) | ( 3 << 8 ) ) ) ;
F_4 ( V_2 , V_111 ,
( ( F_9 ( V_2 , V_111 ) & 0xfffffcff ) | ( 3 << 8 ) ) ) ;
F_4 ( V_2 , V_112 ,
( ( F_9 ( V_2 , V_112 ) & 0xfffffcff ) | ( 3 << 8 ) ) ) ;
V_93 = F_9 ( V_2 , V_110 ) ;
V_74 = ( V_93 >> 26 ) & 0x1f ;
V_75 = ( V_93 >> 21 ) & 0x1f ;
V_93 = F_9 ( V_2 , V_111 ) ;
V_82 = ( V_93 >> 26 ) & 0x1f ;
V_83 = ( V_93 >> 21 ) & 0x1f ;
V_93 = F_9 ( V_2 , V_112 ) ;
V_90 = ( V_93 >> 26 ) & 0x1f ;
V_91 = ( V_93 >> 21 ) & 0x1f ;
if ( ( V_70 > V_113 ) || ( V_70 < V_114 ) ||
( V_72 > V_113 ) || ( V_72 < V_114 ) ||
( V_74 > V_113 ) || ( V_74 < V_114 ) ||
( V_71 > V_113 ) || ( V_71 < V_114 ) ||
( V_73 > V_113 ) || ( V_73 < V_114 ) ||
( V_75 > V_113 ) || ( V_75 < V_114 ) ) {
if ( V_69 == 3 ) {
V_68 = 1 ;
} else {
V_69 ++ ;
V_94 = F_9 ( V_2 , V_105 ) & 0x3fffffff ;
V_94 |= ( V_69 << 30 ) ;
F_4 ( V_2 , V_105 , V_94 ) ;
V_68 = 0 ;
}
} else {
V_68 = 1 ;
}
if ( ( V_78 > V_113 ) || ( V_78 < V_114 ) ||
( V_80 > V_113 ) || ( V_80 < V_114 ) ||
( V_82 > V_113 ) || ( V_82 < V_114 ) ||
( V_79 > V_113 ) || ( V_79 < V_114 ) ||
( V_81 > V_113 ) || ( V_81 < V_114 ) ||
( V_83 > V_113 ) || ( V_83 < V_114 ) ) {
if ( V_77 == 3 ) {
V_76 = 1 ;
} else {
V_77 ++ ;
V_94 = F_9 ( V_2 , V_106 ) & 0x3fffffff ;
V_94 |= ( V_77 << 30 ) ;
F_4 ( V_2 , V_106 , V_94 ) ;
V_76 = 0 ;
}
} else {
V_76 = 1 ;
}
if ( ( V_86 > V_113 ) || ( V_86 < V_114 ) ||
( V_88 > V_113 ) || ( V_88 < V_114 ) ||
( V_90 > V_113 ) || ( V_90 < V_114 ) ||
( V_87 > V_113 ) || ( V_87 < V_114 ) ||
( V_89 > V_113 ) || ( V_89 < V_114 ) ||
( V_91 > V_113 ) || ( V_91 < V_114 ) ) {
if ( V_85 == 3 ) {
V_84 = 1 ;
} else {
V_85 ++ ;
V_94 = F_9 ( V_2 , V_107 ) & 0x3fffffff ;
V_94 |= ( V_85 << 30 ) ;
F_4 ( V_2 , V_107 , V_94 ) ;
V_84 = 0 ;
}
} else {
V_84 = 1 ;
}
}
F_27 ( V_2 , V_95 ,
V_96 ) ;
F_6 ( V_2 , V_108 , V_109 ) ;
F_6 ( V_2 , V_97 ,
V_98 ) ;
return true ;
}
static bool F_29 ( struct V_1 * V_2 ,
T_4 V_115 ,
T_4 V_116 ,
T_4 V_117 ,
T_4 V_118 ,
T_4 V_119 ,
T_4 V_120 ,
T_4 V_121 ,
T_4 V_122 ,
T_4 V_123 [] )
{
T_4 V_124 = V_116 - V_118 ,
V_125 = V_115 - V_117 ,
V_126 ;
T_4 V_127 , V_128 , V_129 , V_130 ;
const T_4 V_131 = 1 << 15 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_126 = ( ( V_124 >> 3 ) * ( V_124 >> 3 ) + ( V_125 >> 3 ) * ( V_125 >> 3 ) ) >> 9 ;
if ( ! V_126 ) {
F_5 ( V_6 , V_15 , L_19 ) ;
return false ;
}
V_127 = V_124 * ( V_119 - V_121 ) + V_125 * ( V_120 - V_122 ) ;
V_128 = V_125 * ( - V_119 + V_121 ) + V_124 * ( V_120 - V_122 ) ;
V_127 = ( V_127 / V_126 ) ;
V_128 = ( V_128 / V_126 ) ;
V_129 = V_119 - ( V_116 * V_127 + V_115 * V_128 ) /
V_131 ;
V_130 = V_120 + ( V_115 * V_127 - V_116 * V_128 ) /
V_131 ;
V_123 [ 0 ] = V_127 ;
V_123 [ 1 ] = V_128 ;
V_123 [ 2 ] = V_129 ;
V_123 [ 3 ] = V_130 ;
return true ;
}
static T_4 F_30 ( struct V_1 * V_2 , T_4 V_132 , T_4 V_133 )
{
T_4 V_134 = abs ( V_132 ) ,
V_135 = abs ( V_133 ) ,
V_136 , V_137 ;
if ( V_134 > V_135 ) {
V_136 = V_134 ;
V_137 = V_135 ;
} else {
V_136 = V_135 ;
V_137 = V_134 ;
}
return V_136 - ( V_136 / 32 ) + ( V_137 / 8 ) + ( V_137 / 4 ) ;
}
static bool F_31 ( struct V_1 * V_2 ,
T_4 V_138 ,
const T_4 V_139 [] ,
T_4 V_140 [] )
{
T_4 V_141 , V_142 , V_143 ,
V_144 , V_145 , V_146 ,
V_147 , V_148 , V_149 ,
V_150 , V_151 , V_152 ;
T_4 V_119 , V_121 , V_153 , V_154 ,
V_120 , V_122 , V_155 , V_156 ,
V_115 , V_116 ,
V_117 , V_118 ;
T_4 V_127 , V_128 , V_129 , V_130 ;
T_4 V_123 [ 4 ] , V_157 , V_158 , V_159 , V_160 ,
V_161 , V_162 ;
const T_4 V_163 = 1 << 15 ;
const T_4 V_164 = 1 << 8 ;
T_4 V_165 , V_166 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_141 = V_139 [ 0 ] & 0xfff ;
V_142 = ( V_139 [ 0 ] >> 12 ) & 0xfff ;
V_143 = ( ( V_139 [ 0 ] >> 24 ) & 0xff ) + ( ( V_139 [ 1 ] & 0xf ) << 8 ) ;
if ( V_141 > 0x800 )
V_141 = - ( ( 0xfff - V_141 ) + 1 ) ;
if ( V_142 > 0x800 )
V_142 = - ( ( 0xfff - V_142 ) + 1 ) ;
if ( V_143 > 0x800 )
V_143 = - ( ( 0xfff - V_143 ) + 1 ) ;
V_144 = ( V_139 [ 1 ] >> 4 ) & 0xfff ;
V_145 = ( V_139 [ 2 ] & 0xfff ) ;
V_146 = ( V_139 [ 2 ] >> 12 ) & 0xfff ;
if ( V_144 > 0x800 )
V_144 = - ( ( 0xfff - V_144 ) + 1 ) ;
if ( V_145 > 0x1000 )
V_145 = - ( ( 0x1fff - V_145 ) + 1 ) ;
if ( V_146 > 0x800 )
V_146 = - ( ( 0xfff - V_146 ) + 1 ) ;
V_147 = ( ( V_139 [ 2 ] >> 24 ) & 0xff ) + ( ( V_139 [ 3 ] & 0xf ) << 8 ) ;
V_148 = ( V_139 [ 3 ] >> 4 ) & 0xfff ;
V_149 = V_139 [ 4 ] & 0xfff ;
if ( V_147 > 0x800 )
V_147 = - ( ( 0xfff - V_147 ) + 1 ) ;
if ( V_148 > 0x800 )
V_148 = - ( ( 0xfff - V_148 ) + 1 ) ;
if ( V_149 > 0x800 )
V_149 = - ( ( 0xfff - V_149 ) + 1 ) ;
V_150 = ( V_139 [ 4 ] >> 12 ) & 0xfff ;
V_151 = ( ( V_139 [ 4 ] >> 24 ) & 0xff ) + ( ( V_139 [ 5 ] & 0xf ) << 8 ) ;
V_152 = ( V_139 [ 5 ] >> 4 ) & 0xfff ;
if ( V_150 > 0x800 )
V_150 = - ( ( 0xfff - V_150 ) + 1 ) ;
if ( V_151 > 0x800 )
V_151 = - ( ( 0xfff - V_151 ) + 1 ) ;
if ( V_152 > 0x800 )
V_152 = - ( ( 0xfff - V_152 ) + 1 ) ;
if ( ( V_142 == 0 ) || ( V_145 == 0 ) ||
( V_148 == 0 ) || ( V_151 == 0 ) ) {
F_5 ( V_6 , V_15 ,
L_20
L_21
L_22
L_23
L_24 ,
V_142 , V_145 ,
V_148 , V_151 ) ;
return false ;
}
if ( ( V_142 < 1024 ) || ( V_142 > 2047 ) ||
( V_148 < 0 ) || ( V_151 < 0 ) ||
( V_142 <= V_141 ) ||
( V_142 <= V_143 ) ||
( V_145 <= V_144 ) ||
( V_145 <= V_146 ) ||
( V_148 <= V_147 ) ||
( V_148 <= V_149 ) ||
( V_151 <= V_150 ) ||
( V_151 <= V_152 ) ) {
return false ;
}
V_119 = ( V_141 * V_163 ) / V_142 ;
V_120 = ( V_143 * V_163 ) / V_142 ;
V_153 = ( V_144 * V_163 ) / V_145 ;
V_155 = ( V_146 * V_163 ) / V_145 ;
V_121 = ( V_147 * V_163 ) / V_148 ;
V_122 = ( V_149 * V_163 ) / V_148 ;
V_154 = ( V_150 * V_163 ) / V_151 ;
V_156 = ( V_152 * V_163 ) / V_151 ;
V_115 = ( ( ( V_119 - V_153 ) * V_164 ) / V_167 ) ;
V_116 = ( ( ( V_155 - V_120 ) * V_164 ) / V_167 ) ;
V_117 = ( ( ( V_121 - V_154 ) * V_164 ) / V_167 ) ;
V_118 = ( ( ( V_156 - V_122 ) * V_164 ) / V_167 ) ;
V_165 = F_30 ( V_2 , V_116 , V_115 ) ;
V_166 = F_30 ( V_2 , V_118 , V_117 ) ;
if ( ( V_165 == 0 ) || ( V_166 == 0 ) ) {
F_5 ( V_6 , V_15 , L_25 ,
V_165 , V_166 ) ;
return false ;
}
V_115 = ( V_115 * V_163 / V_165 ) ;
V_116 = ( V_116 * V_163 / V_165 ) ;
V_117 = ( V_117 * V_163 / V_166 ) ;
V_118 = ( V_118 * V_163 / V_166 ) ;
if ( ! F_29 ( V_2 ,
V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ,
V_122 , V_123 ) ) {
F_5 ( V_6 , V_15 ,
L_26 ) ;
return false ;
}
V_127 = V_123 [ 0 ] ;
V_128 = V_123 [ 1 ] ;
V_129 = V_123 [ 2 ] ;
V_130 = V_123 [ 3 ] ;
F_5 ( V_6 , V_15 ,
L_27 ,
V_138 , V_127 / V_163 , V_128 / V_163 ) ;
if ( V_163 == V_127 ) {
F_5 ( V_6 , V_15 ,
L_28 ,
V_127 , V_163 ) ;
return false ;
}
V_157 = ( V_127 * V_163 ) / ( V_163 - V_127 ) ;
V_158 = - V_128 ;
V_161 = ( V_157 * 128 / V_163 ) ;
V_162 = ( V_158 * 256 / V_163 ) ;
F_5 ( V_6 , V_15 , L_29 ,
V_138 , V_161 , V_162 ) ;
if ( V_162 < - 63 )
V_162 = - 63 ;
if ( V_162 > 63 )
V_162 = 63 ;
if ( V_161 < - 63 )
V_161 = - 63 ;
if ( V_161 > 63 )
V_161 = 63 ;
V_140 [ 0 ] = ( V_161 * 128 ) + V_162 ;
F_5 ( V_6 , V_15 , L_30 ,
V_138 , V_140 [ 0 ] ) ;
if ( - V_129 == V_163 ) {
F_5 ( V_6 , V_15 ,
L_31 ,
V_129 , V_163 ) ;
return false ;
}
V_159 = ( - V_129 * V_163 ) / ( V_163 + V_129 ) ;
V_160 = - V_130 ;
V_161 = ( V_159 * 128 / V_163 ) ;
V_162 = ( V_160 * 256 / V_163 ) ;
F_5 ( V_6 , V_15 , L_32 ,
V_138 , V_161 , V_162 ) ;
if ( V_162 < - 63 )
V_162 = - 63 ;
if ( V_162 > 63 )
V_162 = 63 ;
if ( V_161 < - 63 )
V_161 = - 63 ;
if ( V_161 > 63 )
V_161 = 63 ;
V_140 [ 1 ] = ( V_161 * 128 ) + V_162 ;
F_5 ( V_6 , V_15 , L_33 ,
V_138 , V_140 [ 1 ] ) ;
return true ;
}
static void F_32 ( int * V_168 , int V_169 ,
int V_170 )
{
int V_171 = - 64 , V_172 = 0 ;
int V_173 = 63 , V_174 = 0 ;
int V_175 = 0 , V_28 , V_176 = 0 , V_177 = 0 ;
for ( V_28 = 0 ; V_28 < V_169 ; V_28 ++ ) {
if ( V_168 [ V_28 ] > V_171 ) {
V_171 = V_168 [ V_28 ] ;
V_172 = V_28 ;
} else if ( V_168 [ V_28 ] < V_173 ) {
V_173 = V_168 [ V_28 ] ;
V_174 = V_28 ;
}
}
for ( V_28 = 0 ; V_28 < V_169 ; V_28 ++ ) {
if ( ( abs ( V_168 [ V_28 ] ) < abs ( V_171 ) ) ||
( abs ( V_168 [ V_28 ] ) < abs ( V_173 ) ) ) {
V_175 += V_168 [ V_28 ] ;
V_177 ++ ;
}
}
if ( V_177 )
V_175 /= V_177 ;
else
V_175 = V_168 [ V_169 - 1 ] ;
if ( abs ( V_171 - V_173 ) > V_170 ) {
if ( abs ( V_171 - V_175 ) > abs ( V_173 - V_175 ) )
V_176 = V_172 ;
else
V_176 = V_174 ;
V_168 [ V_176 ] = V_175 ;
}
}
static void F_33 ( struct V_1 * V_2 ,
struct V_178 * V_178 ,
bool V_179 )
{
int V_28 , V_180 , V_169 ;
T_2 V_181 [ V_182 ] [ V_30 ] ;
struct V_20 * V_21 = V_2 -> V_21 ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
for ( V_28 = 0 ; V_28 < V_182 / 2 ; V_28 ++ ) {
V_181 [ V_28 * 2 ] [ 0 ] = V_181 [ ( V_28 * 2 ) + 1 ] [ 0 ] =
F_34 ( V_28 ) ;
if ( ! F_35 ( V_2 ) ) {
V_181 [ V_28 * 2 ] [ 1 ] =
V_181 [ ( V_28 * 2 ) + 1 ] [ 1 ] =
F_36 ( V_28 ) ;
V_181 [ V_28 * 2 ] [ 2 ] =
V_181 [ ( V_28 * 2 ) + 1 ] [ 2 ] =
F_37 ( V_28 ) ;
}
}
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( ! ( V_2 -> V_41 & ( 1 << V_28 ) ) )
continue;
V_169 = F_38 ( V_2 ,
V_183 ,
V_184 ) ;
if ( V_169 > V_182 )
V_169 = V_182 ;
if ( V_169 > 1 ) {
F_32 ( V_178 -> V_185 [ V_28 ] ,
V_169 , V_186 ) ;
F_32 ( V_178 -> V_187 [ V_28 ] ,
V_169 , V_188 ) ;
}
for ( V_180 = 0 ; V_180 < V_169 ; V_180 ++ ) {
V_178 -> V_140 [ 0 ] = ( V_178 -> V_185 [ V_28 ] [ V_180 ] & 0x7f ) |
( ( V_178 -> V_187 [ V_28 ] [ V_180 ] & 0x7f ) << 7 ) ;
if ( ( V_180 % 2 ) == 0 )
F_3 ( V_2 , V_181 [ V_180 ] [ V_28 ] ,
V_189 ,
V_178 -> V_140 [ 0 ] ) ;
else
F_3 ( V_2 , V_181 [ V_180 ] [ V_28 ] ,
V_190 ,
V_178 -> V_140 [ 0 ] ) ;
if ( V_21 )
V_21 -> V_181 [ V_180 ] [ V_28 ] =
V_178 -> V_140 [ 0 ] ;
}
if ( V_21 )
V_21 -> V_191 [ V_28 ] = V_169 ;
}
F_3 ( V_2 , V_192 ,
V_193 , 0x1 ) ;
F_3 ( V_2 , V_55 ,
V_194 , 0x1 ) ;
if ( V_21 ) {
if ( V_179 )
F_39 ( V_195 , & V_21 -> V_196 ) ;
else
F_40 ( V_195 , & V_21 -> V_196 ) ;
}
return;
}
static bool F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_197 ;
V_197 = F_38 ( V_2 , V_198 ,
V_199 ) ;
if ( V_197 )
F_3 ( V_2 , V_198 ,
V_199 , 0 ) ;
F_3 ( V_2 , V_200 ,
V_201 , 1 ) ;
if ( ! F_28 ( V_2 , V_200 ,
V_201 , 0 ,
V_100 ) ) {
F_5 ( V_6 , V_15 , L_34 ) ;
return false ;
}
return true ;
}
static void F_42 ( struct V_1 * V_2 , bool V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const T_2 V_202 [ V_30 ] = {
V_183 ,
V_203 ,
V_204 ,
} ;
const T_3 V_205 [] = {
V_206 ,
V_207 ,
V_208 ,
} ;
struct V_178 V_178 ;
T_4 V_139 [ 6 ] ;
int V_28 , V_180 , V_209 ;
int V_169 ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( ! ( V_2 -> V_41 & ( 1 << V_28 ) ) )
continue;
V_169 = F_38 ( V_2 ,
V_183 ,
V_184 ) ;
if ( V_169 > V_182 )
V_169 = V_182 ;
for ( V_180 = 0 ; V_180 < V_169 ; V_180 ++ ) {
F_5 ( V_6 , V_15 ,
L_35 , V_28 ) ;
if ( F_9 ( V_2 , V_202 [ V_28 ] ) &
V_210 ) {
F_5 ( V_6 , V_15 ,
L_36 , V_28 ) ;
goto V_211;
}
for ( V_209 = 0 ; V_209 < 3 ; V_209 ++ ) {
T_2 V_212 = 2 * V_209 , V_213 = 4 * ( 3 * V_180 + V_209 ) ;
F_3 ( V_2 ,
V_214 ,
V_215 ,
0 ) ;
V_139 [ V_212 ] = F_9 ( V_2 ,
V_205 [ V_28 ] +
V_213 ) ;
F_3 ( V_2 ,
V_214 ,
V_215 ,
1 ) ;
V_139 [ V_212 + 1 ] = 0xffff & F_9 ( V_2 ,
V_205 [ V_28 ] + V_213 ) ;
F_5 ( V_6 , V_15 ,
L_37 ,
V_212 , V_139 [ V_212 ] , V_212 + 1 ,
V_139 [ V_212 + 1 ] ) ;
}
if ( ! F_31 ( V_2 , V_28 , V_139 ,
V_178 . V_140 ) ) {
F_5 ( V_6 , V_15 ,
L_38 ) ;
goto V_211;
}
V_178 . V_185 [ V_28 ] [ V_180 ] = V_178 . V_140 [ 0 ] & 0x7f ;
V_178 . V_187 [ V_28 ] [ V_180 ] =
( V_178 . V_140 [ 0 ] >> 7 ) & 0x7f ;
if ( V_178 . V_185 [ V_28 ] [ V_180 ] > 63 )
V_178 . V_185 [ V_28 ] [ V_180 ] -= 128 ;
if ( V_178 . V_187 [ V_28 ] [ V_180 ] > 63 )
V_178 . V_187 [ V_28 ] [ V_180 ] -= 128 ;
}
}
F_33 ( V_2 , & V_178 , V_179 ) ;
return;
V_211:
F_5 ( V_6 , V_15 , L_39 ) ;
return;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
T_2 V_181 [ V_182 ] [ V_30 ] ;
int V_28 , V_180 ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
for ( V_28 = 0 ; V_28 < V_182 / 2 ; V_28 ++ ) {
V_181 [ V_28 * 2 ] [ 0 ] = V_181 [ ( V_28 * 2 ) + 1 ] [ 0 ] =
F_34 ( V_28 ) ;
if ( ! F_35 ( V_2 ) ) {
V_181 [ V_28 * 2 ] [ 1 ] =
V_181 [ ( V_28 * 2 ) + 1 ] [ 1 ] =
F_36 ( V_28 ) ;
V_181 [ V_28 * 2 ] [ 2 ] =
V_181 [ ( V_28 * 2 ) + 1 ] [ 2 ] =
F_37 ( V_28 ) ;
}
}
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( ! ( V_2 -> V_41 & ( 1 << V_28 ) ) )
continue;
for ( V_180 = 0 ; V_180 < V_21 -> V_191 [ V_28 ] ; V_180 ++ ) {
if ( ( V_180 % 2 ) == 0 )
F_3 ( V_2 , V_181 [ V_180 ] [ V_28 ] ,
V_189 ,
V_21 -> V_181 [ V_180 ] [ V_28 ] ) ;
else
F_3 ( V_2 , V_181 [ V_180 ] [ V_28 ] ,
V_190 ,
V_21 -> V_181 [ V_180 ] [ V_28 ] ) ;
}
}
F_3 ( V_2 , V_192 ,
V_193 , 0x1 ) ;
F_3 ( V_2 , V_55 ,
V_194 , 0x1 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_216 , bool V_217 )
{
int V_213 [ 8 ] = { 0 } , V_218 = 0 , V_219 ;
int V_220 , V_28 ;
F_3 ( V_2 , F_45 ( V_216 ) ,
V_221 , 0x1 ) ;
F_3 ( V_2 , F_45 ( V_216 ) ,
V_222 , 0x0 ) ;
if ( V_217 )
F_3 ( V_2 , F_45 ( V_216 ) ,
V_223 , 0x0 ) ;
else
F_3 ( V_2 , F_45 ( V_216 ) ,
V_224 , 0x0 ) ;
F_3 ( V_2 , F_46 ( V_216 ) ,
V_225 , 0x1 ) ;
F_3 ( V_2 , F_46 ( V_216 ) ,
V_226 , 0x0 ) ;
F_3 ( V_2 , F_47 ( V_216 ) ,
V_227 , 0x1 ) ;
F_3 ( V_2 , F_47 ( V_216 ) ,
V_228 , 0x1 ) ;
F_3 ( V_2 , F_47 ( V_216 ) ,
V_229 , 0x1 ) ;
if ( F_48 ( V_2 ) ) {
F_3 ( V_2 , F_47 ( V_216 ) ,
V_230 , 0x0 ) ;
} else {
if ( V_217 )
F_3 ( V_2 , F_47 ( V_216 ) ,
V_231 , 0x0 ) ;
else
F_3 ( V_2 , F_47 ( V_216 ) ,
V_232 , 0x0 ) ;
}
for ( V_28 = 6 ; V_28 > 0 ; V_28 -- ) {
V_213 [ V_28 ] = F_16 ( V_28 - 1 ) ;
V_219 = V_218 + V_213 [ V_28 ] ;
if ( V_217 )
F_3 ( V_2 , F_47 ( V_216 ) ,
V_230 ,
V_219 ) ;
else
F_3 ( V_2 , F_47 ( V_216 ) ,
V_233 ,
V_219 ) ;
F_49 ( 100 ) ;
V_220 = F_38 ( V_2 , F_47 ( V_216 ) ,
V_234 ) ;
V_213 [ V_28 ] = ( V_220 ) ? 0 : 1 ;
V_218 += ( V_213 [ V_28 ] << ( V_28 - 1 ) ) ;
}
if ( V_217 )
F_3 ( V_2 , F_47 ( V_216 ) ,
V_230 , V_218 ) ;
else
F_3 ( V_2 , F_47 ( V_216 ) ,
V_233 , V_218 ) ;
F_3 ( V_2 , F_45 ( V_216 ) ,
V_221 , 0 ) ;
F_3 ( V_2 , F_46 ( V_216 ) ,
V_225 , 0 ) ;
F_3 ( V_2 , F_47 ( V_216 ) ,
V_229 , 0 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_17 * V_34 ,
bool V_235 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
int V_28 ;
if ( ! F_51 ( V_2 ) && ! F_21 ( V_2 ) && ! F_35 ( V_2 ) )
return;
if ( ( V_2 -> V_236 . V_237 & V_238 ) && ! V_235 )
return;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( ! ( V_2 -> V_19 & ( 1 << V_28 ) ) )
continue;
F_44 ( V_2 , V_28 , F_52 ( V_34 ) ) ;
}
if ( V_21 )
F_39 ( V_239 , & V_21 -> V_196 ) ;
if ( ( V_2 -> V_236 . V_237 & V_238 ) && V_21 ) {
if ( F_52 ( V_34 ) ) {
V_21 -> V_240 [ 0 ] = F_38 ( V_2 ,
F_47 ( 0 ) ,
V_230 ) ;
V_21 -> V_240 [ 1 ] = F_38 ( V_2 ,
F_47 ( 1 ) ,
V_230 ) ;
} else {
V_21 -> V_240 [ 0 ] = F_38 ( V_2 ,
F_47 ( 0 ) ,
V_233 ) ;
V_21 -> V_240 [ 1 ] = F_38 ( V_2 ,
F_47 ( 1 ) ,
V_233 ) ;
}
}
}
static void F_53 ( struct V_1 * V_2 , bool V_179 )
{
T_2 V_241 [ V_30 ] = { V_242 ,
V_243 ,
V_244 } ;
struct V_20 * V_21 = V_2 -> V_21 ;
bool V_245 = false ;
int V_28 , V_209 ;
if ( ! V_21 || ! ( V_2 -> V_63 & V_246 ) )
return;
V_245 = ! ! ( F_9 ( V_2 , V_95 ) &
V_247 ) ;
if ( F_54 ( V_248 , & V_21 -> V_196 ) ) {
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( ! ( V_2 -> V_41 & ( 1 << V_28 ) ) )
continue;
for ( V_209 = 0 ; V_209 < V_249 ; V_209 ++ )
F_4 ( V_2 , F_55 ( V_241 [ V_28 ] ) ,
V_21 -> V_250 [ V_28 ] [ V_209 ] ) ;
}
} else if ( V_179 && V_245 ) {
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( ! ( V_2 -> V_41 & ( 1 << V_28 ) ) )
continue;
for ( V_209 = 0 ; V_209 < V_249 ; V_209 ++ )
V_21 -> V_250 [ V_28 ] [ V_209 ] =
F_9 ( V_2 , F_55 ( V_241 [ V_28 ] ) ) ;
}
F_39 ( V_248 , & V_21 -> V_196 ) ;
}
}
static bool F_56 ( struct V_1 * V_2 ,
struct V_17 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_21 ;
bool V_67 = false ;
bool V_179 = true , V_92 = true ;
bool V_235 = false , V_251 ;
bool V_252 = ! ! ( V_2 -> V_236 . V_237 & V_238 ) ;
T_2 V_253 = 0 ;
T_2 V_254 = 0 , V_255 = V_96 |
V_103 |
V_104 ;
F_57 ( V_2 , V_2 -> V_236 . V_256 , V_2 -> V_236 . V_257 ) ;
if ( V_252 ) {
if ( ! F_58 ( V_2 , V_34 ) )
V_235 = true ;
if ( V_235 )
F_5 ( V_6 , V_15 , L_40 ) ;
}
V_251 = V_235 ;
if ( V_235 ) {
F_59 ( V_2 ) ;
F_60 ( V_2 , 0x00 ) ;
F_61 ( V_2 ) ;
}
if ( V_252 ) {
if ( ! V_235 ) {
V_254 = F_9 ( V_2 , V_95 ) ;
V_255 &= V_254 ;
V_254 &= ~ ( V_96 |
V_103 |
V_104 ) ;
F_4 ( V_2 , V_95 , V_254 ) ;
} else {
if ( V_2 -> V_258 & V_259 )
V_251 = true ;
}
}
if ( V_2 -> V_63 & V_246 ) {
if ( V_21 && F_54 ( V_248 , & V_21 -> V_196 ) )
F_27 ( V_2 , V_101 ,
V_102 ) ;
else {
F_6 ( V_2 , V_101 ,
V_102 ) ;
V_251 = true ;
}
}
if ( ( F_62 ( V_34 ) || F_63 ( V_34 ) ) ||
! ( V_2 -> V_63 & V_64 ) )
goto V_260;
F_3 ( V_2 , V_261 ,
V_262 ,
V_167 ) ;
if ( V_2 -> V_63 & V_65 ) {
if ( V_21 && ! F_54 ( V_195 , & V_21 -> V_196 ) )
F_6 ( V_2 , V_97 ,
V_98 ) ;
else
F_27 ( V_2 , V_97 ,
V_98 ) ;
V_67 = V_251 = true ;
}
V_260:
if ( F_64 ( V_2 ) && F_52 ( V_34 ) && V_251 )
F_65 ( V_2 , & V_179 ) ;
if ( F_9 ( V_2 , V_101 ) & V_102 ) {
V_253 = F_9 ( V_2 , V_263 ) ;
F_4 ( V_2 , V_108 , V_264 ) ;
F_49 ( 5 ) ;
F_4 ( V_2 , V_263 , V_265 ) ;
F_4 ( V_2 , V_108 , V_109 ) ;
}
if ( V_251 || ! ( V_2 -> V_258 & V_259 ) ) {
F_4 ( V_2 , V_95 ,
F_9 ( V_2 , V_95 ) |
V_99 ) ;
V_92 = F_28 ( V_2 , V_95 ,
V_99 ,
0 , V_100 ) ;
F_50 ( V_2 , V_34 , V_235 ) ;
}
if ( F_9 ( V_2 , V_101 ) & V_102 ) {
F_4 ( V_2 , V_263 , V_253 ) ;
F_49 ( 5 ) ;
}
if ( F_64 ( V_2 ) && F_52 ( V_34 ) && V_251 )
F_66 ( V_2 ) ;
if ( V_252 && ! V_235 ) {
V_254 |= V_255 ;
F_4 ( V_2 , V_95 , V_254 ) ;
}
if ( ! V_92 ) {
if ( V_235 )
F_67 ( V_2 ) ;
F_5 ( V_6 , V_15 ,
L_41 ,
V_100 / 1000 ) ;
return false ;
}
if ( V_67 )
F_42 ( V_2 , V_179 ) ;
else if ( V_21 && F_54 ( V_195 , & V_21 -> V_196 ) )
F_43 ( V_2 ) ;
F_53 ( V_2 , V_179 ) ;
if ( V_235 && V_21 ) {
if ( V_179 ) {
if ( ! F_68 ( V_2 ) ) {
F_7 ( F_2 ( V_2 ) ,
L_42 ) ;
} else {
F_69 ( V_2 ) ;
if ( F_54 ( V_239 , & V_21 -> V_196 ) )
F_70 ( V_2 ) ;
}
F_71 ( V_2 ) ;
}
F_67 ( V_2 ) ;
}
F_57 ( V_2 , V_2 -> V_19 , V_2 -> V_41 ) ;
V_2 -> V_266 = V_2 -> V_267 = V_2 -> V_36 = NULL ;
F_72 ( & V_2 -> V_61 ) ;
F_73 ( V_2 , & V_2 -> V_61 ) ;
F_5 ( V_6 , V_15 , L_43 ) ;
V_2 -> V_36 = V_2 -> V_266 ;
if ( V_2 -> V_36 )
F_10 ( V_2 , V_2 -> V_36 ) ;
if ( V_21 )
V_21 -> V_32 = 0 ;
return true ;
}
static bool F_74 ( struct V_1 * V_2 ,
struct V_17 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_21 ;
bool V_67 = false ;
bool V_179 = true , V_92 = true ;
bool V_251 = false , V_268 = false ;
F_57 ( V_2 , V_2 -> V_236 . V_256 , V_2 -> V_236 . V_257 ) ;
if ( V_2 -> V_63 & V_246 ) {
F_6 ( V_2 , V_101 , V_102 ) ;
V_251 = true ;
}
if ( F_62 ( V_34 ) || F_63 ( V_34 ) )
goto V_260;
F_3 ( V_2 , V_261 ,
V_262 ,
V_167 ) ;
if ( V_2 -> V_63 & V_65 ) {
V_67 = true ;
V_251 = true ;
} else {
V_268 = true ;
V_251 = true ;
}
if ( V_268 ) {
V_67 = F_41 ( V_2 ) ;
F_4 ( V_2 , V_108 , V_264 ) ;
F_49 ( 5 ) ;
F_4 ( V_2 , V_108 , V_109 ) ;
}
if ( F_75 ( V_2 ) && F_52 ( V_34 ) ) {
if ( ! F_26 ( V_2 , V_67 ) )
return false ;
}
V_260:
if ( V_251 || ! ( V_2 -> V_258 & V_259 ) ) {
if ( F_48 ( V_2 ) )
F_44 ( V_2 , 0 , F_52 ( V_34 ) ) ;
F_4 ( V_2 , V_95 ,
F_9 ( V_2 , V_95 ) |
V_99 ) ;
V_92 = F_28 ( V_2 , V_95 ,
V_99 ,
0 , V_100 ) ;
}
if ( ! V_92 ) {
F_5 ( V_6 , V_15 ,
L_41 ,
V_100 / 1000 ) ;
return false ;
}
if ( V_67 )
F_42 ( V_2 , V_179 ) ;
F_57 ( V_2 , V_2 -> V_19 , V_2 -> V_41 ) ;
V_2 -> V_266 = V_2 -> V_267 = V_2 -> V_36 = NULL ;
F_72 ( & V_2 -> V_61 ) ;
F_73 ( V_2 , & V_2 -> V_61 ) ;
F_5 ( V_6 , V_15 , L_43 ) ;
V_2 -> V_36 = V_2 -> V_266 ;
if ( V_2 -> V_36 )
F_10 ( V_2 , V_2 -> V_36 ) ;
if ( V_21 )
V_21 -> V_32 = 0 ;
return true ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_269 * V_270 = F_77 ( V_2 ) ;
struct V_271 * V_272 = F_78 ( V_2 ) ;
if ( F_35 ( V_2 ) || F_51 ( V_2 ) || F_21 ( V_2 ) )
V_270 -> V_273 = F_56 ;
else
V_270 -> V_273 = F_74 ;
V_270 -> V_274 = F_22 ;
V_270 -> V_275 = F_1 ;
V_272 -> V_276 = F_11 ;
}
