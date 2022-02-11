void T_1 F_1 ( void )
{
F_2 ( V_1 , V_2 . V_3 ) ;
F_2 ( V_4 , V_2 . V_3 ) ;
F_3 ( & V_5 ) ;
}
void T_1 F_1 ( void ) {}
void T_1 F_4 ( struct V_6 * V_7 )
{
int V_8 ;
if ( ! V_7 )
return;
for ( V_8 = 0 ; V_8 < V_7 -> V_9 ; V_8 ++ ) {
if ( V_7 -> V_10 [ V_8 ] )
F_5 ( V_7 -> V_10 [ V_8 ] , 0 ) ;
}
for ( V_8 = 0 ; V_8 < V_7 -> V_9 ; V_8 ++ ) {
if ( V_7 -> V_11 [ V_8 ] )
F_6 ( V_7 -> V_11 [ V_8 ] , 1 ) ;
}
V_12 = * V_7 ;
F_3 ( & V_13 ) ;
}
void T_1 F_4 ( struct V_6 * V_7 ) {}
void T_1 F_7 ( struct V_6 * V_7 )
{
int V_8 ;
if ( ! V_7 )
return;
for ( V_8 = 0 ; V_8 < V_7 -> V_9 ; V_8 ++ ) {
if ( V_7 -> V_10 [ V_8 ] )
F_5 ( V_7 -> V_10 [ V_8 ] , 0 ) ;
}
V_14 = * V_7 ;
F_3 ( & V_15 ) ;
}
void T_1 F_7 ( struct V_6 * V_7 ) {}
void T_1 F_8 ( struct V_16 * V_7 )
{
V_17 . V_18 . V_10 = - V_19 ;
V_17 . V_18 . V_20 = F_9 ( V_21 ) ;
memcpy ( V_17 . V_22 , V_21 , sizeof( V_21 ) ) ;
if ( V_7 && V_7 -> V_10 > 0 ) {
F_6 ( V_7 -> V_10 , 0 ) ;
F_10 ( V_7 -> V_10 , 1 ) ;
V_17 . V_18 . V_10 = V_7 -> V_10 ;
}
F_3 ( & V_23 ) ;
}
void T_1 F_8 ( struct V_16 * V_7 ) {}
void T_1 F_11 ( struct V_24 * V_7 )
{
if ( ! V_7 )
return;
if ( V_7 -> V_25 ) {
F_6 ( V_7 -> V_25 , 0 ) ;
F_10 ( V_7 -> V_25 , 1 ) ;
}
F_12 ( V_26 , 0 ) ;
F_12 ( V_27 , 0 ) ;
F_12 ( V_28 , 0 ) ;
F_12 ( V_29 , 0 ) ;
F_12 ( V_30 , 0 ) ;
F_12 ( V_31 , 0 ) ;
F_12 ( V_32 , 0 ) ;
F_12 ( V_33 , 0 ) ;
F_12 ( V_34 , 0 ) ;
F_12 ( V_35 , 0 ) ;
if ( ! V_7 -> V_36 ) {
F_13 ( V_37 , 0 ) ;
F_13 ( V_38 , 0 ) ;
F_13 ( V_39 , 0 ) ;
F_13 ( V_40 , 0 ) ;
F_13 ( V_41 , 0 ) ;
F_13 ( V_42 , 0 ) ;
F_13 ( V_43 , 0 ) ;
F_13 ( V_44 , 0 ) ;
}
V_45 = * V_7 ;
F_3 ( & V_46 ) ;
}
void T_1 F_11 ( struct V_24 * V_7 ) {}
void T_1 F_14 ( short V_47 , struct V_48 * V_7 )
{
if ( ! V_7 )
return;
if ( ! V_7 -> V_49 [ 0 ] . V_50 )
return;
#if F_15 ( V_51 ) || F_15 ( V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
V_56 = F_16 ( sizeof( struct V_55 ) , V_57 ) ;
V_54 = & V_56 -> V_58 ;
V_54 -> V_59 = & V_5 . V_60 ;
V_54 -> V_61 = V_62 ;
V_54 -> V_63 = V_64
| V_65 | V_66 ;
V_54 -> V_67 = V_68 | V_69 ;
if ( V_47 == 0 )
V_54 -> V_63 |= F_17 ( V_70 )
| F_18 ( V_70 ) ;
else
V_54 -> V_63 |= F_17 ( V_71 )
| F_18 ( V_71 ) ;
V_7 -> V_72 = V_56 ;
}
#endif
if ( V_7 -> V_49 [ 0 ] . V_73 ) {
F_6 ( V_7 -> V_49 [ 0 ] . V_73 , 1 ) ;
F_10 ( V_7 -> V_49 [ 0 ] . V_73 , 1 ) ;
}
if ( V_7 -> V_49 [ 0 ] . V_74 )
F_6 ( V_7 -> V_49 [ 0 ] . V_74 , 1 ) ;
if ( V_47 == 0 ) {
F_12 ( V_75 , 0 ) ;
F_12 ( V_76 , 1 ) ;
F_12 ( V_77 , 1 ) ;
if ( V_7 -> V_49 [ 0 ] . V_50 == 4 ) {
F_12 ( V_78 , 1 ) ;
F_12 ( V_79 , 1 ) ;
F_12 ( V_80 , 1 ) ;
if ( V_7 -> V_49 [ 0 ] . V_50 == 8 ) {
F_12 ( V_42 , 1 ) ;
F_12 ( V_43 , 1 ) ;
F_12 ( V_39 , 1 ) ;
F_12 ( V_40 , 1 ) ;
}
}
V_81 = * V_7 ;
F_3 ( & V_82 ) ;
} else {
F_12 ( V_83 , 0 ) ;
F_12 ( V_84 , 1 ) ;
F_12 ( V_85 , 1 ) ;
if ( V_7 -> V_49 [ 0 ] . V_50 == 4 ) {
F_12 ( V_86 , 1 ) ;
F_12 ( V_87 , 1 ) ;
F_12 ( V_88 , 1 ) ;
if ( V_7 -> V_49 [ 0 ] . V_50 == 8 ) {
F_12 ( V_44 , 1 ) ;
F_12 ( V_41 , 1 ) ;
F_12 ( V_37 , 1 ) ;
F_12 ( V_38 , 1 ) ;
}
}
V_89 = * V_7 ;
F_3 ( & V_90 ) ;
}
}
void T_1 F_14 ( short V_47 , struct V_48 * V_7 ) {}
void T_1 F_19 ( struct V_91 * V_7 )
{
unsigned long V_92 ;
if ( ! V_7 )
return;
V_92 = F_20 ( V_93 ) ;
F_21 ( V_93 , V_92 | V_94 ) ;
if ( V_7 -> V_95 )
F_5 ( V_7 -> V_95 , 1 ) ;
if ( V_7 -> V_96 )
F_6 ( V_7 -> V_96 , 1 ) ;
if ( V_7 -> V_97 )
F_6 ( V_7 -> V_97 , 1 ) ;
V_98 = * V_7 ;
F_3 ( & V_99 ) ;
}
void T_1 F_19 ( struct V_91 * V_7 ) {}
void T_1 F_22 ( short V_100 , struct V_101 * V_102 , int V_103 )
{
F_23 ( V_100 , V_102 , V_103 ) ;
if ( V_100 == 0 ) {
F_24 ( V_104 , 1 ) ;
F_25 ( V_104 , 1 ) ;
F_24 ( V_105 , 1 ) ;
F_25 ( V_105 , 1 ) ;
F_3 ( & V_106 ) ;
} else {
F_24 ( V_107 , 1 ) ;
F_25 ( V_107 , 1 ) ;
F_24 ( V_108 , 1 ) ;
F_25 ( V_108 , 1 ) ;
F_3 ( & V_109 ) ;
}
}
void T_1 F_22 ( short V_100 , struct V_101 * V_102 , int V_103 )
{
F_23 ( V_100 , V_102 , V_103 ) ;
if ( V_100 == 0 ) {
F_12 ( V_104 , 0 ) ;
F_25 ( V_104 , 1 ) ;
F_12 ( V_105 , 0 ) ;
F_25 ( V_105 , 1 ) ;
F_3 ( & V_106 ) ;
} else {
F_12 ( V_107 , 0 ) ;
F_25 ( V_107 , 1 ) ;
F_12 ( V_108 , 0 ) ;
F_25 ( V_108 , 1 ) ;
F_3 ( & V_109 ) ;
}
}
void T_1 F_22 ( short V_100 , struct V_101 * V_102 , int V_103 ) {}
void T_1 F_26 ( struct V_110 * V_102 , int V_103 )
{
int V_8 ;
unsigned long V_111 ;
short V_112 = 0 ;
short V_113 = 0 ;
for ( V_8 = 0 ; V_8 < V_103 ; V_8 ++ ) {
if ( V_102 [ V_8 ] . V_114 )
V_111 = ( unsigned long ) V_102 [ V_8 ] . V_114 ;
else if ( V_102 [ V_8 ] . V_115 == 0 )
V_111 = V_116 [ V_102 [ V_8 ] . V_117 ] ;
else
V_111 = V_118 [ V_102 [ V_8 ] . V_117 ] ;
if ( V_102 [ V_8 ] . V_115 == 0 )
V_112 = 1 ;
else
V_113 = 1 ;
F_5 ( V_111 , 1 ) ;
V_102 [ V_8 ] . V_114 = ( void * ) V_111 ;
}
F_27 ( V_102 , V_103 ) ;
if ( V_112 ) {
F_12 ( V_119 , 0 ) ;
F_12 ( V_120 , 0 ) ;
F_12 ( V_121 , 0 ) ;
F_3 ( & V_122 ) ;
}
if ( V_113 ) {
F_12 ( V_123 , 0 ) ;
F_12 ( V_124 , 0 ) ;
F_12 ( V_125 , 0 ) ;
F_3 ( & V_126 ) ;
}
}
void T_1 F_26 ( struct V_110 * V_102 , int V_103 ) {}
void T_1 F_28 ( struct V_127 * V_7 )
{
if ( ! V_7 )
return;
F_12 ( V_128 , 0 ) ;
F_12 ( V_129 , 0 ) ;
F_12 ( V_130 , 0 ) ;
F_12 ( V_131 , 0 ) ;
if ( V_7 -> V_132 )
F_5 ( V_7 -> V_132 , 0 ) ;
V_133 = * V_7 ;
F_3 ( & V_134 ) ;
}
void T_1 F_28 ( struct V_127 * V_7 ) {}
void T_1 F_29 ( struct V_135 * V_7 )
{
if ( ! V_7 )
return;
F_12 ( V_136 , 0 ) ;
F_12 ( V_137 , 0 ) ;
F_12 ( V_138 , 0 ) ;
F_12 ( V_139 , 0 ) ;
F_12 ( V_140 , 0 ) ;
F_12 ( V_141 , 0 ) ;
F_12 ( V_142 , 0 ) ;
F_12 ( V_143 , 0 ) ;
F_12 ( V_144 , 0 ) ;
F_12 ( V_145 , 0 ) ;
F_12 ( V_146 , 0 ) ;
F_12 ( V_147 , 0 ) ;
F_12 ( V_148 , 0 ) ;
F_12 ( V_149 , 0 ) ;
F_12 ( V_150 , 0 ) ;
F_12 ( V_151 , 0 ) ;
F_12 ( V_152 , 0 ) ;
F_12 ( V_153 , 0 ) ;
F_12 ( V_154 , 0 ) ;
F_12 ( V_155 , 0 ) ;
F_12 ( V_156 , 0 ) ;
F_12 ( V_157 , 0 ) ;
F_12 ( V_158 , 0 ) ;
F_12 ( V_159 , 0 ) ;
F_12 ( V_160 , 0 ) ;
F_12 ( V_161 , 0 ) ;
F_12 ( V_162 , 0 ) ;
F_12 ( V_163 , 0 ) ;
F_12 ( V_164 , 0 ) ;
F_12 ( V_165 , 0 ) ;
V_166 = * V_7 ;
F_3 ( & V_167 ) ;
}
void T_1 F_29 ( struct V_135 * V_7 ) {}
static void T_1 F_30 ( void )
{
F_3 ( & V_168 ) ;
F_3 ( & V_169 ) ;
}
static void T_1 F_30 ( void ) { }
static void T_1 F_31 ( void )
{
F_3 ( & V_170 ) ;
}
static void T_1 F_31 ( void ) {}
void T_1 F_32 ( struct V_171 * V_7 )
{
if ( ! V_7 )
return;
F_6 ( V_172 , 0 ) ;
F_6 ( V_173 , 0 ) ;
F_6 ( V_174 , 0 ) ;
F_6 ( V_175 , 0 ) ;
V_176 = * V_7 ;
F_3 ( & V_177 ) ;
}
void T_1 F_32 ( struct V_171 * V_7 ) {}
static void T_1 F_33 ( void )
{
F_3 ( & V_178 ) ;
}
static void T_1 F_34 ( void )
{
F_3 ( & V_179 ) ;
}
static void T_1 F_34 ( void ) {}
static void T_1 F_35 ( void )
{
F_3 ( & V_180 ) ;
}
static void T_1 F_35 ( void ) {}
void T_1 F_36 ( T_2 V_181 )
{
if ( V_181 & ( 1 << V_182 ) )
F_13 ( V_183 , 1 ) ;
if ( V_181 & ( 1 << V_184 ) )
F_13 ( V_185 , 1 ) ;
if ( V_181 & ( 1 << V_186 ) )
F_13 ( V_187 , 1 ) ;
if ( V_181 & ( 1 << V_188 ) )
F_13 ( V_189 , 1 ) ;
V_190 = V_181 ;
F_3 ( & V_191 ) ;
}
void T_1 F_36 ( T_2 V_181 ) {}
static inline void F_37 ( unsigned V_192 )
{
if ( V_192 & V_193 )
F_12 ( V_194 , 1 ) ;
if ( V_192 & V_195 )
F_12 ( V_189 , 1 ) ;
if ( V_192 & V_196 )
F_12 ( V_197 , 1 ) ;
if ( V_192 & V_198 )
F_12 ( V_199 , 1 ) ;
if ( V_192 & V_200 )
F_12 ( V_201 , 1 ) ;
if ( V_192 & V_202 )
F_12 ( V_203 , 1 ) ;
}
static inline void F_38 ( unsigned V_192 )
{
if ( V_192 & V_193 )
F_12 ( V_204 , 1 ) ;
if ( V_192 & V_195 )
F_12 ( V_205 , 1 ) ;
if ( V_192 & V_196 )
F_12 ( V_206 , 1 ) ;
if ( V_192 & V_198 )
F_12 ( V_207 , 1 ) ;
if ( V_192 & V_200 )
F_12 ( V_208 , 1 ) ;
if ( V_192 & V_202 )
F_12 ( V_209 , 1 ) ;
}
void T_1 F_39 ( unsigned V_210 , unsigned V_192 )
{
struct V_211 * V_212 ;
switch ( V_210 ) {
case V_213 :
V_212 = & V_214 ;
F_37 ( V_192 ) ;
break;
case V_215 :
V_212 = & V_216 ;
F_38 ( V_192 ) ;
break;
default:
return;
}
F_3 ( V_212 ) ;
}
void T_1 F_39 ( unsigned V_210 , unsigned V_192 ) {}
static inline void F_40 ( void )
{
F_12 ( V_217 , 0 ) ;
F_12 ( V_218 , 1 ) ;
}
static inline void F_41 ( unsigned V_192 )
{
F_12 ( V_219 , 1 ) ;
F_12 ( V_220 , 0 ) ;
if ( V_192 & V_221 )
F_13 ( V_222 , 0 ) ;
if ( V_192 & V_223 )
F_13 ( V_124 , 0 ) ;
}
static inline void F_42 ( unsigned V_192 )
{
F_12 ( V_224 , 1 ) ;
F_12 ( V_225 , 0 ) ;
if ( V_192 & V_221 )
F_12 ( V_226 , 0 ) ;
if ( V_192 & V_223 )
F_12 ( V_227 , 0 ) ;
}
static inline void F_43 ( unsigned V_192 )
{
F_12 ( V_228 , 1 ) ;
F_12 ( V_229 , 0 ) ;
if ( V_192 & V_221 )
F_13 ( V_230 , 0 ) ;
if ( V_192 & V_223 )
F_13 ( V_231 , 0 ) ;
}
static inline void F_44 ( unsigned V_192 )
{
F_12 ( V_232 , 1 ) ;
F_12 ( V_233 , 0 ) ;
if ( V_192 & V_221 )
F_13 ( V_85 , 0 ) ;
if ( V_192 & V_223 )
F_13 ( V_86 , 0 ) ;
}
void T_1 F_45 ( unsigned V_210 , unsigned V_234 , unsigned V_192 )
{
struct V_211 * V_212 ;
struct V_235 * V_18 ;
switch ( V_210 ) {
case 0 :
V_212 = & V_236 ;
F_40 () ;
break;
case V_237 :
V_212 = & V_238 ;
F_41 ( V_192 ) ;
break;
case V_239 :
V_212 = & V_240 ;
F_42 ( V_192 ) ;
break;
case V_241 :
V_212 = & V_242 ;
F_43 ( V_192 ) ;
break;
case V_243 :
V_212 = & V_244 ;
F_44 ( V_192 ) ;
break;
default:
return;
}
V_18 = V_212 -> V_60 . V_245 ;
V_18 -> V_246 = V_234 ;
if ( V_234 < V_247 )
V_248 [ V_234 ] = V_212 ;
}
void T_1 F_46 ( unsigned V_234 )
{
if ( V_234 < V_247 ) {
V_249 = V_248 [ V_234 ] ;
F_47 ( V_248 [ V_234 ] -> V_210 ) ;
}
}
void T_1 F_48 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_247 ; V_8 ++ ) {
if ( V_248 [ V_8 ] )
F_3 ( V_248 [ V_8 ] ) ;
}
if ( ! V_249 )
F_49 ( V_250 L_1 ) ;
}
void T_1 F_45 ( unsigned V_210 , unsigned V_234 , unsigned V_192 ) {}
void T_1 F_46 ( unsigned V_234 ) {}
void T_1 F_48 ( void ) {}
static int T_1 F_50 ( void )
{
F_1 () ;
F_31 () ;
F_33 () ;
F_34 () ;
F_35 () ;
F_30 () ;
return 0 ;
}
