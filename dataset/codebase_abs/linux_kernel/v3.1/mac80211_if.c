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
if ( F_21 ( V_6 -> V_12 , V_40 ,
V_37 -> V_41 ) < 0 ) {
F_3 ( V_10 , L_6 ,
V_23 ) ;
V_17 = - V_34 ;
goto V_42;
}
F_22 ( V_6 -> V_12 , V_40 , & V_38 ) ;
}
if ( V_35 & V_43 )
F_3 ( V_10 , L_7 ,
V_23 , V_37 -> V_44 & V_45 ?
L_8 : L_9 ) ;
if ( V_35 & V_46 )
F_3 ( V_10 , L_10 ,
V_23 , V_37 -> V_44 & V_47 ?
L_8 : L_9 ) ;
if ( V_35 & V_48 ) {
if ( F_21 ( V_6 -> V_12 , V_49 ,
V_37 -> V_50 * 4 ) < 0 ) {
F_3 ( V_10 , L_11 ,
V_23 ) ;
V_17 = - V_34 ;
goto V_42;
}
F_22 ( V_6 -> V_12 , V_49 , & V_38 ) ;
if ( V_38 != ( V_37 -> V_50 * 4 ) )
F_3 ( V_10 , L_12
L_13 , V_23 , V_37 -> V_50 * 4 ,
V_38 ) ;
}
if ( V_35 & V_51 ) {
V_17 = F_18 ( V_2 , V_37 -> V_52 , V_37 -> V_53 ) ;
}
if ( V_35 & V_54 ) {
if ( F_19
( V_6 -> V_12 , V_55 ,
V_37 -> V_56 ) < 0 ) {
F_3 ( V_10 , L_14 , V_23 ) ;
V_17 = - V_34 ;
goto V_42;
}
if ( F_19 ( V_6 -> V_12 , V_57 ,
V_37 -> V_58 ) < 0 ) {
F_3 ( V_10 , L_15 , V_23 ) ;
V_17 = - V_34 ;
goto V_42;
}
}
V_42:
F_6 ( V_6 ) ;
return V_17 ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_59 * V_60 , T_1 V_35 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
struct V_10 * V_10 = V_2 -> V_10 ;
int V_61 ;
if ( V_35 & V_62 ) {
F_3 ( V_10 , L_16 , V_63 ,
V_23 , V_60 -> V_64 ? L_17 : L_18 ) ;
F_2 ( V_6 ) ;
F_24 ( V_6 -> V_12 , V_60 -> V_64 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_65 ) {
if ( V_60 -> V_66 )
V_61 = 1 ;
else
V_61 = 0 ;
F_2 ( V_6 ) ;
F_19 ( V_6 -> V_12 , V_67 , V_61 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_68 ) {
T_2 V_69 = V_60 -> V_70 ;
F_2 ( V_6 ) ;
F_25 ( V_6 -> V_12 , V_71 ,
V_69 & V_72 ) ;
F_25 ( V_6 -> V_12 , V_73 ,
V_69 & V_74 ) ;
F_25 ( V_6 -> V_12 , V_75 ,
V_69 & V_76 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_77 ) {
struct V_78 * V_79 ;
T_1 V_80 , V_81 ;
T_2 V_82 ;
struct V_83 V_84 ;
int error ;
F_2 ( V_6 ) ;
error = F_26 ( V_6 -> V_12 , V_85 ,
& V_84 , sizeof( V_84 ) , NULL ) ;
F_6 ( V_6 ) ;
if ( error ) {
F_3 ( V_10 , L_19 ,
V_23 , error ) ;
return;
}
V_80 = V_60 -> V_86 ;
V_79 = V_2 -> V_10 -> V_87 [ F_27 ( V_6 -> V_12 ) ] ;
for ( V_81 = 0 ; V_81 < V_79 -> V_88 ; V_81 ++ ) {
V_82 = ( V_79 -> V_89 [ V_81 ] . V_90 << 1 ) / 10 ;
F_28 ( & V_84 , V_82 , V_80 & 1 ) ;
V_80 >>= 1 ;
}
F_2 ( V_6 ) ;
F_26 ( V_6 -> V_12 , V_91 , & V_84 , sizeof( V_84 ) , NULL ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_92 ) {
F_2 ( V_6 ) ;
F_19 ( V_6 -> V_12 , V_93 , V_60 -> V_94 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_95 ) {
F_2 ( V_6 ) ;
F_29 ( V_6 -> V_12 , V_96 ,
V_60 -> V_97 ) ;
F_6 ( V_6 ) ;
}
if ( V_35 & V_98 ) {
F_3 ( V_10 , L_20 , V_23 ) ;
}
if ( V_35 & V_99 ) {
F_3 ( V_10 , L_21 , V_23 ,
V_60 -> V_100 ? L_8 : L_9 ) ;
}
if ( V_35 & V_101 ) {
F_3 ( V_10 , L_22
L_23 , V_23 , V_60 -> V_102 ,
V_60 -> V_103 ) ;
}
if ( V_35 & V_104 ) {
F_3 ( V_10 , L_24 , V_23 ,
V_60 -> V_105 ? L_8 : L_9 ) ;
}
if ( V_35 & V_106 ) {
F_3 ( V_10 , L_25
L_23 , V_23 , V_60 -> V_107 ?
L_8 : L_9 , V_60 -> V_108 ) ;
}
if ( V_35 & V_109 ) {
F_3 ( V_10 , L_26 , V_23 ,
V_60 -> V_110 ? L_8 : L_9 ) ;
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
F_3 ( V_10 , L_27 ) ;
if ( V_111 & V_116 )
F_3 ( V_10 , L_28 ) ;
if ( V_111 & V_117 )
F_3 ( V_10 , L_29 ) ;
if ( V_111 & V_118 )
F_3 ( V_10 , L_30 ) ;
if ( V_111 & V_119 )
F_3 ( V_10 , L_31 ) ;
if ( V_111 & V_120 )
F_3 ( V_10 , L_32 ) ;
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
F_3 ( V_2 -> V_10 , L_33 , V_23 ) ;
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
F_3 ( V_2 -> V_10 , L_34 , V_23 ,
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
F_3 ( V_2 -> V_10 , L_33 , V_23 ) ;
return 0 ;
}
static int
F_43 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_124 * V_125 )
{
struct V_142 * V_142 ;
int V_81 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_142 = (struct V_142 * ) V_125 -> V_143 ;
memset ( V_142 , 0 , sizeof( struct V_142 ) ) ;
for ( V_81 = 0 ; V_81 < V_144 ; V_81 ++ )
V_142 -> V_145 [ V_81 ] = 0xFFFF ;
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
F_3 ( V_6 -> V_10 , L_35 ,
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
F_2 ( V_6 ) ;
F_52 ( V_6 -> V_12 , V_169 , V_171 ,
( 1 << ( V_181 +
V_125 -> V_156 . V_158 ) ) - 1 ) ;
F_6 ( V_6 ) ;
break;
default:
F_3 ( V_6 -> V_10 , L_36 ,
V_23 ) ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
bool V_13 ;
F_2 ( V_6 ) ;
V_13 = F_54 ( V_6 -> V_12 ) ;
F_6 ( V_6 ) ;
F_55 ( V_6 -> V_8 -> V_14 -> V_10 , V_13 ) ;
}
static void F_56 ( struct V_1 * V_2 , bool V_182 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
F_57 ( L_37 , V_23 , V_182 ? L_8 : L_9 ) ;
F_2 ( V_6 ) ;
F_58 ( V_6 -> V_12 , V_182 ) ;
F_6 ( V_6 ) ;
}
static int F_59 ( struct V_5 * V_6 , char * V_183 )
{
return F_60 ( V_6 -> V_8 -> V_14 -> V_10 , V_183 ) ;
}
static struct V_5 * F_61 ( T_2 V_184 , T_2 V_185 ,
unsigned long V_186 ,
T_5 V_187 , void * V_188 , T_5 V_189 )
{
struct V_5 * V_6 = NULL ;
int V_190 , V_17 ;
unsigned long V_191 ;
struct V_1 * V_2 ;
T_4 V_192 [ V_193 ] ;
V_190 = V_194 ;
V_17 = 0 ;
if ( V_190 < 0 ) {
return NULL ;
}
V_2 = F_62 ( V_188 ) ;
if ( V_2 != NULL )
V_6 = V_2 -> V_7 ;
if ( F_47 ( V_2 == NULL ) || F_47 ( V_6 == NULL ) )
return NULL ;
V_6 -> V_10 = V_2 -> V_10 ;
F_63 ( & V_6 -> V_195 , 0 ) ;
F_64 ( & V_6 -> V_196 , V_197 , ( unsigned long ) V_6 ) ;
V_191 = V_186 ;
if ( V_187 == V_198 || V_187 == V_199 ) {
} else {
V_187 = V_198 ;
F_65 ( V_6 -> V_10 , L_38 ) ;
}
V_6 -> V_200 = V_187 ;
V_6 -> V_201 = F_66 ( V_191 , V_202 ) ;
if ( V_6 -> V_201 == NULL ) {
F_3 ( V_6 -> V_10 , L_39 , V_190 ) ;
goto V_203;
}
F_67 ( & V_6 -> V_204 ) ;
F_67 ( & V_6 -> V_205 ) ;
if ( F_68 ( V_6 , (struct V_206 * ) V_188 ) < 0 ) {
F_3 ( V_6 -> V_10 , L_40
L_41 , V_63 , L_42 ) ;
F_69 ( V_6 ) ;
F_70 ( (struct V_206 * ) V_188 ) ;
return NULL ;
}
V_6 -> V_12 = F_71 ( ( void * ) V_6 , V_184 , V_185 , V_190 , false ,
V_6 -> V_201 , V_6 -> V_200 , V_188 , & V_17 ) ;
F_69 ( V_6 ) ;
if ( ! V_6 -> V_12 ) {
F_3 ( V_6 -> V_10 , L_43 ,
V_63 , V_17 ) ;
goto V_203;
}
V_6 -> V_8 = F_72 ( V_6 -> V_12 ) ;
V_6 -> V_8 -> V_14 = V_2 ;
if ( F_21 ( V_6 -> V_12 , V_207 , 0 ) < 0 ) {
F_3 ( V_6 -> V_10 , L_44 ,
V_190 ) ;
}
if ( F_73 ( V_189 , V_208 , V_209 , V_63 , V_6 ) ) {
F_3 ( V_6 -> V_10 , L_45 , V_190 ) ;
goto V_203;
}
V_6 -> V_189 = V_189 ;
F_74 ( V_6 -> V_8 , L_46 , V_6 , V_210 , NULL ) ;
if ( F_75 ( V_2 ) ) {
F_3 ( V_6 -> V_10 , L_47 , V_190 ,
V_23 ) ;
goto V_203;
}
memcpy ( V_192 , & V_6 -> V_8 -> V_211 , V_193 ) ;
if ( F_47 ( ! F_76 ( V_192 ) ) )
goto V_203;
F_77 ( V_2 , V_192 ) ;
V_17 = F_78 ( V_2 ) ;
if ( V_17 ) {
F_3 ( V_6 -> V_10 , L_48
L_49 , V_23 , V_17 ) ;
}
if ( V_6 -> V_8 -> V_212 [ 0 ] )
V_17 = F_59 ( V_6 , V_6 -> V_8 -> V_212 ) ;
else
V_17 = F_59 ( V_6 , L_50 ) ;
if ( V_17 ) {
F_3 ( V_6 -> V_10 , L_51 ,
V_23 , V_17 ) ;
}
V_194 ++ ;
return V_6 ;
V_203:
F_79 ( V_6 ) ;
return NULL ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
int V_213 ;
char V_214 [ 4 ] ;
V_213 = 0 ;
V_2 -> V_10 -> V_87 [ V_215 ] = NULL ;
V_2 -> V_10 -> V_87 [ V_216 ] = NULL ;
if ( F_81 ( V_6 -> V_12 , V_217 , ( int * ) & V_214 ) < 0 )
F_3 ( V_2 -> V_10 , L_52 ) ;
if ( V_214 [ 0 ] == 'n' || V_214 [ 0 ] == 'c' ) {
if ( V_214 [ 0 ] == 'c' ) {
V_218 . V_156 . V_219 . V_220 [ 1 ] = 0 ;
V_218 . V_156 . V_219 . V_221 = 72 ;
}
V_2 -> V_10 -> V_87 [ V_215 ] = & V_218 ;
} else {
return - V_222 ;
}
if ( F_82 ( V_6 -> V_8 ) > 1 ) {
V_213 ++ ;
if ( V_214 [ 0 ] == 'n' || V_214 [ 0 ] == 'c' ) {
V_2 -> V_10 -> V_87 [ V_216 ] =
& V_223 ;
} else {
return - V_222 ;
}
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
V_2 -> V_44 = V_224
| V_225
| V_226 ;
V_2 -> V_227 = F_83 () ;
V_2 -> V_228 = V_229 ;
V_2 -> V_230 = 2 ;
V_2 -> V_231 = 7 * 1000 ;
V_2 -> V_10 -> V_232 = F_84 ( V_20 ) ;
V_2 -> V_233 = L_53 ;
V_2 -> V_234 = sizeof( struct V_142 ) ;
return F_80 ( V_2 ) ;
}
static int T_6
F_85 ( struct V_206 * V_235 , const struct V_236 * V_237 )
{
int V_238 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_1 V_61 ;
F_86 ( & V_235 -> V_239 , L_54 ,
V_235 -> V_240 -> V_241 , F_87 ( V_235 -> V_242 ) ,
F_88 ( V_235 -> V_242 ) , V_235 -> V_189 ) ;
if ( ( V_235 -> V_184 != V_243 ) ||
( ( V_235 -> V_185 != 0x0576 ) &&
( ( V_235 -> V_185 & 0xff00 ) != 0x4300 ) &&
( ( V_235 -> V_185 & 0xff00 ) != 0x4700 ) &&
( ( V_235 -> V_185 < 43000 ) || ( V_235 -> V_185 > 43999 ) ) ) )
return - V_244 ;
V_238 = F_89 ( V_235 ) ;
if ( V_238 ) {
F_90 ( L_55 ,
V_23 , V_235 -> V_240 -> V_241 , F_87 ( V_235 -> V_242 ) ,
F_88 ( V_235 -> V_242 ) ) ;
return - V_244 ;
}
F_91 ( V_235 ) ;
F_92 ( V_235 , 0x40 , & V_61 ) ;
if ( ( V_61 & 0x0000ff00 ) != 0 )
F_93 ( V_235 , 0x40 , V_61 & 0xffff00ff ) ;
V_2 = F_94 ( sizeof( struct V_5 ) , & V_245 ) ;
if ( ! V_2 ) {
F_90 ( L_56 , V_23 ) ;
return - V_246 ;
}
F_95 ( V_2 , & V_235 -> V_239 ) ;
F_96 ( V_235 , V_2 ) ;
memset ( V_2 -> V_7 , 0 , sizeof( * V_6 ) ) ;
V_6 = F_61 ( V_235 -> V_184 , V_235 -> V_185 ,
F_97 ( V_235 , 0 ) , V_198 , V_235 ,
V_235 -> V_189 ) ;
if ( ! V_6 ) {
F_90 ( L_57 , V_63 ,
V_23 ) ;
return - V_244 ;
}
return 0 ;
}
static int F_98 ( struct V_206 * V_235 , T_7 V_247 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_62 ( V_235 ) ;
V_6 = F_14 ( V_2 ) ;
if ( ! V_6 ) {
F_3 ( V_6 -> V_10 ,
L_58 ) ;
return - V_244 ;
}
F_2 ( V_6 ) ;
V_6 -> V_8 -> V_248 = false ;
F_6 ( V_6 ) ;
F_99 ( V_235 ) ;
F_100 ( V_235 ) ;
return F_101 ( V_235 , V_249 ) ;
}
static int F_102 ( struct V_206 * V_235 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_17 = 0 ;
T_1 V_61 ;
V_2 = F_62 ( V_235 ) ;
V_6 = F_14 ( V_2 ) ;
if ( ! V_6 ) {
F_3 ( V_6 -> V_10 ,
L_59 ) ;
return - V_244 ;
}
V_17 = F_101 ( V_235 , V_250 ) ;
if ( V_17 )
return V_17 ;
F_103 ( V_235 ) ;
V_17 = F_89 ( V_235 ) ;
if ( V_17 )
return V_17 ;
F_91 ( V_235 ) ;
F_92 ( V_235 , 0x40 , & V_61 ) ;
if ( ( V_61 & 0x0000ff00 ) != 0 )
F_93 ( V_235 , 0x40 , V_61 & 0xffff00ff ) ;
return V_17 ;
}
static void F_70 ( struct V_206 * V_235 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_172 ;
V_2 = F_62 ( V_235 ) ;
V_6 = F_14 ( V_2 ) ;
if ( ! V_6 ) {
F_90 ( L_60 ) ;
return;
}
F_2 ( V_6 ) ;
V_172 = F_104 ( V_235 -> V_184 , V_235 -> V_185 ) ;
F_6 ( V_6 ) ;
if ( ! V_172 ) {
F_3 ( V_6 -> V_10 , L_61
L_62 ) ;
return;
}
if ( V_6 -> V_12 ) {
F_55 ( V_6 -> V_8 -> V_14 -> V_10 , false ) ;
F_10 ( V_6 -> V_8 -> V_14 -> V_10 ) ;
F_105 ( V_2 ) ;
F_2 ( V_6 ) ;
F_17 ( V_6 ) ;
F_6 ( V_6 ) ;
}
F_100 ( V_235 ) ;
F_79 ( V_6 ) ;
F_96 ( V_235 , NULL ) ;
F_106 ( V_2 ) ;
}
static int T_8 F_107 ( void )
{
int error = - V_244 ;
#ifdef F_108
if ( V_251 != 0xdeadbeef )
V_252 = V_251 ;
if ( V_253 != 0xdeadbeef )
V_254 = V_253 ;
#endif
error = F_109 ( & V_255 ) ;
if ( ! error )
return 0 ;
return error ;
}
static void T_9 F_110 ( void )
{
F_111 ( & V_255 ) ;
}
static void F_79 ( struct V_5 * V_6 )
{
struct V_256 * V_257 , * V_258 ;
if ( V_6 -> V_259 . V_260 )
F_112 () ;
if ( V_6 -> V_189 )
F_113 ( V_6 -> V_189 , V_6 ) ;
F_114 ( & V_6 -> V_196 ) ;
if ( V_6 -> V_8 ) {
F_115 ( V_6 -> V_8 , L_46 , V_6 ) ;
}
if ( V_6 -> V_12 ) {
F_116 ( V_6 -> V_12 ) ;
V_6 -> V_12 = NULL ;
V_6 -> V_8 = NULL ;
}
while ( F_117 ( & V_6 -> V_195 ) > 0 )
F_118 () ;
for ( V_257 = V_6 -> V_261 ; V_257 ; V_257 = V_258 ) {
V_258 = V_257 -> V_258 ;
#ifdef F_108
F_119 ( V_257 -> V_262 ) ;
#endif
F_119 ( V_257 ) ;
}
if ( V_6 -> V_201 && V_6 -> V_200 != V_263 &&
V_6 -> V_200 != V_264 ) {
F_120 ( ( void * ) V_6 -> V_201 ) ;
}
V_6 -> V_201 = NULL ;
}
static void F_28 ( struct V_83 * V_84 , T_2 V_82 , bool V_265 )
{
T_1 V_81 ;
for ( V_81 = 0 ; V_81 < V_84 -> V_266 ; V_81 ++ ) {
if ( V_82 != ( V_84 -> V_267 [ V_81 ] & 0x7f ) )
continue;
if ( V_265 )
V_84 -> V_267 [ V_81 ] |= V_268 ;
else
V_84 -> V_267 [ V_81 ] &= V_269 ;
return;
}
}
void F_121 ( struct V_5 * V_6 , struct V_270 * V_271 ,
bool V_247 , int V_272 )
{
F_3 ( V_6 -> V_10 , L_63 , V_23 ) ;
}
void F_122 ( struct V_5 * V_6 )
{
F_65 ( F_123 ( V_6 ) -> V_10 , L_64 , V_6 -> V_8 -> V_190 ) ;
F_124 ( V_6 ) ;
F_125 ( V_6 -> V_12 ) ;
}
T_5 F_124 ( struct V_5 * V_6 )
{
F_65 ( F_123 ( V_6 ) -> V_10 , L_64 , V_6 -> V_8 -> V_190 ) ;
F_126 ( V_6 -> V_12 ) ;
V_6 -> V_273 = 0 ;
return 0 ;
}
void F_127 ( struct V_5 * V_6 )
{
unsigned long V_44 ;
F_128 ( V_6 , V_44 ) ;
F_129 ( V_6 -> V_12 ) ;
F_130 ( V_6 , V_44 ) ;
}
bool F_131 ( struct V_5 * V_6 , T_5 V_274 )
{
return true ;
}
T_1 F_132 ( struct V_5 * V_6 )
{
unsigned long V_44 ;
T_1 V_172 ;
F_128 ( V_6 , V_44 ) ;
V_172 = F_133 ( V_6 -> V_12 ) ;
F_130 ( V_6 , V_44 ) ;
return V_172 ;
}
void F_134 ( struct V_5 * V_6 , T_1 V_275 )
{
unsigned long V_44 ;
F_128 ( V_6 , V_44 ) ;
F_135 ( V_6 -> V_12 , V_275 ) ;
F_130 ( V_6 , V_44 ) ;
}
int F_15 ( struct V_5 * V_6 )
{
int error = 0 ;
if ( V_6 -> V_8 -> V_9 )
return 0 ;
error = F_136 ( V_6 -> V_12 ) ;
return error ;
}
void F_17 ( struct V_5 * V_6 )
{
T_5 V_195 , V_276 = 0 ;
V_276 = F_137 ( V_6 -> V_12 ) ;
V_195 = F_117 ( & V_6 -> V_195 ) - V_276 ;
F_6 ( V_6 ) ;
F_138 ( ( F_117 ( & V_6 -> V_195 ) > V_195 ) , 100 * 1000 ) ;
F_2 ( V_6 ) ;
}
static T_10 V_208 ( int V_189 , void * V_277 )
{
struct V_5 * V_6 ;
bool V_278 , V_279 ;
unsigned long V_44 ;
V_6 = (struct V_5 * ) V_277 ;
F_139 ( V_6 , V_44 ) ;
V_278 = F_140 ( V_6 -> V_12 , & V_279 ) ;
if ( V_278 ) {
if ( V_279 ) {
F_141 ( & V_6 -> V_196 ) ;
}
}
F_142 ( V_6 , V_44 ) ;
return F_143 ( V_278 ) ;
}
static void V_197 ( unsigned long V_280 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_280 ;
F_2 ( V_6 ) ;
if ( V_6 -> V_8 -> V_9 ) {
if ( V_6 -> V_273 ) {
unsigned long V_44 ;
F_128 ( V_6 , V_44 ) ;
F_144 ( V_6 -> V_12 ) ;
F_130 ( V_6 , V_44 ) ;
}
V_6 -> V_273 = F_145 ( V_6 -> V_12 , true ) ;
}
if ( ! V_6 -> V_8 -> V_9 )
goto V_11;
if ( V_6 -> V_273 )
F_141 ( & V_6 -> V_196 ) ;
else {
F_127 ( V_6 ) ;
}
V_11:
F_6 ( V_6 ) ;
}
static void V_256 ( unsigned long V_280 )
{
F_146 ( (struct V_256 * ) V_280 ) ;
}
static void F_146 ( struct V_256 * V_257 )
{
F_2 ( V_257 -> V_6 ) ;
if ( V_257 -> V_126 ) {
if ( V_257 -> V_281 ) {
V_257 -> V_282 . V_283 = V_284 + V_257 -> V_285 * V_286 / 1000 ;
F_147 ( & V_257 -> V_6 -> V_195 ) ;
F_148 ( & V_257 -> V_282 ) ;
V_257 -> V_126 = true ;
} else
V_257 -> V_126 = false ;
V_257 -> V_287 ( V_257 -> V_288 ) ;
}
F_149 ( & V_257 -> V_6 -> V_195 ) ;
F_6 ( V_257 -> V_6 ) ;
}
struct V_256 * F_150 ( struct V_5 * V_6 ,
void (* V_287) ( void * V_288 ) ,
void * V_288 , const char * V_262 )
{
struct V_256 * V_257 ;
V_257 = F_151 ( sizeof( struct V_256 ) , V_289 ) ;
if ( ! V_257 ) {
F_3 ( V_6 -> V_10 , L_65 ,
V_6 -> V_8 -> V_190 ) ;
return 0 ;
}
F_152 ( & V_257 -> V_282 ) ;
V_257 -> V_282 . V_280 = ( unsigned long ) V_257 ;
V_257 -> V_282 . V_290 = V_256 ;
V_257 -> V_6 = V_6 ;
V_257 -> V_287 = V_287 ;
V_257 -> V_288 = V_288 ;
V_257 -> V_258 = V_6 -> V_261 ;
V_6 -> V_261 = V_257 ;
#ifdef F_108
V_257 -> V_262 = F_153 ( strlen ( V_262 ) + 1 , V_289 ) ;
if ( V_257 -> V_262 )
strcpy ( V_257 -> V_262 , V_262 ) ;
#endif
return V_257 ;
}
void F_154 ( struct V_5 * V_6 , struct V_256 * V_257 , T_5 V_285 ,
int V_281 )
{
#ifdef F_108
if ( V_257 -> V_126 ) {
F_3 ( V_6 -> V_10 , L_66 ,
V_23 , V_257 -> V_262 , V_281 ) ;
}
#endif
V_257 -> V_285 = V_285 ;
V_257 -> V_281 = ( bool ) V_281 ;
V_257 -> V_126 = true ;
V_257 -> V_282 . V_283 = V_284 + V_285 * V_286 / 1000 ;
F_147 ( & V_6 -> V_195 ) ;
F_148 ( & V_257 -> V_282 ) ;
}
bool F_155 ( struct V_5 * V_6 , struct V_256 * V_257 )
{
if ( V_257 -> V_126 ) {
V_257 -> V_126 = false ;
if ( ! F_156 ( & V_257 -> V_282 ) ) {
return false ;
}
F_149 ( & V_6 -> V_195 ) ;
}
return true ;
}
void F_157 ( struct V_5 * V_6 , struct V_256 * V_257 )
{
struct V_256 * V_291 ;
F_155 ( V_6 , V_257 ) ;
if ( V_6 -> V_261 == V_257 ) {
V_6 -> V_261 = V_6 -> V_261 -> V_258 ;
#ifdef F_108
F_119 ( V_257 -> V_262 ) ;
#endif
F_119 ( V_257 ) ;
return;
}
V_291 = V_6 -> V_261 ;
while ( V_291 ) {
if ( V_291 -> V_258 == V_257 ) {
V_291 -> V_258 = V_257 -> V_258 ;
#ifdef F_108
F_119 ( V_257 -> V_262 ) ;
#endif
F_119 ( V_257 ) ;
return;
}
V_291 = V_291 -> V_258 ;
}
}
static int V_210 ( void * V_292 )
{
return 0 ;
}
int F_158 ( struct V_5 * V_6 , void * * V_293 , T_1 V_294 )
{
int V_81 , V_295 ;
const T_4 * V_296 ;
struct V_297 * V_298 ;
for ( V_81 = 0 ; V_81 < V_6 -> V_259 . V_260 ; V_81 ++ ) {
V_298 = (struct V_297 * ) V_6 -> V_259 . V_299 [ V_81 ] -> V_280 ;
for ( V_295 = 0 ; V_295 < V_6 -> V_259 . V_300 [ V_81 ] ;
V_295 ++ , V_298 ++ ) {
if ( V_298 -> V_294 == V_294 ) {
V_296 = V_6 -> V_259 . V_301 [ V_81 ] -> V_280 + V_298 -> V_302 ;
* V_293 = F_153 ( V_298 -> V_303 , V_289 ) ;
if ( * V_293 == NULL ) {
F_3 ( V_6 -> V_10 , L_67
L_68 , V_298 -> V_303 ) ;
goto V_203;
}
memcpy ( * V_293 , V_296 , V_298 -> V_303 ) ;
return 0 ;
}
}
}
F_3 ( V_6 -> V_10 , L_69 ,
V_294 ) ;
* V_293 = NULL ;
V_203:
return - V_304 ;
}
int F_159 ( struct V_5 * V_6 , T_1 * V_280 , T_1 V_294 )
{
int V_81 , V_295 ;
const T_4 * V_296 ;
struct V_297 * V_298 ;
for ( V_81 = 0 ; V_81 < V_6 -> V_259 . V_260 ; V_81 ++ ) {
V_298 = (struct V_297 * ) V_6 -> V_259 . V_299 [ V_81 ] -> V_280 ;
for ( V_295 = 0 ; V_295 < V_6 -> V_259 . V_300 [ V_81 ] ;
V_295 ++ , V_298 ++ ) {
if ( V_298 -> V_294 == V_294 ) {
V_296 = V_6 -> V_259 . V_301 [ V_81 ] -> V_280 + V_298 -> V_302 ;
if ( V_298 -> V_303 != 4 ) {
F_3 ( V_6 -> V_10 ,
L_70 ) ;
return - V_305 ;
}
* V_280 = * ( ( T_1 * ) V_296 ) ;
return 0 ;
}
}
}
F_3 ( V_6 -> V_10 , L_71 , V_294 ) ;
return - V_305 ;
}
static int F_68 ( struct V_5 * V_6 , struct V_206 * V_235 )
{
int V_172 ;
struct V_185 * V_185 = & V_235 -> V_239 ;
char V_306 [ 100 ] ;
int V_81 ;
memset ( ( void * ) & V_6 -> V_259 , 0 , sizeof( struct V_307 ) ) ;
for ( V_81 = 0 ; V_81 < V_308 ; V_81 ++ ) {
if ( V_309 [ V_81 ] == NULL )
break;
sprintf ( V_306 , L_72 , V_309 [ V_81 ] ,
V_310 ) ;
V_172 = F_160 ( & V_6 -> V_259 . V_301 [ V_81 ] , V_306 , V_185 ) ;
if ( V_172 ) {
F_3 ( V_6 -> V_10 , L_73 ,
V_63 , V_306 ) ;
return V_172 ;
}
sprintf ( V_306 , L_74 , V_309 [ V_81 ] ,
V_310 ) ;
V_172 = F_160 ( & V_6 -> V_259 . V_299 [ V_81 ] , V_306 , V_185 ) ;
if ( V_172 ) {
F_3 ( V_6 -> V_10 , L_73 ,
V_63 , V_306 ) ;
return V_172 ;
}
V_6 -> V_259 . V_300 [ V_81 ] =
V_6 -> V_259 . V_299 [ V_81 ] -> V_311 / ( sizeof( struct V_297 ) ) ;
}
V_6 -> V_259 . V_260 = V_81 ;
return F_161 ( V_6 ) ;
}
void F_162 ( void * V_312 )
{
F_119 ( V_312 ) ;
}
static void F_69 ( struct V_5 * V_6 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_308 ; V_81 ++ ) {
F_163 ( V_6 -> V_259 . V_301 [ V_81 ] ) ;
F_163 ( V_6 -> V_259 . V_299 [ V_81 ] ) ;
}
}
int F_164 ( struct V_5 * V_6 )
{
int V_81 ;
int V_295 ;
int V_238 = 0 ;
const struct V_313 * V_259 ;
const struct V_313 * V_299 ;
struct V_297 * V_314 ;
for ( V_81 = 0 ; V_81 < V_308 && V_238 == 0 ; V_81 ++ ) {
V_259 = V_6 -> V_259 . V_301 [ V_81 ] ;
V_299 = V_6 -> V_259 . V_299 [ V_81 ] ;
if ( V_259 == NULL && V_299 == NULL ) {
break;
} else if ( V_259 == NULL || V_299 == NULL ) {
F_3 ( V_6 -> V_10 , L_75 ,
V_23 ) ;
V_238 = - V_315 ;
} else if ( V_299 -> V_311 % sizeof( struct V_297 ) ) {
F_3 ( V_6 -> V_10 , L_76
L_77 , V_23 , V_299 -> V_311 ,
sizeof( struct V_297 ) ) ;
V_238 = - V_315 ;
} else if ( V_259 -> V_311 < V_316 || V_259 -> V_311 > V_317 ) {
F_3 ( V_6 -> V_10 , L_78
L_79 , V_23 , V_259 -> V_311 ) ;
V_238 = - V_315 ;
} else {
V_314 = (struct V_297 * ) V_299 -> V_280 ;
for ( V_295 = 0 ; V_295 < V_6 -> V_259 . V_300 [ V_81 ] &&
! V_238 ; V_295 ++ , V_314 ++ ) {
if ( V_314 -> V_302 + V_314 -> V_303 >
V_259 -> V_311 ) {
F_3 ( V_6 -> V_10 ,
L_80 ,
V_23 ) ;
V_238 = - V_315 ;
}
}
}
}
if ( V_238 == 0 && V_6 -> V_259 . V_260 != V_81 ) {
F_3 ( V_6 -> V_10 , L_81 , V_23 ,
V_6 -> V_259 . V_260 ) ;
V_238 = - V_315 ;
}
return V_238 ;
}
bool F_9 ( struct V_5 * V_6 )
{
bool V_13 = F_54 ( V_6 -> V_12 ) ;
F_6 ( V_6 ) ;
F_55 ( V_6 -> V_8 -> V_14 -> V_10 , V_13 ) ;
if ( V_13 )
F_165 ( V_6 -> V_8 -> V_14 -> V_10 ) ;
F_2 ( V_6 ) ;
return V_13 ;
}
void F_166 ( struct V_5 * V_6 , T_5 V_285 )
{
F_6 ( V_6 ) ;
F_167 ( V_285 ) ;
F_2 ( V_6 ) ;
}
