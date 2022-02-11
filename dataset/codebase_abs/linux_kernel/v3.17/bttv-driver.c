static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_10 ? V_10 -> V_11 . type : V_12 ) ;
}
static void F_4 ( struct V_13 * V_14 )
{
F_5 ( L_2 ) ;
}
static void F_6 ( struct V_9 * V_8 )
{
F_7 ( & V_8 -> V_15 , F_4 ) ;
F_8 ( & V_8 -> V_15 ) ;
}
static void F_9 ( struct V_9 * V_8 )
{
F_10 ( & V_8 -> V_15 ) ;
}
static
int F_11 ( struct V_9 * V_10 , struct V_16 * V_17 , int V_18 )
{
int V_19 ;
if ( V_17 -> V_20 & V_18 )
return 1 ;
V_19 = V_18 ;
if ( V_18 & ( V_21 | V_22 ) )
V_19 |= V_21 | V_22 ;
if ( V_10 -> V_20 & V_19 ) {
goto V_23;
}
if ( ( V_18 & V_24 )
&& 0 == ( V_10 -> V_20 & V_24 ) ) {
T_2 V_25 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_25 ;
if ( V_10 -> V_29 > V_25 )
goto V_23;
V_10 -> V_30 = V_25 ;
} else if ( V_18 & V_31 ) {
T_2 V_32 = V_17 -> V_33 . V_32 ;
if ( V_32 > V_10 -> V_30 )
goto V_23;
V_10 -> V_29 = V_32 ;
}
V_17 -> V_20 |= V_18 ;
V_10 -> V_20 |= V_18 ;
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
int F_13 ( struct V_9 * V_10 , int V_18 )
{
return ( V_10 -> V_20 & V_18 ) ;
}
static void
F_14 ( struct V_9 * V_10 )
{
V_10 -> V_29 = 0 ;
}
static void
F_15 ( struct V_9 * V_10 )
{
const struct V_34 * V_35 ;
T_3 V_26 ;
V_35 = & V_36 [ V_10 -> V_35 ] ;
V_10 -> V_30 = V_35 -> V_37 . V_38 . V_25
+ V_35 -> V_37 . V_38 . V_39 ;
V_26 = F_16 ( V_40 ) | 0xc0 ;
F_17 ( V_26 , V_40 ) ;
F_17 ( 0xfe , V_41 ) ;
F_17 ( V_26 , V_42 ) ;
F_17 ( 0xfe , V_43 ) ;
}
static
void F_18 ( struct V_9 * V_10 , struct V_16 * V_17 , int V_44 )
{
if ( ( V_17 -> V_20 & V_44 ) != V_44 ) {
F_19 ( L_3 ) ;
}
V_17 -> V_20 &= ~ V_44 ;
V_10 -> V_20 &= ~ V_44 ;
V_44 = V_10 -> V_20 ;
if ( 0 == ( V_44 & V_24 ) )
F_15 ( V_10 ) ;
if ( 0 == ( V_44 & V_31 ) )
F_14 ( V_10 ) ;
}
static void F_20 ( struct V_9 * V_10 , unsigned int V_45 , unsigned int V_46 )
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
static void F_21 ( struct V_9 * V_10 )
{
int V_53 ;
if ( ! V_10 -> V_54 . V_55 )
return;
if ( V_10 -> V_54 . V_56 == V_10 -> V_54 . V_57 ) {
F_22 ( L_4 , V_10 -> V_11 . V_58 ) ;
return;
}
if ( V_10 -> V_54 . V_59 == V_10 -> V_54 . V_56 ) {
if ( V_10 -> V_54 . V_57 == 0 )
return;
if ( V_60 )
F_23 ( L_5 ,
V_10 -> V_11 . V_58 , V_10 -> V_54 . V_59 ) ;
F_17 ( 0x00 , V_61 ) ;
F_17 ( 0x00 , V_52 ) ;
V_10 -> V_54 . V_57 = 0 ;
return;
}
if ( V_60 )
F_23 ( L_6 ,
V_10 -> V_11 . V_58 ,
V_10 -> V_54 . V_59 , V_10 -> V_54 . V_56 ) ;
F_20 ( V_10 , V_10 -> V_54 . V_59 , V_10 -> V_54 . V_56 ) ;
for ( V_53 = 0 ; V_53 < 10 ; V_53 ++ ) {
F_24 ( 10 ) ;
if ( F_16 ( V_62 ) & V_63 ) {
F_17 ( 0 , V_62 ) ;
} else {
F_17 ( 0x08 , V_61 ) ;
V_10 -> V_54 . V_57 = V_10 -> V_54 . V_56 ;
if ( V_60 )
F_23 ( L_7 ) ;
return;
}
}
V_10 -> V_54 . V_57 = - 1 ;
if ( V_60 )
F_23 ( L_8 ) ;
return;
}
static void F_25 ( struct V_9 * V_10 )
{
int V_53 , V_64 ;
int V_65 = V_36 [ V_10 -> V_35 ] . V_66 ;
int V_67 = V_36 [ V_10 -> V_35 ] . V_68 ;
if ( V_10 -> V_69 == V_10 -> V_70 ) {
F_22 ( L_9 ,
V_10 -> V_11 . V_58 , V_65 ) ;
F_17 ( 0x00 , V_61 ) ;
F_17 ( 0x02 , V_61 ) ;
F_17 ( 0x00 , V_61 ) ;
V_64 = V_71 [ V_65 ] [ 0 ] ;
for( V_53 = 1 ; V_53 <= V_64 ; V_53 ++ )
F_17 ( V_71 [ V_65 ] [ V_53 ] , V_72 ) ;
V_10 -> V_54 . V_56 = 27000000 ;
F_21 ( V_10 ) ;
F_17 ( 0x11 , V_61 ) ;
F_17 ( 0x41 , V_73 ) ;
} else {
V_10 -> V_54 . V_56 = V_67 ;
F_21 ( V_10 ) ;
F_17 ( 0x0 , V_73 ) ;
}
}
static void F_26 ( struct V_9 * V_10 , int V_74 )
{
int V_75 ;
V_10 -> V_74 = V_74 ;
V_75 = ( V_74 >> 8 ) - 128 ;
F_17 ( V_75 & 0xff , V_76 ) ;
}
static void F_27 ( struct V_9 * V_10 , int V_77 )
{
int V_75 ;
V_10 -> V_77 = V_77 ;
V_75 = ( V_77 >> 8 ) - 128 ;
F_17 ( V_75 & 0xff , V_78 ) ;
}
static void F_28 ( struct V_9 * V_10 , int V_79 )
{
int V_75 , V_80 ;
V_10 -> V_81 = V_79 ;
V_75 = ( V_79 >> 7 ) ;
V_80 = ( V_75 >> 6 ) & 4 ;
F_17 ( V_75 & 0xff , V_82 ) ;
F_29 ( V_80 , ~ 4 , V_83 ) ;
F_29 ( V_80 , ~ 4 , V_84 ) ;
}
static void F_30 ( struct V_9 * V_10 , int V_85 )
{
int V_86 , V_87 , V_88 ;
V_10 -> V_89 = V_85 ;
V_86 = ( ( V_85 * V_10 -> V_90 ) / 50 ) >> 7 ;
V_87 = ( ( ( V_85 * ( 100 - V_10 -> V_90 ) / 50 ) >> 7 ) * 180L ) / 254 ;
V_88 = ( V_86 >> 7 ) & 2 ;
V_88 |= ( V_87 >> 8 ) & 1 ;
F_17 ( V_86 & 0xff , V_91 ) ;
F_17 ( V_87 & 0xff , V_92 ) ;
F_29 ( V_88 , ~ 3 , V_83 ) ;
F_29 ( V_88 , ~ 3 , V_84 ) ;
}
static int
F_31 ( struct V_9 * V_10 , unsigned int V_69 )
{
int V_93 , V_94 ;
if ( V_69 >= V_95 [ V_10 -> V_11 . type ] . V_96 )
return - V_97 ;
V_94 = V_95 [ V_10 -> V_11 . type ] . V_98 ;
if ( V_94 )
F_32 ( V_94 , V_94 ) ;
if ( V_69 == V_10 -> V_99 ) {
F_33 ( V_100 , V_83 ) ;
F_33 ( V_100 , V_84 ) ;
} else {
F_34 ( ~ V_100 , V_83 ) ;
F_34 ( ~ V_100 , V_84 ) ;
}
V_93 = F_35 ( V_10 , V_69 ) ;
F_29 ( V_93 << 5 , ~ ( 3 << 5 ) , V_101 ) ;
F_22 ( L_10 , V_10 -> V_11 . V_58 , V_69 , V_93 ) ;
if( V_95 [ V_10 -> V_11 . type ] . V_102 )
V_95 [ V_10 -> V_11 . type ] . V_102 ( V_10 , V_69 ) ;
return 0 ;
}
static void
F_36 ( struct V_9 * V_10 , int V_69 , int V_103 )
{
int V_104 , signal , V_105 ;
F_32 ( V_95 [ V_10 -> V_11 . type ] . V_106 ,
V_95 [ V_10 -> V_11 . type ] . V_106 ) ;
signal = F_16 ( V_62 ) & V_107 ;
V_105 = V_103 || ( V_10 -> V_108 && ( ! signal || ! V_10 -> V_109 )
&& ! V_10 -> V_110 ) ;
if ( V_105 )
V_104 = V_95 [ V_10 -> V_11 . type ] . V_111 ;
else
V_104 = V_95 [ V_10 -> V_11 . type ] . V_112 [ V_69 ] ;
switch ( V_10 -> V_11 . type ) {
case V_113 :
case V_114 :
V_104 = F_37 ( V_10 , V_104 ) ;
break;
default:
F_38 ( V_95 [ V_10 -> V_11 . type ] . V_106 , V_104 ) ;
}
if ( V_115 )
F_39 ( V_10 , V_116 [ V_105 ? 4 : V_69 ] ) ;
}
static int
F_40 ( struct V_9 * V_10 , int V_103 )
{
struct V_117 * V_118 ;
F_36 ( V_10 , V_10 -> V_119 , V_103 ) ;
if ( V_10 -> V_120 ) {
V_118 = F_41 ( V_10 -> V_120 -> V_121 , V_122 ) ;
if ( V_118 )
F_42 ( V_118 , V_103 ) ;
}
if ( V_10 -> V_123 ) {
V_118 = F_41 ( V_10 -> V_123 -> V_121 , V_122 ) ;
if ( V_118 )
F_42 ( V_118 , V_103 ) ;
}
if ( V_10 -> V_124 ) {
V_118 = F_41 ( V_10 -> V_124 -> V_121 , V_122 ) ;
if ( V_118 )
F_42 ( V_118 , V_103 ) ;
}
return 0 ;
}
static int
V_119 ( struct V_9 * V_10 , int V_69 )
{
F_36 ( V_10 , V_69 , V_10 -> V_103 ) ;
if ( V_10 -> V_120 ) {
T_4 V_125 ;
switch ( V_69 ) {
case V_126 :
if ( V_10 -> V_127 ) {
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
if ( V_10 -> V_11 . type == V_114 )
V_125 = F_43 ( V_133 , V_136 , \
V_137 , V_137 ) ;
else
V_125 = V_128 ;
break;
}
F_44 ( V_10 -> V_120 , V_138 , V_139 ,
V_125 , V_140 , 0 ) ;
}
if ( V_10 -> V_123 ) {
F_44 ( V_10 -> V_123 , V_138 , V_139 ,
V_69 , 0 , 0 ) ;
}
return 0 ;
}
static void
F_45 ( struct V_141 * V_11 )
{
if ( 1 ) {
V_11 -> V_142 = 48 ;
V_11 -> V_143 = 32 ;
} else {
V_11 -> V_142 =
( F_46 (unsigned int, 48 , c->rect.width >> 4 ) + 3 ) & ~ 3 ;
V_11 -> V_143 =
F_46 (unsigned int, 32 , c->rect.height >> 4 ) ;
}
V_11 -> V_144 = V_11 -> V_28 . V_145 & ~ 3 ;
V_11 -> V_146 = V_11 -> V_28 . V_39 ;
}
static void
F_47 ( struct V_141 * V_11 , unsigned int V_147 )
{
V_11 -> V_28 = V_36 [ V_147 ] . V_37 . V_148 ;
F_45 ( V_11 ) ;
}
static int
F_48 ( struct V_9 * V_10 , unsigned int V_147 )
{
const struct V_34 * V_35 ;
T_5 V_149 ;
F_49 ( V_147 >= V_150 ) ;
F_49 ( V_10 -> V_35 >= V_150 ) ;
V_35 = & V_36 [ V_147 ] ;
if ( memcmp ( & V_36 [ V_10 -> V_35 ] . V_37 , & V_35 -> V_37 ,
sizeof ( V_35 -> V_37 ) ) ) {
F_47 ( & V_10 -> V_26 [ 0 ] , V_147 ) ;
V_10 -> V_26 [ 1 ] = V_10 -> V_26 [ 0 ] ;
if ( 0 == ( V_10 -> V_20 & V_24 ) ) {
V_10 -> V_30 = V_35 -> V_37 . V_38 . V_25
+ V_35 -> V_37 . V_38 . V_39 ;
}
}
V_10 -> V_35 = V_147 ;
F_17 ( V_35 -> V_151 , V_152 ) ;
F_17 ( V_35 -> V_153 , V_154 ) ;
F_29 ( V_35 -> V_155 , ~ ( V_156 | V_157 ) ,
V_101 ) ;
F_17 ( V_35 -> V_158 , V_159 ) ;
F_17 ( 1 , V_160 ) ;
F_25 ( V_10 ) ;
switch ( V_10 -> V_11 . type ) {
case V_113 :
case V_114 :
F_37 ( V_10 , F_50 () ) ;
break;
}
V_149 = V_35 -> V_161 ;
F_51 ( V_10 , V_162 , V_163 , V_149 ) ;
return 0 ;
}
static void
F_52 ( struct V_9 * V_10 , unsigned int V_69 , unsigned int V_147 )
{
unsigned long V_164 ;
V_10 -> V_69 = V_69 ;
if ( V_165 ) {
F_53 ( & V_10 -> V_166 , V_164 ) ;
if ( V_10 -> V_167 . V_168 ) {
V_10 -> V_169 = V_69 ;
} else {
F_31 ( V_10 , V_69 ) ;
}
F_54 ( & V_10 -> V_166 , V_164 ) ;
} else {
F_31 ( V_10 , V_69 ) ;
}
V_10 -> V_119 = ( V_10 -> V_170 != V_171 && V_69 == 0 ) ?
V_135 : V_132 ;
V_119 ( V_10 , V_10 -> V_119 ) ;
F_48 ( V_10 , V_147 ) ;
}
static void F_55 ( struct V_9 * V_10 )
{
F_17 ( 0xfffffUL , V_172 ) ;
if ( V_95 [ V_10 -> V_11 . type ] . V_173 ) {
F_17 ( V_174 ,
V_175 ) ;
} else {
F_17 ( ( V_10 -> V_176 ) |
( V_10 -> V_177 ? V_178 : 0 ) |
V_179 |
( V_180 ? V_181 : 0 ) |
V_182 | V_183 |
V_184 | V_185 |
V_174 ,
V_175 ) ;
}
}
static void F_56 ( struct V_9 * V_10 )
{
if ( V_95 [ V_10 -> V_11 . type ] . V_173 ) {
F_55 ( V_10 ) ;
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
F_57 ( & V_10 -> V_121 ) ;
F_55 ( V_10 ) ;
}
static void F_58 ( struct V_9 * V_10 )
{
unsigned long V_164 ;
if ( V_60 )
F_23 ( L_11 , V_10 -> V_11 . V_58 ) ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
V_10 -> V_199 = 0 ;
F_59 ( V_10 , 0 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
F_56 ( V_10 ) ;
V_10 -> V_54 . V_57 = - 1 ;
F_52 ( V_10 , V_10 -> V_69 , V_10 -> V_35 ) ;
}
static int F_60 ( struct V_117 * V_11 )
{
struct V_9 * V_10 = F_2 ( V_11 -> V_200 , struct V_9 , V_121 ) ;
int V_201 ;
switch ( V_11 -> V_149 ) {
case V_202 :
F_26 ( V_10 , V_11 -> V_201 ) ;
break;
case V_203 :
F_27 ( V_10 , V_11 -> V_201 ) ;
break;
case V_204 :
F_28 ( V_10 , V_11 -> V_201 ) ;
break;
case V_205 :
F_30 ( V_10 , V_11 -> V_201 ) ;
break;
case V_206 :
if ( V_11 -> V_201 ) {
F_33 ( V_207 , V_208 ) ;
F_33 ( V_207 , V_209 ) ;
} else {
F_34 ( ~ V_207 , V_208 ) ;
F_34 ( ~ V_207 , V_209 ) ;
}
break;
case V_122 :
F_40 ( V_10 , V_11 -> V_201 ) ;
V_10 -> V_103 = V_11 -> V_201 ;
break;
case V_210 :
V_10 -> V_211 ( V_10 , V_11 -> V_201 ) ;
break;
case V_212 :
V_201 = V_11 -> V_201 ? V_213 : 0 ;
F_17 ( V_201 , V_208 ) ;
F_17 ( V_201 , V_209 ) ;
break;
case V_214 :
V_10 -> V_215 = V_11 -> V_201 ;
break;
case V_216 :
if ( V_11 -> V_201 ) {
F_34 ( ~ V_217 , V_83 ) ;
F_34 ( ~ V_217 , V_84 ) ;
} else {
F_33 ( V_217 , V_83 ) ;
F_33 ( V_217 , V_84 ) ;
}
break;
case V_218 :
V_10 -> V_108 = V_11 -> V_201 ;
break;
case V_219 :
F_17 ( V_220 |
( V_11 -> V_201 ? V_221 : 0 ) ,
V_222 ) ;
break;
case V_223 :
V_10 -> V_224 = V_11 -> V_201 ;
break;
case V_225 :
F_17 ( V_11 -> V_201 , V_226 ) ;
break;
case V_227 :
F_17 ( V_11 -> V_201 , V_228 ) ;
break;
case V_229 :
V_10 -> V_90 = V_11 -> V_201 ;
F_30 ( V_10 , V_10 -> V_89 ) ;
break;
case V_230 :
F_29 ( ( V_11 -> V_201 << 7 ) , ~ V_231 , V_232 ) ;
break;
case V_233 :
F_29 ( ( V_11 -> V_201 << 5 ) , ~ V_234 , V_232 ) ;
break;
default:
return - V_97 ;
}
return 0 ;
}
void F_39 ( struct V_9 * V_10 , char * V_235 )
{
unsigned int V_236 , V_237 ;
V_236 = F_16 ( V_238 ) ;
V_237 = F_16 ( V_239 ) ;
F_61 ( L_12 ,
V_10 -> V_11 . V_58 , V_236 , V_237 & V_236 , V_237 & ~ V_236 , V_235 ) ;
}
static void F_62 ( struct V_9 * V_10 )
{
int V_240 = 0 ;
if ( V_10 -> V_109 )
V_240 ++ ;
if ( V_240 ) {
F_33 ( V_241 , V_175 ) ;
} else {
F_34 ( ~ V_241 , V_175 ) ;
V_10 -> V_242 = 0 ;
}
}
static const struct V_243 *
F_63 ( int V_244 )
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
F_64 ( struct V_9 * V_10 , struct V_16 * V_17 ,
struct V_247 * V_248 )
{
struct V_247 * V_249 ;
unsigned long V_164 ;
int V_250 = 0 ;
F_22 ( L_13 , V_248 ) ;
if ( V_248 )
V_248 -> V_251 . V_252 = V_253 ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
V_249 = V_10 -> V_254 ;
V_10 -> V_254 = V_248 ;
V_10 -> V_255 |= 1 ;
F_59 ( V_10 , 0x03 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
if ( NULL != V_249 ) {
F_22 ( L_14 ,
V_249 , V_249 -> V_251 . V_252 ) ;
F_65 ( & V_17 -> V_256 , V_10 , V_249 ) ;
F_66 ( V_249 ) ;
}
if ( NULL == V_248 )
F_18 ( V_10 , V_17 , V_257 ) ;
F_22 ( L_15 ) ;
return V_250 ;
}
static int F_67 ( struct V_258 * V_259 , struct V_9 * V_10 ,
struct V_247 * V_5 ,
const struct V_243 * V_260 ,
unsigned int V_145 , unsigned int V_39 ,
enum V_261 V_262 )
{
struct V_16 * V_17 = V_259 -> V_263 ;
int V_264 = 0 ;
struct V_141 V_11 ;
int V_147 ;
int V_265 ;
if ( NULL == V_260 )
return - V_97 ;
if ( V_260 -> V_266 == V_267 ) {
V_145 = V_268 ;
V_39 = V_269 * 2 ;
if ( V_145 * V_39 > V_5 -> V_251 . V_270 )
return - V_97 ;
V_5 -> V_251 . V_271 = V_5 -> V_251 . V_270 ;
V_147 = V_10 -> V_35 ;
if ( V_10 -> V_29 > V_36 [ V_147 ] . V_37 . V_148 . V_25 ) {
return - V_97 ;
}
V_11 . V_28 = V_36 [ V_147 ] . V_37 . V_148 ;
} else {
V_147 = V_10 -> V_35 ;
V_11 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] ;
if ( V_145 < V_11 . V_142 ||
V_145 > V_11 . V_144 ||
V_39 < V_11 . V_143 )
return - V_97 ;
switch ( V_262 ) {
case V_272 :
case V_273 :
case V_274 :
if ( V_39 * 2 > V_11 . V_146 )
return - V_97 ;
break;
default:
if ( V_39 > V_11 . V_146 )
return - V_97 ;
break;
}
V_5 -> V_251 . V_271 = ( V_145 * V_39 * V_260 -> V_275 ) >> 3 ;
if ( 0 != V_5 -> V_251 . V_276 && V_5 -> V_251 . V_270 < V_5 -> V_251 . V_271 )
return - V_97 ;
}
if ( V_5 -> V_251 . V_145 != V_145 || V_5 -> V_251 . V_39 != V_39 ||
V_5 -> V_251 . V_262 != V_262 ||
V_5 -> V_35 != V_147 || V_5 -> V_260 != V_260 ||
V_5 -> V_26 . V_25 != V_11 . V_28 . V_25 ||
V_5 -> V_26 . V_277 != V_11 . V_28 . V_277 ||
V_5 -> V_26 . V_145 != V_11 . V_28 . V_145 ||
V_5 -> V_26 . V_39 != V_11 . V_28 . V_39 ) {
V_5 -> V_251 . V_145 = V_145 ;
V_5 -> V_251 . V_39 = V_39 ;
V_5 -> V_251 . V_262 = V_262 ;
V_5 -> V_35 = V_147 ;
V_5 -> V_260 = V_260 ;
V_5 -> V_26 = V_11 . V_28 ;
V_264 = 1 ;
}
if ( V_278 == V_5 -> V_251 . V_252 ) {
V_264 = 1 ;
if ( 0 != ( V_265 = F_68 ( V_259 , & V_5 -> V_251 , & V_10 -> V_279 ) ) )
goto V_23;
}
if ( V_264 )
if ( 0 != ( V_265 = F_69 ( V_10 , V_5 ) ) )
goto V_23;
V_5 -> V_251 . V_252 = V_280 ;
return 0 ;
V_23:
F_65 ( V_259 , V_10 , V_5 ) ;
return V_265 ;
}
static int
F_70 ( struct V_258 * V_259 , unsigned int * V_281 , unsigned int * V_271 )
{
struct V_16 * V_17 = V_259 -> V_263 ;
* V_271 = V_17 -> V_260 -> V_275 * V_17 -> V_145 * V_17 -> V_39 >> 3 ;
if ( 0 == * V_281 )
* V_281 = V_282 ;
if ( * V_271 * * V_281 > V_282 * V_283 )
* V_281 = ( V_282 * V_283 ) / * V_271 ;
return 0 ;
}
static int
F_71 ( struct V_258 * V_259 , struct V_284 * V_251 ,
enum V_261 V_262 )
{
struct V_247 * V_5 = F_2 ( V_251 , struct V_247 , V_251 ) ;
struct V_16 * V_17 = V_259 -> V_263 ;
return F_67 ( V_259 , V_17 -> V_10 , V_5 , V_17 -> V_260 ,
V_17 -> V_145 , V_17 -> V_39 , V_262 ) ;
}
static void
F_72 ( struct V_258 * V_259 , struct V_284 * V_251 )
{
struct V_247 * V_5 = F_2 ( V_251 , struct V_247 , V_251 ) ;
struct V_16 * V_17 = V_259 -> V_263 ;
struct V_9 * V_10 = V_17 -> V_10 ;
V_5 -> V_251 . V_252 = V_285 ;
F_73 ( & V_5 -> V_251 . V_286 , & V_10 -> V_287 ) ;
if ( ! V_10 -> V_167 . V_168 ) {
V_10 -> V_255 |= 1 ;
F_59 ( V_10 , 0x03 ) ;
}
}
static void F_74 ( struct V_258 * V_259 , struct V_284 * V_251 )
{
struct V_247 * V_5 = F_2 ( V_251 , struct V_247 , V_251 ) ;
struct V_16 * V_17 = V_259 -> V_263 ;
F_65 ( V_259 , V_17 -> V_10 , V_5 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_110 ) {
V_10 -> V_110 = 1 ;
F_51 ( V_10 , V_288 , V_289 ) ;
V_10 -> V_119 = V_126 ;
V_119 ( V_10 , V_10 -> V_119 ) ;
}
}
static int F_76 ( struct V_290 * V_290 , void * V_291 , T_5 V_149 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
unsigned int V_53 ;
int V_292 = 0 ;
for ( V_53 = 0 ; V_53 < V_150 ; V_53 ++ )
if ( V_149 & V_36 [ V_53 ] . V_161 )
break;
if ( V_53 == V_150 ) {
V_292 = - V_97 ;
goto V_292;
}
V_10 -> V_293 = V_149 ;
F_48 ( V_10 , V_53 ) ;
V_292:
return V_292 ;
}
static int F_77 ( struct V_290 * V_290 , void * V_291 , T_5 * V_149 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
* V_149 = V_10 -> V_293 ;
return 0 ;
}
static int F_78 ( struct V_290 * V_290 , void * V_294 , T_5 * V_149 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( F_16 ( V_62 ) & V_295 )
* V_149 &= V_296 ;
else
* V_149 &= V_297 ;
return 0 ;
}
static int F_79 ( struct V_290 * V_290 , void * V_291 ,
struct V_298 * V_53 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_265 = 0 ;
if ( V_53 -> V_299 >= V_95 [ V_10 -> V_11 . type ] . V_96 ) {
V_265 = - V_97 ;
goto V_292;
}
V_53 -> type = V_300 ;
V_53 -> V_301 = 0 ;
if ( V_10 -> V_170 != V_171 && V_53 -> V_299 == 0 ) {
sprintf ( V_53 -> V_302 , L_16 ) ;
V_53 -> type = V_303 ;
V_53 -> V_288 = 0 ;
} else if ( V_53 -> V_299 == V_10 -> V_99 ) {
sprintf ( V_53 -> V_302 , L_17 ) ;
} else {
sprintf ( V_53 -> V_302 , L_18 , V_53 -> V_299 ) ;
}
if ( V_53 -> V_299 == V_10 -> V_69 ) {
T_6 V_304 = F_16 ( V_62 ) ;
if ( 0 == ( V_304 & V_305 ) )
V_53 -> V_306 |= V_307 ;
if ( 0 == ( V_304 & V_107 ) )
V_53 -> V_306 |= V_308 ;
}
V_53 -> V_293 = V_309 ;
V_292:
return V_265 ;
}
static int F_80 ( struct V_290 * V_290 , void * V_291 , unsigned int * V_53 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
* V_53 = V_10 -> V_69 ;
return 0 ;
}
static int F_81 ( struct V_290 * V_290 , void * V_291 , unsigned int V_53 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_53 >= V_95 [ V_10 -> V_11 . type ] . V_96 )
return - V_97 ;
F_52 ( V_10 , V_53 , V_10 -> V_35 ) ;
return 0 ;
}
static int F_82 ( struct V_290 * V_290 , void * V_291 ,
const struct V_310 * V_311 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_311 -> V_299 )
return - V_97 ;
F_51 ( V_10 , V_288 , V_312 , V_311 ) ;
if ( V_10 -> V_313 ) {
struct V_310 V_314 = * V_311 ;
V_10 -> V_313 ( V_10 , & V_314 , 1 ) ;
}
return 0 ;
}
static int F_83 ( struct V_290 * V_290 , void * V_291 ,
struct V_315 * V_294 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_294 -> V_288 )
return - V_97 ;
if ( V_294 -> type == V_316 )
F_75 ( V_10 ) ;
V_294 -> V_317 = V_294 -> type == V_316 ?
V_10 -> V_318 : V_10 -> V_319 ;
return 0 ;
}
static void F_84 ( struct V_9 * V_10 , const struct V_315 * V_294 )
{
struct V_315 V_320 = * V_294 ;
F_51 ( V_10 , V_288 , V_321 , V_294 ) ;
F_51 ( V_10 , V_288 , V_322 , & V_320 ) ;
if ( V_320 . type == V_316 ) {
F_75 ( V_10 ) ;
V_10 -> V_318 = V_320 . V_317 ;
if ( V_10 -> V_323 )
F_85 ( V_10 , V_10 -> V_318 ) ;
} else {
V_10 -> V_319 = V_320 . V_317 ;
}
}
static int F_86 ( struct V_290 * V_290 , void * V_291 ,
const struct V_315 * V_294 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_294 -> V_288 )
return - V_97 ;
F_84 ( V_10 , V_294 ) ;
return 0 ;
}
static int F_87 ( struct V_290 * V_290 , void * V_294 )
{
struct V_6 * V_324 = F_88 ( V_290 ) ;
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
F_89 ( V_324 -> V_121 , V_10 -> V_11 . V_325 . V_302 ) ;
F_51 ( V_10 , V_326 , V_327 ) ;
return 0 ;
}
static int F_90 ( struct V_290 * V_290 , void * V_294 ,
struct V_328 * V_329 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
V_329 -> V_329 &= 0xfff ;
V_329 -> V_201 = F_16 ( V_329 -> V_329 ) ;
V_329 -> V_271 = 1 ;
return 0 ;
}
static int F_91 ( struct V_290 * V_290 , void * V_294 ,
const struct V_328 * V_329 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
F_17 ( V_329 -> V_201 , V_329 -> V_329 & 0xfff ) ;
return 0 ;
}
static void
F_92 ( struct V_141 * V_11 ,
const struct V_330 * V_331 ,
T_2 V_145 ,
T_2 V_39 ,
enum V_261 V_262 )
{
T_2 V_332 = V_39 << ! F_93 ( V_262 ) ;
T_2 V_333 ;
T_2 V_334 ;
if ( V_145 < V_11 -> V_142 ) {
V_11 -> V_28 . V_145 = V_145 * 16 ;
} else if ( V_145 > V_11 -> V_144 ) {
V_11 -> V_28 . V_145 = V_145 ;
V_333 = V_331 -> V_277 + V_331 -> V_145 - V_145 ;
V_333 = F_94 ( V_333 , ( T_2 ) V_335 ) ;
if ( V_11 -> V_28 . V_277 > V_333 )
V_11 -> V_28 . V_277 = V_333 ;
}
if ( V_39 < V_11 -> V_143 ) {
V_11 -> V_28 . V_39 = V_39 * 16 ;
} else if ( V_332 > V_11 -> V_146 ) {
V_11 -> V_28 . V_39 = ( V_332 + 1 ) & ~ 1 ;
V_334 = V_331 -> V_25 + V_331 -> V_39 - V_11 -> V_28 . V_39 ;
if ( V_11 -> V_28 . V_25 > V_334 )
V_11 -> V_28 . V_25 = V_334 ;
}
F_45 ( V_11 ) ;
}
static int
F_95 ( struct V_16 * V_17 ,
T_2 * V_145 ,
T_2 * V_39 ,
enum V_261 V_262 ,
unsigned int V_336 ,
unsigned int V_337 ,
int V_338 ,
int V_339 )
{
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_330 * V_331 ;
struct V_141 * V_11 ;
T_2 V_340 ;
T_2 V_341 ;
T_2 V_342 ;
T_2 V_343 ;
int V_265 ;
F_49 ( ( int ) V_336 >= 0 ||
V_337 >= ( unsigned int ) - V_336 ) ;
V_331 = & V_36 [ V_10 -> V_35 ] . V_37 . V_38 ;
V_11 = & V_10 -> V_26 [ ! ! V_17 -> V_27 ] ;
if ( V_17 -> V_27
&& V_338
&& V_339
&& ! F_13 ( V_10 , V_24 ) ) {
V_340 = 48 ;
V_341 = 32 ;
V_342 = F_96 (unsigned int, b->width, MAX_HACTIVE) ;
V_343 = V_331 -> V_39 ;
if ( V_10 -> V_29 > V_331 -> V_25 ) {
V_343 -= V_10 -> V_29 - V_331 -> V_25 ;
V_265 = - V_344 ;
if ( V_341 > V_343 )
goto V_23;
}
} else {
V_265 = - V_344 ;
if ( V_10 -> V_29 > V_11 -> V_28 . V_25 )
goto V_23;
V_340 = V_11 -> V_142 ;
V_341 = V_11 -> V_143 ;
V_342 = V_11 -> V_144 ;
V_343 = V_11 -> V_146 ;
V_339 = 0 ;
}
V_340 = ( V_340 - V_336 - 1 ) & V_336 ;
V_342 = V_342 & V_336 ;
V_341 = V_341 ;
V_343 >>= ! F_93 ( V_262 ) ;
if ( V_338 ) {
* V_145 = F_97 ( * V_145 , V_340 , V_342 ) ;
* V_39 = F_97 ( * V_39 , V_341 , V_343 ) ;
* V_145 = ( * V_145 + V_337 ) & V_336 ;
if ( V_339 ) {
F_92 ( V_11 , V_331 , * V_145 , * V_39 , V_262 ) ;
if ( V_10 -> V_29 > V_11 -> V_28 . V_25 ) {
V_11 -> V_28 . V_25 = V_10 -> V_29 ;
}
}
} else {
V_265 = - V_97 ;
if ( * V_145 < V_340 ||
* V_39 < V_341 ||
* V_145 > V_342 ||
* V_39 > V_343 ||
0 != ( * V_145 & ~ V_336 ) )
goto V_23;
}
V_265 = 0 ;
V_23:
return V_265 ;
}
static int
F_98 ( struct V_16 * V_17 , struct V_345 * V_346 ,
int V_338 , int V_339 )
{
enum V_261 V_262 ;
unsigned int V_336 ;
int V_265 ;
if ( V_346 -> V_347 . V_145 < 48 )
V_346 -> V_347 . V_145 = 48 ;
if ( V_346 -> V_347 . V_39 < 32 )
V_346 -> V_347 . V_39 = 32 ;
if ( V_346 -> V_348 > 2048 )
V_346 -> V_348 = 2048 ;
V_346 -> V_349 = 0 ;
V_346 -> V_350 = 0 ;
V_262 = V_346 -> V_262 ;
switch ( V_262 ) {
case V_272 :
case V_273 :
case V_351 :
break;
default:
V_262 = V_352 ;
break;
}
if ( V_352 == V_262 ) {
T_2 V_353 ;
V_353 = V_17 -> V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_39 >> 1 ;
V_262 = ( V_346 -> V_347 . V_39 > V_353 )
? V_351
: V_272 ;
}
V_346 -> V_262 = V_262 ;
if ( NULL == V_17 -> V_354 )
return - V_97 ;
V_336 = ~ 0 ;
switch ( V_17 -> V_354 -> V_275 ) {
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
F_99 () ;
}
V_346 -> V_347 . V_145 -= V_346 -> V_347 . V_277 & ~ V_336 ;
V_346 -> V_347 . V_277 = ( V_346 -> V_347 . V_277 - V_336 - 1 ) & V_336 ;
V_265 = F_95 ( V_17 , & V_346 -> V_347 . V_145 , & V_346 -> V_347 . V_39 ,
V_262 , V_336 ,
0 ,
V_338 , V_339 ) ;
if ( 0 != V_265 )
return V_265 ;
return 0 ;
}
static int F_100 ( struct V_16 * V_17 , struct V_9 * V_10 ,
struct V_345 * V_346 , int V_355 )
{
struct V_356 * V_357 = NULL ;
int V_358 , V_271 , V_250 = 0 ;
if ( NULL == V_17 -> V_354 )
return - V_97 ;
if ( ! ( V_17 -> V_354 -> V_164 & V_359 ) )
return - V_97 ;
V_250 = F_98 ( V_17 , V_346 ,
V_355 ,
V_355 ) ;
if ( 0 != V_250 )
return V_250 ;
V_358 = V_346 -> V_348 ;
V_271 = sizeof( * V_357 ) * ( V_358 + 4 ) ;
V_357 = F_101 ( V_271 , V_360 ) ;
if ( NULL == V_357 )
return - V_361 ;
if ( V_358 > 0 ) {
if ( F_102 ( V_357 , V_346 -> V_357 , sizeof( struct V_356 ) * V_358 ) ) {
F_66 ( V_357 ) ;
return - V_362 ;
}
}
if ( NULL != V_10 -> V_279 . V_363 )
V_358 = F_103 ( V_10 -> V_279 . V_260 . V_145 , V_10 -> V_279 . V_260 . V_39 ,
& V_346 -> V_347 , V_357 , V_358 ) ;
F_104 ( V_357 , V_358 ) ;
switch ( V_17 -> V_354 -> V_275 ) {
case 8 :
case 24 :
F_105 ( & V_346 -> V_347 , V_357 , V_358 , 3 ) ;
break;
case 16 :
F_105 ( & V_346 -> V_347 , V_357 , V_358 , 1 ) ;
break;
case 32 :
break;
default:
F_99 () ;
}
F_66 ( V_17 -> V_364 . V_357 ) ;
V_17 -> V_364 . V_357 = V_357 ;
V_17 -> V_364 . V_365 = V_358 ;
V_17 -> V_364 . V_347 = V_346 -> V_347 ;
V_17 -> V_364 . V_262 = V_346 -> V_262 ;
V_17 -> V_364 . V_366 = 1 ;
V_10 -> V_367 . V_364 . V_347 . V_145 = V_346 -> V_347 . V_145 ;
V_10 -> V_367 . V_364 . V_347 . V_39 = V_346 -> V_347 . V_39 ;
V_10 -> V_367 . V_364 . V_262 = V_346 -> V_262 ;
V_250 = 0 ;
if ( F_12 ( V_17 , V_257 ) ) {
struct V_247 * V_248 ;
V_248 = F_106 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_107 ( V_10 , & V_17 -> V_364 , V_17 -> V_354 , V_248 ) ;
V_250 = F_64 ( V_10 , V_17 , V_248 ) ;
}
return V_250 ;
}
static struct V_258 * F_108 ( struct V_16 * V_17 )
{
struct V_258 * V_259 = NULL ;
switch ( V_17 -> type ) {
case V_368 :
V_259 = & V_17 -> V_256 ;
break;
case V_369 :
V_259 = & V_17 -> V_370 ;
break;
default:
F_99 () ;
}
return V_259 ;
}
static int F_109 ( struct V_16 * V_17 )
{
int V_371 = 0 ;
switch ( V_17 -> type ) {
case V_368 :
V_371 = V_22 ;
break;
case V_369 :
V_371 = V_372 ;
break;
default:
F_99 () ;
}
return V_371 ;
}
static int F_110 ( struct V_16 * V_17 , enum V_373 type )
{
struct V_258 * V_259 = F_108 ( V_17 ) ;
int V_371 = F_109 ( V_17 ) ;
if ( F_12 ( V_17 , V_371 ) )
return - V_344 ;
if ( F_111 ( V_259 ) )
return - V_344 ;
V_17 -> type = type ;
return 0 ;
}
static void
F_112 ( struct V_374 * V_294 ,
const struct V_243 * V_260 ,
unsigned int V_145 ,
unsigned int V_39 )
{
V_294 -> V_145 = V_145 ;
V_294 -> V_39 = V_39 ;
if ( V_260 -> V_164 & V_375 ) {
V_294 -> V_376 = V_145 ;
V_294 -> V_377 = ( V_145 * V_39 * V_260 -> V_275 ) >> 3 ;
} else {
V_294 -> V_376 = ( V_145 * V_260 -> V_275 ) >> 3 ;
V_294 -> V_377 = V_39 * V_294 -> V_376 ;
}
}
static int F_113 ( struct V_290 * V_290 , void * V_291 ,
struct V_378 * V_294 )
{
struct V_16 * V_17 = V_291 ;
F_112 ( & V_294 -> V_260 . V_379 , V_17 -> V_260 ,
V_17 -> V_145 , V_17 -> V_39 ) ;
V_294 -> V_260 . V_379 . V_262 = V_17 -> V_256 . V_262 ;
V_294 -> V_260 . V_379 . V_380 = V_17 -> V_260 -> V_244 ;
V_294 -> V_260 . V_379 . V_381 = V_382 ;
return 0 ;
}
static int F_114 ( struct V_290 * V_290 , void * V_291 ,
struct V_378 * V_294 )
{
struct V_16 * V_17 = V_291 ;
V_294 -> V_260 . V_346 . V_347 = V_17 -> V_364 . V_347 ;
V_294 -> V_260 . V_346 . V_262 = V_17 -> V_364 . V_262 ;
return 0 ;
}
static int F_115 ( struct V_290 * V_290 , void * V_291 ,
struct V_378 * V_294 )
{
const struct V_243 * V_260 ;
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
enum V_261 V_262 ;
T_2 V_145 , V_39 ;
T_2 V_353 ;
int V_265 ;
V_260 = F_63 ( V_294 -> V_260 . V_379 . V_380 ) ;
if ( NULL == V_260 )
return - V_97 ;
V_262 = V_294 -> V_260 . V_379 . V_262 ;
switch ( V_262 ) {
case V_272 :
case V_273 :
case V_274 :
case V_351 :
break;
case V_383 :
case V_384 :
if ( ! ( V_260 -> V_164 & V_375 ) ) {
V_262 = V_384 ;
break;
}
default:
V_353 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_39 >> 1 ;
V_262 = ( V_294 -> V_260 . V_379 . V_39 > V_353 )
? V_351
: V_273 ;
break;
}
V_145 = V_294 -> V_260 . V_379 . V_145 ;
V_39 = V_294 -> V_260 . V_379 . V_39 ;
V_265 = F_95 ( V_17 , & V_145 , & V_39 , V_262 ,
~ 3 ,
2 ,
1 ,
0 ) ;
if ( 0 != V_265 )
return V_265 ;
V_294 -> V_260 . V_379 . V_262 = V_262 ;
F_112 ( & V_294 -> V_260 . V_379 , V_260 , V_145 , V_39 ) ;
V_294 -> V_260 . V_379 . V_381 = V_382 ;
return 0 ;
}
static int F_116 ( struct V_290 * V_290 , void * V_291 ,
struct V_378 * V_294 )
{
struct V_16 * V_17 = V_291 ;
F_98 ( V_17 , & V_294 -> V_260 . V_346 ,
1 ,
0 ) ;
return 0 ;
}
static int F_117 ( struct V_290 * V_290 , void * V_291 ,
struct V_378 * V_294 )
{
int V_250 ;
const struct V_243 * V_260 ;
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
T_2 V_145 , V_39 ;
enum V_261 V_262 ;
V_250 = F_110 ( V_17 , V_294 -> type ) ;
if ( 0 != V_250 )
return V_250 ;
V_250 = F_115 ( V_290 , V_291 , V_294 ) ;
if ( 0 != V_250 )
return V_250 ;
V_145 = V_294 -> V_260 . V_379 . V_145 ;
V_39 = V_294 -> V_260 . V_379 . V_39 ;
V_262 = V_294 -> V_260 . V_379 . V_262 ;
V_250 = F_95 ( V_17 , & V_145 , & V_39 , V_294 -> V_260 . V_379 . V_262 ,
~ 3 ,
2 ,
1 ,
1 ) ;
if ( 0 != V_250 )
return V_250 ;
V_294 -> V_260 . V_379 . V_262 = V_262 ;
V_260 = F_63 ( V_294 -> V_260 . V_379 . V_380 ) ;
V_17 -> V_260 = V_260 ;
V_17 -> V_256 . V_262 = V_294 -> V_260 . V_379 . V_262 ;
V_17 -> V_256 . V_385 = V_386 ;
V_17 -> V_145 = V_294 -> V_260 . V_379 . V_145 ;
V_17 -> V_39 = V_294 -> V_260 . V_379 . V_39 ;
V_10 -> V_367 . V_260 = V_260 ;
V_10 -> V_367 . V_145 = V_294 -> V_260 . V_379 . V_145 ;
V_10 -> V_367 . V_39 = V_294 -> V_260 . V_379 . V_39 ;
return 0 ;
}
static int F_118 ( struct V_290 * V_290 , void * V_291 ,
struct V_378 * V_294 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_387 > 0 ) {
F_19 ( L_19 ) ;
return - V_97 ;
}
return F_100 ( V_17 , V_10 , & V_294 -> V_260 . V_346 , 1 ) ;
}
static int F_119 ( struct V_290 * V_290 , void * V_291 ,
struct V_388 * V_256 )
{
struct V_6 * V_324 = F_88 ( V_290 ) ;
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 == V_389 )
return - V_97 ;
F_120 ( V_256 -> V_390 , L_20 , sizeof( V_256 -> V_390 ) ) ;
F_120 ( V_256 -> V_391 , V_10 -> V_392 -> V_302 , sizeof( V_256 -> V_391 ) ) ;
snprintf ( V_256 -> V_393 , sizeof( V_256 -> V_393 ) ,
L_21 , F_121 ( V_10 -> V_11 . V_394 ) ) ;
V_256 -> V_395 =
V_396 |
V_397 |
V_398 |
V_399 ;
if ( V_387 <= 0 )
V_256 -> V_395 |= V_400 ;
if ( V_10 -> V_401 )
V_256 -> V_395 |= V_402 ;
if ( V_10 -> V_403 )
V_256 -> V_395 |= V_404 ;
if ( V_10 -> V_405 )
V_256 -> V_395 |= V_406 ;
if ( V_10 -> V_170 != V_171 )
V_256 -> V_395 |= V_407 ;
if ( V_324 -> V_408 == V_409 )
V_256 -> V_410 = V_256 -> V_395 &
( V_396 |
V_397 |
V_398 |
V_400 |
V_407 ) ;
else if ( V_324 -> V_408 == V_411 )
V_256 -> V_410 = V_256 -> V_395 &
( V_402 |
V_397 |
V_398 |
V_407 ) ;
else {
V_256 -> V_410 = V_404 | V_407 ;
if ( V_10 -> V_405 )
V_256 -> V_410 |= V_397 |
V_406 ;
}
return 0 ;
}
static int F_122 ( struct V_412 * V_294 )
{
int V_299 = - 1 , V_53 ;
for ( V_53 = 0 ; V_53 < V_245 ; V_53 ++ ) {
if ( V_246 [ V_53 ] . V_244 != - 1 )
V_299 ++ ;
if ( ( unsigned int ) V_299 == V_294 -> V_299 )
break;
}
if ( V_245 == V_53 )
return - V_97 ;
V_294 -> V_380 = V_246 [ V_53 ] . V_244 ;
F_120 ( V_294 -> V_413 , V_246 [ V_53 ] . V_302 , sizeof( V_294 -> V_413 ) ) ;
return V_53 ;
}
static int F_123 ( struct V_290 * V_290 , void * V_291 ,
struct V_412 * V_294 )
{
int V_265 = F_122 ( V_294 ) ;
if ( V_265 < 0 )
return V_265 ;
return 0 ;
}
static int F_124 ( struct V_290 * V_290 , void * V_291 ,
struct V_412 * V_294 )
{
int V_265 ;
if ( V_387 > 0 ) {
F_19 ( L_19 ) ;
return - V_97 ;
}
V_265 = F_122 ( V_294 ) ;
if ( V_265 < 0 )
return V_265 ;
if ( ! ( V_246 [ V_265 ] . V_164 & V_359 ) )
return - V_97 ;
return 0 ;
}
static int F_125 ( struct V_290 * V_290 , void * V_294 ,
struct V_414 * V_415 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
* V_415 = V_10 -> V_279 ;
V_415 -> V_416 = V_417 ;
V_415 -> V_164 = V_418 ;
if ( V_17 -> V_354 )
V_415 -> V_260 . V_380 = V_17 -> V_354 -> V_244 ;
return 0 ;
}
static int F_126 ( struct V_290 * V_290 , void * V_294 , unsigned int V_419 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_247 * V_248 ;
int V_250 = 0 ;
if ( V_419 ) {
if ( F_127 ( ! V_10 -> V_279 . V_363 ) ) {
return - V_97 ;
}
if ( F_127 ( ! V_17 -> V_364 . V_366 ) ) {
F_22 ( L_22 , V_10 -> V_11 . V_58 ) ;
V_250 = - V_97 ;
}
if ( V_250 )
return V_250 ;
}
if ( ! F_11 ( V_10 , V_17 , V_257 ) )
return - V_344 ;
if ( V_419 ) {
V_17 -> V_364 . V_35 = V_10 -> V_35 ;
V_248 = F_106 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_107 ( V_10 , & V_17 -> V_364 , V_17 -> V_354 , V_248 ) ;
} else {
V_248 = NULL ;
}
V_250 = F_64 ( V_10 , V_17 , V_248 ) ;
return V_250 ;
}
static int F_128 ( struct V_290 * V_290 , void * V_294 ,
const struct V_414 * V_415 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_243 * V_260 ;
int V_250 ;
if ( ! F_129 ( V_420 ) &&
! F_129 ( V_421 ) )
return - V_422 ;
V_260 = F_63 ( V_415 -> V_260 . V_380 ) ;
if ( NULL == V_260 )
return - V_97 ;
if ( 0 == ( V_260 -> V_164 & V_359 ) )
return - V_97 ;
V_250 = - V_97 ;
if ( V_415 -> V_164 & V_423 ) {
T_2 V_145 = V_415 -> V_260 . V_145 ;
T_2 V_39 = V_415 -> V_260 . V_39 ;
V_250 = F_95 ( V_17 , & V_145 , & V_39 ,
V_351 ,
~ 3 ,
2 ,
0 ,
0 ) ;
if ( 0 != V_250 )
return V_250 ;
}
V_10 -> V_279 . V_363 = V_415 -> V_363 ;
V_10 -> V_279 . V_260 . V_145 = V_415 -> V_260 . V_145 ;
V_10 -> V_279 . V_260 . V_39 = V_415 -> V_260 . V_39 ;
if ( 0 != V_415 -> V_260 . V_376 )
V_10 -> V_279 . V_260 . V_376 = V_415 -> V_260 . V_376 ;
else
V_10 -> V_279 . V_260 . V_376 = V_10 -> V_279 . V_260 . V_145 * V_260 -> V_275 / 8 ;
V_250 = 0 ;
V_17 -> V_354 = V_260 ;
V_10 -> V_367 . V_354 = V_260 ;
if ( V_415 -> V_164 & V_423 ) {
V_17 -> V_364 . V_347 . V_277 = 0 ;
V_17 -> V_364 . V_347 . V_25 = 0 ;
V_17 -> V_364 . V_347 . V_145 = V_415 -> V_260 . V_145 ;
V_17 -> V_364 . V_347 . V_39 = V_415 -> V_260 . V_39 ;
V_10 -> V_367 . V_364 . V_347 . V_145 = V_415 -> V_260 . V_145 ;
V_10 -> V_367 . V_364 . V_347 . V_39 = V_415 -> V_260 . V_39 ;
F_66 ( V_17 -> V_364 . V_357 ) ;
V_17 -> V_364 . V_357 = NULL ;
V_17 -> V_364 . V_365 = 0 ;
if ( F_12 ( V_17 , V_257 ) ) {
struct V_247 * V_248 ;
V_248 = F_106 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_107 ( V_10 , & V_17 -> V_364 , V_17 -> V_354 , V_248 ) ;
V_250 = F_64 ( V_10 , V_17 , V_248 ) ;
}
}
return V_250 ;
}
static int F_130 ( struct V_290 * V_290 , void * V_291 ,
struct V_424 * V_425 )
{
struct V_16 * V_17 = V_291 ;
return F_131 ( F_108 ( V_17 ) , V_425 ) ;
}
static int F_132 ( struct V_290 * V_290 , void * V_291 ,
struct V_426 * V_331 )
{
struct V_16 * V_17 = V_291 ;
return F_133 ( F_108 ( V_17 ) , V_331 ) ;
}
static int F_134 ( struct V_290 * V_290 , void * V_291 , struct V_426 * V_331 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_371 = F_109 ( V_17 ) ;
if ( ! F_11 ( V_10 , V_17 , V_371 ) )
return - V_344 ;
return F_135 ( F_108 ( V_17 ) , V_331 ) ;
}
static int F_136 ( struct V_290 * V_290 , void * V_291 , struct V_426 * V_331 )
{
struct V_16 * V_17 = V_291 ;
return F_137 ( F_108 ( V_17 ) , V_331 ,
V_290 -> V_427 & V_428 ) ;
}
static int F_138 ( struct V_290 * V_290 , void * V_291 ,
enum V_373 type )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_371 = F_109 ( V_17 ) ;
if ( ! F_11 ( V_10 , V_17 , V_371 ) )
return - V_344 ;
return F_139 ( F_108 ( V_17 ) ) ;
}
static int F_140 ( struct V_290 * V_290 , void * V_291 ,
enum V_373 type )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_250 ;
int V_371 = F_109 ( V_17 ) ;
V_250 = F_141 ( F_108 ( V_17 ) ) ;
if ( V_250 < 0 )
return V_250 ;
F_18 ( V_10 , V_17 , V_371 ) ;
return 0 ;
}
static int F_142 ( struct V_290 * V_290 , void * V_294 ,
struct V_429 * V_430 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_430 -> type != V_368 )
return - V_97 ;
V_430 -> V_430 . V_287 . V_431 = V_282 ;
F_143 ( V_36 [ V_10 -> V_35 ] . V_161 ,
& V_430 -> V_430 . V_287 . V_432 ) ;
return 0 ;
}
static int F_144 ( struct V_290 * V_290 , void * V_291 ,
struct V_310 * V_311 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 != V_311 -> V_299 )
return - V_97 ;
V_311 -> V_433 = V_434 ;
V_311 -> V_416 = V_435 ;
F_51 ( V_10 , V_288 , V_436 , V_311 ) ;
strcpy ( V_311 -> V_302 , L_16 ) ;
V_311 -> type = V_437 ;
if ( F_16 ( V_62 ) & V_107 )
V_311 -> signal = 0xffff ;
if ( V_10 -> V_313 )
V_10 -> V_313 ( V_10 , V_311 , 0 ) ;
return 0 ;
}
static int F_145 ( struct V_290 * V_290 , void * V_291 ,
struct V_438 * V_256 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_256 -> type != V_368 &&
V_256 -> type != V_439 )
return - V_97 ;
* V_256 = V_36 [ V_10 -> V_35 ] . V_37 ;
return 0 ;
}
static int F_146 ( struct V_290 * V_290 , void * V_294 , struct V_440 * V_26 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_26 -> type != V_368 &&
V_26 -> type != V_439 )
return - V_97 ;
V_26 -> V_11 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
return 0 ;
}
static int F_147 ( struct V_290 * V_290 , void * V_294 , const struct V_440 * V_26 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_330 * V_331 ;
int V_250 ;
struct V_141 V_11 ;
T_2 V_441 ;
T_2 V_442 ;
T_2 V_443 ;
T_2 V_444 ;
if ( V_26 -> type != V_368 &&
V_26 -> type != V_439 )
return - V_97 ;
V_250 = - V_344 ;
if ( F_13 ( V_17 -> V_10 , V_24 ) ) {
return V_250 ;
}
V_331 = & V_36 [ V_10 -> V_35 ] . V_37 . V_38 ;
V_441 = V_331 -> V_277 ;
V_443 = V_441 + V_331 -> V_145 ;
V_444 = V_331 -> V_25 + V_331 -> V_39 ;
V_442 = F_148 ( V_331 -> V_25 , V_10 -> V_29 ) ;
if ( V_442 + 32 >= V_444 ) {
return V_250 ;
}
V_11 . V_28 . V_277 = F_149 ( V_445 , V_26 -> V_11 . V_277 , V_441 , V_443 - 48 ) ;
V_11 . V_28 . V_277 = F_94 ( V_11 . V_28 . V_277 , ( T_2 ) V_335 ) ;
V_11 . V_28 . V_145 = F_149 ( V_445 , V_26 -> V_11 . V_145 ,
48 , V_443 - V_11 . V_28 . V_277 ) ;
V_11 . V_28 . V_25 = F_149 ( V_445 , V_26 -> V_11 . V_25 , V_442 , V_444 - 32 ) ;
V_11 . V_28 . V_25 = ( V_11 . V_28 . V_25 + 1 ) & ~ 1 ;
V_11 . V_28 . V_39 = F_149 ( V_445 , V_26 -> V_11 . V_39 ,
32 , V_444 - V_11 . V_28 . V_25 ) ;
V_11 . V_28 . V_39 = ( V_11 . V_28 . V_39 + 1 ) & ~ 1 ;
F_45 ( & V_11 ) ;
V_10 -> V_26 [ 1 ] = V_11 ;
V_17 -> V_27 = 1 ;
if ( V_17 -> V_145 < V_11 . V_142 ) {
V_17 -> V_145 = V_11 . V_142 ;
V_10 -> V_367 . V_145 = V_11 . V_142 ;
} else if ( V_17 -> V_145 > V_11 . V_144 ) {
V_17 -> V_145 = V_11 . V_144 ;
V_10 -> V_367 . V_145 = V_11 . V_144 ;
}
if ( V_17 -> V_39 < V_11 . V_143 ) {
V_17 -> V_39 = V_11 . V_143 ;
V_10 -> V_367 . V_39 = V_11 . V_143 ;
} else if ( V_17 -> V_39 > V_11 . V_146 ) {
V_17 -> V_39 = V_11 . V_146 ;
V_10 -> V_367 . V_39 = V_11 . V_146 ;
}
return 0 ;
}
static T_1 F_150 ( struct V_290 * V_290 , char T_7 * V_237 ,
T_8 V_281 , T_9 * V_446 )
{
struct V_16 * V_17 = V_290 -> V_447 ;
int V_250 = 0 ;
if ( V_17 -> V_10 -> V_199 )
F_58 ( V_17 -> V_10 ) ;
F_22 ( L_23 ,
V_17 -> V_10 -> V_11 . V_58 , ( int ) V_281 , V_448 [ V_17 -> type ] ) ;
switch ( V_17 -> type ) {
case V_368 :
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_21 ) ) {
return - V_344 ;
}
V_250 = F_151 ( & V_17 -> V_256 , V_237 , V_281 , V_446 ,
V_290 -> V_427 & V_428 ) ;
F_18 ( V_17 -> V_10 , V_17 , V_21 ) ;
break;
case V_369 :
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_372 ) )
return - V_344 ;
V_250 = F_152 ( & V_17 -> V_370 , V_237 , V_281 , V_446 , 1 ,
V_290 -> V_427 & V_428 ) ;
break;
default:
F_99 () ;
}
return V_250 ;
}
static unsigned int F_153 ( struct V_290 * V_290 , T_10 * V_449 )
{
struct V_16 * V_17 = V_290 -> V_447 ;
struct V_247 * V_5 ;
enum V_261 V_262 ;
unsigned int V_265 = 0 ;
unsigned long V_450 = F_154 ( V_449 ) ;
if ( F_155 ( & V_17 -> V_17 ) )
V_265 = V_451 ;
else if ( V_450 & V_451 )
F_156 ( V_290 , & V_17 -> V_17 . V_449 , V_449 ) ;
if ( ! ( V_450 & ( V_452 | V_453 ) ) )
return V_265 ;
if ( V_369 == V_17 -> type ) {
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_372 ) )
return V_265 | V_454 ;
return V_265 | F_157 ( V_290 , & V_17 -> V_370 , V_449 ) ;
}
if ( F_12 ( V_17 , V_22 ) ) {
if ( F_158 ( & V_17 -> V_256 . V_455 ) )
return V_265 | V_454 ;
V_5 = F_159 ( V_17 -> V_256 . V_455 . V_456 , struct V_247 , V_251 . V_455 ) ;
} else {
if ( NULL == V_17 -> V_256 . V_457 ) {
if ( F_13 ( V_17 -> V_10 , V_22 ) )
return V_265 | V_454 ;
V_17 -> V_256 . V_457 = F_106 ( V_17 -> V_256 . V_458 ) ;
if ( NULL == V_17 -> V_256 . V_457 )
return V_265 | V_454 ;
V_17 -> V_256 . V_457 -> V_459 = V_460 ;
V_262 = F_160 ( & V_17 -> V_256 ) ;
if ( 0 != V_17 -> V_256 . V_461 -> V_462 ( & V_17 -> V_256 , V_17 -> V_256 . V_457 , V_262 ) ) {
F_66 ( V_17 -> V_256 . V_457 ) ;
V_17 -> V_256 . V_457 = NULL ;
return V_265 | V_454 ;
}
V_17 -> V_256 . V_461 -> V_463 ( & V_17 -> V_256 , V_17 -> V_256 . V_457 ) ;
V_17 -> V_256 . V_464 = 0 ;
}
V_5 = (struct V_247 * ) V_17 -> V_256 . V_457 ;
}
F_156 ( V_290 , & V_5 -> V_251 . V_465 , V_449 ) ;
if ( V_5 -> V_251 . V_252 == V_253 ||
V_5 -> V_251 . V_252 == V_466 )
V_265 = V_265 | V_452 | V_453 ;
return V_265 ;
}
static int F_161 ( struct V_290 * V_290 )
{
struct V_6 * V_324 = F_88 ( V_290 ) ;
struct V_9 * V_10 = F_162 ( V_290 ) ;
struct V_16 * V_17 ;
enum V_373 type = 0 ;
F_22 ( L_24 , F_163 ( V_324 ) ) ;
if ( V_324 -> V_408 == V_409 ) {
type = V_368 ;
} else if ( V_324 -> V_408 == V_411 ) {
type = V_369 ;
} else {
F_164 ( 1 ) ;
return - V_467 ;
}
F_22 ( L_25 ,
V_10 -> V_11 . V_58 , V_448 [ type ] ) ;
V_17 = F_101 ( sizeof( * V_17 ) , V_360 ) ;
if ( F_127 ( ! V_17 ) )
return - V_361 ;
V_10 -> V_109 ++ ;
V_290 -> V_447 = V_17 ;
* V_17 = V_10 -> V_367 ;
F_165 ( & V_17 -> V_17 , V_324 ) ;
V_17 -> type = type ;
V_17 -> V_364 . V_366 = 0 ;
F_166 ( & V_17 -> V_256 , & V_468 ,
& V_10 -> V_11 . V_394 -> V_8 , & V_10 -> V_166 ,
V_368 ,
V_351 ,
sizeof( struct V_247 ) ,
V_17 , & V_10 -> V_469 ) ;
F_166 ( & V_17 -> V_370 , & V_470 ,
& V_10 -> V_11 . V_394 -> V_8 , & V_10 -> V_166 ,
V_369 ,
V_384 ,
sizeof( struct V_247 ) ,
V_17 , & V_10 -> V_469 ) ;
F_48 ( V_10 , V_10 -> V_35 ) ;
F_52 ( V_10 , V_10 -> V_69 , V_10 -> V_35 ) ;
F_40 ( V_10 , V_10 -> V_103 ) ;
V_17 -> V_27 = ! V_471 ;
F_167 ( & V_17 -> V_33 , V_10 -> V_35 ) ;
F_62 ( V_10 ) ;
F_168 ( & V_17 -> V_17 ) ;
return 0 ;
}
static int F_169 ( struct V_290 * V_290 )
{
struct V_16 * V_17 = V_290 -> V_447 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( F_12 ( V_17 , V_257 ) )
F_64 ( V_10 , V_17 , NULL ) ;
if ( F_12 ( V_17 , V_22 ) ) {
F_141 ( & V_17 -> V_256 ) ;
F_18 ( V_10 , V_17 , V_22 ) ;
}
if ( V_17 -> V_256 . V_457 ) {
F_74 ( & V_17 -> V_256 , V_17 -> V_256 . V_457 ) ;
F_66 ( V_17 -> V_256 . V_457 ) ;
}
if ( F_12 ( V_17 , V_21 ) ) {
F_18 ( V_10 , V_17 , V_21 ) ;
}
if ( F_12 ( V_17 , V_372 ) ) {
F_170 ( & V_17 -> V_370 ) ;
F_18 ( V_10 , V_17 , V_372 ) ;
}
F_171 ( & V_17 -> V_256 ) ;
F_171 ( & V_17 -> V_370 ) ;
V_290 -> V_447 = NULL ;
V_10 -> V_109 -- ;
F_62 ( V_10 ) ;
if ( ! V_10 -> V_109 )
F_40 ( V_10 , V_10 -> V_103 ) ;
F_172 ( & V_17 -> V_17 ) ;
F_173 ( & V_17 -> V_17 ) ;
F_66 ( V_17 ) ;
return 0 ;
}
static int
F_174 ( struct V_290 * V_290 , struct V_472 * V_473 )
{
struct V_16 * V_17 = V_290 -> V_447 ;
F_22 ( L_26 ,
V_17 -> V_10 -> V_11 . V_58 , V_448 [ V_17 -> type ] ,
V_473 -> V_474 , V_473 -> V_475 - V_473 -> V_474 ) ;
return F_175 ( F_108 ( V_17 ) , V_473 ) ;
}
static int F_176 ( struct V_290 * V_290 )
{
struct V_6 * V_324 = F_88 ( V_290 ) ;
struct V_9 * V_10 = F_162 ( V_290 ) ;
struct V_16 * V_17 ;
F_22 ( L_24 , F_163 ( V_324 ) ) ;
F_22 ( L_27 , V_10 -> V_11 . V_58 ) ;
V_17 = F_101 ( sizeof( * V_17 ) , V_360 ) ;
if ( F_127 ( ! V_17 ) )
return - V_361 ;
V_290 -> V_447 = V_17 ;
* V_17 = V_10 -> V_367 ;
F_165 ( & V_17 -> V_17 , V_324 ) ;
V_10 -> V_476 ++ ;
F_40 ( V_10 , V_10 -> V_103 ) ;
F_168 ( & V_17 -> V_17 ) ;
return 0 ;
}
static int F_177 ( struct V_290 * V_290 )
{
struct V_16 * V_17 = V_290 -> V_447 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_477 V_478 ;
V_290 -> V_447 = NULL ;
F_172 ( & V_17 -> V_17 ) ;
F_173 ( & V_17 -> V_17 ) ;
F_66 ( V_17 ) ;
V_10 -> V_476 -- ;
F_51 ( V_10 , V_326 , V_479 , V_480 , & V_478 ) ;
if ( V_10 -> V_476 == 0 )
V_10 -> V_110 = 0 ;
return 0 ;
}
static int F_178 ( struct V_290 * V_290 , void * V_291 , struct V_310 * V_311 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 != V_311 -> V_299 )
return - V_97 ;
strcpy ( V_311 -> V_302 , L_28 ) ;
V_311 -> type = V_316 ;
F_75 ( V_10 ) ;
F_51 ( V_10 , V_288 , V_436 , V_311 ) ;
if ( V_10 -> V_313 )
V_10 -> V_313 ( V_10 , V_311 , 0 ) ;
return 0 ;
}
static int F_179 ( struct V_290 * V_290 , void * V_291 ,
const struct V_310 * V_311 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 != V_311 -> V_299 )
return - V_97 ;
F_75 ( V_10 ) ;
F_51 ( V_10 , V_288 , V_312 , V_311 ) ;
return 0 ;
}
static T_1 F_180 ( struct V_290 * V_290 , char T_7 * V_237 ,
T_8 V_281 , T_9 * V_446 )
{
struct V_16 * V_17 = V_290 -> V_447 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_477 V_478 ;
V_478 . V_481 = V_281 / 3 ;
V_478 . V_482 = V_290 -> V_427 & V_428 ;
V_478 . V_483 = V_237 ;
V_478 . V_484 = V_290 ;
V_478 . V_485 = - V_467 ;
F_75 ( V_10 ) ;
F_51 ( V_10 , V_326 , V_479 , V_486 , & V_478 ) ;
return V_478 . V_485 ;
}
static unsigned int F_181 ( struct V_290 * V_290 , T_10 * V_449 )
{
struct V_16 * V_17 = V_290 -> V_447 ;
struct V_9 * V_10 = V_17 -> V_10 ;
unsigned long V_450 = F_154 ( V_449 ) ;
struct V_477 V_478 ;
unsigned int V_371 = 0 ;
if ( F_155 ( & V_17 -> V_17 ) )
V_371 = V_451 ;
else if ( V_450 & V_451 )
F_156 ( V_290 , & V_17 -> V_17 . V_449 , V_449 ) ;
F_75 ( V_10 ) ;
V_478 . V_484 = V_290 ;
V_478 . V_487 = V_449 ;
V_478 . V_485 = V_371 ;
F_51 ( V_10 , V_326 , V_479 , V_488 , & V_478 ) ;
return V_478 . V_485 ;
}
static int F_182 ( T_4 V_489 )
{
static char * V_490 [ 16 ] = {
[ V_491 >> 28 ] = L_29 ,
[ V_492 >> 28 ] = L_30 ,
[ V_493 >> 28 ] = L_31 ,
[ V_494 >> 28 ] = L_32 ,
[ V_495 >> 28 ] = L_33 ,
[ V_496 >> 28 ] = L_34 ,
[ V_497 >> 28 ] = L_35 ,
[ V_498 >> 28 ] = L_36 ,
} ;
static int V_499 [ 16 ] = {
[ V_491 >> 28 ] = 2 ,
[ V_494 >> 28 ] = 2 ,
[ V_495 >> 28 ] = 2 ,
[ V_496 >> 28 ] = 5 ,
[ V_497 >> 28 ] = 2 ,
[ V_498 >> 28 ] = 3 ,
} ;
static char * V_44 [] = {
L_37 , L_38 , L_39 , L_40 ,
L_41 , L_42 , L_43 , L_44 ,
L_45 , L_46 , L_47 , L_48 ,
L_49 , L_50 , L_51 , L_52 ,
} ;
int V_53 ;
F_183 ( L_53 , V_489 ,
V_490 [ V_489 >> 28 ] ? V_490 [ V_489 >> 28 ] : L_54 ) ;
for ( V_53 = F_184 ( V_44 ) - 1 ; V_53 >= 0 ; V_53 -- )
if ( V_489 & ( 1 << ( V_53 + 12 ) ) )
F_183 ( L_55 , V_44 [ V_53 ] ) ;
F_183 ( L_56 , V_489 & 0xfff ) ;
return V_499 [ V_489 >> 28 ] ? V_499 [ V_489 >> 28 ] : 1 ;
}
static void F_185 ( struct V_9 * V_10 ,
struct V_500 * V_489 )
{
unsigned int V_53 , V_501 , V_358 ;
F_23 ( L_57 ,
V_10 -> V_11 . V_325 . V_302 , V_489 -> V_502 , ( unsigned long ) V_489 -> V_503 ) ;
for ( V_53 = 0 ; V_53 < ( V_489 -> V_271 >> 2 ) ; V_53 += V_358 ) {
F_23 ( L_58 ,
V_10 -> V_11 . V_325 . V_302 ,
( unsigned long ) ( V_489 -> V_503 + ( V_53 << 2 ) ) ) ;
V_358 = F_182 ( F_186 ( V_489 -> V_502 [ V_53 ] ) ) ;
for ( V_501 = 1 ; V_501 < V_358 ; V_501 ++ )
F_23 ( L_59 ,
V_10 -> V_11 . V_325 . V_302 ,
( unsigned long ) ( V_489 -> V_503 + ( ( V_53 + V_501 ) << 2 ) ) ,
V_489 -> V_502 [ V_53 + V_501 ] , V_501 ) ;
if ( 0 == V_489 -> V_502 [ V_53 ] )
break;
}
}
static void F_187 ( struct V_9 * V_10 )
{
F_23 ( L_60 , ( unsigned long long ) V_10 -> main. V_503 ) ;
F_23 ( L_61 ,
V_10 -> V_504 ? ( unsigned long long ) V_10 -> V_504 -> V_25 . V_503 : 0 ,
V_10 -> V_504 ? ( unsigned long long ) V_10 -> V_504 -> V_505 . V_503 : 0 ) ;
F_23 ( L_62 ,
V_10 -> V_167 . V_25
? ( unsigned long long ) V_10 -> V_167 . V_25 -> V_25 . V_503 : 0 ,
V_10 -> V_167 . V_505
? ( unsigned long long ) V_10 -> V_167 . V_505 -> V_505 . V_503 : 0 ) ;
F_23 ( L_63 ,
V_10 -> V_254 ? ( unsigned long long ) V_10 -> V_254 -> V_25 . V_503 : 0 ,
V_10 -> V_254 ? ( unsigned long long ) V_10 -> V_254 -> V_505 . V_503 : 0 ) ;
F_185 ( V_10 , & V_10 -> main ) ;
}
static void F_188 ( T_4 V_506 , T_4 V_507 )
{
unsigned int V_53 ;
F_183 ( L_64 ) ;
for ( V_53 = 0 ; V_53 < F_184 ( V_508 ) ; V_53 ++ ) {
if ( V_506 & ( 1 << V_53 ) )
F_183 ( L_55 , V_508 [ V_53 ] ) ;
if ( V_507 & ( 1 << V_53 ) )
F_183 ( L_65 ) ;
}
}
static void F_189 ( struct V_9 * V_10 , T_4 V_265 )
{
F_190 ( L_66 ,
V_10 -> V_11 . V_58 ,
( unsigned long ) V_10 -> main. V_503 ,
( unsigned long ) F_186 ( V_10 -> main. V_502 [ V_509 + 1 ] ) ,
( unsigned long ) F_186 ( V_10 -> main. V_502 [ V_510 + 1 ] ) ,
( unsigned long ) V_265 ) ;
if ( 0 == ( F_16 ( V_62 ) & V_107 ) ) {
F_191 ( L_67
L_68 ,
V_10 -> V_11 . V_58 ) ;
return;
}
F_191 ( L_69 ,
V_10 -> V_11 . V_58 ) ;
F_191 ( L_70 ,
V_10 -> V_11 . V_58 ) ;
F_192 () ;
}
static int
F_193 ( struct V_9 * V_10 , struct V_511 * V_512 )
{
struct V_247 * V_513 ;
memset ( V_512 , 0 , sizeof( * V_512 ) ) ;
if ( ! F_158 ( & V_10 -> V_287 ) ) {
V_512 -> V_168 = 1 ;
V_513 = F_159 ( V_10 -> V_287 . V_456 , struct V_247 , V_251 . V_286 ) ;
if ( F_194 ( V_513 -> V_251 . V_262 ) )
V_512 -> V_25 = V_513 ;
if ( F_195 ( V_513 -> V_251 . V_262 ) )
V_512 -> V_505 = V_513 ;
if ( ! F_93 ( V_513 -> V_251 . V_262 ) &&
( V_513 -> V_251 . V_286 . V_456 != & V_10 -> V_287 ) ) {
V_513 = F_159 ( V_513 -> V_251 . V_286 . V_456 , struct V_247 , V_251 . V_286 ) ;
if ( ! F_93 ( V_513 -> V_251 . V_262 ) ) {
if ( NULL == V_512 -> V_505 &&
V_273 == V_513 -> V_251 . V_262 ) {
V_512 -> V_505 = V_513 ;
}
if ( NULL != V_512 -> V_25 && NULL != V_512 -> V_505 )
V_512 -> V_514 = 2 ;
}
}
}
if ( NULL != V_10 -> V_254 ) {
if ( F_93 ( V_10 -> V_254 -> V_251 . V_262 ) ) {
if ( NULL == V_512 -> V_25 && NULL == V_512 -> V_505 ) {
V_512 -> V_25 = V_10 -> V_254 ;
V_512 -> V_505 = V_10 -> V_254 ;
}
} else {
if ( V_272 == V_10 -> V_254 -> V_251 . V_262 &&
NULL == V_512 -> V_25 ) {
V_512 -> V_25 = V_10 -> V_254 ;
}
if ( V_273 == V_10 -> V_254 -> V_251 . V_262 &&
NULL == V_512 -> V_505 ) {
V_512 -> V_505 = V_10 -> V_254 ;
}
}
}
F_22 ( L_71 ,
V_10 -> V_11 . V_58 , V_512 -> V_25 , V_512 -> V_505 ,
V_10 -> V_254 , V_512 -> V_168 , V_512 -> V_514 ) ;
return 0 ;
}
static void
F_196 ( struct V_9 * V_10 , struct V_511 * V_515 ,
struct V_511 * V_167 , unsigned int V_252 )
{
struct V_516 V_517 ;
F_197 ( & V_517 ) ;
if ( V_515 -> V_25 == V_515 -> V_505 ) {
if ( NULL != V_515 -> V_25 && V_167 -> V_25 != V_515 -> V_25 ) {
if ( V_518 > 1 )
F_61 ( L_72 ,
V_10 -> V_11 . V_58 , V_515 -> V_25 ) ;
V_515 -> V_25 -> V_251 . V_517 = V_517 ;
V_515 -> V_25 -> V_251 . V_242 = V_10 -> V_242 ;
V_515 -> V_25 -> V_251 . V_252 = V_252 ;
F_198 ( & V_515 -> V_25 -> V_251 . V_465 ) ;
}
} else {
if ( NULL != V_515 -> V_25 && V_167 -> V_25 != V_515 -> V_25 ) {
if ( V_518 > 1 )
F_61 ( L_73 ,
V_10 -> V_11 . V_58 , V_515 -> V_25 ) ;
V_515 -> V_25 -> V_251 . V_517 = V_517 ;
V_515 -> V_25 -> V_251 . V_242 = V_10 -> V_242 ;
V_515 -> V_25 -> V_251 . V_252 = V_252 ;
F_198 ( & V_515 -> V_25 -> V_251 . V_465 ) ;
}
if ( NULL != V_515 -> V_505 && V_167 -> V_505 != V_515 -> V_505 ) {
if ( V_518 > 1 )
F_61 ( L_74 ,
V_10 -> V_11 . V_58 , V_515 -> V_505 ) ;
V_515 -> V_505 -> V_251 . V_517 = V_517 ;
V_515 -> V_505 -> V_251 . V_242 = V_10 -> V_242 ;
V_515 -> V_505 -> V_251 . V_252 = V_252 ;
F_198 ( & V_515 -> V_505 -> V_251 . V_465 ) ;
}
}
}
static void
F_199 ( struct V_9 * V_10 , struct V_247 * V_515 ,
unsigned int V_252 )
{
struct V_516 V_517 ;
if ( NULL == V_515 )
return;
F_197 ( & V_517 ) ;
V_515 -> V_251 . V_517 = V_517 ;
V_515 -> V_251 . V_242 = V_10 -> V_242 ;
V_515 -> V_251 . V_252 = V_252 ;
F_198 ( & V_515 -> V_251 . V_465 ) ;
}
static void F_200 ( unsigned long V_237 )
{
struct V_9 * V_10 = (struct V_9 * ) V_237 ;
struct V_511 V_249 , V_248 ;
struct V_247 * V_519 ;
struct V_247 * V_513 ;
unsigned long V_164 ;
if ( V_60 ) {
F_23 ( L_75 ,
V_10 -> V_11 . V_58 , V_10 -> V_520 , V_10 -> V_521 , V_10 -> V_522 ,
F_16 ( V_523 ) ) ;
F_188 ( F_16 ( V_172 ) , 0 ) ;
F_183 ( L_76 ) ;
}
F_53 ( & V_10 -> V_166 , V_164 ) ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_249 = V_10 -> V_167 ;
V_519 = V_10 -> V_504 ;
V_10 -> V_167 = V_248 ;
V_10 -> V_504 = NULL ;
V_10 -> V_255 = 0 ;
F_201 ( V_10 , & V_248 ) ;
F_202 ( V_10 , NULL ) ;
F_59 ( V_10 , 0 ) ;
F_196 ( V_10 , & V_249 , & V_248 , V_466 ) ;
F_199 ( V_10 , V_519 , V_466 ) ;
while ( ! F_158 ( & V_10 -> V_287 ) ) {
V_513 = F_159 ( V_10 -> V_287 . V_456 , struct V_247 , V_251 . V_286 ) ;
F_203 ( & V_513 -> V_251 . V_286 ) ;
V_513 -> V_251 . V_252 = V_466 ;
F_198 ( & V_513 -> V_251 . V_465 ) ;
}
while ( ! F_158 ( & V_10 -> V_524 ) ) {
V_513 = F_159 ( V_10 -> V_524 . V_456 , struct V_247 , V_251 . V_286 ) ;
F_203 ( & V_513 -> V_251 . V_286 ) ;
V_513 -> V_251 . V_252 = V_466 ;
F_198 ( & V_513 -> V_251 . V_465 ) ;
}
V_10 -> V_199 ++ ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
}
static void
F_204 ( struct V_9 * V_10 )
{
struct V_247 * V_515 = V_10 -> V_167 . V_25 ;
if ( NULL == V_515 )
return;
F_205 ( & V_10 -> V_166 ) ;
V_10 -> V_167 . V_514 = 0 ;
V_10 -> V_167 . V_25 = NULL ;
F_206 ( V_10 , V_510 , NULL , 0 ) ;
F_197 ( & V_515 -> V_251 . V_517 ) ;
V_515 -> V_251 . V_242 = V_10 -> V_242 ;
V_515 -> V_251 . V_252 = V_253 ;
F_198 ( & V_515 -> V_251 . V_465 ) ;
F_207 ( & V_10 -> V_166 ) ;
}
static inline int F_208 ( struct V_500 * V_489 , T_4 V_265 )
{
if ( V_265 < V_489 -> V_503 )
return 0 ;
if ( V_265 > V_489 -> V_503 + V_489 -> V_271 )
return 0 ;
return 1 ;
}
static void
F_209 ( struct V_9 * V_10 )
{
struct V_511 V_248 ;
struct V_511 V_249 ;
T_11 V_265 ;
F_205 ( & V_10 -> V_166 ) ;
F_193 ( V_10 , & V_248 ) ;
V_265 = F_16 ( V_523 ) ;
if ( ( V_10 -> V_167 . V_25 && F_208 ( & V_10 -> V_167 . V_25 -> V_25 , V_265 ) ) ||
( V_10 -> V_167 . V_505 && F_208 ( & V_10 -> V_167 . V_505 -> V_505 , V_265 ) ) ) {
V_10 -> V_520 ++ ;
if ( V_525 )
F_189 ( V_10 , V_265 ) ;
F_207 ( & V_10 -> V_166 ) ;
return;
}
V_249 = V_10 -> V_167 ;
V_10 -> V_167 = V_248 ;
V_10 -> V_255 &= ~ 1 ;
F_201 ( V_10 , & V_248 ) ;
F_59 ( V_10 , 0 ) ;
if ( V_12 != V_10 -> V_169 ) {
F_31 ( V_10 , V_10 -> V_169 ) ;
V_10 -> V_169 = V_12 ;
}
F_196 ( V_10 , & V_249 , & V_248 , V_253 ) ;
F_207 ( & V_10 -> V_166 ) ;
}
static void
F_210 ( struct V_9 * V_10 )
{
struct V_247 * V_248 = NULL ;
struct V_247 * V_249 ;
T_4 V_265 ;
F_205 ( & V_10 -> V_166 ) ;
if ( ! F_158 ( & V_10 -> V_524 ) )
V_248 = F_159 ( V_10 -> V_524 . V_456 , struct V_247 , V_251 . V_286 ) ;
V_249 = V_10 -> V_504 ;
V_265 = F_16 ( V_523 ) ;
if ( NULL != V_249 && ( F_208 ( & V_249 -> V_25 , V_265 ) ||
F_208 ( & V_249 -> V_505 , V_265 ) ) ) {
V_10 -> V_520 ++ ;
if ( V_525 )
F_189 ( V_10 , V_265 ) ;
F_207 ( & V_10 -> V_166 ) ;
return;
}
V_10 -> V_504 = V_248 ;
V_10 -> V_255 &= ~ 4 ;
F_202 ( V_10 , V_248 ) ;
F_59 ( V_10 , 0 ) ;
F_199 ( V_10 , V_249 , V_253 ) ;
F_207 ( & V_10 -> V_166 ) ;
}
static T_12 F_211 ( int V_526 , void * V_527 )
{
T_4 V_528 , V_529 ;
T_4 V_530 ;
int V_281 ;
struct V_9 * V_10 ;
int V_531 = 0 ;
V_10 = (struct V_9 * ) V_527 ;
V_281 = 0 ;
while ( 1 ) {
V_528 = F_16 ( V_172 ) ;
V_529 = V_528 & F_16 ( V_175 ) ;
if ( ! V_529 )
break;
V_531 = 1 ;
F_17 ( V_528 , V_172 ) ;
V_530 = F_16 ( V_62 ) ;
if ( V_518 ) {
F_61 ( L_77 ,
V_10 -> V_11 . V_58 , V_281 , V_10 -> V_242 ,
V_528 >> 28 , F_16 ( V_523 ) ) ;
F_188 ( V_528 , V_529 ) ;
if ( V_528 & V_185 )
F_183 ( L_78 ,
V_530 & V_107
? L_79 : L_80 ) ;
if ( V_528 & V_532 )
F_183 ( L_81 ,
V_530 & V_305
? L_79 : L_80 ) ;
if ( V_528 & V_184 )
F_183 ( L_82 ,
V_530 & V_295
? L_83 : L_84 ) ;
F_183 ( L_76 ) ;
}
if ( V_529 & V_241 )
V_10 -> V_242 ++ ;
if ( ( V_529 & V_178 ) && V_10 -> V_533 ) {
F_212 ( V_10 ) ;
}
if ( V_529 & V_174 ) {
V_10 -> V_534 = V_528 ;
F_198 ( & V_10 -> V_535 ) ;
}
if ( ( V_529 & V_182 ) && ( V_528 & ( 4 << 28 ) ) )
F_210 ( V_10 ) ;
if ( ( V_529 & V_182 ) && ( V_528 & ( 2 << 28 ) ) )
F_204 ( V_10 ) ;
if ( ( V_529 & V_182 ) && ( V_528 & ( 1 << 28 ) ) )
F_209 ( V_10 ) ;
if ( ( V_529 & V_185 ) && V_10 -> V_108 )
F_36 ( V_10 , V_10 -> V_119 , V_10 -> V_103 ) ;
if ( V_529 & ( V_179 | V_183 ) ) {
F_23 ( L_85 ,
V_10 -> V_11 . V_58 ,
( V_529 & V_179 ) ? L_86 : L_87 ,
( V_529 & V_183 ) ? L_88 : L_87 ,
F_16 ( V_523 ) ) ;
F_188 ( V_528 , V_529 ) ;
F_183 ( L_76 ) ;
if ( V_536 )
F_187 ( V_10 ) ;
}
if ( V_180 && V_529 & V_181 ) {
F_23 ( L_89 ,
V_10 -> V_11 . V_58 , F_16 ( V_523 ) ) ;
if ( V_536 )
F_187 ( V_10 ) ;
}
V_281 ++ ;
if ( V_281 > 4 ) {
if ( V_281 > 8 || ! ( V_529 & V_178 ) ) {
F_17 ( 0 , V_175 ) ;
F_19 ( L_90 ,
V_10 -> V_11 . V_58 ) ;
} else {
F_19 ( L_91 ,
V_10 -> V_11 . V_58 ) ;
F_17 ( F_16 ( V_175 ) & ( - 1 ^ V_178 ) ,
V_175 ) ;
} ;
F_188 ( V_528 , V_529 ) ;
F_183 ( L_92 ) ;
}
}
V_10 -> V_522 ++ ;
if ( V_531 )
V_10 -> V_521 ++ ;
return F_213 ( V_531 ) ;
}
static struct V_6 * F_214 ( struct V_9 * V_10 ,
const struct V_6 * V_537 ,
const char * V_538 )
{
struct V_6 * V_7 ;
V_7 = F_215 () ;
if ( NULL == V_7 )
return NULL ;
* V_7 = * V_537 ;
V_7 -> V_325 = & V_10 -> V_11 . V_325 ;
V_7 -> V_539 = V_540 ;
V_7 -> V_541 = V_536 ;
F_216 ( V_7 , V_10 ) ;
snprintf ( V_7 -> V_302 , sizeof( V_7 -> V_302 ) , L_93 ,
V_10 -> V_149 , ( V_10 -> V_149 == 848 && V_10 -> V_542 == 0x12 ) ? L_94 : L_87 ,
V_538 , V_95 [ V_10 -> V_11 . type ] . V_302 ) ;
if ( V_10 -> V_170 == V_171 ) {
F_217 ( V_7 , V_543 ) ;
F_217 ( V_7 , V_544 ) ;
F_217 ( V_7 , V_545 ) ;
F_217 ( V_7 , V_546 ) ;
}
return V_7 ;
}
static void F_218 ( struct V_9 * V_10 )
{
if ( V_10 -> V_392 ) {
if ( F_219 ( V_10 -> V_392 ) )
F_220 ( V_10 -> V_392 ) ;
else
V_540 ( V_10 -> V_392 ) ;
V_10 -> V_392 = NULL ;
}
if ( V_10 -> V_401 ) {
if ( F_219 ( V_10 -> V_401 ) )
F_220 ( V_10 -> V_401 ) ;
else
V_540 ( V_10 -> V_401 ) ;
V_10 -> V_401 = NULL ;
}
if ( V_10 -> V_403 ) {
if ( F_219 ( V_10 -> V_403 ) )
F_220 ( V_10 -> V_403 ) ;
else
V_540 ( V_10 -> V_403 ) ;
V_10 -> V_403 = NULL ;
}
}
static int F_221 ( struct V_9 * V_10 )
{
if ( V_387 > 0 )
F_191 ( L_95 ) ;
V_10 -> V_392 = F_214 ( V_10 , & V_547 , L_96 ) ;
if ( NULL == V_10 -> V_392 )
goto V_292;
if ( F_222 ( V_10 -> V_392 , V_409 ,
V_548 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_292;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_163 ( V_10 -> V_392 ) ) ;
if ( F_223 ( & V_10 -> V_392 -> V_8 ,
& V_549 ) < 0 ) {
F_19 ( L_98 , V_10 -> V_11 . V_58 ) ;
goto V_292;
}
V_10 -> V_401 = F_214 ( V_10 , & V_547 , L_99 ) ;
if ( NULL == V_10 -> V_401 )
goto V_292;
if ( F_222 ( V_10 -> V_401 , V_411 ,
V_550 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_292;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_163 ( V_10 -> V_401 ) ) ;
if ( ! V_10 -> V_551 )
return 0 ;
V_10 -> V_403 = F_214 ( V_10 , & V_552 , L_100 ) ;
if ( NULL == V_10 -> V_403 )
goto V_292;
V_10 -> V_403 -> V_121 = & V_10 -> V_553 ;
if ( F_222 ( V_10 -> V_403 , V_554 ,
V_555 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_292;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_163 ( V_10 -> V_403 ) ) ;
return 0 ;
V_292:
F_218 ( V_10 ) ;
return - 1 ;
}
static void F_224 ( struct V_556 * V_8 )
{
#if F_225 ( V_557 )
unsigned int V_478 ;
F_226 ( V_8 , V_558 , & V_478 ) ;
V_478 = ( V_478 | V_559 ) ;
F_227 ( V_8 , V_558 , V_478 ) ;
#endif
}
static int F_228 ( struct V_556 * V_8 , const struct V_560 * V_561 )
{
struct V_315 V_562 = {
. V_288 = 0 ,
. type = V_437 ,
. V_317 = 980 ,
} ;
int V_485 ;
unsigned char V_563 ;
struct V_9 * V_10 ;
struct V_564 * V_565 ;
if ( V_566 == V_567 )
return - V_361 ;
F_23 ( L_101 , V_566 ) ;
V_568 [ V_566 ] = V_10 = F_229 ( sizeof( * V_10 ) , V_360 ) ;
if ( V_10 == NULL ) {
F_19 ( L_102 ) ;
return - V_361 ;
}
V_10 -> V_11 . V_58 = V_566 ;
snprintf ( V_10 -> V_11 . V_325 . V_302 , sizeof( V_10 -> V_11 . V_325 . V_302 ) ,
L_103 , V_10 -> V_11 . V_58 ) ;
F_230 ( & V_10 -> V_469 ) ;
F_231 ( & V_10 -> V_166 ) ;
F_231 ( & V_10 -> V_569 ) ;
F_232 ( & V_10 -> V_535 ) ;
F_233 ( & V_10 -> V_11 . V_570 ) ;
F_233 ( & V_10 -> V_287 ) ;
F_233 ( & V_10 -> V_524 ) ;
F_234 ( & V_10 -> V_571 ) ;
V_10 -> V_571 . V_572 = F_200 ;
V_10 -> V_571 . V_237 = ( unsigned long ) V_10 ;
V_10 -> V_573 = - 1 ;
V_10 -> V_170 = V_12 ;
V_10 -> V_169 = V_12 ;
V_10 -> V_551 = V_574 [ V_10 -> V_11 . V_58 ] ;
V_10 -> V_11 . V_394 = V_8 ;
V_10 -> V_149 = V_8 -> V_1 ;
if ( F_235 ( V_8 ) ) {
F_190 ( L_104 , V_10 -> V_11 . V_58 ) ;
return - V_575 ;
}
if ( F_236 ( V_8 , F_237 ( 32 ) ) ) {
F_190 ( L_105 , V_10 -> V_11 . V_58 ) ;
return - V_575 ;
}
if ( ! F_238 ( F_239 ( V_8 , 0 ) ,
F_240 ( V_8 , 0 ) ,
V_10 -> V_11 . V_325 . V_302 ) ) {
F_190 ( L_106 ,
V_10 -> V_11 . V_58 ,
( unsigned long long ) F_239 ( V_8 , 0 ) ) ;
return - V_344 ;
}
F_241 ( V_8 ) ;
F_224 ( V_8 ) ;
V_485 = F_242 ( & V_8 -> V_8 , & V_10 -> V_11 . V_325 ) ;
if ( V_485 < 0 ) {
F_190 ( L_107 , V_10 -> V_11 . V_58 ) ;
goto V_576;
}
V_565 = & V_10 -> V_121 ;
F_243 ( V_565 , 20 ) ;
V_10 -> V_11 . V_325 . V_121 = V_565 ;
F_243 ( & V_10 -> V_553 , 6 ) ;
V_10 -> V_542 = V_8 -> V_542 ;
F_244 ( V_8 , V_577 , & V_563 ) ;
F_23 ( L_108 ,
V_566 , V_10 -> V_149 , V_10 -> V_542 , F_121 ( V_8 ) ,
V_10 -> V_11 . V_394 -> V_526 , V_563 ,
( unsigned long long ) F_239 ( V_8 , 0 ) ) ;
F_245 () ;
V_10 -> V_578 = F_246 ( F_239 ( V_8 , 0 ) , 0x1000 ) ;
if ( NULL == V_10 -> V_578 ) {
F_19 ( L_109 , V_10 -> V_11 . V_58 ) ;
V_485 = - V_575 ;
goto V_579;
}
F_247 ( V_10 ) ;
F_17 ( 0 , V_175 ) ;
V_485 = F_248 ( V_10 -> V_11 . V_394 -> V_526 , F_211 ,
V_580 , V_10 -> V_11 . V_325 . V_302 , ( void * ) V_10 ) ;
if ( V_485 < 0 ) {
F_19 ( L_110 ,
V_566 , V_10 -> V_11 . V_394 -> V_526 ) ;
goto V_579;
}
if ( 0 != F_249 ( V_10 ) ) {
V_485 = - V_575 ;
goto V_581;
}
V_10 -> V_215 = V_582 ;
V_583 . V_584 = V_582 ;
V_585 . V_584 = V_586 ;
V_10 -> V_108 = V_587 ;
V_588 . V_584 = V_587 ;
V_589 . V_584 = V_590 ;
V_10 -> V_224 = V_591 ;
V_592 . V_584 = V_591 ;
V_593 . V_584 = V_594 ;
V_595 . V_584 = V_596 ;
V_10 -> V_90 = V_597 ;
V_598 . V_584 = V_597 ;
V_599 . V_584 = V_600 ;
V_601 . V_584 = V_602 ;
V_10 -> V_367 . V_10 = V_10 ;
V_10 -> V_367 . V_364 . V_347 . V_145 = 320 ;
V_10 -> V_367 . V_364 . V_347 . V_39 = 240 ;
V_10 -> V_367 . V_260 = F_63 ( V_603 ) ;
V_10 -> V_367 . V_145 = 320 ;
V_10 -> V_367 . V_39 = 240 ;
V_10 -> V_367 . V_364 . V_347 . V_145 = 320 ;
V_10 -> V_367 . V_364 . V_347 . V_39 = 240 ;
V_10 -> V_367 . V_364 . V_262 = V_351 ;
V_10 -> V_69 = 0 ;
F_250 ( V_565 , & V_604 ,
V_202 , 0 , 0xff00 , 0x100 , 32768 ) ;
F_250 ( V_565 , & V_604 ,
V_204 , 0 , 0xff80 , 0x80 , 0x6c00 ) ;
F_250 ( V_565 , & V_604 ,
V_205 , 0 , 0xff80 , 0x80 , 32768 ) ;
F_250 ( V_565 , & V_604 ,
V_206 , 0 , 1 , 1 , 0 ) ;
F_250 ( V_565 , & V_604 ,
V_203 , 0 , 0xff00 , 0x100 , 32768 ) ;
F_250 ( V_565 , & V_604 ,
V_212 , 0 , 1 , 1 , ! ! V_605 ) ;
F_250 ( V_565 , & V_604 ,
V_122 , 0 , 1 , 1 , 0 ) ;
if ( V_10 -> V_211 )
F_250 ( V_565 , & V_604 ,
V_210 , 0 , 0xff00 , 0x100 , 0xff00 ) ;
F_251 ( V_565 , & V_583 , NULL ) ;
F_251 ( V_565 , & V_588 , NULL ) ;
F_251 ( V_565 , & V_585 , NULL ) ;
F_251 ( V_565 , & V_589 , NULL ) ;
F_251 ( V_565 , & V_592 , NULL ) ;
F_251 ( V_565 , & V_595 , NULL ) ;
F_251 ( V_565 , & V_593 , NULL ) ;
F_251 ( V_565 , & V_598 , NULL ) ;
F_251 ( V_565 , & V_599 , NULL ) ;
F_251 ( V_565 , & V_601 , NULL ) ;
if ( V_115 )
F_39 ( V_10 , L_111 ) ;
F_252 ( V_10 ) ;
F_56 ( V_10 ) ;
F_17 ( 0x00 , V_606 ) ;
F_17 ( 0x00 , V_238 ) ;
if ( V_60 )
F_39 ( V_10 , L_112 ) ;
F_253 ( V_10 ) ;
F_254 ( V_10 ) ;
F_255 ( V_10 ) ;
F_256 ( V_10 ) ;
if ( V_10 -> V_170 != V_171 ) {
F_84 ( V_10 , & V_562 ) ;
V_10 -> V_318 = 90500 * 16 ;
}
V_10 -> V_293 = V_607 ;
F_55 ( V_10 ) ;
if ( ! V_95 [ V_10 -> V_11 . type ] . V_173 )
F_57 ( V_565 ) ;
if ( V_565 -> error ) {
V_485 = V_565 -> error ;
goto V_581;
}
F_40 ( V_10 , 1 ) ;
if ( ! V_95 [ V_10 -> V_11 . type ] . V_173 ) {
F_257 ( & V_10 -> V_553 , V_565 ,
V_608 ) ;
if ( V_10 -> V_553 . error ) {
V_485 = V_10 -> V_553 . error ;
goto V_581;
}
F_52 ( V_10 , 0 , V_10 -> V_35 ) ;
F_47 ( & V_10 -> V_26 [ 0 ] , V_10 -> V_35 ) ;
V_10 -> V_26 [ 1 ] = V_10 -> V_26 [ 0 ] ;
F_14 ( V_10 ) ;
F_15 ( V_10 ) ;
F_221 ( V_10 ) ;
}
if ( V_95 [ V_10 -> V_11 . type ] . V_609 ) {
F_258 ( & V_10 -> V_11 , L_113 ) ;
F_6 ( V_10 ) ;
}
if ( ! V_610 ) {
F_259 ( V_10 ) ;
F_260 ( V_10 ) ;
}
V_566 ++ ;
return 0 ;
V_581:
F_261 ( V_10 -> V_11 . V_394 -> V_526 , V_10 ) ;
V_579:
F_262 ( & V_10 -> V_121 ) ;
F_262 ( & V_10 -> V_553 ) ;
F_263 ( & V_10 -> V_11 . V_325 ) ;
V_576:
if ( V_10 -> V_578 )
F_264 ( V_10 -> V_578 ) ;
F_265 ( F_239 ( V_10 -> V_11 . V_394 , 0 ) ,
F_240 ( V_10 -> V_11 . V_394 , 0 ) ) ;
return V_485 ;
}
static void F_266 ( struct V_556 * V_556 )
{
struct V_611 * V_325 = F_267 ( V_556 ) ;
struct V_9 * V_10 = F_268 ( V_325 ) ;
if ( V_60 )
F_23 ( L_114 , V_10 -> V_11 . V_58 ) ;
if ( V_95 [ V_10 -> V_11 . type ] . V_609 )
F_9 ( V_10 ) ;
F_34 ( ~ 15 , V_196 ) ;
F_17 ( 0 , V_175 ) ;
F_17 ( ~ 0x0 , V_172 ) ;
F_17 ( 0x0 , V_238 ) ;
if ( V_115 )
F_39 ( V_10 , L_115 ) ;
V_10 -> V_612 = 1 ;
F_269 ( V_10 ) ;
F_270 ( & V_10 -> V_11 ) ;
F_271 ( V_10 ) ;
F_218 ( V_10 ) ;
F_262 ( & V_10 -> V_121 ) ;
F_262 ( & V_10 -> V_553 ) ;
F_272 ( V_10 -> V_11 . V_394 , & V_10 -> main ) ;
F_261 ( V_10 -> V_11 . V_394 -> V_526 , V_10 ) ;
F_264 ( V_10 -> V_578 ) ;
F_265 ( F_239 ( V_10 -> V_11 . V_394 , 0 ) ,
F_240 ( V_10 -> V_11 . V_394 , 0 ) ) ;
F_263 ( & V_10 -> V_11 . V_325 ) ;
V_568 [ V_10 -> V_11 . V_58 ] = NULL ;
F_66 ( V_10 ) ;
return;
}
static int F_273 ( struct V_556 * V_556 , T_13 V_252 )
{
struct V_611 * V_325 = F_267 ( V_556 ) ;
struct V_9 * V_10 = F_268 ( V_325 ) ;
struct V_511 V_613 ;
unsigned long V_164 ;
F_22 ( L_116 , V_10 -> V_11 . V_58 , V_252 . V_614 ) ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
memset ( & V_613 , 0 , sizeof( V_613 ) ) ;
V_10 -> V_252 . V_162 = V_10 -> V_167 ;
V_10 -> V_252 . V_370 = V_10 -> V_504 ;
V_10 -> V_252 . V_255 = V_10 -> V_255 ;
V_10 -> V_167 = V_613 ;
V_10 -> V_255 = 0 ;
F_201 ( V_10 , & V_613 ) ;
F_202 ( V_10 , NULL ) ;
F_59 ( V_10 , 0 ) ;
F_17 ( 0 , V_175 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
V_10 -> V_252 . V_615 = F_16 ( V_238 ) ;
V_10 -> V_252 . V_616 = F_50 () ;
F_274 ( V_556 ) ;
if ( 0 != F_275 ( V_556 , F_276 ( V_556 , V_252 ) ) ) {
F_277 ( V_556 ) ;
V_10 -> V_252 . V_617 = 1 ;
}
return 0 ;
}
static int F_278 ( struct V_556 * V_556 )
{
struct V_611 * V_325 = F_267 ( V_556 ) ;
struct V_9 * V_10 = F_268 ( V_325 ) ;
unsigned long V_164 ;
int V_292 ;
F_22 ( L_117 , V_10 -> V_11 . V_58 ) ;
if ( V_10 -> V_252 . V_617 ) {
V_292 = F_235 ( V_556 ) ;
if ( V_292 ) {
F_190 ( L_104 , V_10 -> V_11 . V_58 ) ;
return V_292 ;
}
V_10 -> V_252 . V_617 = 0 ;
}
V_292 = F_275 ( V_556 , V_618 ) ;
if ( V_292 ) {
F_277 ( V_556 ) ;
F_190 ( L_104 , V_10 -> V_11 . V_58 ) ;
V_10 -> V_252 . V_617 = 1 ;
return V_292 ;
}
F_279 ( V_556 ) ;
F_58 ( V_10 ) ;
F_32 ( 0xffffff , V_10 -> V_252 . V_615 ) ;
F_280 ( V_10 -> V_252 . V_616 ) ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
V_10 -> V_167 = V_10 -> V_252 . V_162 ;
V_10 -> V_504 = V_10 -> V_252 . V_370 ;
V_10 -> V_255 = V_10 -> V_252 . V_255 ;
F_201 ( V_10 , & V_10 -> V_167 ) ;
F_202 ( V_10 , V_10 -> V_504 ) ;
F_59 ( V_10 , 0 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
return 0 ;
}
static int T_14 F_281 ( void )
{
int V_619 ;
V_566 = 0 ;
F_23 ( L_118 , V_620 ) ;
if ( V_282 < 2 || V_282 > V_621 )
V_282 = 2 ;
if ( V_283 > V_622 )
V_283 = V_622 ;
V_283 = ( V_283 + V_623 - 1 ) & V_624 ;
if ( V_60 )
F_23 ( L_119 ,
V_282 , V_283 >> 10 , V_283 >> V_625 ) ;
F_282 () ;
V_619 = F_283 ( & V_626 ) ;
if ( V_619 < 0 ) {
F_190 ( L_120 , V_619 ) ;
return V_619 ;
}
V_619 = F_284 ( & V_627 ) ;
if ( V_619 < 0 )
F_285 ( & V_626 ) ;
return V_619 ;
}
static void T_15 F_286 ( void )
{
F_287 ( & V_627 ) ;
F_285 ( & V_626 ) ;
}
