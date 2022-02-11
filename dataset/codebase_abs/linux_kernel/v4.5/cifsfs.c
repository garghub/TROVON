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
V_2 -> V_28 = & V_8 -> V_29 ;
V_2 -> V_30 = V_31 ;
V_2 -> V_32 = 14 ;
V_7 = F_10 ( V_2 ) ;
if ( F_11 ( V_7 ) ) {
V_11 = F_12 ( V_7 ) ;
goto V_33;
}
if ( V_10 -> V_34 )
V_2 -> V_35 = & V_36 ;
else
V_2 -> V_35 = & V_37 ;
V_2 -> V_38 = F_13 ( V_7 ) ;
if ( ! V_2 -> V_38 ) {
V_11 = - V_39 ;
goto V_33;
}
#ifdef F_14
if ( V_8 -> V_12 & V_40 ) {
F_15 ( V_41 , L_1 ) ;
V_2 -> V_42 = & V_43 ;
}
#endif
return 0 ;
V_33:
F_15 ( V_44 , L_2 , V_45 ) ;
return V_11 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_8 ) ;
}
static int
F_19 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_1 * V_2 = V_46 -> V_49 ;
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_50 * V_4 = V_10 -> V_16 -> V_4 ;
unsigned int V_51 ;
int V_11 = 0 ;
V_51 = F_20 () ;
V_48 -> V_52 = V_53 ;
V_48 -> V_54 = 0 ;
V_48 -> V_55 = 0 ;
if ( V_4 -> V_56 -> V_57 )
V_11 = V_4 -> V_56 -> V_57 ( V_51 , V_10 , V_48 ) ;
F_21 ( V_51 ) ;
return 0 ;
}
static long F_22 ( struct V_58 * V_58 , int V_59 , T_1 V_60 , T_1 V_61 )
{
struct V_3 * V_8 = F_23 ( V_58 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_50 * V_4 = V_10 -> V_16 -> V_4 ;
if ( V_4 -> V_56 -> V_62 )
return V_4 -> V_56 -> V_62 ( V_58 , V_10 , V_59 , V_60 , V_61 ) ;
return - V_63 ;
}
static int F_24 ( struct V_7 * V_7 , int V_64 )
{
struct V_3 * V_8 ;
V_8 = F_2 ( V_7 -> V_65 ) ;
if ( V_8 -> V_12 & V_66 ) {
if ( ( V_64 & V_67 ) && ! F_25 ( V_7 ) )
return - V_68 ;
else
return 0 ;
} else
return F_26 ( V_7 , V_64 ) ;
}
static struct V_7 *
F_27 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
V_70 = F_28 ( V_71 , V_72 ) ;
if ( ! V_70 )
return NULL ;
V_70 -> V_73 = 0x20 ;
V_70 -> time = 0 ;
F_29 ( V_70 , 0 ) ;
V_70 -> V_74 = 0 ;
F_30 ( & V_70 -> V_75 ) ;
V_70 -> V_76 = 0 ;
V_70 -> V_77 . V_78 = 14 ;
V_70 -> V_79 = 0 ;
V_70 -> V_80 = 0 ;
V_70 -> V_81 = 0 ;
V_70 -> V_82 = 0 ;
#ifdef F_31
F_32 ( V_70 -> V_83 , V_84 ) ;
#endif
F_33 ( & V_70 -> V_85 ) ;
F_33 ( & V_70 -> V_86 ) ;
return & V_70 -> V_77 ;
}
static void F_34 ( struct V_87 * V_88 )
{
struct V_7 * V_7 = F_35 ( V_88 , struct V_7 , V_89 ) ;
F_36 ( V_71 , F_37 ( V_7 ) ) ;
}
static void
F_38 ( struct V_7 * V_7 )
{
F_39 ( & V_7 -> V_89 , F_34 ) ;
}
static void
F_40 ( struct V_7 * V_7 )
{
F_41 ( & V_7 -> V_90 ) ;
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
}
static void
F_44 ( struct V_91 * V_92 , struct V_50 * V_4 )
{
struct V_93 * V_94 = (struct V_93 * ) & V_4 -> V_95 ;
struct V_96 * V_97 = (struct V_96 * ) & V_4 -> V_95 ;
F_45 ( V_92 , L_3 ) ;
switch ( V_4 -> V_95 . V_98 ) {
case V_99 :
F_46 ( V_92 , L_4 , & V_94 -> V_100 . V_101 ) ;
break;
case V_102 :
F_46 ( V_92 , L_5 , & V_97 -> V_103 . V_104 ) ;
if ( V_97 -> V_105 )
F_46 ( V_92 , L_6 , V_97 -> V_105 ) ;
break;
default:
F_45 ( V_92 , L_7 ) ;
}
}
static void
F_47 ( struct V_91 * V_92 , struct V_106 * V_16 )
{
if ( V_16 -> V_107 == V_108 ) {
if ( V_16 -> V_109 == NULL )
F_45 ( V_92 , L_8 ) ;
return;
}
F_45 ( V_92 , L_9 ) ;
switch ( V_16 -> V_107 ) {
case V_110 :
F_45 ( V_92 , L_10 ) ;
break;
case V_111 :
F_45 ( V_92 , L_11 ) ;
break;
case V_112 :
F_45 ( V_92 , L_12 ) ;
break;
case V_113 :
F_45 ( V_92 , L_13 ) ;
break;
case V_114 :
F_45 ( V_92 , L_14 ) ;
break;
default:
F_45 ( V_92 , L_15 ) ;
break;
}
if ( V_16 -> V_115 )
F_45 ( V_92 , L_16 ) ;
}
static void
F_48 ( struct V_91 * V_92 , struct V_3 * V_8 )
{
F_45 ( V_92 , L_17 ) ;
if ( V_8 -> V_12 & V_116 )
F_45 ( V_92 , L_18 ) ;
else if ( V_8 -> V_12 & V_117 )
F_45 ( V_92 , L_19 ) ;
else
F_45 ( V_92 , L_20 ) ;
}
static void
F_49 ( struct V_91 * V_92 , struct V_118 * V_119 )
{
struct V_118 * V_120 ;
V_120 = F_50 () ;
if ( V_120 != V_119 )
F_46 ( V_92 , L_21 , V_119 -> V_121 ) ;
F_51 ( V_120 ) ;
}
static int
F_52 ( struct V_91 * V_92 , struct V_46 * V_122 )
{
struct V_3 * V_8 = F_2 ( V_122 -> V_49 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_123 * V_124 ;
V_124 = (struct V_123 * ) & V_10 -> V_16 -> V_4 -> V_124 ;
F_53 ( V_92 , L_22 , V_10 -> V_16 -> V_4 -> V_18 -> V_125 ) ;
F_47 ( V_92 , V_10 -> V_16 ) ;
F_48 ( V_92 , V_8 ) ;
if ( V_8 -> V_12 & V_126 )
F_45 ( V_92 , L_23 ) ;
else if ( V_10 -> V_16 -> V_109 )
F_53 ( V_92 , L_24 , V_10 -> V_16 -> V_109 ) ;
if ( V_10 -> V_16 -> V_127 )
F_53 ( V_92 , L_25 , V_10 -> V_16 -> V_127 ) ;
if ( V_124 -> V_128 != V_129 ) {
struct V_93 * V_130 ;
struct V_96 * V_131 ;
V_130 = (struct V_93 * ) V_124 ;
V_131 = (struct V_96 * ) V_124 ;
if ( V_124 -> V_128 == V_102 )
F_46 ( V_92 , L_26 ,
& V_131 -> V_103 ) ;
else if ( V_124 -> V_128 == V_99 )
F_46 ( V_92 , L_27 ,
& V_130 -> V_100 . V_101 ) ;
else
F_46 ( V_92 , L_28 ,
( int ) ( V_124 -> V_128 ) ) ;
}
F_46 ( V_92 , L_29 ,
F_54 ( & V_132 , V_8 -> V_133 ) ) ;
if ( V_8 -> V_12 & V_134 )
F_45 ( V_92 , L_30 ) ;
else
F_45 ( V_92 , L_31 ) ;
F_46 ( V_92 , L_32 ,
F_55 ( & V_132 , V_8 -> V_135 ) ) ;
if ( V_8 -> V_12 & V_136 )
F_45 ( V_92 , L_33 ) ;
else
F_45 ( V_92 , L_34 ) ;
F_44 ( V_92 , V_10 -> V_16 -> V_4 ) ;
if ( ! V_10 -> V_137 )
F_46 ( V_92 , L_35 ,
V_8 -> V_138 ,
V_8 -> V_139 ) ;
F_49 ( V_92 , V_8 -> V_140 ) ;
if ( V_10 -> V_141 )
F_45 ( V_92 , L_36 ) ;
if ( V_10 -> V_34 )
F_45 ( V_92 , L_37 ) ;
if ( V_10 -> V_142 )
F_45 ( V_92 , L_38 ) ;
if ( V_10 -> V_143 )
F_45 ( V_92 , L_39 ) ;
else if ( V_10 -> V_144 )
F_45 ( V_92 , L_40 ) ;
if ( V_10 -> V_137 )
F_45 ( V_92 , L_41 ) ;
else
F_45 ( V_92 , L_42 ) ;
if ( V_8 -> V_12 & V_145 )
F_45 ( V_92 , L_43 ) ;
if ( V_8 -> V_12 & V_146 )
F_45 ( V_92 , L_44 ) ;
if ( V_8 -> V_12 & V_40 )
F_45 ( V_92 , L_45 ) ;
if ( V_8 -> V_12 & V_147 )
F_45 ( V_92 , L_46 ) ;
if ( V_8 -> V_12 & V_148 )
F_45 ( V_92 , L_47 ) ;
if ( V_8 -> V_12 & V_149 )
F_45 ( V_92 , L_48 ) ;
if ( V_8 -> V_12 & V_150 )
F_45 ( V_92 , L_49 ) ;
if ( V_8 -> V_12 & V_151 )
F_45 ( V_92 , L_50 ) ;
if ( V_8 -> V_12 & V_152 )
F_45 ( V_92 , L_51 ) ;
if ( V_8 -> V_12 & V_153 )
F_45 ( V_92 , L_52 ) ;
if ( V_8 -> V_12 & V_154 )
F_45 ( V_92 , L_53 ) ;
if ( V_8 -> V_12 & V_155 )
F_45 ( V_92 , L_54 ) ;
if ( V_122 -> V_49 -> V_14 & V_15 )
F_45 ( V_92 , L_55 ) ;
if ( V_8 -> V_12 & V_156 )
F_45 ( V_92 , L_56 ) ;
if ( V_8 -> V_12 & V_157 )
F_45 ( V_92 , L_57 ) ;
if ( V_8 -> V_12 & V_158 )
F_45 ( V_92 , L_58 ) ;
if ( V_8 -> V_12 & V_66 )
F_45 ( V_92 , L_59 ) ;
if ( V_8 -> V_12 & V_159 )
F_46 ( V_92 , L_60 ,
F_54 ( & V_132 ,
V_8 -> V_160 ) ) ;
if ( V_8 -> V_12 & V_161 )
F_46 ( V_92 , L_61 ,
F_55 ( & V_132 ,
V_8 -> V_162 ) ) ;
F_46 ( V_92 , L_62 , V_8 -> V_163 ) ;
F_46 ( V_92 , L_63 , V_8 -> V_164 ) ;
F_46 ( V_92 , L_64 ,
V_10 -> V_16 -> V_4 -> V_165 / V_166 ) ;
F_46 ( V_92 , L_65 , V_8 -> V_167 / V_166 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
if ( V_8 == NULL )
return;
V_10 = F_9 ( V_8 ) ;
F_57 ( & V_168 ) ;
if ( ( V_10 -> V_169 > 1 ) || ( V_10 -> V_170 == V_171 ) ) {
F_58 ( & V_168 ) ;
return;
} else if ( V_10 -> V_169 == 1 )
V_10 -> V_170 = V_171 ;
F_58 ( & V_168 ) ;
if ( V_10 -> V_16 && V_10 -> V_16 -> V_4 ) {
F_15 ( V_41 , L_66 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_172 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_173 ) ;
F_60 ( 1 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_173 ) ;
F_60 ( 1 ) ;
}
return;
}
static int F_61 ( struct V_91 * V_92 , struct V_46 * V_122 )
{
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int * V_74 , char * V_174 )
{
F_63 ( V_2 ) ;
* V_74 |= V_175 ;
return 0 ;
}
static int F_64 ( struct V_7 * V_7 )
{
struct V_3 * V_8 = F_2 ( V_7 -> V_65 ) ;
return ! ( V_8 -> V_12 & V_40 ) ||
F_65 ( V_7 ) ;
}
static struct V_46 *
F_66 ( struct V_176 * V_177 , struct V_1 * V_2 )
{
struct V_46 * V_46 ;
struct V_3 * V_8 = F_2 ( V_2 ) ;
char * V_178 = NULL ;
char * V_92 , * V_179 ;
char V_180 ;
V_178 = F_67 ( V_177 , V_8 ,
F_9 ( V_8 ) ) ;
if ( V_178 == NULL )
return F_68 ( - V_39 ) ;
F_15 ( V_41 , L_67 , V_178 ) ;
V_180 = F_69 ( V_8 ) ;
V_46 = F_70 ( V_2 -> V_38 ) ;
V_179 = V_92 = V_178 ;
do {
struct V_7 * V_181 = F_71 ( V_46 ) ;
struct V_46 * V_182 ;
if ( ! V_181 ) {
F_72 ( V_46 ) ;
V_46 = F_68 ( - V_183 ) ;
break;
}
if ( ! F_73 ( V_181 -> V_184 ) ) {
F_72 ( V_46 ) ;
V_46 = F_68 ( - V_185 ) ;
break;
}
while ( * V_92 == V_180 )
V_92 ++ ;
if ( ! * V_92 )
break;
V_179 = V_92 ++ ;
while ( * V_92 && * V_92 != V_180 )
V_92 ++ ;
F_74 ( V_181 ) ;
V_182 = F_75 ( V_179 , V_46 , V_92 - V_179 ) ;
F_76 ( V_181 ) ;
F_72 ( V_46 ) ;
V_46 = V_182 ;
} while ( ! F_11 ( V_46 ) );
F_77 ( V_178 ) ;
return V_46 ;
}
static int F_78 ( struct V_1 * V_2 , void * V_174 )
{
struct V_186 * V_187 = V_174 ;
V_2 -> V_188 = V_187 -> V_8 ;
return F_79 ( V_2 , NULL ) ;
}
static struct V_46 *
F_80 ( struct V_189 * V_190 ,
int V_74 , const char * V_191 , void * V_174 )
{
int V_11 ;
struct V_1 * V_2 ;
struct V_3 * V_8 ;
struct V_176 * V_192 ;
struct V_186 V_187 ;
struct V_46 * V_122 ;
F_15 ( V_41 , L_68 , V_191 , V_74 ) ;
V_192 = F_81 ( ( char * ) V_174 , V_191 ) ;
if ( F_11 ( V_192 ) )
return F_82 ( V_192 ) ;
V_8 = F_83 ( sizeof( struct V_3 ) , V_72 ) ;
if ( V_8 == NULL ) {
V_122 = F_68 ( - V_39 ) ;
goto V_193;
}
V_8 -> V_194 = F_84 ( V_174 , V_195 , V_72 ) ;
if ( V_8 -> V_194 == NULL ) {
V_122 = F_68 ( - V_39 ) ;
goto V_196;
}
F_85 ( V_192 , V_8 ) ;
V_11 = F_86 ( V_8 , V_192 ) ;
if ( V_11 ) {
if ( ! ( V_74 & V_197 ) )
F_15 ( V_44 , L_69 ,
V_11 ) ;
V_122 = F_68 ( V_11 ) ;
goto V_198;
}
V_187 . V_177 = V_192 ;
V_187 . V_8 = V_8 ;
V_187 . V_74 = V_74 ;
V_74 |= V_175 | V_199 ;
V_2 = F_87 ( V_190 , V_200 , F_78 , V_74 , & V_187 ) ;
if ( F_11 ( V_2 ) ) {
V_122 = F_82 ( V_2 ) ;
F_18 ( V_8 ) ;
goto V_201;
}
if ( V_2 -> V_38 ) {
F_15 ( V_41 , L_70 ) ;
F_18 ( V_8 ) ;
} else {
V_11 = F_8 ( V_2 ) ;
if ( V_11 ) {
V_122 = F_68 ( V_11 ) ;
goto V_202;
}
V_2 -> V_14 |= V_203 ;
}
V_122 = F_66 ( V_192 , V_2 ) ;
if ( F_11 ( V_122 ) )
goto V_202;
F_15 ( V_41 , L_71 , V_122 ) ;
goto V_201;
V_202:
F_88 ( V_2 ) ;
V_201:
F_89 ( V_192 ) ;
return V_122 ;
V_198:
F_77 ( V_8 -> V_194 ) ;
V_196:
F_77 ( V_8 ) ;
V_193:
F_51 ( V_192 -> V_140 ) ;
goto V_201;
}
static T_2
F_90 ( struct V_204 * V_205 , struct V_206 * V_207 )
{
T_2 V_11 ;
struct V_7 * V_7 = F_91 ( V_205 -> V_208 ) ;
if ( V_205 -> V_208 -> V_209 & V_210 )
return F_92 ( V_205 , V_207 ) ;
V_11 = F_93 ( V_7 ) ;
if ( V_11 )
return V_11 ;
return F_94 ( V_205 , V_207 ) ;
}
static T_2 F_95 ( struct V_204 * V_205 , struct V_206 * V_211 )
{
struct V_7 * V_7 = F_91 ( V_205 -> V_208 ) ;
struct V_69 * V_212 = F_37 ( V_7 ) ;
T_2 V_213 ;
int V_11 ;
if ( V_205 -> V_208 -> V_209 & V_210 ) {
V_213 = F_96 ( V_205 , V_211 ) ;
if ( V_213 > 0 && F_97 ( V_212 ) ) {
F_98 ( V_7 ) ;
F_15 ( V_41 ,
L_72 ,
V_7 ) ;
V_212 -> V_214 = 0 ;
}
return V_213 ;
}
V_213 = F_99 ( V_212 ) ;
if ( V_213 )
return V_213 ;
V_213 = F_100 ( V_205 , V_211 ) ;
if ( F_101 ( F_37 ( V_7 ) ) )
goto V_201;
V_11 = F_102 ( V_7 -> V_215 ) ;
if ( V_11 )
F_15 ( V_41 , L_73 ,
V_11 , V_7 ) ;
V_201:
F_103 ( V_212 ) ;
return V_213 ;
}
static T_1 F_104 ( struct V_58 * V_58 , T_1 V_216 , int V_217 )
{
if ( V_217 != V_218 && V_217 != V_219 ) {
int V_11 ;
struct V_7 * V_7 = F_91 ( V_58 ) ;
if ( ! F_97 ( F_37 ( V_7 ) ) && V_7 -> V_215 &&
V_7 -> V_215 -> V_220 != 0 ) {
V_11 = F_105 ( V_7 -> V_215 ) ;
if ( V_11 ) {
F_106 ( V_7 -> V_215 , V_11 ) ;
return V_11 ;
}
}
F_37 ( V_7 ) -> time = 0 ;
V_11 = F_107 ( V_58 ) ;
if ( V_11 < 0 )
return ( T_1 ) V_11 ;
}
return F_108 ( V_58 , V_216 , V_217 ) ;
}
static int
F_109 ( struct V_58 * V_58 , long V_221 , struct V_222 * * V_223 , void * * V_224 )
{
struct V_7 * V_7 = F_91 ( V_58 ) ;
struct V_225 * V_226 = V_58 -> V_227 ;
if ( ! ( F_110 ( V_7 -> V_184 ) ) )
return - V_228 ;
if ( V_221 == V_229 ||
( ( V_221 == V_230 ) && F_97 ( F_37 ( V_7 ) ) ) ||
( ( V_221 == V_231 ) && F_101 ( F_37 ( V_7 ) ) ) )
return F_111 ( V_58 , V_221 , V_223 , V_224 ) ;
else if ( F_112 ( V_226 -> V_232 ) -> V_233 &&
! F_97 ( F_37 ( V_7 ) ) )
return F_111 ( V_58 , V_221 , V_223 , V_224 ) ;
else
return - V_234 ;
}
static int F_113 ( struct V_58 * V_235 , T_1 V_60 ,
struct V_58 * V_236 , T_1 V_237 , T_3 V_61 )
{
struct V_7 * V_238 = F_91 ( V_235 ) ;
struct V_7 * V_239 = F_91 ( V_236 ) ;
struct V_225 * V_240 = V_235 -> V_227 ;
struct V_225 * V_241 = V_236 -> V_227 ;
struct V_9 * V_242 = F_112 ( V_241 -> V_232 ) ;
unsigned int V_51 ;
int V_11 ;
F_15 ( V_41 , L_74 ) ;
V_51 = F_20 () ;
if ( ! V_235 -> V_227 || ! V_236 -> V_227 ) {
V_11 = - V_243 ;
F_15 ( V_44 , L_75 ) ;
goto V_201;
}
F_114 ( V_239 , V_238 ) ;
if ( V_61 == 0 )
V_61 = V_238 -> V_244 - V_60 ;
F_15 ( V_41 , L_76 ) ;
F_115 ( & V_239 -> V_90 , V_237 ,
F_116 ( V_237 + V_61 ) - 1 ) ;
if ( V_242 -> V_16 -> V_4 -> V_56 -> V_245 )
V_11 = V_242 -> V_16 -> V_4 -> V_56 -> V_245 ( V_51 ,
V_240 , V_241 , V_60 , V_61 , V_237 ) ;
else
V_11 = - V_63 ;
F_37 ( V_239 ) -> time = 0 ;
F_117 ( V_238 , V_239 ) ;
V_201:
F_21 ( V_51 ) ;
return V_11 ;
}
static void
F_118 ( void * V_7 )
{
struct V_69 * V_246 = V_7 ;
F_119 ( & V_246 -> V_77 ) ;
F_120 ( & V_246 -> V_247 ) ;
}
static int T_4
F_121 ( void )
{
V_71 = F_122 ( L_77 ,
sizeof( struct V_69 ) ,
0 , ( V_248 |
V_249 | V_250 ) ,
F_118 ) ;
if ( V_71 == NULL )
return - V_39 ;
return 0 ;
}
static void
F_123 ( void )
{
F_124 () ;
F_125 ( V_71 ) ;
}
static int
F_126 ( void )
{
T_5 V_251 = V_252 ;
#ifdef F_31
V_251 = V_253 ;
#endif
if ( V_254 < 8192 ) {
V_254 = 8192 ;
} else if ( V_254 > 1024 * 127 ) {
V_254 = 1024 * 127 ;
} else {
V_254 &= 0x1FE00 ;
}
V_255 = F_122 ( L_78 ,
V_254 + V_251 , 0 ,
V_256 , NULL ) ;
if ( V_255 == NULL )
return - V_39 ;
if ( V_257 < 1 )
V_257 = 1 ;
else if ( V_257 > 64 ) {
V_257 = 64 ;
F_15 ( V_44 , L_79 ) ;
}
V_258 = F_127 ( V_257 ,
V_255 ) ;
if ( V_258 == NULL ) {
F_125 ( V_255 ) ;
return - V_39 ;
}
V_259 = F_122 ( L_80 ,
V_260 , 0 , V_256 ,
NULL ) ;
if ( V_259 == NULL ) {
F_128 ( V_258 ) ;
F_125 ( V_255 ) ;
return - V_39 ;
}
if ( V_261 < 2 )
V_261 = 2 ;
else if ( V_261 > 256 ) {
V_261 = 256 ;
F_15 ( V_41 , L_81 ) ;
}
V_262 = F_127 ( V_261 ,
V_259 ) ;
if ( V_262 == NULL ) {
F_128 ( V_258 ) ;
F_125 ( V_255 ) ;
F_125 ( V_259 ) ;
return - V_39 ;
}
return 0 ;
}
static void
F_129 ( void )
{
F_128 ( V_258 ) ;
F_125 ( V_255 ) ;
F_128 ( V_262 ) ;
F_125 ( V_259 ) ;
}
static int
F_130 ( void )
{
V_263 = F_122 ( L_82 ,
sizeof( struct V_264 ) , 0 ,
V_256 , NULL ) ;
if ( V_263 == NULL )
return - V_39 ;
V_265 = F_127 ( 3 , V_263 ) ;
if ( V_265 == NULL ) {
F_125 ( V_263 ) ;
return - V_39 ;
}
return 0 ;
}
static void
F_131 ( void )
{
F_128 ( V_265 ) ;
F_125 ( V_263 ) ;
}
static int T_4
F_132 ( void )
{
int V_11 = 0 ;
F_133 () ;
F_33 ( & V_266 ) ;
#ifdef F_134
F_33 ( & V_267 ) ;
F_33 ( & V_268 ) ;
#endif
F_135 ( & V_269 , 0 ) ;
F_135 ( & V_270 , 0 ) ;
F_135 ( & V_271 , 0 ) ;
F_135 ( & V_272 , 0 ) ;
F_135 ( & V_273 , 0 ) ;
F_135 ( & V_274 , 0 ) ;
F_135 ( & V_275 , 0 ) ;
#ifdef F_136
F_135 ( & V_276 , 0 ) ;
F_135 ( & V_277 , 0 ) ;
#endif
F_135 ( & V_278 , 0 ) ;
V_279 = 0 ;
V_280 = 0 ;
V_281 = 0 ;
F_30 ( & V_168 ) ;
F_30 ( & V_282 ) ;
F_30 ( & V_283 ) ;
if ( V_284 < 2 ) {
V_284 = 2 ;
F_15 ( V_41 , L_83 ) ;
} else if ( V_284 > V_285 ) {
V_284 = V_285 ;
F_15 ( V_41 , L_84 ,
V_285 ) ;
}
V_286 = F_137 ( L_85 , V_287 | V_288 , 0 ) ;
if ( ! V_286 ) {
V_11 = - V_39 ;
goto V_289;
}
V_11 = F_138 () ;
if ( V_11 )
goto V_290;
V_11 = F_121 () ;
if ( V_11 )
goto V_291;
V_11 = F_130 () ;
if ( V_11 )
goto V_292;
V_11 = F_126 () ;
if ( V_11 )
goto V_293;
#ifdef F_139
V_11 = F_140 ( & V_294 ) ;
if ( V_11 )
goto V_295;
#endif
#ifdef F_141
V_11 = F_142 () ;
if ( V_11 )
goto V_296;
#endif
V_11 = F_143 ( & V_297 ) ;
if ( V_11 )
goto V_298;
return 0 ;
V_298:
#ifdef F_141
F_144 () ;
V_296:
#endif
#ifdef F_139
F_145 ( & V_294 ) ;
V_295:
#endif
F_129 () ;
V_293:
F_131 () ;
V_292:
F_123 () ;
V_291:
F_146 () ;
V_290:
F_147 ( V_286 ) ;
V_289:
F_148 () ;
return V_11 ;
}
static void T_6
F_149 ( void )
{
F_15 ( V_299 , L_86 ) ;
F_150 ( & V_297 ) ;
F_151 () ;
#ifdef F_141
F_144 () ;
#endif
#ifdef F_139
F_145 ( & V_294 ) ;
#endif
F_129 () ;
F_131 () ;
F_123 () ;
F_146 () ;
F_147 ( V_286 ) ;
F_148 () ;
}
