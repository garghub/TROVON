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
static const struct V_16 * F_11 ( int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_12 ( V_19 ) ; V_18 ++ )
if ( V_19 [ V_18 ] . V_17 == V_17 )
return V_19 + V_18 ;
return NULL ;
}
static
int F_13 ( struct V_9 * V_10 , struct V_20 * V_21 , int V_22 )
{
int V_23 ;
if ( V_21 -> V_24 & V_22 )
return 1 ;
V_23 = V_22 ;
if ( V_22 & ( V_25 | V_26 ) )
V_23 |= V_25 | V_26 ;
if ( V_10 -> V_24 & V_23 ) {
goto V_27;
}
if ( ( V_22 & V_28 )
&& 0 == ( V_10 -> V_24 & V_28 ) ) {
T_2 V_29 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_29 ;
if ( V_10 -> V_33 > V_29 )
goto V_27;
V_10 -> V_34 = V_29 ;
} else if ( V_22 & V_35 ) {
T_2 V_36 = V_21 -> V_37 . V_36 ;
if ( V_36 > V_10 -> V_34 )
goto V_27;
V_10 -> V_33 = V_36 ;
}
V_21 -> V_24 |= V_22 ;
V_10 -> V_24 |= V_22 ;
return 1 ;
V_27:
return 0 ;
}
static
int F_14 ( struct V_20 * V_21 , int V_22 )
{
return ( V_21 -> V_24 & V_22 ) ;
}
static
int F_15 ( struct V_9 * V_10 , int V_22 )
{
return ( V_10 -> V_24 & V_22 ) ;
}
static void
F_16 ( struct V_9 * V_10 )
{
V_10 -> V_33 = 0 ;
}
static void
F_17 ( struct V_9 * V_10 )
{
const struct V_38 * V_39 ;
T_3 V_30 ;
V_39 = & V_40 [ V_10 -> V_39 ] ;
V_10 -> V_34 = V_39 -> V_41 . V_42 . V_29
+ V_39 -> V_41 . V_42 . V_43 ;
V_30 = F_18 ( V_44 ) | 0xc0 ;
F_19 ( V_30 , V_44 ) ;
F_19 ( 0xfe , V_45 ) ;
F_19 ( V_30 , V_46 ) ;
F_19 ( 0xfe , V_47 ) ;
}
static
void F_20 ( struct V_9 * V_10 , struct V_20 * V_21 , int V_48 )
{
if ( ( V_21 -> V_24 & V_48 ) != V_48 ) {
F_21 ( L_3 ) ;
}
V_21 -> V_24 &= ~ V_48 ;
V_10 -> V_24 &= ~ V_48 ;
V_48 = V_10 -> V_24 ;
if ( 0 == ( V_48 & V_28 ) )
F_17 ( V_10 ) ;
if ( 0 == ( V_48 & V_35 ) )
F_16 ( V_10 ) ;
}
static void F_22 ( struct V_9 * V_10 , unsigned int V_49 , unsigned int V_50 )
{
unsigned char V_51 , V_21 , V_52 ;
V_49 /= 4 ;
V_50 /= 4 ;
V_50 *= 12 ;
V_52 = V_50 / V_49 ;
V_50 = ( V_50 % V_49 ) * 256 ;
V_21 = V_50 / V_49 ;
V_50 = ( V_50 % V_49 ) * 256 ;
V_51 = V_50 / V_49 ;
F_19 ( V_51 , V_53 ) ;
F_19 ( V_21 , V_54 ) ;
F_19 ( V_52 | V_55 , V_56 ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
int V_18 ;
if ( ! V_10 -> V_57 . V_58 )
return;
if ( V_10 -> V_57 . V_59 == V_10 -> V_57 . V_60 ) {
F_24 ( L_4 , V_10 -> V_11 . V_61 ) ;
return;
}
if ( V_10 -> V_57 . V_62 == V_10 -> V_57 . V_59 ) {
if ( V_10 -> V_57 . V_60 == 0 )
return;
if ( V_63 )
F_25 ( L_5 ,
V_10 -> V_11 . V_61 , V_10 -> V_57 . V_62 ) ;
F_19 ( 0x00 , V_64 ) ;
F_19 ( 0x00 , V_56 ) ;
V_10 -> V_57 . V_60 = 0 ;
return;
}
if ( V_63 )
F_25 ( L_6 ,
V_10 -> V_11 . V_61 ,
V_10 -> V_57 . V_62 , V_10 -> V_57 . V_59 ) ;
F_22 ( V_10 , V_10 -> V_57 . V_62 , V_10 -> V_57 . V_59 ) ;
for ( V_18 = 0 ; V_18 < 10 ; V_18 ++ ) {
F_26 ( 10 ) ;
if ( F_18 ( V_65 ) & V_66 ) {
F_19 ( 0 , V_65 ) ;
} else {
F_19 ( 0x08 , V_64 ) ;
V_10 -> V_57 . V_60 = V_10 -> V_57 . V_59 ;
if ( V_63 )
F_25 ( L_7 ) ;
return;
}
}
V_10 -> V_57 . V_60 = - 1 ;
if ( V_63 )
F_25 ( L_8 ) ;
return;
}
static void F_27 ( struct V_9 * V_10 )
{
int V_18 , V_67 ;
int V_68 = V_40 [ V_10 -> V_39 ] . V_69 ;
int V_70 = V_40 [ V_10 -> V_39 ] . V_71 ;
if ( V_10 -> V_72 == V_10 -> V_73 ) {
F_24 ( L_9 ,
V_10 -> V_11 . V_61 , V_68 ) ;
F_19 ( 0x00 , V_64 ) ;
F_19 ( 0x02 , V_64 ) ;
F_19 ( 0x00 , V_64 ) ;
V_67 = V_74 [ V_68 ] [ 0 ] ;
for( V_18 = 1 ; V_18 <= V_67 ; V_18 ++ )
F_19 ( V_74 [ V_68 ] [ V_18 ] , V_75 ) ;
V_10 -> V_57 . V_59 = 27000000 ;
F_23 ( V_10 ) ;
F_19 ( 0x11 , V_64 ) ;
F_19 ( 0x41 , V_76 ) ;
} else {
V_10 -> V_57 . V_59 = V_70 ;
F_23 ( V_10 ) ;
F_19 ( 0x0 , V_76 ) ;
}
}
static void F_28 ( struct V_9 * V_10 , int V_77 )
{
int V_78 ;
V_10 -> V_77 = V_77 ;
V_78 = ( V_77 >> 8 ) - 128 ;
F_19 ( V_78 & 0xff , V_79 ) ;
}
static void F_29 ( struct V_9 * V_10 , int V_80 )
{
int V_78 ;
V_10 -> V_80 = V_80 ;
V_78 = ( V_80 >> 8 ) - 128 ;
F_19 ( V_78 & 0xff , V_81 ) ;
}
static void F_30 ( struct V_9 * V_10 , int V_82 )
{
int V_78 , V_83 ;
V_10 -> V_84 = V_82 ;
V_78 = ( V_82 >> 7 ) ;
V_83 = ( V_78 >> 6 ) & 4 ;
F_19 ( V_78 & 0xff , V_85 ) ;
F_31 ( V_83 , ~ 4 , V_86 ) ;
F_31 ( V_83 , ~ 4 , V_87 ) ;
}
static void F_32 ( struct V_9 * V_10 , int V_88 )
{
int V_89 , V_90 , V_91 ;
V_10 -> V_92 = V_88 ;
V_89 = ( ( V_88 * V_10 -> V_93 ) / 50 ) >> 7 ;
V_90 = ( ( ( V_88 * ( 100 - V_10 -> V_93 ) / 50 ) >> 7 ) * 180L ) / 254 ;
V_91 = ( V_89 >> 7 ) & 2 ;
V_91 |= ( V_90 >> 8 ) & 1 ;
F_19 ( V_89 & 0xff , V_94 ) ;
F_19 ( V_90 & 0xff , V_95 ) ;
F_31 ( V_91 , ~ 3 , V_86 ) ;
F_31 ( V_91 , ~ 3 , V_87 ) ;
}
static int
F_33 ( struct V_9 * V_10 , unsigned int V_72 )
{
int V_96 , V_97 ;
if ( V_72 >= V_98 [ V_10 -> V_11 . type ] . V_99 )
return - V_100 ;
V_97 = V_98 [ V_10 -> V_11 . type ] . V_101 ;
if ( V_97 )
F_34 ( V_97 , V_97 ) ;
if ( V_72 == V_10 -> V_102 ) {
F_35 ( V_103 , V_86 ) ;
F_35 ( V_103 , V_87 ) ;
} else {
F_36 ( ~ V_103 , V_86 ) ;
F_36 ( ~ V_103 , V_87 ) ;
}
V_96 = F_37 ( V_10 , V_72 ) ;
F_31 ( V_96 << 5 , ~ ( 3 << 5 ) , V_104 ) ;
F_24 ( L_10 , V_10 -> V_11 . V_61 , V_72 , V_96 ) ;
if( V_98 [ V_10 -> V_11 . type ] . V_105 )
V_98 [ V_10 -> V_11 . type ] . V_105 ( V_10 , V_72 ) ;
return 0 ;
}
static int
F_38 ( struct V_9 * V_10 , int V_72 , int V_106 )
{
int V_107 , signal ;
struct V_108 V_109 ;
F_34 ( V_98 [ V_10 -> V_11 . type ] . V_110 ,
V_98 [ V_10 -> V_11 . type ] . V_110 ) ;
signal = F_18 ( V_65 ) & V_111 ;
V_10 -> V_106 = V_106 ;
V_10 -> V_112 = V_72 ;
V_106 = V_106 || ( V_10 -> V_113 && ! signal && ! V_10 -> V_114 ) ;
if ( V_106 )
V_107 = V_98 [ V_10 -> V_11 . type ] . V_115 ;
else
V_107 = V_98 [ V_10 -> V_11 . type ] . V_116 [ V_72 ] ;
switch ( V_10 -> V_11 . type ) {
case V_117 :
case V_118 :
V_107 = F_39 ( V_10 , V_107 ) ;
break;
default:
F_40 ( V_98 [ V_10 -> V_11 . type ] . V_110 , V_107 ) ;
}
if ( V_119 )
F_41 ( V_10 , V_120 [ V_106 ? 4 : V_72 ] ) ;
if ( F_42 () )
return 0 ;
V_109 . V_17 = V_121 ;
V_109 . V_78 = V_10 -> V_106 ;
F_43 ( V_10 , V_122 , V_123 , & V_109 ) ;
if ( V_10 -> V_124 ) {
T_4 V_125 ;
switch ( V_72 ) {
case V_126 :
if ( V_10 -> V_127 ) {
V_125 = V_128 ;
break;
}
V_125 = F_44 ( V_129 , V_130 ,
V_131 , V_131 ) ;
break;
case V_132 :
V_125 = F_44 ( V_133 , V_130 ,
V_131 , V_131 ) ;
break;
case V_134 :
V_125 = F_44 ( V_129 , V_130 ,
V_131 , V_131 ) ;
break;
case V_135 :
default:
if ( V_10 -> V_11 . type == V_118 )
V_125 = F_44 ( V_133 , V_136 , \
V_137 , V_137 ) ;
else
V_125 = V_128 ;
break;
}
F_45 ( V_10 -> V_124 , V_112 , V_138 ,
V_125 , V_139 , 0 ) ;
}
if ( V_10 -> V_140 ) {
F_45 ( V_10 -> V_140 , V_112 , V_138 ,
V_72 , 0 , 0 ) ;
}
return 0 ;
}
static inline int
F_46 ( struct V_9 * V_10 , int V_106 )
{
return F_38 ( V_10 , V_10 -> V_112 , V_106 ) ;
}
static inline int
F_47 ( struct V_9 * V_10 , int V_72 )
{
return F_38 ( V_10 , V_72 , V_10 -> V_106 ) ;
}
static void
F_48 ( struct V_141 * V_11 )
{
if ( 1 ) {
V_11 -> V_142 = 48 ;
V_11 -> V_143 = 32 ;
} else {
V_11 -> V_142 =
( F_49 ( 48 , V_11 -> V_32 . V_144 >> 4 ) + 3 ) & ~ 3 ;
V_11 -> V_143 =
F_49 ( 32 , V_11 -> V_32 . V_43 >> 4 ) ;
}
V_11 -> V_145 = V_11 -> V_32 . V_144 & ~ 3 ;
V_11 -> V_146 = V_11 -> V_32 . V_43 ;
}
static void
F_50 ( struct V_141 * V_11 , unsigned int V_147 )
{
V_11 -> V_32 = V_40 [ V_147 ] . V_41 . V_148 ;
F_48 ( V_11 ) ;
}
static int
F_51 ( struct V_9 * V_10 , unsigned int V_147 )
{
const struct V_38 * V_39 ;
T_5 V_17 ;
F_52 ( V_147 >= V_149 ) ;
F_52 ( V_10 -> V_39 >= V_149 ) ;
V_39 = & V_40 [ V_147 ] ;
if ( memcmp ( & V_40 [ V_10 -> V_39 ] . V_41 , & V_39 -> V_41 ,
sizeof ( V_39 -> V_41 ) ) ) {
F_50 ( & V_10 -> V_30 [ 0 ] , V_147 ) ;
V_10 -> V_30 [ 1 ] = V_10 -> V_30 [ 0 ] ;
if ( 0 == ( V_10 -> V_24 & V_28 ) ) {
V_10 -> V_34 = V_39 -> V_41 . V_42 . V_29
+ V_39 -> V_41 . V_42 . V_43 ;
}
}
V_10 -> V_39 = V_147 ;
F_19 ( V_39 -> V_150 , V_151 ) ;
F_19 ( V_39 -> V_152 , V_153 ) ;
F_31 ( V_39 -> V_154 , ~ ( V_155 | V_156 ) ,
V_104 ) ;
F_19 ( V_39 -> V_157 , V_158 ) ;
F_19 ( 1 , V_159 ) ;
F_27 ( V_10 ) ;
switch ( V_10 -> V_11 . type ) {
case V_117 :
case V_118 :
F_39 ( V_10 , F_53 () ) ;
break;
}
V_17 = V_39 -> V_160 ;
F_43 ( V_10 , V_122 , V_161 , V_17 ) ;
return 0 ;
}
static void
F_54 ( struct V_9 * V_10 , unsigned int V_72 , unsigned int V_147 )
{
unsigned long V_162 ;
V_10 -> V_72 = V_72 ;
if ( V_163 ) {
F_55 ( & V_10 -> V_164 , V_162 ) ;
if ( V_10 -> V_165 . V_166 ) {
V_10 -> V_167 = V_72 ;
} else {
F_33 ( V_10 , V_72 ) ;
}
F_56 ( & V_10 -> V_164 , V_162 ) ;
} else {
F_33 ( V_10 , V_72 ) ;
}
F_47 ( V_10 , ( V_10 -> V_168 != V_169 && V_72 == 0 ) ?
V_135 : V_132 ) ;
F_51 ( V_10 , V_147 ) ;
}
static void F_57 ( struct V_9 * V_10 )
{
F_19 ( 0xfffffUL , V_170 ) ;
if ( V_98 [ V_10 -> V_11 . type ] . V_171 ) {
F_19 ( V_172 ,
V_173 ) ;
} else {
F_19 ( ( V_10 -> V_174 ) |
( V_10 -> V_175 ? V_176 : 0 ) |
V_177 |
( V_178 ? V_179 : 0 ) |
V_180 | V_181 |
V_182 | V_183 |
V_172 ,
V_173 ) ;
}
}
static void F_58 ( struct V_9 * V_10 )
{
int V_184 ;
if ( V_98 [ V_10 -> V_11 . type ] . V_171 ) {
F_57 ( V_10 ) ;
return;
}
F_19 ( 0x00 , V_185 ) ;
F_19 ( V_186 , V_187 ) ;
F_19 ( V_188 | V_189 , V_104 ) ;
F_19 ( V_190 |
V_191 |
V_192 |
V_193 |
V_194 ,
V_195 ) ;
V_184 = V_10 -> V_196 ? V_197 : 0 ;
F_19 ( V_184 , V_198 ) ;
F_19 ( V_184 , V_199 ) ;
F_19 ( 0x20 , V_200 ) ;
F_19 ( 0x20 , V_201 ) ;
F_19 ( V_202 | ( V_10 -> V_203 ? V_204 : 0 ) ,
V_205 ) ;
F_19 ( V_206 , V_207 ) ;
F_19 ( V_208 , V_209 ) ;
if ( V_10 -> V_210 ) {
F_19 ( 0 , V_86 ) ;
F_19 ( 0 , V_87 ) ;
} else {
F_19 ( V_211 , V_86 ) ;
F_19 ( V_211 , V_87 ) ;
}
F_28 ( V_10 , V_10 -> V_77 ) ;
F_29 ( V_10 , V_10 -> V_80 ) ;
F_30 ( V_10 , V_10 -> V_84 ) ;
F_32 ( V_10 , V_10 -> V_92 ) ;
F_57 ( V_10 ) ;
}
static void F_59 ( struct V_9 * V_10 )
{
unsigned long V_162 ;
if ( V_63 )
F_25 ( L_11 , V_10 -> V_11 . V_61 ) ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
V_10 -> V_212 = 0 ;
F_60 ( V_10 , 0 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
F_58 ( V_10 ) ;
V_10 -> V_57 . V_60 = - 1 ;
F_54 ( V_10 , V_10 -> V_72 , V_10 -> V_39 ) ;
}
static int F_61 ( struct V_213 * V_213 , void * V_214 ,
struct V_108 * V_11 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
switch ( V_11 -> V_17 ) {
case V_215 :
V_11 -> V_78 = V_10 -> V_77 ;
break;
case V_216 :
V_11 -> V_78 = V_10 -> V_80 ;
break;
case V_217 :
V_11 -> V_78 = V_10 -> V_84 ;
break;
case V_218 :
V_11 -> V_78 = V_10 -> V_92 ;
break;
case V_219 :
V_11 -> V_78 = V_10 -> V_220 ;
break;
case V_121 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
F_43 ( V_10 , V_122 , V_225 , V_11 ) ;
break;
case V_226 :
V_11 -> V_78 = V_10 -> V_196 ;
break;
case V_227 :
V_11 -> V_78 = V_10 -> V_228 ;
break;
case V_229 :
V_11 -> V_78 = V_10 -> V_210 ;
break;
case V_230 :
V_11 -> V_78 = V_10 -> V_113 ;
break;
case V_231 :
V_11 -> V_78 = V_10 -> V_203 ;
break;
case V_232 :
V_11 -> V_78 = V_10 -> V_233 ;
break;
case V_234 :
V_11 -> V_78 = V_10 -> V_235 ;
break;
case V_236 :
V_11 -> V_78 = V_10 -> V_237 ;
break;
case V_238 :
V_11 -> V_78 = V_10 -> V_93 ;
break;
case V_239 :
V_11 -> V_78 = V_10 -> V_240 ;
break;
case V_241 :
V_11 -> V_78 = V_10 -> V_242 ;
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_62 ( struct V_213 * V_213 , void * V_243 ,
struct V_108 * V_11 )
{
int V_244 ;
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_244 = F_63 ( & V_10 -> V_245 , V_21 -> V_245 ) ;
if ( 0 != V_244 )
return V_244 ;
switch ( V_11 -> V_17 ) {
case V_215 :
F_28 ( V_10 , V_11 -> V_78 ) ;
break;
case V_216 :
F_29 ( V_10 , V_11 -> V_78 ) ;
break;
case V_217 :
F_30 ( V_10 , V_11 -> V_78 ) ;
break;
case V_218 :
F_32 ( V_10 , V_11 -> V_78 ) ;
break;
case V_219 :
V_10 -> V_220 = V_11 -> V_78 ;
if ( V_10 -> V_220 ) {
F_35 ( V_246 , V_198 ) ;
F_35 ( V_246 , V_199 ) ;
} else {
F_36 ( ~ V_246 , V_198 ) ;
F_36 ( ~ V_246 , V_199 ) ;
}
break;
case V_121 :
F_46 ( V_10 , V_11 -> V_78 ) ;
case V_221 :
if ( V_10 -> V_247 )
V_10 -> V_247 ( V_10 , V_11 -> V_78 ) ;
F_43 ( V_10 , V_122 , V_123 , V_11 ) ;
break;
case V_222 :
case V_223 :
case V_224 :
F_43 ( V_10 , V_122 , V_123 , V_11 ) ;
break;
case V_226 :
V_10 -> V_196 = V_11 -> V_78 ;
if ( V_10 -> V_196 ) {
F_35 ( V_197 , V_198 ) ;
F_35 ( V_197 , V_199 ) ;
} else {
F_36 ( ~ V_197 , V_198 ) ;
F_36 ( ~ V_197 , V_199 ) ;
}
break;
case V_227 :
V_10 -> V_228 = V_11 -> V_78 ;
break;
case V_229 :
V_10 -> V_210 = V_11 -> V_78 ;
if ( V_10 -> V_210 ) {
F_36 ( ~ V_211 , V_86 ) ;
F_36 ( ~ V_211 , V_87 ) ;
} else {
F_35 ( V_211 , V_86 ) ;
F_35 ( V_211 , V_87 ) ;
}
break;
case V_230 :
V_10 -> V_113 = V_11 -> V_78 ;
break;
case V_231 :
V_10 -> V_203 = V_11 -> V_78 ;
F_19 ( V_202 |
( V_10 -> V_203 ? V_204 : 0 ) ,
V_205 ) ;
break;
case V_232 :
V_10 -> V_233 = V_11 -> V_78 ;
break;
case V_234 :
V_10 -> V_235 = V_11 -> V_78 ;
F_19 ( V_11 -> V_78 , V_207 ) ;
break;
case V_236 :
V_10 -> V_237 = V_11 -> V_78 ;
F_19 ( V_11 -> V_78 , V_209 ) ;
break;
case V_238 :
V_10 -> V_93 = V_11 -> V_78 ;
F_32 ( V_10 , V_10 -> V_92 ) ;
break;
case V_239 :
V_10 -> V_240 = V_11 -> V_78 ;
F_31 ( ( V_11 -> V_78 << 7 ) , ~ V_248 , V_249 ) ;
break;
case V_241 :
V_10 -> V_242 = V_11 -> V_78 ;
F_31 ( ( V_11 -> V_78 << 5 ) , ~ V_250 , V_249 ) ;
break;
default:
return - V_100 ;
}
return 0 ;
}
void F_41 ( struct V_9 * V_10 , char * V_251 )
{
unsigned int V_252 , V_253 ;
V_252 = F_18 ( V_254 ) ;
V_253 = F_18 ( V_255 ) ;
F_64 ( L_12 ,
V_10 -> V_11 . V_61 , V_252 , V_253 & V_252 , V_253 & ~ V_252 , V_251 ) ;
}
static void F_65 ( struct V_9 * V_10 )
{
int V_256 = 0 ;
if ( V_10 -> V_257 )
V_256 ++ ;
if ( V_256 ) {
F_35 ( V_258 , V_173 ) ;
} else {
F_36 ( ~ V_258 , V_173 ) ;
V_10 -> V_259 = 0 ;
}
}
static const struct V_260 *
F_66 ( int V_261 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_262 ; V_18 ++ ) {
if ( - 1 == V_263 [ V_18 ] . V_261 )
continue;
if ( V_263 [ V_18 ] . V_261 == V_261 )
return V_263 + V_18 ;
}
return NULL ;
}
static int
F_67 ( struct V_9 * V_10 , struct V_20 * V_21 ,
struct V_264 * V_265 )
{
struct V_264 * V_266 ;
unsigned long V_162 ;
int V_267 = 0 ;
F_24 ( L_13 , V_265 ) ;
if ( V_265 )
V_265 -> V_268 . V_269 = V_270 ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
V_266 = V_10 -> V_271 ;
V_10 -> V_271 = V_265 ;
V_10 -> V_272 |= 1 ;
F_60 ( V_10 , 0x03 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
if ( NULL != V_266 ) {
F_24 ( L_14 ,
V_266 , V_266 -> V_268 . V_269 ) ;
F_68 ( & V_21 -> V_273 , V_10 , V_266 ) ;
F_69 ( V_266 ) ;
}
if ( NULL == V_265 )
F_20 ( V_10 , V_21 , V_274 ) ;
F_24 ( L_15 ) ;
return V_267 ;
}
static int F_70 ( struct V_275 * V_276 , struct V_9 * V_10 ,
struct V_264 * V_5 ,
const struct V_260 * V_277 ,
unsigned int V_144 , unsigned int V_43 ,
enum V_278 V_279 )
{
struct V_20 * V_21 = V_276 -> V_280 ;
int V_281 = 0 ;
struct V_141 V_11 ;
int V_147 ;
int V_282 ;
if ( NULL == V_277 )
return - V_100 ;
if ( V_277 -> V_283 == V_284 ) {
V_144 = V_285 ;
V_43 = V_286 * 2 ;
if ( V_144 * V_43 > V_5 -> V_268 . V_287 )
return - V_100 ;
V_5 -> V_268 . V_288 = V_5 -> V_268 . V_287 ;
V_147 = V_10 -> V_39 ;
if ( V_10 -> V_33 > V_40 [ V_147 ] . V_41 . V_148 . V_29 ) {
return - V_100 ;
}
V_11 . V_32 = V_40 [ V_147 ] . V_41 . V_148 ;
} else {
V_147 = V_10 -> V_39 ;
V_11 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] ;
if ( V_144 < V_11 . V_142 ||
V_144 > V_11 . V_145 ||
V_43 < V_11 . V_143 )
return - V_100 ;
switch ( V_279 ) {
case V_289 :
case V_290 :
case V_291 :
if ( V_43 * 2 > V_11 . V_146 )
return - V_100 ;
break;
default:
if ( V_43 > V_11 . V_146 )
return - V_100 ;
break;
}
V_5 -> V_268 . V_288 = ( V_144 * V_43 * V_277 -> V_292 ) >> 3 ;
if ( 0 != V_5 -> V_268 . V_293 && V_5 -> V_268 . V_287 < V_5 -> V_268 . V_288 )
return - V_100 ;
}
if ( V_5 -> V_268 . V_144 != V_144 || V_5 -> V_268 . V_43 != V_43 ||
V_5 -> V_268 . V_279 != V_279 ||
V_5 -> V_39 != V_147 || V_5 -> V_277 != V_277 ||
V_5 -> V_30 . V_29 != V_11 . V_32 . V_29 ||
V_5 -> V_30 . V_294 != V_11 . V_32 . V_294 ||
V_5 -> V_30 . V_144 != V_11 . V_32 . V_144 ||
V_5 -> V_30 . V_43 != V_11 . V_32 . V_43 ) {
V_5 -> V_268 . V_144 = V_144 ;
V_5 -> V_268 . V_43 = V_43 ;
V_5 -> V_268 . V_279 = V_279 ;
V_5 -> V_39 = V_147 ;
V_5 -> V_277 = V_277 ;
V_5 -> V_30 = V_11 . V_32 ;
V_281 = 1 ;
}
if ( V_295 == V_5 -> V_268 . V_269 ) {
V_281 = 1 ;
if ( 0 != ( V_282 = F_71 ( V_276 , & V_5 -> V_268 , & V_10 -> V_296 ) ) )
goto V_27;
}
if ( V_281 )
if ( 0 != ( V_282 = F_72 ( V_10 , V_5 ) ) )
goto V_27;
V_5 -> V_268 . V_269 = V_297 ;
return 0 ;
V_27:
F_68 ( V_276 , V_10 , V_5 ) ;
return V_282 ;
}
static int
F_73 ( struct V_275 * V_276 , unsigned int * V_298 , unsigned int * V_288 )
{
struct V_20 * V_21 = V_276 -> V_280 ;
* V_288 = V_21 -> V_277 -> V_292 * V_21 -> V_144 * V_21 -> V_43 >> 3 ;
if ( 0 == * V_298 )
* V_298 = V_299 ;
if ( * V_288 * * V_298 > V_299 * V_300 )
* V_298 = ( V_299 * V_300 ) / * V_288 ;
return 0 ;
}
static int
F_74 ( struct V_275 * V_276 , struct V_301 * V_268 ,
enum V_278 V_279 )
{
struct V_264 * V_5 = F_2 ( V_268 , struct V_264 , V_268 ) ;
struct V_20 * V_21 = V_276 -> V_280 ;
return F_70 ( V_276 , V_21 -> V_10 , V_5 , V_21 -> V_277 ,
V_21 -> V_144 , V_21 -> V_43 , V_279 ) ;
}
static void
F_75 ( struct V_275 * V_276 , struct V_301 * V_268 )
{
struct V_264 * V_5 = F_2 ( V_268 , struct V_264 , V_268 ) ;
struct V_20 * V_21 = V_276 -> V_280 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_5 -> V_268 . V_269 = V_302 ;
F_76 ( & V_5 -> V_268 . V_303 , & V_10 -> V_304 ) ;
if ( ! V_10 -> V_165 . V_166 ) {
V_10 -> V_272 |= 1 ;
F_60 ( V_10 , 0x03 ) ;
}
}
static void F_77 ( struct V_275 * V_276 , struct V_301 * V_268 )
{
struct V_264 * V_5 = F_2 ( V_268 , struct V_264 , V_268 ) ;
struct V_20 * V_21 = V_276 -> V_280 ;
F_68 ( V_276 , V_21 -> V_10 , V_5 ) ;
}
static int F_78 ( struct V_213 * V_213 , void * V_214 , T_5 * V_17 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
unsigned int V_18 ;
int V_244 ;
V_244 = F_63 ( & V_10 -> V_245 , V_21 -> V_245 ) ;
if ( V_244 )
goto V_244;
for ( V_18 = 0 ; V_18 < V_149 ; V_18 ++ )
if ( * V_17 & V_40 [ V_18 ] . V_160 )
break;
if ( V_18 == V_149 ) {
V_244 = - V_100 ;
goto V_244;
}
F_51 ( V_10 , V_18 ) ;
V_244:
return V_244 ;
}
static int F_79 ( struct V_213 * V_213 , void * V_243 , T_5 * V_17 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( F_18 ( V_65 ) & V_305 )
* V_17 = V_306 ;
else
* V_17 = V_307 ;
return 0 ;
}
static int F_80 ( struct V_213 * V_213 , void * V_214 ,
struct V_308 * V_18 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_282 = 0 ;
if ( V_18 -> V_309 >= V_98 [ V_10 -> V_11 . type ] . V_99 ) {
V_282 = - V_100 ;
goto V_244;
}
V_18 -> type = V_310 ;
V_18 -> V_311 = 1 ;
if ( V_10 -> V_168 != V_169 && V_18 -> V_309 == 0 ) {
sprintf ( V_18 -> V_312 , L_16 ) ;
V_18 -> type = V_313 ;
V_18 -> V_314 = 0 ;
} else if ( V_18 -> V_309 == V_10 -> V_102 ) {
sprintf ( V_18 -> V_312 , L_17 ) ;
} else {
sprintf ( V_18 -> V_312 , L_18 , V_18 -> V_309 ) ;
}
if ( V_18 -> V_309 == V_10 -> V_72 ) {
T_6 V_315 = F_18 ( V_65 ) ;
if ( 0 == ( V_315 & V_316 ) )
V_18 -> V_317 |= V_318 ;
if ( 0 == ( V_315 & V_111 ) )
V_18 -> V_317 |= V_319 ;
}
V_18 -> V_320 = V_321 ;
V_244:
return V_282 ;
}
static int F_81 ( struct V_213 * V_213 , void * V_214 , unsigned int * V_18 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_18 = V_10 -> V_72 ;
return 0 ;
}
static int F_82 ( struct V_213 * V_213 , void * V_214 , unsigned int V_18 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_244 ;
V_244 = F_63 ( & V_10 -> V_245 , V_21 -> V_245 ) ;
if ( F_83 ( V_244 ) )
goto V_244;
if ( V_18 > V_98 [ V_10 -> V_11 . type ] . V_99 ) {
V_244 = - V_100 ;
goto V_244;
}
F_54 ( V_10 , V_18 , V_10 -> V_39 ) ;
V_244:
return 0 ;
}
static int F_84 ( struct V_213 * V_213 , void * V_214 ,
struct V_322 * V_323 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_244 ;
if ( F_83 ( 0 != V_323 -> V_309 ) )
return - V_100 ;
if ( F_83 ( V_10 -> V_168 == V_169 ) ) {
V_244 = - V_100 ;
goto V_244;
}
V_244 = F_63 ( & V_10 -> V_245 , V_21 -> V_245 ) ;
if ( F_83 ( V_244 ) )
goto V_244;
F_43 ( V_10 , V_314 , V_324 , V_323 ) ;
if ( V_10 -> V_325 )
V_10 -> V_325 ( V_10 , V_323 , 1 ) ;
V_244:
return 0 ;
}
static int F_85 ( struct V_213 * V_213 , void * V_214 ,
struct V_326 * V_243 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_243 -> type = V_10 -> V_114 ? V_327 : V_328 ;
V_243 -> V_329 = V_10 -> V_330 ;
return 0 ;
}
static int F_86 ( struct V_213 * V_213 , void * V_214 ,
struct V_326 * V_243 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_244 ;
if ( F_83 ( V_243 -> V_314 != 0 ) )
return - V_100 ;
V_244 = F_63 ( & V_10 -> V_245 , V_21 -> V_245 ) ;
if ( F_83 ( V_244 ) )
goto V_244;
if ( F_83 ( V_243 -> type != ( V_10 -> V_114
? V_327 : V_328 ) ) ) {
V_244 = - V_100 ;
goto V_244;
}
V_10 -> V_330 = V_243 -> V_329 ;
F_43 ( V_10 , V_314 , V_331 , V_243 ) ;
if ( V_10 -> V_332 && V_10 -> V_114 )
F_87 ( V_10 , V_10 -> V_330 ) ;
V_244:
return 0 ;
}
static int F_88 ( struct V_213 * V_213 , void * V_243 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
F_43 ( V_10 , V_122 , V_333 ) ;
return 0 ;
}
static int F_89 ( struct V_213 * V_213 , void * V_243 ,
struct V_334 * V_335 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( ! F_90 ( V_336 ) )
return - V_337 ;
if ( ! F_91 ( & V_335 -> V_338 ) )
return - V_100 ;
V_335 -> V_335 &= 0xfff ;
V_335 -> V_184 = F_18 ( V_335 -> V_335 ) ;
V_335 -> V_288 = 1 ;
return 0 ;
}
static int F_92 ( struct V_213 * V_213 , void * V_243 ,
struct V_334 * V_335 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( ! F_90 ( V_336 ) )
return - V_337 ;
if ( ! F_91 ( & V_335 -> V_338 ) )
return - V_100 ;
V_335 -> V_335 &= 0xfff ;
F_19 ( V_335 -> V_184 , V_335 -> V_335 ) ;
return 0 ;
}
static void
F_93 ( struct V_141 * V_11 ,
const struct V_339 * V_340 ,
T_2 V_144 ,
T_2 V_43 ,
enum V_278 V_279 )
{
T_2 V_341 = V_43 << ! F_94 ( V_279 ) ;
T_2 V_342 ;
T_2 V_343 ;
if ( V_144 < V_11 -> V_142 ) {
V_11 -> V_32 . V_144 = V_144 * 16 ;
} else if ( V_144 > V_11 -> V_145 ) {
V_11 -> V_32 . V_144 = V_144 ;
V_342 = V_340 -> V_294 + V_340 -> V_144 - V_144 ;
V_342 = F_95 ( V_342 , ( T_2 ) V_344 ) ;
if ( V_11 -> V_32 . V_294 > V_342 )
V_11 -> V_32 . V_294 = V_342 ;
}
if ( V_43 < V_11 -> V_143 ) {
V_11 -> V_32 . V_43 = V_43 * 16 ;
} else if ( V_341 > V_11 -> V_146 ) {
V_11 -> V_32 . V_43 = ( V_341 + 1 ) & ~ 1 ;
V_343 = V_340 -> V_29 + V_340 -> V_43 - V_11 -> V_32 . V_43 ;
if ( V_11 -> V_32 . V_29 > V_343 )
V_11 -> V_32 . V_29 = V_343 ;
}
F_48 ( V_11 ) ;
}
static int
F_96 ( struct V_20 * V_21 ,
T_2 * V_144 ,
T_2 * V_43 ,
enum V_278 V_279 ,
unsigned int V_345 ,
unsigned int V_346 ,
int V_347 ,
int V_348 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_339 * V_340 ;
struct V_141 * V_11 ;
T_2 V_349 ;
T_2 V_350 ;
T_2 V_351 ;
T_2 V_352 ;
int V_282 ;
F_52 ( ( int ) V_345 >= 0 ||
V_346 >= ( unsigned int ) - V_345 ) ;
V_340 = & V_40 [ V_10 -> V_39 ] . V_41 . V_42 ;
V_11 = & V_10 -> V_30 [ ! ! V_21 -> V_31 ] ;
if ( V_21 -> V_31
&& V_347
&& V_348
&& ! F_15 ( V_10 , V_28 ) ) {
V_349 = 48 ;
V_350 = 32 ;
V_351 = F_95 ( V_340 -> V_144 , ( T_2 ) V_353 ) ;
V_352 = V_340 -> V_43 ;
if ( V_10 -> V_33 > V_340 -> V_29 ) {
V_352 -= V_10 -> V_33 - V_340 -> V_29 ;
V_282 = - V_354 ;
if ( V_350 > V_352 )
goto V_27;
}
} else {
V_282 = - V_354 ;
if ( V_10 -> V_33 > V_11 -> V_32 . V_29 )
goto V_27;
V_349 = V_11 -> V_142 ;
V_350 = V_11 -> V_143 ;
V_351 = V_11 -> V_145 ;
V_352 = V_11 -> V_146 ;
V_348 = 0 ;
}
V_349 = ( V_349 - V_345 - 1 ) & V_345 ;
V_351 = V_351 & V_345 ;
V_350 = V_350 ;
V_352 >>= ! F_94 ( V_279 ) ;
if ( V_347 ) {
* V_144 = F_97 ( * V_144 , V_349 , V_351 ) ;
* V_43 = F_97 ( * V_43 , V_350 , V_352 ) ;
* V_144 = ( * V_144 + V_346 ) & V_345 ;
if ( V_348 ) {
F_93 ( V_11 , V_340 , * V_144 , * V_43 , V_279 ) ;
if ( V_10 -> V_33 > V_11 -> V_32 . V_29 ) {
V_11 -> V_32 . V_29 = V_10 -> V_33 ;
}
}
} else {
V_282 = - V_100 ;
if ( * V_144 < V_349 ||
* V_43 < V_350 ||
* V_144 > V_351 ||
* V_43 > V_352 ||
0 != ( * V_144 & ~ V_345 ) )
goto V_27;
}
V_282 = 0 ;
V_27:
return V_282 ;
}
static int
F_98 ( struct V_20 * V_21 ,
struct V_355 * V_356 ,
int V_347 ,
int V_348 )
{
enum V_278 V_279 ;
unsigned int V_345 ;
int V_282 ;
if ( V_356 -> V_357 . V_144 < 48 || V_356 -> V_357 . V_43 < 32 )
return - V_100 ;
if ( V_356 -> V_358 > 2048 )
return - V_100 ;
V_279 = V_356 -> V_279 ;
if ( V_359 == V_279 ) {
T_2 V_360 ;
V_360 = V_21 -> V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_43 >> 1 ;
V_279 = ( V_356 -> V_357 . V_43 > V_360 )
? V_361
: V_289 ;
}
switch ( V_279 ) {
case V_289 :
case V_290 :
case V_361 :
break;
default:
return - V_100 ;
}
if ( NULL == V_21 -> V_362 )
return - V_100 ;
V_345 = ~ 0 ;
switch ( V_21 -> V_362 -> V_292 ) {
case 8 :
case 24 :
V_345 = ~ 3 ;
break;
case 16 :
V_345 = ~ 1 ;
break;
case 32 :
break;
default:
F_99 () ;
}
V_356 -> V_357 . V_144 -= V_356 -> V_357 . V_294 & ~ V_345 ;
V_356 -> V_357 . V_294 = ( V_356 -> V_357 . V_294 - V_345 - 1 ) & V_345 ;
V_282 = F_96 ( V_21 , & V_356 -> V_357 . V_144 , & V_356 -> V_357 . V_43 ,
V_279 , V_345 ,
0 ,
V_347 , V_348 ) ;
if ( 0 != V_282 )
return V_282 ;
V_356 -> V_279 = V_279 ;
return 0 ;
}
static int F_100 ( struct V_20 * V_21 , struct V_9 * V_10 ,
struct V_355 * V_356 , int V_363 )
{
struct V_364 * V_365 = NULL ;
int V_366 , V_288 , V_267 = 0 ;
if ( NULL == V_21 -> V_362 )
return - V_100 ;
if ( ! ( V_21 -> V_362 -> V_162 & V_367 ) )
return - V_100 ;
V_267 = F_98 ( V_21 , V_356 ,
V_363 ,
V_363 ) ;
if ( 0 != V_267 )
return V_267 ;
V_366 = V_356 -> V_358 ;
V_288 = sizeof( * V_365 ) * ( V_366 + 4 ) ;
V_365 = F_101 ( V_288 , V_368 ) ;
if ( NULL == V_365 )
return - V_369 ;
if ( V_366 > 0 ) {
if ( F_102 ( V_365 , V_356 -> V_365 , sizeof( struct V_364 ) * V_366 ) ) {
F_69 ( V_365 ) ;
return - V_370 ;
}
}
if ( NULL != V_10 -> V_296 . V_371 )
V_366 = F_103 ( V_10 -> V_296 . V_277 . V_144 , V_10 -> V_296 . V_277 . V_43 ,
& V_356 -> V_357 , V_365 , V_366 ) ;
F_104 ( V_365 , V_366 ) ;
switch ( V_21 -> V_362 -> V_292 ) {
case 8 :
case 24 :
F_105 ( & V_356 -> V_357 , V_365 , V_366 , 3 ) ;
break;
case 16 :
F_105 ( & V_356 -> V_357 , V_365 , V_366 , 1 ) ;
break;
case 32 :
break;
default:
F_99 () ;
}
F_69 ( V_21 -> V_372 . V_365 ) ;
V_21 -> V_372 . V_365 = V_365 ;
V_21 -> V_372 . V_373 = V_366 ;
V_21 -> V_372 . V_357 = V_356 -> V_357 ;
V_21 -> V_372 . V_279 = V_356 -> V_279 ;
V_21 -> V_372 . V_374 = 1 ;
V_10 -> V_375 . V_372 . V_357 . V_144 = V_356 -> V_357 . V_144 ;
V_10 -> V_375 . V_372 . V_357 . V_43 = V_356 -> V_357 . V_43 ;
V_10 -> V_375 . V_372 . V_279 = V_356 -> V_279 ;
V_267 = 0 ;
if ( F_14 ( V_21 , V_274 ) ) {
struct V_264 * V_265 ;
V_265 = F_106 ( sizeof( * V_265 ) ) ;
V_265 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_372 , V_21 -> V_362 , V_265 ) ;
V_267 = F_67 ( V_10 , V_21 , V_265 ) ;
}
return V_267 ;
}
static struct V_275 * F_108 ( struct V_20 * V_21 )
{
struct V_275 * V_276 = NULL ;
switch ( V_21 -> type ) {
case V_376 :
V_276 = & V_21 -> V_273 ;
break;
case V_377 :
V_276 = & V_21 -> V_378 ;
break;
default:
F_99 () ;
}
return V_276 ;
}
static int F_109 ( struct V_20 * V_21 )
{
int V_379 = 0 ;
switch ( V_21 -> type ) {
case V_376 :
V_379 = V_26 ;
break;
case V_377 :
V_379 = V_380 ;
break;
default:
F_99 () ;
}
return V_379 ;
}
static int F_110 ( struct V_20 * V_21 , enum V_381 type )
{
struct V_275 * V_276 = F_108 ( V_21 ) ;
int V_379 = F_109 ( V_21 ) ;
if ( F_14 ( V_21 , V_379 ) )
return - V_354 ;
if ( F_111 ( V_276 ) )
return - V_354 ;
V_21 -> type = type ;
return 0 ;
}
static void
F_112 ( struct V_382 * V_243 ,
const struct V_260 * V_277 ,
unsigned int V_144 ,
unsigned int V_43 )
{
V_243 -> V_144 = V_144 ;
V_243 -> V_43 = V_43 ;
if ( V_277 -> V_162 & V_383 ) {
V_243 -> V_384 = V_144 ;
V_243 -> V_385 = ( V_144 * V_43 * V_277 -> V_292 ) >> 3 ;
} else {
V_243 -> V_384 = ( V_144 * V_277 -> V_292 ) >> 3 ;
V_243 -> V_385 = V_43 * V_243 -> V_384 ;
}
}
static int F_113 ( struct V_213 * V_213 , void * V_214 ,
struct V_386 * V_243 )
{
struct V_20 * V_21 = V_214 ;
F_112 ( & V_243 -> V_277 . V_387 , V_21 -> V_277 ,
V_21 -> V_144 , V_21 -> V_43 ) ;
V_243 -> V_277 . V_387 . V_279 = V_21 -> V_273 . V_279 ;
V_243 -> V_277 . V_387 . V_388 = V_21 -> V_277 -> V_261 ;
return 0 ;
}
static int F_114 ( struct V_213 * V_213 , void * V_214 ,
struct V_386 * V_243 )
{
struct V_20 * V_21 = V_214 ;
V_243 -> V_277 . V_356 . V_357 = V_21 -> V_372 . V_357 ;
V_243 -> V_277 . V_356 . V_279 = V_21 -> V_372 . V_279 ;
return 0 ;
}
static int F_115 ( struct V_213 * V_213 , void * V_214 ,
struct V_386 * V_243 )
{
const struct V_260 * V_277 ;
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
enum V_278 V_279 ;
T_2 V_144 , V_43 ;
int V_282 ;
V_277 = F_66 ( V_243 -> V_277 . V_387 . V_388 ) ;
if ( NULL == V_277 )
return - V_100 ;
V_279 = V_243 -> V_277 . V_387 . V_279 ;
if ( V_359 == V_279 ) {
T_2 V_360 ;
V_360 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_43 >> 1 ;
V_279 = ( V_243 -> V_277 . V_387 . V_43 > V_360 )
? V_361
: V_290 ;
}
if ( V_389 == V_279 )
V_279 = V_390 ;
switch ( V_279 ) {
case V_289 :
case V_290 :
case V_291 :
case V_361 :
break;
case V_390 :
if ( V_277 -> V_162 & V_383 )
return - V_100 ;
break;
default:
return - V_100 ;
}
V_144 = V_243 -> V_277 . V_387 . V_144 ;
V_43 = V_243 -> V_277 . V_387 . V_43 ;
V_282 = F_96 ( V_21 , & V_144 , & V_43 , V_279 ,
~ 3 ,
2 ,
1 ,
0 ) ;
if ( 0 != V_282 )
return V_282 ;
V_243 -> V_277 . V_387 . V_279 = V_279 ;
F_112 ( & V_243 -> V_277 . V_387 , V_277 , V_144 , V_43 ) ;
return 0 ;
}
static int F_116 ( struct V_213 * V_213 , void * V_214 ,
struct V_386 * V_243 )
{
struct V_20 * V_21 = V_214 ;
return F_98 ( V_21 , & V_243 -> V_277 . V_356 ,
1 ,
0 ) ;
}
static int F_117 ( struct V_213 * V_213 , void * V_214 ,
struct V_386 * V_243 )
{
int V_267 ;
const struct V_260 * V_277 ;
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
T_2 V_144 , V_43 ;
enum V_278 V_279 ;
V_267 = F_110 ( V_21 , V_243 -> type ) ;
if ( 0 != V_267 )
return V_267 ;
V_267 = F_115 ( V_213 , V_214 , V_243 ) ;
if ( 0 != V_267 )
return V_267 ;
V_144 = V_243 -> V_277 . V_387 . V_144 ;
V_43 = V_243 -> V_277 . V_387 . V_43 ;
V_279 = V_243 -> V_277 . V_387 . V_279 ;
V_267 = F_96 ( V_21 , & V_144 , & V_43 , V_243 -> V_277 . V_387 . V_279 ,
~ 3 ,
2 ,
1 ,
1 ) ;
if ( 0 != V_267 )
return V_267 ;
V_243 -> V_277 . V_387 . V_279 = V_279 ;
V_277 = F_66 ( V_243 -> V_277 . V_387 . V_388 ) ;
V_21 -> V_277 = V_277 ;
V_21 -> V_273 . V_279 = V_243 -> V_277 . V_387 . V_279 ;
V_21 -> V_273 . V_391 = V_392 ;
V_21 -> V_144 = V_243 -> V_277 . V_387 . V_144 ;
V_21 -> V_43 = V_243 -> V_277 . V_387 . V_43 ;
V_10 -> V_375 . V_277 = V_277 ;
V_10 -> V_375 . V_144 = V_243 -> V_277 . V_387 . V_144 ;
V_10 -> V_375 . V_43 = V_243 -> V_277 . V_387 . V_43 ;
return 0 ;
}
static int F_118 ( struct V_213 * V_213 , void * V_214 ,
struct V_386 * V_243 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_393 > 0 ) {
F_21 ( L_19 ) ;
return - V_100 ;
}
return F_100 ( V_21 , V_10 , & V_243 -> V_277 . V_356 , 1 ) ;
}
static int F_119 ( struct V_213 * V_213 , void * V_214 ,
struct V_394 * V_273 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( 0 == V_395 )
return - V_100 ;
F_120 ( V_273 -> V_396 , L_20 , sizeof( V_273 -> V_396 ) ) ;
F_120 ( V_273 -> V_397 , V_10 -> V_398 -> V_312 , sizeof( V_273 -> V_397 ) ) ;
snprintf ( V_273 -> V_399 , sizeof( V_273 -> V_399 ) ,
L_21 , F_121 ( V_10 -> V_11 . V_400 ) ) ;
V_273 -> V_401 =
V_402 |
V_403 |
V_404 |
V_405 ;
if ( V_393 <= 0 )
V_273 -> V_401 |= V_406 ;
if ( V_10 -> V_407 )
V_273 -> V_401 |= V_408 ;
if ( V_10 -> V_168 != V_169 )
V_273 -> V_401 |= V_409 ;
return 0 ;
}
static int F_122 ( struct V_410 * V_243 )
{
int V_309 = - 1 , V_18 ;
for ( V_18 = 0 ; V_18 < V_262 ; V_18 ++ ) {
if ( V_263 [ V_18 ] . V_261 != - 1 )
V_309 ++ ;
if ( ( unsigned int ) V_309 == V_243 -> V_309 )
break;
}
if ( V_262 == V_18 )
return - V_100 ;
V_243 -> V_388 = V_263 [ V_18 ] . V_261 ;
F_120 ( V_243 -> V_411 , V_263 [ V_18 ] . V_312 , sizeof( V_243 -> V_411 ) ) ;
return V_18 ;
}
static int F_123 ( struct V_213 * V_213 , void * V_214 ,
struct V_410 * V_243 )
{
int V_282 = F_122 ( V_243 ) ;
if ( V_282 < 0 )
return V_282 ;
return 0 ;
}
static int F_124 ( struct V_213 * V_213 , void * V_214 ,
struct V_410 * V_243 )
{
int V_282 ;
if ( V_393 > 0 ) {
F_21 ( L_19 ) ;
return - V_100 ;
}
V_282 = F_122 ( V_243 ) ;
if ( V_282 < 0 )
return V_282 ;
if ( ! ( V_263 [ V_282 ] . V_162 & V_367 ) )
return - V_100 ;
return 0 ;
}
static int F_125 ( struct V_213 * V_213 , void * V_243 ,
struct V_412 * V_413 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_413 = V_10 -> V_296 ;
V_413 -> V_414 = V_415 ;
if ( V_21 -> V_362 )
V_413 -> V_277 . V_388 = V_21 -> V_362 -> V_261 ;
return 0 ;
}
static int F_126 ( struct V_213 * V_213 , void * V_243 , unsigned int V_416 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_264 * V_265 ;
int V_267 = 0 ;
if ( V_416 ) {
if ( F_83 ( ! V_10 -> V_296 . V_371 ) ) {
return - V_100 ;
}
if ( F_83 ( ! V_21 -> V_372 . V_374 ) ) {
F_24 ( L_22 , V_10 -> V_11 . V_61 ) ;
V_267 = - V_100 ;
}
if ( V_267 )
return V_267 ;
}
if ( ! F_13 ( V_10 , V_21 , V_274 ) )
return - V_354 ;
if ( V_416 ) {
V_21 -> V_372 . V_39 = V_10 -> V_39 ;
V_265 = F_106 ( sizeof( * V_265 ) ) ;
V_265 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_372 , V_21 -> V_362 , V_265 ) ;
} else {
V_265 = NULL ;
}
V_267 = F_67 ( V_10 , V_21 , V_265 ) ;
return V_267 ;
}
static int F_127 ( struct V_213 * V_213 , void * V_243 ,
const struct V_412 * V_413 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_260 * V_277 ;
int V_267 ;
if ( ! F_90 ( V_336 ) &&
! F_90 ( V_417 ) )
return - V_337 ;
V_277 = F_66 ( V_413 -> V_277 . V_388 ) ;
if ( NULL == V_277 )
return - V_100 ;
if ( 0 == ( V_277 -> V_162 & V_367 ) )
return - V_100 ;
V_267 = - V_100 ;
if ( V_413 -> V_162 & V_418 ) {
T_2 V_144 = V_413 -> V_277 . V_144 ;
T_2 V_43 = V_413 -> V_277 . V_43 ;
V_267 = F_96 ( V_21 , & V_144 , & V_43 ,
V_361 ,
~ 3 ,
2 ,
0 ,
0 ) ;
if ( 0 != V_267 )
return V_267 ;
}
V_10 -> V_296 . V_371 = V_413 -> V_371 ;
V_10 -> V_296 . V_277 . V_144 = V_413 -> V_277 . V_144 ;
V_10 -> V_296 . V_277 . V_43 = V_413 -> V_277 . V_43 ;
if ( 0 != V_413 -> V_277 . V_384 )
V_10 -> V_296 . V_277 . V_384 = V_413 -> V_277 . V_384 ;
else
V_10 -> V_296 . V_277 . V_384 = V_10 -> V_296 . V_277 . V_144 * V_277 -> V_292 / 8 ;
V_267 = 0 ;
V_21 -> V_362 = V_277 ;
V_10 -> V_375 . V_362 = V_277 ;
if ( V_413 -> V_162 & V_418 ) {
V_21 -> V_372 . V_357 . V_294 = 0 ;
V_21 -> V_372 . V_357 . V_29 = 0 ;
V_21 -> V_372 . V_357 . V_144 = V_413 -> V_277 . V_144 ;
V_21 -> V_372 . V_357 . V_43 = V_413 -> V_277 . V_43 ;
V_10 -> V_375 . V_372 . V_357 . V_144 = V_413 -> V_277 . V_144 ;
V_10 -> V_375 . V_372 . V_357 . V_43 = V_413 -> V_277 . V_43 ;
F_69 ( V_21 -> V_372 . V_365 ) ;
V_21 -> V_372 . V_365 = NULL ;
V_21 -> V_372 . V_373 = 0 ;
if ( F_14 ( V_21 , V_274 ) ) {
struct V_264 * V_265 ;
V_265 = F_106 ( sizeof( * V_265 ) ) ;
V_265 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_372 , V_21 -> V_362 , V_265 ) ;
V_267 = F_67 ( V_10 , V_21 , V_265 ) ;
}
}
return V_267 ;
}
static int F_128 ( struct V_213 * V_213 , void * V_214 ,
struct V_419 * V_420 )
{
struct V_20 * V_21 = V_214 ;
return F_129 ( F_108 ( V_21 ) , V_420 ) ;
}
static int F_130 ( struct V_213 * V_213 , void * V_214 ,
struct V_421 * V_340 )
{
struct V_20 * V_21 = V_214 ;
return F_131 ( F_108 ( V_21 ) , V_340 ) ;
}
static int F_132 ( struct V_213 * V_213 , void * V_214 , struct V_421 * V_340 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_379 = F_109 ( V_21 ) ;
if ( ! F_13 ( V_10 , V_21 , V_379 ) )
return - V_354 ;
return F_133 ( F_108 ( V_21 ) , V_340 ) ;
}
static int F_134 ( struct V_213 * V_213 , void * V_214 , struct V_421 * V_340 )
{
struct V_20 * V_21 = V_214 ;
return F_135 ( F_108 ( V_21 ) , V_340 ,
V_213 -> V_422 & V_423 ) ;
}
static int F_136 ( struct V_213 * V_213 , void * V_214 ,
enum V_381 type )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_379 = F_109 ( V_21 ) ;
if ( ! F_13 ( V_10 , V_21 , V_379 ) )
return - V_354 ;
return F_137 ( F_108 ( V_21 ) ) ;
}
static int F_138 ( struct V_213 * V_213 , void * V_214 ,
enum V_381 type )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_267 ;
int V_379 = F_109 ( V_21 ) ;
V_267 = F_139 ( F_108 ( V_21 ) ) ;
if ( V_267 < 0 )
return V_267 ;
F_20 ( V_10 , V_21 , V_379 ) ;
return 0 ;
}
static int F_140 ( struct V_213 * V_213 , void * V_214 ,
struct V_16 * V_11 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_16 * V_109 ;
if ( ( V_11 -> V_17 < V_424 ||
V_11 -> V_17 >= V_425 ) &&
( V_11 -> V_17 < V_426 ||
V_11 -> V_17 >= V_427 ) )
return - V_100 ;
if ( ! V_10 -> V_247 && ( V_11 -> V_17 == V_221 ) )
* V_11 = V_428 ;
else {
V_109 = F_11 ( V_11 -> V_17 ) ;
* V_11 = ( NULL != V_109 ) ? * V_109 : V_428 ;
}
return 0 ;
}
static int F_141 ( struct V_213 * V_213 , void * V_243 ,
struct V_429 * V_430 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
F_142 ( V_40 [ V_10 -> V_39 ] . V_160 ,
& V_430 -> V_430 . V_304 . V_431 ) ;
return 0 ;
}
static int F_143 ( struct V_213 * V_213 , void * V_214 ,
struct V_322 * V_323 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_10 -> V_168 == V_169 )
return - V_100 ;
if ( 0 != V_323 -> V_309 )
return - V_100 ;
V_323 -> V_432 = V_433 ;
F_43 ( V_10 , V_314 , V_434 , V_323 ) ;
strcpy ( V_323 -> V_312 , L_16 ) ;
V_323 -> V_414 = V_435 ;
V_323 -> type = V_328 ;
if ( F_18 ( V_65 ) & V_111 )
V_323 -> signal = 0xffff ;
if ( V_10 -> V_325 )
V_10 -> V_325 ( V_10 , V_323 , 0 ) ;
return 0 ;
}
static int F_144 ( struct V_213 * V_213 , void * V_243 , enum V_436 * V_420 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_420 = F_145 ( & V_10 -> V_245 ) ;
return 0 ;
}
static int F_146 ( struct V_213 * V_213 , void * V_243 ,
enum V_436 V_245 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_282 ;
V_282 = F_147 ( & V_10 -> V_245 , & V_21 -> V_245 , V_245 ) ;
return V_282 ;
}
static int F_148 ( struct V_213 * V_213 , void * V_214 ,
struct V_437 * V_273 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_273 -> type != V_376 &&
V_273 -> type != V_438 )
return - V_100 ;
* V_273 = V_40 [ V_10 -> V_39 ] . V_41 ;
return 0 ;
}
static int F_149 ( struct V_213 * V_213 , void * V_243 , struct V_439 * V_30 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_30 -> type != V_376 &&
V_30 -> type != V_438 )
return - V_100 ;
V_30 -> V_11 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
return 0 ;
}
static int F_150 ( struct V_213 * V_213 , void * V_243 , const struct V_439 * V_30 )
{
struct V_20 * V_21 = V_243 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_339 * V_340 ;
int V_267 ;
struct V_141 V_11 ;
T_2 V_440 ;
T_2 V_441 ;
T_2 V_442 ;
T_2 V_443 ;
if ( V_30 -> type != V_376 &&
V_30 -> type != V_438 )
return - V_100 ;
V_267 = F_63 ( & V_10 -> V_245 , V_21 -> V_245 ) ;
if ( 0 != V_267 ) {
return V_267 ;
}
V_267 = - V_354 ;
if ( F_15 ( V_21 -> V_10 , V_28 ) ) {
return V_267 ;
}
V_340 = & V_40 [ V_10 -> V_39 ] . V_41 . V_42 ;
V_440 = V_340 -> V_294 ;
V_442 = V_440 + V_340 -> V_144 ;
V_443 = V_340 -> V_29 + V_340 -> V_43 ;
V_441 = F_49 ( V_340 -> V_29 , V_10 -> V_33 ) ;
if ( V_441 + 32 >= V_443 ) {
return V_267 ;
}
V_11 . V_32 . V_294 = F_151 ( V_444 , V_30 -> V_11 . V_294 , V_440 , V_442 - 48 ) ;
V_11 . V_32 . V_294 = F_95 ( V_11 . V_32 . V_294 , ( T_2 ) V_344 ) ;
V_11 . V_32 . V_144 = F_151 ( V_444 , V_30 -> V_11 . V_144 ,
48 , V_442 - V_11 . V_32 . V_294 ) ;
V_11 . V_32 . V_29 = F_151 ( V_444 , V_30 -> V_11 . V_29 , V_441 , V_443 - 32 ) ;
V_11 . V_32 . V_29 = ( V_11 . V_32 . V_29 + 1 ) & ~ 1 ;
V_11 . V_32 . V_43 = F_151 ( V_444 , V_30 -> V_11 . V_43 ,
32 , V_443 - V_11 . V_32 . V_29 ) ;
V_11 . V_32 . V_43 = ( V_11 . V_32 . V_43 + 1 ) & ~ 1 ;
F_48 ( & V_11 ) ;
V_10 -> V_30 [ 1 ] = V_11 ;
V_21 -> V_31 = 1 ;
if ( V_21 -> V_144 < V_11 . V_142 ) {
V_21 -> V_144 = V_11 . V_142 ;
V_10 -> V_375 . V_144 = V_11 . V_142 ;
} else if ( V_21 -> V_144 > V_11 . V_145 ) {
V_21 -> V_144 = V_11 . V_145 ;
V_10 -> V_375 . V_144 = V_11 . V_145 ;
}
if ( V_21 -> V_43 < V_11 . V_143 ) {
V_21 -> V_43 = V_11 . V_143 ;
V_10 -> V_375 . V_43 = V_11 . V_143 ;
} else if ( V_21 -> V_43 > V_11 . V_146 ) {
V_21 -> V_43 = V_11 . V_146 ;
V_10 -> V_375 . V_43 = V_11 . V_146 ;
}
return 0 ;
}
static int F_152 ( struct V_213 * V_213 , void * V_214 , struct V_445 * V_446 )
{
if ( F_83 ( V_446 -> V_309 ) )
return - V_100 ;
strcpy ( V_446 -> V_312 , L_23 ) ;
return 0 ;
}
static int F_153 ( struct V_213 * V_213 , void * V_214 , const struct V_445 * V_446 )
{
if ( F_83 ( V_446 -> V_309 ) )
return - V_100 ;
return 0 ;
}
static T_1 F_154 ( struct V_213 * V_213 , char T_7 * V_253 ,
T_8 V_298 , T_9 * V_447 )
{
struct V_20 * V_21 = V_213 -> V_448 ;
int V_267 = 0 ;
if ( V_21 -> V_10 -> V_212 )
F_59 ( V_21 -> V_10 ) ;
F_24 ( L_24 ,
V_21 -> V_10 -> V_11 . V_61 , ( int ) V_298 , V_449 [ V_21 -> type ] ) ;
switch ( V_21 -> type ) {
case V_376 :
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_25 ) ) {
return - V_354 ;
}
V_267 = F_155 ( & V_21 -> V_273 , V_253 , V_298 , V_447 ,
V_213 -> V_422 & V_423 ) ;
F_20 ( V_21 -> V_10 , V_21 , V_25 ) ;
break;
case V_377 :
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_380 ) )
return - V_354 ;
V_267 = F_156 ( & V_21 -> V_378 , V_253 , V_298 , V_447 , 1 ,
V_213 -> V_422 & V_423 ) ;
break;
default:
F_99 () ;
}
return V_267 ;
}
static unsigned int F_157 ( struct V_213 * V_213 , T_10 * V_450 )
{
struct V_20 * V_21 = V_213 -> V_448 ;
struct V_264 * V_5 ;
enum V_278 V_279 ;
unsigned int V_282 = V_451 ;
if ( V_377 == V_21 -> type ) {
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_380 ) )
return V_451 ;
return F_158 ( V_213 , & V_21 -> V_378 , V_450 ) ;
}
if ( F_14 ( V_21 , V_26 ) ) {
if ( F_159 ( & V_21 -> V_273 . V_452 ) )
goto V_244;
V_5 = F_160 ( V_21 -> V_273 . V_452 . V_453 , struct V_264 , V_268 . V_452 ) ;
} else {
if ( NULL == V_21 -> V_273 . V_454 ) {
if ( F_15 ( V_21 -> V_10 , V_26 ) )
goto V_244;
V_21 -> V_273 . V_454 = F_106 ( V_21 -> V_273 . V_455 ) ;
if ( NULL == V_21 -> V_273 . V_454 )
goto V_244;
V_21 -> V_273 . V_454 -> V_456 = V_457 ;
V_279 = F_161 ( & V_21 -> V_273 ) ;
if ( 0 != V_21 -> V_273 . V_458 -> V_459 ( & V_21 -> V_273 , V_21 -> V_273 . V_454 , V_279 ) ) {
F_69 ( V_21 -> V_273 . V_454 ) ;
V_21 -> V_273 . V_454 = NULL ;
goto V_244;
}
V_21 -> V_273 . V_458 -> V_460 ( & V_21 -> V_273 , V_21 -> V_273 . V_454 ) ;
V_21 -> V_273 . V_461 = 0 ;
}
V_5 = (struct V_264 * ) V_21 -> V_273 . V_454 ;
}
F_162 ( V_213 , & V_5 -> V_268 . V_462 , V_450 ) ;
if ( V_5 -> V_268 . V_269 == V_270 ||
V_5 -> V_268 . V_269 == V_463 )
V_282 = V_464 | V_465 ;
else
V_282 = 0 ;
V_244:
return V_282 ;
}
static int F_163 ( struct V_213 * V_213 )
{
struct V_6 * V_466 = F_164 ( V_213 ) ;
struct V_9 * V_10 = F_165 ( V_213 ) ;
struct V_20 * V_21 ;
enum V_381 type = 0 ;
F_24 ( L_25 , F_166 ( V_466 ) ) ;
if ( V_466 -> V_467 == V_468 ) {
type = V_376 ;
} else if ( V_466 -> V_467 == V_469 ) {
type = V_377 ;
} else {
F_167 ( 1 ) ;
return - V_470 ;
}
F_24 ( L_26 ,
V_10 -> V_11 . V_61 , V_449 [ type ] ) ;
V_21 = F_101 ( sizeof( * V_21 ) , V_368 ) ;
if ( F_83 ( ! V_21 ) )
return - V_369 ;
V_213 -> V_448 = V_21 ;
* V_21 = V_10 -> V_375 ;
V_21 -> type = type ;
V_21 -> V_372 . V_374 = 0 ;
F_168 ( & V_10 -> V_245 , & V_21 -> V_245 ) ;
F_169 ( & V_21 -> V_273 , & V_471 ,
& V_10 -> V_11 . V_400 -> V_8 , & V_10 -> V_164 ,
V_376 ,
V_361 ,
sizeof( struct V_264 ) ,
V_21 , & V_10 -> V_472 ) ;
F_169 ( & V_21 -> V_378 , & V_473 ,
& V_10 -> V_11 . V_400 -> V_8 , & V_10 -> V_164 ,
V_377 ,
V_390 ,
sizeof( struct V_264 ) ,
V_21 , & V_10 -> V_472 ) ;
F_51 ( V_10 , V_10 -> V_39 ) ;
F_54 ( V_10 , V_10 -> V_72 , V_10 -> V_39 ) ;
V_10 -> V_257 ++ ;
V_21 -> V_31 = ! V_474 ;
F_170 ( & V_21 -> V_37 , V_10 -> V_39 ) ;
F_65 ( V_10 ) ;
return 0 ;
}
static int F_171 ( struct V_213 * V_213 )
{
struct V_20 * V_21 = V_213 -> V_448 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( F_14 ( V_21 , V_274 ) )
F_67 ( V_10 , V_21 , NULL ) ;
if ( F_14 ( V_21 , V_26 ) ) {
F_139 ( & V_21 -> V_273 ) ;
F_20 ( V_10 , V_21 , V_26 ) ;
}
if ( V_21 -> V_273 . V_454 ) {
F_77 ( & V_21 -> V_273 , V_21 -> V_273 . V_454 ) ;
F_69 ( V_21 -> V_273 . V_454 ) ;
}
if ( F_14 ( V_21 , V_25 ) ) {
F_20 ( V_10 , V_21 , V_25 ) ;
}
if ( F_14 ( V_21 , V_380 ) ) {
F_172 ( & V_21 -> V_378 ) ;
F_20 ( V_10 , V_21 , V_380 ) ;
}
F_173 ( & V_21 -> V_273 ) ;
F_173 ( & V_21 -> V_378 ) ;
F_174 ( & V_10 -> V_245 , V_21 -> V_245 ) ;
V_213 -> V_448 = NULL ;
F_69 ( V_21 ) ;
V_10 -> V_257 -- ;
F_65 ( V_10 ) ;
if ( ! V_10 -> V_257 )
F_46 ( V_10 , 1 ) ;
return 0 ;
}
static int
F_175 ( struct V_213 * V_213 , struct V_475 * V_476 )
{
struct V_20 * V_21 = V_213 -> V_448 ;
F_24 ( L_27 ,
V_21 -> V_10 -> V_11 . V_61 , V_449 [ V_21 -> type ] ,
V_476 -> V_477 , V_476 -> V_478 - V_476 -> V_477 ) ;
return F_176 ( F_108 ( V_21 ) , V_476 ) ;
}
static int F_177 ( struct V_213 * V_213 )
{
struct V_6 * V_466 = F_164 ( V_213 ) ;
struct V_9 * V_10 = F_165 ( V_213 ) ;
struct V_20 * V_21 ;
F_24 ( L_25 , F_166 ( V_466 ) ) ;
F_24 ( L_28 , V_10 -> V_11 . V_61 ) ;
V_21 = F_101 ( sizeof( * V_21 ) , V_368 ) ;
if ( F_83 ( ! V_21 ) )
return - V_369 ;
V_213 -> V_448 = V_21 ;
* V_21 = V_10 -> V_375 ;
F_168 ( & V_10 -> V_245 , & V_21 -> V_245 ) ;
V_10 -> V_114 ++ ;
F_43 ( V_10 , V_314 , V_479 ) ;
F_47 ( V_10 , V_126 ) ;
return 0 ;
}
static int F_178 ( struct V_213 * V_213 )
{
struct V_20 * V_21 = V_213 -> V_448 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_480 V_481 ;
F_174 ( & V_10 -> V_245 , V_21 -> V_245 ) ;
V_213 -> V_448 = NULL ;
F_69 ( V_21 ) ;
V_10 -> V_114 -- ;
F_43 ( V_10 , V_122 , V_482 , V_483 , & V_481 ) ;
return 0 ;
}
static int F_179 ( struct V_213 * V_213 , void * V_214 ,
struct V_394 * V_273 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
strcpy ( V_273 -> V_396 , L_20 ) ;
F_120 ( V_273 -> V_397 , V_10 -> V_484 -> V_312 , sizeof( V_273 -> V_397 ) ) ;
sprintf ( V_273 -> V_399 , L_21 , F_121 ( V_10 -> V_11 . V_400 ) ) ;
V_273 -> V_401 = V_409 ;
return 0 ;
}
static int F_180 ( struct V_213 * V_213 , void * V_214 , struct V_322 * V_323 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_10 -> V_168 == V_169 )
return - V_100 ;
if ( 0 != V_323 -> V_309 )
return - V_100 ;
strcpy ( V_323 -> V_312 , L_29 ) ;
V_323 -> type = V_327 ;
F_43 ( V_10 , V_314 , V_434 , V_323 ) ;
if ( V_10 -> V_325 )
V_10 -> V_325 ( V_10 , V_323 , 0 ) ;
return 0 ;
}
static int F_181 ( struct V_213 * V_213 , void * V_214 ,
struct V_308 * V_18 )
{
if ( V_18 -> V_309 != 0 )
return - V_100 ;
strcpy ( V_18 -> V_312 , L_29 ) ;
V_18 -> type = V_313 ;
return 0 ;
}
static int F_182 ( struct V_213 * V_213 , void * V_214 ,
struct V_445 * V_446 )
{
if ( F_83 ( V_446 -> V_309 ) )
return - V_100 ;
strcpy ( V_446 -> V_312 , L_29 ) ;
return 0 ;
}
static int F_183 ( struct V_213 * V_213 , void * V_214 ,
struct V_322 * V_323 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( 0 != V_323 -> V_309 )
return - V_100 ;
F_43 ( V_10 , V_314 , V_324 , V_323 ) ;
return 0 ;
}
static int F_184 ( struct V_213 * V_213 , void * V_214 ,
const struct V_445 * V_446 )
{
if ( F_83 ( V_446 -> V_309 ) )
return - V_100 ;
return 0 ;
}
static int F_185 ( struct V_213 * V_485 , void * V_214 , unsigned int V_18 )
{
if ( F_83 ( V_18 ) )
return - V_100 ;
return 0 ;
}
static int F_186 ( struct V_213 * V_213 , void * V_21 , T_5 * V_147 )
{
return 0 ;
}
static int F_187 ( struct V_213 * V_213 , void * V_214 ,
struct V_16 * V_11 )
{
const struct V_16 * V_109 ;
if ( V_11 -> V_17 < V_424 ||
V_11 -> V_17 >= V_425 )
return - V_100 ;
if ( V_11 -> V_17 == V_121 ) {
V_109 = F_11 ( V_11 -> V_17 ) ;
* V_11 = * V_109 ;
} else
* V_11 = V_428 ;
return 0 ;
}
static int F_188 ( struct V_213 * V_485 , void * V_214 , unsigned int * V_18 )
{
* V_18 = 0 ;
return 0 ;
}
static T_1 F_189 ( struct V_213 * V_213 , char T_7 * V_253 ,
T_8 V_298 , T_9 * V_447 )
{
struct V_20 * V_21 = V_213 -> V_448 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_480 V_481 ;
V_481 . V_486 = V_298 / 3 ;
V_481 . V_487 = V_253 ;
V_481 . V_488 = V_213 ;
V_481 . V_489 = - V_470 ;
F_43 ( V_10 , V_122 , V_482 , V_490 , & V_481 ) ;
return V_481 . V_489 ;
}
static unsigned int F_190 ( struct V_213 * V_213 , T_10 * V_450 )
{
struct V_20 * V_21 = V_213 -> V_448 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_480 V_481 ;
V_481 . V_488 = V_213 ;
V_481 . V_491 = V_450 ;
V_481 . V_489 = - V_470 ;
F_43 ( V_10 , V_122 , V_482 , V_492 , & V_481 ) ;
return V_481 . V_489 ;
}
static int F_191 ( T_4 V_493 )
{
static char * V_494 [ 16 ] = {
[ V_495 >> 28 ] = L_30 ,
[ V_496 >> 28 ] = L_31 ,
[ V_497 >> 28 ] = L_32 ,
[ V_498 >> 28 ] = L_33 ,
[ V_499 >> 28 ] = L_34 ,
[ V_500 >> 28 ] = L_35 ,
[ V_501 >> 28 ] = L_36 ,
[ V_502 >> 28 ] = L_37 ,
} ;
static int V_503 [ 16 ] = {
[ V_495 >> 28 ] = 2 ,
[ V_498 >> 28 ] = 2 ,
[ V_499 >> 28 ] = 2 ,
[ V_500 >> 28 ] = 5 ,
[ V_501 >> 28 ] = 2 ,
[ V_502 >> 28 ] = 3 ,
} ;
static char * V_48 [] = {
L_38 , L_39 , L_40 , L_41 ,
L_42 , L_43 , L_44 , L_45 ,
L_46 , L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 , L_53 ,
} ;
int V_18 ;
F_192 ( L_54 , V_493 ,
V_494 [ V_493 >> 28 ] ? V_494 [ V_493 >> 28 ] : L_55 ) ;
for ( V_18 = F_12 ( V_48 ) - 1 ; V_18 >= 0 ; V_18 -- )
if ( V_493 & ( 1 << ( V_18 + 12 ) ) )
F_192 ( L_56 , V_48 [ V_18 ] ) ;
F_192 ( L_57 , V_493 & 0xfff ) ;
return V_503 [ V_493 >> 28 ] ? V_503 [ V_493 >> 28 ] : 1 ;
}
static void F_193 ( struct V_9 * V_10 ,
struct V_504 * V_493 )
{
unsigned int V_18 , V_505 , V_366 ;
F_25 ( L_58 ,
V_10 -> V_11 . V_506 . V_312 , V_493 -> V_507 , ( unsigned long ) V_493 -> V_508 ) ;
for ( V_18 = 0 ; V_18 < ( V_493 -> V_288 >> 2 ) ; V_18 += V_366 ) {
F_25 ( L_59 ,
V_10 -> V_11 . V_506 . V_312 ,
( unsigned long ) ( V_493 -> V_508 + ( V_18 << 2 ) ) ) ;
V_366 = F_191 ( F_194 ( V_493 -> V_507 [ V_18 ] ) ) ;
for ( V_505 = 1 ; V_505 < V_366 ; V_505 ++ )
F_25 ( L_60 ,
V_10 -> V_11 . V_506 . V_312 ,
( unsigned long ) ( V_493 -> V_508 + ( ( V_18 + V_505 ) << 2 ) ) ,
V_493 -> V_507 [ V_18 + V_505 ] , V_505 ) ;
if ( 0 == V_493 -> V_507 [ V_18 ] )
break;
}
}
static void F_195 ( struct V_9 * V_10 )
{
F_25 ( L_61 , ( unsigned long long ) V_10 -> main. V_508 ) ;
F_25 ( L_62 ,
V_10 -> V_509 ? ( unsigned long long ) V_10 -> V_509 -> V_29 . V_508 : 0 ,
V_10 -> V_509 ? ( unsigned long long ) V_10 -> V_509 -> V_510 . V_508 : 0 ) ;
F_25 ( L_63 ,
V_10 -> V_165 . V_29
? ( unsigned long long ) V_10 -> V_165 . V_29 -> V_29 . V_508 : 0 ,
V_10 -> V_165 . V_510
? ( unsigned long long ) V_10 -> V_165 . V_510 -> V_510 . V_508 : 0 ) ;
F_25 ( L_64 ,
V_10 -> V_271 ? ( unsigned long long ) V_10 -> V_271 -> V_29 . V_508 : 0 ,
V_10 -> V_271 ? ( unsigned long long ) V_10 -> V_271 -> V_510 . V_508 : 0 ) ;
F_193 ( V_10 , & V_10 -> main ) ;
}
static void F_196 ( T_4 V_511 , T_4 V_512 )
{
unsigned int V_18 ;
F_192 ( L_65 ) ;
for ( V_18 = 0 ; V_18 < F_12 ( V_513 ) ; V_18 ++ ) {
if ( V_511 & ( 1 << V_18 ) )
F_192 ( L_56 , V_513 [ V_18 ] ) ;
if ( V_512 & ( 1 << V_18 ) )
F_192 ( L_66 ) ;
}
}
static void F_197 ( struct V_9 * V_10 , T_4 V_282 )
{
F_198 ( L_67 ,
V_10 -> V_11 . V_61 ,
( unsigned long ) V_10 -> main. V_508 ,
( unsigned long ) F_194 ( V_10 -> main. V_507 [ V_514 + 1 ] ) ,
( unsigned long ) F_194 ( V_10 -> main. V_507 [ V_515 + 1 ] ) ,
( unsigned long ) V_282 ) ;
if ( 0 == ( F_18 ( V_65 ) & V_111 ) ) {
F_199 ( L_68
L_69 ,
V_10 -> V_11 . V_61 ) ;
return;
}
F_199 ( L_70 ,
V_10 -> V_11 . V_61 ) ;
F_199 ( L_71 ,
V_10 -> V_11 . V_61 ) ;
F_200 () ;
}
static int
F_201 ( struct V_9 * V_10 , struct V_516 * V_517 )
{
struct V_264 * V_518 ;
memset ( V_517 , 0 , sizeof( * V_517 ) ) ;
if ( ! F_159 ( & V_10 -> V_304 ) ) {
V_517 -> V_166 = 1 ;
V_518 = F_160 ( V_10 -> V_304 . V_453 , struct V_264 , V_268 . V_303 ) ;
if ( F_202 ( V_518 -> V_268 . V_279 ) )
V_517 -> V_29 = V_518 ;
if ( F_203 ( V_518 -> V_268 . V_279 ) )
V_517 -> V_510 = V_518 ;
if ( ! F_94 ( V_518 -> V_268 . V_279 ) &&
( V_518 -> V_268 . V_303 . V_453 != & V_10 -> V_304 ) ) {
V_518 = F_160 ( V_518 -> V_268 . V_303 . V_453 , struct V_264 , V_268 . V_303 ) ;
if ( ! F_94 ( V_518 -> V_268 . V_279 ) ) {
if ( NULL == V_517 -> V_510 &&
V_290 == V_518 -> V_268 . V_279 ) {
V_517 -> V_510 = V_518 ;
}
if ( NULL != V_517 -> V_29 && NULL != V_517 -> V_510 )
V_517 -> V_519 = 2 ;
}
}
}
if ( NULL != V_10 -> V_271 ) {
if ( F_94 ( V_10 -> V_271 -> V_268 . V_279 ) ) {
if ( NULL == V_517 -> V_29 && NULL == V_517 -> V_510 ) {
V_517 -> V_29 = V_10 -> V_271 ;
V_517 -> V_510 = V_10 -> V_271 ;
}
} else {
if ( V_289 == V_10 -> V_271 -> V_268 . V_279 &&
NULL == V_517 -> V_29 ) {
V_517 -> V_29 = V_10 -> V_271 ;
}
if ( V_290 == V_10 -> V_271 -> V_268 . V_279 &&
NULL == V_517 -> V_510 ) {
V_517 -> V_510 = V_10 -> V_271 ;
}
}
}
F_24 ( L_72 ,
V_10 -> V_11 . V_61 , V_517 -> V_29 , V_517 -> V_510 ,
V_10 -> V_271 , V_517 -> V_166 , V_517 -> V_519 ) ;
return 0 ;
}
static void
F_204 ( struct V_9 * V_10 , struct V_516 * V_520 ,
struct V_516 * V_165 , unsigned int V_269 )
{
struct V_521 V_522 ;
F_205 ( & V_522 ) ;
if ( V_520 -> V_29 == V_520 -> V_510 ) {
if ( NULL != V_520 -> V_29 && V_165 -> V_29 != V_520 -> V_29 ) {
if ( V_523 > 1 )
F_64 ( L_73 ,
V_10 -> V_11 . V_61 , V_520 -> V_29 ) ;
V_520 -> V_29 -> V_268 . V_522 = V_522 ;
V_520 -> V_29 -> V_268 . V_259 = V_10 -> V_259 ;
V_520 -> V_29 -> V_268 . V_269 = V_269 ;
F_206 ( & V_520 -> V_29 -> V_268 . V_462 ) ;
}
} else {
if ( NULL != V_520 -> V_29 && V_165 -> V_29 != V_520 -> V_29 ) {
if ( V_523 > 1 )
F_64 ( L_74 ,
V_10 -> V_11 . V_61 , V_520 -> V_29 ) ;
V_520 -> V_29 -> V_268 . V_522 = V_522 ;
V_520 -> V_29 -> V_268 . V_259 = V_10 -> V_259 ;
V_520 -> V_29 -> V_268 . V_269 = V_269 ;
F_206 ( & V_520 -> V_29 -> V_268 . V_462 ) ;
}
if ( NULL != V_520 -> V_510 && V_165 -> V_510 != V_520 -> V_510 ) {
if ( V_523 > 1 )
F_64 ( L_75 ,
V_10 -> V_11 . V_61 , V_520 -> V_510 ) ;
V_520 -> V_510 -> V_268 . V_522 = V_522 ;
V_520 -> V_510 -> V_268 . V_259 = V_10 -> V_259 ;
V_520 -> V_510 -> V_268 . V_269 = V_269 ;
F_206 ( & V_520 -> V_510 -> V_268 . V_462 ) ;
}
}
}
static void
F_207 ( struct V_9 * V_10 , struct V_264 * V_520 ,
unsigned int V_269 )
{
struct V_521 V_522 ;
if ( NULL == V_520 )
return;
F_205 ( & V_522 ) ;
V_520 -> V_268 . V_522 = V_522 ;
V_520 -> V_268 . V_259 = V_10 -> V_259 ;
V_520 -> V_268 . V_269 = V_269 ;
F_206 ( & V_520 -> V_268 . V_462 ) ;
}
static void F_208 ( unsigned long V_253 )
{
struct V_9 * V_10 = (struct V_9 * ) V_253 ;
struct V_516 V_266 , V_265 ;
struct V_264 * V_524 ;
struct V_264 * V_518 ;
unsigned long V_162 ;
if ( V_63 ) {
F_25 ( L_76 ,
V_10 -> V_11 . V_61 , V_10 -> V_525 , V_10 -> V_526 , V_10 -> V_527 ,
F_18 ( V_528 ) ) ;
F_196 ( F_18 ( V_170 ) , 0 ) ;
F_192 ( L_77 ) ;
}
F_55 ( & V_10 -> V_164 , V_162 ) ;
memset ( & V_265 , 0 , sizeof( V_265 ) ) ;
V_266 = V_10 -> V_165 ;
V_524 = V_10 -> V_509 ;
V_10 -> V_165 = V_265 ;
V_10 -> V_509 = NULL ;
V_10 -> V_272 = 0 ;
F_209 ( V_10 , & V_265 ) ;
F_210 ( V_10 , NULL ) ;
F_60 ( V_10 , 0 ) ;
F_204 ( V_10 , & V_266 , & V_265 , V_463 ) ;
F_207 ( V_10 , V_524 , V_463 ) ;
while ( ! F_159 ( & V_10 -> V_304 ) ) {
V_518 = F_160 ( V_10 -> V_304 . V_453 , struct V_264 , V_268 . V_303 ) ;
F_211 ( & V_518 -> V_268 . V_303 ) ;
V_518 -> V_268 . V_269 = V_463 ;
F_206 ( & V_518 -> V_268 . V_462 ) ;
}
while ( ! F_159 ( & V_10 -> V_529 ) ) {
V_518 = F_160 ( V_10 -> V_529 . V_453 , struct V_264 , V_268 . V_303 ) ;
F_211 ( & V_518 -> V_268 . V_303 ) ;
V_518 -> V_268 . V_269 = V_463 ;
F_206 ( & V_518 -> V_268 . V_462 ) ;
}
V_10 -> V_212 ++ ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
}
static void
F_212 ( struct V_9 * V_10 )
{
struct V_264 * V_520 = V_10 -> V_165 . V_29 ;
if ( NULL == V_520 )
return;
F_213 ( & V_10 -> V_164 ) ;
V_10 -> V_165 . V_519 = 0 ;
V_10 -> V_165 . V_29 = NULL ;
F_214 ( V_10 , V_515 , NULL , 0 ) ;
F_205 ( & V_520 -> V_268 . V_522 ) ;
V_520 -> V_268 . V_259 = V_10 -> V_259 ;
V_520 -> V_268 . V_269 = V_270 ;
F_206 ( & V_520 -> V_268 . V_462 ) ;
F_215 ( & V_10 -> V_164 ) ;
}
static inline int F_216 ( struct V_504 * V_493 , T_4 V_282 )
{
if ( V_282 < V_493 -> V_508 )
return 0 ;
if ( V_282 > V_493 -> V_508 + V_493 -> V_288 )
return 0 ;
return 1 ;
}
static void
F_217 ( struct V_9 * V_10 )
{
struct V_516 V_265 ;
struct V_516 V_266 ;
T_11 V_282 ;
F_213 ( & V_10 -> V_164 ) ;
F_201 ( V_10 , & V_265 ) ;
V_282 = F_18 ( V_528 ) ;
if ( ( V_10 -> V_165 . V_29 && F_216 ( & V_10 -> V_165 . V_29 -> V_29 , V_282 ) ) ||
( V_10 -> V_165 . V_510 && F_216 ( & V_10 -> V_165 . V_510 -> V_510 , V_282 ) ) ) {
V_10 -> V_525 ++ ;
if ( V_530 )
F_197 ( V_10 , V_282 ) ;
F_215 ( & V_10 -> V_164 ) ;
return;
}
V_266 = V_10 -> V_165 ;
V_10 -> V_165 = V_265 ;
V_10 -> V_272 &= ~ 1 ;
F_209 ( V_10 , & V_265 ) ;
F_60 ( V_10 , 0 ) ;
if ( V_12 != V_10 -> V_167 ) {
F_33 ( V_10 , V_10 -> V_167 ) ;
V_10 -> V_167 = V_12 ;
}
F_204 ( V_10 , & V_266 , & V_265 , V_270 ) ;
F_215 ( & V_10 -> V_164 ) ;
}
static void
F_218 ( struct V_9 * V_10 )
{
struct V_264 * V_265 = NULL ;
struct V_264 * V_266 ;
T_4 V_282 ;
F_213 ( & V_10 -> V_164 ) ;
if ( ! F_159 ( & V_10 -> V_529 ) )
V_265 = F_160 ( V_10 -> V_529 . V_453 , struct V_264 , V_268 . V_303 ) ;
V_266 = V_10 -> V_509 ;
V_282 = F_18 ( V_528 ) ;
if ( NULL != V_266 && ( F_216 ( & V_266 -> V_29 , V_282 ) ||
F_216 ( & V_266 -> V_510 , V_282 ) ) ) {
V_10 -> V_525 ++ ;
if ( V_530 )
F_197 ( V_10 , V_282 ) ;
F_215 ( & V_10 -> V_164 ) ;
return;
}
V_10 -> V_509 = V_265 ;
V_10 -> V_272 &= ~ 4 ;
F_210 ( V_10 , V_265 ) ;
F_60 ( V_10 , 0 ) ;
F_207 ( V_10 , V_266 , V_270 ) ;
F_215 ( & V_10 -> V_164 ) ;
}
static T_12 F_219 ( int V_531 , void * V_532 )
{
T_4 V_533 , V_534 ;
T_4 V_535 ;
int V_298 ;
struct V_9 * V_10 ;
int V_536 = 0 ;
V_10 = (struct V_9 * ) V_532 ;
V_298 = 0 ;
while ( 1 ) {
V_533 = F_18 ( V_170 ) ;
V_534 = V_533 & F_18 ( V_173 ) ;
if ( ! V_534 )
break;
V_536 = 1 ;
F_19 ( V_533 , V_170 ) ;
V_535 = F_18 ( V_65 ) ;
if ( V_523 ) {
F_64 ( L_78 ,
V_10 -> V_11 . V_61 , V_298 , V_10 -> V_259 ,
V_533 >> 28 , F_18 ( V_528 ) ) ;
F_196 ( V_533 , V_534 ) ;
if ( V_533 & V_183 )
F_192 ( L_79 ,
V_535 & V_111
? L_80 : L_81 ) ;
if ( V_533 & V_537 )
F_192 ( L_82 ,
V_535 & V_316
? L_80 : L_81 ) ;
if ( V_533 & V_182 )
F_192 ( L_83 ,
V_535 & V_305
? L_84 : L_85 ) ;
F_192 ( L_77 ) ;
}
if ( V_534 & V_258 )
V_10 -> V_259 ++ ;
if ( ( V_534 & V_176 ) && V_10 -> V_538 ) {
F_220 ( V_10 ) ;
}
if ( V_534 & V_172 ) {
V_10 -> V_539 = V_533 ;
F_206 ( & V_10 -> V_540 ) ;
}
if ( ( V_534 & V_180 ) && ( V_533 & ( 4 << 28 ) ) )
F_218 ( V_10 ) ;
if ( ( V_534 & V_180 ) && ( V_533 & ( 2 << 28 ) ) )
F_212 ( V_10 ) ;
if ( ( V_534 & V_180 ) && ( V_533 & ( 1 << 28 ) ) )
F_217 ( V_10 ) ;
if ( ( V_534 & V_183 ) && V_10 -> V_113 )
F_46 ( V_10 , V_10 -> V_106 ) ;
if ( V_534 & ( V_177 | V_181 ) ) {
F_25 ( L_86 ,
V_10 -> V_11 . V_61 ,
( V_534 & V_177 ) ? L_87 : L_88 ,
( V_534 & V_181 ) ? L_89 : L_88 ,
F_18 ( V_528 ) ) ;
F_196 ( V_533 , V_534 ) ;
F_192 ( L_77 ) ;
if ( V_541 )
F_195 ( V_10 ) ;
}
if ( V_178 && V_534 & V_179 ) {
F_25 ( L_90 ,
V_10 -> V_11 . V_61 , F_18 ( V_528 ) ) ;
if ( V_541 )
F_195 ( V_10 ) ;
}
V_298 ++ ;
if ( V_298 > 4 ) {
if ( V_298 > 8 || ! ( V_534 & V_176 ) ) {
F_19 ( 0 , V_173 ) ;
F_21 ( L_91 ,
V_10 -> V_11 . V_61 ) ;
} else {
F_21 ( L_92 ,
V_10 -> V_11 . V_61 ) ;
F_19 ( F_18 ( V_173 ) & ( - 1 ^ V_176 ) ,
V_173 ) ;
} ;
F_196 ( V_533 , V_534 ) ;
F_192 ( L_93 ) ;
}
}
V_10 -> V_527 ++ ;
if ( V_536 )
V_10 -> V_526 ++ ;
return F_221 ( V_536 ) ;
}
static struct V_6 * F_222 ( struct V_9 * V_10 ,
const struct V_6 * V_542 ,
const char * V_543 )
{
struct V_6 * V_7 ;
V_7 = F_223 () ;
if ( NULL == V_7 )
return NULL ;
* V_7 = * V_542 ;
V_7 -> V_506 = & V_10 -> V_11 . V_506 ;
V_7 -> V_544 = V_545 ;
V_7 -> V_546 = V_541 ;
F_224 ( V_7 , V_10 ) ;
snprintf ( V_7 -> V_312 , sizeof( V_7 -> V_312 ) , L_94 ,
V_10 -> V_17 , ( V_10 -> V_17 == 848 && V_10 -> V_547 == 0x12 ) ? L_95 : L_88 ,
V_543 , V_98 [ V_10 -> V_11 . type ] . V_312 ) ;
return V_7 ;
}
static void F_225 ( struct V_9 * V_10 )
{
if ( V_10 -> V_398 ) {
if ( F_226 ( V_10 -> V_398 ) )
F_227 ( V_10 -> V_398 ) ;
else
V_545 ( V_10 -> V_398 ) ;
V_10 -> V_398 = NULL ;
}
if ( V_10 -> V_548 ) {
if ( F_226 ( V_10 -> V_548 ) )
F_227 ( V_10 -> V_548 ) ;
else
V_545 ( V_10 -> V_548 ) ;
V_10 -> V_548 = NULL ;
}
if ( V_10 -> V_484 ) {
if ( F_226 ( V_10 -> V_484 ) )
F_227 ( V_10 -> V_484 ) ;
else
V_545 ( V_10 -> V_484 ) ;
V_10 -> V_484 = NULL ;
}
}
static int T_13 F_228 ( struct V_9 * V_10 )
{
if ( V_393 > 0 )
F_199 ( L_96 ) ;
V_10 -> V_398 = F_222 ( V_10 , & V_549 , L_97 ) ;
if ( NULL == V_10 -> V_398 )
goto V_244;
if ( F_229 ( V_10 -> V_398 , V_468 ,
V_550 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_244;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_166 ( V_10 -> V_398 ) ) ;
if ( F_230 ( & V_10 -> V_398 -> V_8 ,
& V_551 ) < 0 ) {
F_21 ( L_99 , V_10 -> V_11 . V_61 ) ;
goto V_244;
}
V_10 -> V_548 = F_222 ( V_10 , & V_549 , L_100 ) ;
if ( NULL == V_10 -> V_548 )
goto V_244;
if ( F_229 ( V_10 -> V_548 , V_469 ,
V_552 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_244;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_166 ( V_10 -> V_548 ) ) ;
if ( ! V_10 -> V_553 )
return 0 ;
V_10 -> V_484 = F_222 ( V_10 , & V_554 , L_101 ) ;
if ( NULL == V_10 -> V_484 )
goto V_244;
if ( F_229 ( V_10 -> V_484 , V_555 ,
V_556 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_244;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_166 ( V_10 -> V_484 ) ) ;
return 0 ;
V_244:
F_225 ( V_10 ) ;
return - 1 ;
}
static void F_231 ( struct V_557 * V_8 )
{
#if F_232 ( V_558 )
unsigned int V_481 ;
F_233 ( V_8 , V_559 , & V_481 ) ;
V_481 = ( V_481 | V_560 ) ;
F_234 ( V_8 , V_559 , V_481 ) ;
#endif
}
static int T_13 F_235 ( struct V_557 * V_8 ,
const struct V_561 * V_562 )
{
int V_489 ;
unsigned char V_563 ;
struct V_9 * V_10 ;
if ( V_564 == V_565 )
return - V_369 ;
F_25 ( L_102 , V_564 ) ;
V_566 [ V_564 ] = V_10 = F_236 ( sizeof( * V_10 ) , V_368 ) ;
if ( V_10 == NULL ) {
F_21 ( L_103 ) ;
return - V_369 ;
}
V_10 -> V_11 . V_61 = V_564 ;
snprintf ( V_10 -> V_11 . V_506 . V_312 , sizeof( V_10 -> V_11 . V_506 . V_312 ) ,
L_104 , V_10 -> V_11 . V_61 ) ;
F_237 ( & V_10 -> V_472 ) ;
F_238 ( & V_10 -> V_164 ) ;
F_238 ( & V_10 -> V_567 ) ;
F_239 ( & V_10 -> V_540 ) ;
F_240 ( & V_10 -> V_11 . V_568 ) ;
F_240 ( & V_10 -> V_304 ) ;
F_240 ( & V_10 -> V_529 ) ;
F_241 ( & V_10 -> V_245 ) ;
F_242 ( & V_10 -> V_569 ) ;
V_10 -> V_569 . V_570 = F_208 ;
V_10 -> V_569 . V_253 = ( unsigned long ) V_10 ;
V_10 -> V_571 = - 1 ;
V_10 -> V_168 = V_12 ;
V_10 -> V_167 = V_12 ;
V_10 -> V_553 = V_572 [ V_10 -> V_11 . V_61 ] ;
V_10 -> V_11 . V_400 = V_8 ;
V_10 -> V_17 = V_8 -> V_1 ;
if ( F_243 ( V_8 ) ) {
F_198 ( L_105 , V_10 -> V_11 . V_61 ) ;
return - V_573 ;
}
if ( F_244 ( V_8 , F_245 ( 32 ) ) ) {
F_198 ( L_106 , V_10 -> V_11 . V_61 ) ;
return - V_573 ;
}
if ( ! F_246 ( F_247 ( V_8 , 0 ) ,
F_248 ( V_8 , 0 ) ,
V_10 -> V_11 . V_506 . V_312 ) ) {
F_198 ( L_107 ,
V_10 -> V_11 . V_61 ,
( unsigned long long ) F_247 ( V_8 , 0 ) ) ;
return - V_354 ;
}
F_249 ( V_8 ) ;
F_231 ( V_8 ) ;
V_489 = F_250 ( & V_8 -> V_8 , & V_10 -> V_11 . V_506 ) ;
if ( V_489 < 0 ) {
F_198 ( L_108 , V_10 -> V_11 . V_61 ) ;
goto V_574;
}
V_10 -> V_547 = V_8 -> V_547 ;
F_251 ( V_8 , V_575 , & V_563 ) ;
F_25 ( L_109 ,
V_564 , V_10 -> V_17 , V_10 -> V_547 , F_121 ( V_8 ) ,
V_10 -> V_11 . V_400 -> V_531 , V_563 ,
( unsigned long long ) F_247 ( V_8 , 0 ) ) ;
F_252 () ;
V_10 -> V_576 = F_253 ( F_247 ( V_8 , 0 ) , 0x1000 ) ;
if ( NULL == V_10 -> V_576 ) {
F_21 ( L_110 , V_10 -> V_11 . V_61 ) ;
V_489 = - V_573 ;
goto V_577;
}
F_254 ( V_10 ) ;
F_19 ( 0 , V_173 ) ;
V_489 = F_255 ( V_10 -> V_11 . V_400 -> V_531 , F_219 ,
V_578 | V_579 , V_10 -> V_11 . V_506 . V_312 , ( void * ) V_10 ) ;
if ( V_489 < 0 ) {
F_21 ( L_111 ,
V_564 , V_10 -> V_11 . V_400 -> V_531 ) ;
goto V_577;
}
if ( 0 != F_256 ( V_10 ) ) {
V_489 = - V_573 ;
goto V_580;
}
V_10 -> V_228 = V_581 ;
V_10 -> V_210 = V_582 ;
V_10 -> V_113 = V_583 ;
V_10 -> V_196 = V_584 ;
V_10 -> V_203 = V_585 ;
V_10 -> V_233 = V_586 ;
V_10 -> V_235 = V_206 ;
V_10 -> V_237 = V_208 ;
V_10 -> V_93 = V_587 ;
V_10 -> V_240 = V_588 ;
V_10 -> V_242 = V_589 ;
V_10 -> V_375 . V_10 = V_10 ;
V_10 -> V_375 . V_372 . V_357 . V_144 = 320 ;
V_10 -> V_375 . V_372 . V_357 . V_43 = 240 ;
V_10 -> V_375 . V_277 = F_66 ( V_590 ) ;
V_10 -> V_375 . V_144 = 320 ;
V_10 -> V_375 . V_43 = 240 ;
V_10 -> V_72 = 0 ;
if ( V_119 )
F_41 ( V_10 , L_112 ) ;
F_257 ( V_10 ) ;
F_58 ( V_10 ) ;
F_19 ( 0x00 , V_591 ) ;
F_19 ( 0x00 , V_254 ) ;
if ( V_63 )
F_41 ( V_10 , L_113 ) ;
F_258 ( V_10 ) ;
F_259 ( V_10 ) ;
F_260 ( V_10 ) ;
F_261 ( V_10 ) ;
F_57 ( V_10 ) ;
if ( ! V_98 [ V_10 -> V_11 . type ] . V_171 ) {
F_228 ( V_10 ) ;
F_28 ( V_10 , 32768 ) ;
F_30 ( V_10 , 27648 ) ;
F_29 ( V_10 , 32768 ) ;
F_32 ( V_10 , 32768 ) ;
F_46 ( V_10 , 1 ) ;
F_54 ( V_10 , 0 , V_10 -> V_39 ) ;
F_50 ( & V_10 -> V_30 [ 0 ] , V_10 -> V_39 ) ;
V_10 -> V_30 [ 1 ] = V_10 -> V_30 [ 0 ] ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
}
if ( V_98 [ V_10 -> V_11 . type ] . V_592 ) {
F_262 ( & V_10 -> V_11 , L_114 ) ;
F_6 ( V_10 ) ;
}
if ( ! V_593 ) {
F_263 ( V_10 ) ;
F_264 ( V_10 ) ;
}
V_564 ++ ;
return 0 ;
V_580:
F_265 ( V_10 -> V_11 . V_400 -> V_531 , V_10 ) ;
V_577:
F_266 ( & V_10 -> V_11 . V_506 ) ;
V_574:
if ( V_10 -> V_576 )
F_267 ( V_10 -> V_576 ) ;
F_268 ( F_247 ( V_10 -> V_11 . V_400 , 0 ) ,
F_248 ( V_10 -> V_11 . V_400 , 0 ) ) ;
return V_489 ;
}
static void T_14 F_269 ( struct V_557 * V_557 )
{
struct V_594 * V_506 = F_270 ( V_557 ) ;
struct V_9 * V_10 = F_271 ( V_506 ) ;
if ( V_63 )
F_25 ( L_115 , V_10 -> V_11 . V_61 ) ;
if ( V_98 [ V_10 -> V_11 . type ] . V_592 )
F_9 ( V_10 ) ;
F_36 ( ~ 15 , V_195 ) ;
F_19 ( 0 , V_173 ) ;
F_19 ( ~ 0x0 , V_170 ) ;
F_19 ( 0x0 , V_254 ) ;
if ( V_119 )
F_41 ( V_10 , L_116 ) ;
V_10 -> V_595 = 1 ;
F_272 ( V_10 ) ;
F_273 ( & V_10 -> V_11 ) ;
F_274 ( V_10 ) ;
F_225 ( V_10 ) ;
F_275 ( V_10 -> V_11 . V_400 , & V_10 -> main ) ;
F_265 ( V_10 -> V_11 . V_400 -> V_531 , V_10 ) ;
F_267 ( V_10 -> V_576 ) ;
F_268 ( F_247 ( V_10 -> V_11 . V_400 , 0 ) ,
F_248 ( V_10 -> V_11 . V_400 , 0 ) ) ;
F_266 ( & V_10 -> V_11 . V_506 ) ;
V_566 [ V_10 -> V_11 . V_61 ] = NULL ;
F_69 ( V_10 ) ;
return;
}
static int F_276 ( struct V_557 * V_557 , T_15 V_269 )
{
struct V_594 * V_506 = F_270 ( V_557 ) ;
struct V_9 * V_10 = F_271 ( V_506 ) ;
struct V_516 V_596 ;
unsigned long V_162 ;
F_24 ( L_117 , V_10 -> V_11 . V_61 , V_269 . V_597 ) ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
memset ( & V_596 , 0 , sizeof( V_596 ) ) ;
V_10 -> V_269 . V_598 = V_10 -> V_165 ;
V_10 -> V_269 . V_378 = V_10 -> V_509 ;
V_10 -> V_269 . V_272 = V_10 -> V_272 ;
V_10 -> V_165 = V_596 ;
V_10 -> V_272 = 0 ;
F_209 ( V_10 , & V_596 ) ;
F_210 ( V_10 , NULL ) ;
F_60 ( V_10 , 0 ) ;
F_19 ( 0 , V_173 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
V_10 -> V_269 . V_599 = F_18 ( V_254 ) ;
V_10 -> V_269 . V_600 = F_53 () ;
F_277 ( V_557 ) ;
if ( 0 != F_278 ( V_557 , F_279 ( V_557 , V_269 ) ) ) {
F_280 ( V_557 ) ;
V_10 -> V_269 . V_601 = 1 ;
}
return 0 ;
}
static int F_281 ( struct V_557 * V_557 )
{
struct V_594 * V_506 = F_270 ( V_557 ) ;
struct V_9 * V_10 = F_271 ( V_506 ) ;
unsigned long V_162 ;
int V_244 ;
F_24 ( L_118 , V_10 -> V_11 . V_61 ) ;
if ( V_10 -> V_269 . V_601 ) {
V_244 = F_243 ( V_557 ) ;
if ( V_244 ) {
F_198 ( L_105 , V_10 -> V_11 . V_61 ) ;
return V_244 ;
}
V_10 -> V_269 . V_601 = 0 ;
}
V_244 = F_278 ( V_557 , V_602 ) ;
if ( V_244 ) {
F_280 ( V_557 ) ;
F_198 ( L_105 , V_10 -> V_11 . V_61 ) ;
V_10 -> V_269 . V_601 = 1 ;
return V_244 ;
}
F_282 ( V_557 ) ;
F_59 ( V_10 ) ;
F_34 ( 0xffffff , V_10 -> V_269 . V_599 ) ;
F_283 ( V_10 -> V_269 . V_600 ) ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
V_10 -> V_165 = V_10 -> V_269 . V_598 ;
V_10 -> V_509 = V_10 -> V_269 . V_378 ;
V_10 -> V_272 = V_10 -> V_269 . V_272 ;
F_209 ( V_10 , & V_10 -> V_165 ) ;
F_210 ( V_10 , V_10 -> V_509 ) ;
F_60 ( V_10 , 0 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
return 0 ;
}
static int T_16 F_284 ( void )
{
int V_603 ;
V_564 = 0 ;
F_25 ( L_119 , V_604 ) ;
if ( V_299 < 2 || V_299 > V_605 )
V_299 = 2 ;
if ( V_300 > V_606 )
V_300 = V_606 ;
V_300 = ( V_300 + V_607 - 1 ) & V_608 ;
if ( V_63 )
F_25 ( L_120 ,
V_299 , V_300 >> 10 , V_300 >> V_609 ) ;
F_285 () ;
V_603 = F_286 ( & V_610 ) ;
if ( V_603 < 0 ) {
F_198 ( L_121 , V_603 ) ;
return V_603 ;
}
V_603 = F_287 ( & V_611 ) ;
if ( V_603 < 0 )
F_288 ( & V_610 ) ;
return V_603 ;
}
static void T_17 F_289 ( void )
{
F_290 ( & V_611 ) ;
F_288 ( & V_610 ) ;
}
