static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
if ( F_3 ( V_3 ) ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_6 ;
F_4 ( V_3 , V_5 ) ;
}
V_3 = F_2 ( V_7 ) ;
V_3 |= V_8 ;
F_4 ( V_3 , V_7 ) ;
V_3 = F_2 ( V_9 ) ;
V_3 &= ~ ( V_10 | V_11 ) ;
F_4 ( V_3 , V_9 ) ;
V_3 = F_2 ( V_12 ) ;
V_3 |= ( V_13 ) ;
F_4 ( V_3 , V_12 ) ;
V_3 = F_2 ( V_12 ) ;
V_3 &= ~ V_13 ;
F_4 ( V_3 , V_12 ) ;
F_4 ( 0x0 , V_14 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 -> V_15 , V_16 ,
V_17 ,
V_2 -> V_18 << V_19 ) ;
}
static void F_7 ( struct V_1 * V_2 , enum V_20 V_21 )
{
T_1 V_3 ;
F_8 ( L_1 , V_21 ) ;
V_3 = F_2 ( V_12 ) ;
V_3 &= ~ ( V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 ) ;
switch ( V_21 ) {
case V_28 :
V_3 |= ( V_29 |
V_30 ) ;
break;
case V_31 :
V_3 |= ( V_32 |
V_30 ) ;
break;
case V_33 :
default:
V_3 |= ( V_34 |
V_29 |
V_35 |
V_36 ) ;
break;
}
F_4 ( V_3 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
T_1 V_3 ;
F_8 ( L_2 ,
V_38 -> V_39 , V_38 -> V_40 ) ;
F_8 ( L_3 ,
V_38 -> V_41 , V_38 -> V_42 ) ;
V_3 = F_2 ( V_12 ) ;
V_3 &= ~ ( V_43 | V_44 |
V_45 | V_46 ) ;
if ( V_38 -> V_39 )
V_3 |= V_43 ;
if ( V_38 -> V_40 )
V_3 |= V_44 ;
if ( V_38 -> V_41 )
V_3 |= V_45 ;
if ( V_38 -> V_42 )
V_3 |= V_46 ;
F_4 ( V_3 , V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 , bool V_47 )
{
T_1 V_3 ;
F_8 ( L_4 , V_47 ) ;
V_3 = F_2 ( V_12 ) ;
if ( V_47 )
V_3 |= V_48 ;
else
V_3 &= ~ V_48 ;
F_4 ( V_3 , V_12 ) ;
}
static void F_11 ( struct V_1 * V_2 , bool V_47 ,
bool V_49 , bool V_50 )
{
T_1 V_3 ;
F_8 ( L_5 ,
V_47 , V_49 , V_50 ) ;
V_3 = F_2 ( V_12 ) ;
if ( V_47 ) {
V_3 &= ~ ( V_51 | V_52 ) ;
V_3 |= V_53 ;
if ( V_49 )
V_3 |= V_51 ;
if ( V_50 )
V_3 |= V_52 ;
} else
V_3 &= ~ ( V_51 | V_53 ) ;
F_4 ( V_3 , V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_12 ) ;
V_3 |= V_54 ;
F_4 ( V_3 , V_12 ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = & V_2 -> V_56 ;
T_1 V_3 , V_57 , V_58 ;
V_57 = F_2 ( V_4 ) ;
V_58 = V_59 | V_60 |
V_61 ;
F_8 ( L_6 , V_58 ) ;
if ( V_57 & V_58 ) {
V_3 = F_2 ( V_62 ) ;
V_3 |= ( V_63 | V_64 |
V_65 ) ;
F_4 ( V_3 , V_62 ) ;
V_3 = F_2 ( V_62 ) ;
V_3 &= ~ ( V_63 | V_64 |
V_65 ) ;
F_4 ( V_3 , V_62 ) ;
F_14 ( V_56 -> V_66 , L_7 ,
V_2 -> V_18 , V_57 ) ;
return true ;
}
return false ;
}
static bool F_15 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
F_8 ( L_8 , V_3 ) ;
if ( ! ( V_3 & V_67 ) )
return false ;
V_3 &= ~ ( V_67 ) ;
F_4 ( V_3 , V_4 ) ;
return true ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_68 , V_69 ;
V_3 = F_2 ( V_70 ) ;
V_68 = F_17 ( V_3 ) ;
if ( V_68 == 0 )
V_68 = F_18 ( V_3 ) ;
F_8 ( L_9 ,
F_18 ( V_3 ) ,
F_17 ( V_3 ) ) ;
if ( V_68 == 0 ) {
F_19 ( L_10 ) ;
return - V_71 ;
}
V_69 = V_68 - 1 ;
F_8 ( L_11 , V_69 ) ;
return V_69 ;
}
static void F_20 ( struct V_1 * V_2 , bool V_47 )
{
T_1 V_3 ;
F_8 ( L_4 , V_47 ) ;
V_3 = F_2 ( V_72 ) ;
if ( V_47 )
V_3 |= V_73 ;
else
V_3 &= ~ V_73 ;
F_4 ( V_3 , V_72 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_74 )
{
struct V_55 * V_56 = & V_2 -> V_56 ;
T_1 V_3 ;
F_8 ( L_12 , V_74 ) ;
V_3 = F_2 ( V_75 ) ;
V_3 &= ~ V_76 ;
switch ( V_74 ) {
case V_77 :
V_3 |= V_78 ;
F_4 ( V_3 , V_75 ) ;
return 0 ;
case V_79 :
case V_80 :
V_3 |= V_81 ;
F_4 ( V_3 , V_75 ) ;
return 0 ;
default:
break;
}
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ ( V_82 |
V_83 |
V_84 ) ;
switch ( V_74 ) {
case V_85 :
V_3 |= V_84 ;
break;
case V_86 :
V_3 |= V_87 ;
break;
case V_88 :
V_3 |= V_89 ;
break;
case V_90 :
case V_91 :
V_3 |= V_92 ;
break;
case V_93 :
case V_94 :
V_3 |= ( V_95 |
V_83 ) ;
break;
case V_96 :
case V_97 :
case V_98 :
V_3 |= V_99 ;
break;
case V_100 :
case V_101 :
case V_102 :
V_3 |= ( V_103 |
V_83 ) ;
break;
default:
F_14 ( V_56 -> V_66 , L_13 , V_74 ) ;
return - V_104 ;
}
F_4 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_105 * V_66 , T_1 V_74 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
T_1 V_3 ;
F_8 ( L_12 , V_74 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_106 ;
switch ( V_74 ) {
case V_77 :
case V_79 :
case V_80 :
V_3 |= V_106 ;
break;
case V_91 :
V_3 |= V_107 ;
break;
case V_85 :
case V_86 :
case V_88 :
case V_90 :
V_3 |= V_108 ;
break;
case V_102 :
case V_94 :
case V_96 :
V_3 |= V_109 ;
break;
case V_97 :
case V_98 :
case V_100 :
case V_93 :
case V_101 :
V_3 |= V_107 ;
break;
default:
F_14 ( V_56 -> V_66 , L_14 , V_74 ) ;
return - V_104 ;
}
F_4 ( V_3 , V_5 ) ;
V_3 = F_2 ( V_110 ) ;
V_3 &= ~ V_111 ;
if ( V_74 == V_101 )
V_3 |= V_112 ;
else
V_3 |= V_113 ;
F_4 ( V_3 , V_110 ) ;
return F_21 ( V_2 , V_74 ) ;
}
static int F_24 ( struct V_105 * V_66 ,
enum V_114 V_115 ,
enum V_116 V_117 , bool * V_118 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
T_1 V_119 , V_120 ;
F_8 ( L_15 , V_115 , V_117 ) ;
V_119 = F_2 ( V_5 ) ;
V_119 &= ~ ( V_121 |
V_122 ) ;
V_120 = F_2 ( V_123 ) ;
V_120 &= ~ V_124 ;
switch ( V_115 ) {
case V_125 :
if ( V_117 & V_126 )
V_119 |= V_121 ;
if ( V_117 & V_127 )
V_119 |= V_122 ;
break;
case V_128 :
V_120 |= V_124 ;
if ( V_117 & V_126 )
V_119 |= V_121 ;
if ( V_117 & V_127 )
V_119 |= V_122 ;
break;
case V_129 :
V_119 |= ( V_121 |
V_122 ) ;
if ( V_117 & V_126 )
V_119 &= ~ V_121 ;
if ( V_117 & V_127 )
V_119 &= ~ V_122 ;
break;
case V_130 :
V_119 |= ( V_121 |
V_122 ) ;
V_120 |= V_124 ;
if ( V_117 & V_126 )
V_119 &= ~ V_121 ;
if ( V_117 & V_127 )
V_119 &= ~ V_122 ;
break;
default:
F_14 ( V_56 -> V_66 , L_16 , V_115 ) ;
return - V_104 ;
}
F_4 ( V_119 , V_5 ) ;
F_4 ( V_120 , V_123 ) ;
* V_118 = ( V_120 & V_124 ) ? 1 : 0 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_131 * V_132 , struct V_133 * V_134 )
{
T_1 V_3 , V_135 , V_136 , V_137 , V_138 ;
V_135 = V_132 -> V_139 ;
V_136 = V_134 -> V_140 - V_132 -> V_141 - V_132 -> V_139 ;
V_137 = V_132 -> V_142 ;
V_138 = V_134 -> V_143 - V_132 -> V_144 - V_132 -> V_142 ;
F_8 ( L_17 ,
V_132 -> V_139 , V_132 -> V_142 , V_132 -> V_141 , V_132 -> V_144 , V_134 -> V_140 , V_134 -> V_143 ) ;
F_8 ( L_18 , V_135 , V_136 , V_137 , V_138 ) ;
V_3 = F_2 ( V_62 ) ;
V_3 &= ~ ( V_145 |
V_146 ) ;
V_3 |= ( F_26 ( V_135 ) |
F_27 ( V_137 ) ) ;
V_3 |= V_147 ;
F_4 ( V_3 , V_62 ) ;
V_3 = ( F_28 ( V_136 ) |
F_29 ( V_138 ) ) ;
F_4 ( V_3 , V_148 ) ;
return 0 ;
}
static int F_30 ( struct V_105 * V_66 , int V_118 ,
struct V_131 * V_132 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_131 V_149 = * V_132 ;
struct V_133 V_150 = * V_134 ;
T_1 V_3 ;
F_8 ( L_19 ,
V_118 , V_134 -> V_140 , V_134 -> V_143 ) ;
V_3 = ( F_31 ( V_150 . V_140 ) |
F_32 ( V_150 . V_143 ) ) ;
F_4 ( V_3 , V_151 ) ;
F_8 ( L_20 , V_132 -> V_139 , V_132 -> V_142 , V_132 -> V_141 , V_132 -> V_144 ) ;
if ( V_118 ) {
V_149 . V_141 = V_132 -> V_144 ;
V_149 . V_144 = V_132 -> V_141 ;
V_150 . V_140 = V_134 -> V_143 ;
V_150 . V_143 = V_134 -> V_140 ;
}
V_3 = F_2 ( V_152 ) ;
V_3 &= ~ ( V_153 |
V_154 ) ;
V_3 |= ( F_33 ( V_149 . V_141 ) |
F_34 ( V_149 . V_144 ) ) ;
F_4 ( V_3 , V_152 ) ;
V_3 = ( V_8 |
F_35 ( V_150 . V_140 ) |
F_36 ( V_150 . V_143 ) ) ;
F_4 ( V_3 , V_7 ) ;
V_3 = ( F_37 ( V_149 . V_139 ) |
F_38 ( V_149 . V_142 ) ) ;
F_4 ( V_3 , V_155 ) ;
V_3 = ( F_39 ( V_149 . V_139 ) |
F_40 ( V_149 . V_142 ) ) ;
F_4 ( V_3 , V_156 ) ;
V_3 = ( F_41 ( V_149 . V_139 ) |
F_42 ( V_149 . V_142 ) ) ;
F_4 ( V_3 , V_157 ) ;
return F_25 ( V_2 , & V_149 , & V_150 ) ;
}
static int F_43 ( struct V_105 * V_66 ,
struct V_158 * V_159 , T_1 V_69 ,
enum V_160 V_161 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
struct V_162 * V_163 = V_56 -> V_163 ;
struct V_164 * V_165 ;
struct V_166 * V_167 ;
if ( ! V_163 ) {
F_19 ( L_21 ) ;
return - V_104 ;
}
V_165 = & V_163 -> V_165 ;
F_8 ( L_22 ,
V_165 -> V_168 , V_69 , V_161 ) ;
if ( V_69 > V_169 ) {
F_44 ( V_56 -> V_66 , L_23 , V_69 ) ;
return - V_170 ;
}
switch ( V_161 ) {
case V_171 :
V_167 = & V_165 -> V_167 [ V_172 ] ;
F_4 ( V_159 -> V_173 [ V_174 ] ,
F_45 ( V_69 ) ) ;
if ( V_167 -> V_74 == V_98 ) {
F_4 ( V_159 -> V_173 [ V_175 ] ,
F_46 ( V_69 ) ) ;
F_4 ( V_159 -> V_173 [ V_176 ] ,
F_47 ( V_69 ) ) ;
} else {
F_4 ( V_159 -> V_173 [ V_176 ] ,
F_46 ( V_69 ) ) ;
F_4 ( V_159 -> V_173 [ V_175 ] ,
F_47 ( V_69 ) ) ;
}
break;
case V_177 :
F_4 ( 0x0 , F_45 ( V_69 ) ) ;
F_4 ( 0x0 , F_46 ( V_69 ) ) ;
F_4 ( 0x0 , F_47 ( V_69 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , T_1 V_74 )
{
struct V_55 * V_56 = & V_2 -> V_56 ;
T_1 V_3 ;
F_8 ( L_12 , V_74 ) ;
V_3 = F_2 ( V_75 ) ;
V_3 &= ~ V_178 ;
switch ( V_74 ) {
case V_77 :
V_3 |= V_179 ;
F_4 ( V_3 , V_75 ) ;
return 0 ;
case V_79 :
V_3 |= V_180 ;
F_4 ( V_3 , V_75 ) ;
return 0 ;
case V_80 :
V_3 |= ( V_180 |
V_181 ) ;
F_4 ( V_3 , V_75 ) ;
break;
default:
break;
}
V_3 = F_2 ( V_72 ) ;
V_3 &= ~ ( V_182 |
V_183 |
V_184 ) ;
switch ( V_74 ) {
case V_80 :
V_3 |= V_185 ;
break;
case V_85 :
V_3 |= V_186 ;
break;
case V_86 :
V_3 |= V_187 ;
break;
case V_88 :
V_3 |= V_188 ;
break;
case V_90 :
V_3 |= V_189 ;
break;
case V_93 :
case V_94 :
V_3 |= V_190 ;
V_3 |= V_191 ;
break;
case V_96 :
case V_97 :
case V_98 :
V_3 |= V_192 ;
break;
case V_100 :
case V_101 :
case V_102 :
V_3 |= V_193 ;
V_3 |= V_191 ;
break;
default:
F_14 ( V_56 -> V_66 , L_24 , V_74 ) ;
return - V_104 ;
}
F_4 ( V_3 , V_72 ) ;
return 0 ;
}
static int F_49 ( struct V_105 * V_66 , T_1 V_74 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
T_1 V_3 ;
F_8 ( L_12 , V_74 ) ;
V_3 = F_2 ( V_194 ) ;
if ( V_74 == V_195 ) {
V_3 |= V_196 ;
F_4 ( V_3 , V_194 ) ;
} else {
V_3 &= ~ V_196 ;
F_4 ( V_3 , V_194 ) ;
V_3 = F_2 ( V_123 ) ;
V_3 &= ~ V_197 ;
switch ( V_74 ) {
case V_77 :
case V_79 :
case V_80 :
V_3 |= V_198 ;
break;
case V_85 :
case V_86 :
case V_88 :
case V_90 :
V_3 |= V_199 ;
break;
case V_102 :
case V_94 :
case V_96 :
V_3 |= V_200 ;
break;
case V_97 :
case V_98 :
case V_100 :
case V_101 :
case V_93 :
V_3 |= V_201 ;
break;
default:
F_14 ( V_56 -> V_66 , L_25 ,
V_74 ) ;
return - V_104 ;
}
F_4 ( V_3 , V_123 ) ;
}
V_3 = F_2 ( V_110 ) ;
V_3 &= ~ V_202 ;
if ( V_74 == V_101 )
V_3 |= V_203 ;
else
V_3 |= V_204 ;
F_4 ( V_3 , V_110 ) ;
return F_48 ( V_2 , V_74 ) ;
}
static int F_50 ( struct V_105 * V_66 ,
enum V_114 V_115 ,
enum V_116 V_117 , bool * V_118 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
T_1 V_3 ;
F_8 ( L_15 , V_115 , V_117 ) ;
V_3 = F_2 ( V_123 ) ;
V_3 &= ~ V_205 ;
V_3 &= ~ V_206 ;
switch ( V_115 ) {
case V_125 :
if ( V_117 & V_126 )
V_3 |= V_207 ;
if ( V_117 & V_127 )
V_3 |= V_208 ;
break;
case V_128 :
V_3 |= V_206 ;
if ( V_117 & V_126 )
V_3 |= V_207 ;
if ( V_117 & V_127 )
V_3 |= V_208 ;
break;
case V_129 :
V_3 |= ( V_207 |
V_208 ) ;
if ( V_117 & V_126 )
V_3 &= ~ V_207 ;
if ( V_117 & V_127 )
V_3 &= ~ V_208 ;
break;
case V_130 :
V_3 |= ( V_206 |
V_207 |
V_208 ) ;
if ( V_117 & V_126 )
V_3 &= ~ V_207 ;
if ( V_117 & V_127 )
V_3 &= ~ V_208 ;
break;
default:
F_14 ( V_56 -> V_66 , L_16 , V_115 ) ;
return - V_104 ;
}
F_4 ( V_3 , V_123 ) ;
* V_118 = ( V_3 & V_206 ) ? 1 : 0 ;
return 0 ;
}
static int F_51 ( T_1 V_209 , T_1 V_210 , T_1 * V_211 , T_1 * V_212 )
{
F_8 ( L_26 , V_209 , V_210 ) ;
if ( V_209 >= V_210 * 64 ) {
F_19 ( L_27 ) ;
return - V_104 ;
} else if ( V_209 >= V_210 * 32 ) {
* V_211 = 32 ;
* V_212 = 5 ;
} else if ( V_209 >= V_210 * 16 ) {
* V_211 = 16 ;
* V_212 = 4 ;
} else if ( V_209 >= V_210 * 8 ) {
* V_211 = 8 ;
* V_212 = 3 ;
} else if ( V_209 >= V_210 * 4 ) {
* V_211 = 4 ;
* V_212 = 2 ;
} else if ( V_209 >= V_210 * 2 ) {
* V_211 = 2 ;
* V_212 = 1 ;
} else {
* V_211 = 1 ;
* V_212 = 0 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_213 * V_214 ,
struct V_131 * V_209 , struct V_131 * V_210 )
{
struct V_55 * V_56 = & V_2 -> V_56 ;
T_1 V_3 , V_215 , V_216 ;
T_1 V_217 , V_218 ;
T_1 V_219 , V_220 , V_221 , V_222 ;
int V_223 = 0 ;
T_1 V_224 , V_225 , V_226 , V_227 ;
V_215 = F_2 ( V_123 ) ;
if ( V_215 & V_124 ) {
V_224 = V_209 -> V_144 ;
V_225 = V_209 -> V_141 ;
} else {
V_224 = V_209 -> V_141 ;
V_225 = V_209 -> V_144 ;
}
if ( V_215 & V_206 ) {
V_226 = V_210 -> V_144 ;
V_227 = V_210 -> V_141 ;
} else {
V_226 = V_210 -> V_141 ;
V_227 = V_210 -> V_144 ;
}
V_223 = F_51 ( V_224 , V_226 , & V_219 , & V_220 ) ;
if ( V_223 ) {
F_14 ( V_56 -> V_66 , L_28 ) ;
return V_223 ;
}
V_223 = F_51 ( V_225 , V_227 , & V_221 , & V_222 ) ;
if ( V_223 ) {
F_14 ( V_56 -> V_66 , L_29 ) ;
return V_223 ;
}
V_217 = V_224 / V_219 ;
V_218 = V_225 / V_221 ;
F_8 ( L_30 ,
V_217 , V_218 ) ;
F_8 ( L_31 ,
V_219 , V_220 , V_221 , V_222 ) ;
V_214 -> V_228 = ( V_224 << 14 ) / ( V_226 << V_220 ) ;
V_214 -> V_229 = ( V_225 << 14 ) / ( V_227 << V_222 ) ;
V_214 -> V_230 = ( V_226 >= V_224 ) ? true : false ;
V_214 -> V_231 = ( V_227 >= V_225 ) ? true : false ;
F_8 ( L_32 ,
V_214 -> V_228 , V_214 -> V_229 , V_214 -> V_230 , V_214 -> V_231 ) ;
V_216 = V_232 - ( V_220 + V_222 ) ;
F_8 ( L_33 , V_216 ) ;
V_3 = ( F_53 ( V_216 ) |
F_54 ( V_219 ) |
F_55 ( V_221 ) ) ;
F_4 ( V_3 , V_233 ) ;
V_3 = ( F_56 ( V_217 ) |
F_57 ( V_218 ) ) ;
F_4 ( V_3 , V_234 ) ;
return V_223 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_213 * V_214 )
{
T_1 V_3 , V_215 ;
F_8 ( L_34 ,
V_214 -> V_235 , V_214 -> V_236 , V_214 -> V_230 , V_214 -> V_231 ) ;
F_8 ( L_35 ,
V_214 -> V_228 , V_214 -> V_229 ) ;
V_3 = F_2 ( V_75 ) ;
V_3 &= ~ ( V_237 |
V_238 | V_239 |
V_240 |
V_241 |
V_242 |
V_243 ) ;
if ( V_214 -> V_235 )
V_3 |= ( V_242 |
V_243 ) ;
if ( V_214 -> V_236 )
V_3 |= V_237 ;
if ( V_214 -> V_230 )
V_3 |= V_238 ;
if ( V_214 -> V_231 )
V_3 |= V_239 ;
V_3 |= ( F_59 ( ( V_214 -> V_228 >> 6 ) ) |
F_60 ( ( V_214 -> V_229 >> 6 ) ) ) ;
F_4 ( V_3 , V_75 ) ;
V_215 = F_2 ( V_194 ) ;
V_215 &= ~ V_244 ;
V_215 &= ~ V_245 ;
V_215 |= ( F_61 ( V_214 -> V_228 ) |
F_62 ( V_214 -> V_229 ) ) ;
F_4 ( V_215 , V_194 ) ;
}
static int F_63 ( struct V_105 * V_66 , int V_118 ,
struct V_131 * V_132 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_131 V_149 = * V_132 ;
struct V_133 V_150 = * V_134 ;
T_1 V_3 ;
F_8 ( L_19 ,
V_118 , V_134 -> V_140 , V_134 -> V_143 ) ;
V_3 = ( F_64 ( V_150 . V_140 ) |
F_65 ( V_150 . V_143 ) ) ;
F_4 ( V_3 , V_246 ) ;
F_8 ( L_20 , V_132 -> V_139 , V_132 -> V_142 , V_132 -> V_141 , V_132 -> V_144 ) ;
V_3 = F_2 ( V_12 ) ;
V_3 &= ~ V_247 ;
if ( V_134 -> V_140 >= V_248 )
V_3 |= V_249 ;
else
V_3 |= V_250 ;
F_4 ( V_3 , V_12 ) ;
if ( V_118 ) {
V_149 . V_141 = V_132 -> V_144 ;
V_149 . V_144 = V_132 -> V_141 ;
V_150 . V_140 = V_134 -> V_143 ;
V_150 . V_143 = V_134 -> V_140 ;
}
V_3 = F_2 ( V_123 ) ;
V_3 &= ~ ( V_251 |
V_252 ) ;
V_3 |= ( F_66 ( V_149 . V_141 ) |
F_67 ( V_149 . V_144 ) ) ;
F_4 ( V_3 , V_123 ) ;
V_3 = F_68 ( V_149 . V_141 * V_149 . V_144 ) ;
F_4 ( V_3 , V_253 ) ;
V_3 = ( F_69 ( V_149 . V_139 ) |
F_70 ( V_149 . V_142 ) ) ;
F_4 ( V_3 , V_254 ) ;
V_3 = ( F_71 ( V_149 . V_139 ) |
F_72 ( V_149 . V_142 ) ) ;
F_4 ( V_3 , V_255 ) ;
V_3 = ( F_73 ( V_149 . V_139 ) |
F_74 ( V_149 . V_142 ) ) ;
F_4 ( V_3 , V_256 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
T_1 V_3 , V_257 , V_258 = 0 ;
T_1 V_259 = 0x00000001 ;
V_3 = F_2 ( V_14 ) ;
for ( V_257 = 0 ; V_257 < V_260 ; V_257 ++ )
if ( V_3 & ( V_259 << V_257 ) )
V_258 ++ ;
F_8 ( L_36 , V_258 ) ;
return V_258 ;
}
static int F_76 ( struct V_1 * V_2 , T_1 V_69 ,
enum V_160 V_161 )
{
struct V_55 * V_56 = & V_2 -> V_56 ;
bool V_47 ;
T_1 V_3 ;
T_1 V_259 = 0x00000001 << V_69 ;
int V_223 = 0 ;
F_8 ( L_37 , V_69 , V_161 ) ;
F_77 ( & V_2 -> V_261 ) ;
V_3 = F_2 ( V_14 ) ;
switch ( V_161 ) {
case V_171 :
V_47 = true ;
break;
case V_177 :
V_47 = false ;
break;
default:
F_14 ( V_56 -> V_66 , L_38 ) ;
V_223 = - V_104 ;
goto V_262;
}
V_3 &= ~ V_259 ;
V_3 |= ( V_47 << V_69 ) ;
F_4 ( V_3 , V_14 ) ;
if ( V_161 == V_171 &&
F_75 ( V_2 ) >= V_263 )
F_11 ( V_2 , true , false , true ) ;
if ( V_161 == V_177 &&
F_75 ( V_2 ) <= V_264 )
F_11 ( V_2 , false , false , true ) ;
V_262:
F_78 ( & V_2 -> V_261 ) ;
return V_223 ;
}
static int F_79 ( struct V_105 * V_66 ,
struct V_158 * V_159 , T_1 V_69 ,
enum V_160 V_161 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
struct V_162 * V_163 = V_56 -> V_163 ;
struct V_164 * V_165 ;
struct V_166 * V_167 ;
if ( ! V_163 ) {
F_19 ( L_21 ) ;
return - V_104 ;
}
V_165 = & V_163 -> V_165 ;
F_8 ( L_22 ,
V_165 -> V_168 , V_69 , V_161 ) ;
if ( V_69 > V_265 ) {
F_44 ( V_56 -> V_66 , L_23 , V_69 ) ;
return - V_170 ;
}
switch ( V_161 ) {
case V_171 :
V_167 = & V_165 -> V_167 [ V_266 ] ;
F_4 ( V_159 -> V_173 [ V_174 ] ,
F_80 ( V_69 ) ) ;
if ( V_167 -> V_74 == V_98 ) {
F_4 ( V_159 -> V_173 [ V_175 ] ,
F_81 ( V_69 ) ) ;
F_4 ( V_159 -> V_173 [ V_176 ] ,
F_82 ( V_69 ) ) ;
} else {
F_4 ( V_159 -> V_173 [ V_176 ] ,
F_81 ( V_69 ) ) ;
F_4 ( V_159 -> V_173 [ V_175 ] ,
F_82 ( V_69 ) ) ;
}
break;
case V_177 :
F_4 ( 0x0 , F_80 ( V_69 ) ) ;
F_4 ( 0x0 , F_81 ( V_69 ) ) ;
F_4 ( 0x0 , F_82 ( V_69 ) ) ;
break;
default:
break;
}
return F_76 ( V_2 , V_69 , V_161 ) ;
}
static int F_83 ( struct V_1 * V_2 , bool V_47 )
{
F_8 ( L_4 , V_47 ) ;
if ( V_47 ) {
F_84 ( V_2 -> V_267 [ V_268 ] ) ;
F_84 ( V_2 -> V_267 [ V_269 ] ) ;
V_2 -> V_270 = false ;
} else {
F_85 ( V_2 -> V_267 [ V_268 ] ) ;
F_85 ( V_2 -> V_267 [ V_269 ] ) ;
V_2 -> V_270 = true ;
}
return 0 ;
}
static T_2 F_86 ( int V_271 , void * V_272 )
{
struct V_1 * V_2 = V_272 ;
struct V_55 * V_56 = & V_2 -> V_56 ;
struct V_162 * V_163 = V_56 -> V_163 ;
struct V_273 * V_274 =
V_163 -> V_274 ;
int V_69 ;
F_8 ( L_39 , V_2 -> V_18 ) ;
F_12 ( V_2 ) ;
if ( F_13 ( V_2 ) )
return V_275 ;
if ( ! F_15 ( V_2 ) )
return V_275 ;
V_69 = F_16 ( V_2 ) ;
if ( V_69 < 0 )
return V_276 ;
F_8 ( L_11 , V_69 ) ;
if ( F_76 ( V_2 , V_69 , V_177 ) < 0 ) {
F_19 ( L_40 ) ;
return V_276 ;
}
V_274 -> V_56 = V_56 ;
V_274 -> V_69 [ V_266 ] = V_69 ;
F_87 ( V_56 -> V_277 , (struct V_278 * ) V_274 ) ;
return V_276 ;
}
static int F_88 ( struct V_55 * V_56 )
{
struct V_279 * V_280 ;
V_280 = F_89 ( V_56 -> V_66 , sizeof( * V_280 ) , V_281 ) ;
if ( ! V_280 ) {
F_19 ( L_41 ) ;
return - V_170 ;
}
V_280 -> V_282 = 1 ;
V_280 -> V_283 = 1 ;
V_280 -> V_284 = V_285 ;
V_280 -> V_286 = V_287 ;
V_280 -> V_117 = ( 1 << V_288 ) |
( 1 << V_126 ) |
( 1 << V_127 ) ;
V_280 -> V_115 = ( 1 << V_125 ) |
( 1 << V_128 ) |
( 1 << V_129 ) |
( 1 << V_130 ) ;
V_280 -> V_289 = 1 ;
V_280 -> V_290 = 1 ;
V_280 -> V_291 . V_140 = V_292 ;
V_280 -> V_291 . V_143 = V_292 ;
V_280 -> V_293 . V_140 = V_294 ;
V_280 -> V_293 . V_143 = V_294 ;
V_280 -> V_295 = 1 ;
V_280 -> V_296 . V_140 = V_297 ;
V_280 -> V_296 . V_143 = V_297 ;
V_280 -> V_298 . V_140 = V_299 ;
V_280 -> V_298 . V_143 = V_299 ;
V_56 -> V_280 = V_280 ;
return 0 ;
}
static inline bool F_90 ( enum V_116 V_117 )
{
switch ( V_117 ) {
case V_288 :
case V_126 :
case V_127 :
case V_300 :
return true ;
default:
F_8 ( L_42 ) ;
return false ;
}
}
static int F_91 ( struct V_105 * V_66 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
struct V_279 * V_301 = V_56 -> V_280 ;
struct V_166 * V_167 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
bool V_118 ;
int V_257 ;
F_92 (i) {
if ( ( V_257 == V_172 ) &&
( V_165 -> V_302 == V_303 ) )
continue;
V_167 = & V_165 -> V_167 [ V_257 ] ;
V_132 = & V_167 -> V_132 ;
V_134 = & V_167 -> V_134 ;
if ( ! F_90 ( V_167 -> V_117 ) ) {
F_19 ( L_43 ) ;
goto V_304;
}
switch ( V_167 -> V_115 ) {
case V_128 :
case V_130 :
V_118 = true ;
break;
case V_125 :
case V_129 :
V_118 = false ;
break;
default:
F_19 ( L_44 ) ;
goto V_304;
}
if ( ( V_132 -> V_139 + V_132 -> V_141 > V_134 -> V_140 ) ||
( V_132 -> V_142 + V_132 -> V_144 > V_134 -> V_143 ) ) {
F_19 ( L_45 ) ;
goto V_304;
}
if ( ( V_257 == V_172 ) && ( V_301 -> V_290 ) ) {
if ( V_118 ) {
if ( ( V_132 -> V_144 < V_301 -> V_293 . V_140 ) ||
( V_134 -> V_143 > V_301 -> V_291 . V_140 ) ||
( V_132 -> V_141 < V_301 -> V_293 . V_143 ) ||
( V_134 -> V_140 > V_301 -> V_291 . V_143 ) ) {
F_19 ( L_46 ) ;
goto V_304;
}
} else {
if ( ( V_132 -> V_141 < V_301 -> V_293 . V_140 ) ||
( V_134 -> V_140 > V_301 -> V_291 . V_140 ) ||
( V_132 -> V_144 < V_301 -> V_293 . V_143 ) ||
( V_134 -> V_143 > V_301 -> V_291 . V_143 ) ) {
F_19 ( L_46 ) ;
goto V_304;
}
}
}
if ( ( V_257 == V_266 ) && ( V_301 -> V_295 ) ) {
if ( V_118 ) {
if ( ( V_132 -> V_144 < V_301 -> V_298 . V_140 ) ||
( V_134 -> V_143 > V_301 -> V_296 . V_140 ) ||
( V_132 -> V_141 < V_301 -> V_298 . V_143 ) ||
( V_134 -> V_140 > V_301 -> V_296 . V_143 ) ) {
F_19 ( L_47 ) ;
goto V_304;
}
} else {
if ( ( V_132 -> V_141 < V_301 -> V_298 . V_140 ) ||
( V_134 -> V_140 > V_301 -> V_296 . V_140 ) ||
( V_132 -> V_144 < V_301 -> V_298 . V_143 ) ||
( V_134 -> V_143 > V_301 -> V_296 . V_143 ) ) {
F_19 ( L_47 ) ;
goto V_304;
}
}
}
}
return 0 ;
V_304:
F_92 (i) {
if ( ( V_257 == V_172 ) &&
( V_165 -> V_302 == V_303 ) )
continue;
V_167 = & V_165 -> V_167 [ V_257 ] ;
V_132 = & V_167 -> V_132 ;
V_134 = & V_167 -> V_134 ;
F_19 ( L_48 ,
V_257 ? L_49 : L_50 , V_167 -> V_117 , V_167 -> V_115 ,
V_132 -> V_139 , V_132 -> V_142 , V_132 -> V_141 , V_132 -> V_144 ,
V_134 -> V_140 , V_134 -> V_143 ) ;
}
return - V_104 ;
}
static void F_93 ( struct V_1 * V_2 )
{
int V_257 ;
for ( V_257 = 0 ; V_257 < V_169 ; V_257 ++ ) {
F_4 ( 0 , F_45 ( V_257 ) ) ;
F_4 ( 0 , F_46 ( V_257 ) ) ;
F_4 ( 0 , F_47 ( V_257 ) ) ;
}
for ( V_257 = 0 ; V_257 < V_265 ; V_257 ++ ) {
F_4 ( 0 , F_80 ( V_257 ) ) ;
F_4 ( 0 , F_81 ( V_257 ) ) ;
F_4 ( 0 , F_82 ( V_257 ) ) ;
}
}
static int F_94 ( struct V_105 * V_66 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
F_1 ( V_2 ) ;
memset ( & V_2 -> V_214 , 0x0 , sizeof( V_2 -> V_214 ) ) ;
F_93 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_105 * V_66 , enum V_305 V_302 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
struct V_162 * V_163 = V_56 -> V_163 ;
struct V_164 * V_165 ;
struct V_166 * V_167 ;
struct V_131 V_149 [ V_306 ] ;
struct V_307 V_308 ;
int V_223 , V_257 ;
T_1 V_309 , V_119 ;
F_8 ( L_51 , V_302 ) ;
if ( ! V_163 ) {
F_19 ( L_21 ) ;
return - V_104 ;
}
V_165 = & V_163 -> V_165 ;
F_11 ( V_2 , true , false , true ) ;
F_92 (i) {
V_167 = & V_165 -> V_167 [ V_257 ] ;
V_149 [ V_257 ] = V_167 -> V_132 ;
}
V_223 = F_52 ( V_2 , & V_2 -> V_214 ,
& V_149 [ V_172 ] ,
& V_149 [ V_266 ] ) ;
if ( V_223 ) {
F_14 ( V_66 , L_52 ) ;
return V_223 ;
}
F_10 ( V_2 , false ) ;
F_58 ( V_2 , & V_2 -> V_214 ) ;
F_9 ( V_2 , & V_2 -> V_38 ) ;
switch ( V_302 ) {
case V_310 :
F_7 ( V_2 , V_33 ) ;
F_20 ( V_2 , false ) ;
V_309 = F_2 ( V_5 ) ;
V_309 &= ~ V_311 ;
V_309 |= V_312 ;
F_4 ( V_309 , V_5 ) ;
break;
case V_303 :
F_7 ( V_2 , V_28 ) ;
F_20 ( V_2 , true ) ;
V_223 = F_5 ( V_2 ) ;
if ( V_223 < 0 ) {
F_14 ( V_66 , L_53 ) ;
return V_223 ;
}
V_308 . V_47 = 1 ;
V_308 . V_313 = V_165 -> V_314 ;
F_96 ( V_315 , ( void * ) & V_308 ) ;
break;
case V_316 :
default:
V_223 = - V_104 ;
F_14 ( V_66 , L_54 ) ;
return V_223 ;
}
F_4 ( 0x0 , V_4 ) ;
V_309 = F_2 ( V_9 ) ;
V_309 &= ~ V_10 ;
V_309 |= V_10 ;
V_119 = F_2 ( V_75 ) ;
V_119 &= ~ V_317 ;
V_119 |= ( V_318 |
V_319 ) ;
F_4 ( V_119 , V_75 ) ;
V_309 |= V_11 ;
F_4 ( V_309 , V_9 ) ;
V_309 = F_2 ( V_12 ) ;
V_309 &= ~ V_320 ;
F_4 ( V_309 , V_12 ) ;
V_309 = F_2 ( V_72 ) ;
V_309 &= ~ V_321 ;
F_4 ( V_309 , V_72 ) ;
if ( V_302 == V_310 ) {
V_309 = F_2 ( V_5 ) ;
V_309 |= V_6 ;
F_4 ( V_309 , V_5 ) ;
V_309 = F_2 ( V_5 ) ;
V_309 |= V_6 ;
F_4 ( V_309 , V_5 ) ;
}
return 0 ;
}
static void F_97 ( struct V_105 * V_66 , enum V_305 V_302 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_307 V_308 = { 0 , 0 } ;
T_1 V_3 ;
F_8 ( L_51 , V_302 ) ;
switch ( V_302 ) {
case V_310 :
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_311 ;
V_3 &= ~ V_6 ;
F_4 ( V_3 , V_5 ) ;
break;
case V_303 :
F_96 ( V_315 , ( void * ) & V_308 ) ;
break;
case V_316 :
default:
F_14 ( V_66 , L_54 ) ;
break;
}
F_11 ( V_2 , false , false , true ) ;
F_4 ( 0x0 , V_14 ) ;
V_3 = F_2 ( V_75 ) ;
V_3 &= ~ V_319 ;
F_4 ( V_3 , V_75 ) ;
V_3 = F_2 ( V_9 ) ;
V_3 &= ~ ( V_10 | V_11 ) ;
F_4 ( V_3 , V_9 ) ;
V_3 = F_2 ( V_12 ) ;
V_3 |= V_320 ;
F_4 ( V_3 , V_12 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
int V_257 ;
for ( V_257 = 0 ; V_257 < V_322 ; V_257 ++ ) {
if ( F_99 ( V_2 -> V_267 [ V_257 ] ) )
continue;
F_100 ( V_2 -> V_267 [ V_257 ] ) ;
V_2 -> V_267 [ V_257 ] = F_101 ( - V_104 ) ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_105 * V_323 = V_2 -> V_56 . V_66 ;
struct V_105 * V_66 ;
int V_223 , V_257 ;
for ( V_257 = 0 ; V_257 < V_322 ; V_257 ++ )
V_2 -> V_267 [ V_257 ] = F_101 ( - V_104 ) ;
for ( V_257 = 0 ; V_257 < V_322 ; V_257 ++ ) {
if ( V_257 == V_269 || V_257 == V_324 )
V_66 = V_323 -> V_325 ;
else
V_66 = V_323 ;
V_2 -> V_267 [ V_257 ] = F_103 ( V_66 , V_326 [ V_257 ] ) ;
if ( F_99 ( V_2 -> V_267 [ V_257 ] ) ) {
if ( V_257 >= V_327 )
break;
V_223 = F_104 ( V_2 -> V_267 [ V_257 ] ) ;
F_14 ( V_323 , L_55 ,
V_326 [ V_257 ] ) ;
goto V_328;
}
}
if ( ! F_99 ( V_2 -> V_267 [ V_329 ] ) ) {
V_223 = F_105 ( V_2 -> V_267 [ V_327 ] ,
V_2 -> V_267 [ V_329 ] ) ;
if ( V_223 < 0 ) {
F_14 ( V_323 , L_56 ) ;
goto V_328;
}
}
V_223 = F_106 ( V_2 -> V_267 [ V_330 ] , V_2 -> V_331 ) ;
if ( V_223 < 0 )
goto V_328;
V_223 = F_84 ( V_2 -> V_267 [ V_330 ] ) ;
if ( ! V_223 )
return V_223 ;
V_328:
F_98 ( V_2 ) ;
return V_223 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_332 * V_333 = V_2 -> V_56 . V_66 -> V_334 ;
if ( ! F_108 ( V_333 , L_57 ) )
return - V_335 ;
if ( F_109 ( V_333 , L_58 ,
& V_2 -> V_331 ) )
V_2 -> V_331 = V_336 ;
V_2 -> V_18 = F_110 ( V_333 , L_59 ) ;
if ( V_2 -> V_18 < 0 ) {
F_14 ( V_2 -> V_56 . V_66 , L_60 ) ;
return - V_104 ;
}
return 0 ;
}
static int F_111 ( struct V_337 * V_338 )
{
struct V_105 * V_66 = & V_338 -> V_66 ;
struct V_1 * V_2 ;
struct V_339 * V_340 ;
struct V_55 * V_56 ;
int V_223 ;
if ( ! V_66 -> V_334 ) {
F_14 ( V_66 , L_61 ) ;
return - V_335 ;
}
V_2 = F_89 ( V_66 , sizeof( * V_2 ) , V_281 ) ;
if ( ! V_2 )
return - V_170 ;
V_2 -> V_56 . V_66 = V_66 ;
V_223 = F_107 ( V_2 ) ;
if ( V_223 < 0 )
return V_223 ;
V_2 -> V_15 = F_112 ( V_66 -> V_334 ,
L_62 ) ;
if ( F_99 ( V_2 -> V_15 ) ) {
F_14 ( V_66 , L_63 ) ;
return F_104 ( V_2 -> V_15 ) ;
}
V_2 -> V_341 = F_113 ( V_338 , V_342 , 0 ) ;
V_2 -> V_343 = F_114 ( V_66 , V_2 -> V_341 ) ;
if ( F_99 ( V_2 -> V_343 ) )
return F_104 ( V_2 -> V_343 ) ;
V_340 = F_113 ( V_338 , V_344 , 0 ) ;
if ( ! V_340 ) {
F_14 ( V_66 , L_64 ) ;
return - V_345 ;
}
V_2 -> V_271 = V_340 -> V_346 ;
V_223 = F_115 ( V_66 , V_2 -> V_271 , NULL , F_86 ,
V_347 , L_65 , V_2 ) ;
if ( V_223 < 0 ) {
F_14 ( V_66 , L_66 ) ;
return V_223 ;
}
V_223 = F_102 ( V_2 ) ;
if ( V_223 < 0 )
return V_223 ;
V_56 = & V_2 -> V_56 ;
V_56 -> V_348 [ V_172 ] = & V_349 ;
V_56 -> V_348 [ V_266 ] = & V_350 ;
V_56 -> V_351 = F_91 ;
V_56 -> V_352 = F_94 ;
V_56 -> V_346 = F_95 ;
V_56 -> V_353 = F_97 ;
V_223 = F_88 ( V_56 ) ;
if ( V_223 < 0 ) {
F_14 ( V_66 , L_67 ) ;
goto V_354;
}
F_8 ( L_68 , V_2 -> V_18 , ( int ) V_56 ) ;
F_116 ( & V_2 -> V_261 ) ;
F_117 ( V_338 , V_2 ) ;
F_118 ( V_66 ) ;
F_119 ( V_66 ) ;
V_223 = F_120 ( V_56 ) ;
if ( V_223 < 0 ) {
F_14 ( V_66 , L_69 ) ;
goto V_355;
}
F_44 ( V_66 , L_70 ) ;
return 0 ;
V_355:
F_121 ( V_66 ) ;
V_354:
F_98 ( V_2 ) ;
return V_223 ;
}
static int F_122 ( struct V_337 * V_338 )
{
struct V_105 * V_66 = & V_338 -> V_66 ;
struct V_1 * V_2 = F_23 ( V_66 ) ;
struct V_55 * V_56 = & V_2 -> V_56 ;
F_123 ( V_56 ) ;
F_124 ( & V_2 -> V_261 ) ;
F_98 ( V_2 ) ;
F_125 ( V_66 ) ;
F_121 ( V_66 ) ;
return 0 ;
}
static int F_126 ( struct V_105 * V_66 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
F_8 ( L_71 , V_2 -> V_18 ) ;
if ( F_127 ( V_66 ) )
return 0 ;
return F_83 ( V_2 , false ) ;
}
static int F_128 ( struct V_105 * V_66 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
F_8 ( L_71 , V_2 -> V_18 ) ;
if ( ! F_127 ( V_66 ) )
return F_83 ( V_2 , true ) ;
return 0 ;
}
static int F_129 ( struct V_105 * V_66 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
F_8 ( L_71 , V_2 -> V_18 ) ;
return F_83 ( V_2 , false ) ;
}
static int F_130 ( struct V_105 * V_66 )
{
struct V_1 * V_2 = F_23 ( V_66 ) ;
F_8 ( L_71 , V_2 -> V_18 ) ;
return F_83 ( V_2 , true ) ;
}
