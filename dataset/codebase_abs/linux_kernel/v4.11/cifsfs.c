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
F_32 ( V_72 -> V_85 ) ;
#endif
F_33 ( & V_72 -> V_86 ) ;
F_33 ( & V_72 -> V_87 ) ;
return & V_72 -> V_79 ;
}
static void F_34 ( struct V_88 * V_89 )
{
struct V_7 * V_7 = F_35 ( V_89 , struct V_7 , V_90 ) ;
F_36 ( V_73 , F_37 ( V_7 ) ) ;
}
static void
F_38 ( struct V_7 * V_7 )
{
F_39 ( & V_7 -> V_90 , F_34 ) ;
}
static void
F_40 ( struct V_7 * V_7 )
{
F_41 ( & V_7 -> V_91 ) ;
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
}
static void
F_44 ( struct V_92 * V_93 , struct V_52 * V_4 )
{
struct V_94 * V_95 = (struct V_94 * ) & V_4 -> V_96 ;
struct V_97 * V_98 = (struct V_97 * ) & V_4 -> V_96 ;
F_45 ( V_93 , L_3 ) ;
switch ( V_4 -> V_96 . V_99 ) {
case V_100 :
F_46 ( V_93 , L_4 , & V_95 -> V_101 . V_102 ) ;
break;
case V_103 :
F_46 ( V_93 , L_5 , & V_98 -> V_104 . V_105 ) ;
if ( V_98 -> V_106 )
F_46 ( V_93 , L_6 , V_98 -> V_106 ) ;
break;
default:
F_45 ( V_93 , L_7 ) ;
}
}
static void
F_47 ( struct V_92 * V_93 , struct V_107 * V_16 )
{
if ( V_16 -> V_108 == V_109 ) {
if ( V_16 -> V_110 == NULL )
F_45 ( V_93 , L_8 ) ;
return;
}
F_45 ( V_93 , L_9 ) ;
switch ( V_16 -> V_108 ) {
case V_111 :
F_45 ( V_93 , L_10 ) ;
break;
case V_112 :
F_45 ( V_93 , L_11 ) ;
break;
case V_113 :
F_45 ( V_93 , L_12 ) ;
break;
case V_114 :
F_45 ( V_93 , L_13 ) ;
break;
case V_115 :
F_45 ( V_93 , L_14 ) ;
break;
default:
F_45 ( V_93 , L_15 ) ;
break;
}
if ( V_16 -> V_116 )
F_45 ( V_93 , L_16 ) ;
}
static void
F_48 ( struct V_92 * V_93 , struct V_3 * V_8 )
{
F_45 ( V_93 , L_17 ) ;
if ( V_8 -> V_12 & V_117 )
F_45 ( V_93 , L_18 ) ;
else if ( V_8 -> V_12 & V_118 )
F_45 ( V_93 , L_19 ) ;
else
F_45 ( V_93 , L_20 ) ;
}
static void
F_49 ( struct V_92 * V_93 , struct V_119 * V_120 )
{
struct V_119 * V_121 ;
V_121 = F_50 () ;
if ( V_121 != V_120 )
F_46 ( V_93 , L_21 , V_120 -> V_122 ) ;
F_51 ( V_121 ) ;
}
static int
F_52 ( struct V_92 * V_93 , struct V_48 * V_123 )
{
struct V_3 * V_8 = F_2 ( V_123 -> V_51 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_124 * V_125 ;
V_125 = (struct V_124 * ) & V_10 -> V_16 -> V_4 -> V_125 ;
F_53 ( V_93 , L_22 , V_10 -> V_16 -> V_4 -> V_18 -> V_126 ) ;
F_47 ( V_93 , V_10 -> V_16 ) ;
F_48 ( V_93 , V_8 ) ;
if ( V_8 -> V_12 & V_127 )
F_45 ( V_93 , L_23 ) ;
else if ( V_10 -> V_16 -> V_110 )
F_53 ( V_93 , L_24 , V_10 -> V_16 -> V_110 ) ;
if ( V_10 -> V_16 -> V_128 )
F_53 ( V_93 , L_25 , V_10 -> V_16 -> V_128 ) ;
if ( V_125 -> V_129 != V_130 ) {
struct V_94 * V_131 ;
struct V_97 * V_132 ;
V_131 = (struct V_94 * ) V_125 ;
V_132 = (struct V_97 * ) V_125 ;
if ( V_125 -> V_129 == V_103 )
F_46 ( V_93 , L_26 ,
& V_132 -> V_104 ) ;
else if ( V_125 -> V_129 == V_100 )
F_46 ( V_93 , L_27 ,
& V_131 -> V_101 . V_102 ) ;
else
F_46 ( V_93 , L_28 ,
( int ) ( V_125 -> V_129 ) ) ;
}
F_46 ( V_93 , L_29 ,
F_54 ( & V_133 , V_8 -> V_134 ) ) ;
if ( V_8 -> V_12 & V_135 )
F_45 ( V_93 , L_30 ) ;
else
F_45 ( V_93 , L_31 ) ;
F_46 ( V_93 , L_32 ,
F_55 ( & V_133 , V_8 -> V_136 ) ) ;
if ( V_8 -> V_12 & V_137 )
F_45 ( V_93 , L_33 ) ;
else
F_45 ( V_93 , L_34 ) ;
F_44 ( V_93 , V_10 -> V_16 -> V_4 ) ;
if ( ! V_10 -> V_138 )
F_46 ( V_93 , L_35 ,
V_8 -> V_139 ,
V_8 -> V_140 ) ;
F_49 ( V_93 , V_8 -> V_141 ) ;
if ( V_10 -> V_142 )
F_45 ( V_93 , L_36 ) ;
if ( V_10 -> V_36 )
F_45 ( V_93 , L_37 ) ;
if ( V_10 -> V_143 )
F_45 ( V_93 , L_38 ) ;
if ( V_10 -> V_144 )
F_45 ( V_93 , L_39 ) ;
else if ( V_10 -> V_145 )
F_45 ( V_93 , L_40 ) ;
if ( V_10 -> V_138 )
F_45 ( V_93 , L_41 ) ;
else
F_45 ( V_93 , L_42 ) ;
if ( V_8 -> V_12 & V_146 )
F_45 ( V_93 , L_43 ) ;
if ( V_8 -> V_12 & V_147 )
F_45 ( V_93 , L_44 ) ;
if ( V_8 -> V_12 & V_148 )
F_45 ( V_93 , L_45 ) ;
if ( V_8 -> V_12 & V_42 )
F_45 ( V_93 , L_46 ) ;
if ( V_8 -> V_12 & V_149 )
F_45 ( V_93 , L_47 ) ;
if ( V_8 -> V_12 & V_150 )
F_45 ( V_93 , L_48 ) ;
if ( V_8 -> V_12 & V_151 )
F_45 ( V_93 , L_49 ) ;
if ( V_8 -> V_12 & V_152 )
F_45 ( V_93 , L_50 ) ;
if ( V_8 -> V_12 & V_153 )
F_45 ( V_93 , L_51 ) ;
if ( V_8 -> V_12 & V_154 )
F_45 ( V_93 , L_52 ) ;
if ( V_8 -> V_12 & V_155 )
F_45 ( V_93 , L_53 ) ;
if ( V_8 -> V_12 & V_156 )
F_45 ( V_93 , L_54 ) ;
if ( V_8 -> V_12 & V_157 )
F_45 ( V_93 , L_55 ) ;
if ( V_123 -> V_51 -> V_14 & V_15 )
F_45 ( V_93 , L_56 ) ;
if ( V_8 -> V_12 & V_158 )
F_45 ( V_93 , L_57 ) ;
if ( V_8 -> V_12 & V_159 )
F_45 ( V_93 , L_58 ) ;
if ( V_8 -> V_12 & V_160 )
F_45 ( V_93 , L_59 ) ;
if ( V_8 -> V_12 & V_68 )
F_45 ( V_93 , L_60 ) ;
if ( V_8 -> V_12 & V_161 )
F_46 ( V_93 , L_61 ,
F_54 ( & V_133 ,
V_8 -> V_162 ) ) ;
if ( V_8 -> V_12 & V_163 )
F_46 ( V_93 , L_62 ,
F_55 ( & V_133 ,
V_8 -> V_164 ) ) ;
F_46 ( V_93 , L_63 , V_8 -> V_165 ) ;
F_46 ( V_93 , L_64 , V_8 -> V_166 ) ;
F_46 ( V_93 , L_65 ,
V_10 -> V_16 -> V_4 -> V_167 / V_168 ) ;
F_46 ( V_93 , L_66 , V_8 -> V_169 / V_168 ) ;
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
F_15 ( V_43 , L_67 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_174 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_175 ) ;
F_60 ( 1 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_175 ) ;
F_60 ( 1 ) ;
}
return;
}
static int F_61 ( struct V_92 * V_93 , struct V_48 * V_123 )
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
char * V_93 , * V_181 ;
char V_182 ;
if ( V_8 -> V_12 & V_183 )
return F_67 ( V_2 -> V_40 ) ;
V_180 = F_68 ( V_179 , V_8 ,
F_9 ( V_8 ) , 0 ) ;
if ( V_180 == NULL )
return F_69 ( - V_41 ) ;
F_15 ( V_43 , L_68 , V_180 ) ;
V_182 = F_70 ( V_8 ) ;
V_48 = F_67 ( V_2 -> V_40 ) ;
V_181 = V_93 = V_180 ;
do {
struct V_7 * V_184 = F_71 ( V_48 ) ;
struct V_48 * V_185 ;
if ( ! V_184 ) {
F_72 ( V_48 ) ;
V_48 = F_69 ( - V_186 ) ;
break;
}
if ( ! F_73 ( V_184 -> V_187 ) ) {
F_72 ( V_48 ) ;
V_48 = F_69 ( - V_188 ) ;
break;
}
while ( * V_93 == V_182 )
V_93 ++ ;
if ( ! * V_93 )
break;
V_181 = V_93 ++ ;
while ( * V_93 && * V_93 != V_182 )
V_93 ++ ;
V_185 = F_74 ( V_181 , V_48 , V_93 - V_181 ) ;
F_72 ( V_48 ) ;
V_48 = V_185 ;
} while ( ! F_11 ( V_48 ) );
F_75 ( V_180 ) ;
return V_48 ;
}
static int F_76 ( struct V_1 * V_2 , void * V_176 )
{
struct V_189 * V_190 = V_176 ;
V_2 -> V_191 = V_190 -> V_8 ;
return F_77 ( V_2 , NULL ) ;
}
static struct V_48 *
F_78 ( struct V_192 * V_193 ,
int V_76 , const char * V_194 , void * V_176 )
{
int V_11 ;
struct V_1 * V_2 ;
struct V_3 * V_8 ;
struct V_178 * V_195 ;
struct V_189 V_190 ;
struct V_48 * V_123 ;
F_15 ( V_43 , L_69 , V_194 , V_76 ) ;
V_195 = F_79 ( ( char * ) V_176 , V_194 ) ;
if ( F_11 ( V_195 ) )
return F_80 ( V_195 ) ;
V_8 = F_81 ( sizeof( struct V_3 ) , V_74 ) ;
if ( V_8 == NULL ) {
V_123 = F_69 ( - V_41 ) ;
goto V_196;
}
V_8 -> V_197 = F_82 ( V_176 , V_198 , V_74 ) ;
if ( V_8 -> V_197 == NULL ) {
V_123 = F_69 ( - V_41 ) ;
goto V_199;
}
V_11 = F_83 ( V_195 , V_8 ) ;
if ( V_11 ) {
V_123 = F_69 ( V_11 ) ;
goto V_199;
}
V_11 = F_84 ( V_8 , V_195 ) ;
if ( V_11 ) {
if ( ! ( V_76 & V_200 ) )
F_15 ( V_46 , L_70 ,
V_11 ) ;
V_123 = F_69 ( V_11 ) ;
goto V_199;
}
V_190 . V_179 = V_195 ;
V_190 . V_8 = V_8 ;
V_190 . V_76 = V_76 ;
V_76 |= V_177 | V_201 ;
V_2 = F_85 ( V_193 , V_202 , F_76 , V_76 , & V_190 ) ;
if ( F_11 ( V_2 ) ) {
V_123 = F_80 ( V_2 ) ;
F_18 ( V_8 ) ;
goto V_203;
}
if ( V_2 -> V_40 ) {
F_15 ( V_43 , L_71 ) ;
F_18 ( V_8 ) ;
} else {
V_11 = F_8 ( V_2 ) ;
if ( V_11 ) {
V_123 = F_69 ( V_11 ) ;
goto V_204;
}
V_2 -> V_14 |= V_205 ;
}
V_123 = F_66 ( V_195 , V_2 ) ;
if ( F_11 ( V_123 ) )
goto V_204;
F_15 ( V_43 , L_72 , V_123 ) ;
goto V_203;
V_204:
F_86 ( V_2 ) ;
V_203:
F_87 ( V_195 ) ;
return V_123 ;
V_199:
F_75 ( V_8 -> V_206 ) ;
F_75 ( V_8 -> V_197 ) ;
F_75 ( V_8 ) ;
V_196:
F_51 ( V_195 -> V_141 ) ;
goto V_203;
}
static T_2
F_88 ( struct V_207 * V_208 , struct V_209 * V_210 )
{
T_2 V_11 ;
struct V_7 * V_7 = F_89 ( V_208 -> V_211 ) ;
if ( V_208 -> V_211 -> V_212 & V_213 )
return F_90 ( V_208 , V_210 ) ;
V_11 = F_91 ( V_7 ) ;
if ( V_11 )
return V_11 ;
return F_92 ( V_208 , V_210 ) ;
}
static T_2 F_93 ( struct V_207 * V_208 , struct V_209 * V_214 )
{
struct V_7 * V_7 = F_89 ( V_208 -> V_211 ) ;
struct V_71 * V_215 = F_37 ( V_7 ) ;
T_2 V_216 ;
int V_11 ;
if ( V_208 -> V_211 -> V_212 & V_213 ) {
V_216 = F_94 ( V_208 , V_214 ) ;
if ( V_216 > 0 && F_95 ( V_215 ) ) {
F_96 ( V_7 ) ;
F_15 ( V_43 ,
L_73 ,
V_7 ) ;
V_215 -> V_217 = 0 ;
}
return V_216 ;
}
V_216 = F_97 ( V_215 ) ;
if ( V_216 )
return V_216 ;
V_216 = F_98 ( V_208 , V_214 ) ;
if ( F_99 ( F_37 ( V_7 ) ) )
goto V_203;
V_11 = F_100 ( V_7 -> V_218 ) ;
if ( V_11 )
F_15 ( V_43 , L_74 ,
V_11 , V_7 ) ;
V_203:
F_101 ( V_215 ) ;
return V_216 ;
}
static T_1 F_102 ( struct V_60 * V_60 , T_1 V_219 , int V_220 )
{
if ( V_220 != V_221 && V_220 != V_222 ) {
int V_11 ;
struct V_7 * V_7 = F_89 ( V_60 ) ;
if ( ! F_95 ( F_37 ( V_7 ) ) && V_7 -> V_218 &&
V_7 -> V_218 -> V_223 != 0 ) {
V_11 = F_103 ( V_7 -> V_218 ) ;
if ( V_11 ) {
F_104 ( V_7 -> V_218 , V_11 ) ;
return V_11 ;
}
}
F_37 ( V_7 ) -> time = 0 ;
V_11 = F_105 ( V_60 ) ;
if ( V_11 < 0 )
return ( T_1 ) V_11 ;
}
return F_106 ( V_60 , V_219 , V_220 ) ;
}
static int
F_107 ( struct V_60 * V_60 , long V_224 , struct V_225 * * V_226 , void * * V_227 )
{
struct V_7 * V_7 = F_89 ( V_60 ) ;
struct V_228 * V_229 = V_60 -> V_230 ;
if ( ! ( F_108 ( V_7 -> V_187 ) ) )
return - V_231 ;
if ( V_224 == V_232 ||
( ( V_224 == V_233 ) && F_95 ( F_37 ( V_7 ) ) ) ||
( ( V_224 == V_234 ) && F_99 ( F_37 ( V_7 ) ) ) )
return F_109 ( V_60 , V_224 , V_226 , V_227 ) ;
else if ( F_110 ( V_229 -> V_235 ) -> V_236 &&
! F_95 ( F_37 ( V_7 ) ) )
return F_109 ( V_60 , V_224 , V_226 , V_227 ) ;
else
return - V_237 ;
}
static int F_111 ( struct V_60 * V_238 , T_1 V_62 ,
struct V_60 * V_239 , T_1 V_240 , T_3 V_63 )
{
struct V_7 * V_241 = F_89 ( V_238 ) ;
struct V_7 * V_242 = F_89 ( V_239 ) ;
struct V_228 * V_243 = V_238 -> V_230 ;
struct V_228 * V_244 = V_239 -> V_230 ;
struct V_9 * V_245 = F_110 ( V_244 -> V_235 ) ;
unsigned int V_53 ;
int V_11 ;
F_15 ( V_43 , L_75 ) ;
V_53 = F_20 () ;
if ( ! V_238 -> V_230 || ! V_239 -> V_230 ) {
V_11 = - V_246 ;
F_15 ( V_46 , L_76 ) ;
goto V_203;
}
F_112 ( V_242 , V_241 ) ;
if ( V_63 == 0 )
V_63 = V_241 -> V_247 - V_62 ;
F_15 ( V_43 , L_77 ) ;
F_113 ( & V_242 -> V_91 , V_240 ,
F_114 ( V_240 + V_63 ) - 1 ) ;
if ( V_245 -> V_16 -> V_4 -> V_58 -> V_248 )
V_11 = V_245 -> V_16 -> V_4 -> V_58 -> V_248 ( V_53 ,
V_243 , V_244 , V_62 , V_63 , V_240 ) ;
else
V_11 = - V_65 ;
F_37 ( V_242 ) -> time = 0 ;
F_115 ( V_241 , V_242 ) ;
V_203:
F_21 ( V_53 ) ;
return V_11 ;
}
T_2 F_116 ( unsigned int V_53 ,
struct V_60 * V_238 , T_1 V_62 ,
struct V_60 * V_239 , T_1 V_240 ,
T_4 V_63 , unsigned int V_76 )
{
struct V_7 * V_241 = F_89 ( V_238 ) ;
struct V_7 * V_242 = F_89 ( V_239 ) ;
struct V_228 * V_243 ;
struct V_228 * V_244 ;
struct V_9 * V_249 ;
struct V_9 * V_245 ;
T_2 V_11 ;
F_15 ( V_43 , L_78 ) ;
if ( V_241 == V_242 ) {
V_11 = - V_231 ;
goto V_203;
}
if ( ! V_238 -> V_230 || ! V_239 -> V_230 ) {
V_11 = - V_246 ;
F_15 ( V_46 , L_76 ) ;
goto V_203;
}
V_11 = - V_250 ;
V_244 = V_239 -> V_230 ;
V_243 = V_238 -> V_230 ;
V_249 = F_110 ( V_243 -> V_235 ) ;
V_245 = F_110 ( V_244 -> V_235 ) ;
if ( V_249 -> V_16 != V_245 -> V_16 ) {
F_15 ( V_46 , L_79 ) ;
goto V_203;
}
F_112 ( V_242 , V_241 ) ;
F_15 ( V_43 , L_77 ) ;
F_117 ( & V_242 -> V_91 , 0 ) ;
if ( V_245 -> V_16 -> V_4 -> V_58 -> V_251 )
V_11 = V_245 -> V_16 -> V_4 -> V_58 -> V_251 ( V_53 ,
V_243 , V_244 , V_62 , V_63 , V_240 ) ;
else
V_11 = - V_65 ;
F_37 ( V_242 ) -> time = 0 ;
F_115 ( V_241 , V_242 ) ;
V_203:
return V_11 ;
}
static T_2 F_118 ( struct V_60 * V_238 , T_1 V_62 ,
struct V_60 * V_239 , T_1 V_240 ,
T_4 V_63 , unsigned int V_76 )
{
unsigned int V_53 = F_20 () ;
T_2 V_11 ;
V_11 = F_116 ( V_53 , V_238 , V_62 , V_239 , V_240 ,
V_63 , V_76 ) ;
F_21 ( V_53 ) ;
return V_11 ;
}
static void
F_119 ( void * V_7 )
{
struct V_71 * V_252 = V_7 ;
F_120 ( & V_252 -> V_79 ) ;
F_121 ( & V_252 -> V_253 ) ;
}
static int T_5
F_122 ( void )
{
V_73 = F_123 ( L_80 ,
sizeof( struct V_71 ) ,
0 , ( V_254 |
V_255 | V_256 ) ,
F_119 ) ;
if ( V_73 == NULL )
return - V_41 ;
return 0 ;
}
static void
F_124 ( void )
{
F_125 () ;
F_126 ( V_73 ) ;
}
static int
F_127 ( void )
{
T_4 V_257 = V_258 ;
#ifdef F_31
V_257 = V_259 ;
#endif
if ( V_260 < 8192 ) {
V_260 = 8192 ;
} else if ( V_260 > 1024 * 127 ) {
V_260 = 1024 * 127 ;
} else {
V_260 &= 0x1FE00 ;
}
V_261 = F_123 ( L_81 ,
V_260 + V_257 , 0 ,
V_262 , NULL ) ;
if ( V_261 == NULL )
return - V_41 ;
if ( V_263 < 1 )
V_263 = 1 ;
else if ( V_263 > 64 ) {
V_263 = 64 ;
F_15 ( V_46 , L_82 ) ;
}
V_264 = F_128 ( V_263 ,
V_261 ) ;
if ( V_264 == NULL ) {
F_126 ( V_261 ) ;
return - V_41 ;
}
V_265 = F_123 ( L_83 ,
V_266 , 0 , V_262 ,
NULL ) ;
if ( V_265 == NULL ) {
F_129 ( V_264 ) ;
F_126 ( V_261 ) ;
return - V_41 ;
}
if ( V_267 < 2 )
V_267 = 2 ;
else if ( V_267 > 256 ) {
V_267 = 256 ;
F_15 ( V_43 , L_84 ) ;
}
V_268 = F_128 ( V_267 ,
V_265 ) ;
if ( V_268 == NULL ) {
F_129 ( V_264 ) ;
F_126 ( V_261 ) ;
F_126 ( V_265 ) ;
return - V_41 ;
}
return 0 ;
}
static void
F_130 ( void )
{
F_129 ( V_264 ) ;
F_126 ( V_261 ) ;
F_129 ( V_268 ) ;
F_126 ( V_265 ) ;
}
static int
F_131 ( void )
{
V_269 = F_123 ( L_85 ,
sizeof( struct V_270 ) , 0 ,
V_262 , NULL ) ;
if ( V_269 == NULL )
return - V_41 ;
V_271 = F_128 ( 3 , V_269 ) ;
if ( V_271 == NULL ) {
F_126 ( V_269 ) ;
return - V_41 ;
}
return 0 ;
}
static void
F_132 ( void )
{
F_129 ( V_271 ) ;
F_126 ( V_269 ) ;
}
static int T_5
F_133 ( void )
{
int V_11 = 0 ;
F_134 () ;
F_33 ( & V_272 ) ;
#ifdef F_135
F_33 ( & V_273 ) ;
F_33 ( & V_274 ) ;
#endif
F_136 ( & V_275 , 0 ) ;
F_136 ( & V_276 , 0 ) ;
F_136 ( & V_277 , 0 ) ;
F_136 ( & V_278 , 0 ) ;
F_136 ( & V_279 , 0 ) ;
F_136 ( & V_280 , 0 ) ;
F_136 ( & V_281 , 0 ) ;
#ifdef F_137
F_136 ( & V_282 , 0 ) ;
F_136 ( & V_283 , 0 ) ;
#endif
F_136 ( & V_284 , 0 ) ;
V_285 = 0 ;
V_286 = 0 ;
V_287 = 0 ;
F_30 ( & V_170 ) ;
F_30 ( & V_288 ) ;
F_138 ( & V_289 , sizeof( V_289 ) ) ;
if ( V_290 < 2 ) {
V_290 = 2 ;
F_15 ( V_43 , L_86 ) ;
} else if ( V_290 > V_291 ) {
V_290 = V_291 ;
F_15 ( V_43 , L_87 ,
V_291 ) ;
}
V_292 = F_139 ( L_88 , V_293 | V_294 , 0 ) ;
if ( ! V_292 ) {
V_11 = - V_41 ;
goto V_295;
}
V_11 = F_140 () ;
if ( V_11 )
goto V_296;
V_11 = F_122 () ;
if ( V_11 )
goto V_297;
V_11 = F_131 () ;
if ( V_11 )
goto V_298;
V_11 = F_127 () ;
if ( V_11 )
goto V_299;
#ifdef F_141
V_11 = F_142 () ;
if ( V_11 )
goto V_300;
#endif
#ifdef F_143
V_11 = F_144 () ;
if ( V_11 )
goto V_301;
#endif
V_11 = F_145 ( & V_302 ) ;
if ( V_11 )
goto V_303;
return 0 ;
V_303:
#ifdef F_143
F_146 () ;
V_301:
#endif
#ifdef F_141
F_147 () ;
V_300:
#endif
F_130 () ;
V_299:
F_132 () ;
V_298:
F_124 () ;
V_297:
F_148 () ;
V_296:
F_149 ( V_292 ) ;
V_295:
F_150 () ;
return V_11 ;
}
static void T_6
F_151 ( void )
{
F_15 ( V_304 , L_89 ) ;
F_152 ( & V_302 ) ;
F_153 () ;
#ifdef F_143
F_146 () ;
#endif
#ifdef F_141
F_154 ( & V_305 ) ;
#endif
F_130 () ;
F_132 () ;
F_124 () ;
F_148 () ;
F_149 ( V_292 ) ;
F_150 () ;
}
