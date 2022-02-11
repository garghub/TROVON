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
int V_16 , V_17 , V_18 , V_19 ;
if ( V_10 -> V_11 ) {
struct V_20 V_21 = {
. V_22 = 0xFF00 ,
. V_23 = 4 ,
. V_24 = 8
} ;
F_9 ( V_21 . V_25 , V_26 ) ;
for ( V_16 = 0 ; V_16 < V_26 ; ++ V_16 ) {
V_17 = V_16 % V_21 . V_24 ;
V_18 = ( V_16 / V_21 . V_24 )
% V_21 . V_23 ;
V_19 = ( V_16 / V_21 . V_24 )
/ V_21 . V_23 ;
if ( V_19 == 0 && V_18 > 0 )
F_10 ( V_16 , V_21 . V_25 ) ;
}
F_11 ( V_10 ,
& V_21 . V_27 ,
& V_21 . V_28 ,
& V_21 . V_29 ) ;
V_7 -> V_30 ( V_10 -> V_11 , & V_21 ) ;
}
}
void F_12 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 ) {
V_7 -> V_31 ( V_10 -> V_11 ) ;
V_10 -> V_11 = NULL ;
}
}
void F_13 ( struct V_9 * V_10 , const void * V_32 )
{
if ( V_10 -> V_11 )
V_7 -> V_33 ( V_10 -> V_11 , V_32 ) ;
}
void F_14 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 )
V_7 -> V_34 ( V_10 -> V_11 ) ;
}
int F_15 ( struct V_9 * V_10 )
{
int V_35 = 0 ;
if ( V_10 -> V_11 )
V_35 = V_7 -> V_36 ( V_10 -> V_11 ) ;
return V_35 ;
}
static int F_16 ( struct V_13 * V_37 , T_1 V_38 ,
void * * V_39 , T_2 * V_40 ,
void * * V_41 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
struct V_42 * * V_43 = (struct V_42 * * ) V_39 ;
int V_35 ;
F_17 ( V_37 == NULL ) ;
F_17 ( V_40 == NULL ) ;
F_17 ( V_41 == NULL ) ;
* V_43 = F_18 ( sizeof( struct V_42 ) , V_44 ) ;
if ( ( * V_43 ) == NULL )
return - V_45 ;
V_35 = F_19 ( V_10 , V_38 , V_46 , true , V_47 ,
V_48 , NULL , NULL , & ( * V_43 ) -> V_49 ) ;
if ( V_35 ) {
F_20 ( V_10 -> V_50 ,
L_1 , V_35 ) ;
return V_35 ;
}
V_35 = F_21 ( ( * V_43 ) -> V_49 , true ) ;
if ( V_35 ) {
F_20 ( V_10 -> V_50 , L_2 , V_35 ) ;
goto V_51;
}
V_35 = F_22 ( ( * V_43 ) -> V_49 , V_47 ,
& ( * V_43 ) -> V_40 ) ;
if ( V_35 ) {
F_20 ( V_10 -> V_50 , L_3 , V_35 ) ;
goto V_52;
}
* V_40 = ( * V_43 ) -> V_40 ;
V_35 = F_23 ( ( * V_43 ) -> V_49 , & ( * V_43 ) -> V_41 ) ;
if ( V_35 ) {
F_20 ( V_10 -> V_50 ,
L_4 , V_35 ) ;
goto V_53;
}
* V_41 = ( * V_43 ) -> V_41 ;
F_24 ( ( * V_43 ) -> V_49 ) ;
return 0 ;
V_53:
F_25 ( ( * V_43 ) -> V_49 ) ;
V_52:
F_24 ( ( * V_43 ) -> V_49 ) ;
V_51:
F_26 ( & ( * V_43 ) -> V_49 ) ;
return V_35 ;
}
static void F_27 ( struct V_13 * V_37 , void * V_39 )
{
struct V_42 * V_43 = (struct V_42 * ) V_39 ;
F_17 ( V_43 == NULL ) ;
F_21 ( V_43 -> V_49 , true ) ;
F_28 ( V_43 -> V_49 ) ;
F_25 ( V_43 -> V_49 ) ;
F_24 ( V_43 -> V_49 ) ;
F_26 ( & ( V_43 -> V_49 ) ) ;
F_29 ( V_43 ) ;
}
static T_2 F_30 ( struct V_13 * V_37 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
F_17 ( V_37 == NULL ) ;
return V_10 -> V_54 . V_55 ;
}
static T_2 F_31 ( struct V_13 * V_37 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
return V_10 -> V_56 -> F_31 ( V_10 ) ;
}
static T_3 F_32 ( struct V_13 * V_37 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
return V_10 -> V_57 . V_58 . V_59 . V_60 . V_61 / 100 ;
}
static inline struct V_9 * F_33 ( struct V_13 * V_37 )
{
return (struct V_9 * ) V_37 ;
}
static void F_34 ( struct V_13 * V_37 , T_3 V_62 , T_3 V_63 )
{
struct V_9 * V_10 = F_33 ( V_37 ) ;
F_35 ( V_63 , ( void V_64 * ) ( V_10 -> V_65 + V_62 ) ) ;
}
static T_3 F_36 ( struct V_13 * V_37 , T_3 V_62 )
{
struct V_9 * V_10 = F_33 ( V_37 ) ;
return F_37 ( ( void V_64 * ) ( V_10 -> V_65 + V_62 ) ) ;
}
static void F_38 ( struct V_13 * V_37 , T_3 V_19 , T_3 V_18 ,
T_3 V_17 , T_3 V_66 )
{
struct V_9 * V_10 = F_33 ( V_37 ) ;
T_3 V_63 = F_39 ( V_18 ) | F_40 ( V_19 ) | F_41 ( V_66 ) | F_42 ( V_17 ) ;
F_43 ( & V_10 -> V_67 ) ;
F_34 ( V_37 , V_68 , V_63 ) ;
}
static void F_44 ( struct V_13 * V_37 )
{
struct V_9 * V_10 = F_33 ( V_37 ) ;
F_34 ( V_37 , V_68 , 0 ) ;
F_45 ( & V_10 -> V_67 ) ;
}
static void F_46 ( struct V_13 * V_37 , T_3 V_69 ,
T_3 V_70 )
{
T_3 V_19 = ( ++ V_69 / V_71 ) + 1 ;
T_3 V_18 = ( V_69 % V_71 ) ;
F_38 ( V_37 , V_19 , V_18 , V_70 , 0 ) ;
}
static void F_47 ( struct V_13 * V_37 )
{
F_44 ( V_37 ) ;
}
static void F_48 ( struct V_13 * V_37 , T_3 V_66 ,
T_3 V_72 ,
T_3 V_73 ,
T_3 V_74 ,
T_3 V_75 )
{
F_38 ( V_37 , 0 , 0 , 0 , V_66 ) ;
F_34 ( V_37 , V_76 , V_72 ) ;
F_34 ( V_37 , V_77 , V_73 ) ;
F_34 ( V_37 , V_78 , V_74 ) ;
F_34 ( V_37 , V_79 , V_75 ) ;
F_44 ( V_37 ) ;
}
static int F_49 ( struct V_13 * V_37 , unsigned int V_80 ,
unsigned int V_66 )
{
T_3 V_81 = ( V_80 == 0 ) ? 0 : ( T_3 ) V_80 |
V_82 ;
F_34 ( V_37 , V_83 + V_66 * sizeof( T_3 ) ,
V_81 ) ;
while ( ! ( F_36 ( V_37 , V_84 ) &
( 1U << V_66 ) ) )
F_50 () ;
F_34 ( V_37 , V_84 , 1U << V_66 ) ;
F_34 ( V_37 , V_85 + V_66 * sizeof( T_3 ) ,
V_81 ) ;
return 0 ;
}
static int F_51 ( struct V_13 * V_37 , T_3 V_69 ,
T_3 V_86 , T_2 V_87 )
{
return 0 ;
}
static int F_52 ( struct V_13 * V_37 , T_3 V_69 )
{
T_3 V_19 ;
T_3 V_18 ;
V_19 = ( V_69 / V_71 ) + 1 ;
V_18 = ( V_69 % V_71 ) ;
F_38 ( V_37 , V_19 , V_18 , 0 , 0 ) ;
F_34 ( V_37 , V_88 ,
V_89 | V_90 ) ;
F_44 ( V_37 ) ;
return 0 ;
}
static inline T_3 F_53 ( struct V_91 * V_92 )
{
T_3 V_93 ;
V_93 = V_92 -> V_94 * V_95 +
V_92 -> V_96 * V_97 ;
F_54 ( L_5 , V_93 ) ;
return V_93 ;
}
static inline struct V_98 * F_55 ( void * V_99 )
{
return (struct V_98 * ) V_99 ;
}
static inline struct V_91 * F_56 ( void * V_99 )
{
return (struct V_91 * ) V_99 ;
}
static int F_57 ( struct V_13 * V_37 , void * V_99 , T_3 V_69 ,
T_3 V_70 , T_3 T_4 * V_100 )
{
T_3 V_101 , V_102 ;
struct V_98 * V_92 ;
V_92 = F_55 ( V_99 ) ;
V_102 = ! F_58 ( V_101 , V_100 ) ;
F_46 ( V_37 , V_69 , V_70 ) ;
F_34 ( V_37 , V_103 , V_92 -> V_104 ) ;
F_34 ( V_37 , V_105 , V_92 -> V_106 ) ;
F_34 ( V_37 , V_107 , V_92 -> V_108 ) ;
F_34 ( V_37 , V_109 , V_92 -> V_110 ) ;
F_34 ( V_37 , V_111 , V_92 -> V_112 ) ;
F_34 ( V_37 , V_113 , V_92 -> V_114 ) ;
F_34 ( V_37 , V_115 , V_92 -> V_116 ) ;
F_34 ( V_37 , V_117 , V_92 -> V_118 ) ;
F_34 ( V_37 , V_119 , V_92 -> V_120 ) ;
F_34 ( V_37 , V_121 , V_92 -> V_122 ) ;
F_34 ( V_37 , V_123 ,
V_92 -> V_124 ) ;
F_34 ( V_37 , V_125 , V_92 -> V_126 ) ;
F_34 ( V_37 , V_127 , V_92 -> V_128 ) ;
F_34 ( V_37 , V_129 ,
V_92 -> V_130 ) ;
F_34 ( V_37 , V_131 ,
V_92 -> V_132 ) ;
F_34 ( V_37 , V_133 ,
V_92 -> V_134 ) ;
F_34 ( V_37 , V_135 ,
V_92 -> V_136 ) ;
F_34 ( V_37 , V_137 ,
V_92 -> V_138 ) ;
F_34 ( V_37 , V_139 ,
V_92 -> V_140 ) ;
F_34 ( V_37 , V_141 , V_92 -> V_142 ) ;
F_34 ( V_37 , V_143 ,
V_92 -> V_144 ) ;
F_34 ( V_37 , V_145 ,
V_92 -> V_146 ) ;
F_34 ( V_37 , V_147 ,
V_92 -> V_148 ) ;
F_34 ( V_37 , V_149 , V_92 -> V_150 ) ;
F_34 ( V_37 , V_151 , V_92 -> V_152 ) ;
F_34 ( V_37 , V_153 , V_92 -> V_154 ) ;
F_34 ( V_37 , V_155 , V_92 -> V_156 ) ;
F_34 ( V_37 , V_157 , V_92 -> V_158 ) ;
if ( V_102 )
F_34 ( V_37 , V_159 , V_101 ) ;
F_34 ( V_37 , V_160 , V_92 -> V_161 ) ;
F_47 ( V_37 ) ;
return 0 ;
}
static int F_59 ( struct V_13 * V_37 , void * V_99 )
{
struct V_91 * V_92 ;
T_3 V_162 ;
V_92 = F_56 ( V_99 ) ;
V_162 = F_53 ( V_92 ) ;
F_34 ( V_37 ,
V_162 + V_163 ,
V_92 -> V_164 ) ;
F_34 ( V_37 ,
V_162 + V_165 ,
V_92 -> V_166 ) ;
F_34 ( V_37 ,
V_162 + V_167 ,
V_92 -> V_168 ) ;
F_34 ( V_37 ,
V_162 + V_169 ,
V_92 -> V_170 ) ;
F_34 ( V_37 ,
V_162 + V_171 ,
V_92 -> V_172 ) ;
F_34 ( V_37 ,
V_162 + V_173 ,
V_92 -> V_174 ) ;
F_34 ( V_37 ,
V_162 + V_175 ,
V_92 -> V_176 ) ;
return 0 ;
}
static bool F_60 ( struct V_13 * V_37 , T_2 V_177 ,
T_3 V_69 , T_3 V_70 )
{
T_3 V_178 ;
bool V_93 = false ;
T_3 V_179 , V_180 ;
F_46 ( V_37 , V_69 , V_70 ) ;
V_178 = F_36 ( V_37 , V_160 ) ;
if ( V_178 ) {
V_179 = F_61 ( V_177 >> 8 ) ;
V_180 = F_62 ( V_177 >> 8 ) ;
if ( V_179 == F_36 ( V_37 , V_109 ) &&
V_180 == F_36 ( V_37 , V_111 ) )
V_93 = true ;
}
F_47 ( V_37 ) ;
return V_93 ;
}
static bool F_63 ( struct V_13 * V_37 , void * V_99 )
{
struct V_91 * V_92 ;
T_3 V_162 ;
T_3 V_176 ;
V_92 = F_56 ( V_99 ) ;
V_162 = F_53 ( V_92 ) ;
V_176 = F_36 ( V_37 ,
V_162 + V_175 ) ;
if ( V_176 & V_181 )
return true ;
return false ;
}
static int F_64 ( struct V_13 * V_37 , T_3 V_182 ,
unsigned int V_183 , T_3 V_69 ,
T_3 V_70 )
{
T_3 V_184 ;
F_46 ( V_37 , V_69 , V_70 ) ;
F_34 ( V_37 , V_147 , 0 ) ;
F_34 ( V_37 , V_185 , V_182 ) ;
while ( true ) {
V_184 = F_36 ( V_37 , V_160 ) ;
if ( V_184 & 0x1 )
break;
if ( V_183 == 0 ) {
F_65 ( L_6 ,
V_184 ) ;
F_47 ( V_37 ) ;
return - V_186 ;
}
F_66 ( 20 ) ;
V_183 -= 20 ;
}
F_47 ( V_37 ) ;
return 0 ;
}
static int F_67 ( struct V_13 * V_37 , void * V_99 ,
unsigned int V_183 )
{
struct V_91 * V_92 ;
T_3 V_162 ;
T_3 V_184 ;
V_92 = F_56 ( V_99 ) ;
V_162 = F_53 ( V_92 ) ;
V_184 = F_36 ( V_37 , V_162 + V_175 ) ;
V_184 = V_184 & ~ V_181 ;
F_34 ( V_37 , V_162 + V_175 , V_184 ) ;
while ( true ) {
V_184 = F_36 ( V_37 , V_162 +
V_187 ) ;
if ( V_184 & V_188 )
break;
if ( V_183 == 0 )
return - V_186 ;
F_66 ( 20 ) ;
V_183 -= 20 ;
}
F_34 ( V_37 , V_162 + V_173 , 0 ) ;
F_34 ( V_37 , V_162 + V_189 , 0 ) ;
F_34 ( V_37 , V_162 + V_190 , 0 ) ;
F_34 ( V_37 , V_162 + V_165 , 0 ) ;
return 0 ;
}
static int F_68 ( struct V_13 * V_37 )
{
union V_191 V_192 ;
unsigned int V_16 ;
V_192 . V_193 = 0 ;
V_192 . V_194 . V_195 = 0 ;
V_192 . V_194 . V_196 = V_197 ;
V_192 . V_194 . V_198 = 1 ;
for ( V_16 = 0 ; V_16 < V_199 ; V_16 ++ )
F_34 ( V_37 ,
V_200 [ V_16 * V_201 +
V_202 ] ,
V_192 . V_193 ) ;
return 0 ;
}
static int F_69 ( struct V_13 * V_37 ,
unsigned int V_203 ,
T_3 V_204 ,
T_3 V_205 ,
T_3 V_206 )
{
union V_191 V_192 ;
V_192 . V_193 = V_204 ;
V_192 . V_194 . V_195 = 0 ;
F_34 ( V_37 ,
V_200 [ V_203 * V_201 +
V_202 ] ,
V_192 . V_193 ) ;
F_34 ( V_37 ,
V_200 [ V_203 * V_201 +
V_207 ] ,
V_205 ) ;
F_34 ( V_37 ,
V_200 [ V_203 * V_201 +
V_208 ] ,
V_206 ) ;
V_192 . V_194 . V_195 = 1 ;
F_34 ( V_37 ,
V_200 [ V_203 * V_201 +
V_202 ] ,
V_192 . V_193 ) ;
return 0 ;
}
static int F_70 ( struct V_13 * V_37 ,
T_3 V_209 ,
T_3 V_210 )
{
struct V_9 * V_10 = F_33 ( V_37 ) ;
T_3 V_211 ;
F_43 ( & V_10 -> V_212 ) ;
F_34 ( V_37 , V_213 , V_209 ) ;
F_34 ( V_37 , V_214 , V_210 ) ;
V_211 = V_215 | V_216 |
V_217 ;
F_34 ( V_37 , V_213 , V_211 ) ;
F_45 ( & V_10 -> V_212 ) ;
return 0 ;
}
static T_3 F_71 ( struct V_13 * V_37 ,
unsigned int V_203 ,
unsigned int V_218 )
{
return V_200 [ V_203 * V_201 + V_218 ] ;
}
static bool F_72 ( struct V_13 * V_37 , T_5 V_66 )
{
T_3 V_219 ;
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
V_219 = F_73 ( V_83 + V_66 * 4 ) ;
return V_219 & V_82 ;
}
static T_6 F_74 ( struct V_13 * V_37 ,
T_5 V_66 )
{
T_3 V_219 ;
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
V_219 = F_73 ( V_83 + V_66 * 4 ) ;
return V_219 & V_220 ;
}
static void F_75 ( struct V_13 * V_37 , T_5 V_66 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
return F_76 ( V_221 , 1 << V_66 ) ;
}
static T_6 F_77 ( struct V_13 * V_37 , enum V_222 type )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
const union V_223 * V_224 ;
F_17 ( V_37 == NULL || V_10 -> V_225 == NULL ) ;
switch ( type ) {
case V_226 :
V_224 = ( const union V_223 * ) V_10 -> V_227 -> V_211 ;
break;
case V_228 :
V_224 = ( const union V_223 * ) V_10 -> V_229 -> V_211 ;
break;
case V_230 :
V_224 = ( const union V_223 * ) V_10 -> V_231 -> V_211 ;
break;
case V_232 :
V_224 = ( const union V_223 * ) V_10 -> V_225 -> V_211 ;
break;
case V_233 :
V_224 = ( const union V_223 * )
V_10 -> V_234 -> V_211 ;
break;
case V_235 :
V_224 = ( const union V_223 * ) V_10 -> V_236 -> V_211 ;
break;
case V_237 :
case V_238 :
V_224 = ( const union V_223 * )
V_10 -> V_239 -> V_211 ;
break;
default:
return 0 ;
}
if ( V_224 == NULL )
return 0 ;
return V_224 -> V_240 . V_241 ;
}
