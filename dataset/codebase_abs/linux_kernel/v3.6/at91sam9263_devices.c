void T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
if ( F_2 ( V_2 -> V_5 [ V_3 ] ) )
F_3 ( V_2 -> V_5 [ V_3 ] ,
V_2 -> V_6 [ V_3 ] ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
if ( V_2 -> V_7 [ V_3 ] )
F_4 ( V_2 -> V_7 [ V_3 ] , 1 ) ;
}
V_8 = * V_2 ;
F_5 ( & V_9 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 ) {}
void T_1 F_6 ( struct V_10 * V_2 )
{
if ( ! V_2 )
return;
if ( F_2 ( V_2 -> V_5 ) ) {
F_4 ( V_2 -> V_5 , 0 ) ;
F_7 ( V_2 -> V_5 , 1 ) ;
}
V_11 = * V_2 ;
F_5 ( & V_12 ) ;
}
void T_1 F_6 ( struct V_10 * V_2 ) {}
void T_1 F_8 ( struct V_13 * V_2 )
{
if ( ! V_2 )
return;
if ( F_2 ( V_2 -> V_14 ) ) {
F_4 ( V_2 -> V_14 , 0 ) ;
F_7 ( V_2 -> V_14 , 1 ) ;
}
F_9 ( V_15 , 0 ) ;
F_10 ( V_16 , 0 ) ;
F_9 ( V_17 , 0 ) ;
F_9 ( V_18 , 0 ) ;
F_9 ( V_19 , 0 ) ;
F_9 ( V_20 , 0 ) ;
F_9 ( V_21 , 0 ) ;
F_9 ( V_22 , 0 ) ;
F_9 ( V_23 , 0 ) ;
F_9 ( V_24 , 0 ) ;
if ( ! V_2 -> V_25 ) {
F_9 ( V_26 , 0 ) ;
F_10 ( V_27 , 0 ) ;
F_10 ( V_28 , 0 ) ;
F_10 ( V_29 , 0 ) ;
F_10 ( V_30 , 0 ) ;
F_10 ( V_31 , 0 ) ;
F_10 ( V_32 , 0 ) ;
F_10 ( V_33 , 0 ) ;
}
V_34 = * V_2 ;
F_5 ( & V_35 ) ;
}
void T_1 F_8 ( struct V_13 * V_2 ) {}
void T_1 F_11 ( short V_36 , struct V_37 * V_2 )
{
if ( ! V_2 )
return;
if ( F_2 ( V_2 -> V_38 ) ) {
F_4 ( V_2 -> V_38 , 1 ) ;
F_7 ( V_2 -> V_38 , 1 ) ;
}
if ( F_2 ( V_2 -> V_39 ) )
F_4 ( V_2 -> V_39 , 1 ) ;
if ( F_2 ( V_2 -> V_40 ) )
F_3 ( V_2 -> V_40 , 0 ) ;
if ( V_36 == 0 ) {
F_9 ( V_41 , 0 ) ;
if ( V_2 -> V_42 ) {
F_9 ( V_43 , 1 ) ;
F_9 ( V_44 , 1 ) ;
if ( V_2 -> V_45 ) {
F_9 ( V_46 , 1 ) ;
F_9 ( V_47 , 1 ) ;
F_9 ( V_48 , 1 ) ;
}
} else {
F_9 ( V_49 , 1 ) ;
F_9 ( V_50 , 1 ) ;
if ( V_2 -> V_45 ) {
F_9 ( V_51 , 1 ) ;
F_9 ( V_52 , 1 ) ;
F_9 ( V_53 , 1 ) ;
}
}
V_54 = * V_2 ;
F_5 ( & V_55 ) ;
} else {
F_9 ( V_56 , 0 ) ;
if ( V_2 -> V_42 ) {
F_9 ( V_57 , 1 ) ;
F_9 ( V_58 , 1 ) ;
if ( V_2 -> V_45 ) {
F_9 ( V_59 , 1 ) ;
F_9 ( V_60 , 1 ) ;
F_9 ( V_61 , 1 ) ;
}
} else {
F_9 ( V_62 , 1 ) ;
F_9 ( V_63 , 1 ) ;
if ( V_2 -> V_45 ) {
F_9 ( V_64 , 1 ) ;
F_9 ( V_65 , 1 ) ;
F_9 ( V_66 , 1 ) ;
}
}
V_67 = * V_2 ;
F_5 ( & V_68 ) ;
}
}
void T_1 F_11 ( short V_36 , struct V_37 * V_2 ) {}
void T_1 F_12 ( struct V_69 * V_2 )
{
unsigned long V_70 ;
struct V_71 * V_72 ;
if ( ! V_2 )
return;
V_70 = F_13 ( V_73 ) ;
switch ( V_2 -> V_74 ) {
case 4 :
F_9 ( V_75 , 0 ) ;
V_70 |= V_76 ;
V_77 = * V_2 ;
V_72 = & V_78 ;
break;
case 5 :
F_9 ( V_79 , 0 ) ;
V_70 |= V_80 ;
V_81 = * V_2 ;
V_72 = & V_82 ;
break;
default:
F_14 ( V_83 L_1 ,
V_2 -> V_74 ) ;
return;
}
F_15 ( V_73 , V_70 ) ;
if ( F_2 ( V_2 -> V_38 ) ) {
F_4 ( V_2 -> V_38 , 1 ) ;
F_7 ( V_2 -> V_38 , 1 ) ;
}
if ( F_2 ( V_2 -> V_84 ) ) {
F_4 ( V_2 -> V_84 , 1 ) ;
F_7 ( V_2 -> V_84 , 1 ) ;
}
if ( F_2 ( V_2 -> V_40 ) )
F_3 ( V_2 -> V_40 , 0 ) ;
F_9 ( V_85 , 1 ) ;
F_9 ( V_86 , 0 ) ;
F_9 ( V_87 , 0 ) ;
F_9 ( V_88 , 0 ) ;
V_72 -> V_89 = ( V_2 -> V_90 & V_91 ) ? L_2 : L_3 ;
F_5 ( V_72 ) ;
}
void T_1 F_12 ( struct V_69 * V_2 ) {}
void T_1 F_16 ( struct V_92 * V_2 )
{
unsigned long V_93 ;
if ( ! V_2 )
return;
V_93 = F_13 ( V_73 ) ;
F_15 ( V_73 , V_93 | V_94 ) ;
if ( F_2 ( V_2 -> V_95 ) )
F_3 ( V_2 -> V_95 , 1 ) ;
if ( F_2 ( V_2 -> V_96 ) )
F_4 ( V_2 -> V_96 , 1 ) ;
if ( F_2 ( V_2 -> V_38 ) )
F_4 ( V_2 -> V_38 , 1 ) ;
V_97 = * V_2 ;
F_5 ( & V_98 ) ;
}
void T_1 F_16 ( struct V_92 * V_2 ) {}
void T_1 F_17 ( struct V_99 * V_100 , int V_101 )
{
F_18 ( V_102 , 1 ) ;
F_19 ( V_102 , 1 ) ;
F_18 ( V_103 , 1 ) ;
F_19 ( V_103 , 1 ) ;
F_20 ( 0 , V_100 , V_101 ) ;
F_5 ( & V_104 ) ;
}
void T_1 F_17 ( struct V_99 * V_100 , int V_101 )
{
F_9 ( V_102 , 0 ) ;
F_19 ( V_102 , 1 ) ;
F_9 ( V_103 , 0 ) ;
F_19 ( V_103 , 1 ) ;
F_20 ( 0 , V_100 , V_101 ) ;
F_5 ( & V_104 ) ;
}
void T_1 F_17 ( struct V_99 * V_100 , int V_101 ) {}
void T_1 F_21 ( struct V_105 * V_100 , int V_101 )
{
int V_3 ;
unsigned long V_106 ;
short V_107 = 0 ;
short V_108 = 0 ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ ) {
if ( V_100 [ V_3 ] . V_109 )
V_106 = ( unsigned long ) V_100 [ V_3 ] . V_109 ;
else if ( V_100 [ V_3 ] . V_110 == 0 )
V_106 = V_111 [ V_100 [ V_3 ] . V_112 ] ;
else
V_106 = V_113 [ V_100 [ V_3 ] . V_112 ] ;
if ( ! F_2 ( V_106 ) )
continue;
if ( V_100 [ V_3 ] . V_110 == 0 )
V_107 = 1 ;
else
V_108 = 1 ;
F_3 ( V_106 , 1 ) ;
V_100 [ V_3 ] . V_109 = ( void * ) V_106 ;
}
F_22 ( V_100 , V_101 ) ;
if ( V_107 ) {
F_10 ( V_50 , 0 ) ;
F_10 ( V_49 , 0 ) ;
F_10 ( V_114 , 0 ) ;
F_5 ( & V_115 ) ;
}
if ( V_108 ) {
F_9 ( V_116 , 0 ) ;
F_9 ( V_117 , 0 ) ;
F_9 ( V_118 , 0 ) ;
F_5 ( & V_119 ) ;
}
}
void T_1 F_21 ( struct V_105 * V_100 , int V_101 ) {}
void T_1 F_23 ( struct V_120 * V_2 )
{
if ( ! V_2 )
return;
F_9 ( V_121 , 0 ) ;
F_9 ( V_122 , 0 ) ;
F_9 ( V_123 , 0 ) ;
F_9 ( V_124 , 0 ) ;
if ( F_2 ( V_2 -> V_125 ) )
F_3 ( V_2 -> V_125 , 0 ) ;
V_126 = * V_2 ;
F_5 ( & V_127 ) ;
}
void T_1 F_23 ( struct V_120 * V_2 ) {}
void T_1 F_24 ( struct V_128 * V_2 )
{
F_9 ( V_129 , 0 ) ;
F_9 ( V_130 , 0 ) ;
V_131 . V_132 . V_133 = V_2 ;
F_5 ( & V_131 ) ;
}
void T_1 F_24 ( struct V_128 * V_2 ) {}
void T_1 F_25 ( struct V_134 * V_2 )
{
if ( ! V_2 )
return;
F_9 ( V_135 , 0 ) ;
F_9 ( V_136 , 0 ) ;
F_9 ( V_137 , 0 ) ;
F_10 ( V_138 , 0 ) ;
F_9 ( V_139 , 0 ) ;
F_9 ( V_140 , 0 ) ;
F_9 ( V_141 , 0 ) ;
F_9 ( V_142 , 0 ) ;
F_9 ( V_143 , 0 ) ;
F_9 ( V_144 , 0 ) ;
F_9 ( V_145 , 0 ) ;
F_9 ( V_146 , 0 ) ;
F_9 ( V_147 , 0 ) ;
F_10 ( V_148 , 0 ) ;
F_9 ( V_149 , 0 ) ;
F_9 ( V_150 , 0 ) ;
F_9 ( V_28 , 0 ) ;
F_9 ( V_29 , 0 ) ;
F_9 ( V_33 , 0 ) ;
F_10 ( V_151 , 0 ) ;
F_9 ( V_27 , 0 ) ;
F_9 ( V_30 , 0 ) ;
V_152 = * V_2 ;
F_5 ( & V_153 ) ;
}
void T_1 F_25 ( struct V_134 * V_2 ) {}
void T_1 F_26 ( struct V_154 * V_2 ,
bool V_155 )
{
F_9 ( V_156 , 0 ) ;
F_9 ( V_157 , 0 ) ;
F_9 ( V_158 , 0 ) ;
F_9 ( V_159 , 0 ) ;
F_9 ( V_160 , 0 ) ;
F_9 ( V_161 , 0 ) ;
F_9 ( V_162 , 0 ) ;
F_9 ( V_163 , 0 ) ;
F_9 ( V_164 , 0 ) ;
F_9 ( V_165 , 0 ) ;
F_9 ( V_166 , 0 ) ;
F_10 ( V_167 , 0 ) ;
F_10 ( V_168 , 0 ) ;
F_10 ( V_169 , 0 ) ;
F_10 ( V_170 , 0 ) ;
if ( V_155 ) {
F_10 ( V_171 , 0 ) ;
}
}
void T_1 F_26 ( struct V_154 * V_2 ,
bool V_155 ) {}
static void T_1 F_27 ( void )
{
#if F_28 ( V_172 )
struct V_173 * V_174 ;
V_174 = F_29 ( NULL , V_175 ) ;
if ( V_174 ) {
F_30 ( V_174 ) ;
return;
}
#endif
F_5 ( & V_176 ) ;
}
static void T_1 F_27 ( void ) { }
static void T_1 F_31 ( void )
{
struct V_71 * V_72 ;
struct V_177 * V_178 ;
switch ( V_179 ) {
case 0 :
V_180 . V_181 = 3 ;
V_182 . V_181 = 1 ;
V_72 = & V_180 ;
V_178 = V_183 ;
break;
case 1 :
V_180 . V_181 = 1 ;
V_182 . V_181 = 3 ;
V_72 = & V_182 ;
V_178 = V_184 ;
break;
default:
F_32 ( L_4 ,
V_179 ) ;
return;
}
V_72 -> V_89 = L_5 ;
V_178 [ 1 ] . V_185 = V_186 + 4 * V_187 ;
V_178 [ 1 ] . V_188 = V_178 [ 1 ] . V_185 + 3 ;
V_178 [ 2 ] . V_185 = V_189 + V_190 ;
V_178 [ 2 ] . V_188 = V_189 + V_190 ;
}
static void T_1 F_31 ( void )
{
V_180 . V_181 = 1 ;
V_182 . V_181 = 1 ;
}
static void T_1 F_33 ( void )
{
F_31 () ;
F_5 ( & V_180 ) ;
F_5 ( & V_182 ) ;
}
static void T_1 F_34 ( void )
{
F_5 ( & V_191 ) ;
}
static void T_1 F_34 ( void ) {}
void T_1 F_35 ( T_2 V_192 )
{
if ( V_192 & ( 1 << V_193 ) )
F_10 ( V_194 , 1 ) ;
if ( V_192 & ( 1 << V_195 ) )
F_10 ( V_196 , 1 ) ;
if ( V_192 & ( 1 << V_197 ) )
F_10 ( V_198 , 1 ) ;
if ( V_192 & ( 1 << V_199 ) )
F_10 ( V_200 , 1 ) ;
V_201 = V_192 ;
F_5 ( & V_202 ) ;
}
void T_1 F_35 ( T_2 V_192 ) {}
static inline void F_36 ( unsigned V_203 )
{
if ( V_203 & V_204 )
F_10 ( V_121 , 1 ) ;
if ( V_203 & V_205 )
F_10 ( V_122 , 1 ) ;
if ( V_203 & V_206 )
F_10 ( V_123 , 1 ) ;
if ( V_203 & V_207 )
F_10 ( V_124 , 1 ) ;
if ( V_203 & V_208 )
F_10 ( V_102 , 1 ) ;
if ( V_203 & V_209 )
F_10 ( V_103 , 1 ) ;
}
static inline void F_37 ( unsigned V_203 )
{
if ( V_203 & V_204 )
F_9 ( V_210 , 1 ) ;
if ( V_203 & V_205 )
F_9 ( V_194 , 1 ) ;
if ( V_203 & V_206 )
F_9 ( V_196 , 1 ) ;
if ( V_203 & V_207 )
F_9 ( V_138 , 1 ) ;
if ( V_203 & V_208 )
F_9 ( V_211 , 1 ) ;
if ( V_203 & V_209 )
F_9 ( V_212 , 1 ) ;
}
void T_1 F_38 ( unsigned V_213 , unsigned V_203 )
{
struct V_71 * V_72 ;
switch ( V_213 ) {
case V_214 :
V_72 = & V_215 ;
F_36 ( V_203 ) ;
break;
case V_216 :
V_72 = & V_217 ;
F_37 ( V_203 ) ;
break;
default:
return;
}
F_5 ( V_72 ) ;
}
void T_1 F_38 ( unsigned V_213 , unsigned V_203 ) {}
static inline void F_39 ( void )
{
F_9 ( V_218 , 0 ) ;
F_9 ( V_219 , 1 ) ;
}
static inline void F_40 ( unsigned V_203 )
{
F_9 ( V_220 , 1 ) ;
F_9 ( V_221 , 0 ) ;
if ( V_203 & V_222 )
F_9 ( V_223 , 0 ) ;
if ( V_203 & V_224 )
F_9 ( V_225 , 0 ) ;
}
static inline void F_41 ( unsigned V_203 )
{
F_9 ( V_226 , 1 ) ;
F_9 ( V_227 , 0 ) ;
if ( V_203 & V_222 )
F_10 ( V_79 , 0 ) ;
if ( V_203 & V_224 )
F_10 ( V_86 , 0 ) ;
}
static inline void F_42 ( unsigned V_203 )
{
F_9 ( V_228 , 1 ) ;
F_9 ( V_229 , 0 ) ;
if ( V_203 & V_222 )
F_10 ( V_85 , 0 ) ;
if ( V_203 & V_224 )
F_10 ( V_75 , 0 ) ;
}
void T_1 F_43 ( unsigned V_213 , unsigned V_230 , unsigned V_203 )
{
struct V_71 * V_72 ;
struct V_231 * V_232 ;
switch ( V_213 ) {
case 0 :
V_72 = & V_233 ;
F_39 () ;
break;
case V_234 :
V_72 = & V_235 ;
F_40 ( V_203 ) ;
break;
case V_236 :
V_72 = & V_237 ;
F_41 ( V_203 ) ;
break;
case V_238 :
V_72 = & V_239 ;
F_42 ( V_203 ) ;
break;
default:
return;
}
V_232 = V_72 -> V_132 . V_133 ;
V_232 -> V_240 = V_230 ;
if ( V_230 < V_241 )
V_242 [ V_230 ] = V_72 ;
}
void T_1 F_44 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_241 ; V_3 ++ ) {
if ( V_242 [ V_3 ] )
F_5 ( V_242 [ V_3 ] ) ;
}
}
void T_1 F_43 ( unsigned V_213 , unsigned V_230 , unsigned V_203 ) {}
void T_1 F_44 ( void ) {}
static int T_1 F_45 ( void )
{
if ( F_46 () )
return 0 ;
F_33 () ;
F_34 () ;
F_27 () ;
return 0 ;
}
