void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 . V_6 [ V_3 ] ;
int V_7 ;
if ( F_2 ( V_8 + V_4 -> V_9 ) & V_10 ) {
for ( V_7 = 0 ; V_7 < V_2 -> V_11 ; V_7 ++ ) {
if ( ! ( F_2 ( V_12 + V_4 -> V_9 ) & V_13 ) )
break;
F_3 ( 1 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_11 ; V_7 ++ ) {
if ( F_2 ( V_12 + V_4 -> V_9 ) & V_13 )
break;
F_3 ( 1 ) ;
}
}
}
void F_4 ( struct V_1 * V_2 , int V_3 )
{
F_5 ( V_2 , V_3 ) ;
}
void F_6 ( struct V_1 * V_2 , int V_3 )
{
F_7 ( V_2 , V_3 ) ;
}
T_1 F_8 ( struct V_1 * V_2 , int V_14 , T_2 V_15 )
{
struct V_4 * V_4 = V_2 -> V_5 . V_6 [ V_14 ] ;
T_1 V_16 = F_2 ( V_17 + V_4 -> V_9 ) ;
int V_7 ;
V_16 |= V_18 ;
F_9 ( V_17 + V_4 -> V_9 , V_16 ) ;
F_9 ( V_19 + V_4 -> V_9 ,
( T_1 ) V_15 ) ;
F_9 ( V_20 + V_4 -> V_9 ,
( T_1 ) V_15 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 ; V_7 ++ ) {
if ( F_2 ( V_17 + V_4 -> V_9 ) & V_21 )
break;
F_3 ( 1 ) ;
}
F_10 ( L_1 ) ;
V_16 &= ~ V_18 ;
F_9 ( V_17 + V_4 -> V_9 , V_16 ) ;
return F_2 ( V_17 + V_4 -> V_9 ) & V_21 ;
}
void F_11 ( struct V_1 * V_2 )
{
int V_22 = V_2 -> V_23 . V_24 ;
struct V_25 * V_26 = & V_2 -> V_23 . V_27 [ V_22 ] ;
struct V_28 * V_29 = & V_26 -> V_30 [ 0 ] . V_29 ;
T_1 V_16 , V_31 , V_32 ;
T_1 V_33 , V_34 ;
if ( ( V_29 -> type == V_35 ) && ( V_29 -> V_36 . V_37 ) ) {
if ( V_26 -> V_38 & V_39 ) {
V_16 = F_2 ( V_29 -> V_36 . V_40 ) ;
if ( V_29 -> V_41 )
V_16 |= V_29 -> V_36 . V_42 ;
else
V_16 &= ~ ( V_29 -> V_36 . V_42 ) ;
F_9 ( V_29 -> V_36 . V_40 , V_16 ) ;
if ( V_29 -> V_43 )
F_3 ( V_29 -> V_43 ) ;
} else {
V_16 = F_2 ( V_29 -> V_36 . V_40 ) ;
if ( V_29 -> V_41 )
V_16 &= ~ V_29 -> V_36 . V_42 ;
else
V_16 |= V_29 -> V_36 . V_42 ;
F_9 ( V_29 -> V_36 . V_40 , V_16 ) ;
if ( V_29 -> V_43 )
F_3 ( V_29 -> V_43 ) ;
}
} else if ( V_29 -> type == V_44 )
F_12 ( V_2 , V_29 -> V_45 , V_46 ) ;
V_31 = F_13 ( V_47 ) ;
V_31 &= ~ F_14 ( 0xf ) ;
V_31 &= ~ F_15 ( 0xf ) ;
if ( V_26 -> V_38 & V_48 ) {
if ( V_26 -> V_38 & V_49 ) {
V_31 |= F_14 ( 2 ) ;
V_31 |= F_15 ( 2 ) ;
} else if ( V_26 -> V_38 & V_50 ) {
V_31 |= F_14 ( 4 ) ;
V_31 |= F_15 ( 4 ) ;
}
} else {
V_31 |= F_14 ( 1 ) ;
V_31 |= F_15 ( 1 ) ;
}
F_16 ( V_47 , V_31 ) ;
V_32 = F_13 ( V_51 ) ;
if ( V_26 -> V_38 & V_52 ) {
V_32 |= V_53 ;
if ( V_29 -> V_43 ) {
V_32 |= V_54 ;
V_32 |= F_17 ( V_29 -> V_43 ) ;
} else
V_32 &= ~ V_54 ;
} else
V_32 &= ~ V_53 ;
F_16 ( V_51 , V_32 ) ;
V_33 = F_13 ( V_55 ) ;
if ( V_26 -> V_38 & V_56 )
V_33 &= ~ V_57 ;
else
V_33 |= V_57 ;
F_16 ( V_55 , V_33 ) ;
#if 0
mc_host_dyn_cntl = RREG32_PLL(MC_HOST_DYN_CNTL);
if (ps->misc & ATOM_PM_MISCINFO_DYNAMIC_MC_HOST_BLOCK_EN)
mc_host_dyn_cntl &= ~MC_HOST_FORCEON;
else
mc_host_dyn_cntl |= MC_HOST_FORCEON;
WREG32_PLL(MC_HOST_DYN_CNTL, mc_host_dyn_cntl);
#endif
V_34 = F_13 ( V_58 ) ;
if ( V_26 -> V_38 & V_59 )
V_34 |= V_60 ;
else
V_34 &= ~ V_60 ;
F_16 ( V_58 , V_34 ) ;
if ( ( V_2 -> V_61 & V_62 ) &&
! ( V_2 -> V_61 & V_63 ) &&
V_2 -> V_64 -> V_23 . V_65 &&
( V_26 -> V_66 !=
V_2 -> V_23 . V_27 [ V_2 -> V_23 . V_67 ] . V_66 ) ) {
F_18 ( V_2 ,
V_26 -> V_66 ) ;
F_10 ( L_2 , V_26 -> V_66 ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_69 ;
struct V_70 * V_3 ;
struct V_4 * V_4 ;
T_1 V_16 ;
F_20 (crtc, &ddev->mode_config.crtc_list, head) {
V_4 = F_21 ( V_3 ) ;
if ( V_4 -> V_71 ) {
V_16 = F_2 ( V_8 + V_4 -> V_9 ) ;
V_16 |= V_72 ;
F_9 ( V_8 + V_4 -> V_9 , V_16 ) ;
}
}
}
void F_22 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_69 ;
struct V_70 * V_3 ;
struct V_4 * V_4 ;
T_1 V_16 ;
F_20 (crtc, &ddev->mode_config.crtc_list, head) {
V_4 = F_21 ( V_3 ) ;
if ( V_4 -> V_71 ) {
V_16 = F_2 ( V_8 + V_4 -> V_9 ) ;
V_16 &= ~ V_72 ;
F_9 ( V_8 + V_4 -> V_9 , V_16 ) ;
}
}
}
bool F_23 ( struct V_1 * V_2 , enum V_73 V_74 )
{
T_1 V_16 ;
bool V_75 = false ;
switch ( V_74 ) {
case V_76 :
V_16 = F_2 ( V_77 ) ;
if ( F_24 ( V_16 ) )
V_75 = true ;
break;
case V_78 :
V_16 = F_2 ( V_79 ) ;
if ( F_25 ( V_16 ) )
V_75 = true ;
break;
default:
break;
}
return V_75 ;
}
void F_26 ( struct V_1 * V_2 ,
enum V_73 V_74 )
{
T_1 V_16 ;
bool V_75 = F_23 ( V_2 , V_74 ) ;
switch ( V_74 ) {
case V_76 :
V_16 = F_2 ( V_80 ) ;
if ( V_75 )
V_16 &= ~ F_27 ( 1 ) ;
else
V_16 |= F_27 ( 1 ) ;
F_9 ( V_80 , V_16 ) ;
break;
case V_78 :
V_16 = F_2 ( V_81 ) ;
if ( V_75 )
V_16 &= ~ F_28 ( 1 ) ;
else
V_16 |= F_28 ( 1 ) ;
F_9 ( V_81 , V_16 ) ;
break;
default:
break;
}
}
void F_29 ( struct V_1 * V_2 )
{
struct V_68 * V_82 = V_2 -> V_69 ;
struct V_83 * V_84 ;
F_20 (connector, &dev->mode_config.connector_list, head) {
struct V_85 * V_85 = F_30 ( V_84 ) ;
switch ( V_85 -> V_74 . V_74 ) {
case V_76 :
F_9 ( V_86 ,
F_31 ( 1 ) ) ;
V_2 -> V_87 . V_74 [ 0 ] = true ;
break;
case V_78 :
F_9 ( V_88 ,
F_32 ( 1 ) ) ;
V_2 -> V_87 . V_74 [ 1 ] = true ;
break;
default:
break;
}
F_33 ( V_2 , V_85 -> V_74 . V_74 ) ;
}
if ( V_2 -> V_87 . V_89 )
F_34 ( V_2 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_68 * V_82 = V_2 -> V_69 ;
struct V_83 * V_84 ;
F_20 (connector, &dev->mode_config.connector_list, head) {
struct V_85 * V_85 = F_30 ( V_84 ) ;
switch ( V_85 -> V_74 . V_74 ) {
case V_76 :
F_9 ( V_86 ,
F_31 ( 0 ) ) ;
V_2 -> V_87 . V_74 [ 0 ] = false ;
break;
case V_78 :
F_9 ( V_88 ,
F_32 ( 0 ) ) ;
V_2 -> V_87 . V_74 [ 1 ] = false ;
break;
default:
break;
}
}
}
int F_36 ( struct V_1 * V_2 )
{
struct V_90 V_91 ;
T_1 V_92 , V_16 ;
int V_93 = 0 ;
V_92 = F_2 ( V_94 ) ;
if ( ! F_37 ( V_92 ) ) {
return 0 ;
}
F_38 ( V_2 , & V_91 ) ;
V_92 = F_2 ( V_94 ) ;
F_39 ( V_2 -> V_82 , L_3 , V_95 , __LINE__ , V_92 ) ;
F_9 ( V_96 , 0 ) ;
V_16 = F_2 ( V_97 ) ;
F_9 ( V_97 , V_16 | V_98 ) ;
F_9 ( V_99 , 0 ) ;
F_9 ( V_100 , 0 ) ;
F_9 ( V_97 , V_16 ) ;
F_40 ( V_2 -> V_101 ) ;
F_41 ( V_2 -> V_101 ) ;
F_42 ( 1 ) ;
F_9 ( V_102 , F_43 ( 1 ) |
F_44 ( 1 ) ) ;
F_2 ( V_102 ) ;
F_42 ( 500 ) ;
F_9 ( V_102 , 0 ) ;
F_42 ( 1 ) ;
V_92 = F_2 ( V_94 ) ;
F_39 ( V_2 -> V_82 , L_3 , V_95 , __LINE__ , V_92 ) ;
F_9 ( V_102 , F_45 ( 1 ) ) ;
F_2 ( V_102 ) ;
F_42 ( 500 ) ;
F_9 ( V_102 , 0 ) ;
F_42 ( 1 ) ;
V_92 = F_2 ( V_94 ) ;
F_39 ( V_2 -> V_82 , L_3 , V_95 , __LINE__ , V_92 ) ;
F_9 ( V_102 , F_46 ( 1 ) ) ;
F_2 ( V_102 ) ;
F_42 ( 500 ) ;
F_9 ( V_102 , 0 ) ;
F_42 ( 1 ) ;
V_92 = F_2 ( V_94 ) ;
F_39 ( V_2 -> V_82 , L_3 , V_95 , __LINE__ , V_92 ) ;
F_47 ( V_2 -> V_101 ) ;
if ( F_48 ( V_92 ) || F_49 ( V_92 ) ) {
F_50 ( V_2 -> V_82 , L_4 ) ;
V_2 -> V_103 = true ;
V_93 = - 1 ;
} else
F_39 ( V_2 -> V_82 , L_5 ) ;
F_51 ( V_2 , & V_91 ) ;
return V_93 ;
}
void F_52 ( struct V_1 * V_2 )
{
T_3 V_16 ;
V_16 = F_53 ( V_104 ) ;
V_16 &= V_105 & V_106 ;
F_54 ( V_104 , V_16 ) ;
V_16 = F_53 ( V_104 ) ;
V_16 |= F_55 ( 1 ) | F_56 ( 1 ) ;
F_54 ( V_104 , V_16 ) ;
V_16 = F_53 ( V_104 ) ;
V_16 &= V_105 & V_106 ;
F_54 ( V_104 , V_16 ) ;
V_16 = F_53 ( V_104 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_107 ;
if ( V_2 -> V_108 . V_109 ) {
F_58 ( 1 , L_6 ) ;
return 0 ;
}
V_107 = F_59 ( V_2 ) ;
if ( V_107 ) {
return V_107 ;
}
V_2 -> V_108 . V_110 = V_2 -> V_108 . V_111 * 8 ;
return F_60 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
T_1 V_16 ;
int V_107 , V_7 ;
if ( V_2 -> V_108 . V_109 == NULL ) {
F_50 ( V_2 -> V_82 , L_7 ) ;
return - V_112 ;
}
V_107 = F_62 ( V_2 ) ;
if ( V_107 )
return V_107 ;
F_63 ( V_2 ) ;
V_16 = F_2 ( V_113 ) & ~ V_114 ;
F_9 ( V_113 , V_16 ) ;
F_54 ( V_104 ,
( F_64 ( 6 ) |
F_65 ( 6 ) ) ) ;
for ( V_7 = 0 ; V_7 < 19 ; V_7 ++ ) {
F_54 ( V_115 + V_7 ,
F_66 ( 1 ) |
F_67 (
V_116 ) |
F_68 (
V_117 ) |
F_69 ( 3 ) |
F_70 ( 1 ) |
F_71 ( 3 ) ) ;
}
F_54 ( V_118 ,
F_72 ( 1 ) |
F_73 ( V_119 ) ) ;
for ( V_7 = 1 ; V_7 < 8 ; V_7 ++ )
F_54 ( V_118 + V_7 , 0 ) ;
F_54 ( V_120 ,
V_2 -> V_108 . V_121 ) ;
F_54 ( V_122 , V_2 -> V_123 . V_124 ) ;
F_54 ( V_125 , V_2 -> V_123 . V_126 ) ;
F_54 ( V_127 , 0 ) ;
F_54 ( V_128 , V_2 -> V_123 . V_129 ) ;
F_54 ( V_130 , V_2 -> V_123 . V_131 ) ;
V_16 = F_53 ( V_104 ) ;
F_54 ( V_104 , ( V_16 | F_74 ( 1 ) ) ) ;
V_16 = F_53 ( V_132 ) ;
F_54 ( V_132 , ( V_16 | F_75 ( 1 ) ) ) ;
F_52 ( V_2 ) ;
F_76 ( L_8 ,
( unsigned ) ( V_2 -> V_123 . V_133 >> 20 ) ,
( unsigned long long ) V_2 -> V_108 . V_121 ) ;
V_2 -> V_108 . V_134 = true ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
T_1 V_16 ;
F_54 ( V_104 , 0 ) ;
V_16 = F_53 ( V_132 ) ;
F_54 ( V_132 , V_16 & V_135 ) ;
F_78 ( V_2 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
F_80 ( V_2 ) ;
F_77 ( V_2 ) ;
F_81 ( V_2 ) ;
}
int F_82 ( struct V_1 * V_2 , int V_7 , T_4 V_136 )
{
void T_5 * V_137 = ( void * ) V_2 -> V_108 . V_137 ;
if ( V_7 < 0 || V_7 > V_2 -> V_108 . V_111 ) {
return - V_112 ;
}
V_136 = V_136 & 0xFFFFFFFFFFFFF000ULL ;
V_136 |= V_138 | V_139 | V_140 ;
V_136 |= V_141 | V_142 ;
F_83 ( V_136 , V_137 + ( V_7 * 8 ) ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 )
{
T_3 V_16 = 0 ;
T_3 V_143 = 0 ;
T_1 V_144 = F_2 ( V_80 ) &
~ F_84 ( 1 ) ;
T_1 V_145 = F_2 ( V_81 ) &
~ F_85 ( 1 ) ;
if ( ! V_2 -> V_87 . V_89 ) {
F_58 ( 1 , L_9 ) ;
F_9 ( V_146 , 0 ) ;
return - V_112 ;
}
if ( V_2 -> V_87 . V_147 [ V_148 ] ) {
V_16 |= F_86 ( 1 ) ;
}
if ( V_2 -> V_87 . V_149 ) {
V_16 |= F_87 ( 1 ) ;
}
if ( V_2 -> V_87 . V_150 [ 0 ] ||
V_2 -> V_87 . V_151 [ 0 ] ) {
V_143 |= F_88 ( 1 ) ;
}
if ( V_2 -> V_87 . V_150 [ 1 ] ||
V_2 -> V_87 . V_151 [ 1 ] ) {
V_143 |= F_89 ( 1 ) ;
}
if ( V_2 -> V_87 . V_74 [ 0 ] ) {
V_144 |= F_84 ( 1 ) ;
}
if ( V_2 -> V_87 . V_74 [ 1 ] ) {
V_145 |= F_85 ( 1 ) ;
}
F_9 ( V_146 , V_16 ) ;
F_9 ( V_152 , V_143 ) ;
F_9 ( V_80 , V_144 ) ;
F_9 ( V_81 , V_145 ) ;
return 0 ;
}
static inline T_1 F_90 ( struct V_1 * V_2 )
{
T_3 V_153 = F_2 ( V_154 ) ;
T_3 V_155 = F_91 ( 1 ) ;
T_1 V_16 ;
if ( V_2 -> V_87 . V_149 && F_92 ( V_2 ) ) {
if ( ! V_2 -> V_87 . V_156 )
V_155 |= F_93 ( 1 ) ;
}
if ( F_94 ( V_153 ) ) {
V_2 -> V_87 . V_157 . V_158 . V_159 = F_2 ( V_160 ) ;
if ( F_95 ( V_2 -> V_87 . V_157 . V_158 . V_159 ) ) {
F_9 ( V_161 ,
F_96 ( 1 ) ) ;
}
if ( F_97 ( V_2 -> V_87 . V_157 . V_158 . V_159 ) ) {
F_9 ( V_162 ,
F_98 ( 1 ) ) ;
}
if ( F_99 ( V_2 -> V_87 . V_157 . V_158 . V_159 ) ) {
V_16 = F_2 ( V_80 ) ;
V_16 |= F_100 ( 1 ) ;
F_9 ( V_80 , V_16 ) ;
}
if ( F_101 ( V_2 -> V_87 . V_157 . V_158 . V_159 ) ) {
V_16 = F_2 ( V_81 ) ;
V_16 |= F_102 ( 1 ) ;
F_9 ( V_81 , V_16 ) ;
}
} else {
V_2 -> V_87 . V_157 . V_158 . V_159 = 0 ;
}
if ( V_153 ) {
F_9 ( V_154 , V_153 ) ;
}
return V_153 & V_155 ;
}
void F_103 ( struct V_1 * V_2 )
{
F_9 ( V_146 , 0 ) ;
F_9 ( V_152 , 0 ) ;
F_42 ( 1 ) ;
F_90 ( V_2 ) ;
}
int F_104 ( struct V_1 * V_2 )
{
T_1 V_92 , V_163 ;
bool V_164 = false ;
V_2 -> V_87 . V_156 = false ;
V_92 = F_90 ( V_2 ) ;
if ( ! V_92 && ! V_2 -> V_87 . V_157 . V_158 . V_159 ) {
return V_165 ;
}
while ( V_92 || V_2 -> V_87 . V_157 . V_158 . V_159 ) {
if ( F_105 ( V_92 ) ) {
F_106 ( V_2 , V_148 ) ;
}
if ( F_107 ( V_92 ) ) {
V_2 -> V_87 . V_156 = true ;
V_2 -> V_23 . V_149 = true ;
F_108 ( & V_2 -> V_87 . V_166 ) ;
}
if ( F_95 ( V_2 -> V_87 . V_157 . V_158 . V_159 ) ) {
if ( V_2 -> V_87 . V_150 [ 0 ] ) {
F_109 ( V_2 -> V_69 , 0 ) ;
V_2 -> V_23 . V_167 = true ;
F_108 ( & V_2 -> V_87 . V_168 ) ;
}
if ( V_2 -> V_87 . V_151 [ 0 ] )
F_110 ( V_2 , 0 ) ;
}
if ( F_97 ( V_2 -> V_87 . V_157 . V_158 . V_159 ) ) {
if ( V_2 -> V_87 . V_150 [ 1 ] ) {
F_109 ( V_2 -> V_69 , 1 ) ;
V_2 -> V_23 . V_167 = true ;
F_108 ( & V_2 -> V_87 . V_168 ) ;
}
if ( V_2 -> V_87 . V_151 [ 1 ] )
F_110 ( V_2 , 1 ) ;
}
if ( F_99 ( V_2 -> V_87 . V_157 . V_158 . V_159 ) ) {
V_164 = true ;
F_10 ( L_10 ) ;
}
if ( F_101 ( V_2 -> V_87 . V_157 . V_158 . V_159 ) ) {
V_164 = true ;
F_10 ( L_11 ) ;
}
V_92 = F_90 ( V_2 ) ;
}
V_2 -> V_87 . V_156 = false ;
if ( V_164 )
F_111 ( & V_2 -> V_169 ) ;
if ( V_2 -> V_170 ) {
switch ( V_2 -> V_171 ) {
case V_172 :
case V_173 :
case V_174 :
V_163 = F_2 ( V_113 ) & ~ V_175 ;
F_9 ( V_113 , V_163 ) ;
F_9 ( V_113 , V_163 | V_175 ) ;
break;
default:
F_9 ( V_176 , V_177 ) ;
break;
}
}
return V_178 ;
}
T_1 F_112 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 0 )
return F_2 ( V_179 ) ;
else
return F_2 ( V_180 ) ;
}
int F_113 ( struct V_1 * V_2 )
{
unsigned V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 ; V_7 ++ ) {
if ( F_114 ( F_53 ( V_181 ) ) )
return 0 ;
F_3 ( 1 ) ;
}
return - 1 ;
}
void F_115 ( struct V_1 * V_2 )
{
F_116 ( V_2 ) ;
if ( F_113 ( V_2 ) )
F_117 ( V_2 -> V_82 , L_12 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
T_2 V_182 ;
V_2 -> V_123 . V_183 = F_119 ( V_2 -> V_101 , 0 ) ;
V_2 -> V_123 . V_184 = F_120 ( V_2 -> V_101 , 0 ) ;
V_2 -> V_123 . V_185 = true ;
V_2 -> V_123 . V_186 = 128 ;
V_2 -> V_123 . V_187 = F_2 ( V_188 ) ;
V_2 -> V_123 . V_189 = V_2 -> V_123 . V_187 ;
V_2 -> V_123 . V_190 = V_2 -> V_123 . V_184 ;
V_2 -> V_123 . V_191 = F_121 ( V_2 ) ;
V_182 = F_53 ( V_192 ) ;
V_182 = F_122 ( V_182 ) << 16 ;
F_123 ( V_2 , & V_2 -> V_123 , V_182 ) ;
V_2 -> V_123 . V_193 = 0 ;
F_124 ( V_2 , & V_2 -> V_123 ) ;
F_125 ( V_2 ) ;
}
void F_126 ( struct V_1 * V_2 )
{
struct V_194 * V_195 = NULL ;
struct V_194 * V_196 = NULL ;
T_1 V_197 , V_198 ;
F_127 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 [ 0 ] -> V_182 . V_71 )
V_195 = & V_2 -> V_5 . V_6 [ 0 ] -> V_182 . V_199 ;
if ( V_2 -> V_5 . V_6 [ 1 ] -> V_182 . V_71 )
V_196 = & V_2 -> V_5 . V_6 [ 1 ] -> V_182 . V_199 ;
F_128 ( V_2 , V_195 , V_196 ) ;
if ( V_2 -> V_200 == 2 ) {
V_197 = F_2 ( V_201 ) ;
V_198 = F_2 ( V_202 ) ;
V_197 |= F_129 ( 1 ) ;
V_198 |= F_130 ( 1 ) ;
F_9 ( V_201 , V_197 ) ;
F_9 ( V_203 , V_197 ) ;
F_9 ( V_202 , V_198 ) ;
F_9 ( V_204 , V_198 ) ;
}
}
T_3 F_131 ( struct V_1 * V_2 , T_3 V_40 )
{
F_9 ( V_205 , F_132 ( V_40 ) |
F_133 ( 1 ) ) ;
return F_2 ( V_206 ) ;
}
void F_134 ( struct V_1 * V_2 , T_3 V_40 , T_3 V_207 )
{
F_9 ( V_205 , F_132 ( V_40 ) |
F_133 ( 1 ) | F_135 ( 1 ) ) ;
F_9 ( V_206 , V_207 ) ;
}
void F_136 ( struct V_1 * V_2 )
{
if ( F_137 ( V_2 ) )
F_138 ( L_13 ) ;
}
void F_139 ( struct V_1 * V_2 )
{
V_2 -> V_208 . V_209 . V_210 = V_211 ;
V_2 -> V_208 . V_209 . V_212 = F_140 ( V_211 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
struct V_90 V_91 ;
F_38 ( V_2 , & V_91 ) ;
if ( F_113 ( V_2 ) )
F_117 ( V_2 -> V_82 , L_12 ) ;
F_54 ( V_213 , 0x0FFFFFFF ) ;
F_54 ( V_214 , 0 ) ;
F_54 ( V_215 , 0 ) ;
F_54 ( V_192 ,
F_142 ( V_2 -> V_123 . V_129 >> 16 ) |
F_143 ( V_2 -> V_123 . V_131 >> 16 ) ) ;
F_9 ( V_216 ,
F_144 ( V_2 -> V_123 . V_129 >> 16 ) ) ;
F_51 ( V_2 , & V_91 ) ;
}
static int F_145 ( struct V_1 * V_2 )
{
int V_107 ;
F_141 ( V_2 ) ;
F_146 ( V_2 ) ;
F_115 ( V_2 ) ;
V_107 = F_61 ( V_2 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_147 ( V_2 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_148 ( V_2 , V_148 ) ;
if ( V_107 ) {
F_50 ( V_2 -> V_82 , L_14 , V_107 ) ;
return V_107 ;
}
F_34 ( V_2 ) ;
V_2 -> V_208 . V_209 . V_217 = F_2 ( V_218 ) ;
V_107 = F_149 ( V_2 , 1024 * 1024 ) ;
if ( V_107 ) {
F_50 ( V_2 -> V_82 , L_15 , V_107 ) ;
return V_107 ;
}
V_107 = F_150 ( V_2 ) ;
if ( V_107 ) {
F_50 ( V_2 -> V_82 , L_16 ) ;
return V_107 ;
}
V_107 = F_151 ( V_2 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_152 ( V_2 , V_148 , & V_2 -> V_219 [ V_148 ] ) ;
if ( V_107 ) {
F_50 ( V_2 -> V_82 , L_17 , V_107 ) ;
V_2 -> V_220 = false ;
return V_107 ;
}
return 0 ;
}
int F_153 ( struct V_1 * V_2 )
{
int V_107 ;
F_77 ( V_2 ) ;
F_146 ( V_2 ) ;
if ( F_154 ( V_2 ) ) {
F_117 ( V_2 -> V_82 , L_18 ,
F_2 ( V_94 ) ,
F_2 ( V_221 ) ) ;
}
F_155 ( V_2 -> V_5 . V_222 ) ;
F_146 ( V_2 ) ;
F_156 ( V_2 ) ;
V_2 -> V_220 = true ;
V_107 = F_145 ( V_2 ) ;
if ( V_107 ) {
V_2 -> V_220 = false ;
}
return V_107 ;
}
int F_157 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
F_103 ( V_2 ) ;
F_77 ( V_2 ) ;
return 0 ;
}
void F_162 ( struct V_1 * V_2 )
{
F_159 ( V_2 ) ;
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
F_165 ( V_2 ) ;
F_166 ( V_2 ) ;
F_79 ( V_2 ) ;
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 -> V_223 ) ;
V_2 -> V_223 = NULL ;
}
int F_172 ( struct V_1 * V_2 )
{
int V_107 ;
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
F_156 ( V_2 ) ;
F_175 ( V_2 ) ;
if ( ! F_176 ( V_2 ) ) {
if ( F_177 ( V_2 ) )
return - V_112 ;
}
if ( V_2 -> V_224 ) {
V_107 = F_178 ( V_2 ) ;
if ( V_107 )
return V_107 ;
} else {
F_50 ( V_2 -> V_82 , L_19 ) ;
return - V_112 ;
}
if ( F_154 ( V_2 ) ) {
F_117 ( V_2 -> V_82 ,
L_18 ,
F_2 ( V_94 ) ,
F_2 ( V_221 ) ) ;
}
if ( F_179 ( V_2 ) == false )
return - V_112 ;
F_180 ( V_2 -> V_69 ) ;
F_118 ( V_2 ) ;
F_136 ( V_2 ) ;
V_107 = F_181 ( V_2 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_182 ( V_2 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_183 ( V_2 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_57 ( V_2 ) ;
if ( V_107 )
return V_107 ;
F_139 ( V_2 ) ;
V_107 = F_184 ( V_2 ) ;
V_2 -> V_220 = true ;
if ( V_107 ) {
F_50 ( V_2 -> V_82 , L_20 , V_107 ) ;
V_2 -> V_220 = false ;
}
V_107 = F_145 ( V_2 ) ;
if ( V_107 ) {
F_50 ( V_2 -> V_82 , L_21 ) ;
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
F_165 ( V_2 ) ;
F_79 ( V_2 ) ;
F_167 ( V_2 ) ;
V_2 -> V_220 = false ;
}
return 0 ;
}
