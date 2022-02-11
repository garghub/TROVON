bool F_1 ( void )
{
#if F_2 ( V_1 )
bool (* F_3)( unsigned , const struct V_2 * * );
F_3 = F_4 ( V_3 ) ;
if ( F_3 == NULL )
return false ;
if ( ! F_3 ( V_4 , & V_5 ) ) {
F_5 ( V_3 ) ;
V_5 = NULL ;
return false ;
}
return true ;
#elif F_2 ( V_6 )
if ( ! V_3 ( V_4 , & V_5 ) ) {
V_5 = NULL ;
return false ;
}
return true ;
#else
return false ;
#endif
}
void F_6 ( void )
{
if ( V_5 ) {
V_5 -> exit () ;
F_5 ( V_3 ) ;
}
}
void F_7 ( struct V_7 * V_8 )
{
if ( V_5 )
V_8 -> V_9 = V_5 -> V_10 ( (struct V_11 * ) V_8 ,
V_8 -> V_12 , & V_13 ) ;
}
void F_8 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 ) {
struct V_14 V_15 = {
. V_16 = 0xFF00 ,
. V_17 = 1 ,
. V_18 = 4 - 1 ,
} ;
F_9 ( V_8 ,
& V_15 . V_19 ,
& V_15 . V_20 ,
& V_15 . V_21 ) ;
V_5 -> V_22 ( V_8 -> V_9 , & V_15 ) ;
}
}
void F_10 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 ) {
V_5 -> V_23 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
}
}
void F_11 ( struct V_7 * V_8 , const void * V_24 )
{
if ( V_8 -> V_9 )
V_5 -> V_25 ( V_8 -> V_9 , V_24 ) ;
}
void F_12 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 )
V_5 -> V_26 ( V_8 -> V_9 ) ;
}
int F_13 ( struct V_7 * V_8 )
{
int V_27 = 0 ;
if ( V_8 -> V_9 )
V_27 = V_5 -> V_28 ( V_8 -> V_9 ) ;
return V_27 ;
}
static int F_14 ( struct V_11 * V_29 , T_1 V_30 ,
void * * V_31 , T_2 * V_32 ,
void * * V_33 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
struct V_34 * * V_35 = (struct V_34 * * ) V_31 ;
int V_27 ;
F_15 ( V_29 == NULL ) ;
F_15 ( V_32 == NULL ) ;
F_15 ( V_33 == NULL ) ;
* V_35 = F_16 ( sizeof( struct V_34 ) , V_36 ) ;
if ( ( * V_35 ) == NULL )
return - V_37 ;
V_27 = F_17 ( V_8 , V_30 , V_38 , true , V_39 ,
V_40 , NULL , NULL , & ( * V_35 ) -> V_41 ) ;
if ( V_27 ) {
F_18 ( V_8 -> V_42 ,
L_1 , V_27 ) ;
return V_27 ;
}
V_27 = F_19 ( ( * V_35 ) -> V_41 , true ) ;
if ( V_27 ) {
F_18 ( V_8 -> V_42 , L_2 , V_27 ) ;
goto V_43;
}
V_27 = F_20 ( ( * V_35 ) -> V_41 , V_39 ,
& ( * V_35 ) -> V_32 ) ;
if ( V_27 ) {
F_18 ( V_8 -> V_42 , L_3 , V_27 ) ;
goto V_44;
}
* V_32 = ( * V_35 ) -> V_32 ;
V_27 = F_21 ( ( * V_35 ) -> V_41 , & ( * V_35 ) -> V_33 ) ;
if ( V_27 ) {
F_18 ( V_8 -> V_42 ,
L_4 , V_27 ) ;
goto V_45;
}
* V_33 = ( * V_35 ) -> V_33 ;
F_22 ( ( * V_35 ) -> V_41 ) ;
return 0 ;
V_45:
F_23 ( ( * V_35 ) -> V_41 ) ;
V_44:
F_22 ( ( * V_35 ) -> V_41 ) ;
V_43:
F_24 ( & ( * V_35 ) -> V_41 ) ;
return V_27 ;
}
static void F_25 ( struct V_11 * V_29 , void * V_31 )
{
struct V_34 * V_35 = (struct V_34 * ) V_31 ;
F_15 ( V_35 == NULL ) ;
F_19 ( V_35 -> V_41 , true ) ;
F_26 ( V_35 -> V_41 ) ;
F_23 ( V_35 -> V_41 ) ;
F_22 ( V_35 -> V_41 ) ;
F_24 ( & ( V_35 -> V_41 ) ) ;
F_27 ( V_35 ) ;
}
static T_2 F_28 ( struct V_11 * V_29 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
F_15 ( V_29 == NULL ) ;
return V_8 -> V_46 . V_47 ;
}
static T_2 F_29 ( struct V_11 * V_29 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
return V_8 -> V_48 -> F_29 ( V_8 ) ;
}
static T_3 F_30 ( struct V_11 * V_29 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
return V_8 -> V_49 . V_50 . V_51 . V_52 . V_53 / 100 ;
}
static inline struct V_7 * F_31 ( struct V_11 * V_29 )
{
return (struct V_7 * ) V_29 ;
}
static void F_32 ( struct V_11 * V_29 , T_3 V_54 , T_3 V_55 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
F_33 ( V_55 , ( void V_56 * ) ( V_8 -> V_57 + V_54 ) ) ;
}
static T_3 F_34 ( struct V_11 * V_29 , T_3 V_54 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
return F_35 ( ( void V_56 * ) ( V_8 -> V_57 + V_54 ) ) ;
}
static void F_36 ( struct V_11 * V_29 , T_3 V_58 , T_3 V_59 ,
T_3 V_60 , T_3 V_61 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
T_3 V_55 = F_37 ( V_59 ) | F_38 ( V_58 ) | F_39 ( V_61 ) | F_40 ( V_60 ) ;
F_41 ( & V_8 -> V_62 ) ;
F_32 ( V_29 , V_63 , V_55 ) ;
}
static void F_42 ( struct V_11 * V_29 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
F_32 ( V_29 , V_63 , 0 ) ;
F_43 ( & V_8 -> V_62 ) ;
}
static void F_44 ( struct V_11 * V_29 , T_3 V_64 ,
T_3 V_65 )
{
T_3 V_58 = ( ++ V_64 / V_66 ) + 1 ;
T_3 V_59 = ( V_64 % V_66 ) ;
F_36 ( V_29 , V_58 , V_59 , V_65 , 0 ) ;
}
static void F_45 ( struct V_11 * V_29 )
{
F_42 ( V_29 ) ;
}
static void F_46 ( struct V_11 * V_29 , T_3 V_61 ,
T_3 V_67 ,
T_3 V_68 ,
T_3 V_69 ,
T_3 V_70 )
{
F_36 ( V_29 , 0 , 0 , 0 , V_61 ) ;
F_32 ( V_29 , V_71 , V_67 ) ;
F_32 ( V_29 , V_72 , V_68 ) ;
F_32 ( V_29 , V_73 , V_69 ) ;
F_32 ( V_29 , V_74 , V_70 ) ;
F_42 ( V_29 ) ;
}
static int F_47 ( struct V_11 * V_29 , unsigned int V_75 ,
unsigned int V_61 )
{
T_3 V_76 = ( V_75 == 0 ) ? 0 : ( T_3 ) V_75 |
V_77 ;
F_32 ( V_29 , V_78 + V_61 * sizeof( T_3 ) ,
V_76 ) ;
while ( ! ( F_34 ( V_29 , V_79 ) &
( 1U << V_61 ) ) )
F_48 () ;
F_32 ( V_29 , V_79 , 1U << V_61 ) ;
F_32 ( V_29 , V_80 + V_61 * sizeof( T_3 ) ,
V_76 ) ;
return 0 ;
}
static int F_49 ( struct V_11 * V_29 , T_3 V_64 ,
T_3 V_81 , T_2 V_82 )
{
T_3 V_58 = ( V_64 / V_66 ) + 1 ;
T_3 V_59 = ( V_64 % V_66 ) ;
F_36 ( V_29 , V_58 , V_59 , 0 , 0 ) ;
F_32 ( V_29 , V_83 ,
F_50 ( V_82 >> 8 ) ) ;
F_32 ( V_29 , V_84 ,
F_51 ( V_82 >> 8 ) ) ;
F_32 ( V_29 , V_85 , 0 ) ;
F_32 ( V_29 , V_86 , V_81 ) ;
F_42 ( V_29 ) ;
return 0 ;
}
static int F_52 ( struct V_11 * V_29 , T_3 V_64 )
{
T_3 V_58 ;
T_3 V_59 ;
V_58 = ( V_64 / V_66 ) + 1 ;
V_59 = ( V_64 % V_66 ) ;
F_36 ( V_29 , V_58 , V_59 , 0 , 0 ) ;
F_32 ( V_29 , V_87 ,
V_88 | V_89 ) ;
F_42 ( V_29 ) ;
return 0 ;
}
static inline T_3 F_53 ( struct V_90 * V_91 )
{
T_3 V_92 ;
V_92 = V_91 -> V_93 * V_94 +
V_91 -> V_95 * V_96 ;
F_54 ( L_5 , V_92 ) ;
return V_92 ;
}
static inline struct V_97 * F_55 ( void * V_98 )
{
return (struct V_97 * ) V_98 ;
}
static inline struct V_90 * F_56 ( void * V_98 )
{
return (struct V_90 * ) V_98 ;
}
static int F_57 ( struct V_11 * V_29 , void * V_98 , T_3 V_64 ,
T_3 V_65 , T_3 T_4 * V_99 )
{
T_3 V_100 , V_101 ;
struct V_97 * V_91 ;
V_91 = F_55 ( V_98 ) ;
V_101 = ! F_58 ( V_100 , V_99 ) ;
F_44 ( V_29 , V_64 , V_65 ) ;
F_32 ( V_29 , V_102 , V_91 -> V_103 ) ;
F_32 ( V_29 , V_104 , V_91 -> V_105 ) ;
F_32 ( V_29 , V_106 , V_91 -> V_107 ) ;
F_32 ( V_29 , V_108 , V_91 -> V_109 ) ;
F_32 ( V_29 , V_110 , V_91 -> V_111 ) ;
F_32 ( V_29 , V_112 , V_91 -> V_113 ) ;
F_32 ( V_29 , V_114 , V_91 -> V_115 ) ;
F_32 ( V_29 , V_116 , V_91 -> V_117 ) ;
F_32 ( V_29 , V_118 , V_91 -> V_119 ) ;
F_32 ( V_29 , V_120 , V_91 -> V_121 ) ;
F_32 ( V_29 , V_122 ,
V_91 -> V_123 ) ;
F_32 ( V_29 , V_124 , V_91 -> V_125 ) ;
F_32 ( V_29 , V_126 , V_91 -> V_127 ) ;
F_32 ( V_29 , V_128 ,
V_91 -> V_129 ) ;
F_32 ( V_29 , V_130 ,
V_91 -> V_131 ) ;
F_32 ( V_29 , V_132 ,
V_91 -> V_133 ) ;
F_32 ( V_29 , V_134 ,
V_91 -> V_135 ) ;
F_32 ( V_29 , V_136 ,
V_91 -> V_137 ) ;
F_32 ( V_29 , V_138 ,
V_91 -> V_139 ) ;
F_32 ( V_29 , V_140 , V_91 -> V_141 ) ;
F_32 ( V_29 , V_142 ,
V_91 -> V_143 ) ;
F_32 ( V_29 , V_144 ,
V_91 -> V_145 ) ;
F_32 ( V_29 , V_146 ,
V_91 -> V_147 ) ;
F_32 ( V_29 , V_148 , V_91 -> V_149 ) ;
F_32 ( V_29 , V_150 , V_91 -> V_151 ) ;
F_32 ( V_29 , V_152 , V_91 -> V_153 ) ;
F_32 ( V_29 , V_154 , V_91 -> V_155 ) ;
F_32 ( V_29 , V_156 , V_91 -> V_157 ) ;
if ( V_101 )
F_32 ( V_29 , V_158 , V_100 ) ;
F_32 ( V_29 , V_159 , V_91 -> V_160 ) ;
F_45 ( V_29 ) ;
return 0 ;
}
static int F_59 ( struct V_11 * V_29 , void * V_98 )
{
struct V_90 * V_91 ;
T_3 V_161 ;
V_91 = F_56 ( V_98 ) ;
V_161 = F_53 ( V_91 ) ;
F_32 ( V_29 ,
V_161 + V_162 ,
V_91 -> V_163 ) ;
F_32 ( V_29 ,
V_161 + V_164 ,
V_91 -> V_165 ) ;
F_32 ( V_29 ,
V_161 + V_166 ,
V_91 -> V_167 ) ;
F_32 ( V_29 ,
V_161 + V_168 ,
V_91 -> V_169 ) ;
F_32 ( V_29 ,
V_161 + V_170 ,
V_91 -> V_171 ) ;
F_32 ( V_29 ,
V_161 + V_172 ,
V_91 -> V_173 ) ;
F_32 ( V_29 ,
V_161 + V_174 ,
V_91 -> V_175 ) ;
return 0 ;
}
static bool F_60 ( struct V_11 * V_29 , T_2 V_176 ,
T_3 V_64 , T_3 V_65 )
{
T_3 V_177 ;
bool V_92 = false ;
T_3 V_178 , V_179 ;
F_44 ( V_29 , V_64 , V_65 ) ;
V_177 = F_34 ( V_29 , V_159 ) ;
if ( V_177 ) {
V_178 = F_50 ( V_176 >> 8 ) ;
V_179 = F_51 ( V_176 >> 8 ) ;
if ( V_178 == F_34 ( V_29 , V_108 ) &&
V_179 == F_34 ( V_29 , V_110 ) )
V_92 = true ;
}
F_45 ( V_29 ) ;
return V_92 ;
}
static bool F_61 ( struct V_11 * V_29 , void * V_98 )
{
struct V_90 * V_91 ;
T_3 V_161 ;
T_3 V_175 ;
V_91 = F_56 ( V_98 ) ;
V_161 = F_53 ( V_91 ) ;
V_175 = F_34 ( V_29 ,
V_161 + V_174 ) ;
if ( V_175 & V_180 )
return true ;
return false ;
}
static int F_62 ( struct V_11 * V_29 , T_3 V_181 ,
unsigned int V_182 , T_3 V_64 ,
T_3 V_65 )
{
T_3 V_183 ;
F_44 ( V_29 , V_64 , V_65 ) ;
F_32 ( V_29 , V_146 , 0 ) ;
F_32 ( V_29 , V_184 , V_181 ) ;
while ( true ) {
V_183 = F_34 ( V_29 , V_159 ) ;
if ( V_183 & 0x1 )
break;
if ( V_182 == 0 ) {
F_63 ( L_6 ,
V_183 ) ;
F_45 ( V_29 ) ;
return - V_185 ;
}
F_64 ( 20 ) ;
V_182 -= 20 ;
}
F_45 ( V_29 ) ;
return 0 ;
}
static int F_65 ( struct V_11 * V_29 , void * V_98 ,
unsigned int V_182 )
{
struct V_90 * V_91 ;
T_3 V_161 ;
T_3 V_183 ;
V_91 = F_56 ( V_98 ) ;
V_161 = F_53 ( V_91 ) ;
V_183 = F_34 ( V_29 , V_161 + V_174 ) ;
V_183 = V_183 & ~ V_180 ;
F_32 ( V_29 , V_161 + V_174 , V_183 ) ;
while ( true ) {
V_183 = F_34 ( V_29 , V_161 +
V_186 ) ;
if ( V_183 & V_187 )
break;
if ( V_182 == 0 )
return - V_185 ;
F_64 ( 20 ) ;
V_182 -= 20 ;
}
F_32 ( V_29 , V_161 + V_172 , 0 ) ;
F_32 ( V_29 , V_161 + V_188 , 0 ) ;
F_32 ( V_29 , V_161 + V_189 , 0 ) ;
F_32 ( V_29 , V_161 + V_164 , 0 ) ;
return 0 ;
}
static int F_66 ( struct V_11 * V_29 )
{
union V_190 V_191 ;
unsigned int V_192 ;
V_191 . V_193 = 0 ;
V_191 . V_194 . V_195 = 0 ;
V_191 . V_194 . V_196 = V_197 ;
V_191 . V_194 . V_198 = 1 ;
for ( V_192 = 0 ; V_192 < V_199 ; V_192 ++ )
F_32 ( V_29 ,
V_200 [ V_192 * V_201 +
V_202 ] ,
V_191 . V_193 ) ;
return 0 ;
}
static int F_67 ( struct V_11 * V_29 ,
unsigned int V_203 ,
T_3 V_204 ,
T_3 V_205 ,
T_3 V_206 )
{
union V_190 V_191 ;
V_191 . V_193 = V_204 ;
V_191 . V_194 . V_195 = 0 ;
F_32 ( V_29 ,
V_200 [ V_203 * V_201 +
V_202 ] ,
V_191 . V_193 ) ;
F_32 ( V_29 ,
V_200 [ V_203 * V_201 +
V_207 ] ,
V_205 ) ;
F_32 ( V_29 ,
V_200 [ V_203 * V_201 +
V_208 ] ,
V_206 ) ;
V_191 . V_194 . V_195 = 1 ;
F_32 ( V_29 ,
V_200 [ V_203 * V_201 +
V_202 ] ,
V_191 . V_193 ) ;
return 0 ;
}
static int F_68 ( struct V_11 * V_29 ,
T_3 V_209 ,
T_3 V_210 )
{
struct V_7 * V_8 = F_31 ( V_29 ) ;
T_3 V_211 ;
F_41 ( & V_8 -> V_212 ) ;
F_32 ( V_29 , V_213 , V_209 ) ;
F_32 ( V_29 , V_214 , V_210 ) ;
V_211 = V_215 | V_216 |
V_217 ;
F_32 ( V_29 , V_213 , V_211 ) ;
F_43 ( & V_8 -> V_212 ) ;
return 0 ;
}
static T_3 F_69 ( struct V_11 * V_29 ,
unsigned int V_203 ,
unsigned int V_218 )
{
return V_200 [ V_203 * V_201 + V_218 ] ;
}
static bool F_70 ( struct V_11 * V_29 , T_5 V_61 )
{
T_3 V_219 ;
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
V_219 = F_71 ( V_78 + V_61 * 4 ) ;
return V_219 & V_77 ;
}
static T_6 F_72 ( struct V_11 * V_29 ,
T_5 V_61 )
{
T_3 V_219 ;
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
V_219 = F_71 ( V_78 + V_61 * 4 ) ;
return V_219 & V_220 ;
}
static void F_73 ( struct V_11 * V_29 , T_5 V_61 )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
return F_74 ( V_221 , 1 << V_61 ) ;
}
static T_6 F_75 ( struct V_11 * V_29 , enum V_222 type )
{
struct V_7 * V_8 = (struct V_7 * ) V_29 ;
const union V_223 * V_224 ;
F_15 ( V_29 == NULL || V_8 -> V_225 == NULL ) ;
switch ( type ) {
case V_226 :
V_224 = ( const union V_223 * ) V_8 -> V_227 -> V_211 ;
break;
case V_228 :
V_224 = ( const union V_223 * ) V_8 -> V_229 -> V_211 ;
break;
case V_230 :
V_224 = ( const union V_223 * ) V_8 -> V_231 -> V_211 ;
break;
case V_232 :
V_224 = ( const union V_223 * ) V_8 -> V_225 -> V_211 ;
break;
case V_233 :
V_224 = ( const union V_223 * )
V_8 -> V_234 -> V_211 ;
break;
case V_235 :
V_224 = ( const union V_223 * ) V_8 -> V_236 -> V_211 ;
break;
case V_237 :
case V_238 :
V_224 = ( const union V_223 * )
V_8 -> V_239 -> V_211 ;
break;
default:
return 0 ;
}
if ( V_224 == NULL )
return 0 ;
return V_224 -> V_240 . V_241 ;
}
