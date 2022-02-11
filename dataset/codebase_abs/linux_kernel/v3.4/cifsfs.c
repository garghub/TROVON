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
int V_6 = - V_43 ;
int V_44 ;
V_44 = F_15 () ;
V_39 -> V_45 = V_19 ;
V_39 -> V_46 = V_47 ;
V_39 -> V_48 = 0 ;
V_39 -> V_49 = 0 ;
if ( ( V_42 -> V_11 -> V_12 & V_50 ) &&
( V_51 & F_16 ( V_42 -> V_52 . V_53 ) ) )
V_6 = F_17 ( V_44 , V_42 , V_39 ) ;
if ( V_6 && ( V_42 -> V_11 -> V_12 & V_54 ) )
V_6 = F_18 ( V_44 , V_42 , V_39 ) ;
if ( V_6 )
V_6 = F_19 ( V_44 , V_42 , V_39 ) ;
F_20 ( V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_3 , int V_55 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 -> V_56 ) ;
if ( V_5 -> V_7 & V_57 ) {
if ( ( V_55 & V_58 ) && ! F_22 ( V_3 ) )
return - V_59 ;
else
return 0 ;
} else
return F_23 ( V_3 , V_55 ) ;
}
static struct V_3 *
F_24 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
V_61 = F_25 ( V_62 , V_63 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_64 = 0x20 ;
V_61 -> time = 0 ;
F_26 ( V_61 , 0 ) ;
V_61 -> V_65 = false ;
V_61 -> V_66 = false ;
V_61 -> V_67 . V_68 = 14 ;
V_61 -> V_69 = 0 ;
V_61 -> V_70 = 0 ;
V_61 -> V_71 = 0 ;
F_27 ( & V_61 -> V_72 ) ;
return & V_61 -> V_67 ;
}
static void F_28 ( struct V_73 * V_74 )
{
struct V_3 * V_3 = F_29 ( V_74 , struct V_3 , V_75 ) ;
F_27 ( & V_3 -> V_76 ) ;
F_30 ( V_62 , F_31 ( V_3 ) ) ;
}
static void
F_32 ( struct V_3 * V_3 )
{
F_33 ( & V_3 -> V_75 , F_28 ) ;
}
static void
F_34 ( struct V_3 * V_3 )
{
F_35 ( & V_3 -> V_77 , 0 ) ;
F_36 ( V_3 ) ;
F_37 ( V_3 ) ;
}
static void
F_38 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) & V_81 -> V_84 ;
struct V_85 * V_86 = (struct V_85 * ) & V_81 -> V_84 ;
F_39 ( V_79 , L_3 ) ;
switch ( V_81 -> V_84 . V_87 ) {
case V_88 :
F_39 ( V_79 , L_4 , & V_83 -> V_89 . V_90 ) ;
break;
case V_91 :
F_39 ( V_79 , L_5 , & V_86 -> V_92 . V_93 ) ;
if ( V_86 -> V_94 )
F_39 ( V_79 , L_6 , V_86 -> V_94 ) ;
break;
default:
F_39 ( V_79 , L_7 ) ;
}
}
static void
F_40 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
F_39 ( V_79 , L_8 ) ;
switch ( V_81 -> V_95 ) {
case V_96 :
F_39 ( V_79 , L_9 ) ;
break;
case V_97 :
F_39 ( V_79 , L_10 ) ;
break;
case V_98 :
F_39 ( V_79 , L_11 ) ;
break;
case V_99 :
F_39 ( V_79 , L_12 ) ;
break;
case V_100 :
F_39 ( V_79 , L_13 ) ;
break;
default:
F_39 ( V_79 , L_14 ) ;
break;
}
if ( V_81 -> V_101 & ( V_102 | V_103 ) )
F_39 ( V_79 , L_15 ) ;
}
static int
F_41 ( struct V_78 * V_79 , struct V_37 * V_104 )
{
struct V_4 * V_5 = F_2 ( V_104 -> V_40 ) ;
struct V_41 * V_42 = F_3 ( V_5 ) ;
struct V_105 * V_106 ;
V_106 = (struct V_105 * ) & V_42 -> V_11 -> V_81 -> V_106 ;
F_40 ( V_79 , V_42 -> V_11 -> V_81 ) ;
F_39 ( V_79 , L_16 , V_42 -> V_107 ) ;
if ( V_5 -> V_7 & V_108 )
F_39 ( V_79 , L_17 ) ;
else if ( V_42 -> V_11 -> V_109 )
F_39 ( V_79 , L_18 , V_42 -> V_11 -> V_109 ) ;
if ( V_42 -> V_11 -> V_110 )
F_39 ( V_79 , L_19 , V_42 -> V_11 -> V_110 ) ;
if ( V_106 -> V_111 != V_112 ) {
struct V_82 * V_113 ;
struct V_85 * V_114 ;
V_113 = (struct V_82 * ) V_106 ;
V_114 = (struct V_85 * ) V_106 ;
if ( V_106 -> V_111 == V_91 )
F_39 ( V_79 , L_20 ,
& V_114 -> V_92 ) ;
else if ( V_106 -> V_111 == V_88 )
F_39 ( V_79 , L_21 ,
& V_113 -> V_89 . V_90 ) ;
else
F_39 ( V_79 , L_22 ,
( int ) ( V_106 -> V_111 ) ) ;
}
F_39 ( V_79 , L_23 , V_5 -> V_115 ) ;
if ( V_5 -> V_7 & V_116 )
F_39 ( V_79 , L_24 ) ;
else
F_39 ( V_79 , L_25 ) ;
F_39 ( V_79 , L_26 , V_5 -> V_117 ) ;
if ( V_5 -> V_7 & V_118 )
F_39 ( V_79 , L_27 ) ;
else
F_39 ( V_79 , L_28 ) ;
F_38 ( V_79 , V_42 -> V_11 -> V_81 ) ;
if ( ! V_42 -> V_119 )
F_39 ( V_79 , L_29 ,
V_5 -> V_120 ,
V_5 -> V_121 ) ;
if ( V_42 -> V_122 )
F_39 ( V_79 , L_30 ) ;
if ( V_42 -> V_30 )
F_39 ( V_79 , L_31 ) ;
if ( V_42 -> V_123 )
F_39 ( V_79 , L_32 ) ;
if ( V_42 -> V_119 )
F_39 ( V_79 , L_33 ) ;
else
F_39 ( V_79 , L_34 ) ;
if ( V_5 -> V_7 & V_124 )
F_39 ( V_79 , L_35 ) ;
if ( V_5 -> V_7 & V_125 )
F_39 ( V_79 , L_36 ) ;
if ( V_5 -> V_7 & V_34 )
F_39 ( V_79 , L_37 ) ;
if ( V_5 -> V_7 & V_126 )
F_39 ( V_79 , L_38 ) ;
if ( V_5 -> V_7 & V_127 )
F_39 ( V_79 , L_39 ) ;
if ( V_5 -> V_7 & V_128 )
F_39 ( V_79 , L_40 ) ;
if ( V_5 -> V_7 & V_129 )
F_39 ( V_79 , L_41 ) ;
if ( V_5 -> V_7 & V_130 )
F_39 ( V_79 , L_42 ) ;
if ( V_5 -> V_7 & V_131 )
F_39 ( V_79 , L_43 ) ;
if ( V_5 -> V_7 & V_132 )
F_39 ( V_79 , L_44 ) ;
if ( V_5 -> V_7 & V_133 )
F_39 ( V_79 , L_45 ) ;
if ( V_5 -> V_7 & V_134 )
F_39 ( V_79 , L_46 ) ;
if ( V_104 -> V_40 -> V_9 & V_10 )
F_39 ( V_79 , L_47 ) ;
if ( V_5 -> V_7 & V_135 )
F_39 ( V_79 , L_48 ) ;
if ( V_5 -> V_7 & V_136 )
F_39 ( V_79 , L_49 ) ;
if ( V_5 -> V_7 & V_137 )
F_39 ( V_79 , L_50 ) ;
if ( V_5 -> V_7 & V_57 )
F_39 ( V_79 , L_51 ) ;
if ( V_5 -> V_7 & V_138 )
F_39 ( V_79 , L_52 ) ;
if ( V_5 -> V_7 & V_139 )
F_39 ( V_79 , L_53 , V_5 -> V_140 ) ;
if ( V_5 -> V_7 & V_141 )
F_39 ( V_79 , L_54 , V_5 -> V_142 ) ;
F_39 ( V_79 , L_55 , V_5 -> V_143 ) ;
F_39 ( V_79 , L_56 , V_5 -> V_144 ) ;
F_39 ( V_79 , L_57 , V_5 -> V_145 / V_146 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_41 * V_42 ;
if ( V_5 == NULL )
return;
V_42 = F_3 ( V_5 ) ;
F_43 ( & V_147 ) ;
if ( ( V_42 -> V_148 > 1 ) || ( V_42 -> V_149 == V_150 ) ) {
F_44 ( & V_147 ) ;
return;
} else if ( V_42 -> V_148 == 1 )
V_42 -> V_149 = V_150 ;
F_44 ( & V_147 ) ;
if ( V_42 -> V_11 && V_42 -> V_11 -> V_81 ) {
F_9 ( 1 , L_58 ) ;
F_45 ( & V_42 -> V_11 -> V_81 -> V_151 ) ;
F_45 ( & V_42 -> V_11 -> V_81 -> V_152 ) ;
F_46 ( 1 ) ;
F_45 ( & V_42 -> V_11 -> V_81 -> V_152 ) ;
F_46 ( 1 ) ;
}
return;
}
static int F_47 ( struct V_78 * V_79 , struct V_37 * V_104 )
{
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int * V_153 , char * V_154 )
{
* V_153 |= V_155 ;
return 0 ;
}
static int F_49 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_56 ) ;
return ! ( V_5 -> V_7 & V_34 ) ||
F_50 ( V_3 ) ;
}
static struct V_37 *
F_51 ( struct V_156 * V_157 , struct V_1 * V_2 )
{
struct V_37 * V_37 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_158 = NULL ;
char * V_79 , * V_159 ;
char V_160 ;
V_158 = F_52 ( V_157 , V_5 ,
F_3 ( V_5 ) ) ;
if ( V_158 == NULL )
return F_53 ( - V_29 ) ;
F_9 ( 1 , L_59 , V_158 ) ;
V_160 = F_54 ( V_5 ) ;
V_37 = F_55 ( V_2 -> V_28 ) ;
V_159 = V_79 = V_158 ;
do {
struct V_3 * V_161 = V_37 -> V_162 ;
struct V_37 * V_163 ;
if ( ! V_161 ) {
F_56 ( V_37 ) ;
V_37 = F_53 ( - V_164 ) ;
break;
}
while ( * V_79 == V_160 )
V_79 ++ ;
if ( ! * V_79 )
break;
V_159 = V_79 ++ ;
while ( * V_79 && * V_79 != V_160 )
V_79 ++ ;
F_57 ( & V_161 -> V_165 ) ;
V_163 = F_58 ( V_159 , V_37 , V_79 - V_159 ) ;
F_59 ( & V_161 -> V_165 ) ;
F_56 ( V_37 ) ;
V_37 = V_163 ;
} while ( ! F_5 ( V_37 ) );
F_60 ( V_158 ) ;
return V_37 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_154 )
{
struct V_166 * V_167 = V_154 ;
V_2 -> V_168 = V_167 -> V_5 ;
return F_62 ( V_2 , NULL ) ;
}
static struct V_37 *
F_63 ( struct V_169 * V_170 ,
int V_153 , const char * V_171 , void * V_154 )
{
int V_6 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_156 * V_172 ;
struct V_166 V_167 ;
struct V_37 * V_104 ;
F_9 ( 1 , L_60 , V_171 , V_153 ) ;
V_172 = F_64 ( ( char * ) V_154 , V_171 ) ;
if ( F_5 ( V_172 ) )
return F_65 ( V_172 ) ;
V_5 = F_66 ( sizeof( struct V_4 ) , V_63 ) ;
if ( V_5 == NULL ) {
V_104 = F_53 ( - V_29 ) ;
goto V_173;
}
V_5 -> V_174 = F_67 ( V_154 , V_175 , V_63 ) ;
if ( V_5 -> V_174 == NULL ) {
V_104 = F_53 ( - V_29 ) ;
goto V_176;
}
F_68 ( V_172 , V_5 ) ;
V_6 = F_69 ( V_5 , V_172 ) ;
if ( V_6 ) {
if ( ! ( V_153 & V_177 ) )
F_10 ( 1 , L_61 , V_6 ) ;
V_104 = F_53 ( V_6 ) ;
goto V_178;
}
V_167 . V_157 = V_172 ;
V_167 . V_5 = V_5 ;
V_167 . V_153 = V_153 ;
V_2 = F_70 ( V_170 , V_179 , F_61 , & V_167 ) ;
if ( F_5 ( V_2 ) ) {
V_104 = F_65 ( V_2 ) ;
F_13 ( V_5 ) ;
goto V_180;
}
if ( V_2 -> V_28 ) {
F_9 ( 1 , L_62 ) ;
F_13 ( V_5 ) ;
} else {
V_2 -> V_9 = V_153 ;
V_2 -> V_9 |= V_155 | V_181 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 ) {
V_104 = F_53 ( V_6 ) ;
goto V_182;
}
V_2 -> V_9 |= V_183 ;
}
V_104 = F_51 ( V_172 , V_2 ) ;
if ( F_5 ( V_104 ) )
goto V_182;
F_9 ( 1 , L_63 , V_104 ) ;
goto V_180;
V_182:
F_71 ( V_2 ) ;
V_180:
F_72 ( V_172 ) ;
return V_104 ;
V_178:
F_60 ( V_5 -> V_174 ) ;
V_176:
F_60 ( V_5 ) ;
V_173:
F_73 ( V_172 -> V_184 ) ;
goto V_180;
}
static T_1 F_74 ( struct V_185 * V_186 , const struct V_187 * V_188 ,
unsigned long V_189 , T_2 V_190 )
{
struct V_3 * V_3 = V_186 -> V_191 -> V_192 . V_37 -> V_162 ;
T_1 V_193 ;
int V_6 ;
V_193 = F_75 ( V_186 , V_188 , V_189 , V_190 ) ;
if ( F_31 ( V_3 ) -> V_194 )
return V_193 ;
V_6 = F_76 ( V_3 -> V_195 ) ;
if ( V_6 )
F_9 ( 1 , L_64 , V_6 , V_3 ) ;
return V_193 ;
}
static T_2 F_77 ( struct V_196 * V_196 , T_2 V_197 , int V_198 )
{
if ( V_198 != V_199 && V_198 != V_200 ) {
int V_6 ;
struct V_3 * V_3 = V_196 -> V_192 . V_37 -> V_162 ;
if ( ! F_31 ( V_3 ) -> V_201 && V_3 -> V_195 &&
V_3 -> V_195 -> V_202 != 0 ) {
V_6 = F_78 ( V_3 -> V_195 ) ;
if ( V_6 ) {
F_79 ( V_3 -> V_195 , V_6 ) ;
return V_6 ;
}
}
F_31 ( V_3 ) -> time = 0 ;
V_6 = F_80 ( V_196 ) ;
if ( V_6 < 0 )
return ( T_2 ) V_6 ;
}
return F_81 ( V_196 , V_197 , V_198 ) ;
}
static int F_82 ( struct V_196 * V_196 , long V_203 , struct V_204 * * V_205 )
{
struct V_3 * V_3 = V_196 -> V_192 . V_37 -> V_162 ;
struct V_206 * V_207 = V_196 -> V_208 ;
if ( ! ( F_83 ( V_3 -> V_209 ) ) )
return - V_210 ;
if ( ( ( V_203 == V_211 ) &&
( F_31 ( V_3 ) -> V_201 ) ) ||
( ( V_203 == V_212 ) &&
( F_31 ( V_3 ) -> V_194 ) ) )
return F_84 ( V_196 , V_203 , V_205 ) ;
else if ( F_85 ( V_207 -> V_213 ) -> V_214 &&
! F_31 ( V_3 ) -> V_201 )
return F_84 ( V_196 , V_203 , V_205 ) ;
else
return - V_215 ;
}
static void
F_86 ( void * V_3 )
{
struct V_60 * V_216 = V_3 ;
F_87 ( & V_216 -> V_67 ) ;
F_27 ( & V_216 -> V_217 ) ;
F_88 ( & V_216 -> V_218 ) ;
}
static int
F_89 ( void )
{
V_62 = F_90 ( L_65 ,
sizeof( struct V_60 ) ,
0 , ( V_219 |
V_220 ) ,
F_86 ) ;
if ( V_62 == NULL )
return - V_29 ;
return 0 ;
}
static void
F_91 ( void )
{
F_92 ( V_62 ) ;
}
static int
F_93 ( void )
{
if ( V_221 < 8192 ) {
V_221 = 8192 ;
} else if ( V_221 > 1024 * 127 ) {
V_221 = 1024 * 127 ;
} else {
V_221 &= 0x1FE00 ;
}
V_222 = F_90 ( L_66 ,
V_221 +
V_223 , 0 ,
V_224 , NULL ) ;
if ( V_222 == NULL )
return - V_29 ;
if ( V_225 < 1 )
V_225 = 1 ;
else if ( V_225 > 64 ) {
V_225 = 64 ;
F_10 ( 1 , L_67 ) ;
}
V_226 = F_94 ( V_225 ,
V_222 ) ;
if ( V_226 == NULL ) {
F_92 ( V_222 ) ;
return - V_29 ;
}
V_227 = F_90 ( L_68 ,
V_228 , 0 , V_224 ,
NULL ) ;
if ( V_227 == NULL ) {
F_95 ( V_226 ) ;
F_92 ( V_222 ) ;
return - V_29 ;
}
if ( V_229 < 2 )
V_229 = 2 ;
else if ( V_229 > 256 ) {
V_229 = 256 ;
F_9 ( 1 , L_69 ) ;
}
V_230 = F_94 ( V_229 ,
V_227 ) ;
if ( V_230 == NULL ) {
F_95 ( V_226 ) ;
F_92 ( V_222 ) ;
F_92 ( V_227 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_96 ( void )
{
F_95 ( V_226 ) ;
F_92 ( V_222 ) ;
F_95 ( V_230 ) ;
F_92 ( V_227 ) ;
}
static int
F_97 ( void )
{
V_231 = F_90 ( L_70 ,
sizeof( struct V_232 ) , 0 ,
V_224 , NULL ) ;
if ( V_231 == NULL )
return - V_29 ;
V_233 = F_94 ( 3 , V_231 ) ;
if ( V_233 == NULL ) {
F_92 ( V_231 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_98 ( void )
{
F_95 ( V_233 ) ;
F_92 ( V_231 ) ;
}
static int T_3
F_99 ( void )
{
int V_6 = 0 ;
F_100 () ;
F_27 ( & V_234 ) ;
#ifdef F_101
F_27 ( & V_235 ) ;
F_27 ( & V_236 ) ;
#endif
F_102 ( & V_237 , 0 ) ;
F_102 ( & V_238 , 0 ) ;
F_102 ( & V_239 , 0 ) ;
F_102 ( & V_240 , 0 ) ;
F_102 ( & V_241 , 0 ) ;
F_102 ( & V_242 , 0 ) ;
F_102 ( & V_243 , 0 ) ;
#ifdef F_103
F_102 ( & V_244 , 0 ) ;
F_102 ( & V_245 , 0 ) ;
#endif
F_102 ( & V_246 , 0 ) ;
V_247 = 0 ;
V_248 = 0 ;
V_249 = 0 ;
F_104 ( & V_147 ) ;
F_104 ( & V_250 ) ;
F_104 ( & V_251 ) ;
if ( V_252 < 2 ) {
V_252 = 2 ;
F_9 ( 1 , L_71 ) ;
} else if ( V_252 > V_253 ) {
V_252 = V_253 ;
F_9 ( 1 , L_72 , V_253 ) ;
}
V_254 = F_105 ( L_73 , V_255 | V_256 , 0 ) ;
if ( ! V_254 ) {
V_6 = - V_29 ;
goto V_257;
}
V_6 = F_106 () ;
if ( V_6 )
goto V_258;
V_6 = F_89 () ;
if ( V_6 )
goto V_259;
V_6 = F_97 () ;
if ( V_6 )
goto V_260;
V_6 = F_93 () ;
if ( V_6 )
goto V_261;
#ifdef F_107
V_6 = F_108 ( & V_262 ) ;
if ( V_6 )
goto V_263;
#endif
#ifdef F_109
V_6 = F_110 () ;
if ( V_6 )
goto V_264;
#endif
V_6 = F_111 ( & V_265 ) ;
if ( V_6 )
goto V_266;
return 0 ;
V_266:
#ifdef F_109
F_112 () ;
V_264:
#endif
#ifdef F_107
F_113 ( & V_262 ) ;
V_263:
#endif
F_96 () ;
V_261:
F_98 () ;
V_260:
F_91 () ;
V_259:
F_114 () ;
V_258:
F_115 ( V_254 ) ;
V_257:
F_116 () ;
return V_6 ;
}
static void T_4
F_117 ( void )
{
F_9 ( V_267 , L_74 ) ;
F_118 ( & V_265 ) ;
F_119 () ;
#ifdef F_109
F_120 () ;
F_112 () ;
#endif
#ifdef F_107
F_113 ( & V_262 ) ;
#endif
F_96 () ;
F_98 () ;
F_91 () ;
F_114 () ;
F_115 ( V_254 ) ;
F_116 () ;
}
