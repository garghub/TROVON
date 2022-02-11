static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
V_5 = F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
F_3 ( V_8 , V_9 ) ;
( void ) F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , ( V_3 ) ) ;
V_5 = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , ( V_3 ) ) ;
F_3 ( V_12 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
V_5 = F_4 ( V_14 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return V_5 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
F_3 ( V_14 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_16 , ( ( V_3 ) & 0x1ff ) ) ;
V_5 = F_4 ( V_17 ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
return V_5 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_16 , ( ( V_3 ) & 0x1ff ) ) ;
F_3 ( V_17 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_18 , V_4 ) ;
F_3 ( V_19 , ( V_3 ) ) ;
V_5 = F_4 ( V_20 ) ;
F_5 ( & V_2 -> V_18 , V_4 ) ;
return V_5 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_18 , V_4 ) ;
F_3 ( V_19 , ( V_3 ) ) ;
F_3 ( V_20 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_18 , V_4 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_21 , V_4 ) ;
F_3 ( V_22 , ( V_3 ) ) ;
V_5 = F_4 ( V_23 ) ;
F_5 ( & V_2 -> V_21 , V_4 ) ;
return V_5 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_21 , V_4 ) ;
F_3 ( V_22 , ( V_3 ) ) ;
F_3 ( V_23 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_21 , V_4 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_24 ) ;
switch ( V_2 -> V_25 ) {
case V_26 :
F_19 ( V_2 ,
V_27 ,
( const T_1 ) F_20 ( V_27 ) ) ;
break;
case V_28 :
F_19 ( V_2 ,
V_29 ,
( const T_1 ) F_20 ( V_29 ) ) ;
break;
case V_30 :
F_19 ( V_2 ,
V_31 ,
( const T_1 ) F_20 ( V_31 ) ) ;
break;
case V_32 :
F_19 ( V_2 ,
V_33 ,
( const T_1 ) F_20 ( V_33 ) ) ;
break;
case V_34 :
F_19 ( V_2 ,
V_35 ,
( const T_1 ) F_20 ( V_35 ) ) ;
break;
case V_36 :
case V_37 :
case V_38 :
default:
break;
}
F_21 ( & V_2 -> V_24 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
T_1 V_39 = V_2 -> clock . V_40 . V_41 ;
T_1 V_42 ;
if ( V_2 -> V_4 & V_43 )
return V_39 ;
V_42 = F_23 ( V_44 ) ;
if ( F_24 ( V_42 , V_45 , V_46 ) )
return 1000 ;
V_42 = F_23 ( V_47 ) ;
if ( F_24 ( V_42 , V_48 , V_49 ) )
return V_39 / 4 ;
return V_39 ;
}
void F_25 ( struct V_1 * V_2 ,
T_1 V_50 , T_1 V_51 , T_1 V_52 , T_1 V_53 )
{
T_1 V_54 = 0 ;
V_54 = F_26 ( V_54 , V_55 , V_56 , V_51 ) ;
V_54 = F_26 ( V_54 , V_55 , V_57 , V_50 ) ;
V_54 = F_26 ( V_54 , V_55 , V_58 , V_53 ) ;
V_54 = F_26 ( V_54 , V_55 , V_59 , V_52 ) ;
F_3 ( V_60 , V_54 ) ;
}
static void F_27 ( struct V_1 * V_2 , bool V_61 )
{
}
static bool F_28 ( struct V_1 * V_2 )
{
T_1 V_62 ;
T_1 V_63 = 0 ;
T_1 V_64 = 0 ;
T_1 V_65 = 0 ;
T_1 V_66 ;
bool V_5 ;
V_62 = F_4 ( V_67 ) ;
if ( V_2 -> V_68 . V_69 ) {
V_63 = F_4 ( V_70 ) ;
V_64 = F_4 ( V_71 ) ;
V_65 = F_4 ( V_72 ) ;
}
V_66 = F_23 ( V_73 ) ;
F_3 ( V_67 , ( V_62 & ~ V_74 ) ) ;
if ( V_2 -> V_68 . V_69 ) {
F_3 ( V_70 ,
( V_63 & ~ ( V_75 |
V_76 ) ) ) ;
F_3 ( V_71 ,
( V_64 & ~ ( V_77 |
V_78 ) ) ) ;
F_3 ( V_72 ,
( V_65 & ~ V_79 ) ) ;
}
F_29 ( V_73 , V_66 | V_80 ) ;
V_5 = F_30 ( V_2 ) ;
F_3 ( V_67 , V_62 ) ;
if ( V_2 -> V_68 . V_69 ) {
F_3 ( V_70 , V_63 ) ;
F_3 ( V_71 , V_64 ) ;
F_3 ( V_72 , V_65 ) ;
}
F_29 ( V_73 , V_66 ) ;
return V_5 ;
}
static bool F_31 ( struct V_1 * V_2 ,
T_2 * V_81 , T_1 V_82 )
{
T_1 * V_83 ;
unsigned long V_4 ;
T_1 V_84 , V_85 ;
if ( V_81 == NULL )
return false ;
if ( V_82 == 0 )
return false ;
if ( V_2 -> V_4 & V_43 )
return false ;
V_83 = ( T_1 * ) V_81 ;
V_85 = F_32 ( V_82 , 4 ) / 4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , V_86 ) ;
F_3 ( V_12 , 0 ) ;
F_3 ( V_11 , V_87 ) ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ )
V_83 [ V_84 ] = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return true ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_3 V_3 = F_4 ( V_88 ) ;
if ( V_3 & 1 )
V_2 -> V_89 . V_90 |= V_91 ;
if ( V_3 & 0x80000000 )
V_2 -> V_89 . V_90 |= V_92 ;
if ( V_3 == 0 ) {
if ( F_34 () )
V_2 -> V_89 . V_90 |= V_93 ;
}
}
static T_3 F_35 ( struct V_1 * V_2 ,
bool V_94 , T_1 V_95 ,
T_1 V_96 , T_1 V_97 )
{
if ( V_94 ) {
T_3 V_98 ;
unsigned V_99 = ( V_95 == 0xffffffff ) ? 0 : V_95 ;
unsigned V_100 = ( V_96 == 0xffffffff ) ? 0 : V_96 ;
switch ( V_97 ) {
case V_101 :
return V_2 -> V_102 . V_103 . V_104 [ V_99 ] [ V_100 ] . V_105 ;
case V_106 :
return V_2 -> V_102 . V_103 . V_104 [ V_99 ] [ V_100 ] . V_107 ;
case V_108 :
return V_2 -> V_102 . V_103 . V_104 [ V_99 ] [ V_100 ] . V_109 ;
case V_110 :
return V_2 -> V_102 . V_103 . V_104 [ V_99 ] [ V_100 ] . V_111 ;
}
F_18 ( & V_2 -> V_24 ) ;
if ( V_95 != 0xffffffff || V_96 != 0xffffffff )
F_36 ( V_2 , V_95 , V_96 , 0xffffffff ) ;
V_98 = F_4 ( V_97 ) ;
if ( V_95 != 0xffffffff || V_96 != 0xffffffff )
F_36 ( V_2 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_21 ( & V_2 -> V_24 ) ;
return V_98 ;
} else {
unsigned V_112 ;
switch ( V_97 ) {
case V_113 :
return V_2 -> V_102 . V_103 . V_114 ;
case V_115 :
return V_2 -> V_102 . V_103 . V_116 ;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_112 = ( V_97 - V_117 ) ;
return V_2 -> V_102 . V_103 . V_149 [ V_112 ] ;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_112 = ( V_97 - V_150 ) ;
return V_2 -> V_102 . V_103 . V_166 [ V_112 ] ;
default:
return F_4 ( V_97 ) ;
}
}
}
static int F_37 ( struct V_1 * V_2 , T_1 V_95 ,
T_1 V_96 , T_1 V_97 , T_1 * V_167 )
{
const struct V_168 * V_169 = NULL ;
const struct V_168 * V_170 ;
T_3 V_171 , V_84 ;
* V_167 = 0 ;
switch ( V_2 -> V_25 ) {
case V_26 :
V_169 = V_172 ;
V_171 = F_20 ( V_172 ) ;
break;
case V_28 :
case V_30 :
case V_36 :
case V_37 :
case V_38 :
case V_32 :
case V_34 :
V_169 = V_173 ;
V_171 = F_20 ( V_173 ) ;
break;
default:
return - V_174 ;
}
if ( V_169 ) {
for ( V_84 = 0 ; V_84 < V_171 ; V_84 ++ ) {
V_170 = V_169 + V_84 ;
if ( V_97 != V_170 -> V_97 )
continue;
if ( ! V_170 -> V_175 )
* V_167 = F_35 ( V_2 ,
V_170 -> V_176 ,
V_95 , V_96 , V_97 ) ;
return 0 ;
}
}
for ( V_84 = 0 ; V_84 < F_20 ( V_177 ) ; V_84 ++ ) {
if ( V_97 != V_177 [ V_84 ] . V_97 )
continue;
if ( ! V_177 [ V_84 ] . V_175 )
* V_167 = F_35 ( V_2 ,
V_177 [ V_84 ] . V_176 ,
V_95 , V_96 , V_97 ) ;
return 0 ;
}
return - V_174 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_84 ;
F_39 ( V_2 -> V_178 , L_1 ) ;
F_40 ( V_2 -> V_179 ) ;
F_41 ( V_2 ) ;
F_42 ( 100 ) ;
for ( V_84 = 0 ; V_84 < V_2 -> V_180 ; V_84 ++ ) {
if ( F_4 ( V_181 ) != 0xffffffff ) {
F_43 ( V_2 -> V_179 ) ;
return 0 ;
}
F_42 ( 1 ) ;
}
return - V_174 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_5 ;
F_45 ( V_2 , true ) ;
V_5 = F_38 ( V_2 ) ;
F_45 ( V_2 , false ) ;
return V_5 ;
}
static int F_46 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_182 , T_1 V_183 )
{
int V_5 , V_84 ;
struct V_184 V_185 ;
T_3 V_42 ;
V_5 = F_47 ( V_2 ,
V_186 ,
clock , false , & V_185 ) ;
if ( V_5 )
return V_5 ;
V_42 = F_23 ( V_182 ) ;
V_42 &= ~ ( V_187 |
V_188 ) ;
V_42 |= V_185 . V_189 ;
F_29 ( V_182 , V_42 ) ;
for ( V_84 = 0 ; V_84 < 100 ; V_84 ++ ) {
if ( F_23 ( V_183 ) & V_190 )
break;
F_48 ( 10 ) ;
}
if ( V_84 == 100 )
return - V_191 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_192 , T_1 V_193 )
{
int V_5 ;
V_5 = F_46 ( V_2 , V_192 , V_194 , V_195 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_46 ( V_2 , V_193 , V_196 , V_197 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_198 , T_1 V_199 )
{
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( F_52 ( V_2 -> V_179 -> V_200 ) )
return;
if ( V_201 == 0 )
return;
if ( V_2 -> V_4 & V_43 )
return;
if ( ! ( V_2 -> V_202 . V_203 & ( V_204 |
V_205 ) ) )
return;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_206 == 0 )
return;
}
static void F_54 ( struct V_1 * V_2 ,
bool V_207 )
{
T_1 V_42 ;
if ( V_2 -> V_4 & V_43 )
return;
V_42 = F_4 ( V_208 ) ;
if ( V_207 )
V_42 = F_26 ( V_42 , V_209 , V_209 , 1 ) ;
else
V_42 = F_26 ( V_42 , V_209 , V_209 , 0 ) ;
F_3 ( V_208 , V_42 ) ;
}
static T_3 F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_43 )
return ( F_23 ( V_210 ) & V_211 )
>> V_212 ;
else
return ( F_4 ( V_213 ) & V_214 )
>> V_215 ;
}
static int F_56 ( void * V_216 )
{
bool V_217 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_216 ;
if ( V_2 -> V_4 & V_43 ) {
V_2 -> V_218 = & F_9 ;
V_2 -> V_219 = & F_10 ;
} else {
V_2 -> V_218 = & F_7 ;
V_2 -> V_219 = & F_8 ;
}
V_2 -> V_220 = & F_1 ;
V_2 -> V_221 = & F_6 ;
V_2 -> V_222 = & F_11 ;
V_2 -> V_223 = & F_12 ;
V_2 -> V_224 = & F_13 ;
V_2 -> V_225 = & F_14 ;
V_2 -> V_226 = & F_15 ;
V_2 -> V_227 = & F_16 ;
V_2 -> V_228 = & V_229 ;
if ( F_57 ( V_2 , V_230 ) &&
( V_231 & ( 1 << V_230 ) ) )
V_217 = true ;
V_2 -> V_232 = F_55 ( V_2 ) ;
V_2 -> V_233 = 0xFF ;
switch ( V_2 -> V_25 ) {
case V_26 :
V_2 -> V_234 = 0 ;
V_2 -> V_235 = 0 ;
V_2 -> V_233 = 0x1 ;
break;
case V_28 :
V_2 -> V_234 = V_236 |
V_237 |
V_238 |
V_239 |
V_240 |
V_241 |
V_242 |
V_243 |
V_244 |
V_245 |
V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_251 |
V_252 ;
V_2 -> V_235 = 0 ;
V_2 -> V_233 = V_2 -> V_232 + 0x3c ;
break;
case V_30 :
V_2 -> V_234 = V_236 |
V_242 |
V_243 |
V_244 |
V_245 |
V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_251 |
V_253 |
V_252 ;
V_2 -> V_235 = 0 ;
V_2 -> V_233 = V_2 -> V_232 + 0x14 ;
break;
case V_36 :
V_2 -> V_234 = V_236 |
V_238 |
V_239 |
V_242 |
V_243 |
V_254 |
V_255 |
V_244 |
V_245 |
V_256 |
V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_251 |
V_253 |
V_252 |
V_257 ;
V_2 -> V_235 = 0 ;
V_2 -> V_233 = V_2 -> V_232 + 0x5A ;
break;
case V_37 :
V_2 -> V_234 = V_236 |
V_238 |
V_239 |
V_242 |
V_243 |
V_254 |
V_255 |
V_244 |
V_245 |
V_256 |
V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_251 |
V_253 |
V_252 |
V_257 ;
V_2 -> V_235 = 0 ;
V_2 -> V_233 = V_2 -> V_232 + 0x50 ;
break;
case V_38 :
V_2 -> V_234 = V_252 ;
V_2 -> V_235 = 0 ;
V_2 -> V_233 = V_2 -> V_232 + 0x64 ;
break;
case V_32 :
V_2 -> V_234 = V_252 |
V_236 |
V_237 |
V_238 |
V_239 |
V_240 |
V_237 |
V_241 |
V_242 |
V_243 |
V_246 |
V_247 |
V_248 |
V_244 |
V_245 |
V_257 ;
V_2 -> V_235 = 0 ;
if ( V_2 -> V_232 != 0x00 ) {
V_2 -> V_235 |= V_258 |
V_259 |
V_260 |
V_261 |
V_262 |
V_263 ;
}
V_2 -> V_233 = V_2 -> V_232 + 0x1 ;
break;
case V_34 :
V_2 -> V_234 = V_252 |
V_236 |
V_237 |
V_238 |
V_239 |
V_240 |
V_237 |
V_241 |
V_242 |
V_243 |
V_246 |
V_247 |
V_248 |
V_244 |
V_245 |
V_257 ;
V_2 -> V_235 = V_258 |
V_259 |
V_260 |
V_261 |
V_262 |
V_263 ;
V_2 -> V_233 = V_2 -> V_232 + 0x61 ;
break;
default:
return - V_174 ;
}
if ( V_2 -> V_228 -> V_264 )
F_58 ( V_2 ) ;
if ( V_265 && V_217 )
V_2 -> V_266 . V_267 = true ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_60 ( void * V_216 )
{
return 0 ;
}
static int F_61 ( void * V_216 )
{
return 0 ;
}
static int F_62 ( void * V_216 )
{
struct V_1 * V_2 = (struct V_1 * ) V_216 ;
F_17 ( V_2 ) ;
F_51 ( V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 , true ) ;
return 0 ;
}
static int F_63 ( void * V_216 )
{
struct V_1 * V_2 = (struct V_1 * ) V_216 ;
F_54 ( V_2 , false ) ;
return 0 ;
}
static int F_64 ( void * V_216 )
{
struct V_1 * V_2 = (struct V_1 * ) V_216 ;
return F_63 ( V_2 ) ;
}
static int F_65 ( void * V_216 )
{
struct V_1 * V_2 = (struct V_1 * ) V_216 ;
return F_62 ( V_2 ) ;
}
static bool F_66 ( void * V_216 )
{
return true ;
}
static int F_67 ( void * V_216 )
{
return 0 ;
}
static int F_68 ( void * V_216 )
{
return 0 ;
}
static void F_69 ( struct V_1 * V_2 ,
bool V_207 )
{
T_3 V_268 , V_269 ;
V_268 = V_269 = F_70 ( V_270 ) ;
if ( V_207 && ( V_2 -> V_234 & V_246 ) )
V_269 |= V_271 |
V_272 |
V_273 ;
else
V_269 &= ~ ( V_271 |
V_272 |
V_273 ) ;
if ( V_268 != V_269 )
F_71 ( V_270 , V_269 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
bool V_207 )
{
T_3 V_268 , V_269 ;
V_268 = V_269 = F_4 ( V_274 ) ;
if ( V_207 && ( V_2 -> V_234 & V_247 ) )
V_269 &= ~ V_275 ;
else
V_269 |= V_275 ;
if ( V_268 != V_269 )
F_3 ( V_274 , V_269 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
bool V_207 )
{
T_3 V_268 , V_269 ;
V_268 = V_269 = F_4 ( V_276 ) ;
if ( V_207 && ( V_2 -> V_234 & V_248 ) )
V_269 |= V_277 ;
else
V_269 &= ~ V_277 ;
if ( V_268 != V_269 )
F_3 ( V_276 , V_269 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
bool V_207 )
{
T_3 V_268 , V_269 ;
V_268 = V_269 = F_23 ( V_278 ) ;
if ( V_207 && ( V_2 -> V_234 & V_249 ) )
V_269 &= ~ ( V_279 |
V_280 ) ;
else
V_269 |= V_279 |
V_280 ;
if ( V_268 != V_269 )
F_29 ( V_278 , V_269 ) ;
}
static int F_75 ( void * V_216 ,
enum V_281 V_61 )
{
T_3 V_282 , V_283 = 0 ;
T_3 V_284 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_216 ;
void * V_285 = V_2 -> V_286 . V_285 ;
if ( V_2 -> V_234 & ( V_251 | V_250 ) ) {
if ( V_2 -> V_234 & V_251 ) {
V_284 = V_251 ;
V_283 = V_287 ;
}
if ( V_2 -> V_234 & V_250 ) {
V_284 |= V_250 ;
V_283 |= V_288 ;
}
if ( V_61 == V_289 )
V_283 = 0 ;
V_282 = F_76 ( V_290 ,
V_291 ,
V_284 ,
V_283 ) ;
F_77 ( V_285 , V_282 ) ;
}
if ( V_2 -> V_234 & ( V_245 | V_244 ) ) {
if ( V_2 -> V_234 & V_245 ) {
V_284 = V_245 ;
V_283 = V_287 ;
}
if ( V_2 -> V_234 & V_244 ) {
V_284 |= V_244 ;
V_283 |= V_288 ;
}
if ( V_61 == V_289 )
V_283 = 0 ;
V_282 = F_76 ( V_290 ,
V_292 ,
V_284 ,
V_283 ) ;
F_77 ( V_285 , V_282 ) ;
}
if ( V_2 -> V_234 & ( V_248 | V_247 ) ) {
if ( V_2 -> V_234 & V_248 ) {
V_284 = V_248 ;
V_283 = V_287 ;
}
if ( V_2 -> V_234 & V_247 ) {
V_284 |= V_247 ;
V_283 |= V_288 ;
}
if ( V_61 == V_289 )
V_283 = 0 ;
V_282 = F_76 ( V_290 ,
V_293 ,
V_284 ,
V_283 ) ;
F_77 ( V_285 , V_282 ) ;
}
if ( V_2 -> V_234 & V_246 ) {
if ( V_61 == V_289 )
V_283 = 0 ;
else
V_283 = V_287 ;
V_282 = F_76 ( V_290 ,
V_294 ,
V_295 ,
V_283 ) ;
F_77 ( V_285 , V_282 ) ;
}
if ( V_2 -> V_234 & V_256 ) {
if ( V_61 == V_289 )
V_283 = 0 ;
else
V_283 = V_288 ;
V_282 = F_76 ( V_290 ,
V_294 ,
V_296 ,
V_283 ) ;
F_77 ( V_285 , V_282 ) ;
}
if ( V_2 -> V_234 & V_253 ) {
if ( V_61 == V_289 )
V_283 = 0 ;
else
V_283 = V_287 ;
V_282 = F_76 ( V_290 ,
V_297 ,
V_295 ,
V_283 ) ;
F_77 ( V_285 , V_282 ) ;
}
if ( V_2 -> V_234 & V_249 ) {
if ( V_61 == V_289 )
V_283 = 0 ;
else
V_283 = V_288 ;
V_282 = F_76 ( V_290 ,
V_298 ,
V_296 ,
V_283 ) ;
F_77 ( V_285 , V_282 ) ;
}
return 0 ;
}
static int F_78 ( void * V_216 ,
enum V_281 V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_216 ;
switch ( V_2 -> V_25 ) {
case V_28 :
F_69 ( V_2 ,
V_61 == V_299 ? true : false ) ;
F_72 ( V_2 ,
V_61 == V_299 ? true : false ) ;
F_73 ( V_2 ,
V_61 == V_299 ? true : false ) ;
F_74 ( V_2 ,
V_61 == V_299 ? true : false ) ;
break;
case V_32 :
case V_34 :
F_69 ( V_2 ,
V_61 == V_299 ? true : false ) ;
F_72 ( V_2 ,
V_61 == V_299 ? true : false ) ;
F_73 ( V_2 ,
V_61 == V_299 ? true : false ) ;
break;
case V_30 :
case V_37 :
case V_36 :
case V_38 :
F_75 ( V_2 , V_61 ) ;
default:
break;
}
return 0 ;
}
static int F_79 ( void * V_216 ,
enum V_300 V_61 )
{
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_25 ) {
case V_26 :
F_81 ( V_2 , & V_301 ) ;
F_81 ( V_2 , & V_302 ) ;
F_81 ( V_2 , & V_303 ) ;
F_81 ( V_2 , & V_304 ) ;
if ( V_2 -> V_305 )
F_81 ( V_2 , & V_306 ) ;
F_81 ( V_2 , & V_307 ) ;
F_81 ( V_2 , & V_308 ) ;
break;
case V_28 :
F_81 ( V_2 , & V_301 ) ;
F_81 ( V_2 , & V_309 ) ;
F_81 ( V_2 , & V_310 ) ;
F_81 ( V_2 , & V_304 ) ;
if ( V_2 -> V_305 )
F_81 ( V_2 , & V_306 ) ;
else
F_81 ( V_2 , & V_311 ) ;
F_81 ( V_2 , & V_307 ) ;
F_81 ( V_2 , & V_312 ) ;
F_81 ( V_2 , & V_313 ) ;
F_81 ( V_2 , & V_314 ) ;
break;
case V_30 :
F_81 ( V_2 , & V_301 ) ;
F_81 ( V_2 , & V_315 ) ;
F_81 ( V_2 , & V_310 ) ;
F_81 ( V_2 , & V_304 ) ;
if ( V_2 -> V_305 )
F_81 ( V_2 , & V_306 ) ;
else
F_81 ( V_2 , & V_316 ) ;
F_81 ( V_2 , & V_307 ) ;
F_81 ( V_2 , & V_312 ) ;
F_81 ( V_2 , & V_317 ) ;
F_81 ( V_2 , & V_314 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
F_81 ( V_2 , & V_301 ) ;
F_81 ( V_2 , & V_318 ) ;
F_81 ( V_2 , & V_310 ) ;
F_81 ( V_2 , & V_304 ) ;
if ( V_2 -> V_305 )
F_81 ( V_2 , & V_306 ) ;
else
F_81 ( V_2 , & V_319 ) ;
F_81 ( V_2 , & V_307 ) ;
F_81 ( V_2 , & V_320 ) ;
F_81 ( V_2 , & V_321 ) ;
F_81 ( V_2 , & V_322 ) ;
break;
case V_32 :
F_81 ( V_2 , & V_301 ) ;
F_81 ( V_2 , & V_315 ) ;
F_81 ( V_2 , & V_323 ) ;
F_81 ( V_2 , & V_304 ) ;
if ( V_2 -> V_305 )
F_81 ( V_2 , & V_306 ) ;
else
F_81 ( V_2 , & V_324 ) ;
F_81 ( V_2 , & V_307 ) ;
F_81 ( V_2 , & V_312 ) ;
F_81 ( V_2 , & V_313 ) ;
F_81 ( V_2 , & V_325 ) ;
#if F_82 ( V_326 )
F_81 ( V_2 , & V_327 ) ;
#endif
break;
case V_34 :
F_81 ( V_2 , & V_301 ) ;
F_81 ( V_2 , & V_315 ) ;
F_81 ( V_2 , & V_323 ) ;
F_81 ( V_2 , & V_304 ) ;
if ( V_2 -> V_305 )
F_81 ( V_2 , & V_306 ) ;
else
F_81 ( V_2 , & V_324 ) ;
F_81 ( V_2 , & V_328 ) ;
F_81 ( V_2 , & V_312 ) ;
F_81 ( V_2 , & V_329 ) ;
F_81 ( V_2 , & V_322 ) ;
#if F_82 ( V_326 )
F_81 ( V_2 , & V_327 ) ;
#endif
break;
default:
return - V_174 ;
}
return 0 ;
}
