int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( ( F_3 ( V_6 ) & V_7 ) == 0 , 1000 ) ;
if ( V_5 ) {
F_4 ( L_1 ) ;
return V_5 ;
}
F_5 ( V_8 , V_3 ) ;
F_5 ( V_6 ,
F_6 ( V_9 , V_10 ) |
F_6 ( V_11 , V_12 ) |
F_6 ( 0xf , V_13 ) ) ;
V_5 = F_2 ( ( F_3 ( V_6 ) & V_7 ) == 0 , 1000 ) ;
if ( V_5 ) {
F_4 ( L_2 ) ;
return V_5 ;
}
* V_4 = F_3 ( V_14 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
static bool V_15 = true ;
T_1 V_16 ;
if ( V_15 ) {
if ( F_1 ( V_2 , V_3 , & V_16 ) == 0 )
F_8 ( L_3 , V_3 , V_16 ) ;
F_8 ( L_4 , V_3 , V_4 ) ;
}
V_5 = F_2 ( ( F_3 ( V_6 ) & V_7 ) == 0 , 1000 ) ;
if ( V_5 ) {
F_4 ( L_5 ) ;
return V_5 ;
}
F_5 ( V_8 , V_3 ) ;
F_5 ( V_14 , V_4 ) ;
F_5 ( V_6 ,
F_6 ( V_17 , V_10 ) |
F_6 ( V_11 , V_12 ) |
F_6 ( 0xf , V_13 ) ) ;
V_5 = F_2 ( ( F_3 ( V_6 ) & V_7 ) == 0 , 1000 ) ;
if ( V_5 ) {
F_4 ( L_6 ) ;
return V_5 ;
}
if ( V_15 ) {
if ( F_1 ( V_2 , V_3 , & V_16 ) == 0 )
F_8 ( L_7 , V_3 , V_16 ) ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_18 , 0 ) ;
F_3 ( V_18 ) ;
F_5 ( V_18 , V_19 | V_20 ) ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_23 * clock , bool V_24 , T_1 V_25 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_27 = V_26 -> V_27 ;
T_1 V_28 , V_29 , V_30 ;
int V_5 = 0 ;
int V_31 = ( V_27 == 0 ) ? V_32 : V_33 ;
int V_34 = ( V_27 == 0 ) ? V_35 : V_36 ;
T_1 V_37 ;
T_1 V_38 , V_39 ;
F_9 ( V_2 ) ;
F_5 ( V_31 , V_40 | V_41 ) ;
F_12 ( 100 ) ;
V_37 = 0x68A701 ;
F_7 ( V_2 , F_13 ( V_27 ) , V_37 ) ;
V_5 = F_1 ( V_2 , V_34 , & V_37 ) ;
if ( V_5 )
return V_5 ;
V_37 &= ~ ( V_42 ) ;
if ( V_27 == 1 && ! V_24 && ! ( V_25 & V_43 ) ) {
F_8 ( L_8 ) ;
V_37 |= V_44 ;
} else {
F_8 ( L_9 ) ;
V_37 |= V_45 ;
}
V_5 = F_7 ( V_2 , V_34 , V_37 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , F_14 ( V_27 ) , & V_28 ) ;
if ( V_5 )
return V_5 ;
V_28 &= ~ V_46 ;
V_28 |= ( ( clock -> V_47 ) << V_48 ) ;
V_5 = F_7 ( V_2 , F_14 ( V_27 ) , V_28 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , F_15 ( V_27 ) , & V_29 ) ;
if ( V_5 )
return V_5 ;
V_29 &= 0xFFFF ;
V_29 |= 0x107 ;
V_29 &= ~ ( V_49 |
V_50 |
V_51 ) ;
V_29 |= ( ( clock -> V_52 ) << V_53 ) ;
if ( clock -> V_54 < 2250000 ) {
V_29 |= ( 2 << V_55 ) ;
V_29 |= ( 0 << V_56 ) ;
} else if ( clock -> V_54 < 2750000 ) {
V_29 |= ( 1 << V_55 ) ;
V_29 |= ( 1 << V_56 ) ;
} else if ( clock -> V_54 < 3300000 ) {
V_29 |= ( 0 << V_55 ) ;
V_29 |= ( 2 << V_56 ) ;
} else {
V_29 |= ( 0 << V_55 ) ;
V_29 |= ( 3 << V_56 ) ;
}
V_5 = F_7 ( V_2 , F_15 ( V_27 ) , V_29 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , F_16 ( V_27 ) , & V_30 ) ;
if ( V_5 )
return V_5 ;
V_30 &= ~ ( V_57 | V_58 ) ;
V_30 |= F_6 ( clock -> V_59 , V_60 ) ;
switch ( clock -> V_61 ) {
case 5 :
V_30 |= F_6 ( V_62 , V_63 ) ;
break;
case 10 :
V_30 |= F_6 ( V_64 , V_63 ) ;
break;
case 14 :
V_30 |= F_6 ( V_65 , V_63 ) ;
break;
case 7 :
V_30 |= F_6 ( V_66 , V_63 ) ;
break;
default:
F_4 ( L_10 , clock -> V_61 ) ;
return - V_67 ;
}
V_5 = F_7 ( V_2 , F_16 ( V_27 ) , V_30 ) ;
if ( V_5 )
return V_5 ;
if ( V_25 ) {
if ( ( V_25 & V_68 ) == V_69 ) {
V_38 = V_70 ;
F_1 ( V_2 , V_38 , & V_39 ) ;
V_39 &= ~ ( V_71 ) ;
V_39 |= V_72 | F_17 ( V_27 ) ;
F_7 ( V_2 , V_38 , V_39 ) ;
V_38 = V_73 ;
F_1 ( V_2 , V_38 , & V_39 ) ;
V_39 &= ~ ( V_71 ) ;
V_39 |= V_72 | F_17 ( V_27 ) ;
F_7 ( V_2 , V_38 , V_39 ) ;
} else {
V_38 = V_74 ;
F_1 ( V_2 , V_38 , & V_39 ) ;
V_39 &= ~ ( V_71 ) ;
V_39 |= V_72 | F_17 ( V_27 ) ;
F_7 ( V_2 , V_38 , V_39 ) ;
V_38 = V_75 ;
F_1 ( V_2 , V_38 , & V_39 ) ;
V_39 &= ~ ( V_71 ) ;
V_39 |= V_72 | F_17 ( V_27 ) ;
F_7 ( V_2 , V_38 , V_39 ) ;
}
}
return 0 ;
}
static const struct V_76 * F_18 ( struct V_21 * V_22 ,
int V_77 )
{
const struct V_76 * V_78 ;
if ( F_19 ( V_22 , V_79 ) ) {
if ( V_77 == 96000 )
V_78 = & V_80 [ V_81 ] ;
else
V_78 = & V_80 [ V_82 ] ;
} else if ( F_19 ( V_22 , V_83 ) ||
F_19 ( V_22 , V_84 ) ) {
if ( V_77 == 27000 )
V_78 = & V_80 [ V_85 ] ;
else
V_78 = & V_80 [ V_86 ] ;
} else {
if ( V_77 == 27000 )
V_78 = & V_80 [ V_87 ] ;
else
V_78 = & V_80 [ V_88 ] ;
}
return V_78 ;
}
static void F_20 ( int V_77 , struct V_23 * clock )
{
clock -> V_28 = clock -> V_47 + 2 ;
clock -> V_30 = clock -> V_59 * clock -> V_61 ;
clock -> V_54 = ( V_77 * clock -> V_28 ) / clock -> V_52 ;
clock -> V_89 = clock -> V_54 / clock -> V_30 ;
}
static bool F_21 ( const struct V_76 * V_78 ,
struct V_21 * V_22 , int V_90 ,
int V_77 ,
struct V_23 * V_91 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
struct V_23 clock ;
switch ( V_77 ) {
case 27000 :
if ( V_90 < 200000 ) {
clock . V_59 = 2 ;
clock . V_61 = 10 ;
clock . V_52 = 1 ;
clock . V_92 = 0 ;
clock . V_47 = 118 ;
} else {
clock . V_59 = 1 ;
clock . V_61 = 10 ;
clock . V_52 = 1 ;
clock . V_92 = 0 ;
clock . V_47 = 98 ;
}
break;
case 100000 :
if ( V_90 < 200000 ) {
clock . V_59 = 2 ;
clock . V_61 = 10 ;
clock . V_52 = 5 ;
clock . V_92 = 0 ;
clock . V_47 = 160 ;
} else {
clock . V_59 = 1 ;
clock . V_61 = 10 ;
clock . V_52 = 5 ;
clock . V_92 = 0 ;
clock . V_47 = 133 ;
}
break;
default:
return false ;
}
V_26 -> V_93 -> clock ( V_77 , & clock ) ;
memcpy ( V_91 , & clock , sizeof( struct V_23 ) ) ;
return true ;
}
static bool F_22 ( struct V_1 * V_2 , int V_27 )
{
struct V_21 * V_22 ;
struct V_94 * V_95 = V_2 -> V_96 ;
struct V_26 * V_26 = NULL ;
V_22 = V_95 -> V_97 [ V_27 ] ;
V_26 = F_11 ( V_22 ) ;
if ( V_22 -> V_98 -> V_99 == NULL || ! V_26 -> V_100 )
return false ;
return true ;
}
void F_23 ( struct V_1 * V_2 )
{
if ( F_3 ( V_101 ) & V_102 ) {
F_5 ( V_101 , ( F_3 ( V_101 ) & ~ V_102 ) ) ;
F_3 ( V_101 ) ;
F_24 ( V_2 ) ;
F_5 ( V_103 , 0 ) ;
F_3 ( V_103 ) ;
F_24 ( V_2 ) ;
}
}
void F_25 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_94 * V_95 = V_2 -> V_96 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
if ( F_22 ( V_2 , 0 ) ^ F_22 ( V_2 , 1 ) ) {
T_1 V_104 ;
V_104 = F_3 ( V_105 ) ;
V_104 &= ~ V_106 ;
V_104 |= ( 0x7e << V_107 ) ;
V_104 &= ~ V_108 ;
V_104 |= ( 0x4 << V_109 ) ;
F_5 ( V_105 , V_104 ) ;
V_104 = F_3 ( V_110 ) ;
V_104 &= ~ V_111 ;
V_104 |= ( 0x6 << V_112 ) ;
V_104 &= ~ V_113 ;
V_104 |= ( 0x8 << V_114 ) ;
F_5 ( V_110 , V_104 ) ;
F_5 ( V_115 , 0x36000000 ) ;
if ( V_26 -> V_27 == 1 &&
F_19 ( V_22 , V_79 ) ) {
F_5 ( V_116 , 0x00040330 ) ;
} else {
V_104 = ( 3 << V_117 ) |
( 4 << V_118 ) |
( 3 << V_119 ) |
( 4 << V_120 ) ;
F_5 ( V_116 , V_104 ) ;
}
F_5 ( V_121 , 0x10 ) ;
F_24 ( V_2 ) ;
F_5 ( V_101 , V_102 ) ;
F_3 ( V_101 ) ;
F_24 ( V_2 ) ;
} else {
F_5 ( V_105 , 0x3f880808 ) ;
F_5 ( V_110 , 0x0b020202 ) ;
F_5 ( V_115 , 0x24000000 ) ;
F_5 ( V_122 , 0x08030202 ) ;
F_5 ( V_116 , 0x01010101 ) ;
F_5 ( V_121 , 0x1d0 ) ;
F_24 ( V_2 ) ;
V_95 -> V_123 -> V_124 ( V_2 ) ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
T_1 V_125 ;
V_125 = F_3 ( V_126 ) ;
if ( ( V_125 & V_127 ) == 0 )
return - 1 ;
return ( V_125 >> 29 ) & 0x3 ;
}
static int F_27 ( struct V_21 * V_22 ,
struct V_128 * V_129 ,
struct V_128 * V_130 ,
int V_131 , int V_132 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_94 * V_95 = V_2 -> V_96 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_27 = V_26 -> V_27 ;
const struct V_135 * V_136 = & V_95 -> V_137 [ V_27 ] ;
int V_77 ;
struct V_23 clock ;
T_1 V_138 = 0 , V_139 , V_140 ;
bool V_141 ;
bool V_142 = false , V_24 = false , V_143 = false ;
bool V_144 = false , V_145 = false ;
struct V_146 * V_147 = & V_2 -> V_147 ;
struct V_148 * V_149 ;
const struct V_76 * V_78 ;
T_1 V_25 = 0 ;
bool V_150 = false ;
F_28 (connector, &mode_config->connector_list, head) {
struct V_151 * V_151 =
F_29 ( V_149 ) ;
if ( ! V_149 -> V_152
|| V_149 -> V_152 -> V_22 != V_22 )
continue;
V_25 = V_151 -> V_25 ;
switch ( V_151 -> type ) {
case V_79 :
V_24 = true ;
break;
case V_153 :
V_143 = true ;
break;
case V_154 :
V_142 = true ;
break;
case V_155 :
V_144 = true ;
break;
case V_83 :
V_145 = true ;
break;
case V_84 :
V_150 = true ;
break;
default:
F_4 ( L_11 ) ;
return 0 ;
}
}
if ( V_95 -> V_156 )
V_77 = 96000 ;
else
V_77 = 27000 ;
if ( V_145 || V_150 ) {
if ( V_27 == 0 )
V_77 = 27000 ;
else
V_77 = 100000 ;
}
if ( V_24 && V_95 -> V_157 ) {
V_77 = V_95 -> V_158 * 1000 ;
F_8 ( L_12 , V_95 -> V_158 ) ;
}
F_30 ( V_130 ) ;
V_78 = V_26 -> V_93 -> V_78 ( V_22 , V_77 ) ;
V_141 = V_78 -> V_159 ( V_78 , V_22 , V_130 -> clock , V_77 ,
& clock ) ;
if ( ! V_141 ) {
F_4 ( L_13 ,
V_130 -> clock , clock . V_89 ) ;
return 0 ;
}
V_138 = V_41 ;
if ( V_143 ) {
V_138 |= 3 ;
}
if ( V_145 || V_150 ) {
F_31 ( V_22 , V_129 , V_130 ) ;
} else {
F_5 ( F_32 ( V_27 ) , 0 ) ;
F_5 ( F_33 ( V_27 ) , 0 ) ;
F_5 ( F_34 ( V_27 ) , 0 ) ;
F_5 ( F_35 ( V_27 ) , 0 ) ;
}
V_138 |= V_40 ;
V_140 = F_3 ( V_136 -> V_160 ) ;
V_140 &= ~ ( V_161 ) ;
if ( V_150 ) {
switch ( V_95 -> V_162 . V_163 ) {
case 24 :
V_140 |= V_164 ;
break;
case 18 :
V_140 |= V_165 ;
break;
case 30 :
V_140 |= V_166 ;
break;
default:
V_140 |= V_164 ;
break;
}
} else if ( V_24 ) {
if ( ( F_3 ( V_167 ) & V_168 ) == V_169 )
V_140 |= V_164 ;
else
V_140 |= V_165 ;
} else
V_140 |= V_164 ;
V_139 = V_170 ;
if ( V_27 == 0 )
V_139 |= V_171 ;
else
V_139 |= V_172 ;
V_139 |= V_173 ;
V_140 |= V_174 ;
F_5 ( V_136 -> V_138 , V_138 | V_41 | V_40 ) ;
F_3 ( V_136 -> V_138 ) ;
F_10 ( V_2 , V_22 , & clock , V_24 , V_25 ) ;
F_12 ( 150 ) ;
if ( V_24 ) {
T_1 V_175 = F_3 ( V_167 ) ;
V_175 |=
V_176 | V_177 |
V_178 ;
if ( clock . V_61 == 7 )
V_175 |= V_179 | V_180 ;
else
V_175 &= ~ ( V_179 | V_180 ) ;
F_5 ( V_167 , V_175 ) ;
F_3 ( V_167 ) ;
}
V_138 |= V_181 ;
if ( F_26 ( V_2 ) == V_27 )
F_5 ( V_126 , 0 ) ;
F_8 ( L_14 , V_27 == 0 ? 'A' : 'B' ) ;
F_30 ( V_129 ) ;
F_5 ( V_136 -> V_138 ,
( F_3 ( V_136 -> V_138 ) & ~ V_182 ) | V_181 ) ;
F_3 ( V_136 -> V_138 ) ;
F_12 ( 150 ) ;
if ( ! ( F_3 ( V_136 -> V_138 ) & V_182 ) ) {
F_36 ( V_2 -> V_2 , L_15 ) ;
return - V_183 ;
}
{
int V_184 = V_130 -> clock / V_129 -> clock ;
F_5 ( V_136 -> V_185 , ( 0 << V_186 ) | ( ( V_184 - 1 ) << V_187 ) ) ;
}
F_5 ( V_136 -> V_188 , ( V_130 -> V_189 - 1 ) |
( ( V_130 -> V_190 - 1 ) << 16 ) ) ;
F_5 ( V_136 -> V_191 , ( V_130 -> V_192 - 1 ) |
( ( V_130 -> V_193 - 1 ) << 16 ) ) ;
F_5 ( V_136 -> V_194 , ( V_130 -> V_195 - 1 ) |
( ( V_130 -> V_196 - 1 ) << 16 ) ) ;
F_5 ( V_136 -> V_197 , ( V_130 -> V_198 - 1 ) |
( ( V_130 -> V_199 - 1 ) << 16 ) ) ;
F_5 ( V_136 -> V_200 , ( V_130 -> V_201 - 1 ) |
( ( V_130 -> V_202 - 1 ) << 16 ) ) ;
F_5 ( V_136 -> V_203 , ( V_130 -> V_204 - 1 ) |
( ( V_130 -> V_205 - 1 ) << 16 ) ) ;
F_5 ( V_136 -> V_206 ,
( ( V_129 -> V_207 - 1 ) << 16 ) | ( V_129 -> V_208 - 1 ) ) ;
F_5 ( V_136 -> V_209 , 0 ) ;
F_5 ( V_136 -> V_210 ,
( ( V_129 -> V_208 - 1 ) << 16 ) | ( V_129 -> V_207 - 1 ) ) ;
F_5 ( V_136 -> V_160 , V_140 ) ;
F_3 ( V_136 -> V_160 ) ;
F_24 ( V_2 ) ;
F_5 ( V_136 -> V_211 , V_139 ) ;
{
struct V_212 * V_213 =
V_22 -> V_214 ;
V_213 -> V_215 ( V_22 , V_131 , V_132 , V_134 ) ;
}
F_24 ( V_2 ) ;
return 0 ;
}
static void F_37 ( int V_77 , struct V_23 * clock )
{
clock -> V_28 = 5 * ( clock -> V_92 + 2 ) + ( clock -> V_47 + 2 ) ;
clock -> V_30 = clock -> V_59 * clock -> V_61 ;
clock -> V_54 = V_77 * clock -> V_28 / ( clock -> V_52 + 2 ) ;
clock -> V_89 = clock -> V_54 / clock -> V_30 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_94 * V_95 = V_2 -> V_96 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_27 = V_26 -> V_27 ;
const struct V_135 * V_136 = & V_95 -> V_137 [ V_27 ] ;
T_1 V_138 ;
T_1 V_216 ;
struct V_23 clock ;
bool V_24 ;
struct V_217 * V_30 = & V_95 -> V_218 . V_27 [ V_27 ] ;
if ( F_39 ( V_2 , false ) ) {
V_138 = F_3 ( V_136 -> V_138 ) ;
if ( ( V_138 & V_219 ) == 0 )
V_216 = F_3 ( V_136 -> V_220 ) ;
else
V_216 = F_3 ( V_136 -> V_221 ) ;
V_24 = ( V_27 == 1 ) && ( F_3 ( V_167 ) & V_176 ) ;
F_40 ( V_2 ) ;
} else {
V_138 = V_30 -> V_138 ;
if ( ( V_138 & V_219 ) == 0 )
V_216 = V_30 -> V_220 ;
else
V_216 = V_30 -> V_221 ;
V_24 = ( V_27 == 1 ) &&
( V_95 -> V_218 . V_222 . V_223 & V_176 ) ;
}
clock . V_92 = ( V_216 & V_224 ) >> V_225 ;
clock . V_47 = ( V_216 & V_226 ) >> V_227 ;
clock . V_52 = ( V_216 & V_228 ) >> V_229 ;
if ( V_24 ) {
clock . V_59 =
F_41 ( ( V_138 &
V_230 ) >>
V_231 ) ;
if ( clock . V_59 == 0 ) {
clock . V_59 = 4 ;
F_36 ( V_2 -> V_2 , L_16 , V_138 ) ;
}
clock . V_61 = 14 ;
if ( ( V_138 & V_232 ) ==
V_233 ) {
F_37 ( 66000 , & clock ) ;
} else
F_37 ( 48000 , & clock ) ;
} else {
if ( V_138 & V_234 )
clock . V_59 = 2 ;
else {
clock . V_59 =
( ( V_138 &
V_235 ) >>
V_231 ) + 2 ;
}
if ( V_138 & V_236 )
clock . V_61 = 4 ;
else
clock . V_61 = 2 ;
F_37 ( 48000 , & clock ) ;
}
return clock . V_89 ;
}
struct V_128 * F_42 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_27 = V_26 -> V_27 ;
struct V_94 * V_95 = V_2 -> V_96 ;
struct V_217 * V_30 = & V_95 -> V_218 . V_27 [ V_27 ] ;
const struct V_135 * V_136 = & V_95 -> V_137 [ V_27 ] ;
struct V_128 * V_129 ;
int V_237 ;
int V_194 ;
int V_238 ;
int V_203 ;
if ( F_39 ( V_2 , false ) ) {
V_237 = F_3 ( V_136 -> V_188 ) ;
V_194 = F_3 ( V_136 -> V_194 ) ;
V_238 = F_3 ( V_136 -> V_197 ) ;
V_203 = F_3 ( V_136 -> V_203 ) ;
F_40 ( V_2 ) ;
} else {
V_237 = V_30 -> V_188 ;
V_194 = V_30 -> V_194 ;
V_238 = V_30 -> V_197 ;
V_203 = V_30 -> V_203 ;
}
V_129 = F_43 ( sizeof( * V_129 ) , V_239 ) ;
if ( ! V_129 )
return NULL ;
V_129 -> clock = F_38 ( V_2 , V_22 ) ;
V_129 -> V_208 = ( V_237 & 0xffff ) + 1 ;
V_129 -> V_188 = ( ( V_237 & 0xffff0000 ) >> 16 ) + 1 ;
V_129 -> V_240 = ( V_194 & 0xffff ) + 1 ;
V_129 -> V_241 = ( ( V_194 & 0xffff0000 ) >> 16 ) + 1 ;
V_129 -> V_207 = ( V_238 & 0xffff ) + 1 ;
V_129 -> V_197 = ( ( V_238 & 0xffff0000 ) >> 16 ) + 1 ;
V_129 -> V_242 = ( V_203 & 0xffff ) + 1 ;
V_129 -> V_243 = ( ( V_203 & 0xffff0000 ) >> 16 ) + 1 ;
F_44 ( V_129 ) ;
F_45 ( V_129 , 0 ) ;
return V_129 ;
}
