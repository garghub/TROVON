static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
V_5 = F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
F_3 ( V_8 , V_9 ) ;
( void ) F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , ( V_3 ) ) ;
V_5 = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , ( V_3 ) ) ;
F_3 ( V_12 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
V_5 = F_4 ( V_14 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return V_5 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
F_3 ( V_14 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_16 , ( ( V_3 ) & 0x1ff ) ) ;
V_5 = F_4 ( V_17 ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
return V_5 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_16 , ( ( V_3 ) & 0x1ff ) ) ;
F_3 ( V_17 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_18 , V_4 ) ;
F_3 ( V_19 , ( V_3 ) ) ;
V_5 = F_4 ( V_20 ) ;
F_5 ( & V_2 -> V_18 , V_4 ) ;
return V_5 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_18 , V_4 ) ;
F_3 ( V_19 , ( V_3 ) ) ;
F_3 ( V_20 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_18 , V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_21 ) ;
switch ( V_2 -> V_22 ) {
case V_23 :
F_17 ( V_2 ,
V_24 ,
( const T_1 ) F_18 ( V_24 ) ) ;
break;
case V_25 :
F_17 ( V_2 ,
V_26 ,
( const T_1 ) F_18 ( V_26 ) ) ;
break;
case V_27 :
F_17 ( V_2 ,
V_28 ,
( const T_1 ) F_18 ( V_28 ) ) ;
break;
case V_29 :
F_17 ( V_2 ,
V_30 ,
( const T_1 ) F_18 ( V_30 ) ) ;
break;
default:
break;
}
F_19 ( & V_2 -> V_21 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
T_1 V_31 = V_2 -> clock . V_32 . V_33 ;
T_1 V_34 ;
if ( V_2 -> V_4 & V_35 )
return V_31 ;
V_34 = F_21 ( V_36 ) ;
if ( F_22 ( V_34 , V_37 , V_38 ) )
return 1000 ;
V_34 = F_21 ( V_39 ) ;
if ( F_22 ( V_34 , V_40 , V_41 ) )
return V_31 / 4 ;
return V_31 ;
}
void F_23 ( struct V_1 * V_2 ,
T_1 V_42 , T_1 V_43 , T_1 V_44 , T_1 V_45 )
{
T_1 V_46 = 0 ;
V_46 = F_24 ( V_46 , V_47 , V_48 , V_43 ) ;
V_46 = F_24 ( V_46 , V_47 , V_49 , V_42 ) ;
V_46 = F_24 ( V_46 , V_47 , V_50 , V_45 ) ;
V_46 = F_24 ( V_46 , V_47 , V_51 , V_44 ) ;
F_3 ( V_52 , V_46 ) ;
}
static void F_25 ( struct V_1 * V_2 , bool V_53 )
{
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_54 ;
T_1 V_55 = 0 ;
T_1 V_56 = 0 ;
T_1 V_57 = 0 ;
T_1 V_58 ;
bool V_5 ;
V_54 = F_4 ( V_59 ) ;
if ( V_2 -> V_60 . V_61 ) {
V_55 = F_4 ( V_62 ) ;
V_56 = F_4 ( V_63 ) ;
V_57 = F_4 ( V_64 ) ;
}
V_58 = F_21 ( V_65 ) ;
F_3 ( V_59 , ( V_54 & ~ V_66 ) ) ;
if ( V_2 -> V_60 . V_61 ) {
F_3 ( V_62 ,
( V_55 & ~ ( V_67 |
V_68 ) ) ) ;
F_3 ( V_63 ,
( V_56 & ~ ( V_69 |
V_70 ) ) ) ;
F_3 ( V_64 ,
( V_57 & ~ V_71 ) ) ;
}
F_27 ( V_65 , V_58 | V_72 ) ;
V_5 = F_28 ( V_2 ) ;
F_3 ( V_59 , V_54 ) ;
if ( V_2 -> V_60 . V_61 ) {
F_3 ( V_62 , V_55 ) ;
F_3 ( V_63 , V_56 ) ;
F_3 ( V_64 , V_57 ) ;
}
F_27 ( V_65 , V_58 ) ;
return V_5 ;
}
static T_2 F_29 ( struct V_1 * V_2 , T_1 V_73 ,
T_1 V_74 , T_1 V_75 )
{
T_2 V_76 ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_73 != 0xffffffff || V_74 != 0xffffffff )
F_30 ( V_2 , V_73 , V_74 ) ;
V_76 = F_4 ( V_75 ) ;
if ( V_73 != 0xffffffff || V_74 != 0xffffffff )
F_30 ( V_2 , 0xffffffff , 0xffffffff ) ;
F_19 ( & V_2 -> V_21 ) ;
return V_76 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_73 ,
T_1 V_74 , T_1 V_75 , T_1 * V_77 )
{
struct V_78 * V_79 = NULL ;
struct V_78 * V_80 ;
T_2 V_81 , V_82 ;
* V_77 = 0 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_79 = V_83 ;
V_81 = F_18 ( V_83 ) ;
break;
case V_25 :
case V_27 :
case V_29 :
V_79 = V_84 ;
V_81 = F_18 ( V_84 ) ;
break;
default:
return - V_85 ;
}
if ( V_79 ) {
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ ) {
V_80 = V_79 + V_82 ;
if ( V_75 != V_80 -> V_75 )
continue;
if ( ! V_80 -> V_86 )
* V_77 = V_80 -> V_87 ?
F_29 ( V_2 , V_73 ,
V_74 , V_75 ) :
F_4 ( V_75 ) ;
return 0 ;
}
}
for ( V_82 = 0 ; V_82 < F_18 ( V_88 ) ; V_82 ++ ) {
if ( V_75 != V_88 [ V_82 ] . V_75 )
continue;
if ( ! V_88 [ V_82 ] . V_86 )
* V_77 = V_88 [ V_82 ] . V_87 ?
F_29 ( V_2 , V_73 ,
V_74 , V_75 ) :
F_4 ( V_75 ) ;
return 0 ;
}
return - V_85 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_89 , L_1 ,
F_4 ( V_90 ) ) ;
F_33 ( V_2 -> V_89 , L_2 ,
F_4 ( V_91 ) ) ;
F_33 ( V_2 -> V_89 , L_3 ,
F_4 ( V_92 ) ) ;
F_33 ( V_2 -> V_89 , L_4 ,
F_4 ( V_93 ) ) ;
F_33 ( V_2 -> V_89 , L_5 ,
F_4 ( V_94 ) ) ;
F_33 ( V_2 -> V_89 , L_6 ,
F_4 ( V_95 ) ) ;
F_33 ( V_2 -> V_89 , L_7 ,
F_4 ( V_96 ) ) ;
F_33 ( V_2 -> V_89 , L_8 ,
F_4 ( V_97 ) ) ;
F_33 ( V_2 -> V_89 , L_9 ,
F_4 ( V_98 + V_99 ) ) ;
F_33 ( V_2 -> V_89 , L_10 ,
F_4 ( V_98 + V_100 ) ) ;
F_33 ( V_2 -> V_89 , L_11 , F_4 ( V_101 ) ) ;
F_33 ( V_2 -> V_89 , L_12 ,
F_4 ( V_102 ) ) ;
F_33 ( V_2 -> V_89 , L_13 ,
F_4 ( V_103 ) ) ;
F_33 ( V_2 -> V_89 , L_14 ,
F_4 ( V_104 ) ) ;
F_33 ( V_2 -> V_89 , L_15 ,
F_4 ( V_105 ) ) ;
F_33 ( V_2 -> V_89 , L_16 ,
F_4 ( V_106 ) ) ;
F_33 ( V_2 -> V_89 , L_17 , F_4 ( V_107 ) ) ;
F_33 ( V_2 -> V_89 , L_18 , F_4 ( V_108 ) ) ;
F_33 ( V_2 -> V_89 , L_19 ,
F_4 ( V_109 ) ) ;
F_33 ( V_2 -> V_89 , L_20 , F_4 ( V_110 ) ) ;
}
T_1 F_34 ( struct V_1 * V_2 )
{
T_1 V_111 = 0 ;
T_1 V_34 ;
V_34 = F_4 ( V_90 ) ;
if ( V_34 & ( V_112 | V_113 |
V_114 | V_115 |
V_116 | V_117 |
V_118 | V_119 |
V_120 | V_121 |
V_122 | V_123 ) )
V_111 |= V_124 ;
if ( V_34 & ( V_125 | V_126 ) )
V_111 |= V_127 ;
V_34 = F_4 ( V_91 ) ;
if ( V_34 & V_128 )
V_111 |= V_129 ;
if ( V_34 & ( V_130 |
V_131 |
V_132 ) )
V_111 |= V_127 ;
V_34 = F_4 ( V_97 ) ;
if ( V_34 & V_133 )
V_111 |= V_134 ;
if ( V_34 & V_135 )
V_111 |= V_136 ;
V_34 = F_4 ( V_96 ) ;
if ( V_34 & V_137 )
V_111 |= V_138 ;
if ( V_34 & V_139 )
V_111 |= V_140 ;
if ( V_34 & V_141 )
V_111 |= V_142 ;
if ( V_2 -> V_22 != V_23 ) {
if ( V_34 & ( V_143 |
V_144 ) )
V_111 |= V_145 ;
}
if ( V_34 & V_146 )
V_111 |= V_147 ;
if ( V_34 & ( V_148 | V_149 |
V_150 | V_151 ) )
V_111 |= V_152 ;
V_34 = F_4 ( V_98 + V_99 ) ;
if ( ! ( V_34 & V_153 ) )
V_111 |= V_134 ;
V_34 = F_4 ( V_98 + V_100 ) ;
if ( ! ( V_34 & V_153 ) )
V_111 |= V_136 ;
#if 0
if (adev->asic_type != CHIP_TOPAZ) {
tmp = RREG32(mmVCE_STATUS);
if (tmp & VCE_STATUS__VCPU_REPORT_RB0_BUSY_MASK)
reset_mask |= AMDGPU_RESET_VCE;
if (tmp & VCE_STATUS__VCPU_REPORT_RB1_BUSY_MASK)
reset_mask |= AMDGPU_RESET_VCE1;
}
if (adev->asic_type != CHIP_TOPAZ) {
if (amdgpu_display_is_display_hung(adev))
reset_mask |= AMDGPU_RESET_DISPLAY;
}
#endif
if ( V_111 & V_152 ) {
F_35 ( L_21 , V_111 ) ;
V_111 &= ~ V_152 ;
}
return V_111 ;
}
static void F_36 ( struct V_1 * V_2 , T_1 V_111 )
{
struct V_154 V_155 ;
T_1 V_156 = 0 , V_157 = 0 ;
T_1 V_34 ;
if ( V_111 == 0 )
return;
F_33 ( V_2 -> V_89 , L_22 , V_111 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_89 , L_23 ,
F_4 ( V_158 ) ) ;
F_33 ( V_2 -> V_89 , L_24 ,
F_4 ( V_159 ) ) ;
V_34 = F_4 ( V_160 ) ;
V_34 = F_24 ( V_34 , V_161 , V_162 , 1 ) ;
V_34 = F_24 ( V_34 , V_161 , V_163 , 1 ) ;
V_34 = F_24 ( V_34 , V_161 , V_164 , 1 ) ;
F_3 ( V_160 , V_34 ) ;
V_34 = F_4 ( V_165 ) ;
V_34 = F_24 ( V_34 , V_166 , V_167 , 1 ) ;
V_34 = F_24 ( V_34 , V_166 , V_168 , 1 ) ;
F_3 ( V_165 , V_34 ) ;
if ( V_111 & V_134 ) {
V_34 = F_4 ( V_169 + V_99 ) ;
V_34 = F_24 ( V_34 , V_170 , V_171 , 1 ) ;
F_3 ( V_169 + V_99 , V_34 ) ;
}
if ( V_111 & V_136 ) {
V_34 = F_4 ( V_169 + V_100 ) ;
V_34 = F_24 ( V_34 , V_170 , V_171 , 1 ) ;
F_3 ( V_169 + V_100 , V_34 ) ;
}
F_37 ( V_2 , & V_155 ) ;
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 -> V_89 , L_25 ) ;
}
if ( V_111 & ( V_124 | V_172 | V_127 ) ) {
V_156 =
F_24 ( V_156 , V_173 , V_174 , 1 ) ;
V_156 =
F_24 ( V_156 , V_173 , V_175 , 1 ) ;
}
if ( V_111 & V_127 ) {
V_156 =
F_24 ( V_156 , V_173 , V_174 , 1 ) ;
V_157 =
F_24 ( V_157 , V_176 , V_177 , 1 ) ;
}
if ( V_111 & V_134 )
V_157 =
F_24 ( V_157 , V_176 , V_178 , 1 ) ;
if ( V_111 & V_136 )
V_157 =
F_24 ( V_157 , V_176 , V_179 , 1 ) ;
if ( V_111 & V_180 )
V_157 =
F_24 ( V_157 , V_176 , V_181 , 1 ) ;
if ( V_111 & V_129 )
V_156 =
F_24 ( V_156 , V_173 , V_182 , 1 ) ;
if ( V_111 & V_140 )
V_157 =
F_24 ( V_157 , V_176 , V_183 , 1 ) ;
if ( V_111 & V_138 )
V_157 =
F_24 ( V_157 , V_176 , V_184 , 1 ) ;
if ( V_111 & V_142 )
V_157 =
F_24 ( V_157 , V_176 , V_177 , 1 ) ;
if ( V_111 & V_147 )
V_157 =
F_24 ( V_157 , V_176 , V_185 , 1 ) ;
if ( V_111 & V_145 )
V_157 =
F_24 ( V_157 , V_176 , V_186 , 1 ) ;
if ( V_111 & V_187 )
V_157 =
F_24 ( V_157 , V_176 , V_188 , 1 ) ;
if ( V_111 & V_187 )
V_157 =
F_24 ( V_157 , V_176 , V_189 , 1 ) ;
if ( ! ( V_2 -> V_4 & V_35 ) ) {
if ( V_111 & V_152 )
V_157 =
F_24 ( V_157 , V_176 , V_190 , 1 ) ;
}
if ( V_156 ) {
V_34 = F_4 ( V_191 ) ;
V_34 |= V_156 ;
F_33 ( V_2 -> V_89 , L_26 , V_34 ) ;
F_3 ( V_191 , V_34 ) ;
V_34 = F_4 ( V_191 ) ;
F_40 ( 50 ) ;
V_34 &= ~ V_156 ;
F_3 ( V_191 , V_34 ) ;
V_34 = F_4 ( V_191 ) ;
}
if ( V_157 ) {
V_34 = F_4 ( V_192 ) ;
V_34 |= V_157 ;
F_33 ( V_2 -> V_89 , L_27 , V_34 ) ;
F_3 ( V_192 , V_34 ) ;
V_34 = F_4 ( V_192 ) ;
F_40 ( 50 ) ;
V_34 &= ~ V_157 ;
F_3 ( V_192 , V_34 ) ;
V_34 = F_4 ( V_192 ) ;
}
F_40 ( 50 ) ;
F_41 ( V_2 , & V_155 ) ;
F_40 ( 50 ) ;
F_32 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_154 V_155 ;
T_1 V_34 , V_82 ;
F_33 ( V_2 -> V_89 , L_28 ) ;
V_34 = F_4 ( V_160 ) ;
V_34 = F_24 ( V_34 , V_161 , V_162 , 1 ) ;
V_34 = F_24 ( V_34 , V_161 , V_163 , 1 ) ;
V_34 = F_24 ( V_34 , V_161 , V_164 , 1 ) ;
F_3 ( V_160 , V_34 ) ;
V_34 = F_4 ( V_165 ) ;
V_34 = F_24 ( V_34 , V_166 , V_167 , 1 ) ;
V_34 = F_24 ( V_34 , V_166 , V_168 , 1 ) ;
F_3 ( V_165 , V_34 ) ;
F_3 ( V_160 , V_193 |
V_194 | V_195 ) ;
F_3 ( V_165 ,
V_196 | V_197 ) ;
V_34 = F_4 ( V_169 + V_99 ) ;
V_34 = F_24 ( V_34 , V_170 , V_171 , 1 ) ;
F_3 ( V_169 + V_99 , V_34 ) ;
V_34 = F_4 ( V_169 + V_100 ) ;
V_34 = F_24 ( V_34 , V_170 , V_171 , 1 ) ;
F_3 ( V_169 + V_100 , V_34 ) ;
F_40 ( 50 ) ;
F_37 ( V_2 , & V_155 ) ;
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 -> V_89 , L_29 ) ;
}
F_43 ( V_2 -> V_198 ) ;
F_44 ( V_2 ) ;
F_40 ( 100 ) ;
for ( V_82 = 0 ; V_82 < V_2 -> V_199 ; V_82 ++ ) {
if ( F_4 ( V_200 ) != 0xffffffff )
break;
F_40 ( 1 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , bool V_201 )
{
T_1 V_34 = F_4 ( V_202 ) ;
if ( V_201 )
V_34 |= V_203 ;
else
V_34 &= ~ V_203 ;
F_3 ( V_202 , V_34 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_1 V_111 ;
V_111 = F_34 ( V_2 ) ;
if ( V_111 )
F_45 ( V_2 , true ) ;
F_36 ( V_2 , V_111 ) ;
V_111 = F_34 ( V_2 ) ;
if ( V_111 && V_204 )
F_42 ( V_2 ) ;
V_111 = F_34 ( V_2 ) ;
if ( ! V_111 )
F_45 ( V_2 , false ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_205 , T_1 V_206 )
{
int V_5 , V_82 ;
struct V_207 V_208 ;
T_2 V_34 ;
V_5 = F_48 ( V_2 ,
V_209 ,
clock , false , & V_208 ) ;
if ( V_5 )
return V_5 ;
V_34 = F_21 ( V_205 ) ;
V_34 &= ~ ( V_210 |
V_211 ) ;
V_34 |= V_208 . V_212 ;
F_27 ( V_205 , V_34 ) ;
for ( V_82 = 0 ; V_82 < 100 ; V_82 ++ ) {
if ( F_21 ( V_206 ) & V_213 )
break;
F_49 ( 10 ) ;
}
if ( V_82 == 100 )
return - V_214 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_215 , T_1 V_216 )
{
int V_5 ;
V_5 = F_47 ( V_2 , V_215 , V_217 , V_218 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_47 ( V_2 , V_216 , V_219 , V_220 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_221 , T_1 V_222 )
{
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_223 ;
int V_224 ;
if ( F_53 ( V_2 -> V_198 -> V_225 ) )
return;
if ( V_226 == 0 )
return;
if ( V_2 -> V_4 & V_35 )
return;
V_224 = F_54 ( V_2 -> V_227 , & V_223 ) ;
if ( V_224 != 0 )
return;
if ( ! ( V_223 & ( V_228 | V_229 ) ) )
return;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_230 == 0 )
return;
}
static void F_56 ( struct V_1 * V_2 ,
bool V_231 )
{
T_1 V_34 ;
if ( V_2 -> V_4 & V_35 )
return;
V_34 = F_4 ( V_232 ) ;
if ( V_231 )
V_34 = F_24 ( V_34 , V_233 , V_233 , 1 ) ;
else
V_34 = F_24 ( V_34 , V_233 , V_233 , 0 ) ;
F_3 ( V_232 , V_34 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_234 = V_235 ;
V_2 -> V_236 = F_18 ( V_235 ) ;
break;
case V_25 :
V_2 -> V_234 = V_237 ;
V_2 -> V_236 = F_18 ( V_237 ) ;
break;
case V_27 :
V_2 -> V_234 = V_238 ;
V_2 -> V_236 = F_18 ( V_238 ) ;
break;
case V_29 :
V_2 -> V_234 = V_239 ;
V_2 -> V_236 = F_18 ( V_239 ) ;
break;
default:
return - V_85 ;
}
return 0 ;
}
static T_2 F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 == V_23 )
return ( F_4 ( V_240 ) & V_241 )
>> V_242 ;
else
return ( F_4 ( V_243 ) & V_244 )
>> V_245 ;
}
static int F_59 ( void * V_246 )
{
bool V_247 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_246 ;
if ( V_2 -> V_4 & V_35 ) {
V_2 -> V_248 = & F_9 ;
V_2 -> V_249 = & F_10 ;
} else {
V_2 -> V_248 = & F_7 ;
V_2 -> V_249 = & F_8 ;
}
V_2 -> V_250 = & F_1 ;
V_2 -> V_251 = & F_6 ;
V_2 -> V_252 = & F_11 ;
V_2 -> V_253 = & F_12 ;
V_2 -> V_254 = & F_13 ;
V_2 -> V_255 = & F_14 ;
V_2 -> V_256 = & V_257 ;
if ( F_60 ( V_2 , V_258 ) &&
( V_259 & ( 1 << V_258 ) ) )
V_247 = true ;
V_2 -> V_260 = F_58 ( V_2 ) ;
V_2 -> V_261 = 0xFF ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_262 = false ;
V_2 -> V_263 = 0 ;
V_2 -> V_264 = 0 ;
V_2 -> V_261 = 0x1 ;
if ( V_265 && V_247 )
V_2 -> V_266 . V_267 = true ;
break;
case V_25 :
case V_27 :
V_2 -> V_262 = true ;
V_2 -> V_263 = 0 ;
V_2 -> V_264 = 0 ;
V_2 -> V_261 = V_2 -> V_260 + 0x14 ;
if ( V_265 && V_247 )
V_2 -> V_266 . V_267 = true ;
break;
case V_29 :
V_2 -> V_262 = true ;
V_2 -> V_263 = 0 ;
V_2 -> V_264 = V_268 ;
V_2 -> V_261 = V_2 -> V_260 + 0x1 ;
if ( V_265 && V_247 )
V_2 -> V_266 . V_267 = true ;
break;
default:
return - V_85 ;
}
return 0 ;
}
static int F_61 ( void * V_246 )
{
return 0 ;
}
static int F_62 ( void * V_246 )
{
return 0 ;
}
static int F_63 ( void * V_246 )
{
struct V_1 * V_2 = (struct V_1 * ) V_246 ;
F_15 ( V_2 ) ;
F_52 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 , true ) ;
return 0 ;
}
static int F_64 ( void * V_246 )
{
struct V_1 * V_2 = (struct V_1 * ) V_246 ;
F_56 ( V_2 , false ) ;
return 0 ;
}
static int F_65 ( void * V_246 )
{
struct V_1 * V_2 = (struct V_1 * ) V_246 ;
return F_64 ( V_2 ) ;
}
static int F_66 ( void * V_246 )
{
struct V_1 * V_2 = (struct V_1 * ) V_246 ;
return F_63 ( V_2 ) ;
}
static bool F_67 ( void * V_246 )
{
return true ;
}
static int F_68 ( void * V_246 )
{
return 0 ;
}
static void F_69 ( void * V_246 )
{
return;
}
static int F_70 ( void * V_246 )
{
return 0 ;
}
static int F_71 ( void * V_246 ,
enum V_269 V_53 )
{
return 0 ;
}
static int F_72 ( void * V_246 ,
enum V_270 V_53 )
{
return 0 ;
}
