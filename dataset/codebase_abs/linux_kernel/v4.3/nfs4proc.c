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
static bool F_114 ( struct V_64 * V_65 ,
T_5 V_183 )
{
switch( V_183 & ( V_71 | V_185 ) ) {
case V_71 | V_185 :
return V_65 -> V_256 != 0 ;
case V_185 :
return V_65 -> V_257 != 0 ;
case V_71 :
return V_65 -> V_258 != 0 ;
}
F_115 ( 1 ) ;
return false ;
}
static int F_116 ( struct V_64 * V_65 , T_5 V_259 , int V_260 )
{
int V_51 = 0 ;
if ( V_260 & ( V_230 | V_261 ) )
goto V_129;
switch ( V_259 & ( V_71 | V_185 ) ) {
case V_71 :
V_51 |= F_32 ( V_262 , & V_65 -> V_213 ) != 0
&& V_65 -> V_258 != 0 ;
break;
case V_185 :
V_51 |= F_32 ( V_263 , & V_65 -> V_213 ) != 0
&& V_65 -> V_257 != 0 ;
break;
case V_71 | V_185 :
V_51 |= F_32 ( V_264 , & V_65 -> V_213 ) != 0
&& V_65 -> V_256 != 0 ;
}
V_129:
return V_51 ;
}
static int F_117 ( struct V_265 * V_266 , T_5 V_183 ,
enum V_191 V_192 )
{
if ( V_266 == NULL )
return 0 ;
if ( ( V_266 -> type & V_183 ) != V_183 )
return 0 ;
if ( F_32 ( V_267 , & V_266 -> V_213 ) )
return 0 ;
switch ( V_192 ) {
case V_194 :
case V_193 :
break;
case V_246 :
if ( ! F_32 ( V_268 , & V_266 -> V_213 ) )
break;
default:
return 0 ;
}
F_118 ( V_266 ) ;
return 1 ;
}
static void F_119 ( struct V_64 * V_65 , T_5 V_183 )
{
switch ( V_183 ) {
case V_185 :
V_65 -> V_257 ++ ;
break;
case V_71 :
V_65 -> V_258 ++ ;
break;
case V_71 | V_185 :
V_65 -> V_256 ++ ;
}
F_120 ( V_65 , V_65 -> V_65 | V_183 ) ;
}
static void F_121 ( struct V_64 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_226 -> V_269 -> V_62 ;
bool V_270 = false ;
if ( F_122 ( V_262 , & V_65 -> V_213 ) && V_65 -> V_258 )
V_270 = true ;
if ( F_122 ( V_263 , & V_65 -> V_213 ) && V_65 -> V_257 )
V_270 = true ;
if ( F_122 ( V_264 , & V_65 -> V_213 ) && V_65 -> V_256 )
V_270 = true ;
if ( V_270 )
F_123 ( V_63 , V_65 ) ;
}
static bool F_124 ( struct V_64 * V_65 ,
T_8 * V_251 )
{
if ( F_125 ( V_271 , & V_65 -> V_213 ) == 0 )
return true ;
if ( ! F_126 ( V_251 , & V_65 -> V_272 ) ) {
F_121 ( V_65 ) ;
return true ;
}
if ( F_127 ( V_251 , & V_65 -> V_272 ) )
return true ;
return false ;
}
static void F_128 ( struct V_64 * V_65 )
{
if ( ! ( V_65 -> V_257 || V_65 -> V_258 || V_65 -> V_256 ) )
return;
if ( V_65 -> V_257 )
F_129 ( V_263 , & V_65 -> V_213 ) ;
if ( V_65 -> V_258 )
F_129 ( V_262 , & V_65 -> V_213 ) ;
if ( V_65 -> V_256 )
F_129 ( V_264 , & V_65 -> V_213 ) ;
F_129 ( V_271 , & V_65 -> V_213 ) ;
}
static void F_130 ( struct V_64 * V_65 ,
T_8 * V_273 ,
T_8 * V_251 , T_5 V_183 )
{
F_131 ( V_264 , & V_65 -> V_213 ) ;
switch ( V_183 & ( V_71 | V_185 ) ) {
case V_185 :
F_131 ( V_262 , & V_65 -> V_213 ) ;
break;
case V_71 :
F_131 ( V_263 , & V_65 -> V_213 ) ;
break;
case 0 :
F_131 ( V_262 , & V_65 -> V_213 ) ;
F_131 ( V_263 , & V_65 -> V_213 ) ;
F_131 ( V_271 , & V_65 -> V_213 ) ;
}
if ( V_251 == NULL )
return;
if ( ! F_126 ( V_273 , & V_65 -> V_272 ) ||
( F_126 ( V_251 , & V_65 -> V_272 ) &&
! F_127 ( V_251 , & V_65 -> V_272 ) ) ) {
F_128 ( V_65 ) ;
return;
}
if ( F_32 ( V_274 , & V_65 -> V_213 ) == 0 )
F_132 ( & V_65 -> V_251 , V_251 ) ;
F_132 ( & V_65 -> V_272 , V_251 ) ;
}
static void F_133 ( struct V_64 * V_65 ,
T_8 * V_273 ,
T_8 * V_251 , T_5 V_183 )
{
F_134 ( & V_65 -> V_275 ) ;
F_130 ( V_65 , V_273 , V_251 , V_183 ) ;
F_135 ( & V_65 -> V_275 ) ;
if ( F_32 ( V_276 , & V_65 -> V_213 ) )
F_136 ( V_65 -> V_226 -> V_269 -> V_62 ) ;
}
static void F_137 ( struct V_64 * V_65 , T_8 * V_251 , T_5 V_183 )
{
switch ( V_183 ) {
case V_71 :
F_129 ( V_262 , & V_65 -> V_213 ) ;
break;
case V_185 :
F_129 ( V_263 , & V_65 -> V_213 ) ;
break;
case V_71 | V_185 :
F_129 ( V_264 , & V_65 -> V_213 ) ;
}
if ( ! F_124 ( V_65 , V_251 ) )
return;
if ( F_32 ( V_274 , & V_65 -> V_213 ) == 0 )
F_132 ( & V_65 -> V_251 , V_251 ) ;
F_132 ( & V_65 -> V_272 , V_251 ) ;
}
static void F_138 ( struct V_64 * V_65 , T_8 * V_272 , const T_8 * V_277 , T_5 V_183 )
{
F_134 ( & V_65 -> V_275 ) ;
if ( V_277 != NULL ) {
F_132 ( & V_65 -> V_251 , V_277 ) ;
F_129 ( V_274 , & V_65 -> V_213 ) ;
}
if ( V_272 != NULL )
F_137 ( V_65 , V_272 , V_183 ) ;
F_135 ( & V_65 -> V_275 ) ;
F_35 ( & V_65 -> V_226 -> V_278 ) ;
F_119 ( V_65 , V_183 ) ;
F_37 ( & V_65 -> V_226 -> V_278 ) ;
}
static int F_139 ( struct V_64 * V_65 , T_8 * V_272 , T_8 * V_266 , T_5 V_183 )
{
struct V_171 * V_172 = F_78 ( V_65 -> V_2 ) ;
struct V_265 * V_279 ;
int V_51 = 0 ;
V_183 &= ( V_71 | V_185 ) ;
F_140 () ;
V_279 = F_141 ( V_172 -> V_266 ) ;
if ( V_279 == NULL )
goto V_280;
F_35 ( & V_279 -> V_281 ) ;
if ( F_141 ( V_172 -> V_266 ) != V_279 ||
F_32 ( V_267 , & V_279 -> V_213 ) ||
( V_279 -> type & V_183 ) != V_183 )
goto V_282;
if ( V_266 == NULL )
V_266 = & V_279 -> V_251 ;
else if ( ! F_142 ( & V_279 -> V_251 , V_266 ) )
goto V_282;
F_118 ( V_279 ) ;
F_138 ( V_65 , V_272 , & V_279 -> V_251 , V_183 ) ;
V_51 = 1 ;
V_282:
F_37 ( & V_279 -> V_281 ) ;
V_280:
F_143 () ;
if ( ! V_51 && V_272 != NULL ) {
F_138 ( V_65 , V_272 , NULL , V_183 ) ;
V_51 = 1 ;
}
if ( F_32 ( V_276 , & V_65 -> V_213 ) )
F_136 ( V_65 -> V_226 -> V_269 -> V_62 ) ;
return V_51 ;
}
static bool F_144 ( struct V_283 * V_284 ,
const T_8 * V_251 )
{
struct V_64 * V_65 = V_284 -> V_285 ;
bool V_51 = false ;
F_35 ( & V_65 -> V_286 ) ;
if ( ! F_126 ( V_251 , & V_284 -> V_287 ) )
goto V_288;
if ( ! F_127 ( V_251 , & V_284 -> V_287 ) )
goto V_288;
F_132 ( & V_284 -> V_287 , V_251 ) ;
V_51 = true ;
V_288:
F_37 ( & V_65 -> V_286 ) ;
return V_51 ;
}
static void F_145 ( struct V_2 * V_2 , T_5 V_183 )
{
struct V_265 * V_266 ;
F_140 () ;
V_266 = F_141 ( F_78 ( V_2 ) -> V_266 ) ;
if ( V_266 == NULL || ( V_266 -> type & V_183 ) == V_183 ) {
F_143 () ;
return;
}
F_143 () ;
F_23 ( V_2 ) ;
}
static struct V_64 * F_146 ( struct V_199 * V_289 )
{
struct V_64 * V_65 = V_289 -> V_65 ;
struct V_171 * V_172 = F_78 ( V_65 -> V_2 ) ;
struct V_265 * V_266 ;
int V_260 = V_289 -> V_204 . V_228 ;
T_5 V_183 = V_289 -> V_204 . V_183 ;
enum V_191 V_192 = V_289 -> V_204 . V_192 ;
T_8 V_251 ;
int V_51 = - V_128 ;
for (; ; ) {
F_35 ( & V_65 -> V_226 -> V_278 ) ;
if ( F_116 ( V_65 , V_183 , V_260 ) ) {
F_119 ( V_65 , V_183 ) ;
F_37 ( & V_65 -> V_226 -> V_278 ) ;
goto V_290;
}
F_37 ( & V_65 -> V_226 -> V_278 ) ;
F_140 () ;
V_266 = F_141 ( V_172 -> V_266 ) ;
if ( ! F_117 ( V_266 , V_183 , V_192 ) ) {
F_143 () ;
break;
}
F_132 ( & V_251 , & V_266 -> V_251 ) ;
F_143 () ;
F_147 ( V_289 -> V_204 . V_203 ) ;
if ( ! V_289 -> V_291 ) {
V_51 = F_148 ( V_65 -> V_2 , V_65 -> V_226 -> V_292 , V_260 ) ;
if ( V_51 != 0 )
goto V_129;
}
V_51 = - V_128 ;
if ( F_139 ( V_65 , NULL , & V_251 , V_183 ) )
goto V_290;
}
V_129:
return F_46 ( V_51 ) ;
V_290:
F_95 ( & V_65 -> V_49 ) ;
return V_65 ;
}
static void
F_149 ( struct V_199 * V_156 , struct V_64 * V_65 )
{
struct V_62 * V_63 = F_90 ( V_65 -> V_2 ) -> V_62 ;
struct V_265 * V_266 ;
int V_293 = 0 ;
F_140 () ;
V_266 = F_141 ( F_78 ( V_65 -> V_2 ) -> V_266 ) ;
if ( V_266 )
V_293 = V_266 -> V_213 ;
F_143 () ;
switch ( V_156 -> V_204 . V_192 ) {
default:
break;
case V_196 :
case V_195 :
F_150 ( L_18
L_19
L_20 ,
V_63 -> V_96 ) ;
return;
}
if ( ( V_293 & 1UL << V_268 ) == 0 )
F_151 ( V_65 -> V_2 ,
V_156 -> V_226 -> V_292 ,
& V_156 -> V_200 ) ;
else
F_152 ( V_65 -> V_2 ,
V_156 -> V_226 -> V_292 ,
& V_156 -> V_200 ) ;
}
static struct V_64 *
F_153 ( struct V_199 * V_156 )
{
struct V_2 * V_2 = V_156 -> V_65 -> V_2 ;
struct V_64 * V_65 = V_156 -> V_65 ;
int V_51 ;
if ( ! V_156 -> V_294 ) {
if ( V_156 -> V_295 ) {
V_51 = V_156 -> V_295 ;
goto V_8;
}
goto V_296;
}
V_51 = F_154 ( V_2 , & V_156 -> V_201 ) ;
if ( V_51 )
goto V_8;
if ( V_156 -> V_200 . V_297 != 0 )
F_149 ( V_156 , V_65 ) ;
V_296:
F_139 ( V_65 , & V_156 -> V_200 . V_251 , NULL ,
V_156 -> V_204 . V_183 ) ;
F_95 ( & V_65 -> V_49 ) ;
return V_65 ;
V_8:
return F_46 ( V_51 ) ;
}
static struct V_64 *
F_155 ( struct V_199 * V_156 )
{
struct V_2 * V_2 ;
struct V_64 * V_65 = NULL ;
int V_51 ;
if ( ! V_156 -> V_294 ) {
V_65 = F_146 ( V_156 ) ;
goto V_129;
}
V_51 = - V_128 ;
if ( ! ( V_156 -> V_201 . V_298 & V_299 ) )
goto V_8;
V_2 = F_156 ( V_156 -> V_3 -> V_225 , & V_156 -> V_200 . V_245 , & V_156 -> V_201 , V_156 -> V_202 ) ;
V_51 = F_74 ( V_2 ) ;
if ( F_45 ( V_2 ) )
goto V_8;
V_51 = - V_124 ;
V_65 = F_157 ( V_2 , V_156 -> V_226 ) ;
if ( V_65 == NULL )
goto V_300;
if ( V_156 -> V_200 . V_297 != 0 )
F_149 ( V_156 , V_65 ) ;
F_139 ( V_65 , & V_156 -> V_200 . V_251 , NULL ,
V_156 -> V_204 . V_183 ) ;
F_158 ( V_2 ) ;
V_129:
F_147 ( V_156 -> V_204 . V_203 ) ;
return V_65 ;
V_300:
F_158 ( V_2 ) ;
V_8:
return F_46 ( V_51 ) ;
}
static struct V_64 *
F_159 ( struct V_199 * V_156 )
{
if ( V_156 -> V_204 . V_192 == V_246 )
return F_153 ( V_156 ) ;
return F_155 ( V_156 ) ;
}
static struct V_301 * F_160 ( struct V_64 * V_65 )
{
struct V_171 * V_172 = F_78 ( V_65 -> V_2 ) ;
struct V_301 * V_302 ;
F_35 ( & V_65 -> V_2 -> V_173 ) ;
F_161 (ctx, &nfsi->open_files, list) {
if ( V_302 -> V_65 != V_65 )
continue;
F_162 ( V_302 ) ;
F_37 ( & V_65 -> V_2 -> V_173 ) ;
return V_302 ;
}
F_37 ( & V_65 -> V_2 -> V_173 ) ;
return F_46 ( - V_303 ) ;
}
static struct V_199 * F_163 ( struct V_301 * V_302 ,
struct V_64 * V_65 , enum V_191 V_192 )
{
struct V_199 * V_289 ;
V_289 = F_88 ( V_302 -> V_4 , V_65 -> V_226 , 0 , 0 ,
NULL , NULL , V_192 , V_304 ) ;
if ( V_289 == NULL )
return F_46 ( - V_124 ) ;
V_289 -> V_65 = V_65 ;
F_95 ( & V_65 -> V_49 ) ;
return V_289 ;
}
static int F_164 ( struct V_199 * V_289 ,
T_5 V_183 )
{
struct V_64 * V_305 ;
int V_51 ;
if ( ! F_114 ( V_289 -> V_65 , V_183 ) )
return 0 ;
V_289 -> V_204 . V_228 = 0 ;
V_289 -> V_204 . V_183 = V_183 ;
V_289 -> V_204 . V_229 = F_83 (
F_165 ( V_289 -> V_4 -> V_225 ) ,
V_183 , 0 ) ;
memset ( & V_289 -> V_200 , 0 , sizeof( V_289 -> V_200 ) ) ;
memset ( & V_289 -> V_205 , 0 , sizeof( V_289 -> V_205 ) ) ;
F_85 ( V_289 ) ;
V_51 = F_166 ( V_289 ) ;
if ( V_51 != 0 )
return V_51 ;
V_305 = F_159 ( V_289 ) ;
if ( F_45 ( V_305 ) )
return F_74 ( V_305 ) ;
if ( V_305 != V_289 -> V_65 )
V_51 = - V_306 ;
F_167 ( V_305 , V_183 ) ;
return V_51 ;
}
static int F_168 ( struct V_199 * V_289 , struct V_64 * V_65 )
{
int V_51 ;
F_131 ( V_264 , & V_65 -> V_213 ) ;
F_131 ( V_263 , & V_65 -> V_213 ) ;
F_131 ( V_262 , & V_65 -> V_213 ) ;
F_131 ( V_274 , & V_65 -> V_213 ) ;
F_131 ( V_271 , & V_65 -> V_213 ) ;
F_169 () ;
V_51 = F_164 ( V_289 , V_71 | V_185 ) ;
if ( V_51 != 0 )
return V_51 ;
V_51 = F_164 ( V_289 , V_185 ) ;
if ( V_51 != 0 )
return V_51 ;
V_51 = F_164 ( V_289 , V_71 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( F_32 ( V_274 , & V_65 -> V_213 ) == 0 &&
! F_142 ( & V_65 -> V_251 , & V_65 -> V_272 ) ) {
F_134 ( & V_65 -> V_275 ) ;
if ( F_32 ( V_274 , & V_65 -> V_213 ) == 0 )
F_132 ( & V_65 -> V_251 , & V_65 -> V_272 ) ;
F_135 ( & V_65 -> V_275 ) ;
}
return 0 ;
}
static int F_170 ( struct V_301 * V_302 , struct V_64 * V_65 )
{
struct V_265 * V_266 ;
struct V_199 * V_289 ;
T_5 V_297 = 0 ;
int V_307 ;
V_289 = F_163 ( V_302 , V_65 ,
V_246 ) ;
if ( F_45 ( V_289 ) )
return F_74 ( V_289 ) ;
F_140 () ;
V_266 = F_141 ( F_78 ( V_65 -> V_2 ) -> V_266 ) ;
if ( V_266 != NULL && F_32 ( V_268 , & V_266 -> V_213 ) != 0 )
V_297 = V_266 -> type ;
F_143 () ;
V_289 -> V_204 . V_249 . V_297 = V_297 ;
V_307 = F_168 ( V_289 , V_65 ) ;
F_110 ( V_289 ) ;
return V_307 ;
}
static int F_171 ( struct V_301 * V_302 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_170 ( V_302 , V_65 ) ;
F_172 ( V_302 , 0 , V_8 ) ;
if ( F_82 ( V_14 , V_8 , & V_61 ) )
continue;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_173 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
struct V_301 * V_302 ;
int V_51 ;
V_302 = F_160 ( V_65 ) ;
if ( F_45 ( V_302 ) )
return - V_128 ;
V_51 = F_171 ( V_302 , V_65 ) ;
F_174 ( V_302 ) ;
return V_51 ;
}
static int F_175 ( struct V_13 * V_14 , struct V_64 * V_65 , const T_8 * V_251 , int V_8 )
{
switch ( V_8 ) {
default:
F_30 ( V_308 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_303 :
case - V_128 :
case - V_306 :
break;
case - V_79 :
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
F_129 ( V_274 , & V_65 -> V_213 ) ;
F_29 ( V_14 -> V_62 -> V_86 , V_8 ) ;
return - V_128 ;
case - V_75 :
case - V_74 :
F_129 ( V_274 , & V_65 -> V_213 ) ;
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
F_176 ( V_65 -> V_2 ,
V_251 ) ;
F_24 ( V_14 , V_65 ) ;
return - V_128 ;
case - V_89 :
case - V_88 :
F_129 ( V_274 , & V_65 -> V_213 ) ;
F_177 ( 1 ) ;
return - V_128 ;
case - V_124 :
case - V_309 :
return 0 ;
}
return V_8 ;
}
int F_178 ( struct V_301 * V_302 ,
struct V_64 * V_65 , const T_8 * V_251 ,
T_5 type )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_199 * V_289 ;
int V_8 = 0 ;
V_289 = F_163 ( V_302 , V_65 ,
V_195 ) ;
if ( F_45 ( V_289 ) )
return F_74 ( V_289 ) ;
F_132 ( & V_289 -> V_204 . V_249 . V_266 , V_251 ) ;
F_134 ( & V_65 -> V_275 ) ;
F_132 ( & V_65 -> V_251 , & V_65 -> V_272 ) ;
F_135 ( & V_65 -> V_275 ) ;
F_131 ( V_274 , & V_65 -> V_213 ) ;
switch ( type & ( V_71 | V_185 ) ) {
case V_71 | V_185 :
case V_185 :
V_8 = F_164 ( V_289 , V_71 | V_185 ) ;
if ( V_8 )
break;
V_8 = F_164 ( V_289 , V_185 ) ;
if ( V_8 )
break;
case V_71 :
V_8 = F_164 ( V_289 , V_71 ) ;
}
F_110 ( V_289 ) ;
return F_175 ( V_14 , V_65 , V_251 , V_8 ) ;
}
static void F_179 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
F_42 ( V_156 -> V_204 . V_14 -> V_62 -> V_153 ,
& V_156 -> V_206 . V_158 , & V_156 -> V_205 . V_159 , V_118 ) ;
}
static void F_180 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
F_50 ( V_118 , & V_156 -> V_205 . V_159 ) ;
V_156 -> V_295 = V_118 -> V_147 ;
if ( V_156 -> V_295 == 0 ) {
F_132 ( & V_156 -> V_200 . V_251 , & V_156 -> V_205 . V_251 ) ;
F_181 ( & V_156 -> V_226 -> V_223 , 0 ) ;
F_38 ( V_156 -> V_200 . V_14 , V_156 -> V_105 ) ;
V_156 -> V_294 = 1 ;
}
}
static void F_182 ( void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_64 * V_65 = NULL ;
if ( V_156 -> V_310 == 0 )
goto V_311;
if ( ! V_156 -> V_294 )
goto V_311;
V_65 = F_159 ( V_156 ) ;
if ( ! F_45 ( V_65 ) )
F_167 ( V_65 , V_156 -> V_204 . V_183 ) ;
V_311:
F_110 ( V_156 ) ;
}
static int F_183 ( struct V_199 * V_156 )
{
struct V_13 * V_14 = F_90 ( F_14 ( V_156 -> V_3 ) ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_314 ] ,
. V_315 = & V_156 -> V_206 ,
. V_316 = & V_156 -> V_205 ,
. V_317 = V_156 -> V_226 -> V_292 ,
} ;
struct V_162 V_318 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_319 ,
. V_168 = V_156 ,
. V_320 = V_321 ,
. V_213 = V_322 ,
} ;
int V_307 ;
F_40 ( & V_156 -> V_206 . V_158 , & V_156 -> V_205 . V_159 , 1 ) ;
F_184 ( & V_156 -> V_252 ) ;
V_156 -> V_294 = 0 ;
V_156 -> V_295 = 0 ;
V_156 -> V_105 = V_152 ;
if ( V_156 -> V_291 )
F_41 ( & V_156 -> V_206 . V_158 ) ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_307 = F_112 ( V_118 ) ;
if ( V_307 != 0 ) {
V_156 -> V_310 = 1 ;
F_185 () ;
} else
V_307 = V_156 -> V_295 ;
F_75 ( V_118 ) ;
return V_307 ;
}
static void F_186 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_211 * V_212 = V_156 -> V_226 ;
struct V_62 * V_63 = V_212 -> V_269 -> V_62 ;
enum V_191 V_192 = V_156 -> V_204 . V_192 ;
if ( F_187 ( V_156 -> V_204 . V_203 , V_118 ) != 0 )
goto V_323;
if ( V_156 -> V_65 != NULL ) {
struct V_265 * V_266 ;
if ( F_116 ( V_156 -> V_65 , V_156 -> V_204 . V_183 , V_156 -> V_204 . V_228 ) )
goto V_324;
F_140 () ;
V_266 = F_141 ( F_78 ( V_156 -> V_65 -> V_2 ) -> V_266 ) ;
if ( F_117 ( V_266 , V_156 -> V_204 . V_183 , V_192 ) )
goto V_325;
F_143 () ;
}
V_156 -> V_204 . V_235 = V_63 -> V_236 ;
switch ( V_192 ) {
default:
break;
case V_246 :
case V_195 :
case V_197 :
V_156 -> V_204 . V_243 = & V_326 [ 0 ] ;
case V_193 :
V_118 -> V_327 . V_312 = & V_313 [ V_328 ] ;
F_188 ( & V_156 -> V_200 . V_245 , V_156 -> V_204 . V_245 ) ;
}
V_156 -> V_105 = V_152 ;
if ( F_66 ( V_156 -> V_204 . V_14 ,
& V_156 -> V_204 . V_158 ,
& V_156 -> V_200 . V_159 ,
V_118 ) != 0 )
F_147 ( V_156 -> V_204 . V_203 ) ;
V_156 -> V_204 . V_329 = V_330 ;
if ( V_156 -> V_204 . V_228 & V_230 ) {
V_156 -> V_204 . V_329 = V_331 ;
if ( F_189 ( V_63 ) )
V_156 -> V_204 . V_329 = V_332 ;
else if ( V_63 -> V_166 -> V_333 > 0 )
V_156 -> V_204 . V_329 = V_334 ;
}
return;
V_325:
F_143 () ;
V_324:
V_118 -> V_335 = NULL ;
V_323:
F_63 ( V_118 , & V_156 -> V_200 . V_159 ) ;
}
static void F_190 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
V_156 -> V_295 = V_118 -> V_147 ;
if ( ! F_63 ( V_118 , & V_156 -> V_200 . V_159 ) )
return;
if ( V_118 -> V_147 == 0 ) {
if ( V_156 -> V_200 . V_201 -> V_298 & V_336 ) {
switch ( V_156 -> V_200 . V_201 -> V_259 & V_337 ) {
case V_338 :
break;
case V_339 :
V_156 -> V_295 = - V_340 ;
break;
case V_341 :
V_156 -> V_295 = - V_342 ;
break;
default:
V_156 -> V_295 = - V_343 ;
}
}
F_38 ( V_156 -> V_200 . V_14 , V_156 -> V_105 ) ;
if ( ! ( V_156 -> V_200 . V_344 & V_345 ) )
F_181 ( & V_156 -> V_226 -> V_223 , 0 ) ;
}
V_156 -> V_294 = 1 ;
}
static void F_191 ( void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_64 * V_65 = NULL ;
if ( V_156 -> V_310 == 0 )
goto V_311;
if ( V_156 -> V_295 != 0 || ! V_156 -> V_294 )
goto V_311;
if ( V_156 -> V_200 . V_344 & V_345 )
goto V_311;
V_65 = F_159 ( V_156 ) ;
if ( ! F_45 ( V_65 ) )
F_167 ( V_65 , V_156 -> V_204 . V_183 ) ;
V_311:
F_110 ( V_156 ) ;
}
static int F_192 ( struct V_199 * V_156 , int V_346 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_347 * V_204 = & V_156 -> V_204 ;
struct V_348 * V_200 = & V_156 -> V_200 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_349 ] ,
. V_315 = V_204 ,
. V_316 = V_200 ,
. V_317 = V_156 -> V_226 -> V_292 ,
} ;
struct V_162 V_318 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_350 ,
. V_168 = V_156 ,
. V_320 = V_321 ,
. V_213 = V_322 ,
} ;
int V_307 ;
F_40 ( & V_204 -> V_158 , & V_200 -> V_159 , 1 ) ;
F_184 ( & V_156 -> V_252 ) ;
V_156 -> V_294 = 0 ;
V_156 -> V_295 = 0 ;
V_156 -> V_310 = 0 ;
V_156 -> V_291 = 0 ;
if ( V_346 ) {
F_41 ( & V_204 -> V_158 ) ;
V_156 -> V_291 = 1 ;
}
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_307 = F_112 ( V_118 ) ;
if ( V_307 != 0 ) {
V_156 -> V_310 = 1 ;
F_185 () ;
} else
V_307 = V_156 -> V_295 ;
F_75 ( V_118 ) ;
return V_307 ;
}
static int F_166 ( struct V_199 * V_156 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_348 * V_200 = & V_156 -> V_200 ;
int V_307 ;
V_307 = F_192 ( V_156 , 1 ) ;
if ( V_307 != 0 || ! V_156 -> V_294 )
return V_307 ;
F_193 ( F_90 ( V_3 ) , & V_156 -> V_201 ) ;
if ( V_200 -> V_344 & V_345 ) {
V_307 = F_183 ( V_156 ) ;
if ( V_307 != 0 )
return V_307 ;
}
return V_307 ;
}
static int F_194 ( struct V_317 * V_351 ,
struct V_199 * V_289 ,
struct V_64 * V_65 , T_5 V_183 ,
int V_184 )
{
struct V_352 V_353 ;
T_1 V_354 ;
if ( V_289 -> V_200 . V_355 == 0 )
return 0 ;
V_354 = 0 ;
if ( V_184 & V_356 ) {
V_354 = V_357 ;
} else if ( ( V_183 & V_71 ) && ! V_289 -> V_358 )
V_354 = V_359 ;
V_353 . V_351 = V_351 ;
V_353 . V_152 = V_152 ;
F_195 ( & V_353 , V_289 -> V_200 . V_360 ) ;
F_196 ( V_65 -> V_2 , & V_353 ) ;
if ( ( V_354 & ~ V_353 . V_354 & ( V_359 | V_357 ) ) == 0 )
return 0 ;
F_167 ( V_65 , V_183 ) ;
return - V_29 ;
}
static int F_197 ( struct V_199 * V_156 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_347 * V_204 = & V_156 -> V_204 ;
struct V_348 * V_200 = & V_156 -> V_200 ;
int V_307 ;
V_307 = F_192 ( V_156 , 0 ) ;
if ( ! V_156 -> V_294 )
return V_307 ;
if ( V_307 != 0 ) {
if ( V_307 == - V_26 &&
! ( V_204 -> V_228 & V_361 ) )
return - V_303 ;
return V_307 ;
}
F_193 ( V_14 , & V_156 -> V_201 ) ;
if ( V_204 -> V_228 & V_361 ) {
F_77 ( V_3 , & V_200 -> V_170 ) ;
if ( V_204 -> V_228 & V_230 )
V_156 -> V_358 = 1 ;
else if ( V_200 -> V_170 . V_178 != V_200 -> V_170 . V_180 )
V_156 -> V_358 = 1 ;
}
if ( ( V_200 -> V_344 & V_362 ) == 0 )
V_14 -> V_93 &= ~ V_363 ;
if( V_200 -> V_344 & V_345 ) {
V_307 = F_183 ( V_156 ) ;
if ( V_307 != 0 )
return V_307 ;
}
if ( ! ( V_200 -> V_201 -> V_298 & V_299 ) )
F_198 ( V_14 , & V_200 -> V_245 , V_200 -> V_201 , V_200 -> V_202 ) ;
return 0 ;
}
static int F_199 ( struct V_13 * V_14 )
{
return F_200 ( V_14 -> V_62 ) ;
}
static int F_201 ( struct V_301 * V_302 , struct V_64 * V_65 )
{
struct V_199 * V_289 ;
int V_51 ;
V_289 = F_163 ( V_302 , V_65 ,
V_193 ) ;
if ( F_45 ( V_289 ) )
return F_74 ( V_289 ) ;
V_51 = F_168 ( V_289 , V_65 ) ;
if ( V_51 == - V_306 )
F_202 ( V_302 -> V_4 ) ;
F_110 ( V_289 ) ;
return V_51 ;
}
static int F_203 ( struct V_301 * V_302 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_201 ( V_302 , V_65 ) ;
F_204 ( V_302 , 0 , V_8 ) ;
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
static int F_205 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
struct V_301 * V_302 ;
int V_51 ;
V_302 = F_160 ( V_65 ) ;
if ( F_45 ( V_302 ) )
return - V_128 ;
V_51 = F_203 ( V_302 , V_65 ) ;
F_174 ( V_302 ) ;
return V_51 ;
}
static void F_206 ( struct V_64 * V_65 )
{
F_207 ( V_65 -> V_2 ) ;
F_134 ( & V_65 -> V_275 ) ;
F_132 ( & V_65 -> V_251 , & V_65 -> V_272 ) ;
F_135 ( & V_65 -> V_275 ) ;
F_131 ( V_274 , & V_65 -> V_213 ) ;
}
static void F_208 ( struct V_64 * V_65 )
{
if ( F_209 ( F_78 ( V_65 -> V_2 ) -> V_266 ) != NULL )
F_206 ( V_65 ) ;
}
static int F_210 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
F_208 ( V_65 ) ;
return F_205 ( V_212 , V_65 ) ;
}
static void F_211 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
T_8 V_251 ;
struct V_265 * V_266 ;
struct V_317 * V_351 ;
int V_307 ;
F_140 () ;
V_266 = F_141 ( F_78 ( V_65 -> V_2 ) -> V_266 ) ;
if ( V_266 == NULL ) {
F_143 () ;
return;
}
F_132 ( & V_251 , & V_266 -> V_251 ) ;
V_351 = F_212 ( V_266 -> V_351 ) ;
F_143 () ;
V_307 = F_213 ( V_14 , & V_251 , V_351 ) ;
F_214 ( V_65 , NULL , V_307 ) ;
if ( V_307 != V_364 ) {
if ( V_307 != - V_70 )
F_215 ( V_14 , & V_251 , V_351 ) ;
F_206 ( V_65 ) ;
}
F_216 ( V_351 ) ;
}
static int F_217 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
T_8 * V_251 = & V_65 -> V_272 ;
struct V_317 * V_351 = V_65 -> V_226 -> V_292 ;
int V_307 ;
if ( ( F_32 ( V_262 , & V_65 -> V_213 ) == 0 ) &&
( F_32 ( V_263 , & V_65 -> V_213 ) == 0 ) &&
( F_32 ( V_264 , & V_65 -> V_213 ) == 0 ) )
return - V_70 ;
V_307 = F_213 ( V_14 , V_251 , V_351 ) ;
F_218 ( V_65 , NULL , V_307 ) ;
if ( V_307 != V_364 ) {
if ( V_307 != - V_70 )
F_215 ( V_14 , V_251 , V_351 ) ;
F_131 ( V_262 , & V_65 -> V_213 ) ;
F_131 ( V_263 , & V_65 -> V_213 ) ;
F_131 ( V_264 , & V_65 -> V_213 ) ;
F_131 ( V_271 , & V_65 -> V_213 ) ;
}
return V_307 ;
}
static int F_219 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
int V_307 ;
F_211 ( V_65 ) ;
V_307 = F_217 ( V_65 ) ;
if ( V_307 != V_364 )
V_307 = F_205 ( V_212 , V_65 ) ;
return V_307 ;
}
static inline void F_220 ( struct V_199 * V_289 ,
struct V_5 * V_6 , struct V_1 * * V_7 )
{
const T_1 * V_365 = V_289 -> V_200 . V_365 ;
if ( ( V_365 [ 1 ] & V_366 ) &&
! ( V_6 -> V_247 & V_367 ) )
V_6 -> V_247 |= V_368 ;
if ( ( V_365 [ 1 ] & V_369 ) &&
! ( V_6 -> V_247 & V_370 ) )
V_6 -> V_247 |= V_371 ;
if ( ( V_365 [ 1 ] & V_372 ) )
V_6 -> V_247 &= ~ V_373 ;
if ( V_365 [ 2 ] & V_374 )
* V_7 = NULL ;
}
static int F_221 ( struct V_199 * V_289 ,
T_5 V_183 ,
int V_213 ,
struct V_301 * V_302 )
{
struct V_211 * V_212 = V_289 -> V_226 ;
struct V_13 * V_14 = V_212 -> V_269 ;
struct V_4 * V_4 ;
struct V_64 * V_65 ;
unsigned int V_375 ;
int V_51 ;
V_375 = F_222 ( & V_212 -> V_376 ) ;
V_51 = F_197 ( V_289 ) ;
if ( V_51 != 0 )
goto V_129;
V_65 = F_159 ( V_289 ) ;
V_51 = F_74 ( V_65 ) ;
if ( F_45 ( V_65 ) )
goto V_129;
if ( V_14 -> V_93 & V_363 )
F_129 ( V_377 , & V_65 -> V_213 ) ;
V_4 = V_289 -> V_4 ;
if ( F_223 ( V_4 ) ) {
F_202 ( V_4 ) ;
V_4 = F_224 ( V_4 , F_225 ( V_65 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_289 -> V_4 ;
} else if ( V_4 != V_302 -> V_4 ) {
F_102 ( V_302 -> V_4 ) ;
V_302 -> V_4 = F_94 ( V_4 ) ;
}
F_226 ( V_4 ,
F_227 ( F_14 ( V_289 -> V_3 ) ) ) ;
}
V_51 = F_194 ( V_212 -> V_292 , V_289 , V_65 , V_183 , V_213 ) ;
if ( V_51 != 0 )
goto V_129;
V_302 -> V_65 = V_65 ;
if ( F_14 ( V_4 ) == V_65 -> V_2 ) {
F_228 ( V_302 ) ;
if ( F_229 ( & V_212 -> V_376 , V_375 ) )
F_24 ( V_14 , V_65 ) ;
}
V_129:
return V_51 ;
}
static int F_230 ( struct V_2 * V_3 ,
struct V_301 * V_302 ,
int V_213 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_378 )
{
struct V_211 * V_212 ;
struct V_64 * V_65 = NULL ;
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_199 * V_289 ;
struct V_4 * V_4 = V_302 -> V_4 ;
struct V_317 * V_351 = V_302 -> V_351 ;
struct V_379 * * V_380 = & V_302 -> V_255 ;
T_5 V_183 = V_302 -> V_259 & ( V_71 | V_185 | V_381 ) ;
enum V_191 V_192 = V_194 ;
struct V_1 * V_382 = NULL ;
int V_307 ;
V_307 = - V_124 ;
V_212 = F_231 ( V_14 , V_351 , V_383 ) ;
if ( V_212 == NULL ) {
F_8 ( L_23 ) ;
goto V_384;
}
V_307 = F_199 ( V_14 ) ;
if ( V_307 != 0 )
goto V_385;
if ( F_232 ( V_4 ) )
F_145 ( F_14 ( V_4 ) , V_183 ) ;
V_307 = - V_124 ;
if ( F_232 ( V_4 ) )
V_192 = V_193 ;
V_289 = F_88 ( V_4 , V_212 , V_183 , V_213 , V_6 ,
V_7 , V_192 , V_383 ) ;
if ( V_289 == NULL )
goto V_385;
if ( V_7 ) {
V_382 = F_92 ( V_14 , V_383 ) ;
if ( F_45 ( V_382 ) ) {
V_307 = F_74 ( V_382 ) ;
goto V_386;
}
}
if ( V_14 -> V_15 [ 2 ] & V_387 ) {
if ( ! V_289 -> V_201 . V_255 ) {
V_289 -> V_201 . V_255 = F_233 () ;
if ( ! V_289 -> V_201 . V_255 )
goto V_224;
}
V_289 -> V_204 . V_243 = & V_388 [ 0 ] ;
}
if ( F_232 ( V_4 ) )
V_289 -> V_65 = F_157 ( F_14 ( V_4 ) , V_212 ) ;
V_307 = F_221 ( V_289 , V_183 , V_213 , V_302 ) ;
if ( V_307 != 0 )
goto V_224;
V_65 = V_302 -> V_65 ;
if ( ( V_289 -> V_204 . V_228 & ( V_361 | V_230 ) ) == ( V_361 | V_230 ) &&
( V_289 -> V_204 . V_329 != V_332 ) ) {
F_220 ( V_289 , V_6 , & V_7 ) ;
F_86 ( V_289 -> V_200 . V_201 ) ;
V_307 = F_234 ( V_65 -> V_2 , V_351 ,
V_289 -> V_200 . V_201 , V_6 ,
V_65 , V_7 , V_382 ) ;
if ( V_307 == 0 ) {
F_235 ( V_65 -> V_2 , V_6 ,
V_289 -> V_200 . V_201 ) ;
F_236 ( V_65 -> V_2 , V_289 -> V_200 . V_201 , V_382 ) ;
}
}
if ( V_378 && V_289 -> V_358 )
* V_378 |= V_389 ;
if ( F_237 ( V_380 , V_289 -> V_201 . V_255 , V_14 ) ) {
* V_380 = V_289 -> V_201 . V_255 ;
V_289 -> V_201 . V_255 = NULL ;
}
F_100 ( V_382 ) ;
F_110 ( V_289 ) ;
F_107 ( V_212 ) ;
return 0 ;
V_224:
F_100 ( V_382 ) ;
V_386:
F_110 ( V_289 ) ;
V_385:
F_107 ( V_212 ) ;
V_384:
return V_307 ;
}
static struct V_64 * F_238 ( struct V_2 * V_3 ,
struct V_301 * V_302 ,
int V_213 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_378 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_60 V_61 = { } ;
struct V_64 * V_56 ;
int V_307 ;
do {
V_307 = F_230 ( V_3 , V_302 , V_213 , V_6 , V_7 , V_378 ) ;
V_56 = V_302 -> V_65 ;
F_239 ( V_302 , V_213 , V_307 ) ;
if ( V_307 == 0 )
break;
if ( V_307 == - V_390 ) {
F_240 ( L_5
L_24 ,
F_90 ( V_3 ) -> V_62 -> V_96 ) ;
V_61 . V_66 = 1 ;
continue;
}
if ( V_307 == - V_70 ) {
V_61 . V_66 = 1 ;
continue;
}
if ( V_307 == - V_128 ) {
V_61 . V_66 = 1 ;
continue;
}
if ( F_82 ( V_14 , V_307 , & V_61 ) )
continue;
V_56 = F_46 ( F_21 ( V_14 ,
V_307 , & V_61 ) ) ;
} while ( V_61 . V_66 );
return V_56 ;
}
static int F_241 ( struct V_2 * V_2 , struct V_317 * V_351 ,
struct V_391 * V_392 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_393 ,
struct V_1 * V_382 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_394 V_395 = {
. V_245 = F_98 ( V_2 ) ,
. V_396 = V_6 ,
. V_14 = V_14 ,
. V_242 = V_14 -> V_15 ,
. V_7 = V_393 ,
} ;
struct V_397 V_56 = {
. V_392 = V_392 ,
. V_7 = V_382 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_398 ] ,
. V_315 = & V_395 ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
unsigned long V_105 = V_152 ;
T_5 V_183 ;
bool V_399 ;
int V_307 ;
V_395 . V_242 = F_6 ( V_14 , V_393 ) ;
if ( V_393 )
V_395 . V_242 = F_6 ( V_14 , V_382 ) ;
F_86 ( V_392 ) ;
V_399 = ( V_6 -> V_247 & V_400 ) ? true : false ;
V_183 = V_399 ? V_185 : V_71 ;
if ( F_242 ( & V_395 . V_251 , V_2 , V_183 ) ) {
} else if ( V_399 && V_65 != NULL ) {
struct V_401 V_402 = {
. V_403 = V_57 -> V_404 ,
. V_405 = V_57 -> V_406 ,
} ;
if ( ! F_243 ( V_65 ) )
return - V_407 ;
if ( F_244 ( & V_395 . V_251 , V_65 , V_185 ,
& V_402 ) == - V_35 )
return - V_407 ;
} else
F_132 ( & V_395 . V_251 , & V_408 ) ;
V_307 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_395 . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_307 == 0 && V_65 != NULL )
F_38 ( V_14 , V_105 ) ;
return V_307 ;
}
static int F_234 ( struct V_2 * V_2 , struct V_317 * V_351 ,
struct V_391 * V_392 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_393 ,
struct V_1 * V_382 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_241 ( V_2 , V_351 , V_392 , V_6 , V_65 , V_393 , V_382 ) ;
F_245 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_67 :
if ( ! ( V_6 -> V_247 & V_400 ) ) {
F_246 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_62 -> V_96 ) ;
}
if ( V_65 && ! ( V_65 -> V_65 & V_185 ) ) {
V_8 = - V_407 ;
if ( V_6 -> V_247 & V_409 )
V_8 = - V_29 ;
goto V_129;
}
}
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static bool
F_247 ( struct V_2 * V_2 , struct V_117 * V_118 )
{
if ( V_2 == NULL || ! F_248 ( V_2 ) )
return false ;
return F_249 ( V_2 , V_118 ) ;
}
static void F_250 ( void * V_156 )
{
struct V_410 * V_154 = V_156 ;
struct V_211 * V_212 = V_154 -> V_65 -> V_226 ;
struct V_253 * V_254 = V_154 -> V_65 -> V_2 -> V_411 ;
if ( V_154 -> V_412 )
F_251 ( V_154 -> V_65 -> V_2 ) ;
F_106 ( V_154 -> V_65 ) ;
F_105 ( V_154 -> V_395 . V_203 ) ;
F_107 ( V_212 ) ;
F_108 ( V_254 ) ;
F_101 ( V_154 ) ;
}
static void F_252 ( struct V_117 * V_118 , void * V_156 )
{
struct V_410 * V_154 = V_156 ;
struct V_64 * V_65 = V_154 -> V_65 ;
struct V_13 * V_14 = F_90 ( V_154 -> V_2 ) ;
T_8 * V_413 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_63 ( V_118 , & V_154 -> V_56 . V_159 ) )
return;
F_253 ( V_65 , & V_154 -> V_395 , & V_154 -> V_56 , V_118 -> V_147 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
V_413 = & V_154 -> V_56 . V_251 ;
if ( V_154 -> V_412 )
F_254 ( V_65 -> V_2 ,
V_154 -> V_414 ) ;
F_38 ( V_14 , V_154 -> V_105 ) ;
break;
case - V_69 :
case - V_74 :
case - V_92 :
case - V_70 :
case - V_73 :
if ( ! F_142 ( & V_154 -> V_395 . V_251 ,
& V_65 -> V_272 ) ) {
F_60 ( V_118 ) ;
goto V_415;
}
if ( V_154 -> V_395 . V_183 == 0 )
break;
default:
if ( F_255 ( V_118 , V_14 , V_65 , NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
goto V_415;
}
}
F_133 ( V_65 , & V_154 -> V_395 . V_251 ,
V_413 , V_154 -> V_395 . V_183 ) ;
V_415:
F_147 ( V_154 -> V_395 . V_203 ) ;
F_154 ( V_154 -> V_2 , V_154 -> V_56 . V_392 ) ;
F_8 ( L_30 , V_34 , V_118 -> V_147 ) ;
}
static void F_256 ( struct V_117 * V_118 , void * V_156 )
{
struct V_410 * V_154 = V_156 ;
struct V_64 * V_65 = V_154 -> V_65 ;
struct V_2 * V_2 = V_154 -> V_2 ;
bool V_416 , V_417 , V_418 ;
int V_419 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_187 ( V_154 -> V_395 . V_203 , V_118 ) != 0 )
goto V_323;
V_118 -> V_327 . V_312 = & V_313 [ V_420 ] ;
F_35 ( & V_65 -> V_226 -> V_278 ) ;
V_418 = F_32 ( V_264 , & V_65 -> V_213 ) ;
V_416 = F_32 ( V_262 , & V_65 -> V_213 ) ;
V_417 = F_32 ( V_263 , & V_65 -> V_213 ) ;
F_132 ( & V_154 -> V_395 . V_251 , & V_65 -> V_272 ) ;
V_154 -> V_395 . V_183 = 0 ;
if ( V_65 -> V_256 == 0 ) {
if ( V_65 -> V_258 == 0 )
V_419 |= V_416 ;
else if ( V_416 )
V_154 -> V_395 . V_183 |= V_71 ;
if ( V_65 -> V_257 == 0 )
V_419 |= V_417 ;
else if ( V_417 )
V_154 -> V_395 . V_183 |= V_185 ;
} else if ( V_418 )
V_154 -> V_395 . V_183 |= V_71 | V_185 ;
if ( V_154 -> V_395 . V_183 == 0 )
V_419 |= V_418 ;
if ( ! F_243 ( V_65 ) )
V_419 = 0 ;
F_37 ( & V_65 -> V_226 -> V_278 ) ;
if ( ! V_419 ) {
goto V_324;
}
if ( F_247 ( V_2 , V_118 ) ) {
F_147 ( V_154 -> V_395 . V_203 ) ;
goto V_323;
}
if ( V_154 -> V_395 . V_183 == 0 )
V_118 -> V_327 . V_312 = & V_313 [ V_421 ] ;
if ( V_154 -> V_412 )
F_257 ( V_2 , & V_154 -> V_414 ) ;
V_154 -> V_395 . V_229 =
F_83 ( F_90 ( V_2 ) ,
V_154 -> V_395 . V_183 , 0 ) ;
F_86 ( V_154 -> V_56 . V_392 ) ;
V_154 -> V_105 = V_152 ;
if ( F_66 ( F_90 ( V_2 ) ,
& V_154 -> V_395 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) != 0 )
F_147 ( V_154 -> V_395 . V_203 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_324:
V_118 -> V_335 = NULL ;
V_323:
F_63 ( V_118 , & V_154 -> V_56 . V_159 ) ;
}
static bool F_258 ( struct V_2 * V_2 )
{
if ( ! F_248 ( V_2 ) )
return false ;
return F_259 ( V_2 ) ;
}
int F_260 ( struct V_64 * V_65 , T_6 V_215 , int V_422 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
struct V_410 * V_154 ;
struct V_211 * V_212 = V_65 -> V_226 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_421 ] ,
. V_317 = V_65 -> V_226 -> V_292 ,
} ;
struct V_162 V_318 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_423 ,
. V_320 = V_321 ,
. V_213 = V_322 ,
} ;
int V_307 = - V_124 ;
F_261 ( V_14 -> V_62 , V_424 ,
& V_318 . V_164 , & V_161 ) ;
V_154 = F_91 ( sizeof( * V_154 ) , V_215 ) ;
if ( V_154 == NULL )
goto V_129;
F_40 ( & V_154 -> V_395 . V_158 , & V_154 -> V_56 . V_159 , 1 ) ;
V_154 -> V_2 = V_65 -> V_2 ;
V_154 -> V_65 = V_65 ;
V_154 -> V_395 . V_245 = F_98 ( V_65 -> V_2 ) ;
V_218 = V_14 -> V_62 -> V_166 -> V_218 ;
V_154 -> V_395 . V_203 = V_218 ( & V_65 -> V_226 -> V_223 , V_215 ) ;
if ( F_45 ( V_154 -> V_395 . V_203 ) )
goto V_425;
V_154 -> V_395 . V_183 = 0 ;
V_154 -> V_395 . V_242 = V_14 -> V_426 ;
V_154 -> V_56 . V_392 = & V_154 -> V_392 ;
V_154 -> V_56 . V_203 = V_154 -> V_395 . V_203 ;
V_154 -> V_56 . V_14 = V_14 ;
V_154 -> V_412 = F_258 ( V_65 -> V_2 ) ;
F_93 ( V_154 -> V_2 -> V_411 ) ;
V_161 . V_315 = & V_154 -> V_395 ;
V_161 . V_316 = & V_154 -> V_56 ;
V_318 . V_168 = V_154 ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_307 = 0 ;
if ( V_422 )
V_307 = F_113 ( V_118 ) ;
F_75 ( V_118 ) ;
return V_307 ;
V_425:
F_101 ( V_154 ) ;
V_129:
F_106 ( V_65 ) ;
F_107 ( V_212 ) ;
return V_307 ;
}
static struct V_2 *
F_262 ( struct V_2 * V_3 , struct V_301 * V_302 ,
int V_228 , struct V_5 * V_427 , int * V_378 )
{
struct V_64 * V_65 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_302 -> V_4 , V_427 , & V_17 ) ;
V_65 = F_238 ( V_3 , V_302 , V_228 , V_427 , V_7 , V_378 ) ;
F_4 ( V_7 ) ;
if ( F_45 ( V_65 ) )
return F_263 ( V_65 ) ;
return V_65 -> V_2 ;
}
static void F_264 ( struct V_301 * V_302 , int V_428 )
{
if ( V_302 -> V_65 == NULL )
return;
if ( V_428 )
F_265 ( V_302 -> V_65 , V_302 -> V_259 ) ;
else
F_167 ( V_302 -> V_65 , V_302 -> V_259 ) ;
}
static int F_266 ( struct V_13 * V_14 , struct V_429 * V_430 )
{
T_1 V_242 [ 3 ] = {} , V_431 = V_14 -> V_62 -> V_432 ;
struct V_433 args = {
. V_430 = V_430 ,
. V_242 = V_242 ,
} ;
struct V_434 V_56 = {} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_435 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
int V_307 ;
V_242 [ 0 ] = V_436 |
V_437 |
V_438 |
V_439 |
V_440 ;
if ( V_431 )
V_242 [ 2 ] = V_441 ;
V_307 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_307 == 0 ) {
switch ( V_431 ) {
case 0 :
V_56 . V_15 [ 1 ] &= V_442 ;
V_56 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_56 . V_15 [ 2 ] &= V_443 ;
break;
case 2 :
V_56 . V_15 [ 2 ] &= V_444 ;
}
memcpy ( V_14 -> V_15 , V_56 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_93 &= ~ ( V_445 | V_446 |
V_447 | V_448 |
V_449 | V_450 | V_451 |
V_452 | V_453 |
V_454 | V_455 |
V_9 ) ;
if ( V_56 . V_15 [ 0 ] & V_456 &&
V_56 . V_457 & V_458 )
V_14 -> V_93 |= V_445 ;
if ( V_56 . V_459 != 0 )
V_14 -> V_93 |= V_446 ;
if ( V_56 . V_460 != 0 )
V_14 -> V_93 |= V_447 ;
if ( V_56 . V_15 [ 0 ] & V_45 )
V_14 -> V_93 |= V_448 ;
if ( V_56 . V_15 [ 1 ] & V_372 )
V_14 -> V_93 |= V_449 ;
if ( V_56 . V_15 [ 1 ] & V_461 )
V_14 -> V_93 |= V_450 ;
if ( V_56 . V_15 [ 1 ] & V_462 )
V_14 -> V_93 |= V_451 ;
if ( V_56 . V_15 [ 1 ] & V_463 )
V_14 -> V_93 |= V_452 ;
if ( V_56 . V_15 [ 1 ] & V_366 )
V_14 -> V_93 |= V_453 ;
if ( V_56 . V_15 [ 1 ] & V_464 )
V_14 -> V_93 |= V_454 ;
if ( V_56 . V_15 [ 1 ] & V_369 )
V_14 -> V_93 |= V_455 ;
#ifdef F_267
if ( V_56 . V_15 [ 2 ] & V_374 )
V_14 -> V_93 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_56 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_374 ;
memcpy ( V_14 -> V_426 , V_56 . V_15 , sizeof( V_14 -> V_426 ) ) ;
V_14 -> V_426 [ 0 ] &= V_465 | V_466 ;
V_14 -> V_426 [ 1 ] &= V_464 | V_369 ;
V_14 -> V_426 [ 2 ] = 0 ;
memcpy ( V_14 -> V_467 , V_56 . V_467 ,
sizeof( V_14 -> V_467 ) ) ;
V_14 -> V_457 = V_56 . V_457 ;
V_14 -> V_468 = V_56 . V_468 ;
}
return V_307 ;
}
int F_268 ( struct V_13 * V_14 , struct V_429 * V_430 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_266 ( V_14 , V_430 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_269 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_470 )
{
T_1 V_242 [ 3 ] ;
struct V_471 args = {
. V_242 = V_242 ,
} ;
struct V_472 V_56 = {
. V_14 = V_14 ,
. V_392 = V_470 -> V_392 ,
. V_245 = V_430 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_473 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
V_242 [ 0 ] = V_244 [ 0 ] ;
V_242 [ 1 ] = V_244 [ 1 ] ;
V_242 [ 2 ] = V_244 [ 2 ] & ~ V_374 ;
F_86 ( V_470 -> V_392 ) ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_270 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_470 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_269 ( V_14 , V_430 , V_470 ) ;
F_271 ( V_14 , V_430 , V_470 -> V_392 , V_8 ) ;
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
static int F_272 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_470 , T_4 V_99 )
{
struct V_474 V_475 = {
. V_476 = V_99 ,
} ;
struct V_477 * V_478 ;
int V_51 ;
V_478 = F_273 ( & V_475 , V_14 -> V_90 ) ;
if ( F_45 ( V_478 ) ) {
V_51 = - V_29 ;
goto V_129;
}
V_51 = F_270 ( V_14 , V_430 , V_470 ) ;
V_129:
return V_51 ;
}
static int F_274 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_470 )
{
static const T_4 V_479 [] = {
V_104 ,
V_103 ,
V_480 ,
V_481 ,
V_482 ,
} ;
int V_307 = - V_24 ;
T_9 V_483 ;
if ( V_14 -> V_484 . V_485 > 0 ) {
for ( V_483 = 0 ; V_483 < V_14 -> V_484 . V_485 ; V_483 ++ ) {
V_307 = F_272 ( V_14 , V_430 , V_470 ,
V_14 -> V_484 . V_486 [ V_483 ] ) ;
if ( V_307 == - V_22 || V_307 == - V_29 )
continue;
break;
}
} else {
for ( V_483 = 0 ; V_483 < F_275 ( V_479 ) ; V_483 ++ ) {
V_307 = F_272 ( V_14 , V_430 , V_470 ,
V_479 [ V_483 ] ) ;
if ( V_307 == - V_22 || V_307 == - V_29 )
continue;
break;
}
}
if ( V_307 == - V_29 )
V_307 = - V_24 ;
return V_307 ;
}
static int F_276 ( struct V_13 * V_14 ,
struct V_429 * V_430 , struct V_469 * V_470 )
{
int V_487 = V_14 -> V_62 -> V_432 ;
return V_488 [ V_487 ] -> F_277 ( V_14 , V_430 , V_470 ) ;
}
int F_278 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_470 ,
bool V_489 )
{
int V_307 = 0 ;
if ( ! V_489 )
V_307 = F_270 ( V_14 , V_430 , V_470 ) ;
if ( V_489 || V_307 == V_22 )
V_307 = F_276 ( V_14 , V_430 , V_470 ) ;
if ( V_307 == 0 )
V_307 = F_268 ( V_14 , V_430 ) ;
if ( V_307 == 0 )
V_307 = F_279 ( V_14 , V_430 , V_470 ) ;
return F_7 ( V_307 ) ;
}
static int F_280 ( struct V_13 * V_14 , struct V_429 * V_490 ,
struct V_469 * V_470 )
{
int error ;
struct V_391 * V_392 = V_470 -> V_392 ;
struct V_1 * V_7 = NULL ;
error = F_268 ( V_14 , V_490 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_92 ( V_14 , V_383 ) ;
if ( F_45 ( V_7 ) )
return F_74 ( V_7 ) ;
error = F_198 ( V_14 , V_490 , V_392 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_224;
}
if ( V_392 -> V_298 & V_491 &&
! F_281 ( & V_14 -> V_492 , & V_392 -> V_492 ) )
memcpy ( & V_14 -> V_492 , & V_392 -> V_492 , sizeof( V_14 -> V_492 ) ) ;
V_224:
F_100 ( V_7 ) ;
return error ;
}
static int F_282 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_493 * V_241 , struct V_391 * V_392 ,
struct V_429 * V_430 )
{
int V_307 = - V_124 ;
struct V_494 * V_494 = NULL ;
struct V_495 * V_496 = NULL ;
V_494 = F_283 ( V_383 ) ;
if ( V_494 == NULL )
goto V_129;
V_496 = F_284 ( sizeof( struct V_495 ) , V_383 ) ;
if ( V_496 == NULL )
goto V_129;
V_307 = F_285 ( V_90 , V_3 , V_241 , V_496 , V_494 ) ;
if ( V_307 != 0 )
goto V_129;
if ( F_281 ( & F_90 ( V_3 ) -> V_492 , & V_496 -> V_392 . V_492 ) ) {
F_8 ( L_34
L_35 , V_34 , V_241 -> V_241 ) ;
V_307 = - V_76 ;
goto V_129;
}
F_286 ( & V_496 -> V_392 ) ;
memcpy ( V_392 , & V_496 -> V_392 , sizeof( struct V_391 ) ) ;
memset ( V_430 , 0 , sizeof( struct V_429 ) ) ;
V_129:
if ( V_494 )
F_287 ( V_494 ) ;
F_101 ( V_496 ) ;
return V_307 ;
}
static int F_288 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_391 * V_392 , struct V_1 * V_7 )
{
struct V_497 args = {
. V_245 = V_430 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_498 V_56 = {
. V_392 = V_392 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_499 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
args . V_242 = F_6 ( V_14 , V_7 ) ;
F_86 ( V_392 ) ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_198 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_391 * V_392 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_288 ( V_14 , V_430 , V_392 , V_7 ) ;
F_289 ( V_14 , V_430 , V_392 , V_8 ) ;
V_8 = F_21 ( V_14 , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_290 ( struct V_4 * V_4 , struct V_391 * V_392 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_317 * V_351 = NULL ;
struct V_64 * V_65 = NULL ;
struct V_1 * V_7 = NULL ;
int V_307 ;
if ( F_291 ( V_2 ) &&
V_6 -> V_247 & V_400 &&
V_6 -> V_500 < F_292 ( V_2 ) )
F_293 ( V_2 ) ;
F_86 ( V_392 ) ;
if ( V_6 -> V_247 & V_409 )
V_6 -> V_247 &= ~ ( V_371 | V_501 ) ;
if ( ( V_6 -> V_247 & ~ ( V_502 | V_409 ) ) == 0 )
return 0 ;
if ( V_6 -> V_247 & V_502 ) {
struct V_301 * V_302 ;
V_302 = F_294 ( V_6 -> V_503 ) ;
if ( V_302 ) {
V_351 = V_302 -> V_351 ;
V_65 = V_302 -> V_65 ;
}
}
V_7 = F_92 ( F_90 ( V_2 ) , V_383 ) ;
if ( F_45 ( V_7 ) )
return F_74 ( V_7 ) ;
V_307 = F_234 ( V_2 , V_351 , V_392 , V_6 , V_65 , NULL , V_7 ) ;
if ( V_307 == 0 ) {
F_235 ( V_2 , V_6 , V_392 ) ;
F_236 ( V_2 , V_392 , V_7 ) ;
}
F_100 ( V_7 ) ;
return V_307 ;
}
static int F_295 ( struct V_54 * V_55 , struct V_2 * V_3 ,
const struct V_493 * V_241 , struct V_429 * V_430 ,
struct V_391 * V_392 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
int V_307 ;
struct V_504 args = {
. V_242 = V_14 -> V_15 ,
. V_505 = F_98 ( V_3 ) ,
. V_241 = V_241 ,
} ;
struct V_472 V_56 = {
. V_14 = V_14 ,
. V_392 = V_392 ,
. V_7 = V_7 ,
. V_245 = V_430 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_506 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
args . V_242 = F_6 ( V_14 , V_7 ) ;
F_86 ( V_392 ) ;
F_8 ( L_36 , V_241 -> V_241 ) ;
V_307 = F_76 ( V_55 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
F_8 ( L_37 , V_307 ) ;
return V_307 ;
}
static void F_296 ( struct V_391 * V_392 )
{
V_392 -> V_298 |= V_336 | V_507 |
V_508 | V_509 ;
V_392 -> V_259 = V_341 | V_510 | V_511 ;
V_392 -> V_512 = 2 ;
}
static int F_297 ( struct V_54 * * V_55 , struct V_2 * V_3 ,
struct V_493 * V_241 , struct V_429 * V_430 ,
struct V_391 * V_392 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
struct V_54 * V_90 = * V_55 ;
int V_8 ;
do {
V_8 = F_295 ( V_90 , V_3 , V_241 , V_430 , V_392 , V_7 ) ;
F_298 ( V_3 , V_241 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_303 ;
goto V_129;
case - V_76 :
V_8 = F_282 ( V_90 , V_3 , V_241 , V_392 , V_430 ) ;
if ( V_8 == - V_76 )
V_8 = F_21 ( F_90 ( V_3 ) , V_8 , & V_61 ) ;
goto V_129;
case - V_22 :
V_8 = - V_24 ;
if ( V_90 != * V_55 )
goto V_129;
V_90 = F_299 ( V_90 , V_3 , V_241 ) ;
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
F_300 ( V_90 ) ;
return V_8 ;
}
static int F_301 ( struct V_2 * V_3 , struct V_493 * V_241 ,
struct V_429 * V_430 , struct V_391 * V_392 ,
struct V_1 * V_7 )
{
int V_307 ;
struct V_54 * V_90 = F_302 ( V_3 ) ;
V_307 = F_297 ( & V_90 , V_3 , V_241 , V_430 , V_392 , V_7 ) ;
if ( V_90 != F_302 ( V_3 ) ) {
F_300 ( V_90 ) ;
F_296 ( V_392 ) ;
}
return V_307 ;
}
struct V_54 *
F_303 ( struct V_2 * V_3 , struct V_493 * V_241 ,
struct V_429 * V_430 , struct V_391 * V_392 )
{
struct V_54 * V_90 = F_302 ( V_3 ) ;
int V_307 ;
V_307 = F_297 ( & V_90 , V_3 , V_241 , V_430 , V_392 , NULL ) ;
if ( V_307 < 0 )
return F_46 ( V_307 ) ;
return ( V_90 == F_302 ( V_3 ) ) ? F_304 ( V_90 ) : V_90 ;
}
static int F_305 ( struct V_2 * V_2 , struct V_352 * V_513 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_514 args = {
. V_245 = F_98 ( V_2 ) ,
. V_242 = V_14 -> V_426 ,
} ;
struct V_515 V_56 = {
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_516 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_513 -> V_351 ,
} ;
int V_259 = V_513 -> V_354 ;
int V_307 = 0 ;
if ( V_259 & V_359 )
args . V_208 |= V_231 ;
if ( F_306 ( V_2 -> V_517 ) ) {
if ( V_259 & V_518 )
args . V_208 |= V_232 | V_233 | V_519 ;
if ( V_259 & V_357 )
args . V_208 |= V_520 ;
} else {
if ( V_259 & V_518 )
args . V_208 |= V_232 | V_233 ;
if ( V_259 & V_357 )
args . V_208 |= V_234 ;
}
V_56 . V_392 = F_307 () ;
if ( V_56 . V_392 == NULL )
return - V_124 ;
V_307 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( ! V_307 ) {
F_195 ( V_513 , V_56 . V_208 ) ;
F_154 ( V_2 , V_56 . V_392 ) ;
}
F_308 ( V_56 . V_392 ) ;
return V_307 ;
}
static int F_309 ( struct V_2 * V_2 , struct V_352 * V_513 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_305 ( V_2 , V_513 ) ;
F_310 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_311 ( struct V_2 * V_2 , struct V_494 * V_494 ,
unsigned int V_48 , unsigned int V_521 )
{
struct V_522 args = {
. V_245 = F_98 ( V_2 ) ,
. V_48 = V_48 ,
. V_521 = V_521 ,
. V_42 = & V_494 ,
} ;
struct V_523 V_56 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_524 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
return F_76 ( F_90 ( V_2 ) -> V_90 , F_90 ( V_2 ) , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_312 ( struct V_2 * V_2 , struct V_494 * V_494 ,
unsigned int V_48 , unsigned int V_521 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_311 ( V_2 , V_494 , V_48 , V_521 ) ;
F_313 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_314 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_213 )
{
struct V_1 V_17 , * V_393 = NULL ;
struct V_301 * V_302 ;
struct V_64 * V_65 ;
int V_307 = 0 ;
V_302 = F_315 ( V_4 , V_71 ) ;
if ( F_45 ( V_302 ) )
return F_74 ( V_302 ) ;
V_393 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_316 () ;
V_65 = F_238 ( V_3 , V_302 , V_213 , V_6 , V_393 , NULL ) ;
if ( F_45 ( V_65 ) ) {
V_307 = F_74 ( V_65 ) ;
goto V_129;
}
V_129:
F_4 ( V_393 ) ;
F_174 ( V_302 ) ;
return V_307 ;
}
static int F_317 ( struct V_2 * V_3 , struct V_493 * V_241 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_525 args = {
. V_245 = F_98 ( V_3 ) ,
. V_241 = * V_241 ,
} ;
struct V_526 V_56 = {
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_527 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
int V_307 ;
V_307 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_307 == 0 )
F_77 ( V_3 , & V_56 . V_170 ) ;
return V_307 ;
}
static int F_318 ( struct V_2 * V_3 , struct V_493 * V_241 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_317 ( V_3 , V_241 ) ;
F_319 ( V_3 , V_241 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_320 ( struct V_160 * V_161 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_525 * args = V_161 -> V_315 ;
struct V_526 * V_56 = V_161 -> V_316 ;
V_56 -> V_14 = V_14 ;
V_161 -> V_312 = & V_313 [ V_527 ] ;
F_40 ( & args -> V_158 , & V_56 -> V_159 , 1 ) ;
F_86 ( V_56 -> V_528 ) ;
}
static void F_321 ( struct V_117 * V_118 , struct V_529 * V_156 )
{
F_66 ( F_90 ( V_156 -> V_3 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_322 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_529 * V_156 = V_118 -> V_530 ;
struct V_526 * V_56 = & V_156 -> V_56 ;
if ( ! F_63 ( V_118 , & V_56 -> V_159 ) )
return 0 ;
if ( F_255 ( V_118 , V_56 -> V_14 , NULL ,
& V_156 -> V_50 ) == - V_128 )
return 0 ;
F_77 ( V_3 , & V_56 -> V_170 ) ;
return 1 ;
}
static void F_323 ( struct V_160 * V_161 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
struct V_531 * V_395 = V_161 -> V_315 ;
struct V_532 * V_56 = V_161 -> V_316 ;
V_161 -> V_312 = & V_313 [ V_533 ] ;
V_56 -> V_14 = V_14 ;
F_40 ( & V_395 -> V_158 , & V_56 -> V_159 , 1 ) ;
}
static void F_324 ( struct V_117 * V_118 , struct V_534 * V_156 )
{
F_66 ( F_90 ( V_156 -> V_535 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_325 ( struct V_117 * V_118 , struct V_2 * V_535 ,
struct V_2 * V_536 )
{
struct V_534 * V_156 = V_118 -> V_530 ;
struct V_532 * V_56 = & V_156 -> V_56 ;
if ( ! F_63 ( V_118 , & V_56 -> V_159 ) )
return 0 ;
if ( F_255 ( V_118 , V_56 -> V_14 , NULL , & V_156 -> V_50 ) == - V_128 )
return 0 ;
F_77 ( V_535 , & V_56 -> V_537 ) ;
F_77 ( V_536 , & V_56 -> V_538 ) ;
return 1 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_493 * V_241 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_539 V_395 = {
. V_245 = F_98 ( V_2 ) ,
. V_505 = F_98 ( V_3 ) ,
. V_241 = V_241 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_540 V_56 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_541 ] ,
. V_315 = & V_395 ,
. V_316 = & V_56 ,
} ;
int V_307 = - V_124 ;
V_56 . V_392 = F_307 () ;
if ( V_56 . V_392 == NULL )
goto V_129;
V_56 . V_7 = F_92 ( V_14 , V_383 ) ;
if ( F_45 ( V_56 . V_7 ) ) {
V_307 = F_74 ( V_56 . V_7 ) ;
goto V_129;
}
V_395 . V_242 = F_6 ( V_14 , V_56 . V_7 ) ;
V_307 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_395 . V_158 , & V_56 . V_159 , 1 ) ;
if ( ! V_307 ) {
F_77 ( V_3 , & V_56 . V_170 ) ;
V_307 = F_327 ( V_2 , V_56 . V_392 ) ;
if ( ! V_307 )
F_236 ( V_2 , V_56 . V_392 , V_56 . V_7 ) ;
}
F_100 ( V_56 . V_7 ) ;
V_129:
F_308 ( V_56 . V_392 ) ;
return V_307 ;
}
static int F_328 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_493 * V_241 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( F_90 ( V_2 ) ,
F_326 ( V_2 , V_3 , V_241 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static struct V_542 * F_329 ( struct V_2 * V_3 ,
struct V_493 * V_241 , struct V_5 * V_6 , T_1 V_543 )
{
struct V_542 * V_156 ;
V_156 = F_91 ( sizeof( * V_156 ) , V_383 ) ;
if ( V_156 != NULL ) {
struct V_13 * V_14 = F_90 ( V_3 ) ;
V_156 -> V_7 = F_92 ( V_14 , V_383 ) ;
if ( F_45 ( V_156 -> V_7 ) )
goto V_311;
V_156 -> V_161 . V_312 = & V_313 [ V_544 ] ;
V_156 -> V_161 . V_315 = & V_156 -> V_395 ;
V_156 -> V_161 . V_316 = & V_156 -> V_56 ;
V_156 -> V_395 . V_505 = F_98 ( V_3 ) ;
V_156 -> V_395 . V_14 = V_14 ;
V_156 -> V_395 . V_241 = V_241 ;
V_156 -> V_395 . V_214 = V_6 ;
V_156 -> V_395 . V_543 = V_543 ;
V_156 -> V_395 . V_242 = F_6 ( V_14 , V_156 -> V_7 ) ;
V_156 -> V_56 . V_14 = V_14 ;
V_156 -> V_56 . V_245 = & V_156 -> V_245 ;
V_156 -> V_56 . V_392 = & V_156 -> V_392 ;
V_156 -> V_56 . V_7 = V_156 -> V_7 ;
F_86 ( V_156 -> V_56 . V_392 ) ;
}
return V_156 ;
V_311:
F_101 ( V_156 ) ;
return NULL ;
}
static int F_330 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_542 * V_156 )
{
int V_307 = F_76 ( F_90 ( V_3 ) -> V_90 , F_90 ( V_3 ) , & V_156 -> V_161 ,
& V_156 -> V_395 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
if ( V_307 == 0 ) {
F_77 ( V_3 , & V_156 -> V_56 . V_545 ) ;
V_307 = F_331 ( V_4 , V_156 -> V_56 . V_245 , V_156 -> V_56 . V_392 , V_156 -> V_56 . V_7 ) ;
}
return V_307 ;
}
static void F_332 ( struct V_542 * V_156 )
{
F_100 ( V_156 -> V_7 ) ;
F_101 ( V_156 ) ;
}
static int F_333 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_494 * V_494 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_542 * V_156 ;
int V_307 = - V_546 ;
if ( V_12 > V_547 )
goto V_129;
V_307 = - V_124 ;
V_156 = F_329 ( V_3 , & V_4 -> V_11 , V_6 , V_548 ) ;
if ( V_156 == NULL )
goto V_129;
V_156 -> V_161 . V_312 = & V_313 [ V_549 ] ;
V_156 -> V_395 . V_249 . V_550 . V_42 = & V_494 ;
V_156 -> V_395 . V_249 . V_550 . V_12 = V_12 ;
V_156 -> V_395 . V_7 = V_7 ;
V_307 = F_330 ( V_3 , V_4 , V_156 ) ;
F_332 ( V_156 ) ;
V_129:
return V_307 ;
}
static int F_334 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_494 * V_494 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_333 ( V_3 , V_4 , V_494 , V_12 , V_6 , V_7 ) ;
F_335 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_336 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_542 * V_156 ;
int V_307 = - V_124 ;
V_156 = F_329 ( V_3 , & V_4 -> V_11 , V_6 , V_551 ) ;
if ( V_156 == NULL )
goto V_129;
V_156 -> V_395 . V_7 = V_7 ;
V_307 = F_330 ( V_3 , V_4 , V_156 ) ;
F_332 ( V_156 ) ;
V_129:
return V_307 ;
}
static int F_337 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_316 () ;
do {
V_8 = F_336 ( V_3 , V_4 , V_6 , V_7 ) ;
F_338 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_339 ( struct V_4 * V_4 , struct V_317 * V_351 ,
T_2 V_36 , struct V_494 * * V_42 , unsigned int V_49 , int V_552 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_245 = F_98 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_242 = F_90 ( F_14 ( V_4 ) ) -> V_15 ,
. V_552 = V_552 ,
} ;
struct V_553 V_56 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_554 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
int V_307 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_78 ( V_3 ) -> V_555 , V_4 , & args ) ;
V_56 . V_48 = args . V_48 ;
V_307 = F_76 ( F_90 ( V_3 ) -> V_90 , F_90 ( V_3 ) , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_307 >= 0 ) {
memcpy ( F_78 ( V_3 ) -> V_555 , V_56 . V_37 . V_156 , V_556 ) ;
V_307 += args . V_48 ;
}
F_340 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_307 ) ;
return V_307 ;
}
static int F_341 ( struct V_4 * V_4 , struct V_317 * V_351 ,
T_2 V_36 , struct V_494 * * V_42 , unsigned int V_49 , int V_552 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_339 ( V_4 , V_351 , V_36 ,
V_42 , V_49 , V_552 ) ;
F_342 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_21 ( F_90 ( F_14 ( V_4 ) ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_343 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_557 )
{
struct V_542 * V_156 ;
int V_259 = V_6 -> V_10 ;
int V_307 = - V_124 ;
V_156 = F_329 ( V_3 , & V_4 -> V_11 , V_6 , V_558 ) ;
if ( V_156 == NULL )
goto V_129;
if ( F_344 ( V_259 ) )
V_156 -> V_395 . V_543 = V_559 ;
else if ( F_345 ( V_259 ) ) {
V_156 -> V_395 . V_543 = V_560 ;
V_156 -> V_395 . V_249 . V_561 . V_562 = F_346 ( V_557 ) ;
V_156 -> V_395 . V_249 . V_561 . V_563 = F_347 ( V_557 ) ;
}
else if ( F_348 ( V_259 ) ) {
V_156 -> V_395 . V_543 = V_564 ;
V_156 -> V_395 . V_249 . V_561 . V_562 = F_346 ( V_557 ) ;
V_156 -> V_395 . V_249 . V_561 . V_563 = F_347 ( V_557 ) ;
} else if ( ! F_349 ( V_259 ) ) {
V_307 = - V_27 ;
goto V_311;
}
V_156 -> V_395 . V_7 = V_7 ;
V_307 = F_330 ( V_3 , V_4 , V_156 ) ;
V_311:
F_332 ( V_156 ) ;
V_129:
return V_307 ;
}
static int F_350 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_557 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_316 () ;
do {
V_8 = F_343 ( V_3 , V_4 , V_6 , V_7 , V_557 ) ;
F_351 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_352 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_565 * V_566 )
{
struct V_567 args = {
. V_245 = V_430 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_568 V_56 = {
. V_566 = V_566 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_569 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
F_86 ( V_566 -> V_392 ) ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_353 ( struct V_13 * V_14 , struct V_429 * V_430 , struct V_565 * V_566 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_352 ( V_14 , V_430 , V_566 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_354 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_570 )
{
struct V_571 args = {
. V_245 = V_430 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_572 V_56 = {
. V_570 = V_570 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_573 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_279 ( struct V_13 * V_14 , struct V_429 * V_430 , struct V_469 * V_570 )
{
struct V_60 V_61 = { } ;
unsigned long V_574 = V_152 ;
int V_8 ;
do {
V_8 = F_354 ( V_14 , V_430 , V_570 ) ;
F_355 ( V_14 , V_430 , V_570 -> V_392 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_62 * V_63 = V_14 -> V_62 ;
F_35 ( & V_63 -> V_106 ) ;
V_63 -> V_575 = V_570 -> V_576 * V_87 ;
V_63 -> V_107 = V_574 ;
F_37 ( & V_63 -> V_106 ) ;
break;
}
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_356 ( struct V_13 * V_14 , struct V_429 * V_430 , struct V_469 * V_570 )
{
int error ;
F_86 ( V_570 -> V_392 ) ;
error = F_279 ( V_14 , V_430 , V_570 ) ;
if ( error == 0 ) {
V_14 -> V_577 = V_570 -> V_578 ;
F_357 ( V_14 , V_430 , V_570 -> V_579 ) ;
}
return error ;
}
static int F_358 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_580 * V_581 )
{
struct V_582 args = {
. V_245 = V_430 ,
. V_242 = V_14 -> V_15 ,
} ;
struct V_583 V_56 = {
. V_581 = V_581 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_584 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
if ( ( args . V_242 [ 0 ] & V_585 [ 0 ] ) == 0 ) {
memset ( V_581 , 0 , sizeof( * V_581 ) ) ;
return 0 ;
}
F_86 ( V_581 -> V_392 ) ;
return F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_359 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_580 * V_581 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_358 ( V_14 , V_430 , V_581 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
int F_360 ( T_8 * V_251 ,
const struct V_301 * V_302 ,
const struct V_586 * V_587 ,
T_5 V_183 )
{
const struct V_401 * V_402 = NULL ;
if ( V_587 != NULL )
V_402 = & V_587 -> V_402 ;
return F_244 ( V_251 , V_302 -> V_65 , V_183 , V_402 ) ;
}
static bool F_361 ( T_8 * V_251 ,
const struct V_301 * V_302 ,
const struct V_586 * V_587 ,
T_5 V_183 )
{
T_8 V_588 ;
if ( F_360 ( & V_588 , V_302 , V_587 , V_183 ) == - V_35 )
return true ;
return F_142 ( V_251 , & V_588 ) ;
}
static bool F_362 ( int V_8 )
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
void F_363 ( struct V_589 * V_590 )
{
F_340 ( V_590 -> V_2 ) ;
}
static int F_364 ( struct V_117 * V_118 , struct V_589 * V_590 )
{
struct V_13 * V_14 = F_90 ( V_590 -> V_2 ) ;
F_365 ( V_590 , V_118 -> V_147 ) ;
if ( F_255 ( V_118 , V_14 ,
V_590 -> args . V_591 -> V_65 ,
NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return - V_128 ;
}
F_363 ( V_590 ) ;
if ( V_118 -> V_147 > 0 )
F_38 ( V_14 , V_590 -> V_105 ) ;
return 0 ;
}
static bool F_366 ( struct V_117 * V_118 ,
struct V_592 * args )
{
if ( ! F_362 ( V_118 -> V_147 ) ||
F_361 ( & args -> V_251 ,
args -> V_591 ,
args -> V_593 ,
V_71 ) )
return false ;
F_60 ( V_118 ) ;
return true ;
}
static int F_367 ( struct V_117 * V_118 , struct V_589 * V_590 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_63 ( V_118 , & V_590 -> V_56 . V_159 ) )
return - V_128 ;
if ( F_366 ( V_118 , & V_590 -> args ) )
return - V_128 ;
return V_590 -> V_594 ? V_590 -> V_594 ( V_118 , V_590 ) :
F_364 ( V_118 , V_590 ) ;
}
static void F_368 ( struct V_589 * V_590 ,
struct V_160 * V_161 )
{
V_590 -> V_105 = V_152 ;
V_590 -> V_594 = F_364 ;
V_161 -> V_312 = & V_313 [ V_595 ] ;
F_40 ( & V_590 -> args . V_158 , & V_590 -> V_56 . V_159 , 0 ) ;
}
static int F_369 ( struct V_117 * V_118 ,
struct V_589 * V_590 )
{
if ( F_66 ( F_90 ( V_590 -> V_2 ) ,
& V_590 -> args . V_158 ,
& V_590 -> V_56 . V_159 ,
V_118 ) )
return 0 ;
if ( F_360 ( & V_590 -> args . V_251 , V_590 -> args . V_591 ,
V_590 -> args . V_593 ,
V_590 -> V_596 -> V_597 ) == - V_35 )
return - V_35 ;
if ( F_370 ( F_32 ( V_598 , & V_590 -> args . V_591 -> V_213 ) ) )
return - V_35 ;
return 0 ;
}
static int F_371 ( struct V_117 * V_118 ,
struct V_589 * V_590 )
{
struct V_2 * V_2 = V_590 -> V_2 ;
F_372 ( V_590 , V_118 -> V_147 ) ;
if ( F_255 ( V_118 , F_90 ( V_2 ) ,
V_590 -> args . V_591 -> V_65 ,
NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return - V_128 ;
}
if ( V_118 -> V_147 >= 0 ) {
F_38 ( F_90 ( V_2 ) , V_590 -> V_105 ) ;
F_373 ( V_590 ) ;
}
return 0 ;
}
static bool F_374 ( struct V_117 * V_118 ,
struct V_592 * args )
{
if ( ! F_362 ( V_118 -> V_147 ) ||
F_361 ( & args -> V_251 ,
args -> V_591 ,
args -> V_593 ,
V_185 ) )
return false ;
F_60 ( V_118 ) ;
return true ;
}
static int F_375 ( struct V_117 * V_118 , struct V_589 * V_590 )
{
if ( ! F_63 ( V_118 , & V_590 -> V_56 . V_159 ) )
return - V_128 ;
if ( F_374 ( V_118 , & V_590 -> args ) )
return - V_128 ;
return V_590 -> V_594 ? V_590 -> V_594 ( V_118 , V_590 ) :
F_371 ( V_118 , V_590 ) ;
}
static
bool F_376 ( struct V_589 * V_590 )
{
if ( V_590 -> V_599 != NULL || V_590 -> V_600 != NULL )
return false ;
return F_22 ( V_590 -> V_2 , V_71 ) == 0 ;
}
static void F_377 ( struct V_589 * V_590 ,
struct V_160 * V_161 )
{
struct V_13 * V_14 = F_90 ( V_590 -> V_2 ) ;
if ( ! F_376 ( V_590 ) ) {
V_590 -> args . V_242 = NULL ;
V_590 -> V_56 . V_392 = NULL ;
} else
V_590 -> args . V_242 = V_14 -> V_426 ;
if ( ! V_590 -> V_594 )
V_590 -> V_594 = F_371 ;
V_590 -> V_56 . V_14 = V_14 ;
V_590 -> V_105 = V_152 ;
V_161 -> V_312 = & V_313 [ V_601 ] ;
F_40 ( & V_590 -> args . V_158 , & V_590 -> V_56 . V_159 , 1 ) ;
}
static void F_378 ( struct V_117 * V_118 , struct V_602 * V_156 )
{
F_66 ( F_90 ( V_156 -> V_2 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_379 ( struct V_117 * V_118 , struct V_602 * V_156 )
{
struct V_2 * V_2 = V_156 -> V_2 ;
F_380 ( V_156 , V_118 -> V_147 ) ;
if ( F_255 ( V_118 , F_90 ( V_2 ) ,
NULL , NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_381 ( struct V_117 * V_118 , struct V_602 * V_156 )
{
if ( ! F_63 ( V_118 , & V_156 -> V_56 . V_159 ) )
return - V_128 ;
return V_156 -> V_603 ( V_118 , V_156 ) ;
}
static void F_382 ( struct V_602 * V_156 , struct V_160 * V_161 )
{
struct V_13 * V_14 = F_90 ( V_156 -> V_2 ) ;
if ( V_156 -> V_603 == NULL )
V_156 -> V_603 = F_379 ;
V_156 -> V_56 . V_14 = V_14 ;
V_161 -> V_312 = & V_313 [ V_604 ] ;
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
}
static void F_383 ( void * V_154 )
{
struct V_605 * V_156 = V_154 ;
struct V_62 * V_63 = V_156 -> V_90 ;
if ( F_384 ( & V_63 -> V_606 ) > 1 )
F_385 ( V_63 ) ;
F_386 ( V_63 ) ;
F_101 ( V_156 ) ;
}
static void F_387 ( struct V_117 * V_118 , void * V_154 )
{
struct V_605 * V_156 = V_154 ;
struct V_62 * V_63 = V_156 -> V_90 ;
unsigned long V_105 = V_156 -> V_105 ;
F_388 ( V_63 , V_118 -> V_147 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
break;
case - V_77 :
F_27 ( V_63 ) ;
break;
default:
if ( F_32 ( V_607 , & V_63 -> V_608 ) == 0 )
return;
if ( V_118 -> V_147 != V_609 ) {
F_25 ( V_63 ) ;
return;
}
F_389 ( V_63 ) ;
}
F_34 ( V_63 , V_105 ) ;
}
static int F_390 ( struct V_62 * V_63 , struct V_317 * V_351 , unsigned V_610 )
{
struct V_160 V_161 = {
. V_312 = & V_313 [ V_611 ] ,
. V_315 = V_63 ,
. V_317 = V_351 ,
} ;
struct V_605 * V_156 ;
if ( V_610 == 0 )
return 0 ;
if ( ! F_391 ( & V_63 -> V_606 ) )
return - V_35 ;
V_156 = F_284 ( sizeof( * V_156 ) , V_304 ) ;
if ( V_156 == NULL )
return - V_124 ;
V_156 -> V_90 = V_63 ;
V_156 -> V_105 = V_152 ;
return F_392 ( V_63 -> V_100 , & V_161 , V_612 ,
& V_613 , V_156 ) ;
}
static int F_393 ( struct V_62 * V_63 , struct V_317 * V_351 )
{
struct V_160 V_161 = {
. V_312 = & V_313 [ V_611 ] ,
. V_315 = V_63 ,
. V_317 = V_351 ,
} ;
unsigned long V_574 = V_152 ;
int V_307 ;
V_307 = F_394 ( V_63 -> V_100 , & V_161 , V_612 ) ;
if ( V_307 < 0 )
return V_307 ;
F_34 ( V_63 , V_574 ) ;
return 0 ;
}
static inline int F_395 ( struct V_13 * V_14 )
{
return V_14 -> V_93 & V_445 ;
}
static int F_396 ( const void * V_614 , T_9 V_615 ,
struct V_494 * * V_42 , unsigned int * V_48 )
{
struct V_494 * V_616 , * * V_617 ;
int V_618 = 0 ;
T_9 V_12 ;
V_617 = V_42 ;
do {
V_12 = F_397 ( T_9 , V_619 , V_615 ) ;
V_616 = F_283 ( V_383 ) ;
if ( V_616 == NULL )
goto V_620;
memcpy ( F_398 ( V_616 ) , V_614 , V_12 ) ;
V_614 += V_12 ;
V_615 -= V_12 ;
* V_42 ++ = V_616 ;
V_618 ++ ;
} while ( V_615 != 0 );
return V_618 ;
V_620:
for(; V_618 > 0 ; V_618 -- )
F_287 ( V_617 [ V_618 - 1 ] ) ;
return - V_124 ;
}
static void F_399 ( struct V_2 * V_2 , struct V_621 * V_622 )
{
struct V_171 * V_172 = F_78 ( V_2 ) ;
F_35 ( & V_2 -> V_173 ) ;
F_101 ( V_172 -> V_623 ) ;
V_172 -> V_623 = V_622 ;
F_37 ( & V_2 -> V_173 ) ;
}
static void F_400 ( struct V_2 * V_2 )
{
F_399 ( V_2 , NULL ) ;
}
static inline T_11 F_401 ( struct V_2 * V_2 , char * V_614 , T_9 V_615 )
{
struct V_171 * V_172 = F_78 ( V_2 ) ;
struct V_621 * V_622 ;
int V_51 = - V_303 ;
F_35 ( & V_2 -> V_173 ) ;
V_622 = V_172 -> V_623 ;
if ( V_622 == NULL )
goto V_129;
if ( V_614 == NULL )
goto V_624;
if ( V_622 -> V_625 == 0 )
goto V_129;
V_51 = - V_626 ;
if ( V_622 -> V_12 > V_615 )
goto V_129;
memcpy ( V_614 , V_622 -> V_156 , V_622 -> V_12 ) ;
V_624:
V_51 = V_622 -> V_12 ;
V_129:
F_37 ( & V_2 -> V_173 ) ;
return V_51 ;
}
static void F_402 ( struct V_2 * V_2 , struct V_494 * * V_42 , T_9 V_48 , T_9 V_627 )
{
struct V_621 * V_622 ;
T_9 V_615 = sizeof( * V_622 ) + V_627 ;
if ( V_615 <= V_619 ) {
V_622 = F_284 ( V_615 , V_383 ) ;
if ( V_622 == NULL )
goto V_129;
V_622 -> V_625 = 1 ;
F_403 ( V_622 -> V_156 , V_42 , V_48 , V_627 ) ;
} else {
V_622 = F_284 ( sizeof( * V_622 ) , V_383 ) ;
if ( V_622 == NULL )
goto V_129;
V_622 -> V_625 = 0 ;
}
V_622 -> V_12 = V_627 ;
V_129:
F_399 ( V_2 , V_622 ) ;
}
static T_11 F_404 ( struct V_2 * V_2 , void * V_614 , T_9 V_615 )
{
struct V_494 * V_42 [ V_628 ] = { NULL , } ;
struct V_629 args = {
. V_245 = F_98 ( V_2 ) ,
. V_630 = V_42 ,
. V_627 = V_615 ,
} ;
struct V_631 V_56 = {
. V_627 = V_615 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_632 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
unsigned int V_633 = F_405 ( V_615 , V_619 ) ;
int V_51 = - V_124 , V_483 ;
if ( V_633 == 0 )
V_633 = 1 ;
if ( V_633 > F_275 ( V_42 ) )
return - V_626 ;
for ( V_483 = 0 ; V_483 < V_633 ; V_483 ++ ) {
V_42 [ V_483 ] = F_283 ( V_383 ) ;
if ( ! V_42 [ V_483 ] )
goto V_311;
}
V_56 . V_634 = F_283 ( V_383 ) ;
if ( ! V_56 . V_634 )
goto V_311;
args . V_627 = V_633 * V_619 ;
args . V_635 = 0 ;
F_8 ( L_40 ,
V_34 , V_614 , V_615 , V_633 , args . V_627 ) ;
V_51 = F_76 ( F_90 ( V_2 ) -> V_90 , F_90 ( V_2 ) ,
& V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_51 )
goto V_311;
if ( V_56 . V_636 & V_637 ) {
if ( V_614 == NULL )
goto V_638;
V_51 = - V_626 ;
goto V_311;
}
F_402 ( V_2 , V_42 , V_56 . V_639 , V_56 . V_627 ) ;
if ( V_614 ) {
if ( V_56 . V_627 > V_615 ) {
V_51 = - V_626 ;
goto V_311;
}
F_403 ( V_614 , V_42 , V_56 . V_639 , V_56 . V_627 ) ;
}
V_638:
V_51 = V_56 . V_627 ;
V_311:
for ( V_483 = 0 ; V_483 < V_633 ; V_483 ++ )
if ( V_42 [ V_483 ] )
F_287 ( V_42 [ V_483 ] ) ;
if ( V_56 . V_634 )
F_287 ( V_56 . V_634 ) ;
return V_51 ;
}
static T_11 F_406 ( struct V_2 * V_2 , void * V_614 , T_9 V_615 )
{
struct V_60 V_61 = { } ;
T_11 V_51 ;
do {
V_51 = F_404 ( V_2 , V_614 , V_615 ) ;
F_407 ( V_2 , V_51 ) ;
if ( V_51 >= 0 )
break;
V_51 = F_21 ( F_90 ( V_2 ) , V_51 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_51 ;
}
static T_11 F_408 ( struct V_2 * V_2 , void * V_614 , T_9 V_615 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
int V_51 ;
if ( ! F_395 ( V_14 ) )
return - V_640 ;
V_51 = F_409 ( V_14 , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_78 ( V_2 ) -> V_174 & V_641 )
F_410 ( V_2 ) ;
V_51 = F_401 ( V_2 , V_614 , V_615 ) ;
if ( V_51 != - V_303 )
return V_51 ;
return F_406 ( V_2 , V_614 , V_615 ) ;
}
static int F_411 ( struct V_2 * V_2 , const void * V_614 , T_9 V_615 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_494 * V_42 [ V_628 ] ;
struct V_642 V_395 = {
. V_245 = F_98 ( V_2 ) ,
. V_630 = V_42 ,
. V_627 = V_615 ,
} ;
struct V_643 V_56 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_644 ] ,
. V_315 = & V_395 ,
. V_316 = & V_56 ,
} ;
unsigned int V_633 = F_405 ( V_615 , V_619 ) ;
int V_51 , V_483 ;
if ( ! F_395 ( V_14 ) )
return - V_640 ;
if ( V_633 > F_275 ( V_42 ) )
return - V_626 ;
V_483 = F_396 ( V_614 , V_615 , V_395 . V_630 , & V_395 . V_635 ) ;
if ( V_483 < 0 )
return V_483 ;
F_23 ( V_2 ) ;
V_51 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_395 . V_158 , & V_56 . V_159 , 1 ) ;
for (; V_483 > 0 ; V_483 -- )
F_412 ( V_42 [ V_483 - 1 ] ) ;
F_35 ( & V_2 -> V_173 ) ;
F_78 ( V_2 ) -> V_174 |= V_175 ;
F_37 ( & V_2 -> V_173 ) ;
F_413 ( V_2 ) ;
F_410 ( V_2 ) ;
return V_51 ;
}
static int F_414 ( struct V_2 * V_2 , const void * V_614 , T_9 V_615 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_411 ( V_2 , V_614 , V_615 ) ;
F_415 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_416 ( struct V_2 * V_2 , void * V_614 ,
T_9 V_615 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_391 V_392 ;
struct V_1 V_7 = { 0 , 0 , V_615 , V_614 } ;
T_1 V_242 [ 3 ] = { 0 , 0 , V_374 } ;
struct V_497 V_395 = {
. V_245 = F_98 ( V_2 ) ,
. V_242 = V_242 ,
} ;
struct V_498 V_56 = {
. V_392 = & V_392 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_499 ] ,
. V_315 = & V_395 ,
. V_316 = & V_56 ,
} ;
int V_51 ;
F_86 ( & V_392 ) ;
V_51 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_395 . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( V_392 . V_298 & V_645 ) )
return - V_303 ;
if ( V_615 < V_7 . V_12 )
return - V_626 ;
return 0 ;
}
static int F_417 ( struct V_2 * V_2 , void * V_614 ,
T_9 V_615 )
{
struct V_60 V_61 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_640 ;
do {
V_8 = F_416 ( V_2 , V_614 , V_615 ) ;
F_418 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_419 ( struct V_2 * V_2 ,
struct V_1 * V_393 ,
struct V_391 * V_392 ,
struct V_1 * V_382 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
const T_1 V_242 [ 3 ] = { 0 , 0 , V_374 } ;
struct V_394 V_395 = {
. V_245 = F_98 ( V_2 ) ,
. V_396 = & V_6 ,
. V_14 = V_14 ,
. V_242 = V_242 ,
. V_7 = V_393 ,
} ;
struct V_397 V_56 = {
. V_392 = V_392 ,
. V_7 = V_382 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_398 ] ,
. V_315 = & V_395 ,
. V_316 = & V_56 ,
} ;
int V_307 ;
F_132 ( & V_395 . V_251 , & V_408 ) ;
V_307 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_395 . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_307 )
F_8 ( L_41 , V_34 , V_307 ) ;
return V_307 ;
}
static int F_420 ( struct V_2 * V_2 ,
struct V_1 * V_393 ,
struct V_391 * V_392 ,
struct V_1 * V_382 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_419 ( V_2 , V_393 ,
V_392 , V_382 ) ;
F_421 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_422 ( struct V_4 * V_4 , const void * V_614 , T_9 V_615 )
{
struct V_1 V_393 , * V_382 = NULL ;
struct V_391 V_392 ;
struct V_317 * V_351 ;
struct V_2 * V_2 = F_14 ( V_4 ) ;
int V_307 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_640 ;
F_86 ( & V_392 ) ;
V_393 . V_646 = 0 ;
V_393 . V_647 = 0 ;
V_393 . V_7 = ( char * ) V_614 ;
V_393 . V_12 = V_615 ;
V_351 = F_423 () ;
if ( F_45 ( V_351 ) )
return F_74 ( V_351 ) ;
V_382 = F_92 ( F_90 ( V_2 ) , V_383 ) ;
if ( F_45 ( V_382 ) ) {
V_307 = - F_74 ( V_382 ) ;
goto V_129;
}
V_307 = F_420 ( V_2 , & V_393 , & V_392 , V_382 ) ;
if ( V_307 == 0 )
F_236 ( V_2 , & V_392 , V_382 ) ;
F_100 ( V_382 ) ;
V_129:
F_216 ( V_351 ) ;
return V_307 ;
}
static int
F_255 ( struct V_117 * V_118 , const struct V_13 * V_14 ,
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
goto V_648;
goto V_72;
case - V_73 :
if ( V_65 != NULL ) {
if ( F_24 ( V_14 , V_65 ) < 0 )
goto V_648;
}
case - V_74 :
case - V_75 :
F_25 ( V_63 ) ;
goto V_72;
case - V_76 :
if ( F_26 ( V_14 ) < 0 )
goto V_648;
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
F_424 ( V_14 , V_649 ) ;
F_62 ( V_118 , F_16 ( V_50 ) ) ;
goto V_650;
case - V_88 :
F_62 ( V_118 , V_52 ) ;
case - V_91 :
case - V_92 :
goto V_650;
}
V_118 -> V_147 = F_7 ( V_118 -> V_147 ) ;
return 0 ;
V_648:
V_118 -> V_147 = - V_35 ;
return 0 ;
V_72:
F_49 ( & V_63 -> V_651 , V_118 , NULL ) ;
if ( F_32 ( V_652 , & V_63 -> V_653 ) == 0 )
F_425 ( & V_63 -> V_651 , V_118 ) ;
if ( F_32 ( V_97 , & V_14 -> V_98 ) )
goto V_648;
V_650:
V_118 -> V_147 = 0 ;
return - V_128 ;
}
static void F_426 ( const struct V_62 * V_63 ,
T_12 * V_654 )
{
T_3 V_248 [ 2 ] ;
if ( F_32 ( V_655 , & V_63 -> V_653 ) ) {
V_248 [ 0 ] = 0 ;
V_248 [ 1 ] = F_427 ( V_656 + 1 ) ;
} else {
struct V_657 * V_658 = F_428 ( V_63 -> V_659 , V_660 ) ;
V_248 [ 0 ] = F_427 ( V_658 -> V_661 . V_662 ) ;
V_248 [ 1 ] = F_427 ( V_658 -> V_661 . V_663 ) ;
}
memcpy ( V_654 -> V_156 , V_248 , sizeof( V_654 -> V_156 ) ) ;
}
static int
F_429 ( struct V_62 * V_63 )
{
int V_664 ;
T_9 V_12 ;
char * V_665 ;
if ( V_63 -> V_666 != NULL )
return 0 ;
F_140 () ;
V_12 = 14 + strlen ( V_63 -> V_667 ) + 1 +
strlen ( F_430 ( V_63 -> V_100 , V_668 ) ) +
1 +
strlen ( F_430 ( V_63 -> V_100 , V_669 ) ) +
1 ;
F_143 () ;
if ( V_12 > V_670 + 1 )
return - V_27 ;
V_665 = F_284 ( V_12 , V_383 ) ;
if ( ! V_665 )
return - V_124 ;
F_140 () ;
V_664 = F_431 ( V_665 , V_12 , L_43 ,
V_63 -> V_667 ,
F_430 ( V_63 -> V_100 , V_668 ) ,
F_430 ( V_63 -> V_100 , V_669 ) ) ;
F_143 () ;
V_63 -> V_666 = V_665 ;
return 0 ;
}
static int
F_432 ( struct V_62 * V_63 )
{
int V_664 ;
T_9 V_12 ;
char * V_665 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_671 ) + 1 +
strlen ( V_63 -> V_100 -> V_672 ) + 1 ;
if ( V_12 > V_670 + 1 )
return - V_27 ;
V_665 = F_284 ( V_12 , V_383 ) ;
if ( ! V_665 )
return - V_124 ;
V_664 = F_431 ( V_665 , V_12 , L_44 ,
V_63 -> V_673 -> V_674 , V_63 -> V_432 ,
V_671 ,
V_63 -> V_100 -> V_672 ) ;
V_63 -> V_666 = V_665 ;
return 0 ;
}
static int
F_433 ( struct V_62 * V_63 )
{
int V_664 ;
T_9 V_12 ;
char * V_665 ;
if ( V_63 -> V_666 != NULL )
return 0 ;
if ( V_671 [ 0 ] != '\0' )
return F_432 ( V_63 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_63 -> V_100 -> V_672 ) + 1 ;
if ( V_12 > V_670 + 1 )
return - V_27 ;
V_665 = F_284 ( V_12 , V_383 ) ;
if ( ! V_665 )
return - V_124 ;
V_664 = F_431 ( V_665 , V_12 , L_45 ,
V_63 -> V_673 -> V_674 , V_63 -> V_432 ,
V_63 -> V_100 -> V_672 ) ;
V_63 -> V_666 = V_665 ;
return 0 ;
}
static unsigned int
F_434 ( const struct V_62 * V_63 , char * V_614 , T_9 V_12 )
{
if ( strchr ( V_63 -> V_667 , ':' ) != NULL )
return F_431 ( V_614 , V_12 , L_46 ) ;
else
return F_431 ( V_614 , V_12 , L_47 ) ;
}
static void F_435 ( struct V_117 * V_118 , void * V_154 )
{
struct V_675 * V_676 = V_154 ;
if ( V_118 -> V_147 == 0 )
V_676 -> V_677 = F_212 ( V_118 -> V_678 -> V_679 ) ;
}
int F_436 ( struct V_62 * V_63 , T_1 V_680 ,
unsigned short V_681 , struct V_317 * V_351 ,
struct V_682 * V_56 )
{
T_12 V_683 ;
struct V_675 V_684 = {
. V_683 = & V_683 ,
. V_685 = V_680 ,
. V_686 = V_63 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_687 ] ,
. V_315 = & V_684 ,
. V_316 = V_56 ,
. V_317 = V_351 ,
} ;
struct V_117 * V_118 ;
struct V_162 V_318 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_688 ,
. V_168 = & V_684 ,
. V_213 = V_612 ,
} ;
int V_307 ;
F_426 ( V_63 , & V_683 ) ;
if ( F_32 ( V_689 , & V_63 -> V_690 ) )
V_307 = F_433 ( V_63 ) ;
else
V_307 = F_429 ( V_63 ) ;
if ( V_307 )
goto V_129;
V_684 . V_691 =
F_434 ( V_63 ,
V_684 . V_692 ,
sizeof( V_684 . V_692 ) ) ;
V_684 . V_693 = F_431 ( V_684 . V_694 ,
sizeof( V_684 . V_694 ) , L_48 ,
V_63 -> V_667 , V_681 >> 8 , V_681 & 255 ) ;
F_8 ( L_49 ,
V_63 -> V_100 -> V_101 -> V_695 -> V_696 ,
V_63 -> V_666 ) ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) ) {
V_307 = F_74 ( V_118 ) ;
goto V_129;
}
V_307 = V_118 -> V_147 ;
if ( V_684 . V_677 ) {
V_63 -> V_697 = F_437 ( V_684 . V_677 ) ;
F_216 ( V_684 . V_677 ) ;
}
F_75 ( V_118 ) ;
V_129:
F_438 ( V_63 , V_307 ) ;
F_8 ( L_50 , V_307 ) ;
return V_307 ;
}
int F_439 ( struct V_62 * V_63 ,
struct V_682 * V_395 ,
struct V_317 * V_351 )
{
struct V_160 V_161 = {
. V_312 = & V_313 [ V_698 ] ,
. V_315 = V_395 ,
. V_317 = V_351 ,
} ;
int V_307 ;
F_8 ( L_51 ,
V_63 -> V_100 -> V_101 -> V_695 -> V_696 ,
V_63 -> V_236 ) ;
V_307 = F_394 ( V_63 -> V_100 , & V_161 , V_612 ) ;
F_440 ( V_63 , V_307 ) ;
F_8 ( L_52 , V_307 ) ;
return V_307 ;
}
static void F_441 ( struct V_117 * V_118 , void * V_154 )
{
struct V_699 * V_156 = V_154 ;
if ( ! F_63 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
F_442 ( & V_156 -> args , & V_156 -> V_56 , V_118 -> V_147 ) ;
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
if ( V_156 -> V_412 )
F_254 ( V_156 -> V_2 , V_156 -> V_414 ) ;
break;
default:
if ( F_255 ( V_118 , V_156 -> V_56 . V_14 ,
NULL , NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return;
}
}
V_156 -> V_295 = V_118 -> V_147 ;
}
static void F_443 ( void * V_154 )
{
struct V_699 * V_156 = V_154 ;
struct V_2 * V_2 = V_156 -> V_2 ;
if ( V_2 ) {
if ( V_156 -> V_412 )
F_251 ( V_2 ) ;
F_444 ( V_2 ) ;
}
F_101 ( V_154 ) ;
}
static void F_445 ( struct V_117 * V_118 , void * V_156 )
{
struct V_699 * V_700 ;
V_700 = (struct V_699 * ) V_156 ;
if ( F_247 ( V_700 -> V_2 , V_118 ) )
return;
if ( V_700 -> V_412 )
F_257 ( V_700 -> V_2 , & V_700 -> V_414 ) ;
F_66 ( V_700 -> V_56 . V_14 ,
& V_700 -> args . V_158 ,
& V_700 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_446 ( struct V_2 * V_2 , struct V_317 * V_351 , const T_8 * V_251 , int V_701 )
{
struct V_699 * V_156 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_702 ] ,
. V_317 = V_351 ,
} ;
struct V_162 V_318 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_703 ,
. V_213 = V_322 ,
} ;
int V_307 = 0 ;
V_156 = F_91 ( sizeof( * V_156 ) , V_304 ) ;
if ( V_156 == NULL )
return - V_124 ;
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_156 -> args . V_430 = & V_156 -> V_245 ;
V_156 -> args . V_251 = & V_156 -> V_251 ;
V_156 -> args . V_242 = V_14 -> V_426 ;
F_188 ( & V_156 -> V_245 , F_98 ( V_2 ) ) ;
F_132 ( & V_156 -> V_251 , V_251 ) ;
V_156 -> V_56 . V_392 = & V_156 -> V_392 ;
V_156 -> V_56 . V_14 = V_14 ;
F_86 ( V_156 -> V_56 . V_392 ) ;
V_156 -> V_105 = V_152 ;
V_156 -> V_295 = 0 ;
V_156 -> V_2 = F_447 ( V_2 ) ;
if ( V_156 -> V_2 )
V_156 -> V_412 = F_258 ( V_2 ) ;
V_318 . V_168 = V_156 ;
V_161 . V_315 = & V_156 -> args ;
V_161 . V_316 = & V_156 -> V_56 ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
if ( ! V_701 )
goto V_129;
V_307 = F_112 ( V_118 ) ;
if ( V_307 != 0 )
goto V_129;
V_307 = V_156 -> V_295 ;
if ( V_307 == 0 )
F_448 ( V_2 , & V_156 -> V_392 ) ;
else
F_154 ( V_2 , & V_156 -> V_392 ) ;
V_129:
F_75 ( V_118 ) ;
return V_307 ;
}
int F_449 ( struct V_2 * V_2 , struct V_317 * V_351 , const T_8 * V_251 , int V_701 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_446 ( V_2 , V_351 , V_251 , V_701 ) ;
F_450 ( V_2 , V_8 ) ;
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
F_451 ( unsigned long V_50 )
{
F_19 ( V_50 ) ;
V_50 <<= 1 ;
if ( V_50 > V_704 )
return V_704 ;
return V_50 ;
}
static int F_452 ( struct V_64 * V_65 , int V_705 , struct V_706 * V_707 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_708 V_395 = {
. V_245 = F_98 ( V_2 ) ,
. V_709 = V_707 ,
} ;
struct V_710 V_56 = {
. V_711 = V_707 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_712 ] ,
. V_315 = & V_395 ,
. V_316 = & V_56 ,
. V_317 = V_65 -> V_226 -> V_292 ,
} ;
struct V_283 * V_284 ;
int V_307 ;
V_395 . V_713 . V_235 = V_63 -> V_236 ;
V_307 = F_453 ( V_65 , V_707 ) ;
if ( V_307 != 0 )
goto V_129;
V_284 = V_707 -> V_714 . V_715 . V_226 ;
V_395 . V_713 . V_237 = V_284 -> V_716 . V_240 ;
V_395 . V_713 . V_717 = V_14 -> V_717 ;
V_307 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & V_395 . V_158 , & V_56 . V_159 , 1 ) ;
switch ( V_307 ) {
case 0 :
V_707 -> V_718 = V_719 ;
break;
case - V_309 :
V_307 = 0 ;
}
V_707 -> V_720 -> V_721 ( V_707 ) ;
V_707 -> V_720 = NULL ;
V_129:
return V_307 ;
}
static int F_454 ( struct V_64 * V_65 , int V_705 , struct V_706 * V_707 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_452 ( V_65 , V_705 , V_707 ) ;
F_455 ( V_707 , V_65 , V_705 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_65 -> V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_456 ( struct V_2 * V_2 , struct V_706 * V_709 )
{
int V_56 = 0 ;
switch ( V_709 -> V_722 & ( V_723 | V_724 ) ) {
case V_723 :
V_56 = F_457 ( V_2 , V_709 ) ;
break;
case V_724 :
V_56 = F_458 ( V_2 , V_709 ) ;
break;
default:
F_459 () ;
}
return V_56 ;
}
static struct V_725 * F_460 ( struct V_706 * V_709 ,
struct V_301 * V_302 ,
struct V_283 * V_284 ,
struct V_217 * V_203 )
{
struct V_725 * V_41 ;
struct V_2 * V_2 = V_284 -> V_285 -> V_2 ;
V_41 = F_91 ( sizeof( * V_41 ) , V_304 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_395 . V_245 = F_98 ( V_2 ) ;
V_41 -> V_395 . V_709 = & V_41 -> V_709 ;
V_41 -> V_395 . V_203 = V_203 ;
V_41 -> V_56 . V_203 = V_203 ;
V_41 -> V_284 = V_284 ;
F_95 ( & V_284 -> V_726 ) ;
V_41 -> V_302 = F_162 ( V_302 ) ;
memcpy ( & V_41 -> V_709 , V_709 , sizeof( V_41 -> V_709 ) ) ;
V_41 -> V_14 = F_90 ( V_2 ) ;
return V_41 ;
}
static void F_461 ( void * V_156 )
{
struct V_725 * V_154 = V_156 ;
F_105 ( V_154 -> V_395 . V_203 ) ;
F_462 ( V_154 -> V_284 ) ;
F_174 ( V_154 -> V_302 ) ;
F_101 ( V_154 ) ;
}
static void F_463 ( struct V_117 * V_118 , void * V_156 )
{
struct V_725 * V_154 = V_156 ;
if ( ! F_63 ( V_118 , & V_154 -> V_56 . V_159 ) )
return;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( V_154 -> V_14 , V_154 -> V_105 ) ;
F_456 ( V_154 -> V_284 -> V_285 -> V_2 , & V_154 -> V_709 ) ;
if ( F_144 ( V_154 -> V_284 ,
& V_154 -> V_56 . V_251 ) )
break;
case - V_70 :
case - V_92 :
case - V_74 :
case - V_73 :
if ( ! F_142 ( & V_154 -> V_395 . V_251 ,
& V_154 -> V_284 -> V_287 ) )
F_60 ( V_118 ) ;
break;
default:
if ( F_255 ( V_118 , V_154 -> V_14 ,
NULL , NULL ) == - V_128 )
F_60 ( V_118 ) ;
}
F_147 ( V_154 -> V_395 . V_203 ) ;
}
static void F_464 ( struct V_117 * V_118 , void * V_156 )
{
struct V_725 * V_154 = V_156 ;
if ( F_187 ( V_154 -> V_395 . V_203 , V_118 ) != 0 )
goto V_323;
F_132 ( & V_154 -> V_395 . V_251 , & V_154 -> V_284 -> V_287 ) ;
if ( F_32 ( V_727 , & V_154 -> V_284 -> V_728 ) == 0 ) {
goto V_324;
}
V_154 -> V_105 = V_152 ;
if ( F_66 ( V_154 -> V_14 ,
& V_154 -> V_395 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) != 0 )
F_147 ( V_154 -> V_395 . V_203 ) ;
return;
V_324:
V_118 -> V_335 = NULL ;
V_323:
F_63 ( V_118 , & V_154 -> V_56 . V_159 ) ;
}
static struct V_117 * F_465 ( struct V_706 * V_709 ,
struct V_301 * V_302 ,
struct V_283 * V_284 ,
struct V_217 * V_203 )
{
struct V_725 * V_156 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_729 ] ,
. V_317 = V_302 -> V_351 ,
} ;
struct V_162 V_318 = {
. V_164 = F_302 ( V_284 -> V_285 -> V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_730 ,
. V_320 = V_321 ,
. V_213 = V_322 ,
} ;
F_261 ( F_90 ( V_284 -> V_285 -> V_2 ) -> V_62 ,
V_424 , & V_318 . V_164 , & V_161 ) ;
V_709 -> V_718 = V_719 ;
V_156 = F_460 ( V_709 , V_302 , V_284 , V_203 ) ;
if ( V_156 == NULL ) {
F_105 ( V_203 ) ;
return F_46 ( - V_124 ) ;
}
F_40 ( & V_156 -> V_395 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_161 . V_315 = & V_156 -> V_395 ;
V_161 . V_316 = & V_156 -> V_56 ;
V_318 . V_168 = V_156 ;
return F_73 ( & V_318 ) ;
}
static int F_466 ( struct V_64 * V_65 , int V_705 , struct V_706 * V_707 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_211 * V_212 = V_65 -> V_226 ;
struct V_171 * V_172 = F_78 ( V_2 ) ;
struct V_217 * V_203 ;
struct V_283 * V_284 ;
struct V_117 * V_118 ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
int V_307 = 0 ;
unsigned char V_722 = V_707 -> V_722 ;
V_307 = F_453 ( V_65 , V_707 ) ;
V_707 -> V_722 |= V_731 ;
F_467 ( & V_212 -> V_732 ) ;
F_468 ( & V_172 -> V_733 ) ;
if ( F_456 ( V_2 , V_707 ) == - V_303 ) {
F_469 ( & V_172 -> V_733 ) ;
F_470 ( & V_212 -> V_732 ) ;
goto V_129;
}
F_469 ( & V_172 -> V_733 ) ;
F_470 ( & V_212 -> V_732 ) ;
if ( V_307 != 0 )
goto V_129;
V_284 = V_707 -> V_714 . V_715 . V_226 ;
if ( F_32 ( V_727 , & V_284 -> V_728 ) == 0 )
goto V_129;
V_218 = F_90 ( V_2 ) -> V_62 -> V_166 -> V_218 ;
V_203 = V_218 ( & V_284 -> V_716 , V_383 ) ;
V_307 = - V_124 ;
if ( F_45 ( V_203 ) )
goto V_129;
V_118 = F_465 ( V_707 , F_294 ( V_707 -> V_734 ) , V_284 , V_203 ) ;
V_307 = F_74 ( V_118 ) ;
if ( F_45 ( V_118 ) )
goto V_129;
V_307 = F_112 ( V_118 ) ;
F_75 ( V_118 ) ;
V_129:
V_707 -> V_722 = V_722 ;
F_471 ( V_707 , V_65 , V_735 , V_307 ) ;
return V_307 ;
}
static struct V_736 * F_472 ( struct V_706 * V_709 ,
struct V_301 * V_302 , struct V_283 * V_284 ,
T_6 V_215 )
{
struct V_736 * V_41 ;
struct V_2 * V_2 = V_284 -> V_285 -> V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
V_41 = F_91 ( sizeof( * V_41 ) , V_215 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_395 . V_245 = F_98 ( V_2 ) ;
V_41 -> V_395 . V_709 = & V_41 -> V_709 ;
V_41 -> V_395 . V_737 = F_473 ( & V_284 -> V_285 -> V_226 -> V_223 , V_215 ) ;
if ( F_45 ( V_41 -> V_395 . V_737 ) )
goto V_311;
V_218 = V_14 -> V_62 -> V_166 -> V_218 ;
V_41 -> V_395 . V_738 = V_218 ( & V_284 -> V_716 , V_215 ) ;
if ( F_45 ( V_41 -> V_395 . V_738 ) )
goto V_739;
V_41 -> V_395 . V_713 . V_235 = V_14 -> V_62 -> V_236 ;
V_41 -> V_395 . V_713 . V_237 = V_284 -> V_716 . V_240 ;
V_41 -> V_395 . V_713 . V_717 = V_14 -> V_717 ;
V_41 -> V_56 . V_738 = V_41 -> V_395 . V_738 ;
V_41 -> V_284 = V_284 ;
V_41 -> V_14 = V_14 ;
F_95 ( & V_284 -> V_726 ) ;
V_41 -> V_302 = F_162 ( V_302 ) ;
F_474 ( V_709 -> V_734 ) ;
memcpy ( & V_41 -> V_709 , V_709 , sizeof( V_41 -> V_709 ) ) ;
return V_41 ;
V_739:
F_105 ( V_41 -> V_395 . V_737 ) ;
V_311:
F_101 ( V_41 ) ;
return NULL ;
}
static void F_475 ( struct V_117 * V_118 , void * V_154 )
{
struct V_736 * V_156 = V_154 ;
struct V_64 * V_65 = V_156 -> V_284 -> V_285 ;
F_8 ( L_29 , V_34 ) ;
if ( F_187 ( V_156 -> V_395 . V_738 , V_118 ) != 0 )
goto V_323;
if ( ! F_32 ( V_727 , & V_156 -> V_284 -> V_728 ) ) {
if ( F_187 ( V_156 -> V_395 . V_737 , V_118 ) != 0 ) {
goto V_740;
}
F_132 ( & V_156 -> V_395 . V_272 ,
& V_65 -> V_272 ) ;
V_156 -> V_395 . V_741 = 1 ;
V_156 -> V_56 . V_737 = V_156 -> V_395 . V_737 ;
} else {
V_156 -> V_395 . V_741 = 0 ;
F_132 ( & V_156 -> V_395 . V_742 ,
& V_156 -> V_284 -> V_287 ) ;
}
if ( ! F_243 ( V_65 ) ) {
V_156 -> V_295 = - V_407 ;
V_118 -> V_335 = NULL ;
goto V_743;
}
V_156 -> V_105 = V_152 ;
if ( F_66 ( V_156 -> V_14 ,
& V_156 -> V_395 . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) == 0 )
return;
V_743:
F_147 ( V_156 -> V_395 . V_737 ) ;
V_740:
F_147 ( V_156 -> V_395 . V_738 ) ;
V_323:
F_63 ( V_118 , & V_156 -> V_56 . V_159 ) ;
F_8 ( L_53 , V_34 , V_156 -> V_295 ) ;
}
static void F_476 ( struct V_117 * V_118 , void * V_154 )
{
struct V_736 * V_156 = V_154 ;
struct V_283 * V_284 = V_156 -> V_284 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_63 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
V_156 -> V_295 = V_118 -> V_147 ;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( F_90 ( F_14 ( V_156 -> V_302 -> V_4 ) ) ,
V_156 -> V_105 ) ;
if ( V_156 -> V_395 . V_744 ) {
V_156 -> V_709 . V_722 &= ~ ( V_745 | V_746 ) ;
if ( F_456 ( V_284 -> V_285 -> V_2 , & V_156 -> V_709 ) < 0 ) {
F_60 ( V_118 ) ;
break;
}
}
if ( V_156 -> V_395 . V_741 != 0 ) {
F_181 ( & V_284 -> V_716 , 0 ) ;
F_132 ( & V_284 -> V_287 , & V_156 -> V_56 . V_251 ) ;
F_129 ( V_727 , & V_284 -> V_728 ) ;
} else if ( ! F_144 ( V_284 , & V_156 -> V_56 . V_251 ) )
F_60 ( V_118 ) ;
break;
case - V_70 :
case - V_92 :
case - V_74 :
case - V_73 :
if ( V_156 -> V_395 . V_741 != 0 ) {
if ( ! F_142 ( & V_156 -> V_395 . V_272 ,
& V_284 -> V_285 -> V_272 ) )
F_60 ( V_118 ) ;
} else if ( ! F_142 ( & V_156 -> V_395 . V_742 ,
& V_284 -> V_287 ) )
F_60 ( V_118 ) ;
}
F_8 ( L_30 , V_34 , V_156 -> V_295 ) ;
}
static void F_477 ( void * V_154 )
{
struct V_736 * V_156 = V_154 ;
F_8 ( L_29 , V_34 ) ;
F_105 ( V_156 -> V_395 . V_737 ) ;
if ( V_156 -> V_310 != 0 ) {
struct V_117 * V_118 ;
V_118 = F_465 ( & V_156 -> V_709 , V_156 -> V_302 , V_156 -> V_284 ,
V_156 -> V_395 . V_738 ) ;
if ( ! F_45 ( V_118 ) )
F_478 ( V_118 ) ;
F_8 ( L_54 , V_34 ) ;
} else
F_105 ( V_156 -> V_395 . V_738 ) ;
F_462 ( V_156 -> V_284 ) ;
F_174 ( V_156 -> V_302 ) ;
F_479 ( V_156 -> V_709 . V_734 ) ;
F_101 ( V_156 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_480 ( struct V_13 * V_14 , struct V_283 * V_284 , int V_741 , int error )
{
switch ( error ) {
case - V_69 :
case - V_70 :
V_284 -> V_716 . V_213 &= ~ V_747 ;
if ( V_741 != 0 ||
F_32 ( V_727 , & V_284 -> V_728 ) != 0 )
F_24 ( V_14 , V_284 -> V_285 ) ;
break;
case - V_74 :
V_284 -> V_716 . V_213 &= ~ V_747 ;
case - V_73 :
F_25 ( V_14 -> V_62 ) ;
} ;
}
static int F_481 ( struct V_64 * V_65 , int V_705 , struct V_706 * V_709 , int V_748 )
{
struct V_736 * V_156 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_749 ] ,
. V_317 = V_65 -> V_226 -> V_292 ,
} ;
struct V_162 V_318 = {
. V_164 = F_302 ( V_65 -> V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_750 ,
. V_320 = V_321 ,
. V_213 = V_322 ,
} ;
int V_51 ;
F_8 ( L_29 , V_34 ) ;
V_156 = F_472 ( V_709 , F_294 ( V_709 -> V_734 ) ,
V_709 -> V_714 . V_715 . V_226 ,
V_748 == V_751 ? V_383 : V_304 ) ;
if ( V_156 == NULL )
return - V_124 ;
if ( F_482 ( V_705 ) )
V_156 -> V_395 . V_752 = 1 ;
F_40 ( & V_156 -> V_395 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_161 . V_315 = & V_156 -> V_395 ;
V_161 . V_316 = & V_156 -> V_56 ;
V_318 . V_168 = V_156 ;
if ( V_748 > V_751 ) {
if ( V_748 == V_753 )
V_156 -> V_395 . V_754 = V_753 ;
F_41 ( & V_156 -> V_395 . V_158 ) ;
} else
V_156 -> V_395 . V_744 = 1 ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_51 = F_112 ( V_118 ) ;
if ( V_51 == 0 ) {
V_51 = V_156 -> V_295 ;
if ( V_51 )
F_480 ( V_156 -> V_14 , V_156 -> V_284 ,
V_156 -> V_395 . V_741 , V_51 ) ;
} else
V_156 -> V_310 = 1 ;
F_75 ( V_118 ) ;
F_8 ( L_30 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_483 ( struct V_64 * V_65 , struct V_706 * V_707 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_32 ( V_274 , & V_65 -> V_213 ) != 0 )
return 0 ;
V_8 = F_481 ( V_65 , V_735 , V_707 , V_753 ) ;
F_484 ( V_707 , V_65 , V_735 , V_8 ) ;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_485 ( struct V_64 * V_65 , struct V_706 * V_707 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
V_8 = F_453 ( V_65 , V_707 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_755 ) {
F_129 ( V_756 , & V_707 -> V_714 . V_715 . V_226 -> V_728 ) ;
return 0 ;
}
do {
if ( F_32 ( V_274 , & V_65 -> V_213 ) != 0 )
return 0 ;
V_8 = F_481 ( V_65 , V_735 , V_707 , V_757 ) ;
F_486 ( V_707 , V_65 , V_735 , V_8 ) ;
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
static int F_487 ( struct V_64 * V_65 )
{
int V_307 , V_51 = - V_70 ;
struct V_283 * V_284 ;
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
F_161 (lsp, &state->lock_states, ls_locks) {
if ( F_32 ( V_727 , & V_284 -> V_728 ) ) {
struct V_317 * V_351 = V_284 -> V_285 -> V_226 -> V_292 ;
V_307 = F_213 ( V_14 ,
& V_284 -> V_287 ,
V_351 ) ;
F_488 ( V_65 , V_284 , V_307 ) ;
if ( V_307 != V_364 ) {
if ( V_307 != - V_70 )
F_215 ( V_14 ,
& V_284 -> V_287 ,
V_351 ) ;
F_131 ( V_727 , & V_284 -> V_728 ) ;
V_51 = V_307 ;
}
}
} ;
return V_51 ;
}
static int F_489 ( struct V_64 * V_65 , struct V_706 * V_707 )
{
int V_307 = V_364 ;
if ( F_32 ( V_758 , & V_65 -> V_213 ) )
V_307 = F_487 ( V_65 ) ;
if ( V_307 != V_364 )
V_307 = F_485 ( V_65 , V_707 ) ;
return V_307 ;
}
static int F_490 ( struct V_64 * V_65 , int V_705 , struct V_706 * V_707 )
{
struct V_171 * V_172 = F_78 ( V_65 -> V_2 ) ;
unsigned char V_722 = V_707 -> V_722 ;
int V_307 = - V_759 ;
if ( ( V_722 & V_723 ) &&
! F_32 ( V_377 , & V_65 -> V_213 ) )
goto V_129;
V_307 = F_453 ( V_65 , V_707 ) ;
if ( V_307 != 0 )
goto V_129;
V_707 -> V_722 |= V_746 ;
V_307 = F_456 ( V_65 -> V_2 , V_707 ) ;
if ( V_307 < 0 )
goto V_129;
F_468 ( & V_172 -> V_733 ) ;
if ( F_32 ( V_274 , & V_65 -> V_213 ) ) {
V_707 -> V_722 = V_722 & ~ V_745 ;
V_307 = F_456 ( V_65 -> V_2 , V_707 ) ;
F_469 ( & V_172 -> V_733 ) ;
goto V_129;
}
F_469 ( & V_172 -> V_733 ) ;
V_307 = F_481 ( V_65 , V_705 , V_707 , V_751 ) ;
V_129:
V_707 -> V_722 = V_722 ;
return V_307 ;
}
static int F_491 ( struct V_64 * V_65 , int V_705 , struct V_706 * V_707 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_490 ( V_65 , V_705 , V_707 ) ;
F_492 ( V_707 , V_65 , V_705 , V_8 ) ;
if ( V_8 == - V_309 )
V_8 = - V_128 ;
V_8 = F_21 ( F_90 ( V_65 -> V_2 ) ,
V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_493 ( struct V_760 * V_761 , int V_705 , struct V_706 * V_707 )
{
struct V_301 * V_302 ;
struct V_64 * V_65 ;
unsigned long V_50 = V_762 ;
int V_307 ;
V_302 = F_294 ( V_761 ) ;
V_65 = V_302 -> V_65 ;
if ( V_707 -> V_763 < 0 || V_707 -> V_764 < 0 )
return - V_27 ;
if ( F_494 ( V_705 ) ) {
if ( V_65 != NULL )
return F_454 ( V_65 , V_765 , V_707 ) ;
return 0 ;
}
if ( ! ( F_495 ( V_705 ) || F_482 ( V_705 ) ) )
return - V_27 ;
if ( V_707 -> V_718 == V_719 ) {
if ( V_65 != NULL )
return F_466 ( V_65 , V_705 , V_707 ) ;
return 0 ;
}
if ( V_65 == NULL )
return - V_759 ;
switch ( V_707 -> V_718 ) {
case V_766 :
if ( ! ( V_761 -> V_767 & V_71 ) )
return - V_407 ;
break;
case V_768 :
if ( ! ( V_761 -> V_767 & V_185 ) )
return - V_407 ;
}
do {
V_307 = F_491 ( V_65 , V_705 , V_707 ) ;
if ( ( V_307 != - V_128 ) || F_495 ( V_705 ) )
break;
V_50 = F_451 ( V_50 ) ;
V_307 = - V_58 ;
if ( F_496 () )
break;
} while( V_307 < 0 );
return V_307 ;
}
int F_497 ( struct V_706 * V_709 , struct V_64 * V_65 , const T_8 * V_251 )
{
struct V_13 * V_14 = F_90 ( V_65 -> V_2 ) ;
int V_8 ;
V_8 = F_453 ( V_65 , V_709 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_481 ( V_65 , V_735 , V_709 , V_751 ) ;
return F_175 ( V_14 , V_65 , V_251 , V_8 ) ;
}
static void F_498 ( struct V_117 * V_118 , void * V_154 )
{
struct V_769 * V_156 = V_154 ;
struct V_13 * V_14 = V_156 -> V_14 ;
F_42 ( V_14 -> V_62 -> V_153 ,
& V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , V_118 ) ;
V_156 -> args . V_713 . V_235 = V_14 -> V_62 -> V_236 ;
V_156 -> V_105 = V_152 ;
}
static void F_499 ( struct V_117 * V_118 , void * V_154 )
{
struct V_769 * V_156 = V_154 ;
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
if ( F_255 ( V_118 , V_14 ,
NULL , NULL ) == - V_128 )
F_60 ( V_118 ) ;
}
}
static void F_500 ( void * V_154 )
{
struct V_769 * V_156 = V_154 ;
F_501 ( V_156 -> V_14 , V_156 -> V_284 ) ;
F_101 ( V_154 ) ;
}
static void
F_502 ( struct V_13 * V_14 , struct V_283 * V_284 )
{
struct V_769 * V_156 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_770 ] ,
} ;
if ( V_14 -> V_62 -> V_166 -> V_333 != 0 )
return;
V_156 = F_284 ( sizeof( * V_156 ) , V_304 ) ;
if ( ! V_156 )
return;
V_156 -> V_284 = V_284 ;
V_156 -> V_14 = V_14 ;
V_156 -> args . V_713 . V_235 = V_14 -> V_62 -> V_236 ;
V_156 -> args . V_713 . V_237 = V_284 -> V_716 . V_240 ;
V_156 -> args . V_713 . V_717 = V_14 -> V_717 ;
V_161 . V_315 = & V_156 -> args ;
V_161 . V_316 = & V_156 -> V_56 ;
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 0 ) ;
F_392 ( V_14 -> V_90 , & V_161 , 0 , & V_771 , V_156 ) ;
}
static int F_503 ( struct V_4 * V_4 , const char * V_772 ,
const void * V_614 , T_9 V_615 ,
int V_213 , int type )
{
if ( strcmp ( V_772 , L_55 ) != 0 )
return - V_27 ;
return F_414 ( F_14 ( V_4 ) , V_614 , V_615 ) ;
}
static int F_504 ( struct V_4 * V_4 , const char * V_772 ,
void * V_614 , T_9 V_615 , int type )
{
if ( strcmp ( V_772 , L_55 ) != 0 )
return - V_27 ;
return F_408 ( F_14 ( V_4 ) , V_614 , V_615 ) ;
}
static T_9 F_505 ( struct V_4 * V_4 , char * V_773 ,
T_9 V_774 , const char * V_241 ,
T_9 V_775 , int type )
{
T_9 V_12 = sizeof( V_776 ) ;
if ( ! F_395 ( F_90 ( F_14 ( V_4 ) ) ) )
return 0 ;
if ( V_773 && V_12 <= V_774 )
memcpy ( V_773 , V_776 , V_12 ) ;
return V_12 ;
}
static inline int F_506 ( struct V_13 * V_14 )
{
return V_14 -> V_93 & V_9 ;
}
static int F_507 ( struct V_4 * V_4 , const char * V_772 ,
const void * V_614 , T_9 V_615 ,
int V_213 , int type )
{
if ( F_508 ( V_772 ) )
return F_422 ( V_4 , V_614 , V_615 ) ;
return - V_640 ;
}
static int F_509 ( struct V_4 * V_4 , const char * V_772 ,
void * V_614 , T_9 V_615 , int type )
{
if ( F_508 ( V_772 ) )
return F_417 ( F_14 ( V_4 ) , V_614 , V_615 ) ;
return - V_640 ;
}
static T_9 F_510 ( struct V_4 * V_4 , char * V_773 ,
T_9 V_774 , const char * V_241 ,
T_9 V_775 , int type )
{
T_9 V_12 = 0 ;
if ( F_2 ( F_14 ( V_4 ) , V_9 ) ) {
V_12 = F_511 ( F_14 ( V_4 ) , NULL , 0 ) ;
if ( V_773 && V_12 <= V_774 )
F_511 ( F_14 ( V_4 ) , V_773 , V_12 ) ;
}
return V_12 ;
}
static void F_286 ( struct V_391 * V_392 )
{
if ( ! ( ( ( V_392 -> V_298 & V_777 ) ||
( V_392 -> V_298 & V_778 ) ) &&
( V_392 -> V_298 & V_491 ) &&
( V_392 -> V_298 & V_779 ) ) )
return;
V_392 -> V_298 |= V_336 | V_507 |
V_508 | V_780 ;
V_392 -> V_259 = V_341 | V_510 | V_511 ;
V_392 -> V_512 = 2 ;
}
static int F_512 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_493 * V_241 ,
struct V_495 * V_781 ,
struct V_494 * V_494 )
{
struct V_13 * V_14 = F_90 ( V_3 ) ;
T_1 V_242 [ 3 ] = {
[ 0 ] = V_782 | V_783 ,
} ;
struct V_784 args = {
. V_505 = F_98 ( V_3 ) ,
. V_241 = V_241 ,
. V_494 = V_494 ,
. V_242 = V_242 ,
} ;
struct V_785 V_56 = {
. V_781 = V_781 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_786 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
int V_307 ;
F_8 ( L_56 , V_34 ) ;
if ( F_90 ( V_3 ) -> V_15 [ 1 ] & V_787 )
V_242 [ 1 ] |= V_787 ;
else
V_242 [ 0 ] |= V_45 ;
F_86 ( & V_781 -> V_392 ) ;
V_781 -> V_14 = V_14 ;
V_781 -> V_788 = 0 ;
V_307 = F_76 ( V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
F_8 ( L_57 , V_34 , V_307 ) ;
return V_307 ;
}
int F_285 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_493 * V_241 ,
struct V_495 * V_781 ,
struct V_494 * V_494 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_512 ( V_90 , V_3 , V_241 ,
V_781 , V_494 ) ;
F_513 ( V_3 , V_241 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_514 ( struct V_2 * V_2 ,
struct V_495 * V_496 ,
struct V_494 * V_494 , struct V_317 * V_351 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
T_1 V_242 [ 2 ] = {
[ 0 ] = V_782 | V_783 ,
} ;
struct V_784 args = {
. V_235 = V_14 -> V_62 -> V_236 ,
. V_245 = F_98 ( V_2 ) ,
. V_494 = V_494 ,
. V_242 = V_242 ,
. V_789 = 1 ,
. V_790 = 1 ,
} ;
struct V_785 V_56 = {
. V_781 = V_496 ,
. V_789 = 1 ,
. V_790 = 1 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_786 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
unsigned long V_574 = V_152 ;
int V_307 ;
F_86 ( & V_496 -> V_392 ) ;
V_496 -> V_14 = V_14 ;
V_496 -> V_788 = 0 ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_307 = F_72 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_307 )
return V_307 ;
F_38 ( V_14 , V_574 ) ;
return 0 ;
}
static int F_515 ( struct V_2 * V_2 ,
struct V_495 * V_496 ,
struct V_494 * V_494 , struct V_317 * V_351 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
T_1 V_242 [ 2 ] = {
[ 0 ] = V_782 | V_783 ,
} ;
struct V_784 args = {
. V_245 = F_98 ( V_2 ) ,
. V_494 = V_494 ,
. V_242 = V_242 ,
. V_789 = 1 ,
} ;
struct V_785 V_56 = {
. V_781 = V_496 ,
. V_789 = 1 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_786 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
int V_307 ;
F_86 ( & V_496 -> V_392 ) ;
V_496 -> V_14 = V_14 ;
V_496 -> V_788 = 0 ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_307 = F_72 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_307 == V_791 &&
V_56 . V_159 . V_143 & V_792 )
V_307 = - V_77 ;
return V_307 ;
}
int F_516 ( struct V_2 * V_2 ,
struct V_495 * V_496 ,
struct V_494 * V_494 , struct V_317 * V_351 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_793 * V_794 =
V_63 -> V_166 -> V_795 ;
struct V_60 V_61 = { } ;
int V_307 ;
F_8 ( L_58 , V_34 ,
( unsigned long long ) V_14 -> V_492 . V_796 ,
( unsigned long long ) V_14 -> V_492 . V_797 ,
V_63 -> V_96 ) ;
F_517 ( F_98 ( V_2 ) , V_34 ) ;
do {
V_307 = V_794 -> V_798 ( V_2 , V_496 , V_494 , V_351 ) ;
if ( V_307 != - V_89 )
break;
F_21 ( V_14 , V_307 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_307 ;
}
static int F_518 ( struct V_2 * V_2 , struct V_317 * V_351 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_62 * V_63 = F_90 ( V_2 ) -> V_62 ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_799 args = {
. V_245 = F_98 ( V_2 ) ,
. V_235 = V_63 -> V_236 ,
. V_790 = 1 ,
} ;
struct V_800 V_56 = {
. V_790 = 1 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_801 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
unsigned long V_574 = V_152 ;
int V_307 ;
V_56 . V_245 = F_519 () ;
if ( V_56 . V_245 == NULL )
return - V_124 ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_307 = F_72 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
F_520 ( V_56 . V_245 ) ;
if ( V_307 )
return V_307 ;
F_34 ( V_63 , V_574 ) ;
return 0 ;
}
static int F_521 ( struct V_2 * V_2 , struct V_317 * V_351 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_799 args = {
. V_245 = F_98 ( V_2 ) ,
} ;
struct V_800 V_56 = {
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_801 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
int V_307 ;
V_56 . V_245 = F_519 () ;
if ( V_56 . V_245 == NULL )
return - V_124 ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_307 = F_72 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
F_520 ( V_56 . V_245 ) ;
if ( V_307 == V_791 &&
V_56 . V_159 . V_143 & V_792 )
V_307 = - V_77 ;
return V_307 ;
}
int F_522 ( struct V_2 * V_2 , struct V_317 * V_351 )
{
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_793 * V_794 =
V_63 -> V_166 -> V_795 ;
struct V_60 V_61 = { } ;
int V_307 ;
F_8 ( L_58 , V_34 ,
( unsigned long long ) V_14 -> V_492 . V_796 ,
( unsigned long long ) V_14 -> V_492 . V_797 ,
V_63 -> V_96 ) ;
F_517 ( F_98 ( V_2 ) , V_34 ) ;
do {
V_307 = V_794 -> V_802 ( V_2 , V_351 ) ;
if ( V_307 != - V_89 )
break;
F_21 ( V_14 , V_307 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_307 ;
}
static int F_523 ( struct V_2 * V_3 , const struct V_493 * V_241 , struct V_803 * V_486 , bool V_804 )
{
int V_307 ;
struct V_805 args = {
. V_505 = F_98 ( V_3 ) ,
. V_241 = V_241 ,
} ;
struct V_806 V_56 = {
. V_486 = V_486 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_807 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
struct V_54 * V_55 = F_90 ( V_3 ) -> V_90 ;
struct V_317 * V_351 = NULL ;
if ( V_804 ) {
V_55 = F_90 ( V_3 ) -> V_62 -> V_100 ;
V_351 = F_524 ( F_90 ( V_3 ) -> V_62 ) ;
V_161 . V_317 = V_351 ;
}
F_8 ( L_59 , V_241 -> V_241 ) ;
F_261 ( F_90 ( V_3 ) -> V_62 ,
V_808 , & V_55 , & V_161 ) ;
V_307 = F_76 ( V_55 , F_90 ( V_3 ) , & V_161 , & args . V_158 ,
& V_56 . V_159 , 0 ) ;
F_8 ( L_60 , V_307 ) ;
if ( V_351 )
F_216 ( V_351 ) ;
return V_307 ;
}
int F_525 ( struct V_2 * V_3 , const struct V_493 * V_241 ,
struct V_803 * V_486 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_33 ( F_90 ( V_3 ) -> V_62 ) )
V_8 = F_523 ( V_3 , V_241 , V_486 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_523 ( V_3 , V_241 , V_486 , false ) ;
F_526 ( V_3 , V_241 , V_8 ) ;
V_8 = F_21 ( F_90 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_527 ( T_1 V_213 )
{
if ( V_213 & ~ V_809 )
goto V_810;
if ( ( V_213 & V_811 ) &&
( V_213 & V_812 ) )
goto V_810;
if ( ! ( V_213 & ( V_813 ) ) )
goto V_810;
return V_364 ;
V_810:
return - V_814 ;
}
static bool
F_528 ( struct V_815 * V_816 ,
struct V_815 * V_817 )
{
if ( V_816 -> V_818 == V_817 -> V_818 &&
memcmp ( V_816 -> V_819 , V_817 -> V_819 , V_816 -> V_818 ) == 0 )
return true ;
return false ;
}
int F_529 ( struct V_62 * V_63 , struct V_317 * V_351 )
{
int V_307 ;
struct V_820 args = {
. V_90 = V_63 ,
. V_3 = V_821 ,
} ;
struct V_822 V_56 ;
struct V_160 V_161 = {
. V_312 =
& V_313 [ V_823 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
F_8 ( L_11 , V_34 ) ;
F_530 ( & args . V_824 , & V_63 -> V_86 -> V_825 ) ;
if ( ! ( V_63 -> V_86 -> V_213 & V_826 ) )
args . V_3 = V_827 ;
V_307 = F_394 ( V_63 -> V_100 , & V_161 , V_612 ) ;
F_531 ( V_63 , V_307 ) ;
if ( V_307 == 0 ) {
if ( memcmp ( V_56 . V_824 . V_156 ,
V_63 -> V_86 -> V_825 . V_156 , V_828 ) ) {
F_8 ( L_61 , V_34 ) ;
V_307 = - V_35 ;
goto V_129;
}
if ( ( V_56 . V_3 & args . V_3 ) != V_56 . V_3 || V_56 . V_3 == 0 ) {
F_8 ( L_62 ,
V_34 ) ;
V_307 = - V_35 ;
goto V_129;
}
if ( V_56 . V_829 != args . V_829 ) {
F_8 ( L_63 ,
V_34 ) ;
V_307 = - V_35 ;
goto V_129;
}
}
V_129:
F_8 ( L_64 , V_34 , V_307 ) ;
return V_307 ;
}
static int F_532 ( struct V_62 * V_63 ,
struct V_830 * V_212 )
{
static const T_1 V_831 [ V_832 ] = {
[ 1 ] = 1 << ( V_833 - 32 ) |
1 << ( V_834 - 32 ) |
1 << ( V_835 - 32 ) |
1 << ( V_836 - 32 ) |
1 << ( V_837 - 32 )
} ;
unsigned int V_483 ;
if ( V_212 -> V_838 == V_839 ) {
F_533 ( V_840 , L_65 ) ;
for ( V_483 = 0 ; V_483 <= V_841 ; V_483 ++ ) {
if ( F_32 ( V_483 , V_212 -> V_842 . V_249 . V_843 ) )
F_533 ( V_840 , L_66 , V_483 ) ;
if ( F_32 ( V_483 , V_212 -> V_844 . V_249 . V_843 ) )
F_533 ( V_840 , L_67 , V_483 ) ;
}
for ( V_483 = 0 ; V_483 < V_832 ; V_483 ++ ) {
if ( V_212 -> V_842 . V_249 . V_845 [ V_483 ] & ~ V_831 [ V_483 ] ) {
F_533 ( V_840 , L_68 ) ;
return - V_27 ;
}
}
if ( F_32 ( V_833 , V_212 -> V_842 . V_249 . V_843 ) &&
F_32 ( V_835 , V_212 -> V_842 . V_249 . V_843 ) &&
F_32 ( V_836 , V_212 -> V_842 . V_249 . V_843 ) &&
F_32 ( V_837 , V_212 -> V_842 . V_249 . V_843 ) ) {
F_533 ( V_840 , L_69 ) ;
F_533 ( V_840 , L_70 ) ;
F_129 ( V_846 , & V_63 -> V_847 ) ;
} else {
F_533 ( V_840 , L_68 ) ;
return - V_27 ;
}
if ( F_32 ( V_848 , V_212 -> V_844 . V_249 . V_843 ) &&
F_32 ( V_849 , V_212 -> V_844 . V_249 . V_843 ) ) {
F_533 ( V_840 , L_71 ) ;
F_129 ( V_424 , & V_63 -> V_847 ) ;
}
if ( F_32 ( V_850 , V_212 -> V_844 . V_249 . V_843 ) &&
F_32 ( V_851 , V_212 -> V_844 . V_249 . V_843 ) ) {
F_533 ( V_840 , L_72 ) ;
F_129 ( V_808 , & V_63 -> V_847 ) ;
}
if ( F_32 ( V_852 , V_212 -> V_844 . V_249 . V_843 ) &&
F_32 ( V_853 , V_212 -> V_844 . V_249 . V_843 ) ) {
F_533 ( V_840 , L_73 ) ;
F_129 ( V_854 , & V_63 -> V_847 ) ;
}
if ( F_32 ( V_855 , V_212 -> V_844 . V_249 . V_843 ) ) {
F_533 ( V_840 , L_74 ) ;
F_129 ( V_856 , & V_63 -> V_847 ) ;
}
if ( F_32 ( V_857 , V_212 -> V_844 . V_249 . V_843 ) ) {
F_533 ( V_840 , L_75 ) ;
F_129 ( V_858 , & V_63 -> V_847 ) ;
}
}
return 0 ;
}
static int F_534 ( struct V_62 * V_63 , struct V_317 * V_351 ,
T_1 V_859 )
{
T_12 V_37 ;
struct V_860 args = {
. V_37 = & V_37 ,
. V_90 = V_63 ,
#ifdef F_535
. V_213 = V_861 |
V_862 |
V_863 ,
#else
. V_213 = V_861 |
V_862 ,
#endif
} ;
struct V_864 V_56 = {
0
} ;
int V_307 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_865 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
F_426 ( V_63 , & V_37 ) ;
V_307 = F_433 ( V_63 ) ;
if ( V_307 )
goto V_129;
F_8 ( L_76 ,
V_63 -> V_100 -> V_101 -> V_695 -> V_696 ,
V_63 -> V_666 ) ;
V_56 . V_866 = F_91 ( sizeof( struct V_867 ) ,
V_304 ) ;
if ( F_370 ( V_56 . V_866 == NULL ) ) {
V_307 = - V_124 ;
goto V_129;
}
V_56 . V_819 = F_91 ( sizeof( struct V_815 ) ,
V_304 ) ;
if ( F_370 ( V_56 . V_819 == NULL ) ) {
V_307 = - V_124 ;
goto V_868;
}
V_56 . V_869 = F_91 ( sizeof( struct V_870 ) , V_304 ) ;
if ( F_370 ( V_56 . V_869 == NULL ) ) {
V_307 = - V_124 ;
goto V_871;
}
switch ( V_859 ) {
case V_872 :
args . V_873 . V_838 = V_872 ;
break;
case V_839 :
args . V_873 = V_874 ;
break;
default:
F_115 ( 1 ) ;
V_307 = - V_27 ;
goto V_875;
}
V_307 = F_394 ( V_63 -> V_100 , & V_161 , V_612 ) ;
F_536 ( V_63 , V_307 ) ;
if ( V_307 == 0 )
V_307 = F_527 ( V_56 . V_213 ) ;
if ( V_307 == 0 )
V_307 = F_532 ( V_63 , & V_56 . V_873 ) ;
if ( V_307 == 0 ) {
V_63 -> V_236 = V_56 . V_235 ;
V_63 -> V_876 = V_56 . V_213 ;
if ( ! ( V_56 . V_213 & V_877 ) ) {
F_131 ( V_878 ,
& V_63 -> V_86 -> V_879 ) ;
V_63 -> V_880 = V_56 . V_203 ;
}
F_101 ( V_63 -> V_881 ) ;
V_63 -> V_881 = V_56 . V_866 ;
V_56 . V_866 = NULL ;
F_101 ( V_63 -> V_882 ) ;
V_63 -> V_882 = V_56 . V_869 ;
V_56 . V_869 = NULL ;
if ( V_63 -> V_883 != NULL &&
! F_528 ( V_63 -> V_883 ,
V_56 . V_819 ) ) {
F_8 ( L_77 ,
V_34 ) ;
F_129 ( V_884 , & V_63 -> V_653 ) ;
F_101 ( V_63 -> V_883 ) ;
V_63 -> V_883 = NULL ;
}
if ( V_63 -> V_883 == NULL ) {
V_63 -> V_883 = V_56 . V_819 ;
V_56 . V_819 = NULL ;
}
}
V_875:
F_101 ( V_56 . V_869 ) ;
V_871:
F_101 ( V_56 . V_819 ) ;
V_868:
F_101 ( V_56 . V_866 ) ;
V_129:
if ( V_63 -> V_882 != NULL )
F_8 ( L_78
L_79 ,
V_63 -> V_882 -> V_885 , V_63 -> V_882 -> V_241 ,
V_63 -> V_882 -> V_886 . V_887 ,
V_63 -> V_882 -> V_886 . V_888 ) ;
F_8 ( L_80 , V_307 ) ;
return V_307 ;
}
int F_537 ( struct V_62 * V_63 , struct V_317 * V_351 )
{
T_4 V_889 = V_63 -> V_100 -> V_101 -> V_102 ;
int V_307 ;
if ( V_889 == V_103 ||
V_889 == V_104 ) {
V_307 = F_534 ( V_63 , V_351 , V_839 ) ;
if ( ! V_307 )
return 0 ;
}
return F_534 ( V_63 , V_351 , V_872 ) ;
}
static int F_538 ( struct V_62 * V_63 ,
struct V_317 * V_351 )
{
struct V_160 V_161 = {
. V_312 = & V_313 [ V_890 ] ,
. V_315 = V_63 ,
. V_317 = V_351 ,
} ;
int V_307 ;
V_307 = F_394 ( V_63 -> V_100 , & V_161 , V_612 ) ;
F_539 ( V_63 , V_307 ) ;
if ( V_307 )
F_8 ( L_81
L_82 , V_307 , V_63 -> V_96 ) ;
return V_307 ;
}
static int F_540 ( struct V_62 * V_63 ,
struct V_317 * V_351 )
{
unsigned int V_891 ;
int V_51 ;
for ( V_891 = V_892 ; V_891 != 0 ; V_891 -- ) {
V_51 = F_538 ( V_63 , V_351 ) ;
switch ( V_51 ) {
case - V_89 :
case - V_893 :
F_177 ( 1 ) ;
break;
default:
return V_51 ;
}
}
return 0 ;
}
int F_541 ( struct V_62 * V_63 )
{
struct V_317 * V_351 ;
int V_51 = 0 ;
if ( V_63 -> V_166 -> V_333 < 1 )
goto V_129;
if ( V_63 -> V_876 == 0 )
goto V_129;
if ( V_63 -> V_894 )
goto V_129;
V_351 = F_524 ( V_63 ) ;
V_51 = F_540 ( V_63 , V_351 ) ;
if ( V_351 )
F_216 ( V_351 ) ;
switch ( V_51 ) {
case 0 :
case - V_75 :
V_63 -> V_876 = 0 ;
}
V_129:
return V_51 ;
}
static void F_542 ( struct V_117 * V_118 ,
void * V_154 )
{
struct V_895 * V_156 =
(struct V_895 * ) V_154 ;
F_8 ( L_11 , V_34 ) ;
F_64 ( V_156 -> V_63 -> V_86 ,
& V_156 -> args -> V_896 ,
& V_156 -> V_56 -> V_897 ,
V_118 ) ;
F_8 ( L_83 , V_34 ) ;
}
static void F_543 ( struct V_117 * V_118 , void * V_154 )
{
struct V_895 * V_156 =
(struct V_895 * ) V_154 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_55 ( V_118 , & V_156 -> V_56 -> V_897 ) )
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
int F_544 ( struct V_62 * V_63 , struct V_469 * V_570 )
{
struct V_117 * V_118 ;
struct V_898 args ;
struct V_899 V_56 = {
. V_900 = V_570 ,
} ;
struct V_895 V_156 = {
. args = & args ,
. V_56 = & V_56 ,
. V_63 = V_63 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_901 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
struct V_162 V_163 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_902 ,
. V_168 = & V_156 ,
. V_213 = V_612 ,
} ;
int V_307 ;
F_40 ( & args . V_896 , & V_56 . V_897 , 0 ) ;
F_41 ( & args . V_896 ) ;
F_8 ( L_11 , V_34 ) ;
V_118 = F_73 ( & V_163 ) ;
if ( F_45 ( V_118 ) )
V_307 = F_74 ( V_118 ) ;
else {
V_307 = V_118 -> V_147 ;
F_75 ( V_118 ) ;
}
F_8 ( L_85 , V_34 , V_307 ) ;
return V_307 ;
}
static void F_545 ( struct V_903 * args )
{
unsigned int V_904 , V_905 ;
V_904 = V_906 + V_907 ;
V_905 = V_906 + V_908 ;
args -> V_909 . V_904 = V_904 ;
args -> V_909 . V_905 = V_905 ;
args -> V_909 . V_910 = V_911 ;
args -> V_909 . V_912 = V_913 ;
F_8 ( L_86
L_87 ,
V_34 ,
args -> V_909 . V_904 , args -> V_909 . V_905 ,
args -> V_909 . V_910 , args -> V_909 . V_912 ) ;
args -> V_914 . V_904 = V_619 ;
args -> V_914 . V_905 = V_619 ;
args -> V_914 . V_915 = 0 ;
args -> V_914 . V_910 = V_916 ;
args -> V_914 . V_912 = 1 ;
F_8 ( L_88
L_89 ,
V_34 ,
args -> V_914 . V_904 , args -> V_914 . V_905 ,
args -> V_914 . V_915 , args -> V_914 . V_910 ,
args -> V_914 . V_912 ) ;
}
static int F_546 ( struct V_903 * args ,
struct V_917 * V_56 )
{
struct V_918 * V_919 = & args -> V_909 ;
struct V_918 * V_920 = & V_56 -> V_909 ;
if ( V_920 -> V_905 > V_919 -> V_905 )
return - V_27 ;
if ( V_920 -> V_910 < V_919 -> V_910 )
return - V_27 ;
if ( V_920 -> V_912 == 0 )
return - V_27 ;
if ( V_920 -> V_912 > V_921 )
V_920 -> V_912 = V_921 ;
return 0 ;
}
static int F_547 ( struct V_903 * args ,
struct V_917 * V_56 )
{
struct V_918 * V_919 = & args -> V_914 ;
struct V_918 * V_920 = & V_56 -> V_914 ;
if ( ! ( V_56 -> V_213 & V_826 ) )
goto V_129;
if ( V_920 -> V_904 > V_919 -> V_904 )
return - V_27 ;
if ( V_920 -> V_905 < V_919 -> V_905 )
return - V_27 ;
if ( V_920 -> V_915 > V_919 -> V_915 )
return - V_27 ;
if ( V_920 -> V_910 != V_919 -> V_910 )
return - V_27 ;
if ( V_920 -> V_912 != V_919 -> V_912 )
return - V_27 ;
V_129:
return 0 ;
}
static int F_548 ( struct V_903 * args ,
struct V_917 * V_56 )
{
int V_51 ;
V_51 = F_546 ( args , V_56 ) ;
if ( V_51 )
return V_51 ;
return F_547 ( args , V_56 ) ;
}
static void F_549 ( struct V_131 * V_132 ,
struct V_917 * V_56 )
{
F_530 ( & V_132 -> V_825 , & V_56 -> V_824 ) ;
V_132 -> V_63 -> V_876 |= V_877 ;
F_129 ( V_878 , & V_132 -> V_879 ) ;
V_132 -> V_213 = V_56 -> V_213 ;
memcpy ( & V_132 -> V_909 , & V_56 -> V_909 , sizeof( V_132 -> V_909 ) ) ;
if ( V_56 -> V_213 & V_826 )
memcpy ( & V_132 -> V_914 , & V_56 -> V_914 ,
sizeof( V_132 -> V_914 ) ) ;
}
static int F_550 ( struct V_62 * V_63 ,
struct V_317 * V_351 )
{
struct V_131 * V_132 = V_63 -> V_86 ;
struct V_903 args = {
. V_90 = V_63 ,
. V_235 = V_63 -> V_236 ,
. V_203 = V_63 -> V_880 ,
. V_922 = V_923 ,
} ;
struct V_917 V_56 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_924 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
int V_307 ;
F_545 ( & args ) ;
args . V_213 = ( V_925 | V_826 ) ;
V_307 = F_394 ( V_132 -> V_63 -> V_100 , & V_161 , V_612 ) ;
F_551 ( V_63 , V_307 ) ;
if ( ! V_307 ) {
V_307 = F_548 ( & args , & V_56 ) ;
if ( V_63 -> V_880 == V_56 . V_203 )
V_63 -> V_880 ++ ;
if ( V_307 )
goto V_129;
F_549 ( V_132 , & V_56 ) ;
}
V_129:
return V_307 ;
}
int F_552 ( struct V_62 * V_63 , struct V_317 * V_351 )
{
int V_307 ;
unsigned * V_926 ;
struct V_131 * V_132 = V_63 -> V_86 ;
F_8 ( L_90 , V_34 , V_63 , V_132 ) ;
V_307 = F_550 ( V_63 , V_351 ) ;
if ( V_307 )
goto V_129;
V_307 = F_553 ( V_132 ) ;
F_8 ( L_91 , V_307 ) ;
if ( V_307 )
goto V_129;
V_926 = ( unsigned * ) & V_132 -> V_825 . V_156 [ 0 ] ;
F_8 ( L_92 , V_34 ,
V_63 -> V_880 , V_926 [ 0 ] , V_926 [ 1 ] , V_926 [ 2 ] , V_926 [ 3 ] ) ;
V_129:
F_8 ( L_83 , V_34 ) ;
return V_307 ;
}
int F_554 ( struct V_131 * V_132 ,
struct V_317 * V_351 )
{
struct V_160 V_161 = {
. V_312 = & V_313 [ V_927 ] ,
. V_315 = V_132 ,
. V_317 = V_351 ,
} ;
int V_307 = 0 ;
F_8 ( L_93 ) ;
if ( ! F_122 ( V_878 , & V_132 -> V_879 ) )
return 0 ;
V_307 = F_394 ( V_132 -> V_63 -> V_100 , & V_161 , V_612 ) ;
F_555 ( V_132 -> V_63 , V_307 ) ;
if ( V_307 )
F_8 ( L_94
L_95 , V_307 ) ;
F_8 ( L_96 ) ;
return V_307 ;
}
static void F_556 ( void * V_156 )
{
struct V_928 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
if ( F_384 ( & V_63 -> V_606 ) > 1 )
F_385 ( V_63 ) ;
F_386 ( V_63 ) ;
F_101 ( V_154 ) ;
}
static int F_557 ( struct V_117 * V_118 , struct V_62 * V_63 )
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
static void F_558 ( struct V_117 * V_118 , void * V_156 )
{
struct V_928 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
if ( ! F_55 ( V_118 , V_118 -> V_327 . V_316 ) )
return;
F_559 ( V_63 , V_118 -> V_147 ) ;
if ( V_118 -> V_147 < 0 ) {
F_8 ( L_97 , V_34 , V_118 -> V_147 ) ;
if ( F_384 ( & V_63 -> V_606 ) == 1 )
goto V_129;
if ( F_557 ( V_118 , V_63 ) == - V_128 ) {
F_60 ( V_118 ) ;
return;
}
}
F_8 ( L_98 , V_34 , V_118 -> V_327 . V_317 ) ;
V_129:
F_8 ( L_83 , V_34 ) ;
}
static void F_560 ( struct V_117 * V_118 , void * V_156 )
{
struct V_928 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
struct V_108 * args ;
struct V_109 * V_56 ;
args = V_118 -> V_327 . V_315 ;
V_56 = V_118 -> V_327 . V_316 ;
F_64 ( V_63 -> V_86 , args , V_56 , V_118 ) ;
}
static struct V_117 * F_561 ( struct V_62 * V_63 ,
struct V_317 * V_351 ,
bool V_929 )
{
struct V_928 * V_154 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_930 ] ,
. V_317 = V_351 ,
} ;
struct V_162 V_318 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_931 ,
. V_213 = V_322 | V_612 ,
} ;
if ( ! F_391 ( & V_63 -> V_606 ) )
return F_46 ( - V_35 ) ;
V_154 = F_91 ( sizeof( * V_154 ) , V_304 ) ;
if ( V_154 == NULL ) {
F_386 ( V_63 ) ;
return F_46 ( - V_124 ) ;
}
F_40 ( & V_154 -> args , & V_154 -> V_56 , 0 ) ;
if ( V_929 )
F_41 ( & V_154 -> args ) ;
V_161 . V_315 = & V_154 -> args ;
V_161 . V_316 = & V_154 -> V_56 ;
V_154 -> V_63 = V_63 ;
V_318 . V_168 = V_154 ;
return F_73 ( & V_318 ) ;
}
static int F_562 ( struct V_62 * V_63 , struct V_317 * V_351 , unsigned V_610 )
{
struct V_117 * V_118 ;
int V_51 = 0 ;
if ( ( V_610 & V_932 ) == 0 )
return - V_128 ;
V_118 = F_561 ( V_63 , V_351 , false ) ;
if ( F_45 ( V_118 ) )
V_51 = F_74 ( V_118 ) ;
else
F_478 ( V_118 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_563 ( struct V_62 * V_63 , struct V_317 * V_351 )
{
struct V_117 * V_118 ;
int V_51 ;
V_118 = F_561 ( V_63 , V_351 , true ) ;
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
static void F_564 ( struct V_117 * V_118 , void * V_156 )
{
struct V_933 * V_154 = V_156 ;
F_64 ( V_154 -> V_63 -> V_86 ,
& V_154 -> V_395 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_565 ( struct V_117 * V_118 , struct V_62 * V_63 )
{
switch( V_118 -> V_147 ) {
case 0 :
case - V_934 :
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
static void F_566 ( struct V_117 * V_118 , void * V_156 )
{
struct V_933 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
struct V_109 * V_56 = & V_154 -> V_56 . V_159 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_55 ( V_118 , V_56 ) )
return;
F_567 ( V_63 , V_118 -> V_147 ) ;
if ( F_565 ( V_118 , V_63 ) == - V_128 ) {
F_60 ( V_118 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_568 ( void * V_156 )
{
struct V_933 * V_154 = V_156 ;
F_101 ( V_154 ) ;
}
static int F_569 ( struct V_62 * V_63 ,
struct V_317 * V_351 )
{
struct V_933 * V_154 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_935 ] ,
. V_317 = V_351 ,
} ;
struct V_162 V_318 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_936 ,
. V_213 = V_322 ,
} ;
int V_307 = - V_124 ;
F_8 ( L_11 , V_34 ) ;
V_154 = F_91 ( sizeof( * V_154 ) , V_304 ) ;
if ( V_154 == NULL )
goto V_129;
V_154 -> V_63 = V_63 ;
V_154 -> V_395 . V_937 = 0 ;
F_40 ( & V_154 -> V_395 . V_158 , & V_154 -> V_56 . V_159 , 0 ) ;
F_41 ( & V_154 -> V_395 . V_158 ) ;
V_161 . V_315 = & V_154 -> V_395 ;
V_161 . V_316 = & V_154 -> V_56 ;
V_318 . V_168 = V_154 ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) ) {
V_307 = F_74 ( V_118 ) ;
goto V_129;
}
V_307 = F_112 ( V_118 ) ;
if ( V_307 == 0 )
V_307 = V_118 -> V_147 ;
F_75 ( V_118 ) ;
return 0 ;
V_129:
F_8 ( L_16 , V_34 , V_307 ) ;
return V_307 ;
}
static void
F_570 ( struct V_117 * V_118 , void * V_154 )
{
struct V_938 * V_939 = V_154 ;
struct V_13 * V_14 = F_90 ( V_939 -> args . V_2 ) ;
struct V_131 * V_132 = F_67 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
if ( F_64 ( V_132 , & V_939 -> args . V_158 ,
& V_939 -> V_56 . V_159 , V_118 ) )
return;
if ( F_571 ( & V_939 -> args . V_251 ,
F_78 ( V_939 -> args . V_2 ) -> V_940 ,
& V_939 -> args . V_941 ,
V_939 -> args . V_302 -> V_65 ) ) {
F_572 ( V_118 , V_791 ) ;
}
}
static void F_573 ( struct V_117 * V_118 , void * V_154 )
{
struct V_938 * V_939 = V_154 ;
struct V_2 * V_2 = V_939 -> args . V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
struct V_942 * V_943 ;
struct V_64 * V_65 = NULL ;
unsigned long V_944 , V_574 , V_945 ;
F_8 ( L_99 , V_34 , - V_118 -> V_147 ) ;
if ( ! F_55 ( V_118 , & V_939 -> V_56 . V_159 ) )
goto V_129;
switch ( V_118 -> V_147 ) {
case 0 :
goto V_129;
case - V_946 :
goto V_947;
case - V_19 :
if ( V_939 -> args . V_948 == 0 )
goto V_947;
case - V_20 :
V_944 = F_574 ( V_118 -> V_949 ) ;
V_945 = V_939 -> args . V_105 + V_944 ;
V_574 = V_152 ;
if ( F_575 ( V_945 , V_574 ) ) {
unsigned long V_950 ;
V_950 = F_576 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_100 ,
V_34 , V_950 ) ;
F_62 ( V_118 , V_950 ) ;
goto V_951;
}
break;
case - V_73 :
case - V_70 :
F_35 ( & V_2 -> V_173 ) ;
if ( F_142 ( & V_939 -> args . V_251 ,
& V_939 -> args . V_302 -> V_65 -> V_251 ) ) {
F_37 ( & V_2 -> V_173 ) ;
V_65 = V_939 -> args . V_302 -> V_65 ;
break;
}
V_943 = F_78 ( V_2 ) -> V_940 ;
if ( V_943 && F_142 ( & V_939 -> args . V_251 ,
& V_943 -> V_952 ) ) {
F_577 ( V_953 ) ;
F_129 ( V_954 , & V_943 -> V_955 ) ;
F_578 ( V_943 , & V_953 , NULL ) ;
F_37 ( & V_2 -> V_173 ) ;
F_579 ( & V_953 ) ;
} else
F_37 ( & V_2 -> V_173 ) ;
goto V_951;
}
if ( F_255 ( V_118 , V_14 , V_65 , NULL ) == - V_128 )
goto V_951;
V_129:
F_8 ( L_83 , V_34 ) ;
return;
V_951:
V_118 -> V_147 = 0 ;
F_60 ( V_118 ) ;
return;
V_947:
V_118 -> V_147 = - V_956 ;
goto V_129;
}
static T_9 F_580 ( struct V_13 * V_14 )
{
T_1 V_905 = V_14 -> V_62 -> V_86 -> V_909 . V_905 ;
return F_581 ( 0 , V_905 ) ;
}
static void F_582 ( struct V_494 * * V_42 , T_9 V_957 )
{
int V_483 ;
if ( ! V_42 )
return;
for ( V_483 = 0 ; V_483 < V_957 ; V_483 ++ ) {
if ( ! V_42 [ V_483 ] )
break;
F_287 ( V_42 [ V_483 ] ) ;
}
F_101 ( V_42 ) ;
}
static struct V_494 * * F_583 ( T_9 V_957 , T_6 V_958 )
{
struct V_494 * * V_42 ;
int V_483 ;
V_42 = F_584 ( V_957 , sizeof( struct V_494 * ) , V_958 ) ;
if ( ! V_42 ) {
F_8 ( L_101 , V_34 , V_957 ) ;
return NULL ;
}
for ( V_483 = 0 ; V_483 < V_957 ; V_483 ++ ) {
V_42 [ V_483 ] = F_283 ( V_958 ) ;
if ( ! V_42 [ V_483 ] ) {
F_8 ( L_102 , V_34 ) ;
F_582 ( V_42 , V_957 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_585 ( void * V_154 )
{
struct V_938 * V_939 = V_154 ;
struct V_2 * V_2 = V_939 -> args . V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
T_9 V_959 = F_580 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_582 ( V_939 -> args . V_940 . V_42 , V_959 ) ;
F_586 ( F_78 ( V_2 ) -> V_940 ) ;
F_174 ( V_939 -> args . V_302 ) ;
F_101 ( V_154 ) ;
F_8 ( L_83 , V_34 ) ;
}
struct V_960 *
F_587 ( struct V_938 * V_939 , T_6 V_958 )
{
struct V_2 * V_2 = V_939 -> args . V_2 ;
struct V_13 * V_14 = F_90 ( V_2 ) ;
T_9 V_959 = F_580 ( V_14 ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_961 ] ,
. V_315 = & V_939 -> args ,
. V_316 = & V_939 -> V_56 ,
. V_317 = V_939 -> V_351 ,
} ;
struct V_162 V_318 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_962 ,
. V_168 = V_939 ,
. V_213 = V_322 ,
} ;
struct V_960 * V_963 = NULL ;
int V_307 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_588 ( F_78 ( V_2 ) -> V_940 ) ;
V_939 -> args . V_940 . V_42 = F_583 ( V_959 , V_958 ) ;
if ( ! V_939 -> args . V_940 . V_42 ) {
F_585 ( V_939 ) ;
return F_46 ( - V_124 ) ;
}
V_939 -> args . V_940 . V_521 = V_959 * V_619 ;
V_939 -> args . V_105 = V_152 ;
V_939 -> V_56 . V_964 = & V_939 -> args . V_940 ;
V_939 -> V_56 . V_159 . V_114 = NULL ;
F_40 ( & V_939 -> args . V_158 , & V_939 -> V_56 . V_159 , 0 ) ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) )
return F_263 ( V_118 ) ;
V_307 = F_112 ( V_118 ) ;
if ( V_307 == 0 )
V_307 = V_118 -> V_147 ;
F_589 ( V_939 -> args . V_302 ,
& V_939 -> args . V_941 ,
& V_939 -> V_56 . V_941 ,
V_307 ) ;
if ( V_307 == 0 && V_939 -> V_56 . V_964 -> V_12 )
V_963 = F_590 ( V_939 ) ;
F_75 ( V_118 ) ;
F_8 ( L_16 , V_34 , V_307 ) ;
if ( V_307 )
return F_46 ( V_307 ) ;
return V_963 ;
}
static void
F_591 ( struct V_117 * V_118 , void * V_154 )
{
struct V_965 * V_966 = V_154 ;
F_8 ( L_11 , V_34 ) ;
F_64 ( V_966 -> V_63 -> V_86 ,
& V_966 -> args . V_158 ,
& V_966 -> V_56 . V_159 ,
V_118 ) ;
}
static void F_592 ( struct V_117 * V_118 , void * V_154 )
{
struct V_965 * V_966 = V_154 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_55 ( V_118 , & V_966 -> V_56 . V_159 ) )
return;
V_14 = F_90 ( V_966 -> args . V_2 ) ;
switch ( V_118 -> V_147 ) {
default:
V_118 -> V_147 = 0 ;
case 0 :
break;
case - V_89 :
if ( F_255 ( V_118 , V_14 , NULL , NULL ) != - V_128 )
break;
F_60 ( V_118 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_593 ( void * V_154 )
{
struct V_965 * V_966 = V_154 ;
struct V_942 * V_943 = V_966 -> args . V_940 ;
F_577 ( V_967 ) ;
F_8 ( L_11 , V_34 ) ;
F_35 ( & V_943 -> V_968 -> V_173 ) ;
if ( V_966 -> V_56 . V_969 )
F_594 ( V_943 , & V_966 -> V_56 . V_251 , true ) ;
F_578 ( V_943 , & V_967 , & V_966 -> args . V_941 ) ;
F_595 ( V_943 ) ;
V_943 -> V_970 -- ;
F_37 ( & V_943 -> V_968 -> V_173 ) ;
F_579 ( & V_967 ) ;
F_586 ( V_966 -> args . V_940 ) ;
F_444 ( V_966 -> V_2 ) ;
F_101 ( V_154 ) ;
F_8 ( L_83 , V_34 ) ;
}
int F_596 ( struct V_965 * V_966 , bool V_971 )
{
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_972 ] ,
. V_315 = & V_966 -> args ,
. V_316 = & V_966 -> V_56 ,
. V_317 = V_966 -> V_351 ,
} ;
struct V_162 V_318 = {
. V_164 = F_90 ( V_966 -> args . V_2 ) -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_973 ,
. V_168 = V_966 ,
} ;
int V_307 = 0 ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_971 ) {
V_966 -> V_2 = F_447 ( V_966 -> args . V_2 ) ;
if ( ! V_966 -> V_2 ) {
F_593 ( V_966 ) ;
return - V_128 ;
}
V_318 . V_213 |= V_322 ;
}
F_40 ( & V_966 -> args . V_158 , & V_966 -> V_56 . V_159 , 1 ) ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
if ( V_971 )
V_307 = V_118 -> V_147 ;
F_597 ( V_966 -> args . V_2 , V_307 ) ;
F_8 ( L_16 , V_34 , V_307 ) ;
F_75 ( V_118 ) ;
return V_307 ;
}
static int
F_598 ( struct V_13 * V_14 ,
struct V_974 * V_975 ,
struct V_317 * V_351 )
{
struct V_976 args = {
. V_975 = V_975 ,
. V_977 = V_978 |
V_979 ,
} ;
struct V_980 V_56 = {
. V_975 = V_975 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_981 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
int V_307 ;
F_8 ( L_11 , V_34 ) ;
V_307 = F_76 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_56 . V_982 & ~ args . V_977 )
F_8 ( L_103 , V_34 ) ;
if ( V_56 . V_982 != args . V_977 )
V_975 -> V_983 = 1 ;
F_8 ( L_16 , V_34 , V_307 ) ;
return V_307 ;
}
int F_599 ( struct V_13 * V_14 ,
struct V_974 * V_975 ,
struct V_317 * V_351 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_598 ( V_14 , V_975 , V_351 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_600 ( struct V_117 * V_118 , void * V_154 )
{
struct V_984 * V_156 = V_154 ;
struct V_13 * V_14 = F_90 ( V_156 -> args . V_2 ) ;
struct V_131 * V_132 = F_67 ( V_14 ) ;
F_64 ( V_132 ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static void
F_601 ( struct V_117 * V_118 , void * V_154 )
{
struct V_984 * V_156 = V_154 ;
struct V_13 * V_14 = F_90 ( V_156 -> args . V_2 ) ;
if ( ! F_55 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
switch ( V_118 -> V_147 ) {
case - V_68 :
case - V_985 :
case - V_946 :
case - V_88 :
V_118 -> V_147 = 0 ;
case 0 :
break;
default:
if ( F_255 ( V_118 , V_14 , NULL , NULL ) == - V_128 ) {
F_60 ( V_118 ) ;
return;
}
}
}
static void F_602 ( void * V_154 )
{
struct V_984 * V_156 = V_154 ;
F_603 ( V_156 ) ;
F_448 ( V_156 -> args . V_2 ,
V_156 -> V_56 . V_392 ) ;
F_216 ( V_156 -> V_351 ) ;
F_444 ( V_156 -> V_2 ) ;
F_101 ( V_156 ) ;
}
int
F_604 ( struct V_984 * V_156 , bool V_971 )
{
struct V_160 V_161 = {
. V_312 = & V_313 [ V_986 ] ,
. V_315 = & V_156 -> args ,
. V_316 = & V_156 -> V_56 ,
. V_317 = V_156 -> V_351 ,
} ;
struct V_162 V_318 = {
. V_118 = & V_156 -> V_118 ,
. V_164 = F_302 ( V_156 -> args . V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_987 ,
. V_168 = V_156 ,
} ;
struct V_117 * V_118 ;
int V_307 = 0 ;
F_8 ( L_104
L_105 , V_971 ,
V_156 -> args . V_988 ,
V_156 -> args . V_2 -> V_989 ) ;
if ( ! V_971 ) {
V_156 -> V_2 = F_447 ( V_156 -> args . V_2 ) ;
if ( V_156 -> V_2 == NULL ) {
F_602 ( V_156 ) ;
return - V_128 ;
}
V_318 . V_213 = V_322 ;
}
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_118 = F_73 ( & V_318 ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
if ( V_971 )
V_307 = V_118 -> V_147 ;
F_605 ( V_156 -> args . V_2 , V_307 ) ;
F_8 ( L_106 , V_34 , V_307 ) ;
F_75 ( V_118 ) ;
return V_307 ;
}
static int
F_606 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_470 ,
struct V_803 * V_486 , bool V_804 )
{
struct V_990 args = {
. V_991 = V_992 ,
} ;
struct V_806 V_56 = {
. V_486 = V_486 ,
} ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_993 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
} ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_317 * V_351 = NULL ;
int V_307 ;
if ( V_804 ) {
V_55 = V_14 -> V_62 -> V_100 ;
V_351 = F_524 ( V_14 -> V_62 ) ;
V_161 . V_317 = V_351 ;
}
F_8 ( L_11 , V_34 ) ;
V_307 = F_76 ( V_55 , V_14 , & V_161 , & args . V_158 ,
& V_56 . V_159 , 0 ) ;
F_8 ( L_16 , V_34 , V_307 ) ;
if ( V_351 )
F_216 ( V_351 ) ;
return V_307 ;
}
static int
F_607 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_470 , struct V_803 * V_486 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_33 ( V_14 -> V_62 ) )
V_8 = F_606 ( V_14 , V_430 , V_470 ,
V_486 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_606 ( V_14 , V_430 , V_470 ,
V_486 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_994 :
goto V_129;
default:
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static int
F_608 ( struct V_13 * V_14 , struct V_429 * V_430 ,
struct V_469 * V_470 )
{
int V_8 ;
struct V_494 * V_494 ;
T_4 V_99 = V_995 ;
struct V_803 * V_486 ;
struct V_996 * V_997 ;
int V_483 ;
V_494 = F_283 ( V_383 ) ;
if ( ! V_494 ) {
V_8 = - V_124 ;
goto V_129;
}
V_486 = F_398 ( V_494 ) ;
V_8 = F_607 ( V_14 , V_430 , V_470 , V_486 ) ;
if ( V_8 == - V_22 || V_8 == - V_994 ) {
V_8 = F_274 ( V_14 , V_430 , V_470 ) ;
goto V_998;
}
if ( V_8 )
goto V_998;
for ( V_483 = 0 ; V_483 < V_486 -> V_999 ; V_483 ++ ) {
V_997 = & V_486 -> V_486 [ V_483 ] ;
switch ( V_997 -> V_99 ) {
case V_482 :
case V_481 :
case V_1000 :
V_99 = F_609 ( V_997 -> V_99 ,
& V_997 -> V_1001 ) ;
break;
default:
V_99 = V_995 ;
break;
}
if ( ! F_610 ( & V_14 -> V_484 , V_99 ) )
V_99 = V_995 ;
if ( V_99 != V_995 ) {
V_8 = F_272 ( V_14 , V_430 ,
V_470 , V_99 ) ;
if ( ! V_8 )
break;
}
}
if ( V_99 == V_995 )
V_8 = - V_24 ;
V_998:
F_412 ( V_494 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_129:
return V_8 ;
}
static int F_611 ( struct V_13 * V_14 ,
T_8 * V_251 ,
struct V_317 * V_351 )
{
int V_307 ;
struct V_1002 args = {
. V_251 = V_251 ,
} ;
struct V_1003 V_56 ;
struct V_160 V_161 = {
. V_312 = & V_313 [ V_1004 ] ,
. V_315 = & args ,
. V_316 = & V_56 ,
. V_317 = V_351 ,
} ;
struct V_54 * V_164 = V_14 -> V_90 ;
F_261 ( V_14 -> V_62 , V_854 ,
& V_164 , & V_161 ) ;
F_8 ( L_107 , V_251 ) ;
F_40 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_41 ( & args . V_158 ) ;
V_307 = F_72 ( V_164 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_307 != V_364 ) {
F_8 ( L_108 , V_307 ) ;
return V_307 ;
}
F_8 ( L_109 , - V_56 . V_307 ) ;
return - V_56 . V_307 ;
}
static int F_213 ( struct V_13 * V_14 ,
T_8 * V_251 ,
struct V_317 * V_351 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_611 ( V_14 , V_251 , V_351 ) ;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_612 ( struct V_117 * V_118 , void * V_154 )
{
struct V_1005 * V_156 = V_154 ;
F_64 ( F_67 ( V_156 -> V_14 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static void F_613 ( struct V_117 * V_118 , void * V_154 )
{
struct V_1005 * V_156 = V_154 ;
F_55 ( V_118 , & V_156 -> V_56 . V_159 ) ;
switch ( V_118 -> V_147 ) {
case - V_89 :
if ( F_255 ( V_118 , V_156 -> V_14 , NULL , NULL ) == - V_128 )
F_60 ( V_118 ) ;
}
}
static void F_614 ( void * V_154 )
{
F_101 ( V_154 ) ;
}
static struct V_117 * F_615 ( struct V_13 * V_14 ,
T_8 * V_251 ,
struct V_317 * V_351 ,
bool V_1006 )
{
struct V_160 V_161 = {
. V_312 = & V_313 [ V_1007 ] ,
. V_317 = V_351 ,
} ;
struct V_162 V_163 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_1008 ,
. V_213 = V_322 ,
} ;
struct V_1005 * V_156 ;
F_261 ( V_14 -> V_62 , V_854 ,
& V_163 . V_164 , & V_161 ) ;
F_8 ( L_110 , V_251 ) ;
V_156 = F_284 ( sizeof( * V_156 ) , V_304 ) ;
if ( ! V_156 )
return F_46 ( - V_124 ) ;
V_156 -> V_14 = V_14 ;
F_132 ( & V_156 -> args . V_251 , V_251 ) ;
V_163 . V_168 = V_156 ;
V_161 . V_315 = & V_156 -> args ;
V_161 . V_316 = & V_156 -> V_56 ;
F_40 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 0 ) ;
if ( V_1006 )
F_41 ( & V_156 -> args . V_158 ) ;
return F_73 ( & V_163 ) ;
}
static int F_215 ( struct V_13 * V_14 ,
T_8 * V_251 ,
struct V_317 * V_351 )
{
struct V_117 * V_118 ;
int V_51 ;
V_118 = F_615 ( V_14 , V_251 , V_351 , true ) ;
if ( F_45 ( V_118 ) )
return F_74 ( V_118 ) ;
V_51 = F_113 ( V_118 ) ;
if ( ! V_51 )
V_51 = V_118 -> V_147 ;
F_75 ( V_118 ) ;
return V_51 ;
}
static void
F_616 ( struct V_13 * V_14 , struct V_283 * V_284 )
{
struct V_117 * V_118 ;
struct V_317 * V_351 = V_284 -> V_285 -> V_226 -> V_292 ;
V_118 = F_615 ( V_14 , & V_284 -> V_287 , V_351 , false ) ;
F_501 ( V_14 , V_284 ) ;
if ( F_45 ( V_118 ) )
return;
F_75 ( V_118 ) ;
}
static bool F_617 ( const T_8 * V_1009 ,
const T_8 * V_1010 )
{
if ( memcmp ( V_1009 -> V_1011 , V_1010 -> V_1011 , sizeof( V_1009 -> V_1011 ) ) != 0 )
return false ;
if ( V_1009 -> V_203 == V_1010 -> V_203 )
return true ;
if ( V_1009 -> V_203 == 0 || V_1010 -> V_203 == 0 )
return true ;
return false ;
}
static bool F_618 ( const T_8 * V_1009 ,
const T_8 * V_1010 )
{
return F_142 ( V_1009 , V_1010 ) ;
}
static struct V_217 *
F_619 ( struct V_219 * V_1012 , T_6 V_1013 )
{
return NULL ;
}
