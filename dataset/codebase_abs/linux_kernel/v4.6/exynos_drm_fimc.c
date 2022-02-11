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
static void F_13 ( struct V_1 * V_2 , bool V_42 )
{
T_1 V_8 ;
F_12 ( L_2 , V_42 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
if ( V_42 )
V_8 |= V_43 ;
else
V_8 &= ~ V_43 ;
F_3 ( V_2 , V_8 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 , bool V_42 )
{
T_1 V_8 ;
F_12 ( L_2 , V_42 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
if ( V_42 ) {
V_8 &= ~ V_44 ;
V_8 |= V_45 | V_46 ;
} else
V_8 &= ~ V_45 ;
F_3 ( V_2 , V_8 , V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_17 , V_47 ) ;
}
static bool F_16 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = & V_2 -> V_49 ;
T_1 V_50 , V_51 ;
V_50 = F_1 ( V_2 , V_9 ) ;
V_51 = V_52 | V_53 |
V_54 ;
F_12 ( L_3 , V_51 ) ;
if ( V_50 & V_51 ) {
F_5 ( V_2 , V_55 ,
V_56 | V_57 |
V_58 ) ;
F_17 ( V_49 -> V_59 , L_4 ,
V_2 -> V_23 , V_50 ) ;
return true ;
}
return false ;
}
static bool F_18 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 , V_9 ) ;
F_12 ( L_5 , V_8 ) ;
if ( ! ( V_8 & V_60 ) )
return false ;
V_8 &= ~ ( V_60 ) ;
F_3 ( V_2 , V_8 , V_9 ) ;
return true ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_1 V_8 ;
int V_61 , V_62 ;
V_8 = F_1 ( V_2 , V_63 ) ;
V_61 = F_20 ( V_8 ) ;
if ( V_61 == 0 )
V_61 = F_21 ( V_8 ) ;
F_12 ( L_6 ,
F_21 ( V_8 ) ,
F_20 ( V_8 ) ) ;
if ( V_61 == 0 ) {
F_22 ( L_7 ) ;
return - V_64 ;
}
V_62 = V_61 - 1 ;
F_12 ( L_8 , V_62 ) ;
return V_62 ;
}
static void F_23 ( struct V_1 * V_2 , bool V_42 )
{
T_1 V_8 ;
F_12 ( L_2 , V_42 ) ;
V_8 = F_1 ( V_2 , V_65 ) ;
if ( V_42 )
V_8 |= V_66 ;
else
V_8 &= ~ V_66 ;
F_3 ( V_2 , V_8 , V_65 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_48 * V_49 = & V_2 -> V_49 ;
T_1 V_8 ;
F_12 ( L_9 , V_67 ) ;
V_8 = F_1 ( V_2 , V_68 ) ;
V_8 &= ~ V_69 ;
switch ( V_67 ) {
case V_70 :
V_8 |= V_71 ;
F_3 ( V_2 , V_8 , V_68 ) ;
return 0 ;
case V_72 :
case V_73 :
V_8 |= V_74 ;
F_3 ( V_2 , V_8 , V_68 ) ;
return 0 ;
default:
break;
}
V_8 = F_1 ( V_2 , V_10 ) ;
V_8 &= ~ ( V_75 |
V_76 |
V_77 ) ;
switch ( V_67 ) {
case V_78 :
V_8 |= V_77 ;
break;
case V_79 :
V_8 |= V_80 ;
break;
case V_81 :
V_8 |= V_82 ;
break;
case V_83 :
case V_84 :
V_8 |= V_85 ;
break;
case V_86 :
case V_87 :
V_8 |= ( V_88 |
V_76 ) ;
break;
case V_89 :
case V_90 :
case V_91 :
V_8 |= V_92 ;
break;
case V_93 :
case V_94 :
V_8 |= ( V_95 |
V_76 ) ;
break;
default:
F_17 ( V_49 -> V_59 , L_10 , V_67 ) ;
return - V_96 ;
}
F_3 ( V_2 , V_8 , V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_97 * V_59 , T_1 V_67 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
T_1 V_8 ;
F_12 ( L_9 , V_67 ) ;
V_8 = F_1 ( V_2 , V_10 ) ;
V_8 &= ~ V_98 ;
switch ( V_67 ) {
case V_70 :
case V_72 :
case V_73 :
V_8 |= V_98 ;
break;
case V_84 :
V_8 |= V_99 ;
break;
case V_78 :
case V_79 :
case V_81 :
case V_83 :
V_8 |= V_100 ;
break;
case V_94 :
case V_87 :
case V_89 :
V_8 |= V_101 ;
break;
case V_90 :
case V_91 :
case V_93 :
case V_86 :
V_8 |= V_99 ;
break;
default:
F_17 ( V_49 -> V_59 , L_11 , V_67 ) ;
return - V_96 ;
}
F_3 ( V_2 , V_8 , V_10 ) ;
V_8 = F_1 ( V_2 , V_102 ) ;
V_8 &= ~ V_103 ;
V_8 |= V_104 ;
F_3 ( V_2 , V_8 , V_102 ) ;
return F_24 ( V_2 , V_67 ) ;
}
static int F_27 ( struct V_97 * V_59 ,
enum V_105 V_106 ,
enum V_107 V_108 , bool * V_109 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
T_1 V_110 , V_111 ;
F_12 ( L_12 , V_106 , V_108 ) ;
V_110 = F_1 ( V_2 , V_10 ) ;
V_110 &= ~ ( V_112 |
V_113 ) ;
V_111 = F_1 ( V_2 , V_114 ) ;
V_111 &= ~ V_115 ;
switch ( V_106 ) {
case V_116 :
if ( V_108 & V_117 )
V_110 |= V_112 ;
if ( V_108 & V_118 )
V_110 |= V_113 ;
break;
case V_119 :
V_111 |= V_115 ;
if ( V_108 & V_117 )
V_110 |= V_112 ;
if ( V_108 & V_118 )
V_110 |= V_113 ;
break;
case V_120 :
V_110 |= ( V_112 |
V_113 ) ;
if ( V_108 & V_117 )
V_110 &= ~ V_112 ;
if ( V_108 & V_118 )
V_110 &= ~ V_113 ;
break;
case V_121 :
V_110 |= ( V_112 |
V_113 ) ;
V_111 |= V_115 ;
if ( V_108 & V_117 )
V_110 &= ~ V_112 ;
if ( V_108 & V_118 )
V_110 &= ~ V_113 ;
break;
default:
F_17 ( V_49 -> V_59 , L_13 , V_106 ) ;
return - V_96 ;
}
F_3 ( V_2 , V_110 , V_10 ) ;
F_3 ( V_2 , V_111 , V_114 ) ;
* V_109 = ( V_111 & V_115 ) ? 1 : 0 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_122 * V_123 , struct V_124 * V_125 )
{
T_1 V_8 , V_126 , V_127 , V_128 , V_129 ;
V_126 = V_123 -> V_130 ;
V_127 = V_125 -> V_131 - V_123 -> V_132 - V_123 -> V_130 ;
V_128 = V_123 -> V_133 ;
V_129 = V_125 -> V_134 - V_123 -> V_135 - V_123 -> V_133 ;
F_12 ( L_14 ,
V_123 -> V_130 , V_123 -> V_133 , V_123 -> V_132 , V_123 -> V_135 , V_125 -> V_131 , V_125 -> V_134 ) ;
F_12 ( L_15 , V_126 , V_127 , V_128 , V_129 ) ;
V_8 = F_1 ( V_2 , V_55 ) ;
V_8 &= ~ ( V_136 |
V_137 ) ;
V_8 |= ( F_29 ( V_126 ) |
F_30 ( V_128 ) ) ;
V_8 |= V_138 ;
F_3 ( V_2 , V_8 , V_55 ) ;
V_8 = ( F_31 ( V_127 ) |
F_32 ( V_129 ) ) ;
F_3 ( V_2 , V_8 , V_139 ) ;
return 0 ;
}
static int F_33 ( struct V_97 * V_59 , int V_109 ,
struct V_122 * V_123 , struct V_124 * V_125 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_122 V_140 = * V_123 ;
struct V_124 V_141 = * V_125 ;
T_1 V_8 ;
F_12 ( L_16 ,
V_109 , V_125 -> V_131 , V_125 -> V_134 ) ;
V_8 = ( F_34 ( V_141 . V_131 ) |
F_35 ( V_141 . V_134 ) ) ;
F_3 ( V_2 , V_8 , V_142 ) ;
F_12 ( L_17 , V_123 -> V_130 , V_123 -> V_133 , V_123 -> V_132 , V_123 -> V_135 ) ;
if ( V_109 ) {
V_140 . V_132 = V_123 -> V_135 ;
V_140 . V_135 = V_123 -> V_132 ;
V_141 . V_131 = V_125 -> V_134 ;
V_141 . V_134 = V_125 -> V_131 ;
}
V_8 = F_1 ( V_2 , V_143 ) ;
V_8 &= ~ ( V_144 |
V_145 ) ;
V_8 |= ( F_36 ( V_140 . V_132 ) |
F_37 ( V_140 . V_135 ) ) ;
F_3 ( V_2 , V_8 , V_143 ) ;
V_8 = ( V_13 |
F_38 ( V_141 . V_131 ) |
F_39 ( V_141 . V_134 ) ) ;
F_3 ( V_2 , V_8 , V_12 ) ;
V_8 = ( F_40 ( V_140 . V_130 ) |
F_41 ( V_140 . V_133 ) ) ;
F_3 ( V_2 , V_8 , V_146 ) ;
V_8 = ( F_42 ( V_140 . V_130 ) |
F_43 ( V_140 . V_133 ) ) ;
F_3 ( V_2 , V_8 , V_147 ) ;
V_8 = ( F_44 ( V_140 . V_130 ) |
F_45 ( V_140 . V_133 ) ) ;
F_3 ( V_2 , V_8 , V_148 ) ;
return F_28 ( V_2 , & V_140 , & V_141 ) ;
}
static int F_46 ( struct V_97 * V_59 ,
struct V_149 * V_150 , T_1 V_62 ,
enum V_151 V_152 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_153 * V_154 = V_49 -> V_154 ;
struct V_155 * V_156 ;
struct V_157 * V_158 ;
if ( ! V_154 ) {
F_22 ( L_18 ) ;
return - V_96 ;
}
V_156 = & V_154 -> V_156 ;
F_12 ( L_19 ,
V_156 -> V_159 , V_62 , V_152 ) ;
if ( V_62 > V_160 ) {
F_47 ( V_49 -> V_59 , L_20 , V_62 ) ;
return - V_161 ;
}
switch ( V_152 ) {
case V_162 :
V_158 = & V_156 -> V_158 [ V_163 ] ;
F_3 ( V_2 , V_150 -> V_164 [ V_165 ] ,
V_166 ) ;
if ( V_158 -> V_67 == V_91 ) {
F_3 ( V_2 , V_150 -> V_164 [ V_167 ] ,
V_168 ) ;
F_3 ( V_2 , V_150 -> V_164 [ V_169 ] ,
V_170 ) ;
} else {
F_3 ( V_2 , V_150 -> V_164 [ V_169 ] ,
V_168 ) ;
F_3 ( V_2 , V_150 -> V_164 [ V_167 ] ,
V_170 ) ;
}
break;
case V_171 :
F_3 ( V_2 , 0x0 , V_166 ) ;
F_3 ( V_2 , 0x0 , V_168 ) ;
F_3 ( V_2 , 0x0 , V_170 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_48 * V_49 = & V_2 -> V_49 ;
T_1 V_8 ;
F_12 ( L_9 , V_67 ) ;
V_8 = F_1 ( V_2 , V_68 ) ;
V_8 &= ~ V_172 ;
switch ( V_67 ) {
case V_70 :
V_8 |= V_173 ;
F_3 ( V_2 , V_8 , V_68 ) ;
return 0 ;
case V_72 :
V_8 |= V_174 ;
F_3 ( V_2 , V_8 , V_68 ) ;
return 0 ;
case V_73 :
V_8 |= ( V_174 |
V_175 ) ;
F_3 ( V_2 , V_8 , V_68 ) ;
break;
default:
break;
}
V_8 = F_1 ( V_2 , V_65 ) ;
V_8 &= ~ ( V_176 |
V_177 |
V_178 ) ;
switch ( V_67 ) {
case V_73 :
V_8 |= V_179 ;
break;
case V_78 :
V_8 |= V_180 ;
break;
case V_79 :
V_8 |= V_181 ;
break;
case V_81 :
V_8 |= V_182 ;
break;
case V_83 :
V_8 |= V_183 ;
break;
case V_86 :
case V_87 :
V_8 |= V_184 ;
V_8 |= V_185 ;
break;
case V_89 :
case V_90 :
case V_91 :
V_8 |= V_186 ;
break;
case V_93 :
case V_94 :
V_8 |= V_187 ;
V_8 |= V_185 ;
break;
default:
F_17 ( V_49 -> V_59 , L_21 , V_67 ) ;
return - V_96 ;
}
F_3 ( V_2 , V_8 , V_65 ) ;
return 0 ;
}
static int F_49 ( struct V_97 * V_59 , T_1 V_67 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
T_1 V_8 ;
F_12 ( L_9 , V_67 ) ;
V_8 = F_1 ( V_2 , V_188 ) ;
if ( V_67 == V_189 ) {
V_8 |= V_190 ;
F_3 ( V_2 , V_8 , V_188 ) ;
} else {
V_8 &= ~ V_190 ;
F_3 ( V_2 , V_8 , V_188 ) ;
V_8 = F_1 ( V_2 , V_114 ) ;
V_8 &= ~ V_191 ;
switch ( V_67 ) {
case V_70 :
case V_72 :
case V_73 :
V_8 |= V_192 ;
break;
case V_78 :
case V_79 :
case V_81 :
case V_83 :
V_8 |= V_193 ;
break;
case V_94 :
case V_87 :
case V_89 :
V_8 |= V_194 ;
break;
case V_90 :
case V_91 :
case V_93 :
case V_86 :
V_8 |= V_195 ;
break;
default:
F_17 ( V_49 -> V_59 , L_22 ,
V_67 ) ;
return - V_96 ;
}
F_3 ( V_2 , V_8 , V_114 ) ;
}
V_8 = F_1 ( V_2 , V_102 ) ;
V_8 &= ~ V_196 ;
V_8 |= V_197 ;
F_3 ( V_2 , V_8 , V_102 ) ;
return F_48 ( V_2 , V_67 ) ;
}
static int F_50 ( struct V_97 * V_59 ,
enum V_105 V_106 ,
enum V_107 V_108 , bool * V_109 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
T_1 V_8 ;
F_12 ( L_12 , V_106 , V_108 ) ;
V_8 = F_1 ( V_2 , V_114 ) ;
V_8 &= ~ V_198 ;
V_8 &= ~ V_199 ;
switch ( V_106 ) {
case V_116 :
if ( V_108 & V_117 )
V_8 |= V_200 ;
if ( V_108 & V_118 )
V_8 |= V_201 ;
break;
case V_119 :
V_8 |= V_199 ;
if ( V_108 & V_117 )
V_8 |= V_200 ;
if ( V_108 & V_118 )
V_8 |= V_201 ;
break;
case V_120 :
V_8 |= ( V_200 |
V_201 ) ;
if ( V_108 & V_117 )
V_8 &= ~ V_200 ;
if ( V_108 & V_118 )
V_8 &= ~ V_201 ;
break;
case V_121 :
V_8 |= ( V_199 |
V_200 |
V_201 ) ;
if ( V_108 & V_117 )
V_8 &= ~ V_200 ;
if ( V_108 & V_118 )
V_8 &= ~ V_201 ;
break;
default:
F_17 ( V_49 -> V_59 , L_13 , V_106 ) ;
return - V_96 ;
}
F_3 ( V_2 , V_8 , V_114 ) ;
* V_109 = ( V_8 & V_199 ) ? 1 : 0 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_202 * V_203 ,
struct V_122 * V_204 , struct V_122 * V_205 )
{
struct V_48 * V_49 = & V_2 -> V_49 ;
T_1 V_8 , V_206 , V_207 ;
T_1 V_208 , V_209 ;
T_1 V_210 , V_211 ;
int V_212 = 0 ;
T_1 V_213 , V_214 , V_215 , V_216 ;
V_206 = F_1 ( V_2 , V_114 ) ;
if ( V_206 & V_115 ) {
V_213 = V_204 -> V_135 ;
V_214 = V_204 -> V_132 ;
} else {
V_213 = V_204 -> V_132 ;
V_214 = V_204 -> V_135 ;
}
if ( V_206 & V_199 ) {
V_215 = V_205 -> V_135 ;
V_216 = V_205 -> V_132 ;
} else {
V_215 = V_205 -> V_132 ;
V_216 = V_205 -> V_135 ;
}
V_210 = F_52 ( V_213 / V_215 / 2 ) ;
if ( V_210 > V_217 / 2 ) {
F_17 ( V_49 -> V_59 , L_23 ) ;
return - V_96 ;
}
V_211 = F_52 ( V_214 / V_216 / 2 ) ;
if ( V_211 > V_217 / 2 ) {
F_17 ( V_49 -> V_59 , L_24 ) ;
return - V_96 ;
}
V_208 = V_213 >> V_210 ;
V_209 = V_214 >> V_211 ;
F_12 ( L_25 ,
V_208 , V_209 ) ;
F_12 ( L_26 , V_210 , V_211 ) ;
V_203 -> V_218 = ( V_213 << 14 ) / ( V_215 << V_210 ) ;
V_203 -> V_219 = ( V_214 << 14 ) / ( V_216 << V_211 ) ;
V_203 -> V_220 = ( V_215 >= V_213 ) ? true : false ;
V_203 -> V_221 = ( V_216 >= V_214 ) ? true : false ;
F_12 ( L_27 ,
V_203 -> V_218 , V_203 -> V_219 , V_203 -> V_220 , V_203 -> V_221 ) ;
V_207 = V_217 - ( V_210 + V_211 ) ;
F_12 ( L_28 , V_207 ) ;
V_8 = ( F_53 ( V_207 ) |
F_54 ( 1 << V_210 ) |
F_55 ( 1 << V_211 ) ) ;
F_3 ( V_2 , V_8 , V_222 ) ;
V_8 = ( F_56 ( V_208 ) |
F_57 ( V_209 ) ) ;
F_3 ( V_2 , V_8 , V_223 ) ;
return V_212 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_202 * V_203 )
{
T_1 V_8 , V_206 ;
F_12 ( L_29 ,
V_203 -> V_224 , V_203 -> V_225 , V_203 -> V_220 , V_203 -> V_221 ) ;
F_12 ( L_30 ,
V_203 -> V_218 , V_203 -> V_219 ) ;
V_8 = F_1 ( V_2 , V_68 ) ;
V_8 &= ~ ( V_226 |
V_227 | V_228 |
V_229 |
V_230 |
V_231 |
V_232 ) ;
if ( V_203 -> V_224 )
V_8 |= ( V_231 |
V_232 ) ;
if ( V_203 -> V_225 )
V_8 |= V_226 ;
if ( V_203 -> V_220 )
V_8 |= V_227 ;
if ( V_203 -> V_221 )
V_8 |= V_228 ;
V_8 |= ( F_59 ( ( V_203 -> V_218 >> 6 ) ) |
F_60 ( ( V_203 -> V_219 >> 6 ) ) ) ;
F_3 ( V_2 , V_8 , V_68 ) ;
V_206 = F_1 ( V_2 , V_188 ) ;
V_206 &= ~ V_233 ;
V_206 &= ~ V_234 ;
V_206 |= ( F_61 ( V_203 -> V_218 ) |
F_62 ( V_203 -> V_219 ) ) ;
F_3 ( V_2 , V_206 , V_188 ) ;
}
static int F_63 ( struct V_97 * V_59 , int V_109 ,
struct V_122 * V_123 , struct V_124 * V_125 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_122 V_140 = * V_123 ;
struct V_124 V_141 = * V_125 ;
T_1 V_8 ;
F_12 ( L_16 ,
V_109 , V_125 -> V_131 , V_125 -> V_134 ) ;
V_8 = ( F_64 ( V_141 . V_131 ) |
F_65 ( V_141 . V_134 ) ) ;
F_3 ( V_2 , V_8 , V_235 ) ;
F_12 ( L_17 , V_123 -> V_130 , V_123 -> V_133 , V_123 -> V_132 , V_123 -> V_135 ) ;
V_8 = F_1 ( V_2 , V_17 ) ;
V_8 &= ~ V_236 ;
if ( V_125 -> V_131 >= V_237 )
V_8 |= V_238 ;
else
V_8 |= V_239 ;
F_3 ( V_2 , V_8 , V_17 ) ;
if ( V_109 ) {
V_140 . V_132 = V_123 -> V_135 ;
V_140 . V_135 = V_123 -> V_132 ;
V_141 . V_131 = V_125 -> V_134 ;
V_141 . V_134 = V_125 -> V_131 ;
}
V_8 = F_1 ( V_2 , V_114 ) ;
V_8 &= ~ ( V_240 |
V_241 ) ;
V_8 |= ( F_66 ( V_140 . V_132 ) |
F_67 ( V_140 . V_135 ) ) ;
F_3 ( V_2 , V_8 , V_114 ) ;
V_8 = F_68 ( V_140 . V_132 * V_140 . V_135 ) ;
F_3 ( V_2 , V_8 , V_242 ) ;
V_8 = ( F_69 ( V_140 . V_130 ) |
F_70 ( V_140 . V_133 ) ) ;
F_3 ( V_2 , V_8 , V_243 ) ;
V_8 = ( F_71 ( V_140 . V_130 ) |
F_72 ( V_140 . V_133 ) ) ;
F_3 ( V_2 , V_8 , V_244 ) ;
V_8 = ( F_73 ( V_140 . V_130 ) |
F_74 ( V_140 . V_133 ) ) ;
F_3 ( V_2 , V_8 , V_245 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , T_1 V_62 ,
enum V_151 V_152 )
{
unsigned long V_246 ;
T_1 V_247 ;
T_1 V_8 ;
F_12 ( L_31 , V_62 , V_152 ) ;
F_76 ( & V_2 -> V_248 , V_246 ) ;
V_8 = F_1 ( V_2 , V_19 ) ;
if ( V_152 == V_162 )
V_8 |= ( 1 << V_62 ) ;
else
V_8 &= ~ ( 1 << V_62 ) ;
F_3 ( V_2 , V_8 , V_19 ) ;
V_247 = F_77 ( V_8 ) ;
if ( V_152 == V_162 && V_247 >= V_249 )
F_14 ( V_2 , true ) ;
else if ( V_152 == V_171 && V_247 <= V_250 )
F_14 ( V_2 , false ) ;
F_78 ( & V_2 -> V_248 , V_246 ) ;
}
static int F_79 ( struct V_97 * V_59 ,
struct V_149 * V_150 , T_1 V_62 ,
enum V_151 V_152 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_153 * V_154 = V_49 -> V_154 ;
struct V_155 * V_156 ;
struct V_157 * V_158 ;
if ( ! V_154 ) {
F_22 ( L_18 ) ;
return - V_96 ;
}
V_156 = & V_154 -> V_156 ;
F_12 ( L_19 ,
V_156 -> V_159 , V_62 , V_152 ) ;
if ( V_62 > V_251 ) {
F_47 ( V_49 -> V_59 , L_20 , V_62 ) ;
return - V_161 ;
}
switch ( V_152 ) {
case V_162 :
V_158 = & V_156 -> V_158 [ V_252 ] ;
F_3 ( V_2 , V_150 -> V_164 [ V_165 ] ,
F_80 ( V_62 ) ) ;
if ( V_158 -> V_67 == V_91 ) {
F_3 ( V_2 , V_150 -> V_164 [ V_167 ] ,
F_81 ( V_62 ) ) ;
F_3 ( V_2 , V_150 -> V_164 [ V_169 ] ,
F_82 ( V_62 ) ) ;
} else {
F_3 ( V_2 , V_150 -> V_164 [ V_169 ] ,
F_81 ( V_62 ) ) ;
F_3 ( V_2 , V_150 -> V_164 [ V_167 ] ,
F_82 ( V_62 ) ) ;
}
break;
case V_171 :
F_3 ( V_2 , 0x0 , F_80 ( V_62 ) ) ;
F_3 ( V_2 , 0x0 , F_81 ( V_62 ) ) ;
F_3 ( V_2 , 0x0 , F_82 ( V_62 ) ) ;
break;
default:
break;
}
F_75 ( V_2 , V_62 , V_152 ) ;
return 0 ;
}
static T_3 F_83 ( int V_253 , void * V_254 )
{
struct V_1 * V_2 = V_254 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_153 * V_154 = V_49 -> V_154 ;
struct V_255 * V_256 =
V_154 -> V_256 ;
int V_62 ;
F_12 ( L_32 , V_2 -> V_23 ) ;
F_15 ( V_2 ) ;
if ( F_16 ( V_2 ) )
return V_257 ;
if ( ! F_18 ( V_2 ) )
return V_257 ;
V_62 = F_19 ( V_2 ) ;
if ( V_62 < 0 )
return V_258 ;
F_12 ( L_8 , V_62 ) ;
F_75 ( V_2 , V_62 , V_171 ) ;
V_256 -> V_49 = V_49 ;
V_256 -> V_62 [ V_252 ] = V_62 ;
F_84 ( V_49 -> V_259 , & V_256 -> V_260 ) ;
return V_258 ;
}
static int F_85 ( struct V_48 * V_49 )
{
struct V_261 * V_262 = & V_49 -> V_262 ;
V_262 -> V_263 = 1 ;
V_262 -> V_264 = 1 ;
V_262 -> V_265 = V_266 ;
V_262 -> V_267 = V_268 ;
V_262 -> V_108 = ( 1 << V_269 ) |
( 1 << V_117 ) |
( 1 << V_118 ) ;
V_262 -> V_106 = ( 1 << V_116 ) |
( 1 << V_119 ) |
( 1 << V_120 ) |
( 1 << V_121 ) ;
V_262 -> V_270 = 1 ;
V_262 -> V_271 = 1 ;
V_262 -> V_272 . V_131 = V_273 ;
V_262 -> V_272 . V_134 = V_273 ;
V_262 -> V_274 . V_131 = V_275 ;
V_262 -> V_274 . V_134 = V_275 ;
V_262 -> V_276 = 1 ;
V_262 -> V_277 . V_131 = V_278 ;
V_262 -> V_277 . V_134 = V_278 ;
V_262 -> V_279 . V_131 = V_280 ;
V_262 -> V_279 . V_134 = V_280 ;
return 0 ;
}
static inline bool F_86 ( enum V_107 V_108 )
{
switch ( V_108 ) {
case V_269 :
case V_117 :
case V_118 :
case V_281 :
return true ;
default:
F_12 ( L_33 ) ;
return false ;
}
}
static int F_87 ( struct V_97 * V_59 ,
struct V_155 * V_156 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_261 * V_282 = & V_49 -> V_262 ;
struct V_157 * V_158 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
bool V_109 ;
int V_283 ;
F_88 (i) {
if ( ( V_283 == V_163 ) &&
( V_156 -> V_284 == V_285 ) )
continue;
V_158 = & V_156 -> V_158 [ V_283 ] ;
V_123 = & V_158 -> V_123 ;
V_125 = & V_158 -> V_125 ;
if ( ! F_86 ( V_158 -> V_108 ) ) {
F_22 ( L_34 ) ;
goto V_286;
}
switch ( V_158 -> V_106 ) {
case V_119 :
case V_121 :
V_109 = true ;
break;
case V_116 :
case V_120 :
V_109 = false ;
break;
default:
F_22 ( L_35 ) ;
goto V_286;
}
if ( ( V_123 -> V_130 + V_123 -> V_132 > V_125 -> V_131 ) ||
( V_123 -> V_133 + V_123 -> V_135 > V_125 -> V_134 ) ) {
F_22 ( L_36 ) ;
goto V_286;
}
if ( ( V_283 == V_163 ) && ( V_282 -> V_271 ) ) {
if ( V_109 ) {
if ( ( V_123 -> V_135 < V_282 -> V_274 . V_131 ) ||
( V_125 -> V_134 > V_282 -> V_272 . V_131 ) ||
( V_123 -> V_132 < V_282 -> V_274 . V_134 ) ||
( V_125 -> V_131 > V_282 -> V_272 . V_134 ) ) {
F_22 ( L_37 ) ;
goto V_286;
}
} else {
if ( ( V_123 -> V_132 < V_282 -> V_274 . V_131 ) ||
( V_125 -> V_131 > V_282 -> V_272 . V_131 ) ||
( V_123 -> V_135 < V_282 -> V_274 . V_134 ) ||
( V_125 -> V_134 > V_282 -> V_272 . V_134 ) ) {
F_22 ( L_37 ) ;
goto V_286;
}
}
}
if ( ( V_283 == V_252 ) && ( V_282 -> V_276 ) ) {
if ( V_109 ) {
if ( ( V_123 -> V_135 < V_282 -> V_279 . V_131 ) ||
( V_125 -> V_134 > V_282 -> V_277 . V_131 ) ||
( V_123 -> V_132 < V_282 -> V_279 . V_134 ) ||
( V_125 -> V_131 > V_282 -> V_277 . V_134 ) ) {
F_22 ( L_38 ) ;
goto V_286;
}
} else {
if ( ( V_123 -> V_132 < V_282 -> V_279 . V_131 ) ||
( V_125 -> V_131 > V_282 -> V_277 . V_131 ) ||
( V_123 -> V_135 < V_282 -> V_279 . V_134 ) ||
( V_125 -> V_134 > V_282 -> V_277 . V_134 ) ) {
F_22 ( L_38 ) ;
goto V_286;
}
}
}
}
return 0 ;
V_286:
F_88 (i) {
if ( ( V_283 == V_163 ) &&
( V_156 -> V_284 == V_285 ) )
continue;
V_158 = & V_156 -> V_158 [ V_283 ] ;
V_123 = & V_158 -> V_123 ;
V_125 = & V_158 -> V_125 ;
F_22 ( L_39 ,
V_283 ? L_40 : L_41 , V_158 -> V_108 , V_158 -> V_106 ,
V_123 -> V_130 , V_123 -> V_133 , V_123 -> V_132 , V_123 -> V_135 ,
V_125 -> V_131 , V_125 -> V_134 ) ;
}
return - V_96 ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_283 ;
for ( V_283 = 0 ; V_283 < V_160 ; V_283 ++ ) {
F_3 ( V_2 , 0 , F_90 ( V_283 ) ) ;
F_3 ( V_2 , 0 , F_91 ( V_283 ) ) ;
F_3 ( V_2 , 0 , F_92 ( V_283 ) ) ;
}
for ( V_283 = 0 ; V_283 < V_251 ; V_283 ++ ) {
F_3 ( V_2 , 0 , F_80 ( V_283 ) ) ;
F_3 ( V_2 , 0 , F_81 ( V_283 ) ) ;
F_3 ( V_2 , 0 , F_82 ( V_283 ) ) ;
}
}
static int F_93 ( struct V_97 * V_59 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
F_7 ( V_2 ) ;
memset ( & V_2 -> V_203 , 0x0 , sizeof( V_2 -> V_203 ) ) ;
F_89 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_97 * V_59 , enum V_287 V_284 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_153 * V_154 = V_49 -> V_154 ;
struct V_155 * V_156 ;
struct V_157 * V_158 ;
struct V_122 V_140 [ V_288 ] ;
struct V_289 V_290 ;
int V_212 , V_283 ;
T_1 V_291 , V_110 ;
F_12 ( L_42 , V_284 ) ;
if ( ! V_154 ) {
F_22 ( L_18 ) ;
return - V_96 ;
}
V_156 = & V_154 -> V_156 ;
F_14 ( V_2 , true ) ;
F_88 (i) {
V_158 = & V_156 -> V_158 [ V_283 ] ;
V_140 [ V_283 ] = V_158 -> V_123 ;
}
V_212 = F_51 ( V_2 , & V_2 -> V_203 ,
& V_140 [ V_163 ] ,
& V_140 [ V_252 ] ) ;
if ( V_212 ) {
F_17 ( V_59 , L_43 ) ;
return V_212 ;
}
F_13 ( V_2 , false ) ;
F_58 ( V_2 , & V_2 -> V_203 ) ;
switch ( V_284 ) {
case V_292 :
F_11 ( V_2 , V_38 ) ;
F_23 ( V_2 , false ) ;
V_291 = F_1 ( V_2 , V_10 ) ;
V_291 &= ~ V_293 ;
V_291 |= V_294 ;
F_3 ( V_2 , V_291 , V_10 ) ;
break;
case V_285 :
F_11 ( V_2 , V_33 ) ;
F_23 ( V_2 , true ) ;
V_212 = F_9 ( V_2 ) ;
if ( V_212 < 0 ) {
F_17 ( V_59 , L_44 ) ;
return V_212 ;
}
V_290 . V_42 = 1 ;
V_290 . V_295 = V_156 -> V_296 ;
F_95 ( V_297 , ( void * ) & V_290 ) ;
break;
case V_298 :
default:
V_212 = - V_96 ;
F_17 ( V_59 , L_45 ) ;
return V_212 ;
}
F_3 ( V_2 , 0x0 , V_9 ) ;
V_291 = F_1 ( V_2 , V_14 ) ;
V_291 &= ~ V_15 ;
V_291 |= V_15 ;
V_110 = F_1 ( V_2 , V_68 ) ;
V_110 &= ~ V_299 ;
V_110 |= ( V_300 |
V_301 ) ;
F_3 ( V_2 , V_110 , V_68 ) ;
V_291 |= V_16 ;
F_3 ( V_2 , V_291 , V_14 ) ;
F_6 ( V_2 , V_17 , V_302 ) ;
F_6 ( V_2 , V_65 , V_303 ) ;
if ( V_284 == V_292 )
F_5 ( V_2 , V_10 , V_11 ) ;
return 0 ;
}
static void F_96 ( struct V_97 * V_59 , enum V_287 V_284 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_289 V_290 = { 0 , 0 } ;
T_1 V_8 ;
F_12 ( L_42 , V_284 ) ;
switch ( V_284 ) {
case V_292 :
V_8 = F_1 ( V_2 , V_10 ) ;
V_8 &= ~ V_293 ;
V_8 &= ~ V_11 ;
F_3 ( V_2 , V_8 , V_10 ) ;
break;
case V_285 :
F_95 ( V_297 , ( void * ) & V_290 ) ;
break;
case V_298 :
default:
F_17 ( V_59 , L_45 ) ;
break;
}
F_14 ( V_2 , false ) ;
F_3 ( V_2 , 0x0 , V_19 ) ;
F_6 ( V_2 , V_68 , V_301 ) ;
F_6 ( V_2 , V_14 ,
V_15 | V_16 ) ;
F_5 ( V_2 , V_17 , V_302 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_283 ;
for ( V_283 = 0 ; V_283 < V_304 ; V_283 ++ ) {
if ( F_98 ( V_2 -> V_305 [ V_283 ] ) )
continue;
F_99 ( V_2 -> V_305 [ V_283 ] ) ;
V_2 -> V_305 [ V_283 ] = F_100 ( - V_96 ) ;
}
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_97 * V_306 = V_2 -> V_49 . V_59 ;
struct V_97 * V_59 ;
int V_212 , V_283 ;
for ( V_283 = 0 ; V_283 < V_304 ; V_283 ++ )
V_2 -> V_305 [ V_283 ] = F_100 ( - V_96 ) ;
for ( V_283 = 0 ; V_283 < V_304 ; V_283 ++ ) {
if ( V_283 == V_307 || V_283 == V_308 )
V_59 = V_306 -> V_309 ;
else
V_59 = V_306 ;
V_2 -> V_305 [ V_283 ] = F_102 ( V_59 , V_310 [ V_283 ] ) ;
if ( F_98 ( V_2 -> V_305 [ V_283 ] ) ) {
if ( V_283 >= V_311 )
break;
V_212 = F_103 ( V_2 -> V_305 [ V_283 ] ) ;
F_17 ( V_306 , L_46 ,
V_310 [ V_283 ] ) ;
goto V_312;
}
}
if ( ! F_98 ( V_2 -> V_305 [ V_313 ] ) ) {
V_212 = F_104 ( V_2 -> V_305 [ V_311 ] ,
V_2 -> V_305 [ V_313 ] ) ;
if ( V_212 < 0 ) {
F_17 ( V_306 , L_47 ) ;
goto V_312;
}
}
V_212 = F_105 ( V_2 -> V_305 [ V_314 ] , V_2 -> V_315 ) ;
if ( V_212 < 0 )
goto V_312;
V_212 = F_106 ( V_2 -> V_305 [ V_314 ] ) ;
if ( ! V_212 )
return V_212 ;
V_312:
F_97 ( V_2 ) ;
return V_212 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_316 * V_317 = V_2 -> V_49 . V_59 -> V_318 ;
if ( ! F_108 ( V_317 , L_48 ) )
return - V_319 ;
if ( F_109 ( V_317 , L_49 ,
& V_2 -> V_315 ) )
V_2 -> V_315 = V_320 ;
V_2 -> V_23 = F_110 ( V_317 , L_50 ) ;
if ( V_2 -> V_23 < 0 ) {
F_17 ( V_2 -> V_49 . V_59 , L_51 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_111 ( struct V_321 * V_322 )
{
struct V_97 * V_59 = & V_322 -> V_59 ;
struct V_1 * V_2 ;
struct V_323 * V_324 ;
struct V_48 * V_49 ;
int V_212 ;
if ( ! V_59 -> V_318 ) {
F_17 ( V_59 , L_52 ) ;
return - V_319 ;
}
V_2 = F_112 ( V_59 , sizeof( * V_2 ) , V_325 ) ;
if ( ! V_2 )
return - V_161 ;
V_2 -> V_49 . V_59 = V_59 ;
V_212 = F_107 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_2 -> V_20 = F_113 ( V_59 -> V_318 ,
L_53 ) ;
if ( F_98 ( V_2 -> V_20 ) ) {
F_17 ( V_59 , L_54 ) ;
return F_103 ( V_2 -> V_20 ) ;
}
V_2 -> V_326 = F_114 ( V_322 , V_327 , 0 ) ;
V_2 -> V_4 = F_115 ( V_59 , V_2 -> V_326 ) ;
if ( F_98 ( V_2 -> V_4 ) )
return F_103 ( V_2 -> V_4 ) ;
V_324 = F_114 ( V_322 , V_328 , 0 ) ;
if ( ! V_324 ) {
F_17 ( V_59 , L_55 ) ;
return - V_329 ;
}
V_2 -> V_253 = V_324 -> V_330 ;
V_212 = F_116 ( V_59 , V_2 -> V_253 , NULL , F_83 ,
V_331 , L_56 , V_2 ) ;
if ( V_212 < 0 ) {
F_17 ( V_59 , L_57 ) ;
return V_212 ;
}
V_212 = F_101 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_49 = & V_2 -> V_49 ;
V_49 -> V_332 [ V_163 ] = & V_333 ;
V_49 -> V_332 [ V_252 ] = & V_334 ;
V_49 -> V_335 = F_87 ;
V_49 -> V_336 = F_93 ;
V_49 -> V_330 = F_94 ;
V_49 -> V_337 = F_96 ;
V_212 = F_85 ( V_49 ) ;
if ( V_212 < 0 ) {
F_17 ( V_59 , L_58 ) ;
goto V_338;
}
F_12 ( L_59 , V_2 -> V_23 , V_49 ) ;
F_117 ( & V_2 -> V_248 ) ;
F_118 ( V_322 , V_2 ) ;
F_119 ( V_59 ) ;
V_212 = F_120 ( V_49 ) ;
if ( V_212 < 0 ) {
F_17 ( V_59 , L_60 ) ;
goto V_339;
}
F_47 ( V_59 , L_61 ) ;
return 0 ;
V_339:
F_121 ( V_59 ) ;
V_338:
F_97 ( V_2 ) ;
return V_212 ;
}
static int F_122 ( struct V_321 * V_322 )
{
struct V_97 * V_59 = & V_322 -> V_59 ;
struct V_1 * V_2 = F_26 ( V_59 ) ;
struct V_48 * V_49 = & V_2 -> V_49 ;
F_123 ( V_49 ) ;
F_97 ( V_2 ) ;
F_124 ( V_59 ) ;
F_121 ( V_59 ) ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , bool V_42 )
{
F_12 ( L_2 , V_42 ) ;
if ( V_42 ) {
F_106 ( V_2 -> V_305 [ V_340 ] ) ;
F_106 ( V_2 -> V_305 [ V_307 ] ) ;
V_2 -> V_341 = false ;
} else {
F_126 ( V_2 -> V_305 [ V_340 ] ) ;
F_126 ( V_2 -> V_305 [ V_307 ] ) ;
V_2 -> V_341 = true ;
}
return 0 ;
}
static int F_127 ( struct V_97 * V_59 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
F_12 ( L_62 , V_2 -> V_23 ) ;
if ( F_128 ( V_59 ) )
return 0 ;
return F_125 ( V_2 , false ) ;
}
static int F_129 ( struct V_97 * V_59 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
F_12 ( L_62 , V_2 -> V_23 ) ;
if ( ! F_128 ( V_59 ) )
return F_125 ( V_2 , true ) ;
return 0 ;
}
static int F_130 ( struct V_97 * V_59 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
F_12 ( L_62 , V_2 -> V_23 ) ;
return F_125 ( V_2 , false ) ;
}
static int F_131 ( struct V_97 * V_59 )
{
struct V_1 * V_2 = F_26 ( V_59 ) ;
F_12 ( L_62 , V_2 -> V_23 ) ;
return F_125 ( V_2 , true ) ;
}
