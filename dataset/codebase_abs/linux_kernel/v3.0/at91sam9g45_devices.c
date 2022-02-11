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
V_11 = * V_7 ;
F_3 ( & V_12 ) ;
}
void T_1 F_4 ( struct V_6 * V_7 ) {}
void T_1 F_6 ( struct V_6 * V_7 )
{
int V_8 ;
if ( ! V_7 )
return;
for ( V_8 = 0 ; V_8 < V_7 -> V_9 ; V_8 ++ ) {
if ( V_7 -> V_10 [ V_8 ] )
F_5 ( V_7 -> V_10 [ V_8 ] , 0 ) ;
}
V_13 = * V_7 ;
F_3 ( & V_14 ) ;
}
void T_1 F_6 ( struct V_6 * V_7 ) {}
void T_1 F_7 ( struct V_15 * V_7 )
{
V_16 . V_17 . V_10 = - V_18 ;
V_16 . V_17 . V_19 = F_8 ( V_20 ) ;
memcpy ( V_16 . V_21 , V_20 , sizeof( V_20 ) ) ;
if ( V_7 && V_7 -> V_10 > 0 ) {
F_9 ( V_7 -> V_10 , 0 ) ;
F_10 ( V_7 -> V_10 , 1 ) ;
V_16 . V_17 . V_10 = V_7 -> V_10 ;
}
F_3 ( & V_22 ) ;
}
void T_1 F_7 ( struct V_15 * V_7 ) {}
void T_1 F_11 ( struct V_23 * V_7 )
{
if ( ! V_7 )
return;
if ( V_7 -> V_24 ) {
F_9 ( V_7 -> V_24 , 0 ) ;
F_10 ( V_7 -> V_24 , 1 ) ;
}
F_12 ( V_25 , 0 ) ;
F_12 ( V_26 , 0 ) ;
F_12 ( V_27 , 0 ) ;
F_12 ( V_28 , 0 ) ;
F_12 ( V_29 , 0 ) ;
F_12 ( V_30 , 0 ) ;
F_12 ( V_31 , 0 ) ;
F_12 ( V_32 , 0 ) ;
F_12 ( V_33 , 0 ) ;
F_12 ( V_34 , 0 ) ;
if ( ! V_7 -> V_35 ) {
F_13 ( V_36 , 0 ) ;
F_13 ( V_37 , 0 ) ;
F_13 ( V_38 , 0 ) ;
F_13 ( V_39 , 0 ) ;
F_13 ( V_40 , 0 ) ;
F_13 ( V_41 , 0 ) ;
F_13 ( V_42 , 0 ) ;
F_13 ( V_43 , 0 ) ;
}
V_44 = * V_7 ;
F_3 ( & V_45 ) ;
}
void T_1 F_11 ( struct V_23 * V_7 ) {}
void T_1 F_14 ( short V_46 , struct V_47 * V_7 )
{
if ( ! V_7 )
return;
if ( ! V_7 -> V_48 [ 0 ] . V_49 )
return;
#if F_15 ( V_50 ) || F_15 ( V_51 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
V_55 = F_16 ( sizeof( struct V_54 ) , V_56 ) ;
V_53 = & V_55 -> V_57 ;
V_53 -> V_58 = & V_5 . V_59 ;
V_53 -> V_60 = V_61 ;
V_53 -> V_62 = V_63
| V_64 | V_65 ;
V_53 -> V_66 = V_67 | V_68 ;
if ( V_46 == 0 )
V_53 -> V_62 |= F_17 ( V_69 )
| F_18 ( V_69 ) ;
else
V_53 -> V_62 |= F_17 ( V_70 )
| F_18 ( V_70 ) ;
V_7 -> V_71 = V_55 ;
}
#endif
if ( V_7 -> V_48 [ 0 ] . V_72 ) {
F_9 ( V_7 -> V_48 [ 0 ] . V_72 , 1 ) ;
F_10 ( V_7 -> V_48 [ 0 ] . V_72 , 1 ) ;
}
if ( V_7 -> V_48 [ 0 ] . V_73 )
F_9 ( V_7 -> V_48 [ 0 ] . V_73 , 1 ) ;
if ( V_46 == 0 ) {
F_12 ( V_74 , 0 ) ;
F_12 ( V_75 , 1 ) ;
F_12 ( V_76 , 1 ) ;
if ( V_7 -> V_48 [ 0 ] . V_49 == 4 ) {
F_12 ( V_77 , 1 ) ;
F_12 ( V_78 , 1 ) ;
F_12 ( V_79 , 1 ) ;
if ( V_7 -> V_48 [ 0 ] . V_49 == 8 ) {
F_12 ( V_41 , 1 ) ;
F_12 ( V_42 , 1 ) ;
F_12 ( V_38 , 1 ) ;
F_12 ( V_39 , 1 ) ;
}
}
V_80 = * V_7 ;
F_3 ( & V_81 ) ;
} else {
F_12 ( V_82 , 0 ) ;
F_12 ( V_83 , 1 ) ;
F_12 ( V_84 , 1 ) ;
if ( V_7 -> V_48 [ 0 ] . V_49 == 4 ) {
F_12 ( V_85 , 1 ) ;
F_12 ( V_86 , 1 ) ;
F_12 ( V_87 , 1 ) ;
if ( V_7 -> V_48 [ 0 ] . V_49 == 8 ) {
F_12 ( V_43 , 1 ) ;
F_12 ( V_40 , 1 ) ;
F_12 ( V_36 , 1 ) ;
F_12 ( V_37 , 1 ) ;
}
}
V_88 = * V_7 ;
F_3 ( & V_89 ) ;
}
}
void T_1 F_14 ( short V_46 , struct V_47 * V_7 ) {}
void T_1 F_19 ( struct V_90 * V_7 )
{
unsigned long V_91 ;
if ( ! V_7 )
return;
V_91 = F_20 ( V_92 ) ;
F_21 ( V_92 , V_91 | V_93 ) ;
if ( V_7 -> V_94 )
F_5 ( V_7 -> V_94 , 1 ) ;
if ( V_7 -> V_95 )
F_9 ( V_7 -> V_95 , 1 ) ;
if ( V_7 -> V_96 )
F_9 ( V_7 -> V_96 , 1 ) ;
V_97 = * V_7 ;
F_3 ( & V_98 ) ;
}
void T_1 F_19 ( struct V_90 * V_7 ) {}
void T_1 F_22 ( short V_99 , struct V_100 * V_101 , int V_102 )
{
F_23 ( V_99 , V_101 , V_102 ) ;
if ( V_99 == 0 ) {
F_24 ( V_103 , 1 ) ;
F_25 ( V_103 , 1 ) ;
F_24 ( V_104 , 1 ) ;
F_25 ( V_104 , 1 ) ;
F_3 ( & V_105 ) ;
} else {
F_24 ( V_106 , 1 ) ;
F_25 ( V_106 , 1 ) ;
F_24 ( V_107 , 1 ) ;
F_25 ( V_107 , 1 ) ;
F_3 ( & V_108 ) ;
}
}
void T_1 F_22 ( short V_99 , struct V_100 * V_101 , int V_102 )
{
F_23 ( V_99 , V_101 , V_102 ) ;
if ( V_99 == 0 ) {
F_12 ( V_103 , 0 ) ;
F_25 ( V_103 , 1 ) ;
F_12 ( V_104 , 0 ) ;
F_25 ( V_104 , 1 ) ;
F_3 ( & V_105 ) ;
} else {
F_12 ( V_106 , 0 ) ;
F_25 ( V_106 , 1 ) ;
F_12 ( V_107 , 0 ) ;
F_25 ( V_107 , 1 ) ;
F_3 ( & V_108 ) ;
}
}
void T_1 F_22 ( short V_99 , struct V_100 * V_101 , int V_102 ) {}
void T_1 F_26 ( struct V_109 * V_101 , int V_102 )
{
int V_8 ;
unsigned long V_110 ;
short V_111 = 0 ;
short V_112 = 0 ;
for ( V_8 = 0 ; V_8 < V_102 ; V_8 ++ ) {
if ( V_101 [ V_8 ] . V_113 )
V_110 = ( unsigned long ) V_101 [ V_8 ] . V_113 ;
else if ( V_101 [ V_8 ] . V_114 == 0 )
V_110 = V_115 [ V_101 [ V_8 ] . V_116 ] ;
else
V_110 = V_117 [ V_101 [ V_8 ] . V_116 ] ;
if ( V_101 [ V_8 ] . V_114 == 0 )
V_111 = 1 ;
else
V_112 = 1 ;
F_5 ( V_110 , 1 ) ;
V_101 [ V_8 ] . V_113 = ( void * ) V_110 ;
}
F_27 ( V_101 , V_102 ) ;
if ( V_111 ) {
F_12 ( V_118 , 0 ) ;
F_12 ( V_119 , 0 ) ;
F_12 ( V_120 , 0 ) ;
F_3 ( & V_121 ) ;
}
if ( V_112 ) {
F_12 ( V_122 , 0 ) ;
F_12 ( V_123 , 0 ) ;
F_12 ( V_124 , 0 ) ;
F_3 ( & V_125 ) ;
}
}
void T_1 F_26 ( struct V_109 * V_101 , int V_102 ) {}
void T_1 F_28 ( struct V_126 * V_7 )
{
if ( ! V_7 )
return;
F_12 ( V_127 , 0 ) ;
F_12 ( V_128 , 0 ) ;
F_12 ( V_129 , 0 ) ;
F_12 ( V_130 , 0 ) ;
if ( V_7 -> V_131 )
F_5 ( V_7 -> V_131 , 0 ) ;
V_132 = * V_7 ;
F_3 ( & V_133 ) ;
}
void T_1 F_28 ( struct V_126 * V_7 ) {}
void T_1 F_29 ( struct V_134 * V_7 )
{
if ( ! V_7 )
return;
F_12 ( V_135 , 0 ) ;
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
V_165 = * V_7 ;
F_3 ( & V_166 ) ;
}
void T_1 F_29 ( struct V_134 * V_7 ) {}
static void T_1 F_30 ( void )
{
F_3 ( & V_167 ) ;
F_3 ( & V_168 ) ;
}
static void T_1 F_30 ( void ) { }
static void T_1 F_31 ( void )
{
F_3 ( & V_169 ) ;
}
static void T_1 F_31 ( void ) {}
void T_1 F_32 ( struct V_170 * V_7 )
{
if ( ! V_7 )
return;
F_9 ( V_171 , 0 ) ;
F_9 ( V_172 , 0 ) ;
F_9 ( V_173 , 0 ) ;
F_9 ( V_174 , 0 ) ;
V_175 = * V_7 ;
F_3 ( & V_176 ) ;
}
void T_1 F_32 ( struct V_170 * V_7 ) {}
static void T_1 F_33 ( void )
{
F_3 ( & V_177 ) ;
}
static void T_1 F_34 ( void )
{
F_3 ( & V_178 ) ;
}
static void T_1 F_34 ( void ) {}
void T_1 F_35 ( T_2 V_179 )
{
if ( V_179 & ( 1 << V_180 ) )
F_13 ( V_181 , 1 ) ;
if ( V_179 & ( 1 << V_182 ) )
F_13 ( V_183 , 1 ) ;
if ( V_179 & ( 1 << V_184 ) )
F_13 ( V_185 , 1 ) ;
if ( V_179 & ( 1 << V_186 ) )
F_13 ( V_187 , 1 ) ;
V_188 = V_179 ;
F_3 ( & V_189 ) ;
}
void T_1 F_35 ( T_2 V_179 ) {}
static inline void F_36 ( unsigned V_190 )
{
if ( V_190 & V_191 )
F_12 ( V_192 , 1 ) ;
if ( V_190 & V_193 )
F_12 ( V_187 , 1 ) ;
if ( V_190 & V_194 )
F_12 ( V_195 , 1 ) ;
if ( V_190 & V_196 )
F_12 ( V_197 , 1 ) ;
if ( V_190 & V_198 )
F_12 ( V_199 , 1 ) ;
if ( V_190 & V_200 )
F_12 ( V_201 , 1 ) ;
}
static inline void F_37 ( unsigned V_190 )
{
if ( V_190 & V_191 )
F_12 ( V_202 , 1 ) ;
if ( V_190 & V_193 )
F_12 ( V_203 , 1 ) ;
if ( V_190 & V_194 )
F_12 ( V_204 , 1 ) ;
if ( V_190 & V_196 )
F_12 ( V_205 , 1 ) ;
if ( V_190 & V_198 )
F_12 ( V_206 , 1 ) ;
if ( V_190 & V_200 )
F_12 ( V_207 , 1 ) ;
}
void T_1 F_38 ( unsigned V_208 , unsigned V_190 )
{
struct V_209 * V_210 ;
switch ( V_208 ) {
case V_211 :
V_210 = & V_212 ;
F_36 ( V_190 ) ;
break;
case V_213 :
V_210 = & V_214 ;
F_37 ( V_190 ) ;
break;
default:
return;
}
F_3 ( V_210 ) ;
}
void T_1 F_38 ( unsigned V_208 , unsigned V_190 ) {}
static inline void F_39 ( void )
{
F_12 ( V_215 , 0 ) ;
F_12 ( V_216 , 1 ) ;
}
static inline void F_40 ( unsigned V_190 )
{
F_12 ( V_217 , 1 ) ;
F_12 ( V_218 , 0 ) ;
if ( V_190 & V_219 )
F_13 ( V_220 , 0 ) ;
if ( V_190 & V_221 )
F_13 ( V_123 , 0 ) ;
}
static inline void F_41 ( unsigned V_190 )
{
F_12 ( V_222 , 1 ) ;
F_12 ( V_223 , 0 ) ;
if ( V_190 & V_219 )
F_12 ( V_224 , 0 ) ;
if ( V_190 & V_221 )
F_12 ( V_225 , 0 ) ;
}
static inline void F_42 ( unsigned V_190 )
{
F_12 ( V_226 , 1 ) ;
F_12 ( V_227 , 0 ) ;
if ( V_190 & V_219 )
F_13 ( V_228 , 0 ) ;
if ( V_190 & V_221 )
F_13 ( V_229 , 0 ) ;
}
static inline void F_43 ( unsigned V_190 )
{
F_12 ( V_230 , 1 ) ;
F_12 ( V_231 , 0 ) ;
if ( V_190 & V_219 )
F_13 ( V_84 , 0 ) ;
if ( V_190 & V_221 )
F_13 ( V_85 , 0 ) ;
}
void T_1 F_44 ( unsigned V_208 , unsigned V_232 , unsigned V_190 )
{
struct V_209 * V_210 ;
struct V_233 * V_17 ;
switch ( V_208 ) {
case 0 :
V_210 = & V_234 ;
F_39 () ;
break;
case V_235 :
V_210 = & V_236 ;
F_40 ( V_190 ) ;
break;
case V_237 :
V_210 = & V_238 ;
F_41 ( V_190 ) ;
break;
case V_239 :
V_210 = & V_240 ;
F_42 ( V_190 ) ;
break;
case V_241 :
V_210 = & V_242 ;
F_43 ( V_190 ) ;
break;
default:
return;
}
V_17 = V_210 -> V_59 . V_243 ;
V_17 -> V_244 = V_232 ;
if ( V_232 < V_245 )
V_246 [ V_232 ] = V_210 ;
}
void T_1 F_45 ( unsigned V_232 )
{
if ( V_232 < V_245 ) {
V_247 = V_246 [ V_232 ] ;
F_46 ( V_246 [ V_232 ] -> V_208 ) ;
}
}
void T_1 F_47 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_245 ; V_8 ++ ) {
if ( V_246 [ V_8 ] )
F_3 ( V_246 [ V_8 ] ) ;
}
if ( ! V_247 )
F_48 ( V_248 L_1 ) ;
}
void T_1 F_44 ( unsigned V_208 , unsigned V_232 , unsigned V_190 ) {}
void T_1 F_45 ( unsigned V_232 ) {}
void T_1 F_47 ( void ) {}
static int T_1 F_49 ( void )
{
F_1 () ;
F_31 () ;
F_33 () ;
F_34 () ;
F_30 () ;
return 0 ;
}
