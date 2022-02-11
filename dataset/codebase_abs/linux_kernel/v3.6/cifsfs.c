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
unsigned int V_44 ;
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
F_35 ( & V_3 -> V_76 , 0 ) ;
F_36 ( V_3 ) ;
F_37 ( V_3 ) ;
}
static void
F_38 ( struct V_77 * V_78 , struct V_79 * V_80 )
{
struct V_81 * V_82 = (struct V_81 * ) & V_80 -> V_83 ;
struct V_84 * V_85 = (struct V_84 * ) & V_80 -> V_83 ;
F_39 ( V_78 , L_3 ) ;
switch ( V_80 -> V_83 . V_86 ) {
case V_87 :
F_39 ( V_78 , L_4 , & V_82 -> V_88 . V_89 ) ;
break;
case V_90 :
F_39 ( V_78 , L_5 , & V_85 -> V_91 . V_92 ) ;
if ( V_85 -> V_93 )
F_39 ( V_78 , L_6 , V_85 -> V_93 ) ;
break;
default:
F_39 ( V_78 , L_7 ) ;
}
}
static void
F_40 ( struct V_77 * V_78 , struct V_79 * V_80 )
{
F_39 ( V_78 , L_8 ) ;
switch ( V_80 -> V_94 ) {
case V_95 :
F_39 ( V_78 , L_9 ) ;
break;
case V_96 :
F_39 ( V_78 , L_10 ) ;
break;
case V_97 :
F_39 ( V_78 , L_11 ) ;
break;
case V_98 :
F_39 ( V_78 , L_12 ) ;
break;
case V_99 :
F_39 ( V_78 , L_13 ) ;
break;
default:
F_39 ( V_78 , L_14 ) ;
break;
}
if ( V_80 -> V_100 & ( V_101 | V_102 ) )
F_39 ( V_78 , L_15 ) ;
}
static void
F_41 ( struct V_77 * V_78 , struct V_4 * V_5 )
{
F_39 ( V_78 , L_16 ) ;
if ( V_5 -> V_7 & V_103 )
F_39 ( V_78 , L_17 ) ;
else if ( V_5 -> V_7 & V_104 )
F_39 ( V_78 , L_18 ) ;
else
F_39 ( V_78 , L_19 ) ;
}
static int
F_42 ( struct V_77 * V_78 , struct V_37 * V_105 )
{
struct V_4 * V_5 = F_2 ( V_105 -> V_40 ) ;
struct V_41 * V_42 = F_3 ( V_5 ) ;
struct V_106 * V_107 ;
V_107 = (struct V_106 * ) & V_42 -> V_11 -> V_80 -> V_107 ;
F_39 ( V_78 , L_20 , V_42 -> V_11 -> V_80 -> V_108 -> V_109 ) ;
F_40 ( V_78 , V_42 -> V_11 -> V_80 ) ;
F_41 ( V_78 , V_5 ) ;
F_39 ( V_78 , L_21 , V_42 -> V_110 ) ;
if ( V_5 -> V_7 & V_111 )
F_39 ( V_78 , L_22 ) ;
else if ( V_42 -> V_11 -> V_112 )
F_39 ( V_78 , L_23 , V_42 -> V_11 -> V_112 ) ;
if ( V_42 -> V_11 -> V_113 )
F_39 ( V_78 , L_24 , V_42 -> V_11 -> V_113 ) ;
if ( V_107 -> V_114 != V_115 ) {
struct V_81 * V_116 ;
struct V_84 * V_117 ;
V_116 = (struct V_81 * ) V_107 ;
V_117 = (struct V_84 * ) V_107 ;
if ( V_107 -> V_114 == V_90 )
F_39 ( V_78 , L_25 ,
& V_117 -> V_91 ) ;
else if ( V_107 -> V_114 == V_87 )
F_39 ( V_78 , L_26 ,
& V_116 -> V_88 . V_89 ) ;
else
F_39 ( V_78 , L_27 ,
( int ) ( V_107 -> V_114 ) ) ;
}
F_39 ( V_78 , L_28 , V_5 -> V_118 ) ;
if ( V_5 -> V_7 & V_119 )
F_39 ( V_78 , L_29 ) ;
else
F_39 ( V_78 , L_30 ) ;
F_39 ( V_78 , L_31 , V_5 -> V_120 ) ;
if ( V_5 -> V_7 & V_121 )
F_39 ( V_78 , L_32 ) ;
else
F_39 ( V_78 , L_33 ) ;
F_38 ( V_78 , V_42 -> V_11 -> V_80 ) ;
if ( ! V_42 -> V_122 )
F_39 ( V_78 , L_34 ,
V_5 -> V_123 ,
V_5 -> V_124 ) ;
if ( V_42 -> V_125 )
F_39 ( V_78 , L_35 ) ;
if ( V_42 -> V_30 )
F_39 ( V_78 , L_36 ) ;
if ( V_42 -> V_126 )
F_39 ( V_78 , L_37 ) ;
if ( V_42 -> V_122 )
F_39 ( V_78 , L_38 ) ;
else
F_39 ( V_78 , L_39 ) ;
if ( V_5 -> V_7 & V_127 )
F_39 ( V_78 , L_40 ) ;
if ( V_5 -> V_7 & V_128 )
F_39 ( V_78 , L_41 ) ;
if ( V_5 -> V_7 & V_34 )
F_39 ( V_78 , L_42 ) ;
if ( V_5 -> V_7 & V_129 )
F_39 ( V_78 , L_43 ) ;
if ( V_5 -> V_7 & V_130 )
F_39 ( V_78 , L_44 ) ;
if ( V_5 -> V_7 & V_131 )
F_39 ( V_78 , L_45 ) ;
if ( V_5 -> V_7 & V_132 )
F_39 ( V_78 , L_46 ) ;
if ( V_5 -> V_7 & V_133 )
F_39 ( V_78 , L_47 ) ;
if ( V_5 -> V_7 & V_134 )
F_39 ( V_78 , L_48 ) ;
if ( V_5 -> V_7 & V_135 )
F_39 ( V_78 , L_49 ) ;
if ( V_5 -> V_7 & V_136 )
F_39 ( V_78 , L_50 ) ;
if ( V_105 -> V_40 -> V_9 & V_10 )
F_39 ( V_78 , L_51 ) ;
if ( V_5 -> V_7 & V_137 )
F_39 ( V_78 , L_52 ) ;
if ( V_5 -> V_7 & V_138 )
F_39 ( V_78 , L_53 ) ;
if ( V_5 -> V_7 & V_139 )
F_39 ( V_78 , L_54 ) ;
if ( V_5 -> V_7 & V_57 )
F_39 ( V_78 , L_55 ) ;
if ( V_5 -> V_7 & V_140 )
F_39 ( V_78 , L_56 , V_5 -> V_141 ) ;
if ( V_5 -> V_7 & V_142 )
F_39 ( V_78 , L_57 , V_5 -> V_143 ) ;
F_39 ( V_78 , L_58 , V_5 -> V_144 ) ;
F_39 ( V_78 , L_59 , V_5 -> V_145 ) ;
F_39 ( V_78 , L_60 , V_5 -> V_146 / V_147 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_41 * V_42 ;
if ( V_5 == NULL )
return;
V_42 = F_3 ( V_5 ) ;
F_44 ( & V_148 ) ;
if ( ( V_42 -> V_149 > 1 ) || ( V_42 -> V_150 == V_151 ) ) {
F_45 ( & V_148 ) ;
return;
} else if ( V_42 -> V_149 == 1 )
V_42 -> V_150 = V_151 ;
F_45 ( & V_148 ) ;
if ( V_42 -> V_11 && V_42 -> V_11 -> V_80 ) {
F_9 ( 1 , L_61 ) ;
F_46 ( & V_42 -> V_11 -> V_80 -> V_152 ) ;
F_46 ( & V_42 -> V_11 -> V_80 -> V_153 ) ;
F_47 ( 1 ) ;
F_46 ( & V_42 -> V_11 -> V_80 -> V_153 ) ;
F_47 ( 1 ) ;
}
return;
}
static int F_48 ( struct V_77 * V_78 , struct V_37 * V_105 )
{
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int * V_154 , char * V_155 )
{
* V_154 |= V_156 ;
return 0 ;
}
static int F_50 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_56 ) ;
return ! ( V_5 -> V_7 & V_34 ) ||
F_51 ( V_3 ) ;
}
static struct V_37 *
F_52 ( struct V_157 * V_158 , struct V_1 * V_2 )
{
struct V_37 * V_37 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_159 = NULL ;
char * V_78 , * V_160 ;
char V_161 ;
V_159 = F_53 ( V_158 , V_5 ,
F_3 ( V_5 ) ) ;
if ( V_159 == NULL )
return F_54 ( - V_29 ) ;
F_9 ( 1 , L_62 , V_159 ) ;
V_161 = F_55 ( V_5 ) ;
V_37 = F_56 ( V_2 -> V_28 ) ;
V_160 = V_78 = V_159 ;
do {
struct V_3 * V_162 = V_37 -> V_163 ;
struct V_37 * V_164 ;
if ( ! V_162 ) {
F_57 ( V_37 ) ;
V_37 = F_54 ( - V_165 ) ;
break;
}
while ( * V_78 == V_161 )
V_78 ++ ;
if ( ! * V_78 )
break;
V_160 = V_78 ++ ;
while ( * V_78 && * V_78 != V_161 )
V_78 ++ ;
F_58 ( & V_162 -> V_166 ) ;
V_164 = F_59 ( V_160 , V_37 , V_78 - V_160 ) ;
F_60 ( & V_162 -> V_166 ) ;
F_57 ( V_37 ) ;
V_37 = V_164 ;
} while ( ! F_5 ( V_37 ) );
F_61 ( V_159 ) ;
return V_37 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_155 )
{
struct V_167 * V_168 = V_155 ;
V_2 -> V_169 = V_168 -> V_5 ;
return F_63 ( V_2 , NULL ) ;
}
static struct V_37 *
F_64 ( struct V_170 * V_171 ,
int V_154 , const char * V_172 , void * V_155 )
{
int V_6 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_157 * V_173 ;
struct V_167 V_168 ;
struct V_37 * V_105 ;
F_9 ( 1 , L_63 , V_172 , V_154 ) ;
V_173 = F_65 ( ( char * ) V_155 , V_172 ) ;
if ( F_5 ( V_173 ) )
return F_66 ( V_173 ) ;
V_5 = F_67 ( sizeof( struct V_4 ) , V_63 ) ;
if ( V_5 == NULL ) {
V_105 = F_54 ( - V_29 ) ;
goto V_174;
}
V_5 -> V_175 = F_68 ( V_155 , V_176 , V_63 ) ;
if ( V_5 -> V_175 == NULL ) {
V_105 = F_54 ( - V_29 ) ;
goto V_177;
}
F_69 ( V_173 , V_5 ) ;
V_6 = F_70 ( V_5 , V_173 ) ;
if ( V_6 ) {
if ( ! ( V_154 & V_178 ) )
F_10 ( 1 , L_64 , V_6 ) ;
V_105 = F_54 ( V_6 ) ;
goto V_179;
}
V_168 . V_158 = V_173 ;
V_168 . V_5 = V_5 ;
V_168 . V_154 = V_154 ;
V_154 |= V_156 | V_180 ;
V_2 = F_71 ( V_171 , V_181 , F_62 , V_154 , & V_168 ) ;
if ( F_5 ( V_2 ) ) {
V_105 = F_66 ( V_2 ) ;
F_13 ( V_5 ) ;
goto V_182;
}
if ( V_2 -> V_28 ) {
F_9 ( 1 , L_65 ) ;
F_13 ( V_5 ) ;
} else {
V_6 = F_1 ( V_2 ) ;
if ( V_6 ) {
V_105 = F_54 ( V_6 ) ;
goto V_183;
}
V_2 -> V_9 |= V_184 ;
}
V_105 = F_52 ( V_173 , V_2 ) ;
if ( F_5 ( V_105 ) )
goto V_183;
F_9 ( 1 , L_66 , V_105 ) ;
goto V_182;
V_183:
F_72 ( V_2 ) ;
V_182:
F_73 ( V_173 ) ;
return V_105 ;
V_179:
F_61 ( V_5 -> V_175 ) ;
V_177:
F_61 ( V_5 ) ;
V_174:
F_74 ( V_173 -> V_185 ) ;
goto V_182;
}
static T_1 F_75 ( struct V_186 * V_187 , const struct V_188 * V_189 ,
unsigned long V_190 , T_2 V_191 )
{
struct V_3 * V_3 = V_187 -> V_192 -> V_193 . V_37 -> V_163 ;
T_1 V_194 ;
int V_6 ;
V_194 = F_76 ( V_187 , V_189 , V_190 , V_191 ) ;
if ( F_31 ( V_3 ) -> V_195 )
return V_194 ;
V_6 = F_77 ( V_3 -> V_196 ) ;
if ( V_6 )
F_9 ( 1 , L_67 , V_6 , V_3 ) ;
return V_194 ;
}
static T_2 F_78 ( struct V_197 * V_197 , T_2 V_198 , int V_199 )
{
if ( V_199 != V_200 && V_199 != V_201 ) {
int V_6 ;
struct V_3 * V_3 = V_197 -> V_193 . V_37 -> V_163 ;
if ( ! F_31 ( V_3 ) -> V_202 && V_3 -> V_196 &&
V_3 -> V_196 -> V_203 != 0 ) {
V_6 = F_79 ( V_3 -> V_196 ) ;
if ( V_6 ) {
F_80 ( V_3 -> V_196 , V_6 ) ;
return V_6 ;
}
}
F_31 ( V_3 ) -> time = 0 ;
V_6 = F_81 ( V_197 ) ;
if ( V_6 < 0 )
return ( T_2 ) V_6 ;
}
return F_82 ( V_197 , V_198 , V_199 ) ;
}
static int F_83 ( struct V_197 * V_197 , long V_204 , struct V_205 * * V_206 )
{
struct V_3 * V_3 = V_197 -> V_193 . V_37 -> V_163 ;
struct V_207 * V_208 = V_197 -> V_209 ;
if ( ! ( F_84 ( V_3 -> V_210 ) ) )
return - V_211 ;
if ( ( ( V_204 == V_212 ) &&
( F_31 ( V_3 ) -> V_202 ) ) ||
( ( V_204 == V_213 ) &&
( F_31 ( V_3 ) -> V_195 ) ) )
return F_85 ( V_197 , V_204 , V_206 ) ;
else if ( F_86 ( V_208 -> V_214 ) -> V_215 &&
! F_31 ( V_3 ) -> V_202 )
return F_85 ( V_197 , V_204 , V_206 ) ;
else
return - V_216 ;
}
static void
F_87 ( void * V_3 )
{
struct V_60 * V_217 = V_3 ;
F_88 ( & V_217 -> V_67 ) ;
F_89 ( & V_217 -> V_218 ) ;
}
static int
F_90 ( void )
{
V_62 = F_91 ( L_68 ,
sizeof( struct V_60 ) ,
0 , ( V_219 |
V_220 ) ,
F_87 ) ;
if ( V_62 == NULL )
return - V_29 ;
return 0 ;
}
static void
F_92 ( void )
{
F_93 ( V_62 ) ;
}
static int
F_94 ( void )
{
T_3 V_221 = V_222 ;
#ifdef F_95
V_221 = V_223 ;
#endif
if ( V_224 < 8192 ) {
V_224 = 8192 ;
} else if ( V_224 > 1024 * 127 ) {
V_224 = 1024 * 127 ;
} else {
V_224 &= 0x1FE00 ;
}
V_225 = F_91 ( L_69 ,
V_224 + V_221 , 0 ,
V_226 , NULL ) ;
if ( V_225 == NULL )
return - V_29 ;
if ( V_227 < 1 )
V_227 = 1 ;
else if ( V_227 > 64 ) {
V_227 = 64 ;
F_10 ( 1 , L_70 ) ;
}
V_228 = F_96 ( V_227 ,
V_225 ) ;
if ( V_228 == NULL ) {
F_93 ( V_225 ) ;
return - V_29 ;
}
V_229 = F_91 ( L_71 ,
V_230 , 0 , V_226 ,
NULL ) ;
if ( V_229 == NULL ) {
F_97 ( V_228 ) ;
F_93 ( V_225 ) ;
return - V_29 ;
}
if ( V_231 < 2 )
V_231 = 2 ;
else if ( V_231 > 256 ) {
V_231 = 256 ;
F_9 ( 1 , L_72 ) ;
}
V_232 = F_96 ( V_231 ,
V_229 ) ;
if ( V_232 == NULL ) {
F_97 ( V_228 ) ;
F_93 ( V_225 ) ;
F_93 ( V_229 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_98 ( void )
{
F_97 ( V_228 ) ;
F_93 ( V_225 ) ;
F_97 ( V_232 ) ;
F_93 ( V_229 ) ;
}
static int
F_99 ( void )
{
V_233 = F_91 ( L_73 ,
sizeof( struct V_234 ) , 0 ,
V_226 , NULL ) ;
if ( V_233 == NULL )
return - V_29 ;
V_235 = F_96 ( 3 , V_233 ) ;
if ( V_235 == NULL ) {
F_93 ( V_233 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_100 ( void )
{
F_97 ( V_235 ) ;
F_93 ( V_233 ) ;
}
static int T_4
F_101 ( void )
{
int V_6 = 0 ;
F_102 () ;
F_27 ( & V_236 ) ;
#ifdef F_103
F_27 ( & V_237 ) ;
F_27 ( & V_238 ) ;
#endif
F_104 ( & V_239 , 0 ) ;
F_104 ( & V_240 , 0 ) ;
F_104 ( & V_241 , 0 ) ;
F_104 ( & V_242 , 0 ) ;
F_104 ( & V_243 , 0 ) ;
F_104 ( & V_244 , 0 ) ;
F_104 ( & V_245 , 0 ) ;
#ifdef F_105
F_104 ( & V_246 , 0 ) ;
F_104 ( & V_247 , 0 ) ;
#endif
F_104 ( & V_248 , 0 ) ;
V_249 = 0 ;
V_250 = 0 ;
V_251 = 0 ;
F_106 ( & V_148 ) ;
F_106 ( & V_252 ) ;
F_106 ( & V_253 ) ;
if ( V_254 < 2 ) {
V_254 = 2 ;
F_9 ( 1 , L_74 ) ;
} else if ( V_254 > V_255 ) {
V_254 = V_255 ;
F_9 ( 1 , L_75 , V_255 ) ;
}
V_256 = F_107 ( L_76 , V_257 | V_258 , 0 ) ;
if ( ! V_256 ) {
V_6 = - V_29 ;
goto V_259;
}
V_6 = F_108 () ;
if ( V_6 )
goto V_260;
V_6 = F_90 () ;
if ( V_6 )
goto V_261;
V_6 = F_99 () ;
if ( V_6 )
goto V_262;
V_6 = F_94 () ;
if ( V_6 )
goto V_263;
#ifdef F_109
V_6 = F_110 ( & V_264 ) ;
if ( V_6 )
goto V_265;
#endif
#ifdef F_111
V_6 = F_112 () ;
if ( V_6 )
goto V_266;
#endif
V_6 = F_113 ( & V_267 ) ;
if ( V_6 )
goto V_268;
return 0 ;
V_268:
#ifdef F_111
F_114 () ;
V_266:
#endif
#ifdef F_109
F_115 ( & V_264 ) ;
V_265:
#endif
F_98 () ;
V_263:
F_100 () ;
V_262:
F_92 () ;
V_261:
F_116 () ;
V_260:
F_117 ( V_256 ) ;
V_259:
F_118 () ;
return V_6 ;
}
static void T_5
F_119 ( void )
{
F_9 ( V_269 , L_77 ) ;
F_120 ( & V_267 ) ;
F_121 () ;
#ifdef F_111
F_122 () ;
F_114 () ;
#endif
#ifdef F_109
F_115 ( & V_264 ) ;
#endif
F_98 () ;
F_100 () ;
F_92 () ;
F_116 () ;
F_117 ( V_256 ) ;
F_118 () ;
}
