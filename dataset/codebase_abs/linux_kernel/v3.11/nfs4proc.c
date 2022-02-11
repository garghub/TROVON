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
return - V_25 ;
case - V_26 :
case - V_27 :
return - V_28 ;
case - V_29 :
return - V_30 ;
case - V_31 :
return - V_32 ;
case - V_33 :
return - V_30 ;
case - V_34 :
return - V_35 ;
default:
F_9 ( L_1 ,
V_36 , - V_8 ) ;
break;
}
return - V_37 ;
}
static void F_10 ( T_2 V_38 , T_3 * V_39 , struct V_4 * V_4 ,
struct V_40 * V_41 )
{
T_3 * V_42 , * V_43 ;
if ( V_38 > 2 ) {
V_41 -> V_38 = V_38 ;
memcpy ( & V_41 -> V_39 , V_39 , sizeof( V_41 -> V_39 ) ) ;
return;
}
V_41 -> V_38 = 0 ;
memset ( & V_41 -> V_39 , 0 , sizeof( V_41 -> V_39 ) ) ;
if ( V_38 == 2 )
return;
V_42 = V_43 = F_11 ( * V_41 -> V_44 ) ;
if ( V_38 == 0 ) {
* V_43 ++ = V_45 ;
* V_43 ++ = V_46 ;
* V_43 ++ = V_45 ;
* V_43 ++ = V_45 ;
memcpy ( V_43 , L_2 , 4 ) ;
V_43 ++ ;
* V_43 ++ = V_45 ;
* V_43 ++ = F_12 ( V_47 ) ;
* V_43 ++ = F_12 ( 8 ) ;
V_43 = F_13 ( V_43 , F_14 ( V_4 -> V_48 ) ) ;
}
* V_43 ++ = V_45 ;
* V_43 ++ = V_46 ;
* V_43 ++ = V_49 ;
* V_43 ++ = V_49 ;
memcpy ( V_43 , L_3 , 4 ) ;
V_43 ++ ;
* V_43 ++ = V_45 ;
* V_43 ++ = F_12 ( V_47 ) ;
* V_43 ++ = F_12 ( 8 ) ;
V_43 = F_13 ( V_43 , F_14 ( V_4 -> V_50 -> V_48 ) ) ;
V_41 -> V_51 = ( char * ) V_43 - ( char * ) V_42 ;
V_41 -> V_52 -= V_41 -> V_51 ;
F_15 ( V_42 ) ;
}
static int F_16 ( struct V_53 * V_54 , long * V_55 )
{
int V_56 = 0 ;
F_17 () ;
if ( * V_55 <= 0 )
* V_55 = V_57 ;
if ( * V_55 > V_58 )
* V_55 = V_58 ;
F_18 ( * V_55 ) ;
if ( F_19 ( V_59 ) )
V_56 = - V_60 ;
* V_55 <<= 1 ;
return V_56 ;
}
static int F_20 ( struct V_15 * V_16 , int V_61 , struct V_62 * V_63 )
{
struct V_10 * V_64 = V_16 -> V_10 ;
struct V_65 * V_66 = V_63 -> V_66 ;
struct V_2 * V_2 = V_63 -> V_2 ;
int V_67 = V_61 ;
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
if ( V_66 == NULL )
break;
V_67 = F_23 ( V_16 , V_66 ) ;
if ( V_67 < 0 )
break;
goto V_71;
case - V_72 :
case - V_73 :
case - V_74 :
if ( V_2 != NULL && F_21 ( V_2 , V_70 ) ) {
F_24 ( V_2 ) ;
V_63 -> V_68 = 1 ;
break;
}
if ( V_66 == NULL )
break;
V_67 = F_23 ( V_16 , V_66 ) ;
if ( V_67 < 0 )
break;
goto V_71;
case - V_75 :
if ( V_66 != NULL ) {
V_67 = F_23 ( V_16 , V_66 ) ;
if ( V_67 < 0 )
break;
}
case - V_76 :
case - V_77 :
F_25 ( V_64 ) ;
goto V_71;
#if F_26 ( V_78 )
case - V_79 :
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
F_9 ( L_4 , V_36 ,
V_61 ) ;
F_27 ( V_64 -> V_86 , V_61 ) ;
goto V_71;
#endif
case - V_34 :
if ( V_63 -> V_55 > V_87 ) {
V_67 = - V_35 ;
break;
}
case - V_88 :
case - V_89 :
V_67 = F_16 ( V_16 -> V_90 , & V_63 -> V_55 ) ;
if ( V_67 != 0 )
break;
case - V_91 :
case - V_92 :
V_63 -> V_68 = 1 ;
break;
case - V_26 :
case - V_27 :
if ( V_16 -> V_93 & V_94 ) {
V_16 -> V_93 &= ~ V_94 ;
V_63 -> V_68 = 1 ;
F_28 ( V_95 L_5
L_6
L_7
L_8 ,
V_16 -> V_10 -> V_96 ) ;
}
}
return F_8 ( V_67 ) ;
V_71:
V_67 = F_29 ( V_64 ) ;
if ( V_67 == 0 )
V_63 -> V_68 = 1 ;
return V_67 ;
}
static void F_30 ( struct V_10 * V_64 , unsigned long V_97 )
{
F_31 ( & V_64 -> V_98 ) ;
if ( F_32 ( V_64 -> V_99 , V_97 ) )
V_64 -> V_99 = V_97 ;
F_33 ( & V_64 -> V_98 ) ;
}
static void F_34 ( const struct V_15 * V_16 , unsigned long V_97 )
{
F_30 ( V_16 -> V_10 , V_97 ) ;
}
static void F_35 ( struct V_100 * V_56 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
bool V_105 = false ;
if ( ! V_56 -> V_106 ) {
F_9 ( L_9 , V_36 ) ;
return;
}
V_104 = V_56 -> V_106 -> V_107 ;
V_102 = V_104 -> V_102 ;
F_31 ( & V_104 -> V_108 ) ;
if ( V_104 -> V_109 > V_104 -> V_110 )
V_105 = true ;
if ( F_36 ( V_104 , V_56 -> V_106 ) ) {
V_105 = false ;
goto V_111;
}
F_37 ( V_104 , V_56 -> V_106 ) ;
if ( V_104 -> V_109 != V_112 )
V_105 = false ;
V_111:
F_33 ( & V_104 -> V_108 ) ;
V_56 -> V_106 = NULL ;
if ( V_105 )
F_38 ( V_102 -> V_64 ) ;
}
static int F_39 ( struct V_113 * V_114 , struct V_100 * V_56 )
{
struct V_101 * V_102 ;
struct V_115 * V_116 ;
struct V_10 * V_64 ;
bool V_117 = false ;
int V_67 = 1 ;
if ( ! F_40 ( V_114 ) )
goto V_118;
V_116 = V_56 -> V_106 ;
V_102 = V_116 -> V_107 -> V_102 ;
if ( V_116 -> V_117 ) {
V_116 -> V_117 = 0 ;
V_117 = true ;
}
switch ( V_56 -> V_119 ) {
case 0 :
++ V_116 -> V_120 ;
V_64 = V_102 -> V_64 ;
F_30 ( V_64 , V_56 -> V_121 ) ;
if ( V_56 -> V_122 != 0 )
F_25 ( V_64 ) ;
F_41 ( V_116 -> V_107 , V_116 , V_56 ) ;
break;
case 1 :
V_116 -> V_117 = 1 ;
goto V_118;
case - V_89 :
F_9 ( L_10 ,
V_36 ,
V_116 -> V_123 ,
V_116 -> V_120 ) ;
goto V_124;
case - V_80 :
goto V_125;
case - V_85 :
if ( V_117 ) {
++ V_116 -> V_120 ;
goto V_125;
}
if ( V_116 -> V_120 != 1 ) {
V_116 -> V_120 = 1 ;
goto V_125;
}
break;
case - V_84 :
++ V_116 -> V_120 ;
goto V_125;
default:
++ V_116 -> V_120 ;
}
V_118:
F_9 ( L_11 , V_36 , V_56 -> V_119 ) ;
F_35 ( V_56 ) ;
return V_67 ;
V_125:
if ( F_42 ( V_114 ) ) {
V_114 -> V_126 = 0 ;
V_67 = 0 ;
}
goto V_118;
V_124:
if ( ! F_43 ( V_114 ) )
goto V_118;
F_44 ( V_114 , V_58 ) ;
return 0 ;
}
static int F_45 ( struct V_113 * V_114 ,
struct V_100 * V_56 )
{
if ( V_56 -> V_106 == NULL )
return 1 ;
return F_39 ( V_114 , V_56 ) ;
}
static void F_46 ( struct V_127 * args ,
struct V_100 * V_56 , int V_128 )
{
args -> V_129 = NULL ;
args -> V_130 = 0 ;
args -> V_131 = 0 ;
if ( V_128 )
args -> V_130 = 1 ;
V_56 -> V_106 = NULL ;
}
static void F_47 ( struct V_127 * args )
{
args -> V_131 = 1 ;
}
int F_48 ( struct V_101 * V_102 ,
struct V_127 * args ,
struct V_100 * V_56 ,
struct V_113 * V_114 )
{
struct V_115 * V_116 ;
struct V_103 * V_104 ;
F_9 ( L_12 , V_36 ) ;
if ( V_56 -> V_106 != NULL )
goto V_132;
V_104 = & V_102 -> V_133 ;
V_114 -> V_134 = 0 ;
F_31 ( & V_104 -> V_108 ) ;
if ( F_49 ( V_135 , & V_104 -> V_136 ) &&
! args -> V_131 ) {
F_9 ( L_13 , V_36 ) ;
goto V_137;
}
V_116 = F_50 ( V_104 ) ;
if ( F_51 ( V_116 ) ) {
if ( V_116 == F_52 ( - V_138 ) )
V_114 -> V_134 = V_87 >> 2 ;
F_9 ( L_14 , V_36 ) ;
goto V_137;
}
F_33 ( & V_104 -> V_108 ) ;
args -> V_129 = V_116 ;
F_9 ( L_15 , V_36 ,
V_116 -> V_123 , V_116 -> V_120 ) ;
V_56 -> V_106 = V_116 ;
V_56 -> V_121 = V_139 ;
V_56 -> V_122 = 0 ;
V_56 -> V_119 = 1 ;
V_132:
F_53 ( V_114 ) ;
return 0 ;
V_137:
if ( args -> V_131 )
F_54 ( & V_104 -> V_140 , V_114 ,
NULL , V_141 ) ;
else
F_55 ( & V_104 -> V_140 , V_114 , NULL ) ;
F_33 ( & V_104 -> V_108 ) ;
return - V_142 ;
}
int F_56 ( const struct V_15 * V_16 ,
struct V_127 * args ,
struct V_100 * V_56 ,
struct V_113 * V_114 )
{
struct V_101 * V_102 = F_57 ( V_16 ) ;
int V_67 = 0 ;
if ( V_102 == NULL ) {
F_53 ( V_114 ) ;
goto V_118;
}
F_9 ( L_16 ,
V_36 , V_102 -> V_64 , V_102 , V_56 -> V_106 ?
V_56 -> V_106 -> V_123 : - 1 ) ;
V_67 = F_48 ( V_102 , args , V_56 , V_114 ) ;
V_118:
F_9 ( L_17 , V_36 , V_67 ) ;
return V_67 ;
}
static void F_58 ( struct V_113 * V_114 , void * V_143 )
{
struct V_144 * V_145 = V_143 ;
struct V_101 * V_102 = F_57 ( V_145 -> V_146 ) ;
F_9 ( L_18 , V_36 , V_145 -> V_146 ) ;
F_48 ( V_102 , V_145 -> V_147 , V_145 -> V_148 , V_114 ) ;
}
static void F_59 ( struct V_113 * V_114 , void * V_143 )
{
struct V_144 * V_145 = V_143 ;
F_39 ( V_114 , V_145 -> V_148 ) ;
}
static int F_60 ( struct V_53 * V_54 ,
struct V_15 * V_16 ,
struct V_149 * V_150 ,
struct V_127 * args ,
struct V_100 * V_56 )
{
int V_67 ;
struct V_113 * V_114 ;
struct V_144 V_145 = {
. V_146 = V_16 ,
. V_147 = args ,
. V_148 = V_56 ,
} ;
struct V_151 V_152 = {
. V_153 = V_54 ,
. V_149 = V_150 ,
. V_154 = & V_155 ,
. V_156 = & V_145
} ;
V_114 = F_61 ( & V_152 ) ;
if ( F_51 ( V_114 ) )
V_67 = F_62 ( V_114 ) ;
else {
V_67 = V_114 -> V_126 ;
F_63 ( V_114 ) ;
}
return V_67 ;
}
static
void F_46 ( struct V_127 * args ,
struct V_100 * V_56 , int V_128 )
{
}
static void F_47 ( struct V_127 * args )
{
}
static int F_45 ( struct V_113 * V_114 ,
struct V_100 * V_56 )
{
return 1 ;
}
static
int F_64 ( struct V_53 * V_54 ,
struct V_15 * V_16 ,
struct V_149 * V_150 ,
struct V_127 * args ,
struct V_100 * V_56 )
{
return F_65 ( V_54 , V_150 , 0 ) ;
}
static
int F_66 ( struct V_53 * V_54 ,
struct V_15 * V_16 ,
struct V_149 * V_150 ,
struct V_127 * args ,
struct V_100 * V_56 ,
int V_128 )
{
F_46 ( args , V_56 , V_128 ) ;
return V_16 -> V_10 -> V_157 -> V_158 ( V_54 , V_16 , V_150 ,
args , V_56 ) ;
}
static void F_67 ( struct V_2 * V_3 , struct V_159 * V_160 )
{
struct V_161 * V_162 = F_68 ( V_3 ) ;
F_31 ( & V_3 -> V_163 ) ;
V_162 -> V_164 |= V_165 | V_166 ;
if ( ! V_160 -> V_167 || V_160 -> V_168 != V_3 -> V_169 )
F_69 ( V_3 ) ;
V_3 -> V_169 = V_160 -> V_170 ;
F_70 ( V_3 ) ;
F_33 ( & V_3 -> V_163 ) ;
}
static bool F_71 ( struct V_15 * V_16 ,
int V_8 , struct V_62 * V_63 )
{
if ( V_8 != - V_28 )
return false ;
if ( ! ( V_16 -> V_93 & V_171 ) )
return false ;
V_16 -> V_93 &= ~ V_171 ;
V_63 -> V_68 = 1 ;
return true ;
}
static enum V_172
F_72 ( struct V_15 * V_16 ,
enum V_172 V_173 )
{
if ( V_16 -> V_93 & V_171 )
return V_173 ;
switch ( V_173 ) {
default:
return V_173 ;
case V_174 :
return V_175 ;
case V_176 :
return V_177 ;
case V_178 :
return V_179 ;
}
}
static void F_73 ( struct V_180 * V_43 )
{
V_43 -> V_181 . V_182 = & V_43 -> V_182 ;
V_43 -> V_181 . V_183 = V_43 -> V_183 ;
V_43 -> V_181 . V_184 = V_43 -> V_185 . V_184 ;
V_43 -> V_186 . V_184 = V_43 -> V_187 . V_184 ;
V_43 -> V_181 . V_16 = V_43 -> V_185 . V_16 ;
V_43 -> V_181 . V_188 = V_43 -> V_185 . V_189 ;
F_74 ( & V_43 -> V_182 ) ;
F_75 ( & V_43 -> V_182 , & V_43 -> V_190 , & V_43 -> V_191 ) ;
}
static struct V_180 * F_76 ( struct V_4 * V_4 ,
struct V_192 * V_193 , T_4 V_194 , int V_195 ,
const struct V_5 * V_196 ,
struct V_1 * V_7 ,
enum V_172 V_173 ,
T_5 V_197 )
{
struct V_4 * V_198 = F_77 ( V_4 ) ;
struct V_2 * V_3 = V_198 -> V_48 ;
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_180 * V_43 ;
V_43 = F_78 ( sizeof( * V_43 ) , V_197 ) ;
if ( V_43 == NULL )
goto V_8;
V_43 -> V_183 = F_79 ( V_16 , V_197 ) ;
if ( F_51 ( V_43 -> V_183 ) )
goto V_199;
V_43 -> V_185 . V_184 = F_80 ( & V_193 -> V_200 , V_197 ) ;
if ( V_43 -> V_185 . V_184 == NULL )
goto V_201;
F_81 ( V_4 -> V_202 ) ;
V_43 -> V_4 = F_82 ( V_4 ) ;
V_43 -> V_3 = V_198 ;
V_43 -> V_203 = V_193 ;
F_83 ( & V_193 -> V_204 ) ;
V_43 -> V_185 . V_205 = V_195 ;
V_43 -> V_185 . V_194 = V_194 & ( V_70 | V_206 ) ;
if ( ! ( V_195 & V_207 ) ) {
V_43 -> V_185 . V_189 = V_208 | V_209 |
V_210 | V_211 ;
}
V_43 -> V_185 . V_212 = V_16 -> V_10 -> V_213 ;
V_43 -> V_185 . V_214 . V_215 = F_84 ( V_193 -> V_200 . V_215 ) ;
V_43 -> V_185 . V_214 . V_216 = V_193 -> V_200 . V_217 ;
V_43 -> V_185 . V_218 = & V_4 -> V_13 ;
V_43 -> V_185 . V_16 = V_16 ;
V_43 -> V_185 . V_219 = F_7 ( V_16 , V_7 ) ;
V_43 -> V_185 . V_220 = & V_221 [ 0 ] ;
V_43 -> V_185 . V_7 = V_7 ;
V_43 -> V_185 . V_173 = F_72 ( V_16 , V_173 ) ;
switch ( V_43 -> V_185 . V_173 ) {
case V_175 :
case V_177 :
case V_179 :
V_43 -> V_185 . V_222 = F_85 ( V_3 ) ;
break;
case V_223 :
case V_174 :
case V_176 :
case V_178 :
V_43 -> V_185 . V_222 = F_85 ( V_4 -> V_48 ) ;
}
if ( V_196 != NULL && V_196 -> V_224 != 0 ) {
T_3 V_225 [ 2 ] ;
V_43 -> V_185 . V_226 . V_196 = & V_43 -> V_196 ;
memcpy ( & V_43 -> V_196 , V_196 , sizeof( V_43 -> V_196 ) ) ;
V_225 [ 0 ] = V_139 ;
V_225 [ 1 ] = V_59 -> V_227 ;
memcpy ( V_43 -> V_185 . V_226 . V_39 . V_145 , V_225 ,
sizeof( V_43 -> V_185 . V_226 . V_39 . V_145 ) ) ;
}
V_43 -> V_187 . V_222 = & V_43 -> V_181 . V_222 ;
V_43 -> V_187 . V_228 = & V_43 -> V_181 . V_228 ;
V_43 -> V_187 . V_184 = V_43 -> V_185 . V_184 ;
F_73 ( V_43 ) ;
F_86 ( & V_43 -> V_229 ) ;
return V_43 ;
V_201:
F_87 ( V_43 -> V_183 ) ;
V_199:
F_88 ( V_43 ) ;
V_8:
F_89 ( V_198 ) ;
return NULL ;
}
static void F_90 ( struct V_229 * V_229 )
{
struct V_180 * V_43 = F_91 ( V_229 ,
struct V_180 , V_229 ) ;
struct V_230 * V_231 = V_43 -> V_4 -> V_202 ;
F_92 ( V_43 -> V_185 . V_184 ) ;
if ( V_43 -> V_66 != NULL )
F_93 ( V_43 -> V_66 ) ;
F_94 ( V_43 -> V_203 ) ;
F_87 ( V_43 -> V_183 ) ;
F_89 ( V_43 -> V_3 ) ;
F_89 ( V_43 -> V_4 ) ;
F_95 ( V_231 ) ;
F_96 ( & V_43 -> V_182 ) ;
F_88 ( V_43 ) ;
}
static void F_97 ( struct V_180 * V_43 )
{
if ( V_43 != NULL )
F_98 ( & V_43 -> V_229 , F_90 ) ;
}
static int F_99 ( struct V_113 * V_114 )
{
int V_67 ;
V_67 = F_100 ( V_114 ) ;
return V_67 ;
}
static int F_101 ( struct V_65 * V_66 , T_4 V_232 , int V_233 )
{
int V_67 = 0 ;
if ( V_233 & ( V_207 | V_234 ) )
goto V_118;
switch ( V_232 & ( V_70 | V_206 ) ) {
case V_70 :
V_67 |= F_49 ( V_235 , & V_66 -> V_195 ) != 0
&& V_66 -> V_236 != 0 ;
break;
case V_206 :
V_67 |= F_49 ( V_237 , & V_66 -> V_195 ) != 0
&& V_66 -> V_238 != 0 ;
break;
case V_70 | V_206 :
V_67 |= F_49 ( V_239 , & V_66 -> V_195 ) != 0
&& V_66 -> V_240 != 0 ;
}
V_118:
return V_67 ;
}
static int F_102 ( struct V_241 * V_242 , T_4 V_194 )
{
if ( V_242 == NULL )
return 0 ;
if ( ( V_242 -> type & V_194 ) != V_194 )
return 0 ;
if ( F_49 ( V_243 , & V_242 -> V_195 ) )
return 0 ;
if ( F_49 ( V_244 , & V_242 -> V_195 ) )
return 0 ;
F_103 ( V_242 ) ;
return 1 ;
}
static void F_104 ( struct V_65 * V_66 , T_4 V_194 )
{
switch ( V_194 ) {
case V_206 :
V_66 -> V_238 ++ ;
break;
case V_70 :
V_66 -> V_236 ++ ;
break;
case V_70 | V_206 :
V_66 -> V_240 ++ ;
}
F_105 ( V_66 , V_66 -> V_66 | V_194 ) ;
}
static void F_106 ( struct V_65 * V_66 , T_6 * V_228 , T_4 V_194 )
{
if ( F_49 ( V_245 , & V_66 -> V_195 ) == 0 )
F_107 ( & V_66 -> V_228 , V_228 ) ;
F_107 ( & V_66 -> V_246 , V_228 ) ;
F_108 ( V_247 , & V_66 -> V_195 ) ;
switch ( V_194 ) {
case V_70 :
F_108 ( V_235 , & V_66 -> V_195 ) ;
break;
case V_206 :
F_108 ( V_237 , & V_66 -> V_195 ) ;
break;
case V_70 | V_206 :
F_108 ( V_239 , & V_66 -> V_195 ) ;
}
}
static void F_109 ( struct V_65 * V_66 , T_6 * V_228 , T_4 V_194 )
{
F_110 ( & V_66 -> V_248 ) ;
F_106 ( V_66 , V_228 , V_194 ) ;
F_111 ( & V_66 -> V_248 ) ;
}
static void F_112 ( struct V_65 * V_66 , T_6 * V_246 , const T_6 * V_249 , T_4 V_194 )
{
F_110 ( & V_66 -> V_248 ) ;
if ( V_249 != NULL ) {
F_107 ( & V_66 -> V_228 , V_249 ) ;
F_108 ( V_245 , & V_66 -> V_195 ) ;
}
if ( V_246 != NULL )
F_106 ( V_66 , V_246 , V_194 ) ;
F_111 ( & V_66 -> V_248 ) ;
F_31 ( & V_66 -> V_203 -> V_250 ) ;
F_104 ( V_66 , V_194 ) ;
F_33 ( & V_66 -> V_203 -> V_250 ) ;
}
static int F_113 ( struct V_65 * V_66 , T_6 * V_246 , T_6 * V_242 , T_4 V_194 )
{
struct V_161 * V_162 = F_68 ( V_66 -> V_2 ) ;
struct V_241 * V_251 ;
int V_67 = 0 ;
V_194 &= ( V_70 | V_206 ) ;
F_114 () ;
V_251 = F_115 ( V_162 -> V_242 ) ;
if ( V_251 == NULL )
goto V_252;
F_31 ( & V_251 -> V_253 ) ;
if ( V_162 -> V_242 != V_251 ||
F_49 ( V_244 , & V_251 -> V_195 ) ||
( V_251 -> type & V_194 ) != V_194 )
goto V_254;
if ( V_242 == NULL )
V_242 = & V_251 -> V_228 ;
else if ( ! F_116 ( & V_251 -> V_228 , V_242 ) )
goto V_254;
F_103 ( V_251 ) ;
F_112 ( V_66 , V_246 , & V_251 -> V_228 , V_194 ) ;
V_67 = 1 ;
V_254:
F_33 ( & V_251 -> V_253 ) ;
V_252:
F_117 () ;
if ( ! V_67 && V_246 != NULL ) {
F_112 ( V_66 , V_246 , NULL , V_194 ) ;
V_67 = 1 ;
}
return V_67 ;
}
static void F_118 ( struct V_2 * V_2 , T_4 V_194 )
{
struct V_241 * V_242 ;
F_114 () ;
V_242 = F_115 ( F_68 ( V_2 ) -> V_242 ) ;
if ( V_242 == NULL || ( V_242 -> type & V_194 ) == V_194 ) {
F_117 () ;
return;
}
F_117 () ;
F_22 ( V_2 ) ;
}
static struct V_65 * F_119 ( struct V_180 * V_255 )
{
struct V_65 * V_66 = V_255 -> V_66 ;
struct V_161 * V_162 = F_68 ( V_66 -> V_2 ) ;
struct V_241 * V_242 ;
int V_233 = V_255 -> V_185 . V_205 ;
T_4 V_194 = V_255 -> V_185 . V_194 ;
T_6 V_228 ;
int V_67 = - V_142 ;
for (; ; ) {
if ( F_101 ( V_66 , V_194 , V_233 ) ) {
F_31 ( & V_66 -> V_203 -> V_250 ) ;
if ( F_101 ( V_66 , V_194 , V_233 ) ) {
F_104 ( V_66 , V_194 ) ;
F_33 ( & V_66 -> V_203 -> V_250 ) ;
goto V_256;
}
F_33 ( & V_66 -> V_203 -> V_250 ) ;
}
F_114 () ;
V_242 = F_115 ( V_162 -> V_242 ) ;
if ( ! F_102 ( V_242 , V_194 ) ) {
F_117 () ;
break;
}
F_107 ( & V_228 , & V_242 -> V_228 ) ;
F_117 () ;
F_120 ( V_255 -> V_185 . V_184 ) ;
if ( ! V_255 -> V_257 ) {
V_67 = F_121 ( V_66 -> V_2 , V_66 -> V_203 -> V_258 , V_233 ) ;
if ( V_67 != 0 )
goto V_118;
}
V_67 = - V_142 ;
if ( F_113 ( V_66 , NULL , & V_228 , V_194 ) )
goto V_256;
}
V_118:
return F_52 ( V_67 ) ;
V_256:
F_83 ( & V_66 -> V_52 ) ;
return V_66 ;
}
static void
F_122 ( struct V_180 * V_145 , struct V_65 * V_66 )
{
struct V_10 * V_64 = F_3 ( V_66 -> V_2 ) -> V_10 ;
struct V_241 * V_242 ;
int V_259 = 0 ;
F_114 () ;
V_242 = F_115 ( F_68 ( V_66 -> V_2 ) -> V_242 ) ;
if ( V_242 )
V_259 = V_242 -> V_195 ;
F_117 () ;
if ( V_145 -> V_185 . V_173 == V_177 ) {
F_123 ( L_19
L_20
L_21 ,
V_64 -> V_96 ) ;
} else if ( ( V_259 & 1UL << V_243 ) == 0 )
F_124 ( V_66 -> V_2 ,
V_145 -> V_203 -> V_258 ,
& V_145 -> V_181 ) ;
else
F_125 ( V_66 -> V_2 ,
V_145 -> V_203 -> V_258 ,
& V_145 -> V_181 ) ;
}
static struct V_65 *
F_126 ( struct V_180 * V_145 )
{
struct V_2 * V_2 = V_145 -> V_66 -> V_2 ;
struct V_65 * V_66 = V_145 -> V_66 ;
int V_67 ;
if ( ! V_145 -> V_260 ) {
V_67 = V_145 -> V_261 ;
goto V_8;
}
V_67 = - V_262 ;
if ( ! ( V_145 -> V_182 . V_263 & V_264 ) ||
! ( V_145 -> V_182 . V_263 & V_265 ) ||
! ( V_145 -> V_182 . V_263 & V_266 ) )
goto V_8;
V_67 = - V_138 ;
V_66 = F_127 ( V_2 , V_145 -> V_203 ) ;
if ( V_66 == NULL )
goto V_8;
V_67 = F_128 ( V_2 , & V_145 -> V_182 ) ;
if ( V_67 )
goto V_8;
F_129 ( V_2 , & V_145 -> V_182 , V_145 -> V_183 ) ;
if ( V_145 -> V_181 . V_267 != 0 )
F_122 ( V_145 , V_66 ) ;
F_113 ( V_66 , & V_145 -> V_181 . V_228 , NULL ,
V_145 -> V_185 . V_194 ) ;
return V_66 ;
V_8:
return F_52 ( V_67 ) ;
}
static struct V_65 *
F_130 ( struct V_180 * V_145 )
{
struct V_2 * V_2 ;
struct V_65 * V_66 = NULL ;
int V_67 ;
if ( ! V_145 -> V_260 ) {
V_66 = F_119 ( V_145 ) ;
goto V_118;
}
V_67 = - V_142 ;
if ( ! ( V_145 -> V_182 . V_263 & V_268 ) )
goto V_8;
V_2 = F_131 ( V_145 -> V_3 -> V_202 , & V_145 -> V_181 . V_222 , & V_145 -> V_182 , V_145 -> V_183 ) ;
V_67 = F_62 ( V_2 ) ;
if ( F_51 ( V_2 ) )
goto V_8;
V_67 = - V_138 ;
V_66 = F_127 ( V_2 , V_145 -> V_203 ) ;
if ( V_66 == NULL )
goto V_269;
if ( V_145 -> V_181 . V_267 != 0 )
F_122 ( V_145 , V_66 ) ;
F_113 ( V_66 , & V_145 -> V_181 . V_228 , NULL ,
V_145 -> V_185 . V_194 ) ;
F_132 ( V_2 ) ;
V_118:
F_120 ( V_145 -> V_185 . V_184 ) ;
return V_66 ;
V_269:
F_132 ( V_2 ) ;
V_8:
return F_52 ( V_67 ) ;
}
static struct V_65 *
F_133 ( struct V_180 * V_145 )
{
if ( V_145 -> V_185 . V_173 == V_223 )
return F_126 ( V_145 ) ;
return F_130 ( V_145 ) ;
}
static struct V_270 * F_134 ( struct V_65 * V_66 )
{
struct V_161 * V_162 = F_68 ( V_66 -> V_2 ) ;
struct V_270 * V_271 ;
F_31 ( & V_66 -> V_2 -> V_163 ) ;
F_135 (ctx, &nfsi->open_files, list) {
if ( V_271 -> V_66 != V_66 )
continue;
F_136 ( V_271 ) ;
F_33 ( & V_66 -> V_2 -> V_163 ) ;
return V_271 ;
}
F_33 ( & V_66 -> V_2 -> V_163 ) ;
return F_52 ( - V_272 ) ;
}
static struct V_180 * F_137 ( struct V_270 * V_271 ,
struct V_65 * V_66 , enum V_172 V_173 )
{
struct V_180 * V_255 ;
V_255 = F_76 ( V_271 -> V_4 , V_66 -> V_203 , 0 , 0 ,
NULL , NULL , V_173 , V_273 ) ;
if ( V_255 == NULL )
return F_52 ( - V_138 ) ;
V_255 -> V_66 = V_66 ;
F_83 ( & V_66 -> V_52 ) ;
return V_255 ;
}
static int F_138 ( struct V_180 * V_255 , T_4 V_194 , struct V_65 * * V_56 )
{
struct V_65 * V_274 ;
int V_67 ;
V_255 -> V_185 . V_205 = 0 ;
V_255 -> V_185 . V_194 = V_194 ;
memset ( & V_255 -> V_181 , 0 , sizeof( V_255 -> V_181 ) ) ;
memset ( & V_255 -> V_186 , 0 , sizeof( V_255 -> V_186 ) ) ;
F_73 ( V_255 ) ;
V_67 = F_139 ( V_255 ) ;
if ( V_67 != 0 )
return V_67 ;
V_274 = F_133 ( V_255 ) ;
if ( F_51 ( V_274 ) )
return F_62 ( V_274 ) ;
F_140 ( V_274 , V_194 ) ;
* V_56 = V_274 ;
return 0 ;
}
static int F_141 ( struct V_180 * V_255 , struct V_65 * V_66 )
{
struct V_65 * V_274 ;
int V_67 ;
F_142 ( V_245 , & V_66 -> V_195 ) ;
F_142 ( V_247 , & V_66 -> V_195 ) ;
F_143 () ;
if ( V_66 -> V_240 != 0 ) {
F_142 ( V_239 , & V_66 -> V_195 ) ;
V_67 = F_138 ( V_255 , V_70 | V_206 , & V_274 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_274 != V_66 )
return - V_262 ;
}
if ( V_66 -> V_238 != 0 ) {
F_142 ( V_237 , & V_66 -> V_195 ) ;
V_67 = F_138 ( V_255 , V_206 , & V_274 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_274 != V_66 )
return - V_262 ;
}
if ( V_66 -> V_236 != 0 ) {
F_142 ( V_235 , & V_66 -> V_195 ) ;
V_67 = F_138 ( V_255 , V_70 , & V_274 ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_274 != V_66 )
return - V_262 ;
}
if ( F_49 ( V_245 , & V_66 -> V_195 ) == 0 &&
! F_116 ( & V_66 -> V_228 , & V_66 -> V_246 ) ) {
F_110 ( & V_66 -> V_248 ) ;
if ( F_49 ( V_245 , & V_66 -> V_195 ) == 0 )
F_107 ( & V_66 -> V_228 , & V_66 -> V_246 ) ;
F_111 ( & V_66 -> V_248 ) ;
}
return 0 ;
}
static int F_144 ( struct V_270 * V_271 , struct V_65 * V_66 )
{
struct V_241 * V_242 ;
struct V_180 * V_255 ;
T_4 V_267 = 0 ;
int V_275 ;
V_255 = F_137 ( V_271 , V_66 ,
V_223 ) ;
if ( F_51 ( V_255 ) )
return F_62 ( V_255 ) ;
F_114 () ;
V_242 = F_115 ( F_68 ( V_66 -> V_2 ) -> V_242 ) ;
if ( V_242 != NULL && F_49 ( V_243 , & V_242 -> V_195 ) != 0 )
V_267 = V_242 -> type ;
F_117 () ;
V_255 -> V_185 . V_226 . V_267 = V_267 ;
V_275 = F_141 ( V_255 , V_66 ) ;
F_97 ( V_255 ) ;
return V_275 ;
}
static int F_145 ( struct V_270 * V_271 , struct V_65 * V_66 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_144 ( V_271 , V_66 ) ;
if ( F_71 ( V_16 , V_8 , & V_63 ) )
continue;
if ( V_8 != - V_89 )
break;
F_20 ( V_16 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_146 ( struct V_192 * V_193 , struct V_65 * V_66 )
{
struct V_270 * V_271 ;
int V_67 ;
V_271 = F_134 ( V_66 ) ;
if ( F_51 ( V_271 ) )
return - V_142 ;
V_67 = F_145 ( V_271 , V_66 ) ;
F_147 ( V_271 ) ;
return V_67 ;
}
static int F_148 ( struct V_15 * V_16 , struct V_65 * V_66 , const T_6 * V_228 , int V_8 )
{
switch ( V_8 ) {
default:
F_28 ( V_276 L_22
L_23 , V_36 , V_8 ) ;
case 0 :
case - V_272 :
case - V_262 :
break;
case - V_79 :
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
F_108 ( V_245 , & V_66 -> V_195 ) ;
F_27 ( V_16 -> V_10 -> V_86 , V_8 ) ;
return - V_142 ;
case - V_77 :
case - V_76 :
F_108 ( V_245 , & V_66 -> V_195 ) ;
case - V_75 :
F_25 ( V_16 -> V_10 ) ;
return - V_142 ;
case - V_72 :
case - V_73 :
case - V_74 :
case - V_69 :
F_149 ( V_66 -> V_2 ,
V_228 ) ;
F_23 ( V_16 , V_66 ) ;
return 0 ;
case - V_89 :
case - V_88 :
F_108 ( V_245 , & V_66 -> V_195 ) ;
F_150 ( 1 ) ;
return - V_142 ;
case - V_138 :
case - V_277 :
return 0 ;
}
return V_8 ;
}
int F_151 ( struct V_270 * V_271 , struct V_65 * V_66 , const T_6 * V_228 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
struct V_180 * V_255 ;
int V_8 ;
V_255 = F_137 ( V_271 , V_66 ,
V_176 ) ;
if ( F_51 ( V_255 ) )
return F_62 ( V_255 ) ;
F_107 ( & V_255 -> V_185 . V_226 . V_242 , V_228 ) ;
V_8 = F_141 ( V_255 , V_66 ) ;
F_97 ( V_255 ) ;
return F_148 ( V_16 , V_66 , V_228 , V_8 ) ;
}
static void F_152 ( struct V_113 * V_114 , void * V_143 )
{
struct V_180 * V_145 = V_143 ;
V_145 -> V_261 = V_114 -> V_126 ;
if ( V_145 -> V_261 == 0 ) {
F_107 ( & V_145 -> V_181 . V_228 , & V_145 -> V_186 . V_228 ) ;
F_153 ( & V_145 -> V_203 -> V_200 , 0 ) ;
F_34 ( V_145 -> V_181 . V_16 , V_145 -> V_97 ) ;
V_145 -> V_260 = 1 ;
}
}
static void F_154 ( void * V_143 )
{
struct V_180 * V_145 = V_143 ;
struct V_65 * V_66 = NULL ;
if ( V_145 -> V_278 == 0 )
goto V_279;
if ( ! V_145 -> V_260 )
goto V_279;
V_66 = F_133 ( V_145 ) ;
if ( ! F_51 ( V_66 ) )
F_140 ( V_66 , V_145 -> V_185 . V_194 ) ;
V_279:
F_97 ( V_145 ) ;
}
static int F_155 ( struct V_180 * V_145 )
{
struct V_15 * V_16 = F_3 ( V_145 -> V_3 -> V_48 ) ;
struct V_113 * V_114 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_282 ] ,
. V_283 = & V_145 -> V_187 ,
. V_284 = & V_145 -> V_186 ,
. V_285 = V_145 -> V_203 -> V_258 ,
} ;
struct V_151 V_286 = {
. V_153 = V_16 -> V_90 ,
. V_149 = & V_150 ,
. V_154 = & V_287 ,
. V_156 = V_145 ,
. V_288 = V_289 ,
. V_195 = V_290 ,
} ;
int V_275 ;
F_156 ( & V_145 -> V_229 ) ;
V_145 -> V_260 = 0 ;
V_145 -> V_261 = 0 ;
V_145 -> V_97 = V_139 ;
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
V_275 = F_99 ( V_114 ) ;
if ( V_275 != 0 ) {
V_145 -> V_278 = 1 ;
F_157 () ;
} else
V_275 = V_145 -> V_261 ;
F_63 ( V_114 ) ;
return V_275 ;
}
static void F_158 ( struct V_113 * V_114 , void * V_143 )
{
struct V_180 * V_145 = V_143 ;
struct V_192 * V_193 = V_145 -> V_203 ;
struct V_10 * V_64 = V_193 -> V_291 -> V_10 ;
if ( F_159 ( V_145 -> V_185 . V_184 , V_114 ) != 0 )
goto V_292;
if ( V_145 -> V_66 != NULL ) {
struct V_241 * V_242 ;
if ( F_101 ( V_145 -> V_66 , V_145 -> V_185 . V_194 , V_145 -> V_185 . V_205 ) )
goto V_293;
F_114 () ;
V_242 = F_115 ( F_68 ( V_145 -> V_66 -> V_2 ) -> V_242 ) ;
if ( V_145 -> V_185 . V_173 != V_177 &&
V_145 -> V_185 . V_173 != V_176 &&
F_102 ( V_242 , V_145 -> V_185 . V_194 ) )
goto V_294;
F_117 () ;
}
V_145 -> V_185 . V_212 = V_64 -> V_213 ;
switch ( V_145 -> V_185 . V_173 ) {
case V_223 :
case V_176 :
case V_178 :
V_145 -> V_185 . V_220 = & V_295 [ 0 ] ;
case V_174 :
V_114 -> V_296 . V_280 = & V_281 [ V_297 ] ;
F_160 ( & V_145 -> V_181 . V_222 , V_145 -> V_185 . V_222 ) ;
}
V_145 -> V_97 = V_139 ;
if ( F_56 ( V_145 -> V_185 . V_16 ,
& V_145 -> V_185 . V_147 ,
& V_145 -> V_181 . V_148 ,
V_114 ) != 0 )
F_120 ( V_145 -> V_185 . V_184 ) ;
V_145 -> V_185 . V_298 = V_299 ;
if ( V_145 -> V_185 . V_205 & V_207 ) {
V_145 -> V_185 . V_298 = V_300 ;
if ( F_161 ( V_64 ) )
V_145 -> V_185 . V_298 = V_301 ;
else if ( V_64 -> V_157 -> V_302 > 0 )
V_145 -> V_185 . V_298 = V_303 ;
}
return;
V_294:
F_117 () ;
V_293:
V_114 -> V_304 = NULL ;
V_292:
F_45 ( V_114 , & V_145 -> V_181 . V_148 ) ;
}
static void F_162 ( struct V_113 * V_114 , void * V_143 )
{
struct V_180 * V_145 = V_143 ;
V_145 -> V_261 = V_114 -> V_126 ;
if ( ! F_45 ( V_114 , & V_145 -> V_181 . V_148 ) )
return;
if ( V_114 -> V_126 == 0 ) {
if ( V_145 -> V_181 . V_182 -> V_263 & V_264 ) {
switch ( V_145 -> V_181 . V_182 -> V_232 & V_305 ) {
case V_306 :
break;
case V_307 :
V_145 -> V_261 = - V_308 ;
break;
case V_309 :
V_145 -> V_261 = - V_310 ;
break;
default:
V_145 -> V_261 = - V_311 ;
}
}
F_34 ( V_145 -> V_181 . V_16 , V_145 -> V_97 ) ;
if ( ! ( V_145 -> V_181 . V_312 & V_313 ) )
F_153 ( & V_145 -> V_203 -> V_200 , 0 ) ;
}
V_145 -> V_260 = 1 ;
}
static void F_163 ( void * V_143 )
{
struct V_180 * V_145 = V_143 ;
struct V_65 * V_66 = NULL ;
if ( V_145 -> V_278 == 0 )
goto V_279;
if ( V_145 -> V_261 != 0 || ! V_145 -> V_260 )
goto V_279;
if ( V_145 -> V_181 . V_312 & V_313 )
goto V_279;
V_66 = F_133 ( V_145 ) ;
if ( ! F_51 ( V_66 ) )
F_140 ( V_66 , V_145 -> V_185 . V_194 ) ;
V_279:
F_97 ( V_145 ) ;
}
static int F_164 ( struct V_180 * V_145 , int V_314 )
{
struct V_2 * V_3 = V_145 -> V_3 -> V_48 ;
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_315 * V_185 = & V_145 -> V_185 ;
struct V_316 * V_181 = & V_145 -> V_181 ;
struct V_113 * V_114 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_317 ] ,
. V_283 = V_185 ,
. V_284 = V_181 ,
. V_285 = V_145 -> V_203 -> V_258 ,
} ;
struct V_151 V_286 = {
. V_153 = V_16 -> V_90 ,
. V_149 = & V_150 ,
. V_154 = & V_318 ,
. V_156 = V_145 ,
. V_288 = V_289 ,
. V_195 = V_290 ,
} ;
int V_275 ;
F_46 ( & V_185 -> V_147 , & V_181 -> V_148 , 1 ) ;
F_156 ( & V_145 -> V_229 ) ;
V_145 -> V_260 = 0 ;
V_145 -> V_261 = 0 ;
V_145 -> V_278 = 0 ;
V_145 -> V_257 = 0 ;
if ( V_314 ) {
F_47 ( & V_185 -> V_147 ) ;
V_145 -> V_257 = 1 ;
}
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
V_275 = F_99 ( V_114 ) ;
if ( V_275 != 0 ) {
V_145 -> V_278 = 1 ;
F_157 () ;
} else
V_275 = V_145 -> V_261 ;
F_63 ( V_114 ) ;
return V_275 ;
}
static int F_139 ( struct V_180 * V_145 )
{
struct V_2 * V_3 = V_145 -> V_3 -> V_48 ;
struct V_316 * V_181 = & V_145 -> V_181 ;
int V_275 ;
V_275 = F_164 ( V_145 , 1 ) ;
if ( V_275 != 0 || ! V_145 -> V_260 )
return V_275 ;
F_165 ( F_3 ( V_3 ) , & V_145 -> V_182 ) ;
if ( V_181 -> V_312 & V_313 ) {
V_275 = F_155 ( V_145 ) ;
if ( V_275 != 0 )
return V_275 ;
}
return V_275 ;
}
static int F_166 ( struct V_285 * V_319 ,
struct V_180 * V_255 ,
struct V_65 * V_66 , T_4 V_194 ,
int V_320 )
{
struct V_321 V_322 ;
T_1 V_323 ;
if ( V_255 -> V_181 . V_324 == 0 )
return 0 ;
V_323 = 0 ;
if ( V_320 & V_325 ) {
V_323 = V_326 ;
} else if ( V_194 & V_70 )
V_323 = V_327 ;
V_322 . V_319 = V_319 ;
V_322 . V_139 = V_139 ;
F_167 ( & V_322 , V_255 -> V_181 . V_328 ) ;
F_168 ( V_66 -> V_2 , & V_322 ) ;
if ( ( V_323 & ~ V_322 . V_323 & ( V_327 | V_326 ) ) == 0 )
return 0 ;
F_140 ( V_66 , V_194 ) ;
return - V_30 ;
}
static int F_169 ( struct V_180 * V_145 )
{
struct V_2 * V_3 = V_145 -> V_3 -> V_48 ;
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_315 * V_185 = & V_145 -> V_185 ;
struct V_316 * V_181 = & V_145 -> V_181 ;
int V_275 ;
V_275 = F_164 ( V_145 , 0 ) ;
if ( ! V_145 -> V_260 )
return V_275 ;
if ( V_275 != 0 ) {
if ( V_275 == - V_27 &&
! ( V_185 -> V_205 & V_329 ) )
return - V_272 ;
return V_275 ;
}
F_165 ( V_16 , & V_145 -> V_182 ) ;
if ( V_185 -> V_205 & V_329 )
F_67 ( V_3 , & V_181 -> V_160 ) ;
if ( ( V_181 -> V_312 & V_330 ) == 0 )
V_16 -> V_93 &= ~ V_331 ;
if( V_181 -> V_312 & V_313 ) {
V_275 = F_155 ( V_145 ) ;
if ( V_275 != 0 )
return V_275 ;
}
if ( ! ( V_181 -> V_182 -> V_263 & V_268 ) )
F_170 ( V_16 , & V_181 -> V_222 , V_181 -> V_182 , V_181 -> V_183 ) ;
return 0 ;
}
static int F_171 ( struct V_15 * V_16 )
{
return F_172 ( V_16 -> V_10 ) ;
}
static int F_173 ( struct V_270 * V_271 , struct V_65 * V_66 )
{
struct V_180 * V_255 ;
int V_67 ;
V_255 = F_137 ( V_271 , V_66 ,
V_174 ) ;
if ( F_51 ( V_255 ) )
return F_62 ( V_255 ) ;
V_67 = F_141 ( V_255 , V_66 ) ;
if ( V_67 == - V_262 )
F_174 ( V_271 -> V_4 ) ;
F_97 ( V_255 ) ;
return V_67 ;
}
static int F_175 ( struct V_270 * V_271 , struct V_65 * V_66 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_173 ( V_271 , V_66 ) ;
if ( F_71 ( V_16 , V_8 , & V_63 ) )
continue;
switch ( V_8 ) {
default:
goto V_118;
case - V_88 :
case - V_89 :
F_20 ( V_16 , V_8 , & V_63 ) ;
V_8 = 0 ;
}
} while ( V_63 . V_68 );
V_118:
return V_8 ;
}
static int F_176 ( struct V_192 * V_193 , struct V_65 * V_66 )
{
struct V_270 * V_271 ;
int V_67 ;
V_271 = F_134 ( V_66 ) ;
if ( F_51 ( V_271 ) )
return - V_142 ;
V_67 = F_175 ( V_271 , V_66 ) ;
F_147 ( V_271 ) ;
return V_67 ;
}
static void F_177 ( struct V_65 * V_66 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
T_6 * V_228 = & V_66 -> V_228 ;
struct V_241 * V_242 ;
struct V_285 * V_319 = NULL ;
int V_275 = - V_74 ;
if ( F_49 ( V_245 , & V_66 -> V_195 ) == 0 )
return;
F_114 () ;
V_242 = F_115 ( F_68 ( V_66 -> V_2 ) -> V_242 ) ;
if ( V_242 != NULL &&
F_116 ( & V_242 -> V_228 , V_228 ) ) {
V_319 = F_178 ( V_242 -> V_319 ) ;
F_117 () ;
V_275 = F_179 ( V_16 , V_228 , V_319 ) ;
} else
F_117 () ;
if ( V_275 != V_332 ) {
if ( V_275 != - V_74 )
F_180 ( V_16 , V_228 , V_319 ) ;
F_24 ( V_66 -> V_2 ) ;
F_110 ( & V_66 -> V_248 ) ;
F_107 ( & V_66 -> V_228 , & V_66 -> V_246 ) ;
F_111 ( & V_66 -> V_248 ) ;
F_142 ( V_245 , & V_66 -> V_195 ) ;
}
if ( V_319 != NULL )
F_181 ( V_319 ) ;
}
static int F_182 ( struct V_65 * V_66 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
T_6 * V_228 = & V_66 -> V_246 ;
struct V_285 * V_319 = V_66 -> V_203 -> V_258 ;
int V_275 ;
if ( ( F_49 ( V_235 , & V_66 -> V_195 ) == 0 ) &&
( F_49 ( V_237 , & V_66 -> V_195 ) == 0 ) &&
( F_49 ( V_239 , & V_66 -> V_195 ) == 0 ) )
return - V_74 ;
V_275 = F_179 ( V_16 , V_228 , V_319 ) ;
if ( V_275 != V_332 ) {
if ( V_275 != - V_74 )
F_180 ( V_16 , V_228 , V_319 ) ;
F_142 ( V_235 , & V_66 -> V_195 ) ;
F_142 ( V_237 , & V_66 -> V_195 ) ;
F_142 ( V_239 , & V_66 -> V_195 ) ;
F_142 ( V_247 , & V_66 -> V_195 ) ;
}
return V_275 ;
}
static int F_183 ( struct V_192 * V_193 , struct V_65 * V_66 )
{
int V_275 ;
F_177 ( V_66 ) ;
V_275 = F_182 ( V_66 ) ;
if ( V_275 != V_332 )
V_275 = F_176 ( V_193 , V_66 ) ;
return V_275 ;
}
static inline void F_184 ( struct V_180 * V_255 , struct V_5 * V_6 )
{
if ( ( V_255 -> V_181 . V_333 [ 1 ] & V_334 ) &&
! ( V_6 -> V_224 & V_335 ) )
V_6 -> V_224 |= V_336 ;
if ( ( V_255 -> V_181 . V_333 [ 1 ] & V_337 ) &&
! ( V_6 -> V_224 & V_338 ) )
V_6 -> V_224 |= V_339 ;
}
static int F_185 ( struct V_180 * V_255 ,
T_4 V_194 ,
int V_195 ,
struct V_270 * V_271 )
{
struct V_192 * V_193 = V_255 -> V_203 ;
struct V_15 * V_16 = V_193 -> V_291 ;
struct V_4 * V_4 ;
struct V_65 * V_66 ;
unsigned int V_340 ;
int V_67 ;
V_340 = F_186 ( & V_193 -> V_341 ) ;
V_67 = F_169 ( V_255 ) ;
if ( V_67 != 0 )
goto V_118;
V_66 = F_133 ( V_255 ) ;
V_67 = F_62 ( V_66 ) ;
if ( F_51 ( V_66 ) )
goto V_118;
if ( V_16 -> V_93 & V_331 )
F_108 ( V_342 , & V_66 -> V_195 ) ;
V_4 = V_255 -> V_4 ;
if ( V_4 -> V_48 == NULL ) {
F_174 ( V_4 ) ;
V_4 = F_187 ( V_4 , F_188 ( V_66 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_255 -> V_4 ;
} else if ( V_4 != V_271 -> V_4 ) {
F_89 ( V_271 -> V_4 ) ;
V_271 -> V_4 = F_82 ( V_4 ) ;
}
F_189 ( V_4 ,
F_190 ( V_255 -> V_3 -> V_48 ) ) ;
}
V_67 = F_166 ( V_193 -> V_258 , V_255 , V_66 , V_194 , V_195 ) ;
if ( V_67 != 0 )
goto V_118;
V_271 -> V_66 = V_66 ;
if ( V_4 -> V_48 == V_66 -> V_2 ) {
F_191 ( V_271 ) ;
if ( F_192 ( & V_193 -> V_341 , V_340 ) )
F_23 ( V_16 , V_66 ) ;
}
V_118:
return V_67 ;
}
static int F_193 ( struct V_2 * V_3 ,
struct V_270 * V_271 ,
int V_195 ,
struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_192 * V_193 ;
struct V_65 * V_66 = NULL ;
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_180 * V_255 ;
struct V_4 * V_4 = V_271 -> V_4 ;
struct V_285 * V_319 = V_271 -> V_319 ;
struct V_343 * * V_344 = & V_271 -> V_345 ;
T_4 V_194 = V_271 -> V_232 & ( V_70 | V_206 | V_346 ) ;
enum V_172 V_173 = V_175 ;
struct V_1 * V_347 = NULL ;
int V_275 ;
V_275 = - V_138 ;
V_193 = F_194 ( V_16 , V_319 , V_348 ) ;
if ( V_193 == NULL ) {
F_9 ( L_24 ) ;
goto V_349;
}
V_275 = F_171 ( V_16 ) ;
if ( V_275 != 0 )
goto V_350;
if ( V_4 -> V_48 != NULL )
F_118 ( V_4 -> V_48 , V_194 ) ;
V_275 = - V_138 ;
if ( V_4 -> V_48 )
V_173 = V_174 ;
V_255 = F_76 ( V_4 , V_193 , V_194 , V_195 , V_6 ,
V_7 , V_173 , V_348 ) ;
if ( V_255 == NULL )
goto V_350;
if ( V_7 ) {
V_347 = F_79 ( V_16 , V_348 ) ;
if ( F_51 ( V_347 ) ) {
V_275 = F_62 ( V_347 ) ;
goto V_351;
}
}
if ( V_344 && V_16 -> V_17 [ 2 ] & V_352 ) {
V_255 -> V_182 . V_345 = F_195 () ;
if ( ! V_255 -> V_182 . V_345 )
goto V_201;
V_255 -> V_185 . V_220 = & V_353 [ 0 ] ;
}
if ( V_4 -> V_48 != NULL )
V_255 -> V_66 = F_127 ( V_4 -> V_48 , V_193 ) ;
V_275 = F_185 ( V_255 , V_194 , V_195 , V_271 ) ;
if ( V_275 != 0 )
goto V_201;
V_66 = V_271 -> V_66 ;
if ( ( V_255 -> V_185 . V_205 & V_207 ) &&
( V_255 -> V_185 . V_298 != V_301 ) ) {
F_184 ( V_255 , V_6 ) ;
F_74 ( V_255 -> V_181 . V_182 ) ;
V_275 = F_196 ( V_66 -> V_2 , V_319 ,
V_255 -> V_181 . V_182 , V_6 ,
V_66 , V_7 , V_347 ) ;
if ( V_275 == 0 ) {
F_197 ( V_66 -> V_2 , V_6 ) ;
F_198 ( V_66 -> V_2 , V_255 -> V_181 . V_182 ) ;
F_129 ( V_66 -> V_2 , V_255 -> V_181 . V_182 , V_347 ) ;
}
}
if ( F_199 ( V_344 , V_255 -> V_182 . V_345 , V_16 ) )
* V_344 = V_255 -> V_182 . V_345 ;
else
F_88 ( V_255 -> V_182 . V_345 ) ;
V_255 -> V_182 . V_345 = NULL ;
F_87 ( V_347 ) ;
F_97 ( V_255 ) ;
F_94 ( V_193 ) ;
return 0 ;
V_201:
F_87 ( V_347 ) ;
V_351:
F_88 ( V_255 -> V_182 . V_345 ) ;
F_97 ( V_255 ) ;
V_350:
F_94 ( V_193 ) ;
V_349:
return V_275 ;
}
static struct V_65 * F_200 ( struct V_2 * V_3 ,
struct V_270 * V_271 ,
int V_195 ,
struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_62 V_63 = { } ;
struct V_65 * V_56 ;
int V_275 ;
do {
V_275 = F_193 ( V_3 , V_271 , V_195 , V_6 , V_7 ) ;
V_56 = V_271 -> V_66 ;
if ( V_275 == 0 )
break;
if ( V_275 == - V_354 ) {
F_201 ( L_5
L_25 ,
F_3 ( V_3 ) -> V_10 -> V_96 ) ;
V_63 . V_68 = 1 ;
continue;
}
if ( V_275 == - V_74 ) {
V_63 . V_68 = 1 ;
continue;
}
if ( V_275 == - V_142 ) {
V_63 . V_68 = 1 ;
continue;
}
if ( F_71 ( V_16 , V_275 , & V_63 ) )
continue;
V_56 = F_52 ( F_20 ( V_16 ,
V_275 , & V_63 ) ) ;
} while ( V_63 . V_68 );
return V_56 ;
}
static int F_202 ( struct V_2 * V_2 , struct V_285 * V_319 ,
struct V_355 * V_356 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_357 ,
struct V_1 * V_347 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_358 V_359 = {
. V_222 = F_85 ( V_2 ) ,
. V_360 = V_6 ,
. V_16 = V_16 ,
. V_219 = V_16 -> V_17 ,
. V_7 = V_357 ,
} ;
struct V_361 V_56 = {
. V_356 = V_356 ,
. V_7 = V_347 ,
. V_16 = V_16 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_362 ] ,
. V_283 = & V_359 ,
. V_284 = & V_56 ,
. V_285 = V_319 ,
} ;
unsigned long V_97 = V_139 ;
T_4 V_194 ;
bool V_363 ;
int V_275 ;
V_359 . V_219 = F_7 ( V_16 , V_357 ) ;
if ( V_357 )
V_359 . V_219 = F_7 ( V_16 , V_347 ) ;
F_74 ( V_356 ) ;
V_363 = ( V_6 -> V_224 & V_364 ) ? true : false ;
V_194 = V_363 ? V_206 : V_70 ;
if ( F_203 ( & V_359 . V_228 , V_2 , V_194 ) ) {
} else if ( V_363 && V_66 != NULL && F_204 ( V_66 ) ) {
struct V_365 V_366 = {
. V_367 = V_59 -> V_368 ,
. V_369 = V_59 -> V_370 ,
} ;
F_205 ( & V_359 . V_228 , V_66 , V_206 ,
& V_366 ) ;
} else
F_107 ( & V_359 . V_228 , & V_371 ) ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & V_359 . V_147 , & V_56 . V_148 , 1 ) ;
if ( V_275 == 0 && V_66 != NULL )
F_34 ( V_16 , V_97 ) ;
return V_275 ;
}
static int F_196 ( struct V_2 * V_2 , struct V_285 * V_319 ,
struct V_355 * V_356 , struct V_5 * V_6 ,
struct V_65 * V_66 , struct V_1 * V_357 ,
struct V_1 * V_347 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_62 V_63 = {
. V_66 = V_66 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_202 ( V_2 , V_319 , V_356 , V_6 , V_66 , V_357 , V_347 ) ;
switch ( V_8 ) {
case - V_69 :
if ( ! ( V_6 -> V_224 & V_364 ) ) {
F_206 ( L_26
L_27
L_28
L_29 ,
V_16 -> V_10 -> V_96 ) ;
}
if ( V_66 && ! ( V_66 -> V_66 & V_206 ) ) {
V_8 = - V_372 ;
if ( V_6 -> V_224 & V_373 )
V_8 = - V_30 ;
goto V_118;
}
}
V_8 = F_20 ( V_16 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
V_118:
return V_8 ;
}
static void F_207 ( void * V_145 )
{
struct V_374 * V_143 = V_145 ;
struct V_192 * V_193 = V_143 -> V_66 -> V_203 ;
struct V_230 * V_231 = V_143 -> V_66 -> V_2 -> V_375 ;
if ( V_143 -> V_376 )
F_208 ( V_143 -> V_66 -> V_2 ) ;
F_93 ( V_143 -> V_66 ) ;
F_92 ( V_143 -> V_359 . V_184 ) ;
F_94 ( V_193 ) ;
F_95 ( V_231 ) ;
F_88 ( V_143 ) ;
}
static void F_209 ( struct V_65 * V_66 ,
T_4 V_194 )
{
F_31 ( & V_66 -> V_203 -> V_250 ) ;
F_142 ( V_239 , & V_66 -> V_195 ) ;
switch ( V_194 & ( V_70 | V_206 ) ) {
case V_206 :
F_142 ( V_235 , & V_66 -> V_195 ) ;
break;
case V_70 :
F_142 ( V_237 , & V_66 -> V_195 ) ;
break;
case 0 :
F_142 ( V_235 , & V_66 -> V_195 ) ;
F_142 ( V_237 , & V_66 -> V_195 ) ;
F_142 ( V_247 , & V_66 -> V_195 ) ;
}
F_33 ( & V_66 -> V_203 -> V_250 ) ;
}
static void F_210 ( struct V_113 * V_114 , void * V_145 )
{
struct V_374 * V_143 = V_145 ;
struct V_65 * V_66 = V_143 -> V_66 ;
struct V_15 * V_16 = F_3 ( V_143 -> V_2 ) ;
F_9 ( L_30 , V_36 ) ;
if ( ! F_45 ( V_114 , & V_143 -> V_56 . V_148 ) )
return;
switch ( V_114 -> V_126 ) {
case 0 :
if ( V_143 -> V_376 )
F_211 ( V_66 -> V_2 ,
V_143 -> V_377 ) ;
F_109 ( V_66 , & V_143 -> V_56 . V_228 , 0 ) ;
F_34 ( V_16 , V_143 -> V_97 ) ;
F_209 ( V_66 ,
V_143 -> V_359 . V_194 ) ;
break;
case - V_76 :
case - V_92 :
case - V_74 :
case - V_75 :
if ( V_143 -> V_359 . V_194 == 0 )
break;
default:
if ( F_212 ( V_114 , V_16 , V_66 ) == - V_142 )
F_42 ( V_114 ) ;
}
F_120 ( V_143 -> V_359 . V_184 ) ;
F_128 ( V_143 -> V_2 , V_143 -> V_56 . V_356 ) ;
F_9 ( L_31 , V_36 , V_114 -> V_126 ) ;
}
static void F_213 ( struct V_113 * V_114 , void * V_145 )
{
struct V_374 * V_143 = V_145 ;
struct V_65 * V_66 = V_143 -> V_66 ;
struct V_2 * V_2 = V_143 -> V_2 ;
int V_378 = 0 ;
F_9 ( L_30 , V_36 ) ;
if ( F_159 ( V_143 -> V_359 . V_184 , V_114 ) != 0 )
goto V_292;
V_114 -> V_296 . V_280 = & V_281 [ V_379 ] ;
V_143 -> V_359 . V_194 = V_70 | V_206 ;
F_31 ( & V_66 -> V_203 -> V_250 ) ;
if ( V_66 -> V_240 == 0 ) {
if ( V_66 -> V_236 == 0 ) {
V_378 |= F_49 ( V_235 , & V_66 -> V_195 ) ;
V_378 |= F_49 ( V_239 , & V_66 -> V_195 ) ;
V_143 -> V_359 . V_194 &= ~ V_70 ;
}
if ( V_66 -> V_238 == 0 ) {
V_378 |= F_49 ( V_237 , & V_66 -> V_195 ) ;
V_378 |= F_49 ( V_239 , & V_66 -> V_195 ) ;
V_143 -> V_359 . V_194 &= ~ V_206 ;
}
}
if ( ! F_204 ( V_66 ) )
V_378 = 0 ;
F_33 ( & V_66 -> V_203 -> V_250 ) ;
if ( ! V_378 ) {
goto V_293;
}
if ( V_143 -> V_359 . V_194 == 0 ) {
V_114 -> V_296 . V_280 = & V_281 [ V_380 ] ;
if ( V_143 -> V_376 &&
F_214 ( V_2 , & V_143 -> V_377 , V_114 ) ) {
F_120 ( V_143 -> V_359 . V_184 ) ;
goto V_292;
}
}
F_74 ( V_143 -> V_56 . V_356 ) ;
V_143 -> V_97 = V_139 ;
if ( F_56 ( F_3 ( V_2 ) ,
& V_143 -> V_359 . V_147 ,
& V_143 -> V_56 . V_148 ,
V_114 ) != 0 )
F_120 ( V_143 -> V_359 . V_184 ) ;
F_9 ( L_32 , V_36 ) ;
return;
V_293:
V_114 -> V_304 = NULL ;
V_292:
F_45 ( V_114 , & V_143 -> V_56 . V_148 ) ;
}
int F_215 ( struct V_65 * V_66 , T_5 V_197 , int V_381 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
struct V_374 * V_143 ;
struct V_192 * V_193 = V_66 -> V_203 ;
struct V_113 * V_114 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_380 ] ,
. V_285 = V_66 -> V_203 -> V_258 ,
} ;
struct V_151 V_286 = {
. V_153 = V_16 -> V_90 ,
. V_149 = & V_150 ,
. V_154 = & V_382 ,
. V_288 = V_289 ,
. V_195 = V_290 ,
} ;
int V_275 = - V_138 ;
V_143 = F_78 ( sizeof( * V_143 ) , V_197 ) ;
if ( V_143 == NULL )
goto V_118;
F_46 ( & V_143 -> V_359 . V_147 , & V_143 -> V_56 . V_148 , 1 ) ;
V_143 -> V_2 = V_66 -> V_2 ;
V_143 -> V_66 = V_66 ;
V_143 -> V_359 . V_222 = F_85 ( V_66 -> V_2 ) ;
V_143 -> V_359 . V_228 = & V_66 -> V_246 ;
V_143 -> V_359 . V_184 = F_80 ( & V_66 -> V_203 -> V_200 , V_197 ) ;
if ( V_143 -> V_359 . V_184 == NULL )
goto V_383;
V_143 -> V_359 . V_194 = 0 ;
V_143 -> V_359 . V_219 = V_16 -> V_384 ;
V_143 -> V_56 . V_356 = & V_143 -> V_356 ;
V_143 -> V_56 . V_184 = V_143 -> V_359 . V_184 ;
V_143 -> V_56 . V_16 = V_16 ;
V_143 -> V_376 = F_216 ( V_66 -> V_2 ) ;
F_81 ( V_143 -> V_2 -> V_375 ) ;
V_150 . V_283 = & V_143 -> V_359 ;
V_150 . V_284 = & V_143 -> V_56 ;
V_286 . V_156 = V_143 ;
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
V_275 = 0 ;
if ( V_381 )
V_275 = F_100 ( V_114 ) ;
F_63 ( V_114 ) ;
return V_275 ;
V_383:
F_88 ( V_143 ) ;
V_118:
F_93 ( V_66 ) ;
F_94 ( V_193 ) ;
return V_275 ;
}
static struct V_2 *
F_217 ( struct V_2 * V_3 , struct V_270 * V_271 , int V_205 , struct V_5 * V_385 )
{
struct V_65 * V_66 ;
struct V_1 V_19 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_271 -> V_4 , V_385 , & V_19 ) ;
V_66 = F_200 ( V_3 , V_271 , V_205 , V_385 , V_7 ) ;
F_5 ( V_7 ) ;
if ( F_51 ( V_66 ) )
return F_218 ( V_66 ) ;
return V_66 -> V_2 ;
}
static void F_219 ( struct V_270 * V_271 , int V_386 )
{
if ( V_271 -> V_66 == NULL )
return;
if ( V_386 )
F_220 ( V_271 -> V_66 , V_271 -> V_232 ) ;
else
F_140 ( V_271 -> V_66 , V_271 -> V_232 ) ;
}
static int F_221 ( struct V_15 * V_16 , struct V_387 * V_388 )
{
struct V_389 args = {
. V_388 = V_388 ,
} ;
struct V_390 V_56 = {} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_391 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
int V_275 ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
if ( V_275 == 0 ) {
memcpy ( V_16 -> V_17 , V_56 . V_17 , sizeof( V_16 -> V_17 ) ) ;
V_16 -> V_93 &= ~ ( V_392 | V_393 |
V_394 | V_395 |
V_396 | V_397 | V_398 |
V_399 | V_400 |
V_401 | V_402 ) ;
if ( V_56 . V_17 [ 0 ] & V_403 )
V_16 -> V_93 |= V_392 ;
if ( V_56 . V_404 != 0 )
V_16 -> V_93 |= V_393 ;
if ( V_56 . V_405 != 0 )
V_16 -> V_93 |= V_394 ;
if ( V_56 . V_17 [ 0 ] & V_47 )
V_16 -> V_93 |= V_395 ;
if ( V_56 . V_17 [ 1 ] & V_406 )
V_16 -> V_93 |= V_396 ;
if ( V_56 . V_17 [ 1 ] & V_407 )
V_16 -> V_93 |= V_397 ;
if ( V_56 . V_17 [ 1 ] & V_408 )
V_16 -> V_93 |= V_398 ;
if ( V_56 . V_17 [ 1 ] & V_409 )
V_16 -> V_93 |= V_399 ;
if ( V_56 . V_17 [ 1 ] & V_334 )
V_16 -> V_93 |= V_400 ;
if ( V_56 . V_17 [ 1 ] & V_410 )
V_16 -> V_93 |= V_401 ;
if ( V_56 . V_17 [ 1 ] & V_337 )
V_16 -> V_93 |= V_402 ;
#ifdef F_222
if ( V_56 . V_17 [ 2 ] & V_411 )
V_16 -> V_93 |= V_9 ;
#endif
memcpy ( V_16 -> V_18 , V_56 . V_17 ,
sizeof( V_16 -> V_17 ) ) ;
if ( V_16 -> V_93 & V_9 ) {
V_16 -> V_18 [ 2 ] &= ~ V_411 ;
V_56 . V_17 [ 2 ] &= ~ V_411 ;
}
memcpy ( V_16 -> V_384 , V_56 . V_17 , sizeof( V_16 -> V_384 ) ) ;
V_16 -> V_384 [ 0 ] &= V_412 | V_413 ;
V_16 -> V_384 [ 1 ] &= V_410 | V_337 ;
V_16 -> V_414 = V_56 . V_414 ;
V_16 -> V_415 = V_56 . V_415 ;
}
return V_275 ;
}
int F_223 ( struct V_15 * V_16 , struct V_387 * V_388 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_221 ( V_16 , V_388 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_224 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_417 )
{
T_1 V_219 [ 3 ] ;
struct V_418 args = {
. V_219 = V_219 ,
} ;
struct V_419 V_56 = {
. V_16 = V_16 ,
. V_356 = V_417 -> V_356 ,
. V_222 = V_388 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_420 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
V_219 [ 0 ] = V_221 [ 0 ] ;
V_219 [ 1 ] = V_221 [ 1 ] ;
V_219 [ 2 ] = V_221 [ 2 ] & ~ V_411 ;
F_74 ( V_417 -> V_356 ) ;
return F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
}
static int F_225 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_417 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_224 ( V_16 , V_388 , V_417 ) ;
switch ( V_8 ) {
case 0 :
case - V_24 :
goto V_118;
default:
V_8 = F_20 ( V_16 , V_8 , & V_63 ) ;
}
} while ( V_63 . V_68 );
V_118:
return V_8 ;
}
static int F_226 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_417 , T_7 V_421 )
{
struct V_422 * V_423 ;
int V_67 ;
V_423 = F_227 ( V_421 , V_16 -> V_90 ) ;
if ( F_51 ( V_423 ) ) {
V_67 = - V_30 ;
goto V_118;
}
V_67 = F_225 ( V_16 , V_388 , V_417 ) ;
V_118:
return V_67 ;
}
static int F_228 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_417 )
{
static const T_7 V_424 [] = {
V_425 ,
V_426 ,
V_427 ,
V_428 ,
V_429 ,
} ;
int V_275 = - V_25 ;
T_8 V_430 ;
for ( V_430 = 0 ; V_430 < F_229 ( V_424 ) ; V_430 ++ ) {
V_275 = F_226 ( V_16 , V_388 , V_417 , V_424 [ V_430 ] ) ;
if ( V_275 == - V_24 || V_275 == - V_30 )
continue;
break;
}
if ( V_275 == - V_30 )
V_275 = - V_25 ;
return V_275 ;
}
static int F_230 ( struct V_15 * V_16 ,
struct V_387 * V_388 , struct V_416 * V_417 )
{
int V_431 = V_16 -> V_10 -> V_11 ;
return V_432 [ V_431 ] -> F_231 ( V_16 , V_388 , V_417 ) ;
}
int F_232 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_417 )
{
int V_275 ;
V_275 = F_225 ( V_16 , V_388 , V_417 ) ;
if ( ( V_275 == - V_24 ) &&
! ( V_16 -> V_195 & V_433 ) )
V_275 = F_230 ( V_16 , V_388 , V_417 ) ;
if ( V_275 == 0 )
V_275 = F_223 ( V_16 , V_388 ) ;
if ( V_275 == 0 )
V_275 = F_233 ( V_16 , V_388 , V_417 ) ;
return F_8 ( V_275 ) ;
}
static int F_234 ( struct V_15 * V_16 , struct V_387 * V_434 ,
struct V_416 * V_417 )
{
int error ;
struct V_355 * V_356 = V_417 -> V_356 ;
struct V_1 * V_7 = NULL ;
error = F_223 ( V_16 , V_434 ) ;
if ( error < 0 ) {
F_9 ( L_33 , - error ) ;
return error ;
}
V_7 = F_79 ( V_16 , V_348 ) ;
if ( F_51 ( V_7 ) )
return F_62 ( V_7 ) ;
error = F_235 ( V_16 , V_434 , V_356 , V_7 ) ;
if ( error < 0 ) {
F_9 ( L_34 , - error ) ;
goto V_201;
}
if ( V_356 -> V_263 & V_435 &&
! F_236 ( & V_16 -> V_436 , & V_356 -> V_436 ) )
memcpy ( & V_16 -> V_436 , & V_356 -> V_436 , sizeof( V_16 -> V_436 ) ) ;
V_201:
F_87 ( V_7 ) ;
return error ;
}
static int F_237 ( struct V_53 * V_90 , struct V_2 * V_3 ,
const struct V_437 * V_218 , struct V_355 * V_356 ,
struct V_387 * V_388 )
{
int V_275 = - V_138 ;
struct V_438 * V_438 = NULL ;
struct V_439 * V_440 = NULL ;
V_438 = F_238 ( V_348 ) ;
if ( V_438 == NULL )
goto V_118;
V_440 = F_239 ( sizeof( struct V_439 ) , V_348 ) ;
if ( V_440 == NULL )
goto V_118;
V_275 = F_240 ( V_90 , V_3 , V_218 , V_440 , V_438 ) ;
if ( V_275 != 0 )
goto V_118;
if ( F_236 ( & F_3 ( V_3 ) -> V_436 , & V_440 -> V_356 . V_436 ) ) {
F_9 ( L_35
L_36 , V_36 , V_218 -> V_218 ) ;
V_275 = - V_37 ;
goto V_118;
}
F_241 ( & V_440 -> V_356 ) ;
memcpy ( V_356 , & V_440 -> V_356 , sizeof( struct V_355 ) ) ;
memset ( V_388 , 0 , sizeof( struct V_387 ) ) ;
V_118:
if ( V_438 )
F_242 ( V_438 ) ;
F_88 ( V_440 ) ;
return V_275 ;
}
static int F_170 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_355 * V_356 , struct V_1 * V_7 )
{
struct V_441 args = {
. V_222 = V_388 ,
. V_219 = V_16 -> V_17 ,
} ;
struct V_442 V_56 = {
. V_356 = V_356 ,
. V_7 = V_7 ,
. V_16 = V_16 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_443 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
args . V_219 = F_7 ( V_16 , V_7 ) ;
F_74 ( V_356 ) ;
return F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
}
static int F_235 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_355 * V_356 , struct V_1 * V_7 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_170 ( V_16 , V_388 , V_356 , V_7 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int
F_243 ( struct V_4 * V_4 , struct V_355 * V_356 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = V_4 -> V_48 ;
struct V_285 * V_319 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_1 * V_7 = NULL ;
int V_275 ;
if ( F_244 ( V_2 ) )
F_245 ( V_2 ) ;
F_74 ( V_356 ) ;
if ( V_6 -> V_224 & V_373 )
V_6 -> V_224 &= ~ ( V_339 | V_444 | V_373 ) ;
if ( ( V_6 -> V_224 & ~ ( V_445 ) ) == 0 )
return 0 ;
if ( V_6 -> V_224 & V_445 ) {
struct V_270 * V_271 ;
V_271 = F_246 ( V_6 -> V_446 ) ;
if ( V_271 ) {
V_319 = V_271 -> V_319 ;
V_66 = V_271 -> V_66 ;
}
}
V_7 = F_79 ( F_3 ( V_2 ) , V_348 ) ;
if ( F_51 ( V_7 ) )
return F_62 ( V_7 ) ;
V_275 = F_196 ( V_2 , V_319 , V_356 , V_6 , V_66 , NULL , V_7 ) ;
if ( V_275 == 0 ) {
F_197 ( V_2 , V_6 ) ;
F_129 ( V_2 , V_356 , V_7 ) ;
}
F_87 ( V_7 ) ;
return V_275 ;
}
static int F_247 ( struct V_53 * V_54 , struct V_2 * V_3 ,
const struct V_437 * V_218 , struct V_387 * V_388 ,
struct V_355 * V_356 , struct V_1 * V_7 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
int V_275 ;
struct V_447 args = {
. V_219 = V_16 -> V_17 ,
. V_448 = F_85 ( V_3 ) ,
. V_218 = V_218 ,
} ;
struct V_419 V_56 = {
. V_16 = V_16 ,
. V_356 = V_356 ,
. V_7 = V_7 ,
. V_222 = V_388 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_449 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
args . V_219 = F_7 ( V_16 , V_7 ) ;
F_74 ( V_356 ) ;
F_9 ( L_37 , V_218 -> V_218 ) ;
V_275 = F_66 ( V_54 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
F_9 ( L_38 , V_275 ) ;
return V_275 ;
}
static void F_248 ( struct V_355 * V_356 )
{
V_356 -> V_263 |= V_264 | V_450 |
V_451 | V_452 ;
V_356 -> V_232 = V_309 | V_453 | V_454 ;
V_356 -> V_455 = 2 ;
}
static int F_249 ( struct V_53 * * V_54 , struct V_2 * V_3 ,
struct V_437 * V_218 , struct V_387 * V_388 ,
struct V_355 * V_356 , struct V_1 * V_7 )
{
struct V_62 V_63 = { } ;
struct V_53 * V_90 = * V_54 ;
int V_8 ;
do {
V_8 = F_247 ( V_90 , V_3 , V_218 , V_388 , V_356 , V_7 ) ;
switch ( V_8 ) {
case - V_27 :
V_8 = - V_272 ;
goto V_118;
case - V_456 :
V_8 = F_237 ( V_90 , V_3 , V_218 , V_356 , V_388 ) ;
goto V_118;
case - V_24 :
V_8 = - V_25 ;
if ( V_90 != * V_54 )
goto V_118;
V_90 = F_250 ( V_90 , V_3 , V_218 ) ;
if ( F_51 ( V_90 ) )
return F_62 ( V_90 ) ;
V_63 . V_68 = 1 ;
break;
default:
V_8 = F_20 ( F_3 ( V_3 ) , V_8 , & V_63 ) ;
}
} while ( V_63 . V_68 );
V_118:
if ( V_8 == 0 )
* V_54 = V_90 ;
else if ( V_90 != * V_54 )
F_251 ( V_90 ) ;
return V_8 ;
}
static int F_252 ( struct V_2 * V_3 , struct V_437 * V_218 ,
struct V_387 * V_388 , struct V_355 * V_356 ,
struct V_1 * V_7 )
{
int V_275 ;
struct V_53 * V_90 = F_253 ( V_3 ) ;
V_275 = F_249 ( & V_90 , V_3 , V_218 , V_388 , V_356 , V_7 ) ;
if ( V_90 != F_253 ( V_3 ) ) {
F_251 ( V_90 ) ;
F_248 ( V_356 ) ;
}
return V_275 ;
}
struct V_53 *
F_254 ( struct V_2 * V_3 , struct V_437 * V_218 ,
struct V_387 * V_388 , struct V_355 * V_356 )
{
struct V_53 * V_90 = F_253 ( V_3 ) ;
int V_275 ;
V_275 = F_249 ( & V_90 , V_3 , V_218 , V_388 , V_356 , NULL ) ;
if ( V_275 < 0 )
return F_52 ( V_275 ) ;
return ( V_90 == F_253 ( V_3 ) ) ? F_255 ( V_90 ) : V_90 ;
}
static int F_256 ( struct V_2 * V_2 , struct V_321 * V_457 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_458 args = {
. V_222 = F_85 ( V_2 ) ,
. V_219 = V_16 -> V_384 ,
} ;
struct V_459 V_56 = {
. V_16 = V_16 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_460 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
. V_285 = V_457 -> V_319 ,
} ;
int V_232 = V_457 -> V_323 ;
int V_275 = 0 ;
if ( V_232 & V_327 )
args . V_189 |= V_208 ;
if ( F_257 ( V_2 -> V_461 ) ) {
if ( V_232 & V_462 )
args . V_189 |= V_209 | V_210 | V_463 ;
if ( V_232 & V_326 )
args . V_189 |= V_464 ;
} else {
if ( V_232 & V_462 )
args . V_189 |= V_209 | V_210 ;
if ( V_232 & V_326 )
args . V_189 |= V_211 ;
}
V_56 . V_356 = F_258 () ;
if ( V_56 . V_356 == NULL )
return - V_138 ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
if ( ! V_275 ) {
F_167 ( V_457 , V_56 . V_189 ) ;
F_128 ( V_2 , V_56 . V_356 ) ;
}
F_259 ( V_56 . V_356 ) ;
return V_275 ;
}
static int F_260 ( struct V_2 * V_2 , struct V_321 * V_457 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_2 ) ,
F_256 ( V_2 , V_457 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_261 ( struct V_2 * V_2 , struct V_438 * V_438 ,
unsigned int V_51 , unsigned int V_465 )
{
struct V_466 args = {
. V_222 = F_85 ( V_2 ) ,
. V_51 = V_51 ,
. V_465 = V_465 ,
. V_44 = & V_438 ,
} ;
struct V_467 V_56 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_468 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
return F_66 ( F_3 ( V_2 ) -> V_90 , F_3 ( V_2 ) , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
}
static int F_262 ( struct V_2 * V_2 , struct V_438 * V_438 ,
unsigned int V_51 , unsigned int V_465 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_2 ) ,
F_261 ( V_2 , V_438 , V_51 , V_465 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int
F_263 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_195 )
{
struct V_1 V_19 , * V_357 = NULL ;
struct V_270 * V_271 ;
struct V_65 * V_66 ;
int V_275 = 0 ;
V_271 = F_264 ( V_4 , V_70 ) ;
if ( F_51 ( V_271 ) )
return F_62 ( V_271 ) ;
V_357 = F_1 ( V_3 , V_4 , V_6 , & V_19 ) ;
V_6 -> V_12 &= ~ F_265 () ;
V_66 = F_200 ( V_3 , V_271 , V_195 , V_6 , V_357 ) ;
if ( F_51 ( V_66 ) ) {
V_275 = F_62 ( V_66 ) ;
goto V_118;
}
V_118:
F_5 ( V_357 ) ;
F_147 ( V_271 ) ;
return V_275 ;
}
static int F_266 ( struct V_2 * V_3 , struct V_437 * V_218 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_469 args = {
. V_222 = F_85 ( V_3 ) ,
. V_218 = * V_218 ,
} ;
struct V_470 V_56 = {
. V_16 = V_16 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_471 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
int V_275 ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 1 ) ;
if ( V_275 == 0 )
F_67 ( V_3 , & V_56 . V_160 ) ;
return V_275 ;
}
static int F_267 ( struct V_2 * V_3 , struct V_437 * V_218 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_3 ) ,
F_266 ( V_3 , V_218 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static void F_268 ( struct V_149 * V_150 , struct V_2 * V_3 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_469 * args = V_150 -> V_283 ;
struct V_470 * V_56 = V_150 -> V_284 ;
V_56 -> V_16 = V_16 ;
V_150 -> V_280 = & V_281 [ V_471 ] ;
F_46 ( & args -> V_147 , & V_56 -> V_148 , 1 ) ;
F_74 ( V_56 -> V_472 ) ;
}
static void F_269 ( struct V_113 * V_114 , struct V_473 * V_145 )
{
F_56 ( F_3 ( V_145 -> V_3 ) ,
& V_145 -> args . V_147 ,
& V_145 -> V_56 . V_148 ,
V_114 ) ;
}
static int F_270 ( struct V_113 * V_114 , struct V_2 * V_3 )
{
struct V_470 * V_56 = V_114 -> V_296 . V_284 ;
if ( ! F_45 ( V_114 , & V_56 -> V_148 ) )
return 0 ;
if ( F_212 ( V_114 , V_56 -> V_16 , NULL ) == - V_142 )
return 0 ;
F_67 ( V_3 , & V_56 -> V_160 ) ;
return 1 ;
}
static void F_271 ( struct V_149 * V_150 , struct V_2 * V_3 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
struct V_474 * V_359 = V_150 -> V_283 ;
struct V_475 * V_56 = V_150 -> V_284 ;
V_150 -> V_280 = & V_281 [ V_476 ] ;
V_56 -> V_16 = V_16 ;
F_46 ( & V_359 -> V_147 , & V_56 -> V_148 , 1 ) ;
}
static void F_272 ( struct V_113 * V_114 , struct V_477 * V_145 )
{
F_56 ( F_3 ( V_145 -> V_478 ) ,
& V_145 -> args . V_147 ,
& V_145 -> V_56 . V_148 ,
V_114 ) ;
}
static int F_273 ( struct V_113 * V_114 , struct V_2 * V_478 ,
struct V_2 * V_479 )
{
struct V_475 * V_56 = V_114 -> V_296 . V_284 ;
if ( ! F_45 ( V_114 , & V_56 -> V_148 ) )
return 0 ;
if ( F_212 ( V_114 , V_56 -> V_16 , NULL ) == - V_142 )
return 0 ;
F_67 ( V_478 , & V_56 -> V_480 ) ;
F_67 ( V_479 , & V_56 -> V_481 ) ;
return 1 ;
}
static int F_274 ( struct V_2 * V_478 , struct V_437 * V_482 ,
struct V_2 * V_479 , struct V_437 * V_483 )
{
struct V_15 * V_16 = F_3 ( V_478 ) ;
struct V_474 V_359 = {
. V_478 = F_85 ( V_478 ) ,
. V_479 = F_85 ( V_479 ) ,
. V_482 = V_482 ,
. V_483 = V_483 ,
} ;
struct V_475 V_56 = {
. V_16 = V_16 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_476 ] ,
. V_283 = & V_359 ,
. V_284 = & V_56 ,
} ;
int V_275 = - V_138 ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & V_359 . V_147 , & V_56 . V_148 , 1 ) ;
if ( ! V_275 ) {
F_67 ( V_478 , & V_56 . V_480 ) ;
F_67 ( V_479 , & V_56 . V_481 ) ;
}
return V_275 ;
}
static int F_275 ( struct V_2 * V_478 , struct V_437 * V_482 ,
struct V_2 * V_479 , struct V_437 * V_483 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_478 ) ,
F_274 ( V_478 , V_482 ,
V_479 , V_483 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_276 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_437 * V_218 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_484 V_359 = {
. V_222 = F_85 ( V_2 ) ,
. V_448 = F_85 ( V_3 ) ,
. V_218 = V_218 ,
. V_219 = V_16 -> V_17 ,
} ;
struct V_485 V_56 = {
. V_16 = V_16 ,
. V_7 = NULL ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_486 ] ,
. V_283 = & V_359 ,
. V_284 = & V_56 ,
} ;
int V_275 = - V_138 ;
V_56 . V_356 = F_258 () ;
if ( V_56 . V_356 == NULL )
goto V_118;
V_56 . V_7 = F_79 ( V_16 , V_348 ) ;
if ( F_51 ( V_56 . V_7 ) ) {
V_275 = F_62 ( V_56 . V_7 ) ;
goto V_118;
}
V_359 . V_219 = F_7 ( V_16 , V_56 . V_7 ) ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & V_359 . V_147 , & V_56 . V_148 , 1 ) ;
if ( ! V_275 ) {
F_67 ( V_3 , & V_56 . V_160 ) ;
V_275 = F_198 ( V_2 , V_56 . V_356 ) ;
if ( ! V_275 )
F_129 ( V_2 , V_56 . V_356 , V_56 . V_7 ) ;
}
F_87 ( V_56 . V_7 ) ;
V_118:
F_259 ( V_56 . V_356 ) ;
return V_275 ;
}
static int F_277 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_437 * V_218 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_2 ) ,
F_276 ( V_2 , V_3 , V_218 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static struct V_487 * F_278 ( struct V_2 * V_3 ,
struct V_437 * V_218 , struct V_5 * V_6 , T_1 V_488 )
{
struct V_487 * V_145 ;
V_145 = F_78 ( sizeof( * V_145 ) , V_348 ) ;
if ( V_145 != NULL ) {
struct V_15 * V_16 = F_3 ( V_3 ) ;
V_145 -> V_7 = F_79 ( V_16 , V_348 ) ;
if ( F_51 ( V_145 -> V_7 ) )
goto V_279;
V_145 -> V_150 . V_280 = & V_281 [ V_489 ] ;
V_145 -> V_150 . V_283 = & V_145 -> V_359 ;
V_145 -> V_150 . V_284 = & V_145 -> V_56 ;
V_145 -> V_359 . V_448 = F_85 ( V_3 ) ;
V_145 -> V_359 . V_16 = V_16 ;
V_145 -> V_359 . V_218 = V_218 ;
V_145 -> V_359 . V_196 = V_6 ;
V_145 -> V_359 . V_488 = V_488 ;
V_145 -> V_359 . V_219 = F_7 ( V_16 , V_145 -> V_7 ) ;
V_145 -> V_56 . V_16 = V_16 ;
V_145 -> V_56 . V_222 = & V_145 -> V_222 ;
V_145 -> V_56 . V_356 = & V_145 -> V_356 ;
V_145 -> V_56 . V_7 = V_145 -> V_7 ;
F_74 ( V_145 -> V_56 . V_356 ) ;
}
return V_145 ;
V_279:
F_88 ( V_145 ) ;
return NULL ;
}
static int F_279 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_487 * V_145 )
{
int V_275 = F_66 ( F_3 ( V_3 ) -> V_90 , F_3 ( V_3 ) , & V_145 -> V_150 ,
& V_145 -> V_359 . V_147 , & V_145 -> V_56 . V_148 , 1 ) ;
if ( V_275 == 0 ) {
F_67 ( V_3 , & V_145 -> V_56 . V_490 ) ;
V_275 = F_280 ( V_4 , V_145 -> V_56 . V_222 , V_145 -> V_56 . V_356 , V_145 -> V_56 . V_7 ) ;
}
return V_275 ;
}
static void F_281 ( struct V_487 * V_145 )
{
F_87 ( V_145 -> V_7 ) ;
F_88 ( V_145 ) ;
}
static int F_282 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_438 * V_438 , unsigned int V_14 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_487 * V_145 ;
int V_275 = - V_491 ;
if ( V_14 > V_492 )
goto V_118;
V_275 = - V_138 ;
V_145 = F_278 ( V_3 , & V_4 -> V_13 , V_6 , V_493 ) ;
if ( V_145 == NULL )
goto V_118;
V_145 -> V_150 . V_280 = & V_281 [ V_494 ] ;
V_145 -> V_359 . V_226 . V_495 . V_44 = & V_438 ;
V_145 -> V_359 . V_226 . V_495 . V_14 = V_14 ;
V_145 -> V_359 . V_7 = V_7 ;
V_275 = F_279 ( V_3 , V_4 , V_145 ) ;
F_281 ( V_145 ) ;
V_118:
return V_275 ;
}
static int F_283 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_438 * V_438 , unsigned int V_14 , struct V_5 * V_6 )
{
struct V_62 V_63 = { } ;
struct V_1 V_19 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_19 ) ;
do {
V_8 = F_20 ( F_3 ( V_3 ) ,
F_282 ( V_3 , V_4 , V_438 ,
V_14 , V_6 , V_7 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
F_5 ( V_7 ) ;
return V_8 ;
}
static int F_284 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_487 * V_145 ;
int V_275 = - V_138 ;
V_145 = F_278 ( V_3 , & V_4 -> V_13 , V_6 , V_496 ) ;
if ( V_145 == NULL )
goto V_118;
V_145 -> V_359 . V_7 = V_7 ;
V_275 = F_279 ( V_3 , V_4 , V_145 ) ;
F_281 ( V_145 ) ;
V_118:
return V_275 ;
}
static int F_285 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_62 V_63 = { } ;
struct V_1 V_19 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_19 ) ;
V_6 -> V_12 &= ~ F_265 () ;
do {
V_8 = F_20 ( F_3 ( V_3 ) ,
F_284 ( V_3 , V_4 , V_6 , V_7 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
F_5 ( V_7 ) ;
return V_8 ;
}
static int F_286 ( struct V_4 * V_4 , struct V_285 * V_319 ,
T_2 V_38 , struct V_438 * * V_44 , unsigned int V_52 , int V_497 )
{
struct V_2 * V_3 = V_4 -> V_48 ;
struct V_40 args = {
. V_222 = F_85 ( V_3 ) ,
. V_44 = V_44 ,
. V_51 = 0 ,
. V_52 = V_52 ,
. V_219 = F_3 ( V_4 -> V_48 ) -> V_17 ,
. V_497 = V_497 ,
} ;
struct V_498 V_56 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_499 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
. V_285 = V_319 ,
} ;
int V_275 ;
F_9 ( L_39 , V_36 ,
V_4 -> V_50 -> V_13 . V_218 ,
V_4 -> V_13 . V_218 ,
( unsigned long long ) V_38 ) ;
F_10 ( V_38 , F_68 ( V_3 ) -> V_500 , V_4 , & args ) ;
V_56 . V_51 = args . V_51 ;
V_275 = F_66 ( F_3 ( V_3 ) -> V_90 , F_3 ( V_3 ) , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
if ( V_275 >= 0 ) {
memcpy ( F_68 ( V_3 ) -> V_500 , V_56 . V_39 . V_145 , V_501 ) ;
V_275 += args . V_51 ;
}
F_287 ( V_3 ) ;
F_9 ( L_40 , V_36 , V_275 ) ;
return V_275 ;
}
static int F_288 ( struct V_4 * V_4 , struct V_285 * V_319 ,
T_2 V_38 , struct V_438 * * V_44 , unsigned int V_52 , int V_497 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_4 -> V_48 ) ,
F_286 ( V_4 , V_319 , V_38 ,
V_44 , V_52 , V_497 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_289 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_9 V_502 )
{
struct V_487 * V_145 ;
int V_232 = V_6 -> V_12 ;
int V_275 = - V_138 ;
V_145 = F_278 ( V_3 , & V_4 -> V_13 , V_6 , V_503 ) ;
if ( V_145 == NULL )
goto V_118;
if ( F_290 ( V_232 ) )
V_145 -> V_359 . V_488 = V_504 ;
else if ( F_291 ( V_232 ) ) {
V_145 -> V_359 . V_488 = V_505 ;
V_145 -> V_359 . V_226 . V_506 . V_507 = F_292 ( V_502 ) ;
V_145 -> V_359 . V_226 . V_506 . V_508 = F_293 ( V_502 ) ;
}
else if ( F_294 ( V_232 ) ) {
V_145 -> V_359 . V_488 = V_509 ;
V_145 -> V_359 . V_226 . V_506 . V_507 = F_292 ( V_502 ) ;
V_145 -> V_359 . V_226 . V_506 . V_508 = F_293 ( V_502 ) ;
} else if ( ! F_295 ( V_232 ) ) {
V_275 = - V_28 ;
goto V_279;
}
V_145 -> V_359 . V_7 = V_7 ;
V_275 = F_279 ( V_3 , V_4 , V_145 ) ;
V_279:
F_281 ( V_145 ) ;
V_118:
return V_275 ;
}
static int F_296 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_9 V_502 )
{
struct V_62 V_63 = { } ;
struct V_1 V_19 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_19 ) ;
V_6 -> V_12 &= ~ F_265 () ;
do {
V_8 = F_20 ( F_3 ( V_3 ) ,
F_289 ( V_3 , V_4 , V_6 , V_7 , V_502 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
F_5 ( V_7 ) ;
return V_8 ;
}
static int F_297 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_510 * V_511 )
{
struct V_512 args = {
. V_222 = V_388 ,
. V_219 = V_16 -> V_17 ,
} ;
struct V_513 V_56 = {
. V_511 = V_511 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_514 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
F_74 ( V_511 -> V_356 ) ;
return F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
}
static int F_298 ( struct V_15 * V_16 , struct V_387 * V_388 , struct V_510 * V_511 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_297 ( V_16 , V_388 , V_511 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_299 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_515 )
{
struct V_516 args = {
. V_222 = V_388 ,
. V_219 = V_16 -> V_17 ,
} ;
struct V_517 V_56 = {
. V_515 = V_515 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_518 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
return F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
}
static int F_233 ( struct V_15 * V_16 , struct V_387 * V_388 , struct V_416 * V_515 )
{
struct V_62 V_63 = { } ;
unsigned long V_519 = V_139 ;
int V_8 ;
do {
V_8 = F_299 ( V_16 , V_388 , V_515 ) ;
if ( V_8 == 0 ) {
struct V_10 * V_64 = V_16 -> V_10 ;
F_31 ( & V_64 -> V_98 ) ;
V_64 -> V_520 = V_515 -> V_521 * V_87 ;
V_64 -> V_99 = V_519 ;
F_33 ( & V_64 -> V_98 ) ;
break;
}
V_8 = F_20 ( V_16 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_300 ( struct V_15 * V_16 , struct V_387 * V_388 , struct V_416 * V_515 )
{
int error ;
F_74 ( V_515 -> V_356 ) ;
error = F_233 ( V_16 , V_388 , V_515 ) ;
if ( error == 0 ) {
V_16 -> V_522 = V_515 -> V_523 ;
F_301 ( V_16 , V_388 , V_515 -> V_524 ) ;
}
return error ;
}
static int F_302 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_525 * V_526 )
{
struct V_527 args = {
. V_222 = V_388 ,
. V_219 = V_16 -> V_17 ,
} ;
struct V_528 V_56 = {
. V_526 = V_526 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_529 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
if ( ( args . V_219 [ 0 ] & V_530 [ 0 ] ) == 0 ) {
memset ( V_526 , 0 , sizeof( * V_526 ) ) ;
return 0 ;
}
F_74 ( V_526 -> V_356 ) ;
return F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
}
static int F_303 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_525 * V_526 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_302 ( V_16 , V_388 , V_526 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
int F_304 ( T_6 * V_228 ,
const struct V_270 * V_271 ,
const struct V_531 * V_532 ,
T_4 V_194 )
{
const struct V_365 * V_366 = NULL ;
if ( V_532 != NULL )
V_366 = & V_532 -> V_366 ;
return F_205 ( V_228 , V_271 -> V_66 , V_194 , V_366 ) ;
}
static bool F_305 ( T_6 * V_228 ,
const struct V_270 * V_271 ,
const struct V_531 * V_532 ,
T_4 V_194 )
{
T_6 V_533 ;
if ( F_304 ( & V_533 , V_271 , V_532 , V_194 ) )
return false ;
return F_116 ( V_228 , & V_533 ) ;
}
static bool F_306 ( int V_8 )
{
switch ( V_8 ) {
case - V_72 :
case - V_73 :
case - V_74 :
case - V_76 :
case - V_92 :
case - V_69 :
case - V_75 :
return true ;
}
return false ;
}
void F_307 ( struct V_534 * V_145 )
{
F_287 ( V_145 -> V_535 -> V_2 ) ;
}
static int F_308 ( struct V_113 * V_114 , struct V_534 * V_145 )
{
struct V_15 * V_16 = F_3 ( V_145 -> V_535 -> V_2 ) ;
if ( F_212 ( V_114 , V_16 , V_145 -> args . V_536 -> V_66 ) == - V_142 ) {
F_42 ( V_114 ) ;
return - V_142 ;
}
F_307 ( V_145 ) ;
if ( V_114 -> V_126 > 0 )
F_34 ( V_16 , V_145 -> V_97 ) ;
return 0 ;
}
static bool F_309 ( struct V_113 * V_114 ,
struct V_537 * args )
{
if ( ! F_306 ( V_114 -> V_126 ) ||
F_305 ( & args -> V_228 ,
args -> V_536 ,
args -> V_538 ,
V_70 ) )
return false ;
F_42 ( V_114 ) ;
return true ;
}
static int F_310 ( struct V_113 * V_114 , struct V_534 * V_145 )
{
F_9 ( L_12 , V_36 ) ;
if ( ! F_45 ( V_114 , & V_145 -> V_56 . V_148 ) )
return - V_142 ;
if ( F_309 ( V_114 , & V_145 -> args ) )
return - V_142 ;
return V_145 -> V_539 ? V_145 -> V_539 ( V_114 , V_145 ) :
F_308 ( V_114 , V_145 ) ;
}
static void F_311 ( struct V_534 * V_145 , struct V_149 * V_150 )
{
V_145 -> V_97 = V_139 ;
V_145 -> V_539 = F_308 ;
V_150 -> V_280 = & V_281 [ V_540 ] ;
F_46 ( & V_145 -> args . V_147 , & V_145 -> V_56 . V_148 , 0 ) ;
}
static void F_312 ( struct V_113 * V_114 , struct V_534 * V_145 )
{
if ( F_56 ( F_3 ( V_145 -> V_535 -> V_2 ) ,
& V_145 -> args . V_147 ,
& V_145 -> V_56 . V_148 ,
V_114 ) )
return;
F_304 ( & V_145 -> args . V_228 , V_145 -> args . V_536 ,
V_145 -> args . V_538 , V_70 ) ;
}
static int F_313 ( struct V_113 * V_114 , struct V_541 * V_145 )
{
struct V_2 * V_2 = V_145 -> V_535 -> V_2 ;
if ( F_212 ( V_114 , F_3 ( V_2 ) , V_145 -> args . V_536 -> V_66 ) == - V_142 ) {
F_42 ( V_114 ) ;
return - V_142 ;
}
if ( V_114 -> V_126 >= 0 ) {
F_34 ( F_3 ( V_2 ) , V_145 -> V_97 ) ;
F_314 ( V_2 , & V_145 -> V_356 ) ;
}
return 0 ;
}
static bool F_315 ( struct V_113 * V_114 ,
struct V_542 * args )
{
if ( ! F_306 ( V_114 -> V_126 ) ||
F_305 ( & args -> V_228 ,
args -> V_536 ,
args -> V_538 ,
V_206 ) )
return false ;
F_42 ( V_114 ) ;
return true ;
}
static int F_316 ( struct V_113 * V_114 , struct V_541 * V_145 )
{
if ( ! F_45 ( V_114 , & V_145 -> V_56 . V_148 ) )
return - V_142 ;
if ( F_315 ( V_114 , & V_145 -> args ) )
return - V_142 ;
return V_145 -> V_543 ? V_145 -> V_543 ( V_114 , V_145 ) :
F_313 ( V_114 , V_145 ) ;
}
static
bool F_317 ( const struct V_541 * V_145 )
{
const struct V_544 * V_545 = V_145 -> V_535 ;
if ( V_145 -> V_546 != NULL || V_545 -> V_547 != NULL )
return false ;
return F_21 ( V_545 -> V_2 , V_70 ) == 0 ;
}
static void F_318 ( struct V_541 * V_145 , struct V_149 * V_150 )
{
struct V_15 * V_16 = F_3 ( V_145 -> V_535 -> V_2 ) ;
if ( ! F_317 ( V_145 ) ) {
V_145 -> args . V_219 = NULL ;
V_145 -> V_56 . V_356 = NULL ;
} else
V_145 -> args . V_219 = V_16 -> V_384 ;
if ( ! V_145 -> V_543 )
V_145 -> V_543 = F_313 ;
V_145 -> V_56 . V_16 = V_16 ;
V_145 -> V_97 = V_139 ;
V_150 -> V_280 = & V_281 [ V_548 ] ;
F_46 ( & V_145 -> args . V_147 , & V_145 -> V_56 . V_148 , 1 ) ;
}
static void F_319 ( struct V_113 * V_114 , struct V_541 * V_145 )
{
if ( F_56 ( F_3 ( V_145 -> V_535 -> V_2 ) ,
& V_145 -> args . V_147 ,
& V_145 -> V_56 . V_148 ,
V_114 ) )
return;
F_304 ( & V_145 -> args . V_228 , V_145 -> args . V_536 ,
V_145 -> args . V_538 , V_206 ) ;
}
static void F_320 ( struct V_113 * V_114 , struct V_549 * V_145 )
{
F_56 ( F_3 ( V_145 -> V_2 ) ,
& V_145 -> args . V_147 ,
& V_145 -> V_56 . V_148 ,
V_114 ) ;
}
static int F_321 ( struct V_113 * V_114 , struct V_549 * V_145 )
{
struct V_2 * V_2 = V_145 -> V_2 ;
if ( F_212 ( V_114 , F_3 ( V_2 ) , NULL ) == - V_142 ) {
F_42 ( V_114 ) ;
return - V_142 ;
}
return 0 ;
}
static int F_322 ( struct V_113 * V_114 , struct V_549 * V_145 )
{
if ( ! F_45 ( V_114 , & V_145 -> V_56 . V_148 ) )
return - V_142 ;
return V_145 -> V_550 ( V_114 , V_145 ) ;
}
static void F_323 ( struct V_549 * V_145 , struct V_149 * V_150 )
{
struct V_15 * V_16 = F_3 ( V_145 -> V_2 ) ;
if ( V_145 -> V_550 == NULL )
V_145 -> V_550 = F_321 ;
V_145 -> V_56 . V_16 = V_16 ;
V_150 -> V_280 = & V_281 [ V_551 ] ;
F_46 ( & V_145 -> args . V_147 , & V_145 -> V_56 . V_148 , 1 ) ;
}
static void F_324 ( void * V_143 )
{
struct V_552 * V_145 = V_143 ;
struct V_10 * V_64 = V_145 -> V_90 ;
if ( F_325 ( & V_64 -> V_553 ) > 1 )
F_326 ( V_64 ) ;
F_327 ( V_64 ) ;
F_88 ( V_145 ) ;
}
static void F_328 ( struct V_113 * V_114 , void * V_143 )
{
struct V_552 * V_145 = V_143 ;
struct V_10 * V_64 = V_145 -> V_90 ;
unsigned long V_97 = V_145 -> V_97 ;
if ( V_114 -> V_126 < 0 ) {
if ( F_49 ( V_554 , & V_64 -> V_555 ) == 0 )
return;
if ( V_114 -> V_126 != V_556 ) {
F_25 ( V_64 ) ;
return;
}
F_329 ( V_64 ) ;
}
F_30 ( V_64 , V_97 ) ;
}
static int F_330 ( struct V_10 * V_64 , struct V_285 * V_319 , unsigned V_557 )
{
struct V_149 V_150 = {
. V_280 = & V_281 [ V_558 ] ,
. V_283 = V_64 ,
. V_285 = V_319 ,
} ;
struct V_552 * V_145 ;
if ( V_557 == 0 )
return 0 ;
if ( ! F_331 ( & V_64 -> V_553 ) )
return - V_37 ;
V_145 = F_239 ( sizeof( * V_145 ) , V_273 ) ;
if ( V_145 == NULL )
return - V_138 ;
V_145 -> V_90 = V_64 ;
V_145 -> V_97 = V_139 ;
return F_332 ( V_64 -> V_559 , & V_150 , V_560 ,
& V_561 , V_145 ) ;
}
static int F_333 ( struct V_10 * V_64 , struct V_285 * V_319 )
{
struct V_149 V_150 = {
. V_280 = & V_281 [ V_558 ] ,
. V_283 = V_64 ,
. V_285 = V_319 ,
} ;
unsigned long V_519 = V_139 ;
int V_275 ;
V_275 = F_65 ( V_64 -> V_559 , & V_150 , V_560 ) ;
if ( V_275 < 0 )
return V_275 ;
F_30 ( V_64 , V_519 ) ;
return 0 ;
}
static inline int F_334 ( struct V_15 * V_16 )
{
return ( V_16 -> V_93 & V_392 )
&& ( V_16 -> V_414 & V_562 )
&& ( V_16 -> V_414 & V_563 ) ;
}
static int F_335 ( const void * V_564 , T_8 V_565 ,
struct V_438 * * V_44 , unsigned int * V_51 )
{
struct V_438 * V_566 , * * V_567 ;
int V_568 = 0 ;
T_8 V_14 ;
V_567 = V_44 ;
do {
V_14 = F_336 ( T_8 , V_569 , V_565 ) ;
V_566 = F_238 ( V_348 ) ;
if ( V_566 == NULL )
goto V_570;
memcpy ( F_337 ( V_566 ) , V_564 , V_14 ) ;
V_564 += V_14 ;
V_565 -= V_14 ;
* V_44 ++ = V_566 ;
V_568 ++ ;
} while ( V_565 != 0 );
return V_568 ;
V_570:
for(; V_568 > 0 ; V_568 -- )
F_242 ( V_567 [ V_568 - 1 ] ) ;
return - V_138 ;
}
static void F_338 ( struct V_2 * V_2 , struct V_571 * V_572 )
{
struct V_161 * V_162 = F_68 ( V_2 ) ;
F_31 ( & V_2 -> V_163 ) ;
F_88 ( V_162 -> V_573 ) ;
V_162 -> V_573 = V_572 ;
F_33 ( & V_2 -> V_163 ) ;
}
static void F_339 ( struct V_2 * V_2 )
{
F_338 ( V_2 , NULL ) ;
}
static inline T_10 F_340 ( struct V_2 * V_2 , char * V_564 , T_8 V_565 )
{
struct V_161 * V_162 = F_68 ( V_2 ) ;
struct V_571 * V_572 ;
int V_67 = - V_272 ;
F_31 ( & V_2 -> V_163 ) ;
V_572 = V_162 -> V_573 ;
if ( V_572 == NULL )
goto V_118;
if ( V_564 == NULL )
goto V_574;
if ( V_572 -> V_575 == 0 )
goto V_118;
V_67 = - V_576 ;
if ( V_572 -> V_14 > V_565 )
goto V_118;
memcpy ( V_564 , V_572 -> V_145 , V_572 -> V_14 ) ;
V_574:
V_67 = V_572 -> V_14 ;
V_118:
F_33 ( & V_2 -> V_163 ) ;
return V_67 ;
}
static void F_341 ( struct V_2 * V_2 , struct V_438 * * V_44 , T_8 V_51 , T_8 V_577 )
{
struct V_571 * V_572 ;
T_8 V_565 = sizeof( * V_572 ) + V_577 ;
if ( V_565 <= V_569 ) {
V_572 = F_239 ( V_565 , V_348 ) ;
if ( V_572 == NULL )
goto V_118;
V_572 -> V_575 = 1 ;
F_342 ( V_572 -> V_145 , V_44 , V_51 , V_577 ) ;
} else {
V_572 = F_239 ( sizeof( * V_572 ) , V_348 ) ;
if ( V_572 == NULL )
goto V_118;
V_572 -> V_575 = 0 ;
}
V_572 -> V_14 = V_577 ;
V_118:
F_338 ( V_2 , V_572 ) ;
}
static T_10 F_343 ( struct V_2 * V_2 , void * V_564 , T_8 V_565 )
{
struct V_438 * V_44 [ V_578 ] = { NULL , } ;
struct V_579 args = {
. V_222 = F_85 ( V_2 ) ,
. V_580 = V_44 ,
. V_577 = V_565 ,
} ;
struct V_581 V_56 = {
. V_577 = V_565 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_582 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
unsigned int V_583 = F_344 ( V_565 , V_569 ) ;
int V_67 = - V_138 , V_430 ;
if ( V_583 == 0 )
V_583 = 1 ;
if ( V_583 > F_229 ( V_44 ) )
return - V_576 ;
for ( V_430 = 0 ; V_430 < V_583 ; V_430 ++ ) {
V_44 [ V_430 ] = F_238 ( V_348 ) ;
if ( ! V_44 [ V_430 ] )
goto V_279;
}
V_56 . V_584 = F_238 ( V_348 ) ;
if ( ! V_56 . V_584 )
goto V_279;
args . V_577 = V_583 * V_569 ;
args . V_585 = 0 ;
F_9 ( L_41 ,
V_36 , V_564 , V_565 , V_583 , args . V_577 ) ;
V_67 = F_66 ( F_3 ( V_2 ) -> V_90 , F_3 ( V_2 ) ,
& V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
if ( V_67 )
goto V_279;
if ( V_56 . V_586 & V_587 ) {
if ( V_564 == NULL )
goto V_588;
V_67 = - V_576 ;
goto V_279;
}
F_341 ( V_2 , V_44 , V_56 . V_589 , V_56 . V_577 ) ;
if ( V_564 ) {
if ( V_56 . V_577 > V_565 ) {
V_67 = - V_576 ;
goto V_279;
}
F_342 ( V_564 , V_44 , V_56 . V_589 , V_56 . V_577 ) ;
}
V_588:
V_67 = V_56 . V_577 ;
V_279:
for ( V_430 = 0 ; V_430 < V_583 ; V_430 ++ )
if ( V_44 [ V_430 ] )
F_242 ( V_44 [ V_430 ] ) ;
if ( V_56 . V_584 )
F_242 ( V_56 . V_584 ) ;
return V_67 ;
}
static T_10 F_345 ( struct V_2 * V_2 , void * V_564 , T_8 V_565 )
{
struct V_62 V_63 = { } ;
T_10 V_67 ;
do {
V_67 = F_343 ( V_2 , V_564 , V_565 ) ;
if ( V_67 >= 0 )
break;
V_67 = F_20 ( F_3 ( V_2 ) , V_67 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_67 ;
}
static T_10 F_346 ( struct V_2 * V_2 , void * V_564 , T_8 V_565 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
int V_67 ;
if ( ! F_334 ( V_16 ) )
return - V_590 ;
V_67 = F_347 ( V_16 , V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( F_68 ( V_2 ) -> V_164 & V_591 )
F_348 ( V_2 ) ;
V_67 = F_340 ( V_2 , V_564 , V_565 ) ;
if ( V_67 != - V_272 )
return V_67 ;
return F_345 ( V_2 , V_564 , V_565 ) ;
}
static int F_349 ( struct V_2 * V_2 , const void * V_564 , T_8 V_565 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_438 * V_44 [ V_578 ] ;
struct V_592 V_359 = {
. V_222 = F_85 ( V_2 ) ,
. V_580 = V_44 ,
. V_577 = V_565 ,
} ;
struct V_593 V_56 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_594 ] ,
. V_283 = & V_359 ,
. V_284 = & V_56 ,
} ;
unsigned int V_583 = F_344 ( V_565 , V_569 ) ;
int V_67 , V_430 ;
if ( ! F_334 ( V_16 ) )
return - V_590 ;
if ( V_583 > F_229 ( V_44 ) )
return - V_576 ;
V_430 = F_335 ( V_564 , V_565 , V_359 . V_580 , & V_359 . V_585 ) ;
if ( V_430 < 0 )
return V_430 ;
F_22 ( V_2 ) ;
V_67 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & V_359 . V_147 , & V_56 . V_148 , 1 ) ;
for (; V_430 > 0 ; V_430 -- )
F_350 ( V_44 [ V_430 - 1 ] ) ;
F_31 ( & V_2 -> V_163 ) ;
F_68 ( V_2 ) -> V_164 |= V_165 ;
F_33 ( & V_2 -> V_163 ) ;
F_351 ( V_2 ) ;
F_348 ( V_2 ) ;
return V_67 ;
}
static int F_352 ( struct V_2 * V_2 , const void * V_564 , T_8 V_565 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_2 ) ,
F_349 ( V_2 , V_564 , V_565 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_353 ( struct V_2 * V_2 , void * V_564 ,
T_8 V_565 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_355 V_356 ;
struct V_1 V_7 = { 0 , 0 , V_565 , V_564 } ;
T_1 V_219 [ 3 ] = { 0 , 0 , V_411 } ;
struct V_441 args = {
. V_222 = F_85 ( V_2 ) ,
. V_219 = V_219 ,
} ;
struct V_442 V_56 = {
. V_356 = & V_356 ,
. V_7 = & V_7 ,
. V_16 = V_16 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_443 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
int V_67 ;
F_74 ( & V_356 ) ;
V_67 = F_65 ( V_16 -> V_90 , & V_150 , 0 ) ;
if ( V_67 )
return V_67 ;
if ( ! ( V_356 . V_263 & V_595 ) )
return - V_272 ;
if ( V_565 < V_7 . V_14 )
return - V_576 ;
return 0 ;
}
static int F_354 ( struct V_2 * V_2 , void * V_564 ,
T_8 V_565 )
{
struct V_62 V_63 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_590 ;
do {
V_8 = F_20 ( F_3 ( V_2 ) ,
F_353 ( V_2 , V_564 , V_565 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_355 ( struct V_2 * V_2 ,
struct V_1 * V_357 ,
struct V_355 * V_356 ,
struct V_1 * V_347 )
{
struct V_5 V_6 = { 0 } ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
const T_1 V_219 [ 3 ] = { 0 , 0 , V_411 } ;
struct V_358 args = {
. V_222 = F_85 ( V_2 ) ,
. V_360 = & V_6 ,
. V_16 = V_16 ,
. V_219 = V_219 ,
. V_7 = V_357 ,
} ;
struct V_361 V_56 = {
. V_356 = V_356 ,
. V_7 = V_347 ,
. V_16 = V_16 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_362 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
int V_275 ;
F_107 ( & args . V_228 , & V_371 ) ;
V_275 = F_65 ( V_16 -> V_90 , & V_150 , 0 ) ;
if ( V_275 )
F_9 ( L_42 , V_36 , V_275 ) ;
return V_275 ;
}
static int F_356 ( struct V_2 * V_2 ,
struct V_1 * V_357 ,
struct V_355 * V_356 ,
struct V_1 * V_347 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_2 ) ,
F_355 ( V_2 , V_357 ,
V_356 , V_347 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int
F_357 ( struct V_4 * V_4 , const void * V_564 , T_8 V_565 )
{
struct V_1 V_357 , * V_347 = NULL ;
struct V_355 V_356 ;
struct V_285 * V_319 ;
struct V_2 * V_2 = V_4 -> V_48 ;
int V_275 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_590 ;
F_74 ( & V_356 ) ;
V_357 . V_596 = 0 ;
V_357 . V_597 = 0 ;
V_357 . V_7 = ( char * ) V_564 ;
V_357 . V_14 = V_565 ;
V_319 = F_358 () ;
if ( F_51 ( V_319 ) )
return F_62 ( V_319 ) ;
V_347 = F_79 ( F_3 ( V_2 ) , V_348 ) ;
if ( F_51 ( V_347 ) ) {
V_275 = - F_62 ( V_347 ) ;
goto V_118;
}
V_275 = F_356 ( V_2 , & V_357 , & V_356 , V_347 ) ;
if ( V_275 == 0 )
F_129 ( V_2 , & V_356 , V_347 ) ;
F_87 ( V_347 ) ;
V_118:
F_181 ( V_319 ) ;
return V_275 ;
}
static int
F_212 ( struct V_113 * V_114 , const struct V_15 * V_16 , struct V_65 * V_66 )
{
struct V_10 * V_64 = V_16 -> V_10 ;
if ( V_114 -> V_126 >= 0 )
return 0 ;
switch( V_114 -> V_126 ) {
case - V_72 :
case - V_73 :
case - V_74 :
if ( V_66 == NULL )
break;
F_24 ( V_66 -> V_2 ) ;
case - V_69 :
if ( V_66 == NULL )
break;
if ( F_23 ( V_16 , V_66 ) < 0 )
goto V_598;
goto V_71;
case - V_75 :
if ( V_66 != NULL ) {
if ( F_23 ( V_16 , V_66 ) < 0 )
goto V_598;
}
case - V_76 :
case - V_77 :
F_25 ( V_64 ) ;
goto V_71;
#if F_26 ( V_78 )
case - V_79 :
case - V_80 :
case - V_81 :
case - V_83 :
case - V_82 :
case - V_84 :
case - V_85 :
F_9 ( L_43 , V_36 ,
V_114 -> V_126 ) ;
F_27 ( V_64 -> V_86 , V_114 -> V_126 ) ;
V_114 -> V_126 = 0 ;
return - V_142 ;
#endif
case - V_89 :
F_359 ( V_16 , V_599 ) ;
case - V_88 :
F_44 ( V_114 , V_58 ) ;
V_114 -> V_126 = 0 ;
return - V_142 ;
case - V_91 :
case - V_92 :
V_114 -> V_126 = 0 ;
return - V_142 ;
}
V_114 -> V_126 = F_8 ( V_114 -> V_126 ) ;
return 0 ;
V_598:
V_114 -> V_126 = - V_37 ;
return 0 ;
V_71:
F_55 ( & V_64 -> V_600 , V_114 , NULL ) ;
if ( F_49 ( V_601 , & V_64 -> V_602 ) == 0 )
F_360 ( & V_64 -> V_600 , V_114 ) ;
V_114 -> V_126 = 0 ;
return - V_142 ;
}
static void F_361 ( const struct V_10 * V_64 ,
T_11 * V_603 )
{
T_3 V_225 [ 2 ] ;
if ( F_49 ( V_604 , & V_64 -> V_602 ) ) {
V_225 [ 0 ] = 0 ;
V_225 [ 1 ] = ( T_3 ) ( V_605 + 1 ) ;
} else {
struct V_606 * V_607 = F_362 ( V_64 -> V_608 , V_609 ) ;
V_225 [ 0 ] = ( T_3 ) V_607 -> V_610 . V_611 ;
V_225 [ 1 ] = ( T_3 ) V_607 -> V_610 . V_612 ;
}
memcpy ( V_603 -> V_145 , V_225 , sizeof( V_603 -> V_145 ) ) ;
}
static unsigned int
F_363 ( const struct V_10 * V_64 ,
char * V_564 , T_8 V_14 )
{
unsigned int V_613 ;
F_114 () ;
V_613 = F_364 ( V_564 , V_14 , L_44 ,
V_64 -> V_614 ,
F_365 ( V_64 -> V_559 ,
V_615 ) ,
F_365 ( V_64 -> V_559 ,
V_616 ) ) ;
F_117 () ;
return V_613 ;
}
static unsigned int
F_366 ( const struct V_10 * V_64 ,
char * V_564 , T_8 V_14 )
{
char * V_617 = V_64 -> V_559 -> V_618 ;
if ( V_619 [ 0 ] != '\0' )
V_617 = V_619 ;
return F_364 ( V_564 , V_14 , L_45 ,
V_64 -> V_620 -> V_621 , V_64 -> V_11 ,
V_617 ) ;
}
int F_367 ( struct V_10 * V_64 , T_1 V_622 ,
unsigned short V_623 , struct V_285 * V_319 ,
struct V_624 * V_56 )
{
T_11 V_625 ;
struct V_626 V_627 = {
. V_625 = & V_625 ,
. V_628 = V_622 ,
. V_629 = V_64 -> V_630 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_631 ] ,
. V_283 = & V_627 ,
. V_284 = V_56 ,
. V_285 = V_319 ,
} ;
int V_275 ;
F_361 ( V_64 , & V_625 ) ;
if ( F_49 ( V_632 , & V_64 -> V_633 ) )
V_627 . V_634 =
F_366 ( V_64 ,
V_627 . V_635 ,
sizeof( V_627 . V_635 ) ) ;
else
V_627 . V_634 =
F_363 ( V_64 ,
V_627 . V_635 ,
sizeof( V_627 . V_635 ) ) ;
F_114 () ;
V_627 . V_636 = F_364 ( V_627 . V_637 ,
sizeof( V_627 . V_637 ) , L_46 ,
F_365 ( V_64 -> V_559 ,
V_638 ) ) ;
F_117 () ;
V_627 . V_639 = F_364 ( V_627 . V_640 ,
sizeof( V_627 . V_640 ) , L_47 ,
V_64 -> V_614 , V_623 >> 8 , V_623 & 255 ) ;
F_9 ( L_48 ,
V_64 -> V_559 -> V_641 -> V_642 -> V_643 ,
V_627 . V_634 , V_627 . V_635 ) ;
V_275 = F_65 ( V_64 -> V_559 , & V_150 , V_560 ) ;
F_9 ( L_49 , V_275 ) ;
return V_275 ;
}
int F_368 ( struct V_10 * V_64 ,
struct V_624 * V_359 ,
struct V_285 * V_319 )
{
struct V_149 V_150 = {
. V_280 = & V_281 [ V_644 ] ,
. V_283 = V_359 ,
. V_285 = V_319 ,
} ;
int V_275 ;
F_9 ( L_50 ,
V_64 -> V_559 -> V_641 -> V_642 -> V_643 ,
V_64 -> V_213 ) ;
V_275 = F_65 ( V_64 -> V_559 , & V_150 , V_560 ) ;
F_9 ( L_51 , V_275 ) ;
return V_275 ;
}
static void F_369 ( struct V_113 * V_114 , void * V_143 )
{
struct V_645 * V_145 = V_143 ;
if ( ! F_45 ( V_114 , & V_145 -> V_56 . V_148 ) )
return;
switch ( V_114 -> V_126 ) {
case - V_76 :
case - V_75 :
case 0 :
F_34 ( V_145 -> V_56 . V_16 , V_145 -> V_97 ) ;
break;
default:
if ( F_212 ( V_114 , V_145 -> V_56 . V_16 , NULL ) ==
- V_142 ) {
F_42 ( V_114 ) ;
return;
}
}
V_145 -> V_261 = V_114 -> V_126 ;
}
static void F_370 ( void * V_143 )
{
F_88 ( V_143 ) ;
}
static void F_371 ( struct V_113 * V_114 , void * V_145 )
{
struct V_645 * V_646 ;
V_646 = (struct V_645 * ) V_145 ;
F_56 ( V_646 -> V_56 . V_16 ,
& V_646 -> args . V_147 ,
& V_646 -> V_56 . V_148 ,
V_114 ) ;
}
static int F_372 ( struct V_2 * V_2 , struct V_285 * V_319 , const T_6 * V_228 , int V_647 )
{
struct V_645 * V_145 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_113 * V_114 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_648 ] ,
. V_285 = V_319 ,
} ;
struct V_151 V_286 = {
. V_153 = V_16 -> V_90 ,
. V_149 = & V_150 ,
. V_154 = & V_649 ,
. V_195 = V_290 ,
} ;
int V_275 = 0 ;
V_145 = F_78 ( sizeof( * V_145 ) , V_273 ) ;
if ( V_145 == NULL )
return - V_138 ;
F_46 ( & V_145 -> args . V_147 , & V_145 -> V_56 . V_148 , 1 ) ;
V_145 -> args . V_388 = & V_145 -> V_222 ;
V_145 -> args . V_228 = & V_145 -> V_228 ;
V_145 -> args . V_219 = V_16 -> V_384 ;
F_160 ( & V_145 -> V_222 , F_85 ( V_2 ) ) ;
F_107 ( & V_145 -> V_228 , V_228 ) ;
V_145 -> V_56 . V_356 = & V_145 -> V_356 ;
V_145 -> V_56 . V_16 = V_16 ;
F_74 ( V_145 -> V_56 . V_356 ) ;
V_145 -> V_97 = V_139 ;
V_145 -> V_261 = 0 ;
V_286 . V_156 = V_145 ;
V_150 . V_283 = & V_145 -> args ;
V_150 . V_284 = & V_145 -> V_56 ;
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
if ( ! V_647 )
goto V_118;
V_275 = F_99 ( V_114 ) ;
if ( V_275 != 0 )
goto V_118;
V_275 = V_145 -> V_261 ;
if ( V_275 == 0 )
F_314 ( V_2 , & V_145 -> V_356 ) ;
else
F_128 ( V_2 , & V_145 -> V_356 ) ;
V_118:
F_63 ( V_114 ) ;
return V_275 ;
}
int F_373 ( struct V_2 * V_2 , struct V_285 * V_319 , const T_6 * V_228 , int V_647 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_372 ( V_2 , V_319 , V_228 , V_647 ) ;
switch ( V_8 ) {
case - V_76 :
case - V_75 :
case 0 :
return 0 ;
}
V_8 = F_20 ( V_16 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static unsigned long
F_374 ( unsigned long V_55 )
{
F_18 ( V_55 ) ;
V_55 <<= 1 ;
if ( V_55 > V_650 )
return V_650 ;
return V_55 ;
}
static int F_375 ( struct V_65 * V_66 , int V_651 , struct V_652 * V_653 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_10 * V_64 = V_16 -> V_10 ;
struct V_654 V_359 = {
. V_222 = F_85 ( V_2 ) ,
. V_655 = V_653 ,
} ;
struct V_656 V_56 = {
. V_657 = V_653 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_658 ] ,
. V_283 = & V_359 ,
. V_284 = & V_56 ,
. V_285 = V_66 -> V_203 -> V_258 ,
} ;
struct V_659 * V_660 ;
int V_275 ;
V_359 . V_661 . V_212 = V_64 -> V_213 ;
V_275 = F_376 ( V_66 , V_653 ) ;
if ( V_275 != 0 )
goto V_118;
V_660 = V_653 -> V_662 . V_663 . V_203 ;
V_359 . V_661 . V_214 = V_660 -> V_664 . V_217 ;
V_359 . V_661 . V_665 = V_16 -> V_665 ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & V_359 . V_147 , & V_56 . V_148 , 1 ) ;
switch ( V_275 ) {
case 0 :
V_653 -> V_666 = V_667 ;
break;
case - V_277 :
V_275 = 0 ;
}
V_653 -> V_668 -> V_669 ( V_653 ) ;
V_118:
return V_275 ;
}
static int F_377 ( struct V_65 * V_66 , int V_651 , struct V_652 * V_653 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_66 -> V_2 ) ,
F_375 ( V_66 , V_651 , V_653 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_378 ( struct V_670 * V_670 , struct V_652 * V_655 )
{
int V_56 = 0 ;
switch ( V_655 -> V_671 & ( V_672 | V_673 ) ) {
case V_672 :
V_56 = F_379 ( V_670 , V_655 ) ;
break;
case V_673 :
V_56 = F_380 ( V_670 , V_655 ) ;
break;
default:
F_381 () ;
}
return V_56 ;
}
static struct V_674 * F_382 ( struct V_652 * V_655 ,
struct V_270 * V_271 ,
struct V_659 * V_660 ,
struct V_675 * V_184 )
{
struct V_674 * V_43 ;
struct V_2 * V_2 = V_660 -> V_676 -> V_2 ;
V_43 = F_78 ( sizeof( * V_43 ) , V_273 ) ;
if ( V_43 == NULL )
return NULL ;
V_43 -> V_359 . V_222 = F_85 ( V_2 ) ;
V_43 -> V_359 . V_655 = & V_43 -> V_655 ;
V_43 -> V_359 . V_184 = V_184 ;
V_43 -> V_56 . V_184 = V_184 ;
V_43 -> V_359 . V_228 = & V_660 -> V_677 ;
V_43 -> V_660 = V_660 ;
F_83 ( & V_660 -> V_678 ) ;
V_43 -> V_271 = F_136 ( V_271 ) ;
memcpy ( & V_43 -> V_655 , V_655 , sizeof( V_43 -> V_655 ) ) ;
V_43 -> V_16 = F_3 ( V_2 ) ;
return V_43 ;
}
static void F_383 ( void * V_145 )
{
struct V_674 * V_143 = V_145 ;
F_92 ( V_143 -> V_359 . V_184 ) ;
F_384 ( V_143 -> V_660 ) ;
F_147 ( V_143 -> V_271 ) ;
F_88 ( V_143 ) ;
}
static void F_385 ( struct V_113 * V_114 , void * V_145 )
{
struct V_674 * V_143 = V_145 ;
if ( ! F_45 ( V_114 , & V_143 -> V_56 . V_148 ) )
return;
switch ( V_114 -> V_126 ) {
case 0 :
F_107 ( & V_143 -> V_660 -> V_677 ,
& V_143 -> V_56 . V_228 ) ;
F_34 ( V_143 -> V_16 , V_143 -> V_97 ) ;
break;
case - V_74 :
case - V_92 :
case - V_76 :
case - V_75 :
break;
default:
if ( F_212 ( V_114 , V_143 -> V_16 , NULL ) == - V_142 )
F_42 ( V_114 ) ;
}
F_120 ( V_143 -> V_359 . V_184 ) ;
}
static void F_386 ( struct V_113 * V_114 , void * V_145 )
{
struct V_674 * V_143 = V_145 ;
if ( F_159 ( V_143 -> V_359 . V_184 , V_114 ) != 0 )
goto V_292;
if ( F_49 ( V_679 , & V_143 -> V_660 -> V_680 ) == 0 ) {
goto V_293;
}
V_143 -> V_97 = V_139 ;
if ( F_56 ( V_143 -> V_16 ,
& V_143 -> V_359 . V_147 ,
& V_143 -> V_56 . V_148 ,
V_114 ) != 0 )
F_120 ( V_143 -> V_359 . V_184 ) ;
return;
V_293:
V_114 -> V_304 = NULL ;
V_292:
F_45 ( V_114 , & V_143 -> V_56 . V_148 ) ;
}
static struct V_113 * F_387 ( struct V_652 * V_655 ,
struct V_270 * V_271 ,
struct V_659 * V_660 ,
struct V_675 * V_184 )
{
struct V_674 * V_145 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_681 ] ,
. V_285 = V_271 -> V_319 ,
} ;
struct V_151 V_286 = {
. V_153 = F_253 ( V_660 -> V_676 -> V_2 ) ,
. V_149 = & V_150 ,
. V_154 = & V_682 ,
. V_288 = V_289 ,
. V_195 = V_290 ,
} ;
V_655 -> V_666 = V_667 ;
V_145 = F_382 ( V_655 , V_271 , V_660 , V_184 ) ;
if ( V_145 == NULL ) {
F_92 ( V_184 ) ;
return F_52 ( - V_138 ) ;
}
F_46 ( & V_145 -> V_359 . V_147 , & V_145 -> V_56 . V_148 , 1 ) ;
V_150 . V_283 = & V_145 -> V_359 ;
V_150 . V_284 = & V_145 -> V_56 ;
V_286 . V_156 = V_145 ;
return F_61 ( & V_286 ) ;
}
static int F_388 ( struct V_65 * V_66 , int V_651 , struct V_652 * V_653 )
{
struct V_2 * V_2 = V_66 -> V_2 ;
struct V_192 * V_193 = V_66 -> V_203 ;
struct V_161 * V_162 = F_68 ( V_2 ) ;
struct V_675 * V_184 ;
struct V_659 * V_660 ;
struct V_113 * V_114 ;
int V_275 = 0 ;
unsigned char V_671 = V_653 -> V_671 ;
V_275 = F_376 ( V_66 , V_653 ) ;
V_653 -> V_671 |= V_683 ;
F_389 ( & V_193 -> V_684 ) ;
F_390 ( & V_162 -> V_685 ) ;
if ( F_378 ( V_653 -> V_686 , V_653 ) == - V_272 ) {
F_391 ( & V_162 -> V_685 ) ;
F_392 ( & V_193 -> V_684 ) ;
goto V_118;
}
F_391 ( & V_162 -> V_685 ) ;
F_392 ( & V_193 -> V_684 ) ;
if ( V_275 != 0 )
goto V_118;
V_660 = V_653 -> V_662 . V_663 . V_203 ;
if ( F_49 ( V_679 , & V_660 -> V_680 ) == 0 )
goto V_118;
V_184 = F_80 ( & V_660 -> V_664 , V_348 ) ;
V_275 = - V_138 ;
if ( V_184 == NULL )
goto V_118;
V_114 = F_387 ( V_653 , F_246 ( V_653 -> V_686 ) , V_660 , V_184 ) ;
V_275 = F_62 ( V_114 ) ;
if ( F_51 ( V_114 ) )
goto V_118;
V_275 = F_99 ( V_114 ) ;
F_63 ( V_114 ) ;
V_118:
V_653 -> V_671 = V_671 ;
return V_275 ;
}
static struct V_687 * F_393 ( struct V_652 * V_655 ,
struct V_270 * V_271 , struct V_659 * V_660 ,
T_5 V_197 )
{
struct V_687 * V_43 ;
struct V_2 * V_2 = V_660 -> V_676 -> V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
V_43 = F_78 ( sizeof( * V_43 ) , V_197 ) ;
if ( V_43 == NULL )
return NULL ;
V_43 -> V_359 . V_222 = F_85 ( V_2 ) ;
V_43 -> V_359 . V_655 = & V_43 -> V_655 ;
V_43 -> V_359 . V_688 = F_80 ( & V_660 -> V_676 -> V_203 -> V_200 , V_197 ) ;
if ( V_43 -> V_359 . V_688 == NULL )
goto V_279;
V_43 -> V_359 . V_689 = F_80 ( & V_660 -> V_664 , V_197 ) ;
if ( V_43 -> V_359 . V_689 == NULL )
goto V_690;
V_43 -> V_359 . V_691 = & V_660 -> V_677 ;
V_43 -> V_359 . V_661 . V_212 = V_16 -> V_10 -> V_213 ;
V_43 -> V_359 . V_661 . V_214 = V_660 -> V_664 . V_217 ;
V_43 -> V_359 . V_661 . V_665 = V_16 -> V_665 ;
V_43 -> V_56 . V_689 = V_43 -> V_359 . V_689 ;
V_43 -> V_660 = V_660 ;
V_43 -> V_16 = V_16 ;
F_83 ( & V_660 -> V_678 ) ;
V_43 -> V_271 = F_136 ( V_271 ) ;
memcpy ( & V_43 -> V_655 , V_655 , sizeof( V_43 -> V_655 ) ) ;
return V_43 ;
V_690:
F_92 ( V_43 -> V_359 . V_688 ) ;
V_279:
F_88 ( V_43 ) ;
return NULL ;
}
static void F_394 ( struct V_113 * V_114 , void * V_143 )
{
struct V_687 * V_145 = V_143 ;
struct V_65 * V_66 = V_145 -> V_660 -> V_676 ;
F_9 ( L_30 , V_36 ) ;
if ( F_159 ( V_145 -> V_359 . V_689 , V_114 ) != 0 )
goto V_292;
if ( ! ( V_145 -> V_359 . V_689 -> V_692 -> V_195 & V_693 ) ) {
if ( F_159 ( V_145 -> V_359 . V_688 , V_114 ) != 0 ) {
goto V_694;
}
V_145 -> V_359 . V_246 = & V_66 -> V_246 ;
V_145 -> V_359 . V_695 = 1 ;
V_145 -> V_56 . V_688 = V_145 -> V_359 . V_688 ;
} else
V_145 -> V_359 . V_695 = 0 ;
if ( ! F_204 ( V_66 ) ) {
V_145 -> V_261 = - V_372 ;
V_114 -> V_304 = NULL ;
goto V_696;
}
V_145 -> V_97 = V_139 ;
if ( F_56 ( V_145 -> V_16 ,
& V_145 -> V_359 . V_147 ,
& V_145 -> V_56 . V_148 ,
V_114 ) == 0 )
return;
V_696:
F_120 ( V_145 -> V_359 . V_688 ) ;
V_694:
F_120 ( V_145 -> V_359 . V_689 ) ;
V_292:
F_45 ( V_114 , & V_145 -> V_56 . V_148 ) ;
F_9 ( L_52 , V_36 , V_145 -> V_261 ) ;
}
static void F_395 ( struct V_113 * V_114 , void * V_143 )
{
struct V_687 * V_145 = V_143 ;
F_9 ( L_30 , V_36 ) ;
if ( ! F_45 ( V_114 , & V_145 -> V_56 . V_148 ) )
return;
V_145 -> V_261 = V_114 -> V_126 ;
if ( V_145 -> V_359 . V_695 != 0 ) {
if ( V_145 -> V_261 == 0 )
F_153 ( & V_145 -> V_660 -> V_664 , 0 ) ;
else
goto V_118;
}
if ( V_145 -> V_261 == 0 ) {
F_107 ( & V_145 -> V_660 -> V_677 , & V_145 -> V_56 . V_228 ) ;
F_108 ( V_679 , & V_145 -> V_660 -> V_680 ) ;
F_34 ( F_3 ( V_145 -> V_271 -> V_4 -> V_48 ) , V_145 -> V_97 ) ;
}
V_118:
F_9 ( L_31 , V_36 , V_145 -> V_261 ) ;
}
static void F_396 ( void * V_143 )
{
struct V_687 * V_145 = V_143 ;
F_9 ( L_30 , V_36 ) ;
F_92 ( V_145 -> V_359 . V_688 ) ;
if ( V_145 -> V_278 != 0 ) {
struct V_113 * V_114 ;
V_114 = F_387 ( & V_145 -> V_655 , V_145 -> V_271 , V_145 -> V_660 ,
V_145 -> V_359 . V_689 ) ;
if ( ! F_51 ( V_114 ) )
F_397 ( V_114 ) ;
F_9 ( L_53 , V_36 ) ;
} else
F_92 ( V_145 -> V_359 . V_689 ) ;
F_384 ( V_145 -> V_660 ) ;
F_147 ( V_145 -> V_271 ) ;
F_88 ( V_145 ) ;
F_9 ( L_32 , V_36 ) ;
}
static void F_398 ( struct V_15 * V_16 , struct V_659 * V_660 , int V_695 , int error )
{
switch ( error ) {
case - V_73 :
case - V_74 :
V_660 -> V_664 . V_195 &= ~ V_693 ;
if ( V_695 != 0 ||
F_49 ( V_679 , & V_660 -> V_680 ) != 0 )
F_23 ( V_16 , V_660 -> V_676 ) ;
break;
case - V_76 :
V_660 -> V_664 . V_195 &= ~ V_693 ;
case - V_75 :
F_25 ( V_16 -> V_10 ) ;
} ;
}
static int F_399 ( struct V_65 * V_66 , int V_651 , struct V_652 * V_655 , int V_697 )
{
struct V_687 * V_145 ;
struct V_113 * V_114 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_698 ] ,
. V_285 = V_66 -> V_203 -> V_258 ,
} ;
struct V_151 V_286 = {
. V_153 = F_253 ( V_66 -> V_2 ) ,
. V_149 = & V_150 ,
. V_154 = & V_699 ,
. V_288 = V_289 ,
. V_195 = V_290 ,
} ;
int V_67 ;
F_9 ( L_30 , V_36 ) ;
V_145 = F_393 ( V_655 , F_246 ( V_655 -> V_686 ) ,
V_655 -> V_662 . V_663 . V_203 ,
V_697 == V_700 ? V_348 : V_273 ) ;
if ( V_145 == NULL )
return - V_138 ;
if ( F_400 ( V_651 ) )
V_145 -> V_359 . V_701 = 1 ;
F_46 ( & V_145 -> V_359 . V_147 , & V_145 -> V_56 . V_148 , 1 ) ;
V_150 . V_283 = & V_145 -> V_359 ;
V_150 . V_284 = & V_145 -> V_56 ;
V_286 . V_156 = V_145 ;
if ( V_697 > V_700 ) {
if ( V_697 == V_702 )
V_145 -> V_359 . V_703 = V_702 ;
F_47 ( & V_145 -> V_359 . V_147 ) ;
}
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
V_67 = F_99 ( V_114 ) ;
if ( V_67 == 0 ) {
V_67 = V_145 -> V_261 ;
if ( V_67 )
F_398 ( V_145 -> V_16 , V_145 -> V_660 ,
V_145 -> V_359 . V_695 , V_67 ) ;
} else
V_145 -> V_278 = 1 ;
F_63 ( V_114 ) ;
F_9 ( L_31 , V_36 , V_67 ) ;
return V_67 ;
}
static int F_401 ( struct V_65 * V_66 , struct V_652 * V_653 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
struct V_62 V_63 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_49 ( V_245 , & V_66 -> V_195 ) != 0 )
return 0 ;
V_8 = F_399 ( V_66 , V_704 , V_653 , V_702 ) ;
if ( V_8 != - V_89 )
break;
F_20 ( V_16 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_402 ( struct V_65 * V_66 , struct V_652 * V_653 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
struct V_62 V_63 = {
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
V_8 = F_376 ( V_66 , V_653 ) ;
if ( V_8 != 0 )
return V_8 ;
do {
if ( F_49 ( V_245 , & V_66 -> V_195 ) != 0 )
return 0 ;
V_8 = F_399 ( V_66 , V_704 , V_653 , V_705 ) ;
switch ( V_8 ) {
default:
goto V_118;
case - V_88 :
case - V_89 :
F_20 ( V_16 , V_8 , & V_63 ) ;
V_8 = 0 ;
}
} while ( V_63 . V_68 );
V_118:
return V_8 ;
}
static int F_403 ( struct V_65 * V_66 )
{
int V_275 , V_67 = - V_74 ;
struct V_659 * V_660 ;
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
F_135 (lsp, &state->lock_states, ls_locks) {
if ( F_49 ( V_679 , & V_660 -> V_680 ) ) {
struct V_285 * V_319 = V_660 -> V_676 -> V_203 -> V_258 ;
V_275 = F_179 ( V_16 ,
& V_660 -> V_677 ,
V_319 ) ;
if ( V_275 != V_332 ) {
if ( V_275 != - V_74 )
F_180 ( V_16 ,
& V_660 -> V_677 ,
V_319 ) ;
F_142 ( V_679 , & V_660 -> V_680 ) ;
V_67 = V_275 ;
}
}
} ;
return V_67 ;
}
static int F_404 ( struct V_65 * V_66 , struct V_652 * V_653 )
{
int V_275 = V_332 ;
if ( F_49 ( V_706 , & V_66 -> V_195 ) )
V_275 = F_403 ( V_66 ) ;
if ( V_275 != V_332 )
V_275 = F_402 ( V_66 , V_653 ) ;
return V_275 ;
}
static int F_405 ( struct V_65 * V_66 , int V_651 , struct V_652 * V_653 )
{
struct V_192 * V_193 = V_66 -> V_203 ;
struct V_161 * V_162 = F_68 ( V_66 -> V_2 ) ;
unsigned char V_671 = V_653 -> V_671 ;
unsigned int V_340 ;
int V_275 = - V_707 ;
if ( ( V_671 & V_672 ) &&
! F_49 ( V_342 , & V_66 -> V_195 ) )
goto V_118;
V_275 = F_376 ( V_66 , V_653 ) ;
if ( V_275 != 0 )
goto V_118;
V_653 -> V_671 |= V_708 ;
V_275 = F_378 ( V_653 -> V_686 , V_653 ) ;
if ( V_275 < 0 )
goto V_118;
F_390 ( & V_162 -> V_685 ) ;
if ( F_49 ( V_245 , & V_66 -> V_195 ) ) {
V_653 -> V_671 = V_671 & ~ V_709 ;
V_275 = F_378 ( V_653 -> V_686 , V_653 ) ;
goto V_111;
}
V_340 = F_186 ( & V_193 -> V_341 ) ;
F_391 ( & V_162 -> V_685 ) ;
V_275 = F_399 ( V_66 , V_651 , V_653 , V_700 ) ;
if ( V_275 != 0 )
goto V_118;
F_390 ( & V_162 -> V_685 ) ;
if ( F_192 ( & V_193 -> V_341 , V_340 ) ) {
V_275 = - V_89 ;
goto V_111;
}
V_653 -> V_671 = V_671 | V_709 ;
if ( F_378 ( V_653 -> V_686 , V_653 ) < 0 )
F_28 ( V_95 L_54
L_55 , V_36 ) ;
V_111:
F_391 ( & V_162 -> V_685 ) ;
V_118:
V_653 -> V_671 = V_671 ;
return V_275 ;
}
static int F_406 ( struct V_65 * V_66 , int V_651 , struct V_652 * V_653 )
{
struct V_62 V_63 = {
. V_66 = V_66 ,
. V_2 = V_66 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_405 ( V_66 , V_651 , V_653 ) ;
if ( V_8 == - V_277 )
V_8 = - V_142 ;
V_8 = F_20 ( F_3 ( V_66 -> V_2 ) ,
V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int
F_407 ( struct V_670 * V_710 , int V_651 , struct V_652 * V_653 )
{
struct V_270 * V_271 ;
struct V_65 * V_66 ;
unsigned long V_55 = V_711 ;
int V_275 ;
V_271 = F_246 ( V_710 ) ;
V_66 = V_271 -> V_66 ;
if ( V_653 -> V_712 < 0 || V_653 -> V_713 < 0 )
return - V_28 ;
if ( F_408 ( V_651 ) ) {
if ( V_66 != NULL )
return F_377 ( V_66 , V_714 , V_653 ) ;
return 0 ;
}
if ( ! ( F_409 ( V_651 ) || F_400 ( V_651 ) ) )
return - V_28 ;
if ( V_653 -> V_666 == V_667 ) {
if ( V_66 != NULL )
return F_388 ( V_66 , V_651 , V_653 ) ;
return 0 ;
}
if ( V_66 == NULL )
return - V_707 ;
switch ( V_653 -> V_666 ) {
case V_715 :
if ( ! ( V_710 -> V_716 & V_70 ) )
return - V_372 ;
break;
case V_717 :
if ( ! ( V_710 -> V_716 & V_206 ) )
return - V_372 ;
}
do {
V_275 = F_406 ( V_66 , V_651 , V_653 ) ;
if ( ( V_275 != - V_142 ) || F_409 ( V_651 ) )
break;
V_55 = F_374 ( V_55 ) ;
V_275 = - V_60 ;
if ( F_410 () )
break;
} while( V_275 < 0 );
return V_275 ;
}
int F_411 ( struct V_652 * V_655 , struct V_65 * V_66 , const T_6 * V_228 )
{
struct V_15 * V_16 = F_3 ( V_66 -> V_2 ) ;
int V_8 ;
V_8 = F_376 ( V_66 , V_655 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_399 ( V_66 , V_704 , V_655 , V_700 ) ;
return F_148 ( V_16 , V_66 , V_228 , V_8 ) ;
}
static void F_412 ( void * V_143 )
{
struct V_718 * V_145 = V_143 ;
F_413 ( V_145 -> V_16 , V_145 -> V_660 ) ;
F_88 ( V_143 ) ;
}
static int F_414 ( struct V_15 * V_16 , struct V_659 * V_660 )
{
struct V_718 * V_145 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_719 ] ,
} ;
if ( V_16 -> V_10 -> V_157 -> V_302 != 0 )
return - V_28 ;
V_145 = F_239 ( sizeof( * V_145 ) , V_273 ) ;
if ( ! V_145 )
return - V_138 ;
V_145 -> V_660 = V_660 ;
V_145 -> V_16 = V_16 ;
V_145 -> args . V_661 . V_212 = V_16 -> V_10 -> V_213 ;
V_145 -> args . V_661 . V_214 = V_660 -> V_664 . V_217 ;
V_145 -> args . V_661 . V_665 = V_16 -> V_665 ;
V_150 . V_283 = & V_145 -> args ;
F_332 ( V_16 -> V_90 , & V_150 , 0 , & V_720 , V_145 ) ;
return 0 ;
}
static int F_415 ( struct V_4 * V_4 , const char * V_721 ,
const void * V_564 , T_8 V_565 ,
int V_195 , int type )
{
if ( strcmp ( V_721 , L_56 ) != 0 )
return - V_28 ;
return F_352 ( V_4 -> V_48 , V_564 , V_565 ) ;
}
static int F_416 ( struct V_4 * V_4 , const char * V_721 ,
void * V_564 , T_8 V_565 , int type )
{
if ( strcmp ( V_721 , L_56 ) != 0 )
return - V_28 ;
return F_346 ( V_4 -> V_48 , V_564 , V_565 ) ;
}
static T_8 F_417 ( struct V_4 * V_4 , char * V_722 ,
T_8 V_723 , const char * V_218 ,
T_8 V_724 , int type )
{
T_8 V_14 = sizeof( V_725 ) ;
if ( ! F_334 ( F_3 ( V_4 -> V_48 ) ) )
return 0 ;
if ( V_722 && V_14 <= V_723 )
memcpy ( V_722 , V_725 , V_14 ) ;
return V_14 ;
}
static inline int F_418 ( struct V_15 * V_16 )
{
return V_16 -> V_93 & V_9 ;
}
static int F_419 ( struct V_4 * V_4 , const char * V_721 ,
const void * V_564 , T_8 V_565 ,
int V_195 , int type )
{
if ( F_420 ( V_721 ) )
return F_357 ( V_4 , V_564 , V_565 ) ;
return - V_590 ;
}
static int F_421 ( struct V_4 * V_4 , const char * V_721 ,
void * V_564 , T_8 V_565 , int type )
{
if ( F_420 ( V_721 ) )
return F_354 ( V_4 -> V_48 , V_564 , V_565 ) ;
return - V_590 ;
}
static T_8 F_422 ( struct V_4 * V_4 , char * V_722 ,
T_8 V_723 , const char * V_218 ,
T_8 V_724 , int type )
{
T_8 V_14 = 0 ;
if ( F_2 ( V_4 -> V_48 , V_9 ) ) {
V_14 = F_423 ( V_4 -> V_48 , NULL , 0 ) ;
if ( V_722 && V_14 <= V_723 )
F_423 ( V_4 -> V_48 , V_722 , V_14 ) ;
}
return V_14 ;
}
static void F_241 ( struct V_355 * V_356 )
{
if ( ! ( ( ( V_356 -> V_263 & V_726 ) ||
( V_356 -> V_263 & V_265 ) ) &&
( V_356 -> V_263 & V_435 ) &&
( V_356 -> V_263 & V_727 ) ) )
return;
V_356 -> V_263 |= V_264 | V_450 |
V_451 | V_728 ;
V_356 -> V_232 = V_309 | V_453 | V_454 ;
V_356 -> V_455 = 2 ;
}
static int F_424 ( struct V_53 * V_90 , struct V_2 * V_3 ,
const struct V_437 * V_218 ,
struct V_439 * V_729 ,
struct V_438 * V_438 )
{
struct V_15 * V_16 = F_3 ( V_3 ) ;
T_1 V_219 [ 3 ] = {
[ 0 ] = V_730 | V_731 ,
} ;
struct V_732 args = {
. V_448 = F_85 ( V_3 ) ,
. V_218 = V_218 ,
. V_438 = V_438 ,
. V_219 = V_219 ,
} ;
struct V_733 V_56 = {
. V_729 = V_729 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_734 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
int V_275 ;
F_9 ( L_57 , V_36 ) ;
if ( F_3 ( V_3 ) -> V_17 [ 1 ] & V_735 )
V_219 [ 1 ] |= V_735 ;
else
V_219 [ 0 ] |= V_47 ;
F_74 ( & V_729 -> V_356 ) ;
V_729 -> V_16 = V_16 ;
V_729 -> V_736 = 0 ;
V_275 = F_66 ( V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
F_9 ( L_58 , V_36 , V_275 ) ;
return V_275 ;
}
int F_240 ( struct V_53 * V_90 , struct V_2 * V_3 ,
const struct V_437 * V_218 ,
struct V_439 * V_729 ,
struct V_438 * V_438 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_3 ) ,
F_424 ( V_90 , V_3 , V_218 , V_729 , V_438 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_425 ( struct V_2 * V_3 , const struct V_437 * V_218 , struct V_737 * V_738 )
{
int V_275 ;
struct V_739 args = {
. V_448 = F_85 ( V_3 ) ,
. V_218 = V_218 ,
} ;
struct V_740 V_56 = {
. V_738 = V_738 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_741 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
F_9 ( L_59 , V_218 -> V_218 ) ;
V_275 = F_66 ( F_3 ( V_3 ) -> V_90 , F_3 ( V_3 ) , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
F_9 ( L_60 , V_275 ) ;
return V_275 ;
}
int F_426 ( struct V_2 * V_3 , const struct V_437 * V_218 ,
struct V_737 * V_738 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( F_3 ( V_3 ) ,
F_425 ( V_3 , V_218 , V_738 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static int F_427 ( T_1 V_195 )
{
if ( V_195 & ~ V_742 )
goto V_743;
if ( ( V_195 & V_744 ) &&
( V_195 & V_745 ) )
goto V_743;
if ( ! ( V_195 & ( V_746 ) ) )
goto V_743;
return V_332 ;
V_743:
return - V_747 ;
}
static bool
F_428 ( struct V_748 * V_749 ,
struct V_748 * V_750 )
{
if ( V_749 -> V_751 == V_750 -> V_751 &&
memcmp ( V_749 -> V_752 , V_750 -> V_752 , V_749 -> V_751 ) == 0 )
return true ;
return false ;
}
int F_429 ( struct V_10 * V_64 , struct V_285 * V_319 )
{
int V_275 ;
struct V_753 V_56 ;
struct V_149 V_150 = {
. V_280 =
& V_281 [ V_754 ] ,
. V_283 = V_64 ,
. V_284 = & V_56 ,
. V_285 = V_319 ,
} ;
F_9 ( L_12 , V_36 ) ;
V_56 . V_102 = F_78 ( sizeof( struct V_101 ) , V_273 ) ;
if ( F_430 ( V_56 . V_102 == NULL ) ) {
V_275 = - V_138 ;
goto V_118;
}
V_275 = F_65 ( V_64 -> V_559 , & V_150 , V_560 ) ;
if ( V_275 == 0 ) {
if ( memcmp ( V_56 . V_102 -> V_755 . V_145 ,
V_64 -> V_86 -> V_755 . V_145 , V_756 ) ) {
F_9 ( L_61 , V_36 ) ;
V_275 = - V_37 ;
goto V_757;
}
if ( V_56 . V_3 != V_758 ) {
F_9 ( L_62 ,
V_36 ) ;
V_275 = - V_37 ;
goto V_757;
}
if ( V_56 . V_759 ) {
F_9 ( L_63 ,
V_36 ) ;
V_275 = - V_37 ;
goto V_757;
}
}
V_757:
F_88 ( V_56 . V_102 ) ;
V_118:
F_9 ( L_64 , V_36 , V_275 ) ;
return V_275 ;
}
int F_431 ( struct V_10 * V_64 , struct V_285 * V_319 )
{
T_11 V_39 ;
struct V_760 args = {
. V_39 = & V_39 ,
. V_90 = V_64 ,
. V_195 = V_761 |
V_762 ,
} ;
struct V_763 V_56 = {
0
} ;
int V_275 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_764 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
. V_285 = V_319 ,
} ;
F_361 ( V_64 , & V_39 ) ;
args . V_765 = F_366 ( V_64 , args . V_214 ,
sizeof( args . V_214 ) ) ;
F_9 ( L_65 ,
V_64 -> V_559 -> V_641 -> V_642 -> V_643 ,
args . V_765 , args . V_214 ) ;
V_56 . V_766 = F_78 ( sizeof( struct V_767 ) ,
V_273 ) ;
if ( F_430 ( V_56 . V_766 == NULL ) ) {
V_275 = - V_138 ;
goto V_118;
}
V_56 . V_752 = F_78 ( sizeof( struct V_748 ) ,
V_273 ) ;
if ( F_430 ( V_56 . V_752 == NULL ) ) {
V_275 = - V_138 ;
goto V_768;
}
V_56 . V_769 = F_78 ( sizeof( struct V_770 ) , V_273 ) ;
if ( F_430 ( V_56 . V_769 == NULL ) ) {
V_275 = - V_138 ;
goto V_771;
}
V_275 = F_65 ( V_64 -> V_559 , & V_150 , V_560 ) ;
if ( V_275 == 0 )
V_275 = F_427 ( V_56 . V_195 ) ;
if ( V_275 == 0 ) {
V_64 -> V_213 = V_56 . V_212 ;
V_64 -> V_772 = ( V_56 . V_195 & ~ V_773 ) ;
if ( ! ( V_56 . V_195 & V_773 ) )
V_64 -> V_774 = V_56 . V_184 ;
F_88 ( V_64 -> V_775 ) ;
V_64 -> V_775 = V_56 . V_766 ;
V_56 . V_766 = NULL ;
F_88 ( V_64 -> V_776 ) ;
V_64 -> V_776 = V_56 . V_769 ;
if ( V_64 -> V_777 != NULL &&
! F_428 ( V_64 -> V_777 ,
V_56 . V_752 ) ) {
F_9 ( L_66 ,
V_36 ) ;
F_108 ( V_778 , & V_64 -> V_602 ) ;
F_88 ( V_64 -> V_777 ) ;
V_64 -> V_777 = NULL ;
}
if ( V_64 -> V_777 == NULL ) {
V_64 -> V_777 = V_56 . V_752 ;
goto V_118;
}
} else
F_88 ( V_56 . V_769 ) ;
V_768:
F_88 ( V_56 . V_766 ) ;
V_771:
F_88 ( V_56 . V_752 ) ;
V_118:
if ( V_64 -> V_776 != NULL )
F_9 ( L_67
L_68 ,
V_64 -> V_776 -> V_779 , V_64 -> V_776 -> V_218 ,
V_64 -> V_776 -> V_780 . V_781 ,
V_64 -> V_776 -> V_780 . V_782 ) ;
F_9 ( L_69 , V_275 ) ;
return V_275 ;
}
static int F_432 ( struct V_10 * V_64 ,
struct V_285 * V_319 )
{
struct V_149 V_150 = {
. V_280 = & V_281 [ V_783 ] ,
. V_283 = V_64 ,
. V_285 = V_319 ,
} ;
int V_275 ;
V_275 = F_65 ( V_64 -> V_559 , & V_150 , V_560 ) ;
if ( V_275 )
F_9 ( L_70
L_71 , V_275 , V_64 -> V_96 ) ;
return V_275 ;
}
static int F_433 ( struct V_10 * V_64 ,
struct V_285 * V_319 )
{
unsigned int V_784 ;
int V_67 ;
for ( V_784 = V_785 ; V_784 != 0 ; V_784 -- ) {
V_67 = F_432 ( V_64 , V_319 ) ;
switch ( V_67 ) {
case - V_89 :
case - V_786 :
F_150 ( 1 ) ;
break;
default:
return V_67 ;
}
}
return 0 ;
}
int F_434 ( struct V_10 * V_64 )
{
struct V_285 * V_319 ;
int V_67 = 0 ;
if ( V_64 -> V_157 -> V_302 < 1 )
goto V_118;
if ( V_64 -> V_772 == 0 )
goto V_118;
if ( V_64 -> V_787 )
goto V_118;
V_319 = F_435 ( V_64 ) ;
V_67 = F_433 ( V_64 , V_319 ) ;
if ( V_319 )
F_181 ( V_319 ) ;
switch ( V_67 ) {
case 0 :
case - V_77 :
V_64 -> V_772 = 0 ;
}
V_118:
return V_67 ;
}
static void F_436 ( struct V_113 * V_114 ,
void * V_143 )
{
struct V_788 * V_145 =
(struct V_788 * ) V_143 ;
F_9 ( L_12 , V_36 ) ;
F_48 ( V_145 -> V_64 -> V_86 ,
& V_145 -> args -> V_789 ,
& V_145 -> V_56 -> V_790 ,
V_114 ) ;
F_9 ( L_72 , V_36 ) ;
}
static void F_437 ( struct V_113 * V_114 , void * V_143 )
{
struct V_788 * V_145 =
(struct V_788 * ) V_143 ;
F_9 ( L_12 , V_36 ) ;
if ( ! F_39 ( V_114 , & V_145 -> V_56 -> V_790 ) )
return;
switch ( V_114 -> V_126 ) {
case - V_89 :
case - V_88 :
F_9 ( L_73 , V_36 , V_114 -> V_126 ) ;
F_44 ( V_114 , V_57 ) ;
V_114 -> V_126 = 0 ;
case - V_91 :
F_42 ( V_114 ) ;
return;
}
F_9 ( L_72 , V_36 ) ;
}
int F_438 ( struct V_10 * V_64 , struct V_416 * V_515 )
{
struct V_113 * V_114 ;
struct V_791 args ;
struct V_792 V_56 = {
. V_793 = V_515 ,
} ;
struct V_788 V_145 = {
. args = & args ,
. V_56 = & V_56 ,
. V_64 = V_64 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_794 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
struct V_151 V_152 = {
. V_153 = V_64 -> V_559 ,
. V_149 = & V_150 ,
. V_154 = & V_795 ,
. V_156 = & V_145 ,
. V_195 = V_560 ,
} ;
int V_275 ;
F_46 ( & args . V_789 , & V_56 . V_790 , 0 ) ;
F_47 ( & args . V_789 ) ;
F_9 ( L_12 , V_36 ) ;
V_114 = F_61 ( & V_152 ) ;
if ( F_51 ( V_114 ) )
V_275 = F_62 ( V_114 ) ;
else {
V_275 = V_114 -> V_126 ;
F_63 ( V_114 ) ;
}
F_9 ( L_74 , V_36 , V_275 ) ;
return V_275 ;
}
static void F_439 ( struct V_796 * args )
{
unsigned int V_797 , V_798 ;
V_797 = V_799 + V_800 ;
V_798 = V_799 + V_801 ;
args -> V_802 . V_797 = V_797 ;
args -> V_802 . V_798 = V_798 ;
args -> V_802 . V_803 = V_804 ;
args -> V_802 . V_805 = V_806 ;
F_9 ( L_75
L_76 ,
V_36 ,
args -> V_802 . V_797 , args -> V_802 . V_798 ,
args -> V_802 . V_803 , args -> V_802 . V_805 ) ;
args -> V_807 . V_797 = V_569 ;
args -> V_807 . V_798 = V_569 ;
args -> V_807 . V_808 = 0 ;
args -> V_807 . V_803 = V_809 ;
args -> V_807 . V_805 = 1 ;
F_9 ( L_77
L_78 ,
V_36 ,
args -> V_807 . V_797 , args -> V_807 . V_798 ,
args -> V_807 . V_808 , args -> V_807 . V_803 ,
args -> V_807 . V_805 ) ;
}
static int F_440 ( struct V_796 * args , struct V_101 * V_102 )
{
struct V_810 * V_811 = & args -> V_802 ;
struct V_810 * V_812 = & V_102 -> V_802 ;
if ( V_812 -> V_798 > V_811 -> V_798 )
return - V_28 ;
if ( V_812 -> V_803 < V_811 -> V_803 )
return - V_28 ;
if ( V_812 -> V_805 == 0 )
return - V_28 ;
if ( V_812 -> V_805 > V_813 )
V_812 -> V_805 = V_813 ;
return 0 ;
}
static int F_441 ( struct V_796 * args , struct V_101 * V_102 )
{
struct V_810 * V_811 = & args -> V_807 ;
struct V_810 * V_812 = & V_102 -> V_807 ;
if ( V_812 -> V_797 > V_811 -> V_797 )
return - V_28 ;
if ( V_812 -> V_798 < V_811 -> V_798 )
return - V_28 ;
if ( V_812 -> V_808 > V_811 -> V_808 )
return - V_28 ;
if ( V_812 -> V_803 != V_811 -> V_803 )
return - V_28 ;
if ( V_812 -> V_805 != V_811 -> V_805 )
return - V_28 ;
return 0 ;
}
static int F_442 ( struct V_796 * args ,
struct V_101 * V_102 )
{
int V_67 ;
V_67 = F_440 ( args , V_102 ) ;
if ( V_67 )
return V_67 ;
return F_441 ( args , V_102 ) ;
}
static int F_443 ( struct V_10 * V_64 ,
struct V_285 * V_319 )
{
struct V_101 * V_102 = V_64 -> V_86 ;
struct V_796 args = {
. V_90 = V_64 ,
. V_814 = V_815 ,
} ;
struct V_816 V_56 = {
. V_90 = V_64 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_817 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
. V_285 = V_319 ,
} ;
int V_275 ;
F_439 ( & args ) ;
args . V_195 = ( V_818 | V_819 ) ;
V_275 = F_65 ( V_102 -> V_64 -> V_559 , & V_150 , V_560 ) ;
if ( ! V_275 ) {
V_275 = F_442 ( & args , V_102 ) ;
V_64 -> V_774 ++ ;
}
return V_275 ;
}
int F_444 ( struct V_10 * V_64 , struct V_285 * V_319 )
{
int V_275 ;
unsigned * V_820 ;
struct V_101 * V_102 = V_64 -> V_86 ;
F_9 ( L_79 , V_36 , V_64 , V_102 ) ;
V_275 = F_443 ( V_64 , V_319 ) ;
if ( V_275 )
goto V_118;
V_275 = F_445 ( V_102 ) ;
F_9 ( L_80 , V_275 ) ;
if ( V_275 )
goto V_118;
V_820 = ( unsigned * ) & V_102 -> V_755 . V_145 [ 0 ] ;
F_9 ( L_81 , V_36 ,
V_64 -> V_774 , V_820 [ 0 ] , V_820 [ 1 ] , V_820 [ 2 ] , V_820 [ 3 ] ) ;
V_118:
F_9 ( L_72 , V_36 ) ;
return V_275 ;
}
int F_446 ( struct V_101 * V_102 ,
struct V_285 * V_319 )
{
struct V_149 V_150 = {
. V_280 = & V_281 [ V_821 ] ,
. V_283 = V_102 ,
. V_285 = V_319 ,
} ;
int V_275 = 0 ;
F_9 ( L_82 ) ;
if ( V_102 -> V_64 -> V_822 != V_823 )
return V_275 ;
V_275 = F_65 ( V_102 -> V_64 -> V_559 , & V_150 , V_560 ) ;
if ( V_275 )
F_9 ( L_83
L_84 , V_275 ) ;
F_9 ( L_85 ) ;
return V_275 ;
}
static void F_447 ( void * V_145 )
{
struct V_824 * V_143 = V_145 ;
struct V_10 * V_64 = V_143 -> V_64 ;
if ( F_325 ( & V_64 -> V_553 ) > 1 )
F_326 ( V_64 ) ;
F_327 ( V_64 ) ;
F_88 ( V_143 ) ;
}
static int F_448 ( struct V_113 * V_114 , struct V_10 * V_64 )
{
switch( V_114 -> V_126 ) {
case - V_89 :
F_44 ( V_114 , V_58 ) ;
return - V_142 ;
default:
F_25 ( V_64 ) ;
}
return 0 ;
}
static void F_449 ( struct V_113 * V_114 , void * V_145 )
{
struct V_824 * V_143 = V_145 ;
struct V_10 * V_64 = V_143 -> V_64 ;
if ( ! F_39 ( V_114 , V_114 -> V_296 . V_284 ) )
return;
if ( V_114 -> V_126 < 0 ) {
F_9 ( L_86 , V_36 , V_114 -> V_126 ) ;
if ( F_325 ( & V_64 -> V_553 ) == 1 )
goto V_118;
if ( F_448 ( V_114 , V_64 ) == - V_142 ) {
F_42 ( V_114 ) ;
return;
}
}
F_9 ( L_87 , V_36 , V_114 -> V_296 . V_285 ) ;
V_118:
F_9 ( L_72 , V_36 ) ;
}
static void F_450 ( struct V_113 * V_114 , void * V_145 )
{
struct V_824 * V_143 = V_145 ;
struct V_10 * V_64 = V_143 -> V_64 ;
struct V_127 * args ;
struct V_100 * V_56 ;
args = V_114 -> V_296 . V_283 ;
V_56 = V_114 -> V_296 . V_284 ;
F_48 ( V_64 -> V_86 , args , V_56 , V_114 ) ;
}
static struct V_113 * F_451 ( struct V_10 * V_64 ,
struct V_285 * V_319 ,
bool V_825 )
{
struct V_824 * V_143 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_826 ] ,
. V_285 = V_319 ,
} ;
struct V_151 V_286 = {
. V_153 = V_64 -> V_559 ,
. V_149 = & V_150 ,
. V_154 = & V_827 ,
. V_195 = V_290 | V_560 ,
} ;
if ( ! F_331 ( & V_64 -> V_553 ) )
return F_52 ( - V_37 ) ;
V_143 = F_78 ( sizeof( * V_143 ) , V_273 ) ;
if ( V_143 == NULL ) {
F_327 ( V_64 ) ;
return F_52 ( - V_138 ) ;
}
F_46 ( & V_143 -> args , & V_143 -> V_56 , 0 ) ;
if ( V_825 )
F_47 ( & V_143 -> args ) ;
V_150 . V_283 = & V_143 -> args ;
V_150 . V_284 = & V_143 -> V_56 ;
V_143 -> V_64 = V_64 ;
V_286 . V_156 = V_143 ;
return F_61 ( & V_286 ) ;
}
static int F_452 ( struct V_10 * V_64 , struct V_285 * V_319 , unsigned V_557 )
{
struct V_113 * V_114 ;
int V_67 = 0 ;
if ( ( V_557 & V_828 ) == 0 )
return 0 ;
V_114 = F_451 ( V_64 , V_319 , false ) ;
if ( F_51 ( V_114 ) )
V_67 = F_62 ( V_114 ) ;
else
F_397 ( V_114 ) ;
F_9 ( L_17 , V_36 , V_67 ) ;
return V_67 ;
}
static int F_453 ( struct V_10 * V_64 , struct V_285 * V_319 )
{
struct V_113 * V_114 ;
int V_67 ;
V_114 = F_451 ( V_64 , V_319 , true ) ;
if ( F_51 ( V_114 ) ) {
V_67 = F_62 ( V_114 ) ;
goto V_118;
}
V_67 = F_100 ( V_114 ) ;
if ( ! V_67 ) {
struct V_100 * V_56 = V_114 -> V_296 . V_284 ;
if ( V_114 -> V_126 == 0 )
F_454 ( V_64 , V_56 -> V_122 ) ;
V_67 = V_114 -> V_126 ;
}
F_63 ( V_114 ) ;
V_118:
F_9 ( L_17 , V_36 , V_67 ) ;
return V_67 ;
}
static void F_455 ( struct V_113 * V_114 , void * V_145 )
{
struct V_829 * V_143 = V_145 ;
F_48 ( V_143 -> V_64 -> V_86 ,
& V_143 -> V_359 . V_147 ,
& V_143 -> V_56 . V_148 ,
V_114 ) ;
}
static int F_456 ( struct V_113 * V_114 , struct V_10 * V_64 )
{
switch( V_114 -> V_126 ) {
case 0 :
case - V_830 :
case - V_831 :
break;
case - V_89 :
F_44 ( V_114 , V_58 ) ;
case - V_91 :
return - V_142 ;
default:
F_25 ( V_64 ) ;
}
return 0 ;
}
static void F_457 ( struct V_113 * V_114 , void * V_145 )
{
struct V_829 * V_143 = V_145 ;
struct V_10 * V_64 = V_143 -> V_64 ;
struct V_100 * V_56 = & V_143 -> V_56 . V_148 ;
F_9 ( L_12 , V_36 ) ;
if ( ! F_39 ( V_114 , V_56 ) )
return;
if ( F_456 ( V_114 , V_64 ) == - V_142 ) {
F_42 ( V_114 ) ;
return;
}
F_9 ( L_72 , V_36 ) ;
}
static void F_458 ( void * V_145 )
{
struct V_829 * V_143 = V_145 ;
F_88 ( V_143 ) ;
}
static int F_459 ( struct V_10 * V_64 ,
struct V_285 * V_319 )
{
struct V_829 * V_143 ;
struct V_113 * V_114 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_832 ] ,
. V_285 = V_319 ,
} ;
struct V_151 V_286 = {
. V_153 = V_64 -> V_559 ,
. V_149 = & V_150 ,
. V_154 = & V_833 ,
. V_195 = V_290 ,
} ;
int V_275 = - V_138 ;
F_9 ( L_12 , V_36 ) ;
V_143 = F_78 ( sizeof( * V_143 ) , V_273 ) ;
if ( V_143 == NULL )
goto V_118;
V_143 -> V_64 = V_64 ;
V_143 -> V_359 . V_834 = 0 ;
F_46 ( & V_143 -> V_359 . V_147 , & V_143 -> V_56 . V_148 , 0 ) ;
F_47 ( & V_143 -> V_359 . V_147 ) ;
V_150 . V_283 = & V_143 -> V_359 ;
V_150 . V_284 = & V_143 -> V_56 ;
V_286 . V_156 = V_143 ;
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) ) {
V_275 = F_62 ( V_114 ) ;
goto V_118;
}
V_275 = F_99 ( V_114 ) ;
if ( V_275 == 0 )
V_275 = V_114 -> V_126 ;
F_63 ( V_114 ) ;
return 0 ;
V_118:
F_9 ( L_17 , V_36 , V_275 ) ;
return V_275 ;
}
static void
F_460 ( struct V_113 * V_114 , void * V_143 )
{
struct V_835 * V_836 = V_143 ;
struct V_15 * V_16 = F_3 ( V_836 -> args . V_2 ) ;
struct V_101 * V_102 = F_57 ( V_16 ) ;
F_9 ( L_12 , V_36 ) ;
if ( F_48 ( V_102 , & V_836 -> args . V_147 ,
& V_836 -> V_56 . V_148 , V_114 ) )
return;
if ( F_461 ( & V_836 -> args . V_228 ,
F_68 ( V_836 -> args . V_2 ) -> V_837 ,
V_836 -> args . V_271 -> V_66 ) ) {
F_462 ( V_114 , V_838 ) ;
}
}
static void F_463 ( struct V_113 * V_114 , void * V_143 )
{
struct V_835 * V_836 = V_143 ;
struct V_2 * V_2 = V_836 -> args . V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
struct V_839 * V_840 ;
struct V_65 * V_66 = NULL ;
unsigned long V_841 , V_842 ;
F_9 ( L_12 , V_36 ) ;
if ( ! F_39 ( V_114 , & V_836 -> V_56 . V_148 ) )
goto V_118;
switch ( V_114 -> V_126 ) {
case 0 :
goto V_118;
case - V_21 :
case - V_22 :
V_841 = F_464 ( V_114 -> V_843 ) ;
V_842 = V_836 -> args . V_97 + V_841 ;
if ( F_465 ( V_842 , V_139 ) )
V_114 -> V_126 = - V_89 ;
break;
case - V_75 :
case - V_74 :
F_31 ( & V_2 -> V_163 ) ;
V_840 = F_68 ( V_2 ) -> V_837 ;
if ( ! V_840 || F_466 ( & V_840 -> V_844 ) ) {
F_33 ( & V_2 -> V_163 ) ;
V_66 = V_836 -> args . V_271 -> V_66 ;
} else {
F_467 ( V_845 ) ;
F_468 ( V_840 , & V_845 , NULL ) ;
F_33 ( & V_2 -> V_163 ) ;
F_469 ( & V_845 ) ;
}
}
if ( F_212 ( V_114 , V_16 , V_66 ) == - V_142 )
F_42 ( V_114 ) ;
V_118:
F_9 ( L_72 , V_36 ) ;
}
static T_8 F_470 ( struct V_15 * V_16 )
{
T_1 V_798 = V_16 -> V_10 -> V_86 -> V_802 . V_798 ;
return F_471 ( 0 , V_798 ) ;
}
static void F_472 ( struct V_438 * * V_44 , T_8 V_846 )
{
int V_430 ;
if ( ! V_44 )
return;
for ( V_430 = 0 ; V_430 < V_846 ; V_430 ++ ) {
if ( ! V_44 [ V_430 ] )
break;
F_242 ( V_44 [ V_430 ] ) ;
}
F_88 ( V_44 ) ;
}
static struct V_438 * * F_473 ( T_8 V_846 , T_5 V_847 )
{
struct V_438 * * V_44 ;
int V_430 ;
V_44 = F_474 ( V_846 , sizeof( struct V_438 * ) , V_847 ) ;
if ( ! V_44 ) {
F_9 ( L_88 , V_36 , V_846 ) ;
return NULL ;
}
for ( V_430 = 0 ; V_430 < V_846 ; V_430 ++ ) {
V_44 [ V_430 ] = F_238 ( V_847 ) ;
if ( ! V_44 [ V_430 ] ) {
F_9 ( L_89 , V_36 ) ;
F_472 ( V_44 , V_846 ) ;
return NULL ;
}
}
return V_44 ;
}
static void F_475 ( void * V_143 )
{
struct V_835 * V_836 = V_143 ;
struct V_2 * V_2 = V_836 -> args . V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
T_8 V_848 = F_470 ( V_16 ) ;
F_9 ( L_12 , V_36 ) ;
F_472 ( V_836 -> args . V_837 . V_44 , V_848 ) ;
F_476 ( F_68 ( V_2 ) -> V_837 ) ;
F_147 ( V_836 -> args . V_271 ) ;
F_88 ( V_143 ) ;
F_9 ( L_72 , V_36 ) ;
}
struct V_849 *
F_477 ( struct V_835 * V_836 , T_5 V_847 )
{
struct V_2 * V_2 = V_836 -> args . V_2 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
T_8 V_848 = F_470 ( V_16 ) ;
struct V_113 * V_114 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_850 ] ,
. V_283 = & V_836 -> args ,
. V_284 = & V_836 -> V_56 ,
. V_285 = V_836 -> V_319 ,
} ;
struct V_151 V_286 = {
. V_153 = V_16 -> V_90 ,
. V_149 = & V_150 ,
. V_154 = & V_851 ,
. V_156 = V_836 ,
. V_195 = V_290 ,
} ;
struct V_849 * V_852 = NULL ;
int V_275 = 0 ;
F_9 ( L_12 , V_36 ) ;
V_836 -> args . V_837 . V_44 = F_473 ( V_848 , V_847 ) ;
if ( ! V_836 -> args . V_837 . V_44 ) {
F_475 ( V_836 ) ;
return F_52 ( - V_138 ) ;
}
V_836 -> args . V_837 . V_465 = V_848 * V_569 ;
V_836 -> args . V_97 = V_139 ;
V_836 -> V_56 . V_853 = & V_836 -> args . V_837 ;
V_836 -> V_56 . V_148 . V_106 = NULL ;
F_46 ( & V_836 -> args . V_147 , & V_836 -> V_56 . V_148 , 0 ) ;
F_478 ( F_68 ( V_2 ) -> V_837 ) ;
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) )
return F_218 ( V_114 ) ;
V_275 = F_99 ( V_114 ) ;
if ( V_275 == 0 )
V_275 = V_114 -> V_126 ;
if ( V_275 == 0 && V_836 -> V_56 . V_853 -> V_14 )
V_852 = F_479 ( V_836 ) ;
F_63 ( V_114 ) ;
F_9 ( L_17 , V_36 , V_275 ) ;
if ( V_275 )
return F_52 ( V_275 ) ;
return V_852 ;
}
static void
F_480 ( struct V_113 * V_114 , void * V_143 )
{
struct V_854 * V_855 = V_143 ;
F_9 ( L_12 , V_36 ) ;
F_48 ( V_855 -> V_64 -> V_86 ,
& V_855 -> args . V_147 ,
& V_855 -> V_56 . V_148 ,
V_114 ) ;
}
static void F_481 ( struct V_113 * V_114 , void * V_143 )
{
struct V_854 * V_855 = V_143 ;
struct V_15 * V_16 ;
F_9 ( L_12 , V_36 ) ;
if ( ! F_39 ( V_114 , & V_855 -> V_56 . V_148 ) )
return;
V_16 = F_3 ( V_855 -> args . V_2 ) ;
if ( F_212 ( V_114 , V_16 , NULL ) == - V_142 ) {
F_42 ( V_114 ) ;
return;
}
F_9 ( L_72 , V_36 ) ;
}
static void F_482 ( void * V_143 )
{
struct V_854 * V_855 = V_143 ;
struct V_839 * V_840 = V_855 -> args . V_837 ;
F_9 ( L_12 , V_36 ) ;
F_31 ( & V_840 -> V_856 -> V_163 ) ;
if ( V_855 -> V_56 . V_857 )
F_483 ( V_840 , & V_855 -> V_56 . V_228 , true ) ;
V_840 -> V_858 -- ;
F_33 ( & V_840 -> V_856 -> V_163 ) ;
F_476 ( V_855 -> args . V_837 ) ;
F_88 ( V_143 ) ;
F_9 ( L_72 , V_36 ) ;
}
int F_484 ( struct V_854 * V_855 )
{
struct V_113 * V_114 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_859 ] ,
. V_283 = & V_855 -> args ,
. V_284 = & V_855 -> V_56 ,
. V_285 = V_855 -> V_319 ,
} ;
struct V_151 V_286 = {
. V_153 = V_855 -> V_64 -> V_559 ,
. V_149 = & V_150 ,
. V_154 = & V_860 ,
. V_156 = V_855 ,
} ;
int V_275 ;
F_9 ( L_12 , V_36 ) ;
F_46 ( & V_855 -> args . V_147 , & V_855 -> V_56 . V_148 , 1 ) ;
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
V_275 = V_114 -> V_126 ;
F_9 ( L_17 , V_36 , V_275 ) ;
F_63 ( V_114 ) ;
return V_275 ;
}
static int F_485 ( struct V_15 * V_16 ,
const struct V_387 * V_222 ,
struct V_861 * V_862 )
{
struct V_863 args = {
. V_222 = V_222 ,
. V_864 = V_16 -> V_865 -> V_214 ,
} ;
struct V_866 V_56 = {
. V_862 = V_862 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_867 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
int V_275 ;
F_9 ( L_12 , V_36 ) ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 ,
& V_56 . V_148 , 0 ) ;
F_9 ( L_17 , V_36 , V_275 ) ;
return V_275 ;
}
int F_486 ( struct V_15 * V_16 ,
const struct V_387 * V_222 ,
struct V_861 * V_862 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_485 ( V_16 , V_222 , V_862 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
F_9 ( L_90 , V_36 ,
V_8 , V_862 -> V_868 ) ;
return V_8 ;
}
static int
F_487 ( struct V_15 * V_16 ,
struct V_869 * V_870 ,
struct V_285 * V_319 )
{
struct V_871 args = {
. V_870 = V_870 ,
} ;
struct V_872 V_56 = {
. V_870 = V_870 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_873 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
. V_285 = V_319 ,
} ;
int V_275 ;
F_9 ( L_12 , V_36 ) ;
V_275 = F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
F_9 ( L_17 , V_36 , V_275 ) ;
return V_275 ;
}
int F_488 ( struct V_15 * V_16 ,
struct V_869 * V_870 ,
struct V_285 * V_319 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_20 ( V_16 ,
F_487 ( V_16 , V_870 , V_319 ) ,
& V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static void F_489 ( struct V_113 * V_114 , void * V_143 )
{
struct V_874 * V_145 = V_143 ;
struct V_15 * V_16 = F_3 ( V_145 -> args . V_2 ) ;
struct V_101 * V_102 = F_57 ( V_16 ) ;
F_48 ( V_102 ,
& V_145 -> args . V_147 ,
& V_145 -> V_56 . V_148 ,
V_114 ) ;
}
static void
F_490 ( struct V_113 * V_114 , void * V_143 )
{
struct V_874 * V_145 = V_143 ;
struct V_15 * V_16 = F_3 ( V_145 -> args . V_2 ) ;
if ( ! F_39 ( V_114 , & V_145 -> V_56 . V_148 ) )
return;
switch ( V_114 -> V_126 ) {
case - V_72 :
case - V_875 :
case - V_876 :
case - V_88 :
V_114 -> V_126 = 0 ;
break;
case 0 :
F_314 ( V_145 -> args . V_2 ,
V_145 -> V_56 . V_356 ) ;
break;
default:
if ( F_212 ( V_114 , V_16 , NULL ) == - V_142 ) {
F_42 ( V_114 ) ;
return;
}
}
}
static void F_491 ( void * V_143 )
{
struct V_874 * V_145 = V_143 ;
F_492 ( V_145 ) ;
F_181 ( V_145 -> V_319 ) ;
F_88 ( V_145 ) ;
}
int
F_493 ( struct V_874 * V_145 , bool V_877 )
{
struct V_149 V_150 = {
. V_280 = & V_281 [ V_878 ] ,
. V_283 = & V_145 -> args ,
. V_284 = & V_145 -> V_56 ,
. V_285 = V_145 -> V_319 ,
} ;
struct V_151 V_286 = {
. V_114 = & V_145 -> V_114 ,
. V_153 = F_253 ( V_145 -> args . V_2 ) ,
. V_149 = & V_150 ,
. V_154 = & V_879 ,
. V_156 = V_145 ,
. V_195 = V_290 ,
} ;
struct V_113 * V_114 ;
int V_275 = 0 ;
F_9 ( L_91
L_92 ,
V_145 -> V_114 . V_880 , V_877 ,
V_145 -> args . V_881 ,
V_145 -> args . V_2 -> V_882 ) ;
F_46 ( & V_145 -> args . V_147 , & V_145 -> V_56 . V_148 , 1 ) ;
V_114 = F_61 ( & V_286 ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
if ( V_877 == false )
goto V_118;
V_275 = F_99 ( V_114 ) ;
if ( V_275 != 0 )
goto V_118;
V_275 = V_114 -> V_126 ;
V_118:
F_9 ( L_93 , V_36 , V_275 ) ;
F_63 ( V_114 ) ;
return V_275 ;
}
static int
F_494 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_417 , struct V_737 * V_738 )
{
struct V_883 args = {
. V_884 = V_885 ,
} ;
struct V_740 V_56 = {
. V_738 = V_738 ,
} ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_886 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
} ;
return F_66 ( V_16 -> V_90 , V_16 , & V_150 , & args . V_147 , & V_56 . V_148 , 0 ) ;
}
static int
F_495 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_417 , struct V_737 * V_738 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_494 ( V_16 , V_388 , V_417 , V_738 ) ;
switch ( V_8 ) {
case 0 :
case - V_24 :
case - V_887 :
goto V_118;
default:
V_8 = F_20 ( V_16 , V_8 , & V_63 ) ;
}
} while ( V_63 . V_68 );
V_118:
return V_8 ;
}
static int
F_496 ( struct V_15 * V_16 , struct V_387 * V_388 ,
struct V_416 * V_417 )
{
int V_8 ;
struct V_438 * V_438 ;
T_7 V_421 ;
struct V_737 * V_738 ;
V_438 = F_238 ( V_348 ) ;
if ( ! V_438 ) {
V_8 = - V_138 ;
goto V_118;
}
V_738 = F_337 ( V_438 ) ;
V_8 = F_495 ( V_16 , V_388 , V_417 , V_738 ) ;
if ( V_8 == - V_24 || V_8 == - V_887 ) {
V_8 = F_228 ( V_16 , V_388 , V_417 ) ;
goto V_888;
}
if ( V_8 )
goto V_888;
V_421 = F_497 ( V_738 ) ;
if ( V_8 == 0 )
V_8 = F_226 ( V_16 , V_388 , V_417 , V_421 ) ;
V_888:
F_350 ( V_438 ) ;
if ( V_8 == - V_30 )
return - V_25 ;
V_118:
return V_8 ;
}
static int F_498 ( struct V_15 * V_16 ,
T_6 * V_228 ,
struct V_285 * V_319 )
{
int V_275 ;
struct V_889 args = {
. V_228 = V_228 ,
} ;
struct V_890 V_56 ;
struct V_149 V_150 = {
. V_280 = & V_281 [ V_891 ] ,
. V_283 = & args ,
. V_284 = & V_56 ,
. V_285 = V_319 ,
} ;
F_9 ( L_94 , V_228 ) ;
F_46 ( & args . V_147 , & V_56 . V_148 , 0 ) ;
F_47 ( & args . V_147 ) ;
V_275 = F_60 ( V_16 -> V_90 , V_16 , & V_150 ,
& args . V_147 , & V_56 . V_148 ) ;
if ( V_275 != V_332 ) {
F_9 ( L_95 , V_275 ) ;
return V_275 ;
}
F_9 ( L_96 , - V_56 . V_275 ) ;
return - V_56 . V_275 ;
}
static int F_179 ( struct V_15 * V_16 ,
T_6 * V_228 ,
struct V_285 * V_319 )
{
struct V_62 V_63 = { } ;
int V_8 ;
do {
V_8 = F_498 ( V_16 , V_228 , V_319 ) ;
if ( V_8 != - V_89 )
break;
F_20 ( V_16 , V_8 , & V_63 ) ;
} while ( V_63 . V_68 );
return V_8 ;
}
static void F_499 ( struct V_113 * V_114 , void * V_143 )
{
struct V_892 * V_145 = V_143 ;
F_48 ( F_57 ( V_145 -> V_16 ) ,
& V_145 -> args . V_147 ,
& V_145 -> V_56 . V_148 ,
V_114 ) ;
}
static void F_500 ( struct V_113 * V_114 , void * V_143 )
{
struct V_892 * V_145 = V_143 ;
F_39 ( V_114 , & V_145 -> V_56 . V_148 ) ;
switch ( V_114 -> V_126 ) {
case - V_89 :
if ( F_212 ( V_114 , V_145 -> V_16 , NULL ) == - V_142 )
F_42 ( V_114 ) ;
}
}
static void F_501 ( void * V_143 )
{
F_88 ( V_143 ) ;
}
static struct V_113 * F_502 ( struct V_15 * V_16 ,
T_6 * V_228 ,
struct V_285 * V_319 ,
bool V_893 )
{
struct V_149 V_150 = {
. V_280 = & V_281 [ V_894 ] ,
. V_285 = V_319 ,
} ;
struct V_151 V_152 = {
. V_153 = V_16 -> V_90 ,
. V_149 = & V_150 ,
. V_154 = & V_895 ,
. V_195 = V_290 ,
} ;
struct V_892 * V_145 ;
F_9 ( L_97 , V_228 ) ;
V_145 = F_239 ( sizeof( * V_145 ) , V_273 ) ;
if ( ! V_145 )
return F_52 ( - V_138 ) ;
V_145 -> V_16 = V_16 ;
F_107 ( & V_145 -> args . V_228 , V_228 ) ;
V_152 . V_156 = V_145 ;
V_150 . V_283 = & V_145 -> args ;
V_150 . V_284 = & V_145 -> V_56 ;
F_46 ( & V_145 -> args . V_147 , & V_145 -> V_56 . V_148 , 0 ) ;
if ( V_893 )
F_47 ( & V_145 -> args . V_147 ) ;
return F_61 ( & V_152 ) ;
}
static int F_180 ( struct V_15 * V_16 ,
T_6 * V_228 ,
struct V_285 * V_319 )
{
struct V_113 * V_114 ;
int V_67 ;
V_114 = F_502 ( V_16 , V_228 , V_319 , true ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
V_67 = F_100 ( V_114 ) ;
if ( ! V_67 )
V_67 = V_114 -> V_126 ;
F_63 ( V_114 ) ;
return V_67 ;
}
static int F_503 ( struct V_15 * V_16 , struct V_659 * V_660 )
{
struct V_113 * V_114 ;
struct V_285 * V_319 = V_660 -> V_676 -> V_203 -> V_258 ;
V_114 = F_502 ( V_16 , & V_660 -> V_677 , V_319 , false ) ;
F_413 ( V_16 , V_660 ) ;
if ( F_51 ( V_114 ) )
return F_62 ( V_114 ) ;
F_63 ( V_114 ) ;
return 0 ;
}
static bool F_504 ( const T_6 * V_896 ,
const T_6 * V_897 )
{
if ( memcmp ( V_896 -> V_898 , V_897 -> V_898 , sizeof( V_896 -> V_898 ) ) != 0 )
return false ;
if ( V_896 -> V_184 == V_897 -> V_184 )
return true ;
if ( V_896 -> V_184 == 0 || V_897 -> V_184 == 0 )
return true ;
return false ;
}
static bool F_505 ( const T_6 * V_896 ,
const T_6 * V_897 )
{
return F_116 ( V_896 , V_897 ) ;
}
