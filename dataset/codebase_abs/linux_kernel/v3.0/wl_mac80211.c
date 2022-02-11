static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 ) ;
if ( ! V_6 -> V_8 -> V_9 ) {
F_3 ( V_6 -> V_10 , L_1 ) ;
F_4 ( V_4 ) ;
goto V_11;
}
F_5 ( V_6 -> V_12 , V_4 , V_2 ) ;
V_11:
F_6 ( V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
bool V_13 ;
F_8 ( V_2 ) ;
F_2 ( V_6 ) ;
V_13 = F_9 ( V_6 ) ;
F_6 ( V_6 ) ;
if ( ! V_13 )
F_10 ( V_6 -> V_8 -> V_14 -> V_10 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_5 * V_6 ;
int V_17 ;
if ( V_16 -> type != V_18 &&
V_16 -> type != V_19 &&
V_16 -> type != V_20 &&
V_16 -> type != V_21 &&
V_16 -> type != V_22 ) {
F_3 ( V_2 -> V_10 , L_2
L_3 , V_23 , V_16 -> type ) ;
return - V_24 ;
}
V_6 = F_14 ( V_2 ) ;
F_2 ( V_6 ) ;
V_17 = F_15 ( V_6 ) ;
F_6 ( V_6 ) ;
if ( V_17 != 0 ) {
F_3 ( V_2 -> V_10 , L_4 , V_23 ,
V_17 ) ;
}
return V_17 ;
}
static void
F_16 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_2 ) ;
F_2 ( V_6 ) ;
F_17 ( V_6 ) ;
F_6 ( V_6 ) ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_25 * V_26 ,
enum V_27 type )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
int V_17 = 0 ;
switch ( type ) {
case V_28 :
case V_29 :
V_17 = F_19 ( V_6 -> V_12 , V_30 , V_26 -> V_31 ) ;
break;
case V_32 :
case V_33 :
F_3 ( V_2 -> V_10 ,
L_5 , V_23 ) ;
V_17 = 1 ;
break;
}
if ( V_17 )
return - V_34 ;
return V_17 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_5 * V_6 = F_14 ( V_2 ) ;
int V_17 = 0 ;
int V_38 ;
struct V_10 * V_10 = V_2 -> V_10 ;
F_2 ( V_6 ) ;
if ( V_35 & V_39 ) {
if ( F_21
( V_6 -> V_12 , L_6 , V_37 -> V_40 ) ) {
F_3 ( V_10 , L_7 ,
V_23 ) ;
V_17 = - V_34 ;
goto V_41;
}
F_22 ( V_6 -> V_12 , L_6 , & V_38 ) ;
}
if ( V_35 & V_42 )
F_3 ( V_10 , L_8 ,
V_23 , V_37 -> V_43 & V_44 ?
L_9 : L_10 ) ;
if ( V_35 & V_45 )
F_3 ( V_10 , L_11 ,
V_23 , V_37 -> V_43 & V_46 ?
L_9 : L_10 ) ;
if ( V_35 & V_47 ) {
if ( F_21
( V_6 -> V_12 , L_12 , V_37 -> V_48 * 4 ) ) {
F_3 ( V_10 , L_13 ,
V_23 ) ;
V_17 = - V_34 ;
goto V_41;
}
F_22 ( V_6 -> V_12 , L_12 , & V_38 ) ;
if ( V_38 != ( V_37 -> V_48 * 4 ) )
F_3 ( V_10 , L_14
L_15 , V_23 , V_37 -> V_48 * 4 ,
V_38 ) ;
}
if ( V_35 & V_49 ) {
V_17 = F_18 ( V_2 , V_37 -> V_50 , V_37 -> V_51 ) ;
}
if ( V_35 & V_52 ) {
if ( F_19
( V_6 -> V_12 , V_53 ,
V_37 -> V_54 ) < 0 ) {
F_3 ( V_10 , L_16 , V_23 ) ;
V_17 = - V_34 ;
goto V_41;
}
if ( F_19 ( V_6 -> V_12 , V_55 , V_37 -> V_56 )
< 0 ) {
F_3 ( V_10 , L_17 , V_23 ) ;
V_17 = - V_34 ;
goto V_41;
}
}
V_41:
F_6 ( V_6 ) ;
return V_17 ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_57 * V_58 , T_1 V_35 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
struct V_10 * V_10 = V_2 -> V_10 ;
int V_59 ;
if ( V_35 & V_60 ) {
F_3 ( V_10 , L_18 , V_61 ,
V_23 , V_58 -> V_62 ? L_19 : L_20 ) ;
F_2 ( V_6 ) ;
F_24 ( V_6 -> V_12 , V_58 -> V_62 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_63 ) {
if ( V_58 -> V_64 )
V_59 = 1 ;
else
V_59 = 0 ;
F_2 ( V_6 ) ;
F_19 ( V_6 -> V_12 , V_65 , V_59 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_66 ) {
T_2 V_67 = V_58 -> V_68 ;
F_2 ( V_6 ) ;
F_25 ( V_6 -> V_12 , V_69 ,
V_67 & V_70 ) ;
F_25 ( V_6 -> V_12 , V_71 ,
V_67 & V_72 ) ;
F_25 ( V_6 -> V_12 , V_73 ,
V_67 & V_74 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_75 ) {
struct V_76 * V_77 ;
T_1 V_78 , V_79 ;
T_2 V_80 ;
struct V_81 V_82 ;
int error ;
F_2 ( V_6 ) ;
error = F_26 ( V_6 -> V_12 , V_83 ,
& V_82 , sizeof( V_82 ) , NULL ) ;
F_6 ( V_6 ) ;
if ( error ) {
F_3 ( V_10 , L_21 ,
V_23 , error ) ;
return;
}
V_78 = V_58 -> V_84 ;
V_77 = V_2 -> V_10 -> V_85 [ F_27 ( V_6 -> V_12 ) ] ;
for ( V_79 = 0 ; V_79 < V_77 -> V_86 ; V_79 ++ ) {
V_80 = ( V_77 -> V_87 [ V_79 ] . V_88 << 1 ) / 10 ;
F_28 ( & V_82 , V_80 , V_78 & 1 ) ;
V_78 >>= 1 ;
}
F_2 ( V_6 ) ;
F_26 ( V_6 -> V_12 , V_89 , & V_82 , sizeof( V_82 ) , NULL ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_90 ) {
F_2 ( V_6 ) ;
F_19 ( V_6 -> V_12 , V_91 , V_58 -> V_92 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_93 ) {
F_2 ( V_6 ) ;
F_29 ( V_6 -> V_12 , V_94 ,
V_58 -> V_95 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_96 ) {
F_3 ( V_10 , L_22 , V_23 ) ;
}
if ( V_35 & V_97 ) {
F_3 ( V_10 , L_23 , V_23 ,
V_58 -> V_98 ? L_9 : L_10 ) ;
}
if ( V_35 & V_99 ) {
F_3 ( V_10 , L_24
L_25 , V_23 , V_58 -> V_100 ,
V_58 -> V_101 ) ;
}
if ( V_35 & V_102 ) {
F_3 ( V_10 , L_26 , V_23 ,
V_58 -> V_103 ? L_9 : L_10 ) ;
}
if ( V_35 & V_104 ) {
F_3 ( V_10 , L_27
L_25 , V_23 , V_58 -> V_105 ?
L_9 : L_10 , V_58 -> V_106 ) ;
}
if ( V_35 & V_107 ) {
F_3 ( V_10 , L_28 , V_23 ,
V_58 -> V_108 ? L_9 : L_10 ) ;
}
if ( V_35 & V_109 ) {
F_3 ( V_10 , L_29 , V_23 ,
V_58 -> V_110 ? L_9 : L_10 ) ;
}
return;
}
static void
F_30 ( struct V_1 * V_2 ,
unsigned int V_111 ,
unsigned int * V_112 , T_3 V_113 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_10 = V_2 -> V_10 ;
V_111 &= V_114 ;
* V_112 &= V_114 ;
if ( V_111 & V_115 )
F_3 ( V_10 , L_30 ) ;
if ( V_111 & V_116 )
F_3 ( V_10 , L_31 ) ;
if ( V_111 & V_117 )
F_3 ( V_10 , L_32 ) ;
if ( V_111 & V_118 )
F_3 ( V_10 , L_33 ) ;
if ( V_111 & V_119 )
F_3 ( V_10 , L_34 ) ;
if ( V_111 & V_120 )
F_3 ( V_10 , L_35 ) ;
if ( V_111 & V_121 ) {
F_2 ( V_6 ) ;
if ( * V_112 & V_121 ) {
V_6 -> V_8 -> V_122 |= V_123 ;
F_31 ( V_6 -> V_12 , 1 ) ;
} else {
F_31 ( V_6 -> V_12 , 0 ) ;
V_6 -> V_8 -> V_122 &= ~ V_123 ;
}
F_6 ( V_6 ) ;
}
return;
}
static int
F_32 ( struct V_1 * V_2 , struct V_124 * V_125 , bool V_126 )
{
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 ) ;
F_34 ( V_6 -> V_12 ) ;
F_6 ( V_6 ) ;
return;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 ) ;
F_36 ( V_6 -> V_12 ) ;
F_6 ( V_6 ) ;
return;
}
static void F_37 ( struct V_1 * V_2 , T_3 V_127 )
{
F_3 ( V_2 -> V_10 , L_36 , V_23 ) ;
return;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_130 * V_131 ;
F_2 ( V_6 ) ;
V_131 = V_6 -> V_8 -> V_132 ;
V_129 -> V_133 = 0 ;
V_129 -> V_134 = 0 ;
V_129 -> V_135 = 0 ;
V_129 -> V_136 = 0 ;
F_6 ( V_6 ) ;
return 0 ;
}
static void
F_39 ( struct V_1 * V_2 , struct V_15 * V_16 ,
enum V_137 V_138 , struct V_124 * V_125 )
{
switch ( V_138 ) {
default:
F_3 ( V_2 -> V_10 , L_37 , V_23 ,
V_138 ) ;
break;
}
return;
}
static int
F_40 ( struct V_1 * V_2 , T_2 V_139 ,
const struct V_140 * V_141 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 ) ;
F_41 ( V_6 -> V_12 , V_139 , V_141 , true ) ;
F_6 ( V_6 ) ;
return 0 ;
}
static T_3 F_42 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_10 , L_36 , V_23 ) ;
return 0 ;
}
static int
F_43 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_124 * V_125 )
{
struct V_142 * V_142 ;
int V_79 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_142 = (struct V_142 * ) V_125 -> V_143 ;
memset ( V_142 , 0 , sizeof( struct V_142 ) ) ;
for ( V_79 = 0 ; V_79 < V_144 ; V_79 ++ )
V_142 -> V_145 [ V_79 ] = 0xFFFF ;
V_142 -> V_146 = 0xFFFF ;
V_142 -> V_147 = V_148 ;
V_6 -> V_8 -> V_149 = V_142 ;
V_6 -> V_8 -> V_150 = & ( V_142 -> V_151 ) ;
V_6 -> V_8 -> V_150 -> V_142 = V_142 ;
V_6 -> V_8 -> V_150 -> V_152 = 16 ;
F_44 ( & V_142 -> V_151 . V_153 , V_154 ,
V_154 * V_155 ) ;
V_125 -> V_156 . V_157 = true ;
V_125 -> V_156 . V_158 = V_159 ;
V_125 -> V_156 . V_160 = V_161 ;
V_125 -> V_156 . V_162 = V_163 |
V_164 |
V_165 | V_166 ;
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_124 * V_125 )
{
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
enum V_167 V_168 ,
struct V_124 * V_125 , T_2 V_169 , T_2 * V_170 ,
T_4 V_171 )
{
struct V_142 * V_142 = (struct V_142 * ) V_125 -> V_143 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_172 ;
if ( F_47 ( V_142 -> V_147 != V_148 ) )
return - V_173 ;
switch ( V_168 ) {
case V_174 :
break;
case V_175 :
break;
case V_176 :
F_2 ( V_6 ) ;
V_172 = F_48 ( V_6 -> V_12 , V_169 ) ;
F_6 ( V_6 ) ;
if ( ! V_172 ) {
F_3 ( V_6 -> V_10 , L_38 ,
V_169 ) ;
return - V_177 ;
}
* V_170 = 0 ;
F_49 ( V_16 , V_125 -> V_178 , V_169 ) ;
break;
case V_179 :
F_2 ( V_6 ) ;
F_50 ( V_6 -> V_12 , V_125 , V_169 ) ;
F_6 ( V_6 ) ;
F_51 ( V_16 , V_125 -> V_178 , V_169 ) ;
break;
case V_180 :
break;
default:
F_3 ( V_6 -> V_10 , L_39 ,
V_23 ) ;
}
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
bool V_13 ;
F_2 ( V_6 ) ;
V_13 = F_53 ( V_6 -> V_12 ) ;
F_6 ( V_6 ) ;
F_54 ( V_6 -> V_8 -> V_14 -> V_10 , V_13 ) ;
}
static void F_55 ( struct V_1 * V_2 , bool V_181 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
F_56 ( L_40 , V_23 , V_181 ? L_9 : L_10 ) ;
F_2 ( V_6 ) ;
F_57 ( V_6 -> V_12 , V_181 ) ;
F_6 ( V_6 ) ;
}
static int F_58 ( struct V_5 * V_6 , char * V_182 )
{
return F_59 ( V_6 -> V_8 -> V_14 -> V_10 , V_182 ) ;
}
static struct V_5 * F_60 ( T_2 V_183 , T_2 V_184 , unsigned long V_185 ,
T_5 V_186 , void * V_187 , T_5 V_188 )
{
struct V_5 * V_6 = NULL ;
int V_189 , V_17 ;
unsigned long V_190 ;
struct V_1 * V_2 ;
T_4 V_191 [ V_192 ] ;
V_189 = V_193 ;
V_17 = 0 ;
if ( V_189 < 0 ) {
return NULL ;
}
V_2 = F_61 ( V_187 ) ;
if ( V_2 != NULL )
V_6 = V_2 -> V_7 ;
if ( F_47 ( V_2 == NULL ) || F_47 ( V_6 == NULL ) )
return NULL ;
V_6 -> V_10 = V_2 -> V_10 ;
F_62 ( & V_6 -> V_194 , 0 ) ;
F_63 ( & V_6 -> V_195 , V_196 , ( unsigned long ) V_6 ) ;
V_190 = V_185 ;
if ( V_186 == V_197 ) {
V_6 -> V_198 = false ;
} else if ( V_186 == V_199 ) {
} else {
V_186 = V_197 ;
F_64 ( V_6 -> V_10 , L_41 ) ;
}
V_6 -> V_200 = V_186 ;
V_6 -> V_201 = F_65 ( V_190 , V_202 ) ;
if ( V_6 -> V_201 == NULL ) {
F_3 ( V_6 -> V_10 , L_42 , V_189 ) ;
goto V_203;
}
F_66 ( & V_6 -> V_204 ) ;
F_66 ( & V_6 -> V_205 ) ;
if ( F_67 ( V_6 , (struct V_206 * ) V_187 ) < 0 ) {
F_3 ( V_6 -> V_10 , L_43
L_44 , V_61 , L_45 ) ;
F_68 ( V_6 ) ;
F_69 ( (struct V_206 * ) V_187 ) ;
return NULL ;
}
V_6 -> V_12 = F_70 ( ( void * ) V_6 , V_183 , V_184 , V_189 , V_6 -> V_198 ,
V_6 -> V_201 , V_6 -> V_200 , V_187 , & V_17 ) ;
F_68 ( V_6 ) ;
if ( ! V_6 -> V_12 ) {
F_3 ( V_6 -> V_10 , L_46 ,
V_61 , V_17 ) ;
goto V_203;
}
V_6 -> V_8 = F_71 ( V_6 -> V_12 ) ;
V_6 -> V_8 -> V_14 = V_2 ;
if ( F_21 ( V_6 -> V_12 , L_47 , 0 ) ) {
F_3 ( V_6 -> V_10 , L_48 ,
V_189 ) ;
}
if ( F_72 ( V_188 , V_207 , V_208 , V_61 , V_6 ) ) {
F_3 ( V_6 -> V_10 , L_49 , V_189 ) ;
goto V_203;
}
V_6 -> V_188 = V_188 ;
F_73 ( V_6 -> V_8 , NULL , L_50 , V_6 , NULL , V_209 ,
NULL ) ;
if ( F_74 ( V_2 ) ) {
F_3 ( V_6 -> V_10 , L_51 , V_189 ,
V_23 ) ;
goto V_203;
}
memcpy ( V_191 , & V_6 -> V_8 -> V_210 , V_192 ) ;
if ( F_47 ( ! F_75 ( V_191 ) ) )
goto V_203;
F_76 ( V_2 , V_191 ) ;
V_17 = F_77 ( V_2 ) ;
if ( V_17 ) {
F_3 ( V_6 -> V_10 , L_52
L_53 , V_23 , V_17 ) ;
}
if ( V_6 -> V_8 -> V_211 [ 0 ] )
V_17 = F_58 ( V_6 , V_6 -> V_8 -> V_211 ) ;
else
V_17 = F_58 ( V_6 , L_54 ) ;
if ( V_17 ) {
F_3 ( V_6 -> V_10 , L_55 ,
V_23 , V_17 ) ;
}
V_193 ++ ;
return V_6 ;
V_203:
F_78 ( V_6 ) ;
return NULL ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
int V_212 ;
char V_213 [ 4 ] ;
V_212 = 0 ;
V_2 -> V_10 -> V_85 [ V_214 ] = NULL ;
V_2 -> V_10 -> V_85 [ V_215 ] = NULL ;
if ( F_80 ( V_6 -> V_12 , V_216 , ( int * ) & V_213 ) < 0 ) {
F_3 ( V_2 -> V_10 , L_56 ) ;
}
if ( V_213 [ 0 ] == 'n' || V_213 [ 0 ] == 'c' ) {
if ( V_213 [ 0 ] == 'c' ) {
V_217 . V_156 . V_218 . V_219 [ 1 ] = 0 ;
V_217 . V_156 . V_218 . V_220 = 72 ;
}
V_2 -> V_10 -> V_85 [ V_214 ] = & V_217 ;
} else {
return - V_221 ;
}
if ( F_81 ( V_6 -> V_8 ) > 1 ) {
V_212 ++ ;
if ( V_213 [ 0 ] == 'n' || V_213 [ 0 ] == 'c' ) {
V_2 -> V_10 -> V_85 [ V_215 ] =
& V_222 ;
} else {
return - V_221 ;
}
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
V_2 -> V_43 = V_223
| V_224
| V_225 ;
V_2 -> V_226 = F_82 () ;
V_2 -> V_227 = V_228 ;
V_2 -> V_229 = 2 ;
V_2 -> V_230 = 7 * 1000 ;
V_2 -> V_10 -> V_231 = F_83 ( V_20 ) ;
V_2 -> V_232 = L_57 ;
V_2 -> V_233 = sizeof( struct V_142 ) ;
return F_79 ( V_2 ) ;
}
static int T_6
F_84 ( struct V_206 * V_234 , const struct V_235 * V_236 )
{
int V_237 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_1 V_59 ;
F_85 ( & V_234 -> V_238 , L_58 ,
V_234 -> V_239 -> V_240 , F_86 ( V_234 -> V_241 ) ,
F_87 ( V_234 -> V_241 ) , V_234 -> V_188 ) ;
if ( ( V_234 -> V_183 != V_242 ) ||
( ( ( V_234 -> V_184 & 0xff00 ) != 0x4300 ) &&
( ( V_234 -> V_184 & 0xff00 ) != 0x4700 ) &&
( ( V_234 -> V_184 < 43000 ) || ( V_234 -> V_184 > 43999 ) ) ) )
return - V_243 ;
V_237 = F_88 ( V_234 ) ;
if ( V_237 ) {
F_89 ( L_59 ,
V_23 , V_234 -> V_239 -> V_240 , F_86 ( V_234 -> V_241 ) ,
F_87 ( V_234 -> V_241 ) ) ;
return - V_243 ;
}
F_90 ( V_234 ) ;
F_91 ( V_234 , 0x40 , & V_59 ) ;
if ( ( V_59 & 0x0000ff00 ) != 0 )
F_92 ( V_234 , 0x40 , V_59 & 0xffff00ff ) ;
V_2 = F_93 ( sizeof( struct V_5 ) , & V_244 ) ;
if ( ! V_2 ) {
F_89 ( L_60 , V_23 ) ;
return - V_245 ;
}
F_94 ( V_2 , & V_234 -> V_238 ) ;
F_95 ( V_234 , V_2 ) ;
memset ( V_2 -> V_7 , 0 , sizeof( * V_6 ) ) ;
V_6 = F_60 ( V_234 -> V_183 , V_234 -> V_184 , F_96 ( V_234 , 0 ) ,
V_197 , V_234 , V_234 -> V_188 ) ;
if ( ! V_6 ) {
F_89 ( L_61 , V_61 ,
V_23 ) ;
return - V_243 ;
}
return 0 ;
}
static int F_97 ( struct V_206 * V_234 , T_7 V_246 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_61 ( V_234 ) ;
V_6 = F_14 ( V_2 ) ;
if ( ! V_6 ) {
F_3 ( V_6 -> V_10 ,
L_62 ) ;
return - V_243 ;
}
F_2 ( V_6 ) ;
V_6 -> V_8 -> V_247 = false ;
F_6 ( V_6 ) ;
F_98 ( V_234 ) ;
F_99 ( V_234 ) ;
return F_100 ( V_234 , V_248 ) ;
}
static int F_101 ( struct V_206 * V_234 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_17 = 0 ;
T_1 V_59 ;
V_2 = F_61 ( V_234 ) ;
V_6 = F_14 ( V_2 ) ;
if ( ! V_6 ) {
F_3 ( V_6 -> V_10 ,
L_63 ) ;
return - V_243 ;
}
V_17 = F_100 ( V_234 , V_249 ) ;
if ( V_17 )
return V_17 ;
F_102 ( V_234 ) ;
V_17 = F_88 ( V_234 ) ;
if ( V_17 )
return V_17 ;
F_90 ( V_234 ) ;
F_91 ( V_234 , 0x40 , & V_59 ) ;
if ( ( V_59 & 0x0000ff00 ) != 0 )
F_92 ( V_234 , 0x40 , V_59 & 0xffff00ff ) ;
return V_17 ;
}
static void F_69 ( struct V_206 * V_234 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_172 ;
V_2 = F_61 ( V_234 ) ;
V_6 = F_14 ( V_2 ) ;
if ( ! V_6 ) {
F_89 ( L_64 ) ;
return;
}
F_2 ( V_6 ) ;
V_172 = F_103 ( V_234 -> V_183 , V_234 -> V_184 ) ;
F_6 ( V_6 ) ;
if ( ! V_172 ) {
F_3 ( V_6 -> V_10 , L_65 ) ;
return;
}
if ( V_6 -> V_12 ) {
F_54 ( V_6 -> V_8 -> V_14 -> V_10 , false ) ;
F_10 ( V_6 -> V_8 -> V_14 -> V_10 ) ;
F_104 ( V_2 ) ;
F_2 ( V_6 ) ;
F_17 ( V_6 ) ;
F_6 ( V_6 ) ;
}
F_99 ( V_234 ) ;
F_78 ( V_6 ) ;
F_95 ( V_234 , NULL ) ;
F_105 ( V_2 ) ;
}
static int T_8 F_106 ( void )
{
int error = - V_243 ;
#ifdef F_107
if ( V_250 != 0xdeadbeef )
V_251 = V_250 ;
else {
char * V_252 = F_108 ( NULL , L_66 ) ;
if ( V_252 ) {
unsigned long V_253 ;
( void ) F_109 ( V_252 , 0 , & V_253 ) ;
V_251 = V_253 ;
}
}
if ( V_254 != 0xdeadbeef )
V_255 = V_254 ;
else {
char * V_252 = F_108 ( NULL , L_67 ) ;
if ( V_252 ) {
unsigned long V_253 ;
( void ) F_109 ( V_252 , 0 , & V_253 ) ;
V_255 = V_253 ;
}
}
#endif
error = F_110 ( & V_256 ) ;
if ( ! error )
return 0 ;
return error ;
}
static void T_9 F_111 ( void )
{
F_112 ( & V_256 ) ;
}
static void F_78 ( struct V_5 * V_6 )
{
struct V_257 * V_258 , * V_259 ;
if ( V_6 -> V_260 . V_261 )
F_113 () ;
if ( V_6 -> V_188 )
F_114 ( V_6 -> V_188 , V_6 ) ;
F_115 ( & V_6 -> V_195 ) ;
if ( V_6 -> V_8 ) {
F_116 ( V_6 -> V_8 , L_50 , V_6 ) ;
}
if ( V_6 -> V_12 ) {
F_117 ( V_6 -> V_12 ) ;
V_6 -> V_12 = NULL ;
V_6 -> V_8 = NULL ;
}
while ( F_118 ( & V_6 -> V_194 ) > 0 )
F_119 () ;
for ( V_258 = V_6 -> V_262 ; V_258 ; V_258 = V_259 ) {
V_259 = V_258 -> V_259 ;
#ifdef F_107
F_120 ( V_258 -> V_263 ) ;
#endif
F_120 ( V_258 ) ;
}
if ( V_6 -> V_201 && V_6 -> V_200 != V_264 &&
V_6 -> V_200 != V_265 ) {
F_121 ( ( void * ) V_6 -> V_201 ) ;
}
V_6 -> V_201 = NULL ;
}
static void F_28 ( struct V_81 * V_82 , T_2 V_80 , bool V_266 )
{
T_1 V_79 ;
for ( V_79 = 0 ; V_79 < V_82 -> V_267 ; V_79 ++ ) {
if ( V_80 != ( V_82 -> V_268 [ V_79 ] & 0x7f ) )
continue;
if ( V_266 )
V_82 -> V_268 [ V_79 ] |= V_269 ;
else
V_82 -> V_268 [ V_79 ] &= V_270 ;
return;
}
}
void F_122 ( struct V_5 * V_6 , struct V_271 * V_272 , bool V_246 ,
int V_273 )
{
F_3 ( V_6 -> V_10 , L_68 , V_23 ) ;
}
void F_123 ( struct V_5 * V_6 )
{
F_64 ( F_124 ( V_6 ) -> V_10 , L_69 , V_6 -> V_8 -> V_189 ) ;
F_125 ( V_6 ) ;
F_126 ( V_6 -> V_12 ) ;
}
T_5 F_125 ( struct V_5 * V_6 )
{
F_64 ( F_124 ( V_6 ) -> V_10 , L_69 , V_6 -> V_8 -> V_189 ) ;
F_127 ( V_6 -> V_12 ) ;
V_6 -> V_274 = 0 ;
return 0 ;
}
void F_128 ( struct V_5 * V_6 )
{
unsigned long V_43 ;
F_129 ( V_6 , V_43 ) ;
F_130 ( V_6 -> V_12 ) ;
F_131 ( V_6 , V_43 ) ;
}
bool F_132 ( struct V_5 * V_6 , T_5 V_275 )
{
return true ;
}
T_1 F_133 ( struct V_5 * V_6 )
{
unsigned long V_43 ;
T_1 V_172 ;
F_129 ( V_6 , V_43 ) ;
V_172 = F_134 ( V_6 -> V_12 ) ;
F_131 ( V_6 , V_43 ) ;
return V_172 ;
}
void F_135 ( struct V_5 * V_6 , T_1 V_276 )
{
unsigned long V_43 ;
F_129 ( V_6 , V_43 ) ;
F_136 ( V_6 -> V_12 , V_276 ) ;
F_131 ( V_6 , V_43 ) ;
}
int F_15 ( struct V_5 * V_6 )
{
int error = 0 ;
if ( V_6 -> V_8 -> V_9 )
return 0 ;
error = F_137 ( V_6 -> V_12 ) ;
return error ;
}
void F_17 ( struct V_5 * V_6 )
{
T_5 V_194 , V_277 = 0 ;
V_277 = F_138 ( V_6 -> V_12 ) ;
V_194 = F_118 ( & V_6 -> V_194 ) - V_277 ;
F_6 ( V_6 ) ;
F_139 ( ( F_118 ( & V_6 -> V_194 ) > V_194 ) , 100 * 1000 ) ;
F_2 ( V_6 ) ;
}
static T_10 V_207 ( int V_188 , void * V_278 )
{
struct V_5 * V_6 ;
bool V_279 , V_280 ;
unsigned long V_43 ;
V_6 = (struct V_5 * ) V_278 ;
F_140 ( V_6 , V_43 ) ;
V_279 = F_141 ( V_6 -> V_12 , & V_280 ) ;
if ( V_279 ) {
if ( V_280 ) {
F_142 ( & V_6 -> V_195 ) ;
}
}
F_143 ( V_6 , V_43 ) ;
return F_144 ( V_279 ) ;
}
static void V_196 ( unsigned long V_281 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_281 ;
F_2 ( V_6 ) ;
if ( V_6 -> V_8 -> V_9 ) {
if ( V_6 -> V_274 ) {
unsigned long V_43 ;
F_129 ( V_6 , V_43 ) ;
F_145 ( V_6 -> V_12 ) ;
F_131 ( V_6 , V_43 ) ;
}
V_6 -> V_274 = F_146 ( V_6 -> V_12 , true ) ;
}
if ( ! V_6 -> V_8 -> V_9 )
goto V_11;
if ( V_6 -> V_274 )
F_142 ( & V_6 -> V_195 ) ;
else {
F_128 ( V_6 ) ;
}
V_11:
F_6 ( V_6 ) ;
}
static void V_257 ( unsigned long V_281 )
{
F_147 ( (struct V_257 * ) V_281 ) ;
}
static void F_147 ( struct V_257 * V_258 )
{
F_2 ( V_258 -> V_6 ) ;
if ( V_258 -> V_126 ) {
if ( V_258 -> V_282 ) {
V_258 -> V_283 . V_284 = V_285 + V_258 -> V_286 * V_287 / 1000 ;
F_148 ( & V_258 -> V_6 -> V_194 ) ;
F_149 ( & V_258 -> V_283 ) ;
V_258 -> V_126 = true ;
} else
V_258 -> V_126 = false ;
V_258 -> V_288 ( V_258 -> V_289 ) ;
}
F_150 ( & V_258 -> V_6 -> V_194 ) ;
F_6 ( V_258 -> V_6 ) ;
}
struct V_257 * F_151 ( struct V_5 * V_6 , void (* V_288) ( void * V_289 ) ,
void * V_289 , const char * V_263 )
{
struct V_257 * V_258 ;
V_258 = F_152 ( sizeof( struct V_257 ) , V_290 ) ;
if ( ! V_258 ) {
F_3 ( V_6 -> V_10 , L_70 ,
V_6 -> V_8 -> V_189 ) ;
return 0 ;
}
F_153 ( & V_258 -> V_283 ) ;
V_258 -> V_283 . V_281 = ( unsigned long ) V_258 ;
V_258 -> V_283 . V_291 = V_257 ;
V_258 -> V_6 = V_6 ;
V_258 -> V_288 = V_288 ;
V_258 -> V_289 = V_289 ;
V_258 -> V_259 = V_6 -> V_262 ;
V_6 -> V_262 = V_258 ;
#ifdef F_107
V_258 -> V_263 = F_154 ( strlen ( V_263 ) + 1 , V_290 ) ;
if ( V_258 -> V_263 )
strcpy ( V_258 -> V_263 , V_263 ) ;
#endif
return V_258 ;
}
void F_155 ( struct V_5 * V_6 , struct V_257 * V_258 , T_5 V_286 , int V_282 )
{
#ifdef F_107
if ( V_258 -> V_126 ) {
F_3 ( V_6 -> V_10 , L_71 ,
V_23 , V_258 -> V_263 , V_282 ) ;
}
#endif
V_258 -> V_286 = V_286 ;
V_258 -> V_282 = ( bool ) V_282 ;
V_258 -> V_126 = true ;
V_258 -> V_283 . V_284 = V_285 + V_286 * V_287 / 1000 ;
F_148 ( & V_6 -> V_194 ) ;
F_149 ( & V_258 -> V_283 ) ;
}
bool F_156 ( struct V_5 * V_6 , struct V_257 * V_258 )
{
if ( V_258 -> V_126 ) {
V_258 -> V_126 = false ;
if ( ! F_157 ( & V_258 -> V_283 ) ) {
return false ;
}
F_150 ( & V_6 -> V_194 ) ;
}
return true ;
}
void F_158 ( struct V_5 * V_6 , struct V_257 * V_258 )
{
struct V_257 * V_292 ;
F_156 ( V_6 , V_258 ) ;
if ( V_6 -> V_262 == V_258 ) {
V_6 -> V_262 = V_6 -> V_262 -> V_259 ;
#ifdef F_107
F_120 ( V_258 -> V_263 ) ;
#endif
F_120 ( V_258 ) ;
return;
}
V_292 = V_6 -> V_262 ;
while ( V_292 ) {
if ( V_292 -> V_259 == V_258 ) {
V_292 -> V_259 = V_258 -> V_259 ;
#ifdef F_107
F_120 ( V_258 -> V_263 ) ;
#endif
F_120 ( V_258 ) ;
return;
}
V_292 = V_292 -> V_259 ;
}
}
static int V_209 ( void * V_293 )
{
return 0 ;
}
int F_159 ( struct V_5 * V_6 , void * * V_294 , T_1 V_295 )
{
int V_79 , V_296 ;
const T_4 * V_297 ;
struct V_298 * V_299 ;
for ( V_79 = 0 ; V_79 < V_6 -> V_260 . V_261 ; V_79 ++ ) {
V_299 = (struct V_298 * ) V_6 -> V_260 . V_300 [ V_79 ] -> V_281 ;
for ( V_296 = 0 ; V_296 < V_6 -> V_260 . V_301 [ V_79 ] ;
V_296 ++ , V_299 ++ ) {
if ( V_299 -> V_295 == V_295 ) {
V_297 = V_6 -> V_260 . V_302 [ V_79 ] -> V_281 + V_299 -> V_303 ;
* V_294 = F_154 ( V_299 -> V_304 , V_290 ) ;
if ( * V_294 == NULL ) {
F_3 ( V_6 -> V_10 , L_72
L_73 , V_299 -> V_304 ) ;
goto V_203;
}
memcpy ( * V_294 , V_297 , V_299 -> V_304 ) ;
return 0 ;
}
}
}
F_3 ( V_6 -> V_10 , L_74 ,
V_295 ) ;
* V_294 = NULL ;
V_203:
return - V_305 ;
}
int F_160 ( struct V_5 * V_6 , T_1 * V_281 , T_1 V_295 )
{
int V_79 , V_296 ;
const T_4 * V_297 ;
struct V_298 * V_299 ;
for ( V_79 = 0 ; V_79 < V_6 -> V_260 . V_261 ; V_79 ++ ) {
V_299 = (struct V_298 * ) V_6 -> V_260 . V_300 [ V_79 ] -> V_281 ;
for ( V_296 = 0 ; V_296 < V_6 -> V_260 . V_301 [ V_79 ] ;
V_296 ++ , V_299 ++ ) {
if ( V_299 -> V_295 == V_295 ) {
V_297 = V_6 -> V_260 . V_302 [ V_79 ] -> V_281 + V_299 -> V_303 ;
if ( V_299 -> V_304 != 4 ) {
F_3 ( V_6 -> V_10 ,
L_75 ) ;
return - V_306 ;
}
* V_281 = * ( ( T_1 * ) V_297 ) ;
return 0 ;
}
}
}
F_3 ( V_6 -> V_10 , L_76 , V_295 ) ;
return - V_306 ;
}
static int F_67 ( struct V_5 * V_6 , struct V_206 * V_234 )
{
int V_172 ;
struct V_184 * V_184 = & V_234 -> V_238 ;
char V_307 [ 100 ] ;
int V_79 ;
memset ( ( void * ) & V_6 -> V_260 , 0 , sizeof( struct V_308 ) ) ;
for ( V_79 = 0 ; V_79 < V_309 ; V_79 ++ ) {
if ( V_310 [ V_79 ] == NULL )
break;
sprintf ( V_307 , L_77 , V_310 [ V_79 ] ,
V_311 ) ;
V_172 = F_161 ( & V_6 -> V_260 . V_302 [ V_79 ] , V_307 , V_184 ) ;
if ( V_172 ) {
F_3 ( V_6 -> V_10 , L_78 ,
V_61 , V_307 ) ;
return V_172 ;
}
sprintf ( V_307 , L_79 , V_310 [ V_79 ] ,
V_311 ) ;
V_172 = F_161 ( & V_6 -> V_260 . V_300 [ V_79 ] , V_307 , V_184 ) ;
if ( V_172 ) {
F_3 ( V_6 -> V_10 , L_78 ,
V_61 , V_307 ) ;
return V_172 ;
}
V_6 -> V_260 . V_301 [ V_79 ] =
V_6 -> V_260 . V_300 [ V_79 ] -> V_312 / ( sizeof( struct V_298 ) ) ;
}
V_6 -> V_260 . V_261 = V_79 ;
return F_162 ( V_6 ) ;
}
void F_163 ( void * V_313 )
{
F_120 ( V_313 ) ;
}
static void F_68 ( struct V_5 * V_6 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_309 ; V_79 ++ ) {
F_164 ( V_6 -> V_260 . V_302 [ V_79 ] ) ;
F_164 ( V_6 -> V_260 . V_300 [ V_79 ] ) ;
}
}
int F_165 ( struct V_5 * V_6 )
{
int V_79 ;
int V_296 ;
int V_237 = 0 ;
const struct V_314 * V_260 ;
const struct V_314 * V_300 ;
struct V_298 * V_315 ;
for ( V_79 = 0 ; V_79 < V_309 && V_237 == 0 ; V_79 ++ ) {
V_260 = V_6 -> V_260 . V_302 [ V_79 ] ;
V_300 = V_6 -> V_260 . V_300 [ V_79 ] ;
if ( V_260 == NULL && V_300 == NULL ) {
break;
} else if ( V_260 == NULL || V_300 == NULL ) {
F_3 ( V_6 -> V_10 , L_80 ,
V_23 ) ;
V_237 = - V_316 ;
} else if ( V_300 -> V_312 % sizeof( struct V_298 ) ) {
F_3 ( V_6 -> V_10 , L_81
L_82 , V_23 , V_300 -> V_312 ,
sizeof( struct V_298 ) ) ;
V_237 = - V_316 ;
} else if ( V_260 -> V_312 < V_317 || V_260 -> V_312 > V_318 ) {
F_3 ( V_6 -> V_10 , L_83
L_84 , V_23 , V_260 -> V_312 ) ;
V_237 = - V_316 ;
} else {
V_315 = (struct V_298 * ) V_300 -> V_281 ;
for ( V_296 = 0 ; V_296 < V_6 -> V_260 . V_301 [ V_79 ] &&
! V_237 ; V_296 ++ , V_315 ++ ) {
if ( V_315 -> V_303 + V_315 -> V_304 >
V_260 -> V_312 ) {
F_3 ( V_6 -> V_10 ,
L_85 ,
V_23 ) ;
V_237 = - V_316 ;
}
}
}
}
if ( V_237 == 0 && V_6 -> V_260 . V_261 != V_79 ) {
F_3 ( V_6 -> V_10 , L_86 , V_23 ,
V_6 -> V_260 . V_261 ) ;
V_237 = - V_316 ;
}
return V_237 ;
}
bool F_9 ( struct V_5 * V_6 )
{
bool V_13 = F_53 ( V_6 -> V_12 ) ;
F_6 ( V_6 ) ;
F_54 ( V_6 -> V_8 -> V_14 -> V_10 , V_13 ) ;
if ( V_13 )
F_166 ( V_6 -> V_8 -> V_14 -> V_10 ) ;
F_2 ( V_6 ) ;
return V_13 ;
}
void F_167 ( struct V_5 * V_6 , T_5 V_286 )
{
F_6 ( V_6 ) ;
F_168 ( V_286 ) ;
F_2 ( V_6 ) ;
}
