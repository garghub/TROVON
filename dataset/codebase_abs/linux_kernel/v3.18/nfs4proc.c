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
return - V_29 ;
case - V_33 :
return - V_34 ;
default:
F_8 ( L_1 ,
V_35 , - V_8 ) ;
break;
}
return - V_36 ;
}
static void F_9 ( T_2 V_37 , T_3 * V_38 , struct V_4 * V_4 ,
struct V_39 * V_40 )
{
T_3 * V_41 , * V_42 ;
if ( V_37 > 2 ) {
V_40 -> V_37 = V_37 ;
memcpy ( & V_40 -> V_38 , V_38 , sizeof( V_40 -> V_38 ) ) ;
return;
}
V_40 -> V_37 = 0 ;
memset ( & V_40 -> V_38 , 0 , sizeof( V_40 -> V_38 ) ) ;
if ( V_37 == 2 )
return;
V_41 = V_42 = F_10 ( * V_40 -> V_43 ) ;
if ( V_37 == 0 ) {
* V_42 ++ = V_44 ;
* V_42 ++ = V_45 ;
* V_42 ++ = V_44 ;
* V_42 ++ = V_44 ;
memcpy ( V_42 , L_2 , 4 ) ;
V_42 ++ ;
* V_42 ++ = V_44 ;
* V_42 ++ = F_11 ( V_46 ) ;
* V_42 ++ = F_11 ( 8 ) ;
V_42 = F_12 ( V_42 , F_13 ( V_4 -> V_47 ) ) ;
}
* V_42 ++ = V_44 ;
* V_42 ++ = V_45 ;
* V_42 ++ = V_48 ;
* V_42 ++ = V_48 ;
memcpy ( V_42 , L_3 , 4 ) ;
V_42 ++ ;
* V_42 ++ = V_44 ;
* V_42 ++ = F_11 ( V_46 ) ;
* V_42 ++ = F_11 ( 8 ) ;
V_42 = F_12 ( V_42 , F_13 ( V_4 -> V_49 -> V_47 ) ) ;
V_40 -> V_50 = ( char * ) V_42 - ( char * ) V_41 ;
V_40 -> V_51 -= V_40 -> V_50 ;
F_14 ( V_41 ) ;
}
static long F_15 ( long * V_52 )
{
long V_53 ;
if ( ! V_52 )
return V_54 ;
if ( * V_52 <= 0 )
* V_52 = V_55 ;
if ( * V_52 > V_54 )
* V_52 = V_54 ;
V_53 = * V_52 ;
* V_52 <<= 1 ;
return V_53 ;
}
static int F_16 ( struct V_56 * V_57 , long * V_52 )
{
int V_58 = 0 ;
F_17 () ;
F_18 (
F_15 ( V_52 ) ) ;
if ( F_19 ( V_59 ) )
V_58 = - V_60 ;
return V_58 ;
}
static int F_20 ( struct V_13 * V_14 , int V_61 , struct V_62 * V_63 )
{
struct V_64 * V_65 = V_14 -> V_64 ;
struct V_66 * V_67 = V_63 -> V_67 ;
struct V_2 * V_2 = V_63 -> V_2 ;
int V_53 = V_61 ;
V_63 -> V_68 = 0 ;
switch( V_61 ) {
case 0 :
return 0 ;
case - V_69 :
if ( V_2 && F_21 ( V_2 , V_70 ) ) {
F_22 ( V_2 ) ;
V_63 -> V_68 = 1 ;
return 0 ;
}
if ( V_67 == NULL )
break;
V_53 = F_23 ( V_14 , V_67 ) ;
if ( V_53 < 0 )
break;
goto V_71;
case - V_72 :
case - V_73 :
case - V_74 :
if ( V_67 == NULL )
break;
V_53 = F_23 ( V_14 , V_67 ) ;
if ( V_53 < 0 )
break;
goto V_71;
case - V_75 :
if ( V_67 != NULL ) {
V_53 = F_23 ( V_14 , V_67 ) ;
if ( V_53 < 0 )
break;
}
case - V_76 :
case - V_77 :
F_24 ( V_65 ) ;
goto V_71;
case - V_78 :
V_53 = F_25 ( V_14 ) ;
if ( V_53 < 0 )
break;
goto V_71;
case - V_79 :
F_26 ( V_65 ) ;
goto V_71;
#if F_27 ( V_80 )
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
case - V_87 :
F_8 ( L_4 , V_35 ,
V_61 ) ;
F_28 ( V_65 -> V_88 , V_61 ) ;
goto V_71;
#endif
case - V_33 :
if ( V_63 -> V_52 > V_89 ) {
V_53 = - V_34 ;
break;
}
case - V_90 :
case - V_91 :
V_53 = F_16 ( V_14 -> V_92 , & V_63 -> V_52 ) ;
if ( V_53 != 0 )
break;
case - V_93 :
case - V_94 :
V_63 -> V_68 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_95 & V_96 ) {
V_14 -> V_95 &= ~ V_96 ;
V_63 -> V_68 = 1 ;
F_29 ( V_97 L_5
L_6
L_7
L_8 ,
V_14 -> V_64 -> V_98 ) ;
}
}
return F_7 ( V_53 ) ;
V_71:
V_53 = F_30 ( V_65 ) ;
if ( F_31 ( V_99 , & V_14 -> V_100 ) )
return - V_36 ;
if ( V_53 == 0 )
V_63 -> V_68 = 1 ;
return V_53 ;
}
static bool F_32 ( struct V_64 * V_65 )
{
T_4 V_101 = V_65 -> V_102 -> V_103 -> V_104 ;
if ( V_101 == V_105 ||
V_101 == V_106 )
return true ;
return false ;
}
static void F_33 ( struct V_64 * V_65 , unsigned long V_107 )
{
F_34 ( & V_65 -> V_108 ) ;
if ( F_35 ( V_65 -> V_109 , V_107 ) )
V_65 -> V_109 = V_107 ;
F_36 ( & V_65 -> V_108 ) ;
}
static void F_37 ( const struct V_13 * V_14 , unsigned long V_107 )
{
F_33 ( V_14 -> V_64 , V_107 ) ;
}
static void F_38 ( struct V_110 * args ,
struct V_111 * V_58 , int V_112 )
{
args -> V_113 = NULL ;
args -> V_114 = V_112 ;
args -> V_115 = 0 ;
V_58 -> V_116 = NULL ;
}
static void F_39 ( struct V_110 * args )
{
args -> V_115 = 1 ;
}
static int F_40 ( const struct V_13 * V_14 ,
struct V_110 * args ,
struct V_111 * V_58 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 = V_14 -> V_64 -> V_121 ;
struct V_122 * V_123 ;
if ( V_58 -> V_116 != NULL )
goto V_124;
F_34 ( & V_120 -> V_125 ) ;
if ( F_41 ( V_120 ) && ! args -> V_115 )
goto V_126;
V_123 = F_42 ( V_120 ) ;
if ( F_43 ( V_123 ) ) {
if ( V_123 == F_44 ( - V_127 ) )
V_118 -> V_128 = V_89 >> 2 ;
goto V_126;
}
F_36 ( & V_120 -> V_125 ) ;
args -> V_113 = V_123 ;
V_58 -> V_116 = V_123 ;
V_124:
F_45 ( V_118 ) ;
return 0 ;
V_126:
if ( args -> V_115 )
F_46 ( & V_120 -> V_129 , V_118 ,
NULL , V_130 ) ;
else
F_47 ( & V_120 -> V_129 , V_118 , NULL ) ;
F_36 ( & V_120 -> V_125 ) ;
return - V_131 ;
}
static int F_48 ( struct V_117 * V_118 ,
struct V_111 * V_58 )
{
struct V_122 * V_123 = V_58 -> V_116 ;
struct V_119 * V_120 ;
if ( V_123 == NULL )
goto V_132;
V_120 = V_123 -> V_133 ;
F_34 ( & V_120 -> V_125 ) ;
if ( ! F_49 ( V_120 , V_123 ) )
F_50 ( V_120 , V_123 ) ;
F_36 ( & V_120 -> V_125 ) ;
V_58 -> V_116 = NULL ;
V_132:
return 1 ;
}
static void F_51 ( struct V_111 * V_58 )
{
struct V_134 * V_135 ;
struct V_119 * V_120 ;
struct V_122 * V_123 = V_58 -> V_116 ;
bool V_136 = false ;
V_120 = V_123 -> V_133 ;
V_135 = V_120 -> V_135 ;
F_34 ( & V_120 -> V_125 ) ;
if ( V_120 -> V_137 > V_120 -> V_138 )
V_136 = true ;
if ( F_49 ( V_120 , V_123 ) ) {
V_136 = false ;
goto V_139;
}
F_50 ( V_120 , V_123 ) ;
if ( V_120 -> V_137 != V_140 )
V_136 = false ;
V_139:
F_36 ( & V_120 -> V_125 ) ;
V_58 -> V_116 = NULL ;
if ( V_136 )
F_52 ( V_135 -> V_65 ) ;
}
int F_53 ( struct V_117 * V_118 , struct V_111 * V_58 )
{
struct V_134 * V_135 ;
struct V_122 * V_123 = V_58 -> V_116 ;
struct V_64 * V_65 ;
bool V_141 = false ;
int V_53 = 1 ;
if ( V_123 == NULL )
goto V_142;
if ( ! F_54 ( V_118 ) )
goto V_132;
V_135 = V_123 -> V_133 -> V_135 ;
if ( V_123 -> V_141 ) {
V_123 -> V_141 = 0 ;
V_141 = true ;
}
F_55 ( V_135 , V_58 ) ;
switch ( V_58 -> V_143 ) {
case 0 :
++ V_123 -> V_144 ;
V_65 = V_135 -> V_65 ;
F_33 ( V_65 , V_58 -> V_145 ) ;
if ( V_58 -> V_146 != 0 )
F_24 ( V_65 ) ;
F_56 ( V_123 -> V_133 , V_123 , V_58 ) ;
break;
case 1 :
V_123 -> V_141 = 1 ;
goto V_132;
case - V_91 :
F_8 ( L_9 ,
V_35 ,
V_123 -> V_147 ,
V_123 -> V_144 ) ;
goto V_148;
case - V_82 :
goto V_149;
case - V_87 :
if ( V_141 ) {
++ V_123 -> V_144 ;
goto V_149;
}
if ( V_123 -> V_144 != 1 ) {
V_123 -> V_144 = 1 ;
goto V_149;
}
break;
case - V_86 :
++ V_123 -> V_144 ;
goto V_149;
default:
++ V_123 -> V_144 ;
}
V_132:
F_8 ( L_10 , V_35 , V_58 -> V_143 ) ;
F_51 ( V_58 ) ;
V_142:
return V_53 ;
V_149:
if ( F_57 ( V_118 ) ) {
V_118 -> V_150 = 0 ;
V_53 = 0 ;
}
goto V_132;
V_148:
if ( ! F_58 ( V_118 ) )
goto V_132;
F_59 ( V_118 , V_54 ) ;
return 0 ;
}
static int F_60 ( struct V_117 * V_118 ,
struct V_111 * V_58 )
{
if ( V_58 -> V_116 == NULL )
return 1 ;
if ( ! V_58 -> V_116 -> V_133 -> V_135 )
return F_48 ( V_118 , V_58 ) ;
return F_53 ( V_118 , V_58 ) ;
}
int F_61 ( struct V_134 * V_135 ,
struct V_110 * args ,
struct V_111 * V_58 ,
struct V_117 * V_118 )
{
struct V_122 * V_123 ;
struct V_119 * V_120 ;
F_8 ( L_11 , V_35 ) ;
if ( V_58 -> V_116 != NULL )
goto V_151;
V_120 = & V_135 -> V_152 ;
V_118 -> V_128 = 0 ;
F_34 ( & V_120 -> V_125 ) ;
if ( F_31 ( V_153 , & V_120 -> V_154 ) &&
! args -> V_115 ) {
F_8 ( L_12 , V_35 ) ;
goto V_126;
}
V_123 = F_42 ( V_120 ) ;
if ( F_43 ( V_123 ) ) {
if ( V_123 == F_44 ( - V_127 ) )
V_118 -> V_128 = V_89 >> 2 ;
F_8 ( L_13 , V_35 ) ;
goto V_126;
}
F_36 ( & V_120 -> V_125 ) ;
args -> V_113 = V_123 ;
F_8 ( L_14 , V_35 ,
V_123 -> V_147 , V_123 -> V_144 ) ;
V_58 -> V_116 = V_123 ;
V_58 -> V_145 = V_155 ;
V_58 -> V_146 = 0 ;
V_58 -> V_143 = 1 ;
F_62 ( V_135 , args ) ;
V_151:
F_45 ( V_118 ) ;
return 0 ;
V_126:
if ( args -> V_115 )
F_46 ( & V_120 -> V_129 , V_118 ,
NULL , V_130 ) ;
else
F_47 ( & V_120 -> V_129 , V_118 , NULL ) ;
F_36 ( & V_120 -> V_125 ) ;
return - V_131 ;
}
static int F_63 ( const struct V_13 * V_14 ,
struct V_110 * args ,
struct V_111 * V_58 ,
struct V_117 * V_118 )
{
struct V_134 * V_135 = F_64 ( V_14 ) ;
int V_53 = 0 ;
if ( ! V_135 )
return F_40 ( V_14 , args , V_58 , V_118 ) ;
F_8 ( L_15 ,
V_35 , V_135 -> V_65 , V_135 , V_58 -> V_116 ?
V_58 -> V_116 -> V_147 : V_140 ) ;
V_53 = F_61 ( V_135 , args , V_58 , V_118 ) ;
F_8 ( L_16 , V_35 , V_53 ) ;
return V_53 ;
}
static void F_65 ( struct V_117 * V_118 , void * V_156 )
{
struct V_157 * V_158 = V_156 ;
struct V_134 * V_135 = F_64 ( V_158 -> V_159 ) ;
F_8 ( L_17 , V_35 , V_158 -> V_159 ) ;
F_61 ( V_135 , V_158 -> V_160 , V_158 -> V_161 , V_118 ) ;
}
static void F_66 ( struct V_117 * V_118 , void * V_156 )
{
struct V_157 * V_158 = V_156 ;
F_53 ( V_118 , V_158 -> V_161 ) ;
}
static int F_63 ( const struct V_13 * V_14 ,
struct V_110 * args ,
struct V_111 * V_58 ,
struct V_117 * V_118 )
{
return F_40 ( V_14 , args , V_58 , V_118 ) ;
}
static int F_60 ( struct V_117 * V_118 ,
struct V_111 * V_58 )
{
return F_48 ( V_118 , V_58 ) ;
}
static void F_67 ( struct V_117 * V_118 , void * V_156 )
{
struct V_157 * V_158 = V_156 ;
F_63 ( V_158 -> V_159 ,
V_158 -> V_160 , V_158 -> V_161 , V_118 ) ;
}
static void F_68 ( struct V_117 * V_118 , void * V_156 )
{
struct V_157 * V_158 = V_156 ;
F_60 ( V_118 , V_158 -> V_161 ) ;
}
static int F_69 ( struct V_56 * V_57 ,
struct V_13 * V_14 ,
struct V_162 * V_163 ,
struct V_110 * args ,
struct V_111 * V_58 )
{
int V_53 ;
struct V_117 * V_118 ;
struct V_64 * V_65 = V_14 -> V_64 ;
struct V_157 V_158 = {
. V_159 = V_14 ,
. V_160 = args ,
. V_161 = V_58 ,
} ;
struct V_164 V_165 = {
. V_166 = V_57 ,
. V_162 = V_163 ,
. V_167 = V_65 -> V_168 -> V_169 ,
. V_170 = & V_158
} ;
V_118 = F_70 ( & V_165 ) ;
if ( F_43 ( V_118 ) )
V_53 = F_71 ( V_118 ) ;
else {
V_53 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
}
return V_53 ;
}
int F_73 ( struct V_56 * V_57 ,
struct V_13 * V_14 ,
struct V_162 * V_163 ,
struct V_110 * args ,
struct V_111 * V_58 ,
int V_112 )
{
F_38 ( args , V_58 , V_112 ) ;
return F_69 ( V_57 , V_14 , V_163 , args , V_58 ) ;
}
static void F_74 ( struct V_2 * V_3 , struct V_171 * V_172 )
{
struct V_173 * V_174 = F_75 ( V_3 ) ;
F_34 ( & V_3 -> V_175 ) ;
V_174 -> V_176 |= V_177 | V_178 ;
if ( ! V_172 -> V_179 || V_172 -> V_180 != V_3 -> V_181 )
F_76 ( V_3 ) ;
V_3 -> V_181 = V_172 -> V_182 ;
F_77 ( V_3 ) ;
F_36 ( & V_3 -> V_175 ) ;
}
static bool F_78 ( struct V_13 * V_14 ,
int V_8 , struct V_62 * V_63 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_95 & V_183 ) )
return false ;
V_14 -> V_95 &= ~ V_183 ;
V_63 -> V_68 = 1 ;
return true ;
}
static enum V_184
F_79 ( struct V_13 * V_14 ,
enum V_184 V_185 )
{
if ( V_14 -> V_95 & V_183 )
return V_185 ;
switch ( V_185 ) {
default:
return V_185 ;
case V_186 :
return V_187 ;
case V_188 :
return V_189 ;
case V_190 :
return V_191 ;
}
}
static void F_80 ( struct V_192 * V_42 )
{
V_42 -> V_193 . V_194 = & V_42 -> V_194 ;
V_42 -> V_193 . V_195 = V_42 -> V_195 ;
V_42 -> V_193 . V_196 = V_42 -> V_197 . V_196 ;
V_42 -> V_198 . V_196 = V_42 -> V_199 . V_196 ;
V_42 -> V_193 . V_14 = V_42 -> V_197 . V_14 ;
V_42 -> V_193 . V_200 = V_42 -> V_197 . V_201 ;
F_81 ( & V_42 -> V_194 ) ;
F_82 ( & V_42 -> V_194 , & V_42 -> V_202 , & V_42 -> V_203 ) ;
}
static struct V_192 * F_83 ( struct V_4 * V_4 ,
struct V_204 * V_205 , T_5 V_206 , int V_207 ,
const struct V_5 * V_208 ,
struct V_1 * V_7 ,
enum V_184 V_185 ,
T_6 V_209 )
{
struct V_4 * V_210 = F_84 ( V_4 ) ;
struct V_2 * V_3 = V_210 -> V_47 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_192 * V_42 ;
V_42 = F_86 ( sizeof( * V_42 ) , V_209 ) ;
if ( V_42 == NULL )
goto V_8;
V_42 -> V_195 = F_87 ( V_14 , V_209 ) ;
if ( F_43 ( V_42 -> V_195 ) )
goto V_211;
V_42 -> V_197 . V_196 = F_88 ( & V_205 -> V_212 , V_209 ) ;
if ( V_42 -> V_197 . V_196 == NULL )
goto V_213;
F_89 ( V_4 -> V_214 ) ;
V_42 -> V_4 = F_90 ( V_4 ) ;
V_42 -> V_3 = V_210 ;
V_42 -> V_215 = V_205 ;
F_91 ( & V_205 -> V_216 ) ;
V_42 -> V_197 . V_217 = V_207 ;
V_42 -> V_197 . V_206 = V_206 & ( V_70 | V_218 ) ;
if ( ! ( V_207 & V_219 ) ) {
V_42 -> V_197 . V_201 = V_220 | V_221 |
V_222 | V_223 ;
}
V_42 -> V_197 . V_224 = V_14 -> V_64 -> V_225 ;
V_42 -> V_197 . V_226 . V_227 = F_92 ( V_205 -> V_212 . V_227 ) ;
V_42 -> V_197 . V_226 . V_228 = V_205 -> V_212 . V_229 ;
V_42 -> V_197 . V_230 = & V_4 -> V_11 ;
V_42 -> V_197 . V_14 = V_14 ;
V_42 -> V_197 . V_231 = F_6 ( V_14 , V_7 ) ;
V_42 -> V_197 . V_232 = & V_233 [ 0 ] ;
V_42 -> V_197 . V_7 = V_7 ;
V_42 -> V_197 . V_185 = F_79 ( V_14 , V_185 ) ;
switch ( V_42 -> V_197 . V_185 ) {
case V_187 :
case V_189 :
case V_191 :
V_42 -> V_197 . V_234 = F_93 ( V_3 ) ;
break;
case V_235 :
case V_186 :
case V_188 :
case V_190 :
V_42 -> V_197 . V_234 = F_93 ( V_4 -> V_47 ) ;
}
if ( V_208 != NULL && V_208 -> V_236 != 0 ) {
T_7 V_237 [ 2 ] ;
V_42 -> V_197 . V_238 . V_208 = & V_42 -> V_208 ;
memcpy ( & V_42 -> V_208 , V_208 , sizeof( V_42 -> V_208 ) ) ;
V_237 [ 0 ] = V_155 ;
V_237 [ 1 ] = V_59 -> V_239 ;
memcpy ( V_42 -> V_197 . V_238 . V_38 . V_158 , V_237 ,
sizeof( V_42 -> V_197 . V_238 . V_38 . V_158 ) ) ;
}
V_42 -> V_199 . V_234 = & V_42 -> V_193 . V_234 ;
V_42 -> V_199 . V_240 = & V_42 -> V_193 . V_240 ;
V_42 -> V_199 . V_196 = V_42 -> V_197 . V_196 ;
F_80 ( V_42 ) ;
F_94 ( & V_42 -> V_241 ) ;
return V_42 ;
V_213:
F_95 ( V_42 -> V_195 ) ;
V_211:
F_96 ( V_42 ) ;
V_8:
F_97 ( V_210 ) ;
return NULL ;
}
static void F_98 ( struct V_241 * V_241 )
{
struct V_192 * V_42 = F_99 ( V_241 ,
struct V_192 , V_241 ) ;
struct V_242 * V_243 = V_42 -> V_4 -> V_214 ;
F_100 ( V_42 -> V_197 . V_196 ) ;
if ( V_42 -> V_67 != NULL )
F_101 ( V_42 -> V_67 ) ;
F_102 ( V_42 -> V_215 ) ;
F_95 ( V_42 -> V_195 ) ;
F_97 ( V_42 -> V_3 ) ;
F_97 ( V_42 -> V_4 ) ;
F_103 ( V_243 ) ;
F_104 ( & V_42 -> V_194 ) ;
F_96 ( V_42 -> V_194 . V_244 ) ;
F_96 ( V_42 ) ;
}
static void F_105 ( struct V_192 * V_42 )
{
if ( V_42 != NULL )
F_106 ( & V_42 -> V_241 , F_98 ) ;
}
static int F_107 ( struct V_117 * V_118 )
{
int V_53 ;
V_53 = F_108 ( V_118 ) ;
return V_53 ;
}
static int F_109 ( struct V_66 * V_67 , T_5 V_245 , int V_246 )
{
int V_53 = 0 ;
if ( V_246 & ( V_219 | V_247 ) )
goto V_132;
switch ( V_245 & ( V_70 | V_218 ) ) {
case V_70 :
V_53 |= F_31 ( V_248 , & V_67 -> V_207 ) != 0
&& V_67 -> V_249 != 0 ;
break;
case V_218 :
V_53 |= F_31 ( V_250 , & V_67 -> V_207 ) != 0
&& V_67 -> V_251 != 0 ;
break;
case V_70 | V_218 :
V_53 |= F_31 ( V_252 , & V_67 -> V_207 ) != 0
&& V_67 -> V_253 != 0 ;
}
V_132:
return V_53 ;
}
static int F_110 ( struct V_254 * V_255 , T_5 V_206 )
{
if ( V_255 == NULL )
return 0 ;
if ( ( V_255 -> type & V_206 ) != V_206 )
return 0 ;
if ( F_31 ( V_256 , & V_255 -> V_207 ) )
return 0 ;
if ( F_31 ( V_257 , & V_255 -> V_207 ) )
return 0 ;
F_111 ( V_255 ) ;
return 1 ;
}
static void F_112 ( struct V_66 * V_67 , T_5 V_206 )
{
switch ( V_206 ) {
case V_218 :
V_67 -> V_251 ++ ;
break;
case V_70 :
V_67 -> V_249 ++ ;
break;
case V_70 | V_218 :
V_67 -> V_253 ++ ;
}
F_113 ( V_67 , V_67 -> V_67 | V_206 ) ;
}
static void F_114 ( struct V_66 * V_67 )
{
struct V_64 * V_65 = V_67 -> V_215 -> V_258 -> V_64 ;
bool V_259 = false ;
if ( F_115 ( V_248 , & V_67 -> V_207 ) && V_67 -> V_249 )
V_259 = true ;
if ( F_115 ( V_250 , & V_67 -> V_207 ) && V_67 -> V_251 )
V_259 = true ;
if ( F_115 ( V_252 , & V_67 -> V_207 ) && V_67 -> V_253 )
V_259 = true ;
if ( V_259 )
F_116 ( V_65 , V_67 ) ;
}
static bool F_117 ( struct V_66 * V_67 ,
T_8 * V_240 )
{
if ( F_118 ( V_260 , & V_67 -> V_207 ) == 0 )
return true ;
if ( ! F_119 ( V_240 , & V_67 -> V_261 ) ) {
F_114 ( V_67 ) ;
return true ;
}
if ( F_120 ( V_240 , & V_67 -> V_261 ) )
return true ;
return false ;
}
static void F_121 ( struct V_66 * V_67 ,
T_8 * V_240 , T_5 V_206 )
{
F_122 ( V_252 , & V_67 -> V_207 ) ;
switch ( V_206 & ( V_70 | V_218 ) ) {
case V_218 :
F_122 ( V_248 , & V_67 -> V_207 ) ;
break;
case V_70 :
F_122 ( V_250 , & V_67 -> V_207 ) ;
break;
case 0 :
F_122 ( V_248 , & V_67 -> V_207 ) ;
F_122 ( V_250 , & V_67 -> V_207 ) ;
F_122 ( V_260 , & V_67 -> V_207 ) ;
}
if ( V_240 == NULL )
return;
if ( ! F_117 ( V_67 , V_240 ) )
return;
if ( F_31 ( V_262 , & V_67 -> V_207 ) == 0 )
F_123 ( & V_67 -> V_240 , V_240 ) ;
F_123 ( & V_67 -> V_261 , V_240 ) ;
}
static void F_124 ( struct V_66 * V_67 , T_8 * V_240 , T_5 V_206 )
{
F_125 ( & V_67 -> V_263 ) ;
F_121 ( V_67 , V_240 , V_206 ) ;
F_126 ( & V_67 -> V_263 ) ;
if ( F_31 ( V_264 , & V_67 -> V_207 ) )
F_127 ( V_67 -> V_215 -> V_258 -> V_64 ) ;
}
static void F_128 ( struct V_66 * V_67 , T_8 * V_240 , T_5 V_206 )
{
switch ( V_206 ) {
case V_70 :
F_129 ( V_248 , & V_67 -> V_207 ) ;
break;
case V_218 :
F_129 ( V_250 , & V_67 -> V_207 ) ;
break;
case V_70 | V_218 :
F_129 ( V_252 , & V_67 -> V_207 ) ;
}
if ( ! F_117 ( V_67 , V_240 ) )
return;
if ( F_31 ( V_262 , & V_67 -> V_207 ) == 0 )
F_123 ( & V_67 -> V_240 , V_240 ) ;
F_123 ( & V_67 -> V_261 , V_240 ) ;
}
static void F_130 ( struct V_66 * V_67 , T_8 * V_261 , const T_8 * V_265 , T_5 V_206 )
{
F_125 ( & V_67 -> V_263 ) ;
if ( V_265 != NULL ) {
F_123 ( & V_67 -> V_240 , V_265 ) ;
F_129 ( V_262 , & V_67 -> V_207 ) ;
}
if ( V_261 != NULL )
F_128 ( V_67 , V_261 , V_206 ) ;
F_126 ( & V_67 -> V_263 ) ;
F_34 ( & V_67 -> V_215 -> V_266 ) ;
F_112 ( V_67 , V_206 ) ;
F_36 ( & V_67 -> V_215 -> V_266 ) ;
}
static int F_131 ( struct V_66 * V_67 , T_8 * V_261 , T_8 * V_255 , T_5 V_206 )
{
struct V_173 * V_174 = F_75 ( V_67 -> V_2 ) ;
struct V_254 * V_267 ;
int V_53 = 0 ;
V_206 &= ( V_70 | V_218 ) ;
F_132 () ;
V_267 = F_133 ( V_174 -> V_255 ) ;
if ( V_267 == NULL )
goto V_268;
F_34 ( & V_267 -> V_269 ) ;
if ( F_133 ( V_174 -> V_255 ) != V_267 ||
F_31 ( V_257 , & V_267 -> V_207 ) ||
( V_267 -> type & V_206 ) != V_206 )
goto V_270;
if ( V_255 == NULL )
V_255 = & V_267 -> V_240 ;
else if ( ! F_134 ( & V_267 -> V_240 , V_255 ) )
goto V_270;
F_111 ( V_267 ) ;
F_130 ( V_67 , V_261 , & V_267 -> V_240 , V_206 ) ;
V_53 = 1 ;
V_270:
F_36 ( & V_267 -> V_269 ) ;
V_268:
F_135 () ;
if ( ! V_53 && V_261 != NULL ) {
F_130 ( V_67 , V_261 , NULL , V_206 ) ;
V_53 = 1 ;
}
if ( F_31 ( V_264 , & V_67 -> V_207 ) )
F_127 ( V_67 -> V_215 -> V_258 -> V_64 ) ;
return V_53 ;
}
static void F_136 ( struct V_2 * V_2 , T_5 V_206 )
{
struct V_254 * V_255 ;
F_132 () ;
V_255 = F_133 ( F_75 ( V_2 ) -> V_255 ) ;
if ( V_255 == NULL || ( V_255 -> type & V_206 ) == V_206 ) {
F_135 () ;
return;
}
F_135 () ;
F_22 ( V_2 ) ;
}
static struct V_66 * F_137 ( struct V_192 * V_271 )
{
struct V_66 * V_67 = V_271 -> V_67 ;
struct V_173 * V_174 = F_75 ( V_67 -> V_2 ) ;
struct V_254 * V_255 ;
int V_246 = V_271 -> V_197 . V_217 ;
T_5 V_206 = V_271 -> V_197 . V_206 ;
T_8 V_240 ;
int V_53 = - V_131 ;
for (; ; ) {
F_34 ( & V_67 -> V_215 -> V_266 ) ;
if ( F_109 ( V_67 , V_206 , V_246 ) ) {
F_112 ( V_67 , V_206 ) ;
F_36 ( & V_67 -> V_215 -> V_266 ) ;
goto V_272;
}
F_36 ( & V_67 -> V_215 -> V_266 ) ;
F_132 () ;
V_255 = F_133 ( V_174 -> V_255 ) ;
if ( ! F_110 ( V_255 , V_206 ) ) {
F_135 () ;
break;
}
F_123 ( & V_240 , & V_255 -> V_240 ) ;
F_135 () ;
F_138 ( V_271 -> V_197 . V_196 ) ;
if ( ! V_271 -> V_273 ) {
V_53 = F_139 ( V_67 -> V_2 , V_67 -> V_215 -> V_274 , V_246 ) ;
if ( V_53 != 0 )
goto V_132;
}
V_53 = - V_131 ;
if ( F_131 ( V_67 , NULL , & V_240 , V_206 ) )
goto V_272;
}
V_132:
return F_44 ( V_53 ) ;
V_272:
F_91 ( & V_67 -> V_51 ) ;
return V_67 ;
}
static void
F_140 ( struct V_192 * V_158 , struct V_66 * V_67 )
{
struct V_64 * V_65 = F_85 ( V_67 -> V_2 ) -> V_64 ;
struct V_254 * V_255 ;
int V_275 = 0 ;
F_132 () ;
V_255 = F_133 ( F_75 ( V_67 -> V_2 ) -> V_255 ) ;
if ( V_255 )
V_275 = V_255 -> V_207 ;
F_135 () ;
if ( V_158 -> V_197 . V_185 == V_189 ) {
F_141 ( L_18
L_19
L_20 ,
V_65 -> V_98 ) ;
} else if ( ( V_275 & 1UL << V_256 ) == 0 )
F_142 ( V_67 -> V_2 ,
V_158 -> V_215 -> V_274 ,
& V_158 -> V_193 ) ;
else
F_143 ( V_67 -> V_2 ,
V_158 -> V_215 -> V_274 ,
& V_158 -> V_193 ) ;
}
static struct V_66 *
F_144 ( struct V_192 * V_158 )
{
struct V_2 * V_2 = V_158 -> V_67 -> V_2 ;
struct V_66 * V_67 = V_158 -> V_67 ;
int V_53 ;
if ( ! V_158 -> V_276 ) {
if ( V_158 -> V_277 ) {
V_53 = V_158 -> V_277 ;
goto V_8;
}
goto V_278;
}
V_53 = F_145 ( V_2 , & V_158 -> V_194 ) ;
if ( V_53 )
goto V_8;
if ( V_158 -> V_193 . V_279 != 0 )
F_140 ( V_158 , V_67 ) ;
V_278:
F_131 ( V_67 , & V_158 -> V_193 . V_240 , NULL ,
V_158 -> V_197 . V_206 ) ;
F_91 ( & V_67 -> V_51 ) ;
return V_67 ;
V_8:
return F_44 ( V_53 ) ;
}
static struct V_66 *
F_146 ( struct V_192 * V_158 )
{
struct V_2 * V_2 ;
struct V_66 * V_67 = NULL ;
int V_53 ;
if ( ! V_158 -> V_276 ) {
V_67 = F_137 ( V_158 ) ;
goto V_132;
}
V_53 = - V_131 ;
if ( ! ( V_158 -> V_194 . V_280 & V_281 ) )
goto V_8;
V_2 = F_147 ( V_158 -> V_3 -> V_214 , & V_158 -> V_193 . V_234 , & V_158 -> V_194 , V_158 -> V_195 ) ;
V_53 = F_71 ( V_2 ) ;
if ( F_43 ( V_2 ) )
goto V_8;
V_53 = - V_127 ;
V_67 = F_148 ( V_2 , V_158 -> V_215 ) ;
if ( V_67 == NULL )
goto V_282;
if ( V_158 -> V_193 . V_279 != 0 )
F_140 ( V_158 , V_67 ) ;
F_131 ( V_67 , & V_158 -> V_193 . V_240 , NULL ,
V_158 -> V_197 . V_206 ) ;
F_149 ( V_2 ) ;
V_132:
F_138 ( V_158 -> V_197 . V_196 ) ;
return V_67 ;
V_282:
F_149 ( V_2 ) ;
V_8:
return F_44 ( V_53 ) ;
}
static struct V_66 *
F_150 ( struct V_192 * V_158 )
{
if ( V_158 -> V_197 . V_185 == V_235 )
return F_144 ( V_158 ) ;
return F_146 ( V_158 ) ;
}
static struct V_283 * F_151 ( struct V_66 * V_67 )
{
struct V_173 * V_174 = F_75 ( V_67 -> V_2 ) ;
struct V_283 * V_284 ;
F_34 ( & V_67 -> V_2 -> V_175 ) ;
F_152 (ctx, &nfsi->open_files, list) {
if ( V_284 -> V_67 != V_67 )
continue;
F_153 ( V_284 ) ;
F_36 ( & V_67 -> V_2 -> V_175 ) ;
return V_284 ;
}
F_36 ( & V_67 -> V_2 -> V_175 ) ;
return F_44 ( - V_285 ) ;
}
static struct V_192 * F_154 ( struct V_283 * V_284 ,
struct V_66 * V_67 , enum V_184 V_185 )
{
struct V_192 * V_271 ;
V_271 = F_83 ( V_284 -> V_4 , V_67 -> V_215 , 0 , 0 ,
NULL , NULL , V_185 , V_286 ) ;
if ( V_271 == NULL )
return F_44 ( - V_127 ) ;
V_271 -> V_67 = V_67 ;
F_91 ( & V_67 -> V_51 ) ;
return V_271 ;
}
static int F_155 ( struct V_192 * V_271 , T_5 V_206 , struct V_66 * * V_58 )
{
struct V_66 * V_287 ;
int V_53 ;
V_271 -> V_197 . V_217 = 0 ;
V_271 -> V_197 . V_206 = V_206 ;
memset ( & V_271 -> V_193 , 0 , sizeof( V_271 -> V_193 ) ) ;
memset ( & V_271 -> V_198 , 0 , sizeof( V_271 -> V_198 ) ) ;
F_80 ( V_271 ) ;
V_53 = F_156 ( V_271 ) ;
if ( V_53 != 0 )
return V_53 ;
V_287 = F_150 ( V_271 ) ;
if ( F_43 ( V_287 ) )
return F_71 ( V_287 ) ;
F_157 ( V_287 , V_206 ) ;
* V_58 = V_287 ;
return 0 ;
}
static int F_158 ( struct V_192 * V_271 , struct V_66 * V_67 )
{
struct V_66 * V_287 ;
int V_53 ;
F_122 ( V_252 , & V_67 -> V_207 ) ;
F_122 ( V_250 , & V_67 -> V_207 ) ;
F_122 ( V_248 , & V_67 -> V_207 ) ;
F_122 ( V_262 , & V_67 -> V_207 ) ;
F_122 ( V_260 , & V_67 -> V_207 ) ;
F_159 () ;
if ( V_67 -> V_253 != 0 ) {
V_53 = F_155 ( V_271 , V_70 | V_218 , & V_287 ) ;
if ( V_53 != 0 )
return V_53 ;
if ( V_287 != V_67 )
return - V_288 ;
}
if ( V_67 -> V_251 != 0 ) {
V_53 = F_155 ( V_271 , V_218 , & V_287 ) ;
if ( V_53 != 0 )
return V_53 ;
if ( V_287 != V_67 )
return - V_288 ;
}
if ( V_67 -> V_249 != 0 ) {
V_53 = F_155 ( V_271 , V_70 , & V_287 ) ;
if ( V_53 != 0 )
return V_53 ;
if ( V_287 != V_67 )
return - V_288 ;
}
if ( F_31 ( V_262 , & V_67 -> V_207 ) == 0 &&
! F_134 ( & V_67 -> V_240 , & V_67 -> V_261 ) ) {
F_125 ( & V_67 -> V_263 ) ;
if ( F_31 ( V_262 , & V_67 -> V_207 ) == 0 )
F_123 ( & V_67 -> V_240 , & V_67 -> V_261 ) ;
F_126 ( & V_67 -> V_263 ) ;
}
return 0 ;
}
static int F_160 ( struct V_283 * V_284 , struct V_66 * V_67 )
{
struct V_254 * V_255 ;
struct V_192 * V_271 ;
T_5 V_279 = 0 ;
int V_289 ;
V_271 = F_154 ( V_284 , V_67 ,
V_235 ) ;
if ( F_43 ( V_271 ) )
return F_71 ( V_271 ) ;
F_132 () ;
V_255 = F_133 ( F_75 ( V_67 -> V_2 ) -> V_255 ) ;
if ( V_255 != NULL && F_31 ( V_256 , & V_255 -> V_207 ) != 0 )
V_279 = V_255 -> type ;
F_135 () ;
V_271 -> V_197 . V_238 . V_279 = V_279 ;
V_289 = F_158 ( V_271 , V_67 ) ;
F_105 ( V_271 ) ;
return V_289 ;
}
static int F_161 ( struct V_283 * V_284 , struct V_66 * V_67 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_160 ( V_284 , V_67 ) ;
F_162 ( V_284 , 0 , V_8 ) ;
if ( F_78 ( V_14 , V_8 , & V_63 ) )
continue;
if ( V_8 != - V_91 )
break;
F_20 ( V_14 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_163 ( struct V_204 * V_205 , struct V_66 * V_67 )
{
struct V_283 * V_284 ;
int V_53 ;
V_284 = F_151 ( V_67 ) ;
if ( F_43 ( V_284 ) )
return - V_131 ;
V_53 = F_161 ( V_284 , V_67 ) ;
F_164 ( V_284 ) ;
return V_53 ;
}
static int F_165 ( struct V_13 * V_14 , struct V_66 * V_67 , const T_8 * V_240 , int V_8 )
{
switch ( V_8 ) {
default:
F_29 ( V_290 L_21
L_22 , V_35 , V_8 ) ;
case 0 :
case - V_285 :
case - V_288 :
break;
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
F_129 ( V_262 , & V_67 -> V_207 ) ;
F_28 ( V_14 -> V_64 -> V_88 , V_8 ) ;
return - V_131 ;
case - V_77 :
case - V_76 :
F_129 ( V_262 , & V_67 -> V_207 ) ;
case - V_75 :
F_24 ( V_14 -> V_64 ) ;
return - V_131 ;
case - V_78 :
F_25 ( V_14 ) ;
return - V_131 ;
case - V_79 :
F_26 ( V_14 -> V_64 ) ;
return - V_131 ;
case - V_72 :
case - V_73 :
case - V_74 :
case - V_69 :
F_166 ( V_67 -> V_2 ,
V_240 ) ;
F_23 ( V_14 , V_67 ) ;
return - V_131 ;
case - V_91 :
case - V_90 :
F_129 ( V_262 , & V_67 -> V_207 ) ;
F_167 ( 1 ) ;
return - V_131 ;
case - V_127 :
case - V_291 :
return 0 ;
}
return V_8 ;
}
int F_168 ( struct V_283 * V_284 , struct V_66 * V_67 , const T_8 * V_240 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
struct V_192 * V_271 ;
int V_8 ;
V_271 = F_154 ( V_284 , V_67 ,
V_188 ) ;
if ( F_43 ( V_271 ) )
return F_71 ( V_271 ) ;
F_123 ( & V_271 -> V_197 . V_238 . V_255 , V_240 ) ;
V_8 = F_158 ( V_271 , V_67 ) ;
F_105 ( V_271 ) ;
return F_165 ( V_14 , V_67 , V_240 , V_8 ) ;
}
static void F_169 ( struct V_117 * V_118 , void * V_156 )
{
struct V_192 * V_158 = V_156 ;
F_40 ( V_158 -> V_197 . V_14 , & V_158 -> V_199 . V_160 ,
& V_158 -> V_198 . V_161 , V_118 ) ;
}
static void F_170 ( struct V_117 * V_118 , void * V_156 )
{
struct V_192 * V_158 = V_156 ;
F_48 ( V_118 , & V_158 -> V_198 . V_161 ) ;
V_158 -> V_277 = V_118 -> V_150 ;
if ( V_158 -> V_277 == 0 ) {
F_123 ( & V_158 -> V_193 . V_240 , & V_158 -> V_198 . V_240 ) ;
F_171 ( & V_158 -> V_215 -> V_212 , 0 ) ;
F_37 ( V_158 -> V_193 . V_14 , V_158 -> V_107 ) ;
V_158 -> V_276 = 1 ;
}
}
static void F_172 ( void * V_156 )
{
struct V_192 * V_158 = V_156 ;
struct V_66 * V_67 = NULL ;
if ( V_158 -> V_292 == 0 )
goto V_293;
if ( ! V_158 -> V_276 )
goto V_293;
V_67 = F_150 ( V_158 ) ;
if ( ! F_43 ( V_67 ) )
F_157 ( V_67 , V_158 -> V_197 . V_206 ) ;
V_293:
F_105 ( V_158 ) ;
}
static int F_173 ( struct V_192 * V_158 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_3 -> V_47 ) ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_296 ] ,
. V_297 = & V_158 -> V_199 ,
. V_298 = & V_158 -> V_198 ,
. V_299 = V_158 -> V_215 -> V_274 ,
} ;
struct V_164 V_300 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_301 ,
. V_170 = V_158 ,
. V_302 = V_303 ,
. V_207 = V_304 ,
} ;
int V_289 ;
F_38 ( & V_158 -> V_199 . V_160 , & V_158 -> V_198 . V_161 , 1 ) ;
F_174 ( & V_158 -> V_241 ) ;
V_158 -> V_276 = 0 ;
V_158 -> V_277 = 0 ;
V_158 -> V_107 = V_155 ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_289 = F_107 ( V_118 ) ;
if ( V_289 != 0 ) {
V_158 -> V_292 = 1 ;
F_175 () ;
} else
V_289 = V_158 -> V_277 ;
F_72 ( V_118 ) ;
return V_289 ;
}
static void F_176 ( struct V_117 * V_118 , void * V_156 )
{
struct V_192 * V_158 = V_156 ;
struct V_204 * V_205 = V_158 -> V_215 ;
struct V_64 * V_65 = V_205 -> V_258 -> V_64 ;
if ( F_177 ( V_158 -> V_197 . V_196 , V_118 ) != 0 )
goto V_305;
if ( V_158 -> V_67 != NULL ) {
struct V_254 * V_255 ;
if ( F_109 ( V_158 -> V_67 , V_158 -> V_197 . V_206 , V_158 -> V_197 . V_217 ) )
goto V_306;
F_132 () ;
V_255 = F_133 ( F_75 ( V_158 -> V_67 -> V_2 ) -> V_255 ) ;
if ( V_158 -> V_197 . V_185 != V_189 &&
V_158 -> V_197 . V_185 != V_188 &&
F_110 ( V_255 , V_158 -> V_197 . V_206 ) )
goto V_307;
F_135 () ;
}
V_158 -> V_197 . V_224 = V_65 -> V_225 ;
switch ( V_158 -> V_197 . V_185 ) {
case V_235 :
case V_188 :
case V_190 :
V_158 -> V_197 . V_232 = & V_308 [ 0 ] ;
case V_186 :
V_118 -> V_309 . V_294 = & V_295 [ V_310 ] ;
F_178 ( & V_158 -> V_193 . V_234 , V_158 -> V_197 . V_234 ) ;
}
V_158 -> V_107 = V_155 ;
if ( F_63 ( V_158 -> V_197 . V_14 ,
& V_158 -> V_197 . V_160 ,
& V_158 -> V_193 . V_161 ,
V_118 ) != 0 )
F_138 ( V_158 -> V_197 . V_196 ) ;
V_158 -> V_197 . V_311 = V_312 ;
if ( V_158 -> V_197 . V_217 & V_219 ) {
V_158 -> V_197 . V_311 = V_313 ;
if ( F_179 ( V_65 ) )
V_158 -> V_197 . V_311 = V_314 ;
else if ( V_65 -> V_168 -> V_315 > 0 )
V_158 -> V_197 . V_311 = V_316 ;
}
return;
V_307:
F_135 () ;
V_306:
V_118 -> V_317 = NULL ;
V_305:
F_60 ( V_118 , & V_158 -> V_193 . V_161 ) ;
}
static void F_180 ( struct V_117 * V_118 , void * V_156 )
{
struct V_192 * V_158 = V_156 ;
V_158 -> V_277 = V_118 -> V_150 ;
if ( ! F_60 ( V_118 , & V_158 -> V_193 . V_161 ) )
return;
if ( V_118 -> V_150 == 0 ) {
if ( V_158 -> V_193 . V_194 -> V_280 & V_318 ) {
switch ( V_158 -> V_193 . V_194 -> V_245 & V_319 ) {
case V_320 :
break;
case V_321 :
V_158 -> V_277 = - V_322 ;
break;
case V_323 :
V_158 -> V_277 = - V_324 ;
break;
default:
V_158 -> V_277 = - V_325 ;
}
}
F_37 ( V_158 -> V_193 . V_14 , V_158 -> V_107 ) ;
if ( ! ( V_158 -> V_193 . V_326 & V_327 ) )
F_171 ( & V_158 -> V_215 -> V_212 , 0 ) ;
}
V_158 -> V_276 = 1 ;
}
static void F_181 ( void * V_156 )
{
struct V_192 * V_158 = V_156 ;
struct V_66 * V_67 = NULL ;
if ( V_158 -> V_292 == 0 )
goto V_293;
if ( V_158 -> V_277 != 0 || ! V_158 -> V_276 )
goto V_293;
if ( V_158 -> V_193 . V_326 & V_327 )
goto V_293;
V_67 = F_150 ( V_158 ) ;
if ( ! F_43 ( V_67 ) )
F_157 ( V_67 , V_158 -> V_197 . V_206 ) ;
V_293:
F_105 ( V_158 ) ;
}
static int F_182 ( struct V_192 * V_158 , int V_328 )
{
struct V_2 * V_3 = V_158 -> V_3 -> V_47 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_329 * V_197 = & V_158 -> V_197 ;
struct V_330 * V_193 = & V_158 -> V_193 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_331 ] ,
. V_297 = V_197 ,
. V_298 = V_193 ,
. V_299 = V_158 -> V_215 -> V_274 ,
} ;
struct V_164 V_300 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_332 ,
. V_170 = V_158 ,
. V_302 = V_303 ,
. V_207 = V_304 ,
} ;
int V_289 ;
F_38 ( & V_197 -> V_160 , & V_193 -> V_161 , 1 ) ;
F_174 ( & V_158 -> V_241 ) ;
V_158 -> V_276 = 0 ;
V_158 -> V_277 = 0 ;
V_158 -> V_292 = 0 ;
V_158 -> V_273 = 0 ;
if ( V_328 ) {
F_39 ( & V_197 -> V_160 ) ;
V_158 -> V_273 = 1 ;
}
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_289 = F_107 ( V_118 ) ;
if ( V_289 != 0 ) {
V_158 -> V_292 = 1 ;
F_175 () ;
} else
V_289 = V_158 -> V_277 ;
F_72 ( V_118 ) ;
return V_289 ;
}
static int F_156 ( struct V_192 * V_158 )
{
struct V_2 * V_3 = V_158 -> V_3 -> V_47 ;
struct V_330 * V_193 = & V_158 -> V_193 ;
int V_289 ;
V_289 = F_182 ( V_158 , 1 ) ;
if ( V_289 != 0 || ! V_158 -> V_276 )
return V_289 ;
F_183 ( F_85 ( V_3 ) , & V_158 -> V_194 ) ;
if ( V_193 -> V_326 & V_327 ) {
V_289 = F_173 ( V_158 ) ;
if ( V_289 != 0 )
return V_289 ;
}
return V_289 ;
}
static int F_184 ( struct V_299 * V_333 ,
struct V_192 * V_271 ,
struct V_66 * V_67 , T_5 V_206 ,
int V_334 )
{
struct V_335 V_336 ;
T_1 V_337 ;
if ( V_271 -> V_193 . V_338 == 0 )
return 0 ;
V_337 = 0 ;
if ( V_334 & V_339 ) {
V_337 = V_340 ;
} else if ( ( V_206 & V_70 ) && ! V_271 -> V_341 )
V_337 = V_342 ;
V_336 . V_333 = V_333 ;
V_336 . V_155 = V_155 ;
F_185 ( & V_336 , V_271 -> V_193 . V_343 ) ;
F_186 ( V_67 -> V_2 , & V_336 ) ;
if ( ( V_337 & ~ V_336 . V_337 & ( V_342 | V_340 ) ) == 0 )
return 0 ;
F_157 ( V_67 , V_206 ) ;
return - V_29 ;
}
static int F_187 ( struct V_192 * V_158 )
{
struct V_2 * V_3 = V_158 -> V_3 -> V_47 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_329 * V_197 = & V_158 -> V_197 ;
struct V_330 * V_193 = & V_158 -> V_193 ;
int V_289 ;
V_289 = F_182 ( V_158 , 0 ) ;
if ( ! V_158 -> V_276 )
return V_289 ;
if ( V_289 != 0 ) {
if ( V_289 == - V_26 &&
! ( V_197 -> V_217 & V_344 ) )
return - V_285 ;
return V_289 ;
}
F_183 ( V_14 , & V_158 -> V_194 ) ;
if ( V_197 -> V_217 & V_344 ) {
F_74 ( V_3 , & V_193 -> V_172 ) ;
if ( V_197 -> V_217 & V_219 )
V_158 -> V_341 = 1 ;
else if ( V_193 -> V_172 . V_180 != V_193 -> V_172 . V_182 )
V_158 -> V_341 = 1 ;
}
if ( ( V_193 -> V_326 & V_345 ) == 0 )
V_14 -> V_95 &= ~ V_346 ;
if( V_193 -> V_326 & V_327 ) {
V_289 = F_173 ( V_158 ) ;
if ( V_289 != 0 )
return V_289 ;
}
if ( ! ( V_193 -> V_194 -> V_280 & V_281 ) )
F_188 ( V_14 , & V_193 -> V_234 , V_193 -> V_194 , V_193 -> V_195 ) ;
return 0 ;
}
static int F_189 ( struct V_13 * V_14 )
{
return F_190 ( V_14 -> V_64 ) ;
}
static int F_191 ( struct V_283 * V_284 , struct V_66 * V_67 )
{
struct V_192 * V_271 ;
int V_53 ;
V_271 = F_154 ( V_284 , V_67 ,
V_186 ) ;
if ( F_43 ( V_271 ) )
return F_71 ( V_271 ) ;
V_53 = F_158 ( V_271 , V_67 ) ;
if ( V_53 == - V_288 )
F_192 ( V_284 -> V_4 ) ;
F_105 ( V_271 ) ;
return V_53 ;
}
static int F_193 ( struct V_283 * V_284 , struct V_66 * V_67 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_191 ( V_284 , V_67 ) ;
F_194 ( V_284 , 0 , V_8 ) ;
if ( F_78 ( V_14 , V_8 , & V_63 ) )
continue;
switch ( V_8 ) {
default:
goto V_132;
case - V_90 :
case - V_91 :
F_20 ( V_14 , V_8 , & V_63 ) ;
V_8 = 0 ;
}
} while ( V_63 . V_68 );
V_132:
return V_8 ;
}
static int F_195 ( struct V_204 * V_205 , struct V_66 * V_67 )
{
struct V_283 * V_284 ;
int V_53 ;
V_284 = F_151 ( V_67 ) ;
if ( F_43 ( V_284 ) )
return - V_131 ;
V_53 = F_193 ( V_284 , V_67 ) ;
F_164 ( V_284 ) ;
return V_53 ;
}
static void F_196 ( struct V_66 * V_67 )
{
F_197 ( V_67 -> V_2 ) ;
F_125 ( & V_67 -> V_263 ) ;
F_123 ( & V_67 -> V_240 , & V_67 -> V_261 ) ;
F_126 ( & V_67 -> V_263 ) ;
F_122 ( V_262 , & V_67 -> V_207 ) ;
}
static void F_198 ( struct V_66 * V_67 )
{
if ( F_199 ( F_75 ( V_67 -> V_2 ) -> V_255 ) != NULL )
F_196 ( V_67 ) ;
}
static int F_200 ( struct V_204 * V_205 , struct V_66 * V_67 )
{
F_198 ( V_67 ) ;
return F_195 ( V_205 , V_67 ) ;
}
static void F_201 ( struct V_66 * V_67 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
T_8 V_240 ;
struct V_254 * V_255 ;
struct V_299 * V_333 ;
int V_289 ;
F_132 () ;
V_255 = F_133 ( F_75 ( V_67 -> V_2 ) -> V_255 ) ;
if ( V_255 == NULL ) {
F_135 () ;
return;
}
F_123 ( & V_240 , & V_255 -> V_240 ) ;
V_333 = F_202 ( V_255 -> V_333 ) ;
F_135 () ;
V_289 = F_203 ( V_14 , & V_240 , V_333 ) ;
F_204 ( V_67 , NULL , V_289 ) ;
if ( V_289 != V_347 ) {
if ( V_289 != - V_74 )
F_205 ( V_14 , & V_240 , V_333 ) ;
F_196 ( V_67 ) ;
}
F_206 ( V_333 ) ;
}
static int F_207 ( struct V_66 * V_67 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
T_8 * V_240 = & V_67 -> V_261 ;
struct V_299 * V_333 = V_67 -> V_215 -> V_274 ;
int V_289 ;
if ( ( F_31 ( V_248 , & V_67 -> V_207 ) == 0 ) &&
( F_31 ( V_250 , & V_67 -> V_207 ) == 0 ) &&
( F_31 ( V_252 , & V_67 -> V_207 ) == 0 ) )
return - V_74 ;
V_289 = F_203 ( V_14 , V_240 , V_333 ) ;
F_208 ( V_67 , NULL , V_289 ) ;
if ( V_289 != V_347 ) {
if ( V_289 != - V_74 )
F_205 ( V_14 , V_240 , V_333 ) ;
F_122 ( V_248 , & V_67 -> V_207 ) ;
F_122 ( V_250 , & V_67 -> V_207 ) ;
F_122 ( V_252 , & V_67 -> V_207 ) ;
F_122 ( V_260 , & V_67 -> V_207 ) ;
}
return V_289 ;
}
static int F_209 ( struct V_204 * V_205 , struct V_66 * V_67 )
{
int V_289 ;
F_201 ( V_67 ) ;
V_289 = F_207 ( V_67 ) ;
if ( V_289 != V_347 )
V_289 = F_195 ( V_205 , V_67 ) ;
return V_289 ;
}
static inline void F_210 ( struct V_192 * V_271 , struct V_5 * V_6 )
{
if ( ( V_271 -> V_193 . V_348 [ 1 ] & V_349 ) &&
! ( V_6 -> V_236 & V_350 ) )
V_6 -> V_236 |= V_351 ;
if ( ( V_271 -> V_193 . V_348 [ 1 ] & V_352 ) &&
! ( V_6 -> V_236 & V_353 ) )
V_6 -> V_236 |= V_354 ;
}
static int F_211 ( struct V_192 * V_271 ,
T_5 V_206 ,
int V_207 ,
struct V_283 * V_284 )
{
struct V_204 * V_205 = V_271 -> V_215 ;
struct V_13 * V_14 = V_205 -> V_258 ;
struct V_4 * V_4 ;
struct V_66 * V_67 ;
unsigned int V_355 ;
int V_53 ;
V_355 = F_212 ( & V_205 -> V_356 ) ;
V_53 = F_187 ( V_271 ) ;
if ( V_53 != 0 )
goto V_132;
V_67 = F_150 ( V_271 ) ;
V_53 = F_71 ( V_67 ) ;
if ( F_43 ( V_67 ) )
goto V_132;
if ( V_14 -> V_95 & V_346 )
F_129 ( V_357 , & V_67 -> V_207 ) ;
V_4 = V_271 -> V_4 ;
if ( V_4 -> V_47 == NULL ) {
F_192 ( V_4 ) ;
V_4 = F_213 ( V_4 , F_214 ( V_67 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_271 -> V_4 ;
} else if ( V_4 != V_284 -> V_4 ) {
F_97 ( V_284 -> V_4 ) ;
V_284 -> V_4 = F_90 ( V_4 ) ;
}
F_215 ( V_4 ,
F_216 ( V_271 -> V_3 -> V_47 ) ) ;
}
V_53 = F_184 ( V_205 -> V_274 , V_271 , V_67 , V_206 , V_207 ) ;
if ( V_53 != 0 )
goto V_132;
V_284 -> V_67 = V_67 ;
if ( V_4 -> V_47 == V_67 -> V_2 ) {
F_217 ( V_284 ) ;
if ( F_218 ( & V_205 -> V_356 , V_355 ) )
F_23 ( V_14 , V_67 ) ;
}
V_132:
return V_53 ;
}
static int F_219 ( struct V_2 * V_3 ,
struct V_283 * V_284 ,
int V_207 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_358 )
{
struct V_204 * V_205 ;
struct V_66 * V_67 = NULL ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_192 * V_271 ;
struct V_4 * V_4 = V_284 -> V_4 ;
struct V_299 * V_333 = V_284 -> V_333 ;
struct V_359 * * V_360 = & V_284 -> V_244 ;
T_5 V_206 = V_284 -> V_245 & ( V_70 | V_218 | V_361 ) ;
enum V_184 V_185 = V_187 ;
struct V_1 * V_362 = NULL ;
int V_289 ;
V_289 = - V_127 ;
V_205 = F_220 ( V_14 , V_333 , V_363 ) ;
if ( V_205 == NULL ) {
F_8 ( L_23 ) ;
goto V_364;
}
V_289 = F_189 ( V_14 ) ;
if ( V_289 != 0 )
goto V_365;
if ( V_4 -> V_47 != NULL )
F_136 ( V_4 -> V_47 , V_206 ) ;
V_289 = - V_127 ;
if ( V_4 -> V_47 )
V_185 = V_186 ;
V_271 = F_83 ( V_4 , V_205 , V_206 , V_207 , V_6 ,
V_7 , V_185 , V_363 ) ;
if ( V_271 == NULL )
goto V_365;
if ( V_7 ) {
V_362 = F_87 ( V_14 , V_363 ) ;
if ( F_43 ( V_362 ) ) {
V_289 = F_71 ( V_362 ) ;
goto V_366;
}
}
if ( V_14 -> V_15 [ 2 ] & V_367 ) {
if ( ! V_271 -> V_194 . V_244 ) {
V_271 -> V_194 . V_244 = F_221 () ;
if ( ! V_271 -> V_194 . V_244 )
goto V_213;
}
V_271 -> V_197 . V_232 = & V_368 [ 0 ] ;
}
if ( V_4 -> V_47 != NULL )
V_271 -> V_67 = F_148 ( V_4 -> V_47 , V_205 ) ;
V_289 = F_211 ( V_271 , V_206 , V_207 , V_284 ) ;
if ( V_289 != 0 )
goto V_213;
V_67 = V_284 -> V_67 ;
if ( ( V_271 -> V_197 . V_217 & V_219 ) &&
( V_271 -> V_197 . V_311 != V_314 ) ) {
F_210 ( V_271 , V_6 ) ;
F_81 ( V_271 -> V_193 . V_194 ) ;
V_289 = F_222 ( V_67 -> V_2 , V_333 ,
V_271 -> V_193 . V_194 , V_6 ,
V_67 , V_7 , V_362 ) ;
if ( V_289 == 0 ) {
F_223 ( V_67 -> V_2 , V_6 ) ;
F_224 ( V_67 -> V_2 , V_271 -> V_193 . V_194 ) ;
F_225 ( V_67 -> V_2 , V_271 -> V_193 . V_194 , V_362 ) ;
}
}
if ( V_271 -> V_341 )
* V_358 |= V_369 ;
if ( F_226 ( V_360 , V_271 -> V_194 . V_244 , V_14 ) ) {
* V_360 = V_271 -> V_194 . V_244 ;
V_271 -> V_194 . V_244 = NULL ;
}
F_95 ( V_362 ) ;
F_105 ( V_271 ) ;
F_102 ( V_205 ) ;
return 0 ;
V_213:
F_95 ( V_362 ) ;
V_366:
F_105 ( V_271 ) ;
V_365:
F_102 ( V_205 ) ;
V_364:
return V_289 ;
}
static struct V_66 * F_227 ( struct V_2 * V_3 ,
struct V_283 * V_284 ,
int V_207 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_358 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_62 V_63 = { } ;
struct V_66 * V_58 ;
int V_289 ;
do {
V_289 = F_219 ( V_3 , V_284 , V_207 , V_6 , V_7 , V_358 ) ;
V_58 = V_284 -> V_67 ;
F_228 ( V_284 , V_207 , V_289 ) ;
if ( V_289 == 0 )
break;
if ( V_289 == - V_370 ) {
F_229 ( L_5
L_24 ,
F_85 ( V_3 ) -> V_64 -> V_98 ) ;
V_63 . V_68 = 1 ;
continue;
}
if ( V_289 == - V_74 ) {
V_63 . V_68 = 1 ;
continue;
}
if ( V_289 == - V_131 ) {
V_63 . V_68 = 1 ;
continue;
}
if ( F_78 ( V_14 , V_289 , & V_63 ) )
continue;
V_58 = F_44 ( F_20 ( V_14 ,
V_289 , & V_63 ) ) ;
} while ( V_63 . V_68 );
return V_58 ;
}
static int F_230 ( struct V_2 * V_2 , struct V_299 * V_333 ,
struct V_371 * V_372 , struct V_5 * V_6 ,
struct V_66 * V_67 , struct V_1 * V_373 ,
struct V_1 * V_362 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_374 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_376 = V_6 ,
. V_14 = V_14 ,
. V_231 = V_14 -> V_15 ,
. V_7 = V_373 ,
} ;
struct V_377 V_58 = {
. V_372 = V_372 ,
. V_7 = V_362 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_378 ] ,
. V_297 = & V_375 ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
unsigned long V_107 = V_155 ;
T_5 V_206 ;
bool V_379 ;
int V_289 ;
V_375 . V_231 = F_6 ( V_14 , V_373 ) ;
if ( V_373 )
V_375 . V_231 = F_6 ( V_14 , V_362 ) ;
F_81 ( V_372 ) ;
V_379 = ( V_6 -> V_236 & V_380 ) ? true : false ;
V_206 = V_379 ? V_218 : V_70 ;
if ( F_231 ( & V_375 . V_240 , V_2 , V_206 ) ) {
} else if ( V_379 && V_67 != NULL ) {
struct V_381 V_382 = {
. V_383 = V_59 -> V_384 ,
. V_385 = V_59 -> V_386 ,
} ;
if ( ! F_232 ( V_67 ) )
return - V_387 ;
if ( F_233 ( & V_375 . V_240 , V_67 , V_218 ,
& V_382 ) == - V_36 )
return - V_387 ;
} else
F_123 ( & V_375 . V_240 , & V_388 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_58 . V_161 , 1 ) ;
if ( V_289 == 0 && V_67 != NULL )
F_37 ( V_14 , V_107 ) ;
return V_289 ;
}
static int F_222 ( struct V_2 * V_2 , struct V_299 * V_333 ,
struct V_371 * V_372 , struct V_5 * V_6 ,
struct V_66 * V_67 , struct V_1 * V_373 ,
struct V_1 * V_362 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_62 V_63 = {
. V_67 = V_67 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_230 ( V_2 , V_333 , V_372 , V_6 , V_67 , V_373 , V_362 ) ;
F_234 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_69 :
if ( ! ( V_6 -> V_236 & V_380 ) ) {
F_235 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_64 -> V_98 ) ;
}
if ( V_67 && ! ( V_67 -> V_67 & V_218 ) ) {
V_8 = - V_387 ;
if ( V_6 -> V_236 & V_389 )
V_8 = - V_29 ;
goto V_132;
}
}
V_8 = F_20 ( V_14 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
V_132:
return V_8 ;
}
static void F_236 ( void * V_158 )
{
struct V_390 * V_156 = V_158 ;
struct V_204 * V_205 = V_156 -> V_67 -> V_215 ;
struct V_242 * V_243 = V_156 -> V_67 -> V_2 -> V_391 ;
if ( V_156 -> V_392 )
F_237 ( V_156 -> V_67 -> V_2 ) ;
F_101 ( V_156 -> V_67 ) ;
F_100 ( V_156 -> V_375 . V_196 ) ;
F_102 ( V_205 ) ;
F_103 ( V_243 ) ;
F_96 ( V_156 ) ;
}
static void F_238 ( struct V_117 * V_118 , void * V_158 )
{
struct V_390 * V_156 = V_158 ;
struct V_66 * V_67 = V_156 -> V_67 ;
struct V_13 * V_14 = F_85 ( V_156 -> V_2 ) ;
T_8 * V_393 = NULL ;
F_8 ( L_29 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_156 -> V_58 . V_161 ) )
return;
F_239 ( V_67 , & V_156 -> V_375 , & V_156 -> V_58 , V_118 -> V_150 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
V_393 = & V_156 -> V_58 . V_240 ;
if ( V_156 -> V_375 . V_206 == 0 && V_156 -> V_392 )
F_240 ( V_67 -> V_2 ,
V_156 -> V_394 ) ;
F_37 ( V_14 , V_156 -> V_107 ) ;
break;
case - V_73 :
case - V_76 :
case - V_94 :
case - V_74 :
case - V_75 :
if ( V_156 -> V_375 . V_206 == 0 )
break;
default:
if ( F_241 ( V_118 , V_14 , V_67 , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
goto V_395;
}
}
F_124 ( V_67 , V_393 , V_156 -> V_375 . V_206 ) ;
V_395:
F_138 ( V_156 -> V_375 . V_196 ) ;
F_145 ( V_156 -> V_2 , V_156 -> V_58 . V_372 ) ;
F_8 ( L_30 , V_35 , V_118 -> V_150 ) ;
}
static void F_242 ( struct V_117 * V_118 , void * V_158 )
{
struct V_390 * V_156 = V_158 ;
struct V_66 * V_67 = V_156 -> V_67 ;
struct V_2 * V_2 = V_156 -> V_2 ;
bool V_396 , V_397 , V_398 ;
int V_399 = 0 ;
F_8 ( L_29 , V_35 ) ;
if ( F_177 ( V_156 -> V_375 . V_196 , V_118 ) != 0 )
goto V_305;
V_118 -> V_309 . V_294 = & V_295 [ V_400 ] ;
F_34 ( & V_67 -> V_215 -> V_266 ) ;
V_398 = F_31 ( V_252 , & V_67 -> V_207 ) ;
V_396 = F_31 ( V_248 , & V_67 -> V_207 ) ;
V_397 = F_31 ( V_250 , & V_67 -> V_207 ) ;
V_156 -> V_375 . V_206 = 0 ;
if ( V_67 -> V_253 == 0 ) {
if ( V_67 -> V_249 == 0 )
V_399 |= V_396 ;
else if ( V_396 )
V_156 -> V_375 . V_206 |= V_70 ;
if ( V_67 -> V_251 == 0 )
V_399 |= V_397 ;
else if ( V_397 )
V_156 -> V_375 . V_206 |= V_218 ;
} else if ( V_398 )
V_156 -> V_375 . V_206 |= V_70 | V_218 ;
if ( V_156 -> V_375 . V_206 == 0 )
V_399 |= V_398 ;
if ( ! F_232 ( V_67 ) )
V_399 = 0 ;
F_36 ( & V_67 -> V_215 -> V_266 ) ;
if ( ! V_399 ) {
goto V_306;
}
if ( V_156 -> V_375 . V_206 == 0 ) {
V_118 -> V_309 . V_294 = & V_295 [ V_401 ] ;
if ( V_156 -> V_392 &&
F_243 ( V_2 , & V_156 -> V_394 , V_118 ) ) {
F_138 ( V_156 -> V_375 . V_196 ) ;
goto V_305;
}
}
F_81 ( V_156 -> V_58 . V_372 ) ;
V_156 -> V_107 = V_155 ;
if ( F_63 ( F_85 ( V_2 ) ,
& V_156 -> V_375 . V_160 ,
& V_156 -> V_58 . V_161 ,
V_118 ) != 0 )
F_138 ( V_156 -> V_375 . V_196 ) ;
F_8 ( L_31 , V_35 ) ;
return;
V_306:
V_118 -> V_317 = NULL ;
V_305:
F_60 ( V_118 , & V_156 -> V_58 . V_161 ) ;
}
static bool F_244 ( struct V_66 * V_67 )
{
if ( F_31 ( V_248 , & V_67 -> V_207 ) != 0 &&
V_67 -> V_249 != 0 )
return true ;
if ( F_31 ( V_250 , & V_67 -> V_207 ) != 0 &&
V_67 -> V_251 != 0 )
return true ;
if ( F_31 ( V_252 , & V_67 -> V_207 ) != 0 &&
V_67 -> V_253 != 0 )
return true ;
return false ;
}
static bool F_245 ( struct V_2 * V_2 )
{
struct V_173 * V_174 = F_75 ( V_2 ) ;
struct V_283 * V_284 ;
struct V_66 * V_67 ;
F_34 ( & V_2 -> V_175 ) ;
F_152 (ctx, &nfsi->open_files, list) {
V_67 = V_284 -> V_67 ;
if ( V_67 == NULL )
continue;
if ( F_244 ( V_67 ) ) {
F_36 ( & V_2 -> V_175 ) ;
return false ;
}
}
F_36 ( & V_2 -> V_175 ) ;
if ( F_246 ( V_2 , V_70 ) )
return false ;
return F_247 ( V_2 ) ;
}
int F_248 ( struct V_66 * V_67 , T_6 V_209 , int V_402 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
struct V_390 * V_156 ;
struct V_204 * V_205 = V_67 -> V_215 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_401 ] ,
. V_299 = V_67 -> V_215 -> V_274 ,
} ;
struct V_164 V_300 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_403 ,
. V_302 = V_303 ,
. V_207 = V_304 ,
} ;
int V_289 = - V_127 ;
F_249 ( V_14 -> V_64 , V_404 ,
& V_300 . V_166 , & V_163 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_209 ) ;
if ( V_156 == NULL )
goto V_132;
F_38 ( & V_156 -> V_375 . V_160 , & V_156 -> V_58 . V_161 , 1 ) ;
V_156 -> V_2 = V_67 -> V_2 ;
V_156 -> V_67 = V_67 ;
V_156 -> V_375 . V_234 = F_93 ( V_67 -> V_2 ) ;
V_156 -> V_375 . V_240 = & V_67 -> V_261 ;
V_156 -> V_375 . V_196 = F_88 ( & V_67 -> V_215 -> V_212 , V_209 ) ;
if ( V_156 -> V_375 . V_196 == NULL )
goto V_405;
V_156 -> V_375 . V_206 = 0 ;
V_156 -> V_375 . V_231 = V_14 -> V_406 ;
V_156 -> V_58 . V_372 = & V_156 -> V_372 ;
V_156 -> V_58 . V_196 = V_156 -> V_375 . V_196 ;
V_156 -> V_58 . V_14 = V_14 ;
V_156 -> V_392 = F_245 ( V_67 -> V_2 ) ;
F_89 ( V_156 -> V_2 -> V_391 ) ;
V_163 . V_297 = & V_156 -> V_375 ;
V_163 . V_298 = & V_156 -> V_58 ;
V_300 . V_170 = V_156 ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_289 = 0 ;
if ( V_402 )
V_289 = F_108 ( V_118 ) ;
F_72 ( V_118 ) ;
return V_289 ;
V_405:
F_96 ( V_156 ) ;
V_132:
F_101 ( V_67 ) ;
F_102 ( V_205 ) ;
return V_289 ;
}
static struct V_2 *
F_250 ( struct V_2 * V_3 , struct V_283 * V_284 ,
int V_217 , struct V_5 * V_407 , int * V_358 )
{
struct V_66 * V_67 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_284 -> V_4 , V_407 , & V_17 ) ;
V_67 = F_227 ( V_3 , V_284 , V_217 , V_407 , V_7 , V_358 ) ;
F_4 ( V_7 ) ;
if ( F_43 ( V_67 ) )
return F_251 ( V_67 ) ;
return V_67 -> V_2 ;
}
static void F_252 ( struct V_283 * V_284 , int V_408 )
{
if ( V_284 -> V_67 == NULL )
return;
if ( V_408 )
F_253 ( V_284 -> V_67 , V_284 -> V_245 ) ;
else
F_157 ( V_284 -> V_67 , V_284 -> V_245 ) ;
}
static int F_254 ( struct V_13 * V_14 , struct V_409 * V_410 )
{
struct V_411 args = {
. V_410 = V_410 ,
} ;
struct V_412 V_58 = {} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_413 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
int V_289 ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
if ( V_289 == 0 ) {
switch ( V_14 -> V_64 -> V_414 ) {
case 0 :
V_58 . V_15 [ 1 ] &= V_415 ;
V_58 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_58 . V_15 [ 2 ] &= V_416 ;
break;
case 2 :
V_58 . V_15 [ 2 ] &= V_417 ;
}
memcpy ( V_14 -> V_15 , V_58 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_95 &= ~ ( V_418 | V_419 |
V_420 | V_421 |
V_422 | V_423 | V_424 |
V_425 | V_426 |
V_427 | V_428 |
V_9 ) ;
if ( V_58 . V_15 [ 0 ] & V_429 &&
V_58 . V_430 & V_431 )
V_14 -> V_95 |= V_418 ;
if ( V_58 . V_432 != 0 )
V_14 -> V_95 |= V_419 ;
if ( V_58 . V_433 != 0 )
V_14 -> V_95 |= V_420 ;
if ( V_58 . V_15 [ 0 ] & V_46 )
V_14 -> V_95 |= V_421 ;
if ( V_58 . V_15 [ 1 ] & V_434 )
V_14 -> V_95 |= V_422 ;
if ( V_58 . V_15 [ 1 ] & V_435 )
V_14 -> V_95 |= V_423 ;
if ( V_58 . V_15 [ 1 ] & V_436 )
V_14 -> V_95 |= V_424 ;
if ( V_58 . V_15 [ 1 ] & V_437 )
V_14 -> V_95 |= V_425 ;
if ( V_58 . V_15 [ 1 ] & V_349 )
V_14 -> V_95 |= V_426 ;
if ( V_58 . V_15 [ 1 ] & V_438 )
V_14 -> V_95 |= V_427 ;
if ( V_58 . V_15 [ 1 ] & V_352 )
V_14 -> V_95 |= V_428 ;
#ifdef F_255
if ( V_58 . V_15 [ 2 ] & V_439 )
V_14 -> V_95 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_58 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_439 ;
memcpy ( V_14 -> V_406 , V_58 . V_15 , sizeof( V_14 -> V_406 ) ) ;
V_14 -> V_406 [ 0 ] &= V_440 | V_441 ;
V_14 -> V_406 [ 1 ] &= V_438 | V_352 ;
V_14 -> V_406 [ 2 ] = 0 ;
V_14 -> V_430 = V_58 . V_430 ;
V_14 -> V_442 = V_58 . V_442 ;
}
return V_289 ;
}
int F_256 ( struct V_13 * V_14 , struct V_409 * V_410 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_254 ( V_14 , V_410 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_257 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_444 )
{
T_1 V_231 [ 3 ] ;
struct V_445 args = {
. V_231 = V_231 ,
} ;
struct V_446 V_58 = {
. V_14 = V_14 ,
. V_372 = V_444 -> V_372 ,
. V_234 = V_410 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_447 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
V_231 [ 0 ] = V_233 [ 0 ] ;
V_231 [ 1 ] = V_233 [ 1 ] ;
V_231 [ 2 ] = V_233 [ 2 ] & ~ V_439 ;
F_81 ( V_444 -> V_372 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
}
static int F_258 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_444 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_257 ( V_14 , V_410 , V_444 ) ;
F_259 ( V_14 , V_410 , V_444 -> V_372 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_132;
default:
V_8 = F_20 ( V_14 , V_8 , & V_63 ) ;
}
} while ( V_63 . V_68 );
V_132:
return V_8 ;
}
static int F_260 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_444 , T_4 V_101 )
{
struct V_448 V_449 = {
. V_450 = V_101 ,
} ;
struct V_451 * V_452 ;
int V_53 ;
V_452 = F_261 ( & V_449 , V_14 -> V_92 ) ;
if ( F_43 ( V_452 ) ) {
V_53 = - V_29 ;
goto V_132;
}
V_53 = F_258 ( V_14 , V_410 , V_444 ) ;
V_132:
return V_53 ;
}
static int F_262 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_444 )
{
static const T_4 V_453 [] = {
V_106 ,
V_105 ,
V_454 ,
V_455 ,
V_456 ,
} ;
int V_289 = - V_24 ;
T_9 V_457 ;
if ( V_14 -> V_458 . V_459 > 0 ) {
for ( V_457 = 0 ; V_457 < V_14 -> V_458 . V_459 ; V_457 ++ ) {
V_289 = F_260 ( V_14 , V_410 , V_444 ,
V_14 -> V_458 . V_460 [ V_457 ] ) ;
if ( V_289 == - V_22 || V_289 == - V_29 )
continue;
break;
}
} else {
for ( V_457 = 0 ; V_457 < F_263 ( V_453 ) ; V_457 ++ ) {
V_289 = F_260 ( V_14 , V_410 , V_444 ,
V_453 [ V_457 ] ) ;
if ( V_289 == - V_22 || V_289 == - V_29 )
continue;
break;
}
}
if ( V_289 == - V_29 )
V_289 = - V_24 ;
return V_289 ;
}
static int F_264 ( struct V_13 * V_14 ,
struct V_409 * V_410 , struct V_443 * V_444 )
{
int V_461 = V_14 -> V_64 -> V_414 ;
return V_462 [ V_461 ] -> F_265 ( V_14 , V_410 , V_444 ) ;
}
int F_266 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_444 ,
bool V_463 )
{
int V_289 ;
switch ( V_463 ) {
case false :
V_289 = F_258 ( V_14 , V_410 , V_444 ) ;
if ( V_289 != - V_22 )
break;
default:
V_289 = F_264 ( V_14 , V_410 , V_444 ) ;
}
if ( V_289 == 0 )
V_289 = F_256 ( V_14 , V_410 ) ;
if ( V_289 == 0 )
V_289 = F_267 ( V_14 , V_410 , V_444 ) ;
return F_7 ( V_289 ) ;
}
static int F_268 ( struct V_13 * V_14 , struct V_409 * V_464 ,
struct V_443 * V_444 )
{
int error ;
struct V_371 * V_372 = V_444 -> V_372 ;
struct V_1 * V_7 = NULL ;
error = F_256 ( V_14 , V_464 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_87 ( V_14 , V_363 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
error = F_188 ( V_14 , V_464 , V_372 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_213;
}
if ( V_372 -> V_280 & V_465 &&
! F_269 ( & V_14 -> V_466 , & V_372 -> V_466 ) )
memcpy ( & V_14 -> V_466 , & V_372 -> V_466 , sizeof( V_14 -> V_466 ) ) ;
V_213:
F_95 ( V_7 ) ;
return error ;
}
static int F_270 ( struct V_56 * V_92 , struct V_2 * V_3 ,
const struct V_467 * V_230 , struct V_371 * V_372 ,
struct V_409 * V_410 )
{
int V_289 = - V_127 ;
struct V_468 * V_468 = NULL ;
struct V_469 * V_470 = NULL ;
V_468 = F_271 ( V_363 ) ;
if ( V_468 == NULL )
goto V_132;
V_470 = F_272 ( sizeof( struct V_469 ) , V_363 ) ;
if ( V_470 == NULL )
goto V_132;
V_289 = F_273 ( V_92 , V_3 , V_230 , V_470 , V_468 ) ;
if ( V_289 != 0 )
goto V_132;
if ( F_269 ( & F_85 ( V_3 ) -> V_466 , & V_470 -> V_372 . V_466 ) ) {
F_8 ( L_34
L_35 , V_35 , V_230 -> V_230 ) ;
V_289 = - V_78 ;
goto V_132;
}
F_274 ( & V_470 -> V_372 ) ;
memcpy ( V_372 , & V_470 -> V_372 , sizeof( struct V_371 ) ) ;
memset ( V_410 , 0 , sizeof( struct V_409 ) ) ;
V_132:
if ( V_468 )
F_275 ( V_468 ) ;
F_96 ( V_470 ) ;
return V_289 ;
}
static int F_276 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_371 * V_372 , struct V_1 * V_7 )
{
struct V_471 args = {
. V_234 = V_410 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_472 V_58 = {
. V_372 = V_372 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_473 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
args . V_231 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_372 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
}
static int F_188 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_371 * V_372 , struct V_1 * V_7 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_276 ( V_14 , V_410 , V_372 , V_7 ) ;
F_277 ( V_14 , V_410 , V_372 , V_8 ) ;
V_8 = F_20 ( V_14 , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int
F_278 ( struct V_4 * V_4 , struct V_371 * V_372 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = V_4 -> V_47 ;
struct V_299 * V_333 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_1 * V_7 = NULL ;
int V_289 ;
if ( F_279 ( V_2 ) &&
V_6 -> V_236 & V_380 &&
V_6 -> V_474 < F_280 ( V_2 ) )
F_281 ( V_2 ) ;
F_81 ( V_372 ) ;
if ( V_6 -> V_236 & V_389 )
V_6 -> V_236 &= ~ ( V_354 | V_475 ) ;
if ( ( V_6 -> V_236 & ~ ( V_476 | V_389 ) ) == 0 )
return 0 ;
if ( V_6 -> V_236 & V_476 ) {
struct V_283 * V_284 ;
V_284 = F_282 ( V_6 -> V_477 ) ;
if ( V_284 ) {
V_333 = V_284 -> V_333 ;
V_67 = V_284 -> V_67 ;
}
}
V_7 = F_87 ( F_85 ( V_2 ) , V_363 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
V_289 = F_222 ( V_2 , V_333 , V_372 , V_6 , V_67 , NULL , V_7 ) ;
if ( V_289 == 0 ) {
F_223 ( V_2 , V_6 ) ;
F_225 ( V_2 , V_372 , V_7 ) ;
}
F_95 ( V_7 ) ;
return V_289 ;
}
static int F_283 ( struct V_56 * V_57 , struct V_2 * V_3 ,
const struct V_467 * V_230 , struct V_409 * V_410 ,
struct V_371 * V_372 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
int V_289 ;
struct V_478 args = {
. V_231 = V_14 -> V_15 ,
. V_479 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
} ;
struct V_446 V_58 = {
. V_14 = V_14 ,
. V_372 = V_372 ,
. V_7 = V_7 ,
. V_234 = V_410 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_480 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
args . V_231 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_372 ) ;
F_8 ( L_36 , V_230 -> V_230 ) ;
V_289 = F_73 ( V_57 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
F_8 ( L_37 , V_289 ) ;
return V_289 ;
}
static void F_284 ( struct V_371 * V_372 )
{
V_372 -> V_280 |= V_318 | V_481 |
V_482 | V_483 ;
V_372 -> V_245 = V_323 | V_484 | V_485 ;
V_372 -> V_486 = 2 ;
}
static int F_285 ( struct V_56 * * V_57 , struct V_2 * V_3 ,
struct V_467 * V_230 , struct V_409 * V_410 ,
struct V_371 * V_372 , struct V_1 * V_7 )
{
struct V_62 V_63 = { } ;
struct V_56 * V_92 = * V_57 ;
int V_8 ;
do {
V_8 = F_283 ( V_92 , V_3 , V_230 , V_410 , V_372 , V_7 ) ;
F_286 ( V_3 , V_230 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_285 ;
goto V_132;
case - V_78 :
V_8 = F_270 ( V_92 , V_3 , V_230 , V_372 , V_410 ) ;
goto V_132;
case - V_22 :
V_8 = - V_24 ;
if ( V_92 != * V_57 )
goto V_132;
V_92 = F_287 ( V_92 , V_3 , V_230 ) ;
if ( F_43 ( V_92 ) )
return F_71 ( V_92 ) ;
V_63 . V_68 = 1 ;
break;
default:
V_8 = F_20 ( F_85 ( V_3 ) , V_8 , & V_63 ) ;
}
} while ( V_63 . V_68 );
V_132:
if ( V_8 == 0 )
* V_57 = V_92 ;
else if ( V_92 != * V_57 )
F_288 ( V_92 ) ;
return V_8 ;
}
static int F_289 ( struct V_2 * V_3 , struct V_467 * V_230 ,
struct V_409 * V_410 , struct V_371 * V_372 ,
struct V_1 * V_7 )
{
int V_289 ;
struct V_56 * V_92 = F_290 ( V_3 ) ;
V_289 = F_285 ( & V_92 , V_3 , V_230 , V_410 , V_372 , V_7 ) ;
if ( V_92 != F_290 ( V_3 ) ) {
F_288 ( V_92 ) ;
F_284 ( V_372 ) ;
}
return V_289 ;
}
struct V_56 *
F_291 ( struct V_2 * V_3 , struct V_467 * V_230 ,
struct V_409 * V_410 , struct V_371 * V_372 )
{
struct V_56 * V_92 = F_290 ( V_3 ) ;
int V_289 ;
V_289 = F_285 ( & V_92 , V_3 , V_230 , V_410 , V_372 , NULL ) ;
if ( V_289 < 0 )
return F_44 ( V_289 ) ;
return ( V_92 == F_290 ( V_3 ) ) ? F_292 ( V_92 ) : V_92 ;
}
static int F_293 ( struct V_2 * V_2 , struct V_335 * V_487 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_488 args = {
. V_234 = F_93 ( V_2 ) ,
. V_231 = V_14 -> V_406 ,
} ;
struct V_489 V_58 = {
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_490 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_487 -> V_333 ,
} ;
int V_245 = V_487 -> V_337 ;
int V_289 = 0 ;
if ( V_245 & V_342 )
args . V_201 |= V_220 ;
if ( F_294 ( V_2 -> V_491 ) ) {
if ( V_245 & V_492 )
args . V_201 |= V_221 | V_222 | V_493 ;
if ( V_245 & V_340 )
args . V_201 |= V_494 ;
} else {
if ( V_245 & V_492 )
args . V_201 |= V_221 | V_222 ;
if ( V_245 & V_340 )
args . V_201 |= V_223 ;
}
V_58 . V_372 = F_295 () ;
if ( V_58 . V_372 == NULL )
return - V_127 ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
if ( ! V_289 ) {
F_185 ( V_487 , V_58 . V_201 ) ;
F_145 ( V_2 , V_58 . V_372 ) ;
}
F_296 ( V_58 . V_372 ) ;
return V_289 ;
}
static int F_297 ( struct V_2 * V_2 , struct V_335 * V_487 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_293 ( V_2 , V_487 ) ;
F_298 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_299 ( struct V_2 * V_2 , struct V_468 * V_468 ,
unsigned int V_50 , unsigned int V_495 )
{
struct V_496 args = {
. V_234 = F_93 ( V_2 ) ,
. V_50 = V_50 ,
. V_495 = V_495 ,
. V_43 = & V_468 ,
} ;
struct V_497 V_58 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_498 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
return F_73 ( F_85 ( V_2 ) -> V_92 , F_85 ( V_2 ) , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
}
static int F_300 ( struct V_2 * V_2 , struct V_468 * V_468 ,
unsigned int V_50 , unsigned int V_495 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_299 ( V_2 , V_468 , V_50 , V_495 ) ;
F_301 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int
F_302 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_207 )
{
struct V_1 V_17 , * V_373 = NULL ;
struct V_283 * V_284 ;
struct V_66 * V_67 ;
int V_358 = 0 ;
int V_289 = 0 ;
V_284 = F_303 ( V_4 , V_70 ) ;
if ( F_43 ( V_284 ) )
return F_71 ( V_284 ) ;
V_373 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_304 () ;
V_67 = F_227 ( V_3 , V_284 , V_207 , V_6 , V_373 , & V_358 ) ;
if ( F_43 ( V_67 ) ) {
V_289 = F_71 ( V_67 ) ;
goto V_132;
}
V_132:
F_4 ( V_373 ) ;
F_164 ( V_284 ) ;
return V_289 ;
}
static int F_305 ( struct V_2 * V_3 , struct V_467 * V_230 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_499 args = {
. V_234 = F_93 ( V_3 ) ,
. V_230 = * V_230 ,
} ;
struct V_500 V_58 = {
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_501 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
int V_289 ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 1 ) ;
if ( V_289 == 0 )
F_74 ( V_3 , & V_58 . V_172 ) ;
return V_289 ;
}
static int F_306 ( struct V_2 * V_3 , struct V_467 * V_230 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_305 ( V_3 , V_230 ) ;
F_307 ( V_3 , V_230 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static void F_308 ( struct V_162 * V_163 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_499 * args = V_163 -> V_297 ;
struct V_500 * V_58 = V_163 -> V_298 ;
V_58 -> V_14 = V_14 ;
V_163 -> V_294 = & V_295 [ V_501 ] ;
F_38 ( & args -> V_160 , & V_58 -> V_161 , 1 ) ;
F_81 ( V_58 -> V_502 ) ;
}
static void F_309 ( struct V_117 * V_118 , struct V_503 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_3 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_58 . V_161 ,
V_118 ) ;
}
static int F_310 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_503 * V_158 = V_118 -> V_504 ;
struct V_500 * V_58 = & V_158 -> V_58 ;
if ( ! F_60 ( V_118 , & V_58 -> V_161 ) )
return 0 ;
if ( F_241 ( V_118 , V_58 -> V_14 , NULL ,
& V_158 -> V_52 ) == - V_131 )
return 0 ;
F_74 ( V_3 , & V_58 -> V_172 ) ;
return 1 ;
}
static void F_311 ( struct V_162 * V_163 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_505 * V_375 = V_163 -> V_297 ;
struct V_506 * V_58 = V_163 -> V_298 ;
V_163 -> V_294 = & V_295 [ V_507 ] ;
V_58 -> V_14 = V_14 ;
F_38 ( & V_375 -> V_160 , & V_58 -> V_161 , 1 ) ;
}
static void F_312 ( struct V_117 * V_118 , struct V_508 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_509 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_58 . V_161 ,
V_118 ) ;
}
static int F_313 ( struct V_117 * V_118 , struct V_2 * V_509 ,
struct V_2 * V_510 )
{
struct V_508 * V_158 = V_118 -> V_504 ;
struct V_506 * V_58 = & V_158 -> V_58 ;
if ( ! F_60 ( V_118 , & V_58 -> V_161 ) )
return 0 ;
if ( F_241 ( V_118 , V_58 -> V_14 , NULL , & V_158 -> V_52 ) == - V_131 )
return 0 ;
F_74 ( V_509 , & V_58 -> V_511 ) ;
F_74 ( V_510 , & V_58 -> V_512 ) ;
return 1 ;
}
static int F_314 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_467 * V_230 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_513 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_479 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_514 V_58 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_515 ] ,
. V_297 = & V_375 ,
. V_298 = & V_58 ,
} ;
int V_289 = - V_127 ;
V_58 . V_372 = F_295 () ;
if ( V_58 . V_372 == NULL )
goto V_132;
V_58 . V_7 = F_87 ( V_14 , V_363 ) ;
if ( F_43 ( V_58 . V_7 ) ) {
V_289 = F_71 ( V_58 . V_7 ) ;
goto V_132;
}
V_375 . V_231 = F_6 ( V_14 , V_58 . V_7 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_58 . V_161 , 1 ) ;
if ( ! V_289 ) {
F_74 ( V_3 , & V_58 . V_172 ) ;
V_289 = F_224 ( V_2 , V_58 . V_372 ) ;
if ( ! V_289 )
F_225 ( V_2 , V_58 . V_372 , V_58 . V_7 ) ;
}
F_95 ( V_58 . V_7 ) ;
V_132:
F_296 ( V_58 . V_372 ) ;
return V_289 ;
}
static int F_315 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_467 * V_230 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_85 ( V_2 ) ,
F_314 ( V_2 , V_3 , V_230 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static struct V_516 * F_316 ( struct V_2 * V_3 ,
struct V_467 * V_230 , struct V_5 * V_6 , T_1 V_517 )
{
struct V_516 * V_158 ;
V_158 = F_86 ( sizeof( * V_158 ) , V_363 ) ;
if ( V_158 != NULL ) {
struct V_13 * V_14 = F_85 ( V_3 ) ;
V_158 -> V_7 = F_87 ( V_14 , V_363 ) ;
if ( F_43 ( V_158 -> V_7 ) )
goto V_293;
V_158 -> V_163 . V_294 = & V_295 [ V_518 ] ;
V_158 -> V_163 . V_297 = & V_158 -> V_375 ;
V_158 -> V_163 . V_298 = & V_158 -> V_58 ;
V_158 -> V_375 . V_479 = F_93 ( V_3 ) ;
V_158 -> V_375 . V_14 = V_14 ;
V_158 -> V_375 . V_230 = V_230 ;
V_158 -> V_375 . V_208 = V_6 ;
V_158 -> V_375 . V_517 = V_517 ;
V_158 -> V_375 . V_231 = F_6 ( V_14 , V_158 -> V_7 ) ;
V_158 -> V_58 . V_14 = V_14 ;
V_158 -> V_58 . V_234 = & V_158 -> V_234 ;
V_158 -> V_58 . V_372 = & V_158 -> V_372 ;
V_158 -> V_58 . V_7 = V_158 -> V_7 ;
F_81 ( V_158 -> V_58 . V_372 ) ;
}
return V_158 ;
V_293:
F_96 ( V_158 ) ;
return NULL ;
}
static int F_317 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_516 * V_158 )
{
int V_289 = F_73 ( F_85 ( V_3 ) -> V_92 , F_85 ( V_3 ) , & V_158 -> V_163 ,
& V_158 -> V_375 . V_160 , & V_158 -> V_58 . V_161 , 1 ) ;
if ( V_289 == 0 ) {
F_74 ( V_3 , & V_158 -> V_58 . V_519 ) ;
V_289 = F_318 ( V_4 , V_158 -> V_58 . V_234 , V_158 -> V_58 . V_372 , V_158 -> V_58 . V_7 ) ;
}
return V_289 ;
}
static void F_319 ( struct V_516 * V_158 )
{
F_95 ( V_158 -> V_7 ) ;
F_96 ( V_158 ) ;
}
static int F_320 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_468 * V_468 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_516 * V_158 ;
int V_289 = - V_520 ;
if ( V_12 > V_521 )
goto V_132;
V_289 = - V_127 ;
V_158 = F_316 ( V_3 , & V_4 -> V_11 , V_6 , V_522 ) ;
if ( V_158 == NULL )
goto V_132;
V_158 -> V_163 . V_294 = & V_295 [ V_523 ] ;
V_158 -> V_375 . V_238 . V_524 . V_43 = & V_468 ;
V_158 -> V_375 . V_238 . V_524 . V_12 = V_12 ;
V_158 -> V_375 . V_7 = V_7 ;
V_289 = F_317 ( V_3 , V_4 , V_158 ) ;
F_319 ( V_158 ) ;
V_132:
return V_289 ;
}
static int F_321 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_468 * V_468 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_62 V_63 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_320 ( V_3 , V_4 , V_468 , V_12 , V_6 , V_7 ) ;
F_322 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_323 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_516 * V_158 ;
int V_289 = - V_127 ;
V_158 = F_316 ( V_3 , & V_4 -> V_11 , V_6 , V_525 ) ;
if ( V_158 == NULL )
goto V_132;
V_158 -> V_375 . V_7 = V_7 ;
V_289 = F_317 ( V_3 , V_4 , V_158 ) ;
F_319 ( V_158 ) ;
V_132:
return V_289 ;
}
static int F_324 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_62 V_63 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_304 () ;
do {
V_8 = F_323 ( V_3 , V_4 , V_6 , V_7 ) ;
F_325 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_326 ( struct V_4 * V_4 , struct V_299 * V_333 ,
T_2 V_37 , struct V_468 * * V_43 , unsigned int V_51 , int V_526 )
{
struct V_2 * V_3 = V_4 -> V_47 ;
struct V_39 args = {
. V_234 = F_93 ( V_3 ) ,
. V_43 = V_43 ,
. V_50 = 0 ,
. V_51 = V_51 ,
. V_231 = F_85 ( V_4 -> V_47 ) -> V_15 ,
. V_526 = V_526 ,
} ;
struct V_527 V_58 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_528 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_8 ( L_38 , V_35 ,
V_4 ,
( unsigned long long ) V_37 ) ;
F_9 ( V_37 , F_75 ( V_3 ) -> V_529 , V_4 , & args ) ;
V_58 . V_50 = args . V_50 ;
V_289 = F_73 ( F_85 ( V_3 ) -> V_92 , F_85 ( V_3 ) , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
if ( V_289 >= 0 ) {
memcpy ( F_75 ( V_3 ) -> V_529 , V_58 . V_38 . V_158 , V_530 ) ;
V_289 += args . V_50 ;
}
F_327 ( V_3 ) ;
F_8 ( L_39 , V_35 , V_289 ) ;
return V_289 ;
}
static int F_328 ( struct V_4 * V_4 , struct V_299 * V_333 ,
T_2 V_37 , struct V_468 * * V_43 , unsigned int V_51 , int V_526 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_326 ( V_4 , V_333 , V_37 ,
V_43 , V_51 , V_526 ) ;
F_329 ( V_4 -> V_47 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_4 -> V_47 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_330 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_531 )
{
struct V_516 * V_158 ;
int V_245 = V_6 -> V_10 ;
int V_289 = - V_127 ;
V_158 = F_316 ( V_3 , & V_4 -> V_11 , V_6 , V_532 ) ;
if ( V_158 == NULL )
goto V_132;
if ( F_331 ( V_245 ) )
V_158 -> V_375 . V_517 = V_533 ;
else if ( F_332 ( V_245 ) ) {
V_158 -> V_375 . V_517 = V_534 ;
V_158 -> V_375 . V_238 . V_535 . V_536 = F_333 ( V_531 ) ;
V_158 -> V_375 . V_238 . V_535 . V_537 = F_334 ( V_531 ) ;
}
else if ( F_335 ( V_245 ) ) {
V_158 -> V_375 . V_517 = V_538 ;
V_158 -> V_375 . V_238 . V_535 . V_536 = F_333 ( V_531 ) ;
V_158 -> V_375 . V_238 . V_535 . V_537 = F_334 ( V_531 ) ;
} else if ( ! F_336 ( V_245 ) ) {
V_289 = - V_27 ;
goto V_293;
}
V_158 -> V_375 . V_7 = V_7 ;
V_289 = F_317 ( V_3 , V_4 , V_158 ) ;
V_293:
F_319 ( V_158 ) ;
V_132:
return V_289 ;
}
static int F_337 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_531 )
{
struct V_62 V_63 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_304 () ;
do {
V_8 = F_330 ( V_3 , V_4 , V_6 , V_7 , V_531 ) ;
F_338 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_339 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_539 * V_540 )
{
struct V_541 args = {
. V_234 = V_410 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_542 V_58 = {
. V_540 = V_540 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_543 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
F_81 ( V_540 -> V_372 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
}
static int F_340 ( struct V_13 * V_14 , struct V_409 * V_410 , struct V_539 * V_540 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_339 ( V_14 , V_410 , V_540 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_341 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_544 )
{
struct V_545 args = {
. V_234 = V_410 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_546 V_58 = {
. V_544 = V_544 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_547 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
}
static int F_267 ( struct V_13 * V_14 , struct V_409 * V_410 , struct V_443 * V_544 )
{
struct V_62 V_63 = { } ;
unsigned long V_548 = V_155 ;
int V_8 ;
do {
V_8 = F_341 ( V_14 , V_410 , V_544 ) ;
F_342 ( V_14 , V_410 , V_544 -> V_372 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_64 * V_65 = V_14 -> V_64 ;
F_34 ( & V_65 -> V_108 ) ;
V_65 -> V_549 = V_544 -> V_550 * V_89 ;
V_65 -> V_109 = V_548 ;
F_36 ( & V_65 -> V_108 ) ;
break;
}
V_8 = F_20 ( V_14 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_343 ( struct V_13 * V_14 , struct V_409 * V_410 , struct V_443 * V_544 )
{
int error ;
F_81 ( V_544 -> V_372 ) ;
error = F_267 ( V_14 , V_410 , V_544 ) ;
if ( error == 0 ) {
V_14 -> V_551 = V_544 -> V_552 ;
F_344 ( V_14 , V_410 , V_544 -> V_553 ) ;
}
return error ;
}
static int F_345 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_554 * V_555 )
{
struct V_556 args = {
. V_234 = V_410 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_557 V_58 = {
. V_555 = V_555 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_558 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
if ( ( args . V_231 [ 0 ] & V_559 [ 0 ] ) == 0 ) {
memset ( V_555 , 0 , sizeof( * V_555 ) ) ;
return 0 ;
}
F_81 ( V_555 -> V_372 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
}
static int F_346 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_554 * V_555 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_345 ( V_14 , V_410 , V_555 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
int F_347 ( T_8 * V_240 ,
const struct V_283 * V_284 ,
const struct V_560 * V_561 ,
T_5 V_206 )
{
const struct V_381 * V_382 = NULL ;
if ( V_561 != NULL )
V_382 = & V_561 -> V_382 ;
return F_233 ( V_240 , V_284 -> V_67 , V_206 , V_382 ) ;
}
static bool F_348 ( T_8 * V_240 ,
const struct V_283 * V_284 ,
const struct V_560 * V_561 ,
T_5 V_206 )
{
T_8 V_562 ;
if ( F_347 ( & V_562 , V_284 , V_561 , V_206 ) == - V_36 )
return true ;
return F_134 ( V_240 , & V_562 ) ;
}
static bool F_349 ( int V_8 )
{
switch ( V_8 ) {
case - V_72 :
case - V_73 :
case - V_74 :
case - V_76 :
case - V_94 :
case - V_69 :
case - V_75 :
return true ;
}
return false ;
}
void F_350 ( struct V_563 * V_564 )
{
F_327 ( V_564 -> V_2 ) ;
}
static int F_351 ( struct V_117 * V_118 , struct V_563 * V_564 )
{
struct V_13 * V_14 = F_85 ( V_564 -> V_2 ) ;
F_352 ( V_564 , V_118 -> V_150 ) ;
if ( F_241 ( V_118 , V_14 ,
V_564 -> args . V_565 -> V_67 ,
NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
F_350 ( V_564 ) ;
if ( V_118 -> V_150 > 0 )
F_37 ( V_14 , V_564 -> V_107 ) ;
return 0 ;
}
static bool F_353 ( struct V_117 * V_118 ,
struct V_566 * args )
{
if ( ! F_349 ( V_118 -> V_150 ) ||
F_348 ( & args -> V_240 ,
args -> V_565 ,
args -> V_567 ,
V_70 ) )
return false ;
F_57 ( V_118 ) ;
return true ;
}
static int F_354 ( struct V_117 * V_118 , struct V_563 * V_564 )
{
F_8 ( L_11 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_564 -> V_58 . V_161 ) )
return - V_131 ;
if ( F_353 ( V_118 , & V_564 -> args ) )
return - V_131 ;
return V_564 -> V_568 ? V_564 -> V_568 ( V_118 , V_564 ) :
F_351 ( V_118 , V_564 ) ;
}
static void F_355 ( struct V_563 * V_564 ,
struct V_162 * V_163 )
{
V_564 -> V_107 = V_155 ;
V_564 -> V_568 = F_351 ;
V_163 -> V_294 = & V_295 [ V_569 ] ;
F_38 ( & V_564 -> args . V_160 , & V_564 -> V_58 . V_161 , 0 ) ;
}
static int F_356 ( struct V_117 * V_118 ,
struct V_563 * V_564 )
{
if ( F_63 ( F_85 ( V_564 -> V_2 ) ,
& V_564 -> args . V_160 ,
& V_564 -> V_58 . V_161 ,
V_118 ) )
return 0 ;
if ( F_347 ( & V_564 -> args . V_240 , V_564 -> args . V_565 ,
V_564 -> args . V_567 ,
V_564 -> V_570 -> V_571 ) == - V_36 )
return - V_36 ;
if ( F_357 ( F_31 ( V_572 , & V_564 -> args . V_565 -> V_207 ) ) )
return - V_36 ;
return 0 ;
}
static int F_358 ( struct V_117 * V_118 ,
struct V_563 * V_564 )
{
struct V_2 * V_2 = V_564 -> V_2 ;
F_359 ( V_564 , V_118 -> V_150 ) ;
if ( F_241 ( V_118 , F_85 ( V_2 ) ,
V_564 -> args . V_565 -> V_67 ,
NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
if ( V_118 -> V_150 >= 0 ) {
F_37 ( F_85 ( V_2 ) , V_564 -> V_107 ) ;
F_360 ( V_2 , & V_564 -> V_372 ) ;
}
return 0 ;
}
static bool F_361 ( struct V_117 * V_118 ,
struct V_566 * args )
{
if ( ! F_349 ( V_118 -> V_150 ) ||
F_348 ( & args -> V_240 ,
args -> V_565 ,
args -> V_567 ,
V_218 ) )
return false ;
F_57 ( V_118 ) ;
return true ;
}
static int F_362 ( struct V_117 * V_118 , struct V_563 * V_564 )
{
if ( ! F_60 ( V_118 , & V_564 -> V_58 . V_161 ) )
return - V_131 ;
if ( F_361 ( V_118 , & V_564 -> args ) )
return - V_131 ;
return V_564 -> V_568 ? V_564 -> V_568 ( V_118 , V_564 ) :
F_358 ( V_118 , V_564 ) ;
}
static
bool F_363 ( struct V_563 * V_564 )
{
if ( V_564 -> V_573 != NULL || V_564 -> V_574 != NULL )
return false ;
return F_21 ( V_564 -> V_2 , V_70 ) == 0 ;
}
static void F_364 ( struct V_563 * V_564 ,
struct V_162 * V_163 )
{
struct V_13 * V_14 = F_85 ( V_564 -> V_2 ) ;
if ( ! F_363 ( V_564 ) ) {
V_564 -> args . V_231 = NULL ;
V_564 -> V_58 . V_372 = NULL ;
} else
V_564 -> args . V_231 = V_14 -> V_406 ;
if ( ! V_564 -> V_568 )
V_564 -> V_568 = F_358 ;
V_564 -> V_58 . V_14 = V_14 ;
V_564 -> V_107 = V_155 ;
V_163 -> V_294 = & V_295 [ V_575 ] ;
F_38 ( & V_564 -> args . V_160 , & V_564 -> V_58 . V_161 , 1 ) ;
}
static void F_365 ( struct V_117 * V_118 , struct V_576 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_2 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_58 . V_161 ,
V_118 ) ;
}
static int F_366 ( struct V_117 * V_118 , struct V_576 * V_158 )
{
struct V_2 * V_2 = V_158 -> V_2 ;
F_367 ( V_158 , V_118 -> V_150 ) ;
if ( F_241 ( V_118 , F_85 ( V_2 ) ,
NULL , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_368 ( struct V_117 * V_118 , struct V_576 * V_158 )
{
if ( ! F_60 ( V_118 , & V_158 -> V_58 . V_161 ) )
return - V_131 ;
return V_158 -> V_577 ( V_118 , V_158 ) ;
}
static void F_369 ( struct V_576 * V_158 , struct V_162 * V_163 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_2 ) ;
if ( V_158 -> V_577 == NULL )
V_158 -> V_577 = F_366 ;
V_158 -> V_58 . V_14 = V_14 ;
V_163 -> V_294 = & V_295 [ V_578 ] ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_58 . V_161 , 1 ) ;
}
static void F_370 ( void * V_156 )
{
struct V_579 * V_158 = V_156 ;
struct V_64 * V_65 = V_158 -> V_92 ;
if ( F_371 ( & V_65 -> V_580 ) > 1 )
F_372 ( V_65 ) ;
F_373 ( V_65 ) ;
F_96 ( V_158 ) ;
}
static void F_374 ( struct V_117 * V_118 , void * V_156 )
{
struct V_579 * V_158 = V_156 ;
struct V_64 * V_65 = V_158 -> V_92 ;
unsigned long V_107 = V_158 -> V_107 ;
F_375 ( V_65 , V_118 -> V_150 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
break;
case - V_79 :
F_26 ( V_65 ) ;
break;
default:
if ( F_31 ( V_581 , & V_65 -> V_582 ) == 0 )
return;
if ( V_118 -> V_150 != V_583 ) {
F_24 ( V_65 ) ;
return;
}
F_376 ( V_65 ) ;
}
F_33 ( V_65 , V_107 ) ;
}
static int F_377 ( struct V_64 * V_65 , struct V_299 * V_333 , unsigned V_584 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_585 ] ,
. V_297 = V_65 ,
. V_299 = V_333 ,
} ;
struct V_579 * V_158 ;
if ( V_584 == 0 )
return 0 ;
if ( ! F_378 ( & V_65 -> V_580 ) )
return - V_36 ;
V_158 = F_272 ( sizeof( * V_158 ) , V_286 ) ;
if ( V_158 == NULL )
return - V_127 ;
V_158 -> V_92 = V_65 ;
V_158 -> V_107 = V_155 ;
return F_379 ( V_65 -> V_102 , & V_163 , V_586 ,
& V_587 , V_158 ) ;
}
static int F_380 ( struct V_64 * V_65 , struct V_299 * V_333 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_585 ] ,
. V_297 = V_65 ,
. V_299 = V_333 ,
} ;
unsigned long V_548 = V_155 ;
int V_289 ;
V_289 = F_381 ( V_65 -> V_102 , & V_163 , V_586 ) ;
if ( V_289 < 0 )
return V_289 ;
F_33 ( V_65 , V_548 ) ;
return 0 ;
}
static inline int F_382 ( struct V_13 * V_14 )
{
return V_14 -> V_95 & V_418 ;
}
static int F_383 ( const void * V_588 , T_9 V_589 ,
struct V_468 * * V_43 , unsigned int * V_50 )
{
struct V_468 * V_590 , * * V_591 ;
int V_592 = 0 ;
T_9 V_12 ;
V_591 = V_43 ;
do {
V_12 = F_384 ( T_9 , V_593 , V_589 ) ;
V_590 = F_271 ( V_363 ) ;
if ( V_590 == NULL )
goto V_594;
memcpy ( F_385 ( V_590 ) , V_588 , V_12 ) ;
V_588 += V_12 ;
V_589 -= V_12 ;
* V_43 ++ = V_590 ;
V_592 ++ ;
} while ( V_589 != 0 );
return V_592 ;
V_594:
for(; V_592 > 0 ; V_592 -- )
F_275 ( V_591 [ V_592 - 1 ] ) ;
return - V_127 ;
}
static void F_386 ( struct V_2 * V_2 , struct V_595 * V_596 )
{
struct V_173 * V_174 = F_75 ( V_2 ) ;
F_34 ( & V_2 -> V_175 ) ;
F_96 ( V_174 -> V_597 ) ;
V_174 -> V_597 = V_596 ;
F_36 ( & V_2 -> V_175 ) ;
}
static void F_387 ( struct V_2 * V_2 )
{
F_386 ( V_2 , NULL ) ;
}
static inline T_11 F_388 ( struct V_2 * V_2 , char * V_588 , T_9 V_589 )
{
struct V_173 * V_174 = F_75 ( V_2 ) ;
struct V_595 * V_596 ;
int V_53 = - V_285 ;
F_34 ( & V_2 -> V_175 ) ;
V_596 = V_174 -> V_597 ;
if ( V_596 == NULL )
goto V_132;
if ( V_588 == NULL )
goto V_598;
if ( V_596 -> V_599 == 0 )
goto V_132;
V_53 = - V_600 ;
if ( V_596 -> V_12 > V_589 )
goto V_132;
memcpy ( V_588 , V_596 -> V_158 , V_596 -> V_12 ) ;
V_598:
V_53 = V_596 -> V_12 ;
V_132:
F_36 ( & V_2 -> V_175 ) ;
return V_53 ;
}
static void F_389 ( struct V_2 * V_2 , struct V_468 * * V_43 , T_9 V_50 , T_9 V_601 )
{
struct V_595 * V_596 ;
T_9 V_589 = sizeof( * V_596 ) + V_601 ;
if ( V_589 <= V_593 ) {
V_596 = F_272 ( V_589 , V_363 ) ;
if ( V_596 == NULL )
goto V_132;
V_596 -> V_599 = 1 ;
F_390 ( V_596 -> V_158 , V_43 , V_50 , V_601 ) ;
} else {
V_596 = F_272 ( sizeof( * V_596 ) , V_363 ) ;
if ( V_596 == NULL )
goto V_132;
V_596 -> V_599 = 0 ;
}
V_596 -> V_12 = V_601 ;
V_132:
F_386 ( V_2 , V_596 ) ;
}
static T_11 F_391 ( struct V_2 * V_2 , void * V_588 , T_9 V_589 )
{
struct V_468 * V_43 [ V_602 ] = { NULL , } ;
struct V_603 args = {
. V_234 = F_93 ( V_2 ) ,
. V_604 = V_43 ,
. V_601 = V_589 ,
} ;
struct V_605 V_58 = {
. V_601 = V_589 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_606 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
unsigned int V_607 = F_392 ( V_589 , V_593 ) ;
int V_53 = - V_127 , V_457 ;
if ( V_607 == 0 )
V_607 = 1 ;
if ( V_607 > F_263 ( V_43 ) )
return - V_600 ;
for ( V_457 = 0 ; V_457 < V_607 ; V_457 ++ ) {
V_43 [ V_457 ] = F_271 ( V_363 ) ;
if ( ! V_43 [ V_457 ] )
goto V_293;
}
V_58 . V_608 = F_271 ( V_363 ) ;
if ( ! V_58 . V_608 )
goto V_293;
args . V_601 = V_607 * V_593 ;
args . V_609 = 0 ;
F_8 ( L_40 ,
V_35 , V_588 , V_589 , V_607 , args . V_601 ) ;
V_53 = F_73 ( F_85 ( V_2 ) -> V_92 , F_85 ( V_2 ) ,
& V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
if ( V_53 )
goto V_293;
if ( V_58 . V_610 & V_611 ) {
if ( V_588 == NULL )
goto V_612;
V_53 = - V_600 ;
goto V_293;
}
F_389 ( V_2 , V_43 , V_58 . V_613 , V_58 . V_601 ) ;
if ( V_588 ) {
if ( V_58 . V_601 > V_589 ) {
V_53 = - V_600 ;
goto V_293;
}
F_390 ( V_588 , V_43 , V_58 . V_613 , V_58 . V_601 ) ;
}
V_612:
V_53 = V_58 . V_601 ;
V_293:
for ( V_457 = 0 ; V_457 < V_607 ; V_457 ++ )
if ( V_43 [ V_457 ] )
F_275 ( V_43 [ V_457 ] ) ;
if ( V_58 . V_608 )
F_275 ( V_58 . V_608 ) ;
return V_53 ;
}
static T_11 F_393 ( struct V_2 * V_2 , void * V_588 , T_9 V_589 )
{
struct V_62 V_63 = { } ;
T_11 V_53 ;
do {
V_53 = F_391 ( V_2 , V_588 , V_589 ) ;
F_394 ( V_2 , V_53 ) ;
if ( V_53 >= 0 )
break;
V_53 = F_20 ( F_85 ( V_2 ) , V_53 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_53 ;
}
static T_11 F_395 ( struct V_2 * V_2 , void * V_588 , T_9 V_589 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
int V_53 ;
if ( ! F_382 ( V_14 ) )
return - V_614 ;
V_53 = F_396 ( V_14 , V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_75 ( V_2 ) -> V_176 & V_615 )
F_397 ( V_2 ) ;
V_53 = F_388 ( V_2 , V_588 , V_589 ) ;
if ( V_53 != - V_285 )
return V_53 ;
return F_393 ( V_2 , V_588 , V_589 ) ;
}
static int F_398 ( struct V_2 * V_2 , const void * V_588 , T_9 V_589 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_468 * V_43 [ V_602 ] ;
struct V_616 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_604 = V_43 ,
. V_601 = V_589 ,
} ;
struct V_617 V_58 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_618 ] ,
. V_297 = & V_375 ,
. V_298 = & V_58 ,
} ;
unsigned int V_607 = F_392 ( V_589 , V_593 ) ;
int V_53 , V_457 ;
if ( ! F_382 ( V_14 ) )
return - V_614 ;
if ( V_607 > F_263 ( V_43 ) )
return - V_600 ;
V_457 = F_383 ( V_588 , V_589 , V_375 . V_604 , & V_375 . V_609 ) ;
if ( V_457 < 0 )
return V_457 ;
F_22 ( V_2 ) ;
V_53 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_58 . V_161 , 1 ) ;
for (; V_457 > 0 ; V_457 -- )
F_399 ( V_43 [ V_457 - 1 ] ) ;
F_34 ( & V_2 -> V_175 ) ;
F_75 ( V_2 ) -> V_176 |= V_177 ;
F_36 ( & V_2 -> V_175 ) ;
F_400 ( V_2 ) ;
F_397 ( V_2 ) ;
return V_53 ;
}
static int F_401 ( struct V_2 * V_2 , const void * V_588 , T_9 V_589 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_398 ( V_2 , V_588 , V_589 ) ;
F_402 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_403 ( struct V_2 * V_2 , void * V_588 ,
T_9 V_589 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_371 V_372 ;
struct V_1 V_7 = { 0 , 0 , V_589 , V_588 } ;
T_1 V_231 [ 3 ] = { 0 , 0 , V_439 } ;
struct V_471 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_231 = V_231 ,
} ;
struct V_472 V_58 = {
. V_372 = & V_372 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_473 ] ,
. V_297 = & V_375 ,
. V_298 = & V_58 ,
} ;
int V_53 ;
F_81 ( & V_372 ) ;
V_53 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_58 . V_161 , 0 ) ;
if ( V_53 )
return V_53 ;
if ( ! ( V_372 . V_280 & V_619 ) )
return - V_285 ;
if ( V_589 < V_7 . V_12 )
return - V_600 ;
return 0 ;
}
static int F_404 ( struct V_2 * V_2 , void * V_588 ,
T_9 V_589 )
{
struct V_62 V_63 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_614 ;
do {
V_8 = F_403 ( V_2 , V_588 , V_589 ) ;
F_405 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_406 ( struct V_2 * V_2 ,
struct V_1 * V_373 ,
struct V_371 * V_372 ,
struct V_1 * V_362 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
const T_1 V_231 [ 3 ] = { 0 , 0 , V_439 } ;
struct V_374 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_376 = & V_6 ,
. V_14 = V_14 ,
. V_231 = V_231 ,
. V_7 = V_373 ,
} ;
struct V_377 V_58 = {
. V_372 = V_372 ,
. V_7 = V_362 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_378 ] ,
. V_297 = & V_375 ,
. V_298 = & V_58 ,
} ;
int V_289 ;
F_123 ( & V_375 . V_240 , & V_388 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_58 . V_161 , 1 ) ;
if ( V_289 )
F_8 ( L_41 , V_35 , V_289 ) ;
return V_289 ;
}
static int F_407 ( struct V_2 * V_2 ,
struct V_1 * V_373 ,
struct V_371 * V_372 ,
struct V_1 * V_362 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_406 ( V_2 , V_373 ,
V_372 , V_362 ) ;
F_408 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int
F_409 ( struct V_4 * V_4 , const void * V_588 , T_9 V_589 )
{
struct V_1 V_373 , * V_362 = NULL ;
struct V_371 V_372 ;
struct V_299 * V_333 ;
struct V_2 * V_2 = V_4 -> V_47 ;
int V_289 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_614 ;
F_81 ( & V_372 ) ;
V_373 . V_620 = 0 ;
V_373 . V_621 = 0 ;
V_373 . V_7 = ( char * ) V_588 ;
V_373 . V_12 = V_589 ;
V_333 = F_410 () ;
if ( F_43 ( V_333 ) )
return F_71 ( V_333 ) ;
V_362 = F_87 ( F_85 ( V_2 ) , V_363 ) ;
if ( F_43 ( V_362 ) ) {
V_289 = - F_71 ( V_362 ) ;
goto V_132;
}
V_289 = F_407 ( V_2 , & V_373 , & V_372 , V_362 ) ;
if ( V_289 == 0 )
F_225 ( V_2 , & V_372 , V_362 ) ;
F_95 ( V_362 ) ;
V_132:
F_206 ( V_333 ) ;
return V_289 ;
}
static int
F_241 ( struct V_117 * V_118 , const struct V_13 * V_14 ,
struct V_66 * V_67 , long * V_52 )
{
struct V_64 * V_65 = V_14 -> V_64 ;
if ( V_118 -> V_150 >= 0 )
return 0 ;
switch( V_118 -> V_150 ) {
case - V_72 :
case - V_73 :
case - V_74 :
case - V_69 :
if ( V_67 == NULL )
break;
if ( F_23 ( V_14 , V_67 ) < 0 )
goto V_622;
goto V_71;
case - V_75 :
if ( V_67 != NULL ) {
if ( F_23 ( V_14 , V_67 ) < 0 )
goto V_622;
}
case - V_76 :
case - V_77 :
F_24 ( V_65 ) ;
goto V_71;
case - V_78 :
if ( F_25 ( V_14 ) < 0 )
goto V_622;
goto V_71;
case - V_79 :
F_26 ( V_65 ) ;
goto V_71;
#if F_27 ( V_80 )
case - V_81 :
case - V_82 :
case - V_83 :
case - V_85 :
case - V_84 :
case - V_86 :
case - V_87 :
F_8 ( L_42 , V_35 ,
V_118 -> V_150 ) ;
F_28 ( V_65 -> V_88 , V_118 -> V_150 ) ;
goto V_71;
#endif
case - V_91 :
F_411 ( V_14 , V_623 ) ;
F_59 ( V_118 , F_15 ( V_52 ) ) ;
goto V_624;
case - V_90 :
F_59 ( V_118 , V_54 ) ;
case - V_93 :
case - V_94 :
goto V_624;
}
V_118 -> V_150 = F_7 ( V_118 -> V_150 ) ;
return 0 ;
V_622:
V_118 -> V_150 = - V_36 ;
return 0 ;
V_71:
F_47 ( & V_65 -> V_625 , V_118 , NULL ) ;
if ( F_31 ( V_626 , & V_65 -> V_627 ) == 0 )
F_412 ( & V_65 -> V_625 , V_118 ) ;
if ( F_31 ( V_99 , & V_14 -> V_100 ) )
goto V_622;
V_624:
V_118 -> V_150 = 0 ;
return - V_131 ;
}
static void F_413 ( const struct V_64 * V_65 ,
T_12 * V_628 )
{
T_3 V_237 [ 2 ] ;
if ( F_31 ( V_629 , & V_65 -> V_627 ) ) {
V_237 [ 0 ] = 0 ;
V_237 [ 1 ] = F_414 ( V_630 + 1 ) ;
} else {
struct V_631 * V_632 = F_415 ( V_65 -> V_633 , V_634 ) ;
V_237 [ 0 ] = F_414 ( V_632 -> V_635 . V_636 ) ;
V_237 [ 1 ] = F_414 ( V_632 -> V_635 . V_637 ) ;
}
memcpy ( V_628 -> V_158 , V_237 , sizeof( V_628 -> V_158 ) ) ;
}
static unsigned int
F_416 ( const struct V_64 * V_65 ,
char * V_588 , T_9 V_12 )
{
unsigned int V_638 ;
F_132 () ;
V_638 = F_417 ( V_588 , V_12 , L_43 ,
V_65 -> V_639 ,
F_418 ( V_65 -> V_102 ,
V_640 ) ,
F_418 ( V_65 -> V_102 ,
V_641 ) ) ;
F_135 () ;
return V_638 ;
}
static unsigned int
F_419 ( const struct V_64 * V_65 ,
char * V_588 , T_9 V_12 )
{
const char * V_642 = V_65 -> V_102 -> V_643 ;
if ( V_644 [ 0 ] != '\0' )
return F_417 ( V_588 , V_12 , L_44 ,
V_65 -> V_645 -> V_646 ,
V_65 -> V_414 ,
V_644 ,
V_642 ) ;
return F_417 ( V_588 , V_12 , L_45 ,
V_65 -> V_645 -> V_646 , V_65 -> V_414 ,
V_642 ) ;
}
static unsigned int
F_420 ( const struct V_64 * V_65 , char * V_588 , T_9 V_12 )
{
if ( strchr ( V_65 -> V_639 , ':' ) != NULL )
return F_417 ( V_588 , V_12 , L_46 ) ;
else
return F_417 ( V_588 , V_12 , L_47 ) ;
}
static void F_421 ( struct V_117 * V_118 , void * V_156 )
{
struct V_647 * V_648 = V_156 ;
if ( V_118 -> V_150 == 0 )
V_648 -> V_649 = F_202 ( V_118 -> V_650 -> V_651 ) ;
}
int F_422 ( struct V_64 * V_65 , T_1 V_652 ,
unsigned short V_653 , struct V_299 * V_333 ,
struct V_654 * V_58 )
{
T_12 V_655 ;
struct V_647 V_656 = {
. V_655 = & V_655 ,
. V_657 = V_652 ,
. V_658 = V_65 -> V_659 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_660 ] ,
. V_297 = & V_656 ,
. V_298 = V_58 ,
. V_299 = V_333 ,
} ;
struct V_117 * V_118 ;
struct V_164 V_300 = {
. V_166 = V_65 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_661 ,
. V_170 = & V_656 ,
. V_207 = V_586 ,
} ;
int V_289 ;
F_413 ( V_65 , & V_655 ) ;
if ( F_31 ( V_662 , & V_65 -> V_663 ) )
V_656 . V_664 =
F_419 ( V_65 ,
V_656 . V_665 ,
sizeof( V_656 . V_665 ) ) ;
else
V_656 . V_664 =
F_416 ( V_65 ,
V_656 . V_665 ,
sizeof( V_656 . V_665 ) ) ;
V_656 . V_666 =
F_420 ( V_65 ,
V_656 . V_667 ,
sizeof( V_656 . V_667 ) ) ;
V_656 . V_668 = F_417 ( V_656 . V_669 ,
sizeof( V_656 . V_669 ) , L_48 ,
V_65 -> V_639 , V_653 >> 8 , V_653 & 255 ) ;
F_8 ( L_49 ,
V_65 -> V_102 -> V_103 -> V_670 -> V_671 ,
V_656 . V_664 , V_656 . V_665 ) ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) ) {
V_289 = F_71 ( V_118 ) ;
goto V_132;
}
V_289 = V_118 -> V_150 ;
if ( V_656 . V_649 ) {
V_65 -> V_672 = F_423 ( V_656 . V_649 ) ;
F_206 ( V_656 . V_649 ) ;
}
F_72 ( V_118 ) ;
V_132:
F_424 ( V_65 , V_289 ) ;
F_8 ( L_50 , V_289 ) ;
return V_289 ;
}
int F_425 ( struct V_64 * V_65 ,
struct V_654 * V_375 ,
struct V_299 * V_333 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_673 ] ,
. V_297 = V_375 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_8 ( L_51 ,
V_65 -> V_102 -> V_103 -> V_670 -> V_671 ,
V_65 -> V_225 ) ;
V_289 = F_381 ( V_65 -> V_102 , & V_163 , V_586 ) ;
F_426 ( V_65 , V_289 ) ;
F_8 ( L_52 , V_289 ) ;
return V_289 ;
}
static void F_427 ( struct V_117 * V_118 , void * V_156 )
{
struct V_674 * V_158 = V_156 ;
if ( ! F_60 ( V_118 , & V_158 -> V_58 . V_161 ) )
return;
F_428 ( & V_158 -> args , & V_158 -> V_58 , V_118 -> V_150 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
F_37 ( V_158 -> V_58 . V_14 , V_158 -> V_107 ) ;
case - V_73 :
case - V_72 :
case - V_74 :
case - V_94 :
case - V_76 :
case - V_75 :
V_118 -> V_150 = 0 ;
if ( V_158 -> V_392 )
F_240 ( V_158 -> V_2 , V_158 -> V_394 ) ;
break;
default:
if ( F_241 ( V_118 , V_158 -> V_58 . V_14 ,
NULL , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
V_158 -> V_277 = V_118 -> V_150 ;
}
static void F_429 ( void * V_156 )
{
struct V_674 * V_158 = V_156 ;
if ( V_158 -> V_392 )
F_237 ( V_158 -> V_2 ) ;
F_96 ( V_156 ) ;
}
static void F_430 ( struct V_117 * V_118 , void * V_158 )
{
struct V_674 * V_675 ;
V_675 = (struct V_674 * ) V_158 ;
if ( V_675 -> V_392 &&
F_243 ( V_675 -> V_2 , & V_675 -> V_394 , V_118 ) )
return;
F_63 ( V_675 -> V_58 . V_14 ,
& V_675 -> args . V_160 ,
& V_675 -> V_58 . V_161 ,
V_118 ) ;
}
static int F_431 ( struct V_2 * V_2 , struct V_299 * V_333 , const T_8 * V_240 , int V_676 )
{
struct V_674 * V_158 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_677 ] ,
. V_299 = V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_678 ,
. V_207 = V_304 ,
} ;
int V_289 = 0 ;
V_158 = F_86 ( sizeof( * V_158 ) , V_286 ) ;
if ( V_158 == NULL )
return - V_127 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_58 . V_161 , 1 ) ;
V_158 -> args . V_410 = & V_158 -> V_234 ;
V_158 -> args . V_240 = & V_158 -> V_240 ;
V_158 -> args . V_231 = V_14 -> V_406 ;
F_178 ( & V_158 -> V_234 , F_93 ( V_2 ) ) ;
F_123 ( & V_158 -> V_240 , V_240 ) ;
V_158 -> V_58 . V_372 = & V_158 -> V_372 ;
V_158 -> V_58 . V_14 = V_14 ;
F_81 ( V_158 -> V_58 . V_372 ) ;
V_158 -> V_107 = V_155 ;
V_158 -> V_277 = 0 ;
V_158 -> V_2 = V_2 ;
V_158 -> V_392 = F_432 ( & F_75 ( V_2 ) -> V_679 ) ?
F_247 ( V_2 ) : false ;
V_300 . V_170 = V_158 ;
V_163 . V_297 = & V_158 -> args ;
V_163 . V_298 = & V_158 -> V_58 ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
if ( ! V_676 )
goto V_132;
V_289 = F_107 ( V_118 ) ;
if ( V_289 != 0 )
goto V_132;
V_289 = V_158 -> V_277 ;
if ( V_289 == 0 )
F_360 ( V_2 , & V_158 -> V_372 ) ;
else
F_145 ( V_2 , & V_158 -> V_372 ) ;
V_132:
F_72 ( V_118 ) ;
return V_289 ;
}
int F_433 ( struct V_2 * V_2 , struct V_299 * V_333 , const T_8 * V_240 , int V_676 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_431 ( V_2 , V_333 , V_240 , V_676 ) ;
F_434 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_76 :
case - V_75 :
case 0 :
return 0 ;
}
V_8 = F_20 ( V_14 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static unsigned long
F_435 ( unsigned long V_52 )
{
F_18 ( V_52 ) ;
V_52 <<= 1 ;
if ( V_52 > V_680 )
return V_680 ;
return V_52 ;
}
static int F_436 ( struct V_66 * V_67 , int V_681 , struct V_682 * V_683 )
{
struct V_2 * V_2 = V_67 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_64 ;
struct V_684 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_685 = V_683 ,
} ;
struct V_686 V_58 = {
. V_687 = V_683 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_688 ] ,
. V_297 = & V_375 ,
. V_298 = & V_58 ,
. V_299 = V_67 -> V_215 -> V_274 ,
} ;
struct V_689 * V_690 ;
int V_289 ;
V_375 . V_691 . V_224 = V_65 -> V_225 ;
V_289 = F_437 ( V_67 , V_683 ) ;
if ( V_289 != 0 )
goto V_132;
V_690 = V_683 -> V_692 . V_693 . V_215 ;
V_375 . V_691 . V_226 = V_690 -> V_694 . V_229 ;
V_375 . V_691 . V_695 = V_14 -> V_695 ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_58 . V_161 , 1 ) ;
switch ( V_289 ) {
case 0 :
V_683 -> V_696 = V_697 ;
break;
case - V_291 :
V_289 = 0 ;
}
V_683 -> V_698 -> V_699 ( V_683 ) ;
V_683 -> V_698 = NULL ;
V_132:
return V_289 ;
}
static int F_438 ( struct V_66 * V_67 , int V_681 , struct V_682 * V_683 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_436 ( V_67 , V_681 , V_683 ) ;
F_439 ( V_683 , V_67 , V_681 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_67 -> V_2 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_440 ( struct V_700 * V_700 , struct V_682 * V_685 )
{
int V_58 = 0 ;
switch ( V_685 -> V_701 & ( V_702 | V_703 ) ) {
case V_702 :
V_58 = F_441 ( V_700 , V_685 ) ;
break;
case V_703 :
V_58 = F_442 ( V_700 , V_685 ) ;
break;
default:
F_443 () ;
}
return V_58 ;
}
static struct V_704 * F_444 ( struct V_682 * V_685 ,
struct V_283 * V_284 ,
struct V_689 * V_690 ,
struct V_705 * V_196 )
{
struct V_704 * V_42 ;
struct V_2 * V_2 = V_690 -> V_706 -> V_2 ;
V_42 = F_86 ( sizeof( * V_42 ) , V_286 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_375 . V_234 = F_93 ( V_2 ) ;
V_42 -> V_375 . V_685 = & V_42 -> V_685 ;
V_42 -> V_375 . V_196 = V_196 ;
V_42 -> V_58 . V_196 = V_196 ;
V_42 -> V_375 . V_240 = & V_690 -> V_707 ;
V_42 -> V_690 = V_690 ;
F_91 ( & V_690 -> V_708 ) ;
V_42 -> V_284 = F_153 ( V_284 ) ;
memcpy ( & V_42 -> V_685 , V_685 , sizeof( V_42 -> V_685 ) ) ;
V_42 -> V_14 = F_85 ( V_2 ) ;
return V_42 ;
}
static void F_445 ( void * V_158 )
{
struct V_704 * V_156 = V_158 ;
F_100 ( V_156 -> V_375 . V_196 ) ;
F_446 ( V_156 -> V_690 ) ;
F_164 ( V_156 -> V_284 ) ;
F_96 ( V_156 ) ;
}
static void F_447 ( struct V_117 * V_118 , void * V_158 )
{
struct V_704 * V_156 = V_158 ;
if ( ! F_60 ( V_118 , & V_156 -> V_58 . V_161 ) )
return;
switch ( V_118 -> V_150 ) {
case 0 :
F_123 ( & V_156 -> V_690 -> V_707 ,
& V_156 -> V_58 . V_240 ) ;
F_37 ( V_156 -> V_14 , V_156 -> V_107 ) ;
break;
case - V_74 :
case - V_94 :
case - V_76 :
case - V_75 :
break;
default:
if ( F_241 ( V_118 , V_156 -> V_14 ,
NULL , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
F_138 ( V_156 -> V_375 . V_196 ) ;
}
static void F_448 ( struct V_117 * V_118 , void * V_158 )
{
struct V_704 * V_156 = V_158 ;
if ( F_177 ( V_156 -> V_375 . V_196 , V_118 ) != 0 )
goto V_305;
if ( F_31 ( V_709 , & V_156 -> V_690 -> V_710 ) == 0 ) {
goto V_306;
}
V_156 -> V_107 = V_155 ;
if ( F_63 ( V_156 -> V_14 ,
& V_156 -> V_375 . V_160 ,
& V_156 -> V_58 . V_161 ,
V_118 ) != 0 )
F_138 ( V_156 -> V_375 . V_196 ) ;
return;
V_306:
V_118 -> V_317 = NULL ;
V_305:
F_60 ( V_118 , & V_156 -> V_58 . V_161 ) ;
}
static struct V_117 * F_449 ( struct V_682 * V_685 ,
struct V_283 * V_284 ,
struct V_689 * V_690 ,
struct V_705 * V_196 )
{
struct V_704 * V_158 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_711 ] ,
. V_299 = V_284 -> V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = F_290 ( V_690 -> V_706 -> V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_712 ,
. V_302 = V_303 ,
. V_207 = V_304 ,
} ;
F_249 ( F_85 ( V_690 -> V_706 -> V_2 ) -> V_64 ,
V_404 , & V_300 . V_166 , & V_163 ) ;
V_685 -> V_696 = V_697 ;
V_158 = F_444 ( V_685 , V_284 , V_690 , V_196 ) ;
if ( V_158 == NULL ) {
F_100 ( V_196 ) ;
return F_44 ( - V_127 ) ;
}
F_38 ( & V_158 -> V_375 . V_160 , & V_158 -> V_58 . V_161 , 1 ) ;
V_163 . V_297 = & V_158 -> V_375 ;
V_163 . V_298 = & V_158 -> V_58 ;
V_300 . V_170 = V_158 ;
return F_70 ( & V_300 ) ;
}
static int F_450 ( struct V_66 * V_67 , int V_681 , struct V_682 * V_683 )
{
struct V_2 * V_2 = V_67 -> V_2 ;
struct V_204 * V_205 = V_67 -> V_215 ;
struct V_173 * V_174 = F_75 ( V_2 ) ;
struct V_705 * V_196 ;
struct V_689 * V_690 ;
struct V_117 * V_118 ;
int V_289 = 0 ;
unsigned char V_701 = V_683 -> V_701 ;
V_289 = F_437 ( V_67 , V_683 ) ;
V_683 -> V_701 |= V_713 ;
F_451 ( & V_205 -> V_714 ) ;
F_452 ( & V_174 -> V_715 ) ;
if ( F_440 ( V_683 -> V_716 , V_683 ) == - V_285 ) {
F_453 ( & V_174 -> V_715 ) ;
F_454 ( & V_205 -> V_714 ) ;
goto V_132;
}
F_453 ( & V_174 -> V_715 ) ;
F_454 ( & V_205 -> V_714 ) ;
if ( V_289 != 0 )
goto V_132;
V_690 = V_683 -> V_692 . V_693 . V_215 ;
if ( F_31 ( V_709 , & V_690 -> V_710 ) == 0 )
goto V_132;
V_196 = F_88 ( & V_690 -> V_694 , V_363 ) ;
V_289 = - V_127 ;
if ( V_196 == NULL )
goto V_132;
V_118 = F_449 ( V_683 , F_282 ( V_683 -> V_716 ) , V_690 , V_196 ) ;
V_289 = F_71 ( V_118 ) ;
if ( F_43 ( V_118 ) )
goto V_132;
V_289 = F_107 ( V_118 ) ;
F_72 ( V_118 ) ;
V_132:
V_683 -> V_701 = V_701 ;
F_455 ( V_683 , V_67 , V_717 , V_289 ) ;
return V_289 ;
}
static struct V_718 * F_456 ( struct V_682 * V_685 ,
struct V_283 * V_284 , struct V_689 * V_690 ,
T_6 V_209 )
{
struct V_718 * V_42 ;
struct V_2 * V_2 = V_690 -> V_706 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
V_42 = F_86 ( sizeof( * V_42 ) , V_209 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_375 . V_234 = F_93 ( V_2 ) ;
V_42 -> V_375 . V_685 = & V_42 -> V_685 ;
V_42 -> V_375 . V_719 = F_88 ( & V_690 -> V_706 -> V_215 -> V_212 , V_209 ) ;
if ( V_42 -> V_375 . V_719 == NULL )
goto V_293;
V_42 -> V_375 . V_720 = F_88 ( & V_690 -> V_694 , V_209 ) ;
if ( V_42 -> V_375 . V_720 == NULL )
goto V_721;
V_42 -> V_375 . V_722 = & V_690 -> V_707 ;
V_42 -> V_375 . V_691 . V_224 = V_14 -> V_64 -> V_225 ;
V_42 -> V_375 . V_691 . V_226 = V_690 -> V_694 . V_229 ;
V_42 -> V_375 . V_691 . V_695 = V_14 -> V_695 ;
V_42 -> V_58 . V_720 = V_42 -> V_375 . V_720 ;
V_42 -> V_690 = V_690 ;
V_42 -> V_14 = V_14 ;
F_91 ( & V_690 -> V_708 ) ;
V_42 -> V_284 = F_153 ( V_284 ) ;
memcpy ( & V_42 -> V_685 , V_685 , sizeof( V_42 -> V_685 ) ) ;
return V_42 ;
V_721:
F_100 ( V_42 -> V_375 . V_719 ) ;
V_293:
F_96 ( V_42 ) ;
return NULL ;
}
static void F_457 ( struct V_117 * V_118 , void * V_156 )
{
struct V_718 * V_158 = V_156 ;
struct V_66 * V_67 = V_158 -> V_690 -> V_706 ;
F_8 ( L_29 , V_35 ) ;
if ( F_177 ( V_158 -> V_375 . V_720 , V_118 ) != 0 )
goto V_305;
if ( ! ( V_158 -> V_375 . V_720 -> V_723 -> V_207 & V_724 ) ) {
if ( F_177 ( V_158 -> V_375 . V_719 , V_118 ) != 0 ) {
goto V_725;
}
V_158 -> V_375 . V_261 = & V_67 -> V_261 ;
V_158 -> V_375 . V_726 = 1 ;
V_158 -> V_58 . V_719 = V_158 -> V_375 . V_719 ;
} else
V_158 -> V_375 . V_726 = 0 ;
if ( ! F_232 ( V_67 ) ) {
V_158 -> V_277 = - V_387 ;
V_118 -> V_317 = NULL ;
goto V_727;
}
V_158 -> V_107 = V_155 ;
if ( F_63 ( V_158 -> V_14 ,
& V_158 -> V_375 . V_160 ,
& V_158 -> V_58 . V_161 ,
V_118 ) == 0 )
return;
V_727:
F_138 ( V_158 -> V_375 . V_719 ) ;
V_725:
F_138 ( V_158 -> V_375 . V_720 ) ;
V_305:
F_60 ( V_118 , & V_158 -> V_58 . V_161 ) ;
F_8 ( L_53 , V_35 , V_158 -> V_277 ) ;
}
static void F_458 ( struct V_117 * V_118 , void * V_156 )
{
struct V_718 * V_158 = V_156 ;
F_8 ( L_29 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_158 -> V_58 . V_161 ) )
return;
V_158 -> V_277 = V_118 -> V_150 ;
if ( V_158 -> V_375 . V_726 != 0 ) {
if ( V_158 -> V_277 == 0 )
F_171 ( & V_158 -> V_690 -> V_694 , 0 ) ;
else
goto V_132;
}
if ( V_158 -> V_277 == 0 ) {
F_123 ( & V_158 -> V_690 -> V_707 , & V_158 -> V_58 . V_240 ) ;
F_129 ( V_709 , & V_158 -> V_690 -> V_710 ) ;
F_37 ( F_85 ( V_158 -> V_284 -> V_4 -> V_47 ) , V_158 -> V_107 ) ;
}
V_132:
F_8 ( L_30 , V_35 , V_158 -> V_277 ) ;
}
static void F_459 ( void * V_156 )
{
struct V_718 * V_158 = V_156 ;
F_8 ( L_29 , V_35 ) ;
F_100 ( V_158 -> V_375 . V_719 ) ;
if ( V_158 -> V_292 != 0 ) {
struct V_117 * V_118 ;
V_118 = F_449 ( & V_158 -> V_685 , V_158 -> V_284 , V_158 -> V_690 ,
V_158 -> V_375 . V_720 ) ;
if ( ! F_43 ( V_118 ) )
F_460 ( V_118 ) ;
F_8 ( L_54 , V_35 ) ;
} else
F_100 ( V_158 -> V_375 . V_720 ) ;
F_446 ( V_158 -> V_690 ) ;
F_164 ( V_158 -> V_284 ) ;
F_96 ( V_158 ) ;
F_8 ( L_31 , V_35 ) ;
}
static void F_461 ( struct V_13 * V_14 , struct V_689 * V_690 , int V_726 , int error )
{
switch ( error ) {
case - V_73 :
case - V_74 :
V_690 -> V_694 . V_207 &= ~ V_724 ;
if ( V_726 != 0 ||
F_31 ( V_709 , & V_690 -> V_710 ) != 0 )
F_23 ( V_14 , V_690 -> V_706 ) ;
break;
case - V_76 :
V_690 -> V_694 . V_207 &= ~ V_724 ;
case - V_75 :
F_24 ( V_14 -> V_64 ) ;
} ;
}
static int F_462 ( struct V_66 * V_67 , int V_681 , struct V_682 * V_685 , int V_728 )
{
struct V_718 * V_158 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_729 ] ,
. V_299 = V_67 -> V_215 -> V_274 ,
} ;
struct V_164 V_300 = {
. V_166 = F_290 ( V_67 -> V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_730 ,
. V_302 = V_303 ,
. V_207 = V_304 ,
} ;
int V_53 ;
F_8 ( L_29 , V_35 ) ;
V_158 = F_456 ( V_685 , F_282 ( V_685 -> V_716 ) ,
V_685 -> V_692 . V_693 . V_215 ,
V_728 == V_731 ? V_363 : V_286 ) ;
if ( V_158 == NULL )
return - V_127 ;
if ( F_463 ( V_681 ) )
V_158 -> V_375 . V_732 = 1 ;
F_38 ( & V_158 -> V_375 . V_160 , & V_158 -> V_58 . V_161 , 1 ) ;
V_163 . V_297 = & V_158 -> V_375 ;
V_163 . V_298 = & V_158 -> V_58 ;
V_300 . V_170 = V_158 ;
if ( V_728 > V_731 ) {
if ( V_728 == V_733 )
V_158 -> V_375 . V_734 = V_733 ;
F_39 ( & V_158 -> V_375 . V_160 ) ;
}
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_53 = F_107 ( V_118 ) ;
if ( V_53 == 0 ) {
V_53 = V_158 -> V_277 ;
if ( V_53 )
F_461 ( V_158 -> V_14 , V_158 -> V_690 ,
V_158 -> V_375 . V_726 , V_53 ) ;
} else
V_158 -> V_292 = 1 ;
F_72 ( V_118 ) ;
F_8 ( L_30 , V_35 , V_53 ) ;
return V_53 ;
}
static int F_464 ( struct V_66 * V_67 , struct V_682 * V_683 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
struct V_62 V_63 = {
. V_2 = V_67 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_31 ( V_262 , & V_67 -> V_207 ) != 0 )
return 0 ;
V_8 = F_462 ( V_67 , V_717 , V_683 , V_733 ) ;
F_465 ( V_683 , V_67 , V_717 , V_8 ) ;
if ( V_8 != - V_91 )
break;
F_20 ( V_14 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_466 ( struct V_66 * V_67 , struct V_682 * V_683 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
struct V_62 V_63 = {
. V_2 = V_67 -> V_2 ,
} ;
int V_8 ;
V_8 = F_437 ( V_67 , V_683 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_735 ) {
F_129 ( V_736 , & V_683 -> V_692 . V_693 . V_215 -> V_710 ) ;
return 0 ;
}
do {
if ( F_31 ( V_262 , & V_67 -> V_207 ) != 0 )
return 0 ;
V_8 = F_462 ( V_67 , V_717 , V_683 , V_737 ) ;
F_467 ( V_683 , V_67 , V_717 , V_8 ) ;
switch ( V_8 ) {
default:
goto V_132;
case - V_90 :
case - V_91 :
F_20 ( V_14 , V_8 , & V_63 ) ;
V_8 = 0 ;
}
} while ( V_63 . V_68 );
V_132:
return V_8 ;
}
static int F_468 ( struct V_66 * V_67 )
{
int V_289 , V_53 = - V_74 ;
struct V_689 * V_690 ;
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
F_152 (lsp, &state->lock_states, ls_locks) {
if ( F_31 ( V_709 , & V_690 -> V_710 ) ) {
struct V_299 * V_333 = V_690 -> V_706 -> V_215 -> V_274 ;
V_289 = F_203 ( V_14 ,
& V_690 -> V_707 ,
V_333 ) ;
F_469 ( V_67 , V_690 , V_289 ) ;
if ( V_289 != V_347 ) {
if ( V_289 != - V_74 )
F_205 ( V_14 ,
& V_690 -> V_707 ,
V_333 ) ;
F_122 ( V_709 , & V_690 -> V_710 ) ;
V_53 = V_289 ;
}
}
} ;
return V_53 ;
}
static int F_470 ( struct V_66 * V_67 , struct V_682 * V_683 )
{
int V_289 = V_347 ;
if ( F_31 ( V_738 , & V_67 -> V_207 ) )
V_289 = F_468 ( V_67 ) ;
if ( V_289 != V_347 )
V_289 = F_466 ( V_67 , V_683 ) ;
return V_289 ;
}
static int F_471 ( struct V_66 * V_67 , int V_681 , struct V_682 * V_683 )
{
struct V_204 * V_205 = V_67 -> V_215 ;
struct V_173 * V_174 = F_75 ( V_67 -> V_2 ) ;
unsigned char V_701 = V_683 -> V_701 ;
unsigned int V_355 ;
int V_289 = - V_739 ;
if ( ( V_701 & V_702 ) &&
! F_31 ( V_357 , & V_67 -> V_207 ) )
goto V_132;
V_289 = F_437 ( V_67 , V_683 ) ;
if ( V_289 != 0 )
goto V_132;
V_683 -> V_701 |= V_740 ;
V_289 = F_440 ( V_683 -> V_716 , V_683 ) ;
if ( V_289 < 0 )
goto V_132;
F_452 ( & V_174 -> V_715 ) ;
if ( F_31 ( V_262 , & V_67 -> V_207 ) ) {
V_683 -> V_701 = V_701 & ~ V_741 ;
V_289 = F_440 ( V_683 -> V_716 , V_683 ) ;
goto V_139;
}
V_355 = F_212 ( & V_205 -> V_356 ) ;
F_453 ( & V_174 -> V_715 ) ;
V_289 = F_462 ( V_67 , V_681 , V_683 , V_731 ) ;
if ( V_289 != 0 )
goto V_132;
F_452 ( & V_174 -> V_715 ) ;
if ( F_218 ( & V_205 -> V_356 , V_355 ) ) {
V_289 = - V_91 ;
goto V_139;
}
V_683 -> V_701 = V_701 | V_741 ;
if ( F_440 ( V_683 -> V_716 , V_683 ) < 0 )
F_29 ( V_97 L_55
L_56 , V_35 ) ;
V_139:
F_453 ( & V_174 -> V_715 ) ;
V_132:
V_683 -> V_701 = V_701 ;
return V_289 ;
}
static int F_472 ( struct V_66 * V_67 , int V_681 , struct V_682 * V_683 )
{
struct V_62 V_63 = {
. V_67 = V_67 ,
. V_2 = V_67 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_471 ( V_67 , V_681 , V_683 ) ;
F_473 ( V_683 , V_67 , V_681 , V_8 ) ;
if ( V_8 == - V_291 )
V_8 = - V_131 ;
V_8 = F_20 ( F_85 ( V_67 -> V_2 ) ,
V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int
F_474 ( struct V_700 * V_742 , int V_681 , struct V_682 * V_683 )
{
struct V_283 * V_284 ;
struct V_66 * V_67 ;
unsigned long V_52 = V_743 ;
int V_289 ;
V_284 = F_282 ( V_742 ) ;
V_67 = V_284 -> V_67 ;
if ( V_683 -> V_744 < 0 || V_683 -> V_745 < 0 )
return - V_27 ;
if ( F_475 ( V_681 ) ) {
if ( V_67 != NULL )
return F_438 ( V_67 , V_746 , V_683 ) ;
return 0 ;
}
if ( ! ( F_476 ( V_681 ) || F_463 ( V_681 ) ) )
return - V_27 ;
if ( V_683 -> V_696 == V_697 ) {
if ( V_67 != NULL )
return F_450 ( V_67 , V_681 , V_683 ) ;
return 0 ;
}
if ( V_67 == NULL )
return - V_739 ;
switch ( V_683 -> V_696 ) {
case V_747 :
if ( ! ( V_742 -> V_748 & V_70 ) )
return - V_387 ;
break;
case V_749 :
if ( ! ( V_742 -> V_748 & V_218 ) )
return - V_387 ;
}
do {
V_289 = F_472 ( V_67 , V_681 , V_683 ) ;
if ( ( V_289 != - V_131 ) || F_476 ( V_681 ) )
break;
V_52 = F_435 ( V_52 ) ;
V_289 = - V_60 ;
if ( F_477 () )
break;
} while( V_289 < 0 );
return V_289 ;
}
int F_478 ( struct V_682 * V_685 , struct V_66 * V_67 , const T_8 * V_240 )
{
struct V_13 * V_14 = F_85 ( V_67 -> V_2 ) ;
int V_8 ;
V_8 = F_437 ( V_67 , V_685 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_462 ( V_67 , V_717 , V_685 , V_731 ) ;
return F_165 ( V_14 , V_67 , V_240 , V_8 ) ;
}
static void F_479 ( struct V_117 * V_118 , void * V_156 )
{
struct V_750 * V_158 = V_156 ;
struct V_13 * V_14 = V_158 -> V_14 ;
F_40 ( V_14 , & V_158 -> args . V_160 ,
& V_158 -> V_58 . V_161 , V_118 ) ;
V_158 -> args . V_691 . V_224 = V_14 -> V_64 -> V_225 ;
V_158 -> V_107 = V_155 ;
}
static void F_480 ( struct V_117 * V_118 , void * V_156 )
{
struct V_750 * V_158 = V_156 ;
struct V_13 * V_14 = V_158 -> V_14 ;
F_48 ( V_118 , & V_158 -> V_58 . V_161 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
F_37 ( V_14 , V_158 -> V_107 ) ;
break;
case - V_77 :
case - V_75 :
F_24 ( V_14 -> V_64 ) ;
break;
case - V_79 :
case - V_91 :
if ( F_241 ( V_118 , V_14 ,
NULL , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
}
static void F_481 ( void * V_156 )
{
struct V_750 * V_158 = V_156 ;
F_482 ( V_158 -> V_14 , V_158 -> V_690 ) ;
F_96 ( V_156 ) ;
}
static void
F_483 ( struct V_13 * V_14 , struct V_689 * V_690 )
{
struct V_750 * V_158 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_751 ] ,
} ;
if ( V_14 -> V_64 -> V_168 -> V_315 != 0 )
return;
V_158 = F_272 ( sizeof( * V_158 ) , V_286 ) ;
if ( ! V_158 )
return;
V_158 -> V_690 = V_690 ;
V_158 -> V_14 = V_14 ;
V_158 -> args . V_691 . V_224 = V_14 -> V_64 -> V_225 ;
V_158 -> args . V_691 . V_226 = V_690 -> V_694 . V_229 ;
V_158 -> args . V_691 . V_695 = V_14 -> V_695 ;
V_163 . V_297 = & V_158 -> args ;
V_163 . V_298 = & V_158 -> V_58 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_58 . V_161 , 0 ) ;
F_379 ( V_14 -> V_92 , & V_163 , 0 , & V_752 , V_158 ) ;
}
static int F_484 ( struct V_4 * V_4 , const char * V_753 ,
const void * V_588 , T_9 V_589 ,
int V_207 , int type )
{
if ( strcmp ( V_753 , L_57 ) != 0 )
return - V_27 ;
return F_401 ( V_4 -> V_47 , V_588 , V_589 ) ;
}
static int F_485 ( struct V_4 * V_4 , const char * V_753 ,
void * V_588 , T_9 V_589 , int type )
{
if ( strcmp ( V_753 , L_57 ) != 0 )
return - V_27 ;
return F_395 ( V_4 -> V_47 , V_588 , V_589 ) ;
}
static T_9 F_486 ( struct V_4 * V_4 , char * V_754 ,
T_9 V_755 , const char * V_230 ,
T_9 V_756 , int type )
{
T_9 V_12 = sizeof( V_757 ) ;
if ( ! F_382 ( F_85 ( V_4 -> V_47 ) ) )
return 0 ;
if ( V_754 && V_12 <= V_755 )
memcpy ( V_754 , V_757 , V_12 ) ;
return V_12 ;
}
static inline int F_487 ( struct V_13 * V_14 )
{
return V_14 -> V_95 & V_9 ;
}
static int F_488 ( struct V_4 * V_4 , const char * V_753 ,
const void * V_588 , T_9 V_589 ,
int V_207 , int type )
{
if ( F_489 ( V_753 ) )
return F_409 ( V_4 , V_588 , V_589 ) ;
return - V_614 ;
}
static int F_490 ( struct V_4 * V_4 , const char * V_753 ,
void * V_588 , T_9 V_589 , int type )
{
if ( F_489 ( V_753 ) )
return F_404 ( V_4 -> V_47 , V_588 , V_589 ) ;
return - V_614 ;
}
static T_9 F_491 ( struct V_4 * V_4 , char * V_754 ,
T_9 V_755 , const char * V_230 ,
T_9 V_756 , int type )
{
T_9 V_12 = 0 ;
if ( F_2 ( V_4 -> V_47 , V_9 ) ) {
V_12 = F_492 ( V_4 -> V_47 , NULL , 0 ) ;
if ( V_754 && V_12 <= V_755 )
F_492 ( V_4 -> V_47 , V_754 , V_12 ) ;
}
return V_12 ;
}
static void F_274 ( struct V_371 * V_372 )
{
if ( ! ( ( ( V_372 -> V_280 & V_758 ) ||
( V_372 -> V_280 & V_759 ) ) &&
( V_372 -> V_280 & V_465 ) &&
( V_372 -> V_280 & V_760 ) ) )
return;
V_372 -> V_280 |= V_318 | V_481 |
V_482 | V_761 ;
V_372 -> V_245 = V_323 | V_484 | V_485 ;
V_372 -> V_486 = 2 ;
}
static int F_493 ( struct V_56 * V_92 , struct V_2 * V_3 ,
const struct V_467 * V_230 ,
struct V_469 * V_762 ,
struct V_468 * V_468 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
T_1 V_231 [ 3 ] = {
[ 0 ] = V_763 | V_764 ,
} ;
struct V_765 args = {
. V_479 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
. V_468 = V_468 ,
. V_231 = V_231 ,
} ;
struct V_766 V_58 = {
. V_762 = V_762 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_767 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
int V_289 ;
F_8 ( L_58 , V_35 ) ;
if ( F_85 ( V_3 ) -> V_15 [ 1 ] & V_768 )
V_231 [ 1 ] |= V_768 ;
else
V_231 [ 0 ] |= V_46 ;
F_81 ( & V_762 -> V_372 ) ;
V_762 -> V_14 = V_14 ;
V_762 -> V_769 = 0 ;
V_289 = F_73 ( V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
F_8 ( L_59 , V_35 , V_289 ) ;
return V_289 ;
}
int F_273 ( struct V_56 * V_92 , struct V_2 * V_3 ,
const struct V_467 * V_230 ,
struct V_469 * V_762 ,
struct V_468 * V_468 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_493 ( V_92 , V_3 , V_230 ,
V_762 , V_468 ) ;
F_494 ( V_3 , V_230 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_495 ( struct V_2 * V_2 ,
struct V_469 * V_470 ,
struct V_468 * V_468 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_56 * V_57 = V_14 -> V_92 ;
T_1 V_231 [ 2 ] = {
[ 0 ] = V_763 | V_764 ,
} ;
struct V_765 args = {
. V_224 = V_14 -> V_64 -> V_225 ,
. V_234 = F_93 ( V_2 ) ,
. V_468 = V_468 ,
. V_231 = V_231 ,
. V_770 = 1 ,
. V_771 = 1 ,
} ;
struct V_766 V_58 = {
. V_762 = V_470 ,
. V_770 = 1 ,
. V_771 = 1 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_767 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
unsigned long V_548 = V_155 ;
int V_289 ;
F_81 ( & V_470 -> V_372 ) ;
V_470 -> V_14 = V_14 ;
V_470 -> V_769 = 0 ;
F_38 ( & args . V_160 , & V_58 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_57 , V_14 , & V_163 ,
& args . V_160 , & V_58 . V_161 ) ;
if ( V_289 )
return V_289 ;
F_37 ( V_14 , V_548 ) ;
return 0 ;
}
static int F_496 ( struct V_2 * V_2 ,
struct V_469 * V_470 ,
struct V_468 * V_468 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_56 * V_57 = V_14 -> V_92 ;
T_1 V_231 [ 2 ] = {
[ 0 ] = V_763 | V_764 ,
} ;
struct V_765 args = {
. V_234 = F_93 ( V_2 ) ,
. V_468 = V_468 ,
. V_231 = V_231 ,
. V_770 = 1 ,
} ;
struct V_766 V_58 = {
. V_762 = V_470 ,
. V_770 = 1 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_767 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_81 ( & V_470 -> V_372 ) ;
V_470 -> V_14 = V_14 ;
V_470 -> V_769 = 0 ;
F_38 ( & args . V_160 , & V_58 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_57 , V_14 , & V_163 ,
& args . V_160 , & V_58 . V_161 ) ;
if ( V_289 == V_772 &&
V_58 . V_161 . V_146 & V_773 )
V_289 = - V_79 ;
return V_289 ;
}
int F_497 ( struct V_2 * V_2 ,
struct V_469 * V_470 ,
struct V_468 * V_468 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_64 ;
const struct V_774 * V_775 =
V_65 -> V_168 -> V_776 ;
struct V_62 V_63 = { } ;
int V_289 ;
F_8 ( L_60 , V_35 ,
( unsigned long long ) V_14 -> V_466 . V_777 ,
( unsigned long long ) V_14 -> V_466 . V_778 ,
V_65 -> V_98 ) ;
F_498 ( F_93 ( V_2 ) , V_35 ) ;
do {
V_289 = V_775 -> V_779 ( V_2 , V_470 , V_468 , V_333 ) ;
if ( V_289 != - V_91 )
break;
F_20 ( V_14 , V_289 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_289 ;
}
static int F_499 ( struct V_2 * V_2 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_64 * V_65 = F_85 ( V_2 ) -> V_64 ;
struct V_56 * V_57 = V_14 -> V_92 ;
struct V_780 args = {
. V_234 = F_93 ( V_2 ) ,
. V_224 = V_65 -> V_225 ,
. V_771 = 1 ,
} ;
struct V_781 V_58 = {
. V_771 = 1 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_782 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
unsigned long V_548 = V_155 ;
int V_289 ;
V_58 . V_234 = F_500 () ;
if ( V_58 . V_234 == NULL )
return - V_127 ;
F_38 ( & args . V_160 , & V_58 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_57 , V_14 , & V_163 ,
& args . V_160 , & V_58 . V_161 ) ;
F_501 ( V_58 . V_234 ) ;
if ( V_289 )
return V_289 ;
F_33 ( V_65 , V_548 ) ;
return 0 ;
}
static int F_502 ( struct V_2 * V_2 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_56 * V_57 = V_14 -> V_92 ;
struct V_780 args = {
. V_234 = F_93 ( V_2 ) ,
} ;
struct V_781 V_58 = {
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_782 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
int V_289 ;
V_58 . V_234 = F_500 () ;
if ( V_58 . V_234 == NULL )
return - V_127 ;
F_38 ( & args . V_160 , & V_58 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_57 , V_14 , & V_163 ,
& args . V_160 , & V_58 . V_161 ) ;
F_501 ( V_58 . V_234 ) ;
if ( V_289 == V_772 &&
V_58 . V_161 . V_146 & V_773 )
V_289 = - V_79 ;
return V_289 ;
}
int F_503 ( struct V_2 * V_2 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_64 ;
const struct V_774 * V_775 =
V_65 -> V_168 -> V_776 ;
struct V_62 V_63 = { } ;
int V_289 ;
F_8 ( L_60 , V_35 ,
( unsigned long long ) V_14 -> V_466 . V_777 ,
( unsigned long long ) V_14 -> V_466 . V_778 ,
V_65 -> V_98 ) ;
F_498 ( F_93 ( V_2 ) , V_35 ) ;
do {
V_289 = V_775 -> V_783 ( V_2 , V_333 ) ;
if ( V_289 != - V_91 )
break;
F_20 ( V_14 , V_289 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_289 ;
}
static int F_504 ( struct V_2 * V_3 , const struct V_467 * V_230 , struct V_784 * V_460 , bool V_785 )
{
int V_289 ;
struct V_786 args = {
. V_479 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
} ;
struct V_787 V_58 = {
. V_460 = V_460 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_788 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
struct V_56 * V_57 = F_85 ( V_3 ) -> V_92 ;
struct V_299 * V_333 = NULL ;
if ( V_785 ) {
V_57 = F_85 ( V_3 ) -> V_64 -> V_102 ;
V_333 = F_505 ( F_85 ( V_3 ) -> V_64 ) ;
V_163 . V_299 = V_333 ;
}
F_8 ( L_61 , V_230 -> V_230 ) ;
F_249 ( F_85 ( V_3 ) -> V_64 ,
V_789 , & V_57 , & V_163 ) ;
V_289 = F_73 ( V_57 , F_85 ( V_3 ) , & V_163 , & args . V_160 ,
& V_58 . V_161 , 0 ) ;
F_8 ( L_62 , V_289 ) ;
if ( V_333 )
F_206 ( V_333 ) ;
return V_289 ;
}
int F_506 ( struct V_2 * V_3 , const struct V_467 * V_230 ,
struct V_784 * V_460 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( F_85 ( V_3 ) -> V_64 ) )
V_8 = F_504 ( V_3 , V_230 , V_460 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_504 ( V_3 , V_230 , V_460 , false ) ;
F_507 ( V_3 , V_230 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_508 ( T_1 V_207 )
{
if ( V_207 & ~ V_790 )
goto V_791;
if ( ( V_207 & V_792 ) &&
( V_207 & V_793 ) )
goto V_791;
if ( ! ( V_207 & ( V_794 ) ) )
goto V_791;
return V_347 ;
V_791:
return - V_795 ;
}
static bool
F_509 ( struct V_796 * V_797 ,
struct V_796 * V_798 )
{
if ( V_797 -> V_799 == V_798 -> V_799 &&
memcmp ( V_797 -> V_800 , V_798 -> V_800 , V_797 -> V_799 ) == 0 )
return true ;
return false ;
}
int F_510 ( struct V_64 * V_65 , struct V_299 * V_333 )
{
int V_289 ;
struct V_801 V_58 ;
struct V_162 V_163 = {
. V_294 =
& V_295 [ V_802 ] ,
. V_297 = V_65 ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
F_8 ( L_11 , V_35 ) ;
V_58 . V_135 = F_86 ( sizeof( struct V_134 ) , V_286 ) ;
if ( F_357 ( V_58 . V_135 == NULL ) ) {
V_289 = - V_127 ;
goto V_132;
}
V_289 = F_381 ( V_65 -> V_102 , & V_163 , V_586 ) ;
F_511 ( V_65 , V_289 ) ;
if ( V_289 == 0 ) {
if ( memcmp ( V_58 . V_135 -> V_803 . V_158 ,
V_65 -> V_88 -> V_803 . V_158 , V_804 ) ) {
F_8 ( L_63 , V_35 ) ;
V_289 = - V_36 ;
goto V_805;
}
if ( V_58 . V_3 != V_806 ) {
F_8 ( L_64 ,
V_35 ) ;
V_289 = - V_36 ;
goto V_805;
}
if ( V_58 . V_807 ) {
F_8 ( L_65 ,
V_35 ) ;
V_289 = - V_36 ;
goto V_805;
}
}
V_805:
F_96 ( V_58 . V_135 ) ;
V_132:
F_8 ( L_66 , V_35 , V_289 ) ;
return V_289 ;
}
static int F_512 ( struct V_64 * V_65 ,
struct V_808 * V_205 )
{
static const T_1 V_809 [ V_810 ] = {
[ 1 ] = 1 << ( V_811 - 32 ) |
1 << ( V_812 - 32 ) |
1 << ( V_813 - 32 ) |
1 << ( V_814 - 32 ) |
1 << ( V_815 - 32 )
} ;
unsigned int V_457 ;
if ( V_205 -> V_816 == V_817 ) {
F_513 ( V_818 , L_67 ) ;
for ( V_457 = 0 ; V_457 <= V_819 ; V_457 ++ ) {
if ( F_31 ( V_457 , V_205 -> V_820 . V_238 . V_821 ) )
F_513 ( V_818 , L_68 , V_457 ) ;
if ( F_31 ( V_457 , V_205 -> V_822 . V_238 . V_821 ) )
F_513 ( V_818 , L_69 , V_457 ) ;
}
for ( V_457 = 0 ; V_457 < V_810 ; V_457 ++ ) {
if ( V_205 -> V_820 . V_238 . V_823 [ V_457 ] & ~ V_809 [ V_457 ] ) {
F_513 ( V_818 , L_70 ) ;
return - V_27 ;
}
}
if ( F_31 ( V_811 , V_205 -> V_820 . V_238 . V_821 ) &&
F_31 ( V_813 , V_205 -> V_820 . V_238 . V_821 ) &&
F_31 ( V_814 , V_205 -> V_820 . V_238 . V_821 ) &&
F_31 ( V_815 , V_205 -> V_820 . V_238 . V_821 ) ) {
F_513 ( V_818 , L_71 ) ;
F_513 ( V_818 , L_72 ) ;
F_129 ( V_824 , & V_65 -> V_825 ) ;
} else {
F_513 ( V_818 , L_70 ) ;
return - V_27 ;
}
if ( F_31 ( V_826 , V_205 -> V_822 . V_238 . V_821 ) &&
F_31 ( V_827 , V_205 -> V_822 . V_238 . V_821 ) ) {
F_513 ( V_818 , L_73 ) ;
F_129 ( V_404 , & V_65 -> V_825 ) ;
}
if ( F_31 ( V_828 , V_205 -> V_822 . V_238 . V_821 ) &&
F_31 ( V_829 , V_205 -> V_822 . V_238 . V_821 ) ) {
F_513 ( V_818 , L_74 ) ;
F_129 ( V_789 , & V_65 -> V_825 ) ;
}
if ( F_31 ( V_830 , V_205 -> V_822 . V_238 . V_821 ) &&
F_31 ( V_831 , V_205 -> V_822 . V_238 . V_821 ) ) {
F_513 ( V_818 , L_75 ) ;
F_129 ( V_832 , & V_65 -> V_825 ) ;
}
if ( F_31 ( V_833 , V_205 -> V_822 . V_238 . V_821 ) ) {
F_513 ( V_818 , L_76 ) ;
F_129 ( V_834 , & V_65 -> V_825 ) ;
}
if ( F_31 ( V_835 , V_205 -> V_822 . V_238 . V_821 ) ) {
F_513 ( V_818 , L_77 ) ;
F_129 ( V_836 , & V_65 -> V_825 ) ;
}
}
return 0 ;
}
static int F_514 ( struct V_64 * V_65 , struct V_299 * V_333 ,
T_1 V_837 )
{
T_12 V_38 ;
struct V_838 args = {
. V_38 = & V_38 ,
. V_92 = V_65 ,
#ifdef F_515
. V_207 = V_839 |
V_840 |
V_841 ,
#else
. V_207 = V_839 |
V_840 ,
#endif
} ;
struct V_842 V_58 = {
0
} ;
int V_289 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_843 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
F_413 ( V_65 , & V_38 ) ;
args . V_844 = F_419 ( V_65 , args . V_226 ,
sizeof( args . V_226 ) ) ;
F_8 ( L_78 ,
V_65 -> V_102 -> V_103 -> V_670 -> V_671 ,
args . V_844 , args . V_226 ) ;
V_58 . V_845 = F_86 ( sizeof( struct V_846 ) ,
V_286 ) ;
if ( F_357 ( V_58 . V_845 == NULL ) ) {
V_289 = - V_127 ;
goto V_132;
}
V_58 . V_800 = F_86 ( sizeof( struct V_796 ) ,
V_286 ) ;
if ( F_357 ( V_58 . V_800 == NULL ) ) {
V_289 = - V_127 ;
goto V_847;
}
V_58 . V_848 = F_86 ( sizeof( struct V_849 ) , V_286 ) ;
if ( F_357 ( V_58 . V_848 == NULL ) ) {
V_289 = - V_127 ;
goto V_850;
}
switch ( V_837 ) {
case V_851 :
args . V_852 . V_816 = V_851 ;
break;
case V_817 :
args . V_852 = V_853 ;
break;
default:
F_516 ( 1 ) ;
V_289 = - V_27 ;
goto V_850;
}
V_289 = F_381 ( V_65 -> V_102 , & V_163 , V_586 ) ;
F_517 ( V_65 , V_289 ) ;
if ( V_289 == 0 )
V_289 = F_508 ( V_58 . V_207 ) ;
if ( V_289 == 0 )
V_289 = F_512 ( V_65 , & V_58 . V_852 ) ;
if ( V_289 == 0 ) {
V_65 -> V_225 = V_58 . V_224 ;
V_65 -> V_854 = ( V_58 . V_207 & ~ V_855 ) ;
if ( ! ( V_58 . V_207 & V_855 ) )
V_65 -> V_856 = V_58 . V_196 ;
F_96 ( V_65 -> V_857 ) ;
V_65 -> V_857 = V_58 . V_845 ;
V_58 . V_845 = NULL ;
F_96 ( V_65 -> V_858 ) ;
V_65 -> V_858 = V_58 . V_848 ;
if ( V_65 -> V_859 != NULL &&
! F_509 ( V_65 -> V_859 ,
V_58 . V_800 ) ) {
F_8 ( L_79 ,
V_35 ) ;
F_129 ( V_860 , & V_65 -> V_627 ) ;
F_96 ( V_65 -> V_859 ) ;
V_65 -> V_859 = NULL ;
}
if ( V_65 -> V_859 == NULL ) {
V_65 -> V_859 = V_58 . V_800 ;
goto V_132;
}
} else
F_96 ( V_58 . V_848 ) ;
V_847:
F_96 ( V_58 . V_845 ) ;
V_850:
F_96 ( V_58 . V_800 ) ;
V_132:
if ( V_65 -> V_858 != NULL )
F_8 ( L_80
L_81 ,
V_65 -> V_858 -> V_861 , V_65 -> V_858 -> V_230 ,
V_65 -> V_858 -> V_862 . V_863 ,
V_65 -> V_858 -> V_862 . V_864 ) ;
F_8 ( L_82 , V_289 ) ;
return V_289 ;
}
int F_518 ( struct V_64 * V_65 , struct V_299 * V_333 )
{
T_4 V_865 = V_65 -> V_102 -> V_103 -> V_104 ;
int V_289 ;
if ( V_865 == V_105 ||
V_865 == V_106 ) {
V_289 = F_514 ( V_65 , V_333 , V_817 ) ;
if ( ! V_289 )
return 0 ;
}
return F_514 ( V_65 , V_333 , V_851 ) ;
}
static int F_519 ( struct V_64 * V_65 ,
struct V_299 * V_333 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_866 ] ,
. V_297 = V_65 ,
. V_299 = V_333 ,
} ;
int V_289 ;
V_289 = F_381 ( V_65 -> V_102 , & V_163 , V_586 ) ;
F_520 ( V_65 , V_289 ) ;
if ( V_289 )
F_8 ( L_83
L_84 , V_289 , V_65 -> V_98 ) ;
return V_289 ;
}
static int F_521 ( struct V_64 * V_65 ,
struct V_299 * V_333 )
{
unsigned int V_867 ;
int V_53 ;
for ( V_867 = V_868 ; V_867 != 0 ; V_867 -- ) {
V_53 = F_519 ( V_65 , V_333 ) ;
switch ( V_53 ) {
case - V_91 :
case - V_869 :
F_167 ( 1 ) ;
break;
default:
return V_53 ;
}
}
return 0 ;
}
int F_522 ( struct V_64 * V_65 )
{
struct V_299 * V_333 ;
int V_53 = 0 ;
if ( V_65 -> V_168 -> V_315 < 1 )
goto V_132;
if ( V_65 -> V_854 == 0 )
goto V_132;
if ( V_65 -> V_870 )
goto V_132;
V_333 = F_505 ( V_65 ) ;
V_53 = F_521 ( V_65 , V_333 ) ;
if ( V_333 )
F_206 ( V_333 ) ;
switch ( V_53 ) {
case 0 :
case - V_77 :
V_65 -> V_854 = 0 ;
}
V_132:
return V_53 ;
}
static void F_523 ( struct V_117 * V_118 ,
void * V_156 )
{
struct V_871 * V_158 =
(struct V_871 * ) V_156 ;
F_8 ( L_11 , V_35 ) ;
F_61 ( V_158 -> V_65 -> V_88 ,
& V_158 -> args -> V_872 ,
& V_158 -> V_58 -> V_873 ,
V_118 ) ;
F_8 ( L_85 , V_35 ) ;
}
static void F_524 ( struct V_117 * V_118 , void * V_156 )
{
struct V_871 * V_158 =
(struct V_871 * ) V_156 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , & V_158 -> V_58 -> V_873 ) )
return;
switch ( V_118 -> V_150 ) {
case - V_91 :
case - V_90 :
F_8 ( L_86 , V_35 , V_118 -> V_150 ) ;
F_59 ( V_118 , V_55 ) ;
V_118 -> V_150 = 0 ;
case - V_93 :
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
int F_525 ( struct V_64 * V_65 , struct V_443 * V_544 )
{
struct V_117 * V_118 ;
struct V_874 args ;
struct V_875 V_58 = {
. V_876 = V_544 ,
} ;
struct V_871 V_158 = {
. args = & args ,
. V_58 = & V_58 ,
. V_65 = V_65 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_877 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
struct V_164 V_165 = {
. V_166 = V_65 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_878 ,
. V_170 = & V_158 ,
. V_207 = V_586 ,
} ;
int V_289 ;
F_38 ( & args . V_872 , & V_58 . V_873 , 0 ) ;
F_39 ( & args . V_872 ) ;
F_8 ( L_11 , V_35 ) ;
V_118 = F_70 ( & V_165 ) ;
if ( F_43 ( V_118 ) )
V_289 = F_71 ( V_118 ) ;
else {
V_289 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
}
F_8 ( L_87 , V_35 , V_289 ) ;
return V_289 ;
}
static void F_526 ( struct V_879 * args )
{
unsigned int V_880 , V_881 ;
V_880 = V_882 + V_883 ;
V_881 = V_882 + V_884 ;
args -> V_885 . V_880 = V_880 ;
args -> V_885 . V_881 = V_881 ;
args -> V_885 . V_886 = V_887 ;
args -> V_885 . V_888 = V_889 ;
F_8 ( L_88
L_89 ,
V_35 ,
args -> V_885 . V_880 , args -> V_885 . V_881 ,
args -> V_885 . V_886 , args -> V_885 . V_888 ) ;
args -> V_890 . V_880 = V_593 ;
args -> V_890 . V_881 = V_593 ;
args -> V_890 . V_891 = 0 ;
args -> V_890 . V_886 = V_892 ;
args -> V_890 . V_888 = 1 ;
F_8 ( L_90
L_91 ,
V_35 ,
args -> V_890 . V_880 , args -> V_890 . V_881 ,
args -> V_890 . V_891 , args -> V_890 . V_886 ,
args -> V_890 . V_888 ) ;
}
static int F_527 ( struct V_879 * args , struct V_134 * V_135 )
{
struct V_893 * V_894 = & args -> V_885 ;
struct V_893 * V_895 = & V_135 -> V_885 ;
if ( V_895 -> V_881 > V_894 -> V_881 )
return - V_27 ;
if ( V_895 -> V_886 < V_894 -> V_886 )
return - V_27 ;
if ( V_895 -> V_888 == 0 )
return - V_27 ;
if ( V_895 -> V_888 > V_896 )
V_895 -> V_888 = V_896 ;
return 0 ;
}
static int F_528 ( struct V_879 * args , struct V_134 * V_135 )
{
struct V_893 * V_894 = & args -> V_890 ;
struct V_893 * V_895 = & V_135 -> V_890 ;
if ( V_895 -> V_880 > V_894 -> V_880 )
return - V_27 ;
if ( V_895 -> V_881 < V_894 -> V_881 )
return - V_27 ;
if ( V_895 -> V_891 > V_894 -> V_891 )
return - V_27 ;
if ( V_895 -> V_886 != V_894 -> V_886 )
return - V_27 ;
if ( V_895 -> V_888 != V_894 -> V_888 )
return - V_27 ;
return 0 ;
}
static int F_529 ( struct V_879 * args ,
struct V_134 * V_135 )
{
int V_53 ;
V_53 = F_527 ( args , V_135 ) ;
if ( V_53 )
return V_53 ;
return F_528 ( args , V_135 ) ;
}
static int F_530 ( struct V_64 * V_65 ,
struct V_299 * V_333 )
{
struct V_134 * V_135 = V_65 -> V_88 ;
struct V_879 args = {
. V_92 = V_65 ,
. V_897 = V_898 ,
} ;
struct V_899 V_58 = {
. V_92 = V_65 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_900 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_526 ( & args ) ;
args . V_207 = ( V_901 | V_902 ) ;
V_289 = F_381 ( V_135 -> V_65 -> V_102 , & V_163 , V_586 ) ;
F_531 ( V_65 , V_289 ) ;
if ( ! V_289 ) {
V_289 = F_529 ( & args , V_135 ) ;
V_65 -> V_856 ++ ;
}
return V_289 ;
}
int F_532 ( struct V_64 * V_65 , struct V_299 * V_333 )
{
int V_289 ;
unsigned * V_903 ;
struct V_134 * V_135 = V_65 -> V_88 ;
F_8 ( L_92 , V_35 , V_65 , V_135 ) ;
V_289 = F_530 ( V_65 , V_333 ) ;
if ( V_289 )
goto V_132;
V_289 = F_533 ( V_135 ) ;
F_8 ( L_93 , V_289 ) ;
if ( V_289 )
goto V_132;
V_903 = ( unsigned * ) & V_135 -> V_803 . V_158 [ 0 ] ;
F_8 ( L_94 , V_35 ,
V_65 -> V_856 , V_903 [ 0 ] , V_903 [ 1 ] , V_903 [ 2 ] , V_903 [ 3 ] ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
return V_289 ;
}
int F_534 ( struct V_134 * V_135 ,
struct V_299 * V_333 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_904 ] ,
. V_297 = V_135 ,
. V_299 = V_333 ,
} ;
int V_289 = 0 ;
F_8 ( L_95 ) ;
if ( V_135 -> V_65 -> V_905 != V_906 )
return V_289 ;
V_289 = F_381 ( V_135 -> V_65 -> V_102 , & V_163 , V_586 ) ;
F_535 ( V_135 -> V_65 , V_289 ) ;
if ( V_289 )
F_8 ( L_96
L_97 , V_289 ) ;
F_8 ( L_98 ) ;
return V_289 ;
}
static void F_536 ( void * V_158 )
{
struct V_907 * V_156 = V_158 ;
struct V_64 * V_65 = V_156 -> V_65 ;
if ( F_371 ( & V_65 -> V_580 ) > 1 )
F_372 ( V_65 ) ;
F_373 ( V_65 ) ;
F_96 ( V_156 ) ;
}
static int F_537 ( struct V_117 * V_118 , struct V_64 * V_65 )
{
switch( V_118 -> V_150 ) {
case - V_91 :
F_59 ( V_118 , V_54 ) ;
return - V_131 ;
default:
F_24 ( V_65 ) ;
}
return 0 ;
}
static void F_538 ( struct V_117 * V_118 , void * V_158 )
{
struct V_907 * V_156 = V_158 ;
struct V_64 * V_65 = V_156 -> V_65 ;
if ( ! F_53 ( V_118 , V_118 -> V_309 . V_298 ) )
return;
F_539 ( V_65 , V_118 -> V_150 ) ;
if ( V_118 -> V_150 < 0 ) {
F_8 ( L_99 , V_35 , V_118 -> V_150 ) ;
if ( F_371 ( & V_65 -> V_580 ) == 1 )
goto V_132;
if ( F_537 ( V_118 , V_65 ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
F_8 ( L_100 , V_35 , V_118 -> V_309 . V_299 ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
}
static void F_540 ( struct V_117 * V_118 , void * V_158 )
{
struct V_907 * V_156 = V_158 ;
struct V_64 * V_65 = V_156 -> V_65 ;
struct V_110 * args ;
struct V_111 * V_58 ;
args = V_118 -> V_309 . V_297 ;
V_58 = V_118 -> V_309 . V_298 ;
F_61 ( V_65 -> V_88 , args , V_58 , V_118 ) ;
}
static struct V_117 * F_541 ( struct V_64 * V_65 ,
struct V_299 * V_333 ,
bool V_908 )
{
struct V_907 * V_156 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_909 ] ,
. V_299 = V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = V_65 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_910 ,
. V_207 = V_304 | V_586 ,
} ;
if ( ! F_378 ( & V_65 -> V_580 ) )
return F_44 ( - V_36 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_286 ) ;
if ( V_156 == NULL ) {
F_373 ( V_65 ) ;
return F_44 ( - V_127 ) ;
}
F_38 ( & V_156 -> args , & V_156 -> V_58 , 0 ) ;
if ( V_908 )
F_39 ( & V_156 -> args ) ;
V_163 . V_297 = & V_156 -> args ;
V_163 . V_298 = & V_156 -> V_58 ;
V_156 -> V_65 = V_65 ;
V_300 . V_170 = V_156 ;
return F_70 ( & V_300 ) ;
}
static int F_542 ( struct V_64 * V_65 , struct V_299 * V_333 , unsigned V_584 )
{
struct V_117 * V_118 ;
int V_53 = 0 ;
if ( ( V_584 & V_911 ) == 0 )
return - V_131 ;
V_118 = F_541 ( V_65 , V_333 , false ) ;
if ( F_43 ( V_118 ) )
V_53 = F_71 ( V_118 ) ;
else
F_460 ( V_118 ) ;
F_8 ( L_16 , V_35 , V_53 ) ;
return V_53 ;
}
static int F_543 ( struct V_64 * V_65 , struct V_299 * V_333 )
{
struct V_117 * V_118 ;
int V_53 ;
V_118 = F_541 ( V_65 , V_333 , true ) ;
if ( F_43 ( V_118 ) ) {
V_53 = F_71 ( V_118 ) ;
goto V_132;
}
V_53 = F_108 ( V_118 ) ;
if ( ! V_53 ) {
struct V_111 * V_58 = V_118 -> V_309 . V_298 ;
if ( V_118 -> V_150 == 0 )
F_544 ( V_65 , V_58 -> V_146 ) ;
V_53 = V_118 -> V_150 ;
}
F_72 ( V_118 ) ;
V_132:
F_8 ( L_16 , V_35 , V_53 ) ;
return V_53 ;
}
static void F_545 ( struct V_117 * V_118 , void * V_158 )
{
struct V_912 * V_156 = V_158 ;
F_61 ( V_156 -> V_65 -> V_88 ,
& V_156 -> V_375 . V_160 ,
& V_156 -> V_58 . V_161 ,
V_118 ) ;
}
static int F_546 ( struct V_117 * V_118 , struct V_64 * V_65 )
{
switch( V_118 -> V_150 ) {
case 0 :
case - V_913 :
case - V_23 :
break;
case - V_91 :
F_59 ( V_118 , V_54 ) ;
case - V_93 :
return - V_131 ;
default:
F_24 ( V_65 ) ;
}
return 0 ;
}
static void F_547 ( struct V_117 * V_118 , void * V_158 )
{
struct V_912 * V_156 = V_158 ;
struct V_64 * V_65 = V_156 -> V_65 ;
struct V_111 * V_58 = & V_156 -> V_58 . V_161 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , V_58 ) )
return;
F_548 ( V_65 , V_118 -> V_150 ) ;
if ( F_546 ( V_118 , V_65 ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
static void F_549 ( void * V_158 )
{
struct V_912 * V_156 = V_158 ;
F_96 ( V_156 ) ;
}
static int F_550 ( struct V_64 * V_65 ,
struct V_299 * V_333 )
{
struct V_912 * V_156 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_914 ] ,
. V_299 = V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = V_65 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_915 ,
. V_207 = V_304 ,
} ;
int V_289 = - V_127 ;
F_8 ( L_11 , V_35 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_286 ) ;
if ( V_156 == NULL )
goto V_132;
V_156 -> V_65 = V_65 ;
V_156 -> V_375 . V_916 = 0 ;
F_38 ( & V_156 -> V_375 . V_160 , & V_156 -> V_58 . V_161 , 0 ) ;
F_39 ( & V_156 -> V_375 . V_160 ) ;
V_163 . V_297 = & V_156 -> V_375 ;
V_163 . V_298 = & V_156 -> V_58 ;
V_300 . V_170 = V_156 ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) ) {
V_289 = F_71 ( V_118 ) ;
goto V_132;
}
V_289 = F_107 ( V_118 ) ;
if ( V_289 == 0 )
V_289 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
return 0 ;
V_132:
F_8 ( L_16 , V_35 , V_289 ) ;
return V_289 ;
}
static void
F_551 ( struct V_117 * V_118 , void * V_156 )
{
struct V_917 * V_918 = V_156 ;
struct V_13 * V_14 = F_85 ( V_918 -> args . V_2 ) ;
struct V_134 * V_135 = F_64 ( V_14 ) ;
F_8 ( L_11 , V_35 ) ;
if ( F_61 ( V_135 , & V_918 -> args . V_160 ,
& V_918 -> V_58 . V_161 , V_118 ) )
return;
if ( F_552 ( & V_918 -> args . V_240 ,
F_75 ( V_918 -> args . V_2 ) -> V_919 ,
V_918 -> args . V_284 -> V_67 ) ) {
F_553 ( V_118 , V_772 ) ;
}
}
static void F_554 ( struct V_117 * V_118 , void * V_156 )
{
struct V_917 * V_918 = V_156 ;
struct V_2 * V_2 = V_918 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_920 * V_921 ;
struct V_66 * V_67 = NULL ;
unsigned long V_922 , V_548 , V_923 ;
F_8 ( L_101 , V_35 , - V_118 -> V_150 ) ;
if ( ! F_53 ( V_118 , & V_918 -> V_58 . V_161 ) )
goto V_132;
switch ( V_118 -> V_150 ) {
case 0 :
goto V_132;
case - V_19 :
case - V_20 :
V_922 = F_555 ( V_118 -> V_924 ) ;
V_923 = V_918 -> args . V_107 + V_922 ;
V_548 = V_155 ;
if ( F_556 ( V_923 , V_548 ) ) {
unsigned long V_925 ;
V_925 = F_557 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_102 ,
V_35 , V_925 ) ;
F_59 ( V_118 , V_925 ) ;
V_118 -> V_150 = 0 ;
F_57 ( V_118 ) ;
goto V_132;
}
break;
case - V_75 :
case - V_74 :
F_34 ( & V_2 -> V_175 ) ;
V_921 = F_75 ( V_2 ) -> V_919 ;
if ( ! V_921 || F_432 ( & V_921 -> V_926 ) ) {
F_36 ( & V_2 -> V_175 ) ;
V_67 = V_918 -> args . V_284 -> V_67 ;
} else {
F_558 ( V_927 ) ;
F_559 ( V_921 , & V_927 , NULL ) ;
F_36 ( & V_2 -> V_175 ) ;
F_560 ( & V_927 ) ;
V_118 -> V_150 = 0 ;
F_57 ( V_118 ) ;
}
}
if ( F_241 ( V_118 , V_14 , V_67 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
}
static T_9 F_561 ( struct V_13 * V_14 )
{
T_1 V_881 = V_14 -> V_64 -> V_88 -> V_885 . V_881 ;
return F_562 ( 0 , V_881 ) ;
}
static void F_563 ( struct V_468 * * V_43 , T_9 V_928 )
{
int V_457 ;
if ( ! V_43 )
return;
for ( V_457 = 0 ; V_457 < V_928 ; V_457 ++ ) {
if ( ! V_43 [ V_457 ] )
break;
F_275 ( V_43 [ V_457 ] ) ;
}
F_96 ( V_43 ) ;
}
static struct V_468 * * F_564 ( T_9 V_928 , T_6 V_929 )
{
struct V_468 * * V_43 ;
int V_457 ;
V_43 = F_565 ( V_928 , sizeof( struct V_468 * ) , V_929 ) ;
if ( ! V_43 ) {
F_8 ( L_103 , V_35 , V_928 ) ;
return NULL ;
}
for ( V_457 = 0 ; V_457 < V_928 ; V_457 ++ ) {
V_43 [ V_457 ] = F_271 ( V_929 ) ;
if ( ! V_43 [ V_457 ] ) {
F_8 ( L_104 , V_35 ) ;
F_563 ( V_43 , V_928 ) ;
return NULL ;
}
}
return V_43 ;
}
static void F_566 ( void * V_156 )
{
struct V_917 * V_918 = V_156 ;
struct V_2 * V_2 = V_918 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_930 = F_561 ( V_14 ) ;
F_8 ( L_11 , V_35 ) ;
F_563 ( V_918 -> args . V_919 . V_43 , V_930 ) ;
F_567 ( F_75 ( V_2 ) -> V_919 ) ;
F_164 ( V_918 -> args . V_284 ) ;
F_96 ( V_156 ) ;
F_8 ( L_85 , V_35 ) ;
}
struct V_931 *
F_568 ( struct V_917 * V_918 , T_6 V_929 )
{
struct V_2 * V_2 = V_918 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_930 = F_561 ( V_14 ) ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_932 ] ,
. V_297 = & V_918 -> args ,
. V_298 = & V_918 -> V_58 ,
. V_299 = V_918 -> V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_933 ,
. V_170 = V_918 ,
. V_207 = V_304 ,
} ;
struct V_931 * V_934 = NULL ;
int V_289 = 0 ;
F_8 ( L_11 , V_35 ) ;
V_918 -> args . V_919 . V_43 = F_564 ( V_930 , V_929 ) ;
if ( ! V_918 -> args . V_919 . V_43 ) {
F_566 ( V_918 ) ;
return F_44 ( - V_127 ) ;
}
V_918 -> args . V_919 . V_495 = V_930 * V_593 ;
V_918 -> args . V_107 = V_155 ;
V_918 -> V_58 . V_935 = & V_918 -> args . V_919 ;
V_918 -> V_58 . V_161 . V_116 = NULL ;
F_38 ( & V_918 -> args . V_160 , & V_918 -> V_58 . V_161 , 0 ) ;
F_569 ( F_75 ( V_2 ) -> V_919 ) ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_251 ( V_118 ) ;
V_289 = F_107 ( V_118 ) ;
if ( V_289 == 0 )
V_289 = V_118 -> V_150 ;
F_570 ( V_918 -> args . V_284 ,
& V_918 -> args . V_936 ,
& V_918 -> V_58 . V_936 ,
V_289 ) ;
if ( V_289 == 0 && V_918 -> V_58 . V_935 -> V_12 )
V_934 = F_571 ( V_918 ) ;
F_72 ( V_118 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
if ( V_289 )
return F_44 ( V_289 ) ;
return V_934 ;
}
static void
F_572 ( struct V_117 * V_118 , void * V_156 )
{
struct V_937 * V_938 = V_156 ;
F_8 ( L_11 , V_35 ) ;
F_61 ( V_938 -> V_65 -> V_88 ,
& V_938 -> args . V_160 ,
& V_938 -> V_58 . V_161 ,
V_118 ) ;
}
static void F_573 ( struct V_117 * V_118 , void * V_156 )
{
struct V_937 * V_938 = V_156 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , & V_938 -> V_58 . V_161 ) )
return;
V_14 = F_85 ( V_938 -> args . V_2 ) ;
switch ( V_118 -> V_150 ) {
default:
V_118 -> V_150 = 0 ;
case 0 :
break;
case - V_91 :
if ( F_241 ( V_118 , V_14 , NULL , NULL ) != - V_131 )
break;
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
static void F_574 ( void * V_156 )
{
struct V_937 * V_938 = V_156 ;
struct V_920 * V_921 = V_938 -> args . V_919 ;
F_8 ( L_11 , V_35 ) ;
F_34 ( & V_921 -> V_939 -> V_175 ) ;
if ( V_938 -> V_58 . V_940 )
F_575 ( V_921 , & V_938 -> V_58 . V_240 , true ) ;
V_921 -> V_941 -- ;
F_36 ( & V_921 -> V_939 -> V_175 ) ;
F_567 ( V_938 -> args . V_919 ) ;
F_96 ( V_156 ) ;
F_8 ( L_85 , V_35 ) ;
}
int F_576 ( struct V_937 * V_938 )
{
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_942 ] ,
. V_297 = & V_938 -> args ,
. V_298 = & V_938 -> V_58 ,
. V_299 = V_938 -> V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = F_85 ( V_938 -> args . V_2 ) -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_943 ,
. V_170 = V_938 ,
} ;
int V_289 ;
F_8 ( L_11 , V_35 ) ;
F_38 ( & V_938 -> args . V_160 , & V_938 -> V_58 . V_161 , 1 ) ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_289 = V_118 -> V_150 ;
F_577 ( V_938 -> args . V_2 , V_289 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
F_72 ( V_118 ) ;
return V_289 ;
}
static int
F_578 ( struct V_13 * V_14 ,
struct V_944 * V_945 ,
struct V_299 * V_333 )
{
struct V_946 args = {
. V_945 = V_945 ,
} ;
struct V_947 V_58 = {
. V_945 = V_945 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_948 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_8 ( L_11 , V_35 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_58 . V_161 , 0 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
return V_289 ;
}
int F_579 ( struct V_13 * V_14 ,
struct V_944 * V_945 ,
struct V_299 * V_333 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_578 ( V_14 , V_945 , V_333 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static void F_580 ( struct V_117 * V_118 , void * V_156 )
{
struct V_949 * V_158 = V_156 ;
struct V_13 * V_14 = F_85 ( V_158 -> args . V_2 ) ;
struct V_134 * V_135 = F_64 ( V_14 ) ;
F_61 ( V_135 ,
& V_158 -> args . V_160 ,
& V_158 -> V_58 . V_161 ,
V_118 ) ;
}
static void
F_581 ( struct V_117 * V_118 , void * V_156 )
{
struct V_949 * V_158 = V_156 ;
struct V_13 * V_14 = F_85 ( V_158 -> args . V_2 ) ;
if ( ! F_53 ( V_118 , & V_158 -> V_58 . V_161 ) )
return;
switch ( V_118 -> V_150 ) {
case - V_72 :
case - V_950 :
case - V_951 :
case - V_90 :
V_118 -> V_150 = 0 ;
case 0 :
break;
default:
if ( F_241 ( V_118 , V_14 , NULL , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
}
static void F_582 ( void * V_156 )
{
struct V_949 * V_158 = V_156 ;
F_583 ( V_158 ) ;
F_360 ( V_158 -> args . V_2 ,
V_158 -> V_58 . V_372 ) ;
F_206 ( V_158 -> V_333 ) ;
F_96 ( V_158 ) ;
}
int
F_584 ( struct V_949 * V_158 , bool V_952 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_953 ] ,
. V_297 = & V_158 -> args ,
. V_298 = & V_158 -> V_58 ,
. V_299 = V_158 -> V_333 ,
} ;
struct V_164 V_300 = {
. V_118 = & V_158 -> V_118 ,
. V_166 = F_290 ( V_158 -> args . V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_954 ,
. V_170 = V_158 ,
. V_207 = V_304 ,
} ;
struct V_117 * V_118 ;
int V_289 = 0 ;
F_8 ( L_105
L_106 ,
V_158 -> V_118 . V_955 , V_952 ,
V_158 -> args . V_956 ,
V_158 -> args . V_2 -> V_957 ) ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_58 . V_161 , 1 ) ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
if ( V_952 == false )
goto V_132;
V_289 = F_107 ( V_118 ) ;
if ( V_289 != 0 )
goto V_132;
V_289 = V_118 -> V_150 ;
F_585 ( V_158 -> args . V_2 , V_289 ) ;
V_132:
F_8 ( L_107 , V_35 , V_289 ) ;
F_72 ( V_118 ) ;
return V_289 ;
}
static int
F_586 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_444 ,
struct V_784 * V_460 , bool V_785 )
{
struct V_958 args = {
. V_959 = V_960 ,
} ;
struct V_787 V_58 = {
. V_460 = V_460 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_961 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
} ;
struct V_56 * V_57 = V_14 -> V_92 ;
struct V_299 * V_333 = NULL ;
int V_289 ;
if ( V_785 ) {
V_57 = V_14 -> V_64 -> V_102 ;
V_333 = F_505 ( V_14 -> V_64 ) ;
V_163 . V_299 = V_333 ;
}
F_8 ( L_11 , V_35 ) ;
V_289 = F_73 ( V_57 , V_14 , & V_163 , & args . V_160 ,
& V_58 . V_161 , 0 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
if ( V_333 )
F_206 ( V_333 ) ;
return V_289 ;
}
static int
F_587 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_444 , struct V_784 * V_460 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( V_14 -> V_64 ) )
V_8 = F_586 ( V_14 , V_410 , V_444 ,
V_460 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_586 ( V_14 , V_410 , V_444 ,
V_460 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_962 :
goto V_132;
default:
V_8 = F_20 ( V_14 , V_8 , & V_63 ) ;
}
} while ( V_63 . V_68 );
V_132:
return V_8 ;
}
static int
F_588 ( struct V_13 * V_14 , struct V_409 * V_410 ,
struct V_443 * V_444 )
{
int V_8 ;
struct V_468 * V_468 ;
T_4 V_101 = V_963 ;
struct V_784 * V_460 ;
struct V_964 * V_965 ;
int V_457 ;
V_468 = F_271 ( V_363 ) ;
if ( ! V_468 ) {
V_8 = - V_127 ;
goto V_132;
}
V_460 = F_385 ( V_468 ) ;
V_8 = F_587 ( V_14 , V_410 , V_444 , V_460 ) ;
if ( V_8 == - V_22 || V_8 == - V_962 ) {
V_8 = F_262 ( V_14 , V_410 , V_444 ) ;
goto V_966;
}
if ( V_8 )
goto V_966;
for ( V_457 = 0 ; V_457 < V_460 -> V_967 ; V_457 ++ ) {
V_965 = & V_460 -> V_460 [ V_457 ] ;
switch ( V_965 -> V_101 ) {
case V_456 :
case V_455 :
case V_968 :
V_101 = F_589 ( V_965 -> V_101 ,
& V_965 -> V_969 ) ;
break;
default:
V_101 = V_963 ;
break;
}
if ( ! F_590 ( & V_14 -> V_458 , V_101 ) )
V_101 = V_963 ;
if ( V_101 != V_963 ) {
V_8 = F_260 ( V_14 , V_410 ,
V_444 , V_101 ) ;
if ( ! V_8 )
break;
}
}
if ( V_101 == V_963 )
V_8 = - V_24 ;
V_966:
F_399 ( V_468 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_132:
return V_8 ;
}
static int F_591 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_299 * V_333 )
{
int V_289 ;
struct V_970 args = {
. V_240 = V_240 ,
} ;
struct V_971 V_58 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_972 ] ,
. V_297 = & args ,
. V_298 = & V_58 ,
. V_299 = V_333 ,
} ;
struct V_56 * V_166 = V_14 -> V_92 ;
F_249 ( V_14 -> V_64 , V_832 ,
& V_166 , & V_163 ) ;
F_8 ( L_108 , V_240 ) ;
F_38 ( & args . V_160 , & V_58 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_166 , V_14 , & V_163 ,
& args . V_160 , & V_58 . V_161 ) ;
if ( V_289 != V_347 ) {
F_8 ( L_109 , V_289 ) ;
return V_289 ;
}
F_8 ( L_110 , - V_58 . V_289 ) ;
return - V_58 . V_289 ;
}
static int F_203 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_299 * V_333 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_591 ( V_14 , V_240 , V_333 ) ;
if ( V_8 != - V_91 )
break;
F_20 ( V_14 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static void F_592 ( struct V_117 * V_118 , void * V_156 )
{
struct V_973 * V_158 = V_156 ;
F_61 ( F_64 ( V_158 -> V_14 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_58 . V_161 ,
V_118 ) ;
}
static void F_593 ( struct V_117 * V_118 , void * V_156 )
{
struct V_973 * V_158 = V_156 ;
F_53 ( V_118 , & V_158 -> V_58 . V_161 ) ;
switch ( V_118 -> V_150 ) {
case - V_91 :
if ( F_241 ( V_118 , V_158 -> V_14 , NULL , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
}
static void F_594 ( void * V_156 )
{
F_96 ( V_156 ) ;
}
static struct V_117 * F_595 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_299 * V_333 ,
bool V_974 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_975 ] ,
. V_299 = V_333 ,
} ;
struct V_164 V_165 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_976 ,
. V_207 = V_304 ,
} ;
struct V_973 * V_158 ;
F_249 ( V_14 -> V_64 , V_832 ,
& V_165 . V_166 , & V_163 ) ;
F_8 ( L_111 , V_240 ) ;
V_158 = F_272 ( sizeof( * V_158 ) , V_286 ) ;
if ( ! V_158 )
return F_44 ( - V_127 ) ;
V_158 -> V_14 = V_14 ;
F_123 ( & V_158 -> args . V_240 , V_240 ) ;
V_165 . V_170 = V_158 ;
V_163 . V_297 = & V_158 -> args ;
V_163 . V_298 = & V_158 -> V_58 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_58 . V_161 , 0 ) ;
if ( V_974 )
F_39 ( & V_158 -> args . V_160 ) ;
return F_70 ( & V_165 ) ;
}
static int F_205 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_299 * V_333 )
{
struct V_117 * V_118 ;
int V_53 ;
V_118 = F_595 ( V_14 , V_240 , V_333 , true ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_53 = F_108 ( V_118 ) ;
if ( ! V_53 )
V_53 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
return V_53 ;
}
static void
F_596 ( struct V_13 * V_14 , struct V_689 * V_690 )
{
struct V_117 * V_118 ;
struct V_299 * V_333 = V_690 -> V_706 -> V_215 -> V_274 ;
V_118 = F_595 ( V_14 , & V_690 -> V_707 , V_333 , false ) ;
F_482 ( V_14 , V_690 ) ;
if ( F_43 ( V_118 ) )
return;
F_72 ( V_118 ) ;
}
static bool F_597 ( const T_8 * V_977 ,
const T_8 * V_978 )
{
if ( memcmp ( V_977 -> V_979 , V_978 -> V_979 , sizeof( V_977 -> V_979 ) ) != 0 )
return false ;
if ( V_977 -> V_196 == V_978 -> V_196 )
return true ;
if ( V_977 -> V_196 == 0 || V_978 -> V_196 == 0 )
return true ;
return false ;
}
static bool F_598 ( const T_8 * V_977 ,
const T_8 * V_978 )
{
return F_134 ( V_977 , V_978 ) ;
}
