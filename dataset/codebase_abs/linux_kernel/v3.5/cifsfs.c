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
static void
F_41 ( struct V_78 * V_79 , struct V_4 * V_5 )
{
F_39 ( V_79 , L_16 ) ;
if ( V_5 -> V_7 & V_104 )
F_39 ( V_79 , L_17 ) ;
else if ( V_5 -> V_7 & V_105 )
F_39 ( V_79 , L_18 ) ;
else
F_39 ( V_79 , L_19 ) ;
}
static int
F_42 ( struct V_78 * V_79 , struct V_37 * V_106 )
{
struct V_4 * V_5 = F_2 ( V_106 -> V_40 ) ;
struct V_41 * V_42 = F_3 ( V_5 ) ;
struct V_107 * V_108 ;
V_108 = (struct V_107 * ) & V_42 -> V_11 -> V_81 -> V_108 ;
F_39 ( V_79 , L_20 , V_42 -> V_11 -> V_81 -> V_109 -> V_110 ) ;
F_40 ( V_79 , V_42 -> V_11 -> V_81 ) ;
F_41 ( V_79 , V_5 ) ;
F_39 ( V_79 , L_21 , V_42 -> V_111 ) ;
if ( V_5 -> V_7 & V_112 )
F_39 ( V_79 , L_22 ) ;
else if ( V_42 -> V_11 -> V_113 )
F_39 ( V_79 , L_23 , V_42 -> V_11 -> V_113 ) ;
if ( V_42 -> V_11 -> V_114 )
F_39 ( V_79 , L_24 , V_42 -> V_11 -> V_114 ) ;
if ( V_108 -> V_115 != V_116 ) {
struct V_82 * V_117 ;
struct V_85 * V_118 ;
V_117 = (struct V_82 * ) V_108 ;
V_118 = (struct V_85 * ) V_108 ;
if ( V_108 -> V_115 == V_91 )
F_39 ( V_79 , L_25 ,
& V_118 -> V_92 ) ;
else if ( V_108 -> V_115 == V_88 )
F_39 ( V_79 , L_26 ,
& V_117 -> V_89 . V_90 ) ;
else
F_39 ( V_79 , L_27 ,
( int ) ( V_108 -> V_115 ) ) ;
}
F_39 ( V_79 , L_28 , V_5 -> V_119 ) ;
if ( V_5 -> V_7 & V_120 )
F_39 ( V_79 , L_29 ) ;
else
F_39 ( V_79 , L_30 ) ;
F_39 ( V_79 , L_31 , V_5 -> V_121 ) ;
if ( V_5 -> V_7 & V_122 )
F_39 ( V_79 , L_32 ) ;
else
F_39 ( V_79 , L_33 ) ;
F_38 ( V_79 , V_42 -> V_11 -> V_81 ) ;
if ( ! V_42 -> V_123 )
F_39 ( V_79 , L_34 ,
V_5 -> V_124 ,
V_5 -> V_125 ) ;
if ( V_42 -> V_126 )
F_39 ( V_79 , L_35 ) ;
if ( V_42 -> V_30 )
F_39 ( V_79 , L_36 ) ;
if ( V_42 -> V_127 )
F_39 ( V_79 , L_37 ) ;
if ( V_42 -> V_123 )
F_39 ( V_79 , L_38 ) ;
else
F_39 ( V_79 , L_39 ) ;
if ( V_5 -> V_7 & V_128 )
F_39 ( V_79 , L_40 ) ;
if ( V_5 -> V_7 & V_129 )
F_39 ( V_79 , L_41 ) ;
if ( V_5 -> V_7 & V_34 )
F_39 ( V_79 , L_42 ) ;
if ( V_5 -> V_7 & V_130 )
F_39 ( V_79 , L_43 ) ;
if ( V_5 -> V_7 & V_131 )
F_39 ( V_79 , L_44 ) ;
if ( V_5 -> V_7 & V_132 )
F_39 ( V_79 , L_45 ) ;
if ( V_5 -> V_7 & V_133 )
F_39 ( V_79 , L_46 ) ;
if ( V_5 -> V_7 & V_134 )
F_39 ( V_79 , L_47 ) ;
if ( V_5 -> V_7 & V_135 )
F_39 ( V_79 , L_48 ) ;
if ( V_5 -> V_7 & V_136 )
F_39 ( V_79 , L_49 ) ;
if ( V_5 -> V_7 & V_137 )
F_39 ( V_79 , L_50 ) ;
if ( V_106 -> V_40 -> V_9 & V_10 )
F_39 ( V_79 , L_51 ) ;
if ( V_5 -> V_7 & V_138 )
F_39 ( V_79 , L_52 ) ;
if ( V_5 -> V_7 & V_139 )
F_39 ( V_79 , L_53 ) ;
if ( V_5 -> V_7 & V_140 )
F_39 ( V_79 , L_54 ) ;
if ( V_5 -> V_7 & V_57 )
F_39 ( V_79 , L_55 ) ;
if ( V_5 -> V_7 & V_141 )
F_39 ( V_79 , L_56 , V_5 -> V_142 ) ;
if ( V_5 -> V_7 & V_143 )
F_39 ( V_79 , L_57 , V_5 -> V_144 ) ;
F_39 ( V_79 , L_58 , V_5 -> V_145 ) ;
F_39 ( V_79 , L_59 , V_5 -> V_146 ) ;
F_39 ( V_79 , L_60 , V_5 -> V_147 / V_148 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_41 * V_42 ;
if ( V_5 == NULL )
return;
V_42 = F_3 ( V_5 ) ;
F_44 ( & V_149 ) ;
if ( ( V_42 -> V_150 > 1 ) || ( V_42 -> V_151 == V_152 ) ) {
F_45 ( & V_149 ) ;
return;
} else if ( V_42 -> V_150 == 1 )
V_42 -> V_151 = V_152 ;
F_45 ( & V_149 ) ;
if ( V_42 -> V_11 && V_42 -> V_11 -> V_81 ) {
F_9 ( 1 , L_61 ) ;
F_46 ( & V_42 -> V_11 -> V_81 -> V_153 ) ;
F_46 ( & V_42 -> V_11 -> V_81 -> V_154 ) ;
F_47 ( 1 ) ;
F_46 ( & V_42 -> V_11 -> V_81 -> V_154 ) ;
F_47 ( 1 ) ;
}
return;
}
static int F_48 ( struct V_78 * V_79 , struct V_37 * V_106 )
{
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int * V_155 , char * V_156 )
{
* V_155 |= V_157 ;
return 0 ;
}
static int F_50 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_56 ) ;
return ! ( V_5 -> V_7 & V_34 ) ||
F_51 ( V_3 ) ;
}
static struct V_37 *
F_52 ( struct V_158 * V_159 , struct V_1 * V_2 )
{
struct V_37 * V_37 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_160 = NULL ;
char * V_79 , * V_161 ;
char V_162 ;
V_160 = F_53 ( V_159 , V_5 ,
F_3 ( V_5 ) ) ;
if ( V_160 == NULL )
return F_54 ( - V_29 ) ;
F_9 ( 1 , L_62 , V_160 ) ;
V_162 = F_55 ( V_5 ) ;
V_37 = F_56 ( V_2 -> V_28 ) ;
V_161 = V_79 = V_160 ;
do {
struct V_3 * V_163 = V_37 -> V_164 ;
struct V_37 * V_165 ;
if ( ! V_163 ) {
F_57 ( V_37 ) ;
V_37 = F_54 ( - V_166 ) ;
break;
}
while ( * V_79 == V_162 )
V_79 ++ ;
if ( ! * V_79 )
break;
V_161 = V_79 ++ ;
while ( * V_79 && * V_79 != V_162 )
V_79 ++ ;
F_58 ( & V_163 -> V_167 ) ;
V_165 = F_59 ( V_161 , V_37 , V_79 - V_161 ) ;
F_60 ( & V_163 -> V_167 ) ;
F_57 ( V_37 ) ;
V_37 = V_165 ;
} while ( ! F_5 ( V_37 ) );
F_61 ( V_160 ) ;
return V_37 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_156 )
{
struct V_168 * V_169 = V_156 ;
V_2 -> V_170 = V_169 -> V_5 ;
return F_63 ( V_2 , NULL ) ;
}
static struct V_37 *
F_64 ( struct V_171 * V_172 ,
int V_155 , const char * V_173 , void * V_156 )
{
int V_6 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_158 * V_174 ;
struct V_168 V_169 ;
struct V_37 * V_106 ;
F_9 ( 1 , L_63 , V_173 , V_155 ) ;
V_174 = F_65 ( ( char * ) V_156 , V_173 ) ;
if ( F_5 ( V_174 ) )
return F_66 ( V_174 ) ;
V_5 = F_67 ( sizeof( struct V_4 ) , V_63 ) ;
if ( V_5 == NULL ) {
V_106 = F_54 ( - V_29 ) ;
goto V_175;
}
V_5 -> V_176 = F_68 ( V_156 , V_177 , V_63 ) ;
if ( V_5 -> V_176 == NULL ) {
V_106 = F_54 ( - V_29 ) ;
goto V_178;
}
F_69 ( V_174 , V_5 ) ;
V_6 = F_70 ( V_5 , V_174 ) ;
if ( V_6 ) {
if ( ! ( V_155 & V_179 ) )
F_10 ( 1 , L_64 , V_6 ) ;
V_106 = F_54 ( V_6 ) ;
goto V_180;
}
V_169 . V_159 = V_174 ;
V_169 . V_5 = V_5 ;
V_169 . V_155 = V_155 ;
V_2 = F_71 ( V_172 , V_181 , F_62 , & V_169 ) ;
if ( F_5 ( V_2 ) ) {
V_106 = F_66 ( V_2 ) ;
F_13 ( V_5 ) ;
goto V_182;
}
if ( V_2 -> V_28 ) {
F_9 ( 1 , L_65 ) ;
F_13 ( V_5 ) ;
} else {
V_2 -> V_9 = V_155 ;
V_2 -> V_9 |= V_157 | V_183 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 ) {
V_106 = F_54 ( V_6 ) ;
goto V_184;
}
V_2 -> V_9 |= V_185 ;
}
V_106 = F_52 ( V_174 , V_2 ) ;
if ( F_5 ( V_106 ) )
goto V_184;
F_9 ( 1 , L_66 , V_106 ) ;
goto V_182;
V_184:
F_72 ( V_2 ) ;
V_182:
F_73 ( V_174 ) ;
return V_106 ;
V_180:
F_61 ( V_5 -> V_176 ) ;
V_178:
F_61 ( V_5 ) ;
V_175:
F_74 ( V_174 -> V_186 ) ;
goto V_182;
}
static T_1 F_75 ( struct V_187 * V_188 , const struct V_189 * V_190 ,
unsigned long V_191 , T_2 V_192 )
{
struct V_3 * V_3 = V_188 -> V_193 -> V_194 . V_37 -> V_164 ;
T_1 V_195 ;
int V_6 ;
V_195 = F_76 ( V_188 , V_190 , V_191 , V_192 ) ;
if ( F_31 ( V_3 ) -> V_196 )
return V_195 ;
V_6 = F_77 ( V_3 -> V_197 ) ;
if ( V_6 )
F_9 ( 1 , L_67 , V_6 , V_3 ) ;
return V_195 ;
}
static T_2 F_78 ( struct V_198 * V_198 , T_2 V_199 , int V_200 )
{
if ( V_200 != V_201 && V_200 != V_202 ) {
int V_6 ;
struct V_3 * V_3 = V_198 -> V_194 . V_37 -> V_164 ;
if ( ! F_31 ( V_3 ) -> V_203 && V_3 -> V_197 &&
V_3 -> V_197 -> V_204 != 0 ) {
V_6 = F_79 ( V_3 -> V_197 ) ;
if ( V_6 ) {
F_80 ( V_3 -> V_197 , V_6 ) ;
return V_6 ;
}
}
F_31 ( V_3 ) -> time = 0 ;
V_6 = F_81 ( V_198 ) ;
if ( V_6 < 0 )
return ( T_2 ) V_6 ;
}
return F_82 ( V_198 , V_199 , V_200 ) ;
}
static int F_83 ( struct V_198 * V_198 , long V_205 , struct V_206 * * V_207 )
{
struct V_3 * V_3 = V_198 -> V_194 . V_37 -> V_164 ;
struct V_208 * V_209 = V_198 -> V_210 ;
if ( ! ( F_84 ( V_3 -> V_211 ) ) )
return - V_212 ;
if ( ( ( V_205 == V_213 ) &&
( F_31 ( V_3 ) -> V_203 ) ) ||
( ( V_205 == V_214 ) &&
( F_31 ( V_3 ) -> V_196 ) ) )
return F_85 ( V_198 , V_205 , V_207 ) ;
else if ( F_86 ( V_209 -> V_215 ) -> V_216 &&
! F_31 ( V_3 ) -> V_203 )
return F_85 ( V_198 , V_205 , V_207 ) ;
else
return - V_217 ;
}
static void
F_87 ( void * V_3 )
{
struct V_60 * V_218 = V_3 ;
F_88 ( & V_218 -> V_67 ) ;
F_89 ( & V_218 -> V_219 ) ;
}
static int
F_90 ( void )
{
V_62 = F_91 ( L_68 ,
sizeof( struct V_60 ) ,
0 , ( V_220 |
V_221 ) ,
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
if ( V_222 < 8192 ) {
V_222 = 8192 ;
} else if ( V_222 > 1024 * 127 ) {
V_222 = 1024 * 127 ;
} else {
V_222 &= 0x1FE00 ;
}
V_223 = F_91 ( L_69 ,
V_222 +
V_224 , 0 ,
V_225 , NULL ) ;
if ( V_223 == NULL )
return - V_29 ;
if ( V_226 < 1 )
V_226 = 1 ;
else if ( V_226 > 64 ) {
V_226 = 64 ;
F_10 ( 1 , L_70 ) ;
}
V_227 = F_95 ( V_226 ,
V_223 ) ;
if ( V_227 == NULL ) {
F_93 ( V_223 ) ;
return - V_29 ;
}
V_228 = F_91 ( L_71 ,
V_229 , 0 , V_225 ,
NULL ) ;
if ( V_228 == NULL ) {
F_96 ( V_227 ) ;
F_93 ( V_223 ) ;
return - V_29 ;
}
if ( V_230 < 2 )
V_230 = 2 ;
else if ( V_230 > 256 ) {
V_230 = 256 ;
F_9 ( 1 , L_72 ) ;
}
V_231 = F_95 ( V_230 ,
V_228 ) ;
if ( V_231 == NULL ) {
F_96 ( V_227 ) ;
F_93 ( V_223 ) ;
F_93 ( V_228 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_97 ( void )
{
F_96 ( V_227 ) ;
F_93 ( V_223 ) ;
F_96 ( V_231 ) ;
F_93 ( V_228 ) ;
}
static int
F_98 ( void )
{
V_232 = F_91 ( L_73 ,
sizeof( struct V_233 ) , 0 ,
V_225 , NULL ) ;
if ( V_232 == NULL )
return - V_29 ;
V_234 = F_95 ( 3 , V_232 ) ;
if ( V_234 == NULL ) {
F_93 ( V_232 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_99 ( void )
{
F_96 ( V_234 ) ;
F_93 ( V_232 ) ;
}
static int T_3
F_100 ( void )
{
int V_6 = 0 ;
F_101 () ;
F_27 ( & V_235 ) ;
#ifdef F_102
F_27 ( & V_236 ) ;
F_27 ( & V_237 ) ;
#endif
F_103 ( & V_238 , 0 ) ;
F_103 ( & V_239 , 0 ) ;
F_103 ( & V_240 , 0 ) ;
F_103 ( & V_241 , 0 ) ;
F_103 ( & V_242 , 0 ) ;
F_103 ( & V_243 , 0 ) ;
F_103 ( & V_244 , 0 ) ;
#ifdef F_104
F_103 ( & V_245 , 0 ) ;
F_103 ( & V_246 , 0 ) ;
#endif
F_103 ( & V_247 , 0 ) ;
V_248 = 0 ;
V_249 = 0 ;
V_250 = 0 ;
F_105 ( & V_149 ) ;
F_105 ( & V_251 ) ;
F_105 ( & V_252 ) ;
if ( V_253 < 2 ) {
V_253 = 2 ;
F_9 ( 1 , L_74 ) ;
} else if ( V_253 > V_254 ) {
V_253 = V_254 ;
F_9 ( 1 , L_75 , V_254 ) ;
}
V_255 = F_106 ( L_76 , V_256 | V_257 , 0 ) ;
if ( ! V_255 ) {
V_6 = - V_29 ;
goto V_258;
}
V_6 = F_107 () ;
if ( V_6 )
goto V_259;
V_6 = F_90 () ;
if ( V_6 )
goto V_260;
V_6 = F_98 () ;
if ( V_6 )
goto V_261;
V_6 = F_94 () ;
if ( V_6 )
goto V_262;
#ifdef F_108
V_6 = F_109 ( & V_263 ) ;
if ( V_6 )
goto V_264;
#endif
#ifdef F_110
V_6 = F_111 () ;
if ( V_6 )
goto V_265;
#endif
V_6 = F_112 ( & V_266 ) ;
if ( V_6 )
goto V_267;
return 0 ;
V_267:
#ifdef F_110
F_113 () ;
V_265:
#endif
#ifdef F_108
F_114 ( & V_263 ) ;
V_264:
#endif
F_97 () ;
V_262:
F_99 () ;
V_261:
F_92 () ;
V_260:
F_115 () ;
V_259:
F_116 ( V_255 ) ;
V_258:
F_117 () ;
return V_6 ;
}
static void T_4
F_118 ( void )
{
F_9 ( V_268 , L_77 ) ;
F_119 ( & V_266 ) ;
F_120 () ;
#ifdef F_110
F_121 () ;
F_113 () ;
#endif
#ifdef F_108
F_114 ( & V_263 ) ;
#endif
F_97 () ;
F_99 () ;
F_92 () ;
F_115 () ;
F_116 ( V_255 ) ;
F_117 () ;
}
