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
V_125 = F_44 ( V_127 , V_128 ,
V_129 , V_129 ) ;
break;
case V_130 :
V_125 = F_44 ( V_131 , V_128 ,
V_129 , V_129 ) ;
break;
case V_132 :
V_125 = F_44 ( V_127 , V_128 ,
V_129 , V_129 ) ;
break;
case V_133 :
default:
if ( V_10 -> V_11 . type == V_118 )
V_125 = F_44 ( V_131 , V_134 , \
V_135 , V_135 ) ;
else
V_125 = V_136 ;
break;
}
F_45 ( V_10 -> V_124 , V_112 , V_137 ,
V_125 , V_138 , 0 ) ;
}
if ( V_10 -> V_139 ) {
F_45 ( V_10 -> V_139 , V_112 , V_137 ,
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
F_48 ( struct V_140 * V_11 )
{
if ( 1 ) {
V_11 -> V_141 = 48 ;
V_11 -> V_142 = 32 ;
} else {
V_11 -> V_141 =
( F_49 ( 48 , V_11 -> V_32 . V_143 >> 4 ) + 3 ) & ~ 3 ;
V_11 -> V_142 =
F_49 ( 32 , V_11 -> V_32 . V_43 >> 4 ) ;
}
V_11 -> V_144 = V_11 -> V_32 . V_143 & ~ 3 ;
V_11 -> V_145 = V_11 -> V_32 . V_43 ;
}
static void
F_50 ( struct V_140 * V_11 , unsigned int V_146 )
{
V_11 -> V_32 = V_40 [ V_146 ] . V_41 . V_147 ;
F_48 ( V_11 ) ;
}
static int
F_51 ( struct V_9 * V_10 , unsigned int V_146 )
{
const struct V_38 * V_39 ;
T_5 V_17 ;
F_52 ( V_146 >= V_148 ) ;
F_52 ( V_10 -> V_39 >= V_148 ) ;
V_39 = & V_40 [ V_146 ] ;
if ( memcmp ( & V_40 [ V_10 -> V_39 ] . V_41 , & V_39 -> V_41 ,
sizeof ( V_39 -> V_41 ) ) ) {
F_50 ( & V_10 -> V_30 [ 0 ] , V_146 ) ;
V_10 -> V_30 [ 1 ] = V_10 -> V_30 [ 0 ] ;
if ( 0 == ( V_10 -> V_24 & V_28 ) ) {
V_10 -> V_34 = V_39 -> V_41 . V_42 . V_29
+ V_39 -> V_41 . V_42 . V_43 ;
}
}
V_10 -> V_39 = V_146 ;
F_19 ( V_39 -> V_149 , V_150 ) ;
F_19 ( V_39 -> V_151 , V_152 ) ;
F_31 ( V_39 -> V_153 , ~ ( V_154 | V_155 ) ,
V_104 ) ;
F_19 ( V_39 -> V_156 , V_157 ) ;
F_19 ( 1 , V_158 ) ;
F_27 ( V_10 ) ;
switch ( V_10 -> V_11 . type ) {
case V_117 :
case V_118 :
F_39 ( V_10 , F_53 () ) ;
break;
}
V_17 = V_39 -> V_159 ;
F_43 ( V_10 , V_122 , V_160 , V_17 ) ;
return 0 ;
}
static void
F_54 ( struct V_9 * V_10 , unsigned int V_72 , unsigned int V_146 )
{
unsigned long V_161 ;
V_10 -> V_72 = V_72 ;
if ( V_162 ) {
F_55 ( & V_10 -> V_163 , V_161 ) ;
if ( V_10 -> V_164 . V_165 ) {
V_10 -> V_166 = V_72 ;
} else {
F_33 ( V_10 , V_72 ) ;
}
F_56 ( & V_10 -> V_163 , V_161 ) ;
} else {
F_33 ( V_10 , V_72 ) ;
}
F_47 ( V_10 , ( V_10 -> V_167 != V_168 && V_72 == 0 ) ?
V_133 : V_130 ) ;
F_51 ( V_10 , V_146 ) ;
}
static void F_57 ( struct V_9 * V_10 )
{
F_19 ( 0xfffffUL , V_169 ) ;
if ( V_98 [ V_10 -> V_11 . type ] . V_170 ) {
F_19 ( V_171 ,
V_172 ) ;
} else {
F_19 ( ( V_10 -> V_173 ) |
( V_10 -> V_174 ? V_175 : 0 ) |
V_176 |
( V_177 ? V_178 : 0 ) |
V_179 | V_180 |
V_181 | V_182 |
V_171 ,
V_172 ) ;
}
}
static void F_58 ( struct V_9 * V_10 )
{
int V_183 ;
if ( V_98 [ V_10 -> V_11 . type ] . V_170 ) {
F_57 ( V_10 ) ;
return;
}
F_19 ( 0x00 , V_184 ) ;
F_19 ( V_185 , V_186 ) ;
F_19 ( V_187 | V_188 , V_104 ) ;
F_19 ( V_189 |
V_190 |
V_191 |
V_192 |
V_193 ,
V_194 ) ;
V_183 = V_10 -> V_195 ? V_196 : 0 ;
F_19 ( V_183 , V_197 ) ;
F_19 ( V_183 , V_198 ) ;
F_19 ( 0x20 , V_199 ) ;
F_19 ( 0x20 , V_200 ) ;
F_19 ( V_201 | ( V_10 -> V_202 ? V_203 : 0 ) ,
V_204 ) ;
F_19 ( V_205 , V_206 ) ;
F_19 ( V_207 , V_208 ) ;
if ( V_10 -> V_209 ) {
F_19 ( 0 , V_86 ) ;
F_19 ( 0 , V_87 ) ;
} else {
F_19 ( V_210 , V_86 ) ;
F_19 ( V_210 , V_87 ) ;
}
F_28 ( V_10 , V_10 -> V_77 ) ;
F_29 ( V_10 , V_10 -> V_80 ) ;
F_30 ( V_10 , V_10 -> V_84 ) ;
F_32 ( V_10 , V_10 -> V_92 ) ;
F_57 ( V_10 ) ;
}
static void F_59 ( struct V_9 * V_10 )
{
unsigned long V_161 ;
if ( V_63 )
F_25 ( L_11 , V_10 -> V_11 . V_61 ) ;
F_55 ( & V_10 -> V_163 , V_161 ) ;
V_10 -> V_211 = 0 ;
F_60 ( V_10 , 0 ) ;
F_56 ( & V_10 -> V_163 , V_161 ) ;
F_58 ( V_10 ) ;
V_10 -> V_57 . V_60 = - 1 ;
F_54 ( V_10 , V_10 -> V_72 , V_10 -> V_39 ) ;
}
static int F_61 ( struct V_212 * V_212 , void * V_213 ,
struct V_108 * V_11 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
switch ( V_11 -> V_17 ) {
case V_214 :
V_11 -> V_78 = V_10 -> V_77 ;
break;
case V_215 :
V_11 -> V_78 = V_10 -> V_80 ;
break;
case V_216 :
V_11 -> V_78 = V_10 -> V_84 ;
break;
case V_217 :
V_11 -> V_78 = V_10 -> V_92 ;
break;
case V_121 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
F_43 ( V_10 , V_122 , V_222 , V_11 ) ;
break;
case V_223 :
V_11 -> V_78 = V_10 -> V_195 ;
break;
case V_224 :
V_11 -> V_78 = V_10 -> V_225 ;
break;
case V_226 :
V_11 -> V_78 = V_10 -> V_209 ;
break;
case V_227 :
V_11 -> V_78 = V_10 -> V_113 ;
break;
case V_228 :
V_11 -> V_78 = V_10 -> V_202 ;
break;
case V_229 :
V_11 -> V_78 = V_10 -> V_230 ;
break;
case V_231 :
V_11 -> V_78 = V_10 -> V_232 ;
break;
case V_233 :
V_11 -> V_78 = V_10 -> V_234 ;
break;
case V_235 :
V_11 -> V_78 = V_10 -> V_93 ;
break;
case V_236 :
V_11 -> V_78 = V_10 -> V_237 ;
break;
case V_238 :
V_11 -> V_78 = V_10 -> V_239 ;
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_62 ( struct V_212 * V_212 , void * V_240 ,
struct V_108 * V_11 )
{
int V_241 ;
int V_183 ;
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_241 = F_63 ( & V_10 -> V_242 , V_21 -> V_242 ) ;
if ( 0 != V_241 )
return V_241 ;
switch ( V_11 -> V_17 ) {
case V_214 :
F_28 ( V_10 , V_11 -> V_78 ) ;
break;
case V_215 :
F_29 ( V_10 , V_11 -> V_78 ) ;
break;
case V_216 :
F_30 ( V_10 , V_11 -> V_78 ) ;
break;
case V_217 :
F_32 ( V_10 , V_11 -> V_78 ) ;
break;
case V_121 :
F_46 ( V_10 , V_11 -> V_78 ) ;
case V_218 :
if ( V_10 -> V_243 )
V_10 -> V_243 ( V_10 , V_11 -> V_78 ) ;
F_43 ( V_10 , V_122 , V_123 , V_11 ) ;
break;
case V_219 :
case V_220 :
case V_221 :
F_43 ( V_10 , V_122 , V_123 , V_11 ) ;
break;
case V_223 :
V_10 -> V_195 = V_11 -> V_78 ;
V_183 = V_10 -> V_195 ? V_196 : 0 ;
F_19 ( V_183 , V_197 ) ;
F_19 ( V_183 , V_198 ) ;
break;
case V_224 :
V_10 -> V_225 = V_11 -> V_78 ;
break;
case V_226 :
V_10 -> V_209 = V_11 -> V_78 ;
if ( V_10 -> V_209 ) {
F_36 ( ~ V_210 , V_86 ) ;
F_36 ( ~ V_210 , V_87 ) ;
} else {
F_35 ( V_210 , V_86 ) ;
F_35 ( V_210 , V_87 ) ;
}
break;
case V_227 :
V_10 -> V_113 = V_11 -> V_78 ;
break;
case V_228 :
V_10 -> V_202 = V_11 -> V_78 ;
F_19 ( V_201 |
( V_10 -> V_202 ? V_203 : 0 ) ,
V_204 ) ;
break;
case V_229 :
V_10 -> V_230 = V_11 -> V_78 ;
break;
case V_231 :
V_10 -> V_232 = V_11 -> V_78 ;
F_19 ( V_11 -> V_78 , V_206 ) ;
break;
case V_233 :
V_10 -> V_234 = V_11 -> V_78 ;
F_19 ( V_11 -> V_78 , V_208 ) ;
break;
case V_235 :
V_10 -> V_93 = V_11 -> V_78 ;
F_32 ( V_10 , V_10 -> V_92 ) ;
break;
case V_236 :
V_10 -> V_237 = V_11 -> V_78 ;
F_31 ( ( V_11 -> V_78 << 7 ) , ~ V_244 , V_245 ) ;
break;
case V_238 :
V_10 -> V_239 = V_11 -> V_78 ;
F_31 ( ( V_11 -> V_78 << 5 ) , ~ V_246 , V_245 ) ;
break;
default:
return - V_100 ;
}
return 0 ;
}
void F_41 ( struct V_9 * V_10 , char * V_247 )
{
unsigned int V_248 , V_249 ;
V_248 = F_18 ( V_250 ) ;
V_249 = F_18 ( V_251 ) ;
F_64 ( L_12 ,
V_10 -> V_11 . V_61 , V_248 , V_249 & V_248 , V_249 & ~ V_248 , V_247 ) ;
}
static void F_65 ( struct V_9 * V_10 )
{
int V_252 = 0 ;
if ( V_10 -> V_253 )
V_252 ++ ;
if ( V_252 ) {
F_35 ( V_254 , V_172 ) ;
} else {
F_36 ( ~ V_254 , V_172 ) ;
V_10 -> V_255 = 0 ;
}
}
static const struct V_256 *
F_66 ( int V_257 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_258 ; V_18 ++ ) {
if ( - 1 == V_259 [ V_18 ] . V_257 )
continue;
if ( V_259 [ V_18 ] . V_257 == V_257 )
return V_259 + V_18 ;
}
return NULL ;
}
static int
F_67 ( struct V_9 * V_10 , struct V_20 * V_21 ,
struct V_260 * V_261 )
{
struct V_260 * V_262 ;
unsigned long V_161 ;
int V_263 = 0 ;
F_24 ( L_13 , V_261 ) ;
if ( V_261 )
V_261 -> V_264 . V_265 = V_266 ;
F_55 ( & V_10 -> V_163 , V_161 ) ;
V_262 = V_10 -> V_267 ;
V_10 -> V_267 = V_261 ;
V_10 -> V_268 |= 1 ;
F_60 ( V_10 , 0x03 ) ;
F_56 ( & V_10 -> V_163 , V_161 ) ;
if ( NULL != V_262 ) {
F_24 ( L_14 ,
V_262 , V_262 -> V_264 . V_265 ) ;
F_68 ( & V_21 -> V_269 , V_10 , V_262 ) ;
F_69 ( V_262 ) ;
}
if ( NULL == V_261 )
F_20 ( V_10 , V_21 , V_270 ) ;
F_24 ( L_15 ) ;
return V_263 ;
}
static int F_70 ( struct V_271 * V_272 , struct V_9 * V_10 ,
struct V_260 * V_5 ,
const struct V_256 * V_273 ,
unsigned int V_143 , unsigned int V_43 ,
enum V_274 V_275 )
{
struct V_20 * V_21 = V_272 -> V_276 ;
int V_277 = 0 ;
struct V_140 V_11 ;
int V_146 ;
int V_278 ;
if ( NULL == V_273 )
return - V_100 ;
if ( V_273 -> V_279 == V_280 ) {
V_143 = V_281 ;
V_43 = V_282 * 2 ;
if ( V_143 * V_43 > V_5 -> V_264 . V_283 )
return - V_100 ;
V_5 -> V_264 . V_284 = V_5 -> V_264 . V_283 ;
V_146 = V_10 -> V_39 ;
if ( V_10 -> V_33 > V_40 [ V_146 ] . V_41 . V_147 . V_29 ) {
return - V_100 ;
}
V_11 . V_32 = V_40 [ V_146 ] . V_41 . V_147 ;
} else {
V_146 = V_10 -> V_39 ;
V_11 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] ;
if ( V_143 < V_11 . V_141 ||
V_143 > V_11 . V_144 ||
V_43 < V_11 . V_142 )
return - V_100 ;
switch ( V_275 ) {
case V_285 :
case V_286 :
case V_287 :
if ( V_43 * 2 > V_11 . V_145 )
return - V_100 ;
break;
default:
if ( V_43 > V_11 . V_145 )
return - V_100 ;
break;
}
V_5 -> V_264 . V_284 = ( V_143 * V_43 * V_273 -> V_288 ) >> 3 ;
if ( 0 != V_5 -> V_264 . V_289 && V_5 -> V_264 . V_283 < V_5 -> V_264 . V_284 )
return - V_100 ;
}
if ( V_5 -> V_264 . V_143 != V_143 || V_5 -> V_264 . V_43 != V_43 ||
V_5 -> V_264 . V_275 != V_275 ||
V_5 -> V_39 != V_146 || V_5 -> V_273 != V_273 ||
V_5 -> V_30 . V_29 != V_11 . V_32 . V_29 ||
V_5 -> V_30 . V_290 != V_11 . V_32 . V_290 ||
V_5 -> V_30 . V_143 != V_11 . V_32 . V_143 ||
V_5 -> V_30 . V_43 != V_11 . V_32 . V_43 ) {
V_5 -> V_264 . V_143 = V_143 ;
V_5 -> V_264 . V_43 = V_43 ;
V_5 -> V_264 . V_275 = V_275 ;
V_5 -> V_39 = V_146 ;
V_5 -> V_273 = V_273 ;
V_5 -> V_30 = V_11 . V_32 ;
V_277 = 1 ;
}
if ( V_291 == V_5 -> V_264 . V_265 ) {
V_277 = 1 ;
if ( 0 != ( V_278 = F_71 ( V_272 , & V_5 -> V_264 , & V_10 -> V_292 ) ) )
goto V_27;
}
if ( V_277 )
if ( 0 != ( V_278 = F_72 ( V_10 , V_5 ) ) )
goto V_27;
V_5 -> V_264 . V_265 = V_293 ;
return 0 ;
V_27:
F_68 ( V_272 , V_10 , V_5 ) ;
return V_278 ;
}
static int
F_73 ( struct V_271 * V_272 , unsigned int * V_294 , unsigned int * V_284 )
{
struct V_20 * V_21 = V_272 -> V_276 ;
* V_284 = V_21 -> V_273 -> V_288 * V_21 -> V_143 * V_21 -> V_43 >> 3 ;
if ( 0 == * V_294 )
* V_294 = V_295 ;
if ( * V_284 * * V_294 > V_295 * V_296 )
* V_294 = ( V_295 * V_296 ) / * V_284 ;
return 0 ;
}
static int
F_74 ( struct V_271 * V_272 , struct V_297 * V_264 ,
enum V_274 V_275 )
{
struct V_260 * V_5 = F_2 ( V_264 , struct V_260 , V_264 ) ;
struct V_20 * V_21 = V_272 -> V_276 ;
return F_70 ( V_272 , V_21 -> V_10 , V_5 , V_21 -> V_273 ,
V_21 -> V_143 , V_21 -> V_43 , V_275 ) ;
}
static void
F_75 ( struct V_271 * V_272 , struct V_297 * V_264 )
{
struct V_260 * V_5 = F_2 ( V_264 , struct V_260 , V_264 ) ;
struct V_20 * V_21 = V_272 -> V_276 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_5 -> V_264 . V_265 = V_298 ;
F_76 ( & V_5 -> V_264 . V_299 , & V_10 -> V_300 ) ;
if ( ! V_10 -> V_164 . V_165 ) {
V_10 -> V_268 |= 1 ;
F_60 ( V_10 , 0x03 ) ;
}
}
static void F_77 ( struct V_271 * V_272 , struct V_297 * V_264 )
{
struct V_260 * V_5 = F_2 ( V_264 , struct V_260 , V_264 ) ;
struct V_20 * V_21 = V_272 -> V_276 ;
F_68 ( V_272 , V_21 -> V_10 , V_5 ) ;
}
static int F_78 ( struct V_212 * V_212 , void * V_213 , T_5 * V_17 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
unsigned int V_18 ;
int V_241 ;
V_241 = F_63 ( & V_10 -> V_242 , V_21 -> V_242 ) ;
if ( V_241 )
goto V_241;
for ( V_18 = 0 ; V_18 < V_148 ; V_18 ++ )
if ( * V_17 & V_40 [ V_18 ] . V_159 )
break;
if ( V_18 == V_148 ) {
V_241 = - V_100 ;
goto V_241;
}
F_51 ( V_10 , V_18 ) ;
V_241:
return V_241 ;
}
static int F_79 ( struct V_212 * V_212 , void * V_240 , T_5 * V_17 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( F_18 ( V_65 ) & V_301 )
* V_17 = V_302 ;
else
* V_17 = V_303 ;
return 0 ;
}
static int F_80 ( struct V_212 * V_212 , void * V_213 ,
struct V_304 * V_18 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_278 = 0 ;
if ( V_18 -> V_305 >= V_98 [ V_10 -> V_11 . type ] . V_99 ) {
V_278 = - V_100 ;
goto V_241;
}
V_18 -> type = V_306 ;
V_18 -> V_307 = 1 ;
if ( V_10 -> V_167 != V_168 && V_18 -> V_305 == 0 ) {
sprintf ( V_18 -> V_308 , L_16 ) ;
V_18 -> type = V_309 ;
V_18 -> V_310 = 0 ;
} else if ( V_18 -> V_305 == V_10 -> V_102 ) {
sprintf ( V_18 -> V_308 , L_17 ) ;
} else {
sprintf ( V_18 -> V_308 , L_18 , V_18 -> V_305 ) ;
}
if ( V_18 -> V_305 == V_10 -> V_72 ) {
T_6 V_311 = F_18 ( V_65 ) ;
if ( 0 == ( V_311 & V_312 ) )
V_18 -> V_313 |= V_314 ;
if ( 0 == ( V_311 & V_111 ) )
V_18 -> V_313 |= V_315 ;
}
V_18 -> V_316 = V_317 ;
V_241:
return V_278 ;
}
static int F_81 ( struct V_212 * V_212 , void * V_213 , unsigned int * V_18 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_18 = V_10 -> V_72 ;
return 0 ;
}
static int F_82 ( struct V_212 * V_212 , void * V_213 , unsigned int V_18 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_241 ;
V_241 = F_63 ( & V_10 -> V_242 , V_21 -> V_242 ) ;
if ( F_83 ( V_241 ) )
goto V_241;
if ( V_18 > V_98 [ V_10 -> V_11 . type ] . V_99 ) {
V_241 = - V_100 ;
goto V_241;
}
F_54 ( V_10 , V_18 , V_10 -> V_39 ) ;
V_241:
return 0 ;
}
static int F_84 ( struct V_212 * V_212 , void * V_213 ,
struct V_318 * V_319 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_241 ;
if ( F_83 ( 0 != V_319 -> V_305 ) )
return - V_100 ;
if ( F_83 ( V_10 -> V_167 == V_168 ) ) {
V_241 = - V_100 ;
goto V_241;
}
V_241 = F_63 ( & V_10 -> V_242 , V_21 -> V_242 ) ;
if ( F_83 ( V_241 ) )
goto V_241;
F_43 ( V_10 , V_310 , V_320 , V_319 ) ;
if ( V_10 -> V_321 )
V_10 -> V_321 ( V_10 , V_319 , 1 ) ;
V_241:
return 0 ;
}
static int F_85 ( struct V_212 * V_212 , void * V_213 ,
struct V_322 * V_240 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
V_240 -> type = V_10 -> V_114 ? V_323 : V_324 ;
V_240 -> V_325 = V_10 -> V_326 ;
return 0 ;
}
static int F_86 ( struct V_212 * V_212 , void * V_213 ,
struct V_322 * V_240 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_241 ;
if ( F_83 ( V_240 -> V_310 != 0 ) )
return - V_100 ;
V_241 = F_63 ( & V_10 -> V_242 , V_21 -> V_242 ) ;
if ( F_83 ( V_241 ) )
goto V_241;
if ( F_83 ( V_240 -> type != ( V_10 -> V_114
? V_323 : V_324 ) ) ) {
V_241 = - V_100 ;
goto V_241;
}
V_10 -> V_326 = V_240 -> V_325 ;
F_43 ( V_10 , V_310 , V_327 , V_240 ) ;
if ( V_10 -> V_328 && V_10 -> V_114 )
F_87 ( V_10 , V_10 -> V_326 ) ;
V_241:
return 0 ;
}
static int F_88 ( struct V_212 * V_212 , void * V_240 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
F_43 ( V_10 , V_122 , V_329 ) ;
return 0 ;
}
static int F_89 ( struct V_212 * V_212 , void * V_240 ,
struct V_330 * V_331 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( ! F_90 ( V_332 ) )
return - V_333 ;
if ( ! F_91 ( & V_331 -> V_334 ) )
return - V_100 ;
V_331 -> V_331 &= 0xfff ;
V_331 -> V_183 = F_18 ( V_331 -> V_331 ) ;
V_331 -> V_284 = 1 ;
return 0 ;
}
static int F_92 ( struct V_212 * V_212 , void * V_240 ,
struct V_330 * V_331 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( ! F_90 ( V_332 ) )
return - V_333 ;
if ( ! F_91 ( & V_331 -> V_334 ) )
return - V_100 ;
V_331 -> V_331 &= 0xfff ;
F_19 ( V_331 -> V_183 , V_331 -> V_331 ) ;
return 0 ;
}
static void
F_93 ( struct V_140 * V_11 ,
const struct V_335 * V_336 ,
T_2 V_143 ,
T_2 V_43 ,
enum V_274 V_275 )
{
T_2 V_337 = V_43 << ! F_94 ( V_275 ) ;
T_2 V_338 ;
T_2 V_339 ;
if ( V_143 < V_11 -> V_141 ) {
V_11 -> V_32 . V_143 = V_143 * 16 ;
} else if ( V_143 > V_11 -> V_144 ) {
V_11 -> V_32 . V_143 = V_143 ;
V_338 = V_336 -> V_290 + V_336 -> V_143 - V_143 ;
V_338 = F_95 ( V_338 , ( T_2 ) V_340 ) ;
if ( V_11 -> V_32 . V_290 > V_338 )
V_11 -> V_32 . V_290 = V_338 ;
}
if ( V_43 < V_11 -> V_142 ) {
V_11 -> V_32 . V_43 = V_43 * 16 ;
} else if ( V_337 > V_11 -> V_145 ) {
V_11 -> V_32 . V_43 = ( V_337 + 1 ) & ~ 1 ;
V_339 = V_336 -> V_29 + V_336 -> V_43 - V_11 -> V_32 . V_43 ;
if ( V_11 -> V_32 . V_29 > V_339 )
V_11 -> V_32 . V_29 = V_339 ;
}
F_48 ( V_11 ) ;
}
static int
F_96 ( struct V_20 * V_21 ,
T_2 * V_143 ,
T_2 * V_43 ,
enum V_274 V_275 ,
unsigned int V_341 ,
unsigned int V_342 ,
int V_343 ,
int V_344 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_335 * V_336 ;
struct V_140 * V_11 ;
T_2 V_345 ;
T_2 V_346 ;
T_2 V_347 ;
T_2 V_348 ;
int V_278 ;
F_52 ( ( int ) V_341 >= 0 ||
V_342 >= ( unsigned int ) - V_341 ) ;
V_336 = & V_40 [ V_10 -> V_39 ] . V_41 . V_42 ;
V_11 = & V_10 -> V_30 [ ! ! V_21 -> V_31 ] ;
if ( V_21 -> V_31
&& V_343
&& V_344
&& ! F_15 ( V_10 , V_28 ) ) {
V_345 = 48 ;
V_346 = 32 ;
V_347 = F_95 ( V_336 -> V_143 , ( T_2 ) V_349 ) ;
V_348 = V_336 -> V_43 ;
if ( V_10 -> V_33 > V_336 -> V_29 ) {
V_348 -= V_10 -> V_33 - V_336 -> V_29 ;
V_278 = - V_350 ;
if ( V_346 > V_348 )
goto V_27;
}
} else {
V_278 = - V_350 ;
if ( V_10 -> V_33 > V_11 -> V_32 . V_29 )
goto V_27;
V_345 = V_11 -> V_141 ;
V_346 = V_11 -> V_142 ;
V_347 = V_11 -> V_144 ;
V_348 = V_11 -> V_145 ;
V_344 = 0 ;
}
V_345 = ( V_345 - V_341 - 1 ) & V_341 ;
V_347 = V_347 & V_341 ;
V_346 = V_346 ;
V_348 >>= ! F_94 ( V_275 ) ;
if ( V_343 ) {
* V_143 = F_97 ( * V_143 , V_345 , V_347 ) ;
* V_43 = F_97 ( * V_43 , V_346 , V_348 ) ;
* V_143 = ( * V_143 + V_342 ) & V_341 ;
if ( V_344 ) {
F_93 ( V_11 , V_336 , * V_143 , * V_43 , V_275 ) ;
if ( V_10 -> V_33 > V_11 -> V_32 . V_29 ) {
V_11 -> V_32 . V_29 = V_10 -> V_33 ;
}
}
} else {
V_278 = - V_100 ;
if ( * V_143 < V_345 ||
* V_43 < V_346 ||
* V_143 > V_347 ||
* V_43 > V_348 ||
0 != ( * V_143 & ~ V_341 ) )
goto V_27;
}
V_278 = 0 ;
V_27:
return V_278 ;
}
static int
F_98 ( struct V_20 * V_21 ,
struct V_351 * V_352 ,
int V_343 ,
int V_344 )
{
enum V_274 V_275 ;
unsigned int V_341 ;
int V_278 ;
if ( V_352 -> V_353 . V_143 < 48 || V_352 -> V_353 . V_43 < 32 )
return - V_100 ;
if ( V_352 -> V_354 > 2048 )
return - V_100 ;
V_275 = V_352 -> V_275 ;
if ( V_355 == V_275 ) {
T_2 V_356 ;
V_356 = V_21 -> V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_43 >> 1 ;
V_275 = ( V_352 -> V_353 . V_43 > V_356 )
? V_357
: V_285 ;
}
switch ( V_275 ) {
case V_285 :
case V_286 :
case V_357 :
break;
default:
return - V_100 ;
}
if ( NULL == V_21 -> V_358 )
return - V_100 ;
V_341 = ~ 0 ;
switch ( V_21 -> V_358 -> V_288 ) {
case 8 :
case 24 :
V_341 = ~ 3 ;
break;
case 16 :
V_341 = ~ 1 ;
break;
case 32 :
break;
default:
F_99 () ;
}
V_352 -> V_353 . V_143 -= V_352 -> V_353 . V_290 & ~ V_341 ;
V_352 -> V_353 . V_290 = ( V_352 -> V_353 . V_290 - V_341 - 1 ) & V_341 ;
V_278 = F_96 ( V_21 , & V_352 -> V_353 . V_143 , & V_352 -> V_353 . V_43 ,
V_275 , V_341 ,
0 ,
V_343 , V_344 ) ;
if ( 0 != V_278 )
return V_278 ;
V_352 -> V_275 = V_275 ;
return 0 ;
}
static int F_100 ( struct V_20 * V_21 , struct V_9 * V_10 ,
struct V_351 * V_352 , int V_359 )
{
struct V_360 * V_361 = NULL ;
int V_362 , V_284 , V_263 = 0 ;
if ( NULL == V_21 -> V_358 )
return - V_100 ;
if ( ! ( V_21 -> V_358 -> V_161 & V_363 ) )
return - V_100 ;
V_263 = F_98 ( V_21 , V_352 ,
V_359 ,
V_359 ) ;
if ( 0 != V_263 )
return V_263 ;
V_362 = V_352 -> V_354 ;
V_284 = sizeof( * V_361 ) * ( V_362 + 4 ) ;
V_361 = F_101 ( V_284 , V_364 ) ;
if ( NULL == V_361 )
return - V_365 ;
if ( V_362 > 0 ) {
if ( F_102 ( V_361 , V_352 -> V_361 , sizeof( struct V_360 ) * V_362 ) ) {
F_69 ( V_361 ) ;
return - V_366 ;
}
}
if ( NULL != V_10 -> V_292 . V_367 )
V_362 = F_103 ( V_10 -> V_292 . V_273 . V_143 , V_10 -> V_292 . V_273 . V_43 ,
& V_352 -> V_353 , V_361 , V_362 ) ;
F_104 ( V_361 , V_362 ) ;
switch ( V_21 -> V_358 -> V_288 ) {
case 8 :
case 24 :
F_105 ( & V_352 -> V_353 , V_361 , V_362 , 3 ) ;
break;
case 16 :
F_105 ( & V_352 -> V_353 , V_361 , V_362 , 1 ) ;
break;
case 32 :
break;
default:
F_99 () ;
}
F_69 ( V_21 -> V_368 . V_361 ) ;
V_21 -> V_368 . V_361 = V_361 ;
V_21 -> V_368 . V_369 = V_362 ;
V_21 -> V_368 . V_353 = V_352 -> V_353 ;
V_21 -> V_368 . V_275 = V_352 -> V_275 ;
V_21 -> V_368 . V_370 = 1 ;
V_10 -> V_371 . V_368 . V_353 . V_143 = V_352 -> V_353 . V_143 ;
V_10 -> V_371 . V_368 . V_353 . V_43 = V_352 -> V_353 . V_43 ;
V_10 -> V_371 . V_368 . V_275 = V_352 -> V_275 ;
V_263 = 0 ;
if ( F_14 ( V_21 , V_270 ) ) {
struct V_260 * V_261 ;
V_261 = F_106 ( sizeof( * V_261 ) ) ;
V_261 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_368 , V_21 -> V_358 , V_261 ) ;
V_263 = F_67 ( V_10 , V_21 , V_261 ) ;
}
return V_263 ;
}
static struct V_271 * F_108 ( struct V_20 * V_21 )
{
struct V_271 * V_272 = NULL ;
switch ( V_21 -> type ) {
case V_372 :
V_272 = & V_21 -> V_269 ;
break;
case V_373 :
V_272 = & V_21 -> V_374 ;
break;
default:
F_99 () ;
}
return V_272 ;
}
static int F_109 ( struct V_20 * V_21 )
{
int V_375 = 0 ;
switch ( V_21 -> type ) {
case V_372 :
V_375 = V_26 ;
break;
case V_373 :
V_375 = V_376 ;
break;
default:
F_99 () ;
}
return V_375 ;
}
static int F_110 ( struct V_20 * V_21 , enum V_377 type )
{
struct V_271 * V_272 = F_108 ( V_21 ) ;
int V_375 = F_109 ( V_21 ) ;
if ( F_14 ( V_21 , V_375 ) )
return - V_350 ;
if ( F_111 ( V_272 ) )
return - V_350 ;
V_21 -> type = type ;
return 0 ;
}
static void
F_112 ( struct V_378 * V_240 ,
const struct V_256 * V_273 ,
unsigned int V_143 ,
unsigned int V_43 )
{
V_240 -> V_143 = V_143 ;
V_240 -> V_43 = V_43 ;
if ( V_273 -> V_161 & V_379 ) {
V_240 -> V_380 = V_143 ;
V_240 -> V_381 = ( V_143 * V_43 * V_273 -> V_288 ) >> 3 ;
} else {
V_240 -> V_380 = ( V_143 * V_273 -> V_288 ) >> 3 ;
V_240 -> V_381 = V_43 * V_240 -> V_380 ;
}
}
static int F_113 ( struct V_212 * V_212 , void * V_213 ,
struct V_382 * V_240 )
{
struct V_20 * V_21 = V_213 ;
F_112 ( & V_240 -> V_273 . V_383 , V_21 -> V_273 ,
V_21 -> V_143 , V_21 -> V_43 ) ;
V_240 -> V_273 . V_383 . V_275 = V_21 -> V_269 . V_275 ;
V_240 -> V_273 . V_383 . V_384 = V_21 -> V_273 -> V_257 ;
return 0 ;
}
static int F_114 ( struct V_212 * V_212 , void * V_213 ,
struct V_382 * V_240 )
{
struct V_20 * V_21 = V_213 ;
V_240 -> V_273 . V_352 . V_353 = V_21 -> V_368 . V_353 ;
V_240 -> V_273 . V_352 . V_275 = V_21 -> V_368 . V_275 ;
return 0 ;
}
static int F_115 ( struct V_212 * V_212 , void * V_213 ,
struct V_382 * V_240 )
{
const struct V_256 * V_273 ;
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
enum V_274 V_275 ;
T_2 V_143 , V_43 ;
int V_278 ;
V_273 = F_66 ( V_240 -> V_273 . V_383 . V_384 ) ;
if ( NULL == V_273 )
return - V_100 ;
V_275 = V_240 -> V_273 . V_383 . V_275 ;
if ( V_355 == V_275 ) {
T_2 V_356 ;
V_356 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 . V_43 >> 1 ;
V_275 = ( V_240 -> V_273 . V_383 . V_43 > V_356 )
? V_357
: V_286 ;
}
if ( V_385 == V_275 )
V_275 = V_386 ;
switch ( V_275 ) {
case V_285 :
case V_286 :
case V_287 :
case V_357 :
break;
case V_386 :
if ( V_273 -> V_161 & V_379 )
return - V_100 ;
break;
default:
return - V_100 ;
}
V_143 = V_240 -> V_273 . V_383 . V_143 ;
V_43 = V_240 -> V_273 . V_383 . V_43 ;
V_278 = F_96 ( V_21 , & V_143 , & V_43 , V_275 ,
~ 3 ,
2 ,
1 ,
0 ) ;
if ( 0 != V_278 )
return V_278 ;
V_240 -> V_273 . V_383 . V_275 = V_275 ;
F_112 ( & V_240 -> V_273 . V_383 , V_273 , V_143 , V_43 ) ;
return 0 ;
}
static int F_116 ( struct V_212 * V_212 , void * V_213 ,
struct V_382 * V_240 )
{
struct V_20 * V_21 = V_213 ;
return F_98 ( V_21 , & V_240 -> V_273 . V_352 ,
1 ,
0 ) ;
}
static int F_117 ( struct V_212 * V_212 , void * V_213 ,
struct V_382 * V_240 )
{
int V_263 ;
const struct V_256 * V_273 ;
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
T_2 V_143 , V_43 ;
enum V_274 V_275 ;
V_263 = F_110 ( V_21 , V_240 -> type ) ;
if ( 0 != V_263 )
return V_263 ;
V_263 = F_115 ( V_212 , V_213 , V_240 ) ;
if ( 0 != V_263 )
return V_263 ;
V_143 = V_240 -> V_273 . V_383 . V_143 ;
V_43 = V_240 -> V_273 . V_383 . V_43 ;
V_275 = V_240 -> V_273 . V_383 . V_275 ;
V_263 = F_96 ( V_21 , & V_143 , & V_43 , V_240 -> V_273 . V_383 . V_275 ,
~ 3 ,
2 ,
1 ,
1 ) ;
if ( 0 != V_263 )
return V_263 ;
V_240 -> V_273 . V_383 . V_275 = V_275 ;
V_273 = F_66 ( V_240 -> V_273 . V_383 . V_384 ) ;
V_21 -> V_273 = V_273 ;
V_21 -> V_269 . V_275 = V_240 -> V_273 . V_383 . V_275 ;
V_21 -> V_269 . V_387 = V_388 ;
V_21 -> V_143 = V_240 -> V_273 . V_383 . V_143 ;
V_21 -> V_43 = V_240 -> V_273 . V_383 . V_43 ;
V_10 -> V_371 . V_273 = V_273 ;
V_10 -> V_371 . V_143 = V_240 -> V_273 . V_383 . V_143 ;
V_10 -> V_371 . V_43 = V_240 -> V_273 . V_383 . V_43 ;
return 0 ;
}
static int F_118 ( struct V_212 * V_212 , void * V_213 ,
struct V_382 * V_240 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_389 > 0 ) {
F_21 ( L_19 ) ;
return - V_100 ;
}
return F_100 ( V_21 , V_10 , & V_240 -> V_273 . V_352 , 1 ) ;
}
static int F_119 ( struct V_212 * V_212 , void * V_213 ,
struct V_390 * V_269 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( 0 == V_391 )
return - V_100 ;
F_120 ( V_269 -> V_392 , L_20 , sizeof( V_269 -> V_392 ) ) ;
F_120 ( V_269 -> V_393 , V_10 -> V_394 -> V_308 , sizeof( V_269 -> V_393 ) ) ;
snprintf ( V_269 -> V_395 , sizeof( V_269 -> V_395 ) ,
L_21 , F_121 ( V_10 -> V_11 . V_396 ) ) ;
V_269 -> V_397 =
V_398 |
V_399 |
V_400 |
V_401 ;
if ( V_389 <= 0 )
V_269 -> V_397 |= V_402 ;
if ( V_10 -> V_403 )
V_269 -> V_397 |= V_404 ;
if ( V_10 -> V_167 != V_168 )
V_269 -> V_397 |= V_405 ;
return 0 ;
}
static int F_122 ( struct V_406 * V_240 )
{
int V_305 = - 1 , V_18 ;
for ( V_18 = 0 ; V_18 < V_258 ; V_18 ++ ) {
if ( V_259 [ V_18 ] . V_257 != - 1 )
V_305 ++ ;
if ( ( unsigned int ) V_305 == V_240 -> V_305 )
break;
}
if ( V_258 == V_18 )
return - V_100 ;
V_240 -> V_384 = V_259 [ V_18 ] . V_257 ;
F_120 ( V_240 -> V_407 , V_259 [ V_18 ] . V_308 , sizeof( V_240 -> V_407 ) ) ;
return V_18 ;
}
static int F_123 ( struct V_212 * V_212 , void * V_213 ,
struct V_406 * V_240 )
{
int V_278 = F_122 ( V_240 ) ;
if ( V_278 < 0 )
return V_278 ;
return 0 ;
}
static int F_124 ( struct V_212 * V_212 , void * V_213 ,
struct V_406 * V_240 )
{
int V_278 ;
if ( V_389 > 0 ) {
F_21 ( L_19 ) ;
return - V_100 ;
}
V_278 = F_122 ( V_240 ) ;
if ( V_278 < 0 )
return V_278 ;
if ( ! ( V_259 [ V_278 ] . V_161 & V_363 ) )
return - V_100 ;
return 0 ;
}
static int F_125 ( struct V_212 * V_212 , void * V_240 ,
struct V_408 * V_409 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_409 = V_10 -> V_292 ;
V_409 -> V_410 = V_411 ;
if ( V_21 -> V_358 )
V_409 -> V_273 . V_384 = V_21 -> V_358 -> V_257 ;
return 0 ;
}
static int F_126 ( struct V_212 * V_212 , void * V_240 , unsigned int V_412 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_260 * V_261 ;
int V_263 = 0 ;
if ( V_412 ) {
if ( F_83 ( ! V_10 -> V_292 . V_367 ) ) {
return - V_100 ;
}
if ( F_83 ( ! V_21 -> V_368 . V_370 ) ) {
F_24 ( L_22 , V_10 -> V_11 . V_61 ) ;
V_263 = - V_100 ;
}
if ( V_263 )
return V_263 ;
}
if ( ! F_13 ( V_10 , V_21 , V_270 ) )
return - V_350 ;
if ( V_412 ) {
V_21 -> V_368 . V_39 = V_10 -> V_39 ;
V_261 = F_106 ( sizeof( * V_261 ) ) ;
V_261 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_368 , V_21 -> V_358 , V_261 ) ;
} else {
V_261 = NULL ;
}
V_263 = F_67 ( V_10 , V_21 , V_261 ) ;
return V_263 ;
}
static int F_127 ( struct V_212 * V_212 , void * V_240 ,
struct V_408 * V_409 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_256 * V_273 ;
int V_263 ;
if ( ! F_90 ( V_332 ) &&
! F_90 ( V_413 ) )
return - V_333 ;
V_273 = F_66 ( V_409 -> V_273 . V_384 ) ;
if ( NULL == V_273 )
return - V_100 ;
if ( 0 == ( V_273 -> V_161 & V_363 ) )
return - V_100 ;
V_263 = - V_100 ;
if ( V_409 -> V_161 & V_414 ) {
T_2 V_143 = V_409 -> V_273 . V_143 ;
T_2 V_43 = V_409 -> V_273 . V_43 ;
V_263 = F_96 ( V_21 , & V_143 , & V_43 ,
V_357 ,
~ 3 ,
2 ,
0 ,
0 ) ;
if ( 0 != V_263 )
return V_263 ;
}
V_10 -> V_292 . V_367 = V_409 -> V_367 ;
V_10 -> V_292 . V_273 . V_143 = V_409 -> V_273 . V_143 ;
V_10 -> V_292 . V_273 . V_43 = V_409 -> V_273 . V_43 ;
if ( 0 != V_409 -> V_273 . V_380 )
V_10 -> V_292 . V_273 . V_380 = V_409 -> V_273 . V_380 ;
else
V_10 -> V_292 . V_273 . V_380 = V_10 -> V_292 . V_273 . V_143 * V_273 -> V_288 / 8 ;
V_263 = 0 ;
V_21 -> V_358 = V_273 ;
V_10 -> V_371 . V_358 = V_273 ;
if ( V_409 -> V_161 & V_414 ) {
V_21 -> V_368 . V_353 . V_290 = 0 ;
V_21 -> V_368 . V_353 . V_29 = 0 ;
V_21 -> V_368 . V_353 . V_143 = V_409 -> V_273 . V_143 ;
V_21 -> V_368 . V_353 . V_43 = V_409 -> V_273 . V_43 ;
V_10 -> V_371 . V_368 . V_353 . V_143 = V_409 -> V_273 . V_143 ;
V_10 -> V_371 . V_368 . V_353 . V_43 = V_409 -> V_273 . V_43 ;
F_69 ( V_21 -> V_368 . V_361 ) ;
V_21 -> V_368 . V_361 = NULL ;
V_21 -> V_368 . V_369 = 0 ;
if ( F_14 ( V_21 , V_270 ) ) {
struct V_260 * V_261 ;
V_261 = F_106 ( sizeof( * V_261 ) ) ;
V_261 -> V_30 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
F_107 ( V_10 , & V_21 -> V_368 , V_21 -> V_358 , V_261 ) ;
V_263 = F_67 ( V_10 , V_21 , V_261 ) ;
}
}
return V_263 ;
}
static int F_128 ( struct V_212 * V_212 , void * V_213 ,
struct V_415 * V_416 )
{
struct V_20 * V_21 = V_213 ;
return F_129 ( F_108 ( V_21 ) , V_416 ) ;
}
static int F_130 ( struct V_212 * V_212 , void * V_213 ,
struct V_417 * V_336 )
{
struct V_20 * V_21 = V_213 ;
return F_131 ( F_108 ( V_21 ) , V_336 ) ;
}
static int F_132 ( struct V_212 * V_212 , void * V_213 , struct V_417 * V_336 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_375 = F_109 ( V_21 ) ;
if ( ! F_13 ( V_10 , V_21 , V_375 ) )
return - V_350 ;
return F_133 ( F_108 ( V_21 ) , V_336 ) ;
}
static int F_134 ( struct V_212 * V_212 , void * V_213 , struct V_417 * V_336 )
{
struct V_20 * V_21 = V_213 ;
return F_135 ( F_108 ( V_21 ) , V_336 ,
V_212 -> V_418 & V_419 ) ;
}
static int F_136 ( struct V_212 * V_212 , void * V_213 ,
enum V_377 type )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_375 = F_109 ( V_21 ) ;
if ( ! F_13 ( V_10 , V_21 , V_375 ) )
return - V_350 ;
return F_137 ( F_108 ( V_21 ) ) ;
}
static int F_138 ( struct V_212 * V_212 , void * V_213 ,
enum V_377 type )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_263 ;
int V_375 = F_109 ( V_21 ) ;
V_263 = F_139 ( F_108 ( V_21 ) ) ;
if ( V_263 < 0 )
return V_263 ;
F_20 ( V_10 , V_21 , V_375 ) ;
return 0 ;
}
static int F_140 ( struct V_212 * V_212 , void * V_213 ,
struct V_16 * V_11 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_16 * V_109 ;
if ( ( V_11 -> V_17 < V_420 ||
V_11 -> V_17 >= V_421 ) &&
( V_11 -> V_17 < V_422 ||
V_11 -> V_17 >= V_423 ) )
return - V_100 ;
if ( ! V_10 -> V_243 && ( V_11 -> V_17 == V_218 ) )
* V_11 = V_424 ;
else {
V_109 = F_11 ( V_11 -> V_17 ) ;
* V_11 = ( NULL != V_109 ) ? * V_109 : V_424 ;
}
return 0 ;
}
static int F_141 ( struct V_212 * V_212 , void * V_240 ,
struct V_425 * V_426 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
F_142 ( V_40 [ V_10 -> V_39 ] . V_159 ,
& V_426 -> V_426 . V_300 . V_427 ) ;
return 0 ;
}
static int F_143 ( struct V_212 * V_212 , void * V_213 ,
struct V_318 * V_319 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_10 -> V_167 == V_168 )
return - V_100 ;
if ( 0 != V_319 -> V_305 )
return - V_100 ;
V_319 -> V_428 = V_429 ;
F_43 ( V_10 , V_310 , V_430 , V_319 ) ;
strcpy ( V_319 -> V_308 , L_16 ) ;
V_319 -> V_410 = V_431 ;
V_319 -> type = V_324 ;
if ( F_18 ( V_65 ) & V_111 )
V_319 -> signal = 0xffff ;
if ( V_10 -> V_321 )
V_10 -> V_321 ( V_10 , V_319 , 0 ) ;
return 0 ;
}
static int F_144 ( struct V_212 * V_212 , void * V_240 , enum V_432 * V_416 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
* V_416 = F_145 ( & V_10 -> V_242 ) ;
return 0 ;
}
static int F_146 ( struct V_212 * V_212 , void * V_240 ,
enum V_432 V_242 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
int V_278 ;
V_278 = F_147 ( & V_10 -> V_242 , & V_21 -> V_242 , V_242 ) ;
return V_278 ;
}
static int F_148 ( struct V_212 * V_212 , void * V_213 ,
struct V_433 * V_269 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_269 -> type != V_372 &&
V_269 -> type != V_434 )
return - V_100 ;
* V_269 = V_40 [ V_10 -> V_39 ] . V_41 ;
return 0 ;
}
static int F_149 ( struct V_212 * V_212 , void * V_240 , struct V_435 * V_30 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_30 -> type != V_372 &&
V_30 -> type != V_434 )
return - V_100 ;
V_30 -> V_11 = V_10 -> V_30 [ ! ! V_21 -> V_31 ] . V_32 ;
return 0 ;
}
static int F_150 ( struct V_212 * V_212 , void * V_240 , struct V_435 * V_30 )
{
struct V_20 * V_21 = V_240 ;
struct V_9 * V_10 = V_21 -> V_10 ;
const struct V_335 * V_336 ;
int V_263 ;
struct V_140 V_11 ;
T_2 V_436 ;
T_2 V_437 ;
T_2 V_438 ;
T_2 V_439 ;
if ( V_30 -> type != V_372 &&
V_30 -> type != V_434 )
return - V_100 ;
V_263 = F_63 ( & V_10 -> V_242 , V_21 -> V_242 ) ;
if ( 0 != V_263 ) {
return V_263 ;
}
V_263 = - V_350 ;
if ( F_15 ( V_21 -> V_10 , V_28 ) ) {
return V_263 ;
}
V_336 = & V_40 [ V_10 -> V_39 ] . V_41 . V_42 ;
V_436 = V_336 -> V_290 ;
V_438 = V_436 + V_336 -> V_143 ;
V_439 = V_336 -> V_29 + V_336 -> V_43 ;
V_437 = F_49 ( V_336 -> V_29 , V_10 -> V_33 ) ;
if ( V_437 + 32 >= V_439 ) {
return V_263 ;
}
V_11 . V_32 . V_290 = F_97 ( V_30 -> V_11 . V_290 , V_436 , V_438 - 48 ) ;
V_11 . V_32 . V_290 = F_95 ( V_11 . V_32 . V_290 , ( T_2 ) V_340 ) ;
V_11 . V_32 . V_143 = F_97 ( V_30 -> V_11 . V_143 ,
48 , V_438 - V_11 . V_32 . V_290 ) ;
V_11 . V_32 . V_29 = F_97 ( V_30 -> V_11 . V_29 , V_437 , V_439 - 32 ) ;
V_11 . V_32 . V_29 = ( V_11 . V_32 . V_29 + 1 ) & ~ 1 ;
V_11 . V_32 . V_43 = F_97 ( V_30 -> V_11 . V_43 ,
32 , V_439 - V_11 . V_32 . V_29 ) ;
V_11 . V_32 . V_43 = ( V_11 . V_32 . V_43 + 1 ) & ~ 1 ;
F_48 ( & V_11 ) ;
V_10 -> V_30 [ 1 ] = V_11 ;
V_21 -> V_31 = 1 ;
if ( V_21 -> V_143 < V_11 . V_141 ) {
V_21 -> V_143 = V_11 . V_141 ;
V_10 -> V_371 . V_143 = V_11 . V_141 ;
} else if ( V_21 -> V_143 > V_11 . V_144 ) {
V_21 -> V_143 = V_11 . V_144 ;
V_10 -> V_371 . V_143 = V_11 . V_144 ;
}
if ( V_21 -> V_43 < V_11 . V_142 ) {
V_21 -> V_43 = V_11 . V_142 ;
V_10 -> V_371 . V_43 = V_11 . V_142 ;
} else if ( V_21 -> V_43 > V_11 . V_145 ) {
V_21 -> V_43 = V_11 . V_145 ;
V_10 -> V_371 . V_43 = V_11 . V_145 ;
}
return 0 ;
}
static int F_151 ( struct V_212 * V_212 , void * V_213 , struct V_440 * V_441 )
{
if ( F_83 ( V_441 -> V_305 ) )
return - V_100 ;
strcpy ( V_441 -> V_308 , L_23 ) ;
return 0 ;
}
static int F_152 ( struct V_212 * V_212 , void * V_213 , struct V_440 * V_441 )
{
if ( F_83 ( V_441 -> V_305 ) )
return - V_100 ;
return 0 ;
}
static T_1 F_153 ( struct V_212 * V_212 , char T_7 * V_249 ,
T_8 V_294 , T_9 * V_442 )
{
struct V_20 * V_21 = V_212 -> V_443 ;
int V_263 = 0 ;
if ( V_21 -> V_10 -> V_211 )
F_59 ( V_21 -> V_10 ) ;
F_24 ( L_24 ,
V_21 -> V_10 -> V_11 . V_61 , ( int ) V_294 , V_444 [ V_21 -> type ] ) ;
switch ( V_21 -> type ) {
case V_372 :
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_25 ) ) {
return - V_350 ;
}
V_263 = F_154 ( & V_21 -> V_269 , V_249 , V_294 , V_442 ,
V_212 -> V_418 & V_419 ) ;
F_20 ( V_21 -> V_10 , V_21 , V_25 ) ;
break;
case V_373 :
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_376 ) )
return - V_350 ;
V_263 = F_155 ( & V_21 -> V_374 , V_249 , V_294 , V_442 , 1 ,
V_212 -> V_418 & V_419 ) ;
break;
default:
F_99 () ;
}
return V_263 ;
}
static unsigned int F_156 ( struct V_212 * V_212 , T_10 * V_445 )
{
struct V_20 * V_21 = V_212 -> V_443 ;
struct V_260 * V_5 ;
enum V_274 V_275 ;
unsigned int V_278 = V_446 ;
if ( V_373 == V_21 -> type ) {
if ( ! F_13 ( V_21 -> V_10 , V_21 , V_376 ) )
return V_446 ;
return F_157 ( V_212 , & V_21 -> V_374 , V_445 ) ;
}
if ( F_14 ( V_21 , V_26 ) ) {
if ( F_158 ( & V_21 -> V_269 . V_447 ) )
goto V_241;
V_5 = F_159 ( V_21 -> V_269 . V_447 . V_448 , struct V_260 , V_264 . V_447 ) ;
} else {
if ( NULL == V_21 -> V_269 . V_449 ) {
if ( F_15 ( V_21 -> V_10 , V_26 ) )
goto V_241;
V_21 -> V_269 . V_449 = F_106 ( V_21 -> V_269 . V_450 ) ;
if ( NULL == V_21 -> V_269 . V_449 )
goto V_241;
V_21 -> V_269 . V_449 -> V_451 = V_452 ;
V_275 = F_160 ( & V_21 -> V_269 ) ;
if ( 0 != V_21 -> V_269 . V_453 -> V_454 ( & V_21 -> V_269 , V_21 -> V_269 . V_449 , V_275 ) ) {
F_69 ( V_21 -> V_269 . V_449 ) ;
V_21 -> V_269 . V_449 = NULL ;
goto V_241;
}
V_21 -> V_269 . V_453 -> V_455 ( & V_21 -> V_269 , V_21 -> V_269 . V_449 ) ;
V_21 -> V_269 . V_456 = 0 ;
}
V_5 = (struct V_260 * ) V_21 -> V_269 . V_449 ;
}
F_161 ( V_212 , & V_5 -> V_264 . V_457 , V_445 ) ;
if ( V_5 -> V_264 . V_265 == V_266 ||
V_5 -> V_264 . V_265 == V_458 )
V_278 = V_459 | V_460 ;
else
V_278 = 0 ;
V_241:
return V_278 ;
}
static int F_162 ( struct V_212 * V_212 )
{
struct V_6 * V_461 = F_163 ( V_212 ) ;
struct V_9 * V_10 = F_164 ( V_212 ) ;
struct V_20 * V_21 ;
enum V_377 type = 0 ;
F_24 ( L_25 , F_165 ( V_461 ) ) ;
if ( V_461 -> V_462 == V_463 ) {
type = V_372 ;
} else if ( V_461 -> V_462 == V_464 ) {
type = V_373 ;
} else {
F_166 ( 1 ) ;
return - V_465 ;
}
F_24 ( L_26 ,
V_10 -> V_11 . V_61 , V_444 [ type ] ) ;
V_21 = F_101 ( sizeof( * V_21 ) , V_364 ) ;
if ( F_83 ( ! V_21 ) )
return - V_365 ;
V_212 -> V_443 = V_21 ;
* V_21 = V_10 -> V_371 ;
V_21 -> type = type ;
V_21 -> V_368 . V_370 = 0 ;
F_167 ( & V_10 -> V_242 , & V_21 -> V_242 ) ;
F_168 ( & V_21 -> V_269 , & V_466 ,
& V_10 -> V_11 . V_396 -> V_8 , & V_10 -> V_163 ,
V_372 ,
V_357 ,
sizeof( struct V_260 ) ,
V_21 , & V_10 -> V_467 ) ;
F_168 ( & V_21 -> V_374 , & V_468 ,
& V_10 -> V_11 . V_396 -> V_8 , & V_10 -> V_163 ,
V_373 ,
V_386 ,
sizeof( struct V_260 ) ,
V_21 , & V_10 -> V_467 ) ;
F_51 ( V_10 , V_10 -> V_39 ) ;
F_54 ( V_10 , V_10 -> V_72 , V_10 -> V_39 ) ;
V_10 -> V_253 ++ ;
V_21 -> V_31 = ! V_469 ;
F_169 ( & V_21 -> V_37 , V_10 -> V_39 ) ;
F_65 ( V_10 ) ;
return 0 ;
}
static int F_170 ( struct V_212 * V_212 )
{
struct V_20 * V_21 = V_212 -> V_443 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( F_14 ( V_21 , V_270 ) )
F_67 ( V_10 , V_21 , NULL ) ;
if ( F_14 ( V_21 , V_26 ) ) {
F_139 ( & V_21 -> V_269 ) ;
F_20 ( V_10 , V_21 , V_26 ) ;
}
if ( V_21 -> V_269 . V_449 ) {
F_77 ( & V_21 -> V_269 , V_21 -> V_269 . V_449 ) ;
F_69 ( V_21 -> V_269 . V_449 ) ;
}
if ( F_14 ( V_21 , V_25 ) ) {
F_20 ( V_10 , V_21 , V_25 ) ;
}
if ( F_14 ( V_21 , V_376 ) ) {
F_171 ( & V_21 -> V_374 ) ;
F_20 ( V_10 , V_21 , V_376 ) ;
}
F_172 ( & V_21 -> V_269 ) ;
F_172 ( & V_21 -> V_374 ) ;
F_173 ( & V_10 -> V_242 , V_21 -> V_242 ) ;
V_212 -> V_443 = NULL ;
F_69 ( V_21 ) ;
V_10 -> V_253 -- ;
F_65 ( V_10 ) ;
if ( ! V_10 -> V_253 )
F_46 ( V_10 , 1 ) ;
return 0 ;
}
static int
F_174 ( struct V_212 * V_212 , struct V_470 * V_471 )
{
struct V_20 * V_21 = V_212 -> V_443 ;
F_24 ( L_27 ,
V_21 -> V_10 -> V_11 . V_61 , V_444 [ V_21 -> type ] ,
V_471 -> V_472 , V_471 -> V_473 - V_471 -> V_472 ) ;
return F_175 ( F_108 ( V_21 ) , V_471 ) ;
}
static int F_176 ( struct V_212 * V_212 )
{
struct V_6 * V_461 = F_163 ( V_212 ) ;
struct V_9 * V_10 = F_164 ( V_212 ) ;
struct V_20 * V_21 ;
F_24 ( L_25 , F_165 ( V_461 ) ) ;
F_24 ( L_28 , V_10 -> V_11 . V_61 ) ;
V_21 = F_101 ( sizeof( * V_21 ) , V_364 ) ;
if ( F_83 ( ! V_21 ) )
return - V_365 ;
V_212 -> V_443 = V_21 ;
* V_21 = V_10 -> V_371 ;
F_167 ( & V_10 -> V_242 , & V_21 -> V_242 ) ;
V_10 -> V_114 ++ ;
F_43 ( V_10 , V_310 , V_474 ) ;
F_47 ( V_10 , V_126 ) ;
return 0 ;
}
static int F_177 ( struct V_212 * V_212 )
{
struct V_20 * V_21 = V_212 -> V_443 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_475 V_476 ;
F_173 ( & V_10 -> V_242 , V_21 -> V_242 ) ;
V_212 -> V_443 = NULL ;
F_69 ( V_21 ) ;
V_10 -> V_114 -- ;
F_43 ( V_10 , V_122 , V_477 , V_478 , & V_476 ) ;
return 0 ;
}
static int F_178 ( struct V_212 * V_212 , void * V_213 ,
struct V_390 * V_269 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
strcpy ( V_269 -> V_392 , L_20 ) ;
F_120 ( V_269 -> V_393 , V_10 -> V_479 -> V_308 , sizeof( V_269 -> V_393 ) ) ;
sprintf ( V_269 -> V_395 , L_21 , F_121 ( V_10 -> V_11 . V_396 ) ) ;
V_269 -> V_397 = V_405 ;
return 0 ;
}
static int F_179 ( struct V_212 * V_212 , void * V_213 , struct V_318 * V_319 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( V_10 -> V_167 == V_168 )
return - V_100 ;
if ( 0 != V_319 -> V_305 )
return - V_100 ;
strcpy ( V_319 -> V_308 , L_29 ) ;
V_319 -> type = V_323 ;
F_43 ( V_10 , V_310 , V_430 , V_319 ) ;
if ( V_10 -> V_321 )
V_10 -> V_321 ( V_10 , V_319 , 0 ) ;
return 0 ;
}
static int F_180 ( struct V_212 * V_212 , void * V_213 ,
struct V_304 * V_18 )
{
if ( V_18 -> V_305 != 0 )
return - V_100 ;
strcpy ( V_18 -> V_308 , L_29 ) ;
V_18 -> type = V_309 ;
return 0 ;
}
static int F_181 ( struct V_212 * V_212 , void * V_213 ,
struct V_440 * V_441 )
{
if ( F_83 ( V_441 -> V_305 ) )
return - V_100 ;
strcpy ( V_441 -> V_308 , L_29 ) ;
return 0 ;
}
static int F_182 ( struct V_212 * V_212 , void * V_213 ,
struct V_318 * V_319 )
{
struct V_20 * V_21 = V_213 ;
struct V_9 * V_10 = V_21 -> V_10 ;
if ( 0 != V_319 -> V_305 )
return - V_100 ;
F_43 ( V_10 , V_310 , V_320 , V_319 ) ;
return 0 ;
}
static int F_183 ( struct V_212 * V_212 , void * V_213 ,
struct V_440 * V_441 )
{
if ( F_83 ( V_441 -> V_305 ) )
return - V_100 ;
return 0 ;
}
static int F_184 ( struct V_212 * V_480 , void * V_213 , unsigned int V_18 )
{
if ( F_83 ( V_18 ) )
return - V_100 ;
return 0 ;
}
static int F_185 ( struct V_212 * V_212 , void * V_21 , T_5 * V_146 )
{
return 0 ;
}
static int F_186 ( struct V_212 * V_212 , void * V_213 ,
struct V_16 * V_11 )
{
const struct V_16 * V_109 ;
if ( V_11 -> V_17 < V_420 ||
V_11 -> V_17 >= V_421 )
return - V_100 ;
if ( V_11 -> V_17 == V_121 ) {
V_109 = F_11 ( V_11 -> V_17 ) ;
* V_11 = * V_109 ;
} else
* V_11 = V_424 ;
return 0 ;
}
static int F_187 ( struct V_212 * V_480 , void * V_213 , unsigned int * V_18 )
{
* V_18 = 0 ;
return 0 ;
}
static T_1 F_188 ( struct V_212 * V_212 , char T_7 * V_249 ,
T_8 V_294 , T_9 * V_442 )
{
struct V_20 * V_21 = V_212 -> V_443 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_475 V_476 ;
V_476 . V_481 = V_294 / 3 ;
V_476 . V_482 = V_249 ;
V_476 . V_483 = V_212 ;
V_476 . V_484 = - V_465 ;
F_43 ( V_10 , V_122 , V_477 , V_485 , & V_476 ) ;
return V_476 . V_484 ;
}
static unsigned int F_189 ( struct V_212 * V_212 , T_10 * V_445 )
{
struct V_20 * V_21 = V_212 -> V_443 ;
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_475 V_476 ;
V_476 . V_483 = V_212 ;
V_476 . V_486 = V_445 ;
V_476 . V_484 = - V_465 ;
F_43 ( V_10 , V_122 , V_477 , V_487 , & V_476 ) ;
return V_476 . V_484 ;
}
static int F_190 ( T_4 V_488 )
{
static char * V_489 [ 16 ] = {
[ V_490 >> 28 ] = L_30 ,
[ V_491 >> 28 ] = L_31 ,
[ V_492 >> 28 ] = L_32 ,
[ V_493 >> 28 ] = L_33 ,
[ V_494 >> 28 ] = L_34 ,
[ V_495 >> 28 ] = L_35 ,
[ V_496 >> 28 ] = L_36 ,
[ V_497 >> 28 ] = L_37 ,
} ;
static int V_498 [ 16 ] = {
[ V_490 >> 28 ] = 2 ,
[ V_493 >> 28 ] = 2 ,
[ V_494 >> 28 ] = 2 ,
[ V_495 >> 28 ] = 5 ,
[ V_496 >> 28 ] = 2 ,
[ V_497 >> 28 ] = 3 ,
} ;
static char * V_48 [] = {
L_38 , L_39 , L_40 , L_41 ,
L_42 , L_43 , L_44 , L_45 ,
L_46 , L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 , L_53 ,
} ;
int V_18 ;
F_191 ( L_54 , V_488 ,
V_489 [ V_488 >> 28 ] ? V_489 [ V_488 >> 28 ] : L_55 ) ;
for ( V_18 = F_12 ( V_48 ) - 1 ; V_18 >= 0 ; V_18 -- )
if ( V_488 & ( 1 << ( V_18 + 12 ) ) )
F_191 ( L_56 , V_48 [ V_18 ] ) ;
F_191 ( L_57 , V_488 & 0xfff ) ;
return V_498 [ V_488 >> 28 ] ? V_498 [ V_488 >> 28 ] : 1 ;
}
static void F_192 ( struct V_9 * V_10 ,
struct V_499 * V_488 )
{
unsigned int V_18 , V_500 , V_362 ;
F_25 ( L_58 ,
V_10 -> V_11 . V_501 . V_308 , V_488 -> V_502 , ( unsigned long ) V_488 -> V_503 ) ;
for ( V_18 = 0 ; V_18 < ( V_488 -> V_284 >> 2 ) ; V_18 += V_362 ) {
F_25 ( L_59 ,
V_10 -> V_11 . V_501 . V_308 ,
( unsigned long ) ( V_488 -> V_503 + ( V_18 << 2 ) ) ) ;
V_362 = F_190 ( F_193 ( V_488 -> V_502 [ V_18 ] ) ) ;
for ( V_500 = 1 ; V_500 < V_362 ; V_500 ++ )
F_25 ( L_60 ,
V_10 -> V_11 . V_501 . V_308 ,
( unsigned long ) ( V_488 -> V_503 + ( ( V_18 + V_500 ) << 2 ) ) ,
V_488 -> V_502 [ V_18 + V_500 ] , V_500 ) ;
if ( 0 == V_488 -> V_502 [ V_18 ] )
break;
}
}
static void F_194 ( struct V_9 * V_10 )
{
F_25 ( L_61 , ( unsigned long long ) V_10 -> main. V_503 ) ;
F_25 ( L_62 ,
V_10 -> V_504 ? ( unsigned long long ) V_10 -> V_504 -> V_29 . V_503 : 0 ,
V_10 -> V_504 ? ( unsigned long long ) V_10 -> V_504 -> V_505 . V_503 : 0 ) ;
F_25 ( L_63 ,
V_10 -> V_164 . V_29
? ( unsigned long long ) V_10 -> V_164 . V_29 -> V_29 . V_503 : 0 ,
V_10 -> V_164 . V_505
? ( unsigned long long ) V_10 -> V_164 . V_505 -> V_505 . V_503 : 0 ) ;
F_25 ( L_64 ,
V_10 -> V_267 ? ( unsigned long long ) V_10 -> V_267 -> V_29 . V_503 : 0 ,
V_10 -> V_267 ? ( unsigned long long ) V_10 -> V_267 -> V_505 . V_503 : 0 ) ;
F_192 ( V_10 , & V_10 -> main ) ;
}
static void F_195 ( T_4 V_506 , T_4 V_507 )
{
unsigned int V_18 ;
F_191 ( L_65 ) ;
for ( V_18 = 0 ; V_18 < F_12 ( V_508 ) ; V_18 ++ ) {
if ( V_506 & ( 1 << V_18 ) )
F_191 ( L_56 , V_508 [ V_18 ] ) ;
if ( V_507 & ( 1 << V_18 ) )
F_191 ( L_66 ) ;
}
}
static void F_196 ( struct V_9 * V_10 , T_4 V_278 )
{
F_197 ( L_67 ,
V_10 -> V_11 . V_61 ,
( unsigned long ) V_10 -> main. V_503 ,
( unsigned long ) F_193 ( V_10 -> main. V_502 [ V_509 + 1 ] ) ,
( unsigned long ) F_193 ( V_10 -> main. V_502 [ V_510 + 1 ] ) ,
( unsigned long ) V_278 ) ;
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
F_200 ( struct V_9 * V_10 , struct V_511 * V_512 )
{
struct V_260 * V_513 ;
memset ( V_512 , 0 , sizeof( * V_512 ) ) ;
if ( ! F_158 ( & V_10 -> V_300 ) ) {
V_512 -> V_165 = 1 ;
V_513 = F_159 ( V_10 -> V_300 . V_448 , struct V_260 , V_264 . V_299 ) ;
if ( F_201 ( V_513 -> V_264 . V_275 ) )
V_512 -> V_29 = V_513 ;
if ( F_202 ( V_513 -> V_264 . V_275 ) )
V_512 -> V_505 = V_513 ;
if ( ! F_94 ( V_513 -> V_264 . V_275 ) &&
( V_513 -> V_264 . V_299 . V_448 != & V_10 -> V_300 ) ) {
V_513 = F_159 ( V_513 -> V_264 . V_299 . V_448 , struct V_260 , V_264 . V_299 ) ;
if ( ! F_94 ( V_513 -> V_264 . V_275 ) ) {
if ( NULL == V_512 -> V_505 &&
V_286 == V_513 -> V_264 . V_275 ) {
V_512 -> V_505 = V_513 ;
}
if ( NULL != V_512 -> V_29 && NULL != V_512 -> V_505 )
V_512 -> V_514 = 2 ;
}
}
}
if ( NULL != V_10 -> V_267 ) {
if ( F_94 ( V_10 -> V_267 -> V_264 . V_275 ) ) {
if ( NULL == V_512 -> V_29 && NULL == V_512 -> V_505 ) {
V_512 -> V_29 = V_10 -> V_267 ;
V_512 -> V_505 = V_10 -> V_267 ;
}
} else {
if ( V_285 == V_10 -> V_267 -> V_264 . V_275 &&
NULL == V_512 -> V_29 ) {
V_512 -> V_29 = V_10 -> V_267 ;
}
if ( V_286 == V_10 -> V_267 -> V_264 . V_275 &&
NULL == V_512 -> V_505 ) {
V_512 -> V_505 = V_10 -> V_267 ;
}
}
}
F_24 ( L_72 ,
V_10 -> V_11 . V_61 , V_512 -> V_29 , V_512 -> V_505 ,
V_10 -> V_267 , V_512 -> V_165 , V_512 -> V_514 ) ;
return 0 ;
}
static void
F_203 ( struct V_9 * V_10 , struct V_511 * V_515 ,
struct V_511 * V_164 , unsigned int V_265 )
{
struct V_516 V_517 ;
F_204 ( & V_517 ) ;
if ( V_515 -> V_29 == V_515 -> V_505 ) {
if ( NULL != V_515 -> V_29 && V_164 -> V_29 != V_515 -> V_29 ) {
if ( V_518 > 1 )
F_64 ( L_73 ,
V_10 -> V_11 . V_61 , V_515 -> V_29 ) ;
V_515 -> V_29 -> V_264 . V_517 = V_517 ;
V_515 -> V_29 -> V_264 . V_255 = V_10 -> V_255 ;
V_515 -> V_29 -> V_264 . V_265 = V_265 ;
F_205 ( & V_515 -> V_29 -> V_264 . V_457 ) ;
}
} else {
if ( NULL != V_515 -> V_29 && V_164 -> V_29 != V_515 -> V_29 ) {
if ( V_518 > 1 )
F_64 ( L_74 ,
V_10 -> V_11 . V_61 , V_515 -> V_29 ) ;
V_515 -> V_29 -> V_264 . V_517 = V_517 ;
V_515 -> V_29 -> V_264 . V_255 = V_10 -> V_255 ;
V_515 -> V_29 -> V_264 . V_265 = V_265 ;
F_205 ( & V_515 -> V_29 -> V_264 . V_457 ) ;
}
if ( NULL != V_515 -> V_505 && V_164 -> V_505 != V_515 -> V_505 ) {
if ( V_518 > 1 )
F_64 ( L_75 ,
V_10 -> V_11 . V_61 , V_515 -> V_505 ) ;
V_515 -> V_505 -> V_264 . V_517 = V_517 ;
V_515 -> V_505 -> V_264 . V_255 = V_10 -> V_255 ;
V_515 -> V_505 -> V_264 . V_265 = V_265 ;
F_205 ( & V_515 -> V_505 -> V_264 . V_457 ) ;
}
}
}
static void
F_206 ( struct V_9 * V_10 , struct V_260 * V_515 ,
unsigned int V_265 )
{
struct V_516 V_517 ;
if ( NULL == V_515 )
return;
F_204 ( & V_517 ) ;
V_515 -> V_264 . V_517 = V_517 ;
V_515 -> V_264 . V_255 = V_10 -> V_255 ;
V_515 -> V_264 . V_265 = V_265 ;
F_205 ( & V_515 -> V_264 . V_457 ) ;
}
static void F_207 ( unsigned long V_249 )
{
struct V_9 * V_10 = (struct V_9 * ) V_249 ;
struct V_511 V_262 , V_261 ;
struct V_260 * V_519 ;
struct V_260 * V_513 ;
unsigned long V_161 ;
if ( V_63 ) {
F_25 ( L_76 ,
V_10 -> V_11 . V_61 , V_10 -> V_520 , V_10 -> V_521 , V_10 -> V_522 ,
F_18 ( V_523 ) ) ;
F_195 ( F_18 ( V_169 ) , 0 ) ;
F_191 ( L_77 ) ;
}
F_55 ( & V_10 -> V_163 , V_161 ) ;
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_262 = V_10 -> V_164 ;
V_519 = V_10 -> V_504 ;
V_10 -> V_164 = V_261 ;
V_10 -> V_504 = NULL ;
V_10 -> V_268 = 0 ;
F_208 ( V_10 , & V_261 ) ;
F_209 ( V_10 , NULL ) ;
F_60 ( V_10 , 0 ) ;
F_203 ( V_10 , & V_262 , & V_261 , V_458 ) ;
F_206 ( V_10 , V_519 , V_458 ) ;
while ( ! F_158 ( & V_10 -> V_300 ) ) {
V_513 = F_159 ( V_10 -> V_300 . V_448 , struct V_260 , V_264 . V_299 ) ;
F_210 ( & V_513 -> V_264 . V_299 ) ;
V_513 -> V_264 . V_265 = V_458 ;
F_205 ( & V_513 -> V_264 . V_457 ) ;
}
while ( ! F_158 ( & V_10 -> V_524 ) ) {
V_513 = F_159 ( V_10 -> V_524 . V_448 , struct V_260 , V_264 . V_299 ) ;
F_210 ( & V_513 -> V_264 . V_299 ) ;
V_513 -> V_264 . V_265 = V_458 ;
F_205 ( & V_513 -> V_264 . V_457 ) ;
}
V_10 -> V_211 ++ ;
F_56 ( & V_10 -> V_163 , V_161 ) ;
}
static void
F_211 ( struct V_9 * V_10 )
{
struct V_260 * V_515 = V_10 -> V_164 . V_29 ;
if ( NULL == V_515 )
return;
F_212 ( & V_10 -> V_163 ) ;
V_10 -> V_164 . V_514 = 0 ;
V_10 -> V_164 . V_29 = NULL ;
F_213 ( V_10 , V_510 , NULL , 0 ) ;
F_204 ( & V_515 -> V_264 . V_517 ) ;
V_515 -> V_264 . V_255 = V_10 -> V_255 ;
V_515 -> V_264 . V_265 = V_266 ;
F_205 ( & V_515 -> V_264 . V_457 ) ;
F_214 ( & V_10 -> V_163 ) ;
}
static inline int F_215 ( struct V_499 * V_488 , T_4 V_278 )
{
if ( V_278 < V_488 -> V_503 )
return 0 ;
if ( V_278 > V_488 -> V_503 + V_488 -> V_284 )
return 0 ;
return 1 ;
}
static void
F_216 ( struct V_9 * V_10 )
{
struct V_511 V_261 ;
struct V_511 V_262 ;
T_11 V_278 ;
F_212 ( & V_10 -> V_163 ) ;
F_200 ( V_10 , & V_261 ) ;
V_278 = F_18 ( V_523 ) ;
if ( ( V_10 -> V_164 . V_29 && F_215 ( & V_10 -> V_164 . V_29 -> V_29 , V_278 ) ) ||
( V_10 -> V_164 . V_505 && F_215 ( & V_10 -> V_164 . V_505 -> V_505 , V_278 ) ) ) {
V_10 -> V_520 ++ ;
if ( V_525 )
F_196 ( V_10 , V_278 ) ;
F_214 ( & V_10 -> V_163 ) ;
return;
}
V_262 = V_10 -> V_164 ;
V_10 -> V_164 = V_261 ;
V_10 -> V_268 &= ~ 1 ;
F_208 ( V_10 , & V_261 ) ;
F_60 ( V_10 , 0 ) ;
if ( V_12 != V_10 -> V_166 ) {
F_33 ( V_10 , V_10 -> V_166 ) ;
V_10 -> V_166 = V_12 ;
}
F_203 ( V_10 , & V_262 , & V_261 , V_266 ) ;
F_214 ( & V_10 -> V_163 ) ;
}
static void
F_217 ( struct V_9 * V_10 )
{
struct V_260 * V_261 = NULL ;
struct V_260 * V_262 ;
T_4 V_278 ;
F_212 ( & V_10 -> V_163 ) ;
if ( ! F_158 ( & V_10 -> V_524 ) )
V_261 = F_159 ( V_10 -> V_524 . V_448 , struct V_260 , V_264 . V_299 ) ;
V_262 = V_10 -> V_504 ;
V_278 = F_18 ( V_523 ) ;
if ( NULL != V_262 && ( F_215 ( & V_262 -> V_29 , V_278 ) ||
F_215 ( & V_262 -> V_505 , V_278 ) ) ) {
V_10 -> V_520 ++ ;
if ( V_525 )
F_196 ( V_10 , V_278 ) ;
F_214 ( & V_10 -> V_163 ) ;
return;
}
V_10 -> V_504 = V_261 ;
V_10 -> V_268 &= ~ 4 ;
F_209 ( V_10 , V_261 ) ;
F_60 ( V_10 , 0 ) ;
F_206 ( V_10 , V_262 , V_266 ) ;
F_214 ( & V_10 -> V_163 ) ;
}
static T_12 F_218 ( int V_526 , void * V_527 )
{
T_4 V_528 , V_529 ;
T_4 V_530 ;
int V_294 ;
struct V_9 * V_10 ;
int V_531 = 0 ;
V_10 = (struct V_9 * ) V_527 ;
V_294 = 0 ;
while ( 1 ) {
V_528 = F_18 ( V_169 ) ;
V_529 = V_528 & F_18 ( V_172 ) ;
if ( ! V_529 )
break;
V_531 = 1 ;
F_19 ( V_528 , V_169 ) ;
V_530 = F_18 ( V_65 ) ;
if ( V_518 ) {
F_64 ( L_78 ,
V_10 -> V_11 . V_61 , V_294 , V_10 -> V_255 ,
V_528 >> 28 , F_18 ( V_523 ) ) ;
F_195 ( V_528 , V_529 ) ;
if ( V_528 & V_182 )
F_191 ( L_79 ,
V_530 & V_111
? L_80 : L_81 ) ;
if ( V_528 & V_532 )
F_191 ( L_82 ,
V_530 & V_312
? L_80 : L_81 ) ;
if ( V_528 & V_181 )
F_191 ( L_83 ,
V_530 & V_301
? L_84 : L_85 ) ;
F_191 ( L_77 ) ;
}
if ( V_529 & V_254 )
V_10 -> V_255 ++ ;
if ( ( V_529 & V_175 ) && V_10 -> V_533 ) {
F_219 ( V_10 ) ;
}
if ( V_529 & V_171 ) {
V_10 -> V_534 = V_528 ;
F_205 ( & V_10 -> V_535 ) ;
}
if ( ( V_529 & V_179 ) && ( V_528 & ( 4 << 28 ) ) )
F_217 ( V_10 ) ;
if ( ( V_529 & V_179 ) && ( V_528 & ( 2 << 28 ) ) )
F_211 ( V_10 ) ;
if ( ( V_529 & V_179 ) && ( V_528 & ( 1 << 28 ) ) )
F_216 ( V_10 ) ;
if ( ( V_529 & V_182 ) && V_10 -> V_113 )
F_46 ( V_10 , V_10 -> V_106 ) ;
if ( V_529 & ( V_176 | V_180 ) ) {
F_25 ( L_86 ,
V_10 -> V_11 . V_61 ,
( V_529 & V_176 ) ? L_87 : L_88 ,
( V_529 & V_180 ) ? L_89 : L_88 ,
F_18 ( V_523 ) ) ;
F_195 ( V_528 , V_529 ) ;
F_191 ( L_77 ) ;
if ( V_536 )
F_194 ( V_10 ) ;
}
if ( V_177 && V_529 & V_178 ) {
F_25 ( L_90 ,
V_10 -> V_11 . V_61 , F_18 ( V_523 ) ) ;
if ( V_536 )
F_194 ( V_10 ) ;
}
V_294 ++ ;
if ( V_294 > 4 ) {
if ( V_294 > 8 || ! ( V_529 & V_175 ) ) {
F_19 ( 0 , V_172 ) ;
F_21 ( L_91 ,
V_10 -> V_11 . V_61 ) ;
} else {
F_21 ( L_92 ,
V_10 -> V_11 . V_61 ) ;
F_19 ( F_18 ( V_172 ) & ( - 1 ^ V_175 ) ,
V_172 ) ;
} ;
F_195 ( V_528 , V_529 ) ;
F_191 ( L_93 ) ;
}
}
V_10 -> V_522 ++ ;
if ( V_531 )
V_10 -> V_521 ++ ;
return F_220 ( V_531 ) ;
}
static struct V_6 * F_221 ( struct V_9 * V_10 ,
const struct V_6 * V_537 ,
const char * V_538 )
{
struct V_6 * V_7 ;
V_7 = F_222 () ;
if ( NULL == V_7 )
return NULL ;
* V_7 = * V_537 ;
V_7 -> V_501 = & V_10 -> V_11 . V_501 ;
V_7 -> V_539 = V_540 ;
V_7 -> V_541 = V_536 ;
F_223 ( V_7 , V_10 ) ;
snprintf ( V_7 -> V_308 , sizeof( V_7 -> V_308 ) , L_94 ,
V_10 -> V_17 , ( V_10 -> V_17 == 848 && V_10 -> V_542 == 0x12 ) ? L_95 : L_88 ,
V_538 , V_98 [ V_10 -> V_11 . type ] . V_308 ) ;
return V_7 ;
}
static void F_224 ( struct V_9 * V_10 )
{
if ( V_10 -> V_394 ) {
if ( F_225 ( V_10 -> V_394 ) )
F_226 ( V_10 -> V_394 ) ;
else
V_540 ( V_10 -> V_394 ) ;
V_10 -> V_394 = NULL ;
}
if ( V_10 -> V_543 ) {
if ( F_225 ( V_10 -> V_543 ) )
F_226 ( V_10 -> V_543 ) ;
else
V_540 ( V_10 -> V_543 ) ;
V_10 -> V_543 = NULL ;
}
if ( V_10 -> V_479 ) {
if ( F_225 ( V_10 -> V_479 ) )
F_226 ( V_10 -> V_479 ) ;
else
V_540 ( V_10 -> V_479 ) ;
V_10 -> V_479 = NULL ;
}
}
static int T_13 F_227 ( struct V_9 * V_10 )
{
if ( V_389 > 0 )
F_198 ( L_96 ) ;
V_10 -> V_394 = F_221 ( V_10 , & V_544 , L_97 ) ;
if ( NULL == V_10 -> V_394 )
goto V_241;
if ( F_228 ( V_10 -> V_394 , V_463 ,
V_545 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_241;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_165 ( V_10 -> V_394 ) ) ;
if ( F_229 ( & V_10 -> V_394 -> V_8 ,
& V_546 ) < 0 ) {
F_21 ( L_99 , V_10 -> V_11 . V_61 ) ;
goto V_241;
}
V_10 -> V_543 = F_221 ( V_10 , & V_544 , L_100 ) ;
if ( NULL == V_10 -> V_543 )
goto V_241;
if ( F_228 ( V_10 -> V_543 , V_464 ,
V_547 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_241;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_165 ( V_10 -> V_543 ) ) ;
if ( ! V_10 -> V_548 )
return 0 ;
V_10 -> V_479 = F_221 ( V_10 , & V_549 , L_101 ) ;
if ( NULL == V_10 -> V_479 )
goto V_241;
if ( F_228 ( V_10 -> V_479 , V_550 ,
V_551 [ V_10 -> V_11 . V_61 ] ) < 0 )
goto V_241;
F_25 ( L_98 ,
V_10 -> V_11 . V_61 , F_165 ( V_10 -> V_479 ) ) ;
return 0 ;
V_241:
F_224 ( V_10 ) ;
return - 1 ;
}
static void F_230 ( struct V_552 * V_8 )
{
#if F_231 ( V_553 )
unsigned int V_476 ;
F_232 ( V_8 , V_554 , & V_476 ) ;
V_476 = ( V_476 | V_555 ) ;
F_233 ( V_8 , V_554 , V_476 ) ;
#endif
}
static int T_13 F_234 ( struct V_552 * V_8 ,
const struct V_556 * V_557 )
{
int V_484 ;
unsigned char V_558 ;
struct V_9 * V_10 ;
if ( V_559 == V_560 )
return - V_365 ;
F_25 ( L_102 , V_559 ) ;
V_561 [ V_559 ] = V_10 = F_235 ( sizeof( * V_10 ) , V_364 ) ;
if ( V_10 == NULL ) {
F_21 ( L_103 ) ;
return - V_365 ;
}
V_10 -> V_11 . V_61 = V_559 ;
snprintf ( V_10 -> V_11 . V_501 . V_308 , sizeof( V_10 -> V_11 . V_501 . V_308 ) ,
L_104 , V_10 -> V_11 . V_61 ) ;
F_236 ( & V_10 -> V_467 ) ;
F_237 ( & V_10 -> V_163 ) ;
F_237 ( & V_10 -> V_562 ) ;
F_238 ( & V_10 -> V_535 ) ;
F_239 ( & V_10 -> V_11 . V_563 ) ;
F_239 ( & V_10 -> V_300 ) ;
F_239 ( & V_10 -> V_524 ) ;
F_240 ( & V_10 -> V_242 ) ;
F_241 ( & V_10 -> V_564 ) ;
V_10 -> V_564 . V_565 = F_207 ;
V_10 -> V_564 . V_249 = ( unsigned long ) V_10 ;
V_10 -> V_566 = - 1 ;
V_10 -> V_167 = V_12 ;
V_10 -> V_166 = V_12 ;
V_10 -> V_548 = V_567 [ V_10 -> V_11 . V_61 ] ;
V_10 -> V_11 . V_396 = V_8 ;
V_10 -> V_17 = V_8 -> V_1 ;
if ( F_242 ( V_8 ) ) {
F_197 ( L_105 , V_10 -> V_11 . V_61 ) ;
return - V_568 ;
}
if ( F_243 ( V_8 , F_244 ( 32 ) ) ) {
F_197 ( L_106 , V_10 -> V_11 . V_61 ) ;
return - V_568 ;
}
if ( ! F_245 ( F_246 ( V_8 , 0 ) ,
F_247 ( V_8 , 0 ) ,
V_10 -> V_11 . V_501 . V_308 ) ) {
F_197 ( L_107 ,
V_10 -> V_11 . V_61 ,
( unsigned long long ) F_246 ( V_8 , 0 ) ) ;
return - V_350 ;
}
F_248 ( V_8 ) ;
F_230 ( V_8 ) ;
V_484 = F_249 ( & V_8 -> V_8 , & V_10 -> V_11 . V_501 ) ;
if ( V_484 < 0 ) {
F_197 ( L_108 , V_10 -> V_11 . V_61 ) ;
goto V_569;
}
V_10 -> V_542 = V_8 -> V_542 ;
F_250 ( V_8 , V_570 , & V_558 ) ;
F_25 ( L_109 ,
V_559 , V_10 -> V_17 , V_10 -> V_542 , F_121 ( V_8 ) ,
V_10 -> V_11 . V_396 -> V_526 , V_558 ,
( unsigned long long ) F_246 ( V_8 , 0 ) ) ;
F_251 () ;
V_10 -> V_571 = F_252 ( F_246 ( V_8 , 0 ) , 0x1000 ) ;
if ( NULL == V_10 -> V_571 ) {
F_21 ( L_110 , V_10 -> V_11 . V_61 ) ;
V_484 = - V_568 ;
goto V_572;
}
F_253 ( V_10 ) ;
F_19 ( 0 , V_172 ) ;
V_484 = F_254 ( V_10 -> V_11 . V_396 -> V_526 , F_218 ,
V_573 | V_574 , V_10 -> V_11 . V_501 . V_308 , ( void * ) V_10 ) ;
if ( V_484 < 0 ) {
F_21 ( L_111 ,
V_559 , V_10 -> V_11 . V_396 -> V_526 ) ;
goto V_572;
}
if ( 0 != F_255 ( V_10 ) ) {
V_484 = - V_568 ;
goto V_575;
}
V_10 -> V_225 = V_576 ;
V_10 -> V_209 = V_577 ;
V_10 -> V_113 = V_578 ;
V_10 -> V_195 = V_579 ;
V_10 -> V_202 = V_580 ;
V_10 -> V_230 = V_581 ;
V_10 -> V_232 = V_205 ;
V_10 -> V_234 = V_207 ;
V_10 -> V_93 = V_582 ;
V_10 -> V_237 = V_583 ;
V_10 -> V_239 = V_584 ;
V_10 -> V_371 . V_10 = V_10 ;
V_10 -> V_371 . V_368 . V_353 . V_143 = 320 ;
V_10 -> V_371 . V_368 . V_353 . V_43 = 240 ;
V_10 -> V_371 . V_273 = F_66 ( V_585 ) ;
V_10 -> V_371 . V_143 = 320 ;
V_10 -> V_371 . V_43 = 240 ;
V_10 -> V_72 = 0 ;
if ( V_119 )
F_41 ( V_10 , L_112 ) ;
F_256 ( V_10 ) ;
F_58 ( V_10 ) ;
F_19 ( 0x00 , V_586 ) ;
F_19 ( 0x00 , V_250 ) ;
if ( V_63 )
F_41 ( V_10 , L_113 ) ;
F_257 ( V_10 ) ;
F_258 ( V_10 ) ;
F_259 ( V_10 ) ;
F_260 ( V_10 ) ;
F_57 ( V_10 ) ;
if ( ! V_98 [ V_10 -> V_11 . type ] . V_170 ) {
F_227 ( V_10 ) ;
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
if ( V_98 [ V_10 -> V_11 . type ] . V_587 ) {
F_261 ( & V_10 -> V_11 , L_114 ) ;
F_6 ( V_10 ) ;
}
if ( ! V_588 ) {
F_262 ( V_10 ) ;
F_263 ( V_10 ) ;
}
V_559 ++ ;
return 0 ;
V_575:
F_264 ( V_10 -> V_11 . V_396 -> V_526 , V_10 ) ;
V_572:
F_265 ( & V_10 -> V_11 . V_501 ) ;
V_569:
if ( V_10 -> V_571 )
F_266 ( V_10 -> V_571 ) ;
F_267 ( F_246 ( V_10 -> V_11 . V_396 , 0 ) ,
F_247 ( V_10 -> V_11 . V_396 , 0 ) ) ;
return V_484 ;
}
static void T_14 F_268 ( struct V_552 * V_552 )
{
struct V_589 * V_501 = F_269 ( V_552 ) ;
struct V_9 * V_10 = F_270 ( V_501 ) ;
if ( V_63 )
F_25 ( L_115 , V_10 -> V_11 . V_61 ) ;
if ( V_98 [ V_10 -> V_11 . type ] . V_587 )
F_9 ( V_10 ) ;
F_36 ( ~ 15 , V_194 ) ;
F_19 ( 0 , V_172 ) ;
F_19 ( ~ 0x0 , V_169 ) ;
F_19 ( 0x0 , V_250 ) ;
if ( V_119 )
F_41 ( V_10 , L_116 ) ;
V_10 -> V_590 = 1 ;
F_271 ( V_10 ) ;
F_272 ( & V_10 -> V_11 ) ;
F_273 ( V_10 ) ;
F_224 ( V_10 ) ;
F_274 ( V_10 -> V_11 . V_396 , & V_10 -> main ) ;
F_264 ( V_10 -> V_11 . V_396 -> V_526 , V_10 ) ;
F_266 ( V_10 -> V_571 ) ;
F_267 ( F_246 ( V_10 -> V_11 . V_396 , 0 ) ,
F_247 ( V_10 -> V_11 . V_396 , 0 ) ) ;
F_265 ( & V_10 -> V_11 . V_501 ) ;
V_561 [ V_10 -> V_11 . V_61 ] = NULL ;
F_69 ( V_10 ) ;
return;
}
static int F_275 ( struct V_552 * V_552 , T_15 V_265 )
{
struct V_589 * V_501 = F_269 ( V_552 ) ;
struct V_9 * V_10 = F_270 ( V_501 ) ;
struct V_511 V_591 ;
unsigned long V_161 ;
F_24 ( L_117 , V_10 -> V_11 . V_61 , V_265 . V_592 ) ;
F_55 ( & V_10 -> V_163 , V_161 ) ;
memset ( & V_591 , 0 , sizeof( V_591 ) ) ;
V_10 -> V_265 . V_593 = V_10 -> V_164 ;
V_10 -> V_265 . V_374 = V_10 -> V_504 ;
V_10 -> V_265 . V_268 = V_10 -> V_268 ;
V_10 -> V_164 = V_591 ;
V_10 -> V_268 = 0 ;
F_208 ( V_10 , & V_591 ) ;
F_209 ( V_10 , NULL ) ;
F_60 ( V_10 , 0 ) ;
F_19 ( 0 , V_172 ) ;
F_56 ( & V_10 -> V_163 , V_161 ) ;
V_10 -> V_265 . V_594 = F_18 ( V_250 ) ;
V_10 -> V_265 . V_595 = F_53 () ;
F_276 ( V_552 ) ;
if ( 0 != F_277 ( V_552 , F_278 ( V_552 , V_265 ) ) ) {
F_279 ( V_552 ) ;
V_10 -> V_265 . V_596 = 1 ;
}
return 0 ;
}
static int F_280 ( struct V_552 * V_552 )
{
struct V_589 * V_501 = F_269 ( V_552 ) ;
struct V_9 * V_10 = F_270 ( V_501 ) ;
unsigned long V_161 ;
int V_241 ;
F_24 ( L_118 , V_10 -> V_11 . V_61 ) ;
if ( V_10 -> V_265 . V_596 ) {
V_241 = F_242 ( V_552 ) ;
if ( V_241 ) {
F_197 ( L_105 , V_10 -> V_11 . V_61 ) ;
return V_241 ;
}
V_10 -> V_265 . V_596 = 0 ;
}
V_241 = F_277 ( V_552 , V_597 ) ;
if ( V_241 ) {
F_279 ( V_552 ) ;
F_197 ( L_105 , V_10 -> V_11 . V_61 ) ;
V_10 -> V_265 . V_596 = 1 ;
return V_241 ;
}
F_281 ( V_552 ) ;
F_59 ( V_10 ) ;
F_34 ( 0xffffff , V_10 -> V_265 . V_594 ) ;
F_282 ( V_10 -> V_265 . V_595 ) ;
F_55 ( & V_10 -> V_163 , V_161 ) ;
V_10 -> V_164 = V_10 -> V_265 . V_593 ;
V_10 -> V_504 = V_10 -> V_265 . V_374 ;
V_10 -> V_268 = V_10 -> V_265 . V_268 ;
F_208 ( V_10 , & V_10 -> V_164 ) ;
F_209 ( V_10 , V_10 -> V_504 ) ;
F_60 ( V_10 , 0 ) ;
F_56 ( & V_10 -> V_163 , V_161 ) ;
return 0 ;
}
static int T_16 F_283 ( void )
{
int V_598 ;
V_559 = 0 ;
F_25 ( L_119 , V_599 ) ;
if ( V_295 < 2 || V_295 > V_600 )
V_295 = 2 ;
if ( V_296 > V_601 )
V_296 = V_601 ;
V_296 = ( V_296 + V_602 - 1 ) & V_603 ;
if ( V_63 )
F_25 ( L_120 ,
V_295 , V_296 >> 10 , V_296 >> V_604 ) ;
F_284 () ;
V_598 = F_285 ( & V_605 ) ;
if ( V_598 < 0 ) {
F_197 ( L_121 , V_598 ) ;
return V_598 ;
}
V_598 = F_286 ( & V_606 ) ;
if ( V_598 < 0 )
F_287 ( & V_605 ) ;
return V_598 ;
}
static void T_17 F_288 ( void )
{
F_289 ( & V_606 ) ;
F_287 ( & V_605 ) ;
}
