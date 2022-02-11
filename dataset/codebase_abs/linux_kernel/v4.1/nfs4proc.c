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
if ( V_2 && F_22 ( V_2 , V_68 ) ) {
F_23 ( V_2 ) ;
V_61 -> V_66 = 1 ;
return 0 ;
}
if ( V_65 == NULL )
break;
V_51 = F_24 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
goto V_69;
case - V_70 :
case - V_71 :
case - V_72 :
if ( V_65 == NULL )
break;
V_51 = F_24 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
goto V_69;
case - V_73 :
if ( V_65 != NULL ) {
V_51 = F_24 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
}
case - V_74 :
case - V_75 :
F_25 ( V_63 ) ;
goto V_69;
case - V_76 :
V_51 = F_26 ( V_14 ) ;
if ( V_51 < 0 )
break;
goto V_69;
case - V_77 :
F_27 ( V_63 ) ;
goto V_69;
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
goto V_69;
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
V_69:
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
F_34 ( V_14 -> V_62 , V_105 ) ;
}
static void F_39 ( struct V_108 * args ,
struct V_109 * V_56 , int V_110 )
{
args -> V_111 = NULL ;
args -> V_112 = V_110 ;
args -> V_113 = 0 ;
V_56 -> V_114 = NULL ;
}
static void F_40 ( struct V_108 * args )
{
args -> V_113 = 1 ;
}
int F_41 ( struct V_115 * V_116 ,
struct V_108 * args ,
struct V_109 * V_56 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 ;
if ( V_56 -> V_114 != NULL )
goto V_121;
F_35 ( & V_116 -> V_122 ) ;
if ( F_42 ( V_116 ) && ! args -> V_113 )
goto V_123;
V_120 = F_43 ( V_116 ) ;
if ( F_44 ( V_120 ) ) {
if ( V_120 == F_45 ( - V_124 ) )
V_118 -> V_125 = V_87 >> 2 ;
goto V_123;
}
F_37 ( & V_116 -> V_122 ) ;
args -> V_111 = V_120 ;
V_56 -> V_114 = V_120 ;
V_121:
F_46 ( V_118 ) ;
return 0 ;
V_123:
if ( args -> V_113 )
F_47 ( & V_116 -> V_126 , V_118 ,
NULL , V_127 ) ;
else
F_48 ( & V_116 -> V_126 , V_118 , NULL ) ;
F_37 ( & V_116 -> V_122 ) ;
return - V_128 ;
}
static int F_49 ( struct V_117 * V_118 ,
struct V_109 * V_56 )
{
struct V_119 * V_120 = V_56 -> V_114 ;
struct V_115 * V_116 ;
if ( V_120 == NULL )
goto V_129;
V_116 = V_120 -> V_130 ;
F_35 ( & V_116 -> V_122 ) ;
if ( ! F_50 ( V_116 , V_120 ) )
F_51 ( V_116 , V_120 ) ;
F_37 ( & V_116 -> V_122 ) ;
V_56 -> V_114 = NULL ;
V_129:
return 1 ;
}
static void F_52 ( struct V_109 * V_56 )
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
if ( F_50 ( V_116 , V_120 ) ) {
V_133 = false ;
goto V_136;
}
F_51 ( V_116 , V_120 ) ;
if ( V_116 -> V_134 != V_137 )
V_133 = false ;
V_136:
F_37 ( & V_116 -> V_122 ) ;
V_56 -> V_114 = NULL ;
if ( V_133 )
F_53 ( V_132 -> V_63 ) ;
}
int F_54 ( struct V_117 * V_118 , struct V_109 * V_56 )
{
struct V_131 * V_132 ;
struct V_119 * V_120 = V_56 -> V_114 ;
struct V_62 * V_63 ;
bool V_138 = false ;
int V_51 = 1 ;
if ( V_120 == NULL )
goto V_139;
if ( ! F_55 ( V_118 ) )
goto V_129;
V_132 = V_120 -> V_130 -> V_132 ;
if ( V_120 -> V_138 ) {
V_120 -> V_138 = 0 ;
V_138 = true ;
}
F_56 ( V_132 , V_56 ) ;
switch ( V_56 -> V_140 ) {
case 0 :
++ V_120 -> V_141 ;
V_63 = V_132 -> V_63 ;
F_34 ( V_63 , V_56 -> V_142 ) ;
if ( V_56 -> V_143 != 0 )
F_25 ( V_63 ) ;
F_57 ( V_120 -> V_130 , V_120 , V_56 ) ;
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
F_52 ( V_56 ) ;
V_139:
return V_51 ;
V_146:
if ( F_58 ( V_118 ) ) {
V_118 -> V_147 = 0 ;
V_51 = 0 ;
}
goto V_129;
V_145:
if ( ! F_59 ( V_118 ) )
goto V_129;
F_60 ( V_118 , V_52 ) ;
return 0 ;
}
int F_61 ( struct V_117 * V_118 , struct V_109 * V_56 )
{
if ( V_56 -> V_114 == NULL )
return 1 ;
if ( ! V_56 -> V_114 -> V_130 -> V_132 )
return F_49 ( V_118 , V_56 ) ;
return F_54 ( V_118 , V_56 ) ;
}
int F_62 ( struct V_131 * V_132 ,
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
V_120 = F_43 ( V_116 ) ;
if ( F_44 ( V_120 ) ) {
if ( V_120 == F_45 ( - V_124 ) )
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
F_63 ( V_132 , args ) ;
V_148:
F_46 ( V_118 ) ;
return 0 ;
V_123:
if ( args -> V_113 )
F_47 ( & V_116 -> V_126 , V_118 ,
NULL , V_127 ) ;
else
F_48 ( & V_116 -> V_126 , V_118 , NULL ) ;
F_37 ( & V_116 -> V_122 ) ;
return - V_128 ;
}
static int F_64 ( const struct V_13 * V_14 ,
struct V_108 * args ,
struct V_109 * V_56 ,
struct V_117 * V_118 )
{
struct V_131 * V_132 = F_65 ( V_14 ) ;
int V_51 = 0 ;
if ( ! V_132 )
return F_41 ( V_14 -> V_62 -> V_153 ,
args , V_56 , V_118 ) ;
F_8 ( L_15 ,
V_34 , V_132 -> V_63 , V_132 , V_56 -> V_114 ?
V_56 -> V_114 -> V_144 : V_137 ) ;
V_51 = F_62 ( V_132 , args , V_56 , V_118 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static void F_66 ( struct V_117 * V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
struct V_131 * V_132 = F_65 ( V_156 -> V_157 ) ;
F_8 ( L_17 , V_34 , V_156 -> V_157 ) ;
F_62 ( V_132 , V_156 -> V_158 , V_156 -> V_159 , V_118 ) ;
}
static void F_67 ( struct V_117 * V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
F_54 ( V_118 , V_156 -> V_159 ) ;
}
static int F_64 ( const struct V_13 * V_14 ,
struct V_108 * args ,
struct V_109 * V_56 ,
struct V_117 * V_118 )
{
return F_41 ( V_14 -> V_62 -> V_153 ,
args , V_56 , V_118 ) ;
}
int F_61 ( struct V_117 * V_118 ,
struct V_109 * V_56 )
{
return F_49 ( V_118 , V_56 ) ;
}
static void F_68 ( struct V_117 * V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
F_64 ( V_156 -> V_157 ,
V_156 -> V_158 , V_156 -> V_159 , V_118 ) ;
}
static void F_69 ( struct V_117 * V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
F_61 ( V_118 , V_156 -> V_159 ) ;
}
static int F_70 ( struct V_54 * V_55 ,
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
V_118 = F_71 ( & V_163 ) ;
if ( F_44 ( V_118 ) )
V_51 = F_72 ( V_118 ) ;
else {
V_51 = V_118 -> V_147 ;
F_73 ( V_118 ) ;
}
return V_51 ;
}
int F_74 ( struct V_54 * V_55 ,
struct V_13 * V_14 ,
struct V_160 * V_161 ,
struct V_108 * args ,
struct V_109 * V_56 ,
int V_110 )
{
F_39 ( args , V_56 , V_110 ) ;
return F_70 ( V_55 , V_14 , V_161 , args , V_56 ) ;
}
static void F_75 ( struct V_2 * V_3 , struct V_169 * V_170 )
{
struct V_171 * V_172 = F_76 ( V_3 ) ;
F_35 ( & V_3 -> V_173 ) ;
V_172 -> V_174 |= V_175 | V_176 ;
if ( ! V_170 -> V_177 || V_170 -> V_178 != V_3 -> V_179 )
F_77 ( V_3 ) ;
V_3 -> V_179 = V_170 -> V_180 ;
V_172 -> V_181 = F_78 () ;
F_79 ( V_3 ) ;
F_37 ( & V_3 -> V_173 ) ;
}
static bool F_80 ( struct V_13 * V_14 ,
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
F_81 ( struct V_13 * V_14 ,
T_5 V_183 , int V_184 )
{
T_1 V_56 = 0 ;
switch ( V_183 & ( V_68 | V_185 ) ) {
case V_68 :
V_56 = V_186 ;
break;
case V_185 :
V_56 = V_187 ;
break;
case V_68 | V_185 :
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
F_82 ( struct V_13 * V_14 ,
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
static void F_83 ( struct V_199 * V_41 )
{
V_41 -> V_200 . V_201 = & V_41 -> V_201 ;
V_41 -> V_200 . V_202 = V_41 -> V_202 ;
V_41 -> V_200 . V_203 = V_41 -> V_204 . V_203 ;
V_41 -> V_205 . V_203 = V_41 -> V_206 . V_203 ;
V_41 -> V_200 . V_14 = V_41 -> V_204 . V_14 ;
V_41 -> V_200 . V_207 = V_41 -> V_204 . V_208 ;
F_84 ( & V_41 -> V_201 ) ;
F_85 ( & V_41 -> V_201 , & V_41 -> V_209 , & V_41 -> V_210 ) ;
}
static struct V_199 * F_86 ( struct V_4 * V_4 ,
struct V_211 * V_212 , T_5 V_183 , int V_213 ,
const struct V_5 * V_214 ,
struct V_1 * V_7 ,
enum V_191 V_192 ,
T_6 V_215 )
{
struct V_4 * V_216 = F_87 ( V_4 ) ;
struct V_2 * V_3 = F_14 ( V_216 ) ;
struct V_13 * V_14 = F_88 ( V_3 ) ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
struct V_199 * V_41 ;
V_41 = F_89 ( sizeof( * V_41 ) , V_215 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_202 = F_90 ( V_14 , V_215 ) ;
if ( F_44 ( V_41 -> V_202 ) )
goto V_220;
V_218 = V_14 -> V_62 -> V_166 -> V_218 ;
V_41 -> V_204 . V_203 = V_218 ( & V_212 -> V_221 , V_215 ) ;
if ( F_44 ( V_41 -> V_204 . V_203 ) )
goto V_222;
F_91 ( V_4 -> V_223 ) ;
V_41 -> V_4 = F_92 ( V_4 ) ;
V_41 -> V_3 = V_216 ;
V_41 -> V_224 = V_212 ;
F_93 ( & V_212 -> V_225 ) ;
V_41 -> V_204 . V_226 = V_213 ;
V_41 -> V_204 . V_183 = V_183 & ( V_68 | V_185 ) ;
V_41 -> V_204 . V_227 = F_81 ( V_14 ,
V_183 , V_213 ) ;
if ( ! ( V_213 & V_228 ) ) {
V_41 -> V_204 . V_208 = V_229 | V_230 |
V_231 | V_232 ;
}
V_41 -> V_204 . V_233 = V_14 -> V_62 -> V_234 ;
V_41 -> V_204 . V_235 . V_236 = F_94 ( V_212 -> V_221 . V_236 ) ;
V_41 -> V_204 . V_235 . V_237 = V_212 -> V_221 . V_238 ;
V_41 -> V_204 . V_239 = & V_4 -> V_11 ;
V_41 -> V_204 . V_14 = V_14 ;
V_41 -> V_204 . V_240 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_204 . V_241 = & V_242 [ 0 ] ;
V_41 -> V_204 . V_7 = V_7 ;
V_41 -> V_204 . V_192 = F_82 ( V_14 , V_192 ) ;
switch ( V_41 -> V_204 . V_192 ) {
case V_194 :
case V_196 :
case V_198 :
V_41 -> V_204 . V_243 = F_95 ( V_3 ) ;
break;
case V_244 :
case V_193 :
case V_195 :
case V_197 :
V_41 -> V_204 . V_243 = F_95 ( F_14 ( V_4 ) ) ;
}
if ( V_214 != NULL && V_214 -> V_245 != 0 ) {
T_7 V_246 [ 2 ] ;
V_41 -> V_204 . V_247 . V_214 = & V_41 -> V_214 ;
memcpy ( & V_41 -> V_214 , V_214 , sizeof( V_41 -> V_214 ) ) ;
V_246 [ 0 ] = V_152 ;
V_246 [ 1 ] = V_57 -> V_248 ;
memcpy ( V_41 -> V_204 . V_247 . V_37 . V_156 , V_246 ,
sizeof( V_41 -> V_204 . V_247 . V_37 . V_156 ) ) ;
}
V_41 -> V_206 . V_243 = & V_41 -> V_200 . V_243 ;
V_41 -> V_206 . V_249 = & V_41 -> V_200 . V_249 ;
V_41 -> V_206 . V_203 = V_41 -> V_204 . V_203 ;
F_83 ( V_41 ) ;
F_96 ( & V_41 -> V_250 ) ;
return V_41 ;
V_222:
F_97 ( V_41 -> V_202 ) ;
V_220:
F_98 ( V_41 ) ;
V_8:
F_99 ( V_216 ) ;
return NULL ;
}
static void F_100 ( struct V_250 * V_250 )
{
struct V_199 * V_41 = F_101 ( V_250 ,
struct V_199 , V_250 ) ;
struct V_251 * V_252 = V_41 -> V_4 -> V_223 ;
F_102 ( V_41 -> V_204 . V_203 ) ;
if ( V_41 -> V_65 != NULL )
F_103 ( V_41 -> V_65 ) ;
F_104 ( V_41 -> V_224 ) ;
F_97 ( V_41 -> V_202 ) ;
F_99 ( V_41 -> V_3 ) ;
F_99 ( V_41 -> V_4 ) ;
F_105 ( V_252 ) ;
F_106 ( & V_41 -> V_201 ) ;
F_98 ( V_41 -> V_201 . V_253 ) ;
F_98 ( V_41 ) ;
}
static void F_107 ( struct V_199 * V_41 )
{
if ( V_41 != NULL )
F_108 ( & V_41 -> V_250 , F_100 ) ;
}
static int F_109 ( struct V_117 * V_118 )
{
int V_51 ;
V_51 = F_110 ( V_118 ) ;
return V_51 ;
}
static int F_111 ( struct V_64 * V_65 , T_5 V_254 , int V_255 )
{
int V_51 = 0 ;
if ( V_255 & ( V_228 | V_256 ) )
goto V_129;
switch ( V_254 & ( V_68 | V_185 ) ) {
case V_68 :
V_51 |= F_32 ( V_257 , & V_65 -> V_213 ) != 0
&& V_65 -> V_258 != 0 ;
break;
case V_185 :
V_51 |= F_32 ( V_259 , & V_65 -> V_213 ) != 0
&& V_65 -> V_260 != 0 ;
break;
case V_68 | V_185 :
V_51 |= F_32 ( V_261 , & V_65 -> V_213 ) != 0
&& V_65 -> V_262 != 0 ;
}
V_129:
return V_51 ;
}
static int F_112 ( struct V_263 * V_264 , T_5 V_183 )
{
if ( V_264 == NULL )
return 0 ;
if ( ( V_264 -> type & V_183 ) != V_183 )
return 0 ;
if ( F_32 ( V_265 , & V_264 -> V_213 ) )
return 0 ;
F_113 ( V_264 ) ;
return 1 ;
}
static void F_114 ( struct V_64 * V_65 , T_5 V_183 )
{
switch ( V_183 ) {
case V_185 :
V_65 -> V_260 ++ ;
break;
case V_68 :
V_65 -> V_258 ++ ;
break;
case V_68 | V_185 :
V_65 -> V_262 ++ ;
}
F_115 ( V_65 , V_65 -> V_65 | V_183 ) ;
}
static void F_116 ( struct V_64 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_224 -> V_266 -> V_62 ;
bool V_267 = false ;
if ( F_117 ( V_257 , & V_65 -> V_213 ) && V_65 -> V_258 )
V_267 = true ;
if ( F_117 ( V_259 , & V_65 -> V_213 ) && V_65 -> V_260 )
V_267 = true ;
if ( F_117 ( V_261 , & V_65 -> V_213 ) && V_65 -> V_262 )
V_267 = true ;
if ( V_267 )
F_118 ( V_63 , V_65 ) ;
}
static bool F_119 ( struct V_64 * V_65 ,
T_8 * V_249 )
{
if ( F_120 ( V_268 , & V_65 -> V_213 ) == 0 )
return true ;
if ( ! F_121 ( V_249 , & V_65 -> V_269 ) ) {
F_116 ( V_65 ) ;
return true ;
}
if ( F_122 ( V_249 , & V_65 -> V_269 ) )
return true ;
return false ;
}
static void F_123 ( struct V_64 * V_65 )
{
if ( V_65 -> V_260 )
F_124 ( V_259 , & V_65 -> V_213 ) ;
if ( V_65 -> V_258 )
F_124 ( V_257 , & V_65 -> V_213 ) ;
if ( V_65 -> V_262 )
F_124 ( V_261 , & V_65 -> V_213 ) ;
}
static void F_125 ( struct V_64 * V_65 ,
T_8 * V_249 , T_5 V_183 )
{
F_126 ( V_261 , & V_65 -> V_213 ) ;
switch ( V_183 & ( V_68 | V_185 ) ) {
case V_185 :
F_126 ( V_257 , & V_65 -> V_213 ) ;
break;
case V_68 :
F_126 ( V_259 , & V_65 -> V_213 ) ;
break;
case 0 :
F_126 ( V_257 , & V_65 -> V_213 ) ;
F_126 ( V_259 , & V_65 -> V_213 ) ;
F_126 ( V_268 , & V_65 -> V_213 ) ;
}
if ( V_249 == NULL )
return;
if ( ! F_121 ( V_249 , & V_65 -> V_269 ) ||
! F_122 ( V_249 , & V_65 -> V_269 ) ) {
F_123 ( V_65 ) ;
return;
}
if ( F_32 ( V_270 , & V_65 -> V_213 ) == 0 )
F_127 ( & V_65 -> V_249 , V_249 ) ;
F_127 ( & V_65 -> V_269 , V_249 ) ;
}
static void F_128 ( struct V_64 * V_65 , T_8 * V_249 , T_5 V_183 )
{
F_129 ( & V_65 -> V_271 ) ;
F_125 ( V_65 , V_249 , V_183 ) ;
F_130 ( & V_65 -> V_271 ) ;
if ( F_32 ( V_272 , & V_65 -> V_213 ) )
F_131 ( V_65 -> V_224 -> V_266 -> V_62 ) ;
}
static void F_132 ( struct V_64 * V_65 , T_8 * V_249 , T_5 V_183 )
{
switch ( V_183 ) {
case V_68 :
F_124 ( V_257 , & V_65 -> V_213 ) ;
break;
case V_185 :
F_124 ( V_259 , & V_65 -> V_213 ) ;
break;
case V_68 | V_185 :
F_124 ( V_261 , & V_65 -> V_213 ) ;
}
if ( ! F_119 ( V_65 , V_249 ) )
return;
if ( F_32 ( V_270 , & V_65 -> V_213 ) == 0 )
F_127 ( & V_65 -> V_249 , V_249 ) ;
F_127 ( & V_65 -> V_269 , V_249 ) ;
}
static void F_133 ( struct V_64 * V_65 , T_8 * V_269 , const T_8 * V_273 , T_5 V_183 )
{
F_129 ( & V_65 -> V_271 ) ;
if ( V_273 != NULL ) {
F_127 ( & V_65 -> V_249 , V_273 ) ;
F_124 ( V_270 , & V_65 -> V_213 ) ;
}
if ( V_269 != NULL )
F_132 ( V_65 , V_269 , V_183 ) ;
F_130 ( & V_65 -> V_271 ) ;
F_35 ( & V_65 -> V_224 -> V_274 ) ;
F_114 ( V_65 , V_183 ) ;
F_37 ( & V_65 -> V_224 -> V_274 ) ;
}
static int F_134 ( struct V_64 * V_65 , T_8 * V_269 , T_8 * V_264 , T_5 V_183 )
{
struct V_171 * V_172 = F_76 ( V_65 -> V_2 ) ;
struct V_263 * V_275 ;
int V_51 = 0 ;
V_183 &= ( V_68 | V_185 ) ;
F_135 () ;
V_275 = F_136 ( V_172 -> V_264 ) ;
if ( V_275 == NULL )
goto V_276;
F_35 ( & V_275 -> V_277 ) ;
if ( F_136 ( V_172 -> V_264 ) != V_275 ||
F_32 ( V_265 , & V_275 -> V_213 ) ||
( V_275 -> type & V_183 ) != V_183 )
goto V_278;
if ( V_264 == NULL )
V_264 = & V_275 -> V_249 ;
else if ( ! F_137 ( & V_275 -> V_249 , V_264 ) )
goto V_278;
F_113 ( V_275 ) ;
F_133 ( V_65 , V_269 , & V_275 -> V_249 , V_183 ) ;
V_51 = 1 ;
V_278:
F_37 ( & V_275 -> V_277 ) ;
V_276:
F_138 () ;
if ( ! V_51 && V_269 != NULL ) {
F_133 ( V_65 , V_269 , NULL , V_183 ) ;
V_51 = 1 ;
}
if ( F_32 ( V_272 , & V_65 -> V_213 ) )
F_131 ( V_65 -> V_224 -> V_266 -> V_62 ) ;
return V_51 ;
}
static bool F_139 ( struct V_279 * V_280 ,
const T_8 * V_249 )
{
struct V_64 * V_65 = V_280 -> V_281 ;
bool V_51 = false ;
F_35 ( & V_65 -> V_282 ) ;
if ( ! F_121 ( V_249 , & V_280 -> V_283 ) )
goto V_284;
if ( ! F_122 ( V_249 , & V_280 -> V_283 ) )
goto V_284;
F_127 ( & V_280 -> V_283 , V_249 ) ;
V_51 = true ;
V_284:
F_37 ( & V_65 -> V_282 ) ;
return V_51 ;
}
static void F_140 ( struct V_2 * V_2 , T_5 V_183 )
{
struct V_263 * V_264 ;
F_135 () ;
V_264 = F_136 ( F_76 ( V_2 ) -> V_264 ) ;
if ( V_264 == NULL || ( V_264 -> type & V_183 ) == V_183 ) {
F_138 () ;
return;
}
F_138 () ;
F_23 ( V_2 ) ;
}
static struct V_64 * F_141 ( struct V_199 * V_285 )
{
struct V_64 * V_65 = V_285 -> V_65 ;
struct V_171 * V_172 = F_76 ( V_65 -> V_2 ) ;
struct V_263 * V_264 ;
int V_255 = V_285 -> V_204 . V_226 ;
T_5 V_183 = V_285 -> V_204 . V_183 ;
T_8 V_249 ;
int V_51 = - V_128 ;
for (; ; ) {
F_35 ( & V_65 -> V_224 -> V_274 ) ;
if ( F_111 ( V_65 , V_183 , V_255 ) ) {
F_114 ( V_65 , V_183 ) ;
F_37 ( & V_65 -> V_224 -> V_274 ) ;
goto V_286;
}
F_37 ( & V_65 -> V_224 -> V_274 ) ;
F_135 () ;
V_264 = F_136 ( V_172 -> V_264 ) ;
if ( ! F_112 ( V_264 , V_183 ) ) {
F_138 () ;
break;
}
F_127 ( & V_249 , & V_264 -> V_249 ) ;
F_138 () ;
F_142 ( V_285 -> V_204 . V_203 ) ;
if ( ! V_285 -> V_287 ) {
V_51 = F_143 ( V_65 -> V_2 , V_65 -> V_224 -> V_288 , V_255 ) ;
if ( V_51 != 0 )
goto V_129;
}
V_51 = - V_128 ;
if ( F_134 ( V_65 , NULL , & V_249 , V_183 ) )
goto V_286;
}
V_129:
return F_45 ( V_51 ) ;
V_286:
F_93 ( & V_65 -> V_49 ) ;
return V_65 ;
}
static void
F_144 ( struct V_199 * V_156 , struct V_64 * V_65 )
{
struct V_62 * V_63 = F_88 ( V_65 -> V_2 ) -> V_62 ;
struct V_263 * V_264 ;
int V_289 = 0 ;
F_135 () ;
V_264 = F_136 ( F_76 ( V_65 -> V_2 ) -> V_264 ) ;
if ( V_264 )
V_289 = V_264 -> V_213 ;
F_138 () ;
if ( V_156 -> V_204 . V_192 == V_196 ) {
F_145 ( L_18
L_19
L_20 ,
V_63 -> V_96 ) ;
} else if ( ( V_289 & 1UL << V_290 ) == 0 )
F_146 ( V_65 -> V_2 ,
V_156 -> V_224 -> V_288 ,
& V_156 -> V_200 ) ;
else
F_147 ( V_65 -> V_2 ,
V_156 -> V_224 -> V_288 ,
& V_156 -> V_200 ) ;
}
static struct V_64 *
F_148 ( struct V_199 * V_156 )
{
struct V_2 * V_2 = V_156 -> V_65 -> V_2 ;
struct V_64 * V_65 = V_156 -> V_65 ;
int V_51 ;
if ( ! V_156 -> V_291 ) {
if ( V_156 -> V_292 ) {
V_51 = V_156 -> V_292 ;
goto V_8;
}
goto V_293;
}
V_51 = F_149 ( V_2 , & V_156 -> V_201 ) ;
if ( V_51 )
goto V_8;
if ( V_156 -> V_200 . V_294 != 0 )
F_144 ( V_156 , V_65 ) ;
V_293:
F_134 ( V_65 , & V_156 -> V_200 . V_249 , NULL ,
V_156 -> V_204 . V_183 ) ;
F_93 ( & V_65 -> V_49 ) ;
return V_65 ;
V_8:
return F_45 ( V_51 ) ;
}
static struct V_64 *
F_150 ( struct V_199 * V_156 )
{
struct V_2 * V_2 ;
struct V_64 * V_65 = NULL ;
int V_51 ;
if ( ! V_156 -> V_291 ) {
V_65 = F_141 ( V_156 ) ;
goto V_129;
}
V_51 = - V_128 ;
if ( ! ( V_156 -> V_201 . V_295 & V_296 ) )
goto V_8;
V_2 = F_151 ( V_156 -> V_3 -> V_223 , & V_156 -> V_200 . V_243 , & V_156 -> V_201 , V_156 -> V_202 ) ;
V_51 = F_72 ( V_2 ) ;
if ( F_44 ( V_2 ) )
goto V_8;
V_51 = - V_124 ;
V_65 = F_152 ( V_2 , V_156 -> V_224 ) ;
if ( V_65 == NULL )
goto V_297;
if ( V_156 -> V_200 . V_294 != 0 )
F_144 ( V_156 , V_65 ) ;
F_134 ( V_65 , & V_156 -> V_200 . V_249 , NULL ,
V_156 -> V_204 . V_183 ) ;
F_153 ( V_2 ) ;
V_129:
F_142 ( V_156 -> V_204 . V_203 ) ;
return V_65 ;
V_297:
F_153 ( V_2 ) ;
V_8:
return F_45 ( V_51 ) ;
}
static struct V_64 *
F_154 ( struct V_199 * V_156 )
{
if ( V_156 -> V_204 . V_192 == V_244 )
return F_148 ( V_156 ) ;
return F_150 ( V_156 ) ;
}
static struct V_298 * F_155 ( struct V_64 * V_65 )
{
struct V_171 * V_172 = F_76 ( V_65 -> V_2 ) ;
struct V_298 * V_299 ;
F_35 ( & V_65 -> V_2 -> V_173 ) ;
F_156 (ctx, &nfsi->open_files, list) {
if ( V_299 -> V_65 != V_65 )
continue;
F_157 ( V_299 ) ;
F_37 ( & V_65 -> V_2 -> V_173 ) ;
return V_299 ;
}
F_37 ( & V_65 -> V_2 -> V_173 ) ;
return F_45 ( - V_300 ) ;
}
static struct V_199 * F_158 ( struct V_298 * V_299 ,
struct V_64 * V_65 , enum V_191 V_192 )
{
struct V_199 * V_285 ;
V_285 = F_86 ( V_299 -> V_4 , V_65 -> V_224 , 0 , 0 ,
NULL , NULL , V_192 , V_301 ) ;
if ( V_285 == NULL )
return F_45 ( - V_124 ) ;
V_285 -> V_65 = V_65 ;
F_93 ( & V_65 -> V_49 ) ;
return V_285 ;
}
static int F_159 ( struct V_199 * V_285 , T_5 V_183 , struct V_64 * * V_56 )
{
struct V_64 * V_302 ;
int V_51 ;
V_285 -> V_204 . V_226 = 0 ;
V_285 -> V_204 . V_183 = V_183 ;
V_285 -> V_204 . V_227 = F_81 (
F_160 ( V_285 -> V_4 -> V_223 ) ,
V_183 , 0 ) ;
memset ( & V_285 -> V_200 , 0 , sizeof( V_285 -> V_200 ) ) ;
memset ( & V_285 -> V_205 , 0 , sizeof( V_285 -> V_205 ) ) ;
F_83 ( V_285 ) ;
V_51 = F_161 ( V_285 ) ;
if ( V_51 != 0 )
return V_51 ;
V_302 = F_154 ( V_285 ) ;
if ( F_44 ( V_302 ) )
return F_72 ( V_302 ) ;
F_162 ( V_302 , V_183 ) ;
* V_56 = V_302 ;
return 0 ;
}
static int F_163 ( struct V_199 * V_285 , struct V_64 * V_65 )
{
struct V_64 * V_302 ;
int V_51 ;
F_126 ( V_261 , & V_65 -> V_213 ) ;
F_126 ( V_259 , & V_65 -> V_213 ) ;
F_126 ( V_257 , & V_65 -> V_213 ) ;
F_126 ( V_270 , & V_65 -> V_213 ) ;
F_126 ( V_268 , & V_65 -> V_213 ) ;
F_164 () ;
if ( V_65 -> V_262 != 0 ) {
V_51 = F_159 ( V_285 , V_68 | V_185 , & V_302 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( V_302 != V_65 )
return - V_303 ;
}
if ( V_65 -> V_260 != 0 ) {
V_51 = F_159 ( V_285 , V_185 , & V_302 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( V_302 != V_65 )
return - V_303 ;
}
if ( V_65 -> V_258 != 0 ) {
V_51 = F_159 ( V_285 , V_68 , & V_302 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( V_302 != V_65 )
return - V_303 ;
}
if ( F_32 ( V_270 , & V_65 -> V_213 ) == 0 &&
! F_137 ( & V_65 -> V_249 , & V_65 -> V_269 ) ) {
F_129 ( & V_65 -> V_271 ) ;
if ( F_32 ( V_270 , & V_65 -> V_213 ) == 0 )
F_127 ( & V_65 -> V_249 , & V_65 -> V_269 ) ;
F_130 ( & V_65 -> V_271 ) ;
}
return 0 ;
}
static int F_165 ( struct V_298 * V_299 , struct V_64 * V_65 )
{
struct V_263 * V_264 ;
struct V_199 * V_285 ;
T_5 V_294 = 0 ;
int V_304 ;
V_285 = F_158 ( V_299 , V_65 ,
V_244 ) ;
if ( F_44 ( V_285 ) )
return F_72 ( V_285 ) ;
F_135 () ;
V_264 = F_136 ( F_76 ( V_65 -> V_2 ) -> V_264 ) ;
if ( V_264 != NULL && F_32 ( V_290 , & V_264 -> V_213 ) != 0 )
V_294 = V_264 -> type ;
F_138 () ;
V_285 -> V_204 . V_247 . V_294 = V_294 ;
V_304 = F_163 ( V_285 , V_65 ) ;
F_107 ( V_285 ) ;
return V_304 ;
}
static int F_166 ( struct V_298 * V_299 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_165 ( V_299 , V_65 ) ;
F_167 ( V_299 , 0 , V_8 ) ;
if ( F_80 ( V_14 , V_8 , & V_61 ) )
continue;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_168 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
struct V_298 * V_299 ;
int V_51 ;
V_299 = F_155 ( V_65 ) ;
if ( F_44 ( V_299 ) )
return - V_128 ;
V_51 = F_166 ( V_299 , V_65 ) ;
F_169 ( V_299 ) ;
return V_51 ;
}
static int F_170 ( struct V_13 * V_14 , struct V_64 * V_65 , const T_8 * V_249 , int V_8 )
{
switch ( V_8 ) {
default:
F_30 ( V_305 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_300 :
case - V_303 :
break;
case - V_79 :
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
F_124 ( V_270 , & V_65 -> V_213 ) ;
F_29 ( V_14 -> V_62 -> V_86 , V_8 ) ;
return - V_128 ;
case - V_75 :
case - V_74 :
F_124 ( V_270 , & V_65 -> V_213 ) ;
case - V_73 :
F_25 ( V_14 -> V_62 ) ;
return - V_128 ;
case - V_76 :
F_26 ( V_14 ) ;
return - V_128 ;
case - V_77 :
F_27 ( V_14 -> V_62 ) ;
return - V_128 ;
case - V_70 :
case - V_71 :
case - V_72 :
case - V_67 :
F_171 ( V_65 -> V_2 ,
V_249 ) ;
F_24 ( V_14 , V_65 ) ;
return - V_128 ;
case - V_89 :
case - V_88 :
F_124 ( V_270 , & V_65 -> V_213 ) ;
F_172 ( 1 ) ;
return - V_128 ;
case - V_124 :
case - V_306 :
return 0 ;
}
return V_8 ;
}
int F_173 ( struct V_298 * V_299 , struct V_64 * V_65 , const T_8 * V_249 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
struct V_199 * V_285 ;
int V_8 ;
V_285 = F_158 ( V_299 , V_65 ,
V_195 ) ;
if ( F_44 ( V_285 ) )
return F_72 ( V_285 ) ;
F_127 ( & V_285 -> V_204 . V_247 . V_264 , V_249 ) ;
V_8 = F_163 ( V_285 , V_65 ) ;
F_107 ( V_285 ) ;
return F_170 ( V_14 , V_65 , V_249 , V_8 ) ;
}
static void F_174 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
F_41 ( V_156 -> V_204 . V_14 -> V_62 -> V_153 ,
& V_156 -> V_206 . V_158 , & V_156 -> V_205 . V_159 , V_118 ) ;
}
static void F_175 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
F_49 ( V_118 , & V_156 -> V_205 . V_159 ) ;
V_156 -> V_292 = V_118 -> V_147 ;
if ( V_156 -> V_292 == 0 ) {
F_127 ( & V_156 -> V_200 . V_249 , & V_156 -> V_205 . V_249 ) ;
F_176 ( & V_156 -> V_224 -> V_221 , 0 ) ;
F_38 ( V_156 -> V_200 . V_14 , V_156 -> V_105 ) ;
V_156 -> V_291 = 1 ;
}
}
static void F_177 ( void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_64 * V_65 = NULL ;
if ( V_156 -> V_307 == 0 )
goto V_308;
if ( ! V_156 -> V_291 )
goto V_308;
V_65 = F_154 ( V_156 ) ;
if ( ! F_44 ( V_65 ) )
F_162 ( V_65 , V_156 -> V_204 . V_183 ) ;
V_308:
F_107 ( V_156 ) ;
}
static int F_178 ( struct V_199 * V_156 )
{
struct V_13 * V_14 = F_88 ( F_14 ( V_156 -> V_3 ) ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_311 ] ,
. V_312 = & V_156 -> V_206 ,
. V_313 = & V_156 -> V_205 ,
. V_314 = V_156 -> V_224 -> V_288 ,
} ;
struct V_162 V_315 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_316 ,
. V_168 = V_156 ,
. V_317 = V_318 ,
. V_213 = V_319 ,
} ;
int V_304 ;
F_39 ( & V_156 -> V_206 . V_158 , & V_156 -> V_205 . V_159 , 1 ) ;
F_179 ( & V_156 -> V_250 ) ;
V_156 -> V_291 = 0 ;
V_156 -> V_292 = 0 ;
V_156 -> V_105 = V_152 ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) )
return F_72 ( V_118 ) ;
V_304 = F_109 ( V_118 ) ;
if ( V_304 != 0 ) {
V_156 -> V_307 = 1 ;
F_180 () ;
} else
V_304 = V_156 -> V_292 ;
F_73 ( V_118 ) ;
return V_304 ;
}
static void F_181 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_211 * V_212 = V_156 -> V_224 ;
struct V_62 * V_63 = V_212 -> V_266 -> V_62 ;
if ( F_182 ( V_156 -> V_204 . V_203 , V_118 ) != 0 )
goto V_320;
if ( V_156 -> V_65 != NULL ) {
struct V_263 * V_264 ;
if ( F_111 ( V_156 -> V_65 , V_156 -> V_204 . V_183 , V_156 -> V_204 . V_226 ) )
goto V_321;
F_135 () ;
V_264 = F_136 ( F_76 ( V_156 -> V_65 -> V_2 ) -> V_264 ) ;
if ( V_156 -> V_204 . V_192 != V_196 &&
V_156 -> V_204 . V_192 != V_195 &&
F_112 ( V_264 , V_156 -> V_204 . V_183 ) )
goto V_322;
F_138 () ;
}
V_156 -> V_204 . V_233 = V_63 -> V_234 ;
switch ( V_156 -> V_204 . V_192 ) {
case V_244 :
case V_195 :
case V_197 :
V_156 -> V_204 . V_241 = & V_323 [ 0 ] ;
case V_193 :
V_118 -> V_324 . V_309 = & V_310 [ V_325 ] ;
F_183 ( & V_156 -> V_200 . V_243 , V_156 -> V_204 . V_243 ) ;
}
V_156 -> V_105 = V_152 ;
if ( F_64 ( V_156 -> V_204 . V_14 ,
& V_156 -> V_204 . V_158 ,
& V_156 -> V_200 . V_159 ,
V_118 ) != 0 )
F_142 ( V_156 -> V_204 . V_203 ) ;
V_156 -> V_204 . V_326 = V_327 ;
if ( V_156 -> V_204 . V_226 & V_228 ) {
V_156 -> V_204 . V_326 = V_328 ;
if ( F_184 ( V_63 ) )
V_156 -> V_204 . V_326 = V_329 ;
else if ( V_63 -> V_166 -> V_330 > 0 )
V_156 -> V_204 . V_326 = V_331 ;
}
return;
V_322:
F_138 () ;
V_321:
V_118 -> V_332 = NULL ;
V_320:
F_61 ( V_118 , & V_156 -> V_200 . V_159 ) ;
}
static void F_185 ( struct V_117 * V_118 , void * V_154 )
{
struct V_199 * V_156 = V_154 ;
V_156 -> V_292 = V_118 -> V_147 ;
if ( ! F_61 ( V_118 , & V_156 -> V_200 . V_159 ) )
return;
if ( V_118 -> V_147 == 0 ) {
if ( V_156 -> V_200 . V_201 -> V_295 & V_333 ) {
switch ( V_156 -> V_200 . V_201 -> V_254 & V_334 ) {
case V_335 :
break;
case V_336 :
V_156 -> V_292 = - V_337 ;
break;
case V_338 :
V_156 -> V_292 = - V_339 ;
break;
default:
V_156 -> V_292 = - V_340 ;
}
}
F_38 ( V_156 -> V_200 . V_14 , V_156 -> V_105 ) ;
if ( ! ( V_156 -> V_200 . V_341 & V_342 ) )
F_176 ( & V_156 -> V_224 -> V_221 , 0 ) ;
}
V_156 -> V_291 = 1 ;
}
static void F_186 ( void * V_154 )
{
struct V_199 * V_156 = V_154 ;
struct V_64 * V_65 = NULL ;
if ( V_156 -> V_307 == 0 )
goto V_308;
if ( V_156 -> V_292 != 0 || ! V_156 -> V_291 )
goto V_308;
if ( V_156 -> V_200 . V_341 & V_342 )
goto V_308;
V_65 = F_154 ( V_156 ) ;
if ( ! F_44 ( V_65 ) )
F_162 ( V_65 , V_156 -> V_204 . V_183 ) ;
V_308:
F_107 ( V_156 ) ;
}
static int F_187 ( struct V_199 * V_156 , int V_343 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_13 * V_14 = F_88 ( V_3 ) ;
struct V_344 * V_204 = & V_156 -> V_204 ;
struct V_345 * V_200 = & V_156 -> V_200 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_346 ] ,
. V_312 = V_204 ,
. V_313 = V_200 ,
. V_314 = V_156 -> V_224 -> V_288 ,
} ;
struct V_162 V_315 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_347 ,
. V_168 = V_156 ,
. V_317 = V_318 ,
. V_213 = V_319 ,
} ;
int V_304 ;
F_39 ( & V_204 -> V_158 , & V_200 -> V_159 , 1 ) ;
F_179 ( & V_156 -> V_250 ) ;
V_156 -> V_291 = 0 ;
V_156 -> V_292 = 0 ;
V_156 -> V_307 = 0 ;
V_156 -> V_287 = 0 ;
if ( V_343 ) {
F_40 ( & V_204 -> V_158 ) ;
V_156 -> V_287 = 1 ;
}
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) )
return F_72 ( V_118 ) ;
V_304 = F_109 ( V_118 ) ;
if ( V_304 != 0 ) {
V_156 -> V_307 = 1 ;
F_180 () ;
} else
V_304 = V_156 -> V_292 ;
F_73 ( V_118 ) ;
return V_304 ;
}
static int F_161 ( struct V_199 * V_156 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_345 * V_200 = & V_156 -> V_200 ;
int V_304 ;
V_304 = F_187 ( V_156 , 1 ) ;
if ( V_304 != 0 || ! V_156 -> V_291 )
return V_304 ;
F_188 ( F_88 ( V_3 ) , & V_156 -> V_201 ) ;
if ( V_200 -> V_341 & V_342 ) {
V_304 = F_178 ( V_156 ) ;
if ( V_304 != 0 )
return V_304 ;
}
return V_304 ;
}
static int F_189 ( struct V_314 * V_348 ,
struct V_199 * V_285 ,
struct V_64 * V_65 , T_5 V_183 ,
int V_184 )
{
struct V_349 V_350 ;
T_1 V_351 ;
if ( V_285 -> V_200 . V_352 == 0 )
return 0 ;
V_351 = 0 ;
if ( V_184 & V_353 ) {
V_351 = V_354 ;
} else if ( ( V_183 & V_68 ) && ! V_285 -> V_355 )
V_351 = V_356 ;
V_350 . V_348 = V_348 ;
V_350 . V_152 = V_152 ;
F_190 ( & V_350 , V_285 -> V_200 . V_357 ) ;
F_191 ( V_65 -> V_2 , & V_350 ) ;
if ( ( V_351 & ~ V_350 . V_351 & ( V_356 | V_354 ) ) == 0 )
return 0 ;
F_162 ( V_65 , V_183 ) ;
return - V_29 ;
}
static int F_192 ( struct V_199 * V_156 )
{
struct V_2 * V_3 = F_14 ( V_156 -> V_3 ) ;
struct V_13 * V_14 = F_88 ( V_3 ) ;
struct V_344 * V_204 = & V_156 -> V_204 ;
struct V_345 * V_200 = & V_156 -> V_200 ;
int V_304 ;
V_304 = F_187 ( V_156 , 0 ) ;
if ( ! V_156 -> V_291 )
return V_304 ;
if ( V_304 != 0 ) {
if ( V_304 == - V_26 &&
! ( V_204 -> V_226 & V_358 ) )
return - V_300 ;
return V_304 ;
}
F_188 ( V_14 , & V_156 -> V_201 ) ;
if ( V_204 -> V_226 & V_358 ) {
F_75 ( V_3 , & V_200 -> V_170 ) ;
if ( V_204 -> V_226 & V_228 )
V_156 -> V_355 = 1 ;
else if ( V_200 -> V_170 . V_178 != V_200 -> V_170 . V_180 )
V_156 -> V_355 = 1 ;
}
if ( ( V_200 -> V_341 & V_359 ) == 0 )
V_14 -> V_93 &= ~ V_360 ;
if( V_200 -> V_341 & V_342 ) {
V_304 = F_178 ( V_156 ) ;
if ( V_304 != 0 )
return V_304 ;
}
if ( ! ( V_200 -> V_201 -> V_295 & V_296 ) )
F_193 ( V_14 , & V_200 -> V_243 , V_200 -> V_201 , V_200 -> V_202 ) ;
return 0 ;
}
static int F_194 ( struct V_13 * V_14 )
{
return F_195 ( V_14 -> V_62 ) ;
}
static int F_196 ( struct V_298 * V_299 , struct V_64 * V_65 )
{
struct V_199 * V_285 ;
int V_51 ;
V_285 = F_158 ( V_299 , V_65 ,
V_193 ) ;
if ( F_44 ( V_285 ) )
return F_72 ( V_285 ) ;
V_51 = F_163 ( V_285 , V_65 ) ;
if ( V_51 == - V_303 )
F_197 ( V_299 -> V_4 ) ;
F_107 ( V_285 ) ;
return V_51 ;
}
static int F_198 ( struct V_298 * V_299 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_196 ( V_299 , V_65 ) ;
F_199 ( V_299 , 0 , V_8 ) ;
if ( F_80 ( V_14 , V_8 , & V_61 ) )
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
static int F_200 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
struct V_298 * V_299 ;
int V_51 ;
V_299 = F_155 ( V_65 ) ;
if ( F_44 ( V_299 ) )
return - V_128 ;
V_51 = F_198 ( V_299 , V_65 ) ;
F_169 ( V_299 ) ;
return V_51 ;
}
static void F_201 ( struct V_64 * V_65 )
{
F_202 ( V_65 -> V_2 ) ;
F_129 ( & V_65 -> V_271 ) ;
F_127 ( & V_65 -> V_249 , & V_65 -> V_269 ) ;
F_130 ( & V_65 -> V_271 ) ;
F_126 ( V_270 , & V_65 -> V_213 ) ;
}
static void F_203 ( struct V_64 * V_65 )
{
if ( F_204 ( F_76 ( V_65 -> V_2 ) -> V_264 ) != NULL )
F_201 ( V_65 ) ;
}
static int F_205 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
F_203 ( V_65 ) ;
return F_200 ( V_212 , V_65 ) ;
}
static void F_206 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
T_8 V_249 ;
struct V_263 * V_264 ;
struct V_314 * V_348 ;
int V_304 ;
F_135 () ;
V_264 = F_136 ( F_76 ( V_65 -> V_2 ) -> V_264 ) ;
if ( V_264 == NULL ) {
F_138 () ;
return;
}
F_127 ( & V_249 , & V_264 -> V_249 ) ;
V_348 = F_207 ( V_264 -> V_348 ) ;
F_138 () ;
V_304 = F_208 ( V_14 , & V_249 , V_348 ) ;
F_209 ( V_65 , NULL , V_304 ) ;
if ( V_304 != V_361 ) {
if ( V_304 != - V_72 )
F_210 ( V_14 , & V_249 , V_348 ) ;
F_201 ( V_65 ) ;
}
F_211 ( V_348 ) ;
}
static int F_212 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
T_8 * V_249 = & V_65 -> V_269 ;
struct V_314 * V_348 = V_65 -> V_224 -> V_288 ;
int V_304 ;
if ( ( F_32 ( V_257 , & V_65 -> V_213 ) == 0 ) &&
( F_32 ( V_259 , & V_65 -> V_213 ) == 0 ) &&
( F_32 ( V_261 , & V_65 -> V_213 ) == 0 ) )
return - V_72 ;
V_304 = F_208 ( V_14 , V_249 , V_348 ) ;
F_213 ( V_65 , NULL , V_304 ) ;
if ( V_304 != V_361 ) {
if ( V_304 != - V_72 )
F_210 ( V_14 , V_249 , V_348 ) ;
F_126 ( V_257 , & V_65 -> V_213 ) ;
F_126 ( V_259 , & V_65 -> V_213 ) ;
F_126 ( V_261 , & V_65 -> V_213 ) ;
F_126 ( V_268 , & V_65 -> V_213 ) ;
}
return V_304 ;
}
static int F_214 ( struct V_211 * V_212 , struct V_64 * V_65 )
{
int V_304 ;
F_206 ( V_65 ) ;
V_304 = F_212 ( V_65 ) ;
if ( V_304 != V_361 )
V_304 = F_200 ( V_212 , V_65 ) ;
return V_304 ;
}
static inline void F_215 ( struct V_199 * V_285 , struct V_5 * V_6 )
{
if ( ( V_285 -> V_200 . V_362 [ 1 ] & V_363 ) &&
! ( V_6 -> V_245 & V_364 ) )
V_6 -> V_245 |= V_365 ;
if ( ( V_285 -> V_200 . V_362 [ 1 ] & V_366 ) &&
! ( V_6 -> V_245 & V_367 ) )
V_6 -> V_245 |= V_368 ;
}
static int F_216 ( struct V_199 * V_285 ,
T_5 V_183 ,
int V_213 ,
struct V_298 * V_299 )
{
struct V_211 * V_212 = V_285 -> V_224 ;
struct V_13 * V_14 = V_212 -> V_266 ;
struct V_4 * V_4 ;
struct V_64 * V_65 ;
unsigned int V_369 ;
int V_51 ;
V_369 = F_217 ( & V_212 -> V_370 ) ;
V_51 = F_192 ( V_285 ) ;
if ( V_51 != 0 )
goto V_129;
V_65 = F_154 ( V_285 ) ;
V_51 = F_72 ( V_65 ) ;
if ( F_44 ( V_65 ) )
goto V_129;
if ( V_14 -> V_93 & V_360 )
F_124 ( V_371 , & V_65 -> V_213 ) ;
V_4 = V_285 -> V_4 ;
if ( F_218 ( V_4 ) ) {
F_197 ( V_4 ) ;
V_4 = F_219 ( V_4 , F_220 ( V_65 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_285 -> V_4 ;
} else if ( V_4 != V_299 -> V_4 ) {
F_99 ( V_299 -> V_4 ) ;
V_299 -> V_4 = F_92 ( V_4 ) ;
}
F_221 ( V_4 ,
F_222 ( F_14 ( V_285 -> V_3 ) ) ) ;
}
V_51 = F_189 ( V_212 -> V_288 , V_285 , V_65 , V_183 , V_213 ) ;
if ( V_51 != 0 )
goto V_129;
V_299 -> V_65 = V_65 ;
if ( F_14 ( V_4 ) == V_65 -> V_2 ) {
F_223 ( V_299 ) ;
if ( F_224 ( & V_212 -> V_370 , V_369 ) )
F_24 ( V_14 , V_65 ) ;
}
V_129:
return V_51 ;
}
static int F_225 ( struct V_2 * V_3 ,
struct V_298 * V_299 ,
int V_213 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_372 )
{
struct V_211 * V_212 ;
struct V_64 * V_65 = NULL ;
struct V_13 * V_14 = F_88 ( V_3 ) ;
struct V_199 * V_285 ;
struct V_4 * V_4 = V_299 -> V_4 ;
struct V_314 * V_348 = V_299 -> V_348 ;
struct V_373 * * V_374 = & V_299 -> V_253 ;
T_5 V_183 = V_299 -> V_254 & ( V_68 | V_185 | V_375 ) ;
enum V_191 V_192 = V_194 ;
struct V_1 * V_376 = NULL ;
int V_304 ;
V_304 = - V_124 ;
V_212 = F_226 ( V_14 , V_348 , V_377 ) ;
if ( V_212 == NULL ) {
F_8 ( L_23 ) ;
goto V_378;
}
V_304 = F_194 ( V_14 ) ;
if ( V_304 != 0 )
goto V_379;
if ( F_227 ( V_4 ) )
F_140 ( F_14 ( V_4 ) , V_183 ) ;
V_304 = - V_124 ;
if ( F_227 ( V_4 ) )
V_192 = V_193 ;
V_285 = F_86 ( V_4 , V_212 , V_183 , V_213 , V_6 ,
V_7 , V_192 , V_377 ) ;
if ( V_285 == NULL )
goto V_379;
if ( V_7 ) {
V_376 = F_90 ( V_14 , V_377 ) ;
if ( F_44 ( V_376 ) ) {
V_304 = F_72 ( V_376 ) ;
goto V_380;
}
}
if ( V_14 -> V_15 [ 2 ] & V_381 ) {
if ( ! V_285 -> V_201 . V_253 ) {
V_285 -> V_201 . V_253 = F_228 () ;
if ( ! V_285 -> V_201 . V_253 )
goto V_222;
}
V_285 -> V_204 . V_241 = & V_382 [ 0 ] ;
}
if ( F_227 ( V_4 ) )
V_285 -> V_65 = F_152 ( F_14 ( V_4 ) , V_212 ) ;
V_304 = F_216 ( V_285 , V_183 , V_213 , V_299 ) ;
if ( V_304 != 0 )
goto V_222;
V_65 = V_299 -> V_65 ;
if ( ( V_285 -> V_204 . V_226 & V_228 ) &&
( V_285 -> V_204 . V_326 != V_329 ) ) {
F_215 ( V_285 , V_6 ) ;
F_84 ( V_285 -> V_200 . V_201 ) ;
V_304 = F_229 ( V_65 -> V_2 , V_348 ,
V_285 -> V_200 . V_201 , V_6 ,
V_65 , V_7 , V_376 ) ;
if ( V_304 == 0 ) {
F_230 ( V_65 -> V_2 , V_6 ,
V_285 -> V_200 . V_201 ) ;
F_231 ( V_65 -> V_2 , V_285 -> V_200 . V_201 , V_376 ) ;
}
}
if ( V_285 -> V_355 )
* V_372 |= V_383 ;
if ( F_232 ( V_374 , V_285 -> V_201 . V_253 , V_14 ) ) {
* V_374 = V_285 -> V_201 . V_253 ;
V_285 -> V_201 . V_253 = NULL ;
}
F_97 ( V_376 ) ;
F_107 ( V_285 ) ;
F_104 ( V_212 ) ;
return 0 ;
V_222:
F_97 ( V_376 ) ;
V_380:
F_107 ( V_285 ) ;
V_379:
F_104 ( V_212 ) ;
V_378:
return V_304 ;
}
static struct V_64 * F_233 ( struct V_2 * V_3 ,
struct V_298 * V_299 ,
int V_213 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_372 )
{
struct V_13 * V_14 = F_88 ( V_3 ) ;
struct V_60 V_61 = { } ;
struct V_64 * V_56 ;
int V_304 ;
do {
V_304 = F_225 ( V_3 , V_299 , V_213 , V_6 , V_7 , V_372 ) ;
V_56 = V_299 -> V_65 ;
F_234 ( V_299 , V_213 , V_304 ) ;
if ( V_304 == 0 )
break;
if ( V_304 == - V_384 ) {
F_235 ( L_5
L_24 ,
F_88 ( V_3 ) -> V_62 -> V_96 ) ;
V_61 . V_66 = 1 ;
continue;
}
if ( V_304 == - V_72 ) {
V_61 . V_66 = 1 ;
continue;
}
if ( V_304 == - V_128 ) {
V_61 . V_66 = 1 ;
continue;
}
if ( F_80 ( V_14 , V_304 , & V_61 ) )
continue;
V_56 = F_45 ( F_21 ( V_14 ,
V_304 , & V_61 ) ) ;
} while ( V_61 . V_66 );
return V_56 ;
}
static int F_236 ( struct V_2 * V_2 , struct V_314 * V_348 ,
struct V_385 * V_386 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_387 ,
struct V_1 * V_376 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_388 V_389 = {
. V_243 = F_95 ( V_2 ) ,
. V_390 = V_6 ,
. V_14 = V_14 ,
. V_240 = V_14 -> V_15 ,
. V_7 = V_387 ,
} ;
struct V_391 V_56 = {
. V_386 = V_386 ,
. V_7 = V_376 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_392 ] ,
. V_312 = & V_389 ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
unsigned long V_105 = V_152 ;
T_5 V_183 ;
bool V_393 ;
int V_304 ;
V_389 . V_240 = F_6 ( V_14 , V_387 ) ;
if ( V_387 )
V_389 . V_240 = F_6 ( V_14 , V_376 ) ;
F_84 ( V_386 ) ;
V_393 = ( V_6 -> V_245 & V_394 ) ? true : false ;
V_183 = V_393 ? V_185 : V_68 ;
if ( F_237 ( & V_389 . V_249 , V_2 , V_183 ) ) {
} else if ( V_393 && V_65 != NULL ) {
struct V_395 V_396 = {
. V_397 = V_57 -> V_398 ,
. V_399 = V_57 -> V_400 ,
} ;
if ( ! F_238 ( V_65 ) )
return - V_401 ;
if ( F_239 ( & V_389 . V_249 , V_65 , V_185 ,
& V_396 ) == - V_35 )
return - V_401 ;
} else
F_127 ( & V_389 . V_249 , & V_402 ) ;
V_304 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & V_389 . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_304 == 0 && V_65 != NULL )
F_38 ( V_14 , V_105 ) ;
return V_304 ;
}
static int F_229 ( struct V_2 * V_2 , struct V_314 * V_348 ,
struct V_385 * V_386 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_387 ,
struct V_1 * V_376 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_236 ( V_2 , V_348 , V_386 , V_6 , V_65 , V_387 , V_376 ) ;
F_240 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_67 :
if ( ! ( V_6 -> V_245 & V_394 ) ) {
F_241 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_62 -> V_96 ) ;
}
if ( V_65 && ! ( V_65 -> V_65 & V_185 ) ) {
V_8 = - V_401 ;
if ( V_6 -> V_245 & V_403 )
V_8 = - V_29 ;
goto V_129;
}
}
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static void F_242 ( void * V_156 )
{
struct V_404 * V_154 = V_156 ;
struct V_211 * V_212 = V_154 -> V_65 -> V_224 ;
struct V_251 * V_252 = V_154 -> V_65 -> V_2 -> V_405 ;
if ( V_154 -> V_406 )
F_243 ( V_154 -> V_65 -> V_2 ) ;
F_103 ( V_154 -> V_65 ) ;
F_102 ( V_154 -> V_389 . V_203 ) ;
F_104 ( V_212 ) ;
F_105 ( V_252 ) ;
F_98 ( V_154 ) ;
}
static void F_244 ( struct V_117 * V_118 , void * V_156 )
{
struct V_404 * V_154 = V_156 ;
struct V_64 * V_65 = V_154 -> V_65 ;
struct V_13 * V_14 = F_88 ( V_154 -> V_2 ) ;
T_8 * V_407 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_61 ( V_118 , & V_154 -> V_56 . V_159 ) )
return;
F_245 ( V_65 , & V_154 -> V_389 , & V_154 -> V_56 , V_118 -> V_147 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
V_407 = & V_154 -> V_56 . V_249 ;
if ( V_154 -> V_389 . V_183 == 0 && V_154 -> V_406 )
F_246 ( V_65 -> V_2 ,
V_154 -> V_408 ) ;
F_38 ( V_14 , V_154 -> V_105 ) ;
break;
case - V_71 :
case - V_74 :
case - V_92 :
case - V_72 :
case - V_73 :
if ( ! F_137 ( & V_154 -> V_389 . V_249 ,
& V_65 -> V_269 ) ) {
F_58 ( V_118 ) ;
goto V_409;
}
if ( V_154 -> V_389 . V_183 == 0 )
break;
default:
if ( F_247 ( V_118 , V_14 , V_65 , NULL ) == - V_128 ) {
F_58 ( V_118 ) ;
goto V_409;
}
}
F_128 ( V_65 , V_407 , V_154 -> V_389 . V_183 ) ;
V_409:
F_142 ( V_154 -> V_389 . V_203 ) ;
F_149 ( V_154 -> V_2 , V_154 -> V_56 . V_386 ) ;
F_8 ( L_30 , V_34 , V_118 -> V_147 ) ;
}
static void F_248 ( struct V_117 * V_118 , void * V_156 )
{
struct V_404 * V_154 = V_156 ;
struct V_64 * V_65 = V_154 -> V_65 ;
struct V_2 * V_2 = V_154 -> V_2 ;
bool V_410 , V_411 , V_412 ;
int V_413 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_182 ( V_154 -> V_389 . V_203 , V_118 ) != 0 )
goto V_320;
V_118 -> V_324 . V_309 = & V_310 [ V_414 ] ;
F_35 ( & V_65 -> V_224 -> V_274 ) ;
V_412 = F_32 ( V_261 , & V_65 -> V_213 ) ;
V_410 = F_32 ( V_257 , & V_65 -> V_213 ) ;
V_411 = F_32 ( V_259 , & V_65 -> V_213 ) ;
F_127 ( & V_154 -> V_389 . V_249 , & V_65 -> V_269 ) ;
V_154 -> V_389 . V_183 = 0 ;
if ( V_65 -> V_262 == 0 ) {
if ( V_65 -> V_258 == 0 )
V_413 |= V_410 ;
else if ( V_410 )
V_154 -> V_389 . V_183 |= V_68 ;
if ( V_65 -> V_260 == 0 )
V_413 |= V_411 ;
else if ( V_411 )
V_154 -> V_389 . V_183 |= V_185 ;
} else if ( V_412 )
V_154 -> V_389 . V_183 |= V_68 | V_185 ;
if ( V_154 -> V_389 . V_183 == 0 )
V_413 |= V_412 ;
if ( ! F_238 ( V_65 ) )
V_413 = 0 ;
F_37 ( & V_65 -> V_224 -> V_274 ) ;
if ( ! V_413 ) {
goto V_321;
}
if ( V_154 -> V_389 . V_183 == 0 ) {
V_118 -> V_324 . V_309 = & V_310 [ V_415 ] ;
if ( V_154 -> V_406 &&
F_249 ( V_2 , & V_154 -> V_408 , V_118 ) ) {
F_142 ( V_154 -> V_389 . V_203 ) ;
goto V_320;
}
}
V_154 -> V_389 . V_227 =
F_81 ( F_88 ( V_2 ) ,
V_154 -> V_389 . V_183 , 0 ) ;
F_84 ( V_154 -> V_56 . V_386 ) ;
V_154 -> V_105 = V_152 ;
if ( F_64 ( F_88 ( V_2 ) ,
& V_154 -> V_389 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) != 0 )
F_142 ( V_154 -> V_389 . V_203 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_321:
V_118 -> V_332 = NULL ;
V_320:
F_61 ( V_118 , & V_154 -> V_56 . V_159 ) ;
}
static bool F_250 ( struct V_2 * V_2 )
{
if ( ! F_251 ( V_2 ) )
return false ;
return F_252 ( V_2 ) ;
}
int F_253 ( struct V_64 * V_65 , T_6 V_215 , int V_416 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
struct V_404 * V_154 ;
struct V_211 * V_212 = V_65 -> V_224 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_415 ] ,
. V_314 = V_65 -> V_224 -> V_288 ,
} ;
struct V_162 V_315 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_417 ,
. V_317 = V_318 ,
. V_213 = V_319 ,
} ;
int V_304 = - V_124 ;
F_254 ( V_14 -> V_62 , V_418 ,
& V_315 . V_164 , & V_161 ) ;
V_154 = F_89 ( sizeof( * V_154 ) , V_215 ) ;
if ( V_154 == NULL )
goto V_129;
F_39 ( & V_154 -> V_389 . V_158 , & V_154 -> V_56 . V_159 , 1 ) ;
V_154 -> V_2 = V_65 -> V_2 ;
V_154 -> V_65 = V_65 ;
V_154 -> V_389 . V_243 = F_95 ( V_65 -> V_2 ) ;
V_218 = V_14 -> V_62 -> V_166 -> V_218 ;
V_154 -> V_389 . V_203 = V_218 ( & V_65 -> V_224 -> V_221 , V_215 ) ;
if ( F_44 ( V_154 -> V_389 . V_203 ) )
goto V_419;
V_154 -> V_389 . V_183 = 0 ;
V_154 -> V_389 . V_240 = V_14 -> V_420 ;
V_154 -> V_56 . V_386 = & V_154 -> V_386 ;
V_154 -> V_56 . V_203 = V_154 -> V_389 . V_203 ;
V_154 -> V_56 . V_14 = V_14 ;
V_154 -> V_406 = F_250 ( V_65 -> V_2 ) ;
F_91 ( V_154 -> V_2 -> V_405 ) ;
V_161 . V_312 = & V_154 -> V_389 ;
V_161 . V_313 = & V_154 -> V_56 ;
V_315 . V_168 = V_154 ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) )
return F_72 ( V_118 ) ;
V_304 = 0 ;
if ( V_416 )
V_304 = F_110 ( V_118 ) ;
F_73 ( V_118 ) ;
return V_304 ;
V_419:
F_98 ( V_154 ) ;
V_129:
F_103 ( V_65 ) ;
F_104 ( V_212 ) ;
return V_304 ;
}
static struct V_2 *
F_255 ( struct V_2 * V_3 , struct V_298 * V_299 ,
int V_226 , struct V_5 * V_421 , int * V_372 )
{
struct V_64 * V_65 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_299 -> V_4 , V_421 , & V_17 ) ;
V_65 = F_233 ( V_3 , V_299 , V_226 , V_421 , V_7 , V_372 ) ;
F_4 ( V_7 ) ;
if ( F_44 ( V_65 ) )
return F_256 ( V_65 ) ;
return V_65 -> V_2 ;
}
static void F_257 ( struct V_298 * V_299 , int V_422 )
{
if ( V_299 -> V_65 == NULL )
return;
if ( V_422 )
F_258 ( V_299 -> V_65 , V_299 -> V_254 ) ;
else
F_162 ( V_299 -> V_65 , V_299 -> V_254 ) ;
}
static int F_259 ( struct V_13 * V_14 , struct V_423 * V_424 )
{
struct V_425 args = {
. V_424 = V_424 ,
} ;
struct V_426 V_56 = {} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_427 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
int V_304 ;
V_304 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_304 == 0 ) {
switch ( V_14 -> V_62 -> V_428 ) {
case 0 :
V_56 . V_15 [ 1 ] &= V_429 ;
V_56 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_56 . V_15 [ 2 ] &= V_430 ;
break;
case 2 :
V_56 . V_15 [ 2 ] &= V_431 ;
}
memcpy ( V_14 -> V_15 , V_56 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_93 &= ~ ( V_432 | V_433 |
V_434 | V_435 |
V_436 | V_437 | V_438 |
V_439 | V_440 |
V_441 | V_442 |
V_9 ) ;
if ( V_56 . V_15 [ 0 ] & V_443 &&
V_56 . V_444 & V_445 )
V_14 -> V_93 |= V_432 ;
if ( V_56 . V_446 != 0 )
V_14 -> V_93 |= V_433 ;
if ( V_56 . V_447 != 0 )
V_14 -> V_93 |= V_434 ;
if ( V_56 . V_15 [ 0 ] & V_45 )
V_14 -> V_93 |= V_435 ;
if ( V_56 . V_15 [ 1 ] & V_448 )
V_14 -> V_93 |= V_436 ;
if ( V_56 . V_15 [ 1 ] & V_449 )
V_14 -> V_93 |= V_437 ;
if ( V_56 . V_15 [ 1 ] & V_450 )
V_14 -> V_93 |= V_438 ;
if ( V_56 . V_15 [ 1 ] & V_451 )
V_14 -> V_93 |= V_439 ;
if ( V_56 . V_15 [ 1 ] & V_363 )
V_14 -> V_93 |= V_440 ;
if ( V_56 . V_15 [ 1 ] & V_452 )
V_14 -> V_93 |= V_441 ;
if ( V_56 . V_15 [ 1 ] & V_366 )
V_14 -> V_93 |= V_442 ;
#ifdef F_260
if ( V_56 . V_15 [ 2 ] & V_453 )
V_14 -> V_93 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_56 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_453 ;
memcpy ( V_14 -> V_420 , V_56 . V_15 , sizeof( V_14 -> V_420 ) ) ;
V_14 -> V_420 [ 0 ] &= V_454 | V_455 ;
V_14 -> V_420 [ 1 ] &= V_452 | V_366 ;
V_14 -> V_420 [ 2 ] = 0 ;
V_14 -> V_444 = V_56 . V_444 ;
V_14 -> V_456 = V_56 . V_456 ;
}
return V_304 ;
}
int F_261 ( struct V_13 * V_14 , struct V_423 * V_424 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_259 ( V_14 , V_424 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_262 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_458 )
{
T_1 V_240 [ 3 ] ;
struct V_459 args = {
. V_240 = V_240 ,
} ;
struct V_460 V_56 = {
. V_14 = V_14 ,
. V_386 = V_458 -> V_386 ,
. V_243 = V_424 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_461 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
V_240 [ 0 ] = V_242 [ 0 ] ;
V_240 [ 1 ] = V_242 [ 1 ] ;
V_240 [ 2 ] = V_242 [ 2 ] & ~ V_453 ;
F_84 ( V_458 -> V_386 ) ;
return F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_263 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_458 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_262 ( V_14 , V_424 , V_458 ) ;
F_264 ( V_14 , V_424 , V_458 -> V_386 , V_8 ) ;
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
static int F_265 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_458 , T_4 V_99 )
{
struct V_462 V_463 = {
. V_464 = V_99 ,
} ;
struct V_465 * V_466 ;
int V_51 ;
V_466 = F_266 ( & V_463 , V_14 -> V_90 ) ;
if ( F_44 ( V_466 ) ) {
V_51 = - V_29 ;
goto V_129;
}
V_51 = F_263 ( V_14 , V_424 , V_458 ) ;
V_129:
return V_51 ;
}
static int F_267 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_458 )
{
static const T_4 V_467 [] = {
V_104 ,
V_103 ,
V_468 ,
V_469 ,
V_470 ,
} ;
int V_304 = - V_24 ;
T_9 V_471 ;
if ( V_14 -> V_472 . V_473 > 0 ) {
for ( V_471 = 0 ; V_471 < V_14 -> V_472 . V_473 ; V_471 ++ ) {
V_304 = F_265 ( V_14 , V_424 , V_458 ,
V_14 -> V_472 . V_474 [ V_471 ] ) ;
if ( V_304 == - V_22 || V_304 == - V_29 )
continue;
break;
}
} else {
for ( V_471 = 0 ; V_471 < F_268 ( V_467 ) ; V_471 ++ ) {
V_304 = F_265 ( V_14 , V_424 , V_458 ,
V_467 [ V_471 ] ) ;
if ( V_304 == - V_22 || V_304 == - V_29 )
continue;
break;
}
}
if ( V_304 == - V_29 )
V_304 = - V_24 ;
return V_304 ;
}
static int F_269 ( struct V_13 * V_14 ,
struct V_423 * V_424 , struct V_457 * V_458 )
{
int V_475 = V_14 -> V_62 -> V_428 ;
return V_476 [ V_475 ] -> F_270 ( V_14 , V_424 , V_458 ) ;
}
int F_271 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_458 ,
bool V_477 )
{
int V_304 = 0 ;
if ( ! V_477 )
V_304 = F_263 ( V_14 , V_424 , V_458 ) ;
if ( V_477 || V_304 == V_22 )
V_304 = F_269 ( V_14 , V_424 , V_458 ) ;
if ( V_304 == 0 )
V_304 = F_261 ( V_14 , V_424 ) ;
if ( V_304 == 0 )
V_304 = F_272 ( V_14 , V_424 , V_458 ) ;
return F_7 ( V_304 ) ;
}
static int F_273 ( struct V_13 * V_14 , struct V_423 * V_478 ,
struct V_457 * V_458 )
{
int error ;
struct V_385 * V_386 = V_458 -> V_386 ;
struct V_1 * V_7 = NULL ;
error = F_261 ( V_14 , V_478 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_90 ( V_14 , V_377 ) ;
if ( F_44 ( V_7 ) )
return F_72 ( V_7 ) ;
error = F_193 ( V_14 , V_478 , V_386 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_222;
}
if ( V_386 -> V_295 & V_479 &&
! F_274 ( & V_14 -> V_480 , & V_386 -> V_480 ) )
memcpy ( & V_14 -> V_480 , & V_386 -> V_480 , sizeof( V_14 -> V_480 ) ) ;
V_222:
F_97 ( V_7 ) ;
return error ;
}
static int F_275 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_481 * V_239 , struct V_385 * V_386 ,
struct V_423 * V_424 )
{
int V_304 = - V_124 ;
struct V_482 * V_482 = NULL ;
struct V_483 * V_484 = NULL ;
V_482 = F_276 ( V_377 ) ;
if ( V_482 == NULL )
goto V_129;
V_484 = F_277 ( sizeof( struct V_483 ) , V_377 ) ;
if ( V_484 == NULL )
goto V_129;
V_304 = F_278 ( V_90 , V_3 , V_239 , V_484 , V_482 ) ;
if ( V_304 != 0 )
goto V_129;
if ( F_274 ( & F_88 ( V_3 ) -> V_480 , & V_484 -> V_386 . V_480 ) ) {
F_8 ( L_34
L_35 , V_34 , V_239 -> V_239 ) ;
V_304 = - V_76 ;
goto V_129;
}
F_279 ( & V_484 -> V_386 ) ;
memcpy ( V_386 , & V_484 -> V_386 , sizeof( struct V_385 ) ) ;
memset ( V_424 , 0 , sizeof( struct V_423 ) ) ;
V_129:
if ( V_482 )
F_280 ( V_482 ) ;
F_98 ( V_484 ) ;
return V_304 ;
}
static int F_281 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_385 * V_386 , struct V_1 * V_7 )
{
struct V_485 args = {
. V_243 = V_424 ,
. V_240 = V_14 -> V_15 ,
} ;
struct V_486 V_56 = {
. V_386 = V_386 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_487 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
args . V_240 = F_6 ( V_14 , V_7 ) ;
F_84 ( V_386 ) ;
return F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_193 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_385 * V_386 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_281 ( V_14 , V_424 , V_386 , V_7 ) ;
F_282 ( V_14 , V_424 , V_386 , V_8 ) ;
V_8 = F_21 ( V_14 , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_283 ( struct V_4 * V_4 , struct V_385 * V_386 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_314 * V_348 = NULL ;
struct V_64 * V_65 = NULL ;
struct V_1 * V_7 = NULL ;
int V_304 ;
if ( F_284 ( V_2 ) &&
V_6 -> V_245 & V_394 &&
V_6 -> V_488 < F_285 ( V_2 ) )
F_286 ( V_2 ) ;
F_84 ( V_386 ) ;
if ( V_6 -> V_245 & V_403 )
V_6 -> V_245 &= ~ ( V_368 | V_489 ) ;
if ( ( V_6 -> V_245 & ~ ( V_490 | V_403 ) ) == 0 )
return 0 ;
if ( V_6 -> V_245 & V_490 ) {
struct V_298 * V_299 ;
V_299 = F_287 ( V_6 -> V_491 ) ;
if ( V_299 ) {
V_348 = V_299 -> V_348 ;
V_65 = V_299 -> V_65 ;
}
}
V_7 = F_90 ( F_88 ( V_2 ) , V_377 ) ;
if ( F_44 ( V_7 ) )
return F_72 ( V_7 ) ;
V_304 = F_229 ( V_2 , V_348 , V_386 , V_6 , V_65 , NULL , V_7 ) ;
if ( V_304 == 0 ) {
F_230 ( V_2 , V_6 , V_386 ) ;
F_231 ( V_2 , V_386 , V_7 ) ;
}
F_97 ( V_7 ) ;
return V_304 ;
}
static int F_288 ( struct V_54 * V_55 , struct V_2 * V_3 ,
const struct V_481 * V_239 , struct V_423 * V_424 ,
struct V_385 * V_386 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_88 ( V_3 ) ;
int V_304 ;
struct V_492 args = {
. V_240 = V_14 -> V_15 ,
. V_493 = F_95 ( V_3 ) ,
. V_239 = V_239 ,
} ;
struct V_460 V_56 = {
. V_14 = V_14 ,
. V_386 = V_386 ,
. V_7 = V_7 ,
. V_243 = V_424 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_494 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
args . V_240 = F_6 ( V_14 , V_7 ) ;
F_84 ( V_386 ) ;
F_8 ( L_36 , V_239 -> V_239 ) ;
V_304 = F_74 ( V_55 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
F_8 ( L_37 , V_304 ) ;
return V_304 ;
}
static void F_289 ( struct V_385 * V_386 )
{
V_386 -> V_295 |= V_333 | V_495 |
V_496 | V_497 ;
V_386 -> V_254 = V_338 | V_498 | V_499 ;
V_386 -> V_500 = 2 ;
}
static int F_290 ( struct V_54 * * V_55 , struct V_2 * V_3 ,
struct V_481 * V_239 , struct V_423 * V_424 ,
struct V_385 * V_386 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
struct V_54 * V_90 = * V_55 ;
int V_8 ;
do {
V_8 = F_288 ( V_90 , V_3 , V_239 , V_424 , V_386 , V_7 ) ;
F_291 ( V_3 , V_239 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_300 ;
goto V_129;
case - V_76 :
V_8 = F_275 ( V_90 , V_3 , V_239 , V_386 , V_424 ) ;
goto V_129;
case - V_22 :
V_8 = - V_24 ;
if ( V_90 != * V_55 )
goto V_129;
V_90 = F_292 ( V_90 , V_3 , V_239 ) ;
if ( F_44 ( V_90 ) )
return F_72 ( V_90 ) ;
V_61 . V_66 = 1 ;
break;
default:
V_8 = F_21 ( F_88 ( V_3 ) , V_8 , & V_61 ) ;
}
} while ( V_61 . V_66 );
V_129:
if ( V_8 == 0 )
* V_55 = V_90 ;
else if ( V_90 != * V_55 )
F_293 ( V_90 ) ;
return V_8 ;
}
static int F_294 ( struct V_2 * V_3 , struct V_481 * V_239 ,
struct V_423 * V_424 , struct V_385 * V_386 ,
struct V_1 * V_7 )
{
int V_304 ;
struct V_54 * V_90 = F_295 ( V_3 ) ;
V_304 = F_290 ( & V_90 , V_3 , V_239 , V_424 , V_386 , V_7 ) ;
if ( V_90 != F_295 ( V_3 ) ) {
F_293 ( V_90 ) ;
F_289 ( V_386 ) ;
}
return V_304 ;
}
struct V_54 *
F_296 ( struct V_2 * V_3 , struct V_481 * V_239 ,
struct V_423 * V_424 , struct V_385 * V_386 )
{
struct V_54 * V_90 = F_295 ( V_3 ) ;
int V_304 ;
V_304 = F_290 ( & V_90 , V_3 , V_239 , V_424 , V_386 , NULL ) ;
if ( V_304 < 0 )
return F_45 ( V_304 ) ;
return ( V_90 == F_295 ( V_3 ) ) ? F_297 ( V_90 ) : V_90 ;
}
static int F_298 ( struct V_2 * V_2 , struct V_349 * V_501 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_502 args = {
. V_243 = F_95 ( V_2 ) ,
. V_240 = V_14 -> V_420 ,
} ;
struct V_503 V_56 = {
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_504 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_501 -> V_348 ,
} ;
int V_254 = V_501 -> V_351 ;
int V_304 = 0 ;
if ( V_254 & V_356 )
args . V_208 |= V_229 ;
if ( F_299 ( V_2 -> V_505 ) ) {
if ( V_254 & V_506 )
args . V_208 |= V_230 | V_231 | V_507 ;
if ( V_254 & V_354 )
args . V_208 |= V_508 ;
} else {
if ( V_254 & V_506 )
args . V_208 |= V_230 | V_231 ;
if ( V_254 & V_354 )
args . V_208 |= V_232 ;
}
V_56 . V_386 = F_300 () ;
if ( V_56 . V_386 == NULL )
return - V_124 ;
V_304 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( ! V_304 ) {
F_190 ( V_501 , V_56 . V_208 ) ;
F_149 ( V_2 , V_56 . V_386 ) ;
}
F_301 ( V_56 . V_386 ) ;
return V_304 ;
}
static int F_302 ( struct V_2 * V_2 , struct V_349 * V_501 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_298 ( V_2 , V_501 ) ;
F_303 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_304 ( struct V_2 * V_2 , struct V_482 * V_482 ,
unsigned int V_48 , unsigned int V_509 )
{
struct V_510 args = {
. V_243 = F_95 ( V_2 ) ,
. V_48 = V_48 ,
. V_509 = V_509 ,
. V_42 = & V_482 ,
} ;
struct V_511 V_56 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_512 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
return F_74 ( F_88 ( V_2 ) -> V_90 , F_88 ( V_2 ) , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_305 ( struct V_2 * V_2 , struct V_482 * V_482 ,
unsigned int V_48 , unsigned int V_509 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_304 ( V_2 , V_482 , V_48 , V_509 ) ;
F_306 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_307 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_213 )
{
struct V_1 V_17 , * V_387 = NULL ;
struct V_298 * V_299 ;
struct V_64 * V_65 ;
int V_372 = 0 ;
int V_304 = 0 ;
V_299 = F_308 ( V_4 , V_68 ) ;
if ( F_44 ( V_299 ) )
return F_72 ( V_299 ) ;
V_387 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_309 () ;
V_65 = F_233 ( V_3 , V_299 , V_213 , V_6 , V_387 , & V_372 ) ;
if ( F_44 ( V_65 ) ) {
V_304 = F_72 ( V_65 ) ;
goto V_129;
}
V_129:
F_4 ( V_387 ) ;
F_169 ( V_299 ) ;
return V_304 ;
}
static int F_310 ( struct V_2 * V_3 , struct V_481 * V_239 )
{
struct V_13 * V_14 = F_88 ( V_3 ) ;
struct V_513 args = {
. V_243 = F_95 ( V_3 ) ,
. V_239 = * V_239 ,
} ;
struct V_514 V_56 = {
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_515 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
int V_304 ;
V_304 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_304 == 0 )
F_75 ( V_3 , & V_56 . V_170 ) ;
return V_304 ;
}
static int F_311 ( struct V_2 * V_3 , struct V_481 * V_239 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_310 ( V_3 , V_239 ) ;
F_312 ( V_3 , V_239 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_313 ( struct V_160 * V_161 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_88 ( V_3 ) ;
struct V_513 * args = V_161 -> V_312 ;
struct V_514 * V_56 = V_161 -> V_313 ;
V_56 -> V_14 = V_14 ;
V_161 -> V_309 = & V_310 [ V_515 ] ;
F_39 ( & args -> V_158 , & V_56 -> V_159 , 1 ) ;
F_84 ( V_56 -> V_516 ) ;
}
static void F_314 ( struct V_117 * V_118 , struct V_517 * V_156 )
{
F_64 ( F_88 ( V_156 -> V_3 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_315 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_517 * V_156 = V_118 -> V_518 ;
struct V_514 * V_56 = & V_156 -> V_56 ;
if ( ! F_61 ( V_118 , & V_56 -> V_159 ) )
return 0 ;
if ( F_247 ( V_118 , V_56 -> V_14 , NULL ,
& V_156 -> V_50 ) == - V_128 )
return 0 ;
F_75 ( V_3 , & V_56 -> V_170 ) ;
return 1 ;
}
static void F_316 ( struct V_160 * V_161 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_88 ( V_3 ) ;
struct V_519 * V_389 = V_161 -> V_312 ;
struct V_520 * V_56 = V_161 -> V_313 ;
V_161 -> V_309 = & V_310 [ V_521 ] ;
V_56 -> V_14 = V_14 ;
F_39 ( & V_389 -> V_158 , & V_56 -> V_159 , 1 ) ;
}
static void F_317 ( struct V_117 * V_118 , struct V_522 * V_156 )
{
F_64 ( F_88 ( V_156 -> V_523 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_318 ( struct V_117 * V_118 , struct V_2 * V_523 ,
struct V_2 * V_524 )
{
struct V_522 * V_156 = V_118 -> V_518 ;
struct V_520 * V_56 = & V_156 -> V_56 ;
if ( ! F_61 ( V_118 , & V_56 -> V_159 ) )
return 0 ;
if ( F_247 ( V_118 , V_56 -> V_14 , NULL , & V_156 -> V_50 ) == - V_128 )
return 0 ;
F_75 ( V_523 , & V_56 -> V_525 ) ;
F_75 ( V_524 , & V_56 -> V_526 ) ;
return 1 ;
}
static int F_319 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_481 * V_239 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_527 V_389 = {
. V_243 = F_95 ( V_2 ) ,
. V_493 = F_95 ( V_3 ) ,
. V_239 = V_239 ,
. V_240 = V_14 -> V_15 ,
} ;
struct V_528 V_56 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_529 ] ,
. V_312 = & V_389 ,
. V_313 = & V_56 ,
} ;
int V_304 = - V_124 ;
V_56 . V_386 = F_300 () ;
if ( V_56 . V_386 == NULL )
goto V_129;
V_56 . V_7 = F_90 ( V_14 , V_377 ) ;
if ( F_44 ( V_56 . V_7 ) ) {
V_304 = F_72 ( V_56 . V_7 ) ;
goto V_129;
}
V_389 . V_240 = F_6 ( V_14 , V_56 . V_7 ) ;
V_304 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & V_389 . V_158 , & V_56 . V_159 , 1 ) ;
if ( ! V_304 ) {
F_75 ( V_3 , & V_56 . V_170 ) ;
V_304 = F_320 ( V_2 , V_56 . V_386 ) ;
if ( ! V_304 )
F_231 ( V_2 , V_56 . V_386 , V_56 . V_7 ) ;
}
F_97 ( V_56 . V_7 ) ;
V_129:
F_301 ( V_56 . V_386 ) ;
return V_304 ;
}
static int F_321 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_481 * V_239 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( F_88 ( V_2 ) ,
F_319 ( V_2 , V_3 , V_239 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static struct V_530 * F_322 ( struct V_2 * V_3 ,
struct V_481 * V_239 , struct V_5 * V_6 , T_1 V_531 )
{
struct V_530 * V_156 ;
V_156 = F_89 ( sizeof( * V_156 ) , V_377 ) ;
if ( V_156 != NULL ) {
struct V_13 * V_14 = F_88 ( V_3 ) ;
V_156 -> V_7 = F_90 ( V_14 , V_377 ) ;
if ( F_44 ( V_156 -> V_7 ) )
goto V_308;
V_156 -> V_161 . V_309 = & V_310 [ V_532 ] ;
V_156 -> V_161 . V_312 = & V_156 -> V_389 ;
V_156 -> V_161 . V_313 = & V_156 -> V_56 ;
V_156 -> V_389 . V_493 = F_95 ( V_3 ) ;
V_156 -> V_389 . V_14 = V_14 ;
V_156 -> V_389 . V_239 = V_239 ;
V_156 -> V_389 . V_214 = V_6 ;
V_156 -> V_389 . V_531 = V_531 ;
V_156 -> V_389 . V_240 = F_6 ( V_14 , V_156 -> V_7 ) ;
V_156 -> V_56 . V_14 = V_14 ;
V_156 -> V_56 . V_243 = & V_156 -> V_243 ;
V_156 -> V_56 . V_386 = & V_156 -> V_386 ;
V_156 -> V_56 . V_7 = V_156 -> V_7 ;
F_84 ( V_156 -> V_56 . V_386 ) ;
}
return V_156 ;
V_308:
F_98 ( V_156 ) ;
return NULL ;
}
static int F_323 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_530 * V_156 )
{
int V_304 = F_74 ( F_88 ( V_3 ) -> V_90 , F_88 ( V_3 ) , & V_156 -> V_161 ,
& V_156 -> V_389 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
if ( V_304 == 0 ) {
F_75 ( V_3 , & V_156 -> V_56 . V_533 ) ;
V_304 = F_324 ( V_4 , V_156 -> V_56 . V_243 , V_156 -> V_56 . V_386 , V_156 -> V_56 . V_7 ) ;
}
return V_304 ;
}
static void F_325 ( struct V_530 * V_156 )
{
F_97 ( V_156 -> V_7 ) ;
F_98 ( V_156 ) ;
}
static int F_326 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_482 * V_482 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_530 * V_156 ;
int V_304 = - V_534 ;
if ( V_12 > V_535 )
goto V_129;
V_304 = - V_124 ;
V_156 = F_322 ( V_3 , & V_4 -> V_11 , V_6 , V_536 ) ;
if ( V_156 == NULL )
goto V_129;
V_156 -> V_161 . V_309 = & V_310 [ V_537 ] ;
V_156 -> V_389 . V_247 . V_538 . V_42 = & V_482 ;
V_156 -> V_389 . V_247 . V_538 . V_12 = V_12 ;
V_156 -> V_389 . V_7 = V_7 ;
V_304 = F_323 ( V_3 , V_4 , V_156 ) ;
F_325 ( V_156 ) ;
V_129:
return V_304 ;
}
static int F_327 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_482 * V_482 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_326 ( V_3 , V_4 , V_482 , V_12 , V_6 , V_7 ) ;
F_328 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_329 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_530 * V_156 ;
int V_304 = - V_124 ;
V_156 = F_322 ( V_3 , & V_4 -> V_11 , V_6 , V_539 ) ;
if ( V_156 == NULL )
goto V_129;
V_156 -> V_389 . V_7 = V_7 ;
V_304 = F_323 ( V_3 , V_4 , V_156 ) ;
F_325 ( V_156 ) ;
V_129:
return V_304 ;
}
static int F_330 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_309 () ;
do {
V_8 = F_329 ( V_3 , V_4 , V_6 , V_7 ) ;
F_331 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_332 ( struct V_4 * V_4 , struct V_314 * V_348 ,
T_2 V_36 , struct V_482 * * V_42 , unsigned int V_49 , int V_540 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_243 = F_95 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_240 = F_88 ( F_14 ( V_4 ) ) -> V_15 ,
. V_540 = V_540 ,
} ;
struct V_541 V_56 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_542 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
int V_304 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_76 ( V_3 ) -> V_543 , V_4 , & args ) ;
V_56 . V_48 = args . V_48 ;
V_304 = F_74 ( F_88 ( V_3 ) -> V_90 , F_88 ( V_3 ) , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_304 >= 0 ) {
memcpy ( F_76 ( V_3 ) -> V_543 , V_56 . V_37 . V_156 , V_544 ) ;
V_304 += args . V_48 ;
}
F_333 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_304 ) ;
return V_304 ;
}
static int F_334 ( struct V_4 * V_4 , struct V_314 * V_348 ,
T_2 V_36 , struct V_482 * * V_42 , unsigned int V_49 , int V_540 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_332 ( V_4 , V_348 , V_36 ,
V_42 , V_49 , V_540 ) ;
F_335 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_21 ( F_88 ( F_14 ( V_4 ) ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_336 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_545 )
{
struct V_530 * V_156 ;
int V_254 = V_6 -> V_10 ;
int V_304 = - V_124 ;
V_156 = F_322 ( V_3 , & V_4 -> V_11 , V_6 , V_546 ) ;
if ( V_156 == NULL )
goto V_129;
if ( F_337 ( V_254 ) )
V_156 -> V_389 . V_531 = V_547 ;
else if ( F_338 ( V_254 ) ) {
V_156 -> V_389 . V_531 = V_548 ;
V_156 -> V_389 . V_247 . V_549 . V_550 = F_339 ( V_545 ) ;
V_156 -> V_389 . V_247 . V_549 . V_551 = F_340 ( V_545 ) ;
}
else if ( F_341 ( V_254 ) ) {
V_156 -> V_389 . V_531 = V_552 ;
V_156 -> V_389 . V_247 . V_549 . V_550 = F_339 ( V_545 ) ;
V_156 -> V_389 . V_247 . V_549 . V_551 = F_340 ( V_545 ) ;
} else if ( ! F_342 ( V_254 ) ) {
V_304 = - V_27 ;
goto V_308;
}
V_156 -> V_389 . V_7 = V_7 ;
V_304 = F_323 ( V_3 , V_4 , V_156 ) ;
V_308:
F_325 ( V_156 ) ;
V_129:
return V_304 ;
}
static int F_343 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_545 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_309 () ;
do {
V_8 = F_336 ( V_3 , V_4 , V_6 , V_7 , V_545 ) ;
F_344 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_345 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_553 * V_554 )
{
struct V_555 args = {
. V_243 = V_424 ,
. V_240 = V_14 -> V_15 ,
} ;
struct V_556 V_56 = {
. V_554 = V_554 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_557 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
F_84 ( V_554 -> V_386 ) ;
return F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_346 ( struct V_13 * V_14 , struct V_423 * V_424 , struct V_553 * V_554 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_345 ( V_14 , V_424 , V_554 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_347 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_558 )
{
struct V_559 args = {
. V_243 = V_424 ,
. V_240 = V_14 -> V_15 ,
} ;
struct V_560 V_56 = {
. V_558 = V_558 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_561 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
return F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_272 ( struct V_13 * V_14 , struct V_423 * V_424 , struct V_457 * V_558 )
{
struct V_60 V_61 = { } ;
unsigned long V_562 = V_152 ;
int V_8 ;
do {
V_8 = F_347 ( V_14 , V_424 , V_558 ) ;
F_348 ( V_14 , V_424 , V_558 -> V_386 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_62 * V_63 = V_14 -> V_62 ;
F_35 ( & V_63 -> V_106 ) ;
V_63 -> V_563 = V_558 -> V_564 * V_87 ;
V_63 -> V_107 = V_562 ;
F_37 ( & V_63 -> V_106 ) ;
break;
}
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_349 ( struct V_13 * V_14 , struct V_423 * V_424 , struct V_457 * V_558 )
{
int error ;
F_84 ( V_558 -> V_386 ) ;
error = F_272 ( V_14 , V_424 , V_558 ) ;
if ( error == 0 ) {
V_14 -> V_565 = V_558 -> V_566 ;
F_350 ( V_14 , V_424 , V_558 -> V_567 ) ;
}
return error ;
}
static int F_351 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_568 * V_569 )
{
struct V_570 args = {
. V_243 = V_424 ,
. V_240 = V_14 -> V_15 ,
} ;
struct V_571 V_56 = {
. V_569 = V_569 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_572 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
if ( ( args . V_240 [ 0 ] & V_573 [ 0 ] ) == 0 ) {
memset ( V_569 , 0 , sizeof( * V_569 ) ) ;
return 0 ;
}
F_84 ( V_569 -> V_386 ) ;
return F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
}
static int F_352 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_568 * V_569 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_351 ( V_14 , V_424 , V_569 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
int F_353 ( T_8 * V_249 ,
const struct V_298 * V_299 ,
const struct V_574 * V_575 ,
T_5 V_183 )
{
const struct V_395 * V_396 = NULL ;
if ( V_575 != NULL )
V_396 = & V_575 -> V_396 ;
return F_239 ( V_249 , V_299 -> V_65 , V_183 , V_396 ) ;
}
static bool F_354 ( T_8 * V_249 ,
const struct V_298 * V_299 ,
const struct V_574 * V_575 ,
T_5 V_183 )
{
T_8 V_576 ;
if ( F_353 ( & V_576 , V_299 , V_575 , V_183 ) == - V_35 )
return true ;
return F_137 ( V_249 , & V_576 ) ;
}
static bool F_355 ( int V_8 )
{
switch ( V_8 ) {
case - V_70 :
case - V_71 :
case - V_72 :
case - V_74 :
case - V_92 :
case - V_67 :
case - V_73 :
return true ;
}
return false ;
}
void F_356 ( struct V_577 * V_578 )
{
F_333 ( V_578 -> V_2 ) ;
}
static int F_357 ( struct V_117 * V_118 , struct V_577 * V_578 )
{
struct V_13 * V_14 = F_88 ( V_578 -> V_2 ) ;
F_358 ( V_578 , V_118 -> V_147 ) ;
if ( F_247 ( V_118 , V_14 ,
V_578 -> args . V_579 -> V_65 ,
NULL ) == - V_128 ) {
F_58 ( V_118 ) ;
return - V_128 ;
}
F_356 ( V_578 ) ;
if ( V_118 -> V_147 > 0 )
F_38 ( V_14 , V_578 -> V_105 ) ;
return 0 ;
}
static bool F_359 ( struct V_117 * V_118 ,
struct V_580 * args )
{
if ( ! F_355 ( V_118 -> V_147 ) ||
F_354 ( & args -> V_249 ,
args -> V_579 ,
args -> V_581 ,
V_68 ) )
return false ;
F_58 ( V_118 ) ;
return true ;
}
static int F_360 ( struct V_117 * V_118 , struct V_577 * V_578 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_61 ( V_118 , & V_578 -> V_56 . V_159 ) )
return - V_128 ;
if ( F_359 ( V_118 , & V_578 -> args ) )
return - V_128 ;
return V_578 -> V_582 ? V_578 -> V_582 ( V_118 , V_578 ) :
F_357 ( V_118 , V_578 ) ;
}
static void F_361 ( struct V_577 * V_578 ,
struct V_160 * V_161 )
{
V_578 -> V_105 = V_152 ;
V_578 -> V_582 = F_357 ;
V_161 -> V_309 = & V_310 [ V_583 ] ;
F_39 ( & V_578 -> args . V_158 , & V_578 -> V_56 . V_159 , 0 ) ;
}
static int F_362 ( struct V_117 * V_118 ,
struct V_577 * V_578 )
{
if ( F_64 ( F_88 ( V_578 -> V_2 ) ,
& V_578 -> args . V_158 ,
& V_578 -> V_56 . V_159 ,
V_118 ) )
return 0 ;
if ( F_353 ( & V_578 -> args . V_249 , V_578 -> args . V_579 ,
V_578 -> args . V_581 ,
V_578 -> V_584 -> V_585 ) == - V_35 )
return - V_35 ;
if ( F_363 ( F_32 ( V_586 , & V_578 -> args . V_579 -> V_213 ) ) )
return - V_35 ;
return 0 ;
}
static int F_364 ( struct V_117 * V_118 ,
struct V_577 * V_578 )
{
struct V_2 * V_2 = V_578 -> V_2 ;
F_365 ( V_578 , V_118 -> V_147 ) ;
if ( F_247 ( V_118 , F_88 ( V_2 ) ,
V_578 -> args . V_579 -> V_65 ,
NULL ) == - V_128 ) {
F_58 ( V_118 ) ;
return - V_128 ;
}
if ( V_118 -> V_147 >= 0 ) {
F_38 ( F_88 ( V_2 ) , V_578 -> V_105 ) ;
F_366 ( V_578 ) ;
}
return 0 ;
}
static bool F_367 ( struct V_117 * V_118 ,
struct V_580 * args )
{
if ( ! F_355 ( V_118 -> V_147 ) ||
F_354 ( & args -> V_249 ,
args -> V_579 ,
args -> V_581 ,
V_185 ) )
return false ;
F_58 ( V_118 ) ;
return true ;
}
static int F_368 ( struct V_117 * V_118 , struct V_577 * V_578 )
{
if ( ! F_61 ( V_118 , & V_578 -> V_56 . V_159 ) )
return - V_128 ;
if ( F_367 ( V_118 , & V_578 -> args ) )
return - V_128 ;
return V_578 -> V_582 ? V_578 -> V_582 ( V_118 , V_578 ) :
F_364 ( V_118 , V_578 ) ;
}
static
bool F_369 ( struct V_577 * V_578 )
{
if ( V_578 -> V_587 != NULL || V_578 -> V_588 != NULL )
return false ;
return F_22 ( V_578 -> V_2 , V_68 ) == 0 ;
}
static void F_370 ( struct V_577 * V_578 ,
struct V_160 * V_161 )
{
struct V_13 * V_14 = F_88 ( V_578 -> V_2 ) ;
if ( ! F_369 ( V_578 ) ) {
V_578 -> args . V_240 = NULL ;
V_578 -> V_56 . V_386 = NULL ;
} else
V_578 -> args . V_240 = V_14 -> V_420 ;
if ( ! V_578 -> V_582 )
V_578 -> V_582 = F_364 ;
V_578 -> V_56 . V_14 = V_14 ;
V_578 -> V_105 = V_152 ;
V_161 -> V_309 = & V_310 [ V_589 ] ;
F_39 ( & V_578 -> args . V_158 , & V_578 -> V_56 . V_159 , 1 ) ;
}
static void F_371 ( struct V_117 * V_118 , struct V_590 * V_156 )
{
F_64 ( F_88 ( V_156 -> V_2 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_372 ( struct V_117 * V_118 , struct V_590 * V_156 )
{
struct V_2 * V_2 = V_156 -> V_2 ;
F_373 ( V_156 , V_118 -> V_147 ) ;
if ( F_247 ( V_118 , F_88 ( V_2 ) ,
NULL , NULL ) == - V_128 ) {
F_58 ( V_118 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_374 ( struct V_117 * V_118 , struct V_590 * V_156 )
{
if ( ! F_61 ( V_118 , & V_156 -> V_56 . V_159 ) )
return - V_128 ;
return V_156 -> V_591 ( V_118 , V_156 ) ;
}
static void F_375 ( struct V_590 * V_156 , struct V_160 * V_161 )
{
struct V_13 * V_14 = F_88 ( V_156 -> V_2 ) ;
if ( V_156 -> V_591 == NULL )
V_156 -> V_591 = F_372 ;
V_156 -> V_56 . V_14 = V_14 ;
V_161 -> V_309 = & V_310 [ V_592 ] ;
F_39 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
}
static void F_376 ( void * V_154 )
{
struct V_593 * V_156 = V_154 ;
struct V_62 * V_63 = V_156 -> V_90 ;
if ( F_377 ( & V_63 -> V_594 ) > 1 )
F_378 ( V_63 ) ;
F_379 ( V_63 ) ;
F_98 ( V_156 ) ;
}
static void F_380 ( struct V_117 * V_118 , void * V_154 )
{
struct V_593 * V_156 = V_154 ;
struct V_62 * V_63 = V_156 -> V_90 ;
unsigned long V_105 = V_156 -> V_105 ;
F_381 ( V_63 , V_118 -> V_147 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
break;
case - V_77 :
F_27 ( V_63 ) ;
break;
default:
if ( F_32 ( V_595 , & V_63 -> V_596 ) == 0 )
return;
if ( V_118 -> V_147 != V_597 ) {
F_25 ( V_63 ) ;
return;
}
F_382 ( V_63 ) ;
}
F_34 ( V_63 , V_105 ) ;
}
static int F_383 ( struct V_62 * V_63 , struct V_314 * V_348 , unsigned V_598 )
{
struct V_160 V_161 = {
. V_309 = & V_310 [ V_599 ] ,
. V_312 = V_63 ,
. V_314 = V_348 ,
} ;
struct V_593 * V_156 ;
if ( V_598 == 0 )
return 0 ;
if ( ! F_384 ( & V_63 -> V_594 ) )
return - V_35 ;
V_156 = F_277 ( sizeof( * V_156 ) , V_301 ) ;
if ( V_156 == NULL )
return - V_124 ;
V_156 -> V_90 = V_63 ;
V_156 -> V_105 = V_152 ;
return F_385 ( V_63 -> V_100 , & V_161 , V_600 ,
& V_601 , V_156 ) ;
}
static int F_386 ( struct V_62 * V_63 , struct V_314 * V_348 )
{
struct V_160 V_161 = {
. V_309 = & V_310 [ V_599 ] ,
. V_312 = V_63 ,
. V_314 = V_348 ,
} ;
unsigned long V_562 = V_152 ;
int V_304 ;
V_304 = F_387 ( V_63 -> V_100 , & V_161 , V_600 ) ;
if ( V_304 < 0 )
return V_304 ;
F_34 ( V_63 , V_562 ) ;
return 0 ;
}
static inline int F_388 ( struct V_13 * V_14 )
{
return V_14 -> V_93 & V_432 ;
}
static int F_389 ( const void * V_602 , T_9 V_603 ,
struct V_482 * * V_42 , unsigned int * V_48 )
{
struct V_482 * V_604 , * * V_605 ;
int V_606 = 0 ;
T_9 V_12 ;
V_605 = V_42 ;
do {
V_12 = F_390 ( T_9 , V_607 , V_603 ) ;
V_604 = F_276 ( V_377 ) ;
if ( V_604 == NULL )
goto V_608;
memcpy ( F_391 ( V_604 ) , V_602 , V_12 ) ;
V_602 += V_12 ;
V_603 -= V_12 ;
* V_42 ++ = V_604 ;
V_606 ++ ;
} while ( V_603 != 0 );
return V_606 ;
V_608:
for(; V_606 > 0 ; V_606 -- )
F_280 ( V_605 [ V_606 - 1 ] ) ;
return - V_124 ;
}
static void F_392 ( struct V_2 * V_2 , struct V_609 * V_610 )
{
struct V_171 * V_172 = F_76 ( V_2 ) ;
F_35 ( & V_2 -> V_173 ) ;
F_98 ( V_172 -> V_611 ) ;
V_172 -> V_611 = V_610 ;
F_37 ( & V_2 -> V_173 ) ;
}
static void F_393 ( struct V_2 * V_2 )
{
F_392 ( V_2 , NULL ) ;
}
static inline T_11 F_394 ( struct V_2 * V_2 , char * V_602 , T_9 V_603 )
{
struct V_171 * V_172 = F_76 ( V_2 ) ;
struct V_609 * V_610 ;
int V_51 = - V_300 ;
F_35 ( & V_2 -> V_173 ) ;
V_610 = V_172 -> V_611 ;
if ( V_610 == NULL )
goto V_129;
if ( V_602 == NULL )
goto V_612;
if ( V_610 -> V_613 == 0 )
goto V_129;
V_51 = - V_614 ;
if ( V_610 -> V_12 > V_603 )
goto V_129;
memcpy ( V_602 , V_610 -> V_156 , V_610 -> V_12 ) ;
V_612:
V_51 = V_610 -> V_12 ;
V_129:
F_37 ( & V_2 -> V_173 ) ;
return V_51 ;
}
static void F_395 ( struct V_2 * V_2 , struct V_482 * * V_42 , T_9 V_48 , T_9 V_615 )
{
struct V_609 * V_610 ;
T_9 V_603 = sizeof( * V_610 ) + V_615 ;
if ( V_603 <= V_607 ) {
V_610 = F_277 ( V_603 , V_377 ) ;
if ( V_610 == NULL )
goto V_129;
V_610 -> V_613 = 1 ;
F_396 ( V_610 -> V_156 , V_42 , V_48 , V_615 ) ;
} else {
V_610 = F_277 ( sizeof( * V_610 ) , V_377 ) ;
if ( V_610 == NULL )
goto V_129;
V_610 -> V_613 = 0 ;
}
V_610 -> V_12 = V_615 ;
V_129:
F_392 ( V_2 , V_610 ) ;
}
static T_11 F_397 ( struct V_2 * V_2 , void * V_602 , T_9 V_603 )
{
struct V_482 * V_42 [ V_616 ] = { NULL , } ;
struct V_617 args = {
. V_243 = F_95 ( V_2 ) ,
. V_618 = V_42 ,
. V_615 = V_603 ,
} ;
struct V_619 V_56 = {
. V_615 = V_603 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_620 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
unsigned int V_621 = F_398 ( V_603 , V_607 ) ;
int V_51 = - V_124 , V_471 ;
if ( V_621 == 0 )
V_621 = 1 ;
if ( V_621 > F_268 ( V_42 ) )
return - V_614 ;
for ( V_471 = 0 ; V_471 < V_621 ; V_471 ++ ) {
V_42 [ V_471 ] = F_276 ( V_377 ) ;
if ( ! V_42 [ V_471 ] )
goto V_308;
}
V_56 . V_622 = F_276 ( V_377 ) ;
if ( ! V_56 . V_622 )
goto V_308;
args . V_615 = V_621 * V_607 ;
args . V_623 = 0 ;
F_8 ( L_40 ,
V_34 , V_602 , V_603 , V_621 , args . V_615 ) ;
V_51 = F_74 ( F_88 ( V_2 ) -> V_90 , F_88 ( V_2 ) ,
& V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_51 )
goto V_308;
if ( V_56 . V_624 & V_625 ) {
if ( V_602 == NULL )
goto V_626;
V_51 = - V_614 ;
goto V_308;
}
F_395 ( V_2 , V_42 , V_56 . V_627 , V_56 . V_615 ) ;
if ( V_602 ) {
if ( V_56 . V_615 > V_603 ) {
V_51 = - V_614 ;
goto V_308;
}
F_396 ( V_602 , V_42 , V_56 . V_627 , V_56 . V_615 ) ;
}
V_626:
V_51 = V_56 . V_615 ;
V_308:
for ( V_471 = 0 ; V_471 < V_621 ; V_471 ++ )
if ( V_42 [ V_471 ] )
F_280 ( V_42 [ V_471 ] ) ;
if ( V_56 . V_622 )
F_280 ( V_56 . V_622 ) ;
return V_51 ;
}
static T_11 F_399 ( struct V_2 * V_2 , void * V_602 , T_9 V_603 )
{
struct V_60 V_61 = { } ;
T_11 V_51 ;
do {
V_51 = F_397 ( V_2 , V_602 , V_603 ) ;
F_400 ( V_2 , V_51 ) ;
if ( V_51 >= 0 )
break;
V_51 = F_21 ( F_88 ( V_2 ) , V_51 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_51 ;
}
static T_11 F_401 ( struct V_2 * V_2 , void * V_602 , T_9 V_603 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
int V_51 ;
if ( ! F_388 ( V_14 ) )
return - V_628 ;
V_51 = F_402 ( V_14 , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_76 ( V_2 ) -> V_174 & V_629 )
F_403 ( V_2 ) ;
V_51 = F_394 ( V_2 , V_602 , V_603 ) ;
if ( V_51 != - V_300 )
return V_51 ;
return F_399 ( V_2 , V_602 , V_603 ) ;
}
static int F_404 ( struct V_2 * V_2 , const void * V_602 , T_9 V_603 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_482 * V_42 [ V_616 ] ;
struct V_630 V_389 = {
. V_243 = F_95 ( V_2 ) ,
. V_618 = V_42 ,
. V_615 = V_603 ,
} ;
struct V_631 V_56 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_632 ] ,
. V_312 = & V_389 ,
. V_313 = & V_56 ,
} ;
unsigned int V_621 = F_398 ( V_603 , V_607 ) ;
int V_51 , V_471 ;
if ( ! F_388 ( V_14 ) )
return - V_628 ;
if ( V_621 > F_268 ( V_42 ) )
return - V_614 ;
V_471 = F_389 ( V_602 , V_603 , V_389 . V_618 , & V_389 . V_623 ) ;
if ( V_471 < 0 )
return V_471 ;
F_23 ( V_2 ) ;
V_51 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & V_389 . V_158 , & V_56 . V_159 , 1 ) ;
for (; V_471 > 0 ; V_471 -- )
F_405 ( V_42 [ V_471 - 1 ] ) ;
F_35 ( & V_2 -> V_173 ) ;
F_76 ( V_2 ) -> V_174 |= V_175 ;
F_37 ( & V_2 -> V_173 ) ;
F_406 ( V_2 ) ;
F_403 ( V_2 ) ;
return V_51 ;
}
static int F_407 ( struct V_2 * V_2 , const void * V_602 , T_9 V_603 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_404 ( V_2 , V_602 , V_603 ) ;
F_408 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_409 ( struct V_2 * V_2 , void * V_602 ,
T_9 V_603 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_385 V_386 ;
struct V_1 V_7 = { 0 , 0 , V_603 , V_602 } ;
T_1 V_240 [ 3 ] = { 0 , 0 , V_453 } ;
struct V_485 V_389 = {
. V_243 = F_95 ( V_2 ) ,
. V_240 = V_240 ,
} ;
struct V_486 V_56 = {
. V_386 = & V_386 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_487 ] ,
. V_312 = & V_389 ,
. V_313 = & V_56 ,
} ;
int V_51 ;
F_84 ( & V_386 ) ;
V_51 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & V_389 . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( V_386 . V_295 & V_633 ) )
return - V_300 ;
if ( V_603 < V_7 . V_12 )
return - V_614 ;
return 0 ;
}
static int F_410 ( struct V_2 * V_2 , void * V_602 ,
T_9 V_603 )
{
struct V_60 V_61 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_628 ;
do {
V_8 = F_409 ( V_2 , V_602 , V_603 ) ;
F_411 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_412 ( struct V_2 * V_2 ,
struct V_1 * V_387 ,
struct V_385 * V_386 ,
struct V_1 * V_376 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_88 ( V_2 ) ;
const T_1 V_240 [ 3 ] = { 0 , 0 , V_453 } ;
struct V_388 V_389 = {
. V_243 = F_95 ( V_2 ) ,
. V_390 = & V_6 ,
. V_14 = V_14 ,
. V_240 = V_240 ,
. V_7 = V_387 ,
} ;
struct V_391 V_56 = {
. V_386 = V_386 ,
. V_7 = V_376 ,
. V_14 = V_14 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_392 ] ,
. V_312 = & V_389 ,
. V_313 = & V_56 ,
} ;
int V_304 ;
F_127 ( & V_389 . V_249 , & V_402 ) ;
V_304 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & V_389 . V_158 , & V_56 . V_159 , 1 ) ;
if ( V_304 )
F_8 ( L_41 , V_34 , V_304 ) ;
return V_304 ;
}
static int F_413 ( struct V_2 * V_2 ,
struct V_1 * V_387 ,
struct V_385 * V_386 ,
struct V_1 * V_376 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_412 ( V_2 , V_387 ,
V_386 , V_376 ) ;
F_414 ( V_2 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_415 ( struct V_4 * V_4 , const void * V_602 , T_9 V_603 )
{
struct V_1 V_387 , * V_376 = NULL ;
struct V_385 V_386 ;
struct V_314 * V_348 ;
struct V_2 * V_2 = F_14 ( V_4 ) ;
int V_304 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_628 ;
F_84 ( & V_386 ) ;
V_387 . V_634 = 0 ;
V_387 . V_635 = 0 ;
V_387 . V_7 = ( char * ) V_602 ;
V_387 . V_12 = V_603 ;
V_348 = F_416 () ;
if ( F_44 ( V_348 ) )
return F_72 ( V_348 ) ;
V_376 = F_90 ( F_88 ( V_2 ) , V_377 ) ;
if ( F_44 ( V_376 ) ) {
V_304 = - F_72 ( V_376 ) ;
goto V_129;
}
V_304 = F_413 ( V_2 , & V_387 , & V_386 , V_376 ) ;
if ( V_304 == 0 )
F_231 ( V_2 , & V_386 , V_376 ) ;
F_97 ( V_376 ) ;
V_129:
F_211 ( V_348 ) ;
return V_304 ;
}
static int
F_247 ( struct V_117 * V_118 , const struct V_13 * V_14 ,
struct V_64 * V_65 , long * V_50 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
if ( V_118 -> V_147 >= 0 )
return 0 ;
switch( V_118 -> V_147 ) {
case - V_70 :
case - V_71 :
case - V_72 :
case - V_67 :
if ( V_65 == NULL )
break;
if ( F_24 ( V_14 , V_65 ) < 0 )
goto V_636;
goto V_69;
case - V_73 :
if ( V_65 != NULL ) {
if ( F_24 ( V_14 , V_65 ) < 0 )
goto V_636;
}
case - V_74 :
case - V_75 :
F_25 ( V_63 ) ;
goto V_69;
case - V_76 :
if ( F_26 ( V_14 ) < 0 )
goto V_636;
goto V_69;
case - V_77 :
F_27 ( V_63 ) ;
goto V_69;
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
goto V_69;
#endif
case - V_89 :
F_417 ( V_14 , V_637 ) ;
F_60 ( V_118 , F_16 ( V_50 ) ) ;
goto V_638;
case - V_88 :
F_60 ( V_118 , V_52 ) ;
case - V_91 :
case - V_92 :
goto V_638;
}
V_118 -> V_147 = F_7 ( V_118 -> V_147 ) ;
return 0 ;
V_636:
V_118 -> V_147 = - V_35 ;
return 0 ;
V_69:
F_48 ( & V_63 -> V_639 , V_118 , NULL ) ;
if ( F_32 ( V_640 , & V_63 -> V_641 ) == 0 )
F_418 ( & V_63 -> V_639 , V_118 ) ;
if ( F_32 ( V_97 , & V_14 -> V_98 ) )
goto V_636;
V_638:
V_118 -> V_147 = 0 ;
return - V_128 ;
}
static void F_419 ( const struct V_62 * V_63 ,
T_12 * V_642 )
{
T_3 V_246 [ 2 ] ;
if ( F_32 ( V_643 , & V_63 -> V_641 ) ) {
V_246 [ 0 ] = 0 ;
V_246 [ 1 ] = F_420 ( V_644 + 1 ) ;
} else {
struct V_645 * V_646 = F_421 ( V_63 -> V_647 , V_648 ) ;
V_246 [ 0 ] = F_420 ( V_646 -> V_649 . V_650 ) ;
V_246 [ 1 ] = F_420 ( V_646 -> V_649 . V_651 ) ;
}
memcpy ( V_642 -> V_156 , V_246 , sizeof( V_642 -> V_156 ) ) ;
}
static unsigned int
F_422 ( struct V_62 * V_63 ,
char * V_602 , T_9 V_12 )
{
unsigned int V_652 ;
if ( V_63 -> V_653 != NULL )
return F_423 ( V_602 , V_63 -> V_653 , V_12 ) ;
F_135 () ;
V_652 = F_424 ( V_602 , V_12 , L_43 ,
V_63 -> V_654 ,
F_425 ( V_63 -> V_100 ,
V_655 ) ,
F_425 ( V_63 -> V_100 ,
V_656 ) ) ;
F_138 () ;
V_63 -> V_653 = F_426 ( V_602 , V_377 ) ;
return V_652 ;
}
static unsigned int
F_427 ( struct V_62 * V_63 ,
char * V_602 , T_9 V_12 )
{
const char * V_657 = V_63 -> V_100 -> V_658 ;
unsigned int V_652 ;
if ( V_63 -> V_653 != NULL )
return F_423 ( V_602 , V_63 -> V_653 , V_12 ) ;
if ( V_659 [ 0 ] != '\0' )
V_652 = F_424 ( V_602 , V_12 , L_44 ,
V_63 -> V_660 -> V_661 ,
V_63 -> V_428 ,
V_659 ,
V_657 ) ;
else
V_652 = F_424 ( V_602 , V_12 , L_45 ,
V_63 -> V_660 -> V_661 , V_63 -> V_428 ,
V_657 ) ;
V_63 -> V_653 = F_426 ( V_602 , V_377 ) ;
return V_652 ;
}
static unsigned int
F_428 ( const struct V_62 * V_63 , char * V_602 , T_9 V_12 )
{
if ( strchr ( V_63 -> V_654 , ':' ) != NULL )
return F_424 ( V_602 , V_12 , L_46 ) ;
else
return F_424 ( V_602 , V_12 , L_47 ) ;
}
static void F_429 ( struct V_117 * V_118 , void * V_154 )
{
struct V_662 * V_663 = V_154 ;
if ( V_118 -> V_147 == 0 )
V_663 -> V_664 = F_207 ( V_118 -> V_665 -> V_666 ) ;
}
int F_430 ( struct V_62 * V_63 , T_1 V_667 ,
unsigned short V_668 , struct V_314 * V_348 ,
struct V_669 * V_56 )
{
T_12 V_670 ;
struct V_662 V_671 = {
. V_670 = & V_670 ,
. V_672 = V_667 ,
. V_673 = V_63 -> V_674 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_675 ] ,
. V_312 = & V_671 ,
. V_313 = V_56 ,
. V_314 = V_348 ,
} ;
struct V_117 * V_118 ;
struct V_162 V_315 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_676 ,
. V_168 = & V_671 ,
. V_213 = V_600 ,
} ;
int V_304 ;
F_419 ( V_63 , & V_670 ) ;
if ( F_32 ( V_677 , & V_63 -> V_678 ) )
V_671 . V_679 =
F_427 ( V_63 ,
V_671 . V_680 ,
sizeof( V_671 . V_680 ) ) ;
else
V_671 . V_679 =
F_422 ( V_63 ,
V_671 . V_680 ,
sizeof( V_671 . V_680 ) ) ;
V_671 . V_681 =
F_428 ( V_63 ,
V_671 . V_682 ,
sizeof( V_671 . V_682 ) ) ;
V_671 . V_683 = F_424 ( V_671 . V_684 ,
sizeof( V_671 . V_684 ) , L_48 ,
V_63 -> V_654 , V_668 >> 8 , V_668 & 255 ) ;
F_8 ( L_49 ,
V_63 -> V_100 -> V_101 -> V_685 -> V_686 ,
V_671 . V_679 , V_671 . V_680 ) ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) ) {
V_304 = F_72 ( V_118 ) ;
goto V_129;
}
V_304 = V_118 -> V_147 ;
if ( V_671 . V_664 ) {
V_63 -> V_687 = F_431 ( V_671 . V_664 ) ;
F_211 ( V_671 . V_664 ) ;
}
F_73 ( V_118 ) ;
V_129:
F_432 ( V_63 , V_304 ) ;
F_8 ( L_50 , V_304 ) ;
return V_304 ;
}
int F_433 ( struct V_62 * V_63 ,
struct V_669 * V_389 ,
struct V_314 * V_348 )
{
struct V_160 V_161 = {
. V_309 = & V_310 [ V_688 ] ,
. V_312 = V_389 ,
. V_314 = V_348 ,
} ;
int V_304 ;
F_8 ( L_51 ,
V_63 -> V_100 -> V_101 -> V_685 -> V_686 ,
V_63 -> V_234 ) ;
V_304 = F_387 ( V_63 -> V_100 , & V_161 , V_600 ) ;
F_434 ( V_63 , V_304 ) ;
F_8 ( L_52 , V_304 ) ;
return V_304 ;
}
static void F_435 ( struct V_117 * V_118 , void * V_154 )
{
struct V_689 * V_156 = V_154 ;
if ( ! F_61 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
F_436 ( & V_156 -> args , & V_156 -> V_56 , V_118 -> V_147 ) ;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( V_156 -> V_56 . V_14 , V_156 -> V_105 ) ;
case - V_71 :
case - V_70 :
case - V_72 :
case - V_92 :
case - V_74 :
case - V_73 :
V_118 -> V_147 = 0 ;
if ( V_156 -> V_406 )
F_246 ( V_156 -> V_2 , V_156 -> V_408 ) ;
break;
default:
if ( F_247 ( V_118 , V_156 -> V_56 . V_14 ,
NULL , NULL ) == - V_128 ) {
F_58 ( V_118 ) ;
return;
}
}
V_156 -> V_292 = V_118 -> V_147 ;
}
static void F_437 ( void * V_154 )
{
struct V_689 * V_156 = V_154 ;
struct V_2 * V_2 = V_156 -> V_2 ;
if ( V_2 ) {
if ( V_156 -> V_406 )
F_243 ( V_2 ) ;
F_438 ( V_2 ) ;
}
F_98 ( V_154 ) ;
}
static void F_439 ( struct V_117 * V_118 , void * V_156 )
{
struct V_689 * V_690 ;
V_690 = (struct V_689 * ) V_156 ;
if ( V_690 -> V_406 &&
F_249 ( V_690 -> V_2 , & V_690 -> V_408 , V_118 ) )
return;
F_64 ( V_690 -> V_56 . V_14 ,
& V_690 -> args . V_158 ,
& V_690 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_440 ( struct V_2 * V_2 , struct V_314 * V_348 , const T_8 * V_249 , int V_691 )
{
struct V_689 * V_156 ;
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_692 ] ,
. V_314 = V_348 ,
} ;
struct V_162 V_315 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_693 ,
. V_213 = V_319 ,
} ;
int V_304 = 0 ;
V_156 = F_89 ( sizeof( * V_156 ) , V_301 ) ;
if ( V_156 == NULL )
return - V_124 ;
F_39 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_156 -> args . V_424 = & V_156 -> V_243 ;
V_156 -> args . V_249 = & V_156 -> V_249 ;
V_156 -> args . V_240 = V_14 -> V_420 ;
F_183 ( & V_156 -> V_243 , F_95 ( V_2 ) ) ;
F_127 ( & V_156 -> V_249 , V_249 ) ;
V_156 -> V_56 . V_386 = & V_156 -> V_386 ;
V_156 -> V_56 . V_14 = V_14 ;
F_84 ( V_156 -> V_56 . V_386 ) ;
V_156 -> V_105 = V_152 ;
V_156 -> V_292 = 0 ;
V_156 -> V_2 = F_441 ( V_2 ) ;
if ( V_156 -> V_2 )
V_156 -> V_406 = F_250 ( V_2 ) ;
V_315 . V_168 = V_156 ;
V_161 . V_312 = & V_156 -> args ;
V_161 . V_313 = & V_156 -> V_56 ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) )
return F_72 ( V_118 ) ;
if ( ! V_691 )
goto V_129;
V_304 = F_109 ( V_118 ) ;
if ( V_304 != 0 )
goto V_129;
V_304 = V_156 -> V_292 ;
if ( V_304 == 0 )
F_442 ( V_2 , & V_156 -> V_386 ) ;
else
F_149 ( V_2 , & V_156 -> V_386 ) ;
V_129:
F_73 ( V_118 ) ;
return V_304 ;
}
int F_443 ( struct V_2 * V_2 , struct V_314 * V_348 , const T_8 * V_249 , int V_691 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_440 ( V_2 , V_348 , V_249 , V_691 ) ;
F_444 ( V_2 , V_8 ) ;
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
F_445 ( unsigned long V_50 )
{
F_19 ( V_50 ) ;
V_50 <<= 1 ;
if ( V_50 > V_694 )
return V_694 ;
return V_50 ;
}
static int F_446 ( struct V_64 * V_65 , int V_695 , struct V_696 * V_697 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_698 V_389 = {
. V_243 = F_95 ( V_2 ) ,
. V_699 = V_697 ,
} ;
struct V_700 V_56 = {
. V_701 = V_697 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_702 ] ,
. V_312 = & V_389 ,
. V_313 = & V_56 ,
. V_314 = V_65 -> V_224 -> V_288 ,
} ;
struct V_279 * V_280 ;
int V_304 ;
V_389 . V_703 . V_233 = V_63 -> V_234 ;
V_304 = F_447 ( V_65 , V_697 ) ;
if ( V_304 != 0 )
goto V_129;
V_280 = V_697 -> V_704 . V_705 . V_224 ;
V_389 . V_703 . V_235 = V_280 -> V_706 . V_238 ;
V_389 . V_703 . V_707 = V_14 -> V_707 ;
V_304 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & V_389 . V_158 , & V_56 . V_159 , 1 ) ;
switch ( V_304 ) {
case 0 :
V_697 -> V_708 = V_709 ;
break;
case - V_306 :
V_304 = 0 ;
}
V_697 -> V_710 -> V_711 ( V_697 ) ;
V_697 -> V_710 = NULL ;
V_129:
return V_304 ;
}
static int F_448 ( struct V_64 * V_65 , int V_695 , struct V_696 * V_697 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_446 ( V_65 , V_695 , V_697 ) ;
F_449 ( V_697 , V_65 , V_695 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_65 -> V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_450 ( struct V_712 * V_712 , struct V_696 * V_699 )
{
int V_56 = 0 ;
switch ( V_699 -> V_713 & ( V_714 | V_715 ) ) {
case V_714 :
V_56 = F_451 ( V_712 , V_699 ) ;
break;
case V_715 :
V_56 = F_452 ( V_712 , V_699 ) ;
break;
default:
F_453 () ;
}
return V_56 ;
}
static struct V_716 * F_454 ( struct V_696 * V_699 ,
struct V_298 * V_299 ,
struct V_279 * V_280 ,
struct V_217 * V_203 )
{
struct V_716 * V_41 ;
struct V_2 * V_2 = V_280 -> V_281 -> V_2 ;
V_41 = F_89 ( sizeof( * V_41 ) , V_301 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_389 . V_243 = F_95 ( V_2 ) ;
V_41 -> V_389 . V_699 = & V_41 -> V_699 ;
V_41 -> V_389 . V_203 = V_203 ;
V_41 -> V_56 . V_203 = V_203 ;
V_41 -> V_280 = V_280 ;
F_93 ( & V_280 -> V_717 ) ;
V_41 -> V_299 = F_157 ( V_299 ) ;
memcpy ( & V_41 -> V_699 , V_699 , sizeof( V_41 -> V_699 ) ) ;
V_41 -> V_14 = F_88 ( V_2 ) ;
return V_41 ;
}
static void F_455 ( void * V_156 )
{
struct V_716 * V_154 = V_156 ;
F_102 ( V_154 -> V_389 . V_203 ) ;
F_456 ( V_154 -> V_280 ) ;
F_169 ( V_154 -> V_299 ) ;
F_98 ( V_154 ) ;
}
static void F_457 ( struct V_117 * V_118 , void * V_156 )
{
struct V_716 * V_154 = V_156 ;
if ( ! F_61 ( V_118 , & V_154 -> V_56 . V_159 ) )
return;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( V_154 -> V_14 , V_154 -> V_105 ) ;
F_450 ( V_154 -> V_699 . V_718 , & V_154 -> V_699 ) ;
if ( F_139 ( V_154 -> V_280 ,
& V_154 -> V_56 . V_249 ) )
break;
case - V_72 :
case - V_92 :
case - V_74 :
case - V_73 :
if ( ! F_137 ( & V_154 -> V_389 . V_249 ,
& V_154 -> V_280 -> V_283 ) )
F_58 ( V_118 ) ;
break;
default:
if ( F_247 ( V_118 , V_154 -> V_14 ,
NULL , NULL ) == - V_128 )
F_58 ( V_118 ) ;
}
F_142 ( V_154 -> V_389 . V_203 ) ;
}
static void F_458 ( struct V_117 * V_118 , void * V_156 )
{
struct V_716 * V_154 = V_156 ;
if ( F_182 ( V_154 -> V_389 . V_203 , V_118 ) != 0 )
goto V_320;
F_127 ( & V_154 -> V_389 . V_249 , & V_154 -> V_280 -> V_283 ) ;
if ( F_32 ( V_719 , & V_154 -> V_280 -> V_720 ) == 0 ) {
goto V_321;
}
V_154 -> V_105 = V_152 ;
if ( F_64 ( V_154 -> V_14 ,
& V_154 -> V_389 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) != 0 )
F_142 ( V_154 -> V_389 . V_203 ) ;
return;
V_321:
V_118 -> V_332 = NULL ;
V_320:
F_61 ( V_118 , & V_154 -> V_56 . V_159 ) ;
}
static struct V_117 * F_459 ( struct V_696 * V_699 ,
struct V_298 * V_299 ,
struct V_279 * V_280 ,
struct V_217 * V_203 )
{
struct V_716 * V_156 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_721 ] ,
. V_314 = V_299 -> V_348 ,
} ;
struct V_162 V_315 = {
. V_164 = F_295 ( V_280 -> V_281 -> V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_722 ,
. V_317 = V_318 ,
. V_213 = V_319 ,
} ;
F_254 ( F_88 ( V_280 -> V_281 -> V_2 ) -> V_62 ,
V_418 , & V_315 . V_164 , & V_161 ) ;
V_699 -> V_708 = V_709 ;
V_156 = F_454 ( V_699 , V_299 , V_280 , V_203 ) ;
if ( V_156 == NULL ) {
F_102 ( V_203 ) ;
return F_45 ( - V_124 ) ;
}
F_39 ( & V_156 -> V_389 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_161 . V_312 = & V_156 -> V_389 ;
V_161 . V_313 = & V_156 -> V_56 ;
V_315 . V_168 = V_156 ;
return F_71 ( & V_315 ) ;
}
static int F_460 ( struct V_64 * V_65 , int V_695 , struct V_696 * V_697 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_211 * V_212 = V_65 -> V_224 ;
struct V_171 * V_172 = F_76 ( V_2 ) ;
struct V_217 * V_203 ;
struct V_279 * V_280 ;
struct V_117 * V_118 ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
int V_304 = 0 ;
unsigned char V_713 = V_697 -> V_713 ;
V_304 = F_447 ( V_65 , V_697 ) ;
V_697 -> V_713 |= V_723 ;
F_461 ( & V_212 -> V_724 ) ;
F_462 ( & V_172 -> V_725 ) ;
if ( F_450 ( V_697 -> V_718 , V_697 ) == - V_300 ) {
F_463 ( & V_172 -> V_725 ) ;
F_464 ( & V_212 -> V_724 ) ;
goto V_129;
}
F_463 ( & V_172 -> V_725 ) ;
F_464 ( & V_212 -> V_724 ) ;
if ( V_304 != 0 )
goto V_129;
V_280 = V_697 -> V_704 . V_705 . V_224 ;
if ( F_32 ( V_719 , & V_280 -> V_720 ) == 0 )
goto V_129;
V_218 = F_88 ( V_2 ) -> V_62 -> V_166 -> V_218 ;
V_203 = V_218 ( & V_280 -> V_706 , V_377 ) ;
V_304 = - V_124 ;
if ( F_44 ( V_203 ) )
goto V_129;
V_118 = F_459 ( V_697 , F_287 ( V_697 -> V_718 ) , V_280 , V_203 ) ;
V_304 = F_72 ( V_118 ) ;
if ( F_44 ( V_118 ) )
goto V_129;
V_304 = F_109 ( V_118 ) ;
F_73 ( V_118 ) ;
V_129:
V_697 -> V_713 = V_713 ;
F_465 ( V_697 , V_65 , V_726 , V_304 ) ;
return V_304 ;
}
static struct V_727 * F_466 ( struct V_696 * V_699 ,
struct V_298 * V_299 , struct V_279 * V_280 ,
T_6 V_215 )
{
struct V_727 * V_41 ;
struct V_2 * V_2 = V_280 -> V_281 -> V_2 ;
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_217 * ( * V_218 ) ( struct V_219 * , T_6 ) ;
V_41 = F_89 ( sizeof( * V_41 ) , V_215 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_389 . V_243 = F_95 ( V_2 ) ;
V_41 -> V_389 . V_699 = & V_41 -> V_699 ;
V_41 -> V_389 . V_728 = F_467 ( & V_280 -> V_281 -> V_224 -> V_221 , V_215 ) ;
if ( F_44 ( V_41 -> V_389 . V_728 ) )
goto V_308;
V_218 = V_14 -> V_62 -> V_166 -> V_218 ;
V_41 -> V_389 . V_729 = V_218 ( & V_280 -> V_706 , V_215 ) ;
if ( F_44 ( V_41 -> V_389 . V_729 ) )
goto V_730;
V_41 -> V_389 . V_703 . V_233 = V_14 -> V_62 -> V_234 ;
V_41 -> V_389 . V_703 . V_235 = V_280 -> V_706 . V_238 ;
V_41 -> V_389 . V_703 . V_707 = V_14 -> V_707 ;
V_41 -> V_56 . V_729 = V_41 -> V_389 . V_729 ;
V_41 -> V_280 = V_280 ;
V_41 -> V_14 = V_14 ;
F_93 ( & V_280 -> V_717 ) ;
V_41 -> V_299 = F_157 ( V_299 ) ;
F_468 ( V_699 -> V_718 ) ;
memcpy ( & V_41 -> V_699 , V_699 , sizeof( V_41 -> V_699 ) ) ;
return V_41 ;
V_730:
F_102 ( V_41 -> V_389 . V_728 ) ;
V_308:
F_98 ( V_41 ) ;
return NULL ;
}
static void F_469 ( struct V_117 * V_118 , void * V_154 )
{
struct V_727 * V_156 = V_154 ;
struct V_64 * V_65 = V_156 -> V_280 -> V_281 ;
F_8 ( L_29 , V_34 ) ;
if ( F_182 ( V_156 -> V_389 . V_729 , V_118 ) != 0 )
goto V_320;
if ( ! F_32 ( V_719 , & V_156 -> V_280 -> V_720 ) ) {
if ( F_182 ( V_156 -> V_389 . V_728 , V_118 ) != 0 ) {
goto V_731;
}
F_127 ( & V_156 -> V_389 . V_269 ,
& V_65 -> V_269 ) ;
V_156 -> V_389 . V_732 = 1 ;
V_156 -> V_56 . V_728 = V_156 -> V_389 . V_728 ;
} else {
V_156 -> V_389 . V_732 = 0 ;
F_127 ( & V_156 -> V_389 . V_733 ,
& V_156 -> V_280 -> V_283 ) ;
}
if ( ! F_238 ( V_65 ) ) {
V_156 -> V_292 = - V_401 ;
V_118 -> V_332 = NULL ;
goto V_734;
}
V_156 -> V_105 = V_152 ;
if ( F_64 ( V_156 -> V_14 ,
& V_156 -> V_389 . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) == 0 )
return;
V_734:
F_142 ( V_156 -> V_389 . V_728 ) ;
V_731:
F_142 ( V_156 -> V_389 . V_729 ) ;
V_320:
F_61 ( V_118 , & V_156 -> V_56 . V_159 ) ;
F_8 ( L_53 , V_34 , V_156 -> V_292 ) ;
}
static void F_470 ( struct V_117 * V_118 , void * V_154 )
{
struct V_727 * V_156 = V_154 ;
struct V_279 * V_280 = V_156 -> V_280 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_61 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
V_156 -> V_292 = V_118 -> V_147 ;
switch ( V_118 -> V_147 ) {
case 0 :
F_38 ( F_88 ( F_14 ( V_156 -> V_299 -> V_4 ) ) ,
V_156 -> V_105 ) ;
if ( V_156 -> V_389 . V_735 ) {
V_156 -> V_699 . V_713 &= ~ ( V_736 | V_737 ) ;
if ( F_450 ( V_156 -> V_699 . V_718 , & V_156 -> V_699 ) < 0 ) {
F_58 ( V_118 ) ;
break;
}
}
if ( V_156 -> V_389 . V_732 != 0 ) {
F_176 ( & V_280 -> V_706 , 0 ) ;
F_127 ( & V_280 -> V_283 , & V_156 -> V_56 . V_249 ) ;
F_124 ( V_719 , & V_280 -> V_720 ) ;
} else if ( ! F_139 ( V_280 , & V_156 -> V_56 . V_249 ) )
F_58 ( V_118 ) ;
break;
case - V_72 :
case - V_92 :
case - V_74 :
case - V_73 :
if ( V_156 -> V_389 . V_732 != 0 ) {
if ( ! F_137 ( & V_156 -> V_389 . V_269 ,
& V_280 -> V_281 -> V_269 ) )
F_58 ( V_118 ) ;
} else if ( ! F_137 ( & V_156 -> V_389 . V_733 ,
& V_280 -> V_283 ) )
F_58 ( V_118 ) ;
}
F_8 ( L_30 , V_34 , V_156 -> V_292 ) ;
}
static void F_471 ( void * V_154 )
{
struct V_727 * V_156 = V_154 ;
F_8 ( L_29 , V_34 ) ;
F_102 ( V_156 -> V_389 . V_728 ) ;
if ( V_156 -> V_307 != 0 ) {
struct V_117 * V_118 ;
V_118 = F_459 ( & V_156 -> V_699 , V_156 -> V_299 , V_156 -> V_280 ,
V_156 -> V_389 . V_729 ) ;
if ( ! F_44 ( V_118 ) )
F_472 ( V_118 ) ;
F_8 ( L_54 , V_34 ) ;
} else
F_102 ( V_156 -> V_389 . V_729 ) ;
F_456 ( V_156 -> V_280 ) ;
F_169 ( V_156 -> V_299 ) ;
F_473 ( V_156 -> V_699 . V_718 ) ;
F_98 ( V_156 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_474 ( struct V_13 * V_14 , struct V_279 * V_280 , int V_732 , int error )
{
switch ( error ) {
case - V_71 :
case - V_72 :
V_280 -> V_706 . V_213 &= ~ V_738 ;
if ( V_732 != 0 ||
F_32 ( V_719 , & V_280 -> V_720 ) != 0 )
F_24 ( V_14 , V_280 -> V_281 ) ;
break;
case - V_74 :
V_280 -> V_706 . V_213 &= ~ V_738 ;
case - V_73 :
F_25 ( V_14 -> V_62 ) ;
} ;
}
static int F_475 ( struct V_64 * V_65 , int V_695 , struct V_696 * V_699 , int V_739 )
{
struct V_727 * V_156 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_740 ] ,
. V_314 = V_65 -> V_224 -> V_288 ,
} ;
struct V_162 V_315 = {
. V_164 = F_295 ( V_65 -> V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_741 ,
. V_317 = V_318 ,
. V_213 = V_319 ,
} ;
int V_51 ;
F_8 ( L_29 , V_34 ) ;
V_156 = F_466 ( V_699 , F_287 ( V_699 -> V_718 ) ,
V_699 -> V_704 . V_705 . V_224 ,
V_739 == V_742 ? V_377 : V_301 ) ;
if ( V_156 == NULL )
return - V_124 ;
if ( F_476 ( V_695 ) )
V_156 -> V_389 . V_743 = 1 ;
F_39 ( & V_156 -> V_389 . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_161 . V_312 = & V_156 -> V_389 ;
V_161 . V_313 = & V_156 -> V_56 ;
V_315 . V_168 = V_156 ;
if ( V_739 > V_742 ) {
if ( V_739 == V_744 )
V_156 -> V_389 . V_745 = V_744 ;
F_40 ( & V_156 -> V_389 . V_158 ) ;
} else
V_156 -> V_389 . V_735 = 1 ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) )
return F_72 ( V_118 ) ;
V_51 = F_109 ( V_118 ) ;
if ( V_51 == 0 ) {
V_51 = V_156 -> V_292 ;
if ( V_51 )
F_474 ( V_156 -> V_14 , V_156 -> V_280 ,
V_156 -> V_389 . V_732 , V_51 ) ;
} else
V_156 -> V_307 = 1 ;
F_73 ( V_118 ) ;
F_8 ( L_30 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_477 ( struct V_64 * V_65 , struct V_696 * V_697 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_32 ( V_270 , & V_65 -> V_213 ) != 0 )
return 0 ;
V_8 = F_475 ( V_65 , V_726 , V_697 , V_744 ) ;
F_478 ( V_697 , V_65 , V_726 , V_8 ) ;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_479 ( struct V_64 * V_65 , struct V_696 * V_697 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
V_8 = F_447 ( V_65 , V_697 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_746 ) {
F_124 ( V_747 , & V_697 -> V_704 . V_705 . V_224 -> V_720 ) ;
return 0 ;
}
do {
if ( F_32 ( V_270 , & V_65 -> V_213 ) != 0 )
return 0 ;
V_8 = F_475 ( V_65 , V_726 , V_697 , V_748 ) ;
F_480 ( V_697 , V_65 , V_726 , V_8 ) ;
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
static int F_481 ( struct V_64 * V_65 )
{
int V_304 , V_51 = - V_72 ;
struct V_279 * V_280 ;
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
F_156 (lsp, &state->lock_states, ls_locks) {
if ( F_32 ( V_719 , & V_280 -> V_720 ) ) {
struct V_314 * V_348 = V_280 -> V_281 -> V_224 -> V_288 ;
V_304 = F_208 ( V_14 ,
& V_280 -> V_283 ,
V_348 ) ;
F_482 ( V_65 , V_280 , V_304 ) ;
if ( V_304 != V_361 ) {
if ( V_304 != - V_72 )
F_210 ( V_14 ,
& V_280 -> V_283 ,
V_348 ) ;
F_126 ( V_719 , & V_280 -> V_720 ) ;
V_51 = V_304 ;
}
}
} ;
return V_51 ;
}
static int F_483 ( struct V_64 * V_65 , struct V_696 * V_697 )
{
int V_304 = V_361 ;
if ( F_32 ( V_749 , & V_65 -> V_213 ) )
V_304 = F_481 ( V_65 ) ;
if ( V_304 != V_361 )
V_304 = F_479 ( V_65 , V_697 ) ;
return V_304 ;
}
static int F_484 ( struct V_64 * V_65 , int V_695 , struct V_696 * V_697 )
{
struct V_171 * V_172 = F_76 ( V_65 -> V_2 ) ;
unsigned char V_713 = V_697 -> V_713 ;
int V_304 = - V_750 ;
if ( ( V_713 & V_714 ) &&
! F_32 ( V_371 , & V_65 -> V_213 ) )
goto V_129;
V_304 = F_447 ( V_65 , V_697 ) ;
if ( V_304 != 0 )
goto V_129;
V_697 -> V_713 |= V_737 ;
V_304 = F_450 ( V_697 -> V_718 , V_697 ) ;
if ( V_304 < 0 )
goto V_129;
F_462 ( & V_172 -> V_725 ) ;
if ( F_32 ( V_270 , & V_65 -> V_213 ) ) {
V_697 -> V_713 = V_713 & ~ V_736 ;
V_304 = F_450 ( V_697 -> V_718 , V_697 ) ;
F_463 ( & V_172 -> V_725 ) ;
goto V_129;
}
F_463 ( & V_172 -> V_725 ) ;
V_304 = F_475 ( V_65 , V_695 , V_697 , V_742 ) ;
V_129:
V_697 -> V_713 = V_713 ;
return V_304 ;
}
static int F_485 ( struct V_64 * V_65 , int V_695 , struct V_696 * V_697 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_484 ( V_65 , V_695 , V_697 ) ;
F_486 ( V_697 , V_65 , V_695 , V_8 ) ;
if ( V_8 == - V_306 )
V_8 = - V_128 ;
V_8 = F_21 ( F_88 ( V_65 -> V_2 ) ,
V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int
F_487 ( struct V_712 * V_751 , int V_695 , struct V_696 * V_697 )
{
struct V_298 * V_299 ;
struct V_64 * V_65 ;
unsigned long V_50 = V_752 ;
int V_304 ;
V_299 = F_287 ( V_751 ) ;
V_65 = V_299 -> V_65 ;
if ( V_697 -> V_753 < 0 || V_697 -> V_754 < 0 )
return - V_27 ;
if ( F_488 ( V_695 ) ) {
if ( V_65 != NULL )
return F_448 ( V_65 , V_755 , V_697 ) ;
return 0 ;
}
if ( ! ( F_489 ( V_695 ) || F_476 ( V_695 ) ) )
return - V_27 ;
if ( V_697 -> V_708 == V_709 ) {
if ( V_65 != NULL )
return F_460 ( V_65 , V_695 , V_697 ) ;
return 0 ;
}
if ( V_65 == NULL )
return - V_750 ;
switch ( V_697 -> V_708 ) {
case V_756 :
if ( ! ( V_751 -> V_757 & V_68 ) )
return - V_401 ;
break;
case V_758 :
if ( ! ( V_751 -> V_757 & V_185 ) )
return - V_401 ;
}
do {
V_304 = F_485 ( V_65 , V_695 , V_697 ) ;
if ( ( V_304 != - V_128 ) || F_489 ( V_695 ) )
break;
V_50 = F_445 ( V_50 ) ;
V_304 = - V_58 ;
if ( F_490 () )
break;
} while( V_304 < 0 );
return V_304 ;
}
int F_491 ( struct V_696 * V_699 , struct V_64 * V_65 , const T_8 * V_249 )
{
struct V_13 * V_14 = F_88 ( V_65 -> V_2 ) ;
int V_8 ;
V_8 = F_447 ( V_65 , V_699 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_475 ( V_65 , V_726 , V_699 , V_742 ) ;
return F_170 ( V_14 , V_65 , V_249 , V_8 ) ;
}
static void F_492 ( struct V_117 * V_118 , void * V_154 )
{
struct V_759 * V_156 = V_154 ;
struct V_13 * V_14 = V_156 -> V_14 ;
F_41 ( V_14 -> V_62 -> V_153 ,
& V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , V_118 ) ;
V_156 -> args . V_703 . V_233 = V_14 -> V_62 -> V_234 ;
V_156 -> V_105 = V_152 ;
}
static void F_493 ( struct V_117 * V_118 , void * V_154 )
{
struct V_759 * V_156 = V_154 ;
struct V_13 * V_14 = V_156 -> V_14 ;
F_49 ( V_118 , & V_156 -> V_56 . V_159 ) ;
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
if ( F_247 ( V_118 , V_14 ,
NULL , NULL ) == - V_128 )
F_58 ( V_118 ) ;
}
}
static void F_494 ( void * V_154 )
{
struct V_759 * V_156 = V_154 ;
F_495 ( V_156 -> V_14 , V_156 -> V_280 ) ;
F_98 ( V_154 ) ;
}
static void
F_496 ( struct V_13 * V_14 , struct V_279 * V_280 )
{
struct V_759 * V_156 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_760 ] ,
} ;
if ( V_14 -> V_62 -> V_166 -> V_330 != 0 )
return;
V_156 = F_277 ( sizeof( * V_156 ) , V_301 ) ;
if ( ! V_156 )
return;
V_156 -> V_280 = V_280 ;
V_156 -> V_14 = V_14 ;
V_156 -> args . V_703 . V_233 = V_14 -> V_62 -> V_234 ;
V_156 -> args . V_703 . V_235 = V_280 -> V_706 . V_238 ;
V_156 -> args . V_703 . V_707 = V_14 -> V_707 ;
V_161 . V_312 = & V_156 -> args ;
V_161 . V_313 = & V_156 -> V_56 ;
F_39 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 0 ) ;
F_385 ( V_14 -> V_90 , & V_161 , 0 , & V_761 , V_156 ) ;
}
static int F_497 ( struct V_4 * V_4 , const char * V_762 ,
const void * V_602 , T_9 V_603 ,
int V_213 , int type )
{
if ( strcmp ( V_762 , L_55 ) != 0 )
return - V_27 ;
return F_407 ( F_14 ( V_4 ) , V_602 , V_603 ) ;
}
static int F_498 ( struct V_4 * V_4 , const char * V_762 ,
void * V_602 , T_9 V_603 , int type )
{
if ( strcmp ( V_762 , L_55 ) != 0 )
return - V_27 ;
return F_401 ( F_14 ( V_4 ) , V_602 , V_603 ) ;
}
static T_9 F_499 ( struct V_4 * V_4 , char * V_763 ,
T_9 V_764 , const char * V_239 ,
T_9 V_765 , int type )
{
T_9 V_12 = sizeof( V_766 ) ;
if ( ! F_388 ( F_88 ( F_14 ( V_4 ) ) ) )
return 0 ;
if ( V_763 && V_12 <= V_764 )
memcpy ( V_763 , V_766 , V_12 ) ;
return V_12 ;
}
static inline int F_500 ( struct V_13 * V_14 )
{
return V_14 -> V_93 & V_9 ;
}
static int F_501 ( struct V_4 * V_4 , const char * V_762 ,
const void * V_602 , T_9 V_603 ,
int V_213 , int type )
{
if ( F_502 ( V_762 ) )
return F_415 ( V_4 , V_602 , V_603 ) ;
return - V_628 ;
}
static int F_503 ( struct V_4 * V_4 , const char * V_762 ,
void * V_602 , T_9 V_603 , int type )
{
if ( F_502 ( V_762 ) )
return F_410 ( F_14 ( V_4 ) , V_602 , V_603 ) ;
return - V_628 ;
}
static T_9 F_504 ( struct V_4 * V_4 , char * V_763 ,
T_9 V_764 , const char * V_239 ,
T_9 V_765 , int type )
{
T_9 V_12 = 0 ;
if ( F_2 ( F_14 ( V_4 ) , V_9 ) ) {
V_12 = F_505 ( F_14 ( V_4 ) , NULL , 0 ) ;
if ( V_763 && V_12 <= V_764 )
F_505 ( F_14 ( V_4 ) , V_763 , V_12 ) ;
}
return V_12 ;
}
static void F_279 ( struct V_385 * V_386 )
{
if ( ! ( ( ( V_386 -> V_295 & V_767 ) ||
( V_386 -> V_295 & V_768 ) ) &&
( V_386 -> V_295 & V_479 ) &&
( V_386 -> V_295 & V_769 ) ) )
return;
V_386 -> V_295 |= V_333 | V_495 |
V_496 | V_770 ;
V_386 -> V_254 = V_338 | V_498 | V_499 ;
V_386 -> V_500 = 2 ;
}
static int F_506 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_481 * V_239 ,
struct V_483 * V_771 ,
struct V_482 * V_482 )
{
struct V_13 * V_14 = F_88 ( V_3 ) ;
T_1 V_240 [ 3 ] = {
[ 0 ] = V_772 | V_773 ,
} ;
struct V_774 args = {
. V_493 = F_95 ( V_3 ) ,
. V_239 = V_239 ,
. V_482 = V_482 ,
. V_240 = V_240 ,
} ;
struct V_775 V_56 = {
. V_771 = V_771 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_776 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
int V_304 ;
F_8 ( L_56 , V_34 ) ;
if ( F_88 ( V_3 ) -> V_15 [ 1 ] & V_777 )
V_240 [ 1 ] |= V_777 ;
else
V_240 [ 0 ] |= V_45 ;
F_84 ( & V_771 -> V_386 ) ;
V_771 -> V_14 = V_14 ;
V_771 -> V_778 = 0 ;
V_304 = F_74 ( V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
F_8 ( L_57 , V_34 , V_304 ) ;
return V_304 ;
}
int F_278 ( struct V_54 * V_90 , struct V_2 * V_3 ,
const struct V_481 * V_239 ,
struct V_483 * V_771 ,
struct V_482 * V_482 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_506 ( V_90 , V_3 , V_239 ,
V_771 , V_482 ) ;
F_507 ( V_3 , V_239 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_508 ( struct V_2 * V_2 ,
struct V_483 * V_484 ,
struct V_482 * V_482 , struct V_314 * V_348 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
T_1 V_240 [ 2 ] = {
[ 0 ] = V_772 | V_773 ,
} ;
struct V_774 args = {
. V_233 = V_14 -> V_62 -> V_234 ,
. V_243 = F_95 ( V_2 ) ,
. V_482 = V_482 ,
. V_240 = V_240 ,
. V_779 = 1 ,
. V_780 = 1 ,
} ;
struct V_775 V_56 = {
. V_771 = V_484 ,
. V_779 = 1 ,
. V_780 = 1 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_776 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
unsigned long V_562 = V_152 ;
int V_304 ;
F_84 ( & V_484 -> V_386 ) ;
V_484 -> V_14 = V_14 ;
V_484 -> V_778 = 0 ;
F_39 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_40 ( & args . V_158 ) ;
V_304 = F_70 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_304 )
return V_304 ;
F_38 ( V_14 , V_562 ) ;
return 0 ;
}
static int F_509 ( struct V_2 * V_2 ,
struct V_483 * V_484 ,
struct V_482 * V_482 , struct V_314 * V_348 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
T_1 V_240 [ 2 ] = {
[ 0 ] = V_772 | V_773 ,
} ;
struct V_774 args = {
. V_243 = F_95 ( V_2 ) ,
. V_482 = V_482 ,
. V_240 = V_240 ,
. V_779 = 1 ,
} ;
struct V_775 V_56 = {
. V_771 = V_484 ,
. V_779 = 1 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_776 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
int V_304 ;
F_84 ( & V_484 -> V_386 ) ;
V_484 -> V_14 = V_14 ;
V_484 -> V_778 = 0 ;
F_39 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_40 ( & args . V_158 ) ;
V_304 = F_70 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_304 == V_781 &&
V_56 . V_159 . V_143 & V_782 )
V_304 = - V_77 ;
return V_304 ;
}
int F_510 ( struct V_2 * V_2 ,
struct V_483 * V_484 ,
struct V_482 * V_482 , struct V_314 * V_348 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_783 * V_784 =
V_63 -> V_166 -> V_785 ;
struct V_60 V_61 = { } ;
int V_304 ;
F_8 ( L_58 , V_34 ,
( unsigned long long ) V_14 -> V_480 . V_786 ,
( unsigned long long ) V_14 -> V_480 . V_787 ,
V_63 -> V_96 ) ;
F_511 ( F_95 ( V_2 ) , V_34 ) ;
do {
V_304 = V_784 -> V_788 ( V_2 , V_484 , V_482 , V_348 ) ;
if ( V_304 != - V_89 )
break;
F_21 ( V_14 , V_304 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_304 ;
}
static int F_512 ( struct V_2 * V_2 , struct V_314 * V_348 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_62 * V_63 = F_88 ( V_2 ) -> V_62 ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_789 args = {
. V_243 = F_95 ( V_2 ) ,
. V_233 = V_63 -> V_234 ,
. V_780 = 1 ,
} ;
struct V_790 V_56 = {
. V_780 = 1 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_791 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
unsigned long V_562 = V_152 ;
int V_304 ;
V_56 . V_243 = F_513 () ;
if ( V_56 . V_243 == NULL )
return - V_124 ;
F_39 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_40 ( & args . V_158 ) ;
V_304 = F_70 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
F_514 ( V_56 . V_243 ) ;
if ( V_304 )
return V_304 ;
F_34 ( V_63 , V_562 ) ;
return 0 ;
}
static int F_515 ( struct V_2 * V_2 , struct V_314 * V_348 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_789 args = {
. V_243 = F_95 ( V_2 ) ,
} ;
struct V_790 V_56 = {
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_791 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
int V_304 ;
V_56 . V_243 = F_513 () ;
if ( V_56 . V_243 == NULL )
return - V_124 ;
F_39 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_40 ( & args . V_158 ) ;
V_304 = F_70 ( V_55 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
F_514 ( V_56 . V_243 ) ;
if ( V_304 == V_781 &&
V_56 . V_159 . V_143 & V_782 )
V_304 = - V_77 ;
return V_304 ;
}
int F_516 ( struct V_2 * V_2 , struct V_314 * V_348 )
{
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_783 * V_784 =
V_63 -> V_166 -> V_785 ;
struct V_60 V_61 = { } ;
int V_304 ;
F_8 ( L_58 , V_34 ,
( unsigned long long ) V_14 -> V_480 . V_786 ,
( unsigned long long ) V_14 -> V_480 . V_787 ,
V_63 -> V_96 ) ;
F_511 ( F_95 ( V_2 ) , V_34 ) ;
do {
V_304 = V_784 -> V_792 ( V_2 , V_348 ) ;
if ( V_304 != - V_89 )
break;
F_21 ( V_14 , V_304 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_304 ;
}
static int F_517 ( struct V_2 * V_3 , const struct V_481 * V_239 , struct V_793 * V_474 , bool V_794 )
{
int V_304 ;
struct V_795 args = {
. V_493 = F_95 ( V_3 ) ,
. V_239 = V_239 ,
} ;
struct V_796 V_56 = {
. V_474 = V_474 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_797 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
struct V_54 * V_55 = F_88 ( V_3 ) -> V_90 ;
struct V_314 * V_348 = NULL ;
if ( V_794 ) {
V_55 = F_88 ( V_3 ) -> V_62 -> V_100 ;
V_348 = F_518 ( F_88 ( V_3 ) -> V_62 ) ;
V_161 . V_314 = V_348 ;
}
F_8 ( L_59 , V_239 -> V_239 ) ;
F_254 ( F_88 ( V_3 ) -> V_62 ,
V_798 , & V_55 , & V_161 ) ;
V_304 = F_74 ( V_55 , F_88 ( V_3 ) , & V_161 , & args . V_158 ,
& V_56 . V_159 , 0 ) ;
F_8 ( L_60 , V_304 ) ;
if ( V_348 )
F_211 ( V_348 ) ;
return V_304 ;
}
int F_519 ( struct V_2 * V_3 , const struct V_481 * V_239 ,
struct V_793 * V_474 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_33 ( F_88 ( V_3 ) -> V_62 ) )
V_8 = F_517 ( V_3 , V_239 , V_474 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_517 ( V_3 , V_239 , V_474 , false ) ;
F_520 ( V_3 , V_239 , V_8 ) ;
V_8 = F_21 ( F_88 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static int F_521 ( T_1 V_213 )
{
if ( V_213 & ~ V_799 )
goto V_800;
if ( ( V_213 & V_801 ) &&
( V_213 & V_802 ) )
goto V_800;
if ( ! ( V_213 & ( V_803 ) ) )
goto V_800;
return V_361 ;
V_800:
return - V_804 ;
}
static bool
F_522 ( struct V_805 * V_806 ,
struct V_805 * V_807 )
{
if ( V_806 -> V_808 == V_807 -> V_808 &&
memcmp ( V_806 -> V_809 , V_807 -> V_809 , V_806 -> V_808 ) == 0 )
return true ;
return false ;
}
int F_523 ( struct V_62 * V_63 , struct V_314 * V_348 )
{
int V_304 ;
struct V_810 args = {
. V_90 = V_63 ,
. V_3 = V_811 ,
} ;
struct V_812 V_56 ;
struct V_160 V_161 = {
. V_309 =
& V_310 [ V_813 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
F_8 ( L_11 , V_34 ) ;
F_524 ( & args . V_814 , & V_63 -> V_86 -> V_815 ) ;
if ( ! ( V_63 -> V_86 -> V_213 & V_816 ) )
args . V_3 = V_817 ;
V_304 = F_387 ( V_63 -> V_100 , & V_161 , V_600 ) ;
F_525 ( V_63 , V_304 ) ;
if ( V_304 == 0 ) {
if ( memcmp ( V_56 . V_814 . V_156 ,
V_63 -> V_86 -> V_815 . V_156 , V_818 ) ) {
F_8 ( L_61 , V_34 ) ;
V_304 = - V_35 ;
goto V_129;
}
if ( ( V_56 . V_3 & args . V_3 ) != V_56 . V_3 || V_56 . V_3 == 0 ) {
F_8 ( L_62 ,
V_34 ) ;
V_304 = - V_35 ;
goto V_129;
}
if ( V_56 . V_819 != args . V_819 ) {
F_8 ( L_63 ,
V_34 ) ;
V_304 = - V_35 ;
goto V_129;
}
}
V_129:
F_8 ( L_64 , V_34 , V_304 ) ;
return V_304 ;
}
static int F_526 ( struct V_62 * V_63 ,
struct V_820 * V_212 )
{
static const T_1 V_821 [ V_822 ] = {
[ 1 ] = 1 << ( V_823 - 32 ) |
1 << ( V_824 - 32 ) |
1 << ( V_825 - 32 ) |
1 << ( V_826 - 32 ) |
1 << ( V_827 - 32 )
} ;
unsigned int V_471 ;
if ( V_212 -> V_828 == V_829 ) {
F_527 ( V_830 , L_65 ) ;
for ( V_471 = 0 ; V_471 <= V_831 ; V_471 ++ ) {
if ( F_32 ( V_471 , V_212 -> V_832 . V_247 . V_833 ) )
F_527 ( V_830 , L_66 , V_471 ) ;
if ( F_32 ( V_471 , V_212 -> V_834 . V_247 . V_833 ) )
F_527 ( V_830 , L_67 , V_471 ) ;
}
for ( V_471 = 0 ; V_471 < V_822 ; V_471 ++ ) {
if ( V_212 -> V_832 . V_247 . V_835 [ V_471 ] & ~ V_821 [ V_471 ] ) {
F_527 ( V_830 , L_68 ) ;
return - V_27 ;
}
}
if ( F_32 ( V_823 , V_212 -> V_832 . V_247 . V_833 ) &&
F_32 ( V_825 , V_212 -> V_832 . V_247 . V_833 ) &&
F_32 ( V_826 , V_212 -> V_832 . V_247 . V_833 ) &&
F_32 ( V_827 , V_212 -> V_832 . V_247 . V_833 ) ) {
F_527 ( V_830 , L_69 ) ;
F_527 ( V_830 , L_70 ) ;
F_124 ( V_836 , & V_63 -> V_837 ) ;
} else {
F_527 ( V_830 , L_68 ) ;
return - V_27 ;
}
if ( F_32 ( V_838 , V_212 -> V_834 . V_247 . V_833 ) &&
F_32 ( V_839 , V_212 -> V_834 . V_247 . V_833 ) ) {
F_527 ( V_830 , L_71 ) ;
F_124 ( V_418 , & V_63 -> V_837 ) ;
}
if ( F_32 ( V_840 , V_212 -> V_834 . V_247 . V_833 ) &&
F_32 ( V_841 , V_212 -> V_834 . V_247 . V_833 ) ) {
F_527 ( V_830 , L_72 ) ;
F_124 ( V_798 , & V_63 -> V_837 ) ;
}
if ( F_32 ( V_842 , V_212 -> V_834 . V_247 . V_833 ) &&
F_32 ( V_843 , V_212 -> V_834 . V_247 . V_833 ) ) {
F_527 ( V_830 , L_73 ) ;
F_124 ( V_844 , & V_63 -> V_837 ) ;
}
if ( F_32 ( V_845 , V_212 -> V_834 . V_247 . V_833 ) ) {
F_527 ( V_830 , L_74 ) ;
F_124 ( V_846 , & V_63 -> V_837 ) ;
}
if ( F_32 ( V_847 , V_212 -> V_834 . V_247 . V_833 ) ) {
F_527 ( V_830 , L_75 ) ;
F_124 ( V_848 , & V_63 -> V_837 ) ;
}
}
return 0 ;
}
static int F_528 ( struct V_62 * V_63 , struct V_314 * V_348 ,
T_1 V_849 )
{
T_12 V_37 ;
struct V_850 args = {
. V_37 = & V_37 ,
. V_90 = V_63 ,
#ifdef F_529
. V_213 = V_851 |
V_852 |
V_853 ,
#else
. V_213 = V_851 |
V_852 ,
#endif
} ;
struct V_854 V_56 = {
0
} ;
int V_304 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_855 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
F_419 ( V_63 , & V_37 ) ;
args . V_856 = F_427 ( V_63 , args . V_235 ,
sizeof( args . V_235 ) ) ;
F_8 ( L_76 ,
V_63 -> V_100 -> V_101 -> V_685 -> V_686 ,
args . V_856 , args . V_235 ) ;
V_56 . V_857 = F_89 ( sizeof( struct V_858 ) ,
V_301 ) ;
if ( F_363 ( V_56 . V_857 == NULL ) ) {
V_304 = - V_124 ;
goto V_129;
}
V_56 . V_809 = F_89 ( sizeof( struct V_805 ) ,
V_301 ) ;
if ( F_363 ( V_56 . V_809 == NULL ) ) {
V_304 = - V_124 ;
goto V_859;
}
V_56 . V_860 = F_89 ( sizeof( struct V_861 ) , V_301 ) ;
if ( F_363 ( V_56 . V_860 == NULL ) ) {
V_304 = - V_124 ;
goto V_862;
}
switch ( V_849 ) {
case V_863 :
args . V_864 . V_828 = V_863 ;
break;
case V_829 :
args . V_864 = V_865 ;
break;
default:
F_530 ( 1 ) ;
V_304 = - V_27 ;
goto V_862;
}
V_304 = F_387 ( V_63 -> V_100 , & V_161 , V_600 ) ;
F_531 ( V_63 , V_304 ) ;
if ( V_304 == 0 )
V_304 = F_521 ( V_56 . V_213 ) ;
if ( V_304 == 0 )
V_304 = F_526 ( V_63 , & V_56 . V_864 ) ;
if ( V_304 == 0 ) {
V_63 -> V_234 = V_56 . V_233 ;
V_63 -> V_866 = V_56 . V_213 ;
if ( ! ( V_56 . V_213 & V_867 ) ) {
F_126 ( V_868 ,
& V_63 -> V_86 -> V_869 ) ;
V_63 -> V_870 = V_56 . V_203 ;
}
F_98 ( V_63 -> V_871 ) ;
V_63 -> V_871 = V_56 . V_857 ;
V_56 . V_857 = NULL ;
F_98 ( V_63 -> V_872 ) ;
V_63 -> V_872 = V_56 . V_860 ;
if ( V_63 -> V_873 != NULL &&
! F_522 ( V_63 -> V_873 ,
V_56 . V_809 ) ) {
F_8 ( L_77 ,
V_34 ) ;
F_124 ( V_874 , & V_63 -> V_641 ) ;
F_98 ( V_63 -> V_873 ) ;
V_63 -> V_873 = NULL ;
}
if ( V_63 -> V_873 == NULL ) {
V_63 -> V_873 = V_56 . V_809 ;
goto V_129;
}
} else
F_98 ( V_56 . V_860 ) ;
V_859:
F_98 ( V_56 . V_857 ) ;
V_862:
F_98 ( V_56 . V_809 ) ;
V_129:
if ( V_63 -> V_872 != NULL )
F_8 ( L_78
L_79 ,
V_63 -> V_872 -> V_875 , V_63 -> V_872 -> V_239 ,
V_63 -> V_872 -> V_876 . V_877 ,
V_63 -> V_872 -> V_876 . V_878 ) ;
F_8 ( L_80 , V_304 ) ;
return V_304 ;
}
int F_532 ( struct V_62 * V_63 , struct V_314 * V_348 )
{
T_4 V_879 = V_63 -> V_100 -> V_101 -> V_102 ;
int V_304 ;
if ( V_879 == V_103 ||
V_879 == V_104 ) {
V_304 = F_528 ( V_63 , V_348 , V_829 ) ;
if ( ! V_304 )
return 0 ;
}
return F_528 ( V_63 , V_348 , V_863 ) ;
}
static int F_533 ( struct V_62 * V_63 ,
struct V_314 * V_348 )
{
struct V_160 V_161 = {
. V_309 = & V_310 [ V_880 ] ,
. V_312 = V_63 ,
. V_314 = V_348 ,
} ;
int V_304 ;
V_304 = F_387 ( V_63 -> V_100 , & V_161 , V_600 ) ;
F_534 ( V_63 , V_304 ) ;
if ( V_304 )
F_8 ( L_81
L_82 , V_304 , V_63 -> V_96 ) ;
return V_304 ;
}
static int F_535 ( struct V_62 * V_63 ,
struct V_314 * V_348 )
{
unsigned int V_881 ;
int V_51 ;
for ( V_881 = V_882 ; V_881 != 0 ; V_881 -- ) {
V_51 = F_533 ( V_63 , V_348 ) ;
switch ( V_51 ) {
case - V_89 :
case - V_883 :
F_172 ( 1 ) ;
break;
default:
return V_51 ;
}
}
return 0 ;
}
int F_536 ( struct V_62 * V_63 )
{
struct V_314 * V_348 ;
int V_51 = 0 ;
if ( V_63 -> V_166 -> V_330 < 1 )
goto V_129;
if ( V_63 -> V_866 == 0 )
goto V_129;
if ( V_63 -> V_884 )
goto V_129;
V_348 = F_518 ( V_63 ) ;
V_51 = F_535 ( V_63 , V_348 ) ;
if ( V_348 )
F_211 ( V_348 ) ;
switch ( V_51 ) {
case 0 :
case - V_75 :
V_63 -> V_866 = 0 ;
}
V_129:
return V_51 ;
}
static void F_537 ( struct V_117 * V_118 ,
void * V_154 )
{
struct V_885 * V_156 =
(struct V_885 * ) V_154 ;
F_8 ( L_11 , V_34 ) ;
F_62 ( V_156 -> V_63 -> V_86 ,
& V_156 -> args -> V_886 ,
& V_156 -> V_56 -> V_887 ,
V_118 ) ;
F_8 ( L_83 , V_34 ) ;
}
static void F_538 ( struct V_117 * V_118 , void * V_154 )
{
struct V_885 * V_156 =
(struct V_885 * ) V_154 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_54 ( V_118 , & V_156 -> V_56 -> V_887 ) )
return;
switch ( V_118 -> V_147 ) {
case - V_89 :
case - V_88 :
F_8 ( L_84 , V_34 , V_118 -> V_147 ) ;
F_60 ( V_118 , V_53 ) ;
V_118 -> V_147 = 0 ;
case - V_91 :
F_58 ( V_118 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
int F_539 ( struct V_62 * V_63 , struct V_457 * V_558 )
{
struct V_117 * V_118 ;
struct V_888 args ;
struct V_889 V_56 = {
. V_890 = V_558 ,
} ;
struct V_885 V_156 = {
. args = & args ,
. V_56 = & V_56 ,
. V_63 = V_63 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_891 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
struct V_162 V_163 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_892 ,
. V_168 = & V_156 ,
. V_213 = V_600 ,
} ;
int V_304 ;
F_39 ( & args . V_886 , & V_56 . V_887 , 0 ) ;
F_40 ( & args . V_886 ) ;
F_8 ( L_11 , V_34 ) ;
V_118 = F_71 ( & V_163 ) ;
if ( F_44 ( V_118 ) )
V_304 = F_72 ( V_118 ) ;
else {
V_304 = V_118 -> V_147 ;
F_73 ( V_118 ) ;
}
F_8 ( L_85 , V_34 , V_304 ) ;
return V_304 ;
}
static void F_540 ( struct V_893 * args )
{
unsigned int V_894 , V_895 ;
V_894 = V_896 + V_897 ;
V_895 = V_896 + V_898 ;
args -> V_899 . V_894 = V_894 ;
args -> V_899 . V_895 = V_895 ;
args -> V_899 . V_900 = V_901 ;
args -> V_899 . V_902 = V_903 ;
F_8 ( L_86
L_87 ,
V_34 ,
args -> V_899 . V_894 , args -> V_899 . V_895 ,
args -> V_899 . V_900 , args -> V_899 . V_902 ) ;
args -> V_904 . V_894 = V_607 ;
args -> V_904 . V_895 = V_607 ;
args -> V_904 . V_905 = 0 ;
args -> V_904 . V_900 = V_906 ;
args -> V_904 . V_902 = 1 ;
F_8 ( L_88
L_89 ,
V_34 ,
args -> V_904 . V_894 , args -> V_904 . V_895 ,
args -> V_904 . V_905 , args -> V_904 . V_900 ,
args -> V_904 . V_902 ) ;
}
static int F_541 ( struct V_893 * args ,
struct V_907 * V_56 )
{
struct V_908 * V_909 = & args -> V_899 ;
struct V_908 * V_910 = & V_56 -> V_899 ;
if ( V_910 -> V_895 > V_909 -> V_895 )
return - V_27 ;
if ( V_910 -> V_900 < V_909 -> V_900 )
return - V_27 ;
if ( V_910 -> V_902 == 0 )
return - V_27 ;
if ( V_910 -> V_902 > V_911 )
V_910 -> V_902 = V_911 ;
return 0 ;
}
static int F_542 ( struct V_893 * args ,
struct V_907 * V_56 )
{
struct V_908 * V_909 = & args -> V_904 ;
struct V_908 * V_910 = & V_56 -> V_904 ;
if ( ! ( V_56 -> V_213 & V_816 ) )
goto V_129;
if ( V_910 -> V_894 > V_909 -> V_894 )
return - V_27 ;
if ( V_910 -> V_895 < V_909 -> V_895 )
return - V_27 ;
if ( V_910 -> V_905 > V_909 -> V_905 )
return - V_27 ;
if ( V_910 -> V_900 != V_909 -> V_900 )
return - V_27 ;
if ( V_910 -> V_902 != V_909 -> V_902 )
return - V_27 ;
V_129:
return 0 ;
}
static int F_543 ( struct V_893 * args ,
struct V_907 * V_56 )
{
int V_51 ;
V_51 = F_541 ( args , V_56 ) ;
if ( V_51 )
return V_51 ;
return F_542 ( args , V_56 ) ;
}
static void F_544 ( struct V_131 * V_132 ,
struct V_907 * V_56 )
{
F_524 ( & V_132 -> V_815 , & V_56 -> V_814 ) ;
V_132 -> V_63 -> V_866 |= V_867 ;
F_124 ( V_868 , & V_132 -> V_869 ) ;
V_132 -> V_213 = V_56 -> V_213 ;
memcpy ( & V_132 -> V_899 , & V_56 -> V_899 , sizeof( V_132 -> V_899 ) ) ;
if ( V_56 -> V_213 & V_816 )
memcpy ( & V_132 -> V_904 , & V_56 -> V_904 ,
sizeof( V_132 -> V_904 ) ) ;
}
static int F_545 ( struct V_62 * V_63 ,
struct V_314 * V_348 )
{
struct V_131 * V_132 = V_63 -> V_86 ;
struct V_893 args = {
. V_90 = V_63 ,
. V_233 = V_63 -> V_234 ,
. V_203 = V_63 -> V_870 ,
. V_912 = V_913 ,
} ;
struct V_907 V_56 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_914 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
int V_304 ;
F_540 ( & args ) ;
args . V_213 = ( V_915 | V_816 ) ;
V_304 = F_387 ( V_132 -> V_63 -> V_100 , & V_161 , V_600 ) ;
F_546 ( V_63 , V_304 ) ;
if ( ! V_304 ) {
V_304 = F_543 ( & args , & V_56 ) ;
if ( V_63 -> V_870 == V_56 . V_203 )
V_63 -> V_870 ++ ;
if ( V_304 )
goto V_129;
F_544 ( V_132 , & V_56 ) ;
}
V_129:
return V_304 ;
}
int F_547 ( struct V_62 * V_63 , struct V_314 * V_348 )
{
int V_304 ;
unsigned * V_916 ;
struct V_131 * V_132 = V_63 -> V_86 ;
F_8 ( L_90 , V_34 , V_63 , V_132 ) ;
V_304 = F_545 ( V_63 , V_348 ) ;
if ( V_304 )
goto V_129;
V_304 = F_548 ( V_132 ) ;
F_8 ( L_91 , V_304 ) ;
if ( V_304 )
goto V_129;
V_916 = ( unsigned * ) & V_132 -> V_815 . V_156 [ 0 ] ;
F_8 ( L_92 , V_34 ,
V_63 -> V_870 , V_916 [ 0 ] , V_916 [ 1 ] , V_916 [ 2 ] , V_916 [ 3 ] ) ;
V_129:
F_8 ( L_83 , V_34 ) ;
return V_304 ;
}
int F_549 ( struct V_131 * V_132 ,
struct V_314 * V_348 )
{
struct V_160 V_161 = {
. V_309 = & V_310 [ V_917 ] ,
. V_312 = V_132 ,
. V_314 = V_348 ,
} ;
int V_304 = 0 ;
F_8 ( L_93 ) ;
if ( ! F_117 ( V_868 , & V_132 -> V_869 ) )
return 0 ;
V_304 = F_387 ( V_132 -> V_63 -> V_100 , & V_161 , V_600 ) ;
F_550 ( V_132 -> V_63 , V_304 ) ;
if ( V_304 )
F_8 ( L_94
L_95 , V_304 ) ;
F_8 ( L_96 ) ;
return V_304 ;
}
static void F_551 ( void * V_156 )
{
struct V_918 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
if ( F_377 ( & V_63 -> V_594 ) > 1 )
F_378 ( V_63 ) ;
F_379 ( V_63 ) ;
F_98 ( V_154 ) ;
}
static int F_552 ( struct V_117 * V_118 , struct V_62 * V_63 )
{
switch( V_118 -> V_147 ) {
case - V_89 :
F_60 ( V_118 , V_52 ) ;
return - V_128 ;
default:
F_25 ( V_63 ) ;
}
return 0 ;
}
static void F_553 ( struct V_117 * V_118 , void * V_156 )
{
struct V_918 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
if ( ! F_54 ( V_118 , V_118 -> V_324 . V_313 ) )
return;
F_554 ( V_63 , V_118 -> V_147 ) ;
if ( V_118 -> V_147 < 0 ) {
F_8 ( L_97 , V_34 , V_118 -> V_147 ) ;
if ( F_377 ( & V_63 -> V_594 ) == 1 )
goto V_129;
if ( F_552 ( V_118 , V_63 ) == - V_128 ) {
F_58 ( V_118 ) ;
return;
}
}
F_8 ( L_98 , V_34 , V_118 -> V_324 . V_314 ) ;
V_129:
F_8 ( L_83 , V_34 ) ;
}
static void F_555 ( struct V_117 * V_118 , void * V_156 )
{
struct V_918 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
struct V_108 * args ;
struct V_109 * V_56 ;
args = V_118 -> V_324 . V_312 ;
V_56 = V_118 -> V_324 . V_313 ;
F_62 ( V_63 -> V_86 , args , V_56 , V_118 ) ;
}
static struct V_117 * F_556 ( struct V_62 * V_63 ,
struct V_314 * V_348 ,
bool V_919 )
{
struct V_918 * V_154 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_920 ] ,
. V_314 = V_348 ,
} ;
struct V_162 V_315 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_921 ,
. V_213 = V_319 | V_600 ,
} ;
if ( ! F_384 ( & V_63 -> V_594 ) )
return F_45 ( - V_35 ) ;
V_154 = F_89 ( sizeof( * V_154 ) , V_301 ) ;
if ( V_154 == NULL ) {
F_379 ( V_63 ) ;
return F_45 ( - V_124 ) ;
}
F_39 ( & V_154 -> args , & V_154 -> V_56 , 0 ) ;
if ( V_919 )
F_40 ( & V_154 -> args ) ;
V_161 . V_312 = & V_154 -> args ;
V_161 . V_313 = & V_154 -> V_56 ;
V_154 -> V_63 = V_63 ;
V_315 . V_168 = V_154 ;
return F_71 ( & V_315 ) ;
}
static int F_557 ( struct V_62 * V_63 , struct V_314 * V_348 , unsigned V_598 )
{
struct V_117 * V_118 ;
int V_51 = 0 ;
if ( ( V_598 & V_922 ) == 0 )
return - V_128 ;
V_118 = F_556 ( V_63 , V_348 , false ) ;
if ( F_44 ( V_118 ) )
V_51 = F_72 ( V_118 ) ;
else
F_472 ( V_118 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_558 ( struct V_62 * V_63 , struct V_314 * V_348 )
{
struct V_117 * V_118 ;
int V_51 ;
V_118 = F_556 ( V_63 , V_348 , true ) ;
if ( F_44 ( V_118 ) ) {
V_51 = F_72 ( V_118 ) ;
goto V_129;
}
V_51 = F_110 ( V_118 ) ;
if ( ! V_51 ) {
struct V_109 * V_56 = V_118 -> V_324 . V_313 ;
if ( V_118 -> V_147 == 0 )
F_559 ( V_63 , V_56 -> V_143 ) ;
V_51 = V_118 -> V_147 ;
}
F_73 ( V_118 ) ;
V_129:
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static void F_560 ( struct V_117 * V_118 , void * V_156 )
{
struct V_923 * V_154 = V_156 ;
F_62 ( V_154 -> V_63 -> V_86 ,
& V_154 -> V_389 . V_158 ,
& V_154 -> V_56 . V_159 ,
V_118 ) ;
}
static int F_561 ( struct V_117 * V_118 , struct V_62 * V_63 )
{
switch( V_118 -> V_147 ) {
case 0 :
case - V_924 :
case - V_23 :
break;
case - V_89 :
F_60 ( V_118 , V_52 ) ;
case - V_91 :
return - V_128 ;
default:
F_25 ( V_63 ) ;
}
return 0 ;
}
static void F_562 ( struct V_117 * V_118 , void * V_156 )
{
struct V_923 * V_154 = V_156 ;
struct V_62 * V_63 = V_154 -> V_63 ;
struct V_109 * V_56 = & V_154 -> V_56 . V_159 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_54 ( V_118 , V_56 ) )
return;
F_563 ( V_63 , V_118 -> V_147 ) ;
if ( F_561 ( V_118 , V_63 ) == - V_128 ) {
F_58 ( V_118 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_564 ( void * V_156 )
{
struct V_923 * V_154 = V_156 ;
F_98 ( V_154 ) ;
}
static int F_565 ( struct V_62 * V_63 ,
struct V_314 * V_348 )
{
struct V_923 * V_154 ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_925 ] ,
. V_314 = V_348 ,
} ;
struct V_162 V_315 = {
. V_164 = V_63 -> V_100 ,
. V_160 = & V_161 ,
. V_165 = & V_926 ,
. V_213 = V_319 ,
} ;
int V_304 = - V_124 ;
F_8 ( L_11 , V_34 ) ;
V_154 = F_89 ( sizeof( * V_154 ) , V_301 ) ;
if ( V_154 == NULL )
goto V_129;
V_154 -> V_63 = V_63 ;
V_154 -> V_389 . V_927 = 0 ;
F_39 ( & V_154 -> V_389 . V_158 , & V_154 -> V_56 . V_159 , 0 ) ;
F_40 ( & V_154 -> V_389 . V_158 ) ;
V_161 . V_312 = & V_154 -> V_389 ;
V_161 . V_313 = & V_154 -> V_56 ;
V_315 . V_168 = V_154 ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) ) {
V_304 = F_72 ( V_118 ) ;
goto V_129;
}
V_304 = F_109 ( V_118 ) ;
if ( V_304 == 0 )
V_304 = V_118 -> V_147 ;
F_73 ( V_118 ) ;
return 0 ;
V_129:
F_8 ( L_16 , V_34 , V_304 ) ;
return V_304 ;
}
static void
F_566 ( struct V_117 * V_118 , void * V_154 )
{
struct V_928 * V_929 = V_154 ;
struct V_13 * V_14 = F_88 ( V_929 -> args . V_2 ) ;
struct V_131 * V_132 = F_65 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
if ( F_62 ( V_132 , & V_929 -> args . V_158 ,
& V_929 -> V_56 . V_159 , V_118 ) )
return;
if ( F_567 ( & V_929 -> args . V_249 ,
F_76 ( V_929 -> args . V_2 ) -> V_930 ,
& V_929 -> args . V_931 ,
V_929 -> args . V_299 -> V_65 ) ) {
F_568 ( V_118 , V_781 ) ;
}
}
static void F_569 ( struct V_117 * V_118 , void * V_154 )
{
struct V_928 * V_929 = V_154 ;
struct V_2 * V_2 = V_929 -> args . V_2 ;
struct V_13 * V_14 = F_88 ( V_2 ) ;
struct V_932 * V_933 ;
struct V_64 * V_65 = NULL ;
unsigned long V_934 , V_562 , V_935 ;
F_8 ( L_99 , V_34 , - V_118 -> V_147 ) ;
if ( ! F_54 ( V_118 , & V_929 -> V_56 . V_159 ) )
goto V_129;
switch ( V_118 -> V_147 ) {
case 0 :
goto V_129;
case - V_19 :
case - V_20 :
V_934 = F_570 ( V_118 -> V_936 ) ;
V_935 = V_929 -> args . V_105 + V_934 ;
V_562 = V_152 ;
if ( F_571 ( V_935 , V_562 ) ) {
unsigned long V_937 ;
V_937 = F_572 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_100 ,
V_34 , V_937 ) ;
F_60 ( V_118 , V_937 ) ;
V_118 -> V_147 = 0 ;
F_58 ( V_118 ) ;
goto V_129;
}
break;
case - V_73 :
case - V_72 :
F_35 ( & V_2 -> V_173 ) ;
V_933 = F_76 ( V_2 ) -> V_930 ;
if ( ! V_933 || F_573 ( & V_933 -> V_938 ) ) {
F_37 ( & V_2 -> V_173 ) ;
V_65 = V_929 -> args . V_299 -> V_65 ;
} else {
F_574 ( V_939 ) ;
F_575 ( V_933 , & V_939 , NULL ) ;
F_37 ( & V_2 -> V_173 ) ;
F_576 ( & V_939 ) ;
V_118 -> V_147 = 0 ;
F_58 ( V_118 ) ;
}
}
if ( F_247 ( V_118 , V_14 , V_65 , NULL ) == - V_128 )
F_58 ( V_118 ) ;
V_129:
F_8 ( L_83 , V_34 ) ;
}
static T_9 F_577 ( struct V_13 * V_14 )
{
T_1 V_895 = V_14 -> V_62 -> V_86 -> V_899 . V_895 ;
return F_578 ( 0 , V_895 ) ;
}
static void F_579 ( struct V_482 * * V_42 , T_9 V_940 )
{
int V_471 ;
if ( ! V_42 )
return;
for ( V_471 = 0 ; V_471 < V_940 ; V_471 ++ ) {
if ( ! V_42 [ V_471 ] )
break;
F_280 ( V_42 [ V_471 ] ) ;
}
F_98 ( V_42 ) ;
}
static struct V_482 * * F_580 ( T_9 V_940 , T_6 V_941 )
{
struct V_482 * * V_42 ;
int V_471 ;
V_42 = F_581 ( V_940 , sizeof( struct V_482 * ) , V_941 ) ;
if ( ! V_42 ) {
F_8 ( L_101 , V_34 , V_940 ) ;
return NULL ;
}
for ( V_471 = 0 ; V_471 < V_940 ; V_471 ++ ) {
V_42 [ V_471 ] = F_276 ( V_941 ) ;
if ( ! V_42 [ V_471 ] ) {
F_8 ( L_102 , V_34 ) ;
F_579 ( V_42 , V_940 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_582 ( void * V_154 )
{
struct V_928 * V_929 = V_154 ;
struct V_2 * V_2 = V_929 -> args . V_2 ;
struct V_13 * V_14 = F_88 ( V_2 ) ;
T_9 V_942 = F_577 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_579 ( V_929 -> args . V_930 . V_42 , V_942 ) ;
F_583 ( F_76 ( V_2 ) -> V_930 ) ;
F_169 ( V_929 -> args . V_299 ) ;
F_98 ( V_154 ) ;
F_8 ( L_83 , V_34 ) ;
}
struct V_943 *
F_584 ( struct V_928 * V_929 , T_6 V_941 )
{
struct V_2 * V_2 = V_929 -> args . V_2 ;
struct V_13 * V_14 = F_88 ( V_2 ) ;
T_9 V_942 = F_577 ( V_14 ) ;
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_944 ] ,
. V_312 = & V_929 -> args ,
. V_313 = & V_929 -> V_56 ,
. V_314 = V_929 -> V_348 ,
} ;
struct V_162 V_315 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_945 ,
. V_168 = V_929 ,
. V_213 = V_319 ,
} ;
struct V_943 * V_946 = NULL ;
int V_304 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_585 ( F_76 ( V_2 ) -> V_930 ) ;
V_929 -> args . V_930 . V_42 = F_580 ( V_942 , V_941 ) ;
if ( ! V_929 -> args . V_930 . V_42 ) {
F_582 ( V_929 ) ;
return F_45 ( - V_124 ) ;
}
V_929 -> args . V_930 . V_509 = V_942 * V_607 ;
V_929 -> args . V_105 = V_152 ;
V_929 -> V_56 . V_947 = & V_929 -> args . V_930 ;
V_929 -> V_56 . V_159 . V_114 = NULL ;
F_39 ( & V_929 -> args . V_158 , & V_929 -> V_56 . V_159 , 0 ) ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) )
return F_256 ( V_118 ) ;
V_304 = F_109 ( V_118 ) ;
if ( V_304 == 0 )
V_304 = V_118 -> V_147 ;
F_586 ( V_929 -> args . V_299 ,
& V_929 -> args . V_931 ,
& V_929 -> V_56 . V_931 ,
V_304 ) ;
if ( V_304 == 0 && V_929 -> V_56 . V_947 -> V_12 )
V_946 = F_587 ( V_929 ) ;
F_73 ( V_118 ) ;
F_8 ( L_16 , V_34 , V_304 ) ;
if ( V_304 )
return F_45 ( V_304 ) ;
return V_946 ;
}
static void
F_588 ( struct V_117 * V_118 , void * V_154 )
{
struct V_948 * V_949 = V_154 ;
F_8 ( L_11 , V_34 ) ;
F_62 ( V_949 -> V_63 -> V_86 ,
& V_949 -> args . V_158 ,
& V_949 -> V_56 . V_159 ,
V_118 ) ;
}
static void F_589 ( struct V_117 * V_118 , void * V_154 )
{
struct V_948 * V_949 = V_154 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_54 ( V_118 , & V_949 -> V_56 . V_159 ) )
return;
V_14 = F_88 ( V_949 -> args . V_2 ) ;
switch ( V_118 -> V_147 ) {
default:
V_118 -> V_147 = 0 ;
case 0 :
break;
case - V_89 :
if ( F_247 ( V_118 , V_14 , NULL , NULL ) != - V_128 )
break;
F_58 ( V_118 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_590 ( void * V_154 )
{
struct V_948 * V_949 = V_154 ;
struct V_932 * V_933 = V_949 -> args . V_930 ;
F_8 ( L_11 , V_34 ) ;
F_35 ( & V_933 -> V_950 -> V_173 ) ;
if ( V_949 -> V_56 . V_951 )
F_591 ( V_933 , & V_949 -> V_56 . V_249 , true ) ;
F_592 ( V_933 ) ;
F_126 ( V_952 , & V_933 -> V_953 ) ;
F_593 ( & F_88 ( V_933 -> V_950 ) -> V_954 ) ;
V_933 -> V_955 -- ;
F_37 ( & V_933 -> V_950 -> V_173 ) ;
F_583 ( V_949 -> args . V_930 ) ;
F_438 ( V_949 -> V_2 ) ;
F_98 ( V_154 ) ;
F_8 ( L_83 , V_34 ) ;
}
int F_594 ( struct V_948 * V_949 , bool V_956 )
{
struct V_117 * V_118 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_957 ] ,
. V_312 = & V_949 -> args ,
. V_313 = & V_949 -> V_56 ,
. V_314 = V_949 -> V_348 ,
} ;
struct V_162 V_315 = {
. V_164 = F_88 ( V_949 -> args . V_2 ) -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_958 ,
. V_168 = V_949 ,
} ;
int V_304 = 0 ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_956 ) {
V_949 -> V_2 = F_441 ( V_949 -> args . V_2 ) ;
if ( ! V_949 -> V_2 ) {
F_590 ( V_949 ) ;
return - V_128 ;
}
V_315 . V_213 |= V_319 ;
}
F_39 ( & V_949 -> args . V_158 , & V_949 -> V_56 . V_159 , 1 ) ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) )
return F_72 ( V_118 ) ;
if ( V_956 )
V_304 = V_118 -> V_147 ;
F_595 ( V_949 -> args . V_2 , V_304 ) ;
F_8 ( L_16 , V_34 , V_304 ) ;
F_73 ( V_118 ) ;
return V_304 ;
}
static int
F_596 ( struct V_13 * V_14 ,
struct V_959 * V_960 ,
struct V_314 * V_348 )
{
struct V_961 args = {
. V_960 = V_960 ,
. V_962 = V_963 |
V_964 ,
} ;
struct V_965 V_56 = {
. V_960 = V_960 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_966 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
int V_304 ;
F_8 ( L_11 , V_34 ) ;
V_304 = F_74 ( V_14 -> V_90 , V_14 , & V_161 , & args . V_158 , & V_56 . V_159 , 0 ) ;
if ( V_56 . V_967 & ~ args . V_962 )
F_8 ( L_103 , V_34 ) ;
if ( V_56 . V_967 != args . V_962 )
V_960 -> V_968 = 1 ;
F_8 ( L_16 , V_34 , V_304 ) ;
return V_304 ;
}
int F_597 ( struct V_13 * V_14 ,
struct V_959 * V_960 ,
struct V_314 * V_348 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_21 ( V_14 ,
F_596 ( V_14 , V_960 , V_348 ) ,
& V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_598 ( struct V_117 * V_118 , void * V_154 )
{
struct V_969 * V_156 = V_154 ;
struct V_13 * V_14 = F_88 ( V_156 -> args . V_2 ) ;
struct V_131 * V_132 = F_65 ( V_14 ) ;
F_62 ( V_132 ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static void
F_599 ( struct V_117 * V_118 , void * V_154 )
{
struct V_969 * V_156 = V_154 ;
struct V_13 * V_14 = F_88 ( V_156 -> args . V_2 ) ;
if ( ! F_54 ( V_118 , & V_156 -> V_56 . V_159 ) )
return;
switch ( V_118 -> V_147 ) {
case - V_70 :
case - V_970 :
case - V_971 :
case - V_88 :
V_118 -> V_147 = 0 ;
case 0 :
break;
default:
if ( F_247 ( V_118 , V_14 , NULL , NULL ) == - V_128 ) {
F_58 ( V_118 ) ;
return;
}
}
}
static void F_600 ( void * V_154 )
{
struct V_969 * V_156 = V_154 ;
F_601 ( V_156 ) ;
F_442 ( V_156 -> args . V_2 ,
V_156 -> V_56 . V_386 ) ;
F_211 ( V_156 -> V_348 ) ;
F_438 ( V_156 -> V_2 ) ;
F_98 ( V_156 ) ;
}
int
F_602 ( struct V_969 * V_156 , bool V_956 )
{
struct V_160 V_161 = {
. V_309 = & V_310 [ V_972 ] ,
. V_312 = & V_156 -> args ,
. V_313 = & V_156 -> V_56 ,
. V_314 = V_156 -> V_348 ,
} ;
struct V_162 V_315 = {
. V_118 = & V_156 -> V_118 ,
. V_164 = F_295 ( V_156 -> args . V_2 ) ,
. V_160 = & V_161 ,
. V_165 = & V_973 ,
. V_168 = V_156 ,
} ;
struct V_117 * V_118 ;
int V_304 = 0 ;
F_8 ( L_104
L_105 ,
V_156 -> V_118 . V_974 , V_956 ,
V_156 -> args . V_975 ,
V_156 -> args . V_2 -> V_976 ) ;
if ( ! V_956 ) {
V_156 -> V_2 = F_441 ( V_156 -> args . V_2 ) ;
if ( V_156 -> V_2 == NULL ) {
F_600 ( V_156 ) ;
return - V_128 ;
}
V_315 . V_213 = V_319 ;
}
F_39 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 1 ) ;
V_118 = F_71 ( & V_315 ) ;
if ( F_44 ( V_118 ) )
return F_72 ( V_118 ) ;
if ( V_956 )
V_304 = V_118 -> V_147 ;
F_603 ( V_156 -> args . V_2 , V_304 ) ;
F_8 ( L_106 , V_34 , V_304 ) ;
F_73 ( V_118 ) ;
return V_304 ;
}
static int
F_604 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_458 ,
struct V_793 * V_474 , bool V_794 )
{
struct V_977 args = {
. V_978 = V_979 ,
} ;
struct V_796 V_56 = {
. V_474 = V_474 ,
} ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_980 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
} ;
struct V_54 * V_55 = V_14 -> V_90 ;
struct V_314 * V_348 = NULL ;
int V_304 ;
if ( V_794 ) {
V_55 = V_14 -> V_62 -> V_100 ;
V_348 = F_518 ( V_14 -> V_62 ) ;
V_161 . V_314 = V_348 ;
}
F_8 ( L_11 , V_34 ) ;
V_304 = F_74 ( V_55 , V_14 , & V_161 , & args . V_158 ,
& V_56 . V_159 , 0 ) ;
F_8 ( L_16 , V_34 , V_304 ) ;
if ( V_348 )
F_211 ( V_348 ) ;
return V_304 ;
}
static int
F_605 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_458 , struct V_793 * V_474 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_33 ( V_14 -> V_62 ) )
V_8 = F_604 ( V_14 , V_424 , V_458 ,
V_474 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_604 ( V_14 , V_424 , V_458 ,
V_474 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_981 :
goto V_129;
default:
V_8 = F_21 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_66 );
V_129:
return V_8 ;
}
static int
F_606 ( struct V_13 * V_14 , struct V_423 * V_424 ,
struct V_457 * V_458 )
{
int V_8 ;
struct V_482 * V_482 ;
T_4 V_99 = V_982 ;
struct V_793 * V_474 ;
struct V_983 * V_984 ;
int V_471 ;
V_482 = F_276 ( V_377 ) ;
if ( ! V_482 ) {
V_8 = - V_124 ;
goto V_129;
}
V_474 = F_391 ( V_482 ) ;
V_8 = F_605 ( V_14 , V_424 , V_458 , V_474 ) ;
if ( V_8 == - V_22 || V_8 == - V_981 ) {
V_8 = F_267 ( V_14 , V_424 , V_458 ) ;
goto V_985;
}
if ( V_8 )
goto V_985;
for ( V_471 = 0 ; V_471 < V_474 -> V_986 ; V_471 ++ ) {
V_984 = & V_474 -> V_474 [ V_471 ] ;
switch ( V_984 -> V_99 ) {
case V_470 :
case V_469 :
case V_987 :
V_99 = F_607 ( V_984 -> V_99 ,
& V_984 -> V_988 ) ;
break;
default:
V_99 = V_982 ;
break;
}
if ( ! F_608 ( & V_14 -> V_472 , V_99 ) )
V_99 = V_982 ;
if ( V_99 != V_982 ) {
V_8 = F_265 ( V_14 , V_424 ,
V_458 , V_99 ) ;
if ( ! V_8 )
break;
}
}
if ( V_99 == V_982 )
V_8 = - V_24 ;
V_985:
F_405 ( V_482 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_129:
return V_8 ;
}
static int F_609 ( struct V_13 * V_14 ,
T_8 * V_249 ,
struct V_314 * V_348 )
{
int V_304 ;
struct V_989 args = {
. V_249 = V_249 ,
} ;
struct V_990 V_56 ;
struct V_160 V_161 = {
. V_309 = & V_310 [ V_991 ] ,
. V_312 = & args ,
. V_313 = & V_56 ,
. V_314 = V_348 ,
} ;
struct V_54 * V_164 = V_14 -> V_90 ;
F_254 ( V_14 -> V_62 , V_844 ,
& V_164 , & V_161 ) ;
F_8 ( L_107 , V_249 ) ;
F_39 ( & args . V_158 , & V_56 . V_159 , 0 ) ;
F_40 ( & args . V_158 ) ;
V_304 = F_70 ( V_164 , V_14 , & V_161 ,
& args . V_158 , & V_56 . V_159 ) ;
if ( V_304 != V_361 ) {
F_8 ( L_108 , V_304 ) ;
return V_304 ;
}
F_8 ( L_109 , - V_56 . V_304 ) ;
return - V_56 . V_304 ;
}
static int F_208 ( struct V_13 * V_14 ,
T_8 * V_249 ,
struct V_314 * V_348 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_609 ( V_14 , V_249 , V_348 ) ;
if ( V_8 != - V_89 )
break;
F_21 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_66 );
return V_8 ;
}
static void F_610 ( struct V_117 * V_118 , void * V_154 )
{
struct V_992 * V_156 = V_154 ;
F_62 ( F_65 ( V_156 -> V_14 ) ,
& V_156 -> args . V_158 ,
& V_156 -> V_56 . V_159 ,
V_118 ) ;
}
static void F_611 ( struct V_117 * V_118 , void * V_154 )
{
struct V_992 * V_156 = V_154 ;
F_54 ( V_118 , & V_156 -> V_56 . V_159 ) ;
switch ( V_118 -> V_147 ) {
case - V_89 :
if ( F_247 ( V_118 , V_156 -> V_14 , NULL , NULL ) == - V_128 )
F_58 ( V_118 ) ;
}
}
static void F_612 ( void * V_154 )
{
F_98 ( V_154 ) ;
}
static struct V_117 * F_613 ( struct V_13 * V_14 ,
T_8 * V_249 ,
struct V_314 * V_348 ,
bool V_993 )
{
struct V_160 V_161 = {
. V_309 = & V_310 [ V_994 ] ,
. V_314 = V_348 ,
} ;
struct V_162 V_163 = {
. V_164 = V_14 -> V_90 ,
. V_160 = & V_161 ,
. V_165 = & V_995 ,
. V_213 = V_319 ,
} ;
struct V_992 * V_156 ;
F_254 ( V_14 -> V_62 , V_844 ,
& V_163 . V_164 , & V_161 ) ;
F_8 ( L_110 , V_249 ) ;
V_156 = F_277 ( sizeof( * V_156 ) , V_301 ) ;
if ( ! V_156 )
return F_45 ( - V_124 ) ;
V_156 -> V_14 = V_14 ;
F_127 ( & V_156 -> args . V_249 , V_249 ) ;
V_163 . V_168 = V_156 ;
V_161 . V_312 = & V_156 -> args ;
V_161 . V_313 = & V_156 -> V_56 ;
F_39 ( & V_156 -> args . V_158 , & V_156 -> V_56 . V_159 , 0 ) ;
if ( V_993 )
F_40 ( & V_156 -> args . V_158 ) ;
return F_71 ( & V_163 ) ;
}
static int F_210 ( struct V_13 * V_14 ,
T_8 * V_249 ,
struct V_314 * V_348 )
{
struct V_117 * V_118 ;
int V_51 ;
V_118 = F_613 ( V_14 , V_249 , V_348 , true ) ;
if ( F_44 ( V_118 ) )
return F_72 ( V_118 ) ;
V_51 = F_110 ( V_118 ) ;
if ( ! V_51 )
V_51 = V_118 -> V_147 ;
F_73 ( V_118 ) ;
return V_51 ;
}
static void
F_614 ( struct V_13 * V_14 , struct V_279 * V_280 )
{
struct V_117 * V_118 ;
struct V_314 * V_348 = V_280 -> V_281 -> V_224 -> V_288 ;
V_118 = F_613 ( V_14 , & V_280 -> V_283 , V_348 , false ) ;
F_495 ( V_14 , V_280 ) ;
if ( F_44 ( V_118 ) )
return;
F_73 ( V_118 ) ;
}
static bool F_615 ( const T_8 * V_996 ,
const T_8 * V_997 )
{
if ( memcmp ( V_996 -> V_998 , V_997 -> V_998 , sizeof( V_996 -> V_998 ) ) != 0 )
return false ;
if ( V_996 -> V_203 == V_997 -> V_203 )
return true ;
if ( V_996 -> V_203 == 0 || V_997 -> V_203 == 0 )
return true ;
return false ;
}
static bool F_616 ( const T_8 * V_996 ,
const T_8 * V_997 )
{
return F_137 ( V_996 , V_997 ) ;
}
static struct V_217 *
F_617 ( struct V_219 * V_999 , T_6 V_1000 )
{
return NULL ;
}
