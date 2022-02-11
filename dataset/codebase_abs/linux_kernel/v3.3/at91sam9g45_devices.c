void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
struct V_2 * V_3 =
F_3 ( NULL , L_1 ) ;
if ( V_3 )
F_4 ( V_3 ) ;
else
#endif
F_5 ( & V_4 ) ;
}
void T_1 F_1 ( void ) {}
void T_1 F_6 ( struct V_5 * V_6 )
{
int V_7 ;
if ( ! V_6 )
return;
for ( V_7 = 0 ; V_7 < V_6 -> V_8 ; V_7 ++ ) {
if ( F_7 ( V_6 -> V_9 [ V_7 ] ) )
F_8 ( V_6 -> V_9 [ V_7 ] , 0 ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_8 ; V_7 ++ ) {
if ( V_6 -> V_10 [ V_7 ] )
F_9 ( V_6 -> V_10 [ V_7 ] , 1 ) ;
}
V_11 = * V_6 ;
F_5 ( & V_12 ) ;
}
void T_1 F_6 ( struct V_5 * V_6 ) {}
void T_1 F_10 ( struct V_5 * V_6 )
{
int V_7 ;
if ( ! V_6 )
return;
for ( V_7 = 0 ; V_7 < V_6 -> V_8 ; V_7 ++ ) {
if ( F_7 ( V_6 -> V_9 [ V_7 ] ) )
F_8 ( V_6 -> V_9 [ V_7 ] , 0 ) ;
}
V_13 = * V_6 ;
F_5 ( & V_14 ) ;
}
void T_1 F_10 ( struct V_5 * V_6 ) {}
void T_1 F_11 ( struct V_15 * V_6 )
{
V_16 . V_17 . V_9 = - V_18 ;
V_16 . V_17 . V_19 = F_12 ( V_20 ) ;
memcpy ( V_16 . V_21 , V_20 , sizeof( V_20 ) ) ;
if ( V_6 && F_7 ( V_6 -> V_9 ) ) {
F_9 ( V_6 -> V_9 , 0 ) ;
F_13 ( V_6 -> V_9 , 1 ) ;
V_16 . V_17 . V_9 = V_6 -> V_9 ;
}
F_5 ( & V_22 ) ;
}
void T_1 F_11 ( struct V_15 * V_6 ) {}
void T_1 F_14 ( struct V_23 * V_6 )
{
if ( ! V_6 )
return;
if ( F_7 ( V_6 -> V_24 ) ) {
F_9 ( V_6 -> V_24 , 0 ) ;
F_13 ( V_6 -> V_24 , 1 ) ;
}
F_15 ( V_25 , 0 ) ;
F_15 ( V_26 , 0 ) ;
F_15 ( V_27 , 0 ) ;
F_15 ( V_28 , 0 ) ;
F_15 ( V_29 , 0 ) ;
F_15 ( V_30 , 0 ) ;
F_15 ( V_31 , 0 ) ;
F_15 ( V_32 , 0 ) ;
F_15 ( V_33 , 0 ) ;
F_15 ( V_34 , 0 ) ;
if ( ! V_6 -> V_35 ) {
F_16 ( V_36 , 0 ) ;
F_16 ( V_37 , 0 ) ;
F_16 ( V_38 , 0 ) ;
F_16 ( V_39 , 0 ) ;
F_16 ( V_40 , 0 ) ;
F_16 ( V_41 , 0 ) ;
F_16 ( V_42 , 0 ) ;
F_16 ( V_43 , 0 ) ;
}
V_44 = * V_6 ;
F_5 ( & V_45 ) ;
}
void T_1 F_14 ( struct V_23 * V_6 ) {}
void T_1 F_17 ( short V_46 , struct V_47 * V_6 )
{
if ( ! V_6 )
return;
if ( ! V_6 -> V_48 [ 0 ] . V_49 )
return;
#if F_2 ( V_50 ) || F_2 ( V_51 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
V_55 = F_18 ( sizeof( struct V_54 ) , V_56 ) ;
V_53 = & V_55 -> V_57 ;
V_53 -> V_58 = & V_4 . V_59 ;
V_53 -> V_60 = V_61 ;
V_53 -> V_62 = V_63
| V_64 | V_65 ;
V_53 -> V_66 = V_67 | V_68 ;
if ( V_46 == 0 )
V_53 -> V_62 |= F_19 ( V_69 )
| F_20 ( V_69 ) ;
else
V_53 -> V_62 |= F_19 ( V_70 )
| F_20 ( V_70 ) ;
V_6 -> V_71 = V_55 ;
}
#endif
if ( F_7 ( V_6 -> V_48 [ 0 ] . V_72 ) ) {
F_9 ( V_6 -> V_48 [ 0 ] . V_72 , 1 ) ;
F_13 ( V_6 -> V_48 [ 0 ] . V_72 , 1 ) ;
}
if ( F_7 ( V_6 -> V_48 [ 0 ] . V_73 ) )
F_9 ( V_6 -> V_48 [ 0 ] . V_73 , 1 ) ;
if ( V_46 == 0 ) {
F_15 ( V_74 , 0 ) ;
F_15 ( V_75 , 1 ) ;
F_15 ( V_76 , 1 ) ;
if ( V_6 -> V_48 [ 0 ] . V_49 == 4 ) {
F_15 ( V_77 , 1 ) ;
F_15 ( V_78 , 1 ) ;
F_15 ( V_79 , 1 ) ;
if ( V_6 -> V_48 [ 0 ] . V_49 == 8 ) {
F_15 ( V_41 , 1 ) ;
F_15 ( V_42 , 1 ) ;
F_15 ( V_38 , 1 ) ;
F_15 ( V_39 , 1 ) ;
}
}
V_80 = * V_6 ;
F_5 ( & V_81 ) ;
} else {
F_15 ( V_82 , 0 ) ;
F_15 ( V_83 , 1 ) ;
F_15 ( V_84 , 1 ) ;
if ( V_6 -> V_48 [ 0 ] . V_49 == 4 ) {
F_15 ( V_85 , 1 ) ;
F_15 ( V_86 , 1 ) ;
F_15 ( V_87 , 1 ) ;
if ( V_6 -> V_48 [ 0 ] . V_49 == 8 ) {
F_15 ( V_43 , 1 ) ;
F_15 ( V_40 , 1 ) ;
F_15 ( V_36 , 1 ) ;
F_15 ( V_37 , 1 ) ;
}
}
V_88 = * V_6 ;
F_5 ( & V_89 ) ;
}
}
void T_1 F_17 ( short V_46 , struct V_47 * V_6 ) {}
void T_1 F_21 ( struct V_90 * V_6 )
{
unsigned long V_91 ;
if ( ! V_6 )
return;
V_91 = F_22 ( V_92 ) ;
F_23 ( V_92 , V_91 | V_93 ) ;
if ( F_7 ( V_6 -> V_94 ) )
F_8 ( V_6 -> V_94 , 1 ) ;
if ( F_7 ( V_6 -> V_95 ) )
F_9 ( V_6 -> V_95 , 1 ) ;
if ( F_7 ( V_6 -> V_96 ) )
F_9 ( V_6 -> V_96 , 1 ) ;
V_97 = * V_6 ;
F_5 ( & V_98 ) ;
}
void T_1 F_21 ( struct V_90 * V_6 ) {}
void T_1 F_24 ( short V_99 , struct V_100 * V_101 , int V_102 )
{
F_25 ( V_99 , V_101 , V_102 ) ;
if ( V_99 == 0 ) {
F_26 ( V_103 , 1 ) ;
F_27 ( V_103 , 1 ) ;
F_26 ( V_104 , 1 ) ;
F_27 ( V_104 , 1 ) ;
F_5 ( & V_105 ) ;
} else {
F_26 ( V_106 , 1 ) ;
F_27 ( V_106 , 1 ) ;
F_26 ( V_107 , 1 ) ;
F_27 ( V_107 , 1 ) ;
F_5 ( & V_108 ) ;
}
}
void T_1 F_24 ( short V_99 , struct V_100 * V_101 , int V_102 )
{
F_25 ( V_99 , V_101 , V_102 ) ;
if ( V_99 == 0 ) {
F_15 ( V_103 , 0 ) ;
F_27 ( V_103 , 1 ) ;
F_15 ( V_104 , 0 ) ;
F_27 ( V_104 , 1 ) ;
F_5 ( & V_105 ) ;
} else {
F_15 ( V_106 , 0 ) ;
F_27 ( V_106 , 1 ) ;
F_15 ( V_107 , 0 ) ;
F_27 ( V_107 , 1 ) ;
F_5 ( & V_108 ) ;
}
}
void T_1 F_24 ( short V_99 , struct V_100 * V_101 , int V_102 ) {}
void T_1 F_28 ( struct V_109 * V_101 , int V_102 )
{
int V_7 ;
unsigned long V_110 ;
short V_111 = 0 ;
short V_112 = 0 ;
for ( V_7 = 0 ; V_7 < V_102 ; V_7 ++ ) {
if ( V_101 [ V_7 ] . V_113 )
V_110 = ( unsigned long ) V_101 [ V_7 ] . V_113 ;
else if ( V_101 [ V_7 ] . V_114 == 0 )
V_110 = V_115 [ V_101 [ V_7 ] . V_116 ] ;
else
V_110 = V_117 [ V_101 [ V_7 ] . V_116 ] ;
if ( V_101 [ V_7 ] . V_114 == 0 )
V_111 = 1 ;
else
V_112 = 1 ;
F_8 ( V_110 , 1 ) ;
V_101 [ V_7 ] . V_113 = ( void * ) V_110 ;
}
F_29 ( V_101 , V_102 ) ;
if ( V_111 ) {
F_15 ( V_118 , 0 ) ;
F_15 ( V_119 , 0 ) ;
F_15 ( V_120 , 0 ) ;
F_5 ( & V_121 ) ;
}
if ( V_112 ) {
F_15 ( V_122 , 0 ) ;
F_15 ( V_123 , 0 ) ;
F_15 ( V_124 , 0 ) ;
F_5 ( & V_125 ) ;
}
}
void T_1 F_28 ( struct V_109 * V_101 , int V_102 ) {}
void T_1 F_30 ( struct V_126 * V_6 )
{
if ( ! V_6 )
return;
F_15 ( V_127 , 0 ) ;
F_15 ( V_128 , 0 ) ;
F_15 ( V_129 , 0 ) ;
F_15 ( V_130 , 0 ) ;
if ( F_7 ( V_6 -> V_131 ) )
F_8 ( V_6 -> V_131 , 0 ) ;
V_132 = * V_6 ;
F_5 ( & V_133 ) ;
}
void T_1 F_30 ( struct V_126 * V_6 ) {}
void T_1 F_31 ( struct V_134 * V_6 )
{
if ( ! V_6 )
return;
F_15 ( V_135 , 0 ) ;
F_15 ( V_136 , 0 ) ;
F_15 ( V_137 , 0 ) ;
F_15 ( V_138 , 0 ) ;
F_15 ( V_139 , 0 ) ;
F_15 ( V_140 , 0 ) ;
F_15 ( V_141 , 0 ) ;
F_15 ( V_142 , 0 ) ;
F_15 ( V_143 , 0 ) ;
F_15 ( V_144 , 0 ) ;
F_15 ( V_145 , 0 ) ;
F_15 ( V_146 , 0 ) ;
F_15 ( V_147 , 0 ) ;
F_15 ( V_148 , 0 ) ;
F_15 ( V_149 , 0 ) ;
F_15 ( V_150 , 0 ) ;
F_15 ( V_151 , 0 ) ;
F_15 ( V_152 , 0 ) ;
F_15 ( V_153 , 0 ) ;
F_15 ( V_154 , 0 ) ;
F_15 ( V_155 , 0 ) ;
F_15 ( V_156 , 0 ) ;
F_15 ( V_157 , 0 ) ;
F_15 ( V_158 , 0 ) ;
F_15 ( V_159 , 0 ) ;
F_15 ( V_160 , 0 ) ;
F_15 ( V_161 , 0 ) ;
F_15 ( V_162 , 0 ) ;
F_15 ( V_163 , 0 ) ;
F_15 ( V_164 , 0 ) ;
V_165 = * V_6 ;
F_5 ( & V_166 ) ;
}
void T_1 F_31 ( struct V_134 * V_6 ) {}
static void T_1 F_32 ( void )
{
F_5 ( & V_167 ) ;
F_5 ( & V_168 ) ;
}
static void T_1 F_32 ( void ) { }
static void T_1 F_33 ( void )
{
F_5 ( & V_169 ) ;
}
static void T_1 F_33 ( void ) {}
void T_1 F_34 ( struct V_170 * V_6 )
{
if ( ! V_6 )
return;
F_9 ( V_171 , 0 ) ;
F_9 ( V_172 , 0 ) ;
F_9 ( V_173 , 0 ) ;
F_9 ( V_174 , 0 ) ;
V_175 = * V_6 ;
F_5 ( & V_176 ) ;
}
void T_1 F_34 ( struct V_170 * V_6 ) {}
static void T_1 F_35 ( void )
{
F_5 ( & V_177 ) ;
}
static void T_1 F_36 ( void )
{
F_5 ( & V_178 ) ;
}
static void T_1 F_36 ( void ) {}
static void T_1 F_37 ( void )
{
F_5 ( & V_179 ) ;
}
static void T_1 F_37 ( void ) {}
void T_1 F_38 ( T_2 V_180 )
{
if ( V_180 & ( 1 << V_181 ) )
F_16 ( V_182 , 1 ) ;
if ( V_180 & ( 1 << V_183 ) )
F_16 ( V_184 , 1 ) ;
if ( V_180 & ( 1 << V_185 ) )
F_16 ( V_186 , 1 ) ;
if ( V_180 & ( 1 << V_187 ) )
F_16 ( V_188 , 1 ) ;
V_189 = V_180 ;
F_5 ( & V_190 ) ;
}
void T_1 F_38 ( T_2 V_180 ) {}
static inline void F_39 ( unsigned V_191 )
{
if ( V_191 & V_192 )
F_15 ( V_193 , 1 ) ;
if ( V_191 & V_194 )
F_15 ( V_188 , 1 ) ;
if ( V_191 & V_195 )
F_15 ( V_196 , 1 ) ;
if ( V_191 & V_197 )
F_15 ( V_198 , 1 ) ;
if ( V_191 & V_199 )
F_15 ( V_200 , 1 ) ;
if ( V_191 & V_201 )
F_15 ( V_202 , 1 ) ;
}
static inline void F_40 ( unsigned V_191 )
{
if ( V_191 & V_192 )
F_15 ( V_203 , 1 ) ;
if ( V_191 & V_194 )
F_15 ( V_204 , 1 ) ;
if ( V_191 & V_195 )
F_15 ( V_205 , 1 ) ;
if ( V_191 & V_197 )
F_15 ( V_206 , 1 ) ;
if ( V_191 & V_199 )
F_15 ( V_207 , 1 ) ;
if ( V_191 & V_201 )
F_15 ( V_208 , 1 ) ;
}
void T_1 F_41 ( unsigned V_209 , unsigned V_191 )
{
struct V_210 * V_211 ;
switch ( V_209 ) {
case V_212 :
V_211 = & V_213 ;
F_39 ( V_191 ) ;
break;
case V_214 :
V_211 = & V_215 ;
F_40 ( V_191 ) ;
break;
default:
return;
}
F_5 ( V_211 ) ;
}
void T_1 F_41 ( unsigned V_209 , unsigned V_191 ) {}
static inline void F_42 ( void )
{
F_15 ( V_216 , 0 ) ;
F_15 ( V_217 , 1 ) ;
}
static inline void F_43 ( unsigned V_191 )
{
F_15 ( V_218 , 1 ) ;
F_15 ( V_219 , 0 ) ;
if ( V_191 & V_220 )
F_16 ( V_221 , 0 ) ;
if ( V_191 & V_222 )
F_16 ( V_123 , 0 ) ;
}
static inline void F_44 ( unsigned V_191 )
{
F_15 ( V_223 , 1 ) ;
F_15 ( V_224 , 0 ) ;
if ( V_191 & V_220 )
F_15 ( V_225 , 0 ) ;
if ( V_191 & V_222 )
F_15 ( V_226 , 0 ) ;
}
static inline void F_45 ( unsigned V_191 )
{
F_15 ( V_227 , 1 ) ;
F_15 ( V_228 , 0 ) ;
if ( V_191 & V_220 )
F_16 ( V_229 , 0 ) ;
if ( V_191 & V_222 )
F_16 ( V_230 , 0 ) ;
}
static inline void F_46 ( unsigned V_191 )
{
F_15 ( V_231 , 1 ) ;
F_15 ( V_232 , 0 ) ;
if ( V_191 & V_220 )
F_16 ( V_84 , 0 ) ;
if ( V_191 & V_222 )
F_16 ( V_85 , 0 ) ;
}
void T_1 F_47 ( unsigned V_209 , unsigned V_233 , unsigned V_191 )
{
struct V_210 * V_211 ;
struct V_234 * V_17 ;
switch ( V_209 ) {
case 0 :
V_211 = & V_235 ;
F_42 () ;
break;
case V_236 :
V_211 = & V_237 ;
F_43 ( V_191 ) ;
break;
case V_238 :
V_211 = & V_239 ;
F_44 ( V_191 ) ;
break;
case V_240 :
V_211 = & V_241 ;
F_45 ( V_191 ) ;
break;
case V_242 :
V_211 = & V_243 ;
F_46 ( V_191 ) ;
break;
default:
return;
}
V_17 = V_211 -> V_59 . V_244 ;
V_17 -> V_245 = V_233 ;
if ( V_233 < V_246 )
V_247 [ V_233 ] = V_211 ;
}
void T_1 F_48 ( unsigned V_233 )
{
if ( V_233 < V_246 ) {
V_248 = V_247 [ V_233 ] ;
F_49 ( V_247 [ V_233 ] -> V_209 ) ;
}
}
void T_1 F_50 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_246 ; V_7 ++ ) {
if ( V_247 [ V_7 ] )
F_5 ( V_247 [ V_7 ] ) ;
}
if ( ! V_248 )
F_51 ( V_249 L_2 ) ;
}
void T_1 F_47 ( unsigned V_209 , unsigned V_233 , unsigned V_191 ) {}
void T_1 F_48 ( unsigned V_233 ) {}
void T_1 F_50 ( void ) {}
static int T_1 F_52 ( void )
{
F_1 () ;
F_33 () ;
F_35 () ;
F_36 () ;
F_37 () ;
F_32 () ;
return 0 ;
}
