static bool F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( F_2 ( V_4 + V_5 [ V_3 ] ) & V_6 )
return true ;
else
return false ;
}
static bool F_3 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_7 , V_8 ;
V_7 = F_2 ( V_9 + V_5 [ V_3 ] ) ;
V_8 = F_2 ( V_9 + V_5 [ V_3 ] ) ;
if ( V_7 != V_8 )
return true ;
else
return false ;
}
void F_4 ( struct V_1 * V_2 , int V_3 )
{
unsigned V_10 = 0 ;
if ( V_3 >= V_2 -> V_11 )
return;
if ( ! ( F_2 ( V_12 + V_5 [ V_3 ] ) & V_13 ) )
return;
while ( F_1 ( V_2 , V_3 ) ) {
if ( V_10 ++ % 100 == 0 ) {
if ( ! F_3 ( V_2 , V_3 ) )
break;
}
}
while ( ! F_1 ( V_2 , V_3 ) ) {
if ( V_10 ++ % 100 == 0 ) {
if ( ! F_3 ( V_2 , V_3 ) )
break;
}
}
}
void F_5 ( struct V_1 * V_2 , int V_14 , T_2 V_15 , bool V_16 )
{
struct V_17 * V_17 = V_2 -> V_18 . V_19 [ V_14 ] ;
T_1 V_20 = F_2 ( V_21 + V_17 -> V_22 ) ;
int V_10 ;
V_20 |= V_23 ;
F_6 ( V_21 + V_17 -> V_22 , V_20 ) ;
F_6 ( V_24 + V_17 -> V_22 ,
V_16 ? V_25 : 0 ) ;
F_6 ( V_26 + V_17 -> V_22 ,
( T_1 ) V_15 ) ;
F_6 ( V_27 + V_17 -> V_22 ,
( T_1 ) V_15 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ ) {
if ( F_2 ( V_21 + V_17 -> V_22 ) & V_29 )
break;
F_7 ( 1 ) ;
}
F_8 ( L_1 ) ;
V_20 &= ~ V_23 ;
F_6 ( V_21 + V_17 -> V_22 , V_20 ) ;
}
bool F_9 ( struct V_1 * V_2 , int V_14 )
{
struct V_17 * V_17 = V_2 -> V_18 . V_19 [ V_14 ] ;
return ! ! ( F_2 ( V_21 + V_17 -> V_22 ) &
V_29 ) ;
}
void F_10 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_34 ;
struct V_35 * V_35 = F_11 ( V_31 ) ;
struct V_36 * V_37 = F_12 ( V_31 ) ;
int V_38 = 0 ;
T_1 V_20 = 0 ;
enum V_39 V_40 = V_41 ;
if ( V_37 ) {
struct V_42 * V_42 = F_13 ( V_37 ) ;
V_38 = F_14 ( V_37 ) ;
V_40 = V_42 -> V_40 ;
}
if ( V_35 -> V_43 & V_44 )
return;
if ( V_38 == 0 )
return;
switch ( V_38 ) {
case 6 :
if ( V_40 == V_45 )
V_20 |= V_46 ;
else
V_20 |= V_47 ;
break;
case 8 :
if ( V_40 == V_45 )
V_20 |= ( V_46 |
V_48 ) ;
else
V_20 |= ( V_47 |
V_49 ) ;
break;
case 10 :
default:
break;
}
switch ( V_35 -> V_50 ) {
case V_51 :
F_6 ( V_52 , V_20 ) ;
break;
case V_53 :
F_6 ( V_54 , V_20 ) ;
break;
case V_55 :
F_6 ( V_56 , V_20 ) ;
break;
case V_57 :
F_6 ( V_58 , V_20 ) ;
break;
default:
break;
}
}
void F_15 ( struct V_1 * V_2 )
{
int V_59 = V_2 -> V_60 . V_61 ;
struct V_62 * V_63 = & V_2 -> V_60 . V_64 [ V_59 ] ;
struct V_65 * V_66 = & V_63 -> V_67 [ 0 ] . V_66 ;
T_1 V_20 , V_68 , V_69 ;
T_1 V_70 , V_71 ;
if ( ( V_66 -> type == V_72 ) && ( V_66 -> V_73 . V_74 ) ) {
if ( V_63 -> V_75 & V_76 ) {
V_20 = F_2 ( V_66 -> V_73 . V_77 ) ;
if ( V_66 -> V_78 )
V_20 |= V_66 -> V_73 . V_79 ;
else
V_20 &= ~ ( V_66 -> V_73 . V_79 ) ;
F_6 ( V_66 -> V_73 . V_77 , V_20 ) ;
if ( V_66 -> V_80 )
F_7 ( V_66 -> V_80 ) ;
} else {
V_20 = F_2 ( V_66 -> V_73 . V_77 ) ;
if ( V_66 -> V_78 )
V_20 &= ~ V_66 -> V_73 . V_79 ;
else
V_20 |= V_66 -> V_73 . V_79 ;
F_6 ( V_66 -> V_73 . V_77 , V_20 ) ;
if ( V_66 -> V_80 )
F_7 ( V_66 -> V_80 ) ;
}
} else if ( V_66 -> type == V_81 )
F_16 ( V_2 , V_66 -> V_82 , V_83 ) ;
V_68 = F_17 ( V_84 ) ;
V_68 &= ~ F_18 ( 0xf ) ;
V_68 &= ~ F_19 ( 0xf ) ;
if ( V_63 -> V_75 & V_85 ) {
if ( V_63 -> V_75 & V_86 ) {
V_68 |= F_18 ( 2 ) ;
V_68 |= F_19 ( 2 ) ;
} else if ( V_63 -> V_75 & V_87 ) {
V_68 |= F_18 ( 4 ) ;
V_68 |= F_19 ( 4 ) ;
}
} else {
V_68 |= F_18 ( 1 ) ;
V_68 |= F_19 ( 1 ) ;
}
F_20 ( V_84 , V_68 ) ;
V_69 = F_17 ( V_88 ) ;
if ( V_63 -> V_75 & V_89 ) {
V_69 |= V_90 ;
if ( V_66 -> V_80 ) {
V_69 |= V_91 ;
V_69 |= F_21 ( V_66 -> V_80 ) ;
} else
V_69 &= ~ V_91 ;
} else
V_69 &= ~ V_90 ;
F_20 ( V_88 , V_69 ) ;
V_70 = F_17 ( V_92 ) ;
if ( V_63 -> V_75 & V_93 )
V_70 &= ~ V_94 ;
else
V_70 |= V_94 ;
F_20 ( V_92 , V_70 ) ;
#if 0
mc_host_dyn_cntl = RREG32_PLL(MC_HOST_DYN_CNTL);
if (ps->misc & ATOM_PM_MISCINFO_DYNAMIC_MC_HOST_BLOCK_EN)
mc_host_dyn_cntl &= ~MC_HOST_FORCEON;
else
mc_host_dyn_cntl |= MC_HOST_FORCEON;
WREG32_PLL(MC_HOST_DYN_CNTL, mc_host_dyn_cntl);
#endif
V_71 = F_17 ( V_95 ) ;
if ( V_63 -> V_75 & V_96 )
V_71 |= V_97 ;
else
V_71 &= ~ V_97 ;
F_20 ( V_95 , V_71 ) ;
if ( ( V_2 -> V_98 & V_99 ) &&
! ( V_2 -> V_98 & V_100 ) &&
V_2 -> V_101 -> V_60 . V_102 &&
( V_63 -> V_103 !=
V_2 -> V_60 . V_64 [ V_2 -> V_60 . V_104 ] . V_103 ) ) {
F_22 ( V_2 ,
V_63 -> V_103 ) ;
F_8 ( L_2 , V_63 -> V_103 ) ;
}
}
void F_23 ( struct V_1 * V_2 )
{
struct V_32 * V_105 = V_2 -> V_105 ;
struct V_106 * V_3 ;
struct V_17 * V_17 ;
T_1 V_20 ;
F_24 (crtc, &ddev->mode_config.crtc_list, head) {
V_17 = F_25 ( V_3 ) ;
if ( V_17 -> V_107 ) {
V_20 = F_2 ( V_12 + V_17 -> V_22 ) ;
V_20 |= V_108 ;
F_6 ( V_12 + V_17 -> V_22 , V_20 ) ;
}
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_32 * V_105 = V_2 -> V_105 ;
struct V_106 * V_3 ;
struct V_17 * V_17 ;
T_1 V_20 ;
F_24 (crtc, &ddev->mode_config.crtc_list, head) {
V_17 = F_25 ( V_3 ) ;
if ( V_17 -> V_107 ) {
V_20 = F_2 ( V_12 + V_17 -> V_22 ) ;
V_20 &= ~ V_108 ;
F_6 ( V_12 + V_17 -> V_22 , V_20 ) ;
}
}
}
bool F_27 ( struct V_1 * V_2 , enum V_109 V_110 )
{
T_1 V_20 ;
bool V_111 = false ;
switch ( V_110 ) {
case V_112 :
V_20 = F_2 ( V_113 ) ;
if ( F_28 ( V_20 ) )
V_111 = true ;
break;
case V_114 :
V_20 = F_2 ( V_115 ) ;
if ( F_29 ( V_20 ) )
V_111 = true ;
break;
default:
break;
}
return V_111 ;
}
void F_30 ( struct V_1 * V_2 ,
enum V_109 V_110 )
{
T_1 V_20 ;
bool V_111 = F_27 ( V_2 , V_110 ) ;
switch ( V_110 ) {
case V_112 :
V_20 = F_2 ( V_116 ) ;
if ( V_111 )
V_20 &= ~ F_31 ( 1 ) ;
else
V_20 |= F_31 ( 1 ) ;
F_6 ( V_116 , V_20 ) ;
break;
case V_114 :
V_20 = F_2 ( V_117 ) ;
if ( V_111 )
V_20 &= ~ F_32 ( 1 ) ;
else
V_20 |= F_32 ( 1 ) ;
F_6 ( V_117 , V_20 ) ;
break;
default:
break;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_105 ;
struct V_36 * V_37 ;
unsigned V_118 = 0 ;
F_24 (connector, &dev->mode_config.connector_list, head) {
struct V_42 * V_42 = F_13 ( V_37 ) ;
switch ( V_42 -> V_110 . V_110 ) {
case V_112 :
F_6 ( V_119 ,
F_34 ( 1 ) ) ;
break;
case V_114 :
F_6 ( V_120 ,
F_35 ( 1 ) ) ;
break;
default:
break;
}
if ( V_42 -> V_110 . V_110 != V_121 )
V_118 |= 1 << V_42 -> V_110 . V_110 ;
F_36 ( V_2 , V_42 -> V_110 . V_110 ) ;
}
F_37 ( V_2 , V_118 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_105 ;
struct V_36 * V_37 ;
unsigned V_122 = 0 ;
F_24 (connector, &dev->mode_config.connector_list, head) {
struct V_42 * V_42 = F_13 ( V_37 ) ;
switch ( V_42 -> V_110 . V_110 ) {
case V_112 :
F_6 ( V_119 ,
F_34 ( 0 ) ) ;
break;
case V_114 :
F_6 ( V_120 ,
F_35 ( 0 ) ) ;
break;
default:
break;
}
if ( V_42 -> V_110 . V_110 != V_121 )
V_122 |= 1 << V_42 -> V_110 . V_110 ;
}
F_39 ( V_2 , V_122 ) ;
}
int F_40 ( struct V_1 * V_2 , bool V_123 )
{
struct V_124 V_125 ;
T_1 V_126 , V_20 ;
int V_127 = 0 ;
V_126 = F_2 ( V_128 ) ;
if ( ! F_41 ( V_126 ) ) {
return 0 ;
}
F_42 ( V_2 , & V_125 ) ;
V_126 = F_2 ( V_128 ) ;
F_43 ( V_2 -> V_33 , L_3 , V_129 , __LINE__ , V_126 ) ;
F_6 ( V_130 , 0 ) ;
V_20 = F_2 ( V_131 ) ;
F_6 ( V_131 , V_20 | V_132 ) ;
F_6 ( V_133 , 0 ) ;
F_6 ( V_134 , 0 ) ;
F_6 ( V_131 , V_20 ) ;
F_44 ( V_2 -> V_135 ) ;
F_45 ( V_2 -> V_135 ) ;
F_46 ( 1 ) ;
F_6 ( V_136 , F_47 ( 1 ) |
F_48 ( 1 ) ) ;
F_2 ( V_136 ) ;
F_46 ( 500 ) ;
F_6 ( V_136 , 0 ) ;
F_46 ( 1 ) ;
V_126 = F_2 ( V_128 ) ;
F_43 ( V_2 -> V_33 , L_3 , V_129 , __LINE__ , V_126 ) ;
F_6 ( V_136 , F_49 ( 1 ) ) ;
F_2 ( V_136 ) ;
F_46 ( 500 ) ;
F_6 ( V_136 , 0 ) ;
F_46 ( 1 ) ;
V_126 = F_2 ( V_128 ) ;
F_43 ( V_2 -> V_33 , L_3 , V_129 , __LINE__ , V_126 ) ;
F_6 ( V_136 , F_50 ( 1 ) ) ;
F_2 ( V_136 ) ;
F_46 ( 500 ) ;
F_6 ( V_136 , 0 ) ;
F_46 ( 1 ) ;
V_126 = F_2 ( V_128 ) ;
F_43 ( V_2 -> V_33 , L_3 , V_129 , __LINE__ , V_126 ) ;
F_51 ( V_2 -> V_135 ) ;
if ( F_52 ( V_126 ) || F_53 ( V_126 ) ) {
F_54 ( V_2 -> V_33 , L_4 ) ;
V_127 = - 1 ;
} else
F_43 ( V_2 -> V_33 , L_5 ) ;
F_55 ( V_2 , & V_125 ) ;
return V_127 ;
}
void F_56 ( struct V_1 * V_2 )
{
T_3 V_20 ;
V_20 = F_57 ( V_137 ) ;
V_20 &= V_138 & V_139 ;
F_58 ( V_137 , V_20 ) ;
V_20 = F_57 ( V_137 ) ;
V_20 |= F_59 ( 1 ) | F_60 ( 1 ) ;
F_58 ( V_137 , V_20 ) ;
V_20 = F_57 ( V_137 ) ;
V_20 &= V_138 & V_139 ;
F_58 ( V_137 , V_20 ) ;
V_20 = F_57 ( V_137 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_140 ;
if ( V_2 -> V_141 . V_142 ) {
F_62 ( 1 , L_6 ) ;
return 0 ;
}
V_140 = F_63 ( V_2 ) ;
if ( V_140 ) {
return V_140 ;
}
V_2 -> V_141 . V_143 = V_2 -> V_141 . V_144 * 8 ;
return F_64 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
T_1 V_20 ;
int V_140 , V_10 ;
if ( V_2 -> V_141 . V_142 == NULL ) {
F_54 ( V_2 -> V_33 , L_7 ) ;
return - V_145 ;
}
V_140 = F_66 ( V_2 ) ;
if ( V_140 )
return V_140 ;
V_20 = F_2 ( V_146 ) & ~ V_147 ;
F_6 ( V_146 , V_20 ) ;
F_58 ( V_137 ,
( F_67 ( 6 ) |
F_68 ( 6 ) ) ) ;
for ( V_10 = 0 ; V_10 < 19 ; V_10 ++ ) {
F_58 ( V_148 + V_10 ,
F_69 ( 1 ) |
F_70 (
V_149 ) |
F_71 (
V_150 ) |
F_72 ( 3 ) |
F_73 ( 1 ) |
F_74 ( 3 ) ) ;
}
F_58 ( V_151 ,
F_75 ( 1 ) |
F_76 ( V_152 ) ) ;
for ( V_10 = 1 ; V_10 < 8 ; V_10 ++ )
F_58 ( V_151 + V_10 , 0 ) ;
F_58 ( V_153 ,
V_2 -> V_141 . V_154 ) ;
F_58 ( V_155 , V_2 -> V_156 . V_157 ) ;
F_58 ( V_158 , V_2 -> V_156 . V_159 ) ;
F_58 ( V_160 , 0 ) ;
F_58 ( V_161 , V_2 -> V_156 . V_162 ) ;
F_58 ( V_163 , V_2 -> V_156 . V_164 ) ;
V_20 = F_57 ( V_137 ) ;
F_58 ( V_137 , ( V_20 | F_77 ( 1 ) ) ) ;
V_20 = F_57 ( V_165 ) ;
F_58 ( V_165 , ( V_20 | F_78 ( 1 ) ) ) ;
F_56 ( V_2 ) ;
F_79 ( L_8 ,
( unsigned ) ( V_2 -> V_156 . V_166 >> 20 ) ,
( unsigned long long ) V_2 -> V_141 . V_154 ) ;
V_2 -> V_141 . V_167 = true ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
T_1 V_20 ;
F_58 ( V_137 , 0 ) ;
V_20 = F_57 ( V_165 ) ;
F_58 ( V_165 , V_20 & V_168 ) ;
F_81 ( V_2 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_83 ( V_2 ) ;
F_80 ( V_2 ) ;
F_84 ( V_2 ) ;
}
T_4 F_85 ( T_4 V_169 , T_3 V_98 )
{
V_169 = V_169 & 0xFFFFFFFFFFFFF000ULL ;
V_169 |= V_170 ;
if ( V_98 & V_171 )
V_169 |= V_172 ;
if ( V_98 & V_173 )
V_169 |= V_174 ;
if ( V_98 & V_175 )
V_169 |= V_176 ;
if ( V_98 & V_177 )
V_169 |= V_178 ;
return V_169 ;
}
void F_86 ( struct V_1 * V_2 , unsigned V_10 ,
T_4 V_179 )
{
void T_5 * V_180 = ( void * ) V_2 -> V_141 . V_180 ;
F_87 ( V_179 , V_180 + ( V_10 * 8 ) ) ;
}
int F_88 ( struct V_1 * V_2 )
{
T_3 V_20 = 0 ;
T_3 V_181 = 0 ;
T_1 V_182 = F_2 ( V_116 ) &
~ F_89 ( 1 ) ;
T_1 V_183 = F_2 ( V_117 ) &
~ F_90 ( 1 ) ;
T_1 V_184 ;
if ( F_91 ( V_2 ) )
V_184 = F_2 ( V_185 ) &
~ F_92 ( 1 ) ;
else
V_184 = 0 ;
if ( ! V_2 -> V_186 . V_187 ) {
F_62 ( 1 , L_9 ) ;
F_6 ( V_188 , 0 ) ;
return - V_145 ;
}
if ( F_93 ( & V_2 -> V_186 . V_189 [ V_190 ] ) ) {
V_20 |= F_94 ( 1 ) ;
}
if ( V_2 -> V_186 . V_191 [ 0 ] ||
F_93 ( & V_2 -> V_186 . V_192 [ 0 ] ) ) {
V_181 |= F_95 ( 1 ) ;
}
if ( V_2 -> V_186 . V_191 [ 1 ] ||
F_93 ( & V_2 -> V_186 . V_192 [ 1 ] ) ) {
V_181 |= F_96 ( 1 ) ;
}
if ( V_2 -> V_186 . V_110 [ 0 ] ) {
V_182 |= F_89 ( 1 ) ;
}
if ( V_2 -> V_186 . V_110 [ 1 ] ) {
V_183 |= F_90 ( 1 ) ;
}
if ( V_2 -> V_186 . V_193 [ 0 ] ) {
V_184 |= F_92 ( 1 ) ;
}
F_6 ( V_188 , V_20 ) ;
F_6 ( V_194 , V_181 ) ;
F_6 ( V_116 , V_182 ) ;
F_6 ( V_117 , V_183 ) ;
if ( F_91 ( V_2 ) )
F_6 ( V_185 , V_184 ) ;
F_2 ( V_188 ) ;
return 0 ;
}
static inline T_1 F_97 ( struct V_1 * V_2 )
{
T_3 V_195 = F_2 ( V_196 ) ;
T_3 V_197 = F_98 ( 1 ) ;
T_1 V_20 ;
if ( F_99 ( V_195 ) ) {
V_2 -> V_186 . V_198 . V_199 . V_200 = F_2 ( V_201 ) ;
if ( F_100 ( V_2 -> V_186 . V_198 . V_199 . V_200 ) ) {
F_6 ( V_202 ,
F_101 ( 1 ) ) ;
}
if ( F_102 ( V_2 -> V_186 . V_198 . V_199 . V_200 ) ) {
F_6 ( V_203 ,
F_103 ( 1 ) ) ;
}
if ( F_104 ( V_2 -> V_186 . V_198 . V_199 . V_200 ) ) {
V_20 = F_2 ( V_116 ) ;
V_20 |= F_105 ( 1 ) ;
F_6 ( V_116 , V_20 ) ;
}
if ( F_106 ( V_2 -> V_186 . V_198 . V_199 . V_200 ) ) {
V_20 = F_2 ( V_117 ) ;
V_20 |= F_107 ( 1 ) ;
F_6 ( V_117 , V_20 ) ;
}
} else {
V_2 -> V_186 . V_198 . V_199 . V_200 = 0 ;
}
if ( F_91 ( V_2 ) ) {
V_2 -> V_186 . V_198 . V_199 . V_204 = F_2 ( V_205 ) &
F_108 ( 1 ) ;
if ( F_109 ( V_2 -> V_186 . V_198 . V_199 . V_204 ) ) {
V_20 = F_2 ( V_185 ) ;
V_20 |= F_110 ( 1 ) ;
F_6 ( V_185 , V_20 ) ;
}
} else
V_2 -> V_186 . V_198 . V_199 . V_204 = 0 ;
if ( V_195 ) {
F_6 ( V_196 , V_195 ) ;
}
return V_195 & V_197 ;
}
void F_111 ( struct V_1 * V_2 )
{
T_1 V_184 = F_2 ( V_185 ) &
~ F_92 ( 1 ) ;
F_6 ( V_185 , V_184 ) ;
F_6 ( V_188 , 0 ) ;
F_6 ( V_194 , 0 ) ;
F_46 ( 1 ) ;
F_97 ( V_2 ) ;
}
int F_112 ( struct V_1 * V_2 )
{
T_1 V_126 , V_206 ;
bool V_207 = false ;
bool V_208 = false ;
V_126 = F_97 ( V_2 ) ;
if ( ! V_126 &&
! V_2 -> V_186 . V_198 . V_199 . V_200 &&
! V_2 -> V_186 . V_198 . V_199 . V_204 ) {
return V_209 ;
}
while ( V_126 ||
V_2 -> V_186 . V_198 . V_199 . V_200 ||
V_2 -> V_186 . V_198 . V_199 . V_204 ) {
if ( F_113 ( V_126 ) ) {
F_114 ( V_2 , V_190 ) ;
}
if ( F_100 ( V_2 -> V_186 . V_198 . V_199 . V_200 ) ) {
if ( V_2 -> V_186 . V_191 [ 0 ] ) {
F_115 ( V_2 -> V_105 , 0 ) ;
V_2 -> V_60 . V_210 = true ;
F_116 ( & V_2 -> V_186 . V_211 ) ;
}
if ( F_93 ( & V_2 -> V_186 . V_192 [ 0 ] ) )
F_117 ( V_2 , 0 ) ;
}
if ( F_102 ( V_2 -> V_186 . V_198 . V_199 . V_200 ) ) {
if ( V_2 -> V_186 . V_191 [ 1 ] ) {
F_115 ( V_2 -> V_105 , 1 ) ;
V_2 -> V_60 . V_210 = true ;
F_116 ( & V_2 -> V_186 . V_211 ) ;
}
if ( F_93 ( & V_2 -> V_186 . V_192 [ 1 ] ) )
F_117 ( V_2 , 1 ) ;
}
if ( F_104 ( V_2 -> V_186 . V_198 . V_199 . V_200 ) ) {
V_207 = true ;
F_8 ( L_10 ) ;
}
if ( F_106 ( V_2 -> V_186 . V_198 . V_199 . V_200 ) ) {
V_207 = true ;
F_8 ( L_11 ) ;
}
if ( F_109 ( V_2 -> V_186 . V_198 . V_199 . V_204 ) ) {
V_208 = true ;
F_8 ( L_12 ) ;
}
V_126 = F_97 ( V_2 ) ;
}
if ( V_207 )
F_118 ( & V_2 -> V_212 , 0 ) ;
if ( V_208 )
F_119 ( & V_2 -> V_213 ) ;
if ( V_2 -> V_214 ) {
switch ( V_2 -> V_215 ) {
case V_216 :
case V_217 :
case V_218 :
V_206 = F_2 ( V_146 ) & ~ V_219 ;
F_6 ( V_146 , V_206 ) ;
F_6 ( V_146 , V_206 | V_219 ) ;
break;
default:
F_6 ( V_220 , V_221 ) ;
break;
}
}
return V_222 ;
}
T_1 F_120 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 0 )
return F_2 ( V_223 ) ;
else
return F_2 ( V_224 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ ) {
if ( F_122 ( F_57 ( V_225 ) ) )
return 0 ;
F_7 ( 1 ) ;
}
return - 1 ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_124 ( V_2 ) ;
if ( F_121 ( V_2 ) )
F_125 ( V_2 -> V_33 , L_13 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_2 V_226 ;
V_2 -> V_156 . V_227 = F_127 ( V_2 -> V_135 , 0 ) ;
V_2 -> V_156 . V_228 = F_128 ( V_2 -> V_135 , 0 ) ;
V_2 -> V_156 . V_229 = true ;
V_2 -> V_156 . V_230 = 128 ;
V_2 -> V_156 . V_231 = F_2 ( V_232 ) ;
V_2 -> V_156 . V_233 = V_2 -> V_156 . V_231 ;
V_2 -> V_156 . V_234 = V_2 -> V_156 . V_228 ;
V_2 -> V_156 . V_235 = F_129 ( V_2 ) ;
V_226 = F_57 ( V_236 ) ;
V_226 = F_130 ( V_226 ) << 16 ;
F_131 ( V_2 , & V_2 -> V_156 , V_226 ) ;
V_2 -> V_156 . V_237 = 0 ;
F_132 ( V_2 , & V_2 -> V_156 ) ;
F_133 ( V_2 ) ;
}
void F_134 ( struct V_1 * V_2 )
{
struct V_238 * V_239 = NULL ;
struct V_238 * V_240 = NULL ;
T_1 V_241 , V_242 ;
if ( ! V_2 -> V_18 . V_243 )
return;
F_135 ( V_2 ) ;
if ( V_2 -> V_18 . V_19 [ 0 ] -> V_226 . V_107 )
V_239 = & V_2 -> V_18 . V_19 [ 0 ] -> V_226 . V_244 ;
if ( V_2 -> V_18 . V_19 [ 1 ] -> V_226 . V_107 )
V_240 = & V_2 -> V_18 . V_19 [ 1 ] -> V_226 . V_244 ;
F_136 ( V_2 , V_239 , V_240 ) ;
if ( V_2 -> V_245 == 2 ) {
V_241 = F_2 ( V_246 ) ;
V_242 = F_2 ( V_247 ) ;
V_241 |= F_137 ( 1 ) ;
V_242 |= F_138 ( 1 ) ;
F_6 ( V_246 , V_241 ) ;
F_6 ( V_248 , V_241 ) ;
F_6 ( V_247 , V_242 ) ;
F_6 ( V_249 , V_242 ) ;
}
}
T_3 F_139 ( struct V_1 * V_2 , T_3 V_77 )
{
unsigned long V_98 ;
T_1 V_140 ;
F_140 ( & V_2 -> V_250 , V_98 ) ;
F_6 ( V_251 , F_141 ( V_77 ) |
F_142 ( 1 ) ) ;
V_140 = F_2 ( V_252 ) ;
F_143 ( & V_2 -> V_250 , V_98 ) ;
return V_140 ;
}
void F_144 ( struct V_1 * V_2 , T_3 V_77 , T_3 V_253 )
{
unsigned long V_98 ;
F_140 ( & V_2 -> V_250 , V_98 ) ;
F_6 ( V_251 , F_141 ( V_77 ) |
F_142 ( 1 ) | F_145 ( 1 ) ) ;
F_6 ( V_252 , V_253 ) ;
F_143 ( & V_2 -> V_250 , V_98 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
if ( F_147 ( V_2 ) )
F_148 ( L_14 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
V_2 -> V_254 . V_255 . V_256 = V_257 ;
V_2 -> V_254 . V_255 . V_258 = F_150 ( V_257 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_124 V_125 ;
F_42 ( V_2 , & V_125 ) ;
if ( F_121 ( V_2 ) )
F_125 ( V_2 -> V_33 , L_13 ) ;
F_58 ( V_259 , 0x0FFFFFFF ) ;
F_58 ( V_260 , 0 ) ;
F_58 ( V_261 , 0 ) ;
F_58 ( V_236 ,
F_152 ( V_2 -> V_156 . V_162 >> 16 ) |
F_153 ( V_2 -> V_156 . V_164 >> 16 ) ) ;
F_6 ( V_262 ,
F_154 ( V_2 -> V_156 . V_162 >> 16 ) ) ;
F_55 ( V_2 , & V_125 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_140 ;
F_151 ( V_2 ) ;
F_156 ( V_2 ) ;
F_123 ( V_2 ) ;
V_140 = F_65 ( V_2 ) ;
if ( V_140 )
return V_140 ;
V_140 = F_157 ( V_2 ) ;
if ( V_140 )
return V_140 ;
V_140 = F_158 ( V_2 , V_190 ) ;
if ( V_140 ) {
F_54 ( V_2 -> V_33 , L_15 , V_140 ) ;
return V_140 ;
}
if ( ! V_2 -> V_186 . V_187 ) {
V_140 = F_159 ( V_2 ) ;
if ( V_140 )
return V_140 ;
}
F_88 ( V_2 ) ;
V_2 -> V_254 . V_255 . V_263 = F_2 ( V_264 ) ;
V_140 = F_160 ( V_2 , 1024 * 1024 ) ;
if ( V_140 ) {
F_54 ( V_2 -> V_33 , L_16 , V_140 ) ;
return V_140 ;
}
V_140 = F_161 ( V_2 ) ;
if ( V_140 ) {
F_54 ( V_2 -> V_33 , L_17 , V_140 ) ;
return V_140 ;
}
V_140 = F_162 ( V_2 ) ;
if ( V_140 ) {
F_54 ( V_2 -> V_33 , L_18 ) ;
return V_140 ;
}
return 0 ;
}
int F_163 ( struct V_1 * V_2 )
{
int V_140 ;
F_80 ( V_2 ) ;
F_156 ( V_2 ) ;
if ( F_164 ( V_2 ) ) {
F_125 ( V_2 -> V_33 , L_19 ,
F_2 ( V_128 ) ,
F_2 ( V_265 ) ) ;
}
F_165 ( V_2 -> V_18 . V_266 ) ;
F_156 ( V_2 ) ;
F_166 ( V_2 ) ;
V_2 -> V_267 = true ;
V_140 = F_155 ( V_2 ) ;
if ( V_140 ) {
V_2 -> V_267 = false ;
}
return V_140 ;
}
int F_167 ( struct V_1 * V_2 )
{
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_111 ( V_2 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
void F_172 ( struct V_1 * V_2 )
{
F_173 ( V_2 ) ;
F_169 ( V_2 ) ;
F_174 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 ) ;
F_177 ( V_2 ) ;
F_82 ( V_2 ) ;
F_178 ( V_2 ) ;
F_179 ( V_2 ) ;
F_180 ( V_2 ) ;
F_181 ( V_2 ) ;
F_182 ( V_2 -> V_268 ) ;
V_2 -> V_268 = NULL ;
}
int F_183 ( struct V_1 * V_2 )
{
int V_140 ;
F_184 ( V_2 ) ;
F_185 ( V_2 ) ;
F_166 ( V_2 ) ;
F_186 ( V_2 ) ;
if ( ! F_187 ( V_2 ) ) {
if ( F_188 ( V_2 ) )
return - V_145 ;
}
if ( V_2 -> V_269 ) {
V_140 = F_189 ( V_2 ) ;
if ( V_140 )
return V_140 ;
} else {
F_54 ( V_2 -> V_33 , L_20 ) ;
return - V_145 ;
}
if ( F_164 ( V_2 ) ) {
F_125 ( V_2 -> V_33 ,
L_19 ,
F_2 ( V_128 ) ,
F_2 ( V_265 ) ) ;
}
if ( F_190 ( V_2 ) == false )
return - V_145 ;
F_191 ( V_2 -> V_105 ) ;
F_126 ( V_2 ) ;
F_146 ( V_2 ) ;
V_140 = F_192 ( V_2 ) ;
if ( V_140 )
return V_140 ;
V_140 = F_193 ( V_2 ) ;
if ( V_140 )
return V_140 ;
V_140 = F_61 ( V_2 ) ;
if ( V_140 )
return V_140 ;
F_149 ( V_2 ) ;
F_194 ( V_2 ) ;
V_2 -> V_267 = true ;
V_140 = F_155 ( V_2 ) ;
if ( V_140 ) {
F_54 ( V_2 -> V_33 , L_21 ) ;
F_174 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 ) ;
F_82 ( V_2 ) ;
F_178 ( V_2 ) ;
V_2 -> V_267 = false ;
}
return 0 ;
}
