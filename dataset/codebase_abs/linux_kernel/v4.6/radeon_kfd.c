int F_1 ( void )
{
int V_1 ;
#if F_2 ( V_2 )
int (* F_3)( unsigned , const struct V_3 * * );
F_3 = F_4 ( V_4 ) ;
if ( F_3 == NULL )
return - V_5 ;
V_1 = F_3 ( V_6 , & V_7 ) ;
if ( V_1 ) {
F_5 ( V_4 ) ;
V_7 = NULL ;
}
#elif F_2 ( V_8 )
V_1 = V_4 ( V_6 , & V_7 ) ;
if ( V_1 )
V_7 = NULL ;
#else
V_1 = - V_5 ;
#endif
return V_1 ;
}
void F_6 ( void )
{
if ( V_7 ) {
V_7 -> exit () ;
F_5 ( V_4 ) ;
}
}
void F_7 ( struct V_9 * V_10 )
{
if ( V_7 )
V_10 -> V_11 = V_7 -> V_12 ( (struct V_13 * ) V_10 ,
V_10 -> V_14 , & V_15 ) ;
}
void F_8 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 ) {
struct V_16 V_17 = {
. V_18 = 0xFF00 ,
. V_19 = 1 ,
. V_20 = 4 - 1 ,
} ;
F_9 ( V_10 ,
& V_17 . V_21 ,
& V_17 . V_22 ,
& V_17 . V_23 ) ;
V_7 -> V_24 ( V_10 -> V_11 , & V_17 ) ;
}
}
void F_10 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 ) {
V_7 -> V_25 ( V_10 -> V_11 ) ;
V_10 -> V_11 = NULL ;
}
}
void F_11 ( struct V_9 * V_10 , const void * V_26 )
{
if ( V_10 -> V_11 )
V_7 -> V_27 ( V_10 -> V_11 , V_26 ) ;
}
void F_12 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 )
V_7 -> V_28 ( V_10 -> V_11 ) ;
}
int F_13 ( struct V_9 * V_10 )
{
int V_29 = 0 ;
if ( V_10 -> V_11 )
V_29 = V_7 -> V_30 ( V_10 -> V_11 ) ;
return V_29 ;
}
static int F_14 ( struct V_13 * V_31 , T_1 V_32 ,
void * * V_33 , T_2 * V_34 ,
void * * V_35 )
{
struct V_9 * V_10 = (struct V_9 * ) V_31 ;
struct V_36 * * V_37 = (struct V_36 * * ) V_33 ;
int V_29 ;
F_15 ( V_31 == NULL ) ;
F_15 ( V_34 == NULL ) ;
F_15 ( V_35 == NULL ) ;
* V_37 = F_16 ( sizeof( struct V_36 ) , V_38 ) ;
if ( ( * V_37 ) == NULL )
return - V_39 ;
V_29 = F_17 ( V_10 , V_32 , V_40 , true , V_41 ,
V_42 , NULL , NULL , & ( * V_37 ) -> V_43 ) ;
if ( V_29 ) {
F_18 ( V_10 -> V_44 ,
L_1 , V_29 ) ;
return V_29 ;
}
V_29 = F_19 ( ( * V_37 ) -> V_43 , true ) ;
if ( V_29 ) {
F_18 ( V_10 -> V_44 , L_2 , V_29 ) ;
goto V_45;
}
V_29 = F_20 ( ( * V_37 ) -> V_43 , V_41 ,
& ( * V_37 ) -> V_34 ) ;
if ( V_29 ) {
F_18 ( V_10 -> V_44 , L_3 , V_29 ) ;
goto V_46;
}
* V_34 = ( * V_37 ) -> V_34 ;
V_29 = F_21 ( ( * V_37 ) -> V_43 , & ( * V_37 ) -> V_35 ) ;
if ( V_29 ) {
F_18 ( V_10 -> V_44 ,
L_4 , V_29 ) ;
goto V_47;
}
* V_35 = ( * V_37 ) -> V_35 ;
F_22 ( ( * V_37 ) -> V_43 ) ;
return 0 ;
V_47:
F_23 ( ( * V_37 ) -> V_43 ) ;
V_46:
F_22 ( ( * V_37 ) -> V_43 ) ;
V_45:
F_24 ( & ( * V_37 ) -> V_43 ) ;
return V_29 ;
}
static void F_25 ( struct V_13 * V_31 , void * V_33 )
{
struct V_36 * V_37 = (struct V_36 * ) V_33 ;
F_15 ( V_37 == NULL ) ;
F_19 ( V_37 -> V_43 , true ) ;
F_26 ( V_37 -> V_43 ) ;
F_23 ( V_37 -> V_43 ) ;
F_22 ( V_37 -> V_43 ) ;
F_24 ( & ( V_37 -> V_43 ) ) ;
F_27 ( V_37 ) ;
}
static T_2 F_28 ( struct V_13 * V_31 )
{
struct V_9 * V_10 = (struct V_9 * ) V_31 ;
F_15 ( V_31 == NULL ) ;
return V_10 -> V_48 . V_49 ;
}
static T_2 F_29 ( struct V_13 * V_31 )
{
struct V_9 * V_10 = (struct V_9 * ) V_31 ;
return V_10 -> V_50 -> F_29 ( V_10 ) ;
}
static T_3 F_30 ( struct V_13 * V_31 )
{
struct V_9 * V_10 = (struct V_9 * ) V_31 ;
return V_10 -> V_51 . V_52 . V_53 . V_54 . V_55 / 100 ;
}
static inline struct V_9 * F_31 ( struct V_13 * V_31 )
{
return (struct V_9 * ) V_31 ;
}
static void F_32 ( struct V_13 * V_31 , T_3 V_56 , T_3 V_57 )
{
struct V_9 * V_10 = F_31 ( V_31 ) ;
F_33 ( V_57 , ( void V_58 * ) ( V_10 -> V_59 + V_56 ) ) ;
}
static T_3 F_34 ( struct V_13 * V_31 , T_3 V_56 )
{
struct V_9 * V_10 = F_31 ( V_31 ) ;
return F_35 ( ( void V_58 * ) ( V_10 -> V_59 + V_56 ) ) ;
}
static void F_36 ( struct V_13 * V_31 , T_3 V_60 , T_3 V_61 ,
T_3 V_62 , T_3 V_63 )
{
struct V_9 * V_10 = F_31 ( V_31 ) ;
T_3 V_57 = F_37 ( V_61 ) | F_38 ( V_60 ) | F_39 ( V_63 ) | F_40 ( V_62 ) ;
F_41 ( & V_10 -> V_64 ) ;
F_32 ( V_31 , V_65 , V_57 ) ;
}
static void F_42 ( struct V_13 * V_31 )
{
struct V_9 * V_10 = F_31 ( V_31 ) ;
F_32 ( V_31 , V_65 , 0 ) ;
F_43 ( & V_10 -> V_64 ) ;
}
static void F_44 ( struct V_13 * V_31 , T_3 V_66 ,
T_3 V_67 )
{
T_3 V_60 = ( ++ V_66 / V_68 ) + 1 ;
T_3 V_61 = ( V_66 % V_68 ) ;
F_36 ( V_31 , V_60 , V_61 , V_67 , 0 ) ;
}
static void F_45 ( struct V_13 * V_31 )
{
F_42 ( V_31 ) ;
}
static void F_46 ( struct V_13 * V_31 , T_3 V_63 ,
T_3 V_69 ,
T_3 V_70 ,
T_3 V_71 ,
T_3 V_72 )
{
F_36 ( V_31 , 0 , 0 , 0 , V_63 ) ;
F_32 ( V_31 , V_73 , V_69 ) ;
F_32 ( V_31 , V_74 , V_70 ) ;
F_32 ( V_31 , V_75 , V_71 ) ;
F_32 ( V_31 , V_76 , V_72 ) ;
F_42 ( V_31 ) ;
}
static int F_47 ( struct V_13 * V_31 , unsigned int V_77 ,
unsigned int V_63 )
{
T_3 V_78 = ( V_77 == 0 ) ? 0 : ( T_3 ) V_77 |
V_79 ;
F_32 ( V_31 , V_80 + V_63 * sizeof( T_3 ) ,
V_78 ) ;
while ( ! ( F_34 ( V_31 , V_81 ) &
( 1U << V_63 ) ) )
F_48 () ;
F_32 ( V_31 , V_81 , 1U << V_63 ) ;
F_32 ( V_31 , V_82 + V_63 * sizeof( T_3 ) ,
V_78 ) ;
return 0 ;
}
static int F_49 ( struct V_13 * V_31 , T_3 V_66 ,
T_3 V_83 , T_2 V_84 )
{
T_3 V_60 = ( V_66 / V_68 ) + 1 ;
T_3 V_61 = ( V_66 % V_68 ) ;
F_36 ( V_31 , V_60 , V_61 , 0 , 0 ) ;
F_32 ( V_31 , V_85 ,
F_50 ( V_84 >> 8 ) ) ;
F_32 ( V_31 , V_86 ,
F_51 ( V_84 >> 8 ) ) ;
F_32 ( V_31 , V_87 , 0 ) ;
F_32 ( V_31 , V_88 , V_83 ) ;
F_42 ( V_31 ) ;
return 0 ;
}
static int F_52 ( struct V_13 * V_31 , T_3 V_66 )
{
T_3 V_60 ;
T_3 V_61 ;
V_60 = ( V_66 / V_68 ) + 1 ;
V_61 = ( V_66 % V_68 ) ;
F_36 ( V_31 , V_60 , V_61 , 0 , 0 ) ;
F_32 ( V_31 , V_89 ,
V_90 | V_91 ) ;
F_42 ( V_31 ) ;
return 0 ;
}
static inline T_3 F_53 ( struct V_92 * V_93 )
{
T_3 V_94 ;
V_94 = V_93 -> V_95 * V_96 +
V_93 -> V_97 * V_98 ;
F_54 ( L_5 , V_94 ) ;
return V_94 ;
}
static inline struct V_99 * F_55 ( void * V_100 )
{
return (struct V_99 * ) V_100 ;
}
static inline struct V_92 * F_56 ( void * V_100 )
{
return (struct V_92 * ) V_100 ;
}
static int F_57 ( struct V_13 * V_31 , void * V_100 , T_3 V_66 ,
T_3 V_67 , T_3 T_4 * V_101 )
{
T_3 V_102 , V_103 ;
struct V_99 * V_93 ;
V_93 = F_55 ( V_100 ) ;
V_103 = ! F_58 ( V_102 , V_101 ) ;
F_44 ( V_31 , V_66 , V_67 ) ;
F_32 ( V_31 , V_104 , V_93 -> V_105 ) ;
F_32 ( V_31 , V_106 , V_93 -> V_107 ) ;
F_32 ( V_31 , V_108 , V_93 -> V_109 ) ;
F_32 ( V_31 , V_110 , V_93 -> V_111 ) ;
F_32 ( V_31 , V_112 , V_93 -> V_113 ) ;
F_32 ( V_31 , V_114 , V_93 -> V_115 ) ;
F_32 ( V_31 , V_116 , V_93 -> V_117 ) ;
F_32 ( V_31 , V_118 , V_93 -> V_119 ) ;
F_32 ( V_31 , V_120 , V_93 -> V_121 ) ;
F_32 ( V_31 , V_122 , V_93 -> V_123 ) ;
F_32 ( V_31 , V_124 ,
V_93 -> V_125 ) ;
F_32 ( V_31 , V_126 , V_93 -> V_127 ) ;
F_32 ( V_31 , V_128 , V_93 -> V_129 ) ;
F_32 ( V_31 , V_130 ,
V_93 -> V_131 ) ;
F_32 ( V_31 , V_132 ,
V_93 -> V_133 ) ;
F_32 ( V_31 , V_134 ,
V_93 -> V_135 ) ;
F_32 ( V_31 , V_136 ,
V_93 -> V_137 ) ;
F_32 ( V_31 , V_138 ,
V_93 -> V_139 ) ;
F_32 ( V_31 , V_140 ,
V_93 -> V_141 ) ;
F_32 ( V_31 , V_142 , V_93 -> V_143 ) ;
F_32 ( V_31 , V_144 ,
V_93 -> V_145 ) ;
F_32 ( V_31 , V_146 ,
V_93 -> V_147 ) ;
F_32 ( V_31 , V_148 ,
V_93 -> V_149 ) ;
F_32 ( V_31 , V_150 , V_93 -> V_151 ) ;
F_32 ( V_31 , V_152 , V_93 -> V_153 ) ;
F_32 ( V_31 , V_154 , V_93 -> V_155 ) ;
F_32 ( V_31 , V_156 , V_93 -> V_157 ) ;
F_32 ( V_31 , V_158 , V_93 -> V_159 ) ;
if ( V_103 )
F_32 ( V_31 , V_160 , V_102 ) ;
F_32 ( V_31 , V_161 , V_93 -> V_162 ) ;
F_45 ( V_31 ) ;
return 0 ;
}
static int F_59 ( struct V_13 * V_31 , void * V_100 )
{
struct V_92 * V_93 ;
T_3 V_163 ;
V_93 = F_56 ( V_100 ) ;
V_163 = F_53 ( V_93 ) ;
F_32 ( V_31 ,
V_163 + V_164 ,
V_93 -> V_165 ) ;
F_32 ( V_31 ,
V_163 + V_166 ,
V_93 -> V_167 ) ;
F_32 ( V_31 ,
V_163 + V_168 ,
V_93 -> V_169 ) ;
F_32 ( V_31 ,
V_163 + V_170 ,
V_93 -> V_171 ) ;
F_32 ( V_31 ,
V_163 + V_172 ,
V_93 -> V_173 ) ;
F_32 ( V_31 ,
V_163 + V_174 ,
V_93 -> V_175 ) ;
F_32 ( V_31 ,
V_163 + V_176 ,
V_93 -> V_177 ) ;
return 0 ;
}
static bool F_60 ( struct V_13 * V_31 , T_2 V_178 ,
T_3 V_66 , T_3 V_67 )
{
T_3 V_179 ;
bool V_94 = false ;
T_3 V_180 , V_181 ;
F_44 ( V_31 , V_66 , V_67 ) ;
V_179 = F_34 ( V_31 , V_161 ) ;
if ( V_179 ) {
V_180 = F_50 ( V_178 >> 8 ) ;
V_181 = F_51 ( V_178 >> 8 ) ;
if ( V_180 == F_34 ( V_31 , V_110 ) &&
V_181 == F_34 ( V_31 , V_112 ) )
V_94 = true ;
}
F_45 ( V_31 ) ;
return V_94 ;
}
static bool F_61 ( struct V_13 * V_31 , void * V_100 )
{
struct V_92 * V_93 ;
T_3 V_163 ;
T_3 V_177 ;
V_93 = F_56 ( V_100 ) ;
V_163 = F_53 ( V_93 ) ;
V_177 = F_34 ( V_31 ,
V_163 + V_176 ) ;
if ( V_177 & V_182 )
return true ;
return false ;
}
static int F_62 ( struct V_13 * V_31 , T_3 V_183 ,
unsigned int V_184 , T_3 V_66 ,
T_3 V_67 )
{
T_3 V_185 ;
F_44 ( V_31 , V_66 , V_67 ) ;
F_32 ( V_31 , V_148 , 0 ) ;
F_32 ( V_31 , V_186 , V_183 ) ;
while ( true ) {
V_185 = F_34 ( V_31 , V_161 ) ;
if ( V_185 & 0x1 )
break;
if ( V_184 == 0 ) {
F_63 ( L_6 ,
V_185 ) ;
F_45 ( V_31 ) ;
return - V_187 ;
}
F_64 ( 20 ) ;
V_184 -= 20 ;
}
F_45 ( V_31 ) ;
return 0 ;
}
static int F_65 ( struct V_13 * V_31 , void * V_100 ,
unsigned int V_184 )
{
struct V_92 * V_93 ;
T_3 V_163 ;
T_3 V_185 ;
V_93 = F_56 ( V_100 ) ;
V_163 = F_53 ( V_93 ) ;
V_185 = F_34 ( V_31 , V_163 + V_176 ) ;
V_185 = V_185 & ~ V_182 ;
F_32 ( V_31 , V_163 + V_176 , V_185 ) ;
while ( true ) {
V_185 = F_34 ( V_31 , V_163 +
V_188 ) ;
if ( V_185 & V_189 )
break;
if ( V_184 == 0 )
return - V_187 ;
F_64 ( 20 ) ;
V_184 -= 20 ;
}
F_32 ( V_31 , V_163 + V_174 , 0 ) ;
F_32 ( V_31 , V_163 + V_190 , 0 ) ;
F_32 ( V_31 , V_163 + V_191 , 0 ) ;
F_32 ( V_31 , V_163 + V_166 , 0 ) ;
return 0 ;
}
static int F_66 ( struct V_13 * V_31 )
{
union V_192 V_193 ;
unsigned int V_194 ;
V_193 . V_195 = 0 ;
V_193 . V_196 . V_197 = 0 ;
V_193 . V_196 . V_198 = V_199 ;
V_193 . V_196 . V_200 = 1 ;
for ( V_194 = 0 ; V_194 < V_201 ; V_194 ++ )
F_32 ( V_31 ,
V_202 [ V_194 * V_203 +
V_204 ] ,
V_193 . V_195 ) ;
return 0 ;
}
static int F_67 ( struct V_13 * V_31 ,
unsigned int V_205 ,
T_3 V_206 ,
T_3 V_207 ,
T_3 V_208 )
{
union V_192 V_193 ;
V_193 . V_195 = V_206 ;
V_193 . V_196 . V_197 = 0 ;
F_32 ( V_31 ,
V_202 [ V_205 * V_203 +
V_204 ] ,
V_193 . V_195 ) ;
F_32 ( V_31 ,
V_202 [ V_205 * V_203 +
V_209 ] ,
V_207 ) ;
F_32 ( V_31 ,
V_202 [ V_205 * V_203 +
V_210 ] ,
V_208 ) ;
V_193 . V_196 . V_197 = 1 ;
F_32 ( V_31 ,
V_202 [ V_205 * V_203 +
V_204 ] ,
V_193 . V_195 ) ;
return 0 ;
}
static int F_68 ( struct V_13 * V_31 ,
T_3 V_211 ,
T_3 V_212 )
{
struct V_9 * V_10 = F_31 ( V_31 ) ;
T_3 V_213 ;
F_41 ( & V_10 -> V_214 ) ;
F_32 ( V_31 , V_215 , V_211 ) ;
F_32 ( V_31 , V_216 , V_212 ) ;
V_213 = V_217 | V_218 |
V_219 ;
F_32 ( V_31 , V_215 , V_213 ) ;
F_43 ( & V_10 -> V_214 ) ;
return 0 ;
}
static T_3 F_69 ( struct V_13 * V_31 ,
unsigned int V_205 ,
unsigned int V_220 )
{
return V_202 [ V_205 * V_203 + V_220 ] ;
}
static bool F_70 ( struct V_13 * V_31 , T_5 V_63 )
{
T_3 V_221 ;
struct V_9 * V_10 = (struct V_9 * ) V_31 ;
V_221 = F_71 ( V_80 + V_63 * 4 ) ;
return V_221 & V_79 ;
}
static T_6 F_72 ( struct V_13 * V_31 ,
T_5 V_63 )
{
T_3 V_221 ;
struct V_9 * V_10 = (struct V_9 * ) V_31 ;
V_221 = F_71 ( V_80 + V_63 * 4 ) ;
return V_221 & V_222 ;
}
static void F_73 ( struct V_13 * V_31 , T_5 V_63 )
{
struct V_9 * V_10 = (struct V_9 * ) V_31 ;
return F_74 ( V_223 , 1 << V_63 ) ;
}
static T_6 F_75 ( struct V_13 * V_31 , enum V_224 type )
{
struct V_9 * V_10 = (struct V_9 * ) V_31 ;
const union V_225 * V_226 ;
F_15 ( V_31 == NULL || V_10 -> V_227 == NULL ) ;
switch ( type ) {
case V_228 :
V_226 = ( const union V_225 * ) V_10 -> V_229 -> V_213 ;
break;
case V_230 :
V_226 = ( const union V_225 * ) V_10 -> V_231 -> V_213 ;
break;
case V_232 :
V_226 = ( const union V_225 * ) V_10 -> V_233 -> V_213 ;
break;
case V_234 :
V_226 = ( const union V_225 * ) V_10 -> V_227 -> V_213 ;
break;
case V_235 :
V_226 = ( const union V_225 * )
V_10 -> V_236 -> V_213 ;
break;
case V_237 :
V_226 = ( const union V_225 * ) V_10 -> V_238 -> V_213 ;
break;
case V_239 :
case V_240 :
V_226 = ( const union V_225 * )
V_10 -> V_241 -> V_213 ;
break;
default:
return 0 ;
}
if ( V_226 == NULL )
return 0 ;
return V_226 -> V_242 . V_243 ;
}
