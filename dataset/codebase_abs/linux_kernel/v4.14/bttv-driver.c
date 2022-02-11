static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_9 ? V_9 -> V_10 . type : V_11 ) ;
}
static void F_4 ( struct V_12 * V_13 )
{
F_5 ( L_2 ) ;
}
static void F_6 ( struct V_8 * V_14 )
{
F_7 ( & V_14 -> V_15 , F_4 ) ;
F_8 ( & V_14 -> V_15 ) ;
}
static void F_9 ( struct V_8 * V_14 )
{
F_10 ( & V_14 -> V_15 ) ;
}
static
int F_11 ( struct V_8 * V_9 , struct V_16 * V_17 , int V_18 )
{
int V_19 ;
if ( V_17 -> V_20 & V_18 )
return 1 ;
V_19 = V_18 ;
if ( V_18 & ( V_21 | V_22 ) )
V_19 |= V_21 | V_22 ;
if ( V_9 -> V_20 & V_19 ) {
goto V_23;
}
if ( ( V_18 & V_24 )
&& 0 == ( V_9 -> V_20 & V_24 ) ) {
T_2 V_25 = V_9 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_25 ;
if ( V_9 -> V_29 > V_25 )
goto V_23;
V_9 -> V_30 = V_25 ;
} else if ( V_18 & V_31 ) {
T_2 V_32 = V_17 -> V_33 . V_32 ;
if ( V_32 > V_9 -> V_30 )
goto V_23;
V_9 -> V_29 = V_32 ;
}
V_17 -> V_20 |= V_18 ;
V_9 -> V_20 |= V_18 ;
return 1 ;
V_23:
return 0 ;
}
static
int F_12 ( struct V_16 * V_17 , int V_18 )
{
return ( V_17 -> V_20 & V_18 ) ;
}
static
int F_13 ( struct V_8 * V_9 , int V_18 )
{
return ( V_9 -> V_20 & V_18 ) ;
}
static void
F_14 ( struct V_8 * V_9 )
{
V_9 -> V_29 = 0 ;
}
static void
F_15 ( struct V_8 * V_9 )
{
const struct V_34 * V_35 ;
T_3 V_26 ;
V_35 = & V_36 [ V_9 -> V_35 ] ;
V_9 -> V_30 = V_35 -> V_37 . V_38 . V_25
+ V_35 -> V_37 . V_38 . V_39 ;
V_26 = F_16 ( V_40 ) | 0xc0 ;
F_17 ( V_26 , V_40 ) ;
F_17 ( 0xfe , V_41 ) ;
F_17 ( V_26 , V_42 ) ;
F_17 ( 0xfe , V_43 ) ;
}
static
void F_18 ( struct V_8 * V_9 , struct V_16 * V_17 , int V_44 )
{
if ( ( V_17 -> V_20 & V_44 ) != V_44 ) {
F_19 ( L_3 ) ;
}
V_17 -> V_20 &= ~ V_44 ;
V_9 -> V_20 &= ~ V_44 ;
V_44 = V_9 -> V_20 ;
if ( 0 == ( V_44 & V_24 ) )
F_15 ( V_9 ) ;
if ( 0 == ( V_44 & V_31 ) )
F_14 ( V_9 ) ;
}
static void F_20 ( struct V_8 * V_9 , unsigned int V_45 , unsigned int V_46 )
{
unsigned char V_47 , V_17 , V_48 ;
V_45 /= 4 ;
V_46 /= 4 ;
V_46 *= 12 ;
V_48 = V_46 / V_45 ;
V_46 = ( V_46 % V_45 ) * 256 ;
V_17 = V_46 / V_45 ;
V_46 = ( V_46 % V_45 ) * 256 ;
V_47 = V_46 / V_45 ;
F_17 ( V_47 , V_49 ) ;
F_17 ( V_17 , V_50 ) ;
F_17 ( V_48 | V_51 , V_52 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
int V_53 ;
if ( ! V_9 -> V_54 . V_55 )
return;
if ( V_9 -> V_54 . V_56 == V_9 -> V_54 . V_57 ) {
F_22 ( L_4 , V_9 -> V_10 . V_58 ) ;
return;
}
if ( V_9 -> V_54 . V_59 == V_9 -> V_54 . V_56 ) {
if ( V_9 -> V_54 . V_57 == 0 )
return;
if ( V_60 )
F_23 ( L_5 ,
V_9 -> V_10 . V_58 , V_9 -> V_54 . V_59 ) ;
F_17 ( 0x00 , V_61 ) ;
F_17 ( 0x00 , V_52 ) ;
V_9 -> V_54 . V_57 = 0 ;
return;
}
if ( V_60 )
F_23 ( L_6 ,
V_9 -> V_10 . V_58 ,
V_9 -> V_54 . V_59 , V_9 -> V_54 . V_56 ) ;
F_20 ( V_9 , V_9 -> V_54 . V_59 , V_9 -> V_54 . V_56 ) ;
for ( V_53 = 0 ; V_53 < 10 ; V_53 ++ ) {
F_24 ( 10 ) ;
if ( F_16 ( V_62 ) & V_63 ) {
F_17 ( 0 , V_62 ) ;
} else {
F_17 ( 0x08 , V_61 ) ;
V_9 -> V_54 . V_57 = V_9 -> V_54 . V_56 ;
if ( V_60 )
F_23 ( L_7 ) ;
return;
}
}
V_9 -> V_54 . V_57 = - 1 ;
if ( V_60 )
F_23 ( L_8 ) ;
return;
}
static void F_25 ( struct V_8 * V_9 )
{
int V_53 , V_64 ;
int V_65 = V_36 [ V_9 -> V_35 ] . V_66 ;
int V_67 = V_36 [ V_9 -> V_35 ] . V_68 ;
if ( V_9 -> V_69 == V_9 -> V_70 ) {
F_22 ( L_9 ,
V_9 -> V_10 . V_58 , V_65 ) ;
F_17 ( 0x00 , V_61 ) ;
F_17 ( 0x02 , V_61 ) ;
F_17 ( 0x00 , V_61 ) ;
V_64 = V_71 [ V_65 ] [ 0 ] ;
for( V_53 = 1 ; V_53 <= V_64 ; V_53 ++ )
F_17 ( V_71 [ V_65 ] [ V_53 ] , V_72 ) ;
V_9 -> V_54 . V_56 = 27000000 ;
F_21 ( V_9 ) ;
F_17 ( 0x11 , V_61 ) ;
F_17 ( 0x41 , V_73 ) ;
} else {
V_9 -> V_54 . V_56 = V_67 ;
F_21 ( V_9 ) ;
F_17 ( 0x0 , V_73 ) ;
}
}
static void F_26 ( struct V_8 * V_9 , int V_74 )
{
int V_75 ;
V_9 -> V_74 = V_74 ;
V_75 = ( V_74 >> 8 ) - 128 ;
F_17 ( V_75 & 0xff , V_76 ) ;
}
static void F_27 ( struct V_8 * V_9 , int V_77 )
{
int V_75 ;
V_9 -> V_77 = V_77 ;
V_75 = ( V_77 >> 8 ) - 128 ;
F_17 ( V_75 & 0xff , V_78 ) ;
}
static void F_28 ( struct V_8 * V_9 , int V_79 )
{
int V_75 , V_80 ;
V_9 -> V_81 = V_79 ;
V_75 = ( V_79 >> 7 ) ;
V_80 = ( V_75 >> 6 ) & 4 ;
F_17 ( V_75 & 0xff , V_82 ) ;
F_29 ( V_80 , ~ 4 , V_83 ) ;
F_29 ( V_80 , ~ 4 , V_84 ) ;
}
static void F_30 ( struct V_8 * V_9 , int V_85 )
{
int V_86 , V_87 , V_88 ;
V_9 -> V_89 = V_85 ;
V_86 = ( ( V_85 * V_9 -> V_90 ) / 50 ) >> 7 ;
V_87 = ( ( ( V_85 * ( 100 - V_9 -> V_90 ) / 50 ) >> 7 ) * 180L ) / 254 ;
V_88 = ( V_86 >> 7 ) & 2 ;
V_88 |= ( V_87 >> 8 ) & 1 ;
F_17 ( V_86 & 0xff , V_91 ) ;
F_17 ( V_87 & 0xff , V_92 ) ;
F_29 ( V_88 , ~ 3 , V_83 ) ;
F_29 ( V_88 , ~ 3 , V_84 ) ;
}
static int
F_31 ( struct V_8 * V_9 , unsigned int V_69 )
{
int V_93 , V_94 ;
if ( V_69 >= V_95 [ V_9 -> V_10 . type ] . V_96 )
return - V_97 ;
V_94 = V_95 [ V_9 -> V_10 . type ] . V_98 ;
if ( V_94 )
F_32 ( V_94 , V_94 ) ;
if ( V_69 == V_9 -> V_99 ) {
F_33 ( V_100 , V_83 ) ;
F_33 ( V_100 , V_84 ) ;
} else {
F_34 ( ~ V_100 , V_83 ) ;
F_34 ( ~ V_100 , V_84 ) ;
}
V_93 = F_35 ( V_9 , V_69 ) ;
F_29 ( V_93 << 5 , ~ ( 3 << 5 ) , V_101 ) ;
F_22 ( L_10 , V_9 -> V_10 . V_58 , V_69 , V_93 ) ;
if( V_95 [ V_9 -> V_10 . type ] . V_102 )
V_95 [ V_9 -> V_10 . type ] . V_102 ( V_9 , V_69 ) ;
return 0 ;
}
static void
F_36 ( struct V_8 * V_9 , int V_69 , int V_103 )
{
int V_104 , signal , V_105 ;
F_32 ( V_95 [ V_9 -> V_10 . type ] . V_106 ,
V_95 [ V_9 -> V_10 . type ] . V_106 ) ;
signal = F_16 ( V_62 ) & V_107 ;
V_105 = V_103 || ( V_9 -> V_108 && ( ! signal || ! V_9 -> V_109 )
&& ! V_9 -> V_110 ) ;
if ( V_105 )
V_104 = V_95 [ V_9 -> V_10 . type ] . V_111 ;
else
V_104 = V_95 [ V_9 -> V_10 . type ] . V_112 [ V_69 ] ;
switch ( V_9 -> V_10 . type ) {
case V_113 :
case V_114 :
V_104 = F_37 ( V_9 , V_104 ) ;
break;
default:
F_38 ( V_95 [ V_9 -> V_10 . type ] . V_106 , V_104 ) ;
}
if ( V_115 )
F_39 ( V_9 , V_116 [ V_105 ? 4 : V_69 ] ) ;
}
static int
F_40 ( struct V_8 * V_9 , int V_103 )
{
struct V_117 * V_118 ;
F_36 ( V_9 , V_9 -> V_119 , V_103 ) ;
if ( V_9 -> V_120 ) {
V_118 = F_41 ( V_9 -> V_120 -> V_121 , V_122 ) ;
if ( V_118 )
F_42 ( V_118 , V_103 ) ;
}
if ( V_9 -> V_123 ) {
V_118 = F_41 ( V_9 -> V_123 -> V_121 , V_122 ) ;
if ( V_118 )
F_42 ( V_118 , V_103 ) ;
}
if ( V_9 -> V_124 ) {
V_118 = F_41 ( V_9 -> V_124 -> V_121 , V_122 ) ;
if ( V_118 )
F_42 ( V_118 , V_103 ) ;
}
return 0 ;
}
static int
V_119 ( struct V_8 * V_9 , int V_69 )
{
F_36 ( V_9 , V_69 , V_9 -> V_103 ) ;
if ( V_9 -> V_120 ) {
T_4 V_125 ;
switch ( V_69 ) {
case V_126 :
if ( V_9 -> V_127 ) {
V_125 = V_128 ;
break;
}
V_125 = F_43 ( V_129 , V_130 ,
V_131 , V_131 ) ;
break;
case V_132 :
V_125 = F_43 ( V_133 , V_130 ,
V_131 , V_131 ) ;
break;
case V_134 :
V_125 = F_43 ( V_129 , V_130 ,
V_131 , V_131 ) ;
break;
case V_135 :
default:
if ( V_9 -> V_10 . type == V_114 )
V_125 = F_43 ( V_133 , V_136 , \
V_137 , V_137 ) ;
else
V_125 = V_128 ;
break;
}
F_44 ( V_9 -> V_120 , V_138 , V_139 ,
V_125 , V_140 , 0 ) ;
}
if ( V_9 -> V_123 ) {
F_44 ( V_9 -> V_123 , V_138 , V_139 ,
V_69 , 0 , 0 ) ;
}
return 0 ;
}
static void
F_45 ( struct V_141 * V_10 )
{
if ( 1 ) {
V_10 -> V_142 = 48 ;
V_10 -> V_143 = 32 ;
} else {
V_10 -> V_142 =
( F_46 (unsigned int, 48 , c->rect.width >> 4 ) + 3 ) & ~ 3 ;
V_10 -> V_143 =
F_46 (unsigned int, 32 , c->rect.height >> 4 ) ;
}
V_10 -> V_144 = V_10 -> V_28 . V_145 & ~ 3 ;
V_10 -> V_146 = V_10 -> V_28 . V_39 ;
}
static void
F_47 ( struct V_141 * V_10 , unsigned int V_147 )
{
V_10 -> V_28 = V_36 [ V_147 ] . V_37 . V_148 ;
F_45 ( V_10 ) ;
}
static int
F_48 ( struct V_8 * V_9 , unsigned int V_147 )
{
const struct V_34 * V_35 ;
T_5 V_149 ;
F_49 ( V_147 >= V_150 ) ;
F_49 ( V_9 -> V_35 >= V_150 ) ;
V_35 = & V_36 [ V_147 ] ;
if ( memcmp ( & V_36 [ V_9 -> V_35 ] . V_37 , & V_35 -> V_37 ,
sizeof ( V_35 -> V_37 ) ) ) {
F_47 ( & V_9 -> V_26 [ 0 ] , V_147 ) ;
V_9 -> V_26 [ 1 ] = V_9 -> V_26 [ 0 ] ;
if ( 0 == ( V_9 -> V_20 & V_24 ) ) {
V_9 -> V_30 = V_35 -> V_37 . V_38 . V_25
+ V_35 -> V_37 . V_38 . V_39 ;
}
}
V_9 -> V_35 = V_147 ;
F_17 ( V_35 -> V_151 , V_152 ) ;
F_17 ( V_35 -> V_153 , V_154 ) ;
F_29 ( V_35 -> V_155 , ~ ( V_156 | V_157 ) ,
V_101 ) ;
F_17 ( V_35 -> V_158 , V_159 ) ;
F_17 ( 1 , V_160 ) ;
F_25 ( V_9 ) ;
switch ( V_9 -> V_10 . type ) {
case V_113 :
case V_114 :
F_37 ( V_9 , F_50 () ) ;
break;
}
V_149 = V_35 -> V_161 ;
F_51 ( V_9 , V_162 , V_163 , V_149 ) ;
return 0 ;
}
static void
F_52 ( struct V_8 * V_9 , unsigned int V_69 , unsigned int V_147 )
{
unsigned long V_164 ;
V_9 -> V_69 = V_69 ;
if ( V_165 ) {
F_53 ( & V_9 -> V_166 , V_164 ) ;
if ( V_9 -> V_167 . V_168 ) {
V_9 -> V_169 = V_69 ;
} else {
F_31 ( V_9 , V_69 ) ;
}
F_54 ( & V_9 -> V_166 , V_164 ) ;
} else {
F_31 ( V_9 , V_69 ) ;
}
V_9 -> V_119 = ( V_9 -> V_170 != V_171 && V_69 == 0 ) ?
V_135 : V_132 ;
V_119 ( V_9 , V_9 -> V_119 ) ;
F_48 ( V_9 , V_147 ) ;
}
static void F_55 ( struct V_8 * V_9 )
{
F_17 ( 0xfffffUL , V_172 ) ;
if ( V_95 [ V_9 -> V_10 . type ] . V_173 ) {
F_17 ( V_174 ,
V_175 ) ;
} else {
F_17 ( ( V_9 -> V_176 ) |
( V_9 -> V_177 ? V_178 : 0 ) |
V_179 |
( V_180 ? V_181 : 0 ) |
V_182 | V_183 |
V_184 | V_185 |
V_174 ,
V_175 ) ;
}
}
static void F_56 ( struct V_8 * V_9 )
{
if ( V_95 [ V_9 -> V_10 . type ] . V_173 ) {
F_55 ( V_9 ) ;
return;
}
F_17 ( 0x00 , V_186 ) ;
F_17 ( V_187 , V_188 ) ;
F_17 ( V_189 | V_190 , V_101 ) ;
F_17 ( V_191 |
V_192 |
V_193 |
V_194 |
V_195 ,
V_196 ) ;
F_17 ( 0x20 , V_197 ) ;
F_17 ( 0x20 , V_198 ) ;
F_57 ( & V_9 -> V_121 ) ;
F_55 ( V_9 ) ;
}
static void F_58 ( struct V_8 * V_9 )
{
unsigned long V_164 ;
if ( V_60 )
F_23 ( L_11 , V_9 -> V_10 . V_58 ) ;
F_53 ( & V_9 -> V_166 , V_164 ) ;
V_9 -> V_199 = 0 ;
F_59 ( V_9 , 0 ) ;
F_54 ( & V_9 -> V_166 , V_164 ) ;
F_56 ( V_9 ) ;
V_9 -> V_54 . V_57 = - 1 ;
F_52 ( V_9 , V_9 -> V_69 , V_9 -> V_35 ) ;
}
static int F_60 ( struct V_117 * V_10 )
{
struct V_8 * V_9 = F_61 ( V_10 -> V_200 , struct V_8 , V_121 ) ;
int V_201 ;
switch ( V_10 -> V_149 ) {
case V_202 :
F_26 ( V_9 , V_10 -> V_201 ) ;
break;
case V_203 :
F_27 ( V_9 , V_10 -> V_201 ) ;
break;
case V_204 :
F_28 ( V_9 , V_10 -> V_201 ) ;
break;
case V_205 :
F_30 ( V_9 , V_10 -> V_201 ) ;
break;
case V_206 :
if ( V_10 -> V_201 ) {
F_33 ( V_207 , V_208 ) ;
F_33 ( V_207 , V_209 ) ;
} else {
F_34 ( ~ V_207 , V_208 ) ;
F_34 ( ~ V_207 , V_209 ) ;
}
break;
case V_122 :
F_40 ( V_9 , V_10 -> V_201 ) ;
V_9 -> V_103 = V_10 -> V_201 ;
break;
case V_210 :
V_9 -> V_211 ( V_9 , V_10 -> V_201 ) ;
break;
case V_212 :
V_201 = V_10 -> V_201 ? V_213 : 0 ;
F_17 ( V_201 , V_208 ) ;
F_17 ( V_201 , V_209 ) ;
break;
case V_214 :
V_9 -> V_215 = V_10 -> V_201 ;
break;
case V_216 :
if ( V_10 -> V_201 ) {
F_34 ( ~ V_217 , V_83 ) ;
F_34 ( ~ V_217 , V_84 ) ;
} else {
F_33 ( V_217 , V_83 ) ;
F_33 ( V_217 , V_84 ) ;
}
break;
case V_218 :
V_9 -> V_108 = V_10 -> V_201 ;
break;
case V_219 :
F_17 ( V_220 |
( V_10 -> V_201 ? V_221 : 0 ) ,
V_222 ) ;
break;
case V_223 :
V_9 -> V_224 = V_10 -> V_201 ;
break;
case V_225 :
F_17 ( V_10 -> V_201 , V_226 ) ;
break;
case V_227 :
F_17 ( V_10 -> V_201 , V_228 ) ;
break;
case V_229 :
V_9 -> V_90 = V_10 -> V_201 ;
F_30 ( V_9 , V_9 -> V_89 ) ;
break;
case V_230 :
F_29 ( ( V_10 -> V_201 << 7 ) , ~ V_231 , V_232 ) ;
break;
case V_233 :
F_29 ( ( V_10 -> V_201 << 5 ) , ~ V_234 , V_232 ) ;
break;
default:
return - V_97 ;
}
return 0 ;
}
void F_39 ( struct V_8 * V_9 , char * V_235 )
{
unsigned int V_236 , V_237 ;
V_236 = F_16 ( V_238 ) ;
V_237 = F_16 ( V_239 ) ;
F_62 ( L_12 ,
V_9 -> V_10 . V_58 , V_236 , V_237 & V_236 , V_237 & ~ V_236 , V_235 ) ;
}
static void F_63 ( struct V_8 * V_9 )
{
int V_240 = 0 ;
if ( V_9 -> V_109 )
V_240 ++ ;
if ( V_240 ) {
F_33 ( V_241 , V_175 ) ;
} else {
F_34 ( ~ V_241 , V_175 ) ;
V_9 -> V_242 = 0 ;
}
}
static const struct V_243 *
F_64 ( int V_244 )
{
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_245 ; V_53 ++ ) {
if ( - 1 == V_246 [ V_53 ] . V_244 )
continue;
if ( V_246 [ V_53 ] . V_244 == V_244 )
return V_246 + V_53 ;
}
return NULL ;
}
static int
F_65 ( struct V_8 * V_9 , struct V_16 * V_17 ,
struct V_247 * V_248 )
{
struct V_247 * V_249 ;
unsigned long V_164 ;
F_22 ( L_13 , V_248 ) ;
if ( V_248 )
V_248 -> V_250 . V_251 = V_252 ;
F_53 ( & V_9 -> V_166 , V_164 ) ;
V_249 = V_9 -> V_253 ;
V_9 -> V_253 = V_248 ;
V_9 -> V_254 |= 1 ;
F_59 ( V_9 , 0x03 ) ;
F_54 ( & V_9 -> V_166 , V_164 ) ;
if ( NULL != V_249 ) {
F_22 ( L_14 ,
V_249 , V_249 -> V_250 . V_251 ) ;
F_66 ( & V_17 -> V_255 , V_9 , V_249 ) ;
F_67 ( V_249 ) ;
}
if ( NULL == V_248 )
F_18 ( V_9 , V_17 , V_256 ) ;
F_22 ( L_15 ) ;
return 0 ;
}
static int F_68 ( struct V_257 * V_258 , struct V_8 * V_9 ,
struct V_247 * V_5 ,
const struct V_243 * V_259 ,
unsigned int V_145 , unsigned int V_39 ,
enum V_260 V_261 )
{
struct V_16 * V_17 = V_258 -> V_262 ;
int V_263 = 0 ;
struct V_141 V_10 ;
int V_147 ;
int V_264 ;
if ( NULL == V_259 )
return - V_97 ;
if ( V_259 -> V_265 == V_266 ) {
V_145 = V_267 ;
V_39 = V_268 * 2 ;
if ( V_145 * V_39 > V_5 -> V_250 . V_269 )
return - V_97 ;
V_5 -> V_250 . V_270 = V_5 -> V_250 . V_269 ;
V_147 = V_9 -> V_35 ;
if ( V_9 -> V_29 > V_36 [ V_147 ] . V_37 . V_148 . V_25 ) {
return - V_97 ;
}
V_10 . V_28 = V_36 [ V_147 ] . V_37 . V_148 ;
} else {
V_147 = V_9 -> V_35 ;
V_10 = V_9 -> V_26 [ ! ! V_17 -> V_27 ] ;
if ( V_145 < V_10 . V_142 ||
V_145 > V_10 . V_144 ||
V_39 < V_10 . V_143 )
return - V_97 ;
switch ( V_261 ) {
case V_271 :
case V_272 :
case V_273 :
if ( V_39 * 2 > V_10 . V_146 )
return - V_97 ;
break;
default:
if ( V_39 > V_10 . V_146 )
return - V_97 ;
break;
}
V_5 -> V_250 . V_270 = ( V_145 * V_39 * V_259 -> V_274 ) >> 3 ;
if ( 0 != V_5 -> V_250 . V_275 && V_5 -> V_250 . V_269 < V_5 -> V_250 . V_270 )
return - V_97 ;
}
if ( V_5 -> V_250 . V_145 != V_145 || V_5 -> V_250 . V_39 != V_39 ||
V_5 -> V_250 . V_261 != V_261 ||
V_5 -> V_35 != V_147 || V_5 -> V_259 != V_259 ||
V_5 -> V_26 . V_25 != V_10 . V_28 . V_25 ||
V_5 -> V_26 . V_276 != V_10 . V_28 . V_276 ||
V_5 -> V_26 . V_145 != V_10 . V_28 . V_145 ||
V_5 -> V_26 . V_39 != V_10 . V_28 . V_39 ) {
V_5 -> V_250 . V_145 = V_145 ;
V_5 -> V_250 . V_39 = V_39 ;
V_5 -> V_250 . V_261 = V_261 ;
V_5 -> V_35 = V_147 ;
V_5 -> V_259 = V_259 ;
V_5 -> V_26 = V_10 . V_28 ;
V_263 = 1 ;
}
if ( V_277 == V_5 -> V_250 . V_251 ) {
V_263 = 1 ;
if ( 0 != ( V_264 = F_69 ( V_258 , & V_5 -> V_250 , & V_9 -> V_278 ) ) )
goto V_23;
}
if ( V_263 )
if ( 0 != ( V_264 = F_70 ( V_9 , V_5 ) ) )
goto V_23;
V_5 -> V_250 . V_251 = V_279 ;
return 0 ;
V_23:
F_66 ( V_258 , V_9 , V_5 ) ;
return V_264 ;
}
static int
F_71 ( struct V_257 * V_258 , unsigned int * V_280 , unsigned int * V_270 )
{
struct V_16 * V_17 = V_258 -> V_262 ;
* V_270 = V_17 -> V_259 -> V_274 * V_17 -> V_145 * V_17 -> V_39 >> 3 ;
if ( 0 == * V_280 )
* V_280 = V_281 ;
if ( * V_270 * * V_280 > V_281 * V_282 )
* V_280 = ( V_281 * V_282 ) / * V_270 ;
return 0 ;
}
static int
F_72 ( struct V_257 * V_258 , struct V_283 * V_250 ,
enum V_260 V_261 )
{
struct V_247 * V_5 = F_61 ( V_250 , struct V_247 , V_250 ) ;
struct V_16 * V_17 = V_258 -> V_262 ;
return F_68 ( V_258 , V_17 -> V_9 , V_5 , V_17 -> V_259 ,
V_17 -> V_145 , V_17 -> V_39 , V_261 ) ;
}
static void
F_73 ( struct V_257 * V_258 , struct V_283 * V_250 )
{
struct V_247 * V_5 = F_61 ( V_250 , struct V_247 , V_250 ) ;
struct V_16 * V_17 = V_258 -> V_262 ;
struct V_8 * V_9 = V_17 -> V_9 ;
V_5 -> V_250 . V_251 = V_284 ;
F_74 ( & V_5 -> V_250 . V_285 , & V_9 -> V_286 ) ;
if ( ! V_9 -> V_167 . V_168 ) {
V_9 -> V_254 |= 1 ;
F_59 ( V_9 , 0x03 ) ;
}
}
static void F_75 ( struct V_257 * V_258 , struct V_283 * V_250 )
{
struct V_247 * V_5 = F_61 ( V_250 , struct V_247 , V_250 ) ;
struct V_16 * V_17 = V_258 -> V_262 ;
F_66 ( V_258 , V_17 -> V_9 , V_5 ) ;
}
static void F_76 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_110 ) {
V_9 -> V_110 = 1 ;
F_51 ( V_9 , V_287 , V_288 ) ;
V_9 -> V_119 = V_126 ;
V_119 ( V_9 , V_9 -> V_119 ) ;
}
}
static int F_77 ( struct V_289 * V_289 , void * V_290 , T_5 V_149 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_150 ; V_53 ++ )
if ( V_149 & V_36 [ V_53 ] . V_161 )
break;
if ( V_53 == V_150 )
return - V_97 ;
V_9 -> V_291 = V_149 ;
F_48 ( V_9 , V_53 ) ;
return 0 ;
}
static int F_78 ( struct V_289 * V_289 , void * V_290 , T_5 * V_149 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
* V_149 = V_9 -> V_291 ;
return 0 ;
}
static int F_79 ( struct V_289 * V_289 , void * V_292 , T_5 * V_149 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( F_16 ( V_62 ) & V_293 )
* V_149 &= V_294 ;
else
* V_149 &= V_295 ;
return 0 ;
}
static int F_80 ( struct V_289 * V_289 , void * V_290 ,
struct V_296 * V_53 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_53 -> V_297 >= V_95 [ V_9 -> V_10 . type ] . V_96 )
return - V_97 ;
V_53 -> type = V_298 ;
V_53 -> V_299 = 0 ;
if ( V_9 -> V_170 != V_171 && V_53 -> V_297 == 0 ) {
sprintf ( V_53 -> V_300 , L_16 ) ;
V_53 -> type = V_301 ;
V_53 -> V_287 = 0 ;
} else if ( V_53 -> V_297 == V_9 -> V_99 ) {
sprintf ( V_53 -> V_300 , L_17 ) ;
} else {
sprintf ( V_53 -> V_300 , L_18 , V_53 -> V_297 ) ;
}
if ( V_53 -> V_297 == V_9 -> V_69 ) {
T_6 V_302 = F_16 ( V_62 ) ;
if ( 0 == ( V_302 & V_303 ) )
V_53 -> V_304 |= V_305 ;
if ( 0 == ( V_302 & V_107 ) )
V_53 -> V_304 |= V_306 ;
}
V_53 -> V_291 = V_307 ;
return 0 ;
}
static int F_81 ( struct V_289 * V_289 , void * V_290 , unsigned int * V_53 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
* V_53 = V_9 -> V_69 ;
return 0 ;
}
static int F_82 ( struct V_289 * V_289 , void * V_290 , unsigned int V_53 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_53 >= V_95 [ V_9 -> V_10 . type ] . V_96 )
return - V_97 ;
F_52 ( V_9 , V_53 , V_9 -> V_35 ) ;
return 0 ;
}
static int F_83 ( struct V_289 * V_289 , void * V_290 ,
const struct V_308 * V_309 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_309 -> V_297 )
return - V_97 ;
F_51 ( V_9 , V_287 , V_310 , V_309 ) ;
if ( V_9 -> V_311 ) {
struct V_308 V_312 = * V_309 ;
V_9 -> V_311 ( V_9 , & V_312 , 1 ) ;
}
return 0 ;
}
static int F_84 ( struct V_289 * V_289 , void * V_290 ,
struct V_313 * V_292 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_292 -> V_287 )
return - V_97 ;
if ( V_292 -> type == V_314 )
F_76 ( V_9 ) ;
V_292 -> V_315 = V_292 -> type == V_314 ?
V_9 -> V_316 : V_9 -> V_317 ;
return 0 ;
}
static void F_85 ( struct V_8 * V_9 , const struct V_313 * V_292 )
{
struct V_313 V_318 = * V_292 ;
F_51 ( V_9 , V_287 , V_319 , V_292 ) ;
F_51 ( V_9 , V_287 , V_320 , & V_318 ) ;
if ( V_318 . type == V_314 ) {
F_76 ( V_9 ) ;
V_9 -> V_316 = V_318 . V_315 ;
if ( V_9 -> V_321 ) {
V_9 -> V_322 . V_323 = V_9 -> V_316 ;
F_86 ( & V_9 -> V_322 ) ;
}
} else {
V_9 -> V_317 = V_318 . V_315 ;
}
}
static int F_87 ( struct V_289 * V_289 , void * V_290 ,
const struct V_313 * V_292 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_292 -> V_287 )
return - V_97 ;
F_85 ( V_9 , V_292 ) ;
return 0 ;
}
static int F_88 ( struct V_289 * V_289 , void * V_292 )
{
struct V_6 * V_324 = F_89 ( V_289 ) ;
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
F_90 ( V_324 -> V_121 , V_9 -> V_10 . V_325 . V_300 ) ;
F_51 ( V_9 , V_326 , V_327 ) ;
return 0 ;
}
static int F_91 ( struct V_289 * V_289 , void * V_292 ,
struct V_328 * V_329 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
V_329 -> V_329 &= 0xfff ;
V_329 -> V_201 = F_16 ( V_329 -> V_329 ) ;
V_329 -> V_270 = 1 ;
return 0 ;
}
static int F_92 ( struct V_289 * V_289 , void * V_292 ,
const struct V_328 * V_329 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
F_17 ( V_329 -> V_201 , V_329 -> V_329 & 0xfff ) ;
return 0 ;
}
static void
F_93 ( struct V_141 * V_10 ,
const struct V_330 * V_331 ,
T_2 V_145 ,
T_2 V_39 ,
enum V_260 V_261 )
{
T_2 V_332 = V_39 << ! F_94 ( V_261 ) ;
T_2 V_333 ;
T_2 V_334 ;
if ( V_145 < V_10 -> V_142 ) {
V_10 -> V_28 . V_145 = V_145 * 16 ;
} else if ( V_145 > V_10 -> V_144 ) {
V_10 -> V_28 . V_145 = V_145 ;
V_333 = V_331 -> V_276 + V_331 -> V_145 - V_145 ;
V_333 = F_95 ( V_333 , ( T_2 ) V_335 ) ;
if ( V_10 -> V_28 . V_276 > V_333 )
V_10 -> V_28 . V_276 = V_333 ;
}
if ( V_39 < V_10 -> V_143 ) {
V_10 -> V_28 . V_39 = V_39 * 16 ;
} else if ( V_332 > V_10 -> V_146 ) {
V_10 -> V_28 . V_39 = ( V_332 + 1 ) & ~ 1 ;
V_334 = V_331 -> V_25 + V_331 -> V_39 - V_10 -> V_28 . V_39 ;
if ( V_10 -> V_28 . V_25 > V_334 )
V_10 -> V_28 . V_25 = V_334 ;
}
F_45 ( V_10 ) ;
}
static int
F_96 ( struct V_16 * V_17 ,
T_2 * V_145 ,
T_2 * V_39 ,
enum V_260 V_261 ,
unsigned int V_336 ,
unsigned int V_337 ,
int V_338 ,
int V_339 )
{
struct V_8 * V_9 = V_17 -> V_9 ;
const struct V_330 * V_331 ;
struct V_141 * V_10 ;
T_2 V_340 ;
T_2 V_341 ;
T_2 V_342 ;
T_2 V_343 ;
int V_264 ;
F_49 ( ( int ) V_336 >= 0 ||
V_337 >= ( unsigned int ) - V_336 ) ;
V_331 = & V_36 [ V_9 -> V_35 ] . V_37 . V_38 ;
V_10 = & V_9 -> V_26 [ ! ! V_17 -> V_27 ] ;
if ( V_17 -> V_27
&& V_338
&& V_339
&& ! F_13 ( V_9 , V_24 ) ) {
V_340 = 48 ;
V_341 = 32 ;
V_342 = F_97 (unsigned int, b->width, MAX_HACTIVE) ;
V_343 = V_331 -> V_39 ;
if ( V_9 -> V_29 > V_331 -> V_25 ) {
V_343 -= V_9 -> V_29 - V_331 -> V_25 ;
V_264 = - V_344 ;
if ( V_341 > V_343 )
goto V_23;
}
} else {
V_264 = - V_344 ;
if ( V_9 -> V_29 > V_10 -> V_28 . V_25 )
goto V_23;
V_340 = V_10 -> V_142 ;
V_341 = V_10 -> V_143 ;
V_342 = V_10 -> V_144 ;
V_343 = V_10 -> V_146 ;
V_339 = 0 ;
}
V_340 = ( V_340 - V_336 - 1 ) & V_336 ;
V_342 = V_342 & V_336 ;
V_341 = V_341 ;
V_343 >>= ! F_94 ( V_261 ) ;
if ( V_338 ) {
* V_145 = F_98 ( * V_145 , V_340 , V_342 ) ;
* V_39 = F_98 ( * V_39 , V_341 , V_343 ) ;
* V_145 = ( * V_145 + V_337 ) & V_336 ;
if ( V_339 ) {
F_93 ( V_10 , V_331 , * V_145 , * V_39 , V_261 ) ;
if ( V_9 -> V_29 > V_10 -> V_28 . V_25 ) {
V_10 -> V_28 . V_25 = V_9 -> V_29 ;
}
}
} else {
V_264 = - V_97 ;
if ( * V_145 < V_340 ||
* V_39 < V_341 ||
* V_145 > V_342 ||
* V_39 > V_343 ||
0 != ( * V_145 & ~ V_336 ) )
goto V_23;
}
V_264 = 0 ;
V_23:
return V_264 ;
}
static int
F_99 ( struct V_16 * V_17 , struct V_345 * V_346 ,
int V_338 , int V_339 )
{
enum V_260 V_261 ;
unsigned int V_336 ;
int V_264 ;
if ( V_346 -> V_347 . V_145 < 48 )
V_346 -> V_347 . V_145 = 48 ;
if ( V_346 -> V_347 . V_39 < 32 )
V_346 -> V_347 . V_39 = 32 ;
if ( V_346 -> V_348 > 2048 )
V_346 -> V_348 = 2048 ;
V_346 -> V_349 = 0 ;
V_346 -> V_350 = 0 ;
V_261 = V_346 -> V_261 ;
switch ( V_261 ) {
case V_271 :
case V_272 :
case V_351 :
break;
default:
V_261 = V_352 ;
break;
}
if ( V_352 == V_261 ) {
T_2 V_353 ;
V_353 = V_17 -> V_9 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_39 >> 1 ;
V_261 = ( V_346 -> V_347 . V_39 > V_353 )
? V_351
: V_271 ;
}
V_346 -> V_261 = V_261 ;
if ( NULL == V_17 -> V_354 )
return - V_97 ;
V_336 = ~ 0 ;
switch ( V_17 -> V_354 -> V_274 ) {
case 8 :
case 24 :
V_336 = ~ 3 ;
break;
case 16 :
V_336 = ~ 1 ;
break;
case 32 :
break;
default:
F_100 () ;
}
V_346 -> V_347 . V_145 -= V_346 -> V_347 . V_276 & ~ V_336 ;
V_346 -> V_347 . V_276 = ( V_346 -> V_347 . V_276 - V_336 - 1 ) & V_336 ;
V_264 = F_96 ( V_17 , & V_346 -> V_347 . V_145 , & V_346 -> V_347 . V_39 ,
V_261 , V_336 ,
0 ,
V_338 , V_339 ) ;
if ( 0 != V_264 )
return V_264 ;
return 0 ;
}
static int F_101 ( struct V_16 * V_17 , struct V_8 * V_9 ,
struct V_345 * V_346 , int V_355 )
{
struct V_356 * V_357 = NULL ;
int V_358 , V_270 , V_359 = 0 ;
if ( NULL == V_17 -> V_354 )
return - V_97 ;
if ( ! ( V_17 -> V_354 -> V_164 & V_360 ) )
return - V_97 ;
V_359 = F_99 ( V_17 , V_346 ,
V_355 ,
V_355 ) ;
if ( 0 != V_359 )
return V_359 ;
V_358 = V_346 -> V_348 ;
V_270 = sizeof( * V_357 ) * ( V_358 + 4 ) ;
V_357 = F_102 ( V_270 , V_361 ) ;
if ( NULL == V_357 )
return - V_362 ;
if ( V_358 > 0 ) {
if ( F_103 ( V_357 , V_346 -> V_357 , sizeof( struct V_356 ) * V_358 ) ) {
F_67 ( V_357 ) ;
return - V_363 ;
}
}
if ( NULL != V_9 -> V_278 . V_364 )
V_358 = F_104 ( V_9 -> V_278 . V_259 . V_145 , V_9 -> V_278 . V_259 . V_39 ,
& V_346 -> V_347 , V_357 , V_358 ) ;
F_105 ( V_357 , V_358 ) ;
switch ( V_17 -> V_354 -> V_274 ) {
case 8 :
case 24 :
F_106 ( & V_346 -> V_347 , V_357 , V_358 , 3 ) ;
break;
case 16 :
F_106 ( & V_346 -> V_347 , V_357 , V_358 , 1 ) ;
break;
case 32 :
break;
default:
F_100 () ;
}
F_67 ( V_17 -> V_365 . V_357 ) ;
V_17 -> V_365 . V_357 = V_357 ;
V_17 -> V_365 . V_366 = V_358 ;
V_17 -> V_365 . V_347 = V_346 -> V_347 ;
V_17 -> V_365 . V_261 = V_346 -> V_261 ;
V_17 -> V_365 . V_367 = 1 ;
V_9 -> V_368 . V_365 . V_347 . V_145 = V_346 -> V_347 . V_145 ;
V_9 -> V_368 . V_365 . V_347 . V_39 = V_346 -> V_347 . V_39 ;
V_9 -> V_368 . V_365 . V_261 = V_346 -> V_261 ;
V_359 = 0 ;
if ( F_12 ( V_17 , V_256 ) ) {
struct V_247 * V_248 ;
V_248 = F_107 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_9 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_108 ( V_9 , & V_17 -> V_365 , V_17 -> V_354 , V_248 ) ;
V_359 = F_65 ( V_9 , V_17 , V_248 ) ;
}
return V_359 ;
}
static struct V_257 * F_109 ( struct V_16 * V_17 )
{
struct V_257 * V_258 = NULL ;
switch ( V_17 -> type ) {
case V_369 :
V_258 = & V_17 -> V_255 ;
break;
case V_370 :
V_258 = & V_17 -> V_371 ;
break;
default:
F_100 () ;
}
return V_258 ;
}
static int F_110 ( struct V_16 * V_17 )
{
int V_372 = 0 ;
switch ( V_17 -> type ) {
case V_369 :
V_372 = V_22 ;
break;
case V_370 :
V_372 = V_373 ;
break;
default:
F_100 () ;
}
return V_372 ;
}
static int F_111 ( struct V_16 * V_17 , enum V_374 type )
{
struct V_257 * V_258 = F_109 ( V_17 ) ;
int V_372 = F_110 ( V_17 ) ;
if ( F_12 ( V_17 , V_372 ) )
return - V_344 ;
if ( F_112 ( V_258 ) )
return - V_344 ;
V_17 -> type = type ;
return 0 ;
}
static void
F_113 ( struct V_375 * V_292 ,
const struct V_243 * V_259 ,
unsigned int V_145 ,
unsigned int V_39 )
{
V_292 -> V_145 = V_145 ;
V_292 -> V_39 = V_39 ;
if ( V_259 -> V_164 & V_376 ) {
V_292 -> V_377 = V_145 ;
V_292 -> V_378 = ( V_145 * V_39 * V_259 -> V_274 ) >> 3 ;
} else {
V_292 -> V_377 = ( V_145 * V_259 -> V_274 ) >> 3 ;
V_292 -> V_378 = V_39 * V_292 -> V_377 ;
}
}
static int F_114 ( struct V_289 * V_289 , void * V_290 ,
struct V_379 * V_292 )
{
struct V_16 * V_17 = V_290 ;
F_113 ( & V_292 -> V_259 . V_380 , V_17 -> V_259 ,
V_17 -> V_145 , V_17 -> V_39 ) ;
V_292 -> V_259 . V_380 . V_261 = V_17 -> V_255 . V_261 ;
V_292 -> V_259 . V_380 . V_381 = V_17 -> V_259 -> V_244 ;
V_292 -> V_259 . V_380 . V_382 = V_383 ;
return 0 ;
}
static int F_115 ( struct V_289 * V_289 , void * V_290 ,
struct V_379 * V_292 )
{
struct V_16 * V_17 = V_290 ;
V_292 -> V_259 . V_346 . V_347 = V_17 -> V_365 . V_347 ;
V_292 -> V_259 . V_346 . V_261 = V_17 -> V_365 . V_261 ;
return 0 ;
}
static void F_116 ( const struct V_243 * V_259 ,
unsigned int * V_336 ,
unsigned int * V_337 )
{
if ( V_259 -> V_164 & V_376 ) {
* V_336 = ~ 15 ;
* V_337 = 8 ;
} else {
* V_336 = ~ 3 ;
* V_337 = 2 ;
}
}
static int F_117 ( struct V_289 * V_289 , void * V_290 ,
struct V_379 * V_292 )
{
const struct V_243 * V_259 ;
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
enum V_260 V_261 ;
T_2 V_145 , V_39 ;
T_2 V_353 ;
unsigned int V_336 , V_337 ;
int V_264 ;
V_259 = F_64 ( V_292 -> V_259 . V_380 . V_381 ) ;
if ( NULL == V_259 )
return - V_97 ;
V_261 = V_292 -> V_259 . V_380 . V_261 ;
switch ( V_261 ) {
case V_271 :
case V_272 :
case V_273 :
case V_351 :
break;
case V_384 :
case V_385 :
if ( ! ( V_259 -> V_164 & V_376 ) ) {
V_261 = V_385 ;
break;
}
default:
V_353 = V_9 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_39 >> 1 ;
V_261 = ( V_292 -> V_259 . V_380 . V_39 > V_353 )
? V_351
: V_272 ;
break;
}
V_145 = V_292 -> V_259 . V_380 . V_145 ;
V_39 = V_292 -> V_259 . V_380 . V_39 ;
F_116 ( V_259 , & V_336 , & V_337 ) ;
V_264 = F_96 ( V_17 , & V_145 , & V_39 , V_261 ,
V_336 , V_337 ,
1 ,
0 ) ;
if ( 0 != V_264 )
return V_264 ;
V_292 -> V_259 . V_380 . V_261 = V_261 ;
F_113 ( & V_292 -> V_259 . V_380 , V_259 , V_145 , V_39 ) ;
V_292 -> V_259 . V_380 . V_382 = V_383 ;
return 0 ;
}
static int F_118 ( struct V_289 * V_289 , void * V_290 ,
struct V_379 * V_292 )
{
struct V_16 * V_17 = V_290 ;
F_99 ( V_17 , & V_292 -> V_259 . V_346 ,
1 ,
0 ) ;
return 0 ;
}
static int F_119 ( struct V_289 * V_289 , void * V_290 ,
struct V_379 * V_292 )
{
int V_359 ;
const struct V_243 * V_259 ;
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
T_2 V_145 , V_39 ;
unsigned int V_336 , V_337 ;
enum V_260 V_261 ;
V_359 = F_111 ( V_17 , V_292 -> type ) ;
if ( 0 != V_359 )
return V_359 ;
V_359 = F_117 ( V_289 , V_290 , V_292 ) ;
if ( 0 != V_359 )
return V_359 ;
V_145 = V_292 -> V_259 . V_380 . V_145 ;
V_39 = V_292 -> V_259 . V_380 . V_39 ;
V_261 = V_292 -> V_259 . V_380 . V_261 ;
V_259 = F_64 ( V_292 -> V_259 . V_380 . V_381 ) ;
F_116 ( V_259 , & V_336 , & V_337 ) ;
V_359 = F_96 ( V_17 , & V_145 , & V_39 , V_292 -> V_259 . V_380 . V_261 ,
V_336 , V_337 ,
1 ,
1 ) ;
if ( 0 != V_359 )
return V_359 ;
V_292 -> V_259 . V_380 . V_261 = V_261 ;
V_17 -> V_259 = V_259 ;
V_17 -> V_255 . V_261 = V_292 -> V_259 . V_380 . V_261 ;
V_17 -> V_255 . V_386 = V_387 ;
V_17 -> V_145 = V_292 -> V_259 . V_380 . V_145 ;
V_17 -> V_39 = V_292 -> V_259 . V_380 . V_39 ;
V_9 -> V_368 . V_259 = V_259 ;
V_9 -> V_368 . V_145 = V_292 -> V_259 . V_380 . V_145 ;
V_9 -> V_368 . V_39 = V_292 -> V_259 . V_380 . V_39 ;
return 0 ;
}
static int F_120 ( struct V_289 * V_289 , void * V_290 ,
struct V_379 * V_292 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_388 > 0 ) {
F_19 ( L_19 ) ;
return - V_97 ;
}
return F_101 ( V_17 , V_9 , & V_292 -> V_259 . V_346 , 1 ) ;
}
static int F_121 ( struct V_289 * V_289 , void * V_290 ,
struct V_389 * V_255 )
{
struct V_6 * V_324 = F_89 ( V_289 ) ;
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( 0 == V_390 )
return - V_97 ;
F_122 ( V_255 -> V_391 , L_20 , sizeof( V_255 -> V_391 ) ) ;
F_122 ( V_255 -> V_392 , V_9 -> V_393 . V_300 , sizeof( V_255 -> V_392 ) ) ;
snprintf ( V_255 -> V_394 , sizeof( V_255 -> V_394 ) ,
L_21 , F_123 ( V_9 -> V_10 . V_395 ) ) ;
V_255 -> V_396 =
V_397 |
V_398 |
V_399 |
V_400 ;
if ( V_388 <= 0 )
V_255 -> V_396 |= V_401 ;
if ( F_124 ( & V_9 -> V_402 ) )
V_255 -> V_396 |= V_403 ;
if ( F_124 ( & V_9 -> V_404 ) )
V_255 -> V_396 |= V_405 ;
if ( V_9 -> V_406 )
V_255 -> V_396 |= V_407 ;
if ( V_9 -> V_170 != V_171 )
V_255 -> V_396 |= V_408 ;
if ( V_324 -> V_409 == V_410 )
V_255 -> V_411 = V_255 -> V_396 &
( V_397 |
V_398 |
V_399 |
V_401 |
V_408 ) ;
else if ( V_324 -> V_409 == V_412 )
V_255 -> V_411 = V_255 -> V_396 &
( V_403 |
V_398 |
V_399 |
V_408 ) ;
else {
V_255 -> V_411 = V_405 | V_408 ;
if ( V_9 -> V_406 )
V_255 -> V_411 |= V_398 |
V_407 ;
if ( V_9 -> V_321 )
V_255 -> V_411 |= V_413 ;
}
return 0 ;
}
static int F_125 ( struct V_414 * V_292 )
{
int V_297 = - 1 , V_53 ;
for ( V_53 = 0 ; V_53 < V_245 ; V_53 ++ ) {
if ( V_246 [ V_53 ] . V_244 != - 1 )
V_297 ++ ;
if ( ( unsigned int ) V_297 == V_292 -> V_297 )
break;
}
if ( V_245 == V_53 )
return - V_97 ;
V_292 -> V_381 = V_246 [ V_53 ] . V_244 ;
F_122 ( V_292 -> V_415 , V_246 [ V_53 ] . V_300 , sizeof( V_292 -> V_415 ) ) ;
return V_53 ;
}
static int F_126 ( struct V_289 * V_289 , void * V_290 ,
struct V_414 * V_292 )
{
int V_264 = F_125 ( V_292 ) ;
if ( V_264 < 0 )
return V_264 ;
return 0 ;
}
static int F_127 ( struct V_289 * V_289 , void * V_290 ,
struct V_414 * V_292 )
{
int V_264 ;
if ( V_388 > 0 ) {
F_19 ( L_19 ) ;
return - V_97 ;
}
V_264 = F_125 ( V_292 ) ;
if ( V_264 < 0 )
return V_264 ;
if ( ! ( V_246 [ V_264 ] . V_164 & V_360 ) )
return - V_97 ;
return 0 ;
}
static int F_128 ( struct V_289 * V_289 , void * V_292 ,
struct V_416 * V_417 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
* V_417 = V_9 -> V_278 ;
V_417 -> V_418 = V_419 ;
V_417 -> V_164 = V_420 ;
if ( V_17 -> V_354 )
V_417 -> V_259 . V_381 = V_17 -> V_354 -> V_244 ;
return 0 ;
}
static int F_129 ( struct V_289 * V_289 , void * V_292 , unsigned int V_421 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
struct V_247 * V_248 ;
int V_359 = 0 ;
if ( V_421 ) {
if ( F_130 ( ! V_9 -> V_278 . V_364 ) ) {
return - V_97 ;
}
if ( F_130 ( ! V_17 -> V_365 . V_367 ) ) {
F_22 ( L_22 , V_9 -> V_10 . V_58 ) ;
V_359 = - V_97 ;
}
if ( V_359 )
return V_359 ;
}
if ( ! F_11 ( V_9 , V_17 , V_256 ) )
return - V_344 ;
if ( V_421 ) {
V_17 -> V_365 . V_35 = V_9 -> V_35 ;
V_248 = F_107 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_9 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_108 ( V_9 , & V_17 -> V_365 , V_17 -> V_354 , V_248 ) ;
} else {
V_248 = NULL ;
}
V_359 = F_65 ( V_9 , V_17 , V_248 ) ;
return V_359 ;
}
static int F_131 ( struct V_289 * V_289 , void * V_292 ,
const struct V_416 * V_417 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
const struct V_243 * V_259 ;
int V_359 ;
if ( ! F_132 ( V_422 ) &&
! F_132 ( V_423 ) )
return - V_424 ;
V_259 = F_64 ( V_417 -> V_259 . V_381 ) ;
if ( NULL == V_259 )
return - V_97 ;
if ( 0 == ( V_259 -> V_164 & V_360 ) )
return - V_97 ;
V_359 = - V_97 ;
if ( V_417 -> V_164 & V_425 ) {
T_2 V_145 = V_417 -> V_259 . V_145 ;
T_2 V_39 = V_417 -> V_259 . V_39 ;
V_359 = F_96 ( V_17 , & V_145 , & V_39 ,
V_351 ,
~ 3 ,
2 ,
0 ,
0 ) ;
if ( 0 != V_359 )
return V_359 ;
}
V_9 -> V_278 . V_364 = V_417 -> V_364 ;
V_9 -> V_278 . V_259 . V_145 = V_417 -> V_259 . V_145 ;
V_9 -> V_278 . V_259 . V_39 = V_417 -> V_259 . V_39 ;
if ( 0 != V_417 -> V_259 . V_377 )
V_9 -> V_278 . V_259 . V_377 = V_417 -> V_259 . V_377 ;
else
V_9 -> V_278 . V_259 . V_377 = V_9 -> V_278 . V_259 . V_145 * V_259 -> V_274 / 8 ;
V_359 = 0 ;
V_17 -> V_354 = V_259 ;
V_9 -> V_368 . V_354 = V_259 ;
if ( V_417 -> V_164 & V_425 ) {
V_17 -> V_365 . V_347 . V_276 = 0 ;
V_17 -> V_365 . V_347 . V_25 = 0 ;
V_17 -> V_365 . V_347 . V_145 = V_417 -> V_259 . V_145 ;
V_17 -> V_365 . V_347 . V_39 = V_417 -> V_259 . V_39 ;
V_9 -> V_368 . V_365 . V_347 . V_145 = V_417 -> V_259 . V_145 ;
V_9 -> V_368 . V_365 . V_347 . V_39 = V_417 -> V_259 . V_39 ;
F_67 ( V_17 -> V_365 . V_357 ) ;
V_17 -> V_365 . V_357 = NULL ;
V_17 -> V_365 . V_366 = 0 ;
if ( F_12 ( V_17 , V_256 ) ) {
struct V_247 * V_248 ;
V_248 = F_107 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_9 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_108 ( V_9 , & V_17 -> V_365 , V_17 -> V_354 , V_248 ) ;
V_359 = F_65 ( V_9 , V_17 , V_248 ) ;
}
}
return V_359 ;
}
static int F_133 ( struct V_289 * V_289 , void * V_290 ,
struct V_426 * V_427 )
{
struct V_16 * V_17 = V_290 ;
return F_134 ( F_109 ( V_17 ) , V_427 ) ;
}
static int F_135 ( struct V_289 * V_289 , void * V_290 ,
struct V_428 * V_331 )
{
struct V_16 * V_17 = V_290 ;
return F_136 ( F_109 ( V_17 ) , V_331 ) ;
}
static int F_137 ( struct V_289 * V_289 , void * V_290 , struct V_428 * V_331 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
int V_372 = F_110 ( V_17 ) ;
if ( ! F_11 ( V_9 , V_17 , V_372 ) )
return - V_344 ;
return F_138 ( F_109 ( V_17 ) , V_331 ) ;
}
static int F_139 ( struct V_289 * V_289 , void * V_290 , struct V_428 * V_331 )
{
struct V_16 * V_17 = V_290 ;
return F_140 ( F_109 ( V_17 ) , V_331 ,
V_289 -> V_429 & V_430 ) ;
}
static int F_141 ( struct V_289 * V_289 , void * V_290 ,
enum V_374 type )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
int V_372 = F_110 ( V_17 ) ;
if ( ! F_11 ( V_9 , V_17 , V_372 ) )
return - V_344 ;
return F_142 ( F_109 ( V_17 ) ) ;
}
static int F_143 ( struct V_289 * V_289 , void * V_290 ,
enum V_374 type )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
int V_359 ;
int V_372 = F_110 ( V_17 ) ;
V_359 = F_144 ( F_109 ( V_17 ) ) ;
if ( V_359 < 0 )
return V_359 ;
F_18 ( V_9 , V_17 , V_372 ) ;
return 0 ;
}
static int F_145 ( struct V_289 * V_289 , void * V_292 ,
struct V_431 * V_432 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_432 -> type != V_369 )
return - V_97 ;
V_432 -> V_432 . V_286 . V_433 = V_281 ;
F_146 ( V_36 [ V_9 -> V_35 ] . V_161 ,
& V_432 -> V_432 . V_286 . V_434 ) ;
return 0 ;
}
static int F_147 ( struct V_289 * V_289 , void * V_290 ,
struct V_308 * V_309 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( 0 != V_309 -> V_297 )
return - V_97 ;
V_309 -> V_435 = V_436 ;
V_309 -> V_418 = V_437 ;
F_51 ( V_9 , V_287 , V_438 , V_309 ) ;
strcpy ( V_309 -> V_300 , L_16 ) ;
V_309 -> type = V_439 ;
if ( F_16 ( V_62 ) & V_107 )
V_309 -> signal = 0xffff ;
if ( V_9 -> V_311 )
V_9 -> V_311 ( V_9 , V_309 , 0 ) ;
return 0 ;
}
static int F_148 ( struct V_289 * V_289 , void * V_290 ,
struct V_440 * V_255 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_255 -> type != V_369 &&
V_255 -> type != V_441 )
return - V_97 ;
V_255 -> V_442 = V_36 [ V_9 -> V_35 ] . V_37 . V_442 ;
return 0 ;
}
static int F_149 ( struct V_289 * V_289 , void * V_292 , struct V_443 * V_444 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_444 -> type != V_369 &&
V_444 -> type != V_441 )
return - V_97 ;
switch ( V_444 -> V_445 ) {
case V_446 :
V_444 -> V_447 = V_9 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
break;
case V_448 :
V_444 -> V_447 = V_36 [ V_9 -> V_35 ] . V_37 . V_148 ;
break;
case V_449 :
V_444 -> V_447 = V_36 [ V_9 -> V_35 ] . V_37 . V_38 ;
break;
default:
return - V_97 ;
}
return 0 ;
}
static int F_150 ( struct V_289 * V_289 , void * V_292 , struct V_443 * V_444 )
{
struct V_16 * V_17 = V_292 ;
struct V_8 * V_9 = V_17 -> V_9 ;
const struct V_330 * V_331 ;
int V_359 ;
struct V_141 V_10 ;
T_2 V_450 ;
T_2 V_451 ;
T_2 V_452 ;
T_2 V_453 ;
if ( V_444 -> type != V_369 &&
V_444 -> type != V_441 )
return - V_97 ;
if ( V_444 -> V_445 != V_446 )
return - V_97 ;
V_359 = - V_344 ;
if ( F_13 ( V_17 -> V_9 , V_24 ) ) {
return V_359 ;
}
V_331 = & V_36 [ V_9 -> V_35 ] . V_37 . V_38 ;
V_450 = V_331 -> V_276 ;
V_452 = V_450 + V_331 -> V_145 ;
V_453 = V_331 -> V_25 + V_331 -> V_39 ;
V_451 = F_151 ( V_331 -> V_25 , V_9 -> V_29 ) ;
if ( V_451 + 32 >= V_453 ) {
return V_359 ;
}
V_10 . V_28 . V_276 = F_152 ( V_454 , V_444 -> V_447 . V_276 , V_450 , V_452 - 48 ) ;
V_10 . V_28 . V_276 = F_95 ( V_10 . V_28 . V_276 , ( T_2 ) V_335 ) ;
V_10 . V_28 . V_145 = F_152 ( V_454 , V_444 -> V_447 . V_145 ,
48 , V_452 - V_10 . V_28 . V_276 ) ;
V_10 . V_28 . V_25 = F_152 ( V_454 , V_444 -> V_447 . V_25 , V_451 , V_453 - 32 ) ;
V_10 . V_28 . V_25 = ( V_10 . V_28 . V_25 + 1 ) & ~ 1 ;
V_10 . V_28 . V_39 = F_152 ( V_454 , V_444 -> V_447 . V_39 ,
32 , V_453 - V_10 . V_28 . V_25 ) ;
V_10 . V_28 . V_39 = ( V_10 . V_28 . V_39 + 1 ) & ~ 1 ;
F_45 ( & V_10 ) ;
V_444 -> V_447 = V_10 . V_28 ;
V_9 -> V_26 [ 1 ] = V_10 ;
V_17 -> V_27 = 1 ;
if ( V_17 -> V_145 < V_10 . V_142 ) {
V_17 -> V_145 = V_10 . V_142 ;
V_9 -> V_368 . V_145 = V_10 . V_142 ;
} else if ( V_17 -> V_145 > V_10 . V_144 ) {
V_17 -> V_145 = V_10 . V_144 ;
V_9 -> V_368 . V_145 = V_10 . V_144 ;
}
if ( V_17 -> V_39 < V_10 . V_143 ) {
V_17 -> V_39 = V_10 . V_143 ;
V_9 -> V_368 . V_39 = V_10 . V_143 ;
} else if ( V_17 -> V_39 > V_10 . V_146 ) {
V_17 -> V_39 = V_10 . V_146 ;
V_9 -> V_368 . V_39 = V_10 . V_146 ;
}
return 0 ;
}
static T_1 F_153 ( struct V_289 * V_289 , char T_7 * V_237 ,
T_8 V_280 , T_9 * V_455 )
{
struct V_16 * V_17 = V_289 -> V_456 ;
int V_359 = 0 ;
if ( V_17 -> V_9 -> V_199 )
F_58 ( V_17 -> V_9 ) ;
F_22 ( L_23 ,
V_17 -> V_9 -> V_10 . V_58 , ( int ) V_280 , V_457 [ V_17 -> type ] ) ;
switch ( V_17 -> type ) {
case V_369 :
if ( ! F_11 ( V_17 -> V_9 , V_17 , V_21 ) ) {
return - V_344 ;
}
V_359 = F_154 ( & V_17 -> V_255 , V_237 , V_280 , V_455 ,
V_289 -> V_429 & V_430 ) ;
F_18 ( V_17 -> V_9 , V_17 , V_21 ) ;
break;
case V_370 :
if ( ! F_11 ( V_17 -> V_9 , V_17 , V_373 ) )
return - V_344 ;
V_359 = F_155 ( & V_17 -> V_371 , V_237 , V_280 , V_455 , 1 ,
V_289 -> V_429 & V_430 ) ;
break;
default:
F_100 () ;
}
return V_359 ;
}
static unsigned int F_156 ( struct V_289 * V_289 , T_10 * V_458 )
{
struct V_16 * V_17 = V_289 -> V_456 ;
struct V_247 * V_5 ;
enum V_260 V_261 ;
unsigned int V_264 = 0 ;
unsigned long V_459 = F_157 ( V_458 ) ;
if ( F_158 ( & V_17 -> V_17 ) )
V_264 = V_460 ;
else if ( V_459 & V_460 )
F_159 ( V_289 , & V_17 -> V_17 . V_458 , V_458 ) ;
if ( ! ( V_459 & ( V_461 | V_462 ) ) )
return V_264 ;
if ( V_370 == V_17 -> type ) {
if ( ! F_11 ( V_17 -> V_9 , V_17 , V_373 ) )
return V_264 | V_463 ;
return V_264 | F_160 ( V_289 , & V_17 -> V_371 , V_458 ) ;
}
if ( F_12 ( V_17 , V_22 ) ) {
if ( F_161 ( & V_17 -> V_255 . V_464 ) )
return V_264 | V_463 ;
V_5 = F_162 ( V_17 -> V_255 . V_464 . V_465 , struct V_247 , V_250 . V_464 ) ;
} else {
if ( NULL == V_17 -> V_255 . V_466 ) {
if ( F_13 ( V_17 -> V_9 , V_22 ) )
return V_264 | V_463 ;
V_17 -> V_255 . V_466 = F_107 ( V_17 -> V_255 . V_467 ) ;
if ( NULL == V_17 -> V_255 . V_466 )
return V_264 | V_463 ;
V_17 -> V_255 . V_466 -> V_468 = V_469 ;
V_261 = F_163 ( & V_17 -> V_255 ) ;
if ( 0 != V_17 -> V_255 . V_470 -> V_471 ( & V_17 -> V_255 , V_17 -> V_255 . V_466 , V_261 ) ) {
F_67 ( V_17 -> V_255 . V_466 ) ;
V_17 -> V_255 . V_466 = NULL ;
return V_264 | V_463 ;
}
V_17 -> V_255 . V_470 -> V_472 ( & V_17 -> V_255 , V_17 -> V_255 . V_466 ) ;
V_17 -> V_255 . V_473 = 0 ;
}
V_5 = (struct V_247 * ) V_17 -> V_255 . V_466 ;
}
F_159 ( V_289 , & V_5 -> V_250 . V_474 , V_458 ) ;
if ( V_5 -> V_250 . V_251 == V_252 ||
V_5 -> V_250 . V_251 == V_475 )
V_264 = V_264 | V_461 | V_462 ;
return V_264 ;
}
static int F_164 ( struct V_289 * V_289 )
{
struct V_6 * V_324 = F_89 ( V_289 ) ;
struct V_8 * V_9 = F_165 ( V_289 ) ;
struct V_16 * V_17 ;
enum V_374 type = 0 ;
F_22 ( L_24 , F_166 ( V_324 ) ) ;
if ( V_324 -> V_409 == V_410 ) {
type = V_369 ;
} else if ( V_324 -> V_409 == V_412 ) {
type = V_370 ;
} else {
F_167 ( 1 ) ;
return - V_476 ;
}
F_22 ( L_25 ,
V_9 -> V_10 . V_58 , V_457 [ type ] ) ;
V_17 = F_102 ( sizeof( * V_17 ) , V_361 ) ;
if ( F_130 ( ! V_17 ) )
return - V_362 ;
V_9 -> V_109 ++ ;
V_289 -> V_456 = V_17 ;
* V_17 = V_9 -> V_368 ;
F_168 ( & V_17 -> V_17 , V_324 ) ;
V_17 -> type = type ;
V_17 -> V_365 . V_367 = 0 ;
F_169 ( & V_17 -> V_255 , & V_477 ,
& V_9 -> V_10 . V_395 -> V_14 , & V_9 -> V_166 ,
V_369 ,
V_351 ,
sizeof( struct V_247 ) ,
V_17 , & V_9 -> V_478 ) ;
F_169 ( & V_17 -> V_371 , & V_479 ,
& V_9 -> V_10 . V_395 -> V_14 , & V_9 -> V_166 ,
V_370 ,
V_385 ,
sizeof( struct V_247 ) ,
V_17 , & V_9 -> V_478 ) ;
F_48 ( V_9 , V_9 -> V_35 ) ;
F_52 ( V_9 , V_9 -> V_69 , V_9 -> V_35 ) ;
F_40 ( V_9 , V_9 -> V_103 ) ;
V_17 -> V_27 = ! V_480 ;
F_170 ( & V_17 -> V_33 , V_9 -> V_35 ) ;
F_63 ( V_9 ) ;
F_171 ( & V_17 -> V_17 ) ;
return 0 ;
}
static int F_172 ( struct V_289 * V_289 )
{
struct V_16 * V_17 = V_289 -> V_456 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( F_12 ( V_17 , V_256 ) )
F_65 ( V_9 , V_17 , NULL ) ;
if ( F_12 ( V_17 , V_22 ) ) {
F_144 ( & V_17 -> V_255 ) ;
F_18 ( V_9 , V_17 , V_22 ) ;
}
if ( V_17 -> V_255 . V_466 ) {
F_75 ( & V_17 -> V_255 , V_17 -> V_255 . V_466 ) ;
F_67 ( V_17 -> V_255 . V_466 ) ;
}
if ( F_12 ( V_17 , V_21 ) ) {
F_18 ( V_9 , V_17 , V_21 ) ;
}
if ( F_12 ( V_17 , V_373 ) ) {
F_173 ( & V_17 -> V_371 ) ;
F_18 ( V_9 , V_17 , V_373 ) ;
}
F_174 ( & V_17 -> V_255 ) ;
F_174 ( & V_17 -> V_371 ) ;
V_289 -> V_456 = NULL ;
V_9 -> V_109 -- ;
F_63 ( V_9 ) ;
if ( ! V_9 -> V_109 )
F_40 ( V_9 , V_9 -> V_103 ) ;
F_175 ( & V_17 -> V_17 ) ;
F_176 ( & V_17 -> V_17 ) ;
F_67 ( V_17 ) ;
return 0 ;
}
static int
F_177 ( struct V_289 * V_289 , struct V_481 * V_482 )
{
struct V_16 * V_17 = V_289 -> V_456 ;
F_22 ( L_26 ,
V_17 -> V_9 -> V_10 . V_58 , V_457 [ V_17 -> type ] ,
V_482 -> V_483 , V_482 -> V_484 - V_482 -> V_483 ) ;
return F_178 ( F_109 ( V_17 ) , V_482 ) ;
}
static int F_179 ( struct V_289 * V_289 )
{
struct V_6 * V_324 = F_89 ( V_289 ) ;
struct V_8 * V_9 = F_165 ( V_289 ) ;
struct V_16 * V_17 ;
F_22 ( L_24 , F_166 ( V_324 ) ) ;
F_22 ( L_27 , V_9 -> V_10 . V_58 ) ;
V_17 = F_102 ( sizeof( * V_17 ) , V_361 ) ;
if ( F_130 ( ! V_17 ) )
return - V_362 ;
V_289 -> V_456 = V_17 ;
* V_17 = V_9 -> V_368 ;
F_168 ( & V_17 -> V_17 , V_324 ) ;
V_9 -> V_485 ++ ;
F_40 ( V_9 , V_9 -> V_103 ) ;
F_171 ( & V_17 -> V_17 ) ;
return 0 ;
}
static int F_180 ( struct V_289 * V_289 )
{
struct V_16 * V_17 = V_289 -> V_456 ;
struct V_8 * V_9 = V_17 -> V_9 ;
struct V_486 V_487 ;
V_289 -> V_456 = NULL ;
F_175 ( & V_17 -> V_17 ) ;
F_176 ( & V_17 -> V_17 ) ;
F_67 ( V_17 ) ;
V_9 -> V_485 -- ;
F_51 ( V_9 , V_326 , V_488 , V_489 , & V_487 ) ;
if ( V_9 -> V_485 == 0 )
V_9 -> V_110 = 0 ;
return 0 ;
}
static int F_181 ( struct V_289 * V_289 , void * V_290 , struct V_308 * V_309 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( 0 != V_309 -> V_297 )
return - V_97 ;
strcpy ( V_309 -> V_300 , L_28 ) ;
V_309 -> type = V_314 ;
F_76 ( V_9 ) ;
F_51 ( V_9 , V_287 , V_438 , V_309 ) ;
if ( V_9 -> V_311 )
V_9 -> V_311 ( V_9 , V_309 , 0 ) ;
if ( V_9 -> V_321 )
return F_182 ( & V_9 -> V_322 , V_309 ) ;
return 0 ;
}
static int F_183 ( struct V_289 * V_289 , void * V_290 ,
const struct V_308 * V_309 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( 0 != V_309 -> V_297 )
return - V_97 ;
F_76 ( V_9 ) ;
F_51 ( V_9 , V_287 , V_310 , V_309 ) ;
return 0 ;
}
static int F_184 ( struct V_289 * V_289 , void * V_290 ,
const struct V_490 * V_491 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_9 -> V_321 )
return F_185 ( V_289 , & V_9 -> V_322 , V_491 ) ;
return - V_492 ;
}
static int F_186 ( struct V_289 * V_289 , void * V_290 ,
struct V_493 * V_494 )
{
struct V_16 * V_17 = V_290 ;
struct V_8 * V_9 = V_17 -> V_9 ;
if ( V_9 -> V_321 )
return F_187 ( & V_9 -> V_322 , V_494 ) ;
return - V_492 ;
}
static T_1 F_188 ( struct V_289 * V_289 , char T_7 * V_237 ,
T_8 V_280 , T_9 * V_455 )
{
struct V_16 * V_17 = V_289 -> V_456 ;
struct V_8 * V_9 = V_17 -> V_9 ;
struct V_486 V_487 ;
V_487 . V_495 = V_280 / 3 ;
V_487 . V_496 = V_289 -> V_429 & V_430 ;
V_487 . V_497 = V_237 ;
V_487 . V_498 = V_289 ;
V_487 . V_499 = - V_476 ;
F_76 ( V_9 ) ;
F_51 ( V_9 , V_326 , V_488 , V_500 , & V_487 ) ;
return V_487 . V_499 ;
}
static unsigned int F_189 ( struct V_289 * V_289 , T_10 * V_458 )
{
struct V_16 * V_17 = V_289 -> V_456 ;
struct V_8 * V_9 = V_17 -> V_9 ;
unsigned long V_459 = F_157 ( V_458 ) ;
struct V_486 V_487 ;
unsigned int V_372 = 0 ;
if ( F_158 ( & V_17 -> V_17 ) )
V_372 = V_460 ;
else if ( V_459 & V_460 )
F_159 ( V_289 , & V_17 -> V_17 . V_458 , V_458 ) ;
F_76 ( V_9 ) ;
V_487 . V_498 = V_289 ;
V_487 . V_501 = V_458 ;
V_487 . V_499 = V_372 ;
F_51 ( V_9 , V_326 , V_488 , V_502 , & V_487 ) ;
return V_487 . V_499 ;
}
static int F_190 ( T_4 V_503 )
{
static char * V_504 [ 16 ] = {
[ V_505 >> 28 ] = L_29 ,
[ V_506 >> 28 ] = L_30 ,
[ V_507 >> 28 ] = L_31 ,
[ V_508 >> 28 ] = L_32 ,
[ V_509 >> 28 ] = L_33 ,
[ V_510 >> 28 ] = L_34 ,
[ V_511 >> 28 ] = L_35 ,
[ V_512 >> 28 ] = L_36 ,
} ;
static int V_513 [ 16 ] = {
[ V_505 >> 28 ] = 2 ,
[ V_508 >> 28 ] = 2 ,
[ V_509 >> 28 ] = 2 ,
[ V_510 >> 28 ] = 5 ,
[ V_511 >> 28 ] = 2 ,
[ V_512 >> 28 ] = 3 ,
} ;
static char * V_44 [] = {
L_37 , L_38 , L_39 , L_40 ,
L_41 , L_42 , L_43 , L_44 ,
L_45 , L_46 , L_47 , L_48 ,
L_49 , L_50 , L_51 , L_52 ,
} ;
int V_53 ;
F_191 ( L_53 , V_503 ,
V_504 [ V_503 >> 28 ] ? V_504 [ V_503 >> 28 ] : L_54 ) ;
for ( V_53 = F_192 ( V_44 ) - 1 ; V_53 >= 0 ; V_53 -- )
if ( V_503 & ( 1 << ( V_53 + 12 ) ) )
F_191 ( L_55 , V_44 [ V_53 ] ) ;
F_191 ( L_56 , V_503 & 0xfff ) ;
return V_513 [ V_503 >> 28 ] ? V_513 [ V_503 >> 28 ] : 1 ;
}
static void F_193 ( struct V_8 * V_9 ,
struct V_514 * V_503 )
{
unsigned int V_53 , V_515 , V_358 ;
F_23 ( L_57 ,
V_9 -> V_10 . V_325 . V_300 , V_503 -> V_516 , ( unsigned long ) V_503 -> V_517 ) ;
for ( V_53 = 0 ; V_53 < ( V_503 -> V_270 >> 2 ) ; V_53 += V_358 ) {
F_23 ( L_58 ,
V_9 -> V_10 . V_325 . V_300 ,
( unsigned long ) ( V_503 -> V_517 + ( V_53 << 2 ) ) ) ;
V_358 = F_190 ( F_194 ( V_503 -> V_516 [ V_53 ] ) ) ;
for ( V_515 = 1 ; V_515 < V_358 ; V_515 ++ )
F_23 ( L_59 ,
V_9 -> V_10 . V_325 . V_300 ,
( unsigned long ) ( V_503 -> V_517 + ( ( V_53 + V_515 ) << 2 ) ) ,
V_503 -> V_516 [ V_53 + V_515 ] , V_515 ) ;
if ( 0 == V_503 -> V_516 [ V_53 ] )
break;
}
}
static void F_195 ( struct V_8 * V_9 )
{
F_23 ( L_60 , ( unsigned long long ) V_9 -> main. V_517 ) ;
F_23 ( L_61 ,
V_9 -> V_518 ? ( unsigned long long ) V_9 -> V_518 -> V_25 . V_517 : 0 ,
V_9 -> V_518 ? ( unsigned long long ) V_9 -> V_518 -> V_519 . V_517 : 0 ) ;
F_23 ( L_62 ,
V_9 -> V_167 . V_25
? ( unsigned long long ) V_9 -> V_167 . V_25 -> V_25 . V_517 : 0 ,
V_9 -> V_167 . V_519
? ( unsigned long long ) V_9 -> V_167 . V_519 -> V_519 . V_517 : 0 ) ;
F_23 ( L_63 ,
V_9 -> V_253 ? ( unsigned long long ) V_9 -> V_253 -> V_25 . V_517 : 0 ,
V_9 -> V_253 ? ( unsigned long long ) V_9 -> V_253 -> V_519 . V_517 : 0 ) ;
F_193 ( V_9 , & V_9 -> main ) ;
}
static void F_196 ( T_4 V_520 , T_4 V_521 )
{
unsigned int V_53 ;
F_191 ( L_64 ) ;
for ( V_53 = 0 ; V_53 < F_192 ( V_522 ) ; V_53 ++ ) {
if ( V_520 & ( 1 << V_53 ) )
F_191 ( L_55 , V_522 [ V_53 ] ) ;
if ( V_521 & ( 1 << V_53 ) )
F_191 ( L_65 ) ;
}
}
static void F_197 ( struct V_8 * V_9 , T_4 V_264 )
{
F_198 ( L_66 ,
V_9 -> V_10 . V_58 ,
( unsigned long ) V_9 -> main. V_517 ,
( unsigned long ) F_194 ( V_9 -> main. V_516 [ V_523 + 1 ] ) ,
( unsigned long ) F_194 ( V_9 -> main. V_516 [ V_524 + 1 ] ) ,
( unsigned long ) V_264 ) ;
if ( 0 == ( F_16 ( V_62 ) & V_107 ) ) {
F_199 ( L_67 ,
V_9 -> V_10 . V_58 ) ;
return;
}
F_199 ( L_68 ,
V_9 -> V_10 . V_58 ) ;
F_199 ( L_69 ,
V_9 -> V_10 . V_58 ) ;
F_200 () ;
}
static int
F_201 ( struct V_8 * V_9 , struct V_525 * V_526 )
{
struct V_247 * V_527 ;
memset ( V_526 , 0 , sizeof( * V_526 ) ) ;
if ( ! F_161 ( & V_9 -> V_286 ) ) {
V_526 -> V_168 = 1 ;
V_527 = F_162 ( V_9 -> V_286 . V_465 , struct V_247 , V_250 . V_285 ) ;
if ( F_202 ( V_527 -> V_250 . V_261 ) )
V_526 -> V_25 = V_527 ;
if ( F_203 ( V_527 -> V_250 . V_261 ) )
V_526 -> V_519 = V_527 ;
if ( ! F_94 ( V_527 -> V_250 . V_261 ) &&
( V_527 -> V_250 . V_285 . V_465 != & V_9 -> V_286 ) ) {
V_527 = F_162 ( V_527 -> V_250 . V_285 . V_465 , struct V_247 , V_250 . V_285 ) ;
if ( ! F_94 ( V_527 -> V_250 . V_261 ) ) {
if ( NULL == V_526 -> V_519 &&
V_272 == V_527 -> V_250 . V_261 ) {
V_526 -> V_519 = V_527 ;
}
if ( NULL != V_526 -> V_25 && NULL != V_526 -> V_519 )
V_526 -> V_528 = 2 ;
}
}
}
if ( NULL != V_9 -> V_253 ) {
if ( F_94 ( V_9 -> V_253 -> V_250 . V_261 ) ) {
if ( NULL == V_526 -> V_25 && NULL == V_526 -> V_519 ) {
V_526 -> V_25 = V_9 -> V_253 ;
V_526 -> V_519 = V_9 -> V_253 ;
}
} else {
if ( V_271 == V_9 -> V_253 -> V_250 . V_261 &&
NULL == V_526 -> V_25 ) {
V_526 -> V_25 = V_9 -> V_253 ;
}
if ( V_272 == V_9 -> V_253 -> V_250 . V_261 &&
NULL == V_526 -> V_519 ) {
V_526 -> V_519 = V_9 -> V_253 ;
}
}
}
F_22 ( L_70 ,
V_9 -> V_10 . V_58 , V_526 -> V_25 , V_526 -> V_519 ,
V_9 -> V_253 , V_526 -> V_168 , V_526 -> V_528 ) ;
return 0 ;
}
static void
F_204 ( struct V_8 * V_9 , struct V_525 * V_529 ,
struct V_525 * V_167 , unsigned int V_251 )
{
struct V_530 V_531 ;
F_205 ( & V_531 ) ;
if ( V_529 -> V_25 == V_529 -> V_519 ) {
if ( NULL != V_529 -> V_25 && V_167 -> V_25 != V_529 -> V_25 ) {
if ( V_532 > 1 )
F_62 ( L_71 ,
V_9 -> V_10 . V_58 , V_529 -> V_25 ) ;
V_529 -> V_25 -> V_250 . V_531 = V_531 ;
V_529 -> V_25 -> V_250 . V_242 = V_9 -> V_242 ;
V_529 -> V_25 -> V_250 . V_251 = V_251 ;
F_206 ( & V_529 -> V_25 -> V_250 . V_474 ) ;
}
} else {
if ( NULL != V_529 -> V_25 && V_167 -> V_25 != V_529 -> V_25 ) {
if ( V_532 > 1 )
F_62 ( L_72 ,
V_9 -> V_10 . V_58 , V_529 -> V_25 ) ;
V_529 -> V_25 -> V_250 . V_531 = V_531 ;
V_529 -> V_25 -> V_250 . V_242 = V_9 -> V_242 ;
V_529 -> V_25 -> V_250 . V_251 = V_251 ;
F_206 ( & V_529 -> V_25 -> V_250 . V_474 ) ;
}
if ( NULL != V_529 -> V_519 && V_167 -> V_519 != V_529 -> V_519 ) {
if ( V_532 > 1 )
F_62 ( L_73 ,
V_9 -> V_10 . V_58 , V_529 -> V_519 ) ;
V_529 -> V_519 -> V_250 . V_531 = V_531 ;
V_529 -> V_519 -> V_250 . V_242 = V_9 -> V_242 ;
V_529 -> V_519 -> V_250 . V_251 = V_251 ;
F_206 ( & V_529 -> V_519 -> V_250 . V_474 ) ;
}
}
}
static void
F_207 ( struct V_8 * V_9 , struct V_247 * V_529 ,
unsigned int V_251 )
{
if ( NULL == V_529 )
return;
F_205 ( & V_529 -> V_250 . V_531 ) ;
V_529 -> V_250 . V_242 = V_9 -> V_242 ;
V_529 -> V_250 . V_251 = V_251 ;
F_206 ( & V_529 -> V_250 . V_474 ) ;
}
static void F_208 ( unsigned long V_237 )
{
struct V_8 * V_9 = (struct V_8 * ) V_237 ;
struct V_525 V_249 , V_248 ;
struct V_247 * V_533 ;
struct V_247 * V_527 ;
unsigned long V_164 ;
if ( V_60 ) {
F_23 ( L_74 ,
V_9 -> V_10 . V_58 , V_9 -> V_534 , V_9 -> V_535 , V_9 -> V_536 ,
F_16 ( V_537 ) ) ;
F_196 ( F_16 ( V_172 ) , 0 ) ;
F_191 ( L_75 ) ;
}
F_53 ( & V_9 -> V_166 , V_164 ) ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_249 = V_9 -> V_167 ;
V_533 = V_9 -> V_518 ;
V_9 -> V_167 = V_248 ;
V_9 -> V_518 = NULL ;
V_9 -> V_254 = 0 ;
F_209 ( V_9 , & V_248 ) ;
F_210 ( V_9 , NULL ) ;
F_59 ( V_9 , 0 ) ;
F_204 ( V_9 , & V_249 , & V_248 , V_475 ) ;
F_207 ( V_9 , V_533 , V_475 ) ;
while ( ! F_161 ( & V_9 -> V_286 ) ) {
V_527 = F_162 ( V_9 -> V_286 . V_465 , struct V_247 , V_250 . V_285 ) ;
F_211 ( & V_527 -> V_250 . V_285 ) ;
V_527 -> V_250 . V_251 = V_475 ;
F_206 ( & V_527 -> V_250 . V_474 ) ;
}
while ( ! F_161 ( & V_9 -> V_538 ) ) {
V_527 = F_162 ( V_9 -> V_538 . V_465 , struct V_247 , V_250 . V_285 ) ;
F_211 ( & V_527 -> V_250 . V_285 ) ;
V_527 -> V_250 . V_251 = V_475 ;
F_206 ( & V_527 -> V_250 . V_474 ) ;
}
V_9 -> V_199 ++ ;
F_54 ( & V_9 -> V_166 , V_164 ) ;
}
static void
F_212 ( struct V_8 * V_9 )
{
struct V_247 * V_529 = V_9 -> V_167 . V_25 ;
if ( NULL == V_529 )
return;
F_213 ( & V_9 -> V_166 ) ;
V_9 -> V_167 . V_528 = 0 ;
V_9 -> V_167 . V_25 = NULL ;
F_214 ( V_9 , V_524 , NULL , 0 ) ;
F_205 ( & V_529 -> V_250 . V_531 ) ;
V_529 -> V_250 . V_242 = V_9 -> V_242 ;
V_529 -> V_250 . V_251 = V_252 ;
F_206 ( & V_529 -> V_250 . V_474 ) ;
F_215 ( & V_9 -> V_166 ) ;
}
static inline int F_216 ( struct V_514 * V_503 , T_4 V_264 )
{
if ( V_264 < V_503 -> V_517 )
return 0 ;
if ( V_264 > V_503 -> V_517 + V_503 -> V_270 )
return 0 ;
return 1 ;
}
static void
F_217 ( struct V_8 * V_9 )
{
struct V_525 V_248 ;
struct V_525 V_249 ;
T_11 V_264 ;
F_213 ( & V_9 -> V_166 ) ;
F_201 ( V_9 , & V_248 ) ;
V_264 = F_16 ( V_537 ) ;
if ( ( V_9 -> V_167 . V_25 && F_216 ( & V_9 -> V_167 . V_25 -> V_25 , V_264 ) ) ||
( V_9 -> V_167 . V_519 && F_216 ( & V_9 -> V_167 . V_519 -> V_519 , V_264 ) ) ) {
V_9 -> V_534 ++ ;
if ( V_539 )
F_197 ( V_9 , V_264 ) ;
F_215 ( & V_9 -> V_166 ) ;
return;
}
V_249 = V_9 -> V_167 ;
V_9 -> V_167 = V_248 ;
V_9 -> V_254 &= ~ 1 ;
F_209 ( V_9 , & V_248 ) ;
F_59 ( V_9 , 0 ) ;
if ( V_11 != V_9 -> V_169 ) {
F_31 ( V_9 , V_9 -> V_169 ) ;
V_9 -> V_169 = V_11 ;
}
F_204 ( V_9 , & V_249 , & V_248 , V_252 ) ;
F_215 ( & V_9 -> V_166 ) ;
}
static void
F_218 ( struct V_8 * V_9 )
{
struct V_247 * V_248 = NULL ;
struct V_247 * V_249 ;
T_4 V_264 ;
F_213 ( & V_9 -> V_166 ) ;
if ( ! F_161 ( & V_9 -> V_538 ) )
V_248 = F_162 ( V_9 -> V_538 . V_465 , struct V_247 , V_250 . V_285 ) ;
V_249 = V_9 -> V_518 ;
V_264 = F_16 ( V_537 ) ;
if ( NULL != V_249 && ( F_216 ( & V_249 -> V_25 , V_264 ) ||
F_216 ( & V_249 -> V_519 , V_264 ) ) ) {
V_9 -> V_534 ++ ;
if ( V_539 )
F_197 ( V_9 , V_264 ) ;
F_215 ( & V_9 -> V_166 ) ;
return;
}
V_9 -> V_518 = V_248 ;
V_9 -> V_254 &= ~ 4 ;
F_210 ( V_9 , V_248 ) ;
F_59 ( V_9 , 0 ) ;
F_207 ( V_9 , V_249 , V_252 ) ;
F_215 ( & V_9 -> V_166 ) ;
}
static T_12 F_219 ( int V_540 , void * V_541 )
{
T_4 V_542 , V_543 ;
T_4 V_544 ;
int V_280 ;
struct V_8 * V_9 ;
int V_545 = 0 ;
V_9 = (struct V_8 * ) V_541 ;
V_280 = 0 ;
while ( 1 ) {
V_542 = F_16 ( V_172 ) ;
V_543 = V_542 & F_16 ( V_175 ) ;
if ( ! V_543 )
break;
V_545 = 1 ;
F_17 ( V_542 , V_172 ) ;
V_544 = F_16 ( V_62 ) ;
if ( V_532 ) {
F_62 ( L_76 ,
V_9 -> V_10 . V_58 , V_280 , V_9 -> V_242 ,
V_542 >> 28 , F_16 ( V_537 ) ) ;
F_196 ( V_542 , V_543 ) ;
if ( V_542 & V_185 )
F_191 ( L_77 ,
V_544 & V_107
? L_78 : L_79 ) ;
if ( V_542 & V_546 )
F_191 ( L_80 ,
V_544 & V_303
? L_78 : L_79 ) ;
if ( V_542 & V_184 )
F_191 ( L_81 ,
V_544 & V_293
? L_82 : L_83 ) ;
F_191 ( L_75 ) ;
}
if ( V_543 & V_241 )
V_9 -> V_242 ++ ;
if ( ( V_543 & V_178 ) && V_9 -> V_547 ) {
F_220 ( V_9 ) ;
}
if ( V_543 & V_174 ) {
V_9 -> V_548 = V_542 ;
F_206 ( & V_9 -> V_549 ) ;
}
if ( ( V_543 & V_182 ) && ( V_542 & ( 4 << 28 ) ) )
F_218 ( V_9 ) ;
if ( ( V_543 & V_182 ) && ( V_542 & ( 2 << 28 ) ) )
F_212 ( V_9 ) ;
if ( ( V_543 & V_182 ) && ( V_542 & ( 1 << 28 ) ) )
F_217 ( V_9 ) ;
if ( ( V_543 & V_185 ) && V_9 -> V_108 )
F_36 ( V_9 , V_9 -> V_119 , V_9 -> V_103 ) ;
if ( V_543 & ( V_179 | V_183 ) ) {
F_23 ( L_84 ,
V_9 -> V_10 . V_58 ,
( V_543 & V_179 ) ? L_85 : L_86 ,
( V_543 & V_183 ) ? L_87 : L_86 ,
F_16 ( V_537 ) ) ;
F_196 ( V_542 , V_543 ) ;
F_191 ( L_75 ) ;
if ( V_550 )
F_195 ( V_9 ) ;
}
if ( V_180 && V_543 & V_181 ) {
F_23 ( L_88 ,
V_9 -> V_10 . V_58 , F_16 ( V_537 ) ) ;
if ( V_550 )
F_195 ( V_9 ) ;
}
V_280 ++ ;
if ( V_280 > 4 ) {
if ( V_280 > 8 || ! ( V_543 & V_178 ) ) {
F_17 ( 0 , V_175 ) ;
F_19 ( L_89 ,
V_9 -> V_10 . V_58 ) ;
} else {
F_19 ( L_90 ,
V_9 -> V_10 . V_58 ) ;
F_17 ( F_16 ( V_175 ) & ( - 1 ^ V_178 ) ,
V_175 ) ;
}
F_196 ( V_542 , V_543 ) ;
F_191 ( L_91 ) ;
}
}
V_9 -> V_536 ++ ;
if ( V_545 )
V_9 -> V_535 ++ ;
return F_221 ( V_545 ) ;
}
static void F_222 ( struct V_8 * V_9 ,
struct V_6 * V_7 ,
const struct V_6 * V_551 ,
const char * V_552 )
{
* V_7 = * V_551 ;
V_7 -> V_325 = & V_9 -> V_10 . V_325 ;
V_7 -> V_553 = V_554 ;
F_223 ( V_7 , V_9 ) ;
snprintf ( V_7 -> V_300 , sizeof( V_7 -> V_300 ) , L_92 ,
V_9 -> V_149 , ( V_9 -> V_149 == 848 && V_9 -> V_555 == 0x12 ) ? L_93 : L_86 ,
V_552 , V_95 [ V_9 -> V_10 . type ] . V_300 ) ;
if ( V_9 -> V_170 == V_171 ) {
F_224 ( V_7 , V_556 ) ;
F_224 ( V_7 , V_557 ) ;
F_224 ( V_7 , V_558 ) ;
F_224 ( V_7 , V_559 ) ;
}
}
static void F_225 ( struct V_8 * V_9 )
{
F_226 ( & V_9 -> V_393 ) ;
F_226 ( & V_9 -> V_402 ) ;
F_226 ( & V_9 -> V_404 ) ;
}
static int F_227 ( struct V_8 * V_9 )
{
if ( V_388 > 0 )
F_199 ( L_94 ) ;
F_222 ( V_9 , & V_9 -> V_393 , & V_560 , L_95 ) ;
if ( F_228 ( & V_9 -> V_393 , V_410 ,
V_561 [ V_9 -> V_10 . V_58 ] ) < 0 )
goto V_562;
F_23 ( L_96 ,
V_9 -> V_10 . V_58 , F_166 ( & V_9 -> V_393 ) ) ;
if ( F_229 ( & V_9 -> V_393 . V_14 ,
& V_563 ) < 0 ) {
F_19 ( L_97 , V_9 -> V_10 . V_58 ) ;
goto V_562;
}
F_222 ( V_9 , & V_9 -> V_402 , & V_560 , L_98 ) ;
if ( F_228 ( & V_9 -> V_402 , V_412 ,
V_564 [ V_9 -> V_10 . V_58 ] ) < 0 )
goto V_562;
F_23 ( L_96 ,
V_9 -> V_10 . V_58 , F_166 ( & V_9 -> V_402 ) ) ;
if ( ! V_9 -> V_565 )
return 0 ;
F_222 ( V_9 , & V_9 -> V_404 , & V_566 , L_99 ) ;
V_9 -> V_404 . V_121 = & V_9 -> V_567 ;
if ( F_228 ( & V_9 -> V_404 , V_568 ,
V_569 [ V_9 -> V_10 . V_58 ] ) < 0 )
goto V_562;
F_23 ( L_96 ,
V_9 -> V_10 . V_58 , F_166 ( & V_9 -> V_404 ) ) ;
return 0 ;
V_562:
F_225 ( V_9 ) ;
return - 1 ;
}
static void F_230 ( struct V_570 * V_14 )
{
#if F_231 ( V_571 )
unsigned int V_487 ;
F_232 ( V_14 , V_572 , & V_487 ) ;
V_487 = ( V_487 | V_573 ) ;
F_233 ( V_14 , V_572 , V_487 ) ;
#endif
}
static int F_234 ( struct V_570 * V_14 , const struct V_574 * V_575 )
{
struct V_313 V_576 = {
. V_287 = 0 ,
. type = V_439 ,
. V_315 = 980 ,
} ;
int V_499 ;
unsigned char V_577 ;
struct V_8 * V_9 ;
struct V_578 * V_579 ;
if ( V_580 == V_581 )
return - V_362 ;
F_23 ( L_100 , V_580 ) ;
V_582 [ V_580 ] = V_9 = F_235 ( sizeof( * V_9 ) , V_361 ) ;
if ( V_9 == NULL ) {
F_19 ( L_101 ) ;
return - V_362 ;
}
V_9 -> V_10 . V_58 = V_580 ;
snprintf ( V_9 -> V_10 . V_325 . V_300 , sizeof( V_9 -> V_10 . V_325 . V_300 ) ,
L_102 , V_9 -> V_10 . V_58 ) ;
F_236 ( & V_9 -> V_478 ) ;
F_237 ( & V_9 -> V_166 ) ;
F_237 ( & V_9 -> V_583 ) ;
F_238 ( & V_9 -> V_549 ) ;
F_239 ( & V_9 -> V_10 . V_584 ) ;
F_239 ( & V_9 -> V_286 ) ;
F_239 ( & V_9 -> V_538 ) ;
F_240 ( & V_9 -> V_585 , F_208 , ( unsigned long ) V_9 ) ;
V_9 -> V_586 = - 1 ;
V_9 -> V_170 = V_11 ;
V_9 -> V_169 = V_11 ;
V_9 -> V_565 = V_587 [ V_9 -> V_10 . V_58 ] ;
V_9 -> V_10 . V_395 = V_14 ;
V_9 -> V_149 = V_14 -> V_1 ;
if ( F_241 ( V_14 ) ) {
F_198 ( L_103 , V_9 -> V_10 . V_58 ) ;
return - V_588 ;
}
if ( F_242 ( V_14 , F_243 ( 32 ) ) ) {
F_198 ( L_104 , V_9 -> V_10 . V_58 ) ;
return - V_588 ;
}
if ( ! F_244 ( F_245 ( V_14 , 0 ) ,
F_246 ( V_14 , 0 ) ,
V_9 -> V_10 . V_325 . V_300 ) ) {
F_198 ( L_105 ,
V_9 -> V_10 . V_58 ,
( unsigned long long ) F_245 ( V_14 , 0 ) ) ;
return - V_344 ;
}
F_247 ( V_14 ) ;
F_230 ( V_14 ) ;
V_499 = F_248 ( & V_14 -> V_14 , & V_9 -> V_10 . V_325 ) ;
if ( V_499 < 0 ) {
F_198 ( L_106 , V_9 -> V_10 . V_58 ) ;
goto V_589;
}
V_579 = & V_9 -> V_121 ;
F_249 ( V_579 , 20 ) ;
V_9 -> V_10 . V_325 . V_121 = V_579 ;
F_249 ( & V_9 -> V_567 , 6 ) ;
V_9 -> V_555 = V_14 -> V_555 ;
F_250 ( V_14 , V_590 , & V_577 ) ;
F_23 ( L_107 ,
V_580 , V_9 -> V_149 , V_9 -> V_555 , F_123 ( V_14 ) ,
V_9 -> V_10 . V_395 -> V_540 , V_577 ,
( unsigned long long ) F_245 ( V_14 , 0 ) ) ;
F_251 () ;
V_9 -> V_591 = F_252 ( F_245 ( V_14 , 0 ) , 0x1000 ) ;
if ( NULL == V_9 -> V_591 ) {
F_19 ( L_108 , V_9 -> V_10 . V_58 ) ;
V_499 = - V_588 ;
goto V_592;
}
F_253 ( V_9 ) ;
F_17 ( 0 , V_175 ) ;
V_499 = F_254 ( V_9 -> V_10 . V_395 -> V_540 , F_219 ,
V_593 , V_9 -> V_10 . V_325 . V_300 , ( void * ) V_9 ) ;
if ( V_499 < 0 ) {
F_19 ( L_109 ,
V_580 , V_9 -> V_10 . V_395 -> V_540 ) ;
goto V_592;
}
if ( 0 != F_255 ( V_9 ) ) {
V_499 = - V_588 ;
goto V_594;
}
V_9 -> V_215 = V_595 ;
V_596 . V_597 = V_595 ;
V_598 . V_597 = V_599 ;
V_9 -> V_108 = V_600 ;
V_601 . V_597 = V_600 ;
V_602 . V_597 = V_603 ;
V_9 -> V_224 = V_604 ;
V_605 . V_597 = V_604 ;
V_606 . V_597 = V_607 ;
V_608 . V_597 = V_609 ;
V_9 -> V_90 = V_610 ;
V_611 . V_597 = V_610 ;
V_612 . V_597 = V_613 ;
V_614 . V_597 = V_615 ;
V_9 -> V_368 . V_9 = V_9 ;
V_9 -> V_368 . V_365 . V_347 . V_145 = 320 ;
V_9 -> V_368 . V_365 . V_347 . V_39 = 240 ;
V_9 -> V_368 . V_259 = F_64 ( V_616 ) ;
V_9 -> V_368 . V_145 = 320 ;
V_9 -> V_368 . V_39 = 240 ;
V_9 -> V_368 . V_365 . V_347 . V_145 = 320 ;
V_9 -> V_368 . V_365 . V_347 . V_39 = 240 ;
V_9 -> V_368 . V_365 . V_261 = V_351 ;
V_9 -> V_69 = 0 ;
F_256 ( V_579 , & V_617 ,
V_202 , 0 , 0xff00 , 0x100 , 32768 ) ;
F_256 ( V_579 , & V_617 ,
V_204 , 0 , 0xff80 , 0x80 , 0x6c00 ) ;
F_256 ( V_579 , & V_617 ,
V_205 , 0 , 0xff80 , 0x80 , 32768 ) ;
F_256 ( V_579 , & V_617 ,
V_206 , 0 , 1 , 1 , 0 ) ;
F_256 ( V_579 , & V_617 ,
V_203 , 0 , 0xff00 , 0x100 , 32768 ) ;
F_256 ( V_579 , & V_617 ,
V_212 , 0 , 1 , 1 , ! ! V_618 ) ;
F_256 ( V_579 , & V_617 ,
V_122 , 0 , 1 , 1 , 0 ) ;
if ( V_9 -> V_211 )
F_256 ( V_579 , & V_617 ,
V_210 , 0 , 0xff00 , 0x100 , 0xff00 ) ;
F_257 ( V_579 , & V_596 , NULL ) ;
F_257 ( V_579 , & V_601 , NULL ) ;
F_257 ( V_579 , & V_598 , NULL ) ;
F_257 ( V_579 , & V_602 , NULL ) ;
F_257 ( V_579 , & V_605 , NULL ) ;
F_257 ( V_579 , & V_608 , NULL ) ;
F_257 ( V_579 , & V_606 , NULL ) ;
F_257 ( V_579 , & V_611 , NULL ) ;
F_257 ( V_579 , & V_612 , NULL ) ;
F_257 ( V_579 , & V_614 , NULL ) ;
if ( V_115 )
F_39 ( V_9 , L_110 ) ;
F_258 ( V_9 ) ;
F_56 ( V_9 ) ;
F_17 ( 0x00 , V_619 ) ;
F_17 ( 0x00 , V_238 ) ;
if ( V_60 )
F_39 ( V_9 , L_111 ) ;
F_259 ( V_9 ) ;
F_260 ( V_9 ) ;
F_261 ( V_9 ) ;
F_262 ( V_9 ) ;
if ( V_9 -> V_170 != V_171 ) {
F_85 ( V_9 , & V_576 ) ;
V_9 -> V_316 = 90500 * 16 ;
}
V_9 -> V_291 = V_620 ;
F_55 ( V_9 ) ;
if ( ! V_95 [ V_9 -> V_10 . type ] . V_173 )
F_57 ( V_579 ) ;
if ( V_579 -> error ) {
V_499 = V_579 -> error ;
goto V_594;
}
F_40 ( V_9 , 1 ) ;
if ( ! V_95 [ V_9 -> V_10 . type ] . V_173 ) {
F_263 ( & V_9 -> V_567 , V_579 ,
V_621 ) ;
if ( V_9 -> V_567 . error ) {
V_499 = V_9 -> V_567 . error ;
goto V_594;
}
F_52 ( V_9 , 0 , V_9 -> V_35 ) ;
F_47 ( & V_9 -> V_26 [ 0 ] , V_9 -> V_35 ) ;
V_9 -> V_26 [ 1 ] = V_9 -> V_26 [ 0 ] ;
F_14 ( V_9 ) ;
F_15 ( V_9 ) ;
F_227 ( V_9 ) ;
}
if ( V_95 [ V_9 -> V_10 . type ] . V_622 ) {
F_264 ( & V_9 -> V_10 , L_112 ) ;
F_6 ( V_9 ) ;
}
if ( ! V_623 ) {
F_265 ( V_9 ) ;
F_266 ( V_9 ) ;
}
V_580 ++ ;
return 0 ;
V_594:
F_267 ( V_9 -> V_10 . V_395 -> V_540 , V_9 ) ;
V_592:
F_268 ( & V_9 -> V_121 ) ;
F_268 ( & V_9 -> V_567 ) ;
F_269 ( & V_9 -> V_10 . V_325 ) ;
V_589:
if ( V_9 -> V_591 )
F_270 ( V_9 -> V_591 ) ;
F_271 ( F_245 ( V_9 -> V_10 . V_395 , 0 ) ,
F_246 ( V_9 -> V_10 . V_395 , 0 ) ) ;
F_272 ( V_9 -> V_10 . V_395 ) ;
return V_499 ;
}
static void F_273 ( struct V_570 * V_570 )
{
struct V_624 * V_325 = F_274 ( V_570 ) ;
struct V_8 * V_9 = F_275 ( V_325 ) ;
if ( V_60 )
F_23 ( L_113 , V_9 -> V_10 . V_58 ) ;
if ( V_95 [ V_9 -> V_10 . type ] . V_622 )
F_9 ( V_9 ) ;
F_34 ( ~ 15 , V_196 ) ;
F_17 ( 0 , V_175 ) ;
F_17 ( ~ 0x0 , V_172 ) ;
F_17 ( 0x0 , V_238 ) ;
if ( V_115 )
F_39 ( V_9 , L_114 ) ;
V_9 -> V_625 = 1 ;
F_276 ( V_9 ) ;
F_277 ( & V_9 -> V_10 ) ;
F_278 ( V_9 ) ;
F_225 ( V_9 ) ;
F_268 ( & V_9 -> V_121 ) ;
F_268 ( & V_9 -> V_567 ) ;
F_279 ( V_9 -> V_10 . V_395 , & V_9 -> main ) ;
F_267 ( V_9 -> V_10 . V_395 -> V_540 , V_9 ) ;
F_270 ( V_9 -> V_591 ) ;
F_271 ( F_245 ( V_9 -> V_10 . V_395 , 0 ) ,
F_246 ( V_9 -> V_10 . V_395 , 0 ) ) ;
F_272 ( V_9 -> V_10 . V_395 ) ;
F_269 ( & V_9 -> V_10 . V_325 ) ;
V_582 [ V_9 -> V_10 . V_58 ] = NULL ;
F_67 ( V_9 ) ;
return;
}
static int F_280 ( struct V_570 * V_570 , T_13 V_251 )
{
struct V_624 * V_325 = F_274 ( V_570 ) ;
struct V_8 * V_9 = F_275 ( V_325 ) ;
struct V_525 V_626 ;
unsigned long V_164 ;
F_22 ( L_115 , V_9 -> V_10 . V_58 , V_251 . V_627 ) ;
F_53 ( & V_9 -> V_166 , V_164 ) ;
memset ( & V_626 , 0 , sizeof( V_626 ) ) ;
V_9 -> V_251 . V_162 = V_9 -> V_167 ;
V_9 -> V_251 . V_371 = V_9 -> V_518 ;
V_9 -> V_251 . V_254 = V_9 -> V_254 ;
V_9 -> V_167 = V_626 ;
V_9 -> V_254 = 0 ;
F_209 ( V_9 , & V_626 ) ;
F_210 ( V_9 , NULL ) ;
F_59 ( V_9 , 0 ) ;
F_17 ( 0 , V_175 ) ;
F_54 ( & V_9 -> V_166 , V_164 ) ;
V_9 -> V_251 . V_628 = F_16 ( V_238 ) ;
V_9 -> V_251 . V_629 = F_50 () ;
F_281 ( V_570 ) ;
if ( 0 != F_282 ( V_570 , F_283 ( V_570 , V_251 ) ) ) {
F_272 ( V_570 ) ;
V_9 -> V_251 . V_630 = 1 ;
}
return 0 ;
}
static int F_284 ( struct V_570 * V_570 )
{
struct V_624 * V_325 = F_274 ( V_570 ) ;
struct V_8 * V_9 = F_275 ( V_325 ) ;
unsigned long V_164 ;
int V_562 ;
F_22 ( L_116 , V_9 -> V_10 . V_58 ) ;
if ( V_9 -> V_251 . V_630 ) {
V_562 = F_241 ( V_570 ) ;
if ( V_562 ) {
F_198 ( L_103 , V_9 -> V_10 . V_58 ) ;
return V_562 ;
}
V_9 -> V_251 . V_630 = 0 ;
}
V_562 = F_282 ( V_570 , V_631 ) ;
if ( V_562 ) {
F_272 ( V_570 ) ;
F_198 ( L_103 , V_9 -> V_10 . V_58 ) ;
V_9 -> V_251 . V_630 = 1 ;
return V_562 ;
}
F_285 ( V_570 ) ;
F_58 ( V_9 ) ;
F_32 ( 0xffffff , V_9 -> V_251 . V_628 ) ;
F_286 ( V_9 -> V_251 . V_629 ) ;
F_53 ( & V_9 -> V_166 , V_164 ) ;
V_9 -> V_167 = V_9 -> V_251 . V_162 ;
V_9 -> V_518 = V_9 -> V_251 . V_371 ;
V_9 -> V_254 = V_9 -> V_251 . V_254 ;
F_209 ( V_9 , & V_9 -> V_167 ) ;
F_210 ( V_9 , V_9 -> V_518 ) ;
F_59 ( V_9 , 0 ) ;
F_54 ( & V_9 -> V_166 , V_164 ) ;
return 0 ;
}
static int T_14 F_287 ( void )
{
int V_632 ;
V_580 = 0 ;
F_23 ( L_117 , V_633 ) ;
if ( V_281 < 2 || V_281 > V_634 )
V_281 = 2 ;
if ( V_282 > V_635 )
V_282 = V_635 ;
V_282 = ( V_282 + V_636 - 1 ) & V_637 ;
if ( V_60 )
F_23 ( L_118 ,
V_281 , V_282 >> 10 , V_282 >> V_638 ) ;
F_288 () ;
V_632 = F_289 ( & V_639 ) ;
if ( V_632 < 0 ) {
F_198 ( L_119 , V_632 ) ;
return V_632 ;
}
V_632 = F_290 ( & V_640 ) ;
if ( V_632 < 0 )
F_291 ( & V_639 ) ;
return V_632 ;
}
static void T_15 F_292 ( void )
{
F_293 ( & V_640 ) ;
F_291 ( & V_639 ) ;
}
