static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
int V_8 ;
if ( V_7 == NULL )
return NULL ;
if ( F_2 ( V_3 , V_9 ) == 0 )
return NULL ;
V_8 = F_3 ( V_4 , V_6 -> V_10 ,
& V_4 -> V_11 , ( void * * ) & V_7 -> V_7 , & V_7 -> V_12 ) ;
if ( V_8 == 0 )
return V_7 ;
return NULL ;
}
static inline void
F_4 ( struct V_1 * V_7 )
{
if ( V_7 )
F_5 ( V_7 -> V_7 , V_7 -> V_12 ) ;
}
static inline T_1 * F_6 ( struct V_13 * V_14 , struct V_1 * V_7 )
{
if ( V_7 )
return V_14 -> V_15 ;
return V_14 -> V_16 ;
}
static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_17 )
{ return NULL ; }
static inline void
F_4 ( struct V_1 * V_7 )
{ return; }
static inline T_1 *
F_6 ( struct V_13 * V_14 , struct V_1 * V_7 )
{ return V_14 -> V_15 ; }
static int F_7 ( int V_8 )
{
if ( V_8 >= - 1000 )
return V_8 ;
switch ( V_8 ) {
case - V_18 :
case - V_19 :
case - V_20 :
return - V_21 ;
case - V_22 :
case - V_23 :
return - V_24 ;
case - V_25 :
case - V_26 :
return - V_27 ;
case - V_28 :
return - V_29 ;
case - V_30 :
return - V_31 ;
case - V_32 :
return - V_33 ;
default:
F_8 ( L_1 ,
V_34 , - V_8 ) ;
break;
}
return - V_35 ;
}
static void F_9 ( T_2 V_36 , T_3 * V_37 , struct V_4 * V_4 ,
struct V_38 * V_39 )
{
T_3 * V_40 , * V_41 ;
if ( V_36 > 2 ) {
V_39 -> V_36 = V_36 ;
memcpy ( & V_39 -> V_37 , V_37 , sizeof( V_39 -> V_37 ) ) ;
return;
}
V_39 -> V_36 = 0 ;
memset ( & V_39 -> V_37 , 0 , sizeof( V_39 -> V_37 ) ) ;
if ( V_36 == 2 )
return;
V_40 = V_41 = F_10 ( * V_39 -> V_42 ) ;
if ( V_36 == 0 ) {
* V_41 ++ = V_43 ;
* V_41 ++ = V_44 ;
* V_41 ++ = V_43 ;
* V_41 ++ = V_43 ;
memcpy ( V_41 , L_2 , 4 ) ;
V_41 ++ ;
* V_41 ++ = V_43 ;
* V_41 ++ = F_11 ( V_45 ) ;
* V_41 ++ = F_11 ( 8 ) ;
V_41 = F_12 ( V_41 , F_13 ( F_14 ( V_4 ) ) ) ;
}
* V_41 ++ = V_43 ;
* V_41 ++ = V_44 ;
* V_41 ++ = V_46 ;
* V_41 ++ = V_46 ;
memcpy ( V_41 , L_3 , 4 ) ;
V_41 ++ ;
* V_41 ++ = V_43 ;
* V_41 ++ = F_11 ( V_45 ) ;
* V_41 ++ = F_11 ( 8 ) ;
V_41 = F_12 ( V_41 , F_13 ( F_14 ( V_4 -> V_47 ) ) ) ;
V_39 -> V_48 = ( char * ) V_41 - ( char * ) V_40 ;
V_39 -> V_49 -= V_39 -> V_48 ;
F_15 ( V_40 ) ;
}
static long F_16 ( long * V_50 )
{
long V_51 ;
if ( ! V_50 )
return V_52 ;
if ( * V_50 <= 0 )
* V_50 = V_53 ;
if ( * V_50 > V_52 )
* V_50 = V_52 ;
V_51 = * V_50 ;
* V_50 <<= 1 ;
return V_51 ;
}
static int F_17 ( struct V_54 * V_55 , long * V_50 )
{
int V_56 = 0 ;
F_18 () ;
F_19 (
F_16 ( V_50 ) ) ;
if ( F_20 ( V_57 ) )
V_56 = - V_58 ;
return V_56 ;
}
int F_21 ( struct V_13 * V_14 , int V_59 , struct V_60 * V_61 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_64 * V_65 = V_61 -> V_65 ;
struct V_2 * V_2 = V_61 -> V_2 ;
int V_51 = V_59 ;
V_61 -> V_66 = 0 ;
switch( V_59 ) {
case 0 :
return 0 ;
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
if ( V_2 && F_22 ( V_2 , V_71 ) ) {
F_23 ( V_2 ) ;
V_61 -> V_66 = 1 ;
return 0 ;
}
if ( V_65 == NULL )
break;
V_51 = F_24 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
goto V_72;
case - V_73 :
if ( V_65 != NULL ) {
V_51 = F_24 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
}
case - V_74 :
case - V_75 :
F_25 ( V_63 ) ;
goto V_72;
case - V_76 :
V_51 = F_26 ( V_14 ) ;
if ( V_51 < 0 )
break;
goto V_72;
case - V_77 :
F_27 ( V_63 ) ;
goto V_72;
#if F_28 ( V_78 )
case - V_79 :
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
F_8 ( L_4 , V_34 ,
V_59 ) ;
F_29 ( V_63 -> V_86 , V_59 ) ;
goto V_72;
#endif
case - V_32 :
if ( V_61 -> V_50 > V_87 ) {
V_51 = - V_33 ;
break;
}
case - V_88 :
case - V_89 :
V_51 = F_17 ( V_14 -> V_90 , & V_61 -> V_50 ) ;
if ( V_51 != 0 )
break;
case - V_91 :
case - V_92 :
V_61 -> V_66 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_93 & V_94 ) {
V_14 -> V_93 &= ~ V_94 ;
V_61 -> V_66 = 1 ;
F_30 ( V_95 L_5
L_6
L_7
L_8 ,
V_14 -> V_62 -> V_96 ) ;
}
}
return F_7 ( V_51 ) ;
V_72:
V_51 = F_31 ( V_63 ) ;
if ( F_32 ( V_97 , & V_14 -> V_98 ) )
return - V_35 ;
if ( V_51 == 0 )
V_61 -> V_66 = 1 ;
return V_51 ;
}
static bool F_33 ( struct V_62 * V_63 )
{
T_4 V_99 = V_63 -> V_100 -> V_101 -> V_102 ;
if ( V_99 == V_103 ||
V_99 == V_104 )
return true ;
return false ;
}
static void F_34 ( struct V_62 * V_63 , unsigned long V_105 )
{
F_35 ( & V_63 -> V_106 ) ;
if ( F_36 ( V_63 -> V_107 , V_105 ) )
V_63 -> V_107 = V_105 ;
F_37 ( & V_63 -> V_106 ) ;
}
static void F_38 ( const struct V_13 * V_14 , unsigned long V_105 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
if ( ! F_39 ( V_63 ) )
F_34 ( V_63 , V_105 ) ;
}
void F_40 ( struct V_108 * args ,
struct V_109 * V_56 , int V_110 )
{
args -> V_111 = NULL ;
args -> V_112 = V_110 ;
args -> V_113 = 0 ;
V_56 -> V_114 = NULL ;
}
static void F_41 ( struct V_108 * args )
{
args -> V_113 = 1 ;
}
int F_42 ( struct V_115 * V_116 ,
struct V_108 * args ,
struct V_109 * V_56 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 ;
if ( V_56 -> V_114 != NULL )
goto V_121;
F_35 ( & V_116 -> V_122 ) ;
if ( F_43 ( V_116 ) && ! args -> V_113 )
goto V_123;
V_120 = F_44 ( V_116 ) ;
if ( F_45 ( V_120 ) ) {
if ( V_120 == F_46 ( - V_124 ) )
V_118 -> V_125 = V_87 >> 2 ;
goto V_123;
}
F_37 ( & V_116 -> V_122 ) ;
args -> V_111 = V_120 ;
V_56 -> V_114 = V_120 ;
V_121:
F_47 ( V_118 ) ;
return 0 ;
V_123:
if ( args -> V_113 )
F_48 ( & V_116 -> V_126 , V_118 ,
NULL , V_127 ) ;
else
F_49 ( & V_116 -> V_126 , V_118 , NULL ) ;
F_37 ( & V_116 -> V_122 ) ;
return - V_128 ;
}
static int F_50 ( struct V_117 * V_118 ,
struct V_109 * V_56 )
{
struct V_119 * V_120 = V_56 -> V_114 ;
struct V_115 * V_116 ;
if ( V_120 == NULL )
goto V_129;
V_116 = V_120 -> V_130 ;
F_35 ( & V_116 -> V_122 ) ;
if ( ! F_51 ( V_116 , V_120 ) )
F_52 ( V_116 , V_120 ) ;
F_37 ( & V_116 -> V_122 ) ;
V_56 -> V_114 = NULL ;
V_129:
return 1 ;
}
static void F_53 ( struct V_109 * V_56 )
{
struct V_131 * V_132 ;
struct V_115 * V_116 ;
struct V_119 * V_120 = V_56 -> V_114 ;
bool V_133 = false ;
V_116 = V_120 -> V_130 ;
V_132 = V_116 -> V_132 ;
F_35 ( & V_116 -> V_122 ) ;
if ( V_116 -> V_134 > V_116 -> V_135 )
V_133 = true ;
if ( F_51 ( V_116 , V_120 ) ) {
V_133 = false ;
goto V_136;
}
F_52 ( V_116 , V_120 ) ;
if ( V_116 -> V_134 != V_137 )
V_133 = false ;
V_136:
F_37 ( & V_116 -> V_122 ) ;
V_56 -> V_114 = NULL ;
if ( V_133 )
F_54 ( V_132 -> V_63 ) ;
}
int F_55 ( struct V_117 * V_118 , struct V_109 * V_56 )
{
struct V_131 * V_132 ;
struct V_119 * V_120 = V_56 -> V_114 ;
struct V_62 * V_63 ;
bool V_138 = false ;
int V_51 = 1 ;
if ( V_120 == NULL )
goto V_139;
if ( ! F_56 ( V_118 ) )
goto V_129;
V_132 = V_120 -> V_130 -> V_132 ;
if ( V_120 -> V_138 ) {
V_120 -> V_138 = 0 ;
V_138 = true ;
}
F_57 ( V_132 , V_56 ) ;
switch ( V_56 -> V_140 ) {
case 0 :
++ V_120 -> V_141 ;
V_63 = V_132 -> V_63 ;
F_34 ( V_63 , V_56 -> V_142 ) ;
F_58 ( V_63 , V_56 -> V_143 ) ;
F_59 ( V_120 -> V_130 , V_120 , V_56 ) ;
break;
case 1 :
V_120 -> V_138 = 1 ;
goto V_129;
case - V_89 :
F_8 ( L_9 ,
V_34 ,
V_120 -> V_144 ,
V_120 -> V_141 ) ;
goto V_145;
case - V_80 :
goto V_146;
case - V_85 :
if ( V_138 ) {
++ V_120 -> V_141 ;
goto V_146;
}
if ( V_120 -> V_141 != 1 ) {
V_120 -> V_141 = 1 ;
goto V_146;
}
break;
case - V_84 :
++ V_120 -> V_141 ;
goto V_146;
default:
++ V_120 -> V_141 ;
}
V_129:
F_8 ( L_10 , V_34 , V_56 -> V_140 ) ;
F_53 ( V_56 ) ;
V_139:
return V_51 ;
V_146:
if ( F_60 ( V_118 ) ) {
V_118 -> V_147 = 0 ;
V_51 = 0 ;
}
goto V_129;
V_145:
if ( ! F_61 ( V_118 ) )
goto V_129;
F_62 ( V_118 , V_52 ) ;
return 0 ;
}
int F_63 ( struct V_117 * V_118 , struct V_109 * V_56 )
{
if ( V_56 -> V_114 == NULL )
return 1 ;
if ( ! V_56 -> V_114 -> V_130 -> V_132 )
return F_50 ( V_118 , V_56 ) ;
return F_55 ( V_118 , V_56 ) ;
}
int F_64 ( struct V_131 * V_132 ,
struct V_108 * args ,
struct V_109 * V_56 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 ;
struct V_115 * V_116 ;
F_8 ( L_11 , V_34 ) ;
if ( V_56 -> V_114 != NULL )
goto V_148;
V_116 = & V_132 -> V_149 ;
V_118 -> V_125 = 0 ;
F_35 ( & V_116 -> V_122 ) ;
if ( F_32 ( V_150 , & V_116 -> V_151 ) &&
! args -> V_113 ) {
F_8 ( L_12 , V_34 ) ;
goto V_123;
}
V_120 = F_44 ( V_116 ) ;
if ( F_45 ( V_120 ) ) {
if ( V_120 == F_46 ( - V_124 ) )
V_118 -> V_125 = V_87 >> 2 ;
F_8 ( L_13 , V_34 ) ;
goto V_123;
}
F_37 ( & V_116 -> V_122 ) ;
args -> V_111 = V_120 ;
F_8 ( L_14 , V_34 ,
V_120 -> V_144 , V_120 -> V_141 ) ;
V_56 -> V_114 = V_120 ;
V_56 -> V_142 = V_152 ;
V_56 -> V_143 = 0 ;
V_56 -> V_140 = 1 ;
F_65 ( V_132 , args ) ;
V_148:
F_47 ( V_118 ) ;
return 0 ;
V_123:
if ( args -> V_113 )
F_48 ( & V_116 -> V_126 , V_118 ,
NULL , V_127 ) ;
else
F_49 ( & V_116 -> V_126 , V_118 , NULL ) ;
F_37 ( & V_116 -> V_122 ) ;
return - V_128 ;
}
static int F_66 ( const struct V_13 * V_14 ,
struct V_108 * args ,
struct V_109 * V_56 ,
struct V_117 * V_118 )
{
struct V_131 * V_132 = F_67 ( V_14 ) ;
int V_51 = 0 ;
if ( ! V_132 )
return F_42 ( V_14 -> V_62 -> V_153 ,
args , V_56 , V_118 ) ;
F_8 ( L_15 ,
V_34 , V_132 -> V_63 , V_132 , V_56 -> V_114 ?
V_56 -> V_114 -> V_144 : V_137 ) ;
V_51 = F_64 ( V_132 , args , V_56 , V_118 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static void F_68 ( struct V_117 * V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
struct V_131 * V_132 = F_67 ( V_156 -> V_157 ) ;
F_8 ( L_17 , V_34 , V_156 -> V_157 ) ;
F_64 ( V_132 , V_156 -> V_158 , V_156 -> V_159 , V_118 ) ;
}
static void F_69 ( struct V_117 * V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
F_55 ( V_118 , V_156 -> V_159 ) ;
}
static int F_66 ( const struct V_13 * V_14 ,
struct V_108 * args ,
struct V_109 * V_56 ,
struct V_117 * V_118 )
{
return F_42 ( V_14 -> V_62 -> V_153 ,
args , V_56 , V_118 ) ;
}
int F_63 ( struct V_117 * V_118 ,
struct V_109 * V_56 )
{
return F_50 ( V_118 , V_56 ) ;
}
static void F_70 ( struct V_117 * V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
F_66 ( V_156 -> V_157 ,
V_156 -> V_158 , V_156 -> V_159 , V_118 ) ;
}
static void F_71 ( struct V_117 * V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
F_63 ( V_118 , V_156 -> V_159 ) ;
}
static int F_72 ( struct V_54 * V_55 ,
struct V_13 * V_14 ,
struct V_160 * V_161 ,
struct V_108 * args ,
struct V_109 * V_56 )
{
int V_51 ;
struct V_117 * V_118 ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_155 V_156 = {
. V_157 = V_14 ,
. V_158 = args ,
. V_159 = V_56 ,
} ;
struct V_162 V_163 = {
. V_164 = V_55 ,
. V_160 = V_161 ,
. V_165 = V_63 -> V_166 -> V_167 ,
. V_168 = & V_156
} ;
V_118 = F_73 ( & V_163 ) ;
if ( F_45 ( V_118 ) )
V_51 = F_74 ( V_118 ) ;
else {
V_51 = V_118 -> V_147 ;
F_75 ( V_118 ) ;
}
return V_51 ;
}
int F_76 ( struct V_54 * V_55 ,
struct V_13 * V_14 ,
struct V_160 * V_161 ,
struct V_108 * args ,
struct V_109 * V_56 ,
int V_110 )
{
F_40 ( args , V_56 , V_110 ) ;
return F_72 ( V_55 , V_14 , V_161 , args , V_56 ) ;
}
static void F_77 ( struct V_2 * V_3 , struct V_169 * V_170 )
{
struct V_171 * V_172 = F_78 ( V_3 ) ;
F_35 ( & V_3 -> V_173 ) ;
V_172 -> V_174 |= V_175 | V_176 ;
if ( ! V_170 -> V_177 || V_170 -> V_178 != V_3 -> V_179 )
F_79 ( V_3 ) ;
V_3 -> V_179 = V_170 -> V_180 ;
V_172 -> V_181 = F_80 () ;
F_81 ( V_3 ) ;
F_37 ( & V_3 -> V_173 ) ;
}
static bool F_82 ( struct V_13 * V_14 ,
int V_8 , struct V_60 * V_61 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_93 & V_182 ) )
return false ;
V_14 -> V_93 &= ~ V_182 ;
V_61 -> V_66 = 1 ;
return true ;
}
static T_1
F_83 ( struct V_13 * V_14 ,
T_5 V_183 , int V_184 )
{
T_1 V_56 = 0 ;
switch ( V_183 & ( V_71 | V_185 ) ) {
case V_71 :
V_56 = V_186 ;
break;
case V_185 :
V_56 = V_187 ;
break;
case V_71 | V_185 :
V_56 = V_188 ;
}
if ( ! ( V_14 -> V_93 & V_182 ) )
goto V_129;
if ( V_184 & V_189 )
V_56 |= V_190 ;
V_129:
return V_56 ;
}
static enum V_191
F_84 ( struct V_13 * V_14 ,
enum V_191 V_192 )
{
if ( V_14 -> V_93 & V_182 )
return V_192 ;
switch ( V_192 ) {
default:
return V_192 ;
case V_193 :
return V_194 ;
case V_195 :
return V_196 ;
case V_197 :
return V_198 ;
}
}
static void F_85 ( struct V_199 * V_41 )
{
V_41 -> V_200 . V_201 = & V_41 -> V_201 ;
V_41 -> V_200 . V_202 = V_41 -> V_202 ;
V_41 -> V_200 . V_203 = V_41 -> V_204 . V_203 ;
V_41 -> V_205 . V_203 = V_41 -> V_206 . V_203 ;
V_41 -> V_200 . V_14 = V_41 -> V_204 . V_14 ;
V_41 -> V_200 . V_207 = V_41 -> V_204 . V_208 ;
F_86 ( & V_41 -> V_201 ) ;
F_87 ( & V_41 -> V_201 , & V_41 -> V_209 , & V_41 -> V_210 ) ;
}
static struct V_199 * F_88 ( struct V_4 * V_4 ,
struct V_211 * V_212 , T_5 V_183 , int V_213 ,
const struct V_5 * V_214 ,
struct V_1 * V_7 ,
enum V_191 V_192 ,
T_6 V_215 )
{
struct V_4 * V_216 = F_89 ( V_4 ) ;
struct V_2 * V_3 = F_14 ( V_216 ) ;
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
struct V_199 * V_41 ;
V_41 = F_91 ( sizeof( * V_41 ) , V_215 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_202 = F_92 ( V_14 , V_215 ) ;
if ( F_45 ( V_41 -> V_202 ) )
goto V_220;
V_41 -> V_221 = F_92 ( V_14 , V_215 ) ;
if ( F_45 ( V_41 -> V_221 ) )
goto V_222;
V_218 = V_14 -> V_62 -> V_166 -> V_218 ;
V_41 -> V_204 . V_203 = V_218 ( & V_212 -> V_223 , V_215 ) ;
if ( F_45 ( V_41 -> V_204 . V_203 ) )
goto V_224;
F_93 ( V_4 -> V_225 ) ;
V_41 -> V_4 = F_94 ( V_4 ) ;
V_41 -> V_3 = V_216 ;
V_41 -> V_226 = V_212 ;
F_95 ( & V_212 -> V_227 ) ;
V_41 -> V_204 . V_228 = V_213 ;
V_41 -> V_204 . V_183 = V_183 & ( V_71 | V_185 ) ;
V_41 -> V_204 . V_229 = F_83 ( V_14 ,
V_183 , V_213 ) ;
if ( ! ( V_213 & V_230 ) ) {
V_41 -> V_204 . V_208 = V_231 | V_232 |
V_233 | V_234 ;
}
V_41 -> V_204 . V_235 = V_14 -> V_62 -> V_236 ;
V_41 -> V_204 . V_237 . V_238 = F_96 ( V_212 -> V_223 . V_238 ) ;
V_41 -> V_204 . V_237 . V_239 = V_212 -> V_223 . V_240 ;
V_41 -> V_204 . V_241 = & V_4 -> V_11 ;
V_41 -> V_204 . V_14 = V_14 ;
V_41 -> V_204 . V_242 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_204 . V_243 = & V_244 [ 0 ] ;
V_41 -> V_204 . V_7 = F_97 ( V_41 -> V_221 , V_7 ) ;
V_41 -> V_204 . V_192 = F_84 ( V_14 , V_192 ) ;
switch ( V_41 -> V_204 . V_192 ) {
case V_194 :
case V_196 :
case V_198 :
V_41 -> V_204 . V_245 = F_98 ( V_3 ) ;
break;
case V_246 :
case V_193 :
case V_195 :
case V_197 :
V_41 -> V_204 . V_245 = F_98 ( F_14 ( V_4 ) ) ;
}
if ( V_214 != NULL && V_214 -> V_247 != 0 ) {
T_7 V_248 [ 2 ] ;
V_41 -> V_204 . V_249 . V_214 = & V_41 -> V_214 ;
memcpy ( & V_41 -> V_214 , V_214 , sizeof( V_41 -> V_214 ) ) ;
V_248 [ 0 ] = V_152 ;
V_248 [ 1 ] = V_57 -> V_250 ;
memcpy ( V_41 -> V_204 . V_249 . V_37 . V_156 , V_248 ,
sizeof( V_41 -> V_204 . V_249 . V_37 . V_156 ) ) ;
}
V_41 -> V_206 . V_245 = & V_41 -> V_200 . V_245 ;
V_41 -> V_206 . V_251 = & V_41 -> V_200 . V_251 ;
V_41 -> V_206 . V_203 = V_41 -> V_204 . V_203 ;
F_85 ( V_41 ) ;
F_99 ( & V_41 -> V_252 ) ;
return V_41 ;
V_224:
F_100 ( V_41 -> V_221 ) ;
V_222:
F_100 ( V_41 -> V_202 ) ;
V_220:
F_101 ( V_41 ) ;
V_8:
F_102 ( V_216 ) ;
return NULL ;
}
static void F_103 ( struct V_252 * V_252 )
{
struct V_199 * V_41 = F_104 ( V_252 ,
struct V_199 , V_252 ) ;
struct V_253 * V_254 = V_41 -> V_4 -> V_225 ;
F_105 ( V_41 -> V_204 . V_203 ) ;
if ( V_41 -> V_65 != NULL )
F_106 ( V_41 -> V_65 ) ;
F_107 ( V_41 -> V_226 ) ;
F_100 ( V_41 -> V_221 ) ;
F_100 ( V_41 -> V_202 ) ;
F_102 ( V_41 -> V_3 ) ;
F_102 ( V_41 -> V_4 ) ;
F_108 ( V_254 ) ;
F_109 ( & V_41 -> V_201 ) ;
F_101 ( V_41 -> V_201 . V_255 ) ;
F_101 ( V_41 ) ;
}
static void F_110 ( struct V_199 * V_41 )
{
if ( V_41 != NULL )
F_111 ( & V_41 -> V_252 , F_103 ) ;
}
static int F_112 ( struct V_117 * V_118 )
{
int V_51 ;
V_51 = F_113 ( V_118 ) ;
return V_51 ;
}
static int F_114 ( struct V_64 * V_65 , T_5 V_256 , int V_257 )
{
int V_51 = 0 ;
if ( V_257 & ( V_230 | V_258 ) )
goto V_129;
switch ( V_256 & ( V_71 | V_185 ) ) {
case V_71 :
V_51 |= F_32 ( V_259 , & V_65 -> V_213 ) != 0
&& V_65 -> V_260 != 0 ;
break;
case V_185 :
V_51 |= F_32 ( V_261 , & V_65 -> V_213 ) != 0
&& V_65 -> V_262 != 0 ;
break;
case V_71 | V_185 :
V_51 |= F_32 ( V_263 , & V_65 -> V_213 ) != 0
&& V_65 -> V_264 != 0 ;
}
V_129:
return V_51 ;
}
static int F_115 ( struct V_265 * V_266 , T_5 V_183 )
{
if ( V_266 == NULL )
return 0 ;
if ( ( V_266 -> type & V_183 ) != V_183 )
return 0 ;
if ( F_32 ( V_267 , & V_266 -> V_213 ) )
return 0 ;
F_116 ( V_266 ) ;
return 1 ;
}
static void F_117 ( struct V_64 * V_65 , T_5 V_183 )
{
switch ( V_183 ) {
case V_185 :
V_65 -> V_262 ++ ;
break;
case V_71 :
V_65 -> V_260 ++ ;
break;
case V_71 | V_185 :
V_65 -> V_264 ++ ;
}
F_118 ( V_65 , V_65 -> V_65 | V_183 ) ;
}
static void F_119 ( struct V_64 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_226 -> V_268 -> V_62 ;
bool V_269 = false ;
if ( F_120 ( V_259 , & V_65 -> V_213 ) && V_65 -> V_260 )
V_269 = true ;
if ( F_120 ( V_261 , & V_65 -> V_213 ) && V_65 -> V_262 )
V_269 = true ;
if ( F_120 ( V_263 , & V_65 -> V_213 ) && V_65 -> V_264 )
V_269 = true ;
if ( V_269 )
F_121 ( V_63 , V_65 ) ;
}
static bool F_122 ( struct V_64 * V_65 ,
T_8 * V_251 )
{
if ( F_123 ( V_270 , & V_65 -> V_213 ) == 0 )
return true ;
if ( ! F_124 ( V_251 , & V_65 -> V_271 ) ) {
F_119 ( V_65 ) ;
return true ;
}
if ( F_125 ( V_251 , & V_65 -> V_271 ) )
return true ;
return false ;
}
static void F_126 ( struct V_64 * V_65 )
{
if ( ! ( V_65 -> V_262 || V_65 -> V_260 || V_65 -> V_264 ) )
return;
if ( V_65 -> V_262 )
F_127 ( V_261 , & V_65 -> V_213 ) ;
if ( V_65 -> V_260 )
F_127 ( V_259 , & V_65 -> V_213 ) ;
if ( V_65 -> V_264 )
F_127 ( V_263 , & V_65 -> V_213 ) ;
F_127 ( V_270 , & V_65 -> V_213 ) ;
}
static void F_128 ( struct V_64 * V_65 ,
T_8 * V_251 , T_5 V_183 )
{
F_129 ( V_263 , & V_65 -> V_213 ) ;
switch ( V_183 & ( V_71 | V_185 ) ) {
case V_185 :
F_129 ( V_259 , & V_65 -> V_213 ) ;
break;
case V_71 :
F_129 ( V_261 , & V_65 -> V_213 ) ;
break;
case 0 :
F_129 ( V_259 , & V_65 -> V_213 ) ;
F_129 ( V_261 , & V_65 -> V_213 ) ;
F_129 ( V_270 , & V_65 -> V_213 ) ;
}
if ( V_251 == NULL )
return;
if ( ! F_124 ( V_251 , & V_65 -> V_271 ) ||
! F_125 ( V_251 , & V_65 -> V_271 ) ) {
F_126 ( V_65 ) ;
return;
}
if ( F_32 ( V_272 , & V_65 -> V_213 ) == 0 )
F_130 ( & V_65 -> V_251 , V_251 ) ;
F_130 ( & V_65 -> V_271 , V_251 ) ;
}
static void F_131 ( struct V_64 * V_65 , T_8 * V_251 , T_5 V_183 )
{
F_132 ( & V_65 -> V_273 ) ;
F_128 ( V_65 , V_251 , V_183 ) ;
F_133 ( & V_65 -> V_273 ) ;
if ( F_32 ( V_274 , & V_65 -> V_213 ) )
F_134 ( V_65 -> V_226 -> V_268 -> V_62 ) ;
}
static void F_135 ( struct V_64 * V_65 , T_8 * V_251 , T_5 V_183 )
{
switch ( V_183 ) {
case V_71 :
F_127 ( V_259 , & V_65 -> V_213 ) ;
break;
case V_185 :
F_127 ( V_261 , & V_65 -> V_213 ) ;
break;
case V_71 | V_185 :
F_127 ( V_263 , & V_65 -> V_213 ) ;
}
if ( ! F_122 ( V_65 , V_251 ) )
return;
if ( F_32 ( V_272 , & V_65 -> V_213 ) == 0 )
F_130 ( & V_65 -> V_251 , V_251 ) ;
F_130 ( & V_65 -> V_271 , V_251 ) ;
}
static void F_136 ( struct V_64 * V_65 , T_8 * V_271 , const T_8 * V_275 , T_5 V_183 )
{
F_132 ( & V_65 -> V_273 ) ;
if ( V_275 != NULL ) {
F_130 ( & V_65 -> V_251 , V_275 ) ;
F_127 ( V_272 , & V_65 -> V_213 ) ;
}
if ( V_271 != NULL )
F_135 ( V_65 , V_271 , V_183 ) ;
F_133 ( & V_65 -> V_273 ) ;
F_35 ( & V_65 -> V_226 -> V_276 ) ;
F_117 ( V_65 , V_183 ) ;
F_37 ( & V_65 -> V_226 -> V_276 ) ;
}
static int F_137 ( struct V_64 * V_65 , T_8 * V_271 , T_8 * V_266 , T_5 V_183 )
{
struct V_171 * V_172 = F_78 ( V_65 -> V_2 ) ;
struct V_265 * V_277 ;
int V_51 = 0 ;
V_183 &= ( V_71 | V_185 ) ;
F_138 () ;
V_277 = F_139 ( V_172 -> V_266 ) ;
if ( V_277 == NULL )
goto V_278;
F_35 ( & V_277 -> V_279 ) ;
if ( F_139 ( V_172 -> V_266 ) != V_277 ||
F_32 ( V_267 , & V_277 -> V_213 ) ||
( V_277 -> type & V_183 ) != V_183 )
goto V_280;
if ( V_266 == NULL )
V_266 = & V_277 -> V_251 ;
else if ( ! F_140 ( & V_277 -> V_251 , V_266 ) )
goto V_280;
F_116 ( V_277 ) ;
F_136 ( V_65 , V_271 , & V_277 -> V_251 , V_183 ) ;
V_51 = 1 ;
V_280:
F_37 ( & V_277 -> V_279 ) ;
V_278:
F_141 () ;
if ( ! V_51 && V_271 != NULL ) {
F_136 ( V_65 , V_271 , NULL , V_183 ) ;
V_51 = 1 ;
}
if ( F_32 ( V_274 , & V_65 -> V_213 ) )
F_134 ( V_65 -> V_226 -> V_268 -> V_62 ) ;
return V_51 ;
}
static bool F_142 ( struct V_281 * V_282 ,
const T_8 * V_251 )
{
struct V_64 * V_65 = V_282 -> V_283 ;
bool V_51 = false ;
F_35 ( & V_65 -> V_284 ) ;
if ( ! F_124 ( V_251 , & V_282 -> V_285 ) )
goto V_286;
if ( ! F_125 ( V_251 , & V_282 -> V_285 ) )
goto V_286;
F_130 ( & V_282 -> V_285 , V_251 ) ;
V_51 = true ;
V_286:
F_37 ( & V_65 -> V_284 ) ;
return V_51 ;
}
static void F_143 ( struct V_2 * V_2 , T_5 V_183 )
{
struct V_265 * V_266 ;
F_138 () ;
V_266 = F_139 ( F_78 ( V_2 ) -> V_266 ) ;
if ( V_266 == NULL || ( V_266 -> type & V_183 ) == V_183 ) {
F_141 () ;
return;
}
F_141 () ;
F_23 ( V_2 ) ;
}
static struct V_64 * F_144 ( struct V_199 * V_287 )
{
struct V_64 * V_65 = V_287 -> V_65 ;
struct V_171 * V_172 = F_78 ( V_65 -> V_2 ) ;
struct V_265 * V_266 ;
int V_257 = V_287 -> V_204 . V_228 ;
T_5 V_183 = V_287 -> V_204 . V_183 ;
T_8 V_251 ;
int V_51 = - V_128 ;
for (; ; ) {
F_35 ( & V_65 -> V_226 -> V_276 ) ;
if ( F_114 ( V_65 , V_183 , V_257 ) ) {
F_117 ( V_65 , V_183 ) ;
F_37 ( & V_65 -> V_226 -> V_276 ) ;
goto V_288;
}
F_37 ( & V_65 -> V_226 -> V_276 ) ;
F_138 () ;
V_266 = F_139 ( V_172 -> V_266 ) ;
if ( ! F_115 ( V_266 , V_183 ) ) {
F_141 () ;
break;
}
F_130 ( & V_251 , & V_266 -> V_251 ) ;
F_141 () ;
F_145 ( V_287 -> V_204 . V_203 ) ;
if ( ! V_287 -> V_289 ) {
V_51 = F_146 ( V_65 -> V_2 , V_65 -> V_226 -> V_290 , V_257 ) ;
if ( V_51 != 0 )
goto V_129;
}
V_51 = - V_128 ;
if ( F_137 ( V_65 , NULL , & V_251 , V_183 ) )
goto V_288;
}
V_129:
return F_46 ( V_51 ) ;
V_288:
F_95 ( & V_65 -> V_49 ) ;
return V_65 ;
}
static void
F_147 ( struct V_199 * V_156 , struct V_64 * V_65 )
{
struct V_62 * V_63 = F_90 ( V_65 -> V_2 ) -> V_62 ;
struct V_265 * V_266 ;
int V_291 = 0 ;
F_138 () ;
V_266 = F_139 ( F_78 ( V_65 -> V_2 ) -> V_266 ) ;
if ( V_266 )
V_291 = V_266 -> V_213 ;
F_141 () ;
if ( V_156 -> V_204 . V_192 == V_196 ) {
F_148 ( L_18
L_19
L_20 ,
V_63 -> V_96 ) ;
} else if ( ( V_291 & 1UL << V_292 ) == 0 )
F_149 ( V_65 -> V_2 ,
V_156 -> V_226 -> V_290 ,
& V_156 -> V_200 ) ;
else
F_150 ( V_65 -> V_2 ,
V_156 -> V_226 -> V_290 ,
& V_156 -> V_200 ) ;
}
static struct V_64 *
F_151 ( struct V_199 * V_156 )
{
struct V_2 * V_2 = V_156 -> V_65 -> V_2 ;
struct V_64 * V_65 = V_156 -> V_65 ;
int V_51 ;
if ( ! V_156 -> V_293 ) {
if ( V_156 -> V_294 ) {
V_51 = V_156 -> V_294 ;
goto V_8;
}
goto V_295;
}
V_51 = F_152 ( V_2 , & V_156 -> V_201 ) ;
if ( V_51 )
goto V_8;
if ( V_156 -> V_200 . V_296 != 0 )
F_147 ( V_156 , V_65 ) ;
V_295:
F_137 ( V_65 , & V_156 -> V_200 . V_251 , NULL ,
V_156 -> V_204 . V_183 ) ;
F_95 ( & V_65 -> V_49 ) ;
return V_65 ;
V_8:
return F_46 ( V_51 ) ;
}
static struct V_64 *
F_153 ( struct V_199 * V_156 )
{
struct V_2 * V_2 ;
struct V_64 * V_65 = NULL ;
int V_51 ;
if ( ! V_156 -> V_293 ) {
V_65 = F_144 ( V_156 ) ;
goto V_129;
}
V_51 = - V_128 ;
if ( ! ( V_156 -> V_201 . V_297 & V_298 ) )
goto V_8;
V_2 = F_154 ( V_156 -> V_3 -> V_225 , & V_156 -> V_200 . V_245 , & V_156 -> V_201 , V_156 -> V_202 ) ;
V_51 = F_74 ( V_2 ) ;
if ( F_45 ( V_2 ) )
goto V_8;
V_51 = - V_124 ;
V_65 = F_155 ( V_2 , V_156 -> V_226 ) ;
if ( V_65 == NULL )
goto V_299;
if ( V_156 -> V_200 . V_296 != 0 )
F_147 ( V_156 , V_65 ) ;
F_137 ( V_65 , & V_156 -> V_200 . V_251 , NULL ,
V_156 -> V_204 . V_183 ) ;
F_156 ( V_2 ) ;
V_129:
F_145 ( V_156 -> V_204 . V_203 ) ;
return V_65 ;
V_299:
F_156 ( V_2 ) ;
V_8:
return F_46 ( V_51 ) ;
}
static struct V_64 *
F_157 ( struct V_199 * V_156 )
{
if ( V_156 -> V_204 . V_192 == V_246 )
return F_151 ( V_156 ) ;
return F_153 ( V_156 ) ;
}
static struct V_300 * F_158 ( struct V_64 * V_65 )
{
struct V_171 * V_172 = F_78 ( V_65 -> V_2 ) ;
struct V_300 * V_301 ;
F_35 ( & V_65 -> V_2 -> V_173 ) ;
F_159 (ctx, &nfsi->open_files, list) {
if ( V_301 -> V_65 != V_65 )
continue;
F_160 ( V_301 ) ;
F_37 ( & V_65 -> V_2 -> V_173 ) ;
return V_301 ;
}
F_37 ( & V_65 -> V_2 -> V_173 ) ;
return F_46 ( - V_302 ) ;
}
static struct V_199 * F_161 ( struct V_300 * V_301 ,
struct V_64 * V_65 , enum V_191 V_192 )
{
struct V_199 * V_287 ;
V_287 = F_88 ( V_301 -> V_4 , V_65 -> V_226 , 0 , 0 ,
NULL , NULL , V_192 , V_303 ) ;
if ( V_287 == NULL )
return F_46 ( - V_124 ) ;
V_287 -> V_65 = V_65 ;
F_95 ( & V_65 -> V_49 ) ;
return V_287 ;
}
static int F_162 ( struct V_199 * V_287 , T_5 V_183 , struct V_64 * * V_56 )
{
struct V_64 * V_304 ;
int V_51 ;
if ( ( V_287 -> V_204 . V_192 == V_196 ||
V_287 -> V_204 . V_192 == V_195 ) &&
( V_287 -> V_204 . V_249 . V_296 & V_183 ) != V_183 )
return 0 ;
V_287 -> V_204 . V_228 = 0 ;
V_287 -> V_204 . V_183 = V_183 ;
V_287 -> V_204 . V_229 = F_83 (
F_163 ( V_287 -> V_4 -> V_225 ) ,
V_183 , 0 ) ;
memset ( & V_287 -> V_200 , 0 , sizeof( V_287 -> V_200 ) ) ;
memset ( & V_287 -> V_205 , 0 , sizeof( V_287 -> V_205 ) ) ;
F_85 ( V_287 ) ;
V_51 = F_164 ( V_287 ) ;
if ( V_51 != 0 )
return V_51 ;
V_304 = F_157 ( V_287 ) ;
if ( F_45 ( V_304 ) )
return F_74 ( V_304 ) ;
F_165 ( V_304 , V_183 ) ;
* V_56 = V_304 ;
return 0 ;
}
static int F_166 ( struct V_199 * V_287 , struct V_64 * V_65 )
{
struct V_64 * V_304 ;
int V_51 ;
F_129 ( V_263 , & V_65 -> V_213 ) ;
F_129 ( V_261 , & V_65 -> V_213 ) ;
F_129 ( V_259 , & V_65 -> V_213 ) ;
F_129 ( V_272 , & V_65 -> V_213 ) ;
F_129 ( V_270 , & V_65 -> V_213 ) ;
F_167 () ;
if ( V_65 -> V_264 != 0 ) {
V_51 = F_162 ( V_287 , V_71 | V_185 , & V_304 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( V_304 != V_65 )
return - V_305 ;
}
if ( V_65 -> V_262 != 0 ) {
V_51 = F_162 ( V_287 , V_185 , & V_304 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( V_304 != V_65 )
return - V_305 ;
}
if ( V_65 -> V_260 != 0 ) {
V_51 = F_162 ( V_287 , V_71 , & V_304 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( V_304 != V_65 )
return - V_305 ;
}
if ( F_32 ( V_272 , & V_65 -> V_213 ) == 0 &&
! F_140 ( & V_65 -> V_251 , & V_65 -> V_271 ) ) {
F_132 ( & V_65 -> V_273 ) ;
if ( F_32 ( V_272 , & V_65 -> V_213 ) == 0 )
F_130 ( & V_65 -> V_251 , & V_65 -> V_271 ) ;
F_133 ( & V_65 -> V_273 ) ;
}
return 0 ;
}
static int F_168 ( struct V_300 * V_301 , struct V_64 * V_65 )
{
struct V_265 * V_266 ;
struct V_199 * V_287 ;
T_5 V_296 = 0 ;
int V_306 ;
V_287 = F_161 ( V_301 , V_65 ,
V_246 ) ;
if ( F_45 ( V_287 ) )
return F_74 ( V_287 ) ;
F_138 () ;
V_266 = F_139 ( F_78 ( V_65 -> V_2 ) -> V_266 ) ;
if ( V_266 != NULL && F_32 ( V_292 , & V_266 -> V_213 ) != 0 )
V_296 = V_266 -> type ;
F_141 () ;
V_287 -> V_204 . V_249 . V_296 = V_296 ;
V_306 = F_166 ( V_287 , V_65 ) ;
F_110 ( V_287 ) ;
return V_306 ;
}
static int F_169 ( struct V_300 * V_301 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_168 ( V_301 , V_65 ) ;
F_170 ( V_301 , 0 , V_8 ) ;
if ( F_82 ( V_14 , V_8 , & V_61 ) )
continue;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_171 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
struct V_300 * V_301 ;
int V_51 ;
V_301 = F_158 ( V_65 ) ;
if ( F_45 ( V_301 ) )
return - V_128 ;
V_51 = F_169 ( V_301 , V_65 ) ;
F_172 ( V_301 ) ;
return V_51 ;
}
static int F_173 ( struct V_13 * V_14 , struct V_64 * V_65 , const T_8 * V_251 , int V_8 )
{
switch ( V_8 ) {
default:
F_30 ( V_307 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_302 :
case - V_128 :
case - V_305 :
break;
case - V_79 :
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
F_127 ( V_272 , & V_65 -> V_213 ) ;
F_29 ( V_14 -> V_62 -> V_86 , V_8 ) ;
return - V_128 ;
case - V_75 :
case - V_74 :
F_127 ( V_272 , & V_65 -> V_213 ) ;
case - V_73 :
F_25 ( V_14 -> V_62 ) ;
return - V_128 ;
case - V_76 :
F_26 ( V_14 ) ;
return - V_128 ;
case - V_77 :
F_27 ( V_14 -> V_62 ) ;
return - V_128 ;
case - V_68 :
case - V_69 :
case - V_70 :
case - V_67 :
F_174 ( V_65 -> V_2 ,
V_251 ) ;
F_24 ( V_14 , V_65 ) ;
return - V_128 ;
case - V_89 :
case - V_88 :
F_127 ( V_272 , & V_65 -> V_213 ) ;
F_175 ( 1 ) ;
return - V_128 ;
case - V_124 :
case - V_308 :
return 0 ;
}
return V_8 ;
}
int F_176 ( struct V_300 * V_301 , struct V_64 * V_65 , const T_8 * V_251 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_199 * V_287 ;
int V_8 ;
V_287 = F_161 ( V_301 , V_65 ,
V_195 ) ;
if ( F_45 ( V_287 ) )
return F_74 ( V_287 ) ;
F_130 ( & V_287 -> V_204 . V_249 . V_266 , V_251 ) ;
V_8 = F_166 ( V_287 , V_65 ) ;
F_110 ( V_287 ) ;
return F_173 ( V_14 , V_65 , V_251 , V_8 ) ;
}
static void F_177 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
F_42 ( V_156 -> V_204 . V_14 -> V_62 -> V_153 ,
& V_156 -> V_206 . V_158 , & V_156 -> V_205 . V_159 , V_118 ) ;
}
static void F_178 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
F_50 ( V_118 , & V_156 -> V_205 . V_159 ) ;
V_156 -> V_294 = V_118 -> V_147 ;
if ( V_156 -> V_294 == 0 ) {
F_130 ( & V_156 -> V_200 . V_251 , & V_156 -> V_205 . V_251 ) ;
F_179 ( & V_156 -> V_226 -> V_223 , 0 ) ;
F_38 ( V_156 -> V_200 . V_14 , V_156 -> V_105 ) ;
V_156 -> V_293 = 1 ;
}
}
static void F_180 ( void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_64 * V_65 = NULL ;
if ( V_156 -> V_309 == 0 )
goto V_310;
if ( ! V_156 -> V_293 )
goto V_310;
V_65 = F_157 ( V_156 ) ;
if ( ! F_45 ( V_65 ) )
F_165 ( V_65 , V_156 -> V_204 . V_183 ) ;
V_310:
F_110 ( V_156 ) ;
}
static int F_181 ( struct V_199 * V_156 )
{
struct V_13 * V_14 = F_90 ( F_14 ( V_156 -> V_3 ) ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_313 ] ,
. V_314 = & V_156 -> V_206 ,
. V_315 = & V_156 -> V_205 ,
. V_316 = V_156 -> V_226 -> V_290 ,
} ;
struct V_162 V_317 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_318 ,
. V_168 = V_156 ,
. V_319 = V_320 ,
. V_213 = V_321 ,
} ;
int V_306 ;
F_40 ( & V_156 -> V_206 . V_158 , & V_156 -> V_205 . V_159 , 1 ) ;
F_182 ( & V_156 -> V_252 ) ;
V_156 -> V_293 = 0 ;
V_156 -> V_294 = 0 ;
V_156 -> V_105 = V_152 ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_306 = F_112 ( V_118 ) ;
if ( V_306 != 0 ) {
V_156 -> V_309 = 1 ;
F_183 () ;
} else
V_306 = V_156 -> V_294 ;
F_75 ( V_118 ) ;
return V_306 ;
}
static void F_184 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_211 * V_212 = V_156 -> V_226 ;
struct V_62 * V_63 = V_212 -> V_268 -> V_62 ;
if ( F_185 ( V_156 -> V_204 . V_203 , V_118 ) != 0 )
goto V_322;
if ( V_156 -> V_65 != NULL ) {
struct V_265 * V_266 ;
if ( F_114 ( V_156 -> V_65 , V_156 -> V_204 . V_183 , V_156 -> V_204 . V_228 ) )
goto V_323;
F_138 () ;
V_266 = F_139 ( F_78 ( V_156 -> V_65 -> V_2 ) -> V_266 ) ;
if ( V_156 -> V_204 . V_192 != V_196 &&
V_156 -> V_204 . V_192 != V_195 &&
F_115 ( V_266 , V_156 -> V_204 . V_183 ) )
goto V_324;
F_141 () ;
}
V_156 -> V_204 . V_235 = V_63 -> V_236 ;
switch ( V_156 -> V_204 . V_192 ) {
case V_246 :
case V_195 :
case V_197 :
V_156 -> V_204 . V_243 = & V_325 [ 0 ] ;
case V_193 :
V_118 -> V_326 . V_311 = & V_312 [ V_327 ] ;
F_186 ( & V_156 -> V_200 . V_245 , V_156 -> V_204 . V_245 ) ;
}
V_156 -> V_105 = V_152 ;
if ( F_66 ( V_156 -> V_204 . V_14 ,
& V_156 -> V_204 . V_158 ,
& V_156 -> V_200 . V_159 ,
V_118 ) != 0 )
F_145 ( V_156 -> V_204 . V_203 ) ;
V_156 -> V_204 . V_328 = V_329 ;
if ( V_156 -> V_204 . V_228 & V_230 ) {
V_156 -> V_204 . V_328 = V_330 ;
if ( F_187 ( V_63 ) )
V_156 -> V_204 . V_328 = V_331 ;
else if ( V_63 -> V_166 -> V_332 > 0 )
V_156 -> V_204 . V_328 = V_333 ;
}
return;
V_324:
F_141 () ;
V_323:
V_118 -> V_334 = NULL ;
V_322:
F_63 ( V_118 , & V_156 -> V_200 . V_159 ) ;
}
static void F_188 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
V_156 -> V_294 = V_118 -> V_147 ;
if ( ! F_63 ( V_118 , & V_156 -> V_200 . V_159 ) )
return;
if ( V_118 -> V_147 == 0 ) {
if ( V_156 -> V_200 . V_201 -> V_297 & V_335 ) {
switch ( V_156 -> V_200 . V_201 -> V_256 & V_336 ) {
case V_337 :
break;
case V_338 :
V_156 -> V_294 = - V_339 ;
break;
case V_340 :
V_156 -> V_294 = - V_341 ;
break;
default:
V_156 -> V_294 = - V_342 ;
}
}
F_38 ( V_156 -> V_200 . V_14 , V_156 -> V_105 ) ;
if ( ! ( V_156 -> V_200 . V_343 & V_344 ) )
F_179 ( & V_156 -> V_226 -> V_223 , 0 ) ;
}
V_156 -> V_293 = 1 ;
}
static void F_189 ( void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_64 * V_65 = NULL ;
if ( V_156 -> V_309 == 0 )
goto V_310;
if ( V_156 -> V_294 != 0 || ! V_156 -> V_293 )
goto V_310;
if ( V_156 -> V_200 . V_343 & V_344 )
goto V_310;
V_65 = F_157 ( V_156 ) ;
if ( ! F_45 ( V_65 ) )
F_165 ( V_65 , V_156 -> V_204 . V_183 ) ;
V_310:
F_110 ( V_156 ) ;
}
static int F_190 ( struct V_199 * V_156 , int V_345 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_346 * V_204 = & V_156 -> V_204 ;
struct V_347 * V_200 = & V_156 -> V_200 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_348 ] ,
. V_314 = V_204 ,
. V_315 = V_200 ,
. V_316 = V_156 -> V_226 -> V_290 ,
} ;
struct V_162 V_317 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_349 ,
. V_168 = V_156 ,
. V_319 = V_320 ,
. V_213 = V_321 ,
} ;
int V_306 ;
F_40 ( & V_204 -> V_158 , & V_200 -> V_159 , 1 ) ;
F_182 ( & V_156 -> V_252 ) ;
V_156 -> V_293 = 0 ;
V_156 -> V_294 = 0 ;
V_156 -> V_309 = 0 ;
V_156 -> V_289 = 0 ;
if ( V_345 ) {
F_41 ( & V_204 -> V_158 ) ;
V_156 -> V_289 = 1 ;
}
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_306 = F_112 ( V_118 ) ;
if ( V_306 != 0 ) {
V_156 -> V_309 = 1 ;
F_183 () ;
} else
V_306 = V_156 -> V_294 ;
F_75 ( V_118 ) ;
return V_306 ;
}
static int F_164 ( struct V_199 * V_156 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_347 * V_200 = & V_156 -> V_200 ;
int V_306 ;
V_306 = F_190 ( V_156 , 1 ) ;
if ( V_306 != 0 || ! V_156 -> V_293 )
return V_306 ;
F_191 ( F_90 ( V_3 ) , & V_156 -> V_201 ) ;
if ( V_200 -> V_343 & V_344 ) {
V_306 = F_181 ( V_156 ) ;
if ( V_306 != 0 )
return V_306 ;
}
return V_306 ;
}
static int F_192 ( struct V_316 * V_350 ,
struct V_199 * V_287 ,
struct V_64 * V_65 , T_5 V_183 ,
int V_184 )
{
struct V_351 V_352 ;
T_1 V_353 ;
if ( V_287 -> V_200 . V_354 == 0 )
return 0 ;
V_353 = 0 ;
if ( V_184 & V_355 ) {
V_353 = V_356 ;
} else if ( ( V_183 & V_71 ) && ! V_287 -> V_357 )
V_353 = V_358 ;
V_352 . V_350 = V_350 ;
V_352 . V_152 = V_152 ;
F_193 ( & V_352 , V_287 -> V_200 . V_359 ) ;
F_194 ( V_65 -> V_2 , & V_352 ) ;
if ( ( V_353 & ~ V_352 . V_353 & ( V_358 | V_356 ) ) == 0 )
return 0 ;
F_165 ( V_65 , V_183 ) ;
return - V_29 ;
}
static int F_195 ( struct V_199 * V_156 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_346 * V_204 = & V_156 -> V_204 ;
struct V_347 * V_200 = & V_156 -> V_200 ;
int V_306 ;
V_306 = F_190 ( V_156 , 0 ) ;
if ( ! V_156 -> V_293 )
return V_306 ;
if ( V_306 != 0 ) {
if ( V_306 == - V_26 &&
! ( V_204 -> V_228 & V_360 ) )
return - V_302 ;
return V_306 ;
}
F_191 ( V_14 , & V_156 -> V_201 ) ;
if ( V_204 -> V_228 & V_360 ) {
F_77 ( V_3 , & V_200 -> V_170 ) ;
if ( V_204 -> V_228 & V_230 )
V_156 -> V_357 = 1 ;
else if ( V_200 -> V_170 . V_178 != V_200 -> V_170 . V_180 )
V_156 -> V_357 = 1 ;
}
if ( ( V_200 -> V_343 & V_361 ) == 0 )
V_14 -> V_93 &= ~ V_362 ;
if( V_200 -> V_343 & V_344 ) {
V_306 = F_181 ( V_156 ) ;
if ( V_306 != 0 )
return V_306 ;
}
if ( ! ( V_200 -> V_201 -> V_297 & V_298 ) )
F_196 ( V_14 , & V_200 -> V_245 , V_200 -> V_201 , V_200 -> V_202 ) ;
return 0 ;
}
static int F_197 ( struct V_13 * V_14 )
{
return F_198 ( V_14 -> V_62 ) ;
}
static int F_199 ( struct V_300 * V_301 , struct V_64 * V_65 )
{
struct V_199 * V_287 ;
int V_51 ;
V_287 = F_161 ( V_301 , V_65 ,
V_193 ) ;
if ( F_45 ( V_287 ) )
return F_74 ( V_287 ) ;
V_51 = F_166 ( V_287 , V_65 ) ;
if ( V_51 == - V_305 )
F_200 ( V_301 -> V_4 ) ;
F_110 ( V_287 ) ;
return V_51 ;
}
static int F_201 ( struct V_300 * V_301 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_199 ( V_301 , V_65 ) ;
F_202 ( V_301 , 0 , V_8 ) ;
if ( F_82 ( V_14 , V_8 , & V_61 ) )
continue;
switch ( V_8 ) {
default:
goto V_129;
case - V_88 :
case - V_89 :
F_21 ( V_14 , V_8 , & V_61 ) ;
V_8 = 0 ;
}
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static int F_203 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
struct V_300 * V_301 ;
int V_51 ;
V_301 = F_158 ( V_65 ) ;
if ( F_45 ( V_301 ) )
return - V_128 ;
V_51 = F_201 ( V_301 , V_65 ) ;
F_172 ( V_301 ) ;
return V_51 ;
}
static void F_204 ( struct V_64 * V_65 )
{
F_205 ( V_65 -> V_2 ) ;
F_132 ( & V_65 -> V_273 ) ;
F_130 ( & V_65 -> V_251 , & V_65 -> V_271 ) ;
F_133 ( & V_65 -> V_273 ) ;
F_129 ( V_272 , & V_65 -> V_213 ) ;
}
static void F_206 ( struct V_64 * V_65 )
{
if ( F_207 ( F_78 ( V_65 -> V_2 ) -> V_266 ) != NULL )
F_204 ( V_65 ) ;
}
static int F_208 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
F_206 ( V_65 ) ;
return F_203 ( V_212 , V_65 ) ;
}
static void F_209 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
T_8 V_251 ;
struct V_265 * V_266 ;
struct V_316 * V_350 ;
int V_306 ;
F_138 () ;
V_266 = F_139 ( F_78 ( V_65 -> V_2 ) -> V_266 ) ;
if ( V_266 == NULL ) {
F_141 () ;
return;
}
F_130 ( & V_251 , & V_266 -> V_251 ) ;
V_350 = F_210 ( V_266 -> V_350 ) ;
F_141 () ;
V_306 = F_211 ( V_14 , & V_251 , V_350 ) ;
F_212 ( V_65 , NULL , V_306 ) ;
if ( V_306 != V_363 ) {
if ( V_306 != - V_70 )
F_213 ( V_14 , & V_251 , V_350 ) ;
F_204 ( V_65 ) ;
}
F_214 ( V_350 ) ;
}
static int F_215 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
T_8 * V_251 = & V_65 -> V_271 ;
struct V_316 * V_350 = V_65 -> V_226 -> V_290 ;
int V_306 ;
if ( ( F_32 ( V_259 , & V_65 -> V_213 ) == 0 ) &&
( F_32 ( V_261 , & V_65 -> V_213 ) == 0 ) &&
( F_32 ( V_263 , & V_65 -> V_213 ) == 0 ) )
return - V_70 ;
V_306 = F_211 ( V_14 , V_251 , V_350 ) ;
F_216 ( V_65 , NULL , V_306 ) ;
if ( V_306 != V_363 ) {
if ( V_306 != - V_70 )
F_213 ( V_14 , V_251 , V_350 ) ;
F_129 ( V_259 , & V_65 -> V_213 ) ;
F_129 ( V_261 , & V_65 -> V_213 ) ;
F_129 ( V_263 , & V_65 -> V_213 ) ;
F_129 ( V_270 , & V_65 -> V_213 ) ;
}
return V_306 ;
}
static int F_217 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
int V_306 ;
F_209 ( V_65 ) ;
V_306 = F_215 ( V_65 ) ;
if ( V_306 != V_363 )
V_306 = F_203 ( V_212 , V_65 ) ;
return V_306 ;
}
static inline void F_218 ( struct V_199 * V_287 , struct V_5 * V_6 )
{
if ( ( V_287 -> V_200 . V_364 [ 1 ] & V_365 ) &&
! ( V_6 -> V_247 & V_366 ) )
V_6 -> V_247 |= V_367 ;
if ( ( V_287 -> V_200 . V_364 [ 1 ] & V_368 ) &&
! ( V_6 -> V_247 & V_369 ) )
V_6 -> V_247 |= V_370 ;
}
static int F_219 ( struct V_199 * V_287 ,
T_5 V_183 ,
int V_213 ,
struct V_300 * V_301 )
{
struct V_211 * V_212 = V_287 -> V_226 ;
struct V_13 * V_14 = V_212 -> V_268 ;
struct V_4 * V_4 ;
struct V_64 * V_65 ;
unsigned int V_371 ;
int V_51 ;
V_371 = F_220 ( & V_212 -> V_372 ) ;
V_51 = F_195 ( V_287 ) ;
if ( V_51 != 0 )
goto V_129;
V_65 = F_157 ( V_287 ) ;
V_51 = F_74 ( V_65 ) ;
if ( F_45 ( V_65 ) )
goto V_129;
if ( V_14 -> V_93 & V_362 )
F_127 ( V_373 , & V_65 -> V_213 ) ;
V_4 = V_287 -> V_4 ;
if ( F_221 ( V_4 ) ) {
F_200 ( V_4 ) ;
V_4 = F_222 ( V_4 , F_223 ( V_65 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_287 -> V_4 ;
} else if ( V_4 != V_301 -> V_4 ) {
F_102 ( V_301 -> V_4 ) ;
V_301 -> V_4 = F_94 ( V_4 ) ;
}
F_224 ( V_4 ,
F_225 ( F_14 ( V_287 -> V_3 ) ) ) ;
}
V_51 = F_192 ( V_212 -> V_290 , V_287 , V_65 , V_183 , V_213 ) ;
if ( V_51 != 0 )
goto V_129;
V_301 -> V_65 = V_65 ;
if ( F_14 ( V_4 ) == V_65 -> V_2 ) {
F_226 ( V_301 ) ;
if ( F_227 ( & V_212 -> V_372 , V_371 ) )
F_24 ( V_14 , V_65 ) ;
}
V_129:
return V_51 ;
}
static int F_228 ( struct V_2 * V_3 ,
struct V_300 * V_301 ,
int V_213 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_374 )
{
struct V_211 * V_212 ;
struct V_64 * V_65 = NULL ;
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_199 * V_287 ;
struct V_4 * V_4 = V_301 -> V_4 ;
struct V_316 * V_350 = V_301 -> V_350 ;
struct V_375 * * V_376 = & V_301 -> V_255 ;
T_5 V_183 = V_301 -> V_256 & ( V_71 | V_185 | V_377 ) ;
enum V_191 V_192 = V_194 ;
struct V_1 * V_378 = NULL ;
int V_306 ;
V_306 = - V_124 ;
V_212 = F_229 ( V_14 , V_350 , V_379 ) ;
if ( V_212 == NULL ) {
F_8 ( L_23 ) ;
goto V_380;
}
V_306 = F_197 ( V_14 ) ;
if ( V_306 != 0 )
goto V_381;
if ( F_230 ( V_4 ) )
F_143 ( F_14 ( V_4 ) , V_183 ) ;
V_306 = - V_124 ;
if ( F_230 ( V_4 ) )
V_192 = V_193 ;
V_287 = F_88 ( V_4 , V_212 , V_183 , V_213 , V_6 ,
V_7 , V_192 , V_379 ) ;
if ( V_287 == NULL )
goto V_381;
if ( V_7 ) {
V_378 = F_92 ( V_14 , V_379 ) ;
if ( F_45 ( V_378 ) ) {
V_306 = F_74 ( V_378 ) ;
goto V_382;
}
}
if ( V_14 -> V_15 [ 2 ] & V_383 ) {
if ( ! V_287 -> V_201 . V_255 ) {
V_287 -> V_201 . V_255 = F_231 () ;
if ( ! V_287 -> V_201 . V_255 )
goto V_224;
}
V_287 -> V_204 . V_243 = & V_384 [ 0 ] ;
}
if ( F_230 ( V_4 ) )
V_287 -> V_65 = F_155 ( F_14 ( V_4 ) , V_212 ) ;
V_306 = F_219 ( V_287 , V_183 , V_213 , V_301 ) ;
if ( V_306 != 0 )
goto V_224;
V_65 = V_301 -> V_65 ;
if ( ( V_287 -> V_204 . V_228 & V_230 ) &&
( V_287 -> V_204 . V_328 != V_331 ) ) {
F_218 ( V_287 , V_6 ) ;
F_86 ( V_287 -> V_200 . V_201 ) ;
V_306 = F_232 ( V_65 -> V_2 , V_350 ,
V_287 -> V_200 . V_201 , V_6 ,
V_65 , V_7 , V_378 ) ;
if ( V_306 == 0 ) {
F_233 ( V_65 -> V_2 , V_6 ,
V_287 -> V_200 . V_201 ) ;
F_234 ( V_65 -> V_2 , V_287 -> V_200 . V_201 , V_378 ) ;
}
}
if ( V_287 -> V_357 )
* V_374 |= V_385 ;
if ( F_235 ( V_376 , V_287 -> V_201 . V_255 , V_14 ) ) {
* V_376 = V_287 -> V_201 . V_255 ;
V_287 -> V_201 . V_255 = NULL ;
}
F_100 ( V_378 ) ;
F_110 ( V_287 ) ;
F_107 ( V_212 ) ;
return 0 ;
V_224:
F_100 ( V_378 ) ;
V_382:
F_110 ( V_287 ) ;
V_381:
F_107 ( V_212 ) ;
V_380:
return V_306 ;
}
static struct V_64 * F_236 ( struct V_2 * V_3 ,
struct V_300 * V_301 ,
int V_213 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_374 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_60 V_61 = { } ;
struct V_64 * V_56 ;
int V_306 ;
do {
V_306 = F_228 ( V_3 , V_301 , V_213 , V_6 , V_7 , V_374 ) ;
V_56 = V_301 -> V_65 ;
F_237 ( V_301 , V_213 , V_306 ) ;
if ( V_306 == 0 )
break;
if ( V_306 == - V_386 ) {
F_238 ( L_5
L_24 ,
F_90 ( V_3 ) -> V_62 -> V_96 ) ;
V_61 . V_66 = 1 ;
continue;
}
if ( V_306 == - V_70 ) {
V_61 . V_66 = 1 ;
continue;
}
if ( V_306 == - V_128 ) {
V_61 . V_66 = 1 ;
continue;
}
if ( F_82 ( V_14 , V_306 , & V_61 ) )
continue;
V_56 = F_46 ( F_21 ( V_14 ,
V_306 , & V_61 ) ) ;
} while ( V_61 . V_66 );
return V_56 ;
}
static int F_239 ( struct V_2 * V_2 , struct V_316 * V_350 ,
struct V_387 * V_388 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_389 ,
struct V_1 * V_378 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_390 V_391 = {
. V_245 = F_98 ( V_2 ) ,
. V_392 = V_6 ,
. V_14 = V_14 ,
. V_242 = V_14 -> V_15 ,
. V_7 = V_389 ,
} ;
struct V_393 V_56 = {
. V_388 = V_388 ,
. V_7 = V_378 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_394 ] ,
. V_314 = & V_391 ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
unsigned long V_105 = V_152 ;
T_5 V_183 ;
bool V_395 ;
int V_306 ;
V_391 . V_242 = F_6 ( V_14 , V_389 ) ;
if ( V_389 )
V_391 . V_242 = F_6 ( V_14 , V_378 ) ;
F_86 ( V_388 ) ;
V_395 = ( V_6 -> V_247 & V_396 ) ? true : false ;
V_183 = V_395 ? V_185 : V_71 ;
if ( F_240 ( & V_391 . V_251 , V_2 , V_183 ) ) {
} else if ( V_395 && V_65 != NULL ) {
struct V_397 V_398 = {
. V_399 = V_57 -> V_400 ,
. V_401 = V_57 -> V_402 ,
} ;
if ( ! F_241 ( V_65 ) )
return - V_403 ;
if ( F_242 ( & V_391 . V_251 , V_65 , V_185 ,
& V_398 ) == - V_35 )
return - V_403 ;
} else
F_130 ( & V_391 . V_251 , & V_404 ) ;
V_306 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_391 . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_306 == 0 && V_65 != NULL )
F_38 ( V_14 , V_105 ) ;
return V_306 ;
}
static int F_232 ( struct V_2 * V_2 , struct V_316 * V_350 ,
struct V_387 * V_388 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_389 ,
struct V_1 * V_378 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_239 ( V_2 , V_350 , V_388 , V_6 , V_65 , V_389 , V_378 ) ;
F_243 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_67 :
if ( ! ( V_6 -> V_247 & V_396 ) ) {
F_244 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_62 -> V_96 ) ;
}
if ( V_65 && ! ( V_65 -> V_65 & V_185 ) ) {
V_8 = - V_403 ;
if ( V_6 -> V_247 & V_405 )
V_8 = - V_29 ;
goto V_129;
}
}
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static void F_245 ( void * V_156 )
{
struct V_406 * V_154 = V_156 ;
struct V_211 * V_212 = V_154 -> V_65 -> V_226 ;
struct V_253 * V_254 = V_154 -> V_65 -> V_2 -> V_407 ;
if ( V_154 -> V_408 )
F_246 ( V_154 -> V_65 -> V_2 ) ;
F_106 ( V_154 -> V_65 ) ;
F_105 ( V_154 -> V_391 . V_203 ) ;
F_107 ( V_212 ) ;
F_108 ( V_254 ) ;
F_101 ( V_154 ) ;
}
static void F_247 ( struct V_117 * V_118 , void * V_156 )
{
struct V_406 * V_154 = V_156 ;
struct V_64 * V_65 = V_154 -> V_65 ;
struct V_13 * V_14 = F_90 ( V_154 -> V_2 ) ;
T_8 * V_409 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_63 ( V_118 , & V_154 -> V_56 . V_159 ) )
return;
F_248 ( V_65 , & V_154 -> V_391 , & V_154 -> V_56 , V_118 -> V_147 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
V_409 = & V_154 -> V_56 . V_251 ;
if ( V_154 -> V_391 . V_183 == 0 && V_154 -> V_408 )
F_249 ( V_65 -> V_2 ,
V_154 -> V_410 ) ;
F_38 ( V_14 , V_154 -> V_105 ) ;
break;
case - V_69 :
case - V_74 :
case - V_92 :
case - V_70 :
case - V_73 :
if ( ! F_140 ( & V_154 -> V_391 . V_251 ,
& V_65 -> V_271 ) ) {
F_60 ( V_118 ) ;
goto V_411;
}
if ( V_154 -> V_391 . V_183 == 0 )
break;
default:
if ( F_250 ( V_118 , V_14 , V_65 , NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
goto V_411;
}
}
F_131 ( V_65 , V_409 , V_154 -> V_391 . V_183 ) ;
V_411:
F_145 ( V_154 -> V_391 . V_203 ) ;
F_152 ( V_154 -> V_2 , V_154 -> V_56 . V_388 ) ;
F_8 ( L_30 , V_34 , V_118 -> V_147 ) ;
}
static void F_251 ( struct V_117 * V_118 , void * V_156 )
{
struct V_406 * V_154 = V_156 ;
struct V_64 * V_65 = V_154 -> V_65 ;
struct V_2 * V_2 = V_154 -> V_2 ;
bool V_412 , V_413 , V_414 ;
int V_415 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_185 ( V_154 -> V_391 . V_203 , V_118 ) != 0 )
goto V_322;
V_118 -> V_326 . V_311 = & V_312 [ V_416 ] ;
F_35 ( & V_65 -> V_226 -> V_276 ) ;
V_414 = F_32 ( V_263 , & V_65 -> V_213 ) ;
V_412 = F_32 ( V_259 , & V_65 -> V_213 ) ;
V_413 = F_32 ( V_261 , & V_65 -> V_213 ) ;
F_130 ( & V_154 -> V_391 . V_251 , & V_65 -> V_271 ) ;
V_154 -> V_391 . V_183 = 0 ;
if ( V_65 -> V_264 == 0 ) {
if ( V_65 -> V_260 == 0 )
V_415 |= V_412 ;
else if ( V_412 )
V_154 -> V_391 . V_183 |= V_71 ;
if ( V_65 -> V_262 == 0 )
V_415 |= V_413 ;
else if ( V_413 )
V_154 -> V_391 . V_183 |= V_185 ;
} else if ( V_414 )
V_154 -> V_391 . V_183 |= V_71 | V_185 ;
if ( V_154 -> V_391 . V_183 == 0 )
V_415 |= V_414 ;
if ( ! F_241 ( V_65 ) )
V_415 = 0 ;
F_37 ( & V_65 -> V_226 -> V_276 ) ;
if ( ! V_415 ) {
goto V_323;
}
if ( V_154 -> V_391 . V_183 == 0 ) {
V_118 -> V_326 . V_311 = & V_312 [ V_417 ] ;
if ( V_154 -> V_408 &&
F_252 ( V_2 , & V_154 -> V_410 , V_118 ) ) {
F_145 ( V_154 -> V_391 . V_203 ) ;
goto V_322;
}
}
V_154 -> V_391 . V_229 =
F_83 ( F_90 ( V_2 ) ,
V_154 -> V_391 . V_183 , 0 ) ;
F_86 ( V_154 -> V_56 . V_388 ) ;
V_154 -> V_105 = V_152 ;
if ( F_66 ( F_90 ( V_2 ) ,
& V_154 -> V_391 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) != 0 )
F_145 ( V_154 -> V_391 . V_203 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_323:
V_118 -> V_334 = NULL ;
V_322:
F_63 ( V_118 , & V_154 -> V_56 . V_159 ) ;
}
static bool F_253 ( struct V_2 * V_2 )
{
if ( ! F_254 ( V_2 ) )
return false ;
return F_255 ( V_2 ) ;
}
int F_256 ( struct V_64 * V_65 , T_6 V_215 , int V_418 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
struct V_406 * V_154 ;
struct V_211 * V_212 = V_65 -> V_226 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_417 ] ,
. V_316 = V_65 -> V_226 -> V_290 ,
} ;
struct V_162 V_317 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_419 ,
. V_319 = V_320 ,
. V_213 = V_321 ,
} ;
int V_306 = - V_124 ;
F_257 ( V_14 -> V_62 , V_420 ,
& V_317 . V_164 , & V_161 ) ;
V_154 = F_91 ( sizeof( * V_154 ) , V_215 ) ;
if ( V_154 == NULL )
goto V_129;
F_40 ( & V_154 -> V_391 . V_158 , & V_154 -> V_56 . V_159 , 1 ) ;
V_154 -> V_2 = V_65 -> V_2 ;
V_154 -> V_65 = V_65 ;
V_154 -> V_391 . V_245 = F_98 ( V_65 -> V_2 ) ;
V_218 = V_14 -> V_62 -> V_166 -> V_218 ;
V_154 -> V_391 . V_203 = V_218 ( & V_65 -> V_226 -> V_223 , V_215 ) ;
if ( F_45 ( V_154 -> V_391 . V_203 ) )
goto V_421;
V_154 -> V_391 . V_183 = 0 ;
V_154 -> V_391 . V_242 = V_14 -> V_422 ;
V_154 -> V_56 . V_388 = & V_154 -> V_388 ;
V_154 -> V_56 . V_203 = V_154 -> V_391 . V_203 ;
V_154 -> V_56 . V_14 = V_14 ;
V_154 -> V_408 = F_253 ( V_65 -> V_2 ) ;
F_93 ( V_154 -> V_2 -> V_407 ) ;
V_161 . V_314 = & V_154 -> V_391 ;
V_161 . V_315 = & V_154 -> V_56 ;
V_317 . V_168 = V_154 ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_306 = 0 ;
if ( V_418 )
V_306 = F_113 ( V_118 ) ;
F_75 ( V_118 ) ;
return V_306 ;
V_421:
F_101 ( V_154 ) ;
V_129:
F_106 ( V_65 ) ;
F_107 ( V_212 ) ;
return V_306 ;
}
static struct V_2 *
F_258 ( struct V_2 * V_3 , struct V_300 * V_301 ,
int V_228 , struct V_5 * V_423 , int * V_374 )
{
struct V_64 * V_65 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_301 -> V_4 , V_423 , & V_17 ) ;
V_65 = F_236 ( V_3 , V_301 , V_228 , V_423 , V_7 , V_374 ) ;
F_4 ( V_7 ) ;
if ( F_45 ( V_65 ) )
return F_259 ( V_65 ) ;
return V_65 -> V_2 ;
}
static void F_260 ( struct V_300 * V_301 , int V_424 )
{
if ( V_301 -> V_65 == NULL )
return;
if ( V_424 )
F_261 ( V_301 -> V_65 , V_301 -> V_256 ) ;
else
F_165 ( V_301 -> V_65 , V_301 -> V_256 ) ;
}
static int F_262 ( struct V_13 * V_14 , struct V_425 * V_426 )
{
struct V_427 args = {
. V_426 = V_426 ,
} ;
struct V_428 V_56 = {} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_429 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
int V_306 ;
V_306 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_306 == 0 ) {
switch ( V_14 -> V_62 -> V_430 ) {
case 0 :
V_56 . V_15 [ 1 ] &= V_431 ;
V_56 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_56 . V_15 [ 2 ] &= V_432 ;
break;
case 2 :
V_56 . V_15 [ 2 ] &= V_433 ;
}
memcpy ( V_14 -> V_15 , V_56 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_93 &= ~ ( V_434 | V_435 |
V_436 | V_437 |
V_438 | V_439 | V_440 |
V_441 | V_442 |
V_443 | V_444 |
V_9 ) ;
if ( V_56 . V_15 [ 0 ] & V_445 &&
V_56 . V_446 & V_447 )
V_14 -> V_93 |= V_434 ;
if ( V_56 . V_448 != 0 )
V_14 -> V_93 |= V_435 ;
if ( V_56 . V_449 != 0 )
V_14 -> V_93 |= V_436 ;
if ( V_56 . V_15 [ 0 ] & V_45 )
V_14 -> V_93 |= V_437 ;
if ( V_56 . V_15 [ 1 ] & V_450 )
V_14 -> V_93 |= V_438 ;
if ( V_56 . V_15 [ 1 ] & V_451 )
V_14 -> V_93 |= V_439 ;
if ( V_56 . V_15 [ 1 ] & V_452 )
V_14 -> V_93 |= V_440 ;
if ( V_56 . V_15 [ 1 ] & V_453 )
V_14 -> V_93 |= V_441 ;
if ( V_56 . V_15 [ 1 ] & V_365 )
V_14 -> V_93 |= V_442 ;
if ( V_56 . V_15 [ 1 ] & V_454 )
V_14 -> V_93 |= V_443 ;
if ( V_56 . V_15 [ 1 ] & V_368 )
V_14 -> V_93 |= V_444 ;
#ifdef F_263
if ( V_56 . V_15 [ 2 ] & V_455 )
V_14 -> V_93 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_56 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_455 ;
memcpy ( V_14 -> V_422 , V_56 . V_15 , sizeof( V_14 -> V_422 ) ) ;
V_14 -> V_422 [ 0 ] &= V_456 | V_457 ;
V_14 -> V_422 [ 1 ] &= V_454 | V_368 ;
V_14 -> V_422 [ 2 ] = 0 ;
V_14 -> V_446 = V_56 . V_446 ;
V_14 -> V_458 = V_56 . V_458 ;
}
return V_306 ;
}
int F_264 ( struct V_13 * V_14 , struct V_425 * V_426 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_262 ( V_14 , V_426 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_265 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_460 )
{
T_1 V_242 [ 3 ] ;
struct V_461 args = {
. V_242 = V_242 ,
} ;
struct V_462 V_56 = {
. V_14 = V_14 ,
. V_388 = V_460 -> V_388 ,
. V_245 = V_426 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_463 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
V_242 [ 0 ] = V_244 [ 0 ] ;
V_242 [ 1 ] = V_244 [ 1 ] ;
V_242 [ 2 ] = V_244 [ 2 ] & ~ V_455 ;
F_86 ( V_460 -> V_388 ) ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_266 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_460 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_265 ( V_14 , V_426 , V_460 ) ;
F_267 ( V_14 , V_426 , V_460 -> V_388 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_129;
default:
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static int F_268 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_460 , T_4 V_99 )
{
struct V_464 V_465 = {
. V_466 = V_99 ,
} ;
struct V_467 * V_468 ;
int V_51 ;
V_468 = F_269 ( & V_465 , V_14 -> V_90 ) ;
if ( F_45 ( V_468 ) ) {
V_51 = - V_29 ;
goto V_129;
}
V_51 = F_266 ( V_14 , V_426 , V_460 ) ;
V_129:
return V_51 ;
}
static int F_270 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_460 )
{
static const T_4 V_469 [] = {
V_104 ,
V_103 ,
V_470 ,
V_471 ,
V_472 ,
} ;
int V_306 = - V_24 ;
T_9 V_473 ;
if ( V_14 -> V_474 . V_475 > 0 ) {
for ( V_473 = 0 ; V_473 < V_14 -> V_474 . V_475 ; V_473 ++ ) {
V_306 = F_268 ( V_14 , V_426 , V_460 ,
V_14 -> V_474 . V_476 [ V_473 ] ) ;
if ( V_306 == - V_22 || V_306 == - V_29 )
continue;
break;
}
} else {
for ( V_473 = 0 ; V_473 < F_271 ( V_469 ) ; V_473 ++ ) {
V_306 = F_268 ( V_14 , V_426 , V_460 ,
V_469 [ V_473 ] ) ;
if ( V_306 == - V_22 || V_306 == - V_29 )
continue;
break;
}
}
if ( V_306 == - V_29 )
V_306 = - V_24 ;
return V_306 ;
}
static int F_272 ( struct V_13 * V_14 ,
struct V_425 * V_426 , struct V_459 * V_460 )
{
int V_477 = V_14 -> V_62 -> V_430 ;
return V_478 [ V_477 ] -> F_273 ( V_14 , V_426 , V_460 ) ;
}
int F_274 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_460 ,
bool V_479 )
{
int V_306 = 0 ;
if ( ! V_479 )
V_306 = F_266 ( V_14 , V_426 , V_460 ) ;
if ( V_479 || V_306 == V_22 )
V_306 = F_272 ( V_14 , V_426 , V_460 ) ;
if ( V_306 == 0 )
V_306 = F_264 ( V_14 , V_426 ) ;
if ( V_306 == 0 )
V_306 = F_275 ( V_14 , V_426 , V_460 ) ;
return F_7 ( V_306 ) ;
}
static int F_276 ( struct V_13 * V_14 , struct V_425 * V_480 ,
struct V_459 * V_460 )
{
int error ;
struct V_387 * V_388 = V_460 -> V_388 ;
struct V_1 * V_7 = NULL ;
error = F_264 ( V_14 , V_480 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_92 ( V_14 , V_379 ) ;
if ( F_45 ( V_7 ) )
return F_74 ( V_7 ) ;
error = F_196 ( V_14 , V_480 , V_388 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_224;
}
if ( V_388 -> V_297 & V_481 &&
! F_277 ( & V_14 -> V_482 , & V_388 -> V_482 ) )
memcpy ( & V_14 -> V_482 , & V_388 -> V_482 , sizeof( V_14 -> V_482 ) ) ;
V_224:
F_100 ( V_7 ) ;
return error ;
}
static int F_278 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_483 * V_241 , struct V_387 * V_388 ,
struct V_425 * V_426 )
{
int V_306 = - V_124 ;
struct V_484 * V_484 = NULL ;
struct V_485 * V_486 = NULL ;
V_484 = F_279 ( V_379 ) ;
if ( V_484 == NULL )
goto V_129;
V_486 = F_280 ( sizeof( struct V_485 ) , V_379 ) ;
if ( V_486 == NULL )
goto V_129;
V_306 = F_281 ( V_90 , V_3 , V_241 , V_486 , V_484 ) ;
if ( V_306 != 0 )
goto V_129;
if ( F_277 ( & F_90 ( V_3 ) -> V_482 , & V_486 -> V_388 . V_482 ) ) {
F_8 ( L_34
L_35 , V_34 , V_241 -> V_241 ) ;
V_306 = - V_76 ;
goto V_129;
}
F_282 ( & V_486 -> V_388 ) ;
memcpy ( V_388 , & V_486 -> V_388 , sizeof( struct V_387 ) ) ;
memset ( V_426 , 0 , sizeof( struct V_425 ) ) ;
V_129:
if ( V_484 )
F_283 ( V_484 ) ;
F_101 ( V_486 ) ;
return V_306 ;
}
static int F_284 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_387 * V_388 , struct V_1 * V_7 )
{
struct V_487 args = {
. V_245 = V_426 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_488 V_56 = {
. V_388 = V_388 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_489 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
args . V_242 = F_6 ( V_14 , V_7 ) ;
F_86 ( V_388 ) ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_196 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_387 * V_388 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_284 ( V_14 , V_426 , V_388 , V_7 ) ;
F_285 ( V_14 , V_426 , V_388 , V_8 ) ;
V_8 = F_21 ( V_14 , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_286 ( struct V_4 * V_4 , struct V_387 * V_388 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_316 * V_350 = NULL ;
struct V_64 * V_65 = NULL ;
struct V_1 * V_7 = NULL ;
int V_306 ;
if ( F_287 ( V_2 ) &&
V_6 -> V_247 & V_396 &&
V_6 -> V_490 < F_288 ( V_2 ) )
F_289 ( V_2 ) ;
F_86 ( V_388 ) ;
if ( V_6 -> V_247 & V_405 )
V_6 -> V_247 &= ~ ( V_370 | V_491 ) ;
if ( ( V_6 -> V_247 & ~ ( V_492 | V_405 ) ) == 0 )
return 0 ;
if ( V_6 -> V_247 & V_492 ) {
struct V_300 * V_301 ;
V_301 = F_290 ( V_6 -> V_493 ) ;
if ( V_301 ) {
V_350 = V_301 -> V_350 ;
V_65 = V_301 -> V_65 ;
}
}
V_7 = F_92 ( F_90 ( V_2 ) , V_379 ) ;
if ( F_45 ( V_7 ) )
return F_74 ( V_7 ) ;
V_306 = F_232 ( V_2 , V_350 , V_388 , V_6 , V_65 , NULL , V_7 ) ;
if ( V_306 == 0 ) {
F_233 ( V_2 , V_6 , V_388 ) ;
F_234 ( V_2 , V_388 , V_7 ) ;
}
F_100 ( V_7 ) ;
return V_306 ;
}
static int F_291 ( struct V_54 * V_55 , struct V_2 * V_3 ,
const struct V_483 * V_241 , struct V_425 * V_426 ,
struct V_387 * V_388 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
int V_306 ;
struct V_494 args = {
. V_242 = V_14 -> V_15 ,
. V_495 = F_98 ( V_3 ) ,
. V_241 = V_241 ,
} ;
struct V_462 V_56 = {
. V_14 = V_14 ,
. V_388 = V_388 ,
. V_7 = V_7 ,
. V_245 = V_426 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_496 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
args . V_242 = F_6 ( V_14 , V_7 ) ;
F_86 ( V_388 ) ;
F_8 ( L_36 , V_241 -> V_241 ) ;
V_306 = F_76 ( V_55 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
F_8 ( L_37 , V_306 ) ;
return V_306 ;
}
static void F_292 ( struct V_387 * V_388 )
{
V_388 -> V_297 |= V_335 | V_497 |
V_498 | V_499 ;
V_388 -> V_256 = V_340 | V_500 | V_501 ;
V_388 -> V_502 = 2 ;
}
static int F_293 ( struct V_54 * * V_55 , struct V_2 * V_3 ,
struct V_483 * V_241 , struct V_425 * V_426 ,
struct V_387 * V_388 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
struct V_54 * V_90 = * V_55 ;
int V_8 ;
do {
V_8 = F_291 ( V_90 , V_3 , V_241 , V_426 , V_388 , V_7 ) ;
F_294 ( V_3 , V_241 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_302 ;
goto V_129;
case - V_76 :
V_8 = F_278 ( V_90 , V_3 , V_241 , V_388 , V_426 ) ;
if ( V_8 == - V_76 )
V_8 = F_21 ( F_90 ( V_3 ) , V_8 , & V_61 ) ;
goto V_129;
case - V_22 :
V_8 = - V_24 ;
if ( V_90 != * V_55 )
goto V_129;
V_90 = F_295 ( V_90 , V_3 , V_241 ) ;
if ( F_45 ( V_90 ) )
return F_74 ( V_90 ) ;
V_61 . V_66 = 1 ;
break;
default:
V_8 = F_21 ( F_90 ( V_3 ) , V_8 , & V_61 ) ;
}
} while ( V_61 . V_66 );
V_129:
if ( V_8 == 0 )
* V_55 = V_90 ;
else if ( V_90 != * V_55 )
F_296 ( V_90 ) ;
return V_8 ;
}
static int F_297 ( struct V_2 * V_3 , struct V_483 * V_241 ,
struct V_425 * V_426 , struct V_387 * V_388 ,
struct V_1 * V_7 )
{
int V_306 ;
struct V_54 * V_90 = F_298 ( V_3 ) ;
V_306 = F_293 ( & V_90 , V_3 , V_241 , V_426 , V_388 , V_7 ) ;
if ( V_90 != F_298 ( V_3 ) ) {
F_296 ( V_90 ) ;
F_292 ( V_388 ) ;
}
return V_306 ;
}
struct V_54 *
F_299 ( struct V_2 * V_3 , struct V_483 * V_241 ,
struct V_425 * V_426 , struct V_387 * V_388 )
{
struct V_54 * V_90 = F_298 ( V_3 ) ;
int V_306 ;
V_306 = F_293 ( & V_90 , V_3 , V_241 , V_426 , V_388 , NULL ) ;
if ( V_306 < 0 )
return F_46 ( V_306 ) ;
return ( V_90 == F_298 ( V_3 ) ) ? F_300 ( V_90 ) : V_90 ;
}
static int F_301 ( struct V_2 * V_2 , struct V_351 * V_503 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_504 args = {
. V_245 = F_98 ( V_2 ) ,
. V_242 = V_14 -> V_422 ,
} ;
struct V_505 V_56 = {
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_506 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_503 -> V_350 ,
} ;
int V_256 = V_503 -> V_353 ;
int V_306 = 0 ;
if ( V_256 & V_358 )
args . V_208 |= V_231 ;
if ( F_302 ( V_2 -> V_507 ) ) {
if ( V_256 & V_508 )
args . V_208 |= V_232 | V_233 | V_509 ;
if ( V_256 & V_356 )
args . V_208 |= V_510 ;
} else {
if ( V_256 & V_508 )
args . V_208 |= V_232 | V_233 ;
if ( V_256 & V_356 )
args . V_208 |= V_234 ;
}
V_56 . V_388 = F_303 () ;
if ( V_56 . V_388 == NULL )
return - V_124 ;
V_306 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( ! V_306 ) {
F_193 ( V_503 , V_56 . V_208 ) ;
F_152 ( V_2 , V_56 . V_388 ) ;
}
F_304 ( V_56 . V_388 ) ;
return V_306 ;
}
static int F_305 ( struct V_2 * V_2 , struct V_351 * V_503 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_301 ( V_2 , V_503 ) ;
F_306 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_307 ( struct V_2 * V_2 , struct V_484 * V_484 ,
unsigned int V_48 , unsigned int V_511 )
{
struct V_512 args = {
. V_245 = F_98 ( V_2 ) ,
. V_48 = V_48 ,
. V_511 = V_511 ,
. V_42 = & V_484 ,
} ;
struct V_513 V_56 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_514 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
return F_76 ( F_90 ( V_2 ) -> V_90 , F_90 ( V_2 ) , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_308 ( struct V_2 * V_2 , struct V_484 * V_484 ,
unsigned int V_48 , unsigned int V_511 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_307 ( V_2 , V_484 , V_48 , V_511 ) ;
F_309 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_310 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_213 )
{
struct V_1 V_17 , * V_389 = NULL ;
struct V_300 * V_301 ;
struct V_64 * V_65 ;
int V_374 = 0 ;
int V_306 = 0 ;
V_301 = F_311 ( V_4 , V_71 ) ;
if ( F_45 ( V_301 ) )
return F_74 ( V_301 ) ;
V_389 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_312 () ;
V_65 = F_236 ( V_3 , V_301 , V_213 , V_6 , V_389 , & V_374 ) ;
if ( F_45 ( V_65 ) ) {
V_306 = F_74 ( V_65 ) ;
goto V_129;
}
V_129:
F_4 ( V_389 ) ;
F_172 ( V_301 ) ;
return V_306 ;
}
static int F_313 ( struct V_2 * V_3 , struct V_483 * V_241 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_515 args = {
. V_245 = F_98 ( V_3 ) ,
. V_241 = * V_241 ,
} ;
struct V_516 V_56 = {
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_517 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
int V_306 ;
V_306 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_306 == 0 )
F_77 ( V_3 , & V_56 . V_170 ) ;
return V_306 ;
}
static int F_314 ( struct V_2 * V_3 , struct V_483 * V_241 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_313 ( V_3 , V_241 ) ;
F_315 ( V_3 , V_241 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_316 ( struct V_160 * V_161 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_515 * args = V_161 -> V_314 ;
struct V_516 * V_56 = V_161 -> V_315 ;
V_56 -> V_14 = V_14 ;
V_161 -> V_311 = & V_312 [ V_517 ] ;
F_40 ( & args -> V_158 , & V_56 -> V_159 , 1 ) ;
F_86 ( V_56 -> V_518 ) ;
}
static void F_317 ( struct V_117 * V_118 , struct V_519 * V_156 )
{
F_66 ( F_90 ( V_156 -> V_3 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_318 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_519 * V_156 = V_118 -> V_520 ;
struct V_516 * V_56 = & V_156 -> V_56 ;
if ( ! F_63 ( V_118 , & V_56 -> V_159 ) )
return 0 ;
if ( F_250 ( V_118 , V_56 -> V_14 , NULL ,
& V_156 -> V_50 ) == - V_128 )
return 0 ;
F_77 ( V_3 , & V_56 -> V_170 ) ;
return 1 ;
}
static void F_319 ( struct V_160 * V_161 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_521 * V_391 = V_161 -> V_314 ;
struct V_522 * V_56 = V_161 -> V_315 ;
V_161 -> V_311 = & V_312 [ V_523 ] ;
V_56 -> V_14 = V_14 ;
F_40 ( & V_391 -> V_158 , & V_56 -> V_159 , 1 ) ;
}
static void F_320 ( struct V_117 * V_118 , struct V_524 * V_156 )
{
F_66 ( F_90 ( V_156 -> V_525 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_321 ( struct V_117 * V_118 , struct V_2 * V_525 ,
struct V_2 * V_526 )
{
struct V_524 * V_156 = V_118 -> V_520 ;
struct V_522 * V_56 = & V_156 -> V_56 ;
if ( ! F_63 ( V_118 , & V_56 -> V_159 ) )
return 0 ;
if ( F_250 ( V_118 , V_56 -> V_14 , NULL , & V_156 -> V_50 ) == - V_128 )
return 0 ;
F_77 ( V_525 , & V_56 -> V_527 ) ;
F_77 ( V_526 , & V_56 -> V_528 ) ;
return 1 ;
}
static int F_322 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_483 * V_241 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_529 V_391 = {
. V_245 = F_98 ( V_2 ) ,
. V_495 = F_98 ( V_3 ) ,
. V_241 = V_241 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_530 V_56 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_531 ] ,
. V_314 = & V_391 ,
. V_315 = & V_56 ,
} ;
int V_306 = - V_124 ;
V_56 . V_388 = F_303 () ;
if ( V_56 . V_388 == NULL )
goto V_129;
V_56 . V_7 = F_92 ( V_14 , V_379 ) ;
if ( F_45 ( V_56 . V_7 ) ) {
V_306 = F_74 ( V_56 . V_7 ) ;
goto V_129;
}
V_391 . V_242 = F_6 ( V_14 , V_56 . V_7 ) ;
V_306 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_391 . V_158 , & V_56 . V_159 , 1 ) ;
if ( ! V_306 ) {
F_77 ( V_3 , & V_56 . V_170 ) ;
V_306 = F_323 ( V_2 , V_56 . V_388 ) ;
if ( ! V_306 )
F_234 ( V_2 , V_56 . V_388 , V_56 . V_7 ) ;
}
F_100 ( V_56 . V_7 ) ;
V_129:
F_304 ( V_56 . V_388 ) ;
return V_306 ;
}
static int F_324 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_483 * V_241 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( F_90 ( V_2 ) ,
F_322 ( V_2 , V_3 , V_241 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static struct V_532 * F_325 ( struct V_2 * V_3 ,
struct V_483 * V_241 , struct V_5 * V_6 , T_1 V_533 )
{
struct V_532 * V_156 ;
V_156 = F_91 ( sizeof( * V_156 ) , V_379 ) ;
if ( V_156 != NULL ) {
struct V_13 * V_14 = F_90 ( V_3 ) ;
V_156 -> V_7 = F_92 ( V_14 , V_379 ) ;
if ( F_45 ( V_156 -> V_7 ) )
goto V_310;
V_156 -> V_161 . V_311 = & V_312 [ V_534 ] ;
V_156 -> V_161 . V_314 = & V_156 -> V_391 ;
V_156 -> V_161 . V_315 = & V_156 -> V_56 ;
V_156 -> V_391 . V_495 = F_98 ( V_3 ) ;
V_156 -> V_391 . V_14 = V_14 ;
V_156 -> V_391 . V_241 = V_241 ;
V_156 -> V_391 . V_214 = V_6 ;
V_156 -> V_391 . V_533 = V_533 ;
V_156 -> V_391 . V_242 = F_6 ( V_14 , V_156 -> V_7 ) ;
V_156 -> V_56 . V_14 = V_14 ;
V_156 -> V_56 . V_245 = & V_156 -> V_245 ;
V_156 -> V_56 . V_388 = & V_156 -> V_388 ;
V_156 -> V_56 . V_7 = V_156 -> V_7 ;
F_86 ( V_156 -> V_56 . V_388 ) ;
}
return V_156 ;
V_310:
F_101 ( V_156 ) ;
return NULL ;
}
static int F_326 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_532 * V_156 )
{
int V_306 = F_76 ( F_90 ( V_3 ) -> V_90 , F_90 ( V_3 ) , & V_156 -> V_161 ,
& V_156 -> V_391 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
if ( V_306 == 0 ) {
F_77 ( V_3 , & V_156 -> V_56 . V_535 ) ;
V_306 = F_327 ( V_4 , V_156 -> V_56 . V_245 , V_156 -> V_56 . V_388 , V_156 -> V_56 . V_7 ) ;
}
return V_306 ;
}
static void F_328 ( struct V_532 * V_156 )
{
F_100 ( V_156 -> V_7 ) ;
F_101 ( V_156 ) ;
}
static int F_329 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_484 * V_484 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_532 * V_156 ;
int V_306 = - V_536 ;
if ( V_12 > V_537 )
goto V_129;
V_306 = - V_124 ;
V_156 = F_325 ( V_3 , & V_4 -> V_11 , V_6 , V_538 ) ;
if ( V_156 == NULL )
goto V_129;
V_156 -> V_161 . V_311 = & V_312 [ V_539 ] ;
V_156 -> V_391 . V_249 . V_540 . V_42 = & V_484 ;
V_156 -> V_391 . V_249 . V_540 . V_12 = V_12 ;
V_156 -> V_391 . V_7 = V_7 ;
V_306 = F_326 ( V_3 , V_4 , V_156 ) ;
F_328 ( V_156 ) ;
V_129:
return V_306 ;
}
static int F_330 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_484 * V_484 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_329 ( V_3 , V_4 , V_484 , V_12 , V_6 , V_7 ) ;
F_331 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_332 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_532 * V_156 ;
int V_306 = - V_124 ;
V_156 = F_325 ( V_3 , & V_4 -> V_11 , V_6 , V_541 ) ;
if ( V_156 == NULL )
goto V_129;
V_156 -> V_391 . V_7 = V_7 ;
V_306 = F_326 ( V_3 , V_4 , V_156 ) ;
F_328 ( V_156 ) ;
V_129:
return V_306 ;
}
static int F_333 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_312 () ;
do {
V_8 = F_332 ( V_3 , V_4 , V_6 , V_7 ) ;
F_334 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_335 ( struct V_4 * V_4 , struct V_316 * V_350 ,
T_2 V_36 , struct V_484 * * V_42 , unsigned int V_49 , int V_542 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_245 = F_98 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_242 = F_90 ( F_14 ( V_4 ) ) -> V_15 ,
. V_542 = V_542 ,
} ;
struct V_543 V_56 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_544 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
int V_306 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_78 ( V_3 ) -> V_545 , V_4 , & args ) ;
V_56 . V_48 = args . V_48 ;
V_306 = F_76 ( F_90 ( V_3 ) -> V_90 , F_90 ( V_3 ) , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_306 >= 0 ) {
memcpy ( F_78 ( V_3 ) -> V_545 , V_56 . V_37 . V_156 , V_546 ) ;
V_306 += args . V_48 ;
}
F_336 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_306 ) ;
return V_306 ;
}
static int F_337 ( struct V_4 * V_4 , struct V_316 * V_350 ,
T_2 V_36 , struct V_484 * * V_42 , unsigned int V_49 , int V_542 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_335 ( V_4 , V_350 , V_36 ,
V_42 , V_49 , V_542 ) ;
F_338 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_21 ( F_90 ( F_14 ( V_4 ) ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_339 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_547 )
{
struct V_532 * V_156 ;
int V_256 = V_6 -> V_10 ;
int V_306 = - V_124 ;
V_156 = F_325 ( V_3 , & V_4 -> V_11 , V_6 , V_548 ) ;
if ( V_156 == NULL )
goto V_129;
if ( F_340 ( V_256 ) )
V_156 -> V_391 . V_533 = V_549 ;
else if ( F_341 ( V_256 ) ) {
V_156 -> V_391 . V_533 = V_550 ;
V_156 -> V_391 . V_249 . V_551 . V_552 = F_342 ( V_547 ) ;
V_156 -> V_391 . V_249 . V_551 . V_553 = F_343 ( V_547 ) ;
}
else if ( F_344 ( V_256 ) ) {
V_156 -> V_391 . V_533 = V_554 ;
V_156 -> V_391 . V_249 . V_551 . V_552 = F_342 ( V_547 ) ;
V_156 -> V_391 . V_249 . V_551 . V_553 = F_343 ( V_547 ) ;
} else if ( ! F_345 ( V_256 ) ) {
V_306 = - V_27 ;
goto V_310;
}
V_156 -> V_391 . V_7 = V_7 ;
V_306 = F_326 ( V_3 , V_4 , V_156 ) ;
V_310:
F_328 ( V_156 ) ;
V_129:
return V_306 ;
}
static int F_346 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_547 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_312 () ;
do {
V_8 = F_339 ( V_3 , V_4 , V_6 , V_7 , V_547 ) ;
F_347 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_348 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_555 * V_556 )
{
struct V_557 args = {
. V_245 = V_426 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_558 V_56 = {
. V_556 = V_556 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_559 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
F_86 ( V_556 -> V_388 ) ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_349 ( struct V_13 * V_14 , struct V_425 * V_426 , struct V_555 * V_556 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_348 ( V_14 , V_426 , V_556 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_350 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_560 )
{
struct V_561 args = {
. V_245 = V_426 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_562 V_56 = {
. V_560 = V_560 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_563 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_275 ( struct V_13 * V_14 , struct V_425 * V_426 , struct V_459 * V_560 )
{
struct V_60 V_61 = { } ;
unsigned long V_564 = V_152 ;
int V_8 ;
do {
V_8 = F_350 ( V_14 , V_426 , V_560 ) ;
F_351 ( V_14 , V_426 , V_560 -> V_388 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_62 * V_63 = V_14 -> V_62 ;
F_35 ( & V_63 -> V_106 ) ;
V_63 -> V_565 = V_560 -> V_566 * V_87 ;
V_63 -> V_107 = V_564 ;
F_37 ( & V_63 -> V_106 ) ;
break;
}
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_352 ( struct V_13 * V_14 , struct V_425 * V_426 , struct V_459 * V_560 )
{
int error ;
F_86 ( V_560 -> V_388 ) ;
error = F_275 ( V_14 , V_426 , V_560 ) ;
if ( error == 0 ) {
V_14 -> V_567 = V_560 -> V_568 ;
F_353 ( V_14 , V_426 , V_560 -> V_569 ) ;
}
return error ;
}
static int F_354 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_570 * V_571 )
{
struct V_572 args = {
. V_245 = V_426 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_573 V_56 = {
. V_571 = V_571 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_574 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
if ( ( args . V_242 [ 0 ] & V_575 [ 0 ] ) == 0 ) {
memset ( V_571 , 0 , sizeof( * V_571 ) ) ;
return 0 ;
}
F_86 ( V_571 -> V_388 ) ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_355 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_570 * V_571 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_354 ( V_14 , V_426 , V_571 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
int F_356 ( T_8 * V_251 ,
const struct V_300 * V_301 ,
const struct V_576 * V_577 ,
T_5 V_183 )
{
const struct V_397 * V_398 = NULL ;
if ( V_577 != NULL )
V_398 = & V_577 -> V_398 ;
return F_242 ( V_251 , V_301 -> V_65 , V_183 , V_398 ) ;
}
static bool F_357 ( T_8 * V_251 ,
const struct V_300 * V_301 ,
const struct V_576 * V_577 ,
T_5 V_183 )
{
T_8 V_578 ;
if ( F_356 ( & V_578 , V_301 , V_577 , V_183 ) == - V_35 )
return true ;
return F_140 ( V_251 , & V_578 ) ;
}
static bool F_358 ( int V_8 )
{
switch ( V_8 ) {
case - V_68 :
case - V_69 :
case - V_70 :
case - V_74 :
case - V_92 :
case - V_67 :
case - V_73 :
return true ;
}
return false ;
}
void F_359 ( struct V_579 * V_580 )
{
F_336 ( V_580 -> V_2 ) ;
}
static int F_360 ( struct V_117 * V_118 , struct V_579 * V_580 )
{
struct V_13 * V_14 = F_90 ( V_580 -> V_2 ) ;
F_361 ( V_580 , V_118 -> V_147 ) ;
if ( F_250 ( V_118 , V_14 ,
V_580 -> args . V_581 -> V_65 ,
NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return - V_128 ;
}
F_359 ( V_580 ) ;
if ( V_118 -> V_147 > 0 )
F_38 ( V_14 , V_580 -> V_105 ) ;
return 0 ;
}
static bool F_362 ( struct V_117 * V_118 ,
struct V_582 * args )
{
if ( ! F_358 ( V_118 -> V_147 ) ||
F_357 ( & args -> V_251 ,
args -> V_581 ,
args -> V_583 ,
V_71 ) )
return false ;
F_60 ( V_118 ) ;
return true ;
}
static int F_363 ( struct V_117 * V_118 , struct V_579 * V_580 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_63 ( V_118 , & V_580 -> V_56 . V_159 ) )
return - V_128 ;
if ( F_362 ( V_118 , & V_580 -> args ) )
return - V_128 ;
return V_580 -> V_584 ? V_580 -> V_584 ( V_118 , V_580 ) :
F_360 ( V_118 , V_580 ) ;
}
static void F_364 ( struct V_579 * V_580 ,
struct V_160 * V_161 )
{
V_580 -> V_105 = V_152 ;
V_580 -> V_584 = F_360 ;
V_161 -> V_311 = & V_312 [ V_585 ] ;
F_40 ( & V_580 -> args . V_158 , & V_580 -> V_56 . V_159 , 0 ) ;
}
static int F_365 ( struct V_117 * V_118 ,
struct V_579 * V_580 )
{
if ( F_66 ( F_90 ( V_580 -> V_2 ) ,
& V_580 -> args . V_158 ,
& V_580 -> V_56 . V_159 ,
V_118 ) )
return 0 ;
if ( F_356 ( & V_580 -> args . V_251 , V_580 -> args . V_581 ,
V_580 -> args . V_583 ,
V_580 -> V_586 -> V_587 ) == - V_35 )
return - V_35 ;
if ( F_366 ( F_32 ( V_588 , & V_580 -> args . V_581 -> V_213 ) ) )
return - V_35 ;
return 0 ;
}
static int F_367 ( struct V_117 * V_118 ,
struct V_579 * V_580 )
{
struct V_2 * V_2 = V_580 -> V_2 ;
F_368 ( V_580 , V_118 -> V_147 ) ;
if ( F_250 ( V_118 , F_90 ( V_2 ) ,
V_580 -> args . V_581 -> V_65 ,
NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return - V_128 ;
}
if ( V_118 -> V_147 >= 0 ) {
F_38 ( F_90 ( V_2 ) , V_580 -> V_105 ) ;
F_369 ( V_580 ) ;
}
return 0 ;
}
static bool F_370 ( struct V_117 * V_118 ,
struct V_582 * args )
{
if ( ! F_358 ( V_118 -> V_147 ) ||
F_357 ( & args -> V_251 ,
args -> V_581 ,
args -> V_583 ,
V_185 ) )
return false ;
F_60 ( V_118 ) ;
return true ;
}
static int F_371 ( struct V_117 * V_118 , struct V_579 * V_580 )
{
if ( ! F_63 ( V_118 , & V_580 -> V_56 . V_159 ) )
return - V_128 ;
if ( F_370 ( V_118 , & V_580 -> args ) )
return - V_128 ;
return V_580 -> V_584 ? V_580 -> V_584 ( V_118 , V_580 ) :
F_367 ( V_118 , V_580 ) ;
}
static
bool F_372 ( struct V_579 * V_580 )
{
if ( V_580 -> V_589 != NULL || V_580 -> V_590 != NULL )
return false ;
return F_22 ( V_580 -> V_2 , V_71 ) == 0 ;
}
static void F_373 ( struct V_579 * V_580 ,
struct V_160 * V_161 )
{
struct V_13 * V_14 = F_90 ( V_580 -> V_2 ) ;
if ( ! F_372 ( V_580 ) ) {
V_580 -> args . V_242 = NULL ;
V_580 -> V_56 . V_388 = NULL ;
} else
V_580 -> args . V_242 = V_14 -> V_422 ;
if ( ! V_580 -> V_584 )
V_580 -> V_584 = F_367 ;
V_580 -> V_56 . V_14 = V_14 ;
V_580 -> V_105 = V_152 ;
V_161 -> V_311 = & V_312 [ V_591 ] ;
F_40 ( & V_580 -> args . V_158 , & V_580 -> V_56 . V_159 , 1 ) ;
}
static void F_374 ( struct V_117 * V_118 , struct V_592 * V_156 )
{
F_66 ( F_90 ( V_156 -> V_2 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_375 ( struct V_117 * V_118 , struct V_592 * V_156 )
{
struct V_2 * V_2 = V_156 -> V_2 ;
F_376 ( V_156 , V_118 -> V_147 ) ;
if ( F_250 ( V_118 , F_90 ( V_2 ) ,
NULL , NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_377 ( struct V_117 * V_118 , struct V_592 * V_156 )
{
if ( ! F_63 ( V_118 , & V_156 -> V_56 . V_159 ) )
return - V_128 ;
return V_156 -> V_593 ( V_118 , V_156 ) ;
}
static void F_378 ( struct V_592 * V_156 , struct V_160 * V_161 )
{
struct V_13 * V_14 = F_90 ( V_156 -> V_2 ) ;
if ( V_156 -> V_593 == NULL )
V_156 -> V_593 = F_375 ;
V_156 -> V_56 . V_14 = V_14 ;
V_161 -> V_311 = & V_312 [ V_594 ] ;
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
}
static void F_379 ( void * V_154 )
{
struct V_595 * V_156 = V_154 ;
struct V_62 * V_63 = V_156 -> V_90 ;
if ( F_380 ( & V_63 -> V_596 ) > 1 )
F_381 ( V_63 ) ;
F_382 ( V_63 ) ;
F_101 ( V_156 ) ;
}
static void F_383 ( struct V_117 * V_118 , void * V_154 )
{
struct V_595 * V_156 = V_154 ;
struct V_62 * V_63 = V_156 -> V_90 ;
unsigned long V_105 = V_156 -> V_105 ;
F_384 ( V_63 , V_118 -> V_147 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
break;
case - V_77 :
F_27 ( V_63 ) ;
break;
default:
if ( F_32 ( V_597 , & V_63 -> V_598 ) == 0 )
return;
if ( V_118 -> V_147 != V_599 ) {
F_25 ( V_63 ) ;
return;
}
F_385 ( V_63 ) ;
}
F_34 ( V_63 , V_105 ) ;
}
static int F_386 ( struct V_62 * V_63 , struct V_316 * V_350 , unsigned V_600 )
{
struct V_160 V_161 = {
. V_311 = & V_312 [ V_601 ] ,
. V_314 = V_63 ,
. V_316 = V_350 ,
} ;
struct V_595 * V_156 ;
if ( V_600 == 0 )
return 0 ;
if ( ! F_387 ( & V_63 -> V_596 ) )
return - V_35 ;
V_156 = F_280 ( sizeof( * V_156 ) , V_303 ) ;
if ( V_156 == NULL )
return - V_124 ;
V_156 -> V_90 = V_63 ;
V_156 -> V_105 = V_152 ;
return F_388 ( V_63 -> V_100 , & V_161 , V_602 ,
& V_603 , V_156 ) ;
}
static int F_389 ( struct V_62 * V_63 , struct V_316 * V_350 )
{
struct V_160 V_161 = {
. V_311 = & V_312 [ V_601 ] ,
. V_314 = V_63 ,
. V_316 = V_350 ,
} ;
unsigned long V_564 = V_152 ;
int V_306 ;
V_306 = F_390 ( V_63 -> V_100 , & V_161 , V_602 ) ;
if ( V_306 < 0 )
return V_306 ;
F_34 ( V_63 , V_564 ) ;
return 0 ;
}
static inline int F_391 ( struct V_13 * V_14 )
{
return V_14 -> V_93 & V_434 ;
}
static int F_392 ( const void * V_604 , T_9 V_605 ,
struct V_484 * * V_42 , unsigned int * V_48 )
{
struct V_484 * V_606 , * * V_607 ;
int V_608 = 0 ;
T_9 V_12 ;
V_607 = V_42 ;
do {
V_12 = F_393 ( T_9 , V_609 , V_605 ) ;
V_606 = F_279 ( V_379 ) ;
if ( V_606 == NULL )
goto V_610;
memcpy ( F_394 ( V_606 ) , V_604 , V_12 ) ;
V_604 += V_12 ;
V_605 -= V_12 ;
* V_42 ++ = V_606 ;
V_608 ++ ;
} while ( V_605 != 0 );
return V_608 ;
V_610:
for(; V_608 > 0 ; V_608 -- )
F_283 ( V_607 [ V_608 - 1 ] ) ;
return - V_124 ;
}
static void F_395 ( struct V_2 * V_2 , struct V_611 * V_612 )
{
struct V_171 * V_172 = F_78 ( V_2 ) ;
F_35 ( & V_2 -> V_173 ) ;
F_101 ( V_172 -> V_613 ) ;
V_172 -> V_613 = V_612 ;
F_37 ( & V_2 -> V_173 ) ;
}
static void F_396 ( struct V_2 * V_2 )
{
F_395 ( V_2 , NULL ) ;
}
static inline T_11 F_397 ( struct V_2 * V_2 , char * V_604 , T_9 V_605 )
{
struct V_171 * V_172 = F_78 ( V_2 ) ;
struct V_611 * V_612 ;
int V_51 = - V_302 ;
F_35 ( & V_2 -> V_173 ) ;
V_612 = V_172 -> V_613 ;
if ( V_612 == NULL )
goto V_129;
if ( V_604 == NULL )
goto V_614;
if ( V_612 -> V_615 == 0 )
goto V_129;
V_51 = - V_616 ;
if ( V_612 -> V_12 > V_605 )
goto V_129;
memcpy ( V_604 , V_612 -> V_156 , V_612 -> V_12 ) ;
V_614:
V_51 = V_612 -> V_12 ;
V_129:
F_37 ( & V_2 -> V_173 ) ;
return V_51 ;
}
static void F_398 ( struct V_2 * V_2 , struct V_484 * * V_42 , T_9 V_48 , T_9 V_617 )
{
struct V_611 * V_612 ;
T_9 V_605 = sizeof( * V_612 ) + V_617 ;
if ( V_605 <= V_609 ) {
V_612 = F_280 ( V_605 , V_379 ) ;
if ( V_612 == NULL )
goto V_129;
V_612 -> V_615 = 1 ;
F_399 ( V_612 -> V_156 , V_42 , V_48 , V_617 ) ;
} else {
V_612 = F_280 ( sizeof( * V_612 ) , V_379 ) ;
if ( V_612 == NULL )
goto V_129;
V_612 -> V_615 = 0 ;
}
V_612 -> V_12 = V_617 ;
V_129:
F_395 ( V_2 , V_612 ) ;
}
static T_11 F_400 ( struct V_2 * V_2 , void * V_604 , T_9 V_605 )
{
struct V_484 * V_42 [ V_618 ] = { NULL , } ;
struct V_619 args = {
. V_245 = F_98 ( V_2 ) ,
. V_620 = V_42 ,
. V_617 = V_605 ,
} ;
struct V_621 V_56 = {
. V_617 = V_605 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_622 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
unsigned int V_623 = F_401 ( V_605 , V_609 ) ;
int V_51 = - V_124 , V_473 ;
if ( V_623 == 0 )
V_623 = 1 ;
if ( V_623 > F_271 ( V_42 ) )
return - V_616 ;
for ( V_473 = 0 ; V_473 < V_623 ; V_473 ++ ) {
V_42 [ V_473 ] = F_279 ( V_379 ) ;
if ( ! V_42 [ V_473 ] )
goto V_310;
}
V_56 . V_624 = F_279 ( V_379 ) ;
if ( ! V_56 . V_624 )
goto V_310;
args . V_617 = V_623 * V_609 ;
args . V_625 = 0 ;
F_8 ( L_40 ,
V_34 , V_604 , V_605 , V_623 , args . V_617 ) ;
V_51 = F_76 ( F_90 ( V_2 ) -> V_90 , F_90 ( V_2 ) ,
& V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_51 )
goto V_310;
if ( V_56 . V_626 & V_627 ) {
if ( V_604 == NULL )
goto V_628;
V_51 = - V_616 ;
goto V_310;
}
F_398 ( V_2 , V_42 , V_56 . V_629 , V_56 . V_617 ) ;
if ( V_604 ) {
if ( V_56 . V_617 > V_605 ) {
V_51 = - V_616 ;
goto V_310;
}
F_399 ( V_604 , V_42 , V_56 . V_629 , V_56 . V_617 ) ;
}
V_628:
V_51 = V_56 . V_617 ;
V_310:
for ( V_473 = 0 ; V_473 < V_623 ; V_473 ++ )
if ( V_42 [ V_473 ] )
F_283 ( V_42 [ V_473 ] ) ;
if ( V_56 . V_624 )
F_283 ( V_56 . V_624 ) ;
return V_51 ;
}
static T_11 F_402 ( struct V_2 * V_2 , void * V_604 , T_9 V_605 )
{
struct V_60 V_61 = { } ;
T_11 V_51 ;
do {
V_51 = F_400 ( V_2 , V_604 , V_605 ) ;
F_403 ( V_2 , V_51 ) ;
if ( V_51 >= 0 )
break;
V_51 = F_21 ( F_90 ( V_2 ) , V_51 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_51 ;
}
static T_11 F_404 ( struct V_2 * V_2 , void * V_604 , T_9 V_605 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
int V_51 ;
if ( ! F_391 ( V_14 ) )
return - V_630 ;
V_51 = F_405 ( V_14 , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_78 ( V_2 ) -> V_174 & V_631 )
F_406 ( V_2 ) ;
V_51 = F_397 ( V_2 , V_604 , V_605 ) ;
if ( V_51 != - V_302 )
return V_51 ;
return F_402 ( V_2 , V_604 , V_605 ) ;
}
static int F_407 ( struct V_2 * V_2 , const void * V_604 , T_9 V_605 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_484 * V_42 [ V_618 ] ;
struct V_632 V_391 = {
. V_245 = F_98 ( V_2 ) ,
. V_620 = V_42 ,
. V_617 = V_605 ,
} ;
struct V_633 V_56 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_634 ] ,
. V_314 = & V_391 ,
. V_315 = & V_56 ,
} ;
unsigned int V_623 = F_401 ( V_605 , V_609 ) ;
int V_51 , V_473 ;
if ( ! F_391 ( V_14 ) )
return - V_630 ;
if ( V_623 > F_271 ( V_42 ) )
return - V_616 ;
V_473 = F_392 ( V_604 , V_605 , V_391 . V_620 , & V_391 . V_625 ) ;
if ( V_473 < 0 )
return V_473 ;
F_23 ( V_2 ) ;
V_51 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_391 . V_158 , & V_56 . V_159 , 1 ) ;
for (; V_473 > 0 ; V_473 -- )
F_408 ( V_42 [ V_473 - 1 ] ) ;
F_35 ( & V_2 -> V_173 ) ;
F_78 ( V_2 ) -> V_174 |= V_175 ;
F_37 ( & V_2 -> V_173 ) ;
F_409 ( V_2 ) ;
F_406 ( V_2 ) ;
return V_51 ;
}
static int F_410 ( struct V_2 * V_2 , const void * V_604 , T_9 V_605 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_407 ( V_2 , V_604 , V_605 ) ;
F_411 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_412 ( struct V_2 * V_2 , void * V_604 ,
T_9 V_605 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_387 V_388 ;
struct V_1 V_7 = { 0 , 0 , V_605 , V_604 } ;
T_1 V_242 [ 3 ] = { 0 , 0 , V_455 } ;
struct V_487 V_391 = {
. V_245 = F_98 ( V_2 ) ,
. V_242 = V_242 ,
} ;
struct V_488 V_56 = {
. V_388 = & V_388 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_489 ] ,
. V_314 = & V_391 ,
. V_315 = & V_56 ,
} ;
int V_51 ;
F_86 ( & V_388 ) ;
V_51 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_391 . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( V_388 . V_297 & V_635 ) )
return - V_302 ;
if ( V_605 < V_7 . V_12 )
return - V_616 ;
return 0 ;
}
static int F_413 ( struct V_2 * V_2 , void * V_604 ,
T_9 V_605 )
{
struct V_60 V_61 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_630 ;
do {
V_8 = F_412 ( V_2 , V_604 , V_605 ) ;
F_414 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_415 ( struct V_2 * V_2 ,
struct V_1 * V_389 ,
struct V_387 * V_388 ,
struct V_1 * V_378 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
const T_1 V_242 [ 3 ] = { 0 , 0 , V_455 } ;
struct V_390 V_391 = {
. V_245 = F_98 ( V_2 ) ,
. V_392 = & V_6 ,
. V_14 = V_14 ,
. V_242 = V_242 ,
. V_7 = V_389 ,
} ;
struct V_393 V_56 = {
. V_388 = V_388 ,
. V_7 = V_378 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_394 ] ,
. V_314 = & V_391 ,
. V_315 = & V_56 ,
} ;
int V_306 ;
F_130 ( & V_391 . V_251 , & V_404 ) ;
V_306 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_391 . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_306 )
F_8 ( L_41 , V_34 , V_306 ) ;
return V_306 ;
}
static int F_416 ( struct V_2 * V_2 ,
struct V_1 * V_389 ,
struct V_387 * V_388 ,
struct V_1 * V_378 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_415 ( V_2 , V_389 ,
V_388 , V_378 ) ;
F_417 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_418 ( struct V_4 * V_4 , const void * V_604 , T_9 V_605 )
{
struct V_1 V_389 , * V_378 = NULL ;
struct V_387 V_388 ;
struct V_316 * V_350 ;
struct V_2 * V_2 = F_14 ( V_4 ) ;
int V_306 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_630 ;
F_86 ( & V_388 ) ;
V_389 . V_636 = 0 ;
V_389 . V_637 = 0 ;
V_389 . V_7 = ( char * ) V_604 ;
V_389 . V_12 = V_605 ;
V_350 = F_419 () ;
if ( F_45 ( V_350 ) )
return F_74 ( V_350 ) ;
V_378 = F_92 ( F_90 ( V_2 ) , V_379 ) ;
if ( F_45 ( V_378 ) ) {
V_306 = - F_74 ( V_378 ) ;
goto V_129;
}
V_306 = F_416 ( V_2 , & V_389 , & V_388 , V_378 ) ;
if ( V_306 == 0 )
F_234 ( V_2 , & V_388 , V_378 ) ;
F_100 ( V_378 ) ;
V_129:
F_214 ( V_350 ) ;
return V_306 ;
}
static int
F_250 ( struct V_117 * V_118 , const struct V_13 * V_14 ,
struct V_64 * V_65 , long * V_50 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
if ( V_118 -> V_147 >= 0 )
return 0 ;
switch( V_118 -> V_147 ) {
case - V_68 :
case - V_69 :
case - V_70 :
case - V_67 :
if ( V_65 == NULL )
break;
if ( F_24 ( V_14 , V_65 ) < 0 )
goto V_638;
goto V_72;
case - V_73 :
if ( V_65 != NULL ) {
if ( F_24 ( V_14 , V_65 ) < 0 )
goto V_638;
}
case - V_74 :
case - V_75 :
F_25 ( V_63 ) ;
goto V_72;
case - V_76 :
if ( F_26 ( V_14 ) < 0 )
goto V_638;
goto V_72;
case - V_77 :
F_27 ( V_63 ) ;
goto V_72;
#if F_28 ( V_78 )
case - V_79 :
case - V_80 :
case - V_81 :
case - V_83 :
case - V_82 :
case - V_84 :
case - V_85 :
F_8 ( L_42 , V_34 ,
V_118 -> V_147 ) ;
F_29 ( V_63 -> V_86 , V_118 -> V_147 ) ;
goto V_72;
#endif
case - V_89 :
F_420 ( V_14 , V_639 ) ;
F_62 ( V_118 , F_16 ( V_50 ) ) ;
goto V_640;
case - V_88 :
F_62 ( V_118 , V_52 ) ;
case - V_91 :
case - V_92 :
goto V_640;
}
V_118 -> V_147 = F_7 ( V_118 -> V_147 ) ;
return 0 ;
V_638:
V_118 -> V_147 = - V_35 ;
return 0 ;
V_72:
F_49 ( & V_63 -> V_641 , V_118 , NULL ) ;
if ( F_32 ( V_642 , & V_63 -> V_643 ) == 0 )
F_421 ( & V_63 -> V_641 , V_118 ) ;
if ( F_32 ( V_97 , & V_14 -> V_98 ) )
goto V_638;
V_640:
V_118 -> V_147 = 0 ;
return - V_128 ;
}
static void F_422 ( const struct V_62 * V_63 ,
T_12 * V_644 )
{
T_3 V_248 [ 2 ] ;
if ( F_32 ( V_645 , & V_63 -> V_643 ) ) {
V_248 [ 0 ] = 0 ;
V_248 [ 1 ] = F_423 ( V_646 + 1 ) ;
} else {
struct V_647 * V_648 = F_424 ( V_63 -> V_649 , V_650 ) ;
V_248 [ 0 ] = F_423 ( V_648 -> V_651 . V_652 ) ;
V_248 [ 1 ] = F_423 ( V_648 -> V_651 . V_653 ) ;
}
memcpy ( V_644 -> V_156 , V_248 , sizeof( V_644 -> V_156 ) ) ;
}
static int
F_425 ( struct V_62 * V_63 )
{
int V_654 ;
T_9 V_12 ;
char * V_655 ;
bool V_656 = false ;
if ( V_63 -> V_657 != NULL )
return 0 ;
V_66:
F_138 () ;
V_12 = 10 + strlen ( V_63 -> V_658 ) + 1 +
strlen ( F_426 ( V_63 -> V_100 , V_659 ) ) +
1 +
strlen ( F_426 ( V_63 -> V_100 , V_660 ) ) +
1 ;
F_141 () ;
if ( V_12 > V_661 + 1 )
return - V_27 ;
V_655 = F_280 ( V_12 , V_379 ) ;
if ( ! V_655 )
return - V_124 ;
F_138 () ;
V_654 = F_427 ( V_655 , V_12 , L_43 ,
V_63 -> V_658 ,
F_426 ( V_63 -> V_100 , V_659 ) ,
F_426 ( V_63 -> V_100 , V_660 ) ) ;
F_141 () ;
if ( V_654 >= V_12 ) {
F_101 ( V_655 ) ;
if ( V_656 )
return - V_27 ;
V_656 = true ;
goto V_66;
}
V_63 -> V_657 = V_655 ;
return 0 ;
}
static int
F_428 ( struct V_62 * V_63 )
{
int V_654 ;
T_9 V_12 ;
char * V_655 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_662 ) + 1 +
strlen ( V_63 -> V_100 -> V_663 ) + 1 ;
if ( V_12 > V_661 + 1 )
return - V_27 ;
V_655 = F_280 ( V_12 , V_379 ) ;
if ( ! V_655 )
return - V_124 ;
V_654 = F_427 ( V_655 , V_12 , L_44 ,
V_63 -> V_664 -> V_665 , V_63 -> V_430 ,
V_662 ,
V_63 -> V_100 -> V_663 ) ;
if ( V_654 >= V_12 ) {
F_101 ( V_655 ) ;
return - V_27 ;
}
V_63 -> V_657 = V_655 ;
return 0 ;
}
static int
F_429 ( struct V_62 * V_63 )
{
int V_654 ;
T_9 V_12 ;
char * V_655 ;
if ( V_63 -> V_657 != NULL )
return 0 ;
if ( V_662 [ 0 ] != '\0' )
return F_428 ( V_63 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_63 -> V_100 -> V_663 ) + 1 ;
if ( V_12 > V_661 + 1 )
return - V_27 ;
V_655 = F_280 ( V_12 , V_379 ) ;
if ( ! V_655 )
return - V_124 ;
V_654 = F_427 ( V_655 , V_12 , L_45 ,
V_63 -> V_664 -> V_665 , V_63 -> V_430 ,
V_63 -> V_100 -> V_663 ) ;
if ( V_654 >= V_12 ) {
F_101 ( V_655 ) ;
return - V_27 ;
}
V_63 -> V_657 = V_655 ;
return 0 ;
}
static unsigned int
F_430 ( const struct V_62 * V_63 , char * V_604 , T_9 V_12 )
{
if ( strchr ( V_63 -> V_658 , ':' ) != NULL )
return F_427 ( V_604 , V_12 , L_46 ) ;
else
return F_427 ( V_604 , V_12 , L_47 ) ;
}
static void F_431 ( struct V_117 * V_118 , void * V_154 )
{
struct V_666 * V_667 = V_154 ;
if ( V_118 -> V_147 == 0 )
V_667 -> V_668 = F_210 ( V_118 -> V_669 -> V_670 ) ;
}
int F_432 ( struct V_62 * V_63 , T_1 V_671 ,
unsigned short V_672 , struct V_316 * V_350 ,
struct V_673 * V_56 )
{
T_12 V_674 ;
struct V_666 V_675 = {
. V_674 = & V_674 ,
. V_676 = V_671 ,
. V_677 = V_63 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_678 ] ,
. V_314 = & V_675 ,
. V_315 = V_56 ,
. V_316 = V_350 ,
} ;
struct V_117 * V_118 ;
struct V_162 V_317 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_679 ,
. V_168 = & V_675 ,
. V_213 = V_602 ,
} ;
int V_306 ;
F_422 ( V_63 , & V_674 ) ;
if ( F_32 ( V_680 , & V_63 -> V_681 ) )
V_306 = F_429 ( V_63 ) ;
else
V_306 = F_425 ( V_63 ) ;
if ( V_306 )
goto V_129;
V_675 . V_682 =
F_430 ( V_63 ,
V_675 . V_683 ,
sizeof( V_675 . V_683 ) ) ;
V_675 . V_684 = F_427 ( V_675 . V_685 ,
sizeof( V_675 . V_685 ) , L_48 ,
V_63 -> V_658 , V_672 >> 8 , V_672 & 255 ) ;
F_8 ( L_49 ,
V_63 -> V_100 -> V_101 -> V_686 -> V_687 ,
V_63 -> V_657 ) ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) ) {
V_306 = F_74 ( V_118 ) ;
goto V_129;
}
V_306 = V_118 -> V_147 ;
if ( V_675 . V_668 ) {
V_63 -> V_688 = F_433 ( V_675 . V_668 ) ;
F_214 ( V_675 . V_668 ) ;
}
F_75 ( V_118 ) ;
V_129:
F_434 ( V_63 , V_306 ) ;
F_8 ( L_50 , V_306 ) ;
return V_306 ;
}
int F_435 ( struct V_62 * V_63 ,
struct V_673 * V_391 ,
struct V_316 * V_350 )
{
struct V_160 V_161 = {
. V_311 = & V_312 [ V_689 ] ,
. V_314 = V_391 ,
. V_316 = V_350 ,
} ;
int V_306 ;
F_8 ( L_51 ,
V_63 -> V_100 -> V_101 -> V_686 -> V_687 ,
V_63 -> V_236 ) ;
V_306 = F_390 ( V_63 -> V_100 , & V_161 , V_602 ) ;
F_436 ( V_63 , V_306 ) ;
F_8 ( L_52 , V_306 ) ;
return V_306 ;
}
static void F_437 ( struct V_117 * V_118 , void * V_154 )
{
struct V_690 * V_156 = V_154 ;
if ( ! F_63 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
F_438 ( & V_156 -> args , & V_156 -> V_56 , V_118 -> V_147 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( V_156 -> V_56 . V_14 , V_156 -> V_105 ) ;
case - V_69 :
case - V_68 :
case - V_70 :
case - V_92 :
case - V_74 :
case - V_73 :
V_118 -> V_147 = 0 ;
if ( V_156 -> V_408 )
F_249 ( V_156 -> V_2 , V_156 -> V_410 ) ;
break;
default:
if ( F_250 ( V_118 , V_156 -> V_56 . V_14 ,
NULL , NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return;
}
}
V_156 -> V_294 = V_118 -> V_147 ;
}
static void F_439 ( void * V_154 )
{
struct V_690 * V_156 = V_154 ;
struct V_2 * V_2 = V_156 -> V_2 ;
if ( V_2 ) {
if ( V_156 -> V_408 )
F_246 ( V_2 ) ;
F_440 ( V_2 ) ;
}
F_101 ( V_154 ) ;
}
static void F_441 ( struct V_117 * V_118 , void * V_156 )
{
struct V_690 * V_691 ;
V_691 = (struct V_690 * ) V_156 ;
if ( V_691 -> V_408 &&
F_252 ( V_691 -> V_2 , & V_691 -> V_410 , V_118 ) )
return;
F_66 ( V_691 -> V_56 . V_14 ,
& V_691 -> args . V_158 ,
& V_691 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_442 ( struct V_2 * V_2 , struct V_316 * V_350 , const T_8 * V_251 , int V_692 )
{
struct V_690 * V_156 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_693 ] ,
. V_316 = V_350 ,
} ;
struct V_162 V_317 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_694 ,
. V_213 = V_321 ,
} ;
int V_306 = 0 ;
V_156 = F_91 ( sizeof( * V_156 ) , V_303 ) ;
if ( V_156 == NULL )
return - V_124 ;
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_156 -> args . V_426 = & V_156 -> V_245 ;
V_156 -> args . V_251 = & V_156 -> V_251 ;
V_156 -> args . V_242 = V_14 -> V_422 ;
F_186 ( & V_156 -> V_245 , F_98 ( V_2 ) ) ;
F_130 ( & V_156 -> V_251 , V_251 ) ;
V_156 -> V_56 . V_388 = & V_156 -> V_388 ;
V_156 -> V_56 . V_14 = V_14 ;
F_86 ( V_156 -> V_56 . V_388 ) ;
V_156 -> V_105 = V_152 ;
V_156 -> V_294 = 0 ;
V_156 -> V_2 = F_443 ( V_2 ) ;
if ( V_156 -> V_2 )
V_156 -> V_408 = F_253 ( V_2 ) ;
V_317 . V_168 = V_156 ;
V_161 . V_314 = & V_156 -> args ;
V_161 . V_315 = & V_156 -> V_56 ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
if ( ! V_692 )
goto V_129;
V_306 = F_112 ( V_118 ) ;
if ( V_306 != 0 )
goto V_129;
V_306 = V_156 -> V_294 ;
if ( V_306 == 0 )
F_444 ( V_2 , & V_156 -> V_388 ) ;
else
F_152 ( V_2 , & V_156 -> V_388 ) ;
V_129:
F_75 ( V_118 ) ;
return V_306 ;
}
int F_445 ( struct V_2 * V_2 , struct V_316 * V_350 , const T_8 * V_251 , int V_692 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_442 ( V_2 , V_350 , V_251 , V_692 ) ;
F_446 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_74 :
case - V_73 :
case 0 :
return 0 ;
}
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static unsigned long
F_447 ( unsigned long V_50 )
{
F_19 ( V_50 ) ;
V_50 <<= 1 ;
if ( V_50 > V_695 )
return V_695 ;
return V_50 ;
}
static int F_448 ( struct V_64 * V_65 , int V_696 , struct V_697 * V_698 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_699 V_391 = {
. V_245 = F_98 ( V_2 ) ,
. V_700 = V_698 ,
} ;
struct V_701 V_56 = {
. V_702 = V_698 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_703 ] ,
. V_314 = & V_391 ,
. V_315 = & V_56 ,
. V_316 = V_65 -> V_226 -> V_290 ,
} ;
struct V_281 * V_282 ;
int V_306 ;
V_391 . V_704 . V_235 = V_63 -> V_236 ;
V_306 = F_449 ( V_65 , V_698 ) ;
if ( V_306 != 0 )
goto V_129;
V_282 = V_698 -> V_705 . V_706 . V_226 ;
V_391 . V_704 . V_237 = V_282 -> V_707 . V_240 ;
V_391 . V_704 . V_708 = V_14 -> V_708 ;
V_306 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_391 . V_158 , & V_56 . V_159 , 1 ) ;
switch ( V_306 ) {
case 0 :
V_698 -> V_709 = V_710 ;
break;
case - V_308 :
V_306 = 0 ;
}
V_698 -> V_711 -> V_712 ( V_698 ) ;
V_698 -> V_711 = NULL ;
V_129:
return V_306 ;
}
static int F_450 ( struct V_64 * V_65 , int V_696 , struct V_697 * V_698 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_448 ( V_65 , V_696 , V_698 ) ;
F_451 ( V_698 , V_65 , V_696 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_65 -> V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_452 ( struct V_2 * V_2 , struct V_697 * V_700 )
{
int V_56 = 0 ;
switch ( V_700 -> V_713 & ( V_714 | V_715 ) ) {
case V_714 :
V_56 = F_453 ( V_2 , V_700 ) ;
break;
case V_715 :
V_56 = F_454 ( V_2 , V_700 ) ;
break;
default:
F_455 () ;
}
return V_56 ;
}
static struct V_716 * F_456 ( struct V_697 * V_700 ,
struct V_300 * V_301 ,
struct V_281 * V_282 ,
struct V_217 * V_203 )
{
struct V_716 * V_41 ;
struct V_2 * V_2 = V_282 -> V_283 -> V_2 ;
V_41 = F_91 ( sizeof( * V_41 ) , V_303 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_391 . V_245 = F_98 ( V_2 ) ;
V_41 -> V_391 . V_700 = & V_41 -> V_700 ;
V_41 -> V_391 . V_203 = V_203 ;
V_41 -> V_56 . V_203 = V_203 ;
V_41 -> V_282 = V_282 ;
F_95 ( & V_282 -> V_717 ) ;
V_41 -> V_301 = F_160 ( V_301 ) ;
memcpy ( & V_41 -> V_700 , V_700 , sizeof( V_41 -> V_700 ) ) ;
V_41 -> V_14 = F_90 ( V_2 ) ;
return V_41 ;
}
static void F_457 ( void * V_156 )
{
struct V_716 * V_154 = V_156 ;
F_105 ( V_154 -> V_391 . V_203 ) ;
F_458 ( V_154 -> V_282 ) ;
F_172 ( V_154 -> V_301 ) ;
F_101 ( V_154 ) ;
}
static void F_459 ( struct V_117 * V_118 , void * V_156 )
{
struct V_716 * V_154 = V_156 ;
if ( ! F_63 ( V_118 , & V_154 -> V_56 . V_159 ) )
return;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( V_154 -> V_14 , V_154 -> V_105 ) ;
F_452 ( V_154 -> V_282 -> V_283 -> V_2 , & V_154 -> V_700 ) ;
if ( F_142 ( V_154 -> V_282 ,
& V_154 -> V_56 . V_251 ) )
break;
case - V_70 :
case - V_92 :
case - V_74 :
case - V_73 :
if ( ! F_140 ( & V_154 -> V_391 . V_251 ,
& V_154 -> V_282 -> V_285 ) )
F_60 ( V_118 ) ;
break;
default:
if ( F_250 ( V_118 , V_154 -> V_14 ,
NULL , NULL ) == - V_128 )
F_60 ( V_118 ) ;
}
F_145 ( V_154 -> V_391 . V_203 ) ;
}
static void F_460 ( struct V_117 * V_118 , void * V_156 )
{
struct V_716 * V_154 = V_156 ;
if ( F_185 ( V_154 -> V_391 . V_203 , V_118 ) != 0 )
goto V_322;
F_130 ( & V_154 -> V_391 . V_251 , & V_154 -> V_282 -> V_285 ) ;
if ( F_32 ( V_718 , & V_154 -> V_282 -> V_719 ) == 0 ) {
goto V_323;
}
V_154 -> V_105 = V_152 ;
if ( F_66 ( V_154 -> V_14 ,
& V_154 -> V_391 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) != 0 )
F_145 ( V_154 -> V_391 . V_203 ) ;
return;
V_323:
V_118 -> V_334 = NULL ;
V_322:
F_63 ( V_118 , & V_154 -> V_56 . V_159 ) ;
}
static struct V_117 * F_461 ( struct V_697 * V_700 ,
struct V_300 * V_301 ,
struct V_281 * V_282 ,
struct V_217 * V_203 )
{
struct V_716 * V_156 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_720 ] ,
. V_316 = V_301 -> V_350 ,
} ;
struct V_162 V_317 = {
. V_164 = F_298 ( V_282 -> V_283 -> V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_721 ,
. V_319 = V_320 ,
. V_213 = V_321 ,
} ;
F_257 ( F_90 ( V_282 -> V_283 -> V_2 ) -> V_62 ,
V_420 , & V_317 . V_164 , & V_161 ) ;
V_700 -> V_709 = V_710 ;
V_156 = F_456 ( V_700 , V_301 , V_282 , V_203 ) ;
if ( V_156 == NULL ) {
F_105 ( V_203 ) ;
return F_46 ( - V_124 ) ;
}
F_40 ( & V_156 -> V_391 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_161 . V_314 = & V_156 -> V_391 ;
V_161 . V_315 = & V_156 -> V_56 ;
V_317 . V_168 = V_156 ;
return F_73 ( & V_317 ) ;
}
static int F_462 ( struct V_64 * V_65 , int V_696 , struct V_697 * V_698 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_211 * V_212 = V_65 -> V_226 ;
struct V_171 * V_172 = F_78 ( V_2 ) ;
struct V_217 * V_203 ;
struct V_281 * V_282 ;
struct V_117 * V_118 ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
int V_306 = 0 ;
unsigned char V_713 = V_698 -> V_713 ;
V_306 = F_449 ( V_65 , V_698 ) ;
V_698 -> V_713 |= V_722 ;
F_463 ( & V_212 -> V_723 ) ;
F_464 ( & V_172 -> V_724 ) ;
if ( F_452 ( V_2 , V_698 ) == - V_302 ) {
F_465 ( & V_172 -> V_724 ) ;
F_466 ( & V_212 -> V_723 ) ;
goto V_129;
}
F_465 ( & V_172 -> V_724 ) ;
F_466 ( & V_212 -> V_723 ) ;
if ( V_306 != 0 )
goto V_129;
V_282 = V_698 -> V_705 . V_706 . V_226 ;
if ( F_32 ( V_718 , & V_282 -> V_719 ) == 0 )
goto V_129;
V_218 = F_90 ( V_2 ) -> V_62 -> V_166 -> V_218 ;
V_203 = V_218 ( & V_282 -> V_707 , V_379 ) ;
V_306 = - V_124 ;
if ( F_45 ( V_203 ) )
goto V_129;
V_118 = F_461 ( V_698 , F_290 ( V_698 -> V_725 ) , V_282 , V_203 ) ;
V_306 = F_74 ( V_118 ) ;
if ( F_45 ( V_118 ) )
goto V_129;
V_306 = F_112 ( V_118 ) ;
F_75 ( V_118 ) ;
V_129:
V_698 -> V_713 = V_713 ;
F_467 ( V_698 , V_65 , V_726 , V_306 ) ;
return V_306 ;
}
static struct V_727 * F_468 ( struct V_697 * V_700 ,
struct V_300 * V_301 , struct V_281 * V_282 ,
T_6 V_215 )
{
struct V_727 * V_41 ;
struct V_2 * V_2 = V_282 -> V_283 -> V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
V_41 = F_91 ( sizeof( * V_41 ) , V_215 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_391 . V_245 = F_98 ( V_2 ) ;
V_41 -> V_391 . V_700 = & V_41 -> V_700 ;
V_41 -> V_391 . V_728 = F_469 ( & V_282 -> V_283 -> V_226 -> V_223 , V_215 ) ;
if ( F_45 ( V_41 -> V_391 . V_728 ) )
goto V_310;
V_218 = V_14 -> V_62 -> V_166 -> V_218 ;
V_41 -> V_391 . V_729 = V_218 ( & V_282 -> V_707 , V_215 ) ;
if ( F_45 ( V_41 -> V_391 . V_729 ) )
goto V_730;
V_41 -> V_391 . V_704 . V_235 = V_14 -> V_62 -> V_236 ;
V_41 -> V_391 . V_704 . V_237 = V_282 -> V_707 . V_240 ;
V_41 -> V_391 . V_704 . V_708 = V_14 -> V_708 ;
V_41 -> V_56 . V_729 = V_41 -> V_391 . V_729 ;
V_41 -> V_282 = V_282 ;
V_41 -> V_14 = V_14 ;
F_95 ( & V_282 -> V_717 ) ;
V_41 -> V_301 = F_160 ( V_301 ) ;
F_470 ( V_700 -> V_725 ) ;
memcpy ( & V_41 -> V_700 , V_700 , sizeof( V_41 -> V_700 ) ) ;
return V_41 ;
V_730:
F_105 ( V_41 -> V_391 . V_728 ) ;
V_310:
F_101 ( V_41 ) ;
return NULL ;
}
static void F_471 ( struct V_117 * V_118 , void * V_154 )
{
struct V_727 * V_156 = V_154 ;
struct V_64 * V_65 = V_156 -> V_282 -> V_283 ;
F_8 ( L_29 , V_34 ) ;
if ( F_185 ( V_156 -> V_391 . V_729 , V_118 ) != 0 )
goto V_322;
if ( ! F_32 ( V_718 , & V_156 -> V_282 -> V_719 ) ) {
if ( F_185 ( V_156 -> V_391 . V_728 , V_118 ) != 0 ) {
goto V_731;
}
F_130 ( & V_156 -> V_391 . V_271 ,
& V_65 -> V_271 ) ;
V_156 -> V_391 . V_732 = 1 ;
V_156 -> V_56 . V_728 = V_156 -> V_391 . V_728 ;
} else {
V_156 -> V_391 . V_732 = 0 ;
F_130 ( & V_156 -> V_391 . V_733 ,
& V_156 -> V_282 -> V_285 ) ;
}
if ( ! F_241 ( V_65 ) ) {
V_156 -> V_294 = - V_403 ;
V_118 -> V_334 = NULL ;
goto V_734;
}
V_156 -> V_105 = V_152 ;
if ( F_66 ( V_156 -> V_14 ,
& V_156 -> V_391 . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) == 0 )
return;
V_734:
F_145 ( V_156 -> V_391 . V_728 ) ;
V_731:
F_145 ( V_156 -> V_391 . V_729 ) ;
V_322:
F_63 ( V_118 , & V_156 -> V_56 . V_159 ) ;
F_8 ( L_53 , V_34 , V_156 -> V_294 ) ;
}
static void F_472 ( struct V_117 * V_118 , void * V_154 )
{
struct V_727 * V_156 = V_154 ;
struct V_281 * V_282 = V_156 -> V_282 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_63 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
V_156 -> V_294 = V_118 -> V_147 ;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( F_90 ( F_14 ( V_156 -> V_301 -> V_4 ) ) ,
V_156 -> V_105 ) ;
if ( V_156 -> V_391 . V_735 ) {
V_156 -> V_700 . V_713 &= ~ ( V_736 | V_737 ) ;
if ( F_452 ( V_282 -> V_283 -> V_2 , & V_156 -> V_700 ) < 0 ) {
F_60 ( V_118 ) ;
break;
}
}
if ( V_156 -> V_391 . V_732 != 0 ) {
F_179 ( & V_282 -> V_707 , 0 ) ;
F_130 ( & V_282 -> V_285 , & V_156 -> V_56 . V_251 ) ;
F_127 ( V_718 , & V_282 -> V_719 ) ;
} else if ( ! F_142 ( V_282 , & V_156 -> V_56 . V_251 ) )
F_60 ( V_118 ) ;
break;
case - V_70 :
case - V_92 :
case - V_74 :
case - V_73 :
if ( V_156 -> V_391 . V_732 != 0 ) {
if ( ! F_140 ( & V_156 -> V_391 . V_271 ,
& V_282 -> V_283 -> V_271 ) )
F_60 ( V_118 ) ;
} else if ( ! F_140 ( & V_156 -> V_391 . V_733 ,
& V_282 -> V_285 ) )
F_60 ( V_118 ) ;
}
F_8 ( L_30 , V_34 , V_156 -> V_294 ) ;
}
static void F_473 ( void * V_154 )
{
struct V_727 * V_156 = V_154 ;
F_8 ( L_29 , V_34 ) ;
F_105 ( V_156 -> V_391 . V_728 ) ;
if ( V_156 -> V_309 != 0 ) {
struct V_117 * V_118 ;
V_118 = F_461 ( & V_156 -> V_700 , V_156 -> V_301 , V_156 -> V_282 ,
V_156 -> V_391 . V_729 ) ;
if ( ! F_45 ( V_118 ) )
F_474 ( V_118 ) ;
F_8 ( L_54 , V_34 ) ;
} else
F_105 ( V_156 -> V_391 . V_729 ) ;
F_458 ( V_156 -> V_282 ) ;
F_172 ( V_156 -> V_301 ) ;
F_475 ( V_156 -> V_700 . V_725 ) ;
F_101 ( V_156 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_476 ( struct V_13 * V_14 , struct V_281 * V_282 , int V_732 , int error )
{
switch ( error ) {
case - V_69 :
case - V_70 :
V_282 -> V_707 . V_213 &= ~ V_738 ;
if ( V_732 != 0 ||
F_32 ( V_718 , & V_282 -> V_719 ) != 0 )
F_24 ( V_14 , V_282 -> V_283 ) ;
break;
case - V_74 :
V_282 -> V_707 . V_213 &= ~ V_738 ;
case - V_73 :
F_25 ( V_14 -> V_62 ) ;
} ;
}
static int F_477 ( struct V_64 * V_65 , int V_696 , struct V_697 * V_700 , int V_739 )
{
struct V_727 * V_156 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_740 ] ,
. V_316 = V_65 -> V_226 -> V_290 ,
} ;
struct V_162 V_317 = {
. V_164 = F_298 ( V_65 -> V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_741 ,
. V_319 = V_320 ,
. V_213 = V_321 ,
} ;
int V_51 ;
F_8 ( L_29 , V_34 ) ;
V_156 = F_468 ( V_700 , F_290 ( V_700 -> V_725 ) ,
V_700 -> V_705 . V_706 . V_226 ,
V_739 == V_742 ? V_379 : V_303 ) ;
if ( V_156 == NULL )
return - V_124 ;
if ( F_478 ( V_696 ) )
V_156 -> V_391 . V_743 = 1 ;
F_40 ( & V_156 -> V_391 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_161 . V_314 = & V_156 -> V_391 ;
V_161 . V_315 = & V_156 -> V_56 ;
V_317 . V_168 = V_156 ;
if ( V_739 > V_742 ) {
if ( V_739 == V_744 )
V_156 -> V_391 . V_745 = V_744 ;
F_41 ( & V_156 -> V_391 . V_158 ) ;
} else
V_156 -> V_391 . V_735 = 1 ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_51 = F_112 ( V_118 ) ;
if ( V_51 == 0 ) {
V_51 = V_156 -> V_294 ;
if ( V_51 )
F_476 ( V_156 -> V_14 , V_156 -> V_282 ,
V_156 -> V_391 . V_732 , V_51 ) ;
} else
V_156 -> V_309 = 1 ;
F_75 ( V_118 ) ;
F_8 ( L_30 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_479 ( struct V_64 * V_65 , struct V_697 * V_698 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_32 ( V_272 , & V_65 -> V_213 ) != 0 )
return 0 ;
V_8 = F_477 ( V_65 , V_726 , V_698 , V_744 ) ;
F_480 ( V_698 , V_65 , V_726 , V_8 ) ;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_481 ( struct V_64 * V_65 , struct V_697 * V_698 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
V_8 = F_449 ( V_65 , V_698 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_746 ) {
F_127 ( V_747 , & V_698 -> V_705 . V_706 . V_226 -> V_719 ) ;
return 0 ;
}
do {
if ( F_32 ( V_272 , & V_65 -> V_213 ) != 0 )
return 0 ;
V_8 = F_477 ( V_65 , V_726 , V_698 , V_748 ) ;
F_482 ( V_698 , V_65 , V_726 , V_8 ) ;
switch ( V_8 ) {
default:
goto V_129;
case - V_88 :
case - V_89 :
F_21 ( V_14 , V_8 , & V_61 ) ;
V_8 = 0 ;
}
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static int F_483 ( struct V_64 * V_65 )
{
int V_306 , V_51 = - V_70 ;
struct V_281 * V_282 ;
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
F_159 (lsp, &state->lock_states, ls_locks) {
if ( F_32 ( V_718 , & V_282 -> V_719 ) ) {
struct V_316 * V_350 = V_282 -> V_283 -> V_226 -> V_290 ;
V_306 = F_211 ( V_14 ,
& V_282 -> V_285 ,
V_350 ) ;
F_484 ( V_65 , V_282 , V_306 ) ;
if ( V_306 != V_363 ) {
if ( V_306 != - V_70 )
F_213 ( V_14 ,
& V_282 -> V_285 ,
V_350 ) ;
F_129 ( V_718 , & V_282 -> V_719 ) ;
V_51 = V_306 ;
}
}
} ;
return V_51 ;
}
static int F_485 ( struct V_64 * V_65 , struct V_697 * V_698 )
{
int V_306 = V_363 ;
if ( F_32 ( V_749 , & V_65 -> V_213 ) )
V_306 = F_483 ( V_65 ) ;
if ( V_306 != V_363 )
V_306 = F_481 ( V_65 , V_698 ) ;
return V_306 ;
}
static int F_486 ( struct V_64 * V_65 , int V_696 , struct V_697 * V_698 )
{
struct V_171 * V_172 = F_78 ( V_65 -> V_2 ) ;
unsigned char V_713 = V_698 -> V_713 ;
int V_306 = - V_750 ;
if ( ( V_713 & V_714 ) &&
! F_32 ( V_373 , & V_65 -> V_213 ) )
goto V_129;
V_306 = F_449 ( V_65 , V_698 ) ;
if ( V_306 != 0 )
goto V_129;
V_698 -> V_713 |= V_737 ;
V_306 = F_452 ( V_65 -> V_2 , V_698 ) ;
if ( V_306 < 0 )
goto V_129;
F_464 ( & V_172 -> V_724 ) ;
if ( F_32 ( V_272 , & V_65 -> V_213 ) ) {
V_698 -> V_713 = V_713 & ~ V_736 ;
V_306 = F_452 ( V_65 -> V_2 , V_698 ) ;
F_465 ( & V_172 -> V_724 ) ;
goto V_129;
}
F_465 ( & V_172 -> V_724 ) ;
V_306 = F_477 ( V_65 , V_696 , V_698 , V_742 ) ;
V_129:
V_698 -> V_713 = V_713 ;
return V_306 ;
}
static int F_487 ( struct V_64 * V_65 , int V_696 , struct V_697 * V_698 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_486 ( V_65 , V_696 , V_698 ) ;
F_488 ( V_698 , V_65 , V_696 , V_8 ) ;
if ( V_8 == - V_308 )
V_8 = - V_128 ;
V_8 = F_21 ( F_90 ( V_65 -> V_2 ) ,
V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_489 ( struct V_751 * V_752 , int V_696 , struct V_697 * V_698 )
{
struct V_300 * V_301 ;
struct V_64 * V_65 ;
unsigned long V_50 = V_753 ;
int V_306 ;
V_301 = F_290 ( V_752 ) ;
V_65 = V_301 -> V_65 ;
if ( V_698 -> V_754 < 0 || V_698 -> V_755 < 0 )
return - V_27 ;
if ( F_490 ( V_696 ) ) {
if ( V_65 != NULL )
return F_450 ( V_65 , V_756 , V_698 ) ;
return 0 ;
}
if ( ! ( F_491 ( V_696 ) || F_478 ( V_696 ) ) )
return - V_27 ;
if ( V_698 -> V_709 == V_710 ) {
if ( V_65 != NULL )
return F_462 ( V_65 , V_696 , V_698 ) ;
return 0 ;
}
if ( V_65 == NULL )
return - V_750 ;
switch ( V_698 -> V_709 ) {
case V_757 :
if ( ! ( V_752 -> V_758 & V_71 ) )
return - V_403 ;
break;
case V_759 :
if ( ! ( V_752 -> V_758 & V_185 ) )
return - V_403 ;
}
do {
V_306 = F_487 ( V_65 , V_696 , V_698 ) ;
if ( ( V_306 != - V_128 ) || F_491 ( V_696 ) )
break;
V_50 = F_447 ( V_50 ) ;
V_306 = - V_58 ;
if ( F_492 () )
break;
} while( V_306 < 0 );
return V_306 ;
}
int F_493 ( struct V_697 * V_700 , struct V_64 * V_65 , const T_8 * V_251 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
int V_8 ;
V_8 = F_449 ( V_65 , V_700 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_477 ( V_65 , V_726 , V_700 , V_742 ) ;
return F_173 ( V_14 , V_65 , V_251 , V_8 ) ;
}
static void F_494 ( struct V_117 * V_118 , void * V_154 )
{
struct V_760 * V_156 = V_154 ;
struct V_13 * V_14 = V_156 -> V_14 ;
F_42 ( V_14 -> V_62 -> V_153 ,
& V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , V_118 ) ;
V_156 -> args . V_704 . V_235 = V_14 -> V_62 -> V_236 ;
V_156 -> V_105 = V_152 ;
}
static void F_495 ( struct V_117 * V_118 , void * V_154 )
{
struct V_760 * V_156 = V_154 ;
struct V_13 * V_14 = V_156 -> V_14 ;
F_50 ( V_118 , & V_156 -> V_56 . V_159 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( V_14 , V_156 -> V_105 ) ;
break;
case - V_75 :
case - V_73 :
F_25 ( V_14 -> V_62 ) ;
break;
case - V_77 :
case - V_89 :
if ( F_250 ( V_118 , V_14 ,
NULL , NULL ) == - V_128 )
F_60 ( V_118 ) ;
}
}
static void F_496 ( void * V_154 )
{
struct V_760 * V_156 = V_154 ;
F_497 ( V_156 -> V_14 , V_156 -> V_282 ) ;
F_101 ( V_154 ) ;
}
static void
F_498 ( struct V_13 * V_14 , struct V_281 * V_282 )
{
struct V_760 * V_156 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_761 ] ,
} ;
if ( V_14 -> V_62 -> V_166 -> V_332 != 0 )
return;
V_156 = F_280 ( sizeof( * V_156 ) , V_303 ) ;
if ( ! V_156 )
return;
V_156 -> V_282 = V_282 ;
V_156 -> V_14 = V_14 ;
V_156 -> args . V_704 . V_235 = V_14 -> V_62 -> V_236 ;
V_156 -> args . V_704 . V_237 = V_282 -> V_707 . V_240 ;
V_156 -> args . V_704 . V_708 = V_14 -> V_708 ;
V_161 . V_314 = & V_156 -> args ;
V_161 . V_315 = & V_156 -> V_56 ;
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 0 ) ;
F_388 ( V_14 -> V_90 , & V_161 , 0 , & V_762 , V_156 ) ;
}
static int F_499 ( struct V_4 * V_4 , const char * V_763 ,
const void * V_604 , T_9 V_605 ,
int V_213 , int type )
{
if ( strcmp ( V_763 , L_55 ) != 0 )
return - V_27 ;
return F_410 ( F_14 ( V_4 ) , V_604 , V_605 ) ;
}
static int F_500 ( struct V_4 * V_4 , const char * V_763 ,
void * V_604 , T_9 V_605 , int type )
{
if ( strcmp ( V_763 , L_55 ) != 0 )
return - V_27 ;
return F_404 ( F_14 ( V_4 ) , V_604 , V_605 ) ;
}
static T_9 F_501 ( struct V_4 * V_4 , char * V_764 ,
T_9 V_765 , const char * V_241 ,
T_9 V_766 , int type )
{
T_9 V_12 = sizeof( V_767 ) ;
if ( ! F_391 ( F_90 ( F_14 ( V_4 ) ) ) )
return 0 ;
if ( V_764 && V_12 <= V_765 )
memcpy ( V_764 , V_767 , V_12 ) ;
return V_12 ;
}
static inline int F_502 ( struct V_13 * V_14 )
{
return V_14 -> V_93 & V_9 ;
}
static int F_503 ( struct V_4 * V_4 , const char * V_763 ,
const void * V_604 , T_9 V_605 ,
int V_213 , int type )
{
if ( F_504 ( V_763 ) )
return F_418 ( V_4 , V_604 , V_605 ) ;
return - V_630 ;
}
static int F_505 ( struct V_4 * V_4 , const char * V_763 ,
void * V_604 , T_9 V_605 , int type )
{
if ( F_504 ( V_763 ) )
return F_413 ( F_14 ( V_4 ) , V_604 , V_605 ) ;
return - V_630 ;
}
static T_9 F_506 ( struct V_4 * V_4 , char * V_764 ,
T_9 V_765 , const char * V_241 ,
T_9 V_766 , int type )
{
T_9 V_12 = 0 ;
if ( F_2 ( F_14 ( V_4 ) , V_9 ) ) {
V_12 = F_507 ( F_14 ( V_4 ) , NULL , 0 ) ;
if ( V_764 && V_12 <= V_765 )
F_507 ( F_14 ( V_4 ) , V_764 , V_12 ) ;
}
return V_12 ;
}
static void F_282 ( struct V_387 * V_388 )
{
if ( ! ( ( ( V_388 -> V_297 & V_768 ) ||
( V_388 -> V_297 & V_769 ) ) &&
( V_388 -> V_297 & V_481 ) &&
( V_388 -> V_297 & V_770 ) ) )
return;
V_388 -> V_297 |= V_335 | V_497 |
V_498 | V_771 ;
V_388 -> V_256 = V_340 | V_500 | V_501 ;
V_388 -> V_502 = 2 ;
}
static int F_508 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_483 * V_241 ,
struct V_485 * V_772 ,
struct V_484 * V_484 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
T_1 V_242 [ 3 ] = {
[ 0 ] = V_773 | V_774 ,
} ;
struct V_775 args = {
. V_495 = F_98 ( V_3 ) ,
. V_241 = V_241 ,
. V_484 = V_484 ,
. V_242 = V_242 ,
} ;
struct V_776 V_56 = {
. V_772 = V_772 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_777 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
int V_306 ;
F_8 ( L_56 , V_34 ) ;
if ( F_90 ( V_3 ) -> V_15 [ 1 ] & V_778 )
V_242 [ 1 ] |= V_778 ;
else
V_242 [ 0 ] |= V_45 ;
F_86 ( & V_772 -> V_388 ) ;
V_772 -> V_14 = V_14 ;
V_772 -> V_779 = 0 ;
V_306 = F_76 ( V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
F_8 ( L_57 , V_34 , V_306 ) ;
return V_306 ;
}
int F_281 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_483 * V_241 ,
struct V_485 * V_772 ,
struct V_484 * V_484 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_508 ( V_90 , V_3 , V_241 ,
V_772 , V_484 ) ;
F_509 ( V_3 , V_241 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_510 ( struct V_2 * V_2 ,
struct V_485 * V_486 ,
struct V_484 * V_484 , struct V_316 * V_350 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
T_1 V_242 [ 2 ] = {
[ 0 ] = V_773 | V_774 ,
} ;
struct V_775 args = {
. V_235 = V_14 -> V_62 -> V_236 ,
. V_245 = F_98 ( V_2 ) ,
. V_484 = V_484 ,
. V_242 = V_242 ,
. V_780 = 1 ,
. V_781 = 1 ,
} ;
struct V_776 V_56 = {
. V_772 = V_486 ,
. V_780 = 1 ,
. V_781 = 1 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_777 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
unsigned long V_564 = V_152 ;
int V_306 ;
F_86 ( & V_486 -> V_388 ) ;
V_486 -> V_14 = V_14 ;
V_486 -> V_779 = 0 ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_306 = F_72 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_306 )
return V_306 ;
F_38 ( V_14 , V_564 ) ;
return 0 ;
}
static int F_511 ( struct V_2 * V_2 ,
struct V_485 * V_486 ,
struct V_484 * V_484 , struct V_316 * V_350 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
T_1 V_242 [ 2 ] = {
[ 0 ] = V_773 | V_774 ,
} ;
struct V_775 args = {
. V_245 = F_98 ( V_2 ) ,
. V_484 = V_484 ,
. V_242 = V_242 ,
. V_780 = 1 ,
} ;
struct V_776 V_56 = {
. V_772 = V_486 ,
. V_780 = 1 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_777 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
int V_306 ;
F_86 ( & V_486 -> V_388 ) ;
V_486 -> V_14 = V_14 ;
V_486 -> V_779 = 0 ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_306 = F_72 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_306 == V_782 &&
V_56 . V_159 . V_143 & V_783 )
V_306 = - V_77 ;
return V_306 ;
}
int F_512 ( struct V_2 * V_2 ,
struct V_485 * V_486 ,
struct V_484 * V_484 , struct V_316 * V_350 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_784 * V_785 =
V_63 -> V_166 -> V_786 ;
struct V_60 V_61 = { } ;
int V_306 ;
F_8 ( L_58 , V_34 ,
( unsigned long long ) V_14 -> V_482 . V_787 ,
( unsigned long long ) V_14 -> V_482 . V_788 ,
V_63 -> V_96 ) ;
F_513 ( F_98 ( V_2 ) , V_34 ) ;
do {
V_306 = V_785 -> V_789 ( V_2 , V_486 , V_484 , V_350 ) ;
if ( V_306 != - V_89 )
break;
F_21 ( V_14 , V_306 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_306 ;
}
static int F_514 ( struct V_2 * V_2 , struct V_316 * V_350 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_62 * V_63 = F_90 ( V_2 ) -> V_62 ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_790 args = {
. V_245 = F_98 ( V_2 ) ,
. V_235 = V_63 -> V_236 ,
. V_781 = 1 ,
} ;
struct V_791 V_56 = {
. V_781 = 1 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_792 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
unsigned long V_564 = V_152 ;
int V_306 ;
V_56 . V_245 = F_515 () ;
if ( V_56 . V_245 == NULL )
return - V_124 ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_306 = F_72 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
F_516 ( V_56 . V_245 ) ;
if ( V_306 )
return V_306 ;
F_34 ( V_63 , V_564 ) ;
return 0 ;
}
static int F_517 ( struct V_2 * V_2 , struct V_316 * V_350 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_790 args = {
. V_245 = F_98 ( V_2 ) ,
} ;
struct V_791 V_56 = {
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_792 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
int V_306 ;
V_56 . V_245 = F_515 () ;
if ( V_56 . V_245 == NULL )
return - V_124 ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_306 = F_72 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
F_516 ( V_56 . V_245 ) ;
if ( V_306 == V_782 &&
V_56 . V_159 . V_143 & V_783 )
V_306 = - V_77 ;
return V_306 ;
}
int F_518 ( struct V_2 * V_2 , struct V_316 * V_350 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_784 * V_785 =
V_63 -> V_166 -> V_786 ;
struct V_60 V_61 = { } ;
int V_306 ;
F_8 ( L_58 , V_34 ,
( unsigned long long ) V_14 -> V_482 . V_787 ,
( unsigned long long ) V_14 -> V_482 . V_788 ,
V_63 -> V_96 ) ;
F_513 ( F_98 ( V_2 ) , V_34 ) ;
do {
V_306 = V_785 -> V_793 ( V_2 , V_350 ) ;
if ( V_306 != - V_89 )
break;
F_21 ( V_14 , V_306 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_306 ;
}
static int F_519 ( struct V_2 * V_3 , const struct V_483 * V_241 , struct V_794 * V_476 , bool V_795 )
{
int V_306 ;
struct V_796 args = {
. V_495 = F_98 ( V_3 ) ,
. V_241 = V_241 ,
} ;
struct V_797 V_56 = {
. V_476 = V_476 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_798 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
struct V_54 * V_55 = F_90 ( V_3 ) -> V_90 ;
struct V_316 * V_350 = NULL ;
if ( V_795 ) {
V_55 = F_90 ( V_3 ) -> V_62 -> V_100 ;
V_350 = F_520 ( F_90 ( V_3 ) -> V_62 ) ;
V_161 . V_316 = V_350 ;
}
F_8 ( L_59 , V_241 -> V_241 ) ;
F_257 ( F_90 ( V_3 ) -> V_62 ,
V_799 , & V_55 , & V_161 ) ;
V_306 = F_76 ( V_55 , F_90 ( V_3 ) , & V_161 , & args . V_158 ,
& V_56 . V_159 , 0 ) ;
F_8 ( L_60 , V_306 ) ;
if ( V_350 )
F_214 ( V_350 ) ;
return V_306 ;
}
int F_521 ( struct V_2 * V_3 , const struct V_483 * V_241 ,
struct V_794 * V_476 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_33 ( F_90 ( V_3 ) -> V_62 ) )
V_8 = F_519 ( V_3 , V_241 , V_476 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_519 ( V_3 , V_241 , V_476 , false ) ;
F_522 ( V_3 , V_241 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_523 ( T_1 V_213 )
{
if ( V_213 & ~ V_800 )
goto V_801;
if ( ( V_213 & V_802 ) &&
( V_213 & V_803 ) )
goto V_801;
if ( ! ( V_213 & ( V_804 ) ) )
goto V_801;
return V_363 ;
V_801:
return - V_805 ;
}
static bool
F_524 ( struct V_806 * V_807 ,
struct V_806 * V_808 )
{
if ( V_807 -> V_809 == V_808 -> V_809 &&
memcmp ( V_807 -> V_810 , V_808 -> V_810 , V_807 -> V_809 ) == 0 )
return true ;
return false ;
}
int F_525 ( struct V_62 * V_63 , struct V_316 * V_350 )
{
int V_306 ;
struct V_811 args = {
. V_90 = V_63 ,
. V_3 = V_812 ,
} ;
struct V_813 V_56 ;
struct V_160 V_161 = {
. V_311 =
& V_312 [ V_814 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
F_8 ( L_11 , V_34 ) ;
F_526 ( & args . V_815 , & V_63 -> V_86 -> V_816 ) ;
if ( ! ( V_63 -> V_86 -> V_213 & V_817 ) )
args . V_3 = V_818 ;
V_306 = F_390 ( V_63 -> V_100 , & V_161 , V_602 ) ;
F_527 ( V_63 , V_306 ) ;
if ( V_306 == 0 ) {
if ( memcmp ( V_56 . V_815 . V_156 ,
V_63 -> V_86 -> V_816 . V_156 , V_819 ) ) {
F_8 ( L_61 , V_34 ) ;
V_306 = - V_35 ;
goto V_129;
}
if ( ( V_56 . V_3 & args . V_3 ) != V_56 . V_3 || V_56 . V_3 == 0 ) {
F_8 ( L_62 ,
V_34 ) ;
V_306 = - V_35 ;
goto V_129;
}
if ( V_56 . V_820 != args . V_820 ) {
F_8 ( L_63 ,
V_34 ) ;
V_306 = - V_35 ;
goto V_129;
}
}
V_129:
F_8 ( L_64 , V_34 , V_306 ) ;
return V_306 ;
}
static int F_528 ( struct V_62 * V_63 ,
struct V_821 * V_212 )
{
static const T_1 V_822 [ V_823 ] = {
[ 1 ] = 1 << ( V_824 - 32 ) |
1 << ( V_825 - 32 ) |
1 << ( V_826 - 32 ) |
1 << ( V_827 - 32 ) |
1 << ( V_828 - 32 )
} ;
unsigned int V_473 ;
if ( V_212 -> V_829 == V_830 ) {
F_529 ( V_831 , L_65 ) ;
for ( V_473 = 0 ; V_473 <= V_832 ; V_473 ++ ) {
if ( F_32 ( V_473 , V_212 -> V_833 . V_249 . V_834 ) )
F_529 ( V_831 , L_66 , V_473 ) ;
if ( F_32 ( V_473 , V_212 -> V_835 . V_249 . V_834 ) )
F_529 ( V_831 , L_67 , V_473 ) ;
}
for ( V_473 = 0 ; V_473 < V_823 ; V_473 ++ ) {
if ( V_212 -> V_833 . V_249 . V_836 [ V_473 ] & ~ V_822 [ V_473 ] ) {
F_529 ( V_831 , L_68 ) ;
return - V_27 ;
}
}
if ( F_32 ( V_824 , V_212 -> V_833 . V_249 . V_834 ) &&
F_32 ( V_826 , V_212 -> V_833 . V_249 . V_834 ) &&
F_32 ( V_827 , V_212 -> V_833 . V_249 . V_834 ) &&
F_32 ( V_828 , V_212 -> V_833 . V_249 . V_834 ) ) {
F_529 ( V_831 , L_69 ) ;
F_529 ( V_831 , L_70 ) ;
F_127 ( V_837 , & V_63 -> V_838 ) ;
} else {
F_529 ( V_831 , L_68 ) ;
return - V_27 ;
}
if ( F_32 ( V_839 , V_212 -> V_835 . V_249 . V_834 ) &&
F_32 ( V_840 , V_212 -> V_835 . V_249 . V_834 ) ) {
F_529 ( V_831 , L_71 ) ;
F_127 ( V_420 , & V_63 -> V_838 ) ;
}
if ( F_32 ( V_841 , V_212 -> V_835 . V_249 . V_834 ) &&
F_32 ( V_842 , V_212 -> V_835 . V_249 . V_834 ) ) {
F_529 ( V_831 , L_72 ) ;
F_127 ( V_799 , & V_63 -> V_838 ) ;
}
if ( F_32 ( V_843 , V_212 -> V_835 . V_249 . V_834 ) &&
F_32 ( V_844 , V_212 -> V_835 . V_249 . V_834 ) ) {
F_529 ( V_831 , L_73 ) ;
F_127 ( V_845 , & V_63 -> V_838 ) ;
}
if ( F_32 ( V_846 , V_212 -> V_835 . V_249 . V_834 ) ) {
F_529 ( V_831 , L_74 ) ;
F_127 ( V_847 , & V_63 -> V_838 ) ;
}
if ( F_32 ( V_848 , V_212 -> V_835 . V_249 . V_834 ) ) {
F_529 ( V_831 , L_75 ) ;
F_127 ( V_849 , & V_63 -> V_838 ) ;
}
}
return 0 ;
}
static int F_530 ( struct V_62 * V_63 , struct V_316 * V_350 ,
T_1 V_850 )
{
T_12 V_37 ;
struct V_851 args = {
. V_37 = & V_37 ,
. V_90 = V_63 ,
#ifdef F_531
. V_213 = V_852 |
V_853 |
V_854 ,
#else
. V_213 = V_852 |
V_853 ,
#endif
} ;
struct V_855 V_56 = {
0
} ;
int V_306 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_856 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
F_422 ( V_63 , & V_37 ) ;
V_306 = F_429 ( V_63 ) ;
if ( V_306 )
goto V_129;
F_8 ( L_76 ,
V_63 -> V_100 -> V_101 -> V_686 -> V_687 ,
V_63 -> V_657 ) ;
V_56 . V_857 = F_91 ( sizeof( struct V_858 ) ,
V_303 ) ;
if ( F_366 ( V_56 . V_857 == NULL ) ) {
V_306 = - V_124 ;
goto V_129;
}
V_56 . V_810 = F_91 ( sizeof( struct V_806 ) ,
V_303 ) ;
if ( F_366 ( V_56 . V_810 == NULL ) ) {
V_306 = - V_124 ;
goto V_859;
}
V_56 . V_860 = F_91 ( sizeof( struct V_861 ) , V_303 ) ;
if ( F_366 ( V_56 . V_860 == NULL ) ) {
V_306 = - V_124 ;
goto V_862;
}
switch ( V_850 ) {
case V_863 :
args . V_864 . V_829 = V_863 ;
break;
case V_830 :
args . V_864 = V_865 ;
break;
default:
F_532 ( 1 ) ;
V_306 = - V_27 ;
goto V_866;
}
V_306 = F_390 ( V_63 -> V_100 , & V_161 , V_602 ) ;
F_533 ( V_63 , V_306 ) ;
if ( V_306 == 0 )
V_306 = F_523 ( V_56 . V_213 ) ;
if ( V_306 == 0 )
V_306 = F_528 ( V_63 , & V_56 . V_864 ) ;
if ( V_306 == 0 ) {
V_63 -> V_236 = V_56 . V_235 ;
V_63 -> V_867 = V_56 . V_213 ;
if ( ! ( V_56 . V_213 & V_868 ) ) {
F_129 ( V_869 ,
& V_63 -> V_86 -> V_870 ) ;
V_63 -> V_871 = V_56 . V_203 ;
}
F_101 ( V_63 -> V_872 ) ;
V_63 -> V_872 = V_56 . V_857 ;
V_56 . V_857 = NULL ;
F_101 ( V_63 -> V_873 ) ;
V_63 -> V_873 = V_56 . V_860 ;
V_56 . V_860 = NULL ;
if ( V_63 -> V_874 != NULL &&
! F_524 ( V_63 -> V_874 ,
V_56 . V_810 ) ) {
F_8 ( L_77 ,
V_34 ) ;
F_127 ( V_875 , & V_63 -> V_643 ) ;
F_101 ( V_63 -> V_874 ) ;
V_63 -> V_874 = NULL ;
}
if ( V_63 -> V_874 == NULL ) {
V_63 -> V_874 = V_56 . V_810 ;
V_56 . V_810 = NULL ;
}
}
V_866:
F_101 ( V_56 . V_860 ) ;
V_862:
F_101 ( V_56 . V_810 ) ;
V_859:
F_101 ( V_56 . V_857 ) ;
V_129:
if ( V_63 -> V_873 != NULL )
F_8 ( L_78
L_79 ,
V_63 -> V_873 -> V_876 , V_63 -> V_873 -> V_241 ,
V_63 -> V_873 -> V_877 . V_878 ,
V_63 -> V_873 -> V_877 . V_879 ) ;
F_8 ( L_80 , V_306 ) ;
return V_306 ;
}
int F_534 ( struct V_62 * V_63 , struct V_316 * V_350 )
{
T_4 V_880 = V_63 -> V_100 -> V_101 -> V_102 ;
int V_306 ;
if ( V_880 == V_103 ||
V_880 == V_104 ) {
V_306 = F_530 ( V_63 , V_350 , V_830 ) ;
if ( ! V_306 )
return 0 ;
}
return F_530 ( V_63 , V_350 , V_863 ) ;
}
static int F_535 ( struct V_62 * V_63 ,
struct V_316 * V_350 )
{
struct V_160 V_161 = {
. V_311 = & V_312 [ V_881 ] ,
. V_314 = V_63 ,
. V_316 = V_350 ,
} ;
int V_306 ;
V_306 = F_390 ( V_63 -> V_100 , & V_161 , V_602 ) ;
F_536 ( V_63 , V_306 ) ;
if ( V_306 )
F_8 ( L_81
L_82 , V_306 , V_63 -> V_96 ) ;
return V_306 ;
}
static int F_537 ( struct V_62 * V_63 ,
struct V_316 * V_350 )
{
unsigned int V_882 ;
int V_51 ;
for ( V_882 = V_883 ; V_882 != 0 ; V_882 -- ) {
V_51 = F_535 ( V_63 , V_350 ) ;
switch ( V_51 ) {
case - V_89 :
case - V_884 :
F_175 ( 1 ) ;
break;
default:
return V_51 ;
}
}
return 0 ;
}
int F_538 ( struct V_62 * V_63 )
{
struct V_316 * V_350 ;
int V_51 = 0 ;
if ( V_63 -> V_166 -> V_332 < 1 )
goto V_129;
if ( V_63 -> V_867 == 0 )
goto V_129;
if ( V_63 -> V_885 )
goto V_129;
V_350 = F_520 ( V_63 ) ;
V_51 = F_537 ( V_63 , V_350 ) ;
if ( V_350 )
F_214 ( V_350 ) ;
switch ( V_51 ) {
case 0 :
case - V_75 :
V_63 -> V_867 = 0 ;
}
V_129:
return V_51 ;
}
static void F_539 ( struct V_117 * V_118 ,
void * V_154 )
{
struct V_886 * V_156 =
(struct V_886 * ) V_154 ;
F_8 ( L_11 , V_34 ) ;
F_64 ( V_156 -> V_63 -> V_86 ,
& V_156 -> args -> V_887 ,
& V_156 -> V_56 -> V_888 ,
V_118 ) ;
F_8 ( L_83 , V_34 ) ;
}
static void F_540 ( struct V_117 * V_118 , void * V_154 )
{
struct V_886 * V_156 =
(struct V_886 * ) V_154 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_55 ( V_118 , & V_156 -> V_56 -> V_888 ) )
return;
switch ( V_118 -> V_147 ) {
case - V_89 :
case - V_88 :
F_8 ( L_84 , V_34 , V_118 -> V_147 ) ;
F_62 ( V_118 , V_53 ) ;
V_118 -> V_147 = 0 ;
case - V_91 :
F_60 ( V_118 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
int F_541 ( struct V_62 * V_63 , struct V_459 * V_560 )
{
struct V_117 * V_118 ;
struct V_889 args ;
struct V_890 V_56 = {
. V_891 = V_560 ,
} ;
struct V_886 V_156 = {
. args = & args ,
. V_56 = & V_56 ,
. V_63 = V_63 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_892 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
struct V_162 V_163 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_893 ,
. V_168 = & V_156 ,
. V_213 = V_602 ,
} ;
int V_306 ;
F_40 ( & args . V_887 , & V_56 . V_888 , 0 ) ;
F_41 ( & args . V_887 ) ;
F_8 ( L_11 , V_34 ) ;
V_118 = F_73 ( & V_163 ) ;
if ( F_45 ( V_118 ) )
V_306 = F_74 ( V_118 ) ;
else {
V_306 = V_118 -> V_147 ;
F_75 ( V_118 ) ;
}
F_8 ( L_85 , V_34 , V_306 ) ;
return V_306 ;
}
static void F_542 ( struct V_894 * args )
{
unsigned int V_895 , V_896 ;
V_895 = V_897 + V_898 ;
V_896 = V_897 + V_899 ;
args -> V_900 . V_895 = V_895 ;
args -> V_900 . V_896 = V_896 ;
args -> V_900 . V_901 = V_902 ;
args -> V_900 . V_903 = V_904 ;
F_8 ( L_86
L_87 ,
V_34 ,
args -> V_900 . V_895 , args -> V_900 . V_896 ,
args -> V_900 . V_901 , args -> V_900 . V_903 ) ;
args -> V_905 . V_895 = V_609 ;
args -> V_905 . V_896 = V_609 ;
args -> V_905 . V_906 = 0 ;
args -> V_905 . V_901 = V_907 ;
args -> V_905 . V_903 = 1 ;
F_8 ( L_88
L_89 ,
V_34 ,
args -> V_905 . V_895 , args -> V_905 . V_896 ,
args -> V_905 . V_906 , args -> V_905 . V_901 ,
args -> V_905 . V_903 ) ;
}
static int F_543 ( struct V_894 * args ,
struct V_908 * V_56 )
{
struct V_909 * V_910 = & args -> V_900 ;
struct V_909 * V_911 = & V_56 -> V_900 ;
if ( V_911 -> V_896 > V_910 -> V_896 )
return - V_27 ;
if ( V_911 -> V_901 < V_910 -> V_901 )
return - V_27 ;
if ( V_911 -> V_903 == 0 )
return - V_27 ;
if ( V_911 -> V_903 > V_912 )
V_911 -> V_903 = V_912 ;
return 0 ;
}
static int F_544 ( struct V_894 * args ,
struct V_908 * V_56 )
{
struct V_909 * V_910 = & args -> V_905 ;
struct V_909 * V_911 = & V_56 -> V_905 ;
if ( ! ( V_56 -> V_213 & V_817 ) )
goto V_129;
if ( V_911 -> V_895 > V_910 -> V_895 )
return - V_27 ;
if ( V_911 -> V_896 < V_910 -> V_896 )
return - V_27 ;
if ( V_911 -> V_906 > V_910 -> V_906 )
return - V_27 ;
if ( V_911 -> V_901 != V_910 -> V_901 )
return - V_27 ;
if ( V_911 -> V_903 != V_910 -> V_903 )
return - V_27 ;
V_129:
return 0 ;
}
static int F_545 ( struct V_894 * args ,
struct V_908 * V_56 )
{
int V_51 ;
V_51 = F_543 ( args , V_56 ) ;
if ( V_51 )
return V_51 ;
return F_544 ( args , V_56 ) ;
}
static void F_546 ( struct V_131 * V_132 ,
struct V_908 * V_56 )
{
F_526 ( & V_132 -> V_816 , & V_56 -> V_815 ) ;
V_132 -> V_63 -> V_867 |= V_868 ;
F_127 ( V_869 , & V_132 -> V_870 ) ;
V_132 -> V_213 = V_56 -> V_213 ;
memcpy ( & V_132 -> V_900 , & V_56 -> V_900 , sizeof( V_132 -> V_900 ) ) ;
if ( V_56 -> V_213 & V_817 )
memcpy ( & V_132 -> V_905 , & V_56 -> V_905 ,
sizeof( V_132 -> V_905 ) ) ;
}
static int F_547 ( struct V_62 * V_63 ,
struct V_316 * V_350 )
{
struct V_131 * V_132 = V_63 -> V_86 ;
struct V_894 args = {
. V_90 = V_63 ,
. V_235 = V_63 -> V_236 ,
. V_203 = V_63 -> V_871 ,
. V_913 = V_914 ,
} ;
struct V_908 V_56 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_915 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
int V_306 ;
F_542 ( & args ) ;
args . V_213 = ( V_916 | V_817 ) ;
V_306 = F_390 ( V_132 -> V_63 -> V_100 , & V_161 , V_602 ) ;
F_548 ( V_63 , V_306 ) ;
if ( ! V_306 ) {
V_306 = F_545 ( & args , & V_56 ) ;
if ( V_63 -> V_871 == V_56 . V_203 )
V_63 -> V_871 ++ ;
if ( V_306 )
goto V_129;
F_546 ( V_132 , & V_56 ) ;
}
V_129:
return V_306 ;
}
int F_549 ( struct V_62 * V_63 , struct V_316 * V_350 )
{
int V_306 ;
unsigned * V_917 ;
struct V_131 * V_132 = V_63 -> V_86 ;
F_8 ( L_90 , V_34 , V_63 , V_132 ) ;
V_306 = F_547 ( V_63 , V_350 ) ;
if ( V_306 )
goto V_129;
V_306 = F_550 ( V_132 ) ;
F_8 ( L_91 , V_306 ) ;
if ( V_306 )
goto V_129;
V_917 = ( unsigned * ) & V_132 -> V_816 . V_156 [ 0 ] ;
F_8 ( L_92 , V_34 ,
V_63 -> V_871 , V_917 [ 0 ] , V_917 [ 1 ] , V_917 [ 2 ] , V_917 [ 3 ] ) ;
V_129:
F_8 ( L_83 , V_34 ) ;
return V_306 ;
}
int F_551 ( struct V_131 * V_132 ,
struct V_316 * V_350 )
{
struct V_160 V_161 = {
. V_311 = & V_312 [ V_918 ] ,
. V_314 = V_132 ,
. V_316 = V_350 ,
} ;
int V_306 = 0 ;
F_8 ( L_93 ) ;
if ( ! F_120 ( V_869 , & V_132 -> V_870 ) )
return 0 ;
V_306 = F_390 ( V_132 -> V_63 -> V_100 , & V_161 , V_602 ) ;
F_552 ( V_132 -> V_63 , V_306 ) ;
if ( V_306 )
F_8 ( L_94
L_95 , V_306 ) ;
F_8 ( L_96 ) ;
return V_306 ;
}
static void F_553 ( void * V_156 )
{
struct V_919 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
if ( F_380 ( & V_63 -> V_596 ) > 1 )
F_381 ( V_63 ) ;
F_382 ( V_63 ) ;
F_101 ( V_154 ) ;
}
static int F_554 ( struct V_117 * V_118 , struct V_62 * V_63 )
{
switch( V_118 -> V_147 ) {
case - V_89 :
F_62 ( V_118 , V_52 ) ;
return - V_128 ;
default:
F_25 ( V_63 ) ;
}
return 0 ;
}
static void F_555 ( struct V_117 * V_118 , void * V_156 )
{
struct V_919 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
if ( ! F_55 ( V_118 , V_118 -> V_326 . V_315 ) )
return;
F_556 ( V_63 , V_118 -> V_147 ) ;
if ( V_118 -> V_147 < 0 ) {
F_8 ( L_97 , V_34 , V_118 -> V_147 ) ;
if ( F_380 ( & V_63 -> V_596 ) == 1 )
goto V_129;
if ( F_554 ( V_118 , V_63 ) == - V_128 ) {
F_60 ( V_118 ) ;
return;
}
}
F_8 ( L_98 , V_34 , V_118 -> V_326 . V_316 ) ;
V_129:
F_8 ( L_83 , V_34 ) ;
}
static void F_557 ( struct V_117 * V_118 , void * V_156 )
{
struct V_919 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
struct V_108 * args ;
struct V_109 * V_56 ;
args = V_118 -> V_326 . V_314 ;
V_56 = V_118 -> V_326 . V_315 ;
F_64 ( V_63 -> V_86 , args , V_56 , V_118 ) ;
}
static struct V_117 * F_558 ( struct V_62 * V_63 ,
struct V_316 * V_350 ,
bool V_920 )
{
struct V_919 * V_154 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_921 ] ,
. V_316 = V_350 ,
} ;
struct V_162 V_317 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_922 ,
. V_213 = V_321 | V_602 ,
} ;
if ( ! F_387 ( & V_63 -> V_596 ) )
return F_46 ( - V_35 ) ;
V_154 = F_91 ( sizeof( * V_154 ) , V_303 ) ;
if ( V_154 == NULL ) {
F_382 ( V_63 ) ;
return F_46 ( - V_124 ) ;
}
F_40 ( & V_154 -> args , & V_154 -> V_56 , 0 ) ;
if ( V_920 )
F_41 ( & V_154 -> args ) ;
V_161 . V_314 = & V_154 -> args ;
V_161 . V_315 = & V_154 -> V_56 ;
V_154 -> V_63 = V_63 ;
V_317 . V_168 = V_154 ;
return F_73 ( & V_317 ) ;
}
static int F_559 ( struct V_62 * V_63 , struct V_316 * V_350 , unsigned V_600 )
{
struct V_117 * V_118 ;
int V_51 = 0 ;
if ( ( V_600 & V_923 ) == 0 )
return - V_128 ;
V_118 = F_558 ( V_63 , V_350 , false ) ;
if ( F_45 ( V_118 ) )
V_51 = F_74 ( V_118 ) ;
else
F_474 ( V_118 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_560 ( struct V_62 * V_63 , struct V_316 * V_350 )
{
struct V_117 * V_118 ;
int V_51 ;
V_118 = F_558 ( V_63 , V_350 , true ) ;
if ( F_45 ( V_118 ) ) {
V_51 = F_74 ( V_118 ) ;
goto V_129;
}
V_51 = F_113 ( V_118 ) ;
if ( ! V_51 )
V_51 = V_118 -> V_147 ;
F_75 ( V_118 ) ;
V_129:
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static void F_561 ( struct V_117 * V_118 , void * V_156 )
{
struct V_924 * V_154 = V_156 ;
F_64 ( V_154 -> V_63 -> V_86 ,
& V_154 -> V_391 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_562 ( struct V_117 * V_118 , struct V_62 * V_63 )
{
switch( V_118 -> V_147 ) {
case 0 :
case - V_925 :
case - V_23 :
break;
case - V_89 :
F_62 ( V_118 , V_52 ) ;
case - V_91 :
return - V_128 ;
default:
F_25 ( V_63 ) ;
}
return 0 ;
}
static void F_563 ( struct V_117 * V_118 , void * V_156 )
{
struct V_924 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
struct V_109 * V_56 = & V_154 -> V_56 . V_159 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_55 ( V_118 , V_56 ) )
return;
F_564 ( V_63 , V_118 -> V_147 ) ;
if ( F_562 ( V_118 , V_63 ) == - V_128 ) {
F_60 ( V_118 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_565 ( void * V_156 )
{
struct V_924 * V_154 = V_156 ;
F_101 ( V_154 ) ;
}
static int F_566 ( struct V_62 * V_63 ,
struct V_316 * V_350 )
{
struct V_924 * V_154 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_926 ] ,
. V_316 = V_350 ,
} ;
struct V_162 V_317 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_927 ,
. V_213 = V_321 ,
} ;
int V_306 = - V_124 ;
F_8 ( L_11 , V_34 ) ;
V_154 = F_91 ( sizeof( * V_154 ) , V_303 ) ;
if ( V_154 == NULL )
goto V_129;
V_154 -> V_63 = V_63 ;
V_154 -> V_391 . V_928 = 0 ;
F_40 ( & V_154 -> V_391 . V_158 , & V_154 -> V_56 . V_159 , 0 ) ;
F_41 ( & V_154 -> V_391 . V_158 ) ;
V_161 . V_314 = & V_154 -> V_391 ;
V_161 . V_315 = & V_154 -> V_56 ;
V_317 . V_168 = V_154 ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) ) {
V_306 = F_74 ( V_118 ) ;
goto V_129;
}
V_306 = F_112 ( V_118 ) ;
if ( V_306 == 0 )
V_306 = V_118 -> V_147 ;
F_75 ( V_118 ) ;
return 0 ;
V_129:
F_8 ( L_16 , V_34 , V_306 ) ;
return V_306 ;
}
static void
F_567 ( struct V_117 * V_118 , void * V_154 )
{
struct V_929 * V_930 = V_154 ;
struct V_13 * V_14 = F_90 ( V_930 -> args . V_2 ) ;
struct V_131 * V_132 = F_67 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
if ( F_64 ( V_132 , & V_930 -> args . V_158 ,
& V_930 -> V_56 . V_159 , V_118 ) )
return;
if ( F_568 ( & V_930 -> args . V_251 ,
F_78 ( V_930 -> args . V_2 ) -> V_931 ,
& V_930 -> args . V_932 ,
V_930 -> args . V_301 -> V_65 ) ) {
F_569 ( V_118 , V_782 ) ;
}
}
static void F_570 ( struct V_117 * V_118 , void * V_154 )
{
struct V_929 * V_930 = V_154 ;
struct V_2 * V_2 = V_930 -> args . V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_933 * V_934 ;
struct V_64 * V_65 = NULL ;
unsigned long V_935 , V_564 , V_936 ;
F_8 ( L_99 , V_34 , - V_118 -> V_147 ) ;
if ( ! F_55 ( V_118 , & V_930 -> V_56 . V_159 ) )
goto V_129;
switch ( V_118 -> V_147 ) {
case 0 :
goto V_129;
case - V_19 :
case - V_20 :
V_935 = F_571 ( V_118 -> V_937 ) ;
V_936 = V_930 -> args . V_105 + V_935 ;
V_564 = V_152 ;
if ( F_572 ( V_936 , V_564 ) ) {
unsigned long V_938 ;
V_938 = F_573 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_100 ,
V_34 , V_938 ) ;
F_62 ( V_118 , V_938 ) ;
V_118 -> V_147 = 0 ;
F_60 ( V_118 ) ;
goto V_129;
}
break;
case - V_73 :
case - V_70 :
F_35 ( & V_2 -> V_173 ) ;
V_934 = F_78 ( V_2 ) -> V_931 ;
if ( ! V_934 || F_574 ( & V_934 -> V_939 ) ) {
F_37 ( & V_2 -> V_173 ) ;
V_65 = V_930 -> args . V_301 -> V_65 ;
} else {
F_575 ( V_940 ) ;
F_576 ( V_934 , & V_940 , NULL ) ;
F_37 ( & V_2 -> V_173 ) ;
F_577 ( & V_940 ) ;
V_118 -> V_147 = 0 ;
F_60 ( V_118 ) ;
}
}
if ( F_250 ( V_118 , V_14 , V_65 , NULL ) == - V_128 )
F_60 ( V_118 ) ;
V_129:
F_8 ( L_83 , V_34 ) ;
}
static T_9 F_578 ( struct V_13 * V_14 )
{
T_1 V_896 = V_14 -> V_62 -> V_86 -> V_900 . V_896 ;
return F_579 ( 0 , V_896 ) ;
}
static void F_580 ( struct V_484 * * V_42 , T_9 V_941 )
{
int V_473 ;
if ( ! V_42 )
return;
for ( V_473 = 0 ; V_473 < V_941 ; V_473 ++ ) {
if ( ! V_42 [ V_473 ] )
break;
F_283 ( V_42 [ V_473 ] ) ;
}
F_101 ( V_42 ) ;
}
static struct V_484 * * F_581 ( T_9 V_941 , T_6 V_942 )
{
struct V_484 * * V_42 ;
int V_473 ;
V_42 = F_582 ( V_941 , sizeof( struct V_484 * ) , V_942 ) ;
if ( ! V_42 ) {
F_8 ( L_101 , V_34 , V_941 ) ;
return NULL ;
}
for ( V_473 = 0 ; V_473 < V_941 ; V_473 ++ ) {
V_42 [ V_473 ] = F_279 ( V_942 ) ;
if ( ! V_42 [ V_473 ] ) {
F_8 ( L_102 , V_34 ) ;
F_580 ( V_42 , V_941 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_583 ( void * V_154 )
{
struct V_929 * V_930 = V_154 ;
struct V_2 * V_2 = V_930 -> args . V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
T_9 V_943 = F_578 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_580 ( V_930 -> args . V_931 . V_42 , V_943 ) ;
F_584 ( F_78 ( V_2 ) -> V_931 ) ;
F_172 ( V_930 -> args . V_301 ) ;
F_101 ( V_154 ) ;
F_8 ( L_83 , V_34 ) ;
}
struct V_944 *
F_585 ( struct V_929 * V_930 , T_6 V_942 )
{
struct V_2 * V_2 = V_930 -> args . V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
T_9 V_943 = F_578 ( V_14 ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_945 ] ,
. V_314 = & V_930 -> args ,
. V_315 = & V_930 -> V_56 ,
. V_316 = V_930 -> V_350 ,
} ;
struct V_162 V_317 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_946 ,
. V_168 = V_930 ,
. V_213 = V_321 ,
} ;
struct V_944 * V_947 = NULL ;
int V_306 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_586 ( F_78 ( V_2 ) -> V_931 ) ;
V_930 -> args . V_931 . V_42 = F_581 ( V_943 , V_942 ) ;
if ( ! V_930 -> args . V_931 . V_42 ) {
F_583 ( V_930 ) ;
return F_46 ( - V_124 ) ;
}
V_930 -> args . V_931 . V_511 = V_943 * V_609 ;
V_930 -> args . V_105 = V_152 ;
V_930 -> V_56 . V_948 = & V_930 -> args . V_931 ;
V_930 -> V_56 . V_159 . V_114 = NULL ;
F_40 ( & V_930 -> args . V_158 , & V_930 -> V_56 . V_159 , 0 ) ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) )
return F_259 ( V_118 ) ;
V_306 = F_112 ( V_118 ) ;
if ( V_306 == 0 )
V_306 = V_118 -> V_147 ;
F_587 ( V_930 -> args . V_301 ,
& V_930 -> args . V_932 ,
& V_930 -> V_56 . V_932 ,
V_306 ) ;
if ( V_306 == 0 && V_930 -> V_56 . V_948 -> V_12 )
V_947 = F_588 ( V_930 ) ;
F_75 ( V_118 ) ;
F_8 ( L_16 , V_34 , V_306 ) ;
if ( V_306 )
return F_46 ( V_306 ) ;
return V_947 ;
}
static void
F_589 ( struct V_117 * V_118 , void * V_154 )
{
struct V_949 * V_950 = V_154 ;
F_8 ( L_11 , V_34 ) ;
F_64 ( V_950 -> V_63 -> V_86 ,
& V_950 -> args . V_158 ,
& V_950 -> V_56 . V_159 ,
V_118 ) ;
}
static void F_590 ( struct V_117 * V_118 , void * V_154 )
{
struct V_949 * V_950 = V_154 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_55 ( V_118 , & V_950 -> V_56 . V_159 ) )
return;
V_14 = F_90 ( V_950 -> args . V_2 ) ;
switch ( V_118 -> V_147 ) {
default:
V_118 -> V_147 = 0 ;
case 0 :
break;
case - V_89 :
if ( F_250 ( V_118 , V_14 , NULL , NULL ) != - V_128 )
break;
F_60 ( V_118 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_591 ( void * V_154 )
{
struct V_949 * V_950 = V_154 ;
struct V_933 * V_934 = V_950 -> args . V_931 ;
F_575 ( V_951 ) ;
F_8 ( L_11 , V_34 ) ;
F_35 ( & V_934 -> V_952 -> V_173 ) ;
if ( V_950 -> V_56 . V_953 )
F_592 ( V_934 , & V_950 -> V_56 . V_251 , true ) ;
F_576 ( V_934 , & V_951 , & V_950 -> args . V_932 ) ;
F_593 ( V_934 ) ;
V_934 -> V_954 -- ;
F_37 ( & V_934 -> V_952 -> V_173 ) ;
F_577 ( & V_951 ) ;
F_584 ( V_950 -> args . V_931 ) ;
F_440 ( V_950 -> V_2 ) ;
F_101 ( V_154 ) ;
F_8 ( L_83 , V_34 ) ;
}
int F_594 ( struct V_949 * V_950 , bool V_955 )
{
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_956 ] ,
. V_314 = & V_950 -> args ,
. V_315 = & V_950 -> V_56 ,
. V_316 = V_950 -> V_350 ,
} ;
struct V_162 V_317 = {
. V_164 = F_90 ( V_950 -> args . V_2 ) -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_957 ,
. V_168 = V_950 ,
} ;
int V_306 = 0 ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_955 ) {
V_950 -> V_2 = F_443 ( V_950 -> args . V_2 ) ;
if ( ! V_950 -> V_2 ) {
F_591 ( V_950 ) ;
return - V_128 ;
}
V_317 . V_213 |= V_321 ;
}
F_40 ( & V_950 -> args . V_158 , & V_950 -> V_56 . V_159 , 1 ) ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
if ( V_955 )
V_306 = V_118 -> V_147 ;
F_595 ( V_950 -> args . V_2 , V_306 ) ;
F_8 ( L_16 , V_34 , V_306 ) ;
F_75 ( V_118 ) ;
return V_306 ;
}
static int
F_596 ( struct V_13 * V_14 ,
struct V_958 * V_959 ,
struct V_316 * V_350 )
{
struct V_960 args = {
. V_959 = V_959 ,
. V_961 = V_962 |
V_963 ,
} ;
struct V_964 V_56 = {
. V_959 = V_959 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_965 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
int V_306 ;
F_8 ( L_11 , V_34 ) ;
V_306 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_56 . V_966 & ~ args . V_961 )
F_8 ( L_103 , V_34 ) ;
if ( V_56 . V_966 != args . V_961 )
V_959 -> V_967 = 1 ;
F_8 ( L_16 , V_34 , V_306 ) ;
return V_306 ;
}
int F_597 ( struct V_13 * V_14 ,
struct V_958 * V_959 ,
struct V_316 * V_350 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_596 ( V_14 , V_959 , V_350 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_598 ( struct V_117 * V_118 , void * V_154 )
{
struct V_968 * V_156 = V_154 ;
struct V_13 * V_14 = F_90 ( V_156 -> args . V_2 ) ;
struct V_131 * V_132 = F_67 ( V_14 ) ;
F_64 ( V_132 ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static void
F_599 ( struct V_117 * V_118 , void * V_154 )
{
struct V_968 * V_156 = V_154 ;
struct V_13 * V_14 = F_90 ( V_156 -> args . V_2 ) ;
if ( ! F_55 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
switch ( V_118 -> V_147 ) {
case - V_68 :
case - V_969 :
case - V_970 :
case - V_88 :
V_118 -> V_147 = 0 ;
case 0 :
break;
default:
if ( F_250 ( V_118 , V_14 , NULL , NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return;
}
}
}
static void F_600 ( void * V_154 )
{
struct V_968 * V_156 = V_154 ;
F_601 ( V_156 ) ;
F_444 ( V_156 -> args . V_2 ,
V_156 -> V_56 . V_388 ) ;
F_214 ( V_156 -> V_350 ) ;
F_440 ( V_156 -> V_2 ) ;
F_101 ( V_156 ) ;
}
int
F_602 ( struct V_968 * V_156 , bool V_955 )
{
struct V_160 V_161 = {
. V_311 = & V_312 [ V_971 ] ,
. V_314 = & V_156 -> args ,
. V_315 = & V_156 -> V_56 ,
. V_316 = V_156 -> V_350 ,
} ;
struct V_162 V_317 = {
. V_118 = & V_156 -> V_118 ,
. V_164 = F_298 ( V_156 -> args . V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_972 ,
. V_168 = V_156 ,
} ;
struct V_117 * V_118 ;
int V_306 = 0 ;
F_8 ( L_104
L_105 , V_955 ,
V_156 -> args . V_973 ,
V_156 -> args . V_2 -> V_974 ) ;
if ( ! V_955 ) {
V_156 -> V_2 = F_443 ( V_156 -> args . V_2 ) ;
if ( V_156 -> V_2 == NULL ) {
F_600 ( V_156 ) ;
return - V_128 ;
}
V_317 . V_213 = V_321 ;
}
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_118 = F_73 ( & V_317 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
if ( V_955 )
V_306 = V_118 -> V_147 ;
F_603 ( V_156 -> args . V_2 , V_306 ) ;
F_8 ( L_106 , V_34 , V_306 ) ;
F_75 ( V_118 ) ;
return V_306 ;
}
static int
F_604 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_460 ,
struct V_794 * V_476 , bool V_795 )
{
struct V_975 args = {
. V_976 = V_977 ,
} ;
struct V_797 V_56 = {
. V_476 = V_476 ,
} ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_978 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
} ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_316 * V_350 = NULL ;
int V_306 ;
if ( V_795 ) {
V_55 = V_14 -> V_62 -> V_100 ;
V_350 = F_520 ( V_14 -> V_62 ) ;
V_161 . V_316 = V_350 ;
}
F_8 ( L_11 , V_34 ) ;
V_306 = F_76 ( V_55 , V_14 , & V_161 , & args . V_158 ,
& V_56 . V_159 , 0 ) ;
F_8 ( L_16 , V_34 , V_306 ) ;
if ( V_350 )
F_214 ( V_350 ) ;
return V_306 ;
}
static int
F_605 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_460 , struct V_794 * V_476 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_33 ( V_14 -> V_62 ) )
V_8 = F_604 ( V_14 , V_426 , V_460 ,
V_476 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_604 ( V_14 , V_426 , V_460 ,
V_476 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_979 :
goto V_129;
default:
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static int
F_606 ( struct V_13 * V_14 , struct V_425 * V_426 ,
struct V_459 * V_460 )
{
int V_8 ;
struct V_484 * V_484 ;
T_4 V_99 = V_980 ;
struct V_794 * V_476 ;
struct V_981 * V_982 ;
int V_473 ;
V_484 = F_279 ( V_379 ) ;
if ( ! V_484 ) {
V_8 = - V_124 ;
goto V_129;
}
V_476 = F_394 ( V_484 ) ;
V_8 = F_605 ( V_14 , V_426 , V_460 , V_476 ) ;
if ( V_8 == - V_22 || V_8 == - V_979 ) {
V_8 = F_270 ( V_14 , V_426 , V_460 ) ;
goto V_983;
}
if ( V_8 )
goto V_983;
for ( V_473 = 0 ; V_473 < V_476 -> V_984 ; V_473 ++ ) {
V_982 = & V_476 -> V_476 [ V_473 ] ;
switch ( V_982 -> V_99 ) {
case V_472 :
case V_471 :
case V_985 :
V_99 = F_607 ( V_982 -> V_99 ,
& V_982 -> V_986 ) ;
break;
default:
V_99 = V_980 ;
break;
}
if ( ! F_608 ( & V_14 -> V_474 , V_99 ) )
V_99 = V_980 ;
if ( V_99 != V_980 ) {
V_8 = F_268 ( V_14 , V_426 ,
V_460 , V_99 ) ;
if ( ! V_8 )
break;
}
}
if ( V_99 == V_980 )
V_8 = - V_24 ;
V_983:
F_408 ( V_484 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_129:
return V_8 ;
}
static int F_609 ( struct V_13 * V_14 ,
T_8 * V_251 ,
struct V_316 * V_350 )
{
int V_306 ;
struct V_987 args = {
. V_251 = V_251 ,
} ;
struct V_988 V_56 ;
struct V_160 V_161 = {
. V_311 = & V_312 [ V_989 ] ,
. V_314 = & args ,
. V_315 = & V_56 ,
. V_316 = V_350 ,
} ;
struct V_54 * V_164 = V_14 -> V_90 ;
F_257 ( V_14 -> V_62 , V_845 ,
& V_164 , & V_161 ) ;
F_8 ( L_107 , V_251 ) ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_306 = F_72 ( V_164 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_306 != V_363 ) {
F_8 ( L_108 , V_306 ) ;
return V_306 ;
}
F_8 ( L_109 , - V_56 . V_306 ) ;
return - V_56 . V_306 ;
}
static int F_211 ( struct V_13 * V_14 ,
T_8 * V_251 ,
struct V_316 * V_350 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_609 ( V_14 , V_251 , V_350 ) ;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_610 ( struct V_117 * V_118 , void * V_154 )
{
struct V_990 * V_156 = V_154 ;
F_64 ( F_67 ( V_156 -> V_14 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static void F_611 ( struct V_117 * V_118 , void * V_154 )
{
struct V_990 * V_156 = V_154 ;
F_55 ( V_118 , & V_156 -> V_56 . V_159 ) ;
switch ( V_118 -> V_147 ) {
case - V_89 :
if ( F_250 ( V_118 , V_156 -> V_14 , NULL , NULL ) == - V_128 )
F_60 ( V_118 ) ;
}
}
static void F_612 ( void * V_154 )
{
F_101 ( V_154 ) ;
}
static struct V_117 * F_613 ( struct V_13 * V_14 ,
T_8 * V_251 ,
struct V_316 * V_350 ,
bool V_991 )
{
struct V_160 V_161 = {
. V_311 = & V_312 [ V_992 ] ,
. V_316 = V_350 ,
} ;
struct V_162 V_163 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_993 ,
. V_213 = V_321 ,
} ;
struct V_990 * V_156 ;
F_257 ( V_14 -> V_62 , V_845 ,
& V_163 . V_164 , & V_161 ) ;
F_8 ( L_110 , V_251 ) ;
V_156 = F_280 ( sizeof( * V_156 ) , V_303 ) ;
if ( ! V_156 )
return F_46 ( - V_124 ) ;
V_156 -> V_14 = V_14 ;
F_130 ( & V_156 -> args . V_251 , V_251 ) ;
V_163 . V_168 = V_156 ;
V_161 . V_314 = & V_156 -> args ;
V_161 . V_315 = & V_156 -> V_56 ;
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 0 ) ;
if ( V_991 )
F_41 ( & V_156 -> args . V_158 ) ;
return F_73 ( & V_163 ) ;
}
static int F_213 ( struct V_13 * V_14 ,
T_8 * V_251 ,
struct V_316 * V_350 )
{
struct V_117 * V_118 ;
int V_51 ;
V_118 = F_613 ( V_14 , V_251 , V_350 , true ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_51 = F_113 ( V_118 ) ;
if ( ! V_51 )
V_51 = V_118 -> V_147 ;
F_75 ( V_118 ) ;
return V_51 ;
}
static void
F_614 ( struct V_13 * V_14 , struct V_281 * V_282 )
{
struct V_117 * V_118 ;
struct V_316 * V_350 = V_282 -> V_283 -> V_226 -> V_290 ;
V_118 = F_613 ( V_14 , & V_282 -> V_285 , V_350 , false ) ;
F_497 ( V_14 , V_282 ) ;
if ( F_45 ( V_118 ) )
return;
F_75 ( V_118 ) ;
}
static bool F_615 ( const T_8 * V_994 ,
const T_8 * V_995 )
{
if ( memcmp ( V_994 -> V_996 , V_995 -> V_996 , sizeof( V_994 -> V_996 ) ) != 0 )
return false ;
if ( V_994 -> V_203 == V_995 -> V_203 )
return true ;
if ( V_994 -> V_203 == 0 || V_995 -> V_203 == 0 )
return true ;
return false ;
}
static bool F_616 ( const T_8 * V_994 ,
const T_8 * V_995 )
{
return F_140 ( V_994 , V_995 ) ;
}
static struct V_217 *
F_617 ( struct V_219 * V_997 , T_6 V_998 )
{
return NULL ;
}
