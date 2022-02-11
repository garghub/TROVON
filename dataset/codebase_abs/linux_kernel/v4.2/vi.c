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
default:
break;
}
F_19 ( & V_2 -> V_21 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
T_1 V_29 = V_2 -> clock . V_30 . V_31 ;
T_1 V_32 ;
if ( V_2 -> V_4 & V_33 )
return V_29 ;
V_32 = F_21 ( V_34 ) ;
if ( F_22 ( V_32 , V_35 , V_36 ) )
return 1000 ;
V_32 = F_21 ( V_37 ) ;
if ( F_22 ( V_32 , V_38 , V_39 ) )
return V_29 / 4 ;
return V_29 ;
}
void F_23 ( struct V_1 * V_2 ,
T_1 V_40 , T_1 V_41 , T_1 V_42 , T_1 V_43 )
{
T_1 V_44 = 0 ;
V_44 = F_24 ( V_44 , V_45 , V_46 , V_41 ) ;
V_44 = F_24 ( V_44 , V_45 , V_47 , V_40 ) ;
V_44 = F_24 ( V_44 , V_45 , V_48 , V_43 ) ;
V_44 = F_24 ( V_44 , V_45 , V_49 , V_42 ) ;
F_3 ( V_50 , V_44 ) ;
}
static void F_25 ( struct V_1 * V_2 , bool V_51 )
{
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_52 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 = 0 ;
T_1 V_56 ;
bool V_5 ;
V_52 = F_4 ( V_57 ) ;
if ( V_2 -> V_58 . V_59 ) {
V_53 = F_4 ( V_60 ) ;
V_54 = F_4 ( V_61 ) ;
V_55 = F_4 ( V_62 ) ;
}
V_56 = F_21 ( V_63 ) ;
F_3 ( V_57 , ( V_52 & ~ V_64 ) ) ;
if ( V_2 -> V_58 . V_59 ) {
F_3 ( V_60 ,
( V_53 & ~ ( V_65 |
V_66 ) ) ) ;
F_3 ( V_61 ,
( V_54 & ~ ( V_67 |
V_68 ) ) ) ;
F_3 ( V_62 ,
( V_55 & ~ V_69 ) ) ;
}
F_27 ( V_63 , V_56 | V_70 ) ;
V_5 = F_28 ( V_2 ) ;
F_3 ( V_57 , V_52 ) ;
if ( V_2 -> V_58 . V_59 ) {
F_3 ( V_60 , V_53 ) ;
F_3 ( V_61 , V_54 ) ;
F_3 ( V_62 , V_55 ) ;
}
F_27 ( V_63 , V_56 ) ;
return V_5 ;
}
static T_2 F_29 ( struct V_1 * V_2 , T_1 V_71 ,
T_1 V_72 , T_1 V_73 )
{
T_2 V_74 ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_71 != 0xffffffff || V_72 != 0xffffffff )
F_30 ( V_2 , V_71 , V_72 ) ;
V_74 = F_4 ( V_73 ) ;
if ( V_71 != 0xffffffff || V_72 != 0xffffffff )
F_30 ( V_2 , 0xffffffff , 0xffffffff ) ;
F_19 ( & V_2 -> V_21 ) ;
return V_74 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_71 ,
T_1 V_72 , T_1 V_73 , T_1 * V_75 )
{
struct V_76 * V_77 = NULL ;
struct V_76 * V_78 ;
T_2 V_79 , V_80 ;
* V_75 = 0 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_77 = V_81 ;
V_79 = F_18 ( V_81 ) ;
break;
case V_25 :
case V_27 :
V_77 = V_82 ;
V_79 = F_18 ( V_82 ) ;
break;
default:
return - V_83 ;
}
if ( V_77 ) {
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_78 = V_77 + V_80 ;
if ( V_73 != V_78 -> V_73 )
continue;
if ( ! V_78 -> V_84 )
* V_75 = V_78 -> V_85 ?
F_29 ( V_2 , V_71 ,
V_72 , V_73 ) :
F_4 ( V_73 ) ;
return 0 ;
}
}
for ( V_80 = 0 ; V_80 < F_18 ( V_86 ) ; V_80 ++ ) {
if ( V_73 != V_86 [ V_80 ] . V_73 )
continue;
if ( ! V_86 [ V_80 ] . V_84 )
* V_75 = V_86 [ V_80 ] . V_85 ?
F_29 ( V_2 , V_71 ,
V_72 , V_73 ) :
F_4 ( V_73 ) ;
return 0 ;
}
return - V_83 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_87 , L_1 ,
F_4 ( V_88 ) ) ;
F_33 ( V_2 -> V_87 , L_2 ,
F_4 ( V_89 ) ) ;
F_33 ( V_2 -> V_87 , L_3 ,
F_4 ( V_90 ) ) ;
F_33 ( V_2 -> V_87 , L_4 ,
F_4 ( V_91 ) ) ;
F_33 ( V_2 -> V_87 , L_5 ,
F_4 ( V_92 ) ) ;
F_33 ( V_2 -> V_87 , L_6 ,
F_4 ( V_93 ) ) ;
F_33 ( V_2 -> V_87 , L_7 ,
F_4 ( V_94 ) ) ;
F_33 ( V_2 -> V_87 , L_8 ,
F_4 ( V_95 ) ) ;
F_33 ( V_2 -> V_87 , L_9 ,
F_4 ( V_96 + V_97 ) ) ;
F_33 ( V_2 -> V_87 , L_10 ,
F_4 ( V_96 + V_98 ) ) ;
F_33 ( V_2 -> V_87 , L_11 , F_4 ( V_99 ) ) ;
F_33 ( V_2 -> V_87 , L_12 ,
F_4 ( V_100 ) ) ;
F_33 ( V_2 -> V_87 , L_13 ,
F_4 ( V_101 ) ) ;
F_33 ( V_2 -> V_87 , L_14 ,
F_4 ( V_102 ) ) ;
F_33 ( V_2 -> V_87 , L_15 ,
F_4 ( V_103 ) ) ;
F_33 ( V_2 -> V_87 , L_16 ,
F_4 ( V_104 ) ) ;
F_33 ( V_2 -> V_87 , L_17 , F_4 ( V_105 ) ) ;
F_33 ( V_2 -> V_87 , L_18 , F_4 ( V_106 ) ) ;
F_33 ( V_2 -> V_87 , L_19 ,
F_4 ( V_107 ) ) ;
F_33 ( V_2 -> V_87 , L_20 , F_4 ( V_108 ) ) ;
}
T_1 F_34 ( struct V_1 * V_2 )
{
T_1 V_109 = 0 ;
T_1 V_32 ;
V_32 = F_4 ( V_88 ) ;
if ( V_32 & ( V_110 | V_111 |
V_112 | V_113 |
V_114 | V_115 |
V_116 | V_117 |
V_118 | V_119 |
V_120 | V_121 ) )
V_109 |= V_122 ;
if ( V_32 & ( V_123 | V_124 ) )
V_109 |= V_125 ;
V_32 = F_4 ( V_89 ) ;
if ( V_32 & V_126 )
V_109 |= V_127 ;
if ( V_32 & ( V_128 |
V_129 |
V_130 ) )
V_109 |= V_125 ;
V_32 = F_4 ( V_95 ) ;
if ( V_32 & V_131 )
V_109 |= V_132 ;
if ( V_32 & V_133 )
V_109 |= V_134 ;
V_32 = F_4 ( V_94 ) ;
if ( V_32 & V_135 )
V_109 |= V_136 ;
if ( V_32 & V_137 )
V_109 |= V_138 ;
if ( V_32 & V_139 )
V_109 |= V_140 ;
if ( V_2 -> V_22 != V_23 ) {
if ( V_32 & ( V_141 |
V_142 ) )
V_109 |= V_143 ;
}
if ( V_32 & V_144 )
V_109 |= V_145 ;
if ( V_32 & ( V_146 | V_147 |
V_148 | V_149 ) )
V_109 |= V_150 ;
V_32 = F_4 ( V_96 + V_97 ) ;
if ( ! ( V_32 & V_151 ) )
V_109 |= V_132 ;
V_32 = F_4 ( V_96 + V_98 ) ;
if ( ! ( V_32 & V_151 ) )
V_109 |= V_134 ;
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
if ( V_109 & V_150 ) {
F_35 ( L_21 , V_109 ) ;
V_109 &= ~ V_150 ;
}
return V_109 ;
}
static void F_36 ( struct V_1 * V_2 , T_1 V_109 )
{
struct V_152 V_153 ;
T_1 V_154 = 0 , V_155 = 0 ;
T_1 V_32 ;
if ( V_109 == 0 )
return;
F_33 ( V_2 -> V_87 , L_22 , V_109 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_87 , L_23 ,
F_4 ( V_156 ) ) ;
F_33 ( V_2 -> V_87 , L_24 ,
F_4 ( V_157 ) ) ;
V_32 = F_4 ( V_158 ) ;
V_32 = F_24 ( V_32 , V_159 , V_160 , 1 ) ;
V_32 = F_24 ( V_32 , V_159 , V_161 , 1 ) ;
V_32 = F_24 ( V_32 , V_159 , V_162 , 1 ) ;
F_3 ( V_158 , V_32 ) ;
V_32 = F_4 ( V_163 ) ;
V_32 = F_24 ( V_32 , V_164 , V_165 , 1 ) ;
V_32 = F_24 ( V_32 , V_164 , V_166 , 1 ) ;
F_3 ( V_163 , V_32 ) ;
if ( V_109 & V_132 ) {
V_32 = F_4 ( V_167 + V_97 ) ;
V_32 = F_24 ( V_32 , V_168 , V_169 , 1 ) ;
F_3 ( V_167 + V_97 , V_32 ) ;
}
if ( V_109 & V_134 ) {
V_32 = F_4 ( V_167 + V_98 ) ;
V_32 = F_24 ( V_32 , V_168 , V_169 , 1 ) ;
F_3 ( V_167 + V_98 , V_32 ) ;
}
F_37 ( V_2 , & V_153 ) ;
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 -> V_87 , L_25 ) ;
}
if ( V_109 & ( V_122 | V_170 | V_125 ) ) {
V_154 =
F_24 ( V_154 , V_171 , V_172 , 1 ) ;
V_154 =
F_24 ( V_154 , V_171 , V_173 , 1 ) ;
}
if ( V_109 & V_125 ) {
V_154 =
F_24 ( V_154 , V_171 , V_172 , 1 ) ;
V_155 =
F_24 ( V_155 , V_174 , V_175 , 1 ) ;
}
if ( V_109 & V_132 )
V_155 =
F_24 ( V_155 , V_174 , V_176 , 1 ) ;
if ( V_109 & V_134 )
V_155 =
F_24 ( V_155 , V_174 , V_177 , 1 ) ;
if ( V_109 & V_178 )
V_155 =
F_24 ( V_155 , V_174 , V_179 , 1 ) ;
if ( V_109 & V_127 )
V_154 =
F_24 ( V_154 , V_171 , V_180 , 1 ) ;
if ( V_109 & V_138 )
V_155 =
F_24 ( V_155 , V_174 , V_181 , 1 ) ;
if ( V_109 & V_136 )
V_155 =
F_24 ( V_155 , V_174 , V_182 , 1 ) ;
if ( V_109 & V_140 )
V_155 =
F_24 ( V_155 , V_174 , V_175 , 1 ) ;
if ( V_109 & V_145 )
V_155 =
F_24 ( V_155 , V_174 , V_183 , 1 ) ;
if ( V_109 & V_143 )
V_155 =
F_24 ( V_155 , V_174 , V_184 , 1 ) ;
if ( V_109 & V_185 )
V_155 =
F_24 ( V_155 , V_174 , V_186 , 1 ) ;
if ( V_109 & V_185 )
V_155 =
F_24 ( V_155 , V_174 , V_187 , 1 ) ;
if ( ! ( V_2 -> V_4 & V_33 ) ) {
if ( V_109 & V_150 )
V_155 =
F_24 ( V_155 , V_174 , V_188 , 1 ) ;
}
if ( V_154 ) {
V_32 = F_4 ( V_189 ) ;
V_32 |= V_154 ;
F_33 ( V_2 -> V_87 , L_26 , V_32 ) ;
F_3 ( V_189 , V_32 ) ;
V_32 = F_4 ( V_189 ) ;
F_40 ( 50 ) ;
V_32 &= ~ V_154 ;
F_3 ( V_189 , V_32 ) ;
V_32 = F_4 ( V_189 ) ;
}
if ( V_155 ) {
V_32 = F_4 ( V_190 ) ;
V_32 |= V_155 ;
F_33 ( V_2 -> V_87 , L_27 , V_32 ) ;
F_3 ( V_190 , V_32 ) ;
V_32 = F_4 ( V_190 ) ;
F_40 ( 50 ) ;
V_32 &= ~ V_155 ;
F_3 ( V_190 , V_32 ) ;
V_32 = F_4 ( V_190 ) ;
}
F_40 ( 50 ) ;
F_41 ( V_2 , & V_153 ) ;
F_40 ( 50 ) ;
F_32 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_152 V_153 ;
T_1 V_32 , V_80 ;
F_33 ( V_2 -> V_87 , L_28 ) ;
V_32 = F_4 ( V_158 ) ;
V_32 = F_24 ( V_32 , V_159 , V_160 , 1 ) ;
V_32 = F_24 ( V_32 , V_159 , V_161 , 1 ) ;
V_32 = F_24 ( V_32 , V_159 , V_162 , 1 ) ;
F_3 ( V_158 , V_32 ) ;
V_32 = F_4 ( V_163 ) ;
V_32 = F_24 ( V_32 , V_164 , V_165 , 1 ) ;
V_32 = F_24 ( V_32 , V_164 , V_166 , 1 ) ;
F_3 ( V_163 , V_32 ) ;
F_3 ( V_158 , V_191 |
V_192 | V_193 ) ;
F_3 ( V_163 ,
V_194 | V_195 ) ;
V_32 = F_4 ( V_167 + V_97 ) ;
V_32 = F_24 ( V_32 , V_168 , V_169 , 1 ) ;
F_3 ( V_167 + V_97 , V_32 ) ;
V_32 = F_4 ( V_167 + V_98 ) ;
V_32 = F_24 ( V_32 , V_168 , V_169 , 1 ) ;
F_3 ( V_167 + V_98 , V_32 ) ;
F_40 ( 50 ) ;
F_37 ( V_2 , & V_153 ) ;
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 -> V_87 , L_29 ) ;
}
F_43 ( V_2 -> V_196 ) ;
F_44 ( V_2 ) ;
F_40 ( 100 ) ;
for ( V_80 = 0 ; V_80 < V_2 -> V_197 ; V_80 ++ ) {
if ( F_4 ( V_198 ) != 0xffffffff )
break;
F_40 ( 1 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , bool V_199 )
{
T_1 V_32 = F_4 ( V_200 ) ;
if ( V_199 )
V_32 |= V_201 ;
else
V_32 &= ~ V_201 ;
F_3 ( V_200 , V_32 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_1 V_109 ;
V_109 = F_34 ( V_2 ) ;
if ( V_109 )
F_45 ( V_2 , true ) ;
F_36 ( V_2 , V_109 ) ;
V_109 = F_34 ( V_2 ) ;
if ( V_109 && V_202 )
F_42 ( V_2 ) ;
V_109 = F_34 ( V_2 ) ;
if ( ! V_109 )
F_45 ( V_2 , false ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_203 , T_1 V_204 )
{
int V_5 , V_80 ;
struct V_205 V_206 ;
T_2 V_32 ;
V_5 = F_48 ( V_2 ,
V_207 ,
clock , false , & V_206 ) ;
if ( V_5 )
return V_5 ;
V_32 = F_21 ( V_203 ) ;
V_32 &= ~ ( V_208 |
V_209 ) ;
V_32 |= V_206 . V_210 ;
F_27 ( V_203 , V_32 ) ;
for ( V_80 = 0 ; V_80 < 100 ; V_80 ++ ) {
if ( F_21 ( V_204 ) & V_211 )
break;
F_49 ( 10 ) ;
}
if ( V_80 == 100 )
return - V_212 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_213 , T_1 V_214 )
{
int V_5 ;
V_5 = F_47 ( V_2 , V_213 , V_215 , V_216 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_47 ( V_2 , V_214 , V_217 , V_218 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_219 , T_1 V_220 )
{
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_221 ;
int V_222 ;
if ( V_223 == 0 )
return;
if ( V_2 -> V_4 & V_33 )
return;
V_222 = F_53 ( V_2 -> V_224 , & V_221 ) ;
if ( V_222 != 0 )
return;
if ( ! ( V_221 & ( V_225 | V_226 ) ) )
return;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_227 == 0 )
return;
}
static void F_55 ( struct V_1 * V_2 ,
bool V_228 )
{
T_1 V_32 ;
if ( V_2 -> V_4 & V_33 )
return;
V_32 = F_4 ( V_229 ) ;
if ( V_228 )
V_32 = F_24 ( V_32 , V_230 , V_230 , 1 ) ;
else
V_32 = F_24 ( V_32 , V_230 , V_230 , 0 ) ;
F_3 ( V_229 , V_32 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_231 = V_232 ;
V_2 -> V_233 = F_18 ( V_232 ) ;
break;
case V_25 :
V_2 -> V_231 = V_234 ;
V_2 -> V_233 = F_18 ( V_234 ) ;
break;
case V_27 :
V_2 -> V_231 = V_235 ;
V_2 -> V_233 = F_18 ( V_235 ) ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static T_2 F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 == V_23 )
return ( F_4 ( V_236 ) & V_237 )
>> V_238 ;
else
return ( F_4 ( V_239 ) & V_240 )
>> V_241 ;
}
static int F_58 ( void * V_242 )
{
bool V_243 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_242 ;
if ( V_2 -> V_4 & V_33 ) {
V_2 -> V_244 = & F_9 ;
V_2 -> V_245 = & F_10 ;
} else {
V_2 -> V_244 = & F_7 ;
V_2 -> V_245 = & F_8 ;
}
V_2 -> V_246 = & F_1 ;
V_2 -> V_247 = & F_6 ;
V_2 -> V_248 = & F_11 ;
V_2 -> V_249 = & F_12 ;
V_2 -> V_250 = & F_13 ;
V_2 -> V_251 = & F_14 ;
V_2 -> V_252 = & V_253 ;
if ( F_59 ( V_2 , V_254 ) &&
( V_255 & ( 1 << V_254 ) ) )
V_243 = true ;
V_2 -> V_256 = F_57 ( V_2 ) ;
V_2 -> V_257 = 0xFF ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_258 = false ;
V_2 -> V_259 = 0 ;
V_2 -> V_260 = 0 ;
V_2 -> V_257 = 0x1 ;
if ( V_261 && V_243 )
V_2 -> V_262 . V_263 = true ;
break;
case V_25 :
V_2 -> V_258 = true ;
V_2 -> V_259 = 0 ;
V_2 -> V_260 = 0 ;
V_2 -> V_257 = V_2 -> V_256 + 0x14 ;
if ( V_261 && V_243 )
V_2 -> V_262 . V_263 = true ;
break;
case V_27 :
V_2 -> V_258 = true ;
V_2 -> V_259 = 0 ;
V_2 -> V_260 = V_264 | V_265 ;
V_2 -> V_257 = V_2 -> V_256 + 0x1 ;
if ( V_261 && V_243 )
V_2 -> V_262 . V_263 = true ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static int F_60 ( void * V_242 )
{
return 0 ;
}
static int F_61 ( void * V_242 )
{
return 0 ;
}
static int F_62 ( void * V_242 )
{
struct V_1 * V_2 = (struct V_1 * ) V_242 ;
F_15 ( V_2 ) ;
F_52 ( V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 , true ) ;
return 0 ;
}
static int F_63 ( void * V_242 )
{
struct V_1 * V_2 = (struct V_1 * ) V_242 ;
F_55 ( V_2 , false ) ;
return 0 ;
}
static int F_64 ( void * V_242 )
{
struct V_1 * V_2 = (struct V_1 * ) V_242 ;
return F_63 ( V_2 ) ;
}
static int F_65 ( void * V_242 )
{
struct V_1 * V_2 = (struct V_1 * ) V_242 ;
return F_62 ( V_2 ) ;
}
static bool F_66 ( void * V_242 )
{
return true ;
}
static int F_67 ( void * V_242 )
{
return 0 ;
}
static void F_68 ( void * V_242 )
{
return;
}
static int F_69 ( void * V_242 )
{
return 0 ;
}
static int F_70 ( void * V_242 ,
enum V_266 V_51 )
{
return 0 ;
}
static int F_71 ( void * V_242 ,
enum V_267 V_51 )
{
return 0 ;
}
