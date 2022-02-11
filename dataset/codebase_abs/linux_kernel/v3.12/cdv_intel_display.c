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
struct V_23 clock ;
if ( V_77 == 27000 ) {
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
} else if ( V_77 == 100000 ) {
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
} else
return false ;
clock . V_28 = clock . V_47 + 2 ;
clock . V_30 = clock . V_59 * clock . V_61 ;
clock . V_54 = ( V_77 * clock . V_28 ) / clock . V_52 ;
clock . V_89 = clock . V_54 / clock . V_30 ;
memcpy ( V_91 , & clock , sizeof( struct V_23 ) ) ;
return true ;
}
static bool F_22 ( struct V_1 * V_2 , int V_27 )
{
struct V_21 * V_22 ;
struct V_93 * V_94 = V_2 -> V_95 ;
struct V_26 * V_26 = NULL ;
V_22 = V_94 -> V_96 [ V_27 ] ;
V_26 = F_11 ( V_22 ) ;
if ( V_22 -> V_97 == NULL || ! V_26 -> V_98 )
return false ;
return true ;
}
static bool F_23 ( struct V_1 * V_2 )
{
T_2 V_99 = 0 ;
if ( F_22 ( V_2 , 0 ) )
V_99 |= V_100 ;
if ( F_22 ( V_2 , 1 ) )
V_99 |= V_101 ;
F_8 ( L_11 , V_99 ) ;
if ( V_99 == V_100 || V_99 == V_101 )
return true ;
else
return false ;
}
static bool F_24 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
struct V_102 * V_103 = & V_2 -> V_103 ;
struct V_104 * V_105 ;
if ( V_26 -> V_27 != 1 )
return false ;
F_25 (connector, &mode_config->connector_list, head) {
struct V_106 * V_106 =
F_26 ( V_105 ) ;
if ( ! V_105 -> V_107
|| V_105 -> V_107 -> V_22 != V_22 )
continue;
if ( V_106 -> type == V_79 )
return true ;
}
return false ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( F_3 ( V_108 ) & V_109 ) {
F_5 ( V_108 , ( F_3 ( V_108 ) & ~ V_109 ) ) ;
F_3 ( V_108 ) ;
F_28 ( V_2 ) ;
F_5 ( V_110 , 0 ) ;
F_3 ( V_110 ) ;
F_28 ( V_2 ) ;
}
}
void F_29 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_93 * V_94 = V_2 -> V_95 ;
if ( F_23 ( V_2 ) ) {
T_1 V_111 ;
V_111 = F_3 ( V_112 ) ;
V_111 &= ~ V_113 ;
V_111 |= ( 0x7e << V_114 ) ;
V_111 &= ~ V_115 ;
V_111 |= ( 0x4 << V_116 ) ;
F_5 ( V_112 , V_111 ) ;
V_111 = F_3 ( V_117 ) ;
V_111 &= ~ V_118 ;
V_111 |= ( 0x6 << V_119 ) ;
V_111 &= ~ V_120 ;
V_111 |= ( 0x8 << V_121 ) ;
F_5 ( V_117 , V_111 ) ;
F_5 ( V_122 , 0x36000000 ) ;
if ( F_24 ( V_2 , V_22 ) ) {
F_5 ( V_123 , 0x00040330 ) ;
} else {
V_111 = ( 3 << V_124 ) |
( 4 << V_125 ) |
( 3 << V_126 ) |
( 4 << V_127 ) ;
F_5 ( V_123 , V_111 ) ;
}
F_5 ( V_128 , 0x10 ) ;
F_28 ( V_2 ) ;
F_5 ( V_108 , V_109 ) ;
F_3 ( V_108 ) ;
F_28 ( V_2 ) ;
} else {
F_5 ( V_112 , 0x3f880808 ) ;
F_5 ( V_117 , 0x0b020202 ) ;
F_5 ( V_122 , 0x24000000 ) ;
F_5 ( V_129 , 0x08030202 ) ;
F_5 ( V_123 , 0x01010101 ) ;
F_5 ( V_128 , 0x1d0 ) ;
F_28 ( V_2 ) ;
V_94 -> V_130 -> V_131 ( V_2 ) ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_132 ;
V_132 = F_3 ( V_133 ) ;
if ( ( V_132 & V_134 ) == 0 )
return - 1 ;
return ( V_132 >> 29 ) & 0x3 ;
}
static int F_31 ( struct V_21 * V_22 ,
struct V_135 * V_136 ,
struct V_135 * V_137 ,
int V_138 , int V_139 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_93 * V_94 = V_2 -> V_95 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_27 = V_26 -> V_27 ;
const struct V_142 * V_143 = & V_94 -> V_144 [ V_27 ] ;
int V_77 ;
struct V_23 clock ;
T_1 V_145 = 0 , V_146 , V_147 ;
bool V_148 ;
bool V_149 = false , V_24 = false , V_150 = false ;
bool V_151 = false , V_152 = false ;
struct V_102 * V_103 = & V_2 -> V_103 ;
struct V_104 * V_105 ;
const struct V_76 * V_78 ;
T_1 V_25 = 0 ;
bool V_153 = false ;
F_25 (connector, &mode_config->connector_list, head) {
struct V_106 * V_106 =
F_26 ( V_105 ) ;
if ( ! V_105 -> V_107
|| V_105 -> V_107 -> V_22 != V_22 )
continue;
V_25 = V_106 -> V_25 ;
switch ( V_106 -> type ) {
case V_79 :
V_24 = true ;
break;
case V_154 :
V_150 = true ;
break;
case V_155 :
V_149 = true ;
break;
case V_156 :
V_151 = true ;
break;
case V_83 :
V_152 = true ;
break;
case V_84 :
V_153 = true ;
break;
default:
F_4 ( L_12 ) ;
return 0 ;
}
}
if ( V_94 -> V_157 )
V_77 = 96000 ;
else
V_77 = 27000 ;
if ( V_152 || V_153 ) {
if ( V_27 == 0 )
V_77 = 27000 ;
else
V_77 = 100000 ;
}
if ( V_24 && V_94 -> V_158 ) {
V_77 = V_94 -> V_159 * 1000 ;
F_8 ( L_13 , V_94 -> V_159 ) ;
}
F_32 ( V_137 ) ;
V_78 = V_26 -> V_160 -> V_78 ( V_22 , V_77 ) ;
V_148 = V_78 -> V_161 ( V_78 , V_22 , V_137 -> clock , V_77 ,
& clock ) ;
if ( ! V_148 ) {
F_4 ( L_14 ,
V_137 -> clock , clock . V_89 ) ;
return 0 ;
}
V_145 = V_41 ;
if ( V_150 ) {
V_145 |= 3 ;
}
if ( V_152 || V_153 ) {
F_33 ( V_22 , V_136 , V_137 ) ;
} else {
F_5 ( F_34 ( V_27 ) , 0 ) ;
F_5 ( F_35 ( V_27 ) , 0 ) ;
F_5 ( F_36 ( V_27 ) , 0 ) ;
F_5 ( F_37 ( V_27 ) , 0 ) ;
}
V_145 |= V_40 ;
V_147 = F_3 ( V_143 -> V_162 ) ;
V_147 &= ~ ( V_163 ) ;
if ( V_153 ) {
switch ( V_94 -> V_164 . V_165 ) {
case 24 :
V_147 |= V_166 ;
break;
case 18 :
V_147 |= V_167 ;
break;
case 30 :
V_147 |= V_168 ;
break;
default:
V_147 |= V_166 ;
break;
}
} else if ( V_24 ) {
if ( ( F_3 ( V_169 ) & V_170 ) == V_171 )
V_147 |= V_166 ;
else
V_147 |= V_167 ;
} else
V_147 |= V_166 ;
V_146 = V_172 ;
if ( V_27 == 0 )
V_146 |= V_173 ;
else
V_146 |= V_174 ;
V_146 |= V_175 ;
V_147 |= V_176 ;
F_5 ( V_143 -> V_145 , V_145 | V_41 | V_40 ) ;
F_3 ( V_143 -> V_145 ) ;
F_10 ( V_2 , V_22 , & clock , V_24 , V_25 ) ;
F_12 ( 150 ) ;
if ( V_24 ) {
T_1 V_177 = F_3 ( V_169 ) ;
V_177 |=
V_178 | V_179 |
V_180 ;
if ( clock . V_61 == 7 )
V_177 |= V_181 | V_182 ;
else
V_177 &= ~ ( V_181 | V_182 ) ;
F_5 ( V_169 , V_177 ) ;
F_3 ( V_169 ) ;
}
V_145 |= V_183 ;
if ( F_30 ( V_2 ) == V_27 )
F_5 ( V_133 , 0 ) ;
F_8 ( L_15 , V_27 == 0 ? 'A' : 'B' ) ;
F_32 ( V_136 ) ;
F_5 ( V_143 -> V_145 ,
( F_3 ( V_143 -> V_145 ) & ~ V_184 ) | V_183 ) ;
F_3 ( V_143 -> V_145 ) ;
F_12 ( 150 ) ;
if ( ! ( F_3 ( V_143 -> V_145 ) & V_184 ) ) {
F_38 ( V_2 -> V_2 , L_16 ) ;
return - V_185 ;
}
{
int V_186 = V_137 -> clock / V_136 -> clock ;
F_5 ( V_143 -> V_187 , ( 0 << V_188 ) | ( ( V_186 - 1 ) << V_189 ) ) ;
}
F_5 ( V_143 -> V_190 , ( V_137 -> V_191 - 1 ) |
( ( V_137 -> V_192 - 1 ) << 16 ) ) ;
F_5 ( V_143 -> V_193 , ( V_137 -> V_194 - 1 ) |
( ( V_137 -> V_195 - 1 ) << 16 ) ) ;
F_5 ( V_143 -> V_196 , ( V_137 -> V_197 - 1 ) |
( ( V_137 -> V_198 - 1 ) << 16 ) ) ;
F_5 ( V_143 -> V_199 , ( V_137 -> V_200 - 1 ) |
( ( V_137 -> V_201 - 1 ) << 16 ) ) ;
F_5 ( V_143 -> V_202 , ( V_137 -> V_203 - 1 ) |
( ( V_137 -> V_204 - 1 ) << 16 ) ) ;
F_5 ( V_143 -> V_205 , ( V_137 -> V_206 - 1 ) |
( ( V_137 -> V_207 - 1 ) << 16 ) ) ;
F_5 ( V_143 -> V_208 ,
( ( V_136 -> V_209 - 1 ) << 16 ) | ( V_136 -> V_210 - 1 ) ) ;
F_5 ( V_143 -> V_211 , 0 ) ;
F_5 ( V_143 -> V_212 ,
( ( V_136 -> V_210 - 1 ) << 16 ) | ( V_136 -> V_209 - 1 ) ) ;
F_5 ( V_143 -> V_162 , V_147 ) ;
F_3 ( V_143 -> V_162 ) ;
F_28 ( V_2 ) ;
F_5 ( V_143 -> V_213 , V_146 ) ;
{
struct V_214 * V_215 =
V_22 -> V_216 ;
V_215 -> V_217 ( V_22 , V_138 , V_139 , V_141 ) ;
}
F_28 ( V_2 ) ;
return 0 ;
}
static void F_39 ( int V_77 , struct V_23 * clock )
{
clock -> V_28 = 5 * ( clock -> V_92 + 2 ) + ( clock -> V_47 + 2 ) ;
clock -> V_30 = clock -> V_59 * clock -> V_61 ;
clock -> V_54 = V_77 * clock -> V_28 / ( clock -> V_52 + 2 ) ;
clock -> V_89 = clock -> V_54 / clock -> V_30 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_93 * V_94 = V_2 -> V_95 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_27 = V_26 -> V_27 ;
const struct V_142 * V_143 = & V_94 -> V_144 [ V_27 ] ;
T_1 V_145 ;
T_1 V_218 ;
struct V_23 clock ;
bool V_24 ;
struct V_219 * V_30 = & V_94 -> V_220 . V_27 [ V_27 ] ;
if ( F_41 ( V_2 , false ) ) {
V_145 = F_3 ( V_143 -> V_145 ) ;
if ( ( V_145 & V_221 ) == 0 )
V_218 = F_3 ( V_143 -> V_222 ) ;
else
V_218 = F_3 ( V_143 -> V_223 ) ;
V_24 = ( V_27 == 1 ) && ( F_3 ( V_169 ) & V_178 ) ;
F_42 ( V_2 ) ;
} else {
V_145 = V_30 -> V_145 ;
if ( ( V_145 & V_221 ) == 0 )
V_218 = V_30 -> V_222 ;
else
V_218 = V_30 -> V_223 ;
V_24 = ( V_27 == 1 ) &&
( V_94 -> V_220 . V_224 . V_225 & V_178 ) ;
}
clock . V_92 = ( V_218 & V_226 ) >> V_227 ;
clock . V_47 = ( V_218 & V_228 ) >> V_229 ;
clock . V_52 = ( V_218 & V_230 ) >> V_231 ;
if ( V_24 ) {
clock . V_59 =
F_43 ( ( V_145 &
V_232 ) >>
V_233 ) ;
if ( clock . V_59 == 0 ) {
clock . V_59 = 4 ;
F_38 ( V_2 -> V_2 , L_17 , V_145 ) ;
}
clock . V_61 = 14 ;
if ( ( V_145 & V_234 ) ==
V_235 ) {
F_39 ( 66000 , & clock ) ;
} else
F_39 ( 48000 , & clock ) ;
} else {
if ( V_145 & V_236 )
clock . V_59 = 2 ;
else {
clock . V_59 =
( ( V_145 &
V_237 ) >>
V_233 ) + 2 ;
}
if ( V_145 & V_238 )
clock . V_61 = 4 ;
else
clock . V_61 = 2 ;
F_39 ( 48000 , & clock ) ;
}
return clock . V_89 ;
}
struct V_135 * F_44 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_27 = V_26 -> V_27 ;
struct V_93 * V_94 = V_2 -> V_95 ;
struct V_219 * V_30 = & V_94 -> V_220 . V_27 [ V_27 ] ;
const struct V_142 * V_143 = & V_94 -> V_144 [ V_27 ] ;
struct V_135 * V_136 ;
int V_239 ;
int V_196 ;
int V_240 ;
int V_205 ;
if ( F_41 ( V_2 , false ) ) {
V_239 = F_3 ( V_143 -> V_190 ) ;
V_196 = F_3 ( V_143 -> V_196 ) ;
V_240 = F_3 ( V_143 -> V_199 ) ;
V_205 = F_3 ( V_143 -> V_205 ) ;
F_42 ( V_2 ) ;
} else {
V_239 = V_30 -> V_190 ;
V_196 = V_30 -> V_196 ;
V_240 = V_30 -> V_199 ;
V_205 = V_30 -> V_205 ;
}
V_136 = F_45 ( sizeof( * V_136 ) , V_241 ) ;
if ( ! V_136 )
return NULL ;
V_136 -> clock = F_40 ( V_2 , V_22 ) ;
V_136 -> V_210 = ( V_239 & 0xffff ) + 1 ;
V_136 -> V_190 = ( ( V_239 & 0xffff0000 ) >> 16 ) + 1 ;
V_136 -> V_242 = ( V_196 & 0xffff ) + 1 ;
V_136 -> V_243 = ( ( V_196 & 0xffff0000 ) >> 16 ) + 1 ;
V_136 -> V_209 = ( V_240 & 0xffff ) + 1 ;
V_136 -> V_199 = ( ( V_240 & 0xffff0000 ) >> 16 ) + 1 ;
V_136 -> V_244 = ( V_205 & 0xffff ) + 1 ;
V_136 -> V_245 = ( ( V_205 & 0xffff0000 ) >> 16 ) + 1 ;
F_46 ( V_136 ) ;
F_47 ( V_136 , 0 ) ;
return V_136 ;
}
