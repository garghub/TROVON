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
if ( F_2 ( V_2 -> V_7 [ V_3 ] ) )
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
unsigned int V_3 ;
unsigned int V_38 = 0 ;
if ( ! V_2 )
return;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) {
if ( ! V_2 -> V_40 [ V_3 ] . V_41 )
continue;
if ( F_2 ( V_2 -> V_40 [ V_3 ] . V_42 ) ) {
F_4 ( V_2 -> V_40 [ V_3 ] . V_42 ,
1 ) ;
F_7 ( V_2 -> V_40 [ V_3 ] . V_42 ,
1 ) ;
}
if ( F_2 ( V_2 -> V_40 [ V_3 ] . V_43 ) )
F_4 ( V_2 -> V_40 [ V_3 ] . V_43 , 1 ) ;
if ( V_36 == 0 ) {
switch ( V_3 ) {
case 0 :
F_9 ( V_44 , 1 ) ;
F_9 ( V_45 , 1 ) ;
if ( V_2 -> V_40 [ V_3 ] . V_41 == 4 ) {
F_9 ( V_46 , 1 ) ;
F_9 ( V_47 , 1 ) ;
F_9 ( V_48 , 1 ) ;
}
V_38 ++ ;
break;
case 1 :
F_9 ( V_49 , 1 ) ;
F_9 ( V_50 , 1 ) ;
if ( V_2 -> V_40 [ V_3 ] . V_41 == 4 ) {
F_9 ( V_51 , 1 ) ;
F_9 ( V_52 , 1 ) ;
F_9 ( V_53 , 1 ) ;
}
V_38 ++ ;
break;
default:
F_12 ( V_54
L_1 , V_3 ) ;
break;
}
if ( V_38 ) {
F_9 ( V_55 , 0 ) ;
V_56 = * V_2 ;
F_5 ( & V_57 ) ;
}
} else if ( V_36 == 1 ) {
switch ( V_3 ) {
case 0 :
F_9 ( V_58 , 1 ) ;
F_9 ( V_59 , 1 ) ;
if ( V_2 -> V_40 [ V_3 ] . V_41 == 4 ) {
F_9 ( V_60 , 1 ) ;
F_9 ( V_61 , 1 ) ;
F_9 ( V_62 , 1 ) ;
}
V_38 ++ ;
break;
case 1 :
F_9 ( V_63 , 1 ) ;
F_9 ( V_64 , 1 ) ;
if ( V_2 -> V_40 [ V_3 ] . V_41 == 4 ) {
F_9 ( V_65 , 1 ) ;
F_9 ( V_66 , 1 ) ;
F_9 ( V_67 , 1 ) ;
}
V_38 ++ ;
break;
default:
F_12 ( V_54
L_1 , V_3 ) ;
break;
}
if ( V_38 ) {
F_9 ( V_68 , 0 ) ;
V_69 = * V_2 ;
F_5 ( & V_70 ) ;
}
}
}
}
void T_1 F_11 ( short V_36 , struct V_37 * V_2 ) {}
void T_1 F_13 ( struct V_71 * V_2 )
{
unsigned long V_72 ;
struct V_73 * V_74 ;
if ( ! V_2 )
return;
V_72 = F_14 ( V_75 ) ;
switch ( V_2 -> V_76 ) {
case 4 :
F_9 ( V_77 , 0 ) ;
V_72 |= V_78 ;
V_79 = * V_2 ;
V_74 = & V_80 ;
break;
case 5 :
F_9 ( V_81 , 0 ) ;
V_72 |= V_82 ;
V_83 = * V_2 ;
V_74 = & V_84 ;
break;
default:
F_12 ( V_54 L_2 ,
V_2 -> V_76 ) ;
return;
}
F_15 ( V_75 , V_72 ) ;
if ( F_2 ( V_2 -> V_85 ) ) {
F_4 ( V_2 -> V_85 , 1 ) ;
F_7 ( V_2 -> V_85 , 1 ) ;
}
if ( F_2 ( V_2 -> V_86 ) ) {
F_4 ( V_2 -> V_86 , 1 ) ;
F_7 ( V_2 -> V_86 , 1 ) ;
}
if ( F_2 ( V_2 -> V_87 ) )
F_3 ( V_2 -> V_87 , 0 ) ;
F_9 ( V_88 , 1 ) ;
F_9 ( V_89 , 0 ) ;
F_9 ( V_90 , 0 ) ;
F_9 ( V_91 , 0 ) ;
V_74 -> V_92 = ( V_2 -> V_93 & V_94 ) ? L_3 : L_4 ;
F_5 ( V_74 ) ;
}
void T_1 F_13 ( struct V_71 * V_2 ) {}
void T_1 F_16 ( struct V_95 * V_2 )
{
unsigned long V_96 ;
if ( ! V_2 )
return;
V_96 = F_14 ( V_75 ) ;
F_15 ( V_75 , V_96 | V_97 ) ;
if ( F_2 ( V_2 -> V_98 ) )
F_3 ( V_2 -> V_98 , 1 ) ;
if ( F_2 ( V_2 -> V_99 ) )
F_4 ( V_2 -> V_99 , 1 ) ;
if ( F_2 ( V_2 -> V_85 ) )
F_4 ( V_2 -> V_85 , 1 ) ;
V_100 = * V_2 ;
F_5 ( & V_101 ) ;
}
void T_1 F_16 ( struct V_95 * V_2 ) {}
void T_1 F_17 ( struct V_102 * V_103 , int V_104 )
{
F_18 ( V_105 , 1 ) ;
F_19 ( V_105 , 1 ) ;
F_18 ( V_106 , 1 ) ;
F_19 ( V_106 , 1 ) ;
F_20 ( 0 , V_103 , V_104 ) ;
F_5 ( & V_107 ) ;
}
void T_1 F_17 ( struct V_102 * V_103 , int V_104 )
{
F_9 ( V_105 , 0 ) ;
F_19 ( V_105 , 1 ) ;
F_9 ( V_106 , 0 ) ;
F_19 ( V_106 , 1 ) ;
F_20 ( 0 , V_103 , V_104 ) ;
F_5 ( & V_107 ) ;
}
void T_1 F_17 ( struct V_102 * V_103 , int V_104 ) {}
void T_1 F_21 ( struct V_108 * V_103 , int V_104 )
{
int V_3 ;
unsigned long V_109 ;
short V_110 = 0 ;
short V_111 = 0 ;
for ( V_3 = 0 ; V_3 < V_104 ; V_3 ++ ) {
if ( V_103 [ V_3 ] . V_112 )
V_109 = ( unsigned long ) V_103 [ V_3 ] . V_112 ;
else if ( V_103 [ V_3 ] . V_113 == 0 )
V_109 = V_114 [ V_103 [ V_3 ] . V_115 ] ;
else
V_109 = V_116 [ V_103 [ V_3 ] . V_115 ] ;
if ( ! F_2 ( V_109 ) )
continue;
if ( V_103 [ V_3 ] . V_113 == 0 )
V_110 = 1 ;
else
V_111 = 1 ;
F_3 ( V_109 , 1 ) ;
V_103 [ V_3 ] . V_112 = ( void * ) V_109 ;
}
F_22 ( V_103 , V_104 ) ;
if ( V_110 ) {
F_10 ( V_45 , 0 ) ;
F_10 ( V_44 , 0 ) ;
F_10 ( V_117 , 0 ) ;
F_5 ( & V_118 ) ;
}
if ( V_111 ) {
F_9 ( V_119 , 0 ) ;
F_9 ( V_120 , 0 ) ;
F_9 ( V_121 , 0 ) ;
F_5 ( & V_122 ) ;
}
}
void T_1 F_21 ( struct V_108 * V_103 , int V_104 ) {}
void T_1 F_23 ( struct V_123 * V_2 )
{
if ( ! V_2 )
return;
F_9 ( V_124 , 0 ) ;
F_9 ( V_125 , 0 ) ;
F_9 ( V_126 , 0 ) ;
F_9 ( V_127 , 0 ) ;
if ( F_2 ( V_2 -> V_128 ) )
F_3 ( V_2 -> V_128 , 0 ) ;
V_129 = * V_2 ;
F_5 ( & V_130 ) ;
}
void T_1 F_23 ( struct V_123 * V_2 ) {}
void T_1 F_24 ( struct V_131 * V_2 )
{
F_9 ( V_132 , 0 ) ;
F_9 ( V_133 , 0 ) ;
V_134 . V_135 . V_136 = V_2 ;
F_5 ( & V_134 ) ;
}
void T_1 F_24 ( struct V_131 * V_2 ) {}
void T_1 F_25 ( struct V_137 * V_2 )
{
if ( ! V_2 )
return;
F_9 ( V_138 , 0 ) ;
F_9 ( V_139 , 0 ) ;
F_9 ( V_140 , 0 ) ;
F_10 ( V_141 , 0 ) ;
F_9 ( V_142 , 0 ) ;
F_9 ( V_143 , 0 ) ;
F_9 ( V_144 , 0 ) ;
F_9 ( V_145 , 0 ) ;
F_9 ( V_146 , 0 ) ;
F_9 ( V_147 , 0 ) ;
F_9 ( V_148 , 0 ) ;
F_9 ( V_149 , 0 ) ;
F_9 ( V_150 , 0 ) ;
F_10 ( V_151 , 0 ) ;
F_9 ( V_152 , 0 ) ;
F_9 ( V_153 , 0 ) ;
F_9 ( V_28 , 0 ) ;
F_9 ( V_29 , 0 ) ;
F_9 ( V_33 , 0 ) ;
F_10 ( V_154 , 0 ) ;
F_9 ( V_27 , 0 ) ;
F_9 ( V_30 , 0 ) ;
V_155 = * V_2 ;
F_5 ( & V_156 ) ;
}
void T_1 F_25 ( struct V_137 * V_2 ) {}
void T_1 F_26 ( struct V_157 * V_2 ,
bool V_158 )
{
F_9 ( V_159 , 0 ) ;
F_9 ( V_160 , 0 ) ;
F_9 ( V_161 , 0 ) ;
F_9 ( V_162 , 0 ) ;
F_9 ( V_163 , 0 ) ;
F_9 ( V_164 , 0 ) ;
F_9 ( V_165 , 0 ) ;
F_9 ( V_166 , 0 ) ;
F_9 ( V_167 , 0 ) ;
F_9 ( V_168 , 0 ) ;
F_9 ( V_169 , 0 ) ;
F_10 ( V_170 , 0 ) ;
F_10 ( V_171 , 0 ) ;
F_10 ( V_172 , 0 ) ;
F_10 ( V_173 , 0 ) ;
if ( V_158 ) {
F_10 ( V_174 , 0 ) ;
}
}
void T_1 F_26 ( struct V_157 * V_2 ,
bool V_158 ) {}
static void T_1 F_27 ( void )
{
#if F_28 ( V_175 )
struct V_176 * V_177 ;
V_177 = F_29 ( NULL , V_178 ) ;
if ( V_177 ) {
F_30 ( V_177 ) ;
return;
}
#endif
F_5 ( & V_179 ) ;
}
static void T_1 F_27 ( void ) { }
static void T_1 F_31 ( void )
{
struct V_73 * V_74 ;
struct V_180 * V_181 ;
switch ( V_182 ) {
case 0 :
V_183 . V_184 = 3 ;
V_185 . V_184 = 1 ;
V_74 = & V_183 ;
V_181 = V_186 ;
break;
case 1 :
V_183 . V_184 = 1 ;
V_185 . V_184 = 3 ;
V_74 = & V_185 ;
V_181 = V_187 ;
break;
default:
F_32 ( L_5 ,
V_182 ) ;
return;
}
V_74 -> V_92 = L_6 ;
V_181 [ 1 ] . V_188 = V_189 + 4 * V_190 ;
V_181 [ 1 ] . V_191 = V_181 [ 1 ] . V_188 + 3 ;
V_181 [ 2 ] . V_188 = V_192 + V_193 ;
V_181 [ 2 ] . V_191 = V_192 + V_193 ;
}
static void T_1 F_31 ( void )
{
V_183 . V_184 = 1 ;
V_185 . V_184 = 1 ;
}
static void T_1 F_33 ( void )
{
F_31 () ;
F_5 ( & V_183 ) ;
F_5 ( & V_185 ) ;
}
static void T_1 F_34 ( void )
{
F_5 ( & V_194 ) ;
}
static void T_1 F_34 ( void ) {}
void T_1 F_35 ( T_2 V_195 )
{
if ( V_195 & ( 1 << V_196 ) )
F_10 ( V_197 , 1 ) ;
if ( V_195 & ( 1 << V_198 ) )
F_10 ( V_199 , 1 ) ;
if ( V_195 & ( 1 << V_200 ) )
F_10 ( V_201 , 1 ) ;
if ( V_195 & ( 1 << V_202 ) )
F_10 ( V_203 , 1 ) ;
V_204 = V_195 ;
F_5 ( & V_205 ) ;
}
void T_1 F_35 ( T_2 V_195 ) {}
static inline void F_36 ( unsigned V_206 )
{
if ( V_206 & V_207 )
F_10 ( V_124 , 1 ) ;
if ( V_206 & V_208 )
F_10 ( V_125 , 1 ) ;
if ( V_206 & V_209 )
F_10 ( V_126 , 1 ) ;
if ( V_206 & V_210 )
F_10 ( V_127 , 1 ) ;
if ( V_206 & V_211 )
F_10 ( V_105 , 1 ) ;
if ( V_206 & V_212 )
F_10 ( V_106 , 1 ) ;
}
static inline void F_37 ( unsigned V_206 )
{
if ( V_206 & V_207 )
F_9 ( V_213 , 1 ) ;
if ( V_206 & V_208 )
F_9 ( V_197 , 1 ) ;
if ( V_206 & V_209 )
F_9 ( V_199 , 1 ) ;
if ( V_206 & V_210 )
F_9 ( V_141 , 1 ) ;
if ( V_206 & V_211 )
F_9 ( V_214 , 1 ) ;
if ( V_206 & V_212 )
F_9 ( V_215 , 1 ) ;
}
void T_1 F_38 ( unsigned V_216 , unsigned V_206 )
{
struct V_73 * V_74 ;
switch ( V_216 ) {
case V_217 :
V_74 = & V_218 ;
F_36 ( V_206 ) ;
break;
case V_219 :
V_74 = & V_220 ;
F_37 ( V_206 ) ;
break;
default:
return;
}
F_5 ( V_74 ) ;
}
void T_1 F_38 ( unsigned V_216 , unsigned V_206 ) {}
static inline void F_39 ( void )
{
F_9 ( V_221 , 0 ) ;
F_9 ( V_222 , 1 ) ;
}
static inline void F_40 ( unsigned V_206 )
{
F_9 ( V_223 , 1 ) ;
F_9 ( V_224 , 0 ) ;
if ( V_206 & V_225 )
F_9 ( V_226 , 0 ) ;
if ( V_206 & V_227 )
F_9 ( V_228 , 0 ) ;
}
static inline void F_41 ( unsigned V_206 )
{
F_9 ( V_229 , 1 ) ;
F_9 ( V_230 , 0 ) ;
if ( V_206 & V_225 )
F_10 ( V_81 , 0 ) ;
if ( V_206 & V_227 )
F_10 ( V_89 , 0 ) ;
}
static inline void F_42 ( unsigned V_206 )
{
F_9 ( V_231 , 1 ) ;
F_9 ( V_232 , 0 ) ;
if ( V_206 & V_225 )
F_10 ( V_88 , 0 ) ;
if ( V_206 & V_227 )
F_10 ( V_77 , 0 ) ;
}
void T_1 F_43 ( unsigned V_216 , unsigned V_233 , unsigned V_206 )
{
struct V_73 * V_74 ;
struct V_234 * V_235 ;
switch ( V_216 ) {
case 0 :
V_74 = & V_236 ;
F_39 () ;
break;
case V_237 :
V_74 = & V_238 ;
F_40 ( V_206 ) ;
break;
case V_239 :
V_74 = & V_240 ;
F_41 ( V_206 ) ;
break;
case V_241 :
V_74 = & V_242 ;
F_42 ( V_206 ) ;
break;
default:
return;
}
V_235 = V_74 -> V_135 . V_136 ;
V_235 -> V_243 = V_233 ;
if ( V_233 < V_244 )
V_245 [ V_233 ] = V_74 ;
}
void T_1 F_44 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_244 ; V_3 ++ ) {
if ( V_245 [ V_3 ] )
F_5 ( V_245 [ V_3 ] ) ;
}
}
void T_1 F_43 ( unsigned V_216 , unsigned V_233 , unsigned V_206 ) {}
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
