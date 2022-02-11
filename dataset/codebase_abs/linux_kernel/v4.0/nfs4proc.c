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
V_41 = F_12 ( V_41 , F_13 ( V_4 -> V_46 ) ) ;
}
* V_41 ++ = V_43 ;
* V_41 ++ = V_44 ;
* V_41 ++ = V_47 ;
* V_41 ++ = V_47 ;
memcpy ( V_41 , L_3 , 4 ) ;
V_41 ++ ;
* V_41 ++ = V_43 ;
* V_41 ++ = F_11 ( V_45 ) ;
* V_41 ++ = F_11 ( 8 ) ;
V_41 = F_12 ( V_41 , F_13 ( V_4 -> V_48 -> V_46 ) ) ;
V_39 -> V_49 = ( char * ) V_41 - ( char * ) V_40 ;
V_39 -> V_50 -= V_39 -> V_49 ;
F_14 ( V_40 ) ;
}
static long F_15 ( long * V_51 )
{
long V_52 ;
if ( ! V_51 )
return V_53 ;
if ( * V_51 <= 0 )
* V_51 = V_54 ;
if ( * V_51 > V_53 )
* V_51 = V_53 ;
V_52 = * V_51 ;
* V_51 <<= 1 ;
return V_52 ;
}
static int F_16 ( struct V_55 * V_56 , long * V_51 )
{
int V_57 = 0 ;
F_17 () ;
F_18 (
F_15 ( V_51 ) ) ;
if ( F_19 ( V_58 ) )
V_57 = - V_59 ;
return V_57 ;
}
int F_20 ( struct V_13 * V_14 , int V_60 , struct V_61 * V_62 )
{
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_65 * V_66 = V_62 -> V_66 ;
struct V_2 * V_2 = V_62 -> V_2 ;
int V_52 = V_60 ;
V_62 -> V_67 = 0 ;
switch( V_60 ) {
case 0 :
return 0 ;
case - V_68 :
if ( V_2 && F_21 ( V_2 , V_69 ) ) {
F_22 ( V_2 ) ;
V_62 -> V_67 = 1 ;
return 0 ;
}
if ( V_66 == NULL )
break;
V_52 = F_23 ( V_14 , V_66 ) ;
if ( V_52 < 0 )
break;
goto V_70;
case - V_71 :
case - V_72 :
case - V_73 :
if ( V_66 == NULL )
break;
V_52 = F_23 ( V_14 , V_66 ) ;
if ( V_52 < 0 )
break;
goto V_70;
case - V_74 :
if ( V_66 != NULL ) {
V_52 = F_23 ( V_14 , V_66 ) ;
if ( V_52 < 0 )
break;
}
case - V_75 :
case - V_76 :
F_24 ( V_64 ) ;
goto V_70;
case - V_77 :
V_52 = F_25 ( V_14 ) ;
if ( V_52 < 0 )
break;
goto V_70;
case - V_78 :
F_26 ( V_64 ) ;
goto V_70;
#if F_27 ( V_79 )
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
F_8 ( L_4 , V_34 ,
V_60 ) ;
F_28 ( V_64 -> V_87 , V_60 ) ;
goto V_70;
#endif
case - V_32 :
if ( V_62 -> V_51 > V_88 ) {
V_52 = - V_33 ;
break;
}
case - V_89 :
case - V_90 :
V_52 = F_16 ( V_14 -> V_91 , & V_62 -> V_51 ) ;
if ( V_52 != 0 )
break;
case - V_92 :
case - V_93 :
V_62 -> V_67 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_94 & V_95 ) {
V_14 -> V_94 &= ~ V_95 ;
V_62 -> V_67 = 1 ;
F_29 ( V_96 L_5
L_6
L_7
L_8 ,
V_14 -> V_63 -> V_97 ) ;
}
}
return F_7 ( V_52 ) ;
V_70:
V_52 = F_30 ( V_64 ) ;
if ( F_31 ( V_98 , & V_14 -> V_99 ) )
return - V_35 ;
if ( V_52 == 0 )
V_62 -> V_67 = 1 ;
return V_52 ;
}
static bool F_32 ( struct V_63 * V_64 )
{
T_4 V_100 = V_64 -> V_101 -> V_102 -> V_103 ;
if ( V_100 == V_104 ||
V_100 == V_105 )
return true ;
return false ;
}
static void F_33 ( struct V_63 * V_64 , unsigned long V_106 )
{
F_34 ( & V_64 -> V_107 ) ;
if ( F_35 ( V_64 -> V_108 , V_106 ) )
V_64 -> V_108 = V_106 ;
F_36 ( & V_64 -> V_107 ) ;
}
static void F_37 ( const struct V_13 * V_14 , unsigned long V_106 )
{
F_33 ( V_14 -> V_63 , V_106 ) ;
}
static void F_38 ( struct V_109 * args ,
struct V_110 * V_57 , int V_111 )
{
args -> V_112 = NULL ;
args -> V_113 = V_111 ;
args -> V_114 = 0 ;
V_57 -> V_115 = NULL ;
}
static void F_39 ( struct V_109 * args )
{
args -> V_114 = 1 ;
}
int F_40 ( struct V_116 * V_117 ,
struct V_109 * args ,
struct V_110 * V_57 ,
struct V_118 * V_119 )
{
struct V_120 * V_121 ;
if ( V_57 -> V_115 != NULL )
goto V_122;
F_34 ( & V_117 -> V_123 ) ;
if ( F_41 ( V_117 ) && ! args -> V_114 )
goto V_124;
V_121 = F_42 ( V_117 ) ;
if ( F_43 ( V_121 ) ) {
if ( V_121 == F_44 ( - V_125 ) )
V_119 -> V_126 = V_88 >> 2 ;
goto V_124;
}
F_36 ( & V_117 -> V_123 ) ;
args -> V_112 = V_121 ;
V_57 -> V_115 = V_121 ;
V_122:
F_45 ( V_119 ) ;
return 0 ;
V_124:
if ( args -> V_114 )
F_46 ( & V_117 -> V_127 , V_119 ,
NULL , V_128 ) ;
else
F_47 ( & V_117 -> V_127 , V_119 , NULL ) ;
F_36 ( & V_117 -> V_123 ) ;
return - V_129 ;
}
static int F_48 ( struct V_118 * V_119 ,
struct V_110 * V_57 )
{
struct V_120 * V_121 = V_57 -> V_115 ;
struct V_116 * V_117 ;
if ( V_121 == NULL )
goto V_130;
V_117 = V_121 -> V_131 ;
F_34 ( & V_117 -> V_123 ) ;
if ( ! F_49 ( V_117 , V_121 ) )
F_50 ( V_117 , V_121 ) ;
F_36 ( & V_117 -> V_123 ) ;
V_57 -> V_115 = NULL ;
V_130:
return 1 ;
}
static void F_51 ( struct V_110 * V_57 )
{
struct V_132 * V_133 ;
struct V_116 * V_117 ;
struct V_120 * V_121 = V_57 -> V_115 ;
bool V_134 = false ;
V_117 = V_121 -> V_131 ;
V_133 = V_117 -> V_133 ;
F_34 ( & V_117 -> V_123 ) ;
if ( V_117 -> V_135 > V_117 -> V_136 )
V_134 = true ;
if ( F_49 ( V_117 , V_121 ) ) {
V_134 = false ;
goto V_137;
}
F_50 ( V_117 , V_121 ) ;
if ( V_117 -> V_135 != V_138 )
V_134 = false ;
V_137:
F_36 ( & V_117 -> V_123 ) ;
V_57 -> V_115 = NULL ;
if ( V_134 )
F_52 ( V_133 -> V_64 ) ;
}
int F_53 ( struct V_118 * V_119 , struct V_110 * V_57 )
{
struct V_132 * V_133 ;
struct V_120 * V_121 = V_57 -> V_115 ;
struct V_63 * V_64 ;
bool V_139 = false ;
int V_52 = 1 ;
if ( V_121 == NULL )
goto V_140;
if ( ! F_54 ( V_119 ) )
goto V_130;
V_133 = V_121 -> V_131 -> V_133 ;
if ( V_121 -> V_139 ) {
V_121 -> V_139 = 0 ;
V_139 = true ;
}
F_55 ( V_133 , V_57 ) ;
switch ( V_57 -> V_141 ) {
case 0 :
++ V_121 -> V_142 ;
V_64 = V_133 -> V_64 ;
F_33 ( V_64 , V_57 -> V_143 ) ;
if ( V_57 -> V_144 != 0 )
F_24 ( V_64 ) ;
F_56 ( V_121 -> V_131 , V_121 , V_57 ) ;
break;
case 1 :
V_121 -> V_139 = 1 ;
goto V_130;
case - V_90 :
F_8 ( L_9 ,
V_34 ,
V_121 -> V_145 ,
V_121 -> V_142 ) ;
goto V_146;
case - V_81 :
goto V_147;
case - V_86 :
if ( V_139 ) {
++ V_121 -> V_142 ;
goto V_147;
}
if ( V_121 -> V_142 != 1 ) {
V_121 -> V_142 = 1 ;
goto V_147;
}
break;
case - V_85 :
++ V_121 -> V_142 ;
goto V_147;
default:
++ V_121 -> V_142 ;
}
V_130:
F_8 ( L_10 , V_34 , V_57 -> V_141 ) ;
F_51 ( V_57 ) ;
V_140:
return V_52 ;
V_147:
if ( F_57 ( V_119 ) ) {
V_119 -> V_148 = 0 ;
V_52 = 0 ;
}
goto V_130;
V_146:
if ( ! F_58 ( V_119 ) )
goto V_130;
F_59 ( V_119 , V_53 ) ;
return 0 ;
}
int F_60 ( struct V_118 * V_119 , struct V_110 * V_57 )
{
if ( V_57 -> V_115 == NULL )
return 1 ;
if ( ! V_57 -> V_115 -> V_131 -> V_133 )
return F_48 ( V_119 , V_57 ) ;
return F_53 ( V_119 , V_57 ) ;
}
int F_61 ( struct V_132 * V_133 ,
struct V_109 * args ,
struct V_110 * V_57 ,
struct V_118 * V_119 )
{
struct V_120 * V_121 ;
struct V_116 * V_117 ;
F_8 ( L_11 , V_34 ) ;
if ( V_57 -> V_115 != NULL )
goto V_149;
V_117 = & V_133 -> V_150 ;
V_119 -> V_126 = 0 ;
F_34 ( & V_117 -> V_123 ) ;
if ( F_31 ( V_151 , & V_117 -> V_152 ) &&
! args -> V_114 ) {
F_8 ( L_12 , V_34 ) ;
goto V_124;
}
V_121 = F_42 ( V_117 ) ;
if ( F_43 ( V_121 ) ) {
if ( V_121 == F_44 ( - V_125 ) )
V_119 -> V_126 = V_88 >> 2 ;
F_8 ( L_13 , V_34 ) ;
goto V_124;
}
F_36 ( & V_117 -> V_123 ) ;
args -> V_112 = V_121 ;
F_8 ( L_14 , V_34 ,
V_121 -> V_145 , V_121 -> V_142 ) ;
V_57 -> V_115 = V_121 ;
V_57 -> V_143 = V_153 ;
V_57 -> V_144 = 0 ;
V_57 -> V_141 = 1 ;
F_62 ( V_133 , args ) ;
V_149:
F_45 ( V_119 ) ;
return 0 ;
V_124:
if ( args -> V_114 )
F_46 ( & V_117 -> V_127 , V_119 ,
NULL , V_128 ) ;
else
F_47 ( & V_117 -> V_127 , V_119 , NULL ) ;
F_36 ( & V_117 -> V_123 ) ;
return - V_129 ;
}
static int F_63 ( const struct V_13 * V_14 ,
struct V_109 * args ,
struct V_110 * V_57 ,
struct V_118 * V_119 )
{
struct V_132 * V_133 = F_64 ( V_14 ) ;
int V_52 = 0 ;
if ( ! V_133 )
return F_40 ( V_14 -> V_63 -> V_154 ,
args , V_57 , V_119 ) ;
F_8 ( L_15 ,
V_34 , V_133 -> V_64 , V_133 , V_57 -> V_115 ?
V_57 -> V_115 -> V_145 : V_138 ) ;
V_52 = F_61 ( V_133 , args , V_57 , V_119 ) ;
F_8 ( L_16 , V_34 , V_52 ) ;
return V_52 ;
}
static void F_65 ( struct V_118 * V_119 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
struct V_132 * V_133 = F_64 ( V_157 -> V_158 ) ;
F_8 ( L_17 , V_34 , V_157 -> V_158 ) ;
F_61 ( V_133 , V_157 -> V_159 , V_157 -> V_160 , V_119 ) ;
}
static void F_66 ( struct V_118 * V_119 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_53 ( V_119 , V_157 -> V_160 ) ;
}
static int F_63 ( const struct V_13 * V_14 ,
struct V_109 * args ,
struct V_110 * V_57 ,
struct V_118 * V_119 )
{
return F_40 ( V_14 -> V_63 -> V_154 ,
args , V_57 , V_119 ) ;
}
int F_60 ( struct V_118 * V_119 ,
struct V_110 * V_57 )
{
return F_48 ( V_119 , V_57 ) ;
}
static void F_67 ( struct V_118 * V_119 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_63 ( V_157 -> V_158 ,
V_157 -> V_159 , V_157 -> V_160 , V_119 ) ;
}
static void F_68 ( struct V_118 * V_119 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_60 ( V_119 , V_157 -> V_160 ) ;
}
static int F_69 ( struct V_55 * V_56 ,
struct V_13 * V_14 ,
struct V_161 * V_162 ,
struct V_109 * args ,
struct V_110 * V_57 )
{
int V_52 ;
struct V_118 * V_119 ;
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_156 V_157 = {
. V_158 = V_14 ,
. V_159 = args ,
. V_160 = V_57 ,
} ;
struct V_163 V_164 = {
. V_165 = V_56 ,
. V_161 = V_162 ,
. V_166 = V_64 -> V_167 -> V_168 ,
. V_169 = & V_157
} ;
V_119 = F_70 ( & V_164 ) ;
if ( F_43 ( V_119 ) )
V_52 = F_71 ( V_119 ) ;
else {
V_52 = V_119 -> V_148 ;
F_72 ( V_119 ) ;
}
return V_52 ;
}
int F_73 ( struct V_55 * V_56 ,
struct V_13 * V_14 ,
struct V_161 * V_162 ,
struct V_109 * args ,
struct V_110 * V_57 ,
int V_111 )
{
F_38 ( args , V_57 , V_111 ) ;
return F_69 ( V_56 , V_14 , V_162 , args , V_57 ) ;
}
static void F_74 ( struct V_2 * V_3 , struct V_170 * V_171 )
{
struct V_172 * V_173 = F_75 ( V_3 ) ;
F_34 ( & V_3 -> V_174 ) ;
V_173 -> V_175 |= V_176 | V_177 ;
if ( ! V_171 -> V_178 || V_171 -> V_179 != V_3 -> V_180 )
F_76 ( V_3 ) ;
V_3 -> V_180 = V_171 -> V_181 ;
V_173 -> V_182 = F_77 () ;
F_78 ( V_3 ) ;
F_36 ( & V_3 -> V_174 ) ;
}
static bool F_79 ( struct V_13 * V_14 ,
int V_8 , struct V_61 * V_62 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_94 & V_183 ) )
return false ;
V_14 -> V_94 &= ~ V_183 ;
V_62 -> V_67 = 1 ;
return true ;
}
static T_1
F_80 ( struct V_13 * V_14 ,
T_5 V_184 , int V_185 )
{
T_1 V_57 = 0 ;
switch ( V_184 & ( V_69 | V_186 ) ) {
case V_69 :
V_57 = V_187 ;
break;
case V_186 :
V_57 = V_188 ;
break;
case V_69 | V_186 :
V_57 = V_189 ;
}
if ( ! ( V_14 -> V_94 & V_183 ) )
goto V_130;
if ( V_185 & V_190 )
V_57 |= V_191 ;
V_130:
return V_57 ;
}
static enum V_192
F_81 ( struct V_13 * V_14 ,
enum V_192 V_193 )
{
if ( V_14 -> V_94 & V_183 )
return V_193 ;
switch ( V_193 ) {
default:
return V_193 ;
case V_194 :
return V_195 ;
case V_196 :
return V_197 ;
case V_198 :
return V_199 ;
}
}
static void F_82 ( struct V_200 * V_41 )
{
V_41 -> V_201 . V_202 = & V_41 -> V_202 ;
V_41 -> V_201 . V_203 = V_41 -> V_203 ;
V_41 -> V_201 . V_204 = V_41 -> V_205 . V_204 ;
V_41 -> V_206 . V_204 = V_41 -> V_207 . V_204 ;
V_41 -> V_201 . V_14 = V_41 -> V_205 . V_14 ;
V_41 -> V_201 . V_208 = V_41 -> V_205 . V_209 ;
F_83 ( & V_41 -> V_202 ) ;
F_84 ( & V_41 -> V_202 , & V_41 -> V_210 , & V_41 -> V_211 ) ;
}
static struct V_200 * F_85 ( struct V_4 * V_4 ,
struct V_212 * V_213 , T_5 V_184 , int V_214 ,
const struct V_5 * V_215 ,
struct V_1 * V_7 ,
enum V_192 V_193 ,
T_6 V_216 )
{
struct V_4 * V_217 = F_86 ( V_4 ) ;
struct V_2 * V_3 = V_217 -> V_46 ;
struct V_13 * V_14 = F_87 ( V_3 ) ;
struct V_218 * ( * V_219 ) ( struct V_220 * , T_6 ) ;
struct V_200 * V_41 ;
V_41 = F_88 ( sizeof( * V_41 ) , V_216 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_203 = F_89 ( V_14 , V_216 ) ;
if ( F_43 ( V_41 -> V_203 ) )
goto V_221;
V_219 = V_14 -> V_63 -> V_167 -> V_219 ;
V_41 -> V_205 . V_204 = V_219 ( & V_213 -> V_222 , V_216 ) ;
if ( F_43 ( V_41 -> V_205 . V_204 ) )
goto V_223;
F_90 ( V_4 -> V_224 ) ;
V_41 -> V_4 = F_91 ( V_4 ) ;
V_41 -> V_3 = V_217 ;
V_41 -> V_225 = V_213 ;
F_92 ( & V_213 -> V_226 ) ;
V_41 -> V_205 . V_227 = V_214 ;
V_41 -> V_205 . V_184 = V_184 & ( V_69 | V_186 ) ;
V_41 -> V_205 . V_228 = F_80 ( V_14 ,
V_184 , V_214 ) ;
if ( ! ( V_214 & V_229 ) ) {
V_41 -> V_205 . V_209 = V_230 | V_231 |
V_232 | V_233 ;
}
V_41 -> V_205 . V_234 = V_14 -> V_63 -> V_235 ;
V_41 -> V_205 . V_236 . V_237 = F_93 ( V_213 -> V_222 . V_237 ) ;
V_41 -> V_205 . V_236 . V_238 = V_213 -> V_222 . V_239 ;
V_41 -> V_205 . V_240 = & V_4 -> V_11 ;
V_41 -> V_205 . V_14 = V_14 ;
V_41 -> V_205 . V_241 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_205 . V_242 = & V_243 [ 0 ] ;
V_41 -> V_205 . V_7 = V_7 ;
V_41 -> V_205 . V_193 = F_81 ( V_14 , V_193 ) ;
switch ( V_41 -> V_205 . V_193 ) {
case V_195 :
case V_197 :
case V_199 :
V_41 -> V_205 . V_244 = F_94 ( V_3 ) ;
break;
case V_245 :
case V_194 :
case V_196 :
case V_198 :
V_41 -> V_205 . V_244 = F_94 ( V_4 -> V_46 ) ;
}
if ( V_215 != NULL && V_215 -> V_246 != 0 ) {
T_7 V_247 [ 2 ] ;
V_41 -> V_205 . V_248 . V_215 = & V_41 -> V_215 ;
memcpy ( & V_41 -> V_215 , V_215 , sizeof( V_41 -> V_215 ) ) ;
V_247 [ 0 ] = V_153 ;
V_247 [ 1 ] = V_58 -> V_249 ;
memcpy ( V_41 -> V_205 . V_248 . V_37 . V_157 , V_247 ,
sizeof( V_41 -> V_205 . V_248 . V_37 . V_157 ) ) ;
}
V_41 -> V_207 . V_244 = & V_41 -> V_201 . V_244 ;
V_41 -> V_207 . V_250 = & V_41 -> V_201 . V_250 ;
V_41 -> V_207 . V_204 = V_41 -> V_205 . V_204 ;
F_82 ( V_41 ) ;
F_95 ( & V_41 -> V_251 ) ;
return V_41 ;
V_223:
F_96 ( V_41 -> V_203 ) ;
V_221:
F_97 ( V_41 ) ;
V_8:
F_98 ( V_217 ) ;
return NULL ;
}
static void F_99 ( struct V_251 * V_251 )
{
struct V_200 * V_41 = F_100 ( V_251 ,
struct V_200 , V_251 ) ;
struct V_252 * V_253 = V_41 -> V_4 -> V_224 ;
F_101 ( V_41 -> V_205 . V_204 ) ;
if ( V_41 -> V_66 != NULL )
F_102 ( V_41 -> V_66 ) ;
F_103 ( V_41 -> V_225 ) ;
F_96 ( V_41 -> V_203 ) ;
F_98 ( V_41 -> V_3 ) ;
F_98 ( V_41 -> V_4 ) ;
F_104 ( V_253 ) ;
F_105 ( & V_41 -> V_202 ) ;
F_97 ( V_41 -> V_202 . V_254 ) ;
F_97 ( V_41 ) ;
}
static void F_106 ( struct V_200 * V_41 )
{
if ( V_41 != NULL )
F_107 ( & V_41 -> V_251 , F_99 ) ;
}
static int F_108 ( struct V_118 * V_119 )
{
int V_52 ;
V_52 = F_109 ( V_119 ) ;
return V_52 ;
}
static int F_110 ( struct V_65 * V_66 , T_5 V_255 , int V_256 )
{
int V_52 = 0 ;
if ( V_256 & ( V_229 | V_257 ) )
goto V_130;
switch ( V_255 & ( V_69 | V_186 ) ) {
case V_69 :
V_52 |= F_31 ( V_258 , & V_66 -> V_214 ) != 0
&& V_66 -> V_259 != 0 ;
break;
case V_186 :
V_52 |= F_31 ( V_260 , & V_66 -> V_214 ) != 0
&& V_66 -> V_261 != 0 ;
break;
case V_69 | V_186 :
V_52 |= F_31 ( V_262 , & V_66 -> V_214 ) != 0
&& V_66 -> V_263 != 0 ;
}
V_130:
return V_52 ;
}
static int F_111 ( struct V_264 * V_265 , T_5 V_184 )
{
if ( V_265 == NULL )
return 0 ;
if ( ( V_265 -> type & V_184 ) != V_184 )
return 0 ;
if ( F_31 ( V_266 , & V_265 -> V_214 ) )
return 0 ;
F_112 ( V_265 ) ;
return 1 ;
}
static void F_113 ( struct V_65 * V_66 , T_5 V_184 )
{
switch ( V_184 ) {
case V_186 :
V_66 -> V_261 ++ ;
break;
case V_69 :
V_66 -> V_259 ++ ;
break;
case V_69 | V_186 :
V_66 -> V_263 ++ ;
}
F_114 ( V_66 , V_66 -> V_66 | V_184 ) ;
}
static void F_115 ( struct V_65 * V_66 )
{
struct V_63 * V_64 = V_66 -> V_225 -> V_267 -> V_63 ;
bool V_268 = false ;
if ( F_116 ( V_258 , & V_66 -> V_214 ) && V_66 -> V_259 )
V_268 = true ;
if ( F_116 ( V_260 , & V_66 -> V_214 ) && V_66 -> V_261 )
V_268 = true ;
if ( F_116 ( V_262 , & V_66 -> V_214 ) && V_66 -> V_263 )
V_268 = true ;
if ( V_268 )
F_117 ( V_64 , V_66 ) ;
}
static bool F_118 ( struct V_65 * V_66 ,
T_8 * V_250 )
{
if ( F_119 ( V_269 , & V_66 -> V_214 ) == 0 )
return true ;
if ( ! F_120 ( V_250 , & V_66 -> V_270 ) ) {
F_115 ( V_66 ) ;
return true ;
}
if ( F_121 ( V_250 , & V_66 -> V_270 ) )
return true ;
return false ;
}
static void F_122 ( struct V_65 * V_66 )
{
if ( V_66 -> V_261 )
F_123 ( V_260 , & V_66 -> V_214 ) ;
if ( V_66 -> V_259 )
F_123 ( V_258 , & V_66 -> V_214 ) ;
if ( V_66 -> V_263 )
F_123 ( V_262 , & V_66 -> V_214 ) ;
}
static void F_124 ( struct V_65 * V_66 ,
T_8 * V_250 , T_5 V_184 )
{
F_125 ( V_262 , & V_66 -> V_214 ) ;
switch ( V_184 & ( V_69 | V_186 ) ) {
case V_186 :
F_125 ( V_258 , & V_66 -> V_214 ) ;
break;
case V_69 :
F_125 ( V_260 , & V_66 -> V_214 ) ;
break;
case 0 :
F_125 ( V_258 , & V_66 -> V_214 ) ;
F_125 ( V_260 , & V_66 -> V_214 ) ;
F_125 ( V_269 , & V_66 -> V_214 ) ;
}
if ( V_250 == NULL )
return;
if ( ! F_120 ( V_250 , & V_66 -> V_270 ) ||
! F_121 ( V_250 , & V_66 -> V_270 ) ) {
F_122 ( V_66 ) ;
return;
}
if ( F_31 ( V_271 , & V_66 -> V_214 ) == 0 )
F_126 ( & V_66 -> V_250 , V_250 ) ;
F_126 ( & V_66 -> V_270 , V_250 ) ;
}
static void F_127 ( struct V_65 * V_66 , T_8 * V_250 , T_5 V_184 )
{
F_128 ( & V_66 -> V_272 ) ;
F_124 ( V_66 , V_250 , V_184 ) ;
F_129 ( & V_66 -> V_272 ) ;
if ( F_31 ( V_273 , & V_66 -> V_214 ) )
F_130 ( V_66 -> V_225 -> V_267 -> V_63 ) ;
}
static void F_131 ( struct V_65 * V_66 , T_8 * V_250 , T_5 V_184 )
{
switch ( V_184 ) {
case V_69 :
F_123 ( V_258 , & V_66 -> V_214 ) ;
break;
case V_186 :
F_123 ( V_260 , & V_66 -> V_214 ) ;
break;
case V_69 | V_186 :
F_123 ( V_262 , & V_66 -> V_214 ) ;
}
if ( ! F_118 ( V_66 , V_250 ) )
return;
if ( F_31 ( V_271 , & V_66 -> V_214 ) == 0 )
F_126 ( & V_66 -> V_250 , V_250 ) ;
F_126 ( & V_66 -> V_270 , V_250 ) ;
}
static void F_132 ( struct V_65 * V_66 , T_8 * V_270 , const T_8 * V_274 , T_5 V_184 )
{
F_128 ( & V_66 -> V_272 ) ;
if ( V_274 != NULL ) {
F_126 ( & V_66 -> V_250 , V_274 ) ;
F_123 ( V_271 , & V_66 -> V_214 ) ;
}
if ( V_270 != NULL )
F_131 ( V_66 , V_270 , V_184 ) ;
F_129 ( & V_66 -> V_272 ) ;
F_34 ( & V_66 -> V_225 -> V_275 ) ;
F_113 ( V_66 , V_184 ) ;
F_36 ( & V_66 -> V_225 -> V_275 ) ;
}
static int F_133 ( struct V_65 * V_66 , T_8 * V_270 , T_8 * V_265 , T_5 V_184 )
{
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_264 * V_276 ;
int V_52 = 0 ;
V_184 &= ( V_69 | V_186 ) ;
F_134 () ;
V_276 = F_135 ( V_173 -> V_265 ) ;
if ( V_276 == NULL )
goto V_277;
F_34 ( & V_276 -> V_278 ) ;
if ( F_135 ( V_173 -> V_265 ) != V_276 ||
F_31 ( V_266 , & V_276 -> V_214 ) ||
( V_276 -> type & V_184 ) != V_184 )
goto V_279;
if ( V_265 == NULL )
V_265 = & V_276 -> V_250 ;
else if ( ! F_136 ( & V_276 -> V_250 , V_265 ) )
goto V_279;
F_112 ( V_276 ) ;
F_132 ( V_66 , V_270 , & V_276 -> V_250 , V_184 ) ;
V_52 = 1 ;
V_279:
F_36 ( & V_276 -> V_278 ) ;
V_277:
F_137 () ;
if ( ! V_52 && V_270 != NULL ) {
F_132 ( V_66 , V_270 , NULL , V_184 ) ;
V_52 = 1 ;
}
if ( F_31 ( V_273 , & V_66 -> V_214 ) )
F_130 ( V_66 -> V_225 -> V_267 -> V_63 ) ;
return V_52 ;
}
static bool F_138 ( struct V_280 * V_281 ,
const T_8 * V_250 )
{
struct V_65 * V_66 = V_281 -> V_282 ;
bool V_52 = false ;
F_34 ( & V_66 -> V_283 ) ;
if ( ! F_120 ( V_250 , & V_281 -> V_284 ) )
goto V_285;
if ( ! F_121 ( V_250 , & V_281 -> V_284 ) )
goto V_285;
F_126 ( & V_281 -> V_284 , V_250 ) ;
V_52 = true ;
V_285:
F_36 ( & V_66 -> V_283 ) ;
return V_52 ;
}
static void F_139 ( struct V_2 * V_2 , T_5 V_184 )
{
struct V_264 * V_265 ;
F_134 () ;
V_265 = F_135 ( F_75 ( V_2 ) -> V_265 ) ;
if ( V_265 == NULL || ( V_265 -> type & V_184 ) == V_184 ) {
F_137 () ;
return;
}
F_137 () ;
F_22 ( V_2 ) ;
}
static struct V_65 * F_140 ( struct V_200 * V_286 )
{
struct V_65 * V_66 = V_286 -> V_66 ;
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_264 * V_265 ;
int V_256 = V_286 -> V_205 . V_227 ;
T_5 V_184 = V_286 -> V_205 . V_184 ;
T_8 V_250 ;
int V_52 = - V_129 ;
for (; ; ) {
F_34 ( & V_66 -> V_225 -> V_275 ) ;
if ( F_110 ( V_66 , V_184 , V_256 ) ) {
F_113 ( V_66 , V_184 ) ;
F_36 ( & V_66 -> V_225 -> V_275 ) ;
goto V_287;
}
F_36 ( & V_66 -> V_225 -> V_275 ) ;
F_134 () ;
V_265 = F_135 ( V_173 -> V_265 ) ;
if ( ! F_111 ( V_265 , V_184 ) ) {
F_137 () ;
break;
}
F_126 ( & V_250 , & V_265 -> V_250 ) ;
F_137 () ;
F_141 ( V_286 -> V_205 . V_204 ) ;
if ( ! V_286 -> V_288 ) {
V_52 = F_142 ( V_66 -> V_2 , V_66 -> V_225 -> V_289 , V_256 ) ;
if ( V_52 != 0 )
goto V_130;
}
V_52 = - V_129 ;
if ( F_133 ( V_66 , NULL , & V_250 , V_184 ) )
goto V_287;
}
V_130:
return F_44 ( V_52 ) ;
V_287:
F_92 ( & V_66 -> V_50 ) ;
return V_66 ;
}
static void
F_143 ( struct V_200 * V_157 , struct V_65 * V_66 )
{
struct V_63 * V_64 = F_87 ( V_66 -> V_2 ) -> V_63 ;
struct V_264 * V_265 ;
int V_290 = 0 ;
F_134 () ;
V_265 = F_135 ( F_75 ( V_66 -> V_2 ) -> V_265 ) ;
if ( V_265 )
V_290 = V_265 -> V_214 ;
F_137 () ;
if ( V_157 -> V_205 . V_193 == V_197 ) {
F_144 ( L_18
L_19
L_20 ,
V_64 -> V_97 ) ;
} else if ( ( V_290 & 1UL << V_291 ) == 0 )
F_145 ( V_66 -> V_2 ,
V_157 -> V_225 -> V_289 ,
& V_157 -> V_201 ) ;
else
F_146 ( V_66 -> V_2 ,
V_157 -> V_225 -> V_289 ,
& V_157 -> V_201 ) ;
}
static struct V_65 *
F_147 ( struct V_200 * V_157 )
{
struct V_2 * V_2 = V_157 -> V_66 -> V_2 ;
struct V_65 * V_66 = V_157 -> V_66 ;
int V_52 ;
if ( ! V_157 -> V_292 ) {
if ( V_157 -> V_293 ) {
V_52 = V_157 -> V_293 ;
goto V_8;
}
goto V_294;
}
V_52 = F_148 ( V_2 , & V_157 -> V_202 ) ;
if ( V_52 )
goto V_8;
if ( V_157 -> V_201 . V_295 != 0 )
F_143 ( V_157 , V_66 ) ;
V_294:
F_133 ( V_66 , & V_157 -> V_201 . V_250 , NULL ,
V_157 -> V_205 . V_184 ) ;
F_92 ( & V_66 -> V_50 ) ;
return V_66 ;
V_8:
return F_44 ( V_52 ) ;
}
static struct V_65 *
F_149 ( struct V_200 * V_157 )
{
struct V_2 * V_2 ;
struct V_65 * V_66 = NULL ;
int V_52 ;
if ( ! V_157 -> V_292 ) {
V_66 = F_140 ( V_157 ) ;
goto V_130;
}
V_52 = - V_129 ;
if ( ! ( V_157 -> V_202 . V_296 & V_297 ) )
goto V_8;
V_2 = F_150 ( V_157 -> V_3 -> V_224 , & V_157 -> V_201 . V_244 , & V_157 -> V_202 , V_157 -> V_203 ) ;
V_52 = F_71 ( V_2 ) ;
if ( F_43 ( V_2 ) )
goto V_8;
V_52 = - V_125 ;
V_66 = F_151 ( V_2 , V_157 -> V_225 ) ;
if ( V_66 == NULL )
goto V_298;
if ( V_157 -> V_201 . V_295 != 0 )
F_143 ( V_157 , V_66 ) ;
F_133 ( V_66 , & V_157 -> V_201 . V_250 , NULL ,
V_157 -> V_205 . V_184 ) ;
F_152 ( V_2 ) ;
V_130:
F_141 ( V_157 -> V_205 . V_204 ) ;
return V_66 ;
V_298:
F_152 ( V_2 ) ;
V_8:
return F_44 ( V_52 ) ;
}
static struct V_65 *
F_153 ( struct V_200 * V_157 )
{
if ( V_157 -> V_205 . V_193 == V_245 )
return F_147 ( V_157 ) ;
return F_149 ( V_157 ) ;
}
static struct V_299 * F_154 ( struct V_65 * V_66 )
{
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_299 * V_300 ;
F_34 ( & V_66 -> V_2 -> V_174 ) ;
F_155 (ctx, &nfsi->open_files, list) {
if ( V_300 -> V_66 != V_66 )
continue;
F_156 ( V_300 ) ;
F_36 ( & V_66 -> V_2 -> V_174 ) ;
return V_300 ;
}
F_36 ( & V_66 -> V_2 -> V_174 ) ;
return F_44 ( - V_301 ) ;
}
static struct V_200 * F_157 ( struct V_299 * V_300 ,
struct V_65 * V_66 , enum V_192 V_193 )
{
struct V_200 * V_286 ;
V_286 = F_85 ( V_300 -> V_4 , V_66 -> V_225 , 0 , 0 ,
NULL , NULL , V_193 , V_302 ) ;
if ( V_286 == NULL )
return F_44 ( - V_125 ) ;
V_286 -> V_66 = V_66 ;
F_92 ( & V_66 -> V_50 ) ;
return V_286 ;
}
static int F_158 ( struct V_200 * V_286 , T_5 V_184 , struct V_65 * * V_57 )
{
struct V_65 * V_303 ;
int V_52 ;
V_286 -> V_205 . V_227 = 0 ;
V_286 -> V_205 . V_184 = V_184 ;
V_286 -> V_205 . V_228 = F_80 (
F_159 ( V_286 -> V_4 -> V_224 ) ,
V_184 , 0 ) ;
memset ( & V_286 -> V_201 , 0 , sizeof( V_286 -> V_201 ) ) ;
memset ( & V_286 -> V_206 , 0 , sizeof( V_286 -> V_206 ) ) ;
F_82 ( V_286 ) ;
V_52 = F_160 ( V_286 ) ;
if ( V_52 != 0 )
return V_52 ;
V_303 = F_153 ( V_286 ) ;
if ( F_43 ( V_303 ) )
return F_71 ( V_303 ) ;
F_161 ( V_303 , V_184 ) ;
* V_57 = V_303 ;
return 0 ;
}
static int F_162 ( struct V_200 * V_286 , struct V_65 * V_66 )
{
struct V_65 * V_303 ;
int V_52 ;
F_125 ( V_262 , & V_66 -> V_214 ) ;
F_125 ( V_260 , & V_66 -> V_214 ) ;
F_125 ( V_258 , & V_66 -> V_214 ) ;
F_125 ( V_271 , & V_66 -> V_214 ) ;
F_125 ( V_269 , & V_66 -> V_214 ) ;
F_163 () ;
if ( V_66 -> V_263 != 0 ) {
V_52 = F_158 ( V_286 , V_69 | V_186 , & V_303 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_303 != V_66 )
return - V_304 ;
}
if ( V_66 -> V_261 != 0 ) {
V_52 = F_158 ( V_286 , V_186 , & V_303 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_303 != V_66 )
return - V_304 ;
}
if ( V_66 -> V_259 != 0 ) {
V_52 = F_158 ( V_286 , V_69 , & V_303 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_303 != V_66 )
return - V_304 ;
}
if ( F_31 ( V_271 , & V_66 -> V_214 ) == 0 &&
! F_136 ( & V_66 -> V_250 , & V_66 -> V_270 ) ) {
F_128 ( & V_66 -> V_272 ) ;
if ( F_31 ( V_271 , & V_66 -> V_214 ) == 0 )
F_126 ( & V_66 -> V_250 , & V_66 -> V_270 ) ;
F_129 ( & V_66 -> V_272 ) ;
}
return 0 ;
}
static int F_164 ( struct V_299 * V_300 , struct V_65 * V_66 )
{
struct V_264 * V_265 ;
struct V_200 * V_286 ;
T_5 V_295 = 0 ;
int V_305 ;
V_286 = F_157 ( V_300 , V_66 ,
V_245 ) ;
if ( F_43 ( V_286 ) )
return F_71 ( V_286 ) ;
F_134 () ;
V_265 = F_135 ( F_75 ( V_66 -> V_2 ) -> V_265 ) ;
if ( V_265 != NULL && F_31 ( V_291 , & V_265 -> V_214 ) != 0 )
V_295 = V_265 -> type ;
F_137 () ;
V_286 -> V_205 . V_248 . V_295 = V_295 ;
V_305 = F_162 ( V_286 , V_66 ) ;
F_106 ( V_286 ) ;
return V_305 ;
}
static int F_165 ( struct V_299 * V_300 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_164 ( V_300 , V_66 ) ;
F_166 ( V_300 , 0 , V_8 ) ;
if ( F_79 ( V_14 , V_8 , & V_62 ) )
continue;
if ( V_8 != - V_90 )
break;
F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_167 ( struct V_212 * V_213 , struct V_65 * V_66 )
{
struct V_299 * V_300 ;
int V_52 ;
V_300 = F_154 ( V_66 ) ;
if ( F_43 ( V_300 ) )
return - V_129 ;
V_52 = F_165 ( V_300 , V_66 ) ;
F_168 ( V_300 ) ;
return V_52 ;
}
static int F_169 ( struct V_13 * V_14 , struct V_65 * V_66 , const T_8 * V_250 , int V_8 )
{
switch ( V_8 ) {
default:
F_29 ( V_306 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_301 :
case - V_304 :
break;
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
F_123 ( V_271 , & V_66 -> V_214 ) ;
F_28 ( V_14 -> V_63 -> V_87 , V_8 ) ;
return - V_129 ;
case - V_76 :
case - V_75 :
F_123 ( V_271 , & V_66 -> V_214 ) ;
case - V_74 :
F_24 ( V_14 -> V_63 ) ;
return - V_129 ;
case - V_77 :
F_25 ( V_14 ) ;
return - V_129 ;
case - V_78 :
F_26 ( V_14 -> V_63 ) ;
return - V_129 ;
case - V_71 :
case - V_72 :
case - V_73 :
case - V_68 :
F_170 ( V_66 -> V_2 ,
V_250 ) ;
F_23 ( V_14 , V_66 ) ;
return - V_129 ;
case - V_90 :
case - V_89 :
F_123 ( V_271 , & V_66 -> V_214 ) ;
F_171 ( 1 ) ;
return - V_129 ;
case - V_125 :
case - V_307 :
return 0 ;
}
return V_8 ;
}
int F_172 ( struct V_299 * V_300 , struct V_65 * V_66 , const T_8 * V_250 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
struct V_200 * V_286 ;
int V_8 ;
V_286 = F_157 ( V_300 , V_66 ,
V_196 ) ;
if ( F_43 ( V_286 ) )
return F_71 ( V_286 ) ;
F_126 ( & V_286 -> V_205 . V_248 . V_265 , V_250 ) ;
V_8 = F_162 ( V_286 , V_66 ) ;
F_106 ( V_286 ) ;
return F_169 ( V_14 , V_66 , V_250 , V_8 ) ;
}
static void F_173 ( struct V_118 * V_119 , void * V_155 )
{
struct V_200 * V_157 = V_155 ;
F_40 ( V_157 -> V_205 . V_14 -> V_63 -> V_154 ,
& V_157 -> V_207 . V_159 , & V_157 -> V_206 . V_160 , V_119 ) ;
}
static void F_174 ( struct V_118 * V_119 , void * V_155 )
{
struct V_200 * V_157 = V_155 ;
F_48 ( V_119 , & V_157 -> V_206 . V_160 ) ;
V_157 -> V_293 = V_119 -> V_148 ;
if ( V_157 -> V_293 == 0 ) {
F_126 ( & V_157 -> V_201 . V_250 , & V_157 -> V_206 . V_250 ) ;
F_175 ( & V_157 -> V_225 -> V_222 , 0 ) ;
F_37 ( V_157 -> V_201 . V_14 , V_157 -> V_106 ) ;
V_157 -> V_292 = 1 ;
}
}
static void F_176 ( void * V_155 )
{
struct V_200 * V_157 = V_155 ;
struct V_65 * V_66 = NULL ;
if ( V_157 -> V_308 == 0 )
goto V_309;
if ( ! V_157 -> V_292 )
goto V_309;
V_66 = F_153 ( V_157 ) ;
if ( ! F_43 ( V_66 ) )
F_161 ( V_66 , V_157 -> V_205 . V_184 ) ;
V_309:
F_106 ( V_157 ) ;
}
static int F_177 ( struct V_200 * V_157 )
{
struct V_13 * V_14 = F_87 ( V_157 -> V_3 -> V_46 ) ;
struct V_118 * V_119 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_312 ] ,
. V_313 = & V_157 -> V_207 ,
. V_314 = & V_157 -> V_206 ,
. V_315 = V_157 -> V_225 -> V_289 ,
} ;
struct V_163 V_316 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_317 ,
. V_169 = V_157 ,
. V_318 = V_319 ,
. V_214 = V_320 ,
} ;
int V_305 ;
F_38 ( & V_157 -> V_207 . V_159 , & V_157 -> V_206 . V_160 , 1 ) ;
F_178 ( & V_157 -> V_251 ) ;
V_157 -> V_292 = 0 ;
V_157 -> V_293 = 0 ;
V_157 -> V_106 = V_153 ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) )
return F_71 ( V_119 ) ;
V_305 = F_108 ( V_119 ) ;
if ( V_305 != 0 ) {
V_157 -> V_308 = 1 ;
F_179 () ;
} else
V_305 = V_157 -> V_293 ;
F_72 ( V_119 ) ;
return V_305 ;
}
static void F_180 ( struct V_118 * V_119 , void * V_155 )
{
struct V_200 * V_157 = V_155 ;
struct V_212 * V_213 = V_157 -> V_225 ;
struct V_63 * V_64 = V_213 -> V_267 -> V_63 ;
if ( F_181 ( V_157 -> V_205 . V_204 , V_119 ) != 0 )
goto V_321;
if ( V_157 -> V_66 != NULL ) {
struct V_264 * V_265 ;
if ( F_110 ( V_157 -> V_66 , V_157 -> V_205 . V_184 , V_157 -> V_205 . V_227 ) )
goto V_322;
F_134 () ;
V_265 = F_135 ( F_75 ( V_157 -> V_66 -> V_2 ) -> V_265 ) ;
if ( V_157 -> V_205 . V_193 != V_197 &&
V_157 -> V_205 . V_193 != V_196 &&
F_111 ( V_265 , V_157 -> V_205 . V_184 ) )
goto V_323;
F_137 () ;
}
V_157 -> V_205 . V_234 = V_64 -> V_235 ;
switch ( V_157 -> V_205 . V_193 ) {
case V_245 :
case V_196 :
case V_198 :
V_157 -> V_205 . V_242 = & V_324 [ 0 ] ;
case V_194 :
V_119 -> V_325 . V_310 = & V_311 [ V_326 ] ;
F_182 ( & V_157 -> V_201 . V_244 , V_157 -> V_205 . V_244 ) ;
}
V_157 -> V_106 = V_153 ;
if ( F_63 ( V_157 -> V_205 . V_14 ,
& V_157 -> V_205 . V_159 ,
& V_157 -> V_201 . V_160 ,
V_119 ) != 0 )
F_141 ( V_157 -> V_205 . V_204 ) ;
V_157 -> V_205 . V_327 = V_328 ;
if ( V_157 -> V_205 . V_227 & V_229 ) {
V_157 -> V_205 . V_327 = V_329 ;
if ( F_183 ( V_64 ) )
V_157 -> V_205 . V_327 = V_330 ;
else if ( V_64 -> V_167 -> V_331 > 0 )
V_157 -> V_205 . V_327 = V_332 ;
}
return;
V_323:
F_137 () ;
V_322:
V_119 -> V_333 = NULL ;
V_321:
F_60 ( V_119 , & V_157 -> V_201 . V_160 ) ;
}
static void F_184 ( struct V_118 * V_119 , void * V_155 )
{
struct V_200 * V_157 = V_155 ;
V_157 -> V_293 = V_119 -> V_148 ;
if ( ! F_60 ( V_119 , & V_157 -> V_201 . V_160 ) )
return;
if ( V_119 -> V_148 == 0 ) {
if ( V_157 -> V_201 . V_202 -> V_296 & V_334 ) {
switch ( V_157 -> V_201 . V_202 -> V_255 & V_335 ) {
case V_336 :
break;
case V_337 :
V_157 -> V_293 = - V_338 ;
break;
case V_339 :
V_157 -> V_293 = - V_340 ;
break;
default:
V_157 -> V_293 = - V_341 ;
}
}
F_37 ( V_157 -> V_201 . V_14 , V_157 -> V_106 ) ;
if ( ! ( V_157 -> V_201 . V_342 & V_343 ) )
F_175 ( & V_157 -> V_225 -> V_222 , 0 ) ;
}
V_157 -> V_292 = 1 ;
}
static void F_185 ( void * V_155 )
{
struct V_200 * V_157 = V_155 ;
struct V_65 * V_66 = NULL ;
if ( V_157 -> V_308 == 0 )
goto V_309;
if ( V_157 -> V_293 != 0 || ! V_157 -> V_292 )
goto V_309;
if ( V_157 -> V_201 . V_342 & V_343 )
goto V_309;
V_66 = F_153 ( V_157 ) ;
if ( ! F_43 ( V_66 ) )
F_161 ( V_66 , V_157 -> V_205 . V_184 ) ;
V_309:
F_106 ( V_157 ) ;
}
static int F_186 ( struct V_200 * V_157 , int V_344 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_46 ;
struct V_13 * V_14 = F_87 ( V_3 ) ;
struct V_345 * V_205 = & V_157 -> V_205 ;
struct V_346 * V_201 = & V_157 -> V_201 ;
struct V_118 * V_119 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_347 ] ,
. V_313 = V_205 ,
. V_314 = V_201 ,
. V_315 = V_157 -> V_225 -> V_289 ,
} ;
struct V_163 V_316 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_348 ,
. V_169 = V_157 ,
. V_318 = V_319 ,
. V_214 = V_320 ,
} ;
int V_305 ;
F_38 ( & V_205 -> V_159 , & V_201 -> V_160 , 1 ) ;
F_178 ( & V_157 -> V_251 ) ;
V_157 -> V_292 = 0 ;
V_157 -> V_293 = 0 ;
V_157 -> V_308 = 0 ;
V_157 -> V_288 = 0 ;
if ( V_344 ) {
F_39 ( & V_205 -> V_159 ) ;
V_157 -> V_288 = 1 ;
}
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) )
return F_71 ( V_119 ) ;
V_305 = F_108 ( V_119 ) ;
if ( V_305 != 0 ) {
V_157 -> V_308 = 1 ;
F_179 () ;
} else
V_305 = V_157 -> V_293 ;
F_72 ( V_119 ) ;
return V_305 ;
}
static int F_160 ( struct V_200 * V_157 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_46 ;
struct V_346 * V_201 = & V_157 -> V_201 ;
int V_305 ;
V_305 = F_186 ( V_157 , 1 ) ;
if ( V_305 != 0 || ! V_157 -> V_292 )
return V_305 ;
F_187 ( F_87 ( V_3 ) , & V_157 -> V_202 ) ;
if ( V_201 -> V_342 & V_343 ) {
V_305 = F_177 ( V_157 ) ;
if ( V_305 != 0 )
return V_305 ;
}
return V_305 ;
}
static int F_188 ( struct V_315 * V_349 ,
struct V_200 * V_286 ,
struct V_65 * V_66 , T_5 V_184 ,
int V_185 )
{
struct V_350 V_351 ;
T_1 V_352 ;
if ( V_286 -> V_201 . V_353 == 0 )
return 0 ;
V_352 = 0 ;
if ( V_185 & V_354 ) {
V_352 = V_355 ;
} else if ( ( V_184 & V_69 ) && ! V_286 -> V_356 )
V_352 = V_357 ;
V_351 . V_349 = V_349 ;
V_351 . V_153 = V_153 ;
F_189 ( & V_351 , V_286 -> V_201 . V_358 ) ;
F_190 ( V_66 -> V_2 , & V_351 ) ;
if ( ( V_352 & ~ V_351 . V_352 & ( V_357 | V_355 ) ) == 0 )
return 0 ;
F_161 ( V_66 , V_184 ) ;
return - V_29 ;
}
static int F_191 ( struct V_200 * V_157 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_46 ;
struct V_13 * V_14 = F_87 ( V_3 ) ;
struct V_345 * V_205 = & V_157 -> V_205 ;
struct V_346 * V_201 = & V_157 -> V_201 ;
int V_305 ;
V_305 = F_186 ( V_157 , 0 ) ;
if ( ! V_157 -> V_292 )
return V_305 ;
if ( V_305 != 0 ) {
if ( V_305 == - V_26 &&
! ( V_205 -> V_227 & V_359 ) )
return - V_301 ;
return V_305 ;
}
F_187 ( V_14 , & V_157 -> V_202 ) ;
if ( V_205 -> V_227 & V_359 ) {
F_74 ( V_3 , & V_201 -> V_171 ) ;
if ( V_205 -> V_227 & V_229 )
V_157 -> V_356 = 1 ;
else if ( V_201 -> V_171 . V_179 != V_201 -> V_171 . V_181 )
V_157 -> V_356 = 1 ;
}
if ( ( V_201 -> V_342 & V_360 ) == 0 )
V_14 -> V_94 &= ~ V_361 ;
if( V_201 -> V_342 & V_343 ) {
V_305 = F_177 ( V_157 ) ;
if ( V_305 != 0 )
return V_305 ;
}
if ( ! ( V_201 -> V_202 -> V_296 & V_297 ) )
F_192 ( V_14 , & V_201 -> V_244 , V_201 -> V_202 , V_201 -> V_203 ) ;
return 0 ;
}
static int F_193 ( struct V_13 * V_14 )
{
return F_194 ( V_14 -> V_63 ) ;
}
static int F_195 ( struct V_299 * V_300 , struct V_65 * V_66 )
{
struct V_200 * V_286 ;
int V_52 ;
V_286 = F_157 ( V_300 , V_66 ,
V_194 ) ;
if ( F_43 ( V_286 ) )
return F_71 ( V_286 ) ;
V_52 = F_162 ( V_286 , V_66 ) ;
if ( V_52 == - V_304 )
F_196 ( V_300 -> V_4 ) ;
F_106 ( V_286 ) ;
return V_52 ;
}
static int F_197 ( struct V_299 * V_300 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_195 ( V_300 , V_66 ) ;
F_198 ( V_300 , 0 , V_8 ) ;
if ( F_79 ( V_14 , V_8 , & V_62 ) )
continue;
switch ( V_8 ) {
default:
goto V_130;
case - V_89 :
case - V_90 :
F_20 ( V_14 , V_8 , & V_62 ) ;
V_8 = 0 ;
}
} while ( V_62 . V_67 );
V_130:
return V_8 ;
}
static int F_199 ( struct V_212 * V_213 , struct V_65 * V_66 )
{
struct V_299 * V_300 ;
int V_52 ;
V_300 = F_154 ( V_66 ) ;
if ( F_43 ( V_300 ) )
return - V_129 ;
V_52 = F_197 ( V_300 , V_66 ) ;
F_168 ( V_300 ) ;
return V_52 ;
}
static void F_200 ( struct V_65 * V_66 )
{
F_201 ( V_66 -> V_2 ) ;
F_128 ( & V_66 -> V_272 ) ;
F_126 ( & V_66 -> V_250 , & V_66 -> V_270 ) ;
F_129 ( & V_66 -> V_272 ) ;
F_125 ( V_271 , & V_66 -> V_214 ) ;
}
static void F_202 ( struct V_65 * V_66 )
{
if ( F_203 ( F_75 ( V_66 -> V_2 ) -> V_265 ) != NULL )
F_200 ( V_66 ) ;
}
static int F_204 ( struct V_212 * V_213 , struct V_65 * V_66 )
{
F_202 ( V_66 ) ;
return F_199 ( V_213 , V_66 ) ;
}
static void F_205 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
T_8 V_250 ;
struct V_264 * V_265 ;
struct V_315 * V_349 ;
int V_305 ;
F_134 () ;
V_265 = F_135 ( F_75 ( V_66 -> V_2 ) -> V_265 ) ;
if ( V_265 == NULL ) {
F_137 () ;
return;
}
F_126 ( & V_250 , & V_265 -> V_250 ) ;
V_349 = F_206 ( V_265 -> V_349 ) ;
F_137 () ;
V_305 = F_207 ( V_14 , & V_250 , V_349 ) ;
F_208 ( V_66 , NULL , V_305 ) ;
if ( V_305 != V_362 ) {
if ( V_305 != - V_73 )
F_209 ( V_14 , & V_250 , V_349 ) ;
F_200 ( V_66 ) ;
}
F_210 ( V_349 ) ;
}
static int F_211 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
T_8 * V_250 = & V_66 -> V_270 ;
struct V_315 * V_349 = V_66 -> V_225 -> V_289 ;
int V_305 ;
if ( ( F_31 ( V_258 , & V_66 -> V_214 ) == 0 ) &&
( F_31 ( V_260 , & V_66 -> V_214 ) == 0 ) &&
( F_31 ( V_262 , & V_66 -> V_214 ) == 0 ) )
return - V_73 ;
V_305 = F_207 ( V_14 , V_250 , V_349 ) ;
F_212 ( V_66 , NULL , V_305 ) ;
if ( V_305 != V_362 ) {
if ( V_305 != - V_73 )
F_209 ( V_14 , V_250 , V_349 ) ;
F_125 ( V_258 , & V_66 -> V_214 ) ;
F_125 ( V_260 , & V_66 -> V_214 ) ;
F_125 ( V_262 , & V_66 -> V_214 ) ;
F_125 ( V_269 , & V_66 -> V_214 ) ;
}
return V_305 ;
}
static int F_213 ( struct V_212 * V_213 , struct V_65 * V_66 )
{
int V_305 ;
F_205 ( V_66 ) ;
V_305 = F_211 ( V_66 ) ;
if ( V_305 != V_362 )
V_305 = F_199 ( V_213 , V_66 ) ;
return V_305 ;
}
static inline void F_214 ( struct V_200 * V_286 , struct V_5 * V_6 )
{
if ( ( V_286 -> V_201 . V_363 [ 1 ] & V_364 ) &&
! ( V_6 -> V_246 & V_365 ) )
V_6 -> V_246 |= V_366 ;
if ( ( V_286 -> V_201 . V_363 [ 1 ] & V_367 ) &&
! ( V_6 -> V_246 & V_368 ) )
V_6 -> V_246 |= V_369 ;
}
static int F_215 ( struct V_200 * V_286 ,
T_5 V_184 ,
int V_214 ,
struct V_299 * V_300 )
{
struct V_212 * V_213 = V_286 -> V_225 ;
struct V_13 * V_14 = V_213 -> V_267 ;
struct V_4 * V_4 ;
struct V_65 * V_66 ;
unsigned int V_370 ;
int V_52 ;
V_370 = F_216 ( & V_213 -> V_371 ) ;
V_52 = F_191 ( V_286 ) ;
if ( V_52 != 0 )
goto V_130;
V_66 = F_153 ( V_286 ) ;
V_52 = F_71 ( V_66 ) ;
if ( F_43 ( V_66 ) )
goto V_130;
if ( V_14 -> V_94 & V_361 )
F_123 ( V_372 , & V_66 -> V_214 ) ;
V_4 = V_286 -> V_4 ;
if ( V_4 -> V_46 == NULL ) {
F_196 ( V_4 ) ;
V_4 = F_217 ( V_4 , F_218 ( V_66 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_286 -> V_4 ;
} else if ( V_4 != V_300 -> V_4 ) {
F_98 ( V_300 -> V_4 ) ;
V_300 -> V_4 = F_91 ( V_4 ) ;
}
F_219 ( V_4 ,
F_220 ( V_286 -> V_3 -> V_46 ) ) ;
}
V_52 = F_188 ( V_213 -> V_289 , V_286 , V_66 , V_184 , V_214 ) ;
if ( V_52 != 0 )
goto V_130;
V_300 -> V_66 = V_66 ;
if ( V_4 -> V_46 == V_66 -> V_2 ) {
F_221 ( V_300 ) ;
if ( F_222 ( & V_213 -> V_371 , V_370 ) )
F_23 ( V_14 , V_66 ) ;
}
V_130:
return V_52 ;
}
static int F_223 ( struct V_2 * V_3 ,
struct V_299 * V_300 ,
int V_214 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_373 )
{
struct V_212 * V_213 ;
struct V_65 * V_66 = NULL ;
struct V_13 * V_14 = F_87 ( V_3 ) ;
struct V_200 * V_286 ;
struct V_4 * V_4 = V_300 -> V_4 ;
struct V_315 * V_349 = V_300 -> V_349 ;
struct V_374 * * V_375 = & V_300 -> V_254 ;
T_5 V_184 = V_300 -> V_255 & ( V_69 | V_186 | V_376 ) ;
enum V_192 V_193 = V_195 ;
struct V_1 * V_377 = NULL ;
int V_305 ;
V_305 = - V_125 ;
V_213 = F_224 ( V_14 , V_349 , V_378 ) ;
if ( V_213 == NULL ) {
F_8 ( L_23 ) ;
goto V_379;
}
V_305 = F_193 ( V_14 ) ;
if ( V_305 != 0 )
goto V_380;
if ( V_4 -> V_46 != NULL )
F_139 ( V_4 -> V_46 , V_184 ) ;
V_305 = - V_125 ;
if ( V_4 -> V_46 )
V_193 = V_194 ;
V_286 = F_85 ( V_4 , V_213 , V_184 , V_214 , V_6 ,
V_7 , V_193 , V_378 ) ;
if ( V_286 == NULL )
goto V_380;
if ( V_7 ) {
V_377 = F_89 ( V_14 , V_378 ) ;
if ( F_43 ( V_377 ) ) {
V_305 = F_71 ( V_377 ) ;
goto V_381;
}
}
if ( V_14 -> V_15 [ 2 ] & V_382 ) {
if ( ! V_286 -> V_202 . V_254 ) {
V_286 -> V_202 . V_254 = F_225 () ;
if ( ! V_286 -> V_202 . V_254 )
goto V_223;
}
V_286 -> V_205 . V_242 = & V_383 [ 0 ] ;
}
if ( V_4 -> V_46 != NULL )
V_286 -> V_66 = F_151 ( V_4 -> V_46 , V_213 ) ;
V_305 = F_215 ( V_286 , V_184 , V_214 , V_300 ) ;
if ( V_305 != 0 )
goto V_223;
V_66 = V_300 -> V_66 ;
if ( ( V_286 -> V_205 . V_227 & V_229 ) &&
( V_286 -> V_205 . V_327 != V_330 ) ) {
F_214 ( V_286 , V_6 ) ;
F_83 ( V_286 -> V_201 . V_202 ) ;
V_305 = F_226 ( V_66 -> V_2 , V_349 ,
V_286 -> V_201 . V_202 , V_6 ,
V_66 , V_7 , V_377 ) ;
if ( V_305 == 0 ) {
F_227 ( V_66 -> V_2 , V_6 ,
V_286 -> V_201 . V_202 ) ;
F_228 ( V_66 -> V_2 , V_286 -> V_201 . V_202 , V_377 ) ;
}
}
if ( V_286 -> V_356 )
* V_373 |= V_384 ;
if ( F_229 ( V_375 , V_286 -> V_202 . V_254 , V_14 ) ) {
* V_375 = V_286 -> V_202 . V_254 ;
V_286 -> V_202 . V_254 = NULL ;
}
F_96 ( V_377 ) ;
F_106 ( V_286 ) ;
F_103 ( V_213 ) ;
return 0 ;
V_223:
F_96 ( V_377 ) ;
V_381:
F_106 ( V_286 ) ;
V_380:
F_103 ( V_213 ) ;
V_379:
return V_305 ;
}
static struct V_65 * F_230 ( struct V_2 * V_3 ,
struct V_299 * V_300 ,
int V_214 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_373 )
{
struct V_13 * V_14 = F_87 ( V_3 ) ;
struct V_61 V_62 = { } ;
struct V_65 * V_57 ;
int V_305 ;
do {
V_305 = F_223 ( V_3 , V_300 , V_214 , V_6 , V_7 , V_373 ) ;
V_57 = V_300 -> V_66 ;
F_231 ( V_300 , V_214 , V_305 ) ;
if ( V_305 == 0 )
break;
if ( V_305 == - V_385 ) {
F_232 ( L_5
L_24 ,
F_87 ( V_3 ) -> V_63 -> V_97 ) ;
V_62 . V_67 = 1 ;
continue;
}
if ( V_305 == - V_73 ) {
V_62 . V_67 = 1 ;
continue;
}
if ( V_305 == - V_129 ) {
V_62 . V_67 = 1 ;
continue;
}
if ( F_79 ( V_14 , V_305 , & V_62 ) )
continue;
V_57 = F_44 ( F_20 ( V_14 ,
V_305 , & V_62 ) ) ;
} while ( V_62 . V_67 );
return V_57 ;
}
static int F_233 ( struct V_2 * V_2 , struct V_315 * V_349 ,
struct V_386 * V_387 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_388 ,
struct V_1 * V_377 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_389 V_390 = {
. V_244 = F_94 ( V_2 ) ,
. V_391 = V_6 ,
. V_14 = V_14 ,
. V_241 = V_14 -> V_15 ,
. V_7 = V_388 ,
} ;
struct V_392 V_57 = {
. V_387 = V_387 ,
. V_7 = V_377 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_393 ] ,
. V_313 = & V_390 ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
unsigned long V_106 = V_153 ;
T_5 V_184 ;
bool V_394 ;
int V_305 ;
V_390 . V_241 = F_6 ( V_14 , V_388 ) ;
if ( V_388 )
V_390 . V_241 = F_6 ( V_14 , V_377 ) ;
F_83 ( V_387 ) ;
V_394 = ( V_6 -> V_246 & V_395 ) ? true : false ;
V_184 = V_394 ? V_186 : V_69 ;
if ( F_234 ( & V_390 . V_250 , V_2 , V_184 ) ) {
} else if ( V_394 && V_66 != NULL ) {
struct V_396 V_397 = {
. V_398 = V_58 -> V_399 ,
. V_400 = V_58 -> V_401 ,
} ;
if ( ! F_235 ( V_66 ) )
return - V_402 ;
if ( F_236 ( & V_390 . V_250 , V_66 , V_186 ,
& V_397 ) == - V_35 )
return - V_402 ;
} else
F_126 ( & V_390 . V_250 , & V_403 ) ;
V_305 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_390 . V_159 , & V_57 . V_160 , 1 ) ;
if ( V_305 == 0 && V_66 != NULL )
F_37 ( V_14 , V_106 ) ;
return V_305 ;
}
static int F_226 ( struct V_2 * V_2 , struct V_315 * V_349 ,
struct V_386 * V_387 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_388 ,
struct V_1 * V_377 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_233 ( V_2 , V_349 , V_387 , V_6 , V_66 , V_388 , V_377 ) ;
F_237 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_68 :
if ( ! ( V_6 -> V_246 & V_395 ) ) {
F_238 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_63 -> V_97 ) ;
}
if ( V_66 && ! ( V_66 -> V_66 & V_186 ) ) {
V_8 = - V_402 ;
if ( V_6 -> V_246 & V_404 )
V_8 = - V_29 ;
goto V_130;
}
}
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
V_130:
return V_8 ;
}
static void F_239 ( void * V_157 )
{
struct V_405 * V_155 = V_157 ;
struct V_212 * V_213 = V_155 -> V_66 -> V_225 ;
struct V_252 * V_253 = V_155 -> V_66 -> V_2 -> V_406 ;
if ( V_155 -> V_407 )
F_240 ( V_155 -> V_66 -> V_2 ) ;
F_102 ( V_155 -> V_66 ) ;
F_101 ( V_155 -> V_390 . V_204 ) ;
F_103 ( V_213 ) ;
F_104 ( V_253 ) ;
F_97 ( V_155 ) ;
}
static void F_241 ( struct V_118 * V_119 , void * V_157 )
{
struct V_405 * V_155 = V_157 ;
struct V_65 * V_66 = V_155 -> V_66 ;
struct V_13 * V_14 = F_87 ( V_155 -> V_2 ) ;
T_8 * V_408 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_60 ( V_119 , & V_155 -> V_57 . V_160 ) )
return;
F_242 ( V_66 , & V_155 -> V_390 , & V_155 -> V_57 , V_119 -> V_148 ) ;
switch ( V_119 -> V_148 ) {
case 0 :
V_408 = & V_155 -> V_57 . V_250 ;
if ( V_155 -> V_390 . V_184 == 0 && V_155 -> V_407 )
F_243 ( V_66 -> V_2 ,
V_155 -> V_409 ) ;
F_37 ( V_14 , V_155 -> V_106 ) ;
break;
case - V_72 :
case - V_75 :
case - V_93 :
case - V_73 :
case - V_74 :
if ( ! F_136 ( & V_155 -> V_390 . V_250 ,
& V_66 -> V_270 ) ) {
F_57 ( V_119 ) ;
goto V_410;
}
if ( V_155 -> V_390 . V_184 == 0 )
break;
default:
if ( F_244 ( V_119 , V_14 , V_66 , NULL ) == - V_129 ) {
F_57 ( V_119 ) ;
goto V_410;
}
}
F_127 ( V_66 , V_408 , V_155 -> V_390 . V_184 ) ;
V_410:
F_141 ( V_155 -> V_390 . V_204 ) ;
F_148 ( V_155 -> V_2 , V_155 -> V_57 . V_387 ) ;
F_8 ( L_30 , V_34 , V_119 -> V_148 ) ;
}
static void F_245 ( struct V_118 * V_119 , void * V_157 )
{
struct V_405 * V_155 = V_157 ;
struct V_65 * V_66 = V_155 -> V_66 ;
struct V_2 * V_2 = V_155 -> V_2 ;
bool V_411 , V_412 , V_413 ;
int V_414 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_181 ( V_155 -> V_390 . V_204 , V_119 ) != 0 )
goto V_321;
V_119 -> V_325 . V_310 = & V_311 [ V_415 ] ;
F_34 ( & V_66 -> V_225 -> V_275 ) ;
V_413 = F_31 ( V_262 , & V_66 -> V_214 ) ;
V_411 = F_31 ( V_258 , & V_66 -> V_214 ) ;
V_412 = F_31 ( V_260 , & V_66 -> V_214 ) ;
F_126 ( & V_155 -> V_390 . V_250 , & V_66 -> V_270 ) ;
V_155 -> V_390 . V_184 = 0 ;
if ( V_66 -> V_263 == 0 ) {
if ( V_66 -> V_259 == 0 )
V_414 |= V_411 ;
else if ( V_411 )
V_155 -> V_390 . V_184 |= V_69 ;
if ( V_66 -> V_261 == 0 )
V_414 |= V_412 ;
else if ( V_412 )
V_155 -> V_390 . V_184 |= V_186 ;
} else if ( V_413 )
V_155 -> V_390 . V_184 |= V_69 | V_186 ;
if ( V_155 -> V_390 . V_184 == 0 )
V_414 |= V_413 ;
if ( ! F_235 ( V_66 ) )
V_414 = 0 ;
F_36 ( & V_66 -> V_225 -> V_275 ) ;
if ( ! V_414 ) {
goto V_322;
}
if ( V_155 -> V_390 . V_184 == 0 ) {
V_119 -> V_325 . V_310 = & V_311 [ V_416 ] ;
if ( V_155 -> V_407 &&
F_246 ( V_2 , & V_155 -> V_409 , V_119 ) ) {
F_141 ( V_155 -> V_390 . V_204 ) ;
goto V_321;
}
}
V_155 -> V_390 . V_228 =
F_80 ( F_87 ( V_2 ) ,
V_155 -> V_390 . V_184 , 0 ) ;
F_83 ( V_155 -> V_57 . V_387 ) ;
V_155 -> V_106 = V_153 ;
if ( F_63 ( F_87 ( V_2 ) ,
& V_155 -> V_390 . V_159 ,
& V_155 -> V_57 . V_160 ,
V_119 ) != 0 )
F_141 ( V_155 -> V_390 . V_204 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_322:
V_119 -> V_333 = NULL ;
V_321:
F_60 ( V_119 , & V_155 -> V_57 . V_160 ) ;
}
static bool F_247 ( struct V_2 * V_2 )
{
if ( ! F_248 ( V_2 ) )
return false ;
return F_249 ( V_2 ) ;
}
int F_250 ( struct V_65 * V_66 , T_6 V_216 , int V_417 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
struct V_218 * ( * V_219 ) ( struct V_220 * , T_6 ) ;
struct V_405 * V_155 ;
struct V_212 * V_213 = V_66 -> V_225 ;
struct V_118 * V_119 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_416 ] ,
. V_315 = V_66 -> V_225 -> V_289 ,
} ;
struct V_163 V_316 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_418 ,
. V_318 = V_319 ,
. V_214 = V_320 ,
} ;
int V_305 = - V_125 ;
F_251 ( V_14 -> V_63 , V_419 ,
& V_316 . V_165 , & V_162 ) ;
V_155 = F_88 ( sizeof( * V_155 ) , V_216 ) ;
if ( V_155 == NULL )
goto V_130;
F_38 ( & V_155 -> V_390 . V_159 , & V_155 -> V_57 . V_160 , 1 ) ;
V_155 -> V_2 = V_66 -> V_2 ;
V_155 -> V_66 = V_66 ;
V_155 -> V_390 . V_244 = F_94 ( V_66 -> V_2 ) ;
V_219 = V_14 -> V_63 -> V_167 -> V_219 ;
V_155 -> V_390 . V_204 = V_219 ( & V_66 -> V_225 -> V_222 , V_216 ) ;
if ( F_43 ( V_155 -> V_390 . V_204 ) )
goto V_420;
V_155 -> V_390 . V_184 = 0 ;
V_155 -> V_390 . V_241 = V_14 -> V_421 ;
V_155 -> V_57 . V_387 = & V_155 -> V_387 ;
V_155 -> V_57 . V_204 = V_155 -> V_390 . V_204 ;
V_155 -> V_57 . V_14 = V_14 ;
V_155 -> V_407 = F_247 ( V_66 -> V_2 ) ;
F_90 ( V_155 -> V_2 -> V_406 ) ;
V_162 . V_313 = & V_155 -> V_390 ;
V_162 . V_314 = & V_155 -> V_57 ;
V_316 . V_169 = V_155 ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) )
return F_71 ( V_119 ) ;
V_305 = 0 ;
if ( V_417 )
V_305 = F_109 ( V_119 ) ;
F_72 ( V_119 ) ;
return V_305 ;
V_420:
F_97 ( V_155 ) ;
V_130:
F_102 ( V_66 ) ;
F_103 ( V_213 ) ;
return V_305 ;
}
static struct V_2 *
F_252 ( struct V_2 * V_3 , struct V_299 * V_300 ,
int V_227 , struct V_5 * V_422 , int * V_373 )
{
struct V_65 * V_66 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_300 -> V_4 , V_422 , & V_17 ) ;
V_66 = F_230 ( V_3 , V_300 , V_227 , V_422 , V_7 , V_373 ) ;
F_4 ( V_7 ) ;
if ( F_43 ( V_66 ) )
return F_253 ( V_66 ) ;
return V_66 -> V_2 ;
}
static void F_254 ( struct V_299 * V_300 , int V_423 )
{
if ( V_300 -> V_66 == NULL )
return;
if ( V_423 )
F_255 ( V_300 -> V_66 , V_300 -> V_255 ) ;
else
F_161 ( V_300 -> V_66 , V_300 -> V_255 ) ;
}
static int F_256 ( struct V_13 * V_14 , struct V_424 * V_425 )
{
struct V_426 args = {
. V_425 = V_425 ,
} ;
struct V_427 V_57 = {} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_428 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
int V_305 ;
V_305 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
if ( V_305 == 0 ) {
switch ( V_14 -> V_63 -> V_429 ) {
case 0 :
V_57 . V_15 [ 1 ] &= V_430 ;
V_57 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_57 . V_15 [ 2 ] &= V_431 ;
break;
case 2 :
V_57 . V_15 [ 2 ] &= V_432 ;
}
memcpy ( V_14 -> V_15 , V_57 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_94 &= ~ ( V_433 | V_434 |
V_435 | V_436 |
V_437 | V_438 | V_439 |
V_440 | V_441 |
V_442 | V_443 |
V_9 ) ;
if ( V_57 . V_15 [ 0 ] & V_444 &&
V_57 . V_445 & V_446 )
V_14 -> V_94 |= V_433 ;
if ( V_57 . V_447 != 0 )
V_14 -> V_94 |= V_434 ;
if ( V_57 . V_448 != 0 )
V_14 -> V_94 |= V_435 ;
if ( V_57 . V_15 [ 0 ] & V_45 )
V_14 -> V_94 |= V_436 ;
if ( V_57 . V_15 [ 1 ] & V_449 )
V_14 -> V_94 |= V_437 ;
if ( V_57 . V_15 [ 1 ] & V_450 )
V_14 -> V_94 |= V_438 ;
if ( V_57 . V_15 [ 1 ] & V_451 )
V_14 -> V_94 |= V_439 ;
if ( V_57 . V_15 [ 1 ] & V_452 )
V_14 -> V_94 |= V_440 ;
if ( V_57 . V_15 [ 1 ] & V_364 )
V_14 -> V_94 |= V_441 ;
if ( V_57 . V_15 [ 1 ] & V_453 )
V_14 -> V_94 |= V_442 ;
if ( V_57 . V_15 [ 1 ] & V_367 )
V_14 -> V_94 |= V_443 ;
#ifdef F_257
if ( V_57 . V_15 [ 2 ] & V_454 )
V_14 -> V_94 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_57 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_454 ;
memcpy ( V_14 -> V_421 , V_57 . V_15 , sizeof( V_14 -> V_421 ) ) ;
V_14 -> V_421 [ 0 ] &= V_455 | V_456 ;
V_14 -> V_421 [ 1 ] &= V_453 | V_367 ;
V_14 -> V_421 [ 2 ] = 0 ;
V_14 -> V_445 = V_57 . V_445 ;
V_14 -> V_457 = V_57 . V_457 ;
}
return V_305 ;
}
int F_258 ( struct V_13 * V_14 , struct V_424 * V_425 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_256 ( V_14 , V_425 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_259 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_459 )
{
T_1 V_241 [ 3 ] ;
struct V_460 args = {
. V_241 = V_241 ,
} ;
struct V_461 V_57 = {
. V_14 = V_14 ,
. V_387 = V_459 -> V_387 ,
. V_244 = V_425 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_462 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
V_241 [ 0 ] = V_243 [ 0 ] ;
V_241 [ 1 ] = V_243 [ 1 ] ;
V_241 [ 2 ] = V_243 [ 2 ] & ~ V_454 ;
F_83 ( V_459 -> V_387 ) ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_260 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_459 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_259 ( V_14 , V_425 , V_459 ) ;
F_261 ( V_14 , V_425 , V_459 -> V_387 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_130;
default:
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
}
} while ( V_62 . V_67 );
V_130:
return V_8 ;
}
static int F_262 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_459 , T_4 V_100 )
{
struct V_463 V_464 = {
. V_465 = V_100 ,
} ;
struct V_466 * V_467 ;
int V_52 ;
V_467 = F_263 ( & V_464 , V_14 -> V_91 ) ;
if ( F_43 ( V_467 ) ) {
V_52 = - V_29 ;
goto V_130;
}
V_52 = F_260 ( V_14 , V_425 , V_459 ) ;
V_130:
return V_52 ;
}
static int F_264 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_459 )
{
static const T_4 V_468 [] = {
V_105 ,
V_104 ,
V_469 ,
V_470 ,
V_471 ,
} ;
int V_305 = - V_24 ;
T_9 V_472 ;
if ( V_14 -> V_473 . V_474 > 0 ) {
for ( V_472 = 0 ; V_472 < V_14 -> V_473 . V_474 ; V_472 ++ ) {
V_305 = F_262 ( V_14 , V_425 , V_459 ,
V_14 -> V_473 . V_475 [ V_472 ] ) ;
if ( V_305 == - V_22 || V_305 == - V_29 )
continue;
break;
}
} else {
for ( V_472 = 0 ; V_472 < F_265 ( V_468 ) ; V_472 ++ ) {
V_305 = F_262 ( V_14 , V_425 , V_459 ,
V_468 [ V_472 ] ) ;
if ( V_305 == - V_22 || V_305 == - V_29 )
continue;
break;
}
}
if ( V_305 == - V_29 )
V_305 = - V_24 ;
return V_305 ;
}
static int F_266 ( struct V_13 * V_14 ,
struct V_424 * V_425 , struct V_458 * V_459 )
{
int V_476 = V_14 -> V_63 -> V_429 ;
return V_477 [ V_476 ] -> F_267 ( V_14 , V_425 , V_459 ) ;
}
int F_268 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_459 ,
bool V_478 )
{
int V_305 ;
switch ( V_478 ) {
case false :
V_305 = F_260 ( V_14 , V_425 , V_459 ) ;
if ( V_305 != - V_22 )
break;
default:
V_305 = F_266 ( V_14 , V_425 , V_459 ) ;
}
if ( V_305 == 0 )
V_305 = F_258 ( V_14 , V_425 ) ;
if ( V_305 == 0 )
V_305 = F_269 ( V_14 , V_425 , V_459 ) ;
return F_7 ( V_305 ) ;
}
static int F_270 ( struct V_13 * V_14 , struct V_424 * V_479 ,
struct V_458 * V_459 )
{
int error ;
struct V_386 * V_387 = V_459 -> V_387 ;
struct V_1 * V_7 = NULL ;
error = F_258 ( V_14 , V_479 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_89 ( V_14 , V_378 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
error = F_192 ( V_14 , V_479 , V_387 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_223;
}
if ( V_387 -> V_296 & V_480 &&
! F_271 ( & V_14 -> V_481 , & V_387 -> V_481 ) )
memcpy ( & V_14 -> V_481 , & V_387 -> V_481 , sizeof( V_14 -> V_481 ) ) ;
V_223:
F_96 ( V_7 ) ;
return error ;
}
static int F_272 ( struct V_55 * V_91 , struct V_2 * V_3 ,
const struct V_482 * V_240 , struct V_386 * V_387 ,
struct V_424 * V_425 )
{
int V_305 = - V_125 ;
struct V_483 * V_483 = NULL ;
struct V_484 * V_485 = NULL ;
V_483 = F_273 ( V_378 ) ;
if ( V_483 == NULL )
goto V_130;
V_485 = F_274 ( sizeof( struct V_484 ) , V_378 ) ;
if ( V_485 == NULL )
goto V_130;
V_305 = F_275 ( V_91 , V_3 , V_240 , V_485 , V_483 ) ;
if ( V_305 != 0 )
goto V_130;
if ( F_271 ( & F_87 ( V_3 ) -> V_481 , & V_485 -> V_387 . V_481 ) ) {
F_8 ( L_34
L_35 , V_34 , V_240 -> V_240 ) ;
V_305 = - V_77 ;
goto V_130;
}
F_276 ( & V_485 -> V_387 ) ;
memcpy ( V_387 , & V_485 -> V_387 , sizeof( struct V_386 ) ) ;
memset ( V_425 , 0 , sizeof( struct V_424 ) ) ;
V_130:
if ( V_483 )
F_277 ( V_483 ) ;
F_97 ( V_485 ) ;
return V_305 ;
}
static int F_278 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_386 * V_387 , struct V_1 * V_7 )
{
struct V_486 args = {
. V_244 = V_425 ,
. V_241 = V_14 -> V_15 ,
} ;
struct V_487 V_57 = {
. V_387 = V_387 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_488 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
args . V_241 = F_6 ( V_14 , V_7 ) ;
F_83 ( V_387 ) ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_192 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_386 * V_387 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_278 ( V_14 , V_425 , V_387 , V_7 ) ;
F_279 ( V_14 , V_425 , V_387 , V_8 ) ;
V_8 = F_20 ( V_14 , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int
F_280 ( struct V_4 * V_4 , struct V_386 * V_387 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = V_4 -> V_46 ;
struct V_315 * V_349 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_1 * V_7 = NULL ;
int V_305 ;
if ( F_281 ( V_2 ) &&
V_6 -> V_246 & V_395 &&
V_6 -> V_489 < F_282 ( V_2 ) )
F_283 ( V_2 ) ;
F_83 ( V_387 ) ;
if ( V_6 -> V_246 & V_404 )
V_6 -> V_246 &= ~ ( V_369 | V_490 ) ;
if ( ( V_6 -> V_246 & ~ ( V_491 | V_404 ) ) == 0 )
return 0 ;
if ( V_6 -> V_246 & V_491 ) {
struct V_299 * V_300 ;
V_300 = F_284 ( V_6 -> V_492 ) ;
if ( V_300 ) {
V_349 = V_300 -> V_349 ;
V_66 = V_300 -> V_66 ;
}
}
V_7 = F_89 ( F_87 ( V_2 ) , V_378 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
V_305 = F_226 ( V_2 , V_349 , V_387 , V_6 , V_66 , NULL , V_7 ) ;
if ( V_305 == 0 ) {
F_227 ( V_2 , V_6 , V_387 ) ;
F_228 ( V_2 , V_387 , V_7 ) ;
}
F_96 ( V_7 ) ;
return V_305 ;
}
static int F_285 ( struct V_55 * V_56 , struct V_2 * V_3 ,
const struct V_482 * V_240 , struct V_424 * V_425 ,
struct V_386 * V_387 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_87 ( V_3 ) ;
int V_305 ;
struct V_493 args = {
. V_241 = V_14 -> V_15 ,
. V_494 = F_94 ( V_3 ) ,
. V_240 = V_240 ,
} ;
struct V_461 V_57 = {
. V_14 = V_14 ,
. V_387 = V_387 ,
. V_7 = V_7 ,
. V_244 = V_425 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_495 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
args . V_241 = F_6 ( V_14 , V_7 ) ;
F_83 ( V_387 ) ;
F_8 ( L_36 , V_240 -> V_240 ) ;
V_305 = F_73 ( V_56 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
F_8 ( L_37 , V_305 ) ;
return V_305 ;
}
static void F_286 ( struct V_386 * V_387 )
{
V_387 -> V_296 |= V_334 | V_496 |
V_497 | V_498 ;
V_387 -> V_255 = V_339 | V_499 | V_500 ;
V_387 -> V_501 = 2 ;
}
static int F_287 ( struct V_55 * * V_56 , struct V_2 * V_3 ,
struct V_482 * V_240 , struct V_424 * V_425 ,
struct V_386 * V_387 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
struct V_55 * V_91 = * V_56 ;
int V_8 ;
do {
V_8 = F_285 ( V_91 , V_3 , V_240 , V_425 , V_387 , V_7 ) ;
F_288 ( V_3 , V_240 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_301 ;
goto V_130;
case - V_77 :
V_8 = F_272 ( V_91 , V_3 , V_240 , V_387 , V_425 ) ;
goto V_130;
case - V_22 :
V_8 = - V_24 ;
if ( V_91 != * V_56 )
goto V_130;
V_91 = F_289 ( V_91 , V_3 , V_240 ) ;
if ( F_43 ( V_91 ) )
return F_71 ( V_91 ) ;
V_62 . V_67 = 1 ;
break;
default:
V_8 = F_20 ( F_87 ( V_3 ) , V_8 , & V_62 ) ;
}
} while ( V_62 . V_67 );
V_130:
if ( V_8 == 0 )
* V_56 = V_91 ;
else if ( V_91 != * V_56 )
F_290 ( V_91 ) ;
return V_8 ;
}
static int F_291 ( struct V_2 * V_3 , struct V_482 * V_240 ,
struct V_424 * V_425 , struct V_386 * V_387 ,
struct V_1 * V_7 )
{
int V_305 ;
struct V_55 * V_91 = F_292 ( V_3 ) ;
V_305 = F_287 ( & V_91 , V_3 , V_240 , V_425 , V_387 , V_7 ) ;
if ( V_91 != F_292 ( V_3 ) ) {
F_290 ( V_91 ) ;
F_286 ( V_387 ) ;
}
return V_305 ;
}
struct V_55 *
F_293 ( struct V_2 * V_3 , struct V_482 * V_240 ,
struct V_424 * V_425 , struct V_386 * V_387 )
{
struct V_55 * V_91 = F_292 ( V_3 ) ;
int V_305 ;
V_305 = F_287 ( & V_91 , V_3 , V_240 , V_425 , V_387 , NULL ) ;
if ( V_305 < 0 )
return F_44 ( V_305 ) ;
return ( V_91 == F_292 ( V_3 ) ) ? F_294 ( V_91 ) : V_91 ;
}
static int F_295 ( struct V_2 * V_2 , struct V_350 * V_502 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_503 args = {
. V_244 = F_94 ( V_2 ) ,
. V_241 = V_14 -> V_421 ,
} ;
struct V_504 V_57 = {
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_505 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_502 -> V_349 ,
} ;
int V_255 = V_502 -> V_352 ;
int V_305 = 0 ;
if ( V_255 & V_357 )
args . V_209 |= V_230 ;
if ( F_296 ( V_2 -> V_506 ) ) {
if ( V_255 & V_507 )
args . V_209 |= V_231 | V_232 | V_508 ;
if ( V_255 & V_355 )
args . V_209 |= V_509 ;
} else {
if ( V_255 & V_507 )
args . V_209 |= V_231 | V_232 ;
if ( V_255 & V_355 )
args . V_209 |= V_233 ;
}
V_57 . V_387 = F_297 () ;
if ( V_57 . V_387 == NULL )
return - V_125 ;
V_305 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
if ( ! V_305 ) {
F_189 ( V_502 , V_57 . V_209 ) ;
F_148 ( V_2 , V_57 . V_387 ) ;
}
F_298 ( V_57 . V_387 ) ;
return V_305 ;
}
static int F_299 ( struct V_2 * V_2 , struct V_350 * V_502 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_295 ( V_2 , V_502 ) ;
F_300 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_301 ( struct V_2 * V_2 , struct V_483 * V_483 ,
unsigned int V_49 , unsigned int V_510 )
{
struct V_511 args = {
. V_244 = F_94 ( V_2 ) ,
. V_49 = V_49 ,
. V_510 = V_510 ,
. V_42 = & V_483 ,
} ;
struct V_512 V_57 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_513 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
return F_73 ( F_87 ( V_2 ) -> V_91 , F_87 ( V_2 ) , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_302 ( struct V_2 * V_2 , struct V_483 * V_483 ,
unsigned int V_49 , unsigned int V_510 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_301 ( V_2 , V_483 , V_49 , V_510 ) ;
F_303 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int
F_304 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_214 )
{
struct V_1 V_17 , * V_388 = NULL ;
struct V_299 * V_300 ;
struct V_65 * V_66 ;
int V_373 = 0 ;
int V_305 = 0 ;
V_300 = F_305 ( V_4 , V_69 ) ;
if ( F_43 ( V_300 ) )
return F_71 ( V_300 ) ;
V_388 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_306 () ;
V_66 = F_230 ( V_3 , V_300 , V_214 , V_6 , V_388 , & V_373 ) ;
if ( F_43 ( V_66 ) ) {
V_305 = F_71 ( V_66 ) ;
goto V_130;
}
V_130:
F_4 ( V_388 ) ;
F_168 ( V_300 ) ;
return V_305 ;
}
static int F_307 ( struct V_2 * V_3 , struct V_482 * V_240 )
{
struct V_13 * V_14 = F_87 ( V_3 ) ;
struct V_514 args = {
. V_244 = F_94 ( V_3 ) ,
. V_240 = * V_240 ,
} ;
struct V_515 V_57 = {
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_516 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
int V_305 ;
V_305 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 1 ) ;
if ( V_305 == 0 )
F_74 ( V_3 , & V_57 . V_171 ) ;
return V_305 ;
}
static int F_308 ( struct V_2 * V_3 , struct V_482 * V_240 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_307 ( V_3 , V_240 ) ;
F_309 ( V_3 , V_240 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static void F_310 ( struct V_161 * V_162 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_87 ( V_3 ) ;
struct V_514 * args = V_162 -> V_313 ;
struct V_515 * V_57 = V_162 -> V_314 ;
V_57 -> V_14 = V_14 ;
V_162 -> V_310 = & V_311 [ V_516 ] ;
F_38 ( & args -> V_159 , & V_57 -> V_160 , 1 ) ;
F_83 ( V_57 -> V_517 ) ;
}
static void F_311 ( struct V_118 * V_119 , struct V_518 * V_157 )
{
F_63 ( F_87 ( V_157 -> V_3 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_119 ) ;
}
static int F_312 ( struct V_118 * V_119 , struct V_2 * V_3 )
{
struct V_518 * V_157 = V_119 -> V_519 ;
struct V_515 * V_57 = & V_157 -> V_57 ;
if ( ! F_60 ( V_119 , & V_57 -> V_160 ) )
return 0 ;
if ( F_244 ( V_119 , V_57 -> V_14 , NULL ,
& V_157 -> V_51 ) == - V_129 )
return 0 ;
F_74 ( V_3 , & V_57 -> V_171 ) ;
return 1 ;
}
static void F_313 ( struct V_161 * V_162 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_87 ( V_3 ) ;
struct V_520 * V_390 = V_162 -> V_313 ;
struct V_521 * V_57 = V_162 -> V_314 ;
V_162 -> V_310 = & V_311 [ V_522 ] ;
V_57 -> V_14 = V_14 ;
F_38 ( & V_390 -> V_159 , & V_57 -> V_160 , 1 ) ;
}
static void F_314 ( struct V_118 * V_119 , struct V_523 * V_157 )
{
F_63 ( F_87 ( V_157 -> V_524 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_119 ) ;
}
static int F_315 ( struct V_118 * V_119 , struct V_2 * V_524 ,
struct V_2 * V_525 )
{
struct V_523 * V_157 = V_119 -> V_519 ;
struct V_521 * V_57 = & V_157 -> V_57 ;
if ( ! F_60 ( V_119 , & V_57 -> V_160 ) )
return 0 ;
if ( F_244 ( V_119 , V_57 -> V_14 , NULL , & V_157 -> V_51 ) == - V_129 )
return 0 ;
F_74 ( V_524 , & V_57 -> V_526 ) ;
F_74 ( V_525 , & V_57 -> V_527 ) ;
return 1 ;
}
static int F_316 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_482 * V_240 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_528 V_390 = {
. V_244 = F_94 ( V_2 ) ,
. V_494 = F_94 ( V_3 ) ,
. V_240 = V_240 ,
. V_241 = V_14 -> V_15 ,
} ;
struct V_529 V_57 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_530 ] ,
. V_313 = & V_390 ,
. V_314 = & V_57 ,
} ;
int V_305 = - V_125 ;
V_57 . V_387 = F_297 () ;
if ( V_57 . V_387 == NULL )
goto V_130;
V_57 . V_7 = F_89 ( V_14 , V_378 ) ;
if ( F_43 ( V_57 . V_7 ) ) {
V_305 = F_71 ( V_57 . V_7 ) ;
goto V_130;
}
V_390 . V_241 = F_6 ( V_14 , V_57 . V_7 ) ;
V_305 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_390 . V_159 , & V_57 . V_160 , 1 ) ;
if ( ! V_305 ) {
F_74 ( V_3 , & V_57 . V_171 ) ;
V_305 = F_317 ( V_2 , V_57 . V_387 ) ;
if ( ! V_305 )
F_228 ( V_2 , V_57 . V_387 , V_57 . V_7 ) ;
}
F_96 ( V_57 . V_7 ) ;
V_130:
F_298 ( V_57 . V_387 ) ;
return V_305 ;
}
static int F_318 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_482 * V_240 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_87 ( V_2 ) ,
F_316 ( V_2 , V_3 , V_240 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static struct V_531 * F_319 ( struct V_2 * V_3 ,
struct V_482 * V_240 , struct V_5 * V_6 , T_1 V_532 )
{
struct V_531 * V_157 ;
V_157 = F_88 ( sizeof( * V_157 ) , V_378 ) ;
if ( V_157 != NULL ) {
struct V_13 * V_14 = F_87 ( V_3 ) ;
V_157 -> V_7 = F_89 ( V_14 , V_378 ) ;
if ( F_43 ( V_157 -> V_7 ) )
goto V_309;
V_157 -> V_162 . V_310 = & V_311 [ V_533 ] ;
V_157 -> V_162 . V_313 = & V_157 -> V_390 ;
V_157 -> V_162 . V_314 = & V_157 -> V_57 ;
V_157 -> V_390 . V_494 = F_94 ( V_3 ) ;
V_157 -> V_390 . V_14 = V_14 ;
V_157 -> V_390 . V_240 = V_240 ;
V_157 -> V_390 . V_215 = V_6 ;
V_157 -> V_390 . V_532 = V_532 ;
V_157 -> V_390 . V_241 = F_6 ( V_14 , V_157 -> V_7 ) ;
V_157 -> V_57 . V_14 = V_14 ;
V_157 -> V_57 . V_244 = & V_157 -> V_244 ;
V_157 -> V_57 . V_387 = & V_157 -> V_387 ;
V_157 -> V_57 . V_7 = V_157 -> V_7 ;
F_83 ( V_157 -> V_57 . V_387 ) ;
}
return V_157 ;
V_309:
F_97 ( V_157 ) ;
return NULL ;
}
static int F_320 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_531 * V_157 )
{
int V_305 = F_73 ( F_87 ( V_3 ) -> V_91 , F_87 ( V_3 ) , & V_157 -> V_162 ,
& V_157 -> V_390 . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
if ( V_305 == 0 ) {
F_74 ( V_3 , & V_157 -> V_57 . V_534 ) ;
V_305 = F_321 ( V_4 , V_157 -> V_57 . V_244 , V_157 -> V_57 . V_387 , V_157 -> V_57 . V_7 ) ;
}
return V_305 ;
}
static void F_322 ( struct V_531 * V_157 )
{
F_96 ( V_157 -> V_7 ) ;
F_97 ( V_157 ) ;
}
static int F_323 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_483 * V_483 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_531 * V_157 ;
int V_305 = - V_535 ;
if ( V_12 > V_536 )
goto V_130;
V_305 = - V_125 ;
V_157 = F_319 ( V_3 , & V_4 -> V_11 , V_6 , V_537 ) ;
if ( V_157 == NULL )
goto V_130;
V_157 -> V_162 . V_310 = & V_311 [ V_538 ] ;
V_157 -> V_390 . V_248 . V_539 . V_42 = & V_483 ;
V_157 -> V_390 . V_248 . V_539 . V_12 = V_12 ;
V_157 -> V_390 . V_7 = V_7 ;
V_305 = F_320 ( V_3 , V_4 , V_157 ) ;
F_322 ( V_157 ) ;
V_130:
return V_305 ;
}
static int F_324 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_483 * V_483 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_323 ( V_3 , V_4 , V_483 , V_12 , V_6 , V_7 ) ;
F_325 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_326 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_531 * V_157 ;
int V_305 = - V_125 ;
V_157 = F_319 ( V_3 , & V_4 -> V_11 , V_6 , V_540 ) ;
if ( V_157 == NULL )
goto V_130;
V_157 -> V_390 . V_7 = V_7 ;
V_305 = F_320 ( V_3 , V_4 , V_157 ) ;
F_322 ( V_157 ) ;
V_130:
return V_305 ;
}
static int F_327 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_306 () ;
do {
V_8 = F_326 ( V_3 , V_4 , V_6 , V_7 ) ;
F_328 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_329 ( struct V_4 * V_4 , struct V_315 * V_349 ,
T_2 V_36 , struct V_483 * * V_42 , unsigned int V_50 , int V_541 )
{
struct V_2 * V_3 = V_4 -> V_46 ;
struct V_38 args = {
. V_244 = F_94 ( V_3 ) ,
. V_42 = V_42 ,
. V_49 = 0 ,
. V_50 = V_50 ,
. V_241 = F_87 ( V_4 -> V_46 ) -> V_15 ,
. V_541 = V_541 ,
} ;
struct V_542 V_57 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_543 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
int V_305 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_75 ( V_3 ) -> V_544 , V_4 , & args ) ;
V_57 . V_49 = args . V_49 ;
V_305 = F_73 ( F_87 ( V_3 ) -> V_91 , F_87 ( V_3 ) , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
if ( V_305 >= 0 ) {
memcpy ( F_75 ( V_3 ) -> V_544 , V_57 . V_37 . V_157 , V_545 ) ;
V_305 += args . V_49 ;
}
F_330 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_305 ) ;
return V_305 ;
}
static int F_331 ( struct V_4 * V_4 , struct V_315 * V_349 ,
T_2 V_36 , struct V_483 * * V_42 , unsigned int V_50 , int V_541 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_329 ( V_4 , V_349 , V_36 ,
V_42 , V_50 , V_541 ) ;
F_332 ( V_4 -> V_46 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_4 -> V_46 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_333 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_546 )
{
struct V_531 * V_157 ;
int V_255 = V_6 -> V_10 ;
int V_305 = - V_125 ;
V_157 = F_319 ( V_3 , & V_4 -> V_11 , V_6 , V_547 ) ;
if ( V_157 == NULL )
goto V_130;
if ( F_334 ( V_255 ) )
V_157 -> V_390 . V_532 = V_548 ;
else if ( F_335 ( V_255 ) ) {
V_157 -> V_390 . V_532 = V_549 ;
V_157 -> V_390 . V_248 . V_550 . V_551 = F_336 ( V_546 ) ;
V_157 -> V_390 . V_248 . V_550 . V_552 = F_337 ( V_546 ) ;
}
else if ( F_338 ( V_255 ) ) {
V_157 -> V_390 . V_532 = V_553 ;
V_157 -> V_390 . V_248 . V_550 . V_551 = F_336 ( V_546 ) ;
V_157 -> V_390 . V_248 . V_550 . V_552 = F_337 ( V_546 ) ;
} else if ( ! F_339 ( V_255 ) ) {
V_305 = - V_27 ;
goto V_309;
}
V_157 -> V_390 . V_7 = V_7 ;
V_305 = F_320 ( V_3 , V_4 , V_157 ) ;
V_309:
F_322 ( V_157 ) ;
V_130:
return V_305 ;
}
static int F_340 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_546 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_306 () ;
do {
V_8 = F_333 ( V_3 , V_4 , V_6 , V_7 , V_546 ) ;
F_341 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_342 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_554 * V_555 )
{
struct V_556 args = {
. V_244 = V_425 ,
. V_241 = V_14 -> V_15 ,
} ;
struct V_557 V_57 = {
. V_555 = V_555 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_558 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
F_83 ( V_555 -> V_387 ) ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_343 ( struct V_13 * V_14 , struct V_424 * V_425 , struct V_554 * V_555 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_342 ( V_14 , V_425 , V_555 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_344 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_559 )
{
struct V_560 args = {
. V_244 = V_425 ,
. V_241 = V_14 -> V_15 ,
} ;
struct V_561 V_57 = {
. V_559 = V_559 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_562 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_269 ( struct V_13 * V_14 , struct V_424 * V_425 , struct V_458 * V_559 )
{
struct V_61 V_62 = { } ;
unsigned long V_563 = V_153 ;
int V_8 ;
do {
V_8 = F_344 ( V_14 , V_425 , V_559 ) ;
F_345 ( V_14 , V_425 , V_559 -> V_387 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_63 * V_64 = V_14 -> V_63 ;
F_34 ( & V_64 -> V_107 ) ;
V_64 -> V_564 = V_559 -> V_565 * V_88 ;
V_64 -> V_108 = V_563 ;
F_36 ( & V_64 -> V_107 ) ;
break;
}
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_346 ( struct V_13 * V_14 , struct V_424 * V_425 , struct V_458 * V_559 )
{
int error ;
F_83 ( V_559 -> V_387 ) ;
error = F_269 ( V_14 , V_425 , V_559 ) ;
if ( error == 0 ) {
V_14 -> V_566 = V_559 -> V_567 ;
F_347 ( V_14 , V_425 , V_559 -> V_568 ) ;
}
return error ;
}
static int F_348 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_569 * V_570 )
{
struct V_571 args = {
. V_244 = V_425 ,
. V_241 = V_14 -> V_15 ,
} ;
struct V_572 V_57 = {
. V_570 = V_570 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_573 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
if ( ( args . V_241 [ 0 ] & V_574 [ 0 ] ) == 0 ) {
memset ( V_570 , 0 , sizeof( * V_570 ) ) ;
return 0 ;
}
F_83 ( V_570 -> V_387 ) ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_349 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_569 * V_570 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_348 ( V_14 , V_425 , V_570 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
int F_350 ( T_8 * V_250 ,
const struct V_299 * V_300 ,
const struct V_575 * V_576 ,
T_5 V_184 )
{
const struct V_396 * V_397 = NULL ;
if ( V_576 != NULL )
V_397 = & V_576 -> V_397 ;
return F_236 ( V_250 , V_300 -> V_66 , V_184 , V_397 ) ;
}
static bool F_351 ( T_8 * V_250 ,
const struct V_299 * V_300 ,
const struct V_575 * V_576 ,
T_5 V_184 )
{
T_8 V_577 ;
if ( F_350 ( & V_577 , V_300 , V_576 , V_184 ) == - V_35 )
return true ;
return F_136 ( V_250 , & V_577 ) ;
}
static bool F_352 ( int V_8 )
{
switch ( V_8 ) {
case - V_71 :
case - V_72 :
case - V_73 :
case - V_75 :
case - V_93 :
case - V_68 :
case - V_74 :
return true ;
}
return false ;
}
void F_353 ( struct V_578 * V_579 )
{
F_330 ( V_579 -> V_2 ) ;
}
static int F_354 ( struct V_118 * V_119 , struct V_578 * V_579 )
{
struct V_13 * V_14 = F_87 ( V_579 -> V_2 ) ;
F_355 ( V_579 , V_119 -> V_148 ) ;
if ( F_244 ( V_119 , V_14 ,
V_579 -> args . V_580 -> V_66 ,
NULL ) == - V_129 ) {
F_57 ( V_119 ) ;
return - V_129 ;
}
F_353 ( V_579 ) ;
if ( V_119 -> V_148 > 0 )
F_37 ( V_14 , V_579 -> V_106 ) ;
return 0 ;
}
static bool F_356 ( struct V_118 * V_119 ,
struct V_581 * args )
{
if ( ! F_352 ( V_119 -> V_148 ) ||
F_351 ( & args -> V_250 ,
args -> V_580 ,
args -> V_582 ,
V_69 ) )
return false ;
F_57 ( V_119 ) ;
return true ;
}
static int F_357 ( struct V_118 * V_119 , struct V_578 * V_579 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_119 , & V_579 -> V_57 . V_160 ) )
return - V_129 ;
if ( F_356 ( V_119 , & V_579 -> args ) )
return - V_129 ;
return V_579 -> V_583 ? V_579 -> V_583 ( V_119 , V_579 ) :
F_354 ( V_119 , V_579 ) ;
}
static void F_358 ( struct V_578 * V_579 ,
struct V_161 * V_162 )
{
V_579 -> V_106 = V_153 ;
V_579 -> V_583 = F_354 ;
V_162 -> V_310 = & V_311 [ V_584 ] ;
F_38 ( & V_579 -> args . V_159 , & V_579 -> V_57 . V_160 , 0 ) ;
}
static int F_359 ( struct V_118 * V_119 ,
struct V_578 * V_579 )
{
if ( F_63 ( F_87 ( V_579 -> V_2 ) ,
& V_579 -> args . V_159 ,
& V_579 -> V_57 . V_160 ,
V_119 ) )
return 0 ;
if ( F_350 ( & V_579 -> args . V_250 , V_579 -> args . V_580 ,
V_579 -> args . V_582 ,
V_579 -> V_585 -> V_586 ) == - V_35 )
return - V_35 ;
if ( F_360 ( F_31 ( V_587 , & V_579 -> args . V_580 -> V_214 ) ) )
return - V_35 ;
return 0 ;
}
static int F_361 ( struct V_118 * V_119 ,
struct V_578 * V_579 )
{
struct V_2 * V_2 = V_579 -> V_2 ;
F_362 ( V_579 , V_119 -> V_148 ) ;
if ( F_244 ( V_119 , F_87 ( V_2 ) ,
V_579 -> args . V_580 -> V_66 ,
NULL ) == - V_129 ) {
F_57 ( V_119 ) ;
return - V_129 ;
}
if ( V_119 -> V_148 >= 0 ) {
F_37 ( F_87 ( V_2 ) , V_579 -> V_106 ) ;
F_363 ( V_579 ) ;
}
return 0 ;
}
static bool F_364 ( struct V_118 * V_119 ,
struct V_581 * args )
{
if ( ! F_352 ( V_119 -> V_148 ) ||
F_351 ( & args -> V_250 ,
args -> V_580 ,
args -> V_582 ,
V_186 ) )
return false ;
F_57 ( V_119 ) ;
return true ;
}
static int F_365 ( struct V_118 * V_119 , struct V_578 * V_579 )
{
if ( ! F_60 ( V_119 , & V_579 -> V_57 . V_160 ) )
return - V_129 ;
if ( F_364 ( V_119 , & V_579 -> args ) )
return - V_129 ;
return V_579 -> V_583 ? V_579 -> V_583 ( V_119 , V_579 ) :
F_361 ( V_119 , V_579 ) ;
}
static
bool F_366 ( struct V_578 * V_579 )
{
if ( V_579 -> V_588 != NULL || V_579 -> V_589 != NULL )
return false ;
return F_21 ( V_579 -> V_2 , V_69 ) == 0 ;
}
static void F_367 ( struct V_578 * V_579 ,
struct V_161 * V_162 )
{
struct V_13 * V_14 = F_87 ( V_579 -> V_2 ) ;
if ( ! F_366 ( V_579 ) ) {
V_579 -> args . V_241 = NULL ;
V_579 -> V_57 . V_387 = NULL ;
} else
V_579 -> args . V_241 = V_14 -> V_421 ;
if ( ! V_579 -> V_583 )
V_579 -> V_583 = F_361 ;
V_579 -> V_57 . V_14 = V_14 ;
V_579 -> V_106 = V_153 ;
V_162 -> V_310 = & V_311 [ V_590 ] ;
F_38 ( & V_579 -> args . V_159 , & V_579 -> V_57 . V_160 , 1 ) ;
}
static void F_368 ( struct V_118 * V_119 , struct V_591 * V_157 )
{
F_63 ( F_87 ( V_157 -> V_2 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_119 ) ;
}
static int F_369 ( struct V_118 * V_119 , struct V_591 * V_157 )
{
struct V_2 * V_2 = V_157 -> V_2 ;
F_370 ( V_157 , V_119 -> V_148 ) ;
if ( F_244 ( V_119 , F_87 ( V_2 ) ,
NULL , NULL ) == - V_129 ) {
F_57 ( V_119 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_371 ( struct V_118 * V_119 , struct V_591 * V_157 )
{
if ( ! F_60 ( V_119 , & V_157 -> V_57 . V_160 ) )
return - V_129 ;
return V_157 -> V_592 ( V_119 , V_157 ) ;
}
static void F_372 ( struct V_591 * V_157 , struct V_161 * V_162 )
{
struct V_13 * V_14 = F_87 ( V_157 -> V_2 ) ;
if ( V_157 -> V_592 == NULL )
V_157 -> V_592 = F_369 ;
V_157 -> V_57 . V_14 = V_14 ;
V_162 -> V_310 = & V_311 [ V_593 ] ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
}
static void F_373 ( void * V_155 )
{
struct V_594 * V_157 = V_155 ;
struct V_63 * V_64 = V_157 -> V_91 ;
if ( F_374 ( & V_64 -> V_595 ) > 1 )
F_375 ( V_64 ) ;
F_376 ( V_64 ) ;
F_97 ( V_157 ) ;
}
static void F_377 ( struct V_118 * V_119 , void * V_155 )
{
struct V_594 * V_157 = V_155 ;
struct V_63 * V_64 = V_157 -> V_91 ;
unsigned long V_106 = V_157 -> V_106 ;
F_378 ( V_64 , V_119 -> V_148 ) ;
switch ( V_119 -> V_148 ) {
case 0 :
break;
case - V_78 :
F_26 ( V_64 ) ;
break;
default:
if ( F_31 ( V_596 , & V_64 -> V_597 ) == 0 )
return;
if ( V_119 -> V_148 != V_598 ) {
F_24 ( V_64 ) ;
return;
}
F_379 ( V_64 ) ;
}
F_33 ( V_64 , V_106 ) ;
}
static int F_380 ( struct V_63 * V_64 , struct V_315 * V_349 , unsigned V_599 )
{
struct V_161 V_162 = {
. V_310 = & V_311 [ V_600 ] ,
. V_313 = V_64 ,
. V_315 = V_349 ,
} ;
struct V_594 * V_157 ;
if ( V_599 == 0 )
return 0 ;
if ( ! F_381 ( & V_64 -> V_595 ) )
return - V_35 ;
V_157 = F_274 ( sizeof( * V_157 ) , V_302 ) ;
if ( V_157 == NULL )
return - V_125 ;
V_157 -> V_91 = V_64 ;
V_157 -> V_106 = V_153 ;
return F_382 ( V_64 -> V_101 , & V_162 , V_601 ,
& V_602 , V_157 ) ;
}
static int F_383 ( struct V_63 * V_64 , struct V_315 * V_349 )
{
struct V_161 V_162 = {
. V_310 = & V_311 [ V_600 ] ,
. V_313 = V_64 ,
. V_315 = V_349 ,
} ;
unsigned long V_563 = V_153 ;
int V_305 ;
V_305 = F_384 ( V_64 -> V_101 , & V_162 , V_601 ) ;
if ( V_305 < 0 )
return V_305 ;
F_33 ( V_64 , V_563 ) ;
return 0 ;
}
static inline int F_385 ( struct V_13 * V_14 )
{
return V_14 -> V_94 & V_433 ;
}
static int F_386 ( const void * V_603 , T_9 V_604 ,
struct V_483 * * V_42 , unsigned int * V_49 )
{
struct V_483 * V_605 , * * V_606 ;
int V_607 = 0 ;
T_9 V_12 ;
V_606 = V_42 ;
do {
V_12 = F_387 ( T_9 , V_608 , V_604 ) ;
V_605 = F_273 ( V_378 ) ;
if ( V_605 == NULL )
goto V_609;
memcpy ( F_388 ( V_605 ) , V_603 , V_12 ) ;
V_603 += V_12 ;
V_604 -= V_12 ;
* V_42 ++ = V_605 ;
V_607 ++ ;
} while ( V_604 != 0 );
return V_607 ;
V_609:
for(; V_607 > 0 ; V_607 -- )
F_277 ( V_606 [ V_607 - 1 ] ) ;
return - V_125 ;
}
static void F_389 ( struct V_2 * V_2 , struct V_610 * V_611 )
{
struct V_172 * V_173 = F_75 ( V_2 ) ;
F_34 ( & V_2 -> V_174 ) ;
F_97 ( V_173 -> V_612 ) ;
V_173 -> V_612 = V_611 ;
F_36 ( & V_2 -> V_174 ) ;
}
static void F_390 ( struct V_2 * V_2 )
{
F_389 ( V_2 , NULL ) ;
}
static inline T_11 F_391 ( struct V_2 * V_2 , char * V_603 , T_9 V_604 )
{
struct V_172 * V_173 = F_75 ( V_2 ) ;
struct V_610 * V_611 ;
int V_52 = - V_301 ;
F_34 ( & V_2 -> V_174 ) ;
V_611 = V_173 -> V_612 ;
if ( V_611 == NULL )
goto V_130;
if ( V_603 == NULL )
goto V_613;
if ( V_611 -> V_614 == 0 )
goto V_130;
V_52 = - V_615 ;
if ( V_611 -> V_12 > V_604 )
goto V_130;
memcpy ( V_603 , V_611 -> V_157 , V_611 -> V_12 ) ;
V_613:
V_52 = V_611 -> V_12 ;
V_130:
F_36 ( & V_2 -> V_174 ) ;
return V_52 ;
}
static void F_392 ( struct V_2 * V_2 , struct V_483 * * V_42 , T_9 V_49 , T_9 V_616 )
{
struct V_610 * V_611 ;
T_9 V_604 = sizeof( * V_611 ) + V_616 ;
if ( V_604 <= V_608 ) {
V_611 = F_274 ( V_604 , V_378 ) ;
if ( V_611 == NULL )
goto V_130;
V_611 -> V_614 = 1 ;
F_393 ( V_611 -> V_157 , V_42 , V_49 , V_616 ) ;
} else {
V_611 = F_274 ( sizeof( * V_611 ) , V_378 ) ;
if ( V_611 == NULL )
goto V_130;
V_611 -> V_614 = 0 ;
}
V_611 -> V_12 = V_616 ;
V_130:
F_389 ( V_2 , V_611 ) ;
}
static T_11 F_394 ( struct V_2 * V_2 , void * V_603 , T_9 V_604 )
{
struct V_483 * V_42 [ V_617 ] = { NULL , } ;
struct V_618 args = {
. V_244 = F_94 ( V_2 ) ,
. V_619 = V_42 ,
. V_616 = V_604 ,
} ;
struct V_620 V_57 = {
. V_616 = V_604 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_621 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
unsigned int V_622 = F_395 ( V_604 , V_608 ) ;
int V_52 = - V_125 , V_472 ;
if ( V_622 == 0 )
V_622 = 1 ;
if ( V_622 > F_265 ( V_42 ) )
return - V_615 ;
for ( V_472 = 0 ; V_472 < V_622 ; V_472 ++ ) {
V_42 [ V_472 ] = F_273 ( V_378 ) ;
if ( ! V_42 [ V_472 ] )
goto V_309;
}
V_57 . V_623 = F_273 ( V_378 ) ;
if ( ! V_57 . V_623 )
goto V_309;
args . V_616 = V_622 * V_608 ;
args . V_624 = 0 ;
F_8 ( L_40 ,
V_34 , V_603 , V_604 , V_622 , args . V_616 ) ;
V_52 = F_73 ( F_87 ( V_2 ) -> V_91 , F_87 ( V_2 ) ,
& V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
if ( V_52 )
goto V_309;
if ( V_57 . V_625 & V_626 ) {
if ( V_603 == NULL )
goto V_627;
V_52 = - V_615 ;
goto V_309;
}
F_392 ( V_2 , V_42 , V_57 . V_628 , V_57 . V_616 ) ;
if ( V_603 ) {
if ( V_57 . V_616 > V_604 ) {
V_52 = - V_615 ;
goto V_309;
}
F_393 ( V_603 , V_42 , V_57 . V_628 , V_57 . V_616 ) ;
}
V_627:
V_52 = V_57 . V_616 ;
V_309:
for ( V_472 = 0 ; V_472 < V_622 ; V_472 ++ )
if ( V_42 [ V_472 ] )
F_277 ( V_42 [ V_472 ] ) ;
if ( V_57 . V_623 )
F_277 ( V_57 . V_623 ) ;
return V_52 ;
}
static T_11 F_396 ( struct V_2 * V_2 , void * V_603 , T_9 V_604 )
{
struct V_61 V_62 = { } ;
T_11 V_52 ;
do {
V_52 = F_394 ( V_2 , V_603 , V_604 ) ;
F_397 ( V_2 , V_52 ) ;
if ( V_52 >= 0 )
break;
V_52 = F_20 ( F_87 ( V_2 ) , V_52 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_52 ;
}
static T_11 F_398 ( struct V_2 * V_2 , void * V_603 , T_9 V_604 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
int V_52 ;
if ( ! F_385 ( V_14 ) )
return - V_629 ;
V_52 = F_399 ( V_14 , V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( F_75 ( V_2 ) -> V_175 & V_630 )
F_400 ( V_2 ) ;
V_52 = F_391 ( V_2 , V_603 , V_604 ) ;
if ( V_52 != - V_301 )
return V_52 ;
return F_396 ( V_2 , V_603 , V_604 ) ;
}
static int F_401 ( struct V_2 * V_2 , const void * V_603 , T_9 V_604 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_483 * V_42 [ V_617 ] ;
struct V_631 V_390 = {
. V_244 = F_94 ( V_2 ) ,
. V_619 = V_42 ,
. V_616 = V_604 ,
} ;
struct V_632 V_57 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_633 ] ,
. V_313 = & V_390 ,
. V_314 = & V_57 ,
} ;
unsigned int V_622 = F_395 ( V_604 , V_608 ) ;
int V_52 , V_472 ;
if ( ! F_385 ( V_14 ) )
return - V_629 ;
if ( V_622 > F_265 ( V_42 ) )
return - V_615 ;
V_472 = F_386 ( V_603 , V_604 , V_390 . V_619 , & V_390 . V_624 ) ;
if ( V_472 < 0 )
return V_472 ;
F_22 ( V_2 ) ;
V_52 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_390 . V_159 , & V_57 . V_160 , 1 ) ;
for (; V_472 > 0 ; V_472 -- )
F_402 ( V_42 [ V_472 - 1 ] ) ;
F_34 ( & V_2 -> V_174 ) ;
F_75 ( V_2 ) -> V_175 |= V_176 ;
F_36 ( & V_2 -> V_174 ) ;
F_403 ( V_2 ) ;
F_400 ( V_2 ) ;
return V_52 ;
}
static int F_404 ( struct V_2 * V_2 , const void * V_603 , T_9 V_604 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_401 ( V_2 , V_603 , V_604 ) ;
F_405 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_406 ( struct V_2 * V_2 , void * V_603 ,
T_9 V_604 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_386 V_387 ;
struct V_1 V_7 = { 0 , 0 , V_604 , V_603 } ;
T_1 V_241 [ 3 ] = { 0 , 0 , V_454 } ;
struct V_486 V_390 = {
. V_244 = F_94 ( V_2 ) ,
. V_241 = V_241 ,
} ;
struct V_487 V_57 = {
. V_387 = & V_387 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_488 ] ,
. V_313 = & V_390 ,
. V_314 = & V_57 ,
} ;
int V_52 ;
F_83 ( & V_387 ) ;
V_52 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_390 . V_159 , & V_57 . V_160 , 0 ) ;
if ( V_52 )
return V_52 ;
if ( ! ( V_387 . V_296 & V_634 ) )
return - V_301 ;
if ( V_604 < V_7 . V_12 )
return - V_615 ;
return 0 ;
}
static int F_407 ( struct V_2 * V_2 , void * V_603 ,
T_9 V_604 )
{
struct V_61 V_62 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_629 ;
do {
V_8 = F_406 ( V_2 , V_603 , V_604 ) ;
F_408 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_409 ( struct V_2 * V_2 ,
struct V_1 * V_388 ,
struct V_386 * V_387 ,
struct V_1 * V_377 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_87 ( V_2 ) ;
const T_1 V_241 [ 3 ] = { 0 , 0 , V_454 } ;
struct V_389 V_390 = {
. V_244 = F_94 ( V_2 ) ,
. V_391 = & V_6 ,
. V_14 = V_14 ,
. V_241 = V_241 ,
. V_7 = V_388 ,
} ;
struct V_392 V_57 = {
. V_387 = V_387 ,
. V_7 = V_377 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_393 ] ,
. V_313 = & V_390 ,
. V_314 = & V_57 ,
} ;
int V_305 ;
F_126 ( & V_390 . V_250 , & V_403 ) ;
V_305 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_390 . V_159 , & V_57 . V_160 , 1 ) ;
if ( V_305 )
F_8 ( L_41 , V_34 , V_305 ) ;
return V_305 ;
}
static int F_410 ( struct V_2 * V_2 ,
struct V_1 * V_388 ,
struct V_386 * V_387 ,
struct V_1 * V_377 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_409 ( V_2 , V_388 ,
V_387 , V_377 ) ;
F_411 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int
F_412 ( struct V_4 * V_4 , const void * V_603 , T_9 V_604 )
{
struct V_1 V_388 , * V_377 = NULL ;
struct V_386 V_387 ;
struct V_315 * V_349 ;
struct V_2 * V_2 = V_4 -> V_46 ;
int V_305 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_629 ;
F_83 ( & V_387 ) ;
V_388 . V_635 = 0 ;
V_388 . V_636 = 0 ;
V_388 . V_7 = ( char * ) V_603 ;
V_388 . V_12 = V_604 ;
V_349 = F_413 () ;
if ( F_43 ( V_349 ) )
return F_71 ( V_349 ) ;
V_377 = F_89 ( F_87 ( V_2 ) , V_378 ) ;
if ( F_43 ( V_377 ) ) {
V_305 = - F_71 ( V_377 ) ;
goto V_130;
}
V_305 = F_410 ( V_2 , & V_388 , & V_387 , V_377 ) ;
if ( V_305 == 0 )
F_228 ( V_2 , & V_387 , V_377 ) ;
F_96 ( V_377 ) ;
V_130:
F_210 ( V_349 ) ;
return V_305 ;
}
static int
F_244 ( struct V_118 * V_119 , const struct V_13 * V_14 ,
struct V_65 * V_66 , long * V_51 )
{
struct V_63 * V_64 = V_14 -> V_63 ;
if ( V_119 -> V_148 >= 0 )
return 0 ;
switch( V_119 -> V_148 ) {
case - V_71 :
case - V_72 :
case - V_73 :
case - V_68 :
if ( V_66 == NULL )
break;
if ( F_23 ( V_14 , V_66 ) < 0 )
goto V_637;
goto V_70;
case - V_74 :
if ( V_66 != NULL ) {
if ( F_23 ( V_14 , V_66 ) < 0 )
goto V_637;
}
case - V_75 :
case - V_76 :
F_24 ( V_64 ) ;
goto V_70;
case - V_77 :
if ( F_25 ( V_14 ) < 0 )
goto V_637;
goto V_70;
case - V_78 :
F_26 ( V_64 ) ;
goto V_70;
#if F_27 ( V_79 )
case - V_80 :
case - V_81 :
case - V_82 :
case - V_84 :
case - V_83 :
case - V_85 :
case - V_86 :
F_8 ( L_42 , V_34 ,
V_119 -> V_148 ) ;
F_28 ( V_64 -> V_87 , V_119 -> V_148 ) ;
goto V_70;
#endif
case - V_90 :
F_414 ( V_14 , V_638 ) ;
F_59 ( V_119 , F_15 ( V_51 ) ) ;
goto V_639;
case - V_89 :
F_59 ( V_119 , V_53 ) ;
case - V_92 :
case - V_93 :
goto V_639;
}
V_119 -> V_148 = F_7 ( V_119 -> V_148 ) ;
return 0 ;
V_637:
V_119 -> V_148 = - V_35 ;
return 0 ;
V_70:
F_47 ( & V_64 -> V_640 , V_119 , NULL ) ;
if ( F_31 ( V_641 , & V_64 -> V_642 ) == 0 )
F_415 ( & V_64 -> V_640 , V_119 ) ;
if ( F_31 ( V_98 , & V_14 -> V_99 ) )
goto V_637;
V_639:
V_119 -> V_148 = 0 ;
return - V_129 ;
}
static void F_416 ( const struct V_63 * V_64 ,
T_12 * V_643 )
{
T_3 V_247 [ 2 ] ;
if ( F_31 ( V_644 , & V_64 -> V_642 ) ) {
V_247 [ 0 ] = 0 ;
V_247 [ 1 ] = F_417 ( V_645 + 1 ) ;
} else {
struct V_646 * V_647 = F_418 ( V_64 -> V_648 , V_649 ) ;
V_247 [ 0 ] = F_417 ( V_647 -> V_650 . V_651 ) ;
V_247 [ 1 ] = F_417 ( V_647 -> V_650 . V_652 ) ;
}
memcpy ( V_643 -> V_157 , V_247 , sizeof( V_643 -> V_157 ) ) ;
}
static unsigned int
F_419 ( struct V_63 * V_64 ,
char * V_603 , T_9 V_12 )
{
unsigned int V_653 ;
if ( V_64 -> V_654 != NULL )
return F_420 ( V_603 , V_64 -> V_654 , V_12 ) ;
F_134 () ;
V_653 = F_421 ( V_603 , V_12 , L_43 ,
V_64 -> V_655 ,
F_422 ( V_64 -> V_101 ,
V_656 ) ,
F_422 ( V_64 -> V_101 ,
V_657 ) ) ;
F_137 () ;
V_64 -> V_654 = F_423 ( V_603 , V_378 ) ;
return V_653 ;
}
static unsigned int
F_424 ( struct V_63 * V_64 ,
char * V_603 , T_9 V_12 )
{
const char * V_658 = V_64 -> V_101 -> V_659 ;
unsigned int V_653 ;
if ( V_64 -> V_654 != NULL )
return F_420 ( V_603 , V_64 -> V_654 , V_12 ) ;
if ( V_660 [ 0 ] != '\0' )
V_653 = F_421 ( V_603 , V_12 , L_44 ,
V_64 -> V_661 -> V_662 ,
V_64 -> V_429 ,
V_660 ,
V_658 ) ;
else
V_653 = F_421 ( V_603 , V_12 , L_45 ,
V_64 -> V_661 -> V_662 , V_64 -> V_429 ,
V_658 ) ;
V_64 -> V_654 = F_423 ( V_603 , V_378 ) ;
return V_653 ;
}
static unsigned int
F_425 ( const struct V_63 * V_64 , char * V_603 , T_9 V_12 )
{
if ( strchr ( V_64 -> V_655 , ':' ) != NULL )
return F_421 ( V_603 , V_12 , L_46 ) ;
else
return F_421 ( V_603 , V_12 , L_47 ) ;
}
static void F_426 ( struct V_118 * V_119 , void * V_155 )
{
struct V_663 * V_664 = V_155 ;
if ( V_119 -> V_148 == 0 )
V_664 -> V_665 = F_206 ( V_119 -> V_666 -> V_667 ) ;
}
int F_427 ( struct V_63 * V_64 , T_1 V_668 ,
unsigned short V_669 , struct V_315 * V_349 ,
struct V_670 * V_57 )
{
T_12 V_671 ;
struct V_663 V_672 = {
. V_671 = & V_671 ,
. V_673 = V_668 ,
. V_674 = V_64 -> V_675 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_676 ] ,
. V_313 = & V_672 ,
. V_314 = V_57 ,
. V_315 = V_349 ,
} ;
struct V_118 * V_119 ;
struct V_163 V_316 = {
. V_165 = V_64 -> V_101 ,
. V_161 = & V_162 ,
. V_166 = & V_677 ,
. V_169 = & V_672 ,
. V_214 = V_601 ,
} ;
int V_305 ;
F_416 ( V_64 , & V_671 ) ;
if ( F_31 ( V_678 , & V_64 -> V_679 ) )
V_672 . V_680 =
F_424 ( V_64 ,
V_672 . V_681 ,
sizeof( V_672 . V_681 ) ) ;
else
V_672 . V_680 =
F_419 ( V_64 ,
V_672 . V_681 ,
sizeof( V_672 . V_681 ) ) ;
V_672 . V_682 =
F_425 ( V_64 ,
V_672 . V_683 ,
sizeof( V_672 . V_683 ) ) ;
V_672 . V_684 = F_421 ( V_672 . V_685 ,
sizeof( V_672 . V_685 ) , L_48 ,
V_64 -> V_655 , V_669 >> 8 , V_669 & 255 ) ;
F_8 ( L_49 ,
V_64 -> V_101 -> V_102 -> V_686 -> V_687 ,
V_672 . V_680 , V_672 . V_681 ) ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) ) {
V_305 = F_71 ( V_119 ) ;
goto V_130;
}
V_305 = V_119 -> V_148 ;
if ( V_672 . V_665 ) {
V_64 -> V_688 = F_428 ( V_672 . V_665 ) ;
F_210 ( V_672 . V_665 ) ;
}
F_72 ( V_119 ) ;
V_130:
F_429 ( V_64 , V_305 ) ;
F_8 ( L_50 , V_305 ) ;
return V_305 ;
}
int F_430 ( struct V_63 * V_64 ,
struct V_670 * V_390 ,
struct V_315 * V_349 )
{
struct V_161 V_162 = {
. V_310 = & V_311 [ V_689 ] ,
. V_313 = V_390 ,
. V_315 = V_349 ,
} ;
int V_305 ;
F_8 ( L_51 ,
V_64 -> V_101 -> V_102 -> V_686 -> V_687 ,
V_64 -> V_235 ) ;
V_305 = F_384 ( V_64 -> V_101 , & V_162 , V_601 ) ;
F_431 ( V_64 , V_305 ) ;
F_8 ( L_52 , V_305 ) ;
return V_305 ;
}
static void F_432 ( struct V_118 * V_119 , void * V_155 )
{
struct V_690 * V_157 = V_155 ;
if ( ! F_60 ( V_119 , & V_157 -> V_57 . V_160 ) )
return;
F_433 ( & V_157 -> args , & V_157 -> V_57 , V_119 -> V_148 ) ;
switch ( V_119 -> V_148 ) {
case 0 :
F_37 ( V_157 -> V_57 . V_14 , V_157 -> V_106 ) ;
case - V_72 :
case - V_71 :
case - V_73 :
case - V_93 :
case - V_75 :
case - V_74 :
V_119 -> V_148 = 0 ;
if ( V_157 -> V_407 )
F_243 ( V_157 -> V_2 , V_157 -> V_409 ) ;
break;
default:
if ( F_244 ( V_119 , V_157 -> V_57 . V_14 ,
NULL , NULL ) == - V_129 ) {
F_57 ( V_119 ) ;
return;
}
}
V_157 -> V_293 = V_119 -> V_148 ;
}
static void F_434 ( void * V_155 )
{
struct V_690 * V_157 = V_155 ;
struct V_2 * V_2 = V_157 -> V_2 ;
if ( V_2 ) {
if ( V_157 -> V_407 )
F_240 ( V_2 ) ;
F_435 ( V_2 ) ;
}
F_97 ( V_155 ) ;
}
static void F_436 ( struct V_118 * V_119 , void * V_157 )
{
struct V_690 * V_691 ;
V_691 = (struct V_690 * ) V_157 ;
if ( V_691 -> V_407 &&
F_246 ( V_691 -> V_2 , & V_691 -> V_409 , V_119 ) )
return;
F_63 ( V_691 -> V_57 . V_14 ,
& V_691 -> args . V_159 ,
& V_691 -> V_57 . V_160 ,
V_119 ) ;
}
static int F_437 ( struct V_2 * V_2 , struct V_315 * V_349 , const T_8 * V_250 , int V_692 )
{
struct V_690 * V_157 ;
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_118 * V_119 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_693 ] ,
. V_315 = V_349 ,
} ;
struct V_163 V_316 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_694 ,
. V_214 = V_320 ,
} ;
int V_305 = 0 ;
V_157 = F_88 ( sizeof( * V_157 ) , V_302 ) ;
if ( V_157 == NULL )
return - V_125 ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
V_157 -> args . V_425 = & V_157 -> V_244 ;
V_157 -> args . V_250 = & V_157 -> V_250 ;
V_157 -> args . V_241 = V_14 -> V_421 ;
F_182 ( & V_157 -> V_244 , F_94 ( V_2 ) ) ;
F_126 ( & V_157 -> V_250 , V_250 ) ;
V_157 -> V_57 . V_387 = & V_157 -> V_387 ;
V_157 -> V_57 . V_14 = V_14 ;
F_83 ( V_157 -> V_57 . V_387 ) ;
V_157 -> V_106 = V_153 ;
V_157 -> V_293 = 0 ;
V_157 -> V_2 = F_438 ( V_2 ) ;
if ( V_157 -> V_2 )
V_157 -> V_407 = F_247 ( V_2 ) ;
V_316 . V_169 = V_157 ;
V_162 . V_313 = & V_157 -> args ;
V_162 . V_314 = & V_157 -> V_57 ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) )
return F_71 ( V_119 ) ;
if ( ! V_692 )
goto V_130;
V_305 = F_108 ( V_119 ) ;
if ( V_305 != 0 )
goto V_130;
V_305 = V_157 -> V_293 ;
if ( V_305 == 0 )
F_439 ( V_2 , & V_157 -> V_387 ) ;
else
F_148 ( V_2 , & V_157 -> V_387 ) ;
V_130:
F_72 ( V_119 ) ;
return V_305 ;
}
int F_440 ( struct V_2 * V_2 , struct V_315 * V_349 , const T_8 * V_250 , int V_692 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_437 ( V_2 , V_349 , V_250 , V_692 ) ;
F_441 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_75 :
case - V_74 :
case 0 :
return 0 ;
}
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static unsigned long
F_442 ( unsigned long V_51 )
{
F_18 ( V_51 ) ;
V_51 <<= 1 ;
if ( V_51 > V_695 )
return V_695 ;
return V_51 ;
}
static int F_443 ( struct V_65 * V_66 , int V_696 , struct V_697 * V_698 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_699 V_390 = {
. V_244 = F_94 ( V_2 ) ,
. V_700 = V_698 ,
} ;
struct V_701 V_57 = {
. V_702 = V_698 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_703 ] ,
. V_313 = & V_390 ,
. V_314 = & V_57 ,
. V_315 = V_66 -> V_225 -> V_289 ,
} ;
struct V_280 * V_281 ;
int V_305 ;
V_390 . V_704 . V_234 = V_64 -> V_235 ;
V_305 = F_444 ( V_66 , V_698 ) ;
if ( V_305 != 0 )
goto V_130;
V_281 = V_698 -> V_705 . V_706 . V_225 ;
V_390 . V_704 . V_236 = V_281 -> V_707 . V_239 ;
V_390 . V_704 . V_708 = V_14 -> V_708 ;
V_305 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_390 . V_159 , & V_57 . V_160 , 1 ) ;
switch ( V_305 ) {
case 0 :
V_698 -> V_709 = V_710 ;
break;
case - V_307 :
V_305 = 0 ;
}
V_698 -> V_711 -> V_712 ( V_698 ) ;
V_698 -> V_711 = NULL ;
V_130:
return V_305 ;
}
static int F_445 ( struct V_65 * V_66 , int V_696 , struct V_697 * V_698 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_443 ( V_66 , V_696 , V_698 ) ;
F_446 ( V_698 , V_66 , V_696 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_66 -> V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_447 ( struct V_713 * V_713 , struct V_697 * V_700 )
{
int V_57 = 0 ;
switch ( V_700 -> V_714 & ( V_715 | V_716 ) ) {
case V_715 :
V_57 = F_448 ( V_713 , V_700 ) ;
break;
case V_716 :
V_57 = F_449 ( V_713 , V_700 ) ;
break;
default:
F_450 () ;
}
return V_57 ;
}
static struct V_717 * F_451 ( struct V_697 * V_700 ,
struct V_299 * V_300 ,
struct V_280 * V_281 ,
struct V_218 * V_204 )
{
struct V_717 * V_41 ;
struct V_2 * V_2 = V_281 -> V_282 -> V_2 ;
V_41 = F_88 ( sizeof( * V_41 ) , V_302 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_390 . V_244 = F_94 ( V_2 ) ;
V_41 -> V_390 . V_700 = & V_41 -> V_700 ;
V_41 -> V_390 . V_204 = V_204 ;
V_41 -> V_57 . V_204 = V_204 ;
V_41 -> V_281 = V_281 ;
F_92 ( & V_281 -> V_718 ) ;
V_41 -> V_300 = F_156 ( V_300 ) ;
memcpy ( & V_41 -> V_700 , V_700 , sizeof( V_41 -> V_700 ) ) ;
V_41 -> V_14 = F_87 ( V_2 ) ;
return V_41 ;
}
static void F_452 ( void * V_157 )
{
struct V_717 * V_155 = V_157 ;
F_101 ( V_155 -> V_390 . V_204 ) ;
F_453 ( V_155 -> V_281 ) ;
F_168 ( V_155 -> V_300 ) ;
F_97 ( V_155 ) ;
}
static void F_454 ( struct V_118 * V_119 , void * V_157 )
{
struct V_717 * V_155 = V_157 ;
if ( ! F_60 ( V_119 , & V_155 -> V_57 . V_160 ) )
return;
switch ( V_119 -> V_148 ) {
case 0 :
F_37 ( V_155 -> V_14 , V_155 -> V_106 ) ;
F_447 ( V_155 -> V_700 . V_719 , & V_155 -> V_700 ) ;
if ( F_138 ( V_155 -> V_281 ,
& V_155 -> V_57 . V_250 ) )
break;
case - V_73 :
case - V_93 :
case - V_75 :
case - V_74 :
if ( ! F_136 ( & V_155 -> V_390 . V_250 ,
& V_155 -> V_281 -> V_284 ) )
F_57 ( V_119 ) ;
break;
default:
if ( F_244 ( V_119 , V_155 -> V_14 ,
NULL , NULL ) == - V_129 )
F_57 ( V_119 ) ;
}
F_141 ( V_155 -> V_390 . V_204 ) ;
}
static void F_455 ( struct V_118 * V_119 , void * V_157 )
{
struct V_717 * V_155 = V_157 ;
if ( F_181 ( V_155 -> V_390 . V_204 , V_119 ) != 0 )
goto V_321;
F_126 ( & V_155 -> V_390 . V_250 , & V_155 -> V_281 -> V_284 ) ;
if ( F_31 ( V_720 , & V_155 -> V_281 -> V_721 ) == 0 ) {
goto V_322;
}
V_155 -> V_106 = V_153 ;
if ( F_63 ( V_155 -> V_14 ,
& V_155 -> V_390 . V_159 ,
& V_155 -> V_57 . V_160 ,
V_119 ) != 0 )
F_141 ( V_155 -> V_390 . V_204 ) ;
return;
V_322:
V_119 -> V_333 = NULL ;
V_321:
F_60 ( V_119 , & V_155 -> V_57 . V_160 ) ;
}
static struct V_118 * F_456 ( struct V_697 * V_700 ,
struct V_299 * V_300 ,
struct V_280 * V_281 ,
struct V_218 * V_204 )
{
struct V_717 * V_157 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_722 ] ,
. V_315 = V_300 -> V_349 ,
} ;
struct V_163 V_316 = {
. V_165 = F_292 ( V_281 -> V_282 -> V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_723 ,
. V_318 = V_319 ,
. V_214 = V_320 ,
} ;
F_251 ( F_87 ( V_281 -> V_282 -> V_2 ) -> V_63 ,
V_419 , & V_316 . V_165 , & V_162 ) ;
V_700 -> V_709 = V_710 ;
V_157 = F_451 ( V_700 , V_300 , V_281 , V_204 ) ;
if ( V_157 == NULL ) {
F_101 ( V_204 ) ;
return F_44 ( - V_125 ) ;
}
F_38 ( & V_157 -> V_390 . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
V_162 . V_313 = & V_157 -> V_390 ;
V_162 . V_314 = & V_157 -> V_57 ;
V_316 . V_169 = V_157 ;
return F_70 ( & V_316 ) ;
}
static int F_457 ( struct V_65 * V_66 , int V_696 , struct V_697 * V_698 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_212 * V_213 = V_66 -> V_225 ;
struct V_172 * V_173 = F_75 ( V_2 ) ;
struct V_218 * V_204 ;
struct V_280 * V_281 ;
struct V_118 * V_119 ;
struct V_218 * ( * V_219 ) ( struct V_220 * , T_6 ) ;
int V_305 = 0 ;
unsigned char V_714 = V_698 -> V_714 ;
V_305 = F_444 ( V_66 , V_698 ) ;
V_698 -> V_714 |= V_724 ;
F_458 ( & V_213 -> V_725 ) ;
F_459 ( & V_173 -> V_726 ) ;
if ( F_447 ( V_698 -> V_719 , V_698 ) == - V_301 ) {
F_460 ( & V_173 -> V_726 ) ;
F_461 ( & V_213 -> V_725 ) ;
goto V_130;
}
F_460 ( & V_173 -> V_726 ) ;
F_461 ( & V_213 -> V_725 ) ;
if ( V_305 != 0 )
goto V_130;
V_281 = V_698 -> V_705 . V_706 . V_225 ;
if ( F_31 ( V_720 , & V_281 -> V_721 ) == 0 )
goto V_130;
V_219 = F_87 ( V_2 ) -> V_63 -> V_167 -> V_219 ;
V_204 = V_219 ( & V_281 -> V_707 , V_378 ) ;
V_305 = - V_125 ;
if ( F_43 ( V_204 ) )
goto V_130;
V_119 = F_456 ( V_698 , F_284 ( V_698 -> V_719 ) , V_281 , V_204 ) ;
V_305 = F_71 ( V_119 ) ;
if ( F_43 ( V_119 ) )
goto V_130;
V_305 = F_108 ( V_119 ) ;
F_72 ( V_119 ) ;
V_130:
V_698 -> V_714 = V_714 ;
F_462 ( V_698 , V_66 , V_727 , V_305 ) ;
return V_305 ;
}
static struct V_728 * F_463 ( struct V_697 * V_700 ,
struct V_299 * V_300 , struct V_280 * V_281 ,
T_6 V_216 )
{
struct V_728 * V_41 ;
struct V_2 * V_2 = V_281 -> V_282 -> V_2 ;
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_218 * ( * V_219 ) ( struct V_220 * , T_6 ) ;
V_41 = F_88 ( sizeof( * V_41 ) , V_216 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_390 . V_244 = F_94 ( V_2 ) ;
V_41 -> V_390 . V_700 = & V_41 -> V_700 ;
V_41 -> V_390 . V_729 = F_464 ( & V_281 -> V_282 -> V_225 -> V_222 , V_216 ) ;
if ( F_43 ( V_41 -> V_390 . V_729 ) )
goto V_309;
V_219 = V_14 -> V_63 -> V_167 -> V_219 ;
V_41 -> V_390 . V_730 = V_219 ( & V_281 -> V_707 , V_216 ) ;
if ( F_43 ( V_41 -> V_390 . V_730 ) )
goto V_731;
V_41 -> V_390 . V_704 . V_234 = V_14 -> V_63 -> V_235 ;
V_41 -> V_390 . V_704 . V_236 = V_281 -> V_707 . V_239 ;
V_41 -> V_390 . V_704 . V_708 = V_14 -> V_708 ;
V_41 -> V_57 . V_730 = V_41 -> V_390 . V_730 ;
V_41 -> V_281 = V_281 ;
V_41 -> V_14 = V_14 ;
F_92 ( & V_281 -> V_718 ) ;
V_41 -> V_300 = F_156 ( V_300 ) ;
memcpy ( & V_41 -> V_700 , V_700 , sizeof( V_41 -> V_700 ) ) ;
return V_41 ;
V_731:
F_101 ( V_41 -> V_390 . V_729 ) ;
V_309:
F_97 ( V_41 ) ;
return NULL ;
}
static void F_465 ( struct V_118 * V_119 , void * V_155 )
{
struct V_728 * V_157 = V_155 ;
struct V_65 * V_66 = V_157 -> V_281 -> V_282 ;
F_8 ( L_29 , V_34 ) ;
if ( F_181 ( V_157 -> V_390 . V_730 , V_119 ) != 0 )
goto V_321;
if ( ! F_31 ( V_720 , & V_157 -> V_281 -> V_721 ) ) {
if ( F_181 ( V_157 -> V_390 . V_729 , V_119 ) != 0 ) {
goto V_732;
}
F_126 ( & V_157 -> V_390 . V_270 ,
& V_66 -> V_270 ) ;
V_157 -> V_390 . V_733 = 1 ;
V_157 -> V_57 . V_729 = V_157 -> V_390 . V_729 ;
} else {
V_157 -> V_390 . V_733 = 0 ;
F_126 ( & V_157 -> V_390 . V_734 ,
& V_157 -> V_281 -> V_284 ) ;
}
if ( ! F_235 ( V_66 ) ) {
V_157 -> V_293 = - V_402 ;
V_119 -> V_333 = NULL ;
goto V_735;
}
V_157 -> V_106 = V_153 ;
if ( F_63 ( V_157 -> V_14 ,
& V_157 -> V_390 . V_159 ,
& V_157 -> V_57 . V_160 ,
V_119 ) == 0 )
return;
V_735:
F_141 ( V_157 -> V_390 . V_729 ) ;
V_732:
F_141 ( V_157 -> V_390 . V_730 ) ;
V_321:
F_60 ( V_119 , & V_157 -> V_57 . V_160 ) ;
F_8 ( L_53 , V_34 , V_157 -> V_293 ) ;
}
static void F_466 ( struct V_118 * V_119 , void * V_155 )
{
struct V_728 * V_157 = V_155 ;
struct V_280 * V_281 = V_157 -> V_281 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_60 ( V_119 , & V_157 -> V_57 . V_160 ) )
return;
V_157 -> V_293 = V_119 -> V_148 ;
switch ( V_119 -> V_148 ) {
case 0 :
F_37 ( F_87 ( V_157 -> V_300 -> V_4 -> V_46 ) ,
V_157 -> V_106 ) ;
if ( V_157 -> V_390 . V_736 ) {
V_157 -> V_700 . V_714 &= ~ ( V_737 | V_738 ) ;
if ( F_447 ( V_157 -> V_700 . V_719 , & V_157 -> V_700 ) < 0 ) {
F_57 ( V_119 ) ;
break;
}
}
if ( V_157 -> V_390 . V_733 != 0 ) {
F_175 ( & V_281 -> V_707 , 0 ) ;
F_126 ( & V_281 -> V_284 , & V_157 -> V_57 . V_250 ) ;
F_123 ( V_720 , & V_281 -> V_721 ) ;
} else if ( ! F_138 ( V_281 , & V_157 -> V_57 . V_250 ) )
F_57 ( V_119 ) ;
break;
case - V_73 :
case - V_93 :
case - V_75 :
case - V_74 :
if ( V_157 -> V_390 . V_733 != 0 ) {
if ( ! F_136 ( & V_157 -> V_390 . V_270 ,
& V_281 -> V_282 -> V_270 ) )
F_57 ( V_119 ) ;
} else if ( ! F_136 ( & V_157 -> V_390 . V_734 ,
& V_281 -> V_284 ) )
F_57 ( V_119 ) ;
}
F_8 ( L_30 , V_34 , V_157 -> V_293 ) ;
}
static void F_467 ( void * V_155 )
{
struct V_728 * V_157 = V_155 ;
F_8 ( L_29 , V_34 ) ;
F_101 ( V_157 -> V_390 . V_729 ) ;
if ( V_157 -> V_308 != 0 ) {
struct V_118 * V_119 ;
V_119 = F_456 ( & V_157 -> V_700 , V_157 -> V_300 , V_157 -> V_281 ,
V_157 -> V_390 . V_730 ) ;
if ( ! F_43 ( V_119 ) )
F_468 ( V_119 ) ;
F_8 ( L_54 , V_34 ) ;
} else
F_101 ( V_157 -> V_390 . V_730 ) ;
F_453 ( V_157 -> V_281 ) ;
F_168 ( V_157 -> V_300 ) ;
F_97 ( V_157 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_469 ( struct V_13 * V_14 , struct V_280 * V_281 , int V_733 , int error )
{
switch ( error ) {
case - V_72 :
case - V_73 :
V_281 -> V_707 . V_214 &= ~ V_739 ;
if ( V_733 != 0 ||
F_31 ( V_720 , & V_281 -> V_721 ) != 0 )
F_23 ( V_14 , V_281 -> V_282 ) ;
break;
case - V_75 :
V_281 -> V_707 . V_214 &= ~ V_739 ;
case - V_74 :
F_24 ( V_14 -> V_63 ) ;
} ;
}
static int F_470 ( struct V_65 * V_66 , int V_696 , struct V_697 * V_700 , int V_740 )
{
struct V_728 * V_157 ;
struct V_118 * V_119 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_741 ] ,
. V_315 = V_66 -> V_225 -> V_289 ,
} ;
struct V_163 V_316 = {
. V_165 = F_292 ( V_66 -> V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_742 ,
. V_318 = V_319 ,
. V_214 = V_320 ,
} ;
int V_52 ;
F_8 ( L_29 , V_34 ) ;
V_157 = F_463 ( V_700 , F_284 ( V_700 -> V_719 ) ,
V_700 -> V_705 . V_706 . V_225 ,
V_740 == V_743 ? V_378 : V_302 ) ;
if ( V_157 == NULL )
return - V_125 ;
if ( F_471 ( V_696 ) )
V_157 -> V_390 . V_744 = 1 ;
F_38 ( & V_157 -> V_390 . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
V_162 . V_313 = & V_157 -> V_390 ;
V_162 . V_314 = & V_157 -> V_57 ;
V_316 . V_169 = V_157 ;
if ( V_740 > V_743 ) {
if ( V_740 == V_745 )
V_157 -> V_390 . V_746 = V_745 ;
F_39 ( & V_157 -> V_390 . V_159 ) ;
} else
V_157 -> V_390 . V_736 = 1 ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) )
return F_71 ( V_119 ) ;
V_52 = F_108 ( V_119 ) ;
if ( V_52 == 0 ) {
V_52 = V_157 -> V_293 ;
if ( V_52 )
F_469 ( V_157 -> V_14 , V_157 -> V_281 ,
V_157 -> V_390 . V_733 , V_52 ) ;
} else
V_157 -> V_308 = 1 ;
F_72 ( V_119 ) ;
F_8 ( L_30 , V_34 , V_52 ) ;
return V_52 ;
}
static int F_472 ( struct V_65 * V_66 , struct V_697 * V_698 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
struct V_61 V_62 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_31 ( V_271 , & V_66 -> V_214 ) != 0 )
return 0 ;
V_8 = F_470 ( V_66 , V_727 , V_698 , V_745 ) ;
F_473 ( V_698 , V_66 , V_727 , V_8 ) ;
if ( V_8 != - V_90 )
break;
F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_474 ( struct V_65 * V_66 , struct V_697 * V_698 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
struct V_61 V_62 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
V_8 = F_444 ( V_66 , V_698 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_747 ) {
F_123 ( V_748 , & V_698 -> V_705 . V_706 . V_225 -> V_721 ) ;
return 0 ;
}
do {
if ( F_31 ( V_271 , & V_66 -> V_214 ) != 0 )
return 0 ;
V_8 = F_470 ( V_66 , V_727 , V_698 , V_749 ) ;
F_475 ( V_698 , V_66 , V_727 , V_8 ) ;
switch ( V_8 ) {
default:
goto V_130;
case - V_89 :
case - V_90 :
F_20 ( V_14 , V_8 , & V_62 ) ;
V_8 = 0 ;
}
} while ( V_62 . V_67 );
V_130:
return V_8 ;
}
static int F_476 ( struct V_65 * V_66 )
{
int V_305 , V_52 = - V_73 ;
struct V_280 * V_281 ;
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
F_155 (lsp, &state->lock_states, ls_locks) {
if ( F_31 ( V_720 , & V_281 -> V_721 ) ) {
struct V_315 * V_349 = V_281 -> V_282 -> V_225 -> V_289 ;
V_305 = F_207 ( V_14 ,
& V_281 -> V_284 ,
V_349 ) ;
F_477 ( V_66 , V_281 , V_305 ) ;
if ( V_305 != V_362 ) {
if ( V_305 != - V_73 )
F_209 ( V_14 ,
& V_281 -> V_284 ,
V_349 ) ;
F_125 ( V_720 , & V_281 -> V_721 ) ;
V_52 = V_305 ;
}
}
} ;
return V_52 ;
}
static int F_478 ( struct V_65 * V_66 , struct V_697 * V_698 )
{
int V_305 = V_362 ;
if ( F_31 ( V_750 , & V_66 -> V_214 ) )
V_305 = F_476 ( V_66 ) ;
if ( V_305 != V_362 )
V_305 = F_474 ( V_66 , V_698 ) ;
return V_305 ;
}
static int F_479 ( struct V_65 * V_66 , int V_696 , struct V_697 * V_698 )
{
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
unsigned char V_714 = V_698 -> V_714 ;
int V_305 = - V_751 ;
if ( ( V_714 & V_715 ) &&
! F_31 ( V_372 , & V_66 -> V_214 ) )
goto V_130;
V_305 = F_444 ( V_66 , V_698 ) ;
if ( V_305 != 0 )
goto V_130;
V_698 -> V_714 |= V_738 ;
V_305 = F_447 ( V_698 -> V_719 , V_698 ) ;
if ( V_305 < 0 )
goto V_130;
F_459 ( & V_173 -> V_726 ) ;
if ( F_31 ( V_271 , & V_66 -> V_214 ) ) {
V_698 -> V_714 = V_714 & ~ V_737 ;
V_305 = F_447 ( V_698 -> V_719 , V_698 ) ;
F_460 ( & V_173 -> V_726 ) ;
goto V_130;
}
F_460 ( & V_173 -> V_726 ) ;
V_305 = F_470 ( V_66 , V_696 , V_698 , V_743 ) ;
V_130:
V_698 -> V_714 = V_714 ;
return V_305 ;
}
static int F_480 ( struct V_65 * V_66 , int V_696 , struct V_697 * V_698 )
{
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_479 ( V_66 , V_696 , V_698 ) ;
F_481 ( V_698 , V_66 , V_696 , V_8 ) ;
if ( V_8 == - V_307 )
V_8 = - V_129 ;
V_8 = F_20 ( F_87 ( V_66 -> V_2 ) ,
V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int
F_482 ( struct V_713 * V_752 , int V_696 , struct V_697 * V_698 )
{
struct V_299 * V_300 ;
struct V_65 * V_66 ;
unsigned long V_51 = V_753 ;
int V_305 ;
V_300 = F_284 ( V_752 ) ;
V_66 = V_300 -> V_66 ;
if ( V_698 -> V_754 < 0 || V_698 -> V_755 < 0 )
return - V_27 ;
if ( F_483 ( V_696 ) ) {
if ( V_66 != NULL )
return F_445 ( V_66 , V_756 , V_698 ) ;
return 0 ;
}
if ( ! ( F_484 ( V_696 ) || F_471 ( V_696 ) ) )
return - V_27 ;
if ( V_698 -> V_709 == V_710 ) {
if ( V_66 != NULL )
return F_457 ( V_66 , V_696 , V_698 ) ;
return 0 ;
}
if ( V_66 == NULL )
return - V_751 ;
switch ( V_698 -> V_709 ) {
case V_757 :
if ( ! ( V_752 -> V_758 & V_69 ) )
return - V_402 ;
break;
case V_759 :
if ( ! ( V_752 -> V_758 & V_186 ) )
return - V_402 ;
}
do {
V_305 = F_480 ( V_66 , V_696 , V_698 ) ;
if ( ( V_305 != - V_129 ) || F_484 ( V_696 ) )
break;
V_51 = F_442 ( V_51 ) ;
V_305 = - V_59 ;
if ( F_485 () )
break;
} while( V_305 < 0 );
return V_305 ;
}
int F_486 ( struct V_697 * V_700 , struct V_65 * V_66 , const T_8 * V_250 )
{
struct V_13 * V_14 = F_87 ( V_66 -> V_2 ) ;
int V_8 ;
V_8 = F_444 ( V_66 , V_700 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_470 ( V_66 , V_727 , V_700 , V_743 ) ;
return F_169 ( V_14 , V_66 , V_250 , V_8 ) ;
}
static void F_487 ( struct V_118 * V_119 , void * V_155 )
{
struct V_760 * V_157 = V_155 ;
struct V_13 * V_14 = V_157 -> V_14 ;
F_40 ( V_14 -> V_63 -> V_154 ,
& V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , V_119 ) ;
V_157 -> args . V_704 . V_234 = V_14 -> V_63 -> V_235 ;
V_157 -> V_106 = V_153 ;
}
static void F_488 ( struct V_118 * V_119 , void * V_155 )
{
struct V_760 * V_157 = V_155 ;
struct V_13 * V_14 = V_157 -> V_14 ;
F_48 ( V_119 , & V_157 -> V_57 . V_160 ) ;
switch ( V_119 -> V_148 ) {
case 0 :
F_37 ( V_14 , V_157 -> V_106 ) ;
break;
case - V_76 :
case - V_74 :
F_24 ( V_14 -> V_63 ) ;
break;
case - V_78 :
case - V_90 :
if ( F_244 ( V_119 , V_14 ,
NULL , NULL ) == - V_129 )
F_57 ( V_119 ) ;
}
}
static void F_489 ( void * V_155 )
{
struct V_760 * V_157 = V_155 ;
F_490 ( V_157 -> V_14 , V_157 -> V_281 ) ;
F_97 ( V_155 ) ;
}
static void
F_491 ( struct V_13 * V_14 , struct V_280 * V_281 )
{
struct V_760 * V_157 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_761 ] ,
} ;
if ( V_14 -> V_63 -> V_167 -> V_331 != 0 )
return;
V_157 = F_274 ( sizeof( * V_157 ) , V_302 ) ;
if ( ! V_157 )
return;
V_157 -> V_281 = V_281 ;
V_157 -> V_14 = V_14 ;
V_157 -> args . V_704 . V_234 = V_14 -> V_63 -> V_235 ;
V_157 -> args . V_704 . V_236 = V_281 -> V_707 . V_239 ;
V_157 -> args . V_704 . V_708 = V_14 -> V_708 ;
V_162 . V_313 = & V_157 -> args ;
V_162 . V_314 = & V_157 -> V_57 ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 0 ) ;
F_382 ( V_14 -> V_91 , & V_162 , 0 , & V_762 , V_157 ) ;
}
static int F_492 ( struct V_4 * V_4 , const char * V_763 ,
const void * V_603 , T_9 V_604 ,
int V_214 , int type )
{
if ( strcmp ( V_763 , L_55 ) != 0 )
return - V_27 ;
return F_404 ( V_4 -> V_46 , V_603 , V_604 ) ;
}
static int F_493 ( struct V_4 * V_4 , const char * V_763 ,
void * V_603 , T_9 V_604 , int type )
{
if ( strcmp ( V_763 , L_55 ) != 0 )
return - V_27 ;
return F_398 ( V_4 -> V_46 , V_603 , V_604 ) ;
}
static T_9 F_494 ( struct V_4 * V_4 , char * V_764 ,
T_9 V_765 , const char * V_240 ,
T_9 V_766 , int type )
{
T_9 V_12 = sizeof( V_767 ) ;
if ( ! F_385 ( F_87 ( V_4 -> V_46 ) ) )
return 0 ;
if ( V_764 && V_12 <= V_765 )
memcpy ( V_764 , V_767 , V_12 ) ;
return V_12 ;
}
static inline int F_495 ( struct V_13 * V_14 )
{
return V_14 -> V_94 & V_9 ;
}
static int F_496 ( struct V_4 * V_4 , const char * V_763 ,
const void * V_603 , T_9 V_604 ,
int V_214 , int type )
{
if ( F_497 ( V_763 ) )
return F_412 ( V_4 , V_603 , V_604 ) ;
return - V_629 ;
}
static int F_498 ( struct V_4 * V_4 , const char * V_763 ,
void * V_603 , T_9 V_604 , int type )
{
if ( F_497 ( V_763 ) )
return F_407 ( V_4 -> V_46 , V_603 , V_604 ) ;
return - V_629 ;
}
static T_9 F_499 ( struct V_4 * V_4 , char * V_764 ,
T_9 V_765 , const char * V_240 ,
T_9 V_766 , int type )
{
T_9 V_12 = 0 ;
if ( F_2 ( V_4 -> V_46 , V_9 ) ) {
V_12 = F_500 ( V_4 -> V_46 , NULL , 0 ) ;
if ( V_764 && V_12 <= V_765 )
F_500 ( V_4 -> V_46 , V_764 , V_12 ) ;
}
return V_12 ;
}
static void F_276 ( struct V_386 * V_387 )
{
if ( ! ( ( ( V_387 -> V_296 & V_768 ) ||
( V_387 -> V_296 & V_769 ) ) &&
( V_387 -> V_296 & V_480 ) &&
( V_387 -> V_296 & V_770 ) ) )
return;
V_387 -> V_296 |= V_334 | V_496 |
V_497 | V_771 ;
V_387 -> V_255 = V_339 | V_499 | V_500 ;
V_387 -> V_501 = 2 ;
}
static int F_501 ( struct V_55 * V_91 , struct V_2 * V_3 ,
const struct V_482 * V_240 ,
struct V_484 * V_772 ,
struct V_483 * V_483 )
{
struct V_13 * V_14 = F_87 ( V_3 ) ;
T_1 V_241 [ 3 ] = {
[ 0 ] = V_773 | V_774 ,
} ;
struct V_775 args = {
. V_494 = F_94 ( V_3 ) ,
. V_240 = V_240 ,
. V_483 = V_483 ,
. V_241 = V_241 ,
} ;
struct V_776 V_57 = {
. V_772 = V_772 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_777 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
int V_305 ;
F_8 ( L_56 , V_34 ) ;
if ( F_87 ( V_3 ) -> V_15 [ 1 ] & V_778 )
V_241 [ 1 ] |= V_778 ;
else
V_241 [ 0 ] |= V_45 ;
F_83 ( & V_772 -> V_387 ) ;
V_772 -> V_14 = V_14 ;
V_772 -> V_779 = 0 ;
V_305 = F_73 ( V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
F_8 ( L_57 , V_34 , V_305 ) ;
return V_305 ;
}
int F_275 ( struct V_55 * V_91 , struct V_2 * V_3 ,
const struct V_482 * V_240 ,
struct V_484 * V_772 ,
struct V_483 * V_483 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_501 ( V_91 , V_3 , V_240 ,
V_772 , V_483 ) ;
F_502 ( V_3 , V_240 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_503 ( struct V_2 * V_2 ,
struct V_484 * V_485 ,
struct V_483 * V_483 , struct V_315 * V_349 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_55 * V_56 = V_14 -> V_91 ;
T_1 V_241 [ 2 ] = {
[ 0 ] = V_773 | V_774 ,
} ;
struct V_775 args = {
. V_234 = V_14 -> V_63 -> V_235 ,
. V_244 = F_94 ( V_2 ) ,
. V_483 = V_483 ,
. V_241 = V_241 ,
. V_780 = 1 ,
. V_781 = 1 ,
} ;
struct V_776 V_57 = {
. V_772 = V_485 ,
. V_780 = 1 ,
. V_781 = 1 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_777 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
unsigned long V_563 = V_153 ;
int V_305 ;
F_83 ( & V_485 -> V_387 ) ;
V_485 -> V_14 = V_14 ;
V_485 -> V_779 = 0 ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_305 = F_69 ( V_56 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
if ( V_305 )
return V_305 ;
F_37 ( V_14 , V_563 ) ;
return 0 ;
}
static int F_504 ( struct V_2 * V_2 ,
struct V_484 * V_485 ,
struct V_483 * V_483 , struct V_315 * V_349 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_55 * V_56 = V_14 -> V_91 ;
T_1 V_241 [ 2 ] = {
[ 0 ] = V_773 | V_774 ,
} ;
struct V_775 args = {
. V_244 = F_94 ( V_2 ) ,
. V_483 = V_483 ,
. V_241 = V_241 ,
. V_780 = 1 ,
} ;
struct V_776 V_57 = {
. V_772 = V_485 ,
. V_780 = 1 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_777 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
int V_305 ;
F_83 ( & V_485 -> V_387 ) ;
V_485 -> V_14 = V_14 ;
V_485 -> V_779 = 0 ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_305 = F_69 ( V_56 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
if ( V_305 == V_782 &&
V_57 . V_160 . V_144 & V_783 )
V_305 = - V_78 ;
return V_305 ;
}
int F_505 ( struct V_2 * V_2 ,
struct V_484 * V_485 ,
struct V_483 * V_483 , struct V_315 * V_349 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_784 * V_785 =
V_64 -> V_167 -> V_786 ;
struct V_61 V_62 = { } ;
int V_305 ;
F_8 ( L_58 , V_34 ,
( unsigned long long ) V_14 -> V_481 . V_787 ,
( unsigned long long ) V_14 -> V_481 . V_788 ,
V_64 -> V_97 ) ;
F_506 ( F_94 ( V_2 ) , V_34 ) ;
do {
V_305 = V_785 -> V_789 ( V_2 , V_485 , V_483 , V_349 ) ;
if ( V_305 != - V_90 )
break;
F_20 ( V_14 , V_305 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_305 ;
}
static int F_507 ( struct V_2 * V_2 , struct V_315 * V_349 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_63 * V_64 = F_87 ( V_2 ) -> V_63 ;
struct V_55 * V_56 = V_14 -> V_91 ;
struct V_790 args = {
. V_244 = F_94 ( V_2 ) ,
. V_234 = V_64 -> V_235 ,
. V_781 = 1 ,
} ;
struct V_791 V_57 = {
. V_781 = 1 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_792 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
unsigned long V_563 = V_153 ;
int V_305 ;
V_57 . V_244 = F_508 () ;
if ( V_57 . V_244 == NULL )
return - V_125 ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_305 = F_69 ( V_56 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
F_509 ( V_57 . V_244 ) ;
if ( V_305 )
return V_305 ;
F_33 ( V_64 , V_563 ) ;
return 0 ;
}
static int F_510 ( struct V_2 * V_2 , struct V_315 * V_349 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_55 * V_56 = V_14 -> V_91 ;
struct V_790 args = {
. V_244 = F_94 ( V_2 ) ,
} ;
struct V_791 V_57 = {
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_792 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
int V_305 ;
V_57 . V_244 = F_508 () ;
if ( V_57 . V_244 == NULL )
return - V_125 ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_305 = F_69 ( V_56 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
F_509 ( V_57 . V_244 ) ;
if ( V_305 == V_782 &&
V_57 . V_160 . V_144 & V_783 )
V_305 = - V_78 ;
return V_305 ;
}
int F_511 ( struct V_2 * V_2 , struct V_315 * V_349 )
{
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_784 * V_785 =
V_64 -> V_167 -> V_786 ;
struct V_61 V_62 = { } ;
int V_305 ;
F_8 ( L_58 , V_34 ,
( unsigned long long ) V_14 -> V_481 . V_787 ,
( unsigned long long ) V_14 -> V_481 . V_788 ,
V_64 -> V_97 ) ;
F_506 ( F_94 ( V_2 ) , V_34 ) ;
do {
V_305 = V_785 -> V_793 ( V_2 , V_349 ) ;
if ( V_305 != - V_90 )
break;
F_20 ( V_14 , V_305 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_305 ;
}
static int F_512 ( struct V_2 * V_3 , const struct V_482 * V_240 , struct V_794 * V_475 , bool V_795 )
{
int V_305 ;
struct V_796 args = {
. V_494 = F_94 ( V_3 ) ,
. V_240 = V_240 ,
} ;
struct V_797 V_57 = {
. V_475 = V_475 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_798 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
struct V_55 * V_56 = F_87 ( V_3 ) -> V_91 ;
struct V_315 * V_349 = NULL ;
if ( V_795 ) {
V_56 = F_87 ( V_3 ) -> V_63 -> V_101 ;
V_349 = F_513 ( F_87 ( V_3 ) -> V_63 ) ;
V_162 . V_315 = V_349 ;
}
F_8 ( L_59 , V_240 -> V_240 ) ;
F_251 ( F_87 ( V_3 ) -> V_63 ,
V_799 , & V_56 , & V_162 ) ;
V_305 = F_73 ( V_56 , F_87 ( V_3 ) , & V_162 , & args . V_159 ,
& V_57 . V_160 , 0 ) ;
F_8 ( L_60 , V_305 ) ;
if ( V_349 )
F_210 ( V_349 ) ;
return V_305 ;
}
int F_514 ( struct V_2 * V_3 , const struct V_482 * V_240 ,
struct V_794 * V_475 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( F_87 ( V_3 ) -> V_63 ) )
V_8 = F_512 ( V_3 , V_240 , V_475 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_512 ( V_3 , V_240 , V_475 , false ) ;
F_515 ( V_3 , V_240 , V_8 ) ;
V_8 = F_20 ( F_87 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_516 ( T_1 V_214 )
{
if ( V_214 & ~ V_800 )
goto V_801;
if ( ( V_214 & V_802 ) &&
( V_214 & V_803 ) )
goto V_801;
if ( ! ( V_214 & ( V_804 ) ) )
goto V_801;
return V_362 ;
V_801:
return - V_805 ;
}
static bool
F_517 ( struct V_806 * V_807 ,
struct V_806 * V_808 )
{
if ( V_807 -> V_809 == V_808 -> V_809 &&
memcmp ( V_807 -> V_810 , V_808 -> V_810 , V_807 -> V_809 ) == 0 )
return true ;
return false ;
}
int F_518 ( struct V_63 * V_64 , struct V_315 * V_349 )
{
int V_305 ;
struct V_811 args = {
. V_91 = V_64 ,
. V_3 = V_812 ,
} ;
struct V_813 V_57 ;
struct V_161 V_162 = {
. V_310 =
& V_311 [ V_814 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
F_8 ( L_11 , V_34 ) ;
F_519 ( & args . V_815 , & V_64 -> V_87 -> V_816 ) ;
if ( ! ( V_64 -> V_87 -> V_214 & V_817 ) )
args . V_3 = V_818 ;
V_305 = F_384 ( V_64 -> V_101 , & V_162 , V_601 ) ;
F_520 ( V_64 , V_305 ) ;
if ( V_305 == 0 ) {
if ( memcmp ( V_57 . V_815 . V_157 ,
V_64 -> V_87 -> V_816 . V_157 , V_819 ) ) {
F_8 ( L_61 , V_34 ) ;
V_305 = - V_35 ;
goto V_130;
}
if ( ( V_57 . V_3 & args . V_3 ) != V_57 . V_3 || V_57 . V_3 == 0 ) {
F_8 ( L_62 ,
V_34 ) ;
V_305 = - V_35 ;
goto V_130;
}
if ( V_57 . V_820 != args . V_820 ) {
F_8 ( L_63 ,
V_34 ) ;
V_305 = - V_35 ;
goto V_130;
}
}
V_130:
F_8 ( L_64 , V_34 , V_305 ) ;
return V_305 ;
}
static int F_521 ( struct V_63 * V_64 ,
struct V_821 * V_213 )
{
static const T_1 V_822 [ V_823 ] = {
[ 1 ] = 1 << ( V_824 - 32 ) |
1 << ( V_825 - 32 ) |
1 << ( V_826 - 32 ) |
1 << ( V_827 - 32 ) |
1 << ( V_828 - 32 )
} ;
unsigned int V_472 ;
if ( V_213 -> V_829 == V_830 ) {
F_522 ( V_831 , L_65 ) ;
for ( V_472 = 0 ; V_472 <= V_832 ; V_472 ++ ) {
if ( F_31 ( V_472 , V_213 -> V_833 . V_248 . V_834 ) )
F_522 ( V_831 , L_66 , V_472 ) ;
if ( F_31 ( V_472 , V_213 -> V_835 . V_248 . V_834 ) )
F_522 ( V_831 , L_67 , V_472 ) ;
}
for ( V_472 = 0 ; V_472 < V_823 ; V_472 ++ ) {
if ( V_213 -> V_833 . V_248 . V_836 [ V_472 ] & ~ V_822 [ V_472 ] ) {
F_522 ( V_831 , L_68 ) ;
return - V_27 ;
}
}
if ( F_31 ( V_824 , V_213 -> V_833 . V_248 . V_834 ) &&
F_31 ( V_826 , V_213 -> V_833 . V_248 . V_834 ) &&
F_31 ( V_827 , V_213 -> V_833 . V_248 . V_834 ) &&
F_31 ( V_828 , V_213 -> V_833 . V_248 . V_834 ) ) {
F_522 ( V_831 , L_69 ) ;
F_522 ( V_831 , L_70 ) ;
F_123 ( V_837 , & V_64 -> V_838 ) ;
} else {
F_522 ( V_831 , L_68 ) ;
return - V_27 ;
}
if ( F_31 ( V_839 , V_213 -> V_835 . V_248 . V_834 ) &&
F_31 ( V_840 , V_213 -> V_835 . V_248 . V_834 ) ) {
F_522 ( V_831 , L_71 ) ;
F_123 ( V_419 , & V_64 -> V_838 ) ;
}
if ( F_31 ( V_841 , V_213 -> V_835 . V_248 . V_834 ) &&
F_31 ( V_842 , V_213 -> V_835 . V_248 . V_834 ) ) {
F_522 ( V_831 , L_72 ) ;
F_123 ( V_799 , & V_64 -> V_838 ) ;
}
if ( F_31 ( V_843 , V_213 -> V_835 . V_248 . V_834 ) &&
F_31 ( V_844 , V_213 -> V_835 . V_248 . V_834 ) ) {
F_522 ( V_831 , L_73 ) ;
F_123 ( V_845 , & V_64 -> V_838 ) ;
}
if ( F_31 ( V_846 , V_213 -> V_835 . V_248 . V_834 ) ) {
F_522 ( V_831 , L_74 ) ;
F_123 ( V_847 , & V_64 -> V_838 ) ;
}
if ( F_31 ( V_848 , V_213 -> V_835 . V_248 . V_834 ) ) {
F_522 ( V_831 , L_75 ) ;
F_123 ( V_849 , & V_64 -> V_838 ) ;
}
}
return 0 ;
}
static int F_523 ( struct V_63 * V_64 , struct V_315 * V_349 ,
T_1 V_850 )
{
T_12 V_37 ;
struct V_851 args = {
. V_37 = & V_37 ,
. V_91 = V_64 ,
#ifdef F_524
. V_214 = V_852 |
V_853 |
V_854 ,
#else
. V_214 = V_852 |
V_853 ,
#endif
} ;
struct V_855 V_57 = {
0
} ;
int V_305 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_856 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
F_416 ( V_64 , & V_37 ) ;
args . V_857 = F_424 ( V_64 , args . V_236 ,
sizeof( args . V_236 ) ) ;
F_8 ( L_76 ,
V_64 -> V_101 -> V_102 -> V_686 -> V_687 ,
args . V_857 , args . V_236 ) ;
V_57 . V_858 = F_88 ( sizeof( struct V_859 ) ,
V_302 ) ;
if ( F_360 ( V_57 . V_858 == NULL ) ) {
V_305 = - V_125 ;
goto V_130;
}
V_57 . V_810 = F_88 ( sizeof( struct V_806 ) ,
V_302 ) ;
if ( F_360 ( V_57 . V_810 == NULL ) ) {
V_305 = - V_125 ;
goto V_860;
}
V_57 . V_861 = F_88 ( sizeof( struct V_862 ) , V_302 ) ;
if ( F_360 ( V_57 . V_861 == NULL ) ) {
V_305 = - V_125 ;
goto V_863;
}
switch ( V_850 ) {
case V_864 :
args . V_865 . V_829 = V_864 ;
break;
case V_830 :
args . V_865 = V_866 ;
break;
default:
F_525 ( 1 ) ;
V_305 = - V_27 ;
goto V_863;
}
V_305 = F_384 ( V_64 -> V_101 , & V_162 , V_601 ) ;
F_526 ( V_64 , V_305 ) ;
if ( V_305 == 0 )
V_305 = F_516 ( V_57 . V_214 ) ;
if ( V_305 == 0 )
V_305 = F_521 ( V_64 , & V_57 . V_865 ) ;
if ( V_305 == 0 ) {
V_64 -> V_235 = V_57 . V_234 ;
V_64 -> V_867 = V_57 . V_214 ;
if ( ! ( V_57 . V_214 & V_868 ) ) {
F_125 ( V_869 ,
& V_64 -> V_87 -> V_870 ) ;
V_64 -> V_871 = V_57 . V_204 ;
}
F_97 ( V_64 -> V_872 ) ;
V_64 -> V_872 = V_57 . V_858 ;
V_57 . V_858 = NULL ;
F_97 ( V_64 -> V_873 ) ;
V_64 -> V_873 = V_57 . V_861 ;
if ( V_64 -> V_874 != NULL &&
! F_517 ( V_64 -> V_874 ,
V_57 . V_810 ) ) {
F_8 ( L_77 ,
V_34 ) ;
F_123 ( V_875 , & V_64 -> V_642 ) ;
F_97 ( V_64 -> V_874 ) ;
V_64 -> V_874 = NULL ;
}
if ( V_64 -> V_874 == NULL ) {
V_64 -> V_874 = V_57 . V_810 ;
goto V_130;
}
} else
F_97 ( V_57 . V_861 ) ;
V_860:
F_97 ( V_57 . V_858 ) ;
V_863:
F_97 ( V_57 . V_810 ) ;
V_130:
if ( V_64 -> V_873 != NULL )
F_8 ( L_78
L_79 ,
V_64 -> V_873 -> V_876 , V_64 -> V_873 -> V_240 ,
V_64 -> V_873 -> V_877 . V_878 ,
V_64 -> V_873 -> V_877 . V_879 ) ;
F_8 ( L_80 , V_305 ) ;
return V_305 ;
}
int F_527 ( struct V_63 * V_64 , struct V_315 * V_349 )
{
T_4 V_880 = V_64 -> V_101 -> V_102 -> V_103 ;
int V_305 ;
if ( V_880 == V_104 ||
V_880 == V_105 ) {
V_305 = F_523 ( V_64 , V_349 , V_830 ) ;
if ( ! V_305 )
return 0 ;
}
return F_523 ( V_64 , V_349 , V_864 ) ;
}
static int F_528 ( struct V_63 * V_64 ,
struct V_315 * V_349 )
{
struct V_161 V_162 = {
. V_310 = & V_311 [ V_881 ] ,
. V_313 = V_64 ,
. V_315 = V_349 ,
} ;
int V_305 ;
V_305 = F_384 ( V_64 -> V_101 , & V_162 , V_601 ) ;
F_529 ( V_64 , V_305 ) ;
if ( V_305 )
F_8 ( L_81
L_82 , V_305 , V_64 -> V_97 ) ;
return V_305 ;
}
static int F_530 ( struct V_63 * V_64 ,
struct V_315 * V_349 )
{
unsigned int V_882 ;
int V_52 ;
for ( V_882 = V_883 ; V_882 != 0 ; V_882 -- ) {
V_52 = F_528 ( V_64 , V_349 ) ;
switch ( V_52 ) {
case - V_90 :
case - V_884 :
F_171 ( 1 ) ;
break;
default:
return V_52 ;
}
}
return 0 ;
}
int F_531 ( struct V_63 * V_64 )
{
struct V_315 * V_349 ;
int V_52 = 0 ;
if ( V_64 -> V_167 -> V_331 < 1 )
goto V_130;
if ( V_64 -> V_867 == 0 )
goto V_130;
if ( V_64 -> V_885 )
goto V_130;
V_349 = F_513 ( V_64 ) ;
V_52 = F_530 ( V_64 , V_349 ) ;
if ( V_349 )
F_210 ( V_349 ) ;
switch ( V_52 ) {
case 0 :
case - V_76 :
V_64 -> V_867 = 0 ;
}
V_130:
return V_52 ;
}
static void F_532 ( struct V_118 * V_119 ,
void * V_155 )
{
struct V_886 * V_157 =
(struct V_886 * ) V_155 ;
F_8 ( L_11 , V_34 ) ;
F_61 ( V_157 -> V_64 -> V_87 ,
& V_157 -> args -> V_887 ,
& V_157 -> V_57 -> V_888 ,
V_119 ) ;
F_8 ( L_83 , V_34 ) ;
}
static void F_533 ( struct V_118 * V_119 , void * V_155 )
{
struct V_886 * V_157 =
(struct V_886 * ) V_155 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_53 ( V_119 , & V_157 -> V_57 -> V_888 ) )
return;
switch ( V_119 -> V_148 ) {
case - V_90 :
case - V_89 :
F_8 ( L_84 , V_34 , V_119 -> V_148 ) ;
F_59 ( V_119 , V_54 ) ;
V_119 -> V_148 = 0 ;
case - V_92 :
F_57 ( V_119 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
int F_534 ( struct V_63 * V_64 , struct V_458 * V_559 )
{
struct V_118 * V_119 ;
struct V_889 args ;
struct V_890 V_57 = {
. V_891 = V_559 ,
} ;
struct V_886 V_157 = {
. args = & args ,
. V_57 = & V_57 ,
. V_64 = V_64 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_892 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
struct V_163 V_164 = {
. V_165 = V_64 -> V_101 ,
. V_161 = & V_162 ,
. V_166 = & V_893 ,
. V_169 = & V_157 ,
. V_214 = V_601 ,
} ;
int V_305 ;
F_38 ( & args . V_887 , & V_57 . V_888 , 0 ) ;
F_39 ( & args . V_887 ) ;
F_8 ( L_11 , V_34 ) ;
V_119 = F_70 ( & V_164 ) ;
if ( F_43 ( V_119 ) )
V_305 = F_71 ( V_119 ) ;
else {
V_305 = V_119 -> V_148 ;
F_72 ( V_119 ) ;
}
F_8 ( L_85 , V_34 , V_305 ) ;
return V_305 ;
}
static void F_535 ( struct V_894 * args )
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
args -> V_905 . V_895 = V_608 ;
args -> V_905 . V_896 = V_608 ;
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
static int F_536 ( struct V_894 * args ,
struct V_908 * V_57 )
{
struct V_909 * V_910 = & args -> V_900 ;
struct V_909 * V_911 = & V_57 -> V_900 ;
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
static int F_537 ( struct V_894 * args ,
struct V_908 * V_57 )
{
struct V_909 * V_910 = & args -> V_905 ;
struct V_909 * V_911 = & V_57 -> V_905 ;
if ( ! ( V_57 -> V_214 & V_817 ) )
goto V_130;
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
V_130:
return 0 ;
}
static int F_538 ( struct V_894 * args ,
struct V_908 * V_57 )
{
int V_52 ;
V_52 = F_536 ( args , V_57 ) ;
if ( V_52 )
return V_52 ;
return F_537 ( args , V_57 ) ;
}
static void F_539 ( struct V_132 * V_133 ,
struct V_908 * V_57 )
{
F_519 ( & V_133 -> V_816 , & V_57 -> V_815 ) ;
V_133 -> V_64 -> V_867 |= V_868 ;
F_123 ( V_869 , & V_133 -> V_870 ) ;
V_133 -> V_214 = V_57 -> V_214 ;
memcpy ( & V_133 -> V_900 , & V_57 -> V_900 , sizeof( V_133 -> V_900 ) ) ;
if ( V_57 -> V_214 & V_817 )
memcpy ( & V_133 -> V_905 , & V_57 -> V_905 ,
sizeof( V_133 -> V_905 ) ) ;
}
static int F_540 ( struct V_63 * V_64 ,
struct V_315 * V_349 )
{
struct V_132 * V_133 = V_64 -> V_87 ;
struct V_894 args = {
. V_91 = V_64 ,
. V_234 = V_64 -> V_235 ,
. V_204 = V_64 -> V_871 ,
. V_913 = V_914 ,
} ;
struct V_908 V_57 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_915 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
int V_305 ;
F_535 ( & args ) ;
args . V_214 = ( V_916 | V_817 ) ;
V_305 = F_384 ( V_133 -> V_64 -> V_101 , & V_162 , V_601 ) ;
F_541 ( V_64 , V_305 ) ;
if ( ! V_305 ) {
V_305 = F_538 ( & args , & V_57 ) ;
if ( V_64 -> V_871 == V_57 . V_204 )
V_64 -> V_871 ++ ;
if ( V_305 )
goto V_130;
F_539 ( V_133 , & V_57 ) ;
}
V_130:
return V_305 ;
}
int F_542 ( struct V_63 * V_64 , struct V_315 * V_349 )
{
int V_305 ;
unsigned * V_917 ;
struct V_132 * V_133 = V_64 -> V_87 ;
F_8 ( L_90 , V_34 , V_64 , V_133 ) ;
V_305 = F_540 ( V_64 , V_349 ) ;
if ( V_305 )
goto V_130;
V_305 = F_543 ( V_133 ) ;
F_8 ( L_91 , V_305 ) ;
if ( V_305 )
goto V_130;
V_917 = ( unsigned * ) & V_133 -> V_816 . V_157 [ 0 ] ;
F_8 ( L_92 , V_34 ,
V_64 -> V_871 , V_917 [ 0 ] , V_917 [ 1 ] , V_917 [ 2 ] , V_917 [ 3 ] ) ;
V_130:
F_8 ( L_83 , V_34 ) ;
return V_305 ;
}
int F_544 ( struct V_132 * V_133 ,
struct V_315 * V_349 )
{
struct V_161 V_162 = {
. V_310 = & V_311 [ V_918 ] ,
. V_313 = V_133 ,
. V_315 = V_349 ,
} ;
int V_305 = 0 ;
F_8 ( L_93 ) ;
if ( ! F_116 ( V_869 , & V_133 -> V_870 ) )
return 0 ;
V_305 = F_384 ( V_133 -> V_64 -> V_101 , & V_162 , V_601 ) ;
F_545 ( V_133 -> V_64 , V_305 ) ;
if ( V_305 )
F_8 ( L_94
L_95 , V_305 ) ;
F_8 ( L_96 ) ;
return V_305 ;
}
static void F_546 ( void * V_157 )
{
struct V_919 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
if ( F_374 ( & V_64 -> V_595 ) > 1 )
F_375 ( V_64 ) ;
F_376 ( V_64 ) ;
F_97 ( V_155 ) ;
}
static int F_547 ( struct V_118 * V_119 , struct V_63 * V_64 )
{
switch( V_119 -> V_148 ) {
case - V_90 :
F_59 ( V_119 , V_53 ) ;
return - V_129 ;
default:
F_24 ( V_64 ) ;
}
return 0 ;
}
static void F_548 ( struct V_118 * V_119 , void * V_157 )
{
struct V_919 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
if ( ! F_53 ( V_119 , V_119 -> V_325 . V_314 ) )
return;
F_549 ( V_64 , V_119 -> V_148 ) ;
if ( V_119 -> V_148 < 0 ) {
F_8 ( L_97 , V_34 , V_119 -> V_148 ) ;
if ( F_374 ( & V_64 -> V_595 ) == 1 )
goto V_130;
if ( F_547 ( V_119 , V_64 ) == - V_129 ) {
F_57 ( V_119 ) ;
return;
}
}
F_8 ( L_98 , V_34 , V_119 -> V_325 . V_315 ) ;
V_130:
F_8 ( L_83 , V_34 ) ;
}
static void F_550 ( struct V_118 * V_119 , void * V_157 )
{
struct V_919 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
struct V_109 * args ;
struct V_110 * V_57 ;
args = V_119 -> V_325 . V_313 ;
V_57 = V_119 -> V_325 . V_314 ;
F_61 ( V_64 -> V_87 , args , V_57 , V_119 ) ;
}
static struct V_118 * F_551 ( struct V_63 * V_64 ,
struct V_315 * V_349 ,
bool V_920 )
{
struct V_919 * V_155 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_921 ] ,
. V_315 = V_349 ,
} ;
struct V_163 V_316 = {
. V_165 = V_64 -> V_101 ,
. V_161 = & V_162 ,
. V_166 = & V_922 ,
. V_214 = V_320 | V_601 ,
} ;
if ( ! F_381 ( & V_64 -> V_595 ) )
return F_44 ( - V_35 ) ;
V_155 = F_88 ( sizeof( * V_155 ) , V_302 ) ;
if ( V_155 == NULL ) {
F_376 ( V_64 ) ;
return F_44 ( - V_125 ) ;
}
F_38 ( & V_155 -> args , & V_155 -> V_57 , 0 ) ;
if ( V_920 )
F_39 ( & V_155 -> args ) ;
V_162 . V_313 = & V_155 -> args ;
V_162 . V_314 = & V_155 -> V_57 ;
V_155 -> V_64 = V_64 ;
V_316 . V_169 = V_155 ;
return F_70 ( & V_316 ) ;
}
static int F_552 ( struct V_63 * V_64 , struct V_315 * V_349 , unsigned V_599 )
{
struct V_118 * V_119 ;
int V_52 = 0 ;
if ( ( V_599 & V_923 ) == 0 )
return - V_129 ;
V_119 = F_551 ( V_64 , V_349 , false ) ;
if ( F_43 ( V_119 ) )
V_52 = F_71 ( V_119 ) ;
else
F_468 ( V_119 ) ;
F_8 ( L_16 , V_34 , V_52 ) ;
return V_52 ;
}
static int F_553 ( struct V_63 * V_64 , struct V_315 * V_349 )
{
struct V_118 * V_119 ;
int V_52 ;
V_119 = F_551 ( V_64 , V_349 , true ) ;
if ( F_43 ( V_119 ) ) {
V_52 = F_71 ( V_119 ) ;
goto V_130;
}
V_52 = F_109 ( V_119 ) ;
if ( ! V_52 ) {
struct V_110 * V_57 = V_119 -> V_325 . V_314 ;
if ( V_119 -> V_148 == 0 )
F_554 ( V_64 , V_57 -> V_144 ) ;
V_52 = V_119 -> V_148 ;
}
F_72 ( V_119 ) ;
V_130:
F_8 ( L_16 , V_34 , V_52 ) ;
return V_52 ;
}
static void F_555 ( struct V_118 * V_119 , void * V_157 )
{
struct V_924 * V_155 = V_157 ;
F_61 ( V_155 -> V_64 -> V_87 ,
& V_155 -> V_390 . V_159 ,
& V_155 -> V_57 . V_160 ,
V_119 ) ;
}
static int F_556 ( struct V_118 * V_119 , struct V_63 * V_64 )
{
switch( V_119 -> V_148 ) {
case 0 :
case - V_925 :
case - V_23 :
break;
case - V_90 :
F_59 ( V_119 , V_53 ) ;
case - V_92 :
return - V_129 ;
default:
F_24 ( V_64 ) ;
}
return 0 ;
}
static void F_557 ( struct V_118 * V_119 , void * V_157 )
{
struct V_924 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
struct V_110 * V_57 = & V_155 -> V_57 . V_160 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_53 ( V_119 , V_57 ) )
return;
F_558 ( V_64 , V_119 -> V_148 ) ;
if ( F_556 ( V_119 , V_64 ) == - V_129 ) {
F_57 ( V_119 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_559 ( void * V_157 )
{
struct V_924 * V_155 = V_157 ;
F_97 ( V_155 ) ;
}
static int F_560 ( struct V_63 * V_64 ,
struct V_315 * V_349 )
{
struct V_924 * V_155 ;
struct V_118 * V_119 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_926 ] ,
. V_315 = V_349 ,
} ;
struct V_163 V_316 = {
. V_165 = V_64 -> V_101 ,
. V_161 = & V_162 ,
. V_166 = & V_927 ,
. V_214 = V_320 ,
} ;
int V_305 = - V_125 ;
F_8 ( L_11 , V_34 ) ;
V_155 = F_88 ( sizeof( * V_155 ) , V_302 ) ;
if ( V_155 == NULL )
goto V_130;
V_155 -> V_64 = V_64 ;
V_155 -> V_390 . V_928 = 0 ;
F_38 ( & V_155 -> V_390 . V_159 , & V_155 -> V_57 . V_160 , 0 ) ;
F_39 ( & V_155 -> V_390 . V_159 ) ;
V_162 . V_313 = & V_155 -> V_390 ;
V_162 . V_314 = & V_155 -> V_57 ;
V_316 . V_169 = V_155 ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) ) {
V_305 = F_71 ( V_119 ) ;
goto V_130;
}
V_305 = F_108 ( V_119 ) ;
if ( V_305 == 0 )
V_305 = V_119 -> V_148 ;
F_72 ( V_119 ) ;
return 0 ;
V_130:
F_8 ( L_16 , V_34 , V_305 ) ;
return V_305 ;
}
static void
F_561 ( struct V_118 * V_119 , void * V_155 )
{
struct V_929 * V_930 = V_155 ;
struct V_13 * V_14 = F_87 ( V_930 -> args . V_2 ) ;
struct V_132 * V_133 = F_64 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
if ( F_61 ( V_133 , & V_930 -> args . V_159 ,
& V_930 -> V_57 . V_160 , V_119 ) )
return;
if ( F_562 ( & V_930 -> args . V_250 ,
F_75 ( V_930 -> args . V_2 ) -> V_931 ,
& V_930 -> args . V_932 ,
V_930 -> args . V_300 -> V_66 ) ) {
F_563 ( V_119 , V_782 ) ;
}
}
static void F_564 ( struct V_118 * V_119 , void * V_155 )
{
struct V_929 * V_930 = V_155 ;
struct V_2 * V_2 = V_930 -> args . V_2 ;
struct V_13 * V_14 = F_87 ( V_2 ) ;
struct V_933 * V_934 ;
struct V_65 * V_66 = NULL ;
unsigned long V_935 , V_563 , V_936 ;
F_8 ( L_99 , V_34 , - V_119 -> V_148 ) ;
if ( ! F_53 ( V_119 , & V_930 -> V_57 . V_160 ) )
goto V_130;
switch ( V_119 -> V_148 ) {
case 0 :
goto V_130;
case - V_19 :
case - V_20 :
V_935 = F_565 ( V_119 -> V_937 ) ;
V_936 = V_930 -> args . V_106 + V_935 ;
V_563 = V_153 ;
if ( F_566 ( V_936 , V_563 ) ) {
unsigned long V_938 ;
V_938 = F_567 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_100 ,
V_34 , V_938 ) ;
F_59 ( V_119 , V_938 ) ;
V_119 -> V_148 = 0 ;
F_57 ( V_119 ) ;
goto V_130;
}
break;
case - V_74 :
case - V_73 :
F_34 ( & V_2 -> V_174 ) ;
V_934 = F_75 ( V_2 ) -> V_931 ;
if ( ! V_934 || F_568 ( & V_934 -> V_939 ) ) {
F_36 ( & V_2 -> V_174 ) ;
V_66 = V_930 -> args . V_300 -> V_66 ;
} else {
F_569 ( V_940 ) ;
F_570 ( V_934 , & V_940 , NULL ) ;
F_36 ( & V_2 -> V_174 ) ;
F_571 ( & V_940 ) ;
V_119 -> V_148 = 0 ;
F_57 ( V_119 ) ;
}
}
if ( F_244 ( V_119 , V_14 , V_66 , NULL ) == - V_129 )
F_57 ( V_119 ) ;
V_130:
F_8 ( L_83 , V_34 ) ;
}
static T_9 F_572 ( struct V_13 * V_14 )
{
T_1 V_896 = V_14 -> V_63 -> V_87 -> V_900 . V_896 ;
return F_573 ( 0 , V_896 ) ;
}
static void F_574 ( struct V_483 * * V_42 , T_9 V_941 )
{
int V_472 ;
if ( ! V_42 )
return;
for ( V_472 = 0 ; V_472 < V_941 ; V_472 ++ ) {
if ( ! V_42 [ V_472 ] )
break;
F_277 ( V_42 [ V_472 ] ) ;
}
F_97 ( V_42 ) ;
}
static struct V_483 * * F_575 ( T_9 V_941 , T_6 V_942 )
{
struct V_483 * * V_42 ;
int V_472 ;
V_42 = F_576 ( V_941 , sizeof( struct V_483 * ) , V_942 ) ;
if ( ! V_42 ) {
F_8 ( L_101 , V_34 , V_941 ) ;
return NULL ;
}
for ( V_472 = 0 ; V_472 < V_941 ; V_472 ++ ) {
V_42 [ V_472 ] = F_273 ( V_942 ) ;
if ( ! V_42 [ V_472 ] ) {
F_8 ( L_102 , V_34 ) ;
F_574 ( V_42 , V_941 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_577 ( void * V_155 )
{
struct V_929 * V_930 = V_155 ;
struct V_2 * V_2 = V_930 -> args . V_2 ;
struct V_13 * V_14 = F_87 ( V_2 ) ;
T_9 V_943 = F_572 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_574 ( V_930 -> args . V_931 . V_42 , V_943 ) ;
F_578 ( F_75 ( V_2 ) -> V_931 ) ;
F_168 ( V_930 -> args . V_300 ) ;
F_97 ( V_155 ) ;
F_8 ( L_83 , V_34 ) ;
}
struct V_944 *
F_579 ( struct V_929 * V_930 , T_6 V_942 )
{
struct V_2 * V_2 = V_930 -> args . V_2 ;
struct V_13 * V_14 = F_87 ( V_2 ) ;
T_9 V_943 = F_572 ( V_14 ) ;
struct V_118 * V_119 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_945 ] ,
. V_313 = & V_930 -> args ,
. V_314 = & V_930 -> V_57 ,
. V_315 = V_930 -> V_349 ,
} ;
struct V_163 V_316 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_946 ,
. V_169 = V_930 ,
. V_214 = V_320 ,
} ;
struct V_944 * V_947 = NULL ;
int V_305 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_580 ( F_75 ( V_2 ) -> V_931 ) ;
V_930 -> args . V_931 . V_42 = F_575 ( V_943 , V_942 ) ;
if ( ! V_930 -> args . V_931 . V_42 ) {
F_577 ( V_930 ) ;
return F_44 ( - V_125 ) ;
}
V_930 -> args . V_931 . V_510 = V_943 * V_608 ;
V_930 -> args . V_106 = V_153 ;
V_930 -> V_57 . V_948 = & V_930 -> args . V_931 ;
V_930 -> V_57 . V_160 . V_115 = NULL ;
F_38 ( & V_930 -> args . V_159 , & V_930 -> V_57 . V_160 , 0 ) ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) )
return F_253 ( V_119 ) ;
V_305 = F_108 ( V_119 ) ;
if ( V_305 == 0 )
V_305 = V_119 -> V_148 ;
F_581 ( V_930 -> args . V_300 ,
& V_930 -> args . V_932 ,
& V_930 -> V_57 . V_932 ,
V_305 ) ;
if ( V_305 == 0 && V_930 -> V_57 . V_948 -> V_12 )
V_947 = F_582 ( V_930 ) ;
F_72 ( V_119 ) ;
F_8 ( L_16 , V_34 , V_305 ) ;
if ( V_305 )
return F_44 ( V_305 ) ;
return V_947 ;
}
static void
F_583 ( struct V_118 * V_119 , void * V_155 )
{
struct V_949 * V_950 = V_155 ;
F_8 ( L_11 , V_34 ) ;
F_61 ( V_950 -> V_64 -> V_87 ,
& V_950 -> args . V_159 ,
& V_950 -> V_57 . V_160 ,
V_119 ) ;
}
static void F_584 ( struct V_118 * V_119 , void * V_155 )
{
struct V_949 * V_950 = V_155 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_53 ( V_119 , & V_950 -> V_57 . V_160 ) )
return;
V_14 = F_87 ( V_950 -> args . V_2 ) ;
switch ( V_119 -> V_148 ) {
default:
V_119 -> V_148 = 0 ;
case 0 :
break;
case - V_90 :
if ( F_244 ( V_119 , V_14 , NULL , NULL ) != - V_129 )
break;
F_57 ( V_119 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_585 ( void * V_155 )
{
struct V_949 * V_950 = V_155 ;
struct V_933 * V_934 = V_950 -> args . V_931 ;
F_8 ( L_11 , V_34 ) ;
F_34 ( & V_934 -> V_951 -> V_174 ) ;
if ( V_950 -> V_57 . V_952 )
F_586 ( V_934 , & V_950 -> V_57 . V_250 , true ) ;
F_587 ( V_934 ) ;
F_125 ( V_953 , & V_934 -> V_954 ) ;
F_588 ( & F_87 ( V_934 -> V_951 ) -> V_955 ) ;
V_934 -> V_956 -- ;
F_36 ( & V_934 -> V_951 -> V_174 ) ;
F_578 ( V_950 -> args . V_931 ) ;
F_435 ( V_950 -> V_2 ) ;
F_97 ( V_155 ) ;
F_8 ( L_83 , V_34 ) ;
}
int F_589 ( struct V_949 * V_950 , bool V_957 )
{
struct V_118 * V_119 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_958 ] ,
. V_313 = & V_950 -> args ,
. V_314 = & V_950 -> V_57 ,
. V_315 = V_950 -> V_349 ,
} ;
struct V_163 V_316 = {
. V_165 = F_87 ( V_950 -> args . V_2 ) -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_959 ,
. V_169 = V_950 ,
} ;
int V_305 = 0 ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_957 ) {
V_950 -> V_2 = F_438 ( V_950 -> args . V_2 ) ;
if ( ! V_950 -> V_2 ) {
F_585 ( V_950 ) ;
return - V_129 ;
}
V_316 . V_214 |= V_320 ;
}
F_38 ( & V_950 -> args . V_159 , & V_950 -> V_57 . V_160 , 1 ) ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) )
return F_71 ( V_119 ) ;
if ( V_957 )
V_305 = V_119 -> V_148 ;
F_590 ( V_950 -> args . V_2 , V_305 ) ;
F_8 ( L_16 , V_34 , V_305 ) ;
F_72 ( V_119 ) ;
return V_305 ;
}
static int
F_591 ( struct V_13 * V_14 ,
struct V_960 * V_961 ,
struct V_315 * V_349 )
{
struct V_962 args = {
. V_961 = V_961 ,
} ;
struct V_963 V_57 = {
. V_961 = V_961 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_964 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
int V_305 ;
F_8 ( L_11 , V_34 ) ;
V_305 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
F_8 ( L_16 , V_34 , V_305 ) ;
return V_305 ;
}
int F_592 ( struct V_13 * V_14 ,
struct V_960 * V_961 ,
struct V_315 * V_349 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_591 ( V_14 , V_961 , V_349 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static void F_593 ( struct V_118 * V_119 , void * V_155 )
{
struct V_965 * V_157 = V_155 ;
struct V_13 * V_14 = F_87 ( V_157 -> args . V_2 ) ;
struct V_132 * V_133 = F_64 ( V_14 ) ;
F_61 ( V_133 ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_119 ) ;
}
static void
F_594 ( struct V_118 * V_119 , void * V_155 )
{
struct V_965 * V_157 = V_155 ;
struct V_13 * V_14 = F_87 ( V_157 -> args . V_2 ) ;
if ( ! F_53 ( V_119 , & V_157 -> V_57 . V_160 ) )
return;
switch ( V_119 -> V_148 ) {
case - V_71 :
case - V_966 :
case - V_967 :
case - V_89 :
V_119 -> V_148 = 0 ;
case 0 :
break;
default:
if ( F_244 ( V_119 , V_14 , NULL , NULL ) == - V_129 ) {
F_57 ( V_119 ) ;
return;
}
}
}
static void F_595 ( void * V_155 )
{
struct V_965 * V_157 = V_155 ;
F_596 ( V_157 ) ;
F_439 ( V_157 -> args . V_2 ,
V_157 -> V_57 . V_387 ) ;
F_210 ( V_157 -> V_349 ) ;
F_435 ( V_157 -> V_2 ) ;
F_97 ( V_157 ) ;
}
int
F_597 ( struct V_965 * V_157 , bool V_957 )
{
struct V_161 V_162 = {
. V_310 = & V_311 [ V_968 ] ,
. V_313 = & V_157 -> args ,
. V_314 = & V_157 -> V_57 ,
. V_315 = V_157 -> V_349 ,
} ;
struct V_163 V_316 = {
. V_119 = & V_157 -> V_119 ,
. V_165 = F_292 ( V_157 -> args . V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_969 ,
. V_169 = V_157 ,
} ;
struct V_118 * V_119 ;
int V_305 = 0 ;
F_8 ( L_103
L_104 ,
V_157 -> V_119 . V_970 , V_957 ,
V_157 -> args . V_971 ,
V_157 -> args . V_2 -> V_972 ) ;
if ( ! V_957 ) {
V_157 -> V_2 = F_438 ( V_157 -> args . V_2 ) ;
if ( V_157 -> V_2 == NULL ) {
F_595 ( V_157 ) ;
return - V_129 ;
}
V_316 . V_214 = V_320 ;
}
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
V_119 = F_70 ( & V_316 ) ;
if ( F_43 ( V_119 ) )
return F_71 ( V_119 ) ;
if ( V_957 )
V_305 = V_119 -> V_148 ;
F_598 ( V_157 -> args . V_2 , V_305 ) ;
F_8 ( L_105 , V_34 , V_305 ) ;
F_72 ( V_119 ) ;
return V_305 ;
}
static int
F_599 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_459 ,
struct V_794 * V_475 , bool V_795 )
{
struct V_973 args = {
. V_974 = V_975 ,
} ;
struct V_797 V_57 = {
. V_475 = V_475 ,
} ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_976 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
} ;
struct V_55 * V_56 = V_14 -> V_91 ;
struct V_315 * V_349 = NULL ;
int V_305 ;
if ( V_795 ) {
V_56 = V_14 -> V_63 -> V_101 ;
V_349 = F_513 ( V_14 -> V_63 ) ;
V_162 . V_315 = V_349 ;
}
F_8 ( L_11 , V_34 ) ;
V_305 = F_73 ( V_56 , V_14 , & V_162 , & args . V_159 ,
& V_57 . V_160 , 0 ) ;
F_8 ( L_16 , V_34 , V_305 ) ;
if ( V_349 )
F_210 ( V_349 ) ;
return V_305 ;
}
static int
F_600 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_459 , struct V_794 * V_475 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( V_14 -> V_63 ) )
V_8 = F_599 ( V_14 , V_425 , V_459 ,
V_475 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_599 ( V_14 , V_425 , V_459 ,
V_475 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_977 :
goto V_130;
default:
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
}
} while ( V_62 . V_67 );
V_130:
return V_8 ;
}
static int
F_601 ( struct V_13 * V_14 , struct V_424 * V_425 ,
struct V_458 * V_459 )
{
int V_8 ;
struct V_483 * V_483 ;
T_4 V_100 = V_978 ;
struct V_794 * V_475 ;
struct V_979 * V_980 ;
int V_472 ;
V_483 = F_273 ( V_378 ) ;
if ( ! V_483 ) {
V_8 = - V_125 ;
goto V_130;
}
V_475 = F_388 ( V_483 ) ;
V_8 = F_600 ( V_14 , V_425 , V_459 , V_475 ) ;
if ( V_8 == - V_22 || V_8 == - V_977 ) {
V_8 = F_264 ( V_14 , V_425 , V_459 ) ;
goto V_981;
}
if ( V_8 )
goto V_981;
for ( V_472 = 0 ; V_472 < V_475 -> V_982 ; V_472 ++ ) {
V_980 = & V_475 -> V_475 [ V_472 ] ;
switch ( V_980 -> V_100 ) {
case V_471 :
case V_470 :
case V_983 :
V_100 = F_602 ( V_980 -> V_100 ,
& V_980 -> V_984 ) ;
break;
default:
V_100 = V_978 ;
break;
}
if ( ! F_603 ( & V_14 -> V_473 , V_100 ) )
V_100 = V_978 ;
if ( V_100 != V_978 ) {
V_8 = F_262 ( V_14 , V_425 ,
V_459 , V_100 ) ;
if ( ! V_8 )
break;
}
}
if ( V_100 == V_978 )
V_8 = - V_24 ;
V_981:
F_402 ( V_483 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_130:
return V_8 ;
}
static int F_604 ( struct V_13 * V_14 ,
T_8 * V_250 ,
struct V_315 * V_349 )
{
int V_305 ;
struct V_985 args = {
. V_250 = V_250 ,
} ;
struct V_986 V_57 ;
struct V_161 V_162 = {
. V_310 = & V_311 [ V_987 ] ,
. V_313 = & args ,
. V_314 = & V_57 ,
. V_315 = V_349 ,
} ;
struct V_55 * V_165 = V_14 -> V_91 ;
F_251 ( V_14 -> V_63 , V_845 ,
& V_165 , & V_162 ) ;
F_8 ( L_106 , V_250 ) ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_305 = F_69 ( V_165 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
if ( V_305 != V_362 ) {
F_8 ( L_107 , V_305 ) ;
return V_305 ;
}
F_8 ( L_108 , - V_57 . V_305 ) ;
return - V_57 . V_305 ;
}
static int F_207 ( struct V_13 * V_14 ,
T_8 * V_250 ,
struct V_315 * V_349 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_604 ( V_14 , V_250 , V_349 ) ;
if ( V_8 != - V_90 )
break;
F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static void F_605 ( struct V_118 * V_119 , void * V_155 )
{
struct V_988 * V_157 = V_155 ;
F_61 ( F_64 ( V_157 -> V_14 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_119 ) ;
}
static void F_606 ( struct V_118 * V_119 , void * V_155 )
{
struct V_988 * V_157 = V_155 ;
F_53 ( V_119 , & V_157 -> V_57 . V_160 ) ;
switch ( V_119 -> V_148 ) {
case - V_90 :
if ( F_244 ( V_119 , V_157 -> V_14 , NULL , NULL ) == - V_129 )
F_57 ( V_119 ) ;
}
}
static void F_607 ( void * V_155 )
{
F_97 ( V_155 ) ;
}
static struct V_118 * F_608 ( struct V_13 * V_14 ,
T_8 * V_250 ,
struct V_315 * V_349 ,
bool V_989 )
{
struct V_161 V_162 = {
. V_310 = & V_311 [ V_990 ] ,
. V_315 = V_349 ,
} ;
struct V_163 V_164 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_991 ,
. V_214 = V_320 ,
} ;
struct V_988 * V_157 ;
F_251 ( V_14 -> V_63 , V_845 ,
& V_164 . V_165 , & V_162 ) ;
F_8 ( L_109 , V_250 ) ;
V_157 = F_274 ( sizeof( * V_157 ) , V_302 ) ;
if ( ! V_157 )
return F_44 ( - V_125 ) ;
V_157 -> V_14 = V_14 ;
F_126 ( & V_157 -> args . V_250 , V_250 ) ;
V_164 . V_169 = V_157 ;
V_162 . V_313 = & V_157 -> args ;
V_162 . V_314 = & V_157 -> V_57 ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 0 ) ;
if ( V_989 )
F_39 ( & V_157 -> args . V_159 ) ;
return F_70 ( & V_164 ) ;
}
static int F_209 ( struct V_13 * V_14 ,
T_8 * V_250 ,
struct V_315 * V_349 )
{
struct V_118 * V_119 ;
int V_52 ;
V_119 = F_608 ( V_14 , V_250 , V_349 , true ) ;
if ( F_43 ( V_119 ) )
return F_71 ( V_119 ) ;
V_52 = F_109 ( V_119 ) ;
if ( ! V_52 )
V_52 = V_119 -> V_148 ;
F_72 ( V_119 ) ;
return V_52 ;
}
static void
F_609 ( struct V_13 * V_14 , struct V_280 * V_281 )
{
struct V_118 * V_119 ;
struct V_315 * V_349 = V_281 -> V_282 -> V_225 -> V_289 ;
V_119 = F_608 ( V_14 , & V_281 -> V_284 , V_349 , false ) ;
F_490 ( V_14 , V_281 ) ;
if ( F_43 ( V_119 ) )
return;
F_72 ( V_119 ) ;
}
static bool F_610 ( const T_8 * V_992 ,
const T_8 * V_993 )
{
if ( memcmp ( V_992 -> V_994 , V_993 -> V_994 , sizeof( V_992 -> V_994 ) ) != 0 )
return false ;
if ( V_992 -> V_204 == V_993 -> V_204 )
return true ;
if ( V_992 -> V_204 == 0 || V_993 -> V_204 == 0 )
return true ;
return false ;
}
static bool F_611 ( const T_8 * V_992 ,
const T_8 * V_993 )
{
return F_136 ( V_992 , V_993 ) ;
}
static struct V_218 *
F_612 ( struct V_220 * V_995 , T_6 V_996 )
{
return NULL ;
}
