static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ) ;
if ( V_8 > 1 )
F_4 ( L_1 , V_2 -> V_9 , V_4 ) ;
F_5 ( V_4 , V_6 -> V_10 ) ;
F_6 ( V_2 ) ;
F_7 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( & V_6 -> V_7 ) ;
if ( V_8 > 1 )
F_4 ( L_2 , V_2 -> V_9 , V_4 ) ;
F_9 ( V_4 , V_6 -> V_10 ) ;
F_6 ( V_2 ) ;
F_7 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_12 -> V_2 ;
struct V_5 * V_6 ;
int V_17 , V_18 , V_19 = V_14 -> V_20 ;
struct V_1 * V_2 ;
long V_21 ;
void T_3 * V_22 ;
int V_23 , V_24 ;
int V_25 ;
#ifndef F_11
static int V_26 ;
if ( ! V_26 ++ )
F_4 ( V_27 ) ;
#endif
if ( F_12 ( V_12 ) )
return - V_28 ;
V_21 = F_13 ( V_12 , 0 ) ;
V_24 = F_14 ( V_12 , 0 ) ;
if ( ! V_21 || ( ( F_15 ( V_12 , 0 ) & V_29 ) == 0 ) ) {
F_16 ( V_16 , L_3 ) ;
return - V_30 ;
}
V_2 = F_17 ( sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_31 ;
F_18 ( V_2 , & V_12 -> V_2 ) ;
V_18 = V_12 -> V_18 ;
if ( F_19 ( V_12 , V_32 ) ) {
F_16 ( V_16 , L_4 ) ;
goto V_33;
}
V_22 = F_20 ( V_21 , V_24 ) ;
if ( ! V_22 ) {
F_16 ( V_16 , L_5 ,
V_24 , V_21 ) ;
goto V_34;
}
F_21 ( V_12 ) ;
F_22 ( V_12 ) ;
#ifdef F_23
if ( V_35 )
V_2 -> V_36 |= V_37 | V_38 ;
#endif
#ifdef F_24
V_2 -> V_36 |= V_39 | V_40 ;
#endif
#ifdef F_25
V_2 -> V_36 |= V_41 ;
#endif
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ )
V_2 -> V_42 [ V_17 ] = F_26 ( V_22 + V_43 + 20 - V_17 ) ;
#if ! F_27 ( V_44 )
if ( V_8 > 4 )
for ( V_17 = 0 ; V_17 < 0x20 ; V_17 ++ )
F_4 ( L_6 ,
( unsigned int ) F_26 ( V_22 + V_43 + V_17 ) ,
V_17 % 16 != 15 ? L_7 : L_8 ) ;
#endif
F_28 ( V_45 , V_22 + V_46 ) ;
F_29 ( 1000 ) ;
F_28 ( 0 , V_22 + V_46 ) ;
F_28 ( 1 , V_22 + V_47 ) ;
V_25 = 1000 ;
while ( -- V_25 > 0 ) {
F_29 ( 10 ) ;
if ( ( F_30 ( V_22 + V_47 ) & 1 ) == 0 )
break;
}
if ( V_25 == 0 )
F_4 ( L_9 , V_2 -> V_9 ) ;
F_29 ( 1000 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_22 = V_22 ;
F_31 ( & V_6 -> V_7 ) ;
F_32 ( V_12 , V_2 ) ;
V_6 -> V_11 = V_12 ;
V_6 -> V_48 . V_2 = V_2 ;
V_6 -> V_48 . V_49 = V_49 ;
V_6 -> V_48 . V_50 = V_50 ;
V_6 -> V_48 . V_51 = 0x1f ;
V_6 -> V_48 . V_52 = 0x1f ;
V_23 = V_53 [ V_19 ] . V_23 ;
V_6 -> V_54 = 1 ;
V_6 -> V_55 = ( ( ( V_56 * 10 ) / 1024 ) & V_57 ) |
V_58 | V_59 ;
if ( V_60 > 0 ) {
V_6 -> V_55 |= V_61 ;
switch ( V_60 ) {
case 1 ... 64 :
V_6 -> V_55 |= V_62 ;
break;
case 65 ... 128 :
V_6 -> V_55 |= V_63 ;
break;
case 129 ... 256 :
V_6 -> V_55 |= V_64 ;
break;
default:
V_6 -> V_55 |= V_65 ;
if ( V_60 > 512 )
F_4 ( L_10 ) ;
break;
}
}
V_2 -> V_66 = & V_66 ;
V_2 -> V_67 = V_68 ;
F_33 ( V_2 , & V_69 ) ;
F_34 ( V_2 , & V_6 -> V_70 , V_71 , V_72 ) ;
if ( V_73 )
V_2 -> V_73 = V_73 ;
if ( F_35 ( V_2 ) )
goto V_74;
F_4 ( V_75 L_11 ,
V_2 -> V_9 , V_53 [ V_19 ] . V_9 , V_22 ,
V_2 -> V_42 , V_18 ) ;
if ( V_23 & V_76 ) {
int V_77 , V_78 = 0 ;
int V_79 ;
for ( V_77 = 0 ; V_77 < 32 && V_78 < V_80 ; V_77 ++ ) {
V_50 ( V_2 , V_77 , V_81 , V_82 ) ;
F_36 ( 100 ) ;
V_25 = 1000 ;
while ( -- V_25 > 0 )
if ( ( V_49 ( V_2 , V_77 , V_81 ) & V_82 ) == 0 )
break;
if ( V_25 == 0 ) {
F_4 ( L_12 , V_2 -> V_9 , V_77 ) ;
continue;
}
V_79 = V_49 ( V_2 , V_77 , V_83 ) ;
if ( V_79 != 0 ) {
V_6 -> V_84 [ V_78 ++ ] = V_77 ;
V_6 -> V_48 . V_85 = V_49 ( V_2 , V_77 , V_86 ) ;
F_4 ( V_75 L_13
L_14 ,
V_2 -> V_9 , V_77 , V_79 , V_6 -> V_48 . V_85 ) ;
break;
}
}
V_6 -> V_87 = V_78 ;
if ( V_6 -> V_87 > 0 )
V_6 -> V_48 . V_88 = V_6 -> V_84 [ 0 ] ;
else
memset ( & V_6 -> V_48 , 0 , sizeof( V_6 -> V_48 ) ) ;
}
F_4 ( V_75 L_15 ,
V_2 -> V_9 , V_35 ? L_16 : L_17 ) ;
return 0 ;
V_74:
F_37 ( V_22 ) ;
V_34:
F_38 ( V_12 ) ;
V_33:
F_39 ( V_2 ) ;
return - V_30 ;
}
static int V_49 ( struct V_1 * V_2 , int V_88 , int V_89 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_90 = V_6 -> V_22 + V_91 + ( V_88 << 7 ) + ( V_89 << 2 ) ;
int V_92 , V_25 = 1000 ;
do {
V_92 = F_30 ( V_90 ) ;
} while ( ( V_92 & 0xC0000000 ) != 0x80000000 && -- V_25 > 0 );
if ( V_25 == 0 )
return 0 ;
if ( ( V_92 & 0xffff ) == 0xffff )
return 0 ;
return V_92 & 0xffff ;
}
static void V_50 ( struct V_1 * V_2 , int V_88 , int V_89 , int V_93 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_90 = V_6 -> V_22 + V_91 + ( V_88 << 7 ) + ( V_89 << 2 ) ;
F_28 ( V_93 , V_90 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 , * V_96 ;
const T_4 * V_97 , * V_98 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_21 = V_6 -> V_22 ;
const int V_18 = V_6 -> V_11 -> V_18 ;
int V_17 , V_99 ;
T_5 V_100 , V_101 ;
T_5 V_102 , V_103 , V_104 , V_105 ;
V_99 = F_41 ( V_18 , V_106 , V_107 , V_2 -> V_9 , V_2 ) ;
if ( V_99 )
return V_99 ;
F_28 ( 0 , V_21 + V_108 ) ;
F_28 ( 1 , V_21 + V_47 ) ;
if ( V_8 > 1 )
F_4 ( V_109 L_18 ,
V_2 -> V_9 , V_18 ) ;
if ( ! V_6 -> V_110 ) {
V_102 = ( ( sizeof( struct V_111 ) * V_112 + V_113 - 1 ) / V_113 ) * V_113 ;
V_103 = ( ( sizeof( V_114 ) * V_112 + V_113 - 1 ) / V_113 ) * V_113 ;
V_104 = ( ( sizeof( V_115 ) * V_116 + V_113 - 1 ) / V_113 ) * V_113 ;
V_105 = sizeof( struct V_117 ) * V_118 ;
V_6 -> V_119 = V_102 + V_103 + V_104 + V_105 ;
V_6 -> V_110 = F_42 ( V_6 -> V_11 , V_6 -> V_119 , & V_6 -> V_120 ) ;
if ( V_6 -> V_110 == NULL ) {
F_43 ( V_18 , V_2 ) ;
return - V_31 ;
}
V_6 -> V_121 = V_6 -> V_110 ;
V_6 -> V_122 = V_6 -> V_120 ;
V_6 -> V_123 = ( void * ) V_6 -> V_121 + V_102 ;
V_6 -> V_124 = V_6 -> V_122 + V_102 ;
V_6 -> V_125 = ( void * ) V_6 -> V_123 + V_103 ;
V_6 -> V_126 = V_6 -> V_124 + V_103 ;
V_6 -> V_127 = ( void * ) V_6 -> V_125 + V_104 ;
V_6 -> V_128 = V_6 -> V_126 + V_104 ;
}
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_28 ( ( V_6 -> V_129 << V_130 ) |
( 0 << V_131 ) |
V_132 | V_133 |
V_134 |
V_135 | V_136 |
V_137 ,
V_21 + V_138 ) ;
F_28 ( V_139 |
( 0 << V_140 ) |
( 6 << V_141 ) |
( ( V_142 / 32 ) << V_143 ) ,
V_21 + V_144 ) ;
F_28 ( ( 2 << V_145 ) |
( 0 << V_146 ) |
( ( V_142 / 32 ) << V_147 ) |
V_148 |
V_149 | V_150 ,
V_21 + V_151 ) ;
F_28 ( ( V_6 -> V_120 >> 16 ) >> 16 , V_21 + V_152 ) ;
F_28 ( ( V_6 -> V_120 >> 16 ) >> 16 , V_21 + V_153 ) ;
F_28 ( ( V_6 -> V_120 >> 16 ) >> 16 , V_21 + V_154 ) ;
F_28 ( V_6 -> V_128 , V_21 + V_155 ) ;
F_28 ( V_6 -> V_126 , V_21 + V_156 ) ;
F_28 ( V_6 -> V_122 , V_21 + V_157 ) ;
F_28 ( V_6 -> V_124 |
V_158 |
( 0 << V_159 ) ,
V_21 + V_160 ) ;
if ( V_8 > 1 )
F_4 ( V_109 L_19 , V_2 -> V_9 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ )
F_46 ( V_2 -> V_42 [ V_17 ] , V_21 + V_161 + 5 - V_17 ) ;
F_47 ( 0 , V_21 + V_162 ) ;
F_47 ( 0 , V_21 + V_162 + 4 ) ;
F_47 ( 0 , V_21 + V_162 + 8 ) ;
for ( V_17 = 1 ; V_17 < 16 ; V_17 ++ ) {
T_1 * V_163 = ( T_1 * ) V_2 -> V_42 ;
void T_3 * V_164 = V_21 + V_162 + V_17 * 16 ;
F_47 ( F_48 ( V_163 [ 2 ] ) , V_164 ) ; V_164 += 4 ;
F_47 ( F_48 ( V_163 [ 1 ] ) , V_164 ) ; V_164 += 4 ;
F_47 ( F_48 ( V_163 [ 0 ] ) , V_164 ) ; V_164 += 8 ;
}
V_6 -> V_165 = V_166 | V_167 | V_168 ;
F_28 ( V_45 | V_6 -> V_165 , V_21 + V_46 ) ;
F_29 ( 1000 ) ;
F_28 ( V_6 -> V_165 , V_21 + V_46 ) ;
V_6 -> V_169 = 4 ;
F_28 ( V_6 -> V_169 , V_21 + V_170 ) ;
F_28 ( V_6 -> V_55 , V_21 + V_171 ) ;
F_49 ( & V_6 -> V_70 ) ;
F_50 ( V_2 ) ;
if ( V_8 > 1 )
F_4 ( V_109 L_20 , V_2 -> V_9 ) ;
F_6 ( V_2 ) ;
V_6 -> V_48 . V_85 = V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_86 ) ;
F_51 ( V_2 ) ;
F_28 ( 0x0f00ff00 , V_21 + V_172 ) ;
F_28 ( V_173 | V_174 | V_175 |
V_176 | V_177 | V_178 |
V_179 | V_180 | V_181 ,
V_21 + V_182 ) ;
F_28 ( 0x00800000 | F_30 ( V_21 + V_47 ) ,
V_21 + V_47 ) ;
#ifdef F_24
F_28 ( V_183 , V_21 + V_184 ) ;
#endif
V_99 = F_52 ( & V_95 , V_185 , & V_6 -> V_11 -> V_2 ) ;
if ( V_99 ) {
F_4 ( V_186 L_21 ,
V_185 ) ;
goto V_187;
}
if ( V_95 -> V_188 % 4 ) {
F_4 ( V_186 L_22 ,
V_95 -> V_188 , V_185 ) ;
V_99 = - V_189 ;
goto V_190;
}
V_99 = F_52 ( & V_96 , V_191 , & V_6 -> V_11 -> V_2 ) ;
if ( V_99 ) {
F_4 ( V_186 L_21 ,
V_191 ) ;
goto V_190;
}
if ( V_96 -> V_188 % 4 ) {
F_4 ( V_186 L_22 ,
V_96 -> V_188 , V_191 ) ;
V_99 = - V_189 ;
goto V_192;
}
V_97 = ( const T_4 * ) & V_95 -> V_193 [ 0 ] ;
V_98 = ( const T_4 * ) & V_96 -> V_193 [ 0 ] ;
V_101 = V_95 -> V_188 / 4 ;
V_100 = V_96 -> V_188 / 4 ;
for ( V_17 = 0 ; V_17 < V_101 ; V_17 ++ )
F_28 ( F_53 ( & V_97 [ V_17 ] ) , V_21 + V_194 + V_17 * 4 ) ;
for ( V_17 = 0 ; V_17 < V_100 ; V_17 ++ )
F_28 ( F_53 ( & V_98 [ V_17 ] ) , V_21 + V_195 + V_17 * 4 ) ;
if ( V_35 )
F_28 ( V_196 | V_197 | V_198 | V_199 , V_21 + V_108 ) ;
else
F_28 ( V_196 | V_198 , V_21 + V_108 ) ;
if ( V_8 > 1 )
F_4 ( V_109 L_23 ,
V_2 -> V_9 ) ;
V_192:
F_54 ( V_96 ) ;
V_190:
F_54 ( V_95 ) ;
V_187:
if ( V_99 )
F_55 ( V_2 ) ;
return V_99 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_200 ;
int V_201 = 1000 ;
V_50 ( V_2 , V_6 -> V_84 [ 0 ] , V_86 , V_6 -> V_48 . V_85 ) ;
V_50 ( V_2 , V_6 -> V_84 [ 0 ] , V_81 , V_82 ) ;
F_29 ( 500 ) ;
while ( -- V_201 && V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_81 ) & V_82 )
;
if ( ! V_201 ) {
F_4 ( L_24 , V_2 -> V_9 ) ;
return;
}
V_200 = V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_81 ) ;
if ( ! V_6 -> V_48 . V_202 ) {
V_200 |= V_203 | V_204 ;
} else {
V_200 &= ~ ( V_203 | V_204 ) ;
if ( V_6 -> V_54 )
V_200 |= V_205 ;
if ( V_6 -> V_48 . V_206 )
V_200 |= V_207 ;
F_4 ( V_109 L_25 ,
V_2 -> V_9 ,
V_6 -> V_54 ? L_26 : L_27 ,
V_6 -> V_48 . V_206 ? L_28 : L_29 ) ;
}
V_50 ( V_2 , V_6 -> V_84 [ 0 ] , V_81 , V_200 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_21 = V_6 -> V_22 ;
int V_208 ;
F_4 ( V_209 L_30
L_31 , V_2 -> V_9 , ( int ) F_30 ( V_21 + V_210 ) ) ;
V_208 = V_8 ;
V_8 = 2 ;
F_55 ( V_2 ) ;
F_40 ( V_2 ) ;
V_8 = V_208 ;
V_2 -> V_211 = V_212 ;
V_2 -> V_213 . V_214 ++ ;
F_57 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_17 ;
V_6 -> V_215 = V_6 -> V_216 = V_6 -> V_217 = 0 ;
V_6 -> V_218 = V_6 -> V_219 = V_6 -> V_220 = V_6 -> V_221 = 0 ;
V_6 -> V_129 = ( V_2 -> V_73 <= 1500 ? V_222 : V_2 -> V_73 + 32 ) ;
for ( V_17 = 0 ; V_17 < V_118 ; V_17 ++ ) {
struct V_223 * V_224 = F_58 ( V_2 , V_6 -> V_129 ) ;
V_6 -> V_225 [ V_17 ] . V_224 = V_224 ;
if ( V_224 == NULL )
break;
V_6 -> V_225 [ V_17 ] . V_226 = F_59 ( V_6 -> V_11 , V_224 -> V_193 , V_6 -> V_129 , V_227 ) ;
V_6 -> V_127 [ V_17 ] . V_228 = F_60 ( V_6 -> V_225 [ V_17 ] . V_226 | V_229 ) ;
}
F_47 ( V_17 - 1 , V_6 -> V_22 + V_230 ) ;
V_6 -> V_218 = ( unsigned int ) ( V_17 - V_118 ) ;
for ( ; V_17 < V_118 ; V_17 ++ ) {
V_6 -> V_127 [ V_17 ] . V_228 = 0 ;
V_6 -> V_225 [ V_17 ] . V_224 = NULL ;
V_6 -> V_225 [ V_17 ] . V_226 = 0 ;
}
V_6 -> V_127 [ V_118 - 1 ] . V_228 |= F_60 ( V_231 ) ;
for ( V_17 = 0 ; V_17 < V_112 ; V_17 ++ ) {
V_6 -> V_123 [ V_17 ] . V_232 = 0 ;
V_6 -> V_121 [ V_17 ] . V_232 = 0 ;
}
for ( V_17 = 0 ; V_17 < V_116 ; V_17 ++ )
memset ( & V_6 -> V_233 [ V_17 ] , 0 , sizeof( V_6 -> V_233 [ V_17 ] ) ) ;
}
static T_6 F_61 ( struct V_223 * V_224 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_234 ;
T_7 V_232 ;
int V_17 ;
if ( ( V_6 -> V_216 - V_6 -> V_219 ) + F_62 ( V_224 ) * 2 > V_116 ) {
F_63 ( V_2 ) ;
return V_235 ;
}
#if F_27 ( F_23 ) && F_27 ( V_236 )
if ( V_224 -> V_237 == V_238 ) {
if ( F_64 ( V_224 , ( V_224 -> V_239 + V_240 ) & ~ V_240 ) )
return V_241 ;
}
#endif
V_234 = V_6 -> V_216 % V_116 ;
for ( V_17 = 0 ; V_17 < F_62 ( V_224 ) ; V_17 ++ ) {
int V_242 = 0 ;
V_232 = V_243 ;
if ( V_17 == 0 ) {
V_6 -> V_233 [ V_234 ] . V_224 = V_224 ;
V_232 |= V_244 ;
if ( V_234 >= V_116 - F_62 ( V_224 ) ) {
V_232 |= V_245 ;
V_242 = 1 ;
}
if ( V_6 -> V_217 ) {
V_232 |= V_246 ;
V_6 -> V_217 = 0 ;
}
if ( V_224 -> V_237 == V_238 ) {
V_232 |= V_247 ;
V_2 -> V_213 . V_248 ++ ;
}
V_232 |= F_65 ( V_224 ) | ( F_62 ( V_224 ) << 16 ) ;
V_6 -> V_233 [ V_234 ] . V_226 =
F_59 ( V_6 -> V_11 , V_224 -> V_193 , F_65 ( V_224 ) , V_249 ) ;
} else {
const T_8 * V_250 = & F_66 ( V_224 ) -> V_251 [ V_17 - 1 ] ;
V_232 |= F_67 ( V_250 ) ;
V_6 -> V_233 [ V_234 ] . V_226 =
F_59 ( V_6 -> V_11 ,
F_68 ( V_250 ) ,
F_67 ( V_250 ) ,
V_249 ) ;
}
V_6 -> V_125 [ V_234 ] . V_252 = F_60 ( V_6 -> V_233 [ V_234 ] . V_226 ) ;
V_6 -> V_125 [ V_234 ] . V_232 = F_69 ( V_232 ) ;
if ( V_8 > 3 )
F_4 ( V_109 L_32 ,
V_2 -> V_9 , V_6 -> V_216 , V_6 -> V_219 ,
V_234 , V_232 ) ;
if ( V_242 ) {
V_6 -> V_233 [ V_234 ] . V_253 = V_116 - V_234 ;
V_6 -> V_216 += V_6 -> V_233 [ V_234 ] . V_253 ;
V_234 = 0 ;
} else {
V_6 -> V_233 [ V_234 ] . V_253 = 1 ;
V_6 -> V_216 += V_6 -> V_233 [ V_234 ] . V_253 ;
V_234 ++ ;
}
if ( V_6 -> V_216 % ( V_116 / 2 ) == 0 )
V_6 -> V_217 = 1 ;
}
F_70 () ;
F_28 ( V_234 * ( sizeof( V_115 ) / 8 ) , V_6 -> V_22 + V_254 ) ;
if ( ( V_6 -> V_216 - V_6 -> V_219 ) + 4 > V_116 )
F_63 ( V_2 ) ;
return V_241 ;
}
static T_9 V_106 ( int V_18 , void * V_255 )
{
struct V_1 * V_2 = V_255 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_21 = V_6 -> V_22 ;
int V_25 = V_72 ;
int V_256 ;
int V_257 ;
int V_258 = 0 ;
do {
T_7 V_259 = F_30 ( V_21 + V_260 ) ;
if ( V_8 > 4 )
F_4 ( V_109 L_33 ,
V_2 -> V_9 , V_259 ) ;
if ( V_259 == 0 || V_259 == ( T_7 ) - 1 )
break;
V_258 = 1 ;
if ( V_259 & ( V_173 | V_174 ) ) {
T_7 V_261 ;
if ( F_71 ( F_72 ( & V_6 -> V_70 ) ) ) {
F_73 ( & V_6 -> V_70 ) ;
V_261 = F_30 ( V_21 + V_182 ) ;
V_261 &= ~ ( V_173 | V_174 ) ;
F_28 ( V_261 , V_21 + V_182 ) ;
F_30 ( V_21 + V_182 ) ;
} else {
V_261 = F_30 ( V_21 + V_182 ) ;
if ( V_261 & ( V_173 | V_174 ) ) {
F_4 ( V_75
L_34 ,
V_2 -> V_9 ) ;
V_261 &= ~ ( V_173 | V_174 ) ;
F_28 ( V_261 , V_21 + V_182 ) ;
}
}
}
V_256 = F_30 ( V_21 + V_262 ) ;
if ( V_8 > 3 )
F_4 ( V_109 L_35 ,
V_2 -> V_9 , V_256 ) ;
while ( ( V_257 = F_74 ( V_6 -> V_121 [ V_6 -> V_221 ] . V_232 ) ) != 0 ) {
if ( V_8 > 3 )
F_4 ( V_109 L_36 ,
V_2 -> V_9 , V_6 -> V_219 , V_6 -> V_221 , V_257 ) ;
if ( ( V_257 & 0xe0000000 ) == 0xa0000000 ) {
V_2 -> V_213 . V_263 ++ ;
} else if ( ( V_257 & 0xe0000000 ) == 0x80000000 ) {
T_2 V_234 = ( V_257 & 0x7fff ) / sizeof( V_115 ) ;
struct V_223 * V_224 = V_6 -> V_233 [ V_234 ] . V_224 ;
V_6 -> V_233 [ V_234 ] . V_224 = NULL ;
F_75 ( V_6 -> V_11 ,
V_6 -> V_233 [ V_234 ] . V_226 ,
F_65 ( V_224 ) ,
V_249 ) ;
V_6 -> V_233 [ V_234 ] . V_226 = 0 ;
V_6 -> V_219 += V_6 -> V_233 [ V_234 ] . V_253 ;
V_234 = ( V_234 + V_6 -> V_233 [ V_234 ] . V_253 ) % V_116 ;
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_66 ( V_224 ) -> V_264 ; V_17 ++ ) {
F_75 ( V_6 -> V_11 ,
V_6 -> V_233 [ V_234 ] . V_226 ,
F_67 ( & F_66 ( V_224 ) -> V_251 [ V_17 ] ) ,
V_249 ) ;
V_6 -> V_219 ++ ;
V_234 ++ ;
}
}
F_76 ( V_224 ) ;
}
V_6 -> V_121 [ V_6 -> V_221 ] . V_232 = 0 ;
V_6 -> V_221 = ( V_6 -> V_221 + 1 ) % V_112 ;
}
F_47 ( V_6 -> V_221 , V_21 + V_265 + 2 ) ;
if ( F_77 ( V_2 ) &&
( V_6 -> V_216 - V_6 -> V_219 + 4 < V_116 ) ) {
F_57 ( V_2 ) ;
}
if ( V_259 & V_177 )
F_78 ( V_2 ) ;
if ( V_259 & V_178 )
F_79 ( V_2 ) ;
if ( V_259 & V_266 )
F_80 ( V_2 , V_259 ) ;
if ( -- V_25 < 0 ) {
if ( V_8 > 1 )
F_4 ( V_209 L_37
L_38 ,
V_2 -> V_9 , V_259 ) ;
break;
}
} while ( 1 );
if ( V_8 > 4 )
F_4 ( V_109 L_39 ,
V_2 -> V_9 , ( int ) F_30 ( V_21 + V_210 ) ) ;
return F_81 ( V_258 ) ;
}
static int F_82 ( struct V_1 * V_2 , int * V_267 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_7 V_268 ;
int V_269 = 0 ;
while ( ( V_268 = F_74 ( V_6 -> V_123 [ V_6 -> V_220 ] . V_232 ) ) != 0 ) {
struct V_223 * V_224 ;
T_2 V_270 ;
int V_234 ;
V_114 * V_271 = & V_6 -> V_123 [ V_6 -> V_220 ] ;
if ( V_8 > 4 )
F_4 ( V_109 L_40 , V_6 -> V_220 , V_268 ) ;
if ( ! ( V_268 & V_272 ) ) {
if ( V_8 > 2 )
F_4 ( V_109 L_41 , V_268 ) ;
V_2 -> V_213 . V_273 ++ ;
if ( V_268 & V_274 )
V_2 -> V_213 . V_275 ++ ;
goto V_276;
}
if ( * V_267 <= 0 ) {
V_269 = 1 ;
goto V_277;
}
( * V_267 ) -- ;
V_270 = V_268 ;
V_234 = ( V_268 >> 16 ) & 0x7ff ;
if ( V_8 > 4 )
F_4 ( V_109 L_42 , V_270 , * V_267 ) ;
if ( V_270 < V_278 &&
( V_224 = F_58 ( V_2 , V_270 + 2 ) ) != NULL ) {
F_83 ( V_224 , 2 ) ;
F_84 ( V_6 -> V_11 ,
V_6 -> V_225 [ V_234 ] . V_226 ,
V_270 , V_227 ) ;
F_85 ( V_224 , V_6 -> V_225 [ V_234 ] . V_224 -> V_193 , V_270 ) ;
F_86 ( V_6 -> V_11 ,
V_6 -> V_225 [ V_234 ] . V_226 ,
V_270 , V_227 ) ;
F_87 ( V_224 , V_270 ) ;
} else {
F_75 ( V_6 -> V_11 , V_6 -> V_225 [ V_234 ] . V_226 , V_6 -> V_129 , V_227 ) ;
V_224 = V_6 -> V_225 [ V_234 ] . V_224 ;
F_87 ( V_224 , V_270 ) ;
V_6 -> V_225 [ V_234 ] . V_224 = NULL ;
V_6 -> V_225 [ V_234 ] . V_226 = 0 ;
}
#ifndef V_44
if ( V_8 > 5 ) {
F_4 ( V_109 L_43 ,
V_224 -> V_193 , V_224 -> V_193 + 6 ,
V_224 -> V_193 [ 12 ] , V_224 -> V_193 [ 13 ] ) ;
}
#endif
V_224 -> V_279 = F_88 ( V_224 , V_2 ) ;
#ifdef F_24
if ( V_8 > 4 )
F_4 ( V_109 L_44 , V_6 -> V_220 , F_89 ( V_271 -> V_280 ) ) ;
#endif
if ( F_89 ( V_271 -> V_280 ) & 0x0100 ) {
V_224 -> V_237 = V_281 ;
V_2 -> V_213 . V_282 ++ ;
}
else if ( F_89 ( V_271 -> V_280 ) & 0x0040 ) {
V_224 -> V_237 = V_283 ;
V_224 -> V_284 = F_89 ( V_271 -> V_284 ) ;
F_4 ( V_109 L_45 , V_2 -> V_9 , F_89 ( V_271 -> V_280 ) ) ;
}
#ifdef F_24
if ( F_89 ( V_271 -> V_280 ) & 0x0200 ) {
T_2 V_285 = F_89 ( V_271 -> V_286 ) ;
if ( V_8 > 4 ) {
F_4 ( V_109 L_46 ,
V_285 ) ;
}
F_90 ( V_224 , F_91 ( V_183 ) , V_285 ) ;
}
#endif
F_92 ( V_224 ) ;
V_2 -> V_213 . V_287 ++ ;
V_276:
V_6 -> V_215 ++ ;
V_271 -> V_232 = 0 ;
V_6 -> V_220 = ( V_6 -> V_220 + 1 ) % V_112 ;
}
if ( * V_267 == 0 ) {
V_269 = 1 ;
goto V_277;
}
F_47 ( V_6 -> V_220 , V_6 -> V_22 + V_265 ) ;
V_277:
F_93 ( V_2 ) ;
if ( V_8 > 5 )
F_4 ( V_109 L_47 ,
V_269 , V_6 -> V_220 , V_268 ) ;
return V_269 ;
}
static int V_71 ( struct V_288 * V_70 , int V_289 )
{
struct V_5 * V_6 = F_94 ( V_70 , struct V_5 , V_70 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
T_7 V_259 ;
void T_3 * V_21 = V_6 -> V_22 ;
int V_267 = V_289 ;
do {
F_28 ( V_173 | V_174 , V_21 + V_260 ) ;
if ( F_82 ( V_2 , & V_267 ) )
goto V_277;
V_259 = F_30 ( V_21 + V_210 ) ;
} while ( V_259 & ( V_173 | V_174 ) );
F_95 ( V_70 ) ;
V_259 = F_30 ( V_21 + V_182 ) ;
V_259 |= V_173 | V_174 ;
F_28 ( V_259 , V_21 + V_182 ) ;
V_277:
if ( V_8 > 5 )
F_4 ( V_109 L_48 ,
V_289 - V_267 ) ;
return V_289 - V_267 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_223 * V_224 ;
int V_234 = - 1 ;
for (; V_6 -> V_215 - V_6 -> V_218 > 0 ; V_6 -> V_218 ++ ) {
V_234 = V_6 -> V_218 % V_118 ;
if ( V_6 -> V_225 [ V_234 ] . V_224 == NULL ) {
V_224 = F_58 ( V_2 , V_6 -> V_129 ) ;
V_6 -> V_225 [ V_234 ] . V_224 = V_224 ;
if ( V_224 == NULL )
break;
V_6 -> V_225 [ V_234 ] . V_226 =
F_59 ( V_6 -> V_11 , V_224 -> V_193 , V_6 -> V_129 , V_227 ) ;
V_6 -> V_127 [ V_234 ] . V_228 =
F_60 ( V_6 -> V_225 [ V_234 ] . V_226 | V_229 ) ;
}
if ( V_234 == V_118 - 1 )
V_6 -> V_127 [ V_234 ] . V_228 |= F_60 ( V_231 ) ;
}
if ( V_234 >= 0 )
F_47 ( V_234 , V_6 -> V_22 + V_230 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_21 = V_6 -> V_22 ;
T_2 V_200 , V_290 , V_291 , V_292 ;
T_7 V_293 ;
T_7 V_294 ;
V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_81 ) ;
V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_83 ) ;
V_200 = V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_81 ) ;
V_290 = V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_83 ) ;
if ( V_290 & V_295 ) {
if ( V_200 & V_203 ) {
V_291 = V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_86 ) ;
V_292 = V_49 ( V_2 , V_6 -> V_84 [ 0 ] , V_296 ) ;
if ( V_291 & V_297 && V_292 & V_298 ) {
V_6 -> V_54 = 1 ;
V_6 -> V_48 . V_206 = 1 ;
} else if ( V_291 & V_299 && V_292 & V_300 ) {
V_6 -> V_54 = 1 ;
V_6 -> V_48 . V_206 = 0 ;
} else if ( V_291 & V_301 && V_292 & V_302 ) {
V_6 -> V_54 = 0 ;
V_6 -> V_48 . V_206 = 1 ;
} else {
V_6 -> V_54 = 0 ;
V_6 -> V_48 . V_206 = 0 ;
}
} else {
if ( V_200 & V_205 )
V_6 -> V_54 = 1 ;
else
V_6 -> V_54 = 0 ;
if ( V_200 & V_207 )
V_6 -> V_48 . V_206 = 1 ;
else
V_6 -> V_48 . V_206 = 0 ;
}
F_96 ( V_2 ) ;
F_4 ( V_109 L_49 ,
V_2 -> V_9 ,
V_6 -> V_54 ? L_26 : L_27 ,
V_6 -> V_48 . V_206 ? L_28 : L_29 ) ;
V_293 = V_6 -> V_165 & ~ V_303 ;
if ( V_6 -> V_48 . V_206 )
V_293 |= V_303 ;
if ( V_6 -> V_165 != V_293 ) {
V_6 -> V_165 = V_293 ;
F_28 ( V_6 -> V_165 | V_45 , V_21 + V_46 ) ;
F_29 ( 1000 ) ;
F_28 ( V_6 -> V_165 , V_21 + V_46 ) ;
}
V_294 = V_6 -> V_55 & ~ V_58 ;
if ( V_6 -> V_54 )
V_294 |= V_58 ;
if ( V_6 -> V_55 != V_294 ) {
V_6 -> V_55 = V_294 ;
F_28 ( V_294 , V_21 + V_171 ) ;
}
} else {
F_44 ( V_2 ) ;
F_4 ( V_109 L_50 , V_2 -> V_9 ) ;
}
}
static void F_80 ( struct V_1 * V_2 , int V_259 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_259 & V_304 ) {
if ( V_6 -> V_169 <= V_222 / 16 ) {
F_28 ( ++ V_6 -> V_169 , V_6 -> V_22 + V_170 ) ;
F_4 ( V_305 L_51 ,
V_2 -> V_9 , V_6 -> V_169 * 16 ) ;
} else
F_4 ( V_209 L_52 , V_2 -> V_9 ) ;
}
if ( V_259 & V_179 ) {
V_2 -> V_213 . V_275 ++ ;
V_2 -> V_213 . V_273 ++ ;
}
if ( V_259 & ( V_180 | V_175 ) ) {
V_2 -> V_213 . V_306 ++ ;
V_2 -> V_213 . V_214 ++ ;
}
if ( ( V_259 & ~ ( V_307 | V_266 | V_178 | V_177 | V_304 | V_179 | V_180 | V_308 ) ) && V_8 )
F_4 ( V_186 L_53 ,
V_2 -> V_9 , V_259 ) ;
}
static struct V_309 * F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_21 = V_6 -> V_22 ;
V_2 -> V_213 . V_310 = F_30 ( V_21 + 0x57010 ) ;
V_2 -> V_213 . V_311 = F_30 ( V_21 + 0x57044 ) ;
V_2 -> V_213 . V_263 = F_30 ( V_21 + 0x57000 ) ;
V_2 -> V_213 . V_312 =
F_30 ( V_21 + 0x57024 ) + F_30 ( V_21 + 0x57028 ) ;
V_2 -> V_213 . V_313 = F_30 ( V_21 + 0x57018 ) ;
V_2 -> V_213 . V_314 =
F_30 ( V_21 + 0x57004 ) + F_30 ( V_21 + 0x57008 ) ;
V_2 -> V_213 . V_315 += F_97 ( V_21 + V_316 ) ;
F_47 ( 0 , V_21 + V_316 ) ;
V_2 -> V_213 . V_317 = F_30 ( V_21 + 0x5703C ) ;
V_2 -> V_213 . V_318 = F_30 ( V_21 + 0x57040 ) ;
V_2 -> V_213 . V_319 = F_30 ( V_21 + 0x57058 ) ;
V_2 -> V_213 . V_320 = F_30 ( V_21 + 0x5707C ) ;
return & V_2 -> V_213 ;
}
static T_7 F_98 ( struct V_5 * V_6 )
{
T_7 V_321 = V_322 ;
T_2 V_4 ;
void T_3 * V_323 = V_6 -> V_22 + V_324 + 8 ;
int V_325 = 0 ;
F_99 (vid, np->active_vlans, VLAN_N_VID) {
if ( V_325 == 32 )
break;
F_47 ( V_4 , V_323 ) ;
V_323 += 16 ;
V_325 ++ ;
}
if ( V_325 == 32 ) {
V_321 |= V_326 ;
while ( V_325 < 32 ) {
F_47 ( 0 , V_323 ) ;
V_323 += 16 ;
V_325 ++ ;
}
}
return V_321 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_21 = V_6 -> V_22 ;
T_7 V_327 = V_328 ;
struct V_329 * V_330 ;
int V_17 ;
#ifdef F_24
V_327 |= F_98 ( V_6 ) ;
#endif
if ( V_2 -> V_331 & V_332 ) {
V_327 |= V_333 ;
} else if ( ( F_100 ( V_2 ) > V_334 ) ||
( V_2 -> V_331 & V_335 ) ) {
V_327 |= V_336 | V_337 | V_338 ;
} else if ( F_100 ( V_2 ) <= 14 ) {
void T_3 * V_323 = V_21 + V_162 + 2 * 16 ;
T_1 * V_163 ;
F_101 (ha, dev) {
V_163 = ( T_1 * ) V_330 -> V_252 ;
F_47 ( F_48 ( V_163 [ 2 ] ) , V_323 ) ; V_323 += 4 ;
F_47 ( F_48 ( V_163 [ 1 ] ) , V_323 ) ; V_323 += 4 ;
F_47 ( F_48 ( V_163 [ 0 ] ) , V_323 ) ; V_323 += 8 ;
}
V_163 = ( T_1 * ) V_2 -> V_42 ;
V_17 = F_100 ( V_2 ) + 2 ;
while ( V_17 ++ < 16 ) {
F_47 ( F_48 ( V_163 [ 0 ] ) , V_323 ) ; V_323 += 4 ;
F_47 ( F_48 ( V_163 [ 1 ] ) , V_323 ) ; V_323 += 4 ;
F_47 ( F_48 ( V_163 [ 2 ] ) , V_323 ) ; V_323 += 8 ;
}
V_327 |= V_336 | V_338 ;
} else {
void T_3 * V_323 ;
T_1 * V_163 ;
T_10 V_339 [ 32 ] V_340 ( ( F_102 ( sizeof( long ) ) ) ) ;
memset ( V_339 , 0 , sizeof( V_339 ) ) ;
F_101 (ha, dev) {
int V_341 = F_103 ( V_342 , V_330 -> V_252 ) >> 23 ;
T_11 * V_343 = ( T_11 * ) & V_339 [ ( V_341 >> 4 ) & ~ 1 ] ;
* V_343 |= F_69 ( 1 << ( V_341 & 31 ) ) ;
}
V_323 = V_21 + V_162 + 2 * 16 ;
V_163 = ( T_1 * ) V_2 -> V_42 ;
for ( V_17 = 2 ; V_17 < 16 ; V_17 ++ ) {
F_47 ( F_48 ( V_163 [ 0 ] ) , V_323 ) ; V_323 += 4 ;
F_47 ( F_48 ( V_163 [ 1 ] ) , V_323 ) ; V_323 += 4 ;
F_47 ( F_48 ( V_163 [ 2 ] ) , V_323 ) ; V_323 += 8 ;
}
for ( V_323 = V_21 + V_324 , V_17 = 0 ; V_17 < 32 ; V_323 += 16 , V_17 ++ )
F_47 ( V_339 [ V_17 ] , V_323 ) ;
V_327 |= V_336 | V_338 | V_344 ;
}
F_28 ( V_327 , V_21 + V_345 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
if ( ! F_105 ( V_2 ) )
return - V_189 ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 , struct V_346 * V_347 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_107 ( V_347 -> V_348 , V_32 , sizeof( V_347 -> V_348 ) ) ;
F_107 ( V_347 -> V_27 , V_349 , sizeof( V_347 -> V_27 ) ) ;
F_107 ( V_347 -> V_350 , F_108 ( V_6 -> V_11 ) , sizeof( V_347 -> V_350 ) ) ;
}
static int F_109 ( struct V_1 * V_2 , struct V_351 * V_352 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_110 ( & V_6 -> V_7 ) ;
F_111 ( & V_6 -> V_48 , V_352 ) ;
F_112 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , struct V_351 * V_352 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_353 ;
F_110 ( & V_6 -> V_7 ) ;
V_353 = F_114 ( & V_6 -> V_48 , V_352 ) ;
F_112 ( & V_6 -> V_7 ) ;
F_51 ( V_2 ) ;
return V_353 ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_116 ( & V_6 -> V_48 ) ;
}
static T_7 F_117 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_118 ( & V_6 -> V_48 ) ;
}
static T_7 F_119 ( struct V_1 * V_2 )
{
return V_8 ;
}
static void F_120 ( struct V_1 * V_2 , T_7 V_354 )
{
V_8 = V_354 ;
}
static int F_121 ( struct V_1 * V_2 , struct V_355 * V_356 , int V_357 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_358 * V_193 = F_122 ( V_356 ) ;
int V_359 ;
if ( ! F_105 ( V_2 ) )
return - V_189 ;
F_110 ( & V_6 -> V_7 ) ;
V_359 = F_123 ( & V_6 -> V_48 , V_193 , V_357 , NULL ) ;
F_112 ( & V_6 -> V_7 ) ;
if ( ( V_357 == V_360 ) && ( V_193 -> V_88 == V_6 -> V_84 [ 0 ] ) )
F_51 ( V_2 ) ;
return V_359 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_3 * V_21 = V_6 -> V_22 ;
int V_17 ;
F_63 ( V_2 ) ;
F_124 ( & V_6 -> V_70 ) ;
if ( V_8 > 1 ) {
F_4 ( V_109 L_54 ,
V_2 -> V_9 , ( int ) F_30 ( V_21 + V_210 ) ) ;
F_4 ( V_109 L_55 ,
V_2 -> V_9 , V_6 -> V_216 , V_6 -> V_219 ,
V_6 -> V_215 , V_6 -> V_218 ) ;
}
F_28 ( 0 , V_21 + V_182 ) ;
F_28 ( 0 , V_21 + V_108 ) ;
F_30 ( V_21 + V_108 ) ;
if ( V_8 > 5 ) {
F_4 ( V_109 L_56 ,
( long long ) V_6 -> V_126 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_4 ( V_109 L_57 ,
V_17 , F_74 ( V_6 -> V_125 [ V_17 ] . V_232 ) ,
( long long ) F_125 ( V_6 -> V_125 [ V_17 ] . V_252 ) ,
F_74 ( V_6 -> V_121 [ V_17 ] . V_232 ) ) ;
F_4 ( V_109 L_58 ,
( long long ) V_6 -> V_128 , V_6 -> V_123 ) ;
if ( V_6 -> V_123 )
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
F_4 ( V_109 L_59 ,
V_17 , ( long long ) F_125 ( V_6 -> V_127 [ V_17 ] . V_228 ) , F_74 ( V_6 -> V_123 [ V_17 ] . V_232 ) ) ;
}
}
F_43 ( V_6 -> V_11 -> V_18 , V_2 ) ;
for ( V_17 = 0 ; V_17 < V_118 ; V_17 ++ ) {
V_6 -> V_127 [ V_17 ] . V_228 = F_60 ( 0xBADF00D0 ) ;
if ( V_6 -> V_225 [ V_17 ] . V_224 != NULL ) {
F_75 ( V_6 -> V_11 , V_6 -> V_225 [ V_17 ] . V_226 , V_6 -> V_129 , V_227 ) ;
F_126 ( V_6 -> V_225 [ V_17 ] . V_224 ) ;
}
V_6 -> V_225 [ V_17 ] . V_224 = NULL ;
V_6 -> V_225 [ V_17 ] . V_226 = 0 ;
}
for ( V_17 = 0 ; V_17 < V_116 ; V_17 ++ ) {
struct V_223 * V_224 = V_6 -> V_233 [ V_17 ] . V_224 ;
if ( V_224 == NULL )
continue;
F_75 ( V_6 -> V_11 ,
V_6 -> V_233 [ V_17 ] . V_226 ,
F_65 ( V_224 ) , V_249 ) ;
V_6 -> V_233 [ V_17 ] . V_226 = 0 ;
F_126 ( V_224 ) ;
V_6 -> V_233 [ V_17 ] . V_224 = NULL ;
}
return 0 ;
}
static int F_127 ( struct V_11 * V_12 , T_12 V_361 )
{
struct V_1 * V_2 = F_128 ( V_12 ) ;
if ( F_105 ( V_2 ) ) {
F_129 ( V_2 ) ;
F_55 ( V_2 ) ;
}
F_130 ( V_12 ) ;
F_131 ( V_12 , F_132 ( V_12 , V_361 ) ) ;
return 0 ;
}
static int F_133 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_128 ( V_12 ) ;
F_131 ( V_12 , V_362 ) ;
F_134 ( V_12 ) ;
if ( F_105 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_135 ( V_2 ) ;
}
return 0 ;
}
static void F_136 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_128 ( V_12 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_137 ( ! V_2 ) ;
F_138 ( V_2 ) ;
if ( V_6 -> V_110 )
F_139 ( V_12 , V_6 -> V_119 , V_6 -> V_110 , V_6 -> V_120 ) ;
F_131 ( V_12 , V_363 ) ;
F_140 ( V_12 ) ;
F_37 ( V_6 -> V_22 ) ;
F_38 ( V_12 ) ;
F_39 ( V_2 ) ;
}
static int T_13 F_141 ( void )
{
#ifdef F_11
F_4 ( V_27 ) ;
F_4 (KERN_INFO DRV_NAME L_60 ) ;
#endif
F_142 ( sizeof( V_364 ) != sizeof( V_365 ) ) ;
return F_143 ( & V_366 ) ;
}
static void T_14 F_144 ( void )
{
F_145 ( & V_366 ) ;
}
