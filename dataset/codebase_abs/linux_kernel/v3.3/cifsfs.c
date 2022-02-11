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
V_3 = NULL ;
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
if ( V_3 )
F_11 ( V_3 ) ;
return V_6 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_5 ) ;
}
static int
F_15 ( struct V_37 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_37 -> V_40 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_41 * V_42 = F_3 ( V_5 ) ;
int V_6 = - V_43 ;
int V_44 ;
V_44 = F_16 () ;
V_39 -> V_45 = V_19 ;
V_39 -> V_46 = V_47 ;
V_39 -> V_48 = 0 ;
V_39 -> V_49 = 0 ;
if ( ( V_42 -> V_11 -> V_12 & V_50 ) &&
( V_51 & F_17 ( V_42 -> V_52 . V_53 ) ) )
V_6 = F_18 ( V_44 , V_42 , V_39 ) ;
if ( V_6 && ( V_42 -> V_11 -> V_12 & V_54 ) )
V_6 = F_19 ( V_44 , V_42 , V_39 ) ;
if ( V_6 )
V_6 = F_20 ( V_44 , V_42 , V_39 ) ;
F_21 ( V_44 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_3 , int V_55 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 -> V_56 ) ;
if ( V_5 -> V_7 & V_57 ) {
if ( ( V_55 & V_58 ) && ! F_23 ( V_3 ) )
return - V_59 ;
else
return 0 ;
} else
return F_24 ( V_3 , V_55 ) ;
}
static struct V_3 *
F_25 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
V_61 = F_26 ( V_62 , V_63 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_64 = 0x20 ;
V_61 -> time = 0 ;
F_27 ( V_61 , 0 ) ;
V_61 -> V_65 = false ;
V_61 -> V_66 = false ;
V_61 -> V_67 . V_68 = 14 ;
V_61 -> V_69 = 0 ;
V_61 -> V_70 = 0 ;
V_61 -> V_71 = 0 ;
F_28 ( & V_61 -> V_72 ) ;
return & V_61 -> V_67 ;
}
static void F_29 ( struct V_73 * V_74 )
{
struct V_3 * V_3 = F_30 ( V_74 , struct V_3 , V_75 ) ;
F_28 ( & V_3 -> V_76 ) ;
F_31 ( V_62 , F_32 ( V_3 ) ) ;
}
static void
F_33 ( struct V_3 * V_3 )
{
F_34 ( & V_3 -> V_75 , F_29 ) ;
}
static void
F_35 ( struct V_3 * V_3 )
{
F_36 ( & V_3 -> V_77 , 0 ) ;
F_37 ( V_3 ) ;
F_38 ( V_3 ) ;
}
static void
F_39 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) & V_81 -> V_84 ;
struct V_85 * V_86 = (struct V_85 * ) & V_81 -> V_84 ;
F_40 ( V_79 , L_3 ) ;
switch ( V_81 -> V_84 . V_87 ) {
case V_88 :
F_40 ( V_79 , L_4 , & V_83 -> V_89 . V_90 ) ;
break;
case V_91 :
F_40 ( V_79 , L_5 , & V_86 -> V_92 . V_93 ) ;
if ( V_86 -> V_94 )
F_40 ( V_79 , L_6 , V_86 -> V_94 ) ;
break;
default:
F_40 ( V_79 , L_7 ) ;
}
}
static void
F_41 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
F_40 ( V_79 , L_8 ) ;
switch ( V_81 -> V_95 ) {
case V_96 :
F_40 ( V_79 , L_9 ) ;
break;
case V_97 :
F_40 ( V_79 , L_10 ) ;
break;
case V_98 :
F_40 ( V_79 , L_11 ) ;
break;
case V_99 :
F_40 ( V_79 , L_12 ) ;
break;
case V_100 :
F_40 ( V_79 , L_13 ) ;
break;
default:
F_40 ( V_79 , L_14 ) ;
break;
}
if ( V_81 -> V_101 & ( V_102 | V_103 ) )
F_40 ( V_79 , L_15 ) ;
}
static int
F_42 ( struct V_78 * V_79 , struct V_37 * V_104 )
{
struct V_4 * V_5 = F_2 ( V_104 -> V_40 ) ;
struct V_41 * V_42 = F_3 ( V_5 ) ;
struct V_105 * V_106 ;
V_106 = (struct V_105 * ) & V_42 -> V_11 -> V_81 -> V_106 ;
F_41 ( V_79 , V_42 -> V_11 -> V_81 ) ;
F_40 ( V_79 , L_16 , V_42 -> V_107 ) ;
if ( V_5 -> V_7 & V_108 )
F_40 ( V_79 , L_17 ) ;
else if ( V_42 -> V_11 -> V_109 )
F_40 ( V_79 , L_18 , V_42 -> V_11 -> V_109 ) ;
if ( V_42 -> V_11 -> V_110 )
F_40 ( V_79 , L_19 , V_42 -> V_11 -> V_110 ) ;
if ( V_106 -> V_111 != V_112 ) {
struct V_82 * V_113 ;
struct V_85 * V_114 ;
V_113 = (struct V_82 * ) V_106 ;
V_114 = (struct V_85 * ) V_106 ;
if ( V_106 -> V_111 == V_91 )
F_40 ( V_79 , L_20 ,
& V_114 -> V_92 ) ;
else if ( V_106 -> V_111 == V_88 )
F_40 ( V_79 , L_21 ,
& V_113 -> V_89 . V_90 ) ;
else
F_40 ( V_79 , L_22 ,
( int ) ( V_106 -> V_111 ) ) ;
}
F_40 ( V_79 , L_23 , V_5 -> V_115 ) ;
if ( V_5 -> V_7 & V_116 )
F_40 ( V_79 , L_24 ) ;
else
F_40 ( V_79 , L_25 ) ;
F_40 ( V_79 , L_26 , V_5 -> V_117 ) ;
if ( V_5 -> V_7 & V_118 )
F_40 ( V_79 , L_27 ) ;
else
F_40 ( V_79 , L_28 ) ;
F_39 ( V_79 , V_42 -> V_11 -> V_81 ) ;
if ( ! V_42 -> V_119 )
F_40 ( V_79 , L_29 ,
V_5 -> V_120 ,
V_5 -> V_121 ) ;
if ( V_42 -> V_122 )
F_40 ( V_79 , L_30 ) ;
if ( V_42 -> V_30 )
F_40 ( V_79 , L_31 ) ;
if ( V_42 -> V_123 )
F_40 ( V_79 , L_32 ) ;
if ( V_42 -> V_119 )
F_40 ( V_79 , L_33 ) ;
else
F_40 ( V_79 , L_34 ) ;
if ( V_5 -> V_7 & V_124 )
F_40 ( V_79 , L_35 ) ;
if ( V_5 -> V_7 & V_125 )
F_40 ( V_79 , L_36 ) ;
if ( V_5 -> V_7 & V_34 )
F_40 ( V_79 , L_37 ) ;
if ( V_5 -> V_7 & V_126 )
F_40 ( V_79 , L_38 ) ;
if ( V_5 -> V_7 & V_127 )
F_40 ( V_79 , L_39 ) ;
if ( V_5 -> V_7 & V_128 )
F_40 ( V_79 , L_40 ) ;
if ( V_5 -> V_7 & V_129 )
F_40 ( V_79 , L_41 ) ;
if ( V_5 -> V_7 & V_130 )
F_40 ( V_79 , L_42 ) ;
if ( V_5 -> V_7 & V_131 )
F_40 ( V_79 , L_43 ) ;
if ( V_5 -> V_7 & V_132 )
F_40 ( V_79 , L_44 ) ;
if ( V_5 -> V_7 & V_133 )
F_40 ( V_79 , L_45 ) ;
if ( V_5 -> V_7 & V_134 )
F_40 ( V_79 , L_46 ) ;
if ( V_104 -> V_40 -> V_9 & V_10 )
F_40 ( V_79 , L_47 ) ;
if ( V_5 -> V_7 & V_135 )
F_40 ( V_79 , L_48 ) ;
if ( V_5 -> V_7 & V_136 )
F_40 ( V_79 , L_49 ) ;
if ( V_5 -> V_7 & V_137 )
F_40 ( V_79 , L_50 ) ;
if ( V_5 -> V_7 & V_57 )
F_40 ( V_79 , L_51 ) ;
if ( V_5 -> V_7 & V_138 )
F_40 ( V_79 , L_52 ) ;
F_40 ( V_79 , L_53 , V_5 -> V_139 ) ;
F_40 ( V_79 , L_54 , V_5 -> V_140 ) ;
F_40 ( V_79 , L_55 , V_5 -> V_141 / V_142 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_41 * V_42 ;
if ( V_5 == NULL )
return;
V_42 = F_3 ( V_5 ) ;
F_44 ( & V_143 ) ;
if ( ( V_42 -> V_144 > 1 ) || ( V_42 -> V_145 == V_146 ) ) {
F_45 ( & V_143 ) ;
return;
} else if ( V_42 -> V_144 == 1 )
V_42 -> V_145 = V_146 ;
F_45 ( & V_143 ) ;
if ( V_42 -> V_11 && V_42 -> V_11 -> V_81 ) {
F_9 ( 1 , L_56 ) ;
F_46 ( & V_42 -> V_11 -> V_81 -> V_147 ) ;
F_46 ( & V_42 -> V_11 -> V_81 -> V_148 ) ;
F_47 ( 1 ) ;
F_46 ( & V_42 -> V_11 -> V_81 -> V_148 ) ;
F_47 ( 1 ) ;
}
return;
}
static int F_48 ( struct V_78 * V_79 , struct V_37 * V_104 )
{
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int * V_149 , char * V_150 )
{
* V_149 |= V_151 ;
return 0 ;
}
static int F_50 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_56 ) ;
return ! ( V_5 -> V_7 & V_34 ) ||
F_51 ( V_3 ) ;
}
static struct V_37 *
F_52 ( struct V_152 * V_153 , struct V_1 * V_2 )
{
struct V_37 * V_37 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_154 = NULL ;
char * V_79 , * V_155 ;
char V_156 ;
V_154 = F_53 ( V_153 , V_5 ,
F_3 ( V_5 ) ) ;
if ( V_154 == NULL )
return F_54 ( - V_29 ) ;
F_9 ( 1 , L_57 , V_154 ) ;
V_156 = F_55 ( V_5 ) ;
V_37 = F_56 ( V_2 -> V_28 ) ;
V_155 = V_79 = V_154 ;
do {
struct V_3 * V_157 = V_37 -> V_158 ;
struct V_37 * V_159 ;
if ( ! V_157 ) {
F_57 ( V_37 ) ;
V_37 = F_54 ( - V_160 ) ;
break;
}
while ( * V_79 == V_156 )
V_79 ++ ;
if ( ! * V_79 )
break;
V_155 = V_79 ++ ;
while ( * V_79 && * V_79 != V_156 )
V_79 ++ ;
F_58 ( & V_157 -> V_161 ) ;
V_159 = F_59 ( V_155 , V_37 , V_79 - V_155 ) ;
F_60 ( & V_157 -> V_161 ) ;
F_57 ( V_37 ) ;
V_37 = V_159 ;
} while ( ! F_5 ( V_37 ) );
F_61 ( V_154 ) ;
return V_37 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_150 )
{
struct V_162 * V_163 = V_150 ;
V_2 -> V_164 = V_163 -> V_5 ;
return F_63 ( V_2 , NULL ) ;
}
static struct V_37 *
F_64 ( struct V_165 * V_166 ,
int V_149 , const char * V_167 , void * V_150 )
{
int V_6 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_152 * V_168 ;
struct V_162 V_163 ;
struct V_37 * V_104 ;
F_9 ( 1 , L_58 , V_167 , V_149 ) ;
V_168 = F_65 ( ( char * ) V_150 , V_167 ) ;
if ( F_5 ( V_168 ) )
return F_66 ( V_168 ) ;
V_5 = F_67 ( sizeof( struct V_4 ) , V_63 ) ;
if ( V_5 == NULL ) {
V_104 = F_54 ( - V_29 ) ;
goto V_169;
}
V_5 -> V_170 = F_68 ( V_150 , V_171 , V_63 ) ;
if ( V_5 -> V_170 == NULL ) {
V_104 = F_54 ( - V_29 ) ;
goto V_172;
}
F_69 ( V_168 , V_5 ) ;
V_6 = F_70 ( V_5 , V_168 ) ;
if ( V_6 ) {
if ( ! ( V_149 & V_173 ) )
F_10 ( 1 , L_59 , V_6 ) ;
V_104 = F_54 ( V_6 ) ;
goto V_174;
}
V_163 . V_153 = V_168 ;
V_163 . V_5 = V_5 ;
V_163 . V_149 = V_149 ;
V_2 = F_71 ( V_166 , V_175 , F_62 , & V_163 ) ;
if ( F_5 ( V_2 ) ) {
V_104 = F_66 ( V_2 ) ;
F_14 ( V_5 ) ;
goto V_176;
}
if ( V_2 -> V_28 ) {
F_9 ( 1 , L_60 ) ;
F_14 ( V_5 ) ;
} else {
V_2 -> V_9 = V_149 ;
V_2 -> V_9 |= V_151 | V_177 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 ) {
V_104 = F_54 ( V_6 ) ;
goto V_178;
}
V_2 -> V_9 |= V_179 ;
}
V_104 = F_52 ( V_168 , V_2 ) ;
if ( F_5 ( V_104 ) )
goto V_178;
F_9 ( 1 , L_61 , V_104 ) ;
goto V_176;
V_178:
F_72 ( V_2 ) ;
V_176:
F_73 ( V_168 ) ;
return V_104 ;
V_174:
F_61 ( V_5 -> V_170 ) ;
V_172:
F_61 ( V_5 ) ;
V_169:
F_74 ( V_168 -> V_180 ) ;
goto V_176;
}
static T_1 F_75 ( struct V_181 * V_182 , const struct V_183 * V_184 ,
unsigned long V_185 , T_2 V_186 )
{
struct V_3 * V_3 = V_182 -> V_187 -> V_188 . V_37 -> V_158 ;
T_1 V_189 ;
int V_6 ;
V_189 = F_76 ( V_182 , V_184 , V_185 , V_186 ) ;
if ( F_32 ( V_3 ) -> V_190 )
return V_189 ;
V_6 = F_77 ( V_3 -> V_191 ) ;
if ( V_6 )
F_9 ( 1 , L_62 , V_6 , V_3 ) ;
return V_189 ;
}
static T_2 F_78 ( struct V_192 * V_192 , T_2 V_193 , int V_194 )
{
if ( V_194 != V_195 || V_194 != V_196 ) {
int V_6 ;
struct V_3 * V_3 = V_192 -> V_188 . V_37 -> V_158 ;
if ( ! F_32 ( V_3 ) -> V_197 && V_3 -> V_191 &&
V_3 -> V_191 -> V_198 != 0 ) {
V_6 = F_79 ( V_3 -> V_191 ) ;
if ( V_6 ) {
F_80 ( V_3 -> V_191 , V_6 ) ;
return V_6 ;
}
}
F_32 ( V_3 ) -> time = 0 ;
V_6 = F_81 ( V_192 ) ;
if ( V_6 < 0 )
return ( T_2 ) V_6 ;
}
return F_82 ( V_192 , V_193 , V_194 ) ;
}
static int F_83 ( struct V_192 * V_192 , long V_199 , struct V_200 * * V_201 )
{
struct V_3 * V_3 = V_192 -> V_188 . V_37 -> V_158 ;
struct V_202 * V_203 = V_192 -> V_204 ;
if ( ! ( F_84 ( V_3 -> V_205 ) ) )
return - V_206 ;
if ( ( ( V_199 == V_207 ) &&
( F_32 ( V_3 ) -> V_197 ) ) ||
( ( V_199 == V_208 ) &&
( F_32 ( V_3 ) -> V_190 ) ) )
return F_85 ( V_192 , V_199 , V_201 ) ;
else if ( F_86 ( V_203 -> V_209 ) -> V_210 &&
! F_32 ( V_3 ) -> V_197 )
return F_85 ( V_192 , V_199 , V_201 ) ;
else
return - V_211 ;
}
static void
F_87 ( void * V_3 )
{
struct V_60 * V_212 = V_3 ;
F_88 ( & V_212 -> V_67 ) ;
F_28 ( & V_212 -> V_213 ) ;
F_89 ( & V_212 -> V_214 ) ;
}
static int
F_90 ( void )
{
V_62 = F_91 ( L_63 ,
sizeof( struct V_60 ) ,
0 , ( V_215 |
V_216 ) ,
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
if ( V_217 < 8192 ) {
V_217 = 8192 ;
} else if ( V_217 > 1024 * 127 ) {
V_217 = 1024 * 127 ;
} else {
V_217 &= 0x1FE00 ;
}
V_218 = F_91 ( L_64 ,
V_217 +
V_219 , 0 ,
V_220 , NULL ) ;
if ( V_218 == NULL )
return - V_29 ;
if ( V_221 < 1 )
V_221 = 1 ;
else if ( V_221 > 64 ) {
V_221 = 64 ;
F_10 ( 1 , L_65 ) ;
}
V_222 = F_95 ( V_221 ,
V_218 ) ;
if ( V_222 == NULL ) {
F_93 ( V_218 ) ;
return - V_29 ;
}
V_223 = F_91 ( L_66 ,
V_224 , 0 , V_220 ,
NULL ) ;
if ( V_223 == NULL ) {
F_96 ( V_222 ) ;
F_93 ( V_218 ) ;
return - V_29 ;
}
if ( V_225 < 2 )
V_225 = 2 ;
else if ( V_225 > 256 ) {
V_225 = 256 ;
F_9 ( 1 , L_67 ) ;
}
V_226 = F_95 ( V_225 ,
V_223 ) ;
if ( V_226 == NULL ) {
F_96 ( V_222 ) ;
F_93 ( V_218 ) ;
F_93 ( V_223 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_97 ( void )
{
F_96 ( V_222 ) ;
F_93 ( V_218 ) ;
F_96 ( V_226 ) ;
F_93 ( V_223 ) ;
}
static int
F_98 ( void )
{
V_227 = F_91 ( L_68 ,
sizeof( struct V_228 ) , 0 ,
V_220 , NULL ) ;
if ( V_227 == NULL )
return - V_29 ;
V_229 = F_95 ( 3 , V_227 ) ;
if ( V_229 == NULL ) {
F_93 ( V_227 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_99 ( void )
{
F_96 ( V_229 ) ;
F_93 ( V_227 ) ;
}
static int T_3
F_100 ( void )
{
int V_6 = 0 ;
F_101 () ;
F_28 ( & V_230 ) ;
#ifdef F_102
F_28 ( & V_231 ) ;
F_28 ( & V_232 ) ;
#endif
F_103 ( & V_233 , 0 ) ;
F_103 ( & V_234 , 0 ) ;
F_103 ( & V_235 , 0 ) ;
F_103 ( & V_236 , 0 ) ;
F_103 ( & V_237 , 0 ) ;
F_103 ( & V_238 , 0 ) ;
F_103 ( & V_239 , 0 ) ;
#ifdef F_104
F_103 ( & V_240 , 0 ) ;
F_103 ( & V_241 , 0 ) ;
#endif
F_103 ( & V_242 , 0 ) ;
V_243 = 0 ;
V_244 = 0 ;
V_245 = 0 ;
F_105 ( & V_143 ) ;
F_105 ( & V_246 ) ;
F_105 ( & V_247 ) ;
if ( V_248 < 2 ) {
V_248 = 2 ;
F_9 ( 1 , L_69 ) ;
} else if ( V_248 > 256 ) {
V_248 = 256 ;
F_9 ( 1 , L_70 ) ;
}
V_6 = F_106 () ;
if ( V_6 )
goto V_249;
V_6 = F_90 () ;
if ( V_6 )
goto V_250;
V_6 = F_98 () ;
if ( V_6 )
goto V_251;
V_6 = F_94 () ;
if ( V_6 )
goto V_252;
#ifdef F_107
V_6 = F_108 ( & V_253 ) ;
if ( V_6 )
goto V_254;
#endif
#ifdef F_109
V_6 = F_110 () ;
if ( V_6 )
goto V_255;
#endif
V_6 = F_111 ( & V_256 ) ;
if ( V_6 )
goto V_257;
return 0 ;
V_257:
#ifdef F_109
F_112 () ;
V_255:
#endif
#ifdef F_107
F_113 ( & V_253 ) ;
V_254:
#endif
F_97 () ;
V_252:
F_99 () ;
V_251:
F_92 () ;
V_250:
F_114 () ;
V_249:
F_115 () ;
return V_6 ;
}
static void T_4
F_116 ( void )
{
F_9 ( V_258 , L_71 ) ;
F_115 () ;
F_114 () ;
#ifdef F_117
F_118 () ;
#endif
#ifdef F_109
F_119 () ;
F_112 () ;
#endif
#ifdef F_107
F_113 ( & V_253 ) ;
#endif
F_120 ( & V_256 ) ;
F_92 () ;
F_99 () ;
F_97 () ;
}
