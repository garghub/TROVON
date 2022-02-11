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
if ( ! F_49 ( V_118 ) )
goto V_132;
V_120 = V_123 -> V_133 ;
F_34 ( & V_120 -> V_125 ) ;
if ( ! F_50 ( V_120 , V_123 ) )
F_51 ( V_120 , V_123 ) ;
F_36 ( & V_120 -> V_125 ) ;
V_55 -> V_116 = NULL ;
V_132:
return 1 ;
}
static void F_52 ( struct V_111 * V_55 )
{
struct V_134 * V_135 ;
struct V_119 * V_120 ;
bool V_136 = false ;
if ( ! V_55 -> V_116 ) {
F_8 ( L_9 , V_35 ) ;
return;
}
V_120 = V_55 -> V_116 -> V_133 ;
V_135 = V_120 -> V_135 ;
F_34 ( & V_120 -> V_125 ) ;
if ( V_120 -> V_137 > V_120 -> V_138 )
V_136 = true ;
if ( F_50 ( V_120 , V_55 -> V_116 ) ) {
V_136 = false ;
goto V_139;
}
F_51 ( V_120 , V_55 -> V_116 ) ;
if ( V_120 -> V_137 != V_140 )
V_136 = false ;
V_139:
F_36 ( & V_120 -> V_125 ) ;
V_55 -> V_116 = NULL ;
if ( V_136 )
F_53 ( V_135 -> V_64 ) ;
}
static int F_54 ( struct V_117 * V_118 , struct V_111 * V_55 )
{
struct V_134 * V_135 ;
struct V_122 * V_123 ;
struct V_63 * V_64 ;
bool V_141 = false ;
int V_67 = 1 ;
if ( ! F_49 ( V_118 ) )
goto V_132;
V_123 = V_55 -> V_116 ;
V_135 = V_123 -> V_133 -> V_135 ;
if ( V_123 -> V_141 ) {
V_123 -> V_141 = 0 ;
V_141 = true ;
}
F_55 ( V_135 , V_55 ) ;
switch ( V_55 -> V_142 ) {
case 0 :
++ V_123 -> V_143 ;
V_64 = V_135 -> V_64 ;
F_33 ( V_64 , V_55 -> V_144 ) ;
if ( V_55 -> V_145 != 0 )
F_24 ( V_64 ) ;
F_56 ( V_123 -> V_133 , V_123 , V_55 ) ;
break;
case 1 :
V_123 -> V_141 = 1 ;
goto V_132;
case - V_91 :
F_8 ( L_10 ,
V_35 ,
V_123 -> V_146 ,
V_123 -> V_143 ) ;
goto V_147;
case - V_82 :
goto V_148;
case - V_87 :
if ( V_141 ) {
++ V_123 -> V_143 ;
goto V_148;
}
if ( V_123 -> V_143 != 1 ) {
V_123 -> V_143 = 1 ;
goto V_148;
}
break;
case - V_86 :
++ V_123 -> V_143 ;
goto V_148;
default:
++ V_123 -> V_143 ;
}
V_132:
F_8 ( L_11 , V_35 , V_55 -> V_142 ) ;
F_52 ( V_55 ) ;
return V_67 ;
V_148:
if ( F_57 ( V_118 ) ) {
V_118 -> V_149 = 0 ;
V_67 = 0 ;
}
goto V_132;
V_147:
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
return F_54 ( V_118 , V_55 ) ;
}
int F_61 ( struct V_134 * V_135 ,
struct V_110 * args ,
struct V_111 * V_55 ,
struct V_117 * V_118 )
{
struct V_122 * V_123 ;
struct V_119 * V_120 ;
F_8 ( L_12 , V_35 ) ;
if ( V_55 -> V_116 != NULL )
goto V_150;
V_120 = & V_135 -> V_151 ;
V_118 -> V_128 = 0 ;
F_34 ( & V_120 -> V_125 ) ;
if ( F_31 ( V_152 , & V_120 -> V_153 ) &&
! args -> V_115 ) {
F_8 ( L_13 , V_35 ) ;
goto V_126;
}
V_123 = F_42 ( V_120 ) ;
if ( F_43 ( V_123 ) ) {
if ( V_123 == F_44 ( - V_127 ) )
V_118 -> V_128 = V_89 >> 2 ;
F_8 ( L_14 , V_35 ) ;
goto V_126;
}
F_36 ( & V_120 -> V_125 ) ;
args -> V_113 = V_123 ;
F_8 ( L_15 , V_35 ,
V_123 -> V_146 , V_123 -> V_143 ) ;
V_55 -> V_116 = V_123 ;
V_55 -> V_144 = V_154 ;
V_55 -> V_145 = 0 ;
V_55 -> V_142 = 1 ;
F_62 ( V_135 , args ) ;
V_150:
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
F_8 ( L_16 ,
V_35 , V_135 -> V_64 , V_135 , V_55 -> V_116 ?
V_55 -> V_116 -> V_146 : V_140 ) ;
V_67 = F_61 ( V_135 , args , V_55 , V_118 ) ;
F_8 ( L_17 , V_35 , V_67 ) ;
return V_67 ;
}
static void F_65 ( struct V_117 * V_118 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
struct V_134 * V_135 = F_64 ( V_157 -> V_158 ) ;
F_8 ( L_18 , V_35 , V_157 -> V_158 ) ;
F_61 ( V_135 , V_157 -> V_159 , V_157 -> V_160 , V_118 ) ;
}
static void F_66 ( struct V_117 * V_118 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_54 ( V_118 , V_157 -> V_160 ) ;
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
static void F_67 ( struct V_117 * V_118 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_63 ( V_157 -> V_158 ,
V_157 -> V_159 , V_157 -> V_160 , V_118 ) ;
}
static void F_68 ( struct V_117 * V_118 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_60 ( V_118 , V_157 -> V_160 ) ;
}
static int F_69 ( struct V_52 * V_53 ,
struct V_13 * V_14 ,
struct V_161 * V_162 ,
struct V_110 * args ,
struct V_111 * V_55 )
{
int V_67 ;
struct V_117 * V_118 ;
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_156 V_157 = {
. V_158 = V_14 ,
. V_159 = args ,
. V_160 = V_55 ,
} ;
struct V_163 V_164 = {
. V_165 = V_53 ,
. V_161 = V_162 ,
. V_166 = V_64 -> V_167 -> V_168 ,
. V_169 = & V_157
} ;
V_118 = F_70 ( & V_164 ) ;
if ( F_43 ( V_118 ) )
V_67 = F_71 ( V_118 ) ;
else {
V_67 = V_118 -> V_149 ;
F_72 ( V_118 ) ;
}
return V_67 ;
}
static
int F_73 ( struct V_52 * V_53 ,
struct V_13 * V_14 ,
struct V_161 * V_162 ,
struct V_110 * args ,
struct V_111 * V_55 ,
int V_112 )
{
F_38 ( args , V_55 , V_112 ) ;
return F_69 ( V_53 , V_14 , V_162 , args , V_55 ) ;
}
static void F_74 ( struct V_2 * V_3 , struct V_170 * V_171 )
{
struct V_172 * V_173 = F_75 ( V_3 ) ;
F_34 ( & V_3 -> V_174 ) ;
V_173 -> V_175 |= V_176 | V_177 ;
if ( ! V_171 -> V_178 || V_171 -> V_179 != V_3 -> V_180 )
F_76 ( V_3 ) ;
V_3 -> V_180 = V_171 -> V_181 ;
F_77 ( V_3 ) ;
F_36 ( & V_3 -> V_174 ) ;
}
static bool F_78 ( struct V_13 * V_14 ,
int V_8 , struct V_61 * V_62 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_95 & V_182 ) )
return false ;
V_14 -> V_95 &= ~ V_182 ;
V_62 -> V_68 = 1 ;
return true ;
}
static enum V_183
F_79 ( struct V_13 * V_14 ,
enum V_183 V_184 )
{
if ( V_14 -> V_95 & V_182 )
return V_184 ;
switch ( V_184 ) {
default:
return V_184 ;
case V_185 :
return V_186 ;
case V_187 :
return V_188 ;
case V_189 :
return V_190 ;
}
}
static void F_80 ( struct V_191 * V_42 )
{
V_42 -> V_192 . V_193 = & V_42 -> V_193 ;
V_42 -> V_192 . V_194 = V_42 -> V_194 ;
V_42 -> V_192 . V_195 = V_42 -> V_196 . V_195 ;
V_42 -> V_197 . V_195 = V_42 -> V_198 . V_195 ;
V_42 -> V_192 . V_14 = V_42 -> V_196 . V_14 ;
V_42 -> V_192 . V_199 = V_42 -> V_196 . V_200 ;
F_81 ( & V_42 -> V_193 ) ;
F_82 ( & V_42 -> V_193 , & V_42 -> V_201 , & V_42 -> V_202 ) ;
}
static struct V_191 * F_83 ( struct V_4 * V_4 ,
struct V_203 * V_204 , T_5 V_205 , int V_206 ,
const struct V_5 * V_207 ,
struct V_1 * V_7 ,
enum V_183 V_184 ,
T_6 V_208 )
{
struct V_4 * V_209 = F_84 ( V_4 ) ;
struct V_2 * V_3 = V_209 -> V_47 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_191 * V_42 ;
V_42 = F_86 ( sizeof( * V_42 ) , V_208 ) ;
if ( V_42 == NULL )
goto V_8;
V_42 -> V_194 = F_87 ( V_14 , V_208 ) ;
if ( F_43 ( V_42 -> V_194 ) )
goto V_210;
V_42 -> V_196 . V_195 = F_88 ( & V_204 -> V_211 , V_208 ) ;
if ( V_42 -> V_196 . V_195 == NULL )
goto V_212;
F_89 ( V_4 -> V_213 ) ;
V_42 -> V_4 = F_90 ( V_4 ) ;
V_42 -> V_3 = V_209 ;
V_42 -> V_214 = V_204 ;
F_91 ( & V_204 -> V_215 ) ;
V_42 -> V_196 . V_216 = V_206 ;
V_42 -> V_196 . V_205 = V_205 & ( V_70 | V_217 ) ;
if ( ! ( V_206 & V_218 ) ) {
V_42 -> V_196 . V_200 = V_219 | V_220 |
V_221 | V_222 ;
}
V_42 -> V_196 . V_223 = V_14 -> V_63 -> V_224 ;
V_42 -> V_196 . V_225 . V_226 = F_92 ( V_204 -> V_211 . V_226 ) ;
V_42 -> V_196 . V_225 . V_227 = V_204 -> V_211 . V_228 ;
V_42 -> V_196 . V_229 = & V_4 -> V_11 ;
V_42 -> V_196 . V_14 = V_14 ;
V_42 -> V_196 . V_230 = F_6 ( V_14 , V_7 ) ;
V_42 -> V_196 . V_231 = & V_232 [ 0 ] ;
V_42 -> V_196 . V_7 = V_7 ;
V_42 -> V_196 . V_184 = F_79 ( V_14 , V_184 ) ;
switch ( V_42 -> V_196 . V_184 ) {
case V_186 :
case V_188 :
case V_190 :
V_42 -> V_196 . V_233 = F_93 ( V_3 ) ;
break;
case V_234 :
case V_185 :
case V_187 :
case V_189 :
V_42 -> V_196 . V_233 = F_93 ( V_4 -> V_47 ) ;
}
if ( V_207 != NULL && V_207 -> V_235 != 0 ) {
T_7 V_236 [ 2 ] ;
V_42 -> V_196 . V_237 . V_207 = & V_42 -> V_207 ;
memcpy ( & V_42 -> V_207 , V_207 , sizeof( V_42 -> V_207 ) ) ;
V_236 [ 0 ] = V_154 ;
V_236 [ 1 ] = V_58 -> V_238 ;
memcpy ( V_42 -> V_196 . V_237 . V_38 . V_157 , V_236 ,
sizeof( V_42 -> V_196 . V_237 . V_38 . V_157 ) ) ;
}
V_42 -> V_198 . V_233 = & V_42 -> V_192 . V_233 ;
V_42 -> V_198 . V_239 = & V_42 -> V_192 . V_239 ;
V_42 -> V_198 . V_195 = V_42 -> V_196 . V_195 ;
F_80 ( V_42 ) ;
F_94 ( & V_42 -> V_240 ) ;
return V_42 ;
V_212:
F_95 ( V_42 -> V_194 ) ;
V_210:
F_96 ( V_42 ) ;
V_8:
F_97 ( V_209 ) ;
return NULL ;
}
static void F_98 ( struct V_240 * V_240 )
{
struct V_191 * V_42 = F_99 ( V_240 ,
struct V_191 , V_240 ) ;
struct V_241 * V_242 = V_42 -> V_4 -> V_213 ;
F_100 ( V_42 -> V_196 . V_195 ) ;
if ( V_42 -> V_66 != NULL )
F_101 ( V_42 -> V_66 ) ;
F_102 ( V_42 -> V_214 ) ;
F_95 ( V_42 -> V_194 ) ;
F_97 ( V_42 -> V_3 ) ;
F_97 ( V_42 -> V_4 ) ;
F_103 ( V_242 ) ;
F_104 ( & V_42 -> V_193 ) ;
F_96 ( V_42 ) ;
}
static void F_105 ( struct V_191 * V_42 )
{
if ( V_42 != NULL )
F_106 ( & V_42 -> V_240 , F_98 ) ;
}
static int F_107 ( struct V_117 * V_118 )
{
int V_67 ;
V_67 = F_108 ( V_118 ) ;
return V_67 ;
}
static int F_109 ( struct V_65 * V_66 , T_5 V_243 , int V_244 )
{
int V_67 = 0 ;
if ( V_244 & ( V_218 | V_245 ) )
goto V_132;
switch ( V_243 & ( V_70 | V_217 ) ) {
case V_70 :
V_67 |= F_31 ( V_246 , & V_66 -> V_206 ) != 0
&& V_66 -> V_247 != 0 ;
break;
case V_217 :
V_67 |= F_31 ( V_248 , & V_66 -> V_206 ) != 0
&& V_66 -> V_249 != 0 ;
break;
case V_70 | V_217 :
V_67 |= F_31 ( V_250 , & V_66 -> V_206 ) != 0
&& V_66 -> V_251 != 0 ;
}
V_132:
return V_67 ;
}
static int F_110 ( struct V_252 * V_253 , T_5 V_205 )
{
if ( V_253 == NULL )
return 0 ;
if ( ( V_253 -> type & V_205 ) != V_205 )
return 0 ;
if ( F_31 ( V_254 , & V_253 -> V_206 ) )
return 0 ;
if ( F_31 ( V_255 , & V_253 -> V_206 ) )
return 0 ;
F_111 ( V_253 ) ;
return 1 ;
}
static void F_112 ( struct V_65 * V_66 , T_5 V_205 )
{
switch ( V_205 ) {
case V_217 :
V_66 -> V_249 ++ ;
break;
case V_70 :
V_66 -> V_247 ++ ;
break;
case V_70 | V_217 :
V_66 -> V_251 ++ ;
}
F_113 ( V_66 , V_66 -> V_66 | V_205 ) ;
}
static void F_114 ( struct V_65 * V_66 , T_8 * V_239 , T_5 V_205 )
{
if ( F_31 ( V_256 , & V_66 -> V_206 ) == 0 )
F_115 ( & V_66 -> V_239 , V_239 ) ;
F_115 ( & V_66 -> V_257 , V_239 ) ;
F_116 ( V_258 , & V_66 -> V_206 ) ;
switch ( V_205 ) {
case V_70 :
F_116 ( V_246 , & V_66 -> V_206 ) ;
break;
case V_217 :
F_116 ( V_248 , & V_66 -> V_206 ) ;
break;
case V_70 | V_217 :
F_116 ( V_250 , & V_66 -> V_206 ) ;
}
}
static void F_117 ( struct V_65 * V_66 , T_8 * V_239 , T_5 V_205 )
{
F_118 ( & V_66 -> V_259 ) ;
F_114 ( V_66 , V_239 , V_205 ) ;
F_119 ( & V_66 -> V_259 ) ;
}
static void F_120 ( struct V_65 * V_66 , T_8 * V_257 , const T_8 * V_260 , T_5 V_205 )
{
F_118 ( & V_66 -> V_259 ) ;
if ( V_260 != NULL ) {
F_115 ( & V_66 -> V_239 , V_260 ) ;
F_116 ( V_256 , & V_66 -> V_206 ) ;
}
if ( V_257 != NULL )
F_114 ( V_66 , V_257 , V_205 ) ;
F_119 ( & V_66 -> V_259 ) ;
F_34 ( & V_66 -> V_214 -> V_261 ) ;
F_112 ( V_66 , V_205 ) ;
F_36 ( & V_66 -> V_214 -> V_261 ) ;
}
static int F_121 ( struct V_65 * V_66 , T_8 * V_257 , T_8 * V_253 , T_5 V_205 )
{
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_252 * V_262 ;
int V_67 = 0 ;
V_205 &= ( V_70 | V_217 ) ;
F_122 () ;
V_262 = F_123 ( V_173 -> V_253 ) ;
if ( V_262 == NULL )
goto V_263;
F_34 ( & V_262 -> V_264 ) ;
if ( F_123 ( V_173 -> V_253 ) != V_262 ||
F_31 ( V_255 , & V_262 -> V_206 ) ||
( V_262 -> type & V_205 ) != V_205 )
goto V_265;
if ( V_253 == NULL )
V_253 = & V_262 -> V_239 ;
else if ( ! F_124 ( & V_262 -> V_239 , V_253 ) )
goto V_265;
F_111 ( V_262 ) ;
F_120 ( V_66 , V_257 , & V_262 -> V_239 , V_205 ) ;
V_67 = 1 ;
V_265:
F_36 ( & V_262 -> V_264 ) ;
V_263:
F_125 () ;
if ( ! V_67 && V_257 != NULL ) {
F_120 ( V_66 , V_257 , NULL , V_205 ) ;
V_67 = 1 ;
}
return V_67 ;
}
static void F_126 ( struct V_2 * V_2 , T_5 V_205 )
{
struct V_252 * V_253 ;
F_122 () ;
V_253 = F_123 ( F_75 ( V_2 ) -> V_253 ) ;
if ( V_253 == NULL || ( V_253 -> type & V_205 ) == V_205 ) {
F_125 () ;
return;
}
F_125 () ;
F_21 ( V_2 ) ;
}
static struct V_65 * F_127 ( struct V_191 * V_266 )
{
struct V_65 * V_66 = V_266 -> V_66 ;
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_252 * V_253 ;
int V_244 = V_266 -> V_196 . V_216 ;
T_5 V_205 = V_266 -> V_196 . V_205 ;
T_8 V_239 ;
int V_67 = - V_131 ;
for (; ; ) {
if ( F_109 ( V_66 , V_205 , V_244 ) ) {
F_34 ( & V_66 -> V_214 -> V_261 ) ;
if ( F_109 ( V_66 , V_205 , V_244 ) ) {
F_112 ( V_66 , V_205 ) ;
F_36 ( & V_66 -> V_214 -> V_261 ) ;
goto V_267;
}
F_36 ( & V_66 -> V_214 -> V_261 ) ;
}
F_122 () ;
V_253 = F_123 ( V_173 -> V_253 ) ;
if ( ! F_110 ( V_253 , V_205 ) ) {
F_125 () ;
break;
}
F_115 ( & V_239 , & V_253 -> V_239 ) ;
F_125 () ;
F_128 ( V_266 -> V_196 . V_195 ) ;
if ( ! V_266 -> V_268 ) {
V_67 = F_129 ( V_66 -> V_2 , V_66 -> V_214 -> V_269 , V_244 ) ;
if ( V_67 != 0 )
goto V_132;
}
V_67 = - V_131 ;
if ( F_121 ( V_66 , NULL , & V_239 , V_205 ) )
goto V_267;
}
V_132:
return F_44 ( V_67 ) ;
V_267:
F_91 ( & V_66 -> V_51 ) ;
return V_66 ;
}
static void
F_130 ( struct V_191 * V_157 , struct V_65 * V_66 )
{
struct V_63 * V_64 = F_85 ( V_66 -> V_2 ) -> V_63 ;
struct V_252 * V_253 ;
int V_270 = 0 ;
F_122 () ;
V_253 = F_123 ( F_75 ( V_66 -> V_2 ) -> V_253 ) ;
if ( V_253 )
V_270 = V_253 -> V_206 ;
F_125 () ;
if ( V_157 -> V_196 . V_184 == V_188 ) {
F_131 ( L_19
L_20
L_21 ,
V_64 -> V_98 ) ;
} else if ( ( V_270 & 1UL << V_254 ) == 0 )
F_132 ( V_66 -> V_2 ,
V_157 -> V_214 -> V_269 ,
& V_157 -> V_192 ) ;
else
F_133 ( V_66 -> V_2 ,
V_157 -> V_214 -> V_269 ,
& V_157 -> V_192 ) ;
}
static struct V_65 *
F_134 ( struct V_191 * V_157 )
{
struct V_2 * V_2 = V_157 -> V_66 -> V_2 ;
struct V_65 * V_66 = V_157 -> V_66 ;
int V_67 ;
if ( ! V_157 -> V_271 ) {
if ( V_157 -> V_272 ) {
V_67 = V_157 -> V_272 ;
goto V_8;
}
goto V_273;
}
V_67 = F_135 ( V_2 , & V_157 -> V_193 ) ;
if ( V_67 )
goto V_8;
if ( V_157 -> V_192 . V_274 != 0 )
F_130 ( V_157 , V_66 ) ;
V_273:
F_121 ( V_66 , & V_157 -> V_192 . V_239 , NULL ,
V_157 -> V_196 . V_205 ) ;
F_91 ( & V_66 -> V_51 ) ;
return V_66 ;
V_8:
return F_44 ( V_67 ) ;
}
static struct V_65 *
F_136 ( struct V_191 * V_157 )
{
struct V_2 * V_2 ;
struct V_65 * V_66 = NULL ;
int V_67 ;
if ( ! V_157 -> V_271 ) {
V_66 = F_127 ( V_157 ) ;
goto V_132;
}
V_67 = - V_131 ;
if ( ! ( V_157 -> V_193 . V_275 & V_276 ) )
goto V_8;
V_2 = F_137 ( V_157 -> V_3 -> V_213 , & V_157 -> V_192 . V_233 , & V_157 -> V_193 , V_157 -> V_194 ) ;
V_67 = F_71 ( V_2 ) ;
if ( F_43 ( V_2 ) )
goto V_8;
V_67 = - V_127 ;
V_66 = F_138 ( V_2 , V_157 -> V_214 ) ;
if ( V_66 == NULL )
goto V_277;
if ( V_157 -> V_192 . V_274 != 0 )
F_130 ( V_157 , V_66 ) ;
F_121 ( V_66 , & V_157 -> V_192 . V_239 , NULL ,
V_157 -> V_196 . V_205 ) ;
F_139 ( V_2 ) ;
V_132:
F_128 ( V_157 -> V_196 . V_195 ) ;
return V_66 ;
V_277:
F_139 ( V_2 ) ;
V_8:
return F_44 ( V_67 ) ;
}
static struct V_65 *
F_140 ( struct V_191 * V_157 )
{
if ( V_157 -> V_196 . V_184 == V_234 )
return F_134 ( V_157 ) ;
return F_136 ( V_157 ) ;
}
static struct V_278 * F_141 ( struct V_65 * V_66 )
{
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_278 * V_279 ;
F_34 ( & V_66 -> V_2 -> V_174 ) ;
F_142 (ctx, &nfsi->open_files, list) {
if ( V_279 -> V_66 != V_66 )
continue;
F_143 ( V_279 ) ;
F_36 ( & V_66 -> V_2 -> V_174 ) ;
return V_279 ;
}
F_36 ( & V_66 -> V_2 -> V_174 ) ;
return F_44 ( - V_280 ) ;
}
static struct V_191 * F_144 ( struct V_278 * V_279 ,
struct V_65 * V_66 , enum V_183 V_184 )
{
struct V_191 * V_266 ;
V_266 = F_83 ( V_279 -> V_4 , V_66 -> V_214 , 0 , 0 ,
NULL , NULL , V_184 , V_281 ) ;
if ( V_266 == NULL )
return F_44 ( - V_127 ) ;
V_266 -> V_66 = V_66 ;
F_91 ( & V_66 -> V_51 ) ;
return V_266 ;
}
static int F_145 ( struct V_191 * V_266 , T_5 V_205 , struct V_65 * * V_55 )
{
struct V_65 * V_282 ;
int V_67 ;
V_266 -> V_196 . V_216 = 0 ;
V_266 -> V_196 . V_205 = V_205 ;
memset ( & V_266 -> V_192 , 0 , sizeof( V_266 -> V_192 ) ) ;
memset ( & V_266 -> V_197 , 0 , sizeof( V_266 -> V_197 ) ) ;
F_80 ( V_266 ) ;
V_67 = F_146 ( V_266 ) ;
if ( V_67 != 0 )
return V_67 ;
V_282 = F_140 ( V_266 ) ;
if ( F_43 ( V_282 ) )
return F_71 ( V_282 ) ;
F_147 ( V_282 , V_205 ) ;
* V_55 = V_282 ;
return 0 ;
}
static int F_148 ( struct V_191 * V_266 , struct V_65 * V_66 )
{
struct V_65 * V_282 ;
int V_67 ;
F_149 ( V_256 , & V_66 -> V_206 ) ;
F_149 ( V_258 , & V_66 -> V_206 ) ;
F_150 () ;
if ( V_66 -> V_251 != 0 ) {
F_149 ( V_250 , & V_66 -> V_206 ) ;
V_67 = F_145 ( V_266 , V_70 | V_217 , & V_282 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_282 != V_66 )
return - V_283 ;
}
if ( V_66 -> V_249 != 0 ) {
F_149 ( V_248 , & V_66 -> V_206 ) ;
V_67 = F_145 ( V_266 , V_217 , & V_282 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_282 != V_66 )
return - V_283 ;
}
if ( V_66 -> V_247 != 0 ) {
F_149 ( V_246 , & V_66 -> V_206 ) ;
V_67 = F_145 ( V_266 , V_70 , & V_282 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_282 != V_66 )
return - V_283 ;
}
if ( F_31 ( V_256 , & V_66 -> V_206 ) == 0 &&
! F_124 ( & V_66 -> V_239 , & V_66 -> V_257 ) ) {
F_118 ( & V_66 -> V_259 ) ;
if ( F_31 ( V_256 , & V_66 -> V_206 ) == 0 )
F_115 ( & V_66 -> V_239 , & V_66 -> V_257 ) ;
F_119 ( & V_66 -> V_259 ) ;
}
return 0 ;
}
static int F_151 ( struct V_278 * V_279 , struct V_65 * V_66 )
{
struct V_252 * V_253 ;
struct V_191 * V_266 ;
T_5 V_274 = 0 ;
int V_284 ;
V_266 = F_144 ( V_279 , V_66 ,
V_234 ) ;
if ( F_43 ( V_266 ) )
return F_71 ( V_266 ) ;
F_122 () ;
V_253 = F_123 ( F_75 ( V_66 -> V_2 ) -> V_253 ) ;
if ( V_253 != NULL && F_31 ( V_254 , & V_253 -> V_206 ) != 0 )
V_274 = V_253 -> type ;
F_125 () ;
V_266 -> V_196 . V_237 . V_274 = V_274 ;
V_284 = F_148 ( V_266 , V_66 ) ;
F_105 ( V_266 ) ;
return V_284 ;
}
static int F_152 ( struct V_278 * V_279 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_151 ( V_279 , V_66 ) ;
F_153 ( V_279 , 0 , V_8 ) ;
if ( F_78 ( V_14 , V_8 , & V_62 ) )
continue;
if ( V_8 != - V_91 )
break;
F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_154 ( struct V_203 * V_204 , struct V_65 * V_66 )
{
struct V_278 * V_279 ;
int V_67 ;
V_279 = F_141 ( V_66 ) ;
if ( F_43 ( V_279 ) )
return - V_131 ;
V_67 = F_152 ( V_279 , V_66 ) ;
F_155 ( V_279 ) ;
return V_67 ;
}
static int F_156 ( struct V_13 * V_14 , struct V_65 * V_66 , const T_8 * V_239 , int V_8 )
{
switch ( V_8 ) {
default:
F_29 ( V_285 L_22
L_23 , V_35 , V_8 ) ;
case 0 :
case - V_280 :
case - V_283 :
break;
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
F_116 ( V_256 , & V_66 -> V_206 ) ;
F_28 ( V_14 -> V_63 -> V_88 , V_8 ) ;
return - V_131 ;
case - V_77 :
case - V_76 :
F_116 ( V_256 , & V_66 -> V_206 ) ;
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
V_239 ) ;
F_22 ( V_14 , V_66 ) ;
return 0 ;
case - V_91 :
case - V_90 :
F_116 ( V_256 , & V_66 -> V_206 ) ;
F_158 ( 1 ) ;
return - V_131 ;
case - V_127 :
case - V_286 :
return 0 ;
}
return V_8 ;
}
int F_159 ( struct V_278 * V_279 , struct V_65 * V_66 , const T_8 * V_239 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_191 * V_266 ;
int V_8 ;
V_266 = F_144 ( V_279 , V_66 ,
V_187 ) ;
if ( F_43 ( V_266 ) )
return F_71 ( V_266 ) ;
F_115 ( & V_266 -> V_196 . V_237 . V_253 , V_239 ) ;
V_8 = F_148 ( V_266 , V_66 ) ;
F_105 ( V_266 ) ;
return F_156 ( V_14 , V_66 , V_239 , V_8 ) ;
}
static void F_160 ( struct V_117 * V_118 , void * V_155 )
{
struct V_191 * V_157 = V_155 ;
F_40 ( V_157 -> V_196 . V_14 , & V_157 -> V_196 . V_159 ,
& V_157 -> V_192 . V_160 , V_118 ) ;
}
static void F_161 ( struct V_117 * V_118 , void * V_155 )
{
struct V_191 * V_157 = V_155 ;
F_48 ( V_118 , & V_157 -> V_192 . V_160 ) ;
V_157 -> V_272 = V_118 -> V_149 ;
if ( V_157 -> V_272 == 0 ) {
F_115 ( & V_157 -> V_192 . V_239 , & V_157 -> V_197 . V_239 ) ;
F_162 ( & V_157 -> V_214 -> V_211 , 0 ) ;
F_37 ( V_157 -> V_192 . V_14 , V_157 -> V_107 ) ;
V_157 -> V_271 = 1 ;
}
}
static void F_163 ( void * V_155 )
{
struct V_191 * V_157 = V_155 ;
struct V_65 * V_66 = NULL ;
if ( V_157 -> V_287 == 0 )
goto V_288;
if ( ! V_157 -> V_271 )
goto V_288;
V_66 = F_140 ( V_157 ) ;
if ( ! F_43 ( V_66 ) )
F_147 ( V_66 , V_157 -> V_196 . V_205 ) ;
V_288:
F_105 ( V_157 ) ;
}
static int F_164 ( struct V_191 * V_157 )
{
struct V_13 * V_14 = F_85 ( V_157 -> V_3 -> V_47 ) ;
struct V_117 * V_118 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_291 ] ,
. V_292 = & V_157 -> V_198 ,
. V_293 = & V_157 -> V_197 ,
. V_294 = V_157 -> V_214 -> V_269 ,
} ;
struct V_163 V_295 = {
. V_165 = V_14 -> V_92 ,
. V_161 = & V_162 ,
. V_166 = & V_296 ,
. V_169 = V_157 ,
. V_297 = V_298 ,
. V_206 = V_299 ,
} ;
int V_284 ;
F_38 ( & V_157 -> V_196 . V_159 , & V_157 -> V_192 . V_160 , 1 ) ;
F_165 ( & V_157 -> V_240 ) ;
V_157 -> V_271 = 0 ;
V_157 -> V_272 = 0 ;
V_157 -> V_107 = V_154 ;
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_284 = F_107 ( V_118 ) ;
if ( V_284 != 0 ) {
V_157 -> V_287 = 1 ;
F_166 () ;
} else
V_284 = V_157 -> V_272 ;
F_72 ( V_118 ) ;
return V_284 ;
}
static void F_167 ( struct V_117 * V_118 , void * V_155 )
{
struct V_191 * V_157 = V_155 ;
struct V_203 * V_204 = V_157 -> V_214 ;
struct V_63 * V_64 = V_204 -> V_300 -> V_63 ;
if ( F_168 ( V_157 -> V_196 . V_195 , V_118 ) != 0 )
goto V_301;
if ( V_157 -> V_66 != NULL ) {
struct V_252 * V_253 ;
if ( F_109 ( V_157 -> V_66 , V_157 -> V_196 . V_205 , V_157 -> V_196 . V_216 ) )
goto V_302;
F_122 () ;
V_253 = F_123 ( F_75 ( V_157 -> V_66 -> V_2 ) -> V_253 ) ;
if ( V_157 -> V_196 . V_184 != V_188 &&
V_157 -> V_196 . V_184 != V_187 &&
F_110 ( V_253 , V_157 -> V_196 . V_205 ) )
goto V_303;
F_125 () ;
}
V_157 -> V_196 . V_223 = V_64 -> V_224 ;
switch ( V_157 -> V_196 . V_184 ) {
case V_234 :
case V_187 :
case V_189 :
V_157 -> V_196 . V_231 = & V_304 [ 0 ] ;
case V_185 :
V_118 -> V_305 . V_289 = & V_290 [ V_306 ] ;
F_169 ( & V_157 -> V_192 . V_233 , V_157 -> V_196 . V_233 ) ;
}
V_157 -> V_107 = V_154 ;
if ( F_63 ( V_157 -> V_196 . V_14 ,
& V_157 -> V_196 . V_159 ,
& V_157 -> V_192 . V_160 ,
V_118 ) != 0 )
F_128 ( V_157 -> V_196 . V_195 ) ;
V_157 -> V_196 . V_307 = V_308 ;
if ( V_157 -> V_196 . V_216 & V_218 ) {
V_157 -> V_196 . V_307 = V_309 ;
if ( F_170 ( V_64 ) )
V_157 -> V_196 . V_307 = V_310 ;
else if ( V_64 -> V_167 -> V_311 > 0 )
V_157 -> V_196 . V_307 = V_312 ;
}
return;
V_303:
F_125 () ;
V_302:
V_118 -> V_313 = NULL ;
V_301:
F_60 ( V_118 , & V_157 -> V_192 . V_160 ) ;
}
static void F_171 ( struct V_117 * V_118 , void * V_155 )
{
struct V_191 * V_157 = V_155 ;
V_157 -> V_272 = V_118 -> V_149 ;
if ( ! F_60 ( V_118 , & V_157 -> V_192 . V_160 ) )
return;
if ( V_118 -> V_149 == 0 ) {
if ( V_157 -> V_192 . V_193 -> V_275 & V_314 ) {
switch ( V_157 -> V_192 . V_193 -> V_243 & V_315 ) {
case V_316 :
break;
case V_317 :
V_157 -> V_272 = - V_318 ;
break;
case V_319 :
V_157 -> V_272 = - V_320 ;
break;
default:
V_157 -> V_272 = - V_321 ;
}
}
F_37 ( V_157 -> V_192 . V_14 , V_157 -> V_107 ) ;
if ( ! ( V_157 -> V_192 . V_322 & V_323 ) )
F_162 ( & V_157 -> V_214 -> V_211 , 0 ) ;
}
V_157 -> V_271 = 1 ;
}
static void F_172 ( void * V_155 )
{
struct V_191 * V_157 = V_155 ;
struct V_65 * V_66 = NULL ;
if ( V_157 -> V_287 == 0 )
goto V_288;
if ( V_157 -> V_272 != 0 || ! V_157 -> V_271 )
goto V_288;
if ( V_157 -> V_192 . V_322 & V_323 )
goto V_288;
V_66 = F_140 ( V_157 ) ;
if ( ! F_43 ( V_66 ) )
F_147 ( V_66 , V_157 -> V_196 . V_205 ) ;
V_288:
F_105 ( V_157 ) ;
}
static int F_173 ( struct V_191 * V_157 , int V_324 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_47 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_325 * V_196 = & V_157 -> V_196 ;
struct V_326 * V_192 = & V_157 -> V_192 ;
struct V_117 * V_118 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_327 ] ,
. V_292 = V_196 ,
. V_293 = V_192 ,
. V_294 = V_157 -> V_214 -> V_269 ,
} ;
struct V_163 V_295 = {
. V_165 = V_14 -> V_92 ,
. V_161 = & V_162 ,
. V_166 = & V_328 ,
. V_169 = V_157 ,
. V_297 = V_298 ,
. V_206 = V_299 ,
} ;
int V_284 ;
F_38 ( & V_196 -> V_159 , & V_192 -> V_160 , 1 ) ;
F_165 ( & V_157 -> V_240 ) ;
V_157 -> V_271 = 0 ;
V_157 -> V_272 = 0 ;
V_157 -> V_287 = 0 ;
V_157 -> V_268 = 0 ;
if ( V_324 ) {
F_39 ( & V_196 -> V_159 ) ;
V_157 -> V_268 = 1 ;
}
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_284 = F_107 ( V_118 ) ;
if ( V_284 != 0 ) {
V_157 -> V_287 = 1 ;
F_166 () ;
} else
V_284 = V_157 -> V_272 ;
F_72 ( V_118 ) ;
return V_284 ;
}
static int F_146 ( struct V_191 * V_157 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_47 ;
struct V_326 * V_192 = & V_157 -> V_192 ;
int V_284 ;
V_284 = F_173 ( V_157 , 1 ) ;
if ( V_284 != 0 || ! V_157 -> V_271 )
return V_284 ;
F_174 ( F_85 ( V_3 ) , & V_157 -> V_193 ) ;
if ( V_192 -> V_322 & V_323 ) {
V_284 = F_164 ( V_157 ) ;
if ( V_284 != 0 )
return V_284 ;
}
return V_284 ;
}
static int F_175 ( struct V_294 * V_329 ,
struct V_191 * V_266 ,
struct V_65 * V_66 , T_5 V_205 ,
int V_330 )
{
struct V_331 V_332 ;
T_1 V_333 ;
if ( V_266 -> V_192 . V_334 == 0 )
return 0 ;
V_333 = 0 ;
if ( V_330 & V_335 ) {
V_333 = V_336 ;
} else if ( V_205 & V_70 )
V_333 = V_337 ;
V_332 . V_329 = V_329 ;
V_332 . V_154 = V_154 ;
F_176 ( & V_332 , V_266 -> V_192 . V_338 ) ;
F_177 ( V_66 -> V_2 , & V_332 ) ;
if ( ( V_333 & ~ V_332 . V_333 & ( V_337 | V_336 ) ) == 0 )
return 0 ;
F_147 ( V_66 , V_205 ) ;
return - V_29 ;
}
static int F_178 ( struct V_191 * V_157 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_47 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_325 * V_196 = & V_157 -> V_196 ;
struct V_326 * V_192 = & V_157 -> V_192 ;
int V_284 ;
V_284 = F_173 ( V_157 , 0 ) ;
if ( ! V_157 -> V_271 )
return V_284 ;
if ( V_284 != 0 ) {
if ( V_284 == - V_26 &&
! ( V_196 -> V_216 & V_339 ) )
return - V_280 ;
return V_284 ;
}
F_174 ( V_14 , & V_157 -> V_193 ) ;
if ( V_196 -> V_216 & V_339 ) {
F_74 ( V_3 , & V_192 -> V_171 ) ;
if ( V_196 -> V_216 & V_218 )
V_157 -> V_340 = 1 ;
else if ( V_192 -> V_171 . V_179 != V_192 -> V_171 . V_181 )
V_157 -> V_340 = 1 ;
}
if ( ( V_192 -> V_322 & V_341 ) == 0 )
V_14 -> V_95 &= ~ V_342 ;
if( V_192 -> V_322 & V_323 ) {
V_284 = F_164 ( V_157 ) ;
if ( V_284 != 0 )
return V_284 ;
}
if ( ! ( V_192 -> V_193 -> V_275 & V_276 ) )
F_179 ( V_14 , & V_192 -> V_233 , V_192 -> V_193 , V_192 -> V_194 ) ;
return 0 ;
}
static int F_180 ( struct V_13 * V_14 )
{
return F_181 ( V_14 -> V_63 ) ;
}
static int F_182 ( struct V_278 * V_279 , struct V_65 * V_66 )
{
struct V_191 * V_266 ;
int V_67 ;
V_266 = F_144 ( V_279 , V_66 ,
V_185 ) ;
if ( F_43 ( V_266 ) )
return F_71 ( V_266 ) ;
V_67 = F_148 ( V_266 , V_66 ) ;
if ( V_67 == - V_283 )
F_183 ( V_279 -> V_4 ) ;
F_105 ( V_266 ) ;
return V_67 ;
}
static int F_184 ( struct V_278 * V_279 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_182 ( V_279 , V_66 ) ;
F_185 ( V_279 , 0 , V_8 ) ;
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
static int F_186 ( struct V_203 * V_204 , struct V_65 * V_66 )
{
struct V_278 * V_279 ;
int V_67 ;
V_279 = F_141 ( V_66 ) ;
if ( F_43 ( V_279 ) )
return - V_131 ;
V_67 = F_184 ( V_279 , V_66 ) ;
F_155 ( V_279 ) ;
return V_67 ;
}
static void F_187 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
T_8 * V_239 = & V_66 -> V_239 ;
struct V_252 * V_253 ;
struct V_294 * V_329 = NULL ;
int V_284 = - V_74 ;
if ( F_31 ( V_256 , & V_66 -> V_206 ) == 0 )
return;
F_122 () ;
V_253 = F_123 ( F_75 ( V_66 -> V_2 ) -> V_253 ) ;
if ( V_253 != NULL &&
F_124 ( & V_253 -> V_239 , V_239 ) ) {
V_329 = F_188 ( V_253 -> V_329 ) ;
F_125 () ;
V_284 = F_189 ( V_14 , V_239 , V_329 ) ;
F_190 ( V_66 , NULL , V_284 ) ;
} else
F_125 () ;
if ( V_284 != V_343 ) {
if ( V_284 != - V_74 )
F_191 ( V_14 , V_239 , V_329 ) ;
F_23 ( V_66 -> V_2 ) ;
F_118 ( & V_66 -> V_259 ) ;
F_115 ( & V_66 -> V_239 , & V_66 -> V_257 ) ;
F_119 ( & V_66 -> V_259 ) ;
F_149 ( V_256 , & V_66 -> V_206 ) ;
}
if ( V_329 != NULL )
F_192 ( V_329 ) ;
}
static int F_193 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
T_8 * V_239 = & V_66 -> V_257 ;
struct V_294 * V_329 = V_66 -> V_214 -> V_269 ;
int V_284 ;
if ( ( F_31 ( V_246 , & V_66 -> V_206 ) == 0 ) &&
( F_31 ( V_248 , & V_66 -> V_206 ) == 0 ) &&
( F_31 ( V_250 , & V_66 -> V_206 ) == 0 ) )
return - V_74 ;
V_284 = F_189 ( V_14 , V_239 , V_329 ) ;
F_194 ( V_66 , NULL , V_284 ) ;
if ( V_284 != V_343 ) {
if ( V_284 != - V_74 )
F_191 ( V_14 , V_239 , V_329 ) ;
F_149 ( V_246 , & V_66 -> V_206 ) ;
F_149 ( V_248 , & V_66 -> V_206 ) ;
F_149 ( V_250 , & V_66 -> V_206 ) ;
F_149 ( V_258 , & V_66 -> V_206 ) ;
}
return V_284 ;
}
static int F_195 ( struct V_203 * V_204 , struct V_65 * V_66 )
{
int V_284 ;
F_187 ( V_66 ) ;
V_284 = F_193 ( V_66 ) ;
if ( V_284 != V_343 )
V_284 = F_186 ( V_204 , V_66 ) ;
return V_284 ;
}
static inline void F_196 ( struct V_191 * V_266 , struct V_5 * V_6 )
{
if ( ( V_266 -> V_192 . V_344 [ 1 ] & V_345 ) &&
! ( V_6 -> V_235 & V_346 ) )
V_6 -> V_235 |= V_347 ;
if ( ( V_266 -> V_192 . V_344 [ 1 ] & V_348 ) &&
! ( V_6 -> V_235 & V_349 ) )
V_6 -> V_235 |= V_350 ;
}
static int F_197 ( struct V_191 * V_266 ,
T_5 V_205 ,
int V_206 ,
struct V_278 * V_279 )
{
struct V_203 * V_204 = V_266 -> V_214 ;
struct V_13 * V_14 = V_204 -> V_300 ;
struct V_4 * V_4 ;
struct V_65 * V_66 ;
unsigned int V_351 ;
int V_67 ;
V_351 = F_198 ( & V_204 -> V_352 ) ;
V_67 = F_178 ( V_266 ) ;
if ( V_67 != 0 )
goto V_132;
V_66 = F_140 ( V_266 ) ;
V_67 = F_71 ( V_66 ) ;
if ( F_43 ( V_66 ) )
goto V_132;
if ( V_14 -> V_95 & V_342 )
F_116 ( V_353 , & V_66 -> V_206 ) ;
V_4 = V_266 -> V_4 ;
if ( V_4 -> V_47 == NULL ) {
F_183 ( V_4 ) ;
V_4 = F_199 ( V_4 , F_200 ( V_66 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_266 -> V_4 ;
} else if ( V_4 != V_279 -> V_4 ) {
F_97 ( V_279 -> V_4 ) ;
V_279 -> V_4 = F_90 ( V_4 ) ;
}
F_201 ( V_4 ,
F_202 ( V_266 -> V_3 -> V_47 ) ) ;
}
V_67 = F_175 ( V_204 -> V_269 , V_266 , V_66 , V_205 , V_206 ) ;
if ( V_67 != 0 )
goto V_132;
V_279 -> V_66 = V_66 ;
if ( V_4 -> V_47 == V_66 -> V_2 ) {
F_203 ( V_279 ) ;
if ( F_204 ( & V_204 -> V_352 , V_351 ) )
F_22 ( V_14 , V_66 ) ;
}
V_132:
return V_67 ;
}
static int F_205 ( struct V_2 * V_3 ,
struct V_278 * V_279 ,
int V_206 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_354 )
{
struct V_203 * V_204 ;
struct V_65 * V_66 = NULL ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_191 * V_266 ;
struct V_4 * V_4 = V_279 -> V_4 ;
struct V_294 * V_329 = V_279 -> V_329 ;
struct V_355 * * V_356 = & V_279 -> V_357 ;
T_5 V_205 = V_279 -> V_243 & ( V_70 | V_217 | V_358 ) ;
enum V_183 V_184 = V_186 ;
struct V_1 * V_359 = NULL ;
int V_284 ;
V_284 = - V_127 ;
V_204 = F_206 ( V_14 , V_329 , V_360 ) ;
if ( V_204 == NULL ) {
F_8 ( L_24 ) ;
goto V_361;
}
V_284 = F_180 ( V_14 ) ;
if ( V_284 != 0 )
goto V_362;
if ( V_4 -> V_47 != NULL )
F_126 ( V_4 -> V_47 , V_205 ) ;
V_284 = - V_127 ;
if ( V_4 -> V_47 )
V_184 = V_185 ;
V_266 = F_83 ( V_4 , V_204 , V_205 , V_206 , V_6 ,
V_7 , V_184 , V_360 ) ;
if ( V_266 == NULL )
goto V_362;
if ( V_7 ) {
V_359 = F_87 ( V_14 , V_360 ) ;
if ( F_43 ( V_359 ) ) {
V_284 = F_71 ( V_359 ) ;
goto V_363;
}
}
if ( V_356 && V_14 -> V_15 [ 2 ] & V_364 ) {
V_266 -> V_193 . V_357 = F_207 () ;
if ( ! V_266 -> V_193 . V_357 )
goto V_212;
V_266 -> V_196 . V_231 = & V_365 [ 0 ] ;
}
if ( V_4 -> V_47 != NULL )
V_266 -> V_66 = F_138 ( V_4 -> V_47 , V_204 ) ;
V_284 = F_197 ( V_266 , V_205 , V_206 , V_279 ) ;
if ( V_284 != 0 )
goto V_212;
V_66 = V_279 -> V_66 ;
if ( ( V_266 -> V_196 . V_216 & V_218 ) &&
( V_266 -> V_196 . V_307 != V_310 ) ) {
F_196 ( V_266 , V_6 ) ;
F_81 ( V_266 -> V_192 . V_193 ) ;
V_284 = F_208 ( V_66 -> V_2 , V_329 ,
V_266 -> V_192 . V_193 , V_6 ,
V_66 , V_7 , V_359 ) ;
if ( V_284 == 0 ) {
F_209 ( V_66 -> V_2 , V_6 ) ;
F_210 ( V_66 -> V_2 , V_266 -> V_192 . V_193 ) ;
F_211 ( V_66 -> V_2 , V_266 -> V_192 . V_193 , V_359 ) ;
}
}
if ( V_266 -> V_340 )
* V_354 |= V_366 ;
if ( F_212 ( V_356 , V_266 -> V_193 . V_357 , V_14 ) )
* V_356 = V_266 -> V_193 . V_357 ;
else
F_96 ( V_266 -> V_193 . V_357 ) ;
V_266 -> V_193 . V_357 = NULL ;
F_95 ( V_359 ) ;
F_105 ( V_266 ) ;
F_102 ( V_204 ) ;
return 0 ;
V_212:
F_95 ( V_359 ) ;
V_363:
F_96 ( V_266 -> V_193 . V_357 ) ;
F_105 ( V_266 ) ;
V_362:
F_102 ( V_204 ) ;
V_361:
return V_284 ;
}
static struct V_65 * F_213 ( struct V_2 * V_3 ,
struct V_278 * V_279 ,
int V_206 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_354 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_61 V_62 = { } ;
struct V_65 * V_55 ;
int V_284 ;
do {
V_284 = F_205 ( V_3 , V_279 , V_206 , V_6 , V_7 , V_354 ) ;
V_55 = V_279 -> V_66 ;
F_214 ( V_279 , V_206 , V_284 ) ;
if ( V_284 == 0 )
break;
if ( V_284 == - V_367 ) {
F_215 ( L_5
L_25 ,
F_85 ( V_3 ) -> V_63 -> V_98 ) ;
V_62 . V_68 = 1 ;
continue;
}
if ( V_284 == - V_74 ) {
V_62 . V_68 = 1 ;
continue;
}
if ( V_284 == - V_131 ) {
V_62 . V_68 = 1 ;
continue;
}
if ( F_78 ( V_14 , V_284 , & V_62 ) )
continue;
V_55 = F_44 ( F_19 ( V_14 ,
V_284 , & V_62 ) ) ;
} while ( V_62 . V_68 );
return V_55 ;
}
static int F_216 ( struct V_2 * V_2 , struct V_294 * V_329 ,
struct V_368 * V_369 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_370 ,
struct V_1 * V_359 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_371 V_372 = {
. V_233 = F_93 ( V_2 ) ,
. V_373 = V_6 ,
. V_14 = V_14 ,
. V_230 = V_14 -> V_15 ,
. V_7 = V_370 ,
} ;
struct V_374 V_55 = {
. V_369 = V_369 ,
. V_7 = V_359 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_375 ] ,
. V_292 = & V_372 ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
unsigned long V_107 = V_154 ;
T_5 V_205 ;
bool V_376 ;
int V_284 ;
V_372 . V_230 = F_6 ( V_14 , V_370 ) ;
if ( V_370 )
V_372 . V_230 = F_6 ( V_14 , V_359 ) ;
F_81 ( V_369 ) ;
V_376 = ( V_6 -> V_235 & V_377 ) ? true : false ;
V_205 = V_376 ? V_217 : V_70 ;
if ( F_217 ( & V_372 . V_239 , V_2 , V_205 ) ) {
} else if ( V_376 && V_66 != NULL && F_218 ( V_66 ) ) {
struct V_378 V_379 = {
. V_380 = V_58 -> V_381 ,
. V_382 = V_58 -> V_383 ,
} ;
F_219 ( & V_372 . V_239 , V_66 , V_217 ,
& V_379 ) ;
} else
F_115 ( & V_372 . V_239 , & V_384 ) ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & V_372 . V_159 , & V_55 . V_160 , 1 ) ;
if ( V_284 == 0 && V_66 != NULL )
F_37 ( V_14 , V_107 ) ;
return V_284 ;
}
static int F_208 ( struct V_2 * V_2 , struct V_294 * V_329 ,
struct V_368 * V_369 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_370 ,
struct V_1 * V_359 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_216 ( V_2 , V_329 , V_369 , V_6 , V_66 , V_370 , V_359 ) ;
F_220 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_69 :
if ( ! ( V_6 -> V_235 & V_377 ) ) {
F_221 ( L_26
L_27
L_28
L_29 ,
V_14 -> V_63 -> V_98 ) ;
}
if ( V_66 && ! ( V_66 -> V_66 & V_217 ) ) {
V_8 = - V_385 ;
if ( V_6 -> V_235 & V_386 )
V_8 = - V_29 ;
goto V_132;
}
}
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
V_132:
return V_8 ;
}
static void F_222 ( void * V_157 )
{
struct V_387 * V_155 = V_157 ;
struct V_203 * V_204 = V_155 -> V_66 -> V_214 ;
struct V_241 * V_242 = V_155 -> V_66 -> V_2 -> V_388 ;
if ( V_155 -> V_389 )
F_223 ( V_155 -> V_66 -> V_2 ) ;
F_101 ( V_155 -> V_66 ) ;
F_100 ( V_155 -> V_372 . V_195 ) ;
F_102 ( V_204 ) ;
F_103 ( V_242 ) ;
F_96 ( V_155 ) ;
}
static void F_224 ( struct V_65 * V_66 ,
T_5 V_205 )
{
F_34 ( & V_66 -> V_214 -> V_261 ) ;
F_149 ( V_250 , & V_66 -> V_206 ) ;
switch ( V_205 & ( V_70 | V_217 ) ) {
case V_217 :
F_149 ( V_246 , & V_66 -> V_206 ) ;
break;
case V_70 :
F_149 ( V_248 , & V_66 -> V_206 ) ;
break;
case 0 :
F_149 ( V_246 , & V_66 -> V_206 ) ;
F_149 ( V_248 , & V_66 -> V_206 ) ;
F_149 ( V_258 , & V_66 -> V_206 ) ;
}
F_36 ( & V_66 -> V_214 -> V_261 ) ;
}
static void F_225 ( struct V_117 * V_118 , void * V_157 )
{
struct V_387 * V_155 = V_157 ;
struct V_65 * V_66 = V_155 -> V_66 ;
struct V_13 * V_14 = F_85 ( V_155 -> V_2 ) ;
F_8 ( L_30 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_155 -> V_55 . V_160 ) )
return;
F_226 ( V_66 , & V_155 -> V_372 , & V_155 -> V_55 , V_118 -> V_149 ) ;
switch ( V_118 -> V_149 ) {
case 0 :
if ( V_155 -> V_389 )
F_227 ( V_66 -> V_2 ,
V_155 -> V_390 ) ;
F_117 ( V_66 , & V_155 -> V_55 . V_239 , 0 ) ;
F_37 ( V_14 , V_155 -> V_107 ) ;
break;
case - V_73 :
case - V_76 :
case - V_94 :
case - V_74 :
case - V_75 :
if ( V_155 -> V_372 . V_205 == 0 )
break;
default:
if ( F_228 ( V_118 , V_14 , V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
goto V_391;
}
}
F_224 ( V_66 , V_155 -> V_372 . V_205 ) ;
V_391:
F_128 ( V_155 -> V_372 . V_195 ) ;
F_135 ( V_155 -> V_2 , V_155 -> V_55 . V_369 ) ;
F_8 ( L_31 , V_35 , V_118 -> V_149 ) ;
}
static void F_229 ( struct V_117 * V_118 , void * V_157 )
{
struct V_387 * V_155 = V_157 ;
struct V_65 * V_66 = V_155 -> V_66 ;
struct V_2 * V_2 = V_155 -> V_2 ;
int V_392 = 0 ;
F_8 ( L_30 , V_35 ) ;
if ( F_168 ( V_155 -> V_372 . V_195 , V_118 ) != 0 )
goto V_301;
V_118 -> V_305 . V_289 = & V_290 [ V_393 ] ;
V_155 -> V_372 . V_205 = V_70 | V_217 ;
F_34 ( & V_66 -> V_214 -> V_261 ) ;
if ( V_66 -> V_251 == 0 ) {
if ( V_66 -> V_247 == 0 ) {
V_392 |= F_31 ( V_246 , & V_66 -> V_206 ) ;
V_392 |= F_31 ( V_250 , & V_66 -> V_206 ) ;
V_155 -> V_372 . V_205 &= ~ V_70 ;
}
if ( V_66 -> V_249 == 0 ) {
V_392 |= F_31 ( V_248 , & V_66 -> V_206 ) ;
V_392 |= F_31 ( V_250 , & V_66 -> V_206 ) ;
V_155 -> V_372 . V_205 &= ~ V_217 ;
}
}
if ( ! F_218 ( V_66 ) )
V_392 = 0 ;
F_36 ( & V_66 -> V_214 -> V_261 ) ;
if ( ! V_392 ) {
goto V_302;
}
if ( V_155 -> V_372 . V_205 == 0 ) {
V_118 -> V_305 . V_289 = & V_290 [ V_394 ] ;
if ( V_155 -> V_389 &&
F_230 ( V_2 , & V_155 -> V_390 , V_118 ) ) {
F_128 ( V_155 -> V_372 . V_195 ) ;
goto V_301;
}
}
F_81 ( V_155 -> V_55 . V_369 ) ;
V_155 -> V_107 = V_154 ;
if ( F_63 ( F_85 ( V_2 ) ,
& V_155 -> V_372 . V_159 ,
& V_155 -> V_55 . V_160 ,
V_118 ) != 0 )
F_128 ( V_155 -> V_372 . V_195 ) ;
F_8 ( L_32 , V_35 ) ;
return;
V_302:
V_118 -> V_313 = NULL ;
V_301:
F_60 ( V_118 , & V_155 -> V_55 . V_160 ) ;
}
int F_231 ( struct V_65 * V_66 , T_6 V_208 , int V_395 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_387 * V_155 ;
struct V_203 * V_204 = V_66 -> V_214 ;
struct V_117 * V_118 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_394 ] ,
. V_294 = V_66 -> V_214 -> V_269 ,
} ;
struct V_163 V_295 = {
. V_165 = V_14 -> V_92 ,
. V_161 = & V_162 ,
. V_166 = & V_396 ,
. V_297 = V_298 ,
. V_206 = V_299 ,
} ;
int V_284 = - V_127 ;
F_232 ( V_14 -> V_63 , V_397 ,
& V_295 . V_165 , & V_162 ) ;
V_155 = F_86 ( sizeof( * V_155 ) , V_208 ) ;
if ( V_155 == NULL )
goto V_132;
F_38 ( & V_155 -> V_372 . V_159 , & V_155 -> V_55 . V_160 , 1 ) ;
V_155 -> V_2 = V_66 -> V_2 ;
V_155 -> V_66 = V_66 ;
V_155 -> V_372 . V_233 = F_93 ( V_66 -> V_2 ) ;
V_155 -> V_372 . V_239 = & V_66 -> V_257 ;
V_155 -> V_372 . V_195 = F_88 ( & V_66 -> V_214 -> V_211 , V_208 ) ;
if ( V_155 -> V_372 . V_195 == NULL )
goto V_398;
V_155 -> V_372 . V_205 = 0 ;
V_155 -> V_372 . V_230 = V_14 -> V_399 ;
V_155 -> V_55 . V_369 = & V_155 -> V_369 ;
V_155 -> V_55 . V_195 = V_155 -> V_372 . V_195 ;
V_155 -> V_55 . V_14 = V_14 ;
V_155 -> V_389 = F_233 ( V_66 -> V_2 ) ;
F_89 ( V_155 -> V_2 -> V_388 ) ;
V_162 . V_292 = & V_155 -> V_372 ;
V_162 . V_293 = & V_155 -> V_55 ;
V_295 . V_169 = V_155 ;
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_284 = 0 ;
if ( V_395 )
V_284 = F_108 ( V_118 ) ;
F_72 ( V_118 ) ;
return V_284 ;
V_398:
F_96 ( V_155 ) ;
V_132:
F_101 ( V_66 ) ;
F_102 ( V_204 ) ;
return V_284 ;
}
static struct V_2 *
F_234 ( struct V_2 * V_3 , struct V_278 * V_279 ,
int V_216 , struct V_5 * V_400 , int * V_354 )
{
struct V_65 * V_66 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_279 -> V_4 , V_400 , & V_17 ) ;
V_66 = F_213 ( V_3 , V_279 , V_216 , V_400 , V_7 , V_354 ) ;
F_4 ( V_7 ) ;
if ( F_43 ( V_66 ) )
return F_235 ( V_66 ) ;
return V_66 -> V_2 ;
}
static void F_236 ( struct V_278 * V_279 , int V_401 )
{
if ( V_279 -> V_66 == NULL )
return;
if ( V_401 )
F_237 ( V_279 -> V_66 , V_279 -> V_243 ) ;
else
F_147 ( V_279 -> V_66 , V_279 -> V_243 ) ;
}
static int F_238 ( struct V_13 * V_14 , struct V_402 * V_403 )
{
struct V_404 args = {
. V_403 = V_403 ,
} ;
struct V_405 V_55 = {} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_406 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
int V_284 ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
if ( V_284 == 0 ) {
switch ( V_14 -> V_63 -> V_407 ) {
case 0 :
V_55 . V_15 [ 1 ] &= V_408 ;
V_55 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_55 . V_15 [ 2 ] &= V_409 ;
break;
case 2 :
V_55 . V_15 [ 2 ] &= V_410 ;
}
memcpy ( V_14 -> V_15 , V_55 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_95 &= ~ ( V_411 | V_412 |
V_413 | V_414 |
V_415 | V_416 | V_417 |
V_418 | V_419 |
V_420 | V_421 |
V_9 ) ;
if ( V_55 . V_15 [ 0 ] & V_422 )
V_14 -> V_95 |= V_411 ;
if ( V_55 . V_423 != 0 )
V_14 -> V_95 |= V_412 ;
if ( V_55 . V_424 != 0 )
V_14 -> V_95 |= V_413 ;
if ( V_55 . V_15 [ 0 ] & V_46 )
V_14 -> V_95 |= V_414 ;
if ( V_55 . V_15 [ 1 ] & V_425 )
V_14 -> V_95 |= V_415 ;
if ( V_55 . V_15 [ 1 ] & V_426 )
V_14 -> V_95 |= V_416 ;
if ( V_55 . V_15 [ 1 ] & V_427 )
V_14 -> V_95 |= V_417 ;
if ( V_55 . V_15 [ 1 ] & V_428 )
V_14 -> V_95 |= V_418 ;
if ( V_55 . V_15 [ 1 ] & V_345 )
V_14 -> V_95 |= V_419 ;
if ( V_55 . V_15 [ 1 ] & V_429 )
V_14 -> V_95 |= V_420 ;
if ( V_55 . V_15 [ 1 ] & V_348 )
V_14 -> V_95 |= V_421 ;
#ifdef F_239
if ( V_55 . V_15 [ 2 ] & V_430 )
V_14 -> V_95 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_55 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_430 ;
memcpy ( V_14 -> V_399 , V_55 . V_15 , sizeof( V_14 -> V_399 ) ) ;
V_14 -> V_399 [ 0 ] &= V_431 | V_432 ;
V_14 -> V_399 [ 1 ] &= V_429 | V_348 ;
V_14 -> V_399 [ 2 ] = 0 ;
V_14 -> V_433 = V_55 . V_433 ;
V_14 -> V_434 = V_55 . V_434 ;
}
return V_284 ;
}
int F_240 ( struct V_13 * V_14 , struct V_402 * V_403 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_238 ( V_14 , V_403 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_241 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_436 )
{
T_1 V_230 [ 3 ] ;
struct V_437 args = {
. V_230 = V_230 ,
} ;
struct V_438 V_55 = {
. V_14 = V_14 ,
. V_369 = V_436 -> V_369 ,
. V_233 = V_403 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_439 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
V_230 [ 0 ] = V_232 [ 0 ] ;
V_230 [ 1 ] = V_232 [ 1 ] ;
V_230 [ 2 ] = V_232 [ 2 ] & ~ V_430 ;
F_81 ( V_436 -> V_369 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
}
static int F_242 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_436 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_241 ( V_14 , V_403 , V_436 ) ;
F_243 ( V_14 , V_403 , V_436 -> V_369 , V_8 ) ;
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
static int F_244 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_436 , T_4 V_101 )
{
struct V_440 V_441 = {
. V_442 = V_101 ,
} ;
struct V_443 * V_444 ;
int V_67 ;
V_444 = F_245 ( & V_441 , V_14 -> V_92 ) ;
if ( F_43 ( V_444 ) ) {
V_67 = - V_29 ;
goto V_132;
}
V_67 = F_242 ( V_14 , V_403 , V_436 ) ;
V_132:
return V_67 ;
}
static int F_246 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_436 )
{
static const T_4 V_445 [] = {
V_106 ,
V_105 ,
V_446 ,
V_447 ,
V_448 ,
} ;
int V_284 = - V_24 ;
T_9 V_449 ;
if ( V_14 -> V_450 . V_451 > 0 ) {
for ( V_449 = 0 ; V_449 < V_14 -> V_450 . V_451 ; V_449 ++ ) {
V_284 = F_244 ( V_14 , V_403 , V_436 ,
V_14 -> V_450 . V_452 [ V_449 ] ) ;
if ( V_284 == - V_22 || V_284 == - V_29 )
continue;
break;
}
} else {
for ( V_449 = 0 ; V_449 < F_247 ( V_445 ) ; V_449 ++ ) {
V_284 = F_244 ( V_14 , V_403 , V_436 ,
V_445 [ V_449 ] ) ;
if ( V_284 == - V_22 || V_284 == - V_29 )
continue;
break;
}
}
if ( V_284 == - V_29 )
V_284 = - V_24 ;
return V_284 ;
}
static int F_248 ( struct V_13 * V_14 ,
struct V_402 * V_403 , struct V_435 * V_436 )
{
int V_453 = V_14 -> V_63 -> V_407 ;
return V_454 [ V_453 ] -> F_249 ( V_14 , V_403 , V_436 ) ;
}
int F_250 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_436 ,
bool V_455 )
{
int V_284 ;
switch ( V_455 ) {
case false :
V_284 = F_242 ( V_14 , V_403 , V_436 ) ;
if ( V_284 != - V_22 )
break;
default:
V_284 = F_248 ( V_14 , V_403 , V_436 ) ;
}
if ( V_284 == 0 )
V_284 = F_240 ( V_14 , V_403 ) ;
if ( V_284 == 0 )
V_284 = F_251 ( V_14 , V_403 , V_436 ) ;
return F_7 ( V_284 ) ;
}
static int F_252 ( struct V_13 * V_14 , struct V_402 * V_456 ,
struct V_435 * V_436 )
{
int error ;
struct V_368 * V_369 = V_436 -> V_369 ;
struct V_1 * V_7 = NULL ;
error = F_240 ( V_14 , V_456 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
return error ;
}
V_7 = F_87 ( V_14 , V_360 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
error = F_253 ( V_14 , V_456 , V_369 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_34 , - error ) ;
goto V_212;
}
if ( V_369 -> V_275 & V_457 &&
! F_254 ( & V_14 -> V_458 , & V_369 -> V_458 ) )
memcpy ( & V_14 -> V_458 , & V_369 -> V_458 , sizeof( V_14 -> V_458 ) ) ;
V_212:
F_95 ( V_7 ) ;
return error ;
}
static int F_255 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_459 * V_229 , struct V_368 * V_369 ,
struct V_402 * V_403 )
{
int V_284 = - V_127 ;
struct V_460 * V_460 = NULL ;
struct V_461 * V_462 = NULL ;
V_460 = F_256 ( V_360 ) ;
if ( V_460 == NULL )
goto V_132;
V_462 = F_257 ( sizeof( struct V_461 ) , V_360 ) ;
if ( V_462 == NULL )
goto V_132;
V_284 = F_258 ( V_92 , V_3 , V_229 , V_462 , V_460 ) ;
if ( V_284 != 0 )
goto V_132;
if ( F_254 ( & F_85 ( V_3 ) -> V_458 , & V_462 -> V_369 . V_458 ) ) {
F_8 ( L_35
L_36 , V_35 , V_229 -> V_229 ) ;
V_284 = - V_78 ;
goto V_132;
}
F_259 ( & V_462 -> V_369 ) ;
memcpy ( V_369 , & V_462 -> V_369 , sizeof( struct V_368 ) ) ;
memset ( V_403 , 0 , sizeof( struct V_402 ) ) ;
V_132:
if ( V_460 )
F_260 ( V_460 ) ;
F_96 ( V_462 ) ;
return V_284 ;
}
static int F_179 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_368 * V_369 , struct V_1 * V_7 )
{
struct V_463 args = {
. V_233 = V_403 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_464 V_55 = {
. V_369 = V_369 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_465 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
args . V_230 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_369 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
}
static int F_253 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_368 * V_369 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_179 ( V_14 , V_403 , V_369 , V_7 ) ;
F_261 ( V_14 , V_403 , V_369 , V_8 ) ;
V_8 = F_19 ( V_14 , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_262 ( struct V_4 * V_4 , struct V_368 * V_369 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = V_4 -> V_47 ;
struct V_294 * V_329 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_1 * V_7 = NULL ;
int V_284 ;
if ( F_263 ( V_2 ) )
F_264 ( V_2 ) ;
F_81 ( V_369 ) ;
if ( V_6 -> V_235 & V_386 )
V_6 -> V_235 &= ~ ( V_350 | V_466 ) ;
if ( ( V_6 -> V_235 & ~ ( V_467 | V_386 ) ) == 0 )
return 0 ;
if ( V_6 -> V_235 & V_467 ) {
struct V_278 * V_279 ;
V_279 = F_265 ( V_6 -> V_468 ) ;
if ( V_279 ) {
V_329 = V_279 -> V_329 ;
V_66 = V_279 -> V_66 ;
}
}
V_7 = F_87 ( F_85 ( V_2 ) , V_360 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
V_284 = F_208 ( V_2 , V_329 , V_369 , V_6 , V_66 , NULL , V_7 ) ;
if ( V_284 == 0 ) {
F_209 ( V_2 , V_6 ) ;
F_211 ( V_2 , V_369 , V_7 ) ;
}
F_95 ( V_7 ) ;
return V_284 ;
}
static int F_266 ( struct V_52 * V_53 , struct V_2 * V_3 ,
const struct V_459 * V_229 , struct V_402 * V_403 ,
struct V_368 * V_369 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
int V_284 ;
struct V_469 args = {
. V_230 = V_14 -> V_15 ,
. V_470 = F_93 ( V_3 ) ,
. V_229 = V_229 ,
} ;
struct V_438 V_55 = {
. V_14 = V_14 ,
. V_369 = V_369 ,
. V_7 = V_7 ,
. V_233 = V_403 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_471 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
args . V_230 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_369 ) ;
F_8 ( L_37 , V_229 -> V_229 ) ;
V_284 = F_73 ( V_53 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
F_8 ( L_38 , V_284 ) ;
return V_284 ;
}
static void F_267 ( struct V_368 * V_369 )
{
V_369 -> V_275 |= V_314 | V_472 |
V_473 | V_474 ;
V_369 -> V_243 = V_319 | V_475 | V_476 ;
V_369 -> V_477 = 2 ;
}
static int F_268 ( struct V_52 * * V_53 , struct V_2 * V_3 ,
struct V_459 * V_229 , struct V_402 * V_403 ,
struct V_368 * V_369 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
struct V_52 * V_92 = * V_53 ;
int V_8 ;
do {
V_8 = F_266 ( V_92 , V_3 , V_229 , V_403 , V_369 , V_7 ) ;
F_269 ( V_3 , V_229 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_280 ;
goto V_132;
case - V_78 :
V_8 = F_255 ( V_92 , V_3 , V_229 , V_369 , V_403 ) ;
goto V_132;
case - V_22 :
V_8 = - V_24 ;
if ( V_92 != * V_53 )
goto V_132;
V_92 = F_270 ( V_92 , V_3 , V_229 ) ;
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
static int F_272 ( struct V_2 * V_3 , struct V_459 * V_229 ,
struct V_402 * V_403 , struct V_368 * V_369 ,
struct V_1 * V_7 )
{
int V_284 ;
struct V_52 * V_92 = F_273 ( V_3 ) ;
V_284 = F_268 ( & V_92 , V_3 , V_229 , V_403 , V_369 , V_7 ) ;
if ( V_92 != F_273 ( V_3 ) ) {
F_271 ( V_92 ) ;
F_267 ( V_369 ) ;
}
return V_284 ;
}
struct V_52 *
F_274 ( struct V_2 * V_3 , struct V_459 * V_229 ,
struct V_402 * V_403 , struct V_368 * V_369 )
{
struct V_52 * V_92 = F_273 ( V_3 ) ;
int V_284 ;
V_284 = F_268 ( & V_92 , V_3 , V_229 , V_403 , V_369 , NULL ) ;
if ( V_284 < 0 )
return F_44 ( V_284 ) ;
return ( V_92 == F_273 ( V_3 ) ) ? F_275 ( V_92 ) : V_92 ;
}
static int F_276 ( struct V_2 * V_2 , struct V_331 * V_478 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_479 args = {
. V_233 = F_93 ( V_2 ) ,
. V_230 = V_14 -> V_399 ,
} ;
struct V_480 V_55 = {
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_481 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_478 -> V_329 ,
} ;
int V_243 = V_478 -> V_333 ;
int V_284 = 0 ;
if ( V_243 & V_337 )
args . V_200 |= V_219 ;
if ( F_277 ( V_2 -> V_482 ) ) {
if ( V_243 & V_483 )
args . V_200 |= V_220 | V_221 | V_484 ;
if ( V_243 & V_336 )
args . V_200 |= V_485 ;
} else {
if ( V_243 & V_483 )
args . V_200 |= V_220 | V_221 ;
if ( V_243 & V_336 )
args . V_200 |= V_222 ;
}
V_55 . V_369 = F_278 () ;
if ( V_55 . V_369 == NULL )
return - V_127 ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
if ( ! V_284 ) {
F_176 ( V_478 , V_55 . V_200 ) ;
F_135 ( V_2 , V_55 . V_369 ) ;
}
F_279 ( V_55 . V_369 ) ;
return V_284 ;
}
static int F_280 ( struct V_2 * V_2 , struct V_331 * V_478 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_276 ( V_2 , V_478 ) ;
F_281 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_282 ( struct V_2 * V_2 , struct V_460 * V_460 ,
unsigned int V_50 , unsigned int V_486 )
{
struct V_487 args = {
. V_233 = F_93 ( V_2 ) ,
. V_50 = V_50 ,
. V_486 = V_486 ,
. V_43 = & V_460 ,
} ;
struct V_488 V_55 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_489 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
return F_73 ( F_85 ( V_2 ) -> V_92 , F_85 ( V_2 ) , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
}
static int F_283 ( struct V_2 * V_2 , struct V_460 * V_460 ,
unsigned int V_50 , unsigned int V_486 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_282 ( V_2 , V_460 , V_50 , V_486 ) ;
F_284 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_285 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_206 )
{
struct V_1 V_17 , * V_370 = NULL ;
struct V_278 * V_279 ;
struct V_65 * V_66 ;
int V_354 = 0 ;
int V_284 = 0 ;
V_279 = F_286 ( V_4 , V_70 ) ;
if ( F_43 ( V_279 ) )
return F_71 ( V_279 ) ;
V_370 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_287 () ;
V_66 = F_213 ( V_3 , V_279 , V_206 , V_6 , V_370 , & V_354 ) ;
if ( F_43 ( V_66 ) ) {
V_284 = F_71 ( V_66 ) ;
goto V_132;
}
V_132:
F_4 ( V_370 ) ;
F_155 ( V_279 ) ;
return V_284 ;
}
static int F_288 ( struct V_2 * V_3 , struct V_459 * V_229 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_490 args = {
. V_233 = F_93 ( V_3 ) ,
. V_229 = * V_229 ,
} ;
struct V_491 V_55 = {
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_492 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
int V_284 ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 1 ) ;
if ( V_284 == 0 )
F_74 ( V_3 , & V_55 . V_171 ) ;
return V_284 ;
}
static int F_289 ( struct V_2 * V_3 , struct V_459 * V_229 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_288 ( V_3 , V_229 ) ;
F_290 ( V_3 , V_229 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_291 ( struct V_161 * V_162 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_490 * args = V_162 -> V_292 ;
struct V_491 * V_55 = V_162 -> V_293 ;
V_55 -> V_14 = V_14 ;
V_162 -> V_289 = & V_290 [ V_492 ] ;
F_38 ( & args -> V_159 , & V_55 -> V_160 , 1 ) ;
F_81 ( V_55 -> V_493 ) ;
}
static void F_292 ( struct V_117 * V_118 , struct V_494 * V_157 )
{
F_63 ( F_85 ( V_157 -> V_3 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_55 . V_160 ,
V_118 ) ;
}
static int F_293 ( struct V_117 * V_118 , struct V_2 * V_3 )
{
struct V_494 * V_157 = V_118 -> V_495 ;
struct V_491 * V_55 = & V_157 -> V_55 ;
if ( ! F_60 ( V_118 , & V_55 -> V_160 ) )
return 0 ;
if ( F_228 ( V_118 , V_55 -> V_14 , NULL ) == - V_131 )
return 0 ;
F_74 ( V_3 , & V_55 -> V_171 ) ;
return 1 ;
}
static void F_294 ( struct V_161 * V_162 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_496 * V_372 = V_162 -> V_292 ;
struct V_497 * V_55 = V_162 -> V_293 ;
V_162 -> V_289 = & V_290 [ V_498 ] ;
V_55 -> V_14 = V_14 ;
F_38 ( & V_372 -> V_159 , & V_55 -> V_160 , 1 ) ;
}
static void F_295 ( struct V_117 * V_118 , struct V_499 * V_157 )
{
F_63 ( F_85 ( V_157 -> V_500 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_55 . V_160 ,
V_118 ) ;
}
static int F_296 ( struct V_117 * V_118 , struct V_2 * V_500 ,
struct V_2 * V_501 )
{
struct V_499 * V_157 = V_118 -> V_495 ;
struct V_497 * V_55 = & V_157 -> V_55 ;
if ( ! F_60 ( V_118 , & V_55 -> V_160 ) )
return 0 ;
if ( F_228 ( V_118 , V_55 -> V_14 , NULL ) == - V_131 )
return 0 ;
F_74 ( V_500 , & V_55 -> V_502 ) ;
F_74 ( V_501 , & V_55 -> V_503 ) ;
return 1 ;
}
static int F_297 ( struct V_2 * V_500 , struct V_459 * V_504 ,
struct V_2 * V_501 , struct V_459 * V_505 )
{
struct V_13 * V_14 = F_85 ( V_500 ) ;
struct V_496 V_372 = {
. V_500 = F_93 ( V_500 ) ,
. V_501 = F_93 ( V_501 ) ,
. V_504 = V_504 ,
. V_505 = V_505 ,
} ;
struct V_497 V_55 = {
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_498 ] ,
. V_292 = & V_372 ,
. V_293 = & V_55 ,
} ;
int V_284 = - V_127 ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & V_372 . V_159 , & V_55 . V_160 , 1 ) ;
if ( ! V_284 ) {
F_74 ( V_500 , & V_55 . V_502 ) ;
F_74 ( V_501 , & V_55 . V_503 ) ;
}
return V_284 ;
}
static int F_298 ( struct V_2 * V_500 , struct V_459 * V_504 ,
struct V_2 * V_501 , struct V_459 * V_505 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_297 ( V_500 , V_504 ,
V_501 , V_505 ) ;
F_299 ( V_500 , V_504 , V_501 , V_505 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_500 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_300 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_459 * V_229 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_506 V_372 = {
. V_233 = F_93 ( V_2 ) ,
. V_470 = F_93 ( V_3 ) ,
. V_229 = V_229 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_507 V_55 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_508 ] ,
. V_292 = & V_372 ,
. V_293 = & V_55 ,
} ;
int V_284 = - V_127 ;
V_55 . V_369 = F_278 () ;
if ( V_55 . V_369 == NULL )
goto V_132;
V_55 . V_7 = F_87 ( V_14 , V_360 ) ;
if ( F_43 ( V_55 . V_7 ) ) {
V_284 = F_71 ( V_55 . V_7 ) ;
goto V_132;
}
V_372 . V_230 = F_6 ( V_14 , V_55 . V_7 ) ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & V_372 . V_159 , & V_55 . V_160 , 1 ) ;
if ( ! V_284 ) {
F_74 ( V_3 , & V_55 . V_171 ) ;
V_284 = F_210 ( V_2 , V_55 . V_369 ) ;
if ( ! V_284 )
F_211 ( V_2 , V_55 . V_369 , V_55 . V_7 ) ;
}
F_95 ( V_55 . V_7 ) ;
V_132:
F_279 ( V_55 . V_369 ) ;
return V_284 ;
}
static int F_301 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_459 * V_229 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( F_85 ( V_2 ) ,
F_300 ( V_2 , V_3 , V_229 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static struct V_509 * F_302 ( struct V_2 * V_3 ,
struct V_459 * V_229 , struct V_5 * V_6 , T_1 V_510 )
{
struct V_509 * V_157 ;
V_157 = F_86 ( sizeof( * V_157 ) , V_360 ) ;
if ( V_157 != NULL ) {
struct V_13 * V_14 = F_85 ( V_3 ) ;
V_157 -> V_7 = F_87 ( V_14 , V_360 ) ;
if ( F_43 ( V_157 -> V_7 ) )
goto V_288;
V_157 -> V_162 . V_289 = & V_290 [ V_511 ] ;
V_157 -> V_162 . V_292 = & V_157 -> V_372 ;
V_157 -> V_162 . V_293 = & V_157 -> V_55 ;
V_157 -> V_372 . V_470 = F_93 ( V_3 ) ;
V_157 -> V_372 . V_14 = V_14 ;
V_157 -> V_372 . V_229 = V_229 ;
V_157 -> V_372 . V_207 = V_6 ;
V_157 -> V_372 . V_510 = V_510 ;
V_157 -> V_372 . V_230 = F_6 ( V_14 , V_157 -> V_7 ) ;
V_157 -> V_55 . V_14 = V_14 ;
V_157 -> V_55 . V_233 = & V_157 -> V_233 ;
V_157 -> V_55 . V_369 = & V_157 -> V_369 ;
V_157 -> V_55 . V_7 = V_157 -> V_7 ;
F_81 ( V_157 -> V_55 . V_369 ) ;
}
return V_157 ;
V_288:
F_96 ( V_157 ) ;
return NULL ;
}
static int F_303 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_509 * V_157 )
{
int V_284 = F_73 ( F_85 ( V_3 ) -> V_92 , F_85 ( V_3 ) , & V_157 -> V_162 ,
& V_157 -> V_372 . V_159 , & V_157 -> V_55 . V_160 , 1 ) ;
if ( V_284 == 0 ) {
F_74 ( V_3 , & V_157 -> V_55 . V_512 ) ;
V_284 = F_304 ( V_4 , V_157 -> V_55 . V_233 , V_157 -> V_55 . V_369 , V_157 -> V_55 . V_7 ) ;
}
return V_284 ;
}
static void F_305 ( struct V_509 * V_157 )
{
F_95 ( V_157 -> V_7 ) ;
F_96 ( V_157 ) ;
}
static int F_306 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_460 * V_460 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_509 * V_157 ;
int V_284 = - V_513 ;
if ( V_12 > V_514 )
goto V_132;
V_284 = - V_127 ;
V_157 = F_302 ( V_3 , & V_4 -> V_11 , V_6 , V_515 ) ;
if ( V_157 == NULL )
goto V_132;
V_157 -> V_162 . V_289 = & V_290 [ V_516 ] ;
V_157 -> V_372 . V_237 . V_517 . V_43 = & V_460 ;
V_157 -> V_372 . V_237 . V_517 . V_12 = V_12 ;
V_157 -> V_372 . V_7 = V_7 ;
V_284 = F_303 ( V_3 , V_4 , V_157 ) ;
F_305 ( V_157 ) ;
V_132:
return V_284 ;
}
static int F_307 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_460 * V_460 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_306 ( V_3 , V_4 , V_460 , V_12 , V_6 , V_7 ) ;
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
struct V_509 * V_157 ;
int V_284 = - V_127 ;
V_157 = F_302 ( V_3 , & V_4 -> V_11 , V_6 , V_518 ) ;
if ( V_157 == NULL )
goto V_132;
V_157 -> V_372 . V_7 = V_7 ;
V_284 = F_303 ( V_3 , V_4 , V_157 ) ;
F_305 ( V_157 ) ;
V_132:
return V_284 ;
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
static int F_312 ( struct V_4 * V_4 , struct V_294 * V_329 ,
T_2 V_37 , struct V_460 * * V_43 , unsigned int V_51 , int V_519 )
{
struct V_2 * V_3 = V_4 -> V_47 ;
struct V_39 args = {
. V_233 = F_93 ( V_3 ) ,
. V_43 = V_43 ,
. V_50 = 0 ,
. V_51 = V_51 ,
. V_230 = F_85 ( V_4 -> V_47 ) -> V_15 ,
. V_519 = V_519 ,
} ;
struct V_520 V_55 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_521 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
int V_284 ;
F_8 ( L_39 , V_35 ,
V_4 ,
( unsigned long long ) V_37 ) ;
F_9 ( V_37 , F_75 ( V_3 ) -> V_522 , V_4 , & args ) ;
V_55 . V_50 = args . V_50 ;
V_284 = F_73 ( F_85 ( V_3 ) -> V_92 , F_85 ( V_3 ) , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
if ( V_284 >= 0 ) {
memcpy ( F_75 ( V_3 ) -> V_522 , V_55 . V_38 . V_157 , V_523 ) ;
V_284 += args . V_50 ;
}
F_313 ( V_3 ) ;
F_8 ( L_40 , V_35 , V_284 ) ;
return V_284 ;
}
static int F_314 ( struct V_4 * V_4 , struct V_294 * V_329 ,
T_2 V_37 , struct V_460 * * V_43 , unsigned int V_51 , int V_519 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_312 ( V_4 , V_329 , V_37 ,
V_43 , V_51 , V_519 ) ;
F_315 ( V_4 -> V_47 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_4 -> V_47 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_316 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_524 )
{
struct V_509 * V_157 ;
int V_243 = V_6 -> V_10 ;
int V_284 = - V_127 ;
V_157 = F_302 ( V_3 , & V_4 -> V_11 , V_6 , V_525 ) ;
if ( V_157 == NULL )
goto V_132;
if ( F_317 ( V_243 ) )
V_157 -> V_372 . V_510 = V_526 ;
else if ( F_318 ( V_243 ) ) {
V_157 -> V_372 . V_510 = V_527 ;
V_157 -> V_372 . V_237 . V_528 . V_529 = F_319 ( V_524 ) ;
V_157 -> V_372 . V_237 . V_528 . V_530 = F_320 ( V_524 ) ;
}
else if ( F_321 ( V_243 ) ) {
V_157 -> V_372 . V_510 = V_531 ;
V_157 -> V_372 . V_237 . V_528 . V_529 = F_319 ( V_524 ) ;
V_157 -> V_372 . V_237 . V_528 . V_530 = F_320 ( V_524 ) ;
} else if ( ! F_322 ( V_243 ) ) {
V_284 = - V_27 ;
goto V_288;
}
V_157 -> V_372 . V_7 = V_7 ;
V_284 = F_303 ( V_3 , V_4 , V_157 ) ;
V_288:
F_305 ( V_157 ) ;
V_132:
return V_284 ;
}
static int F_323 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_524 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_287 () ;
do {
V_8 = F_316 ( V_3 , V_4 , V_6 , V_7 , V_524 ) ;
F_324 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_325 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_532 * V_533 )
{
struct V_534 args = {
. V_233 = V_403 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_535 V_55 = {
. V_533 = V_533 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_536 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
F_81 ( V_533 -> V_369 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
}
static int F_326 ( struct V_13 * V_14 , struct V_402 * V_403 , struct V_532 * V_533 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_325 ( V_14 , V_403 , V_533 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_327 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_537 )
{
struct V_538 args = {
. V_233 = V_403 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_539 V_55 = {
. V_537 = V_537 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_540 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
return F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
}
static int F_251 ( struct V_13 * V_14 , struct V_402 * V_403 , struct V_435 * V_537 )
{
struct V_61 V_62 = { } ;
unsigned long V_541 = V_154 ;
int V_8 ;
do {
V_8 = F_327 ( V_14 , V_403 , V_537 ) ;
F_328 ( V_14 , V_403 , V_537 -> V_369 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_63 * V_64 = V_14 -> V_63 ;
F_34 ( & V_64 -> V_108 ) ;
V_64 -> V_542 = V_537 -> V_543 * V_89 ;
V_64 -> V_109 = V_541 ;
F_36 ( & V_64 -> V_108 ) ;
break;
}
V_8 = F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_329 ( struct V_13 * V_14 , struct V_402 * V_403 , struct V_435 * V_537 )
{
int error ;
F_81 ( V_537 -> V_369 ) ;
error = F_251 ( V_14 , V_403 , V_537 ) ;
if ( error == 0 ) {
V_14 -> V_544 = V_537 -> V_545 ;
F_330 ( V_14 , V_403 , V_537 -> V_546 ) ;
}
return error ;
}
static int F_331 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_547 * V_548 )
{
struct V_549 args = {
. V_233 = V_403 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_550 V_55 = {
. V_548 = V_548 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_551 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
if ( ( args . V_230 [ 0 ] & V_552 [ 0 ] ) == 0 ) {
memset ( V_548 , 0 , sizeof( * V_548 ) ) ;
return 0 ;
}
F_81 ( V_548 -> V_369 ) ;
return F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
}
static int F_332 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_547 * V_548 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_331 ( V_14 , V_403 , V_548 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
int F_333 ( T_8 * V_239 ,
const struct V_278 * V_279 ,
const struct V_553 * V_554 ,
T_5 V_205 )
{
const struct V_378 * V_379 = NULL ;
if ( V_554 != NULL )
V_379 = & V_554 -> V_379 ;
return F_219 ( V_239 , V_279 -> V_66 , V_205 , V_379 ) ;
}
static bool F_334 ( T_8 * V_239 ,
const struct V_278 * V_279 ,
const struct V_553 * V_554 ,
T_5 V_205 )
{
T_8 V_555 ;
if ( F_333 ( & V_555 , V_279 , V_554 , V_205 ) )
return false ;
return F_124 ( V_239 , & V_555 ) ;
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
void F_336 ( struct V_556 * V_157 )
{
F_313 ( V_157 -> V_557 -> V_2 ) ;
}
static int F_337 ( struct V_117 * V_118 , struct V_556 * V_157 )
{
struct V_13 * V_14 = F_85 ( V_157 -> V_557 -> V_2 ) ;
F_338 ( V_157 , V_118 -> V_149 ) ;
if ( F_228 ( V_118 , V_14 , V_157 -> args . V_558 -> V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
F_336 ( V_157 ) ;
if ( V_118 -> V_149 > 0 )
F_37 ( V_14 , V_157 -> V_107 ) ;
return 0 ;
}
static bool F_339 ( struct V_117 * V_118 ,
struct V_559 * args )
{
if ( ! F_335 ( V_118 -> V_149 ) ||
F_334 ( & args -> V_239 ,
args -> V_558 ,
args -> V_560 ,
V_70 ) )
return false ;
F_57 ( V_118 ) ;
return true ;
}
static int F_340 ( struct V_117 * V_118 , struct V_556 * V_157 )
{
F_8 ( L_12 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_157 -> V_55 . V_160 ) )
return - V_131 ;
if ( F_339 ( V_118 , & V_157 -> args ) )
return - V_131 ;
return V_157 -> V_561 ? V_157 -> V_561 ( V_118 , V_157 ) :
F_337 ( V_118 , V_157 ) ;
}
static void F_341 ( struct V_556 * V_157 , struct V_161 * V_162 )
{
V_157 -> V_107 = V_154 ;
V_157 -> V_561 = F_337 ;
V_162 -> V_289 = & V_290 [ V_562 ] ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_55 . V_160 , 0 ) ;
}
static int F_342 ( struct V_117 * V_118 , struct V_556 * V_157 )
{
if ( F_63 ( F_85 ( V_157 -> V_557 -> V_2 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_55 . V_160 ,
V_118 ) )
return 0 ;
if ( F_333 ( & V_157 -> args . V_239 , V_157 -> args . V_558 ,
V_157 -> args . V_560 , V_70 ) == - V_36 )
return - V_36 ;
if ( F_343 ( F_31 ( V_563 , & V_157 -> args . V_558 -> V_206 ) ) )
return - V_36 ;
return 0 ;
}
static int F_344 ( struct V_117 * V_118 , struct V_564 * V_157 )
{
struct V_2 * V_2 = V_157 -> V_557 -> V_2 ;
F_345 ( V_157 , V_118 -> V_149 ) ;
if ( F_228 ( V_118 , F_85 ( V_2 ) , V_157 -> args . V_558 -> V_66 ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
if ( V_118 -> V_149 >= 0 ) {
F_37 ( F_85 ( V_2 ) , V_157 -> V_107 ) ;
F_346 ( V_2 , & V_157 -> V_369 ) ;
}
return 0 ;
}
static bool F_347 ( struct V_117 * V_118 ,
struct V_565 * args )
{
if ( ! F_335 ( V_118 -> V_149 ) ||
F_334 ( & args -> V_239 ,
args -> V_558 ,
args -> V_560 ,
V_217 ) )
return false ;
F_57 ( V_118 ) ;
return true ;
}
static int F_348 ( struct V_117 * V_118 , struct V_564 * V_157 )
{
if ( ! F_60 ( V_118 , & V_157 -> V_55 . V_160 ) )
return - V_131 ;
if ( F_347 ( V_118 , & V_157 -> args ) )
return - V_131 ;
return V_157 -> V_566 ? V_157 -> V_566 ( V_118 , V_157 ) :
F_344 ( V_118 , V_157 ) ;
}
static
bool F_349 ( const struct V_564 * V_157 )
{
const struct V_567 * V_568 = V_157 -> V_557 ;
if ( V_157 -> V_569 != NULL || V_568 -> V_570 != NULL )
return false ;
return F_20 ( V_568 -> V_2 , V_70 ) == 0 ;
}
static void F_350 ( struct V_564 * V_157 , struct V_161 * V_162 )
{
struct V_13 * V_14 = F_85 ( V_157 -> V_557 -> V_2 ) ;
if ( ! F_349 ( V_157 ) ) {
V_157 -> args . V_230 = NULL ;
V_157 -> V_55 . V_369 = NULL ;
} else
V_157 -> args . V_230 = V_14 -> V_399 ;
if ( ! V_157 -> V_566 )
V_157 -> V_566 = F_344 ;
V_157 -> V_55 . V_14 = V_14 ;
V_157 -> V_107 = V_154 ;
V_162 -> V_289 = & V_290 [ V_571 ] ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_55 . V_160 , 1 ) ;
}
static int F_351 ( struct V_117 * V_118 , struct V_564 * V_157 )
{
if ( F_63 ( F_85 ( V_157 -> V_557 -> V_2 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_55 . V_160 ,
V_118 ) )
return 0 ;
if ( F_333 ( & V_157 -> args . V_239 , V_157 -> args . V_558 ,
V_157 -> args . V_560 , V_217 ) == - V_36 )
return - V_36 ;
if ( F_343 ( F_31 ( V_563 , & V_157 -> args . V_558 -> V_206 ) ) )
return - V_36 ;
return 0 ;
}
static void F_352 ( struct V_117 * V_118 , struct V_572 * V_157 )
{
F_63 ( F_85 ( V_157 -> V_2 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_55 . V_160 ,
V_118 ) ;
}
static int F_353 ( struct V_117 * V_118 , struct V_572 * V_157 )
{
struct V_2 * V_2 = V_157 -> V_2 ;
F_354 ( V_157 , V_118 -> V_149 ) ;
if ( F_228 ( V_118 , F_85 ( V_2 ) , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_355 ( struct V_117 * V_118 , struct V_572 * V_157 )
{
if ( ! F_60 ( V_118 , & V_157 -> V_55 . V_160 ) )
return - V_131 ;
return V_157 -> V_573 ( V_118 , V_157 ) ;
}
static void F_356 ( struct V_572 * V_157 , struct V_161 * V_162 )
{
struct V_13 * V_14 = F_85 ( V_157 -> V_2 ) ;
if ( V_157 -> V_573 == NULL )
V_157 -> V_573 = F_353 ;
V_157 -> V_55 . V_14 = V_14 ;
V_162 -> V_289 = & V_290 [ V_574 ] ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_55 . V_160 , 1 ) ;
}
static void F_357 ( void * V_155 )
{
struct V_575 * V_157 = V_155 ;
struct V_63 * V_64 = V_157 -> V_92 ;
if ( F_358 ( & V_64 -> V_576 ) > 1 )
F_359 ( V_64 ) ;
F_360 ( V_64 ) ;
F_96 ( V_157 ) ;
}
static void F_361 ( struct V_117 * V_118 , void * V_155 )
{
struct V_575 * V_157 = V_155 ;
struct V_63 * V_64 = V_157 -> V_92 ;
unsigned long V_107 = V_157 -> V_107 ;
F_362 ( V_64 , V_118 -> V_149 ) ;
switch ( V_118 -> V_149 ) {
case 0 :
break;
case - V_79 :
F_26 ( V_64 ) ;
break;
default:
if ( F_31 ( V_577 , & V_64 -> V_578 ) == 0 )
return;
if ( V_118 -> V_149 != V_579 ) {
F_24 ( V_64 ) ;
return;
}
F_363 ( V_64 ) ;
}
F_33 ( V_64 , V_107 ) ;
}
static int F_364 ( struct V_63 * V_64 , struct V_294 * V_329 , unsigned V_580 )
{
struct V_161 V_162 = {
. V_289 = & V_290 [ V_581 ] ,
. V_292 = V_64 ,
. V_294 = V_329 ,
} ;
struct V_575 * V_157 ;
if ( V_580 == 0 )
return 0 ;
if ( ! F_365 ( & V_64 -> V_576 ) )
return - V_36 ;
V_157 = F_257 ( sizeof( * V_157 ) , V_281 ) ;
if ( V_157 == NULL )
return - V_127 ;
V_157 -> V_92 = V_64 ;
V_157 -> V_107 = V_154 ;
return F_366 ( V_64 -> V_102 , & V_162 , V_582 ,
& V_583 , V_157 ) ;
}
static int F_367 ( struct V_63 * V_64 , struct V_294 * V_329 )
{
struct V_161 V_162 = {
. V_289 = & V_290 [ V_581 ] ,
. V_292 = V_64 ,
. V_294 = V_329 ,
} ;
unsigned long V_541 = V_154 ;
int V_284 ;
V_284 = F_368 ( V_64 -> V_102 , & V_162 , V_582 ) ;
if ( V_284 < 0 )
return V_284 ;
F_33 ( V_64 , V_541 ) ;
return 0 ;
}
static inline int F_369 ( struct V_13 * V_14 )
{
return ( V_14 -> V_95 & V_411 )
&& ( V_14 -> V_433 & V_584 )
&& ( V_14 -> V_433 & V_585 ) ;
}
static int F_370 ( const void * V_586 , T_9 V_587 ,
struct V_460 * * V_43 , unsigned int * V_50 )
{
struct V_460 * V_588 , * * V_589 ;
int V_590 = 0 ;
T_9 V_12 ;
V_589 = V_43 ;
do {
V_12 = F_371 ( T_9 , V_591 , V_587 ) ;
V_588 = F_256 ( V_360 ) ;
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
struct V_172 * V_173 = F_75 ( V_2 ) ;
F_34 ( & V_2 -> V_174 ) ;
F_96 ( V_173 -> V_595 ) ;
V_173 -> V_595 = V_594 ;
F_36 ( & V_2 -> V_174 ) ;
}
static void F_374 ( struct V_2 * V_2 )
{
F_373 ( V_2 , NULL ) ;
}
static inline T_11 F_375 ( struct V_2 * V_2 , char * V_586 , T_9 V_587 )
{
struct V_172 * V_173 = F_75 ( V_2 ) ;
struct V_593 * V_594 ;
int V_67 = - V_280 ;
F_34 ( & V_2 -> V_174 ) ;
V_594 = V_173 -> V_595 ;
if ( V_594 == NULL )
goto V_132;
if ( V_586 == NULL )
goto V_596;
if ( V_594 -> V_597 == 0 )
goto V_132;
V_67 = - V_598 ;
if ( V_594 -> V_12 > V_587 )
goto V_132;
memcpy ( V_586 , V_594 -> V_157 , V_594 -> V_12 ) ;
V_596:
V_67 = V_594 -> V_12 ;
V_132:
F_36 ( & V_2 -> V_174 ) ;
return V_67 ;
}
static void F_376 ( struct V_2 * V_2 , struct V_460 * * V_43 , T_9 V_50 , T_9 V_599 )
{
struct V_593 * V_594 ;
T_9 V_587 = sizeof( * V_594 ) + V_599 ;
if ( V_587 <= V_591 ) {
V_594 = F_257 ( V_587 , V_360 ) ;
if ( V_594 == NULL )
goto V_132;
V_594 -> V_597 = 1 ;
F_377 ( V_594 -> V_157 , V_43 , V_50 , V_599 ) ;
} else {
V_594 = F_257 ( sizeof( * V_594 ) , V_360 ) ;
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
struct V_460 * V_43 [ V_600 ] = { NULL , } ;
struct V_601 args = {
. V_233 = F_93 ( V_2 ) ,
. V_602 = V_43 ,
. V_599 = V_587 ,
} ;
struct V_603 V_55 = {
. V_599 = V_587 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_604 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
unsigned int V_605 = F_379 ( V_587 , V_591 ) ;
int V_67 = - V_127 , V_449 ;
if ( V_605 == 0 )
V_605 = 1 ;
if ( V_605 > F_247 ( V_43 ) )
return - V_598 ;
for ( V_449 = 0 ; V_449 < V_605 ; V_449 ++ ) {
V_43 [ V_449 ] = F_256 ( V_360 ) ;
if ( ! V_43 [ V_449 ] )
goto V_288;
}
V_55 . V_606 = F_256 ( V_360 ) ;
if ( ! V_55 . V_606 )
goto V_288;
args . V_599 = V_605 * V_591 ;
args . V_607 = 0 ;
F_8 ( L_41 ,
V_35 , V_586 , V_587 , V_605 , args . V_599 ) ;
V_67 = F_73 ( F_85 ( V_2 ) -> V_92 , F_85 ( V_2 ) ,
& V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
if ( V_67 )
goto V_288;
if ( V_55 . V_608 & V_609 ) {
if ( V_586 == NULL )
goto V_610;
V_67 = - V_598 ;
goto V_288;
}
F_376 ( V_2 , V_43 , V_55 . V_611 , V_55 . V_599 ) ;
if ( V_586 ) {
if ( V_55 . V_599 > V_587 ) {
V_67 = - V_598 ;
goto V_288;
}
F_377 ( V_586 , V_43 , V_55 . V_611 , V_55 . V_599 ) ;
}
V_610:
V_67 = V_55 . V_599 ;
V_288:
for ( V_449 = 0 ; V_449 < V_605 ; V_449 ++ )
if ( V_43 [ V_449 ] )
F_260 ( V_43 [ V_449 ] ) ;
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
if ( F_75 ( V_2 ) -> V_175 & V_613 )
F_384 ( V_2 ) ;
V_67 = F_375 ( V_2 , V_586 , V_587 ) ;
if ( V_67 != - V_280 )
return V_67 ;
return F_380 ( V_2 , V_586 , V_587 ) ;
}
static int F_385 ( struct V_2 * V_2 , const void * V_586 , T_9 V_587 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_460 * V_43 [ V_600 ] ;
struct V_614 V_372 = {
. V_233 = F_93 ( V_2 ) ,
. V_602 = V_43 ,
. V_599 = V_587 ,
} ;
struct V_615 V_55 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_616 ] ,
. V_292 = & V_372 ,
. V_293 = & V_55 ,
} ;
unsigned int V_605 = F_379 ( V_587 , V_591 ) ;
int V_67 , V_449 ;
if ( ! F_369 ( V_14 ) )
return - V_612 ;
if ( V_605 > F_247 ( V_43 ) )
return - V_598 ;
V_449 = F_370 ( V_586 , V_587 , V_372 . V_602 , & V_372 . V_607 ) ;
if ( V_449 < 0 )
return V_449 ;
F_21 ( V_2 ) ;
V_67 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & V_372 . V_159 , & V_55 . V_160 , 1 ) ;
for (; V_449 > 0 ; V_449 -- )
F_386 ( V_43 [ V_449 - 1 ] ) ;
F_34 ( & V_2 -> V_174 ) ;
F_75 ( V_2 ) -> V_175 |= V_176 ;
F_36 ( & V_2 -> V_174 ) ;
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
struct V_368 V_369 ;
struct V_1 V_7 = { 0 , 0 , V_587 , V_586 } ;
T_1 V_230 [ 3 ] = { 0 , 0 , V_430 } ;
struct V_463 V_372 = {
. V_233 = F_93 ( V_2 ) ,
. V_230 = V_230 ,
} ;
struct V_464 V_55 = {
. V_369 = & V_369 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_465 ] ,
. V_292 = & V_372 ,
. V_293 = & V_55 ,
} ;
int V_67 ;
F_81 ( & V_369 ) ;
V_67 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & V_372 . V_159 , & V_55 . V_160 , 0 ) ;
if ( V_67 )
return V_67 ;
if ( ! ( V_369 . V_275 & V_617 ) )
return - V_280 ;
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
struct V_1 * V_370 ,
struct V_368 * V_369 ,
struct V_1 * V_359 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
const T_1 V_230 [ 3 ] = { 0 , 0 , V_430 } ;
struct V_371 V_372 = {
. V_233 = F_93 ( V_2 ) ,
. V_373 = & V_6 ,
. V_14 = V_14 ,
. V_230 = V_230 ,
. V_7 = V_370 ,
} ;
struct V_374 V_55 = {
. V_369 = V_369 ,
. V_7 = V_359 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_375 ] ,
. V_292 = & V_372 ,
. V_293 = & V_55 ,
} ;
int V_284 ;
F_115 ( & V_372 . V_239 , & V_384 ) ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & V_372 . V_159 , & V_55 . V_160 , 1 ) ;
if ( V_284 )
F_8 ( L_42 , V_35 , V_284 ) ;
return V_284 ;
}
static int F_394 ( struct V_2 * V_2 ,
struct V_1 * V_370 ,
struct V_368 * V_369 ,
struct V_1 * V_359 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_393 ( V_2 , V_370 ,
V_369 , V_359 ) ;
F_395 ( V_2 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_396 ( struct V_4 * V_4 , const void * V_586 , T_9 V_587 )
{
struct V_1 V_370 , * V_359 = NULL ;
struct V_368 V_369 ;
struct V_294 * V_329 ;
struct V_2 * V_2 = V_4 -> V_47 ;
int V_284 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_612 ;
F_81 ( & V_369 ) ;
V_370 . V_618 = 0 ;
V_370 . V_619 = 0 ;
V_370 . V_7 = ( char * ) V_586 ;
V_370 . V_12 = V_587 ;
V_329 = F_397 () ;
if ( F_43 ( V_329 ) )
return F_71 ( V_329 ) ;
V_359 = F_87 ( F_85 ( V_2 ) , V_360 ) ;
if ( F_43 ( V_359 ) ) {
V_284 = - F_71 ( V_359 ) ;
goto V_132;
}
V_284 = F_394 ( V_2 , & V_370 , & V_369 , V_359 ) ;
if ( V_284 == 0 )
F_211 ( V_2 , & V_369 , V_359 ) ;
F_95 ( V_359 ) ;
V_132:
F_192 ( V_329 ) ;
return V_284 ;
}
static int
F_228 ( struct V_117 * V_118 , const struct V_13 * V_14 , struct V_65 * V_66 )
{
struct V_63 * V_64 = V_14 -> V_63 ;
if ( V_118 -> V_149 >= 0 )
return 0 ;
switch( V_118 -> V_149 ) {
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
F_8 ( L_43 , V_35 ,
V_118 -> V_149 ) ;
F_28 ( V_64 -> V_88 , V_118 -> V_149 ) ;
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
V_118 -> V_149 = F_7 ( V_118 -> V_149 ) ;
return 0 ;
V_620:
V_118 -> V_149 = - V_36 ;
return 0 ;
V_71:
F_47 ( & V_64 -> V_623 , V_118 , NULL ) ;
if ( F_31 ( V_624 , & V_64 -> V_625 ) == 0 )
F_399 ( & V_64 -> V_623 , V_118 ) ;
if ( F_31 ( V_99 , & V_14 -> V_100 ) )
goto V_620;
V_622:
V_118 -> V_149 = 0 ;
return - V_131 ;
}
static void F_400 ( const struct V_63 * V_64 ,
T_12 * V_626 )
{
T_3 V_236 [ 2 ] ;
if ( F_31 ( V_627 , & V_64 -> V_625 ) ) {
V_236 [ 0 ] = 0 ;
V_236 [ 1 ] = F_401 ( V_628 + 1 ) ;
} else {
struct V_629 * V_630 = F_402 ( V_64 -> V_631 , V_632 ) ;
V_236 [ 0 ] = F_401 ( V_630 -> V_633 . V_634 ) ;
V_236 [ 1 ] = F_401 ( V_630 -> V_633 . V_635 ) ;
}
memcpy ( V_626 -> V_157 , V_236 , sizeof( V_626 -> V_157 ) ) ;
}
static unsigned int
F_403 ( const struct V_63 * V_64 ,
char * V_586 , T_9 V_12 )
{
unsigned int V_636 ;
F_122 () ;
V_636 = F_404 ( V_586 , V_12 , L_44 ,
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
return F_404 ( V_586 , V_12 , L_45 ,
V_64 -> V_643 -> V_644 ,
V_64 -> V_407 ,
V_642 ,
V_640 ) ;
return F_404 ( V_586 , V_12 , L_46 ,
V_64 -> V_643 -> V_644 , V_64 -> V_407 ,
V_640 ) ;
}
int F_407 ( struct V_63 * V_64 , T_1 V_645 ,
unsigned short V_646 , struct V_294 * V_329 ,
struct V_647 * V_55 )
{
T_12 V_648 ;
struct V_649 V_650 = {
. V_648 = & V_648 ,
. V_651 = V_645 ,
. V_652 = V_64 -> V_653 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_654 ] ,
. V_292 = & V_650 ,
. V_293 = V_55 ,
. V_294 = V_329 ,
} ;
int V_284 ;
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
sizeof( V_650 . V_660 ) , L_47 ,
F_405 ( V_64 -> V_102 ,
V_661 ) ) ;
F_125 () ;
V_650 . V_662 = F_404 ( V_650 . V_663 ,
sizeof( V_650 . V_663 ) , L_48 ,
V_64 -> V_637 , V_646 >> 8 , V_646 & 255 ) ;
F_8 ( L_49 ,
V_64 -> V_102 -> V_103 -> V_664 -> V_665 ,
V_650 . V_657 , V_650 . V_658 ) ;
V_284 = F_368 ( V_64 -> V_102 , & V_162 , V_582 ) ;
F_408 ( V_64 , V_284 ) ;
F_8 ( L_50 , V_284 ) ;
return V_284 ;
}
int F_409 ( struct V_63 * V_64 ,
struct V_647 * V_372 ,
struct V_294 * V_329 )
{
struct V_161 V_162 = {
. V_289 = & V_290 [ V_666 ] ,
. V_292 = V_372 ,
. V_294 = V_329 ,
} ;
int V_284 ;
F_8 ( L_51 ,
V_64 -> V_102 -> V_103 -> V_664 -> V_665 ,
V_64 -> V_224 ) ;
V_284 = F_368 ( V_64 -> V_102 , & V_162 , V_582 ) ;
F_410 ( V_64 , V_284 ) ;
F_8 ( L_52 , V_284 ) ;
return V_284 ;
}
static void F_411 ( struct V_117 * V_118 , void * V_155 )
{
struct V_667 * V_157 = V_155 ;
if ( ! F_60 ( V_118 , & V_157 -> V_55 . V_160 ) )
return;
F_412 ( & V_157 -> args , & V_157 -> V_55 , V_118 -> V_149 ) ;
switch ( V_118 -> V_149 ) {
case 0 :
F_37 ( V_157 -> V_55 . V_14 , V_157 -> V_107 ) ;
break;
case - V_73 :
case - V_72 :
case - V_74 :
case - V_94 :
case - V_76 :
case - V_75 :
V_118 -> V_149 = 0 ;
break;
default:
if ( F_228 ( V_118 , V_157 -> V_55 . V_14 , NULL ) ==
- V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
V_157 -> V_272 = V_118 -> V_149 ;
}
static void F_413 ( void * V_155 )
{
F_96 ( V_155 ) ;
}
static void F_414 ( struct V_117 * V_118 , void * V_157 )
{
struct V_667 * V_668 ;
V_668 = (struct V_667 * ) V_157 ;
F_63 ( V_668 -> V_55 . V_14 ,
& V_668 -> args . V_159 ,
& V_668 -> V_55 . V_160 ,
V_118 ) ;
}
static int F_415 ( struct V_2 * V_2 , struct V_294 * V_329 , const T_8 * V_239 , int V_669 )
{
struct V_667 * V_157 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_117 * V_118 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_670 ] ,
. V_294 = V_329 ,
} ;
struct V_163 V_295 = {
. V_165 = V_14 -> V_92 ,
. V_161 = & V_162 ,
. V_166 = & V_671 ,
. V_206 = V_299 ,
} ;
int V_284 = 0 ;
V_157 = F_86 ( sizeof( * V_157 ) , V_281 ) ;
if ( V_157 == NULL )
return - V_127 ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_55 . V_160 , 1 ) ;
V_157 -> args . V_403 = & V_157 -> V_233 ;
V_157 -> args . V_239 = & V_157 -> V_239 ;
V_157 -> args . V_230 = V_14 -> V_399 ;
F_169 ( & V_157 -> V_233 , F_93 ( V_2 ) ) ;
F_115 ( & V_157 -> V_239 , V_239 ) ;
V_157 -> V_55 . V_369 = & V_157 -> V_369 ;
V_157 -> V_55 . V_14 = V_14 ;
F_81 ( V_157 -> V_55 . V_369 ) ;
V_157 -> V_107 = V_154 ;
V_157 -> V_272 = 0 ;
V_295 . V_169 = V_157 ;
V_162 . V_292 = & V_157 -> args ;
V_162 . V_293 = & V_157 -> V_55 ;
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
if ( ! V_669 )
goto V_132;
V_284 = F_107 ( V_118 ) ;
if ( V_284 != 0 )
goto V_132;
V_284 = V_157 -> V_272 ;
if ( V_284 == 0 )
F_346 ( V_2 , & V_157 -> V_369 ) ;
else
F_135 ( V_2 , & V_157 -> V_369 ) ;
V_132:
F_72 ( V_118 ) ;
return V_284 ;
}
int F_416 ( struct V_2 * V_2 , struct V_294 * V_329 , const T_8 * V_239 , int V_669 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_415 ( V_2 , V_329 , V_239 , V_669 ) ;
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
struct V_676 V_372 = {
. V_233 = F_93 ( V_2 ) ,
. V_677 = V_675 ,
} ;
struct V_678 V_55 = {
. V_679 = V_675 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_680 ] ,
. V_292 = & V_372 ,
. V_293 = & V_55 ,
. V_294 = V_66 -> V_214 -> V_269 ,
} ;
struct V_681 * V_682 ;
int V_284 ;
V_372 . V_683 . V_223 = V_64 -> V_224 ;
V_284 = F_420 ( V_66 , V_675 ) ;
if ( V_284 != 0 )
goto V_132;
V_682 = V_675 -> V_684 . V_685 . V_214 ;
V_372 . V_683 . V_225 = V_682 -> V_686 . V_228 ;
V_372 . V_683 . V_687 = V_14 -> V_687 ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & V_372 . V_159 , & V_55 . V_160 , 1 ) ;
switch ( V_284 ) {
case 0 :
V_675 -> V_688 = V_689 ;
break;
case - V_286 :
V_284 = 0 ;
}
V_675 -> V_690 -> V_691 ( V_675 ) ;
V_675 -> V_690 = NULL ;
V_132:
return V_284 ;
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
struct V_278 * V_279 ,
struct V_681 * V_682 ,
struct V_697 * V_195 )
{
struct V_696 * V_42 ;
struct V_2 * V_2 = V_682 -> V_698 -> V_2 ;
V_42 = F_86 ( sizeof( * V_42 ) , V_281 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_372 . V_233 = F_93 ( V_2 ) ;
V_42 -> V_372 . V_677 = & V_42 -> V_677 ;
V_42 -> V_372 . V_195 = V_195 ;
V_42 -> V_55 . V_195 = V_195 ;
V_42 -> V_372 . V_239 = & V_682 -> V_699 ;
V_42 -> V_682 = V_682 ;
F_91 ( & V_682 -> V_700 ) ;
V_42 -> V_279 = F_143 ( V_279 ) ;
memcpy ( & V_42 -> V_677 , V_677 , sizeof( V_42 -> V_677 ) ) ;
V_42 -> V_14 = F_85 ( V_2 ) ;
return V_42 ;
}
static void F_428 ( void * V_157 )
{
struct V_696 * V_155 = V_157 ;
F_100 ( V_155 -> V_372 . V_195 ) ;
F_429 ( V_155 -> V_682 ) ;
F_155 ( V_155 -> V_279 ) ;
F_96 ( V_155 ) ;
}
static void F_430 ( struct V_117 * V_118 , void * V_157 )
{
struct V_696 * V_155 = V_157 ;
if ( ! F_60 ( V_118 , & V_155 -> V_55 . V_160 ) )
return;
switch ( V_118 -> V_149 ) {
case 0 :
F_115 ( & V_155 -> V_682 -> V_699 ,
& V_155 -> V_55 . V_239 ) ;
F_37 ( V_155 -> V_14 , V_155 -> V_107 ) ;
break;
case - V_74 :
case - V_94 :
case - V_76 :
case - V_75 :
break;
default:
if ( F_228 ( V_118 , V_155 -> V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
F_128 ( V_155 -> V_372 . V_195 ) ;
}
static void F_431 ( struct V_117 * V_118 , void * V_157 )
{
struct V_696 * V_155 = V_157 ;
if ( F_168 ( V_155 -> V_372 . V_195 , V_118 ) != 0 )
goto V_301;
if ( F_31 ( V_701 , & V_155 -> V_682 -> V_702 ) == 0 ) {
goto V_302;
}
V_155 -> V_107 = V_154 ;
if ( F_63 ( V_155 -> V_14 ,
& V_155 -> V_372 . V_159 ,
& V_155 -> V_55 . V_160 ,
V_118 ) != 0 )
F_128 ( V_155 -> V_372 . V_195 ) ;
return;
V_302:
V_118 -> V_313 = NULL ;
V_301:
F_60 ( V_118 , & V_155 -> V_55 . V_160 ) ;
}
static struct V_117 * F_432 ( struct V_674 * V_677 ,
struct V_278 * V_279 ,
struct V_681 * V_682 ,
struct V_697 * V_195 )
{
struct V_696 * V_157 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_703 ] ,
. V_294 = V_279 -> V_329 ,
} ;
struct V_163 V_295 = {
. V_165 = F_273 ( V_682 -> V_698 -> V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_704 ,
. V_297 = V_298 ,
. V_206 = V_299 ,
} ;
F_232 ( F_85 ( V_682 -> V_698 -> V_2 ) -> V_63 ,
V_397 , & V_295 . V_165 , & V_162 ) ;
V_677 -> V_688 = V_689 ;
V_157 = F_427 ( V_677 , V_279 , V_682 , V_195 ) ;
if ( V_157 == NULL ) {
F_100 ( V_195 ) ;
return F_44 ( - V_127 ) ;
}
F_38 ( & V_157 -> V_372 . V_159 , & V_157 -> V_55 . V_160 , 1 ) ;
V_162 . V_292 = & V_157 -> V_372 ;
V_162 . V_293 = & V_157 -> V_55 ;
V_295 . V_169 = V_157 ;
return F_70 ( & V_295 ) ;
}
static int F_433 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_675 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_203 * V_204 = V_66 -> V_214 ;
struct V_172 * V_173 = F_75 ( V_2 ) ;
struct V_697 * V_195 ;
struct V_681 * V_682 ;
struct V_117 * V_118 ;
int V_284 = 0 ;
unsigned char V_693 = V_675 -> V_693 ;
V_284 = F_420 ( V_66 , V_675 ) ;
V_675 -> V_693 |= V_705 ;
F_434 ( & V_204 -> V_706 ) ;
F_435 ( & V_173 -> V_707 ) ;
if ( F_423 ( V_675 -> V_708 , V_675 ) == - V_280 ) {
F_436 ( & V_173 -> V_707 ) ;
F_437 ( & V_204 -> V_706 ) ;
goto V_132;
}
F_436 ( & V_173 -> V_707 ) ;
F_437 ( & V_204 -> V_706 ) ;
if ( V_284 != 0 )
goto V_132;
V_682 = V_675 -> V_684 . V_685 . V_214 ;
if ( F_31 ( V_701 , & V_682 -> V_702 ) == 0 )
goto V_132;
V_195 = F_88 ( & V_682 -> V_686 , V_360 ) ;
V_284 = - V_127 ;
if ( V_195 == NULL )
goto V_132;
V_118 = F_432 ( V_675 , F_265 ( V_675 -> V_708 ) , V_682 , V_195 ) ;
V_284 = F_71 ( V_118 ) ;
if ( F_43 ( V_118 ) )
goto V_132;
V_284 = F_107 ( V_118 ) ;
F_72 ( V_118 ) ;
V_132:
V_675 -> V_693 = V_693 ;
F_438 ( V_675 , V_66 , V_709 , V_284 ) ;
return V_284 ;
}
static struct V_710 * F_439 ( struct V_674 * V_677 ,
struct V_278 * V_279 , struct V_681 * V_682 ,
T_6 V_208 )
{
struct V_710 * V_42 ;
struct V_2 * V_2 = V_682 -> V_698 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
V_42 = F_86 ( sizeof( * V_42 ) , V_208 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_372 . V_233 = F_93 ( V_2 ) ;
V_42 -> V_372 . V_677 = & V_42 -> V_677 ;
V_42 -> V_372 . V_711 = F_88 ( & V_682 -> V_698 -> V_214 -> V_211 , V_208 ) ;
if ( V_42 -> V_372 . V_711 == NULL )
goto V_288;
V_42 -> V_372 . V_712 = F_88 ( & V_682 -> V_686 , V_208 ) ;
if ( V_42 -> V_372 . V_712 == NULL )
goto V_713;
V_42 -> V_372 . V_714 = & V_682 -> V_699 ;
V_42 -> V_372 . V_683 . V_223 = V_14 -> V_63 -> V_224 ;
V_42 -> V_372 . V_683 . V_225 = V_682 -> V_686 . V_228 ;
V_42 -> V_372 . V_683 . V_687 = V_14 -> V_687 ;
V_42 -> V_55 . V_712 = V_42 -> V_372 . V_712 ;
V_42 -> V_682 = V_682 ;
V_42 -> V_14 = V_14 ;
F_91 ( & V_682 -> V_700 ) ;
V_42 -> V_279 = F_143 ( V_279 ) ;
memcpy ( & V_42 -> V_677 , V_677 , sizeof( V_42 -> V_677 ) ) ;
return V_42 ;
V_713:
F_100 ( V_42 -> V_372 . V_711 ) ;
V_288:
F_96 ( V_42 ) ;
return NULL ;
}
static void F_440 ( struct V_117 * V_118 , void * V_155 )
{
struct V_710 * V_157 = V_155 ;
struct V_65 * V_66 = V_157 -> V_682 -> V_698 ;
F_8 ( L_30 , V_35 ) ;
if ( F_168 ( V_157 -> V_372 . V_712 , V_118 ) != 0 )
goto V_301;
if ( ! ( V_157 -> V_372 . V_712 -> V_715 -> V_206 & V_716 ) ) {
if ( F_168 ( V_157 -> V_372 . V_711 , V_118 ) != 0 ) {
goto V_717;
}
V_157 -> V_372 . V_257 = & V_66 -> V_257 ;
V_157 -> V_372 . V_718 = 1 ;
V_157 -> V_55 . V_711 = V_157 -> V_372 . V_711 ;
} else
V_157 -> V_372 . V_718 = 0 ;
if ( ! F_218 ( V_66 ) ) {
V_157 -> V_272 = - V_385 ;
V_118 -> V_313 = NULL ;
goto V_719;
}
V_157 -> V_107 = V_154 ;
if ( F_63 ( V_157 -> V_14 ,
& V_157 -> V_372 . V_159 ,
& V_157 -> V_55 . V_160 ,
V_118 ) == 0 )
return;
V_719:
F_128 ( V_157 -> V_372 . V_711 ) ;
V_717:
F_128 ( V_157 -> V_372 . V_712 ) ;
V_301:
F_60 ( V_118 , & V_157 -> V_55 . V_160 ) ;
F_8 ( L_53 , V_35 , V_157 -> V_272 ) ;
}
static void F_441 ( struct V_117 * V_118 , void * V_155 )
{
struct V_710 * V_157 = V_155 ;
F_8 ( L_30 , V_35 ) ;
if ( ! F_60 ( V_118 , & V_157 -> V_55 . V_160 ) )
return;
V_157 -> V_272 = V_118 -> V_149 ;
if ( V_157 -> V_372 . V_718 != 0 ) {
if ( V_157 -> V_272 == 0 )
F_162 ( & V_157 -> V_682 -> V_686 , 0 ) ;
else
goto V_132;
}
if ( V_157 -> V_272 == 0 ) {
F_115 ( & V_157 -> V_682 -> V_699 , & V_157 -> V_55 . V_239 ) ;
F_116 ( V_701 , & V_157 -> V_682 -> V_702 ) ;
F_37 ( F_85 ( V_157 -> V_279 -> V_4 -> V_47 ) , V_157 -> V_107 ) ;
}
V_132:
F_8 ( L_31 , V_35 , V_157 -> V_272 ) ;
}
static void F_442 ( void * V_155 )
{
struct V_710 * V_157 = V_155 ;
F_8 ( L_30 , V_35 ) ;
F_100 ( V_157 -> V_372 . V_711 ) ;
if ( V_157 -> V_287 != 0 ) {
struct V_117 * V_118 ;
V_118 = F_432 ( & V_157 -> V_677 , V_157 -> V_279 , V_157 -> V_682 ,
V_157 -> V_372 . V_712 ) ;
if ( ! F_43 ( V_118 ) )
F_443 ( V_118 ) ;
F_8 ( L_54 , V_35 ) ;
} else
F_100 ( V_157 -> V_372 . V_712 ) ;
F_429 ( V_157 -> V_682 ) ;
F_155 ( V_157 -> V_279 ) ;
F_96 ( V_157 ) ;
F_8 ( L_32 , V_35 ) ;
}
static void F_444 ( struct V_13 * V_14 , struct V_681 * V_682 , int V_718 , int error )
{
switch ( error ) {
case - V_73 :
case - V_74 :
V_682 -> V_686 . V_206 &= ~ V_716 ;
if ( V_718 != 0 ||
F_31 ( V_701 , & V_682 -> V_702 ) != 0 )
F_22 ( V_14 , V_682 -> V_698 ) ;
break;
case - V_76 :
V_682 -> V_686 . V_206 &= ~ V_716 ;
case - V_75 :
F_24 ( V_14 -> V_63 ) ;
} ;
}
static int F_445 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_677 , int V_720 )
{
struct V_710 * V_157 ;
struct V_117 * V_118 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_721 ] ,
. V_294 = V_66 -> V_214 -> V_269 ,
} ;
struct V_163 V_295 = {
. V_165 = F_273 ( V_66 -> V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_722 ,
. V_297 = V_298 ,
. V_206 = V_299 ,
} ;
int V_67 ;
F_8 ( L_30 , V_35 ) ;
V_157 = F_439 ( V_677 , F_265 ( V_677 -> V_708 ) ,
V_677 -> V_684 . V_685 . V_214 ,
V_720 == V_723 ? V_360 : V_281 ) ;
if ( V_157 == NULL )
return - V_127 ;
if ( F_446 ( V_673 ) )
V_157 -> V_372 . V_724 = 1 ;
F_38 ( & V_157 -> V_372 . V_159 , & V_157 -> V_55 . V_160 , 1 ) ;
V_162 . V_292 = & V_157 -> V_372 ;
V_162 . V_293 = & V_157 -> V_55 ;
V_295 . V_169 = V_157 ;
if ( V_720 > V_723 ) {
if ( V_720 == V_725 )
V_157 -> V_372 . V_726 = V_725 ;
F_39 ( & V_157 -> V_372 . V_159 ) ;
}
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_67 = F_107 ( V_118 ) ;
if ( V_67 == 0 ) {
V_67 = V_157 -> V_272 ;
if ( V_67 )
F_444 ( V_157 -> V_14 , V_157 -> V_682 ,
V_157 -> V_372 . V_718 , V_67 ) ;
} else
V_157 -> V_287 = 1 ;
F_72 ( V_118 ) ;
F_8 ( L_31 , V_35 , V_67 ) ;
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
if ( F_31 ( V_256 , & V_66 -> V_206 ) != 0 )
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
F_116 ( V_728 , & V_675 -> V_684 . V_685 . V_214 -> V_702 ) ;
return 0 ;
}
do {
if ( F_31 ( V_256 , & V_66 -> V_206 ) != 0 )
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
int V_284 , V_67 = - V_74 ;
struct V_681 * V_682 ;
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
F_142 (lsp, &state->lock_states, ls_locks) {
if ( F_31 ( V_701 , & V_682 -> V_702 ) ) {
struct V_294 * V_329 = V_682 -> V_698 -> V_214 -> V_269 ;
V_284 = F_189 ( V_14 ,
& V_682 -> V_699 ,
V_329 ) ;
F_452 ( V_66 , V_682 , V_284 ) ;
if ( V_284 != V_343 ) {
if ( V_284 != - V_74 )
F_191 ( V_14 ,
& V_682 -> V_699 ,
V_329 ) ;
F_149 ( V_701 , & V_682 -> V_702 ) ;
V_67 = V_284 ;
}
}
} ;
return V_67 ;
}
static int F_453 ( struct V_65 * V_66 , struct V_674 * V_675 )
{
int V_284 = V_343 ;
if ( F_31 ( V_730 , & V_66 -> V_206 ) )
V_284 = F_451 ( V_66 ) ;
if ( V_284 != V_343 )
V_284 = F_449 ( V_66 , V_675 ) ;
return V_284 ;
}
static int F_454 ( struct V_65 * V_66 , int V_673 , struct V_674 * V_675 )
{
struct V_203 * V_204 = V_66 -> V_214 ;
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
unsigned char V_693 = V_675 -> V_693 ;
unsigned int V_351 ;
int V_284 = - V_731 ;
if ( ( V_693 & V_694 ) &&
! F_31 ( V_353 , & V_66 -> V_206 ) )
goto V_132;
V_284 = F_420 ( V_66 , V_675 ) ;
if ( V_284 != 0 )
goto V_132;
V_675 -> V_693 |= V_732 ;
V_284 = F_423 ( V_675 -> V_708 , V_675 ) ;
if ( V_284 < 0 )
goto V_132;
F_435 ( & V_173 -> V_707 ) ;
if ( F_31 ( V_256 , & V_66 -> V_206 ) ) {
V_675 -> V_693 = V_693 & ~ V_733 ;
V_284 = F_423 ( V_675 -> V_708 , V_675 ) ;
goto V_139;
}
V_351 = F_198 ( & V_204 -> V_352 ) ;
F_436 ( & V_173 -> V_707 ) ;
V_284 = F_445 ( V_66 , V_673 , V_675 , V_723 ) ;
if ( V_284 != 0 )
goto V_132;
F_435 ( & V_173 -> V_707 ) ;
if ( F_204 ( & V_204 -> V_352 , V_351 ) ) {
V_284 = - V_91 ;
goto V_139;
}
V_675 -> V_693 = V_693 | V_733 ;
if ( F_423 ( V_675 -> V_708 , V_675 ) < 0 )
F_29 ( V_97 L_55
L_56 , V_35 ) ;
V_139:
F_436 ( & V_173 -> V_707 ) ;
V_132:
V_675 -> V_693 = V_693 ;
return V_284 ;
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
if ( V_8 == - V_286 )
V_8 = - V_131 ;
V_8 = F_19 ( F_85 ( V_66 -> V_2 ) ,
V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int
F_457 ( struct V_692 * V_734 , int V_673 , struct V_674 * V_675 )
{
struct V_278 * V_279 ;
struct V_65 * V_66 ;
unsigned long V_54 = V_735 ;
int V_284 ;
V_279 = F_265 ( V_734 ) ;
V_66 = V_279 -> V_66 ;
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
if ( ! ( V_734 -> V_740 & V_217 ) )
return - V_385 ;
}
do {
V_284 = F_455 ( V_66 , V_673 , V_675 ) ;
if ( ( V_284 != - V_131 ) || F_459 ( V_673 ) )
break;
V_54 = F_418 ( V_54 ) ;
V_284 = - V_59 ;
if ( F_460 () )
break;
} while( V_284 < 0 );
return V_284 ;
}
int F_461 ( struct V_674 * V_677 , struct V_65 * V_66 , const T_8 * V_239 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
int V_8 ;
V_8 = F_420 ( V_66 , V_677 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_445 ( V_66 , V_709 , V_677 , V_723 ) ;
return F_156 ( V_14 , V_66 , V_239 , V_8 ) ;
}
static void F_462 ( struct V_117 * V_118 , void * V_155 )
{
struct V_742 * V_157 = V_155 ;
F_40 ( V_157 -> V_14 ,
& V_157 -> V_159 , & V_157 -> V_160 , V_118 ) ;
V_157 -> V_107 = V_154 ;
}
static void F_463 ( struct V_117 * V_118 , void * V_155 )
{
struct V_742 * V_157 = V_155 ;
struct V_13 * V_14 = V_157 -> V_14 ;
F_48 ( V_118 , & V_157 -> V_160 ) ;
switch ( V_118 -> V_149 ) {
case 0 :
F_37 ( V_14 , V_157 -> V_107 ) ;
break;
case - V_77 :
case - V_75 :
case - V_79 :
case - V_91 :
if ( F_228 ( V_118 , V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
}
static void F_464 ( void * V_155 )
{
struct V_742 * V_157 = V_155 ;
F_465 ( V_157 -> V_14 , V_157 -> V_682 ) ;
F_96 ( V_155 ) ;
}
static int F_466 ( struct V_13 * V_14 , struct V_681 * V_682 )
{
struct V_742 * V_157 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_743 ] ,
} ;
if ( V_14 -> V_63 -> V_167 -> V_311 != 0 )
return - V_27 ;
V_157 = F_257 ( sizeof( * V_157 ) , V_281 ) ;
if ( ! V_157 )
return - V_127 ;
F_38 ( & V_157 -> V_159 , & V_157 -> V_160 , 0 ) ;
V_157 -> V_682 = V_682 ;
V_157 -> V_14 = V_14 ;
V_157 -> args . V_683 . V_223 = V_14 -> V_63 -> V_224 ;
V_157 -> args . V_683 . V_225 = V_682 -> V_686 . V_228 ;
V_157 -> args . V_683 . V_687 = V_14 -> V_687 ;
V_162 . V_292 = & V_157 -> args ;
F_366 ( V_14 -> V_92 , & V_162 , 0 , & V_744 , V_157 ) ;
return 0 ;
}
static int F_467 ( struct V_4 * V_4 , const char * V_745 ,
const void * V_586 , T_9 V_587 ,
int V_206 , int type )
{
if ( strcmp ( V_745 , L_57 ) != 0 )
return - V_27 ;
return F_388 ( V_4 -> V_47 , V_586 , V_587 ) ;
}
static int F_468 ( struct V_4 * V_4 , const char * V_745 ,
void * V_586 , T_9 V_587 , int type )
{
if ( strcmp ( V_745 , L_57 ) != 0 )
return - V_27 ;
return F_382 ( V_4 -> V_47 , V_586 , V_587 ) ;
}
static T_9 F_469 ( struct V_4 * V_4 , char * V_746 ,
T_9 V_747 , const char * V_229 ,
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
int V_206 , int type )
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
T_9 V_747 , const char * V_229 ,
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
static void F_259 ( struct V_368 * V_369 )
{
if ( ! ( ( ( V_369 -> V_275 & V_750 ) ||
( V_369 -> V_275 & V_751 ) ) &&
( V_369 -> V_275 & V_457 ) &&
( V_369 -> V_275 & V_752 ) ) )
return;
V_369 -> V_275 |= V_314 | V_472 |
V_473 | V_753 ;
V_369 -> V_243 = V_319 | V_475 | V_476 ;
V_369 -> V_477 = 2 ;
}
static int F_476 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_459 * V_229 ,
struct V_461 * V_754 ,
struct V_460 * V_460 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
T_1 V_230 [ 3 ] = {
[ 0 ] = V_755 | V_756 ,
} ;
struct V_757 args = {
. V_470 = F_93 ( V_3 ) ,
. V_229 = V_229 ,
. V_460 = V_460 ,
. V_230 = V_230 ,
} ;
struct V_758 V_55 = {
. V_754 = V_754 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_759 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
int V_284 ;
F_8 ( L_58 , V_35 ) ;
if ( F_85 ( V_3 ) -> V_15 [ 1 ] & V_760 )
V_230 [ 1 ] |= V_760 ;
else
V_230 [ 0 ] |= V_46 ;
F_81 ( & V_754 -> V_369 ) ;
V_754 -> V_14 = V_14 ;
V_754 -> V_761 = 0 ;
V_284 = F_73 ( V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
F_8 ( L_59 , V_35 , V_284 ) ;
return V_284 ;
}
int F_258 ( struct V_52 * V_92 , struct V_2 * V_3 ,
const struct V_459 * V_229 ,
struct V_461 * V_754 ,
struct V_460 * V_460 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_476 ( V_92 , V_3 , V_229 ,
V_754 , V_460 ) ;
F_477 ( V_3 , V_229 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_478 ( struct V_2 * V_2 ,
struct V_461 * V_462 ,
struct V_460 * V_460 , struct V_294 * V_329 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
T_1 V_230 [ 2 ] = {
[ 0 ] = V_755 | V_756 ,
} ;
struct V_757 args = {
. V_223 = V_14 -> V_63 -> V_224 ,
. V_233 = F_93 ( V_2 ) ,
. V_460 = V_460 ,
. V_230 = V_230 ,
. V_762 = 1 ,
. V_763 = 1 ,
} ;
struct V_758 V_55 = {
. V_754 = V_462 ,
. V_762 = 1 ,
. V_763 = 1 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_759 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
unsigned long V_541 = V_154 ;
int V_284 ;
F_81 ( & V_462 -> V_369 ) ;
V_462 -> V_14 = V_14 ;
V_462 -> V_761 = 0 ;
F_38 ( & args . V_159 , & V_55 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_284 = F_69 ( V_53 , V_14 , & V_162 ,
& args . V_159 , & V_55 . V_160 ) ;
if ( V_284 )
return V_284 ;
F_37 ( V_14 , V_541 ) ;
return 0 ;
}
static int F_479 ( struct V_2 * V_2 ,
struct V_461 * V_462 ,
struct V_460 * V_460 , struct V_294 * V_329 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
T_1 V_230 [ 2 ] = {
[ 0 ] = V_755 | V_756 ,
} ;
struct V_757 args = {
. V_233 = F_93 ( V_2 ) ,
. V_460 = V_460 ,
. V_230 = V_230 ,
. V_762 = 1 ,
} ;
struct V_758 V_55 = {
. V_754 = V_462 ,
. V_762 = 1 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_759 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
int V_284 ;
F_81 ( & V_462 -> V_369 ) ;
V_462 -> V_14 = V_14 ;
V_462 -> V_761 = 0 ;
F_38 ( & args . V_159 , & V_55 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_284 = F_69 ( V_53 , V_14 , & V_162 ,
& args . V_159 , & V_55 . V_160 ) ;
if ( V_284 == V_764 &&
V_55 . V_160 . V_145 & V_765 )
V_284 = - V_79 ;
return V_284 ;
}
int F_480 ( struct V_2 * V_2 ,
struct V_461 * V_462 ,
struct V_460 * V_460 , struct V_294 * V_329 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_766 * V_767 =
V_64 -> V_167 -> V_768 ;
struct V_61 V_62 = { } ;
int V_284 ;
F_8 ( L_60 , V_35 ,
( unsigned long long ) V_14 -> V_458 . V_769 ,
( unsigned long long ) V_14 -> V_458 . V_770 ,
V_64 -> V_98 ) ;
F_481 ( F_93 ( V_2 ) , V_35 ) ;
do {
V_284 = V_767 -> V_771 ( V_2 , V_462 , V_460 , V_329 ) ;
if ( V_284 != - V_91 )
break;
F_19 ( V_14 , V_284 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_284 ;
}
static int F_482 ( struct V_2 * V_2 , struct V_294 * V_329 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = F_85 ( V_2 ) -> V_63 ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_772 args = {
. V_233 = F_93 ( V_2 ) ,
. V_223 = V_64 -> V_224 ,
. V_763 = 1 ,
} ;
struct V_773 V_55 = {
. V_763 = 1 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_774 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
unsigned long V_541 = V_154 ;
int V_284 ;
V_55 . V_233 = F_483 () ;
if ( V_55 . V_233 == NULL )
return - V_127 ;
F_38 ( & args . V_159 , & V_55 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_284 = F_69 ( V_53 , V_14 , & V_162 ,
& args . V_159 , & V_55 . V_160 ) ;
F_484 ( V_55 . V_233 ) ;
if ( V_284 )
return V_284 ;
F_33 ( V_64 , V_541 ) ;
return 0 ;
}
static int F_485 ( struct V_2 * V_2 , struct V_294 * V_329 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_772 args = {
. V_233 = F_93 ( V_2 ) ,
} ;
struct V_773 V_55 = {
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_774 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
int V_284 ;
V_55 . V_233 = F_483 () ;
if ( V_55 . V_233 == NULL )
return - V_127 ;
F_38 ( & args . V_159 , & V_55 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_284 = F_69 ( V_53 , V_14 , & V_162 ,
& args . V_159 , & V_55 . V_160 ) ;
F_484 ( V_55 . V_233 ) ;
if ( V_284 == V_764 &&
V_55 . V_160 . V_145 & V_765 )
V_284 = - V_79 ;
return V_284 ;
}
int F_486 ( struct V_2 * V_2 , struct V_294 * V_329 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_766 * V_767 =
V_64 -> V_167 -> V_768 ;
struct V_61 V_62 = { } ;
int V_284 ;
F_8 ( L_60 , V_35 ,
( unsigned long long ) V_14 -> V_458 . V_769 ,
( unsigned long long ) V_14 -> V_458 . V_770 ,
V_64 -> V_98 ) ;
F_481 ( F_93 ( V_2 ) , V_35 ) ;
do {
V_284 = V_767 -> V_775 ( V_2 , V_329 ) ;
if ( V_284 != - V_91 )
break;
F_19 ( V_14 , V_284 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_284 ;
}
static int F_487 ( struct V_2 * V_3 , const struct V_459 * V_229 , struct V_776 * V_452 , bool V_777 )
{
int V_284 ;
struct V_778 args = {
. V_470 = F_93 ( V_3 ) ,
. V_229 = V_229 ,
} ;
struct V_779 V_55 = {
. V_452 = V_452 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_780 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
struct V_52 * V_53 = F_85 ( V_3 ) -> V_92 ;
struct V_294 * V_329 = NULL ;
if ( V_777 ) {
V_53 = F_85 ( V_3 ) -> V_63 -> V_102 ;
V_329 = F_488 ( F_85 ( V_3 ) -> V_63 ) ;
V_162 . V_294 = V_329 ;
}
F_8 ( L_61 , V_229 -> V_229 ) ;
F_232 ( F_85 ( V_3 ) -> V_63 ,
V_781 , & V_53 , & V_162 ) ;
V_284 = F_73 ( V_53 , F_85 ( V_3 ) , & V_162 , & args . V_159 ,
& V_55 . V_160 , 0 ) ;
F_8 ( L_62 , V_284 ) ;
if ( V_329 )
F_192 ( V_329 ) ;
return V_284 ;
}
int F_489 ( struct V_2 * V_3 , const struct V_459 * V_229 ,
struct V_776 * V_452 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( F_85 ( V_3 ) -> V_63 ) )
V_8 = F_487 ( V_3 , V_229 , V_452 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_487 ( V_3 , V_229 , V_452 , false ) ;
F_490 ( V_3 , V_229 , V_8 ) ;
V_8 = F_19 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static int F_491 ( T_1 V_206 )
{
if ( V_206 & ~ V_782 )
goto V_783;
if ( ( V_206 & V_784 ) &&
( V_206 & V_785 ) )
goto V_783;
if ( ! ( V_206 & ( V_786 ) ) )
goto V_783;
return V_343 ;
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
int F_493 ( struct V_63 * V_64 , struct V_294 * V_329 )
{
int V_284 ;
struct V_793 V_55 ;
struct V_161 V_162 = {
. V_289 =
& V_290 [ V_794 ] ,
. V_292 = V_64 ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
F_8 ( L_12 , V_35 ) ;
V_55 . V_135 = F_86 ( sizeof( struct V_134 ) , V_281 ) ;
if ( F_343 ( V_55 . V_135 == NULL ) ) {
V_284 = - V_127 ;
goto V_132;
}
V_284 = F_368 ( V_64 -> V_102 , & V_162 , V_582 ) ;
F_494 ( V_64 , V_284 ) ;
if ( V_284 == 0 ) {
if ( memcmp ( V_55 . V_135 -> V_795 . V_157 ,
V_64 -> V_88 -> V_795 . V_157 , V_796 ) ) {
F_8 ( L_63 , V_35 ) ;
V_284 = - V_36 ;
goto V_797;
}
if ( V_55 . V_3 != V_798 ) {
F_8 ( L_64 ,
V_35 ) ;
V_284 = - V_36 ;
goto V_797;
}
if ( V_55 . V_799 ) {
F_8 ( L_65 ,
V_35 ) ;
V_284 = - V_36 ;
goto V_797;
}
}
V_797:
F_96 ( V_55 . V_135 ) ;
V_132:
F_8 ( L_66 , V_35 , V_284 ) ;
return V_284 ;
}
static int F_495 ( struct V_63 * V_64 ,
struct V_800 * V_204 )
{
static const T_1 V_801 [ V_802 ] = {
[ 1 ] = 1 << ( V_803 - 32 ) |
1 << ( V_804 - 32 ) |
1 << ( V_805 - 32 ) |
1 << ( V_806 - 32 ) |
1 << ( V_807 - 32 )
} ;
unsigned int V_449 ;
if ( V_204 -> V_808 == V_809 ) {
F_496 ( V_810 , L_67 ) ;
for ( V_449 = 0 ; V_449 <= V_811 ; V_449 ++ ) {
if ( F_31 ( V_449 , V_204 -> V_812 . V_237 . V_813 ) )
F_496 ( V_810 , L_68 , V_449 ) ;
if ( F_31 ( V_449 , V_204 -> V_814 . V_237 . V_813 ) )
F_496 ( V_810 , L_69 , V_449 ) ;
}
for ( V_449 = 0 ; V_449 < V_802 ; V_449 ++ ) {
if ( V_204 -> V_812 . V_237 . V_815 [ V_449 ] & ~ V_801 [ V_449 ] ) {
F_496 ( V_810 , L_70 ) ;
return - V_27 ;
}
}
if ( F_31 ( V_803 , V_204 -> V_812 . V_237 . V_813 ) &&
F_31 ( V_805 , V_204 -> V_812 . V_237 . V_813 ) &&
F_31 ( V_806 , V_204 -> V_812 . V_237 . V_813 ) &&
F_31 ( V_807 , V_204 -> V_812 . V_237 . V_813 ) ) {
F_496 ( V_810 , L_71 ) ;
F_496 ( V_810 , L_72 ) ;
F_116 ( V_816 , & V_64 -> V_817 ) ;
} else {
F_496 ( V_810 , L_70 ) ;
return - V_27 ;
}
if ( F_31 ( V_818 , V_204 -> V_814 . V_237 . V_813 ) &&
F_31 ( V_819 , V_204 -> V_814 . V_237 . V_813 ) ) {
F_496 ( V_810 , L_73 ) ;
F_116 ( V_397 , & V_64 -> V_817 ) ;
}
if ( F_31 ( V_820 , V_204 -> V_814 . V_237 . V_813 ) &&
F_31 ( V_821 , V_204 -> V_814 . V_237 . V_813 ) ) {
F_496 ( V_810 , L_74 ) ;
F_116 ( V_781 , & V_64 -> V_817 ) ;
}
if ( F_31 ( V_822 , V_204 -> V_814 . V_237 . V_813 ) &&
F_31 ( V_823 , V_204 -> V_814 . V_237 . V_813 ) ) {
F_496 ( V_810 , L_75 ) ;
F_116 ( V_824 , & V_64 -> V_817 ) ;
}
if ( F_31 ( V_825 , V_204 -> V_814 . V_237 . V_813 ) ) {
F_496 ( V_810 , L_76 ) ;
F_116 ( V_826 , & V_64 -> V_817 ) ;
}
if ( F_31 ( V_827 , V_204 -> V_814 . V_237 . V_813 ) ) {
F_496 ( V_810 , L_77 ) ;
F_116 ( V_828 , & V_64 -> V_817 ) ;
}
}
return 0 ;
}
static int F_497 ( struct V_63 * V_64 , struct V_294 * V_329 ,
T_1 V_829 )
{
T_12 V_38 ;
struct V_830 args = {
. V_38 = & V_38 ,
. V_92 = V_64 ,
#ifdef F_498
. V_206 = V_831 |
V_832 |
V_833 ,
#else
. V_206 = V_831 |
V_832 ,
#endif
} ;
struct V_834 V_55 = {
0
} ;
int V_284 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_835 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
F_400 ( V_64 , & V_38 ) ;
args . V_836 = F_406 ( V_64 , args . V_225 ,
sizeof( args . V_225 ) ) ;
F_8 ( L_78 ,
V_64 -> V_102 -> V_103 -> V_664 -> V_665 ,
args . V_836 , args . V_225 ) ;
V_55 . V_837 = F_86 ( sizeof( struct V_838 ) ,
V_281 ) ;
if ( F_343 ( V_55 . V_837 == NULL ) ) {
V_284 = - V_127 ;
goto V_132;
}
V_55 . V_792 = F_86 ( sizeof( struct V_788 ) ,
V_281 ) ;
if ( F_343 ( V_55 . V_792 == NULL ) ) {
V_284 = - V_127 ;
goto V_839;
}
V_55 . V_840 = F_86 ( sizeof( struct V_841 ) , V_281 ) ;
if ( F_343 ( V_55 . V_840 == NULL ) ) {
V_284 = - V_127 ;
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
V_284 = - V_27 ;
goto V_842;
}
V_284 = F_368 ( V_64 -> V_102 , & V_162 , V_582 ) ;
F_500 ( V_64 , V_284 ) ;
if ( V_284 == 0 )
V_284 = F_491 ( V_55 . V_206 ) ;
if ( V_284 == 0 )
V_284 = F_495 ( V_64 , & V_55 . V_844 ) ;
if ( V_284 == 0 ) {
V_64 -> V_224 = V_55 . V_223 ;
V_64 -> V_846 = ( V_55 . V_206 & ~ V_847 ) ;
if ( ! ( V_55 . V_206 & V_847 ) )
V_64 -> V_848 = V_55 . V_195 ;
F_96 ( V_64 -> V_849 ) ;
V_64 -> V_849 = V_55 . V_837 ;
V_55 . V_837 = NULL ;
F_96 ( V_64 -> V_850 ) ;
V_64 -> V_850 = V_55 . V_840 ;
if ( V_64 -> V_851 != NULL &&
! F_492 ( V_64 -> V_851 ,
V_55 . V_792 ) ) {
F_8 ( L_79 ,
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
F_8 ( L_80
L_81 ,
V_64 -> V_850 -> V_853 , V_64 -> V_850 -> V_229 ,
V_64 -> V_850 -> V_854 . V_855 ,
V_64 -> V_850 -> V_854 . V_856 ) ;
F_8 ( L_82 , V_284 ) ;
return V_284 ;
}
int F_501 ( struct V_63 * V_64 , struct V_294 * V_329 )
{
T_4 V_857 = V_64 -> V_102 -> V_103 -> V_104 ;
int V_284 ;
if ( V_857 == V_105 ||
V_857 == V_106 ) {
V_284 = F_497 ( V_64 , V_329 , V_809 ) ;
if ( ! V_284 )
return 0 ;
}
return F_497 ( V_64 , V_329 , V_843 ) ;
}
static int F_502 ( struct V_63 * V_64 ,
struct V_294 * V_329 )
{
struct V_161 V_162 = {
. V_289 = & V_290 [ V_858 ] ,
. V_292 = V_64 ,
. V_294 = V_329 ,
} ;
int V_284 ;
V_284 = F_368 ( V_64 -> V_102 , & V_162 , V_582 ) ;
F_503 ( V_64 , V_284 ) ;
if ( V_284 )
F_8 ( L_83
L_84 , V_284 , V_64 -> V_98 ) ;
return V_284 ;
}
static int F_504 ( struct V_63 * V_64 ,
struct V_294 * V_329 )
{
unsigned int V_859 ;
int V_67 ;
for ( V_859 = V_860 ; V_859 != 0 ; V_859 -- ) {
V_67 = F_502 ( V_64 , V_329 ) ;
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
struct V_294 * V_329 ;
int V_67 = 0 ;
if ( V_64 -> V_167 -> V_311 < 1 )
goto V_132;
if ( V_64 -> V_846 == 0 )
goto V_132;
if ( V_64 -> V_862 )
goto V_132;
V_329 = F_488 ( V_64 ) ;
V_67 = F_504 ( V_64 , V_329 ) ;
if ( V_329 )
F_192 ( V_329 ) ;
switch ( V_67 ) {
case 0 :
case - V_77 :
V_64 -> V_846 = 0 ;
}
V_132:
return V_67 ;
}
static void F_506 ( struct V_117 * V_118 ,
void * V_155 )
{
struct V_863 * V_157 =
(struct V_863 * ) V_155 ;
F_8 ( L_12 , V_35 ) ;
F_61 ( V_157 -> V_64 -> V_88 ,
& V_157 -> args -> V_864 ,
& V_157 -> V_55 -> V_865 ,
V_118 ) ;
F_8 ( L_85 , V_35 ) ;
}
static void F_507 ( struct V_117 * V_118 , void * V_155 )
{
struct V_863 * V_157 =
(struct V_863 * ) V_155 ;
F_8 ( L_12 , V_35 ) ;
if ( ! F_54 ( V_118 , & V_157 -> V_55 -> V_865 ) )
return;
switch ( V_118 -> V_149 ) {
case - V_91 :
case - V_90 :
F_8 ( L_86 , V_35 , V_118 -> V_149 ) ;
F_59 ( V_118 , V_56 ) ;
V_118 -> V_149 = 0 ;
case - V_93 :
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
int F_508 ( struct V_63 * V_64 , struct V_435 * V_537 )
{
struct V_117 * V_118 ;
struct V_866 args ;
struct V_867 V_55 = {
. V_868 = V_537 ,
} ;
struct V_863 V_157 = {
. args = & args ,
. V_55 = & V_55 ,
. V_64 = V_64 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_869 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
struct V_163 V_164 = {
. V_165 = V_64 -> V_102 ,
. V_161 = & V_162 ,
. V_166 = & V_870 ,
. V_169 = & V_157 ,
. V_206 = V_582 ,
} ;
int V_284 ;
F_38 ( & args . V_864 , & V_55 . V_865 , 0 ) ;
F_39 ( & args . V_864 ) ;
F_8 ( L_12 , V_35 ) ;
V_118 = F_70 ( & V_164 ) ;
if ( F_43 ( V_118 ) )
V_284 = F_71 ( V_118 ) ;
else {
V_284 = V_118 -> V_149 ;
F_72 ( V_118 ) ;
}
F_8 ( L_87 , V_35 , V_284 ) ;
return V_284 ;
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
F_8 ( L_88
L_89 ,
V_35 ,
args -> V_877 . V_872 , args -> V_877 . V_873 ,
args -> V_877 . V_878 , args -> V_877 . V_880 ) ;
args -> V_882 . V_872 = V_591 ;
args -> V_882 . V_873 = V_591 ;
args -> V_882 . V_883 = 0 ;
args -> V_882 . V_878 = V_884 ;
args -> V_882 . V_880 = 1 ;
F_8 ( L_90
L_91 ,
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
struct V_294 * V_329 )
{
struct V_134 * V_135 = V_64 -> V_88 ;
struct V_871 args = {
. V_92 = V_64 ,
. V_889 = V_890 ,
} ;
struct V_891 V_55 = {
. V_92 = V_64 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_892 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
int V_284 ;
F_509 ( & args ) ;
args . V_206 = ( V_893 | V_894 ) ;
V_284 = F_368 ( V_135 -> V_64 -> V_102 , & V_162 , V_582 ) ;
F_514 ( V_64 , V_284 ) ;
if ( ! V_284 ) {
V_284 = F_512 ( & args , V_135 ) ;
V_64 -> V_848 ++ ;
}
return V_284 ;
}
int F_515 ( struct V_63 * V_64 , struct V_294 * V_329 )
{
int V_284 ;
unsigned * V_895 ;
struct V_134 * V_135 = V_64 -> V_88 ;
F_8 ( L_92 , V_35 , V_64 , V_135 ) ;
V_284 = F_513 ( V_64 , V_329 ) ;
if ( V_284 )
goto V_132;
V_284 = F_516 ( V_135 ) ;
F_8 ( L_93 , V_284 ) ;
if ( V_284 )
goto V_132;
V_895 = ( unsigned * ) & V_135 -> V_795 . V_157 [ 0 ] ;
F_8 ( L_94 , V_35 ,
V_64 -> V_848 , V_895 [ 0 ] , V_895 [ 1 ] , V_895 [ 2 ] , V_895 [ 3 ] ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
return V_284 ;
}
int F_517 ( struct V_134 * V_135 ,
struct V_294 * V_329 )
{
struct V_161 V_162 = {
. V_289 = & V_290 [ V_896 ] ,
. V_292 = V_135 ,
. V_294 = V_329 ,
} ;
int V_284 = 0 ;
F_8 ( L_95 ) ;
if ( V_135 -> V_64 -> V_897 != V_898 )
return V_284 ;
V_284 = F_368 ( V_135 -> V_64 -> V_102 , & V_162 , V_582 ) ;
F_518 ( V_135 -> V_64 , V_284 ) ;
if ( V_284 )
F_8 ( L_96
L_97 , V_284 ) ;
F_8 ( L_98 ) ;
return V_284 ;
}
static void F_519 ( void * V_157 )
{
struct V_899 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
if ( F_358 ( & V_64 -> V_576 ) > 1 )
F_359 ( V_64 ) ;
F_360 ( V_64 ) ;
F_96 ( V_155 ) ;
}
static int F_520 ( struct V_117 * V_118 , struct V_63 * V_64 )
{
switch( V_118 -> V_149 ) {
case - V_91 :
F_59 ( V_118 , V_57 ) ;
return - V_131 ;
default:
F_24 ( V_64 ) ;
}
return 0 ;
}
static void F_521 ( struct V_117 * V_118 , void * V_157 )
{
struct V_899 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
if ( ! F_54 ( V_118 , V_118 -> V_305 . V_293 ) )
return;
F_522 ( V_64 , V_118 -> V_149 ) ;
if ( V_118 -> V_149 < 0 ) {
F_8 ( L_99 , V_35 , V_118 -> V_149 ) ;
if ( F_358 ( & V_64 -> V_576 ) == 1 )
goto V_132;
if ( F_520 ( V_118 , V_64 ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
F_8 ( L_100 , V_35 , V_118 -> V_305 . V_294 ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
}
static void F_523 ( struct V_117 * V_118 , void * V_157 )
{
struct V_899 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
struct V_110 * args ;
struct V_111 * V_55 ;
args = V_118 -> V_305 . V_292 ;
V_55 = V_118 -> V_305 . V_293 ;
F_61 ( V_64 -> V_88 , args , V_55 , V_118 ) ;
}
static struct V_117 * F_524 ( struct V_63 * V_64 ,
struct V_294 * V_329 ,
bool V_900 )
{
struct V_899 * V_155 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_901 ] ,
. V_294 = V_329 ,
} ;
struct V_163 V_295 = {
. V_165 = V_64 -> V_102 ,
. V_161 = & V_162 ,
. V_166 = & V_902 ,
. V_206 = V_299 | V_582 ,
} ;
if ( ! F_365 ( & V_64 -> V_576 ) )
return F_44 ( - V_36 ) ;
V_155 = F_86 ( sizeof( * V_155 ) , V_281 ) ;
if ( V_155 == NULL ) {
F_360 ( V_64 ) ;
return F_44 ( - V_127 ) ;
}
F_38 ( & V_155 -> args , & V_155 -> V_55 , 0 ) ;
if ( V_900 )
F_39 ( & V_155 -> args ) ;
V_162 . V_292 = & V_155 -> args ;
V_162 . V_293 = & V_155 -> V_55 ;
V_155 -> V_64 = V_64 ;
V_295 . V_169 = V_155 ;
return F_70 ( & V_295 ) ;
}
static int F_525 ( struct V_63 * V_64 , struct V_294 * V_329 , unsigned V_580 )
{
struct V_117 * V_118 ;
int V_67 = 0 ;
if ( ( V_580 & V_903 ) == 0 )
return 0 ;
V_118 = F_524 ( V_64 , V_329 , false ) ;
if ( F_43 ( V_118 ) )
V_67 = F_71 ( V_118 ) ;
else
F_443 ( V_118 ) ;
F_8 ( L_17 , V_35 , V_67 ) ;
return V_67 ;
}
static int F_526 ( struct V_63 * V_64 , struct V_294 * V_329 )
{
struct V_117 * V_118 ;
int V_67 ;
V_118 = F_524 ( V_64 , V_329 , true ) ;
if ( F_43 ( V_118 ) ) {
V_67 = F_71 ( V_118 ) ;
goto V_132;
}
V_67 = F_108 ( V_118 ) ;
if ( ! V_67 ) {
struct V_111 * V_55 = V_118 -> V_305 . V_293 ;
if ( V_118 -> V_149 == 0 )
F_527 ( V_64 , V_55 -> V_145 ) ;
V_67 = V_118 -> V_149 ;
}
F_72 ( V_118 ) ;
V_132:
F_8 ( L_17 , V_35 , V_67 ) ;
return V_67 ;
}
static void F_528 ( struct V_117 * V_118 , void * V_157 )
{
struct V_904 * V_155 = V_157 ;
F_61 ( V_155 -> V_64 -> V_88 ,
& V_155 -> V_372 . V_159 ,
& V_155 -> V_55 . V_160 ,
V_118 ) ;
}
static int F_529 ( struct V_117 * V_118 , struct V_63 * V_64 )
{
switch( V_118 -> V_149 ) {
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
static void F_530 ( struct V_117 * V_118 , void * V_157 )
{
struct V_904 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
struct V_111 * V_55 = & V_155 -> V_55 . V_160 ;
F_8 ( L_12 , V_35 ) ;
if ( ! F_54 ( V_118 , V_55 ) )
return;
F_531 ( V_64 , V_118 -> V_149 ) ;
if ( F_529 ( V_118 , V_64 ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
static void F_532 ( void * V_157 )
{
struct V_904 * V_155 = V_157 ;
F_96 ( V_155 ) ;
}
static int F_533 ( struct V_63 * V_64 ,
struct V_294 * V_329 )
{
struct V_904 * V_155 ;
struct V_117 * V_118 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_906 ] ,
. V_294 = V_329 ,
} ;
struct V_163 V_295 = {
. V_165 = V_64 -> V_102 ,
. V_161 = & V_162 ,
. V_166 = & V_907 ,
. V_206 = V_299 ,
} ;
int V_284 = - V_127 ;
F_8 ( L_12 , V_35 ) ;
V_155 = F_86 ( sizeof( * V_155 ) , V_281 ) ;
if ( V_155 == NULL )
goto V_132;
V_155 -> V_64 = V_64 ;
V_155 -> V_372 . V_908 = 0 ;
F_38 ( & V_155 -> V_372 . V_159 , & V_155 -> V_55 . V_160 , 0 ) ;
F_39 ( & V_155 -> V_372 . V_159 ) ;
V_162 . V_292 = & V_155 -> V_372 ;
V_162 . V_293 = & V_155 -> V_55 ;
V_295 . V_169 = V_155 ;
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) ) {
V_284 = F_71 ( V_118 ) ;
goto V_132;
}
V_284 = F_107 ( V_118 ) ;
if ( V_284 == 0 )
V_284 = V_118 -> V_149 ;
F_72 ( V_118 ) ;
return 0 ;
V_132:
F_8 ( L_17 , V_35 , V_284 ) ;
return V_284 ;
}
static void
F_534 ( struct V_117 * V_118 , void * V_155 )
{
struct V_909 * V_910 = V_155 ;
struct V_13 * V_14 = F_85 ( V_910 -> args . V_2 ) ;
struct V_134 * V_135 = F_64 ( V_14 ) ;
F_8 ( L_12 , V_35 ) ;
if ( F_61 ( V_135 , & V_910 -> args . V_159 ,
& V_910 -> V_55 . V_160 , V_118 ) )
return;
if ( F_535 ( & V_910 -> args . V_239 ,
F_75 ( V_910 -> args . V_2 ) -> V_911 ,
V_910 -> args . V_279 -> V_66 ) ) {
F_536 ( V_118 , V_764 ) ;
}
}
static void F_537 ( struct V_117 * V_118 , void * V_155 )
{
struct V_909 * V_910 = V_155 ;
struct V_2 * V_2 = V_910 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_912 * V_913 ;
struct V_65 * V_66 = NULL ;
unsigned long V_914 , V_915 ;
F_8 ( L_12 , V_35 ) ;
if ( ! F_54 ( V_118 , & V_910 -> V_55 . V_160 ) )
goto V_132;
switch ( V_118 -> V_149 ) {
case 0 :
goto V_132;
case - V_19 :
case - V_20 :
V_914 = F_538 ( V_118 -> V_916 ) ;
V_915 = V_910 -> args . V_107 + V_914 ;
if ( F_539 ( V_915 , V_154 ) )
V_118 -> V_149 = - V_91 ;
break;
case - V_75 :
case - V_74 :
F_34 ( & V_2 -> V_174 ) ;
V_913 = F_75 ( V_2 ) -> V_911 ;
if ( ! V_913 || F_540 ( & V_913 -> V_917 ) ) {
F_36 ( & V_2 -> V_174 ) ;
V_66 = V_910 -> args . V_279 -> V_66 ;
} else {
F_541 ( V_918 ) ;
F_542 ( V_913 , & V_918 , NULL ) ;
F_36 ( & V_2 -> V_174 ) ;
F_543 ( & V_918 ) ;
}
}
if ( F_228 ( V_118 , V_14 , V_66 ) == - V_131 )
F_57 ( V_118 ) ;
V_132:
F_8 ( L_85 , V_35 ) ;
}
static T_9 F_544 ( struct V_13 * V_14 )
{
T_1 V_873 = V_14 -> V_63 -> V_88 -> V_877 . V_873 ;
return F_545 ( 0 , V_873 ) ;
}
static void F_546 ( struct V_460 * * V_43 , T_9 V_919 )
{
int V_449 ;
if ( ! V_43 )
return;
for ( V_449 = 0 ; V_449 < V_919 ; V_449 ++ ) {
if ( ! V_43 [ V_449 ] )
break;
F_260 ( V_43 [ V_449 ] ) ;
}
F_96 ( V_43 ) ;
}
static struct V_460 * * F_547 ( T_9 V_919 , T_6 V_920 )
{
struct V_460 * * V_43 ;
int V_449 ;
V_43 = F_548 ( V_919 , sizeof( struct V_460 * ) , V_920 ) ;
if ( ! V_43 ) {
F_8 ( L_101 , V_35 , V_919 ) ;
return NULL ;
}
for ( V_449 = 0 ; V_449 < V_919 ; V_449 ++ ) {
V_43 [ V_449 ] = F_256 ( V_920 ) ;
if ( ! V_43 [ V_449 ] ) {
F_8 ( L_102 , V_35 ) ;
F_546 ( V_43 , V_919 ) ;
return NULL ;
}
}
return V_43 ;
}
static void F_549 ( void * V_155 )
{
struct V_909 * V_910 = V_155 ;
struct V_2 * V_2 = V_910 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_921 = F_544 ( V_14 ) ;
F_8 ( L_12 , V_35 ) ;
F_546 ( V_910 -> args . V_911 . V_43 , V_921 ) ;
F_550 ( F_75 ( V_2 ) -> V_911 ) ;
F_155 ( V_910 -> args . V_279 ) ;
F_96 ( V_155 ) ;
F_8 ( L_85 , V_35 ) ;
}
struct V_922 *
F_551 ( struct V_909 * V_910 , T_6 V_920 )
{
struct V_2 * V_2 = V_910 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_921 = F_544 ( V_14 ) ;
struct V_117 * V_118 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_923 ] ,
. V_292 = & V_910 -> args ,
. V_293 = & V_910 -> V_55 ,
. V_294 = V_910 -> V_329 ,
} ;
struct V_163 V_295 = {
. V_165 = V_14 -> V_92 ,
. V_161 = & V_162 ,
. V_166 = & V_924 ,
. V_169 = V_910 ,
. V_206 = V_299 ,
} ;
struct V_922 * V_925 = NULL ;
int V_284 = 0 ;
F_8 ( L_12 , V_35 ) ;
V_910 -> args . V_911 . V_43 = F_547 ( V_921 , V_920 ) ;
if ( ! V_910 -> args . V_911 . V_43 ) {
F_549 ( V_910 ) ;
return F_44 ( - V_127 ) ;
}
V_910 -> args . V_911 . V_486 = V_921 * V_591 ;
V_910 -> args . V_107 = V_154 ;
V_910 -> V_55 . V_926 = & V_910 -> args . V_911 ;
V_910 -> V_55 . V_160 . V_116 = NULL ;
F_38 ( & V_910 -> args . V_159 , & V_910 -> V_55 . V_160 , 0 ) ;
F_552 ( F_75 ( V_2 ) -> V_911 ) ;
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) )
return F_235 ( V_118 ) ;
V_284 = F_107 ( V_118 ) ;
if ( V_284 == 0 )
V_284 = V_118 -> V_149 ;
F_553 ( V_910 -> args . V_279 ,
& V_910 -> args . V_927 ,
& V_910 -> V_55 . V_927 ,
V_284 ) ;
if ( V_284 == 0 && V_910 -> V_55 . V_926 -> V_12 )
V_925 = F_554 ( V_910 ) ;
F_72 ( V_118 ) ;
F_8 ( L_17 , V_35 , V_284 ) ;
if ( V_284 )
return F_44 ( V_284 ) ;
return V_925 ;
}
static void
F_555 ( struct V_117 * V_118 , void * V_155 )
{
struct V_928 * V_929 = V_155 ;
F_8 ( L_12 , V_35 ) ;
F_61 ( V_929 -> V_64 -> V_88 ,
& V_929 -> args . V_159 ,
& V_929 -> V_55 . V_160 ,
V_118 ) ;
}
static void F_556 ( struct V_117 * V_118 , void * V_155 )
{
struct V_928 * V_929 = V_155 ;
struct V_13 * V_14 ;
F_8 ( L_12 , V_35 ) ;
if ( ! F_54 ( V_118 , & V_929 -> V_55 . V_160 ) )
return;
V_14 = F_85 ( V_929 -> args . V_2 ) ;
switch ( V_118 -> V_149 ) {
default:
V_118 -> V_149 = 0 ;
case 0 :
break;
case - V_91 :
if ( F_228 ( V_118 , V_14 , NULL ) != - V_131 )
break;
F_57 ( V_118 ) ;
return;
}
F_8 ( L_85 , V_35 ) ;
}
static void F_557 ( void * V_155 )
{
struct V_928 * V_929 = V_155 ;
struct V_912 * V_913 = V_929 -> args . V_911 ;
F_8 ( L_12 , V_35 ) ;
F_34 ( & V_913 -> V_930 -> V_174 ) ;
if ( V_929 -> V_55 . V_931 )
F_558 ( V_913 , & V_929 -> V_55 . V_239 , true ) ;
V_913 -> V_932 -- ;
F_36 ( & V_913 -> V_930 -> V_174 ) ;
F_550 ( V_929 -> args . V_911 ) ;
F_96 ( V_155 ) ;
F_8 ( L_85 , V_35 ) ;
}
int F_559 ( struct V_928 * V_929 )
{
struct V_117 * V_118 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_933 ] ,
. V_292 = & V_929 -> args ,
. V_293 = & V_929 -> V_55 ,
. V_294 = V_929 -> V_329 ,
} ;
struct V_163 V_295 = {
. V_165 = F_85 ( V_929 -> args . V_2 ) -> V_92 ,
. V_161 = & V_162 ,
. V_166 = & V_934 ,
. V_169 = V_929 ,
} ;
int V_284 ;
F_8 ( L_12 , V_35 ) ;
F_38 ( & V_929 -> args . V_159 , & V_929 -> V_55 . V_160 , 1 ) ;
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_284 = V_118 -> V_149 ;
F_560 ( V_929 -> args . V_2 , V_284 ) ;
F_8 ( L_17 , V_35 , V_284 ) ;
F_72 ( V_118 ) ;
return V_284 ;
}
static int F_561 ( struct V_13 * V_14 ,
const struct V_402 * V_233 ,
struct V_935 * V_936 )
{
struct V_937 args = {
. V_233 = V_233 ,
. V_938 = V_14 -> V_939 -> V_225 ,
} ;
struct V_940 V_55 = {
. V_936 = V_936 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_941 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
int V_284 ;
F_8 ( L_12 , V_35 ) ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 ,
& V_55 . V_160 , 0 ) ;
F_8 ( L_17 , V_35 , V_284 ) ;
return V_284 ;
}
int F_562 ( struct V_13 * V_14 ,
const struct V_402 * V_233 ,
struct V_935 * V_936 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_561 ( V_14 , V_233 , V_936 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
F_8 ( L_103 , V_35 ,
V_8 , V_936 -> V_942 ) ;
return V_8 ;
}
static int
F_563 ( struct V_13 * V_14 ,
struct V_943 * V_944 ,
struct V_294 * V_329 )
{
struct V_945 args = {
. V_944 = V_944 ,
} ;
struct V_946 V_55 = {
. V_944 = V_944 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_947 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
int V_284 ;
F_8 ( L_12 , V_35 ) ;
V_284 = F_73 ( V_14 -> V_92 , V_14 , & V_162 , & args . V_159 , & V_55 . V_160 , 0 ) ;
F_8 ( L_17 , V_35 , V_284 ) ;
return V_284 ;
}
int F_564 ( struct V_13 * V_14 ,
struct V_943 * V_944 ,
struct V_294 * V_329 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_19 ( V_14 ,
F_563 ( V_14 , V_944 , V_329 ) ,
& V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_565 ( struct V_117 * V_118 , void * V_155 )
{
struct V_948 * V_157 = V_155 ;
struct V_13 * V_14 = F_85 ( V_157 -> args . V_2 ) ;
struct V_134 * V_135 = F_64 ( V_14 ) ;
F_61 ( V_135 ,
& V_157 -> args . V_159 ,
& V_157 -> V_55 . V_160 ,
V_118 ) ;
}
static void
F_566 ( struct V_117 * V_118 , void * V_155 )
{
struct V_948 * V_157 = V_155 ;
struct V_13 * V_14 = F_85 ( V_157 -> args . V_2 ) ;
if ( ! F_54 ( V_118 , & V_157 -> V_55 . V_160 ) )
return;
switch ( V_118 -> V_149 ) {
case - V_72 :
case - V_949 :
case - V_950 :
case - V_90 :
V_118 -> V_149 = 0 ;
break;
case 0 :
F_346 ( V_157 -> args . V_2 ,
V_157 -> V_55 . V_369 ) ;
break;
default:
if ( F_228 ( V_118 , V_14 , NULL ) == - V_131 ) {
F_57 ( V_118 ) ;
return;
}
}
}
static void F_567 ( void * V_155 )
{
struct V_948 * V_157 = V_155 ;
F_568 ( V_157 ) ;
F_192 ( V_157 -> V_329 ) ;
F_96 ( V_157 ) ;
}
int
F_569 ( struct V_948 * V_157 , bool V_951 )
{
struct V_161 V_162 = {
. V_289 = & V_290 [ V_952 ] ,
. V_292 = & V_157 -> args ,
. V_293 = & V_157 -> V_55 ,
. V_294 = V_157 -> V_329 ,
} ;
struct V_163 V_295 = {
. V_118 = & V_157 -> V_118 ,
. V_165 = F_273 ( V_157 -> args . V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_953 ,
. V_169 = V_157 ,
. V_206 = V_299 ,
} ;
struct V_117 * V_118 ;
int V_284 = 0 ;
F_8 ( L_104
L_105 ,
V_157 -> V_118 . V_954 , V_951 ,
V_157 -> args . V_955 ,
V_157 -> args . V_2 -> V_956 ) ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_55 . V_160 , 1 ) ;
V_118 = F_70 ( & V_295 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
if ( V_951 == false )
goto V_132;
V_284 = F_107 ( V_118 ) ;
if ( V_284 != 0 )
goto V_132;
V_284 = V_118 -> V_149 ;
F_570 ( V_157 -> args . V_2 , V_284 ) ;
V_132:
F_8 ( L_106 , V_35 , V_284 ) ;
F_72 ( V_118 ) ;
return V_284 ;
}
static int
F_571 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_436 ,
struct V_776 * V_452 , bool V_777 )
{
struct V_957 args = {
. V_958 = V_959 ,
} ;
struct V_779 V_55 = {
. V_452 = V_452 ,
} ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_960 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
} ;
struct V_52 * V_53 = V_14 -> V_92 ;
struct V_294 * V_329 = NULL ;
int V_284 ;
if ( V_777 ) {
V_53 = V_14 -> V_63 -> V_102 ;
V_329 = F_488 ( V_14 -> V_63 ) ;
V_162 . V_294 = V_329 ;
}
F_8 ( L_12 , V_35 ) ;
V_284 = F_73 ( V_53 , V_14 , & V_162 , & args . V_159 ,
& V_55 . V_160 , 0 ) ;
F_8 ( L_17 , V_35 , V_284 ) ;
if ( V_329 )
F_192 ( V_329 ) ;
return V_284 ;
}
static int
F_572 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_436 , struct V_776 * V_452 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( V_14 -> V_63 ) )
V_8 = F_571 ( V_14 , V_403 , V_436 ,
V_452 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_571 ( V_14 , V_403 , V_436 ,
V_452 , false ) ;
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
F_573 ( struct V_13 * V_14 , struct V_402 * V_403 ,
struct V_435 * V_436 )
{
int V_8 ;
struct V_460 * V_460 ;
T_4 V_101 = V_962 ;
struct V_776 * V_452 ;
struct V_963 * V_964 ;
int V_449 ;
V_460 = F_256 ( V_360 ) ;
if ( ! V_460 ) {
V_8 = - V_127 ;
goto V_132;
}
V_452 = F_372 ( V_460 ) ;
V_8 = F_572 ( V_14 , V_403 , V_436 , V_452 ) ;
if ( V_8 == - V_22 || V_8 == - V_961 ) {
V_8 = F_246 ( V_14 , V_403 , V_436 ) ;
goto V_965;
}
if ( V_8 )
goto V_965;
for ( V_449 = 0 ; V_449 < V_452 -> V_966 ; V_449 ++ ) {
V_964 = & V_452 -> V_452 [ V_449 ] ;
switch ( V_964 -> V_101 ) {
case V_448 :
case V_447 :
case V_967 :
V_101 = F_574 ( V_964 -> V_101 ,
& V_964 -> V_968 ) ;
break;
default:
V_101 = V_962 ;
break;
}
if ( ! F_575 ( & V_14 -> V_450 , V_101 ) )
V_101 = V_962 ;
if ( V_101 != V_962 ) {
V_8 = F_244 ( V_14 , V_403 ,
V_436 , V_101 ) ;
if ( ! V_8 )
break;
}
}
if ( V_101 == V_962 )
V_8 = - V_24 ;
V_965:
F_386 ( V_460 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_132:
return V_8 ;
}
static int F_576 ( struct V_13 * V_14 ,
T_8 * V_239 ,
struct V_294 * V_329 )
{
int V_284 ;
struct V_969 args = {
. V_239 = V_239 ,
} ;
struct V_970 V_55 ;
struct V_161 V_162 = {
. V_289 = & V_290 [ V_971 ] ,
. V_292 = & args ,
. V_293 = & V_55 ,
. V_294 = V_329 ,
} ;
struct V_52 * V_165 = V_14 -> V_92 ;
F_232 ( V_14 -> V_63 , V_824 ,
& V_165 , & V_162 ) ;
F_8 ( L_107 , V_239 ) ;
F_38 ( & args . V_159 , & V_55 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_284 = F_69 ( V_165 , V_14 , & V_162 ,
& args . V_159 , & V_55 . V_160 ) ;
if ( V_284 != V_343 ) {
F_8 ( L_108 , V_284 ) ;
return V_284 ;
}
F_8 ( L_109 , - V_55 . V_284 ) ;
return - V_55 . V_284 ;
}
static int F_189 ( struct V_13 * V_14 ,
T_8 * V_239 ,
struct V_294 * V_329 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_576 ( V_14 , V_239 , V_329 ) ;
if ( V_8 != - V_91 )
break;
F_19 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_68 );
return V_8 ;
}
static void F_577 ( struct V_117 * V_118 , void * V_155 )
{
struct V_972 * V_157 = V_155 ;
F_61 ( F_64 ( V_157 -> V_14 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_55 . V_160 ,
V_118 ) ;
}
static void F_578 ( struct V_117 * V_118 , void * V_155 )
{
struct V_972 * V_157 = V_155 ;
F_54 ( V_118 , & V_157 -> V_55 . V_160 ) ;
switch ( V_118 -> V_149 ) {
case - V_91 :
if ( F_228 ( V_118 , V_157 -> V_14 , NULL ) == - V_131 )
F_57 ( V_118 ) ;
}
}
static void F_579 ( void * V_155 )
{
F_96 ( V_155 ) ;
}
static struct V_117 * F_580 ( struct V_13 * V_14 ,
T_8 * V_239 ,
struct V_294 * V_329 ,
bool V_973 )
{
struct V_161 V_162 = {
. V_289 = & V_290 [ V_974 ] ,
. V_294 = V_329 ,
} ;
struct V_163 V_164 = {
. V_165 = V_14 -> V_92 ,
. V_161 = & V_162 ,
. V_166 = & V_975 ,
. V_206 = V_299 ,
} ;
struct V_972 * V_157 ;
F_232 ( V_14 -> V_63 , V_824 ,
& V_164 . V_165 , & V_162 ) ;
F_8 ( L_110 , V_239 ) ;
V_157 = F_257 ( sizeof( * V_157 ) , V_281 ) ;
if ( ! V_157 )
return F_44 ( - V_127 ) ;
V_157 -> V_14 = V_14 ;
F_115 ( & V_157 -> args . V_239 , V_239 ) ;
V_164 . V_169 = V_157 ;
V_162 . V_292 = & V_157 -> args ;
V_162 . V_293 = & V_157 -> V_55 ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_55 . V_160 , 0 ) ;
if ( V_973 )
F_39 ( & V_157 -> args . V_159 ) ;
return F_70 ( & V_164 ) ;
}
static int F_191 ( struct V_13 * V_14 ,
T_8 * V_239 ,
struct V_294 * V_329 )
{
struct V_117 * V_118 ;
int V_67 ;
V_118 = F_580 ( V_14 , V_239 , V_329 , true ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
V_67 = F_108 ( V_118 ) ;
if ( ! V_67 )
V_67 = V_118 -> V_149 ;
F_72 ( V_118 ) ;
return V_67 ;
}
static int F_581 ( struct V_13 * V_14 , struct V_681 * V_682 )
{
struct V_117 * V_118 ;
struct V_294 * V_329 = V_682 -> V_698 -> V_214 -> V_269 ;
V_118 = F_580 ( V_14 , & V_682 -> V_699 , V_329 , false ) ;
F_465 ( V_14 , V_682 ) ;
if ( F_43 ( V_118 ) )
return F_71 ( V_118 ) ;
F_72 ( V_118 ) ;
return 0 ;
}
static bool F_582 ( const T_8 * V_976 ,
const T_8 * V_977 )
{
if ( memcmp ( V_976 -> V_978 , V_977 -> V_978 , sizeof( V_976 -> V_978 ) ) != 0 )
return false ;
if ( V_976 -> V_195 == V_977 -> V_195 )
return true ;
if ( V_976 -> V_195 == 0 || V_977 -> V_195 == 0 )
return true ;
return false ;
}
static bool F_583 ( const T_8 * V_976 ,
const T_8 * V_977 )
{
return F_124 ( V_976 , V_977 ) ;
}
