static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
int V_8 ;
if ( V_7 == NULL )
return NULL ;
if ( F_2 ( V_3 , V_9 ) == 0 )
return NULL ;
if ( F_3 ( V_3 ) -> V_10 -> V_11 < 2 )
return NULL ;
V_8 = F_4 ( V_4 , V_6 -> V_12 ,
& V_4 -> V_13 , ( void * * ) & V_7 -> V_7 , & V_7 -> V_14 ) ;
if ( V_8 == 0 )
return V_7 ;
return NULL ;
}
static inline void
F_5 ( struct V_1 * V_7 )
{
if ( V_7 )
F_6 ( V_7 -> V_7 , V_7 -> V_14 ) ;
}
static inline T_1 * F_7 ( struct V_15 * V_16 , struct V_1 * V_7 )
{
if ( V_7 )
return V_16 -> V_17 ;
return V_16 -> V_18 ;
}
static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_19 )
{ return NULL ; }
static inline void
F_5 ( struct V_1 * V_7 )
{ return; }
static inline T_1 *
F_7 ( struct V_15 * V_16 , struct V_1 * V_7 )
{ return V_16 -> V_17 ; }
static int F_8 ( int V_8 )
{
if ( V_8 >= - 1000 )
return V_8 ;
switch ( V_8 ) {
case - V_20 :
case - V_21 :
case - V_22 :
return - V_23 ;
case - V_24 :
case - V_25 :
return - V_26 ;
case - V_27 :
case - V_28 :
return - V_29 ;
case - V_30 :
return - V_31 ;
case - V_32 :
return - V_33 ;
case - V_34 :
return - V_31 ;
case - V_35 :
return - V_36 ;
default:
F_9 ( L_1 ,
V_37 , - V_8 ) ;
break;
}
return - V_38 ;
}
static void F_10 ( T_2 V_39 , T_3 * V_40 , struct V_4 * V_4 ,
struct V_41 * V_42 )
{
T_3 * V_43 , * V_44 ;
if ( V_39 > 2 ) {
V_42 -> V_39 = V_39 ;
memcpy ( & V_42 -> V_40 , V_40 , sizeof( V_42 -> V_40 ) ) ;
return;
}
V_42 -> V_39 = 0 ;
memset ( & V_42 -> V_40 , 0 , sizeof( V_42 -> V_40 ) ) ;
if ( V_39 == 2 )
return;
V_43 = V_44 = F_11 ( * V_42 -> V_45 ) ;
if ( V_39 == 0 ) {
* V_44 ++ = V_46 ;
* V_44 ++ = V_47 ;
* V_44 ++ = V_46 ;
* V_44 ++ = V_46 ;
memcpy ( V_44 , L_2 , 4 ) ;
V_44 ++ ;
* V_44 ++ = V_46 ;
* V_44 ++ = F_12 ( V_48 ) ;
* V_44 ++ = F_12 ( 8 ) ;
V_44 = F_13 ( V_44 , F_14 ( V_4 -> V_49 ) ) ;
}
* V_44 ++ = V_46 ;
* V_44 ++ = V_47 ;
* V_44 ++ = V_50 ;
* V_44 ++ = V_50 ;
memcpy ( V_44 , L_3 , 4 ) ;
V_44 ++ ;
* V_44 ++ = V_46 ;
* V_44 ++ = F_12 ( V_48 ) ;
* V_44 ++ = F_12 ( 8 ) ;
V_44 = F_13 ( V_44 , F_14 ( V_4 -> V_51 -> V_49 ) ) ;
V_42 -> V_52 = ( char * ) V_44 - ( char * ) V_43 ;
V_42 -> V_53 -= V_42 -> V_52 ;
F_15 ( V_43 ) ;
}
static int F_16 ( struct V_54 * V_55 , long * V_56 )
{
int V_57 = 0 ;
F_17 () ;
if ( * V_56 <= 0 )
* V_56 = V_58 ;
if ( * V_56 > V_59 )
* V_56 = V_59 ;
F_18 ( * V_56 ) ;
if ( F_19 ( V_60 ) )
V_57 = - V_61 ;
* V_56 <<= 1 ;
return V_57 ;
}
static int F_20 ( struct V_15 * V_16 , int V_62 , struct V_63 * V_64 )
{
struct V_10 * V_65 = V_16 -> V_10 ;
struct V_66 * V_67 = V_64 -> V_67 ;
struct V_2 * V_2 = V_64 -> V_2 ;
int V_68 = V_62 ;
V_64 -> V_69 = 0 ;
switch( V_62 ) {
case 0 :
return 0 ;
case - V_70 :
if ( V_2 && F_21 ( V_2 , V_71 ) ) {
F_22 ( V_2 ) ;
V_64 -> V_69 = 1 ;
return 0 ;
}
if ( V_67 == NULL )
break;
V_68 = F_23 ( V_16 , V_67 ) ;
if ( V_68 < 0 )
break;
goto V_72;
case - V_73 :
case - V_74 :
case - V_75 :
if ( V_2 != NULL && F_21 ( V_2 , V_71 ) ) {
F_24 ( V_2 ) ;
V_64 -> V_69 = 1 ;
break;
}
if ( V_67 == NULL )
break;
V_68 = F_23 ( V_16 , V_67 ) ;
if ( V_68 < 0 )
break;
goto V_72;
case - V_76 :
if ( V_67 != NULL ) {
V_68 = F_23 ( V_16 , V_67 ) ;
if ( V_68 < 0 )
break;
}
case - V_77 :
case - V_78 :
F_25 ( V_65 ) ;
goto V_72;
#if F_26 ( V_79 )
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
F_9 ( L_4 , V_37 ,
V_62 ) ;
F_27 ( V_65 -> V_87 , V_62 ) ;
goto V_72;
#endif
case - V_35 :
if ( V_64 -> V_56 > V_88 ) {
V_68 = - V_36 ;
break;
}
case - V_89 :
case - V_90 :
V_68 = F_16 ( V_16 -> V_91 , & V_64 -> V_56 ) ;
if ( V_68 != 0 )
break;
case - V_92 :
case - V_93 :
V_64 -> V_69 = 1 ;
break;
case - V_27 :
case - V_28 :
if ( V_16 -> V_94 & V_95 ) {
V_16 -> V_94 &= ~ V_95 ;
V_64 -> V_69 = 1 ;
F_28 ( V_96 L_5
L_6
L_7
L_8 ,
V_16 -> V_10 -> V_97 ) ;
}
}
return F_8 ( V_68 ) ;
V_72:
V_68 = F_29 ( V_65 ) ;
if ( V_68 == 0 )
V_64 -> V_69 = 1 ;
return V_68 ;
}
static bool F_30 ( struct V_10 * V_65 )
{
T_4 V_98 = V_65 -> V_99 -> V_100 -> V_101 ;
if ( V_98 == V_102 ||
V_98 == V_103 )
return true ;
return false ;
}
static void F_31 ( struct V_10 * V_65 , unsigned long V_104 )
{
F_32 ( & V_65 -> V_105 ) ;
if ( F_33 ( V_65 -> V_106 , V_104 ) )
V_65 -> V_106 = V_104 ;
F_34 ( & V_65 -> V_105 ) ;
}
static void F_35 ( const struct V_15 * V_16 , unsigned long V_104 )
{
F_31 ( V_16 -> V_10 , V_104 ) ;
}
static void F_36 ( struct V_107 * args ,
struct V_108 * V_57 , int V_109 )
{
args -> V_110 = NULL ;
args -> V_111 = V_109 ;
args -> V_112 = 0 ;
V_57 -> V_113 = NULL ;
}
static void F_37 ( struct V_107 * args )
{
args -> V_112 = 1 ;
}
static int F_38 ( const struct V_15 * V_16 ,
struct V_107 * args ,
struct V_108 * V_57 ,
struct V_114 * V_115 )
{
struct V_116 * V_117 = V_16 -> V_10 -> V_118 ;
struct V_119 * V_120 ;
if ( V_57 -> V_113 != NULL )
goto V_121;
F_32 ( & V_117 -> V_122 ) ;
if ( F_39 ( V_117 ) && ! args -> V_112 )
goto V_123;
V_120 = F_40 ( V_117 ) ;
if ( F_41 ( V_120 ) ) {
if ( V_120 == F_42 ( - V_124 ) )
V_115 -> V_125 = V_88 >> 2 ;
goto V_123;
}
F_34 ( & V_117 -> V_122 ) ;
args -> V_110 = V_120 ;
V_57 -> V_113 = V_120 ;
V_121:
F_43 ( V_115 ) ;
return 0 ;
V_123:
if ( args -> V_112 )
F_44 ( & V_117 -> V_126 , V_115 ,
NULL , V_127 ) ;
else
F_45 ( & V_117 -> V_126 , V_115 , NULL ) ;
F_34 ( & V_117 -> V_122 ) ;
return - V_128 ;
}
static int F_46 ( struct V_114 * V_115 ,
struct V_108 * V_57 )
{
struct V_119 * V_120 = V_57 -> V_113 ;
struct V_116 * V_117 ;
if ( ! F_47 ( V_115 ) )
goto V_129;
V_117 = V_120 -> V_130 ;
F_32 ( & V_117 -> V_122 ) ;
if ( ! F_48 ( V_117 , V_120 ) )
F_49 ( V_117 , V_120 ) ;
F_34 ( & V_117 -> V_122 ) ;
V_57 -> V_113 = NULL ;
V_129:
return 1 ;
}
static void F_50 ( struct V_108 * V_57 )
{
struct V_131 * V_132 ;
struct V_116 * V_117 ;
bool V_133 = false ;
if ( ! V_57 -> V_113 ) {
F_9 ( L_9 , V_37 ) ;
return;
}
V_117 = V_57 -> V_113 -> V_130 ;
V_132 = V_117 -> V_132 ;
F_32 ( & V_117 -> V_122 ) ;
if ( V_117 -> V_134 > V_117 -> V_135 )
V_133 = true ;
if ( F_48 ( V_117 , V_57 -> V_113 ) ) {
V_133 = false ;
goto V_136;
}
F_49 ( V_117 , V_57 -> V_113 ) ;
if ( V_117 -> V_134 != V_137 )
V_133 = false ;
V_136:
F_34 ( & V_117 -> V_122 ) ;
V_57 -> V_113 = NULL ;
if ( V_133 )
F_51 ( V_132 -> V_65 ) ;
}
static int F_52 ( struct V_114 * V_115 , struct V_108 * V_57 )
{
struct V_131 * V_132 ;
struct V_119 * V_120 ;
struct V_10 * V_65 ;
bool V_138 = false ;
int V_68 = 1 ;
if ( ! F_47 ( V_115 ) )
goto V_129;
V_120 = V_57 -> V_113 ;
V_132 = V_120 -> V_130 -> V_132 ;
if ( V_120 -> V_138 ) {
V_120 -> V_138 = 0 ;
V_138 = true ;
}
F_53 ( V_132 , V_57 ) ;
switch ( V_57 -> V_139 ) {
case 0 :
++ V_120 -> V_140 ;
V_65 = V_132 -> V_65 ;
F_31 ( V_65 , V_57 -> V_141 ) ;
if ( V_57 -> V_142 != 0 )
F_25 ( V_65 ) ;
F_54 ( V_120 -> V_130 , V_120 , V_57 ) ;
break;
case 1 :
V_120 -> V_138 = 1 ;
goto V_129;
case - V_90 :
F_9 ( L_10 ,
V_37 ,
V_120 -> V_143 ,
V_120 -> V_140 ) ;
goto V_144;
case - V_81 :
goto V_145;
case - V_86 :
if ( V_138 ) {
++ V_120 -> V_140 ;
goto V_145;
}
if ( V_120 -> V_140 != 1 ) {
V_120 -> V_140 = 1 ;
goto V_145;
}
break;
case - V_85 :
++ V_120 -> V_140 ;
goto V_145;
default:
++ V_120 -> V_140 ;
}
V_129:
F_9 ( L_11 , V_37 , V_57 -> V_139 ) ;
F_50 ( V_57 ) ;
return V_68 ;
V_145:
if ( F_55 ( V_115 ) ) {
V_115 -> V_146 = 0 ;
V_68 = 0 ;
}
goto V_129;
V_144:
if ( ! F_56 ( V_115 ) )
goto V_129;
F_57 ( V_115 , V_59 ) ;
return 0 ;
}
static int F_58 ( struct V_114 * V_115 ,
struct V_108 * V_57 )
{
if ( V_57 -> V_113 == NULL )
return 1 ;
if ( ! V_57 -> V_113 -> V_130 -> V_132 )
return F_46 ( V_115 , V_57 ) ;
return F_52 ( V_115 , V_57 ) ;
}
int F_59 ( struct V_131 * V_132 ,
struct V_107 * args ,
struct V_108 * V_57 ,
struct V_114 * V_115 )
{
struct V_119 * V_120 ;
struct V_116 * V_117 ;
F_9 ( L_12 , V_37 ) ;
if ( V_57 -> V_113 != NULL )
goto V_147;
V_117 = & V_132 -> V_148 ;
V_115 -> V_125 = 0 ;
F_32 ( & V_117 -> V_122 ) ;
if ( F_60 ( V_149 , & V_117 -> V_150 ) &&
! args -> V_112 ) {
F_9 ( L_13 , V_37 ) ;
goto V_123;
}
V_120 = F_40 ( V_117 ) ;
if ( F_41 ( V_120 ) ) {
if ( V_120 == F_42 ( - V_124 ) )
V_115 -> V_125 = V_88 >> 2 ;
F_9 ( L_14 , V_37 ) ;
goto V_123;
}
F_34 ( & V_117 -> V_122 ) ;
args -> V_110 = V_120 ;
F_9 ( L_15 , V_37 ,
V_120 -> V_143 , V_120 -> V_140 ) ;
V_57 -> V_113 = V_120 ;
V_57 -> V_141 = V_151 ;
V_57 -> V_142 = 0 ;
V_57 -> V_139 = 1 ;
F_61 ( V_132 , args ) ;
V_147:
F_43 ( V_115 ) ;
return 0 ;
V_123:
if ( args -> V_112 )
F_44 ( & V_117 -> V_126 , V_115 ,
NULL , V_127 ) ;
else
F_45 ( & V_117 -> V_126 , V_115 , NULL ) ;
F_34 ( & V_117 -> V_122 ) ;
return - V_128 ;
}
static int F_62 ( const struct V_15 * V_16 ,
struct V_107 * args ,
struct V_108 * V_57 ,
struct V_114 * V_115 )
{
struct V_131 * V_132 = F_63 ( V_16 ) ;
int V_68 = 0 ;
if ( ! V_132 )
return F_38 ( V_16 , args , V_57 , V_115 ) ;
F_9 ( L_16 ,
V_37 , V_132 -> V_65 , V_132 , V_57 -> V_113 ?
V_57 -> V_113 -> V_143 : V_137 ) ;
V_68 = F_59 ( V_132 , args , V_57 , V_115 ) ;
F_9 ( L_17 , V_37 , V_68 ) ;
return V_68 ;
}
static void F_64 ( struct V_114 * V_115 , void * V_152 )
{
struct V_153 * V_154 = V_152 ;
struct V_131 * V_132 = F_63 ( V_154 -> V_155 ) ;
F_9 ( L_18 , V_37 , V_154 -> V_155 ) ;
F_59 ( V_132 , V_154 -> V_156 , V_154 -> V_157 , V_115 ) ;
}
static void F_65 ( struct V_114 * V_115 , void * V_152 )
{
struct V_153 * V_154 = V_152 ;
F_52 ( V_115 , V_154 -> V_157 ) ;
}
static int F_62 ( const struct V_15 * V_16 ,
struct V_107 * args ,
struct V_108 * V_57 ,
struct V_114 * V_115 )
{
return F_38 ( V_16 , args , V_57 , V_115 ) ;
}
static int F_58 ( struct V_114 * V_115 ,
struct V_108 * V_57 )
{
return F_46 ( V_115 , V_57 ) ;
}
static void F_66 ( struct V_114 * V_115 , void * V_152 )
{
struct V_153 * V_154 = V_152 ;
F_62 ( V_154 -> V_155 ,
V_154 -> V_156 , V_154 -> V_157 , V_115 ) ;
}
static void F_67 ( struct V_114 * V_115 , void * V_152 )
{
struct V_153 * V_154 = V_152 ;
F_58 ( V_115 , V_154 -> V_157 ) ;
}
static int F_68 ( struct V_54 * V_55 ,
struct V_15 * V_16 ,
struct V_158 * V_159 ,
struct V_107 * args ,
struct V_108 * V_57 )
{
int V_68 ;
struct V_114 * V_115 ;
struct V_10 * V_65 = V_16 -> V_10 ;
struct V_153 V_154 = {
. V_155 = V_16 ,
. V_156 = args ,
. V_157 = V_57 ,
} ;
struct V_160 V_161 = {
. V_162 = V_55 ,
. V_158 = V_159 ,
. V_163 = V_65 -> V_164 -> V_165 ,
. V_166 = & V_154
} ;
V_115 = F_69 ( & V_161 ) ;
if ( F_41 ( V_115 ) )
V_68 = F_70 ( V_115 ) ;
else {
V_68 = V_115 -> V_146 ;
F_71 ( V_115 ) ;
}
return V_68 ;
}
static
int F_72 ( struct V_54 * V_55 ,
struct V_15 * V_16 ,
struct V_158 * V_159 ,
struct V_107 * args ,
struct V_108 * V_57 ,
int V_109 )
{
F_36 ( args , V_57 , V_109 ) ;
return F_68 ( V_55 , V_16 , V_159 , args , V_57 ) ;
}
static void F_73 ( struct V_2 * V_3 , struct V_167 * V_168 )
{
struct V_169 * V_170 = F_74 ( V_3 ) ;
F_32 ( & V_3 -> V_171 ) ;
V_170 -> V_172 |= V_173 | V_174 ;
if ( ! V_168 -> V_175 || V_168 -> V_176 != V_3 -> V_177 )
F_75 ( V_3 ) ;
V_3 -> V_177 = V_168 -> V_178 ;
F_76 ( V_3 ) ;
F_34 ( & V_3 -> V_171 ) ;
}
static bool F_77 ( struct V_15 * V_16 ,
int V_8 , struct V_63 * V_64 )
{
if ( V_8 != - V_29 )
return false ;
if ( ! ( V_16 -> V_94 & V_179 ) )
return false ;
V_16 -> V_94 &= ~ V_179 ;
V_64 -> V_69 = 1 ;
return true ;
}
static enum V_180
F_78 ( struct V_15 * V_16 ,
enum V_180 V_181 )
{
if ( V_16 -> V_94 & V_179 )
return V_181 ;
switch ( V_181 ) {
default:
return V_181 ;
case V_182 :
return V_183 ;
case V_184 :
return V_185 ;
case V_186 :
return V_187 ;
}
}
static void F_79 ( struct V_188 * V_44 )
{
V_44 -> V_189 . V_190 = & V_44 -> V_190 ;
V_44 -> V_189 . V_191 = V_44 -> V_191 ;
V_44 -> V_189 . V_192 = V_44 -> V_193 . V_192 ;
V_44 -> V_194 . V_192 = V_44 -> V_195 . V_192 ;
V_44 -> V_189 . V_16 = V_44 -> V_193 . V_16 ;
V_44 -> V_189 . V_196 = V_44 -> V_193 . V_197 ;
F_80 ( & V_44 -> V_190 ) ;
F_81 ( & V_44 -> V_190 , & V_44 -> V_198 , & V_44 -> V_199 ) ;
}
static struct V_188 * F_82 ( struct V_4 * V_4 ,
struct V_200 * V_201 , T_5 V_202 , int V_203 ,
const struct V_5 * V_204 ,
struct V_1 * V_7 ,
enum V_180 V_181 ,
T_6 V_205 )
{
struct V_4 * V_206 = F_83 ( V_4 ) ;
struct V_2 * V_3 = V_206 -> V_49 ;
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_188 * V_44 ;
V_44 = F_84 ( sizeof( * V_44 ) , V_205 ) ;
if ( V_44 == NULL )
goto V_8;
V_44 -> V_191 = F_85 ( V_16 , V_205 ) ;
if ( F_41 ( V_44 -> V_191 ) )
goto V_207;
V_44 -> V_193 . V_192 = F_86 ( & V_201 -> V_208 , V_205 ) ;
if ( V_44 -> V_193 . V_192 == NULL )
goto V_209;
F_87 ( V_4 -> V_210 ) ;
V_44 -> V_4 = F_88 ( V_4 ) ;
V_44 -> V_3 = V_206 ;
V_44 -> V_211 = V_201 ;
F_89 ( & V_201 -> V_212 ) ;
V_44 -> V_193 . V_213 = V_203 ;
V_44 -> V_193 . V_202 = V_202 & ( V_71 | V_214 ) ;
if ( ! ( V_203 & V_215 ) ) {
V_44 -> V_193 . V_197 = V_216 | V_217 |
V_218 | V_219 ;
}
V_44 -> V_193 . V_220 = V_16 -> V_10 -> V_221 ;
V_44 -> V_193 . V_222 . V_223 = F_90 ( V_201 -> V_208 . V_223 ) ;
V_44 -> V_193 . V_222 . V_224 = V_201 -> V_208 . V_225 ;
V_44 -> V_193 . V_226 = & V_4 -> V_13 ;
V_44 -> V_193 . V_16 = V_16 ;
V_44 -> V_193 . V_227 = F_7 ( V_16 , V_7 ) ;
V_44 -> V_193 . V_228 = & V_229 [ 0 ] ;
V_44 -> V_193 . V_7 = V_7 ;
V_44 -> V_193 . V_181 = F_78 ( V_16 , V_181 ) ;
switch ( V_44 -> V_193 . V_181 ) {
case V_183 :
case V_185 :
case V_187 :
V_44 -> V_193 . V_230 = F_91 ( V_3 ) ;
break;
case V_231 :
case V_182 :
case V_184 :
case V_186 :
V_44 -> V_193 . V_230 = F_91 ( V_4 -> V_49 ) ;
}
if ( V_204 != NULL && V_204 -> V_232 != 0 ) {
T_7 V_233 [ 2 ] ;
V_44 -> V_193 . V_234 . V_204 = & V_44 -> V_204 ;
memcpy ( & V_44 -> V_204 , V_204 , sizeof( V_44 -> V_204 ) ) ;
V_233 [ 0 ] = V_151 ;
V_233 [ 1 ] = V_60 -> V_235 ;
memcpy ( V_44 -> V_193 . V_234 . V_40 . V_154 , V_233 ,
sizeof( V_44 -> V_193 . V_234 . V_40 . V_154 ) ) ;
}
V_44 -> V_195 . V_230 = & V_44 -> V_189 . V_230 ;
V_44 -> V_195 . V_236 = & V_44 -> V_189 . V_236 ;
V_44 -> V_195 . V_192 = V_44 -> V_193 . V_192 ;
F_79 ( V_44 ) ;
F_92 ( & V_44 -> V_237 ) ;
return V_44 ;
V_209:
F_93 ( V_44 -> V_191 ) ;
V_207:
F_94 ( V_44 ) ;
V_8:
F_95 ( V_206 ) ;
return NULL ;
}
static void F_96 ( struct V_237 * V_237 )
{
struct V_188 * V_44 = F_97 ( V_237 ,
struct V_188 , V_237 ) ;
struct V_238 * V_239 = V_44 -> V_4 -> V_210 ;
F_98 ( V_44 -> V_193 . V_192 ) ;
if ( V_44 -> V_67 != NULL )
F_99 ( V_44 -> V_67 ) ;
F_100 ( V_44 -> V_211 ) ;
F_93 ( V_44 -> V_191 ) ;
F_95 ( V_44 -> V_3 ) ;
F_95 ( V_44 -> V_4 ) ;
F_101 ( V_239 ) ;
F_102 ( & V_44 -> V_190 ) ;
F_94 ( V_44 ) ;
}
static void F_103 ( struct V_188 * V_44 )
{
if ( V_44 != NULL )
F_104 ( & V_44 -> V_237 , F_96 ) ;
}
static int F_105 ( struct V_114 * V_115 )
{
int V_68 ;
V_68 = F_106 ( V_115 ) ;
return V_68 ;
}
static int F_107 ( struct V_66 * V_67 , T_5 V_240 , int V_241 )
{
int V_68 = 0 ;
if ( V_241 & ( V_215 | V_242 ) )
goto V_129;
switch ( V_240 & ( V_71 | V_214 ) ) {
case V_71 :
V_68 |= F_60 ( V_243 , & V_67 -> V_203 ) != 0
&& V_67 -> V_244 != 0 ;
break;
case V_214 :
V_68 |= F_60 ( V_245 , & V_67 -> V_203 ) != 0
&& V_67 -> V_246 != 0 ;
break;
case V_71 | V_214 :
V_68 |= F_60 ( V_247 , & V_67 -> V_203 ) != 0
&& V_67 -> V_248 != 0 ;
}
V_129:
return V_68 ;
}
static int F_108 ( struct V_249 * V_250 , T_5 V_202 )
{
if ( V_250 == NULL )
return 0 ;
if ( ( V_250 -> type & V_202 ) != V_202 )
return 0 ;
if ( F_60 ( V_251 , & V_250 -> V_203 ) )
return 0 ;
if ( F_60 ( V_252 , & V_250 -> V_203 ) )
return 0 ;
F_109 ( V_250 ) ;
return 1 ;
}
static void F_110 ( struct V_66 * V_67 , T_5 V_202 )
{
switch ( V_202 ) {
case V_214 :
V_67 -> V_246 ++ ;
break;
case V_71 :
V_67 -> V_244 ++ ;
break;
case V_71 | V_214 :
V_67 -> V_248 ++ ;
}
F_111 ( V_67 , V_67 -> V_67 | V_202 ) ;
}
static void F_112 ( struct V_66 * V_67 , T_8 * V_236 , T_5 V_202 )
{
if ( F_60 ( V_253 , & V_67 -> V_203 ) == 0 )
F_113 ( & V_67 -> V_236 , V_236 ) ;
F_113 ( & V_67 -> V_254 , V_236 ) ;
F_114 ( V_255 , & V_67 -> V_203 ) ;
switch ( V_202 ) {
case V_71 :
F_114 ( V_243 , & V_67 -> V_203 ) ;
break;
case V_214 :
F_114 ( V_245 , & V_67 -> V_203 ) ;
break;
case V_71 | V_214 :
F_114 ( V_247 , & V_67 -> V_203 ) ;
}
}
static void F_115 ( struct V_66 * V_67 , T_8 * V_236 , T_5 V_202 )
{
F_116 ( & V_67 -> V_256 ) ;
F_112 ( V_67 , V_236 , V_202 ) ;
F_117 ( & V_67 -> V_256 ) ;
}
static void F_118 ( struct V_66 * V_67 , T_8 * V_254 , const T_8 * V_257 , T_5 V_202 )
{
F_116 ( & V_67 -> V_256 ) ;
if ( V_257 != NULL ) {
F_113 ( & V_67 -> V_236 , V_257 ) ;
F_114 ( V_253 , & V_67 -> V_203 ) ;
}
if ( V_254 != NULL )
F_112 ( V_67 , V_254 , V_202 ) ;
F_117 ( & V_67 -> V_256 ) ;
F_32 ( & V_67 -> V_211 -> V_258 ) ;
F_110 ( V_67 , V_202 ) ;
F_34 ( & V_67 -> V_211 -> V_258 ) ;
}
static int F_119 ( struct V_66 * V_67 , T_8 * V_254 , T_8 * V_250 , T_5 V_202 )
{
struct V_169 * V_170 = F_74 ( V_67 -> V_2 ) ;
struct V_249 * V_259 ;
int V_68 = 0 ;
V_202 &= ( V_71 | V_214 ) ;
F_120 () ;
V_259 = F_121 ( V_170 -> V_250 ) ;
if ( V_259 == NULL )
goto V_260;
F_32 ( & V_259 -> V_261 ) ;
if ( F_121 ( V_170 -> V_250 ) != V_259 ||
F_60 ( V_252 , & V_259 -> V_203 ) ||
( V_259 -> type & V_202 ) != V_202 )
goto V_262;
if ( V_250 == NULL )
V_250 = & V_259 -> V_236 ;
else if ( ! F_122 ( & V_259 -> V_236 , V_250 ) )
goto V_262;
F_109 ( V_259 ) ;
F_118 ( V_67 , V_254 , & V_259 -> V_236 , V_202 ) ;
V_68 = 1 ;
V_262:
F_34 ( & V_259 -> V_261 ) ;
V_260:
F_123 () ;
if ( ! V_68 && V_254 != NULL ) {
F_118 ( V_67 , V_254 , NULL , V_202 ) ;
V_68 = 1 ;
}
return V_68 ;
}
static void F_124 ( struct V_2 * V_2 , T_5 V_202 )
{
struct V_249 * V_250 ;
F_120 () ;
V_250 = F_121 ( F_74 ( V_2 ) -> V_250 ) ;
if ( V_250 == NULL || ( V_250 -> type & V_202 ) == V_202 ) {
F_123 () ;
return;
}
F_123 () ;
F_22 ( V_2 ) ;
}
static struct V_66 * F_125 ( struct V_188 * V_263 )
{
struct V_66 * V_67 = V_263 -> V_67 ;
struct V_169 * V_170 = F_74 ( V_67 -> V_2 ) ;
struct V_249 * V_250 ;
int V_241 = V_263 -> V_193 . V_213 ;
T_5 V_202 = V_263 -> V_193 . V_202 ;
T_8 V_236 ;
int V_68 = - V_128 ;
for (; ; ) {
if ( F_107 ( V_67 , V_202 , V_241 ) ) {
F_32 ( & V_67 -> V_211 -> V_258 ) ;
if ( F_107 ( V_67 , V_202 , V_241 ) ) {
F_110 ( V_67 , V_202 ) ;
F_34 ( & V_67 -> V_211 -> V_258 ) ;
goto V_264;
}
F_34 ( & V_67 -> V_211 -> V_258 ) ;
}
F_120 () ;
V_250 = F_121 ( V_170 -> V_250 ) ;
if ( ! F_108 ( V_250 , V_202 ) ) {
F_123 () ;
break;
}
F_113 ( & V_236 , & V_250 -> V_236 ) ;
F_123 () ;
F_126 ( V_263 -> V_193 . V_192 ) ;
if ( ! V_263 -> V_265 ) {
V_68 = F_127 ( V_67 -> V_2 , V_67 -> V_211 -> V_266 , V_241 ) ;
if ( V_68 != 0 )
goto V_129;
}
V_68 = - V_128 ;
if ( F_119 ( V_67 , NULL , & V_236 , V_202 ) )
goto V_264;
}
V_129:
return F_42 ( V_68 ) ;
V_264:
F_89 ( & V_67 -> V_53 ) ;
return V_67 ;
}
static void
F_128 ( struct V_188 * V_154 , struct V_66 * V_67 )
{
struct V_10 * V_65 = F_3 ( V_67 -> V_2 ) -> V_10 ;
struct V_249 * V_250 ;
int V_267 = 0 ;
F_120 () ;
V_250 = F_121 ( F_74 ( V_67 -> V_2 ) -> V_250 ) ;
if ( V_250 )
V_267 = V_250 -> V_203 ;
F_123 () ;
if ( V_154 -> V_193 . V_181 == V_185 ) {
F_129 ( L_19
L_20
L_21 ,
V_65 -> V_97 ) ;
} else if ( ( V_267 & 1UL << V_251 ) == 0 )
F_130 ( V_67 -> V_2 ,
V_154 -> V_211 -> V_266 ,
& V_154 -> V_189 ) ;
else
F_131 ( V_67 -> V_2 ,
V_154 -> V_211 -> V_266 ,
& V_154 -> V_189 ) ;
}
static struct V_66 *
F_132 ( struct V_188 * V_154 )
{
struct V_2 * V_2 = V_154 -> V_67 -> V_2 ;
struct V_66 * V_67 = V_154 -> V_67 ;
int V_68 ;
if ( ! V_154 -> V_268 ) {
V_68 = V_154 -> V_269 ;
goto V_8;
}
V_68 = - V_270 ;
if ( ! ( V_154 -> V_190 . V_271 & V_272 ) ||
! ( V_154 -> V_190 . V_271 & V_273 ) ||
! ( V_154 -> V_190 . V_271 & V_274 ) )
goto V_8;
V_68 = - V_124 ;
V_67 = F_133 ( V_2 , V_154 -> V_211 ) ;
if ( V_67 == NULL )
goto V_8;
V_68 = F_134 ( V_2 , & V_154 -> V_190 ) ;
if ( V_68 )
goto V_8;
F_135 ( V_2 , & V_154 -> V_190 , V_154 -> V_191 ) ;
if ( V_154 -> V_189 . V_275 != 0 )
F_128 ( V_154 , V_67 ) ;
F_119 ( V_67 , & V_154 -> V_189 . V_236 , NULL ,
V_154 -> V_193 . V_202 ) ;
return V_67 ;
V_8:
return F_42 ( V_68 ) ;
}
static struct V_66 *
F_136 ( struct V_188 * V_154 )
{
struct V_2 * V_2 ;
struct V_66 * V_67 = NULL ;
int V_68 ;
if ( ! V_154 -> V_268 ) {
V_67 = F_125 ( V_154 ) ;
goto V_129;
}
V_68 = - V_128 ;
if ( ! ( V_154 -> V_190 . V_271 & V_276 ) )
goto V_8;
V_2 = F_137 ( V_154 -> V_3 -> V_210 , & V_154 -> V_189 . V_230 , & V_154 -> V_190 , V_154 -> V_191 ) ;
V_68 = F_70 ( V_2 ) ;
if ( F_41 ( V_2 ) )
goto V_8;
V_68 = - V_124 ;
V_67 = F_133 ( V_2 , V_154 -> V_211 ) ;
if ( V_67 == NULL )
goto V_277;
if ( V_154 -> V_189 . V_275 != 0 )
F_128 ( V_154 , V_67 ) ;
F_119 ( V_67 , & V_154 -> V_189 . V_236 , NULL ,
V_154 -> V_193 . V_202 ) ;
F_138 ( V_2 ) ;
V_129:
F_126 ( V_154 -> V_193 . V_192 ) ;
return V_67 ;
V_277:
F_138 ( V_2 ) ;
V_8:
return F_42 ( V_68 ) ;
}
static struct V_66 *
F_139 ( struct V_188 * V_154 )
{
if ( V_154 -> V_193 . V_181 == V_231 )
return F_132 ( V_154 ) ;
return F_136 ( V_154 ) ;
}
static struct V_278 * F_140 ( struct V_66 * V_67 )
{
struct V_169 * V_170 = F_74 ( V_67 -> V_2 ) ;
struct V_278 * V_279 ;
F_32 ( & V_67 -> V_2 -> V_171 ) ;
F_141 (ctx, &nfsi->open_files, list) {
if ( V_279 -> V_67 != V_67 )
continue;
F_142 ( V_279 ) ;
F_34 ( & V_67 -> V_2 -> V_171 ) ;
return V_279 ;
}
F_34 ( & V_67 -> V_2 -> V_171 ) ;
return F_42 ( - V_280 ) ;
}
static struct V_188 * F_143 ( struct V_278 * V_279 ,
struct V_66 * V_67 , enum V_180 V_181 )
{
struct V_188 * V_263 ;
V_263 = F_82 ( V_279 -> V_4 , V_67 -> V_211 , 0 , 0 ,
NULL , NULL , V_181 , V_281 ) ;
if ( V_263 == NULL )
return F_42 ( - V_124 ) ;
V_263 -> V_67 = V_67 ;
F_89 ( & V_67 -> V_53 ) ;
return V_263 ;
}
static int F_144 ( struct V_188 * V_263 , T_5 V_202 , struct V_66 * * V_57 )
{
struct V_66 * V_282 ;
int V_68 ;
V_263 -> V_193 . V_213 = 0 ;
V_263 -> V_193 . V_202 = V_202 ;
memset ( & V_263 -> V_189 , 0 , sizeof( V_263 -> V_189 ) ) ;
memset ( & V_263 -> V_194 , 0 , sizeof( V_263 -> V_194 ) ) ;
F_79 ( V_263 ) ;
V_68 = F_145 ( V_263 ) ;
if ( V_68 != 0 )
return V_68 ;
V_282 = F_139 ( V_263 ) ;
if ( F_41 ( V_282 ) )
return F_70 ( V_282 ) ;
F_146 ( V_282 , V_202 ) ;
* V_57 = V_282 ;
return 0 ;
}
static int F_147 ( struct V_188 * V_263 , struct V_66 * V_67 )
{
struct V_66 * V_282 ;
int V_68 ;
F_148 ( V_253 , & V_67 -> V_203 ) ;
F_148 ( V_255 , & V_67 -> V_203 ) ;
F_149 () ;
if ( V_67 -> V_248 != 0 ) {
F_148 ( V_247 , & V_67 -> V_203 ) ;
V_68 = F_144 ( V_263 , V_71 | V_214 , & V_282 ) ;
if ( V_68 != 0 )
return V_68 ;
if ( V_282 != V_67 )
return - V_270 ;
}
if ( V_67 -> V_246 != 0 ) {
F_148 ( V_245 , & V_67 -> V_203 ) ;
V_68 = F_144 ( V_263 , V_214 , & V_282 ) ;
if ( V_68 != 0 )
return V_68 ;
if ( V_282 != V_67 )
return - V_270 ;
}
if ( V_67 -> V_244 != 0 ) {
F_148 ( V_243 , & V_67 -> V_203 ) ;
V_68 = F_144 ( V_263 , V_71 , & V_282 ) ;
if ( V_68 != 0 )
return V_68 ;
if ( V_282 != V_67 )
return - V_270 ;
}
if ( F_60 ( V_253 , & V_67 -> V_203 ) == 0 &&
! F_122 ( & V_67 -> V_236 , & V_67 -> V_254 ) ) {
F_116 ( & V_67 -> V_256 ) ;
if ( F_60 ( V_253 , & V_67 -> V_203 ) == 0 )
F_113 ( & V_67 -> V_236 , & V_67 -> V_254 ) ;
F_117 ( & V_67 -> V_256 ) ;
}
return 0 ;
}
static int F_150 ( struct V_278 * V_279 , struct V_66 * V_67 )
{
struct V_249 * V_250 ;
struct V_188 * V_263 ;
T_5 V_275 = 0 ;
int V_283 ;
V_263 = F_143 ( V_279 , V_67 ,
V_231 ) ;
if ( F_41 ( V_263 ) )
return F_70 ( V_263 ) ;
F_120 () ;
V_250 = F_121 ( F_74 ( V_67 -> V_2 ) -> V_250 ) ;
if ( V_250 != NULL && F_60 ( V_251 , & V_250 -> V_203 ) != 0 )
V_275 = V_250 -> type ;
F_123 () ;
V_263 -> V_193 . V_234 . V_275 = V_275 ;
V_283 = F_147 ( V_263 , V_67 ) ;
F_103 ( V_263 ) ;
return V_283 ;
}
static int F_151 ( struct V_278 * V_279 , struct V_66 * V_67 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_150 ( V_279 , V_67 ) ;
F_152 ( V_279 , 0 , V_8 ) ;
if ( F_77 ( V_16 , V_8 , & V_64 ) )
continue;
if ( V_8 != - V_90 )
break;
F_20 ( V_16 , V_8 , & V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_153 ( struct V_200 * V_201 , struct V_66 * V_67 )
{
struct V_278 * V_279 ;
int V_68 ;
V_279 = F_140 ( V_67 ) ;
if ( F_41 ( V_279 ) )
return - V_128 ;
V_68 = F_151 ( V_279 , V_67 ) ;
F_154 ( V_279 ) ;
return V_68 ;
}
static int F_155 ( struct V_15 * V_16 , struct V_66 * V_67 , const T_8 * V_236 , int V_8 )
{
switch ( V_8 ) {
default:
F_28 ( V_284 L_22
L_23 , V_37 , V_8 ) ;
case 0 :
case - V_280 :
case - V_270 :
break;
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
F_114 ( V_253 , & V_67 -> V_203 ) ;
F_27 ( V_16 -> V_10 -> V_87 , V_8 ) ;
return - V_128 ;
case - V_78 :
case - V_77 :
F_114 ( V_253 , & V_67 -> V_203 ) ;
case - V_76 :
F_25 ( V_16 -> V_10 ) ;
return - V_128 ;
case - V_73 :
case - V_74 :
case - V_75 :
case - V_70 :
F_156 ( V_67 -> V_2 ,
V_236 ) ;
F_23 ( V_16 , V_67 ) ;
return 0 ;
case - V_90 :
case - V_89 :
F_114 ( V_253 , & V_67 -> V_203 ) ;
F_157 ( 1 ) ;
return - V_128 ;
case - V_124 :
case - V_285 :
return 0 ;
}
return V_8 ;
}
int F_158 ( struct V_278 * V_279 , struct V_66 * V_67 , const T_8 * V_236 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
struct V_188 * V_263 ;
int V_8 ;
V_263 = F_143 ( V_279 , V_67 ,
V_184 ) ;
if ( F_41 ( V_263 ) )
return F_70 ( V_263 ) ;
F_113 ( & V_263 -> V_193 . V_234 . V_250 , V_236 ) ;
V_8 = F_147 ( V_263 , V_67 ) ;
F_103 ( V_263 ) ;
return F_155 ( V_16 , V_67 , V_236 , V_8 ) ;
}
static void F_159 ( struct V_114 * V_115 , void * V_152 )
{
struct V_188 * V_154 = V_152 ;
F_38 ( V_154 -> V_193 . V_16 , & V_154 -> V_193 . V_156 ,
& V_154 -> V_189 . V_157 , V_115 ) ;
}
static void F_160 ( struct V_114 * V_115 , void * V_152 )
{
struct V_188 * V_154 = V_152 ;
F_46 ( V_115 , & V_154 -> V_189 . V_157 ) ;
V_154 -> V_269 = V_115 -> V_146 ;
if ( V_154 -> V_269 == 0 ) {
F_113 ( & V_154 -> V_189 . V_236 , & V_154 -> V_194 . V_236 ) ;
F_161 ( & V_154 -> V_211 -> V_208 , 0 ) ;
F_35 ( V_154 -> V_189 . V_16 , V_154 -> V_104 ) ;
V_154 -> V_268 = 1 ;
}
}
static void F_162 ( void * V_152 )
{
struct V_188 * V_154 = V_152 ;
struct V_66 * V_67 = NULL ;
if ( V_154 -> V_286 == 0 )
goto V_287;
if ( ! V_154 -> V_268 )
goto V_287;
V_67 = F_139 ( V_154 ) ;
if ( ! F_41 ( V_67 ) )
F_146 ( V_67 , V_154 -> V_193 . V_202 ) ;
V_287:
F_103 ( V_154 ) ;
}
static int F_163 ( struct V_188 * V_154 )
{
struct V_15 * V_16 = F_3 ( V_154 -> V_3 -> V_49 ) ;
struct V_114 * V_115 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_290 ] ,
. V_291 = & V_154 -> V_195 ,
. V_292 = & V_154 -> V_194 ,
. V_293 = V_154 -> V_211 -> V_266 ,
} ;
struct V_160 V_294 = {
. V_162 = V_16 -> V_91 ,
. V_158 = & V_159 ,
. V_163 = & V_295 ,
. V_166 = V_154 ,
. V_296 = V_297 ,
. V_203 = V_298 ,
} ;
int V_283 ;
F_36 ( & V_154 -> V_193 . V_156 , & V_154 -> V_189 . V_157 , 1 ) ;
F_164 ( & V_154 -> V_237 ) ;
V_154 -> V_268 = 0 ;
V_154 -> V_269 = 0 ;
V_154 -> V_104 = V_151 ;
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
V_283 = F_105 ( V_115 ) ;
if ( V_283 != 0 ) {
V_154 -> V_286 = 1 ;
F_165 () ;
} else
V_283 = V_154 -> V_269 ;
F_71 ( V_115 ) ;
return V_283 ;
}
static void F_166 ( struct V_114 * V_115 , void * V_152 )
{
struct V_188 * V_154 = V_152 ;
struct V_200 * V_201 = V_154 -> V_211 ;
struct V_10 * V_65 = V_201 -> V_299 -> V_10 ;
if ( F_167 ( V_154 -> V_193 . V_192 , V_115 ) != 0 )
goto V_300;
if ( V_154 -> V_67 != NULL ) {
struct V_249 * V_250 ;
if ( F_107 ( V_154 -> V_67 , V_154 -> V_193 . V_202 , V_154 -> V_193 . V_213 ) )
goto V_301;
F_120 () ;
V_250 = F_121 ( F_74 ( V_154 -> V_67 -> V_2 ) -> V_250 ) ;
if ( V_154 -> V_193 . V_181 != V_185 &&
V_154 -> V_193 . V_181 != V_184 &&
F_108 ( V_250 , V_154 -> V_193 . V_202 ) )
goto V_302;
F_123 () ;
}
V_154 -> V_193 . V_220 = V_65 -> V_221 ;
switch ( V_154 -> V_193 . V_181 ) {
case V_231 :
case V_184 :
case V_186 :
V_154 -> V_193 . V_228 = & V_303 [ 0 ] ;
case V_182 :
V_115 -> V_304 . V_288 = & V_289 [ V_305 ] ;
F_168 ( & V_154 -> V_189 . V_230 , V_154 -> V_193 . V_230 ) ;
}
V_154 -> V_104 = V_151 ;
if ( F_62 ( V_154 -> V_193 . V_16 ,
& V_154 -> V_193 . V_156 ,
& V_154 -> V_189 . V_157 ,
V_115 ) != 0 )
F_126 ( V_154 -> V_193 . V_192 ) ;
V_154 -> V_193 . V_306 = V_307 ;
if ( V_154 -> V_193 . V_213 & V_215 ) {
V_154 -> V_193 . V_306 = V_308 ;
if ( F_169 ( V_65 ) )
V_154 -> V_193 . V_306 = V_309 ;
else if ( V_65 -> V_164 -> V_310 > 0 )
V_154 -> V_193 . V_306 = V_311 ;
}
return;
V_302:
F_123 () ;
V_301:
V_115 -> V_312 = NULL ;
V_300:
F_58 ( V_115 , & V_154 -> V_189 . V_157 ) ;
}
static void F_170 ( struct V_114 * V_115 , void * V_152 )
{
struct V_188 * V_154 = V_152 ;
V_154 -> V_269 = V_115 -> V_146 ;
if ( ! F_58 ( V_115 , & V_154 -> V_189 . V_157 ) )
return;
if ( V_115 -> V_146 == 0 ) {
if ( V_154 -> V_189 . V_190 -> V_271 & V_272 ) {
switch ( V_154 -> V_189 . V_190 -> V_240 & V_313 ) {
case V_314 :
break;
case V_315 :
V_154 -> V_269 = - V_316 ;
break;
case V_317 :
V_154 -> V_269 = - V_318 ;
break;
default:
V_154 -> V_269 = - V_319 ;
}
}
F_35 ( V_154 -> V_189 . V_16 , V_154 -> V_104 ) ;
if ( ! ( V_154 -> V_189 . V_320 & V_321 ) )
F_161 ( & V_154 -> V_211 -> V_208 , 0 ) ;
}
V_154 -> V_268 = 1 ;
}
static void F_171 ( void * V_152 )
{
struct V_188 * V_154 = V_152 ;
struct V_66 * V_67 = NULL ;
if ( V_154 -> V_286 == 0 )
goto V_287;
if ( V_154 -> V_269 != 0 || ! V_154 -> V_268 )
goto V_287;
if ( V_154 -> V_189 . V_320 & V_321 )
goto V_287;
V_67 = F_139 ( V_154 ) ;
if ( ! F_41 ( V_67 ) )
F_146 ( V_67 , V_154 -> V_193 . V_202 ) ;
V_287:
F_103 ( V_154 ) ;
}
static int F_172 ( struct V_188 * V_154 , int V_322 )
{
struct V_2 * V_3 = V_154 -> V_3 -> V_49 ;
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_323 * V_193 = & V_154 -> V_193 ;
struct V_324 * V_189 = & V_154 -> V_189 ;
struct V_114 * V_115 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_325 ] ,
. V_291 = V_193 ,
. V_292 = V_189 ,
. V_293 = V_154 -> V_211 -> V_266 ,
} ;
struct V_160 V_294 = {
. V_162 = V_16 -> V_91 ,
. V_158 = & V_159 ,
. V_163 = & V_326 ,
. V_166 = V_154 ,
. V_296 = V_297 ,
. V_203 = V_298 ,
} ;
int V_283 ;
F_36 ( & V_193 -> V_156 , & V_189 -> V_157 , 1 ) ;
F_164 ( & V_154 -> V_237 ) ;
V_154 -> V_268 = 0 ;
V_154 -> V_269 = 0 ;
V_154 -> V_286 = 0 ;
V_154 -> V_265 = 0 ;
if ( V_322 ) {
F_37 ( & V_193 -> V_156 ) ;
V_154 -> V_265 = 1 ;
}
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
V_283 = F_105 ( V_115 ) ;
if ( V_283 != 0 ) {
V_154 -> V_286 = 1 ;
F_165 () ;
} else
V_283 = V_154 -> V_269 ;
F_71 ( V_115 ) ;
return V_283 ;
}
static int F_145 ( struct V_188 * V_154 )
{
struct V_2 * V_3 = V_154 -> V_3 -> V_49 ;
struct V_324 * V_189 = & V_154 -> V_189 ;
int V_283 ;
V_283 = F_172 ( V_154 , 1 ) ;
if ( V_283 != 0 || ! V_154 -> V_268 )
return V_283 ;
F_173 ( F_3 ( V_3 ) , & V_154 -> V_190 ) ;
if ( V_189 -> V_320 & V_321 ) {
V_283 = F_163 ( V_154 ) ;
if ( V_283 != 0 )
return V_283 ;
}
return V_283 ;
}
static int F_174 ( struct V_293 * V_327 ,
struct V_188 * V_263 ,
struct V_66 * V_67 , T_5 V_202 ,
int V_328 )
{
struct V_329 V_330 ;
T_1 V_331 ;
if ( V_263 -> V_189 . V_332 == 0 )
return 0 ;
V_331 = 0 ;
if ( V_328 & V_333 ) {
V_331 = V_334 ;
} else if ( V_202 & V_71 )
V_331 = V_335 ;
V_330 . V_327 = V_327 ;
V_330 . V_151 = V_151 ;
F_175 ( & V_330 , V_263 -> V_189 . V_336 ) ;
F_176 ( V_67 -> V_2 , & V_330 ) ;
if ( ( V_331 & ~ V_330 . V_331 & ( V_335 | V_334 ) ) == 0 )
return 0 ;
F_146 ( V_67 , V_202 ) ;
return - V_31 ;
}
static int F_177 ( struct V_188 * V_154 )
{
struct V_2 * V_3 = V_154 -> V_3 -> V_49 ;
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_323 * V_193 = & V_154 -> V_193 ;
struct V_324 * V_189 = & V_154 -> V_189 ;
int V_283 ;
V_283 = F_172 ( V_154 , 0 ) ;
if ( ! V_154 -> V_268 )
return V_283 ;
if ( V_283 != 0 ) {
if ( V_283 == - V_28 &&
! ( V_193 -> V_213 & V_337 ) )
return - V_280 ;
return V_283 ;
}
F_173 ( V_16 , & V_154 -> V_190 ) ;
if ( V_193 -> V_213 & V_337 ) {
F_73 ( V_3 , & V_189 -> V_168 ) ;
if ( V_193 -> V_213 & V_215 )
V_154 -> V_338 = 1 ;
else if ( V_189 -> V_168 . V_176 != V_189 -> V_168 . V_178 )
V_154 -> V_338 = 1 ;
}
if ( ( V_189 -> V_320 & V_339 ) == 0 )
V_16 -> V_94 &= ~ V_340 ;
if( V_189 -> V_320 & V_321 ) {
V_283 = F_163 ( V_154 ) ;
if ( V_283 != 0 )
return V_283 ;
}
if ( ! ( V_189 -> V_190 -> V_271 & V_276 ) )
F_178 ( V_16 , & V_189 -> V_230 , V_189 -> V_190 , V_189 -> V_191 ) ;
return 0 ;
}
static int F_179 ( struct V_15 * V_16 )
{
return F_180 ( V_16 -> V_10 ) ;
}
static int F_181 ( struct V_278 * V_279 , struct V_66 * V_67 )
{
struct V_188 * V_263 ;
int V_68 ;
V_263 = F_143 ( V_279 , V_67 ,
V_182 ) ;
if ( F_41 ( V_263 ) )
return F_70 ( V_263 ) ;
V_68 = F_147 ( V_263 , V_67 ) ;
if ( V_68 == - V_270 )
F_182 ( V_279 -> V_4 ) ;
F_103 ( V_263 ) ;
return V_68 ;
}
static int F_183 ( struct V_278 * V_279 , struct V_66 * V_67 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_181 ( V_279 , V_67 ) ;
F_184 ( V_279 , 0 , V_8 ) ;
if ( F_77 ( V_16 , V_8 , & V_64 ) )
continue;
switch ( V_8 ) {
default:
goto V_129;
case - V_89 :
case - V_90 :
F_20 ( V_16 , V_8 , & V_64 ) ;
V_8 = 0 ;
}
} while ( V_64 . V_69 );
V_129:
return V_8 ;
}
static int F_185 ( struct V_200 * V_201 , struct V_66 * V_67 )
{
struct V_278 * V_279 ;
int V_68 ;
V_279 = F_140 ( V_67 ) ;
if ( F_41 ( V_279 ) )
return - V_128 ;
V_68 = F_183 ( V_279 , V_67 ) ;
F_154 ( V_279 ) ;
return V_68 ;
}
static void F_186 ( struct V_66 * V_67 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
T_8 * V_236 = & V_67 -> V_236 ;
struct V_249 * V_250 ;
struct V_293 * V_327 = NULL ;
int V_283 = - V_75 ;
if ( F_60 ( V_253 , & V_67 -> V_203 ) == 0 )
return;
F_120 () ;
V_250 = F_121 ( F_74 ( V_67 -> V_2 ) -> V_250 ) ;
if ( V_250 != NULL &&
F_122 ( & V_250 -> V_236 , V_236 ) ) {
V_327 = F_187 ( V_250 -> V_327 ) ;
F_123 () ;
V_283 = F_188 ( V_16 , V_236 , V_327 ) ;
F_189 ( V_67 , NULL , V_283 ) ;
} else
F_123 () ;
if ( V_283 != V_341 ) {
if ( V_283 != - V_75 )
F_190 ( V_16 , V_236 , V_327 ) ;
F_24 ( V_67 -> V_2 ) ;
F_116 ( & V_67 -> V_256 ) ;
F_113 ( & V_67 -> V_236 , & V_67 -> V_254 ) ;
F_117 ( & V_67 -> V_256 ) ;
F_148 ( V_253 , & V_67 -> V_203 ) ;
}
if ( V_327 != NULL )
F_191 ( V_327 ) ;
}
static int F_192 ( struct V_66 * V_67 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
T_8 * V_236 = & V_67 -> V_254 ;
struct V_293 * V_327 = V_67 -> V_211 -> V_266 ;
int V_283 ;
if ( ( F_60 ( V_243 , & V_67 -> V_203 ) == 0 ) &&
( F_60 ( V_245 , & V_67 -> V_203 ) == 0 ) &&
( F_60 ( V_247 , & V_67 -> V_203 ) == 0 ) )
return - V_75 ;
V_283 = F_188 ( V_16 , V_236 , V_327 ) ;
F_193 ( V_67 , NULL , V_283 ) ;
if ( V_283 != V_341 ) {
if ( V_283 != - V_75 )
F_190 ( V_16 , V_236 , V_327 ) ;
F_148 ( V_243 , & V_67 -> V_203 ) ;
F_148 ( V_245 , & V_67 -> V_203 ) ;
F_148 ( V_247 , & V_67 -> V_203 ) ;
F_148 ( V_255 , & V_67 -> V_203 ) ;
}
return V_283 ;
}
static int F_194 ( struct V_200 * V_201 , struct V_66 * V_67 )
{
int V_283 ;
F_186 ( V_67 ) ;
V_283 = F_192 ( V_67 ) ;
if ( V_283 != V_341 )
V_283 = F_185 ( V_201 , V_67 ) ;
return V_283 ;
}
static inline void F_195 ( struct V_188 * V_263 , struct V_5 * V_6 )
{
if ( ( V_263 -> V_189 . V_342 [ 1 ] & V_343 ) &&
! ( V_6 -> V_232 & V_344 ) )
V_6 -> V_232 |= V_345 ;
if ( ( V_263 -> V_189 . V_342 [ 1 ] & V_346 ) &&
! ( V_6 -> V_232 & V_347 ) )
V_6 -> V_232 |= V_348 ;
}
static int F_196 ( struct V_188 * V_263 ,
T_5 V_202 ,
int V_203 ,
struct V_278 * V_279 )
{
struct V_200 * V_201 = V_263 -> V_211 ;
struct V_15 * V_16 = V_201 -> V_299 ;
struct V_4 * V_4 ;
struct V_66 * V_67 ;
unsigned int V_349 ;
int V_68 ;
V_349 = F_197 ( & V_201 -> V_350 ) ;
V_68 = F_177 ( V_263 ) ;
if ( V_68 != 0 )
goto V_129;
V_67 = F_139 ( V_263 ) ;
V_68 = F_70 ( V_67 ) ;
if ( F_41 ( V_67 ) )
goto V_129;
if ( V_16 -> V_94 & V_340 )
F_114 ( V_351 , & V_67 -> V_203 ) ;
V_4 = V_263 -> V_4 ;
if ( V_4 -> V_49 == NULL ) {
F_182 ( V_4 ) ;
V_4 = F_198 ( V_4 , F_199 ( V_67 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_263 -> V_4 ;
} else if ( V_4 != V_279 -> V_4 ) {
F_95 ( V_279 -> V_4 ) ;
V_279 -> V_4 = F_88 ( V_4 ) ;
}
F_200 ( V_4 ,
F_201 ( V_263 -> V_3 -> V_49 ) ) ;
}
V_68 = F_174 ( V_201 -> V_266 , V_263 , V_67 , V_202 , V_203 ) ;
if ( V_68 != 0 )
goto V_129;
V_279 -> V_67 = V_67 ;
if ( V_4 -> V_49 == V_67 -> V_2 ) {
F_202 ( V_279 ) ;
if ( F_203 ( & V_201 -> V_350 , V_349 ) )
F_23 ( V_16 , V_67 ) ;
}
V_129:
return V_68 ;
}
static int F_204 ( struct V_2 * V_3 ,
struct V_278 * V_279 ,
int V_203 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_352 )
{
struct V_200 * V_201 ;
struct V_66 * V_67 = NULL ;
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_188 * V_263 ;
struct V_4 * V_4 = V_279 -> V_4 ;
struct V_293 * V_327 = V_279 -> V_327 ;
struct V_353 * * V_354 = & V_279 -> V_355 ;
T_5 V_202 = V_279 -> V_240 & ( V_71 | V_214 | V_356 ) ;
enum V_180 V_181 = V_183 ;
struct V_1 * V_357 = NULL ;
int V_283 ;
V_283 = - V_124 ;
V_201 = F_205 ( V_16 , V_327 , V_358 ) ;
if ( V_201 == NULL ) {
F_9 ( L_24 ) ;
goto V_359;
}
V_283 = F_179 ( V_16 ) ;
if ( V_283 != 0 )
goto V_360;
if ( V_4 -> V_49 != NULL )
F_124 ( V_4 -> V_49 , V_202 ) ;
V_283 = - V_124 ;
if ( V_4 -> V_49 )
V_181 = V_182 ;
V_263 = F_82 ( V_4 , V_201 , V_202 , V_203 , V_6 ,
V_7 , V_181 , V_358 ) ;
if ( V_263 == NULL )
goto V_360;
if ( V_7 ) {
V_357 = F_85 ( V_16 , V_358 ) ;
if ( F_41 ( V_357 ) ) {
V_283 = F_70 ( V_357 ) ;
goto V_361;
}
}
if ( V_354 && V_16 -> V_17 [ 2 ] & V_362 ) {
V_263 -> V_190 . V_355 = F_206 () ;
if ( ! V_263 -> V_190 . V_355 )
goto V_209;
V_263 -> V_193 . V_228 = & V_363 [ 0 ] ;
}
if ( V_4 -> V_49 != NULL )
V_263 -> V_67 = F_133 ( V_4 -> V_49 , V_201 ) ;
V_283 = F_196 ( V_263 , V_202 , V_203 , V_279 ) ;
if ( V_283 != 0 )
goto V_209;
V_67 = V_279 -> V_67 ;
if ( ( V_263 -> V_193 . V_213 & V_215 ) &&
( V_263 -> V_193 . V_306 != V_309 ) ) {
F_195 ( V_263 , V_6 ) ;
F_80 ( V_263 -> V_189 . V_190 ) ;
V_283 = F_207 ( V_67 -> V_2 , V_327 ,
V_263 -> V_189 . V_190 , V_6 ,
V_67 , V_7 , V_357 ) ;
if ( V_283 == 0 ) {
F_208 ( V_67 -> V_2 , V_6 ) ;
F_209 ( V_67 -> V_2 , V_263 -> V_189 . V_190 ) ;
F_135 ( V_67 -> V_2 , V_263 -> V_189 . V_190 , V_357 ) ;
}
}
if ( V_263 -> V_338 )
* V_352 |= V_364 ;
if ( F_210 ( V_354 , V_263 -> V_190 . V_355 , V_16 ) )
* V_354 = V_263 -> V_190 . V_355 ;
else
F_94 ( V_263 -> V_190 . V_355 ) ;
V_263 -> V_190 . V_355 = NULL ;
F_93 ( V_357 ) ;
F_103 ( V_263 ) ;
F_100 ( V_201 ) ;
return 0 ;
V_209:
F_93 ( V_357 ) ;
V_361:
F_94 ( V_263 -> V_190 . V_355 ) ;
F_103 ( V_263 ) ;
V_360:
F_100 ( V_201 ) ;
V_359:
return V_283 ;
}
static struct V_66 * F_211 ( struct V_2 * V_3 ,
struct V_278 * V_279 ,
int V_203 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_352 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_63 V_64 = { } ;
struct V_66 * V_57 ;
int V_283 ;
do {
V_283 = F_204 ( V_3 , V_279 , V_203 , V_6 , V_7 , V_352 ) ;
V_57 = V_279 -> V_67 ;
F_212 ( V_279 , V_203 , V_283 ) ;
if ( V_283 == 0 )
break;
if ( V_283 == - V_365 ) {
F_213 ( L_5
L_25 ,
F_3 ( V_3 ) -> V_10 -> V_97 ) ;
V_64 . V_69 = 1 ;
continue;
}
if ( V_283 == - V_75 ) {
V_64 . V_69 = 1 ;
continue;
}
if ( V_283 == - V_128 ) {
V_64 . V_69 = 1 ;
continue;
}
if ( F_77 ( V_16 , V_283 , & V_64 ) )
continue;
V_57 = F_42 ( F_20 ( V_16 ,
V_283 , & V_64 ) ) ;
} while ( V_64 . V_69 );
return V_57 ;
}
static int F_214 ( struct V_2 * V_2 , struct V_293 * V_327 ,
struct V_366 * V_367 , struct V_5 * V_6 ,
struct V_66 * V_67 , struct V_1 * V_368 ,
struct V_1 * V_357 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_369 V_370 = {
. V_230 = F_91 ( V_2 ) ,
. V_371 = V_6 ,
. V_16 = V_16 ,
. V_227 = V_16 -> V_17 ,
. V_7 = V_368 ,
} ;
struct V_372 V_57 = {
. V_367 = V_367 ,
. V_7 = V_357 ,
. V_16 = V_16 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_373 ] ,
. V_291 = & V_370 ,
. V_292 = & V_57 ,
. V_293 = V_327 ,
} ;
unsigned long V_104 = V_151 ;
T_5 V_202 ;
bool V_374 ;
int V_283 ;
V_370 . V_227 = F_7 ( V_16 , V_368 ) ;
if ( V_368 )
V_370 . V_227 = F_7 ( V_16 , V_357 ) ;
F_80 ( V_367 ) ;
V_374 = ( V_6 -> V_232 & V_375 ) ? true : false ;
V_202 = V_374 ? V_214 : V_71 ;
if ( F_215 ( & V_370 . V_236 , V_2 , V_202 ) ) {
} else if ( V_374 && V_67 != NULL && F_216 ( V_67 ) ) {
struct V_376 V_377 = {
. V_378 = V_60 -> V_379 ,
. V_380 = V_60 -> V_381 ,
} ;
F_217 ( & V_370 . V_236 , V_67 , V_214 ,
& V_377 ) ;
} else
F_113 ( & V_370 . V_236 , & V_382 ) ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & V_370 . V_156 , & V_57 . V_157 , 1 ) ;
if ( V_283 == 0 && V_67 != NULL )
F_35 ( V_16 , V_104 ) ;
return V_283 ;
}
static int F_207 ( struct V_2 * V_2 , struct V_293 * V_327 ,
struct V_366 * V_367 , struct V_5 * V_6 ,
struct V_66 * V_67 , struct V_1 * V_368 ,
struct V_1 * V_357 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_63 V_64 = {
. V_67 = V_67 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_214 ( V_2 , V_327 , V_367 , V_6 , V_67 , V_368 , V_357 ) ;
F_218 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_70 :
if ( ! ( V_6 -> V_232 & V_375 ) ) {
F_219 ( L_26
L_27
L_28
L_29 ,
V_16 -> V_10 -> V_97 ) ;
}
if ( V_67 && ! ( V_67 -> V_67 & V_214 ) ) {
V_8 = - V_383 ;
if ( V_6 -> V_232 & V_384 )
V_8 = - V_31 ;
goto V_129;
}
}
V_8 = F_20 ( V_16 , V_8 , & V_64 ) ;
} while ( V_64 . V_69 );
V_129:
return V_8 ;
}
static void F_220 ( void * V_154 )
{
struct V_385 * V_152 = V_154 ;
struct V_200 * V_201 = V_152 -> V_67 -> V_211 ;
struct V_238 * V_239 = V_152 -> V_67 -> V_2 -> V_386 ;
if ( V_152 -> V_387 )
F_221 ( V_152 -> V_67 -> V_2 ) ;
F_99 ( V_152 -> V_67 ) ;
F_98 ( V_152 -> V_370 . V_192 ) ;
F_100 ( V_201 ) ;
F_101 ( V_239 ) ;
F_94 ( V_152 ) ;
}
static void F_222 ( struct V_66 * V_67 ,
T_5 V_202 )
{
F_32 ( & V_67 -> V_211 -> V_258 ) ;
F_148 ( V_247 , & V_67 -> V_203 ) ;
switch ( V_202 & ( V_71 | V_214 ) ) {
case V_214 :
F_148 ( V_243 , & V_67 -> V_203 ) ;
break;
case V_71 :
F_148 ( V_245 , & V_67 -> V_203 ) ;
break;
case 0 :
F_148 ( V_243 , & V_67 -> V_203 ) ;
F_148 ( V_245 , & V_67 -> V_203 ) ;
F_148 ( V_255 , & V_67 -> V_203 ) ;
}
F_34 ( & V_67 -> V_211 -> V_258 ) ;
}
static void F_223 ( struct V_114 * V_115 , void * V_154 )
{
struct V_385 * V_152 = V_154 ;
struct V_66 * V_67 = V_152 -> V_67 ;
struct V_15 * V_16 = F_3 ( V_152 -> V_2 ) ;
F_9 ( L_30 , V_37 ) ;
if ( ! F_58 ( V_115 , & V_152 -> V_57 . V_157 ) )
return;
F_224 ( V_67 , & V_152 -> V_370 , & V_152 -> V_57 , V_115 -> V_146 ) ;
switch ( V_115 -> V_146 ) {
case 0 :
if ( V_152 -> V_387 )
F_225 ( V_67 -> V_2 ,
V_152 -> V_388 ) ;
F_115 ( V_67 , & V_152 -> V_57 . V_236 , 0 ) ;
F_35 ( V_16 , V_152 -> V_104 ) ;
F_222 ( V_67 ,
V_152 -> V_370 . V_202 ) ;
break;
case - V_77 :
case - V_93 :
case - V_75 :
case - V_76 :
if ( V_152 -> V_370 . V_202 == 0 )
break;
default:
if ( F_226 ( V_115 , V_16 , V_67 ) == - V_128 )
F_55 ( V_115 ) ;
}
F_126 ( V_152 -> V_370 . V_192 ) ;
F_134 ( V_152 -> V_2 , V_152 -> V_57 . V_367 ) ;
F_9 ( L_31 , V_37 , V_115 -> V_146 ) ;
}
static void F_227 ( struct V_114 * V_115 , void * V_154 )
{
struct V_385 * V_152 = V_154 ;
struct V_66 * V_67 = V_152 -> V_67 ;
struct V_2 * V_2 = V_152 -> V_2 ;
int V_389 = 0 ;
F_9 ( L_30 , V_37 ) ;
if ( F_167 ( V_152 -> V_370 . V_192 , V_115 ) != 0 )
goto V_300;
V_115 -> V_304 . V_288 = & V_289 [ V_390 ] ;
V_152 -> V_370 . V_202 = V_71 | V_214 ;
F_32 ( & V_67 -> V_211 -> V_258 ) ;
if ( V_67 -> V_248 == 0 ) {
if ( V_67 -> V_244 == 0 ) {
V_389 |= F_60 ( V_243 , & V_67 -> V_203 ) ;
V_389 |= F_60 ( V_247 , & V_67 -> V_203 ) ;
V_152 -> V_370 . V_202 &= ~ V_71 ;
}
if ( V_67 -> V_246 == 0 ) {
V_389 |= F_60 ( V_245 , & V_67 -> V_203 ) ;
V_389 |= F_60 ( V_247 , & V_67 -> V_203 ) ;
V_152 -> V_370 . V_202 &= ~ V_214 ;
}
}
if ( ! F_216 ( V_67 ) )
V_389 = 0 ;
F_34 ( & V_67 -> V_211 -> V_258 ) ;
if ( ! V_389 ) {
goto V_301;
}
if ( V_152 -> V_370 . V_202 == 0 ) {
V_115 -> V_304 . V_288 = & V_289 [ V_391 ] ;
if ( V_152 -> V_387 &&
F_228 ( V_2 , & V_152 -> V_388 , V_115 ) ) {
F_126 ( V_152 -> V_370 . V_192 ) ;
goto V_300;
}
}
F_80 ( V_152 -> V_57 . V_367 ) ;
V_152 -> V_104 = V_151 ;
if ( F_62 ( F_3 ( V_2 ) ,
& V_152 -> V_370 . V_156 ,
& V_152 -> V_57 . V_157 ,
V_115 ) != 0 )
F_126 ( V_152 -> V_370 . V_192 ) ;
F_9 ( L_32 , V_37 ) ;
return;
V_301:
V_115 -> V_312 = NULL ;
V_300:
F_58 ( V_115 , & V_152 -> V_57 . V_157 ) ;
}
int F_229 ( struct V_66 * V_67 , T_6 V_205 , int V_392 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
struct V_385 * V_152 ;
struct V_200 * V_201 = V_67 -> V_211 ;
struct V_114 * V_115 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_391 ] ,
. V_293 = V_67 -> V_211 -> V_266 ,
} ;
struct V_160 V_294 = {
. V_162 = V_16 -> V_91 ,
. V_158 = & V_159 ,
. V_163 = & V_393 ,
. V_296 = V_297 ,
. V_203 = V_298 ,
} ;
int V_283 = - V_124 ;
F_230 ( V_16 -> V_10 , V_394 ,
& V_294 . V_162 , & V_159 ) ;
V_152 = F_84 ( sizeof( * V_152 ) , V_205 ) ;
if ( V_152 == NULL )
goto V_129;
F_36 ( & V_152 -> V_370 . V_156 , & V_152 -> V_57 . V_157 , 1 ) ;
V_152 -> V_2 = V_67 -> V_2 ;
V_152 -> V_67 = V_67 ;
V_152 -> V_370 . V_230 = F_91 ( V_67 -> V_2 ) ;
V_152 -> V_370 . V_236 = & V_67 -> V_254 ;
V_152 -> V_370 . V_192 = F_86 ( & V_67 -> V_211 -> V_208 , V_205 ) ;
if ( V_152 -> V_370 . V_192 == NULL )
goto V_395;
V_152 -> V_370 . V_202 = 0 ;
V_152 -> V_370 . V_227 = V_16 -> V_396 ;
V_152 -> V_57 . V_367 = & V_152 -> V_367 ;
V_152 -> V_57 . V_192 = V_152 -> V_370 . V_192 ;
V_152 -> V_57 . V_16 = V_16 ;
V_152 -> V_387 = F_231 ( V_67 -> V_2 ) ;
F_87 ( V_152 -> V_2 -> V_386 ) ;
V_159 . V_291 = & V_152 -> V_370 ;
V_159 . V_292 = & V_152 -> V_57 ;
V_294 . V_166 = V_152 ;
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
V_283 = 0 ;
if ( V_392 )
V_283 = F_106 ( V_115 ) ;
F_71 ( V_115 ) ;
return V_283 ;
V_395:
F_94 ( V_152 ) ;
V_129:
F_99 ( V_67 ) ;
F_100 ( V_201 ) ;
return V_283 ;
}
static struct V_2 *
F_232 ( struct V_2 * V_3 , struct V_278 * V_279 ,
int V_213 , struct V_5 * V_397 , int * V_352 )
{
struct V_66 * V_67 ;
struct V_1 V_19 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_279 -> V_4 , V_397 , & V_19 ) ;
V_67 = F_211 ( V_3 , V_279 , V_213 , V_397 , V_7 , V_352 ) ;
F_5 ( V_7 ) ;
if ( F_41 ( V_67 ) )
return F_233 ( V_67 ) ;
return V_67 -> V_2 ;
}
static void F_234 ( struct V_278 * V_279 , int V_398 )
{
if ( V_279 -> V_67 == NULL )
return;
if ( V_398 )
F_235 ( V_279 -> V_67 , V_279 -> V_240 ) ;
else
F_146 ( V_279 -> V_67 , V_279 -> V_240 ) ;
}
static int F_236 ( struct V_15 * V_16 , struct V_399 * V_400 )
{
struct V_401 args = {
. V_400 = V_400 ,
} ;
struct V_402 V_57 = {} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_403 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
int V_283 ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
if ( V_283 == 0 ) {
memcpy ( V_16 -> V_17 , V_57 . V_17 , sizeof( V_16 -> V_17 ) ) ;
V_16 -> V_94 &= ~ ( V_404 | V_405 |
V_406 | V_407 |
V_408 | V_409 | V_410 |
V_411 | V_412 |
V_413 | V_414 ) ;
if ( V_57 . V_17 [ 0 ] & V_415 )
V_16 -> V_94 |= V_404 ;
if ( V_57 . V_416 != 0 )
V_16 -> V_94 |= V_405 ;
if ( V_57 . V_417 != 0 )
V_16 -> V_94 |= V_406 ;
if ( V_57 . V_17 [ 0 ] & V_48 )
V_16 -> V_94 |= V_407 ;
if ( V_57 . V_17 [ 1 ] & V_418 )
V_16 -> V_94 |= V_408 ;
if ( V_57 . V_17 [ 1 ] & V_419 )
V_16 -> V_94 |= V_409 ;
if ( V_57 . V_17 [ 1 ] & V_420 )
V_16 -> V_94 |= V_410 ;
if ( V_57 . V_17 [ 1 ] & V_421 )
V_16 -> V_94 |= V_411 ;
if ( V_57 . V_17 [ 1 ] & V_343 )
V_16 -> V_94 |= V_412 ;
if ( V_57 . V_17 [ 1 ] & V_422 )
V_16 -> V_94 |= V_413 ;
if ( V_57 . V_17 [ 1 ] & V_346 )
V_16 -> V_94 |= V_414 ;
#ifdef F_237
if ( V_57 . V_17 [ 2 ] & V_423 )
V_16 -> V_94 |= V_9 ;
#endif
memcpy ( V_16 -> V_18 , V_57 . V_17 ,
sizeof( V_16 -> V_17 ) ) ;
if ( V_16 -> V_94 & V_9 ) {
V_16 -> V_18 [ 2 ] &= ~ V_423 ;
V_57 . V_17 [ 2 ] &= ~ V_423 ;
}
memcpy ( V_16 -> V_396 , V_57 . V_17 , sizeof( V_16 -> V_396 ) ) ;
V_16 -> V_396 [ 0 ] &= V_424 | V_425 ;
V_16 -> V_396 [ 1 ] &= V_422 | V_346 ;
V_16 -> V_426 = V_57 . V_426 ;
V_16 -> V_427 = V_57 . V_427 ;
}
return V_283 ;
}
int F_238 ( struct V_15 * V_16 , struct V_399 * V_400 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_236 ( V_16 , V_400 ) ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_239 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_429 )
{
T_1 V_227 [ 3 ] ;
struct V_430 args = {
. V_227 = V_227 ,
} ;
struct V_431 V_57 = {
. V_16 = V_16 ,
. V_367 = V_429 -> V_367 ,
. V_230 = V_400 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_432 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
V_227 [ 0 ] = V_229 [ 0 ] ;
V_227 [ 1 ] = V_229 [ 1 ] ;
V_227 [ 2 ] = V_229 [ 2 ] & ~ V_423 ;
F_80 ( V_429 -> V_367 ) ;
return F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
}
static int F_240 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_429 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_239 ( V_16 , V_400 , V_429 ) ;
F_241 ( V_16 , V_400 , V_429 -> V_367 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_24 :
goto V_129;
default:
V_8 = F_20 ( V_16 , V_8 , & V_64 ) ;
}
} while ( V_64 . V_69 );
V_129:
return V_8 ;
}
static int F_242 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_429 , T_4 V_98 )
{
struct V_433 V_434 = {
. V_435 = V_98 ,
} ;
struct V_436 * V_437 ;
int V_68 ;
V_437 = F_243 ( & V_434 , V_16 -> V_91 ) ;
if ( F_41 ( V_437 ) ) {
V_68 = - V_31 ;
goto V_129;
}
V_68 = F_240 ( V_16 , V_400 , V_429 ) ;
V_129:
return V_68 ;
}
static int F_244 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_429 )
{
static const T_4 V_438 [] = {
V_103 ,
V_102 ,
V_439 ,
V_440 ,
V_441 ,
} ;
int V_283 = - V_26 ;
T_9 V_442 ;
for ( V_442 = 0 ; V_442 < F_245 ( V_438 ) ; V_442 ++ ) {
V_283 = F_242 ( V_16 , V_400 , V_429 , V_438 [ V_442 ] ) ;
if ( V_283 == - V_24 || V_283 == - V_31 )
continue;
break;
}
if ( V_283 == - V_31 )
V_283 = - V_26 ;
return V_283 ;
}
static int F_246 ( struct V_15 * V_16 ,
struct V_399 * V_400 , struct V_428 * V_429 )
{
int V_443 = V_16 -> V_10 -> V_11 ;
return V_444 [ V_443 ] -> F_247 ( V_16 , V_400 , V_429 ) ;
}
int F_248 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_429 ,
bool V_445 )
{
int V_283 ;
switch ( V_445 ) {
case false :
V_283 = F_240 ( V_16 , V_400 , V_429 ) ;
if ( V_283 != - V_24 )
break;
if ( V_16 -> V_203 & V_446 )
break;
default:
V_283 = F_246 ( V_16 , V_400 , V_429 ) ;
}
if ( V_283 == 0 )
V_283 = F_238 ( V_16 , V_400 ) ;
if ( V_283 == 0 )
V_283 = F_249 ( V_16 , V_400 , V_429 ) ;
return F_8 ( V_283 ) ;
}
static int F_250 ( struct V_15 * V_16 , struct V_399 * V_447 ,
struct V_428 * V_429 )
{
int error ;
struct V_366 * V_367 = V_429 -> V_367 ;
struct V_1 * V_7 = NULL ;
error = F_238 ( V_16 , V_447 ) ;
if ( error < 0 ) {
F_9 ( L_33 , - error ) ;
return error ;
}
V_7 = F_85 ( V_16 , V_358 ) ;
if ( F_41 ( V_7 ) )
return F_70 ( V_7 ) ;
error = F_251 ( V_16 , V_447 , V_367 , V_7 ) ;
if ( error < 0 ) {
F_9 ( L_34 , - error ) ;
goto V_209;
}
if ( V_367 -> V_271 & V_448 &&
! F_252 ( & V_16 -> V_449 , & V_367 -> V_449 ) )
memcpy ( & V_16 -> V_449 , & V_367 -> V_449 , sizeof( V_16 -> V_449 ) ) ;
V_209:
F_93 ( V_7 ) ;
return error ;
}
static int F_253 ( struct V_54 * V_91 , struct V_2 * V_3 ,
const struct V_450 * V_226 , struct V_366 * V_367 ,
struct V_399 * V_400 )
{
int V_283 = - V_124 ;
struct V_451 * V_451 = NULL ;
struct V_452 * V_453 = NULL ;
V_451 = F_254 ( V_358 ) ;
if ( V_451 == NULL )
goto V_129;
V_453 = F_255 ( sizeof( struct V_452 ) , V_358 ) ;
if ( V_453 == NULL )
goto V_129;
V_283 = F_256 ( V_91 , V_3 , V_226 , V_453 , V_451 ) ;
if ( V_283 != 0 )
goto V_129;
if ( F_252 ( & F_3 ( V_3 ) -> V_449 , & V_453 -> V_367 . V_449 ) ) {
F_9 ( L_35
L_36 , V_37 , V_226 -> V_226 ) ;
V_283 = - V_38 ;
goto V_129;
}
F_257 ( & V_453 -> V_367 ) ;
memcpy ( V_367 , & V_453 -> V_367 , sizeof( struct V_366 ) ) ;
memset ( V_400 , 0 , sizeof( struct V_399 ) ) ;
V_129:
if ( V_451 )
F_258 ( V_451 ) ;
F_94 ( V_453 ) ;
return V_283 ;
}
static int F_178 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_366 * V_367 , struct V_1 * V_7 )
{
struct V_454 args = {
. V_230 = V_400 ,
. V_227 = V_16 -> V_17 ,
} ;
struct V_455 V_57 = {
. V_367 = V_367 ,
. V_7 = V_7 ,
. V_16 = V_16 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_456 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
args . V_227 = F_7 ( V_16 , V_7 ) ;
F_80 ( V_367 ) ;
return F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
}
static int F_251 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_366 * V_367 , struct V_1 * V_7 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_178 ( V_16 , V_400 , V_367 , V_7 ) ;
F_259 ( V_16 , V_400 , V_367 , V_8 ) ;
V_8 = F_20 ( V_16 , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int
F_260 ( struct V_4 * V_4 , struct V_366 * V_367 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = V_4 -> V_49 ;
struct V_293 * V_327 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_1 * V_7 = NULL ;
int V_283 ;
if ( F_261 ( V_2 ) )
F_262 ( V_2 ) ;
F_80 ( V_367 ) ;
if ( V_6 -> V_232 & V_384 )
V_6 -> V_232 &= ~ ( V_348 | V_457 ) ;
if ( ( V_6 -> V_232 & ~ ( V_458 | V_384 ) ) == 0 )
return 0 ;
if ( V_6 -> V_232 & V_458 ) {
struct V_278 * V_279 ;
V_279 = F_263 ( V_6 -> V_459 ) ;
if ( V_279 ) {
V_327 = V_279 -> V_327 ;
V_67 = V_279 -> V_67 ;
}
}
V_7 = F_85 ( F_3 ( V_2 ) , V_358 ) ;
if ( F_41 ( V_7 ) )
return F_70 ( V_7 ) ;
V_283 = F_207 ( V_2 , V_327 , V_367 , V_6 , V_67 , NULL , V_7 ) ;
if ( V_283 == 0 ) {
F_208 ( V_2 , V_6 ) ;
F_135 ( V_2 , V_367 , V_7 ) ;
}
F_93 ( V_7 ) ;
return V_283 ;
}
static int F_264 ( struct V_54 * V_55 , struct V_2 * V_3 ,
const struct V_450 * V_226 , struct V_399 * V_400 ,
struct V_366 * V_367 , struct V_1 * V_7 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
int V_283 ;
struct V_460 args = {
. V_227 = V_16 -> V_17 ,
. V_461 = F_91 ( V_3 ) ,
. V_226 = V_226 ,
} ;
struct V_431 V_57 = {
. V_16 = V_16 ,
. V_367 = V_367 ,
. V_7 = V_7 ,
. V_230 = V_400 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_462 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
args . V_227 = F_7 ( V_16 , V_7 ) ;
F_80 ( V_367 ) ;
F_9 ( L_37 , V_226 -> V_226 ) ;
V_283 = F_72 ( V_55 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
F_9 ( L_38 , V_283 ) ;
return V_283 ;
}
static void F_265 ( struct V_366 * V_367 )
{
V_367 -> V_271 |= V_272 | V_463 |
V_464 | V_465 ;
V_367 -> V_240 = V_317 | V_466 | V_467 ;
V_367 -> V_468 = 2 ;
}
static int F_266 ( struct V_54 * * V_55 , struct V_2 * V_3 ,
struct V_450 * V_226 , struct V_399 * V_400 ,
struct V_366 * V_367 , struct V_1 * V_7 )
{
struct V_63 V_64 = { } ;
struct V_54 * V_91 = * V_55 ;
int V_8 ;
do {
V_8 = F_264 ( V_91 , V_3 , V_226 , V_400 , V_367 , V_7 ) ;
F_267 ( V_3 , V_226 , V_8 ) ;
switch ( V_8 ) {
case - V_28 :
V_8 = - V_280 ;
goto V_129;
case - V_469 :
V_8 = F_253 ( V_91 , V_3 , V_226 , V_367 , V_400 ) ;
goto V_129;
case - V_24 :
V_8 = - V_26 ;
if ( V_91 != * V_55 )
goto V_129;
if ( F_3 ( V_3 ) -> V_203 & V_446 )
goto V_129;
V_91 = F_268 ( V_91 , V_3 , V_226 ) ;
if ( F_41 ( V_91 ) )
return F_70 ( V_91 ) ;
V_64 . V_69 = 1 ;
break;
default:
V_8 = F_20 ( F_3 ( V_3 ) , V_8 , & V_64 ) ;
}
} while ( V_64 . V_69 );
V_129:
if ( V_8 == 0 )
* V_55 = V_91 ;
else if ( V_91 != * V_55 )
F_269 ( V_91 ) ;
return V_8 ;
}
static int F_270 ( struct V_2 * V_3 , struct V_450 * V_226 ,
struct V_399 * V_400 , struct V_366 * V_367 ,
struct V_1 * V_7 )
{
int V_283 ;
struct V_54 * V_91 = F_271 ( V_3 ) ;
V_283 = F_266 ( & V_91 , V_3 , V_226 , V_400 , V_367 , V_7 ) ;
if ( V_91 != F_271 ( V_3 ) ) {
F_269 ( V_91 ) ;
F_265 ( V_367 ) ;
}
return V_283 ;
}
struct V_54 *
F_272 ( struct V_2 * V_3 , struct V_450 * V_226 ,
struct V_399 * V_400 , struct V_366 * V_367 )
{
struct V_54 * V_91 = F_271 ( V_3 ) ;
int V_283 ;
V_283 = F_266 ( & V_91 , V_3 , V_226 , V_400 , V_367 , NULL ) ;
if ( V_283 < 0 )
return F_42 ( V_283 ) ;
return ( V_91 == F_271 ( V_3 ) ) ? F_273 ( V_91 ) : V_91 ;
}
static int F_274 ( struct V_2 * V_2 , struct V_329 * V_470 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_471 args = {
. V_230 = F_91 ( V_2 ) ,
. V_227 = V_16 -> V_396 ,
} ;
struct V_472 V_57 = {
. V_16 = V_16 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_473 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
. V_293 = V_470 -> V_327 ,
} ;
int V_240 = V_470 -> V_331 ;
int V_283 = 0 ;
if ( V_240 & V_335 )
args . V_197 |= V_216 ;
if ( F_275 ( V_2 -> V_474 ) ) {
if ( V_240 & V_475 )
args . V_197 |= V_217 | V_218 | V_476 ;
if ( V_240 & V_334 )
args . V_197 |= V_477 ;
} else {
if ( V_240 & V_475 )
args . V_197 |= V_217 | V_218 ;
if ( V_240 & V_334 )
args . V_197 |= V_219 ;
}
V_57 . V_367 = F_276 () ;
if ( V_57 . V_367 == NULL )
return - V_124 ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
if ( ! V_283 ) {
F_175 ( V_470 , V_57 . V_197 ) ;
F_134 ( V_2 , V_57 . V_367 ) ;
}
F_277 ( V_57 . V_367 ) ;
return V_283 ;
}
static int F_278 ( struct V_2 * V_2 , struct V_329 * V_470 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_274 ( V_2 , V_470 ) ;
F_279 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_2 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_280 ( struct V_2 * V_2 , struct V_451 * V_451 ,
unsigned int V_52 , unsigned int V_478 )
{
struct V_479 args = {
. V_230 = F_91 ( V_2 ) ,
. V_52 = V_52 ,
. V_478 = V_478 ,
. V_45 = & V_451 ,
} ;
struct V_480 V_57 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_481 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
return F_72 ( F_3 ( V_2 ) -> V_91 , F_3 ( V_2 ) , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
}
static int F_281 ( struct V_2 * V_2 , struct V_451 * V_451 ,
unsigned int V_52 , unsigned int V_478 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_280 ( V_2 , V_451 , V_52 , V_478 ) ;
F_282 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_2 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int
F_283 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_203 )
{
struct V_1 V_19 , * V_368 = NULL ;
struct V_278 * V_279 ;
struct V_66 * V_67 ;
int V_352 = 0 ;
int V_283 = 0 ;
V_279 = F_284 ( V_4 , V_71 ) ;
if ( F_41 ( V_279 ) )
return F_70 ( V_279 ) ;
V_368 = F_1 ( V_3 , V_4 , V_6 , & V_19 ) ;
V_6 -> V_12 &= ~ F_285 () ;
V_67 = F_211 ( V_3 , V_279 , V_203 , V_6 , V_368 , & V_352 ) ;
if ( F_41 ( V_67 ) ) {
V_283 = F_70 ( V_67 ) ;
goto V_129;
}
V_129:
F_5 ( V_368 ) ;
F_154 ( V_279 ) ;
return V_283 ;
}
static int F_286 ( struct V_2 * V_3 , struct V_450 * V_226 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_482 args = {
. V_230 = F_91 ( V_3 ) ,
. V_226 = * V_226 ,
} ;
struct V_483 V_57 = {
. V_16 = V_16 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_484 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
int V_283 ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 1 ) ;
if ( V_283 == 0 )
F_73 ( V_3 , & V_57 . V_168 ) ;
return V_283 ;
}
static int F_287 ( struct V_2 * V_3 , struct V_450 * V_226 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_286 ( V_3 , V_226 ) ;
F_288 ( V_3 , V_226 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_3 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static void F_289 ( struct V_158 * V_159 , struct V_2 * V_3 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_482 * args = V_159 -> V_291 ;
struct V_483 * V_57 = V_159 -> V_292 ;
V_57 -> V_16 = V_16 ;
V_159 -> V_288 = & V_289 [ V_484 ] ;
F_36 ( & args -> V_156 , & V_57 -> V_157 , 1 ) ;
F_80 ( V_57 -> V_485 ) ;
}
static void F_290 ( struct V_114 * V_115 , struct V_486 * V_154 )
{
F_62 ( F_3 ( V_154 -> V_3 ) ,
& V_154 -> args . V_156 ,
& V_154 -> V_57 . V_157 ,
V_115 ) ;
}
static int F_291 ( struct V_114 * V_115 , struct V_2 * V_3 )
{
struct V_486 * V_154 = V_115 -> V_487 ;
struct V_483 * V_57 = & V_154 -> V_57 ;
if ( ! F_58 ( V_115 , & V_57 -> V_157 ) )
return 0 ;
if ( F_226 ( V_115 , V_57 -> V_16 , NULL ) == - V_128 )
return 0 ;
F_73 ( V_3 , & V_57 -> V_168 ) ;
return 1 ;
}
static void F_292 ( struct V_158 * V_159 , struct V_2 * V_3 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_488 * V_370 = V_159 -> V_291 ;
struct V_489 * V_57 = V_159 -> V_292 ;
V_159 -> V_288 = & V_289 [ V_490 ] ;
V_57 -> V_16 = V_16 ;
F_36 ( & V_370 -> V_156 , & V_57 -> V_157 , 1 ) ;
}
static void F_293 ( struct V_114 * V_115 , struct V_491 * V_154 )
{
F_62 ( F_3 ( V_154 -> V_492 ) ,
& V_154 -> args . V_156 ,
& V_154 -> V_57 . V_157 ,
V_115 ) ;
}
static int F_294 ( struct V_114 * V_115 , struct V_2 * V_492 ,
struct V_2 * V_493 )
{
struct V_491 * V_154 = V_115 -> V_487 ;
struct V_489 * V_57 = & V_154 -> V_57 ;
if ( ! F_58 ( V_115 , & V_57 -> V_157 ) )
return 0 ;
if ( F_226 ( V_115 , V_57 -> V_16 , NULL ) == - V_128 )
return 0 ;
F_73 ( V_492 , & V_57 -> V_494 ) ;
F_73 ( V_493 , & V_57 -> V_495 ) ;
return 1 ;
}
static int F_295 ( struct V_2 * V_492 , struct V_450 * V_496 ,
struct V_2 * V_493 , struct V_450 * V_497 )
{
struct V_15 * V_16 = F_3 ( V_492 ) ;
struct V_488 V_370 = {
. V_492 = F_91 ( V_492 ) ,
. V_493 = F_91 ( V_493 ) ,
. V_496 = V_496 ,
. V_497 = V_497 ,
} ;
struct V_489 V_57 = {
. V_16 = V_16 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_490 ] ,
. V_291 = & V_370 ,
. V_292 = & V_57 ,
} ;
int V_283 = - V_124 ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & V_370 . V_156 , & V_57 . V_157 , 1 ) ;
if ( ! V_283 ) {
F_73 ( V_492 , & V_57 . V_494 ) ;
F_73 ( V_493 , & V_57 . V_495 ) ;
}
return V_283 ;
}
static int F_296 ( struct V_2 * V_492 , struct V_450 * V_496 ,
struct V_2 * V_493 , struct V_450 * V_497 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_295 ( V_492 , V_496 ,
V_493 , V_497 ) ;
F_297 ( V_492 , V_496 , V_493 , V_497 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_492 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_298 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_450 * V_226 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_498 V_370 = {
. V_230 = F_91 ( V_2 ) ,
. V_461 = F_91 ( V_3 ) ,
. V_226 = V_226 ,
. V_227 = V_16 -> V_17 ,
} ;
struct V_499 V_57 = {
. V_16 = V_16 ,
. V_7 = NULL ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_500 ] ,
. V_291 = & V_370 ,
. V_292 = & V_57 ,
} ;
int V_283 = - V_124 ;
V_57 . V_367 = F_276 () ;
if ( V_57 . V_367 == NULL )
goto V_129;
V_57 . V_7 = F_85 ( V_16 , V_358 ) ;
if ( F_41 ( V_57 . V_7 ) ) {
V_283 = F_70 ( V_57 . V_7 ) ;
goto V_129;
}
V_370 . V_227 = F_7 ( V_16 , V_57 . V_7 ) ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & V_370 . V_156 , & V_57 . V_157 , 1 ) ;
if ( ! V_283 ) {
F_73 ( V_3 , & V_57 . V_168 ) ;
V_283 = F_209 ( V_2 , V_57 . V_367 ) ;
if ( ! V_283 )
F_135 ( V_2 , V_57 . V_367 , V_57 . V_7 ) ;
}
F_93 ( V_57 . V_7 ) ;
V_129:
F_277 ( V_57 . V_367 ) ;
return V_283 ;
}
static int F_299 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_450 * V_226 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_2 ) ,
F_298 ( V_2 , V_3 , V_226 ) ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static struct V_501 * F_300 ( struct V_2 * V_3 ,
struct V_450 * V_226 , struct V_5 * V_6 , T_1 V_502 )
{
struct V_501 * V_154 ;
V_154 = F_84 ( sizeof( * V_154 ) , V_358 ) ;
if ( V_154 != NULL ) {
struct V_15 * V_16 = F_3 ( V_3 ) ;
V_154 -> V_7 = F_85 ( V_16 , V_358 ) ;
if ( F_41 ( V_154 -> V_7 ) )
goto V_287;
V_154 -> V_159 . V_288 = & V_289 [ V_503 ] ;
V_154 -> V_159 . V_291 = & V_154 -> V_370 ;
V_154 -> V_159 . V_292 = & V_154 -> V_57 ;
V_154 -> V_370 . V_461 = F_91 ( V_3 ) ;
V_154 -> V_370 . V_16 = V_16 ;
V_154 -> V_370 . V_226 = V_226 ;
V_154 -> V_370 . V_204 = V_6 ;
V_154 -> V_370 . V_502 = V_502 ;
V_154 -> V_370 . V_227 = F_7 ( V_16 , V_154 -> V_7 ) ;
V_154 -> V_57 . V_16 = V_16 ;
V_154 -> V_57 . V_230 = & V_154 -> V_230 ;
V_154 -> V_57 . V_367 = & V_154 -> V_367 ;
V_154 -> V_57 . V_7 = V_154 -> V_7 ;
F_80 ( V_154 -> V_57 . V_367 ) ;
}
return V_154 ;
V_287:
F_94 ( V_154 ) ;
return NULL ;
}
static int F_301 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_501 * V_154 )
{
int V_283 = F_72 ( F_3 ( V_3 ) -> V_91 , F_3 ( V_3 ) , & V_154 -> V_159 ,
& V_154 -> V_370 . V_156 , & V_154 -> V_57 . V_157 , 1 ) ;
if ( V_283 == 0 ) {
F_73 ( V_3 , & V_154 -> V_57 . V_504 ) ;
V_283 = F_302 ( V_4 , V_154 -> V_57 . V_230 , V_154 -> V_57 . V_367 , V_154 -> V_57 . V_7 ) ;
}
return V_283 ;
}
static void F_303 ( struct V_501 * V_154 )
{
F_93 ( V_154 -> V_7 ) ;
F_94 ( V_154 ) ;
}
static int F_304 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_451 * V_451 , unsigned int V_14 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_501 * V_154 ;
int V_283 = - V_505 ;
if ( V_14 > V_506 )
goto V_129;
V_283 = - V_124 ;
V_154 = F_300 ( V_3 , & V_4 -> V_13 , V_6 , V_507 ) ;
if ( V_154 == NULL )
goto V_129;
V_154 -> V_159 . V_288 = & V_289 [ V_508 ] ;
V_154 -> V_370 . V_234 . V_509 . V_45 = & V_451 ;
V_154 -> V_370 . V_234 . V_509 . V_14 = V_14 ;
V_154 -> V_370 . V_7 = V_7 ;
V_283 = F_301 ( V_3 , V_4 , V_154 ) ;
F_303 ( V_154 ) ;
V_129:
return V_283 ;
}
static int F_305 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_451 * V_451 , unsigned int V_14 , struct V_5 * V_6 )
{
struct V_63 V_64 = { } ;
struct V_1 V_19 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_19 ) ;
do {
V_8 = F_304 ( V_3 , V_4 , V_451 , V_14 , V_6 , V_7 ) ;
F_306 ( V_3 , & V_4 -> V_13 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_3 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
F_5 ( V_7 ) ;
return V_8 ;
}
static int F_307 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_501 * V_154 ;
int V_283 = - V_124 ;
V_154 = F_300 ( V_3 , & V_4 -> V_13 , V_6 , V_510 ) ;
if ( V_154 == NULL )
goto V_129;
V_154 -> V_370 . V_7 = V_7 ;
V_283 = F_301 ( V_3 , V_4 , V_154 ) ;
F_303 ( V_154 ) ;
V_129:
return V_283 ;
}
static int F_308 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_63 V_64 = { } ;
struct V_1 V_19 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_19 ) ;
V_6 -> V_12 &= ~ F_285 () ;
do {
V_8 = F_307 ( V_3 , V_4 , V_6 , V_7 ) ;
F_309 ( V_3 , & V_4 -> V_13 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_3 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
F_5 ( V_7 ) ;
return V_8 ;
}
static int F_310 ( struct V_4 * V_4 , struct V_293 * V_327 ,
T_2 V_39 , struct V_451 * * V_45 , unsigned int V_53 , int V_511 )
{
struct V_2 * V_3 = V_4 -> V_49 ;
struct V_41 args = {
. V_230 = F_91 ( V_3 ) ,
. V_45 = V_45 ,
. V_52 = 0 ,
. V_53 = V_53 ,
. V_227 = F_3 ( V_4 -> V_49 ) -> V_17 ,
. V_511 = V_511 ,
} ;
struct V_512 V_57 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_513 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
. V_293 = V_327 ,
} ;
int V_283 ;
F_9 ( L_39 , V_37 ,
V_4 -> V_51 -> V_13 . V_226 ,
V_4 -> V_13 . V_226 ,
( unsigned long long ) V_39 ) ;
F_10 ( V_39 , F_74 ( V_3 ) -> V_514 , V_4 , & args ) ;
V_57 . V_52 = args . V_52 ;
V_283 = F_72 ( F_3 ( V_3 ) -> V_91 , F_3 ( V_3 ) , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
if ( V_283 >= 0 ) {
memcpy ( F_74 ( V_3 ) -> V_514 , V_57 . V_40 . V_154 , V_515 ) ;
V_283 += args . V_52 ;
}
F_311 ( V_3 ) ;
F_9 ( L_40 , V_37 , V_283 ) ;
return V_283 ;
}
static int F_312 ( struct V_4 * V_4 , struct V_293 * V_327 ,
T_2 V_39 , struct V_451 * * V_45 , unsigned int V_53 , int V_511 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_310 ( V_4 , V_327 , V_39 ,
V_45 , V_53 , V_511 ) ;
F_313 ( V_4 -> V_49 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_4 -> V_49 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_314 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_516 )
{
struct V_501 * V_154 ;
int V_240 = V_6 -> V_12 ;
int V_283 = - V_124 ;
V_154 = F_300 ( V_3 , & V_4 -> V_13 , V_6 , V_517 ) ;
if ( V_154 == NULL )
goto V_129;
if ( F_315 ( V_240 ) )
V_154 -> V_370 . V_502 = V_518 ;
else if ( F_316 ( V_240 ) ) {
V_154 -> V_370 . V_502 = V_519 ;
V_154 -> V_370 . V_234 . V_520 . V_521 = F_317 ( V_516 ) ;
V_154 -> V_370 . V_234 . V_520 . V_522 = F_318 ( V_516 ) ;
}
else if ( F_319 ( V_240 ) ) {
V_154 -> V_370 . V_502 = V_523 ;
V_154 -> V_370 . V_234 . V_520 . V_521 = F_317 ( V_516 ) ;
V_154 -> V_370 . V_234 . V_520 . V_522 = F_318 ( V_516 ) ;
} else if ( ! F_320 ( V_240 ) ) {
V_283 = - V_29 ;
goto V_287;
}
V_154 -> V_370 . V_7 = V_7 ;
V_283 = F_301 ( V_3 , V_4 , V_154 ) ;
V_287:
F_303 ( V_154 ) ;
V_129:
return V_283 ;
}
static int F_321 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_516 )
{
struct V_63 V_64 = { } ;
struct V_1 V_19 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_19 ) ;
V_6 -> V_12 &= ~ F_285 () ;
do {
V_8 = F_314 ( V_3 , V_4 , V_6 , V_7 , V_516 ) ;
F_322 ( V_3 , & V_4 -> V_13 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_3 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
F_5 ( V_7 ) ;
return V_8 ;
}
static int F_323 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_524 * V_525 )
{
struct V_526 args = {
. V_230 = V_400 ,
. V_227 = V_16 -> V_17 ,
} ;
struct V_527 V_57 = {
. V_525 = V_525 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_528 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
F_80 ( V_525 -> V_367 ) ;
return F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
}
static int F_324 ( struct V_15 * V_16 , struct V_399 * V_400 , struct V_524 * V_525 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_323 ( V_16 , V_400 , V_525 ) ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_325 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_529 )
{
struct V_530 args = {
. V_230 = V_400 ,
. V_227 = V_16 -> V_17 ,
} ;
struct V_531 V_57 = {
. V_529 = V_529 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_532 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
return F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
}
static int F_249 ( struct V_15 * V_16 , struct V_399 * V_400 , struct V_428 * V_529 )
{
struct V_63 V_64 = { } ;
unsigned long V_533 = V_151 ;
int V_8 ;
do {
V_8 = F_325 ( V_16 , V_400 , V_529 ) ;
F_326 ( V_16 , V_400 , V_529 -> V_367 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_10 * V_65 = V_16 -> V_10 ;
F_32 ( & V_65 -> V_105 ) ;
V_65 -> V_534 = V_529 -> V_535 * V_88 ;
V_65 -> V_106 = V_533 ;
F_34 ( & V_65 -> V_105 ) ;
break;
}
V_8 = F_20 ( V_16 , V_8 , & V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_327 ( struct V_15 * V_16 , struct V_399 * V_400 , struct V_428 * V_529 )
{
int error ;
F_80 ( V_529 -> V_367 ) ;
error = F_249 ( V_16 , V_400 , V_529 ) ;
if ( error == 0 ) {
V_16 -> V_536 = V_529 -> V_537 ;
F_328 ( V_16 , V_400 , V_529 -> V_538 ) ;
}
return error ;
}
static int F_329 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_539 * V_540 )
{
struct V_541 args = {
. V_230 = V_400 ,
. V_227 = V_16 -> V_17 ,
} ;
struct V_542 V_57 = {
. V_540 = V_540 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_543 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
if ( ( args . V_227 [ 0 ] & V_544 [ 0 ] ) == 0 ) {
memset ( V_540 , 0 , sizeof( * V_540 ) ) ;
return 0 ;
}
F_80 ( V_540 -> V_367 ) ;
return F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
}
static int F_330 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_539 * V_540 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_329 ( V_16 , V_400 , V_540 ) ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
int F_331 ( T_8 * V_236 ,
const struct V_278 * V_279 ,
const struct V_545 * V_546 ,
T_5 V_202 )
{
const struct V_376 * V_377 = NULL ;
if ( V_546 != NULL )
V_377 = & V_546 -> V_377 ;
return F_217 ( V_236 , V_279 -> V_67 , V_202 , V_377 ) ;
}
static bool F_332 ( T_8 * V_236 ,
const struct V_278 * V_279 ,
const struct V_545 * V_546 ,
T_5 V_202 )
{
T_8 V_547 ;
if ( F_331 ( & V_547 , V_279 , V_546 , V_202 ) )
return false ;
return F_122 ( V_236 , & V_547 ) ;
}
static bool F_333 ( int V_8 )
{
switch ( V_8 ) {
case - V_73 :
case - V_74 :
case - V_75 :
case - V_77 :
case - V_93 :
case - V_70 :
case - V_76 :
return true ;
}
return false ;
}
void F_334 ( struct V_548 * V_154 )
{
F_311 ( V_154 -> V_549 -> V_2 ) ;
}
static int F_335 ( struct V_114 * V_115 , struct V_548 * V_154 )
{
struct V_15 * V_16 = F_3 ( V_154 -> V_549 -> V_2 ) ;
F_336 ( V_154 , V_115 -> V_146 ) ;
if ( F_226 ( V_115 , V_16 , V_154 -> args . V_550 -> V_67 ) == - V_128 ) {
F_55 ( V_115 ) ;
return - V_128 ;
}
F_334 ( V_154 ) ;
if ( V_115 -> V_146 > 0 )
F_35 ( V_16 , V_154 -> V_104 ) ;
return 0 ;
}
static bool F_337 ( struct V_114 * V_115 ,
struct V_551 * args )
{
if ( ! F_333 ( V_115 -> V_146 ) ||
F_332 ( & args -> V_236 ,
args -> V_550 ,
args -> V_552 ,
V_71 ) )
return false ;
F_55 ( V_115 ) ;
return true ;
}
static int F_338 ( struct V_114 * V_115 , struct V_548 * V_154 )
{
F_9 ( L_12 , V_37 ) ;
if ( ! F_58 ( V_115 , & V_154 -> V_57 . V_157 ) )
return - V_128 ;
if ( F_337 ( V_115 , & V_154 -> args ) )
return - V_128 ;
return V_154 -> V_553 ? V_154 -> V_553 ( V_115 , V_154 ) :
F_335 ( V_115 , V_154 ) ;
}
static void F_339 ( struct V_548 * V_154 , struct V_158 * V_159 )
{
V_154 -> V_104 = V_151 ;
V_154 -> V_553 = F_335 ;
V_159 -> V_288 = & V_289 [ V_554 ] ;
F_36 ( & V_154 -> args . V_156 , & V_154 -> V_57 . V_157 , 0 ) ;
}
static int F_340 ( struct V_114 * V_115 , struct V_548 * V_154 )
{
if ( F_62 ( F_3 ( V_154 -> V_549 -> V_2 ) ,
& V_154 -> args . V_156 ,
& V_154 -> V_57 . V_157 ,
V_115 ) )
return 0 ;
if ( F_331 ( & V_154 -> args . V_236 , V_154 -> args . V_550 ,
V_154 -> args . V_552 , V_71 ) == - V_38 )
return - V_38 ;
if ( F_341 ( F_60 ( V_555 , & V_154 -> args . V_550 -> V_203 ) ) )
return - V_38 ;
return 0 ;
}
static int F_342 ( struct V_114 * V_115 , struct V_556 * V_154 )
{
struct V_2 * V_2 = V_154 -> V_549 -> V_2 ;
F_343 ( V_154 , V_115 -> V_146 ) ;
if ( F_226 ( V_115 , F_3 ( V_2 ) , V_154 -> args . V_550 -> V_67 ) == - V_128 ) {
F_55 ( V_115 ) ;
return - V_128 ;
}
if ( V_115 -> V_146 >= 0 ) {
F_35 ( F_3 ( V_2 ) , V_154 -> V_104 ) ;
F_344 ( V_2 , & V_154 -> V_367 ) ;
}
return 0 ;
}
static bool F_345 ( struct V_114 * V_115 ,
struct V_557 * args )
{
if ( ! F_333 ( V_115 -> V_146 ) ||
F_332 ( & args -> V_236 ,
args -> V_550 ,
args -> V_552 ,
V_214 ) )
return false ;
F_55 ( V_115 ) ;
return true ;
}
static int F_346 ( struct V_114 * V_115 , struct V_556 * V_154 )
{
if ( ! F_58 ( V_115 , & V_154 -> V_57 . V_157 ) )
return - V_128 ;
if ( F_345 ( V_115 , & V_154 -> args ) )
return - V_128 ;
return V_154 -> V_558 ? V_154 -> V_558 ( V_115 , V_154 ) :
F_342 ( V_115 , V_154 ) ;
}
static
bool F_347 ( const struct V_556 * V_154 )
{
const struct V_559 * V_560 = V_154 -> V_549 ;
if ( V_154 -> V_561 != NULL || V_560 -> V_562 != NULL )
return false ;
return F_21 ( V_560 -> V_2 , V_71 ) == 0 ;
}
static void F_348 ( struct V_556 * V_154 , struct V_158 * V_159 )
{
struct V_15 * V_16 = F_3 ( V_154 -> V_549 -> V_2 ) ;
if ( ! F_347 ( V_154 ) ) {
V_154 -> args . V_227 = NULL ;
V_154 -> V_57 . V_367 = NULL ;
} else
V_154 -> args . V_227 = V_16 -> V_396 ;
if ( ! V_154 -> V_558 )
V_154 -> V_558 = F_342 ;
V_154 -> V_57 . V_16 = V_16 ;
V_154 -> V_104 = V_151 ;
V_159 -> V_288 = & V_289 [ V_563 ] ;
F_36 ( & V_154 -> args . V_156 , & V_154 -> V_57 . V_157 , 1 ) ;
}
static int F_349 ( struct V_114 * V_115 , struct V_556 * V_154 )
{
if ( F_62 ( F_3 ( V_154 -> V_549 -> V_2 ) ,
& V_154 -> args . V_156 ,
& V_154 -> V_57 . V_157 ,
V_115 ) )
return 0 ;
if ( F_331 ( & V_154 -> args . V_236 , V_154 -> args . V_550 ,
V_154 -> args . V_552 , V_214 ) == - V_38 )
return - V_38 ;
if ( F_341 ( F_60 ( V_555 , & V_154 -> args . V_550 -> V_203 ) ) )
return - V_38 ;
return 0 ;
}
static void F_350 ( struct V_114 * V_115 , struct V_564 * V_154 )
{
F_62 ( F_3 ( V_154 -> V_2 ) ,
& V_154 -> args . V_156 ,
& V_154 -> V_57 . V_157 ,
V_115 ) ;
}
static int F_351 ( struct V_114 * V_115 , struct V_564 * V_154 )
{
struct V_2 * V_2 = V_154 -> V_2 ;
F_352 ( V_154 , V_115 -> V_146 ) ;
if ( F_226 ( V_115 , F_3 ( V_2 ) , NULL ) == - V_128 ) {
F_55 ( V_115 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_353 ( struct V_114 * V_115 , struct V_564 * V_154 )
{
if ( ! F_58 ( V_115 , & V_154 -> V_57 . V_157 ) )
return - V_128 ;
return V_154 -> V_565 ( V_115 , V_154 ) ;
}
static void F_354 ( struct V_564 * V_154 , struct V_158 * V_159 )
{
struct V_15 * V_16 = F_3 ( V_154 -> V_2 ) ;
if ( V_154 -> V_565 == NULL )
V_154 -> V_565 = F_351 ;
V_154 -> V_57 . V_16 = V_16 ;
V_159 -> V_288 = & V_289 [ V_566 ] ;
F_36 ( & V_154 -> args . V_156 , & V_154 -> V_57 . V_157 , 1 ) ;
}
static void F_355 ( void * V_152 )
{
struct V_567 * V_154 = V_152 ;
struct V_10 * V_65 = V_154 -> V_91 ;
if ( F_356 ( & V_65 -> V_568 ) > 1 )
F_357 ( V_65 ) ;
F_358 ( V_65 ) ;
F_94 ( V_154 ) ;
}
static void F_359 ( struct V_114 * V_115 , void * V_152 )
{
struct V_567 * V_154 = V_152 ;
struct V_10 * V_65 = V_154 -> V_91 ;
unsigned long V_104 = V_154 -> V_104 ;
F_360 ( V_65 , V_115 -> V_146 ) ;
if ( V_115 -> V_146 < 0 ) {
if ( F_60 ( V_569 , & V_65 -> V_570 ) == 0 )
return;
if ( V_115 -> V_146 != V_571 ) {
F_25 ( V_65 ) ;
return;
}
F_361 ( V_65 ) ;
}
F_31 ( V_65 , V_104 ) ;
}
static int F_362 ( struct V_10 * V_65 , struct V_293 * V_327 , unsigned V_572 )
{
struct V_158 V_159 = {
. V_288 = & V_289 [ V_573 ] ,
. V_291 = V_65 ,
. V_293 = V_327 ,
} ;
struct V_567 * V_154 ;
if ( V_572 == 0 )
return 0 ;
if ( ! F_363 ( & V_65 -> V_568 ) )
return - V_38 ;
V_154 = F_255 ( sizeof( * V_154 ) , V_281 ) ;
if ( V_154 == NULL )
return - V_124 ;
V_154 -> V_91 = V_65 ;
V_154 -> V_104 = V_151 ;
return F_364 ( V_65 -> V_99 , & V_159 , V_574 ,
& V_575 , V_154 ) ;
}
static int F_365 ( struct V_10 * V_65 , struct V_293 * V_327 )
{
struct V_158 V_159 = {
. V_288 = & V_289 [ V_573 ] ,
. V_291 = V_65 ,
. V_293 = V_327 ,
} ;
unsigned long V_533 = V_151 ;
int V_283 ;
V_283 = F_366 ( V_65 -> V_99 , & V_159 , V_574 ) ;
if ( V_283 < 0 )
return V_283 ;
F_31 ( V_65 , V_533 ) ;
return 0 ;
}
static inline int F_367 ( struct V_15 * V_16 )
{
return ( V_16 -> V_94 & V_404 )
&& ( V_16 -> V_426 & V_576 )
&& ( V_16 -> V_426 & V_577 ) ;
}
static int F_368 ( const void * V_578 , T_9 V_579 ,
struct V_451 * * V_45 , unsigned int * V_52 )
{
struct V_451 * V_580 , * * V_581 ;
int V_582 = 0 ;
T_9 V_14 ;
V_581 = V_45 ;
do {
V_14 = F_369 ( T_9 , V_583 , V_579 ) ;
V_580 = F_254 ( V_358 ) ;
if ( V_580 == NULL )
goto V_584;
memcpy ( F_370 ( V_580 ) , V_578 , V_14 ) ;
V_578 += V_14 ;
V_579 -= V_14 ;
* V_45 ++ = V_580 ;
V_582 ++ ;
} while ( V_579 != 0 );
return V_582 ;
V_584:
for(; V_582 > 0 ; V_582 -- )
F_258 ( V_581 [ V_582 - 1 ] ) ;
return - V_124 ;
}
static void F_371 ( struct V_2 * V_2 , struct V_585 * V_586 )
{
struct V_169 * V_170 = F_74 ( V_2 ) ;
F_32 ( & V_2 -> V_171 ) ;
F_94 ( V_170 -> V_587 ) ;
V_170 -> V_587 = V_586 ;
F_34 ( & V_2 -> V_171 ) ;
}
static void F_372 ( struct V_2 * V_2 )
{
F_371 ( V_2 , NULL ) ;
}
static inline T_11 F_373 ( struct V_2 * V_2 , char * V_578 , T_9 V_579 )
{
struct V_169 * V_170 = F_74 ( V_2 ) ;
struct V_585 * V_586 ;
int V_68 = - V_280 ;
F_32 ( & V_2 -> V_171 ) ;
V_586 = V_170 -> V_587 ;
if ( V_586 == NULL )
goto V_129;
if ( V_578 == NULL )
goto V_588;
if ( V_586 -> V_589 == 0 )
goto V_129;
V_68 = - V_590 ;
if ( V_586 -> V_14 > V_579 )
goto V_129;
memcpy ( V_578 , V_586 -> V_154 , V_586 -> V_14 ) ;
V_588:
V_68 = V_586 -> V_14 ;
V_129:
F_34 ( & V_2 -> V_171 ) ;
return V_68 ;
}
static void F_374 ( struct V_2 * V_2 , struct V_451 * * V_45 , T_9 V_52 , T_9 V_591 )
{
struct V_585 * V_586 ;
T_9 V_579 = sizeof( * V_586 ) + V_591 ;
if ( V_579 <= V_583 ) {
V_586 = F_255 ( V_579 , V_358 ) ;
if ( V_586 == NULL )
goto V_129;
V_586 -> V_589 = 1 ;
F_375 ( V_586 -> V_154 , V_45 , V_52 , V_591 ) ;
} else {
V_586 = F_255 ( sizeof( * V_586 ) , V_358 ) ;
if ( V_586 == NULL )
goto V_129;
V_586 -> V_589 = 0 ;
}
V_586 -> V_14 = V_591 ;
V_129:
F_371 ( V_2 , V_586 ) ;
}
static T_11 F_376 ( struct V_2 * V_2 , void * V_578 , T_9 V_579 )
{
struct V_451 * V_45 [ V_592 ] = { NULL , } ;
struct V_593 args = {
. V_230 = F_91 ( V_2 ) ,
. V_594 = V_45 ,
. V_591 = V_579 ,
} ;
struct V_595 V_57 = {
. V_591 = V_579 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_596 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
unsigned int V_597 = F_377 ( V_579 , V_583 ) ;
int V_68 = - V_124 , V_442 ;
if ( V_597 == 0 )
V_597 = 1 ;
if ( V_597 > F_245 ( V_45 ) )
return - V_590 ;
for ( V_442 = 0 ; V_442 < V_597 ; V_442 ++ ) {
V_45 [ V_442 ] = F_254 ( V_358 ) ;
if ( ! V_45 [ V_442 ] )
goto V_287;
}
V_57 . V_598 = F_254 ( V_358 ) ;
if ( ! V_57 . V_598 )
goto V_287;
args . V_591 = V_597 * V_583 ;
args . V_599 = 0 ;
F_9 ( L_41 ,
V_37 , V_578 , V_579 , V_597 , args . V_591 ) ;
V_68 = F_72 ( F_3 ( V_2 ) -> V_91 , F_3 ( V_2 ) ,
& V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
if ( V_68 )
goto V_287;
if ( V_57 . V_600 & V_601 ) {
if ( V_578 == NULL )
goto V_602;
V_68 = - V_590 ;
goto V_287;
}
F_374 ( V_2 , V_45 , V_57 . V_603 , V_57 . V_591 ) ;
if ( V_578 ) {
if ( V_57 . V_591 > V_579 ) {
V_68 = - V_590 ;
goto V_287;
}
F_375 ( V_578 , V_45 , V_57 . V_603 , V_57 . V_591 ) ;
}
V_602:
V_68 = V_57 . V_591 ;
V_287:
for ( V_442 = 0 ; V_442 < V_597 ; V_442 ++ )
if ( V_45 [ V_442 ] )
F_258 ( V_45 [ V_442 ] ) ;
if ( V_57 . V_598 )
F_258 ( V_57 . V_598 ) ;
return V_68 ;
}
static T_11 F_378 ( struct V_2 * V_2 , void * V_578 , T_9 V_579 )
{
struct V_63 V_64 = { } ;
T_11 V_68 ;
do {
V_68 = F_376 ( V_2 , V_578 , V_579 ) ;
F_379 ( V_2 , V_68 ) ;
if ( V_68 >= 0 )
break;
V_68 = F_20 ( F_3 ( V_2 ) , V_68 , & V_64 ) ;
} while ( V_64 . V_69 );
return V_68 ;
}
static T_11 F_380 ( struct V_2 * V_2 , void * V_578 , T_9 V_579 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
int V_68 ;
if ( ! F_367 ( V_16 ) )
return - V_604 ;
V_68 = F_381 ( V_16 , V_2 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( F_74 ( V_2 ) -> V_172 & V_605 )
F_382 ( V_2 ) ;
V_68 = F_373 ( V_2 , V_578 , V_579 ) ;
if ( V_68 != - V_280 )
return V_68 ;
return F_378 ( V_2 , V_578 , V_579 ) ;
}
static int F_383 ( struct V_2 * V_2 , const void * V_578 , T_9 V_579 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_451 * V_45 [ V_592 ] ;
struct V_606 V_370 = {
. V_230 = F_91 ( V_2 ) ,
. V_594 = V_45 ,
. V_591 = V_579 ,
} ;
struct V_607 V_57 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_608 ] ,
. V_291 = & V_370 ,
. V_292 = & V_57 ,
} ;
unsigned int V_597 = F_377 ( V_579 , V_583 ) ;
int V_68 , V_442 ;
if ( ! F_367 ( V_16 ) )
return - V_604 ;
if ( V_597 > F_245 ( V_45 ) )
return - V_590 ;
V_442 = F_368 ( V_578 , V_579 , V_370 . V_594 , & V_370 . V_599 ) ;
if ( V_442 < 0 )
return V_442 ;
F_22 ( V_2 ) ;
V_68 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & V_370 . V_156 , & V_57 . V_157 , 1 ) ;
for (; V_442 > 0 ; V_442 -- )
F_384 ( V_45 [ V_442 - 1 ] ) ;
F_32 ( & V_2 -> V_171 ) ;
F_74 ( V_2 ) -> V_172 |= V_173 ;
F_34 ( & V_2 -> V_171 ) ;
F_385 ( V_2 ) ;
F_382 ( V_2 ) ;
return V_68 ;
}
static int F_386 ( struct V_2 * V_2 , const void * V_578 , T_9 V_579 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_383 ( V_2 , V_578 , V_579 ) ;
F_387 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_2 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_388 ( struct V_2 * V_2 , void * V_578 ,
T_9 V_579 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_366 V_367 ;
struct V_1 V_7 = { 0 , 0 , V_579 , V_578 } ;
T_1 V_227 [ 3 ] = { 0 , 0 , V_423 } ;
struct V_454 args = {
. V_230 = F_91 ( V_2 ) ,
. V_227 = V_227 ,
} ;
struct V_455 V_57 = {
. V_367 = & V_367 ,
. V_7 = & V_7 ,
. V_16 = V_16 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_456 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
int V_68 ;
F_80 ( & V_367 ) ;
V_68 = F_366 ( V_16 -> V_91 , & V_159 , 0 ) ;
if ( V_68 )
return V_68 ;
if ( ! ( V_367 . V_271 & V_609 ) )
return - V_280 ;
if ( V_579 < V_7 . V_14 )
return - V_590 ;
return 0 ;
}
static int F_389 ( struct V_2 * V_2 , void * V_578 ,
T_9 V_579 )
{
struct V_63 V_64 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_604 ;
do {
V_8 = F_388 ( V_2 , V_578 , V_579 ) ;
F_390 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_2 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_391 ( struct V_2 * V_2 ,
struct V_1 * V_368 ,
struct V_366 * V_367 ,
struct V_1 * V_357 )
{
struct V_5 V_6 = { 0 } ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
const T_1 V_227 [ 3 ] = { 0 , 0 , V_423 } ;
struct V_369 args = {
. V_230 = F_91 ( V_2 ) ,
. V_371 = & V_6 ,
. V_16 = V_16 ,
. V_227 = V_227 ,
. V_7 = V_368 ,
} ;
struct V_372 V_57 = {
. V_367 = V_367 ,
. V_7 = V_357 ,
. V_16 = V_16 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_373 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
int V_283 ;
F_113 ( & args . V_236 , & V_382 ) ;
V_283 = F_366 ( V_16 -> V_91 , & V_159 , 0 ) ;
if ( V_283 )
F_9 ( L_42 , V_37 , V_283 ) ;
return V_283 ;
}
static int F_392 ( struct V_2 * V_2 ,
struct V_1 * V_368 ,
struct V_366 * V_367 ,
struct V_1 * V_357 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_391 ( V_2 , V_368 ,
V_367 , V_357 ) ;
F_393 ( V_2 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_2 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int
F_394 ( struct V_4 * V_4 , const void * V_578 , T_9 V_579 )
{
struct V_1 V_368 , * V_357 = NULL ;
struct V_366 V_367 ;
struct V_293 * V_327 ;
struct V_2 * V_2 = V_4 -> V_49 ;
int V_283 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_604 ;
F_80 ( & V_367 ) ;
V_368 . V_610 = 0 ;
V_368 . V_611 = 0 ;
V_368 . V_7 = ( char * ) V_578 ;
V_368 . V_14 = V_579 ;
V_327 = F_395 () ;
if ( F_41 ( V_327 ) )
return F_70 ( V_327 ) ;
V_357 = F_85 ( F_3 ( V_2 ) , V_358 ) ;
if ( F_41 ( V_357 ) ) {
V_283 = - F_70 ( V_357 ) ;
goto V_129;
}
V_283 = F_392 ( V_2 , & V_368 , & V_367 , V_357 ) ;
if ( V_283 == 0 )
F_135 ( V_2 , & V_367 , V_357 ) ;
F_93 ( V_357 ) ;
V_129:
F_191 ( V_327 ) ;
return V_283 ;
}
static int
F_226 ( struct V_114 * V_115 , const struct V_15 * V_16 , struct V_66 * V_67 )
{
struct V_10 * V_65 = V_16 -> V_10 ;
if ( V_115 -> V_146 >= 0 )
return 0 ;
switch( V_115 -> V_146 ) {
case - V_73 :
case - V_74 :
case - V_75 :
if ( V_67 == NULL )
break;
F_24 ( V_67 -> V_2 ) ;
case - V_70 :
if ( V_67 == NULL )
break;
if ( F_23 ( V_16 , V_67 ) < 0 )
goto V_612;
goto V_72;
case - V_76 :
if ( V_67 != NULL ) {
if ( F_23 ( V_16 , V_67 ) < 0 )
goto V_612;
}
case - V_77 :
case - V_78 :
F_25 ( V_65 ) ;
goto V_72;
#if F_26 ( V_79 )
case - V_80 :
case - V_81 :
case - V_82 :
case - V_84 :
case - V_83 :
case - V_85 :
case - V_86 :
F_9 ( L_43 , V_37 ,
V_115 -> V_146 ) ;
F_27 ( V_65 -> V_87 , V_115 -> V_146 ) ;
V_115 -> V_146 = 0 ;
return - V_128 ;
#endif
case - V_90 :
F_396 ( V_16 , V_613 ) ;
case - V_89 :
F_57 ( V_115 , V_59 ) ;
V_115 -> V_146 = 0 ;
return - V_128 ;
case - V_92 :
case - V_93 :
V_115 -> V_146 = 0 ;
return - V_128 ;
}
V_115 -> V_146 = F_8 ( V_115 -> V_146 ) ;
return 0 ;
V_612:
V_115 -> V_146 = - V_38 ;
return 0 ;
V_72:
F_45 ( & V_65 -> V_614 , V_115 , NULL ) ;
if ( F_60 ( V_615 , & V_65 -> V_616 ) == 0 )
F_397 ( & V_65 -> V_614 , V_115 ) ;
V_115 -> V_146 = 0 ;
return - V_128 ;
}
static void F_398 ( const struct V_10 * V_65 ,
T_12 * V_617 )
{
T_3 V_233 [ 2 ] ;
if ( F_60 ( V_618 , & V_65 -> V_616 ) ) {
V_233 [ 0 ] = 0 ;
V_233 [ 1 ] = F_399 ( V_619 + 1 ) ;
} else {
struct V_620 * V_621 = F_400 ( V_65 -> V_622 , V_623 ) ;
V_233 [ 0 ] = F_399 ( V_621 -> V_624 . V_625 ) ;
V_233 [ 1 ] = F_399 ( V_621 -> V_624 . V_626 ) ;
}
memcpy ( V_617 -> V_154 , V_233 , sizeof( V_617 -> V_154 ) ) ;
}
static unsigned int
F_401 ( const struct V_10 * V_65 ,
char * V_578 , T_9 V_14 )
{
unsigned int V_627 ;
F_120 () ;
V_627 = F_402 ( V_578 , V_14 , L_44 ,
V_65 -> V_628 ,
F_403 ( V_65 -> V_99 ,
V_629 ) ,
F_403 ( V_65 -> V_99 ,
V_630 ) ) ;
F_123 () ;
return V_627 ;
}
static unsigned int
F_404 ( const struct V_10 * V_65 ,
char * V_578 , T_9 V_14 )
{
const char * V_631 = V_65 -> V_99 -> V_632 ;
if ( V_633 [ 0 ] != '\0' )
return F_402 ( V_578 , V_14 , L_45 ,
V_65 -> V_634 -> V_635 ,
V_65 -> V_11 ,
V_633 ,
V_631 ) ;
return F_402 ( V_578 , V_14 , L_46 ,
V_65 -> V_634 -> V_635 , V_65 -> V_11 ,
V_631 ) ;
}
int F_405 ( struct V_10 * V_65 , T_1 V_636 ,
unsigned short V_637 , struct V_293 * V_327 ,
struct V_638 * V_57 )
{
T_12 V_639 ;
struct V_640 V_641 = {
. V_639 = & V_639 ,
. V_642 = V_636 ,
. V_643 = V_65 -> V_644 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_645 ] ,
. V_291 = & V_641 ,
. V_292 = V_57 ,
. V_293 = V_327 ,
} ;
int V_283 ;
F_398 ( V_65 , & V_639 ) ;
if ( F_60 ( V_646 , & V_65 -> V_647 ) )
V_641 . V_648 =
F_404 ( V_65 ,
V_641 . V_649 ,
sizeof( V_641 . V_649 ) ) ;
else
V_641 . V_648 =
F_401 ( V_65 ,
V_641 . V_649 ,
sizeof( V_641 . V_649 ) ) ;
F_120 () ;
V_641 . V_650 = F_402 ( V_641 . V_651 ,
sizeof( V_641 . V_651 ) , L_47 ,
F_403 ( V_65 -> V_99 ,
V_652 ) ) ;
F_123 () ;
V_641 . V_653 = F_402 ( V_641 . V_654 ,
sizeof( V_641 . V_654 ) , L_48 ,
V_65 -> V_628 , V_637 >> 8 , V_637 & 255 ) ;
F_9 ( L_49 ,
V_65 -> V_99 -> V_100 -> V_655 -> V_656 ,
V_641 . V_648 , V_641 . V_649 ) ;
V_283 = F_366 ( V_65 -> V_99 , & V_159 , V_574 ) ;
F_406 ( V_65 , V_283 ) ;
F_9 ( L_50 , V_283 ) ;
return V_283 ;
}
int F_407 ( struct V_10 * V_65 ,
struct V_638 * V_370 ,
struct V_293 * V_327 )
{
struct V_158 V_159 = {
. V_288 = & V_289 [ V_657 ] ,
. V_291 = V_370 ,
. V_293 = V_327 ,
} ;
int V_283 ;
F_9 ( L_51 ,
V_65 -> V_99 -> V_100 -> V_655 -> V_656 ,
V_65 -> V_221 ) ;
V_283 = F_366 ( V_65 -> V_99 , & V_159 , V_574 ) ;
F_408 ( V_65 , V_283 ) ;
F_9 ( L_52 , V_283 ) ;
return V_283 ;
}
static void F_409 ( struct V_114 * V_115 , void * V_152 )
{
struct V_658 * V_154 = V_152 ;
if ( ! F_58 ( V_115 , & V_154 -> V_57 . V_157 ) )
return;
F_410 ( & V_154 -> args , & V_154 -> V_57 , V_115 -> V_146 ) ;
switch ( V_115 -> V_146 ) {
case - V_77 :
case - V_76 :
case 0 :
F_35 ( V_154 -> V_57 . V_16 , V_154 -> V_104 ) ;
break;
default:
if ( F_226 ( V_115 , V_154 -> V_57 . V_16 , NULL ) ==
- V_128 ) {
F_55 ( V_115 ) ;
return;
}
}
V_154 -> V_269 = V_115 -> V_146 ;
}
static void F_411 ( void * V_152 )
{
F_94 ( V_152 ) ;
}
static void F_412 ( struct V_114 * V_115 , void * V_154 )
{
struct V_658 * V_659 ;
V_659 = (struct V_658 * ) V_154 ;
F_62 ( V_659 -> V_57 . V_16 ,
& V_659 -> args . V_156 ,
& V_659 -> V_57 . V_157 ,
V_115 ) ;
}
static int F_413 ( struct V_2 * V_2 , struct V_293 * V_327 , const T_8 * V_236 , int V_660 )
{
struct V_658 * V_154 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_114 * V_115 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_661 ] ,
. V_293 = V_327 ,
} ;
struct V_160 V_294 = {
. V_162 = V_16 -> V_91 ,
. V_158 = & V_159 ,
. V_163 = & V_662 ,
. V_203 = V_298 ,
} ;
int V_283 = 0 ;
V_154 = F_84 ( sizeof( * V_154 ) , V_281 ) ;
if ( V_154 == NULL )
return - V_124 ;
F_36 ( & V_154 -> args . V_156 , & V_154 -> V_57 . V_157 , 1 ) ;
V_154 -> args . V_400 = & V_154 -> V_230 ;
V_154 -> args . V_236 = & V_154 -> V_236 ;
V_154 -> args . V_227 = V_16 -> V_396 ;
F_168 ( & V_154 -> V_230 , F_91 ( V_2 ) ) ;
F_113 ( & V_154 -> V_236 , V_236 ) ;
V_154 -> V_57 . V_367 = & V_154 -> V_367 ;
V_154 -> V_57 . V_16 = V_16 ;
F_80 ( V_154 -> V_57 . V_367 ) ;
V_154 -> V_104 = V_151 ;
V_154 -> V_269 = 0 ;
V_294 . V_166 = V_154 ;
V_159 . V_291 = & V_154 -> args ;
V_159 . V_292 = & V_154 -> V_57 ;
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
if ( ! V_660 )
goto V_129;
V_283 = F_105 ( V_115 ) ;
if ( V_283 != 0 )
goto V_129;
V_283 = V_154 -> V_269 ;
if ( V_283 == 0 )
F_344 ( V_2 , & V_154 -> V_367 ) ;
else
F_134 ( V_2 , & V_154 -> V_367 ) ;
V_129:
F_71 ( V_115 ) ;
return V_283 ;
}
int F_414 ( struct V_2 * V_2 , struct V_293 * V_327 , const T_8 * V_236 , int V_660 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_413 ( V_2 , V_327 , V_236 , V_660 ) ;
F_415 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_77 :
case - V_76 :
case 0 :
return 0 ;
}
V_8 = F_20 ( V_16 , V_8 , & V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static unsigned long
F_416 ( unsigned long V_56 )
{
F_18 ( V_56 ) ;
V_56 <<= 1 ;
if ( V_56 > V_663 )
return V_663 ;
return V_56 ;
}
static int F_417 ( struct V_66 * V_67 , int V_664 , struct V_665 * V_666 )
{
struct V_2 * V_2 = V_67 -> V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_10 * V_65 = V_16 -> V_10 ;
struct V_667 V_370 = {
. V_230 = F_91 ( V_2 ) ,
. V_668 = V_666 ,
} ;
struct V_669 V_57 = {
. V_670 = V_666 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_671 ] ,
. V_291 = & V_370 ,
. V_292 = & V_57 ,
. V_293 = V_67 -> V_211 -> V_266 ,
} ;
struct V_672 * V_673 ;
int V_283 ;
V_370 . V_674 . V_220 = V_65 -> V_221 ;
V_283 = F_418 ( V_67 , V_666 ) ;
if ( V_283 != 0 )
goto V_129;
V_673 = V_666 -> V_675 . V_676 . V_211 ;
V_370 . V_674 . V_222 = V_673 -> V_677 . V_225 ;
V_370 . V_674 . V_678 = V_16 -> V_678 ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & V_370 . V_156 , & V_57 . V_157 , 1 ) ;
switch ( V_283 ) {
case 0 :
V_666 -> V_679 = V_680 ;
break;
case - V_285 :
V_283 = 0 ;
}
V_666 -> V_681 -> V_682 ( V_666 ) ;
V_129:
return V_283 ;
}
static int F_419 ( struct V_66 * V_67 , int V_664 , struct V_665 * V_666 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_417 ( V_67 , V_664 , V_666 ) ;
F_420 ( V_666 , V_67 , V_664 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_67 -> V_2 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_421 ( struct V_683 * V_683 , struct V_665 * V_668 )
{
int V_57 = 0 ;
switch ( V_668 -> V_684 & ( V_685 | V_686 ) ) {
case V_685 :
V_57 = F_422 ( V_683 , V_668 ) ;
break;
case V_686 :
V_57 = F_423 ( V_683 , V_668 ) ;
break;
default:
F_424 () ;
}
return V_57 ;
}
static struct V_687 * F_425 ( struct V_665 * V_668 ,
struct V_278 * V_279 ,
struct V_672 * V_673 ,
struct V_688 * V_192 )
{
struct V_687 * V_44 ;
struct V_2 * V_2 = V_673 -> V_689 -> V_2 ;
V_44 = F_84 ( sizeof( * V_44 ) , V_281 ) ;
if ( V_44 == NULL )
return NULL ;
V_44 -> V_370 . V_230 = F_91 ( V_2 ) ;
V_44 -> V_370 . V_668 = & V_44 -> V_668 ;
V_44 -> V_370 . V_192 = V_192 ;
V_44 -> V_57 . V_192 = V_192 ;
V_44 -> V_370 . V_236 = & V_673 -> V_690 ;
V_44 -> V_673 = V_673 ;
F_89 ( & V_673 -> V_691 ) ;
V_44 -> V_279 = F_142 ( V_279 ) ;
memcpy ( & V_44 -> V_668 , V_668 , sizeof( V_44 -> V_668 ) ) ;
V_44 -> V_16 = F_3 ( V_2 ) ;
return V_44 ;
}
static void F_426 ( void * V_154 )
{
struct V_687 * V_152 = V_154 ;
F_98 ( V_152 -> V_370 . V_192 ) ;
F_427 ( V_152 -> V_673 ) ;
F_154 ( V_152 -> V_279 ) ;
F_94 ( V_152 ) ;
}
static void F_428 ( struct V_114 * V_115 , void * V_154 )
{
struct V_687 * V_152 = V_154 ;
if ( ! F_58 ( V_115 , & V_152 -> V_57 . V_157 ) )
return;
switch ( V_115 -> V_146 ) {
case 0 :
F_113 ( & V_152 -> V_673 -> V_690 ,
& V_152 -> V_57 . V_236 ) ;
F_35 ( V_152 -> V_16 , V_152 -> V_104 ) ;
break;
case - V_75 :
case - V_93 :
case - V_77 :
case - V_76 :
break;
default:
if ( F_226 ( V_115 , V_152 -> V_16 , NULL ) == - V_128 )
F_55 ( V_115 ) ;
}
F_126 ( V_152 -> V_370 . V_192 ) ;
}
static void F_429 ( struct V_114 * V_115 , void * V_154 )
{
struct V_687 * V_152 = V_154 ;
if ( F_167 ( V_152 -> V_370 . V_192 , V_115 ) != 0 )
goto V_300;
if ( F_60 ( V_692 , & V_152 -> V_673 -> V_693 ) == 0 ) {
goto V_301;
}
V_152 -> V_104 = V_151 ;
if ( F_62 ( V_152 -> V_16 ,
& V_152 -> V_370 . V_156 ,
& V_152 -> V_57 . V_157 ,
V_115 ) != 0 )
F_126 ( V_152 -> V_370 . V_192 ) ;
return;
V_301:
V_115 -> V_312 = NULL ;
V_300:
F_58 ( V_115 , & V_152 -> V_57 . V_157 ) ;
}
static struct V_114 * F_430 ( struct V_665 * V_668 ,
struct V_278 * V_279 ,
struct V_672 * V_673 ,
struct V_688 * V_192 )
{
struct V_687 * V_154 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_694 ] ,
. V_293 = V_279 -> V_327 ,
} ;
struct V_160 V_294 = {
. V_162 = F_271 ( V_673 -> V_689 -> V_2 ) ,
. V_158 = & V_159 ,
. V_163 = & V_695 ,
. V_296 = V_297 ,
. V_203 = V_298 ,
} ;
F_230 ( F_3 ( V_673 -> V_689 -> V_2 ) -> V_10 ,
V_394 , & V_294 . V_162 , & V_159 ) ;
V_668 -> V_679 = V_680 ;
V_154 = F_425 ( V_668 , V_279 , V_673 , V_192 ) ;
if ( V_154 == NULL ) {
F_98 ( V_192 ) ;
return F_42 ( - V_124 ) ;
}
F_36 ( & V_154 -> V_370 . V_156 , & V_154 -> V_57 . V_157 , 1 ) ;
V_159 . V_291 = & V_154 -> V_370 ;
V_159 . V_292 = & V_154 -> V_57 ;
V_294 . V_166 = V_154 ;
return F_69 ( & V_294 ) ;
}
static int F_431 ( struct V_66 * V_67 , int V_664 , struct V_665 * V_666 )
{
struct V_2 * V_2 = V_67 -> V_2 ;
struct V_200 * V_201 = V_67 -> V_211 ;
struct V_169 * V_170 = F_74 ( V_2 ) ;
struct V_688 * V_192 ;
struct V_672 * V_673 ;
struct V_114 * V_115 ;
int V_283 = 0 ;
unsigned char V_684 = V_666 -> V_684 ;
V_283 = F_418 ( V_67 , V_666 ) ;
V_666 -> V_684 |= V_696 ;
F_432 ( & V_201 -> V_697 ) ;
F_433 ( & V_170 -> V_698 ) ;
if ( F_421 ( V_666 -> V_699 , V_666 ) == - V_280 ) {
F_434 ( & V_170 -> V_698 ) ;
F_435 ( & V_201 -> V_697 ) ;
goto V_129;
}
F_434 ( & V_170 -> V_698 ) ;
F_435 ( & V_201 -> V_697 ) ;
if ( V_283 != 0 )
goto V_129;
V_673 = V_666 -> V_675 . V_676 . V_211 ;
if ( F_60 ( V_692 , & V_673 -> V_693 ) == 0 )
goto V_129;
V_192 = F_86 ( & V_673 -> V_677 , V_358 ) ;
V_283 = - V_124 ;
if ( V_192 == NULL )
goto V_129;
V_115 = F_430 ( V_666 , F_263 ( V_666 -> V_699 ) , V_673 , V_192 ) ;
V_283 = F_70 ( V_115 ) ;
if ( F_41 ( V_115 ) )
goto V_129;
V_283 = F_105 ( V_115 ) ;
F_71 ( V_115 ) ;
V_129:
V_666 -> V_684 = V_684 ;
F_436 ( V_666 , V_67 , V_700 , V_283 ) ;
return V_283 ;
}
static struct V_701 * F_437 ( struct V_665 * V_668 ,
struct V_278 * V_279 , struct V_672 * V_673 ,
T_6 V_205 )
{
struct V_701 * V_44 ;
struct V_2 * V_2 = V_673 -> V_689 -> V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
V_44 = F_84 ( sizeof( * V_44 ) , V_205 ) ;
if ( V_44 == NULL )
return NULL ;
V_44 -> V_370 . V_230 = F_91 ( V_2 ) ;
V_44 -> V_370 . V_668 = & V_44 -> V_668 ;
V_44 -> V_370 . V_702 = F_86 ( & V_673 -> V_689 -> V_211 -> V_208 , V_205 ) ;
if ( V_44 -> V_370 . V_702 == NULL )
goto V_287;
V_44 -> V_370 . V_703 = F_86 ( & V_673 -> V_677 , V_205 ) ;
if ( V_44 -> V_370 . V_703 == NULL )
goto V_704;
V_44 -> V_370 . V_705 = & V_673 -> V_690 ;
V_44 -> V_370 . V_674 . V_220 = V_16 -> V_10 -> V_221 ;
V_44 -> V_370 . V_674 . V_222 = V_673 -> V_677 . V_225 ;
V_44 -> V_370 . V_674 . V_678 = V_16 -> V_678 ;
V_44 -> V_57 . V_703 = V_44 -> V_370 . V_703 ;
V_44 -> V_673 = V_673 ;
V_44 -> V_16 = V_16 ;
F_89 ( & V_673 -> V_691 ) ;
V_44 -> V_279 = F_142 ( V_279 ) ;
memcpy ( & V_44 -> V_668 , V_668 , sizeof( V_44 -> V_668 ) ) ;
return V_44 ;
V_704:
F_98 ( V_44 -> V_370 . V_702 ) ;
V_287:
F_94 ( V_44 ) ;
return NULL ;
}
static void F_438 ( struct V_114 * V_115 , void * V_152 )
{
struct V_701 * V_154 = V_152 ;
struct V_66 * V_67 = V_154 -> V_673 -> V_689 ;
F_9 ( L_30 , V_37 ) ;
if ( F_167 ( V_154 -> V_370 . V_703 , V_115 ) != 0 )
goto V_300;
if ( ! ( V_154 -> V_370 . V_703 -> V_706 -> V_203 & V_707 ) ) {
if ( F_167 ( V_154 -> V_370 . V_702 , V_115 ) != 0 ) {
goto V_708;
}
V_154 -> V_370 . V_254 = & V_67 -> V_254 ;
V_154 -> V_370 . V_709 = 1 ;
V_154 -> V_57 . V_702 = V_154 -> V_370 . V_702 ;
} else
V_154 -> V_370 . V_709 = 0 ;
if ( ! F_216 ( V_67 ) ) {
V_154 -> V_269 = - V_383 ;
V_115 -> V_312 = NULL ;
goto V_710;
}
V_154 -> V_104 = V_151 ;
if ( F_62 ( V_154 -> V_16 ,
& V_154 -> V_370 . V_156 ,
& V_154 -> V_57 . V_157 ,
V_115 ) == 0 )
return;
V_710:
F_126 ( V_154 -> V_370 . V_702 ) ;
V_708:
F_126 ( V_154 -> V_370 . V_703 ) ;
V_300:
F_58 ( V_115 , & V_154 -> V_57 . V_157 ) ;
F_9 ( L_53 , V_37 , V_154 -> V_269 ) ;
}
static void F_439 ( struct V_114 * V_115 , void * V_152 )
{
struct V_701 * V_154 = V_152 ;
F_9 ( L_30 , V_37 ) ;
if ( ! F_58 ( V_115 , & V_154 -> V_57 . V_157 ) )
return;
V_154 -> V_269 = V_115 -> V_146 ;
if ( V_154 -> V_370 . V_709 != 0 ) {
if ( V_154 -> V_269 == 0 )
F_161 ( & V_154 -> V_673 -> V_677 , 0 ) ;
else
goto V_129;
}
if ( V_154 -> V_269 == 0 ) {
F_113 ( & V_154 -> V_673 -> V_690 , & V_154 -> V_57 . V_236 ) ;
F_114 ( V_692 , & V_154 -> V_673 -> V_693 ) ;
F_35 ( F_3 ( V_154 -> V_279 -> V_4 -> V_49 ) , V_154 -> V_104 ) ;
}
V_129:
F_9 ( L_31 , V_37 , V_154 -> V_269 ) ;
}
static void F_440 ( void * V_152 )
{
struct V_701 * V_154 = V_152 ;
F_9 ( L_30 , V_37 ) ;
F_98 ( V_154 -> V_370 . V_702 ) ;
if ( V_154 -> V_286 != 0 ) {
struct V_114 * V_115 ;
V_115 = F_430 ( & V_154 -> V_668 , V_154 -> V_279 , V_154 -> V_673 ,
V_154 -> V_370 . V_703 ) ;
if ( ! F_41 ( V_115 ) )
F_441 ( V_115 ) ;
F_9 ( L_54 , V_37 ) ;
} else
F_98 ( V_154 -> V_370 . V_703 ) ;
F_427 ( V_154 -> V_673 ) ;
F_154 ( V_154 -> V_279 ) ;
F_94 ( V_154 ) ;
F_9 ( L_32 , V_37 ) ;
}
static void F_442 ( struct V_15 * V_16 , struct V_672 * V_673 , int V_709 , int error )
{
switch ( error ) {
case - V_74 :
case - V_75 :
V_673 -> V_677 . V_203 &= ~ V_707 ;
if ( V_709 != 0 ||
F_60 ( V_692 , & V_673 -> V_693 ) != 0 )
F_23 ( V_16 , V_673 -> V_689 ) ;
break;
case - V_77 :
V_673 -> V_677 . V_203 &= ~ V_707 ;
case - V_76 :
F_25 ( V_16 -> V_10 ) ;
} ;
}
static int F_443 ( struct V_66 * V_67 , int V_664 , struct V_665 * V_668 , int V_711 )
{
struct V_701 * V_154 ;
struct V_114 * V_115 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_712 ] ,
. V_293 = V_67 -> V_211 -> V_266 ,
} ;
struct V_160 V_294 = {
. V_162 = F_271 ( V_67 -> V_2 ) ,
. V_158 = & V_159 ,
. V_163 = & V_713 ,
. V_296 = V_297 ,
. V_203 = V_298 ,
} ;
int V_68 ;
F_9 ( L_30 , V_37 ) ;
V_154 = F_437 ( V_668 , F_263 ( V_668 -> V_699 ) ,
V_668 -> V_675 . V_676 . V_211 ,
V_711 == V_714 ? V_358 : V_281 ) ;
if ( V_154 == NULL )
return - V_124 ;
if ( F_444 ( V_664 ) )
V_154 -> V_370 . V_715 = 1 ;
F_36 ( & V_154 -> V_370 . V_156 , & V_154 -> V_57 . V_157 , 1 ) ;
V_159 . V_291 = & V_154 -> V_370 ;
V_159 . V_292 = & V_154 -> V_57 ;
V_294 . V_166 = V_154 ;
if ( V_711 > V_714 ) {
if ( V_711 == V_716 )
V_154 -> V_370 . V_717 = V_716 ;
F_37 ( & V_154 -> V_370 . V_156 ) ;
}
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
V_68 = F_105 ( V_115 ) ;
if ( V_68 == 0 ) {
V_68 = V_154 -> V_269 ;
if ( V_68 )
F_442 ( V_154 -> V_16 , V_154 -> V_673 ,
V_154 -> V_370 . V_709 , V_68 ) ;
} else
V_154 -> V_286 = 1 ;
F_71 ( V_115 ) ;
F_9 ( L_31 , V_37 , V_68 ) ;
return V_68 ;
}
static int F_445 ( struct V_66 * V_67 , struct V_665 * V_666 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
struct V_63 V_64 = {
. V_2 = V_67 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_60 ( V_253 , & V_67 -> V_203 ) != 0 )
return 0 ;
V_8 = F_443 ( V_67 , V_700 , V_666 , V_716 ) ;
F_446 ( V_666 , V_67 , V_700 , V_8 ) ;
if ( V_8 != - V_90 )
break;
F_20 ( V_16 , V_8 , & V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_447 ( struct V_66 * V_67 , struct V_665 * V_666 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
struct V_63 V_64 = {
. V_2 = V_67 -> V_2 ,
} ;
int V_8 ;
V_8 = F_418 ( V_67 , V_666 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_718 ) {
F_114 ( V_719 , & V_666 -> V_675 . V_676 . V_211 -> V_693 ) ;
return 0 ;
}
do {
if ( F_60 ( V_253 , & V_67 -> V_203 ) != 0 )
return 0 ;
V_8 = F_443 ( V_67 , V_700 , V_666 , V_720 ) ;
F_448 ( V_666 , V_67 , V_700 , V_8 ) ;
switch ( V_8 ) {
default:
goto V_129;
case - V_89 :
case - V_90 :
F_20 ( V_16 , V_8 , & V_64 ) ;
V_8 = 0 ;
}
} while ( V_64 . V_69 );
V_129:
return V_8 ;
}
static int F_449 ( struct V_66 * V_67 )
{
int V_283 , V_68 = - V_75 ;
struct V_672 * V_673 ;
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
F_141 (lsp, &state->lock_states, ls_locks) {
if ( F_60 ( V_692 , & V_673 -> V_693 ) ) {
struct V_293 * V_327 = V_673 -> V_689 -> V_211 -> V_266 ;
V_283 = F_188 ( V_16 ,
& V_673 -> V_690 ,
V_327 ) ;
F_450 ( V_67 , V_673 , V_283 ) ;
if ( V_283 != V_341 ) {
if ( V_283 != - V_75 )
F_190 ( V_16 ,
& V_673 -> V_690 ,
V_327 ) ;
F_148 ( V_692 , & V_673 -> V_693 ) ;
V_68 = V_283 ;
}
}
} ;
return V_68 ;
}
static int F_451 ( struct V_66 * V_67 , struct V_665 * V_666 )
{
int V_283 = V_341 ;
if ( F_60 ( V_721 , & V_67 -> V_203 ) )
V_283 = F_449 ( V_67 ) ;
if ( V_283 != V_341 )
V_283 = F_447 ( V_67 , V_666 ) ;
return V_283 ;
}
static int F_452 ( struct V_66 * V_67 , int V_664 , struct V_665 * V_666 )
{
struct V_200 * V_201 = V_67 -> V_211 ;
struct V_169 * V_170 = F_74 ( V_67 -> V_2 ) ;
unsigned char V_684 = V_666 -> V_684 ;
unsigned int V_349 ;
int V_283 = - V_722 ;
if ( ( V_684 & V_685 ) &&
! F_60 ( V_351 , & V_67 -> V_203 ) )
goto V_129;
V_283 = F_418 ( V_67 , V_666 ) ;
if ( V_283 != 0 )
goto V_129;
V_666 -> V_684 |= V_723 ;
V_283 = F_421 ( V_666 -> V_699 , V_666 ) ;
if ( V_283 < 0 )
goto V_129;
F_433 ( & V_170 -> V_698 ) ;
if ( F_60 ( V_253 , & V_67 -> V_203 ) ) {
V_666 -> V_684 = V_684 & ~ V_724 ;
V_283 = F_421 ( V_666 -> V_699 , V_666 ) ;
goto V_136;
}
V_349 = F_197 ( & V_201 -> V_350 ) ;
F_434 ( & V_170 -> V_698 ) ;
V_283 = F_443 ( V_67 , V_664 , V_666 , V_714 ) ;
if ( V_283 != 0 )
goto V_129;
F_433 ( & V_170 -> V_698 ) ;
if ( F_203 ( & V_201 -> V_350 , V_349 ) ) {
V_283 = - V_90 ;
goto V_136;
}
V_666 -> V_684 = V_684 | V_724 ;
if ( F_421 ( V_666 -> V_699 , V_666 ) < 0 )
F_28 ( V_96 L_55
L_56 , V_37 ) ;
V_136:
F_434 ( & V_170 -> V_698 ) ;
V_129:
V_666 -> V_684 = V_684 ;
return V_283 ;
}
static int F_453 ( struct V_66 * V_67 , int V_664 , struct V_665 * V_666 )
{
struct V_63 V_64 = {
. V_67 = V_67 ,
. V_2 = V_67 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_452 ( V_67 , V_664 , V_666 ) ;
F_454 ( V_666 , V_67 , V_664 , V_8 ) ;
if ( V_8 == - V_285 )
V_8 = - V_128 ;
V_8 = F_20 ( F_3 ( V_67 -> V_2 ) ,
V_8 , & V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int
F_455 ( struct V_683 * V_725 , int V_664 , struct V_665 * V_666 )
{
struct V_278 * V_279 ;
struct V_66 * V_67 ;
unsigned long V_56 = V_726 ;
int V_283 ;
V_279 = F_263 ( V_725 ) ;
V_67 = V_279 -> V_67 ;
if ( V_666 -> V_727 < 0 || V_666 -> V_728 < 0 )
return - V_29 ;
if ( F_456 ( V_664 ) ) {
if ( V_67 != NULL )
return F_419 ( V_67 , V_729 , V_666 ) ;
return 0 ;
}
if ( ! ( F_457 ( V_664 ) || F_444 ( V_664 ) ) )
return - V_29 ;
if ( V_666 -> V_679 == V_680 ) {
if ( V_67 != NULL )
return F_431 ( V_67 , V_664 , V_666 ) ;
return 0 ;
}
if ( V_67 == NULL )
return - V_722 ;
switch ( V_666 -> V_679 ) {
case V_730 :
if ( ! ( V_725 -> V_731 & V_71 ) )
return - V_383 ;
break;
case V_732 :
if ( ! ( V_725 -> V_731 & V_214 ) )
return - V_383 ;
}
do {
V_283 = F_453 ( V_67 , V_664 , V_666 ) ;
if ( ( V_283 != - V_128 ) || F_457 ( V_664 ) )
break;
V_56 = F_416 ( V_56 ) ;
V_283 = - V_61 ;
if ( F_458 () )
break;
} while( V_283 < 0 );
return V_283 ;
}
int F_459 ( struct V_665 * V_668 , struct V_66 * V_67 , const T_8 * V_236 )
{
struct V_15 * V_16 = F_3 ( V_67 -> V_2 ) ;
int V_8 ;
V_8 = F_418 ( V_67 , V_668 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_443 ( V_67 , V_700 , V_668 , V_714 ) ;
return F_155 ( V_16 , V_67 , V_236 , V_8 ) ;
}
static void F_460 ( struct V_114 * V_115 , void * V_152 )
{
struct V_733 * V_154 = V_152 ;
F_38 ( V_154 -> V_16 ,
& V_154 -> V_156 , & V_154 -> V_157 , V_115 ) ;
}
static void F_461 ( struct V_114 * V_115 , void * V_152 )
{
struct V_733 * V_154 = V_152 ;
F_46 ( V_115 , & V_154 -> V_157 ) ;
}
static void F_462 ( void * V_152 )
{
struct V_733 * V_154 = V_152 ;
F_463 ( V_154 -> V_16 , V_154 -> V_673 ) ;
F_94 ( V_152 ) ;
}
static int F_464 ( struct V_15 * V_16 , struct V_672 * V_673 )
{
struct V_733 * V_154 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_734 ] ,
} ;
if ( V_16 -> V_10 -> V_164 -> V_310 != 0 )
return - V_29 ;
V_154 = F_255 ( sizeof( * V_154 ) , V_281 ) ;
if ( ! V_154 )
return - V_124 ;
F_36 ( & V_154 -> V_156 , & V_154 -> V_157 , 0 ) ;
V_154 -> V_673 = V_673 ;
V_154 -> V_16 = V_16 ;
V_154 -> args . V_674 . V_220 = V_16 -> V_10 -> V_221 ;
V_154 -> args . V_674 . V_222 = V_673 -> V_677 . V_225 ;
V_154 -> args . V_674 . V_678 = V_16 -> V_678 ;
V_159 . V_291 = & V_154 -> args ;
F_364 ( V_16 -> V_91 , & V_159 , 0 , & V_735 , V_154 ) ;
return 0 ;
}
static int F_465 ( struct V_4 * V_4 , const char * V_736 ,
const void * V_578 , T_9 V_579 ,
int V_203 , int type )
{
if ( strcmp ( V_736 , L_57 ) != 0 )
return - V_29 ;
return F_386 ( V_4 -> V_49 , V_578 , V_579 ) ;
}
static int F_466 ( struct V_4 * V_4 , const char * V_736 ,
void * V_578 , T_9 V_579 , int type )
{
if ( strcmp ( V_736 , L_57 ) != 0 )
return - V_29 ;
return F_380 ( V_4 -> V_49 , V_578 , V_579 ) ;
}
static T_9 F_467 ( struct V_4 * V_4 , char * V_737 ,
T_9 V_738 , const char * V_226 ,
T_9 V_739 , int type )
{
T_9 V_14 = sizeof( V_740 ) ;
if ( ! F_367 ( F_3 ( V_4 -> V_49 ) ) )
return 0 ;
if ( V_737 && V_14 <= V_738 )
memcpy ( V_737 , V_740 , V_14 ) ;
return V_14 ;
}
static inline int F_468 ( struct V_15 * V_16 )
{
return V_16 -> V_94 & V_9 ;
}
static int F_469 ( struct V_4 * V_4 , const char * V_736 ,
const void * V_578 , T_9 V_579 ,
int V_203 , int type )
{
if ( F_470 ( V_736 ) )
return F_394 ( V_4 , V_578 , V_579 ) ;
return - V_604 ;
}
static int F_471 ( struct V_4 * V_4 , const char * V_736 ,
void * V_578 , T_9 V_579 , int type )
{
if ( F_470 ( V_736 ) )
return F_389 ( V_4 -> V_49 , V_578 , V_579 ) ;
return - V_604 ;
}
static T_9 F_472 ( struct V_4 * V_4 , char * V_737 ,
T_9 V_738 , const char * V_226 ,
T_9 V_739 , int type )
{
T_9 V_14 = 0 ;
if ( F_2 ( V_4 -> V_49 , V_9 ) ) {
V_14 = F_473 ( V_4 -> V_49 , NULL , 0 ) ;
if ( V_737 && V_14 <= V_738 )
F_473 ( V_4 -> V_49 , V_737 , V_14 ) ;
}
return V_14 ;
}
static void F_257 ( struct V_366 * V_367 )
{
if ( ! ( ( ( V_367 -> V_271 & V_741 ) ||
( V_367 -> V_271 & V_273 ) ) &&
( V_367 -> V_271 & V_448 ) &&
( V_367 -> V_271 & V_742 ) ) )
return;
V_367 -> V_271 |= V_272 | V_463 |
V_464 | V_743 ;
V_367 -> V_240 = V_317 | V_466 | V_467 ;
V_367 -> V_468 = 2 ;
}
static int F_474 ( struct V_54 * V_91 , struct V_2 * V_3 ,
const struct V_450 * V_226 ,
struct V_452 * V_744 ,
struct V_451 * V_451 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
T_1 V_227 [ 3 ] = {
[ 0 ] = V_745 | V_746 ,
} ;
struct V_747 args = {
. V_461 = F_91 ( V_3 ) ,
. V_226 = V_226 ,
. V_451 = V_451 ,
. V_227 = V_227 ,
} ;
struct V_748 V_57 = {
. V_744 = V_744 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_749 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
int V_283 ;
F_9 ( L_58 , V_37 ) ;
if ( F_3 ( V_3 ) -> V_17 [ 1 ] & V_750 )
V_227 [ 1 ] |= V_750 ;
else
V_227 [ 0 ] |= V_48 ;
F_80 ( & V_744 -> V_367 ) ;
V_744 -> V_16 = V_16 ;
V_744 -> V_751 = 0 ;
V_283 = F_72 ( V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
F_9 ( L_59 , V_37 , V_283 ) ;
return V_283 ;
}
int F_256 ( struct V_54 * V_91 , struct V_2 * V_3 ,
const struct V_450 * V_226 ,
struct V_452 * V_744 ,
struct V_451 * V_451 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_474 ( V_91 , V_3 , V_226 ,
V_744 , V_451 ) ;
F_475 ( V_3 , V_226 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_3 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_476 ( struct V_2 * V_3 , const struct V_450 * V_226 , struct V_752 * V_753 , bool V_754 )
{
int V_283 ;
struct V_755 args = {
. V_461 = F_91 ( V_3 ) ,
. V_226 = V_226 ,
} ;
struct V_756 V_57 = {
. V_753 = V_753 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_757 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
struct V_54 * V_55 = F_3 ( V_3 ) -> V_91 ;
struct V_293 * V_327 = NULL ;
if ( V_754 ) {
V_55 = F_3 ( V_3 ) -> V_10 -> V_99 ;
V_327 = F_477 ( F_3 ( V_3 ) -> V_10 ) ;
V_159 . V_293 = V_327 ;
}
F_9 ( L_60 , V_226 -> V_226 ) ;
F_230 ( F_3 ( V_3 ) -> V_10 ,
V_758 , & V_55 , & V_159 ) ;
V_283 = F_72 ( V_55 , F_3 ( V_3 ) , & V_159 , & args . V_156 ,
& V_57 . V_157 , 0 ) ;
F_9 ( L_61 , V_283 ) ;
if ( V_327 )
F_191 ( V_327 ) ;
return V_283 ;
}
int F_478 ( struct V_2 * V_3 , const struct V_450 * V_226 ,
struct V_752 * V_753 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = - V_24 ;
if ( F_30 ( F_3 ( V_3 ) -> V_10 ) )
V_8 = F_476 ( V_3 , V_226 , V_753 , true ) ;
if ( V_8 == - V_24 )
V_8 = F_476 ( V_3 , V_226 , V_753 , false ) ;
F_479 ( V_3 , V_226 , V_8 ) ;
V_8 = F_20 ( F_3 ( V_3 ) , V_8 ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static int F_480 ( T_1 V_203 )
{
if ( V_203 & ~ V_759 )
goto V_760;
if ( ( V_203 & V_761 ) &&
( V_203 & V_762 ) )
goto V_760;
if ( ! ( V_203 & ( V_763 ) ) )
goto V_760;
return V_341 ;
V_760:
return - V_764 ;
}
static bool
F_481 ( struct V_765 * V_766 ,
struct V_765 * V_767 )
{
if ( V_766 -> V_768 == V_767 -> V_768 &&
memcmp ( V_766 -> V_769 , V_767 -> V_769 , V_766 -> V_768 ) == 0 )
return true ;
return false ;
}
int F_482 ( struct V_10 * V_65 , struct V_293 * V_327 )
{
int V_283 ;
struct V_770 V_57 ;
struct V_158 V_159 = {
. V_288 =
& V_289 [ V_771 ] ,
. V_291 = V_65 ,
. V_292 = & V_57 ,
. V_293 = V_327 ,
} ;
F_9 ( L_12 , V_37 ) ;
V_57 . V_132 = F_84 ( sizeof( struct V_131 ) , V_281 ) ;
if ( F_341 ( V_57 . V_132 == NULL ) ) {
V_283 = - V_124 ;
goto V_129;
}
V_283 = F_366 ( V_65 -> V_99 , & V_159 , V_574 ) ;
F_483 ( V_65 , V_283 ) ;
if ( V_283 == 0 ) {
if ( memcmp ( V_57 . V_132 -> V_772 . V_154 ,
V_65 -> V_87 -> V_772 . V_154 , V_773 ) ) {
F_9 ( L_62 , V_37 ) ;
V_283 = - V_38 ;
goto V_774;
}
if ( V_57 . V_3 != V_775 ) {
F_9 ( L_63 ,
V_37 ) ;
V_283 = - V_38 ;
goto V_774;
}
if ( V_57 . V_776 ) {
F_9 ( L_64 ,
V_37 ) ;
V_283 = - V_38 ;
goto V_774;
}
}
V_774:
F_94 ( V_57 . V_132 ) ;
V_129:
F_9 ( L_65 , V_37 , V_283 ) ;
return V_283 ;
}
static int F_484 ( struct V_10 * V_65 ,
struct V_777 * V_201 )
{
static const T_1 V_778 [ V_779 ] = {
[ 1 ] = 1 << ( V_780 - 32 ) |
1 << ( V_781 - 32 ) |
1 << ( V_782 - 32 ) |
1 << ( V_783 - 32 ) |
1 << ( V_784 - 32 )
} ;
unsigned int V_442 ;
if ( V_201 -> V_785 == V_786 ) {
F_485 ( V_787 , L_66 ) ;
for ( V_442 = 0 ; V_442 <= V_788 ; V_442 ++ ) {
if ( F_60 ( V_442 , V_201 -> V_789 . V_234 . V_790 ) )
F_485 ( V_787 , L_67 , V_442 ) ;
if ( F_60 ( V_442 , V_201 -> V_791 . V_234 . V_790 ) )
F_485 ( V_787 , L_68 , V_442 ) ;
}
for ( V_442 = 0 ; V_442 < V_779 ; V_442 ++ ) {
if ( V_201 -> V_789 . V_234 . V_792 [ V_442 ] & ~ V_778 [ V_442 ] ) {
F_485 ( V_787 , L_69 ) ;
return - V_29 ;
}
}
if ( F_60 ( V_780 , V_201 -> V_789 . V_234 . V_790 ) &&
F_60 ( V_782 , V_201 -> V_789 . V_234 . V_790 ) &&
F_60 ( V_783 , V_201 -> V_789 . V_234 . V_790 ) &&
F_60 ( V_784 , V_201 -> V_789 . V_234 . V_790 ) ) {
F_485 ( V_787 , L_70 ) ;
F_485 ( V_787 , L_71 ) ;
F_114 ( V_793 , & V_65 -> V_794 ) ;
} else {
F_485 ( V_787 , L_69 ) ;
return - V_29 ;
}
if ( F_60 ( V_795 , V_201 -> V_791 . V_234 . V_790 ) &&
F_60 ( V_796 , V_201 -> V_791 . V_234 . V_790 ) ) {
F_485 ( V_787 , L_72 ) ;
F_114 ( V_394 , & V_65 -> V_794 ) ;
}
if ( F_60 ( V_797 , V_201 -> V_791 . V_234 . V_790 ) &&
F_60 ( V_798 , V_201 -> V_791 . V_234 . V_790 ) ) {
F_485 ( V_787 , L_73 ) ;
F_114 ( V_758 , & V_65 -> V_794 ) ;
}
if ( F_60 ( V_799 , V_201 -> V_791 . V_234 . V_790 ) &&
F_60 ( V_800 , V_201 -> V_791 . V_234 . V_790 ) ) {
F_485 ( V_787 , L_74 ) ;
F_114 ( V_801 , & V_65 -> V_794 ) ;
}
if ( F_60 ( V_802 , V_201 -> V_791 . V_234 . V_790 ) ) {
F_485 ( V_787 , L_75 ) ;
F_114 ( V_803 , & V_65 -> V_794 ) ;
}
if ( F_60 ( V_804 , V_201 -> V_791 . V_234 . V_790 ) ) {
F_485 ( V_787 , L_76 ) ;
F_114 ( V_805 , & V_65 -> V_794 ) ;
}
}
return 0 ;
}
static int F_486 ( struct V_10 * V_65 , struct V_293 * V_327 ,
T_1 V_806 )
{
T_12 V_40 ;
struct V_807 args = {
. V_40 = & V_40 ,
. V_91 = V_65 ,
. V_203 = V_808 |
V_809 ,
} ;
struct V_810 V_57 = {
0
} ;
int V_283 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_811 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
. V_293 = V_327 ,
} ;
F_398 ( V_65 , & V_40 ) ;
args . V_812 = F_404 ( V_65 , args . V_222 ,
sizeof( args . V_222 ) ) ;
F_9 ( L_77 ,
V_65 -> V_99 -> V_100 -> V_655 -> V_656 ,
args . V_812 , args . V_222 ) ;
V_57 . V_813 = F_84 ( sizeof( struct V_814 ) ,
V_281 ) ;
if ( F_341 ( V_57 . V_813 == NULL ) ) {
V_283 = - V_124 ;
goto V_129;
}
V_57 . V_769 = F_84 ( sizeof( struct V_765 ) ,
V_281 ) ;
if ( F_341 ( V_57 . V_769 == NULL ) ) {
V_283 = - V_124 ;
goto V_815;
}
V_57 . V_816 = F_84 ( sizeof( struct V_817 ) , V_281 ) ;
if ( F_341 ( V_57 . V_816 == NULL ) ) {
V_283 = - V_124 ;
goto V_818;
}
switch ( V_806 ) {
case V_819 :
args . V_820 . V_785 = V_819 ;
break;
case V_786 :
args . V_820 = V_821 ;
break;
default:
F_487 ( 1 ) ;
V_283 = - V_29 ;
goto V_818;
}
V_283 = F_366 ( V_65 -> V_99 , & V_159 , V_574 ) ;
F_488 ( V_65 , V_283 ) ;
if ( V_283 == 0 )
V_283 = F_480 ( V_57 . V_203 ) ;
if ( V_283 == 0 )
V_283 = F_484 ( V_65 , & V_57 . V_820 ) ;
if ( V_283 == 0 ) {
V_65 -> V_221 = V_57 . V_220 ;
V_65 -> V_822 = ( V_57 . V_203 & ~ V_823 ) ;
if ( ! ( V_57 . V_203 & V_823 ) )
V_65 -> V_824 = V_57 . V_192 ;
F_94 ( V_65 -> V_825 ) ;
V_65 -> V_825 = V_57 . V_813 ;
V_57 . V_813 = NULL ;
F_94 ( V_65 -> V_826 ) ;
V_65 -> V_826 = V_57 . V_816 ;
if ( V_65 -> V_827 != NULL &&
! F_481 ( V_65 -> V_827 ,
V_57 . V_769 ) ) {
F_9 ( L_78 ,
V_37 ) ;
F_114 ( V_828 , & V_65 -> V_616 ) ;
F_94 ( V_65 -> V_827 ) ;
V_65 -> V_827 = NULL ;
}
if ( V_65 -> V_827 == NULL ) {
V_65 -> V_827 = V_57 . V_769 ;
goto V_129;
}
} else
F_94 ( V_57 . V_816 ) ;
V_815:
F_94 ( V_57 . V_813 ) ;
V_818:
F_94 ( V_57 . V_769 ) ;
V_129:
if ( V_65 -> V_826 != NULL )
F_9 ( L_79
L_80 ,
V_65 -> V_826 -> V_829 , V_65 -> V_826 -> V_226 ,
V_65 -> V_826 -> V_830 . V_831 ,
V_65 -> V_826 -> V_830 . V_832 ) ;
F_9 ( L_81 , V_283 ) ;
return V_283 ;
}
int F_489 ( struct V_10 * V_65 , struct V_293 * V_327 )
{
T_4 V_833 = V_65 -> V_99 -> V_100 -> V_101 ;
int V_283 ;
if ( V_833 == V_102 ||
V_833 == V_103 ) {
V_283 = F_486 ( V_65 , V_327 , V_786 ) ;
if ( ! V_283 )
return 0 ;
}
return F_486 ( V_65 , V_327 , V_819 ) ;
}
static int F_490 ( struct V_10 * V_65 ,
struct V_293 * V_327 )
{
struct V_158 V_159 = {
. V_288 = & V_289 [ V_834 ] ,
. V_291 = V_65 ,
. V_293 = V_327 ,
} ;
int V_283 ;
V_283 = F_366 ( V_65 -> V_99 , & V_159 , V_574 ) ;
F_491 ( V_65 , V_283 ) ;
if ( V_283 )
F_9 ( L_82
L_83 , V_283 , V_65 -> V_97 ) ;
return V_283 ;
}
static int F_492 ( struct V_10 * V_65 ,
struct V_293 * V_327 )
{
unsigned int V_835 ;
int V_68 ;
for ( V_835 = V_836 ; V_835 != 0 ; V_835 -- ) {
V_68 = F_490 ( V_65 , V_327 ) ;
switch ( V_68 ) {
case - V_90 :
case - V_837 :
F_157 ( 1 ) ;
break;
default:
return V_68 ;
}
}
return 0 ;
}
int F_493 ( struct V_10 * V_65 )
{
struct V_293 * V_327 ;
int V_68 = 0 ;
if ( V_65 -> V_164 -> V_310 < 1 )
goto V_129;
if ( V_65 -> V_822 == 0 )
goto V_129;
if ( V_65 -> V_838 )
goto V_129;
V_327 = F_477 ( V_65 ) ;
V_68 = F_492 ( V_65 , V_327 ) ;
if ( V_327 )
F_191 ( V_327 ) ;
switch ( V_68 ) {
case 0 :
case - V_78 :
V_65 -> V_822 = 0 ;
}
V_129:
return V_68 ;
}
static void F_494 ( struct V_114 * V_115 ,
void * V_152 )
{
struct V_839 * V_154 =
(struct V_839 * ) V_152 ;
F_9 ( L_12 , V_37 ) ;
F_59 ( V_154 -> V_65 -> V_87 ,
& V_154 -> args -> V_840 ,
& V_154 -> V_57 -> V_841 ,
V_115 ) ;
F_9 ( L_84 , V_37 ) ;
}
static void F_495 ( struct V_114 * V_115 , void * V_152 )
{
struct V_839 * V_154 =
(struct V_839 * ) V_152 ;
F_9 ( L_12 , V_37 ) ;
if ( ! F_52 ( V_115 , & V_154 -> V_57 -> V_841 ) )
return;
switch ( V_115 -> V_146 ) {
case - V_90 :
case - V_89 :
F_9 ( L_85 , V_37 , V_115 -> V_146 ) ;
F_57 ( V_115 , V_58 ) ;
V_115 -> V_146 = 0 ;
case - V_92 :
F_55 ( V_115 ) ;
return;
}
F_9 ( L_84 , V_37 ) ;
}
int F_496 ( struct V_10 * V_65 , struct V_428 * V_529 )
{
struct V_114 * V_115 ;
struct V_842 args ;
struct V_843 V_57 = {
. V_844 = V_529 ,
} ;
struct V_839 V_154 = {
. args = & args ,
. V_57 = & V_57 ,
. V_65 = V_65 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_845 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
struct V_160 V_161 = {
. V_162 = V_65 -> V_99 ,
. V_158 = & V_159 ,
. V_163 = & V_846 ,
. V_166 = & V_154 ,
. V_203 = V_574 ,
} ;
int V_283 ;
F_36 ( & args . V_840 , & V_57 . V_841 , 0 ) ;
F_37 ( & args . V_840 ) ;
F_9 ( L_12 , V_37 ) ;
V_115 = F_69 ( & V_161 ) ;
if ( F_41 ( V_115 ) )
V_283 = F_70 ( V_115 ) ;
else {
V_283 = V_115 -> V_146 ;
F_71 ( V_115 ) ;
}
F_9 ( L_86 , V_37 , V_283 ) ;
return V_283 ;
}
static void F_497 ( struct V_847 * args )
{
unsigned int V_848 , V_849 ;
V_848 = V_850 + V_851 ;
V_849 = V_850 + V_852 ;
args -> V_853 . V_848 = V_848 ;
args -> V_853 . V_849 = V_849 ;
args -> V_853 . V_854 = V_855 ;
args -> V_853 . V_856 = V_857 ;
F_9 ( L_87
L_88 ,
V_37 ,
args -> V_853 . V_848 , args -> V_853 . V_849 ,
args -> V_853 . V_854 , args -> V_853 . V_856 ) ;
args -> V_858 . V_848 = V_583 ;
args -> V_858 . V_849 = V_583 ;
args -> V_858 . V_859 = 0 ;
args -> V_858 . V_854 = V_860 ;
args -> V_858 . V_856 = 1 ;
F_9 ( L_89
L_90 ,
V_37 ,
args -> V_858 . V_848 , args -> V_858 . V_849 ,
args -> V_858 . V_859 , args -> V_858 . V_854 ,
args -> V_858 . V_856 ) ;
}
static int F_498 ( struct V_847 * args , struct V_131 * V_132 )
{
struct V_861 * V_862 = & args -> V_853 ;
struct V_861 * V_863 = & V_132 -> V_853 ;
if ( V_863 -> V_849 > V_862 -> V_849 )
return - V_29 ;
if ( V_863 -> V_854 < V_862 -> V_854 )
return - V_29 ;
if ( V_863 -> V_856 == 0 )
return - V_29 ;
if ( V_863 -> V_856 > V_864 )
V_863 -> V_856 = V_864 ;
return 0 ;
}
static int F_499 ( struct V_847 * args , struct V_131 * V_132 )
{
struct V_861 * V_862 = & args -> V_858 ;
struct V_861 * V_863 = & V_132 -> V_858 ;
if ( V_863 -> V_848 > V_862 -> V_848 )
return - V_29 ;
if ( V_863 -> V_849 < V_862 -> V_849 )
return - V_29 ;
if ( V_863 -> V_859 > V_862 -> V_859 )
return - V_29 ;
if ( V_863 -> V_854 != V_862 -> V_854 )
return - V_29 ;
if ( V_863 -> V_856 != V_862 -> V_856 )
return - V_29 ;
return 0 ;
}
static int F_500 ( struct V_847 * args ,
struct V_131 * V_132 )
{
int V_68 ;
V_68 = F_498 ( args , V_132 ) ;
if ( V_68 )
return V_68 ;
return F_499 ( args , V_132 ) ;
}
static int F_501 ( struct V_10 * V_65 ,
struct V_293 * V_327 )
{
struct V_131 * V_132 = V_65 -> V_87 ;
struct V_847 args = {
. V_91 = V_65 ,
. V_865 = V_866 ,
} ;
struct V_867 V_57 = {
. V_91 = V_65 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_868 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
. V_293 = V_327 ,
} ;
int V_283 ;
F_497 ( & args ) ;
args . V_203 = ( V_869 | V_870 ) ;
V_283 = F_366 ( V_132 -> V_65 -> V_99 , & V_159 , V_574 ) ;
F_502 ( V_65 , V_283 ) ;
if ( ! V_283 ) {
V_283 = F_500 ( & args , V_132 ) ;
V_65 -> V_824 ++ ;
}
return V_283 ;
}
int F_503 ( struct V_10 * V_65 , struct V_293 * V_327 )
{
int V_283 ;
unsigned * V_871 ;
struct V_131 * V_132 = V_65 -> V_87 ;
F_9 ( L_91 , V_37 , V_65 , V_132 ) ;
V_283 = F_501 ( V_65 , V_327 ) ;
if ( V_283 )
goto V_129;
V_283 = F_504 ( V_132 ) ;
F_9 ( L_92 , V_283 ) ;
if ( V_283 )
goto V_129;
V_871 = ( unsigned * ) & V_132 -> V_772 . V_154 [ 0 ] ;
F_9 ( L_93 , V_37 ,
V_65 -> V_824 , V_871 [ 0 ] , V_871 [ 1 ] , V_871 [ 2 ] , V_871 [ 3 ] ) ;
V_129:
F_9 ( L_84 , V_37 ) ;
return V_283 ;
}
int F_505 ( struct V_131 * V_132 ,
struct V_293 * V_327 )
{
struct V_158 V_159 = {
. V_288 = & V_289 [ V_872 ] ,
. V_291 = V_132 ,
. V_293 = V_327 ,
} ;
int V_283 = 0 ;
F_9 ( L_94 ) ;
if ( V_132 -> V_65 -> V_873 != V_874 )
return V_283 ;
V_283 = F_366 ( V_132 -> V_65 -> V_99 , & V_159 , V_574 ) ;
F_506 ( V_132 -> V_65 , V_283 ) ;
if ( V_283 )
F_9 ( L_95
L_96 , V_283 ) ;
F_9 ( L_97 ) ;
return V_283 ;
}
static void F_507 ( void * V_154 )
{
struct V_875 * V_152 = V_154 ;
struct V_10 * V_65 = V_152 -> V_65 ;
if ( F_356 ( & V_65 -> V_568 ) > 1 )
F_357 ( V_65 ) ;
F_358 ( V_65 ) ;
F_94 ( V_152 ) ;
}
static int F_508 ( struct V_114 * V_115 , struct V_10 * V_65 )
{
switch( V_115 -> V_146 ) {
case - V_90 :
F_57 ( V_115 , V_59 ) ;
return - V_128 ;
default:
F_25 ( V_65 ) ;
}
return 0 ;
}
static void F_509 ( struct V_114 * V_115 , void * V_154 )
{
struct V_875 * V_152 = V_154 ;
struct V_10 * V_65 = V_152 -> V_65 ;
if ( ! F_52 ( V_115 , V_115 -> V_304 . V_292 ) )
return;
F_510 ( V_65 , V_115 -> V_146 ) ;
if ( V_115 -> V_146 < 0 ) {
F_9 ( L_98 , V_37 , V_115 -> V_146 ) ;
if ( F_356 ( & V_65 -> V_568 ) == 1 )
goto V_129;
if ( F_508 ( V_115 , V_65 ) == - V_128 ) {
F_55 ( V_115 ) ;
return;
}
}
F_9 ( L_99 , V_37 , V_115 -> V_304 . V_293 ) ;
V_129:
F_9 ( L_84 , V_37 ) ;
}
static void F_511 ( struct V_114 * V_115 , void * V_154 )
{
struct V_875 * V_152 = V_154 ;
struct V_10 * V_65 = V_152 -> V_65 ;
struct V_107 * args ;
struct V_108 * V_57 ;
args = V_115 -> V_304 . V_291 ;
V_57 = V_115 -> V_304 . V_292 ;
F_59 ( V_65 -> V_87 , args , V_57 , V_115 ) ;
}
static struct V_114 * F_512 ( struct V_10 * V_65 ,
struct V_293 * V_327 ,
bool V_876 )
{
struct V_875 * V_152 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_877 ] ,
. V_293 = V_327 ,
} ;
struct V_160 V_294 = {
. V_162 = V_65 -> V_99 ,
. V_158 = & V_159 ,
. V_163 = & V_878 ,
. V_203 = V_298 | V_574 ,
} ;
if ( ! F_363 ( & V_65 -> V_568 ) )
return F_42 ( - V_38 ) ;
V_152 = F_84 ( sizeof( * V_152 ) , V_281 ) ;
if ( V_152 == NULL ) {
F_358 ( V_65 ) ;
return F_42 ( - V_124 ) ;
}
F_36 ( & V_152 -> args , & V_152 -> V_57 , 0 ) ;
if ( V_876 )
F_37 ( & V_152 -> args ) ;
V_159 . V_291 = & V_152 -> args ;
V_159 . V_292 = & V_152 -> V_57 ;
V_152 -> V_65 = V_65 ;
V_294 . V_166 = V_152 ;
return F_69 ( & V_294 ) ;
}
static int F_513 ( struct V_10 * V_65 , struct V_293 * V_327 , unsigned V_572 )
{
struct V_114 * V_115 ;
int V_68 = 0 ;
if ( ( V_572 & V_879 ) == 0 )
return 0 ;
V_115 = F_512 ( V_65 , V_327 , false ) ;
if ( F_41 ( V_115 ) )
V_68 = F_70 ( V_115 ) ;
else
F_441 ( V_115 ) ;
F_9 ( L_17 , V_37 , V_68 ) ;
return V_68 ;
}
static int F_514 ( struct V_10 * V_65 , struct V_293 * V_327 )
{
struct V_114 * V_115 ;
int V_68 ;
V_115 = F_512 ( V_65 , V_327 , true ) ;
if ( F_41 ( V_115 ) ) {
V_68 = F_70 ( V_115 ) ;
goto V_129;
}
V_68 = F_106 ( V_115 ) ;
if ( ! V_68 ) {
struct V_108 * V_57 = V_115 -> V_304 . V_292 ;
if ( V_115 -> V_146 == 0 )
F_515 ( V_65 , V_57 -> V_142 ) ;
V_68 = V_115 -> V_146 ;
}
F_71 ( V_115 ) ;
V_129:
F_9 ( L_17 , V_37 , V_68 ) ;
return V_68 ;
}
static void F_516 ( struct V_114 * V_115 , void * V_154 )
{
struct V_880 * V_152 = V_154 ;
F_59 ( V_152 -> V_65 -> V_87 ,
& V_152 -> V_370 . V_156 ,
& V_152 -> V_57 . V_157 ,
V_115 ) ;
}
static int F_517 ( struct V_114 * V_115 , struct V_10 * V_65 )
{
switch( V_115 -> V_146 ) {
case 0 :
case - V_881 :
case - V_25 :
break;
case - V_90 :
F_57 ( V_115 , V_59 ) ;
case - V_92 :
return - V_128 ;
default:
F_25 ( V_65 ) ;
}
return 0 ;
}
static void F_518 ( struct V_114 * V_115 , void * V_154 )
{
struct V_880 * V_152 = V_154 ;
struct V_10 * V_65 = V_152 -> V_65 ;
struct V_108 * V_57 = & V_152 -> V_57 . V_157 ;
F_9 ( L_12 , V_37 ) ;
if ( ! F_52 ( V_115 , V_57 ) )
return;
F_519 ( V_65 , V_115 -> V_146 ) ;
if ( F_517 ( V_115 , V_65 ) == - V_128 ) {
F_55 ( V_115 ) ;
return;
}
F_9 ( L_84 , V_37 ) ;
}
static void F_520 ( void * V_154 )
{
struct V_880 * V_152 = V_154 ;
F_94 ( V_152 ) ;
}
static int F_521 ( struct V_10 * V_65 ,
struct V_293 * V_327 )
{
struct V_880 * V_152 ;
struct V_114 * V_115 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_882 ] ,
. V_293 = V_327 ,
} ;
struct V_160 V_294 = {
. V_162 = V_65 -> V_99 ,
. V_158 = & V_159 ,
. V_163 = & V_883 ,
. V_203 = V_298 ,
} ;
int V_283 = - V_124 ;
F_9 ( L_12 , V_37 ) ;
V_152 = F_84 ( sizeof( * V_152 ) , V_281 ) ;
if ( V_152 == NULL )
goto V_129;
V_152 -> V_65 = V_65 ;
V_152 -> V_370 . V_884 = 0 ;
F_36 ( & V_152 -> V_370 . V_156 , & V_152 -> V_57 . V_157 , 0 ) ;
F_37 ( & V_152 -> V_370 . V_156 ) ;
V_159 . V_291 = & V_152 -> V_370 ;
V_159 . V_292 = & V_152 -> V_57 ;
V_294 . V_166 = V_152 ;
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) ) {
V_283 = F_70 ( V_115 ) ;
goto V_129;
}
V_283 = F_105 ( V_115 ) ;
if ( V_283 == 0 )
V_283 = V_115 -> V_146 ;
F_71 ( V_115 ) ;
return 0 ;
V_129:
F_9 ( L_17 , V_37 , V_283 ) ;
return V_283 ;
}
static void
F_522 ( struct V_114 * V_115 , void * V_152 )
{
struct V_885 * V_886 = V_152 ;
struct V_15 * V_16 = F_3 ( V_886 -> args . V_2 ) ;
struct V_131 * V_132 = F_63 ( V_16 ) ;
F_9 ( L_12 , V_37 ) ;
if ( F_59 ( V_132 , & V_886 -> args . V_156 ,
& V_886 -> V_57 . V_157 , V_115 ) )
return;
if ( F_523 ( & V_886 -> args . V_236 ,
F_74 ( V_886 -> args . V_2 ) -> V_887 ,
V_886 -> args . V_279 -> V_67 ) ) {
F_524 ( V_115 , V_888 ) ;
}
}
static void F_525 ( struct V_114 * V_115 , void * V_152 )
{
struct V_885 * V_886 = V_152 ;
struct V_2 * V_2 = V_886 -> args . V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_889 * V_890 ;
struct V_66 * V_67 = NULL ;
unsigned long V_891 , V_892 ;
F_9 ( L_12 , V_37 ) ;
if ( ! F_52 ( V_115 , & V_886 -> V_57 . V_157 ) )
goto V_129;
switch ( V_115 -> V_146 ) {
case 0 :
goto V_129;
case - V_21 :
case - V_22 :
V_891 = F_526 ( V_115 -> V_893 ) ;
V_892 = V_886 -> args . V_104 + V_891 ;
if ( F_527 ( V_892 , V_151 ) )
V_115 -> V_146 = - V_90 ;
break;
case - V_76 :
case - V_75 :
F_32 ( & V_2 -> V_171 ) ;
V_890 = F_74 ( V_2 ) -> V_887 ;
if ( ! V_890 || F_528 ( & V_890 -> V_894 ) ) {
F_34 ( & V_2 -> V_171 ) ;
V_67 = V_886 -> args . V_279 -> V_67 ;
} else {
F_529 ( V_895 ) ;
F_530 ( V_890 , & V_895 , NULL ) ;
F_34 ( & V_2 -> V_171 ) ;
F_531 ( & V_895 ) ;
}
}
if ( F_226 ( V_115 , V_16 , V_67 ) == - V_128 )
F_55 ( V_115 ) ;
V_129:
F_9 ( L_84 , V_37 ) ;
}
static T_9 F_532 ( struct V_15 * V_16 )
{
T_1 V_849 = V_16 -> V_10 -> V_87 -> V_853 . V_849 ;
return F_533 ( 0 , V_849 ) ;
}
static void F_534 ( struct V_451 * * V_45 , T_9 V_896 )
{
int V_442 ;
if ( ! V_45 )
return;
for ( V_442 = 0 ; V_442 < V_896 ; V_442 ++ ) {
if ( ! V_45 [ V_442 ] )
break;
F_258 ( V_45 [ V_442 ] ) ;
}
F_94 ( V_45 ) ;
}
static struct V_451 * * F_535 ( T_9 V_896 , T_6 V_897 )
{
struct V_451 * * V_45 ;
int V_442 ;
V_45 = F_536 ( V_896 , sizeof( struct V_451 * ) , V_897 ) ;
if ( ! V_45 ) {
F_9 ( L_100 , V_37 , V_896 ) ;
return NULL ;
}
for ( V_442 = 0 ; V_442 < V_896 ; V_442 ++ ) {
V_45 [ V_442 ] = F_254 ( V_897 ) ;
if ( ! V_45 [ V_442 ] ) {
F_9 ( L_101 , V_37 ) ;
F_534 ( V_45 , V_896 ) ;
return NULL ;
}
}
return V_45 ;
}
static void F_537 ( void * V_152 )
{
struct V_885 * V_886 = V_152 ;
struct V_2 * V_2 = V_886 -> args . V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
T_9 V_898 = F_532 ( V_16 ) ;
F_9 ( L_12 , V_37 ) ;
F_534 ( V_886 -> args . V_887 . V_45 , V_898 ) ;
F_538 ( F_74 ( V_2 ) -> V_887 ) ;
F_154 ( V_886 -> args . V_279 ) ;
F_94 ( V_152 ) ;
F_9 ( L_84 , V_37 ) ;
}
struct V_899 *
F_539 ( struct V_885 * V_886 , T_6 V_897 )
{
struct V_2 * V_2 = V_886 -> args . V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
T_9 V_898 = F_532 ( V_16 ) ;
struct V_114 * V_115 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_900 ] ,
. V_291 = & V_886 -> args ,
. V_292 = & V_886 -> V_57 ,
. V_293 = V_886 -> V_327 ,
} ;
struct V_160 V_294 = {
. V_162 = V_16 -> V_91 ,
. V_158 = & V_159 ,
. V_163 = & V_901 ,
. V_166 = V_886 ,
. V_203 = V_298 ,
} ;
struct V_899 * V_902 = NULL ;
int V_283 = 0 ;
F_9 ( L_12 , V_37 ) ;
V_886 -> args . V_887 . V_45 = F_535 ( V_898 , V_897 ) ;
if ( ! V_886 -> args . V_887 . V_45 ) {
F_537 ( V_886 ) ;
return F_42 ( - V_124 ) ;
}
V_886 -> args . V_887 . V_478 = V_898 * V_583 ;
V_886 -> args . V_104 = V_151 ;
V_886 -> V_57 . V_903 = & V_886 -> args . V_887 ;
V_886 -> V_57 . V_157 . V_113 = NULL ;
F_36 ( & V_886 -> args . V_156 , & V_886 -> V_57 . V_157 , 0 ) ;
F_540 ( F_74 ( V_2 ) -> V_887 ) ;
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) )
return F_233 ( V_115 ) ;
V_283 = F_105 ( V_115 ) ;
if ( V_283 == 0 )
V_283 = V_115 -> V_146 ;
F_541 ( V_886 -> args . V_279 ,
& V_886 -> args . V_904 ,
& V_886 -> V_57 . V_904 ,
V_283 ) ;
if ( V_283 == 0 && V_886 -> V_57 . V_903 -> V_14 )
V_902 = F_542 ( V_886 ) ;
F_71 ( V_115 ) ;
F_9 ( L_17 , V_37 , V_283 ) ;
if ( V_283 )
return F_42 ( V_283 ) ;
return V_902 ;
}
static void
F_543 ( struct V_114 * V_115 , void * V_152 )
{
struct V_905 * V_906 = V_152 ;
F_9 ( L_12 , V_37 ) ;
F_59 ( V_906 -> V_65 -> V_87 ,
& V_906 -> args . V_156 ,
& V_906 -> V_57 . V_157 ,
V_115 ) ;
}
static void F_544 ( struct V_114 * V_115 , void * V_152 )
{
struct V_905 * V_906 = V_152 ;
struct V_15 * V_16 ;
F_9 ( L_12 , V_37 ) ;
if ( ! F_52 ( V_115 , & V_906 -> V_57 . V_157 ) )
return;
V_16 = F_3 ( V_906 -> args . V_2 ) ;
if ( F_226 ( V_115 , V_16 , NULL ) == - V_128 ) {
F_55 ( V_115 ) ;
return;
}
F_9 ( L_84 , V_37 ) ;
}
static void F_545 ( void * V_152 )
{
struct V_905 * V_906 = V_152 ;
struct V_889 * V_890 = V_906 -> args . V_887 ;
F_9 ( L_12 , V_37 ) ;
F_32 ( & V_890 -> V_907 -> V_171 ) ;
if ( V_906 -> V_57 . V_908 )
F_546 ( V_890 , & V_906 -> V_57 . V_236 , true ) ;
V_890 -> V_909 -- ;
F_34 ( & V_890 -> V_907 -> V_171 ) ;
F_538 ( V_906 -> args . V_887 ) ;
F_94 ( V_152 ) ;
F_9 ( L_84 , V_37 ) ;
}
int F_547 ( struct V_905 * V_906 )
{
struct V_114 * V_115 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_910 ] ,
. V_291 = & V_906 -> args ,
. V_292 = & V_906 -> V_57 ,
. V_293 = V_906 -> V_327 ,
} ;
struct V_160 V_294 = {
. V_162 = F_3 ( V_906 -> args . V_2 ) -> V_91 ,
. V_158 = & V_159 ,
. V_163 = & V_911 ,
. V_166 = V_906 ,
} ;
int V_283 ;
F_9 ( L_12 , V_37 ) ;
F_36 ( & V_906 -> args . V_156 , & V_906 -> V_57 . V_157 , 1 ) ;
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
V_283 = V_115 -> V_146 ;
F_548 ( V_906 -> args . V_2 , V_283 ) ;
F_9 ( L_17 , V_37 , V_283 ) ;
F_71 ( V_115 ) ;
return V_283 ;
}
static int F_549 ( struct V_15 * V_16 ,
const struct V_399 * V_230 ,
struct V_912 * V_913 )
{
struct V_914 args = {
. V_230 = V_230 ,
. V_915 = V_16 -> V_916 -> V_222 ,
} ;
struct V_917 V_57 = {
. V_913 = V_913 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_918 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
int V_283 ;
F_9 ( L_12 , V_37 ) ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 ,
& V_57 . V_157 , 0 ) ;
F_9 ( L_17 , V_37 , V_283 ) ;
return V_283 ;
}
int F_550 ( struct V_15 * V_16 ,
const struct V_399 * V_230 ,
struct V_912 * V_913 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_549 ( V_16 , V_230 , V_913 ) ,
& V_64 ) ;
} while ( V_64 . V_69 );
F_9 ( L_102 , V_37 ,
V_8 , V_913 -> V_919 ) ;
return V_8 ;
}
static int
F_551 ( struct V_15 * V_16 ,
struct V_920 * V_921 ,
struct V_293 * V_327 )
{
struct V_922 args = {
. V_921 = V_921 ,
} ;
struct V_923 V_57 = {
. V_921 = V_921 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_924 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
. V_293 = V_327 ,
} ;
int V_283 ;
F_9 ( L_12 , V_37 ) ;
V_283 = F_72 ( V_16 -> V_91 , V_16 , & V_159 , & args . V_156 , & V_57 . V_157 , 0 ) ;
F_9 ( L_17 , V_37 , V_283 ) ;
return V_283 ;
}
int F_552 ( struct V_15 * V_16 ,
struct V_920 * V_921 ,
struct V_293 * V_327 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_551 ( V_16 , V_921 , V_327 ) ,
& V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static void F_553 ( struct V_114 * V_115 , void * V_152 )
{
struct V_925 * V_154 = V_152 ;
struct V_15 * V_16 = F_3 ( V_154 -> args . V_2 ) ;
struct V_131 * V_132 = F_63 ( V_16 ) ;
F_59 ( V_132 ,
& V_154 -> args . V_156 ,
& V_154 -> V_57 . V_157 ,
V_115 ) ;
}
static void
F_554 ( struct V_114 * V_115 , void * V_152 )
{
struct V_925 * V_154 = V_152 ;
struct V_15 * V_16 = F_3 ( V_154 -> args . V_2 ) ;
if ( ! F_52 ( V_115 , & V_154 -> V_57 . V_157 ) )
return;
switch ( V_115 -> V_146 ) {
case - V_73 :
case - V_926 :
case - V_927 :
case - V_89 :
V_115 -> V_146 = 0 ;
break;
case 0 :
F_344 ( V_154 -> args . V_2 ,
V_154 -> V_57 . V_367 ) ;
break;
default:
if ( F_226 ( V_115 , V_16 , NULL ) == - V_128 ) {
F_55 ( V_115 ) ;
return;
}
}
}
static void F_555 ( void * V_152 )
{
struct V_925 * V_154 = V_152 ;
F_556 ( V_154 ) ;
F_191 ( V_154 -> V_327 ) ;
F_94 ( V_154 ) ;
}
int
F_557 ( struct V_925 * V_154 , bool V_928 )
{
struct V_158 V_159 = {
. V_288 = & V_289 [ V_929 ] ,
. V_291 = & V_154 -> args ,
. V_292 = & V_154 -> V_57 ,
. V_293 = V_154 -> V_327 ,
} ;
struct V_160 V_294 = {
. V_115 = & V_154 -> V_115 ,
. V_162 = F_271 ( V_154 -> args . V_2 ) ,
. V_158 = & V_159 ,
. V_163 = & V_930 ,
. V_166 = V_154 ,
. V_203 = V_298 ,
} ;
struct V_114 * V_115 ;
int V_283 = 0 ;
F_9 ( L_103
L_104 ,
V_154 -> V_115 . V_931 , V_928 ,
V_154 -> args . V_932 ,
V_154 -> args . V_2 -> V_933 ) ;
F_36 ( & V_154 -> args . V_156 , & V_154 -> V_57 . V_157 , 1 ) ;
V_115 = F_69 ( & V_294 ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
if ( V_928 == false )
goto V_129;
V_283 = F_105 ( V_115 ) ;
if ( V_283 != 0 )
goto V_129;
V_283 = V_115 -> V_146 ;
F_558 ( V_154 -> args . V_2 , V_283 ) ;
V_129:
F_9 ( L_105 , V_37 , V_283 ) ;
F_71 ( V_115 ) ;
return V_283 ;
}
static int
F_559 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_429 ,
struct V_752 * V_753 , bool V_754 )
{
struct V_934 args = {
. V_935 = V_936 ,
} ;
struct V_756 V_57 = {
. V_753 = V_753 ,
} ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_937 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
} ;
struct V_54 * V_55 = V_16 -> V_91 ;
struct V_293 * V_327 = NULL ;
int V_283 ;
if ( V_754 ) {
V_55 = V_16 -> V_10 -> V_99 ;
V_327 = F_477 ( V_16 -> V_10 ) ;
V_159 . V_293 = V_327 ;
}
F_9 ( L_12 , V_37 ) ;
V_283 = F_72 ( V_55 , V_16 , & V_159 , & args . V_156 ,
& V_57 . V_157 , 0 ) ;
F_9 ( L_17 , V_37 , V_283 ) ;
if ( V_327 )
F_191 ( V_327 ) ;
return V_283 ;
}
static int
F_560 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_429 , struct V_752 * V_753 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = - V_24 ;
if ( F_30 ( V_16 -> V_10 ) )
V_8 = F_559 ( V_16 , V_400 , V_429 ,
V_753 , true ) ;
if ( V_8 == - V_24 )
V_8 = F_559 ( V_16 , V_400 , V_429 ,
V_753 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_24 :
case - V_938 :
goto V_129;
default:
V_8 = F_20 ( V_16 , V_8 , & V_64 ) ;
}
} while ( V_64 . V_69 );
V_129:
return V_8 ;
}
static int
F_561 ( struct V_15 * V_16 , struct V_399 * V_400 ,
struct V_428 * V_429 )
{
int V_8 ;
struct V_451 * V_451 ;
T_4 V_98 = V_939 ;
struct V_752 * V_753 ;
struct V_940 * V_941 ;
int V_442 ;
V_451 = F_254 ( V_358 ) ;
if ( ! V_451 ) {
V_8 = - V_124 ;
goto V_129;
}
V_753 = F_370 ( V_451 ) ;
V_8 = F_560 ( V_16 , V_400 , V_429 , V_753 ) ;
if ( V_8 == - V_24 || V_8 == - V_938 ) {
V_8 = F_244 ( V_16 , V_400 , V_429 ) ;
goto V_942;
}
if ( V_8 )
goto V_942;
for ( V_442 = 0 ; V_442 < V_753 -> V_943 ; V_442 ++ ) {
V_941 = & V_753 -> V_753 [ V_442 ] ;
switch ( V_941 -> V_98 ) {
case V_441 :
case V_440 :
case V_944 :
V_98 = F_562 ( V_941 -> V_98 ,
& V_941 -> V_945 ) ;
break;
default:
V_98 = V_939 ;
break;
}
if ( V_98 != V_939 ) {
V_8 = F_242 ( V_16 , V_400 ,
V_429 , V_98 ) ;
if ( ! V_8 )
break;
}
}
if ( V_98 == V_939 )
V_8 = - V_26 ;
V_942:
F_384 ( V_451 ) ;
if ( V_8 == - V_31 )
return - V_26 ;
V_129:
return V_8 ;
}
static int F_563 ( struct V_15 * V_16 ,
T_8 * V_236 ,
struct V_293 * V_327 )
{
int V_283 ;
struct V_946 args = {
. V_236 = V_236 ,
} ;
struct V_947 V_57 ;
struct V_158 V_159 = {
. V_288 = & V_289 [ V_948 ] ,
. V_291 = & args ,
. V_292 = & V_57 ,
. V_293 = V_327 ,
} ;
struct V_54 * V_162 = V_16 -> V_91 ;
F_230 ( V_16 -> V_10 , V_801 ,
& V_162 , & V_159 ) ;
F_9 ( L_106 , V_236 ) ;
F_36 ( & args . V_156 , & V_57 . V_157 , 0 ) ;
F_37 ( & args . V_156 ) ;
V_283 = F_68 ( V_162 , V_16 , & V_159 ,
& args . V_156 , & V_57 . V_157 ) ;
if ( V_283 != V_341 ) {
F_9 ( L_107 , V_283 ) ;
return V_283 ;
}
F_9 ( L_108 , - V_57 . V_283 ) ;
return - V_57 . V_283 ;
}
static int F_188 ( struct V_15 * V_16 ,
T_8 * V_236 ,
struct V_293 * V_327 )
{
struct V_63 V_64 = { } ;
int V_8 ;
do {
V_8 = F_563 ( V_16 , V_236 , V_327 ) ;
if ( V_8 != - V_90 )
break;
F_20 ( V_16 , V_8 , & V_64 ) ;
} while ( V_64 . V_69 );
return V_8 ;
}
static void F_564 ( struct V_114 * V_115 , void * V_152 )
{
struct V_949 * V_154 = V_152 ;
F_59 ( F_63 ( V_154 -> V_16 ) ,
& V_154 -> args . V_156 ,
& V_154 -> V_57 . V_157 ,
V_115 ) ;
}
static void F_565 ( struct V_114 * V_115 , void * V_152 )
{
struct V_949 * V_154 = V_152 ;
F_52 ( V_115 , & V_154 -> V_57 . V_157 ) ;
switch ( V_115 -> V_146 ) {
case - V_90 :
if ( F_226 ( V_115 , V_154 -> V_16 , NULL ) == - V_128 )
F_55 ( V_115 ) ;
}
}
static void F_566 ( void * V_152 )
{
F_94 ( V_152 ) ;
}
static struct V_114 * F_567 ( struct V_15 * V_16 ,
T_8 * V_236 ,
struct V_293 * V_327 ,
bool V_950 )
{
struct V_158 V_159 = {
. V_288 = & V_289 [ V_951 ] ,
. V_293 = V_327 ,
} ;
struct V_160 V_161 = {
. V_162 = V_16 -> V_91 ,
. V_158 = & V_159 ,
. V_163 = & V_952 ,
. V_203 = V_298 ,
} ;
struct V_949 * V_154 ;
F_230 ( V_16 -> V_10 , V_801 ,
& V_161 . V_162 , & V_159 ) ;
F_9 ( L_109 , V_236 ) ;
V_154 = F_255 ( sizeof( * V_154 ) , V_281 ) ;
if ( ! V_154 )
return F_42 ( - V_124 ) ;
V_154 -> V_16 = V_16 ;
F_113 ( & V_154 -> args . V_236 , V_236 ) ;
V_161 . V_166 = V_154 ;
V_159 . V_291 = & V_154 -> args ;
V_159 . V_292 = & V_154 -> V_57 ;
F_36 ( & V_154 -> args . V_156 , & V_154 -> V_57 . V_157 , 0 ) ;
if ( V_950 )
F_37 ( & V_154 -> args . V_156 ) ;
return F_69 ( & V_161 ) ;
}
static int F_190 ( struct V_15 * V_16 ,
T_8 * V_236 ,
struct V_293 * V_327 )
{
struct V_114 * V_115 ;
int V_68 ;
V_115 = F_567 ( V_16 , V_236 , V_327 , true ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
V_68 = F_106 ( V_115 ) ;
if ( ! V_68 )
V_68 = V_115 -> V_146 ;
F_71 ( V_115 ) ;
return V_68 ;
}
static int F_568 ( struct V_15 * V_16 , struct V_672 * V_673 )
{
struct V_114 * V_115 ;
struct V_293 * V_327 = V_673 -> V_689 -> V_211 -> V_266 ;
V_115 = F_567 ( V_16 , & V_673 -> V_690 , V_327 , false ) ;
F_463 ( V_16 , V_673 ) ;
if ( F_41 ( V_115 ) )
return F_70 ( V_115 ) ;
F_71 ( V_115 ) ;
return 0 ;
}
static bool F_569 ( const T_8 * V_953 ,
const T_8 * V_954 )
{
if ( memcmp ( V_953 -> V_955 , V_954 -> V_955 , sizeof( V_953 -> V_955 ) ) != 0 )
return false ;
if ( V_953 -> V_192 == V_954 -> V_192 )
return true ;
if ( V_953 -> V_192 == 0 || V_954 -> V_192 == 0 )
return true ;
return false ;
}
static bool F_570 ( const T_8 * V_953 ,
const T_8 * V_954 )
{
return F_122 ( V_953 , V_954 ) ;
}
