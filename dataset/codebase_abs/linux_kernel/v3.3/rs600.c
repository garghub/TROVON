void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( V_2 , V_3 ) ;
}
T_1 F_5 ( struct V_1 * V_2 , int V_4 , T_2 V_5 )
{
struct V_6 * V_6 = V_2 -> V_7 . V_8 [ V_4 ] ;
T_1 V_9 = F_6 ( V_10 + V_6 -> V_11 ) ;
int V_12 ;
V_9 |= V_13 ;
F_7 ( V_10 + V_6 -> V_11 , V_9 ) ;
F_7 ( V_14 + V_6 -> V_11 ,
( T_1 ) V_5 ) ;
F_7 ( V_15 + V_6 -> V_11 ,
( T_1 ) V_5 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
if ( F_6 ( V_10 + V_6 -> V_11 ) & V_17 )
break;
F_8 ( 1 ) ;
}
F_9 ( L_1 ) ;
V_9 &= ~ V_13 ;
F_7 ( V_10 + V_6 -> V_11 , V_9 ) ;
return F_6 ( V_10 + V_6 -> V_11 ) & V_17 ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_18 = V_2 -> V_19 . V_20 ;
struct V_21 * V_22 = & V_2 -> V_19 . V_23 [ V_18 ] ;
struct V_24 * V_25 = & V_22 -> V_26 [ 0 ] . V_25 ;
T_1 V_9 , V_27 , V_28 ;
T_1 V_29 , V_30 ;
if ( ( V_25 -> type == V_31 ) && ( V_25 -> V_32 . V_33 ) ) {
if ( V_22 -> V_34 & V_35 ) {
V_9 = F_6 ( V_25 -> V_32 . V_36 ) ;
if ( V_25 -> V_37 )
V_9 |= V_25 -> V_32 . V_38 ;
else
V_9 &= ~ ( V_25 -> V_32 . V_38 ) ;
F_7 ( V_25 -> V_32 . V_36 , V_9 ) ;
if ( V_25 -> V_39 )
F_8 ( V_25 -> V_39 ) ;
} else {
V_9 = F_6 ( V_25 -> V_32 . V_36 ) ;
if ( V_25 -> V_37 )
V_9 &= ~ V_25 -> V_32 . V_38 ;
else
V_9 |= V_25 -> V_32 . V_38 ;
F_7 ( V_25 -> V_32 . V_36 , V_9 ) ;
if ( V_25 -> V_39 )
F_8 ( V_25 -> V_39 ) ;
}
} else if ( V_25 -> type == V_40 )
F_11 ( V_2 , V_25 -> V_41 , V_42 ) ;
V_27 = F_12 ( V_43 ) ;
V_27 &= ~ F_13 ( 0xf ) ;
V_27 &= ~ F_14 ( 0xf ) ;
if ( V_22 -> V_34 & V_44 ) {
if ( V_22 -> V_34 & V_45 ) {
V_27 |= F_13 ( 2 ) ;
V_27 |= F_14 ( 2 ) ;
} else if ( V_22 -> V_34 & V_46 ) {
V_27 |= F_13 ( 4 ) ;
V_27 |= F_14 ( 4 ) ;
}
} else {
V_27 |= F_13 ( 1 ) ;
V_27 |= F_14 ( 1 ) ;
}
F_15 ( V_43 , V_27 ) ;
V_28 = F_12 ( V_47 ) ;
if ( V_22 -> V_34 & V_48 ) {
V_28 |= V_49 ;
if ( V_25 -> V_39 ) {
V_28 |= V_50 ;
V_28 |= F_16 ( V_25 -> V_39 ) ;
} else
V_28 &= ~ V_50 ;
} else
V_28 &= ~ V_49 ;
F_15 ( V_47 , V_28 ) ;
V_29 = F_12 ( V_51 ) ;
if ( V_22 -> V_34 & V_52 )
V_29 &= ~ V_53 ;
else
V_29 |= V_53 ;
F_15 ( V_51 , V_29 ) ;
#if 0
mc_host_dyn_cntl = RREG32_PLL(MC_HOST_DYN_CNTL);
if (ps->misc & ATOM_PM_MISCINFO_DYNAMIC_MC_HOST_BLOCK_EN)
mc_host_dyn_cntl &= ~MC_HOST_FORCEON;
else
mc_host_dyn_cntl |= MC_HOST_FORCEON;
WREG32_PLL(MC_HOST_DYN_CNTL, mc_host_dyn_cntl);
#endif
V_30 = F_12 ( V_54 ) ;
if ( V_22 -> V_34 & V_55 )
V_30 |= V_56 ;
else
V_30 &= ~ V_56 ;
F_15 ( V_54 , V_30 ) ;
if ( ( V_2 -> V_57 & V_58 ) &&
! ( V_2 -> V_57 & V_59 ) &&
V_2 -> V_60 -> V_61 &&
( V_22 -> V_62 !=
V_2 -> V_19 . V_23 [ V_2 -> V_19 . V_63 ] . V_62 ) ) {
F_17 ( V_2 ,
V_22 -> V_62 ) ;
F_9 ( L_2 , V_22 -> V_62 ) ;
}
}
void F_18 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_66 * V_3 ;
struct V_6 * V_6 ;
T_1 V_9 ;
F_19 (crtc, &ddev->mode_config.crtc_list, head) {
V_6 = F_20 ( V_3 ) ;
if ( V_6 -> V_67 ) {
V_9 = F_6 ( V_68 + V_6 -> V_11 ) ;
V_9 |= V_69 ;
F_7 ( V_68 + V_6 -> V_11 , V_9 ) ;
}
}
}
void F_21 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_66 * V_3 ;
struct V_6 * V_6 ;
T_1 V_9 ;
F_19 (crtc, &ddev->mode_config.crtc_list, head) {
V_6 = F_20 ( V_3 ) ;
if ( V_6 -> V_67 ) {
V_9 = F_6 ( V_68 + V_6 -> V_11 ) ;
V_9 &= ~ V_69 ;
F_7 ( V_68 + V_6 -> V_11 , V_9 ) ;
}
}
}
bool F_22 ( struct V_1 * V_2 , enum V_70 V_71 )
{
T_1 V_9 ;
bool V_72 = false ;
switch ( V_71 ) {
case V_73 :
V_9 = F_6 ( V_74 ) ;
if ( F_23 ( V_9 ) )
V_72 = true ;
break;
case V_75 :
V_9 = F_6 ( V_76 ) ;
if ( F_24 ( V_9 ) )
V_72 = true ;
break;
default:
break;
}
return V_72 ;
}
void F_25 ( struct V_1 * V_2 ,
enum V_70 V_71 )
{
T_1 V_9 ;
bool V_72 = F_22 ( V_2 , V_71 ) ;
switch ( V_71 ) {
case V_73 :
V_9 = F_6 ( V_77 ) ;
if ( V_72 )
V_9 &= ~ F_26 ( 1 ) ;
else
V_9 |= F_26 ( 1 ) ;
F_7 ( V_77 , V_9 ) ;
break;
case V_75 :
V_9 = F_6 ( V_78 ) ;
if ( V_72 )
V_9 &= ~ F_27 ( 1 ) ;
else
V_9 |= F_27 ( 1 ) ;
F_7 ( V_78 , V_9 ) ;
break;
default:
break;
}
}
void F_28 ( struct V_1 * V_2 )
{
struct V_64 * V_79 = V_2 -> V_65 ;
struct V_80 * V_81 ;
F_19 (connector, &dev->mode_config.connector_list, head) {
struct V_82 * V_82 = F_29 ( V_81 ) ;
switch ( V_82 -> V_71 . V_71 ) {
case V_73 :
F_7 ( V_83 ,
F_30 ( 1 ) ) ;
V_2 -> V_84 . V_71 [ 0 ] = true ;
break;
case V_75 :
F_7 ( V_85 ,
F_31 ( 1 ) ) ;
V_2 -> V_84 . V_71 [ 1 ] = true ;
break;
default:
break;
}
F_32 ( V_2 , V_82 -> V_71 . V_71 ) ;
}
if ( V_2 -> V_84 . V_86 )
F_33 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_64 * V_79 = V_2 -> V_65 ;
struct V_80 * V_81 ;
F_19 (connector, &dev->mode_config.connector_list, head) {
struct V_82 * V_82 = F_29 ( V_81 ) ;
switch ( V_82 -> V_71 . V_71 ) {
case V_73 :
F_7 ( V_83 ,
F_30 ( 0 ) ) ;
V_2 -> V_84 . V_71 [ 0 ] = false ;
break;
case V_75 :
F_7 ( V_85 ,
F_31 ( 0 ) ) ;
V_2 -> V_84 . V_71 [ 1 ] = false ;
break;
default:
break;
}
}
}
int F_35 ( struct V_1 * V_2 )
{
struct V_87 V_88 ;
T_1 V_89 , V_9 ;
int V_90 = 0 ;
V_89 = F_6 ( V_91 ) ;
if ( ! F_36 ( V_89 ) ) {
return 0 ;
}
F_37 ( V_2 , & V_88 ) ;
V_89 = F_6 ( V_91 ) ;
F_38 ( V_2 -> V_79 , L_3 , V_92 , __LINE__ , V_89 ) ;
F_7 ( V_93 , 0 ) ;
V_9 = F_6 ( V_94 ) ;
F_7 ( V_94 , V_9 | V_95 ) ;
F_7 ( V_96 , 0 ) ;
F_7 ( V_97 , 0 ) ;
F_7 ( V_94 , V_9 ) ;
F_39 ( V_2 -> V_98 ) ;
F_40 ( V_2 -> V_98 ) ;
F_41 ( 1 ) ;
F_7 ( V_99 , F_42 ( 1 ) |
F_43 ( 1 ) ) ;
F_6 ( V_99 ) ;
F_41 ( 500 ) ;
F_7 ( V_99 , 0 ) ;
F_41 ( 1 ) ;
V_89 = F_6 ( V_91 ) ;
F_38 ( V_2 -> V_79 , L_3 , V_92 , __LINE__ , V_89 ) ;
F_7 ( V_99 , F_44 ( 1 ) ) ;
F_6 ( V_99 ) ;
F_41 ( 500 ) ;
F_7 ( V_99 , 0 ) ;
F_41 ( 1 ) ;
V_89 = F_6 ( V_91 ) ;
F_38 ( V_2 -> V_79 , L_3 , V_92 , __LINE__ , V_89 ) ;
F_7 ( V_99 , F_45 ( 1 ) ) ;
F_6 ( V_99 ) ;
F_41 ( 500 ) ;
F_7 ( V_99 , 0 ) ;
F_41 ( 1 ) ;
V_89 = F_6 ( V_91 ) ;
F_38 ( V_2 -> V_79 , L_3 , V_92 , __LINE__ , V_89 ) ;
F_46 ( V_2 -> V_98 ) ;
if ( F_47 ( V_89 ) || F_48 ( V_89 ) ) {
F_49 ( V_2 -> V_79 , L_4 ) ;
V_2 -> V_100 = true ;
V_90 = - 1 ;
} else
F_38 ( V_2 -> V_79 , L_5 ) ;
F_50 ( V_2 , & V_88 ) ;
return V_90 ;
}
void F_51 ( struct V_1 * V_2 )
{
T_3 V_9 ;
V_9 = F_52 ( V_101 ) ;
V_9 &= V_102 & V_103 ;
F_53 ( V_101 , V_9 ) ;
V_9 = F_52 ( V_101 ) ;
V_9 |= F_54 ( 1 ) | F_55 ( 1 ) ;
F_53 ( V_101 , V_9 ) ;
V_9 = F_52 ( V_101 ) ;
V_9 &= V_102 & V_103 ;
F_53 ( V_101 , V_9 ) ;
V_9 = F_52 ( V_101 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_104 ;
if ( V_2 -> V_105 . V_106 ) {
F_57 ( 1 , L_6 ) ;
return 0 ;
}
V_104 = F_58 ( V_2 ) ;
if ( V_104 ) {
return V_104 ;
}
V_2 -> V_105 . V_107 = V_2 -> V_105 . V_108 * 8 ;
return F_59 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_1 V_9 ;
int V_104 , V_12 ;
if ( V_2 -> V_105 . V_106 == NULL ) {
F_49 ( V_2 -> V_79 , L_7 ) ;
return - V_109 ;
}
V_104 = F_61 ( V_2 ) ;
if ( V_104 )
return V_104 ;
F_62 ( V_2 ) ;
V_9 = F_6 ( V_110 ) & ~ V_111 ;
F_7 ( V_110 , V_9 ) ;
F_53 ( V_101 ,
( F_63 ( 6 ) |
F_64 ( 6 ) ) ) ;
for ( V_12 = 0 ; V_12 < 19 ; V_12 ++ ) {
F_53 ( V_112 + V_12 ,
F_65 ( 1 ) |
F_66 (
V_113 ) |
F_67 (
V_114 ) |
F_68 ( 3 ) |
F_69 ( 1 ) |
F_70 ( 3 ) ) ;
}
F_53 ( V_115 ,
F_71 ( 1 ) |
F_72 ( V_116 ) ) ;
for ( V_12 = 1 ; V_12 < 8 ; V_12 ++ )
F_53 ( V_115 + V_12 , 0 ) ;
F_53 ( V_117 ,
V_2 -> V_105 . V_118 ) ;
F_53 ( V_119 , V_2 -> V_120 . V_121 ) ;
F_53 ( V_122 , V_2 -> V_120 . V_123 ) ;
F_53 ( V_124 , 0 ) ;
F_53 ( V_125 , V_2 -> V_120 . V_126 ) ;
F_53 ( V_127 , V_2 -> V_120 . V_128 ) ;
V_9 = F_52 ( V_101 ) ;
F_53 ( V_101 , ( V_9 | F_73 ( 1 ) ) ) ;
V_9 = F_52 ( V_129 ) ;
F_53 ( V_129 , ( V_9 | F_74 ( 1 ) ) ) ;
F_51 ( V_2 ) ;
F_75 ( L_8 ,
( unsigned ) ( V_2 -> V_120 . V_130 >> 20 ) ,
( unsigned long long ) V_2 -> V_105 . V_118 ) ;
V_2 -> V_105 . V_131 = true ;
return 0 ;
}
void F_76 ( struct V_1 * V_2 )
{
T_1 V_9 ;
F_53 ( V_101 , 0 ) ;
V_9 = F_52 ( V_129 ) ;
F_53 ( V_129 , V_9 & V_132 ) ;
F_77 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_79 ( V_2 ) ;
F_76 ( V_2 ) ;
F_80 ( V_2 ) ;
}
int F_81 ( struct V_1 * V_2 , int V_12 , T_4 V_133 )
{
void T_5 * V_134 = ( void * ) V_2 -> V_105 . V_134 ;
if ( V_12 < 0 || V_12 > V_2 -> V_105 . V_108 ) {
return - V_109 ;
}
V_133 = V_133 & 0xFFFFFFFFFFFFF000ULL ;
V_133 |= V_135 | V_136 | V_137 ;
V_133 |= V_138 | V_139 ;
F_82 ( V_133 , V_134 + ( V_12 * 8 ) ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
T_3 V_9 = 0 ;
T_3 V_140 = 0 ;
T_1 V_141 = F_6 ( V_77 ) &
~ F_83 ( 1 ) ;
T_1 V_142 = F_6 ( V_78 ) &
~ F_84 ( 1 ) ;
if ( ! V_2 -> V_84 . V_86 ) {
F_57 ( 1 , L_9 ) ;
F_7 ( V_143 , 0 ) ;
return - V_109 ;
}
if ( V_2 -> V_84 . V_144 [ V_145 ] ) {
V_9 |= F_85 ( 1 ) ;
}
if ( V_2 -> V_84 . V_146 ) {
V_9 |= F_86 ( 1 ) ;
}
if ( V_2 -> V_84 . V_147 [ 0 ] ||
V_2 -> V_84 . V_148 [ 0 ] ) {
V_140 |= F_87 ( 1 ) ;
}
if ( V_2 -> V_84 . V_147 [ 1 ] ||
V_2 -> V_84 . V_148 [ 1 ] ) {
V_140 |= F_88 ( 1 ) ;
}
if ( V_2 -> V_84 . V_71 [ 0 ] ) {
V_141 |= F_83 ( 1 ) ;
}
if ( V_2 -> V_84 . V_71 [ 1 ] ) {
V_142 |= F_84 ( 1 ) ;
}
F_7 ( V_143 , V_9 ) ;
F_7 ( V_149 , V_140 ) ;
F_7 ( V_77 , V_141 ) ;
F_7 ( V_78 , V_142 ) ;
return 0 ;
}
static inline T_1 F_89 ( struct V_1 * V_2 )
{
T_3 V_150 = F_6 ( V_151 ) ;
T_3 V_152 = F_90 ( 1 ) ;
T_1 V_9 ;
if ( V_2 -> V_84 . V_146 && F_91 ( V_2 ) ) {
if ( ! V_2 -> V_84 . V_153 )
V_152 |= F_92 ( 1 ) ;
}
if ( F_93 ( V_150 ) ) {
V_2 -> V_84 . V_154 . V_155 . V_156 = F_6 ( V_157 ) ;
if ( F_94 ( V_2 -> V_84 . V_154 . V_155 . V_156 ) ) {
F_7 ( V_158 ,
F_95 ( 1 ) ) ;
}
if ( F_96 ( V_2 -> V_84 . V_154 . V_155 . V_156 ) ) {
F_7 ( V_159 ,
F_97 ( 1 ) ) ;
}
if ( F_98 ( V_2 -> V_84 . V_154 . V_155 . V_156 ) ) {
V_9 = F_6 ( V_77 ) ;
V_9 |= F_99 ( 1 ) ;
F_7 ( V_77 , V_9 ) ;
}
if ( F_100 ( V_2 -> V_84 . V_154 . V_155 . V_156 ) ) {
V_9 = F_6 ( V_78 ) ;
V_9 |= F_101 ( 1 ) ;
F_7 ( V_78 , V_9 ) ;
}
} else {
V_2 -> V_84 . V_154 . V_155 . V_156 = 0 ;
}
if ( V_150 ) {
F_7 ( V_151 , V_150 ) ;
}
return V_150 & V_152 ;
}
void F_102 ( struct V_1 * V_2 )
{
F_7 ( V_143 , 0 ) ;
F_7 ( V_149 , 0 ) ;
F_41 ( 1 ) ;
F_89 ( V_2 ) ;
}
int F_103 ( struct V_1 * V_2 )
{
T_1 V_89 , V_160 ;
bool V_161 = false ;
V_2 -> V_84 . V_153 = false ;
V_89 = F_89 ( V_2 ) ;
if ( ! V_89 && ! V_2 -> V_84 . V_154 . V_155 . V_156 ) {
return V_162 ;
}
while ( V_89 || V_2 -> V_84 . V_154 . V_155 . V_156 ) {
if ( F_104 ( V_89 ) ) {
F_105 ( V_2 , V_145 ) ;
}
if ( F_106 ( V_89 ) ) {
V_2 -> V_84 . V_153 = true ;
V_2 -> V_19 . V_146 = true ;
F_107 ( & V_2 -> V_84 . V_163 ) ;
}
if ( F_94 ( V_2 -> V_84 . V_154 . V_155 . V_156 ) ) {
if ( V_2 -> V_84 . V_147 [ 0 ] ) {
F_108 ( V_2 -> V_65 , 0 ) ;
V_2 -> V_19 . V_164 = true ;
F_107 ( & V_2 -> V_84 . V_165 ) ;
}
if ( V_2 -> V_84 . V_148 [ 0 ] )
F_109 ( V_2 , 0 ) ;
}
if ( F_96 ( V_2 -> V_84 . V_154 . V_155 . V_156 ) ) {
if ( V_2 -> V_84 . V_147 [ 1 ] ) {
F_108 ( V_2 -> V_65 , 1 ) ;
V_2 -> V_19 . V_164 = true ;
F_107 ( & V_2 -> V_84 . V_165 ) ;
}
if ( V_2 -> V_84 . V_148 [ 1 ] )
F_109 ( V_2 , 1 ) ;
}
if ( F_98 ( V_2 -> V_84 . V_154 . V_155 . V_156 ) ) {
V_161 = true ;
F_9 ( L_10 ) ;
}
if ( F_100 ( V_2 -> V_84 . V_154 . V_155 . V_156 ) ) {
V_161 = true ;
F_9 ( L_11 ) ;
}
V_89 = F_89 ( V_2 ) ;
}
V_2 -> V_84 . V_153 = false ;
if ( V_161 )
F_110 ( & V_2 -> V_166 ) ;
if ( V_2 -> V_167 ) {
switch ( V_2 -> V_168 ) {
case V_169 :
case V_170 :
case V_171 :
V_160 = F_6 ( V_110 ) & ~ V_172 ;
F_7 ( V_110 , V_160 ) ;
F_7 ( V_110 , V_160 | V_172 ) ;
break;
default:
F_7 ( V_173 , V_174 ) ;
break;
}
}
return V_175 ;
}
T_1 F_111 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 0 )
return F_6 ( V_176 ) ;
else
return F_6 ( V_177 ) ;
}
int F_112 ( struct V_1 * V_2 )
{
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
if ( F_113 ( F_52 ( V_178 ) ) )
return 0 ;
F_8 ( 1 ) ;
}
return - 1 ;
}
void F_114 ( struct V_1 * V_2 )
{
F_115 ( V_2 ) ;
if ( F_112 ( V_2 ) )
F_116 ( V_2 -> V_79 , L_12 ) ;
}
void F_117 ( struct V_1 * V_2 )
{
T_2 V_179 ;
V_2 -> V_120 . V_180 = F_118 ( V_2 -> V_98 , 0 ) ;
V_2 -> V_120 . V_181 = F_119 ( V_2 -> V_98 , 0 ) ;
V_2 -> V_120 . V_182 = true ;
V_2 -> V_120 . V_183 = 128 ;
V_2 -> V_120 . V_184 = F_6 ( V_185 ) ;
V_2 -> V_120 . V_186 = V_2 -> V_120 . V_184 ;
V_2 -> V_120 . V_187 = V_2 -> V_120 . V_181 ;
V_2 -> V_120 . V_188 = F_120 ( V_2 ) ;
V_179 = F_52 ( V_189 ) ;
V_179 = F_121 ( V_179 ) << 16 ;
F_122 ( V_2 , & V_2 -> V_120 , V_179 ) ;
V_2 -> V_120 . V_190 = 0 ;
F_123 ( V_2 , & V_2 -> V_120 ) ;
F_124 ( V_2 ) ;
}
void F_125 ( struct V_1 * V_2 )
{
struct V_191 * V_192 = NULL ;
struct V_191 * V_193 = NULL ;
T_1 V_194 , V_195 ;
F_126 ( V_2 ) ;
if ( V_2 -> V_7 . V_8 [ 0 ] -> V_179 . V_67 )
V_192 = & V_2 -> V_7 . V_8 [ 0 ] -> V_179 . V_196 ;
if ( V_2 -> V_7 . V_8 [ 1 ] -> V_179 . V_67 )
V_193 = & V_2 -> V_7 . V_8 [ 1 ] -> V_179 . V_196 ;
F_127 ( V_2 , V_192 , V_193 ) ;
if ( V_2 -> V_197 == 2 ) {
V_194 = F_6 ( V_198 ) ;
V_195 = F_6 ( V_199 ) ;
V_194 |= F_128 ( 1 ) ;
V_195 |= F_129 ( 1 ) ;
F_7 ( V_198 , V_194 ) ;
F_7 ( V_200 , V_194 ) ;
F_7 ( V_199 , V_195 ) ;
F_7 ( V_201 , V_195 ) ;
}
}
T_3 F_130 ( struct V_1 * V_2 , T_3 V_36 )
{
F_7 ( V_202 , F_131 ( V_36 ) |
F_132 ( 1 ) ) ;
return F_6 ( V_203 ) ;
}
void F_133 ( struct V_1 * V_2 , T_3 V_36 , T_3 V_204 )
{
F_7 ( V_202 , F_131 ( V_36 ) |
F_132 ( 1 ) | F_134 ( 1 ) ) ;
F_7 ( V_203 , V_204 ) ;
}
void F_135 ( struct V_1 * V_2 )
{
if ( F_136 ( V_2 ) )
F_137 ( L_13 ) ;
}
void F_138 ( struct V_1 * V_2 )
{
V_2 -> V_205 . V_206 . V_207 = V_208 ;
V_2 -> V_205 . V_206 . V_209 = F_139 ( V_208 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_87 V_88 ;
F_37 ( V_2 , & V_88 ) ;
if ( F_112 ( V_2 ) )
F_116 ( V_2 -> V_79 , L_12 ) ;
F_53 ( V_210 , 0x0FFFFFFF ) ;
F_53 ( V_211 , 0 ) ;
F_53 ( V_212 , 0 ) ;
F_53 ( V_189 ,
F_141 ( V_2 -> V_120 . V_126 >> 16 ) |
F_142 ( V_2 -> V_120 . V_128 >> 16 ) ) ;
F_7 ( V_213 ,
F_143 ( V_2 -> V_120 . V_126 >> 16 ) ) ;
F_50 ( V_2 , & V_88 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_104 ;
F_140 ( V_2 ) ;
F_145 ( V_2 ) ;
F_114 ( V_2 ) ;
V_104 = F_60 ( V_2 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_146 ( V_2 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_147 ( V_2 , V_145 ) ;
if ( V_104 ) {
F_49 ( V_2 -> V_79 , L_14 , V_104 ) ;
return V_104 ;
}
F_33 ( V_2 ) ;
V_2 -> V_205 . V_206 . V_214 = F_6 ( V_215 ) ;
V_104 = F_148 ( V_2 , 1024 * 1024 ) ;
if ( V_104 ) {
F_49 ( V_2 -> V_79 , L_15 , V_104 ) ;
return V_104 ;
}
V_104 = F_149 ( V_2 ) ;
if ( V_104 ) {
F_49 ( V_2 -> V_79 , L_16 ) ;
return V_104 ;
}
V_104 = F_150 ( V_2 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_151 ( V_2 ) ;
if ( V_104 ) {
F_49 ( V_2 -> V_79 , L_17 , V_104 ) ;
V_2 -> V_216 = false ;
return V_104 ;
}
return 0 ;
}
int F_152 ( struct V_1 * V_2 )
{
int V_104 ;
F_76 ( V_2 ) ;
F_145 ( V_2 ) ;
if ( F_153 ( V_2 ) ) {
F_116 ( V_2 -> V_79 , L_18 ,
F_6 ( V_91 ) ,
F_6 ( V_217 ) ) ;
}
F_154 ( V_2 -> V_7 . V_218 ) ;
F_145 ( V_2 ) ;
F_155 ( V_2 ) ;
V_2 -> V_216 = true ;
V_104 = F_144 ( V_2 ) ;
if ( V_104 ) {
V_2 -> V_216 = false ;
}
return V_104 ;
}
int F_156 ( struct V_1 * V_2 )
{
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
F_102 ( V_2 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
void F_161 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
F_162 ( V_2 ) ;
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
F_165 ( V_2 ) ;
F_78 ( V_2 ) ;
F_166 ( V_2 ) ;
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 -> V_219 ) ;
V_2 -> V_219 = NULL ;
}
int F_171 ( struct V_1 * V_2 )
{
int V_104 ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
F_155 ( V_2 ) ;
F_174 ( V_2 ) ;
if ( ! F_175 ( V_2 ) ) {
if ( F_176 ( V_2 ) )
return - V_109 ;
}
if ( V_2 -> V_220 ) {
V_104 = F_177 ( V_2 ) ;
if ( V_104 )
return V_104 ;
} else {
F_49 ( V_2 -> V_79 , L_19 ) ;
return - V_109 ;
}
if ( F_153 ( V_2 ) ) {
F_116 ( V_2 -> V_79 ,
L_18 ,
F_6 ( V_91 ) ,
F_6 ( V_217 ) ) ;
}
if ( F_178 ( V_2 ) == false )
return - V_109 ;
F_179 ( V_2 -> V_65 ) ;
F_117 ( V_2 ) ;
F_135 ( V_2 ) ;
V_104 = F_180 ( V_2 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_181 ( V_2 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_182 ( V_2 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_56 ( V_2 ) ;
if ( V_104 )
return V_104 ;
F_138 ( V_2 ) ;
V_104 = F_183 ( V_2 ) ;
V_2 -> V_216 = true ;
if ( V_104 ) {
F_49 ( V_2 -> V_79 , L_20 , V_104 ) ;
V_2 -> V_216 = false ;
}
V_104 = F_144 ( V_2 ) ;
if ( V_104 ) {
F_49 ( V_2 -> V_79 , L_21 ) ;
F_162 ( V_2 ) ;
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
F_78 ( V_2 ) ;
F_166 ( V_2 ) ;
V_2 -> V_216 = false ;
}
return 0 ;
}
