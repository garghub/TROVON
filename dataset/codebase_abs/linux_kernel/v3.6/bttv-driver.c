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
case V_121 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
F_43 ( V_10 , V_122 , V_223 , V_11 ) ;
break;
case V_224 :
V_11 -> V_78 = V_10 -> V_196 ;
break;
case V_225 :
V_11 -> V_78 = V_10 -> V_226 ;
break;
case V_227 :
V_11 -> V_78 = V_10 -> V_210 ;
break;
case V_228 :
V_11 -> V_78 = V_10 -> V_113 ;
break;
case V_229 :
V_11 -> V_78 = V_10 -> V_203 ;
break;
case V_230 :
V_11 -> V_78 = V_10 -> V_231 ;
break;
case V_232 :
V_11 -> V_78 = V_10 -> V_233 ;
break;
case V_234 :
V_11 -> V_78 = V_10 -> V_235 ;
break;
case V_236 :
V_11 -> V_78 = V_10 -> V_93 ;
break;
case V_237 :
V_11 -> V_78 = V_10 -> V_238 ;
break;
case V_239 :
V_11 -> V_78 = V_10 -> V_240 ;
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_62 ( struct V_213 * V_213 , void * V_241 ,
struct V_108 * V_11 )
{
int V_242 ;
int V_184 ;
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_242 = F_63 ( & V_10 -> V_243 , V_21 -> V_243 ) ;
if ( 0 != V_242 )
return V_242 ;
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
case V_121 :
F_46 ( V_10 , V_11 -> V_78 ) ;
case V_219 :
if ( V_10 -> V_244 )
V_10 -> V_244 ( V_10 , V_11 -> V_78 ) ;
F_43 ( V_10 , V_122 , V_123 , V_11 ) ;
break;
case V_220 :
case V_221 :
case V_222 :
F_43 ( V_10 , V_122 , V_123 , V_11 ) ;
break;
case V_224 :
V_10 -> V_196 = V_11 -> V_78 ;
V_184 = V_10 -> V_196 ? V_197 : 0 ;
F_19 ( V_184 , V_198 ) ;
F_19 ( V_184 , V_199 ) ;
break;
case V_225 :
V_10 -> V_226 = V_11 -> V_78 ;
break;
case V_227 :
V_10 -> V_210 = V_11 -> V_78 ;
if ( V_10 -> V_210 ) {
F_36 ( ~ V_211 , V_86 ) ;
F_36 ( ~ V_211 , V_87 ) ;
} else {
F_35 ( V_211 , V_86 ) ;
F_35 ( V_211 , V_87 ) ;
}
break;
case V_228 :
V_10 -> V_113 = V_11 -> V_78 ;
break;
case V_229 :
V_10 -> V_203 = V_11 -> V_78 ;
F_19 ( V_202 |
( V_10 -> V_203 ? V_204 : 0 ) ,
V_205 ) ;
break;
case V_230 :
V_10 -> V_231 = V_11 -> V_78 ;
break;
case V_232 :
V_10 -> V_233 = V_11 -> V_78 ;
F_19 ( V_11 -> V_78 , V_207 ) ;
break;
case V_234 :
V_10 -> V_235 = V_11 -> V_78 ;
F_19 ( V_11 -> V_78 , V_209 ) ;
break;
case V_236 :
V_10 -> V_93 = V_11 -> V_78 ;
F_32 ( V_10 , V_10 -> V_92 ) ;
break;
case V_237 :
V_10 -> V_238 = V_11 -> V_78 ;
F_31 ( ( V_11 -> V_78 << 7 ) , ~ V_245 , V_246 ) ;
break;
case V_239 :
V_10 -> V_240 = V_11 -> V_78 ;
F_31 ( ( V_11 -> V_78 << 5 ) , ~ V_247 , V_246 ) ;
break;
default:
return - V_100 ;
}
return 0 ;
}
void F_41 ( struct V_9 * V_10 , char * V_248 )
{
unsigned int V_249 , V_250 ;
V_249 = F_18 ( V_251 ) ;
V_250 = F_18 ( V_252 ) ;
F_64 ( L_12 ,
V_10 -> V_11 . V_61 , V_249 , V_250 & V_249 , V_250 & ~ V_249 , V_248 ) ;
}
static void F_65 ( struct V_9 * V_10 )
{
int V_253 = 0 ;
if ( V_10 -> V_254 )
V_253 ++ ;
if ( V_253 ) {
F_35 ( V_255 , V_173 ) ;
} else {
F_36 ( ~ V_255 , V_173 ) ;
V_10 -> V_256 = 0 ;
}
}
static const struct V_257 *
F_66 ( int V_258 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_259 ; V_18 ++ ) {
if ( - 1 == V_260 [ V_18 ] . V_258 )
continue;
if ( V_260 [ V_18 ] . V_258 == V_258 )
return V_260 + V_18 ;
}
return NULL ;
}
static int
F_67 ( struct V_9 * V_10 , struct V_20 * V_21 ,
struct V_261 * V_262 )
{
struct V_261 * V_263 ;
unsigned long V_162 ;
int V_264 = 0 ;
F_24 ( L_13 , V_262 ) ;
if ( V_262 )
V_262 -> V_265 . V_266 = V_267 ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
V_263 = V_10 -> V_268 ;
V_10 -> V_268 = V_262 ;
V_10 -> V_269 |= 1 ;
F_60 ( V_10 , 0x03 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
if ( NULL != V_263 ) {
F_24 ( L_14 ,
V_263 , V_263 -> V_265 . V_266 ) ;
F_68 ( & V_21 -> V_270 , V_10 , V_263 ) ;
F_69 ( V_263 ) ;
}
if ( NULL == V_262 )
F_20 ( V_10 , V_21 , V_271 ) ;
F_24 ( L_15 ) ;
return V_264 ;
}
static int F_70 ( struct V_272 * V_273 , struct V_9 * V_10 ,
struct V_261 * V_5 ,
const struct V_257 * V_274 ,
unsigned int V_144 , unsigned int V_43 ,
enum V_275 V_276 )
{
struct V_20 * V_21 = V_273 -> V_277 ;
int V_278 = 0 ;
struct V_141 V_11 ;
int V_147 ;
int V_279 ;
if ( NULL == V_274 )
return - V_100 ;
if ( V_274 -> V_280 == V_281 ) {
V_144 = V_282 ;
V_43 = V_283 * 2 ;
if ( V_144 * V_43 > V_5 -> V_265 . V_284 )
return - V_100 ;
V_5 -> V_265 . V_285 = V_5 -> V_265 . V_284 ;
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
switch ( V_276 ) {
case V_286 :
case V_287 :
case V_288 :
if ( V_43 * 2 > V_11 . V_146 )
return - V_100 ;
break;
default:
if ( V_43 > V_11 . V_146 )
return - V_100 ;
break;
}
V_5 -> V_265 . V_285 = ( V_144 * V_43 * V_274 -> V_289 ) >> 3 ;
if ( 0 != V_5 -> V_265 . V_290 && V_5 -> V_265 . V_284 < V_5 -> V_265 . V_285 )
return - V_100 ;
}
if ( V_5 -> V_265 . V_144 != V_144 || V_5 -> V_265 . V_43 != V_43 ||
V_5 -> V_265 . V_276 != V_276 ||
V_5 -> V_39 != V_147 || V_5 -> V_274 != V_274 ||
V_5 -> V_30 . V_29 != V_11 . V_32 . V_29 ||
V_5 -> V_30 . V_291 != V_11 . V_32 . V_291 ||
V_5 -> V_30 . V_144 != V_11 . V_32 . V_144 ||
V_5 -> V_30 . V_43 != V_11 . V_32 . V_43 ) {
V_5 -> V_265 . V_144 = V_144 ;
V_5 -> V_265 . V_43 = V_43 ;
V_5 -> V_265 . V_276 = V_276 ;
V_5 -> V_39 = V_147 ;
V_5 -> V_274 = V_274 ;
V_5 -> V_30 = V_11 . V_32 ;
V_278 = 1 ;
}
if ( V_292 == V_5 -> V_265 . V_266 ) {
V_278 = 1 ;
if ( 0 != ( V_279 = F_71 ( V_273 , & V_5 -> V_265 , & V_10 -> V_293 ) ) )
goto V_27;
}
if ( V_278 )
if ( 0 != ( V_279 = F_72 ( V_10 , V_5 ) ) )
goto V_27;
V_5 -> V_265 . V_266 = V_294 ;
return 0 ;
V_27:
F_68 ( V_273 , V_10 , V_5 ) ;
return V_279 ;
}
static int
F_73 ( struct V_272 * V_273 , unsigned int * V_295 , unsigned int * V_285 )
{
struct V_20 * V_21 = V_273 -> V_277 ;
* V_285 = V_21 -> V_274 -> V_289 * V_21 -> V_144 * V_21 -> V_43 >> 3 ;
if ( 0 == * V_295 )
* V_295 = V_296 ;
if ( * V_285 * * V_295 > V_296 * V_297 )
* V_295 = ( V_296 * V_297 ) / * V_285 ;
return 0 ;
}
static int
F_74 ( struct V_272 * V_273 , struct V_298 * V_265 ,
enum V_275 V_276 )
{
struct V_261 * V_5 = F_2 ( V_265 , struct V_261 , V_265 ) ;
struct V_20 * V_21 = V_273 -> V_277 ;
return F_70 ( V_273 , V_21 -> V_10 , V_5 , V_21 -> V_274 ,
V_21 -> V_144 , V_21 -> V_43 , V_276 ) ;
}
static void
F_75 ( struct V_272 * V_273 , struct V_298 * V_265 )
{
struct V_261 * V_5 = F_2 ( V_265 , struct V_261 , V_265 ) ;
struct V_20 * V_21 = V_273 -> V_277 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_5 -> V_265 . V_266 = V_299 ;
F_76 ( & V_5 -> V_265 . V_300 , & V_10 -> V_301 ) ;
if ( ! V_10 -> V_165 . V_166 ) {
V_10 -> V_269 |= 1 ;
F_60 ( V_10 , 0x03 ) ;
}
}
static void F_77 ( struct V_272 * V_273 , struct V_298 * V_265 )
{
struct V_261 * V_5 = F_2 ( V_265 , struct V_261 , V_265 ) ;
struct V_20 * V_21 = V_273 -> V_277 ;
F_68 ( V_273 , V_21 -> V_10 , V_5 ) ;
}
static int F_78 ( struct V_213 * V_213 , void * V_214 , T_5 * V_17 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
unsigned int V_18 ;
int V_242 ;
V_242 = F_63 ( & V_10 -> V_243 , V_21 -> V_243 ) ;
if ( V_242 )
goto V_242;
for ( V_18 = 0 ; V_18 < V_149 ; V_18 ++ )
if ( * V_17 & V_40 [ V_18 ] . V_160 )
break;
if ( V_18 == V_149 ) {
V_242 = - V_100 ;
goto V_242;
}
F_51 ( V_10 , V_18 ) ;
V_242:
return V_242 ;
}
static int F_79 ( struct V_213 * V_213 , void * V_241 , T_5 * V_17 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( F_18 ( V_65 ) & V_302 )
* V_17 = V_303 ;
else
* V_17 = V_304 ;
return 0 ;
}
static int F_80 ( struct V_213 * V_213 , void * V_214 ,
struct V_305 * V_18 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_279 = 0 ;
if ( V_18 -> V_306 >= V_98 [ V_10 -> V_11 . type ] . V_99 ) {
V_279 = - V_100 ;
goto V_242;
}
V_18 -> type = V_307 ;
V_18 -> V_308 = 1 ;
if ( V_10 -> V_168 != V_169 && V_18 -> V_306 == 0 ) {
sprintf ( V_18 -> V_309 , L_16 ) ;
V_18 -> type = V_310 ;
V_18 -> V_311 = 0 ;
} else if ( V_18 -> V_306 == V_10 -> V_102 ) {
sprintf ( V_18 -> V_309 , L_17 ) ;
} else {
sprintf ( V_18 -> V_309 , L_18 , V_18 -> V_306 ) ;
}
if ( V_18 -> V_306 == V_10 -> V_72 ) {
T_6 V_312 = F_18 ( V_65 ) ;
if ( 0 == ( V_312 & V_313 ) )
V_18 -> V_314 |= V_315 ;
if ( 0 == ( V_312 & V_111 ) )
V_18 -> V_314 |= V_316 ;
}
V_18 -> V_317 = V_318 ;
V_242:
return V_279 ;
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
int V_242 ;
V_242 = F_63 ( & V_10 -> V_243 , V_21 -> V_243 ) ;
if ( F_83 ( V_242 ) )
goto V_242;
if ( V_18 > V_98 [ V_10 -> V_11 . type ] . V_99 ) {
V_242 = - V_100 ;
goto V_242;
}
F_54 ( V_10 , V_18 , V_10 -> V_39 ) ;
V_242:
return 0 ;
}
static int F_84 ( struct V_213 * V_213 , void * V_214 ,
struct V_319 * V_320 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_242 ;
if ( F_83 ( 0 != V_320 -> V_306 ) )
return - V_100 ;
if ( F_83 ( V_10 -> V_168 == V_169 ) ) {
V_242 = - V_100 ;
goto V_242;
}
V_242 = F_63 ( & V_10 -> V_243 , V_21 -> V_243 ) ;
if ( F_83 ( V_242 ) )
goto V_242;
F_43 ( V_10 , V_311 , V_321 , V_320 ) ;
if ( V_10 -> V_322 )
V_10 -> V_322 ( V_10 , V_320 , 1 ) ;
V_242:
return 0 ;
}
static int F_85 ( struct V_213 * V_213 , void * V_214 ,
struct V_323 * V_241 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_241 -> type = V_10 -> V_114 ? V_324 : V_325 ;
V_241 -> V_326 = V_10 -> V_327 ;
return 0 ;
}
static int F_86 ( struct V_213 * V_213 , void * V_214 ,
struct V_323 * V_241 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_242 ;
if ( F_83 ( V_241 -> V_311 != 0 ) )
return - V_100 ;
V_242 = F_63 ( & V_10 -> V_243 , V_21 -> V_243 ) ;
if ( F_83 ( V_242 ) )
goto V_242;
if ( F_83 ( V_241 -> type != ( V_10 -> V_114
? V_324 : V_325 ) ) ) {
V_242 = - V_100 ;
goto V_242;
}
V_10 -> V_327 = V_241 -> V_326 ;
F_43 ( V_10 , V_311 , V_328 , V_241 ) ;
if ( V_10 -> V_329 && V_10 -> V_114 )
F_87 ( V_10 , V_10 -> V_327 ) ;
V_242:
return 0 ;
}
static int F_88 ( struct V_213 * V_213 , void * V_241 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
F_43 ( V_10 , V_122 , V_330 ) ;
return 0 ;
}
static int F_89 ( struct V_213 * V_213 , void * V_241 ,
struct V_331 * V_332 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( ! F_90 ( V_333 ) )
return - V_334 ;
if ( ! F_91 ( & V_332 -> V_335 ) )
return - V_100 ;
V_332 -> V_332 &= 0xfff ;
V_332 -> V_184 = F_18 ( V_332 -> V_332 ) ;
V_332 -> V_285 = 1 ;
return 0 ;
}
static int F_92 ( struct V_213 * V_213 , void * V_241 ,
struct V_331 * V_332 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( ! F_90 ( V_333 ) )
return - V_334 ;
if ( ! F_91 ( & V_332 -> V_335 ) )
return - V_100 ;
V_332 -> V_332 &= 0xfff ;
F_19 ( V_332 -> V_184 , V_332 -> V_332 ) ;
return 0 ;
}
static void
F_93 ( struct V_141 * V_11 ,
const struct V_336 * V_337 ,
T_2 V_144 ,
T_2 V_43 ,
enum V_275 V_276 )
{
T_2 V_338 = V_43 << ! F_94 ( V_276 ) ;
T_2 V_339 ;
T_2 V_340 ;
if ( V_144 < V_11 -> V_142 ) {
V_11 -> V_32 . V_144 = V_144 * 16 ;
} else if ( V_144 > V_11 -> V_145 ) {
V_11 -> V_32 . V_144 = V_144 ;
V_339 = V_337 -> V_291 + V_337 -> V_144 - V_144 ;
V_339 = F_95 ( V_339 , ( T_2 ) V_341 ) ;
if ( V_11 -> V_32 . V_291 > V_339 )
V_11 -> V_32 . V_291 = V_339 ;
}
if ( V_43 < V_11 -> V_143 ) {
V_11 -> V_32 . V_43 = V_43 * 16 ;
} else if ( V_338 > V_11 -> V_146 ) {
V_11 -> V_32 . V_43 = ( V_338 + 1 ) & ~ 1 ;
V_340 = V_337 -> V_29 + V_337 -> V_43 - V_11 -> V_32 . V_43 ;
if ( V_11 -> V_32 . V_29 > V_340 )
V_11 -> V_32 . V_29 = V_340 ;
}
F_48 ( V_11 ) ;
}
static int
F_96 ( struct V_20 * V_21 ,
T_2 * V_144 ,
T_2 * V_43 ,
enum V_275 V_276 ,
unsigned int V_342 ,
unsigned int V_343 ,
int V_344 ,
int V_345 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_336 * V_337 ;
struct V_141 * V_11 ;
T_2 V_346 ;
T_2 V_347 ;
T_2 V_348 ;
T_2 V_349 ;
int V_279 ;
F_52 ( ( int ) V_342 >= 0 ||
V_343 >= ( unsigned int ) - V_342 ) ;
V_337 = & V_40 [ V_10 -> V_39 ] . V_41 . V_42 ;
V_11 = & V_10 -> V_30 [ ! ! V_21 -> V_31 ] ;
if ( V_21 -> V_31
&& V_344
&& V_345
&& ! F_15 ( V_10 , V_28 ) ) {
V_346 = 48 ;
V_347 = 32 ;
V_348 = F_95 ( V_337 -> V_144 , ( T_2 ) V_350 ) ;
V_349 = V_337 -> V_43 ;
if ( V_10 -> V_33 > V_337 -> V_29 ) {
V_349 -= V_10 -> V_33 - V_337 -> V_29 ;
V_279 = - V_351 ;
if ( V_347 > V_349 )
goto V_27;
}
} else {
V_279 = - V_351 ;
if ( V_10 -> V_33 > V_11 -> V_32 . V_29 )
goto V_27;
V_346 = V_11 -> V_142 ;
V_347 = V_11 -> V_143 ;
V_348 = V_11 -> V_145 ;
V_349 = V_11 -> V_146 ;
V_345 = 0 ;
}
V_346 = ( V_346 - V_342 - 1 ) & V_342 ;
V_348 = V_348 & V_342 ;
V_347 = V_347 ;
V_349 >>= ! F_94 ( V_276 ) ;
if ( V_344 ) {
* V_144 = F_97 ( * V_144 , V_346 , V_348 ) ;
* V_43 = F_97 ( * V_43 , V_347 , V_349 ) ;
* V_144 = ( * V_144 + V_343 ) & V_342 ;
if ( V_345 ) {
F_93 ( V_11 , V_337 , * V_144 , * V_43 , V_276 ) ;
if ( V_10 -> V_33 > V_11 -> V_32 . V_29 ) {
V_11 -> V_32 . V_29 = V_10 -> V_33 ;
}
}
} else {
V_279 = - V_100 ;
if ( * V_144 < V_346 ||
* V_43 < V_347 ||
* V_144 > V_348 ||
* V_43 > V_349 ||
0 != ( * V_144 & ~ V_342 ) )
goto V_27;
}
V_279 = 0 ;
V_27:
return V_279 ;
}
static int
F_98 ( struct V_20 * V_21 ,
struct V_352 * V_353 ,
int V_344 ,
int V_345 )
{
enum V_275 V_276 ;
unsigned int V_342 ;
int V_279 ;
if ( V_353 -> V_354 . V_144 < 48 || V_353 -> V_354 . V_43 < 32 )
return - V_100 ;
if ( V_353 -> V_355 > 2048 )
return - V_100 ;
V_276 = V_353 -> V_276 ;
if ( V_356 == V_276 ) {
T_2 V_357 ;
V_357 = V_21 -> V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_43 >> 1 ;
V_276 = ( V_353 -> V_354 . V_43 > V_357 )
? V_358
: V_286 ;
}
switch ( V_276 ) {
case V_286 :
case V_287 :
case V_358 :
break;
default:
return - V_100 ;
}
if ( NULL == V_21 -> V_359 )
return - V_100 ;
V_342 = ~ 0 ;
switch ( V_21 -> V_359 -> V_289 ) {
case 8 :
case 24 :
V_342 = ~ 3 ;
break;
case 16 :
V_342 = ~ 1 ;
break;
case 32 :
break;
default:
F_99 () ;
}
V_353 -> V_354 . V_144 -= V_353 -> V_354 . V_291 & ~ V_342 ;
V_353 -> V_354 . V_291 = ( V_353 -> V_354 . V_291 - V_342 - 1 ) & V_342 ;
V_279 = F_96 ( V_21 , & V_353 -> V_354 . V_144 , & V_353 -> V_354 . V_43 ,
V_276 , V_342 ,
0 ,
V_344 , V_345 ) ;
if ( 0 != V_279 )
return V_279 ;
V_353 -> V_276 = V_276 ;
return 0 ;
}
static int F_100 ( struct V_20 * V_21 , struct V_9 * V_10 ,
struct V_352 * V_353 , int V_360 )
{
struct V_361 * V_362 = NULL ;
int V_363 , V_285 , V_264 = 0 ;
if ( NULL == V_21 -> V_359 )
return - V_100 ;
if ( ! ( V_21 -> V_359 -> V_162 & V_364 ) )
return - V_100 ;
V_264 = F_98 ( V_21 , V_353 ,
V_360 ,
V_360 ) ;
if ( 0 != V_264 )
return V_264 ;
V_363 = V_353 -> V_355 ;
V_285 = sizeof( * V_362 ) * ( V_363 + 4 ) ;
V_362 = F_101 ( V_285 , V_365 ) ;
if ( NULL == V_362 )
return - V_366 ;
if ( V_363 > 0 ) {
if ( F_102 ( V_362 , V_353 -> V_362 , sizeof( struct V_361 ) * V_363 ) ) {
F_69 ( V_362 ) ;
return - V_367 ;
}
}
if ( NULL != V_10 -> V_293 . V_368 )
V_363 = F_103 ( V_10 -> V_293 . V_274 . V_144 , V_10 -> V_293 . V_274 . V_43 ,
& V_353 -> V_354 , V_362 , V_363 ) ;
F_104 ( V_362 , V_363 ) ;
switch ( V_21 -> V_359 -> V_289 ) {
case 8 :
case 24 :
F_105 ( & V_353 -> V_354 , V_362 , V_363 , 3 ) ;
break;
case 16 :
F_105 ( & V_353 -> V_354 , V_362 , V_363 , 1 ) ;
break;
case 32 :
break;
default:
F_99 () ;
}
F_69 ( V_21 -> V_369 . V_362 ) ;
V_21 -> V_369 . V_362 = V_362 ;
V_21 -> V_369 . V_370 = V_363 ;
V_21 -> V_369 . V_354 = V_353 -> V_354 ;
V_21 -> V_369 . V_276 = V_353 -> V_276 ;
V_21 -> V_369 . V_371 = 1 ;
V_10 -> V_372 . V_369 . V_354 . V_144 = V_353 -> V_354 . V_144 ;
V_10 -> V_372 . V_369 . V_354 . V_43 = V_353 -> V_354 . V_43 ;
V_10 -> V_372 . V_369 . V_276 = V_353 -> V_276 ;
V_264 = 0 ;
if ( F_14 ( V_21 , V_271 ) ) {
struct V_261 * V_262 ;
V_262 = F_106 ( sizeof( * V_262 ) ) ;
V_262 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_369 , V_21 -> V_359 , V_262 ) ;
V_264 = F_67 ( V_10 , V_21 , V_262 ) ;
}
return V_264 ;
}
static struct V_272 * F_108 ( struct V_20 * V_21 )
{
struct V_272 * V_273 = NULL ;
switch ( V_21 -> type ) {
case V_373 :
V_273 = & V_21 -> V_270 ;
break;
case V_374 :
V_273 = & V_21 -> V_375 ;
break;
default:
F_99 () ;
}
return V_273 ;
}
static int F_109 ( struct V_20 * V_21 )
{
int V_376 = 0 ;
switch ( V_21 -> type ) {
case V_373 :
V_376 = V_26 ;
break;
case V_374 :
V_376 = V_377 ;
break;
default:
F_99 () ;
}
return V_376 ;
}
static int F_110 ( struct V_20 * V_21 , enum V_378 type )
{
struct V_272 * V_273 = F_108 ( V_21 ) ;
int V_376 = F_109 ( V_21 ) ;
if ( F_14 ( V_21 , V_376 ) )
return - V_351 ;
if ( F_111 ( V_273 ) )
return - V_351 ;
V_21 -> type = type ;
return 0 ;
}
static void
F_112 ( struct V_379 * V_241 ,
const struct V_257 * V_274 ,
unsigned int V_144 ,
unsigned int V_43 )
{
V_241 -> V_144 = V_144 ;
V_241 -> V_43 = V_43 ;
if ( V_274 -> V_162 & V_380 ) {
V_241 -> V_381 = V_144 ;
V_241 -> V_382 = ( V_144 * V_43 * V_274 -> V_289 ) >> 3 ;
} else {
V_241 -> V_381 = ( V_144 * V_274 -> V_289 ) >> 3 ;
V_241 -> V_382 = V_43 * V_241 -> V_381 ;
}
}
static int F_113 ( struct V_213 * V_213 , void * V_214 ,
struct V_383 * V_241 )
{
struct V_20 * V_21 = V_214 ;
F_112 ( & V_241 -> V_274 . V_384 , V_21 -> V_274 ,
V_21 -> V_144 , V_21 -> V_43 ) ;
V_241 -> V_274 . V_384 . V_276 = V_21 -> V_270 . V_276 ;
V_241 -> V_274 . V_384 . V_385 = V_21 -> V_274 -> V_258 ;
return 0 ;
}
static int F_114 ( struct V_213 * V_213 , void * V_214 ,
struct V_383 * V_241 )
{
struct V_20 * V_21 = V_214 ;
V_241 -> V_274 . V_353 . V_354 = V_21 -> V_369 . V_354 ;
V_241 -> V_274 . V_353 . V_276 = V_21 -> V_369 . V_276 ;
return 0 ;
}
static int F_115 ( struct V_213 * V_213 , void * V_214 ,
struct V_383 * V_241 )
{
const struct V_257 * V_274 ;
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
enum V_275 V_276 ;
T_2 V_144 , V_43 ;
int V_279 ;
V_274 = F_66 ( V_241 -> V_274 . V_384 . V_385 ) ;
if ( NULL == V_274 )
return - V_100 ;
V_276 = V_241 -> V_274 . V_384 . V_276 ;
if ( V_356 == V_276 ) {
T_2 V_357 ;
V_357 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_43 >> 1 ;
V_276 = ( V_241 -> V_274 . V_384 . V_43 > V_357 )
? V_358
: V_287 ;
}
if ( V_386 == V_276 )
V_276 = V_387 ;
switch ( V_276 ) {
case V_286 :
case V_287 :
case V_288 :
case V_358 :
break;
case V_387 :
if ( V_274 -> V_162 & V_380 )
return - V_100 ;
break;
default:
return - V_100 ;
}
V_144 = V_241 -> V_274 . V_384 . V_144 ;
V_43 = V_241 -> V_274 . V_384 . V_43 ;
V_279 = F_96 ( V_21 , & V_144 , & V_43 , V_276 ,
~ 3 ,
2 ,
1 ,
0 ) ;
if ( 0 != V_279 )
return V_279 ;
V_241 -> V_274 . V_384 . V_276 = V_276 ;
F_112 ( & V_241 -> V_274 . V_384 , V_274 , V_144 , V_43 ) ;
return 0 ;
}
static int F_116 ( struct V_213 * V_213 , void * V_214 ,
struct V_383 * V_241 )
{
struct V_20 * V_21 = V_214 ;
return F_98 ( V_21 , & V_241 -> V_274 . V_353 ,
1 ,
0 ) ;
}
static int F_117 ( struct V_213 * V_213 , void * V_214 ,
struct V_383 * V_241 )
{
int V_264 ;
const struct V_257 * V_274 ;
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
T_2 V_144 , V_43 ;
enum V_275 V_276 ;
V_264 = F_110 ( V_21 , V_241 -> type ) ;
if ( 0 != V_264 )
return V_264 ;
V_264 = F_115 ( V_213 , V_214 , V_241 ) ;
if ( 0 != V_264 )
return V_264 ;
V_144 = V_241 -> V_274 . V_384 . V_144 ;
V_43 = V_241 -> V_274 . V_384 . V_43 ;
V_276 = V_241 -> V_274 . V_384 . V_276 ;
V_264 = F_96 ( V_21 , & V_144 , & V_43 , V_241 -> V_274 . V_384 . V_276 ,
~ 3 ,
2 ,
1 ,
1 ) ;
if ( 0 != V_264 )
return V_264 ;
V_241 -> V_274 . V_384 . V_276 = V_276 ;
V_274 = F_66 ( V_241 -> V_274 . V_384 . V_385 ) ;
V_21 -> V_274 = V_274 ;
V_21 -> V_270 . V_276 = V_241 -> V_274 . V_384 . V_276 ;
V_21 -> V_270 . V_388 = V_389 ;
V_21 -> V_144 = V_241 -> V_274 . V_384 . V_144 ;
V_21 -> V_43 = V_241 -> V_274 . V_384 . V_43 ;
V_10 -> V_372 . V_274 = V_274 ;
V_10 -> V_372 . V_144 = V_241 -> V_274 . V_384 . V_144 ;
V_10 -> V_372 . V_43 = V_241 -> V_274 . V_384 . V_43 ;
return 0 ;
}
static int F_118 ( struct V_213 * V_213 , void * V_214 ,
struct V_383 * V_241 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_390 > 0 ) {
F_21 ( L_19 ) ;
return - V_100 ;
}
return F_100 ( V_21 , V_10 , & V_241 -> V_274 . V_353 , 1 ) ;
}
static int F_119 ( struct V_213 * V_213 , void * V_214 ,
struct V_391 * V_270 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( 0 == V_392 )
return - V_100 ;
F_120 ( V_270 -> V_393 , L_20 , sizeof( V_270 -> V_393 ) ) ;
F_120 ( V_270 -> V_394 , V_10 -> V_395 -> V_309 , sizeof( V_270 -> V_394 ) ) ;
snprintf ( V_270 -> V_396 , sizeof( V_270 -> V_396 ) ,
L_21 , F_121 ( V_10 -> V_11 . V_397 ) ) ;
V_270 -> V_398 =
V_399 |
V_400 |
V_401 |
V_402 ;
if ( V_390 <= 0 )
V_270 -> V_398 |= V_403 ;
if ( V_10 -> V_404 )
V_270 -> V_398 |= V_405 ;
if ( V_10 -> V_168 != V_169 )
V_270 -> V_398 |= V_406 ;
return 0 ;
}
static int F_122 ( struct V_407 * V_241 )
{
int V_306 = - 1 , V_18 ;
for ( V_18 = 0 ; V_18 < V_259 ; V_18 ++ ) {
if ( V_260 [ V_18 ] . V_258 != - 1 )
V_306 ++ ;
if ( ( unsigned int ) V_306 == V_241 -> V_306 )
break;
}
if ( V_259 == V_18 )
return - V_100 ;
V_241 -> V_385 = V_260 [ V_18 ] . V_258 ;
F_120 ( V_241 -> V_408 , V_260 [ V_18 ] . V_309 , sizeof( V_241 -> V_408 ) ) ;
return V_18 ;
}
static int F_123 ( struct V_213 * V_213 , void * V_214 ,
struct V_407 * V_241 )
{
int V_279 = F_122 ( V_241 ) ;
if ( V_279 < 0 )
return V_279 ;
return 0 ;
}
static int F_124 ( struct V_213 * V_213 , void * V_214 ,
struct V_407 * V_241 )
{
int V_279 ;
if ( V_390 > 0 ) {
F_21 ( L_19 ) ;
return - V_100 ;
}
V_279 = F_122 ( V_241 ) ;
if ( V_279 < 0 )
return V_279 ;
if ( ! ( V_260 [ V_279 ] . V_162 & V_364 ) )
return - V_100 ;
return 0 ;
}
static int F_125 ( struct V_213 * V_213 , void * V_241 ,
struct V_409 * V_410 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_410 = V_10 -> V_293 ;
V_410 -> V_411 = V_412 ;
if ( V_21 -> V_359 )
V_410 -> V_274 . V_385 = V_21 -> V_359 -> V_258 ;
return 0 ;
}
static int F_126 ( struct V_213 * V_213 , void * V_241 , unsigned int V_413 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_261 * V_262 ;
int V_264 = 0 ;
if ( V_413 ) {
if ( F_83 ( ! V_10 -> V_293 . V_368 ) ) {
return - V_100 ;
}
if ( F_83 ( ! V_21 -> V_369 . V_371 ) ) {
F_24 ( L_22 , V_10 -> V_11 . V_61 ) ;
V_264 = - V_100 ;
}
if ( V_264 )
return V_264 ;
}
if ( ! F_13 ( V_10 , V_21 , V_271 ) )
return - V_351 ;
if ( V_413 ) {
V_21 -> V_369 . V_39 = V_10 -> V_39 ;
V_262 = F_106 ( sizeof( * V_262 ) ) ;
V_262 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_369 , V_21 -> V_359 , V_262 ) ;
} else {
V_262 = NULL ;
}
V_264 = F_67 ( V_10 , V_21 , V_262 ) ;
return V_264 ;
}
static int F_127 ( struct V_213 * V_213 , void * V_241 ,
struct V_409 * V_410 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_257 * V_274 ;
int V_264 ;
if ( ! F_90 ( V_333 ) &&
! F_90 ( V_414 ) )
return - V_334 ;
V_274 = F_66 ( V_410 -> V_274 . V_385 ) ;
if ( NULL == V_274 )
return - V_100 ;
if ( 0 == ( V_274 -> V_162 & V_364 ) )
return - V_100 ;
V_264 = - V_100 ;
if ( V_410 -> V_162 & V_415 ) {
T_2 V_144 = V_410 -> V_274 . V_144 ;
T_2 V_43 = V_410 -> V_274 . V_43 ;
V_264 = F_96 ( V_21 , & V_144 , & V_43 ,
V_358 ,
~ 3 ,
2 ,
0 ,
0 ) ;
if ( 0 != V_264 )
return V_264 ;
}
V_10 -> V_293 . V_368 = V_410 -> V_368 ;
V_10 -> V_293 . V_274 . V_144 = V_410 -> V_274 . V_144 ;
V_10 -> V_293 . V_274 . V_43 = V_410 -> V_274 . V_43 ;
if ( 0 != V_410 -> V_274 . V_381 )
V_10 -> V_293 . V_274 . V_381 = V_410 -> V_274 . V_381 ;
else
V_10 -> V_293 . V_274 . V_381 = V_10 -> V_293 . V_274 . V_144 * V_274 -> V_289 / 8 ;
V_264 = 0 ;
V_21 -> V_359 = V_274 ;
V_10 -> V_372 . V_359 = V_274 ;
if ( V_410 -> V_162 & V_415 ) {
V_21 -> V_369 . V_354 . V_291 = 0 ;
V_21 -> V_369 . V_354 . V_29 = 0 ;
V_21 -> V_369 . V_354 . V_144 = V_410 -> V_274 . V_144 ;
V_21 -> V_369 . V_354 . V_43 = V_410 -> V_274 . V_43 ;
V_10 -> V_372 . V_369 . V_354 . V_144 = V_410 -> V_274 . V_144 ;
V_10 -> V_372 . V_369 . V_354 . V_43 = V_410 -> V_274 . V_43 ;
F_69 ( V_21 -> V_369 . V_362 ) ;
V_21 -> V_369 . V_362 = NULL ;
V_21 -> V_369 . V_370 = 0 ;
if ( F_14 ( V_21 , V_271 ) ) {
struct V_261 * V_262 ;
V_262 = F_106 ( sizeof( * V_262 ) ) ;
V_262 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_369 , V_21 -> V_359 , V_262 ) ;
V_264 = F_67 ( V_10 , V_21 , V_262 ) ;
}
}
return V_264 ;
}
static int F_128 ( struct V_213 * V_213 , void * V_214 ,
struct V_416 * V_417 )
{
struct V_20 * V_21 = V_214 ;
return F_129 ( F_108 ( V_21 ) , V_417 ) ;
}
static int F_130 ( struct V_213 * V_213 , void * V_214 ,
struct V_418 * V_337 )
{
struct V_20 * V_21 = V_214 ;
return F_131 ( F_108 ( V_21 ) , V_337 ) ;
}
static int F_132 ( struct V_213 * V_213 , void * V_214 , struct V_418 * V_337 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_376 = F_109 ( V_21 ) ;
if ( ! F_13 ( V_10 , V_21 , V_376 ) )
return - V_351 ;
return F_133 ( F_108 ( V_21 ) , V_337 ) ;
}
static int F_134 ( struct V_213 * V_213 , void * V_214 , struct V_418 * V_337 )
{
struct V_20 * V_21 = V_214 ;
return F_135 ( F_108 ( V_21 ) , V_337 ,
V_213 -> V_419 & V_420 ) ;
}
static int F_136 ( struct V_213 * V_213 , void * V_214 ,
enum V_378 type )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_376 = F_109 ( V_21 ) ;
if ( ! F_13 ( V_10 , V_21 , V_376 ) )
return - V_351 ;
return F_137 ( F_108 ( V_21 ) ) ;
}
static int F_138 ( struct V_213 * V_213 , void * V_214 ,
enum V_378 type )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_264 ;
int V_376 = F_109 ( V_21 ) ;
V_264 = F_139 ( F_108 ( V_21 ) ) ;
if ( V_264 < 0 )
return V_264 ;
F_20 ( V_10 , V_21 , V_376 ) ;
return 0 ;
}
static int F_140 ( struct V_213 * V_213 , void * V_214 ,
struct V_16 * V_11 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_16 * V_109 ;
if ( ( V_11 -> V_17 < V_421 ||
V_11 -> V_17 >= V_422 ) &&
( V_11 -> V_17 < V_423 ||
V_11 -> V_17 >= V_424 ) )
return - V_100 ;
if ( ! V_10 -> V_244 && ( V_11 -> V_17 == V_219 ) )
* V_11 = V_425 ;
else {
V_109 = F_11 ( V_11 -> V_17 ) ;
* V_11 = ( NULL != V_109 ) ? * V_109 : V_425 ;
}
return 0 ;
}
static int F_141 ( struct V_213 * V_213 , void * V_241 ,
struct V_426 * V_427 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
F_142 ( V_40 [ V_10 -> V_39 ] . V_160 ,
& V_427 -> V_427 . V_301 . V_428 ) ;
return 0 ;
}
static int F_143 ( struct V_213 * V_213 , void * V_214 ,
struct V_319 * V_320 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_10 -> V_168 == V_169 )
return - V_100 ;
if ( 0 != V_320 -> V_306 )
return - V_100 ;
V_320 -> V_429 = V_430 ;
F_43 ( V_10 , V_311 , V_431 , V_320 ) ;
strcpy ( V_320 -> V_309 , L_16 ) ;
V_320 -> V_411 = V_432 ;
V_320 -> type = V_325 ;
if ( F_18 ( V_65 ) & V_111 )
V_320 -> signal = 0xffff ;
if ( V_10 -> V_322 )
V_10 -> V_322 ( V_10 , V_320 , 0 ) ;
return 0 ;
}
static int F_144 ( struct V_213 * V_213 , void * V_241 , enum V_433 * V_417 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_417 = F_145 ( & V_10 -> V_243 ) ;
return 0 ;
}
static int F_146 ( struct V_213 * V_213 , void * V_241 ,
enum V_433 V_243 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_279 ;
V_279 = F_147 ( & V_10 -> V_243 , & V_21 -> V_243 , V_243 ) ;
return V_279 ;
}
static int F_148 ( struct V_213 * V_213 , void * V_214 ,
struct V_434 * V_270 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_270 -> type != V_373 &&
V_270 -> type != V_435 )
return - V_100 ;
* V_270 = V_40 [ V_10 -> V_39 ] . V_41 ;
return 0 ;
}
static int F_149 ( struct V_213 * V_213 , void * V_241 , struct V_436 * V_30 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_30 -> type != V_373 &&
V_30 -> type != V_435 )
return - V_100 ;
V_30 -> V_11 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
return 0 ;
}
static int F_150 ( struct V_213 * V_213 , void * V_241 , struct V_436 * V_30 )
{
struct V_20 * V_21 = V_241 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_336 * V_337 ;
int V_264 ;
struct V_141 V_11 ;
T_2 V_437 ;
T_2 V_438 ;
T_2 V_439 ;
T_2 V_440 ;
if ( V_30 -> type != V_373 &&
V_30 -> type != V_435 )
return - V_100 ;
V_264 = F_63 ( & V_10 -> V_243 , V_21 -> V_243 ) ;
if ( 0 != V_264 ) {
return V_264 ;
}
V_264 = - V_351 ;
if ( F_15 ( V_21 -> V_10 , V_28 ) ) {
return V_264 ;
}
V_337 = & V_40 [ V_10 -> V_39 ] . V_41 . V_42 ;
V_437 = V_337 -> V_291 ;
V_439 = V_437 + V_337 -> V_144 ;
V_440 = V_337 -> V_29 + V_337 -> V_43 ;
V_438 = F_49 ( V_337 -> V_29 , V_10 -> V_33 ) ;
if ( V_438 + 32 >= V_440 ) {
return V_264 ;
}
V_11 . V_32 . V_291 = F_97 ( V_30 -> V_11 . V_291 , V_437 , V_439 - 48 ) ;
V_11 . V_32 . V_291 = F_95 ( V_11 . V_32 . V_291 , ( T_2 ) V_341 ) ;
V_11 . V_32 . V_144 = F_97 ( V_30 -> V_11 . V_144 ,
48 , V_439 - V_11 . V_32 . V_291 ) ;
V_11 . V_32 . V_29 = F_97 ( V_30 -> V_11 . V_29 , V_438 , V_440 - 32 ) ;
V_11 . V_32 . V_29 = ( V_11 . V_32 . V_29 + 1 ) & ~ 1 ;
V_11 . V_32 . V_43 = F_97 ( V_30 -> V_11 . V_43 ,
32 , V_440 - V_11 . V_32 . V_29 ) ;
V_11 . V_32 . V_43 = ( V_11 . V_32 . V_43 + 1 ) & ~ 1 ;
F_48 ( & V_11 ) ;
V_10 -> V_30 [ 1 ] = V_11 ;
V_21 -> V_31 = 1 ;
if ( V_21 -> V_144 < V_11 . V_142 ) {
V_21 -> V_144 = V_11 . V_142 ;
V_10 -> V_372 . V_144 = V_11 . V_142 ;
} else if ( V_21 -> V_144 > V_11 . V_145 ) {
V_21 -> V_144 = V_11 . V_145 ;
V_10 -> V_372 . V_144 = V_11 . V_145 ;
}
if ( V_21 -> V_43 < V_11 . V_143 ) {
V_21 -> V_43 = V_11 . V_143 ;
V_10 -> V_372 . V_43 = V_11 . V_143 ;
} else if ( V_21 -> V_43 > V_11 . V_146 ) {
V_21 -> V_43 = V_11 . V_146 ;
V_10 -> V_372 . V_43 = V_11 . V_146 ;
}
return 0 ;
}
static int F_151 ( struct V_213 * V_213 , void * V_214 , struct V_441 * V_442 )
{
if ( F_83 ( V_442 -> V_306 ) )
return - V_100 ;
strcpy ( V_442 -> V_309 , L_23 ) ;
return 0 ;
}
static int F_152 ( struct V_213 * V_213 , void * V_214 , struct V_441 * V_442 )
{
if ( F_83 ( V_442 -> V_306 ) )
return - V_100 ;
return 0 ;
}
static T_1 F_153 ( struct V_213 * V_213 , char T_7 * V_250 ,
T_8 V_295 , T_9 * V_443 )
{
struct V_20 * V_21 = V_213 -> V_444 ;
int V_264 = 0 ;
if ( V_21 -> V_10 -> V_212 )
F_59 ( V_21 -> V_10 ) ;
F_24 ( L_24 ,
V_21 -> V_10 -> V_11 . V_61 , ( int ) V_295 , V_445 [ V_21 -> type ] ) ;
switch ( V_21 -> type ) {
case V_373 :
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_25 ) ) {
return - V_351 ;
}
V_264 = F_154 ( & V_21 -> V_270 , V_250 , V_295 , V_443 ,
V_213 -> V_419 & V_420 ) ;
F_20 ( V_21 -> V_10 , V_21 , V_25 ) ;
break;
case V_374 :
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_377 ) )
return - V_351 ;
V_264 = F_155 ( & V_21 -> V_375 , V_250 , V_295 , V_443 , 1 ,
V_213 -> V_419 & V_420 ) ;
break;
default:
F_99 () ;
}
return V_264 ;
}
static unsigned int F_156 ( struct V_213 * V_213 , T_10 * V_446 )
{
struct V_20 * V_21 = V_213 -> V_444 ;
struct V_261 * V_5 ;
enum V_275 V_276 ;
unsigned int V_279 = V_447 ;
if ( V_374 == V_21 -> type ) {
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_377 ) )
return V_447 ;
return F_157 ( V_213 , & V_21 -> V_375 , V_446 ) ;
}
if ( F_14 ( V_21 , V_26 ) ) {
if ( F_158 ( & V_21 -> V_270 . V_448 ) )
goto V_242;
V_5 = F_159 ( V_21 -> V_270 . V_448 . V_449 , struct V_261 , V_265 . V_448 ) ;
} else {
if ( NULL == V_21 -> V_270 . V_450 ) {
if ( F_15 ( V_21 -> V_10 , V_26 ) )
goto V_242;
V_21 -> V_270 . V_450 = F_106 ( V_21 -> V_270 . V_451 ) ;
if ( NULL == V_21 -> V_270 . V_450 )
goto V_242;
V_21 -> V_270 . V_450 -> V_452 = V_453 ;
V_276 = F_160 ( & V_21 -> V_270 ) ;
if ( 0 != V_21 -> V_270 . V_454 -> V_455 ( & V_21 -> V_270 , V_21 -> V_270 . V_450 , V_276 ) ) {
F_69 ( V_21 -> V_270 . V_450 ) ;
V_21 -> V_270 . V_450 = NULL ;
goto V_242;
}
V_21 -> V_270 . V_454 -> V_456 ( & V_21 -> V_270 , V_21 -> V_270 . V_450 ) ;
V_21 -> V_270 . V_457 = 0 ;
}
V_5 = (struct V_261 * ) V_21 -> V_270 . V_450 ;
}
F_161 ( V_213 , & V_5 -> V_265 . V_458 , V_446 ) ;
if ( V_5 -> V_265 . V_266 == V_267 ||
V_5 -> V_265 . V_266 == V_459 )
V_279 = V_460 | V_461 ;
else
V_279 = 0 ;
V_242:
return V_279 ;
}
static int F_162 ( struct V_213 * V_213 )
{
struct V_6 * V_462 = F_163 ( V_213 ) ;
struct V_9 * V_10 = F_164 ( V_213 ) ;
struct V_20 * V_21 ;
enum V_378 type = 0 ;
F_24 ( L_25 , F_165 ( V_462 ) ) ;
if ( V_462 -> V_463 == V_464 ) {
type = V_373 ;
} else if ( V_462 -> V_463 == V_465 ) {
type = V_374 ;
} else {
F_166 ( 1 ) ;
return - V_466 ;
}
F_24 ( L_26 ,
V_10 -> V_11 . V_61 , V_445 [ type ] ) ;
V_21 = F_101 ( sizeof( * V_21 ) , V_365 ) ;
if ( F_83 ( ! V_21 ) )
return - V_366 ;
V_213 -> V_444 = V_21 ;
* V_21 = V_10 -> V_372 ;
V_21 -> type = type ;
V_21 -> V_369 . V_371 = 0 ;
F_167 ( & V_10 -> V_243 , & V_21 -> V_243 ) ;
F_168 ( & V_21 -> V_270 , & V_467 ,
& V_10 -> V_11 . V_397 -> V_8 , & V_10 -> V_164 ,
V_373 ,
V_358 ,
sizeof( struct V_261 ) ,
V_21 , & V_10 -> V_468 ) ;
F_168 ( & V_21 -> V_375 , & V_469 ,
& V_10 -> V_11 . V_397 -> V_8 , & V_10 -> V_164 ,
V_374 ,
V_387 ,
sizeof( struct V_261 ) ,
V_21 , & V_10 -> V_468 ) ;
F_51 ( V_10 , V_10 -> V_39 ) ;
F_54 ( V_10 , V_10 -> V_72 , V_10 -> V_39 ) ;
V_10 -> V_254 ++ ;
V_21 -> V_31 = ! V_470 ;
F_169 ( & V_21 -> V_37 , V_10 -> V_39 ) ;
F_65 ( V_10 ) ;
return 0 ;
}
static int F_170 ( struct V_213 * V_213 )
{
struct V_20 * V_21 = V_213 -> V_444 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( F_14 ( V_21 , V_271 ) )
F_67 ( V_10 , V_21 , NULL ) ;
if ( F_14 ( V_21 , V_26 ) ) {
F_139 ( & V_21 -> V_270 ) ;
F_20 ( V_10 , V_21 , V_26 ) ;
}
if ( V_21 -> V_270 . V_450 ) {
F_77 ( & V_21 -> V_270 , V_21 -> V_270 . V_450 ) ;
F_69 ( V_21 -> V_270 . V_450 ) ;
}
if ( F_14 ( V_21 , V_25 ) ) {
F_20 ( V_10 , V_21 , V_25 ) ;
}
if ( F_14 ( V_21 , V_377 ) ) {
F_171 ( & V_21 -> V_375 ) ;
F_20 ( V_10 , V_21 , V_377 ) ;
}
F_172 ( & V_21 -> V_270 ) ;
F_172 ( & V_21 -> V_375 ) ;
F_173 ( & V_10 -> V_243 , V_21 -> V_243 ) ;
V_213 -> V_444 = NULL ;
F_69 ( V_21 ) ;
V_10 -> V_254 -- ;
F_65 ( V_10 ) ;
if ( ! V_10 -> V_254 )
F_46 ( V_10 , 1 ) ;
return 0 ;
}
static int
F_174 ( struct V_213 * V_213 , struct V_471 * V_472 )
{
struct V_20 * V_21 = V_213 -> V_444 ;
F_24 ( L_27 ,
V_21 -> V_10 -> V_11 . V_61 , V_445 [ V_21 -> type ] ,
V_472 -> V_473 , V_472 -> V_474 - V_472 -> V_473 ) ;
return F_175 ( F_108 ( V_21 ) , V_472 ) ;
}
static int F_176 ( struct V_213 * V_213 )
{
struct V_6 * V_462 = F_163 ( V_213 ) ;
struct V_9 * V_10 = F_164 ( V_213 ) ;
struct V_20 * V_21 ;
F_24 ( L_25 , F_165 ( V_462 ) ) ;
F_24 ( L_28 , V_10 -> V_11 . V_61 ) ;
V_21 = F_101 ( sizeof( * V_21 ) , V_365 ) ;
if ( F_83 ( ! V_21 ) )
return - V_366 ;
V_213 -> V_444 = V_21 ;
* V_21 = V_10 -> V_372 ;
F_167 ( & V_10 -> V_243 , & V_21 -> V_243 ) ;
V_10 -> V_114 ++ ;
F_43 ( V_10 , V_311 , V_475 ) ;
F_47 ( V_10 , V_126 ) ;
return 0 ;
}
static int F_177 ( struct V_213 * V_213 )
{
struct V_20 * V_21 = V_213 -> V_444 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_476 V_477 ;
F_173 ( & V_10 -> V_243 , V_21 -> V_243 ) ;
V_213 -> V_444 = NULL ;
F_69 ( V_21 ) ;
V_10 -> V_114 -- ;
F_43 ( V_10 , V_122 , V_478 , V_479 , & V_477 ) ;
return 0 ;
}
static int F_178 ( struct V_213 * V_213 , void * V_214 ,
struct V_391 * V_270 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
strcpy ( V_270 -> V_393 , L_20 ) ;
F_120 ( V_270 -> V_394 , V_10 -> V_480 -> V_309 , sizeof( V_270 -> V_394 ) ) ;
sprintf ( V_270 -> V_396 , L_21 , F_121 ( V_10 -> V_11 . V_397 ) ) ;
V_270 -> V_398 = V_406 ;
return 0 ;
}
static int F_179 ( struct V_213 * V_213 , void * V_214 , struct V_319 * V_320 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_10 -> V_168 == V_169 )
return - V_100 ;
if ( 0 != V_320 -> V_306 )
return - V_100 ;
strcpy ( V_320 -> V_309 , L_29 ) ;
V_320 -> type = V_324 ;
F_43 ( V_10 , V_311 , V_431 , V_320 ) ;
if ( V_10 -> V_322 )
V_10 -> V_322 ( V_10 , V_320 , 0 ) ;
return 0 ;
}
static int F_180 ( struct V_213 * V_213 , void * V_214 ,
struct V_305 * V_18 )
{
if ( V_18 -> V_306 != 0 )
return - V_100 ;
strcpy ( V_18 -> V_309 , L_29 ) ;
V_18 -> type = V_310 ;
return 0 ;
}
static int F_181 ( struct V_213 * V_213 , void * V_214 ,
struct V_441 * V_442 )
{
if ( F_83 ( V_442 -> V_306 ) )
return - V_100 ;
strcpy ( V_442 -> V_309 , L_29 ) ;
return 0 ;
}
static int F_182 ( struct V_213 * V_213 , void * V_214 ,
struct V_319 * V_320 )
{
struct V_20 * V_21 = V_214 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( 0 != V_320 -> V_306 )
return - V_100 ;
F_43 ( V_10 , V_311 , V_321 , V_320 ) ;
return 0 ;
}
static int F_183 ( struct V_213 * V_213 , void * V_214 ,
struct V_441 * V_442 )
{
if ( F_83 ( V_442 -> V_306 ) )
return - V_100 ;
return 0 ;
}
static int F_184 ( struct V_213 * V_481 , void * V_214 , unsigned int V_18 )
{
if ( F_83 ( V_18 ) )
return - V_100 ;
return 0 ;
}
static int F_185 ( struct V_213 * V_213 , void * V_21 , T_5 * V_147 )
{
return 0 ;
}
static int F_186 ( struct V_213 * V_213 , void * V_214 ,
struct V_16 * V_11 )
{
const struct V_16 * V_109 ;
if ( V_11 -> V_17 < V_421 ||
V_11 -> V_17 >= V_422 )
return - V_100 ;
if ( V_11 -> V_17 == V_121 ) {
V_109 = F_11 ( V_11 -> V_17 ) ;
* V_11 = * V_109 ;
} else
* V_11 = V_425 ;
return 0 ;
}
static int F_187 ( struct V_213 * V_481 , void * V_214 , unsigned int * V_18 )
{
* V_18 = 0 ;
return 0 ;
}
static T_1 F_188 ( struct V_213 * V_213 , char T_7 * V_250 ,
T_8 V_295 , T_9 * V_443 )
{
struct V_20 * V_21 = V_213 -> V_444 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_476 V_477 ;
V_477 . V_482 = V_295 / 3 ;
V_477 . V_483 = V_250 ;
V_477 . V_484 = V_213 ;
V_477 . V_485 = - V_466 ;
F_43 ( V_10 , V_122 , V_478 , V_486 , & V_477 ) ;
return V_477 . V_485 ;
}
static unsigned int F_189 ( struct V_213 * V_213 , T_10 * V_446 )
{
struct V_20 * V_21 = V_213 -> V_444 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_476 V_477 ;
V_477 . V_484 = V_213 ;
V_477 . V_487 = V_446 ;
V_477 . V_485 = - V_466 ;
F_43 ( V_10 , V_122 , V_478 , V_488 , & V_477 ) ;
return V_477 . V_485 ;
}
static int F_190 ( T_4 V_489 )
{
static char * V_490 [ 16 ] = {
[ V_491 >> 28 ] = L_30 ,
[ V_492 >> 28 ] = L_31 ,
[ V_493 >> 28 ] = L_32 ,
[ V_494 >> 28 ] = L_33 ,
[ V_495 >> 28 ] = L_34 ,
[ V_496 >> 28 ] = L_35 ,
[ V_497 >> 28 ] = L_36 ,
[ V_498 >> 28 ] = L_37 ,
} ;
static int V_499 [ 16 ] = {
[ V_491 >> 28 ] = 2 ,
[ V_494 >> 28 ] = 2 ,
[ V_495 >> 28 ] = 2 ,
[ V_496 >> 28 ] = 5 ,
[ V_497 >> 28 ] = 2 ,
[ V_498 >> 28 ] = 3 ,
} ;
static char * V_48 [] = {
L_38 , L_39 , L_40 , L_41 ,
L_42 , L_43 , L_44 , L_45 ,
L_46 , L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 , L_53 ,
} ;
int V_18 ;
F_191 ( L_54 , V_489 ,
V_490 [ V_489 >> 28 ] ? V_490 [ V_489 >> 28 ] : L_55 ) ;
for ( V_18 = F_12 ( V_48 ) - 1 ; V_18 >= 0 ; V_18 -- )
if ( V_489 & ( 1 << ( V_18 + 12 ) ) )
F_191 ( L_56 , V_48 [ V_18 ] ) ;
F_191 ( L_57 , V_489 & 0xfff ) ;
return V_499 [ V_489 >> 28 ] ? V_499 [ V_489 >> 28 ] : 1 ;
}
static void F_192 ( struct V_9 * V_10 ,
struct V_500 * V_489 )
{
unsigned int V_18 , V_501 , V_363 ;
F_25 ( L_58 ,
V_10 -> V_11 . V_502 . V_309 , V_489 -> V_503 , ( unsigned long ) V_489 -> V_504 ) ;
for ( V_18 = 0 ; V_18 < ( V_489 -> V_285 >> 2 ) ; V_18 += V_363 ) {
F_25 ( L_59 ,
V_10 -> V_11 . V_502 . V_309 ,
( unsigned long ) ( V_489 -> V_504 + ( V_18 << 2 ) ) ) ;
V_363 = F_190 ( F_193 ( V_489 -> V_503 [ V_18 ] ) ) ;
for ( V_501 = 1 ; V_501 < V_363 ; V_501 ++ )
F_25 ( L_60 ,
V_10 -> V_11 . V_502 . V_309 ,
( unsigned long ) ( V_489 -> V_504 + ( ( V_18 + V_501 ) << 2 ) ) ,
V_489 -> V_503 [ V_18 + V_501 ] , V_501 ) ;
if ( 0 == V_489 -> V_503 [ V_18 ] )
break;
}
}
static void F_194 ( struct V_9 * V_10 )
{
F_25 ( L_61 , ( unsigned long long ) V_10 -> main. V_504 ) ;
F_25 ( L_62 ,
V_10 -> V_505 ? ( unsigned long long ) V_10 -> V_505 -> V_29 . V_504 : 0 ,
V_10 -> V_505 ? ( unsigned long long ) V_10 -> V_505 -> V_506 . V_504 : 0 ) ;
F_25 ( L_63 ,
V_10 -> V_165 . V_29
? ( unsigned long long ) V_10 -> V_165 . V_29 -> V_29 . V_504 : 0 ,
V_10 -> V_165 . V_506
? ( unsigned long long ) V_10 -> V_165 . V_506 -> V_506 . V_504 : 0 ) ;
F_25 ( L_64 ,
V_10 -> V_268 ? ( unsigned long long ) V_10 -> V_268 -> V_29 . V_504 : 0 ,
V_10 -> V_268 ? ( unsigned long long ) V_10 -> V_268 -> V_506 . V_504 : 0 ) ;
F_192 ( V_10 , & V_10 -> main ) ;
}
static void F_195 ( T_4 V_507 , T_4 V_508 )
{
unsigned int V_18 ;
F_191 ( L_65 ) ;
for ( V_18 = 0 ; V_18 < F_12 ( V_509 ) ; V_18 ++ ) {
if ( V_507 & ( 1 << V_18 ) )
F_191 ( L_56 , V_509 [ V_18 ] ) ;
if ( V_508 & ( 1 << V_18 ) )
F_191 ( L_66 ) ;
}
}
static void F_196 ( struct V_9 * V_10 , T_4 V_279 )
{
F_197 ( L_67 ,
V_10 -> V_11 . V_61 ,
( unsigned long ) V_10 -> main. V_504 ,
( unsigned long ) F_193 ( V_10 -> main. V_503 [ V_510 + 1 ] ) ,
( unsigned long ) F_193 ( V_10 -> main. V_503 [ V_511 + 1 ] ) ,
( unsigned long ) V_279 ) ;
if ( 0 == ( F_18 ( V_65 ) & V_111 ) ) {
F_198 ( L_68
L_69 ,
V_10 -> V_11 . V_61 ) ;
return;
}
F_198 ( L_70 ,
V_10 -> V_11 . V_61 ) ;
F_198 ( L_71 ,
V_10 -> V_11 . V_61 ) ;
F_199 () ;
}
static int
F_200 ( struct V_9 * V_10 , struct V_512 * V_513 )
{
struct V_261 * V_514 ;
memset ( V_513 , 0 , sizeof( * V_513 ) ) ;
if ( ! F_158 ( & V_10 -> V_301 ) ) {
V_513 -> V_166 = 1 ;
V_514 = F_159 ( V_10 -> V_301 . V_449 , struct V_261 , V_265 . V_300 ) ;
if ( F_201 ( V_514 -> V_265 . V_276 ) )
V_513 -> V_29 = V_514 ;
if ( F_202 ( V_514 -> V_265 . V_276 ) )
V_513 -> V_506 = V_514 ;
if ( ! F_94 ( V_514 -> V_265 . V_276 ) &&
( V_514 -> V_265 . V_300 . V_449 != & V_10 -> V_301 ) ) {
V_514 = F_159 ( V_514 -> V_265 . V_300 . V_449 , struct V_261 , V_265 . V_300 ) ;
if ( ! F_94 ( V_514 -> V_265 . V_276 ) ) {
if ( NULL == V_513 -> V_506 &&
V_287 == V_514 -> V_265 . V_276 ) {
V_513 -> V_506 = V_514 ;
}
if ( NULL != V_513 -> V_29 && NULL != V_513 -> V_506 )
V_513 -> V_515 = 2 ;
}
}
}
if ( NULL != V_10 -> V_268 ) {
if ( F_94 ( V_10 -> V_268 -> V_265 . V_276 ) ) {
if ( NULL == V_513 -> V_29 && NULL == V_513 -> V_506 ) {
V_513 -> V_29 = V_10 -> V_268 ;
V_513 -> V_506 = V_10 -> V_268 ;
}
} else {
if ( V_286 == V_10 -> V_268 -> V_265 . V_276 &&
NULL == V_513 -> V_29 ) {
V_513 -> V_29 = V_10 -> V_268 ;
}
if ( V_287 == V_10 -> V_268 -> V_265 . V_276 &&
NULL == V_513 -> V_506 ) {
V_513 -> V_506 = V_10 -> V_268 ;
}
}
}
F_24 ( L_72 ,
V_10 -> V_11 . V_61 , V_513 -> V_29 , V_513 -> V_506 ,
V_10 -> V_268 , V_513 -> V_166 , V_513 -> V_515 ) ;
return 0 ;
}
static void
F_203 ( struct V_9 * V_10 , struct V_512 * V_516 ,
struct V_512 * V_165 , unsigned int V_266 )
{
struct V_517 V_518 ;
F_204 ( & V_518 ) ;
if ( V_516 -> V_29 == V_516 -> V_506 ) {
if ( NULL != V_516 -> V_29 && V_165 -> V_29 != V_516 -> V_29 ) {
if ( V_519 > 1 )
F_64 ( L_73 ,
V_10 -> V_11 . V_61 , V_516 -> V_29 ) ;
V_516 -> V_29 -> V_265 . V_518 = V_518 ;
V_516 -> V_29 -> V_265 . V_256 = V_10 -> V_256 ;
V_516 -> V_29 -> V_265 . V_266 = V_266 ;
F_205 ( & V_516 -> V_29 -> V_265 . V_458 ) ;
}
} else {
if ( NULL != V_516 -> V_29 && V_165 -> V_29 != V_516 -> V_29 ) {
if ( V_519 > 1 )
F_64 ( L_74 ,
V_10 -> V_11 . V_61 , V_516 -> V_29 ) ;
V_516 -> V_29 -> V_265 . V_518 = V_518 ;
V_516 -> V_29 -> V_265 . V_256 = V_10 -> V_256 ;
V_516 -> V_29 -> V_265 . V_266 = V_266 ;
F_205 ( & V_516 -> V_29 -> V_265 . V_458 ) ;
}
if ( NULL != V_516 -> V_506 && V_165 -> V_506 != V_516 -> V_506 ) {
if ( V_519 > 1 )
F_64 ( L_75 ,
V_10 -> V_11 . V_61 , V_516 -> V_506 ) ;
V_516 -> V_506 -> V_265 . V_518 = V_518 ;
V_516 -> V_506 -> V_265 . V_256 = V_10 -> V_256 ;
V_516 -> V_506 -> V_265 . V_266 = V_266 ;
F_205 ( & V_516 -> V_506 -> V_265 . V_458 ) ;
}
}
}
static void
F_206 ( struct V_9 * V_10 , struct V_261 * V_516 ,
unsigned int V_266 )
{
struct V_517 V_518 ;
if ( NULL == V_516 )
return;
F_204 ( & V_518 ) ;
V_516 -> V_265 . V_518 = V_518 ;
V_516 -> V_265 . V_256 = V_10 -> V_256 ;
V_516 -> V_265 . V_266 = V_266 ;
F_205 ( & V_516 -> V_265 . V_458 ) ;
}
static void F_207 ( unsigned long V_250 )
{
struct V_9 * V_10 = (struct V_9 * ) V_250 ;
struct V_512 V_263 , V_262 ;
struct V_261 * V_520 ;
struct V_261 * V_514 ;
unsigned long V_162 ;
if ( V_63 ) {
F_25 ( L_76 ,
V_10 -> V_11 . V_61 , V_10 -> V_521 , V_10 -> V_522 , V_10 -> V_523 ,
F_18 ( V_524 ) ) ;
F_195 ( F_18 ( V_170 ) , 0 ) ;
F_191 ( L_77 ) ;
}
F_55 ( & V_10 -> V_164 , V_162 ) ;
memset ( & V_262 , 0 , sizeof( V_262 ) ) ;
V_263 = V_10 -> V_165 ;
V_520 = V_10 -> V_505 ;
V_10 -> V_165 = V_262 ;
V_10 -> V_505 = NULL ;
V_10 -> V_269 = 0 ;
F_208 ( V_10 , & V_262 ) ;
F_209 ( V_10 , NULL ) ;
F_60 ( V_10 , 0 ) ;
F_203 ( V_10 , & V_263 , & V_262 , V_459 ) ;
F_206 ( V_10 , V_520 , V_459 ) ;
while ( ! F_158 ( & V_10 -> V_301 ) ) {
V_514 = F_159 ( V_10 -> V_301 . V_449 , struct V_261 , V_265 . V_300 ) ;
F_210 ( & V_514 -> V_265 . V_300 ) ;
V_514 -> V_265 . V_266 = V_459 ;
F_205 ( & V_514 -> V_265 . V_458 ) ;
}
while ( ! F_158 ( & V_10 -> V_525 ) ) {
V_514 = F_159 ( V_10 -> V_525 . V_449 , struct V_261 , V_265 . V_300 ) ;
F_210 ( & V_514 -> V_265 . V_300 ) ;
V_514 -> V_265 . V_266 = V_459 ;
F_205 ( & V_514 -> V_265 . V_458 ) ;
}
V_10 -> V_212 ++ ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
}
static void
F_211 ( struct V_9 * V_10 )
{
struct V_261 * V_516 = V_10 -> V_165 . V_29 ;
if ( NULL == V_516 )
return;
F_212 ( & V_10 -> V_164 ) ;
V_10 -> V_165 . V_515 = 0 ;
V_10 -> V_165 . V_29 = NULL ;
F_213 ( V_10 , V_511 , NULL , 0 ) ;
F_204 ( & V_516 -> V_265 . V_518 ) ;
V_516 -> V_265 . V_256 = V_10 -> V_256 ;
V_516 -> V_265 . V_266 = V_267 ;
F_205 ( & V_516 -> V_265 . V_458 ) ;
F_214 ( & V_10 -> V_164 ) ;
}
static inline int F_215 ( struct V_500 * V_489 , T_4 V_279 )
{
if ( V_279 < V_489 -> V_504 )
return 0 ;
if ( V_279 > V_489 -> V_504 + V_489 -> V_285 )
return 0 ;
return 1 ;
}
static void
F_216 ( struct V_9 * V_10 )
{
struct V_512 V_262 ;
struct V_512 V_263 ;
T_11 V_279 ;
F_212 ( & V_10 -> V_164 ) ;
F_200 ( V_10 , & V_262 ) ;
V_279 = F_18 ( V_524 ) ;
if ( ( V_10 -> V_165 . V_29 && F_215 ( & V_10 -> V_165 . V_29 -> V_29 , V_279 ) ) ||
( V_10 -> V_165 . V_506 && F_215 ( & V_10 -> V_165 . V_506 -> V_506 , V_279 ) ) ) {
V_10 -> V_521 ++ ;
if ( V_526 )
F_196 ( V_10 , V_279 ) ;
F_214 ( & V_10 -> V_164 ) ;
return;
}
V_263 = V_10 -> V_165 ;
V_10 -> V_165 = V_262 ;
V_10 -> V_269 &= ~ 1 ;
F_208 ( V_10 , & V_262 ) ;
F_60 ( V_10 , 0 ) ;
if ( V_12 != V_10 -> V_167 ) {
F_33 ( V_10 , V_10 -> V_167 ) ;
V_10 -> V_167 = V_12 ;
}
F_203 ( V_10 , & V_263 , & V_262 , V_267 ) ;
F_214 ( & V_10 -> V_164 ) ;
}
static void
F_217 ( struct V_9 * V_10 )
{
struct V_261 * V_262 = NULL ;
struct V_261 * V_263 ;
T_4 V_279 ;
F_212 ( & V_10 -> V_164 ) ;
if ( ! F_158 ( & V_10 -> V_525 ) )
V_262 = F_159 ( V_10 -> V_525 . V_449 , struct V_261 , V_265 . V_300 ) ;
V_263 = V_10 -> V_505 ;
V_279 = F_18 ( V_524 ) ;
if ( NULL != V_263 && ( F_215 ( & V_263 -> V_29 , V_279 ) ||
F_215 ( & V_263 -> V_506 , V_279 ) ) ) {
V_10 -> V_521 ++ ;
if ( V_526 )
F_196 ( V_10 , V_279 ) ;
F_214 ( & V_10 -> V_164 ) ;
return;
}
V_10 -> V_505 = V_262 ;
V_10 -> V_269 &= ~ 4 ;
F_209 ( V_10 , V_262 ) ;
F_60 ( V_10 , 0 ) ;
F_206 ( V_10 , V_263 , V_267 ) ;
F_214 ( & V_10 -> V_164 ) ;
}
static T_12 F_218 ( int V_527 , void * V_528 )
{
T_4 V_529 , V_530 ;
T_4 V_531 ;
int V_295 ;
struct V_9 * V_10 ;
int V_532 = 0 ;
V_10 = (struct V_9 * ) V_528 ;
V_295 = 0 ;
while ( 1 ) {
V_529 = F_18 ( V_170 ) ;
V_530 = V_529 & F_18 ( V_173 ) ;
if ( ! V_530 )
break;
V_532 = 1 ;
F_19 ( V_529 , V_170 ) ;
V_531 = F_18 ( V_65 ) ;
if ( V_519 ) {
F_64 ( L_78 ,
V_10 -> V_11 . V_61 , V_295 , V_10 -> V_256 ,
V_529 >> 28 , F_18 ( V_524 ) ) ;
F_195 ( V_529 , V_530 ) ;
if ( V_529 & V_183 )
F_191 ( L_79 ,
V_531 & V_111
? L_80 : L_81 ) ;
if ( V_529 & V_533 )
F_191 ( L_82 ,
V_531 & V_313
? L_80 : L_81 ) ;
if ( V_529 & V_182 )
F_191 ( L_83 ,
V_531 & V_302
? L_84 : L_85 ) ;
F_191 ( L_77 ) ;
}
if ( V_530 & V_255 )
V_10 -> V_256 ++ ;
if ( ( V_530 & V_176 ) && V_10 -> V_534 ) {
F_219 ( V_10 ) ;
}
if ( V_530 & V_172 ) {
V_10 -> V_535 = V_529 ;
F_205 ( & V_10 -> V_536 ) ;
}
if ( ( V_530 & V_180 ) && ( V_529 & ( 4 << 28 ) ) )
F_217 ( V_10 ) ;
if ( ( V_530 & V_180 ) && ( V_529 & ( 2 << 28 ) ) )
F_211 ( V_10 ) ;
if ( ( V_530 & V_180 ) && ( V_529 & ( 1 << 28 ) ) )
F_216 ( V_10 ) ;
if ( ( V_530 & V_183 ) && V_10 -> V_113 )
F_46 ( V_10 , V_10 -> V_106 ) ;
if ( V_530 & ( V_177 | V_181 ) ) {
F_25 ( L_86 ,
V_10 -> V_11 . V_61 ,
( V_530 & V_177 ) ? L_87 : L_88 ,
( V_530 & V_181 ) ? L_89 : L_88 ,
F_18 ( V_524 ) ) ;
F_195 ( V_529 , V_530 ) ;
F_191 ( L_77 ) ;
if ( V_537 )
F_194 ( V_10 ) ;
}
if ( V_178 && V_530 & V_179 ) {
F_25 ( L_90 ,
V_10 -> V_11 . V_61 , F_18 ( V_524 ) ) ;
if ( V_537 )
F_194 ( V_10 ) ;
}
V_295 ++ ;
if ( V_295 > 4 ) {
if ( V_295 > 8 || ! ( V_530 & V_176 ) ) {
F_19 ( 0 , V_173 ) ;
F_21 ( L_91 ,
V_10 -> V_11 . V_61 ) ;
} else {
F_21 ( L_92 ,
V_10 -> V_11 . V_61 ) ;
F_19 ( F_18 ( V_173 ) & ( - 1 ^ V_176 ) ,
V_173 ) ;
} ;
F_195 ( V_529 , V_530 ) ;
F_191 ( L_93 ) ;
}
}
V_10 -> V_523 ++ ;
if ( V_532 )
V_10 -> V_522 ++ ;
return F_220 ( V_532 ) ;
}
static struct V_6 * F_221 ( struct V_9 * V_10 ,
const struct V_6 * V_538 ,
const char * V_539 )
{
struct V_6 * V_7 ;
V_7 = F_222 () ;
if ( NULL == V_7 )
return NULL ;
* V_7 = * V_538 ;
V_7 -> V_502 = & V_10 -> V_11 . V_502 ;
V_7 -> V_540 = V_541 ;
V_7 -> V_542 = V_537 ;
F_223 ( V_7 , V_10 ) ;
snprintf ( V_7 -> V_309 , sizeof( V_7 -> V_309 ) , L_94 ,
V_10 -> V_17 , ( V_10 -> V_17 == 848 && V_10 -> V_543 == 0x12 ) ? L_95 : L_88 ,
V_539 , V_98 [ V_10 -> V_11 . type ] . V_309 ) ;
return V_7 ;
}
static void F_224 ( struct V_9 * V_10 )
{
if ( V_10 -> V_395 ) {
if ( F_225 ( V_10 -> V_395 ) )
F_226 ( V_10 -> V_395 ) ;
else
V_541 ( V_10 -> V_395 ) ;
V_10 -> V_395 = NULL ;
}
if ( V_10 -> V_544 ) {
if ( F_225 ( V_10 -> V_544 ) )
F_226 ( V_10 -> V_544 ) ;
else
V_541 ( V_10 -> V_544 ) ;
V_10 -> V_544 = NULL ;
}
if ( V_10 -> V_480 ) {
if ( F_225 ( V_10 -> V_480 ) )
F_226 ( V_10 -> V_480 ) ;
else
V_541 ( V_10 -> V_480 ) ;
V_10 -> V_480 = NULL ;
}
}
static int T_13 F_227 ( struct V_9 * V_10 )
{
if ( V_390 > 0 )
F_198 ( L_96 ) ;
V_10 -> V_395 = F_221 ( V_10 , & V_545 , L_97 ) ;
if ( NULL == V_10 -> V_395 )
goto V_242;
if ( F_228 ( V_10 -> V_395 , V_464 ,
V_546 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_242;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_165 ( V_10 -> V_395 ) ) ;
if ( F_229 ( & V_10 -> V_395 -> V_8 ,
& V_547 ) < 0 ) {
F_21 ( L_99 , V_10 -> V_11 . V_61 ) ;
goto V_242;
}
V_10 -> V_544 = F_221 ( V_10 , & V_545 , L_100 ) ;
if ( NULL == V_10 -> V_544 )
goto V_242;
if ( F_228 ( V_10 -> V_544 , V_465 ,
V_548 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_242;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_165 ( V_10 -> V_544 ) ) ;
if ( ! V_10 -> V_549 )
return 0 ;
V_10 -> V_480 = F_221 ( V_10 , & V_550 , L_101 ) ;
if ( NULL == V_10 -> V_480 )
goto V_242;
if ( F_228 ( V_10 -> V_480 , V_551 ,
V_552 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_242;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_165 ( V_10 -> V_480 ) ) ;
return 0 ;
V_242:
F_224 ( V_10 ) ;
return - 1 ;
}
static void F_230 ( struct V_553 * V_8 )
{
#if F_231 ( V_554 )
unsigned int V_477 ;
F_232 ( V_8 , V_555 , & V_477 ) ;
V_477 = ( V_477 | V_556 ) ;
F_233 ( V_8 , V_555 , V_477 ) ;
#endif
}
static int T_13 F_234 ( struct V_553 * V_8 ,
const struct V_557 * V_558 )
{
int V_485 ;
unsigned char V_559 ;
struct V_9 * V_10 ;
if ( V_560 == V_561 )
return - V_366 ;
F_25 ( L_102 , V_560 ) ;
V_562 [ V_560 ] = V_10 = F_235 ( sizeof( * V_10 ) , V_365 ) ;
if ( V_10 == NULL ) {
F_21 ( L_103 ) ;
return - V_366 ;
}
V_10 -> V_11 . V_61 = V_560 ;
snprintf ( V_10 -> V_11 . V_502 . V_309 , sizeof( V_10 -> V_11 . V_502 . V_309 ) ,
L_104 , V_10 -> V_11 . V_61 ) ;
F_236 ( & V_10 -> V_468 ) ;
F_237 ( & V_10 -> V_164 ) ;
F_237 ( & V_10 -> V_563 ) ;
F_238 ( & V_10 -> V_536 ) ;
F_239 ( & V_10 -> V_11 . V_564 ) ;
F_239 ( & V_10 -> V_301 ) ;
F_239 ( & V_10 -> V_525 ) ;
F_240 ( & V_10 -> V_243 ) ;
F_241 ( & V_10 -> V_565 ) ;
V_10 -> V_565 . V_566 = F_207 ;
V_10 -> V_565 . V_250 = ( unsigned long ) V_10 ;
V_10 -> V_567 = - 1 ;
V_10 -> V_168 = V_12 ;
V_10 -> V_167 = V_12 ;
V_10 -> V_549 = V_568 [ V_10 -> V_11 . V_61 ] ;
V_10 -> V_11 . V_397 = V_8 ;
V_10 -> V_17 = V_8 -> V_1 ;
if ( F_242 ( V_8 ) ) {
F_197 ( L_105 , V_10 -> V_11 . V_61 ) ;
return - V_569 ;
}
if ( F_243 ( V_8 , F_244 ( 32 ) ) ) {
F_197 ( L_106 , V_10 -> V_11 . V_61 ) ;
return - V_569 ;
}
if ( ! F_245 ( F_246 ( V_8 , 0 ) ,
F_247 ( V_8 , 0 ) ,
V_10 -> V_11 . V_502 . V_309 ) ) {
F_197 ( L_107 ,
V_10 -> V_11 . V_61 ,
( unsigned long long ) F_246 ( V_8 , 0 ) ) ;
return - V_351 ;
}
F_248 ( V_8 ) ;
F_230 ( V_8 ) ;
V_485 = F_249 ( & V_8 -> V_8 , & V_10 -> V_11 . V_502 ) ;
if ( V_485 < 0 ) {
F_197 ( L_108 , V_10 -> V_11 . V_61 ) ;
goto V_570;
}
V_10 -> V_543 = V_8 -> V_543 ;
F_250 ( V_8 , V_571 , & V_559 ) ;
F_25 ( L_109 ,
V_560 , V_10 -> V_17 , V_10 -> V_543 , F_121 ( V_8 ) ,
V_10 -> V_11 . V_397 -> V_527 , V_559 ,
( unsigned long long ) F_246 ( V_8 , 0 ) ) ;
F_251 () ;
V_10 -> V_572 = F_252 ( F_246 ( V_8 , 0 ) , 0x1000 ) ;
if ( NULL == V_10 -> V_572 ) {
F_21 ( L_110 , V_10 -> V_11 . V_61 ) ;
V_485 = - V_569 ;
goto V_573;
}
F_253 ( V_10 ) ;
F_19 ( 0 , V_173 ) ;
V_485 = F_254 ( V_10 -> V_11 . V_397 -> V_527 , F_218 ,
V_574 | V_575 , V_10 -> V_11 . V_502 . V_309 , ( void * ) V_10 ) ;
if ( V_485 < 0 ) {
F_21 ( L_111 ,
V_560 , V_10 -> V_11 . V_397 -> V_527 ) ;
goto V_573;
}
if ( 0 != F_255 ( V_10 ) ) {
V_485 = - V_569 ;
goto V_576;
}
V_10 -> V_226 = V_577 ;
V_10 -> V_210 = V_578 ;
V_10 -> V_113 = V_579 ;
V_10 -> V_196 = V_580 ;
V_10 -> V_203 = V_581 ;
V_10 -> V_231 = V_582 ;
V_10 -> V_233 = V_206 ;
V_10 -> V_235 = V_208 ;
V_10 -> V_93 = V_583 ;
V_10 -> V_238 = V_584 ;
V_10 -> V_240 = V_585 ;
V_10 -> V_372 . V_10 = V_10 ;
V_10 -> V_372 . V_369 . V_354 . V_144 = 320 ;
V_10 -> V_372 . V_369 . V_354 . V_43 = 240 ;
V_10 -> V_372 . V_274 = F_66 ( V_586 ) ;
V_10 -> V_372 . V_144 = 320 ;
V_10 -> V_372 . V_43 = 240 ;
V_10 -> V_72 = 0 ;
if ( V_119 )
F_41 ( V_10 , L_112 ) ;
F_256 ( V_10 ) ;
F_58 ( V_10 ) ;
F_19 ( 0x00 , V_587 ) ;
F_19 ( 0x00 , V_251 ) ;
if ( V_63 )
F_41 ( V_10 , L_113 ) ;
F_257 ( V_10 ) ;
F_258 ( V_10 ) ;
F_259 ( V_10 ) ;
F_260 ( V_10 ) ;
F_57 ( V_10 ) ;
if ( ! V_98 [ V_10 -> V_11 . type ] . V_171 ) {
F_227 ( V_10 ) ;
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
if ( V_98 [ V_10 -> V_11 . type ] . V_588 ) {
F_261 ( & V_10 -> V_11 , L_114 ) ;
F_6 ( V_10 ) ;
}
if ( ! V_589 ) {
F_262 ( V_10 ) ;
F_263 ( V_10 ) ;
}
V_560 ++ ;
return 0 ;
V_576:
F_264 ( V_10 -> V_11 . V_397 -> V_527 , V_10 ) ;
V_573:
F_265 ( & V_10 -> V_11 . V_502 ) ;
V_570:
if ( V_10 -> V_572 )
F_266 ( V_10 -> V_572 ) ;
F_267 ( F_246 ( V_10 -> V_11 . V_397 , 0 ) ,
F_247 ( V_10 -> V_11 . V_397 , 0 ) ) ;
return V_485 ;
}
static void T_14 F_268 ( struct V_553 * V_553 )
{
struct V_590 * V_502 = F_269 ( V_553 ) ;
struct V_9 * V_10 = F_270 ( V_502 ) ;
if ( V_63 )
F_25 ( L_115 , V_10 -> V_11 . V_61 ) ;
if ( V_98 [ V_10 -> V_11 . type ] . V_588 )
F_9 ( V_10 ) ;
F_36 ( ~ 15 , V_195 ) ;
F_19 ( 0 , V_173 ) ;
F_19 ( ~ 0x0 , V_170 ) ;
F_19 ( 0x0 , V_251 ) ;
if ( V_119 )
F_41 ( V_10 , L_116 ) ;
V_10 -> V_591 = 1 ;
F_271 ( V_10 ) ;
F_272 ( & V_10 -> V_11 ) ;
F_273 ( V_10 ) ;
F_224 ( V_10 ) ;
F_274 ( V_10 -> V_11 . V_397 , & V_10 -> main ) ;
F_264 ( V_10 -> V_11 . V_397 -> V_527 , V_10 ) ;
F_266 ( V_10 -> V_572 ) ;
F_267 ( F_246 ( V_10 -> V_11 . V_397 , 0 ) ,
F_247 ( V_10 -> V_11 . V_397 , 0 ) ) ;
F_265 ( & V_10 -> V_11 . V_502 ) ;
V_562 [ V_10 -> V_11 . V_61 ] = NULL ;
F_69 ( V_10 ) ;
return;
}
static int F_275 ( struct V_553 * V_553 , T_15 V_266 )
{
struct V_590 * V_502 = F_269 ( V_553 ) ;
struct V_9 * V_10 = F_270 ( V_502 ) ;
struct V_512 V_592 ;
unsigned long V_162 ;
F_24 ( L_117 , V_10 -> V_11 . V_61 , V_266 . V_593 ) ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
memset ( & V_592 , 0 , sizeof( V_592 ) ) ;
V_10 -> V_266 . V_594 = V_10 -> V_165 ;
V_10 -> V_266 . V_375 = V_10 -> V_505 ;
V_10 -> V_266 . V_269 = V_10 -> V_269 ;
V_10 -> V_165 = V_592 ;
V_10 -> V_269 = 0 ;
F_208 ( V_10 , & V_592 ) ;
F_209 ( V_10 , NULL ) ;
F_60 ( V_10 , 0 ) ;
F_19 ( 0 , V_173 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
V_10 -> V_266 . V_595 = F_18 ( V_251 ) ;
V_10 -> V_266 . V_596 = F_53 () ;
F_276 ( V_553 ) ;
if ( 0 != F_277 ( V_553 , F_278 ( V_553 , V_266 ) ) ) {
F_279 ( V_553 ) ;
V_10 -> V_266 . V_597 = 1 ;
}
return 0 ;
}
static int F_280 ( struct V_553 * V_553 )
{
struct V_590 * V_502 = F_269 ( V_553 ) ;
struct V_9 * V_10 = F_270 ( V_502 ) ;
unsigned long V_162 ;
int V_242 ;
F_24 ( L_118 , V_10 -> V_11 . V_61 ) ;
if ( V_10 -> V_266 . V_597 ) {
V_242 = F_242 ( V_553 ) ;
if ( V_242 ) {
F_197 ( L_105 , V_10 -> V_11 . V_61 ) ;
return V_242 ;
}
V_10 -> V_266 . V_597 = 0 ;
}
V_242 = F_277 ( V_553 , V_598 ) ;
if ( V_242 ) {
F_279 ( V_553 ) ;
F_197 ( L_105 , V_10 -> V_11 . V_61 ) ;
V_10 -> V_266 . V_597 = 1 ;
return V_242 ;
}
F_281 ( V_553 ) ;
F_59 ( V_10 ) ;
F_34 ( 0xffffff , V_10 -> V_266 . V_595 ) ;
F_282 ( V_10 -> V_266 . V_596 ) ;
F_55 ( & V_10 -> V_164 , V_162 ) ;
V_10 -> V_165 = V_10 -> V_266 . V_594 ;
V_10 -> V_505 = V_10 -> V_266 . V_375 ;
V_10 -> V_269 = V_10 -> V_266 . V_269 ;
F_208 ( V_10 , & V_10 -> V_165 ) ;
F_209 ( V_10 , V_10 -> V_505 ) ;
F_60 ( V_10 , 0 ) ;
F_56 ( & V_10 -> V_164 , V_162 ) ;
return 0 ;
}
static int T_16 F_283 ( void )
{
int V_599 ;
V_560 = 0 ;
F_25 ( L_119 , V_600 ) ;
if ( V_296 < 2 || V_296 > V_601 )
V_296 = 2 ;
if ( V_297 > V_602 )
V_297 = V_602 ;
V_297 = ( V_297 + V_603 - 1 ) & V_604 ;
if ( V_63 )
F_25 ( L_120 ,
V_296 , V_297 >> 10 , V_297 >> V_605 ) ;
F_284 () ;
V_599 = F_285 ( & V_606 ) ;
if ( V_599 < 0 ) {
F_197 ( L_121 , V_599 ) ;
return V_599 ;
}
V_599 = F_286 ( & V_607 ) ;
if ( V_599 < 0 )
F_287 ( & V_606 ) ;
return V_599 ;
}
static void T_17 F_288 ( void )
{
F_289 ( & V_607 ) ;
F_287 ( & V_606 ) ;
}
