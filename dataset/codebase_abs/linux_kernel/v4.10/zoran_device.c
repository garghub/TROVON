void
F_1 ( struct V_1 * V_2 ,
int V_3 ,
unsigned int V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
V_6 = ( 1 << ( 24 + V_3 ) ) & 0xff000000 ;
V_5 = F_2 ( V_7 ) & ~ V_6 ;
if ( V_4 ) {
V_5 |= V_6 ;
}
F_3 ( V_5 , V_7 ) ;
F_4 ( 1 ) ;
}
int
F_5 ( struct V_1 * V_2 )
{
T_1 V_8 ;
while ( ( V_8 = F_2 ( V_9 ) ) & V_10 ) {
}
if ( ( V_8 & V_11 ) && ! V_2 -> V_12 . V_13 ) {
F_6 ( 1 , V_14 L_1 , F_7 ( V_2 ) ,
V_8 ) ;
return - 1 ;
}
return 0 ;
}
int
F_8 ( struct V_1 * V_2 ,
unsigned int V_15 ,
unsigned int V_5 ,
unsigned int V_4 )
{
T_1 V_8 ;
V_8 =
V_16 | V_11 | ( ( V_15 & 7 ) << 20 ) |
( ( V_5 & 7 ) << 16 ) | ( V_4 & 0xFF ) ;
F_3 ( V_8 , V_9 ) ;
return F_5 ( V_2 ) ;
}
int
F_9 ( struct V_1 * V_2 ,
unsigned int V_15 ,
unsigned int V_5 )
{
T_1 V_8 ;
V_8 = V_11 | ( ( V_15 & 7 ) << 20 ) | ( ( V_5 & 7 ) << 16 ) ;
F_3 ( V_8 , V_9 ) ;
if ( F_5 ( V_2 ) < 0 ) {
return - 1 ;
}
return F_2 ( V_9 ) & 0xFF ;
}
static void
F_10 ( struct V_1 * V_2 )
{
if ( V_17 > 2 ) {
int V_18 , V_15 [ 8 ] ;
for ( V_18 = 1 ; V_18 < 8 ; V_18 ++ ) {
V_15 [ V_18 ] = F_9 ( V_2 , V_18 , 0 ) ;
}
F_11 ( V_14 L_2 ,
F_7 ( V_2 ) , 8 , V_15 ) ;
}
}
void
F_12 ( struct V_1 * V_2 )
{
int V_19 , V_18 , V_20 , V_21 , V_15 [ 8 ] , V_22 [ 8 ] , V_23 [ 8 ] [ 3 ] ;
T_2 V_24 , V_25 ;
F_10 ( V_2 ) ;
F_11 ( V_14 L_3 ,
F_7 ( V_2 ) ) ;
for ( V_18 = 1 ; V_18 < 8 ; V_18 ++ ) {
V_22 [ V_18 ] = V_15 [ V_18 ] = F_9 ( V_2 , V_18 , 0 ) ;
}
V_19 = 0 ;
V_20 = 0 ;
V_24 = F_13 () ;
while ( V_19 < 10000 ) {
F_4 ( 10 ) ;
V_19 ++ ;
for ( V_18 = 1 ; ( V_18 < 8 ) && ( V_20 < 8 ) ; V_18 ++ ) {
V_21 = F_9 ( V_2 , V_18 , 0 ) ;
if ( V_21 != V_15 [ V_18 ] ) {
V_25 = F_13 () ;
V_23 [ V_20 ] [ 0 ] = F_14 ( F_15 ( V_25 , V_24 ) ) ;
V_24 = V_25 ;
V_23 [ V_20 ] [ 1 ] = V_18 ;
V_23 [ V_20 ] [ 2 ] = V_21 ;
V_20 ++ ;
V_15 [ V_18 ] = V_21 ;
}
}
if ( V_20 >= 8 )
break;
}
F_11 ( V_14 L_2 , F_7 ( V_2 ) , 8 , V_22 ) ;
if ( V_20 == 0 ) {
F_11 ( V_14 L_4 , F_7 ( V_2 ) ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
F_11 ( V_14 L_5 , F_7 ( V_2 ) ,
V_23 [ V_18 ] [ 0 ] , V_23 [ V_18 ] [ 1 ] , V_23 [ V_18 ] [ 2 ] ) ;
}
}
void
F_16 ( struct V_1 * V_2 ,
int V_26 )
{
F_1 ( V_2 , V_2 -> V_12 . V_27 [ V_28 ] , ! V_26 ) ;
if ( ! V_26 ) {
F_6 ( 3 ,
V_29
L_6 ,
F_7 ( V_2 ) , F_2 ( V_7 ) ) ;
F_4 ( 500 ) ;
} else {
F_6 ( 3 ,
V_29
L_7 ,
F_7 ( V_2 ) , F_2 ( V_7 ) ) ;
F_4 ( 2 ) ;
}
}
int
F_17 ( struct V_1 * V_2 )
{
F_16 ( V_2 , 0 ) ;
if ( V_2 -> V_12 . V_30 [ V_31 ] != 0xff ) {
F_8 ( V_2 , V_2 -> V_12 . V_30 [ V_31 ] , 0 ,
0 ) ;
F_4 ( 2 ) ;
} else {
F_1 ( V_2 , V_2 -> V_12 . V_27 [ V_32 ] , 0 ) ;
F_4 ( 2 ) ;
F_1 ( V_2 , V_2 -> V_12 . V_27 [ V_32 ] , 1 ) ;
F_4 ( 2 ) ;
}
return 0 ;
}
static void
F_18 ( struct V_1 * V_2 ,
enum V_33 V_34 )
{
T_1 V_5 ;
switch ( V_34 ) {
case V_35 :
F_19 ( ~ V_36 , V_37 ) ;
V_5 = F_2 ( V_38 ) ;
if ( ( V_5 & ( 1 << 10 ) ) && V_2 -> V_12 . type != V_39 ) {
V_5 += ( ( 1 << 10 ) | 1 ) ;
}
F_3 ( V_5 , V_38 ) ;
break;
case V_40 :
case V_41 :
default:
if ( ( V_2 -> V_42 & V_43 ) ||
( V_2 -> V_12 . type == V_39 &&
( V_2 -> V_42 & V_44 ) ) )
F_19 ( ~ V_36 , V_37 ) ;
else
F_20 ( V_36 , V_37 ) ;
V_5 = F_2 ( V_38 ) ;
if ( ! ( V_5 & ( 1 << 10 ) ) && V_2 -> V_12 . type != V_39 ) {
V_5 -= ( ( 1 << 10 ) | 1 ) ;
}
F_3 ( V_5 , V_38 ) ;
break;
}
}
static void
F_21 ( struct V_1 * V_2 ,
int V_45 ,
int V_46 ,
const struct V_47 * V_48 )
{
struct V_49 * V_50 ;
unsigned V_51 , V_52 , V_53 , V_54 ;
unsigned V_55 ;
unsigned V_56 , V_57 ;
unsigned V_58 , V_59 , V_60 , V_61 ;
unsigned V_62 , V_63 , V_64 , V_65 ;
unsigned V_66 , V_67 , V_68 , V_69 ;
T_1 V_5 ;
unsigned V_70 ;
V_50 = V_2 -> V_71 ;
V_62 = V_50 -> V_62 ;
V_64 = V_50 -> V_64 ;
F_6 ( 2 , V_14 L_8 ,
F_7 ( V_2 ) , V_45 , V_46 ) ;
if ( V_45 < V_72 ||
V_46 < V_73 ||
V_45 > V_62 || V_46 > V_64 ) {
F_6 ( 1 , V_74 L_9 ,
F_7 ( V_2 ) , V_45 , V_46 ) ;
return;
}
V_56 = V_45 ;
V_66 = F_22 ( V_56 * 64 , V_50 -> V_62 ) ;
V_63 = ( V_56 * 64 ) / V_66 ;
V_68 = 64 - V_66 ;
V_58 = 2 * ( ( V_50 -> V_62 - V_63 ) / 4 ) ;
V_59 = V_50 -> V_62 - V_63 - V_58 ;
V_51 = V_50 -> V_51 ? V_50 -> V_51 : 1 ;
V_52 = V_51 + V_50 -> V_62 - 1 ;
V_51 += V_58 ;
V_52 -= V_59 ;
V_5 = ( ( V_51 & V_75 ) << V_76 )
| ( ( V_52 & V_75 ) << V_77 ) ;
if ( V_2 -> V_12 . V_78 . V_79 )
V_5 |= V_80 ;
F_3 ( V_5 , V_38 ) ;
V_55 = ! ( V_46 > V_81 / 2 ) ;
V_57 = V_55 ? V_46 : V_46 / 2 ;
V_67 = F_22 ( V_57 * 64 * 2 , V_50 -> V_64 ) ;
V_65 = ( V_57 * 64 ) / V_67 ;
V_69 = 64 - V_67 ;
V_60 = ( V_50 -> V_64 / 2 - V_65 ) / 2 ;
V_61 = V_50 -> V_64 / 2 - V_65 - V_60 ;
V_53 = V_50 -> V_53 ;
V_54 = V_53 + V_50 -> V_64 / 2 ;
V_53 += V_60 ;
V_54 -= V_61 ;
V_5 = ( ( V_53 & V_82 ) << V_83 )
| ( ( V_54 & V_82 ) << V_84 ) ;
if ( V_2 -> V_12 . V_78 . V_85 )
V_5 |= V_86 ;
F_3 ( V_5 , V_87 ) ;
V_5 = 0 ;
V_5 |= ( V_68 << V_88 ) ;
V_5 |= ( V_69 << V_89 ) ;
V_5 |= ( V_55 << V_90 ) ;
if ( ! ( V_2 -> V_42 & V_43 ) )
V_5 |= V_36 ;
V_5 |= V_91 ;
if ( V_68 >= 48 ) {
V_5 |= 3 << V_92 ;
} else if ( V_68 >= 32 ) {
V_5 |= 2 << V_92 ;
} else if ( V_68 >= 16 ) {
V_5 |= 1 << V_92 ;
}
V_5 |= V_48 -> V_93 ;
F_3 ( V_5 , V_37 ) ;
V_5 = ( 16 << V_94 )
| ( V_57 << V_95 )
| ( V_56 << V_96 ) ;
if ( V_97 & V_98 )
V_5 &= ~ V_99 ;
else
V_5 |= V_99 ;
F_3 ( V_5 , V_100 ) ;
if ( V_2 -> V_101 ) {
V_70 = ( V_102 + 31 ) / 32 ;
V_5 = F_23 ( V_2 -> V_101 ) ;
F_3 ( V_5 , V_103 ) ;
V_5 = F_23 ( V_2 -> V_101 + V_70 ) ;
F_3 ( V_5 , V_104 ) ;
V_5 =
V_70 - ( V_2 -> V_105 . V_106 +
31 ) / 32 ;
if ( V_55 == 0 )
V_5 += V_70 ;
V_5 <<= V_107 ;
F_3 ( V_5 , V_108 ) ;
}
F_18 ( V_2 , V_2 -> V_109 ) ;
}
void
F_24 ( struct V_1 * V_2 ,
int V_110 )
{
T_1 V_5 ;
if ( V_110 ) {
F_19 ( ~ V_111 , V_100 ) ;
F_21 ( V_2 ,
V_2 -> V_105 . V_106 ,
V_2 -> V_105 . V_112 ,
V_2 -> V_105 . V_48 ) ;
V_5 = ( long ) V_2 -> V_113 +
V_2 -> V_105 . V_114 *
( ( V_2 -> V_105 . V_48 -> V_115 + 7 ) / 8 ) +
V_2 -> V_105 . V_116 *
V_2 -> V_117 ;
F_3 ( V_5 , V_118 ) ;
if ( V_5 & 3 )
F_6 ( 1 ,
V_74
L_10 ,
F_7 ( V_2 ) ) ;
if ( V_2 -> V_105 . V_112 > V_81 / 2 )
V_5 += V_2 -> V_117 ;
F_3 ( V_5 , V_119 ) ;
V_5 = V_2 -> V_117 -
V_2 -> V_105 . V_106 *
( ( V_2 -> V_105 . V_48 -> V_115 + 7 ) / 8 ) ;
if ( V_2 -> V_105 . V_112 > V_81 / 2 )
V_5 += V_2 -> V_117 ;
if ( V_5 & 3 )
F_6 ( 1 ,
V_74
L_11 ,
F_7 ( V_2 ) ) ;
V_5 = ( V_5 << V_120 ) ;
V_5 |= V_121 ;
F_3 ( V_5 , V_122 ) ;
if ( V_2 -> V_105 . V_123 > 0 )
F_20 ( V_124 , V_108 ) ;
F_20 ( V_111 , V_100 ) ;
} else {
F_19 ( ~ V_111 , V_100 ) ;
}
}
void F_25 ( struct V_125 * V_126 , struct V_127 * V_128 , int V_129 )
{
struct V_1 * V_2 = V_126 -> V_2 ;
unsigned V_70 = ( V_102 + 31 ) / 32 ;
T_1 * V_6 ;
int V_114 , V_116 , V_106 , V_112 ;
unsigned V_18 , V_20 , V_130 ;
memset ( V_126 -> V_101 , ~ 0 , V_70 * 4 * V_81 ) ;
for ( V_18 = 0 ; V_18 < V_129 ; ++ V_18 ) {
V_114 = V_128 [ V_18 ] . V_131 . V_132 ;
V_116 = V_128 [ V_18 ] . V_131 . V_133 ;
V_106 = V_128 [ V_18 ] . V_131 . V_106 ;
V_112 = V_128 [ V_18 ] . V_131 . V_112 ;
if ( V_114 < 0 ) {
V_106 += V_114 ;
V_114 = 0 ;
}
if ( V_116 < 0 ) {
V_112 += V_116 ;
V_116 = 0 ;
}
if ( V_114 + V_106 > V_126 -> V_105 . V_106 ) {
V_106 = V_126 -> V_105 . V_106 - V_114 ;
}
if ( V_116 + V_112 > V_126 -> V_105 . V_112 ) {
V_112 = V_126 -> V_105 . V_112 - V_116 ;
}
if ( V_112 <= 0 ) {
continue;
}
if ( V_106 <= 0 ) {
continue;
}
for ( V_20 = 0 ; V_20 < V_112 ; ++ V_20 ) {
V_6 = V_126 -> V_101 + ( V_116 + V_20 ) * V_70 ;
for ( V_130 = 0 ; V_130 < V_106 ; ++ V_130 ) {
V_6 [ ( V_114 + V_130 ) / 32 ] &=
~ ( ( T_1 ) 1 << ( V_114 + V_130 ) % 32 ) ;
}
}
}
}
void
F_26 ( struct V_1 * V_2 ,
int V_34 )
{
if ( V_34 ) {
if ( F_2 ( V_122 ) & V_134 )
F_6 ( 1 ,
V_135
L_12 ,
F_7 ( V_2 ) ) ;
F_3 ( V_136 , V_137 ) ;
F_20 ( V_2 -> V_12 . V_138 , V_139 ) ;
F_20 ( V_134 , V_122 ) ;
F_21 ( V_2 , V_2 -> V_140 . V_106 ,
V_2 -> V_140 . V_112 ,
V_2 -> V_140 . V_48 ) ;
V_2 -> V_141 = 1 ;
} else {
F_19 ( ~ V_2 -> V_12 . V_138 , V_139 ) ;
V_2 -> V_141 = 0 ;
V_2 -> V_142 = V_143 ;
if ( V_2 -> V_144 ) {
F_24 ( V_2 , 1 ) ;
} else {
F_19 ( ~ V_111 , V_100 ) ;
F_19 ( ~ V_134 , V_122 ) ;
}
}
}
int
F_27 ( struct V_1 * V_2 )
{
unsigned long V_145 ;
if ( ! V_2 -> V_141 )
return 0 ;
F_28 ( V_2 -> V_146 ,
( V_2 -> V_147 == V_2 -> V_148 ) ) ;
if ( F_29 ( V_149 ) )
return - V_150 ;
F_30 ( & V_2 -> V_151 , V_145 ) ;
F_26 ( V_2 , 0 ) ;
F_31 ( & V_2 -> V_151 , V_145 ) ;
return 0 ;
}
static inline void
F_32 ( struct V_1 * V_2 ,
int V_152 )
{
F_1 ( V_2 , V_2 -> V_12 . V_27 [ V_153 ] , V_152 ) ;
}
static void
F_33 ( struct V_1 * V_2 ,
int V_152 )
{
switch ( V_2 -> V_12 . type ) {
case V_154 :
case V_39 :
if ( ! V_155 )
F_1 ( V_2 , 5 , V_152 ) ;
else
F_1 ( V_2 , 5 , 1 ) ;
break;
default:
F_1 ( V_2 , V_2 -> V_12 . V_27 [ V_156 ] ,
V_2 -> V_12 . V_157 [ V_156 ] ? ! V_152 : V_152 ) ;
break;
}
}
static void
F_34 ( struct V_1 * V_2 )
{
int V_18 ;
V_2 -> V_158 = 0 ;
V_2 -> V_159 = 0 ;
V_2 -> V_160 = 0 ;
V_2 -> V_161 = 0 ;
V_2 -> V_162 = 0 ;
V_2 -> V_163 = 0 ;
V_2 -> V_164 = 0 ;
V_2 -> V_165 = 0 ;
V_2 -> V_166 = 0 ;
V_2 -> V_167 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_168 . V_169 ; V_18 ++ ) {
V_2 -> V_168 . V_170 [ V_18 ] . V_171 = V_172 ;
}
for ( V_18 = 0 ; V_18 < V_173 ; V_18 ++ ) {
V_2 -> V_174 [ V_18 ] = F_35 ( 1 ) ;
}
}
static void
F_36 ( struct V_1 * V_2 ,
enum V_33 V_34 )
{
struct V_49 * V_50 ;
T_1 V_5 ;
V_50 = V_2 -> V_71 ;
F_3 ( 0 , V_175 ) ;
switch ( V_34 ) {
case V_40 :
default:
V_5 = V_176 ;
break;
case V_35 :
V_5 = V_177 ;
V_5 |= V_178 ;
break;
case V_179 :
V_5 = V_180 ;
break;
case V_181 :
V_5 = V_182 ;
break;
}
V_5 |= V_183 ;
if ( V_2 -> V_184 . V_185 == 1 )
V_5 |= V_186 ;
F_3 ( V_5 , V_187 ) ;
F_20 ( V_86 , V_87 ) ;
V_5 = ( 6 << V_188 ) |
( V_50 -> V_189 << V_190 ) ;
F_3 ( V_5 , V_191 ) ;
V_5 = ( ( V_2 -> V_184 . V_192 + V_50 -> V_53 ) << V_193 ) |
( V_2 -> V_184 . V_194 << V_195 ) ;
F_3 ( V_5 , V_196 ) ;
if ( V_2 -> V_12 . V_78 . V_79 )
F_20 ( V_80 , V_38 ) ;
else
F_19 ( ~ V_80 , V_38 ) ;
V_5 = ( ( V_50 -> V_197 ) << V_198 ) |
( V_50 -> V_199 << V_200 ) ;
F_3 ( V_5 , V_201 ) ;
V_5 = ( ( V_2 -> V_184 . V_202 +
V_50 -> V_51 + 4 ) << V_203 ) |
( V_2 -> V_184 . V_204 << V_205 ) ;
F_3 ( V_5 , V_206 ) ;
if ( V_2 -> V_184 . V_207 )
V_5 = V_208 ;
else
V_5 = 0 ;
F_3 ( V_5 , V_209 ) ;
V_5 = F_23 ( V_2 -> V_174 ) ;
F_3 ( V_5 , V_210 ) ;
switch ( V_34 ) {
case V_179 :
case V_40 :
if ( V_2 -> V_12 . type != V_211 )
V_5 = 140 ;
else
V_5 = 60 ;
break;
case V_181 :
case V_35 :
V_5 = 20 ;
break;
default:
V_5 = 80 ;
break;
}
F_3 ( V_5 , V_212 ) ;
F_18 ( V_2 , V_34 ) ;
}
void
F_37 ( struct V_1 * V_2 )
{
int V_21 , V_213 = 0 ;
F_11 ( V_14 L_13 , F_7 ( V_2 ) ) ;
if ( ( V_21 = V_2 -> V_214 ) < - 1 || V_21 > 1 ) {
F_11 ( V_215 L_14 , V_21 ) ;
}
if ( ( V_21 = V_2 -> V_216 ) != 0 ) {
F_11 ( V_215 L_15 , V_21 ) ;
V_213 ++ ;
}
if ( ( V_21 = V_2 -> V_217 ) != 0 ) {
F_11 ( V_215 L_16 , V_21 ) ;
V_213 ++ ;
}
if ( ( V_21 = V_2 -> V_218 ) != 0 ) {
F_11 ( V_215 L_17 , V_21 ) ;
V_213 ++ ;
}
if ( ( V_21 = V_2 -> V_219 ) != 0 ) {
F_11 ( V_215 L_18 , V_21 ) ;
V_213 ++ ;
}
if ( V_2 -> V_220 ) {
F_11 ( V_215 L_19 , V_2 -> V_220 ,
V_2 -> V_221 ) ;
}
if ( V_2 -> V_222 ) {
F_11 ( V_215 L_20 , V_2 -> V_222 ) ;
}
F_11 ( V_215 L_21 , V_2 -> V_161 ,
V_2 -> V_160 , V_2 -> V_159 , V_2 -> V_158 ) ;
if ( ! V_213 ) {
F_11 ( V_215 L_22 ) ;
}
F_11 ( V_215 L_23 ) ;
}
void
F_38 ( struct V_1 * V_2 )
{
V_2 -> V_216 = 0 ;
V_2 -> V_217 = 0 ;
V_2 -> V_218 = 0 ;
V_2 -> V_219 = 0 ;
V_2 -> V_214 = 0 ;
V_2 -> V_223 = 0 ;
V_2 -> V_224 = 0 ;
V_2 -> V_225 = 0 ;
V_2 -> V_226 = 0 ;
V_2 -> V_227 = 0 ;
V_2 -> V_228 = 0 ;
V_2 -> V_222 = 0 ;
V_2 -> V_229 = 0 ;
V_2 -> V_220 = 0 ;
V_2 -> V_221 = 0x7fffffff ;
}
static T_1
F_39 ( struct V_1 * V_2 )
{
T_1 V_230 ;
if ( ( V_230 = F_2 ( V_137 ) & 0x78000000 ) ) {
if ( V_230 & V_231 ) {
F_3 ( V_231 , V_137 ) ;
V_2 -> V_216 ++ ;
}
if ( V_230 & V_232 ) {
F_3 ( V_232 , V_137 ) ;
V_2 -> V_217 ++ ;
}
if ( V_230 & V_233 ) {
F_3 ( V_233 , V_137 ) ;
V_2 -> V_218 ++ ;
}
if ( V_230 & V_234 ) {
F_3 ( V_234 , V_137 ) ;
V_2 -> V_219 ++ ;
}
}
return V_230 ;
}
void
F_40 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_235 = 0 ;
F_3 ( V_236 , V_175 ) ;
F_19 ( ~ V_237 , V_238 ) ;
F_20 ( V_239 , V_175 ) ;
F_3 ( V_136 , V_137 ) ;
F_3 ( V_2 -> V_12 . V_240 |
V_241 |
V_242 ,
V_139 ) ;
F_32 ( V_2 , 0 ) ;
V_5 = ( V_2 -> V_12 . V_30 [ 1 ] << V_243 ) |
( 0 << V_244 ) ;
F_3 ( V_5 , V_245 ) ;
if ( V_2 -> V_12 . V_246 == V_247 &&
V_2 -> V_12 . V_248 == V_249 ) {
if ( V_2 -> V_250 )
F_41 ( V_2 -> V_250 , 0 , 1 ) ;
F_8 ( V_2 , 0 , 0 , 0 ) ;
}
F_20 ( V_251 , V_175 ) ;
F_20 ( V_252 , V_187 ) ;
F_4 ( 30 ) ;
F_32 ( V_2 , 1 ) ;
F_6 ( 3 , V_29 L_24 , F_7 ( V_2 ) ) ;
}
void
F_42 ( struct V_1 * V_2 ,
enum V_33 V_34 )
{
struct V_253 V_254 ;
int V_255 =
V_2 -> V_168 . V_256 / V_2 -> V_184 . V_185 ;
V_2 -> V_109 = V_34 ;
V_254 . V_114 = V_2 -> V_184 . V_202 ;
V_254 . V_116 = V_2 -> V_184 . V_192 ;
V_254 . V_106 = V_2 -> V_184 . V_204 ;
V_254 . V_112 = V_2 -> V_184 . V_194 ;
V_254 . V_257 =
V_2 -> V_184 . V_68 | ( V_2 -> V_184 . V_69 << 8 ) ;
V_254 . V_258 = V_2 -> V_184 . V_259 . V_258 ;
switch ( V_34 ) {
case V_40 : {
struct V_260 V_261 ;
struct V_262 V_263 ;
F_33 ( V_2 , 0 ) ;
F_43 ( V_2 , V_264 , V_265 , 1 ) ;
F_44 ( V_2 , V_264 , V_266 , 0 , 0 , 0 ) ;
F_16 ( V_2 , 0 ) ;
V_261 . V_267 = V_2 -> V_184 . V_259 . V_268 ;
V_261 . V_269 = V_2 -> V_184 . V_259 . V_270 ;
memcpy ( V_261 . V_271 , V_2 -> V_184 . V_259 . V_272 , 60 ) ;
V_2 -> V_273 -> V_274 ( V_2 -> V_273 , V_275 ,
sizeof( struct V_260 ) , & V_261 ) ;
V_263 . V_269 = V_2 -> V_184 . V_259 . V_276 ;
memcpy ( V_263 . V_271 , V_2 -> V_184 . V_259 . V_277 , 60 ) ;
V_2 -> V_273 -> V_274 ( V_2 -> V_273 , V_278 ,
sizeof( struct V_262 ) , & V_263 ) ;
V_2 -> V_273 -> V_274 ( V_2 -> V_273 , V_279 ,
sizeof( int ) , & V_255 ) ;
V_2 -> V_273 -> V_280 ( V_2 -> V_273 , V_2 -> V_71 , & V_254 ,
& V_2 -> V_12 . V_78 ) ;
V_2 -> V_273 -> V_281 ( V_2 -> V_273 , V_282 ) ;
if ( V_2 -> V_250 ) {
V_2 -> V_250 -> V_274 ( V_2 -> V_250 , V_279 ,
sizeof( int ) , & V_255 ) ;
V_2 -> V_250 -> V_280 ( V_2 -> V_250 , V_2 -> V_71 , & V_254 ,
& V_2 -> V_12 . V_78 ) ;
V_2 -> V_250 -> V_281 ( V_2 -> V_250 , V_282 ) ;
}
F_34 ( V_2 ) ;
F_36 ( V_2 , V_34 ) ;
F_38 ( V_2 ) ;
F_6 ( 2 , V_14 L_25 ,
F_7 ( V_2 ) ) ;
break;
}
case V_35 :
F_43 ( V_2 , V_264 , V_265 , 0 ) ;
F_33 ( V_2 , 1 ) ;
F_44 ( V_2 , V_264 , V_266 , 1 , 0 , 0 ) ;
F_16 ( V_2 , 0 ) ;
if ( V_2 -> V_250 ) {
V_2 -> V_250 -> V_280 ( V_2 -> V_250 , V_2 -> V_71 , & V_254 ,
& V_2 -> V_12 . V_78 ) ;
V_2 -> V_250 -> V_281 ( V_2 -> V_250 , V_283 ) ;
}
V_2 -> V_273 -> V_280 ( V_2 -> V_273 , V_2 -> V_71 , & V_254 ,
& V_2 -> V_12 . V_78 ) ;
V_2 -> V_273 -> V_281 ( V_2 -> V_273 , V_283 ) ;
F_34 ( V_2 ) ;
F_36 ( V_2 , V_34 ) ;
F_38 ( V_2 ) ;
F_6 ( 2 , V_14 L_26 ,
F_7 ( V_2 ) ) ;
break;
case V_41 :
default:
F_19 ( ~ ( V_2 -> V_12 . V_240 | V_241 ) ,
V_139 ) ;
F_3 ( V_2 -> V_12 . V_240 | V_241 ,
V_137 ) ;
F_19 ( ~ V_252 , V_187 ) ;
F_45 ( 50 ) ;
F_33 ( V_2 , 0 ) ;
F_32 ( V_2 , 1 ) ;
F_20 ( V_237 , V_238 ) ;
F_3 ( 0 , V_175 ) ;
F_19 ( ~ V_284 , V_187 ) ;
F_19 ( ~ V_178 , V_187 ) ;
F_17 ( V_2 ) ;
F_16 ( V_2 , 1 ) ;
F_18 ( V_2 , V_34 ) ;
F_43 ( V_2 , V_264 , V_265 , 1 ) ;
F_44 ( V_2 , V_264 , V_266 , 0 , 0 , 0 ) ;
F_6 ( 2 , V_14 L_27 , F_7 ( V_2 ) ) ;
break;
}
}
void
F_46 ( struct V_1 * V_2 )
{
int V_285 , V_18 , V_286 ;
V_286 =
( V_2 -> V_184 . V_287 ==
1 ) ? V_173 : ( V_173 >> 1 ) ;
while ( ( V_2 -> V_159 - V_2 -> V_160 ) < V_286 &&
V_2 -> V_159 < V_2 -> V_158 ) {
V_285 = V_2 -> V_288 [ V_2 -> V_159 & V_289 ] ;
if ( V_2 -> V_184 . V_287 == 1 ) {
V_18 = ( V_2 -> V_159 -
V_2 -> V_166 ) & V_290 ;
if ( ! ( V_2 -> V_174 [ V_18 ] & F_35 ( 1 ) ) )
break;
V_2 -> V_174 [ V_18 ] =
F_35 ( V_2 -> V_168 . V_170 [ V_285 ] . V_291 . V_292 ) ;
} else {
V_18 = ( ( V_2 -> V_159 -
V_2 -> V_166 ) & 1 ) * 2 ;
if ( ! ( V_2 -> V_174 [ V_18 ] & F_35 ( 1 ) ) )
break;
V_2 -> V_174 [ V_18 ] =
F_35 ( V_2 -> V_168 . V_170 [ V_285 ] . V_291 . V_292 ) ;
V_2 -> V_174 [ V_18 + 1 ] =
F_35 ( V_2 -> V_168 . V_170 [ V_285 ] . V_291 . V_292 ) ;
}
V_2 -> V_168 . V_170 [ V_285 ] . V_171 = V_293 ;
V_2 -> V_159 ++ ;
}
if ( V_2 -> V_109 == V_35 )
V_2 -> V_167 ++ ;
}
static void
F_47 ( struct V_1 * V_2 )
{
int V_18 ;
T_1 V_174 ;
unsigned int V_294 ;
unsigned int V_295 ;
struct V_296 * V_170 ;
int V_285 ;
if ( V_2 -> V_109 == V_35 ) {
V_2 -> V_162 ++ ;
}
while ( V_2 -> V_160 < V_2 -> V_159 ) {
if ( V_2 -> V_184 . V_287 == 1 )
V_18 = ( V_2 -> V_160 -
V_2 -> V_166 ) & V_290 ;
else
V_18 = ( ( V_2 -> V_160 -
V_2 -> V_166 ) & 1 ) * 2 + 1 ;
V_174 = F_48 ( V_2 -> V_174 [ V_18 ] ) ;
if ( ( V_174 & 1 ) == 0 ) {
return;
}
V_285 = V_2 -> V_288 [ V_2 -> V_160 & V_289 ] ;
V_170 = & V_2 -> V_168 . V_170 [ V_285 ] ;
F_49 ( & V_170 -> V_297 . V_298 ) ;
if ( V_2 -> V_109 == V_40 ) {
V_170 -> V_297 . V_299 = ( V_174 & 0x7fffff ) >> 1 ;
V_294 = ( ( V_174 >> 24 ) + V_2 -> V_165 ) & 0xff ;
V_295 = ( V_294 - V_2 -> V_162 ) & 0xff ;
V_2 -> V_162 += V_295 ;
} else {
V_170 -> V_297 . V_299 = 0 ;
}
V_170 -> V_297 . V_294 =
V_2 -> V_184 . V_287 ==
2 ? ( V_2 -> V_162 >> 1 ) : V_2 -> V_162 ;
V_170 -> V_171 = V_300 ;
V_2 -> V_160 ++ ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned int V_301 = 0 ;
int V_34 ;
if ( V_2 -> V_109 == V_40 ) {
F_43 ( V_2 , V_264 , V_302 , & V_301 ) ;
V_34 = V_282 ;
} else {
V_301 = V_303 ;
V_34 = V_283 ;
}
if ( V_2 -> V_109 == V_35 ||
! ( V_301 & V_303 ) ) {
F_17 ( V_2 ) ;
V_2 -> V_273 -> V_281 ( V_2 -> V_273 , V_34 ) ;
F_36 ( V_2 , V_2 -> V_109 ) ;
F_40 ( V_2 ) ;
if ( V_2 -> V_164 <= 8 )
F_6 ( 2 , V_14 L_28 ,
F_7 ( V_2 ) ) ;
V_2 -> V_229 = 0 ;
V_2 -> V_163 = 2 ;
}
}
static void
F_51 ( struct V_1 * V_2 ,
T_1 V_304 ,
T_1 V_305 )
{
int V_18 ;
if ( V_2 -> V_109 != V_40 &&
V_2 -> V_109 != V_35 ) {
return;
}
if ( ( V_305 & 1 ) == 0 &&
V_2 -> V_109 == V_40 &&
V_2 -> V_160 - V_2 -> V_161 >= V_2 -> V_168 . V_169 ) {
F_47 ( V_2 ) ;
F_46 ( V_2 ) ;
F_52 ( & V_2 -> V_306 ) ;
V_2 -> V_229 = 0 ;
return;
}
if ( V_2 -> V_163 == 1 ) {
F_50 ( V_2 ) ;
return;
}
F_19 ( ~ V_252 , V_187 ) ;
F_4 ( 1 ) ;
V_305 = V_305 | ( F_9 ( V_2 , 7 , 0 ) & 3 ) << 8 ;
F_3 ( 0 , V_175 ) ;
F_20 ( V_237 , V_238 ) ;
F_17 ( V_2 ) ;
F_16 ( V_2 , 1 ) ;
V_2 -> V_163 = 1 ;
V_2 -> V_164 ++ ;
if ( V_17 > 1 && V_2 -> V_164 <= 8 ) {
long V_285 ;
int V_20 ;
V_285 = V_2 -> V_288 [ V_2 -> V_160 & V_289 ] ;
F_11 ( V_74
L_29 ,
F_7 ( V_2 ) , V_305 , V_2 -> V_307 ,
V_2 -> V_161 , V_2 -> V_160 ,
V_2 -> V_159 , V_2 -> V_158 ,
V_2 -> V_162 , V_285 ) ;
F_11 ( V_14 L_30 ) ;
for ( V_20 = 0 ; V_20 < V_173 ; V_20 ++ ) {
for ( V_18 = 0 ; V_18 < V_2 -> V_168 . V_169 ; V_18 ++ ) {
if ( F_48 ( V_2 -> V_174 [ V_20 ] ) == V_2 -> V_168 . V_170 [ V_18 ] . V_291 . V_292 )
F_11 ( V_215 L_31 , V_20 , V_18 ) ;
}
}
F_11 ( V_215 L_23 ) ;
}
if ( V_2 -> V_184 . V_287 == 1 )
V_18 = ( V_2 -> V_160 - V_2 -> V_166 ) & V_290 ;
else
V_18 = ( ( V_2 -> V_160 - V_2 -> V_166 ) & 1 ) * 2 ;
if ( V_2 -> V_109 == V_35 ) {
V_2 -> V_174 [ V_18 ] |= F_35 ( 1 ) ;
if ( V_2 -> V_184 . V_287 != 1 )
V_2 -> V_174 [ V_18 + 1 ] |= F_35 ( 1 ) ;
F_47 ( V_2 ) ;
F_46 ( V_2 ) ;
F_52 ( & V_2 -> V_306 ) ;
if ( V_2 -> V_184 . V_287 == 1 )
V_18 = ( V_2 -> V_160 - V_2 -> V_166 ) & V_290 ;
else
V_18 = ( ( V_2 -> V_160 - V_2 -> V_166 ) & 1 ) * 2 ;
}
if ( V_18 ) {
int V_20 ;
T_3 V_308 [ V_173 ] ;
memcpy ( V_308 , V_2 -> V_174 , sizeof( V_308 ) ) ;
for ( V_20 = 0 ; V_20 < V_173 ; V_20 ++ )
V_2 -> V_174 [ V_20 ] = V_308 [ ( V_18 + V_20 ) & V_290 ] ;
V_2 -> V_166 += V_18 ;
V_2 -> V_166 &= V_290 ;
}
if ( V_2 -> V_109 == V_40 )
V_2 -> V_165 = V_2 -> V_162 ;
F_50 ( V_2 ) ;
}
T_4
F_53 ( int V_309 ,
void * V_310 )
{
T_1 V_305 , V_304 ;
int V_129 ;
struct V_1 * V_2 ;
unsigned long V_145 ;
V_2 = V_310 ;
V_129 = 0 ;
if ( V_2 -> V_311 ) {
F_30 ( & V_2 -> V_151 , V_145 ) ;
while ( ( V_305 = F_39 ( V_2 ) ) ) {
if ( V_129 ++ > 100 ) {
F_19 ( ~ V_242 , V_139 ) ;
F_6 ( 1 ,
V_74
L_32 ,
F_7 ( V_2 ) , V_305 ) ;
F_52 ( & V_2 -> V_312 ) ;
}
}
V_2 -> V_307 = V_305 ;
F_31 ( & V_2 -> V_151 , V_145 ) ;
return V_313 ;
}
F_30 ( & V_2 -> V_151 , V_145 ) ;
while ( 1 ) {
V_305 = F_39 ( V_2 ) ;
V_304 = V_305 & V_136 ;
if ( ! V_304 ) {
break;
}
F_6 ( 4 ,
V_29
L_33 ,
V_304 , F_2 ( V_139 ) ) ;
if ( V_304 & V_2 -> V_12 . V_138 ) {
if ( V_2 -> V_109 == V_35 ||
V_2 -> V_109 == V_40 ) {
V_2 -> V_229 ++ ;
}
if ( V_2 -> V_141 ) {
if ( ( F_2 ( V_122 ) & V_134 ) == 0 )
F_6 ( 1 ,
V_135
L_34 ,
F_7 ( V_2 ) ) ;
if ( V_2 -> V_142 != V_143 ) {
if ( ( F_2 ( V_122 ) & V_314 ) == 0 ) {
V_2 -> V_315 . V_170 [ V_2 -> V_142 ] . V_171 = V_300 ;
V_2 -> V_315 . V_170 [ V_2 -> V_142 ] . V_297 . V_294 = V_2 -> V_316 ;
F_49 ( & V_2 -> V_315 . V_170 [ V_2 -> V_142 ] . V_297 . V_298 ) ;
V_2 -> V_142 = V_143 ;
V_2 -> V_147 ++ ;
}
}
if ( V_2 -> V_142 == V_143 )
F_52 ( & V_2 -> V_146 ) ;
if ( V_2 -> V_142 == V_143 &&
V_2 -> V_147 != V_2 -> V_148 ) {
int V_285 = V_2 -> V_317 [ V_2 -> V_147 & V_318 ] ;
T_1 V_5 ;
V_2 -> V_142 = V_285 ;
V_5 = V_2 -> V_315 . V_170 [ V_285 ] . V_319 . V_320 ;
F_3 ( V_5 , V_118 ) ;
if ( V_2 -> V_140 . V_112 > V_81 / 2 )
V_5 += V_2 -> V_140 . V_321 ;
F_3 ( V_5 , V_119 ) ;
V_5 = 0 ;
if ( V_2 -> V_140 . V_112 > V_81 / 2 )
V_5 += V_2 -> V_140 . V_321 ;
V_5 = ( V_5 << V_120 ) ;
V_5 |= V_121 ;
V_5 |= V_134 ;
V_5 |= V_314 ;
F_3 ( V_5 , V_122 ) ;
F_20 ( V_111 ,
V_100 ) ;
}
}
V_2 -> V_316 ++ ;
}
#if ( V_136 & V_233 )
if ( V_304 & V_233 ) {
V_2 -> V_218 ++ ;
F_54 ( F_11 ( V_29 L_35 ,
F_7 ( V_2 ) ) ) ;
F_19 ( ~ V_322 , V_139 ) ;
}
#endif
#if ( V_136 & V_234 )
if ( ( V_304 & V_234 ) &&
( V_2 -> V_109 == V_35 ||
V_2 -> V_109 == V_40 ) ) {
if ( V_17 > 1 && ( ! V_2 -> V_235 || V_2 -> V_163 ) ) {
char V_323 [ V_173 + 1 ] ;
int V_18 ;
F_11 ( V_14
L_36 ,
F_7 ( V_2 ) , V_305 ,
V_2 -> V_184 . V_207 ,
V_2 -> V_184 . V_185 ,
V_2 -> V_229 ) ;
for ( V_18 = 0 ; V_18 < V_173 ; V_18 ++ )
V_323 [ V_18 ] = F_48 ( V_2 -> V_174 [ V_18 ] ) & 1 ? '1' : '0' ;
V_323 [ V_173 ] = 0 ;
F_11 ( V_14
L_37 ,
F_7 ( V_2 ) , V_323 ,
V_2 -> V_161 ,
V_2 -> V_160 ,
V_2 -> V_159 ,
V_2 -> V_158 ) ;
} else {
if ( V_2 -> V_229 > V_2 -> V_220 )
V_2 -> V_220 = V_2 -> V_229 ;
if ( V_2 -> V_229 < V_2 -> V_221 )
V_2 -> V_221 = V_2 -> V_229 ;
}
if ( V_17 > 2 && V_2 -> V_235 < 6 ) {
int V_18 ;
F_11 ( V_14 L_38 ,
F_7 ( V_2 ) , V_2 -> V_162 ) ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
F_11 ( V_215 L_39 ,
F_48 ( V_2 -> V_174 [ V_18 ] ) ) ;
}
F_11 ( V_215 L_23 ) ;
}
V_2 -> V_235 ++ ;
V_2 -> V_229 = 0 ;
V_2 -> V_163 = 0 ;
F_47 ( V_2 ) ;
F_46 ( V_2 ) ;
F_52 ( & V_2 -> V_306 ) ;
}
#endif
if ( ( V_304 & V_2 -> V_12 . V_240 ) ||
V_2 -> V_229 > 25 ||
V_2 -> V_163 == 1 ||
( ( V_2 -> V_109 == V_35 ) &&
( V_2 -> V_235 && ( V_2 -> V_229 > V_2 -> V_184 . V_185 ) ) ) ) {
F_51 ( V_2 , V_304 , V_305 ) ;
}
V_129 ++ ;
if ( V_129 > 10 ) {
F_6 ( 2 , V_135 L_40 ,
F_7 ( V_2 ) , V_129 ) ;
if ( V_129 > 20 ) {
F_19 ( ~ V_242 , V_139 ) ;
F_6 ( 2 ,
V_74
L_41 ,
F_7 ( V_2 ) ) ;
break;
}
}
V_2 -> V_307 = V_305 ;
}
F_31 ( & V_2 -> V_151 , V_145 ) ;
return V_313 ;
}
void
F_55 ( struct V_1 * V_2 ,
int V_324 )
{
if ( V_324 ) {
F_56 ( V_2 -> V_325 ) ;
} else {
T_5 V_326 ;
F_57 ( V_2 -> V_325 , V_327 , & V_326 ) ;
V_326 &= ~ V_328 ;
F_58 ( V_2 -> V_325 , V_327 , V_326 ) ;
}
}
void
F_59 ( struct V_1 * V_2 )
{
F_55 ( V_2 , 1 ) ;
if ( V_2 -> V_12 . V_329 ) {
V_2 -> V_12 . V_329 ( V_2 ) ;
}
F_43 ( V_2 , V_330 , V_329 , 0 ) ;
F_43 ( V_2 , V_264 , V_331 , V_2 -> V_42 ) ;
F_43 ( V_2 , V_264 , V_266 ,
V_2 -> V_12 . V_332 [ V_2 -> V_332 ] . V_333 , 0 , 0 ) ;
F_44 ( V_2 , V_330 , V_329 , 0 ) ;
F_44 ( V_2 , V_264 , V_334 , V_2 -> V_42 ) ;
F_44 ( V_2 , V_264 , V_266 , 0 , 0 , 0 ) ;
F_16 ( V_2 , 1 ) ;
F_16 ( V_2 , 0 ) ;
F_60 ( V_2 ) ;
F_42 ( V_2 , V_41 ) ;
F_3 ( V_136 , V_137 ) ;
}
void
F_61 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_335 ) ;
F_62 ( 1 ) ;
F_20 ( V_336 , V_335 ) ;
F_62 ( 1 ) ;
F_3 ( 0 , V_175 ) ;
F_3 ( V_336 | 0 , V_335 ) ;
F_3 ( ( 0x81 << 24 ) | 0x8888 , V_7 ) ;
}
static void
F_60 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_2 ( V_37 ) ;
V_5 |= V_337 ;
V_5 &= ~ V_338 ;
V_5 |= V_36 ;
V_5 |= V_91 ;
F_3 ( V_5 , V_37 ) ;
V_5 = F_2 ( V_100 ) ;
if ( V_97 & V_98 )
V_5 &= ~ V_99 ;
else
V_5 |= V_99 ;
F_3 ( V_5 , V_100 ) ;
}
