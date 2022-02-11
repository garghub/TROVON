static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
void T_2 * V_7 = V_2 -> V_4 + V_3 ;
F_4 ( F_2 ( V_7 ) | V_6 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
void T_2 * V_7 = V_2 -> V_4 + V_3 ;
F_4 ( F_2 ( V_7 ) & ~ V_6 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 , V_9 ) ;
if ( F_8 ( V_8 ) )
F_6 ( V_2 , V_10 , V_11 ) ;
F_5 ( V_2 , V_12 , V_13 ) ;
F_6 ( V_2 , V_14 ,
V_15 | V_16 ) ;
F_5 ( V_2 , V_17 , V_18 ) ;
F_6 ( V_2 , V_17 , V_18 ) ;
F_3 ( V_2 , 0x0 , V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 -> V_20 , V_21 ,
V_22 ,
V_2 -> V_23 << V_24 ) ;
}
static void F_11 ( struct V_1 * V_2 , enum V_25 V_26 )
{
T_1 V_8 ;
F_12 ( L_1 , V_26 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
V_8 &= ~ ( V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 ) ;
switch ( V_26 ) {
case V_33 :
V_8 |= ( V_34 |
V_35 ) ;
break;
case V_36 :
V_8 |= ( V_37 |
V_35 ) ;
break;
case V_38 :
default:
V_8 |= ( V_39 |
V_34 |
V_40 |
V_41 ) ;
break;
}
F_3 ( V_2 , V_8 , V_17 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
T_1 V_8 ;
F_12 ( L_2 ,
V_43 -> V_44 , V_43 -> V_45 ) ;
F_12 ( L_3 ,
V_43 -> V_46 , V_43 -> V_47 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
V_8 &= ~ ( V_48 | V_49 |
V_50 | V_51 ) ;
if ( V_43 -> V_44 )
V_8 |= V_48 ;
if ( V_43 -> V_45 )
V_8 |= V_49 ;
if ( V_43 -> V_46 )
V_8 |= V_50 ;
if ( V_43 -> V_47 )
V_8 |= V_51 ;
F_3 ( V_2 , V_8 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 , bool V_52 )
{
T_1 V_8 ;
F_12 ( L_4 , V_52 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
if ( V_52 )
V_8 |= V_53 ;
else
V_8 &= ~ V_53 ;
F_3 ( V_2 , V_8 , V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_52 )
{
T_1 V_8 ;
F_12 ( L_4 , V_52 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
if ( V_52 ) {
V_8 &= ~ V_54 ;
V_8 |= V_55 | V_56 ;
} else
V_8 &= ~ V_55 ;
F_3 ( V_2 , V_8 , V_17 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_17 , V_57 ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_60 , V_61 ;
V_60 = F_1 ( V_2 , V_9 ) ;
V_61 = V_62 | V_63 |
V_64 ;
F_12 ( L_5 , V_61 ) ;
if ( V_60 & V_61 ) {
F_5 ( V_2 , V_65 ,
V_66 | V_67 |
V_68 ) ;
F_18 ( V_59 -> V_69 , L_6 ,
V_2 -> V_23 , V_60 ) ;
return true ;
}
return false ;
}
static bool F_19 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 , V_9 ) ;
F_12 ( L_7 , V_8 ) ;
if ( ! ( V_8 & V_70 ) )
return false ;
V_8 &= ~ ( V_70 ) ;
F_3 ( V_2 , V_8 , V_9 ) ;
return true ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_8 ;
int V_71 , V_72 ;
V_8 = F_1 ( V_2 , V_73 ) ;
V_71 = F_21 ( V_8 ) ;
if ( V_71 == 0 )
V_71 = F_22 ( V_8 ) ;
F_12 ( L_8 ,
F_22 ( V_8 ) ,
F_21 ( V_8 ) ) ;
if ( V_71 == 0 ) {
F_23 ( L_9 ) ;
return - V_74 ;
}
V_72 = V_71 - 1 ;
F_12 ( L_10 , V_72 ) ;
return V_72 ;
}
static void F_24 ( struct V_1 * V_2 , bool V_52 )
{
T_1 V_8 ;
F_12 ( L_4 , V_52 ) ;
V_8 = F_1 ( V_2 , V_75 ) ;
if ( V_52 )
V_8 |= V_76 ;
else
V_8 &= ~ V_76 ;
F_3 ( V_2 , V_8 , V_75 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_77 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_11 , V_77 ) ;
V_8 = F_1 ( V_2 , V_78 ) ;
V_8 &= ~ V_79 ;
switch ( V_77 ) {
case V_80 :
V_8 |= V_81 ;
F_3 ( V_2 , V_8 , V_78 ) ;
return 0 ;
case V_82 :
case V_83 :
V_8 |= V_84 ;
F_3 ( V_2 , V_8 , V_78 ) ;
return 0 ;
default:
break;
}
V_8 = F_1 ( V_2 , V_10 ) ;
V_8 &= ~ ( V_85 |
V_86 |
V_87 ) ;
switch ( V_77 ) {
case V_88 :
V_8 |= V_87 ;
break;
case V_89 :
V_8 |= V_90 ;
break;
case V_91 :
V_8 |= V_92 ;
break;
case V_93 :
case V_94 :
V_8 |= V_95 ;
break;
case V_96 :
case V_97 :
V_8 |= ( V_98 |
V_86 ) ;
break;
case V_99 :
case V_100 :
case V_101 :
V_8 |= V_102 ;
break;
case V_103 :
case V_104 :
V_8 |= ( V_105 |
V_86 ) ;
break;
default:
F_18 ( V_59 -> V_69 , L_12 , V_77 ) ;
return - V_106 ;
}
F_3 ( V_2 , V_8 , V_10 ) ;
return 0 ;
}
static int F_26 ( struct V_107 * V_69 , T_1 V_77 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_11 , V_77 ) ;
V_8 = F_1 ( V_2 , V_10 ) ;
V_8 &= ~ V_108 ;
switch ( V_77 ) {
case V_80 :
case V_82 :
case V_83 :
V_8 |= V_108 ;
break;
case V_94 :
V_8 |= V_109 ;
break;
case V_88 :
case V_89 :
case V_91 :
case V_93 :
V_8 |= V_110 ;
break;
case V_104 :
case V_97 :
case V_99 :
V_8 |= V_111 ;
break;
case V_100 :
case V_101 :
case V_103 :
case V_96 :
V_8 |= V_109 ;
break;
default:
F_18 ( V_59 -> V_69 , L_13 , V_77 ) ;
return - V_106 ;
}
F_3 ( V_2 , V_8 , V_10 ) ;
V_8 = F_1 ( V_2 , V_112 ) ;
V_8 &= ~ V_113 ;
V_8 |= V_114 ;
F_3 ( V_2 , V_8 , V_112 ) ;
return F_25 ( V_2 , V_77 ) ;
}
static int F_28 ( struct V_107 * V_69 ,
enum V_115 V_116 ,
enum V_117 V_118 , bool * V_119 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_120 , V_121 ;
F_12 ( L_14 , V_116 , V_118 ) ;
V_120 = F_1 ( V_2 , V_10 ) ;
V_120 &= ~ ( V_122 |
V_123 ) ;
V_121 = F_1 ( V_2 , V_124 ) ;
V_121 &= ~ V_125 ;
switch ( V_116 ) {
case V_126 :
if ( V_118 & V_127 )
V_120 |= V_122 ;
if ( V_118 & V_128 )
V_120 |= V_123 ;
break;
case V_129 :
V_121 |= V_125 ;
if ( V_118 & V_127 )
V_120 |= V_122 ;
if ( V_118 & V_128 )
V_120 |= V_123 ;
break;
case V_130 :
V_120 |= ( V_122 |
V_123 ) ;
if ( V_118 & V_127 )
V_120 &= ~ V_122 ;
if ( V_118 & V_128 )
V_120 &= ~ V_123 ;
break;
case V_131 :
V_120 |= ( V_122 |
V_123 ) ;
V_121 |= V_125 ;
if ( V_118 & V_127 )
V_120 &= ~ V_122 ;
if ( V_118 & V_128 )
V_120 &= ~ V_123 ;
break;
default:
F_18 ( V_59 -> V_69 , L_15 , V_116 ) ;
return - V_106 ;
}
F_3 ( V_2 , V_120 , V_10 ) ;
F_3 ( V_2 , V_121 , V_124 ) ;
* V_119 = ( V_121 & V_125 ) ? 1 : 0 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_132 * V_133 , struct V_134 * V_135 )
{
T_1 V_8 , V_136 , V_137 , V_138 , V_139 ;
V_136 = V_133 -> V_140 ;
V_137 = V_135 -> V_141 - V_133 -> V_142 - V_133 -> V_140 ;
V_138 = V_133 -> V_143 ;
V_139 = V_135 -> V_144 - V_133 -> V_145 - V_133 -> V_143 ;
F_12 ( L_16 ,
V_133 -> V_140 , V_133 -> V_143 , V_133 -> V_142 , V_133 -> V_145 , V_135 -> V_141 , V_135 -> V_144 ) ;
F_12 ( L_17 , V_136 , V_137 , V_138 , V_139 ) ;
V_8 = F_1 ( V_2 , V_65 ) ;
V_8 &= ~ ( V_146 |
V_147 ) ;
V_8 |= ( F_30 ( V_136 ) |
F_31 ( V_138 ) ) ;
V_8 |= V_148 ;
F_3 ( V_2 , V_8 , V_65 ) ;
V_8 = ( F_32 ( V_137 ) |
F_33 ( V_139 ) ) ;
F_3 ( V_2 , V_8 , V_149 ) ;
return 0 ;
}
static int F_34 ( struct V_107 * V_69 , int V_119 ,
struct V_132 * V_133 , struct V_134 * V_135 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_132 V_150 = * V_133 ;
struct V_134 V_151 = * V_135 ;
T_1 V_8 ;
F_12 ( L_18 ,
V_119 , V_135 -> V_141 , V_135 -> V_144 ) ;
V_8 = ( F_35 ( V_151 . V_141 ) |
F_36 ( V_151 . V_144 ) ) ;
F_3 ( V_2 , V_8 , V_152 ) ;
F_12 ( L_19 , V_133 -> V_140 , V_133 -> V_143 , V_133 -> V_142 , V_133 -> V_145 ) ;
if ( V_119 ) {
V_150 . V_142 = V_133 -> V_145 ;
V_150 . V_145 = V_133 -> V_142 ;
V_151 . V_141 = V_135 -> V_144 ;
V_151 . V_144 = V_135 -> V_141 ;
}
V_8 = F_1 ( V_2 , V_153 ) ;
V_8 &= ~ ( V_154 |
V_155 ) ;
V_8 |= ( F_37 ( V_150 . V_142 ) |
F_38 ( V_150 . V_145 ) ) ;
F_3 ( V_2 , V_8 , V_153 ) ;
V_8 = ( V_13 |
F_39 ( V_151 . V_141 ) |
F_40 ( V_151 . V_144 ) ) ;
F_3 ( V_2 , V_8 , V_12 ) ;
V_8 = ( F_41 ( V_150 . V_140 ) |
F_42 ( V_150 . V_143 ) ) ;
F_3 ( V_2 , V_8 , V_156 ) ;
V_8 = ( F_43 ( V_150 . V_140 ) |
F_44 ( V_150 . V_143 ) ) ;
F_3 ( V_2 , V_8 , V_157 ) ;
V_8 = ( F_45 ( V_150 . V_140 ) |
F_46 ( V_150 . V_143 ) ) ;
F_3 ( V_2 , V_8 , V_158 ) ;
return F_29 ( V_2 , & V_150 , & V_151 ) ;
}
static int F_47 ( struct V_107 * V_69 ,
struct V_159 * V_160 , T_1 V_72 ,
enum V_161 V_162 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_163 * V_164 = V_59 -> V_164 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
if ( ! V_164 ) {
F_23 ( L_20 ) ;
return - V_106 ;
}
V_166 = & V_164 -> V_166 ;
F_12 ( L_21 ,
V_166 -> V_169 , V_72 , V_162 ) ;
if ( V_72 > V_170 ) {
F_48 ( V_59 -> V_69 , L_22 , V_72 ) ;
return - V_171 ;
}
switch ( V_162 ) {
case V_172 :
V_168 = & V_166 -> V_168 [ V_173 ] ;
F_3 ( V_2 , V_160 -> V_174 [ V_175 ] ,
V_176 ) ;
if ( V_168 -> V_77 == V_101 ) {
F_3 ( V_2 , V_160 -> V_174 [ V_177 ] ,
V_178 ) ;
F_3 ( V_2 , V_160 -> V_174 [ V_179 ] ,
V_180 ) ;
} else {
F_3 ( V_2 , V_160 -> V_174 [ V_179 ] ,
V_178 ) ;
F_3 ( V_2 , V_160 -> V_174 [ V_177 ] ,
V_180 ) ;
}
break;
case V_181 :
F_3 ( V_2 , 0x0 , V_176 ) ;
F_3 ( V_2 , 0x0 , V_178 ) ;
F_3 ( V_2 , 0x0 , V_180 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_77 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_11 , V_77 ) ;
V_8 = F_1 ( V_2 , V_78 ) ;
V_8 &= ~ V_182 ;
switch ( V_77 ) {
case V_80 :
V_8 |= V_183 ;
F_3 ( V_2 , V_8 , V_78 ) ;
return 0 ;
case V_82 :
V_8 |= V_184 ;
F_3 ( V_2 , V_8 , V_78 ) ;
return 0 ;
case V_83 :
V_8 |= ( V_184 |
V_185 ) ;
F_3 ( V_2 , V_8 , V_78 ) ;
break;
default:
break;
}
V_8 = F_1 ( V_2 , V_75 ) ;
V_8 &= ~ ( V_186 |
V_187 |
V_188 ) ;
switch ( V_77 ) {
case V_83 :
V_8 |= V_189 ;
break;
case V_88 :
V_8 |= V_190 ;
break;
case V_89 :
V_8 |= V_191 ;
break;
case V_91 :
V_8 |= V_192 ;
break;
case V_93 :
V_8 |= V_193 ;
break;
case V_96 :
case V_97 :
V_8 |= V_194 ;
V_8 |= V_195 ;
break;
case V_99 :
case V_100 :
case V_101 :
V_8 |= V_196 ;
break;
case V_103 :
case V_104 :
V_8 |= V_197 ;
V_8 |= V_195 ;
break;
default:
F_18 ( V_59 -> V_69 , L_23 , V_77 ) ;
return - V_106 ;
}
F_3 ( V_2 , V_8 , V_75 ) ;
return 0 ;
}
static int F_50 ( struct V_107 * V_69 , T_1 V_77 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_11 , V_77 ) ;
V_8 = F_1 ( V_2 , V_198 ) ;
if ( V_77 == V_199 ) {
V_8 |= V_200 ;
F_3 ( V_2 , V_8 , V_198 ) ;
} else {
V_8 &= ~ V_200 ;
F_3 ( V_2 , V_8 , V_198 ) ;
V_8 = F_1 ( V_2 , V_124 ) ;
V_8 &= ~ V_201 ;
switch ( V_77 ) {
case V_80 :
case V_82 :
case V_83 :
V_8 |= V_202 ;
break;
case V_88 :
case V_89 :
case V_91 :
case V_93 :
V_8 |= V_203 ;
break;
case V_104 :
case V_97 :
case V_99 :
V_8 |= V_204 ;
break;
case V_100 :
case V_101 :
case V_103 :
case V_96 :
V_8 |= V_205 ;
break;
default:
F_18 ( V_59 -> V_69 , L_24 ,
V_77 ) ;
return - V_106 ;
}
F_3 ( V_2 , V_8 , V_124 ) ;
}
V_8 = F_1 ( V_2 , V_112 ) ;
V_8 &= ~ V_206 ;
V_8 |= V_207 ;
F_3 ( V_2 , V_8 , V_112 ) ;
return F_49 ( V_2 , V_77 ) ;
}
static int F_51 ( struct V_107 * V_69 ,
enum V_115 V_116 ,
enum V_117 V_118 , bool * V_119 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_14 , V_116 , V_118 ) ;
V_8 = F_1 ( V_2 , V_124 ) ;
V_8 &= ~ V_208 ;
V_8 &= ~ V_209 ;
switch ( V_116 ) {
case V_126 :
if ( V_118 & V_127 )
V_8 |= V_210 ;
if ( V_118 & V_128 )
V_8 |= V_211 ;
break;
case V_129 :
V_8 |= V_209 ;
if ( V_118 & V_127 )
V_8 |= V_210 ;
if ( V_118 & V_128 )
V_8 |= V_211 ;
break;
case V_130 :
V_8 |= ( V_210 |
V_211 ) ;
if ( V_118 & V_127 )
V_8 &= ~ V_210 ;
if ( V_118 & V_128 )
V_8 &= ~ V_211 ;
break;
case V_131 :
V_8 |= ( V_209 |
V_210 |
V_211 ) ;
if ( V_118 & V_127 )
V_8 &= ~ V_210 ;
if ( V_118 & V_128 )
V_8 &= ~ V_211 ;
break;
default:
F_18 ( V_59 -> V_69 , L_15 , V_116 ) ;
return - V_106 ;
}
F_3 ( V_2 , V_8 , V_124 ) ;
* V_119 = ( V_8 & V_209 ) ? 1 : 0 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_212 * V_213 ,
struct V_132 * V_214 , struct V_132 * V_215 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 , V_216 , V_217 ;
T_1 V_218 , V_219 ;
T_1 V_220 , V_221 ;
int V_222 = 0 ;
T_1 V_223 , V_224 , V_225 , V_226 ;
V_216 = F_1 ( V_2 , V_124 ) ;
if ( V_216 & V_125 ) {
V_223 = V_214 -> V_145 ;
V_224 = V_214 -> V_142 ;
} else {
V_223 = V_214 -> V_142 ;
V_224 = V_214 -> V_145 ;
}
if ( V_216 & V_209 ) {
V_225 = V_215 -> V_145 ;
V_226 = V_215 -> V_142 ;
} else {
V_225 = V_215 -> V_142 ;
V_226 = V_215 -> V_145 ;
}
V_220 = F_53 ( V_223 / V_225 / 2 ) ;
if ( V_220 > V_227 / 2 ) {
F_18 ( V_59 -> V_69 , L_25 ) ;
return - V_106 ;
}
V_221 = F_53 ( V_224 / V_226 / 2 ) ;
if ( V_221 > V_227 / 2 ) {
F_18 ( V_59 -> V_69 , L_26 ) ;
return - V_106 ;
}
V_218 = V_223 >> V_220 ;
V_219 = V_224 >> V_221 ;
F_12 ( L_27 ,
V_218 , V_219 ) ;
F_12 ( L_28 , V_220 , V_221 ) ;
V_213 -> V_228 = ( V_223 << 14 ) / ( V_225 << V_220 ) ;
V_213 -> V_229 = ( V_224 << 14 ) / ( V_226 << V_221 ) ;
V_213 -> V_230 = ( V_225 >= V_223 ) ? true : false ;
V_213 -> V_231 = ( V_226 >= V_224 ) ? true : false ;
F_12 ( L_29 ,
V_213 -> V_228 , V_213 -> V_229 , V_213 -> V_230 , V_213 -> V_231 ) ;
V_217 = V_227 - ( V_220 + V_221 ) ;
F_12 ( L_30 , V_217 ) ;
V_8 = ( F_54 ( V_217 ) |
F_55 ( 1 << V_220 ) |
F_56 ( 1 << V_221 ) ) ;
F_3 ( V_2 , V_8 , V_232 ) ;
V_8 = ( F_57 ( V_218 ) |
F_58 ( V_219 ) ) ;
F_3 ( V_2 , V_8 , V_233 ) ;
return V_222 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_212 * V_213 )
{
T_1 V_8 , V_216 ;
F_12 ( L_31 ,
V_213 -> V_234 , V_213 -> V_235 , V_213 -> V_230 , V_213 -> V_231 ) ;
F_12 ( L_32 ,
V_213 -> V_228 , V_213 -> V_229 ) ;
V_8 = F_1 ( V_2 , V_78 ) ;
V_8 &= ~ ( V_236 |
V_237 | V_238 |
V_239 |
V_240 |
V_241 |
V_242 ) ;
if ( V_213 -> V_234 )
V_8 |= ( V_241 |
V_242 ) ;
if ( V_213 -> V_235 )
V_8 |= V_236 ;
if ( V_213 -> V_230 )
V_8 |= V_237 ;
if ( V_213 -> V_231 )
V_8 |= V_238 ;
V_8 |= ( F_60 ( ( V_213 -> V_228 >> 6 ) ) |
F_61 ( ( V_213 -> V_229 >> 6 ) ) ) ;
F_3 ( V_2 , V_8 , V_78 ) ;
V_216 = F_1 ( V_2 , V_198 ) ;
V_216 &= ~ V_243 ;
V_216 &= ~ V_244 ;
V_216 |= ( F_62 ( V_213 -> V_228 ) |
F_63 ( V_213 -> V_229 ) ) ;
F_3 ( V_2 , V_216 , V_198 ) ;
}
static int F_64 ( struct V_107 * V_69 , int V_119 ,
struct V_132 * V_133 , struct V_134 * V_135 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_132 V_150 = * V_133 ;
struct V_134 V_151 = * V_135 ;
T_1 V_8 ;
F_12 ( L_18 ,
V_119 , V_135 -> V_141 , V_135 -> V_144 ) ;
V_8 = ( F_65 ( V_151 . V_141 ) |
F_66 ( V_151 . V_144 ) ) ;
F_3 ( V_2 , V_8 , V_245 ) ;
F_12 ( L_19 , V_133 -> V_140 , V_133 -> V_143 , V_133 -> V_142 , V_133 -> V_145 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
V_8 &= ~ V_246 ;
if ( V_135 -> V_141 >= V_247 )
V_8 |= V_248 ;
else
V_8 |= V_249 ;
F_3 ( V_2 , V_8 , V_17 ) ;
if ( V_119 ) {
V_150 . V_142 = V_133 -> V_145 ;
V_150 . V_145 = V_133 -> V_142 ;
V_151 . V_141 = V_135 -> V_144 ;
V_151 . V_144 = V_135 -> V_141 ;
}
V_8 = F_1 ( V_2 , V_124 ) ;
V_8 &= ~ ( V_250 |
V_251 ) ;
V_8 |= ( F_67 ( V_150 . V_142 ) |
F_68 ( V_150 . V_145 ) ) ;
F_3 ( V_2 , V_8 , V_124 ) ;
V_8 = F_69 ( V_150 . V_142 * V_150 . V_145 ) ;
F_3 ( V_2 , V_8 , V_252 ) ;
V_8 = ( F_70 ( V_150 . V_140 ) |
F_71 ( V_150 . V_143 ) ) ;
F_3 ( V_2 , V_8 , V_253 ) ;
V_8 = ( F_72 ( V_150 . V_140 ) |
F_73 ( V_150 . V_143 ) ) ;
F_3 ( V_2 , V_8 , V_254 ) ;
V_8 = ( F_74 ( V_150 . V_140 ) |
F_75 ( V_150 . V_143 ) ) ;
F_3 ( V_2 , V_8 , V_255 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , T_1 V_72 ,
enum V_161 V_162 )
{
unsigned long V_256 ;
T_1 V_257 ;
T_1 V_8 ;
F_12 ( L_33 , V_72 , V_162 ) ;
F_77 ( & V_2 -> V_258 , V_256 ) ;
V_8 = F_1 ( V_2 , V_19 ) ;
if ( V_162 == V_172 )
V_8 |= ( 1 << V_72 ) ;
else
V_8 &= ~ ( 1 << V_72 ) ;
F_3 ( V_2 , V_8 , V_19 ) ;
V_257 = F_78 ( V_8 ) ;
if ( V_162 == V_172 && V_257 >= V_259 )
F_15 ( V_2 , true ) ;
else if ( V_162 == V_181 && V_257 <= V_260 )
F_15 ( V_2 , false ) ;
F_79 ( & V_2 -> V_258 , V_256 ) ;
}
static int F_80 ( struct V_107 * V_69 ,
struct V_159 * V_160 , T_1 V_72 ,
enum V_161 V_162 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_163 * V_164 = V_59 -> V_164 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
if ( ! V_164 ) {
F_23 ( L_20 ) ;
return - V_106 ;
}
V_166 = & V_164 -> V_166 ;
F_12 ( L_21 ,
V_166 -> V_169 , V_72 , V_162 ) ;
if ( V_72 > V_261 ) {
F_48 ( V_59 -> V_69 , L_22 , V_72 ) ;
return - V_171 ;
}
switch ( V_162 ) {
case V_172 :
V_168 = & V_166 -> V_168 [ V_262 ] ;
F_3 ( V_2 , V_160 -> V_174 [ V_175 ] ,
F_81 ( V_72 ) ) ;
if ( V_168 -> V_77 == V_101 ) {
F_3 ( V_2 , V_160 -> V_174 [ V_177 ] ,
F_82 ( V_72 ) ) ;
F_3 ( V_2 , V_160 -> V_174 [ V_179 ] ,
F_83 ( V_72 ) ) ;
} else {
F_3 ( V_2 , V_160 -> V_174 [ V_179 ] ,
F_82 ( V_72 ) ) ;
F_3 ( V_2 , V_160 -> V_174 [ V_177 ] ,
F_83 ( V_72 ) ) ;
}
break;
case V_181 :
F_3 ( V_2 , 0x0 , F_81 ( V_72 ) ) ;
F_3 ( V_2 , 0x0 , F_82 ( V_72 ) ) ;
F_3 ( V_2 , 0x0 , F_83 ( V_72 ) ) ;
break;
default:
break;
}
F_76 ( V_2 , V_72 , V_162 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , bool V_52 )
{
F_12 ( L_4 , V_52 ) ;
if ( V_52 ) {
F_85 ( V_2 -> V_263 [ V_264 ] ) ;
F_85 ( V_2 -> V_263 [ V_265 ] ) ;
V_2 -> V_266 = false ;
} else {
F_86 ( V_2 -> V_263 [ V_264 ] ) ;
F_86 ( V_2 -> V_263 [ V_265 ] ) ;
V_2 -> V_266 = true ;
}
return 0 ;
}
static T_3 F_87 ( int V_267 , void * V_268 )
{
struct V_1 * V_2 = V_268 ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_163 * V_164 = V_59 -> V_164 ;
struct V_269 * V_270 =
V_164 -> V_270 ;
int V_72 ;
F_12 ( L_34 , V_2 -> V_23 ) ;
F_16 ( V_2 ) ;
if ( F_17 ( V_2 ) )
return V_271 ;
if ( ! F_19 ( V_2 ) )
return V_271 ;
V_72 = F_20 ( V_2 ) ;
if ( V_72 < 0 )
return V_272 ;
F_12 ( L_10 , V_72 ) ;
F_76 ( V_2 , V_72 , V_181 ) ;
V_270 -> V_59 = V_59 ;
V_270 -> V_72 [ V_262 ] = V_72 ;
F_88 ( V_59 -> V_273 , & V_270 -> V_274 ) ;
return V_272 ;
}
static int F_89 ( struct V_58 * V_59 )
{
struct V_275 * V_276 = & V_59 -> V_276 ;
V_276 -> V_277 = 1 ;
V_276 -> V_278 = 1 ;
V_276 -> V_279 = V_280 ;
V_276 -> V_281 = V_282 ;
V_276 -> V_118 = ( 1 << V_283 ) |
( 1 << V_127 ) |
( 1 << V_128 ) ;
V_276 -> V_116 = ( 1 << V_126 ) |
( 1 << V_129 ) |
( 1 << V_130 ) |
( 1 << V_131 ) ;
V_276 -> V_284 = 1 ;
V_276 -> V_285 = 1 ;
V_276 -> V_286 . V_141 = V_287 ;
V_276 -> V_286 . V_144 = V_287 ;
V_276 -> V_288 . V_141 = V_289 ;
V_276 -> V_288 . V_144 = V_289 ;
V_276 -> V_290 = 1 ;
V_276 -> V_291 . V_141 = V_292 ;
V_276 -> V_291 . V_144 = V_292 ;
V_276 -> V_293 . V_141 = V_294 ;
V_276 -> V_293 . V_144 = V_294 ;
return 0 ;
}
static inline bool F_90 ( enum V_117 V_118 )
{
switch ( V_118 ) {
case V_283 :
case V_127 :
case V_128 :
case V_295 :
return true ;
default:
F_12 ( L_35 ) ;
return false ;
}
}
static int F_91 ( struct V_107 * V_69 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_275 * V_296 = & V_59 -> V_276 ;
struct V_167 * V_168 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
bool V_119 ;
int V_297 ;
F_92 (i) {
if ( ( V_297 == V_173 ) &&
( V_166 -> V_298 == V_299 ) )
continue;
V_168 = & V_166 -> V_168 [ V_297 ] ;
V_133 = & V_168 -> V_133 ;
V_135 = & V_168 -> V_135 ;
if ( ! F_90 ( V_168 -> V_118 ) ) {
F_23 ( L_36 ) ;
goto V_300;
}
switch ( V_168 -> V_116 ) {
case V_129 :
case V_131 :
V_119 = true ;
break;
case V_126 :
case V_130 :
V_119 = false ;
break;
default:
F_23 ( L_37 ) ;
goto V_300;
}
if ( ( V_133 -> V_140 + V_133 -> V_142 > V_135 -> V_141 ) ||
( V_133 -> V_143 + V_133 -> V_145 > V_135 -> V_144 ) ) {
F_23 ( L_38 ) ;
goto V_300;
}
if ( ( V_297 == V_173 ) && ( V_296 -> V_285 ) ) {
if ( V_119 ) {
if ( ( V_133 -> V_145 < V_296 -> V_288 . V_141 ) ||
( V_135 -> V_144 > V_296 -> V_286 . V_141 ) ||
( V_133 -> V_142 < V_296 -> V_288 . V_144 ) ||
( V_135 -> V_141 > V_296 -> V_286 . V_144 ) ) {
F_23 ( L_39 ) ;
goto V_300;
}
} else {
if ( ( V_133 -> V_142 < V_296 -> V_288 . V_141 ) ||
( V_135 -> V_141 > V_296 -> V_286 . V_141 ) ||
( V_133 -> V_145 < V_296 -> V_288 . V_144 ) ||
( V_135 -> V_144 > V_296 -> V_286 . V_144 ) ) {
F_23 ( L_39 ) ;
goto V_300;
}
}
}
if ( ( V_297 == V_262 ) && ( V_296 -> V_290 ) ) {
if ( V_119 ) {
if ( ( V_133 -> V_145 < V_296 -> V_293 . V_141 ) ||
( V_135 -> V_144 > V_296 -> V_291 . V_141 ) ||
( V_133 -> V_142 < V_296 -> V_293 . V_144 ) ||
( V_135 -> V_141 > V_296 -> V_291 . V_144 ) ) {
F_23 ( L_40 ) ;
goto V_300;
}
} else {
if ( ( V_133 -> V_142 < V_296 -> V_293 . V_141 ) ||
( V_135 -> V_141 > V_296 -> V_291 . V_141 ) ||
( V_133 -> V_145 < V_296 -> V_293 . V_144 ) ||
( V_135 -> V_144 > V_296 -> V_291 . V_144 ) ) {
F_23 ( L_40 ) ;
goto V_300;
}
}
}
}
return 0 ;
V_300:
F_92 (i) {
if ( ( V_297 == V_173 ) &&
( V_166 -> V_298 == V_299 ) )
continue;
V_168 = & V_166 -> V_168 [ V_297 ] ;
V_133 = & V_168 -> V_133 ;
V_135 = & V_168 -> V_135 ;
F_23 ( L_41 ,
V_297 ? L_42 : L_43 , V_168 -> V_118 , V_168 -> V_116 ,
V_133 -> V_140 , V_133 -> V_143 , V_133 -> V_142 , V_133 -> V_145 ,
V_135 -> V_141 , V_135 -> V_144 ) ;
}
return - V_106 ;
}
static void F_93 ( struct V_1 * V_2 )
{
int V_297 ;
for ( V_297 = 0 ; V_297 < V_170 ; V_297 ++ ) {
F_3 ( V_2 , 0 , F_94 ( V_297 ) ) ;
F_3 ( V_2 , 0 , F_95 ( V_297 ) ) ;
F_3 ( V_2 , 0 , F_96 ( V_297 ) ) ;
}
for ( V_297 = 0 ; V_297 < V_261 ; V_297 ++ ) {
F_3 ( V_2 , 0 , F_81 ( V_297 ) ) ;
F_3 ( V_2 , 0 , F_82 ( V_297 ) ) ;
F_3 ( V_2 , 0 , F_83 ( V_297 ) ) ;
}
}
static int F_97 ( struct V_107 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_7 ( V_2 ) ;
memset ( & V_2 -> V_213 , 0x0 , sizeof( V_2 -> V_213 ) ) ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_98 ( struct V_107 * V_69 , enum V_301 V_298 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_163 * V_164 = V_59 -> V_164 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
struct V_132 V_150 [ V_302 ] ;
struct V_303 V_304 ;
int V_222 , V_297 ;
T_1 V_305 , V_120 ;
F_12 ( L_44 , V_298 ) ;
if ( ! V_164 ) {
F_23 ( L_20 ) ;
return - V_106 ;
}
V_166 = & V_164 -> V_166 ;
F_15 ( V_2 , true ) ;
F_92 (i) {
V_168 = & V_166 -> V_168 [ V_297 ] ;
V_150 [ V_297 ] = V_168 -> V_133 ;
}
V_222 = F_52 ( V_2 , & V_2 -> V_213 ,
& V_150 [ V_173 ] ,
& V_150 [ V_262 ] ) ;
if ( V_222 ) {
F_18 ( V_69 , L_45 ) ;
return V_222 ;
}
F_14 ( V_2 , false ) ;
F_59 ( V_2 , & V_2 -> V_213 ) ;
F_13 ( V_2 , & V_2 -> V_43 ) ;
switch ( V_298 ) {
case V_306 :
F_11 ( V_2 , V_38 ) ;
F_24 ( V_2 , false ) ;
V_305 = F_1 ( V_2 , V_10 ) ;
V_305 &= ~ V_307 ;
V_305 |= V_308 ;
F_3 ( V_2 , V_305 , V_10 ) ;
break;
case V_299 :
F_11 ( V_2 , V_33 ) ;
F_24 ( V_2 , true ) ;
V_222 = F_9 ( V_2 ) ;
if ( V_222 < 0 ) {
F_18 ( V_69 , L_46 ) ;
return V_222 ;
}
V_304 . V_52 = 1 ;
V_304 . V_309 = V_166 -> V_310 ;
F_99 ( V_311 , ( void * ) & V_304 ) ;
break;
case V_312 :
default:
V_222 = - V_106 ;
F_18 ( V_69 , L_47 ) ;
return V_222 ;
}
F_3 ( V_2 , 0x0 , V_9 ) ;
V_305 = F_1 ( V_2 , V_14 ) ;
V_305 &= ~ V_15 ;
V_305 |= V_15 ;
V_120 = F_1 ( V_2 , V_78 ) ;
V_120 &= ~ V_313 ;
V_120 |= ( V_314 |
V_315 ) ;
F_3 ( V_2 , V_120 , V_78 ) ;
V_305 |= V_16 ;
F_3 ( V_2 , V_305 , V_14 ) ;
F_6 ( V_2 , V_17 , V_316 ) ;
F_6 ( V_2 , V_75 , V_317 ) ;
if ( V_298 == V_306 )
F_5 ( V_2 , V_10 , V_11 ) ;
return 0 ;
}
static void F_100 ( struct V_107 * V_69 , enum V_301 V_298 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_303 V_304 = { 0 , 0 } ;
T_1 V_8 ;
F_12 ( L_44 , V_298 ) ;
switch ( V_298 ) {
case V_306 :
V_8 = F_1 ( V_2 , V_10 ) ;
V_8 &= ~ V_307 ;
V_8 &= ~ V_11 ;
F_3 ( V_2 , V_8 , V_10 ) ;
break;
case V_299 :
F_99 ( V_311 , ( void * ) & V_304 ) ;
break;
case V_312 :
default:
F_18 ( V_69 , L_47 ) ;
break;
}
F_15 ( V_2 , false ) ;
F_3 ( V_2 , 0x0 , V_19 ) ;
F_6 ( V_2 , V_78 , V_315 ) ;
F_6 ( V_2 , V_14 ,
V_15 | V_16 ) ;
F_5 ( V_2 , V_17 , V_316 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
int V_297 ;
for ( V_297 = 0 ; V_297 < V_318 ; V_297 ++ ) {
if ( F_102 ( V_2 -> V_263 [ V_297 ] ) )
continue;
F_103 ( V_2 -> V_263 [ V_297 ] ) ;
V_2 -> V_263 [ V_297 ] = F_104 ( - V_106 ) ;
}
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_107 * V_319 = V_2 -> V_59 . V_69 ;
struct V_107 * V_69 ;
int V_222 , V_297 ;
for ( V_297 = 0 ; V_297 < V_318 ; V_297 ++ )
V_2 -> V_263 [ V_297 ] = F_104 ( - V_106 ) ;
for ( V_297 = 0 ; V_297 < V_318 ; V_297 ++ ) {
if ( V_297 == V_265 || V_297 == V_320 )
V_69 = V_319 -> V_321 ;
else
V_69 = V_319 ;
V_2 -> V_263 [ V_297 ] = F_106 ( V_69 , V_322 [ V_297 ] ) ;
if ( F_102 ( V_2 -> V_263 [ V_297 ] ) ) {
if ( V_297 >= V_323 )
break;
V_222 = F_107 ( V_2 -> V_263 [ V_297 ] ) ;
F_18 ( V_319 , L_48 ,
V_322 [ V_297 ] ) ;
goto V_324;
}
}
if ( ! F_102 ( V_2 -> V_263 [ V_325 ] ) ) {
V_222 = F_108 ( V_2 -> V_263 [ V_323 ] ,
V_2 -> V_263 [ V_325 ] ) ;
if ( V_222 < 0 ) {
F_18 ( V_319 , L_49 ) ;
goto V_324;
}
}
V_222 = F_109 ( V_2 -> V_263 [ V_326 ] , V_2 -> V_327 ) ;
if ( V_222 < 0 )
goto V_324;
V_222 = F_85 ( V_2 -> V_263 [ V_326 ] ) ;
if ( ! V_222 )
return V_222 ;
V_324:
F_101 ( V_2 ) ;
return V_222 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_328 * V_329 = V_2 -> V_59 . V_69 -> V_330 ;
if ( ! F_111 ( V_329 , L_50 ) )
return - V_331 ;
if ( F_112 ( V_329 , L_51 ,
& V_2 -> V_327 ) )
V_2 -> V_327 = V_332 ;
V_2 -> V_23 = F_113 ( V_329 , L_52 ) ;
if ( V_2 -> V_23 < 0 ) {
F_18 ( V_2 -> V_59 . V_69 , L_53 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_114 ( struct V_333 * V_334 )
{
struct V_107 * V_69 = & V_334 -> V_69 ;
struct V_1 * V_2 ;
struct V_335 * V_336 ;
struct V_58 * V_59 ;
int V_222 ;
if ( ! V_69 -> V_330 ) {
F_18 ( V_69 , L_54 ) ;
return - V_331 ;
}
V_2 = F_115 ( V_69 , sizeof( * V_2 ) , V_337 ) ;
if ( ! V_2 )
return - V_171 ;
V_2 -> V_59 . V_69 = V_69 ;
V_222 = F_110 ( V_2 ) ;
if ( V_222 < 0 )
return V_222 ;
V_2 -> V_20 = F_116 ( V_69 -> V_330 ,
L_55 ) ;
if ( F_102 ( V_2 -> V_20 ) ) {
F_18 ( V_69 , L_56 ) ;
return F_107 ( V_2 -> V_20 ) ;
}
V_2 -> V_338 = F_117 ( V_334 , V_339 , 0 ) ;
V_2 -> V_4 = F_118 ( V_69 , V_2 -> V_338 ) ;
if ( F_102 ( V_2 -> V_4 ) )
return F_107 ( V_2 -> V_4 ) ;
V_336 = F_117 ( V_334 , V_340 , 0 ) ;
if ( ! V_336 ) {
F_18 ( V_69 , L_57 ) ;
return - V_341 ;
}
V_2 -> V_267 = V_336 -> V_342 ;
V_222 = F_119 ( V_69 , V_2 -> V_267 , NULL , F_87 ,
V_343 , L_58 , V_2 ) ;
if ( V_222 < 0 ) {
F_18 ( V_69 , L_59 ) ;
return V_222 ;
}
V_222 = F_105 ( V_2 ) ;
if ( V_222 < 0 )
return V_222 ;
V_59 = & V_2 -> V_59 ;
V_59 -> V_344 [ V_173 ] = & V_345 ;
V_59 -> V_344 [ V_262 ] = & V_346 ;
V_59 -> V_347 = F_91 ;
V_59 -> V_348 = F_97 ;
V_59 -> V_342 = F_98 ;
V_59 -> V_349 = F_100 ;
V_222 = F_89 ( V_59 ) ;
if ( V_222 < 0 ) {
F_18 ( V_69 , L_60 ) ;
goto V_350;
}
F_12 ( L_61 , V_2 -> V_23 , ( int ) V_59 ) ;
F_120 ( & V_2 -> V_258 ) ;
F_121 ( V_334 , V_2 ) ;
F_122 ( V_69 ) ;
V_222 = F_123 ( V_59 ) ;
if ( V_222 < 0 ) {
F_18 ( V_69 , L_62 ) ;
goto V_351;
}
F_48 ( V_69 , L_63 ) ;
return 0 ;
V_351:
F_124 ( V_69 ) ;
V_350:
F_101 ( V_2 ) ;
return V_222 ;
}
static int F_125 ( struct V_333 * V_334 )
{
struct V_107 * V_69 = & V_334 -> V_69 ;
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
F_126 ( V_59 ) ;
F_101 ( V_2 ) ;
F_127 ( V_69 ) ;
F_124 ( V_69 ) ;
return 0 ;
}
static int F_128 ( struct V_107 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_12 ( L_64 , V_2 -> V_23 ) ;
if ( F_129 ( V_69 ) )
return 0 ;
return F_84 ( V_2 , false ) ;
}
static int F_130 ( struct V_107 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_12 ( L_64 , V_2 -> V_23 ) ;
if ( ! F_129 ( V_69 ) )
return F_84 ( V_2 , true ) ;
return 0 ;
}
static int F_131 ( struct V_107 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_12 ( L_64 , V_2 -> V_23 ) ;
return F_84 ( V_2 , false ) ;
}
static int F_132 ( struct V_107 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_12 ( L_64 , V_2 -> V_23 ) ;
return F_84 ( V_2 , true ) ;
}
