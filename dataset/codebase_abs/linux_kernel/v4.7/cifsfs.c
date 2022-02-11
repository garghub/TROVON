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
struct V_9 * V_10 ;
int V_11 = 0 ;
V_8 = F_2 ( V_2 ) ;
V_10 = F_9 ( V_8 ) ;
if ( V_8 -> V_12 & V_13 )
V_2 -> V_14 |= V_15 ;
if ( V_10 -> V_16 -> V_17 & V_10 -> V_16 -> V_4 -> V_18 -> V_19 )
V_2 -> V_20 = V_21 ;
else
V_2 -> V_20 = V_22 ;
V_2 -> V_23 = 100 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = & V_27 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = & V_8 -> V_31 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_34 = 14 ;
V_7 = F_10 ( V_2 ) ;
if ( F_11 ( V_7 ) ) {
V_11 = F_12 ( V_7 ) ;
goto V_35;
}
if ( V_10 -> V_36 )
V_2 -> V_37 = & V_38 ;
else
V_2 -> V_37 = & V_39 ;
V_2 -> V_40 = F_13 ( V_7 ) ;
if ( ! V_2 -> V_40 ) {
V_11 = - V_41 ;
goto V_35;
}
#ifdef F_14
if ( V_8 -> V_12 & V_42 ) {
F_15 ( V_43 , L_1 ) ;
V_2 -> V_44 = & V_45 ;
}
#endif
return 0 ;
V_35:
F_15 ( V_46 , L_2 , V_47 ) ;
return V_11 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_8 ) ;
}
static int
F_19 ( struct V_48 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_51 ;
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_52 * V_4 = V_10 -> V_16 -> V_4 ;
unsigned int V_53 ;
int V_11 = 0 ;
V_53 = F_20 () ;
V_50 -> V_54 = V_55 ;
V_50 -> V_56 = 0 ;
V_50 -> V_57 = 0 ;
if ( V_4 -> V_58 -> V_59 )
V_11 = V_4 -> V_58 -> V_59 ( V_53 , V_10 , V_50 ) ;
F_21 ( V_53 ) ;
return 0 ;
}
static long F_22 ( struct V_60 * V_60 , int V_61 , T_1 V_62 , T_1 V_63 )
{
struct V_3 * V_8 = F_23 ( V_60 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_52 * V_4 = V_10 -> V_16 -> V_4 ;
if ( V_4 -> V_58 -> V_64 )
return V_4 -> V_58 -> V_64 ( V_60 , V_10 , V_61 , V_62 , V_63 ) ;
return - V_65 ;
}
static int F_24 ( struct V_7 * V_7 , int V_66 )
{
struct V_3 * V_8 ;
V_8 = F_2 ( V_7 -> V_67 ) ;
if ( V_8 -> V_12 & V_68 ) {
if ( ( V_66 & V_69 ) && ! F_25 ( V_7 ) )
return - V_70 ;
else
return 0 ;
} else
return F_26 ( V_7 , V_66 ) ;
}
static struct V_7 *
F_27 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
V_72 = F_28 ( V_73 , V_74 ) ;
if ( ! V_72 )
return NULL ;
V_72 -> V_75 = 0x20 ;
V_72 -> time = 0 ;
F_29 ( V_72 , 0 ) ;
V_72 -> V_76 = 0 ;
F_30 ( & V_72 -> V_77 ) ;
V_72 -> V_78 = 0 ;
V_72 -> V_79 . V_80 = 14 ;
V_72 -> V_81 = 0 ;
V_72 -> V_82 = 0 ;
V_72 -> V_83 = 0 ;
V_72 -> V_84 = 0 ;
#ifdef F_31
F_32 ( V_72 -> V_85 , V_86 ) ;
#endif
F_33 ( & V_72 -> V_87 ) ;
F_33 ( & V_72 -> V_88 ) ;
return & V_72 -> V_79 ;
}
static void F_34 ( struct V_89 * V_90 )
{
struct V_7 * V_7 = F_35 ( V_90 , struct V_7 , V_91 ) ;
F_36 ( V_73 , F_37 ( V_7 ) ) ;
}
static void
F_38 ( struct V_7 * V_7 )
{
F_39 ( & V_7 -> V_91 , F_34 ) ;
}
static void
F_40 ( struct V_7 * V_7 )
{
F_41 ( & V_7 -> V_92 ) ;
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
}
static void
F_44 ( struct V_93 * V_94 , struct V_52 * V_4 )
{
struct V_95 * V_96 = (struct V_95 * ) & V_4 -> V_97 ;
struct V_98 * V_99 = (struct V_98 * ) & V_4 -> V_97 ;
F_45 ( V_94 , L_3 ) ;
switch ( V_4 -> V_97 . V_100 ) {
case V_101 :
F_46 ( V_94 , L_4 , & V_96 -> V_102 . V_103 ) ;
break;
case V_104 :
F_46 ( V_94 , L_5 , & V_99 -> V_105 . V_106 ) ;
if ( V_99 -> V_107 )
F_46 ( V_94 , L_6 , V_99 -> V_107 ) ;
break;
default:
F_45 ( V_94 , L_7 ) ;
}
}
static void
F_47 ( struct V_93 * V_94 , struct V_108 * V_16 )
{
if ( V_16 -> V_109 == V_110 ) {
if ( V_16 -> V_111 == NULL )
F_45 ( V_94 , L_8 ) ;
return;
}
F_45 ( V_94 , L_9 ) ;
switch ( V_16 -> V_109 ) {
case V_112 :
F_45 ( V_94 , L_10 ) ;
break;
case V_113 :
F_45 ( V_94 , L_11 ) ;
break;
case V_114 :
F_45 ( V_94 , L_12 ) ;
break;
case V_115 :
F_45 ( V_94 , L_13 ) ;
break;
case V_116 :
F_45 ( V_94 , L_14 ) ;
break;
default:
F_45 ( V_94 , L_15 ) ;
break;
}
if ( V_16 -> V_117 )
F_45 ( V_94 , L_16 ) ;
}
static void
F_48 ( struct V_93 * V_94 , struct V_3 * V_8 )
{
F_45 ( V_94 , L_17 ) ;
if ( V_8 -> V_12 & V_118 )
F_45 ( V_94 , L_18 ) ;
else if ( V_8 -> V_12 & V_119 )
F_45 ( V_94 , L_19 ) ;
else
F_45 ( V_94 , L_20 ) ;
}
static void
F_49 ( struct V_93 * V_94 , struct V_120 * V_121 )
{
struct V_120 * V_122 ;
V_122 = F_50 () ;
if ( V_122 != V_121 )
F_46 ( V_94 , L_21 , V_121 -> V_123 ) ;
F_51 ( V_122 ) ;
}
static int
F_52 ( struct V_93 * V_94 , struct V_48 * V_124 )
{
struct V_3 * V_8 = F_2 ( V_124 -> V_51 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_125 * V_126 ;
V_126 = (struct V_125 * ) & V_10 -> V_16 -> V_4 -> V_126 ;
F_53 ( V_94 , L_22 , V_10 -> V_16 -> V_4 -> V_18 -> V_127 ) ;
F_47 ( V_94 , V_10 -> V_16 ) ;
F_48 ( V_94 , V_8 ) ;
if ( V_8 -> V_12 & V_128 )
F_45 ( V_94 , L_23 ) ;
else if ( V_10 -> V_16 -> V_111 )
F_53 ( V_94 , L_24 , V_10 -> V_16 -> V_111 ) ;
if ( V_10 -> V_16 -> V_129 )
F_53 ( V_94 , L_25 , V_10 -> V_16 -> V_129 ) ;
if ( V_126 -> V_130 != V_131 ) {
struct V_95 * V_132 ;
struct V_98 * V_133 ;
V_132 = (struct V_95 * ) V_126 ;
V_133 = (struct V_98 * ) V_126 ;
if ( V_126 -> V_130 == V_104 )
F_46 ( V_94 , L_26 ,
& V_133 -> V_105 ) ;
else if ( V_126 -> V_130 == V_101 )
F_46 ( V_94 , L_27 ,
& V_132 -> V_102 . V_103 ) ;
else
F_46 ( V_94 , L_28 ,
( int ) ( V_126 -> V_130 ) ) ;
}
F_46 ( V_94 , L_29 ,
F_54 ( & V_134 , V_8 -> V_135 ) ) ;
if ( V_8 -> V_12 & V_136 )
F_45 ( V_94 , L_30 ) ;
else
F_45 ( V_94 , L_31 ) ;
F_46 ( V_94 , L_32 ,
F_55 ( & V_134 , V_8 -> V_137 ) ) ;
if ( V_8 -> V_12 & V_138 )
F_45 ( V_94 , L_33 ) ;
else
F_45 ( V_94 , L_34 ) ;
F_44 ( V_94 , V_10 -> V_16 -> V_4 ) ;
if ( ! V_10 -> V_139 )
F_46 ( V_94 , L_35 ,
V_8 -> V_140 ,
V_8 -> V_141 ) ;
F_49 ( V_94 , V_8 -> V_142 ) ;
if ( V_10 -> V_143 )
F_45 ( V_94 , L_36 ) ;
if ( V_10 -> V_36 )
F_45 ( V_94 , L_37 ) ;
if ( V_10 -> V_144 )
F_45 ( V_94 , L_38 ) ;
if ( V_10 -> V_145 )
F_45 ( V_94 , L_39 ) ;
else if ( V_10 -> V_146 )
F_45 ( V_94 , L_40 ) ;
if ( V_10 -> V_139 )
F_45 ( V_94 , L_41 ) ;
else
F_45 ( V_94 , L_42 ) ;
if ( V_8 -> V_12 & V_147 )
F_45 ( V_94 , L_43 ) ;
if ( V_8 -> V_12 & V_148 )
F_45 ( V_94 , L_44 ) ;
if ( V_8 -> V_12 & V_42 )
F_45 ( V_94 , L_45 ) ;
if ( V_8 -> V_12 & V_149 )
F_45 ( V_94 , L_46 ) ;
if ( V_8 -> V_12 & V_150 )
F_45 ( V_94 , L_47 ) ;
if ( V_8 -> V_12 & V_151 )
F_45 ( V_94 , L_48 ) ;
if ( V_8 -> V_12 & V_152 )
F_45 ( V_94 , L_49 ) ;
if ( V_8 -> V_12 & V_153 )
F_45 ( V_94 , L_50 ) ;
if ( V_8 -> V_12 & V_154 )
F_45 ( V_94 , L_51 ) ;
if ( V_8 -> V_12 & V_155 )
F_45 ( V_94 , L_52 ) ;
if ( V_8 -> V_12 & V_156 )
F_45 ( V_94 , L_53 ) ;
if ( V_8 -> V_12 & V_157 )
F_45 ( V_94 , L_54 ) ;
if ( V_124 -> V_51 -> V_14 & V_15 )
F_45 ( V_94 , L_55 ) ;
if ( V_8 -> V_12 & V_158 )
F_45 ( V_94 , L_56 ) ;
if ( V_8 -> V_12 & V_159 )
F_45 ( V_94 , L_57 ) ;
if ( V_8 -> V_12 & V_160 )
F_45 ( V_94 , L_58 ) ;
if ( V_8 -> V_12 & V_68 )
F_45 ( V_94 , L_59 ) ;
if ( V_8 -> V_12 & V_161 )
F_46 ( V_94 , L_60 ,
F_54 ( & V_134 ,
V_8 -> V_162 ) ) ;
if ( V_8 -> V_12 & V_163 )
F_46 ( V_94 , L_61 ,
F_55 ( & V_134 ,
V_8 -> V_164 ) ) ;
F_46 ( V_94 , L_62 , V_8 -> V_165 ) ;
F_46 ( V_94 , L_63 , V_8 -> V_166 ) ;
F_46 ( V_94 , L_64 ,
V_10 -> V_16 -> V_4 -> V_167 / V_168 ) ;
F_46 ( V_94 , L_65 , V_8 -> V_169 / V_168 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
if ( V_8 == NULL )
return;
V_10 = F_9 ( V_8 ) ;
F_57 ( & V_170 ) ;
if ( ( V_10 -> V_171 > 1 ) || ( V_10 -> V_172 == V_173 ) ) {
F_58 ( & V_170 ) ;
return;
} else if ( V_10 -> V_171 == 1 )
V_10 -> V_172 = V_173 ;
F_58 ( & V_170 ) ;
if ( V_10 -> V_16 && V_10 -> V_16 -> V_4 ) {
F_15 ( V_43 , L_66 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_174 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_175 ) ;
F_60 ( 1 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_175 ) ;
F_60 ( 1 ) ;
}
return;
}
static int F_61 ( struct V_93 * V_94 , struct V_48 * V_124 )
{
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int * V_76 , char * V_176 )
{
F_63 ( V_2 ) ;
* V_76 |= V_177 ;
return 0 ;
}
static int F_64 ( struct V_7 * V_7 )
{
struct V_3 * V_8 = F_2 ( V_7 -> V_67 ) ;
return ! ( V_8 -> V_12 & V_42 ) ||
F_65 ( V_7 ) ;
}
static struct V_48 *
F_66 ( struct V_178 * V_179 , struct V_1 * V_2 )
{
struct V_48 * V_48 ;
struct V_3 * V_8 = F_2 ( V_2 ) ;
char * V_180 = NULL ;
char * V_94 , * V_181 ;
char V_182 ;
V_180 = F_67 ( V_179 , V_8 ,
F_9 ( V_8 ) ) ;
if ( V_180 == NULL )
return F_68 ( - V_41 ) ;
F_15 ( V_43 , L_67 , V_180 ) ;
V_182 = F_69 ( V_8 ) ;
V_48 = F_70 ( V_2 -> V_40 ) ;
V_181 = V_94 = V_180 ;
do {
struct V_7 * V_183 = F_71 ( V_48 ) ;
struct V_48 * V_184 ;
if ( ! V_183 ) {
F_72 ( V_48 ) ;
V_48 = F_68 ( - V_185 ) ;
break;
}
if ( ! F_73 ( V_183 -> V_186 ) ) {
F_72 ( V_48 ) ;
V_48 = F_68 ( - V_187 ) ;
break;
}
while ( * V_94 == V_182 )
V_94 ++ ;
if ( ! * V_94 )
break;
V_181 = V_94 ++ ;
while ( * V_94 && * V_94 != V_182 )
V_94 ++ ;
V_184 = F_74 ( V_181 , V_48 , V_94 - V_181 ) ;
F_72 ( V_48 ) ;
V_48 = V_184 ;
} while ( ! F_11 ( V_48 ) );
F_75 ( V_180 ) ;
return V_48 ;
}
static int F_76 ( struct V_1 * V_2 , void * V_176 )
{
struct V_188 * V_189 = V_176 ;
V_2 -> V_190 = V_189 -> V_8 ;
return F_77 ( V_2 , NULL ) ;
}
static struct V_48 *
F_78 ( struct V_191 * V_192 ,
int V_76 , const char * V_193 , void * V_176 )
{
int V_11 ;
struct V_1 * V_2 ;
struct V_3 * V_8 ;
struct V_178 * V_194 ;
struct V_188 V_189 ;
struct V_48 * V_124 ;
F_15 ( V_43 , L_68 , V_193 , V_76 ) ;
V_194 = F_79 ( ( char * ) V_176 , V_193 ) ;
if ( F_11 ( V_194 ) )
return F_80 ( V_194 ) ;
V_8 = F_81 ( sizeof( struct V_3 ) , V_74 ) ;
if ( V_8 == NULL ) {
V_124 = F_68 ( - V_41 ) ;
goto V_195;
}
V_8 -> V_196 = F_82 ( V_176 , V_197 , V_74 ) ;
if ( V_8 -> V_196 == NULL ) {
V_124 = F_68 ( - V_41 ) ;
goto V_198;
}
F_83 ( V_194 , V_8 ) ;
V_11 = F_84 ( V_8 , V_194 ) ;
if ( V_11 ) {
if ( ! ( V_76 & V_199 ) )
F_15 ( V_46 , L_69 ,
V_11 ) ;
V_124 = F_68 ( V_11 ) ;
goto V_200;
}
V_189 . V_179 = V_194 ;
V_189 . V_8 = V_8 ;
V_189 . V_76 = V_76 ;
V_76 |= V_177 | V_201 ;
V_2 = F_85 ( V_192 , V_202 , F_76 , V_76 , & V_189 ) ;
if ( F_11 ( V_2 ) ) {
V_124 = F_80 ( V_2 ) ;
F_18 ( V_8 ) ;
goto V_203;
}
if ( V_2 -> V_40 ) {
F_15 ( V_43 , L_70 ) ;
F_18 ( V_8 ) ;
} else {
V_11 = F_8 ( V_2 ) ;
if ( V_11 ) {
V_124 = F_68 ( V_11 ) ;
goto V_204;
}
V_2 -> V_14 |= V_205 ;
}
V_124 = F_66 ( V_194 , V_2 ) ;
if ( F_11 ( V_124 ) )
goto V_204;
F_15 ( V_43 , L_71 , V_124 ) ;
goto V_203;
V_204:
F_86 ( V_2 ) ;
V_203:
F_87 ( V_194 ) ;
return V_124 ;
V_200:
F_75 ( V_8 -> V_196 ) ;
V_198:
F_75 ( V_8 ) ;
V_195:
F_51 ( V_194 -> V_142 ) ;
goto V_203;
}
static T_2
F_88 ( struct V_206 * V_207 , struct V_208 * V_209 )
{
T_2 V_11 ;
struct V_7 * V_7 = F_89 ( V_207 -> V_210 ) ;
if ( V_207 -> V_210 -> V_211 & V_212 )
return F_90 ( V_207 , V_209 ) ;
V_11 = F_91 ( V_7 ) ;
if ( V_11 )
return V_11 ;
return F_92 ( V_207 , V_209 ) ;
}
static T_2 F_93 ( struct V_206 * V_207 , struct V_208 * V_213 )
{
struct V_7 * V_7 = F_89 ( V_207 -> V_210 ) ;
struct V_71 * V_214 = F_37 ( V_7 ) ;
T_2 V_215 ;
int V_11 ;
if ( V_207 -> V_210 -> V_211 & V_212 ) {
V_215 = F_94 ( V_207 , V_213 ) ;
if ( V_215 > 0 && F_95 ( V_214 ) ) {
F_96 ( V_7 ) ;
F_15 ( V_43 ,
L_72 ,
V_7 ) ;
V_214 -> V_216 = 0 ;
}
return V_215 ;
}
V_215 = F_97 ( V_214 ) ;
if ( V_215 )
return V_215 ;
V_215 = F_98 ( V_207 , V_213 ) ;
if ( F_99 ( F_37 ( V_7 ) ) )
goto V_203;
V_11 = F_100 ( V_7 -> V_217 ) ;
if ( V_11 )
F_15 ( V_43 , L_73 ,
V_11 , V_7 ) ;
V_203:
F_101 ( V_214 ) ;
return V_215 ;
}
static T_1 F_102 ( struct V_60 * V_60 , T_1 V_218 , int V_219 )
{
if ( V_219 != V_220 && V_219 != V_221 ) {
int V_11 ;
struct V_7 * V_7 = F_89 ( V_60 ) ;
if ( ! F_95 ( F_37 ( V_7 ) ) && V_7 -> V_217 &&
V_7 -> V_217 -> V_222 != 0 ) {
V_11 = F_103 ( V_7 -> V_217 ) ;
if ( V_11 ) {
F_104 ( V_7 -> V_217 , V_11 ) ;
return V_11 ;
}
}
F_37 ( V_7 ) -> time = 0 ;
V_11 = F_105 ( V_60 ) ;
if ( V_11 < 0 )
return ( T_1 ) V_11 ;
}
return F_106 ( V_60 , V_218 , V_219 ) ;
}
static int
F_107 ( struct V_60 * V_60 , long V_223 , struct V_224 * * V_225 , void * * V_226 )
{
struct V_7 * V_7 = F_89 ( V_60 ) ;
struct V_227 * V_228 = V_60 -> V_229 ;
if ( ! ( F_108 ( V_7 -> V_186 ) ) )
return - V_230 ;
if ( V_223 == V_231 ||
( ( V_223 == V_232 ) && F_95 ( F_37 ( V_7 ) ) ) ||
( ( V_223 == V_233 ) && F_99 ( F_37 ( V_7 ) ) ) )
return F_109 ( V_60 , V_223 , V_225 , V_226 ) ;
else if ( F_110 ( V_228 -> V_234 ) -> V_235 &&
! F_95 ( F_37 ( V_7 ) ) )
return F_109 ( V_60 , V_223 , V_225 , V_226 ) ;
else
return - V_236 ;
}
static int F_111 ( struct V_60 * V_237 , T_1 V_62 ,
struct V_60 * V_238 , T_1 V_239 , T_3 V_63 )
{
struct V_7 * V_240 = F_89 ( V_237 ) ;
struct V_7 * V_241 = F_89 ( V_238 ) ;
struct V_227 * V_242 = V_237 -> V_229 ;
struct V_227 * V_243 = V_238 -> V_229 ;
struct V_9 * V_244 = F_110 ( V_243 -> V_234 ) ;
unsigned int V_53 ;
int V_11 ;
F_15 ( V_43 , L_74 ) ;
V_53 = F_20 () ;
if ( ! V_237 -> V_229 || ! V_238 -> V_229 ) {
V_11 = - V_245 ;
F_15 ( V_46 , L_75 ) ;
goto V_203;
}
F_112 ( V_241 , V_240 ) ;
if ( V_63 == 0 )
V_63 = V_240 -> V_246 - V_62 ;
F_15 ( V_43 , L_76 ) ;
F_113 ( & V_241 -> V_92 , V_239 ,
F_114 ( V_239 + V_63 ) - 1 ) ;
if ( V_244 -> V_16 -> V_4 -> V_58 -> V_247 )
V_11 = V_244 -> V_16 -> V_4 -> V_58 -> V_247 ( V_53 ,
V_242 , V_243 , V_62 , V_63 , V_239 ) ;
else
V_11 = - V_65 ;
F_37 ( V_241 ) -> time = 0 ;
F_115 ( V_240 , V_241 ) ;
V_203:
F_21 ( V_53 ) ;
return V_11 ;
}
static void
F_116 ( void * V_7 )
{
struct V_71 * V_248 = V_7 ;
F_117 ( & V_248 -> V_79 ) ;
F_118 ( & V_248 -> V_249 ) ;
}
static int T_4
F_119 ( void )
{
V_73 = F_120 ( L_77 ,
sizeof( struct V_71 ) ,
0 , ( V_250 |
V_251 | V_252 ) ,
F_116 ) ;
if ( V_73 == NULL )
return - V_41 ;
return 0 ;
}
static void
F_121 ( void )
{
F_122 () ;
F_123 ( V_73 ) ;
}
static int
F_124 ( void )
{
T_5 V_253 = V_254 ;
#ifdef F_31
V_253 = V_255 ;
#endif
if ( V_256 < 8192 ) {
V_256 = 8192 ;
} else if ( V_256 > 1024 * 127 ) {
V_256 = 1024 * 127 ;
} else {
V_256 &= 0x1FE00 ;
}
V_257 = F_120 ( L_78 ,
V_256 + V_253 , 0 ,
V_258 , NULL ) ;
if ( V_257 == NULL )
return - V_41 ;
if ( V_259 < 1 )
V_259 = 1 ;
else if ( V_259 > 64 ) {
V_259 = 64 ;
F_15 ( V_46 , L_79 ) ;
}
V_260 = F_125 ( V_259 ,
V_257 ) ;
if ( V_260 == NULL ) {
F_123 ( V_257 ) ;
return - V_41 ;
}
V_261 = F_120 ( L_80 ,
V_262 , 0 , V_258 ,
NULL ) ;
if ( V_261 == NULL ) {
F_126 ( V_260 ) ;
F_123 ( V_257 ) ;
return - V_41 ;
}
if ( V_263 < 2 )
V_263 = 2 ;
else if ( V_263 > 256 ) {
V_263 = 256 ;
F_15 ( V_43 , L_81 ) ;
}
V_264 = F_125 ( V_263 ,
V_261 ) ;
if ( V_264 == NULL ) {
F_126 ( V_260 ) ;
F_123 ( V_257 ) ;
F_123 ( V_261 ) ;
return - V_41 ;
}
return 0 ;
}
static void
F_127 ( void )
{
F_126 ( V_260 ) ;
F_123 ( V_257 ) ;
F_126 ( V_264 ) ;
F_123 ( V_261 ) ;
}
static int
F_128 ( void )
{
V_265 = F_120 ( L_82 ,
sizeof( struct V_266 ) , 0 ,
V_258 , NULL ) ;
if ( V_265 == NULL )
return - V_41 ;
V_267 = F_125 ( 3 , V_265 ) ;
if ( V_267 == NULL ) {
F_123 ( V_265 ) ;
return - V_41 ;
}
return 0 ;
}
static void
F_129 ( void )
{
F_126 ( V_267 ) ;
F_123 ( V_265 ) ;
}
static int T_4
F_130 ( void )
{
int V_11 = 0 ;
F_131 () ;
F_33 ( & V_268 ) ;
#ifdef F_132
F_33 ( & V_269 ) ;
F_33 ( & V_270 ) ;
#endif
F_133 ( & V_271 , 0 ) ;
F_133 ( & V_272 , 0 ) ;
F_133 ( & V_273 , 0 ) ;
F_133 ( & V_274 , 0 ) ;
F_133 ( & V_275 , 0 ) ;
F_133 ( & V_276 , 0 ) ;
F_133 ( & V_277 , 0 ) ;
#ifdef F_134
F_133 ( & V_278 , 0 ) ;
F_133 ( & V_279 , 0 ) ;
#endif
F_133 ( & V_280 , 0 ) ;
V_281 = 0 ;
V_282 = 0 ;
V_283 = 0 ;
F_30 ( & V_170 ) ;
F_30 ( & V_284 ) ;
F_30 ( & V_285 ) ;
F_32 ( & V_286 , sizeof( V_286 ) ) ;
if ( V_287 < 2 ) {
V_287 = 2 ;
F_15 ( V_43 , L_83 ) ;
} else if ( V_287 > V_288 ) {
V_287 = V_288 ;
F_15 ( V_43 , L_84 ,
V_288 ) ;
}
V_289 = F_135 ( L_85 , V_290 | V_291 , 0 ) ;
if ( ! V_289 ) {
V_11 = - V_41 ;
goto V_292;
}
V_11 = F_136 () ;
if ( V_11 )
goto V_293;
V_11 = F_119 () ;
if ( V_11 )
goto V_294;
V_11 = F_128 () ;
if ( V_11 )
goto V_295;
V_11 = F_124 () ;
if ( V_11 )
goto V_296;
#ifdef F_137
V_11 = F_138 () ;
if ( V_11 )
goto V_297;
#endif
#ifdef F_139
V_11 = F_140 () ;
if ( V_11 )
goto V_298;
#endif
V_11 = F_141 ( & V_299 ) ;
if ( V_11 )
goto V_300;
return 0 ;
V_300:
#ifdef F_139
F_142 () ;
V_298:
#endif
#ifdef F_137
F_143 () ;
V_297:
#endif
F_127 () ;
V_296:
F_129 () ;
V_295:
F_121 () ;
V_294:
F_144 () ;
V_293:
F_145 ( V_289 ) ;
V_292:
F_146 () ;
return V_11 ;
}
static void T_6
F_147 ( void )
{
F_15 ( V_301 , L_86 ) ;
F_148 ( & V_299 ) ;
F_149 () ;
#ifdef F_139
F_142 () ;
#endif
#ifdef F_137
F_150 ( & V_302 ) ;
#endif
F_127 () ;
F_129 () ;
F_121 () ;
F_144 () ;
F_145 ( V_289 ) ;
F_146 () ;
}
