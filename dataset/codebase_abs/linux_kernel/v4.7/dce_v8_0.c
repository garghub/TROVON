static T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
unsigned long V_5 ;
T_1 V_6 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
F_3 ( V_8 + V_3 , V_4 ) ;
V_6 = F_4 ( V_9 + V_3 ) ;
F_5 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_10 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
F_3 ( V_8 + V_3 , V_4 ) ;
F_3 ( V_9 + V_3 , V_10 ) ;
F_5 ( & V_2 -> V_7 , V_5 ) ;
}
static bool F_7 ( struct V_1 * V_2 , int V_11 )
{
if ( F_4 ( V_12 + V_13 [ V_11 ] ) &
V_14 )
return true ;
else
return false ;
}
static bool F_8 ( struct V_1 * V_2 , int V_11 )
{
T_1 V_15 , V_16 ;
V_15 = F_4 ( V_17 + V_13 [ V_11 ] ) ;
V_16 = F_4 ( V_17 + V_13 [ V_11 ] ) ;
if ( V_15 != V_16 )
return true ;
else
return false ;
}
static void F_9 ( struct V_1 * V_2 , int V_11 )
{
unsigned V_18 = 0 ;
if ( V_11 >= V_2 -> V_19 . V_20 )
return;
if ( ! ( F_4 ( V_21 + V_13 [ V_11 ] ) & V_22 ) )
return;
while ( F_7 ( V_2 , V_11 ) ) {
if ( V_18 ++ % 100 == 0 ) {
if ( ! F_8 ( V_2 , V_11 ) )
break;
}
}
while ( ! F_7 ( V_2 , V_11 ) ) {
if ( V_18 ++ % 100 == 0 ) {
if ( ! F_8 ( V_2 , V_11 ) )
break;
}
}
}
static T_1 F_10 ( struct V_1 * V_2 , int V_11 )
{
if ( V_11 >= V_2 -> V_19 . V_20 )
return 0 ;
else
return F_4 ( V_23 + V_13 [ V_11 ] ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ )
F_12 ( V_2 , & V_2 -> V_24 , V_18 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ )
F_14 ( V_2 , & V_2 -> V_24 , V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
int V_25 , T_2 V_26 , bool V_27 )
{
struct V_28 * V_28 = V_2 -> V_19 . V_29 [ V_25 ] ;
F_3 ( V_30 + V_28 -> V_31 , V_27 ?
V_32 : 0 ) ;
F_3 ( V_33 + V_28 -> V_31 ,
F_16 ( V_26 ) ) ;
F_3 ( V_34 + V_28 -> V_31 ,
F_17 ( V_26 ) ) ;
F_4 ( V_34 + V_28 -> V_31 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_11 ,
T_1 * V_35 , T_1 * V_36 )
{
if ( ( V_11 < 0 ) || ( V_11 >= V_2 -> V_19 . V_20 ) )
return - V_37 ;
* V_35 = F_4 ( V_38 + V_13 [ V_11 ] ) ;
* V_36 = F_4 ( V_17 + V_13 [ V_11 ] ) ;
return 0 ;
}
static bool F_19 ( struct V_1 * V_2 ,
enum V_39 V_40 )
{
bool V_41 = false ;
switch ( V_40 ) {
case V_42 :
if ( F_4 ( V_43 ) & V_44 )
V_41 = true ;
break;
case V_45 :
if ( F_4 ( V_46 ) & V_47 )
V_41 = true ;
break;
case V_48 :
if ( F_4 ( V_49 ) & V_50 )
V_41 = true ;
break;
case V_51 :
if ( F_4 ( V_52 ) & V_53 )
V_41 = true ;
break;
case V_54 :
if ( F_4 ( V_55 ) & V_56 )
V_41 = true ;
break;
case V_57 :
if ( F_4 ( V_58 ) & V_59 )
V_41 = true ;
break;
default:
break;
}
return V_41 ;
}
static void F_20 ( struct V_1 * V_2 ,
enum V_39 V_40 )
{
T_1 V_60 ;
bool V_41 = F_19 ( V_2 , V_40 ) ;
switch ( V_40 ) {
case V_42 :
V_60 = F_4 ( V_61 ) ;
if ( V_41 )
V_60 &= ~ V_62 ;
else
V_60 |= V_62 ;
F_3 ( V_61 , V_60 ) ;
break;
case V_45 :
V_60 = F_4 ( V_63 ) ;
if ( V_41 )
V_60 &= ~ V_64 ;
else
V_60 |= V_64 ;
F_3 ( V_63 , V_60 ) ;
break;
case V_48 :
V_60 = F_4 ( V_65 ) ;
if ( V_41 )
V_60 &= ~ V_66 ;
else
V_60 |= V_66 ;
F_3 ( V_65 , V_60 ) ;
break;
case V_51 :
V_60 = F_4 ( V_67 ) ;
if ( V_41 )
V_60 &= ~ V_68 ;
else
V_60 |= V_68 ;
F_3 ( V_67 , V_60 ) ;
break;
case V_54 :
V_60 = F_4 ( V_69 ) ;
if ( V_41 )
V_60 &= ~ V_70 ;
else
V_60 |= V_70 ;
F_3 ( V_69 , V_60 ) ;
break;
case V_57 :
V_60 = F_4 ( V_71 ) ;
if ( V_41 )
V_60 &= ~ V_72 ;
else
V_60 |= V_72 ;
F_3 ( V_71 , V_60 ) ;
break;
default:
break;
}
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = V_2 -> V_75 ;
struct V_76 * V_77 ;
T_1 V_60 = ( 0x9c4 << V_78 ) |
( 0xfa << V_79 ) |
V_80 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
struct V_81 * V_81 = F_23 ( V_77 ) ;
if ( V_77 -> V_82 == V_83 ||
V_77 -> V_82 == V_84 ) {
continue;
}
switch ( V_81 -> V_40 . V_40 ) {
case V_42 :
F_3 ( V_85 , V_60 ) ;
break;
case V_45 :
F_3 ( V_86 , V_60 ) ;
break;
case V_48 :
F_3 ( V_87 , V_60 ) ;
break;
case V_51 :
F_3 ( V_88 , V_60 ) ;
break;
case V_54 :
F_3 ( V_89 , V_60 ) ;
break;
case V_57 :
F_3 ( V_90 , V_60 ) ;
break;
default:
break;
}
F_20 ( V_2 , V_81 -> V_40 . V_40 ) ;
F_12 ( V_2 , & V_2 -> V_91 , V_81 -> V_40 . V_40 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = V_2 -> V_75 ;
struct V_76 * V_77 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
struct V_81 * V_81 = F_23 ( V_77 ) ;
switch ( V_81 -> V_40 . V_40 ) {
case V_42 :
F_3 ( V_85 , 0 ) ;
break;
case V_45 :
F_3 ( V_86 , 0 ) ;
break;
case V_48 :
F_3 ( V_87 , 0 ) ;
break;
case V_51 :
F_3 ( V_88 , 0 ) ;
break;
case V_54 :
F_3 ( V_89 , 0 ) ;
break;
case V_57 :
F_3 ( V_90 , 0 ) ;
break;
default:
break;
}
F_14 ( V_2 , & V_2 -> V_91 , V_81 -> V_40 . V_40 ) ;
}
}
static T_1 F_25 ( struct V_1 * V_2 )
{
return V_92 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_93 = 0 ;
T_1 V_94 [ 6 ] ;
T_1 V_18 , V_95 , V_60 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( F_4 ( V_21 + V_13 [ V_18 ] ) & V_22 ) {
V_94 [ V_18 ] = F_4 ( V_96 + V_13 [ V_18 ] ) ;
V_93 |= ( 1 << V_18 ) ;
}
}
for ( V_95 = 0 ; V_95 < 10 ; V_95 ++ ) {
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_93 & ( 1 << V_18 ) ) {
V_60 = F_4 ( V_96 + V_13 [ V_18 ] ) ;
if ( V_60 != V_94 [ V_18 ] )
V_93 &= ~ ( 1 << V_18 ) ;
}
}
if ( V_93 == 0 )
return false ;
F_27 ( 100 ) ;
}
return true ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
T_1 V_99 , V_60 ;
int V_18 ;
V_98 -> V_100 = F_4 ( V_101 ) ;
V_98 -> V_102 = F_4 ( V_103 ) ;
V_60 = F_4 ( V_101 ) ;
V_60 = F_29 ( V_60 , V_104 , V_105 , 0 ) ;
F_3 ( V_101 , V_60 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_99 = F_30 ( F_4 ( V_21 + V_13 [ V_18 ] ) ,
V_106 , V_107 ) ;
if ( V_99 ) {
#if 0
u32 frame_count;
int j;
save->crtc_enabled[i] = true;
tmp = RREG32(mmCRTC_BLANK_CONTROL + crtc_offsets[i]);
if (REG_GET_FIELD(tmp, CRTC_BLANK_CONTROL, CRTC_BLANK_DATA_EN) == 0) {
amdgpu_display_vblank_wait(adev, i);
WREG32(mmCRTC_UPDATE_LOCK + crtc_offsets[i], 1);
tmp = REG_SET_FIELD(tmp, CRTC_BLANK_CONTROL, CRTC_BLANK_DATA_EN, 1);
WREG32(mmCRTC_BLANK_CONTROL + crtc_offsets[i], tmp);
WREG32(mmCRTC_UPDATE_LOCK + crtc_offsets[i], 0);
}
frame_count = amdgpu_display_vblank_get_counter(adev, i);
for (j = 0; j < adev->usec_timeout; j++) {
if (amdgpu_display_vblank_get_counter(adev, i) != frame_count)
break;
udelay(1);
}
tmp = RREG32(mmGRPH_UPDATE + crtc_offsets[i]);
if (REG_GET_FIELD(tmp, GRPH_UPDATE, GRPH_UPDATE_LOCK) == 0) {
tmp = REG_SET_FIELD(tmp, GRPH_UPDATE, GRPH_UPDATE_LOCK, 1);
WREG32(mmGRPH_UPDATE + crtc_offsets[i], tmp);
}
tmp = RREG32(mmMASTER_UPDATE_LOCK + crtc_offsets[i]);
if (REG_GET_FIELD(tmp, MASTER_UPDATE_LOCK, MASTER_UPDATE_LOCK) == 0) {
tmp = REG_SET_FIELD(tmp, MASTER_UPDATE_LOCK, MASTER_UPDATE_LOCK, 1);
WREG32(mmMASTER_UPDATE_LOCK + crtc_offsets[i], tmp);
}
#else
F_3 ( V_108 + V_13 [ V_18 ] , 1 ) ;
V_60 = F_4 ( V_21 + V_13 [ V_18 ] ) ;
V_60 = F_29 ( V_60 , V_106 , V_107 , 0 ) ;
F_3 ( V_21 + V_13 [ V_18 ] , V_60 ) ;
F_3 ( V_108 + V_13 [ V_18 ] , 0 ) ;
V_98 -> V_99 [ V_18 ] = false ;
#endif
} else {
V_98 -> V_99 [ V_18 ] = false ;
}
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
T_1 V_60 , V_109 ;
int V_18 , V_95 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
F_3 ( V_33 + V_13 [ V_18 ] ,
F_16 ( V_2 -> V_110 . V_111 ) ) ;
F_3 ( V_112 + V_13 [ V_18 ] ,
F_16 ( V_2 -> V_110 . V_111 ) ) ;
F_3 ( V_34 + V_13 [ V_18 ] ,
( T_1 ) V_2 -> V_110 . V_111 ) ;
F_3 ( V_113 + V_13 [ V_18 ] ,
( T_1 ) V_2 -> V_110 . V_111 ) ;
if ( V_98 -> V_99 [ V_18 ] ) {
V_60 = F_4 ( V_114 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_60 , V_115 , V_115 ) != 3 ) {
V_60 = F_29 ( V_60 , V_115 , V_115 , 3 ) ;
F_3 ( V_114 + V_13 [ V_18 ] , V_60 ) ;
}
V_60 = F_4 ( V_116 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_60 , V_117 , V_118 ) ) {
V_60 = F_29 ( V_60 , V_117 , V_118 , 0 ) ;
F_3 ( V_116 + V_13 [ V_18 ] , V_60 ) ;
}
V_60 = F_4 ( V_119 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_60 , V_120 , V_120 ) ) {
V_60 = F_29 ( V_60 , V_120 , V_120 , 0 ) ;
F_3 ( V_119 + V_13 [ V_18 ] , V_60 ) ;
}
for ( V_95 = 0 ; V_95 < V_2 -> V_121 ; V_95 ++ ) {
V_60 = F_4 ( V_116 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_60 , V_117 , V_122 ) == 0 )
break;
F_27 ( 1 ) ;
}
V_60 = F_4 ( V_123 + V_13 [ V_18 ] ) ;
V_60 = F_29 ( V_60 , V_124 , V_125 , 0 ) ;
F_3 ( V_108 + V_13 [ V_18 ] , 1 ) ;
F_3 ( V_123 + V_13 [ V_18 ] , V_60 ) ;
F_3 ( V_108 + V_13 [ V_18 ] , 0 ) ;
V_109 = F_32 ( V_2 , V_18 ) ;
for ( V_95 = 0 ; V_95 < V_2 -> V_121 ; V_95 ++ ) {
if ( F_32 ( V_2 , V_18 ) != V_109 )
break;
F_27 ( 1 ) ;
}
}
}
F_3 ( V_126 , F_16 ( V_2 -> V_110 . V_111 ) ) ;
F_3 ( V_127 , F_17 ( V_2 -> V_110 . V_111 ) ) ;
F_3 ( V_103 , V_98 -> V_102 ) ;
F_33 ( 1 ) ;
F_3 ( V_101 , V_98 -> V_100 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
bool V_128 )
{
T_1 V_60 ;
V_60 = F_4 ( V_103 ) ;
if ( V_128 )
V_60 = F_29 ( V_60 , V_129 , V_130 , 0 ) ;
else
V_60 = F_29 ( V_60 , V_129 , V_130 , 1 ) ;
F_3 ( V_103 , V_60 ) ;
V_60 = F_4 ( V_101 ) ;
if ( V_128 )
V_60 = F_29 ( V_60 , V_104 , V_105 , 1 ) ;
else
V_60 = F_29 ( V_60 , V_104 , V_105 , 0 ) ;
F_3 ( V_101 , V_60 ) ;
}
static void F_35 ( struct V_131 * V_132 )
{
struct V_73 * V_74 = V_132 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_28 * V_28 = F_37 ( V_132 -> V_11 ) ;
struct V_76 * V_77 = F_38 ( V_132 ) ;
int V_135 = 0 ;
T_1 V_60 = 0 ;
enum V_136 V_137 = V_138 ;
if ( V_77 ) {
struct V_81 * V_81 = F_23 ( V_77 ) ;
V_135 = F_39 ( V_77 ) ;
V_137 = V_81 -> V_137 ;
}
if ( V_134 -> V_139 & V_140 )
return;
if ( ( V_134 -> V_141 == V_142 ) ||
( V_134 -> V_141 == V_143 ) )
return;
if ( V_135 == 0 )
return;
switch ( V_135 ) {
case 6 :
if ( V_137 == V_144 )
V_60 |= ( V_145 |
V_146 |
V_147 |
( 0 << V_148 ) ) ;
else
V_60 |= ( V_149 |
( 0 << V_150 ) ) ;
break;
case 8 :
if ( V_137 == V_144 )
V_60 |= ( V_145 |
V_146 |
V_151 |
V_147 |
( 1 << V_148 ) ) ;
else
V_60 |= ( V_149 |
( 1 << V_150 ) ) ;
break;
case 10 :
if ( V_137 == V_144 )
V_60 |= ( V_145 |
V_146 |
V_151 |
V_147 |
( 2 << V_148 ) ) ;
else
V_60 |= ( V_149 |
( 2 << V_150 ) ) ;
break;
default:
break;
}
F_3 ( V_152 + V_28 -> V_31 , V_60 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_28 * V_28 ,
struct V_153 * V_154 )
{
T_1 V_60 , V_155 , V_18 ;
T_1 V_156 = V_28 -> V_25 * 0x8 ;
if ( V_28 -> V_157 . V_158 && V_154 ) {
if ( V_154 -> V_159 < 1920 ) {
V_60 = 1 ;
V_155 = 2 ;
} else if ( V_154 -> V_159 < 2560 ) {
V_60 = 2 ;
V_155 = 2 ;
} else if ( V_154 -> V_159 < 4096 ) {
V_60 = 0 ;
V_155 = ( V_2 -> V_5 & V_160 ) ? 2 : 4 ;
} else {
F_41 ( L_1 ) ;
V_60 = 0 ;
V_155 = ( V_2 -> V_5 & V_160 ) ? 2 : 4 ;
}
} else {
V_60 = 1 ;
V_155 = 0 ;
}
F_3 ( V_161 + V_28 -> V_31 ,
( V_60 << V_162 ) |
( 0x6B0 << V_163 ) ) ;
F_3 ( V_164 + V_156 ,
( V_155 << V_165 ) ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_121 ; V_18 ++ ) {
if ( F_4 ( V_164 + V_156 ) &
V_166 )
break;
F_27 ( 1 ) ;
}
if ( V_28 -> V_157 . V_158 && V_154 ) {
switch ( V_60 ) {
case 0 :
default:
return 4096 * 2 ;
case 1 :
return 1920 * 2 ;
case 2 :
return 2560 * 2 ;
}
}
return 0 ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
T_1 V_60 = F_4 ( V_167 ) ;
switch ( ( V_60 & V_168 ) >> V_169 ) {
case 0 :
default:
return 1 ;
case 1 :
return 2 ;
case 2 :
return 4 ;
case 3 :
return 8 ;
case 4 :
return 3 ;
case 5 :
return 6 ;
case 6 :
return 10 ;
case 7 :
return 12 ;
case 8 :
return 16 ;
}
}
static T_1 F_43 ( struct V_170 * V_171 )
{
T_3 V_172 ;
T_3 V_173 , V_174 , V_175 ;
T_3 V_176 ;
V_176 . V_177 = F_44 ( 1000 ) ;
V_173 . V_177 = F_44 ( V_171 -> V_173 ) ;
V_173 . V_177 = F_45 ( V_173 , V_176 ) ;
V_174 . V_177 = F_44 ( V_171 -> V_174 * 4 ) ;
V_176 . V_177 = F_44 ( 10 ) ;
V_172 . V_177 = F_44 ( 7 ) ;
V_172 . V_177 = F_45 ( V_172 , V_176 ) ;
V_175 . V_177 = F_46 ( V_174 , V_173 ) ;
V_175 . V_177 = F_46 ( V_175 , V_172 ) ;
return F_47 ( V_175 ) ;
}
static T_1 F_48 ( struct V_170 * V_171 )
{
T_3 V_178 ;
T_3 V_173 , V_174 , V_175 ;
T_3 V_176 ;
V_176 . V_177 = F_44 ( 1000 ) ;
V_173 . V_177 = F_44 ( V_171 -> V_173 ) ;
V_173 . V_177 = F_45 ( V_173 , V_176 ) ;
V_174 . V_177 = F_44 ( V_171 -> V_174 * 4 ) ;
V_176 . V_177 = F_44 ( 10 ) ;
V_178 . V_177 = F_44 ( 3 ) ;
V_178 . V_177 = F_45 ( V_178 , V_176 ) ;
V_175 . V_177 = F_46 ( V_174 , V_173 ) ;
V_175 . V_177 = F_46 ( V_175 , V_178 ) ;
return F_47 ( V_175 ) ;
}
static T_1 F_49 ( struct V_170 * V_171 )
{
T_3 V_179 ;
T_3 V_180 , V_175 ;
T_3 V_176 ;
V_176 . V_177 = F_44 ( 1000 ) ;
V_180 . V_177 = F_44 ( V_171 -> V_180 ) ;
V_180 . V_177 = F_45 ( V_180 , V_176 ) ;
V_176 . V_177 = F_44 ( 10 ) ;
V_179 . V_177 = F_44 ( 8 ) ;
V_179 . V_177 = F_45 ( V_179 , V_176 ) ;
V_176 . V_177 = F_44 ( 32 ) ;
V_175 . V_177 = F_46 ( V_176 , V_180 ) ;
V_175 . V_177 = F_46 ( V_175 , V_179 ) ;
return F_47 ( V_175 ) ;
}
static T_1 F_50 ( struct V_170 * V_171 )
{
T_3 V_181 ;
T_3 V_182 , V_175 ;
T_3 V_176 , V_183 ;
V_176 . V_177 = F_44 ( 1000 ) ;
V_182 . V_177 = F_44 ( V_171 -> V_182 ) ;
V_182 . V_177 = F_45 ( V_182 , V_176 ) ;
V_176 . V_177 = F_44 ( 32 ) ;
V_183 . V_177 = F_46 ( V_176 , V_182 ) ;
V_176 . V_177 = F_44 ( 10 ) ;
V_181 . V_177 = F_44 ( 8 ) ;
V_181 . V_177 = F_45 ( V_181 , V_176 ) ;
V_175 . V_177 = F_46 ( V_183 , V_181 ) ;
return F_47 ( V_175 ) ;
}
static T_1 F_51 ( struct V_170 * V_171 )
{
T_1 V_184 = F_43 ( V_171 ) ;
T_1 V_185 = F_49 ( V_171 ) ;
T_1 V_186 = F_50 ( V_171 ) ;
return F_52 ( V_184 , F_52 ( V_185 , V_186 ) ) ;
}
static T_1 F_53 ( struct V_170 * V_171 )
{
T_3 V_187 ;
T_3 V_188 ;
T_3 V_189 ;
T_3 V_175 ;
T_3 V_176 ;
V_176 . V_177 = F_44 ( 1000 ) ;
V_188 . V_177 = F_44 ( V_171 -> V_190 + V_171 -> V_191 ) ;
V_188 . V_177 = F_45 ( V_188 , V_176 ) ;
V_187 . V_177 = F_44 ( V_171 -> V_192 ) ;
V_189 . V_177 = F_44 ( V_171 -> V_189 ) ;
V_175 . V_177 = F_46 ( V_189 , V_187 ) ;
V_175 . V_177 = F_46 ( V_175 , V_171 -> V_193 ) ;
V_175 . V_177 = F_45 ( V_175 , V_188 ) ;
return F_47 ( V_175 ) ;
}
static T_1 F_54 ( struct V_170 * V_171 )
{
T_1 V_194 = 2000 ;
T_1 V_195 = F_51 ( V_171 ) ;
T_1 V_196 = ( 512 * 8 * 1000 ) / V_195 ;
T_1 V_197 = ( 128 * 4 * 1000 ) / V_195 ;
T_1 V_198 = 40000000 / V_171 -> V_182 ;
T_1 V_199 = ( ( V_171 -> V_200 + 1 ) * V_196 ) +
( V_171 -> V_200 * V_197 ) ;
T_1 V_201 = V_194 + V_199 + V_198 ;
T_1 V_202 , V_203 , V_204 ;
T_1 V_60 , V_205 = 12288 ;
T_3 V_176 , V_183 , V_206 ;
if ( V_171 -> V_200 == 0 )
return 0 ;
V_176 . V_177 = F_44 ( 2 ) ;
V_183 . V_177 = F_44 ( 1 ) ;
if ( ( V_171 -> V_193 . V_177 > V_176 . V_177 ) ||
( ( V_171 -> V_193 . V_177 > V_183 . V_177 ) && ( V_171 -> V_207 >= 3 ) ) ||
( V_171 -> V_207 >= 5 ) ||
( ( V_171 -> V_193 . V_177 >= V_176 . V_177 ) && V_171 -> V_208 ) )
V_202 = 4 ;
else
V_202 = 2 ;
V_176 . V_177 = F_44 ( V_195 ) ;
V_183 . V_177 = F_44 ( V_171 -> V_200 ) ;
V_176 . V_177 = F_45 ( V_176 , V_183 ) ;
V_183 . V_177 = F_44 ( V_194 + 512 ) ;
V_206 . V_177 = F_44 ( V_171 -> V_182 ) ;
V_183 . V_177 = F_45 ( V_183 , V_206 ) ;
V_206 . V_177 = F_44 ( V_205 ) ;
V_183 . V_177 = F_45 ( V_206 , V_183 ) ;
V_60 = F_52 ( F_47 ( V_176 ) , F_47 ( V_183 ) ) ;
V_183 . V_177 = F_44 ( 1000 ) ;
V_206 . V_177 = F_44 ( V_171 -> V_182 ) ;
V_183 . V_177 = F_45 ( V_206 , V_183 ) ;
V_206 . V_177 = F_44 ( V_171 -> V_192 ) ;
V_183 . V_177 = F_46 ( V_183 , V_206 ) ;
V_203 = F_52 ( V_60 , F_47 ( V_183 ) ) ;
V_176 . V_177 = F_44 ( V_202 * V_171 -> V_189 * V_171 -> V_192 ) ;
V_183 . V_177 = F_44 ( 1000 ) ;
V_206 . V_177 = F_44 ( V_203 ) ;
V_183 . V_177 = F_45 ( V_206 , V_183 ) ;
V_176 . V_177 = F_45 ( V_176 , V_183 ) ;
V_204 = F_47 ( V_176 ) ;
if ( V_204 < V_171 -> V_190 )
return V_201 ;
else
return V_201 + ( V_204 - V_171 -> V_190 ) ;
}
static bool F_55 ( struct V_170 * V_171 )
{
if ( F_53 ( V_171 ) <=
( F_48 ( V_171 ) / V_171 -> V_200 ) )
return true ;
else
return false ;
}
static bool F_56 ( struct V_170 * V_171 )
{
if ( F_53 ( V_171 ) <=
( F_51 ( V_171 ) / V_171 -> V_200 ) )
return true ;
else
return false ;
}
static bool F_57 ( struct V_170 * V_171 )
{
T_1 V_209 = V_171 -> V_210 / V_171 -> V_189 ;
T_1 V_188 = V_171 -> V_190 + V_171 -> V_191 ;
T_1 V_211 ;
T_1 V_212 ;
T_3 V_176 ;
V_176 . V_177 = F_44 ( 1 ) ;
if ( V_171 -> V_193 . V_177 > V_176 . V_177 )
V_211 = 1 ;
else {
if ( V_209 <= ( V_171 -> V_207 + 1 ) )
V_211 = 1 ;
else
V_211 = 2 ;
}
V_212 = ( V_211 * V_188 + V_171 -> V_191 ) ;
if ( F_54 ( V_171 ) <= V_212 )
return true ;
else
return false ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_28 * V_28 ,
T_1 V_210 , T_1 V_200 )
{
struct V_153 * V_154 = & V_28 -> V_157 . V_154 ;
struct V_170 V_213 , V_214 ;
T_1 V_215 ;
T_1 V_188 = 0 ;
T_1 V_216 = 0 , V_217 = 0 ;
T_1 V_60 , V_218 , V_219 = 0 ;
if ( V_28 -> V_157 . V_158 && V_200 && V_154 ) {
V_215 = 1000000 / ( T_1 ) V_154 -> clock ;
V_188 = F_52 ( ( T_1 ) V_154 -> V_220 * V_215 , ( T_1 ) 65535 ) ;
if ( V_2 -> V_221 . V_222 ) {
V_214 . V_173 =
F_59 ( V_2 , false ) * 10 ;
V_214 . V_180 =
F_60 ( V_2 , false ) * 10 ;
} else {
V_214 . V_173 = V_2 -> V_221 . V_223 * 10 ;
V_214 . V_180 = V_2 -> V_221 . V_224 * 10 ;
}
V_214 . V_182 = V_154 -> clock ;
V_214 . V_189 = V_154 -> V_159 ;
V_214 . V_190 = V_154 -> V_159 * V_215 ;
V_214 . V_191 = V_188 - V_214 . V_190 ;
V_214 . V_208 = false ;
if ( V_154 -> V_5 & V_225 )
V_214 . V_208 = true ;
V_214 . V_193 = V_28 -> V_193 ;
V_214 . V_207 = 1 ;
if ( V_28 -> V_226 != V_227 )
V_214 . V_207 = 2 ;
V_214 . V_192 = 4 ;
V_214 . V_210 = V_210 ;
V_214 . V_174 = F_42 ( V_2 ) ;
V_214 . V_200 = V_200 ;
V_216 = F_52 ( F_54 ( & V_214 ) , ( T_1 ) 65535 ) ;
if ( ! F_55 ( & V_214 ) ||
! F_56 ( & V_214 ) ||
! F_57 ( & V_214 ) ||
( V_2 -> V_19 . V_228 == 2 ) ) {
F_41 ( L_2 ) ;
}
if ( V_2 -> V_221 . V_222 ) {
V_213 . V_173 =
F_59 ( V_2 , true ) * 10 ;
V_213 . V_180 =
F_60 ( V_2 , true ) * 10 ;
} else {
V_213 . V_173 = V_2 -> V_221 . V_223 * 10 ;
V_213 . V_180 = V_2 -> V_221 . V_224 * 10 ;
}
V_213 . V_182 = V_154 -> clock ;
V_213 . V_189 = V_154 -> V_159 ;
V_213 . V_190 = V_154 -> V_159 * V_215 ;
V_213 . V_191 = V_188 - V_213 . V_190 ;
V_213 . V_208 = false ;
if ( V_154 -> V_5 & V_225 )
V_213 . V_208 = true ;
V_213 . V_193 = V_28 -> V_193 ;
V_213 . V_207 = 1 ;
if ( V_28 -> V_226 != V_227 )
V_213 . V_207 = 2 ;
V_213 . V_192 = 4 ;
V_213 . V_210 = V_210 ;
V_213 . V_174 = F_42 ( V_2 ) ;
V_213 . V_200 = V_200 ;
V_217 = F_52 ( F_54 ( & V_213 ) , ( T_1 ) 65535 ) ;
if ( ! F_55 ( & V_213 ) ||
! F_56 ( & V_213 ) ||
! F_57 ( & V_213 ) ||
( V_2 -> V_19 . V_228 == 2 ) ) {
F_41 ( L_2 ) ;
}
V_219 = F_61 ( V_210 , V_154 -> V_159 ) ;
}
V_218 = F_4 ( V_229 + V_28 -> V_31 ) ;
V_60 = V_218 ;
V_60 &= ~ ( 3 << V_230 ) ;
V_60 |= ( 1 << V_230 ) ;
F_3 ( V_229 + V_28 -> V_31 , V_60 ) ;
F_3 ( V_231 + V_28 -> V_31 ,
( ( V_216 << V_232 ) |
( V_188 << V_233 ) ) ) ;
V_60 = F_4 ( V_229 + V_28 -> V_31 ) ;
V_60 &= ~ ( 3 << V_230 ) ;
V_60 |= ( 2 << V_230 ) ;
F_3 ( V_229 + V_28 -> V_31 , V_60 ) ;
F_3 ( V_231 + V_28 -> V_31 ,
( ( V_217 << V_232 ) |
( V_188 << V_233 ) ) ) ;
F_3 ( V_229 + V_28 -> V_31 , V_218 ) ;
V_28 -> V_188 = V_188 ;
V_28 -> V_214 = V_216 ;
V_28 -> V_213 = V_217 ;
V_28 -> V_219 = V_219 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_153 * V_154 = NULL ;
T_1 V_200 = 0 , V_210 ;
int V_18 ;
F_63 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_29 [ V_18 ] -> V_157 . V_158 )
V_200 ++ ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_154 = & V_2 -> V_19 . V_29 [ V_18 ] -> V_157 . V_154 ;
V_210 = F_40 ( V_2 , V_2 -> V_19 . V_29 [ V_18 ] , V_154 ) ;
F_58 ( V_2 , V_2 -> V_19 . V_29 [ V_18 ] ,
V_210 , V_200 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
int V_18 ;
T_1 V_234 , V_60 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_235 . V_236 ; V_18 ++ ) {
V_234 = V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_234 ;
V_60 = F_65 ( V_234 ,
V_238 ) ;
if ( ( ( V_60 &
V_239 ) >>
V_240 ) == 1 )
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_41 = false ;
else
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_41 = true ;
}
}
static struct V_241 * F_66 ( struct V_1 * V_2 )
{
int V_18 ;
F_64 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_235 . V_236 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_41 )
return & V_2 -> V_19 . V_235 . V_237 [ V_18 ] ;
}
F_67 ( L_3 ) ;
return NULL ;
}
static void F_68 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
T_1 V_234 ;
if ( ! V_243 || ! V_243 -> V_245 || ! V_243 -> V_245 -> V_237 )
return;
V_234 = V_243 -> V_245 -> V_234 ;
F_3 ( V_246 + V_234 ,
( V_243 -> V_245 -> V_237 -> V_247 << V_248 ) ) ;
}
static void F_69 ( struct V_131 * V_132 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = V_132 -> V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
struct V_76 * V_77 ;
struct V_81 * V_81 = NULL ;
T_1 V_60 = 0 , V_234 ;
if ( ! V_243 || ! V_243 -> V_245 || ! V_243 -> V_245 -> V_237 )
return;
V_234 = V_243 -> V_245 -> V_237 -> V_234 ;
F_22 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_77 -> V_132 == V_132 ) {
V_81 = F_23 ( V_77 ) ;
break;
}
}
if ( ! V_81 ) {
F_67 ( L_4 ) ;
return;
}
if ( V_154 -> V_5 & V_225 ) {
if ( V_77 -> V_249 [ 1 ] )
V_60 =
( V_77 -> V_250 [ 1 ] <<
V_251 ) |
( V_77 -> V_252 [ 1 ] <<
V_253 ) ;
else
V_60 =
( 0 <<
V_251 ) |
( 0 <<
V_253 ) ;
} else {
if ( V_77 -> V_249 [ 0 ] )
V_60 =
( V_77 -> V_250 [ 0 ] <<
V_251 ) |
( V_77 -> V_252 [ 0 ] <<
V_253 ) ;
else
V_60 =
( 0 <<
V_251 ) |
( 0 <<
V_253 ) ;
}
F_70 ( V_234 , V_254 , V_60 ) ;
}
static void F_71 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
struct V_76 * V_77 ;
struct V_81 * V_81 = NULL ;
T_1 V_234 , V_60 ;
T_4 * V_255 = NULL ;
int V_256 ;
if ( ! V_243 || ! V_243 -> V_245 || ! V_243 -> V_245 -> V_237 )
return;
V_234 = V_243 -> V_245 -> V_237 -> V_234 ;
F_22 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_77 -> V_132 == V_132 ) {
V_81 = F_23 ( V_77 ) ;
break;
}
}
if ( ! V_81 ) {
F_67 ( L_4 ) ;
return;
}
V_256 = F_72 ( F_73 ( V_77 ) , & V_255 ) ;
if ( V_256 < 0 ) {
F_67 ( L_5 , V_256 ) ;
V_256 = 0 ;
}
V_60 = F_65 ( V_234 , V_257 ) ;
V_60 &= ~ ( V_258 |
V_259 ) ;
V_60 |= V_260 ;
if ( V_256 )
V_60 |= ( V_255 [ 0 ] << V_261 ) ;
else
V_60 |= ( 5 << V_261 ) ;
F_70 ( V_234 , V_257 , V_60 ) ;
F_74 ( V_255 ) ;
}
static void F_75 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
T_1 V_234 ;
struct V_76 * V_77 ;
struct V_81 * V_81 = NULL ;
struct V_262 * V_263 ;
int V_18 , V_256 ;
static const T_5 V_264 [] [ 2 ] = {
{ V_265 , V_266 } ,
{ V_267 , V_268 } ,
{ V_269 , V_270 } ,
{ V_271 , V_272 } ,
{ V_273 , V_274 } ,
{ V_275 , V_276 } ,
{ V_277 , V_278 } ,
{ V_279 , V_280 } ,
{ V_281 , V_282 } ,
{ V_283 , V_284 } ,
{ V_285 , V_286 } ,
{ V_287 , V_288 } ,
} ;
if ( ! V_243 || ! V_243 -> V_245 || ! V_243 -> V_245 -> V_237 )
return;
V_234 = V_243 -> V_245 -> V_237 -> V_234 ;
F_22 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_77 -> V_132 == V_132 ) {
V_81 = F_23 ( V_77 ) ;
break;
}
}
if ( ! V_81 ) {
F_67 ( L_4 ) ;
return;
}
V_256 = F_76 ( F_73 ( V_77 ) , & V_263 ) ;
if ( V_256 <= 0 ) {
F_67 ( L_6 , V_256 ) ;
return;
}
F_77 ( ! V_263 ) ;
for ( V_18 = 0 ; V_18 < F_78 ( V_264 ) ; V_18 ++ ) {
T_1 V_289 = 0 ;
T_4 V_290 = 0 ;
int V_291 = - 1 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_256 ; V_95 ++ ) {
struct V_262 * V_292 = & V_263 [ V_95 ] ;
if ( V_292 -> V_293 == V_264 [ V_18 ] [ 1 ] ) {
if ( V_292 -> V_294 > V_291 ) {
V_289 = ( V_292 -> V_294 <<
V_295 ) |
( V_292 -> V_296 <<
V_297 ) |
( V_292 -> V_298 <<
V_299 ) ;
V_291 = V_292 -> V_294 ;
}
if ( V_292 -> V_293 == V_266 )
V_290 |= V_292 -> V_298 ;
else
break;
}
}
V_289 |= ( V_290 <<
V_300 ) ;
F_70 ( V_234 , V_264 [ V_18 ] [ 0 ] , V_289 ) ;
}
F_74 ( V_263 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_241 * V_237 ,
bool V_301 )
{
if ( ! V_237 )
return;
F_70 ( V_237 -> V_234 , V_302 ,
V_301 ? V_303 : 0 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_18 ;
if ( ! V_304 )
return 0 ;
V_2 -> V_19 . V_235 . V_158 = true ;
if ( V_2 -> V_305 == V_306 )
V_2 -> V_19 . V_235 . V_236 = 7 ;
else if ( ( V_2 -> V_305 == V_307 ) ||
( V_2 -> V_305 == V_308 ) )
V_2 -> V_19 . V_235 . V_236 = 3 ;
else if ( ( V_2 -> V_305 == V_309 ) ||
( V_2 -> V_305 == V_310 ) )
V_2 -> V_19 . V_235 . V_236 = 7 ;
else
V_2 -> V_19 . V_235 . V_236 = 3 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_235 . V_236 ; V_18 ++ ) {
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_294 = - 1 ;
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_311 = - 1 ;
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_312 = - 1 ;
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_313 = 0 ;
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_314 = 0 ;
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_41 = false ;
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_234 = V_315 [ V_18 ] ;
V_2 -> V_19 . V_235 . V_237 [ V_18 ] . V_247 = V_18 ;
F_79 ( V_2 , & V_2 -> V_19 . V_235 . V_237 [ V_18 ] , false ) ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
int V_18 ;
if ( ! V_304 )
return;
if ( ! V_2 -> V_19 . V_235 . V_158 )
return;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_235 . V_236 ; V_18 ++ )
F_79 ( V_2 , & V_2 -> V_19 . V_235 . V_237 [ V_18 ] , false ) ;
V_2 -> V_19 . V_235 . V_158 = false ;
}
static void F_82 ( struct V_131 * V_132 , T_6 clock )
{
struct V_73 * V_74 = V_132 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_316 V_317 = V_316 ( clock ) ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
T_6 V_234 = V_243 -> V_245 -> V_234 ;
F_3 ( V_318 + V_234 , ( V_317 . V_319 << V_320 ) ) ;
F_3 ( V_321 + V_234 , V_317 . V_322 ) ;
F_3 ( V_323 + V_234 , ( V_317 . V_324 << V_320 ) ) ;
F_3 ( V_325 + V_234 , V_317 . V_326 ) ;
F_3 ( V_327 + V_234 , ( V_317 . V_328 << V_329 ) ) ;
F_3 ( V_330 + V_234 , V_317 . V_331 ) ;
}
static void F_83 ( struct V_131 * V_132 ,
void * V_332 , T_7 V_333 )
{
struct V_73 * V_74 = V_132 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
T_6 V_234 = V_243 -> V_245 -> V_234 ;
T_8 * V_334 = V_332 + 3 ;
T_8 * V_335 = V_332 ;
F_3 ( V_336 + V_234 ,
V_334 [ 0x0 ] | ( V_334 [ 0x1 ] << 8 ) | ( V_334 [ 0x2 ] << 16 ) | ( V_334 [ 0x3 ] << 24 ) ) ;
F_3 ( V_337 + V_234 ,
V_334 [ 0x4 ] | ( V_334 [ 0x5 ] << 8 ) | ( V_334 [ 0x6 ] << 16 ) | ( V_334 [ 0x7 ] << 24 ) ) ;
F_3 ( V_338 + V_234 ,
V_334 [ 0x8 ] | ( V_334 [ 0x9 ] << 8 ) | ( V_334 [ 0xA ] << 16 ) | ( V_334 [ 0xB ] << 24 ) ) ;
F_3 ( V_339 + V_234 ,
V_334 [ 0xC ] | ( V_334 [ 0xD ] << 8 ) | ( V_335 [ 1 ] << 24 ) ) ;
}
static void F_84 ( struct V_131 * V_132 , T_1 clock )
{
struct V_73 * V_74 = V_132 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
struct V_28 * V_28 = F_37 ( V_132 -> V_11 ) ;
T_1 V_340 = 24 * 1000 ;
T_1 V_341 = clock ;
if ( ! V_243 || ! V_243 -> V_245 )
return;
F_3 ( V_342 , ( V_28 -> V_25 << V_343 ) ) ;
F_3 ( V_344 , V_340 ) ;
F_3 ( V_345 , V_341 ) ;
}
static void F_85 ( struct V_131 * V_132 ,
struct V_153 * V_154 )
{
struct V_73 * V_74 = V_132 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
struct V_76 * V_77 = F_38 ( V_132 ) ;
T_4 V_332 [ V_346 + V_347 ] ;
struct V_348 V_334 ;
T_6 V_234 , V_349 ;
T_9 V_350 ;
int V_135 = 8 ;
if ( ! V_243 || ! V_243 -> V_245 )
return;
if ( ! V_243 -> V_245 -> V_158 )
return;
V_234 = V_243 -> V_245 -> V_234 ;
if ( V_132 -> V_11 ) {
struct V_28 * V_28 = F_37 ( V_132 -> V_11 ) ;
V_135 = V_28 -> V_135 ;
}
V_243 -> V_245 -> V_237 = F_66 ( V_2 ) ;
F_79 ( V_2 , V_243 -> V_245 -> V_237 , false ) ;
F_84 ( V_132 , V_154 -> clock ) ;
F_3 ( V_351 + V_234 ,
V_352 ) ;
F_3 ( V_353 + V_234 , 0x1000 ) ;
V_349 = F_4 ( V_354 + V_234 ) ;
V_349 &= ~ V_355 ;
V_349 &= ~ V_356 ;
switch ( V_135 ) {
case 0 :
case 6 :
case 8 :
case 16 :
default:
F_86 ( L_7 ,
V_77 -> V_357 , V_135 ) ;
break;
case 10 :
V_349 |= V_355 ;
V_349 |= 1 << V_358 ;
F_86 ( L_8 ,
V_77 -> V_357 ) ;
break;
case 12 :
V_349 |= V_355 ;
V_349 |= 2 << V_358 ;
F_86 ( L_9 ,
V_77 -> V_357 ) ;
break;
}
F_3 ( V_354 + V_234 , V_349 ) ;
F_3 ( V_351 + V_234 ,
V_352 |
V_359 |
V_360 ) ;
F_3 ( V_361 + V_234 ,
V_362 |
V_363 ) ;
F_3 ( V_364 + V_234 ,
V_365 ) ;
F_3 ( V_366 + V_234 ,
( 2 << V_367 ) ) ;
F_3 ( V_368 + V_234 , 0 ) ;
F_3 ( V_369 + V_234 ,
( 1 << V_370 ) |
( 3 << V_371 ) ) ;
F_3 ( V_372 + V_234 ,
V_373 ) ;
if ( V_135 > 8 )
F_3 ( V_374 + V_234 ,
V_375 ) ;
else
F_3 ( V_374 + V_234 ,
V_376 |
V_375 ) ;
F_82 ( V_132 , V_154 -> clock ) ;
F_3 ( V_377 + V_234 ,
( 1 << V_378 ) ) ;
F_3 ( V_379 + V_234 ,
( 2 << V_380 ) ) ;
F_3 ( V_381 + V_234 ,
( 3 << V_382 ) |
( 4 << V_383 ) |
( 5 << V_384 ) |
( 6 << V_385 ) |
( 7 << V_386 ) |
( 8 << V_387 ) ) ;
F_71 ( V_132 ) ;
F_3 ( V_388 + V_234 ,
( 0xff << V_389 ) ) ;
F_68 ( V_132 ) ;
F_75 ( V_132 ) ;
F_69 ( V_132 , V_154 ) ;
V_350 = F_87 ( & V_334 , V_154 ) ;
if ( V_350 < 0 ) {
F_67 ( L_10 , V_350 ) ;
return;
}
V_350 = F_88 ( & V_334 , V_332 , sizeof( V_332 ) ) ;
if ( V_350 < 0 ) {
F_67 ( L_11 , V_350 ) ;
return;
}
F_83 ( V_132 , V_332 , sizeof( V_332 ) ) ;
F_89 ( V_361 + V_234 ,
V_390 |
V_390 ) ;
F_90 ( V_366 + V_234 ,
( 2 << V_391 ) ,
~ V_392 ) ;
F_89 ( V_372 + V_234 ,
V_393 ) ;
F_3 ( V_394 + V_234 , 0x00FFFFFF ) ;
F_3 ( V_395 + V_234 , 0x007FFFFF ) ;
F_3 ( V_396 + V_234 , 0x00000001 ) ;
F_3 ( V_397 + V_234 , 0x00000001 ) ;
F_79 ( V_2 , V_243 -> V_245 -> V_237 , true ) ;
}
static void F_91 ( struct V_131 * V_132 , bool V_301 )
{
struct V_73 * V_74 = V_132 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
if ( ! V_243 || ! V_243 -> V_245 )
return;
if ( V_301 && V_243 -> V_245 -> V_158 )
return;
if ( ! V_301 && ! V_243 -> V_245 -> V_158 )
return;
if ( ! V_301 && V_243 -> V_245 -> V_237 ) {
F_79 ( V_2 , V_243 -> V_245 -> V_237 , false ) ;
V_243 -> V_245 -> V_237 = NULL ;
}
V_243 -> V_245 -> V_158 = V_301 ;
F_86 ( L_12 ,
V_301 ? L_13 : L_14 , V_243 -> V_245 -> V_234 , V_134 -> V_141 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_398 ; V_18 ++ )
V_2 -> V_19 . V_245 [ V_18 ] = NULL ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_398 ; V_18 ++ ) {
V_2 -> V_19 . V_245 [ V_18 ] = F_93 ( sizeof( struct V_399 ) , V_400 ) ;
if ( V_2 -> V_19 . V_245 [ V_18 ] ) {
V_2 -> V_19 . V_245 [ V_18 ] -> V_234 = V_401 [ V_18 ] ;
V_2 -> V_19 . V_245 [ V_18 ] -> V_247 = V_18 ;
} else {
int V_95 ;
for ( V_95 = 0 ; V_95 < V_18 ; V_95 ++ ) {
F_74 ( V_2 -> V_19 . V_245 [ V_95 ] ) ;
V_2 -> V_19 . V_245 [ V_95 ] = NULL ;
}
return - V_402 ;
}
}
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_398 ; V_18 ++ ) {
F_74 ( V_2 -> V_19 . V_245 [ V_18 ] ) ;
V_2 -> V_19 . V_245 [ V_18 ] = NULL ;
}
}
static void F_95 ( struct V_403 * V_11 , bool V_301 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
T_1 V_404 ;
V_404 = F_4 ( V_405 [ V_28 -> V_25 ] ) & ~ 1 ;
if ( V_301 )
F_3 ( V_405 [ V_28 -> V_25 ] , V_404 | 1 ) ;
else
F_3 ( V_405 [ V_28 -> V_25 ] , V_404 ) ;
}
static void F_96 ( struct V_403 * V_11 , bool V_301 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
if ( V_301 )
F_3 ( V_406 + V_28 -> V_31 , 1 ) ;
else
F_3 ( V_406 + V_28 -> V_31 , 0 ) ;
}
static int F_97 ( struct V_403 * V_11 ,
struct V_407 * V_408 ,
int V_409 , int V_410 , int V_411 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_412 * V_413 ;
struct V_407 * V_414 ;
struct V_415 * V_416 ;
struct V_417 * V_418 ;
T_10 V_419 , V_420 ;
T_6 V_421 , V_422 ;
T_1 V_423 = ( V_424 << V_425 ) ;
T_1 V_426 ;
T_1 V_427 , V_428 ;
int V_6 ;
bool V_429 = false ;
if ( ! V_411 && ! V_11 -> V_430 -> V_408 ) {
F_41 ( L_15 ) ;
return 0 ;
}
if ( V_411 ) {
V_413 = F_98 ( V_408 ) ;
V_414 = V_408 ;
} else {
V_413 = F_98 ( V_11 -> V_430 -> V_408 ) ;
V_414 = V_11 -> V_430 -> V_408 ;
}
V_416 = V_413 -> V_416 ;
V_418 = F_99 ( V_416 ) ;
V_6 = F_100 ( V_418 , false ) ;
if ( F_101 ( V_6 != 0 ) )
return V_6 ;
if ( V_411 ) {
V_419 = F_102 ( V_418 ) ;
} else {
V_6 = F_103 ( V_418 , V_431 , & V_419 ) ;
if ( F_101 ( V_6 != 0 ) ) {
F_104 ( V_418 ) ;
return - V_37 ;
}
}
F_105 ( V_418 , & V_420 ) ;
F_104 ( V_418 ) ;
V_426 = F_106 ( V_420 , V_432 ) ;
switch ( V_414 -> V_433 ) {
case V_434 :
V_421 = ( ( V_435 << V_436 ) |
( V_437 << V_438 ) ) ;
break;
case V_439 :
case V_440 :
V_421 = ( ( V_441 << V_436 ) |
( V_442 << V_438 ) ) ;
#ifdef F_107
V_423 = ( V_443 << V_425 ) ;
#endif
break;
case V_444 :
case V_445 :
V_421 = ( ( V_441 << V_436 ) |
( V_442 << V_438 ) ) ;
#ifdef F_107
V_423 = ( V_443 << V_425 ) ;
#endif
break;
case V_446 :
case V_447 :
V_421 = ( ( V_441 << V_436 ) |
( V_448 << V_438 ) ) ;
#ifdef F_107
V_423 = ( V_443 << V_425 ) ;
#endif
break;
case V_449 :
V_421 = ( ( V_441 << V_436 ) |
( V_450 << V_438 ) ) ;
#ifdef F_107
V_423 = ( V_443 << V_425 ) ;
#endif
break;
case V_451 :
case V_452 :
V_421 = ( ( V_453 << V_436 ) |
( V_454 << V_438 ) ) ;
#ifdef F_107
V_423 = ( V_455 << V_425 ) ;
#endif
break;
case V_456 :
case V_457 :
V_421 = ( ( V_453 << V_436 ) |
( V_458 << V_438 ) ) ;
#ifdef F_107
V_423 = ( V_455 << V_425 ) ;
#endif
V_429 = true ;
break;
case V_459 :
case V_460 :
V_421 = ( ( V_453 << V_436 ) |
( V_461 << V_438 ) ) ;
#ifdef F_107
V_423 = ( V_455 << V_425 ) ;
#endif
V_429 = true ;
break;
default:
F_67 ( L_16 ,
F_108 ( V_414 -> V_433 ) ) ;
return - V_37 ;
}
if ( F_106 ( V_420 , V_462 ) == V_463 ) {
unsigned V_464 , V_465 , V_466 , V_467 , V_468 ;
V_464 = F_106 ( V_420 , V_469 ) ;
V_465 = F_106 ( V_420 , V_470 ) ;
V_466 = F_106 ( V_420 , V_471 ) ;
V_467 = F_106 ( V_420 , V_472 ) ;
V_468 = F_106 ( V_420 , V_473 ) ;
V_421 |= ( V_468 << V_474 ) ;
V_421 |= ( V_475 << V_476 ) ;
V_421 |= ( V_467 << V_477 ) ;
V_421 |= ( V_464 << V_478 ) ;
V_421 |= ( V_465 << V_479 ) ;
V_421 |= ( V_466 << V_480 ) ;
V_421 |= ( V_481 << V_482 ) ;
} else if ( F_106 ( V_420 , V_462 ) == V_483 ) {
V_421 |= ( V_484 << V_476 ) ;
}
V_421 |= ( V_426 << V_485 ) ;
F_95 ( V_11 , false ) ;
F_3 ( V_30 + V_28 -> V_31 , 0 ) ;
F_3 ( V_33 + V_28 -> V_31 ,
F_16 ( V_419 ) ) ;
F_3 ( V_112 + V_28 -> V_31 ,
F_16 ( V_419 ) ) ;
F_3 ( V_34 + V_28 -> V_31 ,
( T_1 ) V_419 & V_486 ) ;
F_3 ( V_113 + V_28 -> V_31 ,
( T_1 ) V_419 & V_487 ) ;
F_3 ( V_488 + V_28 -> V_31 , V_421 ) ;
F_3 ( V_489 + V_28 -> V_31 , V_423 ) ;
F_90 ( V_490 + V_28 -> V_31 ,
( V_429 ? V_491 : 0 ) ,
~ V_491 ) ;
if ( V_429 )
F_41 ( L_17 ) ;
F_3 ( V_492 + V_28 -> V_31 , 0 ) ;
F_3 ( V_493 + V_28 -> V_31 , 0 ) ;
F_3 ( V_494 + V_28 -> V_31 , 0 ) ;
F_3 ( V_495 + V_28 -> V_31 , 0 ) ;
F_3 ( V_496 + V_28 -> V_31 , V_414 -> V_497 ) ;
F_3 ( V_498 + V_28 -> V_31 , V_414 -> V_499 ) ;
V_422 = V_414 -> V_500 [ 0 ] / ( V_414 -> V_501 / 8 ) ;
F_3 ( V_502 + V_28 -> V_31 , V_422 ) ;
F_96 ( V_11 , true ) ;
F_3 ( V_503 + V_28 -> V_31 ,
V_414 -> V_499 ) ;
V_409 &= ~ 3 ;
V_410 &= ~ 1 ;
F_3 ( V_504 + V_28 -> V_31 ,
( V_409 << 16 ) | V_410 ) ;
V_427 = V_11 -> V_154 . V_505 ;
V_428 = ( V_11 -> V_154 . V_506 + 1 ) & ~ 1 ;
F_3 ( V_507 + V_28 -> V_31 ,
( V_427 << 16 ) | V_428 ) ;
F_3 ( V_114 + V_28 -> V_31 , 3 ) ;
if ( ! V_411 && V_408 && V_408 != V_11 -> V_430 -> V_408 ) {
V_413 = F_98 ( V_408 ) ;
V_418 = F_99 ( V_413 -> V_416 ) ;
V_6 = F_100 ( V_418 , false ) ;
if ( F_101 ( V_6 != 0 ) )
return V_6 ;
F_109 ( V_418 ) ;
F_104 ( V_418 ) ;
}
F_62 ( V_2 ) ;
return 0 ;
}
static void F_110 ( struct V_403 * V_11 ,
struct V_153 * V_154 )
{
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_28 * V_28 = F_37 ( V_11 ) ;
if ( V_154 -> V_5 & V_225 )
F_3 ( V_508 + V_28 -> V_31 ,
V_509 ) ;
else
F_3 ( V_508 + V_28 -> V_31 , 0 ) ;
}
static void F_111 ( struct V_403 * V_11 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
int V_18 ;
F_41 ( L_18 , V_28 -> V_25 ) ;
F_3 ( V_510 + V_28 -> V_31 ,
( ( V_511 << V_512 ) |
( V_511 << V_513 ) ) ) ;
F_3 ( V_514 + V_28 -> V_31 ,
V_515 ) ;
F_3 ( V_516 + V_28 -> V_31 ,
V_517 ) ;
F_3 ( V_518 + V_28 -> V_31 ,
( ( V_519 << V_520 ) |
( V_519 << V_521 ) ) ) ;
F_3 ( V_522 + V_28 -> V_31 , 0 ) ;
F_3 ( V_523 + V_28 -> V_31 , 0 ) ;
F_3 ( V_524 + V_28 -> V_31 , 0 ) ;
F_3 ( V_525 + V_28 -> V_31 , 0 ) ;
F_3 ( V_526 + V_28 -> V_31 , 0xffff ) ;
F_3 ( V_527 + V_28 -> V_31 , 0xffff ) ;
F_3 ( V_528 + V_28 -> V_31 , 0xffff ) ;
F_3 ( V_529 + V_28 -> V_31 , 0 ) ;
F_3 ( V_530 + V_28 -> V_31 , 0x00000007 ) ;
F_3 ( V_531 + V_28 -> V_31 , 0 ) ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
F_3 ( V_532 + V_28 -> V_31 ,
( V_28 -> V_533 [ V_18 ] << 20 ) |
( V_28 -> V_534 [ V_18 ] << 10 ) |
( V_28 -> V_535 [ V_18 ] << 0 ) ) ;
}
F_3 ( V_536 + V_28 -> V_31 ,
( ( V_537 << V_538 ) |
( V_537 << V_539 ) |
( V_537 << V_540 ) ) ) ;
F_3 ( V_541 + V_28 -> V_31 ,
( ( V_542 << V_543 ) |
( V_542 << V_544 ) ) ) ;
F_3 ( V_545 + V_28 -> V_31 ,
( ( V_546 << V_547 ) |
( V_546 << V_548 ) ) ) ;
F_3 ( V_549 + V_28 -> V_31 ,
( ( V_550 << V_551 ) |
( V_550 << V_552 ) ) ) ;
F_3 ( 0x1a50 + V_28 -> V_31 , 0 ) ;
F_3 ( V_553 + V_28 -> V_31 ,
V_554 ) ;
}
static int F_112 ( struct V_131 * V_132 )
{
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 = V_134 -> V_244 ;
switch ( V_134 -> V_141 ) {
case V_555 :
if ( V_243 -> V_556 )
return 1 ;
else
return 0 ;
break;
case V_557 :
if ( V_243 -> V_556 )
return 3 ;
else
return 2 ;
break;
case V_558 :
if ( V_243 -> V_556 )
return 5 ;
else
return 4 ;
break;
case V_559 :
return 6 ;
break;
default:
F_67 ( L_19 , V_134 -> V_141 ) ;
return 0 ;
}
}
static T_1 F_113 ( struct V_403 * V_11 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
T_1 V_560 ;
int V_561 ;
if ( F_114 ( F_115 ( V_28 -> V_132 ) ) ) {
if ( V_2 -> clock . V_562 )
return V_563 ;
else {
V_561 = F_116 ( V_11 ) ;
if ( V_561 != V_563 )
return V_561 ;
}
} else {
V_561 = F_117 ( V_11 ) ;
if ( V_561 != V_563 )
return V_561 ;
}
if ( ( V_2 -> V_305 == V_307 ) ||
( V_2 -> V_305 == V_308 ) ) {
V_560 = F_118 ( V_11 ) ;
if ( ! ( V_560 & ( 1 << V_564 ) ) )
return V_564 ;
if ( ! ( V_560 & ( 1 << V_565 ) ) )
return V_565 ;
F_67 ( L_20 ) ;
return V_563 ;
} else {
V_560 = F_118 ( V_11 ) ;
if ( ! ( V_560 & ( 1 << V_564 ) ) )
return V_564 ;
if ( ! ( V_560 & ( 1 << V_565 ) ) )
return V_565 ;
if ( ! ( V_560 & ( 1 << V_566 ) ) )
return V_566 ;
F_67 ( L_20 ) ;
return V_563 ;
}
return V_563 ;
}
static void F_119 ( struct V_403 * V_11 , bool V_567 )
{
struct V_1 * V_2 = V_11 -> V_74 -> V_133 ;
struct V_28 * V_28 = F_37 ( V_11 ) ;
T_6 V_568 ;
V_568 = F_4 ( V_569 + V_28 -> V_31 ) ;
if ( V_567 )
V_568 |= V_570 ;
else
V_568 &= ~ V_570 ;
F_3 ( V_569 + V_28 -> V_31 , V_568 ) ;
}
static void F_120 ( struct V_403 * V_11 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_74 -> V_133 ;
F_121 ( V_571 + V_28 -> V_31 ,
( V_572 << V_573 ) |
( V_574 << V_575 ) ) ;
}
static void F_122 ( struct V_403 * V_11 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_74 -> V_133 ;
F_3 ( V_576 + V_28 -> V_31 ,
F_16 ( V_28 -> V_577 ) ) ;
F_3 ( V_578 + V_28 -> V_31 ,
F_17 ( V_28 -> V_577 ) ) ;
F_121 ( V_571 + V_28 -> V_31 ,
V_579 |
( V_572 << V_573 ) |
( V_574 << V_575 ) ) ;
}
static int F_123 ( struct V_403 * V_11 ,
int V_409 , int V_410 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_74 -> V_133 ;
int V_580 = 0 , V_581 = 0 ;
V_409 += V_11 -> V_409 ;
V_410 += V_11 -> V_410 ;
F_86 ( L_21 , V_409 , V_410 , V_11 -> V_409 , V_11 -> V_410 ) ;
if ( V_409 < 0 ) {
V_580 = F_52 ( - V_409 , V_28 -> V_582 - 1 ) ;
V_409 = 0 ;
}
if ( V_410 < 0 ) {
V_581 = F_52 ( - V_410 , V_28 -> V_583 - 1 ) ;
V_410 = 0 ;
}
F_3 ( V_584 + V_28 -> V_31 , ( V_409 << 16 ) | V_410 ) ;
F_3 ( V_585 + V_28 -> V_31 , ( V_580 << 16 ) | V_581 ) ;
F_3 ( V_586 + V_28 -> V_31 ,
( ( V_28 -> V_587 - 1 ) << 16 ) | ( V_28 -> V_588 - 1 ) ) ;
V_28 -> V_589 = V_409 ;
V_28 -> V_590 = V_410 ;
return 0 ;
}
static int F_124 ( struct V_403 * V_11 ,
int V_409 , int V_410 )
{
int V_591 ;
F_119 ( V_11 , true ) ;
V_591 = F_123 ( V_11 , V_409 , V_410 ) ;
F_119 ( V_11 , false ) ;
return V_591 ;
}
static int F_125 ( struct V_403 * V_11 ,
struct V_592 * V_593 ,
T_6 V_594 ,
T_6 V_497 ,
T_6 V_499 ,
T_11 V_595 ,
T_11 V_596 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_415 * V_416 ;
struct V_417 * V_597 ;
int V_591 ;
if ( ! V_594 ) {
F_120 ( V_11 ) ;
V_416 = NULL ;
goto V_598;
}
if ( ( V_497 > V_28 -> V_582 ) ||
( V_499 > V_28 -> V_583 ) ) {
F_67 ( L_22 , V_497 , V_499 ) ;
return - V_37 ;
}
V_416 = F_126 ( V_593 , V_594 ) ;
if ( ! V_416 ) {
F_67 ( L_23 , V_594 , V_28 -> V_25 ) ;
return - V_599 ;
}
V_597 = F_99 ( V_416 ) ;
V_591 = F_100 ( V_597 , false ) ;
if ( V_591 != 0 ) {
F_127 ( V_416 ) ;
return V_591 ;
}
V_591 = F_103 ( V_597 , V_431 , & V_28 -> V_577 ) ;
F_104 ( V_597 ) ;
if ( V_591 ) {
F_67 ( L_24 , V_591 ) ;
F_127 ( V_416 ) ;
return V_591 ;
}
V_28 -> V_587 = V_497 ;
V_28 -> V_588 = V_499 ;
F_119 ( V_11 , true ) ;
if ( V_595 != V_28 -> V_600 ||
V_596 != V_28 -> V_601 ) {
int V_409 , V_410 ;
V_409 = V_28 -> V_589 + V_28 -> V_600 - V_595 ;
V_410 = V_28 -> V_590 + V_28 -> V_601 - V_596 ;
F_123 ( V_11 , V_409 , V_410 ) ;
V_28 -> V_600 = V_595 ;
V_28 -> V_601 = V_596 ;
}
F_122 ( V_11 ) ;
F_119 ( V_11 , false ) ;
V_598:
if ( V_28 -> V_602 ) {
struct V_417 * V_597 = F_99 ( V_28 -> V_602 ) ;
V_591 = F_100 ( V_597 , false ) ;
if ( F_128 ( V_591 == 0 ) ) {
F_109 ( V_597 ) ;
F_104 ( V_597 ) ;
}
F_127 ( V_28 -> V_602 ) ;
}
V_28 -> V_602 = V_416 ;
return 0 ;
}
static void F_129 ( struct V_403 * V_11 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
if ( V_28 -> V_602 ) {
F_119 ( V_11 , true ) ;
F_123 ( V_11 , V_28 -> V_589 ,
V_28 -> V_590 ) ;
F_122 ( V_11 ) ;
F_119 ( V_11 , false ) ;
}
}
static void F_130 ( struct V_403 * V_11 , T_5 * V_603 , T_5 * V_604 ,
T_5 * V_605 , T_6 V_606 , T_6 V_333 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
int V_607 = ( V_606 + V_333 > 256 ) ? 256 : V_606 + V_333 , V_18 ;
for ( V_18 = V_606 ; V_18 < V_607 ; V_18 ++ ) {
V_28 -> V_533 [ V_18 ] = V_603 [ V_18 ] >> 6 ;
V_28 -> V_534 [ V_18 ] = V_604 [ V_18 ] >> 6 ;
V_28 -> V_535 [ V_18 ] = V_605 [ V_18 ] >> 6 ;
}
F_111 ( V_11 ) ;
}
static void F_131 ( struct V_403 * V_11 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
F_132 ( V_11 ) ;
F_74 ( V_28 ) ;
}
static void F_133 ( struct V_403 * V_11 , int V_154 )
{
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_28 * V_28 = F_37 ( V_11 ) ;
unsigned type ;
switch ( V_154 ) {
case V_608 :
V_28 -> V_158 = true ;
F_134 ( V_11 , V_609 ) ;
F_95 ( V_11 , true ) ;
F_135 ( V_11 , V_610 ) ;
F_95 ( V_11 , false ) ;
type = F_136 ( V_2 , V_28 -> V_25 ) ;
F_137 ( V_2 , & V_2 -> V_611 , type ) ;
F_137 ( V_2 , & V_2 -> V_24 , type ) ;
F_138 ( V_74 , V_28 -> V_25 ) ;
F_111 ( V_11 ) ;
break;
case V_612 :
case V_613 :
case V_614 :
F_139 ( V_74 , V_28 -> V_25 ) ;
if ( V_28 -> V_158 ) {
F_95 ( V_11 , true ) ;
F_135 ( V_11 , V_609 ) ;
F_95 ( V_11 , false ) ;
}
F_134 ( V_11 , V_610 ) ;
V_28 -> V_158 = false ;
break;
}
F_140 ( V_2 ) ;
}
static void F_141 ( struct V_403 * V_11 )
{
F_142 ( V_11 , V_610 ) ;
F_143 ( V_11 , V_609 ) ;
F_133 ( V_11 , V_614 ) ;
}
static void F_144 ( struct V_403 * V_11 )
{
F_133 ( V_11 , V_608 ) ;
F_143 ( V_11 , V_610 ) ;
}
static void F_145 ( struct V_403 * V_11 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
struct V_615 V_616 ;
int V_18 ;
F_133 ( V_11 , V_614 ) ;
if ( V_11 -> V_430 -> V_408 ) {
int V_6 ;
struct V_412 * V_413 ;
struct V_417 * V_418 ;
V_413 = F_98 ( V_11 -> V_430 -> V_408 ) ;
V_418 = F_99 ( V_413 -> V_416 ) ;
V_6 = F_100 ( V_418 , false ) ;
if ( F_101 ( V_6 ) )
F_67 ( L_25 ) ;
else {
F_109 ( V_418 ) ;
F_104 ( V_418 ) ;
}
}
F_96 ( V_11 , false ) ;
F_142 ( V_11 , V_609 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_29 [ V_18 ] &&
V_2 -> V_19 . V_29 [ V_18 ] -> V_158 &&
V_18 != V_28 -> V_25 &&
V_28 -> V_617 == V_2 -> V_19 . V_29 [ V_18 ] -> V_617 ) {
goto V_618;
}
}
switch ( V_28 -> V_617 ) {
case V_565 :
case V_564 :
F_146 ( V_11 , V_28 -> V_25 , V_28 -> V_617 ,
0 , 0 , V_610 , 0 , 0 , 0 , 0 , 0 , false , & V_616 ) ;
break;
case V_566 :
if ( ( V_2 -> V_305 == V_306 ) ||
( V_2 -> V_305 == V_309 ) ||
( V_2 -> V_305 == V_310 ) )
F_146 ( V_11 , V_28 -> V_25 , V_28 -> V_617 ,
0 , 0 , V_610 , 0 , 0 , 0 , 0 , 0 , false , & V_616 ) ;
break;
default:
break;
}
V_618:
V_28 -> V_617 = V_563 ;
V_28 -> V_619 = 0 ;
V_28 -> V_132 = NULL ;
V_28 -> V_77 = NULL ;
}
static int F_147 ( struct V_403 * V_11 ,
struct V_153 * V_154 ,
struct V_153 * V_620 ,
int V_409 , int V_410 , struct V_407 * V_621 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
if ( ! V_28 -> V_619 )
return - V_37 ;
F_148 ( V_11 , V_620 ) ;
F_149 ( V_11 , V_620 ) ;
F_97 ( V_11 , V_621 , V_409 , V_410 , 0 ) ;
F_150 ( V_11 , V_154 , V_620 ) ;
F_151 ( V_11 ) ;
F_129 ( V_11 ) ;
V_28 -> V_622 = * V_620 ;
return 0 ;
}
static bool F_152 ( struct V_403 * V_11 ,
const struct V_153 * V_154 ,
struct V_153 * V_620 )
{
struct V_28 * V_28 = F_37 ( V_11 ) ;
struct V_73 * V_74 = V_11 -> V_74 ;
struct V_131 * V_132 ;
F_22 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_132 -> V_11 == V_11 ) {
V_28 -> V_132 = V_132 ;
V_28 -> V_77 = F_38 ( V_132 ) ;
break;
}
}
if ( ( V_28 -> V_132 == NULL ) || ( V_28 -> V_77 == NULL ) ) {
V_28 -> V_132 = NULL ;
V_28 -> V_77 = NULL ;
return false ;
}
if ( ! F_153 ( V_11 , V_154 , V_620 ) )
return false ;
if ( F_154 ( V_11 , V_620 ) )
return false ;
V_28 -> V_617 = F_113 ( V_11 ) ;
if ( ( V_28 -> V_617 == V_563 ) &&
! F_114 ( F_115 ( V_28 -> V_132 ) ) )
return false ;
return true ;
}
static int F_155 ( struct V_403 * V_11 , int V_409 , int V_410 ,
struct V_407 * V_621 )
{
return F_97 ( V_11 , V_621 , V_409 , V_410 , 0 ) ;
}
static int F_156 ( struct V_403 * V_11 ,
struct V_407 * V_408 ,
int V_409 , int V_410 , enum V_623 V_624 )
{
return F_97 ( V_11 , V_408 , V_409 , V_410 , 1 ) ;
}
static int F_157 ( struct V_1 * V_2 , int V_625 )
{
struct V_28 * V_28 ;
int V_18 ;
V_28 = F_93 ( sizeof( struct V_28 ) +
( V_626 * sizeof( struct V_76 * ) ) , V_400 ) ;
if ( V_28 == NULL )
return - V_402 ;
F_158 ( V_2 -> V_75 , & V_28 -> V_157 , & V_627 ) ;
F_159 ( & V_28 -> V_157 , 256 ) ;
V_28 -> V_25 = V_625 ;
V_2 -> V_19 . V_29 [ V_625 ] = V_28 ;
V_28 -> V_582 = V_628 ;
V_28 -> V_583 = V_629 ;
V_2 -> V_75 -> V_630 . V_587 = V_28 -> V_582 ;
V_2 -> V_75 -> V_630 . V_588 = V_28 -> V_583 ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
V_28 -> V_533 [ V_18 ] = V_18 << 2 ;
V_28 -> V_534 [ V_18 ] = V_18 << 2 ;
V_28 -> V_535 [ V_18 ] = V_18 << 2 ;
}
V_28 -> V_31 = V_13 [ V_28 -> V_25 ] ;
V_28 -> V_617 = V_563 ;
V_28 -> V_619 = 0 ;
V_28 -> V_132 = NULL ;
V_28 -> V_77 = NULL ;
F_160 ( & V_28 -> V_157 , & V_631 ) ;
return 0 ;
}
static int F_161 ( void * V_594 )
{
struct V_1 * V_2 = (struct V_1 * ) V_594 ;
V_2 -> V_632 = & F_1 ;
V_2 -> V_633 = & F_6 ;
F_162 ( V_2 ) ;
F_163 ( V_2 ) ;
switch ( V_2 -> V_305 ) {
case V_309 :
case V_310 :
V_2 -> V_19 . V_20 = 6 ;
V_2 -> V_19 . V_634 = 6 ;
V_2 -> V_19 . V_398 = 6 ;
break;
case V_306 :
V_2 -> V_19 . V_20 = 4 ;
V_2 -> V_19 . V_634 = 6 ;
V_2 -> V_19 . V_398 = 7 ;
break;
case V_307 :
case V_308 :
V_2 -> V_19 . V_20 = 2 ;
V_2 -> V_19 . V_634 = 6 ;
V_2 -> V_19 . V_398 = 6 ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static int F_164 ( void * V_594 )
{
int V_6 , V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_594 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_6 = F_165 ( V_2 , V_18 + 1 , & V_2 -> V_611 ) ;
if ( V_6 )
return V_6 ;
}
for ( V_18 = 8 ; V_18 < 20 ; V_18 += 2 ) {
V_6 = F_165 ( V_2 , V_18 , & V_2 -> V_24 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_165 ( V_2 , 42 , & V_2 -> V_91 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_75 -> V_630 . V_635 = & V_636 ;
V_2 -> V_75 -> V_630 . V_637 = true ;
V_2 -> V_75 -> V_630 . V_638 = 16384 ;
V_2 -> V_75 -> V_630 . V_639 = 16384 ;
V_2 -> V_75 -> V_630 . V_640 = 24 ;
V_2 -> V_75 -> V_630 . V_641 = 1 ;
V_2 -> V_75 -> V_630 . V_642 = V_2 -> V_110 . V_643 ;
V_6 = F_166 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_75 -> V_630 . V_638 = 16384 ;
V_2 -> V_75 -> V_630 . V_639 = 16384 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_6 = F_157 ( V_2 , V_18 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_167 ( V_2 ) )
F_168 ( V_2 -> V_75 ) ;
else
return - V_37 ;
V_6 = F_92 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_80 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_169 ( V_2 -> V_75 ) ;
V_2 -> V_19 . V_644 = true ;
return 0 ;
}
static int F_170 ( void * V_594 )
{
struct V_1 * V_2 = (struct V_1 * ) V_594 ;
F_74 ( V_2 -> V_19 . V_645 ) ;
F_171 ( V_2 -> V_75 ) ;
F_81 ( V_2 ) ;
F_94 ( V_2 ) ;
F_172 ( V_2 -> V_75 ) ;
V_2 -> V_19 . V_644 = false ;
return 0 ;
}
static int F_173 ( void * V_594 )
{
int V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_594 ;
F_174 ( V_2 ) ;
F_175 ( V_2 , V_2 -> clock . V_646 ) ;
F_21 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_235 . V_236 ; V_18 ++ ) {
F_79 ( V_2 , & V_2 -> V_19 . V_235 . V_237 [ V_18 ] , false ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int F_176 ( void * V_594 )
{
int V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_594 ;
F_24 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_235 . V_236 ; V_18 ++ ) {
F_79 ( V_2 , & V_2 -> V_19 . V_235 . V_237 [ V_18 ] , false ) ;
}
F_13 ( V_2 ) ;
return 0 ;
}
static int F_177 ( void * V_594 )
{
struct V_1 * V_2 = (struct V_1 * ) V_594 ;
F_178 ( V_2 ) ;
return F_176 ( V_594 ) ;
}
static int F_179 ( void * V_594 )
{
struct V_1 * V_2 = (struct V_1 * ) V_594 ;
int V_591 ;
V_591 = F_173 ( V_594 ) ;
F_180 ( V_2 ) ;
if ( V_2 -> V_19 . V_647 ) {
T_4 V_648 = F_181 ( V_2 ,
V_2 -> V_19 . V_647 ) ;
F_182 ( V_2 , V_2 -> V_19 . V_647 ,
V_648 ) ;
}
return V_591 ;
}
static bool F_183 ( void * V_594 )
{
return true ;
}
static int F_184 ( void * V_594 )
{
return 0 ;
}
static int F_185 ( void * V_594 )
{
T_1 V_649 = 0 , V_60 ;
struct V_1 * V_2 = (struct V_1 * ) V_594 ;
if ( F_26 ( V_2 ) )
V_649 |= V_650 ;
if ( V_649 ) {
V_60 = F_4 ( V_651 ) ;
V_60 |= V_649 ;
F_186 ( V_2 -> V_74 , L_26 , V_60 ) ;
F_3 ( V_651 , V_60 ) ;
V_60 = F_4 ( V_651 ) ;
F_27 ( 50 ) ;
V_60 &= ~ V_649 ;
F_3 ( V_651 , V_60 ) ;
V_60 = F_4 ( V_651 ) ;
F_27 ( 50 ) ;
}
return 0 ;
}
static void F_187 ( struct V_1 * V_2 ,
int V_11 ,
enum V_652 V_624 )
{
T_1 V_653 , V_654 ;
if ( V_11 >= V_2 -> V_19 . V_20 ) {
F_86 ( L_27 , V_11 ) ;
return;
}
switch ( V_11 ) {
case 0 :
V_653 = V_655 ;
break;
case 1 :
V_653 = V_656 ;
break;
case 2 :
V_653 = V_657 ;
break;
case 3 :
V_653 = V_658 ;
break;
case 4 :
V_653 = V_659 ;
break;
case 5 :
V_653 = V_660 ;
break;
default:
F_86 ( L_27 , V_11 ) ;
return;
}
switch ( V_624 ) {
case V_661 :
V_654 = F_4 ( V_662 + V_653 ) ;
V_654 &= ~ V_663 ;
F_3 ( V_662 + V_653 , V_654 ) ;
break;
case V_664 :
V_654 = F_4 ( V_662 + V_653 ) ;
V_654 |= V_663 ;
F_3 ( V_662 + V_653 , V_654 ) ;
break;
default:
break;
}
}
static void F_188 ( struct V_1 * V_2 ,
int V_11 ,
enum V_652 V_624 )
{
T_1 V_653 , V_654 ;
if ( V_11 >= V_2 -> V_19 . V_20 ) {
F_86 ( L_27 , V_11 ) ;
return;
}
switch ( V_11 ) {
case 0 :
V_653 = V_655 ;
break;
case 1 :
V_653 = V_656 ;
break;
case 2 :
V_653 = V_657 ;
break;
case 3 :
V_653 = V_658 ;
break;
case 4 :
V_653 = V_659 ;
break;
case 5 :
V_653 = V_660 ;
break;
default:
F_86 ( L_27 , V_11 ) ;
return;
}
switch ( V_624 ) {
case V_661 :
V_654 = F_4 ( V_662 + V_653 ) ;
V_654 &= ~ V_665 ;
F_3 ( V_662 + V_653 , V_654 ) ;
break;
case V_664 :
V_654 = F_4 ( V_662 + V_653 ) ;
V_654 |= V_665 ;
F_3 ( V_662 + V_653 , V_654 ) ;
break;
default:
break;
}
}
static int F_189 ( struct V_1 * V_2 ,
struct V_666 * V_667 ,
unsigned type ,
enum V_652 V_624 )
{
T_1 V_668 , V_669 ;
switch ( type ) {
case V_42 :
V_668 = V_61 ;
break;
case V_45 :
V_668 = V_63 ;
break;
case V_48 :
V_668 = V_65 ;
break;
case V_51 :
V_668 = V_67 ;
break;
case V_54 :
V_668 = V_69 ;
break;
case V_57 :
V_668 = V_71 ;
break;
default:
F_86 ( L_28 , type ) ;
return 0 ;
}
switch ( V_624 ) {
case V_661 :
V_669 = F_4 ( V_668 ) ;
V_669 &= ~ V_670 ;
F_3 ( V_668 , V_669 ) ;
break;
case V_664 :
V_669 = F_4 ( V_668 ) ;
V_669 |= V_670 ;
F_3 ( V_668 , V_669 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_190 ( struct V_1 * V_2 ,
struct V_666 * V_667 ,
unsigned type ,
enum V_652 V_624 )
{
switch ( type ) {
case V_671 :
F_187 ( V_2 , 0 , V_624 ) ;
break;
case V_672 :
F_187 ( V_2 , 1 , V_624 ) ;
break;
case V_673 :
F_187 ( V_2 , 2 , V_624 ) ;
break;
case V_674 :
F_187 ( V_2 , 3 , V_624 ) ;
break;
case V_675 :
F_187 ( V_2 , 4 , V_624 ) ;
break;
case V_676 :
F_187 ( V_2 , 5 , V_624 ) ;
break;
case V_677 :
F_188 ( V_2 , 0 , V_624 ) ;
break;
case V_678 :
F_188 ( V_2 , 1 , V_624 ) ;
break;
case V_679 :
F_188 ( V_2 , 2 , V_624 ) ;
break;
case V_680 :
F_188 ( V_2 , 3 , V_624 ) ;
break;
case V_681 :
F_188 ( V_2 , 4 , V_624 ) ;
break;
case V_682 :
F_188 ( V_2 , 5 , V_624 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_191 ( struct V_1 * V_2 ,
struct V_666 * V_683 ,
struct V_684 * V_685 )
{
unsigned V_11 = V_685 -> V_686 - 1 ;
T_6 V_687 = F_4 ( V_688 [ V_11 ] . V_4 ) ;
unsigned V_689 = F_136 ( V_2 , V_11 ) ;
switch ( V_685 -> V_690 ) {
case 0 :
if ( V_687 & V_688 [ V_11 ] . V_691 )
F_3 ( V_692 + V_13 [ V_11 ] , V_693 ) ;
else
F_86 ( L_29 ) ;
if ( F_192 ( V_2 , V_683 , V_689 ) ) {
F_193 ( V_2 -> V_75 , V_11 ) ;
}
F_86 ( L_30 , V_11 + 1 ) ;
break;
case 1 :
if ( V_687 & V_688 [ V_11 ] . V_694 )
F_3 ( V_695 + V_13 [ V_11 ] , V_696 ) ;
else
F_86 ( L_29 ) ;
F_86 ( L_31 , V_11 + 1 ) ;
break;
default:
F_86 ( L_32 , V_685 -> V_686 , V_685 -> V_690 ) ;
break;
}
return 0 ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_666 * V_667 ,
unsigned type ,
enum V_652 V_624 )
{
T_1 V_4 ;
if ( type >= V_2 -> V_19 . V_20 ) {
F_67 ( L_33 , type ) ;
return - V_37 ;
}
V_4 = F_4 ( V_697 + V_13 [ type ] ) ;
if ( V_624 == V_661 )
F_3 ( V_697 + V_13 [ type ] ,
V_4 & ~ V_698 ) ;
else
F_3 ( V_697 + V_13 [ type ] ,
V_4 | V_698 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 ,
struct V_666 * V_683 ,
struct V_684 * V_685 )
{
unsigned long V_5 ;
unsigned V_25 ;
struct V_28 * V_28 ;
struct V_699 * V_700 ;
V_25 = ( V_685 -> V_686 - 8 ) >> 1 ;
V_28 = V_2 -> V_19 . V_29 [ V_25 ] ;
if ( V_25 >= V_2 -> V_19 . V_20 ) {
F_67 ( L_33 , V_25 ) ;
return - V_37 ;
}
if ( F_4 ( V_701 + V_13 [ V_25 ] ) &
V_702 )
F_3 ( V_701 + V_13 [ V_25 ] ,
V_703 ) ;
if ( V_28 == NULL )
return 0 ;
F_2 ( & V_2 -> V_75 -> V_704 , V_5 ) ;
V_700 = V_28 -> V_705 ;
if ( V_28 -> V_706 != V_707 ) {
F_196 ( L_34
L_35 ,
V_28 -> V_706 ,
V_707 ) ;
F_5 ( & V_2 -> V_75 -> V_704 , V_5 ) ;
return 0 ;
}
V_28 -> V_706 = V_708 ;
V_28 -> V_705 = NULL ;
if ( V_700 -> V_709 )
F_197 ( & V_28 -> V_157 , V_700 -> V_709 ) ;
F_5 ( & V_2 -> V_75 -> V_704 , V_5 ) ;
F_198 ( V_2 -> V_75 , V_28 -> V_25 ) ;
F_199 ( & V_700 -> V_710 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_666 * V_683 ,
struct V_684 * V_685 )
{
T_6 V_687 , V_711 , V_712 , V_60 ;
unsigned V_40 ;
if ( V_685 -> V_690 >= V_2 -> V_19 . V_634 ) {
F_86 ( L_32 , V_685 -> V_686 , V_685 -> V_690 ) ;
return 0 ;
}
V_40 = V_685 -> V_690 ;
V_687 = F_4 ( V_688 [ V_40 ] . V_4 ) ;
V_711 = V_688 [ V_40 ] . V_40 ;
V_712 = V_713 [ V_40 ] ;
if ( V_687 & V_711 ) {
V_60 = F_4 ( V_712 ) ;
V_60 |= V_714 ;
F_3 ( V_712 , V_60 ) ;
F_199 ( & V_2 -> V_715 ) ;
F_86 ( L_36 , V_40 + 1 ) ;
}
return 0 ;
}
static int F_201 ( void * V_594 ,
enum V_716 V_624 )
{
return 0 ;
}
static int F_202 ( void * V_594 ,
enum V_717 V_624 )
{
return 0 ;
}
static void
F_203 ( struct V_131 * V_132 ,
struct V_153 * V_154 ,
struct V_153 * V_620 )
{
struct V_134 * V_134 = F_36 ( V_132 ) ;
V_134 -> V_718 = V_620 -> clock ;
F_204 ( V_132 , V_614 ) ;
F_110 ( V_132 -> V_11 , V_154 ) ;
if ( F_115 ( V_132 ) == V_719 ) {
F_91 ( V_132 , true ) ;
F_85 ( V_132 , V_620 ) ;
}
}
static void F_205 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_74 -> V_133 ;
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_76 * V_77 = F_38 ( V_132 ) ;
if ( ( V_134 -> V_720 &
( V_721 | V_140 ) ) ||
( F_206 ( V_132 ) !=
V_722 ) ) {
struct V_242 * V_243 = V_134 -> V_244 ;
if ( V_243 ) {
V_243 -> V_723 = F_112 ( V_132 ) ;
if ( V_134 -> V_720 & V_721 )
V_243 -> V_245 = V_2 -> V_19 . V_245 [ V_243 -> V_723 ] ;
}
}
F_207 ( V_2 , true ) ;
if ( V_77 ) {
struct V_81 * V_81 = F_23 ( V_77 ) ;
if ( V_81 -> V_724 . V_725 )
F_208 ( V_81 ) ;
if ( V_77 -> V_82 == V_83 )
F_209 ( V_77 ,
V_726 ) ;
}
F_210 ( V_132 ) ;
F_35 ( V_132 ) ;
}
static void F_211 ( struct V_131 * V_132 )
{
struct V_73 * V_74 = V_132 -> V_74 ;
struct V_1 * V_2 = V_74 -> V_133 ;
F_204 ( V_132 , V_608 ) ;
F_207 ( V_2 , false ) ;
}
static void F_212 ( struct V_131 * V_132 )
{
struct V_134 * V_134 = F_36 ( V_132 ) ;
struct V_242 * V_243 ;
F_204 ( V_132 , V_614 ) ;
if ( F_213 ( V_132 ) ) {
if ( F_115 ( V_132 ) == V_719 )
F_91 ( V_132 , false ) ;
V_243 = V_134 -> V_244 ;
V_243 -> V_723 = - 1 ;
}
V_134 -> V_720 = 0 ;
}
static void F_214 ( struct V_131 * V_132 )
{
}
static void F_215 ( struct V_131 * V_132 )
{
}
static void
F_216 ( struct V_131 * V_132 ,
struct V_153 * V_154 ,
struct V_153 * V_620 )
{
}
static void F_217 ( struct V_131 * V_132 )
{
}
static void
F_218 ( struct V_131 * V_132 , int V_154 )
{
}
static void F_219 ( struct V_131 * V_132 )
{
struct V_134 * V_134 = F_36 ( V_132 ) ;
if ( V_134 -> V_139 & ( V_140 ) )
F_220 ( V_134 ) ;
F_74 ( V_134 -> V_244 ) ;
F_221 ( V_132 ) ;
F_74 ( V_134 ) ;
}
static void F_222 ( struct V_1 * V_2 ,
T_6 V_727 ,
T_6 V_728 ,
T_5 V_729 )
{
struct V_73 * V_74 = V_2 -> V_75 ;
struct V_131 * V_132 ;
struct V_134 * V_134 ;
F_22 (encoder, &dev->mode_config.encoder_list, head) {
V_134 = F_36 ( V_132 ) ;
if ( V_134 -> V_727 == V_727 ) {
V_134 -> V_139 |= V_728 ;
return;
}
}
V_134 = F_93 ( sizeof( struct V_134 ) , V_400 ) ;
if ( ! V_134 )
return;
V_132 = & V_134 -> V_157 ;
switch ( V_2 -> V_19 . V_20 ) {
case 1 :
V_132 -> V_730 = 0x1 ;
break;
case 2 :
default:
V_132 -> V_730 = 0x3 ;
break;
case 4 :
V_132 -> V_730 = 0xf ;
break;
case 6 :
V_132 -> V_730 = 0x3f ;
break;
}
V_134 -> V_244 = NULL ;
V_134 -> V_727 = V_727 ;
V_134 -> V_141 = ( V_727 & V_731 ) >> V_732 ;
V_134 -> V_139 = V_728 ;
V_134 -> V_226 = V_227 ;
V_134 -> V_733 = V_734 ;
V_134 -> V_735 = false ;
V_134 -> V_729 = V_729 ;
switch ( V_134 -> V_141 ) {
case V_142 :
case V_143 :
F_223 ( V_74 , V_132 , & V_736 ,
V_737 , NULL ) ;
F_224 ( V_132 , & V_738 ) ;
break;
case V_739 :
case V_555 :
case V_557 :
case V_558 :
case V_559 :
if ( V_134 -> V_139 & ( V_140 ) ) {
V_134 -> V_226 = V_740 ;
F_223 ( V_74 , V_132 , & V_736 ,
V_741 , NULL ) ;
V_134 -> V_244 = F_225 ( V_134 ) ;
} else if ( V_134 -> V_139 & ( V_742 ) ) {
F_223 ( V_74 , V_132 , & V_736 ,
V_737 , NULL ) ;
V_134 -> V_244 = F_226 ( V_134 ) ;
} else {
F_223 ( V_74 , V_132 , & V_736 ,
V_743 , NULL ) ;
V_134 -> V_244 = F_226 ( V_134 ) ;
}
F_224 ( V_132 , & V_744 ) ;
break;
case V_745 :
case V_746 :
case V_747 :
case V_748 :
case V_749 :
case V_750 :
case V_751 :
case V_752 :
case V_753 :
V_134 -> V_735 = true ;
if ( V_134 -> V_139 & ( V_140 ) )
F_223 ( V_74 , V_132 , & V_736 ,
V_741 , NULL ) ;
else if ( V_134 -> V_139 & ( V_742 ) )
F_223 ( V_74 , V_132 , & V_736 ,
V_737 , NULL ) ;
else
F_223 ( V_74 , V_132 , & V_736 ,
V_743 , NULL ) ;
F_224 ( V_132 , & V_754 ) ;
break;
}
}
static void F_162 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 . V_635 == NULL )
V_2 -> V_19 . V_635 = & V_755 ;
}
static void F_163 ( struct V_1 * V_2 )
{
V_2 -> V_611 . V_756 = V_757 ;
V_2 -> V_611 . V_635 = & V_758 ;
V_2 -> V_24 . V_756 = V_759 ;
V_2 -> V_24 . V_635 = & V_760 ;
V_2 -> V_91 . V_756 = V_761 ;
V_2 -> V_91 . V_635 = & V_762 ;
}
