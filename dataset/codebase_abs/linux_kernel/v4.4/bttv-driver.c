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
F_22 ( L_13 , V_248 ) ;
if ( V_248 )
V_248 -> V_250 . V_251 = V_252 ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
V_249 = V_10 -> V_253 ;
V_10 -> V_253 = V_248 ;
V_10 -> V_254 |= 1 ;
F_59 ( V_10 , 0x03 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
if ( NULL != V_249 ) {
F_22 ( L_14 ,
V_249 , V_249 -> V_250 . V_251 ) ;
F_65 ( & V_17 -> V_255 , V_10 , V_249 ) ;
F_66 ( V_249 ) ;
}
if ( NULL == V_248 )
F_18 ( V_10 , V_17 , V_256 ) ;
F_22 ( L_15 ) ;
return 0 ;
}
static int F_67 ( struct V_257 * V_258 , struct V_9 * V_10 ,
struct V_247 * V_5 ,
const struct V_243 * V_259 ,
unsigned int V_145 , unsigned int V_39 ,
enum V_260 V_261 )
{
struct V_16 * V_17 = V_258 -> V_262 ;
int V_263 = 0 ;
struct V_141 V_11 ;
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
switch ( V_261 ) {
case V_271 :
case V_272 :
case V_273 :
if ( V_39 * 2 > V_11 . V_146 )
return - V_97 ;
break;
default:
if ( V_39 > V_11 . V_146 )
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
V_5 -> V_26 . V_25 != V_11 . V_28 . V_25 ||
V_5 -> V_26 . V_276 != V_11 . V_28 . V_276 ||
V_5 -> V_26 . V_145 != V_11 . V_28 . V_145 ||
V_5 -> V_26 . V_39 != V_11 . V_28 . V_39 ) {
V_5 -> V_250 . V_145 = V_145 ;
V_5 -> V_250 . V_39 = V_39 ;
V_5 -> V_250 . V_261 = V_261 ;
V_5 -> V_35 = V_147 ;
V_5 -> V_259 = V_259 ;
V_5 -> V_26 = V_11 . V_28 ;
V_263 = 1 ;
}
if ( V_277 == V_5 -> V_250 . V_251 ) {
V_263 = 1 ;
if ( 0 != ( V_264 = F_68 ( V_258 , & V_5 -> V_250 , & V_10 -> V_278 ) ) )
goto V_23;
}
if ( V_263 )
if ( 0 != ( V_264 = F_69 ( V_10 , V_5 ) ) )
goto V_23;
V_5 -> V_250 . V_251 = V_279 ;
return 0 ;
V_23:
F_65 ( V_258 , V_10 , V_5 ) ;
return V_264 ;
}
static int
F_70 ( struct V_257 * V_258 , unsigned int * V_280 , unsigned int * V_270 )
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
F_71 ( struct V_257 * V_258 , struct V_283 * V_250 ,
enum V_260 V_261 )
{
struct V_247 * V_5 = F_2 ( V_250 , struct V_247 , V_250 ) ;
struct V_16 * V_17 = V_258 -> V_262 ;
return F_67 ( V_258 , V_17 -> V_10 , V_5 , V_17 -> V_259 ,
V_17 -> V_145 , V_17 -> V_39 , V_261 ) ;
}
static void
F_72 ( struct V_257 * V_258 , struct V_283 * V_250 )
{
struct V_247 * V_5 = F_2 ( V_250 , struct V_247 , V_250 ) ;
struct V_16 * V_17 = V_258 -> V_262 ;
struct V_9 * V_10 = V_17 -> V_10 ;
V_5 -> V_250 . V_251 = V_284 ;
F_73 ( & V_5 -> V_250 . V_285 , & V_10 -> V_286 ) ;
if ( ! V_10 -> V_167 . V_168 ) {
V_10 -> V_254 |= 1 ;
F_59 ( V_10 , 0x03 ) ;
}
}
static void F_74 ( struct V_257 * V_258 , struct V_283 * V_250 )
{
struct V_247 * V_5 = F_2 ( V_250 , struct V_247 , V_250 ) ;
struct V_16 * V_17 = V_258 -> V_262 ;
F_65 ( V_258 , V_17 -> V_10 , V_5 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_110 ) {
V_10 -> V_110 = 1 ;
F_51 ( V_10 , V_287 , V_288 ) ;
V_10 -> V_119 = V_126 ;
V_119 ( V_10 , V_10 -> V_119 ) ;
}
}
static int F_76 ( struct V_289 * V_289 , void * V_290 , T_5 V_149 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
unsigned int V_53 ;
int V_291 = 0 ;
for ( V_53 = 0 ; V_53 < V_150 ; V_53 ++ )
if ( V_149 & V_36 [ V_53 ] . V_161 )
break;
if ( V_53 == V_150 ) {
V_291 = - V_97 ;
goto V_291;
}
V_10 -> V_292 = V_149 ;
F_48 ( V_10 , V_53 ) ;
V_291:
return V_291 ;
}
static int F_77 ( struct V_289 * V_289 , void * V_290 , T_5 * V_149 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
* V_149 = V_10 -> V_292 ;
return 0 ;
}
static int F_78 ( struct V_289 * V_289 , void * V_293 , T_5 * V_149 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( F_16 ( V_62 ) & V_294 )
* V_149 &= V_295 ;
else
* V_149 &= V_296 ;
return 0 ;
}
static int F_79 ( struct V_289 * V_289 , void * V_290 ,
struct V_297 * V_53 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_264 = 0 ;
if ( V_53 -> V_298 >= V_95 [ V_10 -> V_11 . type ] . V_96 ) {
V_264 = - V_97 ;
goto V_291;
}
V_53 -> type = V_299 ;
V_53 -> V_300 = 0 ;
if ( V_10 -> V_170 != V_171 && V_53 -> V_298 == 0 ) {
sprintf ( V_53 -> V_301 , L_16 ) ;
V_53 -> type = V_302 ;
V_53 -> V_287 = 0 ;
} else if ( V_53 -> V_298 == V_10 -> V_99 ) {
sprintf ( V_53 -> V_301 , L_17 ) ;
} else {
sprintf ( V_53 -> V_301 , L_18 , V_53 -> V_298 ) ;
}
if ( V_53 -> V_298 == V_10 -> V_69 ) {
T_6 V_303 = F_16 ( V_62 ) ;
if ( 0 == ( V_303 & V_304 ) )
V_53 -> V_305 |= V_306 ;
if ( 0 == ( V_303 & V_107 ) )
V_53 -> V_305 |= V_307 ;
}
V_53 -> V_292 = V_308 ;
V_291:
return V_264 ;
}
static int F_80 ( struct V_289 * V_289 , void * V_290 , unsigned int * V_53 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
* V_53 = V_10 -> V_69 ;
return 0 ;
}
static int F_81 ( struct V_289 * V_289 , void * V_290 , unsigned int V_53 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_53 >= V_95 [ V_10 -> V_11 . type ] . V_96 )
return - V_97 ;
F_52 ( V_10 , V_53 , V_10 -> V_35 ) ;
return 0 ;
}
static int F_82 ( struct V_289 * V_289 , void * V_290 ,
const struct V_309 * V_310 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_310 -> V_298 )
return - V_97 ;
F_51 ( V_10 , V_287 , V_311 , V_310 ) ;
if ( V_10 -> V_312 ) {
struct V_309 V_313 = * V_310 ;
V_10 -> V_312 ( V_10 , & V_313 , 1 ) ;
}
return 0 ;
}
static int F_83 ( struct V_289 * V_289 , void * V_290 ,
struct V_314 * V_293 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_293 -> V_287 )
return - V_97 ;
if ( V_293 -> type == V_315 )
F_75 ( V_10 ) ;
V_293 -> V_316 = V_293 -> type == V_315 ?
V_10 -> V_317 : V_10 -> V_318 ;
return 0 ;
}
static void F_84 ( struct V_9 * V_10 , const struct V_314 * V_293 )
{
struct V_314 V_319 = * V_293 ;
F_51 ( V_10 , V_287 , V_320 , V_293 ) ;
F_51 ( V_10 , V_287 , V_321 , & V_319 ) ;
if ( V_319 . type == V_315 ) {
F_75 ( V_10 ) ;
V_10 -> V_317 = V_319 . V_316 ;
if ( V_10 -> V_322 ) {
V_10 -> V_323 . V_324 = V_10 -> V_317 ;
F_85 ( & V_10 -> V_323 ) ;
}
} else {
V_10 -> V_318 = V_319 . V_316 ;
}
}
static int F_86 ( struct V_289 * V_289 , void * V_290 ,
const struct V_314 * V_293 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_293 -> V_287 )
return - V_97 ;
F_84 ( V_10 , V_293 ) ;
return 0 ;
}
static int F_87 ( struct V_289 * V_289 , void * V_293 )
{
struct V_6 * V_325 = F_88 ( V_289 ) ;
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
F_89 ( V_325 -> V_121 , V_10 -> V_11 . V_326 . V_301 ) ;
F_51 ( V_10 , V_327 , V_328 ) ;
return 0 ;
}
static int F_90 ( struct V_289 * V_289 , void * V_293 ,
struct V_329 * V_330 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
V_330 -> V_330 &= 0xfff ;
V_330 -> V_201 = F_16 ( V_330 -> V_330 ) ;
V_330 -> V_270 = 1 ;
return 0 ;
}
static int F_91 ( struct V_289 * V_289 , void * V_293 ,
const struct V_329 * V_330 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
F_17 ( V_330 -> V_201 , V_330 -> V_330 & 0xfff ) ;
return 0 ;
}
static void
F_92 ( struct V_141 * V_11 ,
const struct V_331 * V_332 ,
T_2 V_145 ,
T_2 V_39 ,
enum V_260 V_261 )
{
T_2 V_333 = V_39 << ! F_93 ( V_261 ) ;
T_2 V_334 ;
T_2 V_335 ;
if ( V_145 < V_11 -> V_142 ) {
V_11 -> V_28 . V_145 = V_145 * 16 ;
} else if ( V_145 > V_11 -> V_144 ) {
V_11 -> V_28 . V_145 = V_145 ;
V_334 = V_332 -> V_276 + V_332 -> V_145 - V_145 ;
V_334 = F_94 ( V_334 , ( T_2 ) V_336 ) ;
if ( V_11 -> V_28 . V_276 > V_334 )
V_11 -> V_28 . V_276 = V_334 ;
}
if ( V_39 < V_11 -> V_143 ) {
V_11 -> V_28 . V_39 = V_39 * 16 ;
} else if ( V_333 > V_11 -> V_146 ) {
V_11 -> V_28 . V_39 = ( V_333 + 1 ) & ~ 1 ;
V_335 = V_332 -> V_25 + V_332 -> V_39 - V_11 -> V_28 . V_39 ;
if ( V_11 -> V_28 . V_25 > V_335 )
V_11 -> V_28 . V_25 = V_335 ;
}
F_45 ( V_11 ) ;
}
static int
F_95 ( struct V_16 * V_17 ,
T_2 * V_145 ,
T_2 * V_39 ,
enum V_260 V_261 ,
unsigned int V_337 ,
unsigned int V_338 ,
int V_339 ,
int V_340 )
{
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_331 * V_332 ;
struct V_141 * V_11 ;
T_2 V_341 ;
T_2 V_342 ;
T_2 V_343 ;
T_2 V_344 ;
int V_264 ;
F_49 ( ( int ) V_337 >= 0 ||
V_338 >= ( unsigned int ) - V_337 ) ;
V_332 = & V_36 [ V_10 -> V_35 ] . V_37 . V_38 ;
V_11 = & V_10 -> V_26 [ ! ! V_17 -> V_27 ] ;
if ( V_17 -> V_27
&& V_339
&& V_340
&& ! F_13 ( V_10 , V_24 ) ) {
V_341 = 48 ;
V_342 = 32 ;
V_343 = F_96 (unsigned int, b->width, MAX_HACTIVE) ;
V_344 = V_332 -> V_39 ;
if ( V_10 -> V_29 > V_332 -> V_25 ) {
V_344 -= V_10 -> V_29 - V_332 -> V_25 ;
V_264 = - V_345 ;
if ( V_342 > V_344 )
goto V_23;
}
} else {
V_264 = - V_345 ;
if ( V_10 -> V_29 > V_11 -> V_28 . V_25 )
goto V_23;
V_341 = V_11 -> V_142 ;
V_342 = V_11 -> V_143 ;
V_343 = V_11 -> V_144 ;
V_344 = V_11 -> V_146 ;
V_340 = 0 ;
}
V_341 = ( V_341 - V_337 - 1 ) & V_337 ;
V_343 = V_343 & V_337 ;
V_342 = V_342 ;
V_344 >>= ! F_93 ( V_261 ) ;
if ( V_339 ) {
* V_145 = F_97 ( * V_145 , V_341 , V_343 ) ;
* V_39 = F_97 ( * V_39 , V_342 , V_344 ) ;
* V_145 = ( * V_145 + V_338 ) & V_337 ;
if ( V_340 ) {
F_92 ( V_11 , V_332 , * V_145 , * V_39 , V_261 ) ;
if ( V_10 -> V_29 > V_11 -> V_28 . V_25 ) {
V_11 -> V_28 . V_25 = V_10 -> V_29 ;
}
}
} else {
V_264 = - V_97 ;
if ( * V_145 < V_341 ||
* V_39 < V_342 ||
* V_145 > V_343 ||
* V_39 > V_344 ||
0 != ( * V_145 & ~ V_337 ) )
goto V_23;
}
V_264 = 0 ;
V_23:
return V_264 ;
}
static int
F_98 ( struct V_16 * V_17 , struct V_346 * V_347 ,
int V_339 , int V_340 )
{
enum V_260 V_261 ;
unsigned int V_337 ;
int V_264 ;
if ( V_347 -> V_348 . V_145 < 48 )
V_347 -> V_348 . V_145 = 48 ;
if ( V_347 -> V_348 . V_39 < 32 )
V_347 -> V_348 . V_39 = 32 ;
if ( V_347 -> V_349 > 2048 )
V_347 -> V_349 = 2048 ;
V_347 -> V_350 = 0 ;
V_347 -> V_351 = 0 ;
V_261 = V_347 -> V_261 ;
switch ( V_261 ) {
case V_271 :
case V_272 :
case V_352 :
break;
default:
V_261 = V_353 ;
break;
}
if ( V_353 == V_261 ) {
T_2 V_354 ;
V_354 = V_17 -> V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_39 >> 1 ;
V_261 = ( V_347 -> V_348 . V_39 > V_354 )
? V_352
: V_271 ;
}
V_347 -> V_261 = V_261 ;
if ( NULL == V_17 -> V_355 )
return - V_97 ;
V_337 = ~ 0 ;
switch ( V_17 -> V_355 -> V_274 ) {
case 8 :
case 24 :
V_337 = ~ 3 ;
break;
case 16 :
V_337 = ~ 1 ;
break;
case 32 :
break;
default:
F_99 () ;
}
V_347 -> V_348 . V_145 -= V_347 -> V_348 . V_276 & ~ V_337 ;
V_347 -> V_348 . V_276 = ( V_347 -> V_348 . V_276 - V_337 - 1 ) & V_337 ;
V_264 = F_95 ( V_17 , & V_347 -> V_348 . V_145 , & V_347 -> V_348 . V_39 ,
V_261 , V_337 ,
0 ,
V_339 , V_340 ) ;
if ( 0 != V_264 )
return V_264 ;
return 0 ;
}
static int F_100 ( struct V_16 * V_17 , struct V_9 * V_10 ,
struct V_346 * V_347 , int V_356 )
{
struct V_357 * V_358 = NULL ;
int V_359 , V_270 , V_360 = 0 ;
if ( NULL == V_17 -> V_355 )
return - V_97 ;
if ( ! ( V_17 -> V_355 -> V_164 & V_361 ) )
return - V_97 ;
V_360 = F_98 ( V_17 , V_347 ,
V_356 ,
V_356 ) ;
if ( 0 != V_360 )
return V_360 ;
V_359 = V_347 -> V_349 ;
V_270 = sizeof( * V_358 ) * ( V_359 + 4 ) ;
V_358 = F_101 ( V_270 , V_362 ) ;
if ( NULL == V_358 )
return - V_363 ;
if ( V_359 > 0 ) {
if ( F_102 ( V_358 , V_347 -> V_358 , sizeof( struct V_357 ) * V_359 ) ) {
F_66 ( V_358 ) ;
return - V_364 ;
}
}
if ( NULL != V_10 -> V_278 . V_365 )
V_359 = F_103 ( V_10 -> V_278 . V_259 . V_145 , V_10 -> V_278 . V_259 . V_39 ,
& V_347 -> V_348 , V_358 , V_359 ) ;
F_104 ( V_358 , V_359 ) ;
switch ( V_17 -> V_355 -> V_274 ) {
case 8 :
case 24 :
F_105 ( & V_347 -> V_348 , V_358 , V_359 , 3 ) ;
break;
case 16 :
F_105 ( & V_347 -> V_348 , V_358 , V_359 , 1 ) ;
break;
case 32 :
break;
default:
F_99 () ;
}
F_66 ( V_17 -> V_366 . V_358 ) ;
V_17 -> V_366 . V_358 = V_358 ;
V_17 -> V_366 . V_367 = V_359 ;
V_17 -> V_366 . V_348 = V_347 -> V_348 ;
V_17 -> V_366 . V_261 = V_347 -> V_261 ;
V_17 -> V_366 . V_368 = 1 ;
V_10 -> V_369 . V_366 . V_348 . V_145 = V_347 -> V_348 . V_145 ;
V_10 -> V_369 . V_366 . V_348 . V_39 = V_347 -> V_348 . V_39 ;
V_10 -> V_369 . V_366 . V_261 = V_347 -> V_261 ;
V_360 = 0 ;
if ( F_12 ( V_17 , V_256 ) ) {
struct V_247 * V_248 ;
V_248 = F_106 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_107 ( V_10 , & V_17 -> V_366 , V_17 -> V_355 , V_248 ) ;
V_360 = F_64 ( V_10 , V_17 , V_248 ) ;
}
return V_360 ;
}
static struct V_257 * F_108 ( struct V_16 * V_17 )
{
struct V_257 * V_258 = NULL ;
switch ( V_17 -> type ) {
case V_370 :
V_258 = & V_17 -> V_255 ;
break;
case V_371 :
V_258 = & V_17 -> V_372 ;
break;
default:
F_99 () ;
}
return V_258 ;
}
static int F_109 ( struct V_16 * V_17 )
{
int V_373 = 0 ;
switch ( V_17 -> type ) {
case V_370 :
V_373 = V_22 ;
break;
case V_371 :
V_373 = V_374 ;
break;
default:
F_99 () ;
}
return V_373 ;
}
static int F_110 ( struct V_16 * V_17 , enum V_375 type )
{
struct V_257 * V_258 = F_108 ( V_17 ) ;
int V_373 = F_109 ( V_17 ) ;
if ( F_12 ( V_17 , V_373 ) )
return - V_345 ;
if ( F_111 ( V_258 ) )
return - V_345 ;
V_17 -> type = type ;
return 0 ;
}
static void
F_112 ( struct V_376 * V_293 ,
const struct V_243 * V_259 ,
unsigned int V_145 ,
unsigned int V_39 )
{
V_293 -> V_145 = V_145 ;
V_293 -> V_39 = V_39 ;
if ( V_259 -> V_164 & V_377 ) {
V_293 -> V_378 = V_145 ;
V_293 -> V_379 = ( V_145 * V_39 * V_259 -> V_274 ) >> 3 ;
} else {
V_293 -> V_378 = ( V_145 * V_259 -> V_274 ) >> 3 ;
V_293 -> V_379 = V_39 * V_293 -> V_378 ;
}
}
static int F_113 ( struct V_289 * V_289 , void * V_290 ,
struct V_380 * V_293 )
{
struct V_16 * V_17 = V_290 ;
F_112 ( & V_293 -> V_259 . V_381 , V_17 -> V_259 ,
V_17 -> V_145 , V_17 -> V_39 ) ;
V_293 -> V_259 . V_381 . V_261 = V_17 -> V_255 . V_261 ;
V_293 -> V_259 . V_381 . V_382 = V_17 -> V_259 -> V_244 ;
V_293 -> V_259 . V_381 . V_383 = V_384 ;
return 0 ;
}
static int F_114 ( struct V_289 * V_289 , void * V_290 ,
struct V_380 * V_293 )
{
struct V_16 * V_17 = V_290 ;
V_293 -> V_259 . V_347 . V_348 = V_17 -> V_366 . V_348 ;
V_293 -> V_259 . V_347 . V_261 = V_17 -> V_366 . V_261 ;
return 0 ;
}
static int F_115 ( struct V_289 * V_289 , void * V_290 ,
struct V_380 * V_293 )
{
const struct V_243 * V_259 ;
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
enum V_260 V_261 ;
T_2 V_145 , V_39 ;
T_2 V_354 ;
int V_264 ;
V_259 = F_63 ( V_293 -> V_259 . V_381 . V_382 ) ;
if ( NULL == V_259 )
return - V_97 ;
V_261 = V_293 -> V_259 . V_381 . V_261 ;
switch ( V_261 ) {
case V_271 :
case V_272 :
case V_273 :
case V_352 :
break;
case V_385 :
case V_386 :
if ( ! ( V_259 -> V_164 & V_377 ) ) {
V_261 = V_386 ;
break;
}
default:
V_354 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_39 >> 1 ;
V_261 = ( V_293 -> V_259 . V_381 . V_39 > V_354 )
? V_352
: V_272 ;
break;
}
V_145 = V_293 -> V_259 . V_381 . V_145 ;
V_39 = V_293 -> V_259 . V_381 . V_39 ;
V_264 = F_95 ( V_17 , & V_145 , & V_39 , V_261 ,
~ 3 ,
2 ,
1 ,
0 ) ;
if ( 0 != V_264 )
return V_264 ;
V_293 -> V_259 . V_381 . V_261 = V_261 ;
F_112 ( & V_293 -> V_259 . V_381 , V_259 , V_145 , V_39 ) ;
V_293 -> V_259 . V_381 . V_383 = V_384 ;
return 0 ;
}
static int F_116 ( struct V_289 * V_289 , void * V_290 ,
struct V_380 * V_293 )
{
struct V_16 * V_17 = V_290 ;
F_98 ( V_17 , & V_293 -> V_259 . V_347 ,
1 ,
0 ) ;
return 0 ;
}
static int F_117 ( struct V_289 * V_289 , void * V_290 ,
struct V_380 * V_293 )
{
int V_360 ;
const struct V_243 * V_259 ;
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
T_2 V_145 , V_39 ;
enum V_260 V_261 ;
V_360 = F_110 ( V_17 , V_293 -> type ) ;
if ( 0 != V_360 )
return V_360 ;
V_360 = F_115 ( V_289 , V_290 , V_293 ) ;
if ( 0 != V_360 )
return V_360 ;
V_145 = V_293 -> V_259 . V_381 . V_145 ;
V_39 = V_293 -> V_259 . V_381 . V_39 ;
V_261 = V_293 -> V_259 . V_381 . V_261 ;
V_360 = F_95 ( V_17 , & V_145 , & V_39 , V_293 -> V_259 . V_381 . V_261 ,
~ 3 ,
2 ,
1 ,
1 ) ;
if ( 0 != V_360 )
return V_360 ;
V_293 -> V_259 . V_381 . V_261 = V_261 ;
V_259 = F_63 ( V_293 -> V_259 . V_381 . V_382 ) ;
V_17 -> V_259 = V_259 ;
V_17 -> V_255 . V_261 = V_293 -> V_259 . V_381 . V_261 ;
V_17 -> V_255 . V_387 = V_388 ;
V_17 -> V_145 = V_293 -> V_259 . V_381 . V_145 ;
V_17 -> V_39 = V_293 -> V_259 . V_381 . V_39 ;
V_10 -> V_369 . V_259 = V_259 ;
V_10 -> V_369 . V_145 = V_293 -> V_259 . V_381 . V_145 ;
V_10 -> V_369 . V_39 = V_293 -> V_259 . V_381 . V_39 ;
return 0 ;
}
static int F_118 ( struct V_289 * V_289 , void * V_290 ,
struct V_380 * V_293 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_389 > 0 ) {
F_19 ( L_19 ) ;
return - V_97 ;
}
return F_100 ( V_17 , V_10 , & V_293 -> V_259 . V_347 , 1 ) ;
}
static int F_119 ( struct V_289 * V_289 , void * V_290 ,
struct V_390 * V_255 )
{
struct V_6 * V_325 = F_88 ( V_289 ) ;
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 == V_391 )
return - V_97 ;
F_120 ( V_255 -> V_392 , L_20 , sizeof( V_255 -> V_392 ) ) ;
F_120 ( V_255 -> V_393 , V_10 -> V_394 . V_301 , sizeof( V_255 -> V_393 ) ) ;
snprintf ( V_255 -> V_395 , sizeof( V_255 -> V_395 ) ,
L_21 , F_121 ( V_10 -> V_11 . V_396 ) ) ;
V_255 -> V_397 =
V_398 |
V_399 |
V_400 |
V_401 ;
if ( V_389 <= 0 )
V_255 -> V_397 |= V_402 ;
if ( F_122 ( & V_10 -> V_403 ) )
V_255 -> V_397 |= V_404 ;
if ( F_122 ( & V_10 -> V_405 ) )
V_255 -> V_397 |= V_406 ;
if ( V_10 -> V_407 )
V_255 -> V_397 |= V_408 ;
if ( V_10 -> V_170 != V_171 )
V_255 -> V_397 |= V_409 ;
if ( V_325 -> V_410 == V_411 )
V_255 -> V_412 = V_255 -> V_397 &
( V_398 |
V_399 |
V_400 |
V_402 |
V_409 ) ;
else if ( V_325 -> V_410 == V_413 )
V_255 -> V_412 = V_255 -> V_397 &
( V_404 |
V_399 |
V_400 |
V_409 ) ;
else {
V_255 -> V_412 = V_406 | V_409 ;
if ( V_10 -> V_407 )
V_255 -> V_412 |= V_399 |
V_408 ;
if ( V_10 -> V_322 )
V_255 -> V_412 |= V_414 ;
}
return 0 ;
}
static int F_123 ( struct V_415 * V_293 )
{
int V_298 = - 1 , V_53 ;
for ( V_53 = 0 ; V_53 < V_245 ; V_53 ++ ) {
if ( V_246 [ V_53 ] . V_244 != - 1 )
V_298 ++ ;
if ( ( unsigned int ) V_298 == V_293 -> V_298 )
break;
}
if ( V_245 == V_53 )
return - V_97 ;
V_293 -> V_382 = V_246 [ V_53 ] . V_244 ;
F_120 ( V_293 -> V_416 , V_246 [ V_53 ] . V_301 , sizeof( V_293 -> V_416 ) ) ;
return V_53 ;
}
static int F_124 ( struct V_289 * V_289 , void * V_290 ,
struct V_415 * V_293 )
{
int V_264 = F_123 ( V_293 ) ;
if ( V_264 < 0 )
return V_264 ;
return 0 ;
}
static int F_125 ( struct V_289 * V_289 , void * V_290 ,
struct V_415 * V_293 )
{
int V_264 ;
if ( V_389 > 0 ) {
F_19 ( L_19 ) ;
return - V_97 ;
}
V_264 = F_123 ( V_293 ) ;
if ( V_264 < 0 )
return V_264 ;
if ( ! ( V_246 [ V_264 ] . V_164 & V_361 ) )
return - V_97 ;
return 0 ;
}
static int F_126 ( struct V_289 * V_289 , void * V_293 ,
struct V_417 * V_418 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
* V_418 = V_10 -> V_278 ;
V_418 -> V_419 = V_420 ;
V_418 -> V_164 = V_421 ;
if ( V_17 -> V_355 )
V_418 -> V_259 . V_382 = V_17 -> V_355 -> V_244 ;
return 0 ;
}
static int F_127 ( struct V_289 * V_289 , void * V_293 , unsigned int V_422 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_247 * V_248 ;
int V_360 = 0 ;
if ( V_422 ) {
if ( F_128 ( ! V_10 -> V_278 . V_365 ) ) {
return - V_97 ;
}
if ( F_128 ( ! V_17 -> V_366 . V_368 ) ) {
F_22 ( L_22 , V_10 -> V_11 . V_58 ) ;
V_360 = - V_97 ;
}
if ( V_360 )
return V_360 ;
}
if ( ! F_11 ( V_10 , V_17 , V_256 ) )
return - V_345 ;
if ( V_422 ) {
V_17 -> V_366 . V_35 = V_10 -> V_35 ;
V_248 = F_106 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_107 ( V_10 , & V_17 -> V_366 , V_17 -> V_355 , V_248 ) ;
} else {
V_248 = NULL ;
}
V_360 = F_64 ( V_10 , V_17 , V_248 ) ;
return V_360 ;
}
static int F_129 ( struct V_289 * V_289 , void * V_293 ,
const struct V_417 * V_418 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_243 * V_259 ;
int V_360 ;
if ( ! F_130 ( V_423 ) &&
! F_130 ( V_424 ) )
return - V_425 ;
V_259 = F_63 ( V_418 -> V_259 . V_382 ) ;
if ( NULL == V_259 )
return - V_97 ;
if ( 0 == ( V_259 -> V_164 & V_361 ) )
return - V_97 ;
V_360 = - V_97 ;
if ( V_418 -> V_164 & V_426 ) {
T_2 V_145 = V_418 -> V_259 . V_145 ;
T_2 V_39 = V_418 -> V_259 . V_39 ;
V_360 = F_95 ( V_17 , & V_145 , & V_39 ,
V_352 ,
~ 3 ,
2 ,
0 ,
0 ) ;
if ( 0 != V_360 )
return V_360 ;
}
V_10 -> V_278 . V_365 = V_418 -> V_365 ;
V_10 -> V_278 . V_259 . V_145 = V_418 -> V_259 . V_145 ;
V_10 -> V_278 . V_259 . V_39 = V_418 -> V_259 . V_39 ;
if ( 0 != V_418 -> V_259 . V_378 )
V_10 -> V_278 . V_259 . V_378 = V_418 -> V_259 . V_378 ;
else
V_10 -> V_278 . V_259 . V_378 = V_10 -> V_278 . V_259 . V_145 * V_259 -> V_274 / 8 ;
V_360 = 0 ;
V_17 -> V_355 = V_259 ;
V_10 -> V_369 . V_355 = V_259 ;
if ( V_418 -> V_164 & V_426 ) {
V_17 -> V_366 . V_348 . V_276 = 0 ;
V_17 -> V_366 . V_348 . V_25 = 0 ;
V_17 -> V_366 . V_348 . V_145 = V_418 -> V_259 . V_145 ;
V_17 -> V_366 . V_348 . V_39 = V_418 -> V_259 . V_39 ;
V_10 -> V_369 . V_366 . V_348 . V_145 = V_418 -> V_259 . V_145 ;
V_10 -> V_369 . V_366 . V_348 . V_39 = V_418 -> V_259 . V_39 ;
F_66 ( V_17 -> V_366 . V_358 ) ;
V_17 -> V_366 . V_358 = NULL ;
V_17 -> V_366 . V_367 = 0 ;
if ( F_12 ( V_17 , V_256 ) ) {
struct V_247 * V_248 ;
V_248 = F_106 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_107 ( V_10 , & V_17 -> V_366 , V_17 -> V_355 , V_248 ) ;
V_360 = F_64 ( V_10 , V_17 , V_248 ) ;
}
}
return V_360 ;
}
static int F_131 ( struct V_289 * V_289 , void * V_290 ,
struct V_427 * V_428 )
{
struct V_16 * V_17 = V_290 ;
return F_132 ( F_108 ( V_17 ) , V_428 ) ;
}
static int F_133 ( struct V_289 * V_289 , void * V_290 ,
struct V_429 * V_332 )
{
struct V_16 * V_17 = V_290 ;
return F_134 ( F_108 ( V_17 ) , V_332 ) ;
}
static int F_135 ( struct V_289 * V_289 , void * V_290 , struct V_429 * V_332 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_373 = F_109 ( V_17 ) ;
if ( ! F_11 ( V_10 , V_17 , V_373 ) )
return - V_345 ;
return F_136 ( F_108 ( V_17 ) , V_332 ) ;
}
static int F_137 ( struct V_289 * V_289 , void * V_290 , struct V_429 * V_332 )
{
struct V_16 * V_17 = V_290 ;
return F_138 ( F_108 ( V_17 ) , V_332 ,
V_289 -> V_430 & V_431 ) ;
}
static int F_139 ( struct V_289 * V_289 , void * V_290 ,
enum V_375 type )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_373 = F_109 ( V_17 ) ;
if ( ! F_11 ( V_10 , V_17 , V_373 ) )
return - V_345 ;
return F_140 ( F_108 ( V_17 ) ) ;
}
static int F_141 ( struct V_289 * V_289 , void * V_290 ,
enum V_375 type )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_360 ;
int V_373 = F_109 ( V_17 ) ;
V_360 = F_142 ( F_108 ( V_17 ) ) ;
if ( V_360 < 0 )
return V_360 ;
F_18 ( V_10 , V_17 , V_373 ) ;
return 0 ;
}
static int F_143 ( struct V_289 * V_289 , void * V_293 ,
struct V_432 * V_433 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_433 -> type != V_370 )
return - V_97 ;
V_433 -> V_433 . V_286 . V_434 = V_281 ;
F_144 ( V_36 [ V_10 -> V_35 ] . V_161 ,
& V_433 -> V_433 . V_286 . V_435 ) ;
return 0 ;
}
static int F_145 ( struct V_289 * V_289 , void * V_290 ,
struct V_309 * V_310 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 != V_310 -> V_298 )
return - V_97 ;
V_310 -> V_436 = V_437 ;
V_310 -> V_419 = V_438 ;
F_51 ( V_10 , V_287 , V_439 , V_310 ) ;
strcpy ( V_310 -> V_301 , L_16 ) ;
V_310 -> type = V_440 ;
if ( F_16 ( V_62 ) & V_107 )
V_310 -> signal = 0xffff ;
if ( V_10 -> V_312 )
V_10 -> V_312 ( V_10 , V_310 , 0 ) ;
return 0 ;
}
static int F_146 ( struct V_289 * V_289 , void * V_290 ,
struct V_441 * V_255 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_255 -> type != V_370 &&
V_255 -> type != V_442 )
return - V_97 ;
* V_255 = V_36 [ V_10 -> V_35 ] . V_37 ;
return 0 ;
}
static int F_147 ( struct V_289 * V_289 , void * V_293 , struct V_443 * V_26 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_26 -> type != V_370 &&
V_26 -> type != V_442 )
return - V_97 ;
V_26 -> V_11 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
return 0 ;
}
static int F_148 ( struct V_289 * V_289 , void * V_293 , const struct V_443 * V_26 )
{
struct V_16 * V_17 = V_293 ;
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_331 * V_332 ;
int V_360 ;
struct V_141 V_11 ;
T_2 V_444 ;
T_2 V_445 ;
T_2 V_446 ;
T_2 V_447 ;
if ( V_26 -> type != V_370 &&
V_26 -> type != V_442 )
return - V_97 ;
V_360 = - V_345 ;
if ( F_13 ( V_17 -> V_10 , V_24 ) ) {
return V_360 ;
}
V_332 = & V_36 [ V_10 -> V_35 ] . V_37 . V_38 ;
V_444 = V_332 -> V_276 ;
V_446 = V_444 + V_332 -> V_145 ;
V_447 = V_332 -> V_25 + V_332 -> V_39 ;
V_445 = F_149 ( V_332 -> V_25 , V_10 -> V_29 ) ;
if ( V_445 + 32 >= V_447 ) {
return V_360 ;
}
V_11 . V_28 . V_276 = F_150 ( V_448 , V_26 -> V_11 . V_276 , V_444 , V_446 - 48 ) ;
V_11 . V_28 . V_276 = F_94 ( V_11 . V_28 . V_276 , ( T_2 ) V_336 ) ;
V_11 . V_28 . V_145 = F_150 ( V_448 , V_26 -> V_11 . V_145 ,
48 , V_446 - V_11 . V_28 . V_276 ) ;
V_11 . V_28 . V_25 = F_150 ( V_448 , V_26 -> V_11 . V_25 , V_445 , V_447 - 32 ) ;
V_11 . V_28 . V_25 = ( V_11 . V_28 . V_25 + 1 ) & ~ 1 ;
V_11 . V_28 . V_39 = F_150 ( V_448 , V_26 -> V_11 . V_39 ,
32 , V_447 - V_11 . V_28 . V_25 ) ;
V_11 . V_28 . V_39 = ( V_11 . V_28 . V_39 + 1 ) & ~ 1 ;
F_45 ( & V_11 ) ;
V_10 -> V_26 [ 1 ] = V_11 ;
V_17 -> V_27 = 1 ;
if ( V_17 -> V_145 < V_11 . V_142 ) {
V_17 -> V_145 = V_11 . V_142 ;
V_10 -> V_369 . V_145 = V_11 . V_142 ;
} else if ( V_17 -> V_145 > V_11 . V_144 ) {
V_17 -> V_145 = V_11 . V_144 ;
V_10 -> V_369 . V_145 = V_11 . V_144 ;
}
if ( V_17 -> V_39 < V_11 . V_143 ) {
V_17 -> V_39 = V_11 . V_143 ;
V_10 -> V_369 . V_39 = V_11 . V_143 ;
} else if ( V_17 -> V_39 > V_11 . V_146 ) {
V_17 -> V_39 = V_11 . V_146 ;
V_10 -> V_369 . V_39 = V_11 . V_146 ;
}
return 0 ;
}
static T_1 F_151 ( struct V_289 * V_289 , char T_7 * V_237 ,
T_8 V_280 , T_9 * V_449 )
{
struct V_16 * V_17 = V_289 -> V_450 ;
int V_360 = 0 ;
if ( V_17 -> V_10 -> V_199 )
F_58 ( V_17 -> V_10 ) ;
F_22 ( L_23 ,
V_17 -> V_10 -> V_11 . V_58 , ( int ) V_280 , V_451 [ V_17 -> type ] ) ;
switch ( V_17 -> type ) {
case V_370 :
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_21 ) ) {
return - V_345 ;
}
V_360 = F_152 ( & V_17 -> V_255 , V_237 , V_280 , V_449 ,
V_289 -> V_430 & V_431 ) ;
F_18 ( V_17 -> V_10 , V_17 , V_21 ) ;
break;
case V_371 :
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_374 ) )
return - V_345 ;
V_360 = F_153 ( & V_17 -> V_372 , V_237 , V_280 , V_449 , 1 ,
V_289 -> V_430 & V_431 ) ;
break;
default:
F_99 () ;
}
return V_360 ;
}
static unsigned int F_154 ( struct V_289 * V_289 , T_10 * V_452 )
{
struct V_16 * V_17 = V_289 -> V_450 ;
struct V_247 * V_5 ;
enum V_260 V_261 ;
unsigned int V_264 = 0 ;
unsigned long V_453 = F_155 ( V_452 ) ;
if ( F_156 ( & V_17 -> V_17 ) )
V_264 = V_454 ;
else if ( V_453 & V_454 )
F_157 ( V_289 , & V_17 -> V_17 . V_452 , V_452 ) ;
if ( ! ( V_453 & ( V_455 | V_456 ) ) )
return V_264 ;
if ( V_371 == V_17 -> type ) {
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_374 ) )
return V_264 | V_457 ;
return V_264 | F_158 ( V_289 , & V_17 -> V_372 , V_452 ) ;
}
if ( F_12 ( V_17 , V_22 ) ) {
if ( F_159 ( & V_17 -> V_255 . V_458 ) )
return V_264 | V_457 ;
V_5 = F_160 ( V_17 -> V_255 . V_458 . V_459 , struct V_247 , V_250 . V_458 ) ;
} else {
if ( NULL == V_17 -> V_255 . V_460 ) {
if ( F_13 ( V_17 -> V_10 , V_22 ) )
return V_264 | V_457 ;
V_17 -> V_255 . V_460 = F_106 ( V_17 -> V_255 . V_461 ) ;
if ( NULL == V_17 -> V_255 . V_460 )
return V_264 | V_457 ;
V_17 -> V_255 . V_460 -> V_462 = V_463 ;
V_261 = F_161 ( & V_17 -> V_255 ) ;
if ( 0 != V_17 -> V_255 . V_464 -> V_465 ( & V_17 -> V_255 , V_17 -> V_255 . V_460 , V_261 ) ) {
F_66 ( V_17 -> V_255 . V_460 ) ;
V_17 -> V_255 . V_460 = NULL ;
return V_264 | V_457 ;
}
V_17 -> V_255 . V_464 -> V_466 ( & V_17 -> V_255 , V_17 -> V_255 . V_460 ) ;
V_17 -> V_255 . V_467 = 0 ;
}
V_5 = (struct V_247 * ) V_17 -> V_255 . V_460 ;
}
F_157 ( V_289 , & V_5 -> V_250 . V_468 , V_452 ) ;
if ( V_5 -> V_250 . V_251 == V_252 ||
V_5 -> V_250 . V_251 == V_469 )
V_264 = V_264 | V_455 | V_456 ;
return V_264 ;
}
static int F_162 ( struct V_289 * V_289 )
{
struct V_6 * V_325 = F_88 ( V_289 ) ;
struct V_9 * V_10 = F_163 ( V_289 ) ;
struct V_16 * V_17 ;
enum V_375 type = 0 ;
F_22 ( L_24 , F_164 ( V_325 ) ) ;
if ( V_325 -> V_410 == V_411 ) {
type = V_370 ;
} else if ( V_325 -> V_410 == V_413 ) {
type = V_371 ;
} else {
F_165 ( 1 ) ;
return - V_470 ;
}
F_22 ( L_25 ,
V_10 -> V_11 . V_58 , V_451 [ type ] ) ;
V_17 = F_101 ( sizeof( * V_17 ) , V_362 ) ;
if ( F_128 ( ! V_17 ) )
return - V_363 ;
V_10 -> V_109 ++ ;
V_289 -> V_450 = V_17 ;
* V_17 = V_10 -> V_369 ;
F_166 ( & V_17 -> V_17 , V_325 ) ;
V_17 -> type = type ;
V_17 -> V_366 . V_368 = 0 ;
F_167 ( & V_17 -> V_255 , & V_471 ,
& V_10 -> V_11 . V_396 -> V_8 , & V_10 -> V_166 ,
V_370 ,
V_352 ,
sizeof( struct V_247 ) ,
V_17 , & V_10 -> V_472 ) ;
F_167 ( & V_17 -> V_372 , & V_473 ,
& V_10 -> V_11 . V_396 -> V_8 , & V_10 -> V_166 ,
V_371 ,
V_386 ,
sizeof( struct V_247 ) ,
V_17 , & V_10 -> V_472 ) ;
F_48 ( V_10 , V_10 -> V_35 ) ;
F_52 ( V_10 , V_10 -> V_69 , V_10 -> V_35 ) ;
F_40 ( V_10 , V_10 -> V_103 ) ;
V_17 -> V_27 = ! V_474 ;
F_168 ( & V_17 -> V_33 , V_10 -> V_35 ) ;
F_62 ( V_10 ) ;
F_169 ( & V_17 -> V_17 ) ;
return 0 ;
}
static int F_170 ( struct V_289 * V_289 )
{
struct V_16 * V_17 = V_289 -> V_450 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( F_12 ( V_17 , V_256 ) )
F_64 ( V_10 , V_17 , NULL ) ;
if ( F_12 ( V_17 , V_22 ) ) {
F_142 ( & V_17 -> V_255 ) ;
F_18 ( V_10 , V_17 , V_22 ) ;
}
if ( V_17 -> V_255 . V_460 ) {
F_74 ( & V_17 -> V_255 , V_17 -> V_255 . V_460 ) ;
F_66 ( V_17 -> V_255 . V_460 ) ;
}
if ( F_12 ( V_17 , V_21 ) ) {
F_18 ( V_10 , V_17 , V_21 ) ;
}
if ( F_12 ( V_17 , V_374 ) ) {
F_171 ( & V_17 -> V_372 ) ;
F_18 ( V_10 , V_17 , V_374 ) ;
}
F_172 ( & V_17 -> V_255 ) ;
F_172 ( & V_17 -> V_372 ) ;
V_289 -> V_450 = NULL ;
V_10 -> V_109 -- ;
F_62 ( V_10 ) ;
if ( ! V_10 -> V_109 )
F_40 ( V_10 , V_10 -> V_103 ) ;
F_173 ( & V_17 -> V_17 ) ;
F_174 ( & V_17 -> V_17 ) ;
F_66 ( V_17 ) ;
return 0 ;
}
static int
F_175 ( struct V_289 * V_289 , struct V_475 * V_476 )
{
struct V_16 * V_17 = V_289 -> V_450 ;
F_22 ( L_26 ,
V_17 -> V_10 -> V_11 . V_58 , V_451 [ V_17 -> type ] ,
V_476 -> V_477 , V_476 -> V_478 - V_476 -> V_477 ) ;
return F_176 ( F_108 ( V_17 ) , V_476 ) ;
}
static int F_177 ( struct V_289 * V_289 )
{
struct V_6 * V_325 = F_88 ( V_289 ) ;
struct V_9 * V_10 = F_163 ( V_289 ) ;
struct V_16 * V_17 ;
F_22 ( L_24 , F_164 ( V_325 ) ) ;
F_22 ( L_27 , V_10 -> V_11 . V_58 ) ;
V_17 = F_101 ( sizeof( * V_17 ) , V_362 ) ;
if ( F_128 ( ! V_17 ) )
return - V_363 ;
V_289 -> V_450 = V_17 ;
* V_17 = V_10 -> V_369 ;
F_166 ( & V_17 -> V_17 , V_325 ) ;
V_10 -> V_479 ++ ;
F_40 ( V_10 , V_10 -> V_103 ) ;
F_169 ( & V_17 -> V_17 ) ;
return 0 ;
}
static int F_178 ( struct V_289 * V_289 )
{
struct V_16 * V_17 = V_289 -> V_450 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_480 V_481 ;
V_289 -> V_450 = NULL ;
F_173 ( & V_17 -> V_17 ) ;
F_174 ( & V_17 -> V_17 ) ;
F_66 ( V_17 ) ;
V_10 -> V_479 -- ;
F_51 ( V_10 , V_327 , V_482 , V_483 , & V_481 ) ;
if ( V_10 -> V_479 == 0 )
V_10 -> V_110 = 0 ;
return 0 ;
}
static int F_179 ( struct V_289 * V_289 , void * V_290 , struct V_309 * V_310 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 != V_310 -> V_298 )
return - V_97 ;
strcpy ( V_310 -> V_301 , L_28 ) ;
V_310 -> type = V_315 ;
F_75 ( V_10 ) ;
F_51 ( V_10 , V_287 , V_439 , V_310 ) ;
if ( V_10 -> V_312 )
V_10 -> V_312 ( V_10 , V_310 , 0 ) ;
if ( V_10 -> V_322 )
return F_180 ( & V_10 -> V_323 , V_310 ) ;
return 0 ;
}
static int F_181 ( struct V_289 * V_289 , void * V_290 ,
const struct V_309 * V_310 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 != V_310 -> V_298 )
return - V_97 ;
F_75 ( V_10 ) ;
F_51 ( V_10 , V_287 , V_311 , V_310 ) ;
return 0 ;
}
static int F_182 ( struct V_289 * V_289 , void * V_290 ,
const struct V_484 * V_485 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_10 -> V_322 )
return F_183 ( V_289 , & V_10 -> V_323 , V_485 ) ;
return - V_486 ;
}
static int F_184 ( struct V_289 * V_289 , void * V_290 ,
struct V_487 * V_488 )
{
struct V_16 * V_17 = V_290 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_10 -> V_322 )
return F_185 ( & V_10 -> V_323 , V_488 ) ;
return - V_486 ;
}
static T_1 F_186 ( struct V_289 * V_289 , char T_7 * V_237 ,
T_8 V_280 , T_9 * V_449 )
{
struct V_16 * V_17 = V_289 -> V_450 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_480 V_481 ;
V_481 . V_489 = V_280 / 3 ;
V_481 . V_490 = V_289 -> V_430 & V_431 ;
V_481 . V_491 = V_237 ;
V_481 . V_492 = V_289 ;
V_481 . V_493 = - V_470 ;
F_75 ( V_10 ) ;
F_51 ( V_10 , V_327 , V_482 , V_494 , & V_481 ) ;
return V_481 . V_493 ;
}
static unsigned int F_187 ( struct V_289 * V_289 , T_10 * V_452 )
{
struct V_16 * V_17 = V_289 -> V_450 ;
struct V_9 * V_10 = V_17 -> V_10 ;
unsigned long V_453 = F_155 ( V_452 ) ;
struct V_480 V_481 ;
unsigned int V_373 = 0 ;
if ( F_156 ( & V_17 -> V_17 ) )
V_373 = V_454 ;
else if ( V_453 & V_454 )
F_157 ( V_289 , & V_17 -> V_17 . V_452 , V_452 ) ;
F_75 ( V_10 ) ;
V_481 . V_492 = V_289 ;
V_481 . V_495 = V_452 ;
V_481 . V_493 = V_373 ;
F_51 ( V_10 , V_327 , V_482 , V_496 , & V_481 ) ;
return V_481 . V_493 ;
}
static int F_188 ( T_4 V_497 )
{
static char * V_498 [ 16 ] = {
[ V_499 >> 28 ] = L_29 ,
[ V_500 >> 28 ] = L_30 ,
[ V_501 >> 28 ] = L_31 ,
[ V_502 >> 28 ] = L_32 ,
[ V_503 >> 28 ] = L_33 ,
[ V_504 >> 28 ] = L_34 ,
[ V_505 >> 28 ] = L_35 ,
[ V_506 >> 28 ] = L_36 ,
} ;
static int V_507 [ 16 ] = {
[ V_499 >> 28 ] = 2 ,
[ V_502 >> 28 ] = 2 ,
[ V_503 >> 28 ] = 2 ,
[ V_504 >> 28 ] = 5 ,
[ V_505 >> 28 ] = 2 ,
[ V_506 >> 28 ] = 3 ,
} ;
static char * V_44 [] = {
L_37 , L_38 , L_39 , L_40 ,
L_41 , L_42 , L_43 , L_44 ,
L_45 , L_46 , L_47 , L_48 ,
L_49 , L_50 , L_51 , L_52 ,
} ;
int V_53 ;
F_189 ( L_53 , V_497 ,
V_498 [ V_497 >> 28 ] ? V_498 [ V_497 >> 28 ] : L_54 ) ;
for ( V_53 = F_190 ( V_44 ) - 1 ; V_53 >= 0 ; V_53 -- )
if ( V_497 & ( 1 << ( V_53 + 12 ) ) )
F_189 ( L_55 , V_44 [ V_53 ] ) ;
F_189 ( L_56 , V_497 & 0xfff ) ;
return V_507 [ V_497 >> 28 ] ? V_507 [ V_497 >> 28 ] : 1 ;
}
static void F_191 ( struct V_9 * V_10 ,
struct V_508 * V_497 )
{
unsigned int V_53 , V_509 , V_359 ;
F_23 ( L_57 ,
V_10 -> V_11 . V_326 . V_301 , V_497 -> V_510 , ( unsigned long ) V_497 -> V_511 ) ;
for ( V_53 = 0 ; V_53 < ( V_497 -> V_270 >> 2 ) ; V_53 += V_359 ) {
F_23 ( L_58 ,
V_10 -> V_11 . V_326 . V_301 ,
( unsigned long ) ( V_497 -> V_511 + ( V_53 << 2 ) ) ) ;
V_359 = F_188 ( F_192 ( V_497 -> V_510 [ V_53 ] ) ) ;
for ( V_509 = 1 ; V_509 < V_359 ; V_509 ++ )
F_23 ( L_59 ,
V_10 -> V_11 . V_326 . V_301 ,
( unsigned long ) ( V_497 -> V_511 + ( ( V_53 + V_509 ) << 2 ) ) ,
V_497 -> V_510 [ V_53 + V_509 ] , V_509 ) ;
if ( 0 == V_497 -> V_510 [ V_53 ] )
break;
}
}
static void F_193 ( struct V_9 * V_10 )
{
F_23 ( L_60 , ( unsigned long long ) V_10 -> main. V_511 ) ;
F_23 ( L_61 ,
V_10 -> V_512 ? ( unsigned long long ) V_10 -> V_512 -> V_25 . V_511 : 0 ,
V_10 -> V_512 ? ( unsigned long long ) V_10 -> V_512 -> V_513 . V_511 : 0 ) ;
F_23 ( L_62 ,
V_10 -> V_167 . V_25
? ( unsigned long long ) V_10 -> V_167 . V_25 -> V_25 . V_511 : 0 ,
V_10 -> V_167 . V_513
? ( unsigned long long ) V_10 -> V_167 . V_513 -> V_513 . V_511 : 0 ) ;
F_23 ( L_63 ,
V_10 -> V_253 ? ( unsigned long long ) V_10 -> V_253 -> V_25 . V_511 : 0 ,
V_10 -> V_253 ? ( unsigned long long ) V_10 -> V_253 -> V_513 . V_511 : 0 ) ;
F_191 ( V_10 , & V_10 -> main ) ;
}
static void F_194 ( T_4 V_514 , T_4 V_515 )
{
unsigned int V_53 ;
F_189 ( L_64 ) ;
for ( V_53 = 0 ; V_53 < F_190 ( V_516 ) ; V_53 ++ ) {
if ( V_514 & ( 1 << V_53 ) )
F_189 ( L_55 , V_516 [ V_53 ] ) ;
if ( V_515 & ( 1 << V_53 ) )
F_189 ( L_65 ) ;
}
}
static void F_195 ( struct V_9 * V_10 , T_4 V_264 )
{
F_196 ( L_66 ,
V_10 -> V_11 . V_58 ,
( unsigned long ) V_10 -> main. V_511 ,
( unsigned long ) F_192 ( V_10 -> main. V_510 [ V_517 + 1 ] ) ,
( unsigned long ) F_192 ( V_10 -> main. V_510 [ V_518 + 1 ] ) ,
( unsigned long ) V_264 ) ;
if ( 0 == ( F_16 ( V_62 ) & V_107 ) ) {
F_197 ( L_67
L_68 ,
V_10 -> V_11 . V_58 ) ;
return;
}
F_197 ( L_69 ,
V_10 -> V_11 . V_58 ) ;
F_197 ( L_70 ,
V_10 -> V_11 . V_58 ) ;
F_198 () ;
}
static int
F_199 ( struct V_9 * V_10 , struct V_519 * V_520 )
{
struct V_247 * V_521 ;
memset ( V_520 , 0 , sizeof( * V_520 ) ) ;
if ( ! F_159 ( & V_10 -> V_286 ) ) {
V_520 -> V_168 = 1 ;
V_521 = F_160 ( V_10 -> V_286 . V_459 , struct V_247 , V_250 . V_285 ) ;
if ( F_200 ( V_521 -> V_250 . V_261 ) )
V_520 -> V_25 = V_521 ;
if ( F_201 ( V_521 -> V_250 . V_261 ) )
V_520 -> V_513 = V_521 ;
if ( ! F_93 ( V_521 -> V_250 . V_261 ) &&
( V_521 -> V_250 . V_285 . V_459 != & V_10 -> V_286 ) ) {
V_521 = F_160 ( V_521 -> V_250 . V_285 . V_459 , struct V_247 , V_250 . V_285 ) ;
if ( ! F_93 ( V_521 -> V_250 . V_261 ) ) {
if ( NULL == V_520 -> V_513 &&
V_272 == V_521 -> V_250 . V_261 ) {
V_520 -> V_513 = V_521 ;
}
if ( NULL != V_520 -> V_25 && NULL != V_520 -> V_513 )
V_520 -> V_522 = 2 ;
}
}
}
if ( NULL != V_10 -> V_253 ) {
if ( F_93 ( V_10 -> V_253 -> V_250 . V_261 ) ) {
if ( NULL == V_520 -> V_25 && NULL == V_520 -> V_513 ) {
V_520 -> V_25 = V_10 -> V_253 ;
V_520 -> V_513 = V_10 -> V_253 ;
}
} else {
if ( V_271 == V_10 -> V_253 -> V_250 . V_261 &&
NULL == V_520 -> V_25 ) {
V_520 -> V_25 = V_10 -> V_253 ;
}
if ( V_272 == V_10 -> V_253 -> V_250 . V_261 &&
NULL == V_520 -> V_513 ) {
V_520 -> V_513 = V_10 -> V_253 ;
}
}
}
F_22 ( L_71 ,
V_10 -> V_11 . V_58 , V_520 -> V_25 , V_520 -> V_513 ,
V_10 -> V_253 , V_520 -> V_168 , V_520 -> V_522 ) ;
return 0 ;
}
static void
F_202 ( struct V_9 * V_10 , struct V_519 * V_523 ,
struct V_519 * V_167 , unsigned int V_251 )
{
struct V_524 V_525 ;
F_203 ( & V_525 ) ;
if ( V_523 -> V_25 == V_523 -> V_513 ) {
if ( NULL != V_523 -> V_25 && V_167 -> V_25 != V_523 -> V_25 ) {
if ( V_526 > 1 )
F_61 ( L_72 ,
V_10 -> V_11 . V_58 , V_523 -> V_25 ) ;
V_523 -> V_25 -> V_250 . V_525 = V_525 ;
V_523 -> V_25 -> V_250 . V_242 = V_10 -> V_242 ;
V_523 -> V_25 -> V_250 . V_251 = V_251 ;
F_204 ( & V_523 -> V_25 -> V_250 . V_468 ) ;
}
} else {
if ( NULL != V_523 -> V_25 && V_167 -> V_25 != V_523 -> V_25 ) {
if ( V_526 > 1 )
F_61 ( L_73 ,
V_10 -> V_11 . V_58 , V_523 -> V_25 ) ;
V_523 -> V_25 -> V_250 . V_525 = V_525 ;
V_523 -> V_25 -> V_250 . V_242 = V_10 -> V_242 ;
V_523 -> V_25 -> V_250 . V_251 = V_251 ;
F_204 ( & V_523 -> V_25 -> V_250 . V_468 ) ;
}
if ( NULL != V_523 -> V_513 && V_167 -> V_513 != V_523 -> V_513 ) {
if ( V_526 > 1 )
F_61 ( L_74 ,
V_10 -> V_11 . V_58 , V_523 -> V_513 ) ;
V_523 -> V_513 -> V_250 . V_525 = V_525 ;
V_523 -> V_513 -> V_250 . V_242 = V_10 -> V_242 ;
V_523 -> V_513 -> V_250 . V_251 = V_251 ;
F_204 ( & V_523 -> V_513 -> V_250 . V_468 ) ;
}
}
}
static void
F_205 ( struct V_9 * V_10 , struct V_247 * V_523 ,
unsigned int V_251 )
{
if ( NULL == V_523 )
return;
F_203 ( & V_523 -> V_250 . V_525 ) ;
V_523 -> V_250 . V_242 = V_10 -> V_242 ;
V_523 -> V_250 . V_251 = V_251 ;
F_204 ( & V_523 -> V_250 . V_468 ) ;
}
static void F_206 ( unsigned long V_237 )
{
struct V_9 * V_10 = (struct V_9 * ) V_237 ;
struct V_519 V_249 , V_248 ;
struct V_247 * V_527 ;
struct V_247 * V_521 ;
unsigned long V_164 ;
if ( V_60 ) {
F_23 ( L_75 ,
V_10 -> V_11 . V_58 , V_10 -> V_528 , V_10 -> V_529 , V_10 -> V_530 ,
F_16 ( V_531 ) ) ;
F_194 ( F_16 ( V_172 ) , 0 ) ;
F_189 ( L_76 ) ;
}
F_53 ( & V_10 -> V_166 , V_164 ) ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_249 = V_10 -> V_167 ;
V_527 = V_10 -> V_512 ;
V_10 -> V_167 = V_248 ;
V_10 -> V_512 = NULL ;
V_10 -> V_254 = 0 ;
F_207 ( V_10 , & V_248 ) ;
F_208 ( V_10 , NULL ) ;
F_59 ( V_10 , 0 ) ;
F_202 ( V_10 , & V_249 , & V_248 , V_469 ) ;
F_205 ( V_10 , V_527 , V_469 ) ;
while ( ! F_159 ( & V_10 -> V_286 ) ) {
V_521 = F_160 ( V_10 -> V_286 . V_459 , struct V_247 , V_250 . V_285 ) ;
F_209 ( & V_521 -> V_250 . V_285 ) ;
V_521 -> V_250 . V_251 = V_469 ;
F_204 ( & V_521 -> V_250 . V_468 ) ;
}
while ( ! F_159 ( & V_10 -> V_532 ) ) {
V_521 = F_160 ( V_10 -> V_532 . V_459 , struct V_247 , V_250 . V_285 ) ;
F_209 ( & V_521 -> V_250 . V_285 ) ;
V_521 -> V_250 . V_251 = V_469 ;
F_204 ( & V_521 -> V_250 . V_468 ) ;
}
V_10 -> V_199 ++ ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
}
static void
F_210 ( struct V_9 * V_10 )
{
struct V_247 * V_523 = V_10 -> V_167 . V_25 ;
if ( NULL == V_523 )
return;
F_211 ( & V_10 -> V_166 ) ;
V_10 -> V_167 . V_522 = 0 ;
V_10 -> V_167 . V_25 = NULL ;
F_212 ( V_10 , V_518 , NULL , 0 ) ;
F_203 ( & V_523 -> V_250 . V_525 ) ;
V_523 -> V_250 . V_242 = V_10 -> V_242 ;
V_523 -> V_250 . V_251 = V_252 ;
F_204 ( & V_523 -> V_250 . V_468 ) ;
F_213 ( & V_10 -> V_166 ) ;
}
static inline int F_214 ( struct V_508 * V_497 , T_4 V_264 )
{
if ( V_264 < V_497 -> V_511 )
return 0 ;
if ( V_264 > V_497 -> V_511 + V_497 -> V_270 )
return 0 ;
return 1 ;
}
static void
F_215 ( struct V_9 * V_10 )
{
struct V_519 V_248 ;
struct V_519 V_249 ;
T_11 V_264 ;
F_211 ( & V_10 -> V_166 ) ;
F_199 ( V_10 , & V_248 ) ;
V_264 = F_16 ( V_531 ) ;
if ( ( V_10 -> V_167 . V_25 && F_214 ( & V_10 -> V_167 . V_25 -> V_25 , V_264 ) ) ||
( V_10 -> V_167 . V_513 && F_214 ( & V_10 -> V_167 . V_513 -> V_513 , V_264 ) ) ) {
V_10 -> V_528 ++ ;
if ( V_533 )
F_195 ( V_10 , V_264 ) ;
F_213 ( & V_10 -> V_166 ) ;
return;
}
V_249 = V_10 -> V_167 ;
V_10 -> V_167 = V_248 ;
V_10 -> V_254 &= ~ 1 ;
F_207 ( V_10 , & V_248 ) ;
F_59 ( V_10 , 0 ) ;
if ( V_12 != V_10 -> V_169 ) {
F_31 ( V_10 , V_10 -> V_169 ) ;
V_10 -> V_169 = V_12 ;
}
F_202 ( V_10 , & V_249 , & V_248 , V_252 ) ;
F_213 ( & V_10 -> V_166 ) ;
}
static void
F_216 ( struct V_9 * V_10 )
{
struct V_247 * V_248 = NULL ;
struct V_247 * V_249 ;
T_4 V_264 ;
F_211 ( & V_10 -> V_166 ) ;
if ( ! F_159 ( & V_10 -> V_532 ) )
V_248 = F_160 ( V_10 -> V_532 . V_459 , struct V_247 , V_250 . V_285 ) ;
V_249 = V_10 -> V_512 ;
V_264 = F_16 ( V_531 ) ;
if ( NULL != V_249 && ( F_214 ( & V_249 -> V_25 , V_264 ) ||
F_214 ( & V_249 -> V_513 , V_264 ) ) ) {
V_10 -> V_528 ++ ;
if ( V_533 )
F_195 ( V_10 , V_264 ) ;
F_213 ( & V_10 -> V_166 ) ;
return;
}
V_10 -> V_512 = V_248 ;
V_10 -> V_254 &= ~ 4 ;
F_208 ( V_10 , V_248 ) ;
F_59 ( V_10 , 0 ) ;
F_205 ( V_10 , V_249 , V_252 ) ;
F_213 ( & V_10 -> V_166 ) ;
}
static T_12 F_217 ( int V_534 , void * V_535 )
{
T_4 V_536 , V_537 ;
T_4 V_538 ;
int V_280 ;
struct V_9 * V_10 ;
int V_539 = 0 ;
V_10 = (struct V_9 * ) V_535 ;
V_280 = 0 ;
while ( 1 ) {
V_536 = F_16 ( V_172 ) ;
V_537 = V_536 & F_16 ( V_175 ) ;
if ( ! V_537 )
break;
V_539 = 1 ;
F_17 ( V_536 , V_172 ) ;
V_538 = F_16 ( V_62 ) ;
if ( V_526 ) {
F_61 ( L_77 ,
V_10 -> V_11 . V_58 , V_280 , V_10 -> V_242 ,
V_536 >> 28 , F_16 ( V_531 ) ) ;
F_194 ( V_536 , V_537 ) ;
if ( V_536 & V_185 )
F_189 ( L_78 ,
V_538 & V_107
? L_79 : L_80 ) ;
if ( V_536 & V_540 )
F_189 ( L_81 ,
V_538 & V_304
? L_79 : L_80 ) ;
if ( V_536 & V_184 )
F_189 ( L_82 ,
V_538 & V_294
? L_83 : L_84 ) ;
F_189 ( L_76 ) ;
}
if ( V_537 & V_241 )
V_10 -> V_242 ++ ;
if ( ( V_537 & V_178 ) && V_10 -> V_541 ) {
F_218 ( V_10 ) ;
}
if ( V_537 & V_174 ) {
V_10 -> V_542 = V_536 ;
F_204 ( & V_10 -> V_543 ) ;
}
if ( ( V_537 & V_182 ) && ( V_536 & ( 4 << 28 ) ) )
F_216 ( V_10 ) ;
if ( ( V_537 & V_182 ) && ( V_536 & ( 2 << 28 ) ) )
F_210 ( V_10 ) ;
if ( ( V_537 & V_182 ) && ( V_536 & ( 1 << 28 ) ) )
F_215 ( V_10 ) ;
if ( ( V_537 & V_185 ) && V_10 -> V_108 )
F_36 ( V_10 , V_10 -> V_119 , V_10 -> V_103 ) ;
if ( V_537 & ( V_179 | V_183 ) ) {
F_23 ( L_85 ,
V_10 -> V_11 . V_58 ,
( V_537 & V_179 ) ? L_86 : L_87 ,
( V_537 & V_183 ) ? L_88 : L_87 ,
F_16 ( V_531 ) ) ;
F_194 ( V_536 , V_537 ) ;
F_189 ( L_76 ) ;
if ( V_544 )
F_193 ( V_10 ) ;
}
if ( V_180 && V_537 & V_181 ) {
F_23 ( L_89 ,
V_10 -> V_11 . V_58 , F_16 ( V_531 ) ) ;
if ( V_544 )
F_193 ( V_10 ) ;
}
V_280 ++ ;
if ( V_280 > 4 ) {
if ( V_280 > 8 || ! ( V_537 & V_178 ) ) {
F_17 ( 0 , V_175 ) ;
F_19 ( L_90 ,
V_10 -> V_11 . V_58 ) ;
} else {
F_19 ( L_91 ,
V_10 -> V_11 . V_58 ) ;
F_17 ( F_16 ( V_175 ) & ( - 1 ^ V_178 ) ,
V_175 ) ;
}
F_194 ( V_536 , V_537 ) ;
F_189 ( L_92 ) ;
}
}
V_10 -> V_530 ++ ;
if ( V_539 )
V_10 -> V_529 ++ ;
return F_219 ( V_539 ) ;
}
static void F_220 ( struct V_9 * V_10 ,
struct V_6 * V_7 ,
const struct V_6 * V_545 ,
const char * V_546 )
{
* V_7 = * V_545 ;
V_7 -> V_326 = & V_10 -> V_11 . V_326 ;
V_7 -> V_547 = V_548 ;
F_221 ( V_7 , V_10 ) ;
snprintf ( V_7 -> V_301 , sizeof( V_7 -> V_301 ) , L_93 ,
V_10 -> V_149 , ( V_10 -> V_149 == 848 && V_10 -> V_549 == 0x12 ) ? L_94 : L_87 ,
V_546 , V_95 [ V_10 -> V_11 . type ] . V_301 ) ;
if ( V_10 -> V_170 == V_171 ) {
F_222 ( V_7 , V_550 ) ;
F_222 ( V_7 , V_551 ) ;
F_222 ( V_7 , V_552 ) ;
F_222 ( V_7 , V_553 ) ;
}
}
static void F_223 ( struct V_9 * V_10 )
{
F_224 ( & V_10 -> V_394 ) ;
F_224 ( & V_10 -> V_403 ) ;
F_224 ( & V_10 -> V_405 ) ;
}
static int F_225 ( struct V_9 * V_10 )
{
if ( V_389 > 0 )
F_197 ( L_95 ) ;
F_220 ( V_10 , & V_10 -> V_394 , & V_554 , L_96 ) ;
if ( F_226 ( & V_10 -> V_394 , V_411 ,
V_555 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_291;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_164 ( & V_10 -> V_394 ) ) ;
if ( F_227 ( & V_10 -> V_394 . V_8 ,
& V_556 ) < 0 ) {
F_19 ( L_98 , V_10 -> V_11 . V_58 ) ;
goto V_291;
}
F_220 ( V_10 , & V_10 -> V_403 , & V_554 , L_99 ) ;
if ( F_226 ( & V_10 -> V_403 , V_413 ,
V_557 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_291;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_164 ( & V_10 -> V_403 ) ) ;
if ( ! V_10 -> V_558 )
return 0 ;
F_220 ( V_10 , & V_10 -> V_405 , & V_559 , L_100 ) ;
V_10 -> V_405 . V_121 = & V_10 -> V_560 ;
if ( F_226 ( & V_10 -> V_405 , V_561 ,
V_562 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_291;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_164 ( & V_10 -> V_405 ) ) ;
return 0 ;
V_291:
F_223 ( V_10 ) ;
return - 1 ;
}
static void F_228 ( struct V_563 * V_8 )
{
#if F_229 ( V_564 )
unsigned int V_481 ;
F_230 ( V_8 , V_565 , & V_481 ) ;
V_481 = ( V_481 | V_566 ) ;
F_231 ( V_8 , V_565 , V_481 ) ;
#endif
}
static int F_232 ( struct V_563 * V_8 , const struct V_567 * V_568 )
{
struct V_314 V_569 = {
. V_287 = 0 ,
. type = V_440 ,
. V_316 = 980 ,
} ;
int V_493 ;
unsigned char V_570 ;
struct V_9 * V_10 ;
struct V_571 * V_572 ;
if ( V_573 == V_574 )
return - V_363 ;
F_23 ( L_101 , V_573 ) ;
V_575 [ V_573 ] = V_10 = F_233 ( sizeof( * V_10 ) , V_362 ) ;
if ( V_10 == NULL ) {
F_19 ( L_102 ) ;
return - V_363 ;
}
V_10 -> V_11 . V_58 = V_573 ;
snprintf ( V_10 -> V_11 . V_326 . V_301 , sizeof( V_10 -> V_11 . V_326 . V_301 ) ,
L_103 , V_10 -> V_11 . V_58 ) ;
F_234 ( & V_10 -> V_472 ) ;
F_235 ( & V_10 -> V_166 ) ;
F_235 ( & V_10 -> V_576 ) ;
F_236 ( & V_10 -> V_543 ) ;
F_237 ( & V_10 -> V_11 . V_577 ) ;
F_237 ( & V_10 -> V_286 ) ;
F_237 ( & V_10 -> V_532 ) ;
F_238 ( & V_10 -> V_578 ) ;
V_10 -> V_578 . V_579 = F_206 ;
V_10 -> V_578 . V_237 = ( unsigned long ) V_10 ;
V_10 -> V_580 = - 1 ;
V_10 -> V_170 = V_12 ;
V_10 -> V_169 = V_12 ;
V_10 -> V_558 = V_581 [ V_10 -> V_11 . V_58 ] ;
V_10 -> V_11 . V_396 = V_8 ;
V_10 -> V_149 = V_8 -> V_1 ;
if ( F_239 ( V_8 ) ) {
F_196 ( L_104 , V_10 -> V_11 . V_58 ) ;
return - V_582 ;
}
if ( F_240 ( V_8 , F_241 ( 32 ) ) ) {
F_196 ( L_105 , V_10 -> V_11 . V_58 ) ;
return - V_582 ;
}
if ( ! F_242 ( F_243 ( V_8 , 0 ) ,
F_244 ( V_8 , 0 ) ,
V_10 -> V_11 . V_326 . V_301 ) ) {
F_196 ( L_106 ,
V_10 -> V_11 . V_58 ,
( unsigned long long ) F_243 ( V_8 , 0 ) ) ;
return - V_345 ;
}
F_245 ( V_8 ) ;
F_228 ( V_8 ) ;
V_493 = F_246 ( & V_8 -> V_8 , & V_10 -> V_11 . V_326 ) ;
if ( V_493 < 0 ) {
F_196 ( L_107 , V_10 -> V_11 . V_58 ) ;
goto V_583;
}
V_572 = & V_10 -> V_121 ;
F_247 ( V_572 , 20 ) ;
V_10 -> V_11 . V_326 . V_121 = V_572 ;
F_247 ( & V_10 -> V_560 , 6 ) ;
V_10 -> V_549 = V_8 -> V_549 ;
F_248 ( V_8 , V_584 , & V_570 ) ;
F_23 ( L_108 ,
V_573 , V_10 -> V_149 , V_10 -> V_549 , F_121 ( V_8 ) ,
V_10 -> V_11 . V_396 -> V_534 , V_570 ,
( unsigned long long ) F_243 ( V_8 , 0 ) ) ;
F_249 () ;
V_10 -> V_585 = F_250 ( F_243 ( V_8 , 0 ) , 0x1000 ) ;
if ( NULL == V_10 -> V_585 ) {
F_19 ( L_109 , V_10 -> V_11 . V_58 ) ;
V_493 = - V_582 ;
goto V_586;
}
F_251 ( V_10 ) ;
F_17 ( 0 , V_175 ) ;
V_493 = F_252 ( V_10 -> V_11 . V_396 -> V_534 , F_217 ,
V_587 , V_10 -> V_11 . V_326 . V_301 , ( void * ) V_10 ) ;
if ( V_493 < 0 ) {
F_19 ( L_110 ,
V_573 , V_10 -> V_11 . V_396 -> V_534 ) ;
goto V_586;
}
if ( 0 != F_253 ( V_10 ) ) {
V_493 = - V_582 ;
goto V_588;
}
V_10 -> V_215 = V_589 ;
V_590 . V_591 = V_589 ;
V_592 . V_591 = V_593 ;
V_10 -> V_108 = V_594 ;
V_595 . V_591 = V_594 ;
V_596 . V_591 = V_597 ;
V_10 -> V_224 = V_598 ;
V_599 . V_591 = V_598 ;
V_600 . V_591 = V_601 ;
V_602 . V_591 = V_603 ;
V_10 -> V_90 = V_604 ;
V_605 . V_591 = V_604 ;
V_606 . V_591 = V_607 ;
V_608 . V_591 = V_609 ;
V_10 -> V_369 . V_10 = V_10 ;
V_10 -> V_369 . V_366 . V_348 . V_145 = 320 ;
V_10 -> V_369 . V_366 . V_348 . V_39 = 240 ;
V_10 -> V_369 . V_259 = F_63 ( V_610 ) ;
V_10 -> V_369 . V_145 = 320 ;
V_10 -> V_369 . V_39 = 240 ;
V_10 -> V_369 . V_366 . V_348 . V_145 = 320 ;
V_10 -> V_369 . V_366 . V_348 . V_39 = 240 ;
V_10 -> V_369 . V_366 . V_261 = V_352 ;
V_10 -> V_69 = 0 ;
F_254 ( V_572 , & V_611 ,
V_202 , 0 , 0xff00 , 0x100 , 32768 ) ;
F_254 ( V_572 , & V_611 ,
V_204 , 0 , 0xff80 , 0x80 , 0x6c00 ) ;
F_254 ( V_572 , & V_611 ,
V_205 , 0 , 0xff80 , 0x80 , 32768 ) ;
F_254 ( V_572 , & V_611 ,
V_206 , 0 , 1 , 1 , 0 ) ;
F_254 ( V_572 , & V_611 ,
V_203 , 0 , 0xff00 , 0x100 , 32768 ) ;
F_254 ( V_572 , & V_611 ,
V_212 , 0 , 1 , 1 , ! ! V_612 ) ;
F_254 ( V_572 , & V_611 ,
V_122 , 0 , 1 , 1 , 0 ) ;
if ( V_10 -> V_211 )
F_254 ( V_572 , & V_611 ,
V_210 , 0 , 0xff00 , 0x100 , 0xff00 ) ;
F_255 ( V_572 , & V_590 , NULL ) ;
F_255 ( V_572 , & V_595 , NULL ) ;
F_255 ( V_572 , & V_592 , NULL ) ;
F_255 ( V_572 , & V_596 , NULL ) ;
F_255 ( V_572 , & V_599 , NULL ) ;
F_255 ( V_572 , & V_602 , NULL ) ;
F_255 ( V_572 , & V_600 , NULL ) ;
F_255 ( V_572 , & V_605 , NULL ) ;
F_255 ( V_572 , & V_606 , NULL ) ;
F_255 ( V_572 , & V_608 , NULL ) ;
if ( V_115 )
F_39 ( V_10 , L_111 ) ;
F_256 ( V_10 ) ;
F_56 ( V_10 ) ;
F_17 ( 0x00 , V_613 ) ;
F_17 ( 0x00 , V_238 ) ;
if ( V_60 )
F_39 ( V_10 , L_112 ) ;
F_257 ( V_10 ) ;
F_258 ( V_10 ) ;
F_259 ( V_10 ) ;
F_260 ( V_10 ) ;
if ( V_10 -> V_170 != V_171 ) {
F_84 ( V_10 , & V_569 ) ;
V_10 -> V_317 = 90500 * 16 ;
}
V_10 -> V_292 = V_614 ;
F_55 ( V_10 ) ;
if ( ! V_95 [ V_10 -> V_11 . type ] . V_173 )
F_57 ( V_572 ) ;
if ( V_572 -> error ) {
V_493 = V_572 -> error ;
goto V_588;
}
F_40 ( V_10 , 1 ) ;
if ( ! V_95 [ V_10 -> V_11 . type ] . V_173 ) {
F_261 ( & V_10 -> V_560 , V_572 ,
V_615 ) ;
if ( V_10 -> V_560 . error ) {
V_493 = V_10 -> V_560 . error ;
goto V_588;
}
F_52 ( V_10 , 0 , V_10 -> V_35 ) ;
F_47 ( & V_10 -> V_26 [ 0 ] , V_10 -> V_35 ) ;
V_10 -> V_26 [ 1 ] = V_10 -> V_26 [ 0 ] ;
F_14 ( V_10 ) ;
F_15 ( V_10 ) ;
F_225 ( V_10 ) ;
}
if ( V_95 [ V_10 -> V_11 . type ] . V_616 ) {
F_262 ( & V_10 -> V_11 , L_113 ) ;
F_6 ( V_10 ) ;
}
if ( ! V_617 ) {
F_263 ( V_10 ) ;
F_264 ( V_10 ) ;
}
V_573 ++ ;
return 0 ;
V_588:
F_265 ( V_10 -> V_11 . V_396 -> V_534 , V_10 ) ;
V_586:
F_266 ( & V_10 -> V_121 ) ;
F_266 ( & V_10 -> V_560 ) ;
F_267 ( & V_10 -> V_11 . V_326 ) ;
V_583:
if ( V_10 -> V_585 )
F_268 ( V_10 -> V_585 ) ;
F_269 ( F_243 ( V_10 -> V_11 . V_396 , 0 ) ,
F_244 ( V_10 -> V_11 . V_396 , 0 ) ) ;
F_270 ( V_10 -> V_11 . V_396 ) ;
return V_493 ;
}
static void F_271 ( struct V_563 * V_563 )
{
struct V_618 * V_326 = F_272 ( V_563 ) ;
struct V_9 * V_10 = F_273 ( V_326 ) ;
if ( V_60 )
F_23 ( L_114 , V_10 -> V_11 . V_58 ) ;
if ( V_95 [ V_10 -> V_11 . type ] . V_616 )
F_9 ( V_10 ) ;
F_34 ( ~ 15 , V_196 ) ;
F_17 ( 0 , V_175 ) ;
F_17 ( ~ 0x0 , V_172 ) ;
F_17 ( 0x0 , V_238 ) ;
if ( V_115 )
F_39 ( V_10 , L_115 ) ;
V_10 -> V_619 = 1 ;
F_274 ( V_10 ) ;
F_275 ( & V_10 -> V_11 ) ;
F_276 ( V_10 ) ;
F_223 ( V_10 ) ;
F_266 ( & V_10 -> V_121 ) ;
F_266 ( & V_10 -> V_560 ) ;
F_277 ( V_10 -> V_11 . V_396 , & V_10 -> main ) ;
F_265 ( V_10 -> V_11 . V_396 -> V_534 , V_10 ) ;
F_268 ( V_10 -> V_585 ) ;
F_269 ( F_243 ( V_10 -> V_11 . V_396 , 0 ) ,
F_244 ( V_10 -> V_11 . V_396 , 0 ) ) ;
F_270 ( V_10 -> V_11 . V_396 ) ;
F_267 ( & V_10 -> V_11 . V_326 ) ;
V_575 [ V_10 -> V_11 . V_58 ] = NULL ;
F_66 ( V_10 ) ;
return;
}
static int F_278 ( struct V_563 * V_563 , T_13 V_251 )
{
struct V_618 * V_326 = F_272 ( V_563 ) ;
struct V_9 * V_10 = F_273 ( V_326 ) ;
struct V_519 V_620 ;
unsigned long V_164 ;
F_22 ( L_116 , V_10 -> V_11 . V_58 , V_251 . V_621 ) ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
memset ( & V_620 , 0 , sizeof( V_620 ) ) ;
V_10 -> V_251 . V_162 = V_10 -> V_167 ;
V_10 -> V_251 . V_372 = V_10 -> V_512 ;
V_10 -> V_251 . V_254 = V_10 -> V_254 ;
V_10 -> V_167 = V_620 ;
V_10 -> V_254 = 0 ;
F_207 ( V_10 , & V_620 ) ;
F_208 ( V_10 , NULL ) ;
F_59 ( V_10 , 0 ) ;
F_17 ( 0 , V_175 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
V_10 -> V_251 . V_622 = F_16 ( V_238 ) ;
V_10 -> V_251 . V_623 = F_50 () ;
F_279 ( V_563 ) ;
if ( 0 != F_280 ( V_563 , F_281 ( V_563 , V_251 ) ) ) {
F_270 ( V_563 ) ;
V_10 -> V_251 . V_624 = 1 ;
}
return 0 ;
}
static int F_282 ( struct V_563 * V_563 )
{
struct V_618 * V_326 = F_272 ( V_563 ) ;
struct V_9 * V_10 = F_273 ( V_326 ) ;
unsigned long V_164 ;
int V_291 ;
F_22 ( L_117 , V_10 -> V_11 . V_58 ) ;
if ( V_10 -> V_251 . V_624 ) {
V_291 = F_239 ( V_563 ) ;
if ( V_291 ) {
F_196 ( L_104 , V_10 -> V_11 . V_58 ) ;
return V_291 ;
}
V_10 -> V_251 . V_624 = 0 ;
}
V_291 = F_280 ( V_563 , V_625 ) ;
if ( V_291 ) {
F_270 ( V_563 ) ;
F_196 ( L_104 , V_10 -> V_11 . V_58 ) ;
V_10 -> V_251 . V_624 = 1 ;
return V_291 ;
}
F_283 ( V_563 ) ;
F_58 ( V_10 ) ;
F_32 ( 0xffffff , V_10 -> V_251 . V_622 ) ;
F_284 ( V_10 -> V_251 . V_623 ) ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
V_10 -> V_167 = V_10 -> V_251 . V_162 ;
V_10 -> V_512 = V_10 -> V_251 . V_372 ;
V_10 -> V_254 = V_10 -> V_251 . V_254 ;
F_207 ( V_10 , & V_10 -> V_167 ) ;
F_208 ( V_10 , V_10 -> V_512 ) ;
F_59 ( V_10 , 0 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
return 0 ;
}
static int T_14 F_285 ( void )
{
int V_626 ;
V_573 = 0 ;
F_23 ( L_118 , V_627 ) ;
if ( V_281 < 2 || V_281 > V_628 )
V_281 = 2 ;
if ( V_282 > V_629 )
V_282 = V_629 ;
V_282 = ( V_282 + V_630 - 1 ) & V_631 ;
if ( V_60 )
F_23 ( L_119 ,
V_281 , V_282 >> 10 , V_282 >> V_632 ) ;
F_286 () ;
V_626 = F_287 ( & V_633 ) ;
if ( V_626 < 0 ) {
F_196 ( L_120 , V_626 ) ;
return V_626 ;
}
V_626 = F_288 ( & V_634 ) ;
if ( V_626 < 0 )
F_289 ( & V_633 ) ;
return V_626 ;
}
static void T_15 F_290 ( void )
{
F_291 ( & V_634 ) ;
F_289 ( & V_633 ) ;
}
