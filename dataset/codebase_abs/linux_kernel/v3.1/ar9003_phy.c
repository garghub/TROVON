static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 = 0 , V_7 = 0 ;
T_2 V_8 , V_9 = 0 , V_10 = 0 ;
struct V_11 V_12 ;
int V_13 ;
F_2 ( V_2 , V_4 , & V_12 ) ;
V_8 = V_12 . V_14 ;
if ( V_8 < 4800 ) {
if ( F_3 ( V_2 ) ) {
T_2 V_15 ;
T_2 div ;
if ( V_2 -> V_16 )
div = 75 ;
else
div = 120 ;
V_9 = ( V_8 * 4 ) / div ;
V_15 = ( ( ( V_8 * 4 ) % div ) * 0x20000 ) / div ;
V_9 = ( V_9 << 17 ) | V_15 ;
} else if ( F_4 ( V_2 ) ) {
T_2 V_15 ;
V_9 = ( V_8 * 4 ) / 120 ;
V_15 = ( ( ( V_8 * 4 ) % 120 ) * 0x20000 ) / 120 ;
V_9 = ( V_9 << 17 ) | V_15 ;
} else if ( F_5 ( V_2 ) ) {
if ( V_2 -> V_16 ) {
T_2 V_15 ;
V_9 = ( V_8 * 2 ) / 75 ;
V_15 = ( ( ( V_8 * 2 ) % 75 ) * 0x20000 ) / 75 ;
V_9 = ( V_9 << 17 ) | V_15 ;
} else
V_9 = F_6 ( V_8 ) >> 1 ;
} else
V_9 = F_6 ( V_8 ) ;
V_5 = 1 ;
} else {
if ( F_5 ( V_2 ) && V_2 -> V_16 ) {
T_2 V_15 ;
V_9 = ( V_8 * 2 ) / 75 ;
V_15 = ( ( ( V_8 * 2 ) % 75 ) * 0x20000 ) / 75 ;
V_9 = ( V_9 << 17 ) | V_15 ;
} else {
V_9 = F_7 ( V_8 ) ;
V_9 >>= 1 ;
}
V_5 = 0 ;
}
V_6 = 1 ;
V_7 = 0 ;
V_13 = 0 ;
V_10 = ( V_5 << 29 ) ;
F_8 ( V_2 , V_17 , V_10 ) ;
F_9 ( V_2 , V_18 ,
V_19 , 1 ) ;
V_10 = ( V_9 << 2 ) | ( V_6 << 30 ) |
( V_7 << 28 ) | ( V_13 << 31 ) ;
F_8 ( V_2 , V_20 , V_10 ) ;
V_13 = 1 ;
V_10 = ( V_9 << 2 ) | ( V_6 << 30 ) |
( V_7 << 28 ) | ( V_13 << 31 ) ;
F_8 ( V_2 , V_20 , V_10 ) ;
V_2 -> V_21 = V_4 ;
V_2 -> V_22 = - 1 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const T_2 V_23 [ 4 ] = { 2420 , 2440 , 2464 , 2480 } ;
int V_24 , V_25 = 0 , V_26 ;
int V_27 ;
int V_28 , V_29 , V_30 ;
T_3 * V_31 = NULL ;
if ( F_4 ( V_2 ) || F_5 ( V_2 ) || F_3 ( V_2 ) ) {
V_31 = F_11 ( V_2 ,
F_12 ( V_4 ) ) ;
if ( V_31 [ 0 ] == 0 )
return;
V_29 = 5 ;
if ( F_13 ( V_4 ) ) {
V_28 = 19 ;
if ( F_14 ( V_2 , V_32 ,
V_33 ) == 0 )
V_30 = V_4 -> V_34 + 10 ;
else
V_30 = V_4 -> V_34 - 10 ;
} else {
V_28 = 10 ;
V_30 = V_4 -> V_34 ;
}
} else {
V_28 = 10 ;
V_29 = 4 ;
V_30 = V_4 -> V_34 ;
}
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
V_25 = 0 ;
if ( F_4 ( V_2 ) || F_5 ( V_2 ) || F_3 ( V_2 ) )
V_24 = F_15 ( V_31 [ V_27 ] ,
F_12 ( V_4 ) ) - V_30 ;
else
V_24 = V_23 [ V_27 ] - V_30 ;
if ( V_24 < 0 ) {
V_25 = 1 ;
V_24 = - V_24 ;
}
if ( V_24 < V_28 ) {
V_26 = ( int ) ( ( V_24 << 19 ) / 11 ) ;
if ( V_25 == 1 )
V_26 = - V_26 ;
V_26 = V_26 & 0xfffff ;
F_9 ( V_2 , V_35 ,
V_36 , 0x7 ) ;
F_9 ( V_2 , V_37 ,
V_38 , 0x7f ) ;
F_9 ( V_2 , V_37 ,
V_39 ,
0x2 ) ;
F_9 ( V_2 , V_37 ,
V_40 ,
0x1 ) ;
F_9 ( V_2 , V_37 ,
V_41 ,
V_26 ) ;
return;
}
}
F_9 ( V_2 , V_35 ,
V_36 , 0x5 ) ;
F_9 ( V_2 , V_37 ,
V_40 , 0x0 ) ;
F_9 ( V_2 , V_37 ,
V_41 , 0x0 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_42 ,
V_43 , 0 ) ;
F_9 ( V_2 , V_44 ,
V_45 , 0 ) ;
F_9 ( V_2 , V_44 ,
V_46 , 0 ) ;
F_9 ( V_2 , V_47 ,
V_48 , 0 ) ;
F_9 ( V_2 , V_44 ,
V_49 , 0 ) ;
F_9 ( V_2 , V_44 ,
V_50 , 0 ) ;
F_9 ( V_2 , V_42 ,
V_51 , 0 ) ;
F_9 ( V_2 , V_52 ,
V_53 , 0 ) ;
F_9 ( V_2 , V_52 ,
V_54 , 0 ) ;
F_9 ( V_2 , V_52 ,
V_55 , 0 ) ;
F_9 ( V_2 , V_42 ,
V_56 , 0 ) ;
F_9 ( V_2 , V_42 ,
V_57 , 0 ) ;
F_9 ( V_2 , V_58 ,
V_59 , 0 ) ;
F_9 ( V_2 , V_60 ,
V_61 , 0 ) ;
F_9 ( V_2 , V_62 ,
V_63 , 0 ) ;
F_9 ( V_2 , V_58 ,
V_64 , 0 ) ;
F_9 ( V_2 , V_62 ,
V_65 , 0 ) ;
F_9 ( V_2 , V_60 ,
V_66 , 0 ) ;
F_9 ( V_2 , V_52 ,
V_67 , 0 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
int V_68 ,
int V_69 ,
int V_70 ,
int V_71 )
{
int V_72 = 0 ;
F_9 ( V_2 , V_42 ,
V_43 , 0x1 ) ;
F_9 ( V_2 , V_44 ,
V_45 , V_69 ) ;
F_9 ( V_2 , V_44 ,
V_46 , V_70 ) ;
F_9 ( V_2 , V_47 ,
V_48 , V_71 ) ;
F_9 ( V_2 , V_44 ,
V_49 , 0x1 ) ;
F_9 ( V_2 , V_44 ,
V_50 , 0x1 ) ;
F_9 ( V_2 , V_42 ,
V_51 , 0x1 ) ;
F_9 ( V_2 , V_52 ,
V_73 , 34 ) ;
F_9 ( V_2 , V_52 ,
V_53 , 1 ) ;
if ( F_14 ( V_2 , V_74 ,
V_75 ) == 0x1 )
F_9 ( V_2 , V_52 ,
V_54 , 1 ) ;
V_72 = ( V_68 << 4 ) / 5 ;
if ( V_72 < 0 )
V_72 = V_72 - 1 ;
V_72 = V_72 & 0x7f ;
F_9 ( V_2 , V_52 ,
V_55 , 0x1 ) ;
F_9 ( V_2 , V_42 ,
V_56 , 0x1 ) ;
F_9 ( V_2 , V_42 ,
V_57 , 0x1 ) ;
F_9 ( V_2 , V_58 ,
V_59 , V_72 ) ;
F_9 ( V_2 , V_60 ,
V_61 , V_72 ) ;
F_9 ( V_2 , V_62 ,
V_63 , V_72 ) ;
F_9 ( V_2 , V_58 ,
V_64 , 0xc ) ;
F_9 ( V_2 , V_62 ,
V_65 , 0xc ) ;
F_9 ( V_2 , V_60 ,
V_66 , 0xa0 ) ;
F_9 ( V_2 , V_52 ,
V_67 , 0xff ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_68 )
{
int V_69 = 0 ;
int V_71 = 0 ;
int V_70 = 0 ;
if ( F_13 ( V_4 ) ) {
if ( V_68 < 0 ) {
if ( F_14 ( V_2 , V_32 ,
V_33 ) == 0x0 )
V_71 = 1 ;
else
V_71 = 0 ;
V_69 = ( ( V_68 + 10 ) << 9 ) / 11 ;
} else {
if ( F_14 ( V_2 , V_32 ,
V_33 ) == 0x0 )
V_71 = 0 ;
else
V_71 = 1 ;
V_69 = ( ( V_68 - 10 ) << 9 ) / 11 ;
}
V_70 = ( V_68 << 17 ) / 5 ;
} else {
V_71 = 0 ;
V_69 = ( V_68 << 9 ) / 11 ;
V_70 = ( V_68 << 18 ) / 5 ;
}
V_69 = V_69 & 0x3ff ;
V_70 = V_70 & 0xfffff ;
F_17 ( V_2 ,
V_68 ,
V_69 ,
V_70 ,
V_71 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_30 ;
int V_28 = 10 ;
int V_68 = 0 ;
int V_76 ;
T_3 * V_77 ;
unsigned int V_27 ;
struct V_78 * V_79 = & V_2 -> V_80 . V_81 ;
if ( F_20 ( V_4 ) ) {
V_77 = & ( V_79 -> V_82 . V_83 [ 0 ] ) ;
V_76 = 0 ;
}
else {
V_77 = & ( V_79 -> V_84 . V_83 [ 0 ] ) ;
V_76 = 1 ;
}
if ( V_77 [ 0 ] == 0 )
return;
if ( F_13 ( V_4 ) ) {
V_28 = 19 ;
if ( F_14 ( V_2 , V_32 ,
V_33 ) == 0x0 )
V_30 = V_4 -> V_34 - 10 ;
else
V_30 = V_4 -> V_34 + 10 ;
} else {
V_28 = 10 ;
V_30 = V_4 -> V_34 ;
}
F_16 ( V_2 ) ;
for ( V_27 = 0 ; V_27 < V_85 && V_77 [ V_27 ] ; V_27 ++ ) {
V_68 = F_15 ( V_77 [ V_27 ] , V_76 ) - V_30 ;
if ( abs ( V_68 ) < V_28 ) {
F_18 ( V_2 , V_4 , V_68 ) ;
break;
}
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_10 ( V_2 , V_4 ) ;
F_19 ( V_2 , V_4 ) ;
}
static T_2 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_86 ;
V_86 = F_23 ( 0x5 , V_87 ) ;
if ( V_4 && F_24 ( V_4 ) )
V_86 |= F_23 ( 0x1 , V_88 ) ;
else if ( V_4 && F_25 ( V_4 ) )
V_86 |= F_23 ( 0x2 , V_88 ) ;
V_86 |= F_23 ( 0x2c , V_89 ) ;
return V_86 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_90 ;
T_2 V_91 = 0 ;
V_91 =
( F_27 ( V_2 , V_32 ) & V_92 ) ;
V_90 = V_93 | V_94 | V_95 |
V_96 | V_91 ;
if ( F_13 ( V_4 ) ) {
V_90 |= V_97 ;
if ( ( V_4 -> V_98 == V_99 ) ||
( V_4 -> V_98 == V_100 ) )
V_90 |= V_33 ;
}
V_90 |= F_27 ( V_2 , V_32 ) ;
V_90 &= ~ V_101 ;
F_8 ( V_2 , V_32 , V_90 ) ;
F_28 ( V_2 ) ;
F_8 ( V_2 , V_102 , 25 << V_103 ) ;
F_8 ( V_2 , V_104 , 0xF << V_105 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_106 ;
V_106 = F_27 ( V_2 , V_107 ) & V_108 ;
if ( F_30 ( V_4 ) )
V_106 = ( 4 * V_106 ) / 22 ;
else
V_106 /= 10 ;
F_8 ( V_2 , V_109 , V_110 ) ;
F_31 ( V_106 + V_111 ) ;
}
void F_32 ( struct V_1 * V_2 , T_3 V_112 , T_3 V_113 )
{
switch ( V_112 ) {
case 0x5 :
F_33 ( V_2 , V_114 ,
V_115 ) ;
case 0x3 :
case 0x1 :
case 0x2 :
case 0x7 :
F_8 ( V_2 , V_116 , V_112 ) ;
F_8 ( V_2 , V_117 , V_112 ) ;
break;
default:
break;
}
if ( ( V_2 -> V_118 . V_119 & V_120 ) && ( V_113 == 0x7 ) )
F_8 ( V_2 , V_121 , 0x3 ) ;
else
F_8 ( V_2 , V_121 , V_113 ) ;
if ( V_113 == 0x5 ) {
F_33 ( V_2 , V_114 ,
V_115 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
T_2 V_122 ;
F_33 ( V_2 , V_123 , ( V_124 | V_125 ) ) ;
V_122 = F_27 ( V_2 , V_126 ) & ( ~ V_127 ) ;
F_8 ( V_2 , V_126 ,
V_122 | V_128 | V_129 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_130 * V_131 ,
int V_132 )
{
unsigned int V_27 , V_133 = 0 ;
if ( ! V_131 -> V_134 )
return;
if ( V_132 >= V_131 -> V_135 )
V_132 = 1 ;
for ( V_27 = 0 ; V_27 < V_131 -> V_136 ; V_27 ++ ) {
T_2 V_137 = F_36 ( V_131 , V_27 , 0 ) ;
T_2 V_122 = F_36 ( V_131 , V_27 , V_132 ) ;
F_8 ( V_2 , V_137 , V_122 ) ;
F_37 ( V_133 ) ;
}
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_138 * V_139 = F_39 ( V_2 ) ;
unsigned int V_133 = 0 , V_27 ;
struct V_140 * V_34 = V_4 -> V_4 ;
T_2 V_141 ;
switch ( V_4 -> V_98 ) {
case V_142 :
case V_143 :
V_141 = 1 ;
break;
case V_99 :
case V_144 :
V_141 = 2 ;
break;
case V_145 :
case V_146 :
case V_147 :
V_141 = 4 ;
break;
case V_100 :
case V_148 :
V_141 = 3 ;
break;
default:
return - V_149 ;
}
for ( V_27 = 0 ; V_27 < V_150 ; V_27 ++ ) {
F_35 ( V_2 , & V_2 -> V_151 [ V_27 ] , V_141 ) ;
F_35 ( V_2 , & V_2 -> V_152 [ V_27 ] , V_141 ) ;
F_35 ( V_2 , & V_2 -> V_153 [ V_27 ] , V_141 ) ;
F_35 ( V_2 , & V_2 -> V_154 [ V_27 ] , V_141 ) ;
}
F_40 ( & V_2 -> V_155 , 1 , V_133 ) ;
F_40 ( & V_2 -> V_156 , V_141 , V_133 ) ;
if ( F_41 ( V_2 , V_4 ) )
F_40 ( & V_2 -> V_157 ,
V_141 , V_133 ) ;
if ( F_3 ( V_2 ) )
F_40 ( & V_2 -> V_157 , 1 , V_133 ) ;
if ( F_5 ( V_2 ) && ! V_2 -> V_16 )
F_40 ( & V_2 -> V_158 , 1 , V_133 ) ;
F_34 ( V_2 ) ;
F_26 ( V_2 , V_4 ) ;
F_32 ( V_2 , V_2 -> V_159 , V_2 -> V_160 ) ;
V_2 -> V_161 -> V_162 ( V_2 , V_4 ,
F_42 ( V_139 , V_4 ) ,
V_34 -> V_163 * 2 ,
V_34 -> V_164 * 2 ,
F_43 ( ( T_2 ) V_165 ,
( T_2 ) V_139 -> V_166 ) , false ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_167 = 0 ;
if ( V_4 == NULL )
return;
V_167 |= ( F_30 ( V_4 ) || F_45 ( V_4 ) )
? V_75 : V_168 ;
if ( F_41 ( V_2 , V_4 ) )
V_167 |= ( V_75 | V_169 ) ;
F_8 ( V_2 , V_74 , V_167 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_109 , V_170 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_171 , V_172 , V_173 ;
T_2 V_174 = 0x64000000 ;
struct V_11 V_12 ;
if ( F_24 ( V_4 ) )
V_174 = V_174 >> 1 ;
else if ( F_25 ( V_4 ) )
V_174 = V_174 >> 2 ;
F_2 ( V_2 , V_4 , & V_12 ) ;
V_171 = V_174 / V_12 . V_14 ;
F_48 ( V_2 , V_171 , & V_173 ,
& V_172 ) ;
F_9 ( V_2 , V_175 ,
V_176 , V_173 ) ;
F_9 ( V_2 , V_175 ,
V_177 , V_172 ) ;
V_171 = ( 9 * V_171 ) / 10 ;
F_48 ( V_2 , V_171 , & V_173 ,
& V_172 ) ;
F_9 ( V_2 , V_178 ,
V_179 , V_173 ) ;
F_9 ( V_2 , V_178 ,
V_180 , V_172 ) ;
}
static bool F_49 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_181 , V_182 ) ;
return F_50 ( V_2 , V_183 , V_184 ,
V_184 , V_185 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_2 V_106 = F_27 ( V_2 , V_107 ) & V_108 ;
if ( F_30 ( V_2 -> V_21 ) )
V_106 = ( 4 * V_106 ) / 22 ;
else
V_106 /= 10 ;
F_31 ( V_106 + V_111 ) ;
F_8 ( V_2 , V_181 , 0 ) ;
}
static void F_52 ( struct V_1 * V_2 , bool V_186 )
{
T_2 V_187 = F_27 ( V_2 , V_188 ) ;
if ( V_186 )
V_187 |= V_189 ;
else
V_187 &= ~ V_189 ;
F_8 ( V_2 , V_188 , V_187 ) ;
}
static bool F_53 ( struct V_1 * V_2 ,
enum V_190 V_191 , int V_192 )
{
struct V_193 * V_194 = F_54 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_195 * V_196 = & V_4 -> V_197 ;
T_4 V_186 , V_198 ;
switch ( V_191 & V_2 -> V_199 ) {
case V_200 : {
T_2 V_201 = V_192 ? 1 : 0 ;
int V_202 = V_201 ?
V_196 -> V_203 . V_202 : V_204 ;
int V_205 = V_201 ?
V_196 -> V_203 . V_205 : V_206 ;
int V_207 = V_201 ?
V_196 -> V_203 . V_207 : V_208 ;
int V_209 = V_201 ?
V_196 -> V_203 . V_209 : V_210 ;
int V_211 = V_201 ?
V_196 -> V_203 . V_211 : V_212 ;
int V_213 = V_201 ?
V_196 -> V_203 . V_213 : V_214 ;
int V_215 = V_201 ?
V_196 -> V_203 . V_215 : V_216 ;
int V_217 = V_201 ?
V_196 -> V_203 . V_217 : V_218 ;
int V_219 = V_201 ?
V_196 -> V_203 . V_219 : V_220 ;
int V_221 = V_201 ?
V_196 -> V_203 . V_221 : V_222 ;
F_9 ( V_2 , V_223 ,
V_224 ,
V_202 ) ;
F_9 ( V_2 , V_223 ,
V_225 ,
V_205 ) ;
F_9 ( V_2 , V_226 ,
V_227 , V_207 ) ;
F_9 ( V_2 , V_226 ,
V_228 , V_209 ) ;
F_9 ( V_2 , V_226 ,
V_229 , V_211 ) ;
F_9 ( V_2 , V_223 ,
V_230 ,
V_213 ) ;
F_9 ( V_2 , V_47 ,
V_231 , V_215 ) ;
F_9 ( V_2 , V_47 ,
V_232 , V_217 ) ;
F_9 ( V_2 , V_47 ,
V_233 , V_219 ) ;
F_9 ( V_2 , V_47 ,
V_234 , V_221 ) ;
if ( V_201 )
F_33 ( V_2 , V_223 ,
V_235 ) ;
else
F_55 ( V_2 , V_223 ,
V_235 ) ;
if ( ! V_201 != V_196 -> V_236 ) {
F_56 ( V_194 , V_237 ,
L_1 ,
V_4 -> V_34 ,
! V_196 -> V_236 ?
L_2 : L_3 ,
V_201 ? L_2 : L_3 ) ;
if ( V_201 )
V_2 -> V_238 . V_239 ++ ;
else
V_2 -> V_238 . V_240 ++ ;
V_196 -> V_236 = ! V_201 ;
}
break;
}
case V_241 : {
T_2 V_242 = V_192 ;
if ( V_242 >= F_57 ( V_243 ) ) {
F_56 ( V_194 , V_237 ,
L_4 ,
V_242 , F_57 ( V_243 ) ) ;
return false ;
}
V_186 = V_243 [ V_242 ] -
V_243 [ V_244 ] +
V_196 -> V_203 . V_245 ;
if ( V_186 < V_246 )
V_186 = V_246 ;
if ( V_186 > V_247 )
V_186 = V_247 ;
F_9 ( V_2 , V_248 ,
V_249 ,
V_186 ) ;
V_198 = V_243 [ V_242 ] -
V_243 [ V_244 ] +
V_196 -> V_203 . V_250 ;
if ( V_198 < V_246 )
V_198 = V_246 ;
if ( V_198 > V_247 )
V_198 = V_247 ;
F_9 ( V_2 , V_251 ,
V_252 , V_198 ) ;
if ( V_242 != V_196 -> V_253 ) {
F_56 ( V_194 , V_237 ,
L_5 ,
V_4 -> V_34 ,
V_196 -> V_253 ,
V_242 ,
V_244 ,
V_186 ,
V_196 -> V_203 . V_245 ) ;
F_56 ( V_194 , V_237 ,
L_6 ,
V_4 -> V_34 ,
V_196 -> V_253 ,
V_242 ,
V_244 ,
V_198 ,
V_196 -> V_203 . V_250 ) ;
if ( V_242 > V_196 -> V_253 )
V_2 -> V_238 . V_254 ++ ;
else if ( V_242 < V_196 -> V_253 )
V_2 -> V_238 . V_255 ++ ;
V_196 -> V_253 = V_242 ;
}
break;
}
case V_256 : {
T_2 V_242 = V_192 ;
if ( V_242 >= F_57 ( V_257 ) ) {
F_56 ( V_194 , V_237 ,
L_7 ,
V_242 , F_57 ( V_257 ) ) ;
return false ;
}
V_186 = V_257 [ V_242 ] -
V_257 [ V_258 ] +
V_196 -> V_203 . V_259 ;
if ( V_186 < V_260 )
V_186 = V_260 ;
if ( V_186 > V_261 )
V_186 = V_261 ;
F_9 ( V_2 , V_262 ,
V_263 ,
V_186 ) ;
V_198 = V_257 [ V_242 ] -
V_257 [ V_258 ] +
V_196 -> V_203 . V_264 ;
if ( V_198 < V_260 )
V_198 = V_260 ;
if ( V_198 > V_261 )
V_198 = V_261 ;
F_9 ( V_2 , V_265 ,
V_266 , V_198 ) ;
if ( V_242 != V_196 -> V_267 ) {
F_56 ( V_194 , V_237 ,
L_8 ,
V_4 -> V_34 ,
V_196 -> V_267 ,
V_242 ,
V_258 ,
V_186 ,
V_196 -> V_203 . V_259 ) ;
F_56 ( V_194 , V_237 ,
L_9 ,
V_4 -> V_34 ,
V_196 -> V_267 ,
V_242 ,
V_258 ,
V_198 ,
V_196 -> V_203 . V_264 ) ;
if ( V_242 > V_196 -> V_267 )
V_2 -> V_238 . V_268 ++ ;
else if ( V_242 < V_196 -> V_267 )
V_2 -> V_238 . V_269 ++ ;
V_196 -> V_267 = V_242 ;
}
break;
}
case V_270 : {
bool V_271 = V_192 ? 1 : 0 ;
F_9 ( V_2 , V_272 ,
V_273 , V_271 ) ;
F_9 ( V_2 , V_272 ,
V_274 , V_271 ) ;
if ( ! V_271 != V_196 -> V_275 ) {
F_56 ( V_194 , V_237 ,
L_10 ,
V_4 -> V_34 ,
! V_196 -> V_275 ? L_2 : L_3 ,
V_271 ? L_2 : L_3 ) ;
if ( V_271 )
V_2 -> V_238 . V_276 ++ ;
else
V_2 -> V_238 . V_277 ++ ;
V_196 -> V_275 = ! V_271 ;
}
break;
}
case V_278 :
break;
default:
F_56 ( V_194 , V_237 , L_11 , V_191 ) ;
return false ;
}
F_56 ( V_194 , V_237 ,
L_12 ,
V_196 -> V_267 ,
! V_196 -> V_236 ? L_2 : L_3 ,
V_196 -> V_253 ,
! V_196 -> V_275 ? L_2 : L_3 ,
V_196 -> V_279 ,
V_196 -> V_280 ,
V_196 -> V_281 ) ;
return true ;
}
static void F_58 ( struct V_1 * V_2 ,
T_5 V_282 [ V_283 ] )
{
#define F_59 0x1FF00000
#define F_60 20
#define F_61 0x01FF0000
#define F_62 16
T_5 V_284 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_285 ; V_27 ++ ) {
if ( V_2 -> V_159 & F_63 ( V_27 ) ) {
V_284 = F_64 ( F_27 ( V_2 , V_2 -> V_286 [ V_27 ] ) ,
F_59 ) ;
V_282 [ V_27 ] = F_65 ( V_284 , 8 ) ;
if ( F_13 ( V_2 -> V_21 ) ) {
T_3 V_287 = V_285 + V_27 ;
V_284 = F_64 ( F_27 ( V_2 , V_2 -> V_286 [ V_287 ] ) ,
F_61 ) ;
V_282 [ V_287 ] = F_65 ( V_284 , 8 ) ;
}
}
}
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_288 . V_289 = V_290 ;
V_2 -> V_288 . F_43 = V_291 ;
if ( F_3 ( V_2 ) )
V_2 -> V_288 . V_292 = V_293 ;
else
V_2 -> V_288 . V_292 = V_294 ;
V_2 -> V_295 . V_289 = V_296 ;
V_2 -> V_295 . F_43 = V_297 ;
V_2 -> V_295 . V_292 = V_298 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_195 * V_196 ;
struct V_193 * V_194 = F_54 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_299 * V_203 ;
T_2 V_122 ;
V_196 = & V_2 -> V_21 -> V_197 ;
V_203 = & V_196 -> V_203 ;
F_56 ( V_194 , V_237 ,
L_13 ,
V_2 -> V_300 . V_301 ,
V_2 -> V_300 . V_302 ,
V_2 -> V_303 ,
V_4 -> V_34 ,
V_4 -> V_304 ) ;
V_122 = F_27 ( V_2 , V_226 ) ;
V_203 -> V_207 = F_64 ( V_122 , V_227 ) ;
V_203 -> V_209 = F_64 ( V_122 , V_228 ) ;
V_203 -> V_211 = F_64 ( V_122 , V_229 ) ;
V_122 = F_27 ( V_2 , V_223 ) ;
V_203 -> V_202 = F_64 ( V_122 , V_224 ) ;
V_203 -> V_205 = F_64 ( V_122 , V_225 ) ;
V_203 -> V_213 = F_64 ( V_122 , V_230 ) ;
V_122 = F_27 ( V_2 , V_47 ) ;
V_203 -> V_219 = F_64 ( V_122 , V_233 ) ;
V_203 -> V_221 = F_64 ( V_122 , V_234 ) ;
V_203 -> V_215 = F_64 ( V_122 , V_231 ) ;
V_203 -> V_217 = F_64 ( V_122 , V_232 ) ;
V_203 -> V_245 = F_14 ( V_2 ,
V_248 ,
V_249 ) ;
V_203 -> V_250 = F_14 ( V_2 ,
V_251 ,
V_252 ) ;
V_203 -> V_259 = F_14 ( V_2 ,
V_262 ,
V_263 ) ;
V_203 -> V_264 = F_14 ( V_2 ,
V_265 ,
V_266 ) ;
V_196 -> V_267 = V_258 ;
V_196 -> V_253 = V_244 ;
V_196 -> V_236 = ! V_305 ;
V_196 -> V_275 = ! V_306 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_307 * V_308 )
{
T_2 V_309 = 0 , V_310 = 0 ;
if ( ! V_308 ) {
F_55 ( V_2 , V_311 , V_312 ) ;
return;
}
V_309 |= V_312 | V_313 ;
V_309 |= F_23 ( V_308 -> V_314 , V_315 ) ;
V_309 |= F_23 ( V_308 -> V_316 , V_317 ) ;
V_309 |= F_23 ( V_308 -> V_318 , V_319 ) ;
V_309 |= F_23 ( V_308 -> V_320 , V_321 ) ;
V_309 |= F_23 ( V_308 -> V_322 , V_323 ) ;
V_310 |= V_324 ;
V_310 |= V_325 ;
V_310 |= F_23 ( V_308 -> V_326 , V_327 ) ;
V_310 |= F_23 ( V_308 -> V_328 , V_329 ) ;
V_310 |= F_23 ( V_308 -> V_330 , V_331 ) ;
F_8 ( V_2 , V_311 , V_309 ) ;
F_8 ( V_2 , V_332 , V_310 ) ;
if ( V_308 -> V_333 )
F_33 ( V_2 , V_334 , V_335 ) ;
else
F_55 ( V_2 , V_334 , V_335 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_307 * V_308 = & V_2 -> V_336 ;
V_308 -> V_314 = - 28 ;
V_308 -> V_316 = 0 ;
V_308 -> V_318 = 10 ;
V_308 -> V_320 = 24 ;
V_308 -> V_322 = 8 ;
V_308 -> V_326 = 255 ;
V_308 -> V_328 = 12 ;
V_308 -> V_330 = 8 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_337 * V_338 )
{
T_2 V_339 ;
V_339 = F_27 ( V_2 , V_340 ) ;
V_338 -> V_341 = ( V_339 & V_342 ) >>
V_343 ;
V_338 -> V_344 = ( V_339 & V_345 ) >>
V_346 ;
V_338 -> V_347 = ( V_339 & V_348 ) >>
V_349 ;
if ( F_71 ( V_2 ) ) {
V_338 -> V_350 = - 9 ;
V_338 -> V_351 = 1 ;
} else if ( F_4 ( V_2 ) ) {
V_338 -> V_350 = - 9 ;
V_338 -> V_351 = 2 ;
} else {
V_338 -> V_350 = - 3 ;
V_338 -> V_351 = 0 ;
}
}
static void F_72 ( struct V_1 * V_2 ,
struct V_337 * V_338 )
{
T_2 V_339 ;
V_339 = F_27 ( V_2 , V_340 ) ;
V_339 &= ~ ( V_342 |
V_345 |
V_348 |
V_352 |
V_353 ) ;
V_339 |= ( ( V_338 -> V_341 <<
V_343 )
& V_342 ) ;
V_339 |= ( ( V_338 -> V_344 << V_346 )
& V_345 ) ;
V_339 |= ( ( V_338 -> V_347 << V_349 )
& V_348 ) ;
V_339 |= ( ( V_338 -> V_354 << V_355 )
& V_352 ) ;
V_339 |= ( ( V_338 -> V_356 << V_357 )
& V_353 ) ;
F_8 ( V_2 , V_340 , V_339 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_358 * V_359 = F_74 ( V_2 ) ;
struct V_360 * V_361 = F_75 ( V_2 ) ;
static const T_2 V_362 [ 6 ] = {
V_363 ,
V_364 ,
V_365 ,
V_265 ,
V_366 ,
V_367 ,
} ;
V_359 -> V_368 = F_1 ;
V_359 -> V_369 = F_21 ;
V_359 -> V_370 = F_22 ;
V_359 -> V_371 = F_26 ;
V_359 -> V_372 = F_29 ;
V_359 -> V_373 = F_38 ;
V_359 -> V_374 = F_44 ;
V_359 -> V_375 = F_46 ;
V_359 -> V_376 = F_47 ;
V_359 -> V_377 = F_49 ;
V_359 -> V_378 = F_51 ;
V_359 -> V_379 = F_52 ;
V_359 -> V_380 = F_53 ;
V_359 -> V_381 = F_58 ;
V_359 -> V_382 = F_67 ;
V_359 -> V_383 = F_68 ;
V_361 -> V_384 = F_70 ;
V_361 -> V_385 = F_72 ;
F_66 ( V_2 ) ;
F_69 ( V_2 ) ;
memcpy ( V_2 -> V_286 , V_362 , sizeof( V_2 -> V_286 ) ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_193 * V_194 = F_54 ( V_2 ) ;
T_2 V_386 = V_2 -> V_387 ;
T_2 V_122 , V_388 ;
if ( ! V_386 ) {
F_8 ( V_2 , V_389 ,
F_27 ( V_2 , V_389 ) &
~ ( V_390 |
V_391 ) ) ;
F_8 ( V_2 , V_392 ,
F_27 ( V_2 , V_392 ) &
~ ( V_393 |
V_394 ) ) ;
F_56 ( V_194 , V_395 , L_14 ) ;
return;
}
V_122 = F_27 ( V_2 , V_389 ) & V_396 ;
F_8 ( V_2 , V_389 ,
( V_122 | V_391 ) &
~ V_390 ) ;
if ( V_386 > 10000 )
V_386 = 10000 ;
V_388 = ( 100 * V_386 ) / 74 ;
if ( V_2 -> V_21 && F_13 ( V_2 -> V_21 ) )
V_388 = ( 100 * V_386 ) / 37 ;
F_8 ( V_2 , V_392 ,
V_393 |
V_397 |
( V_398 & ( V_388 << 2 ) ) ) ;
F_56 ( V_194 , V_395 ,
L_15 ,
V_386 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
V_2 -> V_399 = F_27 ( V_2 , V_400 ) ;
F_8 ( V_2 , V_400 ,
V_2 -> V_399 & ~ V_401 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_193 * V_194 = F_54 ( V_2 ) ;
T_2 V_402 ;
if ( F_79 ( ! ( V_194 -> V_403 & V_395 ) ) )
return;
V_402 = V_2 -> V_399 ;
F_56 ( V_194 , V_395 ,
L_16 , V_402 ) ;
F_56 ( V_194 , V_395 ,
L_17 ,
F_64 ( V_402 , V_404 ) ,
F_64 ( V_402 , V_405 ) ,
F_64 ( V_402 , V_406 ) ,
F_64 ( V_402 , V_407 ) ,
F_64 ( V_402 , V_408 ) ,
F_64 ( V_402 , V_409 ) ,
F_64 ( V_402 , V_410 ) ,
F_64 ( V_402 , V_411 ) ,
F_64 ( V_402 , V_412 ) ) ;
F_56 ( V_194 , V_395 ,
L_18 ,
F_27 ( V_2 , V_392 ) ,
F_27 ( V_2 , V_389 ) ) ;
F_56 ( V_194 , V_395 ,
L_19 ,
F_27 ( V_2 , V_32 ) ) ;
#define F_80 ( T_6 ) (common->cc_survey._field * 100 / common->cc_survey.cycles)
if ( V_194 -> V_413 . V_414 )
F_56 ( V_194 , V_395 ,
L_20 ,
F_80 ( V_415 ) , F_80 ( V_416 ) , F_80 ( V_417 ) ) ;
F_56 ( V_194 , V_395 ,
L_21 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
T_2 V_122 ;
if ( ! ( ( F_64 ( V_2 -> V_399 ,
V_407 ) == 0xb ) ||
V_2 -> V_418 ) )
return;
V_2 -> V_418 = true ;
V_122 = F_27 ( V_2 , V_419 ) ;
V_122 &= ~ V_420 ;
F_8 ( V_2 , V_419 , V_122 ) ;
}
