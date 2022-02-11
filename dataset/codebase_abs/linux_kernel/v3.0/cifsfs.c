void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( & V_4 -> V_5 ) == 1 )
F_4 ( & V_2 -> V_6 ) ;
}
void
F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_6 ( & V_4 -> V_5 ) )
F_7 ( V_2 ) ;
}
static int
F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_7 ;
struct V_3 * V_8 ;
int V_9 = 0 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_10 & V_11 )
V_2 -> V_12 |= V_13 ;
if ( F_9 ( V_8 ) -> V_14 -> V_15 & V_16 )
V_2 -> V_17 = V_18 ;
else
V_2 -> V_17 = V_19 ;
V_2 -> V_20 = 100 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = & V_24 ;
V_2 -> V_25 = & V_8 -> V_26 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = 14 ;
V_7 = F_10 ( V_2 ) ;
if ( F_11 ( V_7 ) ) {
V_9 = F_12 ( V_7 ) ;
V_7 = NULL ;
goto V_30;
}
V_2 -> V_31 = F_13 ( V_7 ) ;
if ( ! V_2 -> V_31 ) {
V_9 = - V_32 ;
goto V_30;
}
if ( F_9 ( V_8 ) -> V_33 )
V_2 -> V_34 = & V_35 ;
else
V_2 -> V_34 = & V_36 ;
#ifdef F_14
if ( V_8 -> V_10 & V_37 ) {
F_15 ( 1 , L_1 ) ;
V_2 -> V_38 = & V_39 ;
}
#endif
return 0 ;
V_30:
F_16 ( 1 , L_2 ) ;
if ( V_7 )
F_17 ( V_7 ) ;
return V_9 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_8 ) ;
}
static int
F_21 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_40 -> V_43 ;
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_44 * V_45 = F_9 ( V_8 ) ;
int V_9 = - V_46 ;
int V_47 ;
V_47 = F_22 () ;
V_42 -> V_48 = V_22 ;
V_42 -> V_49 = V_50 ;
V_42 -> V_51 = 0 ;
V_42 -> V_52 = 0 ;
if ( ( V_45 -> V_14 -> V_15 & V_53 ) &&
( V_54 & F_23 ( V_45 -> V_55 . V_56 ) ) )
V_9 = F_24 ( V_47 , V_45 , V_42 ) ;
if ( V_9 && ( V_45 -> V_14 -> V_15 & V_57 ) )
V_9 = F_25 ( V_47 , V_45 , V_42 ) ;
if ( V_9 )
V_9 = F_26 ( V_47 , V_45 , V_42 ) ;
F_27 ( V_47 ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_7 , int V_58 , unsigned int V_59 )
{
struct V_3 * V_8 ;
V_8 = F_2 ( V_7 -> V_60 ) ;
if ( V_8 -> V_10 & V_61 ) {
if ( ( V_58 & V_62 ) && ! F_29 ( V_7 ) )
return - V_63 ;
else
return 0 ;
} else
return F_30 ( V_7 , V_58 , V_59 , NULL ) ;
}
static struct V_7 *
F_31 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
V_65 = F_32 ( V_66 , V_67 ) ;
if ( ! V_65 )
return NULL ;
V_65 -> V_68 = 0x20 ;
V_65 -> time = 0 ;
F_33 ( V_65 , 0 ) ;
V_65 -> V_69 = false ;
V_65 -> V_70 = false ;
V_65 -> V_71 . V_72 = 14 ;
V_65 -> V_73 = 0 ;
V_65 -> V_74 = 0 ;
V_65 -> V_75 = 0 ;
F_34 ( & V_65 -> V_76 ) ;
return & V_65 -> V_71 ;
}
static void F_35 ( struct V_77 * V_78 )
{
struct V_7 * V_7 = F_36 ( V_78 , struct V_7 , V_79 ) ;
F_34 ( & V_7 -> V_80 ) ;
F_37 ( V_66 , F_38 ( V_7 ) ) ;
}
static void
F_39 ( struct V_7 * V_7 )
{
F_40 ( & V_7 -> V_79 , F_35 ) ;
}
static void
F_41 ( struct V_7 * V_7 )
{
F_42 ( & V_7 -> V_81 , 0 ) ;
F_43 ( V_7 ) ;
F_44 ( V_7 ) ;
}
static void
F_45 ( struct V_82 * V_83 , struct V_84 * V_4 )
{
struct V_85 * V_86 = (struct V_85 * ) & V_4 -> V_87 ;
struct V_88 * V_89 = (struct V_88 * ) & V_4 -> V_87 ;
F_46 ( V_83 , L_3 ) ;
switch ( V_4 -> V_87 . V_90 ) {
case V_91 :
F_46 ( V_83 , L_4 , & V_86 -> V_92 . V_93 ) ;
break;
case V_94 :
F_46 ( V_83 , L_5 , & V_89 -> V_95 . V_96 ) ;
if ( V_89 -> V_97 )
F_46 ( V_83 , L_6 , V_89 -> V_97 ) ;
break;
default:
F_46 ( V_83 , L_7 ) ;
}
}
static void
F_47 ( struct V_82 * V_83 , struct V_84 * V_4 )
{
F_46 ( V_83 , L_8 ) ;
switch ( V_4 -> V_98 ) {
case V_99 :
F_46 ( V_83 , L_9 ) ;
break;
case V_100 :
F_46 ( V_83 , L_10 ) ;
break;
case V_101 :
F_46 ( V_83 , L_11 ) ;
break;
case V_102 :
F_46 ( V_83 , L_12 ) ;
break;
case V_103 :
F_46 ( V_83 , L_13 ) ;
break;
default:
F_46 ( V_83 , L_14 ) ;
break;
}
if ( V_4 -> V_104 & ( V_105 | V_106 ) )
F_46 ( V_83 , L_15 ) ;
}
static int
F_48 ( struct V_82 * V_83 , struct V_107 * V_108 )
{
struct V_3 * V_8 = F_2 ( V_108 -> V_109 ) ;
struct V_44 * V_45 = F_9 ( V_8 ) ;
struct V_110 * V_111 ;
V_111 = (struct V_110 * ) & V_45 -> V_14 -> V_4 -> V_111 ;
F_47 ( V_83 , V_45 -> V_14 -> V_4 ) ;
F_46 ( V_83 , L_16 , V_45 -> V_112 ) ;
if ( V_8 -> V_10 & V_113 )
F_46 ( V_83 , L_17 ) ;
else if ( V_45 -> V_14 -> V_114 )
F_46 ( V_83 , L_18 , V_45 -> V_14 -> V_114 ) ;
if ( V_45 -> V_14 -> V_115 )
F_46 ( V_83 , L_19 , V_45 -> V_14 -> V_115 ) ;
if ( V_111 -> V_116 != V_117 ) {
struct V_85 * V_118 ;
struct V_88 * V_119 ;
V_118 = (struct V_85 * ) V_111 ;
V_119 = (struct V_88 * ) V_111 ;
if ( V_111 -> V_116 == V_94 )
F_46 ( V_83 , L_20 ,
& V_119 -> V_95 ) ;
else if ( V_111 -> V_116 == V_91 )
F_46 ( V_83 , L_21 ,
& V_118 -> V_92 . V_93 ) ;
else
F_46 ( V_83 , L_22 ,
( int ) ( V_111 -> V_116 ) ) ;
}
F_46 ( V_83 , L_23 , V_8 -> V_120 ) ;
if ( V_8 -> V_10 & V_121 )
F_46 ( V_83 , L_24 ) ;
else
F_46 ( V_83 , L_25 ) ;
F_46 ( V_83 , L_26 , V_8 -> V_122 ) ;
if ( V_8 -> V_10 & V_123 )
F_46 ( V_83 , L_27 ) ;
else
F_46 ( V_83 , L_28 ) ;
F_45 ( V_83 , V_45 -> V_14 -> V_4 ) ;
if ( ! V_45 -> V_124 )
F_46 ( V_83 , L_29 ,
V_8 -> V_125 ,
V_8 -> V_126 ) ;
if ( V_45 -> V_127 )
F_46 ( V_83 , L_30 ) ;
if ( V_45 -> V_33 )
F_46 ( V_83 , L_31 ) ;
if ( V_45 -> V_128 )
F_46 ( V_83 , L_32 ) ;
if ( V_45 -> V_124 )
F_46 ( V_83 , L_33 ) ;
else
F_46 ( V_83 , L_34 ) ;
if ( V_8 -> V_10 & V_129 )
F_46 ( V_83 , L_35 ) ;
if ( V_8 -> V_10 & V_130 )
F_46 ( V_83 , L_36 ) ;
if ( V_8 -> V_10 & V_37 )
F_46 ( V_83 , L_37 ) ;
if ( V_8 -> V_10 & V_131 )
F_46 ( V_83 , L_38 ) ;
if ( V_8 -> V_10 & V_132 )
F_46 ( V_83 , L_39 ) ;
if ( V_8 -> V_10 & V_133 )
F_46 ( V_83 , L_40 ) ;
if ( V_8 -> V_10 & V_134 )
F_46 ( V_83 , L_41 ) ;
if ( V_8 -> V_10 & V_135 )
F_46 ( V_83 , L_42 ) ;
if ( V_8 -> V_10 & V_136 )
F_46 ( V_83 , L_43 ) ;
if ( V_8 -> V_10 & V_137 )
F_46 ( V_83 , L_44 ) ;
if ( V_8 -> V_10 & V_138 )
F_46 ( V_83 , L_45 ) ;
if ( V_8 -> V_10 & V_139 )
F_46 ( V_83 , L_46 ) ;
if ( V_108 -> V_109 -> V_12 & V_13 )
F_46 ( V_83 , L_47 ) ;
if ( V_8 -> V_10 & V_140 )
F_46 ( V_83 , L_48 ) ;
if ( V_8 -> V_10 & V_141 )
F_46 ( V_83 , L_49 ) ;
F_46 ( V_83 , L_50 , V_8 -> V_142 ) ;
F_46 ( V_83 , L_51 , V_8 -> V_143 ) ;
F_46 ( V_83 , L_52 , V_8 -> V_144 / V_145 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_44 * V_45 ;
if ( V_8 == NULL )
return;
V_45 = F_9 ( V_8 ) ;
F_50 ( & V_146 ) ;
if ( ( V_45 -> V_147 > 1 ) || ( V_45 -> V_148 == V_149 ) ) {
F_51 ( & V_146 ) ;
return;
} else if ( V_45 -> V_147 == 1 )
V_45 -> V_148 = V_149 ;
F_51 ( & V_146 ) ;
if ( V_45 -> V_14 && V_45 -> V_14 -> V_4 ) {
F_15 ( 1 , L_53 ) ;
F_52 ( & V_45 -> V_14 -> V_4 -> V_150 ) ;
F_52 ( & V_45 -> V_14 -> V_4 -> V_151 ) ;
F_53 ( 1 ) ;
F_52 ( & V_45 -> V_14 -> V_4 -> V_151 ) ;
F_53 ( 1 ) ;
}
return;
}
static int F_54 ( struct V_82 * V_83 , struct V_107 * V_152 )
{
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , int * V_59 , char * V_153 )
{
* V_59 |= V_154 ;
return 0 ;
}
static int F_56 ( struct V_7 * V_7 )
{
struct V_3 * V_8 = F_2 ( V_7 -> V_60 ) ;
return ! ( V_8 -> V_10 & V_37 ) ||
F_57 ( V_7 ) ;
}
static struct V_40 *
F_58 ( struct V_155 * V_156 , struct V_1 * V_2 )
{
struct V_40 * V_40 ;
struct V_3 * V_8 = F_2 ( V_2 ) ;
char * V_157 = NULL ;
char * V_83 , * V_158 ;
char V_159 ;
int V_47 ;
V_157 = F_59 ( V_156 , V_8 ,
F_9 ( V_8 ) ) ;
if ( V_157 == NULL )
return F_60 ( - V_32 ) ;
F_15 ( 1 , L_54 , V_157 ) ;
V_47 = F_22 () ;
V_159 = F_61 ( V_8 ) ;
V_40 = F_62 ( V_2 -> V_31 ) ;
V_158 = V_83 = V_157 ;
do {
struct V_7 * V_160 = V_40 -> V_161 ;
struct V_40 * V_162 ;
while ( * V_83 == V_159 )
V_83 ++ ;
if ( ! * V_83 )
break;
V_158 = V_83 ++ ;
while ( * V_83 && * V_83 != V_159 )
V_83 ++ ;
F_63 ( & V_160 -> V_163 ) ;
V_162 = F_64 ( V_158 , V_40 , V_83 - V_158 ) ;
F_65 ( & V_160 -> V_163 ) ;
F_66 ( V_40 ) ;
V_40 = V_162 ;
} while ( ! F_11 ( V_40 ) );
F_67 ( V_47 ) ;
F_68 ( V_157 ) ;
return V_40 ;
}
static int F_69 ( struct V_1 * V_2 , void * V_153 )
{
struct V_164 * V_165 = V_153 ;
V_2 -> V_166 = V_165 -> V_8 ;
return F_70 ( V_2 , NULL ) ;
}
static struct V_40 *
F_71 ( struct V_167 * V_168 ,
int V_59 , const char * V_169 , void * V_153 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_3 * V_8 ;
struct V_155 * V_170 ;
struct V_164 V_165 ;
struct V_40 * V_171 ;
F_15 ( 1 , L_55 , V_169 , V_59 ) ;
V_170 = F_72 ( ( char * ) V_153 , V_169 ) ;
if ( F_11 ( V_170 ) )
return F_73 ( V_170 ) ;
V_8 = F_74 ( sizeof( struct V_3 ) , V_67 ) ;
if ( V_8 == NULL ) {
V_171 = F_60 ( - V_32 ) ;
goto V_172;
}
V_8 -> V_173 = F_75 ( V_153 , V_174 , V_67 ) ;
if ( V_8 -> V_173 == NULL ) {
V_171 = F_60 ( - V_32 ) ;
goto V_175;
}
F_76 ( V_170 , V_8 ) ;
V_9 = F_77 ( V_8 , V_170 ) ;
if ( V_9 ) {
if ( ! ( V_59 & V_176 ) )
F_16 ( 1 , L_56 , V_9 ) ;
V_171 = F_60 ( V_9 ) ;
goto V_177;
}
V_165 . V_156 = V_170 ;
V_165 . V_8 = V_8 ;
V_165 . V_59 = V_59 ;
V_2 = F_78 ( V_168 , V_178 , F_69 , & V_165 ) ;
if ( F_11 ( V_2 ) ) {
V_171 = F_73 ( V_2 ) ;
F_20 ( V_8 ) ;
goto V_179;
}
if ( V_2 -> V_31 ) {
F_15 ( 1 , L_57 ) ;
F_20 ( V_8 ) ;
} else {
V_2 -> V_12 = V_59 ;
V_2 -> V_12 |= V_154 | V_180 ;
V_9 = F_8 ( V_2 ) ;
if ( V_9 ) {
V_171 = F_60 ( V_9 ) ;
goto V_181;
}
V_2 -> V_12 |= V_182 ;
}
V_171 = F_58 ( V_170 , V_2 ) ;
if ( F_11 ( V_171 ) )
goto V_181;
F_15 ( 1 , L_58 , V_171 ) ;
goto V_179;
V_181:
F_79 ( V_2 ) ;
V_179:
F_80 ( V_170 ) ;
return V_171 ;
V_177:
F_68 ( V_8 -> V_173 ) ;
V_175:
F_68 ( V_8 ) ;
V_172:
F_81 ( V_170 -> V_183 ) ;
goto V_179;
}
static T_1 F_82 ( struct V_184 * V_185 , const struct V_186 * V_187 ,
unsigned long V_188 , T_2 V_189 )
{
struct V_7 * V_7 = V_185 -> V_190 -> V_191 . V_40 -> V_161 ;
T_1 V_192 ;
int V_9 ;
V_192 = F_83 ( V_185 , V_187 , V_188 , V_189 ) ;
if ( F_38 ( V_7 ) -> V_193 )
return V_192 ;
V_9 = F_84 ( V_7 -> V_194 ) ;
if ( V_9 )
F_15 ( 1 , L_59 , V_9 , V_7 ) ;
return V_192 ;
}
static T_2 F_85 ( struct V_195 * V_195 , T_2 V_196 , int V_197 )
{
if ( V_197 == V_198 ) {
int V_9 ;
struct V_7 * V_7 = V_195 -> V_191 . V_40 -> V_161 ;
if ( ! F_38 ( V_7 ) -> V_199 && V_7 -> V_194 &&
V_7 -> V_194 -> V_200 != 0 ) {
V_9 = F_86 ( V_7 -> V_194 ) ;
if ( V_9 ) {
F_87 ( V_7 -> V_194 , V_9 ) ;
return V_9 ;
}
}
F_38 ( V_7 ) -> time = 0 ;
V_9 = F_88 ( V_195 ) ;
if ( V_9 < 0 )
return ( T_2 ) V_9 ;
}
return F_89 ( V_195 , V_196 , V_197 ) ;
}
static int F_90 ( struct V_195 * V_195 , long V_201 , struct V_202 * * V_203 )
{
struct V_7 * V_7 = V_195 -> V_191 . V_40 -> V_161 ;
struct V_204 * V_205 = V_195 -> V_206 ;
if ( ! ( F_91 ( V_7 -> V_207 ) ) )
return - V_208 ;
if ( ( ( V_201 == V_209 ) &&
( F_38 ( V_7 ) -> V_199 ) ) ||
( ( V_201 == V_210 ) &&
( F_38 ( V_7 ) -> V_193 ) ) )
return F_92 ( V_195 , V_201 , V_203 ) ;
else if ( F_93 ( V_205 -> V_211 ) -> V_212 &&
! F_38 ( V_7 ) -> V_199 )
return F_92 ( V_195 , V_201 , V_203 ) ;
else
return - V_213 ;
}
static void
F_94 ( void * V_7 )
{
struct V_64 * V_214 = V_7 ;
F_95 ( & V_214 -> V_71 ) ;
F_34 ( & V_214 -> V_215 ) ;
}
static int
F_96 ( void )
{
V_66 = F_97 ( L_60 ,
sizeof( struct V_64 ) ,
0 , ( V_216 |
V_217 ) ,
F_94 ) ;
if ( V_66 == NULL )
return - V_32 ;
return 0 ;
}
static void
F_98 ( void )
{
F_99 ( V_66 ) ;
}
static int
F_100 ( void )
{
if ( V_218 < 8192 ) {
V_218 = 8192 ;
} else if ( V_218 > 1024 * 127 ) {
V_218 = 1024 * 127 ;
} else {
V_218 &= 0x1FE00 ;
}
V_219 = F_97 ( L_61 ,
V_218 +
V_220 , 0 ,
V_221 , NULL ) ;
if ( V_219 == NULL )
return - V_32 ;
if ( V_222 < 1 )
V_222 = 1 ;
else if ( V_222 > 64 ) {
V_222 = 64 ;
F_16 ( 1 , L_62 ) ;
}
V_223 = F_101 ( V_222 ,
V_219 ) ;
if ( V_223 == NULL ) {
F_99 ( V_219 ) ;
return - V_32 ;
}
V_224 = F_97 ( L_63 ,
V_225 , 0 , V_221 ,
NULL ) ;
if ( V_224 == NULL ) {
F_102 ( V_223 ) ;
F_99 ( V_219 ) ;
return - V_32 ;
}
if ( V_226 < 2 )
V_226 = 2 ;
else if ( V_226 > 256 ) {
V_226 = 256 ;
F_15 ( 1 , L_64 ) ;
}
V_227 = F_101 ( V_226 ,
V_224 ) ;
if ( V_227 == NULL ) {
F_102 ( V_223 ) ;
F_99 ( V_219 ) ;
F_99 ( V_224 ) ;
return - V_32 ;
}
return 0 ;
}
static void
F_103 ( void )
{
F_102 ( V_223 ) ;
F_99 ( V_219 ) ;
F_102 ( V_227 ) ;
F_99 ( V_224 ) ;
}
static int
F_104 ( void )
{
V_228 = F_97 ( L_65 ,
sizeof( struct V_229 ) , 0 ,
V_221 , NULL ) ;
if ( V_228 == NULL )
return - V_32 ;
V_230 = F_101 ( 3 , V_228 ) ;
if ( V_230 == NULL ) {
F_99 ( V_228 ) ;
return - V_32 ;
}
return 0 ;
}
static void
F_105 ( void )
{
F_102 ( V_230 ) ;
F_99 ( V_228 ) ;
}
static int T_3
F_106 ( void )
{
int V_9 = 0 ;
F_107 () ;
F_34 ( & V_231 ) ;
#ifdef F_108
F_34 ( & V_232 ) ;
F_34 ( & V_233 ) ;
#endif
F_109 ( & V_234 , 0 ) ;
F_109 ( & V_235 , 0 ) ;
F_109 ( & V_236 , 0 ) ;
F_109 ( & V_237 , 0 ) ;
F_109 ( & V_238 , 0 ) ;
F_109 ( & V_239 , 0 ) ;
F_109 ( & V_240 , 0 ) ;
#ifdef F_110
F_109 ( & V_241 , 0 ) ;
F_109 ( & V_242 , 0 ) ;
#endif
F_109 ( & V_243 , 0 ) ;
V_244 = 0 ;
V_245 = 0 ;
V_246 = 0 ;
F_111 ( & V_146 ) ;
F_111 ( & V_247 ) ;
F_111 ( & V_248 ) ;
if ( V_249 < 2 ) {
V_249 = 2 ;
F_15 ( 1 , L_66 ) ;
} else if ( V_249 > 256 ) {
V_249 = 256 ;
F_15 ( 1 , L_67 ) ;
}
V_9 = F_112 () ;
if ( V_9 )
goto V_250;
V_9 = F_96 () ;
if ( V_9 )
goto V_251;
V_9 = F_104 () ;
if ( V_9 )
goto V_252;
V_9 = F_100 () ;
if ( V_9 )
goto V_253;
#ifdef F_113
V_9 = F_114 ( & V_254 ) ;
if ( V_9 )
goto V_255;
#endif
#ifdef F_115
V_9 = F_116 () ;
if ( V_9 )
goto V_256;
#endif
V_9 = F_117 ( & V_257 ) ;
if ( V_9 )
goto V_258;
return 0 ;
V_258:
#ifdef F_115
F_118 () ;
V_256:
#endif
#ifdef F_113
F_119 ( & V_254 ) ;
V_255:
#endif
F_103 () ;
V_253:
F_105 () ;
V_252:
F_98 () ;
V_251:
F_120 () ;
V_250:
F_121 () ;
return V_9 ;
}
static void T_4
F_122 ( void )
{
F_15 ( V_259 , L_68 ) ;
F_121 () ;
F_120 () ;
#ifdef F_123
F_124 () ;
#endif
#ifdef F_115
F_125 () ;
F_118 () ;
#endif
#ifdef F_113
F_119 ( & V_254 ) ;
#endif
F_126 ( & V_257 ) ;
F_98 () ;
F_105 () ;
F_103 () ;
}
