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
static int F_15 ( struct V_52 * V_53 , long * V_54 )
{
int V_55 = 0 ;
F_16 () ;
if ( * V_54 <= 0 )
* V_54 = V_56 ;
if ( * V_54 > V_57 )
* V_54 = V_57 ;
F_17 ( * V_54 ) ;
if ( F_18 ( V_58 ) )
V_55 = - V_59 ;
* V_54 <<= 1 ;
return V_55 ;
}
static int F_19 ( struct V_13 * V_14 , int V_60 , struct V_61 * V_62 )
{
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_65 * V_66 = V_62 -> V_66 ;
struct V_2 * V_2 = V_62 -> V_2 ;
int V_67 = V_60 ;
V_62 -> V_68 = 0 ;
switch( V_60 ) {
case 0 :
return 0 ;
case - V_69 :
if ( V_2 && F_20 ( V_2 , V_70 ) ) {
F_21 ( V_2 ) ;
V_62 -> V_68 = 1 ;
return 0 ;
}
if ( V_66 == NULL )
break;
V_67 = F_22 ( V_14 , V_66 ) ;
if ( V_67 < 0 )
break;
goto V_71;
case - V_72 :
case - V_73 :
case - V_74 :
if ( V_2 != NULL && F_20 ( V_2 , V_70 ) ) {
F_23 ( V_2 ) ;
V_62 -> V_68 = 1 ;
break;
}
if ( V_66 == NULL )
break;
V_67 = F_22 ( V_14 , V_66 ) ;
if ( V_67 < 0 )
break;
goto V_71;
case - V_75 :
if ( V_66 != NULL ) {
V_67 = F_22 ( V_14 , V_66 ) ;
if ( V_67 < 0 )
break;
}
case - V_76 :
case - V_77 :
F_24 ( V_64 ) ;
goto V_71;
case - V_78 :
V_67 = F_25 ( V_14 ) ;
if ( V_67 < 0 )
break;
goto V_71;
case - V_79 :
F_26 ( V_64 ) ;
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
V_60 ) ;
F_28 ( V_64 -> V_88 , V_60 ) ;
goto V_71;
#endif
case - V_33 :
if ( V_62 -> V_54 > V_89 ) {
V_67 = - V_34 ;
break;
}
case - V_90 :
case - V_91 :
V_67 = F_15 ( V_14 -> V_92 , & V_62 -> V_54 ) ;
if ( V_67 != 0 )
break;
case - V_93 :
case - V_94 :
V_62 -> V_68 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_95 & V_96 ) {
V_14 -> V_95 &= ~ V_96 ;
V_62 -> V_68 = 1 ;
F_29 ( V_97 L_5
L_6
L_7
L_8 ,
V_14 -> V_63 -> V_98 ) ;
}
}
return F_7 ( V_67 ) ;
V_71:
V_67 = F_30 ( V_64 ) ;
if ( F_31 ( V_99 , & V_14 -> V_100 ) )
return - V_36 ;
if ( V_67 == 0 )
V_62 -> V_68 = 1 ;
return V_67 ;
}
static bool F_32 ( struct V_63 * V_64 )
{
T_4 V_101 = V_64 -> V_102 -> V_103 -> V_104 ;
if ( V_101 == V_105 ||
V_101 == V_106 )
return true ;
return false ;
}
static void F_33 ( struct V_63 * V_64 , unsigned long V_107 )
{
F_34 ( & V_64 -> V_108 ) ;
if ( F_35 ( V_64 -> V_109 , V_107 ) )
V_64 -> V_109 = V_107 ;
F_36 ( & V_64 -> V_108 ) ;
}
static void F_37 ( const struct V_13 * V_14 , unsigned long V_107 )
{
F_33 ( V_14 -> V_63 , V_107 ) ;
}
static void F_38 ( struct V_110 * args ,
struct V_111 * V_55 , int V_112 )
{
args -> V_113 = NULL ;
args -> V_114 = V_112 ;
args -> V_115 = 0 ;
V_55 -> V_116 = NULL ;
}
static void F_39 ( struct V_110 * args )
{
args -> V_115 = 1 ;
}
static int F_40 ( const struct V_13 * V_14 ,
struct V_110 * args ,
struct V_111 * V_55 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 = V_14 -> V_63 -> V_121 ;
struct V_122 * V_123 ;
if ( V_55 -> V_116 != NULL )
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
V_55 -> V_116 = V_123 ;
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
struct V_111 * V_55 )
{
struct V_122 * V_123 = V_55 -> V_116 ;
struct V_119 * V_120 ;
if ( V_123 == NULL )
goto V_132;
V_120 = V_123 -> V_133 ;
F_34 ( & V_120 -> V_125 ) ;
if ( ! F_49 ( V_120 , V_123 ) )
F_50 ( V_120 , V_123 ) ;
F_36 ( & V_120 -> V_125 ) ;
V_55 -> V_116 = NULL ;
V_132:
return 1 ;
}
static void F_51 ( struct V_111 * V_55 )
{
struct V_134 * V_135 ;
struct V_119 * V_120 ;
struct V_122 * V_123 = V_55 -> V_116 ;
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
V_55 -> V_116 = NULL ;
if ( V_136 )
F_52 ( V_135 -> V_64 ) ;
}
int F_53 ( struct V_117 * V_118 , struct V_111 * V_55 )
{
struct V_134 * V_135 ;
struct V_122 * V_123 = V_55 -> V_116 ;
struct V_63 * V_64 ;
bool V_141 = false ;
int V_67 = 1 ;
if ( V_123 == NULL )
goto V_142;
if ( ! F_54 ( V_118 ) )
goto V_132;
V_135 = V_123 -> V_133 -> V_135 ;
if ( V_123 -> V_141 ) {
V_123 -> V_141 = 0 ;
V_141 = true ;
}
F_55 ( V_135 , V_55 ) ;
switch ( V_55 -> V_143 ) {
case 0 :
++ V_123 -> V_144 ;
V_64 = V_135 -> V_64 ;
F_33 ( V_64 , V_55 -> V_145 ) ;
if ( V_55 -> V_146 != 0 )
F_24 ( V_64 ) ;
F_56 ( V_123 -> V_133 , V_123 , V_55 ) ;
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
F_8 ( L_10 , V_35 , V_55 -> V_143 ) ;
F_51 ( V_55 ) ;
V_142:
return V_67 ;
V_149:
if ( F_57 ( V_118 ) ) {
V_118 -> V_150 = 0 ;
V_67 = 0 ;
}
goto V_132;
V_148:
if ( ! F_58 ( V_118 ) )
goto V_132;
F_59 ( V_118 , V_57 ) ;
return 0 ;
}
static int F_60 ( struct V_117 * V_118 ,
struct V_111 * V_55 )
{
if ( V_55 -> V_116 == NULL )
return 1 ;
if ( ! V_55 -> V_116 -> V_133 -> V_135 )
return F_48 ( V_118 , V_55 ) ;
return F_53 ( V_118 , V_55 ) ;
}
int F_61 ( struct V_134 * V_135 ,
struct V_110 * args ,
struct V_111 * V_55 ,
struct V_117 * V_118 )
{
struct V_122 * V_123 ;
struct V_119 * V_120 ;
F_8 ( L_11 , V_35 ) ;
if ( V_55 -> V_116 != NULL )
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
V_55 -> V_116 = V_123 ;
V_55 -> V_145 = V_155 ;
V_55 -> V_146 = 0 ;
V_55 -> V_143 = 1 ;
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
struct V_111 * V_55 ,
struct V_117 * V_118 )
{
struct V_134 * V_135 = F_64 ( V_14 ) ;
int V_67 = 0 ;
if ( ! V_135 )
return F_40 ( V_14 , args , V_55 , V_118 ) ;
F_8 ( L_15 ,
V_35 , V_135 -> V_64 , V_135 , V_55 -> V_116 ?
V_55 -> V_116 -> V_147 : V_140 ) ;
V_67 = F_61 ( V_135 , args , V_55 , V_118 ) ;
F_8 ( L_16 , V_35 , V_67 ) ;
return V_67 ;
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
struct V_111 * V_55 ,
struct V_117 * V_118 )
{
return F_40 ( V_14 , args , V_55 , V_118 ) ;
}
static int F_60 ( struct V_117 * V_118 ,
struct V_111 * V_55 )
{
return F_48 ( V_118 , V_55 ) ;
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
static int F_69 ( struct V_52 * V_53 ,
struct V_13 * V_14 ,
struct V_162 * V_163 ,
struct V_110 * args ,
struct V_111 * V_55 )
{
int V_67 ;
struct V_117 * V_118 ;
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_157 V_158 = {
. V_159 = V_14 ,
. V_160 = args ,
. V_161 = V_55 ,
} ;
struct V_164 V_165 = {
. V_166 = V_53 ,
. V_162 = V_163 ,
. V_167 = V_64 -> V_168 -> V_169 ,
. V_170 = & V_158
} ;
V_118 = F_70 ( & V_165 ) ;
if ( F_43 ( V_118 ) )
V_67 = F_71 ( V_118 ) ;
else {
V_67 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
}
return V_67 ;
}
static
int F_73 ( struct V_52 * V_53 ,
struct V_13 * V_14 ,
struct V_162 * V_163 ,
struct V_110 * args ,
struct V_111 * V_55 ,
int V_112 )
{
F_38 ( args , V_55 , V_112 ) ;
return F_69 ( V_53 , V_14 , V_163 , args , V_55 ) ;
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
int V_8 , struct V_61 * V_62 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_95 & V_183 ) )
return false ;
V_14 -> V_95 &= ~ V_183 ;
V_62 -> V_68 = 1 ;
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
V_42 -> V_197 . V_224 = V_14 -> V_63 -> V_225 ;
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
V_237 [ 1 ] = V_58 -> V_239 ;
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
if ( V_42 -> V_66 != NULL )
F_101 ( V_42 -> V_66 ) ;
F_102 ( V_42 -> V_215 ) ;
F_95 ( V_42 -> V_195 ) ;
F_97 ( V_42 -> V_3 ) ;
F_97 ( V_42 -> V_4 ) ;
F_103 ( V_243 ) ;
F_104 ( & V_42 -> V_194 ) ;
F_96 ( V_42 ) ;
}
static void F_105 ( struct V_192 * V_42 )
{
if ( V_42 != NULL )
F_106 ( & V_42 -> V_241 , F_98 ) ;
}
static int F_107 ( struct V_117 * V_118 )
{
int V_67 ;
V_67 = F_108 ( V_118 ) ;
return V_67 ;
}
static int F_109 ( struct V_65 * V_66 , T_5 V_244 , int V_245 )
{
int V_67 = 0 ;
if ( V_245 & ( V_219 | V_246 ) )
goto V_132;
switch ( V_244 & ( V_70 | V_218 ) ) {
case V_70 :
V_67 |= F_31 ( V_247 , & V_66 -> V_207 ) != 0
&& V_66 -> V_248 != 0 ;
break;
case V_218 :
V_67 |= F_31 ( V_249 , & V_66 -> V_207 ) != 0
&& V_66 -> V_250 != 0 ;
break;
case V_70 | V_218 :
V_67 |= F_31 ( V_251 , & V_66 -> V_207 ) != 0
&& V_66 -> V_252 != 0 ;
}
V_132:
return V_67 ;
}
static int F_110 ( struct V_253 * V_254 , T_5 V_206 )
{
if ( V_254 == NULL )
return 0 ;
if ( ( V_254 -> type & V_206 ) != V_206 )
return 0 ;
if ( F_31 ( V_255 , & V_254 -> V_207 ) )
return 0 ;
if ( F_31 ( V_256 , & V_254 -> V_207 ) )
return 0 ;
F_111 ( V_254 ) ;
return 1 ;
}
static void F_112 ( struct V_65 * V_66 , T_5 V_206 )
{
switch ( V_206 ) {
case V_218 :
V_66 -> V_250 ++ ;
break;
case V_70 :
V_66 -> V_248 ++ ;
break;
case V_70 | V_218 :
V_66 -> V_252 ++ ;
}
F_113 ( V_66 , V_66 -> V_66 | V_206 ) ;
}
static void F_114 ( struct V_65 * V_66 , T_8 * V_240 , T_5 V_206 )
{
if ( F_31 ( V_257 , & V_66 -> V_207 ) == 0 )
F_115 ( & V_66 -> V_240 , V_240 ) ;
F_115 ( & V_66 -> V_258 , V_240 ) ;
F_116 ( V_259 , & V_66 -> V_207 ) ;
switch ( V_206 ) {
case V_70 :
F_116 ( V_247 , & V_66 -> V_207 ) ;
break;
case V_218 :
F_116 ( V_249 , & V_66 -> V_207 ) ;
break;
case V_70 | V_218 :
F_116 ( V_251 , & V_66 -> V_207 ) ;
}
}
static void F_117 ( struct V_65 * V_66 , T_8 * V_240 , T_5 V_206 )
{
F_118 ( & V_66 -> V_260 ) ;
F_114 ( V_66 , V_240 , V_206 ) ;
F_119 ( & V_66 -> V_260 ) ;
}
static void F_120 ( struct V_65 * V_66 , T_8 * V_258 , const T_8 * V_261 , T_5 V_206 )
{
F_118 ( & V_66 -> V_260 ) ;
if ( V_261 != NULL ) {
F_115 ( & V_66 -> V_240 , V_261 ) ;
F_116 ( V_257 , & V_66 -> V_207 ) ;
}
if ( V_258 != NULL )
F_114 ( V_66 , V_258 , V_206 ) ;
F_119 ( & V_66 -> V_260 ) ;
F_34 ( & V_66 -> V_215 -> V_262 ) ;
F_112 ( V_66 , V_206 ) ;
F_36 ( & V_66 -> V_215 -> V_262 ) ;
}
static int F_121 ( struct V_65 * V_66 , T_8 * V_258 , T_8 * V_254 , T_5 V_206 )
{
struct V_173 * V_174 = F_75 ( V_66 -> V_2 ) ;
struct V_253 * V_263 ;
int V_67 = 0 ;
V_206 &= ( V_70 | V_218 ) ;
F_122 () ;
V_263 = F_123 ( V_174 -> V_254 ) ;
if ( V_263 == NULL )
goto V_264;
F_34 ( & V_263 -> V_265 ) ;
if ( F_123 ( V_174 -> V_254 ) != V_263 ||
F_31 ( V_256 , & V_263 -> V_207 ) ||
( V_263 -> type & V_206 ) != V_206 )
goto V_266;
if ( V_254 == NULL )
V_254 = & V_263 -> V_240 ;
else if ( ! F_124 ( & V_263 -> V_240 , V_254 ) )
goto V_266;
F_111 ( V_263 ) ;
F_120 ( V_66 , V_258 , & V_263 -> V_240 , V_206 ) ;
V_67 = 1 ;
V_266:
F_36 ( & V_263 -> V_265 ) ;
V_264:
F_125 () ;
if ( ! V_67 && V_258 != NULL ) {
F_120 ( V_66 , V_258 , NULL , V_206 ) ;
V_67 = 1 ;
}
return V_67 ;
}
static void F_126 ( struct V_2 * V_2 , T_5 V_206 )
{
struct V_253 * V_254 ;
F_122 () ;
V_254 = F_123 ( F_75 ( V_2 ) -> V_254 ) ;
if ( V_254 == NULL || ( V_254 -> type & V_206 ) == V_206 ) {
F_125 () ;
return;
}
F_125 () ;
F_21 ( V_2 ) ;
}
static struct V_65 * F_127 ( struct V_192 * V_267 )
{
struct V_65 * V_66 = V_267 -> V_66 ;
struct V_173 * V_174 = F_75 ( V_66 -> V_2 ) ;
struct V_253 * V_254 ;
int V_245 = V_267 -> V_197 . V_217 ;
T_5 V_206 = V_267 -> V_197 . V_206 ;
T_8 V_240 ;
int V_67 = - V_131 ;
for (; ; ) {
if ( F_109 ( V_66 , V_206 , V_245 ) ) {
F_34 ( & V_66 -> V_215 -> V_262 ) ;
if ( F_109 ( V_66 , V_206 , V_245 ) ) {
F_112 ( V_66 , V_206 ) ;
F_36 ( & V_66 -> V_215 -> V_262 ) ;
goto V_268;
}
F_36 ( & V_66 -> V_215 -> V_262 ) ;
}
F_122 () ;
V_254 = F_123 ( V_174 -> V_254 ) ;
if ( ! F_110 ( V_254 , V_206 ) ) {
F_125 () ;
break;
}
F_115 ( & V_240 , & V_254 -> V_240 ) ;
F_125 () ;
F_128 ( V_267 -> V_197 . V_196 ) ;
if ( ! V_267 -> V_269 ) {
V_67 = F_129 ( V_66 -> V_2 , V_66 -> V_215 -> V_270 , V_245 ) ;
if ( V_67 != 0 )
goto V_132;
}
V_67 = - V_131 ;
if ( F_121 ( V_66 , NULL , & V_240 , V_206 ) )
goto V_268;
}
V_132:
return F_44 ( V_67 ) ;
V_268:
F_91 ( & V_66 -> V_51 ) ;
return V_66 ;
}
static void
F_130 ( struct V_192 * V_158 , struct V_65 * V_66 )
{
struct V_63 * V_64 = F_85 ( V_66 -> V_2 ) -> V_63 ;
struct V_253 * V_254 ;
int V_271 = 0 ;
F_122 () ;
V_254 = F_123 ( F_75 ( V_66 -> V_2 ) -> V_254 ) ;
if ( V_254 )
V_271 = V_254 -> V_207 ;
F_125 () ;
if ( V_158 -> V_197 . V_185 == V_189 ) {
F_131 ( L_18
L_19
L_20 ,
V_64 -> V_98 ) ;
} else if ( ( V_271 & 1UL << V_255 ) == 0 )
F_132 ( V_66 -> V_2 ,
V_158 -> V_215 -> V_270 ,
& V_158 -> V_193 ) ;
else
F_133 ( V_66 -> V_2 ,
V_158 -> V_215 -> V_270 ,
& V_158 -> V_193 ) ;
}
static struct V_65 *
F_134 ( struct V_192 * V_158 )
{
struct V_2 * V_2 = V_158 -> V_66 -> V_2 ;
struct V_65 * V_66 = V_158 -> V_66 ;
int V_67 ;
if ( ! V_158 -> V_272 ) {
if ( V_158 -> V_273 ) {
V_67 = V_158 -> V_273 ;
goto V_8;
}
goto V_274;
}
V_67 = F_135 ( V_2 , & V_158 -> V_194 ) ;
if ( V_67 )
goto V_8;
if ( V_158 -> V_193 . V_275 != 0 )
F_130 ( V_158 , V_66 ) ;
V_274:
F_121 ( V_66 , & V_158 -> V_193 . V_240 , NULL ,
V_158 -> V_197 . V_206 ) ;
F_91 ( & V_66 -> V_51 ) ;
return V_66 ;
V_8:
return F_44 ( V_67 ) ;
}
static struct V_65 *
F_136 ( struct V_192 * V_158 )
{
struct V_2 * V_2 ;
struct V_65 * V_66 = NULL ;
int V_67 ;
if ( ! V_158 -> V_272 ) {
V_66 = F_127 ( V_158 ) ;
goto V_132;
}
V_67 = - V_131 ;
if ( ! ( V_158 -> V_194 . V_276 & V_277 ) )
goto V_8;
V_2 = F_137 ( V_158 -> V_3 -> V_214 , & V_158 -> V_193 . V_234 , & V_158 -> V_194 , V_158 -> V_195 ) ;
V_67 = F_71 ( V_2 ) ;
if ( F_43 ( V_2 ) )
goto V_8;
V_67 = - V_127 ;
V_66 = F_138 ( V_2 , V_158 -> V_215 ) ;
if ( V_66 == NULL )
goto V_278;
if ( V_158 -> V_193 . V_275 != 0 )
F_130 ( V_158 , V_66 ) ;
F_121 ( V_66 , & V_158 -> V_193 . V_240 , NULL ,
V_158 -> V_197 . V_206 ) ;
F_139 ( V_2 ) ;
V_132:
F_128 ( V_158 -> V_197 . V_196 ) ;
return V_66 ;
V_278:
F_139 ( V_2 ) ;
V_8:
return F_44 ( V_67 ) ;
}
static struct V_65 *
F_140 ( struct V_192 * V_158 )
{
if ( V_158 -> V_197 . V_185 == V_235 )
return F_134 ( V_158 ) ;
return F_136 ( V_158 ) ;
}
static struct V_279 * F_141 ( struct V_65 * V_66 )
{
struct V_173 * V_174 = F_75 ( V_66 -> V_2 ) ;
struct V_279 * V_280 ;
F_34 ( & V_66 -> V_2 -> V_175 ) ;
F_142 (ctx, &nfsi->open_files, list) {
if ( V_280 -> V_66 != V_66 )
continue;
F_143 ( V_280 ) ;
F_36 ( & V_66 -> V_2 -> V_175 ) ;
return V_280 ;
}
F_36 ( & V_66 -> V_2 -> V_175 ) ;
return F_44 ( - V_281 ) ;
}
static struct V_192 * F_144 ( struct V_279 * V_280 ,
struct V_65 * V_66 , enum V_184 V_185 )
{
struct V_192 * V_267 ;
V_267 = F_83 ( V_280 -> V_4 , V_66 -> V_215 , 0 , 0 ,
NULL , NULL , V_185 , V_282 ) ;
if ( V_267 == NULL )
return F_44 ( - V_127 ) ;
V_267 -> V_66 = V_66 ;
F_91 ( & V_66 -> V_51 ) ;
return V_267 ;
}
static int F_145 ( struct V_192 * V_267 , T_5 V_206 , struct V_65 * * V_55 )
{
struct V_65 * V_283 ;
int V_67 ;
V_267 -> V_197 . V_217 = 0 ;
V_267 -> V_197 . V_206 = V_206 ;
memset ( & V_267 -> V_193 , 0 , sizeof( V_267 -> V_193 ) ) ;
memset ( & V_267 -> V_198 , 0 , sizeof( V_267 -> V_198 ) ) ;
F_80 ( V_267 ) ;
V_67 = F_146 ( V_267 ) ;
if ( V_67 != 0 )
return V_67 ;
V_283 = F_140 ( V_267 ) ;
if ( F_43 ( V_283 ) )
return F_71 ( V_283 ) ;
F_147 ( V_283 , V_206 ) ;
* V_55 = V_283 ;
return 0 ;
}
static int F_148 ( struct V_192 * V_267 , struct V_65 * V_66 )
{
struct V_65 * V_283 ;
int V_67 ;
F_149 ( V_257 , & V_66 -> V_207 ) ;
F_149 ( V_259 , & V_66 -> V_207 ) ;
F_150 () ;
if ( V_66 -> V_252 != 0 ) {
F_149 ( V_251 , & V_66 -> V_207 ) ;
V_67 = F_145 ( V_267 , V_70 | V_218 , & V_283 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_283 != V_66 )
return - V_284 ;
}
if ( V_66 -> V_250 != 0 ) {
F_149 ( V_249 , & V_66 -> V_207 ) ;
V_67 = F_145 ( V_267 , V_218 , & V_283 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_283 != V_66 )
return - V_284 ;
}
if ( V_66 -> V_248 != 0 ) {
F_149 ( V_247 , & V_66 -> V_207 ) ;
V_67 = F_145 ( V_267 , V_70 , & V_283 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_283 != V_66 )
return - V_284 ;
}
if ( F_31 ( V_257 , & V_66 -> V_207 ) == 0 &&
! F_124 ( & V_66 -> V_240 , & V_66 -> V_258 ) ) {
F_118 ( & V_66 -> V_260 ) ;
if ( F_31 ( V_257 , & V_66 -> V_207 ) == 0 )
F_115 ( & V_66 -> V_240 , & V_66 -> V_258 ) ;
F_119 ( & V_66 -> V_260 ) ;
}
return 0 ;
}
static int F_151 ( struct V_279 * V_280 , struct V_65 * V_66 )
{
struct V_253 * V_254 ;
struct V_192 * V_267 ;
T_5 V_275 = 0 ;
int V_285 ;
V_267 = F_144 ( V_280 , V_66 ,
V_235 ) ;
if ( F_43 ( V_267 ) )
return F_71 ( V_267 ) ;
F_122 () ;
V_254 = F_123 ( F_75 ( V_66 -> V_2 ) -> V_254 ) ;
if ( V_254 != NULL && F_31 ( V_255 , & V_254 -> V_207 ) != 0 )
V_275 = V_254 -> type ;
F_125 () ;
V_267 -> V_197 . V_238 . V_275 = V_275 ;
V_285 = F_148 ( V_267 , V_66 ) ;
F_105 ( V_267 ) ;
return V_285 ;
}
static int F_152 ( struct V_279 * V_280 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_151 ( V_280 , V_66 ) ;
F_153 ( V_280 , 0 , V_8 ) ;
if ( F_78 ( V_14 , V_8 , & V_62 ) )
continue;
if ( V_8 != - V_91 )
break;
F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_154 ( struct V_204 * V_205 , struct V_65 * V_66 )
{
struct V_279 * V_280 ;
int V_67 ;
V_280 = F_141 ( V_66 ) ;
if ( F_43 ( V_280 ) )
return - V_131 ;
V_67 = F_152 ( V_280 , V_66 ) ;
F_155 ( V_280 ) ;
return V_67 ;
}
static int F_156 ( struct V_13 * V_14 , struct V_65 * V_66 , const T_8 * V_240 , int V_8 )
{
switch ( V_8 ) {
default:
F_29 ( V_286 L_21
L_22 , V_35 , V_8 ) ;
case 0 :
case - V_281 :
case - V_284 :
break;
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
F_116 ( V_257 , & V_66 -> V_207 ) ;
F_28 ( V_14 -> V_63 -> V_88 , V_8 ) ;
return - V_131 ;
case - V_77 :
case - V_76 :
F_116 ( V_257 , & V_66 -> V_207 ) ;
case - V_75 :
F_24 ( V_14 -> V_63 ) ;
return - V_131 ;
case - V_78 :
F_25 ( V_14 ) ;
return - V_131 ;
case - V_79 :
F_26 ( V_14 -> V_63 ) ;
return - V_131 ;
case - V_72 :
case - V_73 :
case - V_74 :
case - V_69 :
F_157 ( V_66 -> V_2 ,
V_240 ) ;
F_22 ( V_14 , V_66 ) ;
return 0 ;
case - V_91 :
case - V_90 :
F_116 ( V_257 , & V_66 -> V_207 ) ;
F_158 ( 1 ) ;
return - V_131 ;
case - V_127 :
case - V_287 :
return 0 ;
}
return V_8 ;
}
int F_159 ( struct V_279 * V_280 , struct V_65 * V_66 , const T_8 * V_240 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_192 * V_267 ;
int V_8 ;
V_267 = F_144 ( V_280 , V_66 ,
V_188 ) ;
if ( F_43 ( V_267 ) )
return F_71 ( V_267 ) ;
F_115 ( & V_267 -> V_197 . V_238 . V_254 , V_240 ) ;
V_8 = F_148 ( V_267 , V_66 ) ;
F_105 ( V_267 ) ;
return F_156 ( V_14 , V_66 , V_240 , V_8 ) ;
}
static void F_160 ( struct V_117 * V_118 , void * V_156 )
{
struct V_192 * V_158 = V_156 ;
F_40 ( V_158 -> V_197 . V_14 , & V_158 -> V_199 . V_160 ,
& V_158 -> V_198 . V_161 , V_118 ) ;
}
static void F_161 ( struct V_117 * V_118 , void * V_156 )
{
struct V_192 * V_158 = V_156 ;
F_48 ( V_118 , & V_158 -> V_198 . V_161 ) ;
V_158 -> V_273 = V_118 -> V_150 ;
if ( V_158 -> V_273 == 0 ) {
F_115 ( & V_158 -> V_193 . V_240 , & V_158 -> V_198 . V_240 ) ;
F_162 ( & V_158 -> V_215 -> V_212 , 0 ) ;
F_37 ( V_158 -> V_193 . V_14 , V_158 -> V_107 ) ;
V_158 -> V_272 = 1 ;
}
}
static void F_163 ( void * V_156 )
{
struct V_192 * V_158 = V_156 ;
struct V_65 * V_66 = NULL ;
if ( V_158 -> V_288 == 0 )
goto V_289;
if ( ! V_158 -> V_272 )
goto V_289;
V_66 = F_140 ( V_158 ) ;
if ( ! F_43 ( V_66 ) )
F_147 ( V_66 , V_158 -> V_197 . V_206 ) ;
V_289:
F_105 ( V_158 ) ;
}
static int F_164 ( struct V_192 * V_158 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_3 -> V_47 ) ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_292 ] ,
. V_293 = & V_158 -> V_199 ,
. V_294 = & V_158 -> V_198 ,
. V_295 = V_158 -> V_215 -> V_270 ,
} ;
struct V_164 V_296 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_297 ,
. V_170 = V_158 ,
. V_298 = V_299 ,
. V_207 = V_300 ,
} ;
int V_285 ;
F_38 ( & V_158 -> V_199 . V_160 , & V_158 -> V_198 . V_161 , 1 ) ;
F_165 ( & V_158 -> V_241 ) ;
V_158 -> V_272 = 0 ;
V_158 -> V_273 = 0 ;
V_158 -> V_107 = V_155 ;
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_285 = F_107 ( V_118 ) ;
if ( V_285 != 0 ) {
V_158 -> V_288 = 1 ;
F_166 () ;
} else
V_285 = V_158 -> V_273 ;
F_72 ( V_118 ) ;
return V_285 ;
}
static void F_167 ( struct V_117 * V_118 , void * V_156 )
{
struct V_192 * V_158 = V_156 ;
struct V_204 * V_205 = V_158 -> V_215 ;
struct V_63 * V_64 = V_205 -> V_301 -> V_63 ;
if ( F_168 ( V_158 -> V_197 . V_196 , V_118 ) != 0 )
goto V_302;
if ( V_158 -> V_66 != NULL ) {
struct V_253 * V_254 ;
if ( F_109 ( V_158 -> V_66 , V_158 -> V_197 . V_206 , V_158 -> V_197 . V_217 ) )
goto V_303;
F_122 () ;
V_254 = F_123 ( F_75 ( V_158 -> V_66 -> V_2 ) -> V_254 ) ;
if ( V_158 -> V_197 . V_185 != V_189 &&
V_158 -> V_197 . V_185 != V_188 &&
F_110 ( V_254 , V_158 -> V_197 . V_206 ) )
goto V_304;
F_125 () ;
}
V_158 -> V_197 . V_224 = V_64 -> V_225 ;
switch ( V_158 -> V_197 . V_185 ) {
case V_235 :
case V_188 :
case V_190 :
V_158 -> V_197 . V_232 = & V_305 [ 0 ] ;
case V_186 :
V_118 -> V_306 . V_290 = & V_291 [ V_307 ] ;
F_169 ( & V_158 -> V_193 . V_234 , V_158 -> V_197 . V_234 ) ;
}
V_158 -> V_107 = V_155 ;
if ( F_63 ( V_158 -> V_197 . V_14 ,
& V_158 -> V_197 . V_160 ,
& V_158 -> V_193 . V_161 ,
V_118 ) != 0 )
F_128 ( V_158 -> V_197 . V_196 ) ;
V_158 -> V_197 . V_308 = V_309 ;
if ( V_158 -> V_197 . V_217 & V_219 ) {
V_158 -> V_197 . V_308 = V_310 ;
if ( F_170 ( V_64 ) )
V_158 -> V_197 . V_308 = V_311 ;
else if ( V_64 -> V_168 -> V_312 > 0 )
V_158 -> V_197 . V_308 = V_313 ;
}
return;
V_304:
F_125 () ;
V_303:
V_118 -> V_314 = NULL ;
V_302:
F_60 ( V_118 , & V_158 -> V_193 . V_161 ) ;
}
static void F_171 ( struct V_117 * V_118 , void * V_156 )
{
struct V_192 * V_158 = V_156 ;
V_158 -> V_273 = V_118 -> V_150 ;
if ( ! F_60 ( V_118 , & V_158 -> V_193 . V_161 ) )
return;
if ( V_118 -> V_150 == 0 ) {
if ( V_158 -> V_193 . V_194 -> V_276 & V_315 ) {
switch ( V_158 -> V_193 . V_194 -> V_244 & V_316 ) {
case V_317 :
break;
case V_318 :
V_158 -> V_273 = - V_319 ;
break;
case V_320 :
V_158 -> V_273 = - V_321 ;
break;
default:
V_158 -> V_273 = - V_322 ;
}
}
F_37 ( V_158 -> V_193 . V_14 , V_158 -> V_107 ) ;
if ( ! ( V_158 -> V_193 . V_323 & V_324 ) )
F_162 ( & V_158 -> V_215 -> V_212 , 0 ) ;
}
V_158 -> V_272 = 1 ;
}
static void F_172 ( void * V_156 )
{
struct V_192 * V_158 = V_156 ;
struct V_65 * V_66 = NULL ;
if ( V_158 -> V_288 == 0 )
goto V_289;
if ( V_158 -> V_273 != 0 || ! V_158 -> V_272 )
goto V_289;
if ( V_158 -> V_193 . V_323 & V_324 )
goto V_289;
V_66 = F_140 ( V_158 ) ;
if ( ! F_43 ( V_66 ) )
F_147 ( V_66 , V_158 -> V_197 . V_206 ) ;
V_289:
F_105 ( V_158 ) ;
}
static int F_173 ( struct V_192 * V_158 , int V_325 )
{
struct V_2 * V_3 = V_158 -> V_3 -> V_47 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_326 * V_197 = & V_158 -> V_197 ;
struct V_327 * V_193 = & V_158 -> V_193 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_328 ] ,
. V_293 = V_197 ,
. V_294 = V_193 ,
. V_295 = V_158 -> V_215 -> V_270 ,
} ;
struct V_164 V_296 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_329 ,
. V_170 = V_158 ,
. V_298 = V_299 ,
. V_207 = V_300 ,
} ;
int V_285 ;
F_38 ( & V_197 -> V_160 , & V_193 -> V_161 , 1 ) ;
F_165 ( & V_158 -> V_241 ) ;
V_158 -> V_272 = 0 ;
V_158 -> V_273 = 0 ;
V_158 -> V_288 = 0 ;
V_158 -> V_269 = 0 ;
if ( V_325 ) {
F_39 ( & V_197 -> V_160 ) ;
V_158 -> V_269 = 1 ;
}
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_285 = F_107 ( V_118 ) ;
if ( V_285 != 0 ) {
V_158 -> V_288 = 1 ;
F_166 () ;
} else
V_285 = V_158 -> V_273 ;
F_72 ( V_118 ) ;
return V_285 ;
}
static int F_146 ( struct V_192 * V_158 )
{
struct V_2 * V_3 = V_158 -> V_3 -> V_47 ;
struct V_327 * V_193 = & V_158 -> V_193 ;
int V_285 ;
V_285 = F_173 ( V_158 , 1 ) ;
if ( V_285 != 0 || ! V_158 -> V_272 )
return V_285 ;
F_174 ( F_85 ( V_3 ) , & V_158 -> V_194 ) ;
if ( V_193 -> V_323 & V_324 ) {
V_285 = F_164 ( V_158 ) ;
if ( V_285 != 0 )
return V_285 ;
}
return V_285 ;
}
static int F_175 ( struct V_295 * V_330 ,
struct V_192 * V_267 ,
struct V_65 * V_66 , T_5 V_206 ,
int V_331 )
{
struct V_332 V_333 ;
T_1 V_334 ;
if ( V_267 -> V_193 . V_335 == 0 )
return 0 ;
V_334 = 0 ;
if ( V_331 & V_336 ) {
V_334 = V_337 ;
} else if ( V_206 & V_70 )
V_334 = V_338 ;
V_333 . V_330 = V_330 ;
V_333 . V_155 = V_155 ;
F_176 ( & V_333 , V_267 -> V_193 . V_339 ) ;
F_177 ( V_66 -> V_2 , & V_333 ) ;
if ( ( V_334 & ~ V_333 . V_334 & ( V_338 | V_337 ) ) == 0 )
return 0 ;
F_147 ( V_66 , V_206 ) ;
return - V_29 ;
}
static int F_178 ( struct V_192 * V_158 )
{
struct V_2 * V_3 = V_158 -> V_3 -> V_47 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_326 * V_197 = & V_158 -> V_197 ;
struct V_327 * V_193 = & V_158 -> V_193 ;
int V_285 ;
V_285 = F_173 ( V_158 , 0 ) ;
if ( ! V_158 -> V_272 )
return V_285 ;
if ( V_285 != 0 ) {
if ( V_285 == - V_26 &&
! ( V_197 -> V_217 & V_340 ) )
return - V_281 ;
return V_285 ;
}
F_174 ( V_14 , & V_158 -> V_194 ) ;
if ( V_197 -> V_217 & V_340 ) {
F_74 ( V_3 , & V_193 -> V_172 ) ;
if ( V_197 -> V_217 & V_219 )
V_158 -> V_341 = 1 ;
else if ( V_193 -> V_172 . V_180 != V_193 -> V_172 . V_182 )
V_158 -> V_341 = 1 ;
}
if ( ( V_193 -> V_323 & V_342 ) == 0 )
V_14 -> V_95 &= ~ V_343 ;
if( V_193 -> V_323 & V_324 ) {
V_285 = F_164 ( V_158 ) ;
if ( V_285 != 0 )
return V_285 ;
}
if ( ! ( V_193 -> V_194 -> V_276 & V_277 ) )
F_179 ( V_14 , & V_193 -> V_234 , V_193 -> V_194 , V_193 -> V_195 ) ;
return 0 ;
}
static int F_180 ( struct V_13 * V_14 )
{
return F_181 ( V_14 -> V_63 ) ;
}
static int F_182 ( struct V_279 * V_280 , struct V_65 * V_66 )
{
struct V_192 * V_267 ;
int V_67 ;
V_267 = F_144 ( V_280 , V_66 ,
V_186 ) ;
if ( F_43 ( V_267 ) )
return F_71 ( V_267 ) ;
V_67 = F_148 ( V_267 , V_66 ) ;
if ( V_67 == - V_284 )
F_183 ( V_280 -> V_4 ) ;
F_105 ( V_267 ) ;
return V_67 ;
}
static int F_184 ( struct V_279 * V_280 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_182 ( V_280 , V_66 ) ;
F_185 ( V_280 , 0 , V_8 ) ;
if ( F_78 ( V_14 , V_8 , & V_62 ) )
continue;
switch ( V_8 ) {
default:
goto V_132;
case - V_90 :
case - V_91 :
F_19 ( V_14 , V_8 , & V_62 ) ;
V_8 = 0 ;
}
} while ( V_62 . V_68 );
V_132:
return V_8 ;
}
static int F_186 ( struct V_204 * V_205 , struct V_65 * V_66 )
{
struct V_279 * V_280 ;
int V_67 ;
V_280 = F_141 ( V_66 ) ;
if ( F_43 ( V_280 ) )
return - V_131 ;
V_67 = F_184 ( V_280 , V_66 ) ;
F_155 ( V_280 ) ;
return V_67 ;
}
static void F_187 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
T_8 * V_240 = & V_66 -> V_240 ;
struct V_253 * V_254 ;
struct V_295 * V_330 = NULL ;
int V_285 = - V_74 ;
if ( F_31 ( V_257 , & V_66 -> V_207 ) == 0 )
return;
F_122 () ;
V_254 = F_123 ( F_75 ( V_66 -> V_2 ) -> V_254 ) ;
if ( V_254 != NULL &&
F_124 ( & V_254 -> V_240 , V_240 ) ) {
V_330 = F_188 ( V_254 -> V_330 ) ;
F_125 () ;
V_285 = F_189 ( V_14 , V_240 , V_330 ) ;
F_190 ( V_66 , NULL , V_285 ) ;
} else
F_125 () ;
if ( V_285 != V_344 ) {
if ( V_285 != - V_74 )
F_191 ( V_14 , V_240 , V_330 ) ;
F_23 ( V_66 -> V_2 ) ;
F_118 ( & V_66 -> V_260 ) ;
F_115 ( & V_66 -> V_240 , & V_66 -> V_258 ) ;
F_119 ( & V_66 -> V_260 ) ;
F_149 ( V_257 , & V_66 -> V_207 ) ;
}
if ( V_330 != NULL )
F_192 ( V_330 ) ;
}
static int F_193 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
T_8 * V_240 = & V_66 -> V_258 ;
struct V_295 * V_330 = V_66 -> V_215 -> V_270 ;
int V_285 ;
if ( ( F_31 ( V_247 , & V_66 -> V_207 ) == 0 ) &&
( F_31 ( V_249 , & V_66 -> V_207 ) == 0 ) &&
( F_31 ( V_251 , & V_66 -> V_207 ) == 0 ) )
return - V_74 ;
V_285 = F_189 ( V_14 , V_240 , V_330 ) ;
F_194 ( V_66 , NULL , V_285 ) ;
if ( V_285 != V_344 ) {
if ( V_285 != - V_74 )
F_191 ( V_14 , V_240 , V_330 ) ;
F_149 ( V_247 , & V_66 -> V_207 ) ;
F_149 ( V_249 , & V_66 -> V_207 ) ;
F_149 ( V_251 , & V_66 -> V_207 ) ;
F_149 ( V_259 , & V_66 -> V_207 ) ;
}
return V_285 ;
}
static int F_195 ( struct V_204 * V_205 , struct V_65 * V_66 )
{
int V_285 ;
F_187 ( V_66 ) ;
V_285 = F_193 ( V_66 ) ;
if ( V_285 != V_344 )
V_285 = F_186 ( V_205 , V_66 ) ;
return V_285 ;
}
static inline void F_196 ( struct V_192 * V_267 , struct V_5 * V_6 )
{
if ( ( V_267 -> V_193 . V_345 [ 1 ] & V_346 ) &&
! ( V_6 -> V_236 & V_347 ) )
V_6 -> V_236 |= V_348 ;
if ( ( V_267 -> V_193 . V_345 [ 1 ] & V_349 ) &&
! ( V_6 -> V_236 & V_350 ) )
V_6 -> V_236 |= V_351 ;
}
static int F_197 ( struct V_192 * V_267 ,
T_5 V_206 ,
int V_207 ,
struct V_279 * V_280 )
{
struct V_204 * V_205 = V_267 -> V_215 ;
struct V_13 * V_14 = V_205 -> V_301 ;
struct V_4 * V_4 ;
struct V_65 * V_66 ;
unsigned int V_352 ;
int V_67 ;
V_352 = F_198 ( & V_205 -> V_353 ) ;
V_67 = F_178 ( V_267 ) ;
if ( V_67 != 0 )
goto V_132;
V_66 = F_140 ( V_267 ) ;
V_67 = F_71 ( V_66 ) ;
if ( F_43 ( V_66 ) )
goto V_132;
if ( V_14 -> V_95 & V_343 )
F_116 ( V_354 , & V_66 -> V_207 ) ;
V_4 = V_267 -> V_4 ;
if ( V_4 -> V_47 == NULL ) {
F_183 ( V_4 ) ;
V_4 = F_199 ( V_4 , F_200 ( V_66 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_267 -> V_4 ;
} else if ( V_4 != V_280 -> V_4 ) {
F_97 ( V_280 -> V_4 ) ;
V_280 -> V_4 = F_90 ( V_4 ) ;
}
F_201 ( V_4 ,
F_202 ( V_267 -> V_3 -> V_47 ) ) ;
}
V_67 = F_175 ( V_205 -> V_270 , V_267 , V_66 , V_206 , V_207 ) ;
if ( V_67 != 0 )
goto V_132;
V_280 -> V_66 = V_66 ;
if ( V_4 -> V_47 == V_66 -> V_2 ) {
F_203 ( V_280 ) ;
if ( F_204 ( & V_205 -> V_353 , V_352 ) )
F_22 ( V_14 , V_66 ) ;
}
V_132:
return V_67 ;
}
static int F_205 ( struct V_2 * V_3 ,
struct V_279 * V_280 ,
int V_207 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_355 )
{
struct V_204 * V_205 ;
struct V_65 * V_66 = NULL ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_192 * V_267 ;
struct V_4 * V_4 = V_280 -> V_4 ;
struct V_295 * V_330 = V_280 -> V_330 ;
struct V_356 * * V_357 = & V_280 -> V_358 ;
T_5 V_206 = V_280 -> V_244 & ( V_70 | V_218 | V_359 ) ;
enum V_184 V_185 = V_187 ;
struct V_1 * V_360 = NULL ;
int V_285 ;
V_285 = - V_127 ;
V_205 = F_206 ( V_14 , V_330 , V_361 ) ;
if ( V_205 == NULL ) {
F_8 ( L_23 ) ;
goto V_362;
}
V_285 = F_180 ( V_14 ) ;
if ( V_285 != 0 )
goto V_363;
if ( V_4 -> V_47 != NULL )
F_126 ( V_4 -> V_47 , V_206 ) ;
V_285 = - V_127 ;
if ( V_4 -> V_47 )
V_185 = V_186 ;
V_267 = F_83 ( V_4 , V_205 , V_206 , V_207 , V_6 ,
V_7 , V_185 , V_361 ) ;
if ( V_267 == NULL )
goto V_363;
if ( V_7 ) {
V_360 = F_87 ( V_14 , V_361 ) ;
if ( F_43 ( V_360 ) ) {
V_285 = F_71 ( V_360 ) ;
goto V_364;
}
}
if ( V_357 && V_14 -> V_15 [ 2 ] & V_365 ) {
V_267 -> V_194 . V_358 = F_207 () ;
if ( ! V_267 -> V_194 . V_358 )
goto V_213;
V_267 -> V_197 . V_232 = & V_366 [ 0 ] ;
}
if ( V_4 -> V_47 != NULL )
V_267 -> V_66 = F_138 ( V_4 -> V_47 , V_205 ) ;
V_285 = F_197 ( V_267 , V_206 , V_207 , V_280 ) ;
if ( V_285 != 0 )
goto V_213;
V_66 = V_280 -> V_66 ;
if ( ( V_267 -> V_197 . V_217 & V_219 ) &&
( V_267 -> V_197 . V_308 != V_311 ) ) {
F_196 ( V_267 , V_6 ) ;
F_81 ( V_267 -> V_193 . V_194 ) ;
V_285 = F_208 ( V_66 -> V_2 , V_330 ,
V_267 -> V_193 . V_194 , V_6 ,
V_66 , V_7 , V_360 ) ;
if ( V_285 == 0 ) {
F_209 ( V_66 -> V_2 , V_6 ) ;
F_210 ( V_66 -> V_2 , V_267 -> V_193 . V_194 ) ;
F_211 ( V_66 -> V_2 , V_267 -> V_193 . V_194 , V_360 ) ;
}
}
if ( V_267 -> V_341 )
* V_355 |= V_367 ;
if ( F_212 ( V_357 , V_267 -> V_194 . V_358 , V_14 ) )
* V_357 = V_267 -> V_194 . V_358 ;
else
F_96 ( V_267 -> V_194 . V_358 ) ;
V_267 -> V_194 . V_358 = NULL ;
F_95 ( V_360 ) ;
F_105 ( V_267 ) ;
F_102 ( V_205 ) ;
return 0 ;
V_213:
F_95 ( V_360 ) ;
V_364:
F_96 ( V_267 -> V_194 . V_358 ) ;
F_105 ( V_267 ) ;
V_363:
F_102 ( V_205 ) ;
V_362:
return V_285 ;
}
static struct V_65 * F_213 ( struct V_2 * V_3 ,
struct V_279 * V_280 ,
int V_207 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_355 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_61 V_62 = { } ;
struct V_65 * V_55 ;
int V_285 ;
do {
V_285 = F_205 ( V_3 , V_280 , V_207 , V_6 , V_7 , V_355 ) ;
V_55 = V_280 -> V_66 ;
F_214 ( V_280 , V_207 , V_285 ) ;
if ( V_285 == 0 )
break;
if ( V_285 == - V_368 ) {
F_215 ( L_5
L_24 ,
F_85 ( V_3 ) -> V_63 -> V_98 ) ;
V_62 . V_68 = 1 ;
continue;
}
if ( V_285 == - V_74 ) {
V_62 . V_68 = 1 ;
continue;
}
if ( V_285 == - V_131 ) {
V_62 . V_68 = 1 ;
continue;
}
if ( F_78 ( V_14 , V_285 , & V_62 ) )
continue;
V_55 = F_44 ( F_19 ( V_14 ,
V_285 , & V_62 ) ) ;
} while ( V_62 . V_68 );
return V_55 ;
}
static int F_216 ( struct V_2 * V_2 , struct V_295 * V_330 ,
struct V_369 * V_370 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_371 ,
struct V_1 * V_360 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_372 V_373 = {
. V_234 = F_93 ( V_2 ) ,
. V_374 = V_6 ,
. V_14 = V_14 ,
. V_231 = V_14 -> V_15 ,
. V_7 = V_371 ,
} ;
struct V_375 V_55 = {
. V_370 = V_370 ,
. V_7 = V_360 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_376 ] ,
. V_293 = & V_373 ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
unsigned long V_107 = V_155 ;
T_5 V_206 ;
bool V_377 ;
int V_285 ;
V_373 . V_231 = F_6 ( V_14 , V_371 ) ;
if ( V_371 )
V_373 . V_231 = F_6 ( V_14 , V_360 ) ;
F_81 ( V_370 ) ;
V_377 = ( V_6 -> V_236 & V_378 ) ? true : false ;
V_206 = V_377 ? V_218 : V_70 ;
if ( F_217 ( & V_373 . V_240 , V_2 , V_206 ) ) {
} else if ( V_377 && V_66 != NULL ) {
struct V_379 V_380 = {
. V_381 = V_58 -> V_382 ,
. V_383 = V_58 -> V_384 ,
} ;
if ( ! F_218 ( V_66 ) )
return - V_385 ;
if ( F_219 ( & V_373 . V_240 , V_66 , V_218 ,
& V_380 ) == - V_36 )
return - V_385 ;
} else
F_115 ( & V_373 . V_240 , & V_386 ) ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_373 . V_160 , & V_55 . V_161 , 1 ) ;
if ( V_285 == 0 && V_66 != NULL )
F_37 ( V_14 , V_107 ) ;
return V_285 ;
}
static int F_208 ( struct V_2 * V_2 , struct V_295 * V_330 ,
struct V_369 * V_370 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_371 ,
struct V_1 * V_360 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_216 ( V_2 , V_330 , V_370 , V_6 , V_66 , V_371 , V_360 ) ;
F_220 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_69 :
if ( ! ( V_6 -> V_236 & V_378 ) ) {
F_221 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_63 -> V_98 ) ;
}
if ( V_66 && ! ( V_66 -> V_66 & V_218 ) ) {
V_8 = - V_385 ;
if ( V_6 -> V_236 & V_387 )
V_8 = - V_29 ;
goto V_132;
}
}
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
V_132:
return V_8 ;
}
static void F_222 ( void * V_158 )
{
struct V_388 * V_156 = V_158 ;
struct V_204 * V_205 = V_156 -> V_66 -> V_215 ;
struct V_242 * V_243 = V_156 -> V_66 -> V_2 -> V_389 ;
if ( V_156 -> V_390 )
F_223 ( V_156 -> V_66 -> V_2 ) ;
F_101 ( V_156 -> V_66 ) ;
F_100 ( V_156 -> V_373 . V_196 ) ;
F_102 ( V_205 ) ;
F_103 ( V_243 ) ;
F_96 ( V_156 ) ;
}
static void F_224 ( struct V_65 * V_66 ,
T_5 V_206 )
{
F_34 ( & V_66 -> V_215 -> V_262 ) ;
F_149 ( V_251 , & V_66 -> V_207 ) ;
switch ( V_206 & ( V_70 | V_218 ) ) {
case V_218 :
F_149 ( V_247 , & V_66 -> V_207 ) ;
break;
case V_70 :
F_149 ( V_249 , & V_66 -> V_207 ) ;
break;
case 0 :
F_149 ( V_247 , & V_66 -> V_207 ) ;
F_149 ( V_249 , & V_66 -> V_207 ) ;
F_149 ( V_259 , & V_66 -> V_207 ) ;
}
F_36 ( & V_66 -> V_215 -> V_262 ) ;
}
static void F_225 ( struct V_117 * V_118 , void * V_158 )
{
struct V_388 * V_156 = V_158 ;
struct V_65 * V_66 = V_156 -> V_66 ;
struct V_13 * V_14 = F_85 ( V_156 -> V_2 ) ;
F_8 ( L_29 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_156 -> V_55 . V_161 ) )
return;
F_226 ( V_66 , & V_156 -> V_373 , & V_156 -> V_55 , V_118 -> V_150 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
if ( V_156 -> V_390 )
F_227 ( V_66 -> V_2 ,
V_156 -> V_391 ) ;
F_117 ( V_66 , & V_156 -> V_55 . V_240 , 0 ) ;
F_37 ( V_14 , V_156 -> V_107 ) ;
break;
case - V_73 :
case - V_76 :
case - V_94 :
case - V_74 :
case - V_75 :
if ( V_156 -> V_373 . V_206 == 0 )
break;
default:
if ( F_228 ( V_118 , V_14 , V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
goto V_392;
}
}
F_224 ( V_66 , V_156 -> V_373 . V_206 ) ;
V_392:
F_128 ( V_156 -> V_373 . V_196 ) ;
F_135 ( V_156 -> V_2 , V_156 -> V_55 . V_370 ) ;
F_8 ( L_30 , V_35 , V_118 -> V_150 ) ;
}
static void F_229 ( struct V_117 * V_118 , void * V_158 )
{
struct V_388 * V_156 = V_158 ;
struct V_65 * V_66 = V_156 -> V_66 ;
struct V_2 * V_2 = V_156 -> V_2 ;
int V_393 = 0 ;
F_8 ( L_29 , V_35 ) ;
if ( F_168 ( V_156 -> V_373 . V_196 , V_118 ) != 0 )
goto V_302;
V_118 -> V_306 . V_290 = & V_291 [ V_394 ] ;
V_156 -> V_373 . V_206 = V_70 | V_218 ;
F_34 ( & V_66 -> V_215 -> V_262 ) ;
if ( V_66 -> V_252 == 0 ) {
if ( V_66 -> V_248 == 0 ) {
V_393 |= F_31 ( V_247 , & V_66 -> V_207 ) ;
V_393 |= F_31 ( V_251 , & V_66 -> V_207 ) ;
V_156 -> V_373 . V_206 &= ~ V_70 ;
}
if ( V_66 -> V_250 == 0 ) {
V_393 |= F_31 ( V_249 , & V_66 -> V_207 ) ;
V_393 |= F_31 ( V_251 , & V_66 -> V_207 ) ;
V_156 -> V_373 . V_206 &= ~ V_218 ;
}
}
if ( ! F_218 ( V_66 ) )
V_393 = 0 ;
F_36 ( & V_66 -> V_215 -> V_262 ) ;
if ( ! V_393 ) {
goto V_303;
}
if ( V_156 -> V_373 . V_206 == 0 ) {
V_118 -> V_306 . V_290 = & V_291 [ V_395 ] ;
if ( V_156 -> V_390 &&
F_230 ( V_2 , & V_156 -> V_391 , V_118 ) ) {
F_128 ( V_156 -> V_373 . V_196 ) ;
goto V_302;
}
}
F_81 ( V_156 -> V_55 . V_370 ) ;
V_156 -> V_107 = V_155 ;
if ( F_63 ( F_85 ( V_2 ) ,
& V_156 -> V_373 . V_160 ,
& V_156 -> V_55 . V_161 ,
V_118 ) != 0 )
F_128 ( V_156 -> V_373 . V_196 ) ;
F_8 ( L_31 , V_35 ) ;
return;
V_303:
V_118 -> V_314 = NULL ;
V_302:
F_60 ( V_118 , & V_156 -> V_55 . V_161 ) ;
}
int F_231 ( struct V_65 * V_66 , T_6 V_209 , int V_396 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_388 * V_156 ;
struct V_204 * V_205 = V_66 -> V_215 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_395 ] ,
. V_295 = V_66 -> V_215 -> V_270 ,
} ;
struct V_164 V_296 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_397 ,
. V_298 = V_299 ,
. V_207 = V_300 ,
} ;
int V_285 = - V_127 ;
F_232 ( V_14 -> V_63 , V_398 ,
& V_296 . V_166 , & V_163 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_209 ) ;
if ( V_156 == NULL )
goto V_132;
F_38 ( & V_156 -> V_373 . V_160 , & V_156 -> V_55 . V_161 , 1 ) ;
V_156 -> V_2 = V_66 -> V_2 ;
V_156 -> V_66 = V_66 ;
V_156 -> V_373 . V_234 = F_93 ( V_66 -> V_2 ) ;
V_156 -> V_373 . V_240 = & V_66 -> V_258 ;
V_156 -> V_373 . V_196 = F_88 ( & V_66 -> V_215 -> V_212 , V_209 ) ;
if ( V_156 -> V_373 . V_196 == NULL )
goto V_399;
V_156 -> V_373 . V_206 = 0 ;
V_156 -> V_373 . V_231 = V_14 -> V_400 ;
V_156 -> V_55 . V_370 = & V_156 -> V_370 ;
V_156 -> V_55 . V_196 = V_156 -> V_373 . V_196 ;
V_156 -> V_55 . V_14 = V_14 ;
V_156 -> V_390 = F_233 ( V_66 -> V_2 ) ;
F_89 ( V_156 -> V_2 -> V_389 ) ;
V_163 . V_293 = & V_156 -> V_373 ;
V_163 . V_294 = & V_156 -> V_55 ;
V_296 . V_170 = V_156 ;
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_285 = 0 ;
if ( V_396 )
V_285 = F_108 ( V_118 ) ;
F_72 ( V_118 ) ;
return V_285 ;
V_399:
F_96 ( V_156 ) ;
V_132:
F_101 ( V_66 ) ;
F_102 ( V_205 ) ;
return V_285 ;
}
static struct V_2 *
F_234 ( struct V_2 * V_3 , struct V_279 * V_280 ,
int V_217 , struct V_5 * V_401 , int * V_355 )
{
struct V_65 * V_66 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_280 -> V_4 , V_401 , & V_17 ) ;
V_66 = F_213 ( V_3 , V_280 , V_217 , V_401 , V_7 , V_355 ) ;
F_4 ( V_7 ) ;
if ( F_43 ( V_66 ) )
return F_235 ( V_66 ) ;
return V_66 -> V_2 ;
}
static void F_236 ( struct V_279 * V_280 , int V_402 )
{
if ( V_280 -> V_66 == NULL )
return;
if ( V_402 )
F_237 ( V_280 -> V_66 , V_280 -> V_244 ) ;
else
F_147 ( V_280 -> V_66 , V_280 -> V_244 ) ;
}
static int F_238 ( struct V_13 * V_14 , struct V_403 * V_404 )
{
struct V_405 args = {
. V_404 = V_404 ,
} ;
struct V_406 V_55 = {} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_407 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
int V_285 ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
if ( V_285 == 0 ) {
switch ( V_14 -> V_63 -> V_408 ) {
case 0 :
V_55 . V_15 [ 1 ] &= V_409 ;
V_55 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_55 . V_15 [ 2 ] &= V_410 ;
break;
case 2 :
V_55 . V_15 [ 2 ] &= V_411 ;
}
memcpy ( V_14 -> V_15 , V_55 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_95 &= ~ ( V_412 | V_413 |
V_414 | V_415 |
V_416 | V_417 | V_418 |
V_419 | V_420 |
V_421 | V_422 |
V_9 ) ;
if ( V_55 . V_15 [ 0 ] & V_423 &&
V_55 . V_424 & V_425 )
V_14 -> V_95 |= V_412 ;
if ( V_55 . V_426 != 0 )
V_14 -> V_95 |= V_413 ;
if ( V_55 . V_427 != 0 )
V_14 -> V_95 |= V_414 ;
if ( V_55 . V_15 [ 0 ] & V_46 )
V_14 -> V_95 |= V_415 ;
if ( V_55 . V_15 [ 1 ] & V_428 )
V_14 -> V_95 |= V_416 ;
if ( V_55 . V_15 [ 1 ] & V_429 )
V_14 -> V_95 |= V_417 ;
if ( V_55 . V_15 [ 1 ] & V_430 )
V_14 -> V_95 |= V_418 ;
if ( V_55 . V_15 [ 1 ] & V_431 )
V_14 -> V_95 |= V_419 ;
if ( V_55 . V_15 [ 1 ] & V_346 )
V_14 -> V_95 |= V_420 ;
if ( V_55 . V_15 [ 1 ] & V_432 )
V_14 -> V_95 |= V_421 ;
if ( V_55 . V_15 [ 1 ] & V_349 )
V_14 -> V_95 |= V_422 ;
#ifdef F_239
if ( V_55 . V_15 [ 2 ] & V_433 )
V_14 -> V_95 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_55 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_433 ;
memcpy ( V_14 -> V_400 , V_55 . V_15 , sizeof( V_14 -> V_400 ) ) ;
V_14 -> V_400 [ 0 ] &= V_434 | V_435 ;
V_14 -> V_400 [ 1 ] &= V_432 | V_349 ;
V_14 -> V_400 [ 2 ] = 0 ;
V_14 -> V_424 = V_55 . V_424 ;
V_14 -> V_436 = V_55 . V_436 ;
}
return V_285 ;
}
int F_240 ( struct V_13 * V_14 , struct V_403 * V_404 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_238 ( V_14 , V_404 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_241 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_438 )
{
T_1 V_231 [ 3 ] ;
struct V_439 args = {
. V_231 = V_231 ,
} ;
struct V_440 V_55 = {
. V_14 = V_14 ,
. V_370 = V_438 -> V_370 ,
. V_234 = V_404 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_441 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
V_231 [ 0 ] = V_233 [ 0 ] ;
V_231 [ 1 ] = V_233 [ 1 ] ;
V_231 [ 2 ] = V_233 [ 2 ] & ~ V_433 ;
F_81 ( V_438 -> V_370 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_242 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_438 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_241 ( V_14 , V_404 , V_438 ) ;
F_243 ( V_14 , V_404 , V_438 -> V_370 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_132;
default:
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
}
} while ( V_62 . V_68 );
V_132:
return V_8 ;
}
static int F_244 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_438 , T_4 V_101 )
{
struct V_442 V_443 = {
. V_444 = V_101 ,
} ;
struct V_445 * V_446 ;
int V_67 ;
V_446 = F_245 ( & V_443 , V_14 -> V_92 ) ;
if ( F_43 ( V_446 ) ) {
V_67 = - V_29 ;
goto V_132;
}
V_67 = F_242 ( V_14 , V_404 , V_438 ) ;
V_132:
return V_67 ;
}
static int F_246 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_438 )
{
static const T_4 V_447 [] = {
V_106 ,
V_105 ,
V_448 ,
V_449 ,
V_450 ,
} ;
int V_285 = - V_24 ;
T_9 V_451 ;
if ( V_14 -> V_452 . V_453 > 0 ) {
for ( V_451 = 0 ; V_451 < V_14 -> V_452 . V_453 ; V_451 ++ ) {
V_285 = F_244 ( V_14 , V_404 , V_438 ,
V_14 -> V_452 . V_454 [ V_451 ] ) ;
if ( V_285 == - V_22 || V_285 == - V_29 )
continue;
break;
}
} else {
for ( V_451 = 0 ; V_451 < F_247 ( V_447 ) ; V_451 ++ ) {
V_285 = F_244 ( V_14 , V_404 , V_438 ,
V_447 [ V_451 ] ) ;
if ( V_285 == - V_22 || V_285 == - V_29 )
continue;
break;
}
}
if ( V_285 == - V_29 )
V_285 = - V_24 ;
return V_285 ;
}
static int F_248 ( struct V_13 * V_14 ,
struct V_403 * V_404 , struct V_437 * V_438 )
{
int V_455 = V_14 -> V_63 -> V_408 ;
return V_456 [ V_455 ] -> F_249 ( V_14 , V_404 , V_438 ) ;
}
int F_250 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_438 ,
bool V_457 )
{
int V_285 ;
switch ( V_457 ) {
case false :
V_285 = F_242 ( V_14 , V_404 , V_438 ) ;
if ( V_285 != - V_22 )
break;
default:
V_285 = F_248 ( V_14 , V_404 , V_438 ) ;
}
if ( V_285 == 0 )
V_285 = F_240 ( V_14 , V_404 ) ;
if ( V_285 == 0 )
V_285 = F_251 ( V_14 , V_404 , V_438 ) ;
return F_7 ( V_285 ) ;
}
static int F_252 ( struct V_13 * V_14 , struct V_403 * V_458 ,
struct V_437 * V_438 )
{
int error ;
struct V_369 * V_370 = V_438 -> V_370 ;
struct V_1 * V_7 = NULL ;
error = F_240 ( V_14 , V_458 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_87 ( V_14 , V_361 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
error = F_253 ( V_14 , V_458 , V_370 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_213;
}
if ( V_370 -> V_276 & V_459 &&
! F_254 ( & V_14 -> V_460 , & V_370 -> V_460 ) )
memcpy ( & V_14 -> V_460 , & V_370 -> V_460 , sizeof( V_14 -> V_460 ) ) ;
V_213:
F_95 ( V_7 ) ;
return error ;
}
static int F_255 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_461 * V_230 , struct V_369 * V_370 ,
struct V_403 * V_404 )
{
int V_285 = - V_127 ;
struct V_462 * V_462 = NULL ;
struct V_463 * V_464 = NULL ;
V_462 = F_256 ( V_361 ) ;
if ( V_462 == NULL )
goto V_132;
V_464 = F_257 ( sizeof( struct V_463 ) , V_361 ) ;
if ( V_464 == NULL )
goto V_132;
V_285 = F_258 ( V_92 , V_3 , V_230 , V_464 , V_462 ) ;
if ( V_285 != 0 )
goto V_132;
if ( F_254 ( & F_85 ( V_3 ) -> V_460 , & V_464 -> V_370 . V_460 ) ) {
F_8 ( L_34
L_35 , V_35 , V_230 -> V_230 ) ;
V_285 = - V_78 ;
goto V_132;
}
F_259 ( & V_464 -> V_370 ) ;
memcpy ( V_370 , & V_464 -> V_370 , sizeof( struct V_369 ) ) ;
memset ( V_404 , 0 , sizeof( struct V_403 ) ) ;
V_132:
if ( V_462 )
F_260 ( V_462 ) ;
F_96 ( V_464 ) ;
return V_285 ;
}
static int F_179 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_369 * V_370 , struct V_1 * V_7 )
{
struct V_465 args = {
. V_234 = V_404 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_466 V_55 = {
. V_370 = V_370 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_467 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
args . V_231 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_370 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_253 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_369 * V_370 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_179 ( V_14 , V_404 , V_370 , V_7 ) ;
F_261 ( V_14 , V_404 , V_370 , V_8 ) ;
V_8 = F_19 ( V_14 , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_262 ( struct V_4 * V_4 , struct V_369 * V_370 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = V_4 -> V_47 ;
struct V_295 * V_330 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_1 * V_7 = NULL ;
int V_285 ;
if ( F_263 ( V_2 ) )
F_264 ( V_2 ) ;
F_81 ( V_370 ) ;
if ( V_6 -> V_236 & V_387 )
V_6 -> V_236 &= ~ ( V_351 | V_468 ) ;
if ( ( V_6 -> V_236 & ~ ( V_469 | V_387 ) ) == 0 )
return 0 ;
if ( V_6 -> V_236 & V_469 ) {
struct V_279 * V_280 ;
V_280 = F_265 ( V_6 -> V_470 ) ;
if ( V_280 ) {
V_330 = V_280 -> V_330 ;
V_66 = V_280 -> V_66 ;
}
}
V_7 = F_87 ( F_85 ( V_2 ) , V_361 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
V_285 = F_208 ( V_2 , V_330 , V_370 , V_6 , V_66 , NULL , V_7 ) ;
if ( V_285 == 0 ) {
F_209 ( V_2 , V_6 ) ;
F_211 ( V_2 , V_370 , V_7 ) ;
}
F_95 ( V_7 ) ;
return V_285 ;
}
static int F_266 ( struct V_52 * V_53 , struct V_2 * V_3 ,
const struct V_461 * V_230 , struct V_403 * V_404 ,
struct V_369 * V_370 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
int V_285 ;
struct V_471 args = {
. V_231 = V_14 -> V_15 ,
. V_472 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
} ;
struct V_440 V_55 = {
. V_14 = V_14 ,
. V_370 = V_370 ,
. V_7 = V_7 ,
. V_234 = V_404 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_473 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
args . V_231 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_370 ) ;
F_8 ( L_36 , V_230 -> V_230 ) ;
V_285 = F_73 ( V_53 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
F_8 ( L_37 , V_285 ) ;
return V_285 ;
}
static void F_267 ( struct V_369 * V_370 )
{
V_370 -> V_276 |= V_315 | V_474 |
V_475 | V_476 ;
V_370 -> V_244 = V_320 | V_477 | V_478 ;
V_370 -> V_479 = 2 ;
}
static int F_268 ( struct V_52 * * V_53 , struct V_2 * V_3 ,
struct V_461 * V_230 , struct V_403 * V_404 ,
struct V_369 * V_370 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
struct V_52 * V_92 = * V_53 ;
int V_8 ;
do {
V_8 = F_266 ( V_92 , V_3 , V_230 , V_404 , V_370 , V_7 ) ;
F_269 ( V_3 , V_230 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_281 ;
goto V_132;
case - V_78 :
V_8 = F_255 ( V_92 , V_3 , V_230 , V_370 , V_404 ) ;
goto V_132;
case - V_22 :
V_8 = - V_24 ;
if ( V_92 != * V_53 )
goto V_132;
V_92 = F_270 ( V_92 , V_3 , V_230 ) ;
if ( F_43 ( V_92 ) )
return F_71 ( V_92 ) ;
V_62 . V_68 = 1 ;
break;
default:
V_8 = F_19 ( F_85 ( V_3 ) , V_8 , & V_62 ) ;
}
} while ( V_62 . V_68 );
V_132:
if ( V_8 == 0 )
* V_53 = V_92 ;
else if ( V_92 != * V_53 )
F_271 ( V_92 ) ;
return V_8 ;
}
static int F_272 ( struct V_2 * V_3 , struct V_461 * V_230 ,
struct V_403 * V_404 , struct V_369 * V_370 ,
struct V_1 * V_7 )
{
int V_285 ;
struct V_52 * V_92 = F_273 ( V_3 ) ;
V_285 = F_268 ( & V_92 , V_3 , V_230 , V_404 , V_370 , V_7 ) ;
if ( V_92 != F_273 ( V_3 ) ) {
F_271 ( V_92 ) ;
F_267 ( V_370 ) ;
}
return V_285 ;
}
struct V_52 *
F_274 ( struct V_2 * V_3 , struct V_461 * V_230 ,
struct V_403 * V_404 , struct V_369 * V_370 )
{
struct V_52 * V_92 = F_273 ( V_3 ) ;
int V_285 ;
V_285 = F_268 ( & V_92 , V_3 , V_230 , V_404 , V_370 , NULL ) ;
if ( V_285 < 0 )
return F_44 ( V_285 ) ;
return ( V_92 == F_273 ( V_3 ) ) ? F_275 ( V_92 ) : V_92 ;
}
static int F_276 ( struct V_2 * V_2 , struct V_332 * V_480 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_481 args = {
. V_234 = F_93 ( V_2 ) ,
. V_231 = V_14 -> V_400 ,
} ;
struct V_482 V_55 = {
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_483 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_480 -> V_330 ,
} ;
int V_244 = V_480 -> V_334 ;
int V_285 = 0 ;
if ( V_244 & V_338 )
args . V_201 |= V_220 ;
if ( F_277 ( V_2 -> V_484 ) ) {
if ( V_244 & V_485 )
args . V_201 |= V_221 | V_222 | V_486 ;
if ( V_244 & V_337 )
args . V_201 |= V_487 ;
} else {
if ( V_244 & V_485 )
args . V_201 |= V_221 | V_222 ;
if ( V_244 & V_337 )
args . V_201 |= V_223 ;
}
V_55 . V_370 = F_278 () ;
if ( V_55 . V_370 == NULL )
return - V_127 ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
if ( ! V_285 ) {
F_176 ( V_480 , V_55 . V_201 ) ;
F_135 ( V_2 , V_55 . V_370 ) ;
}
F_279 ( V_55 . V_370 ) ;
return V_285 ;
}
static int F_280 ( struct V_2 * V_2 , struct V_332 * V_480 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_276 ( V_2 , V_480 ) ;
F_281 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_282 ( struct V_2 * V_2 , struct V_462 * V_462 ,
unsigned int V_50 , unsigned int V_488 )
{
struct V_489 args = {
. V_234 = F_93 ( V_2 ) ,
. V_50 = V_50 ,
. V_488 = V_488 ,
. V_43 = & V_462 ,
} ;
struct V_490 V_55 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_491 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
return F_73 ( F_85 ( V_2 ) -> V_92 , F_85 ( V_2 ) , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_283 ( struct V_2 * V_2 , struct V_462 * V_462 ,
unsigned int V_50 , unsigned int V_488 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_282 ( V_2 , V_462 , V_50 , V_488 ) ;
F_284 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_285 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_207 )
{
struct V_1 V_17 , * V_371 = NULL ;
struct V_279 * V_280 ;
struct V_65 * V_66 ;
int V_355 = 0 ;
int V_285 = 0 ;
V_280 = F_286 ( V_4 , V_70 ) ;
if ( F_43 ( V_280 ) )
return F_71 ( V_280 ) ;
V_371 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_287 () ;
V_66 = F_213 ( V_3 , V_280 , V_207 , V_6 , V_371 , & V_355 ) ;
if ( F_43 ( V_66 ) ) {
V_285 = F_71 ( V_66 ) ;
goto V_132;
}
V_132:
F_4 ( V_371 ) ;
F_155 ( V_280 ) ;
return V_285 ;
}
static int F_288 ( struct V_2 * V_3 , struct V_461 * V_230 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_492 args = {
. V_234 = F_93 ( V_3 ) ,
. V_230 = * V_230 ,
} ;
struct V_493 V_55 = {
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_494 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
int V_285 ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 1 ) ;
if ( V_285 == 0 )
F_74 ( V_3 , & V_55 . V_172 ) ;
return V_285 ;
}
static int F_289 ( struct V_2 * V_3 , struct V_461 * V_230 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_288 ( V_3 , V_230 ) ;
F_290 ( V_3 , V_230 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_291 ( struct V_162 * V_163 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_492 * args = V_163 -> V_293 ;
struct V_493 * V_55 = V_163 -> V_294 ;
V_55 -> V_14 = V_14 ;
V_163 -> V_290 = & V_291 [ V_494 ] ;
F_38 ( & args -> V_160 , & V_55 -> V_161 , 1 ) ;
F_81 ( V_55 -> V_495 ) ;
}
static void F_292 ( struct V_117 * V_118 , struct V_496 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_3 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_293 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_496 * V_158 = V_118 -> V_497 ;
struct V_493 * V_55 = & V_158 -> V_55 ;
if ( ! F_60 ( V_118 , & V_55 -> V_161 ) )
return 0 ;
if ( F_228 ( V_118 , V_55 -> V_14 , NULL ) == - V_131 )
return 0 ;
F_74 ( V_3 , & V_55 -> V_172 ) ;
return 1 ;
}
static void F_294 ( struct V_162 * V_163 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_498 * V_373 = V_163 -> V_293 ;
struct V_499 * V_55 = V_163 -> V_294 ;
V_163 -> V_290 = & V_291 [ V_500 ] ;
V_55 -> V_14 = V_14 ;
F_38 ( & V_373 -> V_160 , & V_55 -> V_161 , 1 ) ;
}
static void F_295 ( struct V_117 * V_118 , struct V_501 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_502 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_296 ( struct V_117 * V_118 , struct V_2 * V_502 ,
struct V_2 * V_503 )
{
struct V_501 * V_158 = V_118 -> V_497 ;
struct V_499 * V_55 = & V_158 -> V_55 ;
if ( ! F_60 ( V_118 , & V_55 -> V_161 ) )
return 0 ;
if ( F_228 ( V_118 , V_55 -> V_14 , NULL ) == - V_131 )
return 0 ;
F_74 ( V_502 , & V_55 -> V_504 ) ;
F_74 ( V_503 , & V_55 -> V_505 ) ;
return 1 ;
}
static int F_297 ( struct V_2 * V_502 , struct V_461 * V_506 ,
struct V_2 * V_503 , struct V_461 * V_507 )
{
struct V_13 * V_14 = F_85 ( V_502 ) ;
struct V_498 V_373 = {
. V_502 = F_93 ( V_502 ) ,
. V_503 = F_93 ( V_503 ) ,
. V_506 = V_506 ,
. V_507 = V_507 ,
} ;
struct V_499 V_55 = {
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_500 ] ,
. V_293 = & V_373 ,
. V_294 = & V_55 ,
} ;
int V_285 = - V_127 ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_373 . V_160 , & V_55 . V_161 , 1 ) ;
if ( ! V_285 ) {
F_74 ( V_502 , & V_55 . V_504 ) ;
F_74 ( V_503 , & V_55 . V_505 ) ;
}
return V_285 ;
}
static int F_298 ( struct V_2 * V_502 , struct V_461 * V_506 ,
struct V_2 * V_503 , struct V_461 * V_507 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_297 ( V_502 , V_506 ,
V_503 , V_507 ) ;
F_299 ( V_502 , V_506 , V_503 , V_507 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_502 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_300 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_461 * V_230 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_508 V_373 = {
. V_234 = F_93 ( V_2 ) ,
. V_472 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_509 V_55 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_510 ] ,
. V_293 = & V_373 ,
. V_294 = & V_55 ,
} ;
int V_285 = - V_127 ;
V_55 . V_370 = F_278 () ;
if ( V_55 . V_370 == NULL )
goto V_132;
V_55 . V_7 = F_87 ( V_14 , V_361 ) ;
if ( F_43 ( V_55 . V_7 ) ) {
V_285 = F_71 ( V_55 . V_7 ) ;
goto V_132;
}
V_373 . V_231 = F_6 ( V_14 , V_55 . V_7 ) ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_373 . V_160 , & V_55 . V_161 , 1 ) ;
if ( ! V_285 ) {
F_74 ( V_3 , & V_55 . V_172 ) ;
V_285 = F_210 ( V_2 , V_55 . V_370 ) ;
if ( ! V_285 )
F_211 ( V_2 , V_55 . V_370 , V_55 . V_7 ) ;
}
F_95 ( V_55 . V_7 ) ;
V_132:
F_279 ( V_55 . V_370 ) ;
return V_285 ;
}
static int F_301 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_461 * V_230 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( F_85 ( V_2 ) ,
F_300 ( V_2 , V_3 , V_230 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static struct V_511 * F_302 ( struct V_2 * V_3 ,
struct V_461 * V_230 , struct V_5 * V_6 , T_1 V_512 )
{
struct V_511 * V_158 ;
V_158 = F_86 ( sizeof( * V_158 ) , V_361 ) ;
if ( V_158 != NULL ) {
struct V_13 * V_14 = F_85 ( V_3 ) ;
V_158 -> V_7 = F_87 ( V_14 , V_361 ) ;
if ( F_43 ( V_158 -> V_7 ) )
goto V_289;
V_158 -> V_163 . V_290 = & V_291 [ V_513 ] ;
V_158 -> V_163 . V_293 = & V_158 -> V_373 ;
V_158 -> V_163 . V_294 = & V_158 -> V_55 ;
V_158 -> V_373 . V_472 = F_93 ( V_3 ) ;
V_158 -> V_373 . V_14 = V_14 ;
V_158 -> V_373 . V_230 = V_230 ;
V_158 -> V_373 . V_208 = V_6 ;
V_158 -> V_373 . V_512 = V_512 ;
V_158 -> V_373 . V_231 = F_6 ( V_14 , V_158 -> V_7 ) ;
V_158 -> V_55 . V_14 = V_14 ;
V_158 -> V_55 . V_234 = & V_158 -> V_234 ;
V_158 -> V_55 . V_370 = & V_158 -> V_370 ;
V_158 -> V_55 . V_7 = V_158 -> V_7 ;
F_81 ( V_158 -> V_55 . V_370 ) ;
}
return V_158 ;
V_289:
F_96 ( V_158 ) ;
return NULL ;
}
static int F_303 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_511 * V_158 )
{
int V_285 = F_73 ( F_85 ( V_3 ) -> V_92 , F_85 ( V_3 ) , & V_158 -> V_163 ,
& V_158 -> V_373 . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
if ( V_285 == 0 ) {
F_74 ( V_3 , & V_158 -> V_55 . V_514 ) ;
V_285 = F_304 ( V_4 , V_158 -> V_55 . V_234 , V_158 -> V_55 . V_370 , V_158 -> V_55 . V_7 ) ;
}
return V_285 ;
}
static void F_305 ( struct V_511 * V_158 )
{
F_95 ( V_158 -> V_7 ) ;
F_96 ( V_158 ) ;
}
static int F_306 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_462 * V_462 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_511 * V_158 ;
int V_285 = - V_515 ;
if ( V_12 > V_516 )
goto V_132;
V_285 = - V_127 ;
V_158 = F_302 ( V_3 , & V_4 -> V_11 , V_6 , V_517 ) ;
if ( V_158 == NULL )
goto V_132;
V_158 -> V_163 . V_290 = & V_291 [ V_518 ] ;
V_158 -> V_373 . V_238 . V_519 . V_43 = & V_462 ;
V_158 -> V_373 . V_238 . V_519 . V_12 = V_12 ;
V_158 -> V_373 . V_7 = V_7 ;
V_285 = F_303 ( V_3 , V_4 , V_158 ) ;
F_305 ( V_158 ) ;
V_132:
return V_285 ;
}
static int F_307 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_462 * V_462 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_306 ( V_3 , V_4 , V_462 , V_12 , V_6 , V_7 ) ;
F_308 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_309 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_511 * V_158 ;
int V_285 = - V_127 ;
V_158 = F_302 ( V_3 , & V_4 -> V_11 , V_6 , V_520 ) ;
if ( V_158 == NULL )
goto V_132;
V_158 -> V_373 . V_7 = V_7 ;
V_285 = F_303 ( V_3 , V_4 , V_158 ) ;
F_305 ( V_158 ) ;
V_132:
return V_285 ;
}
static int F_310 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_287 () ;
do {
V_8 = F_309 ( V_3 , V_4 , V_6 , V_7 ) ;
F_311 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_312 ( struct V_4 * V_4 , struct V_295 * V_330 ,
T_2 V_37 , struct V_462 * * V_43 , unsigned int V_51 , int V_521 )
{
struct V_2 * V_3 = V_4 -> V_47 ;
struct V_39 args = {
. V_234 = F_93 ( V_3 ) ,
. V_43 = V_43 ,
. V_50 = 0 ,
. V_51 = V_51 ,
. V_231 = F_85 ( V_4 -> V_47 ) -> V_15 ,
. V_521 = V_521 ,
} ;
struct V_522 V_55 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_523 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
int V_285 ;
F_8 ( L_38 , V_35 ,
V_4 ,
( unsigned long long ) V_37 ) ;
F_9 ( V_37 , F_75 ( V_3 ) -> V_524 , V_4 , & args ) ;
V_55 . V_50 = args . V_50 ;
V_285 = F_73 ( F_85 ( V_3 ) -> V_92 , F_85 ( V_3 ) , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
if ( V_285 >= 0 ) {
memcpy ( F_75 ( V_3 ) -> V_524 , V_55 . V_38 . V_158 , V_525 ) ;
V_285 += args . V_50 ;
}
F_313 ( V_3 ) ;
F_8 ( L_39 , V_35 , V_285 ) ;
return V_285 ;
}
static int F_314 ( struct V_4 * V_4 , struct V_295 * V_330 ,
T_2 V_37 , struct V_462 * * V_43 , unsigned int V_51 , int V_521 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_312 ( V_4 , V_330 , V_37 ,
V_43 , V_51 , V_521 ) ;
F_315 ( V_4 -> V_47 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_4 -> V_47 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_316 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_526 )
{
struct V_511 * V_158 ;
int V_244 = V_6 -> V_10 ;
int V_285 = - V_127 ;
V_158 = F_302 ( V_3 , & V_4 -> V_11 , V_6 , V_527 ) ;
if ( V_158 == NULL )
goto V_132;
if ( F_317 ( V_244 ) )
V_158 -> V_373 . V_512 = V_528 ;
else if ( F_318 ( V_244 ) ) {
V_158 -> V_373 . V_512 = V_529 ;
V_158 -> V_373 . V_238 . V_530 . V_531 = F_319 ( V_526 ) ;
V_158 -> V_373 . V_238 . V_530 . V_532 = F_320 ( V_526 ) ;
}
else if ( F_321 ( V_244 ) ) {
V_158 -> V_373 . V_512 = V_533 ;
V_158 -> V_373 . V_238 . V_530 . V_531 = F_319 ( V_526 ) ;
V_158 -> V_373 . V_238 . V_530 . V_532 = F_320 ( V_526 ) ;
} else if ( ! F_322 ( V_244 ) ) {
V_285 = - V_27 ;
goto V_289;
}
V_158 -> V_373 . V_7 = V_7 ;
V_285 = F_303 ( V_3 , V_4 , V_158 ) ;
V_289:
F_305 ( V_158 ) ;
V_132:
return V_285 ;
}
static int F_323 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_526 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_287 () ;
do {
V_8 = F_316 ( V_3 , V_4 , V_6 , V_7 , V_526 ) ;
F_324 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_325 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_534 * V_535 )
{
struct V_536 args = {
. V_234 = V_404 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_537 V_55 = {
. V_535 = V_535 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_538 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
F_81 ( V_535 -> V_370 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_326 ( struct V_13 * V_14 , struct V_403 * V_404 , struct V_534 * V_535 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_325 ( V_14 , V_404 , V_535 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_327 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_539 )
{
struct V_540 args = {
. V_234 = V_404 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_541 V_55 = {
. V_539 = V_539 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_542 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_251 ( struct V_13 * V_14 , struct V_403 * V_404 , struct V_437 * V_539 )
{
struct V_61 V_62 = { } ;
unsigned long V_543 = V_155 ;
int V_8 ;
do {
V_8 = F_327 ( V_14 , V_404 , V_539 ) ;
F_328 ( V_14 , V_404 , V_539 -> V_370 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_63 * V_64 = V_14 -> V_63 ;
F_34 ( & V_64 -> V_108 ) ;
V_64 -> V_544 = V_539 -> V_545 * V_89 ;
V_64 -> V_109 = V_543 ;
F_36 ( & V_64 -> V_108 ) ;
break;
}
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_329 ( struct V_13 * V_14 , struct V_403 * V_404 , struct V_437 * V_539 )
{
int error ;
F_81 ( V_539 -> V_370 ) ;
error = F_251 ( V_14 , V_404 , V_539 ) ;
if ( error == 0 ) {
V_14 -> V_546 = V_539 -> V_547 ;
F_330 ( V_14 , V_404 , V_539 -> V_548 ) ;
}
return error ;
}
static int F_331 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_549 * V_550 )
{
struct V_551 args = {
. V_234 = V_404 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_552 V_55 = {
. V_550 = V_550 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_553 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
if ( ( args . V_231 [ 0 ] & V_554 [ 0 ] ) == 0 ) {
memset ( V_550 , 0 , sizeof( * V_550 ) ) ;
return 0 ;
}
F_81 ( V_550 -> V_370 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_332 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_549 * V_550 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_331 ( V_14 , V_404 , V_550 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
int F_333 ( T_8 * V_240 ,
const struct V_279 * V_280 ,
const struct V_555 * V_556 ,
T_5 V_206 )
{
const struct V_379 * V_380 = NULL ;
if ( V_556 != NULL )
V_380 = & V_556 -> V_380 ;
return F_219 ( V_240 , V_280 -> V_66 , V_206 , V_380 ) ;
}
static bool F_334 ( T_8 * V_240 ,
const struct V_279 * V_280 ,
const struct V_555 * V_556 ,
T_5 V_206 )
{
T_8 V_557 ;
if ( F_333 ( & V_557 , V_280 , V_556 , V_206 ) == - V_36 )
return true ;
return F_124 ( V_240 , & V_557 ) ;
}
static bool F_335 ( int V_8 )
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
void F_336 ( struct V_558 * V_158 )
{
F_313 ( V_158 -> V_559 -> V_2 ) ;
}
static int F_337 ( struct V_117 * V_118 , struct V_558 * V_158 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_559 -> V_2 ) ;
F_338 ( V_158 , V_118 -> V_150 ) ;
if ( F_228 ( V_118 , V_14 , V_158 -> args . V_560 -> V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
F_336 ( V_158 ) ;
if ( V_118 -> V_150 > 0 )
F_37 ( V_14 , V_158 -> V_107 ) ;
return 0 ;
}
static bool F_339 ( struct V_117 * V_118 ,
struct V_561 * args )
{
if ( ! F_335 ( V_118 -> V_150 ) ||
F_334 ( & args -> V_240 ,
args -> V_560 ,
args -> V_562 ,
V_70 ) )
return false ;
F_57 ( V_118 ) ;
return true ;
}
static int F_340 ( struct V_117 * V_118 , struct V_558 * V_158 )
{
F_8 ( L_11 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return - V_131 ;
if ( F_339 ( V_118 , & V_158 -> args ) )
return - V_131 ;
return V_158 -> V_563 ? V_158 -> V_563 ( V_118 , V_158 ) :
F_337 ( V_118 , V_158 ) ;
}
static void F_341 ( struct V_558 * V_158 , struct V_162 * V_163 )
{
V_158 -> V_107 = V_155 ;
V_158 -> V_563 = F_337 ;
V_163 -> V_290 = & V_291 [ V_564 ] ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 0 ) ;
}
static int F_342 ( struct V_117 * V_118 , struct V_558 * V_158 )
{
if ( F_63 ( F_85 ( V_158 -> V_559 -> V_2 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) )
return 0 ;
if ( F_333 ( & V_158 -> args . V_240 , V_158 -> args . V_560 ,
V_158 -> args . V_562 , V_70 ) == - V_36 )
return - V_36 ;
if ( F_343 ( F_31 ( V_565 , & V_158 -> args . V_560 -> V_207 ) ) )
return - V_36 ;
return 0 ;
}
static int F_344 ( struct V_117 * V_118 , struct V_566 * V_158 )
{
struct V_2 * V_2 = V_158 -> V_559 -> V_2 ;
F_345 ( V_158 , V_118 -> V_150 ) ;
if ( F_228 ( V_118 , F_85 ( V_2 ) , V_158 -> args . V_560 -> V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
if ( V_118 -> V_150 >= 0 ) {
F_37 ( F_85 ( V_2 ) , V_158 -> V_107 ) ;
F_346 ( V_2 , & V_158 -> V_370 ) ;
}
return 0 ;
}
static bool F_347 ( struct V_117 * V_118 ,
struct V_567 * args )
{
if ( ! F_335 ( V_118 -> V_150 ) ||
F_334 ( & args -> V_240 ,
args -> V_560 ,
args -> V_562 ,
V_218 ) )
return false ;
F_57 ( V_118 ) ;
return true ;
}
static int F_348 ( struct V_117 * V_118 , struct V_566 * V_158 )
{
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return - V_131 ;
if ( F_347 ( V_118 , & V_158 -> args ) )
return - V_131 ;
return V_158 -> V_568 ? V_158 -> V_568 ( V_118 , V_158 ) :
F_344 ( V_118 , V_158 ) ;
}
static
bool F_349 ( const struct V_566 * V_158 )
{
const struct V_569 * V_570 = V_158 -> V_559 ;
if ( V_158 -> V_571 != NULL || V_570 -> V_572 != NULL )
return false ;
return F_20 ( V_570 -> V_2 , V_70 ) == 0 ;
}
static void F_350 ( struct V_566 * V_158 , struct V_162 * V_163 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_559 -> V_2 ) ;
if ( ! F_349 ( V_158 ) ) {
V_158 -> args . V_231 = NULL ;
V_158 -> V_55 . V_370 = NULL ;
} else
V_158 -> args . V_231 = V_14 -> V_400 ;
if ( ! V_158 -> V_568 )
V_158 -> V_568 = F_344 ;
V_158 -> V_55 . V_14 = V_14 ;
V_158 -> V_107 = V_155 ;
V_163 -> V_290 = & V_291 [ V_573 ] ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
}
static int F_351 ( struct V_117 * V_118 , struct V_566 * V_158 )
{
if ( F_63 ( F_85 ( V_158 -> V_559 -> V_2 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) )
return 0 ;
if ( F_333 ( & V_158 -> args . V_240 , V_158 -> args . V_560 ,
V_158 -> args . V_562 , V_218 ) == - V_36 )
return - V_36 ;
if ( F_343 ( F_31 ( V_565 , & V_158 -> args . V_560 -> V_207 ) ) )
return - V_36 ;
return 0 ;
}
static void F_352 ( struct V_117 * V_118 , struct V_574 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_2 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_353 ( struct V_117 * V_118 , struct V_574 * V_158 )
{
struct V_2 * V_2 = V_158 -> V_2 ;
F_354 ( V_158 , V_118 -> V_150 ) ;
if ( F_228 ( V_118 , F_85 ( V_2 ) , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_355 ( struct V_117 * V_118 , struct V_574 * V_158 )
{
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return - V_131 ;
return V_158 -> V_575 ( V_118 , V_158 ) ;
}
static void F_356 ( struct V_574 * V_158 , struct V_162 * V_163 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_2 ) ;
if ( V_158 -> V_575 == NULL )
V_158 -> V_575 = F_353 ;
V_158 -> V_55 . V_14 = V_14 ;
V_163 -> V_290 = & V_291 [ V_576 ] ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
}
static void F_357 ( void * V_156 )
{
struct V_577 * V_158 = V_156 ;
struct V_63 * V_64 = V_158 -> V_92 ;
if ( F_358 ( & V_64 -> V_578 ) > 1 )
F_359 ( V_64 ) ;
F_360 ( V_64 ) ;
F_96 ( V_158 ) ;
}
static void F_361 ( struct V_117 * V_118 , void * V_156 )
{
struct V_577 * V_158 = V_156 ;
struct V_63 * V_64 = V_158 -> V_92 ;
unsigned long V_107 = V_158 -> V_107 ;
F_362 ( V_64 , V_118 -> V_150 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
break;
case - V_79 :
F_26 ( V_64 ) ;
break;
default:
if ( F_31 ( V_579 , & V_64 -> V_580 ) == 0 )
return;
if ( V_118 -> V_150 != V_581 ) {
F_24 ( V_64 ) ;
return;
}
F_363 ( V_64 ) ;
}
F_33 ( V_64 , V_107 ) ;
}
static int F_364 ( struct V_63 * V_64 , struct V_295 * V_330 , unsigned V_582 )
{
struct V_162 V_163 = {
. V_290 = & V_291 [ V_583 ] ,
. V_293 = V_64 ,
. V_295 = V_330 ,
} ;
struct V_577 * V_158 ;
if ( V_582 == 0 )
return 0 ;
if ( ! F_365 ( & V_64 -> V_578 ) )
return - V_36 ;
V_158 = F_257 ( sizeof( * V_158 ) , V_282 ) ;
if ( V_158 == NULL )
return - V_127 ;
V_158 -> V_92 = V_64 ;
V_158 -> V_107 = V_155 ;
return F_366 ( V_64 -> V_102 , & V_163 , V_584 ,
& V_585 , V_158 ) ;
}
static int F_367 ( struct V_63 * V_64 , struct V_295 * V_330 )
{
struct V_162 V_163 = {
. V_290 = & V_291 [ V_583 ] ,
. V_293 = V_64 ,
. V_295 = V_330 ,
} ;
unsigned long V_543 = V_155 ;
int V_285 ;
V_285 = F_368 ( V_64 -> V_102 , & V_163 , V_584 ) ;
if ( V_285 < 0 )
return V_285 ;
F_33 ( V_64 , V_543 ) ;
return 0 ;
}
static inline int F_369 ( struct V_13 * V_14 )
{
return V_14 -> V_95 & V_412 ;
}
static int F_370 ( const void * V_586 , T_9 V_587 ,
struct V_462 * * V_43 , unsigned int * V_50 )
{
struct V_462 * V_588 , * * V_589 ;
int V_590 = 0 ;
T_9 V_12 ;
V_589 = V_43 ;
do {
V_12 = F_371 ( T_9 , V_591 , V_587 ) ;
V_588 = F_256 ( V_361 ) ;
if ( V_588 == NULL )
goto V_592;
memcpy ( F_372 ( V_588 ) , V_586 , V_12 ) ;
V_586 += V_12 ;
V_587 -= V_12 ;
* V_43 ++ = V_588 ;
V_590 ++ ;
} while ( V_587 != 0 );
return V_590 ;
V_592:
for(; V_590 > 0 ; V_590 -- )
F_260 ( V_589 [ V_590 - 1 ] ) ;
return - V_127 ;
}
static void F_373 ( struct V_2 * V_2 , struct V_593 * V_594 )
{
struct V_173 * V_174 = F_75 ( V_2 ) ;
F_34 ( & V_2 -> V_175 ) ;
F_96 ( V_174 -> V_595 ) ;
V_174 -> V_595 = V_594 ;
F_36 ( & V_2 -> V_175 ) ;
}
static void F_374 ( struct V_2 * V_2 )
{
F_373 ( V_2 , NULL ) ;
}
static inline T_11 F_375 ( struct V_2 * V_2 , char * V_586 , T_9 V_587 )
{
struct V_173 * V_174 = F_75 ( V_2 ) ;
struct V_593 * V_594 ;
int V_67 = - V_281 ;
F_34 ( & V_2 -> V_175 ) ;
V_594 = V_174 -> V_595 ;
if ( V_594 == NULL )
goto V_132;
if ( V_586 == NULL )
goto V_596;
if ( V_594 -> V_597 == 0 )
goto V_132;
V_67 = - V_598 ;
if ( V_594 -> V_12 > V_587 )
goto V_132;
memcpy ( V_586 , V_594 -> V_158 , V_594 -> V_12 ) ;
V_596:
V_67 = V_594 -> V_12 ;
V_132:
F_36 ( & V_2 -> V_175 ) ;
return V_67 ;
}
static void F_376 ( struct V_2 * V_2 , struct V_462 * * V_43 , T_9 V_50 , T_9 V_599 )
{
struct V_593 * V_594 ;
T_9 V_587 = sizeof( * V_594 ) + V_599 ;
if ( V_587 <= V_591 ) {
V_594 = F_257 ( V_587 , V_361 ) ;
if ( V_594 == NULL )
goto V_132;
V_594 -> V_597 = 1 ;
F_377 ( V_594 -> V_158 , V_43 , V_50 , V_599 ) ;
} else {
V_594 = F_257 ( sizeof( * V_594 ) , V_361 ) ;
if ( V_594 == NULL )
goto V_132;
V_594 -> V_597 = 0 ;
}
V_594 -> V_12 = V_599 ;
V_132:
F_373 ( V_2 , V_594 ) ;
}
static T_11 F_378 ( struct V_2 * V_2 , void * V_586 , T_9 V_587 )
{
struct V_462 * V_43 [ V_600 ] = { NULL , } ;
struct V_601 args = {
. V_234 = F_93 ( V_2 ) ,
. V_602 = V_43 ,
. V_599 = V_587 ,
} ;
struct V_603 V_55 = {
. V_599 = V_587 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_604 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
unsigned int V_605 = F_379 ( V_587 , V_591 ) ;
int V_67 = - V_127 , V_451 ;
if ( V_605 == 0 )
V_605 = 1 ;
if ( V_605 > F_247 ( V_43 ) )
return - V_598 ;
for ( V_451 = 0 ; V_451 < V_605 ; V_451 ++ ) {
V_43 [ V_451 ] = F_256 ( V_361 ) ;
if ( ! V_43 [ V_451 ] )
goto V_289;
}
V_55 . V_606 = F_256 ( V_361 ) ;
if ( ! V_55 . V_606 )
goto V_289;
args . V_599 = V_605 * V_591 ;
args . V_607 = 0 ;
F_8 ( L_40 ,
V_35 , V_586 , V_587 , V_605 , args . V_599 ) ;
V_67 = F_73 ( F_85 ( V_2 ) -> V_92 , F_85 ( V_2 ) ,
& V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
if ( V_67 )
goto V_289;
if ( V_55 . V_608 & V_609 ) {
if ( V_586 == NULL )
goto V_610;
V_67 = - V_598 ;
goto V_289;
}
F_376 ( V_2 , V_43 , V_55 . V_611 , V_55 . V_599 ) ;
if ( V_586 ) {
if ( V_55 . V_599 > V_587 ) {
V_67 = - V_598 ;
goto V_289;
}
F_377 ( V_586 , V_43 , V_55 . V_611 , V_55 . V_599 ) ;
}
V_610:
V_67 = V_55 . V_599 ;
V_289:
for ( V_451 = 0 ; V_451 < V_605 ; V_451 ++ )
if ( V_43 [ V_451 ] )
F_260 ( V_43 [ V_451 ] ) ;
if ( V_55 . V_606 )
F_260 ( V_55 . V_606 ) ;
return V_67 ;
}
static T_11 F_380 ( struct V_2 * V_2 , void * V_586 , T_9 V_587 )
{
struct V_61 V_62 = { } ;
T_11 V_67 ;
do {
V_67 = F_378 ( V_2 , V_586 , V_587 ) ;
F_381 ( V_2 , V_67 ) ;
if ( V_67 >= 0 )
break;
V_67 = F_19 ( F_85 ( V_2 ) , V_67 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_67 ;
}
static T_11 F_382 ( struct V_2 * V_2 , void * V_586 , T_9 V_587 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
int V_67 ;
if ( ! F_369 ( V_14 ) )
return - V_612 ;
V_67 = F_383 ( V_14 , V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( F_75 ( V_2 ) -> V_176 & V_613 )
F_384 ( V_2 ) ;
V_67 = F_375 ( V_2 , V_586 , V_587 ) ;
if ( V_67 != - V_281 )
return V_67 ;
return F_380 ( V_2 , V_586 , V_587 ) ;
}
static int F_385 ( struct V_2 * V_2 , const void * V_586 , T_9 V_587 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_462 * V_43 [ V_600 ] ;
struct V_614 V_373 = {
. V_234 = F_93 ( V_2 ) ,
. V_602 = V_43 ,
. V_599 = V_587 ,
} ;
struct V_615 V_55 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_616 ] ,
. V_293 = & V_373 ,
. V_294 = & V_55 ,
} ;
unsigned int V_605 = F_379 ( V_587 , V_591 ) ;
int V_67 , V_451 ;
if ( ! F_369 ( V_14 ) )
return - V_612 ;
if ( V_605 > F_247 ( V_43 ) )
return - V_598 ;
V_451 = F_370 ( V_586 , V_587 , V_373 . V_602 , & V_373 . V_607 ) ;
if ( V_451 < 0 )
return V_451 ;
F_21 ( V_2 ) ;
V_67 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_373 . V_160 , & V_55 . V_161 , 1 ) ;
for (; V_451 > 0 ; V_451 -- )
F_386 ( V_43 [ V_451 - 1 ] ) ;
F_34 ( & V_2 -> V_175 ) ;
F_75 ( V_2 ) -> V_176 |= V_177 ;
F_36 ( & V_2 -> V_175 ) ;
F_387 ( V_2 ) ;
F_384 ( V_2 ) ;
return V_67 ;
}
static int F_388 ( struct V_2 * V_2 , const void * V_586 , T_9 V_587 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_385 ( V_2 , V_586 , V_587 ) ;
F_389 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_390 ( struct V_2 * V_2 , void * V_586 ,
T_9 V_587 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_369 V_370 ;
struct V_1 V_7 = { 0 , 0 , V_587 , V_586 } ;
T_1 V_231 [ 3 ] = { 0 , 0 , V_433 } ;
struct V_465 V_373 = {
. V_234 = F_93 ( V_2 ) ,
. V_231 = V_231 ,
} ;
struct V_466 V_55 = {
. V_370 = & V_370 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_467 ] ,
. V_293 = & V_373 ,
. V_294 = & V_55 ,
} ;
int V_67 ;
F_81 ( & V_370 ) ;
V_67 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_373 . V_160 , & V_55 . V_161 , 0 ) ;
if ( V_67 )
return V_67 ;
if ( ! ( V_370 . V_276 & V_617 ) )
return - V_281 ;
if ( V_587 < V_7 . V_12 )
return - V_598 ;
return 0 ;
}
static int F_391 ( struct V_2 * V_2 , void * V_586 ,
T_9 V_587 )
{
struct V_61 V_62 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_612 ;
do {
V_8 = F_390 ( V_2 , V_586 , V_587 ) ;
F_392 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_393 ( struct V_2 * V_2 ,
struct V_1 * V_371 ,
struct V_369 * V_370 ,
struct V_1 * V_360 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
const T_1 V_231 [ 3 ] = { 0 , 0 , V_433 } ;
struct V_372 V_373 = {
. V_234 = F_93 ( V_2 ) ,
. V_374 = & V_6 ,
. V_14 = V_14 ,
. V_231 = V_231 ,
. V_7 = V_371 ,
} ;
struct V_375 V_55 = {
. V_370 = V_370 ,
. V_7 = V_360 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_376 ] ,
. V_293 = & V_373 ,
. V_294 = & V_55 ,
} ;
int V_285 ;
F_115 ( & V_373 . V_240 , & V_386 ) ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_373 . V_160 , & V_55 . V_161 , 1 ) ;
if ( V_285 )
F_8 ( L_41 , V_35 , V_285 ) ;
return V_285 ;
}
static int F_394 ( struct V_2 * V_2 ,
struct V_1 * V_371 ,
struct V_369 * V_370 ,
struct V_1 * V_360 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_393 ( V_2 , V_371 ,
V_370 , V_360 ) ;
F_395 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_396 ( struct V_4 * V_4 , const void * V_586 , T_9 V_587 )
{
struct V_1 V_371 , * V_360 = NULL ;
struct V_369 V_370 ;
struct V_295 * V_330 ;
struct V_2 * V_2 = V_4 -> V_47 ;
int V_285 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_612 ;
F_81 ( & V_370 ) ;
V_371 . V_618 = 0 ;
V_371 . V_619 = 0 ;
V_371 . V_7 = ( char * ) V_586 ;
V_371 . V_12 = V_587 ;
V_330 = F_397 () ;
if ( F_43 ( V_330 ) )
return F_71 ( V_330 ) ;
V_360 = F_87 ( F_85 ( V_2 ) , V_361 ) ;
if ( F_43 ( V_360 ) ) {
V_285 = - F_71 ( V_360 ) ;
goto V_132;
}
V_285 = F_394 ( V_2 , & V_371 , & V_370 , V_360 ) ;
if ( V_285 == 0 )
F_211 ( V_2 , & V_370 , V_360 ) ;
F_95 ( V_360 ) ;
V_132:
F_192 ( V_330 ) ;
return V_285 ;
}
static int
F_228 ( struct V_117 * V_118 , const struct V_13 * V_14 , struct V_65 * V_66 )
{
struct V_63 * V_64 = V_14 -> V_63 ;
if ( V_118 -> V_150 >= 0 )
return 0 ;
switch( V_118 -> V_150 ) {
case - V_72 :
case - V_73 :
case - V_74 :
if ( V_66 == NULL )
break;
F_23 ( V_66 -> V_2 ) ;
case - V_69 :
if ( V_66 == NULL )
break;
if ( F_22 ( V_14 , V_66 ) < 0 )
goto V_620;
goto V_71;
case - V_75 :
if ( V_66 != NULL ) {
if ( F_22 ( V_14 , V_66 ) < 0 )
goto V_620;
}
case - V_76 :
case - V_77 :
F_24 ( V_64 ) ;
goto V_71;
case - V_78 :
if ( F_25 ( V_14 ) < 0 )
goto V_620;
goto V_71;
case - V_79 :
F_26 ( V_64 ) ;
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
F_28 ( V_64 -> V_88 , V_118 -> V_150 ) ;
goto V_71;
#endif
case - V_91 :
F_398 ( V_14 , V_621 ) ;
case - V_90 :
F_59 ( V_118 , V_57 ) ;
case - V_93 :
case - V_94 :
goto V_622;
}
V_118 -> V_150 = F_7 ( V_118 -> V_150 ) ;
return 0 ;
V_620:
V_118 -> V_150 = - V_36 ;
return 0 ;
V_71:
F_47 ( & V_64 -> V_623 , V_118 , NULL ) ;
if ( F_31 ( V_624 , & V_64 -> V_625 ) == 0 )
F_399 ( & V_64 -> V_623 , V_118 ) ;
if ( F_31 ( V_99 , & V_14 -> V_100 ) )
goto V_620;
V_622:
V_118 -> V_150 = 0 ;
return - V_131 ;
}
static void F_400 ( const struct V_63 * V_64 ,
T_12 * V_626 )
{
T_3 V_237 [ 2 ] ;
if ( F_31 ( V_627 , & V_64 -> V_625 ) ) {
V_237 [ 0 ] = 0 ;
V_237 [ 1 ] = F_401 ( V_628 + 1 ) ;
} else {
struct V_629 * V_630 = F_402 ( V_64 -> V_631 , V_632 ) ;
V_237 [ 0 ] = F_401 ( V_630 -> V_633 . V_634 ) ;
V_237 [ 1 ] = F_401 ( V_630 -> V_633 . V_635 ) ;
}
memcpy ( V_626 -> V_158 , V_237 , sizeof( V_626 -> V_158 ) ) ;
}
static unsigned int
F_403 ( const struct V_63 * V_64 ,
char * V_586 , T_9 V_12 )
{
unsigned int V_636 ;
F_122 () ;
V_636 = F_404 ( V_586 , V_12 , L_43 ,
V_64 -> V_637 ,
F_405 ( V_64 -> V_102 ,
V_638 ) ,
F_405 ( V_64 -> V_102 ,
V_639 ) ) ;
F_125 () ;
return V_636 ;
}
static unsigned int
F_406 ( const struct V_63 * V_64 ,
char * V_586 , T_9 V_12 )
{
const char * V_640 = V_64 -> V_102 -> V_641 ;
if ( V_642 [ 0 ] != '\0' )
return F_404 ( V_586 , V_12 , L_44 ,
V_64 -> V_643 -> V_644 ,
V_64 -> V_408 ,
V_642 ,
V_640 ) ;
return F_404 ( V_586 , V_12 , L_45 ,
V_64 -> V_643 -> V_644 , V_64 -> V_408 ,
V_640 ) ;
}
int F_407 ( struct V_63 * V_64 , T_1 V_645 ,
unsigned short V_646 , struct V_295 * V_330 ,
struct V_647 * V_55 )
{
T_12 V_648 ;
struct V_649 V_650 = {
. V_648 = & V_648 ,
. V_651 = V_645 ,
. V_652 = V_64 -> V_653 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_654 ] ,
. V_293 = & V_650 ,
. V_294 = V_55 ,
. V_295 = V_330 ,
} ;
int V_285 ;
F_400 ( V_64 , & V_648 ) ;
if ( F_31 ( V_655 , & V_64 -> V_656 ) )
V_650 . V_657 =
F_406 ( V_64 ,
V_650 . V_658 ,
sizeof( V_650 . V_658 ) ) ;
else
V_650 . V_657 =
F_403 ( V_64 ,
V_650 . V_658 ,
sizeof( V_650 . V_658 ) ) ;
F_122 () ;
V_650 . V_659 = F_404 ( V_650 . V_660 ,
sizeof( V_650 . V_660 ) , L_46 ,
F_405 ( V_64 -> V_102 ,
V_661 ) ) ;
F_125 () ;
V_650 . V_662 = F_404 ( V_650 . V_663 ,
sizeof( V_650 . V_663 ) , L_47 ,
V_64 -> V_637 , V_646 >> 8 , V_646 & 255 ) ;
F_8 ( L_48 ,
V_64 -> V_102 -> V_103 -> V_664 -> V_665 ,
V_650 . V_657 , V_650 . V_658 ) ;
V_285 = F_368 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_408 ( V_64 , V_285 ) ;
F_8 ( L_49 , V_285 ) ;
return V_285 ;
}
int F_409 ( struct V_63 * V_64 ,
struct V_647 * V_373 ,
struct V_295 * V_330 )
{
struct V_162 V_163 = {
. V_290 = & V_291 [ V_666 ] ,
. V_293 = V_373 ,
. V_295 = V_330 ,
} ;
int V_285 ;
F_8 ( L_50 ,
V_64 -> V_102 -> V_103 -> V_664 -> V_665 ,
V_64 -> V_225 ) ;
V_285 = F_368 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_410 ( V_64 , V_285 ) ;
F_8 ( L_51 , V_285 ) ;
return V_285 ;
}
static void F_411 ( struct V_117 * V_118 , void * V_156 )
{
struct V_667 * V_158 = V_156 ;
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return;
F_412 ( & V_158 -> args , & V_158 -> V_55 , V_118 -> V_150 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
F_37 ( V_158 -> V_55 . V_14 , V_158 -> V_107 ) ;
break;
case - V_73 :
case - V_72 :
case - V_74 :
case - V_94 :
case - V_76 :
case - V_75 :
V_118 -> V_150 = 0 ;
break;
default:
if ( F_228 ( V_118 , V_158 -> V_55 . V_14 , NULL ) ==
- V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
V_158 -> V_273 = V_118 -> V_150 ;
}
static void F_413 ( void * V_156 )
{
F_96 ( V_156 ) ;
}
static void F_414 ( struct V_117 * V_118 , void * V_158 )
{
struct V_667 * V_668 ;
V_668 = (struct V_667 * ) V_158 ;
F_63 ( V_668 -> V_55 . V_14 ,
& V_668 -> args . V_160 ,
& V_668 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_415 ( struct V_2 * V_2 , struct V_295 * V_330 , const T_8 * V_240 , int V_669 )
{
struct V_667 * V_158 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_670 ] ,
. V_295 = V_330 ,
} ;
struct V_164 V_296 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_671 ,
. V_207 = V_300 ,
} ;
int V_285 = 0 ;
V_158 = F_86 ( sizeof( * V_158 ) , V_282 ) ;
if ( V_158 == NULL )
return - V_127 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
V_158 -> args . V_404 = & V_158 -> V_234 ;
V_158 -> args . V_240 = & V_158 -> V_240 ;
V_158 -> args . V_231 = V_14 -> V_400 ;
F_169 ( & V_158 -> V_234 , F_93 ( V_2 ) ) ;
F_115 ( & V_158 -> V_240 , V_240 ) ;
V_158 -> V_55 . V_370 = & V_158 -> V_370 ;
V_158 -> V_55 . V_14 = V_14 ;
F_81 ( V_158 -> V_55 . V_370 ) ;
V_158 -> V_107 = V_155 ;
V_158 -> V_273 = 0 ;
V_296 . V_170 = V_158 ;
V_163 . V_293 = & V_158 -> args ;
V_163 . V_294 = & V_158 -> V_55 ;
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
if ( ! V_669 )
goto V_132;
V_285 = F_107 ( V_118 ) ;
if ( V_285 != 0 )
goto V_132;
V_285 = V_158 -> V_273 ;
if ( V_285 == 0 )
F_346 ( V_2 , & V_158 -> V_370 ) ;
else
F_135 ( V_2 , & V_158 -> V_370 ) ;
V_132:
F_72 ( V_118 ) ;
return V_285 ;
}
int F_416 ( struct V_2 * V_2 , struct V_295 * V_330 , const T_8 * V_240 , int V_669 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_415 ( V_2 , V_330 , V_240 , V_669 ) ;
F_417 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_76 :
case - V_75 :
case 0 :
return 0 ;
}
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static unsigned long
F_418 ( unsigned long V_54 )
{
F_17 ( V_54 ) ;
V_54 <<= 1 ;
if ( V_54 > V_672 )
return V_672 ;
return V_54 ;
}
static int F_419 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_675 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_676 V_373 = {
. V_234 = F_93 ( V_2 ) ,
. V_677 = V_675 ,
} ;
struct V_678 V_55 = {
. V_679 = V_675 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_680 ] ,
. V_293 = & V_373 ,
. V_294 = & V_55 ,
. V_295 = V_66 -> V_215 -> V_270 ,
} ;
struct V_681 * V_682 ;
int V_285 ;
V_373 . V_683 . V_224 = V_64 -> V_225 ;
V_285 = F_420 ( V_66 , V_675 ) ;
if ( V_285 != 0 )
goto V_132;
V_682 = V_675 -> V_684 . V_685 . V_215 ;
V_373 . V_683 . V_226 = V_682 -> V_686 . V_229 ;
V_373 . V_683 . V_687 = V_14 -> V_687 ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_373 . V_160 , & V_55 . V_161 , 1 ) ;
switch ( V_285 ) {
case 0 :
V_675 -> V_688 = V_689 ;
break;
case - V_287 :
V_285 = 0 ;
}
V_675 -> V_690 -> V_691 ( V_675 ) ;
V_675 -> V_690 = NULL ;
V_132:
return V_285 ;
}
static int F_421 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_675 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_419 ( V_66 , V_673 , V_675 ) ;
F_422 ( V_675 , V_66 , V_673 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_66 -> V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_423 ( struct V_692 * V_692 , struct V_674 * V_677 )
{
int V_55 = 0 ;
switch ( V_677 -> V_693 & ( V_694 | V_695 ) ) {
case V_694 :
V_55 = F_424 ( V_692 , V_677 ) ;
break;
case V_695 :
V_55 = F_425 ( V_692 , V_677 ) ;
break;
default:
F_426 () ;
}
return V_55 ;
}
static struct V_696 * F_427 ( struct V_674 * V_677 ,
struct V_279 * V_280 ,
struct V_681 * V_682 ,
struct V_697 * V_196 )
{
struct V_696 * V_42 ;
struct V_2 * V_2 = V_682 -> V_698 -> V_2 ;
V_42 = F_86 ( sizeof( * V_42 ) , V_282 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_373 . V_234 = F_93 ( V_2 ) ;
V_42 -> V_373 . V_677 = & V_42 -> V_677 ;
V_42 -> V_373 . V_196 = V_196 ;
V_42 -> V_55 . V_196 = V_196 ;
V_42 -> V_373 . V_240 = & V_682 -> V_699 ;
V_42 -> V_682 = V_682 ;
F_91 ( & V_682 -> V_700 ) ;
V_42 -> V_280 = F_143 ( V_280 ) ;
memcpy ( & V_42 -> V_677 , V_677 , sizeof( V_42 -> V_677 ) ) ;
V_42 -> V_14 = F_85 ( V_2 ) ;
return V_42 ;
}
static void F_428 ( void * V_158 )
{
struct V_696 * V_156 = V_158 ;
F_100 ( V_156 -> V_373 . V_196 ) ;
F_429 ( V_156 -> V_682 ) ;
F_155 ( V_156 -> V_280 ) ;
F_96 ( V_156 ) ;
}
static void F_430 ( struct V_117 * V_118 , void * V_158 )
{
struct V_696 * V_156 = V_158 ;
if ( ! F_60 ( V_118 , & V_156 -> V_55 . V_161 ) )
return;
switch ( V_118 -> V_150 ) {
case 0 :
F_115 ( & V_156 -> V_682 -> V_699 ,
& V_156 -> V_55 . V_240 ) ;
F_37 ( V_156 -> V_14 , V_156 -> V_107 ) ;
break;
case - V_74 :
case - V_94 :
case - V_76 :
case - V_75 :
break;
default:
if ( F_228 ( V_118 , V_156 -> V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
F_128 ( V_156 -> V_373 . V_196 ) ;
}
static void F_431 ( struct V_117 * V_118 , void * V_158 )
{
struct V_696 * V_156 = V_158 ;
if ( F_168 ( V_156 -> V_373 . V_196 , V_118 ) != 0 )
goto V_302;
if ( F_31 ( V_701 , & V_156 -> V_682 -> V_702 ) == 0 ) {
goto V_303;
}
V_156 -> V_107 = V_155 ;
if ( F_63 ( V_156 -> V_14 ,
& V_156 -> V_373 . V_160 ,
& V_156 -> V_55 . V_161 ,
V_118 ) != 0 )
F_128 ( V_156 -> V_373 . V_196 ) ;
return;
V_303:
V_118 -> V_314 = NULL ;
V_302:
F_60 ( V_118 , & V_156 -> V_55 . V_161 ) ;
}
static struct V_117 * F_432 ( struct V_674 * V_677 ,
struct V_279 * V_280 ,
struct V_681 * V_682 ,
struct V_697 * V_196 )
{
struct V_696 * V_158 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_703 ] ,
. V_295 = V_280 -> V_330 ,
} ;
struct V_164 V_296 = {
. V_166 = F_273 ( V_682 -> V_698 -> V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_704 ,
. V_298 = V_299 ,
. V_207 = V_300 ,
} ;
F_232 ( F_85 ( V_682 -> V_698 -> V_2 ) -> V_63 ,
V_398 , & V_296 . V_166 , & V_163 ) ;
V_677 -> V_688 = V_689 ;
V_158 = F_427 ( V_677 , V_280 , V_682 , V_196 ) ;
if ( V_158 == NULL ) {
F_100 ( V_196 ) ;
return F_44 ( - V_127 ) ;
}
F_38 ( & V_158 -> V_373 . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
V_163 . V_293 = & V_158 -> V_373 ;
V_163 . V_294 = & V_158 -> V_55 ;
V_296 . V_170 = V_158 ;
return F_70 ( & V_296 ) ;
}
static int F_433 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_675 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_204 * V_205 = V_66 -> V_215 ;
struct V_173 * V_174 = F_75 ( V_2 ) ;
struct V_697 * V_196 ;
struct V_681 * V_682 ;
struct V_117 * V_118 ;
int V_285 = 0 ;
unsigned char V_693 = V_675 -> V_693 ;
V_285 = F_420 ( V_66 , V_675 ) ;
V_675 -> V_693 |= V_705 ;
F_434 ( & V_205 -> V_706 ) ;
F_435 ( & V_174 -> V_707 ) ;
if ( F_423 ( V_675 -> V_708 , V_675 ) == - V_281 ) {
F_436 ( & V_174 -> V_707 ) ;
F_437 ( & V_205 -> V_706 ) ;
goto V_132;
}
F_436 ( & V_174 -> V_707 ) ;
F_437 ( & V_205 -> V_706 ) ;
if ( V_285 != 0 )
goto V_132;
V_682 = V_675 -> V_684 . V_685 . V_215 ;
if ( F_31 ( V_701 , & V_682 -> V_702 ) == 0 )
goto V_132;
V_196 = F_88 ( & V_682 -> V_686 , V_361 ) ;
V_285 = - V_127 ;
if ( V_196 == NULL )
goto V_132;
V_118 = F_432 ( V_675 , F_265 ( V_675 -> V_708 ) , V_682 , V_196 ) ;
V_285 = F_71 ( V_118 ) ;
if ( F_43 ( V_118 ) )
goto V_132;
V_285 = F_107 ( V_118 ) ;
F_72 ( V_118 ) ;
V_132:
V_675 -> V_693 = V_693 ;
F_438 ( V_675 , V_66 , V_709 , V_285 ) ;
return V_285 ;
}
static struct V_710 * F_439 ( struct V_674 * V_677 ,
struct V_279 * V_280 , struct V_681 * V_682 ,
T_6 V_209 )
{
struct V_710 * V_42 ;
struct V_2 * V_2 = V_682 -> V_698 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
V_42 = F_86 ( sizeof( * V_42 ) , V_209 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_373 . V_234 = F_93 ( V_2 ) ;
V_42 -> V_373 . V_677 = & V_42 -> V_677 ;
V_42 -> V_373 . V_711 = F_88 ( & V_682 -> V_698 -> V_215 -> V_212 , V_209 ) ;
if ( V_42 -> V_373 . V_711 == NULL )
goto V_289;
V_42 -> V_373 . V_712 = F_88 ( & V_682 -> V_686 , V_209 ) ;
if ( V_42 -> V_373 . V_712 == NULL )
goto V_713;
V_42 -> V_373 . V_714 = & V_682 -> V_699 ;
V_42 -> V_373 . V_683 . V_224 = V_14 -> V_63 -> V_225 ;
V_42 -> V_373 . V_683 . V_226 = V_682 -> V_686 . V_229 ;
V_42 -> V_373 . V_683 . V_687 = V_14 -> V_687 ;
V_42 -> V_55 . V_712 = V_42 -> V_373 . V_712 ;
V_42 -> V_682 = V_682 ;
V_42 -> V_14 = V_14 ;
F_91 ( & V_682 -> V_700 ) ;
V_42 -> V_280 = F_143 ( V_280 ) ;
memcpy ( & V_42 -> V_677 , V_677 , sizeof( V_42 -> V_677 ) ) ;
return V_42 ;
V_713:
F_100 ( V_42 -> V_373 . V_711 ) ;
V_289:
F_96 ( V_42 ) ;
return NULL ;
}
static void F_440 ( struct V_117 * V_118 , void * V_156 )
{
struct V_710 * V_158 = V_156 ;
struct V_65 * V_66 = V_158 -> V_682 -> V_698 ;
F_8 ( L_29 , V_35 ) ;
if ( F_168 ( V_158 -> V_373 . V_712 , V_118 ) != 0 )
goto V_302;
if ( ! ( V_158 -> V_373 . V_712 -> V_715 -> V_207 & V_716 ) ) {
if ( F_168 ( V_158 -> V_373 . V_711 , V_118 ) != 0 ) {
goto V_717;
}
V_158 -> V_373 . V_258 = & V_66 -> V_258 ;
V_158 -> V_373 . V_718 = 1 ;
V_158 -> V_55 . V_711 = V_158 -> V_373 . V_711 ;
} else
V_158 -> V_373 . V_718 = 0 ;
if ( ! F_218 ( V_66 ) ) {
V_158 -> V_273 = - V_385 ;
V_118 -> V_314 = NULL ;
goto V_719;
}
V_158 -> V_107 = V_155 ;
if ( F_63 ( V_158 -> V_14 ,
& V_158 -> V_373 . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) == 0 )
return;
V_719:
F_128 ( V_158 -> V_373 . V_711 ) ;
V_717:
F_128 ( V_158 -> V_373 . V_712 ) ;
V_302:
F_60 ( V_118 , & V_158 -> V_55 . V_161 ) ;
F_8 ( L_52 , V_35 , V_158 -> V_273 ) ;
}
static void F_441 ( struct V_117 * V_118 , void * V_156 )
{
struct V_710 * V_158 = V_156 ;
F_8 ( L_29 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return;
V_158 -> V_273 = V_118 -> V_150 ;
if ( V_158 -> V_373 . V_718 != 0 ) {
if ( V_158 -> V_273 == 0 )
F_162 ( & V_158 -> V_682 -> V_686 , 0 ) ;
else
goto V_132;
}
if ( V_158 -> V_273 == 0 ) {
F_115 ( & V_158 -> V_682 -> V_699 , & V_158 -> V_55 . V_240 ) ;
F_116 ( V_701 , & V_158 -> V_682 -> V_702 ) ;
F_37 ( F_85 ( V_158 -> V_280 -> V_4 -> V_47 ) , V_158 -> V_107 ) ;
}
V_132:
F_8 ( L_30 , V_35 , V_158 -> V_273 ) ;
}
static void F_442 ( void * V_156 )
{
struct V_710 * V_158 = V_156 ;
F_8 ( L_29 , V_35 ) ;
F_100 ( V_158 -> V_373 . V_711 ) ;
if ( V_158 -> V_288 != 0 ) {
struct V_117 * V_118 ;
V_118 = F_432 ( & V_158 -> V_677 , V_158 -> V_280 , V_158 -> V_682 ,
V_158 -> V_373 . V_712 ) ;
if ( ! F_43 ( V_118 ) )
F_443 ( V_118 ) ;
F_8 ( L_53 , V_35 ) ;
} else
F_100 ( V_158 -> V_373 . V_712 ) ;
F_429 ( V_158 -> V_682 ) ;
F_155 ( V_158 -> V_280 ) ;
F_96 ( V_158 ) ;
F_8 ( L_31 , V_35 ) ;
}
static void F_444 ( struct V_13 * V_14 , struct V_681 * V_682 , int V_718 , int error )
{
switch ( error ) {
case - V_73 :
case - V_74 :
V_682 -> V_686 . V_207 &= ~ V_716 ;
if ( V_718 != 0 ||
F_31 ( V_701 , & V_682 -> V_702 ) != 0 )
F_22 ( V_14 , V_682 -> V_698 ) ;
break;
case - V_76 :
V_682 -> V_686 . V_207 &= ~ V_716 ;
case - V_75 :
F_24 ( V_14 -> V_63 ) ;
} ;
}
static int F_445 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_677 , int V_720 )
{
struct V_710 * V_158 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_721 ] ,
. V_295 = V_66 -> V_215 -> V_270 ,
} ;
struct V_164 V_296 = {
. V_166 = F_273 ( V_66 -> V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_722 ,
. V_298 = V_299 ,
. V_207 = V_300 ,
} ;
int V_67 ;
F_8 ( L_29 , V_35 ) ;
V_158 = F_439 ( V_677 , F_265 ( V_677 -> V_708 ) ,
V_677 -> V_684 . V_685 . V_215 ,
V_720 == V_723 ? V_361 : V_282 ) ;
if ( V_158 == NULL )
return - V_127 ;
if ( F_446 ( V_673 ) )
V_158 -> V_373 . V_724 = 1 ;
F_38 ( & V_158 -> V_373 . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
V_163 . V_293 = & V_158 -> V_373 ;
V_163 . V_294 = & V_158 -> V_55 ;
V_296 . V_170 = V_158 ;
if ( V_720 > V_723 ) {
if ( V_720 == V_725 )
V_158 -> V_373 . V_726 = V_725 ;
F_39 ( & V_158 -> V_373 . V_160 ) ;
}
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_67 = F_107 ( V_118 ) ;
if ( V_67 == 0 ) {
V_67 = V_158 -> V_273 ;
if ( V_67 )
F_444 ( V_158 -> V_14 , V_158 -> V_682 ,
V_158 -> V_373 . V_718 , V_67 ) ;
} else
V_158 -> V_288 = 1 ;
F_72 ( V_118 ) ;
F_8 ( L_30 , V_35 , V_67 ) ;
return V_67 ;
}
static int F_447 ( struct V_65 * V_66 , struct V_674 * V_675 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_31 ( V_257 , & V_66 -> V_207 ) != 0 )
return 0 ;
V_8 = F_445 ( V_66 , V_709 , V_675 , V_725 ) ;
F_448 ( V_675 , V_66 , V_709 , V_8 ) ;
if ( V_8 != - V_91 )
break;
F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_449 ( struct V_65 * V_66 , struct V_674 * V_675 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
V_8 = F_420 ( V_66 , V_675 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_727 ) {
F_116 ( V_728 , & V_675 -> V_684 . V_685 . V_215 -> V_702 ) ;
return 0 ;
}
do {
if ( F_31 ( V_257 , & V_66 -> V_207 ) != 0 )
return 0 ;
V_8 = F_445 ( V_66 , V_709 , V_675 , V_729 ) ;
F_450 ( V_675 , V_66 , V_709 , V_8 ) ;
switch ( V_8 ) {
default:
goto V_132;
case - V_90 :
case - V_91 :
F_19 ( V_14 , V_8 , & V_62 ) ;
V_8 = 0 ;
}
} while ( V_62 . V_68 );
V_132:
return V_8 ;
}
static int F_451 ( struct V_65 * V_66 )
{
int V_285 , V_67 = - V_74 ;
struct V_681 * V_682 ;
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
F_142 (lsp, &state->lock_states, ls_locks) {
if ( F_31 ( V_701 , & V_682 -> V_702 ) ) {
struct V_295 * V_330 = V_682 -> V_698 -> V_215 -> V_270 ;
V_285 = F_189 ( V_14 ,
& V_682 -> V_699 ,
V_330 ) ;
F_452 ( V_66 , V_682 , V_285 ) ;
if ( V_285 != V_344 ) {
if ( V_285 != - V_74 )
F_191 ( V_14 ,
& V_682 -> V_699 ,
V_330 ) ;
F_149 ( V_701 , & V_682 -> V_702 ) ;
V_67 = V_285 ;
}
}
} ;
return V_67 ;
}
static int F_453 ( struct V_65 * V_66 , struct V_674 * V_675 )
{
int V_285 = V_344 ;
if ( F_31 ( V_730 , & V_66 -> V_207 ) )
V_285 = F_451 ( V_66 ) ;
if ( V_285 != V_344 )
V_285 = F_449 ( V_66 , V_675 ) ;
return V_285 ;
}
static int F_454 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_675 )
{
struct V_204 * V_205 = V_66 -> V_215 ;
struct V_173 * V_174 = F_75 ( V_66 -> V_2 ) ;
unsigned char V_693 = V_675 -> V_693 ;
unsigned int V_352 ;
int V_285 = - V_731 ;
if ( ( V_693 & V_694 ) &&
! F_31 ( V_354 , & V_66 -> V_207 ) )
goto V_132;
V_285 = F_420 ( V_66 , V_675 ) ;
if ( V_285 != 0 )
goto V_132;
V_675 -> V_693 |= V_732 ;
V_285 = F_423 ( V_675 -> V_708 , V_675 ) ;
if ( V_285 < 0 )
goto V_132;
F_435 ( & V_174 -> V_707 ) ;
if ( F_31 ( V_257 , & V_66 -> V_207 ) ) {
V_675 -> V_693 = V_693 & ~ V_733 ;
V_285 = F_423 ( V_675 -> V_708 , V_675 ) ;
goto V_139;
}
V_352 = F_198 ( & V_205 -> V_353 ) ;
F_436 ( & V_174 -> V_707 ) ;
V_285 = F_445 ( V_66 , V_673 , V_675 , V_723 ) ;
if ( V_285 != 0 )
goto V_132;
F_435 ( & V_174 -> V_707 ) ;
if ( F_204 ( & V_205 -> V_353 , V_352 ) ) {
V_285 = - V_91 ;
goto V_139;
}
V_675 -> V_693 = V_693 | V_733 ;
if ( F_423 ( V_675 -> V_708 , V_675 ) < 0 )
F_29 ( V_97 L_54
L_55 , V_35 ) ;
V_139:
F_436 ( & V_174 -> V_707 ) ;
V_132:
V_675 -> V_693 = V_693 ;
return V_285 ;
}
static int F_455 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_675 )
{
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_454 ( V_66 , V_673 , V_675 ) ;
F_456 ( V_675 , V_66 , V_673 , V_8 ) ;
if ( V_8 == - V_287 )
V_8 = - V_131 ;
V_8 = F_19 ( F_85 ( V_66 -> V_2 ) ,
V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_457 ( struct V_692 * V_734 , int V_673 , struct V_674 * V_675 )
{
struct V_279 * V_280 ;
struct V_65 * V_66 ;
unsigned long V_54 = V_735 ;
int V_285 ;
V_280 = F_265 ( V_734 ) ;
V_66 = V_280 -> V_66 ;
if ( V_675 -> V_736 < 0 || V_675 -> V_737 < 0 )
return - V_27 ;
if ( F_458 ( V_673 ) ) {
if ( V_66 != NULL )
return F_421 ( V_66 , V_738 , V_675 ) ;
return 0 ;
}
if ( ! ( F_459 ( V_673 ) || F_446 ( V_673 ) ) )
return - V_27 ;
if ( V_675 -> V_688 == V_689 ) {
if ( V_66 != NULL )
return F_433 ( V_66 , V_673 , V_675 ) ;
return 0 ;
}
if ( V_66 == NULL )
return - V_731 ;
switch ( V_675 -> V_688 ) {
case V_739 :
if ( ! ( V_734 -> V_740 & V_70 ) )
return - V_385 ;
break;
case V_741 :
if ( ! ( V_734 -> V_740 & V_218 ) )
return - V_385 ;
}
do {
V_285 = F_455 ( V_66 , V_673 , V_675 ) ;
if ( ( V_285 != - V_131 ) || F_459 ( V_673 ) )
break;
V_54 = F_418 ( V_54 ) ;
V_285 = - V_59 ;
if ( F_460 () )
break;
} while( V_285 < 0 );
return V_285 ;
}
int F_461 ( struct V_674 * V_677 , struct V_65 * V_66 , const T_8 * V_240 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
int V_8 ;
V_8 = F_420 ( V_66 , V_677 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_445 ( V_66 , V_709 , V_677 , V_723 ) ;
return F_156 ( V_14 , V_66 , V_240 , V_8 ) ;
}
static void F_462 ( struct V_117 * V_118 , void * V_156 )
{
struct V_742 * V_158 = V_156 ;
F_40 ( V_158 -> V_14 ,
& V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , V_118 ) ;
V_158 -> V_107 = V_155 ;
}
static void F_463 ( struct V_117 * V_118 , void * V_156 )
{
struct V_742 * V_158 = V_156 ;
struct V_13 * V_14 = V_158 -> V_14 ;
F_48 ( V_118 , & V_158 -> V_55 . V_161 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
F_37 ( V_14 , V_158 -> V_107 ) ;
break;
case - V_77 :
case - V_75 :
case - V_79 :
case - V_91 :
if ( F_228 ( V_118 , V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
}
static void F_464 ( void * V_156 )
{
struct V_742 * V_158 = V_156 ;
F_465 ( V_158 -> V_14 , V_158 -> V_682 ) ;
F_96 ( V_156 ) ;
}
static int F_466 ( struct V_13 * V_14 , struct V_681 * V_682 )
{
struct V_742 * V_158 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_743 ] ,
} ;
if ( V_14 -> V_63 -> V_168 -> V_312 != 0 )
return - V_27 ;
V_158 = F_257 ( sizeof( * V_158 ) , V_282 ) ;
if ( ! V_158 )
return - V_127 ;
V_158 -> V_682 = V_682 ;
V_158 -> V_14 = V_14 ;
V_158 -> args . V_683 . V_224 = V_14 -> V_63 -> V_225 ;
V_158 -> args . V_683 . V_226 = V_682 -> V_686 . V_229 ;
V_158 -> args . V_683 . V_687 = V_14 -> V_687 ;
V_163 . V_293 = & V_158 -> args ;
V_163 . V_294 = & V_158 -> V_55 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 0 ) ;
F_366 ( V_14 -> V_92 , & V_163 , 0 , & V_744 , V_158 ) ;
return 0 ;
}
static int F_467 ( struct V_4 * V_4 , const char * V_745 ,
const void * V_586 , T_9 V_587 ,
int V_207 , int type )
{
if ( strcmp ( V_745 , L_56 ) != 0 )
return - V_27 ;
return F_388 ( V_4 -> V_47 , V_586 , V_587 ) ;
}
static int F_468 ( struct V_4 * V_4 , const char * V_745 ,
void * V_586 , T_9 V_587 , int type )
{
if ( strcmp ( V_745 , L_56 ) != 0 )
return - V_27 ;
return F_382 ( V_4 -> V_47 , V_586 , V_587 ) ;
}
static T_9 F_469 ( struct V_4 * V_4 , char * V_746 ,
T_9 V_747 , const char * V_230 ,
T_9 V_748 , int type )
{
T_9 V_12 = sizeof( V_749 ) ;
if ( ! F_369 ( F_85 ( V_4 -> V_47 ) ) )
return 0 ;
if ( V_746 && V_12 <= V_747 )
memcpy ( V_746 , V_749 , V_12 ) ;
return V_12 ;
}
static inline int F_470 ( struct V_13 * V_14 )
{
return V_14 -> V_95 & V_9 ;
}
static int F_471 ( struct V_4 * V_4 , const char * V_745 ,
const void * V_586 , T_9 V_587 ,
int V_207 , int type )
{
if ( F_472 ( V_745 ) )
return F_396 ( V_4 , V_586 , V_587 ) ;
return - V_612 ;
}
static int F_473 ( struct V_4 * V_4 , const char * V_745 ,
void * V_586 , T_9 V_587 , int type )
{
if ( F_472 ( V_745 ) )
return F_391 ( V_4 -> V_47 , V_586 , V_587 ) ;
return - V_612 ;
}
static T_9 F_474 ( struct V_4 * V_4 , char * V_746 ,
T_9 V_747 , const char * V_230 ,
T_9 V_748 , int type )
{
T_9 V_12 = 0 ;
if ( F_2 ( V_4 -> V_47 , V_9 ) ) {
V_12 = F_475 ( V_4 -> V_47 , NULL , 0 ) ;
if ( V_746 && V_12 <= V_747 )
F_475 ( V_4 -> V_47 , V_746 , V_12 ) ;
}
return V_12 ;
}
static void F_259 ( struct V_369 * V_370 )
{
if ( ! ( ( ( V_370 -> V_276 & V_750 ) ||
( V_370 -> V_276 & V_751 ) ) &&
( V_370 -> V_276 & V_459 ) &&
( V_370 -> V_276 & V_752 ) ) )
return;
V_370 -> V_276 |= V_315 | V_474 |
V_475 | V_753 ;
V_370 -> V_244 = V_320 | V_477 | V_478 ;
V_370 -> V_479 = 2 ;
}
static int F_476 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_461 * V_230 ,
struct V_463 * V_754 ,
struct V_462 * V_462 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
T_1 V_231 [ 3 ] = {
[ 0 ] = V_755 | V_756 ,
} ;
struct V_757 args = {
. V_472 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
. V_462 = V_462 ,
. V_231 = V_231 ,
} ;
struct V_758 V_55 = {
. V_754 = V_754 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_759 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
int V_285 ;
F_8 ( L_57 , V_35 ) ;
if ( F_85 ( V_3 ) -> V_15 [ 1 ] & V_760 )
V_231 [ 1 ] |= V_760 ;
else
V_231 [ 0 ] |= V_46 ;
F_81 ( & V_754 -> V_370 ) ;
V_754 -> V_14 = V_14 ;
V_754 -> V_761 = 0 ;
V_285 = F_73 ( V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
F_8 ( L_58 , V_35 , V_285 ) ;
return V_285 ;
}
int F_258 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_461 * V_230 ,
struct V_463 * V_754 ,
struct V_462 * V_462 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_476 ( V_92 , V_3 , V_230 ,
V_754 , V_462 ) ;
F_477 ( V_3 , V_230 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_478 ( struct V_2 * V_2 ,
struct V_463 * V_464 ,
struct V_462 * V_462 , struct V_295 * V_330 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
T_1 V_231 [ 2 ] = {
[ 0 ] = V_755 | V_756 ,
} ;
struct V_757 args = {
. V_224 = V_14 -> V_63 -> V_225 ,
. V_234 = F_93 ( V_2 ) ,
. V_462 = V_462 ,
. V_231 = V_231 ,
. V_762 = 1 ,
. V_763 = 1 ,
} ;
struct V_758 V_55 = {
. V_754 = V_464 ,
. V_762 = 1 ,
. V_763 = 1 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_759 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
unsigned long V_543 = V_155 ;
int V_285 ;
F_81 ( & V_464 -> V_370 ) ;
V_464 -> V_14 = V_14 ;
V_464 -> V_761 = 0 ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_285 = F_69 ( V_53 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
if ( V_285 )
return V_285 ;
F_37 ( V_14 , V_543 ) ;
return 0 ;
}
static int F_479 ( struct V_2 * V_2 ,
struct V_463 * V_464 ,
struct V_462 * V_462 , struct V_295 * V_330 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
T_1 V_231 [ 2 ] = {
[ 0 ] = V_755 | V_756 ,
} ;
struct V_757 args = {
. V_234 = F_93 ( V_2 ) ,
. V_462 = V_462 ,
. V_231 = V_231 ,
. V_762 = 1 ,
} ;
struct V_758 V_55 = {
. V_754 = V_464 ,
. V_762 = 1 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_759 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
int V_285 ;
F_81 ( & V_464 -> V_370 ) ;
V_464 -> V_14 = V_14 ;
V_464 -> V_761 = 0 ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_285 = F_69 ( V_53 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
if ( V_285 == V_764 &&
V_55 . V_161 . V_146 & V_765 )
V_285 = - V_79 ;
return V_285 ;
}
int F_480 ( struct V_2 * V_2 ,
struct V_463 * V_464 ,
struct V_462 * V_462 , struct V_295 * V_330 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_766 * V_767 =
V_64 -> V_168 -> V_768 ;
struct V_61 V_62 = { } ;
int V_285 ;
F_8 ( L_59 , V_35 ,
( unsigned long long ) V_14 -> V_460 . V_769 ,
( unsigned long long ) V_14 -> V_460 . V_770 ,
V_64 -> V_98 ) ;
F_481 ( F_93 ( V_2 ) , V_35 ) ;
do {
V_285 = V_767 -> V_771 ( V_2 , V_464 , V_462 , V_330 ) ;
if ( V_285 != - V_91 )
break;
F_19 ( V_14 , V_285 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_285 ;
}
static int F_482 ( struct V_2 * V_2 , struct V_295 * V_330 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = F_85 ( V_2 ) -> V_63 ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_772 args = {
. V_234 = F_93 ( V_2 ) ,
. V_224 = V_64 -> V_225 ,
. V_763 = 1 ,
} ;
struct V_773 V_55 = {
. V_763 = 1 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_774 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
unsigned long V_543 = V_155 ;
int V_285 ;
V_55 . V_234 = F_483 () ;
if ( V_55 . V_234 == NULL )
return - V_127 ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_285 = F_69 ( V_53 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
F_484 ( V_55 . V_234 ) ;
if ( V_285 )
return V_285 ;
F_33 ( V_64 , V_543 ) ;
return 0 ;
}
static int F_485 ( struct V_2 * V_2 , struct V_295 * V_330 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_772 args = {
. V_234 = F_93 ( V_2 ) ,
} ;
struct V_773 V_55 = {
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_774 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
int V_285 ;
V_55 . V_234 = F_483 () ;
if ( V_55 . V_234 == NULL )
return - V_127 ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_285 = F_69 ( V_53 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
F_484 ( V_55 . V_234 ) ;
if ( V_285 == V_764 &&
V_55 . V_161 . V_146 & V_765 )
V_285 = - V_79 ;
return V_285 ;
}
int F_486 ( struct V_2 * V_2 , struct V_295 * V_330 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_766 * V_767 =
V_64 -> V_168 -> V_768 ;
struct V_61 V_62 = { } ;
int V_285 ;
F_8 ( L_59 , V_35 ,
( unsigned long long ) V_14 -> V_460 . V_769 ,
( unsigned long long ) V_14 -> V_460 . V_770 ,
V_64 -> V_98 ) ;
F_481 ( F_93 ( V_2 ) , V_35 ) ;
do {
V_285 = V_767 -> V_775 ( V_2 , V_330 ) ;
if ( V_285 != - V_91 )
break;
F_19 ( V_14 , V_285 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_285 ;
}
static int F_487 ( struct V_2 * V_3 , const struct V_461 * V_230 , struct V_776 * V_454 , bool V_777 )
{
int V_285 ;
struct V_778 args = {
. V_472 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
} ;
struct V_779 V_55 = {
. V_454 = V_454 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_780 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
struct V_52 * V_53 = F_85 ( V_3 ) -> V_92 ;
struct V_295 * V_330 = NULL ;
if ( V_777 ) {
V_53 = F_85 ( V_3 ) -> V_63 -> V_102 ;
V_330 = F_488 ( F_85 ( V_3 ) -> V_63 ) ;
V_163 . V_295 = V_330 ;
}
F_8 ( L_60 , V_230 -> V_230 ) ;
F_232 ( F_85 ( V_3 ) -> V_63 ,
V_781 , & V_53 , & V_163 ) ;
V_285 = F_73 ( V_53 , F_85 ( V_3 ) , & V_163 , & args . V_160 ,
& V_55 . V_161 , 0 ) ;
F_8 ( L_61 , V_285 ) ;
if ( V_330 )
F_192 ( V_330 ) ;
return V_285 ;
}
int F_489 ( struct V_2 * V_3 , const struct V_461 * V_230 ,
struct V_776 * V_454 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( F_85 ( V_3 ) -> V_63 ) )
V_8 = F_487 ( V_3 , V_230 , V_454 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_487 ( V_3 , V_230 , V_454 , false ) ;
F_490 ( V_3 , V_230 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_491 ( T_1 V_207 )
{
if ( V_207 & ~ V_782 )
goto V_783;
if ( ( V_207 & V_784 ) &&
( V_207 & V_785 ) )
goto V_783;
if ( ! ( V_207 & ( V_786 ) ) )
goto V_783;
return V_344 ;
V_783:
return - V_787 ;
}
static bool
F_492 ( struct V_788 * V_789 ,
struct V_788 * V_790 )
{
if ( V_789 -> V_791 == V_790 -> V_791 &&
memcmp ( V_789 -> V_792 , V_790 -> V_792 , V_789 -> V_791 ) == 0 )
return true ;
return false ;
}
int F_493 ( struct V_63 * V_64 , struct V_295 * V_330 )
{
int V_285 ;
struct V_793 V_55 ;
struct V_162 V_163 = {
. V_290 =
& V_291 [ V_794 ] ,
. V_293 = V_64 ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
F_8 ( L_11 , V_35 ) ;
V_55 . V_135 = F_86 ( sizeof( struct V_134 ) , V_282 ) ;
if ( F_343 ( V_55 . V_135 == NULL ) ) {
V_285 = - V_127 ;
goto V_132;
}
V_285 = F_368 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_494 ( V_64 , V_285 ) ;
if ( V_285 == 0 ) {
if ( memcmp ( V_55 . V_135 -> V_795 . V_158 ,
V_64 -> V_88 -> V_795 . V_158 , V_796 ) ) {
F_8 ( L_62 , V_35 ) ;
V_285 = - V_36 ;
goto V_797;
}
if ( V_55 . V_3 != V_798 ) {
F_8 ( L_63 ,
V_35 ) ;
V_285 = - V_36 ;
goto V_797;
}
if ( V_55 . V_799 ) {
F_8 ( L_64 ,
V_35 ) ;
V_285 = - V_36 ;
goto V_797;
}
}
V_797:
F_96 ( V_55 . V_135 ) ;
V_132:
F_8 ( L_65 , V_35 , V_285 ) ;
return V_285 ;
}
static int F_495 ( struct V_63 * V_64 ,
struct V_800 * V_205 )
{
static const T_1 V_801 [ V_802 ] = {
[ 1 ] = 1 << ( V_803 - 32 ) |
1 << ( V_804 - 32 ) |
1 << ( V_805 - 32 ) |
1 << ( V_806 - 32 ) |
1 << ( V_807 - 32 )
} ;
unsigned int V_451 ;
if ( V_205 -> V_808 == V_809 ) {
F_496 ( V_810 , L_66 ) ;
for ( V_451 = 0 ; V_451 <= V_811 ; V_451 ++ ) {
if ( F_31 ( V_451 , V_205 -> V_812 . V_238 . V_813 ) )
F_496 ( V_810 , L_67 , V_451 ) ;
if ( F_31 ( V_451 , V_205 -> V_814 . V_238 . V_813 ) )
F_496 ( V_810 , L_68 , V_451 ) ;
}
for ( V_451 = 0 ; V_451 < V_802 ; V_451 ++ ) {
if ( V_205 -> V_812 . V_238 . V_815 [ V_451 ] & ~ V_801 [ V_451 ] ) {
F_496 ( V_810 , L_69 ) ;
return - V_27 ;
}
}
if ( F_31 ( V_803 , V_205 -> V_812 . V_238 . V_813 ) &&
F_31 ( V_805 , V_205 -> V_812 . V_238 . V_813 ) &&
F_31 ( V_806 , V_205 -> V_812 . V_238 . V_813 ) &&
F_31 ( V_807 , V_205 -> V_812 . V_238 . V_813 ) ) {
F_496 ( V_810 , L_70 ) ;
F_496 ( V_810 , L_71 ) ;
F_116 ( V_816 , & V_64 -> V_817 ) ;
} else {
F_496 ( V_810 , L_69 ) ;
return - V_27 ;
}
if ( F_31 ( V_818 , V_205 -> V_814 . V_238 . V_813 ) &&
F_31 ( V_819 , V_205 -> V_814 . V_238 . V_813 ) ) {
F_496 ( V_810 , L_72 ) ;
F_116 ( V_398 , & V_64 -> V_817 ) ;
}
if ( F_31 ( V_820 , V_205 -> V_814 . V_238 . V_813 ) &&
F_31 ( V_821 , V_205 -> V_814 . V_238 . V_813 ) ) {
F_496 ( V_810 , L_73 ) ;
F_116 ( V_781 , & V_64 -> V_817 ) ;
}
if ( F_31 ( V_822 , V_205 -> V_814 . V_238 . V_813 ) &&
F_31 ( V_823 , V_205 -> V_814 . V_238 . V_813 ) ) {
F_496 ( V_810 , L_74 ) ;
F_116 ( V_824 , & V_64 -> V_817 ) ;
}
if ( F_31 ( V_825 , V_205 -> V_814 . V_238 . V_813 ) ) {
F_496 ( V_810 , L_75 ) ;
F_116 ( V_826 , & V_64 -> V_817 ) ;
}
if ( F_31 ( V_827 , V_205 -> V_814 . V_238 . V_813 ) ) {
F_496 ( V_810 , L_76 ) ;
F_116 ( V_828 , & V_64 -> V_817 ) ;
}
}
return 0 ;
}
static int F_497 ( struct V_63 * V_64 , struct V_295 * V_330 ,
T_1 V_829 )
{
T_12 V_38 ;
struct V_830 args = {
. V_38 = & V_38 ,
. V_92 = V_64 ,
#ifdef F_498
. V_207 = V_831 |
V_832 |
V_833 ,
#else
. V_207 = V_831 |
V_832 ,
#endif
} ;
struct V_834 V_55 = {
0
} ;
int V_285 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_835 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
F_400 ( V_64 , & V_38 ) ;
args . V_836 = F_406 ( V_64 , args . V_226 ,
sizeof( args . V_226 ) ) ;
F_8 ( L_77 ,
V_64 -> V_102 -> V_103 -> V_664 -> V_665 ,
args . V_836 , args . V_226 ) ;
V_55 . V_837 = F_86 ( sizeof( struct V_838 ) ,
V_282 ) ;
if ( F_343 ( V_55 . V_837 == NULL ) ) {
V_285 = - V_127 ;
goto V_132;
}
V_55 . V_792 = F_86 ( sizeof( struct V_788 ) ,
V_282 ) ;
if ( F_343 ( V_55 . V_792 == NULL ) ) {
V_285 = - V_127 ;
goto V_839;
}
V_55 . V_840 = F_86 ( sizeof( struct V_841 ) , V_282 ) ;
if ( F_343 ( V_55 . V_840 == NULL ) ) {
V_285 = - V_127 ;
goto V_842;
}
switch ( V_829 ) {
case V_843 :
args . V_844 . V_808 = V_843 ;
break;
case V_809 :
args . V_844 = V_845 ;
break;
default:
F_499 ( 1 ) ;
V_285 = - V_27 ;
goto V_842;
}
V_285 = F_368 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_500 ( V_64 , V_285 ) ;
if ( V_285 == 0 )
V_285 = F_491 ( V_55 . V_207 ) ;
if ( V_285 == 0 )
V_285 = F_495 ( V_64 , & V_55 . V_844 ) ;
if ( V_285 == 0 ) {
V_64 -> V_225 = V_55 . V_224 ;
V_64 -> V_846 = ( V_55 . V_207 & ~ V_847 ) ;
if ( ! ( V_55 . V_207 & V_847 ) )
V_64 -> V_848 = V_55 . V_196 ;
F_96 ( V_64 -> V_849 ) ;
V_64 -> V_849 = V_55 . V_837 ;
V_55 . V_837 = NULL ;
F_96 ( V_64 -> V_850 ) ;
V_64 -> V_850 = V_55 . V_840 ;
if ( V_64 -> V_851 != NULL &&
! F_492 ( V_64 -> V_851 ,
V_55 . V_792 ) ) {
F_8 ( L_78 ,
V_35 ) ;
F_116 ( V_852 , & V_64 -> V_625 ) ;
F_96 ( V_64 -> V_851 ) ;
V_64 -> V_851 = NULL ;
}
if ( V_64 -> V_851 == NULL ) {
V_64 -> V_851 = V_55 . V_792 ;
goto V_132;
}
} else
F_96 ( V_55 . V_840 ) ;
V_839:
F_96 ( V_55 . V_837 ) ;
V_842:
F_96 ( V_55 . V_792 ) ;
V_132:
if ( V_64 -> V_850 != NULL )
F_8 ( L_79
L_80 ,
V_64 -> V_850 -> V_853 , V_64 -> V_850 -> V_230 ,
V_64 -> V_850 -> V_854 . V_855 ,
V_64 -> V_850 -> V_854 . V_856 ) ;
F_8 ( L_81 , V_285 ) ;
return V_285 ;
}
int F_501 ( struct V_63 * V_64 , struct V_295 * V_330 )
{
T_4 V_857 = V_64 -> V_102 -> V_103 -> V_104 ;
int V_285 ;
if ( V_857 == V_105 ||
V_857 == V_106 ) {
V_285 = F_497 ( V_64 , V_330 , V_809 ) ;
if ( ! V_285 )
return 0 ;
}
return F_497 ( V_64 , V_330 , V_843 ) ;
}
static int F_502 ( struct V_63 * V_64 ,
struct V_295 * V_330 )
{
struct V_162 V_163 = {
. V_290 = & V_291 [ V_858 ] ,
. V_293 = V_64 ,
. V_295 = V_330 ,
} ;
int V_285 ;
V_285 = F_368 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_503 ( V_64 , V_285 ) ;
if ( V_285 )
F_8 ( L_82
L_83 , V_285 , V_64 -> V_98 ) ;
return V_285 ;
}
static int F_504 ( struct V_63 * V_64 ,
struct V_295 * V_330 )
{
unsigned int V_859 ;
int V_67 ;
for ( V_859 = V_860 ; V_859 != 0 ; V_859 -- ) {
V_67 = F_502 ( V_64 , V_330 ) ;
switch ( V_67 ) {
case - V_91 :
case - V_861 :
F_158 ( 1 ) ;
break;
default:
return V_67 ;
}
}
return 0 ;
}
int F_505 ( struct V_63 * V_64 )
{
struct V_295 * V_330 ;
int V_67 = 0 ;
if ( V_64 -> V_168 -> V_312 < 1 )
goto V_132;
if ( V_64 -> V_846 == 0 )
goto V_132;
if ( V_64 -> V_862 )
goto V_132;
V_330 = F_488 ( V_64 ) ;
V_67 = F_504 ( V_64 , V_330 ) ;
if ( V_330 )
F_192 ( V_330 ) ;
switch ( V_67 ) {
case 0 :
case - V_77 :
V_64 -> V_846 = 0 ;
}
V_132:
return V_67 ;
}
static void F_506 ( struct V_117 * V_118 ,
void * V_156 )
{
struct V_863 * V_158 =
(struct V_863 * ) V_156 ;
F_8 ( L_11 , V_35 ) ;
F_61 ( V_158 -> V_64 -> V_88 ,
& V_158 -> args -> V_864 ,
& V_158 -> V_55 -> V_865 ,
V_118 ) ;
F_8 ( L_84 , V_35 ) ;
}
static void F_507 ( struct V_117 * V_118 , void * V_156 )
{
struct V_863 * V_158 =
(struct V_863 * ) V_156 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , & V_158 -> V_55 -> V_865 ) )
return;
switch ( V_118 -> V_150 ) {
case - V_91 :
case - V_90 :
F_8 ( L_85 , V_35 , V_118 -> V_150 ) ;
F_59 ( V_118 , V_56 ) ;
V_118 -> V_150 = 0 ;
case - V_93 :
F_57 ( V_118 ) ;
return;
}
F_8 ( L_84 , V_35 ) ;
}
int F_508 ( struct V_63 * V_64 , struct V_437 * V_539 )
{
struct V_117 * V_118 ;
struct V_866 args ;
struct V_867 V_55 = {
. V_868 = V_539 ,
} ;
struct V_863 V_158 = {
. args = & args ,
. V_55 = & V_55 ,
. V_64 = V_64 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_869 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
struct V_164 V_165 = {
. V_166 = V_64 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_870 ,
. V_170 = & V_158 ,
. V_207 = V_584 ,
} ;
int V_285 ;
F_38 ( & args . V_864 , & V_55 . V_865 , 0 ) ;
F_39 ( & args . V_864 ) ;
F_8 ( L_11 , V_35 ) ;
V_118 = F_70 ( & V_165 ) ;
if ( F_43 ( V_118 ) )
V_285 = F_71 ( V_118 ) ;
else {
V_285 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
}
F_8 ( L_86 , V_35 , V_285 ) ;
return V_285 ;
}
static void F_509 ( struct V_871 * args )
{
unsigned int V_872 , V_873 ;
V_872 = V_874 + V_875 ;
V_873 = V_874 + V_876 ;
args -> V_877 . V_872 = V_872 ;
args -> V_877 . V_873 = V_873 ;
args -> V_877 . V_878 = V_879 ;
args -> V_877 . V_880 = V_881 ;
F_8 ( L_87
L_88 ,
V_35 ,
args -> V_877 . V_872 , args -> V_877 . V_873 ,
args -> V_877 . V_878 , args -> V_877 . V_880 ) ;
args -> V_882 . V_872 = V_591 ;
args -> V_882 . V_873 = V_591 ;
args -> V_882 . V_883 = 0 ;
args -> V_882 . V_878 = V_884 ;
args -> V_882 . V_880 = 1 ;
F_8 ( L_89
L_90 ,
V_35 ,
args -> V_882 . V_872 , args -> V_882 . V_873 ,
args -> V_882 . V_883 , args -> V_882 . V_878 ,
args -> V_882 . V_880 ) ;
}
static int F_510 ( struct V_871 * args , struct V_134 * V_135 )
{
struct V_885 * V_886 = & args -> V_877 ;
struct V_885 * V_887 = & V_135 -> V_877 ;
if ( V_887 -> V_873 > V_886 -> V_873 )
return - V_27 ;
if ( V_887 -> V_878 < V_886 -> V_878 )
return - V_27 ;
if ( V_887 -> V_880 == 0 )
return - V_27 ;
if ( V_887 -> V_880 > V_888 )
V_887 -> V_880 = V_888 ;
return 0 ;
}
static int F_511 ( struct V_871 * args , struct V_134 * V_135 )
{
struct V_885 * V_886 = & args -> V_882 ;
struct V_885 * V_887 = & V_135 -> V_882 ;
if ( V_887 -> V_872 > V_886 -> V_872 )
return - V_27 ;
if ( V_887 -> V_873 < V_886 -> V_873 )
return - V_27 ;
if ( V_887 -> V_883 > V_886 -> V_883 )
return - V_27 ;
if ( V_887 -> V_878 != V_886 -> V_878 )
return - V_27 ;
if ( V_887 -> V_880 != V_886 -> V_880 )
return - V_27 ;
return 0 ;
}
static int F_512 ( struct V_871 * args ,
struct V_134 * V_135 )
{
int V_67 ;
V_67 = F_510 ( args , V_135 ) ;
if ( V_67 )
return V_67 ;
return F_511 ( args , V_135 ) ;
}
static int F_513 ( struct V_63 * V_64 ,
struct V_295 * V_330 )
{
struct V_134 * V_135 = V_64 -> V_88 ;
struct V_871 args = {
. V_92 = V_64 ,
. V_889 = V_890 ,
} ;
struct V_891 V_55 = {
. V_92 = V_64 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_892 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
int V_285 ;
F_509 ( & args ) ;
args . V_207 = ( V_893 | V_894 ) ;
V_285 = F_368 ( V_135 -> V_64 -> V_102 , & V_163 , V_584 ) ;
F_514 ( V_64 , V_285 ) ;
if ( ! V_285 ) {
V_285 = F_512 ( & args , V_135 ) ;
V_64 -> V_848 ++ ;
}
return V_285 ;
}
int F_515 ( struct V_63 * V_64 , struct V_295 * V_330 )
{
int V_285 ;
unsigned * V_895 ;
struct V_134 * V_135 = V_64 -> V_88 ;
F_8 ( L_91 , V_35 , V_64 , V_135 ) ;
V_285 = F_513 ( V_64 , V_330 ) ;
if ( V_285 )
goto V_132;
V_285 = F_516 ( V_135 ) ;
F_8 ( L_92 , V_285 ) ;
if ( V_285 )
goto V_132;
V_895 = ( unsigned * ) & V_135 -> V_795 . V_158 [ 0 ] ;
F_8 ( L_93 , V_35 ,
V_64 -> V_848 , V_895 [ 0 ] , V_895 [ 1 ] , V_895 [ 2 ] , V_895 [ 3 ] ) ;
V_132:
F_8 ( L_84 , V_35 ) ;
return V_285 ;
}
int F_517 ( struct V_134 * V_135 ,
struct V_295 * V_330 )
{
struct V_162 V_163 = {
. V_290 = & V_291 [ V_896 ] ,
. V_293 = V_135 ,
. V_295 = V_330 ,
} ;
int V_285 = 0 ;
F_8 ( L_94 ) ;
if ( V_135 -> V_64 -> V_897 != V_898 )
return V_285 ;
V_285 = F_368 ( V_135 -> V_64 -> V_102 , & V_163 , V_584 ) ;
F_518 ( V_135 -> V_64 , V_285 ) ;
if ( V_285 )
F_8 ( L_95
L_96 , V_285 ) ;
F_8 ( L_97 ) ;
return V_285 ;
}
static void F_519 ( void * V_158 )
{
struct V_899 * V_156 = V_158 ;
struct V_63 * V_64 = V_156 -> V_64 ;
if ( F_358 ( & V_64 -> V_578 ) > 1 )
F_359 ( V_64 ) ;
F_360 ( V_64 ) ;
F_96 ( V_156 ) ;
}
static int F_520 ( struct V_117 * V_118 , struct V_63 * V_64 )
{
switch( V_118 -> V_150 ) {
case - V_91 :
F_59 ( V_118 , V_57 ) ;
return - V_131 ;
default:
F_24 ( V_64 ) ;
}
return 0 ;
}
static void F_521 ( struct V_117 * V_118 , void * V_158 )
{
struct V_899 * V_156 = V_158 ;
struct V_63 * V_64 = V_156 -> V_64 ;
if ( ! F_53 ( V_118 , V_118 -> V_306 . V_294 ) )
return;
F_522 ( V_64 , V_118 -> V_150 ) ;
if ( V_118 -> V_150 < 0 ) {
F_8 ( L_98 , V_35 , V_118 -> V_150 ) ;
if ( F_358 ( & V_64 -> V_578 ) == 1 )
goto V_132;
if ( F_520 ( V_118 , V_64 ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
F_8 ( L_99 , V_35 , V_118 -> V_306 . V_295 ) ;
V_132:
F_8 ( L_84 , V_35 ) ;
}
static void F_523 ( struct V_117 * V_118 , void * V_158 )
{
struct V_899 * V_156 = V_158 ;
struct V_63 * V_64 = V_156 -> V_64 ;
struct V_110 * args ;
struct V_111 * V_55 ;
args = V_118 -> V_306 . V_293 ;
V_55 = V_118 -> V_306 . V_294 ;
F_61 ( V_64 -> V_88 , args , V_55 , V_118 ) ;
}
static struct V_117 * F_524 ( struct V_63 * V_64 ,
struct V_295 * V_330 ,
bool V_900 )
{
struct V_899 * V_156 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_901 ] ,
. V_295 = V_330 ,
} ;
struct V_164 V_296 = {
. V_166 = V_64 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_902 ,
. V_207 = V_300 | V_584 ,
} ;
if ( ! F_365 ( & V_64 -> V_578 ) )
return F_44 ( - V_36 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_282 ) ;
if ( V_156 == NULL ) {
F_360 ( V_64 ) ;
return F_44 ( - V_127 ) ;
}
F_38 ( & V_156 -> args , & V_156 -> V_55 , 0 ) ;
if ( V_900 )
F_39 ( & V_156 -> args ) ;
V_163 . V_293 = & V_156 -> args ;
V_163 . V_294 = & V_156 -> V_55 ;
V_156 -> V_64 = V_64 ;
V_296 . V_170 = V_156 ;
return F_70 ( & V_296 ) ;
}
static int F_525 ( struct V_63 * V_64 , struct V_295 * V_330 , unsigned V_582 )
{
struct V_117 * V_118 ;
int V_67 = 0 ;
if ( ( V_582 & V_903 ) == 0 )
return 0 ;
V_118 = F_524 ( V_64 , V_330 , false ) ;
if ( F_43 ( V_118 ) )
V_67 = F_71 ( V_118 ) ;
else
F_443 ( V_118 ) ;
F_8 ( L_16 , V_35 , V_67 ) ;
return V_67 ;
}
static int F_526 ( struct V_63 * V_64 , struct V_295 * V_330 )
{
struct V_117 * V_118 ;
int V_67 ;
V_118 = F_524 ( V_64 , V_330 , true ) ;
if ( F_43 ( V_118 ) ) {
V_67 = F_71 ( V_118 ) ;
goto V_132;
}
V_67 = F_108 ( V_118 ) ;
if ( ! V_67 ) {
struct V_111 * V_55 = V_118 -> V_306 . V_294 ;
if ( V_118 -> V_150 == 0 )
F_527 ( V_64 , V_55 -> V_146 ) ;
V_67 = V_118 -> V_150 ;
}
F_72 ( V_118 ) ;
V_132:
F_8 ( L_16 , V_35 , V_67 ) ;
return V_67 ;
}
static void F_528 ( struct V_117 * V_118 , void * V_158 )
{
struct V_904 * V_156 = V_158 ;
F_61 ( V_156 -> V_64 -> V_88 ,
& V_156 -> V_373 . V_160 ,
& V_156 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_529 ( struct V_117 * V_118 , struct V_63 * V_64 )
{
switch( V_118 -> V_150 ) {
case 0 :
case - V_905 :
case - V_23 :
break;
case - V_91 :
F_59 ( V_118 , V_57 ) ;
case - V_93 :
return - V_131 ;
default:
F_24 ( V_64 ) ;
}
return 0 ;
}
static void F_530 ( struct V_117 * V_118 , void * V_158 )
{
struct V_904 * V_156 = V_158 ;
struct V_63 * V_64 = V_156 -> V_64 ;
struct V_111 * V_55 = & V_156 -> V_55 . V_161 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , V_55 ) )
return;
F_531 ( V_64 , V_118 -> V_150 ) ;
if ( F_529 ( V_118 , V_64 ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
F_8 ( L_84 , V_35 ) ;
}
static void F_532 ( void * V_158 )
{
struct V_904 * V_156 = V_158 ;
F_96 ( V_156 ) ;
}
static int F_533 ( struct V_63 * V_64 ,
struct V_295 * V_330 )
{
struct V_904 * V_156 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_906 ] ,
. V_295 = V_330 ,
} ;
struct V_164 V_296 = {
. V_166 = V_64 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_907 ,
. V_207 = V_300 ,
} ;
int V_285 = - V_127 ;
F_8 ( L_11 , V_35 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_282 ) ;
if ( V_156 == NULL )
goto V_132;
V_156 -> V_64 = V_64 ;
V_156 -> V_373 . V_908 = 0 ;
F_38 ( & V_156 -> V_373 . V_160 , & V_156 -> V_55 . V_161 , 0 ) ;
F_39 ( & V_156 -> V_373 . V_160 ) ;
V_163 . V_293 = & V_156 -> V_373 ;
V_163 . V_294 = & V_156 -> V_55 ;
V_296 . V_170 = V_156 ;
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) ) {
V_285 = F_71 ( V_118 ) ;
goto V_132;
}
V_285 = F_107 ( V_118 ) ;
if ( V_285 == 0 )
V_285 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
return 0 ;
V_132:
F_8 ( L_16 , V_35 , V_285 ) ;
return V_285 ;
}
static void
F_534 ( struct V_117 * V_118 , void * V_156 )
{
struct V_909 * V_910 = V_156 ;
struct V_13 * V_14 = F_85 ( V_910 -> args . V_2 ) ;
struct V_134 * V_135 = F_64 ( V_14 ) ;
F_8 ( L_11 , V_35 ) ;
if ( F_61 ( V_135 , & V_910 -> args . V_160 ,
& V_910 -> V_55 . V_161 , V_118 ) )
return;
if ( F_535 ( & V_910 -> args . V_240 ,
F_75 ( V_910 -> args . V_2 ) -> V_911 ,
V_910 -> args . V_280 -> V_66 ) ) {
F_536 ( V_118 , V_764 ) ;
}
}
static void F_537 ( struct V_117 * V_118 , void * V_156 )
{
struct V_909 * V_910 = V_156 ;
struct V_2 * V_2 = V_910 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_912 * V_913 ;
struct V_65 * V_66 = NULL ;
unsigned long V_914 , V_543 , V_915 ;
F_8 ( L_100 , V_35 , - V_118 -> V_150 ) ;
if ( ! F_53 ( V_118 , & V_910 -> V_55 . V_161 ) )
goto V_132;
switch ( V_118 -> V_150 ) {
case 0 :
goto V_132;
case - V_19 :
case - V_20 :
V_914 = F_538 ( V_118 -> V_916 ) ;
V_915 = V_910 -> args . V_107 + V_914 ;
V_543 = V_155 ;
if ( F_539 ( V_915 , V_543 ) ) {
unsigned long V_917 ;
V_917 = F_540 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_101 ,
V_35 , V_917 ) ;
F_59 ( V_118 , V_917 ) ;
V_118 -> V_150 = 0 ;
F_57 ( V_118 ) ;
goto V_132;
}
break;
case - V_75 :
case - V_74 :
F_34 ( & V_2 -> V_175 ) ;
V_913 = F_75 ( V_2 ) -> V_911 ;
if ( ! V_913 || F_541 ( & V_913 -> V_918 ) ) {
F_36 ( & V_2 -> V_175 ) ;
V_66 = V_910 -> args . V_280 -> V_66 ;
} else {
F_542 ( V_919 ) ;
F_543 ( V_913 , & V_919 , NULL ) ;
F_36 ( & V_2 -> V_175 ) ;
F_544 ( & V_919 ) ;
}
}
if ( F_228 ( V_118 , V_14 , V_66 ) == - V_131 )
F_57 ( V_118 ) ;
V_132:
F_8 ( L_84 , V_35 ) ;
}
static T_9 F_545 ( struct V_13 * V_14 )
{
T_1 V_873 = V_14 -> V_63 -> V_88 -> V_877 . V_873 ;
return F_546 ( 0 , V_873 ) ;
}
static void F_547 ( struct V_462 * * V_43 , T_9 V_920 )
{
int V_451 ;
if ( ! V_43 )
return;
for ( V_451 = 0 ; V_451 < V_920 ; V_451 ++ ) {
if ( ! V_43 [ V_451 ] )
break;
F_260 ( V_43 [ V_451 ] ) ;
}
F_96 ( V_43 ) ;
}
static struct V_462 * * F_548 ( T_9 V_920 , T_6 V_921 )
{
struct V_462 * * V_43 ;
int V_451 ;
V_43 = F_549 ( V_920 , sizeof( struct V_462 * ) , V_921 ) ;
if ( ! V_43 ) {
F_8 ( L_102 , V_35 , V_920 ) ;
return NULL ;
}
for ( V_451 = 0 ; V_451 < V_920 ; V_451 ++ ) {
V_43 [ V_451 ] = F_256 ( V_921 ) ;
if ( ! V_43 [ V_451 ] ) {
F_8 ( L_103 , V_35 ) ;
F_547 ( V_43 , V_920 ) ;
return NULL ;
}
}
return V_43 ;
}
static void F_550 ( void * V_156 )
{
struct V_909 * V_910 = V_156 ;
struct V_2 * V_2 = V_910 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_922 = F_545 ( V_14 ) ;
F_8 ( L_11 , V_35 ) ;
F_547 ( V_910 -> args . V_911 . V_43 , V_922 ) ;
F_551 ( F_75 ( V_2 ) -> V_911 ) ;
F_155 ( V_910 -> args . V_280 ) ;
F_96 ( V_156 ) ;
F_8 ( L_84 , V_35 ) ;
}
struct V_923 *
F_552 ( struct V_909 * V_910 , T_6 V_921 )
{
struct V_2 * V_2 = V_910 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_922 = F_545 ( V_14 ) ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_924 ] ,
. V_293 = & V_910 -> args ,
. V_294 = & V_910 -> V_55 ,
. V_295 = V_910 -> V_330 ,
} ;
struct V_164 V_296 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_925 ,
. V_170 = V_910 ,
. V_207 = V_300 ,
} ;
struct V_923 * V_926 = NULL ;
int V_285 = 0 ;
F_8 ( L_11 , V_35 ) ;
V_910 -> args . V_911 . V_43 = F_548 ( V_922 , V_921 ) ;
if ( ! V_910 -> args . V_911 . V_43 ) {
F_550 ( V_910 ) ;
return F_44 ( - V_127 ) ;
}
V_910 -> args . V_911 . V_488 = V_922 * V_591 ;
V_910 -> args . V_107 = V_155 ;
V_910 -> V_55 . V_927 = & V_910 -> args . V_911 ;
V_910 -> V_55 . V_161 . V_116 = NULL ;
F_38 ( & V_910 -> args . V_160 , & V_910 -> V_55 . V_161 , 0 ) ;
F_553 ( F_75 ( V_2 ) -> V_911 ) ;
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) )
return F_235 ( V_118 ) ;
V_285 = F_107 ( V_118 ) ;
if ( V_285 == 0 )
V_285 = V_118 -> V_150 ;
F_554 ( V_910 -> args . V_280 ,
& V_910 -> args . V_928 ,
& V_910 -> V_55 . V_928 ,
V_285 ) ;
if ( V_285 == 0 && V_910 -> V_55 . V_927 -> V_12 )
V_926 = F_555 ( V_910 ) ;
F_72 ( V_118 ) ;
F_8 ( L_16 , V_35 , V_285 ) ;
if ( V_285 )
return F_44 ( V_285 ) ;
return V_926 ;
}
static void
F_556 ( struct V_117 * V_118 , void * V_156 )
{
struct V_929 * V_930 = V_156 ;
F_8 ( L_11 , V_35 ) ;
F_61 ( V_930 -> V_64 -> V_88 ,
& V_930 -> args . V_160 ,
& V_930 -> V_55 . V_161 ,
V_118 ) ;
}
static void F_557 ( struct V_117 * V_118 , void * V_156 )
{
struct V_929 * V_930 = V_156 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , & V_930 -> V_55 . V_161 ) )
return;
V_14 = F_85 ( V_930 -> args . V_2 ) ;
switch ( V_118 -> V_150 ) {
default:
V_118 -> V_150 = 0 ;
case 0 :
break;
case - V_91 :
if ( F_228 ( V_118 , V_14 , NULL ) != - V_131 )
break;
F_57 ( V_118 ) ;
return;
}
F_8 ( L_84 , V_35 ) ;
}
static void F_558 ( void * V_156 )
{
struct V_929 * V_930 = V_156 ;
struct V_912 * V_913 = V_930 -> args . V_911 ;
F_8 ( L_11 , V_35 ) ;
F_34 ( & V_913 -> V_931 -> V_175 ) ;
if ( V_930 -> V_55 . V_932 )
F_559 ( V_913 , & V_930 -> V_55 . V_240 , true ) ;
V_913 -> V_933 -- ;
F_36 ( & V_913 -> V_931 -> V_175 ) ;
F_551 ( V_930 -> args . V_911 ) ;
F_96 ( V_156 ) ;
F_8 ( L_84 , V_35 ) ;
}
int F_560 ( struct V_929 * V_930 )
{
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_934 ] ,
. V_293 = & V_930 -> args ,
. V_294 = & V_930 -> V_55 ,
. V_295 = V_930 -> V_330 ,
} ;
struct V_164 V_296 = {
. V_166 = F_85 ( V_930 -> args . V_2 ) -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_935 ,
. V_170 = V_930 ,
} ;
int V_285 ;
F_8 ( L_11 , V_35 ) ;
F_38 ( & V_930 -> args . V_160 , & V_930 -> V_55 . V_161 , 1 ) ;
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_285 = V_118 -> V_150 ;
F_561 ( V_930 -> args . V_2 , V_285 ) ;
F_8 ( L_16 , V_35 , V_285 ) ;
F_72 ( V_118 ) ;
return V_285 ;
}
static int F_562 ( struct V_13 * V_14 ,
const struct V_403 * V_234 ,
struct V_936 * V_937 )
{
struct V_938 args = {
. V_234 = V_234 ,
. V_939 = V_14 -> V_940 -> V_226 ,
} ;
struct V_941 V_55 = {
. V_937 = V_937 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_942 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
int V_285 ;
F_8 ( L_11 , V_35 ) ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 ,
& V_55 . V_161 , 0 ) ;
F_8 ( L_16 , V_35 , V_285 ) ;
return V_285 ;
}
int F_563 ( struct V_13 * V_14 ,
const struct V_403 * V_234 ,
struct V_936 * V_937 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_562 ( V_14 , V_234 , V_937 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_8 ( L_104 , V_35 ,
V_8 , V_937 -> V_943 ) ;
return V_8 ;
}
static int
F_564 ( struct V_13 * V_14 ,
struct V_944 * V_945 ,
struct V_295 * V_330 )
{
struct V_946 args = {
. V_945 = V_945 ,
} ;
struct V_947 V_55 = {
. V_945 = V_945 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_948 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
int V_285 ;
F_8 ( L_11 , V_35 ) ;
V_285 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
F_8 ( L_16 , V_35 , V_285 ) ;
return V_285 ;
}
int F_565 ( struct V_13 * V_14 ,
struct V_944 * V_945 ,
struct V_295 * V_330 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_564 ( V_14 , V_945 , V_330 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_566 ( struct V_117 * V_118 , void * V_156 )
{
struct V_949 * V_158 = V_156 ;
struct V_13 * V_14 = F_85 ( V_158 -> args . V_2 ) ;
struct V_134 * V_135 = F_64 ( V_14 ) ;
F_61 ( V_135 ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static void
F_567 ( struct V_117 * V_118 , void * V_156 )
{
struct V_949 * V_158 = V_156 ;
struct V_13 * V_14 = F_85 ( V_158 -> args . V_2 ) ;
if ( ! F_53 ( V_118 , & V_158 -> V_55 . V_161 ) )
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
if ( F_228 ( V_118 , V_14 , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
}
static void F_568 ( void * V_156 )
{
struct V_949 * V_158 = V_156 ;
F_569 ( V_158 ) ;
F_346 ( V_158 -> args . V_2 ,
V_158 -> V_55 . V_370 ) ;
F_192 ( V_158 -> V_330 ) ;
F_96 ( V_158 ) ;
}
int
F_570 ( struct V_949 * V_158 , bool V_952 )
{
struct V_162 V_163 = {
. V_290 = & V_291 [ V_953 ] ,
. V_293 = & V_158 -> args ,
. V_294 = & V_158 -> V_55 ,
. V_295 = V_158 -> V_330 ,
} ;
struct V_164 V_296 = {
. V_118 = & V_158 -> V_118 ,
. V_166 = F_273 ( V_158 -> args . V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_954 ,
. V_170 = V_158 ,
. V_207 = V_300 ,
} ;
struct V_117 * V_118 ;
int V_285 = 0 ;
F_8 ( L_105
L_106 ,
V_158 -> V_118 . V_955 , V_952 ,
V_158 -> args . V_956 ,
V_158 -> args . V_2 -> V_957 ) ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
V_118 = F_70 ( & V_296 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
if ( V_952 == false )
goto V_132;
V_285 = F_107 ( V_118 ) ;
if ( V_285 != 0 )
goto V_132;
V_285 = V_118 -> V_150 ;
F_571 ( V_158 -> args . V_2 , V_285 ) ;
V_132:
F_8 ( L_107 , V_35 , V_285 ) ;
F_72 ( V_118 ) ;
return V_285 ;
}
static int
F_572 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_438 ,
struct V_776 * V_454 , bool V_777 )
{
struct V_958 args = {
. V_959 = V_960 ,
} ;
struct V_779 V_55 = {
. V_454 = V_454 ,
} ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_961 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
} ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_295 * V_330 = NULL ;
int V_285 ;
if ( V_777 ) {
V_53 = V_14 -> V_63 -> V_102 ;
V_330 = F_488 ( V_14 -> V_63 ) ;
V_163 . V_295 = V_330 ;
}
F_8 ( L_11 , V_35 ) ;
V_285 = F_73 ( V_53 , V_14 , & V_163 , & args . V_160 ,
& V_55 . V_161 , 0 ) ;
F_8 ( L_16 , V_35 , V_285 ) ;
if ( V_330 )
F_192 ( V_330 ) ;
return V_285 ;
}
static int
F_573 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_438 , struct V_776 * V_454 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( V_14 -> V_63 ) )
V_8 = F_572 ( V_14 , V_404 , V_438 ,
V_454 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_572 ( V_14 , V_404 , V_438 ,
V_454 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_962 :
goto V_132;
default:
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
}
} while ( V_62 . V_68 );
V_132:
return V_8 ;
}
static int
F_574 ( struct V_13 * V_14 , struct V_403 * V_404 ,
struct V_437 * V_438 )
{
int V_8 ;
struct V_462 * V_462 ;
T_4 V_101 = V_963 ;
struct V_776 * V_454 ;
struct V_964 * V_965 ;
int V_451 ;
V_462 = F_256 ( V_361 ) ;
if ( ! V_462 ) {
V_8 = - V_127 ;
goto V_132;
}
V_454 = F_372 ( V_462 ) ;
V_8 = F_573 ( V_14 , V_404 , V_438 , V_454 ) ;
if ( V_8 == - V_22 || V_8 == - V_962 ) {
V_8 = F_246 ( V_14 , V_404 , V_438 ) ;
goto V_966;
}
if ( V_8 )
goto V_966;
for ( V_451 = 0 ; V_451 < V_454 -> V_967 ; V_451 ++ ) {
V_965 = & V_454 -> V_454 [ V_451 ] ;
switch ( V_965 -> V_101 ) {
case V_450 :
case V_449 :
case V_968 :
V_101 = F_575 ( V_965 -> V_101 ,
& V_965 -> V_969 ) ;
break;
default:
V_101 = V_963 ;
break;
}
if ( ! F_576 ( & V_14 -> V_452 , V_101 ) )
V_101 = V_963 ;
if ( V_101 != V_963 ) {
V_8 = F_244 ( V_14 , V_404 ,
V_438 , V_101 ) ;
if ( ! V_8 )
break;
}
}
if ( V_101 == V_963 )
V_8 = - V_24 ;
V_966:
F_386 ( V_462 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_132:
return V_8 ;
}
static int F_577 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_295 * V_330 )
{
int V_285 ;
struct V_970 args = {
. V_240 = V_240 ,
} ;
struct V_971 V_55 ;
struct V_162 V_163 = {
. V_290 = & V_291 [ V_972 ] ,
. V_293 = & args ,
. V_294 = & V_55 ,
. V_295 = V_330 ,
} ;
struct V_52 * V_166 = V_14 -> V_92 ;
F_232 ( V_14 -> V_63 , V_824 ,
& V_166 , & V_163 ) ;
F_8 ( L_108 , V_240 ) ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_285 = F_69 ( V_166 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
if ( V_285 != V_344 ) {
F_8 ( L_109 , V_285 ) ;
return V_285 ;
}
F_8 ( L_110 , - V_55 . V_285 ) ;
return - V_55 . V_285 ;
}
static int F_189 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_295 * V_330 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_577 ( V_14 , V_240 , V_330 ) ;
if ( V_8 != - V_91 )
break;
F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_578 ( struct V_117 * V_118 , void * V_156 )
{
struct V_973 * V_158 = V_156 ;
F_61 ( F_64 ( V_158 -> V_14 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static void F_579 ( struct V_117 * V_118 , void * V_156 )
{
struct V_973 * V_158 = V_156 ;
F_53 ( V_118 , & V_158 -> V_55 . V_161 ) ;
switch ( V_118 -> V_150 ) {
case - V_91 :
if ( F_228 ( V_118 , V_158 -> V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
}
static void F_580 ( void * V_156 )
{
F_96 ( V_156 ) ;
}
static struct V_117 * F_581 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_295 * V_330 ,
bool V_974 )
{
struct V_162 V_163 = {
. V_290 = & V_291 [ V_975 ] ,
. V_295 = V_330 ,
} ;
struct V_164 V_165 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_976 ,
. V_207 = V_300 ,
} ;
struct V_973 * V_158 ;
F_232 ( V_14 -> V_63 , V_824 ,
& V_165 . V_166 , & V_163 ) ;
F_8 ( L_111 , V_240 ) ;
V_158 = F_257 ( sizeof( * V_158 ) , V_282 ) ;
if ( ! V_158 )
return F_44 ( - V_127 ) ;
V_158 -> V_14 = V_14 ;
F_115 ( & V_158 -> args . V_240 , V_240 ) ;
V_165 . V_170 = V_158 ;
V_163 . V_293 = & V_158 -> args ;
V_163 . V_294 = & V_158 -> V_55 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 0 ) ;
if ( V_974 )
F_39 ( & V_158 -> args . V_160 ) ;
return F_70 ( & V_165 ) ;
}
static int F_191 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_295 * V_330 )
{
struct V_117 * V_118 ;
int V_67 ;
V_118 = F_581 ( V_14 , V_240 , V_330 , true ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_67 = F_108 ( V_118 ) ;
if ( ! V_67 )
V_67 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
return V_67 ;
}
static int F_582 ( struct V_13 * V_14 , struct V_681 * V_682 )
{
struct V_117 * V_118 ;
struct V_295 * V_330 = V_682 -> V_698 -> V_215 -> V_270 ;
V_118 = F_581 ( V_14 , & V_682 -> V_699 , V_330 , false ) ;
F_465 ( V_14 , V_682 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
F_72 ( V_118 ) ;
return 0 ;
}
static bool F_583 ( const T_8 * V_977 ,
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
static bool F_584 ( const T_8 * V_977 ,
const T_8 * V_978 )
{
return F_124 ( V_977 , V_978 ) ;
}
