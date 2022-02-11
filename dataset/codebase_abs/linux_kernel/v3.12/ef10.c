static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , & V_3 , V_4 ) ;
return F_3 ( V_3 , V_5 ) == 0xb007 ?
F_3 ( V_3 , V_6 ) : - V_7 ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
return F_5 ( & V_2 -> V_8 -> V_9 [ V_10 ] ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( V_11 , V_12 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 V_15 ;
int V_16 ;
F_8 ( V_17 != 0 ) ;
V_16 = F_9 ( V_2 , V_18 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < sizeof( V_11 ) ) {
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_1 ) ;
return - V_7 ;
}
V_14 -> V_21 =
F_11 ( V_11 , V_22 ) ;
if ( ! ( V_14 -> V_21 &
( 1 << V_23 ) ) ) {
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_2 ) ;
return - V_24 ;
}
if ( ! ( V_14 -> V_21 &
( 1 << V_25 ) ) ) {
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_3 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_7 ( V_11 , V_27 ) ;
int V_16 ;
V_16 = F_9 ( V_2 , V_28 , NULL , 0 ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_16 )
return V_16 ;
V_16 = F_11 ( V_11 , V_29 ) ;
return V_16 > 0 ? V_16 : - V_30 ;
}
static int F_13 ( struct V_1 * V_2 , T_3 * V_31 )
{
F_7 ( V_11 , V_32 ) ;
T_2 V_15 ;
int V_16 ;
F_8 ( V_33 != 0 ) ;
V_16 = F_9 ( V_2 , V_34 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_32 )
return - V_7 ;
memcpy ( V_31 ,
F_14 ( V_11 , V_35 ) , V_36 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_37 , V_16 ;
V_2 -> V_38 =
F_16 (unsigned int,
EFX_MAX_CHANNELS,
resource_size(&efx->pci_dev->resource[EFX_MEM_BAR]) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
F_17 ( V_2 -> V_38 == 0 ) ;
V_14 = F_18 ( sizeof( * V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_40 ;
V_2 -> V_14 = V_14 ;
V_16 = F_19 ( V_2 , & V_14 -> V_41 ,
8 + V_42 , V_39 ) ;
if ( V_16 )
goto V_43;
V_37 = 0 ;
for (; ; ) {
V_16 = F_1 ( V_2 ) ;
if ( V_16 >= 0 )
break;
if ( ++ V_37 == 5 )
goto V_44;
F_20 ( 1 ) ;
}
V_14 -> V_45 = V_16 ;
V_14 -> V_46 = V_47 ;
F_21 ( V_2 , F_22 ( 1 ) , V_48 ) ;
V_16 = F_23 ( V_2 ) ;
if ( V_16 )
goto V_44;
V_16 = F_24 ( V_2 , V_49 ) ;
if ( V_16 )
goto V_50;
V_16 = F_25 ( V_2 , true , false , 0 ) ;
if ( V_16 )
goto V_50;
V_16 = F_6 ( V_2 ) ;
if ( V_16 < 0 )
goto V_50;
V_2 -> V_51 =
V_52 - V_53 ;
V_16 = F_26 ( V_2 ) ;
if ( V_16 < 0 )
goto V_50;
V_2 -> V_54 = V_16 ;
V_16 = F_13 ( V_2 , V_2 -> V_20 -> V_55 ) ;
if ( V_16 )
goto V_50;
V_16 = F_12 ( V_2 ) ;
if ( V_16 < 0 )
goto V_50;
V_2 -> V_56 = 1536000 / V_16 ;
V_16 = F_27 ( V_2 , V_57 , true ) ;
if ( V_16 == 0 )
V_14 -> V_58 = true ;
else if ( V_16 != - V_59 && V_16 != - V_60 )
goto V_50;
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_4 ,
V_14 -> V_58 ? L_5 : L_6 ) ;
V_16 = F_29 ( V_2 ) ;
if ( V_16 )
goto V_50;
return 0 ;
V_50:
F_30 ( V_2 ) ;
V_44:
F_31 ( V_2 , & V_14 -> V_41 ) ;
V_43:
F_32 ( V_14 ) ;
V_2 -> V_14 = NULL ;
return V_16 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_16 = F_9 ( V_2 , V_61 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_16 == - V_62 )
V_16 = 0 ;
return V_16 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
V_16 = F_33 ( V_2 ) ;
F_37 ( V_16 != 0 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 , & V_14 -> V_41 ) ;
F_32 ( V_14 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned int V_63 , unsigned int V_64 )
{
F_7 ( V_65 , V_66 ) ;
F_7 ( V_11 , V_67 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_65 , V_68 , V_63 ) ;
F_39 ( V_65 , V_69 , V_64 ) ;
V_16 = F_9 ( V_2 , V_70 , V_65 , sizeof( V_65 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_67 )
return - V_7 ;
F_28 ( V_2 , V_19 , V_2 -> V_20 , L_7 ,
F_11 ( V_11 , V_71 ) ) ;
V_14 -> V_72 = F_11 ( V_11 , V_71 ) ;
V_14 -> V_73 = F_11 ( V_11 , V_74 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
unsigned int V_75 =
F_41 ( V_2 -> V_76 , V_2 -> V_77 * V_78 ) ;
return F_38 ( V_2 , V_75 , V_75 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
if ( V_14 -> V_79 ) {
V_16 = F_6 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_79 = false ;
}
if ( V_14 -> V_80 ) {
V_16 = F_38 ( V_2 , V_14 -> V_73 ,
V_14 -> V_73 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_80 = false ;
}
F_43 ( V_2 ) ;
return 0 ;
}
static int F_44 ( T_4 * V_81 )
{
enum {
V_82 = ( ( V_83 | V_84 ) <<
V_85 ) ,
V_86 = ( ( V_87 | V_88 |
V_89 | V_83 |
V_84 | V_90 ) <<
V_85 )
};
if ( ( * V_81 & V_86 ) == V_86 ) {
* V_81 &= ~ V_86 ;
return V_91 ;
}
if ( ( * V_81 & V_82 ) == V_82 ) {
* V_81 &= ~ V_82 ;
return V_49 ;
}
return - V_92 ;
}
static T_5 F_45 ( struct V_1 * V_2 )
{
T_5 V_93 = V_94 ;
T_4 V_95 = F_46 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_95 & ( 1 << V_96 ) )
V_93 |= V_97 ;
else
V_93 |= V_98 ;
if ( V_14 -> V_21 &
( 1 << V_99 ) )
V_93 |= V_100 ;
return V_93 ;
}
static void F_47 ( struct V_1 * V_2 , unsigned long * V_101 )
{
T_5 V_93 = F_45 ( V_2 ) ;
#if V_102 == 64
V_101 [ 0 ] = V_93 ;
#else
V_101 [ 0 ] = V_93 & 0xffffffff ;
V_101 [ 1 ] = V_93 >> 32 ;
#endif
}
static T_2 F_48 ( struct V_1 * V_2 , T_3 * V_103 )
{
F_49 ( V_101 , V_104 ) ;
F_47 ( V_2 , V_101 ) ;
return F_50 ( V_105 , V_104 ,
V_101 , V_103 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_49 ( V_101 , V_104 ) ;
T_6 V_106 , V_107 ;
T_5 * V_108 = V_14 -> V_108 ;
T_6 * V_109 ;
F_47 ( V_2 , V_101 ) ;
V_109 = V_2 -> V_110 . V_111 ;
V_14 = V_2 -> V_14 ;
V_107 = V_109 [ V_112 ] ;
if ( V_107 == V_113 )
return 0 ;
F_52 () ;
F_53 ( V_105 , V_104 , V_101 ,
V_108 , V_2 -> V_110 . V_111 , false ) ;
F_52 () ;
V_106 = V_109 [ V_114 ] ;
if ( V_107 != V_106 )
return - V_115 ;
V_108 [ V_116 ] =
V_108 [ V_117 ] -
V_108 [ V_118 ] ;
F_54 ( & V_108 [ V_119 ] ,
V_108 [ V_118 ] ) ;
return 0 ;
}
static T_2 F_55 ( struct V_1 * V_2 , T_5 * V_120 ,
struct V_121 * V_122 )
{
F_49 ( V_101 , V_104 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_5 * V_108 = V_14 -> V_108 ;
T_2 V_123 = 0 , V_124 ;
int V_125 ;
F_47 ( V_2 , V_101 ) ;
for ( V_125 = 0 ; V_125 < 100 ; ++ V_125 ) {
if ( F_51 ( V_2 ) == 0 )
break;
F_56 ( 100 ) ;
}
if ( V_120 ) {
F_57 (index, mask, EF10_STAT_COUNT) {
if ( V_105 [ V_124 ] . V_126 ) {
* V_120 ++ = V_108 [ V_124 ] ;
++ V_123 ;
}
}
}
if ( V_122 ) {
V_122 -> V_127 = V_108 [ V_128 ] ;
V_122 -> V_129 = V_108 [ V_130 ] ;
V_122 -> V_131 = V_108 [ V_117 ] ;
V_122 -> V_132 = V_108 [ V_133 ] ;
V_122 -> V_134 = V_108 [ V_135 ] ;
V_122 -> V_136 = V_108 [ V_137 ] ;
V_122 -> V_138 =
V_108 [ V_139 ] +
V_108 [ V_140 ] ;
V_122 -> V_141 = V_108 [ V_142 ] ;
V_122 -> V_143 = V_108 [ V_144 ] ;
V_122 -> V_145 = V_108 [ V_146 ] ;
V_122 -> V_147 = ( V_122 -> V_138 +
V_122 -> V_141 +
V_122 -> V_143 ) ;
}
return V_123 ;
}
static void F_58 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = V_149 -> V_2 ;
unsigned int V_150 , V_151 ;
T_1 V_152 ;
if ( V_149 -> V_153 ) {
V_150 = 3 ;
V_151 = V_149 -> V_153 - 1 ;
} else {
V_150 = 0 ;
V_151 = 0 ;
}
if ( F_59 ( V_2 ) ) {
F_60 ( V_152 , V_154 ,
V_155 ,
V_156 , V_150 ,
V_157 , V_151 ) ;
F_61 ( V_2 , & V_152 , V_158 ,
V_149 -> V_149 ) ;
} else {
F_62 ( V_152 , V_159 , V_150 ,
V_160 , V_151 ) ;
F_61 ( V_2 , & V_152 , V_161 ,
V_149 -> V_149 ) ;
}
}
static void F_63 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
V_163 -> V_164 = 0 ;
V_163 -> V_165 = 0 ;
memset ( & V_163 -> V_166 , 0 , sizeof( V_163 -> V_166 ) ) ;
}
static int F_64 ( struct V_1 * V_2 , T_4 type )
{
if ( type != 0 )
return - V_92 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 ,
const T_1 * V_167 , T_2 V_168 ,
const T_1 * V_169 , T_2 V_170 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_3 * V_171 = V_14 -> V_41 . V_111 ;
memcpy ( V_171 , V_167 , V_168 ) ;
memcpy ( V_171 + V_168 , V_169 , V_170 ) ;
F_66 () ;
F_21 ( V_2 , F_22 ( ( T_5 ) V_14 -> V_41 . V_172 >> 32 ) ,
V_173 ) ;
F_21 ( V_2 , F_22 ( ( T_4 ) V_14 -> V_41 . V_172 ) ,
V_48 ) ;
}
static bool F_67 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const T_1 V_167 = * ( const T_1 * ) V_14 -> V_41 . V_111 ;
F_52 () ;
return F_3 ( V_167 , V_174 ) ;
}
static void
F_68 ( struct V_1 * V_2 , T_1 * V_11 ,
T_2 V_175 , T_2 V_15 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const T_3 * V_171 = V_14 -> V_41 . V_111 ;
memcpy ( V_11 , V_171 + V_175 , V_15 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
V_16 = F_1 ( V_2 ) ;
if ( V_16 < 0 ) {
return 0 ;
}
if ( V_16 == V_14 -> V_45 )
return 0 ;
V_14 -> V_45 = V_16 ;
V_14 -> V_80 = true ;
V_14 -> V_176 = true ;
V_14 -> V_46 = V_47 ;
V_14 -> V_79 = true ;
V_14 -> V_108 [ V_119 ] = 0 ;
return - V_7 ;
}
static T_7 F_70 ( int V_177 , void * V_178 )
{
struct V_179 * V_180 = V_178 ;
struct V_1 * V_2 = V_180 -> V_2 ;
F_71 ( V_2 , V_181 , V_2 -> V_20 ,
L_8 , V_177 , F_72 () ) ;
if ( F_73 ( F_74 ( V_2 -> V_182 ) ) ) {
if ( V_180 -> V_124 == V_2 -> V_183 )
V_2 -> V_184 = F_72 () ;
F_75 ( V_2 -> V_149 [ V_180 -> V_124 ] ) ;
}
return V_185 ;
}
static T_7 F_76 ( int V_177 , void * V_178 )
{
struct V_1 * V_2 = V_178 ;
bool V_186 = F_74 ( V_2 -> V_182 ) ;
struct V_148 * V_149 ;
T_1 V_3 ;
T_4 V_187 ;
F_2 ( V_2 , & V_3 , V_188 ) ;
V_187 = F_3 ( V_3 , V_189 ) ;
if ( V_187 == 0 )
return V_190 ;
if ( F_73 ( V_186 ) ) {
if ( V_187 & ( 1U << V_2 -> V_183 ) )
V_2 -> V_184 = F_72 () ;
F_77 (channel, efx) {
if ( V_187 & 1 )
F_75 ( V_149 ) ;
V_187 >>= 1 ;
}
}
F_71 ( V_2 , V_181 , V_2 -> V_20 ,
L_9 V_191 L_10 ,
V_177 , F_72 () , F_78 ( V_3 ) ) ;
return V_185 ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_7 ( V_65 , V_192 ) ;
F_8 ( V_193 != 0 ) ;
F_39 ( V_65 , V_194 , V_2 -> V_183 ) ;
( void ) F_9 ( V_2 , V_195 ,
V_65 , sizeof( V_65 ) , NULL , 0 , NULL ) ;
}
static int F_80 ( struct V_196 * V_197 )
{
return F_19 ( V_197 -> V_2 , & V_197 -> V_198 . V_199 ,
( V_197 -> V_200 + 1 ) *
sizeof( V_201 ) ,
V_39 ) ;
}
static inline void F_81 ( struct V_196 * V_197 ,
const V_201 * V_198 )
{
unsigned int V_202 ;
T_8 V_3 ;
V_202 = V_197 -> V_203 & V_197 -> V_200 ;
F_82 ( V_3 , V_204 , V_202 ) ;
V_3 . V_205 [ 0 ] = * V_198 ;
F_83 ( V_197 -> V_2 , & V_3 ,
V_206 , V_197 -> V_207 ) ;
}
static void F_84 ( struct V_196 * V_197 )
{
F_7 ( V_65 , F_85 ( V_208 * 8 /
V_209 ) ) ;
F_7 ( V_11 , V_210 ) ;
bool V_211 = V_197 -> V_207 & V_212 ;
T_2 V_213 = V_197 -> V_198 . V_199 . V_214 / V_209 ;
struct V_148 * V_149 = V_197 -> V_149 ;
struct V_1 * V_2 = V_197 -> V_2 ;
T_2 V_215 , V_15 ;
T_9 V_172 ;
V_201 * V_198 ;
int V_16 ;
int V_37 ;
F_39 ( V_65 , V_216 , V_197 -> V_200 + 1 ) ;
F_39 ( V_65 , V_217 , V_149 -> V_149 ) ;
F_39 ( V_65 , V_218 , V_197 -> V_207 ) ;
F_39 ( V_65 , V_219 , V_197 -> V_207 ) ;
F_86 ( V_65 , V_220 ,
V_221 , ! V_211 ,
V_222 , ! V_211 ) ;
F_39 ( V_65 , V_223 , 0 ) ;
F_39 ( V_65 , V_224 , V_225 ) ;
V_172 = V_197 -> V_198 . V_199 . V_172 ;
F_28 ( V_2 , V_226 , V_2 -> V_20 , L_11 ,
V_197 -> V_207 , V_213 , ( T_5 ) V_172 ) ;
for ( V_37 = 0 ; V_37 < V_213 ; ++ V_37 ) {
F_87 ( V_65 , V_227 , V_37 , V_172 ) ;
V_172 += V_209 ;
}
V_215 = F_85 ( V_213 ) ;
V_16 = F_9 ( V_2 , V_228 , V_65 , V_215 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
goto V_229;
V_197 -> V_230 [ 0 ] . V_81 = V_231 ;
V_197 -> V_232 = 1 ;
V_198 = F_88 ( V_197 , 0 ) ;
F_89 ( * V_198 ,
V_233 , true ,
V_234 ,
V_235 ,
V_236 , V_211 ,
V_237 , V_211 ) ;
V_197 -> V_203 = 1 ;
F_66 () ;
F_81 ( V_197 , V_198 ) ;
return;
V_229:
F_37 ( true ) ;
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_12 , V_238 , V_16 ) ;
}
static void F_90 ( struct V_196 * V_197 )
{
F_7 ( V_65 , V_239 ) ;
F_7 ( V_11 , V_240 ) ;
struct V_1 * V_2 = V_197 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_65 , V_241 ,
V_197 -> V_207 ) ;
V_16 = F_9 ( V_2 , V_242 , V_65 , sizeof( V_65 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_229;
return;
V_229:
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_12 , V_238 , V_16 ) ;
}
static void F_91 ( struct V_196 * V_197 )
{
F_31 ( V_197 -> V_2 , & V_197 -> V_198 . V_199 ) ;
}
static inline void F_92 ( struct V_196 * V_197 )
{
unsigned int V_202 ;
T_1 V_3 ;
V_202 = V_197 -> V_203 & V_197 -> V_200 ;
F_93 ( V_3 , V_243 , V_202 ) ;
F_61 ( V_197 -> V_2 , & V_3 ,
V_244 , V_197 -> V_207 ) ;
}
static void F_94 ( struct V_196 * V_197 )
{
unsigned int V_245 = V_197 -> V_203 ;
struct V_246 * V_230 ;
unsigned int V_202 ;
V_201 * V_198 ;
F_17 ( V_197 -> V_203 == V_197 -> V_232 ) ;
do {
V_202 = V_197 -> V_203 & V_197 -> V_200 ;
V_230 = & V_197 -> V_230 [ V_202 ] ;
V_198 = F_88 ( V_197 , V_202 ) ;
++ V_197 -> V_203 ;
if ( V_230 -> V_81 & V_231 ) {
* V_198 = V_230 -> V_247 ;
} else {
F_8 ( V_248 != 1 ) ;
F_95 (
* V_198 ,
V_249 ,
V_230 -> V_81 & V_248 ,
V_250 , V_230 -> V_214 ,
V_251 , V_230 -> V_172 ) ;
}
} while ( V_197 -> V_203 != V_197 -> V_232 );
F_66 () ;
if ( F_96 ( V_197 , V_245 ) ) {
V_198 = F_88 ( V_197 ,
V_245 & V_197 -> V_200 ) ;
F_81 ( V_197 , V_198 ) ;
++ V_197 -> V_252 ;
} else {
F_92 ( V_197 ) ;
}
}
static int F_97 ( struct V_1 * V_2 , T_4 * V_180 )
{
F_7 ( V_65 , V_253 ) ;
F_7 ( V_11 , V_254 ) ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_65 , V_255 ,
V_225 ) ;
F_39 ( V_65 , V_256 ,
V_257 ) ;
F_39 ( V_65 , V_258 ,
V_259 ) ;
V_16 = F_9 ( V_2 , V_260 , V_65 , sizeof( V_65 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_254 )
return - V_7 ;
* V_180 = F_11 ( V_11 , V_261 ) ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 , T_4 V_180 )
{
F_7 ( V_65 , V_262 ) ;
int V_16 ;
F_39 ( V_65 , V_263 ,
V_180 ) ;
V_16 = F_9 ( V_2 , V_264 , V_65 , sizeof( V_65 ) ,
NULL , 0 , NULL ) ;
F_37 ( V_16 != 0 ) ;
}
static int F_99 ( struct V_1 * V_2 , T_4 V_180 )
{
F_7 ( V_265 , V_266 ) ;
F_7 ( V_267 , V_268 ) ;
int V_37 , V_16 ;
F_39 ( V_265 , V_269 ,
V_180 ) ;
F_8 ( F_100 ( V_2 -> V_270 ) !=
V_271 ) ;
for ( V_37 = 0 ; V_37 < F_100 ( V_2 -> V_270 ) ; ++ V_37 )
F_14 ( V_265 ,
V_272 ) [ V_37 ] =
( T_3 ) V_2 -> V_270 [ V_37 ] ;
V_16 = F_9 ( V_2 , V_273 , V_265 ,
sizeof( V_265 ) , NULL , 0 , NULL ) ;
if ( V_16 != 0 )
return V_16 ;
F_39 ( V_267 , V_274 ,
V_180 ) ;
F_8 ( F_100 ( V_2 -> V_275 ) !=
V_276 ) ;
for ( V_37 = 0 ; V_37 < F_100 ( V_2 -> V_275 ) ; ++ V_37 )
F_14 ( V_267 , V_277 ) [ V_37 ] =
V_2 -> V_275 [ V_37 ] ;
return F_9 ( V_2 , V_278 , V_267 ,
sizeof( V_267 ) , NULL , 0 , NULL ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_46 != V_47 )
F_98 ( V_2 , V_14 -> V_46 ) ;
V_14 -> V_46 = V_47 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
F_28 ( V_2 , V_19 , V_2 -> V_20 , L_13 ) ;
if ( V_14 -> V_46 == V_47 ) {
V_16 = F_97 ( V_2 , & V_14 -> V_46 ) ;
if ( V_16 != 0 )
goto V_229;
}
V_16 = F_99 ( V_2 , V_14 -> V_46 ) ;
if ( V_16 != 0 )
goto V_229;
return;
V_229:
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_12 , V_238 , V_16 ) ;
}
static int F_101 ( struct V_279 * V_280 )
{
return F_19 ( V_280 -> V_2 , & V_280 -> V_281 . V_199 ,
( V_280 -> V_200 + 1 ) *
sizeof( V_201 ) ,
V_39 ) ;
}
static void F_102 ( struct V_279 * V_280 )
{
F_7 ( V_65 ,
F_103 ( V_208 * 8 /
V_209 ) ) ;
F_7 ( V_11 , V_282 ) ;
struct V_148 * V_149 = F_104 ( V_280 ) ;
T_2 V_213 = V_280 -> V_281 . V_199 . V_214 / V_209 ;
struct V_1 * V_2 = V_280 -> V_2 ;
T_2 V_215 , V_15 ;
T_9 V_172 ;
int V_16 ;
int V_37 ;
V_280 -> V_283 = 0 ;
V_280 -> V_284 = 0 ;
F_39 ( V_65 , V_285 , V_280 -> V_200 + 1 ) ;
F_39 ( V_65 , V_286 , V_149 -> V_149 ) ;
F_39 ( V_65 , V_287 , F_105 ( V_280 ) ) ;
F_39 ( V_65 , V_288 ,
F_105 ( V_280 ) ) ;
F_106 ( V_65 , V_289 ,
V_290 , 1 ) ;
F_39 ( V_65 , V_291 , 0 ) ;
F_39 ( V_65 , V_292 , V_225 ) ;
V_172 = V_280 -> V_281 . V_199 . V_172 ;
F_28 ( V_2 , V_226 , V_2 -> V_20 , L_14 ,
F_105 ( V_280 ) , V_213 , ( T_5 ) V_172 ) ;
for ( V_37 = 0 ; V_37 < V_213 ; ++ V_37 ) {
F_87 ( V_65 , V_293 , V_37 , V_172 ) ;
V_172 += V_209 ;
}
V_215 = F_103 ( V_213 ) ;
V_16 = F_9 ( V_2 , V_294 , V_65 , V_215 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
goto V_229;
return;
V_229:
F_37 ( true ) ;
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_12 , V_238 , V_16 ) ;
}
static void F_107 ( struct V_279 * V_280 )
{
F_7 ( V_65 , V_295 ) ;
F_7 ( V_11 , V_296 ) ;
struct V_1 * V_2 = V_280 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_65 , V_297 ,
F_105 ( V_280 ) ) ;
V_16 = F_9 ( V_2 , V_298 , V_65 , sizeof( V_65 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_229;
return;
V_229:
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_12 , V_238 , V_16 ) ;
}
static void F_108 ( struct V_279 * V_280 )
{
F_31 ( V_280 -> V_2 , & V_280 -> V_281 . V_199 ) ;
}
static inline void
F_109 ( struct V_279 * V_280 , unsigned int V_124 )
{
struct V_299 * V_300 ;
V_201 * V_281 ;
V_281 = F_110 ( V_280 , V_124 ) ;
V_300 = V_299 ( V_280 , V_124 ) ;
F_111 ( * V_281 ,
V_301 , V_300 -> V_214 ,
V_302 , V_300 -> V_172 ) ;
}
static void F_112 ( struct V_279 * V_280 )
{
struct V_1 * V_2 = V_280 -> V_2 ;
unsigned int V_203 ;
T_1 V_3 ;
V_203 = V_280 -> V_303 & ~ 7 ;
if ( V_280 -> V_304 == V_203 )
return;
do
F_109 (
V_280 ,
V_280 -> V_304 & V_280 -> V_200 ) ;
while ( ++ V_280 -> V_304 != V_203 );
F_66 () ;
F_93 ( V_3 , V_305 ,
V_203 & V_280 -> V_200 ) ;
F_61 ( V_2 , & V_3 , V_306 ,
F_105 ( V_280 ) ) ;
}
static void F_113 ( struct V_279 * V_280 )
{
struct V_148 * V_149 = F_104 ( V_280 ) ;
F_7 ( V_65 , V_307 ) ;
V_201 V_308 ;
F_111 ( V_308 ,
V_309 , V_310 ,
V_311 , V_312 ) ;
F_39 ( V_65 , V_313 , V_149 -> V_149 ) ;
memcpy ( F_14 ( V_65 , V_314 ) , & V_308 . T_5 [ 0 ] ,
sizeof( V_201 ) ) ;
F_114 ( V_149 -> V_2 , V_315 ,
V_65 , sizeof( V_65 ) , 0 ,
V_316 , 0 ) ;
}
static void
V_316 ( struct V_1 * V_2 , unsigned long V_317 ,
int V_16 , T_1 * V_11 ,
T_2 V_318 )
{
}
static int F_115 ( struct V_148 * V_149 )
{
return F_19 ( V_149 -> V_2 , & V_149 -> V_319 . V_199 ,
( V_149 -> V_320 + 1 ) *
sizeof( V_201 ) ,
V_39 ) ;
}
static int F_116 ( struct V_148 * V_149 )
{
F_7 ( V_65 ,
F_117 ( V_321 * 8 /
V_209 ) ) ;
F_7 ( V_11 , V_322 ) ;
T_2 V_213 = V_149 -> V_319 . V_199 . V_214 / V_209 ;
struct V_1 * V_2 = V_149 -> V_2 ;
struct V_13 * V_14 ;
bool V_323 ;
T_2 V_215 , V_15 ;
T_9 V_172 ;
int V_16 ;
int V_37 ;
V_14 = V_2 -> V_14 ;
V_323 =
! ! ( V_14 -> V_21 &
1 << V_324 ) ;
memset ( V_149 -> V_319 . V_199 . V_111 , 0xff , V_149 -> V_319 . V_199 . V_214 ) ;
F_39 ( V_65 , V_325 , V_149 -> V_320 + 1 ) ;
F_39 ( V_65 , V_326 , V_149 -> V_149 ) ;
F_39 ( V_65 , V_327 , V_149 -> V_149 ) ;
F_118 ( V_65 , V_328 ,
V_329 , 1 ,
V_330 , 1 ,
V_331 , 1 ,
V_332 , ! V_323 ) ;
F_39 ( V_65 , V_333 ,
V_334 ) ;
F_39 ( V_65 , V_335 , 0 ) ;
F_39 ( V_65 , V_336 , 0 ) ;
F_39 ( V_65 , V_337 ,
V_338 ) ;
F_39 ( V_65 , V_339 , 0 ) ;
V_172 = V_149 -> V_319 . V_199 . V_172 ;
for ( V_37 = 0 ; V_37 < V_213 ; ++ V_37 ) {
F_87 ( V_65 , V_340 , V_37 , V_172 ) ;
V_172 += V_209 ;
}
V_215 = F_117 ( V_213 ) ;
V_16 = F_9 ( V_2 , V_341 , V_65 , V_215 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
goto V_229;
return 0 ;
V_229:
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_12 , V_238 , V_16 ) ;
return V_16 ;
}
static void F_119 ( struct V_148 * V_149 )
{
F_7 ( V_65 , V_342 ) ;
F_7 ( V_11 , V_343 ) ;
struct V_1 * V_2 = V_149 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_65 , V_344 , V_149 -> V_149 ) ;
V_16 = F_9 ( V_2 , V_345 , V_65 , sizeof( V_65 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_229;
return;
V_229:
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_12 , V_238 , V_16 ) ;
}
static void F_120 ( struct V_148 * V_149 )
{
F_31 ( V_149 -> V_2 , & V_149 -> V_319 . V_199 ) ;
}
static void F_121 ( struct V_279 * V_280 ,
unsigned int V_346 )
{
struct V_1 * V_2 = V_280 -> V_2 ;
F_122 ( V_2 , V_226 , V_2 -> V_20 ,
L_15 ,
F_105 ( V_280 ) , V_346 ) ;
F_123 ( V_2 , V_347 ) ;
}
static void
F_124 ( struct V_279 * V_280 ,
unsigned int V_348 , unsigned int V_349 )
{
unsigned int V_350 = ( V_348 - V_349 ) & V_280 -> V_200 ;
struct V_1 * V_2 = V_280 -> V_2 ;
F_122 ( V_2 , V_226 , V_2 -> V_20 ,
L_16 ,
V_350 , V_348 , V_349 ) ;
F_123 ( V_2 , V_347 ) ;
}
static void F_125 ( struct V_279 * V_280 )
{
unsigned int V_351 ;
F_37 ( V_280 -> V_283 == 0 ) ;
F_28 ( V_280 -> V_2 , V_226 , V_280 -> V_2 -> V_20 ,
L_17 ,
V_280 -> V_283 ) ;
V_351 = V_280 -> V_352 & V_280 -> V_200 ;
F_126 ( V_280 , V_351 , V_280 -> V_283 ,
0 , V_353 ) ;
V_280 -> V_352 += V_280 -> V_283 ;
V_280 -> V_283 = 0 ;
V_280 -> V_284 = 0 ;
++ F_104 ( V_280 ) -> V_354 ;
}
static int F_127 ( struct V_148 * V_149 ,
const V_201 * V_308 )
{
unsigned int V_131 , V_355 , V_346 , V_356 ;
unsigned int V_357 , V_358 , V_37 ;
struct V_1 * V_2 = V_149 -> V_2 ;
struct V_279 * V_280 ;
bool V_359 ;
T_10 V_81 = 0 ;
if ( F_128 ( F_74 ( V_2 -> V_360 ) ) )
return 0 ;
V_131 = F_129 ( * V_308 , V_361 ) ;
V_355 = F_129 ( * V_308 , V_362 ) ;
V_346 = F_129 ( * V_308 , V_363 ) ;
V_356 = F_129 ( * V_308 , V_364 ) ;
V_359 = F_129 ( * V_308 , V_365 ) ;
F_37 ( F_129 ( * V_308 , V_366 ) ) ;
V_280 = F_130 ( V_149 ) ;
if ( F_128 ( V_346 != F_105 ( V_280 ) ) )
F_121 ( V_280 , V_346 ) ;
V_357 = ( ( V_355 - V_280 -> V_352 ) &
( ( 1 << V_367 ) - 1 ) ) ;
if ( V_357 != V_280 -> V_283 + 1 ) {
if ( F_128 ( V_357 == V_280 -> V_283 ) ) {
F_37 ( V_131 != 0 ) ;
F_125 ( V_280 ) ;
return 0 ;
}
if ( F_128 ( V_280 -> V_283 != 0 ) ) {
F_124 (
V_280 , V_355 ,
( V_280 -> V_352 +
V_280 -> V_283 + 1 ) &
( ( 1 << V_367 ) - 1 ) ) ;
return 0 ;
}
V_280 -> V_283 = 1 ;
V_280 -> V_284 = 0 ;
V_358 = V_357 ;
++ V_149 -> V_368 ;
V_149 -> V_369 += V_358 ;
V_81 |= V_370 ;
} else {
++ V_280 -> V_283 ;
V_280 -> V_284 += V_131 ;
if ( V_359 )
return 0 ;
V_358 = 1 ;
}
if ( F_128 ( F_129 ( * V_308 , V_371 ) ) )
V_81 |= V_353 ;
if ( F_128 ( F_129 ( * V_308 , V_372 ) ) ) {
V_149 -> V_373 += V_358 ;
} else if ( F_128 ( F_129 ( * V_308 ,
V_374 ) ) ) {
V_149 -> V_375 += V_358 ;
} else if ( V_356 == V_376 ||
V_356 == V_377 ) {
V_81 |= V_378 ;
}
if ( V_356 == V_376 )
V_81 |= V_379 ;
V_149 -> V_380 += 2 * V_358 ;
for ( V_37 = 0 ; V_37 < V_358 ; V_37 ++ ) {
F_126 ( V_280 ,
V_280 -> V_352 & V_280 -> V_200 ,
V_280 -> V_283 , V_280 -> V_284 ,
V_81 ) ;
V_280 -> V_352 += V_280 -> V_283 ;
}
V_280 -> V_283 = 0 ;
V_280 -> V_284 = 0 ;
return V_358 ;
}
static int
F_131 ( struct V_148 * V_149 , V_201 * V_308 )
{
struct V_1 * V_2 = V_149 -> V_2 ;
struct V_196 * V_197 ;
unsigned int V_381 ;
unsigned int V_382 ;
int V_383 = 0 ;
if ( F_128 ( F_74 ( V_2 -> V_360 ) ) )
return 0 ;
if ( F_128 ( F_129 ( * V_308 , V_384 ) ) )
return 0 ;
V_381 = F_129 ( * V_308 , V_385 ) ;
V_382 = F_129 ( * V_308 , V_386 ) ;
V_197 = F_132 ( V_149 ,
V_382 % V_78 ) ;
V_383 = ( ( V_381 + 1 - V_197 -> V_387 ) &
V_197 -> V_200 ) ;
F_133 ( V_197 , V_381 & V_197 -> V_200 ) ;
return V_383 ;
}
static void
F_134 ( struct V_148 * V_149 , V_201 * V_308 )
{
struct V_1 * V_2 = V_149 -> V_2 ;
int V_388 ;
V_388 = F_129 ( * V_308 , V_389 ) ;
switch ( V_388 ) {
case V_390 :
case V_391 :
break;
case V_392 :
break;
default:
F_10 ( V_2 , V_226 , V_2 -> V_20 ,
L_18
L_19 V_393 L_20 ,
V_149 -> V_149 , V_388 ,
F_135 ( * V_308 ) ) ;
}
}
static void F_136 ( struct V_148 * V_149 ,
V_201 * V_308 )
{
struct V_1 * V_2 = V_149 -> V_2 ;
T_4 V_388 ;
V_388 = F_129 ( * V_308 , V_394 ) ;
switch ( V_388 ) {
case V_395 :
V_149 -> V_396 = F_72 () ;
break;
case V_312 :
F_137 ( & V_149 -> V_280 ) ;
break;
default:
F_10 ( V_2 , V_226 , V_2 -> V_20 ,
L_21
L_19 V_393 L_20 ,
V_149 -> V_149 , ( unsigned ) V_388 ,
F_135 ( * V_308 ) ) ;
}
}
static int F_138 ( struct V_148 * V_149 , int V_397 )
{
struct V_1 * V_2 = V_149 -> V_2 ;
V_201 V_308 , * V_398 ;
unsigned int V_399 ;
int V_400 ;
int V_383 = 0 ;
int V_401 = 0 ;
V_399 = V_149 -> V_402 ;
for (; ; ) {
V_398 = F_139 ( V_149 , V_399 ) ;
V_308 = * V_398 ;
if ( ! F_140 ( & V_308 ) )
break;
F_141 ( * V_398 ) ;
++ V_399 ;
V_400 = F_129 ( V_308 , V_309 ) ;
F_71 ( V_2 , V_19 , V_2 -> V_20 ,
L_22 V_393 L_10 ,
V_149 -> V_149 , F_135 ( V_308 ) ) ;
switch ( V_400 ) {
case V_403 :
F_142 ( V_149 , & V_308 ) ;
break;
case V_404 :
V_401 += F_127 ( V_149 , & V_308 ) ;
if ( V_401 >= V_397 ) {
V_401 = V_397 ;
goto V_405;
}
break;
case V_406 :
V_383 += F_131 ( V_149 , & V_308 ) ;
if ( V_383 > V_2 -> V_407 ) {
V_401 = V_397 ;
goto V_405;
} else if ( ++ V_401 == V_397 ) {
goto V_405;
}
break;
case V_408 :
F_134 ( V_149 , & V_308 ) ;
if ( ++ V_401 == V_397 )
goto V_405;
break;
case V_310 :
F_136 ( V_149 , & V_308 ) ;
break;
default:
F_10 ( V_2 , V_226 , V_2 -> V_20 ,
L_23
L_19 V_393 L_20 ,
V_149 -> V_149 , V_400 ,
F_135 ( V_308 ) ) ;
}
}
V_405:
V_149 -> V_402 = V_399 ;
return V_401 ;
}
static void F_143 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = V_149 -> V_2 ;
T_1 V_409 ;
if ( F_59 ( V_2 ) ) {
F_8 ( V_410 <
( 1 << V_411 ) ) ;
F_8 ( V_321 >
( 1 << 2 * V_411 ) ) ;
F_62 ( V_409 , V_412 ,
V_413 ,
V_414 ,
( V_149 -> V_402 &
V_149 -> V_320 ) >>
V_411 ) ;
F_61 ( V_2 , & V_409 , V_158 ,
V_149 -> V_149 ) ;
F_62 ( V_409 , V_412 ,
V_415 ,
V_414 ,
V_149 -> V_402 &
( ( 1 << V_411 ) - 1 ) ) ;
F_61 ( V_2 , & V_409 , V_158 ,
V_149 -> V_149 ) ;
} else {
F_93 ( V_409 , V_416 ,
V_149 -> V_402 &
V_149 -> V_320 ) ;
F_61 ( V_2 , & V_409 , V_417 , V_149 -> V_149 ) ;
}
}
static void F_144 ( struct V_148 * V_149 )
{
F_7 ( V_65 , V_307 ) ;
struct V_1 * V_2 = V_149 -> V_2 ;
V_201 V_308 ;
int V_16 ;
F_111 ( V_308 ,
V_309 , V_310 ,
V_311 , V_395 ) ;
F_39 ( V_65 , V_313 , V_149 -> V_149 ) ;
memcpy ( F_14 ( V_65 , V_314 ) , & V_308 . T_5 [ 0 ] ,
sizeof( V_201 ) ) ;
V_16 = F_9 ( V_2 , V_315 , V_65 , sizeof( V_65 ) ,
NULL , 0 , NULL ) ;
if ( V_16 != 0 )
goto V_229;
return;
V_229:
F_37 ( true ) ;
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_12 , V_238 , V_16 ) ;
}
void F_145 ( struct V_1 * V_2 )
{
if ( F_146 ( & V_2 -> V_418 ) )
F_147 ( & V_2 -> V_419 ) ;
F_37 ( F_148 ( & V_2 -> V_418 ) < 0 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_148 * V_149 ;
struct V_196 * V_197 ;
struct V_279 * V_280 ;
int V_420 ;
if ( V_14 -> V_80 ) {
F_150 ( & V_2 -> V_418 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_421 != V_422 ) {
F_77 (channel, efx) {
F_151 (rx_queue, channel)
F_107 ( V_280 ) ;
F_152 (tx_queue, channel)
F_90 ( V_197 ) ;
}
F_153 ( V_2 -> V_419 ,
F_148 ( & V_2 -> V_418 ) == 0 ,
F_154 ( V_423 ) ) ;
V_420 = F_148 ( & V_2 -> V_418 ) ;
if ( V_420 ) {
F_10 ( V_2 , V_226 , V_2 -> V_20 , L_24 ,
V_420 ) ;
return - V_424 ;
}
}
return 0 ;
}
static bool F_155 ( const struct V_425 * V_426 ,
const struct V_425 * V_427 )
{
if ( ( V_426 -> V_428 ^ V_427 -> V_428 ) |
( ( V_426 -> V_81 ^ V_427 -> V_81 ) &
( V_429 | V_430 ) ) )
return false ;
return memcmp ( & V_426 -> V_431 , & V_427 -> V_431 ,
sizeof( struct V_425 ) -
F_156 ( struct V_425 , V_431 ) ) == 0 ;
}
static unsigned int F_157 ( const struct V_425 * V_432 )
{
F_8 ( F_156 ( struct V_425 , V_431 ) & 3 ) ;
return F_158 ( ( const T_4 * ) & V_432 -> V_431 ,
( sizeof( struct V_425 ) -
F_156 ( struct V_425 , V_431 ) ) / 4 ,
0 ) ;
}
static bool F_159 ( const struct V_425 * V_432 )
{
if ( V_432 -> V_428 & V_433 &&
! F_160 ( V_432 -> V_434 ) )
return true ;
if ( ( V_432 -> V_428 &
( V_435 | V_436 ) ) ==
( V_435 | V_436 ) ) {
if ( V_432 -> V_437 == F_161 ( V_438 ) &&
! F_162 ( V_432 -> V_439 [ 0 ] ) )
return true ;
if ( V_432 -> V_437 == F_161 ( V_440 ) &&
( ( const T_3 * ) V_432 -> V_439 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_425 *
F_163 ( const struct V_441 * V_442 ,
unsigned int V_443 )
{
return (struct V_425 * ) ( V_442 -> V_444 [ V_443 ] . V_432 &
~ V_445 ) ;
}
static unsigned int
F_164 ( const struct V_441 * V_442 ,
unsigned int V_443 )
{
return V_442 -> V_444 [ V_443 ] . V_432 & V_445 ;
}
static void
F_165 ( struct V_441 * V_442 ,
unsigned int V_443 ,
const struct V_425 * V_432 ,
unsigned int V_81 )
{
V_442 -> V_444 [ V_443 ] . V_432 = ( unsigned long ) V_432 | V_81 ;
}
static void F_166 ( struct V_1 * V_2 ,
const struct V_425 * V_432 ,
T_1 * V_65 , T_5 V_446 ,
bool V_447 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
memset ( V_65 , 0 , V_448 ) ;
if ( V_447 ) {
F_39 ( V_65 , V_449 ,
V_450 ) ;
F_167 ( V_65 , V_451 , V_446 ) ;
} else {
T_4 V_452 = 0 ;
F_39 ( V_65 , V_449 ,
F_159 ( V_432 ) ?
V_453 :
V_454 ) ;
if ( V_432 -> V_428 & V_455 )
V_452 |=
F_160 ( V_432 -> V_434 ) ?
1 << V_456 :
1 << V_457 ;
#define F_168 ( T_11 , T_12 , T_13 ) \
if (spec->match_flags & EFX_FILTER_MATCH_ ## gen_flag) { \
match_fields |= \
1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN; \
BUILD_BUG_ON( \
MC_CMD_FILTER_OP_IN_ ## mcdi_field ## _LEN < \
sizeof(spec->gen_field)); \
memcpy(MCDI_PTR(inbuf, FILTER_OP_IN_ ## mcdi_field), \
&spec->gen_field, sizeof(spec->gen_field)); \
}
F_168 ( V_458 , V_459 , V_460 ) ;
F_168 ( V_461 , V_439 , V_462 ) ;
F_168 ( V_463 , V_464 , V_465 ) ;
F_168 ( V_466 , V_467 , V_468 ) ;
F_168 ( V_469 , V_434 , V_470 ) ;
F_168 ( V_471 , V_472 , V_473 ) ;
F_168 ( V_474 , V_437 , V_474 ) ;
F_168 ( V_475 , V_476 , V_477 ) ;
F_168 ( V_478 , V_431 , V_479 ) ;
F_168 ( V_480 , V_481 , V_480 ) ;
#undef F_168
F_39 ( V_65 , V_482 ,
V_452 ) ;
}
F_39 ( V_65 , V_483 , V_225 ) ;
F_39 ( V_65 , V_484 ,
V_432 -> V_485 == V_486 ?
V_487 :
V_488 ) ;
F_39 ( V_65 , V_489 ,
V_490 ) ;
F_39 ( V_65 , V_491 , V_432 -> V_485 ) ;
F_39 ( V_65 , V_492 ,
( V_432 -> V_81 & V_493 ) ?
V_494 :
V_495 ) ;
if ( V_432 -> V_81 & V_493 )
F_39 ( V_65 , V_496 ,
V_432 -> V_497 !=
V_498 ?
V_432 -> V_497 : V_14 -> V_46 ) ;
}
static int F_169 ( struct V_1 * V_2 ,
const struct V_425 * V_432 ,
T_5 * V_446 , bool V_447 )
{
F_7 ( V_65 , V_448 ) ;
F_7 ( V_11 , V_499 ) ;
int V_16 ;
F_166 ( V_2 , V_432 , V_65 , * V_446 , V_447 ) ;
V_16 = F_9 ( V_2 , V_500 , V_65 , sizeof( V_65 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_16 == 0 )
* V_446 = F_170 ( V_11 , V_501 ) ;
return V_16 ;
}
static int F_171 ( struct V_441 * V_442 ,
enum V_502 V_428 )
{
unsigned int V_503 ;
for ( V_503 = 0 ;
V_503 < V_442 -> V_504 ;
V_503 ++ )
if ( V_442 -> V_505 [ V_503 ] == V_428 )
return V_503 ;
return - V_506 ;
}
static T_14 F_172 ( struct V_1 * V_2 ,
struct V_425 * V_432 ,
bool V_507 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
F_49 ( V_509 , V_510 ) ;
struct V_425 * V_511 ;
unsigned int V_503 , V_512 ;
unsigned int V_513 ;
bool V_447 = false ;
int V_514 = - 1 ;
F_173 ( V_515 ) ;
bool V_516 ;
T_14 V_16 ;
if ( ( V_432 -> V_81 & ( V_429 | V_430 ) ) !=
V_429 )
return - V_92 ;
V_16 = F_171 ( V_442 , V_432 -> V_428 ) ;
if ( V_16 < 0 )
return V_16 ;
V_503 = V_16 ;
V_512 = F_157 ( V_432 ) ;
V_516 = F_174 ( V_432 ) ;
if ( V_516 )
F_175 ( V_509 , V_510 ) ;
for (; ; ) {
unsigned int V_517 = 1 ;
unsigned int V_37 ;
F_176 ( & V_2 -> V_518 ) ;
for (; ; ) {
V_37 = ( V_512 + V_517 ) & ( V_519 - 1 ) ;
V_511 = F_163 ( V_442 , V_37 ) ;
if ( ! V_511 ) {
if ( V_514 < 0 )
V_514 = V_37 ;
} else if ( F_155 ( V_432 , V_511 ) ) {
if ( V_442 -> V_444 [ V_37 ] . V_432 &
V_520 )
break;
if ( V_432 -> V_521 < V_511 -> V_521 &&
! ( V_511 -> V_521 ==
V_522 &&
V_511 -> V_81 &
V_523 ) ) {
V_16 = - V_524 ;
goto V_525;
}
if ( ! V_516 ) {
if ( V_432 -> V_521 ==
V_511 -> V_521 &&
! V_507 ) {
V_16 = - V_526 ;
goto V_525;
}
V_514 = V_37 ;
goto V_527;
} else if ( V_432 -> V_521 >
V_511 -> V_521 ||
( V_432 -> V_521 ==
V_511 -> V_521 &&
V_507 ) ) {
if ( V_514 < 0 )
V_514 = V_37 ;
else
F_177 ( V_517 , V_509 ) ;
}
}
if ( V_517 == V_510 ) {
if ( V_514 < 0 ) {
V_16 = - V_528 ;
goto V_525;
}
goto V_527;
}
++ V_517 ;
}
F_178 ( & V_442 -> V_529 , & V_515 , V_530 ) ;
F_179 ( & V_2 -> V_518 ) ;
F_180 () ;
}
V_527:
V_511 = F_163 ( V_442 , V_514 ) ;
if ( V_511 ) {
if ( V_432 -> V_81 & V_523 ) {
V_511 -> V_81 |= V_523 ;
V_442 -> V_444 [ V_514 ] . V_432 &=
~ V_531 ;
V_16 = V_514 ;
goto V_525;
}
V_447 = true ;
V_513 = F_164 ( V_442 , V_514 ) ;
} else {
V_511 = F_181 ( sizeof( * V_432 ) , V_532 ) ;
if ( ! V_511 ) {
V_16 = - V_40 ;
goto V_525;
}
* V_511 = * V_432 ;
V_513 = 0 ;
}
F_165 ( V_442 , V_514 , V_511 ,
V_513 | V_520 ) ;
if ( V_516 ) {
unsigned int V_517 , V_37 ;
for ( V_517 = 0 ; V_517 < V_510 ; V_517 ++ ) {
V_37 = ( V_512 + V_517 ) & ( V_519 - 1 ) ;
if ( F_182 ( V_517 , V_509 ) )
V_442 -> V_444 [ V_37 ] . V_432 |=
V_520 ;
}
}
F_179 ( & V_2 -> V_518 ) ;
V_16 = F_169 ( V_2 , V_432 , & V_442 -> V_444 [ V_514 ] . V_446 ,
V_447 ) ;
F_176 ( & V_2 -> V_518 ) ;
if ( V_16 == 0 ) {
if ( V_447 ) {
V_511 -> V_521 = V_432 -> V_521 ;
V_511 -> V_81 &= V_523 ;
V_511 -> V_81 |= V_432 -> V_81 ;
V_511 -> V_497 = V_432 -> V_497 ;
V_511 -> V_485 = V_432 -> V_485 ;
}
} else if ( ! V_447 ) {
F_32 ( V_511 ) ;
V_511 = NULL ;
}
F_165 ( V_442 , V_514 , V_511 , V_513 ) ;
if ( V_516 ) {
F_7 ( V_65 , V_448 ) ;
unsigned int V_517 , V_37 ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
for ( V_517 = 0 ; V_517 < V_510 ; V_517 ++ ) {
if ( ! F_182 ( V_517 , V_509 ) )
continue;
V_37 = ( V_512 + V_517 ) & ( V_519 - 1 ) ;
V_511 = F_163 ( V_442 , V_37 ) ;
V_513 = F_164 ( V_442 , V_37 ) ;
if ( V_16 == 0 ) {
F_179 ( & V_2 -> V_518 ) ;
F_39 ( V_65 , V_449 ,
V_533 ) ;
F_167 ( V_65 , V_451 ,
V_442 -> V_444 [ V_37 ] . V_446 ) ;
V_16 = F_9 ( V_2 , V_500 ,
V_65 , sizeof( V_65 ) ,
NULL , 0 , NULL ) ;
F_176 ( & V_2 -> V_518 ) ;
}
if ( V_16 == 0 ) {
F_32 ( V_511 ) ;
V_511 = NULL ;
V_513 = 0 ;
} else {
V_513 &= ~ V_520 ;
}
F_165 ( V_442 , V_37 , V_511 ,
V_513 ) ;
}
}
if ( V_16 == 0 )
V_16 = V_503 * V_519 + V_514 ;
F_183 ( & V_442 -> V_529 ) ;
V_525:
F_179 ( & V_2 -> V_518 ) ;
F_184 ( & V_442 -> V_529 , & V_515 ) ;
return V_16 ;
}
void F_185 ( struct V_1 * V_2 )
{
}
static int F_186 ( struct V_1 * V_2 ,
enum V_534 V_521 ,
T_4 V_535 , bool V_536 )
{
unsigned int V_443 = V_535 % V_519 ;
struct V_441 * V_442 = V_2 -> V_508 ;
F_7 ( V_65 ,
V_537 +
V_538 ) ;
struct V_425 * V_432 ;
F_173 ( V_515 ) ;
int V_16 ;
for (; ; ) {
F_176 ( & V_2 -> V_518 ) ;
if ( ! ( V_442 -> V_444 [ V_443 ] . V_432 &
V_520 ) )
break;
F_178 ( & V_442 -> V_529 , & V_515 , V_530 ) ;
F_179 ( & V_2 -> V_518 ) ;
F_180 () ;
}
V_432 = F_163 ( V_442 , V_443 ) ;
if ( ! V_432 || V_432 -> V_521 > V_521 ||
( ! V_536 &&
F_171 ( V_442 , V_432 -> V_428 ) !=
V_535 / V_519 ) ) {
V_16 = - V_60 ;
goto V_525;
}
V_442 -> V_444 [ V_443 ] . V_432 |= V_520 ;
F_179 ( & V_2 -> V_518 ) ;
if ( V_432 -> V_81 & V_523 && ! V_536 ) {
struct V_425 V_539 = * V_432 ;
V_539 . V_521 = V_522 ;
V_539 . V_81 = ( V_429 |
V_493 |
V_523 ) ;
V_539 . V_485 = 0 ;
V_539 . V_497 = V_498 ;
V_16 = F_169 ( V_2 , & V_539 ,
& V_442 -> V_444 [ V_443 ] . V_446 ,
true ) ;
F_176 ( & V_2 -> V_518 ) ;
if ( V_16 == 0 )
* V_432 = V_539 ;
} else {
F_39 ( V_65 , V_449 ,
F_159 ( V_432 ) ?
V_540 :
V_533 ) ;
F_167 ( V_65 , V_451 ,
V_442 -> V_444 [ V_443 ] . V_446 ) ;
V_16 = F_9 ( V_2 , V_500 ,
V_65 , sizeof( V_65 ) , NULL , 0 , NULL ) ;
F_176 ( & V_2 -> V_518 ) ;
if ( V_16 == 0 ) {
F_32 ( V_432 ) ;
F_165 ( V_442 , V_443 , NULL , 0 ) ;
}
}
V_442 -> V_444 [ V_443 ] . V_432 &= ~ V_520 ;
F_183 ( & V_442 -> V_529 ) ;
V_525:
F_179 ( & V_2 -> V_518 ) ;
F_184 ( & V_442 -> V_529 , & V_515 ) ;
return V_16 ;
}
static int F_187 ( struct V_1 * V_2 ,
enum V_534 V_521 ,
T_4 V_535 )
{
return F_186 ( V_2 , V_521 , V_535 , false ) ;
}
static int F_188 ( struct V_1 * V_2 ,
enum V_534 V_521 ,
T_4 V_535 , struct V_425 * V_432 )
{
unsigned int V_443 = V_535 % V_519 ;
struct V_441 * V_442 = V_2 -> V_508 ;
const struct V_425 * V_511 ;
int V_16 ;
F_176 ( & V_2 -> V_518 ) ;
V_511 = F_163 ( V_442 , V_443 ) ;
if ( V_511 && V_511 -> V_521 == V_521 &&
F_171 ( V_442 , V_511 -> V_428 ) ==
V_535 / V_519 ) {
* V_432 = * V_511 ;
V_16 = 0 ;
} else {
V_16 = - V_60 ;
}
F_179 ( & V_2 -> V_518 ) ;
return V_16 ;
}
static void F_189 ( struct V_1 * V_2 ,
enum V_534 V_521 )
{
}
static T_4 F_190 ( struct V_1 * V_2 ,
enum V_534 V_521 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
unsigned int V_443 ;
T_14 V_541 = 0 ;
F_176 ( & V_2 -> V_518 ) ;
for ( V_443 = 0 ; V_443 < V_519 ; V_443 ++ ) {
if ( V_442 -> V_444 [ V_443 ] . V_432 &&
F_163 ( V_442 , V_443 ) -> V_521 ==
V_521 )
++ V_541 ;
}
F_179 ( & V_2 -> V_518 ) ;
return V_541 ;
}
static T_4 F_191 ( struct V_1 * V_2 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
return V_442 -> V_504 * V_519 ;
}
static T_14 F_192 ( struct V_1 * V_2 ,
enum V_534 V_521 ,
T_4 * V_199 , T_4 V_542 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
struct V_425 * V_432 ;
unsigned int V_443 ;
T_14 V_541 = 0 ;
F_176 ( & V_2 -> V_518 ) ;
for ( V_443 = 0 ; V_443 < V_519 ; V_443 ++ ) {
V_432 = F_163 ( V_442 , V_443 ) ;
if ( V_432 && V_432 -> V_521 == V_521 ) {
if ( V_541 == V_542 ) {
V_541 = - V_543 ;
break;
}
V_199 [ V_541 ++ ] = ( F_171 (
V_442 , V_432 -> V_428 ) *
V_519 +
V_443 ) ;
}
}
F_179 ( & V_2 -> V_518 ) ;
return V_541 ;
}
static T_14 F_193 ( struct V_1 * V_2 ,
struct V_425 * V_432 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
F_7 ( V_65 , V_448 ) ;
struct V_425 * V_511 ;
unsigned int V_512 , V_37 , V_517 = 1 ;
bool V_447 = false ;
int V_514 = - 1 ;
T_5 V_317 ;
T_14 V_16 ;
F_194 ( V_432 -> V_81 !=
( V_429 | V_544 ) ) ;
F_194 ( V_432 -> V_521 != V_545 ) ;
F_194 ( F_174 ( V_432 ) ) ;
V_512 = F_157 ( V_432 ) ;
F_176 ( & V_2 -> V_518 ) ;
for (; ; ) {
V_37 = ( V_512 + V_517 ) & ( V_519 - 1 ) ;
V_511 = F_163 ( V_442 , V_37 ) ;
if ( ! V_511 ) {
if ( V_514 < 0 )
V_514 = V_37 ;
} else if ( F_155 ( V_432 , V_511 ) ) {
if ( V_442 -> V_444 [ V_37 ] . V_432 & V_520 ) {
V_16 = - V_528 ;
goto V_546;
}
F_194 ( V_511 -> V_81 &
V_523 ) ;
if ( V_432 -> V_521 < V_511 -> V_521 ) {
V_16 = - V_524 ;
goto V_546;
}
V_514 = V_37 ;
break;
}
if ( V_517 == V_510 ) {
if ( V_514 < 0 ) {
V_16 = - V_528 ;
goto V_546;
}
break;
}
++ V_517 ;
}
V_511 = F_163 ( V_442 , V_514 ) ;
if ( V_511 ) {
V_447 = true ;
} else {
V_511 = F_181 ( sizeof( * V_432 ) , V_532 ) ;
if ( ! V_511 ) {
V_16 = - V_40 ;
goto V_546;
}
* V_511 = * V_432 ;
}
F_165 ( V_442 , V_514 , V_511 ,
V_520 ) ;
F_179 ( & V_2 -> V_518 ) ;
V_317 = V_447 << 31 | V_514 << 16 | V_432 -> V_485 ;
F_166 ( V_2 , V_432 , V_65 ,
V_442 -> V_444 [ V_514 ] . V_446 , V_447 ) ;
F_114 ( V_2 , V_500 , V_65 , sizeof( V_65 ) ,
V_499 ,
V_547 , V_317 ) ;
return V_514 ;
V_546:
F_179 ( & V_2 -> V_518 ) ;
return V_16 ;
}
static void
V_547 ( struct V_1 * V_2 , unsigned long V_317 ,
int V_16 , T_1 * V_11 ,
T_2 V_318 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
unsigned int V_514 , V_485 ;
struct V_425 * V_432 ;
bool V_447 ;
V_447 = V_317 >> 31 ;
V_514 = ( V_317 >> 16 ) & ( V_519 - 1 ) ;
V_485 = V_317 & 0xffff ;
F_176 ( & V_2 -> V_518 ) ;
V_432 = F_163 ( V_442 , V_514 ) ;
if ( V_16 == 0 ) {
V_442 -> V_444 [ V_514 ] . V_446 =
F_170 ( V_11 , V_501 ) ;
if ( V_447 )
V_432 -> V_485 = V_485 ;
} else if ( ! V_447 ) {
F_32 ( V_432 ) ;
V_432 = NULL ;
}
F_165 ( V_442 , V_514 , V_432 , 0 ) ;
F_179 ( & V_2 -> V_518 ) ;
F_183 ( & V_442 -> V_529 ) ;
}
static bool F_195 ( struct V_1 * V_2 , T_4 V_548 ,
unsigned int V_443 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
struct V_425 * V_432 =
F_163 ( V_442 , V_443 ) ;
F_7 ( V_65 ,
V_537 +
V_538 ) ;
if ( ! V_432 ||
( V_442 -> V_444 [ V_443 ] . V_432 & V_520 ) ||
V_432 -> V_521 != V_545 ||
! F_196 ( V_2 -> V_20 , V_432 -> V_485 ,
V_548 , V_443 ) )
return false ;
F_39 ( V_65 , V_449 ,
V_540 ) ;
F_167 ( V_65 , V_451 ,
V_442 -> V_444 [ V_443 ] . V_446 ) ;
if ( F_114 ( V_2 , V_500 , V_65 , sizeof( V_65 ) , 0 ,
V_549 , V_443 ) )
return false ;
V_442 -> V_444 [ V_443 ] . V_432 |= V_520 ;
return true ;
}
static void
V_549 ( struct V_1 * V_2 ,
unsigned long V_443 ,
int V_16 , T_1 * V_11 ,
T_2 V_318 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
struct V_425 * V_432 =
F_163 ( V_442 , V_443 ) ;
F_176 ( & V_2 -> V_518 ) ;
if ( V_16 == 0 ) {
F_32 ( V_432 ) ;
F_165 ( V_442 , V_443 , NULL , 0 ) ;
}
V_442 -> V_444 [ V_443 ] . V_432 &= ~ V_520 ;
F_183 ( & V_442 -> V_529 ) ;
F_179 ( & V_2 -> V_518 ) ;
}
static int F_197 ( T_4 V_550 )
{
int V_428 = 0 ;
#define F_198 ( T_11 , T_13 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_198 ( V_551 , V_552 ) ;
F_198 ( V_551 , V_553 ) ;
F_198 ( V_458 , V_460 ) ;
F_198 ( V_461 , V_462 ) ;
F_198 ( V_463 , V_465 ) ;
F_198 ( V_466 , V_468 ) ;
F_198 ( V_469 , V_470 ) ;
F_198 ( V_471 , V_473 ) ;
F_198 ( V_474 , V_474 ) ;
F_198 ( V_475 , V_477 ) ;
F_198 ( V_478 , V_479 ) ;
F_198 ( V_480 , V_480 ) ;
#undef F_198
if ( V_550 )
return - V_92 ;
return V_428 ;
}
static int F_199 ( struct V_1 * V_2 )
{
F_7 ( V_65 , V_554 ) ;
F_7 ( V_11 , V_555 ) ;
unsigned int V_556 , V_557 ;
struct V_441 * V_442 ;
T_2 V_15 ;
int V_16 ;
V_442 = F_18 ( sizeof( * V_442 ) , V_39 ) ;
if ( ! V_442 )
return - V_40 ;
F_39 ( V_65 , V_558 ,
V_559 ) ;
V_16 = F_9 ( V_2 , V_560 ,
V_65 , sizeof( V_65 ) , V_11 , sizeof( V_11 ) ,
& V_15 ) ;
if ( V_16 )
goto V_229;
V_557 = F_200 (
V_15 , V_561 ) ;
V_442 -> V_504 = 0 ;
for ( V_556 = 0 ; V_556 < V_557 ; V_556 ++ ) {
T_4 V_550 =
F_201 (
V_11 ,
V_561 ,
V_556 ) ;
V_16 = F_197 ( V_550 ) ;
if ( V_16 < 0 ) {
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_25 ,
V_238 , V_550 , V_556 ) ;
} else {
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_26 ,
V_238 , V_550 , V_556 ,
V_16 , V_442 -> V_504 ) ;
V_442 -> V_505 [ V_442 -> V_504 ++ ] = V_16 ;
}
}
V_442 -> V_444 = F_202 ( V_519 * sizeof( * V_442 -> V_444 ) ) ;
if ( ! V_442 -> V_444 ) {
V_16 = - V_40 ;
goto V_229;
}
V_2 -> V_508 = V_442 ;
F_203 ( & V_442 -> V_529 ) ;
return 0 ;
V_229:
F_32 ( V_442 ) ;
return V_16 ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_425 * V_432 ;
unsigned int V_443 ;
bool V_562 = false ;
int V_16 ;
if ( ! V_14 -> V_176 )
return;
F_176 ( & V_2 -> V_518 ) ;
for ( V_443 = 0 ; V_443 < V_519 ; V_443 ++ ) {
V_432 = F_163 ( V_442 , V_443 ) ;
if ( ! V_432 )
continue;
V_442 -> V_444 [ V_443 ] . V_432 |= V_520 ;
F_179 ( & V_2 -> V_518 ) ;
V_16 = F_169 ( V_2 , V_432 ,
& V_442 -> V_444 [ V_443 ] . V_446 ,
false ) ;
if ( V_16 )
V_562 = true ;
F_176 ( & V_2 -> V_518 ) ;
if ( V_16 ) {
F_32 ( V_432 ) ;
F_165 ( V_442 , V_443 , NULL , 0 ) ;
} else {
V_442 -> V_444 [ V_443 ] . V_432 &=
~ V_520 ;
}
}
F_179 ( & V_2 -> V_518 ) ;
if ( V_562 )
F_10 ( V_2 , V_226 , V_2 -> V_20 ,
L_27 ) ;
else
V_14 -> V_176 = false ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
F_7 ( V_65 , V_448 ) ;
struct V_425 * V_432 ;
unsigned int V_443 ;
int V_16 ;
for ( V_443 = 0 ; V_443 < V_519 ; V_443 ++ ) {
V_432 = F_163 ( V_442 , V_443 ) ;
if ( ! V_432 )
continue;
F_39 ( V_65 , V_449 ,
F_159 ( V_432 ) ?
V_540 :
V_533 ) ;
F_167 ( V_65 , V_451 ,
V_442 -> V_444 [ V_443 ] . V_446 ) ;
V_16 = F_9 ( V_2 , V_500 , V_65 , sizeof( V_65 ) ,
NULL , 0 , NULL ) ;
F_37 ( V_16 != 0 ) ;
F_32 ( V_432 ) ;
}
F_206 ( V_442 -> V_444 ) ;
F_32 ( V_442 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_441 * V_442 = V_2 -> V_508 ;
struct V_563 * V_20 = V_2 -> V_20 ;
struct V_425 V_432 ;
bool V_564 = false ;
struct V_565 * V_566 ;
struct V_565 * V_567 ;
unsigned int V_443 ;
int V_37 , V_568 , V_16 ;
if ( ! F_208 ( V_2 ) )
return;
F_176 ( & V_2 -> V_518 ) ;
V_568 = V_442 -> V_569 < 0 ? 1 : V_442 -> V_569 ;
for ( V_37 = 0 ; V_37 < V_568 ; V_37 ++ ) {
V_443 = V_442 -> V_570 [ V_37 ] . V_571 % V_519 ;
V_442 -> V_444 [ V_443 ] . V_432 |= V_531 ;
}
V_568 = V_442 -> V_572 < 0 ? 1 : V_442 -> V_572 ;
for ( V_37 = 0 ; V_37 < V_568 ; V_37 ++ ) {
V_443 = V_442 -> V_573 [ V_37 ] . V_571 % V_519 ;
V_442 -> V_444 [ V_443 ] . V_432 |= V_531 ;
}
F_179 ( & V_2 -> V_518 ) ;
F_209 ( V_20 ) ;
if ( V_20 -> V_81 & V_574 ||
F_210 ( V_20 ) >= V_575 ) {
V_442 -> V_569 = - 1 ;
} else {
V_442 -> V_569 = 1 + F_210 ( V_20 ) ;
memcpy ( V_442 -> V_570 [ 0 ] . V_111 , V_20 -> V_576 ,
V_36 ) ;
V_37 = 1 ;
F_211 (uc, net_dev) {
memcpy ( V_442 -> V_570 [ V_37 ] . V_111 ,
V_566 -> V_111 , V_36 ) ;
V_37 ++ ;
}
}
if ( V_20 -> V_81 & ( V_574 | V_577 ) ||
F_212 ( V_20 ) >= V_578 ) {
V_442 -> V_572 = - 1 ;
} else {
V_442 -> V_572 = 1 + F_212 ( V_20 ) ;
F_213 ( V_442 -> V_573 [ 0 ] . V_111 ) ;
V_37 = 1 ;
F_214 (mc, net_dev) {
memcpy ( V_442 -> V_573 [ V_37 ] . V_111 ,
V_567 -> V_111 , V_36 ) ;
V_37 ++ ;
}
}
F_215 ( V_20 ) ;
if ( V_442 -> V_569 >= 0 ) {
for ( V_37 = 0 ; V_37 < V_442 -> V_569 ; V_37 ++ ) {
F_216 ( & V_432 , V_522 ,
V_493 |
V_523 ,
0 ) ;
F_217 ( & V_432 , V_579 ,
V_442 -> V_570 [ V_37 ] . V_111 ) ;
V_16 = F_172 ( V_2 , & V_432 , true ) ;
if ( V_16 < 0 ) {
while ( V_37 -- )
F_187 (
V_2 , V_522 ,
V_442 -> V_570 [ V_37 ] . V_571 ) ;
V_442 -> V_569 = - 1 ;
break;
}
V_442 -> V_570 [ V_37 ] . V_571 = V_16 ;
}
}
if ( V_442 -> V_569 < 0 ) {
F_216 ( & V_432 , V_522 ,
V_493 |
V_523 ,
0 ) ;
F_218 ( & V_432 ) ;
V_16 = F_172 ( V_2 , & V_432 , true ) ;
if ( V_16 < 0 ) {
F_37 ( 1 ) ;
V_442 -> V_569 = 0 ;
} else {
V_442 -> V_570 [ 0 ] . V_571 = V_16 ;
}
}
if ( V_442 -> V_572 >= 0 ) {
for ( V_37 = 0 ; V_37 < V_442 -> V_572 ; V_37 ++ ) {
F_216 ( & V_432 , V_522 ,
V_493 |
V_523 ,
0 ) ;
F_217 ( & V_432 , V_579 ,
V_442 -> V_573 [ V_37 ] . V_111 ) ;
V_16 = F_172 ( V_2 , & V_432 , true ) ;
if ( V_16 < 0 ) {
while ( V_37 -- )
F_187 (
V_2 , V_522 ,
V_442 -> V_573 [ V_37 ] . V_571 ) ;
V_442 -> V_572 = - 1 ;
break;
}
V_442 -> V_573 [ V_37 ] . V_571 = V_16 ;
}
}
if ( V_442 -> V_572 < 0 ) {
F_216 ( & V_432 , V_522 ,
V_493 |
V_523 ,
0 ) ;
F_219 ( & V_432 ) ;
V_16 = F_172 ( V_2 , & V_432 , true ) ;
if ( V_16 < 0 ) {
F_37 ( 1 ) ;
V_442 -> V_572 = 0 ;
} else {
V_442 -> V_573 [ 0 ] . V_571 = V_16 ;
}
}
for ( V_37 = 0 ; V_37 < V_519 ; V_37 ++ ) {
if ( F_74 ( V_442 -> V_444 [ V_37 ] . V_432 ) &
V_531 ) {
if ( F_186 ( V_2 ,
V_522 ,
V_37 , true ) < 0 )
V_564 = true ;
}
}
F_37 ( V_564 ) ;
}
static int F_220 ( struct V_1 * V_2 )
{
F_207 ( V_2 ) ;
return F_221 ( V_2 ) ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_580 * V_581 ,
unsigned int type )
{
F_7 ( V_65 , V_582 ) ;
F_7 ( V_11 , V_583 ) ;
const struct V_584 * V_585 ;
T_2 V_542 , V_586 , V_15 ;
bool V_587 ;
int V_16 ;
for ( V_585 = V_588 ; ; V_585 ++ ) {
if ( V_585 ==
V_588 + F_100 ( V_588 ) )
return - V_24 ;
if ( ( type & ~ V_585 -> V_589 ) == V_585 -> type )
break;
}
if ( V_585 -> V_590 != F_223 ( V_2 ) )
return - V_24 ;
V_16 = F_224 ( V_2 , type , & V_542 , & V_586 , & V_587 ) ;
if ( V_16 )
return V_16 ;
if ( V_587 )
return - V_24 ;
V_581 -> V_591 = type ;
F_39 ( V_65 , V_592 , type ) ;
V_16 = F_9 ( V_2 , V_593 , V_65 , sizeof( V_65 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_594 )
return - V_7 ;
if ( F_11 ( V_11 , V_595 ) &
( 1 << V_596 ) )
V_581 -> V_597 = F_11 ( V_11 ,
V_598 ) ;
V_581 -> V_599 . V_600 = L_28 ;
V_581 -> V_599 . V_601 = V_585 -> V_126 ;
V_581 -> V_599 . V_602 . type = V_603 ;
V_581 -> V_599 . V_602 . V_81 = V_604 ;
V_581 -> V_599 . V_602 . V_542 = V_542 ;
V_581 -> V_599 . V_602 . V_605 = V_586 ;
return 0 ;
}
static int F_225 ( struct V_1 * V_2 )
{
F_7 ( V_11 , V_606 ) ;
struct V_580 * V_607 ;
T_2 V_15 , V_608 , V_37 , V_609 ;
unsigned int type ;
int V_16 ;
F_226 () ;
F_8 ( V_610 != 0 ) ;
V_16 = F_9 ( V_2 , V_611 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_612 )
return - V_7 ;
V_608 = F_11 ( V_11 , V_613 ) ;
if ( V_608 >
F_200 ( V_15 , V_614 ) )
return - V_7 ;
V_607 = F_227 ( V_608 , sizeof( * V_607 ) , V_39 ) ;
if ( ! V_607 )
return - V_40 ;
V_609 = 0 ;
for ( V_37 = 0 ; V_37 < V_608 ; V_37 ++ ) {
type = F_201 ( V_11 , V_614 ,
V_37 ) ;
V_16 = F_222 ( V_2 , & V_607 [ V_609 ] , type ) ;
if ( V_16 == 0 )
V_609 ++ ;
else if ( V_16 != - V_24 )
goto V_229;
}
V_16 = F_228 ( V_2 , & V_607 [ 0 ] . V_599 , V_609 , sizeof( * V_607 ) ) ;
V_229:
if ( V_16 )
F_32 ( V_607 ) ;
return V_16 ;
}
static void F_229 ( struct V_1 * V_2 , T_4 V_615 )
{
F_21 ( V_2 , F_22 ( V_615 ) , V_173 ) ;
}
