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
int V_67 ;
V_67 = F_108 ( V_118 ) ;
return V_67 ;
}
static int F_109 ( struct V_65 * V_66 , T_5 V_245 , int V_246 )
{
int V_67 = 0 ;
if ( V_246 & ( V_219 | V_247 ) )
goto V_132;
switch ( V_245 & ( V_70 | V_218 ) ) {
case V_70 :
V_67 |= F_31 ( V_248 , & V_66 -> V_207 ) != 0
&& V_66 -> V_249 != 0 ;
break;
case V_218 :
V_67 |= F_31 ( V_250 , & V_66 -> V_207 ) != 0
&& V_66 -> V_251 != 0 ;
break;
case V_70 | V_218 :
V_67 |= F_31 ( V_252 , & V_66 -> V_207 ) != 0
&& V_66 -> V_253 != 0 ;
}
V_132:
return V_67 ;
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
static void F_112 ( struct V_65 * V_66 , T_5 V_206 )
{
switch ( V_206 ) {
case V_218 :
V_66 -> V_251 ++ ;
break;
case V_70 :
V_66 -> V_249 ++ ;
break;
case V_70 | V_218 :
V_66 -> V_253 ++ ;
}
F_113 ( V_66 , V_66 -> V_66 | V_206 ) ;
}
static void F_114 ( struct V_65 * V_66 )
{
struct V_63 * V_64 = V_66 -> V_215 -> V_258 -> V_63 ;
bool V_259 = false ;
if ( F_115 ( V_248 , & V_66 -> V_207 ) && V_66 -> V_249 )
V_259 = true ;
if ( F_115 ( V_250 , & V_66 -> V_207 ) && V_66 -> V_251 )
V_259 = true ;
if ( F_115 ( V_252 , & V_66 -> V_207 ) && V_66 -> V_253 )
V_259 = true ;
if ( V_259 )
F_116 ( V_64 , V_66 ) ;
}
static bool F_117 ( struct V_65 * V_66 ,
T_8 * V_240 )
{
if ( F_118 ( V_260 , & V_66 -> V_207 ) == 0 )
return true ;
if ( ! F_119 ( V_240 , & V_66 -> V_261 ) ) {
F_114 ( V_66 ) ;
return true ;
}
if ( F_120 ( V_240 , & V_66 -> V_261 ) )
return true ;
return false ;
}
static void F_121 ( struct V_65 * V_66 ,
T_8 * V_240 , T_5 V_206 )
{
F_122 ( V_252 , & V_66 -> V_207 ) ;
switch ( V_206 & ( V_70 | V_218 ) ) {
case V_218 :
F_122 ( V_248 , & V_66 -> V_207 ) ;
break;
case V_70 :
F_122 ( V_250 , & V_66 -> V_207 ) ;
break;
case 0 :
F_122 ( V_248 , & V_66 -> V_207 ) ;
F_122 ( V_250 , & V_66 -> V_207 ) ;
F_122 ( V_260 , & V_66 -> V_207 ) ;
}
if ( V_240 == NULL )
return;
if ( ! F_117 ( V_66 , V_240 ) )
return;
if ( F_31 ( V_262 , & V_66 -> V_207 ) == 0 )
F_123 ( & V_66 -> V_240 , V_240 ) ;
F_123 ( & V_66 -> V_261 , V_240 ) ;
}
static void F_124 ( struct V_65 * V_66 , T_8 * V_240 , T_5 V_206 )
{
F_125 ( & V_66 -> V_263 ) ;
F_121 ( V_66 , V_240 , V_206 ) ;
F_126 ( & V_66 -> V_263 ) ;
if ( F_31 ( V_264 , & V_66 -> V_207 ) )
F_127 ( V_66 -> V_215 -> V_258 -> V_63 ) ;
}
static void F_128 ( struct V_65 * V_66 , T_8 * V_240 , T_5 V_206 )
{
switch ( V_206 ) {
case V_70 :
F_129 ( V_248 , & V_66 -> V_207 ) ;
break;
case V_218 :
F_129 ( V_250 , & V_66 -> V_207 ) ;
break;
case V_70 | V_218 :
F_129 ( V_252 , & V_66 -> V_207 ) ;
}
if ( ! F_117 ( V_66 , V_240 ) )
return;
if ( F_31 ( V_262 , & V_66 -> V_207 ) == 0 )
F_123 ( & V_66 -> V_240 , V_240 ) ;
F_123 ( & V_66 -> V_261 , V_240 ) ;
}
static void F_130 ( struct V_65 * V_66 , T_8 * V_261 , const T_8 * V_265 , T_5 V_206 )
{
F_125 ( & V_66 -> V_263 ) ;
if ( V_265 != NULL ) {
F_123 ( & V_66 -> V_240 , V_265 ) ;
F_129 ( V_262 , & V_66 -> V_207 ) ;
}
if ( V_261 != NULL )
F_128 ( V_66 , V_261 , V_206 ) ;
F_126 ( & V_66 -> V_263 ) ;
F_34 ( & V_66 -> V_215 -> V_266 ) ;
F_112 ( V_66 , V_206 ) ;
F_36 ( & V_66 -> V_215 -> V_266 ) ;
}
static int F_131 ( struct V_65 * V_66 , T_8 * V_261 , T_8 * V_255 , T_5 V_206 )
{
struct V_173 * V_174 = F_75 ( V_66 -> V_2 ) ;
struct V_254 * V_267 ;
int V_67 = 0 ;
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
F_130 ( V_66 , V_261 , & V_267 -> V_240 , V_206 ) ;
V_67 = 1 ;
V_270:
F_36 ( & V_267 -> V_269 ) ;
V_268:
F_135 () ;
if ( ! V_67 && V_261 != NULL ) {
F_130 ( V_66 , V_261 , NULL , V_206 ) ;
V_67 = 1 ;
}
if ( F_31 ( V_264 , & V_66 -> V_207 ) )
F_127 ( V_66 -> V_215 -> V_258 -> V_63 ) ;
return V_67 ;
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
F_21 ( V_2 ) ;
}
static struct V_65 * F_137 ( struct V_192 * V_271 )
{
struct V_65 * V_66 = V_271 -> V_66 ;
struct V_173 * V_174 = F_75 ( V_66 -> V_2 ) ;
struct V_254 * V_255 ;
int V_246 = V_271 -> V_197 . V_217 ;
T_5 V_206 = V_271 -> V_197 . V_206 ;
T_8 V_240 ;
int V_67 = - V_131 ;
for (; ; ) {
if ( F_109 ( V_66 , V_206 , V_246 ) ) {
F_34 ( & V_66 -> V_215 -> V_266 ) ;
if ( F_109 ( V_66 , V_206 , V_246 ) ) {
F_112 ( V_66 , V_206 ) ;
F_36 ( & V_66 -> V_215 -> V_266 ) ;
goto V_272;
}
F_36 ( & V_66 -> V_215 -> V_266 ) ;
}
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
V_67 = F_139 ( V_66 -> V_2 , V_66 -> V_215 -> V_274 , V_246 ) ;
if ( V_67 != 0 )
goto V_132;
}
V_67 = - V_131 ;
if ( F_131 ( V_66 , NULL , & V_240 , V_206 ) )
goto V_272;
}
V_132:
return F_44 ( V_67 ) ;
V_272:
F_91 ( & V_66 -> V_51 ) ;
return V_66 ;
}
static void
F_140 ( struct V_192 * V_158 , struct V_65 * V_66 )
{
struct V_63 * V_64 = F_85 ( V_66 -> V_2 ) -> V_63 ;
struct V_254 * V_255 ;
int V_275 = 0 ;
F_132 () ;
V_255 = F_133 ( F_75 ( V_66 -> V_2 ) -> V_255 ) ;
if ( V_255 )
V_275 = V_255 -> V_207 ;
F_135 () ;
if ( V_158 -> V_197 . V_185 == V_189 ) {
F_141 ( L_18
L_19
L_20 ,
V_64 -> V_98 ) ;
} else if ( ( V_275 & 1UL << V_256 ) == 0 )
F_142 ( V_66 -> V_2 ,
V_158 -> V_215 -> V_274 ,
& V_158 -> V_193 ) ;
else
F_143 ( V_66 -> V_2 ,
V_158 -> V_215 -> V_274 ,
& V_158 -> V_193 ) ;
}
static struct V_65 *
F_144 ( struct V_192 * V_158 )
{
struct V_2 * V_2 = V_158 -> V_66 -> V_2 ;
struct V_65 * V_66 = V_158 -> V_66 ;
int V_67 ;
if ( ! V_158 -> V_276 ) {
if ( V_158 -> V_277 ) {
V_67 = V_158 -> V_277 ;
goto V_8;
}
goto V_278;
}
V_67 = F_145 ( V_2 , & V_158 -> V_194 ) ;
if ( V_67 )
goto V_8;
if ( V_158 -> V_193 . V_279 != 0 )
F_140 ( V_158 , V_66 ) ;
V_278:
F_131 ( V_66 , & V_158 -> V_193 . V_240 , NULL ,
V_158 -> V_197 . V_206 ) ;
F_91 ( & V_66 -> V_51 ) ;
return V_66 ;
V_8:
return F_44 ( V_67 ) ;
}
static struct V_65 *
F_146 ( struct V_192 * V_158 )
{
struct V_2 * V_2 ;
struct V_65 * V_66 = NULL ;
int V_67 ;
if ( ! V_158 -> V_276 ) {
V_66 = F_137 ( V_158 ) ;
goto V_132;
}
V_67 = - V_131 ;
if ( ! ( V_158 -> V_194 . V_280 & V_281 ) )
goto V_8;
V_2 = F_147 ( V_158 -> V_3 -> V_214 , & V_158 -> V_193 . V_234 , & V_158 -> V_194 , V_158 -> V_195 ) ;
V_67 = F_71 ( V_2 ) ;
if ( F_43 ( V_2 ) )
goto V_8;
V_67 = - V_127 ;
V_66 = F_148 ( V_2 , V_158 -> V_215 ) ;
if ( V_66 == NULL )
goto V_282;
if ( V_158 -> V_193 . V_279 != 0 )
F_140 ( V_158 , V_66 ) ;
F_131 ( V_66 , & V_158 -> V_193 . V_240 , NULL ,
V_158 -> V_197 . V_206 ) ;
F_149 ( V_2 ) ;
V_132:
F_138 ( V_158 -> V_197 . V_196 ) ;
return V_66 ;
V_282:
F_149 ( V_2 ) ;
V_8:
return F_44 ( V_67 ) ;
}
static struct V_65 *
F_150 ( struct V_192 * V_158 )
{
if ( V_158 -> V_197 . V_185 == V_235 )
return F_144 ( V_158 ) ;
return F_146 ( V_158 ) ;
}
static struct V_283 * F_151 ( struct V_65 * V_66 )
{
struct V_173 * V_174 = F_75 ( V_66 -> V_2 ) ;
struct V_283 * V_284 ;
F_34 ( & V_66 -> V_2 -> V_175 ) ;
F_152 (ctx, &nfsi->open_files, list) {
if ( V_284 -> V_66 != V_66 )
continue;
F_153 ( V_284 ) ;
F_36 ( & V_66 -> V_2 -> V_175 ) ;
return V_284 ;
}
F_36 ( & V_66 -> V_2 -> V_175 ) ;
return F_44 ( - V_285 ) ;
}
static struct V_192 * F_154 ( struct V_283 * V_284 ,
struct V_65 * V_66 , enum V_184 V_185 )
{
struct V_192 * V_271 ;
V_271 = F_83 ( V_284 -> V_4 , V_66 -> V_215 , 0 , 0 ,
NULL , NULL , V_185 , V_286 ) ;
if ( V_271 == NULL )
return F_44 ( - V_127 ) ;
V_271 -> V_66 = V_66 ;
F_91 ( & V_66 -> V_51 ) ;
return V_271 ;
}
static int F_155 ( struct V_192 * V_271 , T_5 V_206 , struct V_65 * * V_55 )
{
struct V_65 * V_287 ;
int V_67 ;
V_271 -> V_197 . V_217 = 0 ;
V_271 -> V_197 . V_206 = V_206 ;
memset ( & V_271 -> V_193 , 0 , sizeof( V_271 -> V_193 ) ) ;
memset ( & V_271 -> V_198 , 0 , sizeof( V_271 -> V_198 ) ) ;
F_80 ( V_271 ) ;
V_67 = F_156 ( V_271 ) ;
if ( V_67 != 0 )
return V_67 ;
V_287 = F_150 ( V_271 ) ;
if ( F_43 ( V_287 ) )
return F_71 ( V_287 ) ;
F_157 ( V_287 , V_206 ) ;
* V_55 = V_287 ;
return 0 ;
}
static int F_158 ( struct V_192 * V_271 , struct V_65 * V_66 )
{
struct V_65 * V_287 ;
int V_67 ;
F_122 ( V_252 , & V_66 -> V_207 ) ;
F_122 ( V_250 , & V_66 -> V_207 ) ;
F_122 ( V_248 , & V_66 -> V_207 ) ;
F_122 ( V_262 , & V_66 -> V_207 ) ;
F_122 ( V_260 , & V_66 -> V_207 ) ;
F_159 () ;
if ( V_66 -> V_253 != 0 ) {
V_67 = F_155 ( V_271 , V_70 | V_218 , & V_287 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_287 != V_66 )
return - V_288 ;
}
if ( V_66 -> V_251 != 0 ) {
V_67 = F_155 ( V_271 , V_218 , & V_287 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_287 != V_66 )
return - V_288 ;
}
if ( V_66 -> V_249 != 0 ) {
V_67 = F_155 ( V_271 , V_70 , & V_287 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_287 != V_66 )
return - V_288 ;
}
if ( F_31 ( V_262 , & V_66 -> V_207 ) == 0 &&
! F_134 ( & V_66 -> V_240 , & V_66 -> V_261 ) ) {
F_125 ( & V_66 -> V_263 ) ;
if ( F_31 ( V_262 , & V_66 -> V_207 ) == 0 )
F_123 ( & V_66 -> V_240 , & V_66 -> V_261 ) ;
F_126 ( & V_66 -> V_263 ) ;
}
return 0 ;
}
static int F_160 ( struct V_283 * V_284 , struct V_65 * V_66 )
{
struct V_254 * V_255 ;
struct V_192 * V_271 ;
T_5 V_279 = 0 ;
int V_289 ;
V_271 = F_154 ( V_284 , V_66 ,
V_235 ) ;
if ( F_43 ( V_271 ) )
return F_71 ( V_271 ) ;
F_132 () ;
V_255 = F_133 ( F_75 ( V_66 -> V_2 ) -> V_255 ) ;
if ( V_255 != NULL && F_31 ( V_256 , & V_255 -> V_207 ) != 0 )
V_279 = V_255 -> type ;
F_135 () ;
V_271 -> V_197 . V_238 . V_279 = V_279 ;
V_289 = F_158 ( V_271 , V_66 ) ;
F_105 ( V_271 ) ;
return V_289 ;
}
static int F_161 ( struct V_283 * V_284 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_160 ( V_284 , V_66 ) ;
F_162 ( V_284 , 0 , V_8 ) ;
if ( F_78 ( V_14 , V_8 , & V_62 ) )
continue;
if ( V_8 != - V_91 )
break;
F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_163 ( struct V_204 * V_205 , struct V_65 * V_66 )
{
struct V_283 * V_284 ;
int V_67 ;
V_284 = F_151 ( V_66 ) ;
if ( F_43 ( V_284 ) )
return - V_131 ;
V_67 = F_161 ( V_284 , V_66 ) ;
F_164 ( V_284 ) ;
return V_67 ;
}
static int F_165 ( struct V_13 * V_14 , struct V_65 * V_66 , const T_8 * V_240 , int V_8 )
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
F_129 ( V_262 , & V_66 -> V_207 ) ;
F_28 ( V_14 -> V_63 -> V_88 , V_8 ) ;
return - V_131 ;
case - V_77 :
case - V_76 :
F_129 ( V_262 , & V_66 -> V_207 ) ;
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
F_166 ( V_66 -> V_2 ,
V_240 ) ;
F_22 ( V_14 , V_66 ) ;
return 0 ;
case - V_91 :
case - V_90 :
F_129 ( V_262 , & V_66 -> V_207 ) ;
F_167 ( 1 ) ;
return - V_131 ;
case - V_127 :
case - V_291 :
return 0 ;
}
return V_8 ;
}
int F_168 ( struct V_283 * V_284 , struct V_65 * V_66 , const T_8 * V_240 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_192 * V_271 ;
int V_8 ;
V_271 = F_154 ( V_284 , V_66 ,
V_188 ) ;
if ( F_43 ( V_271 ) )
return F_71 ( V_271 ) ;
F_123 ( & V_271 -> V_197 . V_238 . V_255 , V_240 ) ;
V_8 = F_158 ( V_271 , V_66 ) ;
F_105 ( V_271 ) ;
return F_165 ( V_14 , V_66 , V_240 , V_8 ) ;
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
struct V_65 * V_66 = NULL ;
if ( V_158 -> V_292 == 0 )
goto V_293;
if ( ! V_158 -> V_276 )
goto V_293;
V_66 = F_150 ( V_158 ) ;
if ( ! F_43 ( V_66 ) )
F_157 ( V_66 , V_158 -> V_197 . V_206 ) ;
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
struct V_63 * V_64 = V_205 -> V_258 -> V_63 ;
if ( F_177 ( V_158 -> V_197 . V_196 , V_118 ) != 0 )
goto V_305;
if ( V_158 -> V_66 != NULL ) {
struct V_254 * V_255 ;
if ( F_109 ( V_158 -> V_66 , V_158 -> V_197 . V_206 , V_158 -> V_197 . V_217 ) )
goto V_306;
F_132 () ;
V_255 = F_133 ( F_75 ( V_158 -> V_66 -> V_2 ) -> V_255 ) ;
if ( V_158 -> V_197 . V_185 != V_189 &&
V_158 -> V_197 . V_185 != V_188 &&
F_110 ( V_255 , V_158 -> V_197 . V_206 ) )
goto V_307;
F_135 () ;
}
V_158 -> V_197 . V_224 = V_64 -> V_225 ;
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
if ( F_179 ( V_64 ) )
V_158 -> V_197 . V_311 = V_314 ;
else if ( V_64 -> V_168 -> V_315 > 0 )
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
struct V_65 * V_66 = NULL ;
if ( V_158 -> V_292 == 0 )
goto V_293;
if ( V_158 -> V_277 != 0 || ! V_158 -> V_276 )
goto V_293;
if ( V_158 -> V_193 . V_326 & V_327 )
goto V_293;
V_66 = F_150 ( V_158 ) ;
if ( ! F_43 ( V_66 ) )
F_157 ( V_66 , V_158 -> V_197 . V_206 ) ;
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
struct V_65 * V_66 , T_5 V_206 ,
int V_334 )
{
struct V_335 V_336 ;
T_1 V_337 ;
if ( V_271 -> V_193 . V_338 == 0 )
return 0 ;
V_337 = 0 ;
if ( V_334 & V_339 ) {
V_337 = V_340 ;
} else if ( V_206 & V_70 )
V_337 = V_341 ;
V_336 . V_333 = V_333 ;
V_336 . V_155 = V_155 ;
F_185 ( & V_336 , V_271 -> V_193 . V_342 ) ;
F_186 ( V_66 -> V_2 , & V_336 ) ;
if ( ( V_337 & ~ V_336 . V_337 & ( V_341 | V_340 ) ) == 0 )
return 0 ;
F_157 ( V_66 , V_206 ) ;
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
! ( V_197 -> V_217 & V_343 ) )
return - V_285 ;
return V_289 ;
}
F_183 ( V_14 , & V_158 -> V_194 ) ;
if ( V_197 -> V_217 & V_343 ) {
F_74 ( V_3 , & V_193 -> V_172 ) ;
if ( V_197 -> V_217 & V_219 )
V_158 -> V_344 = 1 ;
else if ( V_193 -> V_172 . V_180 != V_193 -> V_172 . V_182 )
V_158 -> V_344 = 1 ;
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
return F_190 ( V_14 -> V_63 ) ;
}
static int F_191 ( struct V_283 * V_284 , struct V_65 * V_66 )
{
struct V_192 * V_271 ;
int V_67 ;
V_271 = F_154 ( V_284 , V_66 ,
V_186 ) ;
if ( F_43 ( V_271 ) )
return F_71 ( V_271 ) ;
V_67 = F_158 ( V_271 , V_66 ) ;
if ( V_67 == - V_288 )
F_192 ( V_284 -> V_4 ) ;
F_105 ( V_271 ) ;
return V_67 ;
}
static int F_193 ( struct V_283 * V_284 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_191 ( V_284 , V_66 ) ;
F_194 ( V_284 , 0 , V_8 ) ;
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
static int F_195 ( struct V_204 * V_205 , struct V_65 * V_66 )
{
struct V_283 * V_284 ;
int V_67 ;
V_284 = F_151 ( V_66 ) ;
if ( F_43 ( V_284 ) )
return - V_131 ;
V_67 = F_193 ( V_284 , V_66 ) ;
F_164 ( V_284 ) ;
return V_67 ;
}
static void F_196 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
T_8 * V_240 = & V_66 -> V_240 ;
struct V_254 * V_255 ;
struct V_299 * V_333 = NULL ;
int V_289 = - V_74 ;
if ( F_31 ( V_262 , & V_66 -> V_207 ) == 0 )
return;
F_132 () ;
V_255 = F_133 ( F_75 ( V_66 -> V_2 ) -> V_255 ) ;
if ( V_255 != NULL &&
F_134 ( & V_255 -> V_240 , V_240 ) ) {
V_333 = F_197 ( V_255 -> V_333 ) ;
F_135 () ;
V_289 = F_198 ( V_14 , V_240 , V_333 ) ;
F_199 ( V_66 , NULL , V_289 ) ;
} else
F_135 () ;
if ( V_289 != V_347 ) {
if ( V_289 != - V_74 )
F_200 ( V_14 , V_240 , V_333 ) ;
F_23 ( V_66 -> V_2 ) ;
F_125 ( & V_66 -> V_263 ) ;
F_123 ( & V_66 -> V_240 , & V_66 -> V_261 ) ;
F_126 ( & V_66 -> V_263 ) ;
F_122 ( V_262 , & V_66 -> V_207 ) ;
}
if ( V_333 != NULL )
F_201 ( V_333 ) ;
}
static int F_202 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
T_8 * V_240 = & V_66 -> V_261 ;
struct V_299 * V_333 = V_66 -> V_215 -> V_274 ;
int V_289 ;
if ( ( F_31 ( V_248 , & V_66 -> V_207 ) == 0 ) &&
( F_31 ( V_250 , & V_66 -> V_207 ) == 0 ) &&
( F_31 ( V_252 , & V_66 -> V_207 ) == 0 ) )
return - V_74 ;
V_289 = F_198 ( V_14 , V_240 , V_333 ) ;
F_203 ( V_66 , NULL , V_289 ) ;
if ( V_289 != V_347 ) {
if ( V_289 != - V_74 )
F_200 ( V_14 , V_240 , V_333 ) ;
F_122 ( V_248 , & V_66 -> V_207 ) ;
F_122 ( V_250 , & V_66 -> V_207 ) ;
F_122 ( V_252 , & V_66 -> V_207 ) ;
F_122 ( V_260 , & V_66 -> V_207 ) ;
}
return V_289 ;
}
static int F_204 ( struct V_204 * V_205 , struct V_65 * V_66 )
{
int V_289 ;
F_196 ( V_66 ) ;
V_289 = F_202 ( V_66 ) ;
if ( V_289 != V_347 )
V_289 = F_195 ( V_205 , V_66 ) ;
return V_289 ;
}
static inline void F_205 ( struct V_192 * V_271 , struct V_5 * V_6 )
{
if ( ( V_271 -> V_193 . V_348 [ 1 ] & V_349 ) &&
! ( V_6 -> V_236 & V_350 ) )
V_6 -> V_236 |= V_351 ;
if ( ( V_271 -> V_193 . V_348 [ 1 ] & V_352 ) &&
! ( V_6 -> V_236 & V_353 ) )
V_6 -> V_236 |= V_354 ;
}
static int F_206 ( struct V_192 * V_271 ,
T_5 V_206 ,
int V_207 ,
struct V_283 * V_284 )
{
struct V_204 * V_205 = V_271 -> V_215 ;
struct V_13 * V_14 = V_205 -> V_258 ;
struct V_4 * V_4 ;
struct V_65 * V_66 ;
unsigned int V_355 ;
int V_67 ;
V_355 = F_207 ( & V_205 -> V_356 ) ;
V_67 = F_187 ( V_271 ) ;
if ( V_67 != 0 )
goto V_132;
V_66 = F_150 ( V_271 ) ;
V_67 = F_71 ( V_66 ) ;
if ( F_43 ( V_66 ) )
goto V_132;
if ( V_14 -> V_95 & V_346 )
F_129 ( V_357 , & V_66 -> V_207 ) ;
V_4 = V_271 -> V_4 ;
if ( V_4 -> V_47 == NULL ) {
F_192 ( V_4 ) ;
V_4 = F_208 ( V_4 , F_209 ( V_66 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_271 -> V_4 ;
} else if ( V_4 != V_284 -> V_4 ) {
F_97 ( V_284 -> V_4 ) ;
V_284 -> V_4 = F_90 ( V_4 ) ;
}
F_210 ( V_4 ,
F_211 ( V_271 -> V_3 -> V_47 ) ) ;
}
V_67 = F_184 ( V_205 -> V_274 , V_271 , V_66 , V_206 , V_207 ) ;
if ( V_67 != 0 )
goto V_132;
V_284 -> V_66 = V_66 ;
if ( V_4 -> V_47 == V_66 -> V_2 ) {
F_212 ( V_284 ) ;
if ( F_213 ( & V_205 -> V_356 , V_355 ) )
F_22 ( V_14 , V_66 ) ;
}
V_132:
return V_67 ;
}
static int F_214 ( struct V_2 * V_3 ,
struct V_283 * V_284 ,
int V_207 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_358 )
{
struct V_204 * V_205 ;
struct V_65 * V_66 = NULL ;
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
V_205 = F_215 ( V_14 , V_333 , V_363 ) ;
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
V_271 -> V_194 . V_244 = F_216 () ;
if ( ! V_271 -> V_194 . V_244 )
goto V_213;
}
V_271 -> V_197 . V_232 = & V_368 [ 0 ] ;
}
if ( V_4 -> V_47 != NULL )
V_271 -> V_66 = F_148 ( V_4 -> V_47 , V_205 ) ;
V_289 = F_206 ( V_271 , V_206 , V_207 , V_284 ) ;
if ( V_289 != 0 )
goto V_213;
V_66 = V_284 -> V_66 ;
if ( ( V_271 -> V_197 . V_217 & V_219 ) &&
( V_271 -> V_197 . V_311 != V_314 ) ) {
F_205 ( V_271 , V_6 ) ;
F_81 ( V_271 -> V_193 . V_194 ) ;
V_289 = F_217 ( V_66 -> V_2 , V_333 ,
V_271 -> V_193 . V_194 , V_6 ,
V_66 , V_7 , V_362 ) ;
if ( V_289 == 0 ) {
F_218 ( V_66 -> V_2 , V_6 ) ;
F_219 ( V_66 -> V_2 , V_271 -> V_193 . V_194 ) ;
F_220 ( V_66 -> V_2 , V_271 -> V_193 . V_194 , V_362 ) ;
}
}
if ( V_271 -> V_344 )
* V_358 |= V_369 ;
if ( F_221 ( V_360 , V_271 -> V_194 . V_244 , V_14 ) ) {
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
static struct V_65 * F_222 ( struct V_2 * V_3 ,
struct V_283 * V_284 ,
int V_207 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_358 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_61 V_62 = { } ;
struct V_65 * V_55 ;
int V_289 ;
do {
V_289 = F_214 ( V_3 , V_284 , V_207 , V_6 , V_7 , V_358 ) ;
V_55 = V_284 -> V_66 ;
F_223 ( V_284 , V_207 , V_289 ) ;
if ( V_289 == 0 )
break;
if ( V_289 == - V_370 ) {
F_224 ( L_5
L_24 ,
F_85 ( V_3 ) -> V_63 -> V_98 ) ;
V_62 . V_68 = 1 ;
continue;
}
if ( V_289 == - V_74 ) {
V_62 . V_68 = 1 ;
continue;
}
if ( V_289 == - V_131 ) {
V_62 . V_68 = 1 ;
continue;
}
if ( F_78 ( V_14 , V_289 , & V_62 ) )
continue;
V_55 = F_44 ( F_19 ( V_14 ,
V_289 , & V_62 ) ) ;
} while ( V_62 . V_68 );
return V_55 ;
}
static int F_225 ( struct V_2 * V_2 , struct V_299 * V_333 ,
struct V_371 * V_372 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_373 ,
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
struct V_377 V_55 = {
. V_372 = V_372 ,
. V_7 = V_362 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_378 ] ,
. V_297 = & V_375 ,
. V_298 = & V_55 ,
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
if ( F_226 ( & V_375 . V_240 , V_2 , V_206 ) ) {
} else if ( V_379 && V_66 != NULL ) {
struct V_381 V_382 = {
. V_383 = V_58 -> V_384 ,
. V_385 = V_58 -> V_386 ,
} ;
if ( ! F_227 ( V_66 ) )
return - V_387 ;
if ( F_228 ( & V_375 . V_240 , V_66 , V_218 ,
& V_382 ) == - V_36 )
return - V_387 ;
} else
F_123 ( & V_375 . V_240 , & V_388 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_55 . V_161 , 1 ) ;
if ( V_289 == 0 && V_66 != NULL )
F_37 ( V_14 , V_107 ) ;
return V_289 ;
}
static int F_217 ( struct V_2 * V_2 , struct V_299 * V_333 ,
struct V_371 * V_372 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_373 ,
struct V_1 * V_362 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_225 ( V_2 , V_333 , V_372 , V_6 , V_66 , V_373 , V_362 ) ;
F_229 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_69 :
if ( ! ( V_6 -> V_236 & V_380 ) ) {
F_230 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_63 -> V_98 ) ;
}
if ( V_66 && ! ( V_66 -> V_66 & V_218 ) ) {
V_8 = - V_387 ;
if ( V_6 -> V_236 & V_389 )
V_8 = - V_29 ;
goto V_132;
}
}
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
V_132:
return V_8 ;
}
static void F_231 ( void * V_158 )
{
struct V_390 * V_156 = V_158 ;
struct V_204 * V_205 = V_156 -> V_66 -> V_215 ;
struct V_242 * V_243 = V_156 -> V_66 -> V_2 -> V_391 ;
if ( V_156 -> V_392 )
F_232 ( V_156 -> V_66 -> V_2 ) ;
F_101 ( V_156 -> V_66 ) ;
F_100 ( V_156 -> V_375 . V_196 ) ;
F_102 ( V_205 ) ;
F_103 ( V_243 ) ;
F_96 ( V_156 ) ;
}
static void F_233 ( struct V_117 * V_118 , void * V_158 )
{
struct V_390 * V_156 = V_158 ;
struct V_65 * V_66 = V_156 -> V_66 ;
struct V_13 * V_14 = F_85 ( V_156 -> V_2 ) ;
F_8 ( L_29 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_156 -> V_55 . V_161 ) )
return;
F_234 ( V_66 , & V_156 -> V_375 , & V_156 -> V_55 , V_118 -> V_150 ) ;
switch ( V_118 -> V_150 ) {
case 0 :
if ( V_156 -> V_392 )
F_235 ( V_66 -> V_2 ,
V_156 -> V_393 ) ;
F_124 ( V_66 , & V_156 -> V_55 . V_240 , 0 ) ;
F_37 ( V_14 , V_156 -> V_107 ) ;
goto V_394;
case - V_73 :
case - V_76 :
case - V_94 :
case - V_74 :
case - V_75 :
if ( V_156 -> V_375 . V_206 == 0 )
break;
default:
if ( F_236 ( V_118 , V_14 , V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
goto V_394;
}
}
F_124 ( V_66 , NULL , V_156 -> V_375 . V_206 ) ;
V_394:
F_138 ( V_156 -> V_375 . V_196 ) ;
F_145 ( V_156 -> V_2 , V_156 -> V_55 . V_372 ) ;
F_8 ( L_30 , V_35 , V_118 -> V_150 ) ;
}
static void F_237 ( struct V_117 * V_118 , void * V_158 )
{
struct V_390 * V_156 = V_158 ;
struct V_65 * V_66 = V_156 -> V_66 ;
struct V_2 * V_2 = V_156 -> V_2 ;
int V_395 = 0 ;
F_8 ( L_29 , V_35 ) ;
if ( F_177 ( V_156 -> V_375 . V_196 , V_118 ) != 0 )
goto V_305;
V_118 -> V_309 . V_294 = & V_295 [ V_396 ] ;
V_156 -> V_375 . V_206 = V_70 | V_218 ;
F_34 ( & V_66 -> V_215 -> V_266 ) ;
if ( V_66 -> V_253 == 0 ) {
if ( V_66 -> V_249 == 0 ) {
V_395 |= F_31 ( V_248 , & V_66 -> V_207 ) ;
V_395 |= F_31 ( V_252 , & V_66 -> V_207 ) ;
V_156 -> V_375 . V_206 &= ~ V_70 ;
}
if ( V_66 -> V_251 == 0 ) {
V_395 |= F_31 ( V_250 , & V_66 -> V_207 ) ;
V_395 |= F_31 ( V_252 , & V_66 -> V_207 ) ;
V_156 -> V_375 . V_206 &= ~ V_218 ;
}
}
if ( ! F_227 ( V_66 ) )
V_395 = 0 ;
F_36 ( & V_66 -> V_215 -> V_266 ) ;
if ( ! V_395 ) {
goto V_306;
}
if ( V_156 -> V_375 . V_206 == 0 ) {
V_118 -> V_309 . V_294 = & V_295 [ V_397 ] ;
if ( V_156 -> V_392 &&
F_238 ( V_2 , & V_156 -> V_393 , V_118 ) ) {
F_138 ( V_156 -> V_375 . V_196 ) ;
goto V_305;
}
}
F_81 ( V_156 -> V_55 . V_372 ) ;
V_156 -> V_107 = V_155 ;
if ( F_63 ( F_85 ( V_2 ) ,
& V_156 -> V_375 . V_160 ,
& V_156 -> V_55 . V_161 ,
V_118 ) != 0 )
F_138 ( V_156 -> V_375 . V_196 ) ;
F_8 ( L_31 , V_35 ) ;
return;
V_306:
V_118 -> V_317 = NULL ;
V_305:
F_60 ( V_118 , & V_156 -> V_55 . V_161 ) ;
}
int F_239 ( struct V_65 * V_66 , T_6 V_209 , int V_398 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_390 * V_156 ;
struct V_204 * V_205 = V_66 -> V_215 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_397 ] ,
. V_299 = V_66 -> V_215 -> V_274 ,
} ;
struct V_164 V_300 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_399 ,
. V_302 = V_303 ,
. V_207 = V_304 ,
} ;
int V_289 = - V_127 ;
F_240 ( V_14 -> V_63 , V_400 ,
& V_300 . V_166 , & V_163 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_209 ) ;
if ( V_156 == NULL )
goto V_132;
F_38 ( & V_156 -> V_375 . V_160 , & V_156 -> V_55 . V_161 , 1 ) ;
V_156 -> V_2 = V_66 -> V_2 ;
V_156 -> V_66 = V_66 ;
V_156 -> V_375 . V_234 = F_93 ( V_66 -> V_2 ) ;
V_156 -> V_375 . V_240 = & V_66 -> V_261 ;
V_156 -> V_375 . V_196 = F_88 ( & V_66 -> V_215 -> V_212 , V_209 ) ;
if ( V_156 -> V_375 . V_196 == NULL )
goto V_401;
V_156 -> V_375 . V_206 = 0 ;
V_156 -> V_375 . V_231 = V_14 -> V_402 ;
V_156 -> V_55 . V_372 = & V_156 -> V_372 ;
V_156 -> V_55 . V_196 = V_156 -> V_375 . V_196 ;
V_156 -> V_55 . V_14 = V_14 ;
V_156 -> V_392 = F_241 ( V_66 -> V_2 ) ;
F_89 ( V_156 -> V_2 -> V_391 ) ;
V_163 . V_297 = & V_156 -> V_375 ;
V_163 . V_298 = & V_156 -> V_55 ;
V_300 . V_170 = V_156 ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_289 = 0 ;
if ( V_398 )
V_289 = F_108 ( V_118 ) ;
F_72 ( V_118 ) ;
return V_289 ;
V_401:
F_96 ( V_156 ) ;
V_132:
F_101 ( V_66 ) ;
F_102 ( V_205 ) ;
return V_289 ;
}
static struct V_2 *
F_242 ( struct V_2 * V_3 , struct V_283 * V_284 ,
int V_217 , struct V_5 * V_403 , int * V_358 )
{
struct V_65 * V_66 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_284 -> V_4 , V_403 , & V_17 ) ;
V_66 = F_222 ( V_3 , V_284 , V_217 , V_403 , V_7 , V_358 ) ;
F_4 ( V_7 ) ;
if ( F_43 ( V_66 ) )
return F_243 ( V_66 ) ;
return V_66 -> V_2 ;
}
static void F_244 ( struct V_283 * V_284 , int V_404 )
{
if ( V_284 -> V_66 == NULL )
return;
if ( V_404 )
F_245 ( V_284 -> V_66 , V_284 -> V_245 ) ;
else
F_157 ( V_284 -> V_66 , V_284 -> V_245 ) ;
}
static int F_246 ( struct V_13 * V_14 , struct V_405 * V_406 )
{
struct V_407 args = {
. V_406 = V_406 ,
} ;
struct V_408 V_55 = {} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_409 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
int V_289 ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
if ( V_289 == 0 ) {
switch ( V_14 -> V_63 -> V_410 ) {
case 0 :
V_55 . V_15 [ 1 ] &= V_411 ;
V_55 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_55 . V_15 [ 2 ] &= V_412 ;
break;
case 2 :
V_55 . V_15 [ 2 ] &= V_413 ;
}
memcpy ( V_14 -> V_15 , V_55 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_95 &= ~ ( V_414 | V_415 |
V_416 | V_417 |
V_418 | V_419 | V_420 |
V_421 | V_422 |
V_423 | V_424 |
V_9 ) ;
if ( V_55 . V_15 [ 0 ] & V_425 &&
V_55 . V_426 & V_427 )
V_14 -> V_95 |= V_414 ;
if ( V_55 . V_428 != 0 )
V_14 -> V_95 |= V_415 ;
if ( V_55 . V_429 != 0 )
V_14 -> V_95 |= V_416 ;
if ( V_55 . V_15 [ 0 ] & V_46 )
V_14 -> V_95 |= V_417 ;
if ( V_55 . V_15 [ 1 ] & V_430 )
V_14 -> V_95 |= V_418 ;
if ( V_55 . V_15 [ 1 ] & V_431 )
V_14 -> V_95 |= V_419 ;
if ( V_55 . V_15 [ 1 ] & V_432 )
V_14 -> V_95 |= V_420 ;
if ( V_55 . V_15 [ 1 ] & V_433 )
V_14 -> V_95 |= V_421 ;
if ( V_55 . V_15 [ 1 ] & V_349 )
V_14 -> V_95 |= V_422 ;
if ( V_55 . V_15 [ 1 ] & V_434 )
V_14 -> V_95 |= V_423 ;
if ( V_55 . V_15 [ 1 ] & V_352 )
V_14 -> V_95 |= V_424 ;
#ifdef F_247
if ( V_55 . V_15 [ 2 ] & V_435 )
V_14 -> V_95 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_55 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_435 ;
memcpy ( V_14 -> V_402 , V_55 . V_15 , sizeof( V_14 -> V_402 ) ) ;
V_14 -> V_402 [ 0 ] &= V_436 | V_437 ;
V_14 -> V_402 [ 1 ] &= V_434 | V_352 ;
V_14 -> V_402 [ 2 ] = 0 ;
V_14 -> V_426 = V_55 . V_426 ;
V_14 -> V_438 = V_55 . V_438 ;
}
return V_289 ;
}
int F_248 ( struct V_13 * V_14 , struct V_405 * V_406 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_246 ( V_14 , V_406 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_249 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_440 )
{
T_1 V_231 [ 3 ] ;
struct V_441 args = {
. V_231 = V_231 ,
} ;
struct V_442 V_55 = {
. V_14 = V_14 ,
. V_372 = V_440 -> V_372 ,
. V_234 = V_406 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_443 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
V_231 [ 0 ] = V_233 [ 0 ] ;
V_231 [ 1 ] = V_233 [ 1 ] ;
V_231 [ 2 ] = V_233 [ 2 ] & ~ V_435 ;
F_81 ( V_440 -> V_372 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_250 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_440 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_249 ( V_14 , V_406 , V_440 ) ;
F_251 ( V_14 , V_406 , V_440 -> V_372 , V_8 ) ;
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
static int F_252 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_440 , T_4 V_101 )
{
struct V_444 V_445 = {
. V_446 = V_101 ,
} ;
struct V_447 * V_448 ;
int V_67 ;
V_448 = F_253 ( & V_445 , V_14 -> V_92 ) ;
if ( F_43 ( V_448 ) ) {
V_67 = - V_29 ;
goto V_132;
}
V_67 = F_250 ( V_14 , V_406 , V_440 ) ;
V_132:
return V_67 ;
}
static int F_254 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_440 )
{
static const T_4 V_449 [] = {
V_106 ,
V_105 ,
V_450 ,
V_451 ,
V_452 ,
} ;
int V_289 = - V_24 ;
T_9 V_453 ;
if ( V_14 -> V_454 . V_455 > 0 ) {
for ( V_453 = 0 ; V_453 < V_14 -> V_454 . V_455 ; V_453 ++ ) {
V_289 = F_252 ( V_14 , V_406 , V_440 ,
V_14 -> V_454 . V_456 [ V_453 ] ) ;
if ( V_289 == - V_22 || V_289 == - V_29 )
continue;
break;
}
} else {
for ( V_453 = 0 ; V_453 < F_255 ( V_449 ) ; V_453 ++ ) {
V_289 = F_252 ( V_14 , V_406 , V_440 ,
V_449 [ V_453 ] ) ;
if ( V_289 == - V_22 || V_289 == - V_29 )
continue;
break;
}
}
if ( V_289 == - V_29 )
V_289 = - V_24 ;
return V_289 ;
}
static int F_256 ( struct V_13 * V_14 ,
struct V_405 * V_406 , struct V_439 * V_440 )
{
int V_457 = V_14 -> V_63 -> V_410 ;
return V_458 [ V_457 ] -> F_257 ( V_14 , V_406 , V_440 ) ;
}
int F_258 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_440 ,
bool V_459 )
{
int V_289 ;
switch ( V_459 ) {
case false :
V_289 = F_250 ( V_14 , V_406 , V_440 ) ;
if ( V_289 != - V_22 )
break;
default:
V_289 = F_256 ( V_14 , V_406 , V_440 ) ;
}
if ( V_289 == 0 )
V_289 = F_248 ( V_14 , V_406 ) ;
if ( V_289 == 0 )
V_289 = F_259 ( V_14 , V_406 , V_440 ) ;
return F_7 ( V_289 ) ;
}
static int F_260 ( struct V_13 * V_14 , struct V_405 * V_460 ,
struct V_439 * V_440 )
{
int error ;
struct V_371 * V_372 = V_440 -> V_372 ;
struct V_1 * V_7 = NULL ;
error = F_248 ( V_14 , V_460 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_87 ( V_14 , V_363 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
error = F_261 ( V_14 , V_460 , V_372 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_213;
}
if ( V_372 -> V_280 & V_461 &&
! F_262 ( & V_14 -> V_462 , & V_372 -> V_462 ) )
memcpy ( & V_14 -> V_462 , & V_372 -> V_462 , sizeof( V_14 -> V_462 ) ) ;
V_213:
F_95 ( V_7 ) ;
return error ;
}
static int F_263 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_463 * V_230 , struct V_371 * V_372 ,
struct V_405 * V_406 )
{
int V_289 = - V_127 ;
struct V_464 * V_464 = NULL ;
struct V_465 * V_466 = NULL ;
V_464 = F_264 ( V_363 ) ;
if ( V_464 == NULL )
goto V_132;
V_466 = F_265 ( sizeof( struct V_465 ) , V_363 ) ;
if ( V_466 == NULL )
goto V_132;
V_289 = F_266 ( V_92 , V_3 , V_230 , V_466 , V_464 ) ;
if ( V_289 != 0 )
goto V_132;
if ( F_262 ( & F_85 ( V_3 ) -> V_462 , & V_466 -> V_372 . V_462 ) ) {
F_8 ( L_34
L_35 , V_35 , V_230 -> V_230 ) ;
V_289 = - V_78 ;
goto V_132;
}
F_267 ( & V_466 -> V_372 ) ;
memcpy ( V_372 , & V_466 -> V_372 , sizeof( struct V_371 ) ) ;
memset ( V_406 , 0 , sizeof( struct V_405 ) ) ;
V_132:
if ( V_464 )
F_268 ( V_464 ) ;
F_96 ( V_466 ) ;
return V_289 ;
}
static int F_188 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_371 * V_372 , struct V_1 * V_7 )
{
struct V_467 args = {
. V_234 = V_406 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_468 V_55 = {
. V_372 = V_372 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_469 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
args . V_231 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_372 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_261 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_371 * V_372 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_188 ( V_14 , V_406 , V_372 , V_7 ) ;
F_269 ( V_14 , V_406 , V_372 , V_8 ) ;
V_8 = F_19 ( V_14 , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_270 ( struct V_4 * V_4 , struct V_371 * V_372 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = V_4 -> V_47 ;
struct V_299 * V_333 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_1 * V_7 = NULL ;
int V_289 ;
if ( F_271 ( V_2 ) )
F_272 ( V_2 ) ;
F_81 ( V_372 ) ;
if ( V_6 -> V_236 & V_389 )
V_6 -> V_236 &= ~ ( V_354 | V_470 ) ;
if ( ( V_6 -> V_236 & ~ ( V_471 | V_389 ) ) == 0 )
return 0 ;
if ( V_6 -> V_236 & V_471 ) {
struct V_283 * V_284 ;
V_284 = F_273 ( V_6 -> V_472 ) ;
if ( V_284 ) {
V_333 = V_284 -> V_333 ;
V_66 = V_284 -> V_66 ;
}
}
V_7 = F_87 ( F_85 ( V_2 ) , V_363 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
V_289 = F_217 ( V_2 , V_333 , V_372 , V_6 , V_66 , NULL , V_7 ) ;
if ( V_289 == 0 ) {
F_218 ( V_2 , V_6 ) ;
F_220 ( V_2 , V_372 , V_7 ) ;
}
F_95 ( V_7 ) ;
return V_289 ;
}
static int F_274 ( struct V_52 * V_53 , struct V_2 * V_3 ,
const struct V_463 * V_230 , struct V_405 * V_406 ,
struct V_371 * V_372 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
int V_289 ;
struct V_473 args = {
. V_231 = V_14 -> V_15 ,
. V_474 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
} ;
struct V_442 V_55 = {
. V_14 = V_14 ,
. V_372 = V_372 ,
. V_7 = V_7 ,
. V_234 = V_406 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_475 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
args . V_231 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_372 ) ;
F_8 ( L_36 , V_230 -> V_230 ) ;
V_289 = F_73 ( V_53 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
F_8 ( L_37 , V_289 ) ;
return V_289 ;
}
static void F_275 ( struct V_371 * V_372 )
{
V_372 -> V_280 |= V_318 | V_476 |
V_477 | V_478 ;
V_372 -> V_245 = V_323 | V_479 | V_480 ;
V_372 -> V_481 = 2 ;
}
static int F_276 ( struct V_52 * * V_53 , struct V_2 * V_3 ,
struct V_463 * V_230 , struct V_405 * V_406 ,
struct V_371 * V_372 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
struct V_52 * V_92 = * V_53 ;
int V_8 ;
do {
V_8 = F_274 ( V_92 , V_3 , V_230 , V_406 , V_372 , V_7 ) ;
F_277 ( V_3 , V_230 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_285 ;
goto V_132;
case - V_78 :
V_8 = F_263 ( V_92 , V_3 , V_230 , V_372 , V_406 ) ;
goto V_132;
case - V_22 :
V_8 = - V_24 ;
if ( V_92 != * V_53 )
goto V_132;
V_92 = F_278 ( V_92 , V_3 , V_230 ) ;
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
F_279 ( V_92 ) ;
return V_8 ;
}
static int F_280 ( struct V_2 * V_3 , struct V_463 * V_230 ,
struct V_405 * V_406 , struct V_371 * V_372 ,
struct V_1 * V_7 )
{
int V_289 ;
struct V_52 * V_92 = F_281 ( V_3 ) ;
V_289 = F_276 ( & V_92 , V_3 , V_230 , V_406 , V_372 , V_7 ) ;
if ( V_92 != F_281 ( V_3 ) ) {
F_279 ( V_92 ) ;
F_275 ( V_372 ) ;
}
return V_289 ;
}
struct V_52 *
F_282 ( struct V_2 * V_3 , struct V_463 * V_230 ,
struct V_405 * V_406 , struct V_371 * V_372 )
{
struct V_52 * V_92 = F_281 ( V_3 ) ;
int V_289 ;
V_289 = F_276 ( & V_92 , V_3 , V_230 , V_406 , V_372 , NULL ) ;
if ( V_289 < 0 )
return F_44 ( V_289 ) ;
return ( V_92 == F_281 ( V_3 ) ) ? F_283 ( V_92 ) : V_92 ;
}
static int F_284 ( struct V_2 * V_2 , struct V_335 * V_482 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_483 args = {
. V_234 = F_93 ( V_2 ) ,
. V_231 = V_14 -> V_402 ,
} ;
struct V_484 V_55 = {
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_485 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_482 -> V_333 ,
} ;
int V_245 = V_482 -> V_337 ;
int V_289 = 0 ;
if ( V_245 & V_341 )
args . V_201 |= V_220 ;
if ( F_285 ( V_2 -> V_486 ) ) {
if ( V_245 & V_487 )
args . V_201 |= V_221 | V_222 | V_488 ;
if ( V_245 & V_340 )
args . V_201 |= V_489 ;
} else {
if ( V_245 & V_487 )
args . V_201 |= V_221 | V_222 ;
if ( V_245 & V_340 )
args . V_201 |= V_223 ;
}
V_55 . V_372 = F_286 () ;
if ( V_55 . V_372 == NULL )
return - V_127 ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
if ( ! V_289 ) {
F_185 ( V_482 , V_55 . V_201 ) ;
F_145 ( V_2 , V_55 . V_372 ) ;
}
F_287 ( V_55 . V_372 ) ;
return V_289 ;
}
static int F_288 ( struct V_2 * V_2 , struct V_335 * V_482 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_284 ( V_2 , V_482 ) ;
F_289 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_290 ( struct V_2 * V_2 , struct V_464 * V_464 ,
unsigned int V_50 , unsigned int V_490 )
{
struct V_491 args = {
. V_234 = F_93 ( V_2 ) ,
. V_50 = V_50 ,
. V_490 = V_490 ,
. V_43 = & V_464 ,
} ;
struct V_492 V_55 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_493 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
return F_73 ( F_85 ( V_2 ) -> V_92 , F_85 ( V_2 ) , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_291 ( struct V_2 * V_2 , struct V_464 * V_464 ,
unsigned int V_50 , unsigned int V_490 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_290 ( V_2 , V_464 , V_50 , V_490 ) ;
F_292 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_293 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_207 )
{
struct V_1 V_17 , * V_373 = NULL ;
struct V_283 * V_284 ;
struct V_65 * V_66 ;
int V_358 = 0 ;
int V_289 = 0 ;
V_284 = F_294 ( V_4 , V_70 ) ;
if ( F_43 ( V_284 ) )
return F_71 ( V_284 ) ;
V_373 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_295 () ;
V_66 = F_222 ( V_3 , V_284 , V_207 , V_6 , V_373 , & V_358 ) ;
if ( F_43 ( V_66 ) ) {
V_289 = F_71 ( V_66 ) ;
goto V_132;
}
V_132:
F_4 ( V_373 ) ;
F_164 ( V_284 ) ;
return V_289 ;
}
static int F_296 ( struct V_2 * V_3 , struct V_463 * V_230 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_494 args = {
. V_234 = F_93 ( V_3 ) ,
. V_230 = * V_230 ,
} ;
struct V_495 V_55 = {
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_496 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
int V_289 ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 1 ) ;
if ( V_289 == 0 )
F_74 ( V_3 , & V_55 . V_172 ) ;
return V_289 ;
}
static int F_297 ( struct V_2 * V_3 , struct V_463 * V_230 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_296 ( V_3 , V_230 ) ;
F_298 ( V_3 , V_230 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_299 ( struct V_162 * V_163 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_494 * args = V_163 -> V_297 ;
struct V_495 * V_55 = V_163 -> V_298 ;
V_55 -> V_14 = V_14 ;
V_163 -> V_294 = & V_295 [ V_496 ] ;
F_38 ( & args -> V_160 , & V_55 -> V_161 , 1 ) ;
F_81 ( V_55 -> V_497 ) ;
}
static void F_300 ( struct V_117 * V_118 , struct V_498 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_3 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_301 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_498 * V_158 = V_118 -> V_499 ;
struct V_495 * V_55 = & V_158 -> V_55 ;
if ( ! F_60 ( V_118 , & V_55 -> V_161 ) )
return 0 ;
if ( F_236 ( V_118 , V_55 -> V_14 , NULL ) == - V_131 )
return 0 ;
F_74 ( V_3 , & V_55 -> V_172 ) ;
return 1 ;
}
static void F_302 ( struct V_162 * V_163 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_500 * V_375 = V_163 -> V_297 ;
struct V_501 * V_55 = V_163 -> V_298 ;
V_163 -> V_294 = & V_295 [ V_502 ] ;
V_55 -> V_14 = V_14 ;
F_38 ( & V_375 -> V_160 , & V_55 -> V_161 , 1 ) ;
}
static void F_303 ( struct V_117 * V_118 , struct V_503 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_504 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_304 ( struct V_117 * V_118 , struct V_2 * V_504 ,
struct V_2 * V_505 )
{
struct V_503 * V_158 = V_118 -> V_499 ;
struct V_501 * V_55 = & V_158 -> V_55 ;
if ( ! F_60 ( V_118 , & V_55 -> V_161 ) )
return 0 ;
if ( F_236 ( V_118 , V_55 -> V_14 , NULL ) == - V_131 )
return 0 ;
F_74 ( V_504 , & V_55 -> V_506 ) ;
F_74 ( V_505 , & V_55 -> V_507 ) ;
return 1 ;
}
static int F_305 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_463 * V_230 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_508 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_474 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_509 V_55 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_510 ] ,
. V_297 = & V_375 ,
. V_298 = & V_55 ,
} ;
int V_289 = - V_127 ;
V_55 . V_372 = F_286 () ;
if ( V_55 . V_372 == NULL )
goto V_132;
V_55 . V_7 = F_87 ( V_14 , V_363 ) ;
if ( F_43 ( V_55 . V_7 ) ) {
V_289 = F_71 ( V_55 . V_7 ) ;
goto V_132;
}
V_375 . V_231 = F_6 ( V_14 , V_55 . V_7 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_55 . V_161 , 1 ) ;
if ( ! V_289 ) {
F_74 ( V_3 , & V_55 . V_172 ) ;
V_289 = F_219 ( V_2 , V_55 . V_372 ) ;
if ( ! V_289 )
F_220 ( V_2 , V_55 . V_372 , V_55 . V_7 ) ;
}
F_95 ( V_55 . V_7 ) ;
V_132:
F_287 ( V_55 . V_372 ) ;
return V_289 ;
}
static int F_306 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_463 * V_230 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( F_85 ( V_2 ) ,
F_305 ( V_2 , V_3 , V_230 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static struct V_511 * F_307 ( struct V_2 * V_3 ,
struct V_463 * V_230 , struct V_5 * V_6 , T_1 V_512 )
{
struct V_511 * V_158 ;
V_158 = F_86 ( sizeof( * V_158 ) , V_363 ) ;
if ( V_158 != NULL ) {
struct V_13 * V_14 = F_85 ( V_3 ) ;
V_158 -> V_7 = F_87 ( V_14 , V_363 ) ;
if ( F_43 ( V_158 -> V_7 ) )
goto V_293;
V_158 -> V_163 . V_294 = & V_295 [ V_513 ] ;
V_158 -> V_163 . V_297 = & V_158 -> V_375 ;
V_158 -> V_163 . V_298 = & V_158 -> V_55 ;
V_158 -> V_375 . V_474 = F_93 ( V_3 ) ;
V_158 -> V_375 . V_14 = V_14 ;
V_158 -> V_375 . V_230 = V_230 ;
V_158 -> V_375 . V_208 = V_6 ;
V_158 -> V_375 . V_512 = V_512 ;
V_158 -> V_375 . V_231 = F_6 ( V_14 , V_158 -> V_7 ) ;
V_158 -> V_55 . V_14 = V_14 ;
V_158 -> V_55 . V_234 = & V_158 -> V_234 ;
V_158 -> V_55 . V_372 = & V_158 -> V_372 ;
V_158 -> V_55 . V_7 = V_158 -> V_7 ;
F_81 ( V_158 -> V_55 . V_372 ) ;
}
return V_158 ;
V_293:
F_96 ( V_158 ) ;
return NULL ;
}
static int F_308 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_511 * V_158 )
{
int V_289 = F_73 ( F_85 ( V_3 ) -> V_92 , F_85 ( V_3 ) , & V_158 -> V_163 ,
& V_158 -> V_375 . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
if ( V_289 == 0 ) {
F_74 ( V_3 , & V_158 -> V_55 . V_514 ) ;
V_289 = F_309 ( V_4 , V_158 -> V_55 . V_234 , V_158 -> V_55 . V_372 , V_158 -> V_55 . V_7 ) ;
}
return V_289 ;
}
static void F_310 ( struct V_511 * V_158 )
{
F_95 ( V_158 -> V_7 ) ;
F_96 ( V_158 ) ;
}
static int F_311 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_464 * V_464 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_511 * V_158 ;
int V_289 = - V_515 ;
if ( V_12 > V_516 )
goto V_132;
V_289 = - V_127 ;
V_158 = F_307 ( V_3 , & V_4 -> V_11 , V_6 , V_517 ) ;
if ( V_158 == NULL )
goto V_132;
V_158 -> V_163 . V_294 = & V_295 [ V_518 ] ;
V_158 -> V_375 . V_238 . V_519 . V_43 = & V_464 ;
V_158 -> V_375 . V_238 . V_519 . V_12 = V_12 ;
V_158 -> V_375 . V_7 = V_7 ;
V_289 = F_308 ( V_3 , V_4 , V_158 ) ;
F_310 ( V_158 ) ;
V_132:
return V_289 ;
}
static int F_312 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_464 * V_464 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_311 ( V_3 , V_4 , V_464 , V_12 , V_6 , V_7 ) ;
F_313 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_314 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_511 * V_158 ;
int V_289 = - V_127 ;
V_158 = F_307 ( V_3 , & V_4 -> V_11 , V_6 , V_520 ) ;
if ( V_158 == NULL )
goto V_132;
V_158 -> V_375 . V_7 = V_7 ;
V_289 = F_308 ( V_3 , V_4 , V_158 ) ;
F_310 ( V_158 ) ;
V_132:
return V_289 ;
}
static int F_315 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_295 () ;
do {
V_8 = F_314 ( V_3 , V_4 , V_6 , V_7 ) ;
F_316 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_317 ( struct V_4 * V_4 , struct V_299 * V_333 ,
T_2 V_37 , struct V_464 * * V_43 , unsigned int V_51 , int V_521 )
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
. V_294 = & V_295 [ V_523 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_8 ( L_38 , V_35 ,
V_4 ,
( unsigned long long ) V_37 ) ;
F_9 ( V_37 , F_75 ( V_3 ) -> V_524 , V_4 , & args ) ;
V_55 . V_50 = args . V_50 ;
V_289 = F_73 ( F_85 ( V_3 ) -> V_92 , F_85 ( V_3 ) , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
if ( V_289 >= 0 ) {
memcpy ( F_75 ( V_3 ) -> V_524 , V_55 . V_38 . V_158 , V_525 ) ;
V_289 += args . V_50 ;
}
F_318 ( V_3 ) ;
F_8 ( L_39 , V_35 , V_289 ) ;
return V_289 ;
}
static int F_319 ( struct V_4 * V_4 , struct V_299 * V_333 ,
T_2 V_37 , struct V_464 * * V_43 , unsigned int V_51 , int V_521 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_317 ( V_4 , V_333 , V_37 ,
V_43 , V_51 , V_521 ) ;
F_320 ( V_4 -> V_47 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_4 -> V_47 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_321 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_526 )
{
struct V_511 * V_158 ;
int V_245 = V_6 -> V_10 ;
int V_289 = - V_127 ;
V_158 = F_307 ( V_3 , & V_4 -> V_11 , V_6 , V_527 ) ;
if ( V_158 == NULL )
goto V_132;
if ( F_322 ( V_245 ) )
V_158 -> V_375 . V_512 = V_528 ;
else if ( F_323 ( V_245 ) ) {
V_158 -> V_375 . V_512 = V_529 ;
V_158 -> V_375 . V_238 . V_530 . V_531 = F_324 ( V_526 ) ;
V_158 -> V_375 . V_238 . V_530 . V_532 = F_325 ( V_526 ) ;
}
else if ( F_326 ( V_245 ) ) {
V_158 -> V_375 . V_512 = V_533 ;
V_158 -> V_375 . V_238 . V_530 . V_531 = F_324 ( V_526 ) ;
V_158 -> V_375 . V_238 . V_530 . V_532 = F_325 ( V_526 ) ;
} else if ( ! F_327 ( V_245 ) ) {
V_289 = - V_27 ;
goto V_293;
}
V_158 -> V_375 . V_7 = V_7 ;
V_289 = F_308 ( V_3 , V_4 , V_158 ) ;
V_293:
F_310 ( V_158 ) ;
V_132:
return V_289 ;
}
static int F_328 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_526 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_295 () ;
do {
V_8 = F_321 ( V_3 , V_4 , V_6 , V_7 , V_526 ) ;
F_329 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_330 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_534 * V_535 )
{
struct V_536 args = {
. V_234 = V_406 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_537 V_55 = {
. V_535 = V_535 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_538 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
F_81 ( V_535 -> V_372 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_331 ( struct V_13 * V_14 , struct V_405 * V_406 , struct V_534 * V_535 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_330 ( V_14 , V_406 , V_535 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_332 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_539 )
{
struct V_540 args = {
. V_234 = V_406 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_541 V_55 = {
. V_539 = V_539 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_542 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_259 ( struct V_13 * V_14 , struct V_405 * V_406 , struct V_439 * V_539 )
{
struct V_61 V_62 = { } ;
unsigned long V_543 = V_155 ;
int V_8 ;
do {
V_8 = F_332 ( V_14 , V_406 , V_539 ) ;
F_333 ( V_14 , V_406 , V_539 -> V_372 , V_8 ) ;
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
static int F_334 ( struct V_13 * V_14 , struct V_405 * V_406 , struct V_439 * V_539 )
{
int error ;
F_81 ( V_539 -> V_372 ) ;
error = F_259 ( V_14 , V_406 , V_539 ) ;
if ( error == 0 ) {
V_14 -> V_546 = V_539 -> V_547 ;
F_335 ( V_14 , V_406 , V_539 -> V_548 ) ;
}
return error ;
}
static int F_336 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_549 * V_550 )
{
struct V_551 args = {
. V_234 = V_406 ,
. V_231 = V_14 -> V_15 ,
} ;
struct V_552 V_55 = {
. V_550 = V_550 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_553 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
if ( ( args . V_231 [ 0 ] & V_554 [ 0 ] ) == 0 ) {
memset ( V_550 , 0 , sizeof( * V_550 ) ) ;
return 0 ;
}
F_81 ( V_550 -> V_372 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
}
static int F_337 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_549 * V_550 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_336 ( V_14 , V_406 , V_550 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
int F_338 ( T_8 * V_240 ,
const struct V_283 * V_284 ,
const struct V_555 * V_556 ,
T_5 V_206 )
{
const struct V_381 * V_382 = NULL ;
if ( V_556 != NULL )
V_382 = & V_556 -> V_382 ;
return F_228 ( V_240 , V_284 -> V_66 , V_206 , V_382 ) ;
}
static bool F_339 ( T_8 * V_240 ,
const struct V_283 * V_284 ,
const struct V_555 * V_556 ,
T_5 V_206 )
{
T_8 V_557 ;
if ( F_338 ( & V_557 , V_284 , V_556 , V_206 ) == - V_36 )
return true ;
return F_134 ( V_240 , & V_557 ) ;
}
static bool F_340 ( int V_8 )
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
void F_341 ( struct V_558 * V_158 )
{
F_318 ( V_158 -> V_559 -> V_2 ) ;
}
static int F_342 ( struct V_117 * V_118 , struct V_558 * V_158 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_559 -> V_2 ) ;
F_343 ( V_158 , V_118 -> V_150 ) ;
if ( F_236 ( V_118 , V_14 , V_158 -> args . V_560 -> V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
F_341 ( V_158 ) ;
if ( V_118 -> V_150 > 0 )
F_37 ( V_14 , V_158 -> V_107 ) ;
return 0 ;
}
static bool F_344 ( struct V_117 * V_118 ,
struct V_561 * args )
{
if ( ! F_340 ( V_118 -> V_150 ) ||
F_339 ( & args -> V_240 ,
args -> V_560 ,
args -> V_562 ,
V_70 ) )
return false ;
F_57 ( V_118 ) ;
return true ;
}
static int F_345 ( struct V_117 * V_118 , struct V_558 * V_158 )
{
F_8 ( L_11 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return - V_131 ;
if ( F_344 ( V_118 , & V_158 -> args ) )
return - V_131 ;
return V_158 -> V_563 ? V_158 -> V_563 ( V_118 , V_158 ) :
F_342 ( V_118 , V_158 ) ;
}
static void F_346 ( struct V_558 * V_158 , struct V_162 * V_163 )
{
V_158 -> V_107 = V_155 ;
V_158 -> V_563 = F_342 ;
V_163 -> V_294 = & V_295 [ V_564 ] ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 0 ) ;
}
static int F_347 ( struct V_117 * V_118 , struct V_558 * V_158 )
{
if ( F_63 ( F_85 ( V_158 -> V_559 -> V_2 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) )
return 0 ;
if ( F_338 ( & V_158 -> args . V_240 , V_158 -> args . V_560 ,
V_158 -> args . V_562 , V_70 ) == - V_36 )
return - V_36 ;
if ( F_348 ( F_31 ( V_565 , & V_158 -> args . V_560 -> V_207 ) ) )
return - V_36 ;
return 0 ;
}
static int F_349 ( struct V_117 * V_118 , struct V_566 * V_158 )
{
struct V_2 * V_2 = V_158 -> V_559 -> V_2 ;
F_350 ( V_158 , V_118 -> V_150 ) ;
if ( F_236 ( V_118 , F_85 ( V_2 ) , V_158 -> args . V_560 -> V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
if ( V_118 -> V_150 >= 0 ) {
F_37 ( F_85 ( V_2 ) , V_158 -> V_107 ) ;
F_351 ( V_2 , & V_158 -> V_372 ) ;
}
return 0 ;
}
static bool F_352 ( struct V_117 * V_118 ,
struct V_567 * args )
{
if ( ! F_340 ( V_118 -> V_150 ) ||
F_339 ( & args -> V_240 ,
args -> V_560 ,
args -> V_562 ,
V_218 ) )
return false ;
F_57 ( V_118 ) ;
return true ;
}
static int F_353 ( struct V_117 * V_118 , struct V_566 * V_158 )
{
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return - V_131 ;
if ( F_352 ( V_118 , & V_158 -> args ) )
return - V_131 ;
return V_158 -> V_568 ? V_158 -> V_568 ( V_118 , V_158 ) :
F_349 ( V_118 , V_158 ) ;
}
static
bool F_354 ( const struct V_566 * V_158 )
{
const struct V_569 * V_570 = V_158 -> V_559 ;
if ( V_158 -> V_571 != NULL || V_570 -> V_572 != NULL )
return false ;
return F_20 ( V_570 -> V_2 , V_70 ) == 0 ;
}
static void F_355 ( struct V_566 * V_158 , struct V_162 * V_163 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_559 -> V_2 ) ;
if ( ! F_354 ( V_158 ) ) {
V_158 -> args . V_231 = NULL ;
V_158 -> V_55 . V_372 = NULL ;
} else
V_158 -> args . V_231 = V_14 -> V_402 ;
if ( ! V_158 -> V_568 )
V_158 -> V_568 = F_349 ;
V_158 -> V_55 . V_14 = V_14 ;
V_158 -> V_107 = V_155 ;
V_163 -> V_294 = & V_295 [ V_573 ] ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
}
static int F_356 ( struct V_117 * V_118 , struct V_566 * V_158 )
{
if ( F_63 ( F_85 ( V_158 -> V_559 -> V_2 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) )
return 0 ;
if ( F_338 ( & V_158 -> args . V_240 , V_158 -> args . V_560 ,
V_158 -> args . V_562 , V_218 ) == - V_36 )
return - V_36 ;
if ( F_348 ( F_31 ( V_565 , & V_158 -> args . V_560 -> V_207 ) ) )
return - V_36 ;
return 0 ;
}
static void F_357 ( struct V_117 * V_118 , struct V_574 * V_158 )
{
F_63 ( F_85 ( V_158 -> V_2 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_358 ( struct V_117 * V_118 , struct V_574 * V_158 )
{
struct V_2 * V_2 = V_158 -> V_2 ;
F_359 ( V_158 , V_118 -> V_150 ) ;
if ( F_236 ( V_118 , F_85 ( V_2 ) , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_360 ( struct V_117 * V_118 , struct V_574 * V_158 )
{
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return - V_131 ;
return V_158 -> V_575 ( V_118 , V_158 ) ;
}
static void F_361 ( struct V_574 * V_158 , struct V_162 * V_163 )
{
struct V_13 * V_14 = F_85 ( V_158 -> V_2 ) ;
if ( V_158 -> V_575 == NULL )
V_158 -> V_575 = F_358 ;
V_158 -> V_55 . V_14 = V_14 ;
V_163 -> V_294 = & V_295 [ V_576 ] ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
}
static void F_362 ( void * V_156 )
{
struct V_577 * V_158 = V_156 ;
struct V_63 * V_64 = V_158 -> V_92 ;
if ( F_363 ( & V_64 -> V_578 ) > 1 )
F_364 ( V_64 ) ;
F_365 ( V_64 ) ;
F_96 ( V_158 ) ;
}
static void F_366 ( struct V_117 * V_118 , void * V_156 )
{
struct V_577 * V_158 = V_156 ;
struct V_63 * V_64 = V_158 -> V_92 ;
unsigned long V_107 = V_158 -> V_107 ;
F_367 ( V_64 , V_118 -> V_150 ) ;
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
F_368 ( V_64 ) ;
}
F_33 ( V_64 , V_107 ) ;
}
static int F_369 ( struct V_63 * V_64 , struct V_299 * V_333 , unsigned V_582 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_583 ] ,
. V_297 = V_64 ,
. V_299 = V_333 ,
} ;
struct V_577 * V_158 ;
if ( V_582 == 0 )
return 0 ;
if ( ! F_370 ( & V_64 -> V_578 ) )
return - V_36 ;
V_158 = F_265 ( sizeof( * V_158 ) , V_286 ) ;
if ( V_158 == NULL )
return - V_127 ;
V_158 -> V_92 = V_64 ;
V_158 -> V_107 = V_155 ;
return F_371 ( V_64 -> V_102 , & V_163 , V_584 ,
& V_585 , V_158 ) ;
}
static int F_372 ( struct V_63 * V_64 , struct V_299 * V_333 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_583 ] ,
. V_297 = V_64 ,
. V_299 = V_333 ,
} ;
unsigned long V_543 = V_155 ;
int V_289 ;
V_289 = F_373 ( V_64 -> V_102 , & V_163 , V_584 ) ;
if ( V_289 < 0 )
return V_289 ;
F_33 ( V_64 , V_543 ) ;
return 0 ;
}
static inline int F_374 ( struct V_13 * V_14 )
{
return V_14 -> V_95 & V_414 ;
}
static int F_375 ( const void * V_586 , T_9 V_587 ,
struct V_464 * * V_43 , unsigned int * V_50 )
{
struct V_464 * V_588 , * * V_589 ;
int V_590 = 0 ;
T_9 V_12 ;
V_589 = V_43 ;
do {
V_12 = F_376 ( T_9 , V_591 , V_587 ) ;
V_588 = F_264 ( V_363 ) ;
if ( V_588 == NULL )
goto V_592;
memcpy ( F_377 ( V_588 ) , V_586 , V_12 ) ;
V_586 += V_12 ;
V_587 -= V_12 ;
* V_43 ++ = V_588 ;
V_590 ++ ;
} while ( V_587 != 0 );
return V_590 ;
V_592:
for(; V_590 > 0 ; V_590 -- )
F_268 ( V_589 [ V_590 - 1 ] ) ;
return - V_127 ;
}
static void F_378 ( struct V_2 * V_2 , struct V_593 * V_594 )
{
struct V_173 * V_174 = F_75 ( V_2 ) ;
F_34 ( & V_2 -> V_175 ) ;
F_96 ( V_174 -> V_595 ) ;
V_174 -> V_595 = V_594 ;
F_36 ( & V_2 -> V_175 ) ;
}
static void F_379 ( struct V_2 * V_2 )
{
F_378 ( V_2 , NULL ) ;
}
static inline T_11 F_380 ( struct V_2 * V_2 , char * V_586 , T_9 V_587 )
{
struct V_173 * V_174 = F_75 ( V_2 ) ;
struct V_593 * V_594 ;
int V_67 = - V_285 ;
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
static void F_381 ( struct V_2 * V_2 , struct V_464 * * V_43 , T_9 V_50 , T_9 V_599 )
{
struct V_593 * V_594 ;
T_9 V_587 = sizeof( * V_594 ) + V_599 ;
if ( V_587 <= V_591 ) {
V_594 = F_265 ( V_587 , V_363 ) ;
if ( V_594 == NULL )
goto V_132;
V_594 -> V_597 = 1 ;
F_382 ( V_594 -> V_158 , V_43 , V_50 , V_599 ) ;
} else {
V_594 = F_265 ( sizeof( * V_594 ) , V_363 ) ;
if ( V_594 == NULL )
goto V_132;
V_594 -> V_597 = 0 ;
}
V_594 -> V_12 = V_599 ;
V_132:
F_378 ( V_2 , V_594 ) ;
}
static T_11 F_383 ( struct V_2 * V_2 , void * V_586 , T_9 V_587 )
{
struct V_464 * V_43 [ V_600 ] = { NULL , } ;
struct V_601 args = {
. V_234 = F_93 ( V_2 ) ,
. V_602 = V_43 ,
. V_599 = V_587 ,
} ;
struct V_603 V_55 = {
. V_599 = V_587 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_604 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
unsigned int V_605 = F_384 ( V_587 , V_591 ) ;
int V_67 = - V_127 , V_453 ;
if ( V_605 == 0 )
V_605 = 1 ;
if ( V_605 > F_255 ( V_43 ) )
return - V_598 ;
for ( V_453 = 0 ; V_453 < V_605 ; V_453 ++ ) {
V_43 [ V_453 ] = F_264 ( V_363 ) ;
if ( ! V_43 [ V_453 ] )
goto V_293;
}
V_55 . V_606 = F_264 ( V_363 ) ;
if ( ! V_55 . V_606 )
goto V_293;
args . V_599 = V_605 * V_591 ;
args . V_607 = 0 ;
F_8 ( L_40 ,
V_35 , V_586 , V_587 , V_605 , args . V_599 ) ;
V_67 = F_73 ( F_85 ( V_2 ) -> V_92 , F_85 ( V_2 ) ,
& V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
if ( V_67 )
goto V_293;
if ( V_55 . V_608 & V_609 ) {
if ( V_586 == NULL )
goto V_610;
V_67 = - V_598 ;
goto V_293;
}
F_381 ( V_2 , V_43 , V_55 . V_611 , V_55 . V_599 ) ;
if ( V_586 ) {
if ( V_55 . V_599 > V_587 ) {
V_67 = - V_598 ;
goto V_293;
}
F_382 ( V_586 , V_43 , V_55 . V_611 , V_55 . V_599 ) ;
}
V_610:
V_67 = V_55 . V_599 ;
V_293:
for ( V_453 = 0 ; V_453 < V_605 ; V_453 ++ )
if ( V_43 [ V_453 ] )
F_268 ( V_43 [ V_453 ] ) ;
if ( V_55 . V_606 )
F_268 ( V_55 . V_606 ) ;
return V_67 ;
}
static T_11 F_385 ( struct V_2 * V_2 , void * V_586 , T_9 V_587 )
{
struct V_61 V_62 = { } ;
T_11 V_67 ;
do {
V_67 = F_383 ( V_2 , V_586 , V_587 ) ;
F_386 ( V_2 , V_67 ) ;
if ( V_67 >= 0 )
break;
V_67 = F_19 ( F_85 ( V_2 ) , V_67 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_67 ;
}
static T_11 F_387 ( struct V_2 * V_2 , void * V_586 , T_9 V_587 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
int V_67 ;
if ( ! F_374 ( V_14 ) )
return - V_612 ;
V_67 = F_388 ( V_14 , V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( F_75 ( V_2 ) -> V_176 & V_613 )
F_389 ( V_2 ) ;
V_67 = F_380 ( V_2 , V_586 , V_587 ) ;
if ( V_67 != - V_285 )
return V_67 ;
return F_385 ( V_2 , V_586 , V_587 ) ;
}
static int F_390 ( struct V_2 * V_2 , const void * V_586 , T_9 V_587 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_464 * V_43 [ V_600 ] ;
struct V_614 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_602 = V_43 ,
. V_599 = V_587 ,
} ;
struct V_615 V_55 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_616 ] ,
. V_297 = & V_375 ,
. V_298 = & V_55 ,
} ;
unsigned int V_605 = F_384 ( V_587 , V_591 ) ;
int V_67 , V_453 ;
if ( ! F_374 ( V_14 ) )
return - V_612 ;
if ( V_605 > F_255 ( V_43 ) )
return - V_598 ;
V_453 = F_375 ( V_586 , V_587 , V_375 . V_602 , & V_375 . V_607 ) ;
if ( V_453 < 0 )
return V_453 ;
F_21 ( V_2 ) ;
V_67 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_55 . V_161 , 1 ) ;
for (; V_453 > 0 ; V_453 -- )
F_391 ( V_43 [ V_453 - 1 ] ) ;
F_34 ( & V_2 -> V_175 ) ;
F_75 ( V_2 ) -> V_176 |= V_177 ;
F_36 ( & V_2 -> V_175 ) ;
F_392 ( V_2 ) ;
F_389 ( V_2 ) ;
return V_67 ;
}
static int F_393 ( struct V_2 * V_2 , const void * V_586 , T_9 V_587 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_390 ( V_2 , V_586 , V_587 ) ;
F_394 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_395 ( struct V_2 * V_2 , void * V_586 ,
T_9 V_587 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_371 V_372 ;
struct V_1 V_7 = { 0 , 0 , V_587 , V_586 } ;
T_1 V_231 [ 3 ] = { 0 , 0 , V_435 } ;
struct V_467 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_231 = V_231 ,
} ;
struct V_468 V_55 = {
. V_372 = & V_372 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_469 ] ,
. V_297 = & V_375 ,
. V_298 = & V_55 ,
} ;
int V_67 ;
F_81 ( & V_372 ) ;
V_67 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_55 . V_161 , 0 ) ;
if ( V_67 )
return V_67 ;
if ( ! ( V_372 . V_280 & V_617 ) )
return - V_285 ;
if ( V_587 < V_7 . V_12 )
return - V_598 ;
return 0 ;
}
static int F_396 ( struct V_2 * V_2 , void * V_586 ,
T_9 V_587 )
{
struct V_61 V_62 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_612 ;
do {
V_8 = F_395 ( V_2 , V_586 , V_587 ) ;
F_397 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_398 ( struct V_2 * V_2 ,
struct V_1 * V_373 ,
struct V_371 * V_372 ,
struct V_1 * V_362 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
const T_1 V_231 [ 3 ] = { 0 , 0 , V_435 } ;
struct V_374 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_376 = & V_6 ,
. V_14 = V_14 ,
. V_231 = V_231 ,
. V_7 = V_373 ,
} ;
struct V_377 V_55 = {
. V_372 = V_372 ,
. V_7 = V_362 ,
. V_14 = V_14 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_378 ] ,
. V_297 = & V_375 ,
. V_298 = & V_55 ,
} ;
int V_289 ;
F_123 ( & V_375 . V_240 , & V_388 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_55 . V_161 , 1 ) ;
if ( V_289 )
F_8 ( L_41 , V_35 , V_289 ) ;
return V_289 ;
}
static int F_399 ( struct V_2 * V_2 ,
struct V_1 * V_373 ,
struct V_371 * V_372 ,
struct V_1 * V_362 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_398 ( V_2 , V_373 ,
V_372 , V_362 ) ;
F_400 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_401 ( struct V_4 * V_4 , const void * V_586 , T_9 V_587 )
{
struct V_1 V_373 , * V_362 = NULL ;
struct V_371 V_372 ;
struct V_299 * V_333 ;
struct V_2 * V_2 = V_4 -> V_47 ;
int V_289 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_612 ;
F_81 ( & V_372 ) ;
V_373 . V_618 = 0 ;
V_373 . V_619 = 0 ;
V_373 . V_7 = ( char * ) V_586 ;
V_373 . V_12 = V_587 ;
V_333 = F_402 () ;
if ( F_43 ( V_333 ) )
return F_71 ( V_333 ) ;
V_362 = F_87 ( F_85 ( V_2 ) , V_363 ) ;
if ( F_43 ( V_362 ) ) {
V_289 = - F_71 ( V_362 ) ;
goto V_132;
}
V_289 = F_399 ( V_2 , & V_373 , & V_372 , V_362 ) ;
if ( V_289 == 0 )
F_220 ( V_2 , & V_372 , V_362 ) ;
F_95 ( V_362 ) ;
V_132:
F_201 ( V_333 ) ;
return V_289 ;
}
static int
F_236 ( struct V_117 * V_118 , const struct V_13 * V_14 , struct V_65 * V_66 )
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
F_403 ( V_14 , V_621 ) ;
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
F_404 ( & V_64 -> V_623 , V_118 ) ;
if ( F_31 ( V_99 , & V_14 -> V_100 ) )
goto V_620;
V_622:
V_118 -> V_150 = 0 ;
return - V_131 ;
}
static void F_405 ( const struct V_63 * V_64 ,
T_12 * V_626 )
{
T_3 V_237 [ 2 ] ;
if ( F_31 ( V_627 , & V_64 -> V_625 ) ) {
V_237 [ 0 ] = 0 ;
V_237 [ 1 ] = F_406 ( V_628 + 1 ) ;
} else {
struct V_629 * V_630 = F_407 ( V_64 -> V_631 , V_632 ) ;
V_237 [ 0 ] = F_406 ( V_630 -> V_633 . V_634 ) ;
V_237 [ 1 ] = F_406 ( V_630 -> V_633 . V_635 ) ;
}
memcpy ( V_626 -> V_158 , V_237 , sizeof( V_626 -> V_158 ) ) ;
}
static unsigned int
F_408 ( const struct V_63 * V_64 ,
char * V_586 , T_9 V_12 )
{
unsigned int V_636 ;
F_132 () ;
V_636 = F_409 ( V_586 , V_12 , L_43 ,
V_64 -> V_637 ,
F_410 ( V_64 -> V_102 ,
V_638 ) ,
F_410 ( V_64 -> V_102 ,
V_639 ) ) ;
F_135 () ;
return V_636 ;
}
static unsigned int
F_411 ( const struct V_63 * V_64 ,
char * V_586 , T_9 V_12 )
{
const char * V_640 = V_64 -> V_102 -> V_641 ;
if ( V_642 [ 0 ] != '\0' )
return F_409 ( V_586 , V_12 , L_44 ,
V_64 -> V_643 -> V_644 ,
V_64 -> V_410 ,
V_642 ,
V_640 ) ;
return F_409 ( V_586 , V_12 , L_45 ,
V_64 -> V_643 -> V_644 , V_64 -> V_410 ,
V_640 ) ;
}
static unsigned int
F_412 ( const struct V_63 * V_64 , char * V_586 , T_9 V_12 )
{
if ( strchr ( V_64 -> V_637 , ':' ) != NULL )
return F_409 ( V_586 , V_12 , L_46 ) ;
else
return F_409 ( V_586 , V_12 , L_47 ) ;
}
int F_413 ( struct V_63 * V_64 , T_1 V_645 ,
unsigned short V_646 , struct V_299 * V_333 ,
struct V_647 * V_55 )
{
T_12 V_648 ;
struct V_649 V_650 = {
. V_648 = & V_648 ,
. V_651 = V_645 ,
. V_652 = V_64 -> V_653 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_654 ] ,
. V_297 = & V_650 ,
. V_298 = V_55 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_405 ( V_64 , & V_648 ) ;
if ( F_31 ( V_655 , & V_64 -> V_656 ) )
V_650 . V_657 =
F_411 ( V_64 ,
V_650 . V_658 ,
sizeof( V_650 . V_658 ) ) ;
else
V_650 . V_657 =
F_408 ( V_64 ,
V_650 . V_658 ,
sizeof( V_650 . V_658 ) ) ;
V_650 . V_659 =
F_412 ( V_64 ,
V_650 . V_660 ,
sizeof( V_650 . V_660 ) ) ;
V_650 . V_661 = F_409 ( V_650 . V_662 ,
sizeof( V_650 . V_662 ) , L_48 ,
V_64 -> V_637 , V_646 >> 8 , V_646 & 255 ) ;
F_8 ( L_49 ,
V_64 -> V_102 -> V_103 -> V_663 -> V_664 ,
V_650 . V_657 , V_650 . V_658 ) ;
V_289 = F_373 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_414 ( V_64 , V_289 ) ;
F_8 ( L_50 , V_289 ) ;
return V_289 ;
}
int F_415 ( struct V_63 * V_64 ,
struct V_647 * V_375 ,
struct V_299 * V_333 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_665 ] ,
. V_297 = V_375 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_8 ( L_51 ,
V_64 -> V_102 -> V_103 -> V_663 -> V_664 ,
V_64 -> V_225 ) ;
V_289 = F_373 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_416 ( V_64 , V_289 ) ;
F_8 ( L_52 , V_289 ) ;
return V_289 ;
}
static void F_417 ( struct V_117 * V_118 , void * V_156 )
{
struct V_666 * V_158 = V_156 ;
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return;
F_418 ( & V_158 -> args , & V_158 -> V_55 , V_118 -> V_150 ) ;
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
if ( F_236 ( V_118 , V_158 -> V_55 . V_14 , NULL ) ==
- V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
V_158 -> V_277 = V_118 -> V_150 ;
}
static void F_419 ( void * V_156 )
{
F_96 ( V_156 ) ;
}
static void F_420 ( struct V_117 * V_118 , void * V_158 )
{
struct V_666 * V_667 ;
V_667 = (struct V_666 * ) V_158 ;
F_63 ( V_667 -> V_55 . V_14 ,
& V_667 -> args . V_160 ,
& V_667 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_421 ( struct V_2 * V_2 , struct V_299 * V_333 , const T_8 * V_240 , int V_668 )
{
struct V_666 * V_158 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_669 ] ,
. V_299 = V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_670 ,
. V_207 = V_304 ,
} ;
int V_289 = 0 ;
V_158 = F_86 ( sizeof( * V_158 ) , V_286 ) ;
if ( V_158 == NULL )
return - V_127 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
V_158 -> args . V_406 = & V_158 -> V_234 ;
V_158 -> args . V_240 = & V_158 -> V_240 ;
V_158 -> args . V_231 = V_14 -> V_402 ;
F_178 ( & V_158 -> V_234 , F_93 ( V_2 ) ) ;
F_123 ( & V_158 -> V_240 , V_240 ) ;
V_158 -> V_55 . V_372 = & V_158 -> V_372 ;
V_158 -> V_55 . V_14 = V_14 ;
F_81 ( V_158 -> V_55 . V_372 ) ;
V_158 -> V_107 = V_155 ;
V_158 -> V_277 = 0 ;
V_300 . V_170 = V_158 ;
V_163 . V_297 = & V_158 -> args ;
V_163 . V_298 = & V_158 -> V_55 ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
if ( ! V_668 )
goto V_132;
V_289 = F_107 ( V_118 ) ;
if ( V_289 != 0 )
goto V_132;
V_289 = V_158 -> V_277 ;
if ( V_289 == 0 )
F_351 ( V_2 , & V_158 -> V_372 ) ;
else
F_145 ( V_2 , & V_158 -> V_372 ) ;
V_132:
F_72 ( V_118 ) ;
return V_289 ;
}
int F_422 ( struct V_2 * V_2 , struct V_299 * V_333 , const T_8 * V_240 , int V_668 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_421 ( V_2 , V_333 , V_240 , V_668 ) ;
F_423 ( V_2 , V_8 ) ;
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
F_424 ( unsigned long V_54 )
{
F_17 ( V_54 ) ;
V_54 <<= 1 ;
if ( V_54 > V_671 )
return V_671 ;
return V_54 ;
}
static int F_425 ( struct V_65 * V_66 , int V_672 , struct V_673 * V_674 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_675 V_375 = {
. V_234 = F_93 ( V_2 ) ,
. V_676 = V_674 ,
} ;
struct V_677 V_55 = {
. V_678 = V_674 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_679 ] ,
. V_297 = & V_375 ,
. V_298 = & V_55 ,
. V_299 = V_66 -> V_215 -> V_274 ,
} ;
struct V_680 * V_681 ;
int V_289 ;
V_375 . V_682 . V_224 = V_64 -> V_225 ;
V_289 = F_426 ( V_66 , V_674 ) ;
if ( V_289 != 0 )
goto V_132;
V_681 = V_674 -> V_683 . V_684 . V_215 ;
V_375 . V_682 . V_226 = V_681 -> V_685 . V_229 ;
V_375 . V_682 . V_686 = V_14 -> V_686 ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & V_375 . V_160 , & V_55 . V_161 , 1 ) ;
switch ( V_289 ) {
case 0 :
V_674 -> V_687 = V_688 ;
break;
case - V_291 :
V_289 = 0 ;
}
V_674 -> V_689 -> V_690 ( V_674 ) ;
V_674 -> V_689 = NULL ;
V_132:
return V_289 ;
}
static int F_427 ( struct V_65 * V_66 , int V_672 , struct V_673 * V_674 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_425 ( V_66 , V_672 , V_674 ) ;
F_428 ( V_674 , V_66 , V_672 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_66 -> V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_429 ( struct V_691 * V_691 , struct V_673 * V_676 )
{
int V_55 = 0 ;
switch ( V_676 -> V_692 & ( V_693 | V_694 ) ) {
case V_693 :
V_55 = F_430 ( V_691 , V_676 ) ;
break;
case V_694 :
V_55 = F_431 ( V_691 , V_676 ) ;
break;
default:
F_432 () ;
}
return V_55 ;
}
static struct V_695 * F_433 ( struct V_673 * V_676 ,
struct V_283 * V_284 ,
struct V_680 * V_681 ,
struct V_696 * V_196 )
{
struct V_695 * V_42 ;
struct V_2 * V_2 = V_681 -> V_697 -> V_2 ;
V_42 = F_86 ( sizeof( * V_42 ) , V_286 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_375 . V_234 = F_93 ( V_2 ) ;
V_42 -> V_375 . V_676 = & V_42 -> V_676 ;
V_42 -> V_375 . V_196 = V_196 ;
V_42 -> V_55 . V_196 = V_196 ;
V_42 -> V_375 . V_240 = & V_681 -> V_698 ;
V_42 -> V_681 = V_681 ;
F_91 ( & V_681 -> V_699 ) ;
V_42 -> V_284 = F_153 ( V_284 ) ;
memcpy ( & V_42 -> V_676 , V_676 , sizeof( V_42 -> V_676 ) ) ;
V_42 -> V_14 = F_85 ( V_2 ) ;
return V_42 ;
}
static void F_434 ( void * V_158 )
{
struct V_695 * V_156 = V_158 ;
F_100 ( V_156 -> V_375 . V_196 ) ;
F_435 ( V_156 -> V_681 ) ;
F_164 ( V_156 -> V_284 ) ;
F_96 ( V_156 ) ;
}
static void F_436 ( struct V_117 * V_118 , void * V_158 )
{
struct V_695 * V_156 = V_158 ;
if ( ! F_60 ( V_118 , & V_156 -> V_55 . V_161 ) )
return;
switch ( V_118 -> V_150 ) {
case 0 :
F_123 ( & V_156 -> V_681 -> V_698 ,
& V_156 -> V_55 . V_240 ) ;
F_37 ( V_156 -> V_14 , V_156 -> V_107 ) ;
break;
case - V_74 :
case - V_94 :
case - V_76 :
case - V_75 :
break;
default:
if ( F_236 ( V_118 , V_156 -> V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
F_138 ( V_156 -> V_375 . V_196 ) ;
}
static void F_437 ( struct V_117 * V_118 , void * V_158 )
{
struct V_695 * V_156 = V_158 ;
if ( F_177 ( V_156 -> V_375 . V_196 , V_118 ) != 0 )
goto V_305;
if ( F_31 ( V_700 , & V_156 -> V_681 -> V_701 ) == 0 ) {
goto V_306;
}
V_156 -> V_107 = V_155 ;
if ( F_63 ( V_156 -> V_14 ,
& V_156 -> V_375 . V_160 ,
& V_156 -> V_55 . V_161 ,
V_118 ) != 0 )
F_138 ( V_156 -> V_375 . V_196 ) ;
return;
V_306:
V_118 -> V_317 = NULL ;
V_305:
F_60 ( V_118 , & V_156 -> V_55 . V_161 ) ;
}
static struct V_117 * F_438 ( struct V_673 * V_676 ,
struct V_283 * V_284 ,
struct V_680 * V_681 ,
struct V_696 * V_196 )
{
struct V_695 * V_158 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_702 ] ,
. V_299 = V_284 -> V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = F_281 ( V_681 -> V_697 -> V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_703 ,
. V_302 = V_303 ,
. V_207 = V_304 ,
} ;
F_240 ( F_85 ( V_681 -> V_697 -> V_2 ) -> V_63 ,
V_400 , & V_300 . V_166 , & V_163 ) ;
V_676 -> V_687 = V_688 ;
V_158 = F_433 ( V_676 , V_284 , V_681 , V_196 ) ;
if ( V_158 == NULL ) {
F_100 ( V_196 ) ;
return F_44 ( - V_127 ) ;
}
F_38 ( & V_158 -> V_375 . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
V_163 . V_297 = & V_158 -> V_375 ;
V_163 . V_298 = & V_158 -> V_55 ;
V_300 . V_170 = V_158 ;
return F_70 ( & V_300 ) ;
}
static int F_439 ( struct V_65 * V_66 , int V_672 , struct V_673 * V_674 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_204 * V_205 = V_66 -> V_215 ;
struct V_173 * V_174 = F_75 ( V_2 ) ;
struct V_696 * V_196 ;
struct V_680 * V_681 ;
struct V_117 * V_118 ;
int V_289 = 0 ;
unsigned char V_692 = V_674 -> V_692 ;
V_289 = F_426 ( V_66 , V_674 ) ;
V_674 -> V_692 |= V_704 ;
F_440 ( & V_205 -> V_705 ) ;
F_441 ( & V_174 -> V_706 ) ;
if ( F_429 ( V_674 -> V_707 , V_674 ) == - V_285 ) {
F_442 ( & V_174 -> V_706 ) ;
F_443 ( & V_205 -> V_705 ) ;
goto V_132;
}
F_442 ( & V_174 -> V_706 ) ;
F_443 ( & V_205 -> V_705 ) ;
if ( V_289 != 0 )
goto V_132;
V_681 = V_674 -> V_683 . V_684 . V_215 ;
if ( F_31 ( V_700 , & V_681 -> V_701 ) == 0 )
goto V_132;
V_196 = F_88 ( & V_681 -> V_685 , V_363 ) ;
V_289 = - V_127 ;
if ( V_196 == NULL )
goto V_132;
V_118 = F_438 ( V_674 , F_273 ( V_674 -> V_707 ) , V_681 , V_196 ) ;
V_289 = F_71 ( V_118 ) ;
if ( F_43 ( V_118 ) )
goto V_132;
V_289 = F_107 ( V_118 ) ;
F_72 ( V_118 ) ;
V_132:
V_674 -> V_692 = V_692 ;
F_444 ( V_674 , V_66 , V_708 , V_289 ) ;
return V_289 ;
}
static struct V_709 * F_445 ( struct V_673 * V_676 ,
struct V_283 * V_284 , struct V_680 * V_681 ,
T_6 V_209 )
{
struct V_709 * V_42 ;
struct V_2 * V_2 = V_681 -> V_697 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
V_42 = F_86 ( sizeof( * V_42 ) , V_209 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_375 . V_234 = F_93 ( V_2 ) ;
V_42 -> V_375 . V_676 = & V_42 -> V_676 ;
V_42 -> V_375 . V_710 = F_88 ( & V_681 -> V_697 -> V_215 -> V_212 , V_209 ) ;
if ( V_42 -> V_375 . V_710 == NULL )
goto V_293;
V_42 -> V_375 . V_711 = F_88 ( & V_681 -> V_685 , V_209 ) ;
if ( V_42 -> V_375 . V_711 == NULL )
goto V_712;
V_42 -> V_375 . V_713 = & V_681 -> V_698 ;
V_42 -> V_375 . V_682 . V_224 = V_14 -> V_63 -> V_225 ;
V_42 -> V_375 . V_682 . V_226 = V_681 -> V_685 . V_229 ;
V_42 -> V_375 . V_682 . V_686 = V_14 -> V_686 ;
V_42 -> V_55 . V_711 = V_42 -> V_375 . V_711 ;
V_42 -> V_681 = V_681 ;
V_42 -> V_14 = V_14 ;
F_91 ( & V_681 -> V_699 ) ;
V_42 -> V_284 = F_153 ( V_284 ) ;
memcpy ( & V_42 -> V_676 , V_676 , sizeof( V_42 -> V_676 ) ) ;
return V_42 ;
V_712:
F_100 ( V_42 -> V_375 . V_710 ) ;
V_293:
F_96 ( V_42 ) ;
return NULL ;
}
static void F_446 ( struct V_117 * V_118 , void * V_156 )
{
struct V_709 * V_158 = V_156 ;
struct V_65 * V_66 = V_158 -> V_681 -> V_697 ;
F_8 ( L_29 , V_35 ) ;
if ( F_177 ( V_158 -> V_375 . V_711 , V_118 ) != 0 )
goto V_305;
if ( ! ( V_158 -> V_375 . V_711 -> V_714 -> V_207 & V_715 ) ) {
if ( F_177 ( V_158 -> V_375 . V_710 , V_118 ) != 0 ) {
goto V_716;
}
V_158 -> V_375 . V_261 = & V_66 -> V_261 ;
V_158 -> V_375 . V_717 = 1 ;
V_158 -> V_55 . V_710 = V_158 -> V_375 . V_710 ;
} else
V_158 -> V_375 . V_717 = 0 ;
if ( ! F_227 ( V_66 ) ) {
V_158 -> V_277 = - V_387 ;
V_118 -> V_317 = NULL ;
goto V_718;
}
V_158 -> V_107 = V_155 ;
if ( F_63 ( V_158 -> V_14 ,
& V_158 -> V_375 . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) == 0 )
return;
V_718:
F_138 ( V_158 -> V_375 . V_710 ) ;
V_716:
F_138 ( V_158 -> V_375 . V_711 ) ;
V_305:
F_60 ( V_118 , & V_158 -> V_55 . V_161 ) ;
F_8 ( L_53 , V_35 , V_158 -> V_277 ) ;
}
static void F_447 ( struct V_117 * V_118 , void * V_156 )
{
struct V_709 * V_158 = V_156 ;
F_8 ( L_29 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_158 -> V_55 . V_161 ) )
return;
V_158 -> V_277 = V_118 -> V_150 ;
if ( V_158 -> V_375 . V_717 != 0 ) {
if ( V_158 -> V_277 == 0 )
F_171 ( & V_158 -> V_681 -> V_685 , 0 ) ;
else
goto V_132;
}
if ( V_158 -> V_277 == 0 ) {
F_123 ( & V_158 -> V_681 -> V_698 , & V_158 -> V_55 . V_240 ) ;
F_129 ( V_700 , & V_158 -> V_681 -> V_701 ) ;
F_37 ( F_85 ( V_158 -> V_284 -> V_4 -> V_47 ) , V_158 -> V_107 ) ;
}
V_132:
F_8 ( L_30 , V_35 , V_158 -> V_277 ) ;
}
static void F_448 ( void * V_156 )
{
struct V_709 * V_158 = V_156 ;
F_8 ( L_29 , V_35 ) ;
F_100 ( V_158 -> V_375 . V_710 ) ;
if ( V_158 -> V_292 != 0 ) {
struct V_117 * V_118 ;
V_118 = F_438 ( & V_158 -> V_676 , V_158 -> V_284 , V_158 -> V_681 ,
V_158 -> V_375 . V_711 ) ;
if ( ! F_43 ( V_118 ) )
F_449 ( V_118 ) ;
F_8 ( L_54 , V_35 ) ;
} else
F_100 ( V_158 -> V_375 . V_711 ) ;
F_435 ( V_158 -> V_681 ) ;
F_164 ( V_158 -> V_284 ) ;
F_96 ( V_158 ) ;
F_8 ( L_31 , V_35 ) ;
}
static void F_450 ( struct V_13 * V_14 , struct V_680 * V_681 , int V_717 , int error )
{
switch ( error ) {
case - V_73 :
case - V_74 :
V_681 -> V_685 . V_207 &= ~ V_715 ;
if ( V_717 != 0 ||
F_31 ( V_700 , & V_681 -> V_701 ) != 0 )
F_22 ( V_14 , V_681 -> V_697 ) ;
break;
case - V_76 :
V_681 -> V_685 . V_207 &= ~ V_715 ;
case - V_75 :
F_24 ( V_14 -> V_63 ) ;
} ;
}
static int F_451 ( struct V_65 * V_66 , int V_672 , struct V_673 * V_676 , int V_719 )
{
struct V_709 * V_158 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_720 ] ,
. V_299 = V_66 -> V_215 -> V_274 ,
} ;
struct V_164 V_300 = {
. V_166 = F_281 ( V_66 -> V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_721 ,
. V_302 = V_303 ,
. V_207 = V_304 ,
} ;
int V_67 ;
F_8 ( L_29 , V_35 ) ;
V_158 = F_445 ( V_676 , F_273 ( V_676 -> V_707 ) ,
V_676 -> V_683 . V_684 . V_215 ,
V_719 == V_722 ? V_363 : V_286 ) ;
if ( V_158 == NULL )
return - V_127 ;
if ( F_452 ( V_672 ) )
V_158 -> V_375 . V_723 = 1 ;
F_38 ( & V_158 -> V_375 . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
V_163 . V_297 = & V_158 -> V_375 ;
V_163 . V_298 = & V_158 -> V_55 ;
V_300 . V_170 = V_158 ;
if ( V_719 > V_722 ) {
if ( V_719 == V_724 )
V_158 -> V_375 . V_725 = V_724 ;
F_39 ( & V_158 -> V_375 . V_160 ) ;
}
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_67 = F_107 ( V_118 ) ;
if ( V_67 == 0 ) {
V_67 = V_158 -> V_277 ;
if ( V_67 )
F_450 ( V_158 -> V_14 , V_158 -> V_681 ,
V_158 -> V_375 . V_717 , V_67 ) ;
} else
V_158 -> V_292 = 1 ;
F_72 ( V_118 ) ;
F_8 ( L_30 , V_35 , V_67 ) ;
return V_67 ;
}
static int F_453 ( struct V_65 * V_66 , struct V_673 * V_674 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_31 ( V_262 , & V_66 -> V_207 ) != 0 )
return 0 ;
V_8 = F_451 ( V_66 , V_708 , V_674 , V_724 ) ;
F_454 ( V_674 , V_66 , V_708 , V_8 ) ;
if ( V_8 != - V_91 )
break;
F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_455 ( struct V_65 * V_66 , struct V_673 * V_674 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
V_8 = F_426 ( V_66 , V_674 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_726 ) {
F_129 ( V_727 , & V_674 -> V_683 . V_684 . V_215 -> V_701 ) ;
return 0 ;
}
do {
if ( F_31 ( V_262 , & V_66 -> V_207 ) != 0 )
return 0 ;
V_8 = F_451 ( V_66 , V_708 , V_674 , V_728 ) ;
F_456 ( V_674 , V_66 , V_708 , V_8 ) ;
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
static int F_457 ( struct V_65 * V_66 )
{
int V_289 , V_67 = - V_74 ;
struct V_680 * V_681 ;
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
F_152 (lsp, &state->lock_states, ls_locks) {
if ( F_31 ( V_700 , & V_681 -> V_701 ) ) {
struct V_299 * V_333 = V_681 -> V_697 -> V_215 -> V_274 ;
V_289 = F_198 ( V_14 ,
& V_681 -> V_698 ,
V_333 ) ;
F_458 ( V_66 , V_681 , V_289 ) ;
if ( V_289 != V_347 ) {
if ( V_289 != - V_74 )
F_200 ( V_14 ,
& V_681 -> V_698 ,
V_333 ) ;
F_122 ( V_700 , & V_681 -> V_701 ) ;
V_67 = V_289 ;
}
}
} ;
return V_67 ;
}
static int F_459 ( struct V_65 * V_66 , struct V_673 * V_674 )
{
int V_289 = V_347 ;
if ( F_31 ( V_729 , & V_66 -> V_207 ) )
V_289 = F_457 ( V_66 ) ;
if ( V_289 != V_347 )
V_289 = F_455 ( V_66 , V_674 ) ;
return V_289 ;
}
static int F_460 ( struct V_65 * V_66 , int V_672 , struct V_673 * V_674 )
{
struct V_204 * V_205 = V_66 -> V_215 ;
struct V_173 * V_174 = F_75 ( V_66 -> V_2 ) ;
unsigned char V_692 = V_674 -> V_692 ;
unsigned int V_355 ;
int V_289 = - V_730 ;
if ( ( V_692 & V_693 ) &&
! F_31 ( V_357 , & V_66 -> V_207 ) )
goto V_132;
V_289 = F_426 ( V_66 , V_674 ) ;
if ( V_289 != 0 )
goto V_132;
V_674 -> V_692 |= V_731 ;
V_289 = F_429 ( V_674 -> V_707 , V_674 ) ;
if ( V_289 < 0 )
goto V_132;
F_441 ( & V_174 -> V_706 ) ;
if ( F_31 ( V_262 , & V_66 -> V_207 ) ) {
V_674 -> V_692 = V_692 & ~ V_732 ;
V_289 = F_429 ( V_674 -> V_707 , V_674 ) ;
goto V_139;
}
V_355 = F_207 ( & V_205 -> V_356 ) ;
F_442 ( & V_174 -> V_706 ) ;
V_289 = F_451 ( V_66 , V_672 , V_674 , V_722 ) ;
if ( V_289 != 0 )
goto V_132;
F_441 ( & V_174 -> V_706 ) ;
if ( F_213 ( & V_205 -> V_356 , V_355 ) ) {
V_289 = - V_91 ;
goto V_139;
}
V_674 -> V_692 = V_692 | V_732 ;
if ( F_429 ( V_674 -> V_707 , V_674 ) < 0 )
F_29 ( V_97 L_55
L_56 , V_35 ) ;
V_139:
F_442 ( & V_174 -> V_706 ) ;
V_132:
V_674 -> V_692 = V_692 ;
return V_289 ;
}
static int F_461 ( struct V_65 * V_66 , int V_672 , struct V_673 * V_674 )
{
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_460 ( V_66 , V_672 , V_674 ) ;
F_462 ( V_674 , V_66 , V_672 , V_8 ) ;
if ( V_8 == - V_291 )
V_8 = - V_131 ;
V_8 = F_19 ( F_85 ( V_66 -> V_2 ) ,
V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_463 ( struct V_691 * V_733 , int V_672 , struct V_673 * V_674 )
{
struct V_283 * V_284 ;
struct V_65 * V_66 ;
unsigned long V_54 = V_734 ;
int V_289 ;
V_284 = F_273 ( V_733 ) ;
V_66 = V_284 -> V_66 ;
if ( V_674 -> V_735 < 0 || V_674 -> V_736 < 0 )
return - V_27 ;
if ( F_464 ( V_672 ) ) {
if ( V_66 != NULL )
return F_427 ( V_66 , V_737 , V_674 ) ;
return 0 ;
}
if ( ! ( F_465 ( V_672 ) || F_452 ( V_672 ) ) )
return - V_27 ;
if ( V_674 -> V_687 == V_688 ) {
if ( V_66 != NULL )
return F_439 ( V_66 , V_672 , V_674 ) ;
return 0 ;
}
if ( V_66 == NULL )
return - V_730 ;
switch ( V_674 -> V_687 ) {
case V_738 :
if ( ! ( V_733 -> V_739 & V_70 ) )
return - V_387 ;
break;
case V_740 :
if ( ! ( V_733 -> V_739 & V_218 ) )
return - V_387 ;
}
do {
V_289 = F_461 ( V_66 , V_672 , V_674 ) ;
if ( ( V_289 != - V_131 ) || F_465 ( V_672 ) )
break;
V_54 = F_424 ( V_54 ) ;
V_289 = - V_59 ;
if ( F_466 () )
break;
} while( V_289 < 0 );
return V_289 ;
}
int F_467 ( struct V_673 * V_676 , struct V_65 * V_66 , const T_8 * V_240 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
int V_8 ;
V_8 = F_426 ( V_66 , V_676 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_451 ( V_66 , V_708 , V_676 , V_722 ) ;
return F_165 ( V_14 , V_66 , V_240 , V_8 ) ;
}
static void F_468 ( struct V_117 * V_118 , void * V_156 )
{
struct V_741 * V_158 = V_156 ;
F_40 ( V_158 -> V_14 ,
& V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , V_118 ) ;
V_158 -> V_107 = V_155 ;
}
static void F_469 ( struct V_117 * V_118 , void * V_156 )
{
struct V_741 * V_158 = V_156 ;
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
if ( F_236 ( V_118 , V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
}
static void F_470 ( void * V_156 )
{
struct V_741 * V_158 = V_156 ;
F_471 ( V_158 -> V_14 , V_158 -> V_681 ) ;
F_96 ( V_156 ) ;
}
static int F_472 ( struct V_13 * V_14 , struct V_680 * V_681 )
{
struct V_741 * V_158 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_742 ] ,
} ;
if ( V_14 -> V_63 -> V_168 -> V_315 != 0 )
return - V_27 ;
V_158 = F_265 ( sizeof( * V_158 ) , V_286 ) ;
if ( ! V_158 )
return - V_127 ;
V_158 -> V_681 = V_681 ;
V_158 -> V_14 = V_14 ;
V_158 -> args . V_682 . V_224 = V_14 -> V_63 -> V_225 ;
V_158 -> args . V_682 . V_226 = V_681 -> V_685 . V_229 ;
V_158 -> args . V_682 . V_686 = V_14 -> V_686 ;
V_163 . V_297 = & V_158 -> args ;
V_163 . V_298 = & V_158 -> V_55 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 0 ) ;
F_371 ( V_14 -> V_92 , & V_163 , 0 , & V_743 , V_158 ) ;
return 0 ;
}
static int F_473 ( struct V_4 * V_4 , const char * V_744 ,
const void * V_586 , T_9 V_587 ,
int V_207 , int type )
{
if ( strcmp ( V_744 , L_57 ) != 0 )
return - V_27 ;
return F_393 ( V_4 -> V_47 , V_586 , V_587 ) ;
}
static int F_474 ( struct V_4 * V_4 , const char * V_744 ,
void * V_586 , T_9 V_587 , int type )
{
if ( strcmp ( V_744 , L_57 ) != 0 )
return - V_27 ;
return F_387 ( V_4 -> V_47 , V_586 , V_587 ) ;
}
static T_9 F_475 ( struct V_4 * V_4 , char * V_745 ,
T_9 V_746 , const char * V_230 ,
T_9 V_747 , int type )
{
T_9 V_12 = sizeof( V_748 ) ;
if ( ! F_374 ( F_85 ( V_4 -> V_47 ) ) )
return 0 ;
if ( V_745 && V_12 <= V_746 )
memcpy ( V_745 , V_748 , V_12 ) ;
return V_12 ;
}
static inline int F_476 ( struct V_13 * V_14 )
{
return V_14 -> V_95 & V_9 ;
}
static int F_477 ( struct V_4 * V_4 , const char * V_744 ,
const void * V_586 , T_9 V_587 ,
int V_207 , int type )
{
if ( F_478 ( V_744 ) )
return F_401 ( V_4 , V_586 , V_587 ) ;
return - V_612 ;
}
static int F_479 ( struct V_4 * V_4 , const char * V_744 ,
void * V_586 , T_9 V_587 , int type )
{
if ( F_478 ( V_744 ) )
return F_396 ( V_4 -> V_47 , V_586 , V_587 ) ;
return - V_612 ;
}
static T_9 F_480 ( struct V_4 * V_4 , char * V_745 ,
T_9 V_746 , const char * V_230 ,
T_9 V_747 , int type )
{
T_9 V_12 = 0 ;
if ( F_2 ( V_4 -> V_47 , V_9 ) ) {
V_12 = F_481 ( V_4 -> V_47 , NULL , 0 ) ;
if ( V_745 && V_12 <= V_746 )
F_481 ( V_4 -> V_47 , V_745 , V_12 ) ;
}
return V_12 ;
}
static void F_267 ( struct V_371 * V_372 )
{
if ( ! ( ( ( V_372 -> V_280 & V_749 ) ||
( V_372 -> V_280 & V_750 ) ) &&
( V_372 -> V_280 & V_461 ) &&
( V_372 -> V_280 & V_751 ) ) )
return;
V_372 -> V_280 |= V_318 | V_476 |
V_477 | V_752 ;
V_372 -> V_245 = V_323 | V_479 | V_480 ;
V_372 -> V_481 = 2 ;
}
static int F_482 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_463 * V_230 ,
struct V_465 * V_753 ,
struct V_464 * V_464 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
T_1 V_231 [ 3 ] = {
[ 0 ] = V_754 | V_755 ,
} ;
struct V_756 args = {
. V_474 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
. V_464 = V_464 ,
. V_231 = V_231 ,
} ;
struct V_757 V_55 = {
. V_753 = V_753 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_758 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
int V_289 ;
F_8 ( L_58 , V_35 ) ;
if ( F_85 ( V_3 ) -> V_15 [ 1 ] & V_759 )
V_231 [ 1 ] |= V_759 ;
else
V_231 [ 0 ] |= V_46 ;
F_81 ( & V_753 -> V_372 ) ;
V_753 -> V_14 = V_14 ;
V_753 -> V_760 = 0 ;
V_289 = F_73 ( V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
F_8 ( L_59 , V_35 , V_289 ) ;
return V_289 ;
}
int F_266 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_463 * V_230 ,
struct V_465 * V_753 ,
struct V_464 * V_464 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_482 ( V_92 , V_3 , V_230 ,
V_753 , V_464 ) ;
F_483 ( V_3 , V_230 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_484 ( struct V_2 * V_2 ,
struct V_465 * V_466 ,
struct V_464 * V_464 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
T_1 V_231 [ 2 ] = {
[ 0 ] = V_754 | V_755 ,
} ;
struct V_756 args = {
. V_224 = V_14 -> V_63 -> V_225 ,
. V_234 = F_93 ( V_2 ) ,
. V_464 = V_464 ,
. V_231 = V_231 ,
. V_761 = 1 ,
. V_762 = 1 ,
} ;
struct V_757 V_55 = {
. V_753 = V_466 ,
. V_761 = 1 ,
. V_762 = 1 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_758 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
unsigned long V_543 = V_155 ;
int V_289 ;
F_81 ( & V_466 -> V_372 ) ;
V_466 -> V_14 = V_14 ;
V_466 -> V_760 = 0 ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_53 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
if ( V_289 )
return V_289 ;
F_37 ( V_14 , V_543 ) ;
return 0 ;
}
static int F_485 ( struct V_2 * V_2 ,
struct V_465 * V_466 ,
struct V_464 * V_464 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
T_1 V_231 [ 2 ] = {
[ 0 ] = V_754 | V_755 ,
} ;
struct V_756 args = {
. V_234 = F_93 ( V_2 ) ,
. V_464 = V_464 ,
. V_231 = V_231 ,
. V_761 = 1 ,
} ;
struct V_757 V_55 = {
. V_753 = V_466 ,
. V_761 = 1 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_758 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_81 ( & V_466 -> V_372 ) ;
V_466 -> V_14 = V_14 ;
V_466 -> V_760 = 0 ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_53 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
if ( V_289 == V_763 &&
V_55 . V_161 . V_146 & V_764 )
V_289 = - V_79 ;
return V_289 ;
}
int F_486 ( struct V_2 * V_2 ,
struct V_465 * V_466 ,
struct V_464 * V_464 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_765 * V_766 =
V_64 -> V_168 -> V_767 ;
struct V_61 V_62 = { } ;
int V_289 ;
F_8 ( L_60 , V_35 ,
( unsigned long long ) V_14 -> V_462 . V_768 ,
( unsigned long long ) V_14 -> V_462 . V_769 ,
V_64 -> V_98 ) ;
F_487 ( F_93 ( V_2 ) , V_35 ) ;
do {
V_289 = V_766 -> V_770 ( V_2 , V_466 , V_464 , V_333 ) ;
if ( V_289 != - V_91 )
break;
F_19 ( V_14 , V_289 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_289 ;
}
static int F_488 ( struct V_2 * V_2 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = F_85 ( V_2 ) -> V_63 ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_771 args = {
. V_234 = F_93 ( V_2 ) ,
. V_224 = V_64 -> V_225 ,
. V_762 = 1 ,
} ;
struct V_772 V_55 = {
. V_762 = 1 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_773 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
unsigned long V_543 = V_155 ;
int V_289 ;
V_55 . V_234 = F_489 () ;
if ( V_55 . V_234 == NULL )
return - V_127 ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_53 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
F_490 ( V_55 . V_234 ) ;
if ( V_289 )
return V_289 ;
F_33 ( V_64 , V_543 ) ;
return 0 ;
}
static int F_491 ( struct V_2 * V_2 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_771 args = {
. V_234 = F_93 ( V_2 ) ,
} ;
struct V_772 V_55 = {
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_773 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
int V_289 ;
V_55 . V_234 = F_489 () ;
if ( V_55 . V_234 == NULL )
return - V_127 ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_53 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
F_490 ( V_55 . V_234 ) ;
if ( V_289 == V_763 &&
V_55 . V_161 . V_146 & V_764 )
V_289 = - V_79 ;
return V_289 ;
}
int F_492 ( struct V_2 * V_2 , struct V_299 * V_333 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_765 * V_766 =
V_64 -> V_168 -> V_767 ;
struct V_61 V_62 = { } ;
int V_289 ;
F_8 ( L_60 , V_35 ,
( unsigned long long ) V_14 -> V_462 . V_768 ,
( unsigned long long ) V_14 -> V_462 . V_769 ,
V_64 -> V_98 ) ;
F_487 ( F_93 ( V_2 ) , V_35 ) ;
do {
V_289 = V_766 -> V_774 ( V_2 , V_333 ) ;
if ( V_289 != - V_91 )
break;
F_19 ( V_14 , V_289 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_289 ;
}
static int F_493 ( struct V_2 * V_3 , const struct V_463 * V_230 , struct V_775 * V_456 , bool V_776 )
{
int V_289 ;
struct V_777 args = {
. V_474 = F_93 ( V_3 ) ,
. V_230 = V_230 ,
} ;
struct V_778 V_55 = {
. V_456 = V_456 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_779 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
struct V_52 * V_53 = F_85 ( V_3 ) -> V_92 ;
struct V_299 * V_333 = NULL ;
if ( V_776 ) {
V_53 = F_85 ( V_3 ) -> V_63 -> V_102 ;
V_333 = F_494 ( F_85 ( V_3 ) -> V_63 ) ;
V_163 . V_299 = V_333 ;
}
F_8 ( L_61 , V_230 -> V_230 ) ;
F_240 ( F_85 ( V_3 ) -> V_63 ,
V_780 , & V_53 , & V_163 ) ;
V_289 = F_73 ( V_53 , F_85 ( V_3 ) , & V_163 , & args . V_160 ,
& V_55 . V_161 , 0 ) ;
F_8 ( L_62 , V_289 ) ;
if ( V_333 )
F_201 ( V_333 ) ;
return V_289 ;
}
int F_495 ( struct V_2 * V_3 , const struct V_463 * V_230 ,
struct V_775 * V_456 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( F_85 ( V_3 ) -> V_63 ) )
V_8 = F_493 ( V_3 , V_230 , V_456 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_493 ( V_3 , V_230 , V_456 , false ) ;
F_496 ( V_3 , V_230 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_497 ( T_1 V_207 )
{
if ( V_207 & ~ V_781 )
goto V_782;
if ( ( V_207 & V_783 ) &&
( V_207 & V_784 ) )
goto V_782;
if ( ! ( V_207 & ( V_785 ) ) )
goto V_782;
return V_347 ;
V_782:
return - V_786 ;
}
static bool
F_498 ( struct V_787 * V_788 ,
struct V_787 * V_789 )
{
if ( V_788 -> V_790 == V_789 -> V_790 &&
memcmp ( V_788 -> V_791 , V_789 -> V_791 , V_788 -> V_790 ) == 0 )
return true ;
return false ;
}
int F_499 ( struct V_63 * V_64 , struct V_299 * V_333 )
{
int V_289 ;
struct V_792 V_55 ;
struct V_162 V_163 = {
. V_294 =
& V_295 [ V_793 ] ,
. V_297 = V_64 ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
F_8 ( L_11 , V_35 ) ;
V_55 . V_135 = F_86 ( sizeof( struct V_134 ) , V_286 ) ;
if ( F_348 ( V_55 . V_135 == NULL ) ) {
V_289 = - V_127 ;
goto V_132;
}
V_289 = F_373 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_500 ( V_64 , V_289 ) ;
if ( V_289 == 0 ) {
if ( memcmp ( V_55 . V_135 -> V_794 . V_158 ,
V_64 -> V_88 -> V_794 . V_158 , V_795 ) ) {
F_8 ( L_63 , V_35 ) ;
V_289 = - V_36 ;
goto V_796;
}
if ( V_55 . V_3 != V_797 ) {
F_8 ( L_64 ,
V_35 ) ;
V_289 = - V_36 ;
goto V_796;
}
if ( V_55 . V_798 ) {
F_8 ( L_65 ,
V_35 ) ;
V_289 = - V_36 ;
goto V_796;
}
}
V_796:
F_96 ( V_55 . V_135 ) ;
V_132:
F_8 ( L_66 , V_35 , V_289 ) ;
return V_289 ;
}
static int F_501 ( struct V_63 * V_64 ,
struct V_799 * V_205 )
{
static const T_1 V_800 [ V_801 ] = {
[ 1 ] = 1 << ( V_802 - 32 ) |
1 << ( V_803 - 32 ) |
1 << ( V_804 - 32 ) |
1 << ( V_805 - 32 ) |
1 << ( V_806 - 32 )
} ;
unsigned int V_453 ;
if ( V_205 -> V_807 == V_808 ) {
F_502 ( V_809 , L_67 ) ;
for ( V_453 = 0 ; V_453 <= V_810 ; V_453 ++ ) {
if ( F_31 ( V_453 , V_205 -> V_811 . V_238 . V_812 ) )
F_502 ( V_809 , L_68 , V_453 ) ;
if ( F_31 ( V_453 , V_205 -> V_813 . V_238 . V_812 ) )
F_502 ( V_809 , L_69 , V_453 ) ;
}
for ( V_453 = 0 ; V_453 < V_801 ; V_453 ++ ) {
if ( V_205 -> V_811 . V_238 . V_814 [ V_453 ] & ~ V_800 [ V_453 ] ) {
F_502 ( V_809 , L_70 ) ;
return - V_27 ;
}
}
if ( F_31 ( V_802 , V_205 -> V_811 . V_238 . V_812 ) &&
F_31 ( V_804 , V_205 -> V_811 . V_238 . V_812 ) &&
F_31 ( V_805 , V_205 -> V_811 . V_238 . V_812 ) &&
F_31 ( V_806 , V_205 -> V_811 . V_238 . V_812 ) ) {
F_502 ( V_809 , L_71 ) ;
F_502 ( V_809 , L_72 ) ;
F_129 ( V_815 , & V_64 -> V_816 ) ;
} else {
F_502 ( V_809 , L_70 ) ;
return - V_27 ;
}
if ( F_31 ( V_817 , V_205 -> V_813 . V_238 . V_812 ) &&
F_31 ( V_818 , V_205 -> V_813 . V_238 . V_812 ) ) {
F_502 ( V_809 , L_73 ) ;
F_129 ( V_400 , & V_64 -> V_816 ) ;
}
if ( F_31 ( V_819 , V_205 -> V_813 . V_238 . V_812 ) &&
F_31 ( V_820 , V_205 -> V_813 . V_238 . V_812 ) ) {
F_502 ( V_809 , L_74 ) ;
F_129 ( V_780 , & V_64 -> V_816 ) ;
}
if ( F_31 ( V_821 , V_205 -> V_813 . V_238 . V_812 ) &&
F_31 ( V_822 , V_205 -> V_813 . V_238 . V_812 ) ) {
F_502 ( V_809 , L_75 ) ;
F_129 ( V_823 , & V_64 -> V_816 ) ;
}
if ( F_31 ( V_824 , V_205 -> V_813 . V_238 . V_812 ) ) {
F_502 ( V_809 , L_76 ) ;
F_129 ( V_825 , & V_64 -> V_816 ) ;
}
if ( F_31 ( V_826 , V_205 -> V_813 . V_238 . V_812 ) ) {
F_502 ( V_809 , L_77 ) ;
F_129 ( V_827 , & V_64 -> V_816 ) ;
}
}
return 0 ;
}
static int F_503 ( struct V_63 * V_64 , struct V_299 * V_333 ,
T_1 V_828 )
{
T_12 V_38 ;
struct V_829 args = {
. V_38 = & V_38 ,
. V_92 = V_64 ,
#ifdef F_504
. V_207 = V_830 |
V_831 |
V_832 ,
#else
. V_207 = V_830 |
V_831 ,
#endif
} ;
struct V_833 V_55 = {
0
} ;
int V_289 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_834 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
F_405 ( V_64 , & V_38 ) ;
args . V_835 = F_411 ( V_64 , args . V_226 ,
sizeof( args . V_226 ) ) ;
F_8 ( L_78 ,
V_64 -> V_102 -> V_103 -> V_663 -> V_664 ,
args . V_835 , args . V_226 ) ;
V_55 . V_836 = F_86 ( sizeof( struct V_837 ) ,
V_286 ) ;
if ( F_348 ( V_55 . V_836 == NULL ) ) {
V_289 = - V_127 ;
goto V_132;
}
V_55 . V_791 = F_86 ( sizeof( struct V_787 ) ,
V_286 ) ;
if ( F_348 ( V_55 . V_791 == NULL ) ) {
V_289 = - V_127 ;
goto V_838;
}
V_55 . V_839 = F_86 ( sizeof( struct V_840 ) , V_286 ) ;
if ( F_348 ( V_55 . V_839 == NULL ) ) {
V_289 = - V_127 ;
goto V_841;
}
switch ( V_828 ) {
case V_842 :
args . V_843 . V_807 = V_842 ;
break;
case V_808 :
args . V_843 = V_844 ;
break;
default:
F_505 ( 1 ) ;
V_289 = - V_27 ;
goto V_841;
}
V_289 = F_373 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_506 ( V_64 , V_289 ) ;
if ( V_289 == 0 )
V_289 = F_497 ( V_55 . V_207 ) ;
if ( V_289 == 0 )
V_289 = F_501 ( V_64 , & V_55 . V_843 ) ;
if ( V_289 == 0 ) {
V_64 -> V_225 = V_55 . V_224 ;
V_64 -> V_845 = ( V_55 . V_207 & ~ V_846 ) ;
if ( ! ( V_55 . V_207 & V_846 ) )
V_64 -> V_847 = V_55 . V_196 ;
F_96 ( V_64 -> V_848 ) ;
V_64 -> V_848 = V_55 . V_836 ;
V_55 . V_836 = NULL ;
F_96 ( V_64 -> V_849 ) ;
V_64 -> V_849 = V_55 . V_839 ;
if ( V_64 -> V_850 != NULL &&
! F_498 ( V_64 -> V_850 ,
V_55 . V_791 ) ) {
F_8 ( L_79 ,
V_35 ) ;
F_129 ( V_851 , & V_64 -> V_625 ) ;
F_96 ( V_64 -> V_850 ) ;
V_64 -> V_850 = NULL ;
}
if ( V_64 -> V_850 == NULL ) {
V_64 -> V_850 = V_55 . V_791 ;
goto V_132;
}
} else
F_96 ( V_55 . V_839 ) ;
V_838:
F_96 ( V_55 . V_836 ) ;
V_841:
F_96 ( V_55 . V_791 ) ;
V_132:
if ( V_64 -> V_849 != NULL )
F_8 ( L_80
L_81 ,
V_64 -> V_849 -> V_852 , V_64 -> V_849 -> V_230 ,
V_64 -> V_849 -> V_853 . V_854 ,
V_64 -> V_849 -> V_853 . V_855 ) ;
F_8 ( L_82 , V_289 ) ;
return V_289 ;
}
int F_507 ( struct V_63 * V_64 , struct V_299 * V_333 )
{
T_4 V_856 = V_64 -> V_102 -> V_103 -> V_104 ;
int V_289 ;
if ( V_856 == V_105 ||
V_856 == V_106 ) {
V_289 = F_503 ( V_64 , V_333 , V_808 ) ;
if ( ! V_289 )
return 0 ;
}
return F_503 ( V_64 , V_333 , V_842 ) ;
}
static int F_508 ( struct V_63 * V_64 ,
struct V_299 * V_333 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_857 ] ,
. V_297 = V_64 ,
. V_299 = V_333 ,
} ;
int V_289 ;
V_289 = F_373 ( V_64 -> V_102 , & V_163 , V_584 ) ;
F_509 ( V_64 , V_289 ) ;
if ( V_289 )
F_8 ( L_83
L_84 , V_289 , V_64 -> V_98 ) ;
return V_289 ;
}
static int F_510 ( struct V_63 * V_64 ,
struct V_299 * V_333 )
{
unsigned int V_858 ;
int V_67 ;
for ( V_858 = V_859 ; V_858 != 0 ; V_858 -- ) {
V_67 = F_508 ( V_64 , V_333 ) ;
switch ( V_67 ) {
case - V_91 :
case - V_860 :
F_167 ( 1 ) ;
break;
default:
return V_67 ;
}
}
return 0 ;
}
int F_511 ( struct V_63 * V_64 )
{
struct V_299 * V_333 ;
int V_67 = 0 ;
if ( V_64 -> V_168 -> V_315 < 1 )
goto V_132;
if ( V_64 -> V_845 == 0 )
goto V_132;
if ( V_64 -> V_861 )
goto V_132;
V_333 = F_494 ( V_64 ) ;
V_67 = F_510 ( V_64 , V_333 ) ;
if ( V_333 )
F_201 ( V_333 ) ;
switch ( V_67 ) {
case 0 :
case - V_77 :
V_64 -> V_845 = 0 ;
}
V_132:
return V_67 ;
}
static void F_512 ( struct V_117 * V_118 ,
void * V_156 )
{
struct V_862 * V_158 =
(struct V_862 * ) V_156 ;
F_8 ( L_11 , V_35 ) ;
F_61 ( V_158 -> V_64 -> V_88 ,
& V_158 -> args -> V_863 ,
& V_158 -> V_55 -> V_864 ,
V_118 ) ;
F_8 ( L_85 , V_35 ) ;
}
static void F_513 ( struct V_117 * V_118 , void * V_156 )
{
struct V_862 * V_158 =
(struct V_862 * ) V_156 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , & V_158 -> V_55 -> V_864 ) )
return;
switch ( V_118 -> V_150 ) {
case - V_91 :
case - V_90 :
F_8 ( L_86 , V_35 , V_118 -> V_150 ) ;
F_59 ( V_118 , V_56 ) ;
V_118 -> V_150 = 0 ;
case - V_93 :
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
int F_514 ( struct V_63 * V_64 , struct V_439 * V_539 )
{
struct V_117 * V_118 ;
struct V_865 args ;
struct V_866 V_55 = {
. V_867 = V_539 ,
} ;
struct V_862 V_158 = {
. args = & args ,
. V_55 = & V_55 ,
. V_64 = V_64 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_868 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
struct V_164 V_165 = {
. V_166 = V_64 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_869 ,
. V_170 = & V_158 ,
. V_207 = V_584 ,
} ;
int V_289 ;
F_38 ( & args . V_863 , & V_55 . V_864 , 0 ) ;
F_39 ( & args . V_863 ) ;
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
static void F_515 ( struct V_870 * args )
{
unsigned int V_871 , V_872 ;
V_871 = V_873 + V_874 ;
V_872 = V_873 + V_875 ;
args -> V_876 . V_871 = V_871 ;
args -> V_876 . V_872 = V_872 ;
args -> V_876 . V_877 = V_878 ;
args -> V_876 . V_879 = V_880 ;
F_8 ( L_88
L_89 ,
V_35 ,
args -> V_876 . V_871 , args -> V_876 . V_872 ,
args -> V_876 . V_877 , args -> V_876 . V_879 ) ;
args -> V_881 . V_871 = V_591 ;
args -> V_881 . V_872 = V_591 ;
args -> V_881 . V_882 = 0 ;
args -> V_881 . V_877 = V_883 ;
args -> V_881 . V_879 = 1 ;
F_8 ( L_90
L_91 ,
V_35 ,
args -> V_881 . V_871 , args -> V_881 . V_872 ,
args -> V_881 . V_882 , args -> V_881 . V_877 ,
args -> V_881 . V_879 ) ;
}
static int F_516 ( struct V_870 * args , struct V_134 * V_135 )
{
struct V_884 * V_885 = & args -> V_876 ;
struct V_884 * V_886 = & V_135 -> V_876 ;
if ( V_886 -> V_872 > V_885 -> V_872 )
return - V_27 ;
if ( V_886 -> V_877 < V_885 -> V_877 )
return - V_27 ;
if ( V_886 -> V_879 == 0 )
return - V_27 ;
if ( V_886 -> V_879 > V_887 )
V_886 -> V_879 = V_887 ;
return 0 ;
}
static int F_517 ( struct V_870 * args , struct V_134 * V_135 )
{
struct V_884 * V_885 = & args -> V_881 ;
struct V_884 * V_886 = & V_135 -> V_881 ;
if ( V_886 -> V_871 > V_885 -> V_871 )
return - V_27 ;
if ( V_886 -> V_872 < V_885 -> V_872 )
return - V_27 ;
if ( V_886 -> V_882 > V_885 -> V_882 )
return - V_27 ;
if ( V_886 -> V_877 != V_885 -> V_877 )
return - V_27 ;
if ( V_886 -> V_879 != V_885 -> V_879 )
return - V_27 ;
return 0 ;
}
static int F_518 ( struct V_870 * args ,
struct V_134 * V_135 )
{
int V_67 ;
V_67 = F_516 ( args , V_135 ) ;
if ( V_67 )
return V_67 ;
return F_517 ( args , V_135 ) ;
}
static int F_519 ( struct V_63 * V_64 ,
struct V_299 * V_333 )
{
struct V_134 * V_135 = V_64 -> V_88 ;
struct V_870 args = {
. V_92 = V_64 ,
. V_888 = V_889 ,
} ;
struct V_890 V_55 = {
. V_92 = V_64 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_891 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_515 ( & args ) ;
args . V_207 = ( V_892 | V_893 ) ;
V_289 = F_373 ( V_135 -> V_64 -> V_102 , & V_163 , V_584 ) ;
F_520 ( V_64 , V_289 ) ;
if ( ! V_289 ) {
V_289 = F_518 ( & args , V_135 ) ;
V_64 -> V_847 ++ ;
}
return V_289 ;
}
int F_521 ( struct V_63 * V_64 , struct V_299 * V_333 )
{
int V_289 ;
unsigned * V_894 ;
struct V_134 * V_135 = V_64 -> V_88 ;
F_8 ( L_92 , V_35 , V_64 , V_135 ) ;
V_289 = F_519 ( V_64 , V_333 ) ;
if ( V_289 )
goto V_132;
V_289 = F_522 ( V_135 ) ;
F_8 ( L_93 , V_289 ) ;
if ( V_289 )
goto V_132;
V_894 = ( unsigned * ) & V_135 -> V_794 . V_158 [ 0 ] ;
F_8 ( L_94 , V_35 ,
V_64 -> V_847 , V_894 [ 0 ] , V_894 [ 1 ] , V_894 [ 2 ] , V_894 [ 3 ] ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
return V_289 ;
}
int F_523 ( struct V_134 * V_135 ,
struct V_299 * V_333 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_895 ] ,
. V_297 = V_135 ,
. V_299 = V_333 ,
} ;
int V_289 = 0 ;
F_8 ( L_95 ) ;
if ( V_135 -> V_64 -> V_896 != V_897 )
return V_289 ;
V_289 = F_373 ( V_135 -> V_64 -> V_102 , & V_163 , V_584 ) ;
F_524 ( V_135 -> V_64 , V_289 ) ;
if ( V_289 )
F_8 ( L_96
L_97 , V_289 ) ;
F_8 ( L_98 ) ;
return V_289 ;
}
static void F_525 ( void * V_158 )
{
struct V_898 * V_156 = V_158 ;
struct V_63 * V_64 = V_156 -> V_64 ;
if ( F_363 ( & V_64 -> V_578 ) > 1 )
F_364 ( V_64 ) ;
F_365 ( V_64 ) ;
F_96 ( V_156 ) ;
}
static int F_526 ( struct V_117 * V_118 , struct V_63 * V_64 )
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
static void F_527 ( struct V_117 * V_118 , void * V_158 )
{
struct V_898 * V_156 = V_158 ;
struct V_63 * V_64 = V_156 -> V_64 ;
if ( ! F_53 ( V_118 , V_118 -> V_309 . V_298 ) )
return;
F_528 ( V_64 , V_118 -> V_150 ) ;
if ( V_118 -> V_150 < 0 ) {
F_8 ( L_99 , V_35 , V_118 -> V_150 ) ;
if ( F_363 ( & V_64 -> V_578 ) == 1 )
goto V_132;
if ( F_526 ( V_118 , V_64 ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
F_8 ( L_100 , V_35 , V_118 -> V_309 . V_299 ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
}
static void F_529 ( struct V_117 * V_118 , void * V_158 )
{
struct V_898 * V_156 = V_158 ;
struct V_63 * V_64 = V_156 -> V_64 ;
struct V_110 * args ;
struct V_111 * V_55 ;
args = V_118 -> V_309 . V_297 ;
V_55 = V_118 -> V_309 . V_298 ;
F_61 ( V_64 -> V_88 , args , V_55 , V_118 ) ;
}
static struct V_117 * F_530 ( struct V_63 * V_64 ,
struct V_299 * V_333 ,
bool V_899 )
{
struct V_898 * V_156 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_900 ] ,
. V_299 = V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = V_64 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_901 ,
. V_207 = V_304 | V_584 ,
} ;
if ( ! F_370 ( & V_64 -> V_578 ) )
return F_44 ( - V_36 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_286 ) ;
if ( V_156 == NULL ) {
F_365 ( V_64 ) ;
return F_44 ( - V_127 ) ;
}
F_38 ( & V_156 -> args , & V_156 -> V_55 , 0 ) ;
if ( V_899 )
F_39 ( & V_156 -> args ) ;
V_163 . V_297 = & V_156 -> args ;
V_163 . V_298 = & V_156 -> V_55 ;
V_156 -> V_64 = V_64 ;
V_300 . V_170 = V_156 ;
return F_70 ( & V_300 ) ;
}
static int F_531 ( struct V_63 * V_64 , struct V_299 * V_333 , unsigned V_582 )
{
struct V_117 * V_118 ;
int V_67 = 0 ;
if ( ( V_582 & V_902 ) == 0 )
return 0 ;
V_118 = F_530 ( V_64 , V_333 , false ) ;
if ( F_43 ( V_118 ) )
V_67 = F_71 ( V_118 ) ;
else
F_449 ( V_118 ) ;
F_8 ( L_16 , V_35 , V_67 ) ;
return V_67 ;
}
static int F_532 ( struct V_63 * V_64 , struct V_299 * V_333 )
{
struct V_117 * V_118 ;
int V_67 ;
V_118 = F_530 ( V_64 , V_333 , true ) ;
if ( F_43 ( V_118 ) ) {
V_67 = F_71 ( V_118 ) ;
goto V_132;
}
V_67 = F_108 ( V_118 ) ;
if ( ! V_67 ) {
struct V_111 * V_55 = V_118 -> V_309 . V_298 ;
if ( V_118 -> V_150 == 0 )
F_533 ( V_64 , V_55 -> V_146 ) ;
V_67 = V_118 -> V_150 ;
}
F_72 ( V_118 ) ;
V_132:
F_8 ( L_16 , V_35 , V_67 ) ;
return V_67 ;
}
static void F_534 ( struct V_117 * V_118 , void * V_158 )
{
struct V_903 * V_156 = V_158 ;
F_61 ( V_156 -> V_64 -> V_88 ,
& V_156 -> V_375 . V_160 ,
& V_156 -> V_55 . V_161 ,
V_118 ) ;
}
static int F_535 ( struct V_117 * V_118 , struct V_63 * V_64 )
{
switch( V_118 -> V_150 ) {
case 0 :
case - V_904 :
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
static void F_536 ( struct V_117 * V_118 , void * V_158 )
{
struct V_903 * V_156 = V_158 ;
struct V_63 * V_64 = V_156 -> V_64 ;
struct V_111 * V_55 = & V_156 -> V_55 . V_161 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , V_55 ) )
return;
F_537 ( V_64 , V_118 -> V_150 ) ;
if ( F_535 ( V_118 , V_64 ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
static void F_538 ( void * V_158 )
{
struct V_903 * V_156 = V_158 ;
F_96 ( V_156 ) ;
}
static int F_539 ( struct V_63 * V_64 ,
struct V_299 * V_333 )
{
struct V_903 * V_156 ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_905 ] ,
. V_299 = V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = V_64 -> V_102 ,
. V_162 = & V_163 ,
. V_167 = & V_906 ,
. V_207 = V_304 ,
} ;
int V_289 = - V_127 ;
F_8 ( L_11 , V_35 ) ;
V_156 = F_86 ( sizeof( * V_156 ) , V_286 ) ;
if ( V_156 == NULL )
goto V_132;
V_156 -> V_64 = V_64 ;
V_156 -> V_375 . V_907 = 0 ;
F_38 ( & V_156 -> V_375 . V_160 , & V_156 -> V_55 . V_161 , 0 ) ;
F_39 ( & V_156 -> V_375 . V_160 ) ;
V_163 . V_297 = & V_156 -> V_375 ;
V_163 . V_298 = & V_156 -> V_55 ;
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
F_540 ( struct V_117 * V_118 , void * V_156 )
{
struct V_908 * V_909 = V_156 ;
struct V_13 * V_14 = F_85 ( V_909 -> args . V_2 ) ;
struct V_134 * V_135 = F_64 ( V_14 ) ;
F_8 ( L_11 , V_35 ) ;
if ( F_61 ( V_135 , & V_909 -> args . V_160 ,
& V_909 -> V_55 . V_161 , V_118 ) )
return;
if ( F_541 ( & V_909 -> args . V_240 ,
F_75 ( V_909 -> args . V_2 ) -> V_910 ,
V_909 -> args . V_284 -> V_66 ) ) {
F_542 ( V_118 , V_763 ) ;
}
}
static void F_543 ( struct V_117 * V_118 , void * V_156 )
{
struct V_908 * V_909 = V_156 ;
struct V_2 * V_2 = V_909 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_911 * V_912 ;
struct V_65 * V_66 = NULL ;
unsigned long V_913 , V_543 , V_914 ;
F_8 ( L_101 , V_35 , - V_118 -> V_150 ) ;
if ( ! F_53 ( V_118 , & V_909 -> V_55 . V_161 ) )
goto V_132;
switch ( V_118 -> V_150 ) {
case 0 :
goto V_132;
case - V_19 :
case - V_20 :
V_913 = F_544 ( V_118 -> V_915 ) ;
V_914 = V_909 -> args . V_107 + V_913 ;
V_543 = V_155 ;
if ( F_545 ( V_914 , V_543 ) ) {
unsigned long V_916 ;
V_916 = F_546 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_102 ,
V_35 , V_916 ) ;
F_59 ( V_118 , V_916 ) ;
V_118 -> V_150 = 0 ;
F_57 ( V_118 ) ;
goto V_132;
}
break;
case - V_75 :
case - V_74 :
F_34 ( & V_2 -> V_175 ) ;
V_912 = F_75 ( V_2 ) -> V_910 ;
if ( ! V_912 || F_547 ( & V_912 -> V_917 ) ) {
F_36 ( & V_2 -> V_175 ) ;
V_66 = V_909 -> args . V_284 -> V_66 ;
} else {
F_548 ( V_918 ) ;
F_549 ( V_912 , & V_918 , NULL ) ;
F_36 ( & V_2 -> V_175 ) ;
F_550 ( & V_918 ) ;
}
}
if ( F_236 ( V_118 , V_14 , V_66 ) == - V_131 )
F_57 ( V_118 ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
}
static T_9 F_551 ( struct V_13 * V_14 )
{
T_1 V_872 = V_14 -> V_63 -> V_88 -> V_876 . V_872 ;
return F_552 ( 0 , V_872 ) ;
}
static void F_553 ( struct V_464 * * V_43 , T_9 V_919 )
{
int V_453 ;
if ( ! V_43 )
return;
for ( V_453 = 0 ; V_453 < V_919 ; V_453 ++ ) {
if ( ! V_43 [ V_453 ] )
break;
F_268 ( V_43 [ V_453 ] ) ;
}
F_96 ( V_43 ) ;
}
static struct V_464 * * F_554 ( T_9 V_919 , T_6 V_920 )
{
struct V_464 * * V_43 ;
int V_453 ;
V_43 = F_555 ( V_919 , sizeof( struct V_464 * ) , V_920 ) ;
if ( ! V_43 ) {
F_8 ( L_103 , V_35 , V_919 ) ;
return NULL ;
}
for ( V_453 = 0 ; V_453 < V_919 ; V_453 ++ ) {
V_43 [ V_453 ] = F_264 ( V_920 ) ;
if ( ! V_43 [ V_453 ] ) {
F_8 ( L_104 , V_35 ) ;
F_553 ( V_43 , V_919 ) ;
return NULL ;
}
}
return V_43 ;
}
static void F_556 ( void * V_156 )
{
struct V_908 * V_909 = V_156 ;
struct V_2 * V_2 = V_909 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_921 = F_551 ( V_14 ) ;
F_8 ( L_11 , V_35 ) ;
F_553 ( V_909 -> args . V_910 . V_43 , V_921 ) ;
F_557 ( F_75 ( V_2 ) -> V_910 ) ;
F_164 ( V_909 -> args . V_284 ) ;
F_96 ( V_156 ) ;
F_8 ( L_85 , V_35 ) ;
}
struct V_922 *
F_558 ( struct V_908 * V_909 , T_6 V_920 )
{
struct V_2 * V_2 = V_909 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_921 = F_551 ( V_14 ) ;
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_923 ] ,
. V_297 = & V_909 -> args ,
. V_298 = & V_909 -> V_55 ,
. V_299 = V_909 -> V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_924 ,
. V_170 = V_909 ,
. V_207 = V_304 ,
} ;
struct V_922 * V_925 = NULL ;
int V_289 = 0 ;
F_8 ( L_11 , V_35 ) ;
V_909 -> args . V_910 . V_43 = F_554 ( V_921 , V_920 ) ;
if ( ! V_909 -> args . V_910 . V_43 ) {
F_556 ( V_909 ) ;
return F_44 ( - V_127 ) ;
}
V_909 -> args . V_910 . V_490 = V_921 * V_591 ;
V_909 -> args . V_107 = V_155 ;
V_909 -> V_55 . V_926 = & V_909 -> args . V_910 ;
V_909 -> V_55 . V_161 . V_116 = NULL ;
F_38 ( & V_909 -> args . V_160 , & V_909 -> V_55 . V_161 , 0 ) ;
F_559 ( F_75 ( V_2 ) -> V_910 ) ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_243 ( V_118 ) ;
V_289 = F_107 ( V_118 ) ;
if ( V_289 == 0 )
V_289 = V_118 -> V_150 ;
F_560 ( V_909 -> args . V_284 ,
& V_909 -> args . V_927 ,
& V_909 -> V_55 . V_927 ,
V_289 ) ;
if ( V_289 == 0 && V_909 -> V_55 . V_926 -> V_12 )
V_925 = F_561 ( V_909 ) ;
F_72 ( V_118 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
if ( V_289 )
return F_44 ( V_289 ) ;
return V_925 ;
}
static void
F_562 ( struct V_117 * V_118 , void * V_156 )
{
struct V_928 * V_929 = V_156 ;
F_8 ( L_11 , V_35 ) ;
F_61 ( V_929 -> V_64 -> V_88 ,
& V_929 -> args . V_160 ,
& V_929 -> V_55 . V_161 ,
V_118 ) ;
}
static void F_563 ( struct V_117 * V_118 , void * V_156 )
{
struct V_928 * V_929 = V_156 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_35 ) ;
if ( ! F_53 ( V_118 , & V_929 -> V_55 . V_161 ) )
return;
V_14 = F_85 ( V_929 -> args . V_2 ) ;
switch ( V_118 -> V_150 ) {
default:
V_118 -> V_150 = 0 ;
case 0 :
break;
case - V_91 :
if ( F_236 ( V_118 , V_14 , NULL ) != - V_131 )
break;
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
static void F_564 ( void * V_156 )
{
struct V_928 * V_929 = V_156 ;
struct V_911 * V_912 = V_929 -> args . V_910 ;
F_8 ( L_11 , V_35 ) ;
F_34 ( & V_912 -> V_930 -> V_175 ) ;
if ( V_929 -> V_55 . V_931 )
F_565 ( V_912 , & V_929 -> V_55 . V_240 , true ) ;
V_912 -> V_932 -- ;
F_36 ( & V_912 -> V_930 -> V_175 ) ;
F_557 ( V_929 -> args . V_910 ) ;
F_96 ( V_156 ) ;
F_8 ( L_85 , V_35 ) ;
}
int F_566 ( struct V_928 * V_929 )
{
struct V_117 * V_118 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_933 ] ,
. V_297 = & V_929 -> args ,
. V_298 = & V_929 -> V_55 ,
. V_299 = V_929 -> V_333 ,
} ;
struct V_164 V_300 = {
. V_166 = F_85 ( V_929 -> args . V_2 ) -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_934 ,
. V_170 = V_929 ,
} ;
int V_289 ;
F_8 ( L_11 , V_35 ) ;
F_38 ( & V_929 -> args . V_160 , & V_929 -> V_55 . V_161 , 1 ) ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_289 = V_118 -> V_150 ;
F_567 ( V_929 -> args . V_2 , V_289 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
F_72 ( V_118 ) ;
return V_289 ;
}
static int F_568 ( struct V_13 * V_14 ,
const struct V_405 * V_234 ,
struct V_935 * V_936 )
{
struct V_937 args = {
. V_234 = V_234 ,
. V_938 = V_14 -> V_939 -> V_226 ,
} ;
struct V_940 V_55 = {
. V_936 = V_936 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_941 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
int V_289 ;
F_8 ( L_11 , V_35 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 ,
& V_55 . V_161 , 0 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
return V_289 ;
}
int F_569 ( struct V_13 * V_14 ,
const struct V_405 * V_234 ,
struct V_935 * V_936 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_568 ( V_14 , V_234 , V_936 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_8 ( L_105 , V_35 ,
V_8 , V_936 -> V_942 ) ;
return V_8 ;
}
static int
F_570 ( struct V_13 * V_14 ,
struct V_943 * V_944 ,
struct V_299 * V_333 )
{
struct V_945 args = {
. V_944 = V_944 ,
} ;
struct V_946 V_55 = {
. V_944 = V_944 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_947 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
int V_289 ;
F_8 ( L_11 , V_35 ) ;
V_289 = F_73 ( V_14 -> V_92 , V_14 , & V_163 , & args . V_160 , & V_55 . V_161 , 0 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
return V_289 ;
}
int F_571 ( struct V_13 * V_14 ,
struct V_943 * V_944 ,
struct V_299 * V_333 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_570 ( V_14 , V_944 , V_333 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_572 ( struct V_117 * V_118 , void * V_156 )
{
struct V_948 * V_158 = V_156 ;
struct V_13 * V_14 = F_85 ( V_158 -> args . V_2 ) ;
struct V_134 * V_135 = F_64 ( V_14 ) ;
F_61 ( V_135 ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static void
F_573 ( struct V_117 * V_118 , void * V_156 )
{
struct V_948 * V_158 = V_156 ;
struct V_13 * V_14 = F_85 ( V_158 -> args . V_2 ) ;
if ( ! F_53 ( V_118 , & V_158 -> V_55 . V_161 ) )
return;
switch ( V_118 -> V_150 ) {
case - V_72 :
case - V_949 :
case - V_950 :
case - V_90 :
V_118 -> V_150 = 0 ;
case 0 :
break;
default:
if ( F_236 ( V_118 , V_14 , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
}
static void F_574 ( void * V_156 )
{
struct V_948 * V_158 = V_156 ;
F_575 ( V_158 ) ;
F_351 ( V_158 -> args . V_2 ,
V_158 -> V_55 . V_372 ) ;
F_201 ( V_158 -> V_333 ) ;
F_96 ( V_158 ) ;
}
int
F_576 ( struct V_948 * V_158 , bool V_951 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_952 ] ,
. V_297 = & V_158 -> args ,
. V_298 = & V_158 -> V_55 ,
. V_299 = V_158 -> V_333 ,
} ;
struct V_164 V_300 = {
. V_118 = & V_158 -> V_118 ,
. V_166 = F_281 ( V_158 -> args . V_2 ) ,
. V_162 = & V_163 ,
. V_167 = & V_953 ,
. V_170 = V_158 ,
. V_207 = V_304 ,
} ;
struct V_117 * V_118 ;
int V_289 = 0 ;
F_8 ( L_106
L_107 ,
V_158 -> V_118 . V_954 , V_951 ,
V_158 -> args . V_955 ,
V_158 -> args . V_2 -> V_956 ) ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 1 ) ;
V_118 = F_70 ( & V_300 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
if ( V_951 == false )
goto V_132;
V_289 = F_107 ( V_118 ) ;
if ( V_289 != 0 )
goto V_132;
V_289 = V_118 -> V_150 ;
F_577 ( V_158 -> args . V_2 , V_289 ) ;
V_132:
F_8 ( L_108 , V_35 , V_289 ) ;
F_72 ( V_118 ) ;
return V_289 ;
}
static int
F_578 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_440 ,
struct V_775 * V_456 , bool V_776 )
{
struct V_957 args = {
. V_958 = V_959 ,
} ;
struct V_778 V_55 = {
. V_456 = V_456 ,
} ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_960 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
} ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_299 * V_333 = NULL ;
int V_289 ;
if ( V_776 ) {
V_53 = V_14 -> V_63 -> V_102 ;
V_333 = F_494 ( V_14 -> V_63 ) ;
V_163 . V_299 = V_333 ;
}
F_8 ( L_11 , V_35 ) ;
V_289 = F_73 ( V_53 , V_14 , & V_163 , & args . V_160 ,
& V_55 . V_161 , 0 ) ;
F_8 ( L_16 , V_35 , V_289 ) ;
if ( V_333 )
F_201 ( V_333 ) ;
return V_289 ;
}
static int
F_579 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_440 , struct V_775 * V_456 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( V_14 -> V_63 ) )
V_8 = F_578 ( V_14 , V_406 , V_440 ,
V_456 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_578 ( V_14 , V_406 , V_440 ,
V_456 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_961 :
goto V_132;
default:
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
}
} while ( V_62 . V_68 );
V_132:
return V_8 ;
}
static int
F_580 ( struct V_13 * V_14 , struct V_405 * V_406 ,
struct V_439 * V_440 )
{
int V_8 ;
struct V_464 * V_464 ;
T_4 V_101 = V_962 ;
struct V_775 * V_456 ;
struct V_963 * V_964 ;
int V_453 ;
V_464 = F_264 ( V_363 ) ;
if ( ! V_464 ) {
V_8 = - V_127 ;
goto V_132;
}
V_456 = F_377 ( V_464 ) ;
V_8 = F_579 ( V_14 , V_406 , V_440 , V_456 ) ;
if ( V_8 == - V_22 || V_8 == - V_961 ) {
V_8 = F_254 ( V_14 , V_406 , V_440 ) ;
goto V_965;
}
if ( V_8 )
goto V_965;
for ( V_453 = 0 ; V_453 < V_456 -> V_966 ; V_453 ++ ) {
V_964 = & V_456 -> V_456 [ V_453 ] ;
switch ( V_964 -> V_101 ) {
case V_452 :
case V_451 :
case V_967 :
V_101 = F_581 ( V_964 -> V_101 ,
& V_964 -> V_968 ) ;
break;
default:
V_101 = V_962 ;
break;
}
if ( ! F_582 ( & V_14 -> V_454 , V_101 ) )
V_101 = V_962 ;
if ( V_101 != V_962 ) {
V_8 = F_252 ( V_14 , V_406 ,
V_440 , V_101 ) ;
if ( ! V_8 )
break;
}
}
if ( V_101 == V_962 )
V_8 = - V_24 ;
V_965:
F_391 ( V_464 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_132:
return V_8 ;
}
static int F_583 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_299 * V_333 )
{
int V_289 ;
struct V_969 args = {
. V_240 = V_240 ,
} ;
struct V_970 V_55 ;
struct V_162 V_163 = {
. V_294 = & V_295 [ V_971 ] ,
. V_297 = & args ,
. V_298 = & V_55 ,
. V_299 = V_333 ,
} ;
struct V_52 * V_166 = V_14 -> V_92 ;
F_240 ( V_14 -> V_63 , V_823 ,
& V_166 , & V_163 ) ;
F_8 ( L_109 , V_240 ) ;
F_38 ( & args . V_160 , & V_55 . V_161 , 0 ) ;
F_39 ( & args . V_160 ) ;
V_289 = F_69 ( V_166 , V_14 , & V_163 ,
& args . V_160 , & V_55 . V_161 ) ;
if ( V_289 != V_347 ) {
F_8 ( L_110 , V_289 ) ;
return V_289 ;
}
F_8 ( L_111 , - V_55 . V_289 ) ;
return - V_55 . V_289 ;
}
static int F_198 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_299 * V_333 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_583 ( V_14 , V_240 , V_333 ) ;
if ( V_8 != - V_91 )
break;
F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_584 ( struct V_117 * V_118 , void * V_156 )
{
struct V_972 * V_158 = V_156 ;
F_61 ( F_64 ( V_158 -> V_14 ) ,
& V_158 -> args . V_160 ,
& V_158 -> V_55 . V_161 ,
V_118 ) ;
}
static void F_585 ( struct V_117 * V_118 , void * V_156 )
{
struct V_972 * V_158 = V_156 ;
F_53 ( V_118 , & V_158 -> V_55 . V_161 ) ;
switch ( V_118 -> V_150 ) {
case - V_91 :
if ( F_236 ( V_118 , V_158 -> V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
}
static void F_586 ( void * V_156 )
{
F_96 ( V_156 ) ;
}
static struct V_117 * F_587 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_299 * V_333 ,
bool V_973 )
{
struct V_162 V_163 = {
. V_294 = & V_295 [ V_974 ] ,
. V_299 = V_333 ,
} ;
struct V_164 V_165 = {
. V_166 = V_14 -> V_92 ,
. V_162 = & V_163 ,
. V_167 = & V_975 ,
. V_207 = V_304 ,
} ;
struct V_972 * V_158 ;
F_240 ( V_14 -> V_63 , V_823 ,
& V_165 . V_166 , & V_163 ) ;
F_8 ( L_112 , V_240 ) ;
V_158 = F_265 ( sizeof( * V_158 ) , V_286 ) ;
if ( ! V_158 )
return F_44 ( - V_127 ) ;
V_158 -> V_14 = V_14 ;
F_123 ( & V_158 -> args . V_240 , V_240 ) ;
V_165 . V_170 = V_158 ;
V_163 . V_297 = & V_158 -> args ;
V_163 . V_298 = & V_158 -> V_55 ;
F_38 ( & V_158 -> args . V_160 , & V_158 -> V_55 . V_161 , 0 ) ;
if ( V_973 )
F_39 ( & V_158 -> args . V_160 ) ;
return F_70 ( & V_165 ) ;
}
static int F_200 ( struct V_13 * V_14 ,
T_8 * V_240 ,
struct V_299 * V_333 )
{
struct V_117 * V_118 ;
int V_67 ;
V_118 = F_587 ( V_14 , V_240 , V_333 , true ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_67 = F_108 ( V_118 ) ;
if ( ! V_67 )
V_67 = V_118 -> V_150 ;
F_72 ( V_118 ) ;
return V_67 ;
}
static int F_588 ( struct V_13 * V_14 , struct V_680 * V_681 )
{
struct V_117 * V_118 ;
struct V_299 * V_333 = V_681 -> V_697 -> V_215 -> V_274 ;
V_118 = F_587 ( V_14 , & V_681 -> V_698 , V_333 , false ) ;
F_471 ( V_14 , V_681 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
F_72 ( V_118 ) ;
return 0 ;
}
static bool F_589 ( const T_8 * V_976 ,
const T_8 * V_977 )
{
if ( memcmp ( V_976 -> V_978 , V_977 -> V_978 , sizeof( V_976 -> V_978 ) ) != 0 )
return false ;
if ( V_976 -> V_196 == V_977 -> V_196 )
return true ;
if ( V_976 -> V_196 == 0 || V_977 -> V_196 == 0 )
return true ;
return false ;
}
static bool F_590 ( const T_8 * V_976 ,
const T_8 * V_977 )
{
return F_134 ( V_976 , V_977 ) ;
}
