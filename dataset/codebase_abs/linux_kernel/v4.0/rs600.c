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
void F_5 ( struct V_1 * V_2 , int V_14 , T_2 V_15 )
{
struct V_16 * V_16 = V_2 -> V_17 . V_18 [ V_14 ] ;
T_1 V_19 = F_2 ( V_20 + V_16 -> V_21 ) ;
int V_10 ;
V_19 |= V_22 ;
F_6 ( V_20 + V_16 -> V_21 , V_19 ) ;
F_6 ( V_23 + V_16 -> V_21 ,
( T_1 ) V_15 ) ;
F_6 ( V_24 + V_16 -> V_21 ,
( T_1 ) V_15 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
if ( F_2 ( V_20 + V_16 -> V_21 ) & V_26 )
break;
F_7 ( 1 ) ;
}
F_8 ( L_1 ) ;
V_19 &= ~ V_22 ;
F_6 ( V_20 + V_16 -> V_21 , V_19 ) ;
}
bool F_9 ( struct V_1 * V_2 , int V_14 )
{
struct V_16 * V_16 = V_2 -> V_17 . V_18 [ V_14 ] ;
return ! ! ( F_2 ( V_20 + V_16 -> V_21 ) &
V_26 ) ;
}
void F_10 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_1 * V_2 = V_30 -> V_31 ;
struct V_32 * V_32 = F_11 ( V_28 ) ;
struct V_33 * V_34 = F_12 ( V_28 ) ;
int V_35 = 0 ;
T_1 V_19 = 0 ;
enum V_36 V_37 = V_38 ;
if ( V_34 ) {
struct V_39 * V_39 = F_13 ( V_34 ) ;
V_35 = F_14 ( V_34 ) ;
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
F_6 ( V_49 , V_19 ) ;
break;
case V_50 :
F_6 ( V_51 , V_19 ) ;
break;
case V_52 :
F_6 ( V_53 , V_19 ) ;
break;
case V_54 :
F_6 ( V_55 , V_19 ) ;
break;
default:
break;
}
}
void F_15 ( struct V_1 * V_2 )
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
F_6 ( V_63 -> V_70 . V_74 , V_19 ) ;
if ( V_63 -> V_77 )
F_7 ( V_63 -> V_77 ) ;
} else {
V_19 = F_2 ( V_63 -> V_70 . V_74 ) ;
if ( V_63 -> V_75 )
V_19 &= ~ V_63 -> V_70 . V_76 ;
else
V_19 |= V_63 -> V_70 . V_76 ;
F_6 ( V_63 -> V_70 . V_74 , V_19 ) ;
if ( V_63 -> V_77 )
F_7 ( V_63 -> V_77 ) ;
}
} else if ( V_63 -> type == V_78 )
F_16 ( V_2 , V_63 -> V_79 , V_80 ) ;
V_65 = F_17 ( V_81 ) ;
V_65 &= ~ F_18 ( 0xf ) ;
V_65 &= ~ F_19 ( 0xf ) ;
if ( V_60 -> V_72 & V_82 ) {
if ( V_60 -> V_72 & V_83 ) {
V_65 |= F_18 ( 2 ) ;
V_65 |= F_19 ( 2 ) ;
} else if ( V_60 -> V_72 & V_84 ) {
V_65 |= F_18 ( 4 ) ;
V_65 |= F_19 ( 4 ) ;
}
} else {
V_65 |= F_18 ( 1 ) ;
V_65 |= F_19 ( 1 ) ;
}
F_20 ( V_81 , V_65 ) ;
V_66 = F_17 ( V_85 ) ;
if ( V_60 -> V_72 & V_86 ) {
V_66 |= V_87 ;
if ( V_63 -> V_77 ) {
V_66 |= V_88 ;
V_66 |= F_21 ( V_63 -> V_77 ) ;
} else
V_66 &= ~ V_88 ;
} else
V_66 &= ~ V_87 ;
F_20 ( V_85 , V_66 ) ;
V_67 = F_17 ( V_89 ) ;
if ( V_60 -> V_72 & V_90 )
V_67 &= ~ V_91 ;
else
V_67 |= V_91 ;
F_20 ( V_89 , V_67 ) ;
#if 0
mc_host_dyn_cntl = RREG32_PLL(MC_HOST_DYN_CNTL);
if (ps->misc & ATOM_PM_MISCINFO_DYNAMIC_MC_HOST_BLOCK_EN)
mc_host_dyn_cntl &= ~MC_HOST_FORCEON;
else
mc_host_dyn_cntl |= MC_HOST_FORCEON;
WREG32_PLL(MC_HOST_DYN_CNTL, mc_host_dyn_cntl);
#endif
V_68 = F_17 ( V_92 ) ;
if ( V_60 -> V_72 & V_93 )
V_68 |= V_94 ;
else
V_68 &= ~ V_94 ;
F_20 ( V_92 , V_68 ) ;
if ( ( V_2 -> V_95 & V_96 ) &&
! ( V_2 -> V_95 & V_97 ) &&
V_2 -> V_98 -> V_57 . V_99 &&
( V_60 -> V_100 !=
V_2 -> V_57 . V_61 [ V_2 -> V_57 . V_101 ] . V_100 ) ) {
F_22 ( V_2 ,
V_60 -> V_100 ) ;
F_8 ( L_2 , V_60 -> V_100 ) ;
}
}
void F_23 ( struct V_1 * V_2 )
{
struct V_29 * V_102 = V_2 -> V_102 ;
struct V_103 * V_3 ;
struct V_16 * V_16 ;
T_1 V_19 ;
F_24 (crtc, &ddev->mode_config.crtc_list, head) {
V_16 = F_25 ( V_3 ) ;
if ( V_16 -> V_104 ) {
V_19 = F_2 ( V_12 + V_16 -> V_21 ) ;
V_19 |= V_105 ;
F_6 ( V_12 + V_16 -> V_21 , V_19 ) ;
}
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_29 * V_102 = V_2 -> V_102 ;
struct V_103 * V_3 ;
struct V_16 * V_16 ;
T_1 V_19 ;
F_24 (crtc, &ddev->mode_config.crtc_list, head) {
V_16 = F_25 ( V_3 ) ;
if ( V_16 -> V_104 ) {
V_19 = F_2 ( V_12 + V_16 -> V_21 ) ;
V_19 &= ~ V_105 ;
F_6 ( V_12 + V_16 -> V_21 , V_19 ) ;
}
}
}
bool F_27 ( struct V_1 * V_2 , enum V_106 V_107 )
{
T_1 V_19 ;
bool V_108 = false ;
switch ( V_107 ) {
case V_109 :
V_19 = F_2 ( V_110 ) ;
if ( F_28 ( V_19 ) )
V_108 = true ;
break;
case V_111 :
V_19 = F_2 ( V_112 ) ;
if ( F_29 ( V_19 ) )
V_108 = true ;
break;
default:
break;
}
return V_108 ;
}
void F_30 ( struct V_1 * V_2 ,
enum V_106 V_107 )
{
T_1 V_19 ;
bool V_108 = F_27 ( V_2 , V_107 ) ;
switch ( V_107 ) {
case V_109 :
V_19 = F_2 ( V_113 ) ;
if ( V_108 )
V_19 &= ~ F_31 ( 1 ) ;
else
V_19 |= F_31 ( 1 ) ;
F_6 ( V_113 , V_19 ) ;
break;
case V_111 :
V_19 = F_2 ( V_114 ) ;
if ( V_108 )
V_19 &= ~ F_32 ( 1 ) ;
else
V_19 |= F_32 ( 1 ) ;
F_6 ( V_114 , V_19 ) ;
break;
default:
break;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_102 ;
struct V_33 * V_34 ;
unsigned V_115 = 0 ;
F_24 (connector, &dev->mode_config.connector_list, head) {
struct V_39 * V_39 = F_13 ( V_34 ) ;
switch ( V_39 -> V_107 . V_107 ) {
case V_109 :
F_6 ( V_116 ,
F_34 ( 1 ) ) ;
break;
case V_111 :
F_6 ( V_117 ,
F_35 ( 1 ) ) ;
break;
default:
break;
}
V_115 |= 1 << V_39 -> V_107 . V_107 ;
F_36 ( V_2 , V_39 -> V_107 . V_107 ) ;
}
F_37 ( V_2 , V_115 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_102 ;
struct V_33 * V_34 ;
unsigned V_118 = 0 ;
F_24 (connector, &dev->mode_config.connector_list, head) {
struct V_39 * V_39 = F_13 ( V_34 ) ;
switch ( V_39 -> V_107 . V_107 ) {
case V_109 :
F_6 ( V_116 ,
F_34 ( 0 ) ) ;
break;
case V_111 :
F_6 ( V_117 ,
F_35 ( 0 ) ) ;
break;
default:
break;
}
V_118 |= 1 << V_39 -> V_107 . V_107 ;
}
F_39 ( V_2 , V_118 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_119 V_120 ;
T_1 V_121 , V_19 ;
int V_122 = 0 ;
V_121 = F_2 ( V_123 ) ;
if ( ! F_41 ( V_121 ) ) {
return 0 ;
}
F_42 ( V_2 , & V_120 ) ;
V_121 = F_2 ( V_123 ) ;
F_43 ( V_2 -> V_30 , L_3 , V_124 , __LINE__ , V_121 ) ;
F_6 ( V_125 , 0 ) ;
V_19 = F_2 ( V_126 ) ;
F_6 ( V_126 , V_19 | V_127 ) ;
F_6 ( V_128 , 0 ) ;
F_6 ( V_129 , 0 ) ;
F_6 ( V_126 , V_19 ) ;
F_44 ( V_2 -> V_130 ) ;
F_45 ( V_2 -> V_130 ) ;
F_46 ( 1 ) ;
F_6 ( V_131 , F_47 ( 1 ) |
F_48 ( 1 ) ) ;
F_2 ( V_131 ) ;
F_46 ( 500 ) ;
F_6 ( V_131 , 0 ) ;
F_46 ( 1 ) ;
V_121 = F_2 ( V_123 ) ;
F_43 ( V_2 -> V_30 , L_3 , V_124 , __LINE__ , V_121 ) ;
F_6 ( V_131 , F_49 ( 1 ) ) ;
F_2 ( V_131 ) ;
F_46 ( 500 ) ;
F_6 ( V_131 , 0 ) ;
F_46 ( 1 ) ;
V_121 = F_2 ( V_123 ) ;
F_43 ( V_2 -> V_30 , L_3 , V_124 , __LINE__ , V_121 ) ;
F_6 ( V_131 , F_50 ( 1 ) ) ;
F_2 ( V_131 ) ;
F_46 ( 500 ) ;
F_6 ( V_131 , 0 ) ;
F_46 ( 1 ) ;
V_121 = F_2 ( V_123 ) ;
F_43 ( V_2 -> V_30 , L_3 , V_124 , __LINE__ , V_121 ) ;
F_51 ( V_2 -> V_130 ) ;
if ( F_52 ( V_121 ) || F_53 ( V_121 ) ) {
F_54 ( V_2 -> V_30 , L_4 ) ;
V_122 = - 1 ;
} else
F_43 ( V_2 -> V_30 , L_5 ) ;
F_55 ( V_2 , & V_120 ) ;
return V_122 ;
}
void F_56 ( struct V_1 * V_2 )
{
T_3 V_19 ;
V_19 = F_57 ( V_132 ) ;
V_19 &= V_133 & V_134 ;
F_58 ( V_132 , V_19 ) ;
V_19 = F_57 ( V_132 ) ;
V_19 |= F_59 ( 1 ) | F_60 ( 1 ) ;
F_58 ( V_132 , V_19 ) ;
V_19 = F_57 ( V_132 ) ;
V_19 &= V_133 & V_134 ;
F_58 ( V_132 , V_19 ) ;
V_19 = F_57 ( V_132 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_135 ;
if ( V_2 -> V_136 . V_137 ) {
F_62 ( 1 , L_6 ) ;
return 0 ;
}
V_135 = F_63 ( V_2 ) ;
if ( V_135 ) {
return V_135 ;
}
V_2 -> V_136 . V_138 = V_2 -> V_136 . V_139 * 8 ;
return F_64 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
T_1 V_19 ;
int V_135 , V_10 ;
if ( V_2 -> V_136 . V_137 == NULL ) {
F_54 ( V_2 -> V_30 , L_7 ) ;
return - V_140 ;
}
V_135 = F_66 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_19 = F_2 ( V_141 ) & ~ V_142 ;
F_6 ( V_141 , V_19 ) ;
F_58 ( V_132 ,
( F_67 ( 6 ) |
F_68 ( 6 ) ) ) ;
for ( V_10 = 0 ; V_10 < 19 ; V_10 ++ ) {
F_58 ( V_143 + V_10 ,
F_69 ( 1 ) |
F_70 (
V_144 ) |
F_71 (
V_145 ) |
F_72 ( 3 ) |
F_73 ( 1 ) |
F_74 ( 3 ) ) ;
}
F_58 ( V_146 ,
F_75 ( 1 ) |
F_76 ( V_147 ) ) ;
for ( V_10 = 1 ; V_10 < 8 ; V_10 ++ )
F_58 ( V_146 + V_10 , 0 ) ;
F_58 ( V_148 ,
V_2 -> V_136 . V_149 ) ;
F_58 ( V_150 , V_2 -> V_151 . V_152 ) ;
F_58 ( V_153 , V_2 -> V_151 . V_154 ) ;
F_58 ( V_155 , 0 ) ;
F_58 ( V_156 , V_2 -> V_151 . V_157 ) ;
F_58 ( V_158 , V_2 -> V_151 . V_159 ) ;
V_19 = F_57 ( V_132 ) ;
F_58 ( V_132 , ( V_19 | F_77 ( 1 ) ) ) ;
V_19 = F_57 ( V_160 ) ;
F_58 ( V_160 , ( V_19 | F_78 ( 1 ) ) ) ;
F_56 ( V_2 ) ;
F_79 ( L_8 ,
( unsigned ) ( V_2 -> V_151 . V_161 >> 20 ) ,
( unsigned long long ) V_2 -> V_136 . V_149 ) ;
V_2 -> V_136 . V_162 = true ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
T_1 V_19 ;
F_58 ( V_132 , 0 ) ;
V_19 = F_57 ( V_160 ) ;
F_58 ( V_160 , V_19 & V_163 ) ;
F_81 ( V_2 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_83 ( V_2 ) ;
F_80 ( V_2 ) ;
F_84 ( V_2 ) ;
}
T_4 F_85 ( T_4 V_164 , T_3 V_95 )
{
V_164 = V_164 & 0xFFFFFFFFFFFFF000ULL ;
V_164 |= V_165 ;
if ( V_95 & V_166 )
V_164 |= V_167 ;
if ( V_95 & V_168 )
V_164 |= V_169 ;
if ( V_95 & V_170 )
V_164 |= V_171 ;
if ( V_95 & V_172 )
V_164 |= V_173 ;
return V_164 ;
}
void F_86 ( struct V_1 * V_2 , unsigned V_10 ,
T_4 V_174 )
{
void T_5 * V_175 = ( void * ) V_2 -> V_136 . V_175 ;
F_87 ( V_174 , V_175 + ( V_10 * 8 ) ) ;
}
int F_88 ( struct V_1 * V_2 )
{
T_3 V_19 = 0 ;
T_3 V_176 = 0 ;
T_1 V_177 = F_2 ( V_113 ) &
~ F_89 ( 1 ) ;
T_1 V_178 = F_2 ( V_114 ) &
~ F_90 ( 1 ) ;
T_1 V_179 ;
if ( F_91 ( V_2 ) )
V_179 = F_2 ( V_180 ) &
~ F_92 ( 1 ) ;
else
V_179 = 0 ;
if ( ! V_2 -> V_181 . V_182 ) {
F_62 ( 1 , L_9 ) ;
F_6 ( V_183 , 0 ) ;
return - V_140 ;
}
if ( F_93 ( & V_2 -> V_181 . V_184 [ V_185 ] ) ) {
V_19 |= F_94 ( 1 ) ;
}
if ( V_2 -> V_181 . V_186 [ 0 ] ||
F_93 ( & V_2 -> V_181 . V_187 [ 0 ] ) ) {
V_176 |= F_95 ( 1 ) ;
}
if ( V_2 -> V_181 . V_186 [ 1 ] ||
F_93 ( & V_2 -> V_181 . V_187 [ 1 ] ) ) {
V_176 |= F_96 ( 1 ) ;
}
if ( V_2 -> V_181 . V_107 [ 0 ] ) {
V_177 |= F_89 ( 1 ) ;
}
if ( V_2 -> V_181 . V_107 [ 1 ] ) {
V_178 |= F_90 ( 1 ) ;
}
if ( V_2 -> V_181 . V_188 [ 0 ] ) {
V_179 |= F_92 ( 1 ) ;
}
F_6 ( V_183 , V_19 ) ;
F_6 ( V_189 , V_176 ) ;
F_6 ( V_113 , V_177 ) ;
F_6 ( V_114 , V_178 ) ;
if ( F_91 ( V_2 ) )
F_6 ( V_180 , V_179 ) ;
F_2 ( V_183 ) ;
return 0 ;
}
static inline T_1 F_97 ( struct V_1 * V_2 )
{
T_3 V_190 = F_2 ( V_191 ) ;
T_3 V_192 = F_98 ( 1 ) ;
T_1 V_19 ;
if ( F_99 ( V_190 ) ) {
V_2 -> V_181 . V_193 . V_194 . V_195 = F_2 ( V_196 ) ;
if ( F_100 ( V_2 -> V_181 . V_193 . V_194 . V_195 ) ) {
F_6 ( V_197 ,
F_101 ( 1 ) ) ;
}
if ( F_102 ( V_2 -> V_181 . V_193 . V_194 . V_195 ) ) {
F_6 ( V_198 ,
F_103 ( 1 ) ) ;
}
if ( F_104 ( V_2 -> V_181 . V_193 . V_194 . V_195 ) ) {
V_19 = F_2 ( V_113 ) ;
V_19 |= F_105 ( 1 ) ;
F_6 ( V_113 , V_19 ) ;
}
if ( F_106 ( V_2 -> V_181 . V_193 . V_194 . V_195 ) ) {
V_19 = F_2 ( V_114 ) ;
V_19 |= F_107 ( 1 ) ;
F_6 ( V_114 , V_19 ) ;
}
} else {
V_2 -> V_181 . V_193 . V_194 . V_195 = 0 ;
}
if ( F_91 ( V_2 ) ) {
V_2 -> V_181 . V_193 . V_194 . V_199 = F_2 ( V_200 ) &
F_108 ( 1 ) ;
if ( F_109 ( V_2 -> V_181 . V_193 . V_194 . V_199 ) ) {
V_19 = F_2 ( V_180 ) ;
V_19 |= F_110 ( 1 ) ;
F_6 ( V_180 , V_19 ) ;
}
} else
V_2 -> V_181 . V_193 . V_194 . V_199 = 0 ;
if ( V_190 ) {
F_6 ( V_191 , V_190 ) ;
}
return V_190 & V_192 ;
}
void F_111 ( struct V_1 * V_2 )
{
T_1 V_179 = F_2 ( V_180 ) &
~ F_92 ( 1 ) ;
F_6 ( V_180 , V_179 ) ;
F_6 ( V_183 , 0 ) ;
F_6 ( V_189 , 0 ) ;
F_46 ( 1 ) ;
F_97 ( V_2 ) ;
}
int F_112 ( struct V_1 * V_2 )
{
T_1 V_121 , V_201 ;
bool V_202 = false ;
bool V_203 = false ;
V_121 = F_97 ( V_2 ) ;
if ( ! V_121 &&
! V_2 -> V_181 . V_193 . V_194 . V_195 &&
! V_2 -> V_181 . V_193 . V_194 . V_199 ) {
return V_204 ;
}
while ( V_121 ||
V_2 -> V_181 . V_193 . V_194 . V_195 ||
V_2 -> V_181 . V_193 . V_194 . V_199 ) {
if ( F_113 ( V_121 ) ) {
F_114 ( V_2 , V_185 ) ;
}
if ( F_100 ( V_2 -> V_181 . V_193 . V_194 . V_195 ) ) {
if ( V_2 -> V_181 . V_186 [ 0 ] ) {
F_115 ( V_2 -> V_102 , 0 ) ;
V_2 -> V_57 . V_205 = true ;
F_116 ( & V_2 -> V_181 . V_206 ) ;
}
if ( F_93 ( & V_2 -> V_181 . V_187 [ 0 ] ) )
F_117 ( V_2 , 0 ) ;
}
if ( F_102 ( V_2 -> V_181 . V_193 . V_194 . V_195 ) ) {
if ( V_2 -> V_181 . V_186 [ 1 ] ) {
F_115 ( V_2 -> V_102 , 1 ) ;
V_2 -> V_57 . V_205 = true ;
F_116 ( & V_2 -> V_181 . V_206 ) ;
}
if ( F_93 ( & V_2 -> V_181 . V_187 [ 1 ] ) )
F_117 ( V_2 , 1 ) ;
}
if ( F_104 ( V_2 -> V_181 . V_193 . V_194 . V_195 ) ) {
V_202 = true ;
F_8 ( L_10 ) ;
}
if ( F_106 ( V_2 -> V_181 . V_193 . V_194 . V_195 ) ) {
V_202 = true ;
F_8 ( L_11 ) ;
}
if ( F_109 ( V_2 -> V_181 . V_193 . V_194 . V_199 ) ) {
V_203 = true ;
F_8 ( L_12 ) ;
}
V_121 = F_97 ( V_2 ) ;
}
if ( V_202 )
F_118 ( & V_2 -> V_207 ) ;
if ( V_203 )
F_118 ( & V_2 -> V_208 ) ;
if ( V_2 -> V_209 ) {
switch ( V_2 -> V_210 ) {
case V_211 :
case V_212 :
case V_213 :
V_201 = F_2 ( V_141 ) & ~ V_214 ;
F_6 ( V_141 , V_201 ) ;
F_6 ( V_141 , V_201 | V_214 ) ;
break;
default:
F_6 ( V_215 , V_216 ) ;
break;
}
}
return V_217 ;
}
T_1 F_119 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 0 )
return F_2 ( V_218 ) ;
else
return F_2 ( V_219 ) ;
}
int F_120 ( struct V_1 * V_2 )
{
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
if ( F_121 ( F_57 ( V_220 ) ) )
return 0 ;
F_7 ( 1 ) ;
}
return - 1 ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_123 ( V_2 ) ;
if ( F_120 ( V_2 ) )
F_124 ( V_2 -> V_30 , L_13 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
T_2 V_221 ;
V_2 -> V_151 . V_222 = F_126 ( V_2 -> V_130 , 0 ) ;
V_2 -> V_151 . V_223 = F_127 ( V_2 -> V_130 , 0 ) ;
V_2 -> V_151 . V_224 = true ;
V_2 -> V_151 . V_225 = 128 ;
V_2 -> V_151 . V_226 = F_2 ( V_227 ) ;
V_2 -> V_151 . V_228 = V_2 -> V_151 . V_226 ;
V_2 -> V_151 . V_229 = V_2 -> V_151 . V_223 ;
V_2 -> V_151 . V_230 = F_128 ( V_2 ) ;
V_221 = F_57 ( V_231 ) ;
V_221 = F_129 ( V_221 ) << 16 ;
F_130 ( V_2 , & V_2 -> V_151 , V_221 ) ;
V_2 -> V_151 . V_232 = 0 ;
F_131 ( V_2 , & V_2 -> V_151 ) ;
F_132 ( V_2 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
struct V_233 * V_234 = NULL ;
struct V_233 * V_235 = NULL ;
T_1 V_236 , V_237 ;
if ( ! V_2 -> V_17 . V_238 )
return;
F_134 ( V_2 ) ;
if ( V_2 -> V_17 . V_18 [ 0 ] -> V_221 . V_104 )
V_234 = & V_2 -> V_17 . V_18 [ 0 ] -> V_221 . V_239 ;
if ( V_2 -> V_17 . V_18 [ 1 ] -> V_221 . V_104 )
V_235 = & V_2 -> V_17 . V_18 [ 1 ] -> V_221 . V_239 ;
F_135 ( V_2 , V_234 , V_235 ) ;
if ( V_2 -> V_240 == 2 ) {
V_236 = F_2 ( V_241 ) ;
V_237 = F_2 ( V_242 ) ;
V_236 |= F_136 ( 1 ) ;
V_237 |= F_137 ( 1 ) ;
F_6 ( V_241 , V_236 ) ;
F_6 ( V_243 , V_236 ) ;
F_6 ( V_242 , V_237 ) ;
F_6 ( V_244 , V_237 ) ;
}
}
T_3 F_138 ( struct V_1 * V_2 , T_3 V_74 )
{
unsigned long V_95 ;
T_1 V_135 ;
F_139 ( & V_2 -> V_245 , V_95 ) ;
F_6 ( V_246 , F_140 ( V_74 ) |
F_141 ( 1 ) ) ;
V_135 = F_2 ( V_247 ) ;
F_142 ( & V_2 -> V_245 , V_95 ) ;
return V_135 ;
}
void F_143 ( struct V_1 * V_2 , T_3 V_74 , T_3 V_248 )
{
unsigned long V_95 ;
F_139 ( & V_2 -> V_245 , V_95 ) ;
F_6 ( V_246 , F_140 ( V_74 ) |
F_141 ( 1 ) | F_144 ( 1 ) ) ;
F_6 ( V_247 , V_248 ) ;
F_142 ( & V_2 -> V_245 , V_95 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
if ( F_146 ( V_2 ) )
F_147 ( L_14 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
V_2 -> V_249 . V_250 . V_251 = V_252 ;
V_2 -> V_249 . V_250 . V_253 = F_149 ( V_252 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_119 V_120 ;
F_42 ( V_2 , & V_120 ) ;
if ( F_120 ( V_2 ) )
F_124 ( V_2 -> V_30 , L_13 ) ;
F_58 ( V_254 , 0x0FFFFFFF ) ;
F_58 ( V_255 , 0 ) ;
F_58 ( V_256 , 0 ) ;
F_58 ( V_231 ,
F_151 ( V_2 -> V_151 . V_157 >> 16 ) |
F_152 ( V_2 -> V_151 . V_159 >> 16 ) ) ;
F_6 ( V_257 ,
F_153 ( V_2 -> V_151 . V_157 >> 16 ) ) ;
F_55 ( V_2 , & V_120 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
int V_135 ;
F_150 ( V_2 ) ;
F_155 ( V_2 ) ;
F_122 ( V_2 ) ;
V_135 = F_65 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_156 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_157 ( V_2 , V_185 ) ;
if ( V_135 ) {
F_54 ( V_2 -> V_30 , L_15 , V_135 ) ;
return V_135 ;
}
if ( ! V_2 -> V_181 . V_182 ) {
V_135 = F_158 ( V_2 ) ;
if ( V_135 )
return V_135 ;
}
F_88 ( V_2 ) ;
V_2 -> V_249 . V_250 . V_258 = F_2 ( V_259 ) ;
V_135 = F_159 ( V_2 , 1024 * 1024 ) ;
if ( V_135 ) {
F_54 ( V_2 -> V_30 , L_16 , V_135 ) ;
return V_135 ;
}
V_135 = F_160 ( V_2 ) ;
if ( V_135 ) {
F_54 ( V_2 -> V_30 , L_17 , V_135 ) ;
return V_135 ;
}
V_135 = F_161 ( V_2 ) ;
if ( V_135 ) {
F_54 ( V_2 -> V_30 , L_18 ) ;
return V_135 ;
}
return 0 ;
}
int F_162 ( struct V_1 * V_2 )
{
int V_135 ;
F_80 ( V_2 ) ;
F_155 ( V_2 ) ;
if ( F_163 ( V_2 ) ) {
F_124 ( V_2 -> V_30 , L_19 ,
F_2 ( V_123 ) ,
F_2 ( V_260 ) ) ;
}
F_164 ( V_2 -> V_17 . V_261 ) ;
F_155 ( V_2 ) ;
F_165 ( V_2 ) ;
V_2 -> V_262 = true ;
V_135 = F_154 ( V_2 ) ;
if ( V_135 ) {
V_2 -> V_262 = false ;
}
return V_135 ;
}
int F_166 ( struct V_1 * V_2 )
{
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_111 ( V_2 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
void F_171 ( struct V_1 * V_2 )
{
F_172 ( V_2 ) ;
F_168 ( V_2 ) ;
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 ) ;
F_82 ( V_2 ) ;
F_177 ( V_2 ) ;
F_178 ( V_2 ) ;
F_179 ( V_2 ) ;
F_180 ( V_2 ) ;
F_181 ( V_2 -> V_263 ) ;
V_2 -> V_263 = NULL ;
}
int F_182 ( struct V_1 * V_2 )
{
int V_135 ;
F_183 ( V_2 ) ;
F_184 ( V_2 ) ;
F_165 ( V_2 ) ;
F_185 ( V_2 ) ;
if ( ! F_186 ( V_2 ) ) {
if ( F_187 ( V_2 ) )
return - V_140 ;
}
if ( V_2 -> V_264 ) {
V_135 = F_188 ( V_2 ) ;
if ( V_135 )
return V_135 ;
} else {
F_54 ( V_2 -> V_30 , L_20 ) ;
return - V_140 ;
}
if ( F_163 ( V_2 ) ) {
F_124 ( V_2 -> V_30 ,
L_19 ,
F_2 ( V_123 ) ,
F_2 ( V_260 ) ) ;
}
if ( F_189 ( V_2 ) == false )
return - V_140 ;
F_190 ( V_2 -> V_102 ) ;
F_125 ( V_2 ) ;
F_145 ( V_2 ) ;
V_135 = F_191 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_192 ( V_2 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_61 ( V_2 ) ;
if ( V_135 )
return V_135 ;
F_148 ( V_2 ) ;
F_193 ( V_2 ) ;
V_2 -> V_262 = true ;
V_135 = F_154 ( V_2 ) ;
if ( V_135 ) {
F_54 ( V_2 -> V_30 , L_21 ) ;
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
F_175 ( V_2 ) ;
F_82 ( V_2 ) ;
F_177 ( V_2 ) ;
V_2 -> V_262 = false ;
}
return 0 ;
}
