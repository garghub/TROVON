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
F_25 ( V_63 L_5 ,
V_10 -> V_11 . V_61 , V_10 -> V_57 . V_62 ) ;
F_19 ( 0x00 , V_64 ) ;
F_19 ( 0x00 , V_56 ) ;
V_10 -> V_57 . V_60 = 0 ;
return;
}
F_25 ( V_63 L_6 , V_10 -> V_11 . V_61 ,
V_10 -> V_57 . V_62 , V_10 -> V_57 . V_59 ) ;
F_22 ( V_10 , V_10 -> V_57 . V_62 , V_10 -> V_57 . V_59 ) ;
for ( V_18 = 0 ; V_18 < 10 ; V_18 ++ ) {
F_25 ( L_7 ) ;
F_26 ( 10 ) ;
if ( F_18 ( V_65 ) & V_66 ) {
F_19 ( 0 , V_65 ) ;
} else {
F_19 ( 0x08 , V_64 ) ;
V_10 -> V_57 . V_60 = V_10 -> V_57 . V_59 ;
F_25 ( L_8 ) ;
return;
}
}
V_10 -> V_57 . V_60 = - 1 ;
F_25 ( L_9 ) ;
return;
}
static void F_27 ( struct V_9 * V_10 )
{
int V_18 , V_67 ;
int V_68 = V_40 [ V_10 -> V_39 ] . V_69 ;
int V_70 = V_40 [ V_10 -> V_39 ] . V_71 ;
if ( V_10 -> V_72 == V_10 -> V_73 ) {
F_24 ( L_10 ,
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
F_24 ( V_105 L_11 ,
V_10 -> V_11 . V_61 , V_72 , V_96 ) ;
if( V_98 [ V_10 -> V_11 . type ] . V_106 )
V_98 [ V_10 -> V_11 . type ] . V_106 ( V_10 , V_72 ) ;
return 0 ;
}
static int
F_38 ( struct V_9 * V_10 , int V_72 , int V_107 )
{
int V_108 , signal ;
struct V_109 V_110 ;
F_34 ( V_98 [ V_10 -> V_11 . type ] . V_111 ,
V_98 [ V_10 -> V_11 . type ] . V_111 ) ;
signal = F_18 ( V_65 ) & V_112 ;
V_10 -> V_107 = V_107 ;
V_10 -> V_113 = V_72 ;
V_107 = V_107 || ( V_10 -> V_114 && ! signal && ! V_10 -> V_115 ) ;
if ( V_107 )
V_108 = V_98 [ V_10 -> V_11 . type ] . V_116 ;
else
V_108 = V_98 [ V_10 -> V_11 . type ] . V_117 [ V_72 ] ;
switch ( V_10 -> V_11 . type ) {
case V_118 :
case V_119 :
V_108 = F_39 ( V_10 , V_108 ) ;
break;
default:
F_40 ( V_98 [ V_10 -> V_11 . type ] . V_111 , V_108 ) ;
}
if ( V_120 )
F_41 ( V_10 , V_121 [ V_107 ? 4 : V_72 ] ) ;
if ( F_42 () )
return 0 ;
V_110 . V_17 = V_122 ;
V_110 . V_78 = V_10 -> V_107 ;
F_43 ( V_10 , V_123 , V_124 , & V_110 ) ;
if ( V_10 -> V_125 ) {
T_4 V_126 ;
switch ( V_72 ) {
case V_127 :
V_126 = F_44 ( V_128 , V_129 ,
V_130 , V_130 ) ;
break;
case V_131 :
V_126 = F_44 ( V_132 , V_129 ,
V_130 , V_130 ) ;
break;
case V_133 :
V_126 = F_44 ( V_128 , V_129 ,
V_130 , V_130 ) ;
break;
case V_134 :
default:
if ( V_10 -> V_11 . type == V_119 )
V_126 = F_44 ( V_132 , V_135 , \
V_136 , V_136 ) ;
else
V_126 = V_137 ;
break;
}
F_45 ( V_10 -> V_125 , V_113 , V_138 ,
V_126 , V_139 , 0 ) ;
}
if ( V_10 -> V_140 ) {
F_45 ( V_10 -> V_140 , V_113 , V_138 ,
V_72 , 0 , 0 ) ;
}
return 0 ;
}
static inline int
F_46 ( struct V_9 * V_10 , int V_107 )
{
return F_38 ( V_10 , V_10 -> V_113 , V_107 ) ;
}
static inline int
F_47 ( struct V_9 * V_10 , int V_72 )
{
return F_38 ( V_10 , V_72 , V_10 -> V_107 ) ;
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
case V_118 :
case V_119 :
F_39 ( V_10 , F_53 () ) ;
break;
}
V_17 = V_39 -> V_160 ;
F_43 ( V_10 , V_123 , V_161 , V_17 ) ;
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
V_134 : V_131 ) ;
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
if ( V_212 )
F_21 ( V_63 L_12 , V_10 -> V_11 . V_61 ) ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
V_10 -> V_213 = 0 ;
F_60 ( V_10 , 0 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
F_58 ( V_10 ) ;
V_10 -> V_57 . V_60 = - 1 ;
F_54 ( V_10 , V_10 -> V_72 , V_10 -> V_39 ) ;
}
static int F_61 ( struct V_214 * V_214 , void * V_215 ,
struct V_109 * V_11 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
switch ( V_11 -> V_17 ) {
case V_216 :
V_11 -> V_78 = V_10 -> V_77 ;
break;
case V_217 :
V_11 -> V_78 = V_10 -> V_80 ;
break;
case V_218 :
V_11 -> V_78 = V_10 -> V_84 ;
break;
case V_219 :
V_11 -> V_78 = V_10 -> V_92 ;
break;
case V_122 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
F_43 ( V_10 , V_123 , V_224 , V_11 ) ;
break;
case V_225 :
V_11 -> V_78 = V_10 -> V_196 ;
break;
case V_226 :
V_11 -> V_78 = V_10 -> V_227 ;
break;
case V_228 :
V_11 -> V_78 = V_10 -> V_210 ;
break;
case V_229 :
V_11 -> V_78 = V_10 -> V_114 ;
break;
case V_230 :
V_11 -> V_78 = V_10 -> V_203 ;
break;
case V_231 :
V_11 -> V_78 = V_10 -> V_232 ;
break;
case V_233 :
V_11 -> V_78 = V_10 -> V_234 ;
break;
case V_235 :
V_11 -> V_78 = V_10 -> V_236 ;
break;
case V_237 :
V_11 -> V_78 = V_10 -> V_93 ;
break;
case V_238 :
V_11 -> V_78 = V_10 -> V_239 ;
break;
case V_240 :
V_11 -> V_78 = V_10 -> V_241 ;
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_62 ( struct V_214 * V_214 , void * V_242 ,
struct V_109 * V_11 )
{
int V_243 ;
int V_184 ;
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_243 = F_63 ( & V_10 -> V_244 , V_21 -> V_244 ) ;
if ( 0 != V_243 )
return V_243 ;
switch ( V_11 -> V_17 ) {
case V_216 :
F_28 ( V_10 , V_11 -> V_78 ) ;
break;
case V_217 :
F_29 ( V_10 , V_11 -> V_78 ) ;
break;
case V_218 :
F_30 ( V_10 , V_11 -> V_78 ) ;
break;
case V_219 :
F_32 ( V_10 , V_11 -> V_78 ) ;
break;
case V_122 :
F_46 ( V_10 , V_11 -> V_78 ) ;
case V_220 :
if ( V_10 -> V_245 )
V_10 -> V_245 ( V_10 , V_11 -> V_78 ) ;
F_43 ( V_10 , V_123 , V_124 , V_11 ) ;
break;
case V_221 :
case V_222 :
case V_223 :
F_43 ( V_10 , V_123 , V_124 , V_11 ) ;
break;
case V_225 :
V_10 -> V_196 = V_11 -> V_78 ;
V_184 = V_10 -> V_196 ? V_197 : 0 ;
F_19 ( V_184 , V_198 ) ;
F_19 ( V_184 , V_199 ) ;
break;
case V_226 :
V_10 -> V_227 = V_11 -> V_78 ;
break;
case V_228 :
V_10 -> V_210 = V_11 -> V_78 ;
if ( V_10 -> V_210 ) {
F_36 ( ~ V_211 , V_86 ) ;
F_36 ( ~ V_211 , V_87 ) ;
} else {
F_35 ( V_211 , V_86 ) ;
F_35 ( V_211 , V_87 ) ;
}
break;
case V_229 :
V_10 -> V_114 = V_11 -> V_78 ;
break;
case V_230 :
V_10 -> V_203 = V_11 -> V_78 ;
F_19 ( V_202 |
( V_10 -> V_203 ? V_204 : 0 ) ,
V_205 ) ;
break;
case V_231 :
V_10 -> V_232 = V_11 -> V_78 ;
break;
case V_233 :
V_10 -> V_234 = V_11 -> V_78 ;
F_19 ( V_11 -> V_78 , V_207 ) ;
break;
case V_235 :
V_10 -> V_236 = V_11 -> V_78 ;
F_19 ( V_11 -> V_78 , V_209 ) ;
break;
case V_237 :
V_10 -> V_93 = V_11 -> V_78 ;
F_32 ( V_10 , V_10 -> V_92 ) ;
break;
case V_238 :
V_10 -> V_239 = V_11 -> V_78 ;
F_31 ( ( V_11 -> V_78 << 7 ) , ~ V_246 , V_247 ) ;
break;
case V_240 :
V_10 -> V_241 = V_11 -> V_78 ;
F_31 ( ( V_11 -> V_78 << 5 ) , ~ V_248 , V_247 ) ;
break;
default:
return - V_100 ;
}
return 0 ;
}
void F_41 ( struct V_9 * V_10 , char * V_249 )
{
unsigned int V_250 , V_251 ;
V_250 = F_18 ( V_252 ) ;
V_251 = F_18 ( V_253 ) ;
F_21 ( V_105 L_13 ,
V_10 -> V_11 . V_61 , V_250 , V_251 & V_250 , V_251 & ~ V_250 , V_249 ) ;
}
static void F_64 ( struct V_9 * V_10 )
{
int V_254 = 0 ;
if ( V_10 -> V_255 )
V_254 ++ ;
if ( V_254 ) {
F_35 ( V_256 , V_173 ) ;
} else {
F_36 ( ~ V_256 , V_173 ) ;
V_10 -> V_257 = 0 ;
}
}
static const struct V_258 *
F_65 ( int V_259 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_260 ; V_18 ++ ) {
if ( - 1 == V_261 [ V_18 ] . V_259 )
continue;
if ( V_261 [ V_18 ] . V_259 == V_259 )
return V_261 + V_18 ;
}
return NULL ;
}
static int
F_66 ( struct V_9 * V_10 , struct V_20 * V_21 ,
struct V_262 * V_263 )
{
struct V_262 * V_264 ;
unsigned long V_162 ;
int V_265 = 0 ;
F_24 ( L_14 , V_263 ) ;
if ( V_263 )
V_263 -> V_266 . V_267 = V_268 ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
V_264 = V_10 -> V_269 ;
V_10 -> V_269 = V_263 ;
V_10 -> V_270 |= 1 ;
F_60 ( V_10 , 0x03 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
if ( NULL != V_264 ) {
F_24 ( L_15 , V_264 , V_264 -> V_266 . V_267 ) ;
F_67 ( & V_21 -> V_271 , V_10 , V_264 ) ;
F_68 ( V_264 ) ;
}
if ( NULL == V_263 )
F_20 ( V_10 , V_21 , V_272 ) ;
F_24 ( L_16 ) ;
return V_265 ;
}
static int F_69 ( struct V_273 * V_274 , struct V_9 * V_10 ,
struct V_262 * V_5 ,
const struct V_258 * V_275 ,
unsigned int V_144 , unsigned int V_43 ,
enum V_276 V_277 )
{
struct V_20 * V_21 = V_274 -> V_278 ;
int V_279 = 0 ;
struct V_141 V_11 ;
int V_147 ;
int V_280 ;
if ( NULL == V_275 )
return - V_100 ;
if ( V_275 -> V_281 == V_282 ) {
V_144 = V_283 ;
V_43 = V_284 * 2 ;
if ( V_144 * V_43 > V_5 -> V_266 . V_285 )
return - V_100 ;
V_5 -> V_266 . V_286 = V_5 -> V_266 . V_285 ;
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
switch ( V_277 ) {
case V_287 :
case V_288 :
case V_289 :
if ( V_43 * 2 > V_11 . V_146 )
return - V_100 ;
break;
default:
if ( V_43 > V_11 . V_146 )
return - V_100 ;
break;
}
V_5 -> V_266 . V_286 = ( V_144 * V_43 * V_275 -> V_290 ) >> 3 ;
if ( 0 != V_5 -> V_266 . V_291 && V_5 -> V_266 . V_285 < V_5 -> V_266 . V_286 )
return - V_100 ;
}
if ( V_5 -> V_266 . V_144 != V_144 || V_5 -> V_266 . V_43 != V_43 ||
V_5 -> V_266 . V_277 != V_277 ||
V_5 -> V_39 != V_147 || V_5 -> V_275 != V_275 ||
V_5 -> V_30 . V_29 != V_11 . V_32 . V_29 ||
V_5 -> V_30 . V_292 != V_11 . V_32 . V_292 ||
V_5 -> V_30 . V_144 != V_11 . V_32 . V_144 ||
V_5 -> V_30 . V_43 != V_11 . V_32 . V_43 ) {
V_5 -> V_266 . V_144 = V_144 ;
V_5 -> V_266 . V_43 = V_43 ;
V_5 -> V_266 . V_277 = V_277 ;
V_5 -> V_39 = V_147 ;
V_5 -> V_275 = V_275 ;
V_5 -> V_30 = V_11 . V_32 ;
V_279 = 1 ;
}
if ( V_293 == V_5 -> V_266 . V_267 ) {
V_279 = 1 ;
if ( 0 != ( V_280 = F_70 ( V_274 , & V_5 -> V_266 , & V_10 -> V_294 ) ) )
goto V_27;
}
if ( V_279 )
if ( 0 != ( V_280 = F_71 ( V_10 , V_5 ) ) )
goto V_27;
V_5 -> V_266 . V_267 = V_295 ;
return 0 ;
V_27:
F_67 ( V_274 , V_10 , V_5 ) ;
return V_280 ;
}
static int
F_72 ( struct V_273 * V_274 , unsigned int * V_296 , unsigned int * V_286 )
{
struct V_20 * V_21 = V_274 -> V_278 ;
* V_286 = V_21 -> V_275 -> V_290 * V_21 -> V_144 * V_21 -> V_43 >> 3 ;
if ( 0 == * V_296 )
* V_296 = V_297 ;
if ( * V_286 * * V_296 > V_297 * V_298 )
* V_296 = ( V_297 * V_298 ) / * V_286 ;
return 0 ;
}
static int
F_73 ( struct V_273 * V_274 , struct V_299 * V_266 ,
enum V_276 V_277 )
{
struct V_262 * V_5 = F_2 ( V_266 , struct V_262 , V_266 ) ;
struct V_20 * V_21 = V_274 -> V_278 ;
return F_69 ( V_274 , V_21 -> V_10 , V_5 , V_21 -> V_275 ,
V_21 -> V_144 , V_21 -> V_43 , V_277 ) ;
}
static void
F_74 ( struct V_273 * V_274 , struct V_299 * V_266 )
{
struct V_262 * V_5 = F_2 ( V_266 , struct V_262 , V_266 ) ;
struct V_20 * V_21 = V_274 -> V_278 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_5 -> V_266 . V_267 = V_300 ;
F_75 ( & V_5 -> V_266 . V_301 , & V_10 -> V_302 ) ;
if ( ! V_10 -> V_165 . V_166 ) {
V_10 -> V_270 |= 1 ;
F_60 ( V_10 , 0x03 ) ;
}
}
static void F_76 ( struct V_273 * V_274 , struct V_299 * V_266 )
{
struct V_262 * V_5 = F_2 ( V_266 , struct V_262 , V_266 ) ;
struct V_20 * V_21 = V_274 -> V_278 ;
F_67 ( V_274 , V_21 -> V_10 , V_5 ) ;
}
static int F_77 ( struct V_214 * V_214 , void * V_215 , T_5 * V_17 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
unsigned int V_18 ;
int V_243 ;
V_243 = F_63 ( & V_10 -> V_244 , V_21 -> V_244 ) ;
if ( V_243 )
goto V_243;
for ( V_18 = 0 ; V_18 < V_149 ; V_18 ++ )
if ( * V_17 & V_40 [ V_18 ] . V_160 )
break;
if ( V_18 == V_149 ) {
V_243 = - V_100 ;
goto V_243;
}
F_51 ( V_10 , V_18 ) ;
V_243:
return V_243 ;
}
static int F_78 ( struct V_214 * V_214 , void * V_242 , T_5 * V_17 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( F_18 ( V_65 ) & V_303 )
* V_17 = V_304 ;
else
* V_17 = V_305 ;
return 0 ;
}
static int F_79 ( struct V_214 * V_214 , void * V_215 ,
struct V_306 * V_18 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_280 = 0 ;
if ( V_18 -> V_307 >= V_98 [ V_10 -> V_11 . type ] . V_99 ) {
V_280 = - V_100 ;
goto V_243;
}
V_18 -> type = V_308 ;
V_18 -> V_309 = 1 ;
if ( V_10 -> V_168 != V_169 && V_18 -> V_307 == 0 ) {
sprintf ( V_18 -> V_310 , L_17 ) ;
V_18 -> type = V_311 ;
V_18 -> V_312 = 0 ;
} else if ( V_18 -> V_307 == V_10 -> V_102 ) {
sprintf ( V_18 -> V_310 , L_18 ) ;
} else {
sprintf ( V_18 -> V_310 , L_19 , V_18 -> V_307 ) ;
}
if ( V_18 -> V_307 == V_10 -> V_72 ) {
T_6 V_313 = F_18 ( V_65 ) ;
if ( 0 == ( V_313 & V_314 ) )
V_18 -> V_315 |= V_316 ;
if ( 0 == ( V_313 & V_112 ) )
V_18 -> V_315 |= V_317 ;
}
V_18 -> V_318 = V_319 ;
V_243:
return V_280 ;
}
static int F_80 ( struct V_214 * V_214 , void * V_215 , unsigned int * V_18 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_18 = V_10 -> V_72 ;
return 0 ;
}
static int F_81 ( struct V_214 * V_214 , void * V_215 , unsigned int V_18 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_243 ;
V_243 = F_63 ( & V_10 -> V_244 , V_21 -> V_244 ) ;
if ( F_82 ( V_243 ) )
goto V_243;
if ( V_18 > V_98 [ V_10 -> V_11 . type ] . V_99 ) {
V_243 = - V_100 ;
goto V_243;
}
F_54 ( V_10 , V_18 , V_10 -> V_39 ) ;
V_243:
return 0 ;
}
static int F_83 ( struct V_214 * V_214 , void * V_215 ,
struct V_320 * V_321 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_243 ;
if ( F_82 ( 0 != V_321 -> V_307 ) )
return - V_100 ;
if ( F_82 ( V_10 -> V_168 == V_169 ) ) {
V_243 = - V_100 ;
goto V_243;
}
V_243 = F_63 ( & V_10 -> V_244 , V_21 -> V_244 ) ;
if ( F_82 ( V_243 ) )
goto V_243;
F_43 ( V_10 , V_312 , V_322 , V_321 ) ;
if ( V_10 -> V_323 )
V_10 -> V_323 ( V_10 , V_321 , 1 ) ;
V_243:
return 0 ;
}
static int F_84 ( struct V_214 * V_214 , void * V_215 ,
struct V_324 * V_242 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_242 -> type = V_10 -> V_115 ? V_325 : V_326 ;
V_242 -> V_327 = V_10 -> V_328 ;
return 0 ;
}
static int F_85 ( struct V_214 * V_214 , void * V_215 ,
struct V_324 * V_242 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_243 ;
if ( F_82 ( V_242 -> V_312 != 0 ) )
return - V_100 ;
V_243 = F_63 ( & V_10 -> V_244 , V_21 -> V_244 ) ;
if ( F_82 ( V_243 ) )
goto V_243;
if ( F_82 ( V_242 -> type != ( V_10 -> V_115
? V_325 : V_326 ) ) ) {
V_243 = - V_100 ;
goto V_243;
}
V_10 -> V_328 = V_242 -> V_327 ;
F_43 ( V_10 , V_312 , V_329 , V_242 ) ;
if ( V_10 -> V_330 && V_10 -> V_115 )
F_86 ( V_10 , V_10 -> V_328 ) ;
V_243:
return 0 ;
}
static int F_87 ( struct V_214 * V_214 , void * V_242 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
F_21 ( V_63 L_20 ,
V_10 -> V_11 . V_61 , V_10 -> V_11 . V_61 ) ;
F_43 ( V_10 , V_123 , V_331 ) ;
F_21 ( V_63 L_21 ,
V_10 -> V_11 . V_61 , V_10 -> V_11 . V_61 ) ;
return 0 ;
}
static int F_88 ( struct V_214 * V_214 , void * V_242 ,
struct V_332 * V_333 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( ! F_89 ( V_334 ) )
return - V_335 ;
if ( ! F_90 ( & V_333 -> V_336 ) )
return - V_100 ;
V_333 -> V_333 &= 0xfff ;
V_333 -> V_184 = F_18 ( V_333 -> V_333 ) ;
V_333 -> V_286 = 1 ;
return 0 ;
}
static int F_91 ( struct V_214 * V_214 , void * V_242 ,
struct V_332 * V_333 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( ! F_89 ( V_334 ) )
return - V_335 ;
if ( ! F_90 ( & V_333 -> V_336 ) )
return - V_100 ;
V_333 -> V_333 &= 0xfff ;
F_19 ( V_333 -> V_184 , V_333 -> V_333 ) ;
return 0 ;
}
static void
F_92 ( struct V_141 * V_11 ,
const struct V_337 * V_338 ,
T_2 V_144 ,
T_2 V_43 ,
enum V_276 V_277 )
{
T_2 V_339 = V_43 << ! F_93 ( V_277 ) ;
T_2 V_340 ;
T_2 V_341 ;
if ( V_144 < V_11 -> V_142 ) {
V_11 -> V_32 . V_144 = V_144 * 16 ;
} else if ( V_144 > V_11 -> V_145 ) {
V_11 -> V_32 . V_144 = V_144 ;
V_340 = V_338 -> V_292 + V_338 -> V_144 - V_144 ;
V_340 = F_94 ( V_340 , ( T_2 ) V_342 ) ;
if ( V_11 -> V_32 . V_292 > V_340 )
V_11 -> V_32 . V_292 = V_340 ;
}
if ( V_43 < V_11 -> V_143 ) {
V_11 -> V_32 . V_43 = V_43 * 16 ;
} else if ( V_339 > V_11 -> V_146 ) {
V_11 -> V_32 . V_43 = ( V_339 + 1 ) & ~ 1 ;
V_341 = V_338 -> V_29 + V_338 -> V_43 - V_11 -> V_32 . V_43 ;
if ( V_11 -> V_32 . V_29 > V_341 )
V_11 -> V_32 . V_29 = V_341 ;
}
F_48 ( V_11 ) ;
}
static int
F_95 ( struct V_20 * V_21 ,
T_2 * V_144 ,
T_2 * V_43 ,
enum V_276 V_277 ,
unsigned int V_343 ,
unsigned int V_344 ,
int V_345 ,
int V_346 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_337 * V_338 ;
struct V_141 * V_11 ;
T_2 V_347 ;
T_2 V_348 ;
T_2 V_349 ;
T_2 V_350 ;
int V_280 ;
F_52 ( ( int ) V_343 >= 0 ||
V_344 >= ( unsigned int ) - V_343 ) ;
V_338 = & V_40 [ V_10 -> V_39 ] . V_41 . V_42 ;
V_11 = & V_10 -> V_30 [ ! ! V_21 -> V_31 ] ;
if ( V_21 -> V_31
&& V_345
&& V_346
&& ! F_15 ( V_10 , V_28 ) ) {
V_347 = 48 ;
V_348 = 32 ;
V_349 = F_94 ( V_338 -> V_144 , ( T_2 ) V_351 ) ;
V_350 = V_338 -> V_43 ;
if ( V_10 -> V_33 > V_338 -> V_29 ) {
V_350 -= V_10 -> V_33 - V_338 -> V_29 ;
V_280 = - V_352 ;
if ( V_348 > V_350 )
goto V_27;
}
} else {
V_280 = - V_352 ;
if ( V_10 -> V_33 > V_11 -> V_32 . V_29 )
goto V_27;
V_347 = V_11 -> V_142 ;
V_348 = V_11 -> V_143 ;
V_349 = V_11 -> V_145 ;
V_350 = V_11 -> V_146 ;
V_346 = 0 ;
}
V_347 = ( V_347 - V_343 - 1 ) & V_343 ;
V_349 = V_349 & V_343 ;
V_348 = V_348 ;
V_350 >>= ! F_93 ( V_277 ) ;
if ( V_345 ) {
* V_144 = F_96 ( * V_144 , V_347 , V_349 ) ;
* V_43 = F_96 ( * V_43 , V_348 , V_350 ) ;
* V_144 = ( * V_144 + V_344 ) & V_343 ;
if ( V_346 ) {
F_92 ( V_11 , V_338 , * V_144 , * V_43 , V_277 ) ;
if ( V_10 -> V_33 > V_11 -> V_32 . V_29 ) {
V_11 -> V_32 . V_29 = V_10 -> V_33 ;
}
}
} else {
V_280 = - V_100 ;
if ( * V_144 < V_347 ||
* V_43 < V_348 ||
* V_144 > V_349 ||
* V_43 > V_350 ||
0 != ( * V_144 & ~ V_343 ) )
goto V_27;
}
V_280 = 0 ;
V_27:
return V_280 ;
}
static int
F_97 ( struct V_20 * V_21 ,
struct V_353 * V_354 ,
int V_345 ,
int V_346 )
{
enum V_276 V_277 ;
unsigned int V_343 ;
int V_280 ;
if ( V_354 -> V_355 . V_144 < 48 || V_354 -> V_355 . V_43 < 32 )
return - V_100 ;
if ( V_354 -> V_356 > 2048 )
return - V_100 ;
V_277 = V_354 -> V_277 ;
if ( V_357 == V_277 ) {
T_2 V_358 ;
V_358 = V_21 -> V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_43 >> 1 ;
V_277 = ( V_354 -> V_355 . V_43 > V_358 )
? V_359
: V_287 ;
}
switch ( V_277 ) {
case V_287 :
case V_288 :
case V_359 :
break;
default:
return - V_100 ;
}
if ( NULL == V_21 -> V_360 )
return - V_100 ;
V_343 = ~ 0 ;
switch ( V_21 -> V_360 -> V_290 ) {
case 8 :
case 24 :
V_343 = ~ 3 ;
break;
case 16 :
V_343 = ~ 1 ;
break;
case 32 :
break;
default:
F_98 () ;
}
V_354 -> V_355 . V_144 -= V_354 -> V_355 . V_292 & ~ V_343 ;
V_354 -> V_355 . V_292 = ( V_354 -> V_355 . V_292 - V_343 - 1 ) & V_343 ;
V_280 = F_95 ( V_21 , & V_354 -> V_355 . V_144 , & V_354 -> V_355 . V_43 ,
V_277 , V_343 ,
0 ,
V_345 , V_346 ) ;
if ( 0 != V_280 )
return V_280 ;
V_354 -> V_277 = V_277 ;
return 0 ;
}
static int F_99 ( struct V_20 * V_21 , struct V_9 * V_10 ,
struct V_353 * V_354 , int V_361 )
{
struct V_362 * V_363 = NULL ;
int V_364 , V_286 , V_265 = 0 ;
if ( NULL == V_21 -> V_360 )
return - V_100 ;
if ( ! ( V_21 -> V_360 -> V_162 & V_365 ) )
return - V_100 ;
V_265 = F_97 ( V_21 , V_354 ,
V_361 ,
V_361 ) ;
if ( 0 != V_265 )
return V_265 ;
V_364 = V_354 -> V_356 ;
V_286 = sizeof( * V_363 ) * ( V_364 + 4 ) ;
V_363 = F_100 ( V_286 , V_366 ) ;
if ( NULL == V_363 )
return - V_367 ;
if ( V_364 > 0 ) {
if ( F_101 ( V_363 , V_354 -> V_363 , sizeof( struct V_362 ) * V_364 ) ) {
F_68 ( V_363 ) ;
return - V_368 ;
}
}
if ( NULL != V_10 -> V_294 . V_369 )
V_364 = F_102 ( V_10 -> V_294 . V_275 . V_144 , V_10 -> V_294 . V_275 . V_43 ,
& V_354 -> V_355 , V_363 , V_364 ) ;
F_103 ( V_363 , V_364 ) ;
switch ( V_21 -> V_360 -> V_290 ) {
case 8 :
case 24 :
F_104 ( & V_354 -> V_355 , V_363 , V_364 , 3 ) ;
break;
case 16 :
F_104 ( & V_354 -> V_355 , V_363 , V_364 , 1 ) ;
break;
case 32 :
break;
default:
F_98 () ;
}
F_68 ( V_21 -> V_370 . V_363 ) ;
V_21 -> V_370 . V_363 = V_363 ;
V_21 -> V_370 . V_371 = V_364 ;
V_21 -> V_370 . V_355 = V_354 -> V_355 ;
V_21 -> V_370 . V_277 = V_354 -> V_277 ;
V_21 -> V_370 . V_372 = 1 ;
V_10 -> V_373 . V_370 . V_355 . V_144 = V_354 -> V_355 . V_144 ;
V_10 -> V_373 . V_370 . V_355 . V_43 = V_354 -> V_355 . V_43 ;
V_10 -> V_373 . V_370 . V_277 = V_354 -> V_277 ;
V_265 = 0 ;
if ( F_14 ( V_21 , V_272 ) ) {
struct V_262 * V_263 ;
V_263 = F_105 ( sizeof( * V_263 ) ) ;
V_263 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_106 ( V_10 , & V_21 -> V_370 , V_21 -> V_360 , V_263 ) ;
V_265 = F_66 ( V_10 , V_21 , V_263 ) ;
}
return V_265 ;
}
static struct V_273 * F_107 ( struct V_20 * V_21 )
{
struct V_273 * V_274 = NULL ;
switch ( V_21 -> type ) {
case V_374 :
V_274 = & V_21 -> V_271 ;
break;
case V_375 :
V_274 = & V_21 -> V_376 ;
break;
default:
F_98 () ;
}
return V_274 ;
}
static int F_108 ( struct V_20 * V_21 )
{
int V_377 = 0 ;
switch ( V_21 -> type ) {
case V_374 :
V_377 = V_26 ;
break;
case V_375 :
V_377 = V_378 ;
break;
default:
F_98 () ;
}
return V_377 ;
}
static int F_109 ( struct V_20 * V_21 , enum V_379 type )
{
struct V_273 * V_274 = F_107 ( V_21 ) ;
int V_377 = F_108 ( V_21 ) ;
if ( F_14 ( V_21 , V_377 ) )
return - V_352 ;
if ( F_110 ( V_274 ) )
return - V_352 ;
V_21 -> type = type ;
return 0 ;
}
static void
F_111 ( struct V_380 * V_242 ,
const struct V_258 * V_275 ,
unsigned int V_144 ,
unsigned int V_43 )
{
V_242 -> V_144 = V_144 ;
V_242 -> V_43 = V_43 ;
if ( V_275 -> V_162 & V_381 ) {
V_242 -> V_382 = V_144 ;
V_242 -> V_383 = ( V_144 * V_43 * V_275 -> V_290 ) >> 3 ;
} else {
V_242 -> V_382 = ( V_144 * V_275 -> V_290 ) >> 3 ;
V_242 -> V_383 = V_43 * V_242 -> V_382 ;
}
}
static int F_112 ( struct V_214 * V_214 , void * V_215 ,
struct V_384 * V_242 )
{
struct V_20 * V_21 = V_215 ;
F_111 ( & V_242 -> V_275 . V_385 , V_21 -> V_275 ,
V_21 -> V_144 , V_21 -> V_43 ) ;
V_242 -> V_275 . V_385 . V_277 = V_21 -> V_271 . V_277 ;
V_242 -> V_275 . V_385 . V_386 = V_21 -> V_275 -> V_259 ;
return 0 ;
}
static int F_113 ( struct V_214 * V_214 , void * V_215 ,
struct V_384 * V_242 )
{
struct V_20 * V_21 = V_215 ;
V_242 -> V_275 . V_354 . V_355 = V_21 -> V_370 . V_355 ;
V_242 -> V_275 . V_354 . V_277 = V_21 -> V_370 . V_277 ;
return 0 ;
}
static int F_114 ( struct V_214 * V_214 , void * V_215 ,
struct V_384 * V_242 )
{
const struct V_258 * V_275 ;
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
enum V_276 V_277 ;
T_2 V_144 , V_43 ;
int V_280 ;
V_275 = F_65 ( V_242 -> V_275 . V_385 . V_386 ) ;
if ( NULL == V_275 )
return - V_100 ;
V_277 = V_242 -> V_275 . V_385 . V_277 ;
if ( V_357 == V_277 ) {
T_2 V_358 ;
V_358 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_43 >> 1 ;
V_277 = ( V_242 -> V_275 . V_385 . V_43 > V_358 )
? V_359
: V_288 ;
}
if ( V_387 == V_277 )
V_277 = V_388 ;
switch ( V_277 ) {
case V_287 :
case V_288 :
case V_289 :
case V_359 :
break;
case V_388 :
if ( V_275 -> V_162 & V_381 )
return - V_100 ;
break;
default:
return - V_100 ;
}
V_144 = V_242 -> V_275 . V_385 . V_144 ;
V_43 = V_242 -> V_275 . V_385 . V_43 ;
V_280 = F_95 ( V_21 , & V_144 , & V_43 , V_277 ,
~ 3 ,
2 ,
1 ,
0 ) ;
if ( 0 != V_280 )
return V_280 ;
V_242 -> V_275 . V_385 . V_277 = V_277 ;
F_111 ( & V_242 -> V_275 . V_385 , V_275 , V_144 , V_43 ) ;
return 0 ;
}
static int F_115 ( struct V_214 * V_214 , void * V_215 ,
struct V_384 * V_242 )
{
struct V_20 * V_21 = V_215 ;
return F_97 ( V_21 , & V_242 -> V_275 . V_354 ,
1 ,
0 ) ;
}
static int F_116 ( struct V_214 * V_214 , void * V_215 ,
struct V_384 * V_242 )
{
int V_265 ;
const struct V_258 * V_275 ;
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
T_2 V_144 , V_43 ;
enum V_276 V_277 ;
V_265 = F_109 ( V_21 , V_242 -> type ) ;
if ( 0 != V_265 )
return V_265 ;
V_265 = F_114 ( V_214 , V_215 , V_242 ) ;
if ( 0 != V_265 )
return V_265 ;
V_144 = V_242 -> V_275 . V_385 . V_144 ;
V_43 = V_242 -> V_275 . V_385 . V_43 ;
V_277 = V_242 -> V_275 . V_385 . V_277 ;
V_265 = F_95 ( V_21 , & V_144 , & V_43 , V_242 -> V_275 . V_385 . V_277 ,
~ 3 ,
2 ,
1 ,
1 ) ;
if ( 0 != V_265 )
return V_265 ;
V_242 -> V_275 . V_385 . V_277 = V_277 ;
V_275 = F_65 ( V_242 -> V_275 . V_385 . V_386 ) ;
V_21 -> V_275 = V_275 ;
V_21 -> V_271 . V_277 = V_242 -> V_275 . V_385 . V_277 ;
V_21 -> V_271 . V_389 = V_390 ;
V_21 -> V_144 = V_242 -> V_275 . V_385 . V_144 ;
V_21 -> V_43 = V_242 -> V_275 . V_385 . V_43 ;
V_10 -> V_373 . V_275 = V_275 ;
V_10 -> V_373 . V_144 = V_242 -> V_275 . V_385 . V_144 ;
V_10 -> V_373 . V_43 = V_242 -> V_275 . V_385 . V_43 ;
return 0 ;
}
static int F_117 ( struct V_214 * V_214 , void * V_215 ,
struct V_384 * V_242 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_391 > 0 ) {
F_21 ( V_392 L_22 ) ;
return - V_100 ;
}
return F_99 ( V_21 , V_10 , & V_242 -> V_275 . V_354 , 1 ) ;
}
static int F_118 ( struct V_214 * V_214 , void * V_215 ,
struct V_393 * V_271 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( 0 == V_394 )
return - V_100 ;
F_119 ( V_271 -> V_395 , L_23 , sizeof( V_271 -> V_395 ) ) ;
F_119 ( V_271 -> V_396 , V_10 -> V_397 -> V_310 , sizeof( V_271 -> V_396 ) ) ;
snprintf ( V_271 -> V_398 , sizeof( V_271 -> V_398 ) ,
L_24 , F_120 ( V_10 -> V_11 . V_399 ) ) ;
V_271 -> V_400 = V_401 ;
V_271 -> V_402 =
V_403 |
V_404 |
V_405 |
V_406 ;
if ( V_391 <= 0 )
V_271 -> V_402 |= V_407 ;
if ( V_10 -> V_408 )
V_271 -> V_402 |= V_409 ;
if ( V_10 -> V_168 != V_169 )
V_271 -> V_402 |= V_410 ;
return 0 ;
}
static int F_121 ( struct V_411 * V_242 )
{
int V_307 = - 1 , V_18 ;
for ( V_18 = 0 ; V_18 < V_260 ; V_18 ++ ) {
if ( V_261 [ V_18 ] . V_259 != - 1 )
V_307 ++ ;
if ( ( unsigned int ) V_307 == V_242 -> V_307 )
break;
}
if ( V_260 == V_18 )
return - V_100 ;
V_242 -> V_386 = V_261 [ V_18 ] . V_259 ;
F_119 ( V_242 -> V_412 , V_261 [ V_18 ] . V_310 , sizeof( V_242 -> V_412 ) ) ;
return V_18 ;
}
static int F_122 ( struct V_214 * V_214 , void * V_215 ,
struct V_411 * V_242 )
{
int V_280 = F_121 ( V_242 ) ;
if ( V_280 < 0 )
return V_280 ;
return 0 ;
}
static int F_123 ( struct V_214 * V_214 , void * V_215 ,
struct V_411 * V_242 )
{
int V_280 ;
if ( V_391 > 0 ) {
F_21 ( V_392 L_22 ) ;
return - V_100 ;
}
V_280 = F_121 ( V_242 ) ;
if ( V_280 < 0 )
return V_280 ;
if ( ! ( V_261 [ V_280 ] . V_162 & V_365 ) )
return - V_100 ;
return 0 ;
}
static int F_124 ( struct V_214 * V_214 , void * V_242 ,
struct V_413 * V_414 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_414 = V_10 -> V_294 ;
V_414 -> V_415 = V_416 ;
if ( V_21 -> V_360 )
V_414 -> V_275 . V_386 = V_21 -> V_360 -> V_259 ;
return 0 ;
}
static int F_125 ( struct V_214 * V_214 , void * V_242 , unsigned int V_417 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_262 * V_263 ;
int V_265 = 0 ;
if ( V_417 ) {
if ( F_82 ( ! V_10 -> V_294 . V_369 ) ) {
return - V_100 ;
}
if ( F_82 ( ! V_21 -> V_370 . V_372 ) ) {
F_24 ( L_25 , V_10 -> V_11 . V_61 ) ;
V_265 = - V_100 ;
}
if ( V_265 )
return V_265 ;
}
if ( ! F_13 ( V_10 , V_21 , V_272 ) )
return - V_352 ;
if ( V_417 ) {
V_21 -> V_370 . V_39 = V_10 -> V_39 ;
V_263 = F_105 ( sizeof( * V_263 ) ) ;
V_263 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_106 ( V_10 , & V_21 -> V_370 , V_21 -> V_360 , V_263 ) ;
} else {
V_263 = NULL ;
}
V_265 = F_66 ( V_10 , V_21 , V_263 ) ;
return V_265 ;
}
static int F_126 ( struct V_214 * V_214 , void * V_242 ,
struct V_413 * V_414 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_258 * V_275 ;
int V_265 ;
if ( ! F_89 ( V_334 ) &&
! F_89 ( V_418 ) )
return - V_335 ;
V_275 = F_65 ( V_414 -> V_275 . V_386 ) ;
if ( NULL == V_275 )
return - V_100 ;
if ( 0 == ( V_275 -> V_162 & V_365 ) )
return - V_100 ;
V_265 = - V_100 ;
if ( V_414 -> V_162 & V_419 ) {
T_2 V_144 = V_414 -> V_275 . V_144 ;
T_2 V_43 = V_414 -> V_275 . V_43 ;
V_265 = F_95 ( V_21 , & V_144 , & V_43 ,
V_359 ,
~ 3 ,
2 ,
0 ,
0 ) ;
if ( 0 != V_265 )
return V_265 ;
}
V_10 -> V_294 . V_369 = V_414 -> V_369 ;
V_10 -> V_294 . V_275 . V_144 = V_414 -> V_275 . V_144 ;
V_10 -> V_294 . V_275 . V_43 = V_414 -> V_275 . V_43 ;
if ( 0 != V_414 -> V_275 . V_382 )
V_10 -> V_294 . V_275 . V_382 = V_414 -> V_275 . V_382 ;
else
V_10 -> V_294 . V_275 . V_382 = V_10 -> V_294 . V_275 . V_144 * V_275 -> V_290 / 8 ;
V_265 = 0 ;
V_21 -> V_360 = V_275 ;
V_10 -> V_373 . V_360 = V_275 ;
if ( V_414 -> V_162 & V_419 ) {
V_21 -> V_370 . V_355 . V_292 = 0 ;
V_21 -> V_370 . V_355 . V_29 = 0 ;
V_21 -> V_370 . V_355 . V_144 = V_414 -> V_275 . V_144 ;
V_21 -> V_370 . V_355 . V_43 = V_414 -> V_275 . V_43 ;
V_10 -> V_373 . V_370 . V_355 . V_144 = V_414 -> V_275 . V_144 ;
V_10 -> V_373 . V_370 . V_355 . V_43 = V_414 -> V_275 . V_43 ;
F_68 ( V_21 -> V_370 . V_363 ) ;
V_21 -> V_370 . V_363 = NULL ;
V_21 -> V_370 . V_371 = 0 ;
if ( F_14 ( V_21 , V_272 ) ) {
struct V_262 * V_263 ;
V_263 = F_105 ( sizeof( * V_263 ) ) ;
V_263 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_106 ( V_10 , & V_21 -> V_370 , V_21 -> V_360 , V_263 ) ;
V_265 = F_66 ( V_10 , V_21 , V_263 ) ;
}
}
return V_265 ;
}
static int F_127 ( struct V_214 * V_214 , void * V_215 ,
struct V_420 * V_421 )
{
struct V_20 * V_21 = V_215 ;
return F_128 ( F_107 ( V_21 ) , V_421 ) ;
}
static int F_129 ( struct V_214 * V_214 , void * V_215 ,
struct V_422 * V_338 )
{
struct V_20 * V_21 = V_215 ;
return F_130 ( F_107 ( V_21 ) , V_338 ) ;
}
static int F_131 ( struct V_214 * V_214 , void * V_215 , struct V_422 * V_338 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_377 = F_108 ( V_21 ) ;
if ( ! F_13 ( V_10 , V_21 , V_377 ) )
return - V_352 ;
return F_132 ( F_107 ( V_21 ) , V_338 ) ;
}
static int F_133 ( struct V_214 * V_214 , void * V_215 , struct V_422 * V_338 )
{
struct V_20 * V_21 = V_215 ;
return F_134 ( F_107 ( V_21 ) , V_338 ,
V_214 -> V_423 & V_424 ) ;
}
static int F_135 ( struct V_214 * V_214 , void * V_215 ,
enum V_379 type )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_377 = F_108 ( V_21 ) ;
if ( ! F_13 ( V_10 , V_21 , V_377 ) )
return - V_352 ;
return F_136 ( F_107 ( V_21 ) ) ;
}
static int F_137 ( struct V_214 * V_214 , void * V_215 ,
enum V_379 type )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_265 ;
int V_377 = F_108 ( V_21 ) ;
V_265 = F_138 ( F_107 ( V_21 ) ) ;
if ( V_265 < 0 )
return V_265 ;
F_20 ( V_10 , V_21 , V_377 ) ;
return 0 ;
}
static int F_139 ( struct V_214 * V_214 , void * V_215 ,
struct V_16 * V_11 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_16 * V_110 ;
if ( ( V_11 -> V_17 < V_425 ||
V_11 -> V_17 >= V_426 ) &&
( V_11 -> V_17 < V_427 ||
V_11 -> V_17 >= V_428 ) )
return - V_100 ;
if ( ! V_10 -> V_245 && ( V_11 -> V_17 == V_220 ) )
* V_11 = V_429 ;
else {
V_110 = F_11 ( V_11 -> V_17 ) ;
* V_11 = ( NULL != V_110 ) ? * V_110 : V_429 ;
}
return 0 ;
}
static int F_140 ( struct V_214 * V_214 , void * V_242 ,
struct V_430 * V_431 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
F_141 ( V_40 [ V_10 -> V_39 ] . V_160 ,
& V_431 -> V_431 . V_302 . V_432 ) ;
return 0 ;
}
static int F_142 ( struct V_214 * V_214 , void * V_215 ,
struct V_320 * V_321 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_10 -> V_168 == V_169 )
return - V_100 ;
if ( 0 != V_321 -> V_307 )
return - V_100 ;
V_321 -> V_433 = V_434 ;
F_43 ( V_10 , V_312 , V_435 , V_321 ) ;
strcpy ( V_321 -> V_310 , L_17 ) ;
V_321 -> V_415 = V_436 ;
V_321 -> type = V_326 ;
if ( F_18 ( V_65 ) & V_112 )
V_321 -> signal = 0xffff ;
if ( V_10 -> V_323 )
V_10 -> V_323 ( V_10 , V_321 , 0 ) ;
return 0 ;
}
static int F_143 ( struct V_214 * V_214 , void * V_242 , enum V_437 * V_421 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_421 = F_144 ( & V_10 -> V_244 ) ;
return 0 ;
}
static int F_145 ( struct V_214 * V_214 , void * V_242 ,
enum V_437 V_244 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_280 ;
V_280 = F_146 ( & V_10 -> V_244 , & V_21 -> V_244 , V_244 ) ;
return V_280 ;
}
static int F_147 ( struct V_214 * V_214 , void * V_215 ,
struct V_438 * V_271 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_271 -> type != V_374 &&
V_271 -> type != V_439 )
return - V_100 ;
* V_271 = V_40 [ V_10 -> V_39 ] . V_41 ;
return 0 ;
}
static int F_148 ( struct V_214 * V_214 , void * V_242 , struct V_440 * V_30 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_30 -> type != V_374 &&
V_30 -> type != V_439 )
return - V_100 ;
V_30 -> V_11 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
return 0 ;
}
static int F_149 ( struct V_214 * V_214 , void * V_242 , struct V_440 * V_30 )
{
struct V_20 * V_21 = V_242 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_337 * V_338 ;
int V_265 ;
struct V_141 V_11 ;
T_2 V_441 ;
T_2 V_442 ;
T_2 V_443 ;
T_2 V_444 ;
if ( V_30 -> type != V_374 &&
V_30 -> type != V_439 )
return - V_100 ;
V_265 = F_63 ( & V_10 -> V_244 , V_21 -> V_244 ) ;
if ( 0 != V_265 ) {
return V_265 ;
}
V_265 = - V_352 ;
if ( F_15 ( V_21 -> V_10 , V_28 ) ) {
return V_265 ;
}
V_338 = & V_40 [ V_10 -> V_39 ] . V_41 . V_42 ;
V_441 = V_338 -> V_292 ;
V_443 = V_441 + V_338 -> V_144 ;
V_444 = V_338 -> V_29 + V_338 -> V_43 ;
V_442 = F_49 ( V_338 -> V_29 , V_10 -> V_33 ) ;
if ( V_442 + 32 >= V_444 ) {
return V_265 ;
}
V_11 . V_32 . V_292 = F_96 ( V_30 -> V_11 . V_292 , V_441 , V_443 - 48 ) ;
V_11 . V_32 . V_292 = F_94 ( V_11 . V_32 . V_292 , ( T_2 ) V_342 ) ;
V_11 . V_32 . V_144 = F_96 ( V_30 -> V_11 . V_144 ,
48 , V_443 - V_11 . V_32 . V_292 ) ;
V_11 . V_32 . V_29 = F_96 ( V_30 -> V_11 . V_29 , V_442 , V_444 - 32 ) ;
V_11 . V_32 . V_29 = ( V_11 . V_32 . V_29 + 1 ) & ~ 1 ;
V_11 . V_32 . V_43 = F_96 ( V_30 -> V_11 . V_43 ,
32 , V_444 - V_11 . V_32 . V_29 ) ;
V_11 . V_32 . V_43 = ( V_11 . V_32 . V_43 + 1 ) & ~ 1 ;
F_48 ( & V_11 ) ;
V_10 -> V_30 [ 1 ] = V_11 ;
V_21 -> V_31 = 1 ;
if ( V_21 -> V_144 < V_11 . V_142 ) {
V_21 -> V_144 = V_11 . V_142 ;
V_10 -> V_373 . V_144 = V_11 . V_142 ;
} else if ( V_21 -> V_144 > V_11 . V_145 ) {
V_21 -> V_144 = V_11 . V_145 ;
V_10 -> V_373 . V_144 = V_11 . V_145 ;
}
if ( V_21 -> V_43 < V_11 . V_143 ) {
V_21 -> V_43 = V_11 . V_143 ;
V_10 -> V_373 . V_43 = V_11 . V_143 ;
} else if ( V_21 -> V_43 > V_11 . V_146 ) {
V_21 -> V_43 = V_11 . V_146 ;
V_10 -> V_373 . V_43 = V_11 . V_146 ;
}
return 0 ;
}
static int F_150 ( struct V_214 * V_214 , void * V_215 , struct V_445 * V_446 )
{
if ( F_82 ( V_446 -> V_307 ) )
return - V_100 ;
strcpy ( V_446 -> V_310 , L_26 ) ;
return 0 ;
}
static int F_151 ( struct V_214 * V_214 , void * V_215 , struct V_445 * V_446 )
{
if ( F_82 ( V_446 -> V_307 ) )
return - V_100 ;
return 0 ;
}
static T_1 F_152 ( struct V_214 * V_214 , char T_7 * V_251 ,
T_8 V_296 , T_9 * V_447 )
{
struct V_20 * V_21 = V_214 -> V_448 ;
int V_265 = 0 ;
if ( V_21 -> V_10 -> V_213 )
F_59 ( V_21 -> V_10 ) ;
F_24 ( L_27 ,
V_21 -> V_10 -> V_11 . V_61 , ( int ) V_296 , V_449 [ V_21 -> type ] ) ;
switch ( V_21 -> type ) {
case V_374 :
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_25 ) ) {
return - V_352 ;
}
V_265 = F_153 ( & V_21 -> V_271 , V_251 , V_296 , V_447 ,
V_214 -> V_423 & V_424 ) ;
F_20 ( V_21 -> V_10 , V_21 , V_25 ) ;
break;
case V_375 :
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_378 ) )
return - V_352 ;
V_265 = F_154 ( & V_21 -> V_376 , V_251 , V_296 , V_447 , 1 ,
V_214 -> V_423 & V_424 ) ;
break;
default:
F_98 () ;
}
return V_265 ;
}
static unsigned int F_155 ( struct V_214 * V_214 , T_10 * V_450 )
{
struct V_20 * V_21 = V_214 -> V_448 ;
struct V_262 * V_5 ;
enum V_276 V_277 ;
unsigned int V_280 = V_451 ;
if ( V_375 == V_21 -> type ) {
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_378 ) )
return V_451 ;
return F_156 ( V_214 , & V_21 -> V_376 , V_450 ) ;
}
if ( F_14 ( V_21 , V_26 ) ) {
if ( F_157 ( & V_21 -> V_271 . V_452 ) )
goto V_243;
V_5 = F_158 ( V_21 -> V_271 . V_452 . V_453 , struct V_262 , V_266 . V_452 ) ;
} else {
if ( NULL == V_21 -> V_271 . V_454 ) {
if ( F_15 ( V_21 -> V_10 , V_26 ) )
goto V_243;
V_21 -> V_271 . V_454 = F_105 ( V_21 -> V_271 . V_455 ) ;
if ( NULL == V_21 -> V_271 . V_454 )
goto V_243;
V_21 -> V_271 . V_454 -> V_456 = V_457 ;
V_277 = F_159 ( & V_21 -> V_271 ) ;
if ( 0 != V_21 -> V_271 . V_458 -> V_459 ( & V_21 -> V_271 , V_21 -> V_271 . V_454 , V_277 ) ) {
F_68 ( V_21 -> V_271 . V_454 ) ;
V_21 -> V_271 . V_454 = NULL ;
goto V_243;
}
V_21 -> V_271 . V_458 -> V_460 ( & V_21 -> V_271 , V_21 -> V_271 . V_454 ) ;
V_21 -> V_271 . V_461 = 0 ;
}
V_5 = (struct V_262 * ) V_21 -> V_271 . V_454 ;
}
F_160 ( V_214 , & V_5 -> V_266 . V_462 , V_450 ) ;
if ( V_5 -> V_266 . V_267 == V_268 ||
V_5 -> V_266 . V_267 == V_463 )
V_280 = V_464 | V_465 ;
else
V_280 = 0 ;
V_243:
return V_280 ;
}
static int F_161 ( struct V_214 * V_214 )
{
struct V_6 * V_466 = F_162 ( V_214 ) ;
struct V_9 * V_10 = F_163 ( V_214 ) ;
struct V_20 * V_21 ;
enum V_379 type = 0 ;
F_24 ( V_105 L_28 , F_164 ( V_466 ) ) ;
if ( V_466 -> V_467 == V_468 ) {
type = V_374 ;
} else if ( V_466 -> V_467 == V_469 ) {
type = V_375 ;
} else {
F_165 ( 1 ) ;
return - V_470 ;
}
F_24 ( V_105 L_29 ,
V_10 -> V_11 . V_61 , V_449 [ type ] ) ;
V_21 = F_100 ( sizeof( * V_21 ) , V_366 ) ;
if ( F_82 ( ! V_21 ) )
return - V_367 ;
V_214 -> V_448 = V_21 ;
* V_21 = V_10 -> V_373 ;
V_21 -> type = type ;
V_21 -> V_370 . V_372 = 0 ;
F_166 ( & V_10 -> V_244 , & V_21 -> V_244 ) ;
F_167 ( & V_21 -> V_271 , & V_471 ,
& V_10 -> V_11 . V_399 -> V_8 , & V_10 -> V_164 ,
V_374 ,
V_359 ,
sizeof( struct V_262 ) ,
V_21 , & V_10 -> V_472 ) ;
F_167 ( & V_21 -> V_376 , & V_473 ,
& V_10 -> V_11 . V_399 -> V_8 , & V_10 -> V_164 ,
V_375 ,
V_388 ,
sizeof( struct V_262 ) ,
V_21 , & V_10 -> V_472 ) ;
F_51 ( V_10 , V_10 -> V_39 ) ;
F_54 ( V_10 , V_10 -> V_72 , V_10 -> V_39 ) ;
V_10 -> V_255 ++ ;
V_21 -> V_31 = ! V_474 ;
F_168 ( & V_21 -> V_37 , V_10 -> V_39 ) ;
F_64 ( V_10 ) ;
return 0 ;
}
static int F_169 ( struct V_214 * V_214 )
{
struct V_20 * V_21 = V_214 -> V_448 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( F_14 ( V_21 , V_272 ) )
F_66 ( V_10 , V_21 , NULL ) ;
if ( F_14 ( V_21 , V_26 ) ) {
F_138 ( & V_21 -> V_271 ) ;
F_20 ( V_10 , V_21 , V_26 ) ;
}
if ( V_21 -> V_271 . V_454 ) {
F_76 ( & V_21 -> V_271 , V_21 -> V_271 . V_454 ) ;
F_68 ( V_21 -> V_271 . V_454 ) ;
}
if ( F_14 ( V_21 , V_25 ) ) {
F_20 ( V_10 , V_21 , V_25 ) ;
}
if ( F_14 ( V_21 , V_378 ) ) {
F_170 ( & V_21 -> V_376 ) ;
F_20 ( V_10 , V_21 , V_378 ) ;
}
F_171 ( & V_21 -> V_271 ) ;
F_171 ( & V_21 -> V_376 ) ;
F_172 ( & V_10 -> V_244 , V_21 -> V_244 ) ;
V_214 -> V_448 = NULL ;
F_68 ( V_21 ) ;
V_10 -> V_255 -- ;
F_64 ( V_10 ) ;
if ( ! V_10 -> V_255 )
F_46 ( V_10 , 1 ) ;
return 0 ;
}
static int
F_173 ( struct V_214 * V_214 , struct V_475 * V_476 )
{
struct V_20 * V_21 = V_214 -> V_448 ;
F_24 ( L_30 ,
V_21 -> V_10 -> V_11 . V_61 , V_449 [ V_21 -> type ] ,
V_476 -> V_477 , V_476 -> V_478 - V_476 -> V_477 ) ;
return F_174 ( F_107 ( V_21 ) , V_476 ) ;
}
static int F_175 ( struct V_214 * V_214 )
{
struct V_6 * V_466 = F_162 ( V_214 ) ;
struct V_9 * V_10 = F_163 ( V_214 ) ;
struct V_20 * V_21 ;
F_24 ( L_28 , F_164 ( V_466 ) ) ;
F_24 ( L_31 , V_10 -> V_11 . V_61 ) ;
V_21 = F_100 ( sizeof( * V_21 ) , V_366 ) ;
if ( F_82 ( ! V_21 ) )
return - V_367 ;
V_214 -> V_448 = V_21 ;
* V_21 = V_10 -> V_373 ;
F_166 ( & V_10 -> V_244 , & V_21 -> V_244 ) ;
V_10 -> V_115 ++ ;
F_43 ( V_10 , V_312 , V_479 ) ;
F_47 ( V_10 , V_127 ) ;
return 0 ;
}
static int F_176 ( struct V_214 * V_214 )
{
struct V_20 * V_21 = V_214 -> V_448 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_480 V_481 ;
F_172 ( & V_10 -> V_244 , V_21 -> V_244 ) ;
V_214 -> V_448 = NULL ;
F_68 ( V_21 ) ;
V_10 -> V_115 -- ;
F_43 ( V_10 , V_123 , V_482 , V_483 , & V_481 ) ;
return 0 ;
}
static int F_177 ( struct V_214 * V_214 , void * V_215 ,
struct V_393 * V_271 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
strcpy ( V_271 -> V_395 , L_23 ) ;
F_119 ( V_271 -> V_396 , V_10 -> V_484 -> V_310 , sizeof( V_271 -> V_396 ) ) ;
sprintf ( V_271 -> V_398 , L_24 , F_120 ( V_10 -> V_11 . V_399 ) ) ;
V_271 -> V_400 = V_401 ;
V_271 -> V_402 = V_410 ;
return 0 ;
}
static int F_178 ( struct V_214 * V_214 , void * V_215 , struct V_320 * V_321 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_10 -> V_168 == V_169 )
return - V_100 ;
if ( 0 != V_321 -> V_307 )
return - V_100 ;
strcpy ( V_321 -> V_310 , L_32 ) ;
V_321 -> type = V_325 ;
F_43 ( V_10 , V_312 , V_435 , V_321 ) ;
if ( V_10 -> V_323 )
V_10 -> V_323 ( V_10 , V_321 , 0 ) ;
return 0 ;
}
static int F_179 ( struct V_214 * V_214 , void * V_215 ,
struct V_306 * V_18 )
{
if ( V_18 -> V_307 != 0 )
return - V_100 ;
strcpy ( V_18 -> V_310 , L_32 ) ;
V_18 -> type = V_311 ;
return 0 ;
}
static int F_180 ( struct V_214 * V_214 , void * V_215 ,
struct V_445 * V_446 )
{
if ( F_82 ( V_446 -> V_307 ) )
return - V_100 ;
strcpy ( V_446 -> V_310 , L_32 ) ;
return 0 ;
}
static int F_181 ( struct V_214 * V_214 , void * V_215 ,
struct V_320 * V_321 )
{
struct V_20 * V_21 = V_215 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( 0 != V_321 -> V_307 )
return - V_100 ;
F_43 ( V_10 , V_312 , V_322 , V_321 ) ;
return 0 ;
}
static int F_182 ( struct V_214 * V_214 , void * V_215 ,
struct V_445 * V_446 )
{
if ( F_82 ( V_446 -> V_307 ) )
return - V_100 ;
return 0 ;
}
static int F_183 ( struct V_214 * V_485 , void * V_215 , unsigned int V_18 )
{
if ( F_82 ( V_18 ) )
return - V_100 ;
return 0 ;
}
static int F_184 ( struct V_214 * V_214 , void * V_21 , T_5 * V_147 )
{
return 0 ;
}
static int F_185 ( struct V_214 * V_214 , void * V_215 ,
struct V_16 * V_11 )
{
const struct V_16 * V_110 ;
if ( V_11 -> V_17 < V_425 ||
V_11 -> V_17 >= V_426 )
return - V_100 ;
if ( V_11 -> V_17 == V_122 ) {
V_110 = F_11 ( V_11 -> V_17 ) ;
* V_11 = * V_110 ;
} else
* V_11 = V_429 ;
return 0 ;
}
static int F_186 ( struct V_214 * V_485 , void * V_215 , unsigned int * V_18 )
{
* V_18 = 0 ;
return 0 ;
}
static T_1 F_187 ( struct V_214 * V_214 , char T_7 * V_251 ,
T_8 V_296 , T_9 * V_447 )
{
struct V_20 * V_21 = V_214 -> V_448 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_480 V_481 ;
V_481 . V_486 = V_296 / 3 ;
V_481 . V_487 = V_251 ;
V_481 . V_488 = V_214 ;
V_481 . V_489 = - V_470 ;
F_43 ( V_10 , V_123 , V_482 , V_490 , & V_481 ) ;
return V_481 . V_489 ;
}
static unsigned int F_188 ( struct V_214 * V_214 , T_10 * V_450 )
{
struct V_20 * V_21 = V_214 -> V_448 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_480 V_481 ;
V_481 . V_488 = V_214 ;
V_481 . V_491 = V_450 ;
V_481 . V_489 = - V_470 ;
F_43 ( V_10 , V_123 , V_482 , V_492 , & V_481 ) ;
return V_481 . V_489 ;
}
static int F_189 ( T_4 V_493 )
{
static char * V_494 [ 16 ] = {
[ V_495 >> 28 ] = L_33 ,
[ V_496 >> 28 ] = L_34 ,
[ V_497 >> 28 ] = L_35 ,
[ V_498 >> 28 ] = L_36 ,
[ V_499 >> 28 ] = L_37 ,
[ V_500 >> 28 ] = L_38 ,
[ V_501 >> 28 ] = L_39 ,
[ V_502 >> 28 ] = L_40 ,
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
L_41 , L_42 , L_43 , L_44 ,
L_45 , L_46 , L_47 , L_48 ,
L_49 , L_50 , L_51 , L_52 ,
L_53 , L_54 , L_55 , L_56 ,
} ;
int V_18 ;
F_21 ( L_57 , V_493 ,
V_494 [ V_493 >> 28 ] ? V_494 [ V_493 >> 28 ] : L_58 ) ;
for ( V_18 = F_12 ( V_48 ) - 1 ; V_18 >= 0 ; V_18 -- )
if ( V_493 & ( 1 << ( V_18 + 12 ) ) )
F_21 ( L_59 , V_48 [ V_18 ] ) ;
F_21 ( L_60 , V_493 & 0xfff ) ;
return V_503 [ V_493 >> 28 ] ? V_503 [ V_493 >> 28 ] : 1 ;
}
static void F_190 ( struct V_9 * V_10 ,
struct V_504 * V_493 )
{
unsigned int V_18 , V_505 , V_364 ;
F_21 ( L_61 ,
V_10 -> V_11 . V_506 . V_310 , V_493 -> V_507 , ( unsigned long ) V_493 -> V_508 ) ;
for ( V_18 = 0 ; V_18 < ( V_493 -> V_286 >> 2 ) ; V_18 += V_364 ) {
F_21 ( L_62 , V_10 -> V_11 . V_506 . V_310 ,
( unsigned long ) ( V_493 -> V_508 + ( V_18 << 2 ) ) ) ;
V_364 = F_189 ( F_191 ( V_493 -> V_507 [ V_18 ] ) ) ;
for ( V_505 = 1 ; V_505 < V_364 ; V_505 ++ )
F_21 ( L_63 ,
V_10 -> V_11 . V_506 . V_310 , ( unsigned long ) ( V_493 -> V_508 + ( ( V_18 + V_505 ) << 2 ) ) ,
V_493 -> V_507 [ V_18 + V_505 ] , V_505 ) ;
if ( 0 == V_493 -> V_507 [ V_18 ] )
break;
}
}
static void F_192 ( struct V_9 * V_10 )
{
F_21 ( L_64 ,
( unsigned long long ) V_10 -> main. V_508 ) ;
F_21 ( L_65 ,
V_10 -> V_509 ? ( unsigned long long ) V_10 -> V_509 -> V_29 . V_508 : 0 ,
V_10 -> V_509 ? ( unsigned long long ) V_10 -> V_509 -> V_510 . V_508 : 0 ) ;
F_21 ( L_66 ,
V_10 -> V_165 . V_29 ? ( unsigned long long ) V_10 -> V_165 . V_29 -> V_29 . V_508 : 0 ,
V_10 -> V_165 . V_510 ? ( unsigned long long ) V_10 -> V_165 . V_510 -> V_510 . V_508 : 0 ) ;
F_21 ( L_67 ,
V_10 -> V_269 ? ( unsigned long long ) V_10 -> V_269 -> V_29 . V_508 : 0 ,
V_10 -> V_269 ? ( unsigned long long ) V_10 -> V_269 -> V_510 . V_508 : 0 ) ;
F_190 ( V_10 , & V_10 -> main ) ;
}
static void F_193 ( T_4 V_511 , T_4 V_512 )
{
unsigned int V_18 ;
F_21 ( L_68 ) ;
for ( V_18 = 0 ; V_18 < F_12 ( V_513 ) ; V_18 ++ ) {
if ( V_511 & ( 1 << V_18 ) )
F_21 ( L_59 , V_513 [ V_18 ] ) ;
if ( V_512 & ( 1 << V_18 ) )
F_21 ( L_69 ) ;
}
}
static void F_194 ( struct V_9 * V_10 , T_4 V_280 )
{
F_21 ( L_70 ,
V_10 -> V_11 . V_61 ,
( unsigned long ) V_10 -> main. V_508 ,
( unsigned long ) F_191 ( V_10 -> main. V_507 [ V_514 + 1 ] ) ,
( unsigned long ) F_191 ( V_10 -> main. V_507 [ V_515 + 1 ] ) ,
( unsigned long ) V_280 ) ;
if ( 0 == ( F_18 ( V_65 ) & V_112 ) ) {
F_21 ( L_71
L_72 ,
V_10 -> V_11 . V_61 ) ;
return;
}
F_21 ( L_73 ,
V_10 -> V_11 . V_61 ) ;
F_21 ( L_74 ,
V_10 -> V_11 . V_61 ) ;
F_195 () ;
}
static int
F_196 ( struct V_9 * V_10 , struct V_516 * V_517 )
{
struct V_262 * V_518 ;
memset ( V_517 , 0 , sizeof( * V_517 ) ) ;
if ( ! F_157 ( & V_10 -> V_302 ) ) {
V_517 -> V_166 = 1 ;
V_518 = F_158 ( V_10 -> V_302 . V_453 , struct V_262 , V_266 . V_301 ) ;
if ( F_197 ( V_518 -> V_266 . V_277 ) )
V_517 -> V_29 = V_518 ;
if ( F_198 ( V_518 -> V_266 . V_277 ) )
V_517 -> V_510 = V_518 ;
if ( ! F_93 ( V_518 -> V_266 . V_277 ) &&
( V_518 -> V_266 . V_301 . V_453 != & V_10 -> V_302 ) ) {
V_518 = F_158 ( V_518 -> V_266 . V_301 . V_453 , struct V_262 , V_266 . V_301 ) ;
if ( ! F_93 ( V_518 -> V_266 . V_277 ) ) {
if ( NULL == V_517 -> V_510 &&
V_288 == V_518 -> V_266 . V_277 ) {
V_517 -> V_510 = V_518 ;
}
if ( NULL != V_517 -> V_29 && NULL != V_517 -> V_510 )
V_517 -> V_519 = 2 ;
}
}
}
if ( NULL != V_10 -> V_269 ) {
if ( F_93 ( V_10 -> V_269 -> V_266 . V_277 ) ) {
if ( NULL == V_517 -> V_29 && NULL == V_517 -> V_510 ) {
V_517 -> V_29 = V_10 -> V_269 ;
V_517 -> V_510 = V_10 -> V_269 ;
}
} else {
if ( V_287 == V_10 -> V_269 -> V_266 . V_277 &&
NULL == V_517 -> V_29 ) {
V_517 -> V_29 = V_10 -> V_269 ;
}
if ( V_288 == V_10 -> V_269 -> V_266 . V_277 &&
NULL == V_517 -> V_510 ) {
V_517 -> V_510 = V_10 -> V_269 ;
}
}
}
F_24 ( L_75 ,
V_10 -> V_11 . V_61 , V_517 -> V_29 , V_517 -> V_510 ,
V_10 -> V_269 , V_517 -> V_166 , V_517 -> V_519 ) ;
return 0 ;
}
static void
F_199 ( struct V_9 * V_10 , struct V_516 * V_520 ,
struct V_516 * V_165 , unsigned int V_267 )
{
struct V_521 V_522 ;
F_200 ( & V_522 ) ;
if ( V_520 -> V_29 == V_520 -> V_510 ) {
if ( NULL != V_520 -> V_29 && V_165 -> V_29 != V_520 -> V_29 ) {
if ( V_523 > 1 )
F_21 ( L_76 , V_10 -> V_11 . V_61 , V_520 -> V_29 ) ;
V_520 -> V_29 -> V_266 . V_522 = V_522 ;
V_520 -> V_29 -> V_266 . V_257 = V_10 -> V_257 ;
V_520 -> V_29 -> V_266 . V_267 = V_267 ;
F_201 ( & V_520 -> V_29 -> V_266 . V_462 ) ;
}
} else {
if ( NULL != V_520 -> V_29 && V_165 -> V_29 != V_520 -> V_29 ) {
if ( V_523 > 1 )
F_21 ( L_77 , V_10 -> V_11 . V_61 , V_520 -> V_29 ) ;
V_520 -> V_29 -> V_266 . V_522 = V_522 ;
V_520 -> V_29 -> V_266 . V_257 = V_10 -> V_257 ;
V_520 -> V_29 -> V_266 . V_267 = V_267 ;
F_201 ( & V_520 -> V_29 -> V_266 . V_462 ) ;
}
if ( NULL != V_520 -> V_510 && V_165 -> V_510 != V_520 -> V_510 ) {
if ( V_523 > 1 )
F_21 ( L_78 , V_10 -> V_11 . V_61 , V_520 -> V_510 ) ;
V_520 -> V_510 -> V_266 . V_522 = V_522 ;
V_520 -> V_510 -> V_266 . V_257 = V_10 -> V_257 ;
V_520 -> V_510 -> V_266 . V_267 = V_267 ;
F_201 ( & V_520 -> V_510 -> V_266 . V_462 ) ;
}
}
}
static void
F_202 ( struct V_9 * V_10 , struct V_262 * V_520 ,
unsigned int V_267 )
{
struct V_521 V_522 ;
if ( NULL == V_520 )
return;
F_200 ( & V_522 ) ;
V_520 -> V_266 . V_522 = V_522 ;
V_520 -> V_266 . V_257 = V_10 -> V_257 ;
V_520 -> V_266 . V_267 = V_267 ;
F_201 ( & V_520 -> V_266 . V_462 ) ;
}
static void F_203 ( unsigned long V_251 )
{
struct V_9 * V_10 = (struct V_9 * ) V_251 ;
struct V_516 V_264 , V_263 ;
struct V_262 * V_524 ;
struct V_262 * V_518 ;
unsigned long V_162 ;
if ( V_212 ) {
F_21 ( V_63 L_79 ,
V_10 -> V_11 . V_61 , V_10 -> V_525 , V_10 -> V_526 , V_10 -> V_527 ,
F_18 ( V_528 ) ) ;
F_193 ( F_18 ( V_170 ) , 0 ) ;
F_21 ( L_80 ) ;
}
F_55 ( & V_10 -> V_164 , V_162 ) ;
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_264 = V_10 -> V_165 ;
V_524 = V_10 -> V_509 ;
V_10 -> V_165 = V_263 ;
V_10 -> V_509 = NULL ;
V_10 -> V_270 = 0 ;
F_204 ( V_10 , & V_263 ) ;
F_205 ( V_10 , NULL ) ;
F_60 ( V_10 , 0 ) ;
F_199 ( V_10 , & V_264 , & V_263 , V_463 ) ;
F_202 ( V_10 , V_524 , V_463 ) ;
while ( ! F_157 ( & V_10 -> V_302 ) ) {
V_518 = F_158 ( V_10 -> V_302 . V_453 , struct V_262 , V_266 . V_301 ) ;
F_206 ( & V_518 -> V_266 . V_301 ) ;
V_518 -> V_266 . V_267 = V_463 ;
F_201 ( & V_518 -> V_266 . V_462 ) ;
}
while ( ! F_157 ( & V_10 -> V_529 ) ) {
V_518 = F_158 ( V_10 -> V_529 . V_453 , struct V_262 , V_266 . V_301 ) ;
F_206 ( & V_518 -> V_266 . V_301 ) ;
V_518 -> V_266 . V_267 = V_463 ;
F_201 ( & V_518 -> V_266 . V_462 ) ;
}
V_10 -> V_213 ++ ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
}
static void
F_207 ( struct V_9 * V_10 )
{
struct V_262 * V_520 = V_10 -> V_165 . V_29 ;
if ( NULL == V_520 )
return;
F_208 ( & V_10 -> V_164 ) ;
V_10 -> V_165 . V_519 = 0 ;
V_10 -> V_165 . V_29 = NULL ;
F_209 ( V_10 , V_515 , NULL , 0 ) ;
F_200 ( & V_520 -> V_266 . V_522 ) ;
V_520 -> V_266 . V_257 = V_10 -> V_257 ;
V_520 -> V_266 . V_267 = V_268 ;
F_201 ( & V_520 -> V_266 . V_462 ) ;
F_210 ( & V_10 -> V_164 ) ;
}
static inline int F_211 ( struct V_504 * V_493 , T_4 V_280 )
{
if ( V_280 < V_493 -> V_508 )
return 0 ;
if ( V_280 > V_493 -> V_508 + V_493 -> V_286 )
return 0 ;
return 1 ;
}
static void
F_212 ( struct V_9 * V_10 )
{
struct V_516 V_263 ;
struct V_516 V_264 ;
T_11 V_280 ;
F_208 ( & V_10 -> V_164 ) ;
F_196 ( V_10 , & V_263 ) ;
V_280 = F_18 ( V_528 ) ;
if ( ( V_10 -> V_165 . V_29 && F_211 ( & V_10 -> V_165 . V_29 -> V_29 , V_280 ) ) ||
( V_10 -> V_165 . V_510 && F_211 ( & V_10 -> V_165 . V_510 -> V_510 , V_280 ) ) ) {
V_10 -> V_525 ++ ;
if ( V_530 )
F_194 ( V_10 , V_280 ) ;
F_210 ( & V_10 -> V_164 ) ;
return;
}
V_264 = V_10 -> V_165 ;
V_10 -> V_165 = V_263 ;
V_10 -> V_270 &= ~ 1 ;
F_204 ( V_10 , & V_263 ) ;
F_60 ( V_10 , 0 ) ;
if ( V_12 != V_10 -> V_167 ) {
F_33 ( V_10 , V_10 -> V_167 ) ;
V_10 -> V_167 = V_12 ;
}
F_199 ( V_10 , & V_264 , & V_263 , V_268 ) ;
F_210 ( & V_10 -> V_164 ) ;
}
static void
F_213 ( struct V_9 * V_10 )
{
struct V_262 * V_263 = NULL ;
struct V_262 * V_264 ;
T_4 V_280 ;
F_208 ( & V_10 -> V_164 ) ;
if ( ! F_157 ( & V_10 -> V_529 ) )
V_263 = F_158 ( V_10 -> V_529 . V_453 , struct V_262 , V_266 . V_301 ) ;
V_264 = V_10 -> V_509 ;
V_280 = F_18 ( V_528 ) ;
if ( NULL != V_264 && ( F_211 ( & V_264 -> V_29 , V_280 ) ||
F_211 ( & V_264 -> V_510 , V_280 ) ) ) {
V_10 -> V_525 ++ ;
if ( V_530 )
F_194 ( V_10 , V_280 ) ;
F_210 ( & V_10 -> V_164 ) ;
return;
}
V_10 -> V_509 = V_263 ;
V_10 -> V_270 &= ~ 4 ;
F_205 ( V_10 , V_263 ) ;
F_60 ( V_10 , 0 ) ;
F_202 ( V_10 , V_264 , V_268 ) ;
F_210 ( & V_10 -> V_164 ) ;
}
static T_12 F_214 ( int V_531 , void * V_532 )
{
T_4 V_533 , V_534 ;
T_4 V_535 ;
int V_296 ;
struct V_9 * V_10 ;
int V_536 = 0 ;
V_10 = (struct V_9 * ) V_532 ;
V_296 = 0 ;
while ( 1 ) {
V_533 = F_18 ( V_170 ) ;
V_534 = V_533 & F_18 ( V_173 ) ;
if ( ! V_534 )
break;
V_536 = 1 ;
F_19 ( V_533 , V_170 ) ;
V_535 = F_18 ( V_65 ) ;
if ( V_523 ) {
F_21 ( V_105 L_81
L_82 ,
V_10 -> V_11 . V_61 , V_296 , V_10 -> V_257 ,
V_533 >> 28 , F_18 ( V_528 ) ) ;
F_193 ( V_533 , V_534 ) ;
if ( V_533 & V_183 )
F_21 ( L_83 , ( V_535 & V_112 )
? L_84 : L_85 ) ;
if ( V_533 & V_537 )
F_21 ( L_86 , ( V_535 & V_314 )
? L_84 : L_85 ) ;
if ( V_533 & V_182 )
F_21 ( L_87 , ( V_535 & V_303 )
? L_88 : L_89 ) ;
F_21 ( L_80 ) ;
}
if ( V_534 & V_256 )
V_10 -> V_257 ++ ;
if ( ( V_534 & V_176 ) && V_10 -> V_538 ) {
F_215 ( V_10 ) ;
}
if ( V_534 & V_172 ) {
V_10 -> V_539 = V_533 ;
F_201 ( & V_10 -> V_540 ) ;
}
if ( ( V_534 & V_180 ) && ( V_533 & ( 4 << 28 ) ) )
F_213 ( V_10 ) ;
if ( ( V_534 & V_180 ) && ( V_533 & ( 2 << 28 ) ) )
F_207 ( V_10 ) ;
if ( ( V_534 & V_180 ) && ( V_533 & ( 1 << 28 ) ) )
F_212 ( V_10 ) ;
if ( ( V_534 & V_183 ) && V_10 -> V_114 )
F_46 ( V_10 , V_10 -> V_107 ) ;
if ( V_534 & ( V_177 | V_181 ) ) {
F_21 ( V_63 L_90 , V_10 -> V_11 . V_61 ,
( V_534 & V_177 ) ? L_91 : L_92 ,
( V_534 & V_181 ) ? L_93 : L_92 ,
F_18 ( V_528 ) ) ;
F_193 ( V_533 , V_534 ) ;
F_21 ( L_80 ) ;
if ( V_541 )
F_192 ( V_10 ) ;
}
if ( V_178 && V_534 & V_179 ) {
F_21 ( V_63 L_94 ,
V_10 -> V_11 . V_61 , F_18 ( V_528 ) ) ;
if ( V_541 )
F_192 ( V_10 ) ;
}
V_296 ++ ;
if ( V_296 > 4 ) {
if ( V_296 > 8 || ! ( V_534 & V_176 ) ) {
F_19 ( 0 , V_173 ) ;
F_21 ( V_392
L_95 , V_10 -> V_11 . V_61 ) ;
} else {
F_21 ( V_392
L_96 , V_10 -> V_11 . V_61 ) ;
F_19 ( F_18 ( V_173 ) & ( - 1 ^ V_176 ) ,
V_173 ) ;
} ;
F_193 ( V_533 , V_534 ) ;
F_21 ( L_97 ) ;
}
}
V_10 -> V_527 ++ ;
if ( V_536 )
V_10 -> V_526 ++ ;
return F_216 ( V_536 ) ;
}
static struct V_6 * F_217 ( struct V_9 * V_10 ,
const struct V_6 * V_542 ,
const char * V_543 )
{
struct V_6 * V_7 ;
V_7 = F_218 () ;
if ( NULL == V_7 )
return NULL ;
* V_7 = * V_542 ;
V_7 -> V_506 = & V_10 -> V_11 . V_506 ;
V_7 -> V_544 = V_545 ;
V_7 -> V_546 = V_541 ;
F_219 ( V_7 , V_10 ) ;
snprintf ( V_7 -> V_310 , sizeof( V_7 -> V_310 ) , L_98 ,
V_10 -> V_17 , ( V_10 -> V_17 == 848 && V_10 -> V_547 == 0x12 ) ? L_99 : L_92 ,
V_543 , V_98 [ V_10 -> V_11 . type ] . V_310 ) ;
return V_7 ;
}
static void F_220 ( struct V_9 * V_10 )
{
if ( V_10 -> V_397 ) {
if ( F_221 ( V_10 -> V_397 ) )
F_222 ( V_10 -> V_397 ) ;
else
V_545 ( V_10 -> V_397 ) ;
V_10 -> V_397 = NULL ;
}
if ( V_10 -> V_548 ) {
if ( F_221 ( V_10 -> V_548 ) )
F_222 ( V_10 -> V_548 ) ;
else
V_545 ( V_10 -> V_548 ) ;
V_10 -> V_548 = NULL ;
}
if ( V_10 -> V_484 ) {
if ( F_221 ( V_10 -> V_484 ) )
F_222 ( V_10 -> V_484 ) ;
else
V_545 ( V_10 -> V_484 ) ;
V_10 -> V_484 = NULL ;
}
}
static int T_13 F_223 ( struct V_9 * V_10 )
{
if ( V_391 > 0 )
F_21 ( L_100 ) ;
V_10 -> V_397 = F_217 ( V_10 , & V_549 , L_101 ) ;
if ( NULL == V_10 -> V_397 )
goto V_243;
if ( F_224 ( V_10 -> V_397 , V_468 ,
V_550 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_243;
F_21 ( V_63 L_102 ,
V_10 -> V_11 . V_61 , F_164 ( V_10 -> V_397 ) ) ;
if ( F_225 ( & V_10 -> V_397 -> V_8 ,
& V_551 ) < 0 ) {
F_21 ( V_392 L_103
L_9 , V_10 -> V_11 . V_61 ) ;
goto V_243;
}
V_10 -> V_548 = F_217 ( V_10 , & V_549 , L_104 ) ;
if ( NULL == V_10 -> V_548 )
goto V_243;
if ( F_224 ( V_10 -> V_548 , V_469 ,
V_552 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_243;
F_21 ( V_63 L_102 ,
V_10 -> V_11 . V_61 , F_164 ( V_10 -> V_548 ) ) ;
if ( ! V_10 -> V_553 )
return 0 ;
V_10 -> V_484 = F_217 ( V_10 , & V_554 , L_105 ) ;
if ( NULL == V_10 -> V_484 )
goto V_243;
if ( F_224 ( V_10 -> V_484 , V_555 ,
V_556 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_243;
F_21 ( V_63 L_102 ,
V_10 -> V_11 . V_61 , F_164 ( V_10 -> V_484 ) ) ;
return 0 ;
V_243:
F_220 ( V_10 ) ;
return - 1 ;
}
static void F_226 ( struct V_557 * V_8 )
{
#if F_227 ( V_558 )
unsigned int V_481 ;
F_228 ( V_8 , V_559 , & V_481 ) ;
V_481 = ( V_481 | V_560 ) ;
F_229 ( V_8 , V_559 , V_481 ) ;
#endif
}
static int T_13 F_230 ( struct V_557 * V_8 ,
const struct V_561 * V_562 )
{
int V_489 ;
unsigned char V_563 ;
struct V_9 * V_10 ;
if ( V_564 == V_565 )
return - V_367 ;
F_21 ( V_63 L_106 , V_564 ) ;
V_566 [ V_564 ] = V_10 = F_231 ( sizeof( * V_10 ) , V_366 ) ;
if ( V_10 == NULL ) {
F_21 ( V_392 L_107 ) ;
return - V_367 ;
}
V_10 -> V_11 . V_61 = V_564 ;
snprintf ( V_10 -> V_11 . V_506 . V_310 , sizeof( V_10 -> V_11 . V_506 . V_310 ) ,
L_108 , V_10 -> V_11 . V_61 ) ;
F_232 ( & V_10 -> V_472 ) ;
F_233 ( & V_10 -> V_164 ) ;
F_233 ( & V_10 -> V_567 ) ;
F_234 ( & V_10 -> V_540 ) ;
F_235 ( & V_10 -> V_11 . V_568 ) ;
F_235 ( & V_10 -> V_302 ) ;
F_235 ( & V_10 -> V_529 ) ;
F_236 ( & V_10 -> V_244 ) ;
F_237 ( & V_10 -> V_569 ) ;
V_10 -> V_569 . V_570 = F_203 ;
V_10 -> V_569 . V_251 = ( unsigned long ) V_10 ;
V_10 -> V_571 = - 1 ;
V_10 -> V_168 = V_12 ;
V_10 -> V_167 = V_12 ;
V_10 -> V_553 = V_572 [ V_10 -> V_11 . V_61 ] ;
V_10 -> V_11 . V_399 = V_8 ;
V_10 -> V_17 = V_8 -> V_1 ;
if ( F_238 ( V_8 ) ) {
F_21 ( V_573 L_109 ,
V_10 -> V_11 . V_61 ) ;
return - V_574 ;
}
if ( F_239 ( V_8 , F_240 ( 32 ) ) ) {
F_21 ( V_573 L_110 ,
V_10 -> V_11 . V_61 ) ;
return - V_574 ;
}
if ( ! F_241 ( F_242 ( V_8 , 0 ) ,
F_243 ( V_8 , 0 ) ,
V_10 -> V_11 . V_506 . V_310 ) ) {
F_21 ( V_573 L_111 ,
V_10 -> V_11 . V_61 ,
( unsigned long long ) F_242 ( V_8 , 0 ) ) ;
return - V_352 ;
}
F_244 ( V_8 ) ;
F_226 ( V_8 ) ;
V_489 = F_245 ( & V_8 -> V_8 , & V_10 -> V_11 . V_506 ) ;
if ( V_489 < 0 ) {
F_21 ( V_573 L_112 , V_10 -> V_11 . V_61 ) ;
goto V_575;
}
V_10 -> V_547 = V_8 -> V_547 ;
F_246 ( V_8 , V_576 , & V_563 ) ;
F_21 ( V_63 L_113 ,
V_564 , V_10 -> V_17 , V_10 -> V_547 , F_120 ( V_8 ) ) ;
F_21 ( L_114 ,
V_10 -> V_11 . V_399 -> V_531 , V_563 ,
( unsigned long long ) F_242 ( V_8 , 0 ) ) ;
F_247 () ;
V_10 -> V_577 = F_248 ( F_242 ( V_8 , 0 ) , 0x1000 ) ;
if ( NULL == V_10 -> V_577 ) {
F_21 ( L_115 , V_10 -> V_11 . V_61 ) ;
V_489 = - V_574 ;
goto V_578;
}
F_249 ( V_10 ) ;
F_19 ( 0 , V_173 ) ;
V_489 = F_250 ( V_10 -> V_11 . V_399 -> V_531 , F_214 ,
V_579 | V_580 , V_10 -> V_11 . V_506 . V_310 , ( void * ) V_10 ) ;
if ( V_489 < 0 ) {
F_21 ( V_392 L_116 ,
V_564 , V_10 -> V_11 . V_399 -> V_531 ) ;
goto V_578;
}
if ( 0 != F_251 ( V_10 ) ) {
V_489 = - V_574 ;
goto V_581;
}
V_10 -> V_227 = V_582 ;
V_10 -> V_210 = V_583 ;
V_10 -> V_114 = V_584 ;
V_10 -> V_196 = V_585 ;
V_10 -> V_203 = V_586 ;
V_10 -> V_232 = V_587 ;
V_10 -> V_234 = V_206 ;
V_10 -> V_236 = V_208 ;
V_10 -> V_93 = V_588 ;
V_10 -> V_239 = V_589 ;
V_10 -> V_241 = V_590 ;
V_10 -> V_373 . V_10 = V_10 ;
V_10 -> V_373 . V_370 . V_355 . V_144 = 320 ;
V_10 -> V_373 . V_370 . V_355 . V_43 = 240 ;
V_10 -> V_373 . V_275 = F_65 ( V_591 ) ;
V_10 -> V_373 . V_144 = 320 ;
V_10 -> V_373 . V_43 = 240 ;
V_10 -> V_72 = 0 ;
if ( V_120 )
F_41 ( V_10 , L_117 ) ;
F_252 ( V_10 ) ;
F_58 ( V_10 ) ;
F_19 ( 0x00 , V_592 ) ;
F_19 ( 0x00 , V_252 ) ;
if ( V_212 )
F_41 ( V_10 , L_118 ) ;
F_253 ( V_10 ) ;
F_254 ( V_10 ) ;
F_255 ( V_10 ) ;
F_256 ( V_10 ) ;
F_57 ( V_10 ) ;
if ( ! V_98 [ V_10 -> V_11 . type ] . V_171 ) {
F_223 ( V_10 ) ;
F_28 ( V_10 , 32768 ) ;
F_30 ( V_10 , 32768 ) ;
F_29 ( V_10 , 32768 ) ;
F_32 ( V_10 , 32768 ) ;
F_46 ( V_10 , 1 ) ;
F_54 ( V_10 , 0 , V_10 -> V_39 ) ;
F_50 ( & V_10 -> V_30 [ 0 ] , V_10 -> V_39 ) ;
V_10 -> V_30 [ 1 ] = V_10 -> V_30 [ 0 ] ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
}
if ( V_98 [ V_10 -> V_11 . type ] . V_593 ) {
F_257 ( & V_10 -> V_11 , L_119 ) ;
F_6 ( V_10 ) ;
}
if ( ! V_594 ) {
F_258 ( V_10 ) ;
F_259 ( V_10 ) ;
}
V_564 ++ ;
return 0 ;
V_581:
F_260 ( V_10 -> V_11 . V_399 -> V_531 , V_10 ) ;
V_578:
F_261 ( & V_10 -> V_11 . V_506 ) ;
V_575:
if ( V_10 -> V_577 )
F_262 ( V_10 -> V_577 ) ;
F_263 ( F_242 ( V_10 -> V_11 . V_399 , 0 ) ,
F_243 ( V_10 -> V_11 . V_399 , 0 ) ) ;
return V_489 ;
}
static void T_14 F_264 ( struct V_557 * V_557 )
{
struct V_595 * V_506 = F_265 ( V_557 ) ;
struct V_9 * V_10 = F_266 ( V_506 ) ;
if ( V_212 )
F_21 ( L_120 , V_10 -> V_11 . V_61 ) ;
if ( V_98 [ V_10 -> V_11 . type ] . V_593 )
F_9 ( V_10 ) ;
F_36 ( ~ 15 , V_195 ) ;
F_19 ( 0 , V_173 ) ;
F_19 ( ~ 0x0 , V_170 ) ;
F_19 ( 0x0 , V_252 ) ;
if ( V_120 )
F_41 ( V_10 , L_121 ) ;
V_10 -> V_596 = 1 ;
F_267 ( V_10 ) ;
F_268 ( & V_10 -> V_11 ) ;
F_269 ( V_10 ) ;
F_220 ( V_10 ) ;
F_270 ( V_10 -> V_11 . V_399 , & V_10 -> main ) ;
F_260 ( V_10 -> V_11 . V_399 -> V_531 , V_10 ) ;
F_262 ( V_10 -> V_577 ) ;
F_263 ( F_242 ( V_10 -> V_11 . V_399 , 0 ) ,
F_243 ( V_10 -> V_11 . V_399 , 0 ) ) ;
F_261 ( & V_10 -> V_11 . V_506 ) ;
V_566 [ V_10 -> V_11 . V_61 ] = NULL ;
F_68 ( V_10 ) ;
return;
}
static int F_271 ( struct V_557 * V_557 , T_15 V_267 )
{
struct V_595 * V_506 = F_265 ( V_557 ) ;
struct V_9 * V_10 = F_266 ( V_506 ) ;
struct V_516 V_597 ;
unsigned long V_162 ;
F_24 ( L_122 , V_10 -> V_11 . V_61 , V_267 . V_598 ) ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
memset ( & V_597 , 0 , sizeof( V_597 ) ) ;
V_10 -> V_267 . V_599 = V_10 -> V_165 ;
V_10 -> V_267 . V_376 = V_10 -> V_509 ;
V_10 -> V_267 . V_270 = V_10 -> V_270 ;
V_10 -> V_165 = V_597 ;
V_10 -> V_270 = 0 ;
F_204 ( V_10 , & V_597 ) ;
F_205 ( V_10 , NULL ) ;
F_60 ( V_10 , 0 ) ;
F_19 ( 0 , V_173 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
V_10 -> V_267 . V_600 = F_18 ( V_252 ) ;
V_10 -> V_267 . V_601 = F_53 () ;
F_272 ( V_557 ) ;
if ( 0 != F_273 ( V_557 , F_274 ( V_557 , V_267 ) ) ) {
F_275 ( V_557 ) ;
V_10 -> V_267 . V_602 = 1 ;
}
return 0 ;
}
static int F_276 ( struct V_557 * V_557 )
{
struct V_595 * V_506 = F_265 ( V_557 ) ;
struct V_9 * V_10 = F_266 ( V_506 ) ;
unsigned long V_162 ;
int V_243 ;
F_24 ( L_123 , V_10 -> V_11 . V_61 ) ;
if ( V_10 -> V_267 . V_602 ) {
V_243 = F_238 ( V_557 ) ;
if ( V_243 ) {
F_21 ( V_573 L_109 ,
V_10 -> V_11 . V_61 ) ;
return V_243 ;
}
V_10 -> V_267 . V_602 = 0 ;
}
V_243 = F_273 ( V_557 , V_603 ) ;
if ( V_243 ) {
F_275 ( V_557 ) ;
F_21 ( V_573 L_109 ,
V_10 -> V_11 . V_61 ) ;
V_10 -> V_267 . V_602 = 1 ;
return V_243 ;
}
F_277 ( V_557 ) ;
F_59 ( V_10 ) ;
F_34 ( 0xffffff , V_10 -> V_267 . V_600 ) ;
F_278 ( V_10 -> V_267 . V_601 ) ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
V_10 -> V_165 = V_10 -> V_267 . V_599 ;
V_10 -> V_509 = V_10 -> V_267 . V_376 ;
V_10 -> V_270 = V_10 -> V_267 . V_270 ;
F_204 ( V_10 , & V_10 -> V_165 ) ;
F_205 ( V_10 , V_10 -> V_509 ) ;
F_60 ( V_10 , 0 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
return 0 ;
}
static int T_16 F_279 ( void )
{
int V_604 ;
V_564 = 0 ;
F_21 ( V_63 L_124 ,
( V_401 >> 16 ) & 0xff ,
( V_401 >> 8 ) & 0xff ,
V_401 & 0xff ) ;
#ifdef F_280
F_21 ( V_63 L_125 ,
F_280 / 10000 , ( F_280 / 100 ) % 100 , F_280 % 100 ) ;
#endif
if ( V_297 < 2 || V_297 > V_605 )
V_297 = 2 ;
if ( V_298 > V_606 )
V_298 = V_606 ;
V_298 = ( V_298 + V_607 - 1 ) & V_608 ;
if ( V_212 )
F_21 ( V_63 L_126 ,
V_297 , V_298 >> 10 , V_298 >> V_609 ) ;
F_281 () ;
V_604 = F_282 ( & V_610 ) ;
if ( V_604 < 0 ) {
F_21 ( V_573 L_127 , V_604 ) ;
return V_604 ;
}
V_604 = F_283 ( & V_611 ) ;
if ( V_604 < 0 )
F_284 ( & V_610 ) ;
return V_604 ;
}
static void T_17 F_285 ( void )
{
F_286 ( & V_611 ) ;
F_284 ( & V_610 ) ;
}
