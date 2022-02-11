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
case V_31 :
F_17 ( V_2 ,
V_32 ,
( const T_1 ) F_18 ( V_32 ) ) ;
break;
default:
break;
}
F_19 ( & V_2 -> V_21 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
T_1 V_33 = V_2 -> clock . V_34 . V_35 ;
T_1 V_36 ;
if ( V_2 -> V_4 & V_37 )
return V_33 ;
V_36 = F_21 ( V_38 ) ;
if ( F_22 ( V_36 , V_39 , V_40 ) )
return 1000 ;
V_36 = F_21 ( V_41 ) ;
if ( F_22 ( V_36 , V_42 , V_43 ) )
return V_33 / 4 ;
return V_33 ;
}
void F_23 ( struct V_1 * V_2 ,
T_1 V_44 , T_1 V_45 , T_1 V_46 , T_1 V_47 )
{
T_1 V_48 = 0 ;
V_48 = F_24 ( V_48 , V_49 , V_50 , V_45 ) ;
V_48 = F_24 ( V_48 , V_49 , V_51 , V_44 ) ;
V_48 = F_24 ( V_48 , V_49 , V_52 , V_47 ) ;
V_48 = F_24 ( V_48 , V_49 , V_53 , V_46 ) ;
F_3 ( V_54 , V_48 ) ;
}
static void F_25 ( struct V_1 * V_2 , bool V_55 )
{
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_56 ;
T_1 V_57 = 0 ;
T_1 V_58 = 0 ;
T_1 V_59 = 0 ;
T_1 V_60 ;
bool V_5 ;
V_56 = F_4 ( V_61 ) ;
if ( V_2 -> V_62 . V_63 ) {
V_57 = F_4 ( V_64 ) ;
V_58 = F_4 ( V_65 ) ;
V_59 = F_4 ( V_66 ) ;
}
V_60 = F_21 ( V_67 ) ;
F_3 ( V_61 , ( V_56 & ~ V_68 ) ) ;
if ( V_2 -> V_62 . V_63 ) {
F_3 ( V_64 ,
( V_57 & ~ ( V_69 |
V_70 ) ) ) ;
F_3 ( V_65 ,
( V_58 & ~ ( V_71 |
V_72 ) ) ) ;
F_3 ( V_66 ,
( V_59 & ~ V_73 ) ) ;
}
F_27 ( V_67 , V_60 | V_74 ) ;
V_5 = F_28 ( V_2 ) ;
F_3 ( V_61 , V_56 ) ;
if ( V_2 -> V_62 . V_63 ) {
F_3 ( V_64 , V_57 ) ;
F_3 ( V_65 , V_58 ) ;
F_3 ( V_66 , V_59 ) ;
}
F_27 ( V_67 , V_60 ) ;
return V_5 ;
}
static T_2 F_29 ( struct V_1 * V_2 , T_1 V_75 ,
T_1 V_76 , T_1 V_77 )
{
T_2 V_78 ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_75 != 0xffffffff || V_76 != 0xffffffff )
F_30 ( V_2 , V_75 , V_76 ) ;
V_78 = F_4 ( V_77 ) ;
if ( V_75 != 0xffffffff || V_76 != 0xffffffff )
F_30 ( V_2 , 0xffffffff , 0xffffffff ) ;
F_19 ( & V_2 -> V_21 ) ;
return V_78 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_75 ,
T_1 V_76 , T_1 V_77 , T_1 * V_79 )
{
struct V_80 * V_81 = NULL ;
struct V_80 * V_82 ;
T_2 V_83 , V_84 ;
* V_79 = 0 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_81 = V_85 ;
V_83 = F_18 ( V_85 ) ;
break;
case V_25 :
case V_27 :
case V_29 :
case V_31 :
V_81 = V_86 ;
V_83 = F_18 ( V_86 ) ;
break;
default:
return - V_87 ;
}
if ( V_81 ) {
for ( V_84 = 0 ; V_84 < V_83 ; V_84 ++ ) {
V_82 = V_81 + V_84 ;
if ( V_77 != V_82 -> V_77 )
continue;
if ( ! V_82 -> V_88 )
* V_79 = V_82 -> V_89 ?
F_29 ( V_2 , V_75 ,
V_76 , V_77 ) :
F_4 ( V_77 ) ;
return 0 ;
}
}
for ( V_84 = 0 ; V_84 < F_18 ( V_90 ) ; V_84 ++ ) {
if ( V_77 != V_90 [ V_84 ] . V_77 )
continue;
if ( ! V_90 [ V_84 ] . V_88 )
* V_79 = V_90 [ V_84 ] . V_89 ?
F_29 ( V_2 , V_75 ,
V_76 , V_77 ) :
F_4 ( V_77 ) ;
return 0 ;
}
return - V_87 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_91 , L_1 ,
F_4 ( V_92 ) ) ;
F_33 ( V_2 -> V_91 , L_2 ,
F_4 ( V_93 ) ) ;
F_33 ( V_2 -> V_91 , L_3 ,
F_4 ( V_94 ) ) ;
F_33 ( V_2 -> V_91 , L_4 ,
F_4 ( V_95 ) ) ;
F_33 ( V_2 -> V_91 , L_5 ,
F_4 ( V_96 ) ) ;
F_33 ( V_2 -> V_91 , L_6 ,
F_4 ( V_97 ) ) ;
F_33 ( V_2 -> V_91 , L_7 ,
F_4 ( V_98 ) ) ;
F_33 ( V_2 -> V_91 , L_8 ,
F_4 ( V_99 ) ) ;
F_33 ( V_2 -> V_91 , L_9 ,
F_4 ( V_100 + V_101 ) ) ;
if ( V_2 -> V_102 . V_103 > 1 ) {
F_33 ( V_2 -> V_91 , L_10 ,
F_4 ( V_100 + V_104 ) ) ;
}
F_33 ( V_2 -> V_91 , L_11 , F_4 ( V_105 ) ) ;
F_33 ( V_2 -> V_91 , L_12 ,
F_4 ( V_106 ) ) ;
F_33 ( V_2 -> V_91 , L_13 ,
F_4 ( V_107 ) ) ;
F_33 ( V_2 -> V_91 , L_14 ,
F_4 ( V_108 ) ) ;
F_33 ( V_2 -> V_91 , L_15 ,
F_4 ( V_109 ) ) ;
F_33 ( V_2 -> V_91 , L_16 ,
F_4 ( V_110 ) ) ;
F_33 ( V_2 -> V_91 , L_17 , F_4 ( V_111 ) ) ;
F_33 ( V_2 -> V_91 , L_18 , F_4 ( V_112 ) ) ;
F_33 ( V_2 -> V_91 , L_19 ,
F_4 ( V_113 ) ) ;
F_33 ( V_2 -> V_91 , L_20 , F_4 ( V_114 ) ) ;
}
T_1 F_34 ( struct V_1 * V_2 )
{
T_1 V_115 = 0 ;
T_1 V_36 ;
V_36 = F_4 ( V_92 ) ;
if ( V_36 & ( V_116 | V_117 |
V_118 | V_119 |
V_120 | V_121 |
V_122 | V_123 |
V_124 | V_125 |
V_126 | V_127 ) )
V_115 |= V_128 ;
if ( V_36 & ( V_129 | V_130 ) )
V_115 |= V_131 ;
V_36 = F_4 ( V_93 ) ;
if ( V_36 & V_132 )
V_115 |= V_133 ;
if ( V_36 & ( V_134 |
V_135 |
V_136 ) )
V_115 |= V_131 ;
V_36 = F_4 ( V_99 ) ;
if ( V_36 & V_137 )
V_115 |= V_138 ;
if ( V_36 & V_139 )
V_115 |= V_140 ;
V_36 = F_4 ( V_98 ) ;
if ( V_36 & V_141 )
V_115 |= V_142 ;
if ( V_36 & V_143 )
V_115 |= V_144 ;
if ( V_36 & V_145 )
V_115 |= V_146 ;
if ( V_2 -> V_22 != V_23 ) {
if ( V_36 & ( V_147 |
V_148 ) )
V_115 |= V_149 ;
}
if ( V_36 & V_150 )
V_115 |= V_151 ;
if ( V_36 & ( V_152 | V_153 |
V_154 | V_155 ) )
V_115 |= V_156 ;
V_36 = F_4 ( V_100 + V_101 ) ;
if ( ! ( V_36 & V_157 ) )
V_115 |= V_138 ;
if ( V_2 -> V_102 . V_103 > 1 ) {
V_36 = F_4 ( V_100 + V_104 ) ;
if ( ! ( V_36 & V_157 ) )
V_115 |= V_140 ;
}
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
if ( V_115 & V_156 ) {
F_35 ( L_21 , V_115 ) ;
V_115 &= ~ V_156 ;
}
return V_115 ;
}
static void F_36 ( struct V_1 * V_2 , T_1 V_115 )
{
struct V_158 V_159 ;
T_1 V_160 = 0 , V_161 = 0 ;
T_1 V_36 ;
if ( V_115 == 0 )
return;
F_33 ( V_2 -> V_91 , L_22 , V_115 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_91 , L_23 ,
F_4 ( V_162 ) ) ;
F_33 ( V_2 -> V_91 , L_24 ,
F_4 ( V_163 ) ) ;
V_36 = F_4 ( V_164 ) ;
V_36 = F_24 ( V_36 , V_165 , V_166 , 1 ) ;
V_36 = F_24 ( V_36 , V_165 , V_167 , 1 ) ;
V_36 = F_24 ( V_36 , V_165 , V_168 , 1 ) ;
F_3 ( V_164 , V_36 ) ;
V_36 = F_4 ( V_169 ) ;
V_36 = F_24 ( V_36 , V_170 , V_171 , 1 ) ;
V_36 = F_24 ( V_36 , V_170 , V_172 , 1 ) ;
F_3 ( V_169 , V_36 ) ;
if ( V_115 & V_138 ) {
V_36 = F_4 ( V_173 + V_101 ) ;
V_36 = F_24 ( V_36 , V_174 , V_175 , 1 ) ;
F_3 ( V_173 + V_101 , V_36 ) ;
}
if ( V_115 & V_140 ) {
V_36 = F_4 ( V_173 + V_104 ) ;
V_36 = F_24 ( V_36 , V_174 , V_175 , 1 ) ;
F_3 ( V_173 + V_104 , V_36 ) ;
}
F_37 ( V_2 , & V_159 ) ;
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 -> V_91 , L_25 ) ;
}
if ( V_115 & ( V_128 | V_176 | V_131 ) ) {
V_160 =
F_24 ( V_160 , V_177 , V_178 , 1 ) ;
V_160 =
F_24 ( V_160 , V_177 , V_179 , 1 ) ;
}
if ( V_115 & V_131 ) {
V_160 =
F_24 ( V_160 , V_177 , V_178 , 1 ) ;
V_161 =
F_24 ( V_161 , V_180 , V_181 , 1 ) ;
}
if ( V_115 & V_138 )
V_161 =
F_24 ( V_161 , V_180 , V_182 , 1 ) ;
if ( V_115 & V_140 )
V_161 =
F_24 ( V_161 , V_180 , V_183 , 1 ) ;
if ( V_115 & V_184 )
V_161 =
F_24 ( V_161 , V_180 , V_185 , 1 ) ;
if ( V_115 & V_133 )
V_160 =
F_24 ( V_160 , V_177 , V_186 , 1 ) ;
if ( V_115 & V_144 )
V_161 =
F_24 ( V_161 , V_180 , V_187 , 1 ) ;
if ( V_115 & V_142 )
V_161 =
F_24 ( V_161 , V_180 , V_188 , 1 ) ;
if ( V_115 & V_146 )
V_161 =
F_24 ( V_161 , V_180 , V_181 , 1 ) ;
if ( V_115 & V_151 )
V_161 =
F_24 ( V_161 , V_180 , V_189 , 1 ) ;
if ( V_115 & V_149 )
V_161 =
F_24 ( V_161 , V_180 , V_190 , 1 ) ;
if ( V_115 & V_191 )
V_161 =
F_24 ( V_161 , V_180 , V_192 , 1 ) ;
if ( V_115 & V_191 )
V_161 =
F_24 ( V_161 , V_180 , V_193 , 1 ) ;
if ( ! ( V_2 -> V_4 & V_37 ) ) {
if ( V_115 & V_156 )
V_161 =
F_24 ( V_161 , V_180 , V_194 , 1 ) ;
}
if ( V_160 ) {
V_36 = F_4 ( V_195 ) ;
V_36 |= V_160 ;
F_33 ( V_2 -> V_91 , L_26 , V_36 ) ;
F_3 ( V_195 , V_36 ) ;
V_36 = F_4 ( V_195 ) ;
F_40 ( 50 ) ;
V_36 &= ~ V_160 ;
F_3 ( V_195 , V_36 ) ;
V_36 = F_4 ( V_195 ) ;
}
if ( V_161 ) {
V_36 = F_4 ( V_196 ) ;
V_36 |= V_161 ;
F_33 ( V_2 -> V_91 , L_27 , V_36 ) ;
F_3 ( V_196 , V_36 ) ;
V_36 = F_4 ( V_196 ) ;
F_40 ( 50 ) ;
V_36 &= ~ V_161 ;
F_3 ( V_196 , V_36 ) ;
V_36 = F_4 ( V_196 ) ;
}
F_40 ( 50 ) ;
F_41 ( V_2 , & V_159 ) ;
F_40 ( 50 ) ;
F_32 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_158 V_159 ;
T_1 V_36 , V_84 ;
F_33 ( V_2 -> V_91 , L_28 ) ;
V_36 = F_4 ( V_164 ) ;
V_36 = F_24 ( V_36 , V_165 , V_166 , 1 ) ;
V_36 = F_24 ( V_36 , V_165 , V_167 , 1 ) ;
V_36 = F_24 ( V_36 , V_165 , V_168 , 1 ) ;
F_3 ( V_164 , V_36 ) ;
V_36 = F_4 ( V_169 ) ;
V_36 = F_24 ( V_36 , V_170 , V_171 , 1 ) ;
V_36 = F_24 ( V_36 , V_170 , V_172 , 1 ) ;
F_3 ( V_169 , V_36 ) ;
F_3 ( V_164 , V_197 |
V_198 | V_199 ) ;
F_3 ( V_169 ,
V_200 | V_201 ) ;
V_36 = F_4 ( V_173 + V_101 ) ;
V_36 = F_24 ( V_36 , V_174 , V_175 , 1 ) ;
F_3 ( V_173 + V_101 , V_36 ) ;
V_36 = F_4 ( V_173 + V_104 ) ;
V_36 = F_24 ( V_36 , V_174 , V_175 , 1 ) ;
F_3 ( V_173 + V_104 , V_36 ) ;
F_40 ( 50 ) ;
F_37 ( V_2 , & V_159 ) ;
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 -> V_91 , L_29 ) ;
}
F_43 ( V_2 -> V_202 ) ;
F_44 ( V_2 ) ;
F_40 ( 100 ) ;
for ( V_84 = 0 ; V_84 < V_2 -> V_203 ; V_84 ++ ) {
if ( F_4 ( V_204 ) != 0xffffffff )
break;
F_40 ( 1 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , bool V_205 )
{
T_1 V_36 = F_4 ( V_206 ) ;
if ( V_205 )
V_36 |= V_207 ;
else
V_36 &= ~ V_207 ;
F_3 ( V_206 , V_36 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_1 V_115 ;
V_115 = F_34 ( V_2 ) ;
if ( V_115 )
F_45 ( V_2 , true ) ;
F_36 ( V_2 , V_115 ) ;
V_115 = F_34 ( V_2 ) ;
if ( V_115 && V_208 )
F_42 ( V_2 ) ;
V_115 = F_34 ( V_2 ) ;
if ( ! V_115 )
F_45 ( V_2 , false ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_209 , T_1 V_210 )
{
int V_5 , V_84 ;
struct V_211 V_212 ;
T_2 V_36 ;
V_5 = F_48 ( V_2 ,
V_213 ,
clock , false , & V_212 ) ;
if ( V_5 )
return V_5 ;
V_36 = F_21 ( V_209 ) ;
V_36 &= ~ ( V_214 |
V_215 ) ;
V_36 |= V_212 . V_216 ;
F_27 ( V_209 , V_36 ) ;
for ( V_84 = 0 ; V_84 < 100 ; V_84 ++ ) {
if ( F_21 ( V_210 ) & V_217 )
break;
F_49 ( 10 ) ;
}
if ( V_84 == 100 )
return - V_218 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_219 , T_1 V_220 )
{
int V_5 ;
V_5 = F_47 ( V_2 , V_219 , V_221 , V_222 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_47 ( V_2 , V_220 , V_223 , V_224 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_225 , T_1 V_226 )
{
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_227 ;
int V_228 ;
if ( F_53 ( V_2 -> V_202 -> V_229 ) )
return;
if ( V_230 == 0 )
return;
if ( V_2 -> V_4 & V_37 )
return;
V_228 = F_54 ( V_2 -> V_231 , & V_227 ) ;
if ( V_228 != 0 )
return;
if ( ! ( V_227 & ( V_232 | V_233 ) ) )
return;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_234 == 0 )
return;
}
static void F_56 ( struct V_1 * V_2 ,
bool V_235 )
{
T_1 V_36 ;
if ( V_2 -> V_4 & V_37 )
return;
V_36 = F_4 ( V_236 ) ;
if ( V_235 )
V_36 = F_24 ( V_36 , V_237 , V_237 , 1 ) ;
else
V_36 = F_24 ( V_36 , V_237 , V_237 , 0 ) ;
F_3 ( V_236 , V_36 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_238 = V_239 ;
V_2 -> V_240 = F_18 ( V_239 ) ;
break;
case V_25 :
V_2 -> V_238 = V_241 ;
V_2 -> V_240 = F_18 ( V_241 ) ;
break;
case V_27 :
V_2 -> V_238 = V_242 ;
V_2 -> V_240 = F_18 ( V_242 ) ;
break;
case V_29 :
case V_31 :
V_2 -> V_238 = V_243 ;
V_2 -> V_240 = F_18 ( V_243 ) ;
break;
default:
return - V_87 ;
}
return 0 ;
}
static T_2 F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 == V_23 )
return ( F_4 ( V_244 ) & V_245 )
>> V_246 ;
else if ( V_2 -> V_4 & V_37 )
return ( F_21 ( V_247 ) & V_248 )
>> V_249 ;
else
return ( F_4 ( V_250 ) & V_251 )
>> V_252 ;
}
static int F_59 ( void * V_253 )
{
bool V_254 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_253 ;
if ( V_2 -> V_4 & V_37 ) {
V_2 -> V_255 = & F_9 ;
V_2 -> V_256 = & F_10 ;
} else {
V_2 -> V_255 = & F_7 ;
V_2 -> V_256 = & F_8 ;
}
V_2 -> V_257 = & F_1 ;
V_2 -> V_258 = & F_6 ;
V_2 -> V_259 = & F_11 ;
V_2 -> V_260 = & F_12 ;
V_2 -> V_261 = & F_13 ;
V_2 -> V_262 = & F_14 ;
V_2 -> V_263 = & V_264 ;
if ( F_60 ( V_2 , V_265 ) &&
( V_266 & ( 1 << V_265 ) ) )
V_254 = true ;
V_2 -> V_267 = F_58 ( V_2 ) ;
V_2 -> V_268 = 0xFF ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_269 = false ;
V_2 -> V_270 = 0 ;
V_2 -> V_271 = 0 ;
V_2 -> V_268 = 0x1 ;
break;
case V_25 :
V_2 -> V_269 = true ;
V_2 -> V_270 = 0 ;
V_2 -> V_271 = 0 ;
V_2 -> V_268 = V_2 -> V_267 + 0x3c ;
break;
case V_27 :
V_2 -> V_269 = true ;
V_2 -> V_270 = 0 ;
V_2 -> V_271 = 0 ;
V_2 -> V_268 = V_2 -> V_267 + 0x14 ;
break;
case V_29 :
case V_31 :
V_2 -> V_269 = true ;
V_2 -> V_270 = 0 ;
V_2 -> V_271 = V_272 ;
V_2 -> V_268 = V_2 -> V_267 + 0x1 ;
break;
default:
return - V_87 ;
}
if ( V_273 && V_254 )
V_2 -> V_274 . V_275 = true ;
return 0 ;
}
static int F_61 ( void * V_253 )
{
return 0 ;
}
static int F_62 ( void * V_253 )
{
return 0 ;
}
static int F_63 ( void * V_253 )
{
struct V_1 * V_2 = (struct V_1 * ) V_253 ;
F_15 ( V_2 ) ;
F_52 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 , true ) ;
return 0 ;
}
static int F_64 ( void * V_253 )
{
struct V_1 * V_2 = (struct V_1 * ) V_253 ;
F_56 ( V_2 , false ) ;
return 0 ;
}
static int F_65 ( void * V_253 )
{
struct V_1 * V_2 = (struct V_1 * ) V_253 ;
return F_64 ( V_2 ) ;
}
static int F_66 ( void * V_253 )
{
struct V_1 * V_2 = (struct V_1 * ) V_253 ;
return F_63 ( V_2 ) ;
}
static bool F_67 ( void * V_253 )
{
return true ;
}
static int F_68 ( void * V_253 )
{
return 0 ;
}
static void F_69 ( void * V_253 )
{
return;
}
static int F_70 ( void * V_253 )
{
return 0 ;
}
static int F_71 ( void * V_253 ,
enum V_276 V_55 )
{
return 0 ;
}
static int F_72 ( void * V_253 ,
enum V_277 V_55 )
{
return 0 ;
}
