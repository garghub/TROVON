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
V_11 = F_10 ( V_2 ) ;
if ( V_11 )
goto V_30;
V_2 -> V_31 -> V_32 = V_8 -> V_33 / V_34 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = 14 ;
V_7 = F_11 ( V_2 ) ;
if ( F_12 ( V_7 ) ) {
V_11 = F_13 ( V_7 ) ;
goto V_30;
}
if ( V_10 -> V_38 )
V_2 -> V_39 = & V_40 ;
else
V_2 -> V_39 = & V_41 ;
V_2 -> V_42 = F_14 ( V_7 ) ;
if ( ! V_2 -> V_42 ) {
V_11 = - V_43 ;
goto V_30;
}
#ifdef F_15
if ( V_8 -> V_12 & V_44 ) {
F_16 ( V_45 , L_1 ) ;
V_2 -> V_46 = & V_47 ;
}
#endif
return 0 ;
V_30:
F_16 ( V_48 , L_2 , V_49 ) ;
return V_11 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_8 ) ;
}
static int
F_20 ( struct V_50 * V_50 , struct V_51 * V_52 )
{
struct V_1 * V_2 = V_50 -> V_53 ;
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_54 * V_4 = V_10 -> V_16 -> V_4 ;
unsigned int V_55 ;
int V_11 = 0 ;
V_55 = F_21 () ;
V_52 -> V_56 = V_57 ;
V_52 -> V_58 = 0 ;
V_52 -> V_59 = 0 ;
if ( V_4 -> V_60 -> V_61 )
V_11 = V_4 -> V_60 -> V_61 ( V_55 , V_10 , V_52 ) ;
F_22 ( V_55 ) ;
return 0 ;
}
static long F_23 ( struct V_62 * V_62 , int V_63 , T_1 V_64 , T_1 V_65 )
{
struct V_3 * V_8 = F_24 ( V_62 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_54 * V_4 = V_10 -> V_16 -> V_4 ;
if ( V_4 -> V_60 -> V_66 )
return V_4 -> V_60 -> V_66 ( V_62 , V_10 , V_63 , V_64 , V_65 ) ;
return - V_67 ;
}
static int F_25 ( struct V_7 * V_7 , int V_68 )
{
struct V_3 * V_8 ;
V_8 = F_2 ( V_7 -> V_69 ) ;
if ( V_8 -> V_12 & V_70 ) {
if ( ( V_68 & V_71 ) && ! F_26 ( V_7 ) )
return - V_72 ;
else
return 0 ;
} else
return F_27 ( V_7 , V_68 ) ;
}
static struct V_7 *
F_28 ( struct V_1 * V_2 )
{
struct V_73 * V_74 ;
V_74 = F_29 ( V_75 , V_76 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_77 = 0x20 ;
V_74 -> time = 0 ;
F_30 ( V_74 , 0 ) ;
V_74 -> V_78 = 0 ;
F_31 ( & V_74 -> V_79 ) ;
V_74 -> V_80 = 0 ;
V_74 -> V_81 . V_82 = 14 ;
V_74 -> V_83 = 0 ;
V_74 -> V_84 = 0 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 0 ;
F_32 ( V_74 -> V_87 ) ;
F_33 ( & V_74 -> V_88 ) ;
F_33 ( & V_74 -> V_89 ) ;
return & V_74 -> V_81 ;
}
static void F_34 ( struct V_90 * V_91 )
{
struct V_7 * V_7 = F_35 ( V_91 , struct V_7 , V_92 ) ;
F_36 ( V_75 , F_37 ( V_7 ) ) ;
}
static void
F_38 ( struct V_7 * V_7 )
{
F_39 ( & V_7 -> V_92 , F_34 ) ;
}
static void
F_40 ( struct V_7 * V_7 )
{
F_41 ( & V_7 -> V_93 ) ;
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
}
static void
F_44 ( struct V_94 * V_95 , struct V_54 * V_4 )
{
struct V_96 * V_97 = (struct V_96 * ) & V_4 -> V_98 ;
struct V_99 * V_100 = (struct V_99 * ) & V_4 -> V_98 ;
F_45 ( V_95 , L_3 ) ;
switch ( V_4 -> V_98 . V_101 ) {
case V_102 :
F_46 ( V_95 , L_4 , & V_97 -> V_103 . V_104 ) ;
break;
case V_105 :
F_46 ( V_95 , L_5 , & V_100 -> V_106 . V_107 ) ;
if ( V_100 -> V_108 )
F_46 ( V_95 , L_6 , V_100 -> V_108 ) ;
break;
default:
F_45 ( V_95 , L_7 ) ;
}
}
static void
F_47 ( struct V_94 * V_95 , struct V_109 * V_16 )
{
if ( V_16 -> V_110 == V_111 ) {
if ( V_16 -> V_112 == NULL )
F_45 ( V_95 , L_8 ) ;
return;
}
F_45 ( V_95 , L_9 ) ;
switch ( V_16 -> V_110 ) {
case V_113 :
F_45 ( V_95 , L_10 ) ;
break;
case V_114 :
F_45 ( V_95 , L_11 ) ;
break;
case V_115 :
F_45 ( V_95 , L_12 ) ;
break;
case V_116 :
F_45 ( V_95 , L_13 ) ;
break;
case V_117 :
F_45 ( V_95 , L_14 ) ;
break;
default:
F_45 ( V_95 , L_15 ) ;
break;
}
if ( V_16 -> V_118 )
F_45 ( V_95 , L_16 ) ;
}
static void
F_48 ( struct V_94 * V_95 , struct V_3 * V_8 )
{
F_45 ( V_95 , L_17 ) ;
if ( V_8 -> V_12 & V_119 )
F_45 ( V_95 , L_18 ) ;
else if ( V_8 -> V_12 & V_120 )
F_45 ( V_95 , L_19 ) ;
else
F_45 ( V_95 , L_20 ) ;
}
static void
F_49 ( struct V_94 * V_95 , struct V_121 * V_122 )
{
struct V_121 * V_123 ;
V_123 = F_50 () ;
if ( V_123 != V_122 )
F_46 ( V_95 , L_21 , V_122 -> V_124 ) ;
F_51 ( V_123 ) ;
}
static int
F_52 ( struct V_94 * V_95 , struct V_50 * V_125 )
{
struct V_3 * V_8 = F_2 ( V_125 -> V_53 ) ;
struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_126 * V_127 ;
V_127 = (struct V_126 * ) & V_10 -> V_16 -> V_4 -> V_127 ;
F_53 ( V_95 , L_22 , V_10 -> V_16 -> V_4 -> V_18 -> V_128 ) ;
F_47 ( V_95 , V_10 -> V_16 ) ;
F_48 ( V_95 , V_8 ) ;
if ( V_8 -> V_12 & V_129 )
F_45 ( V_95 , L_23 ) ;
else if ( V_10 -> V_16 -> V_112 )
F_53 ( V_95 , L_24 , V_10 -> V_16 -> V_112 ) ;
if ( V_10 -> V_16 -> V_130 )
F_53 ( V_95 , L_25 , V_10 -> V_16 -> V_130 ) ;
if ( V_127 -> V_131 != V_132 ) {
struct V_96 * V_133 ;
struct V_99 * V_134 ;
V_133 = (struct V_96 * ) V_127 ;
V_134 = (struct V_99 * ) V_127 ;
if ( V_127 -> V_131 == V_105 )
F_46 ( V_95 , L_26 ,
& V_134 -> V_106 ) ;
else if ( V_127 -> V_131 == V_102 )
F_46 ( V_95 , L_27 ,
& V_133 -> V_103 . V_104 ) ;
else
F_46 ( V_95 , L_28 ,
( int ) ( V_127 -> V_131 ) ) ;
}
F_46 ( V_95 , L_29 ,
F_54 ( & V_135 , V_8 -> V_136 ) ) ;
if ( V_8 -> V_12 & V_137 )
F_45 ( V_95 , L_30 ) ;
else
F_45 ( V_95 , L_31 ) ;
F_46 ( V_95 , L_32 ,
F_55 ( & V_135 , V_8 -> V_138 ) ) ;
if ( V_8 -> V_12 & V_139 )
F_45 ( V_95 , L_33 ) ;
else
F_45 ( V_95 , L_34 ) ;
F_44 ( V_95 , V_10 -> V_16 -> V_4 ) ;
if ( ! V_10 -> V_140 )
F_46 ( V_95 , L_35 ,
V_8 -> V_141 ,
V_8 -> V_142 ) ;
F_49 ( V_95 , V_8 -> V_143 ) ;
if ( V_10 -> V_144 )
F_45 ( V_95 , L_36 ) ;
if ( V_10 -> V_38 )
F_45 ( V_95 , L_37 ) ;
if ( V_10 -> V_145 )
F_45 ( V_95 , L_38 ) ;
else
F_45 ( V_95 , L_39 ) ;
if ( V_10 -> V_146 )
F_45 ( V_95 , L_40 ) ;
else if ( V_10 -> V_147 )
F_45 ( V_95 , L_41 ) ;
if ( V_10 -> V_140 )
F_45 ( V_95 , L_42 ) ;
else
F_45 ( V_95 , L_43 ) ;
if ( V_8 -> V_12 & V_148 )
F_45 ( V_95 , L_44 ) ;
if ( V_8 -> V_12 & V_149 )
F_45 ( V_95 , L_45 ) ;
if ( V_8 -> V_12 & V_150 )
F_45 ( V_95 , L_46 ) ;
if ( V_8 -> V_12 & V_44 )
F_45 ( V_95 , L_47 ) ;
if ( V_8 -> V_12 & V_151 )
F_45 ( V_95 , L_48 ) ;
if ( V_8 -> V_12 & V_152 )
F_45 ( V_95 , L_49 ) ;
if ( V_8 -> V_12 & V_153 )
F_45 ( V_95 , L_50 ) ;
if ( V_8 -> V_12 & V_154 )
F_45 ( V_95 , L_51 ) ;
if ( V_8 -> V_12 & V_155 )
F_45 ( V_95 , L_52 ) ;
if ( V_8 -> V_12 & V_156 )
F_45 ( V_95 , L_53 ) ;
if ( V_8 -> V_12 & V_157 )
F_45 ( V_95 , L_54 ) ;
if ( V_8 -> V_12 & V_158 )
F_45 ( V_95 , L_55 ) ;
if ( V_8 -> V_12 & V_159 )
F_45 ( V_95 , L_56 ) ;
if ( V_125 -> V_53 -> V_14 & V_15 )
F_45 ( V_95 , L_57 ) ;
if ( V_8 -> V_12 & V_160 )
F_45 ( V_95 , L_58 ) ;
if ( V_8 -> V_12 & V_161 )
F_45 ( V_95 , L_59 ) ;
if ( V_8 -> V_12 & V_162 )
F_45 ( V_95 , L_60 ) ;
if ( V_8 -> V_12 & V_70 )
F_45 ( V_95 , L_61 ) ;
if ( V_8 -> V_12 & V_163 )
F_46 ( V_95 , L_62 ,
F_54 ( & V_135 ,
V_8 -> V_164 ) ) ;
if ( V_8 -> V_12 & V_165 )
F_46 ( V_95 , L_63 ,
F_55 ( & V_135 ,
V_8 -> V_166 ) ) ;
F_46 ( V_95 , L_64 , V_8 -> V_33 ) ;
F_46 ( V_95 , L_65 , V_8 -> V_167 ) ;
F_46 ( V_95 , L_66 ,
V_10 -> V_16 -> V_4 -> V_168 / V_169 ) ;
F_46 ( V_95 , L_67 , V_8 -> V_170 / V_169 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
if ( V_8 == NULL )
return;
V_10 = F_9 ( V_8 ) ;
F_57 ( & V_171 ) ;
if ( ( V_10 -> V_172 > 1 ) || ( V_10 -> V_173 == V_174 ) ) {
F_58 ( & V_171 ) ;
return;
} else if ( V_10 -> V_172 == 1 )
V_10 -> V_173 = V_174 ;
F_58 ( & V_171 ) ;
if ( V_10 -> V_16 && V_10 -> V_16 -> V_4 ) {
F_16 ( V_45 , L_68 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_175 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_176 ) ;
F_60 ( 1 ) ;
F_59 ( & V_10 -> V_16 -> V_4 -> V_176 ) ;
F_60 ( 1 ) ;
}
return;
}
static int F_61 ( struct V_94 * V_95 , struct V_50 * V_125 )
{
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int * V_78 , char * V_177 )
{
F_63 ( V_2 ) ;
* V_78 |= V_178 ;
return 0 ;
}
static int F_64 ( struct V_7 * V_7 )
{
struct V_3 * V_8 = F_2 ( V_7 -> V_69 ) ;
return ! ( V_8 -> V_12 & V_44 ) ||
F_65 ( V_7 ) ;
}
static struct V_50 *
F_66 ( struct V_179 * V_180 , struct V_1 * V_2 )
{
struct V_50 * V_50 ;
struct V_3 * V_8 = F_2 ( V_2 ) ;
char * V_181 = NULL ;
char * V_95 , * V_182 ;
char V_183 ;
if ( V_8 -> V_12 & V_184 )
return F_67 ( V_2 -> V_42 ) ;
V_181 = F_68 ( V_180 , V_8 ,
F_9 ( V_8 ) , 0 ) ;
if ( V_181 == NULL )
return F_69 ( - V_43 ) ;
F_16 ( V_45 , L_69 , V_181 ) ;
V_183 = F_70 ( V_8 ) ;
V_50 = F_67 ( V_2 -> V_42 ) ;
V_182 = V_95 = V_181 ;
do {
struct V_7 * V_185 = F_71 ( V_50 ) ;
struct V_50 * V_186 ;
if ( ! V_185 ) {
F_72 ( V_50 ) ;
V_50 = F_69 ( - V_187 ) ;
break;
}
if ( ! F_73 ( V_185 -> V_188 ) ) {
F_72 ( V_50 ) ;
V_50 = F_69 ( - V_189 ) ;
break;
}
while ( * V_95 == V_183 )
V_95 ++ ;
if ( ! * V_95 )
break;
V_182 = V_95 ++ ;
while ( * V_95 && * V_95 != V_183 )
V_95 ++ ;
V_186 = F_74 ( V_182 , V_50 , V_95 - V_182 ) ;
F_72 ( V_50 ) ;
V_50 = V_186 ;
} while ( ! F_12 ( V_50 ) );
F_75 ( V_181 ) ;
return V_50 ;
}
static int F_76 ( struct V_1 * V_2 , void * V_177 )
{
struct V_190 * V_191 = V_177 ;
V_2 -> V_192 = V_191 -> V_8 ;
return F_77 ( V_2 , NULL ) ;
}
static struct V_50 *
F_78 ( struct V_193 * V_194 ,
int V_78 , const char * V_195 , void * V_177 )
{
int V_11 ;
struct V_1 * V_2 ;
struct V_3 * V_8 ;
struct V_179 * V_196 ;
struct V_190 V_191 ;
struct V_50 * V_125 ;
F_16 ( V_45 , L_70 , V_195 , V_78 ) ;
V_196 = F_79 ( ( char * ) V_177 , V_195 ) ;
if ( F_12 ( V_196 ) )
return F_80 ( V_196 ) ;
V_8 = F_81 ( sizeof( struct V_3 ) , V_76 ) ;
if ( V_8 == NULL ) {
V_125 = F_69 ( - V_43 ) ;
goto V_197;
}
V_8 -> V_198 = F_82 ( V_177 , V_34 , V_76 ) ;
if ( V_8 -> V_198 == NULL ) {
V_125 = F_69 ( - V_43 ) ;
goto V_199;
}
V_11 = F_83 ( V_196 , V_8 ) ;
if ( V_11 ) {
V_125 = F_69 ( V_11 ) ;
goto V_199;
}
V_11 = F_84 ( V_8 , V_196 ) ;
if ( V_11 ) {
if ( ! ( V_78 & V_200 ) )
F_16 ( V_48 , L_71 ,
V_11 ) ;
V_125 = F_69 ( V_11 ) ;
goto V_199;
}
V_191 . V_180 = V_196 ;
V_191 . V_8 = V_8 ;
V_191 . V_78 = V_78 ;
V_78 |= V_178 | V_201 ;
V_2 = F_85 ( V_194 , V_202 , F_76 , V_78 , & V_191 ) ;
if ( F_12 ( V_2 ) ) {
V_125 = F_80 ( V_2 ) ;
F_19 ( V_8 ) ;
goto V_203;
}
if ( V_2 -> V_42 ) {
F_16 ( V_45 , L_72 ) ;
F_19 ( V_8 ) ;
} else {
V_11 = F_8 ( V_2 ) ;
if ( V_11 ) {
V_125 = F_69 ( V_11 ) ;
goto V_204;
}
V_2 -> V_14 |= V_205 ;
}
V_125 = F_66 ( V_196 , V_2 ) ;
if ( F_12 ( V_125 ) )
goto V_204;
F_16 ( V_45 , L_73 , V_125 ) ;
goto V_203;
V_204:
F_86 ( V_2 ) ;
V_203:
F_87 ( V_196 ) ;
return V_125 ;
V_199:
F_75 ( V_8 -> V_206 ) ;
F_75 ( V_8 -> V_198 ) ;
F_75 ( V_8 ) ;
V_197:
F_51 ( V_196 -> V_143 ) ;
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
struct V_73 * V_215 = F_37 ( V_7 ) ;
T_2 V_216 ;
int V_11 ;
if ( V_208 -> V_211 -> V_212 & V_213 ) {
V_216 = F_94 ( V_208 , V_214 ) ;
if ( V_216 > 0 && F_95 ( V_215 ) ) {
F_96 ( V_7 ) ;
F_16 ( V_45 ,
L_74 ,
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
F_16 ( V_45 , L_75 ,
V_11 , V_7 ) ;
V_203:
F_101 ( V_215 ) ;
return V_216 ;
}
static T_1 F_102 ( struct V_62 * V_62 , T_1 V_219 , int V_220 )
{
if ( V_220 != V_221 && V_220 != V_222 ) {
int V_11 ;
struct V_7 * V_7 = F_89 ( V_62 ) ;
if ( ! F_95 ( F_37 ( V_7 ) ) && V_7 -> V_218 &&
V_7 -> V_218 -> V_223 != 0 ) {
V_11 = F_103 ( V_7 -> V_218 ) ;
if ( V_11 ) {
F_104 ( V_7 -> V_218 , V_11 ) ;
return V_11 ;
}
}
F_37 ( V_7 ) -> time = 0 ;
V_11 = F_105 ( V_62 ) ;
if ( V_11 < 0 )
return ( T_1 ) V_11 ;
}
return F_106 ( V_62 , V_219 , V_220 ) ;
}
static int
F_107 ( struct V_62 * V_62 , long V_224 , struct V_225 * * V_226 , void * * V_227 )
{
struct V_7 * V_7 = F_89 ( V_62 ) ;
struct V_228 * V_229 = V_62 -> V_230 ;
if ( ! ( F_108 ( V_7 -> V_188 ) ) )
return - V_231 ;
if ( V_224 == V_232 ||
( ( V_224 == V_233 ) && F_95 ( F_37 ( V_7 ) ) ) ||
( ( V_224 == V_234 ) && F_99 ( F_37 ( V_7 ) ) ) )
return F_109 ( V_62 , V_224 , V_226 , V_227 ) ;
else if ( F_110 ( V_229 -> V_235 ) -> V_236 &&
! F_95 ( F_37 ( V_7 ) ) )
return F_109 ( V_62 , V_224 , V_226 , V_227 ) ;
else
return - V_237 ;
}
static int F_111 ( struct V_62 * V_238 , T_1 V_64 ,
struct V_62 * V_239 , T_1 V_240 , T_3 V_65 )
{
struct V_7 * V_241 = F_89 ( V_238 ) ;
struct V_7 * V_242 = F_89 ( V_239 ) ;
struct V_228 * V_243 = V_238 -> V_230 ;
struct V_228 * V_244 = V_239 -> V_230 ;
struct V_9 * V_245 = F_110 ( V_244 -> V_235 ) ;
unsigned int V_55 ;
int V_11 ;
F_16 ( V_45 , L_76 ) ;
V_55 = F_21 () ;
if ( ! V_238 -> V_230 || ! V_239 -> V_230 ) {
V_11 = - V_246 ;
F_16 ( V_48 , L_77 ) ;
goto V_203;
}
F_112 ( V_242 , V_241 ) ;
if ( V_65 == 0 )
V_65 = V_241 -> V_247 - V_64 ;
F_16 ( V_45 , L_78 ) ;
F_113 ( & V_242 -> V_93 , V_240 ,
F_114 ( V_240 + V_65 ) - 1 ) ;
if ( V_245 -> V_16 -> V_4 -> V_60 -> V_248 )
V_11 = V_245 -> V_16 -> V_4 -> V_60 -> V_248 ( V_55 ,
V_243 , V_244 , V_64 , V_65 , V_240 ) ;
else
V_11 = - V_67 ;
F_37 ( V_242 ) -> time = 0 ;
F_115 ( V_241 , V_242 ) ;
V_203:
F_22 ( V_55 ) ;
return V_11 ;
}
T_2 F_116 ( unsigned int V_55 ,
struct V_62 * V_238 , T_1 V_64 ,
struct V_62 * V_239 , T_1 V_240 ,
T_4 V_65 , unsigned int V_78 )
{
struct V_7 * V_241 = F_89 ( V_238 ) ;
struct V_7 * V_242 = F_89 ( V_239 ) ;
struct V_228 * V_243 ;
struct V_228 * V_244 ;
struct V_9 * V_249 ;
struct V_9 * V_245 ;
T_2 V_11 ;
F_16 ( V_45 , L_79 ) ;
if ( V_241 == V_242 ) {
V_11 = - V_231 ;
goto V_203;
}
if ( ! V_238 -> V_230 || ! V_239 -> V_230 ) {
V_11 = - V_246 ;
F_16 ( V_48 , L_77 ) ;
goto V_203;
}
V_11 = - V_250 ;
V_244 = V_239 -> V_230 ;
V_243 = V_238 -> V_230 ;
V_249 = F_110 ( V_243 -> V_235 ) ;
V_245 = F_110 ( V_244 -> V_235 ) ;
if ( V_249 -> V_16 != V_245 -> V_16 ) {
F_16 ( V_48 , L_80 ) ;
goto V_203;
}
F_112 ( V_242 , V_241 ) ;
F_16 ( V_45 , L_78 ) ;
F_117 ( & V_242 -> V_93 , 0 ) ;
if ( V_245 -> V_16 -> V_4 -> V_60 -> V_251 )
V_11 = V_245 -> V_16 -> V_4 -> V_60 -> V_251 ( V_55 ,
V_243 , V_244 , V_64 , V_65 , V_240 ) ;
else
V_11 = - V_67 ;
F_37 ( V_242 ) -> time = 0 ;
F_115 ( V_241 , V_242 ) ;
V_203:
return V_11 ;
}
static T_2 F_118 ( struct V_62 * V_238 , T_1 V_64 ,
struct V_62 * V_239 , T_1 V_240 ,
T_4 V_65 , unsigned int V_78 )
{
unsigned int V_55 = F_21 () ;
T_2 V_11 ;
V_11 = F_116 ( V_55 , V_238 , V_64 , V_239 , V_240 ,
V_65 , V_78 ) ;
F_22 ( V_55 ) ;
return V_11 ;
}
static void
F_119 ( void * V_7 )
{
struct V_73 * V_252 = V_7 ;
F_120 ( & V_252 -> V_81 ) ;
F_121 ( & V_252 -> V_253 ) ;
}
static int T_5
F_122 ( void )
{
V_75 = F_123 ( L_81 ,
sizeof( struct V_73 ) ,
0 , ( V_254 |
V_255 | V_256 ) ,
F_119 ) ;
if ( V_75 == NULL )
return - V_43 ;
return 0 ;
}
static void
F_124 ( void )
{
F_125 () ;
F_126 ( V_75 ) ;
}
static int
F_127 ( void )
{
T_4 V_257 = V_258 ;
if ( V_259 < 8192 ) {
V_259 = 8192 ;
} else if ( V_259 > 1024 * 127 ) {
V_259 = 1024 * 127 ;
} else {
V_259 &= 0x1FE00 ;
}
V_260 = F_123 ( L_82 ,
V_259 + V_257 , 0 ,
V_261 , NULL ) ;
if ( V_260 == NULL )
return - V_43 ;
if ( V_262 < 1 )
V_262 = 1 ;
else if ( V_262 > 64 ) {
V_262 = 64 ;
F_16 ( V_48 , L_83 ) ;
}
V_263 = F_128 ( V_262 ,
V_260 ) ;
if ( V_263 == NULL ) {
F_126 ( V_260 ) ;
return - V_43 ;
}
V_264 = F_123 ( L_84 ,
V_265 , 0 , V_261 ,
NULL ) ;
if ( V_264 == NULL ) {
F_129 ( V_263 ) ;
F_126 ( V_260 ) ;
return - V_43 ;
}
if ( V_266 < 2 )
V_266 = 2 ;
else if ( V_266 > 256 ) {
V_266 = 256 ;
F_16 ( V_45 , L_85 ) ;
}
V_267 = F_128 ( V_266 ,
V_264 ) ;
if ( V_267 == NULL ) {
F_129 ( V_263 ) ;
F_126 ( V_260 ) ;
F_126 ( V_264 ) ;
return - V_43 ;
}
return 0 ;
}
static void
F_130 ( void )
{
F_129 ( V_263 ) ;
F_126 ( V_260 ) ;
F_129 ( V_267 ) ;
F_126 ( V_264 ) ;
}
static int
F_131 ( void )
{
V_268 = F_123 ( L_86 ,
sizeof( struct V_269 ) , 0 ,
V_261 , NULL ) ;
if ( V_268 == NULL )
return - V_43 ;
V_270 = F_128 ( 3 , V_268 ) ;
if ( V_270 == NULL ) {
F_126 ( V_268 ) ;
return - V_43 ;
}
return 0 ;
}
static void
F_132 ( void )
{
F_129 ( V_270 ) ;
F_126 ( V_268 ) ;
}
static int T_5
F_133 ( void )
{
int V_11 = 0 ;
F_134 () ;
F_33 ( & V_271 ) ;
#ifdef F_135
F_33 ( & V_272 ) ;
F_33 ( & V_273 ) ;
#endif
F_136 ( & V_274 , 0 ) ;
F_136 ( & V_275 , 0 ) ;
F_136 ( & V_276 , 0 ) ;
F_136 ( & V_277 , 0 ) ;
F_136 ( & V_278 , 0 ) ;
F_136 ( & V_279 , 0 ) ;
F_136 ( & V_280 , 0 ) ;
#ifdef F_137
F_136 ( & V_281 , 0 ) ;
F_136 ( & V_282 , 0 ) ;
#endif
F_136 ( & V_283 , 0 ) ;
V_284 = 0 ;
V_285 = 0 ;
V_286 = 0 ;
F_31 ( & V_171 ) ;
F_31 ( & V_287 ) ;
V_288 = F_138 () ;
if ( V_289 < 2 ) {
V_289 = 2 ;
F_16 ( V_45 , L_87 ) ;
} else if ( V_289 > V_290 ) {
V_289 = V_290 ;
F_16 ( V_45 , L_88 ,
V_290 ) ;
}
V_291 = F_139 ( L_89 , V_292 | V_293 , 0 ) ;
if ( ! V_291 ) {
V_11 = - V_43 ;
goto V_294;
}
V_295 = F_139 ( L_90 ,
V_292 | V_293 , 0 ) ;
if ( ! V_295 ) {
V_11 = - V_43 ;
goto V_296;
}
V_11 = F_140 () ;
if ( V_11 )
goto V_297;
V_11 = F_122 () ;
if ( V_11 )
goto V_298;
V_11 = F_131 () ;
if ( V_11 )
goto V_299;
V_11 = F_127 () ;
if ( V_11 )
goto V_300;
#ifdef F_141
V_11 = F_142 () ;
if ( V_11 )
goto V_301;
#endif
#ifdef F_143
V_11 = F_144 () ;
if ( V_11 )
goto V_302;
#endif
V_11 = F_145 ( & V_303 ) ;
if ( V_11 )
goto V_304;
return 0 ;
V_304:
#ifdef F_143
F_146 () ;
V_302:
#endif
#ifdef F_141
F_147 () ;
V_301:
#endif
F_130 () ;
V_300:
F_132 () ;
V_299:
F_124 () ;
V_298:
F_148 () ;
V_297:
F_149 ( V_295 ) ;
V_296:
F_149 ( V_291 ) ;
V_294:
F_150 () ;
return V_11 ;
}
static void T_6
F_151 ( void )
{
F_16 ( V_305 , L_91 ) ;
F_152 ( & V_303 ) ;
F_153 () ;
#ifdef F_143
F_146 () ;
#endif
#ifdef F_141
F_147 () ;
#endif
F_130 () ;
F_132 () ;
F_124 () ;
F_148 () ;
F_149 ( V_295 ) ;
F_149 ( V_291 ) ;
F_150 () ;
}
