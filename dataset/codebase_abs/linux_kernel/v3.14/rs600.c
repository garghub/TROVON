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
void F_5 ( struct V_1 * V_2 , int V_3 )
{
F_6 ( V_2 , V_3 ) ;
}
void F_7 ( struct V_1 * V_2 , int V_3 )
{
F_8 ( V_2 , V_3 ) ;
}
T_1 F_9 ( struct V_1 * V_2 , int V_14 , T_2 V_15 )
{
struct V_16 * V_16 = V_2 -> V_17 . V_18 [ V_14 ] ;
T_1 V_19 = F_2 ( V_20 + V_16 -> V_21 ) ;
int V_10 ;
V_19 |= V_22 ;
F_10 ( V_20 + V_16 -> V_21 , V_19 ) ;
F_10 ( V_23 + V_16 -> V_21 ,
( T_1 ) V_15 ) ;
F_10 ( V_24 + V_16 -> V_21 ,
( T_1 ) V_15 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
if ( F_2 ( V_20 + V_16 -> V_21 ) & V_26 )
break;
F_11 ( 1 ) ;
}
F_12 ( L_1 ) ;
V_19 &= ~ V_22 ;
F_10 ( V_20 + V_16 -> V_21 , V_19 ) ;
return F_2 ( V_20 + V_16 -> V_21 ) & V_26 ;
}
void F_13 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_1 * V_2 = V_30 -> V_31 ;
struct V_32 * V_32 = F_14 ( V_28 ) ;
struct V_33 * V_34 = F_15 ( V_28 ) ;
int V_35 = 0 ;
T_1 V_19 = 0 ;
enum V_36 V_37 = V_38 ;
if ( V_34 ) {
struct V_39 * V_39 = F_16 ( V_34 ) ;
V_35 = F_17 ( V_34 ) ;
V_37 = V_39 -> V_37 ;
}
if ( V_32 -> V_40 & V_41 )
return;
if ( V_35 == 0 )
return;
switch ( V_35 ) {
case 6 :
if ( V_37 == V_42 )
V_19 |= V_43 ;
else
V_19 |= V_44 ;
break;
case 8 :
if ( V_37 == V_42 )
V_19 |= ( V_43 |
V_45 ) ;
else
V_19 |= ( V_44 |
V_46 ) ;
break;
case 10 :
default:
break;
}
switch ( V_32 -> V_47 ) {
case V_48 :
F_10 ( V_49 , V_19 ) ;
break;
case V_50 :
F_10 ( V_51 , V_19 ) ;
break;
case V_52 :
F_10 ( V_53 , V_19 ) ;
break;
case V_54 :
F_10 ( V_55 , V_19 ) ;
break;
default:
break;
}
}
void F_18 ( struct V_1 * V_2 )
{
int V_56 = V_2 -> V_57 . V_58 ;
struct V_59 * V_60 = & V_2 -> V_57 . V_61 [ V_56 ] ;
struct V_62 * V_63 = & V_60 -> V_64 [ 0 ] . V_63 ;
T_1 V_19 , V_65 , V_66 ;
T_1 V_67 , V_68 ;
if ( ( V_63 -> type == V_69 ) && ( V_63 -> V_70 . V_71 ) ) {
if ( V_60 -> V_72 & V_73 ) {
V_19 = F_2 ( V_63 -> V_70 . V_74 ) ;
if ( V_63 -> V_75 )
V_19 |= V_63 -> V_70 . V_76 ;
else
V_19 &= ~ ( V_63 -> V_70 . V_76 ) ;
F_10 ( V_63 -> V_70 . V_74 , V_19 ) ;
if ( V_63 -> V_77 )
F_11 ( V_63 -> V_77 ) ;
} else {
V_19 = F_2 ( V_63 -> V_70 . V_74 ) ;
if ( V_63 -> V_75 )
V_19 &= ~ V_63 -> V_70 . V_76 ;
else
V_19 |= V_63 -> V_70 . V_76 ;
F_10 ( V_63 -> V_70 . V_74 , V_19 ) ;
if ( V_63 -> V_77 )
F_11 ( V_63 -> V_77 ) ;
}
} else if ( V_63 -> type == V_78 )
F_19 ( V_2 , V_63 -> V_79 , V_80 ) ;
V_65 = F_20 ( V_81 ) ;
V_65 &= ~ F_21 ( 0xf ) ;
V_65 &= ~ F_22 ( 0xf ) ;
if ( V_60 -> V_72 & V_82 ) {
if ( V_60 -> V_72 & V_83 ) {
V_65 |= F_21 ( 2 ) ;
V_65 |= F_22 ( 2 ) ;
} else if ( V_60 -> V_72 & V_84 ) {
V_65 |= F_21 ( 4 ) ;
V_65 |= F_22 ( 4 ) ;
}
} else {
V_65 |= F_21 ( 1 ) ;
V_65 |= F_22 ( 1 ) ;
}
F_23 ( V_81 , V_65 ) ;
V_66 = F_20 ( V_85 ) ;
if ( V_60 -> V_72 & V_86 ) {
V_66 |= V_87 ;
if ( V_63 -> V_77 ) {
V_66 |= V_88 ;
V_66 |= F_24 ( V_63 -> V_77 ) ;
} else
V_66 &= ~ V_88 ;
} else
V_66 &= ~ V_87 ;
F_23 ( V_85 , V_66 ) ;
V_67 = F_20 ( V_89 ) ;
if ( V_60 -> V_72 & V_90 )
V_67 &= ~ V_91 ;
else
V_67 |= V_91 ;
F_23 ( V_89 , V_67 ) ;
#if 0
mc_host_dyn_cntl = RREG32_PLL(MC_HOST_DYN_CNTL);
if (ps->misc & ATOM_PM_MISCINFO_DYNAMIC_MC_HOST_BLOCK_EN)
mc_host_dyn_cntl &= ~MC_HOST_FORCEON;
else
mc_host_dyn_cntl |= MC_HOST_FORCEON;
WREG32_PLL(MC_HOST_DYN_CNTL, mc_host_dyn_cntl);
#endif
V_68 = F_20 ( V_92 ) ;
if ( V_60 -> V_72 & V_93 )
V_68 |= V_94 ;
else
V_68 &= ~ V_94 ;
F_23 ( V_92 , V_68 ) ;
if ( ( V_2 -> V_95 & V_96 ) &&
! ( V_2 -> V_95 & V_97 ) &&
V_2 -> V_98 -> V_57 . V_99 &&
( V_60 -> V_100 !=
V_2 -> V_57 . V_61 [ V_2 -> V_57 . V_101 ] . V_100 ) ) {
F_25 ( V_2 ,
V_60 -> V_100 ) ;
F_12 ( L_2 , V_60 -> V_100 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_29 * V_102 = V_2 -> V_102 ;
struct V_103 * V_3 ;
struct V_16 * V_16 ;
T_1 V_19 ;
F_27 (crtc, &ddev->mode_config.crtc_list, head) {
V_16 = F_28 ( V_3 ) ;
if ( V_16 -> V_104 ) {
V_19 = F_2 ( V_12 + V_16 -> V_21 ) ;
V_19 |= V_105 ;
F_10 ( V_12 + V_16 -> V_21 , V_19 ) ;
}
}
}
void F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_102 = V_2 -> V_102 ;
struct V_103 * V_3 ;
struct V_16 * V_16 ;
T_1 V_19 ;
F_27 (crtc, &ddev->mode_config.crtc_list, head) {
V_16 = F_28 ( V_3 ) ;
if ( V_16 -> V_104 ) {
V_19 = F_2 ( V_12 + V_16 -> V_21 ) ;
V_19 &= ~ V_105 ;
F_10 ( V_12 + V_16 -> V_21 , V_19 ) ;
}
}
}
bool F_30 ( struct V_1 * V_2 , enum V_106 V_107 )
{
T_1 V_19 ;
bool V_108 = false ;
switch ( V_107 ) {
case V_109 :
V_19 = F_2 ( V_110 ) ;
if ( F_31 ( V_19 ) )
V_108 = true ;
break;
case V_111 :
V_19 = F_2 ( V_112 ) ;
if ( F_32 ( V_19 ) )
V_108 = true ;
break;
default:
break;
}
return V_108 ;
}
void F_33 ( struct V_1 * V_2 ,
enum V_106 V_107 )
{
T_1 V_19 ;
bool V_108 = F_30 ( V_2 , V_107 ) ;
switch ( V_107 ) {
case V_109 :
V_19 = F_2 ( V_113 ) ;
if ( V_108 )
V_19 &= ~ F_34 ( 1 ) ;
else
V_19 |= F_34 ( 1 ) ;
F_10 ( V_113 , V_19 ) ;
break;
case V_111 :
V_19 = F_2 ( V_114 ) ;
if ( V_108 )
V_19 &= ~ F_35 ( 1 ) ;
else
V_19 |= F_35 ( 1 ) ;
F_10 ( V_114 , V_19 ) ;
break;
default:
break;
}
}
void F_36 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_102 ;
struct V_33 * V_34 ;
unsigned V_115 = 0 ;
F_27 (connector, &dev->mode_config.connector_list, head) {
struct V_39 * V_39 = F_16 ( V_34 ) ;
switch ( V_39 -> V_107 . V_107 ) {
case V_109 :
F_10 ( V_116 ,
F_37 ( 1 ) ) ;
break;
case V_111 :
F_10 ( V_117 ,
F_38 ( 1 ) ) ;
break;
default:
break;
}
V_115 |= 1 << V_39 -> V_107 . V_107 ;
F_39 ( V_2 , V_39 -> V_107 . V_107 ) ;
}
F_40 ( V_2 , V_115 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_102 ;
struct V_33 * V_34 ;
unsigned V_118 = 0 ;
F_27 (connector, &dev->mode_config.connector_list, head) {
struct V_39 * V_39 = F_16 ( V_34 ) ;
switch ( V_39 -> V_107 . V_107 ) {
case V_109 :
F_10 ( V_116 ,
F_37 ( 0 ) ) ;
break;
case V_111 :
F_10 ( V_117 ,
F_38 ( 0 ) ) ;
break;
default:
break;
}
V_118 |= 1 << V_39 -> V_107 . V_107 ;
}
F_42 ( V_2 , V_118 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_119 V_120 ;
T_1 V_121 , V_19 ;
int V_122 = 0 ;
V_121 = F_2 ( V_123 ) ;
if ( ! F_44 ( V_121 ) ) {
return 0 ;
}
F_45 ( V_2 , & V_120 ) ;
V_121 = F_2 ( V_123 ) ;
F_46 ( V_2 -> V_30 , L_3 , V_124 , __LINE__ , V_121 ) ;
F_10 ( V_125 , 0 ) ;
V_19 = F_2 ( V_126 ) ;
F_10 ( V_126 , V_19 | V_127 ) ;
F_10 ( V_128 , 0 ) ;
F_10 ( V_129 , 0 ) ;
F_10 ( V_126 , V_19 ) ;
F_47 ( V_2 -> V_130 ) ;
F_48 ( V_2 -> V_130 ) ;
F_49 ( 1 ) ;
F_10 ( V_131 , F_50 ( 1 ) |
F_51 ( 1 ) ) ;
F_2 ( V_131 ) ;
F_49 ( 500 ) ;
F_10 ( V_131 , 0 ) ;
F_49 ( 1 ) ;
V_121 = F_2 ( V_123 ) ;
F_46 ( V_2 -> V_30 , L_3 , V_124 , __LINE__ , V_121 ) ;
F_10 ( V_131 , F_52 ( 1 ) ) ;
F_2 ( V_131 ) ;
F_49 ( 500 ) ;
F_10 ( V_131 , 0 ) ;
F_49 ( 1 ) ;
V_121 = F_2 ( V_123 ) ;
F_46 ( V_2 -> V_30 , L_3 , V_124 , __LINE__ , V_121 ) ;
F_10 ( V_131 , F_53 ( 1 ) ) ;
F_2 ( V_131 ) ;
F_49 ( 500 ) ;
F_10 ( V_131 , 0 ) ;
F_49 ( 1 ) ;
V_121 = F_2 ( V_123 ) ;
F_46 ( V_2 -> V_30 , L_3 , V_124 , __LINE__ , V_121 ) ;
F_54 ( V_2 -> V_130 ) ;
if ( F_55 ( V_121 ) || F_56 ( V_121 ) ) {
F_57 ( V_2 -> V_30 , L_4 ) ;
V_122 = - 1 ;
} else
F_46 ( V_2 -> V_30 , L_5 ) ;
F_58 ( V_2 , & V_120 ) ;
return V_122 ;
}
void F_59 ( struct V_1 * V_2 )
{
T_3 V_19 ;
V_19 = F_60 ( V_132 ) ;
V_19 &= V_133 & V_134 ;
F_61 ( V_132 , V_19 ) ;
V_19 = F_60 ( V_132 ) ;
V_19 |= F_62 ( 1 ) | F_63 ( 1 ) ;
F_61 ( V_132 , V_19 ) ;
V_19 = F_60 ( V_132 ) ;
V_19 &= V_133 & V_134 ;
F_61 ( V_132 , V_19 ) ;
V_19 = F_60 ( V_132 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_135 ;
if ( V_2 -> V_136 . V_137 ) {
F_65 ( 1 , L_6 ) ;
return 0 ;
}
V_135 = F_66 ( V_2 ) ;
if ( V_135 ) {
return V_135 ;
}
V_2 -> V_136 . V_138 = V_2 -> V_136 . V_139 * 8 ;
return F_67 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
T_1 V_19 ;
int V_135 , V_10 ;
if ( V_2 -> V_136 . V_137 == NULL ) {
F_57 ( V_2 -> V_30 , L_7 ) ;
return - V_140 ;
}
V_135 = F_69 ( V_2 ) ;
if ( V_135 )
return V_135 ;
F_70 ( V_2 ) ;
V_19 = F_2 ( V_141 ) & ~ V_142 ;
F_10 ( V_141 , V_19 ) ;
F_61 ( V_132 ,
( F_71 ( 6 ) |
F_72 ( 6 ) ) ) ;
for ( V_10 = 0 ; V_10 < 19 ; V_10 ++ ) {
F_61 ( V_143 + V_10 ,
F_73 ( 1 ) |
F_74 (
V_144 ) |
F_75 (
V_145 ) |
F_76 ( 3 ) |
F_77 ( 1 ) |
F_78 ( 3 ) ) ;
}
F_61 ( V_146 ,
F_79 ( 1 ) |
F_80 ( V_147 ) ) ;
for ( V_10 = 1 ; V_10 < 8 ; V_10 ++ )
F_61 ( V_146 + V_10 , 0 ) ;
F_61 ( V_148 ,
V_2 -> V_136 . V_149 ) ;
F_61 ( V_150 , V_2 -> V_151 . V_152 ) ;
F_61 ( V_153 , V_2 -> V_151 . V_154 ) ;
F_61 ( V_155 , 0 ) ;
F_61 ( V_156 , V_2 -> V_151 . V_157 ) ;
F_61 ( V_158 , V_2 -> V_151 . V_159 ) ;
V_19 = F_60 ( V_132 ) ;
F_61 ( V_132 , ( V_19 | F_81 ( 1 ) ) ) ;
V_19 = F_60 ( V_160 ) ;
F_61 ( V_160 , ( V_19 | F_82 ( 1 ) ) ) ;
F_59 ( V_2 ) ;
F_83 ( L_8 ,
( unsigned ) ( V_2 -> V_151 . V_161 >> 20 ) ,
( unsigned long long ) V_2 -> V_136 . V_149 ) ;
V_2 -> V_136 . V_162 = true ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
T_1 V_19 ;
F_61 ( V_132 , 0 ) ;
V_19 = F_60 ( V_160 ) ;
F_61 ( V_160 , V_19 & V_163 ) ;
F_85 ( V_2 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_87 ( V_2 ) ;
F_84 ( V_2 ) ;
F_88 ( V_2 ) ;
}
int F_89 ( struct V_1 * V_2 , int V_10 , T_4 V_164 )
{
void T_5 * V_165 = ( void * ) V_2 -> V_136 . V_165 ;
if ( V_10 < 0 || V_10 > V_2 -> V_136 . V_139 ) {
return - V_140 ;
}
V_164 = V_164 & 0xFFFFFFFFFFFFF000ULL ;
V_164 |= V_166 | V_167 | V_168 ;
V_164 |= V_169 | V_170 ;
F_90 ( V_164 , V_165 + ( V_10 * 8 ) ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 )
{
T_3 V_19 = 0 ;
T_3 V_171 = 0 ;
T_1 V_172 = F_2 ( V_113 ) &
~ F_92 ( 1 ) ;
T_1 V_173 = F_2 ( V_114 ) &
~ F_93 ( 1 ) ;
T_1 V_174 ;
if ( F_94 ( V_2 ) )
V_174 = F_2 ( V_175 ) &
~ F_95 ( 1 ) ;
else
V_174 = 0 ;
if ( ! V_2 -> V_176 . V_177 ) {
F_65 ( 1 , L_9 ) ;
F_10 ( V_178 , 0 ) ;
return - V_140 ;
}
if ( F_96 ( & V_2 -> V_176 . V_179 [ V_180 ] ) ) {
V_19 |= F_97 ( 1 ) ;
}
if ( V_2 -> V_176 . V_181 [ 0 ] ||
F_96 ( & V_2 -> V_176 . V_182 [ 0 ] ) ) {
V_171 |= F_98 ( 1 ) ;
}
if ( V_2 -> V_176 . V_181 [ 1 ] ||
F_96 ( & V_2 -> V_176 . V_182 [ 1 ] ) ) {
V_171 |= F_99 ( 1 ) ;
}
if ( V_2 -> V_176 . V_107 [ 0 ] ) {
V_172 |= F_92 ( 1 ) ;
}
if ( V_2 -> V_176 . V_107 [ 1 ] ) {
V_173 |= F_93 ( 1 ) ;
}
if ( V_2 -> V_176 . V_183 [ 0 ] ) {
V_174 |= F_95 ( 1 ) ;
}
F_10 ( V_178 , V_19 ) ;
F_10 ( V_184 , V_171 ) ;
F_10 ( V_113 , V_172 ) ;
F_10 ( V_114 , V_173 ) ;
if ( F_94 ( V_2 ) )
F_10 ( V_175 , V_174 ) ;
return 0 ;
}
static inline T_1 F_100 ( struct V_1 * V_2 )
{
T_3 V_185 = F_2 ( V_186 ) ;
T_3 V_187 = F_101 ( 1 ) ;
T_1 V_19 ;
if ( F_102 ( V_185 ) ) {
V_2 -> V_176 . V_188 . V_189 . V_190 = F_2 ( V_191 ) ;
if ( F_103 ( V_2 -> V_176 . V_188 . V_189 . V_190 ) ) {
F_10 ( V_192 ,
F_104 ( 1 ) ) ;
}
if ( F_105 ( V_2 -> V_176 . V_188 . V_189 . V_190 ) ) {
F_10 ( V_193 ,
F_106 ( 1 ) ) ;
}
if ( F_107 ( V_2 -> V_176 . V_188 . V_189 . V_190 ) ) {
V_19 = F_2 ( V_113 ) ;
V_19 |= F_108 ( 1 ) ;
F_10 ( V_113 , V_19 ) ;
}
if ( F_109 ( V_2 -> V_176 . V_188 . V_189 . V_190 ) ) {
V_19 = F_2 ( V_114 ) ;
V_19 |= F_110 ( 1 ) ;
F_10 ( V_114 , V_19 ) ;
}
} else {
V_2 -> V_176 . V_188 . V_189 . V_190 = 0 ;
}
if ( F_94 ( V_2 ) ) {
V_2 -> V_176 . V_188 . V_189 . V_194 = F_2 ( V_195 ) &
F_111 ( 1 ) ;
if ( F_112 ( V_2 -> V_176 . V_188 . V_189 . V_194 ) ) {
V_19 = F_2 ( V_175 ) ;
V_19 |= F_113 ( 1 ) ;
F_10 ( V_175 , V_19 ) ;
}
} else
V_2 -> V_176 . V_188 . V_189 . V_194 = 0 ;
if ( V_185 ) {
F_10 ( V_186 , V_185 ) ;
}
return V_185 & V_187 ;
}
void F_114 ( struct V_1 * V_2 )
{
T_1 V_174 = F_2 ( V_175 ) &
~ F_95 ( 1 ) ;
F_10 ( V_175 , V_174 ) ;
F_10 ( V_178 , 0 ) ;
F_10 ( V_184 , 0 ) ;
F_49 ( 1 ) ;
F_100 ( V_2 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
T_1 V_121 , V_196 ;
bool V_197 = false ;
bool V_198 = false ;
V_121 = F_100 ( V_2 ) ;
if ( ! V_121 &&
! V_2 -> V_176 . V_188 . V_189 . V_190 &&
! V_2 -> V_176 . V_188 . V_189 . V_194 ) {
return V_199 ;
}
while ( V_121 ||
V_2 -> V_176 . V_188 . V_189 . V_190 ||
V_2 -> V_176 . V_188 . V_189 . V_194 ) {
if ( F_116 ( V_121 ) ) {
F_117 ( V_2 , V_180 ) ;
}
if ( F_103 ( V_2 -> V_176 . V_188 . V_189 . V_190 ) ) {
if ( V_2 -> V_176 . V_181 [ 0 ] ) {
F_118 ( V_2 -> V_102 , 0 ) ;
V_2 -> V_57 . V_200 = true ;
F_119 ( & V_2 -> V_176 . V_201 ) ;
}
if ( F_96 ( & V_2 -> V_176 . V_182 [ 0 ] ) )
F_120 ( V_2 , 0 ) ;
}
if ( F_105 ( V_2 -> V_176 . V_188 . V_189 . V_190 ) ) {
if ( V_2 -> V_176 . V_181 [ 1 ] ) {
F_118 ( V_2 -> V_102 , 1 ) ;
V_2 -> V_57 . V_200 = true ;
F_119 ( & V_2 -> V_176 . V_201 ) ;
}
if ( F_96 ( & V_2 -> V_176 . V_182 [ 1 ] ) )
F_120 ( V_2 , 1 ) ;
}
if ( F_107 ( V_2 -> V_176 . V_188 . V_189 . V_190 ) ) {
V_197 = true ;
F_12 ( L_10 ) ;
}
if ( F_109 ( V_2 -> V_176 . V_188 . V_189 . V_190 ) ) {
V_197 = true ;
F_12 ( L_11 ) ;
}
if ( F_112 ( V_2 -> V_176 . V_188 . V_189 . V_194 ) ) {
V_198 = true ;
F_12 ( L_12 ) ;
}
V_121 = F_100 ( V_2 ) ;
}
if ( V_197 )
F_121 ( & V_2 -> V_202 ) ;
if ( V_198 )
F_121 ( & V_2 -> V_203 ) ;
if ( V_2 -> V_204 ) {
switch ( V_2 -> V_205 ) {
case V_206 :
case V_207 :
case V_208 :
V_196 = F_2 ( V_141 ) & ~ V_209 ;
F_10 ( V_141 , V_196 ) ;
F_10 ( V_141 , V_196 | V_209 ) ;
break;
default:
F_10 ( V_210 , V_211 ) ;
break;
}
}
return V_212 ;
}
T_1 F_122 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 0 )
return F_2 ( V_213 ) ;
else
return F_2 ( V_214 ) ;
}
int F_123 ( struct V_1 * V_2 )
{
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
if ( F_124 ( F_60 ( V_215 ) ) )
return 0 ;
F_11 ( 1 ) ;
}
return - 1 ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_126 ( V_2 ) ;
if ( F_123 ( V_2 ) )
F_127 ( V_2 -> V_30 , L_13 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
T_2 V_216 ;
V_2 -> V_151 . V_217 = F_129 ( V_2 -> V_130 , 0 ) ;
V_2 -> V_151 . V_218 = F_130 ( V_2 -> V_130 , 0 ) ;
V_2 -> V_151 . V_219 = true ;
V_2 -> V_151 . V_220 = 128 ;
V_2 -> V_151 . V_221 = F_2 ( V_222 ) ;
V_2 -> V_151 . V_223 = V_2 -> V_151 . V_221 ;
V_2 -> V_151 . V_224 = V_2 -> V_151 . V_218 ;
V_2 -> V_151 . V_225 = F_131 ( V_2 ) ;
V_216 = F_60 ( V_226 ) ;
V_216 = F_132 ( V_216 ) << 16 ;
F_133 ( V_2 , & V_2 -> V_151 , V_216 ) ;
V_2 -> V_151 . V_227 = 0 ;
F_134 ( V_2 , & V_2 -> V_151 ) ;
F_135 ( V_2 ) ;
}
void F_136 ( struct V_1 * V_2 )
{
struct V_228 * V_229 = NULL ;
struct V_228 * V_230 = NULL ;
T_1 V_231 , V_232 ;
F_137 ( V_2 ) ;
if ( V_2 -> V_17 . V_18 [ 0 ] -> V_216 . V_104 )
V_229 = & V_2 -> V_17 . V_18 [ 0 ] -> V_216 . V_233 ;
if ( V_2 -> V_17 . V_18 [ 1 ] -> V_216 . V_104 )
V_230 = & V_2 -> V_17 . V_18 [ 1 ] -> V_216 . V_233 ;
F_138 ( V_2 , V_229 , V_230 ) ;
if ( V_2 -> V_234 == 2 ) {
V_231 = F_2 ( V_235 ) ;
V_232 = F_2 ( V_236 ) ;
V_231 |= F_139 ( 1 ) ;
V_232 |= F_140 ( 1 ) ;
F_10 ( V_235 , V_231 ) ;
F_10 ( V_237 , V_231 ) ;
F_10 ( V_236 , V_232 ) ;
F_10 ( V_238 , V_232 ) ;
}
}
T_3 F_141 ( struct V_1 * V_2 , T_3 V_74 )
{
unsigned long V_95 ;
T_1 V_135 ;
F_142 ( & V_2 -> V_239 , V_95 ) ;
F_10 ( V_240 , F_143 ( V_74 ) |
F_144 ( 1 ) ) ;
V_135 = F_2 ( V_241 ) ;
F_145 ( & V_2 -> V_239 , V_95 ) ;
return V_135 ;
}
void F_146 ( struct V_1 * V_2 , T_3 V_74 , T_3 V_242 )
{
unsigned long V_95 ;
F_142 ( & V_2 -> V_239 , V_95 ) ;
F_10 ( V_240 , F_143 ( V_74 ) |
F_144 ( 1 ) | F_147 ( 1 ) ) ;
F_10 ( V_241 , V_242 ) ;
F_145 ( & V_2 -> V_239 , V_95 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
if ( F_149 ( V_2 ) )
F_150 ( L_14 ) ;
}
void F_151 ( struct V_1 * V_2 )
{
V_2 -> V_243 . V_244 . V_245 = V_246 ;
V_2 -> V_243 . V_244 . V_247 = F_152 ( V_246 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_119 V_120 ;
F_45 ( V_2 , & V_120 ) ;
if ( F_123 ( V_2 ) )
F_127 ( V_2 -> V_30 , L_13 ) ;
F_61 ( V_248 , 0x0FFFFFFF ) ;
F_61 ( V_249 , 0 ) ;
F_61 ( V_250 , 0 ) ;
F_61 ( V_226 ,
F_154 ( V_2 -> V_151 . V_157 >> 16 ) |
F_155 ( V_2 -> V_151 . V_159 >> 16 ) ) ;
F_10 ( V_251 ,
F_156 ( V_2 -> V_151 . V_157 >> 16 ) ) ;
F_58 ( V_2 , & V_120 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
int V_135 ;
F_153 ( V_2 ) ;
F_158 ( V_2 ) ;
F_125 ( V_2 ) ;
V_135 = F_68 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_159 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_160 ( V_2 , V_180 ) ;
if ( V_135 ) {
F_57 ( V_2 -> V_30 , L_15 , V_135 ) ;
return V_135 ;
}
if ( ! V_2 -> V_176 . V_177 ) {
V_135 = F_161 ( V_2 ) ;
if ( V_135 )
return V_135 ;
}
F_91 ( V_2 ) ;
V_2 -> V_243 . V_244 . V_252 = F_2 ( V_253 ) ;
V_135 = F_162 ( V_2 , 1024 * 1024 ) ;
if ( V_135 ) {
F_57 ( V_2 -> V_30 , L_16 , V_135 ) ;
return V_135 ;
}
V_135 = F_163 ( V_2 ) ;
if ( V_135 ) {
F_57 ( V_2 -> V_30 , L_17 , V_135 ) ;
return V_135 ;
}
V_135 = F_164 ( V_2 ) ;
if ( V_135 ) {
F_57 ( V_2 -> V_30 , L_18 ) ;
return V_135 ;
}
return 0 ;
}
int F_165 ( struct V_1 * V_2 )
{
int V_135 ;
F_84 ( V_2 ) ;
F_158 ( V_2 ) ;
if ( F_166 ( V_2 ) ) {
F_127 ( V_2 -> V_30 , L_19 ,
F_2 ( V_123 ) ,
F_2 ( V_254 ) ) ;
}
F_167 ( V_2 -> V_17 . V_255 ) ;
F_158 ( V_2 ) ;
F_168 ( V_2 ) ;
V_2 -> V_256 = true ;
V_135 = F_157 ( V_2 ) ;
if ( V_135 ) {
V_2 -> V_256 = false ;
}
return V_135 ;
}
int F_169 ( struct V_1 * V_2 )
{
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
F_114 ( V_2 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
void F_174 ( struct V_1 * V_2 )
{
F_175 ( V_2 ) ;
F_171 ( V_2 ) ;
F_176 ( V_2 ) ;
F_177 ( V_2 ) ;
F_178 ( V_2 ) ;
F_179 ( V_2 ) ;
F_86 ( V_2 ) ;
F_180 ( V_2 ) ;
F_181 ( V_2 ) ;
F_182 ( V_2 ) ;
F_183 ( V_2 ) ;
F_184 ( V_2 -> V_257 ) ;
V_2 -> V_257 = NULL ;
}
int F_185 ( struct V_1 * V_2 )
{
int V_135 ;
F_186 ( V_2 ) ;
F_187 ( V_2 ) ;
F_168 ( V_2 ) ;
F_188 ( V_2 ) ;
if ( ! F_189 ( V_2 ) ) {
if ( F_190 ( V_2 ) )
return - V_140 ;
}
if ( V_2 -> V_258 ) {
V_135 = F_191 ( V_2 ) ;
if ( V_135 )
return V_135 ;
} else {
F_57 ( V_2 -> V_30 , L_20 ) ;
return - V_140 ;
}
if ( F_166 ( V_2 ) ) {
F_127 ( V_2 -> V_30 ,
L_19 ,
F_2 ( V_123 ) ,
F_2 ( V_254 ) ) ;
}
if ( F_192 ( V_2 ) == false )
return - V_140 ;
F_193 ( V_2 -> V_102 ) ;
F_128 ( V_2 ) ;
F_148 ( V_2 ) ;
V_135 = F_194 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_195 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_64 ( V_2 ) ;
if ( V_135 )
return V_135 ;
F_151 ( V_2 ) ;
F_196 ( V_2 ) ;
V_2 -> V_256 = true ;
V_135 = F_157 ( V_2 ) ;
if ( V_135 ) {
F_57 ( V_2 -> V_30 , L_21 ) ;
F_176 ( V_2 ) ;
F_177 ( V_2 ) ;
F_178 ( V_2 ) ;
F_86 ( V_2 ) ;
F_180 ( V_2 ) ;
V_2 -> V_256 = false ;
}
return 0 ;
}
