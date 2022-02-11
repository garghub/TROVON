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
F_6 ( V_2 , V_65 ,
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
case V_105 :
V_8 |= ( V_106 |
V_86 ) ;
break;
default:
F_18 ( V_59 -> V_69 , L_12 , V_77 ) ;
return - V_107 ;
}
F_3 ( V_2 , V_8 , V_10 ) ;
return 0 ;
}
static int F_26 ( struct V_108 * V_69 , T_1 V_77 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_11 , V_77 ) ;
V_8 = F_1 ( V_2 , V_10 ) ;
V_8 &= ~ V_109 ;
switch ( V_77 ) {
case V_80 :
case V_82 :
case V_83 :
V_8 |= V_109 ;
break;
case V_94 :
V_8 |= V_110 ;
break;
case V_88 :
case V_89 :
case V_91 :
case V_93 :
V_8 |= V_111 ;
break;
case V_105 :
case V_97 :
case V_99 :
V_8 |= V_112 ;
break;
case V_100 :
case V_101 :
case V_103 :
case V_96 :
case V_104 :
V_8 |= V_110 ;
break;
default:
F_18 ( V_59 -> V_69 , L_13 , V_77 ) ;
return - V_107 ;
}
F_3 ( V_2 , V_8 , V_10 ) ;
V_8 = F_1 ( V_2 , V_113 ) ;
V_8 &= ~ V_114 ;
if ( V_77 == V_104 )
V_8 |= V_115 ;
else
V_8 |= V_116 ;
F_3 ( V_2 , V_8 , V_113 ) ;
return F_25 ( V_2 , V_77 ) ;
}
static int F_28 ( struct V_108 * V_69 ,
enum V_117 V_118 ,
enum V_119 V_120 , bool * V_121 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_122 , V_123 ;
F_12 ( L_14 , V_118 , V_120 ) ;
V_122 = F_1 ( V_2 , V_10 ) ;
V_122 &= ~ ( V_124 |
V_125 ) ;
V_123 = F_1 ( V_2 , V_126 ) ;
V_123 &= ~ V_127 ;
switch ( V_118 ) {
case V_128 :
if ( V_120 & V_129 )
V_122 |= V_124 ;
if ( V_120 & V_130 )
V_122 |= V_125 ;
break;
case V_131 :
V_123 |= V_127 ;
if ( V_120 & V_129 )
V_122 |= V_124 ;
if ( V_120 & V_130 )
V_122 |= V_125 ;
break;
case V_132 :
V_122 |= ( V_124 |
V_125 ) ;
if ( V_120 & V_129 )
V_122 &= ~ V_124 ;
if ( V_120 & V_130 )
V_122 &= ~ V_125 ;
break;
case V_133 :
V_122 |= ( V_124 |
V_125 ) ;
V_123 |= V_127 ;
if ( V_120 & V_129 )
V_122 &= ~ V_124 ;
if ( V_120 & V_130 )
V_122 &= ~ V_125 ;
break;
default:
F_18 ( V_59 -> V_69 , L_15 , V_118 ) ;
return - V_107 ;
}
F_3 ( V_2 , V_122 , V_10 ) ;
F_3 ( V_2 , V_123 , V_126 ) ;
* V_121 = ( V_123 & V_127 ) ? 1 : 0 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_134 * V_135 , struct V_136 * V_137 )
{
T_1 V_8 , V_138 , V_139 , V_140 , V_141 ;
V_138 = V_135 -> V_142 ;
V_139 = V_137 -> V_143 - V_135 -> V_144 - V_135 -> V_142 ;
V_140 = V_135 -> V_145 ;
V_141 = V_137 -> V_146 - V_135 -> V_147 - V_135 -> V_145 ;
F_12 ( L_16 ,
V_135 -> V_142 , V_135 -> V_145 , V_135 -> V_144 , V_135 -> V_147 , V_137 -> V_143 , V_137 -> V_146 ) ;
F_12 ( L_17 , V_138 , V_139 , V_140 , V_141 ) ;
V_8 = F_1 ( V_2 , V_65 ) ;
V_8 &= ~ ( V_148 |
V_149 ) ;
V_8 |= ( F_30 ( V_138 ) |
F_31 ( V_140 ) ) ;
V_8 |= V_150 ;
F_3 ( V_2 , V_8 , V_65 ) ;
V_8 = ( F_32 ( V_139 ) |
F_33 ( V_141 ) ) ;
F_3 ( V_2 , V_8 , V_151 ) ;
return 0 ;
}
static int F_34 ( struct V_108 * V_69 , int V_121 ,
struct V_134 * V_135 , struct V_136 * V_137 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_134 V_152 = * V_135 ;
struct V_136 V_153 = * V_137 ;
T_1 V_8 ;
F_12 ( L_18 ,
V_121 , V_137 -> V_143 , V_137 -> V_146 ) ;
V_8 = ( F_35 ( V_153 . V_143 ) |
F_36 ( V_153 . V_146 ) ) ;
F_3 ( V_2 , V_8 , V_154 ) ;
F_12 ( L_19 , V_135 -> V_142 , V_135 -> V_145 , V_135 -> V_144 , V_135 -> V_147 ) ;
if ( V_121 ) {
V_152 . V_144 = V_135 -> V_147 ;
V_152 . V_147 = V_135 -> V_144 ;
V_153 . V_143 = V_137 -> V_146 ;
V_153 . V_146 = V_137 -> V_143 ;
}
V_8 = F_1 ( V_2 , V_155 ) ;
V_8 &= ~ ( V_156 |
V_157 ) ;
V_8 |= ( F_37 ( V_152 . V_144 ) |
F_38 ( V_152 . V_147 ) ) ;
F_3 ( V_2 , V_8 , V_155 ) ;
V_8 = ( V_13 |
F_39 ( V_153 . V_143 ) |
F_40 ( V_153 . V_146 ) ) ;
F_3 ( V_2 , V_8 , V_12 ) ;
V_8 = ( F_41 ( V_152 . V_142 ) |
F_42 ( V_152 . V_145 ) ) ;
F_3 ( V_2 , V_8 , V_158 ) ;
V_8 = ( F_43 ( V_152 . V_142 ) |
F_44 ( V_152 . V_145 ) ) ;
F_3 ( V_2 , V_8 , V_159 ) ;
V_8 = ( F_45 ( V_152 . V_142 ) |
F_46 ( V_152 . V_145 ) ) ;
F_3 ( V_2 , V_8 , V_160 ) ;
return F_29 ( V_2 , & V_152 , & V_153 ) ;
}
static int F_47 ( struct V_108 * V_69 ,
struct V_161 * V_162 , T_1 V_72 ,
enum V_163 V_164 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_165 * V_166 = V_59 -> V_166 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
if ( ! V_166 ) {
F_23 ( L_20 ) ;
return - V_107 ;
}
V_168 = & V_166 -> V_168 ;
F_12 ( L_21 ,
V_168 -> V_171 , V_72 , V_164 ) ;
if ( V_72 > V_172 ) {
F_48 ( V_59 -> V_69 , L_22 , V_72 ) ;
return - V_173 ;
}
switch ( V_164 ) {
case V_174 :
V_170 = & V_168 -> V_170 [ V_175 ] ;
F_3 ( V_2 , V_162 -> V_176 [ V_177 ] ,
F_49 ( V_72 ) ) ;
if ( V_170 -> V_77 == V_101 ) {
F_3 ( V_2 , V_162 -> V_176 [ V_178 ] ,
F_50 ( V_72 ) ) ;
F_3 ( V_2 , V_162 -> V_176 [ V_179 ] ,
F_51 ( V_72 ) ) ;
} else {
F_3 ( V_2 , V_162 -> V_176 [ V_179 ] ,
F_50 ( V_72 ) ) ;
F_3 ( V_2 , V_162 -> V_176 [ V_178 ] ,
F_51 ( V_72 ) ) ;
}
break;
case V_180 :
F_3 ( V_2 , 0x0 , F_49 ( V_72 ) ) ;
F_3 ( V_2 , 0x0 , F_50 ( V_72 ) ) ;
F_3 ( V_2 , 0x0 , F_51 ( V_72 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , T_1 V_77 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_11 , V_77 ) ;
V_8 = F_1 ( V_2 , V_78 ) ;
V_8 &= ~ V_181 ;
switch ( V_77 ) {
case V_80 :
V_8 |= V_182 ;
F_3 ( V_2 , V_8 , V_78 ) ;
return 0 ;
case V_82 :
V_8 |= V_183 ;
F_3 ( V_2 , V_8 , V_78 ) ;
return 0 ;
case V_83 :
V_8 |= ( V_183 |
V_184 ) ;
F_3 ( V_2 , V_8 , V_78 ) ;
break;
default:
break;
}
V_8 = F_1 ( V_2 , V_75 ) ;
V_8 &= ~ ( V_185 |
V_186 |
V_187 ) ;
switch ( V_77 ) {
case V_83 :
V_8 |= V_188 ;
break;
case V_88 :
V_8 |= V_189 ;
break;
case V_89 :
V_8 |= V_190 ;
break;
case V_91 :
V_8 |= V_191 ;
break;
case V_93 :
V_8 |= V_192 ;
break;
case V_96 :
case V_97 :
V_8 |= V_193 ;
V_8 |= V_194 ;
break;
case V_99 :
case V_100 :
case V_101 :
V_8 |= V_195 ;
break;
case V_103 :
case V_104 :
case V_105 :
V_8 |= V_196 ;
V_8 |= V_194 ;
break;
default:
F_18 ( V_59 -> V_69 , L_23 , V_77 ) ;
return - V_107 ;
}
F_3 ( V_2 , V_8 , V_75 ) ;
return 0 ;
}
static int F_53 ( struct V_108 * V_69 , T_1 V_77 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_11 , V_77 ) ;
V_8 = F_1 ( V_2 , V_197 ) ;
if ( V_77 == V_198 ) {
V_8 |= V_199 ;
F_3 ( V_2 , V_8 , V_197 ) ;
} else {
V_8 &= ~ V_199 ;
F_3 ( V_2 , V_8 , V_197 ) ;
V_8 = F_1 ( V_2 , V_126 ) ;
V_8 &= ~ V_200 ;
switch ( V_77 ) {
case V_80 :
case V_82 :
case V_83 :
V_8 |= V_201 ;
break;
case V_88 :
case V_89 :
case V_91 :
case V_93 :
V_8 |= V_202 ;
break;
case V_105 :
case V_97 :
case V_99 :
V_8 |= V_203 ;
break;
case V_100 :
case V_101 :
case V_103 :
case V_104 :
case V_96 :
V_8 |= V_204 ;
break;
default:
F_18 ( V_59 -> V_69 , L_24 ,
V_77 ) ;
return - V_107 ;
}
F_3 ( V_2 , V_8 , V_126 ) ;
}
V_8 = F_1 ( V_2 , V_113 ) ;
V_8 &= ~ V_205 ;
if ( V_77 == V_104 )
V_8 |= V_206 ;
else
V_8 |= V_207 ;
F_3 ( V_2 , V_8 , V_113 ) ;
return F_52 ( V_2 , V_77 ) ;
}
static int F_54 ( struct V_108 * V_69 ,
enum V_117 V_118 ,
enum V_119 V_120 , bool * V_121 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 ;
F_12 ( L_14 , V_118 , V_120 ) ;
V_8 = F_1 ( V_2 , V_126 ) ;
V_8 &= ~ V_208 ;
V_8 &= ~ V_209 ;
switch ( V_118 ) {
case V_128 :
if ( V_120 & V_129 )
V_8 |= V_210 ;
if ( V_120 & V_130 )
V_8 |= V_211 ;
break;
case V_131 :
V_8 |= V_209 ;
if ( V_120 & V_129 )
V_8 |= V_210 ;
if ( V_120 & V_130 )
V_8 |= V_211 ;
break;
case V_132 :
V_8 |= ( V_210 |
V_211 ) ;
if ( V_120 & V_129 )
V_8 &= ~ V_210 ;
if ( V_120 & V_130 )
V_8 &= ~ V_211 ;
break;
case V_133 :
V_8 |= ( V_209 |
V_210 |
V_211 ) ;
if ( V_120 & V_129 )
V_8 &= ~ V_210 ;
if ( V_120 & V_130 )
V_8 &= ~ V_211 ;
break;
default:
F_18 ( V_59 -> V_69 , L_15 , V_118 ) ;
return - V_107 ;
}
F_3 ( V_2 , V_8 , V_126 ) ;
* V_121 = ( V_8 & V_209 ) ? 1 : 0 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_212 * V_213 ,
struct V_134 * V_214 , struct V_134 * V_215 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
T_1 V_8 , V_216 , V_217 ;
T_1 V_218 , V_219 ;
T_1 V_220 , V_221 ;
int V_222 = 0 ;
T_1 V_223 , V_224 , V_225 , V_226 ;
V_216 = F_1 ( V_2 , V_126 ) ;
if ( V_216 & V_127 ) {
V_223 = V_214 -> V_147 ;
V_224 = V_214 -> V_144 ;
} else {
V_223 = V_214 -> V_144 ;
V_224 = V_214 -> V_147 ;
}
if ( V_216 & V_209 ) {
V_225 = V_215 -> V_147 ;
V_226 = V_215 -> V_144 ;
} else {
V_225 = V_215 -> V_144 ;
V_226 = V_215 -> V_147 ;
}
V_220 = F_56 ( V_223 / V_225 / 2 ) ;
if ( V_220 > V_227 / 2 ) {
F_18 ( V_59 -> V_69 , L_25 ) ;
return - V_107 ;
}
V_221 = F_56 ( V_224 / V_226 / 2 ) ;
if ( V_221 > V_227 / 2 ) {
F_18 ( V_59 -> V_69 , L_26 ) ;
return - V_107 ;
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
V_8 = ( F_57 ( V_217 ) |
F_58 ( 1 << V_220 ) |
F_59 ( 1 << V_221 ) ) ;
F_3 ( V_2 , V_8 , V_232 ) ;
V_8 = ( F_60 ( V_218 ) |
F_61 ( V_219 ) ) ;
F_3 ( V_2 , V_8 , V_233 ) ;
return V_222 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_212 * V_213 )
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
V_8 |= ( F_63 ( ( V_213 -> V_228 >> 6 ) ) |
F_64 ( ( V_213 -> V_229 >> 6 ) ) ) ;
F_3 ( V_2 , V_8 , V_78 ) ;
V_216 = F_1 ( V_2 , V_197 ) ;
V_216 &= ~ V_243 ;
V_216 &= ~ V_244 ;
V_216 |= ( F_65 ( V_213 -> V_228 ) |
F_66 ( V_213 -> V_229 ) ) ;
F_3 ( V_2 , V_216 , V_197 ) ;
}
static int F_67 ( struct V_108 * V_69 , int V_121 ,
struct V_134 * V_135 , struct V_136 * V_137 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_134 V_152 = * V_135 ;
struct V_136 V_153 = * V_137 ;
T_1 V_8 ;
F_12 ( L_18 ,
V_121 , V_137 -> V_143 , V_137 -> V_146 ) ;
V_8 = ( F_68 ( V_153 . V_143 ) |
F_69 ( V_153 . V_146 ) ) ;
F_3 ( V_2 , V_8 , V_245 ) ;
F_12 ( L_19 , V_135 -> V_142 , V_135 -> V_145 , V_135 -> V_144 , V_135 -> V_147 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
V_8 &= ~ V_246 ;
if ( V_137 -> V_143 >= V_247 )
V_8 |= V_248 ;
else
V_8 |= V_249 ;
F_3 ( V_2 , V_8 , V_17 ) ;
if ( V_121 ) {
V_152 . V_144 = V_135 -> V_147 ;
V_152 . V_147 = V_135 -> V_144 ;
V_153 . V_143 = V_137 -> V_146 ;
V_153 . V_146 = V_137 -> V_143 ;
}
V_8 = F_1 ( V_2 , V_126 ) ;
V_8 &= ~ ( V_250 |
V_251 ) ;
V_8 |= ( F_70 ( V_152 . V_144 ) |
F_71 ( V_152 . V_147 ) ) ;
F_3 ( V_2 , V_8 , V_126 ) ;
V_8 = F_72 ( V_152 . V_144 * V_152 . V_147 ) ;
F_3 ( V_2 , V_8 , V_252 ) ;
V_8 = ( F_73 ( V_152 . V_142 ) |
F_74 ( V_152 . V_145 ) ) ;
F_3 ( V_2 , V_8 , V_253 ) ;
V_8 = ( F_75 ( V_152 . V_142 ) |
F_76 ( V_152 . V_145 ) ) ;
F_3 ( V_2 , V_8 , V_254 ) ;
V_8 = ( F_77 ( V_152 . V_142 ) |
F_78 ( V_152 . V_145 ) ) ;
F_3 ( V_2 , V_8 , V_255 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
T_1 V_8 , V_256 ;
V_8 = F_1 ( V_2 , V_19 ) ;
V_256 = F_80 ( V_8 ) ;
F_12 ( L_33 , V_256 ) ;
return V_256 ;
}
static int F_81 ( struct V_1 * V_2 , T_1 V_72 ,
enum V_163 V_164 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
bool V_52 ;
T_1 V_8 ;
T_1 V_257 = 0x00000001 << V_72 ;
int V_222 = 0 ;
unsigned long V_258 ;
F_12 ( L_34 , V_72 , V_164 ) ;
F_82 ( & V_2 -> V_259 , V_258 ) ;
V_8 = F_1 ( V_2 , V_19 ) ;
switch ( V_164 ) {
case V_174 :
V_52 = true ;
break;
case V_180 :
V_52 = false ;
break;
default:
F_18 ( V_59 -> V_69 , L_35 ) ;
V_222 = - V_107 ;
goto V_260;
}
V_8 &= ~ V_257 ;
V_8 |= ( V_52 << V_72 ) ;
F_3 ( V_2 , V_8 , V_19 ) ;
if ( V_164 == V_174 &&
F_79 ( V_2 ) >= V_261 )
F_15 ( V_2 , true ) ;
if ( V_164 == V_180 &&
F_79 ( V_2 ) <= V_262 )
F_15 ( V_2 , false ) ;
V_260:
F_83 ( & V_2 -> V_259 , V_258 ) ;
return V_222 ;
}
static int F_84 ( struct V_108 * V_69 ,
struct V_161 * V_162 , T_1 V_72 ,
enum V_163 V_164 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_165 * V_166 = V_59 -> V_166 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
if ( ! V_166 ) {
F_23 ( L_20 ) ;
return - V_107 ;
}
V_168 = & V_166 -> V_168 ;
F_12 ( L_21 ,
V_168 -> V_171 , V_72 , V_164 ) ;
if ( V_72 > V_263 ) {
F_48 ( V_59 -> V_69 , L_22 , V_72 ) ;
return - V_173 ;
}
switch ( V_164 ) {
case V_174 :
V_170 = & V_168 -> V_170 [ V_264 ] ;
F_3 ( V_2 , V_162 -> V_176 [ V_177 ] ,
F_85 ( V_72 ) ) ;
if ( V_170 -> V_77 == V_101 ) {
F_3 ( V_2 , V_162 -> V_176 [ V_178 ] ,
F_86 ( V_72 ) ) ;
F_3 ( V_2 , V_162 -> V_176 [ V_179 ] ,
F_87 ( V_72 ) ) ;
} else {
F_3 ( V_2 , V_162 -> V_176 [ V_179 ] ,
F_86 ( V_72 ) ) ;
F_3 ( V_2 , V_162 -> V_176 [ V_178 ] ,
F_87 ( V_72 ) ) ;
}
break;
case V_180 :
F_3 ( V_2 , 0x0 , F_85 ( V_72 ) ) ;
F_3 ( V_2 , 0x0 , F_86 ( V_72 ) ) ;
F_3 ( V_2 , 0x0 , F_87 ( V_72 ) ) ;
break;
default:
break;
}
return F_81 ( V_2 , V_72 , V_164 ) ;
}
static int F_88 ( struct V_1 * V_2 , bool V_52 )
{
F_12 ( L_4 , V_52 ) ;
if ( V_52 ) {
F_89 ( V_2 -> V_265 [ V_266 ] ) ;
F_89 ( V_2 -> V_265 [ V_267 ] ) ;
V_2 -> V_268 = false ;
} else {
F_90 ( V_2 -> V_265 [ V_266 ] ) ;
F_90 ( V_2 -> V_265 [ V_267 ] ) ;
V_2 -> V_268 = true ;
}
return 0 ;
}
static T_3 F_91 ( int V_269 , void * V_270 )
{
struct V_1 * V_2 = V_270 ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_165 * V_166 = V_59 -> V_166 ;
struct V_271 * V_272 =
V_166 -> V_272 ;
int V_72 ;
F_12 ( L_36 , V_2 -> V_23 ) ;
F_16 ( V_2 ) ;
if ( F_17 ( V_2 ) )
return V_273 ;
if ( ! F_19 ( V_2 ) )
return V_273 ;
V_72 = F_20 ( V_2 ) ;
if ( V_72 < 0 )
return V_274 ;
F_12 ( L_10 , V_72 ) ;
if ( F_81 ( V_2 , V_72 , V_180 ) < 0 ) {
F_23 ( L_37 ) ;
return V_274 ;
}
V_272 -> V_59 = V_59 ;
V_272 -> V_72 [ V_264 ] = V_72 ;
F_92 ( V_59 -> V_275 , (struct V_276 * ) V_272 ) ;
return V_274 ;
}
static int F_93 ( struct V_58 * V_59 )
{
struct V_277 * V_278 = & V_59 -> V_278 ;
V_278 -> V_279 = 1 ;
V_278 -> V_280 = 1 ;
V_278 -> V_281 = V_282 ;
V_278 -> V_283 = V_284 ;
V_278 -> V_120 = ( 1 << V_285 ) |
( 1 << V_129 ) |
( 1 << V_130 ) ;
V_278 -> V_118 = ( 1 << V_128 ) |
( 1 << V_131 ) |
( 1 << V_132 ) |
( 1 << V_133 ) ;
V_278 -> V_286 = 1 ;
V_278 -> V_287 = 1 ;
V_278 -> V_288 . V_143 = V_289 ;
V_278 -> V_288 . V_146 = V_289 ;
V_278 -> V_290 . V_143 = V_291 ;
V_278 -> V_290 . V_146 = V_291 ;
V_278 -> V_292 = 1 ;
V_278 -> V_293 . V_143 = V_294 ;
V_278 -> V_293 . V_146 = V_294 ;
V_278 -> V_295 . V_143 = V_296 ;
V_278 -> V_295 . V_146 = V_296 ;
return 0 ;
}
static inline bool F_94 ( enum V_119 V_120 )
{
switch ( V_120 ) {
case V_285 :
case V_129 :
case V_130 :
case V_297 :
return true ;
default:
F_12 ( L_38 ) ;
return false ;
}
}
static int F_95 ( struct V_108 * V_69 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_277 * V_298 = & V_59 -> V_278 ;
struct V_169 * V_170 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
bool V_121 ;
int V_299 ;
F_96 (i) {
if ( ( V_299 == V_175 ) &&
( V_168 -> V_300 == V_301 ) )
continue;
V_170 = & V_168 -> V_170 [ V_299 ] ;
V_135 = & V_170 -> V_135 ;
V_137 = & V_170 -> V_137 ;
if ( ! F_94 ( V_170 -> V_120 ) ) {
F_23 ( L_39 ) ;
goto V_302;
}
switch ( V_170 -> V_118 ) {
case V_131 :
case V_133 :
V_121 = true ;
break;
case V_128 :
case V_132 :
V_121 = false ;
break;
default:
F_23 ( L_40 ) ;
goto V_302;
}
if ( ( V_135 -> V_142 + V_135 -> V_144 > V_137 -> V_143 ) ||
( V_135 -> V_145 + V_135 -> V_147 > V_137 -> V_146 ) ) {
F_23 ( L_41 ) ;
goto V_302;
}
if ( ( V_299 == V_175 ) && ( V_298 -> V_287 ) ) {
if ( V_121 ) {
if ( ( V_135 -> V_147 < V_298 -> V_290 . V_143 ) ||
( V_137 -> V_146 > V_298 -> V_288 . V_143 ) ||
( V_135 -> V_144 < V_298 -> V_290 . V_146 ) ||
( V_137 -> V_143 > V_298 -> V_288 . V_146 ) ) {
F_23 ( L_42 ) ;
goto V_302;
}
} else {
if ( ( V_135 -> V_144 < V_298 -> V_290 . V_143 ) ||
( V_137 -> V_143 > V_298 -> V_288 . V_143 ) ||
( V_135 -> V_147 < V_298 -> V_290 . V_146 ) ||
( V_137 -> V_146 > V_298 -> V_288 . V_146 ) ) {
F_23 ( L_42 ) ;
goto V_302;
}
}
}
if ( ( V_299 == V_264 ) && ( V_298 -> V_292 ) ) {
if ( V_121 ) {
if ( ( V_135 -> V_147 < V_298 -> V_295 . V_143 ) ||
( V_137 -> V_146 > V_298 -> V_293 . V_143 ) ||
( V_135 -> V_144 < V_298 -> V_295 . V_146 ) ||
( V_137 -> V_143 > V_298 -> V_293 . V_146 ) ) {
F_23 ( L_43 ) ;
goto V_302;
}
} else {
if ( ( V_135 -> V_144 < V_298 -> V_295 . V_143 ) ||
( V_137 -> V_143 > V_298 -> V_293 . V_143 ) ||
( V_135 -> V_147 < V_298 -> V_295 . V_146 ) ||
( V_137 -> V_146 > V_298 -> V_293 . V_146 ) ) {
F_23 ( L_43 ) ;
goto V_302;
}
}
}
}
return 0 ;
V_302:
F_96 (i) {
if ( ( V_299 == V_175 ) &&
( V_168 -> V_300 == V_301 ) )
continue;
V_170 = & V_168 -> V_170 [ V_299 ] ;
V_135 = & V_170 -> V_135 ;
V_137 = & V_170 -> V_137 ;
F_23 ( L_44 ,
V_299 ? L_45 : L_46 , V_170 -> V_120 , V_170 -> V_118 ,
V_135 -> V_142 , V_135 -> V_145 , V_135 -> V_144 , V_135 -> V_147 ,
V_137 -> V_143 , V_137 -> V_146 ) ;
}
return - V_107 ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_299 ;
for ( V_299 = 0 ; V_299 < V_172 ; V_299 ++ ) {
F_3 ( V_2 , 0 , F_49 ( V_299 ) ) ;
F_3 ( V_2 , 0 , F_50 ( V_299 ) ) ;
F_3 ( V_2 , 0 , F_51 ( V_299 ) ) ;
}
for ( V_299 = 0 ; V_299 < V_263 ; V_299 ++ ) {
F_3 ( V_2 , 0 , F_85 ( V_299 ) ) ;
F_3 ( V_2 , 0 , F_86 ( V_299 ) ) ;
F_3 ( V_2 , 0 , F_87 ( V_299 ) ) ;
}
}
static int F_98 ( struct V_108 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_7 ( V_2 ) ;
memset ( & V_2 -> V_213 , 0x0 , sizeof( V_2 -> V_213 ) ) ;
F_97 ( V_2 ) ;
return 0 ;
}
static int F_99 ( struct V_108 * V_69 , enum V_303 V_300 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_165 * V_166 = V_59 -> V_166 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
struct V_134 V_152 [ V_304 ] ;
struct V_305 V_306 ;
int V_222 , V_299 ;
T_1 V_307 , V_122 ;
F_12 ( L_47 , V_300 ) ;
if ( ! V_166 ) {
F_23 ( L_20 ) ;
return - V_107 ;
}
V_168 = & V_166 -> V_168 ;
F_15 ( V_2 , true ) ;
F_96 (i) {
V_170 = & V_168 -> V_170 [ V_299 ] ;
V_152 [ V_299 ] = V_170 -> V_135 ;
}
V_222 = F_55 ( V_2 , & V_2 -> V_213 ,
& V_152 [ V_175 ] ,
& V_152 [ V_264 ] ) ;
if ( V_222 ) {
F_18 ( V_69 , L_48 ) ;
return V_222 ;
}
F_14 ( V_2 , false ) ;
F_62 ( V_2 , & V_2 -> V_213 ) ;
F_13 ( V_2 , & V_2 -> V_43 ) ;
switch ( V_300 ) {
case V_308 :
F_11 ( V_2 , V_38 ) ;
F_24 ( V_2 , false ) ;
V_307 = F_1 ( V_2 , V_10 ) ;
V_307 &= ~ V_309 ;
V_307 |= V_310 ;
F_3 ( V_2 , V_307 , V_10 ) ;
break;
case V_301 :
F_11 ( V_2 , V_33 ) ;
F_24 ( V_2 , true ) ;
V_222 = F_9 ( V_2 ) ;
if ( V_222 < 0 ) {
F_18 ( V_69 , L_49 ) ;
return V_222 ;
}
V_306 . V_52 = 1 ;
V_306 . V_311 = V_168 -> V_312 ;
F_100 ( V_313 , ( void * ) & V_306 ) ;
break;
case V_314 :
default:
V_222 = - V_107 ;
F_18 ( V_69 , L_50 ) ;
return V_222 ;
}
F_3 ( V_2 , 0x0 , V_9 ) ;
V_307 = F_1 ( V_2 , V_14 ) ;
V_307 &= ~ V_15 ;
V_307 |= V_15 ;
V_122 = F_1 ( V_2 , V_78 ) ;
V_122 &= ~ V_315 ;
V_122 |= ( V_316 |
V_317 ) ;
F_3 ( V_2 , V_122 , V_78 ) ;
V_307 |= V_16 ;
F_3 ( V_2 , V_307 , V_14 ) ;
F_6 ( V_2 , V_17 , V_318 ) ;
F_6 ( V_2 , V_75 , V_319 ) ;
if ( V_300 == V_308 ) {
F_5 ( V_2 , V_10 , V_11 ) ;
F_5 ( V_2 , V_10 , V_11 ) ;
}
return 0 ;
}
static void F_101 ( struct V_108 * V_69 , enum V_303 V_300 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_305 V_306 = { 0 , 0 } ;
T_1 V_8 ;
F_12 ( L_47 , V_300 ) ;
switch ( V_300 ) {
case V_308 :
V_8 = F_1 ( V_2 , V_10 ) ;
V_8 &= ~ V_309 ;
V_8 &= ~ V_11 ;
F_3 ( V_2 , V_8 , V_10 ) ;
break;
case V_301 :
F_100 ( V_313 , ( void * ) & V_306 ) ;
break;
case V_314 :
default:
F_18 ( V_69 , L_50 ) ;
break;
}
F_15 ( V_2 , false ) ;
F_3 ( V_2 , 0x0 , V_19 ) ;
F_6 ( V_2 , V_78 , V_317 ) ;
F_6 ( V_2 , V_14 ,
V_15 | V_16 ) ;
F_5 ( V_2 , V_17 , V_318 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
int V_299 ;
for ( V_299 = 0 ; V_299 < V_320 ; V_299 ++ ) {
if ( F_103 ( V_2 -> V_265 [ V_299 ] ) )
continue;
F_104 ( V_2 -> V_265 [ V_299 ] ) ;
V_2 -> V_265 [ V_299 ] = F_105 ( - V_107 ) ;
}
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_108 * V_321 = V_2 -> V_59 . V_69 ;
struct V_108 * V_69 ;
int V_222 , V_299 ;
for ( V_299 = 0 ; V_299 < V_320 ; V_299 ++ )
V_2 -> V_265 [ V_299 ] = F_105 ( - V_107 ) ;
for ( V_299 = 0 ; V_299 < V_320 ; V_299 ++ ) {
if ( V_299 == V_267 || V_299 == V_322 )
V_69 = V_321 -> V_323 ;
else
V_69 = V_321 ;
V_2 -> V_265 [ V_299 ] = F_107 ( V_69 , V_324 [ V_299 ] ) ;
if ( F_103 ( V_2 -> V_265 [ V_299 ] ) ) {
if ( V_299 >= V_325 )
break;
V_222 = F_108 ( V_2 -> V_265 [ V_299 ] ) ;
F_18 ( V_321 , L_51 ,
V_324 [ V_299 ] ) ;
goto V_326;
}
}
if ( ! F_103 ( V_2 -> V_265 [ V_327 ] ) ) {
V_222 = F_109 ( V_2 -> V_265 [ V_325 ] ,
V_2 -> V_265 [ V_327 ] ) ;
if ( V_222 < 0 ) {
F_18 ( V_321 , L_52 ) ;
goto V_326;
}
}
V_222 = F_110 ( V_2 -> V_265 [ V_328 ] , V_2 -> V_329 ) ;
if ( V_222 < 0 )
goto V_326;
V_222 = F_89 ( V_2 -> V_265 [ V_328 ] ) ;
if ( ! V_222 )
return V_222 ;
V_326:
F_102 ( V_2 ) ;
return V_222 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_330 * V_331 = V_2 -> V_59 . V_69 -> V_332 ;
if ( ! F_112 ( V_331 , L_53 ) )
return - V_333 ;
if ( F_113 ( V_331 , L_54 ,
& V_2 -> V_329 ) )
V_2 -> V_329 = V_334 ;
V_2 -> V_23 = F_114 ( V_331 , L_55 ) ;
if ( V_2 -> V_23 < 0 ) {
F_18 ( V_2 -> V_59 . V_69 , L_56 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_115 ( struct V_335 * V_336 )
{
struct V_108 * V_69 = & V_336 -> V_69 ;
struct V_1 * V_2 ;
struct V_337 * V_338 ;
struct V_58 * V_59 ;
int V_222 ;
if ( ! V_69 -> V_332 ) {
F_18 ( V_69 , L_57 ) ;
return - V_333 ;
}
V_2 = F_116 ( V_69 , sizeof( * V_2 ) , V_339 ) ;
if ( ! V_2 )
return - V_173 ;
V_2 -> V_59 . V_69 = V_69 ;
V_222 = F_111 ( V_2 ) ;
if ( V_222 < 0 )
return V_222 ;
V_2 -> V_20 = F_117 ( V_69 -> V_332 ,
L_58 ) ;
if ( F_103 ( V_2 -> V_20 ) ) {
F_18 ( V_69 , L_59 ) ;
return F_108 ( V_2 -> V_20 ) ;
}
V_2 -> V_340 = F_118 ( V_336 , V_341 , 0 ) ;
V_2 -> V_4 = F_119 ( V_69 , V_2 -> V_340 ) ;
if ( F_103 ( V_2 -> V_4 ) )
return F_108 ( V_2 -> V_4 ) ;
V_338 = F_118 ( V_336 , V_342 , 0 ) ;
if ( ! V_338 ) {
F_18 ( V_69 , L_60 ) ;
return - V_343 ;
}
V_2 -> V_269 = V_338 -> V_344 ;
V_222 = F_120 ( V_69 , V_2 -> V_269 , NULL , F_91 ,
V_345 , L_61 , V_2 ) ;
if ( V_222 < 0 ) {
F_18 ( V_69 , L_62 ) ;
return V_222 ;
}
V_222 = F_106 ( V_2 ) ;
if ( V_222 < 0 )
return V_222 ;
V_59 = & V_2 -> V_59 ;
V_59 -> V_346 [ V_175 ] = & V_347 ;
V_59 -> V_346 [ V_264 ] = & V_348 ;
V_59 -> V_349 = F_95 ;
V_59 -> V_350 = F_98 ;
V_59 -> V_344 = F_99 ;
V_59 -> V_351 = F_101 ;
V_222 = F_93 ( V_59 ) ;
if ( V_222 < 0 ) {
F_18 ( V_69 , L_63 ) ;
goto V_352;
}
F_12 ( L_64 , V_2 -> V_23 , ( int ) V_59 ) ;
F_121 ( & V_2 -> V_259 ) ;
F_122 ( V_336 , V_2 ) ;
F_123 ( V_69 ) ;
F_124 ( V_69 ) ;
V_222 = F_125 ( V_59 ) ;
if ( V_222 < 0 ) {
F_18 ( V_69 , L_65 ) ;
goto V_353;
}
F_48 ( V_69 , L_66 ) ;
return 0 ;
V_353:
F_126 ( V_69 ) ;
V_352:
F_102 ( V_2 ) ;
return V_222 ;
}
static int F_127 ( struct V_335 * V_336 )
{
struct V_108 * V_69 = & V_336 -> V_69 ;
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_58 * V_59 = & V_2 -> V_59 ;
F_128 ( V_59 ) ;
F_102 ( V_2 ) ;
F_129 ( V_69 ) ;
F_126 ( V_69 ) ;
return 0 ;
}
static int F_130 ( struct V_108 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_12 ( L_67 , V_2 -> V_23 ) ;
if ( F_131 ( V_69 ) )
return 0 ;
return F_88 ( V_2 , false ) ;
}
static int F_132 ( struct V_108 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_12 ( L_67 , V_2 -> V_23 ) ;
if ( ! F_131 ( V_69 ) )
return F_88 ( V_2 , true ) ;
return 0 ;
}
static int F_133 ( struct V_108 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_12 ( L_67 , V_2 -> V_23 ) ;
return F_88 ( V_2 , false ) ;
}
static int F_134 ( struct V_108 * V_69 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
F_12 ( L_67 , V_2 -> V_23 ) ;
return F_88 ( V_2 , true ) ;
}
