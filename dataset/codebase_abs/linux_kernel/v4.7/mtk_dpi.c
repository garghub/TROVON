static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
T_1 V_9 = F_4 ( V_5 -> V_10 + V_6 ) & ~ V_8 ;
V_9 |= ( V_7 & V_8 ) ;
F_5 ( V_9 , V_5 -> V_10 + V_6 ) ;
}
static void F_6 ( struct V_1 * V_5 , bool V_11 )
{
F_3 ( V_5 , V_12 , V_11 ? V_13 : 0 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_5 )
{
F_3 ( V_5 , V_14 , V_15 , V_15 ) ;
}
static void F_8 ( struct V_1 * V_5 )
{
F_3 ( V_5 , V_14 , 0 , V_15 ) ;
}
static void F_9 ( struct V_1 * V_5 ,
struct V_16 * V_17 )
{
F_3 ( V_5 , V_18 ,
V_17 -> V_19 << V_20 , V_21 ) ;
F_3 ( V_5 , V_22 ,
V_17 -> V_23 << V_24 , V_25 ) ;
F_3 ( V_5 , V_22 , V_17 -> V_26 << V_27 ,
V_28 ) ;
}
static void F_10 ( struct V_1 * V_5 ,
struct V_16 * V_17 ,
T_1 V_29 , T_1 V_30 )
{
F_3 ( V_5 , V_29 ,
V_17 -> V_19 << V_31 ,
V_32 ) ;
F_3 ( V_5 , V_29 ,
V_17 -> V_33 << V_34 ,
V_35 ) ;
F_3 ( V_5 , V_30 ,
V_17 -> V_23 << V_36 ,
V_37 ) ;
F_3 ( V_5 , V_30 ,
V_17 -> V_26 << V_38 ,
V_39 ) ;
}
static void F_11 ( struct V_1 * V_5 ,
struct V_16 * V_17 )
{
F_10 ( V_5 , V_17 , V_40 , V_41 ) ;
}
static void F_12 ( struct V_1 * V_5 ,
struct V_16 * V_17 )
{
F_10 ( V_5 , V_17 , V_42 ,
V_43 ) ;
}
static void F_13 ( struct V_1 * V_5 ,
struct V_16 * V_17 )
{
F_10 ( V_5 , V_17 , V_44 ,
V_45 ) ;
}
static void F_14 ( struct V_1 * V_5 ,
struct V_16 * V_17 )
{
F_10 ( V_5 , V_17 , V_46 ,
V_47 ) ;
}
static void F_15 ( struct V_1 * V_5 ,
struct V_48 * V_49 )
{
unsigned int V_50 ;
V_50 = ( V_49 -> V_51 == V_52 ? 0 : V_53 ) |
( V_49 -> V_54 == V_52 ? 0 : V_55 ) |
( V_49 -> V_56 == V_52 ? 0 : V_57 ) |
( V_49 -> V_58 == V_52 ? 0 : V_59 ) ;
F_3 ( V_5 , V_60 , V_50 ,
V_53 | V_55 | V_57 | V_59 ) ;
}
static void F_16 ( struct V_1 * V_5 , bool V_61 )
{
F_3 ( V_5 , V_62 , V_61 ? V_63 : 0 , V_63 ) ;
}
static void F_17 ( struct V_1 * V_5 , bool V_64 )
{
F_3 ( V_5 , V_62 , V_64 ? V_65 : 0 , V_65 ) ;
}
static void F_18 ( struct V_1 * V_5 , T_1 V_66 , T_1 V_67 )
{
F_3 ( V_5 , V_68 , V_66 << V_69 , V_70 ) ;
F_3 ( V_5 , V_68 , V_67 << V_71 , V_72 ) ;
}
static void F_19 ( struct V_1 * V_5 ,
struct V_73 * V_74 )
{
F_3 ( V_5 , V_75 , V_74 -> V_76 << V_77 ,
V_78 ) ;
F_3 ( V_5 , V_75 , V_74 -> V_79 << V_80 ,
V_81 ) ;
F_3 ( V_5 , V_82 , V_74 -> V_83 << V_84 ,
V_85 ) ;
F_3 ( V_5 , V_82 , V_74 -> V_86 << V_87 ,
V_88 ) ;
}
static void F_20 ( struct V_1 * V_5 ,
enum V_89 V_90 )
{
T_1 V_7 ;
switch ( V_90 ) {
case V_91 :
V_7 = V_92 ;
break;
case V_93 :
V_7 = V_94 ;
break;
case V_95 :
V_7 = V_96 ;
break;
case V_97 :
V_7 = V_98 ;
break;
default:
V_7 = V_92 ;
break;
}
F_3 ( V_5 , V_60 , V_7 << V_99 ,
V_100 ) ;
}
static void F_21 ( struct V_1 * V_5 ,
enum V_101 V_102 )
{
T_1 V_7 ;
switch ( V_102 ) {
case V_103 :
V_7 = V_104 ;
break;
case V_105 :
V_7 = V_106 ;
break;
case V_107 :
V_7 = V_108 ;
break;
case V_109 :
V_7 = V_110 ;
break;
case V_111 :
V_7 = V_112 ;
break;
default:
V_7 = V_104 ;
break;
}
F_3 ( V_5 , V_60 , V_7 << V_113 , V_114 ) ;
}
static void F_22 ( struct V_1 * V_5 ,
enum V_115 V_116 )
{
T_1 V_7 ;
switch ( V_116 ) {
case V_117 :
V_7 = V_118 ;
break;
case V_119 :
V_7 = V_120 ;
break;
case V_121 :
V_7 = V_122 ;
break;
case V_123 :
V_7 = V_124 ;
break;
case V_125 :
V_7 = V_126 ;
break;
case V_127 :
V_7 = V_128 ;
break;
default:
V_7 = V_118 ;
break;
}
F_3 ( V_5 , V_60 , V_7 << V_129 , V_130 ) ;
}
static void F_23 ( struct V_1 * V_5 , bool V_131 )
{
F_3 ( V_5 , V_62 , V_131 ? V_132 : 0 , V_132 ) ;
}
static void F_24 ( struct V_1 * V_5 , bool V_131 )
{
F_3 ( V_5 , V_62 , V_131 ? V_133 : 0 , V_133 ) ;
}
static void F_25 ( struct V_1 * V_5 , bool V_131 )
{
F_3 ( V_5 , V_62 , V_131 ? V_134 : 0 , V_134 ) ;
}
static void F_26 ( struct V_1 * V_5 )
{
F_3 ( V_5 , V_135 , V_136 , V_136 ) ;
}
static void F_27 ( struct V_1 * V_5 ,
enum V_137 V_138 )
{
if ( ( V_138 == V_139 ) ||
( V_138 == V_140 ) ) {
F_23 ( V_5 , false ) ;
F_24 ( V_5 , true ) ;
F_25 ( V_5 , false ) ;
F_22 ( V_5 , V_127 ) ;
} else if ( ( V_138 == V_141 ) ||
( V_138 == V_142 ) ) {
F_23 ( V_5 , true ) ;
F_24 ( V_5 , true ) ;
F_25 ( V_5 , true ) ;
F_22 ( V_5 , V_117 ) ;
} else {
F_23 ( V_5 , false ) ;
F_24 ( V_5 , false ) ;
F_25 ( V_5 , false ) ;
F_22 ( V_5 , V_117 ) ;
}
}
static void F_28 ( struct V_1 * V_5 , enum V_143 V_144 )
{
V_5 -> V_145 &= ~ V_144 ;
if ( ( V_5 -> V_145 & V_146 ) ||
( V_5 -> V_145 & V_147 ) )
return;
if ( ! V_5 -> V_148 )
return;
F_8 ( V_5 ) ;
F_29 ( V_5 -> V_149 ) ;
F_29 ( V_5 -> V_150 ) ;
V_5 -> V_148 = false ;
}
static int F_30 ( struct V_1 * V_5 , enum V_143 V_144 )
{
int V_151 ;
V_5 -> V_145 |= V_144 ;
if ( ! ( V_5 -> V_145 & V_146 ) &&
! ( V_5 -> V_145 & V_147 ) )
return 0 ;
if ( V_5 -> V_148 )
return 0 ;
V_151 = F_31 ( V_5 -> V_150 ) ;
if ( V_151 ) {
F_32 ( V_5 -> V_152 , L_1 , V_151 ) ;
goto V_153;
}
V_151 = F_31 ( V_5 -> V_149 ) ;
if ( V_151 ) {
F_32 ( V_5 -> V_152 , L_2 , V_151 ) ;
goto V_154;
}
F_7 ( V_5 ) ;
V_5 -> V_148 = true ;
return 0 ;
V_154:
F_29 ( V_5 -> V_150 ) ;
V_153:
V_5 -> V_145 &= ~ V_144 ;
return V_151 ;
}
static int F_33 ( struct V_1 * V_5 ,
struct V_155 * V_156 )
{
struct V_73 V_74 ;
struct V_48 V_49 ;
struct V_16 V_157 ;
struct V_16 V_158 = { 0 } ;
struct V_16 V_159 = { 0 } ;
struct V_16 V_160 = { 0 } ;
struct V_16 V_161 = { 0 } ;
unsigned long V_162 ;
unsigned long V_163 ;
unsigned int V_164 ;
V_162 = 1000UL * V_156 -> clock ;
if ( V_156 -> clock <= 74000 )
V_164 = 8 * 3 ;
else
V_164 = 4 * 3 ;
V_163 = V_162 * V_164 ;
F_34 ( V_5 -> V_152 , L_3 ,
V_163 , V_162 ) ;
F_35 ( V_5 -> V_165 , V_163 ) ;
V_163 = F_36 ( V_5 -> V_165 ) ;
V_162 = V_163 / V_164 ;
F_35 ( V_5 -> V_149 , V_162 ) ;
V_162 = F_36 ( V_5 -> V_149 ) ;
F_34 ( V_5 -> V_152 , L_4 ,
V_163 , V_162 ) ;
V_74 . V_83 = 0x0010 ;
V_74 . V_86 = 0x0FE0 ;
V_74 . V_76 = 0x0010 ;
V_74 . V_79 = 0x0FE0 ;
V_49 . V_51 = V_166 ;
V_49 . V_54 = V_52 ;
V_49 . V_56 = V_156 -> V_167 & V_168 ?
V_166 : V_52 ;
V_49 . V_58 = V_156 -> V_167 & V_169 ?
V_166 : V_52 ;
V_157 . V_19 = V_156 -> V_170 - V_156 -> V_171 ;
V_157 . V_23 = V_156 -> V_172 - V_156 -> V_170 ;
V_157 . V_26 = V_156 -> V_171 - V_156 -> V_173 ;
V_157 . V_33 = false ;
V_158 . V_19 = V_156 -> V_174 - V_156 -> V_175 ;
V_158 . V_23 = V_156 -> V_176 - V_156 -> V_174 ;
V_158 . V_26 = V_156 -> V_175 - V_156 -> V_177 ;
V_158 . V_33 = false ;
if ( V_156 -> V_167 & V_178 &&
V_156 -> V_167 & V_179 ) {
V_159 = V_158 ;
V_160 = V_158 ;
V_161 = V_158 ;
V_159 . V_33 = true ;
V_161 . V_33 = true ;
} else if ( V_156 -> V_167 & V_178 &&
! ( V_156 -> V_167 & V_179 ) ) {
V_159 = V_158 ;
V_159 . V_33 = true ;
} else if ( ! ( V_156 -> V_167 & V_178 ) &&
V_156 -> V_167 & V_179 ) {
V_160 = V_158 ;
}
F_6 ( V_5 , true ) ;
F_15 ( V_5 , & V_49 ) ;
F_9 ( V_5 , & V_157 ) ;
F_11 ( V_5 , & V_158 ) ;
F_13 ( V_5 , & V_160 ) ;
F_12 ( V_5 , & V_159 ) ;
F_14 ( V_5 , & V_161 ) ;
F_16 ( V_5 , ! ! ( V_156 -> V_167 & V_179 ) ) ;
F_17 ( V_5 , ! ! ( V_156 -> V_167 &
V_178 ) ) ;
if ( V_156 -> V_167 & V_178 )
F_18 ( V_5 , V_156 -> V_173 , V_156 -> V_177 / 2 ) ;
else
F_18 ( V_5 , V_156 -> V_173 , V_156 -> V_177 ) ;
F_19 ( V_5 , & V_74 ) ;
F_20 ( V_5 , V_5 -> V_180 ) ;
F_22 ( V_5 , V_5 -> V_181 ) ;
F_21 ( V_5 , V_5 -> V_182 ) ;
F_27 ( V_5 , V_5 -> V_183 ) ;
F_26 ( V_5 ) ;
F_6 ( V_5 , false ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_4 )
{
F_38 ( V_4 ) ;
}
static bool F_39 ( struct V_2 * V_4 ,
const struct V_155 * V_156 ,
struct V_155 * V_184 )
{
return true ;
}
static void F_40 ( struct V_2 * V_4 ,
struct V_155 * V_156 ,
struct V_155 * V_184 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_41 ( & V_5 -> V_156 , V_184 ) ;
}
static void F_42 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_28 ( V_5 , V_147 ) ;
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_30 ( V_5 , V_147 ) ;
F_33 ( V_5 , & V_5 -> V_156 ) ;
}
static int F_44 ( struct V_2 * V_4 ,
struct V_185 * V_186 ,
struct V_187 * V_188 )
{
return 0 ;
}
static void F_45 ( struct V_189 * V_190 )
{
struct V_1 * V_5 = F_2 ( V_190 , struct V_1 , V_191 ) ;
F_30 ( V_5 , V_146 ) ;
}
static void F_46 ( struct V_189 * V_190 )
{
struct V_1 * V_5 = F_2 ( V_190 , struct V_1 , V_191 ) ;
F_28 ( V_5 , V_146 ) ;
}
static int F_47 ( struct V_192 * V_152 , struct V_192 * V_193 , void * V_194 )
{
struct V_1 * V_5 = F_48 ( V_152 ) ;
struct V_195 * V_196 = V_194 ;
int V_151 ;
V_151 = F_49 ( V_196 , & V_5 -> V_191 ) ;
if ( V_151 < 0 ) {
F_32 ( V_152 , L_5 ,
V_152 -> V_197 -> V_198 , V_151 ) ;
return V_151 ;
}
V_151 = F_50 ( V_196 , & V_5 -> V_4 , & V_199 ,
V_200 , NULL ) ;
if ( V_151 ) {
F_32 ( V_152 , L_6 , V_151 ) ;
goto V_201;
}
F_51 ( & V_5 -> V_4 , & V_202 ) ;
V_5 -> V_4 . V_203 = F_52 ( 1 ) ;
V_5 -> V_4 . V_204 -> V_4 = & V_5 -> V_4 ;
V_151 = F_53 ( V_5 -> V_4 . V_152 , V_5 -> V_4 . V_204 ) ;
if ( V_151 ) {
F_32 ( V_152 , L_7 , V_151 ) ;
goto V_205;
}
V_5 -> V_180 = V_91 ;
V_5 -> V_181 = V_117 ;
V_5 -> V_182 = V_103 ;
V_5 -> V_183 = V_206 ;
return 0 ;
V_205:
F_38 ( & V_5 -> V_4 ) ;
V_201:
F_54 ( V_196 , & V_5 -> V_191 ) ;
return V_151 ;
}
static void F_55 ( struct V_192 * V_152 , struct V_192 * V_193 ,
void * V_194 )
{
struct V_1 * V_5 = F_48 ( V_152 ) ;
struct V_195 * V_196 = V_194 ;
F_38 ( & V_5 -> V_4 ) ;
F_54 ( V_196 , & V_5 -> V_191 ) ;
}
static int F_56 ( struct V_207 * V_208 )
{
struct V_192 * V_152 = & V_208 -> V_152 ;
struct V_1 * V_5 ;
struct V_209 * V_210 ;
struct V_211 * V_212 , * V_213 = NULL ;
int V_214 ;
int V_151 ;
V_5 = F_57 ( V_152 , sizeof( * V_5 ) , V_215 ) ;
if ( ! V_5 )
return - V_216 ;
V_5 -> V_152 = V_152 ;
V_210 = F_58 ( V_208 , V_217 , 0 ) ;
V_5 -> V_10 = F_59 ( V_152 , V_210 ) ;
if ( F_60 ( V_5 -> V_10 ) ) {
V_151 = F_61 ( V_5 -> V_10 ) ;
F_32 ( V_152 , L_8 , V_151 ) ;
return V_151 ;
}
V_5 -> V_150 = F_62 ( V_152 , L_9 ) ;
if ( F_60 ( V_5 -> V_150 ) ) {
V_151 = F_61 ( V_5 -> V_150 ) ;
F_32 ( V_152 , L_10 , V_151 ) ;
return V_151 ;
}
V_5 -> V_149 = F_62 ( V_152 , L_11 ) ;
if ( F_60 ( V_5 -> V_149 ) ) {
V_151 = F_61 ( V_5 -> V_149 ) ;
F_32 ( V_152 , L_12 , V_151 ) ;
return V_151 ;
}
V_5 -> V_165 = F_62 ( V_152 , L_13 ) ;
if ( F_60 ( V_5 -> V_165 ) ) {
V_151 = F_61 ( V_5 -> V_165 ) ;
F_32 ( V_152 , L_14 , V_151 ) ;
return V_151 ;
}
V_5 -> V_218 = F_63 ( V_208 , 0 ) ;
if ( V_5 -> V_218 <= 0 ) {
F_32 ( V_152 , L_15 , V_5 -> V_218 ) ;
return - V_219 ;
}
V_212 = F_64 ( V_152 -> V_197 , NULL ) ;
if ( V_212 ) {
V_213 = F_65 ( V_212 ) ;
F_66 ( V_212 ) ;
}
if ( ! V_213 ) {
F_32 ( V_152 , L_16 ) ;
return - V_220 ;
}
F_67 ( V_152 , L_17 , V_213 -> V_198 ) ;
V_5 -> V_4 . V_204 = F_68 ( V_213 ) ;
F_66 ( V_213 ) ;
if ( ! V_5 -> V_4 . V_204 )
return - V_221 ;
V_214 = F_69 ( V_152 -> V_197 , V_222 ) ;
if ( V_214 < 0 ) {
F_32 ( V_152 , L_18 , V_214 ) ;
return V_214 ;
}
V_151 = F_70 ( V_152 , V_152 -> V_197 , & V_5 -> V_191 , V_214 ,
& V_223 ) ;
if ( V_151 ) {
F_32 ( V_152 , L_19 , V_151 ) ;
return V_151 ;
}
F_71 ( V_208 , V_5 ) ;
V_151 = F_72 ( V_152 , & V_224 ) ;
if ( V_151 ) {
F_32 ( V_152 , L_20 , V_151 ) ;
return V_151 ;
}
return 0 ;
}
static int F_73 ( struct V_207 * V_208 )
{
F_74 ( & V_208 -> V_152 , & V_224 ) ;
return 0 ;
}
