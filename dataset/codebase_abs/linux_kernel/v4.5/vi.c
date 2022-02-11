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
static bool F_29 ( struct V_1 * V_2 ,
T_2 * V_75 , T_1 V_76 )
{
T_1 * V_77 ;
unsigned long V_4 ;
T_1 V_78 , V_79 ;
if ( V_75 == NULL )
return false ;
if ( V_76 == 0 )
return false ;
if ( V_2 -> V_4 & V_37 )
return false ;
V_77 = ( T_1 * ) V_75 ;
V_79 = F_30 ( V_76 , 4 ) / 4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , V_80 ) ;
F_3 ( V_12 , 0 ) ;
F_3 ( V_11 , V_81 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ )
V_77 [ V_78 ] = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return true ;
}
static T_3 F_31 ( struct V_1 * V_2 , T_1 V_82 ,
T_1 V_83 , T_1 V_84 )
{
T_3 V_85 ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_82 != 0xffffffff || V_83 != 0xffffffff )
F_32 ( V_2 , V_82 , V_83 ) ;
V_85 = F_4 ( V_84 ) ;
if ( V_82 != 0xffffffff || V_83 != 0xffffffff )
F_32 ( V_2 , 0xffffffff , 0xffffffff ) ;
F_19 ( & V_2 -> V_21 ) ;
return V_85 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_82 ,
T_1 V_83 , T_1 V_84 , T_1 * V_86 )
{
struct V_87 * V_88 = NULL ;
struct V_87 * V_89 ;
T_3 V_90 , V_78 ;
* V_86 = 0 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_88 = V_91 ;
V_90 = F_18 ( V_91 ) ;
break;
case V_25 :
case V_27 :
case V_29 :
case V_31 :
V_88 = V_92 ;
V_90 = F_18 ( V_92 ) ;
break;
default:
return - V_93 ;
}
if ( V_88 ) {
for ( V_78 = 0 ; V_78 < V_90 ; V_78 ++ ) {
V_89 = V_88 + V_78 ;
if ( V_84 != V_89 -> V_84 )
continue;
if ( ! V_89 -> V_94 )
* V_86 = V_89 -> V_95 ?
F_31 ( V_2 , V_82 ,
V_83 , V_84 ) :
F_4 ( V_84 ) ;
return 0 ;
}
}
for ( V_78 = 0 ; V_78 < F_18 ( V_96 ) ; V_78 ++ ) {
if ( V_84 != V_96 [ V_78 ] . V_84 )
continue;
if ( ! V_96 [ V_78 ] . V_94 )
* V_86 = V_96 [ V_78 ] . V_95 ?
F_31 ( V_2 , V_82 ,
V_83 , V_84 ) :
F_4 ( V_84 ) ;
return 0 ;
}
return - V_93 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_97 , L_1 ,
F_4 ( V_98 ) ) ;
F_35 ( V_2 -> V_97 , L_2 ,
F_4 ( V_99 ) ) ;
F_35 ( V_2 -> V_97 , L_3 ,
F_4 ( V_100 ) ) ;
F_35 ( V_2 -> V_97 , L_4 ,
F_4 ( V_101 ) ) ;
F_35 ( V_2 -> V_97 , L_5 ,
F_4 ( V_102 ) ) ;
F_35 ( V_2 -> V_97 , L_6 ,
F_4 ( V_103 ) ) ;
F_35 ( V_2 -> V_97 , L_7 ,
F_4 ( V_104 ) ) ;
F_35 ( V_2 -> V_97 , L_8 ,
F_4 ( V_105 ) ) ;
F_35 ( V_2 -> V_97 , L_9 ,
F_4 ( V_106 + V_107 ) ) ;
if ( V_2 -> V_108 . V_109 > 1 ) {
F_35 ( V_2 -> V_97 , L_10 ,
F_4 ( V_106 + V_110 ) ) ;
}
F_35 ( V_2 -> V_97 , L_11 , F_4 ( V_111 ) ) ;
F_35 ( V_2 -> V_97 , L_12 ,
F_4 ( V_112 ) ) ;
F_35 ( V_2 -> V_97 , L_13 ,
F_4 ( V_113 ) ) ;
F_35 ( V_2 -> V_97 , L_14 ,
F_4 ( V_114 ) ) ;
F_35 ( V_2 -> V_97 , L_15 ,
F_4 ( V_115 ) ) ;
F_35 ( V_2 -> V_97 , L_16 ,
F_4 ( V_116 ) ) ;
F_35 ( V_2 -> V_97 , L_17 , F_4 ( V_117 ) ) ;
F_35 ( V_2 -> V_97 , L_18 , F_4 ( V_118 ) ) ;
F_35 ( V_2 -> V_97 , L_19 ,
F_4 ( V_119 ) ) ;
F_35 ( V_2 -> V_97 , L_20 , F_4 ( V_120 ) ) ;
}
T_1 F_36 ( struct V_1 * V_2 )
{
T_1 V_121 = 0 ;
T_1 V_36 ;
V_36 = F_4 ( V_98 ) ;
if ( V_36 & ( V_122 | V_123 |
V_124 | V_125 |
V_126 | V_127 |
V_128 | V_129 |
V_130 | V_131 |
V_132 | V_133 ) )
V_121 |= V_134 ;
if ( V_36 & ( V_135 | V_136 ) )
V_121 |= V_137 ;
V_36 = F_4 ( V_99 ) ;
if ( V_36 & V_138 )
V_121 |= V_139 ;
if ( V_36 & ( V_140 |
V_141 |
V_142 ) )
V_121 |= V_137 ;
V_36 = F_4 ( V_105 ) ;
if ( V_36 & V_143 )
V_121 |= V_144 ;
if ( V_36 & V_145 )
V_121 |= V_146 ;
V_36 = F_4 ( V_104 ) ;
if ( V_36 & V_147 )
V_121 |= V_148 ;
if ( V_36 & V_149 )
V_121 |= V_150 ;
if ( V_36 & V_151 )
V_121 |= V_152 ;
if ( V_2 -> V_22 != V_23 ) {
if ( V_36 & ( V_153 |
V_154 ) )
V_121 |= V_155 ;
}
if ( V_36 & V_156 )
V_121 |= V_157 ;
if ( V_36 & ( V_158 | V_159 |
V_160 | V_161 ) )
V_121 |= V_162 ;
V_36 = F_4 ( V_106 + V_107 ) ;
if ( ! ( V_36 & V_163 ) )
V_121 |= V_144 ;
if ( V_2 -> V_108 . V_109 > 1 ) {
V_36 = F_4 ( V_106 + V_110 ) ;
if ( ! ( V_36 & V_163 ) )
V_121 |= V_146 ;
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
if ( V_121 & V_162 ) {
F_37 ( L_21 , V_121 ) ;
V_121 &= ~ V_162 ;
}
return V_121 ;
}
static void F_38 ( struct V_1 * V_2 , T_1 V_121 )
{
struct V_164 V_165 ;
T_1 V_166 = 0 , V_167 = 0 ;
T_1 V_36 ;
if ( V_121 == 0 )
return;
F_35 ( V_2 -> V_97 , L_22 , V_121 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 -> V_97 , L_23 ,
F_4 ( V_168 ) ) ;
F_35 ( V_2 -> V_97 , L_24 ,
F_4 ( V_169 ) ) ;
V_36 = F_4 ( V_170 ) ;
V_36 = F_24 ( V_36 , V_171 , V_172 , 1 ) ;
V_36 = F_24 ( V_36 , V_171 , V_173 , 1 ) ;
V_36 = F_24 ( V_36 , V_171 , V_174 , 1 ) ;
F_3 ( V_170 , V_36 ) ;
V_36 = F_4 ( V_175 ) ;
V_36 = F_24 ( V_36 , V_176 , V_177 , 1 ) ;
V_36 = F_24 ( V_36 , V_176 , V_178 , 1 ) ;
F_3 ( V_175 , V_36 ) ;
if ( V_121 & V_144 ) {
V_36 = F_4 ( V_179 + V_107 ) ;
V_36 = F_24 ( V_36 , V_180 , V_181 , 1 ) ;
F_3 ( V_179 + V_107 , V_36 ) ;
}
if ( V_121 & V_146 ) {
V_36 = F_4 ( V_179 + V_110 ) ;
V_36 = F_24 ( V_36 , V_180 , V_181 , 1 ) ;
F_3 ( V_179 + V_110 , V_36 ) ;
}
F_39 ( V_2 , & V_165 ) ;
if ( F_40 ( V_2 ) ) {
F_41 ( V_2 -> V_97 , L_25 ) ;
}
if ( V_121 & ( V_134 | V_182 | V_137 ) ) {
V_166 =
F_24 ( V_166 , V_183 , V_184 , 1 ) ;
V_166 =
F_24 ( V_166 , V_183 , V_185 , 1 ) ;
}
if ( V_121 & V_137 ) {
V_166 =
F_24 ( V_166 , V_183 , V_184 , 1 ) ;
V_167 =
F_24 ( V_167 , V_186 , V_187 , 1 ) ;
}
if ( V_121 & V_144 )
V_167 =
F_24 ( V_167 , V_186 , V_188 , 1 ) ;
if ( V_121 & V_146 )
V_167 =
F_24 ( V_167 , V_186 , V_189 , 1 ) ;
if ( V_121 & V_190 )
V_167 =
F_24 ( V_167 , V_186 , V_191 , 1 ) ;
if ( V_121 & V_139 )
V_166 =
F_24 ( V_166 , V_183 , V_192 , 1 ) ;
if ( V_121 & V_150 )
V_167 =
F_24 ( V_167 , V_186 , V_193 , 1 ) ;
if ( V_121 & V_148 )
V_167 =
F_24 ( V_167 , V_186 , V_194 , 1 ) ;
if ( V_121 & V_152 )
V_167 =
F_24 ( V_167 , V_186 , V_187 , 1 ) ;
if ( V_121 & V_157 )
V_167 =
F_24 ( V_167 , V_186 , V_195 , 1 ) ;
if ( V_121 & V_155 )
V_167 =
F_24 ( V_167 , V_186 , V_196 , 1 ) ;
if ( V_121 & V_197 )
V_167 =
F_24 ( V_167 , V_186 , V_198 , 1 ) ;
if ( V_121 & V_197 )
V_167 =
F_24 ( V_167 , V_186 , V_199 , 1 ) ;
if ( ! ( V_2 -> V_4 & V_37 ) ) {
if ( V_121 & V_162 )
V_167 =
F_24 ( V_167 , V_186 , V_200 , 1 ) ;
}
if ( V_166 ) {
V_36 = F_4 ( V_201 ) ;
V_36 |= V_166 ;
F_35 ( V_2 -> V_97 , L_26 , V_36 ) ;
F_3 ( V_201 , V_36 ) ;
V_36 = F_4 ( V_201 ) ;
F_42 ( 50 ) ;
V_36 &= ~ V_166 ;
F_3 ( V_201 , V_36 ) ;
V_36 = F_4 ( V_201 ) ;
}
if ( V_167 ) {
V_36 = F_4 ( V_202 ) ;
V_36 |= V_167 ;
F_35 ( V_2 -> V_97 , L_27 , V_36 ) ;
F_3 ( V_202 , V_36 ) ;
V_36 = F_4 ( V_202 ) ;
F_42 ( 50 ) ;
V_36 &= ~ V_167 ;
F_3 ( V_202 , V_36 ) ;
V_36 = F_4 ( V_202 ) ;
}
F_42 ( 50 ) ;
F_43 ( V_2 , & V_165 ) ;
F_42 ( 50 ) ;
F_34 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_164 V_165 ;
T_1 V_36 , V_78 ;
F_35 ( V_2 -> V_97 , L_28 ) ;
V_36 = F_4 ( V_170 ) ;
V_36 = F_24 ( V_36 , V_171 , V_172 , 1 ) ;
V_36 = F_24 ( V_36 , V_171 , V_173 , 1 ) ;
V_36 = F_24 ( V_36 , V_171 , V_174 , 1 ) ;
F_3 ( V_170 , V_36 ) ;
V_36 = F_4 ( V_175 ) ;
V_36 = F_24 ( V_36 , V_176 , V_177 , 1 ) ;
V_36 = F_24 ( V_36 , V_176 , V_178 , 1 ) ;
F_3 ( V_175 , V_36 ) ;
F_3 ( V_170 , V_203 |
V_204 | V_205 ) ;
F_3 ( V_175 ,
V_206 | V_207 ) ;
V_36 = F_4 ( V_179 + V_107 ) ;
V_36 = F_24 ( V_36 , V_180 , V_181 , 1 ) ;
F_3 ( V_179 + V_107 , V_36 ) ;
V_36 = F_4 ( V_179 + V_110 ) ;
V_36 = F_24 ( V_36 , V_180 , V_181 , 1 ) ;
F_3 ( V_179 + V_110 , V_36 ) ;
F_42 ( 50 ) ;
F_39 ( V_2 , & V_165 ) ;
if ( F_40 ( V_2 ) ) {
F_41 ( V_2 -> V_97 , L_29 ) ;
}
F_45 ( V_2 -> V_208 ) ;
F_46 ( V_2 ) ;
F_42 ( 100 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_209 ; V_78 ++ ) {
if ( F_4 ( V_210 ) != 0xffffffff )
break;
F_42 ( 1 ) ;
}
}
static void F_47 ( struct V_1 * V_2 , bool V_211 )
{
T_1 V_36 = F_4 ( V_212 ) ;
if ( V_211 )
V_36 |= V_213 ;
else
V_36 &= ~ V_213 ;
F_3 ( V_212 , V_36 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
T_1 V_121 ;
V_121 = F_36 ( V_2 ) ;
if ( V_121 )
F_47 ( V_2 , true ) ;
F_38 ( V_2 , V_121 ) ;
V_121 = F_36 ( V_2 ) ;
if ( V_121 && V_214 )
F_44 ( V_2 ) ;
V_121 = F_36 ( V_2 ) ;
if ( ! V_121 )
F_47 ( V_2 , false ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_215 , T_1 V_216 )
{
int V_5 , V_78 ;
struct V_217 V_218 ;
T_3 V_36 ;
V_5 = F_50 ( V_2 ,
V_219 ,
clock , false , & V_218 ) ;
if ( V_5 )
return V_5 ;
V_36 = F_21 ( V_215 ) ;
V_36 &= ~ ( V_220 |
V_221 ) ;
V_36 |= V_218 . V_222 ;
F_27 ( V_215 , V_36 ) ;
for ( V_78 = 0 ; V_78 < 100 ; V_78 ++ ) {
if ( F_21 ( V_216 ) & V_223 )
break;
F_51 ( 10 ) ;
}
if ( V_78 == 100 )
return - V_224 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , T_1 V_225 , T_1 V_226 )
{
int V_5 ;
V_5 = F_49 ( V_2 , V_225 , V_227 , V_228 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_49 ( V_2 , V_226 , V_229 , V_230 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_231 , T_1 V_232 )
{
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_55 ( V_2 -> V_208 -> V_233 ) )
return;
if ( V_234 == 0 )
return;
if ( V_2 -> V_4 & V_37 )
return;
if ( ! ( V_2 -> V_235 . V_236 & ( V_237 |
V_238 ) ) )
return;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_239 == 0 )
return;
}
static void F_57 ( struct V_1 * V_2 ,
bool V_240 )
{
T_1 V_36 ;
if ( V_2 -> V_4 & V_37 )
return;
V_36 = F_4 ( V_241 ) ;
if ( V_240 )
V_36 = F_24 ( V_36 , V_242 , V_242 , 1 ) ;
else
V_36 = F_24 ( V_36 , V_242 , V_242 , 0 ) ;
F_3 ( V_241 , V_36 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_243 = V_244 ;
V_2 -> V_245 = F_18 ( V_244 ) ;
break;
case V_25 :
V_2 -> V_243 = V_246 ;
V_2 -> V_245 = F_18 ( V_246 ) ;
break;
case V_27 :
V_2 -> V_243 = V_247 ;
V_2 -> V_245 = F_18 ( V_247 ) ;
break;
case V_29 :
case V_31 :
V_2 -> V_243 = V_248 ;
V_2 -> V_245 = F_18 ( V_248 ) ;
break;
default:
return - V_93 ;
}
return 0 ;
}
static T_3 F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_37 )
return ( F_21 ( V_249 ) & V_250 )
>> V_251 ;
else
return ( F_4 ( V_252 ) & V_253 )
>> V_254 ;
}
static int F_60 ( void * V_255 )
{
bool V_256 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_255 ;
if ( V_2 -> V_4 & V_37 ) {
V_2 -> V_257 = & F_9 ;
V_2 -> V_258 = & F_10 ;
} else {
V_2 -> V_257 = & F_7 ;
V_2 -> V_258 = & F_8 ;
}
V_2 -> V_259 = & F_1 ;
V_2 -> V_260 = & F_6 ;
V_2 -> V_261 = & F_11 ;
V_2 -> V_262 = & F_12 ;
V_2 -> V_263 = & F_13 ;
V_2 -> V_264 = & F_14 ;
V_2 -> V_265 = & V_266 ;
if ( F_61 ( V_2 , V_267 ) &&
( V_268 & ( 1 << V_267 ) ) )
V_256 = true ;
V_2 -> V_269 = F_59 ( V_2 ) ;
V_2 -> V_270 = 0xFF ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_271 = false ;
V_2 -> V_272 = 0 ;
V_2 -> V_273 = 0 ;
V_2 -> V_270 = 0x1 ;
break;
case V_25 :
V_2 -> V_271 = true ;
V_2 -> V_272 = 0 ;
V_2 -> V_273 = 0 ;
V_2 -> V_270 = V_2 -> V_269 + 0x3c ;
break;
case V_27 :
V_2 -> V_271 = true ;
V_2 -> V_272 = 0 ;
V_2 -> V_273 = 0 ;
V_2 -> V_270 = V_2 -> V_269 + 0x14 ;
break;
case V_29 :
case V_31 :
V_2 -> V_271 = true ;
V_2 -> V_272 = 0 ;
V_2 -> V_273 = 0 ;
V_2 -> V_270 = V_2 -> V_269 + 0x1 ;
break;
default:
return - V_93 ;
}
if ( V_274 && V_256 )
V_2 -> V_275 . V_276 = true ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_63 ( void * V_255 )
{
return 0 ;
}
static int F_64 ( void * V_255 )
{
return 0 ;
}
static int F_65 ( void * V_255 )
{
struct V_1 * V_2 = (struct V_1 * ) V_255 ;
F_15 ( V_2 ) ;
F_54 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 , true ) ;
return 0 ;
}
static int F_66 ( void * V_255 )
{
struct V_1 * V_2 = (struct V_1 * ) V_255 ;
F_57 ( V_2 , false ) ;
return 0 ;
}
static int F_67 ( void * V_255 )
{
struct V_1 * V_2 = (struct V_1 * ) V_255 ;
return F_66 ( V_2 ) ;
}
static int F_68 ( void * V_255 )
{
struct V_1 * V_2 = (struct V_1 * ) V_255 ;
return F_65 ( V_2 ) ;
}
static bool F_69 ( void * V_255 )
{
return true ;
}
static int F_70 ( void * V_255 )
{
return 0 ;
}
static void F_71 ( void * V_255 )
{
return;
}
static int F_72 ( void * V_255 )
{
return 0 ;
}
static void F_73 ( struct V_1 * V_2 ,
bool V_240 )
{
T_3 V_277 , V_278 ;
V_277 = V_278 = F_74 ( V_279 ) ;
if ( V_240 )
V_278 |= V_280 |
V_281 |
V_282 ;
else
V_278 &= ~ ( V_280 |
V_281 |
V_282 ) ;
if ( V_277 != V_278 )
F_75 ( V_279 , V_278 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
bool V_240 )
{
T_3 V_277 , V_278 ;
V_277 = V_278 = F_4 ( V_283 ) ;
if ( V_240 )
V_278 &= ~ V_284 ;
else
V_278 |= V_284 ;
if ( V_277 != V_278 )
F_3 ( V_283 , V_278 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
bool V_240 )
{
T_3 V_277 , V_278 ;
V_277 = V_278 = F_4 ( V_285 ) ;
if ( V_240 )
V_278 |= V_286 ;
else
V_278 &= ~ V_286 ;
if ( V_277 != V_278 )
F_3 ( V_285 , V_278 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
bool V_240 )
{
T_3 V_277 , V_278 ;
V_277 = V_278 = F_21 ( V_287 ) ;
if ( V_240 )
V_278 &= ~ ( V_288 |
V_289 ) ;
else
V_278 |= V_288 |
V_289 ;
if ( V_277 != V_278 )
F_27 ( V_287 , V_278 ) ;
}
static int F_79 ( void * V_255 ,
enum V_290 V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_255 ;
switch ( V_2 -> V_22 ) {
case V_25 :
F_73 ( V_2 ,
V_55 == V_291 ? true : false ) ;
F_76 ( V_2 ,
V_55 == V_291 ? true : false ) ;
F_77 ( V_2 ,
V_55 == V_291 ? true : false ) ;
F_78 ( V_2 ,
V_55 == V_291 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_80 ( void * V_255 ,
enum V_292 V_55 )
{
return 0 ;
}
