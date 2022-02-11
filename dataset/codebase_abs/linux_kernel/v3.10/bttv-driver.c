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
( F_46 ( 48 , V_11 -> V_28 . V_144 >> 4 ) + 3 ) & ~ 3 ;
V_11 -> V_143 =
F_46 ( 32 , V_11 -> V_28 . V_39 >> 4 ) ;
}
V_11 -> V_145 = V_11 -> V_28 . V_144 & ~ 3 ;
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
unsigned int V_144 , unsigned int V_39 ,
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
V_144 = V_268 ;
V_39 = V_269 * 2 ;
if ( V_144 * V_39 > V_5 -> V_251 . V_270 )
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
if ( V_144 < V_11 . V_142 ||
V_144 > V_11 . V_145 ||
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
V_5 -> V_251 . V_271 = ( V_144 * V_39 * V_260 -> V_275 ) >> 3 ;
if ( 0 != V_5 -> V_251 . V_276 && V_5 -> V_251 . V_270 < V_5 -> V_251 . V_271 )
return - V_97 ;
}
if ( V_5 -> V_251 . V_144 != V_144 || V_5 -> V_251 . V_39 != V_39 ||
V_5 -> V_251 . V_262 != V_262 ||
V_5 -> V_35 != V_147 || V_5 -> V_260 != V_260 ||
V_5 -> V_26 . V_25 != V_11 . V_28 . V_25 ||
V_5 -> V_26 . V_277 != V_11 . V_28 . V_277 ||
V_5 -> V_26 . V_144 != V_11 . V_28 . V_144 ||
V_5 -> V_26 . V_39 != V_11 . V_28 . V_39 ) {
V_5 -> V_251 . V_144 = V_144 ;
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
* V_271 = V_17 -> V_260 -> V_275 * V_17 -> V_144 * V_17 -> V_39 >> 3 ;
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
V_17 -> V_144 , V_17 -> V_39 , V_262 ) ;
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
* V_149 = V_296 ;
else
* V_149 = V_297 ;
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
F_51 ( V_10 , V_162 , V_326 ) ;
return 0 ;
}
static int F_90 ( struct V_290 * V_290 , void * V_294 , struct V_327 * V_328 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
V_328 -> V_329 = V_330 ;
V_328 -> V_331 = 0 ;
if ( V_328 -> V_332 . type == V_333 ) {
if ( F_91 ( & V_328 -> V_332 ) ) {
V_328 -> V_329 = V_10 -> V_149 ;
if ( V_328 -> V_329 == V_334 )
V_328 -> V_329 = V_335 ;
}
return 0 ;
}
if ( V_328 -> V_332 . type != V_336 &&
V_328 -> V_332 . type != V_337 )
return - V_97 ;
return F_92 ( V_10 , V_162 , V_338 , V_328 ) ;
}
static int F_93 ( struct V_290 * V_290 , void * V_294 ,
struct V_339 * V_340 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( ! F_94 ( V_341 ) )
return - V_342 ;
if ( ! F_91 ( & V_340 -> V_332 ) ) {
F_51 ( V_10 , V_162 , V_343 , V_340 ) ;
return 0 ;
}
V_340 -> V_340 &= 0xfff ;
V_340 -> V_201 = F_16 ( V_340 -> V_340 ) ;
V_340 -> V_271 = 1 ;
return 0 ;
}
static int F_95 ( struct V_290 * V_290 , void * V_294 ,
const struct V_339 * V_340 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( ! F_94 ( V_341 ) )
return - V_342 ;
if ( ! F_91 ( & V_340 -> V_332 ) ) {
F_51 ( V_10 , V_162 , V_344 , V_340 ) ;
return 0 ;
}
F_17 ( V_340 -> V_201 , V_340 -> V_340 & 0xfff ) ;
return 0 ;
}
static void
F_96 ( struct V_141 * V_11 ,
const struct V_345 * V_346 ,
T_2 V_144 ,
T_2 V_39 ,
enum V_261 V_262 )
{
T_2 V_347 = V_39 << ! F_97 ( V_262 ) ;
T_2 V_348 ;
T_2 V_349 ;
if ( V_144 < V_11 -> V_142 ) {
V_11 -> V_28 . V_144 = V_144 * 16 ;
} else if ( V_144 > V_11 -> V_145 ) {
V_11 -> V_28 . V_144 = V_144 ;
V_348 = V_346 -> V_277 + V_346 -> V_144 - V_144 ;
V_348 = F_98 ( V_348 , ( T_2 ) V_350 ) ;
if ( V_11 -> V_28 . V_277 > V_348 )
V_11 -> V_28 . V_277 = V_348 ;
}
if ( V_39 < V_11 -> V_143 ) {
V_11 -> V_28 . V_39 = V_39 * 16 ;
} else if ( V_347 > V_11 -> V_146 ) {
V_11 -> V_28 . V_39 = ( V_347 + 1 ) & ~ 1 ;
V_349 = V_346 -> V_25 + V_346 -> V_39 - V_11 -> V_28 . V_39 ;
if ( V_11 -> V_28 . V_25 > V_349 )
V_11 -> V_28 . V_25 = V_349 ;
}
F_45 ( V_11 ) ;
}
static int
F_99 ( struct V_16 * V_17 ,
T_2 * V_144 ,
T_2 * V_39 ,
enum V_261 V_262 ,
unsigned int V_351 ,
unsigned int V_352 ,
int V_353 ,
int V_354 )
{
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_345 * V_346 ;
struct V_141 * V_11 ;
T_2 V_355 ;
T_2 V_356 ;
T_2 V_357 ;
T_2 V_358 ;
int V_265 ;
F_49 ( ( int ) V_351 >= 0 ||
V_352 >= ( unsigned int ) - V_351 ) ;
V_346 = & V_36 [ V_10 -> V_35 ] . V_37 . V_38 ;
V_11 = & V_10 -> V_26 [ ! ! V_17 -> V_27 ] ;
if ( V_17 -> V_27
&& V_353
&& V_354
&& ! F_13 ( V_10 , V_24 ) ) {
V_355 = 48 ;
V_356 = 32 ;
V_357 = F_98 ( V_346 -> V_144 , ( T_2 ) V_359 ) ;
V_358 = V_346 -> V_39 ;
if ( V_10 -> V_29 > V_346 -> V_25 ) {
V_358 -= V_10 -> V_29 - V_346 -> V_25 ;
V_265 = - V_360 ;
if ( V_356 > V_358 )
goto V_23;
}
} else {
V_265 = - V_360 ;
if ( V_10 -> V_29 > V_11 -> V_28 . V_25 )
goto V_23;
V_355 = V_11 -> V_142 ;
V_356 = V_11 -> V_143 ;
V_357 = V_11 -> V_145 ;
V_358 = V_11 -> V_146 ;
V_354 = 0 ;
}
V_355 = ( V_355 - V_351 - 1 ) & V_351 ;
V_357 = V_357 & V_351 ;
V_356 = V_356 ;
V_358 >>= ! F_97 ( V_262 ) ;
if ( V_353 ) {
* V_144 = F_100 ( * V_144 , V_355 , V_357 ) ;
* V_39 = F_100 ( * V_39 , V_356 , V_358 ) ;
* V_144 = ( * V_144 + V_352 ) & V_351 ;
if ( V_354 ) {
F_96 ( V_11 , V_346 , * V_144 , * V_39 , V_262 ) ;
if ( V_10 -> V_29 > V_11 -> V_28 . V_25 ) {
V_11 -> V_28 . V_25 = V_10 -> V_29 ;
}
}
} else {
V_265 = - V_97 ;
if ( * V_144 < V_355 ||
* V_39 < V_356 ||
* V_144 > V_357 ||
* V_39 > V_358 ||
0 != ( * V_144 & ~ V_351 ) )
goto V_23;
}
V_265 = 0 ;
V_23:
return V_265 ;
}
static int
F_101 ( struct V_16 * V_17 , struct V_361 * V_362 ,
int V_353 , int V_354 )
{
enum V_261 V_262 ;
unsigned int V_351 ;
int V_265 ;
if ( V_362 -> V_363 . V_144 < 48 )
V_362 -> V_363 . V_144 = 48 ;
if ( V_362 -> V_363 . V_39 < 32 )
V_362 -> V_363 . V_39 = 32 ;
if ( V_362 -> V_364 > 2048 )
V_362 -> V_364 = 2048 ;
V_362 -> V_365 = 0 ;
V_362 -> V_366 = 0 ;
V_262 = V_362 -> V_262 ;
switch ( V_262 ) {
case V_272 :
case V_273 :
case V_367 :
break;
default:
V_262 = V_368 ;
break;
}
if ( V_368 == V_262 ) {
T_2 V_369 ;
V_369 = V_17 -> V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_39 >> 1 ;
V_262 = ( V_362 -> V_363 . V_39 > V_369 )
? V_367
: V_272 ;
}
V_362 -> V_262 = V_262 ;
if ( NULL == V_17 -> V_370 )
return - V_97 ;
V_351 = ~ 0 ;
switch ( V_17 -> V_370 -> V_275 ) {
case 8 :
case 24 :
V_351 = ~ 3 ;
break;
case 16 :
V_351 = ~ 1 ;
break;
case 32 :
break;
default:
F_102 () ;
}
V_362 -> V_363 . V_144 -= V_362 -> V_363 . V_277 & ~ V_351 ;
V_362 -> V_363 . V_277 = ( V_362 -> V_363 . V_277 - V_351 - 1 ) & V_351 ;
V_265 = F_99 ( V_17 , & V_362 -> V_363 . V_144 , & V_362 -> V_363 . V_39 ,
V_262 , V_351 ,
0 ,
V_353 , V_354 ) ;
if ( 0 != V_265 )
return V_265 ;
return 0 ;
}
static int F_103 ( struct V_16 * V_17 , struct V_9 * V_10 ,
struct V_361 * V_362 , int V_371 )
{
struct V_372 * V_373 = NULL ;
int V_374 , V_271 , V_250 = 0 ;
if ( NULL == V_17 -> V_370 )
return - V_97 ;
if ( ! ( V_17 -> V_370 -> V_164 & V_375 ) )
return - V_97 ;
V_250 = F_101 ( V_17 , V_362 ,
V_371 ,
V_371 ) ;
if ( 0 != V_250 )
return V_250 ;
V_374 = V_362 -> V_364 ;
V_271 = sizeof( * V_373 ) * ( V_374 + 4 ) ;
V_373 = F_104 ( V_271 , V_376 ) ;
if ( NULL == V_373 )
return - V_377 ;
if ( V_374 > 0 ) {
if ( F_105 ( V_373 , V_362 -> V_373 , sizeof( struct V_372 ) * V_374 ) ) {
F_66 ( V_373 ) ;
return - V_378 ;
}
}
if ( NULL != V_10 -> V_279 . V_379 )
V_374 = F_106 ( V_10 -> V_279 . V_260 . V_144 , V_10 -> V_279 . V_260 . V_39 ,
& V_362 -> V_363 , V_373 , V_374 ) ;
F_107 ( V_373 , V_374 ) ;
switch ( V_17 -> V_370 -> V_275 ) {
case 8 :
case 24 :
F_108 ( & V_362 -> V_363 , V_373 , V_374 , 3 ) ;
break;
case 16 :
F_108 ( & V_362 -> V_363 , V_373 , V_374 , 1 ) ;
break;
case 32 :
break;
default:
F_102 () ;
}
F_66 ( V_17 -> V_380 . V_373 ) ;
V_17 -> V_380 . V_373 = V_373 ;
V_17 -> V_380 . V_381 = V_374 ;
V_17 -> V_380 . V_363 = V_362 -> V_363 ;
V_17 -> V_380 . V_262 = V_362 -> V_262 ;
V_17 -> V_380 . V_382 = 1 ;
V_10 -> V_383 . V_380 . V_363 . V_144 = V_362 -> V_363 . V_144 ;
V_10 -> V_383 . V_380 . V_363 . V_39 = V_362 -> V_363 . V_39 ;
V_10 -> V_383 . V_380 . V_262 = V_362 -> V_262 ;
V_250 = 0 ;
if ( F_12 ( V_17 , V_257 ) ) {
struct V_247 * V_248 ;
V_248 = F_109 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_110 ( V_10 , & V_17 -> V_380 , V_17 -> V_370 , V_248 ) ;
V_250 = F_64 ( V_10 , V_17 , V_248 ) ;
}
return V_250 ;
}
static struct V_258 * F_111 ( struct V_16 * V_17 )
{
struct V_258 * V_259 = NULL ;
switch ( V_17 -> type ) {
case V_384 :
V_259 = & V_17 -> V_256 ;
break;
case V_385 :
V_259 = & V_17 -> V_386 ;
break;
default:
F_102 () ;
}
return V_259 ;
}
static int F_112 ( struct V_16 * V_17 )
{
int V_387 = 0 ;
switch ( V_17 -> type ) {
case V_384 :
V_387 = V_22 ;
break;
case V_385 :
V_387 = V_388 ;
break;
default:
F_102 () ;
}
return V_387 ;
}
static int F_113 ( struct V_16 * V_17 , enum V_389 type )
{
struct V_258 * V_259 = F_111 ( V_17 ) ;
int V_387 = F_112 ( V_17 ) ;
if ( F_12 ( V_17 , V_387 ) )
return - V_360 ;
if ( F_114 ( V_259 ) )
return - V_360 ;
V_17 -> type = type ;
return 0 ;
}
static void
F_115 ( struct V_390 * V_294 ,
const struct V_243 * V_260 ,
unsigned int V_144 ,
unsigned int V_39 )
{
V_294 -> V_144 = V_144 ;
V_294 -> V_39 = V_39 ;
if ( V_260 -> V_164 & V_391 ) {
V_294 -> V_392 = V_144 ;
V_294 -> V_393 = ( V_144 * V_39 * V_260 -> V_275 ) >> 3 ;
} else {
V_294 -> V_392 = ( V_144 * V_260 -> V_275 ) >> 3 ;
V_294 -> V_393 = V_39 * V_294 -> V_392 ;
}
}
static int F_116 ( struct V_290 * V_290 , void * V_291 ,
struct V_394 * V_294 )
{
struct V_16 * V_17 = V_291 ;
F_115 ( & V_294 -> V_260 . V_395 , V_17 -> V_260 ,
V_17 -> V_144 , V_17 -> V_39 ) ;
V_294 -> V_260 . V_395 . V_262 = V_17 -> V_256 . V_262 ;
V_294 -> V_260 . V_395 . V_396 = V_17 -> V_260 -> V_244 ;
V_294 -> V_260 . V_395 . V_397 = V_398 ;
return 0 ;
}
static int F_117 ( struct V_290 * V_290 , void * V_291 ,
struct V_394 * V_294 )
{
struct V_16 * V_17 = V_291 ;
V_294 -> V_260 . V_362 . V_363 = V_17 -> V_380 . V_363 ;
V_294 -> V_260 . V_362 . V_262 = V_17 -> V_380 . V_262 ;
return 0 ;
}
static int F_118 ( struct V_290 * V_290 , void * V_291 ,
struct V_394 * V_294 )
{
const struct V_243 * V_260 ;
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
enum V_261 V_262 ;
T_2 V_144 , V_39 ;
T_2 V_369 ;
int V_265 ;
V_260 = F_63 ( V_294 -> V_260 . V_395 . V_396 ) ;
if ( NULL == V_260 )
return - V_97 ;
V_262 = V_294 -> V_260 . V_395 . V_262 ;
switch ( V_262 ) {
case V_272 :
case V_273 :
case V_274 :
case V_367 :
break;
case V_399 :
case V_400 :
if ( ! ( V_260 -> V_164 & V_391 ) ) {
V_262 = V_400 ;
break;
}
default:
V_369 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 . V_39 >> 1 ;
V_262 = ( V_294 -> V_260 . V_395 . V_39 > V_369 )
? V_367
: V_273 ;
break;
}
V_144 = V_294 -> V_260 . V_395 . V_144 ;
V_39 = V_294 -> V_260 . V_395 . V_39 ;
V_265 = F_99 ( V_17 , & V_144 , & V_39 , V_262 ,
~ 3 ,
2 ,
1 ,
0 ) ;
if ( 0 != V_265 )
return V_265 ;
V_294 -> V_260 . V_395 . V_262 = V_262 ;
F_115 ( & V_294 -> V_260 . V_395 , V_260 , V_144 , V_39 ) ;
V_294 -> V_260 . V_395 . V_397 = V_398 ;
return 0 ;
}
static int F_119 ( struct V_290 * V_290 , void * V_291 ,
struct V_394 * V_294 )
{
struct V_16 * V_17 = V_291 ;
F_101 ( V_17 , & V_294 -> V_260 . V_362 ,
1 ,
0 ) ;
return 0 ;
}
static int F_120 ( struct V_290 * V_290 , void * V_291 ,
struct V_394 * V_294 )
{
int V_250 ;
const struct V_243 * V_260 ;
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
T_2 V_144 , V_39 ;
enum V_261 V_262 ;
V_250 = F_113 ( V_17 , V_294 -> type ) ;
if ( 0 != V_250 )
return V_250 ;
V_250 = F_118 ( V_290 , V_291 , V_294 ) ;
if ( 0 != V_250 )
return V_250 ;
V_144 = V_294 -> V_260 . V_395 . V_144 ;
V_39 = V_294 -> V_260 . V_395 . V_39 ;
V_262 = V_294 -> V_260 . V_395 . V_262 ;
V_250 = F_99 ( V_17 , & V_144 , & V_39 , V_294 -> V_260 . V_395 . V_262 ,
~ 3 ,
2 ,
1 ,
1 ) ;
if ( 0 != V_250 )
return V_250 ;
V_294 -> V_260 . V_395 . V_262 = V_262 ;
V_260 = F_63 ( V_294 -> V_260 . V_395 . V_396 ) ;
V_17 -> V_260 = V_260 ;
V_17 -> V_256 . V_262 = V_294 -> V_260 . V_395 . V_262 ;
V_17 -> V_256 . V_401 = V_402 ;
V_17 -> V_144 = V_294 -> V_260 . V_395 . V_144 ;
V_17 -> V_39 = V_294 -> V_260 . V_395 . V_39 ;
V_10 -> V_383 . V_260 = V_260 ;
V_10 -> V_383 . V_144 = V_294 -> V_260 . V_395 . V_144 ;
V_10 -> V_383 . V_39 = V_294 -> V_260 . V_395 . V_39 ;
return 0 ;
}
static int F_121 ( struct V_290 * V_290 , void * V_291 ,
struct V_394 * V_294 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_403 > 0 ) {
F_19 ( L_19 ) ;
return - V_97 ;
}
return F_103 ( V_17 , V_10 , & V_294 -> V_260 . V_362 , 1 ) ;
}
static int F_122 ( struct V_290 * V_290 , void * V_291 ,
struct V_404 * V_256 )
{
struct V_6 * V_324 = F_88 ( V_290 ) ;
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 == V_405 )
return - V_97 ;
F_123 ( V_256 -> V_406 , L_20 , sizeof( V_256 -> V_406 ) ) ;
F_123 ( V_256 -> V_407 , V_10 -> V_408 -> V_302 , sizeof( V_256 -> V_407 ) ) ;
snprintf ( V_256 -> V_409 , sizeof( V_256 -> V_409 ) ,
L_21 , F_124 ( V_10 -> V_11 . V_410 ) ) ;
V_256 -> V_411 =
V_412 |
V_413 |
V_414 |
V_415 ;
if ( V_403 <= 0 )
V_256 -> V_411 |= V_416 ;
if ( V_10 -> V_417 )
V_256 -> V_411 |= V_418 ;
if ( V_10 -> V_419 )
V_256 -> V_411 |= V_420 ;
if ( V_10 -> V_421 )
V_256 -> V_411 |= V_422 ;
if ( V_10 -> V_170 != V_171 )
V_256 -> V_411 |= V_423 ;
if ( V_324 -> V_424 == V_425 )
V_256 -> V_426 = V_256 -> V_411 &
( V_412 |
V_413 |
V_414 |
V_416 |
V_423 ) ;
else if ( V_324 -> V_424 == V_427 )
V_256 -> V_426 = V_256 -> V_411 &
( V_418 |
V_413 |
V_414 |
V_423 ) ;
else {
V_256 -> V_426 = V_420 | V_423 ;
if ( V_10 -> V_421 )
V_256 -> V_426 |= V_413 |
V_422 ;
}
return 0 ;
}
static int F_125 ( struct V_428 * V_294 )
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
V_294 -> V_396 = V_246 [ V_53 ] . V_244 ;
F_123 ( V_294 -> V_429 , V_246 [ V_53 ] . V_302 , sizeof( V_294 -> V_429 ) ) ;
return V_53 ;
}
static int F_126 ( struct V_290 * V_290 , void * V_291 ,
struct V_428 * V_294 )
{
int V_265 = F_125 ( V_294 ) ;
if ( V_265 < 0 )
return V_265 ;
return 0 ;
}
static int F_127 ( struct V_290 * V_290 , void * V_291 ,
struct V_428 * V_294 )
{
int V_265 ;
if ( V_403 > 0 ) {
F_19 ( L_19 ) ;
return - V_97 ;
}
V_265 = F_125 ( V_294 ) ;
if ( V_265 < 0 )
return V_265 ;
if ( ! ( V_246 [ V_265 ] . V_164 & V_375 ) )
return - V_97 ;
return 0 ;
}
static int F_128 ( struct V_290 * V_290 , void * V_294 ,
struct V_430 * V_431 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
* V_431 = V_10 -> V_279 ;
V_431 -> V_432 = V_433 ;
V_431 -> V_164 = V_434 ;
if ( V_17 -> V_370 )
V_431 -> V_260 . V_396 = V_17 -> V_370 -> V_244 ;
return 0 ;
}
static int F_129 ( struct V_290 * V_290 , void * V_294 , unsigned int V_435 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_247 * V_248 ;
int V_250 = 0 ;
if ( V_435 ) {
if ( F_130 ( ! V_10 -> V_279 . V_379 ) ) {
return - V_97 ;
}
if ( F_130 ( ! V_17 -> V_380 . V_382 ) ) {
F_22 ( L_22 , V_10 -> V_11 . V_58 ) ;
V_250 = - V_97 ;
}
if ( V_250 )
return V_250 ;
}
if ( ! F_11 ( V_10 , V_17 , V_257 ) )
return - V_360 ;
if ( V_435 ) {
V_17 -> V_380 . V_35 = V_10 -> V_35 ;
V_248 = F_109 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_110 ( V_10 , & V_17 -> V_380 , V_17 -> V_370 , V_248 ) ;
} else {
V_248 = NULL ;
}
V_250 = F_64 ( V_10 , V_17 , V_248 ) ;
return V_250 ;
}
static int F_131 ( struct V_290 * V_290 , void * V_294 ,
const struct V_430 * V_431 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_243 * V_260 ;
int V_250 ;
if ( ! F_94 ( V_341 ) &&
! F_94 ( V_436 ) )
return - V_342 ;
V_260 = F_63 ( V_431 -> V_260 . V_396 ) ;
if ( NULL == V_260 )
return - V_97 ;
if ( 0 == ( V_260 -> V_164 & V_375 ) )
return - V_97 ;
V_250 = - V_97 ;
if ( V_431 -> V_164 & V_437 ) {
T_2 V_144 = V_431 -> V_260 . V_144 ;
T_2 V_39 = V_431 -> V_260 . V_39 ;
V_250 = F_99 ( V_17 , & V_144 , & V_39 ,
V_367 ,
~ 3 ,
2 ,
0 ,
0 ) ;
if ( 0 != V_250 )
return V_250 ;
}
V_10 -> V_279 . V_379 = V_431 -> V_379 ;
V_10 -> V_279 . V_260 . V_144 = V_431 -> V_260 . V_144 ;
V_10 -> V_279 . V_260 . V_39 = V_431 -> V_260 . V_39 ;
if ( 0 != V_431 -> V_260 . V_392 )
V_10 -> V_279 . V_260 . V_392 = V_431 -> V_260 . V_392 ;
else
V_10 -> V_279 . V_260 . V_392 = V_10 -> V_279 . V_260 . V_144 * V_260 -> V_275 / 8 ;
V_250 = 0 ;
V_17 -> V_370 = V_260 ;
V_10 -> V_383 . V_370 = V_260 ;
if ( V_431 -> V_164 & V_437 ) {
V_17 -> V_380 . V_363 . V_277 = 0 ;
V_17 -> V_380 . V_363 . V_25 = 0 ;
V_17 -> V_380 . V_363 . V_144 = V_431 -> V_260 . V_144 ;
V_17 -> V_380 . V_363 . V_39 = V_431 -> V_260 . V_39 ;
V_10 -> V_383 . V_380 . V_363 . V_144 = V_431 -> V_260 . V_144 ;
V_10 -> V_383 . V_380 . V_363 . V_39 = V_431 -> V_260 . V_39 ;
F_66 ( V_17 -> V_380 . V_373 ) ;
V_17 -> V_380 . V_373 = NULL ;
V_17 -> V_380 . V_381 = 0 ;
if ( F_12 ( V_17 , V_257 ) ) {
struct V_247 * V_248 ;
V_248 = F_109 ( sizeof( * V_248 ) ) ;
V_248 -> V_26 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
F_110 ( V_10 , & V_17 -> V_380 , V_17 -> V_370 , V_248 ) ;
V_250 = F_64 ( V_10 , V_17 , V_248 ) ;
}
}
return V_250 ;
}
static int F_132 ( struct V_290 * V_290 , void * V_291 ,
struct V_438 * V_439 )
{
struct V_16 * V_17 = V_291 ;
return F_133 ( F_111 ( V_17 ) , V_439 ) ;
}
static int F_134 ( struct V_290 * V_290 , void * V_291 ,
struct V_440 * V_346 )
{
struct V_16 * V_17 = V_291 ;
return F_135 ( F_111 ( V_17 ) , V_346 ) ;
}
static int F_136 ( struct V_290 * V_290 , void * V_291 , struct V_440 * V_346 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_387 = F_112 ( V_17 ) ;
if ( ! F_11 ( V_10 , V_17 , V_387 ) )
return - V_360 ;
return F_137 ( F_111 ( V_17 ) , V_346 ) ;
}
static int F_138 ( struct V_290 * V_290 , void * V_291 , struct V_440 * V_346 )
{
struct V_16 * V_17 = V_291 ;
return F_139 ( F_111 ( V_17 ) , V_346 ,
V_290 -> V_441 & V_442 ) ;
}
static int F_140 ( struct V_290 * V_290 , void * V_291 ,
enum V_389 type )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_387 = F_112 ( V_17 ) ;
if ( ! F_11 ( V_10 , V_17 , V_387 ) )
return - V_360 ;
return F_141 ( F_111 ( V_17 ) ) ;
}
static int F_142 ( struct V_290 * V_290 , void * V_291 ,
enum V_389 type )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
int V_250 ;
int V_387 = F_112 ( V_17 ) ;
V_250 = F_143 ( F_111 ( V_17 ) ) ;
if ( V_250 < 0 )
return V_250 ;
F_18 ( V_10 , V_17 , V_387 ) ;
return 0 ;
}
static int F_144 ( struct V_290 * V_290 , void * V_294 ,
struct V_443 * V_444 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_444 -> type != V_384 )
return - V_97 ;
V_444 -> V_444 . V_287 . V_445 = V_282 ;
F_145 ( V_36 [ V_10 -> V_35 ] . V_161 ,
& V_444 -> V_444 . V_287 . V_446 ) ;
return 0 ;
}
static int F_146 ( struct V_290 * V_290 , void * V_291 ,
struct V_310 * V_311 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 != V_311 -> V_299 )
return - V_97 ;
V_311 -> V_447 = V_448 ;
V_311 -> V_432 = V_449 ;
F_51 ( V_10 , V_288 , V_450 , V_311 ) ;
strcpy ( V_311 -> V_302 , L_16 ) ;
V_311 -> type = V_451 ;
if ( F_16 ( V_62 ) & V_107 )
V_311 -> signal = 0xffff ;
if ( V_10 -> V_313 )
V_10 -> V_313 ( V_10 , V_311 , 0 ) ;
return 0 ;
}
static int F_147 ( struct V_290 * V_290 , void * V_291 ,
struct V_452 * V_256 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_256 -> type != V_384 &&
V_256 -> type != V_453 )
return - V_97 ;
* V_256 = V_36 [ V_10 -> V_35 ] . V_37 ;
return 0 ;
}
static int F_148 ( struct V_290 * V_290 , void * V_294 , struct V_454 * V_26 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( V_26 -> type != V_384 &&
V_26 -> type != V_453 )
return - V_97 ;
V_26 -> V_11 = V_10 -> V_26 [ ! ! V_17 -> V_27 ] . V_28 ;
return 0 ;
}
static int F_149 ( struct V_290 * V_290 , void * V_294 , const struct V_454 * V_26 )
{
struct V_16 * V_17 = V_294 ;
struct V_9 * V_10 = V_17 -> V_10 ;
const struct V_345 * V_346 ;
int V_250 ;
struct V_141 V_11 ;
T_2 V_455 ;
T_2 V_456 ;
T_2 V_457 ;
T_2 V_458 ;
if ( V_26 -> type != V_384 &&
V_26 -> type != V_453 )
return - V_97 ;
V_250 = - V_360 ;
if ( F_13 ( V_17 -> V_10 , V_24 ) ) {
return V_250 ;
}
V_346 = & V_36 [ V_10 -> V_35 ] . V_37 . V_38 ;
V_455 = V_346 -> V_277 ;
V_457 = V_455 + V_346 -> V_144 ;
V_458 = V_346 -> V_25 + V_346 -> V_39 ;
V_456 = F_46 ( V_346 -> V_25 , V_10 -> V_29 ) ;
if ( V_456 + 32 >= V_458 ) {
return V_250 ;
}
V_11 . V_28 . V_277 = F_150 ( V_459 , V_26 -> V_11 . V_277 , V_455 , V_457 - 48 ) ;
V_11 . V_28 . V_277 = F_98 ( V_11 . V_28 . V_277 , ( T_2 ) V_350 ) ;
V_11 . V_28 . V_144 = F_150 ( V_459 , V_26 -> V_11 . V_144 ,
48 , V_457 - V_11 . V_28 . V_277 ) ;
V_11 . V_28 . V_25 = F_150 ( V_459 , V_26 -> V_11 . V_25 , V_456 , V_458 - 32 ) ;
V_11 . V_28 . V_25 = ( V_11 . V_28 . V_25 + 1 ) & ~ 1 ;
V_11 . V_28 . V_39 = F_150 ( V_459 , V_26 -> V_11 . V_39 ,
32 , V_458 - V_11 . V_28 . V_25 ) ;
V_11 . V_28 . V_39 = ( V_11 . V_28 . V_39 + 1 ) & ~ 1 ;
F_45 ( & V_11 ) ;
V_10 -> V_26 [ 1 ] = V_11 ;
V_17 -> V_27 = 1 ;
if ( V_17 -> V_144 < V_11 . V_142 ) {
V_17 -> V_144 = V_11 . V_142 ;
V_10 -> V_383 . V_144 = V_11 . V_142 ;
} else if ( V_17 -> V_144 > V_11 . V_145 ) {
V_17 -> V_144 = V_11 . V_145 ;
V_10 -> V_383 . V_144 = V_11 . V_145 ;
}
if ( V_17 -> V_39 < V_11 . V_143 ) {
V_17 -> V_39 = V_11 . V_143 ;
V_10 -> V_383 . V_39 = V_11 . V_143 ;
} else if ( V_17 -> V_39 > V_11 . V_146 ) {
V_17 -> V_39 = V_11 . V_146 ;
V_10 -> V_383 . V_39 = V_11 . V_146 ;
}
return 0 ;
}
static T_1 F_151 ( struct V_290 * V_290 , char T_7 * V_237 ,
T_8 V_281 , T_9 * V_460 )
{
struct V_16 * V_17 = V_290 -> V_461 ;
int V_250 = 0 ;
if ( V_17 -> V_10 -> V_199 )
F_58 ( V_17 -> V_10 ) ;
F_22 ( L_23 ,
V_17 -> V_10 -> V_11 . V_58 , ( int ) V_281 , V_462 [ V_17 -> type ] ) ;
switch ( V_17 -> type ) {
case V_384 :
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_21 ) ) {
return - V_360 ;
}
V_250 = F_152 ( & V_17 -> V_256 , V_237 , V_281 , V_460 ,
V_290 -> V_441 & V_442 ) ;
F_18 ( V_17 -> V_10 , V_17 , V_21 ) ;
break;
case V_385 :
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_388 ) )
return - V_360 ;
V_250 = F_153 ( & V_17 -> V_386 , V_237 , V_281 , V_460 , 1 ,
V_290 -> V_441 & V_442 ) ;
break;
default:
F_102 () ;
}
return V_250 ;
}
static unsigned int F_154 ( struct V_290 * V_290 , T_10 * V_463 )
{
struct V_16 * V_17 = V_290 -> V_461 ;
struct V_247 * V_5 ;
enum V_261 V_262 ;
unsigned int V_265 = 0 ;
unsigned long V_464 = F_155 ( V_463 ) ;
if ( F_156 ( & V_17 -> V_17 ) )
V_265 = V_465 ;
else if ( V_464 & V_465 )
F_157 ( V_290 , & V_17 -> V_17 . V_463 , V_463 ) ;
if ( ! ( V_464 & ( V_466 | V_467 ) ) )
return V_265 ;
if ( V_385 == V_17 -> type ) {
if ( ! F_11 ( V_17 -> V_10 , V_17 , V_388 ) )
return V_265 | V_468 ;
return V_265 | F_158 ( V_290 , & V_17 -> V_386 , V_463 ) ;
}
if ( F_12 ( V_17 , V_22 ) ) {
if ( F_159 ( & V_17 -> V_256 . V_469 ) )
return V_265 | V_468 ;
V_5 = F_160 ( V_17 -> V_256 . V_469 . V_470 , struct V_247 , V_251 . V_469 ) ;
} else {
if ( NULL == V_17 -> V_256 . V_471 ) {
if ( F_13 ( V_17 -> V_10 , V_22 ) )
return V_265 | V_468 ;
V_17 -> V_256 . V_471 = F_109 ( V_17 -> V_256 . V_472 ) ;
if ( NULL == V_17 -> V_256 . V_471 )
return V_265 | V_468 ;
V_17 -> V_256 . V_471 -> V_473 = V_474 ;
V_262 = F_161 ( & V_17 -> V_256 ) ;
if ( 0 != V_17 -> V_256 . V_475 -> V_476 ( & V_17 -> V_256 , V_17 -> V_256 . V_471 , V_262 ) ) {
F_66 ( V_17 -> V_256 . V_471 ) ;
V_17 -> V_256 . V_471 = NULL ;
return V_265 | V_468 ;
}
V_17 -> V_256 . V_475 -> V_477 ( & V_17 -> V_256 , V_17 -> V_256 . V_471 ) ;
V_17 -> V_256 . V_478 = 0 ;
}
V_5 = (struct V_247 * ) V_17 -> V_256 . V_471 ;
}
F_157 ( V_290 , & V_5 -> V_251 . V_479 , V_463 ) ;
if ( V_5 -> V_251 . V_252 == V_253 ||
V_5 -> V_251 . V_252 == V_480 )
V_265 = V_265 | V_466 | V_467 ;
return V_265 ;
}
static int F_162 ( struct V_290 * V_290 )
{
struct V_6 * V_324 = F_88 ( V_290 ) ;
struct V_9 * V_10 = F_163 ( V_290 ) ;
struct V_16 * V_17 ;
enum V_389 type = 0 ;
F_22 ( L_24 , F_164 ( V_324 ) ) ;
if ( V_324 -> V_424 == V_425 ) {
type = V_384 ;
} else if ( V_324 -> V_424 == V_427 ) {
type = V_385 ;
} else {
F_165 ( 1 ) ;
return - V_481 ;
}
F_22 ( L_25 ,
V_10 -> V_11 . V_58 , V_462 [ type ] ) ;
V_17 = F_104 ( sizeof( * V_17 ) , V_376 ) ;
if ( F_130 ( ! V_17 ) )
return - V_377 ;
V_10 -> V_109 ++ ;
V_290 -> V_461 = V_17 ;
* V_17 = V_10 -> V_383 ;
F_166 ( & V_17 -> V_17 , V_324 ) ;
V_17 -> type = type ;
V_17 -> V_380 . V_382 = 0 ;
F_167 ( & V_17 -> V_256 , & V_482 ,
& V_10 -> V_11 . V_410 -> V_8 , & V_10 -> V_166 ,
V_384 ,
V_367 ,
sizeof( struct V_247 ) ,
V_17 , & V_10 -> V_483 ) ;
F_167 ( & V_17 -> V_386 , & V_484 ,
& V_10 -> V_11 . V_410 -> V_8 , & V_10 -> V_166 ,
V_385 ,
V_400 ,
sizeof( struct V_247 ) ,
V_17 , & V_10 -> V_483 ) ;
F_48 ( V_10 , V_10 -> V_35 ) ;
F_52 ( V_10 , V_10 -> V_69 , V_10 -> V_35 ) ;
F_40 ( V_10 , V_10 -> V_103 ) ;
V_17 -> V_27 = ! V_485 ;
F_168 ( & V_17 -> V_33 , V_10 -> V_35 ) ;
F_62 ( V_10 ) ;
F_169 ( & V_17 -> V_17 ) ;
return 0 ;
}
static int F_170 ( struct V_290 * V_290 )
{
struct V_16 * V_17 = V_290 -> V_461 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( F_12 ( V_17 , V_257 ) )
F_64 ( V_10 , V_17 , NULL ) ;
if ( F_12 ( V_17 , V_22 ) ) {
F_143 ( & V_17 -> V_256 ) ;
F_18 ( V_10 , V_17 , V_22 ) ;
}
if ( V_17 -> V_256 . V_471 ) {
F_74 ( & V_17 -> V_256 , V_17 -> V_256 . V_471 ) ;
F_66 ( V_17 -> V_256 . V_471 ) ;
}
if ( F_12 ( V_17 , V_21 ) ) {
F_18 ( V_10 , V_17 , V_21 ) ;
}
if ( F_12 ( V_17 , V_388 ) ) {
F_171 ( & V_17 -> V_386 ) ;
F_18 ( V_10 , V_17 , V_388 ) ;
}
F_172 ( & V_17 -> V_256 ) ;
F_172 ( & V_17 -> V_386 ) ;
V_290 -> V_461 = NULL ;
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
F_175 ( struct V_290 * V_290 , struct V_486 * V_487 )
{
struct V_16 * V_17 = V_290 -> V_461 ;
F_22 ( L_26 ,
V_17 -> V_10 -> V_11 . V_58 , V_462 [ V_17 -> type ] ,
V_487 -> V_488 , V_487 -> V_489 - V_487 -> V_488 ) ;
return F_176 ( F_111 ( V_17 ) , V_487 ) ;
}
static int F_177 ( struct V_290 * V_290 )
{
struct V_6 * V_324 = F_88 ( V_290 ) ;
struct V_9 * V_10 = F_163 ( V_290 ) ;
struct V_16 * V_17 ;
F_22 ( L_24 , F_164 ( V_324 ) ) ;
F_22 ( L_27 , V_10 -> V_11 . V_58 ) ;
V_17 = F_104 ( sizeof( * V_17 ) , V_376 ) ;
if ( F_130 ( ! V_17 ) )
return - V_377 ;
V_290 -> V_461 = V_17 ;
* V_17 = V_10 -> V_383 ;
F_166 ( & V_17 -> V_17 , V_324 ) ;
V_10 -> V_490 ++ ;
F_40 ( V_10 , V_10 -> V_103 ) ;
F_169 ( & V_17 -> V_17 ) ;
return 0 ;
}
static int F_178 ( struct V_290 * V_290 )
{
struct V_16 * V_17 = V_290 -> V_461 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_491 V_492 ;
V_290 -> V_461 = NULL ;
F_173 ( & V_17 -> V_17 ) ;
F_174 ( & V_17 -> V_17 ) ;
F_66 ( V_17 ) ;
V_10 -> V_490 -- ;
F_51 ( V_10 , V_162 , V_493 , V_494 , & V_492 ) ;
if ( V_10 -> V_490 == 0 )
V_10 -> V_110 = 0 ;
return 0 ;
}
static int F_179 ( struct V_290 * V_290 , void * V_291 , struct V_310 * V_311 )
{
struct V_16 * V_17 = V_291 ;
struct V_9 * V_10 = V_17 -> V_10 ;
if ( 0 != V_311 -> V_299 )
return - V_97 ;
strcpy ( V_311 -> V_302 , L_28 ) ;
V_311 -> type = V_316 ;
F_75 ( V_10 ) ;
F_51 ( V_10 , V_288 , V_450 , V_311 ) ;
if ( V_10 -> V_313 )
V_10 -> V_313 ( V_10 , V_311 , 0 ) ;
return 0 ;
}
static int F_180 ( struct V_290 * V_290 , void * V_291 ,
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
static T_1 F_181 ( struct V_290 * V_290 , char T_7 * V_237 ,
T_8 V_281 , T_9 * V_460 )
{
struct V_16 * V_17 = V_290 -> V_461 ;
struct V_9 * V_10 = V_17 -> V_10 ;
struct V_491 V_492 ;
V_492 . V_495 = V_281 / 3 ;
V_492 . V_496 = V_237 ;
V_492 . V_497 = V_290 ;
V_492 . V_498 = - V_481 ;
F_75 ( V_10 ) ;
F_51 ( V_10 , V_162 , V_493 , V_499 , & V_492 ) ;
return V_492 . V_498 ;
}
static unsigned int F_182 ( struct V_290 * V_290 , T_10 * V_463 )
{
struct V_16 * V_17 = V_290 -> V_461 ;
struct V_9 * V_10 = V_17 -> V_10 ;
unsigned long V_464 = F_155 ( V_463 ) ;
struct V_491 V_492 ;
unsigned int V_387 = 0 ;
if ( F_156 ( & V_17 -> V_17 ) )
V_387 = V_465 ;
else if ( V_464 & V_465 )
F_157 ( V_290 , & V_17 -> V_17 . V_463 , V_463 ) ;
F_75 ( V_10 ) ;
V_492 . V_497 = V_290 ;
V_492 . V_500 = V_463 ;
V_492 . V_498 = V_387 ;
F_51 ( V_10 , V_162 , V_493 , V_501 , & V_492 ) ;
return V_492 . V_498 ;
}
static int F_183 ( T_4 V_502 )
{
static char * V_503 [ 16 ] = {
[ V_504 >> 28 ] = L_29 ,
[ V_505 >> 28 ] = L_30 ,
[ V_506 >> 28 ] = L_31 ,
[ V_507 >> 28 ] = L_32 ,
[ V_508 >> 28 ] = L_33 ,
[ V_509 >> 28 ] = L_34 ,
[ V_510 >> 28 ] = L_35 ,
[ V_511 >> 28 ] = L_36 ,
} ;
static int V_512 [ 16 ] = {
[ V_504 >> 28 ] = 2 ,
[ V_507 >> 28 ] = 2 ,
[ V_508 >> 28 ] = 2 ,
[ V_509 >> 28 ] = 5 ,
[ V_510 >> 28 ] = 2 ,
[ V_511 >> 28 ] = 3 ,
} ;
static char * V_44 [] = {
L_37 , L_38 , L_39 , L_40 ,
L_41 , L_42 , L_43 , L_44 ,
L_45 , L_46 , L_47 , L_48 ,
L_49 , L_50 , L_51 , L_52 ,
} ;
int V_53 ;
F_184 ( L_53 , V_502 ,
V_503 [ V_502 >> 28 ] ? V_503 [ V_502 >> 28 ] : L_54 ) ;
for ( V_53 = F_185 ( V_44 ) - 1 ; V_53 >= 0 ; V_53 -- )
if ( V_502 & ( 1 << ( V_53 + 12 ) ) )
F_184 ( L_55 , V_44 [ V_53 ] ) ;
F_184 ( L_56 , V_502 & 0xfff ) ;
return V_512 [ V_502 >> 28 ] ? V_512 [ V_502 >> 28 ] : 1 ;
}
static void F_186 ( struct V_9 * V_10 ,
struct V_513 * V_502 )
{
unsigned int V_53 , V_514 , V_374 ;
F_23 ( L_57 ,
V_10 -> V_11 . V_325 . V_302 , V_502 -> V_515 , ( unsigned long ) V_502 -> V_516 ) ;
for ( V_53 = 0 ; V_53 < ( V_502 -> V_271 >> 2 ) ; V_53 += V_374 ) {
F_23 ( L_58 ,
V_10 -> V_11 . V_325 . V_302 ,
( unsigned long ) ( V_502 -> V_516 + ( V_53 << 2 ) ) ) ;
V_374 = F_183 ( F_187 ( V_502 -> V_515 [ V_53 ] ) ) ;
for ( V_514 = 1 ; V_514 < V_374 ; V_514 ++ )
F_23 ( L_59 ,
V_10 -> V_11 . V_325 . V_302 ,
( unsigned long ) ( V_502 -> V_516 + ( ( V_53 + V_514 ) << 2 ) ) ,
V_502 -> V_515 [ V_53 + V_514 ] , V_514 ) ;
if ( 0 == V_502 -> V_515 [ V_53 ] )
break;
}
}
static void F_188 ( struct V_9 * V_10 )
{
F_23 ( L_60 , ( unsigned long long ) V_10 -> main. V_516 ) ;
F_23 ( L_61 ,
V_10 -> V_517 ? ( unsigned long long ) V_10 -> V_517 -> V_25 . V_516 : 0 ,
V_10 -> V_517 ? ( unsigned long long ) V_10 -> V_517 -> V_518 . V_516 : 0 ) ;
F_23 ( L_62 ,
V_10 -> V_167 . V_25
? ( unsigned long long ) V_10 -> V_167 . V_25 -> V_25 . V_516 : 0 ,
V_10 -> V_167 . V_518
? ( unsigned long long ) V_10 -> V_167 . V_518 -> V_518 . V_516 : 0 ) ;
F_23 ( L_63 ,
V_10 -> V_254 ? ( unsigned long long ) V_10 -> V_254 -> V_25 . V_516 : 0 ,
V_10 -> V_254 ? ( unsigned long long ) V_10 -> V_254 -> V_518 . V_516 : 0 ) ;
F_186 ( V_10 , & V_10 -> main ) ;
}
static void F_189 ( T_4 V_519 , T_4 V_520 )
{
unsigned int V_53 ;
F_184 ( L_64 ) ;
for ( V_53 = 0 ; V_53 < F_185 ( V_521 ) ; V_53 ++ ) {
if ( V_519 & ( 1 << V_53 ) )
F_184 ( L_55 , V_521 [ V_53 ] ) ;
if ( V_520 & ( 1 << V_53 ) )
F_184 ( L_65 ) ;
}
}
static void F_190 ( struct V_9 * V_10 , T_4 V_265 )
{
F_191 ( L_66 ,
V_10 -> V_11 . V_58 ,
( unsigned long ) V_10 -> main. V_516 ,
( unsigned long ) F_187 ( V_10 -> main. V_515 [ V_522 + 1 ] ) ,
( unsigned long ) F_187 ( V_10 -> main. V_515 [ V_523 + 1 ] ) ,
( unsigned long ) V_265 ) ;
if ( 0 == ( F_16 ( V_62 ) & V_107 ) ) {
F_192 ( L_67
L_68 ,
V_10 -> V_11 . V_58 ) ;
return;
}
F_192 ( L_69 ,
V_10 -> V_11 . V_58 ) ;
F_192 ( L_70 ,
V_10 -> V_11 . V_58 ) ;
F_193 () ;
}
static int
F_194 ( struct V_9 * V_10 , struct V_524 * V_525 )
{
struct V_247 * V_526 ;
memset ( V_525 , 0 , sizeof( * V_525 ) ) ;
if ( ! F_159 ( & V_10 -> V_287 ) ) {
V_525 -> V_168 = 1 ;
V_526 = F_160 ( V_10 -> V_287 . V_470 , struct V_247 , V_251 . V_286 ) ;
if ( F_195 ( V_526 -> V_251 . V_262 ) )
V_525 -> V_25 = V_526 ;
if ( F_196 ( V_526 -> V_251 . V_262 ) )
V_525 -> V_518 = V_526 ;
if ( ! F_97 ( V_526 -> V_251 . V_262 ) &&
( V_526 -> V_251 . V_286 . V_470 != & V_10 -> V_287 ) ) {
V_526 = F_160 ( V_526 -> V_251 . V_286 . V_470 , struct V_247 , V_251 . V_286 ) ;
if ( ! F_97 ( V_526 -> V_251 . V_262 ) ) {
if ( NULL == V_525 -> V_518 &&
V_273 == V_526 -> V_251 . V_262 ) {
V_525 -> V_518 = V_526 ;
}
if ( NULL != V_525 -> V_25 && NULL != V_525 -> V_518 )
V_525 -> V_527 = 2 ;
}
}
}
if ( NULL != V_10 -> V_254 ) {
if ( F_97 ( V_10 -> V_254 -> V_251 . V_262 ) ) {
if ( NULL == V_525 -> V_25 && NULL == V_525 -> V_518 ) {
V_525 -> V_25 = V_10 -> V_254 ;
V_525 -> V_518 = V_10 -> V_254 ;
}
} else {
if ( V_272 == V_10 -> V_254 -> V_251 . V_262 &&
NULL == V_525 -> V_25 ) {
V_525 -> V_25 = V_10 -> V_254 ;
}
if ( V_273 == V_10 -> V_254 -> V_251 . V_262 &&
NULL == V_525 -> V_518 ) {
V_525 -> V_518 = V_10 -> V_254 ;
}
}
}
F_22 ( L_71 ,
V_10 -> V_11 . V_58 , V_525 -> V_25 , V_525 -> V_518 ,
V_10 -> V_254 , V_525 -> V_168 , V_525 -> V_527 ) ;
return 0 ;
}
static void
F_197 ( struct V_9 * V_10 , struct V_524 * V_528 ,
struct V_524 * V_167 , unsigned int V_252 )
{
struct V_529 V_530 ;
F_198 ( & V_530 ) ;
if ( V_528 -> V_25 == V_528 -> V_518 ) {
if ( NULL != V_528 -> V_25 && V_167 -> V_25 != V_528 -> V_25 ) {
if ( V_531 > 1 )
F_61 ( L_72 ,
V_10 -> V_11 . V_58 , V_528 -> V_25 ) ;
V_528 -> V_25 -> V_251 . V_530 = V_530 ;
V_528 -> V_25 -> V_251 . V_242 = V_10 -> V_242 ;
V_528 -> V_25 -> V_251 . V_252 = V_252 ;
F_199 ( & V_528 -> V_25 -> V_251 . V_479 ) ;
}
} else {
if ( NULL != V_528 -> V_25 && V_167 -> V_25 != V_528 -> V_25 ) {
if ( V_531 > 1 )
F_61 ( L_73 ,
V_10 -> V_11 . V_58 , V_528 -> V_25 ) ;
V_528 -> V_25 -> V_251 . V_530 = V_530 ;
V_528 -> V_25 -> V_251 . V_242 = V_10 -> V_242 ;
V_528 -> V_25 -> V_251 . V_252 = V_252 ;
F_199 ( & V_528 -> V_25 -> V_251 . V_479 ) ;
}
if ( NULL != V_528 -> V_518 && V_167 -> V_518 != V_528 -> V_518 ) {
if ( V_531 > 1 )
F_61 ( L_74 ,
V_10 -> V_11 . V_58 , V_528 -> V_518 ) ;
V_528 -> V_518 -> V_251 . V_530 = V_530 ;
V_528 -> V_518 -> V_251 . V_242 = V_10 -> V_242 ;
V_528 -> V_518 -> V_251 . V_252 = V_252 ;
F_199 ( & V_528 -> V_518 -> V_251 . V_479 ) ;
}
}
}
static void
F_200 ( struct V_9 * V_10 , struct V_247 * V_528 ,
unsigned int V_252 )
{
struct V_529 V_530 ;
if ( NULL == V_528 )
return;
F_198 ( & V_530 ) ;
V_528 -> V_251 . V_530 = V_530 ;
V_528 -> V_251 . V_242 = V_10 -> V_242 ;
V_528 -> V_251 . V_252 = V_252 ;
F_199 ( & V_528 -> V_251 . V_479 ) ;
}
static void F_201 ( unsigned long V_237 )
{
struct V_9 * V_10 = (struct V_9 * ) V_237 ;
struct V_524 V_249 , V_248 ;
struct V_247 * V_532 ;
struct V_247 * V_526 ;
unsigned long V_164 ;
if ( V_60 ) {
F_23 ( L_75 ,
V_10 -> V_11 . V_58 , V_10 -> V_533 , V_10 -> V_534 , V_10 -> V_535 ,
F_16 ( V_536 ) ) ;
F_189 ( F_16 ( V_172 ) , 0 ) ;
F_184 ( L_76 ) ;
}
F_53 ( & V_10 -> V_166 , V_164 ) ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_249 = V_10 -> V_167 ;
V_532 = V_10 -> V_517 ;
V_10 -> V_167 = V_248 ;
V_10 -> V_517 = NULL ;
V_10 -> V_255 = 0 ;
F_202 ( V_10 , & V_248 ) ;
F_203 ( V_10 , NULL ) ;
F_59 ( V_10 , 0 ) ;
F_197 ( V_10 , & V_249 , & V_248 , V_480 ) ;
F_200 ( V_10 , V_532 , V_480 ) ;
while ( ! F_159 ( & V_10 -> V_287 ) ) {
V_526 = F_160 ( V_10 -> V_287 . V_470 , struct V_247 , V_251 . V_286 ) ;
F_204 ( & V_526 -> V_251 . V_286 ) ;
V_526 -> V_251 . V_252 = V_480 ;
F_199 ( & V_526 -> V_251 . V_479 ) ;
}
while ( ! F_159 ( & V_10 -> V_537 ) ) {
V_526 = F_160 ( V_10 -> V_537 . V_470 , struct V_247 , V_251 . V_286 ) ;
F_204 ( & V_526 -> V_251 . V_286 ) ;
V_526 -> V_251 . V_252 = V_480 ;
F_199 ( & V_526 -> V_251 . V_479 ) ;
}
V_10 -> V_199 ++ ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
}
static void
F_205 ( struct V_9 * V_10 )
{
struct V_247 * V_528 = V_10 -> V_167 . V_25 ;
if ( NULL == V_528 )
return;
F_206 ( & V_10 -> V_166 ) ;
V_10 -> V_167 . V_527 = 0 ;
V_10 -> V_167 . V_25 = NULL ;
F_207 ( V_10 , V_523 , NULL , 0 ) ;
F_198 ( & V_528 -> V_251 . V_530 ) ;
V_528 -> V_251 . V_242 = V_10 -> V_242 ;
V_528 -> V_251 . V_252 = V_253 ;
F_199 ( & V_528 -> V_251 . V_479 ) ;
F_208 ( & V_10 -> V_166 ) ;
}
static inline int F_209 ( struct V_513 * V_502 , T_4 V_265 )
{
if ( V_265 < V_502 -> V_516 )
return 0 ;
if ( V_265 > V_502 -> V_516 + V_502 -> V_271 )
return 0 ;
return 1 ;
}
static void
F_210 ( struct V_9 * V_10 )
{
struct V_524 V_248 ;
struct V_524 V_249 ;
T_11 V_265 ;
F_206 ( & V_10 -> V_166 ) ;
F_194 ( V_10 , & V_248 ) ;
V_265 = F_16 ( V_536 ) ;
if ( ( V_10 -> V_167 . V_25 && F_209 ( & V_10 -> V_167 . V_25 -> V_25 , V_265 ) ) ||
( V_10 -> V_167 . V_518 && F_209 ( & V_10 -> V_167 . V_518 -> V_518 , V_265 ) ) ) {
V_10 -> V_533 ++ ;
if ( V_538 )
F_190 ( V_10 , V_265 ) ;
F_208 ( & V_10 -> V_166 ) ;
return;
}
V_249 = V_10 -> V_167 ;
V_10 -> V_167 = V_248 ;
V_10 -> V_255 &= ~ 1 ;
F_202 ( V_10 , & V_248 ) ;
F_59 ( V_10 , 0 ) ;
if ( V_12 != V_10 -> V_169 ) {
F_31 ( V_10 , V_10 -> V_169 ) ;
V_10 -> V_169 = V_12 ;
}
F_197 ( V_10 , & V_249 , & V_248 , V_253 ) ;
F_208 ( & V_10 -> V_166 ) ;
}
static void
F_211 ( struct V_9 * V_10 )
{
struct V_247 * V_248 = NULL ;
struct V_247 * V_249 ;
T_4 V_265 ;
F_206 ( & V_10 -> V_166 ) ;
if ( ! F_159 ( & V_10 -> V_537 ) )
V_248 = F_160 ( V_10 -> V_537 . V_470 , struct V_247 , V_251 . V_286 ) ;
V_249 = V_10 -> V_517 ;
V_265 = F_16 ( V_536 ) ;
if ( NULL != V_249 && ( F_209 ( & V_249 -> V_25 , V_265 ) ||
F_209 ( & V_249 -> V_518 , V_265 ) ) ) {
V_10 -> V_533 ++ ;
if ( V_538 )
F_190 ( V_10 , V_265 ) ;
F_208 ( & V_10 -> V_166 ) ;
return;
}
V_10 -> V_517 = V_248 ;
V_10 -> V_255 &= ~ 4 ;
F_203 ( V_10 , V_248 ) ;
F_59 ( V_10 , 0 ) ;
F_200 ( V_10 , V_249 , V_253 ) ;
F_208 ( & V_10 -> V_166 ) ;
}
static T_12 F_212 ( int V_539 , void * V_540 )
{
T_4 V_541 , V_542 ;
T_4 V_543 ;
int V_281 ;
struct V_9 * V_10 ;
int V_544 = 0 ;
V_10 = (struct V_9 * ) V_540 ;
V_281 = 0 ;
while ( 1 ) {
V_541 = F_16 ( V_172 ) ;
V_542 = V_541 & F_16 ( V_175 ) ;
if ( ! V_542 )
break;
V_544 = 1 ;
F_17 ( V_541 , V_172 ) ;
V_543 = F_16 ( V_62 ) ;
if ( V_531 ) {
F_61 ( L_77 ,
V_10 -> V_11 . V_58 , V_281 , V_10 -> V_242 ,
V_541 >> 28 , F_16 ( V_536 ) ) ;
F_189 ( V_541 , V_542 ) ;
if ( V_541 & V_185 )
F_184 ( L_78 ,
V_543 & V_107
? L_79 : L_80 ) ;
if ( V_541 & V_545 )
F_184 ( L_81 ,
V_543 & V_305
? L_79 : L_80 ) ;
if ( V_541 & V_184 )
F_184 ( L_82 ,
V_543 & V_295
? L_83 : L_84 ) ;
F_184 ( L_76 ) ;
}
if ( V_542 & V_241 )
V_10 -> V_242 ++ ;
if ( ( V_542 & V_178 ) && V_10 -> V_546 ) {
F_213 ( V_10 ) ;
}
if ( V_542 & V_174 ) {
V_10 -> V_547 = V_541 ;
F_199 ( & V_10 -> V_548 ) ;
}
if ( ( V_542 & V_182 ) && ( V_541 & ( 4 << 28 ) ) )
F_211 ( V_10 ) ;
if ( ( V_542 & V_182 ) && ( V_541 & ( 2 << 28 ) ) )
F_205 ( V_10 ) ;
if ( ( V_542 & V_182 ) && ( V_541 & ( 1 << 28 ) ) )
F_210 ( V_10 ) ;
if ( ( V_542 & V_185 ) && V_10 -> V_108 )
F_36 ( V_10 , V_10 -> V_119 , V_10 -> V_103 ) ;
if ( V_542 & ( V_179 | V_183 ) ) {
F_23 ( L_85 ,
V_10 -> V_11 . V_58 ,
( V_542 & V_179 ) ? L_86 : L_87 ,
( V_542 & V_183 ) ? L_88 : L_87 ,
F_16 ( V_536 ) ) ;
F_189 ( V_541 , V_542 ) ;
F_184 ( L_76 ) ;
if ( V_549 )
F_188 ( V_10 ) ;
}
if ( V_180 && V_542 & V_181 ) {
F_23 ( L_89 ,
V_10 -> V_11 . V_58 , F_16 ( V_536 ) ) ;
if ( V_549 )
F_188 ( V_10 ) ;
}
V_281 ++ ;
if ( V_281 > 4 ) {
if ( V_281 > 8 || ! ( V_542 & V_178 ) ) {
F_17 ( 0 , V_175 ) ;
F_19 ( L_90 ,
V_10 -> V_11 . V_58 ) ;
} else {
F_19 ( L_91 ,
V_10 -> V_11 . V_58 ) ;
F_17 ( F_16 ( V_175 ) & ( - 1 ^ V_178 ) ,
V_175 ) ;
} ;
F_189 ( V_541 , V_542 ) ;
F_184 ( L_92 ) ;
}
}
V_10 -> V_535 ++ ;
if ( V_544 )
V_10 -> V_534 ++ ;
return F_214 ( V_544 ) ;
}
static struct V_6 * F_215 ( struct V_9 * V_10 ,
const struct V_6 * V_550 ,
const char * V_551 )
{
struct V_6 * V_7 ;
V_7 = F_216 () ;
if ( NULL == V_7 )
return NULL ;
* V_7 = * V_550 ;
V_7 -> V_325 = & V_10 -> V_11 . V_325 ;
V_7 -> V_552 = V_553 ;
V_7 -> V_554 = V_549 ;
F_217 ( V_555 , & V_7 -> V_164 ) ;
F_218 ( V_7 , V_10 ) ;
snprintf ( V_7 -> V_302 , sizeof( V_7 -> V_302 ) , L_93 ,
V_10 -> V_149 , ( V_10 -> V_149 == 848 && V_10 -> V_331 == 0x12 ) ? L_94 : L_87 ,
V_551 , V_95 [ V_10 -> V_11 . type ] . V_302 ) ;
if ( V_10 -> V_170 == V_171 ) {
F_219 ( V_7 , V_556 ) ;
F_219 ( V_7 , V_557 ) ;
F_219 ( V_7 , V_558 ) ;
F_219 ( V_7 , V_559 ) ;
}
return V_7 ;
}
static void F_220 ( struct V_9 * V_10 )
{
if ( V_10 -> V_408 ) {
if ( F_221 ( V_10 -> V_408 ) )
F_222 ( V_10 -> V_408 ) ;
else
V_553 ( V_10 -> V_408 ) ;
V_10 -> V_408 = NULL ;
}
if ( V_10 -> V_417 ) {
if ( F_221 ( V_10 -> V_417 ) )
F_222 ( V_10 -> V_417 ) ;
else
V_553 ( V_10 -> V_417 ) ;
V_10 -> V_417 = NULL ;
}
if ( V_10 -> V_419 ) {
if ( F_221 ( V_10 -> V_419 ) )
F_222 ( V_10 -> V_419 ) ;
else
V_553 ( V_10 -> V_419 ) ;
V_10 -> V_419 = NULL ;
}
}
static int F_223 ( struct V_9 * V_10 )
{
if ( V_403 > 0 )
F_192 ( L_95 ) ;
V_10 -> V_408 = F_215 ( V_10 , & V_560 , L_96 ) ;
if ( NULL == V_10 -> V_408 )
goto V_292;
if ( F_224 ( V_10 -> V_408 , V_425 ,
V_561 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_292;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_164 ( V_10 -> V_408 ) ) ;
if ( F_225 ( & V_10 -> V_408 -> V_8 ,
& V_562 ) < 0 ) {
F_19 ( L_98 , V_10 -> V_11 . V_58 ) ;
goto V_292;
}
V_10 -> V_417 = F_215 ( V_10 , & V_560 , L_99 ) ;
if ( NULL == V_10 -> V_417 )
goto V_292;
if ( F_224 ( V_10 -> V_417 , V_427 ,
V_563 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_292;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_164 ( V_10 -> V_417 ) ) ;
if ( ! V_10 -> V_564 )
return 0 ;
V_10 -> V_419 = F_215 ( V_10 , & V_565 , L_100 ) ;
if ( NULL == V_10 -> V_419 )
goto V_292;
V_10 -> V_419 -> V_121 = & V_10 -> V_566 ;
if ( F_224 ( V_10 -> V_419 , V_567 ,
V_568 [ V_10 -> V_11 . V_58 ] ) < 0 )
goto V_292;
F_23 ( L_97 ,
V_10 -> V_11 . V_58 , F_164 ( V_10 -> V_419 ) ) ;
return 0 ;
V_292:
F_220 ( V_10 ) ;
return - 1 ;
}
static void F_226 ( struct V_569 * V_8 )
{
#if F_227 ( V_570 )
unsigned int V_492 ;
F_228 ( V_8 , V_571 , & V_492 ) ;
V_492 = ( V_492 | V_572 ) ;
F_229 ( V_8 , V_571 , V_492 ) ;
#endif
}
static int F_230 ( struct V_569 * V_8 , const struct V_573 * V_574 )
{
struct V_315 V_575 = {
. V_288 = 0 ,
. type = V_451 ,
. V_317 = 980 ,
} ;
int V_498 ;
unsigned char V_576 ;
struct V_9 * V_10 ;
struct V_577 * V_578 ;
if ( V_579 == V_580 )
return - V_377 ;
F_23 ( L_101 , V_579 ) ;
V_581 [ V_579 ] = V_10 = F_231 ( sizeof( * V_10 ) , V_376 ) ;
if ( V_10 == NULL ) {
F_19 ( L_102 ) ;
return - V_377 ;
}
V_10 -> V_11 . V_58 = V_579 ;
snprintf ( V_10 -> V_11 . V_325 . V_302 , sizeof( V_10 -> V_11 . V_325 . V_302 ) ,
L_103 , V_10 -> V_11 . V_58 ) ;
F_232 ( & V_10 -> V_483 ) ;
F_233 ( & V_10 -> V_166 ) ;
F_233 ( & V_10 -> V_582 ) ;
F_234 ( & V_10 -> V_548 ) ;
F_235 ( & V_10 -> V_11 . V_583 ) ;
F_235 ( & V_10 -> V_287 ) ;
F_235 ( & V_10 -> V_537 ) ;
F_236 ( & V_10 -> V_584 ) ;
V_10 -> V_584 . V_585 = F_201 ;
V_10 -> V_584 . V_237 = ( unsigned long ) V_10 ;
V_10 -> V_586 = - 1 ;
V_10 -> V_170 = V_12 ;
V_10 -> V_169 = V_12 ;
V_10 -> V_564 = V_587 [ V_10 -> V_11 . V_58 ] ;
V_10 -> V_11 . V_410 = V_8 ;
V_10 -> V_149 = V_8 -> V_1 ;
if ( F_237 ( V_8 ) ) {
F_191 ( L_104 , V_10 -> V_11 . V_58 ) ;
return - V_588 ;
}
if ( F_238 ( V_8 , F_239 ( 32 ) ) ) {
F_191 ( L_105 , V_10 -> V_11 . V_58 ) ;
return - V_588 ;
}
if ( ! F_240 ( F_241 ( V_8 , 0 ) ,
F_242 ( V_8 , 0 ) ,
V_10 -> V_11 . V_325 . V_302 ) ) {
F_191 ( L_106 ,
V_10 -> V_11 . V_58 ,
( unsigned long long ) F_241 ( V_8 , 0 ) ) ;
return - V_360 ;
}
F_243 ( V_8 ) ;
F_226 ( V_8 ) ;
V_498 = F_244 ( & V_8 -> V_8 , & V_10 -> V_11 . V_325 ) ;
if ( V_498 < 0 ) {
F_191 ( L_107 , V_10 -> V_11 . V_58 ) ;
goto V_589;
}
V_578 = & V_10 -> V_121 ;
F_245 ( V_578 , 20 ) ;
V_10 -> V_11 . V_325 . V_121 = V_578 ;
F_245 ( & V_10 -> V_566 , 6 ) ;
V_10 -> V_331 = V_8 -> V_331 ;
F_246 ( V_8 , V_590 , & V_576 ) ;
F_23 ( L_108 ,
V_579 , V_10 -> V_149 , V_10 -> V_331 , F_124 ( V_8 ) ,
V_10 -> V_11 . V_410 -> V_539 , V_576 ,
( unsigned long long ) F_241 ( V_8 , 0 ) ) ;
F_247 () ;
V_10 -> V_591 = F_248 ( F_241 ( V_8 , 0 ) , 0x1000 ) ;
if ( NULL == V_10 -> V_591 ) {
F_19 ( L_109 , V_10 -> V_11 . V_58 ) ;
V_498 = - V_588 ;
goto V_592;
}
F_249 ( V_10 ) ;
F_17 ( 0 , V_175 ) ;
V_498 = F_250 ( V_10 -> V_11 . V_410 -> V_539 , F_212 ,
V_593 | V_594 , V_10 -> V_11 . V_325 . V_302 , ( void * ) V_10 ) ;
if ( V_498 < 0 ) {
F_19 ( L_110 ,
V_579 , V_10 -> V_11 . V_410 -> V_539 ) ;
goto V_592;
}
if ( 0 != F_251 ( V_10 ) ) {
V_498 = - V_588 ;
goto V_595;
}
V_10 -> V_215 = V_596 ;
V_597 . V_598 = V_596 ;
V_599 . V_598 = V_600 ;
V_10 -> V_108 = V_601 ;
V_602 . V_598 = V_601 ;
V_603 . V_598 = V_604 ;
V_10 -> V_224 = V_605 ;
V_606 . V_598 = V_605 ;
V_607 . V_598 = V_608 ;
V_609 . V_598 = V_610 ;
V_10 -> V_90 = V_611 ;
V_612 . V_598 = V_611 ;
V_613 . V_598 = V_614 ;
V_615 . V_598 = V_616 ;
V_10 -> V_383 . V_10 = V_10 ;
V_10 -> V_383 . V_380 . V_363 . V_144 = 320 ;
V_10 -> V_383 . V_380 . V_363 . V_39 = 240 ;
V_10 -> V_383 . V_260 = F_63 ( V_617 ) ;
V_10 -> V_383 . V_144 = 320 ;
V_10 -> V_383 . V_39 = 240 ;
V_10 -> V_383 . V_380 . V_363 . V_144 = 320 ;
V_10 -> V_383 . V_380 . V_363 . V_39 = 240 ;
V_10 -> V_383 . V_380 . V_262 = V_367 ;
V_10 -> V_69 = 0 ;
F_252 ( V_578 , & V_618 ,
V_202 , 0 , 0xff00 , 0x100 , 32768 ) ;
F_252 ( V_578 , & V_618 ,
V_204 , 0 , 0xff80 , 0x80 , 0x6c00 ) ;
F_252 ( V_578 , & V_618 ,
V_205 , 0 , 0xff80 , 0x80 , 32768 ) ;
F_252 ( V_578 , & V_618 ,
V_206 , 0 , 1 , 1 , 0 ) ;
F_252 ( V_578 , & V_618 ,
V_203 , 0 , 0xff00 , 0x100 , 32768 ) ;
F_252 ( V_578 , & V_618 ,
V_212 , 0 , 1 , 1 , ! ! V_619 ) ;
F_252 ( V_578 , & V_618 ,
V_122 , 0 , 1 , 1 , 0 ) ;
if ( V_10 -> V_211 )
F_252 ( V_578 , & V_618 ,
V_210 , 0 , 0xff00 , 0x100 , 0xff00 ) ;
F_253 ( V_578 , & V_597 , NULL ) ;
F_253 ( V_578 , & V_602 , NULL ) ;
F_253 ( V_578 , & V_599 , NULL ) ;
F_253 ( V_578 , & V_603 , NULL ) ;
F_253 ( V_578 , & V_606 , NULL ) ;
F_253 ( V_578 , & V_609 , NULL ) ;
F_253 ( V_578 , & V_607 , NULL ) ;
F_253 ( V_578 , & V_612 , NULL ) ;
F_253 ( V_578 , & V_613 , NULL ) ;
F_253 ( V_578 , & V_615 , NULL ) ;
if ( V_115 )
F_39 ( V_10 , L_111 ) ;
F_254 ( V_10 ) ;
F_56 ( V_10 ) ;
F_17 ( 0x00 , V_620 ) ;
F_17 ( 0x00 , V_238 ) ;
if ( V_60 )
F_39 ( V_10 , L_112 ) ;
F_255 ( V_10 ) ;
F_256 ( V_10 ) ;
F_257 ( V_10 ) ;
F_258 ( V_10 ) ;
if ( V_10 -> V_170 != V_171 ) {
F_84 ( V_10 , & V_575 ) ;
V_10 -> V_318 = 90500 * 16 ;
}
V_10 -> V_293 = V_621 ;
F_55 ( V_10 ) ;
F_57 ( V_578 ) ;
if ( V_578 -> error ) {
V_498 = V_578 -> error ;
goto V_595;
}
F_40 ( V_10 , 1 ) ;
if ( ! V_95 [ V_10 -> V_11 . type ] . V_173 ) {
F_259 ( & V_10 -> V_566 , V_578 ,
V_622 ) ;
if ( V_10 -> V_566 . error ) {
V_498 = V_10 -> V_566 . error ;
goto V_595;
}
F_52 ( V_10 , 0 , V_10 -> V_35 ) ;
F_47 ( & V_10 -> V_26 [ 0 ] , V_10 -> V_35 ) ;
V_10 -> V_26 [ 1 ] = V_10 -> V_26 [ 0 ] ;
F_14 ( V_10 ) ;
F_15 ( V_10 ) ;
F_223 ( V_10 ) ;
}
if ( V_95 [ V_10 -> V_11 . type ] . V_623 ) {
F_260 ( & V_10 -> V_11 , L_113 ) ;
F_6 ( V_10 ) ;
}
if ( ! V_624 ) {
F_261 ( V_10 ) ;
F_262 ( V_10 ) ;
}
V_579 ++ ;
return 0 ;
V_595:
F_263 ( V_10 -> V_11 . V_410 -> V_539 , V_10 ) ;
V_592:
F_264 ( & V_10 -> V_121 ) ;
F_264 ( & V_10 -> V_566 ) ;
F_265 ( & V_10 -> V_11 . V_325 ) ;
V_589:
if ( V_10 -> V_591 )
F_266 ( V_10 -> V_591 ) ;
F_267 ( F_241 ( V_10 -> V_11 . V_410 , 0 ) ,
F_242 ( V_10 -> V_11 . V_410 , 0 ) ) ;
return V_498 ;
}
static void F_268 ( struct V_569 * V_569 )
{
struct V_625 * V_325 = F_269 ( V_569 ) ;
struct V_9 * V_10 = F_270 ( V_325 ) ;
if ( V_60 )
F_23 ( L_114 , V_10 -> V_11 . V_58 ) ;
if ( V_95 [ V_10 -> V_11 . type ] . V_623 )
F_9 ( V_10 ) ;
F_34 ( ~ 15 , V_196 ) ;
F_17 ( 0 , V_175 ) ;
F_17 ( ~ 0x0 , V_172 ) ;
F_17 ( 0x0 , V_238 ) ;
if ( V_115 )
F_39 ( V_10 , L_115 ) ;
V_10 -> V_626 = 1 ;
F_271 ( V_10 ) ;
F_272 ( & V_10 -> V_11 ) ;
F_273 ( V_10 ) ;
F_220 ( V_10 ) ;
F_264 ( & V_10 -> V_121 ) ;
F_264 ( & V_10 -> V_566 ) ;
F_274 ( V_10 -> V_11 . V_410 , & V_10 -> main ) ;
F_263 ( V_10 -> V_11 . V_410 -> V_539 , V_10 ) ;
F_266 ( V_10 -> V_591 ) ;
F_267 ( F_241 ( V_10 -> V_11 . V_410 , 0 ) ,
F_242 ( V_10 -> V_11 . V_410 , 0 ) ) ;
F_265 ( & V_10 -> V_11 . V_325 ) ;
V_581 [ V_10 -> V_11 . V_58 ] = NULL ;
F_66 ( V_10 ) ;
return;
}
static int F_275 ( struct V_569 * V_569 , T_13 V_252 )
{
struct V_625 * V_325 = F_269 ( V_569 ) ;
struct V_9 * V_10 = F_270 ( V_325 ) ;
struct V_524 V_627 ;
unsigned long V_164 ;
F_22 ( L_116 , V_10 -> V_11 . V_58 , V_252 . V_628 ) ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
memset ( & V_627 , 0 , sizeof( V_627 ) ) ;
V_10 -> V_252 . V_629 = V_10 -> V_167 ;
V_10 -> V_252 . V_386 = V_10 -> V_517 ;
V_10 -> V_252 . V_255 = V_10 -> V_255 ;
V_10 -> V_167 = V_627 ;
V_10 -> V_255 = 0 ;
F_202 ( V_10 , & V_627 ) ;
F_203 ( V_10 , NULL ) ;
F_59 ( V_10 , 0 ) ;
F_17 ( 0 , V_175 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
V_10 -> V_252 . V_630 = F_16 ( V_238 ) ;
V_10 -> V_252 . V_631 = F_50 () ;
F_276 ( V_569 ) ;
if ( 0 != F_277 ( V_569 , F_278 ( V_569 , V_252 ) ) ) {
F_279 ( V_569 ) ;
V_10 -> V_252 . V_632 = 1 ;
}
return 0 ;
}
static int F_280 ( struct V_569 * V_569 )
{
struct V_625 * V_325 = F_269 ( V_569 ) ;
struct V_9 * V_10 = F_270 ( V_325 ) ;
unsigned long V_164 ;
int V_292 ;
F_22 ( L_117 , V_10 -> V_11 . V_58 ) ;
if ( V_10 -> V_252 . V_632 ) {
V_292 = F_237 ( V_569 ) ;
if ( V_292 ) {
F_191 ( L_104 , V_10 -> V_11 . V_58 ) ;
return V_292 ;
}
V_10 -> V_252 . V_632 = 0 ;
}
V_292 = F_277 ( V_569 , V_633 ) ;
if ( V_292 ) {
F_279 ( V_569 ) ;
F_191 ( L_104 , V_10 -> V_11 . V_58 ) ;
V_10 -> V_252 . V_632 = 1 ;
return V_292 ;
}
F_281 ( V_569 ) ;
F_58 ( V_10 ) ;
F_32 ( 0xffffff , V_10 -> V_252 . V_630 ) ;
F_282 ( V_10 -> V_252 . V_631 ) ;
F_53 ( & V_10 -> V_166 , V_164 ) ;
V_10 -> V_167 = V_10 -> V_252 . V_629 ;
V_10 -> V_517 = V_10 -> V_252 . V_386 ;
V_10 -> V_255 = V_10 -> V_252 . V_255 ;
F_202 ( V_10 , & V_10 -> V_167 ) ;
F_203 ( V_10 , V_10 -> V_517 ) ;
F_59 ( V_10 , 0 ) ;
F_54 ( & V_10 -> V_166 , V_164 ) ;
return 0 ;
}
static int T_14 F_283 ( void )
{
int V_634 ;
V_579 = 0 ;
F_23 ( L_118 , V_635 ) ;
if ( V_282 < 2 || V_282 > V_636 )
V_282 = 2 ;
if ( V_283 > V_637 )
V_283 = V_637 ;
V_283 = ( V_283 + V_638 - 1 ) & V_639 ;
if ( V_60 )
F_23 ( L_119 ,
V_282 , V_283 >> 10 , V_283 >> V_640 ) ;
F_284 () ;
V_634 = F_285 ( & V_641 ) ;
if ( V_634 < 0 ) {
F_191 ( L_120 , V_634 ) ;
return V_634 ;
}
V_634 = F_286 ( & V_642 ) ;
if ( V_634 < 0 )
F_287 ( & V_641 ) ;
return V_634 ;
}
static void T_15 F_288 ( void )
{
F_289 ( & V_642 ) ;
F_287 ( & V_641 ) ;
}
