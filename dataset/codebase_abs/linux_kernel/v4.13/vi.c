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
if ( F_19 ( V_2 ) ) {
F_20 ( V_2 ) ;
F_21 ( & V_2 -> V_24 ) ;
return;
}
switch ( V_2 -> V_25 ) {
case V_26 :
F_22 ( V_2 ,
V_27 ,
( const T_1 ) F_23 ( V_27 ) ) ;
break;
case V_28 :
F_22 ( V_2 ,
V_29 ,
( const T_1 ) F_23 ( V_29 ) ) ;
break;
case V_30 :
F_22 ( V_2 ,
V_31 ,
( const T_1 ) F_23 ( V_31 ) ) ;
break;
case V_32 :
F_22 ( V_2 ,
V_33 ,
( const T_1 ) F_23 ( V_33 ) ) ;
break;
case V_34 :
F_22 ( V_2 ,
V_35 ,
( const T_1 ) F_23 ( V_35 ) ) ;
break;
case V_36 :
case V_37 :
case V_38 :
default:
break;
}
F_21 ( & V_2 -> V_24 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
T_1 V_39 = V_2 -> clock . V_40 . V_41 ;
T_1 V_42 ;
if ( V_2 -> V_4 & V_43 )
return V_39 ;
V_42 = F_25 ( V_44 ) ;
if ( F_26 ( V_42 , V_45 , V_46 ) )
return 1000 ;
V_42 = F_25 ( V_47 ) ;
if ( F_26 ( V_42 , V_48 , V_49 ) )
return V_39 / 4 ;
return V_39 ;
}
void F_27 ( struct V_1 * V_2 ,
T_1 V_50 , T_1 V_51 , T_1 V_52 , T_1 V_53 )
{
T_1 V_54 = 0 ;
V_54 = F_28 ( V_54 , V_55 , V_56 , V_51 ) ;
V_54 = F_28 ( V_54 , V_55 , V_57 , V_50 ) ;
V_54 = F_28 ( V_54 , V_55 , V_58 , V_53 ) ;
V_54 = F_28 ( V_54 , V_55 , V_59 , V_52 ) ;
F_3 ( V_60 , V_54 ) ;
}
static void F_29 ( struct V_1 * V_2 , bool V_61 )
{
}
static bool F_30 ( struct V_1 * V_2 )
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
V_66 = F_25 ( V_73 ) ;
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
F_31 ( V_73 , V_66 | V_80 ) ;
V_5 = F_32 ( V_2 ) ;
F_3 ( V_67 , V_62 ) ;
if ( V_2 -> V_68 . V_69 ) {
F_3 ( V_70 , V_63 ) ;
F_3 ( V_71 , V_64 ) ;
F_3 ( V_72 , V_65 ) ;
}
F_31 ( V_73 , V_66 ) ;
return V_5 ;
}
static bool F_33 ( struct V_1 * V_2 ,
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
V_85 = F_34 ( V_82 , 4 ) / 4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , V_86 ) ;
F_3 ( V_12 , 0 ) ;
F_3 ( V_11 , V_87 ) ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ )
V_83 [ V_84 ] = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return true ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_3 V_3 = F_4 ( V_88 ) ;
if ( V_3 & 1 )
V_2 -> V_89 . V_90 |= V_91 ;
if ( V_3 & 0x80000000 )
V_2 -> V_89 . V_90 |= V_92 ;
if ( V_3 == 0 ) {
if ( F_36 () )
V_2 -> V_89 . V_90 |= V_93 ;
}
}
static T_3 F_37 ( struct V_1 * V_2 ,
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
F_38 ( V_2 , V_95 , V_96 , 0xffffffff ) ;
V_98 = F_4 ( V_97 ) ;
if ( V_95 != 0xffffffff || V_96 != 0xffffffff )
F_38 ( V_2 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
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
static int F_39 ( struct V_1 * V_2 , T_1 V_95 ,
T_1 V_96 , T_1 V_97 , T_1 * V_167 )
{
T_3 V_84 ;
* V_167 = 0 ;
for ( V_84 = 0 ; V_84 < F_23 ( V_168 ) ; V_84 ++ ) {
bool V_94 = V_168 [ V_84 ] . V_169 ;
if ( V_97 != V_168 [ V_84 ] . V_97 )
continue;
* V_167 = F_37 ( V_2 , V_94 , V_95 , V_96 ,
V_97 ) ;
return 0 ;
}
return - V_170 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_84 ;
F_41 ( V_2 -> V_171 , L_1 ) ;
F_42 ( V_2 -> V_172 ) ;
F_43 ( V_2 ) ;
F_44 ( 100 ) ;
for ( V_84 = 0 ; V_84 < V_2 -> V_173 ; V_84 ++ ) {
if ( F_4 ( V_174 ) != 0xffffffff ) {
F_45 ( V_2 -> V_172 ) ;
V_2 -> V_175 = true ;
return 0 ;
}
F_44 ( 1 ) ;
}
return - V_170 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_5 ;
F_47 ( V_2 , true ) ;
V_5 = F_40 ( V_2 ) ;
F_47 ( V_2 , false ) ;
return V_5 ;
}
static T_1 F_48 ( struct V_1 * V_2 )
{
return F_4 ( V_174 ) ;
}
static int F_49 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_176 , T_1 V_177 )
{
int V_5 , V_84 ;
struct V_178 V_179 ;
T_3 V_42 ;
V_5 = F_50 ( V_2 ,
V_180 ,
clock , false , & V_179 ) ;
if ( V_5 )
return V_5 ;
V_42 = F_25 ( V_176 ) ;
V_42 &= ~ ( V_181 |
V_182 ) ;
V_42 |= V_179 . V_183 ;
F_31 ( V_176 , V_42 ) ;
for ( V_84 = 0 ; V_84 < 100 ; V_84 ++ ) {
if ( F_25 ( V_177 ) & V_184 )
break;
F_51 ( 10 ) ;
}
if ( V_84 == 100 )
return - V_185 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , T_1 V_186 , T_1 V_187 )
{
int V_5 ;
V_5 = F_49 ( V_2 , V_186 , V_188 , V_189 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_49 ( V_2 , V_187 , V_190 , V_191 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_192 , T_1 V_193 )
{
int V_5 , V_84 ;
struct V_178 V_179 ;
T_1 V_42 ;
V_5 = F_50 ( V_2 ,
V_180 ,
V_193 , false , & V_179 ) ;
if ( V_5 )
return V_5 ;
for ( V_84 = 0 ; V_84 < 100 ; V_84 ++ ) {
if ( F_25 ( V_194 ) & V_195 )
break;
F_51 ( 10 ) ;
}
if ( V_84 == 100 )
return - V_185 ;
V_42 = F_25 ( V_196 ) ;
V_42 &= ~ ( V_197 |
V_198 ) ;
V_42 |= V_179 . V_183 ;
F_31 ( V_196 , V_42 ) ;
for ( V_84 = 0 ; V_84 < 100 ; V_84 ++ ) {
if ( F_25 ( V_194 ) & V_195 )
break;
F_51 ( 10 ) ;
}
if ( V_84 == 100 )
return - V_185 ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_55 ( V_2 -> V_172 -> V_199 ) )
return;
if ( V_200 == 0 )
return;
if ( V_2 -> V_4 & V_43 )
return;
if ( ! ( V_2 -> V_201 . V_202 & ( V_203 |
V_204 ) ) )
return;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_205 == 0 )
return;
}
static void F_57 ( struct V_1 * V_2 ,
bool V_206 )
{
T_1 V_42 ;
if ( V_2 -> V_4 & V_43 )
return;
V_42 = F_4 ( V_207 ) ;
if ( V_206 )
V_42 = F_28 ( V_42 , V_208 , V_208 , 1 ) ;
else
V_42 = F_28 ( V_42 , V_208 , V_208 , 0 ) ;
F_3 ( V_207 , V_42 ) ;
}
static T_3 F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_43 )
return ( F_25 ( V_209 ) & V_210 )
>> V_211 ;
else
return ( F_4 ( V_212 ) & V_213 )
>> V_214 ;
}
static int F_59 ( void * V_215 )
{
bool V_216 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
if ( V_2 -> V_4 & V_43 ) {
V_2 -> V_217 = & F_9 ;
V_2 -> V_218 = & F_10 ;
} else {
V_2 -> V_217 = & F_7 ;
V_2 -> V_218 = & F_8 ;
}
V_2 -> V_219 = & F_1 ;
V_2 -> V_220 = & F_6 ;
V_2 -> V_221 = & F_11 ;
V_2 -> V_222 = & F_12 ;
V_2 -> V_223 = & F_13 ;
V_2 -> V_224 = & F_14 ;
V_2 -> V_225 = & F_15 ;
V_2 -> V_226 = & F_16 ;
V_2 -> V_227 = & V_228 ;
if ( F_60 ( V_2 , V_229 ) &&
( V_230 & ( 1 << V_229 ) ) )
V_216 = true ;
V_2 -> V_231 = F_58 ( V_2 ) ;
V_2 -> V_232 = 0xFF ;
switch ( V_2 -> V_25 ) {
case V_26 :
V_2 -> V_233 = 0 ;
V_2 -> V_234 = 0 ;
V_2 -> V_232 = 0x1 ;
break;
case V_28 :
V_2 -> V_233 = V_235 |
V_236 |
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
V_251 ;
V_2 -> V_234 = 0 ;
V_2 -> V_232 = V_2 -> V_231 + 0x3c ;
break;
case V_30 :
V_2 -> V_233 = V_235 |
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
V_252 |
V_251 ;
V_2 -> V_234 = 0 ;
V_2 -> V_232 = V_2 -> V_231 + 0x14 ;
break;
case V_36 :
V_2 -> V_233 = V_235 |
V_237 |
V_238 |
V_241 |
V_242 |
V_253 |
V_254 |
V_243 |
V_244 |
V_255 |
V_245 |
V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_252 |
V_251 |
V_256 ;
V_2 -> V_234 = 0 ;
V_2 -> V_232 = V_2 -> V_231 + 0x5A ;
break;
case V_37 :
V_2 -> V_233 = V_235 |
V_237 |
V_238 |
V_241 |
V_242 |
V_253 |
V_254 |
V_243 |
V_244 |
V_255 |
V_245 |
V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_252 |
V_251 |
V_256 ;
V_2 -> V_234 = 0 ;
V_2 -> V_232 = V_2 -> V_231 + 0x50 ;
break;
case V_38 :
V_2 -> V_233 = V_235 |
V_237 |
V_238 |
V_241 |
V_242 |
V_253 |
V_254 |
V_243 |
V_244 |
V_255 |
V_245 |
V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_252 |
V_251 |
V_256 ;
V_2 -> V_234 = 0 ;
V_2 -> V_232 = V_2 -> V_231 + 0x64 ;
break;
case V_32 :
V_2 -> V_233 = V_251 |
V_235 |
V_236 |
V_237 |
V_238 |
V_239 |
V_240 |
V_241 |
V_242 |
V_245 |
V_246 |
V_247 |
V_243 |
V_244 |
V_256 ;
V_2 -> V_234 = 0 ;
if ( V_2 -> V_231 != 0x00 || F_61 ( V_2 -> V_172 -> V_257 ) ) {
V_2 -> V_234 |= V_258 |
V_259 |
V_260 |
V_261 |
V_262 |
V_263 ;
}
V_2 -> V_232 = V_2 -> V_231 + 0x1 ;
break;
case V_34 :
V_2 -> V_233 = V_251 |
V_235 |
V_236 |
V_237 |
V_238 |
V_239 |
V_240 |
V_241 |
V_242 |
V_245 |
V_246 |
V_247 |
V_243 |
V_244 |
V_256 ;
V_2 -> V_234 = V_258 |
V_259 |
V_260 |
V_261 |
V_262 |
V_263 ;
V_2 -> V_232 = V_2 -> V_231 + 0x61 ;
break;
default:
return - V_170 ;
}
if ( F_19 ( V_2 ) ) {
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
}
V_2 -> V_264 . V_265 = F_64 ( V_2 , V_266 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
static int F_66 ( void * V_215 )
{
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
if ( F_19 ( V_2 ) )
F_67 ( V_2 ) ;
return 0 ;
}
static int F_68 ( void * V_215 )
{
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
if ( F_19 ( V_2 ) )
F_69 ( V_2 ) ;
return 0 ;
}
static int F_70 ( void * V_215 )
{
return 0 ;
}
static int F_71 ( void * V_215 )
{
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
F_17 ( V_2 ) ;
F_54 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 , true ) ;
return 0 ;
}
static int F_72 ( void * V_215 )
{
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
F_57 ( V_2 , false ) ;
if ( F_19 ( V_2 ) )
F_73 ( V_2 ) ;
return 0 ;
}
static int F_74 ( void * V_215 )
{
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
return F_72 ( V_2 ) ;
}
static int F_75 ( void * V_215 )
{
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
return F_71 ( V_2 ) ;
}
static bool F_76 ( void * V_215 )
{
return true ;
}
static int F_77 ( void * V_215 )
{
return 0 ;
}
static int F_78 ( void * V_215 )
{
return 0 ;
}
static void F_79 ( struct V_1 * V_2 ,
bool V_206 )
{
T_3 V_267 , V_268 ;
V_267 = V_268 = F_80 ( V_269 ) ;
if ( V_206 && ( V_2 -> V_233 & V_245 ) )
V_268 |= V_270 |
V_271 |
V_272 ;
else
V_268 &= ~ ( V_270 |
V_271 |
V_272 ) ;
if ( V_267 != V_268 )
F_81 ( V_269 , V_268 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
bool V_206 )
{
T_3 V_267 , V_268 ;
V_267 = V_268 = F_4 ( V_273 ) ;
if ( V_206 && ( V_2 -> V_233 & V_246 ) )
V_268 &= ~ V_274 ;
else
V_268 |= V_274 ;
if ( V_267 != V_268 )
F_3 ( V_273 , V_268 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
bool V_206 )
{
T_3 V_267 , V_268 ;
V_267 = V_268 = F_4 ( V_275 ) ;
if ( V_206 && ( V_2 -> V_233 & V_247 ) )
V_268 |= V_276 ;
else
V_268 &= ~ V_276 ;
if ( V_267 != V_268 )
F_3 ( V_275 , V_268 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
bool V_206 )
{
T_3 V_267 , V_268 ;
V_267 = V_268 = F_4 ( 0x157a ) ;
if ( V_206 && ( V_2 -> V_233 & V_252 ) )
V_268 |= 1 ;
else
V_268 &= ~ 1 ;
if ( V_267 != V_268 )
F_3 ( 0x157a , V_268 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
bool V_206 )
{
T_3 V_267 , V_268 ;
V_267 = V_268 = F_25 ( V_277 ) ;
if ( V_206 && ( V_2 -> V_233 & V_248 ) )
V_268 &= ~ ( V_278 |
V_279 ) ;
else
V_268 |= V_278 |
V_279 ;
if ( V_267 != V_268 )
F_31 ( V_277 , V_268 ) ;
}
static int F_86 ( void * V_215 ,
enum V_280 V_61 )
{
T_3 V_281 , V_282 = 0 ;
T_3 V_283 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
void * V_284 = V_2 -> V_285 . V_284 ;
if ( V_2 -> V_233 & ( V_250 | V_249 ) ) {
if ( V_2 -> V_233 & V_250 ) {
V_283 = V_250 ;
V_282 = V_286 ;
}
if ( V_2 -> V_233 & V_249 ) {
V_283 |= V_249 ;
V_282 |= V_287 ;
}
if ( V_61 == V_288 )
V_282 = 0 ;
V_281 = F_87 ( V_289 ,
V_290 ,
V_283 ,
V_282 ) ;
F_88 ( V_284 , V_281 ) ;
}
if ( V_2 -> V_233 & ( V_244 | V_243 ) ) {
if ( V_2 -> V_233 & V_244 ) {
V_283 = V_244 ;
V_282 = V_286 ;
}
if ( V_2 -> V_233 & V_243 ) {
V_283 |= V_243 ;
V_282 |= V_287 ;
}
if ( V_61 == V_288 )
V_282 = 0 ;
V_281 = F_87 ( V_289 ,
V_291 ,
V_283 ,
V_282 ) ;
F_88 ( V_284 , V_281 ) ;
}
if ( V_2 -> V_233 & ( V_247 | V_246 ) ) {
if ( V_2 -> V_233 & V_247 ) {
V_283 = V_247 ;
V_282 = V_286 ;
}
if ( V_2 -> V_233 & V_246 ) {
V_283 |= V_246 ;
V_282 |= V_287 ;
}
if ( V_61 == V_288 )
V_282 = 0 ;
V_281 = F_87 ( V_289 ,
V_292 ,
V_283 ,
V_282 ) ;
F_88 ( V_284 , V_281 ) ;
}
if ( V_2 -> V_233 & V_245 ) {
if ( V_61 == V_288 )
V_282 = 0 ;
else
V_282 = V_286 ;
V_281 = F_87 ( V_289 ,
V_293 ,
V_294 ,
V_282 ) ;
F_88 ( V_284 , V_281 ) ;
}
if ( V_2 -> V_233 & V_255 ) {
if ( V_61 == V_288 )
V_282 = 0 ;
else
V_282 = V_287 ;
V_281 = F_87 ( V_289 ,
V_293 ,
V_295 ,
V_282 ) ;
F_88 ( V_284 , V_281 ) ;
}
if ( V_2 -> V_233 & V_252 ) {
if ( V_61 == V_288 )
V_282 = 0 ;
else
V_282 = V_286 ;
V_281 = F_87 ( V_289 ,
V_296 ,
V_294 ,
V_282 ) ;
F_88 ( V_284 , V_281 ) ;
}
if ( V_2 -> V_233 & V_248 ) {
if ( V_61 == V_288 )
V_282 = 0 ;
else
V_282 = V_287 ;
V_281 = F_87 ( V_289 ,
V_297 ,
V_295 ,
V_282 ) ;
F_88 ( V_284 , V_281 ) ;
}
return 0 ;
}
static int F_89 ( void * V_215 ,
enum V_280 V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
if ( F_19 ( V_2 ) )
return 0 ;
switch ( V_2 -> V_25 ) {
case V_28 :
F_79 ( V_2 ,
V_61 == V_298 ) ;
F_82 ( V_2 ,
V_61 == V_298 ) ;
F_83 ( V_2 ,
V_61 == V_298 ) ;
F_85 ( V_2 ,
V_61 == V_298 ) ;
break;
case V_32 :
case V_34 :
F_79 ( V_2 ,
V_61 == V_298 ) ;
F_82 ( V_2 ,
V_61 == V_298 ) ;
F_83 ( V_2 ,
V_61 == V_298 ) ;
F_84 ( V_2 ,
V_61 == V_298 ) ;
break;
case V_30 :
case V_37 :
case V_36 :
case V_38 :
F_86 ( V_2 , V_61 ) ;
default:
break;
}
return 0 ;
}
static int F_90 ( void * V_215 ,
enum V_299 V_61 )
{
return 0 ;
}
static void F_91 ( void * V_215 , T_1 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_215 ;
int V_268 ;
if ( F_19 ( V_2 ) )
* V_4 = 0 ;
V_268 = F_80 ( V_269 ) ;
if ( V_268 & V_270 )
* V_4 |= V_245 ;
V_268 = F_4 ( V_275 ) ;
if ( V_268 & V_276 )
* V_4 |= V_247 ;
V_268 = F_4 ( V_273 ) ;
if ( ! ( V_268 & V_274 ) )
* V_4 |= V_246 ;
V_268 = F_25 ( V_277 ) ;
if ( ! ( V_268 & V_278 ) )
* V_4 |= V_248 ;
}
int F_92 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
if ( F_19 ( V_2 ) )
V_2 -> V_89 . V_300 = & V_301 ;
switch ( V_2 -> V_25 ) {
case V_26 :
F_93 ( V_2 , & V_302 ) ;
F_93 ( V_2 , & V_303 ) ;
F_93 ( V_2 , & V_304 ) ;
F_93 ( V_2 , & V_305 ) ;
if ( V_2 -> V_306 )
F_93 ( V_2 , & V_307 ) ;
F_93 ( V_2 , & V_308 ) ;
F_93 ( V_2 , & V_309 ) ;
break;
case V_28 :
F_93 ( V_2 , & V_302 ) ;
F_93 ( V_2 , & V_310 ) ;
F_93 ( V_2 , & V_311 ) ;
F_93 ( V_2 , & V_305 ) ;
if ( V_2 -> V_306 || F_19 ( V_2 ) )
F_93 ( V_2 , & V_307 ) ;
else
F_93 ( V_2 , & V_312 ) ;
F_93 ( V_2 , & V_308 ) ;
F_93 ( V_2 , & V_313 ) ;
if ( ! F_19 ( V_2 ) ) {
F_93 ( V_2 , & V_314 ) ;
F_93 ( V_2 , & V_315 ) ;
}
break;
case V_30 :
F_93 ( V_2 , & V_302 ) ;
F_93 ( V_2 , & V_316 ) ;
F_93 ( V_2 , & V_311 ) ;
F_93 ( V_2 , & V_305 ) ;
if ( V_2 -> V_306 || F_19 ( V_2 ) )
F_93 ( V_2 , & V_307 ) ;
else
F_93 ( V_2 , & V_317 ) ;
F_93 ( V_2 , & V_308 ) ;
F_93 ( V_2 , & V_313 ) ;
if ( ! F_19 ( V_2 ) ) {
F_93 ( V_2 , & V_318 ) ;
F_93 ( V_2 , & V_315 ) ;
}
break;
case V_36 :
case V_37 :
case V_38 :
F_93 ( V_2 , & V_302 ) ;
F_93 ( V_2 , & V_319 ) ;
F_93 ( V_2 , & V_311 ) ;
F_93 ( V_2 , & V_305 ) ;
if ( V_2 -> V_306 )
F_93 ( V_2 , & V_307 ) ;
else
F_93 ( V_2 , & V_320 ) ;
F_93 ( V_2 , & V_308 ) ;
F_93 ( V_2 , & V_321 ) ;
F_93 ( V_2 , & V_322 ) ;
F_93 ( V_2 , & V_323 ) ;
break;
case V_32 :
F_93 ( V_2 , & V_302 ) ;
F_93 ( V_2 , & V_316 ) ;
F_93 ( V_2 , & V_324 ) ;
F_93 ( V_2 , & V_305 ) ;
if ( V_2 -> V_306 )
F_93 ( V_2 , & V_307 ) ;
else
F_93 ( V_2 , & V_325 ) ;
F_93 ( V_2 , & V_308 ) ;
F_93 ( V_2 , & V_313 ) ;
F_93 ( V_2 , & V_314 ) ;
F_93 ( V_2 , & V_326 ) ;
#if F_94 ( V_327 )
F_93 ( V_2 , & V_328 ) ;
#endif
break;
case V_34 :
F_93 ( V_2 , & V_302 ) ;
F_93 ( V_2 , & V_316 ) ;
F_93 ( V_2 , & V_324 ) ;
F_93 ( V_2 , & V_305 ) ;
if ( V_2 -> V_306 )
F_93 ( V_2 , & V_307 ) ;
else
F_93 ( V_2 , & V_325 ) ;
F_93 ( V_2 , & V_329 ) ;
F_93 ( V_2 , & V_313 ) ;
F_93 ( V_2 , & V_330 ) ;
F_93 ( V_2 , & V_323 ) ;
#if F_94 ( V_327 )
F_93 ( V_2 , & V_328 ) ;
#endif
break;
default:
return - V_170 ;
}
return 0 ;
}
