static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 ;
int V_6 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_7 & V_8 )
V_2 -> V_9 |= V_10 ;
if ( F_3 ( V_5 ) -> V_11 -> V_12 & V_13 )
V_2 -> V_14 = V_15 ;
else
V_2 -> V_14 = V_16 ;
V_2 -> V_17 = 100 ;
V_2 -> V_18 = V_19 ;
V_2 -> V_20 = & V_21 ;
V_2 -> V_22 = & V_5 -> V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = 14 ;
V_3 = F_4 ( V_2 ) ;
if ( F_5 ( V_3 ) ) {
V_6 = F_6 ( V_3 ) ;
goto V_27;
}
V_2 -> V_28 = F_7 ( V_3 ) ;
if ( ! V_2 -> V_28 ) {
V_6 = - V_29 ;
goto V_27;
}
if ( F_3 ( V_5 ) -> V_30 )
V_2 -> V_31 = & V_32 ;
else
V_2 -> V_31 = & V_33 ;
#ifdef F_8
if ( V_5 -> V_7 & V_34 ) {
F_9 ( 1 , L_1 ) ;
V_2 -> V_35 = & V_36 ;
}
#endif
return 0 ;
V_27:
F_10 ( 1 , L_2 ) ;
return V_6 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_5 ) ;
}
static int
F_14 ( struct V_37 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_37 -> V_40 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_41 * V_42 = F_3 ( V_5 ) ;
struct V_43 * V_44 = V_42 -> V_11 -> V_44 ;
unsigned int V_45 ;
int V_6 = 0 ;
V_45 = F_15 () ;
V_39 -> V_46 = V_47 ;
V_39 -> V_48 = 0 ;
V_39 -> V_49 = 0 ;
if ( V_44 -> V_50 -> V_51 )
V_6 = V_44 -> V_50 -> V_51 ( V_45 , V_42 , V_39 ) ;
F_16 ( V_45 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_3 , int V_52 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 -> V_53 ) ;
if ( V_5 -> V_7 & V_54 ) {
if ( ( V_52 & V_55 ) && ! F_18 ( V_3 ) )
return - V_56 ;
else
return 0 ;
} else
return F_19 ( V_3 , V_52 ) ;
}
static struct V_3 *
F_20 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
V_58 = F_21 ( V_59 , V_60 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_61 = 0x20 ;
V_58 -> time = 0 ;
F_22 ( V_58 , 0 ) ;
V_58 -> V_62 = false ;
V_58 -> V_63 = false ;
V_58 -> V_64 . V_65 = 14 ;
V_58 -> V_66 = 0 ;
V_58 -> V_67 = 0 ;
V_58 -> V_68 = 0 ;
#ifdef F_23
F_24 ( V_58 -> V_69 , V_70 ) ;
#endif
F_25 ( & V_58 -> V_71 ) ;
F_25 ( & V_58 -> V_72 ) ;
return & V_58 -> V_64 ;
}
static void F_26 ( struct V_73 * V_74 )
{
struct V_3 * V_3 = F_27 ( V_74 , struct V_3 , V_75 ) ;
F_28 ( V_59 , F_29 ( V_3 ) ) ;
}
static void
F_30 ( struct V_3 * V_3 )
{
F_31 ( & V_3 -> V_75 , F_26 ) ;
}
static void
F_32 ( struct V_3 * V_3 )
{
F_33 ( & V_3 -> V_76 , 0 ) ;
F_34 ( V_3 ) ;
F_35 ( V_3 ) ;
}
static void
F_36 ( struct V_77 * V_78 , struct V_43 * V_44 )
{
struct V_79 * V_80 = (struct V_79 * ) & V_44 -> V_81 ;
struct V_82 * V_83 = (struct V_82 * ) & V_44 -> V_81 ;
F_37 ( V_78 , L_3 ) ;
switch ( V_44 -> V_81 . V_84 ) {
case V_85 :
F_37 ( V_78 , L_4 , & V_80 -> V_86 . V_87 ) ;
break;
case V_88 :
F_37 ( V_78 , L_5 , & V_83 -> V_89 . V_90 ) ;
if ( V_83 -> V_91 )
F_37 ( V_78 , L_6 , V_83 -> V_91 ) ;
break;
default:
F_37 ( V_78 , L_7 ) ;
}
}
static void
F_38 ( struct V_77 * V_78 , struct V_43 * V_44 )
{
F_37 ( V_78 , L_8 ) ;
switch ( V_44 -> V_92 ) {
case V_93 :
F_37 ( V_78 , L_9 ) ;
break;
case V_94 :
F_37 ( V_78 , L_10 ) ;
break;
case V_95 :
F_37 ( V_78 , L_11 ) ;
break;
case V_96 :
F_37 ( V_78 , L_12 ) ;
break;
case V_97 :
F_37 ( V_78 , L_13 ) ;
break;
default:
F_37 ( V_78 , L_14 ) ;
break;
}
if ( V_44 -> V_98 & ( V_99 | V_100 ) )
F_37 ( V_78 , L_15 ) ;
}
static void
F_39 ( struct V_77 * V_78 , struct V_4 * V_5 )
{
F_37 ( V_78 , L_16 ) ;
if ( V_5 -> V_7 & V_101 )
F_37 ( V_78 , L_17 ) ;
else if ( V_5 -> V_7 & V_102 )
F_37 ( V_78 , L_18 ) ;
else
F_37 ( V_78 , L_19 ) ;
}
static int
F_40 ( struct V_77 * V_78 , struct V_37 * V_103 )
{
struct V_4 * V_5 = F_2 ( V_103 -> V_40 ) ;
struct V_41 * V_42 = F_3 ( V_5 ) ;
struct V_104 * V_105 ;
V_105 = (struct V_104 * ) & V_42 -> V_11 -> V_44 -> V_105 ;
F_37 ( V_78 , L_20 , V_42 -> V_11 -> V_44 -> V_106 -> V_107 ) ;
F_38 ( V_78 , V_42 -> V_11 -> V_44 ) ;
F_39 ( V_78 , V_5 ) ;
F_37 ( V_78 , L_21 ) ;
F_41 ( V_78 , V_42 -> V_108 , L_22 ) ;
if ( V_5 -> V_7 & V_109 )
F_37 ( V_78 , L_23 ) ;
else if ( V_42 -> V_11 -> V_110 )
F_37 ( V_78 , L_24 , V_42 -> V_11 -> V_110 ) ;
if ( V_42 -> V_11 -> V_111 )
F_37 ( V_78 , L_25 , V_42 -> V_11 -> V_111 ) ;
if ( V_105 -> V_112 != V_113 ) {
struct V_79 * V_114 ;
struct V_82 * V_115 ;
V_114 = (struct V_79 * ) V_105 ;
V_115 = (struct V_82 * ) V_105 ;
if ( V_105 -> V_112 == V_88 )
F_37 ( V_78 , L_26 ,
& V_115 -> V_89 ) ;
else if ( V_105 -> V_112 == V_85 )
F_37 ( V_78 , L_27 ,
& V_114 -> V_86 . V_87 ) ;
else
F_37 ( V_78 , L_28 ,
( int ) ( V_105 -> V_112 ) ) ;
}
F_37 ( V_78 , L_29 , V_5 -> V_116 ) ;
if ( V_5 -> V_7 & V_117 )
F_37 ( V_78 , L_30 ) ;
else
F_37 ( V_78 , L_31 ) ;
F_37 ( V_78 , L_32 , V_5 -> V_118 ) ;
if ( V_5 -> V_7 & V_119 )
F_37 ( V_78 , L_33 ) ;
else
F_37 ( V_78 , L_34 ) ;
F_36 ( V_78 , V_42 -> V_11 -> V_44 ) ;
if ( ! V_42 -> V_120 )
F_37 ( V_78 , L_35 ,
V_5 -> V_121 ,
V_5 -> V_122 ) ;
if ( V_42 -> V_123 )
F_37 ( V_78 , L_36 ) ;
if ( V_42 -> V_30 )
F_37 ( V_78 , L_37 ) ;
if ( V_42 -> V_124 )
F_37 ( V_78 , L_38 ) ;
if ( V_42 -> V_120 )
F_37 ( V_78 , L_39 ) ;
else
F_37 ( V_78 , L_40 ) ;
if ( V_5 -> V_7 & V_125 )
F_37 ( V_78 , L_41 ) ;
if ( V_5 -> V_7 & V_126 )
F_37 ( V_78 , L_42 ) ;
if ( V_5 -> V_7 & V_34 )
F_37 ( V_78 , L_43 ) ;
if ( V_5 -> V_7 & V_127 )
F_37 ( V_78 , L_44 ) ;
if ( V_5 -> V_7 & V_128 )
F_37 ( V_78 , L_45 ) ;
if ( V_5 -> V_7 & V_129 )
F_37 ( V_78 , L_46 ) ;
if ( V_5 -> V_7 & V_130 )
F_37 ( V_78 , L_47 ) ;
if ( V_5 -> V_7 & V_131 )
F_37 ( V_78 , L_48 ) ;
if ( V_5 -> V_7 & V_132 )
F_37 ( V_78 , L_49 ) ;
if ( V_5 -> V_7 & V_133 )
F_37 ( V_78 , L_50 ) ;
if ( V_5 -> V_7 & V_134 )
F_37 ( V_78 , L_51 ) ;
if ( V_103 -> V_40 -> V_9 & V_10 )
F_37 ( V_78 , L_52 ) ;
if ( V_5 -> V_7 & V_135 )
F_37 ( V_78 , L_53 ) ;
if ( V_5 -> V_7 & V_136 )
F_37 ( V_78 , L_54 ) ;
if ( V_5 -> V_7 & V_137 )
F_37 ( V_78 , L_55 ) ;
if ( V_5 -> V_7 & V_54 )
F_37 ( V_78 , L_56 ) ;
if ( V_5 -> V_7 & V_138 )
F_37 ( V_78 , L_57 , V_5 -> V_139 ) ;
if ( V_5 -> V_7 & V_140 )
F_37 ( V_78 , L_58 , V_5 -> V_141 ) ;
F_37 ( V_78 , L_59 , V_5 -> V_142 ) ;
F_37 ( V_78 , L_60 , V_5 -> V_143 ) ;
F_37 ( V_78 , L_61 , V_5 -> V_144 / V_145 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_41 * V_42 ;
if ( V_5 == NULL )
return;
V_42 = F_3 ( V_5 ) ;
F_43 ( & V_146 ) ;
if ( ( V_42 -> V_147 > 1 ) || ( V_42 -> V_148 == V_149 ) ) {
F_44 ( & V_146 ) ;
return;
} else if ( V_42 -> V_147 == 1 )
V_42 -> V_148 = V_149 ;
F_44 ( & V_146 ) ;
if ( V_42 -> V_11 && V_42 -> V_11 -> V_44 ) {
F_9 ( 1 , L_62 ) ;
F_45 ( & V_42 -> V_11 -> V_44 -> V_150 ) ;
F_45 ( & V_42 -> V_11 -> V_44 -> V_151 ) ;
F_46 ( 1 ) ;
F_45 ( & V_42 -> V_11 -> V_44 -> V_151 ) ;
F_46 ( 1 ) ;
}
return;
}
static int F_47 ( struct V_77 * V_78 , struct V_37 * V_103 )
{
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int * V_152 , char * V_153 )
{
* V_152 |= V_154 ;
return 0 ;
}
static int F_49 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_53 ) ;
return ! ( V_5 -> V_7 & V_34 ) ||
F_50 ( V_3 ) ;
}
static struct V_37 *
F_51 ( struct V_155 * V_156 , struct V_1 * V_2 )
{
struct V_37 * V_37 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_157 = NULL ;
char * V_78 , * V_158 ;
char V_159 ;
V_157 = F_52 ( V_156 , V_5 ,
F_3 ( V_5 ) ) ;
if ( V_157 == NULL )
return F_53 ( - V_29 ) ;
F_9 ( 1 , L_63 , V_157 ) ;
V_159 = F_54 ( V_5 ) ;
V_37 = F_55 ( V_2 -> V_28 ) ;
V_158 = V_78 = V_157 ;
do {
struct V_3 * V_160 = V_37 -> V_161 ;
struct V_37 * V_162 ;
if ( ! V_160 ) {
F_56 ( V_37 ) ;
V_37 = F_53 ( - V_163 ) ;
break;
}
while ( * V_78 == V_159 )
V_78 ++ ;
if ( ! * V_78 )
break;
V_158 = V_78 ++ ;
while ( * V_78 && * V_78 != V_159 )
V_78 ++ ;
F_57 ( & V_160 -> V_164 ) ;
V_162 = F_58 ( V_158 , V_37 , V_78 - V_158 ) ;
F_59 ( & V_160 -> V_164 ) ;
F_56 ( V_37 ) ;
V_37 = V_162 ;
} while ( ! F_5 ( V_37 ) );
F_60 ( V_157 ) ;
return V_37 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_153 )
{
struct V_165 * V_166 = V_153 ;
V_2 -> V_167 = V_166 -> V_5 ;
return F_62 ( V_2 , NULL ) ;
}
static struct V_37 *
F_63 ( struct V_168 * V_169 ,
int V_152 , const char * V_170 , void * V_153 )
{
int V_6 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_155 * V_171 ;
struct V_165 V_166 ;
struct V_37 * V_103 ;
F_9 ( 1 , L_64 , V_170 , V_152 ) ;
V_171 = F_64 ( ( char * ) V_153 , V_170 ) ;
if ( F_5 ( V_171 ) )
return F_65 ( V_171 ) ;
V_5 = F_66 ( sizeof( struct V_4 ) , V_60 ) ;
if ( V_5 == NULL ) {
V_103 = F_53 ( - V_29 ) ;
goto V_172;
}
V_5 -> V_173 = F_67 ( V_153 , V_174 , V_60 ) ;
if ( V_5 -> V_173 == NULL ) {
V_103 = F_53 ( - V_29 ) ;
goto V_175;
}
F_68 ( V_171 , V_5 ) ;
V_6 = F_69 ( V_5 , V_171 ) ;
if ( V_6 ) {
if ( ! ( V_152 & V_176 ) )
F_10 ( 1 , L_65 , V_6 ) ;
V_103 = F_53 ( V_6 ) ;
goto V_177;
}
V_166 . V_156 = V_171 ;
V_166 . V_5 = V_5 ;
V_166 . V_152 = V_152 ;
V_152 |= V_154 | V_178 ;
V_2 = F_70 ( V_169 , V_179 , F_61 , V_152 , & V_166 ) ;
if ( F_5 ( V_2 ) ) {
V_103 = F_65 ( V_2 ) ;
F_13 ( V_5 ) ;
goto V_180;
}
if ( V_2 -> V_28 ) {
F_9 ( 1 , L_66 ) ;
F_13 ( V_5 ) ;
} else {
V_6 = F_1 ( V_2 ) ;
if ( V_6 ) {
V_103 = F_53 ( V_6 ) ;
goto V_181;
}
V_2 -> V_9 |= V_182 ;
}
V_103 = F_51 ( V_171 , V_2 ) ;
if ( F_5 ( V_103 ) )
goto V_181;
F_9 ( 1 , L_67 , V_103 ) ;
goto V_180;
V_181:
F_71 ( V_2 ) ;
V_180:
F_72 ( V_171 ) ;
return V_103 ;
V_177:
F_60 ( V_5 -> V_173 ) ;
V_175:
F_60 ( V_5 ) ;
V_172:
F_73 ( V_171 -> V_183 ) ;
goto V_180;
}
static T_1 F_74 ( struct V_184 * V_185 , const struct V_186 * V_187 ,
unsigned long V_188 , T_2 V_189 )
{
struct V_3 * V_3 = V_185 -> V_190 -> V_191 . V_37 -> V_161 ;
T_1 V_192 ;
int V_6 ;
V_192 = F_75 ( V_185 , V_187 , V_188 , V_189 ) ;
if ( F_29 ( V_3 ) -> V_193 )
return V_192 ;
V_6 = F_76 ( V_3 -> V_194 ) ;
if ( V_6 )
F_9 ( 1 , L_68 , V_6 , V_3 ) ;
return V_192 ;
}
static T_2 F_77 ( struct V_195 * V_195 , T_2 V_196 , int V_197 )
{
if ( V_197 != V_198 && V_197 != V_199 ) {
int V_6 ;
struct V_3 * V_3 = V_195 -> V_191 . V_37 -> V_161 ;
if ( ! F_29 ( V_3 ) -> V_200 && V_3 -> V_194 &&
V_3 -> V_194 -> V_201 != 0 ) {
V_6 = F_78 ( V_3 -> V_194 ) ;
if ( V_6 ) {
F_79 ( V_3 -> V_194 , V_6 ) ;
return V_6 ;
}
}
F_29 ( V_3 ) -> time = 0 ;
V_6 = F_80 ( V_195 ) ;
if ( V_6 < 0 )
return ( T_2 ) V_6 ;
}
return F_81 ( V_195 , V_196 , V_197 ) ;
}
static int F_82 ( struct V_195 * V_195 , long V_202 , struct V_203 * * V_204 )
{
struct V_3 * V_3 = V_195 -> V_191 . V_37 -> V_161 ;
struct V_205 * V_206 = V_195 -> V_207 ;
if ( ! ( F_83 ( V_3 -> V_208 ) ) )
return - V_209 ;
if ( ( ( V_202 == V_210 ) &&
( F_29 ( V_3 ) -> V_200 ) ) ||
( ( V_202 == V_211 ) &&
( F_29 ( V_3 ) -> V_193 ) ) )
return F_84 ( V_195 , V_202 , V_204 ) ;
else if ( F_85 ( V_206 -> V_212 ) -> V_213 &&
! F_29 ( V_3 ) -> V_200 )
return F_84 ( V_195 , V_202 , V_204 ) ;
else
return - V_214 ;
}
static void
F_86 ( void * V_3 )
{
struct V_57 * V_215 = V_3 ;
F_87 ( & V_215 -> V_64 ) ;
F_88 ( & V_215 -> V_216 ) ;
}
static int
F_89 ( void )
{
V_59 = F_90 ( L_69 ,
sizeof( struct V_57 ) ,
0 , ( V_217 |
V_218 ) ,
F_86 ) ;
if ( V_59 == NULL )
return - V_29 ;
return 0 ;
}
static void
F_91 ( void )
{
F_92 () ;
F_93 ( V_59 ) ;
}
static int
F_94 ( void )
{
T_3 V_219 = V_220 ;
#ifdef F_23
V_219 = V_221 ;
#endif
if ( V_222 < 8192 ) {
V_222 = 8192 ;
} else if ( V_222 > 1024 * 127 ) {
V_222 = 1024 * 127 ;
} else {
V_222 &= 0x1FE00 ;
}
V_223 = F_90 ( L_70 ,
V_222 + V_219 , 0 ,
V_224 , NULL ) ;
if ( V_223 == NULL )
return - V_29 ;
if ( V_225 < 1 )
V_225 = 1 ;
else if ( V_225 > 64 ) {
V_225 = 64 ;
F_10 ( 1 , L_71 ) ;
}
V_226 = F_95 ( V_225 ,
V_223 ) ;
if ( V_226 == NULL ) {
F_93 ( V_223 ) ;
return - V_29 ;
}
V_227 = F_90 ( L_72 ,
V_228 , 0 , V_224 ,
NULL ) ;
if ( V_227 == NULL ) {
F_96 ( V_226 ) ;
F_93 ( V_223 ) ;
return - V_29 ;
}
if ( V_229 < 2 )
V_229 = 2 ;
else if ( V_229 > 256 ) {
V_229 = 256 ;
F_9 ( 1 , L_73 ) ;
}
V_230 = F_95 ( V_229 ,
V_227 ) ;
if ( V_230 == NULL ) {
F_96 ( V_226 ) ;
F_93 ( V_223 ) ;
F_93 ( V_227 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_97 ( void )
{
F_96 ( V_226 ) ;
F_93 ( V_223 ) ;
F_96 ( V_230 ) ;
F_93 ( V_227 ) ;
}
static int
F_98 ( void )
{
V_231 = F_90 ( L_74 ,
sizeof( struct V_232 ) , 0 ,
V_224 , NULL ) ;
if ( V_231 == NULL )
return - V_29 ;
V_233 = F_95 ( 3 , V_231 ) ;
if ( V_233 == NULL ) {
F_93 ( V_231 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_99 ( void )
{
F_96 ( V_233 ) ;
F_93 ( V_231 ) ;
}
static int T_4
F_100 ( void )
{
int V_6 = 0 ;
F_101 () ;
F_25 ( & V_234 ) ;
#ifdef F_102
F_25 ( & V_235 ) ;
F_25 ( & V_236 ) ;
#endif
F_103 ( & V_237 , 0 ) ;
F_103 ( & V_238 , 0 ) ;
F_103 ( & V_239 , 0 ) ;
F_103 ( & V_240 , 0 ) ;
F_103 ( & V_241 , 0 ) ;
F_103 ( & V_242 , 0 ) ;
F_103 ( & V_243 , 0 ) ;
#ifdef F_104
F_103 ( & V_244 , 0 ) ;
F_103 ( & V_245 , 0 ) ;
#endif
F_103 ( & V_246 , 0 ) ;
V_247 = 0 ;
V_248 = 0 ;
V_249 = 0 ;
F_105 ( & V_146 ) ;
F_105 ( & V_250 ) ;
F_105 ( & V_251 ) ;
#ifdef F_23
F_24 ( V_252 , V_253 ) ;
#endif
if ( V_254 < 2 ) {
V_254 = 2 ;
F_9 ( 1 , L_75 ) ;
} else if ( V_254 > V_255 ) {
V_254 = V_255 ;
F_9 ( 1 , L_76 , V_255 ) ;
}
V_256 = F_106 ( L_77 , V_257 | V_258 , 0 ) ;
if ( ! V_256 ) {
V_6 = - V_29 ;
goto V_259;
}
V_6 = F_107 () ;
if ( V_6 )
goto V_260;
V_6 = F_89 () ;
if ( V_6 )
goto V_261;
V_6 = F_98 () ;
if ( V_6 )
goto V_262;
V_6 = F_94 () ;
if ( V_6 )
goto V_263;
#ifdef F_108
V_6 = F_109 ( & V_264 ) ;
if ( V_6 )
goto V_265;
#endif
#ifdef F_110
V_6 = F_111 () ;
if ( V_6 )
goto V_266;
#endif
V_6 = F_112 ( & V_267 ) ;
if ( V_6 )
goto V_268;
return 0 ;
V_268:
#ifdef F_110
F_113 () ;
V_266:
#endif
#ifdef F_108
F_114 ( & V_264 ) ;
V_265:
#endif
F_97 () ;
V_263:
F_99 () ;
V_262:
F_91 () ;
V_261:
F_115 () ;
V_260:
F_116 ( V_256 ) ;
V_259:
F_117 () ;
return V_6 ;
}
static void T_5
F_118 ( void )
{
F_9 ( V_269 , L_78 ) ;
F_119 ( & V_267 ) ;
F_120 () ;
#ifdef F_110
F_113 () ;
#endif
#ifdef F_108
F_114 ( & V_264 ) ;
#endif
F_97 () ;
F_99 () ;
F_91 () ;
F_115 () ;
F_116 ( V_256 ) ;
F_117 () ;
}
