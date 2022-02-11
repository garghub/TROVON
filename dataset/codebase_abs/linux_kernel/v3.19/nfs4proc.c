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
static int F_40 ( const struct V_13 * V_14 ,
struct V_109 * args ,
struct V_110 * V_57 ,
struct V_116 * V_117 )
{
struct V_118 * V_119 = V_14 -> V_63 -> V_120 ;
struct V_121 * V_122 ;
if ( V_57 -> V_115 != NULL )
goto V_123;
F_34 ( & V_119 -> V_124 ) ;
if ( F_41 ( V_119 ) && ! args -> V_114 )
goto V_125;
V_122 = F_42 ( V_119 ) ;
if ( F_43 ( V_122 ) ) {
if ( V_122 == F_44 ( - V_126 ) )
V_117 -> V_127 = V_88 >> 2 ;
goto V_125;
}
F_36 ( & V_119 -> V_124 ) ;
args -> V_112 = V_122 ;
V_57 -> V_115 = V_122 ;
V_123:
F_45 ( V_117 ) ;
return 0 ;
V_125:
if ( args -> V_114 )
F_46 ( & V_119 -> V_128 , V_117 ,
NULL , V_129 ) ;
else
F_47 ( & V_119 -> V_128 , V_117 , NULL ) ;
F_36 ( & V_119 -> V_124 ) ;
return - V_130 ;
}
static int F_48 ( struct V_116 * V_117 ,
struct V_110 * V_57 )
{
struct V_121 * V_122 = V_57 -> V_115 ;
struct V_118 * V_119 ;
if ( V_122 == NULL )
goto V_131;
V_119 = V_122 -> V_132 ;
F_34 ( & V_119 -> V_124 ) ;
if ( ! F_49 ( V_119 , V_122 ) )
F_50 ( V_119 , V_122 ) ;
F_36 ( & V_119 -> V_124 ) ;
V_57 -> V_115 = NULL ;
V_131:
return 1 ;
}
static void F_51 ( struct V_110 * V_57 )
{
struct V_133 * V_134 ;
struct V_118 * V_119 ;
struct V_121 * V_122 = V_57 -> V_115 ;
bool V_135 = false ;
V_119 = V_122 -> V_132 ;
V_134 = V_119 -> V_134 ;
F_34 ( & V_119 -> V_124 ) ;
if ( V_119 -> V_136 > V_119 -> V_137 )
V_135 = true ;
if ( F_49 ( V_119 , V_122 ) ) {
V_135 = false ;
goto V_138;
}
F_50 ( V_119 , V_122 ) ;
if ( V_119 -> V_136 != V_139 )
V_135 = false ;
V_138:
F_36 ( & V_119 -> V_124 ) ;
V_57 -> V_115 = NULL ;
if ( V_135 )
F_52 ( V_134 -> V_64 ) ;
}
int F_53 ( struct V_116 * V_117 , struct V_110 * V_57 )
{
struct V_133 * V_134 ;
struct V_121 * V_122 = V_57 -> V_115 ;
struct V_63 * V_64 ;
bool V_140 = false ;
int V_52 = 1 ;
if ( V_122 == NULL )
goto V_141;
if ( ! F_54 ( V_117 ) )
goto V_131;
V_134 = V_122 -> V_132 -> V_134 ;
if ( V_122 -> V_140 ) {
V_122 -> V_140 = 0 ;
V_140 = true ;
}
F_55 ( V_134 , V_57 ) ;
switch ( V_57 -> V_142 ) {
case 0 :
++ V_122 -> V_143 ;
V_64 = V_134 -> V_64 ;
F_33 ( V_64 , V_57 -> V_144 ) ;
if ( V_57 -> V_145 != 0 )
F_24 ( V_64 ) ;
F_56 ( V_122 -> V_132 , V_122 , V_57 ) ;
break;
case 1 :
V_122 -> V_140 = 1 ;
goto V_131;
case - V_90 :
F_8 ( L_9 ,
V_34 ,
V_122 -> V_146 ,
V_122 -> V_143 ) ;
goto V_147;
case - V_81 :
goto V_148;
case - V_86 :
if ( V_140 ) {
++ V_122 -> V_143 ;
goto V_148;
}
if ( V_122 -> V_143 != 1 ) {
V_122 -> V_143 = 1 ;
goto V_148;
}
break;
case - V_85 :
++ V_122 -> V_143 ;
goto V_148;
default:
++ V_122 -> V_143 ;
}
V_131:
F_8 ( L_10 , V_34 , V_57 -> V_142 ) ;
F_51 ( V_57 ) ;
V_141:
return V_52 ;
V_148:
if ( F_57 ( V_117 ) ) {
V_117 -> V_149 = 0 ;
V_52 = 0 ;
}
goto V_131;
V_147:
if ( ! F_58 ( V_117 ) )
goto V_131;
F_59 ( V_117 , V_53 ) ;
return 0 ;
}
static int F_60 ( struct V_116 * V_117 ,
struct V_110 * V_57 )
{
if ( V_57 -> V_115 == NULL )
return 1 ;
if ( ! V_57 -> V_115 -> V_132 -> V_134 )
return F_48 ( V_117 , V_57 ) ;
return F_53 ( V_117 , V_57 ) ;
}
int F_61 ( struct V_133 * V_134 ,
struct V_109 * args ,
struct V_110 * V_57 ,
struct V_116 * V_117 )
{
struct V_121 * V_122 ;
struct V_118 * V_119 ;
F_8 ( L_11 , V_34 ) ;
if ( V_57 -> V_115 != NULL )
goto V_150;
V_119 = & V_134 -> V_151 ;
V_117 -> V_127 = 0 ;
F_34 ( & V_119 -> V_124 ) ;
if ( F_31 ( V_152 , & V_119 -> V_153 ) &&
! args -> V_114 ) {
F_8 ( L_12 , V_34 ) ;
goto V_125;
}
V_122 = F_42 ( V_119 ) ;
if ( F_43 ( V_122 ) ) {
if ( V_122 == F_44 ( - V_126 ) )
V_117 -> V_127 = V_88 >> 2 ;
F_8 ( L_13 , V_34 ) ;
goto V_125;
}
F_36 ( & V_119 -> V_124 ) ;
args -> V_112 = V_122 ;
F_8 ( L_14 , V_34 ,
V_122 -> V_146 , V_122 -> V_143 ) ;
V_57 -> V_115 = V_122 ;
V_57 -> V_144 = V_154 ;
V_57 -> V_145 = 0 ;
V_57 -> V_142 = 1 ;
F_62 ( V_134 , args ) ;
V_150:
F_45 ( V_117 ) ;
return 0 ;
V_125:
if ( args -> V_114 )
F_46 ( & V_119 -> V_128 , V_117 ,
NULL , V_129 ) ;
else
F_47 ( & V_119 -> V_128 , V_117 , NULL ) ;
F_36 ( & V_119 -> V_124 ) ;
return - V_130 ;
}
static int F_63 ( const struct V_13 * V_14 ,
struct V_109 * args ,
struct V_110 * V_57 ,
struct V_116 * V_117 )
{
struct V_133 * V_134 = F_64 ( V_14 ) ;
int V_52 = 0 ;
if ( ! V_134 )
return F_40 ( V_14 , args , V_57 , V_117 ) ;
F_8 ( L_15 ,
V_34 , V_134 -> V_64 , V_134 , V_57 -> V_115 ?
V_57 -> V_115 -> V_146 : V_139 ) ;
V_52 = F_61 ( V_134 , args , V_57 , V_117 ) ;
F_8 ( L_16 , V_34 , V_52 ) ;
return V_52 ;
}
static void F_65 ( struct V_116 * V_117 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
struct V_133 * V_134 = F_64 ( V_157 -> V_158 ) ;
F_8 ( L_17 , V_34 , V_157 -> V_158 ) ;
F_61 ( V_134 , V_157 -> V_159 , V_157 -> V_160 , V_117 ) ;
}
static void F_66 ( struct V_116 * V_117 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_53 ( V_117 , V_157 -> V_160 ) ;
}
static int F_63 ( const struct V_13 * V_14 ,
struct V_109 * args ,
struct V_110 * V_57 ,
struct V_116 * V_117 )
{
return F_40 ( V_14 , args , V_57 , V_117 ) ;
}
static int F_60 ( struct V_116 * V_117 ,
struct V_110 * V_57 )
{
return F_48 ( V_117 , V_57 ) ;
}
static void F_67 ( struct V_116 * V_117 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_63 ( V_157 -> V_158 ,
V_157 -> V_159 , V_157 -> V_160 , V_117 ) ;
}
static void F_68 ( struct V_116 * V_117 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
F_60 ( V_117 , V_157 -> V_160 ) ;
}
static int F_69 ( struct V_55 * V_56 ,
struct V_13 * V_14 ,
struct V_161 * V_162 ,
struct V_109 * args ,
struct V_110 * V_57 )
{
int V_52 ;
struct V_116 * V_117 ;
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
V_117 = F_70 ( & V_164 ) ;
if ( F_43 ( V_117 ) )
V_52 = F_71 ( V_117 ) ;
else {
V_52 = V_117 -> V_149 ;
F_72 ( V_117 ) ;
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
F_77 ( V_3 ) ;
F_36 ( & V_3 -> V_174 ) ;
}
static bool F_78 ( struct V_13 * V_14 ,
int V_8 , struct V_61 * V_62 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_94 & V_182 ) )
return false ;
V_14 -> V_94 &= ~ V_182 ;
V_62 -> V_67 = 1 ;
return true ;
}
static enum V_183
F_79 ( struct V_13 * V_14 ,
enum V_183 V_184 )
{
if ( V_14 -> V_94 & V_182 )
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
static void F_80 ( struct V_191 * V_41 )
{
V_41 -> V_192 . V_193 = & V_41 -> V_193 ;
V_41 -> V_192 . V_194 = V_41 -> V_194 ;
V_41 -> V_192 . V_195 = V_41 -> V_196 . V_195 ;
V_41 -> V_197 . V_195 = V_41 -> V_198 . V_195 ;
V_41 -> V_192 . V_14 = V_41 -> V_196 . V_14 ;
V_41 -> V_192 . V_199 = V_41 -> V_196 . V_200 ;
F_81 ( & V_41 -> V_193 ) ;
F_82 ( & V_41 -> V_193 , & V_41 -> V_201 , & V_41 -> V_202 ) ;
}
static struct V_191 * F_83 ( struct V_4 * V_4 ,
struct V_203 * V_204 , T_5 V_205 , int V_206 ,
const struct V_5 * V_207 ,
struct V_1 * V_7 ,
enum V_183 V_184 ,
T_6 V_208 )
{
struct V_4 * V_209 = F_84 ( V_4 ) ;
struct V_2 * V_3 = V_209 -> V_46 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_191 * V_41 ;
V_41 = F_86 ( sizeof( * V_41 ) , V_208 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_194 = F_87 ( V_14 , V_208 ) ;
if ( F_43 ( V_41 -> V_194 ) )
goto V_210;
V_41 -> V_196 . V_195 = F_88 ( & V_204 -> V_211 , V_208 ) ;
if ( V_41 -> V_196 . V_195 == NULL )
goto V_212;
F_89 ( V_4 -> V_213 ) ;
V_41 -> V_4 = F_90 ( V_4 ) ;
V_41 -> V_3 = V_209 ;
V_41 -> V_214 = V_204 ;
F_91 ( & V_204 -> V_215 ) ;
V_41 -> V_196 . V_216 = V_206 ;
V_41 -> V_196 . V_205 = V_205 & ( V_69 | V_217 ) ;
if ( ! ( V_206 & V_218 ) ) {
V_41 -> V_196 . V_200 = V_219 | V_220 |
V_221 | V_222 ;
}
V_41 -> V_196 . V_223 = V_14 -> V_63 -> V_224 ;
V_41 -> V_196 . V_225 . V_226 = F_92 ( V_204 -> V_211 . V_226 ) ;
V_41 -> V_196 . V_225 . V_227 = V_204 -> V_211 . V_228 ;
V_41 -> V_196 . V_229 = & V_4 -> V_11 ;
V_41 -> V_196 . V_14 = V_14 ;
V_41 -> V_196 . V_230 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_196 . V_231 = & V_232 [ 0 ] ;
V_41 -> V_196 . V_7 = V_7 ;
V_41 -> V_196 . V_184 = F_79 ( V_14 , V_184 ) ;
switch ( V_41 -> V_196 . V_184 ) {
case V_186 :
case V_188 :
case V_190 :
V_41 -> V_196 . V_233 = F_93 ( V_3 ) ;
break;
case V_234 :
case V_185 :
case V_187 :
case V_189 :
V_41 -> V_196 . V_233 = F_93 ( V_4 -> V_46 ) ;
}
if ( V_207 != NULL && V_207 -> V_235 != 0 ) {
T_7 V_236 [ 2 ] ;
V_41 -> V_196 . V_237 . V_207 = & V_41 -> V_207 ;
memcpy ( & V_41 -> V_207 , V_207 , sizeof( V_41 -> V_207 ) ) ;
V_236 [ 0 ] = V_154 ;
V_236 [ 1 ] = V_58 -> V_238 ;
memcpy ( V_41 -> V_196 . V_237 . V_37 . V_157 , V_236 ,
sizeof( V_41 -> V_196 . V_237 . V_37 . V_157 ) ) ;
}
V_41 -> V_198 . V_233 = & V_41 -> V_192 . V_233 ;
V_41 -> V_198 . V_239 = & V_41 -> V_192 . V_239 ;
V_41 -> V_198 . V_195 = V_41 -> V_196 . V_195 ;
F_80 ( V_41 ) ;
F_94 ( & V_41 -> V_240 ) ;
return V_41 ;
V_212:
F_95 ( V_41 -> V_194 ) ;
V_210:
F_96 ( V_41 ) ;
V_8:
F_97 ( V_209 ) ;
return NULL ;
}
static void F_98 ( struct V_240 * V_240 )
{
struct V_191 * V_41 = F_99 ( V_240 ,
struct V_191 , V_240 ) ;
struct V_241 * V_242 = V_41 -> V_4 -> V_213 ;
F_100 ( V_41 -> V_196 . V_195 ) ;
if ( V_41 -> V_66 != NULL )
F_101 ( V_41 -> V_66 ) ;
F_102 ( V_41 -> V_214 ) ;
F_95 ( V_41 -> V_194 ) ;
F_97 ( V_41 -> V_3 ) ;
F_97 ( V_41 -> V_4 ) ;
F_103 ( V_242 ) ;
F_104 ( & V_41 -> V_193 ) ;
F_96 ( V_41 -> V_193 . V_243 ) ;
F_96 ( V_41 ) ;
}
static void F_105 ( struct V_191 * V_41 )
{
if ( V_41 != NULL )
F_106 ( & V_41 -> V_240 , F_98 ) ;
}
static int F_107 ( struct V_116 * V_117 )
{
int V_52 ;
V_52 = F_108 ( V_117 ) ;
return V_52 ;
}
static int F_109 ( struct V_65 * V_66 , T_5 V_244 , int V_245 )
{
int V_52 = 0 ;
if ( V_245 & ( V_218 | V_246 ) )
goto V_131;
switch ( V_244 & ( V_69 | V_217 ) ) {
case V_69 :
V_52 |= F_31 ( V_247 , & V_66 -> V_206 ) != 0
&& V_66 -> V_248 != 0 ;
break;
case V_217 :
V_52 |= F_31 ( V_249 , & V_66 -> V_206 ) != 0
&& V_66 -> V_250 != 0 ;
break;
case V_69 | V_217 :
V_52 |= F_31 ( V_251 , & V_66 -> V_206 ) != 0
&& V_66 -> V_252 != 0 ;
}
V_131:
return V_52 ;
}
static int F_110 ( struct V_253 * V_254 , T_5 V_205 )
{
if ( V_254 == NULL )
return 0 ;
if ( ( V_254 -> type & V_205 ) != V_205 )
return 0 ;
if ( F_31 ( V_255 , & V_254 -> V_206 ) )
return 0 ;
F_111 ( V_254 ) ;
return 1 ;
}
static void F_112 ( struct V_65 * V_66 , T_5 V_205 )
{
switch ( V_205 ) {
case V_217 :
V_66 -> V_250 ++ ;
break;
case V_69 :
V_66 -> V_248 ++ ;
break;
case V_69 | V_217 :
V_66 -> V_252 ++ ;
}
F_113 ( V_66 , V_66 -> V_66 | V_205 ) ;
}
static void F_114 ( struct V_65 * V_66 )
{
struct V_63 * V_64 = V_66 -> V_214 -> V_256 -> V_63 ;
bool V_257 = false ;
if ( F_115 ( V_247 , & V_66 -> V_206 ) && V_66 -> V_248 )
V_257 = true ;
if ( F_115 ( V_249 , & V_66 -> V_206 ) && V_66 -> V_250 )
V_257 = true ;
if ( F_115 ( V_251 , & V_66 -> V_206 ) && V_66 -> V_252 )
V_257 = true ;
if ( V_257 )
F_116 ( V_64 , V_66 ) ;
}
static bool F_117 ( struct V_65 * V_66 ,
T_8 * V_239 )
{
if ( F_118 ( V_258 , & V_66 -> V_206 ) == 0 )
return true ;
if ( ! F_119 ( V_239 , & V_66 -> V_259 ) ) {
F_114 ( V_66 ) ;
return true ;
}
if ( F_120 ( V_239 , & V_66 -> V_259 ) )
return true ;
return false ;
}
static void F_121 ( struct V_65 * V_66 ,
T_8 * V_239 , T_5 V_205 )
{
F_122 ( V_251 , & V_66 -> V_206 ) ;
switch ( V_205 & ( V_69 | V_217 ) ) {
case V_217 :
F_122 ( V_247 , & V_66 -> V_206 ) ;
break;
case V_69 :
F_122 ( V_249 , & V_66 -> V_206 ) ;
break;
case 0 :
F_122 ( V_247 , & V_66 -> V_206 ) ;
F_122 ( V_249 , & V_66 -> V_206 ) ;
F_122 ( V_258 , & V_66 -> V_206 ) ;
}
if ( V_239 == NULL )
return;
if ( ! F_117 ( V_66 , V_239 ) )
return;
if ( F_31 ( V_260 , & V_66 -> V_206 ) == 0 )
F_123 ( & V_66 -> V_239 , V_239 ) ;
F_123 ( & V_66 -> V_259 , V_239 ) ;
}
static void F_124 ( struct V_65 * V_66 , T_8 * V_239 , T_5 V_205 )
{
F_125 ( & V_66 -> V_261 ) ;
F_121 ( V_66 , V_239 , V_205 ) ;
F_126 ( & V_66 -> V_261 ) ;
if ( F_31 ( V_262 , & V_66 -> V_206 ) )
F_127 ( V_66 -> V_214 -> V_256 -> V_63 ) ;
}
static void F_128 ( struct V_65 * V_66 , T_8 * V_239 , T_5 V_205 )
{
switch ( V_205 ) {
case V_69 :
F_129 ( V_247 , & V_66 -> V_206 ) ;
break;
case V_217 :
F_129 ( V_249 , & V_66 -> V_206 ) ;
break;
case V_69 | V_217 :
F_129 ( V_251 , & V_66 -> V_206 ) ;
}
if ( ! F_117 ( V_66 , V_239 ) )
return;
if ( F_31 ( V_260 , & V_66 -> V_206 ) == 0 )
F_123 ( & V_66 -> V_239 , V_239 ) ;
F_123 ( & V_66 -> V_259 , V_239 ) ;
}
static void F_130 ( struct V_65 * V_66 , T_8 * V_259 , const T_8 * V_263 , T_5 V_205 )
{
F_125 ( & V_66 -> V_261 ) ;
if ( V_263 != NULL ) {
F_123 ( & V_66 -> V_239 , V_263 ) ;
F_129 ( V_260 , & V_66 -> V_206 ) ;
}
if ( V_259 != NULL )
F_128 ( V_66 , V_259 , V_205 ) ;
F_126 ( & V_66 -> V_261 ) ;
F_34 ( & V_66 -> V_214 -> V_264 ) ;
F_112 ( V_66 , V_205 ) ;
F_36 ( & V_66 -> V_214 -> V_264 ) ;
}
static int F_131 ( struct V_65 * V_66 , T_8 * V_259 , T_8 * V_254 , T_5 V_205 )
{
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_253 * V_265 ;
int V_52 = 0 ;
V_205 &= ( V_69 | V_217 ) ;
F_132 () ;
V_265 = F_133 ( V_173 -> V_254 ) ;
if ( V_265 == NULL )
goto V_266;
F_34 ( & V_265 -> V_267 ) ;
if ( F_133 ( V_173 -> V_254 ) != V_265 ||
F_31 ( V_255 , & V_265 -> V_206 ) ||
( V_265 -> type & V_205 ) != V_205 )
goto V_268;
if ( V_254 == NULL )
V_254 = & V_265 -> V_239 ;
else if ( ! F_134 ( & V_265 -> V_239 , V_254 ) )
goto V_268;
F_111 ( V_265 ) ;
F_130 ( V_66 , V_259 , & V_265 -> V_239 , V_205 ) ;
V_52 = 1 ;
V_268:
F_36 ( & V_265 -> V_267 ) ;
V_266:
F_135 () ;
if ( ! V_52 && V_259 != NULL ) {
F_130 ( V_66 , V_259 , NULL , V_205 ) ;
V_52 = 1 ;
}
if ( F_31 ( V_262 , & V_66 -> V_206 ) )
F_127 ( V_66 -> V_214 -> V_256 -> V_63 ) ;
return V_52 ;
}
static void F_136 ( struct V_2 * V_2 , T_5 V_205 )
{
struct V_253 * V_254 ;
F_132 () ;
V_254 = F_133 ( F_75 ( V_2 ) -> V_254 ) ;
if ( V_254 == NULL || ( V_254 -> type & V_205 ) == V_205 ) {
F_135 () ;
return;
}
F_135 () ;
F_22 ( V_2 ) ;
}
static struct V_65 * F_137 ( struct V_191 * V_269 )
{
struct V_65 * V_66 = V_269 -> V_66 ;
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_253 * V_254 ;
int V_245 = V_269 -> V_196 . V_216 ;
T_5 V_205 = V_269 -> V_196 . V_205 ;
T_8 V_239 ;
int V_52 = - V_130 ;
for (; ; ) {
F_34 ( & V_66 -> V_214 -> V_264 ) ;
if ( F_109 ( V_66 , V_205 , V_245 ) ) {
F_112 ( V_66 , V_205 ) ;
F_36 ( & V_66 -> V_214 -> V_264 ) ;
goto V_270;
}
F_36 ( & V_66 -> V_214 -> V_264 ) ;
F_132 () ;
V_254 = F_133 ( V_173 -> V_254 ) ;
if ( ! F_110 ( V_254 , V_205 ) ) {
F_135 () ;
break;
}
F_123 ( & V_239 , & V_254 -> V_239 ) ;
F_135 () ;
F_138 ( V_269 -> V_196 . V_195 ) ;
if ( ! V_269 -> V_271 ) {
V_52 = F_139 ( V_66 -> V_2 , V_66 -> V_214 -> V_272 , V_245 ) ;
if ( V_52 != 0 )
goto V_131;
}
V_52 = - V_130 ;
if ( F_131 ( V_66 , NULL , & V_239 , V_205 ) )
goto V_270;
}
V_131:
return F_44 ( V_52 ) ;
V_270:
F_91 ( & V_66 -> V_50 ) ;
return V_66 ;
}
static void
F_140 ( struct V_191 * V_157 , struct V_65 * V_66 )
{
struct V_63 * V_64 = F_85 ( V_66 -> V_2 ) -> V_63 ;
struct V_253 * V_254 ;
int V_273 = 0 ;
F_132 () ;
V_254 = F_133 ( F_75 ( V_66 -> V_2 ) -> V_254 ) ;
if ( V_254 )
V_273 = V_254 -> V_206 ;
F_135 () ;
if ( V_157 -> V_196 . V_184 == V_188 ) {
F_141 ( L_18
L_19
L_20 ,
V_64 -> V_97 ) ;
} else if ( ( V_273 & 1UL << V_274 ) == 0 )
F_142 ( V_66 -> V_2 ,
V_157 -> V_214 -> V_272 ,
& V_157 -> V_192 ) ;
else
F_143 ( V_66 -> V_2 ,
V_157 -> V_214 -> V_272 ,
& V_157 -> V_192 ) ;
}
static struct V_65 *
F_144 ( struct V_191 * V_157 )
{
struct V_2 * V_2 = V_157 -> V_66 -> V_2 ;
struct V_65 * V_66 = V_157 -> V_66 ;
int V_52 ;
if ( ! V_157 -> V_275 ) {
if ( V_157 -> V_276 ) {
V_52 = V_157 -> V_276 ;
goto V_8;
}
goto V_277;
}
V_52 = F_145 ( V_2 , & V_157 -> V_193 ) ;
if ( V_52 )
goto V_8;
if ( V_157 -> V_192 . V_278 != 0 )
F_140 ( V_157 , V_66 ) ;
V_277:
F_131 ( V_66 , & V_157 -> V_192 . V_239 , NULL ,
V_157 -> V_196 . V_205 ) ;
F_91 ( & V_66 -> V_50 ) ;
return V_66 ;
V_8:
return F_44 ( V_52 ) ;
}
static struct V_65 *
F_146 ( struct V_191 * V_157 )
{
struct V_2 * V_2 ;
struct V_65 * V_66 = NULL ;
int V_52 ;
if ( ! V_157 -> V_275 ) {
V_66 = F_137 ( V_157 ) ;
goto V_131;
}
V_52 = - V_130 ;
if ( ! ( V_157 -> V_193 . V_279 & V_280 ) )
goto V_8;
V_2 = F_147 ( V_157 -> V_3 -> V_213 , & V_157 -> V_192 . V_233 , & V_157 -> V_193 , V_157 -> V_194 ) ;
V_52 = F_71 ( V_2 ) ;
if ( F_43 ( V_2 ) )
goto V_8;
V_52 = - V_126 ;
V_66 = F_148 ( V_2 , V_157 -> V_214 ) ;
if ( V_66 == NULL )
goto V_281;
if ( V_157 -> V_192 . V_278 != 0 )
F_140 ( V_157 , V_66 ) ;
F_131 ( V_66 , & V_157 -> V_192 . V_239 , NULL ,
V_157 -> V_196 . V_205 ) ;
F_149 ( V_2 ) ;
V_131:
F_138 ( V_157 -> V_196 . V_195 ) ;
return V_66 ;
V_281:
F_149 ( V_2 ) ;
V_8:
return F_44 ( V_52 ) ;
}
static struct V_65 *
F_150 ( struct V_191 * V_157 )
{
if ( V_157 -> V_196 . V_184 == V_234 )
return F_144 ( V_157 ) ;
return F_146 ( V_157 ) ;
}
static struct V_282 * F_151 ( struct V_65 * V_66 )
{
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
struct V_282 * V_283 ;
F_34 ( & V_66 -> V_2 -> V_174 ) ;
F_152 (ctx, &nfsi->open_files, list) {
if ( V_283 -> V_66 != V_66 )
continue;
F_153 ( V_283 ) ;
F_36 ( & V_66 -> V_2 -> V_174 ) ;
return V_283 ;
}
F_36 ( & V_66 -> V_2 -> V_174 ) ;
return F_44 ( - V_284 ) ;
}
static struct V_191 * F_154 ( struct V_282 * V_283 ,
struct V_65 * V_66 , enum V_183 V_184 )
{
struct V_191 * V_269 ;
V_269 = F_83 ( V_283 -> V_4 , V_66 -> V_214 , 0 , 0 ,
NULL , NULL , V_184 , V_285 ) ;
if ( V_269 == NULL )
return F_44 ( - V_126 ) ;
V_269 -> V_66 = V_66 ;
F_91 ( & V_66 -> V_50 ) ;
return V_269 ;
}
static int F_155 ( struct V_191 * V_269 , T_5 V_205 , struct V_65 * * V_57 )
{
struct V_65 * V_286 ;
int V_52 ;
V_269 -> V_196 . V_216 = 0 ;
V_269 -> V_196 . V_205 = V_205 ;
memset ( & V_269 -> V_192 , 0 , sizeof( V_269 -> V_192 ) ) ;
memset ( & V_269 -> V_197 , 0 , sizeof( V_269 -> V_197 ) ) ;
F_80 ( V_269 ) ;
V_52 = F_156 ( V_269 ) ;
if ( V_52 != 0 )
return V_52 ;
V_286 = F_150 ( V_269 ) ;
if ( F_43 ( V_286 ) )
return F_71 ( V_286 ) ;
F_157 ( V_286 , V_205 ) ;
* V_57 = V_286 ;
return 0 ;
}
static int F_158 ( struct V_191 * V_269 , struct V_65 * V_66 )
{
struct V_65 * V_286 ;
int V_52 ;
F_122 ( V_251 , & V_66 -> V_206 ) ;
F_122 ( V_249 , & V_66 -> V_206 ) ;
F_122 ( V_247 , & V_66 -> V_206 ) ;
F_122 ( V_260 , & V_66 -> V_206 ) ;
F_122 ( V_258 , & V_66 -> V_206 ) ;
F_159 () ;
if ( V_66 -> V_252 != 0 ) {
V_52 = F_155 ( V_269 , V_69 | V_217 , & V_286 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_286 != V_66 )
return - V_287 ;
}
if ( V_66 -> V_250 != 0 ) {
V_52 = F_155 ( V_269 , V_217 , & V_286 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_286 != V_66 )
return - V_287 ;
}
if ( V_66 -> V_248 != 0 ) {
V_52 = F_155 ( V_269 , V_69 , & V_286 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_286 != V_66 )
return - V_287 ;
}
if ( F_31 ( V_260 , & V_66 -> V_206 ) == 0 &&
! F_134 ( & V_66 -> V_239 , & V_66 -> V_259 ) ) {
F_125 ( & V_66 -> V_261 ) ;
if ( F_31 ( V_260 , & V_66 -> V_206 ) == 0 )
F_123 ( & V_66 -> V_239 , & V_66 -> V_259 ) ;
F_126 ( & V_66 -> V_261 ) ;
}
return 0 ;
}
static int F_160 ( struct V_282 * V_283 , struct V_65 * V_66 )
{
struct V_253 * V_254 ;
struct V_191 * V_269 ;
T_5 V_278 = 0 ;
int V_288 ;
V_269 = F_154 ( V_283 , V_66 ,
V_234 ) ;
if ( F_43 ( V_269 ) )
return F_71 ( V_269 ) ;
F_132 () ;
V_254 = F_133 ( F_75 ( V_66 -> V_2 ) -> V_254 ) ;
if ( V_254 != NULL && F_31 ( V_274 , & V_254 -> V_206 ) != 0 )
V_278 = V_254 -> type ;
F_135 () ;
V_269 -> V_196 . V_237 . V_278 = V_278 ;
V_288 = F_158 ( V_269 , V_66 ) ;
F_105 ( V_269 ) ;
return V_288 ;
}
static int F_161 ( struct V_282 * V_283 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_160 ( V_283 , V_66 ) ;
F_162 ( V_283 , 0 , V_8 ) ;
if ( F_78 ( V_14 , V_8 , & V_62 ) )
continue;
if ( V_8 != - V_90 )
break;
F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_163 ( struct V_203 * V_204 , struct V_65 * V_66 )
{
struct V_282 * V_283 ;
int V_52 ;
V_283 = F_151 ( V_66 ) ;
if ( F_43 ( V_283 ) )
return - V_130 ;
V_52 = F_161 ( V_283 , V_66 ) ;
F_164 ( V_283 ) ;
return V_52 ;
}
static int F_165 ( struct V_13 * V_14 , struct V_65 * V_66 , const T_8 * V_239 , int V_8 )
{
switch ( V_8 ) {
default:
F_29 ( V_289 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_284 :
case - V_287 :
break;
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
F_129 ( V_260 , & V_66 -> V_206 ) ;
F_28 ( V_14 -> V_63 -> V_87 , V_8 ) ;
return - V_130 ;
case - V_76 :
case - V_75 :
F_129 ( V_260 , & V_66 -> V_206 ) ;
case - V_74 :
F_24 ( V_14 -> V_63 ) ;
return - V_130 ;
case - V_77 :
F_25 ( V_14 ) ;
return - V_130 ;
case - V_78 :
F_26 ( V_14 -> V_63 ) ;
return - V_130 ;
case - V_71 :
case - V_72 :
case - V_73 :
case - V_68 :
F_166 ( V_66 -> V_2 ,
V_239 ) ;
F_23 ( V_14 , V_66 ) ;
return - V_130 ;
case - V_90 :
case - V_89 :
F_129 ( V_260 , & V_66 -> V_206 ) ;
F_167 ( 1 ) ;
return - V_130 ;
case - V_126 :
case - V_290 :
return 0 ;
}
return V_8 ;
}
int F_168 ( struct V_282 * V_283 , struct V_65 * V_66 , const T_8 * V_239 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_191 * V_269 ;
int V_8 ;
V_269 = F_154 ( V_283 , V_66 ,
V_187 ) ;
if ( F_43 ( V_269 ) )
return F_71 ( V_269 ) ;
F_123 ( & V_269 -> V_196 . V_237 . V_254 , V_239 ) ;
V_8 = F_158 ( V_269 , V_66 ) ;
F_105 ( V_269 ) ;
return F_165 ( V_14 , V_66 , V_239 , V_8 ) ;
}
static void F_169 ( struct V_116 * V_117 , void * V_155 )
{
struct V_191 * V_157 = V_155 ;
F_40 ( V_157 -> V_196 . V_14 , & V_157 -> V_198 . V_159 ,
& V_157 -> V_197 . V_160 , V_117 ) ;
}
static void F_170 ( struct V_116 * V_117 , void * V_155 )
{
struct V_191 * V_157 = V_155 ;
F_48 ( V_117 , & V_157 -> V_197 . V_160 ) ;
V_157 -> V_276 = V_117 -> V_149 ;
if ( V_157 -> V_276 == 0 ) {
F_123 ( & V_157 -> V_192 . V_239 , & V_157 -> V_197 . V_239 ) ;
F_171 ( & V_157 -> V_214 -> V_211 , 0 ) ;
F_37 ( V_157 -> V_192 . V_14 , V_157 -> V_106 ) ;
V_157 -> V_275 = 1 ;
}
}
static void F_172 ( void * V_155 )
{
struct V_191 * V_157 = V_155 ;
struct V_65 * V_66 = NULL ;
if ( V_157 -> V_291 == 0 )
goto V_292;
if ( ! V_157 -> V_275 )
goto V_292;
V_66 = F_150 ( V_157 ) ;
if ( ! F_43 ( V_66 ) )
F_157 ( V_66 , V_157 -> V_196 . V_205 ) ;
V_292:
F_105 ( V_157 ) ;
}
static int F_173 ( struct V_191 * V_157 )
{
struct V_13 * V_14 = F_85 ( V_157 -> V_3 -> V_46 ) ;
struct V_116 * V_117 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_295 ] ,
. V_296 = & V_157 -> V_198 ,
. V_297 = & V_157 -> V_197 ,
. V_298 = V_157 -> V_214 -> V_272 ,
} ;
struct V_163 V_299 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_300 ,
. V_169 = V_157 ,
. V_301 = V_302 ,
. V_206 = V_303 ,
} ;
int V_288 ;
F_38 ( & V_157 -> V_198 . V_159 , & V_157 -> V_197 . V_160 , 1 ) ;
F_174 ( & V_157 -> V_240 ) ;
V_157 -> V_275 = 0 ;
V_157 -> V_276 = 0 ;
V_157 -> V_106 = V_154 ;
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) )
return F_71 ( V_117 ) ;
V_288 = F_107 ( V_117 ) ;
if ( V_288 != 0 ) {
V_157 -> V_291 = 1 ;
F_175 () ;
} else
V_288 = V_157 -> V_276 ;
F_72 ( V_117 ) ;
return V_288 ;
}
static void F_176 ( struct V_116 * V_117 , void * V_155 )
{
struct V_191 * V_157 = V_155 ;
struct V_203 * V_204 = V_157 -> V_214 ;
struct V_63 * V_64 = V_204 -> V_256 -> V_63 ;
if ( F_177 ( V_157 -> V_196 . V_195 , V_117 ) != 0 )
goto V_304;
if ( V_157 -> V_66 != NULL ) {
struct V_253 * V_254 ;
if ( F_109 ( V_157 -> V_66 , V_157 -> V_196 . V_205 , V_157 -> V_196 . V_216 ) )
goto V_305;
F_132 () ;
V_254 = F_133 ( F_75 ( V_157 -> V_66 -> V_2 ) -> V_254 ) ;
if ( V_157 -> V_196 . V_184 != V_188 &&
V_157 -> V_196 . V_184 != V_187 &&
F_110 ( V_254 , V_157 -> V_196 . V_205 ) )
goto V_306;
F_135 () ;
}
V_157 -> V_196 . V_223 = V_64 -> V_224 ;
switch ( V_157 -> V_196 . V_184 ) {
case V_234 :
case V_187 :
case V_189 :
V_157 -> V_196 . V_231 = & V_307 [ 0 ] ;
case V_185 :
V_117 -> V_308 . V_293 = & V_294 [ V_309 ] ;
F_178 ( & V_157 -> V_192 . V_233 , V_157 -> V_196 . V_233 ) ;
}
V_157 -> V_106 = V_154 ;
if ( F_63 ( V_157 -> V_196 . V_14 ,
& V_157 -> V_196 . V_159 ,
& V_157 -> V_192 . V_160 ,
V_117 ) != 0 )
F_138 ( V_157 -> V_196 . V_195 ) ;
V_157 -> V_196 . V_310 = V_311 ;
if ( V_157 -> V_196 . V_216 & V_218 ) {
V_157 -> V_196 . V_310 = V_312 ;
if ( F_179 ( V_64 ) )
V_157 -> V_196 . V_310 = V_313 ;
else if ( V_64 -> V_167 -> V_314 > 0 )
V_157 -> V_196 . V_310 = V_315 ;
}
return;
V_306:
F_135 () ;
V_305:
V_117 -> V_316 = NULL ;
V_304:
F_60 ( V_117 , & V_157 -> V_192 . V_160 ) ;
}
static void F_180 ( struct V_116 * V_117 , void * V_155 )
{
struct V_191 * V_157 = V_155 ;
V_157 -> V_276 = V_117 -> V_149 ;
if ( ! F_60 ( V_117 , & V_157 -> V_192 . V_160 ) )
return;
if ( V_117 -> V_149 == 0 ) {
if ( V_157 -> V_192 . V_193 -> V_279 & V_317 ) {
switch ( V_157 -> V_192 . V_193 -> V_244 & V_318 ) {
case V_319 :
break;
case V_320 :
V_157 -> V_276 = - V_321 ;
break;
case V_322 :
V_157 -> V_276 = - V_323 ;
break;
default:
V_157 -> V_276 = - V_324 ;
}
}
F_37 ( V_157 -> V_192 . V_14 , V_157 -> V_106 ) ;
if ( ! ( V_157 -> V_192 . V_325 & V_326 ) )
F_171 ( & V_157 -> V_214 -> V_211 , 0 ) ;
}
V_157 -> V_275 = 1 ;
}
static void F_181 ( void * V_155 )
{
struct V_191 * V_157 = V_155 ;
struct V_65 * V_66 = NULL ;
if ( V_157 -> V_291 == 0 )
goto V_292;
if ( V_157 -> V_276 != 0 || ! V_157 -> V_275 )
goto V_292;
if ( V_157 -> V_192 . V_325 & V_326 )
goto V_292;
V_66 = F_150 ( V_157 ) ;
if ( ! F_43 ( V_66 ) )
F_157 ( V_66 , V_157 -> V_196 . V_205 ) ;
V_292:
F_105 ( V_157 ) ;
}
static int F_182 ( struct V_191 * V_157 , int V_327 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_46 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_328 * V_196 = & V_157 -> V_196 ;
struct V_329 * V_192 = & V_157 -> V_192 ;
struct V_116 * V_117 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_330 ] ,
. V_296 = V_196 ,
. V_297 = V_192 ,
. V_298 = V_157 -> V_214 -> V_272 ,
} ;
struct V_163 V_299 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_331 ,
. V_169 = V_157 ,
. V_301 = V_302 ,
. V_206 = V_303 ,
} ;
int V_288 ;
F_38 ( & V_196 -> V_159 , & V_192 -> V_160 , 1 ) ;
F_174 ( & V_157 -> V_240 ) ;
V_157 -> V_275 = 0 ;
V_157 -> V_276 = 0 ;
V_157 -> V_291 = 0 ;
V_157 -> V_271 = 0 ;
if ( V_327 ) {
F_39 ( & V_196 -> V_159 ) ;
V_157 -> V_271 = 1 ;
}
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) )
return F_71 ( V_117 ) ;
V_288 = F_107 ( V_117 ) ;
if ( V_288 != 0 ) {
V_157 -> V_291 = 1 ;
F_175 () ;
} else
V_288 = V_157 -> V_276 ;
F_72 ( V_117 ) ;
return V_288 ;
}
static int F_156 ( struct V_191 * V_157 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_46 ;
struct V_329 * V_192 = & V_157 -> V_192 ;
int V_288 ;
V_288 = F_182 ( V_157 , 1 ) ;
if ( V_288 != 0 || ! V_157 -> V_275 )
return V_288 ;
F_183 ( F_85 ( V_3 ) , & V_157 -> V_193 ) ;
if ( V_192 -> V_325 & V_326 ) {
V_288 = F_173 ( V_157 ) ;
if ( V_288 != 0 )
return V_288 ;
}
return V_288 ;
}
static int F_184 ( struct V_298 * V_332 ,
struct V_191 * V_269 ,
struct V_65 * V_66 , T_5 V_205 ,
int V_333 )
{
struct V_334 V_335 ;
T_1 V_336 ;
if ( V_269 -> V_192 . V_337 == 0 )
return 0 ;
V_336 = 0 ;
if ( V_333 & V_338 ) {
V_336 = V_339 ;
} else if ( ( V_205 & V_69 ) && ! V_269 -> V_340 )
V_336 = V_341 ;
V_335 . V_332 = V_332 ;
V_335 . V_154 = V_154 ;
F_185 ( & V_335 , V_269 -> V_192 . V_342 ) ;
F_186 ( V_66 -> V_2 , & V_335 ) ;
if ( ( V_336 & ~ V_335 . V_336 & ( V_341 | V_339 ) ) == 0 )
return 0 ;
F_157 ( V_66 , V_205 ) ;
return - V_29 ;
}
static int F_187 ( struct V_191 * V_157 )
{
struct V_2 * V_3 = V_157 -> V_3 -> V_46 ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_328 * V_196 = & V_157 -> V_196 ;
struct V_329 * V_192 = & V_157 -> V_192 ;
int V_288 ;
V_288 = F_182 ( V_157 , 0 ) ;
if ( ! V_157 -> V_275 )
return V_288 ;
if ( V_288 != 0 ) {
if ( V_288 == - V_26 &&
! ( V_196 -> V_216 & V_343 ) )
return - V_284 ;
return V_288 ;
}
F_183 ( V_14 , & V_157 -> V_193 ) ;
if ( V_196 -> V_216 & V_343 ) {
F_74 ( V_3 , & V_192 -> V_171 ) ;
if ( V_196 -> V_216 & V_218 )
V_157 -> V_340 = 1 ;
else if ( V_192 -> V_171 . V_179 != V_192 -> V_171 . V_181 )
V_157 -> V_340 = 1 ;
}
if ( ( V_192 -> V_325 & V_344 ) == 0 )
V_14 -> V_94 &= ~ V_345 ;
if( V_192 -> V_325 & V_326 ) {
V_288 = F_173 ( V_157 ) ;
if ( V_288 != 0 )
return V_288 ;
}
if ( ! ( V_192 -> V_193 -> V_279 & V_280 ) )
F_188 ( V_14 , & V_192 -> V_233 , V_192 -> V_193 , V_192 -> V_194 ) ;
return 0 ;
}
static int F_189 ( struct V_13 * V_14 )
{
return F_190 ( V_14 -> V_63 ) ;
}
static int F_191 ( struct V_282 * V_283 , struct V_65 * V_66 )
{
struct V_191 * V_269 ;
int V_52 ;
V_269 = F_154 ( V_283 , V_66 ,
V_185 ) ;
if ( F_43 ( V_269 ) )
return F_71 ( V_269 ) ;
V_52 = F_158 ( V_269 , V_66 ) ;
if ( V_52 == - V_287 )
F_192 ( V_283 -> V_4 ) ;
F_105 ( V_269 ) ;
return V_52 ;
}
static int F_193 ( struct V_282 * V_283 , struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_191 ( V_283 , V_66 ) ;
F_194 ( V_283 , 0 , V_8 ) ;
if ( F_78 ( V_14 , V_8 , & V_62 ) )
continue;
switch ( V_8 ) {
default:
goto V_131;
case - V_89 :
case - V_90 :
F_20 ( V_14 , V_8 , & V_62 ) ;
V_8 = 0 ;
}
} while ( V_62 . V_67 );
V_131:
return V_8 ;
}
static int F_195 ( struct V_203 * V_204 , struct V_65 * V_66 )
{
struct V_282 * V_283 ;
int V_52 ;
V_283 = F_151 ( V_66 ) ;
if ( F_43 ( V_283 ) )
return - V_130 ;
V_52 = F_193 ( V_283 , V_66 ) ;
F_164 ( V_283 ) ;
return V_52 ;
}
static void F_196 ( struct V_65 * V_66 )
{
F_197 ( V_66 -> V_2 ) ;
F_125 ( & V_66 -> V_261 ) ;
F_123 ( & V_66 -> V_239 , & V_66 -> V_259 ) ;
F_126 ( & V_66 -> V_261 ) ;
F_122 ( V_260 , & V_66 -> V_206 ) ;
}
static void F_198 ( struct V_65 * V_66 )
{
if ( F_199 ( F_75 ( V_66 -> V_2 ) -> V_254 ) != NULL )
F_196 ( V_66 ) ;
}
static int F_200 ( struct V_203 * V_204 , struct V_65 * V_66 )
{
F_198 ( V_66 ) ;
return F_195 ( V_204 , V_66 ) ;
}
static void F_201 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
T_8 V_239 ;
struct V_253 * V_254 ;
struct V_298 * V_332 ;
int V_288 ;
F_132 () ;
V_254 = F_133 ( F_75 ( V_66 -> V_2 ) -> V_254 ) ;
if ( V_254 == NULL ) {
F_135 () ;
return;
}
F_123 ( & V_239 , & V_254 -> V_239 ) ;
V_332 = F_202 ( V_254 -> V_332 ) ;
F_135 () ;
V_288 = F_203 ( V_14 , & V_239 , V_332 ) ;
F_204 ( V_66 , NULL , V_288 ) ;
if ( V_288 != V_346 ) {
if ( V_288 != - V_73 )
F_205 ( V_14 , & V_239 , V_332 ) ;
F_196 ( V_66 ) ;
}
F_206 ( V_332 ) ;
}
static int F_207 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
T_8 * V_239 = & V_66 -> V_259 ;
struct V_298 * V_332 = V_66 -> V_214 -> V_272 ;
int V_288 ;
if ( ( F_31 ( V_247 , & V_66 -> V_206 ) == 0 ) &&
( F_31 ( V_249 , & V_66 -> V_206 ) == 0 ) &&
( F_31 ( V_251 , & V_66 -> V_206 ) == 0 ) )
return - V_73 ;
V_288 = F_203 ( V_14 , V_239 , V_332 ) ;
F_208 ( V_66 , NULL , V_288 ) ;
if ( V_288 != V_346 ) {
if ( V_288 != - V_73 )
F_205 ( V_14 , V_239 , V_332 ) ;
F_122 ( V_247 , & V_66 -> V_206 ) ;
F_122 ( V_249 , & V_66 -> V_206 ) ;
F_122 ( V_251 , & V_66 -> V_206 ) ;
F_122 ( V_258 , & V_66 -> V_206 ) ;
}
return V_288 ;
}
static int F_209 ( struct V_203 * V_204 , struct V_65 * V_66 )
{
int V_288 ;
F_201 ( V_66 ) ;
V_288 = F_207 ( V_66 ) ;
if ( V_288 != V_346 )
V_288 = F_195 ( V_204 , V_66 ) ;
return V_288 ;
}
static inline void F_210 ( struct V_191 * V_269 , struct V_5 * V_6 )
{
if ( ( V_269 -> V_192 . V_347 [ 1 ] & V_348 ) &&
! ( V_6 -> V_235 & V_349 ) )
V_6 -> V_235 |= V_350 ;
if ( ( V_269 -> V_192 . V_347 [ 1 ] & V_351 ) &&
! ( V_6 -> V_235 & V_352 ) )
V_6 -> V_235 |= V_353 ;
}
static int F_211 ( struct V_191 * V_269 ,
T_5 V_205 ,
int V_206 ,
struct V_282 * V_283 )
{
struct V_203 * V_204 = V_269 -> V_214 ;
struct V_13 * V_14 = V_204 -> V_256 ;
struct V_4 * V_4 ;
struct V_65 * V_66 ;
unsigned int V_354 ;
int V_52 ;
V_354 = F_212 ( & V_204 -> V_355 ) ;
V_52 = F_187 ( V_269 ) ;
if ( V_52 != 0 )
goto V_131;
V_66 = F_150 ( V_269 ) ;
V_52 = F_71 ( V_66 ) ;
if ( F_43 ( V_66 ) )
goto V_131;
if ( V_14 -> V_94 & V_345 )
F_129 ( V_356 , & V_66 -> V_206 ) ;
V_4 = V_269 -> V_4 ;
if ( V_4 -> V_46 == NULL ) {
F_192 ( V_4 ) ;
V_4 = F_213 ( V_4 , F_214 ( V_66 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_269 -> V_4 ;
} else if ( V_4 != V_283 -> V_4 ) {
F_97 ( V_283 -> V_4 ) ;
V_283 -> V_4 = F_90 ( V_4 ) ;
}
F_215 ( V_4 ,
F_216 ( V_269 -> V_3 -> V_46 ) ) ;
}
V_52 = F_184 ( V_204 -> V_272 , V_269 , V_66 , V_205 , V_206 ) ;
if ( V_52 != 0 )
goto V_131;
V_283 -> V_66 = V_66 ;
if ( V_4 -> V_46 == V_66 -> V_2 ) {
F_217 ( V_283 ) ;
if ( F_218 ( & V_204 -> V_355 , V_354 ) )
F_23 ( V_14 , V_66 ) ;
}
V_131:
return V_52 ;
}
static int F_219 ( struct V_2 * V_3 ,
struct V_282 * V_283 ,
int V_206 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_357 )
{
struct V_203 * V_204 ;
struct V_65 * V_66 = NULL ;
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_191 * V_269 ;
struct V_4 * V_4 = V_283 -> V_4 ;
struct V_298 * V_332 = V_283 -> V_332 ;
struct V_358 * * V_359 = & V_283 -> V_243 ;
T_5 V_205 = V_283 -> V_244 & ( V_69 | V_217 | V_360 ) ;
enum V_183 V_184 = V_186 ;
struct V_1 * V_361 = NULL ;
int V_288 ;
V_288 = - V_126 ;
V_204 = F_220 ( V_14 , V_332 , V_362 ) ;
if ( V_204 == NULL ) {
F_8 ( L_23 ) ;
goto V_363;
}
V_288 = F_189 ( V_14 ) ;
if ( V_288 != 0 )
goto V_364;
if ( V_4 -> V_46 != NULL )
F_136 ( V_4 -> V_46 , V_205 ) ;
V_288 = - V_126 ;
if ( V_4 -> V_46 )
V_184 = V_185 ;
V_269 = F_83 ( V_4 , V_204 , V_205 , V_206 , V_6 ,
V_7 , V_184 , V_362 ) ;
if ( V_269 == NULL )
goto V_364;
if ( V_7 ) {
V_361 = F_87 ( V_14 , V_362 ) ;
if ( F_43 ( V_361 ) ) {
V_288 = F_71 ( V_361 ) ;
goto V_365;
}
}
if ( V_14 -> V_15 [ 2 ] & V_366 ) {
if ( ! V_269 -> V_193 . V_243 ) {
V_269 -> V_193 . V_243 = F_221 () ;
if ( ! V_269 -> V_193 . V_243 )
goto V_212;
}
V_269 -> V_196 . V_231 = & V_367 [ 0 ] ;
}
if ( V_4 -> V_46 != NULL )
V_269 -> V_66 = F_148 ( V_4 -> V_46 , V_204 ) ;
V_288 = F_211 ( V_269 , V_205 , V_206 , V_283 ) ;
if ( V_288 != 0 )
goto V_212;
V_66 = V_283 -> V_66 ;
if ( ( V_269 -> V_196 . V_216 & V_218 ) &&
( V_269 -> V_196 . V_310 != V_313 ) ) {
F_210 ( V_269 , V_6 ) ;
F_81 ( V_269 -> V_192 . V_193 ) ;
V_288 = F_222 ( V_66 -> V_2 , V_332 ,
V_269 -> V_192 . V_193 , V_6 ,
V_66 , V_7 , V_361 ) ;
if ( V_288 == 0 ) {
F_223 ( V_66 -> V_2 , V_6 ) ;
F_224 ( V_66 -> V_2 , V_269 -> V_192 . V_193 ) ;
F_225 ( V_66 -> V_2 , V_269 -> V_192 . V_193 , V_361 ) ;
}
}
if ( V_269 -> V_340 )
* V_357 |= V_368 ;
if ( F_226 ( V_359 , V_269 -> V_193 . V_243 , V_14 ) ) {
* V_359 = V_269 -> V_193 . V_243 ;
V_269 -> V_193 . V_243 = NULL ;
}
F_95 ( V_361 ) ;
F_105 ( V_269 ) ;
F_102 ( V_204 ) ;
return 0 ;
V_212:
F_95 ( V_361 ) ;
V_365:
F_105 ( V_269 ) ;
V_364:
F_102 ( V_204 ) ;
V_363:
return V_288 ;
}
static struct V_65 * F_227 ( struct V_2 * V_3 ,
struct V_282 * V_283 ,
int V_206 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_357 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_61 V_62 = { } ;
struct V_65 * V_57 ;
int V_288 ;
do {
V_288 = F_219 ( V_3 , V_283 , V_206 , V_6 , V_7 , V_357 ) ;
V_57 = V_283 -> V_66 ;
F_228 ( V_283 , V_206 , V_288 ) ;
if ( V_288 == 0 )
break;
if ( V_288 == - V_369 ) {
F_229 ( L_5
L_24 ,
F_85 ( V_3 ) -> V_63 -> V_97 ) ;
V_62 . V_67 = 1 ;
continue;
}
if ( V_288 == - V_73 ) {
V_62 . V_67 = 1 ;
continue;
}
if ( V_288 == - V_130 ) {
V_62 . V_67 = 1 ;
continue;
}
if ( F_78 ( V_14 , V_288 , & V_62 ) )
continue;
V_57 = F_44 ( F_20 ( V_14 ,
V_288 , & V_62 ) ) ;
} while ( V_62 . V_67 );
return V_57 ;
}
static int F_230 ( struct V_2 * V_2 , struct V_298 * V_332 ,
struct V_370 * V_371 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_372 ,
struct V_1 * V_361 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_373 V_374 = {
. V_233 = F_93 ( V_2 ) ,
. V_375 = V_6 ,
. V_14 = V_14 ,
. V_230 = V_14 -> V_15 ,
. V_7 = V_372 ,
} ;
struct V_376 V_57 = {
. V_371 = V_371 ,
. V_7 = V_361 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_377 ] ,
. V_296 = & V_374 ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
unsigned long V_106 = V_154 ;
T_5 V_205 ;
bool V_378 ;
int V_288 ;
V_374 . V_230 = F_6 ( V_14 , V_372 ) ;
if ( V_372 )
V_374 . V_230 = F_6 ( V_14 , V_361 ) ;
F_81 ( V_371 ) ;
V_378 = ( V_6 -> V_235 & V_379 ) ? true : false ;
V_205 = V_378 ? V_217 : V_69 ;
if ( F_231 ( & V_374 . V_239 , V_2 , V_205 ) ) {
} else if ( V_378 && V_66 != NULL ) {
struct V_380 V_381 = {
. V_382 = V_58 -> V_383 ,
. V_384 = V_58 -> V_385 ,
} ;
if ( ! F_232 ( V_66 ) )
return - V_386 ;
if ( F_233 ( & V_374 . V_239 , V_66 , V_217 ,
& V_381 ) == - V_35 )
return - V_386 ;
} else
F_123 ( & V_374 . V_239 , & V_387 ) ;
V_288 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_374 . V_159 , & V_57 . V_160 , 1 ) ;
if ( V_288 == 0 && V_66 != NULL )
F_37 ( V_14 , V_106 ) ;
return V_288 ;
}
static int F_222 ( struct V_2 * V_2 , struct V_298 * V_332 ,
struct V_370 * V_371 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_372 ,
struct V_1 * V_361 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_230 ( V_2 , V_332 , V_371 , V_6 , V_66 , V_372 , V_361 ) ;
F_234 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_68 :
if ( ! ( V_6 -> V_235 & V_379 ) ) {
F_235 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_63 -> V_97 ) ;
}
if ( V_66 && ! ( V_66 -> V_66 & V_217 ) ) {
V_8 = - V_386 ;
if ( V_6 -> V_235 & V_388 )
V_8 = - V_29 ;
goto V_131;
}
}
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
V_131:
return V_8 ;
}
static void F_236 ( void * V_157 )
{
struct V_389 * V_155 = V_157 ;
struct V_203 * V_204 = V_155 -> V_66 -> V_214 ;
struct V_241 * V_242 = V_155 -> V_66 -> V_2 -> V_390 ;
if ( V_155 -> V_391 )
F_237 ( V_155 -> V_66 -> V_2 ) ;
F_101 ( V_155 -> V_66 ) ;
F_100 ( V_155 -> V_374 . V_195 ) ;
F_102 ( V_204 ) ;
F_103 ( V_242 ) ;
F_96 ( V_155 ) ;
}
static void F_238 ( struct V_116 * V_117 , void * V_157 )
{
struct V_389 * V_155 = V_157 ;
struct V_65 * V_66 = V_155 -> V_66 ;
struct V_13 * V_14 = F_85 ( V_155 -> V_2 ) ;
T_8 * V_392 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_60 ( V_117 , & V_155 -> V_57 . V_160 ) )
return;
F_239 ( V_66 , & V_155 -> V_374 , & V_155 -> V_57 , V_117 -> V_149 ) ;
switch ( V_117 -> V_149 ) {
case 0 :
V_392 = & V_155 -> V_57 . V_239 ;
if ( V_155 -> V_374 . V_205 == 0 && V_155 -> V_391 )
F_240 ( V_66 -> V_2 ,
V_155 -> V_393 ) ;
F_37 ( V_14 , V_155 -> V_106 ) ;
break;
case - V_72 :
case - V_75 :
case - V_93 :
case - V_73 :
case - V_74 :
if ( V_155 -> V_374 . V_205 == 0 )
break;
default:
if ( F_241 ( V_117 , V_14 , V_66 , NULL ) == - V_130 ) {
F_57 ( V_117 ) ;
goto V_394;
}
}
F_124 ( V_66 , V_392 , V_155 -> V_374 . V_205 ) ;
V_394:
F_138 ( V_155 -> V_374 . V_195 ) ;
F_145 ( V_155 -> V_2 , V_155 -> V_57 . V_371 ) ;
F_8 ( L_30 , V_34 , V_117 -> V_149 ) ;
}
static void F_242 ( struct V_116 * V_117 , void * V_157 )
{
struct V_389 * V_155 = V_157 ;
struct V_65 * V_66 = V_155 -> V_66 ;
struct V_2 * V_2 = V_155 -> V_2 ;
bool V_395 , V_396 , V_397 ;
int V_398 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_177 ( V_155 -> V_374 . V_195 , V_117 ) != 0 )
goto V_304;
V_117 -> V_308 . V_293 = & V_294 [ V_399 ] ;
F_34 ( & V_66 -> V_214 -> V_264 ) ;
V_397 = F_31 ( V_251 , & V_66 -> V_206 ) ;
V_395 = F_31 ( V_247 , & V_66 -> V_206 ) ;
V_396 = F_31 ( V_249 , & V_66 -> V_206 ) ;
V_155 -> V_374 . V_205 = 0 ;
if ( V_66 -> V_252 == 0 ) {
if ( V_66 -> V_248 == 0 )
V_398 |= V_395 ;
else if ( V_395 )
V_155 -> V_374 . V_205 |= V_69 ;
if ( V_66 -> V_250 == 0 )
V_398 |= V_396 ;
else if ( V_396 )
V_155 -> V_374 . V_205 |= V_217 ;
} else if ( V_397 )
V_155 -> V_374 . V_205 |= V_69 | V_217 ;
if ( V_155 -> V_374 . V_205 == 0 )
V_398 |= V_397 ;
if ( ! F_232 ( V_66 ) )
V_398 = 0 ;
F_36 ( & V_66 -> V_214 -> V_264 ) ;
if ( ! V_398 ) {
goto V_305;
}
if ( V_155 -> V_374 . V_205 == 0 ) {
V_117 -> V_308 . V_293 = & V_294 [ V_400 ] ;
if ( V_155 -> V_391 &&
F_243 ( V_2 , & V_155 -> V_393 , V_117 ) ) {
F_138 ( V_155 -> V_374 . V_195 ) ;
goto V_304;
}
}
F_81 ( V_155 -> V_57 . V_371 ) ;
V_155 -> V_106 = V_154 ;
if ( F_63 ( F_85 ( V_2 ) ,
& V_155 -> V_374 . V_159 ,
& V_155 -> V_57 . V_160 ,
V_117 ) != 0 )
F_138 ( V_155 -> V_374 . V_195 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_305:
V_117 -> V_316 = NULL ;
V_304:
F_60 ( V_117 , & V_155 -> V_57 . V_160 ) ;
}
static bool F_244 ( struct V_65 * V_66 )
{
if ( F_31 ( V_247 , & V_66 -> V_206 ) != 0 &&
V_66 -> V_248 != 0 )
return true ;
if ( F_31 ( V_249 , & V_66 -> V_206 ) != 0 &&
V_66 -> V_250 != 0 )
return true ;
if ( F_31 ( V_251 , & V_66 -> V_206 ) != 0 &&
V_66 -> V_252 != 0 )
return true ;
return false ;
}
static bool F_245 ( struct V_2 * V_2 )
{
struct V_172 * V_173 = F_75 ( V_2 ) ;
struct V_282 * V_283 ;
struct V_65 * V_66 ;
F_34 ( & V_2 -> V_174 ) ;
F_152 (ctx, &nfsi->open_files, list) {
V_66 = V_283 -> V_66 ;
if ( V_66 == NULL )
continue;
if ( F_244 ( V_66 ) ) {
F_36 ( & V_2 -> V_174 ) ;
return false ;
}
}
F_36 ( & V_2 -> V_174 ) ;
if ( F_246 ( V_2 , V_69 ) )
return false ;
return F_247 ( V_2 ) ;
}
int F_248 ( struct V_65 * V_66 , T_6 V_208 , int V_401 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_389 * V_155 ;
struct V_203 * V_204 = V_66 -> V_214 ;
struct V_116 * V_117 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_400 ] ,
. V_298 = V_66 -> V_214 -> V_272 ,
} ;
struct V_163 V_299 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_402 ,
. V_301 = V_302 ,
. V_206 = V_303 ,
} ;
int V_288 = - V_126 ;
F_249 ( V_14 -> V_63 , V_403 ,
& V_299 . V_165 , & V_162 ) ;
V_155 = F_86 ( sizeof( * V_155 ) , V_208 ) ;
if ( V_155 == NULL )
goto V_131;
F_38 ( & V_155 -> V_374 . V_159 , & V_155 -> V_57 . V_160 , 1 ) ;
V_155 -> V_2 = V_66 -> V_2 ;
V_155 -> V_66 = V_66 ;
V_155 -> V_374 . V_233 = F_93 ( V_66 -> V_2 ) ;
V_155 -> V_374 . V_239 = & V_66 -> V_259 ;
V_155 -> V_374 . V_195 = F_88 ( & V_66 -> V_214 -> V_211 , V_208 ) ;
if ( V_155 -> V_374 . V_195 == NULL )
goto V_404;
V_155 -> V_374 . V_205 = 0 ;
V_155 -> V_374 . V_230 = V_14 -> V_405 ;
V_155 -> V_57 . V_371 = & V_155 -> V_371 ;
V_155 -> V_57 . V_195 = V_155 -> V_374 . V_195 ;
V_155 -> V_57 . V_14 = V_14 ;
V_155 -> V_391 = F_245 ( V_66 -> V_2 ) ;
F_89 ( V_155 -> V_2 -> V_390 ) ;
V_162 . V_296 = & V_155 -> V_374 ;
V_162 . V_297 = & V_155 -> V_57 ;
V_299 . V_169 = V_155 ;
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) )
return F_71 ( V_117 ) ;
V_288 = 0 ;
if ( V_401 )
V_288 = F_108 ( V_117 ) ;
F_72 ( V_117 ) ;
return V_288 ;
V_404:
F_96 ( V_155 ) ;
V_131:
F_101 ( V_66 ) ;
F_102 ( V_204 ) ;
return V_288 ;
}
static struct V_2 *
F_250 ( struct V_2 * V_3 , struct V_282 * V_283 ,
int V_216 , struct V_5 * V_406 , int * V_357 )
{
struct V_65 * V_66 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_283 -> V_4 , V_406 , & V_17 ) ;
V_66 = F_227 ( V_3 , V_283 , V_216 , V_406 , V_7 , V_357 ) ;
F_4 ( V_7 ) ;
if ( F_43 ( V_66 ) )
return F_251 ( V_66 ) ;
return V_66 -> V_2 ;
}
static void F_252 ( struct V_282 * V_283 , int V_407 )
{
if ( V_283 -> V_66 == NULL )
return;
if ( V_407 )
F_253 ( V_283 -> V_66 , V_283 -> V_244 ) ;
else
F_157 ( V_283 -> V_66 , V_283 -> V_244 ) ;
}
static int F_254 ( struct V_13 * V_14 , struct V_408 * V_409 )
{
struct V_410 args = {
. V_409 = V_409 ,
} ;
struct V_411 V_57 = {} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_412 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
int V_288 ;
V_288 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
if ( V_288 == 0 ) {
switch ( V_14 -> V_63 -> V_413 ) {
case 0 :
V_57 . V_15 [ 1 ] &= V_414 ;
V_57 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_57 . V_15 [ 2 ] &= V_415 ;
break;
case 2 :
V_57 . V_15 [ 2 ] &= V_416 ;
}
memcpy ( V_14 -> V_15 , V_57 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_94 &= ~ ( V_417 | V_418 |
V_419 | V_420 |
V_421 | V_422 | V_423 |
V_424 | V_425 |
V_426 | V_427 |
V_9 ) ;
if ( V_57 . V_15 [ 0 ] & V_428 &&
V_57 . V_429 & V_430 )
V_14 -> V_94 |= V_417 ;
if ( V_57 . V_431 != 0 )
V_14 -> V_94 |= V_418 ;
if ( V_57 . V_432 != 0 )
V_14 -> V_94 |= V_419 ;
if ( V_57 . V_15 [ 0 ] & V_45 )
V_14 -> V_94 |= V_420 ;
if ( V_57 . V_15 [ 1 ] & V_433 )
V_14 -> V_94 |= V_421 ;
if ( V_57 . V_15 [ 1 ] & V_434 )
V_14 -> V_94 |= V_422 ;
if ( V_57 . V_15 [ 1 ] & V_435 )
V_14 -> V_94 |= V_423 ;
if ( V_57 . V_15 [ 1 ] & V_436 )
V_14 -> V_94 |= V_424 ;
if ( V_57 . V_15 [ 1 ] & V_348 )
V_14 -> V_94 |= V_425 ;
if ( V_57 . V_15 [ 1 ] & V_437 )
V_14 -> V_94 |= V_426 ;
if ( V_57 . V_15 [ 1 ] & V_351 )
V_14 -> V_94 |= V_427 ;
#ifdef F_255
if ( V_57 . V_15 [ 2 ] & V_438 )
V_14 -> V_94 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_57 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_438 ;
memcpy ( V_14 -> V_405 , V_57 . V_15 , sizeof( V_14 -> V_405 ) ) ;
V_14 -> V_405 [ 0 ] &= V_439 | V_440 ;
V_14 -> V_405 [ 1 ] &= V_437 | V_351 ;
V_14 -> V_405 [ 2 ] = 0 ;
V_14 -> V_429 = V_57 . V_429 ;
V_14 -> V_441 = V_57 . V_441 ;
}
return V_288 ;
}
int F_256 ( struct V_13 * V_14 , struct V_408 * V_409 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_254 ( V_14 , V_409 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_257 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_443 )
{
T_1 V_230 [ 3 ] ;
struct V_444 args = {
. V_230 = V_230 ,
} ;
struct V_445 V_57 = {
. V_14 = V_14 ,
. V_371 = V_443 -> V_371 ,
. V_233 = V_409 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_446 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
V_230 [ 0 ] = V_232 [ 0 ] ;
V_230 [ 1 ] = V_232 [ 1 ] ;
V_230 [ 2 ] = V_232 [ 2 ] & ~ V_438 ;
F_81 ( V_443 -> V_371 ) ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_258 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_443 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_257 ( V_14 , V_409 , V_443 ) ;
F_259 ( V_14 , V_409 , V_443 -> V_371 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_131;
default:
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
}
} while ( V_62 . V_67 );
V_131:
return V_8 ;
}
static int F_260 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_443 , T_4 V_100 )
{
struct V_447 V_448 = {
. V_449 = V_100 ,
} ;
struct V_450 * V_451 ;
int V_52 ;
V_451 = F_261 ( & V_448 , V_14 -> V_91 ) ;
if ( F_43 ( V_451 ) ) {
V_52 = - V_29 ;
goto V_131;
}
V_52 = F_258 ( V_14 , V_409 , V_443 ) ;
V_131:
return V_52 ;
}
static int F_262 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_443 )
{
static const T_4 V_452 [] = {
V_105 ,
V_104 ,
V_453 ,
V_454 ,
V_455 ,
} ;
int V_288 = - V_24 ;
T_9 V_456 ;
if ( V_14 -> V_457 . V_458 > 0 ) {
for ( V_456 = 0 ; V_456 < V_14 -> V_457 . V_458 ; V_456 ++ ) {
V_288 = F_260 ( V_14 , V_409 , V_443 ,
V_14 -> V_457 . V_459 [ V_456 ] ) ;
if ( V_288 == - V_22 || V_288 == - V_29 )
continue;
break;
}
} else {
for ( V_456 = 0 ; V_456 < F_263 ( V_452 ) ; V_456 ++ ) {
V_288 = F_260 ( V_14 , V_409 , V_443 ,
V_452 [ V_456 ] ) ;
if ( V_288 == - V_22 || V_288 == - V_29 )
continue;
break;
}
}
if ( V_288 == - V_29 )
V_288 = - V_24 ;
return V_288 ;
}
static int F_264 ( struct V_13 * V_14 ,
struct V_408 * V_409 , struct V_442 * V_443 )
{
int V_460 = V_14 -> V_63 -> V_413 ;
return V_461 [ V_460 ] -> F_265 ( V_14 , V_409 , V_443 ) ;
}
int F_266 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_443 ,
bool V_462 )
{
int V_288 ;
switch ( V_462 ) {
case false :
V_288 = F_258 ( V_14 , V_409 , V_443 ) ;
if ( V_288 != - V_22 )
break;
default:
V_288 = F_264 ( V_14 , V_409 , V_443 ) ;
}
if ( V_288 == 0 )
V_288 = F_256 ( V_14 , V_409 ) ;
if ( V_288 == 0 )
V_288 = F_267 ( V_14 , V_409 , V_443 ) ;
return F_7 ( V_288 ) ;
}
static int F_268 ( struct V_13 * V_14 , struct V_408 * V_463 ,
struct V_442 * V_443 )
{
int error ;
struct V_370 * V_371 = V_443 -> V_371 ;
struct V_1 * V_7 = NULL ;
error = F_256 ( V_14 , V_463 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_87 ( V_14 , V_362 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
error = F_188 ( V_14 , V_463 , V_371 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_212;
}
if ( V_371 -> V_279 & V_464 &&
! F_269 ( & V_14 -> V_465 , & V_371 -> V_465 ) )
memcpy ( & V_14 -> V_465 , & V_371 -> V_465 , sizeof( V_14 -> V_465 ) ) ;
V_212:
F_95 ( V_7 ) ;
return error ;
}
static int F_270 ( struct V_55 * V_91 , struct V_2 * V_3 ,
const struct V_466 * V_229 , struct V_370 * V_371 ,
struct V_408 * V_409 )
{
int V_288 = - V_126 ;
struct V_467 * V_467 = NULL ;
struct V_468 * V_469 = NULL ;
V_467 = F_271 ( V_362 ) ;
if ( V_467 == NULL )
goto V_131;
V_469 = F_272 ( sizeof( struct V_468 ) , V_362 ) ;
if ( V_469 == NULL )
goto V_131;
V_288 = F_273 ( V_91 , V_3 , V_229 , V_469 , V_467 ) ;
if ( V_288 != 0 )
goto V_131;
if ( F_269 ( & F_85 ( V_3 ) -> V_465 , & V_469 -> V_371 . V_465 ) ) {
F_8 ( L_34
L_35 , V_34 , V_229 -> V_229 ) ;
V_288 = - V_77 ;
goto V_131;
}
F_274 ( & V_469 -> V_371 ) ;
memcpy ( V_371 , & V_469 -> V_371 , sizeof( struct V_370 ) ) ;
memset ( V_409 , 0 , sizeof( struct V_408 ) ) ;
V_131:
if ( V_467 )
F_275 ( V_467 ) ;
F_96 ( V_469 ) ;
return V_288 ;
}
static int F_276 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_370 * V_371 , struct V_1 * V_7 )
{
struct V_470 args = {
. V_233 = V_409 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_471 V_57 = {
. V_371 = V_371 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_472 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
args . V_230 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_371 ) ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_188 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_370 * V_371 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_276 ( V_14 , V_409 , V_371 , V_7 ) ;
F_277 ( V_14 , V_409 , V_371 , V_8 ) ;
V_8 = F_20 ( V_14 , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int
F_278 ( struct V_4 * V_4 , struct V_370 * V_371 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = V_4 -> V_46 ;
struct V_298 * V_332 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_1 * V_7 = NULL ;
int V_288 ;
if ( F_279 ( V_2 ) &&
V_6 -> V_235 & V_379 &&
V_6 -> V_473 < F_280 ( V_2 ) )
F_281 ( V_2 ) ;
F_81 ( V_371 ) ;
if ( V_6 -> V_235 & V_388 )
V_6 -> V_235 &= ~ ( V_353 | V_474 ) ;
if ( ( V_6 -> V_235 & ~ ( V_475 | V_388 ) ) == 0 )
return 0 ;
if ( V_6 -> V_235 & V_475 ) {
struct V_282 * V_283 ;
V_283 = F_282 ( V_6 -> V_476 ) ;
if ( V_283 ) {
V_332 = V_283 -> V_332 ;
V_66 = V_283 -> V_66 ;
}
}
V_7 = F_87 ( F_85 ( V_2 ) , V_362 ) ;
if ( F_43 ( V_7 ) )
return F_71 ( V_7 ) ;
V_288 = F_222 ( V_2 , V_332 , V_371 , V_6 , V_66 , NULL , V_7 ) ;
if ( V_288 == 0 ) {
F_223 ( V_2 , V_6 ) ;
F_225 ( V_2 , V_371 , V_7 ) ;
}
F_95 ( V_7 ) ;
return V_288 ;
}
static int F_283 ( struct V_55 * V_56 , struct V_2 * V_3 ,
const struct V_466 * V_229 , struct V_408 * V_409 ,
struct V_370 * V_371 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
int V_288 ;
struct V_477 args = {
. V_230 = V_14 -> V_15 ,
. V_478 = F_93 ( V_3 ) ,
. V_229 = V_229 ,
} ;
struct V_445 V_57 = {
. V_14 = V_14 ,
. V_371 = V_371 ,
. V_7 = V_7 ,
. V_233 = V_409 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_479 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
args . V_230 = F_6 ( V_14 , V_7 ) ;
F_81 ( V_371 ) ;
F_8 ( L_36 , V_229 -> V_229 ) ;
V_288 = F_73 ( V_56 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
F_8 ( L_37 , V_288 ) ;
return V_288 ;
}
static void F_284 ( struct V_370 * V_371 )
{
V_371 -> V_279 |= V_317 | V_480 |
V_481 | V_482 ;
V_371 -> V_244 = V_322 | V_483 | V_484 ;
V_371 -> V_485 = 2 ;
}
static int F_285 ( struct V_55 * * V_56 , struct V_2 * V_3 ,
struct V_466 * V_229 , struct V_408 * V_409 ,
struct V_370 * V_371 , struct V_1 * V_7 )
{
struct V_61 V_62 = { } ;
struct V_55 * V_91 = * V_56 ;
int V_8 ;
do {
V_8 = F_283 ( V_91 , V_3 , V_229 , V_409 , V_371 , V_7 ) ;
F_286 ( V_3 , V_229 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_284 ;
goto V_131;
case - V_77 :
V_8 = F_270 ( V_91 , V_3 , V_229 , V_371 , V_409 ) ;
goto V_131;
case - V_22 :
V_8 = - V_24 ;
if ( V_91 != * V_56 )
goto V_131;
V_91 = F_287 ( V_91 , V_3 , V_229 ) ;
if ( F_43 ( V_91 ) )
return F_71 ( V_91 ) ;
V_62 . V_67 = 1 ;
break;
default:
V_8 = F_20 ( F_85 ( V_3 ) , V_8 , & V_62 ) ;
}
} while ( V_62 . V_67 );
V_131:
if ( V_8 == 0 )
* V_56 = V_91 ;
else if ( V_91 != * V_56 )
F_288 ( V_91 ) ;
return V_8 ;
}
static int F_289 ( struct V_2 * V_3 , struct V_466 * V_229 ,
struct V_408 * V_409 , struct V_370 * V_371 ,
struct V_1 * V_7 )
{
int V_288 ;
struct V_55 * V_91 = F_290 ( V_3 ) ;
V_288 = F_285 ( & V_91 , V_3 , V_229 , V_409 , V_371 , V_7 ) ;
if ( V_91 != F_290 ( V_3 ) ) {
F_288 ( V_91 ) ;
F_284 ( V_371 ) ;
}
return V_288 ;
}
struct V_55 *
F_291 ( struct V_2 * V_3 , struct V_466 * V_229 ,
struct V_408 * V_409 , struct V_370 * V_371 )
{
struct V_55 * V_91 = F_290 ( V_3 ) ;
int V_288 ;
V_288 = F_285 ( & V_91 , V_3 , V_229 , V_409 , V_371 , NULL ) ;
if ( V_288 < 0 )
return F_44 ( V_288 ) ;
return ( V_91 == F_290 ( V_3 ) ) ? F_292 ( V_91 ) : V_91 ;
}
static int F_293 ( struct V_2 * V_2 , struct V_334 * V_486 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_487 args = {
. V_233 = F_93 ( V_2 ) ,
. V_230 = V_14 -> V_405 ,
} ;
struct V_488 V_57 = {
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_489 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_486 -> V_332 ,
} ;
int V_244 = V_486 -> V_336 ;
int V_288 = 0 ;
if ( V_244 & V_341 )
args . V_200 |= V_219 ;
if ( F_294 ( V_2 -> V_490 ) ) {
if ( V_244 & V_491 )
args . V_200 |= V_220 | V_221 | V_492 ;
if ( V_244 & V_339 )
args . V_200 |= V_493 ;
} else {
if ( V_244 & V_491 )
args . V_200 |= V_220 | V_221 ;
if ( V_244 & V_339 )
args . V_200 |= V_222 ;
}
V_57 . V_371 = F_295 () ;
if ( V_57 . V_371 == NULL )
return - V_126 ;
V_288 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
if ( ! V_288 ) {
F_185 ( V_486 , V_57 . V_200 ) ;
F_145 ( V_2 , V_57 . V_371 ) ;
}
F_296 ( V_57 . V_371 ) ;
return V_288 ;
}
static int F_297 ( struct V_2 * V_2 , struct V_334 * V_486 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_293 ( V_2 , V_486 ) ;
F_298 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_299 ( struct V_2 * V_2 , struct V_467 * V_467 ,
unsigned int V_49 , unsigned int V_494 )
{
struct V_495 args = {
. V_233 = F_93 ( V_2 ) ,
. V_49 = V_49 ,
. V_494 = V_494 ,
. V_42 = & V_467 ,
} ;
struct V_496 V_57 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_497 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
return F_73 ( F_85 ( V_2 ) -> V_91 , F_85 ( V_2 ) , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_300 ( struct V_2 * V_2 , struct V_467 * V_467 ,
unsigned int V_49 , unsigned int V_494 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_299 ( V_2 , V_467 , V_49 , V_494 ) ;
F_301 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int
F_302 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_206 )
{
struct V_1 V_17 , * V_372 = NULL ;
struct V_282 * V_283 ;
struct V_65 * V_66 ;
int V_357 = 0 ;
int V_288 = 0 ;
V_283 = F_303 ( V_4 , V_69 ) ;
if ( F_43 ( V_283 ) )
return F_71 ( V_283 ) ;
V_372 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_304 () ;
V_66 = F_227 ( V_3 , V_283 , V_206 , V_6 , V_372 , & V_357 ) ;
if ( F_43 ( V_66 ) ) {
V_288 = F_71 ( V_66 ) ;
goto V_131;
}
V_131:
F_4 ( V_372 ) ;
F_164 ( V_283 ) ;
return V_288 ;
}
static int F_305 ( struct V_2 * V_3 , struct V_466 * V_229 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_498 args = {
. V_233 = F_93 ( V_3 ) ,
. V_229 = * V_229 ,
} ;
struct V_499 V_57 = {
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_500 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
int V_288 ;
V_288 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 1 ) ;
if ( V_288 == 0 )
F_74 ( V_3 , & V_57 . V_171 ) ;
return V_288 ;
}
static int F_306 ( struct V_2 * V_3 , struct V_466 * V_229 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_305 ( V_3 , V_229 ) ;
F_307 ( V_3 , V_229 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static void F_308 ( struct V_161 * V_162 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_498 * args = V_162 -> V_296 ;
struct V_499 * V_57 = V_162 -> V_297 ;
V_57 -> V_14 = V_14 ;
V_162 -> V_293 = & V_294 [ V_500 ] ;
F_38 ( & args -> V_159 , & V_57 -> V_160 , 1 ) ;
F_81 ( V_57 -> V_501 ) ;
}
static void F_309 ( struct V_116 * V_117 , struct V_502 * V_157 )
{
F_63 ( F_85 ( V_157 -> V_3 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_117 ) ;
}
static int F_310 ( struct V_116 * V_117 , struct V_2 * V_3 )
{
struct V_502 * V_157 = V_117 -> V_503 ;
struct V_499 * V_57 = & V_157 -> V_57 ;
if ( ! F_60 ( V_117 , & V_57 -> V_160 ) )
return 0 ;
if ( F_241 ( V_117 , V_57 -> V_14 , NULL ,
& V_157 -> V_51 ) == - V_130 )
return 0 ;
F_74 ( V_3 , & V_57 -> V_171 ) ;
return 1 ;
}
static void F_311 ( struct V_161 * V_162 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
struct V_504 * V_374 = V_162 -> V_296 ;
struct V_505 * V_57 = V_162 -> V_297 ;
V_162 -> V_293 = & V_294 [ V_506 ] ;
V_57 -> V_14 = V_14 ;
F_38 ( & V_374 -> V_159 , & V_57 -> V_160 , 1 ) ;
}
static void F_312 ( struct V_116 * V_117 , struct V_507 * V_157 )
{
F_63 ( F_85 ( V_157 -> V_508 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_117 ) ;
}
static int F_313 ( struct V_116 * V_117 , struct V_2 * V_508 ,
struct V_2 * V_509 )
{
struct V_507 * V_157 = V_117 -> V_503 ;
struct V_505 * V_57 = & V_157 -> V_57 ;
if ( ! F_60 ( V_117 , & V_57 -> V_160 ) )
return 0 ;
if ( F_241 ( V_117 , V_57 -> V_14 , NULL , & V_157 -> V_51 ) == - V_130 )
return 0 ;
F_74 ( V_508 , & V_57 -> V_510 ) ;
F_74 ( V_509 , & V_57 -> V_511 ) ;
return 1 ;
}
static int F_314 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_466 * V_229 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_512 V_374 = {
. V_233 = F_93 ( V_2 ) ,
. V_478 = F_93 ( V_3 ) ,
. V_229 = V_229 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_513 V_57 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_514 ] ,
. V_296 = & V_374 ,
. V_297 = & V_57 ,
} ;
int V_288 = - V_126 ;
V_57 . V_371 = F_295 () ;
if ( V_57 . V_371 == NULL )
goto V_131;
V_57 . V_7 = F_87 ( V_14 , V_362 ) ;
if ( F_43 ( V_57 . V_7 ) ) {
V_288 = F_71 ( V_57 . V_7 ) ;
goto V_131;
}
V_374 . V_230 = F_6 ( V_14 , V_57 . V_7 ) ;
V_288 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_374 . V_159 , & V_57 . V_160 , 1 ) ;
if ( ! V_288 ) {
F_74 ( V_3 , & V_57 . V_171 ) ;
V_288 = F_224 ( V_2 , V_57 . V_371 ) ;
if ( ! V_288 )
F_225 ( V_2 , V_57 . V_371 , V_57 . V_7 ) ;
}
F_95 ( V_57 . V_7 ) ;
V_131:
F_296 ( V_57 . V_371 ) ;
return V_288 ;
}
static int F_315 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_466 * V_229 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_85 ( V_2 ) ,
F_314 ( V_2 , V_3 , V_229 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static struct V_515 * F_316 ( struct V_2 * V_3 ,
struct V_466 * V_229 , struct V_5 * V_6 , T_1 V_516 )
{
struct V_515 * V_157 ;
V_157 = F_86 ( sizeof( * V_157 ) , V_362 ) ;
if ( V_157 != NULL ) {
struct V_13 * V_14 = F_85 ( V_3 ) ;
V_157 -> V_7 = F_87 ( V_14 , V_362 ) ;
if ( F_43 ( V_157 -> V_7 ) )
goto V_292;
V_157 -> V_162 . V_293 = & V_294 [ V_517 ] ;
V_157 -> V_162 . V_296 = & V_157 -> V_374 ;
V_157 -> V_162 . V_297 = & V_157 -> V_57 ;
V_157 -> V_374 . V_478 = F_93 ( V_3 ) ;
V_157 -> V_374 . V_14 = V_14 ;
V_157 -> V_374 . V_229 = V_229 ;
V_157 -> V_374 . V_207 = V_6 ;
V_157 -> V_374 . V_516 = V_516 ;
V_157 -> V_374 . V_230 = F_6 ( V_14 , V_157 -> V_7 ) ;
V_157 -> V_57 . V_14 = V_14 ;
V_157 -> V_57 . V_233 = & V_157 -> V_233 ;
V_157 -> V_57 . V_371 = & V_157 -> V_371 ;
V_157 -> V_57 . V_7 = V_157 -> V_7 ;
F_81 ( V_157 -> V_57 . V_371 ) ;
}
return V_157 ;
V_292:
F_96 ( V_157 ) ;
return NULL ;
}
static int F_317 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_515 * V_157 )
{
int V_288 = F_73 ( F_85 ( V_3 ) -> V_91 , F_85 ( V_3 ) , & V_157 -> V_162 ,
& V_157 -> V_374 . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
if ( V_288 == 0 ) {
F_74 ( V_3 , & V_157 -> V_57 . V_518 ) ;
V_288 = F_318 ( V_4 , V_157 -> V_57 . V_233 , V_157 -> V_57 . V_371 , V_157 -> V_57 . V_7 ) ;
}
return V_288 ;
}
static void F_319 ( struct V_515 * V_157 )
{
F_95 ( V_157 -> V_7 ) ;
F_96 ( V_157 ) ;
}
static int F_320 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_467 * V_467 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_515 * V_157 ;
int V_288 = - V_519 ;
if ( V_12 > V_520 )
goto V_131;
V_288 = - V_126 ;
V_157 = F_316 ( V_3 , & V_4 -> V_11 , V_6 , V_521 ) ;
if ( V_157 == NULL )
goto V_131;
V_157 -> V_162 . V_293 = & V_294 [ V_522 ] ;
V_157 -> V_374 . V_237 . V_523 . V_42 = & V_467 ;
V_157 -> V_374 . V_237 . V_523 . V_12 = V_12 ;
V_157 -> V_374 . V_7 = V_7 ;
V_288 = F_317 ( V_3 , V_4 , V_157 ) ;
F_319 ( V_157 ) ;
V_131:
return V_288 ;
}
static int F_321 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_467 * V_467 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_320 ( V_3 , V_4 , V_467 , V_12 , V_6 , V_7 ) ;
F_322 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_323 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_515 * V_157 ;
int V_288 = - V_126 ;
V_157 = F_316 ( V_3 , & V_4 -> V_11 , V_6 , V_524 ) ;
if ( V_157 == NULL )
goto V_131;
V_157 -> V_374 . V_7 = V_7 ;
V_288 = F_317 ( V_3 , V_4 , V_157 ) ;
F_319 ( V_157 ) ;
V_131:
return V_288 ;
}
static int F_324 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_304 () ;
do {
V_8 = F_323 ( V_3 , V_4 , V_6 , V_7 ) ;
F_325 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_326 ( struct V_4 * V_4 , struct V_298 * V_332 ,
T_2 V_36 , struct V_467 * * V_42 , unsigned int V_50 , int V_525 )
{
struct V_2 * V_3 = V_4 -> V_46 ;
struct V_38 args = {
. V_233 = F_93 ( V_3 ) ,
. V_42 = V_42 ,
. V_49 = 0 ,
. V_50 = V_50 ,
. V_230 = F_85 ( V_4 -> V_46 ) -> V_15 ,
. V_525 = V_525 ,
} ;
struct V_526 V_57 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_527 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
int V_288 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_75 ( V_3 ) -> V_528 , V_4 , & args ) ;
V_57 . V_49 = args . V_49 ;
V_288 = F_73 ( F_85 ( V_3 ) -> V_91 , F_85 ( V_3 ) , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
if ( V_288 >= 0 ) {
memcpy ( F_75 ( V_3 ) -> V_528 , V_57 . V_37 . V_157 , V_529 ) ;
V_288 += args . V_49 ;
}
F_327 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_288 ) ;
return V_288 ;
}
static int F_328 ( struct V_4 * V_4 , struct V_298 * V_332 ,
T_2 V_36 , struct V_467 * * V_42 , unsigned int V_50 , int V_525 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_326 ( V_4 , V_332 , V_36 ,
V_42 , V_50 , V_525 ) ;
F_329 ( V_4 -> V_46 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_4 -> V_46 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_330 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_530 )
{
struct V_515 * V_157 ;
int V_244 = V_6 -> V_10 ;
int V_288 = - V_126 ;
V_157 = F_316 ( V_3 , & V_4 -> V_11 , V_6 , V_531 ) ;
if ( V_157 == NULL )
goto V_131;
if ( F_331 ( V_244 ) )
V_157 -> V_374 . V_516 = V_532 ;
else if ( F_332 ( V_244 ) ) {
V_157 -> V_374 . V_516 = V_533 ;
V_157 -> V_374 . V_237 . V_534 . V_535 = F_333 ( V_530 ) ;
V_157 -> V_374 . V_237 . V_534 . V_536 = F_334 ( V_530 ) ;
}
else if ( F_335 ( V_244 ) ) {
V_157 -> V_374 . V_516 = V_537 ;
V_157 -> V_374 . V_237 . V_534 . V_535 = F_333 ( V_530 ) ;
V_157 -> V_374 . V_237 . V_534 . V_536 = F_334 ( V_530 ) ;
} else if ( ! F_336 ( V_244 ) ) {
V_288 = - V_27 ;
goto V_292;
}
V_157 -> V_374 . V_7 = V_7 ;
V_288 = F_317 ( V_3 , V_4 , V_157 ) ;
V_292:
F_319 ( V_157 ) ;
V_131:
return V_288 ;
}
static int F_337 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_530 )
{
struct V_61 V_62 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_304 () ;
do {
V_8 = F_330 ( V_3 , V_4 , V_6 , V_7 , V_530 ) ;
F_338 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_339 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_538 * V_539 )
{
struct V_540 args = {
. V_233 = V_409 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_541 V_57 = {
. V_539 = V_539 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_542 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
F_81 ( V_539 -> V_371 ) ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_340 ( struct V_13 * V_14 , struct V_408 * V_409 , struct V_538 * V_539 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_339 ( V_14 , V_409 , V_539 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_341 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_543 )
{
struct V_544 args = {
. V_233 = V_409 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_545 V_57 = {
. V_543 = V_543 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_546 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_267 ( struct V_13 * V_14 , struct V_408 * V_409 , struct V_442 * V_543 )
{
struct V_61 V_62 = { } ;
unsigned long V_547 = V_154 ;
int V_8 ;
do {
V_8 = F_341 ( V_14 , V_409 , V_543 ) ;
F_342 ( V_14 , V_409 , V_543 -> V_371 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_63 * V_64 = V_14 -> V_63 ;
F_34 ( & V_64 -> V_107 ) ;
V_64 -> V_548 = V_543 -> V_549 * V_88 ;
V_64 -> V_108 = V_547 ;
F_36 ( & V_64 -> V_107 ) ;
break;
}
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_343 ( struct V_13 * V_14 , struct V_408 * V_409 , struct V_442 * V_543 )
{
int error ;
F_81 ( V_543 -> V_371 ) ;
error = F_267 ( V_14 , V_409 , V_543 ) ;
if ( error == 0 ) {
V_14 -> V_550 = V_543 -> V_551 ;
F_344 ( V_14 , V_409 , V_543 -> V_552 ) ;
}
return error ;
}
static int F_345 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_553 * V_554 )
{
struct V_555 args = {
. V_233 = V_409 ,
. V_230 = V_14 -> V_15 ,
} ;
struct V_556 V_57 = {
. V_554 = V_554 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_557 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
if ( ( args . V_230 [ 0 ] & V_558 [ 0 ] ) == 0 ) {
memset ( V_554 , 0 , sizeof( * V_554 ) ) ;
return 0 ;
}
F_81 ( V_554 -> V_371 ) ;
return F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
}
static int F_346 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_553 * V_554 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_345 ( V_14 , V_409 , V_554 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
int F_347 ( T_8 * V_239 ,
const struct V_282 * V_283 ,
const struct V_559 * V_560 ,
T_5 V_205 )
{
const struct V_380 * V_381 = NULL ;
if ( V_560 != NULL )
V_381 = & V_560 -> V_381 ;
return F_233 ( V_239 , V_283 -> V_66 , V_205 , V_381 ) ;
}
static bool F_348 ( T_8 * V_239 ,
const struct V_282 * V_283 ,
const struct V_559 * V_560 ,
T_5 V_205 )
{
T_8 V_561 ;
if ( F_347 ( & V_561 , V_283 , V_560 , V_205 ) == - V_35 )
return true ;
return F_134 ( V_239 , & V_561 ) ;
}
static bool F_349 ( int V_8 )
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
void F_350 ( struct V_562 * V_563 )
{
F_327 ( V_563 -> V_2 ) ;
}
static int F_351 ( struct V_116 * V_117 , struct V_562 * V_563 )
{
struct V_13 * V_14 = F_85 ( V_563 -> V_2 ) ;
F_352 ( V_563 , V_117 -> V_149 ) ;
if ( F_241 ( V_117 , V_14 ,
V_563 -> args . V_564 -> V_66 ,
NULL ) == - V_130 ) {
F_57 ( V_117 ) ;
return - V_130 ;
}
F_350 ( V_563 ) ;
if ( V_117 -> V_149 > 0 )
F_37 ( V_14 , V_563 -> V_106 ) ;
return 0 ;
}
static bool F_353 ( struct V_116 * V_117 ,
struct V_565 * args )
{
if ( ! F_349 ( V_117 -> V_149 ) ||
F_348 ( & args -> V_239 ,
args -> V_564 ,
args -> V_566 ,
V_69 ) )
return false ;
F_57 ( V_117 ) ;
return true ;
}
static int F_354 ( struct V_116 * V_117 , struct V_562 * V_563 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_117 , & V_563 -> V_57 . V_160 ) )
return - V_130 ;
if ( F_353 ( V_117 , & V_563 -> args ) )
return - V_130 ;
return V_563 -> V_567 ? V_563 -> V_567 ( V_117 , V_563 ) :
F_351 ( V_117 , V_563 ) ;
}
static void F_355 ( struct V_562 * V_563 ,
struct V_161 * V_162 )
{
V_563 -> V_106 = V_154 ;
V_563 -> V_567 = F_351 ;
V_162 -> V_293 = & V_294 [ V_568 ] ;
F_38 ( & V_563 -> args . V_159 , & V_563 -> V_57 . V_160 , 0 ) ;
}
static int F_356 ( struct V_116 * V_117 ,
struct V_562 * V_563 )
{
if ( F_63 ( F_85 ( V_563 -> V_2 ) ,
& V_563 -> args . V_159 ,
& V_563 -> V_57 . V_160 ,
V_117 ) )
return 0 ;
if ( F_347 ( & V_563 -> args . V_239 , V_563 -> args . V_564 ,
V_563 -> args . V_566 ,
V_563 -> V_569 -> V_570 ) == - V_35 )
return - V_35 ;
if ( F_357 ( F_31 ( V_571 , & V_563 -> args . V_564 -> V_206 ) ) )
return - V_35 ;
return 0 ;
}
static int F_358 ( struct V_116 * V_117 ,
struct V_562 * V_563 )
{
struct V_2 * V_2 = V_563 -> V_2 ;
F_359 ( V_563 , V_117 -> V_149 ) ;
if ( F_241 ( V_117 , F_85 ( V_2 ) ,
V_563 -> args . V_564 -> V_66 ,
NULL ) == - V_130 ) {
F_57 ( V_117 ) ;
return - V_130 ;
}
if ( V_117 -> V_149 >= 0 ) {
F_37 ( F_85 ( V_2 ) , V_563 -> V_106 ) ;
F_360 ( V_2 , & V_563 -> V_371 ) ;
}
return 0 ;
}
static bool F_361 ( struct V_116 * V_117 ,
struct V_565 * args )
{
if ( ! F_349 ( V_117 -> V_149 ) ||
F_348 ( & args -> V_239 ,
args -> V_564 ,
args -> V_566 ,
V_217 ) )
return false ;
F_57 ( V_117 ) ;
return true ;
}
static int F_362 ( struct V_116 * V_117 , struct V_562 * V_563 )
{
if ( ! F_60 ( V_117 , & V_563 -> V_57 . V_160 ) )
return - V_130 ;
if ( F_361 ( V_117 , & V_563 -> args ) )
return - V_130 ;
return V_563 -> V_567 ? V_563 -> V_567 ( V_117 , V_563 ) :
F_358 ( V_117 , V_563 ) ;
}
static
bool F_363 ( struct V_562 * V_563 )
{
if ( V_563 -> V_572 != NULL || V_563 -> V_573 != NULL )
return false ;
return F_21 ( V_563 -> V_2 , V_69 ) == 0 ;
}
static void F_364 ( struct V_562 * V_563 ,
struct V_161 * V_162 )
{
struct V_13 * V_14 = F_85 ( V_563 -> V_2 ) ;
if ( ! F_363 ( V_563 ) ) {
V_563 -> args . V_230 = NULL ;
V_563 -> V_57 . V_371 = NULL ;
} else
V_563 -> args . V_230 = V_14 -> V_405 ;
if ( ! V_563 -> V_567 )
V_563 -> V_567 = F_358 ;
V_563 -> V_57 . V_14 = V_14 ;
V_563 -> V_106 = V_154 ;
V_162 -> V_293 = & V_294 [ V_574 ] ;
F_38 ( & V_563 -> args . V_159 , & V_563 -> V_57 . V_160 , 1 ) ;
}
static void F_365 ( struct V_116 * V_117 , struct V_575 * V_157 )
{
F_63 ( F_85 ( V_157 -> V_2 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_117 ) ;
}
static int F_366 ( struct V_116 * V_117 , struct V_575 * V_157 )
{
struct V_2 * V_2 = V_157 -> V_2 ;
F_367 ( V_157 , V_117 -> V_149 ) ;
if ( F_241 ( V_117 , F_85 ( V_2 ) ,
NULL , NULL ) == - V_130 ) {
F_57 ( V_117 ) ;
return - V_130 ;
}
return 0 ;
}
static int F_368 ( struct V_116 * V_117 , struct V_575 * V_157 )
{
if ( ! F_60 ( V_117 , & V_157 -> V_57 . V_160 ) )
return - V_130 ;
return V_157 -> V_576 ( V_117 , V_157 ) ;
}
static void F_369 ( struct V_575 * V_157 , struct V_161 * V_162 )
{
struct V_13 * V_14 = F_85 ( V_157 -> V_2 ) ;
if ( V_157 -> V_576 == NULL )
V_157 -> V_576 = F_366 ;
V_157 -> V_57 . V_14 = V_14 ;
V_162 -> V_293 = & V_294 [ V_577 ] ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
}
static void F_370 ( void * V_155 )
{
struct V_578 * V_157 = V_155 ;
struct V_63 * V_64 = V_157 -> V_91 ;
if ( F_371 ( & V_64 -> V_579 ) > 1 )
F_372 ( V_64 ) ;
F_373 ( V_64 ) ;
F_96 ( V_157 ) ;
}
static void F_374 ( struct V_116 * V_117 , void * V_155 )
{
struct V_578 * V_157 = V_155 ;
struct V_63 * V_64 = V_157 -> V_91 ;
unsigned long V_106 = V_157 -> V_106 ;
F_375 ( V_64 , V_117 -> V_149 ) ;
switch ( V_117 -> V_149 ) {
case 0 :
break;
case - V_78 :
F_26 ( V_64 ) ;
break;
default:
if ( F_31 ( V_580 , & V_64 -> V_581 ) == 0 )
return;
if ( V_117 -> V_149 != V_582 ) {
F_24 ( V_64 ) ;
return;
}
F_376 ( V_64 ) ;
}
F_33 ( V_64 , V_106 ) ;
}
static int F_377 ( struct V_63 * V_64 , struct V_298 * V_332 , unsigned V_583 )
{
struct V_161 V_162 = {
. V_293 = & V_294 [ V_584 ] ,
. V_296 = V_64 ,
. V_298 = V_332 ,
} ;
struct V_578 * V_157 ;
if ( V_583 == 0 )
return 0 ;
if ( ! F_378 ( & V_64 -> V_579 ) )
return - V_35 ;
V_157 = F_272 ( sizeof( * V_157 ) , V_285 ) ;
if ( V_157 == NULL )
return - V_126 ;
V_157 -> V_91 = V_64 ;
V_157 -> V_106 = V_154 ;
return F_379 ( V_64 -> V_101 , & V_162 , V_585 ,
& V_586 , V_157 ) ;
}
static int F_380 ( struct V_63 * V_64 , struct V_298 * V_332 )
{
struct V_161 V_162 = {
. V_293 = & V_294 [ V_584 ] ,
. V_296 = V_64 ,
. V_298 = V_332 ,
} ;
unsigned long V_547 = V_154 ;
int V_288 ;
V_288 = F_381 ( V_64 -> V_101 , & V_162 , V_585 ) ;
if ( V_288 < 0 )
return V_288 ;
F_33 ( V_64 , V_547 ) ;
return 0 ;
}
static inline int F_382 ( struct V_13 * V_14 )
{
return V_14 -> V_94 & V_417 ;
}
static int F_383 ( const void * V_587 , T_9 V_588 ,
struct V_467 * * V_42 , unsigned int * V_49 )
{
struct V_467 * V_589 , * * V_590 ;
int V_591 = 0 ;
T_9 V_12 ;
V_590 = V_42 ;
do {
V_12 = F_384 ( T_9 , V_592 , V_588 ) ;
V_589 = F_271 ( V_362 ) ;
if ( V_589 == NULL )
goto V_593;
memcpy ( F_385 ( V_589 ) , V_587 , V_12 ) ;
V_587 += V_12 ;
V_588 -= V_12 ;
* V_42 ++ = V_589 ;
V_591 ++ ;
} while ( V_588 != 0 );
return V_591 ;
V_593:
for(; V_591 > 0 ; V_591 -- )
F_275 ( V_590 [ V_591 - 1 ] ) ;
return - V_126 ;
}
static void F_386 ( struct V_2 * V_2 , struct V_594 * V_595 )
{
struct V_172 * V_173 = F_75 ( V_2 ) ;
F_34 ( & V_2 -> V_174 ) ;
F_96 ( V_173 -> V_596 ) ;
V_173 -> V_596 = V_595 ;
F_36 ( & V_2 -> V_174 ) ;
}
static void F_387 ( struct V_2 * V_2 )
{
F_386 ( V_2 , NULL ) ;
}
static inline T_11 F_388 ( struct V_2 * V_2 , char * V_587 , T_9 V_588 )
{
struct V_172 * V_173 = F_75 ( V_2 ) ;
struct V_594 * V_595 ;
int V_52 = - V_284 ;
F_34 ( & V_2 -> V_174 ) ;
V_595 = V_173 -> V_596 ;
if ( V_595 == NULL )
goto V_131;
if ( V_587 == NULL )
goto V_597;
if ( V_595 -> V_598 == 0 )
goto V_131;
V_52 = - V_599 ;
if ( V_595 -> V_12 > V_588 )
goto V_131;
memcpy ( V_587 , V_595 -> V_157 , V_595 -> V_12 ) ;
V_597:
V_52 = V_595 -> V_12 ;
V_131:
F_36 ( & V_2 -> V_174 ) ;
return V_52 ;
}
static void F_389 ( struct V_2 * V_2 , struct V_467 * * V_42 , T_9 V_49 , T_9 V_600 )
{
struct V_594 * V_595 ;
T_9 V_588 = sizeof( * V_595 ) + V_600 ;
if ( V_588 <= V_592 ) {
V_595 = F_272 ( V_588 , V_362 ) ;
if ( V_595 == NULL )
goto V_131;
V_595 -> V_598 = 1 ;
F_390 ( V_595 -> V_157 , V_42 , V_49 , V_600 ) ;
} else {
V_595 = F_272 ( sizeof( * V_595 ) , V_362 ) ;
if ( V_595 == NULL )
goto V_131;
V_595 -> V_598 = 0 ;
}
V_595 -> V_12 = V_600 ;
V_131:
F_386 ( V_2 , V_595 ) ;
}
static T_11 F_391 ( struct V_2 * V_2 , void * V_587 , T_9 V_588 )
{
struct V_467 * V_42 [ V_601 ] = { NULL , } ;
struct V_602 args = {
. V_233 = F_93 ( V_2 ) ,
. V_603 = V_42 ,
. V_600 = V_588 ,
} ;
struct V_604 V_57 = {
. V_600 = V_588 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_605 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
unsigned int V_606 = F_392 ( V_588 , V_592 ) ;
int V_52 = - V_126 , V_456 ;
if ( V_606 == 0 )
V_606 = 1 ;
if ( V_606 > F_263 ( V_42 ) )
return - V_599 ;
for ( V_456 = 0 ; V_456 < V_606 ; V_456 ++ ) {
V_42 [ V_456 ] = F_271 ( V_362 ) ;
if ( ! V_42 [ V_456 ] )
goto V_292;
}
V_57 . V_607 = F_271 ( V_362 ) ;
if ( ! V_57 . V_607 )
goto V_292;
args . V_600 = V_606 * V_592 ;
args . V_608 = 0 ;
F_8 ( L_40 ,
V_34 , V_587 , V_588 , V_606 , args . V_600 ) ;
V_52 = F_73 ( F_85 ( V_2 ) -> V_91 , F_85 ( V_2 ) ,
& V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
if ( V_52 )
goto V_292;
if ( V_57 . V_609 & V_610 ) {
if ( V_587 == NULL )
goto V_611;
V_52 = - V_599 ;
goto V_292;
}
F_389 ( V_2 , V_42 , V_57 . V_612 , V_57 . V_600 ) ;
if ( V_587 ) {
if ( V_57 . V_600 > V_588 ) {
V_52 = - V_599 ;
goto V_292;
}
F_390 ( V_587 , V_42 , V_57 . V_612 , V_57 . V_600 ) ;
}
V_611:
V_52 = V_57 . V_600 ;
V_292:
for ( V_456 = 0 ; V_456 < V_606 ; V_456 ++ )
if ( V_42 [ V_456 ] )
F_275 ( V_42 [ V_456 ] ) ;
if ( V_57 . V_607 )
F_275 ( V_57 . V_607 ) ;
return V_52 ;
}
static T_11 F_393 ( struct V_2 * V_2 , void * V_587 , T_9 V_588 )
{
struct V_61 V_62 = { } ;
T_11 V_52 ;
do {
V_52 = F_391 ( V_2 , V_587 , V_588 ) ;
F_394 ( V_2 , V_52 ) ;
if ( V_52 >= 0 )
break;
V_52 = F_20 ( F_85 ( V_2 ) , V_52 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_52 ;
}
static T_11 F_395 ( struct V_2 * V_2 , void * V_587 , T_9 V_588 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
int V_52 ;
if ( ! F_382 ( V_14 ) )
return - V_613 ;
V_52 = F_396 ( V_14 , V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( F_75 ( V_2 ) -> V_175 & V_614 )
F_397 ( V_2 ) ;
V_52 = F_388 ( V_2 , V_587 , V_588 ) ;
if ( V_52 != - V_284 )
return V_52 ;
return F_393 ( V_2 , V_587 , V_588 ) ;
}
static int F_398 ( struct V_2 * V_2 , const void * V_587 , T_9 V_588 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_467 * V_42 [ V_601 ] ;
struct V_615 V_374 = {
. V_233 = F_93 ( V_2 ) ,
. V_603 = V_42 ,
. V_600 = V_588 ,
} ;
struct V_616 V_57 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_617 ] ,
. V_296 = & V_374 ,
. V_297 = & V_57 ,
} ;
unsigned int V_606 = F_392 ( V_588 , V_592 ) ;
int V_52 , V_456 ;
if ( ! F_382 ( V_14 ) )
return - V_613 ;
if ( V_606 > F_263 ( V_42 ) )
return - V_599 ;
V_456 = F_383 ( V_587 , V_588 , V_374 . V_603 , & V_374 . V_608 ) ;
if ( V_456 < 0 )
return V_456 ;
F_22 ( V_2 ) ;
V_52 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_374 . V_159 , & V_57 . V_160 , 1 ) ;
for (; V_456 > 0 ; V_456 -- )
F_399 ( V_42 [ V_456 - 1 ] ) ;
F_34 ( & V_2 -> V_174 ) ;
F_75 ( V_2 ) -> V_175 |= V_176 ;
F_36 ( & V_2 -> V_174 ) ;
F_400 ( V_2 ) ;
F_397 ( V_2 ) ;
return V_52 ;
}
static int F_401 ( struct V_2 * V_2 , const void * V_587 , T_9 V_588 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_398 ( V_2 , V_587 , V_588 ) ;
F_402 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_403 ( struct V_2 * V_2 , void * V_587 ,
T_9 V_588 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_370 V_371 ;
struct V_1 V_7 = { 0 , 0 , V_588 , V_587 } ;
T_1 V_230 [ 3 ] = { 0 , 0 , V_438 } ;
struct V_470 V_374 = {
. V_233 = F_93 ( V_2 ) ,
. V_230 = V_230 ,
} ;
struct V_471 V_57 = {
. V_371 = & V_371 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_472 ] ,
. V_296 = & V_374 ,
. V_297 = & V_57 ,
} ;
int V_52 ;
F_81 ( & V_371 ) ;
V_52 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_374 . V_159 , & V_57 . V_160 , 0 ) ;
if ( V_52 )
return V_52 ;
if ( ! ( V_371 . V_279 & V_618 ) )
return - V_284 ;
if ( V_588 < V_7 . V_12 )
return - V_599 ;
return 0 ;
}
static int F_404 ( struct V_2 * V_2 , void * V_587 ,
T_9 V_588 )
{
struct V_61 V_62 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_613 ;
do {
V_8 = F_403 ( V_2 , V_587 , V_588 ) ;
F_405 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_406 ( struct V_2 * V_2 ,
struct V_1 * V_372 ,
struct V_370 * V_371 ,
struct V_1 * V_361 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
const T_1 V_230 [ 3 ] = { 0 , 0 , V_438 } ;
struct V_373 V_374 = {
. V_233 = F_93 ( V_2 ) ,
. V_375 = & V_6 ,
. V_14 = V_14 ,
. V_230 = V_230 ,
. V_7 = V_372 ,
} ;
struct V_376 V_57 = {
. V_371 = V_371 ,
. V_7 = V_361 ,
. V_14 = V_14 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_377 ] ,
. V_296 = & V_374 ,
. V_297 = & V_57 ,
} ;
int V_288 ;
F_123 ( & V_374 . V_239 , & V_387 ) ;
V_288 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_374 . V_159 , & V_57 . V_160 , 1 ) ;
if ( V_288 )
F_8 ( L_41 , V_34 , V_288 ) ;
return V_288 ;
}
static int F_407 ( struct V_2 * V_2 ,
struct V_1 * V_372 ,
struct V_370 * V_371 ,
struct V_1 * V_361 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_406 ( V_2 , V_372 ,
V_371 , V_361 ) ;
F_408 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int
F_409 ( struct V_4 * V_4 , const void * V_587 , T_9 V_588 )
{
struct V_1 V_372 , * V_361 = NULL ;
struct V_370 V_371 ;
struct V_298 * V_332 ;
struct V_2 * V_2 = V_4 -> V_46 ;
int V_288 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_613 ;
F_81 ( & V_371 ) ;
V_372 . V_619 = 0 ;
V_372 . V_620 = 0 ;
V_372 . V_7 = ( char * ) V_587 ;
V_372 . V_12 = V_588 ;
V_332 = F_410 () ;
if ( F_43 ( V_332 ) )
return F_71 ( V_332 ) ;
V_361 = F_87 ( F_85 ( V_2 ) , V_362 ) ;
if ( F_43 ( V_361 ) ) {
V_288 = - F_71 ( V_361 ) ;
goto V_131;
}
V_288 = F_407 ( V_2 , & V_372 , & V_371 , V_361 ) ;
if ( V_288 == 0 )
F_225 ( V_2 , & V_371 , V_361 ) ;
F_95 ( V_361 ) ;
V_131:
F_206 ( V_332 ) ;
return V_288 ;
}
static int
F_241 ( struct V_116 * V_117 , const struct V_13 * V_14 ,
struct V_65 * V_66 , long * V_51 )
{
struct V_63 * V_64 = V_14 -> V_63 ;
if ( V_117 -> V_149 >= 0 )
return 0 ;
switch( V_117 -> V_149 ) {
case - V_71 :
case - V_72 :
case - V_73 :
case - V_68 :
if ( V_66 == NULL )
break;
if ( F_23 ( V_14 , V_66 ) < 0 )
goto V_621;
goto V_70;
case - V_74 :
if ( V_66 != NULL ) {
if ( F_23 ( V_14 , V_66 ) < 0 )
goto V_621;
}
case - V_75 :
case - V_76 :
F_24 ( V_64 ) ;
goto V_70;
case - V_77 :
if ( F_25 ( V_14 ) < 0 )
goto V_621;
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
V_117 -> V_149 ) ;
F_28 ( V_64 -> V_87 , V_117 -> V_149 ) ;
goto V_70;
#endif
case - V_90 :
F_411 ( V_14 , V_622 ) ;
F_59 ( V_117 , F_15 ( V_51 ) ) ;
goto V_623;
case - V_89 :
F_59 ( V_117 , V_53 ) ;
case - V_92 :
case - V_93 :
goto V_623;
}
V_117 -> V_149 = F_7 ( V_117 -> V_149 ) ;
return 0 ;
V_621:
V_117 -> V_149 = - V_35 ;
return 0 ;
V_70:
F_47 ( & V_64 -> V_624 , V_117 , NULL ) ;
if ( F_31 ( V_625 , & V_64 -> V_626 ) == 0 )
F_412 ( & V_64 -> V_624 , V_117 ) ;
if ( F_31 ( V_98 , & V_14 -> V_99 ) )
goto V_621;
V_623:
V_117 -> V_149 = 0 ;
return - V_130 ;
}
static void F_413 ( const struct V_63 * V_64 ,
T_12 * V_627 )
{
T_3 V_236 [ 2 ] ;
if ( F_31 ( V_628 , & V_64 -> V_626 ) ) {
V_236 [ 0 ] = 0 ;
V_236 [ 1 ] = F_414 ( V_629 + 1 ) ;
} else {
struct V_630 * V_631 = F_415 ( V_64 -> V_632 , V_633 ) ;
V_236 [ 0 ] = F_414 ( V_631 -> V_634 . V_635 ) ;
V_236 [ 1 ] = F_414 ( V_631 -> V_634 . V_636 ) ;
}
memcpy ( V_627 -> V_157 , V_236 , sizeof( V_627 -> V_157 ) ) ;
}
static unsigned int
F_416 ( struct V_63 * V_64 ,
char * V_587 , T_9 V_12 )
{
unsigned int V_637 ;
if ( V_64 -> V_638 != NULL )
return F_417 ( V_587 , V_64 -> V_638 , V_12 ) ;
F_132 () ;
V_637 = F_418 ( V_587 , V_12 , L_43 ,
V_64 -> V_639 ,
F_419 ( V_64 -> V_101 ,
V_640 ) ,
F_419 ( V_64 -> V_101 ,
V_641 ) ) ;
F_135 () ;
V_64 -> V_638 = F_420 ( V_587 , V_362 ) ;
return V_637 ;
}
static unsigned int
F_421 ( struct V_63 * V_64 ,
char * V_587 , T_9 V_12 )
{
const char * V_642 = V_64 -> V_101 -> V_643 ;
unsigned int V_637 ;
if ( V_64 -> V_638 != NULL )
return F_417 ( V_587 , V_64 -> V_638 , V_12 ) ;
if ( V_644 [ 0 ] != '\0' )
V_637 = F_418 ( V_587 , V_12 , L_44 ,
V_64 -> V_645 -> V_646 ,
V_64 -> V_413 ,
V_644 ,
V_642 ) ;
else
V_637 = F_418 ( V_587 , V_12 , L_45 ,
V_64 -> V_645 -> V_646 , V_64 -> V_413 ,
V_642 ) ;
V_64 -> V_638 = F_420 ( V_587 , V_362 ) ;
return V_637 ;
}
static unsigned int
F_422 ( const struct V_63 * V_64 , char * V_587 , T_9 V_12 )
{
if ( strchr ( V_64 -> V_639 , ':' ) != NULL )
return F_418 ( V_587 , V_12 , L_46 ) ;
else
return F_418 ( V_587 , V_12 , L_47 ) ;
}
static void F_423 ( struct V_116 * V_117 , void * V_155 )
{
struct V_647 * V_648 = V_155 ;
if ( V_117 -> V_149 == 0 )
V_648 -> V_649 = F_202 ( V_117 -> V_650 -> V_651 ) ;
}
int F_424 ( struct V_63 * V_64 , T_1 V_652 ,
unsigned short V_653 , struct V_298 * V_332 ,
struct V_654 * V_57 )
{
T_12 V_655 ;
struct V_647 V_656 = {
. V_655 = & V_655 ,
. V_657 = V_652 ,
. V_658 = V_64 -> V_659 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_660 ] ,
. V_296 = & V_656 ,
. V_297 = V_57 ,
. V_298 = V_332 ,
} ;
struct V_116 * V_117 ;
struct V_163 V_299 = {
. V_165 = V_64 -> V_101 ,
. V_161 = & V_162 ,
. V_166 = & V_661 ,
. V_169 = & V_656 ,
. V_206 = V_585 ,
} ;
int V_288 ;
F_413 ( V_64 , & V_655 ) ;
if ( F_31 ( V_662 , & V_64 -> V_663 ) )
V_656 . V_664 =
F_421 ( V_64 ,
V_656 . V_665 ,
sizeof( V_656 . V_665 ) ) ;
else
V_656 . V_664 =
F_416 ( V_64 ,
V_656 . V_665 ,
sizeof( V_656 . V_665 ) ) ;
V_656 . V_666 =
F_422 ( V_64 ,
V_656 . V_667 ,
sizeof( V_656 . V_667 ) ) ;
V_656 . V_668 = F_418 ( V_656 . V_669 ,
sizeof( V_656 . V_669 ) , L_48 ,
V_64 -> V_639 , V_653 >> 8 , V_653 & 255 ) ;
F_8 ( L_49 ,
V_64 -> V_101 -> V_102 -> V_670 -> V_671 ,
V_656 . V_664 , V_656 . V_665 ) ;
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) ) {
V_288 = F_71 ( V_117 ) ;
goto V_131;
}
V_288 = V_117 -> V_149 ;
if ( V_656 . V_649 ) {
V_64 -> V_672 = F_425 ( V_656 . V_649 ) ;
F_206 ( V_656 . V_649 ) ;
}
F_72 ( V_117 ) ;
V_131:
F_426 ( V_64 , V_288 ) ;
F_8 ( L_50 , V_288 ) ;
return V_288 ;
}
int F_427 ( struct V_63 * V_64 ,
struct V_654 * V_374 ,
struct V_298 * V_332 )
{
struct V_161 V_162 = {
. V_293 = & V_294 [ V_673 ] ,
. V_296 = V_374 ,
. V_298 = V_332 ,
} ;
int V_288 ;
F_8 ( L_51 ,
V_64 -> V_101 -> V_102 -> V_670 -> V_671 ,
V_64 -> V_224 ) ;
V_288 = F_381 ( V_64 -> V_101 , & V_162 , V_585 ) ;
F_428 ( V_64 , V_288 ) ;
F_8 ( L_52 , V_288 ) ;
return V_288 ;
}
static void F_429 ( struct V_116 * V_117 , void * V_155 )
{
struct V_674 * V_157 = V_155 ;
if ( ! F_60 ( V_117 , & V_157 -> V_57 . V_160 ) )
return;
F_430 ( & V_157 -> args , & V_157 -> V_57 , V_117 -> V_149 ) ;
switch ( V_117 -> V_149 ) {
case 0 :
F_37 ( V_157 -> V_57 . V_14 , V_157 -> V_106 ) ;
case - V_72 :
case - V_71 :
case - V_73 :
case - V_93 :
case - V_75 :
case - V_74 :
V_117 -> V_149 = 0 ;
if ( V_157 -> V_391 )
F_240 ( V_157 -> V_2 , V_157 -> V_393 ) ;
break;
default:
if ( F_241 ( V_117 , V_157 -> V_57 . V_14 ,
NULL , NULL ) == - V_130 ) {
F_57 ( V_117 ) ;
return;
}
}
V_157 -> V_276 = V_117 -> V_149 ;
}
static void F_431 ( void * V_155 )
{
struct V_674 * V_157 = V_155 ;
if ( V_157 -> V_391 )
F_237 ( V_157 -> V_2 ) ;
F_96 ( V_155 ) ;
}
static void F_432 ( struct V_116 * V_117 , void * V_157 )
{
struct V_674 * V_675 ;
V_675 = (struct V_674 * ) V_157 ;
if ( V_675 -> V_391 &&
F_243 ( V_675 -> V_2 , & V_675 -> V_393 , V_117 ) )
return;
F_63 ( V_675 -> V_57 . V_14 ,
& V_675 -> args . V_159 ,
& V_675 -> V_57 . V_160 ,
V_117 ) ;
}
static int F_433 ( struct V_2 * V_2 , struct V_298 * V_332 , const T_8 * V_239 , int V_676 )
{
struct V_674 * V_157 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_116 * V_117 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_677 ] ,
. V_298 = V_332 ,
} ;
struct V_163 V_299 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_678 ,
. V_206 = V_303 ,
} ;
int V_288 = 0 ;
V_157 = F_86 ( sizeof( * V_157 ) , V_285 ) ;
if ( V_157 == NULL )
return - V_126 ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
V_157 -> args . V_409 = & V_157 -> V_233 ;
V_157 -> args . V_239 = & V_157 -> V_239 ;
V_157 -> args . V_230 = V_14 -> V_405 ;
F_178 ( & V_157 -> V_233 , F_93 ( V_2 ) ) ;
F_123 ( & V_157 -> V_239 , V_239 ) ;
V_157 -> V_57 . V_371 = & V_157 -> V_371 ;
V_157 -> V_57 . V_14 = V_14 ;
F_81 ( V_157 -> V_57 . V_371 ) ;
V_157 -> V_106 = V_154 ;
V_157 -> V_276 = 0 ;
V_157 -> V_2 = V_2 ;
V_157 -> V_391 = F_434 ( & F_75 ( V_2 ) -> V_679 ) ?
F_247 ( V_2 ) : false ;
V_299 . V_169 = V_157 ;
V_162 . V_296 = & V_157 -> args ;
V_162 . V_297 = & V_157 -> V_57 ;
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) )
return F_71 ( V_117 ) ;
if ( ! V_676 )
goto V_131;
V_288 = F_107 ( V_117 ) ;
if ( V_288 != 0 )
goto V_131;
V_288 = V_157 -> V_276 ;
if ( V_288 == 0 )
F_360 ( V_2 , & V_157 -> V_371 ) ;
else
F_145 ( V_2 , & V_157 -> V_371 ) ;
V_131:
F_72 ( V_117 ) ;
return V_288 ;
}
int F_435 ( struct V_2 * V_2 , struct V_298 * V_332 , const T_8 * V_239 , int V_676 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_433 ( V_2 , V_332 , V_239 , V_676 ) ;
F_436 ( V_2 , V_8 ) ;
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
F_437 ( unsigned long V_51 )
{
F_18 ( V_51 ) ;
V_51 <<= 1 ;
if ( V_51 > V_680 )
return V_680 ;
return V_51 ;
}
static int F_438 ( struct V_65 * V_66 , int V_681 , struct V_682 * V_683 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
struct V_684 V_374 = {
. V_233 = F_93 ( V_2 ) ,
. V_685 = V_683 ,
} ;
struct V_686 V_57 = {
. V_687 = V_683 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_688 ] ,
. V_296 = & V_374 ,
. V_297 = & V_57 ,
. V_298 = V_66 -> V_214 -> V_272 ,
} ;
struct V_689 * V_690 ;
int V_288 ;
V_374 . V_691 . V_223 = V_64 -> V_224 ;
V_288 = F_439 ( V_66 , V_683 ) ;
if ( V_288 != 0 )
goto V_131;
V_690 = V_683 -> V_692 . V_693 . V_214 ;
V_374 . V_691 . V_225 = V_690 -> V_694 . V_228 ;
V_374 . V_691 . V_695 = V_14 -> V_695 ;
V_288 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & V_374 . V_159 , & V_57 . V_160 , 1 ) ;
switch ( V_288 ) {
case 0 :
V_683 -> V_696 = V_697 ;
break;
case - V_290 :
V_288 = 0 ;
}
V_683 -> V_698 -> V_699 ( V_683 ) ;
V_683 -> V_698 = NULL ;
V_131:
return V_288 ;
}
static int F_440 ( struct V_65 * V_66 , int V_681 , struct V_682 * V_683 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_438 ( V_66 , V_681 , V_683 ) ;
F_441 ( V_683 , V_66 , V_681 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_66 -> V_2 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_442 ( struct V_700 * V_700 , struct V_682 * V_685 )
{
int V_57 = 0 ;
switch ( V_685 -> V_701 & ( V_702 | V_703 ) ) {
case V_702 :
V_57 = F_443 ( V_700 , V_685 ) ;
break;
case V_703 :
V_57 = F_444 ( V_700 , V_685 ) ;
break;
default:
F_445 () ;
}
return V_57 ;
}
static struct V_704 * F_446 ( struct V_682 * V_685 ,
struct V_282 * V_283 ,
struct V_689 * V_690 ,
struct V_705 * V_195 )
{
struct V_704 * V_41 ;
struct V_2 * V_2 = V_690 -> V_706 -> V_2 ;
V_41 = F_86 ( sizeof( * V_41 ) , V_285 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_374 . V_233 = F_93 ( V_2 ) ;
V_41 -> V_374 . V_685 = & V_41 -> V_685 ;
V_41 -> V_374 . V_195 = V_195 ;
V_41 -> V_57 . V_195 = V_195 ;
V_41 -> V_374 . V_239 = & V_690 -> V_707 ;
V_41 -> V_690 = V_690 ;
F_91 ( & V_690 -> V_708 ) ;
V_41 -> V_283 = F_153 ( V_283 ) ;
memcpy ( & V_41 -> V_685 , V_685 , sizeof( V_41 -> V_685 ) ) ;
V_41 -> V_14 = F_85 ( V_2 ) ;
return V_41 ;
}
static void F_447 ( void * V_157 )
{
struct V_704 * V_155 = V_157 ;
F_100 ( V_155 -> V_374 . V_195 ) ;
F_448 ( V_155 -> V_690 ) ;
F_164 ( V_155 -> V_283 ) ;
F_96 ( V_155 ) ;
}
static void F_449 ( struct V_116 * V_117 , void * V_157 )
{
struct V_704 * V_155 = V_157 ;
if ( ! F_60 ( V_117 , & V_155 -> V_57 . V_160 ) )
return;
switch ( V_117 -> V_149 ) {
case 0 :
F_123 ( & V_155 -> V_690 -> V_707 ,
& V_155 -> V_57 . V_239 ) ;
F_37 ( V_155 -> V_14 , V_155 -> V_106 ) ;
break;
case - V_73 :
case - V_93 :
case - V_75 :
case - V_74 :
break;
default:
if ( F_241 ( V_117 , V_155 -> V_14 ,
NULL , NULL ) == - V_130 )
F_57 ( V_117 ) ;
}
F_138 ( V_155 -> V_374 . V_195 ) ;
}
static void F_450 ( struct V_116 * V_117 , void * V_157 )
{
struct V_704 * V_155 = V_157 ;
if ( F_177 ( V_155 -> V_374 . V_195 , V_117 ) != 0 )
goto V_304;
if ( F_31 ( V_709 , & V_155 -> V_690 -> V_710 ) == 0 ) {
goto V_305;
}
V_155 -> V_106 = V_154 ;
if ( F_63 ( V_155 -> V_14 ,
& V_155 -> V_374 . V_159 ,
& V_155 -> V_57 . V_160 ,
V_117 ) != 0 )
F_138 ( V_155 -> V_374 . V_195 ) ;
return;
V_305:
V_117 -> V_316 = NULL ;
V_304:
F_60 ( V_117 , & V_155 -> V_57 . V_160 ) ;
}
static struct V_116 * F_451 ( struct V_682 * V_685 ,
struct V_282 * V_283 ,
struct V_689 * V_690 ,
struct V_705 * V_195 )
{
struct V_704 * V_157 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_711 ] ,
. V_298 = V_283 -> V_332 ,
} ;
struct V_163 V_299 = {
. V_165 = F_290 ( V_690 -> V_706 -> V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_712 ,
. V_301 = V_302 ,
. V_206 = V_303 ,
} ;
F_249 ( F_85 ( V_690 -> V_706 -> V_2 ) -> V_63 ,
V_403 , & V_299 . V_165 , & V_162 ) ;
V_685 -> V_696 = V_697 ;
V_157 = F_446 ( V_685 , V_283 , V_690 , V_195 ) ;
if ( V_157 == NULL ) {
F_100 ( V_195 ) ;
return F_44 ( - V_126 ) ;
}
F_38 ( & V_157 -> V_374 . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
V_162 . V_296 = & V_157 -> V_374 ;
V_162 . V_297 = & V_157 -> V_57 ;
V_299 . V_169 = V_157 ;
return F_70 ( & V_299 ) ;
}
static int F_452 ( struct V_65 * V_66 , int V_681 , struct V_682 * V_683 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_203 * V_204 = V_66 -> V_214 ;
struct V_172 * V_173 = F_75 ( V_2 ) ;
struct V_705 * V_195 ;
struct V_689 * V_690 ;
struct V_116 * V_117 ;
int V_288 = 0 ;
unsigned char V_701 = V_683 -> V_701 ;
V_288 = F_439 ( V_66 , V_683 ) ;
V_683 -> V_701 |= V_713 ;
F_453 ( & V_204 -> V_714 ) ;
F_454 ( & V_173 -> V_715 ) ;
if ( F_442 ( V_683 -> V_716 , V_683 ) == - V_284 ) {
F_455 ( & V_173 -> V_715 ) ;
F_456 ( & V_204 -> V_714 ) ;
goto V_131;
}
F_455 ( & V_173 -> V_715 ) ;
F_456 ( & V_204 -> V_714 ) ;
if ( V_288 != 0 )
goto V_131;
V_690 = V_683 -> V_692 . V_693 . V_214 ;
if ( F_31 ( V_709 , & V_690 -> V_710 ) == 0 )
goto V_131;
V_195 = F_88 ( & V_690 -> V_694 , V_362 ) ;
V_288 = - V_126 ;
if ( V_195 == NULL )
goto V_131;
V_117 = F_451 ( V_683 , F_282 ( V_683 -> V_716 ) , V_690 , V_195 ) ;
V_288 = F_71 ( V_117 ) ;
if ( F_43 ( V_117 ) )
goto V_131;
V_288 = F_107 ( V_117 ) ;
F_72 ( V_117 ) ;
V_131:
V_683 -> V_701 = V_701 ;
F_457 ( V_683 , V_66 , V_717 , V_288 ) ;
return V_288 ;
}
static struct V_718 * F_458 ( struct V_682 * V_685 ,
struct V_282 * V_283 , struct V_689 * V_690 ,
T_6 V_208 )
{
struct V_718 * V_41 ;
struct V_2 * V_2 = V_690 -> V_706 -> V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
V_41 = F_86 ( sizeof( * V_41 ) , V_208 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_374 . V_233 = F_93 ( V_2 ) ;
V_41 -> V_374 . V_685 = & V_41 -> V_685 ;
V_41 -> V_374 . V_719 = F_88 ( & V_690 -> V_706 -> V_214 -> V_211 , V_208 ) ;
if ( V_41 -> V_374 . V_719 == NULL )
goto V_292;
V_41 -> V_374 . V_720 = F_88 ( & V_690 -> V_694 , V_208 ) ;
if ( V_41 -> V_374 . V_720 == NULL )
goto V_721;
V_41 -> V_374 . V_722 = & V_690 -> V_707 ;
V_41 -> V_374 . V_691 . V_223 = V_14 -> V_63 -> V_224 ;
V_41 -> V_374 . V_691 . V_225 = V_690 -> V_694 . V_228 ;
V_41 -> V_374 . V_691 . V_695 = V_14 -> V_695 ;
V_41 -> V_57 . V_720 = V_41 -> V_374 . V_720 ;
V_41 -> V_690 = V_690 ;
V_41 -> V_14 = V_14 ;
F_91 ( & V_690 -> V_708 ) ;
V_41 -> V_283 = F_153 ( V_283 ) ;
memcpy ( & V_41 -> V_685 , V_685 , sizeof( V_41 -> V_685 ) ) ;
return V_41 ;
V_721:
F_100 ( V_41 -> V_374 . V_719 ) ;
V_292:
F_96 ( V_41 ) ;
return NULL ;
}
static void F_459 ( struct V_116 * V_117 , void * V_155 )
{
struct V_718 * V_157 = V_155 ;
struct V_65 * V_66 = V_157 -> V_690 -> V_706 ;
F_8 ( L_29 , V_34 ) ;
if ( F_177 ( V_157 -> V_374 . V_720 , V_117 ) != 0 )
goto V_304;
if ( ! ( V_157 -> V_374 . V_720 -> V_723 -> V_206 & V_724 ) ) {
if ( F_177 ( V_157 -> V_374 . V_719 , V_117 ) != 0 ) {
goto V_725;
}
V_157 -> V_374 . V_259 = & V_66 -> V_259 ;
V_157 -> V_374 . V_726 = 1 ;
V_157 -> V_57 . V_719 = V_157 -> V_374 . V_719 ;
} else
V_157 -> V_374 . V_726 = 0 ;
if ( ! F_232 ( V_66 ) ) {
V_157 -> V_276 = - V_386 ;
V_117 -> V_316 = NULL ;
goto V_727;
}
V_157 -> V_106 = V_154 ;
if ( F_63 ( V_157 -> V_14 ,
& V_157 -> V_374 . V_159 ,
& V_157 -> V_57 . V_160 ,
V_117 ) == 0 )
return;
V_727:
F_138 ( V_157 -> V_374 . V_719 ) ;
V_725:
F_138 ( V_157 -> V_374 . V_720 ) ;
V_304:
F_60 ( V_117 , & V_157 -> V_57 . V_160 ) ;
F_8 ( L_53 , V_34 , V_157 -> V_276 ) ;
}
static void F_460 ( struct V_116 * V_117 , void * V_155 )
{
struct V_718 * V_157 = V_155 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_60 ( V_117 , & V_157 -> V_57 . V_160 ) )
return;
V_157 -> V_276 = V_117 -> V_149 ;
if ( V_157 -> V_374 . V_726 != 0 ) {
if ( V_157 -> V_276 == 0 )
F_171 ( & V_157 -> V_690 -> V_694 , 0 ) ;
else
goto V_131;
}
if ( V_157 -> V_276 == 0 ) {
F_123 ( & V_157 -> V_690 -> V_707 , & V_157 -> V_57 . V_239 ) ;
F_129 ( V_709 , & V_157 -> V_690 -> V_710 ) ;
F_37 ( F_85 ( V_157 -> V_283 -> V_4 -> V_46 ) , V_157 -> V_106 ) ;
}
V_131:
F_8 ( L_30 , V_34 , V_157 -> V_276 ) ;
}
static void F_461 ( void * V_155 )
{
struct V_718 * V_157 = V_155 ;
F_8 ( L_29 , V_34 ) ;
F_100 ( V_157 -> V_374 . V_719 ) ;
if ( V_157 -> V_291 != 0 ) {
struct V_116 * V_117 ;
V_117 = F_451 ( & V_157 -> V_685 , V_157 -> V_283 , V_157 -> V_690 ,
V_157 -> V_374 . V_720 ) ;
if ( ! F_43 ( V_117 ) )
F_462 ( V_117 ) ;
F_8 ( L_54 , V_34 ) ;
} else
F_100 ( V_157 -> V_374 . V_720 ) ;
F_448 ( V_157 -> V_690 ) ;
F_164 ( V_157 -> V_283 ) ;
F_96 ( V_157 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_463 ( struct V_13 * V_14 , struct V_689 * V_690 , int V_726 , int error )
{
switch ( error ) {
case - V_72 :
case - V_73 :
V_690 -> V_694 . V_206 &= ~ V_724 ;
if ( V_726 != 0 ||
F_31 ( V_709 , & V_690 -> V_710 ) != 0 )
F_23 ( V_14 , V_690 -> V_706 ) ;
break;
case - V_75 :
V_690 -> V_694 . V_206 &= ~ V_724 ;
case - V_74 :
F_24 ( V_14 -> V_63 ) ;
} ;
}
static int F_464 ( struct V_65 * V_66 , int V_681 , struct V_682 * V_685 , int V_728 )
{
struct V_718 * V_157 ;
struct V_116 * V_117 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_729 ] ,
. V_298 = V_66 -> V_214 -> V_272 ,
} ;
struct V_163 V_299 = {
. V_165 = F_290 ( V_66 -> V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_730 ,
. V_301 = V_302 ,
. V_206 = V_303 ,
} ;
int V_52 ;
F_8 ( L_29 , V_34 ) ;
V_157 = F_458 ( V_685 , F_282 ( V_685 -> V_716 ) ,
V_685 -> V_692 . V_693 . V_214 ,
V_728 == V_731 ? V_362 : V_285 ) ;
if ( V_157 == NULL )
return - V_126 ;
if ( F_465 ( V_681 ) )
V_157 -> V_374 . V_732 = 1 ;
F_38 ( & V_157 -> V_374 . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
V_162 . V_296 = & V_157 -> V_374 ;
V_162 . V_297 = & V_157 -> V_57 ;
V_299 . V_169 = V_157 ;
if ( V_728 > V_731 ) {
if ( V_728 == V_733 )
V_157 -> V_374 . V_734 = V_733 ;
F_39 ( & V_157 -> V_374 . V_159 ) ;
}
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) )
return F_71 ( V_117 ) ;
V_52 = F_107 ( V_117 ) ;
if ( V_52 == 0 ) {
V_52 = V_157 -> V_276 ;
if ( V_52 )
F_463 ( V_157 -> V_14 , V_157 -> V_690 ,
V_157 -> V_374 . V_726 , V_52 ) ;
} else
V_157 -> V_291 = 1 ;
F_72 ( V_117 ) ;
F_8 ( L_30 , V_34 , V_52 ) ;
return V_52 ;
}
static int F_466 ( struct V_65 * V_66 , struct V_682 * V_683 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_31 ( V_260 , & V_66 -> V_206 ) != 0 )
return 0 ;
V_8 = F_464 ( V_66 , V_717 , V_683 , V_733 ) ;
F_467 ( V_683 , V_66 , V_717 , V_8 ) ;
if ( V_8 != - V_90 )
break;
F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_468 ( struct V_65 * V_66 , struct V_682 * V_683 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
struct V_61 V_62 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
V_8 = F_439 ( V_66 , V_683 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_735 ) {
F_129 ( V_736 , & V_683 -> V_692 . V_693 . V_214 -> V_710 ) ;
return 0 ;
}
do {
if ( F_31 ( V_260 , & V_66 -> V_206 ) != 0 )
return 0 ;
V_8 = F_464 ( V_66 , V_717 , V_683 , V_737 ) ;
F_469 ( V_683 , V_66 , V_717 , V_8 ) ;
switch ( V_8 ) {
default:
goto V_131;
case - V_89 :
case - V_90 :
F_20 ( V_14 , V_8 , & V_62 ) ;
V_8 = 0 ;
}
} while ( V_62 . V_67 );
V_131:
return V_8 ;
}
static int F_470 ( struct V_65 * V_66 )
{
int V_288 , V_52 = - V_73 ;
struct V_689 * V_690 ;
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
F_152 (lsp, &state->lock_states, ls_locks) {
if ( F_31 ( V_709 , & V_690 -> V_710 ) ) {
struct V_298 * V_332 = V_690 -> V_706 -> V_214 -> V_272 ;
V_288 = F_203 ( V_14 ,
& V_690 -> V_707 ,
V_332 ) ;
F_471 ( V_66 , V_690 , V_288 ) ;
if ( V_288 != V_346 ) {
if ( V_288 != - V_73 )
F_205 ( V_14 ,
& V_690 -> V_707 ,
V_332 ) ;
F_122 ( V_709 , & V_690 -> V_710 ) ;
V_52 = V_288 ;
}
}
} ;
return V_52 ;
}
static int F_472 ( struct V_65 * V_66 , struct V_682 * V_683 )
{
int V_288 = V_346 ;
if ( F_31 ( V_738 , & V_66 -> V_206 ) )
V_288 = F_470 ( V_66 ) ;
if ( V_288 != V_346 )
V_288 = F_468 ( V_66 , V_683 ) ;
return V_288 ;
}
static int F_473 ( struct V_65 * V_66 , int V_681 , struct V_682 * V_683 )
{
struct V_203 * V_204 = V_66 -> V_214 ;
struct V_172 * V_173 = F_75 ( V_66 -> V_2 ) ;
unsigned char V_701 = V_683 -> V_701 ;
unsigned int V_354 ;
int V_288 = - V_739 ;
if ( ( V_701 & V_702 ) &&
! F_31 ( V_356 , & V_66 -> V_206 ) )
goto V_131;
V_288 = F_439 ( V_66 , V_683 ) ;
if ( V_288 != 0 )
goto V_131;
V_683 -> V_701 |= V_740 ;
V_288 = F_442 ( V_683 -> V_716 , V_683 ) ;
if ( V_288 < 0 )
goto V_131;
F_454 ( & V_173 -> V_715 ) ;
if ( F_31 ( V_260 , & V_66 -> V_206 ) ) {
V_683 -> V_701 = V_701 & ~ V_741 ;
V_288 = F_442 ( V_683 -> V_716 , V_683 ) ;
goto V_138;
}
V_354 = F_212 ( & V_204 -> V_355 ) ;
F_455 ( & V_173 -> V_715 ) ;
V_288 = F_464 ( V_66 , V_681 , V_683 , V_731 ) ;
if ( V_288 != 0 )
goto V_131;
F_454 ( & V_173 -> V_715 ) ;
if ( F_218 ( & V_204 -> V_355 , V_354 ) ) {
V_288 = - V_90 ;
goto V_138;
}
V_683 -> V_701 = V_701 | V_741 ;
if ( F_442 ( V_683 -> V_716 , V_683 ) < 0 )
F_29 ( V_96 L_55
L_56 , V_34 ) ;
V_138:
F_455 ( & V_173 -> V_715 ) ;
V_131:
V_683 -> V_701 = V_701 ;
return V_288 ;
}
static int F_474 ( struct V_65 * V_66 , int V_681 , struct V_682 * V_683 )
{
struct V_61 V_62 = {
. V_66 = V_66 ,
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_473 ( V_66 , V_681 , V_683 ) ;
F_475 ( V_683 , V_66 , V_681 , V_8 ) ;
if ( V_8 == - V_290 )
V_8 = - V_130 ;
V_8 = F_20 ( F_85 ( V_66 -> V_2 ) ,
V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int
F_476 ( struct V_700 * V_742 , int V_681 , struct V_682 * V_683 )
{
struct V_282 * V_283 ;
struct V_65 * V_66 ;
unsigned long V_51 = V_743 ;
int V_288 ;
V_283 = F_282 ( V_742 ) ;
V_66 = V_283 -> V_66 ;
if ( V_683 -> V_744 < 0 || V_683 -> V_745 < 0 )
return - V_27 ;
if ( F_477 ( V_681 ) ) {
if ( V_66 != NULL )
return F_440 ( V_66 , V_746 , V_683 ) ;
return 0 ;
}
if ( ! ( F_478 ( V_681 ) || F_465 ( V_681 ) ) )
return - V_27 ;
if ( V_683 -> V_696 == V_697 ) {
if ( V_66 != NULL )
return F_452 ( V_66 , V_681 , V_683 ) ;
return 0 ;
}
if ( V_66 == NULL )
return - V_739 ;
switch ( V_683 -> V_696 ) {
case V_747 :
if ( ! ( V_742 -> V_748 & V_69 ) )
return - V_386 ;
break;
case V_749 :
if ( ! ( V_742 -> V_748 & V_217 ) )
return - V_386 ;
}
do {
V_288 = F_474 ( V_66 , V_681 , V_683 ) ;
if ( ( V_288 != - V_130 ) || F_478 ( V_681 ) )
break;
V_51 = F_437 ( V_51 ) ;
V_288 = - V_59 ;
if ( F_479 () )
break;
} while( V_288 < 0 );
return V_288 ;
}
int F_480 ( struct V_682 * V_685 , struct V_65 * V_66 , const T_8 * V_239 )
{
struct V_13 * V_14 = F_85 ( V_66 -> V_2 ) ;
int V_8 ;
V_8 = F_439 ( V_66 , V_685 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_464 ( V_66 , V_717 , V_685 , V_731 ) ;
return F_165 ( V_14 , V_66 , V_239 , V_8 ) ;
}
static void F_481 ( struct V_116 * V_117 , void * V_155 )
{
struct V_750 * V_157 = V_155 ;
struct V_13 * V_14 = V_157 -> V_14 ;
F_40 ( V_14 , & V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 , V_117 ) ;
V_157 -> args . V_691 . V_223 = V_14 -> V_63 -> V_224 ;
V_157 -> V_106 = V_154 ;
}
static void F_482 ( struct V_116 * V_117 , void * V_155 )
{
struct V_750 * V_157 = V_155 ;
struct V_13 * V_14 = V_157 -> V_14 ;
F_48 ( V_117 , & V_157 -> V_57 . V_160 ) ;
switch ( V_117 -> V_149 ) {
case 0 :
F_37 ( V_14 , V_157 -> V_106 ) ;
break;
case - V_76 :
case - V_74 :
F_24 ( V_14 -> V_63 ) ;
break;
case - V_78 :
case - V_90 :
if ( F_241 ( V_117 , V_14 ,
NULL , NULL ) == - V_130 )
F_57 ( V_117 ) ;
}
}
static void F_483 ( void * V_155 )
{
struct V_750 * V_157 = V_155 ;
F_484 ( V_157 -> V_14 , V_157 -> V_690 ) ;
F_96 ( V_155 ) ;
}
static void
F_485 ( struct V_13 * V_14 , struct V_689 * V_690 )
{
struct V_750 * V_157 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_751 ] ,
} ;
if ( V_14 -> V_63 -> V_167 -> V_314 != 0 )
return;
V_157 = F_272 ( sizeof( * V_157 ) , V_285 ) ;
if ( ! V_157 )
return;
V_157 -> V_690 = V_690 ;
V_157 -> V_14 = V_14 ;
V_157 -> args . V_691 . V_223 = V_14 -> V_63 -> V_224 ;
V_157 -> args . V_691 . V_225 = V_690 -> V_694 . V_228 ;
V_157 -> args . V_691 . V_695 = V_14 -> V_695 ;
V_162 . V_296 = & V_157 -> args ;
V_162 . V_297 = & V_157 -> V_57 ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 0 ) ;
F_379 ( V_14 -> V_91 , & V_162 , 0 , & V_752 , V_157 ) ;
}
static int F_486 ( struct V_4 * V_4 , const char * V_753 ,
const void * V_587 , T_9 V_588 ,
int V_206 , int type )
{
if ( strcmp ( V_753 , L_57 ) != 0 )
return - V_27 ;
return F_401 ( V_4 -> V_46 , V_587 , V_588 ) ;
}
static int F_487 ( struct V_4 * V_4 , const char * V_753 ,
void * V_587 , T_9 V_588 , int type )
{
if ( strcmp ( V_753 , L_57 ) != 0 )
return - V_27 ;
return F_395 ( V_4 -> V_46 , V_587 , V_588 ) ;
}
static T_9 F_488 ( struct V_4 * V_4 , char * V_754 ,
T_9 V_755 , const char * V_229 ,
T_9 V_756 , int type )
{
T_9 V_12 = sizeof( V_757 ) ;
if ( ! F_382 ( F_85 ( V_4 -> V_46 ) ) )
return 0 ;
if ( V_754 && V_12 <= V_755 )
memcpy ( V_754 , V_757 , V_12 ) ;
return V_12 ;
}
static inline int F_489 ( struct V_13 * V_14 )
{
return V_14 -> V_94 & V_9 ;
}
static int F_490 ( struct V_4 * V_4 , const char * V_753 ,
const void * V_587 , T_9 V_588 ,
int V_206 , int type )
{
if ( F_491 ( V_753 ) )
return F_409 ( V_4 , V_587 , V_588 ) ;
return - V_613 ;
}
static int F_492 ( struct V_4 * V_4 , const char * V_753 ,
void * V_587 , T_9 V_588 , int type )
{
if ( F_491 ( V_753 ) )
return F_404 ( V_4 -> V_46 , V_587 , V_588 ) ;
return - V_613 ;
}
static T_9 F_493 ( struct V_4 * V_4 , char * V_754 ,
T_9 V_755 , const char * V_229 ,
T_9 V_756 , int type )
{
T_9 V_12 = 0 ;
if ( F_2 ( V_4 -> V_46 , V_9 ) ) {
V_12 = F_494 ( V_4 -> V_46 , NULL , 0 ) ;
if ( V_754 && V_12 <= V_755 )
F_494 ( V_4 -> V_46 , V_754 , V_12 ) ;
}
return V_12 ;
}
static void F_274 ( struct V_370 * V_371 )
{
if ( ! ( ( ( V_371 -> V_279 & V_758 ) ||
( V_371 -> V_279 & V_759 ) ) &&
( V_371 -> V_279 & V_464 ) &&
( V_371 -> V_279 & V_760 ) ) )
return;
V_371 -> V_279 |= V_317 | V_480 |
V_481 | V_761 ;
V_371 -> V_244 = V_322 | V_483 | V_484 ;
V_371 -> V_485 = 2 ;
}
static int F_495 ( struct V_55 * V_91 , struct V_2 * V_3 ,
const struct V_466 * V_229 ,
struct V_468 * V_762 ,
struct V_467 * V_467 )
{
struct V_13 * V_14 = F_85 ( V_3 ) ;
T_1 V_230 [ 3 ] = {
[ 0 ] = V_763 | V_764 ,
} ;
struct V_765 args = {
. V_478 = F_93 ( V_3 ) ,
. V_229 = V_229 ,
. V_467 = V_467 ,
. V_230 = V_230 ,
} ;
struct V_766 V_57 = {
. V_762 = V_762 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_767 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
int V_288 ;
F_8 ( L_58 , V_34 ) ;
if ( F_85 ( V_3 ) -> V_15 [ 1 ] & V_768 )
V_230 [ 1 ] |= V_768 ;
else
V_230 [ 0 ] |= V_45 ;
F_81 ( & V_762 -> V_371 ) ;
V_762 -> V_14 = V_14 ;
V_762 -> V_769 = 0 ;
V_288 = F_73 ( V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
F_8 ( L_59 , V_34 , V_288 ) ;
return V_288 ;
}
int F_273 ( struct V_55 * V_91 , struct V_2 * V_3 ,
const struct V_466 * V_229 ,
struct V_468 * V_762 ,
struct V_467 * V_467 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_495 ( V_91 , V_3 , V_229 ,
V_762 , V_467 ) ;
F_496 ( V_3 , V_229 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_497 ( struct V_2 * V_2 ,
struct V_468 * V_469 ,
struct V_467 * V_467 , struct V_298 * V_332 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_55 * V_56 = V_14 -> V_91 ;
T_1 V_230 [ 2 ] = {
[ 0 ] = V_763 | V_764 ,
} ;
struct V_765 args = {
. V_223 = V_14 -> V_63 -> V_224 ,
. V_233 = F_93 ( V_2 ) ,
. V_467 = V_467 ,
. V_230 = V_230 ,
. V_770 = 1 ,
. V_771 = 1 ,
} ;
struct V_766 V_57 = {
. V_762 = V_469 ,
. V_770 = 1 ,
. V_771 = 1 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_767 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
unsigned long V_547 = V_154 ;
int V_288 ;
F_81 ( & V_469 -> V_371 ) ;
V_469 -> V_14 = V_14 ;
V_469 -> V_769 = 0 ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_288 = F_69 ( V_56 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
if ( V_288 )
return V_288 ;
F_37 ( V_14 , V_547 ) ;
return 0 ;
}
static int F_498 ( struct V_2 * V_2 ,
struct V_468 * V_469 ,
struct V_467 * V_467 , struct V_298 * V_332 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_55 * V_56 = V_14 -> V_91 ;
T_1 V_230 [ 2 ] = {
[ 0 ] = V_763 | V_764 ,
} ;
struct V_765 args = {
. V_233 = F_93 ( V_2 ) ,
. V_467 = V_467 ,
. V_230 = V_230 ,
. V_770 = 1 ,
} ;
struct V_766 V_57 = {
. V_762 = V_469 ,
. V_770 = 1 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_767 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
int V_288 ;
F_81 ( & V_469 -> V_371 ) ;
V_469 -> V_14 = V_14 ;
V_469 -> V_769 = 0 ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_288 = F_69 ( V_56 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
if ( V_288 == V_772 &&
V_57 . V_160 . V_145 & V_773 )
V_288 = - V_78 ;
return V_288 ;
}
int F_499 ( struct V_2 * V_2 ,
struct V_468 * V_469 ,
struct V_467 * V_467 , struct V_298 * V_332 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_774 * V_775 =
V_64 -> V_167 -> V_776 ;
struct V_61 V_62 = { } ;
int V_288 ;
F_8 ( L_60 , V_34 ,
( unsigned long long ) V_14 -> V_465 . V_777 ,
( unsigned long long ) V_14 -> V_465 . V_778 ,
V_64 -> V_97 ) ;
F_500 ( F_93 ( V_2 ) , V_34 ) ;
do {
V_288 = V_775 -> V_779 ( V_2 , V_469 , V_467 , V_332 ) ;
if ( V_288 != - V_90 )
break;
F_20 ( V_14 , V_288 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_288 ;
}
static int F_501 ( struct V_2 * V_2 , struct V_298 * V_332 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = F_85 ( V_2 ) -> V_63 ;
struct V_55 * V_56 = V_14 -> V_91 ;
struct V_780 args = {
. V_233 = F_93 ( V_2 ) ,
. V_223 = V_64 -> V_224 ,
. V_771 = 1 ,
} ;
struct V_781 V_57 = {
. V_771 = 1 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_782 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
unsigned long V_547 = V_154 ;
int V_288 ;
V_57 . V_233 = F_502 () ;
if ( V_57 . V_233 == NULL )
return - V_126 ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_288 = F_69 ( V_56 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
F_503 ( V_57 . V_233 ) ;
if ( V_288 )
return V_288 ;
F_33 ( V_64 , V_547 ) ;
return 0 ;
}
static int F_504 ( struct V_2 * V_2 , struct V_298 * V_332 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_55 * V_56 = V_14 -> V_91 ;
struct V_780 args = {
. V_233 = F_93 ( V_2 ) ,
} ;
struct V_781 V_57 = {
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_782 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
int V_288 ;
V_57 . V_233 = F_502 () ;
if ( V_57 . V_233 == NULL )
return - V_126 ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_288 = F_69 ( V_56 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
F_503 ( V_57 . V_233 ) ;
if ( V_288 == V_772 &&
V_57 . V_160 . V_145 & V_773 )
V_288 = - V_78 ;
return V_288 ;
}
int F_505 ( struct V_2 * V_2 , struct V_298 * V_332 )
{
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_63 * V_64 = V_14 -> V_63 ;
const struct V_774 * V_775 =
V_64 -> V_167 -> V_776 ;
struct V_61 V_62 = { } ;
int V_288 ;
F_8 ( L_60 , V_34 ,
( unsigned long long ) V_14 -> V_465 . V_777 ,
( unsigned long long ) V_14 -> V_465 . V_778 ,
V_64 -> V_97 ) ;
F_500 ( F_93 ( V_2 ) , V_34 ) ;
do {
V_288 = V_775 -> V_783 ( V_2 , V_332 ) ;
if ( V_288 != - V_90 )
break;
F_20 ( V_14 , V_288 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_288 ;
}
static int F_506 ( struct V_2 * V_3 , const struct V_466 * V_229 , struct V_784 * V_459 , bool V_785 )
{
int V_288 ;
struct V_786 args = {
. V_478 = F_93 ( V_3 ) ,
. V_229 = V_229 ,
} ;
struct V_787 V_57 = {
. V_459 = V_459 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_788 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
struct V_55 * V_56 = F_85 ( V_3 ) -> V_91 ;
struct V_298 * V_332 = NULL ;
if ( V_785 ) {
V_56 = F_85 ( V_3 ) -> V_63 -> V_101 ;
V_332 = F_507 ( F_85 ( V_3 ) -> V_63 ) ;
V_162 . V_298 = V_332 ;
}
F_8 ( L_61 , V_229 -> V_229 ) ;
F_249 ( F_85 ( V_3 ) -> V_63 ,
V_789 , & V_56 , & V_162 ) ;
V_288 = F_73 ( V_56 , F_85 ( V_3 ) , & V_162 , & args . V_159 ,
& V_57 . V_160 , 0 ) ;
F_8 ( L_62 , V_288 ) ;
if ( V_332 )
F_206 ( V_332 ) ;
return V_288 ;
}
int F_508 ( struct V_2 * V_3 , const struct V_466 * V_229 ,
struct V_784 * V_459 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( F_85 ( V_3 ) -> V_63 ) )
V_8 = F_506 ( V_3 , V_229 , V_459 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_506 ( V_3 , V_229 , V_459 , false ) ;
F_509 ( V_3 , V_229 , V_8 ) ;
V_8 = F_20 ( F_85 ( V_3 ) , V_8 ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static int F_510 ( T_1 V_206 )
{
if ( V_206 & ~ V_790 )
goto V_791;
if ( ( V_206 & V_792 ) &&
( V_206 & V_793 ) )
goto V_791;
if ( ! ( V_206 & ( V_794 ) ) )
goto V_791;
return V_346 ;
V_791:
return - V_795 ;
}
static bool
F_511 ( struct V_796 * V_797 ,
struct V_796 * V_798 )
{
if ( V_797 -> V_799 == V_798 -> V_799 &&
memcmp ( V_797 -> V_800 , V_798 -> V_800 , V_797 -> V_799 ) == 0 )
return true ;
return false ;
}
int F_512 ( struct V_63 * V_64 , struct V_298 * V_332 )
{
int V_288 ;
struct V_801 V_57 ;
struct V_161 V_162 = {
. V_293 =
& V_294 [ V_802 ] ,
. V_296 = V_64 ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
F_8 ( L_11 , V_34 ) ;
V_57 . V_134 = F_86 ( sizeof( struct V_133 ) , V_285 ) ;
if ( F_357 ( V_57 . V_134 == NULL ) ) {
V_288 = - V_126 ;
goto V_131;
}
V_288 = F_381 ( V_64 -> V_101 , & V_162 , V_585 ) ;
F_513 ( V_64 , V_288 ) ;
if ( V_288 == 0 ) {
if ( memcmp ( V_57 . V_134 -> V_803 . V_157 ,
V_64 -> V_87 -> V_803 . V_157 , V_804 ) ) {
F_8 ( L_63 , V_34 ) ;
V_288 = - V_35 ;
goto V_805;
}
if ( V_57 . V_3 != V_806 ) {
F_8 ( L_64 ,
V_34 ) ;
V_288 = - V_35 ;
goto V_805;
}
if ( V_57 . V_807 ) {
F_8 ( L_65 ,
V_34 ) ;
V_288 = - V_35 ;
goto V_805;
}
}
V_805:
F_96 ( V_57 . V_134 ) ;
V_131:
F_8 ( L_66 , V_34 , V_288 ) ;
return V_288 ;
}
static int F_514 ( struct V_63 * V_64 ,
struct V_808 * V_204 )
{
static const T_1 V_809 [ V_810 ] = {
[ 1 ] = 1 << ( V_811 - 32 ) |
1 << ( V_812 - 32 ) |
1 << ( V_813 - 32 ) |
1 << ( V_814 - 32 ) |
1 << ( V_815 - 32 )
} ;
unsigned int V_456 ;
if ( V_204 -> V_816 == V_817 ) {
F_515 ( V_818 , L_67 ) ;
for ( V_456 = 0 ; V_456 <= V_819 ; V_456 ++ ) {
if ( F_31 ( V_456 , V_204 -> V_820 . V_237 . V_821 ) )
F_515 ( V_818 , L_68 , V_456 ) ;
if ( F_31 ( V_456 , V_204 -> V_822 . V_237 . V_821 ) )
F_515 ( V_818 , L_69 , V_456 ) ;
}
for ( V_456 = 0 ; V_456 < V_810 ; V_456 ++ ) {
if ( V_204 -> V_820 . V_237 . V_823 [ V_456 ] & ~ V_809 [ V_456 ] ) {
F_515 ( V_818 , L_70 ) ;
return - V_27 ;
}
}
if ( F_31 ( V_811 , V_204 -> V_820 . V_237 . V_821 ) &&
F_31 ( V_813 , V_204 -> V_820 . V_237 . V_821 ) &&
F_31 ( V_814 , V_204 -> V_820 . V_237 . V_821 ) &&
F_31 ( V_815 , V_204 -> V_820 . V_237 . V_821 ) ) {
F_515 ( V_818 , L_71 ) ;
F_515 ( V_818 , L_72 ) ;
F_129 ( V_824 , & V_64 -> V_825 ) ;
} else {
F_515 ( V_818 , L_70 ) ;
return - V_27 ;
}
if ( F_31 ( V_826 , V_204 -> V_822 . V_237 . V_821 ) &&
F_31 ( V_827 , V_204 -> V_822 . V_237 . V_821 ) ) {
F_515 ( V_818 , L_73 ) ;
F_129 ( V_403 , & V_64 -> V_825 ) ;
}
if ( F_31 ( V_828 , V_204 -> V_822 . V_237 . V_821 ) &&
F_31 ( V_829 , V_204 -> V_822 . V_237 . V_821 ) ) {
F_515 ( V_818 , L_74 ) ;
F_129 ( V_789 , & V_64 -> V_825 ) ;
}
if ( F_31 ( V_830 , V_204 -> V_822 . V_237 . V_821 ) &&
F_31 ( V_831 , V_204 -> V_822 . V_237 . V_821 ) ) {
F_515 ( V_818 , L_75 ) ;
F_129 ( V_832 , & V_64 -> V_825 ) ;
}
if ( F_31 ( V_833 , V_204 -> V_822 . V_237 . V_821 ) ) {
F_515 ( V_818 , L_76 ) ;
F_129 ( V_834 , & V_64 -> V_825 ) ;
}
if ( F_31 ( V_835 , V_204 -> V_822 . V_237 . V_821 ) ) {
F_515 ( V_818 , L_77 ) ;
F_129 ( V_836 , & V_64 -> V_825 ) ;
}
}
return 0 ;
}
static int F_516 ( struct V_63 * V_64 , struct V_298 * V_332 ,
T_1 V_837 )
{
T_12 V_37 ;
struct V_838 args = {
. V_37 = & V_37 ,
. V_91 = V_64 ,
#ifdef F_517
. V_206 = V_839 |
V_840 |
V_841 ,
#else
. V_206 = V_839 |
V_840 ,
#endif
} ;
struct V_842 V_57 = {
0
} ;
int V_288 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_843 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
F_413 ( V_64 , & V_37 ) ;
args . V_844 = F_421 ( V_64 , args . V_225 ,
sizeof( args . V_225 ) ) ;
F_8 ( L_78 ,
V_64 -> V_101 -> V_102 -> V_670 -> V_671 ,
args . V_844 , args . V_225 ) ;
V_57 . V_845 = F_86 ( sizeof( struct V_846 ) ,
V_285 ) ;
if ( F_357 ( V_57 . V_845 == NULL ) ) {
V_288 = - V_126 ;
goto V_131;
}
V_57 . V_800 = F_86 ( sizeof( struct V_796 ) ,
V_285 ) ;
if ( F_357 ( V_57 . V_800 == NULL ) ) {
V_288 = - V_126 ;
goto V_847;
}
V_57 . V_848 = F_86 ( sizeof( struct V_849 ) , V_285 ) ;
if ( F_357 ( V_57 . V_848 == NULL ) ) {
V_288 = - V_126 ;
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
F_518 ( 1 ) ;
V_288 = - V_27 ;
goto V_850;
}
V_288 = F_381 ( V_64 -> V_101 , & V_162 , V_585 ) ;
F_519 ( V_64 , V_288 ) ;
if ( V_288 == 0 )
V_288 = F_510 ( V_57 . V_206 ) ;
if ( V_288 == 0 )
V_288 = F_514 ( V_64 , & V_57 . V_852 ) ;
if ( V_288 == 0 ) {
V_64 -> V_224 = V_57 . V_223 ;
V_64 -> V_854 = ( V_57 . V_206 & ~ V_855 ) ;
if ( ! ( V_57 . V_206 & V_855 ) )
V_64 -> V_856 = V_57 . V_195 ;
F_96 ( V_64 -> V_857 ) ;
V_64 -> V_857 = V_57 . V_845 ;
V_57 . V_845 = NULL ;
F_96 ( V_64 -> V_858 ) ;
V_64 -> V_858 = V_57 . V_848 ;
if ( V_64 -> V_859 != NULL &&
! F_511 ( V_64 -> V_859 ,
V_57 . V_800 ) ) {
F_8 ( L_79 ,
V_34 ) ;
F_129 ( V_860 , & V_64 -> V_626 ) ;
F_96 ( V_64 -> V_859 ) ;
V_64 -> V_859 = NULL ;
}
if ( V_64 -> V_859 == NULL ) {
V_64 -> V_859 = V_57 . V_800 ;
goto V_131;
}
} else
F_96 ( V_57 . V_848 ) ;
V_847:
F_96 ( V_57 . V_845 ) ;
V_850:
F_96 ( V_57 . V_800 ) ;
V_131:
if ( V_64 -> V_858 != NULL )
F_8 ( L_80
L_81 ,
V_64 -> V_858 -> V_861 , V_64 -> V_858 -> V_229 ,
V_64 -> V_858 -> V_862 . V_863 ,
V_64 -> V_858 -> V_862 . V_864 ) ;
F_8 ( L_82 , V_288 ) ;
return V_288 ;
}
int F_520 ( struct V_63 * V_64 , struct V_298 * V_332 )
{
T_4 V_865 = V_64 -> V_101 -> V_102 -> V_103 ;
int V_288 ;
if ( V_865 == V_104 ||
V_865 == V_105 ) {
V_288 = F_516 ( V_64 , V_332 , V_817 ) ;
if ( ! V_288 )
return 0 ;
}
return F_516 ( V_64 , V_332 , V_851 ) ;
}
static int F_521 ( struct V_63 * V_64 ,
struct V_298 * V_332 )
{
struct V_161 V_162 = {
. V_293 = & V_294 [ V_866 ] ,
. V_296 = V_64 ,
. V_298 = V_332 ,
} ;
int V_288 ;
V_288 = F_381 ( V_64 -> V_101 , & V_162 , V_585 ) ;
F_522 ( V_64 , V_288 ) ;
if ( V_288 )
F_8 ( L_83
L_84 , V_288 , V_64 -> V_97 ) ;
return V_288 ;
}
static int F_523 ( struct V_63 * V_64 ,
struct V_298 * V_332 )
{
unsigned int V_867 ;
int V_52 ;
for ( V_867 = V_868 ; V_867 != 0 ; V_867 -- ) {
V_52 = F_521 ( V_64 , V_332 ) ;
switch ( V_52 ) {
case - V_90 :
case - V_869 :
F_167 ( 1 ) ;
break;
default:
return V_52 ;
}
}
return 0 ;
}
int F_524 ( struct V_63 * V_64 )
{
struct V_298 * V_332 ;
int V_52 = 0 ;
if ( V_64 -> V_167 -> V_314 < 1 )
goto V_131;
if ( V_64 -> V_854 == 0 )
goto V_131;
if ( V_64 -> V_870 )
goto V_131;
V_332 = F_507 ( V_64 ) ;
V_52 = F_523 ( V_64 , V_332 ) ;
if ( V_332 )
F_206 ( V_332 ) ;
switch ( V_52 ) {
case 0 :
case - V_76 :
V_64 -> V_854 = 0 ;
}
V_131:
return V_52 ;
}
static void F_525 ( struct V_116 * V_117 ,
void * V_155 )
{
struct V_871 * V_157 =
(struct V_871 * ) V_155 ;
F_8 ( L_11 , V_34 ) ;
F_61 ( V_157 -> V_64 -> V_87 ,
& V_157 -> args -> V_872 ,
& V_157 -> V_57 -> V_873 ,
V_117 ) ;
F_8 ( L_85 , V_34 ) ;
}
static void F_526 ( struct V_116 * V_117 , void * V_155 )
{
struct V_871 * V_157 =
(struct V_871 * ) V_155 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_53 ( V_117 , & V_157 -> V_57 -> V_873 ) )
return;
switch ( V_117 -> V_149 ) {
case - V_90 :
case - V_89 :
F_8 ( L_86 , V_34 , V_117 -> V_149 ) ;
F_59 ( V_117 , V_54 ) ;
V_117 -> V_149 = 0 ;
case - V_92 :
F_57 ( V_117 ) ;
return;
}
F_8 ( L_85 , V_34 ) ;
}
int F_527 ( struct V_63 * V_64 , struct V_442 * V_543 )
{
struct V_116 * V_117 ;
struct V_874 args ;
struct V_875 V_57 = {
. V_876 = V_543 ,
} ;
struct V_871 V_157 = {
. args = & args ,
. V_57 = & V_57 ,
. V_64 = V_64 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_877 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
struct V_163 V_164 = {
. V_165 = V_64 -> V_101 ,
. V_161 = & V_162 ,
. V_166 = & V_878 ,
. V_169 = & V_157 ,
. V_206 = V_585 ,
} ;
int V_288 ;
F_38 ( & args . V_872 , & V_57 . V_873 , 0 ) ;
F_39 ( & args . V_872 ) ;
F_8 ( L_11 , V_34 ) ;
V_117 = F_70 ( & V_164 ) ;
if ( F_43 ( V_117 ) )
V_288 = F_71 ( V_117 ) ;
else {
V_288 = V_117 -> V_149 ;
F_72 ( V_117 ) ;
}
F_8 ( L_87 , V_34 , V_288 ) ;
return V_288 ;
}
static void F_528 ( struct V_879 * args )
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
V_34 ,
args -> V_885 . V_880 , args -> V_885 . V_881 ,
args -> V_885 . V_886 , args -> V_885 . V_888 ) ;
args -> V_890 . V_880 = V_592 ;
args -> V_890 . V_881 = V_592 ;
args -> V_890 . V_891 = 0 ;
args -> V_890 . V_886 = V_892 ;
args -> V_890 . V_888 = 1 ;
F_8 ( L_90
L_91 ,
V_34 ,
args -> V_890 . V_880 , args -> V_890 . V_881 ,
args -> V_890 . V_891 , args -> V_890 . V_886 ,
args -> V_890 . V_888 ) ;
}
static int F_529 ( struct V_879 * args , struct V_133 * V_134 )
{
struct V_893 * V_894 = & args -> V_885 ;
struct V_893 * V_895 = & V_134 -> V_885 ;
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
static int F_530 ( struct V_879 * args , struct V_133 * V_134 )
{
struct V_893 * V_894 = & args -> V_890 ;
struct V_893 * V_895 = & V_134 -> V_890 ;
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
static int F_531 ( struct V_879 * args ,
struct V_133 * V_134 )
{
int V_52 ;
V_52 = F_529 ( args , V_134 ) ;
if ( V_52 )
return V_52 ;
return F_530 ( args , V_134 ) ;
}
static int F_532 ( struct V_63 * V_64 ,
struct V_298 * V_332 )
{
struct V_133 * V_134 = V_64 -> V_87 ;
struct V_879 args = {
. V_91 = V_64 ,
. V_897 = V_898 ,
} ;
struct V_899 V_57 = {
. V_91 = V_64 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_900 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
int V_288 ;
F_528 ( & args ) ;
args . V_206 = ( V_901 | V_902 ) ;
V_288 = F_381 ( V_134 -> V_64 -> V_101 , & V_162 , V_585 ) ;
F_533 ( V_64 , V_288 ) ;
if ( ! V_288 ) {
V_288 = F_531 ( & args , V_134 ) ;
V_64 -> V_856 ++ ;
}
return V_288 ;
}
int F_534 ( struct V_63 * V_64 , struct V_298 * V_332 )
{
int V_288 ;
unsigned * V_903 ;
struct V_133 * V_134 = V_64 -> V_87 ;
F_8 ( L_92 , V_34 , V_64 , V_134 ) ;
V_288 = F_532 ( V_64 , V_332 ) ;
if ( V_288 )
goto V_131;
V_288 = F_535 ( V_134 ) ;
F_8 ( L_93 , V_288 ) ;
if ( V_288 )
goto V_131;
V_903 = ( unsigned * ) & V_134 -> V_803 . V_157 [ 0 ] ;
F_8 ( L_94 , V_34 ,
V_64 -> V_856 , V_903 [ 0 ] , V_903 [ 1 ] , V_903 [ 2 ] , V_903 [ 3 ] ) ;
V_131:
F_8 ( L_85 , V_34 ) ;
return V_288 ;
}
int F_536 ( struct V_133 * V_134 ,
struct V_298 * V_332 )
{
struct V_161 V_162 = {
. V_293 = & V_294 [ V_904 ] ,
. V_296 = V_134 ,
. V_298 = V_332 ,
} ;
int V_288 = 0 ;
F_8 ( L_95 ) ;
if ( V_134 -> V_64 -> V_905 != V_906 )
return V_288 ;
V_288 = F_381 ( V_134 -> V_64 -> V_101 , & V_162 , V_585 ) ;
F_537 ( V_134 -> V_64 , V_288 ) ;
if ( V_288 )
F_8 ( L_96
L_97 , V_288 ) ;
F_8 ( L_98 ) ;
return V_288 ;
}
static void F_538 ( void * V_157 )
{
struct V_907 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
if ( F_371 ( & V_64 -> V_579 ) > 1 )
F_372 ( V_64 ) ;
F_373 ( V_64 ) ;
F_96 ( V_155 ) ;
}
static int F_539 ( struct V_116 * V_117 , struct V_63 * V_64 )
{
switch( V_117 -> V_149 ) {
case - V_90 :
F_59 ( V_117 , V_53 ) ;
return - V_130 ;
default:
F_24 ( V_64 ) ;
}
return 0 ;
}
static void F_540 ( struct V_116 * V_117 , void * V_157 )
{
struct V_907 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
if ( ! F_53 ( V_117 , V_117 -> V_308 . V_297 ) )
return;
F_541 ( V_64 , V_117 -> V_149 ) ;
if ( V_117 -> V_149 < 0 ) {
F_8 ( L_99 , V_34 , V_117 -> V_149 ) ;
if ( F_371 ( & V_64 -> V_579 ) == 1 )
goto V_131;
if ( F_539 ( V_117 , V_64 ) == - V_130 ) {
F_57 ( V_117 ) ;
return;
}
}
F_8 ( L_100 , V_34 , V_117 -> V_308 . V_298 ) ;
V_131:
F_8 ( L_85 , V_34 ) ;
}
static void F_542 ( struct V_116 * V_117 , void * V_157 )
{
struct V_907 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
struct V_109 * args ;
struct V_110 * V_57 ;
args = V_117 -> V_308 . V_296 ;
V_57 = V_117 -> V_308 . V_297 ;
F_61 ( V_64 -> V_87 , args , V_57 , V_117 ) ;
}
static struct V_116 * F_543 ( struct V_63 * V_64 ,
struct V_298 * V_332 ,
bool V_908 )
{
struct V_907 * V_155 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_909 ] ,
. V_298 = V_332 ,
} ;
struct V_163 V_299 = {
. V_165 = V_64 -> V_101 ,
. V_161 = & V_162 ,
. V_166 = & V_910 ,
. V_206 = V_303 | V_585 ,
} ;
if ( ! F_378 ( & V_64 -> V_579 ) )
return F_44 ( - V_35 ) ;
V_155 = F_86 ( sizeof( * V_155 ) , V_285 ) ;
if ( V_155 == NULL ) {
F_373 ( V_64 ) ;
return F_44 ( - V_126 ) ;
}
F_38 ( & V_155 -> args , & V_155 -> V_57 , 0 ) ;
if ( V_908 )
F_39 ( & V_155 -> args ) ;
V_162 . V_296 = & V_155 -> args ;
V_162 . V_297 = & V_155 -> V_57 ;
V_155 -> V_64 = V_64 ;
V_299 . V_169 = V_155 ;
return F_70 ( & V_299 ) ;
}
static int F_544 ( struct V_63 * V_64 , struct V_298 * V_332 , unsigned V_583 )
{
struct V_116 * V_117 ;
int V_52 = 0 ;
if ( ( V_583 & V_911 ) == 0 )
return - V_130 ;
V_117 = F_543 ( V_64 , V_332 , false ) ;
if ( F_43 ( V_117 ) )
V_52 = F_71 ( V_117 ) ;
else
F_462 ( V_117 ) ;
F_8 ( L_16 , V_34 , V_52 ) ;
return V_52 ;
}
static int F_545 ( struct V_63 * V_64 , struct V_298 * V_332 )
{
struct V_116 * V_117 ;
int V_52 ;
V_117 = F_543 ( V_64 , V_332 , true ) ;
if ( F_43 ( V_117 ) ) {
V_52 = F_71 ( V_117 ) ;
goto V_131;
}
V_52 = F_108 ( V_117 ) ;
if ( ! V_52 ) {
struct V_110 * V_57 = V_117 -> V_308 . V_297 ;
if ( V_117 -> V_149 == 0 )
F_546 ( V_64 , V_57 -> V_145 ) ;
V_52 = V_117 -> V_149 ;
}
F_72 ( V_117 ) ;
V_131:
F_8 ( L_16 , V_34 , V_52 ) ;
return V_52 ;
}
static void F_547 ( struct V_116 * V_117 , void * V_157 )
{
struct V_912 * V_155 = V_157 ;
F_61 ( V_155 -> V_64 -> V_87 ,
& V_155 -> V_374 . V_159 ,
& V_155 -> V_57 . V_160 ,
V_117 ) ;
}
static int F_548 ( struct V_116 * V_117 , struct V_63 * V_64 )
{
switch( V_117 -> V_149 ) {
case 0 :
case - V_913 :
case - V_23 :
break;
case - V_90 :
F_59 ( V_117 , V_53 ) ;
case - V_92 :
return - V_130 ;
default:
F_24 ( V_64 ) ;
}
return 0 ;
}
static void F_549 ( struct V_116 * V_117 , void * V_157 )
{
struct V_912 * V_155 = V_157 ;
struct V_63 * V_64 = V_155 -> V_64 ;
struct V_110 * V_57 = & V_155 -> V_57 . V_160 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_53 ( V_117 , V_57 ) )
return;
F_550 ( V_64 , V_117 -> V_149 ) ;
if ( F_548 ( V_117 , V_64 ) == - V_130 ) {
F_57 ( V_117 ) ;
return;
}
F_8 ( L_85 , V_34 ) ;
}
static void F_551 ( void * V_157 )
{
struct V_912 * V_155 = V_157 ;
F_96 ( V_155 ) ;
}
static int F_552 ( struct V_63 * V_64 ,
struct V_298 * V_332 )
{
struct V_912 * V_155 ;
struct V_116 * V_117 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_914 ] ,
. V_298 = V_332 ,
} ;
struct V_163 V_299 = {
. V_165 = V_64 -> V_101 ,
. V_161 = & V_162 ,
. V_166 = & V_915 ,
. V_206 = V_303 ,
} ;
int V_288 = - V_126 ;
F_8 ( L_11 , V_34 ) ;
V_155 = F_86 ( sizeof( * V_155 ) , V_285 ) ;
if ( V_155 == NULL )
goto V_131;
V_155 -> V_64 = V_64 ;
V_155 -> V_374 . V_916 = 0 ;
F_38 ( & V_155 -> V_374 . V_159 , & V_155 -> V_57 . V_160 , 0 ) ;
F_39 ( & V_155 -> V_374 . V_159 ) ;
V_162 . V_296 = & V_155 -> V_374 ;
V_162 . V_297 = & V_155 -> V_57 ;
V_299 . V_169 = V_155 ;
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) ) {
V_288 = F_71 ( V_117 ) ;
goto V_131;
}
V_288 = F_107 ( V_117 ) ;
if ( V_288 == 0 )
V_288 = V_117 -> V_149 ;
F_72 ( V_117 ) ;
return 0 ;
V_131:
F_8 ( L_16 , V_34 , V_288 ) ;
return V_288 ;
}
static void
F_553 ( struct V_116 * V_117 , void * V_155 )
{
struct V_917 * V_918 = V_155 ;
struct V_13 * V_14 = F_85 ( V_918 -> args . V_2 ) ;
struct V_133 * V_134 = F_64 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
if ( F_61 ( V_134 , & V_918 -> args . V_159 ,
& V_918 -> V_57 . V_160 , V_117 ) )
return;
if ( F_554 ( & V_918 -> args . V_239 ,
F_75 ( V_918 -> args . V_2 ) -> V_919 ,
V_918 -> args . V_283 -> V_66 ) ) {
F_555 ( V_117 , V_772 ) ;
}
}
static void F_556 ( struct V_116 * V_117 , void * V_155 )
{
struct V_917 * V_918 = V_155 ;
struct V_2 * V_2 = V_918 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
struct V_920 * V_921 ;
struct V_65 * V_66 = NULL ;
unsigned long V_922 , V_547 , V_923 ;
F_8 ( L_101 , V_34 , - V_117 -> V_149 ) ;
if ( ! F_53 ( V_117 , & V_918 -> V_57 . V_160 ) )
goto V_131;
switch ( V_117 -> V_149 ) {
case 0 :
goto V_131;
case - V_19 :
case - V_20 :
V_922 = F_557 ( V_117 -> V_924 ) ;
V_923 = V_918 -> args . V_106 + V_922 ;
V_547 = V_154 ;
if ( F_558 ( V_923 , V_547 ) ) {
unsigned long V_925 ;
V_925 = F_559 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_102 ,
V_34 , V_925 ) ;
F_59 ( V_117 , V_925 ) ;
V_117 -> V_149 = 0 ;
F_57 ( V_117 ) ;
goto V_131;
}
break;
case - V_74 :
case - V_73 :
F_34 ( & V_2 -> V_174 ) ;
V_921 = F_75 ( V_2 ) -> V_919 ;
if ( ! V_921 || F_434 ( & V_921 -> V_926 ) ) {
F_36 ( & V_2 -> V_174 ) ;
V_66 = V_918 -> args . V_283 -> V_66 ;
} else {
F_560 ( V_927 ) ;
F_561 ( V_921 , & V_927 , NULL ) ;
F_36 ( & V_2 -> V_174 ) ;
F_562 ( & V_927 ) ;
V_117 -> V_149 = 0 ;
F_57 ( V_117 ) ;
}
}
if ( F_241 ( V_117 , V_14 , V_66 , NULL ) == - V_130 )
F_57 ( V_117 ) ;
V_131:
F_8 ( L_85 , V_34 ) ;
}
static T_9 F_563 ( struct V_13 * V_14 )
{
T_1 V_881 = V_14 -> V_63 -> V_87 -> V_885 . V_881 ;
return F_564 ( 0 , V_881 ) ;
}
static void F_565 ( struct V_467 * * V_42 , T_9 V_928 )
{
int V_456 ;
if ( ! V_42 )
return;
for ( V_456 = 0 ; V_456 < V_928 ; V_456 ++ ) {
if ( ! V_42 [ V_456 ] )
break;
F_275 ( V_42 [ V_456 ] ) ;
}
F_96 ( V_42 ) ;
}
static struct V_467 * * F_566 ( T_9 V_928 , T_6 V_929 )
{
struct V_467 * * V_42 ;
int V_456 ;
V_42 = F_567 ( V_928 , sizeof( struct V_467 * ) , V_929 ) ;
if ( ! V_42 ) {
F_8 ( L_103 , V_34 , V_928 ) ;
return NULL ;
}
for ( V_456 = 0 ; V_456 < V_928 ; V_456 ++ ) {
V_42 [ V_456 ] = F_271 ( V_929 ) ;
if ( ! V_42 [ V_456 ] ) {
F_8 ( L_104 , V_34 ) ;
F_565 ( V_42 , V_928 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_568 ( void * V_155 )
{
struct V_917 * V_918 = V_155 ;
struct V_2 * V_2 = V_918 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_930 = F_563 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_565 ( V_918 -> args . V_919 . V_42 , V_930 ) ;
F_569 ( F_75 ( V_2 ) -> V_919 ) ;
F_164 ( V_918 -> args . V_283 ) ;
F_96 ( V_155 ) ;
F_8 ( L_85 , V_34 ) ;
}
struct V_931 *
F_570 ( struct V_917 * V_918 , T_6 V_929 )
{
struct V_2 * V_2 = V_918 -> args . V_2 ;
struct V_13 * V_14 = F_85 ( V_2 ) ;
T_9 V_930 = F_563 ( V_14 ) ;
struct V_116 * V_117 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_932 ] ,
. V_296 = & V_918 -> args ,
. V_297 = & V_918 -> V_57 ,
. V_298 = V_918 -> V_332 ,
} ;
struct V_163 V_299 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_933 ,
. V_169 = V_918 ,
. V_206 = V_303 ,
} ;
struct V_931 * V_934 = NULL ;
int V_288 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_571 ( F_75 ( V_2 ) -> V_919 ) ;
V_918 -> args . V_919 . V_42 = F_566 ( V_930 , V_929 ) ;
if ( ! V_918 -> args . V_919 . V_42 ) {
F_568 ( V_918 ) ;
return F_44 ( - V_126 ) ;
}
V_918 -> args . V_919 . V_494 = V_930 * V_592 ;
V_918 -> args . V_106 = V_154 ;
V_918 -> V_57 . V_935 = & V_918 -> args . V_919 ;
V_918 -> V_57 . V_160 . V_115 = NULL ;
F_38 ( & V_918 -> args . V_159 , & V_918 -> V_57 . V_160 , 0 ) ;
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) )
return F_251 ( V_117 ) ;
V_288 = F_107 ( V_117 ) ;
if ( V_288 == 0 )
V_288 = V_117 -> V_149 ;
F_572 ( V_918 -> args . V_283 ,
& V_918 -> args . V_936 ,
& V_918 -> V_57 . V_936 ,
V_288 ) ;
if ( V_288 == 0 && V_918 -> V_57 . V_935 -> V_12 )
V_934 = F_573 ( V_918 ) ;
F_72 ( V_117 ) ;
F_8 ( L_16 , V_34 , V_288 ) ;
if ( V_288 )
return F_44 ( V_288 ) ;
return V_934 ;
}
static void
F_574 ( struct V_116 * V_117 , void * V_155 )
{
struct V_937 * V_938 = V_155 ;
F_8 ( L_11 , V_34 ) ;
F_61 ( V_938 -> V_64 -> V_87 ,
& V_938 -> args . V_159 ,
& V_938 -> V_57 . V_160 ,
V_117 ) ;
}
static void F_575 ( struct V_116 * V_117 , void * V_155 )
{
struct V_937 * V_938 = V_155 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_53 ( V_117 , & V_938 -> V_57 . V_160 ) )
return;
V_14 = F_85 ( V_938 -> args . V_2 ) ;
switch ( V_117 -> V_149 ) {
default:
V_117 -> V_149 = 0 ;
case 0 :
break;
case - V_90 :
if ( F_241 ( V_117 , V_14 , NULL , NULL ) != - V_130 )
break;
F_57 ( V_117 ) ;
return;
}
F_8 ( L_85 , V_34 ) ;
}
static void F_576 ( void * V_155 )
{
struct V_937 * V_938 = V_155 ;
struct V_920 * V_921 = V_938 -> args . V_919 ;
F_8 ( L_11 , V_34 ) ;
F_34 ( & V_921 -> V_939 -> V_174 ) ;
if ( V_938 -> V_57 . V_940 )
F_577 ( V_921 , & V_938 -> V_57 . V_239 , true ) ;
V_921 -> V_941 -- ;
F_36 ( & V_921 -> V_939 -> V_174 ) ;
F_569 ( V_938 -> args . V_919 ) ;
F_96 ( V_155 ) ;
F_8 ( L_85 , V_34 ) ;
}
int F_578 ( struct V_937 * V_938 )
{
struct V_116 * V_117 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_942 ] ,
. V_296 = & V_938 -> args ,
. V_297 = & V_938 -> V_57 ,
. V_298 = V_938 -> V_332 ,
} ;
struct V_163 V_299 = {
. V_165 = F_85 ( V_938 -> args . V_2 ) -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_943 ,
. V_169 = V_938 ,
} ;
int V_288 ;
F_8 ( L_11 , V_34 ) ;
F_38 ( & V_938 -> args . V_159 , & V_938 -> V_57 . V_160 , 1 ) ;
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) )
return F_71 ( V_117 ) ;
V_288 = V_117 -> V_149 ;
F_579 ( V_938 -> args . V_2 , V_288 ) ;
F_8 ( L_16 , V_34 , V_288 ) ;
F_72 ( V_117 ) ;
return V_288 ;
}
static int
F_580 ( struct V_13 * V_14 ,
struct V_944 * V_945 ,
struct V_298 * V_332 )
{
struct V_946 args = {
. V_945 = V_945 ,
} ;
struct V_947 V_57 = {
. V_945 = V_945 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_948 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
int V_288 ;
F_8 ( L_11 , V_34 ) ;
V_288 = F_73 ( V_14 -> V_91 , V_14 , & V_162 , & args . V_159 , & V_57 . V_160 , 0 ) ;
F_8 ( L_16 , V_34 , V_288 ) ;
return V_288 ;
}
int F_581 ( struct V_13 * V_14 ,
struct V_944 * V_945 ,
struct V_298 * V_332 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_14 ,
F_580 ( V_14 , V_945 , V_332 ) ,
& V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static void F_582 ( struct V_116 * V_117 , void * V_155 )
{
struct V_949 * V_157 = V_155 ;
struct V_13 * V_14 = F_85 ( V_157 -> args . V_2 ) ;
struct V_133 * V_134 = F_64 ( V_14 ) ;
F_61 ( V_134 ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_117 ) ;
}
static void
F_583 ( struct V_116 * V_117 , void * V_155 )
{
struct V_949 * V_157 = V_155 ;
struct V_13 * V_14 = F_85 ( V_157 -> args . V_2 ) ;
if ( ! F_53 ( V_117 , & V_157 -> V_57 . V_160 ) )
return;
switch ( V_117 -> V_149 ) {
case - V_71 :
case - V_950 :
case - V_951 :
case - V_89 :
V_117 -> V_149 = 0 ;
case 0 :
break;
default:
if ( F_241 ( V_117 , V_14 , NULL , NULL ) == - V_130 ) {
F_57 ( V_117 ) ;
return;
}
}
}
static void F_584 ( void * V_155 )
{
struct V_949 * V_157 = V_155 ;
F_585 ( V_157 ) ;
F_360 ( V_157 -> args . V_2 ,
V_157 -> V_57 . V_371 ) ;
F_206 ( V_157 -> V_332 ) ;
F_96 ( V_157 ) ;
}
int
F_586 ( struct V_949 * V_157 , bool V_952 )
{
struct V_161 V_162 = {
. V_293 = & V_294 [ V_953 ] ,
. V_296 = & V_157 -> args ,
. V_297 = & V_157 -> V_57 ,
. V_298 = V_157 -> V_332 ,
} ;
struct V_163 V_299 = {
. V_117 = & V_157 -> V_117 ,
. V_165 = F_290 ( V_157 -> args . V_2 ) ,
. V_161 = & V_162 ,
. V_166 = & V_954 ,
. V_169 = V_157 ,
. V_206 = V_303 ,
} ;
struct V_116 * V_117 ;
int V_288 = 0 ;
F_8 ( L_105
L_106 ,
V_157 -> V_117 . V_955 , V_952 ,
V_157 -> args . V_956 ,
V_157 -> args . V_2 -> V_957 ) ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 1 ) ;
V_117 = F_70 ( & V_299 ) ;
if ( F_43 ( V_117 ) )
return F_71 ( V_117 ) ;
if ( V_952 == false )
goto V_131;
V_288 = F_107 ( V_117 ) ;
if ( V_288 != 0 )
goto V_131;
V_288 = V_117 -> V_149 ;
F_587 ( V_157 -> args . V_2 , V_288 ) ;
V_131:
F_8 ( L_107 , V_34 , V_288 ) ;
F_72 ( V_117 ) ;
return V_288 ;
}
static int
F_588 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_443 ,
struct V_784 * V_459 , bool V_785 )
{
struct V_958 args = {
. V_959 = V_960 ,
} ;
struct V_787 V_57 = {
. V_459 = V_459 ,
} ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_961 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
} ;
struct V_55 * V_56 = V_14 -> V_91 ;
struct V_298 * V_332 = NULL ;
int V_288 ;
if ( V_785 ) {
V_56 = V_14 -> V_63 -> V_101 ;
V_332 = F_507 ( V_14 -> V_63 ) ;
V_162 . V_298 = V_332 ;
}
F_8 ( L_11 , V_34 ) ;
V_288 = F_73 ( V_56 , V_14 , & V_162 , & args . V_159 ,
& V_57 . V_160 , 0 ) ;
F_8 ( L_16 , V_34 , V_288 ) ;
if ( V_332 )
F_206 ( V_332 ) ;
return V_288 ;
}
static int
F_589 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_443 , struct V_784 * V_459 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_32 ( V_14 -> V_63 ) )
V_8 = F_588 ( V_14 , V_409 , V_443 ,
V_459 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_588 ( V_14 , V_409 , V_443 ,
V_459 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_962 :
goto V_131;
default:
V_8 = F_20 ( V_14 , V_8 , & V_62 ) ;
}
} while ( V_62 . V_67 );
V_131:
return V_8 ;
}
static int
F_590 ( struct V_13 * V_14 , struct V_408 * V_409 ,
struct V_442 * V_443 )
{
int V_8 ;
struct V_467 * V_467 ;
T_4 V_100 = V_963 ;
struct V_784 * V_459 ;
struct V_964 * V_965 ;
int V_456 ;
V_467 = F_271 ( V_362 ) ;
if ( ! V_467 ) {
V_8 = - V_126 ;
goto V_131;
}
V_459 = F_385 ( V_467 ) ;
V_8 = F_589 ( V_14 , V_409 , V_443 , V_459 ) ;
if ( V_8 == - V_22 || V_8 == - V_962 ) {
V_8 = F_262 ( V_14 , V_409 , V_443 ) ;
goto V_966;
}
if ( V_8 )
goto V_966;
for ( V_456 = 0 ; V_456 < V_459 -> V_967 ; V_456 ++ ) {
V_965 = & V_459 -> V_459 [ V_456 ] ;
switch ( V_965 -> V_100 ) {
case V_455 :
case V_454 :
case V_968 :
V_100 = F_591 ( V_965 -> V_100 ,
& V_965 -> V_969 ) ;
break;
default:
V_100 = V_963 ;
break;
}
if ( ! F_592 ( & V_14 -> V_457 , V_100 ) )
V_100 = V_963 ;
if ( V_100 != V_963 ) {
V_8 = F_260 ( V_14 , V_409 ,
V_443 , V_100 ) ;
if ( ! V_8 )
break;
}
}
if ( V_100 == V_963 )
V_8 = - V_24 ;
V_966:
F_399 ( V_467 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_131:
return V_8 ;
}
static int F_593 ( struct V_13 * V_14 ,
T_8 * V_239 ,
struct V_298 * V_332 )
{
int V_288 ;
struct V_970 args = {
. V_239 = V_239 ,
} ;
struct V_971 V_57 ;
struct V_161 V_162 = {
. V_293 = & V_294 [ V_972 ] ,
. V_296 = & args ,
. V_297 = & V_57 ,
. V_298 = V_332 ,
} ;
struct V_55 * V_165 = V_14 -> V_91 ;
F_249 ( V_14 -> V_63 , V_832 ,
& V_165 , & V_162 ) ;
F_8 ( L_108 , V_239 ) ;
F_38 ( & args . V_159 , & V_57 . V_160 , 0 ) ;
F_39 ( & args . V_159 ) ;
V_288 = F_69 ( V_165 , V_14 , & V_162 ,
& args . V_159 , & V_57 . V_160 ) ;
if ( V_288 != V_346 ) {
F_8 ( L_109 , V_288 ) ;
return V_288 ;
}
F_8 ( L_110 , - V_57 . V_288 ) ;
return - V_57 . V_288 ;
}
static int F_203 ( struct V_13 * V_14 ,
T_8 * V_239 ,
struct V_298 * V_332 )
{
struct V_61 V_62 = { } ;
int V_8 ;
do {
V_8 = F_593 ( V_14 , V_239 , V_332 ) ;
if ( V_8 != - V_90 )
break;
F_20 ( V_14 , V_8 , & V_62 ) ;
} while ( V_62 . V_67 );
return V_8 ;
}
static void F_594 ( struct V_116 * V_117 , void * V_155 )
{
struct V_973 * V_157 = V_155 ;
F_61 ( F_64 ( V_157 -> V_14 ) ,
& V_157 -> args . V_159 ,
& V_157 -> V_57 . V_160 ,
V_117 ) ;
}
static void F_595 ( struct V_116 * V_117 , void * V_155 )
{
struct V_973 * V_157 = V_155 ;
F_53 ( V_117 , & V_157 -> V_57 . V_160 ) ;
switch ( V_117 -> V_149 ) {
case - V_90 :
if ( F_241 ( V_117 , V_157 -> V_14 , NULL , NULL ) == - V_130 )
F_57 ( V_117 ) ;
}
}
static void F_596 ( void * V_155 )
{
F_96 ( V_155 ) ;
}
static struct V_116 * F_597 ( struct V_13 * V_14 ,
T_8 * V_239 ,
struct V_298 * V_332 ,
bool V_974 )
{
struct V_161 V_162 = {
. V_293 = & V_294 [ V_975 ] ,
. V_298 = V_332 ,
} ;
struct V_163 V_164 = {
. V_165 = V_14 -> V_91 ,
. V_161 = & V_162 ,
. V_166 = & V_976 ,
. V_206 = V_303 ,
} ;
struct V_973 * V_157 ;
F_249 ( V_14 -> V_63 , V_832 ,
& V_164 . V_165 , & V_162 ) ;
F_8 ( L_111 , V_239 ) ;
V_157 = F_272 ( sizeof( * V_157 ) , V_285 ) ;
if ( ! V_157 )
return F_44 ( - V_126 ) ;
V_157 -> V_14 = V_14 ;
F_123 ( & V_157 -> args . V_239 , V_239 ) ;
V_164 . V_169 = V_157 ;
V_162 . V_296 = & V_157 -> args ;
V_162 . V_297 = & V_157 -> V_57 ;
F_38 ( & V_157 -> args . V_159 , & V_157 -> V_57 . V_160 , 0 ) ;
if ( V_974 )
F_39 ( & V_157 -> args . V_159 ) ;
return F_70 ( & V_164 ) ;
}
static int F_205 ( struct V_13 * V_14 ,
T_8 * V_239 ,
struct V_298 * V_332 )
{
struct V_116 * V_117 ;
int V_52 ;
V_117 = F_597 ( V_14 , V_239 , V_332 , true ) ;
if ( F_43 ( V_117 ) )
return F_71 ( V_117 ) ;
V_52 = F_108 ( V_117 ) ;
if ( ! V_52 )
V_52 = V_117 -> V_149 ;
F_72 ( V_117 ) ;
return V_52 ;
}
static void
F_598 ( struct V_13 * V_14 , struct V_689 * V_690 )
{
struct V_116 * V_117 ;
struct V_298 * V_332 = V_690 -> V_706 -> V_214 -> V_272 ;
V_117 = F_597 ( V_14 , & V_690 -> V_707 , V_332 , false ) ;
F_484 ( V_14 , V_690 ) ;
if ( F_43 ( V_117 ) )
return;
F_72 ( V_117 ) ;
}
static bool F_599 ( const T_8 * V_977 ,
const T_8 * V_978 )
{
if ( memcmp ( V_977 -> V_979 , V_978 -> V_979 , sizeof( V_977 -> V_979 ) ) != 0 )
return false ;
if ( V_977 -> V_195 == V_978 -> V_195 )
return true ;
if ( V_977 -> V_195 == 0 || V_978 -> V_195 == 0 )
return true ;
return false ;
}
static bool F_600 ( const T_8 * V_977 ,
const T_8 * V_978 )
{
return F_134 ( V_977 , V_978 ) ;
}
