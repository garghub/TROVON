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
int V_25 , T_2 V_26 )
{
struct V_27 * V_27 = V_2 -> V_19 . V_28 [ V_25 ] ;
F_3 ( V_29 + V_27 -> V_30 ,
F_16 ( V_26 ) ) ;
F_3 ( V_31 + V_27 -> V_30 ,
F_17 ( V_26 ) ) ;
F_4 ( V_31 + V_27 -> V_30 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_11 ,
T_1 * V_32 , T_1 * V_33 )
{
if ( ( V_11 < 0 ) || ( V_11 >= V_2 -> V_19 . V_20 ) )
return - V_34 ;
* V_32 = F_4 ( V_35 + V_13 [ V_11 ] ) ;
* V_33 = F_4 ( V_17 + V_13 [ V_11 ] ) ;
return 0 ;
}
static bool F_19 ( struct V_1 * V_2 ,
enum V_36 V_37 )
{
bool V_38 = false ;
switch ( V_37 ) {
case V_39 :
if ( F_4 ( V_40 ) & V_41 )
V_38 = true ;
break;
case V_42 :
if ( F_4 ( V_43 ) & V_44 )
V_38 = true ;
break;
case V_45 :
if ( F_4 ( V_46 ) & V_47 )
V_38 = true ;
break;
case V_48 :
if ( F_4 ( V_49 ) & V_50 )
V_38 = true ;
break;
case V_51 :
if ( F_4 ( V_52 ) & V_53 )
V_38 = true ;
break;
case V_54 :
if ( F_4 ( V_55 ) & V_56 )
V_38 = true ;
break;
default:
break;
}
return V_38 ;
}
static void F_20 ( struct V_1 * V_2 ,
enum V_36 V_37 )
{
T_1 V_57 ;
bool V_38 = F_19 ( V_2 , V_37 ) ;
switch ( V_37 ) {
case V_39 :
V_57 = F_4 ( V_58 ) ;
if ( V_38 )
V_57 &= ~ V_59 ;
else
V_57 |= V_59 ;
F_3 ( V_58 , V_57 ) ;
break;
case V_42 :
V_57 = F_4 ( V_60 ) ;
if ( V_38 )
V_57 &= ~ V_61 ;
else
V_57 |= V_61 ;
F_3 ( V_60 , V_57 ) ;
break;
case V_45 :
V_57 = F_4 ( V_62 ) ;
if ( V_38 )
V_57 &= ~ V_63 ;
else
V_57 |= V_63 ;
F_3 ( V_62 , V_57 ) ;
break;
case V_48 :
V_57 = F_4 ( V_64 ) ;
if ( V_38 )
V_57 &= ~ V_65 ;
else
V_57 |= V_65 ;
F_3 ( V_64 , V_57 ) ;
break;
case V_51 :
V_57 = F_4 ( V_66 ) ;
if ( V_38 )
V_57 &= ~ V_67 ;
else
V_57 |= V_67 ;
F_3 ( V_66 , V_57 ) ;
break;
case V_54 :
V_57 = F_4 ( V_68 ) ;
if ( V_38 )
V_57 &= ~ V_69 ;
else
V_57 |= V_69 ;
F_3 ( V_68 , V_57 ) ;
break;
default:
break;
}
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = V_2 -> V_72 ;
struct V_73 * V_74 ;
T_1 V_57 = ( 0x9c4 << V_75 ) |
( 0xfa << V_76 ) |
V_77 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
struct V_78 * V_78 = F_23 ( V_74 ) ;
if ( V_74 -> V_79 == V_80 ||
V_74 -> V_79 == V_81 ) {
continue;
}
switch ( V_78 -> V_37 . V_37 ) {
case V_39 :
F_3 ( V_82 , V_57 ) ;
break;
case V_42 :
F_3 ( V_83 , V_57 ) ;
break;
case V_45 :
F_3 ( V_84 , V_57 ) ;
break;
case V_48 :
F_3 ( V_85 , V_57 ) ;
break;
case V_51 :
F_3 ( V_86 , V_57 ) ;
break;
case V_54 :
F_3 ( V_87 , V_57 ) ;
break;
default:
break;
}
F_20 ( V_2 , V_78 -> V_37 . V_37 ) ;
F_12 ( V_2 , & V_2 -> V_88 , V_78 -> V_37 . V_37 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = V_2 -> V_72 ;
struct V_73 * V_74 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
struct V_78 * V_78 = F_23 ( V_74 ) ;
switch ( V_78 -> V_37 . V_37 ) {
case V_39 :
F_3 ( V_82 , 0 ) ;
break;
case V_42 :
F_3 ( V_83 , 0 ) ;
break;
case V_45 :
F_3 ( V_84 , 0 ) ;
break;
case V_48 :
F_3 ( V_85 , 0 ) ;
break;
case V_51 :
F_3 ( V_86 , 0 ) ;
break;
case V_54 :
F_3 ( V_87 , 0 ) ;
break;
default:
break;
}
F_14 ( V_2 , & V_2 -> V_88 , V_78 -> V_37 . V_37 ) ;
}
}
static T_1 F_25 ( struct V_1 * V_2 )
{
return V_89 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_90 = 0 ;
T_1 V_91 [ 6 ] ;
T_1 V_18 , V_92 , V_57 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( F_4 ( V_21 + V_13 [ V_18 ] ) & V_22 ) {
V_91 [ V_18 ] = F_4 ( V_93 + V_13 [ V_18 ] ) ;
V_90 |= ( 1 << V_18 ) ;
}
}
for ( V_92 = 0 ; V_92 < 10 ; V_92 ++ ) {
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_90 & ( 1 << V_18 ) ) {
V_57 = F_4 ( V_93 + V_13 [ V_18 ] ) ;
if ( V_57 != V_91 [ V_18 ] )
V_90 &= ~ ( 1 << V_18 ) ;
}
}
if ( V_90 == 0 )
return false ;
F_27 ( 100 ) ;
}
return true ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
T_1 V_96 , V_57 ;
int V_18 ;
V_95 -> V_97 = F_4 ( V_98 ) ;
V_95 -> V_99 = F_4 ( V_100 ) ;
V_57 = F_4 ( V_98 ) ;
V_57 = F_29 ( V_57 , V_101 , V_102 , 0 ) ;
F_3 ( V_98 , V_57 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_96 = F_30 ( F_4 ( V_21 + V_13 [ V_18 ] ) ,
V_103 , V_104 ) ;
if ( V_96 ) {
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
F_3 ( V_105 + V_13 [ V_18 ] , 1 ) ;
V_57 = F_4 ( V_21 + V_13 [ V_18 ] ) ;
V_57 = F_29 ( V_57 , V_103 , V_104 , 0 ) ;
F_3 ( V_21 + V_13 [ V_18 ] , V_57 ) ;
F_3 ( V_105 + V_13 [ V_18 ] , 0 ) ;
V_95 -> V_96 [ V_18 ] = false ;
#endif
} else {
V_95 -> V_96 [ V_18 ] = false ;
}
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
T_1 V_57 , V_106 ;
int V_18 , V_92 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
F_3 ( V_29 + V_13 [ V_18 ] ,
F_16 ( V_2 -> V_107 . V_108 ) ) ;
F_3 ( V_109 + V_13 [ V_18 ] ,
F_16 ( V_2 -> V_107 . V_108 ) ) ;
F_3 ( V_31 + V_13 [ V_18 ] ,
( T_1 ) V_2 -> V_107 . V_108 ) ;
F_3 ( V_110 + V_13 [ V_18 ] ,
( T_1 ) V_2 -> V_107 . V_108 ) ;
if ( V_95 -> V_96 [ V_18 ] ) {
V_57 = F_4 ( V_111 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_57 , V_112 , V_112 ) != 3 ) {
V_57 = F_29 ( V_57 , V_112 , V_112 , 3 ) ;
F_3 ( V_111 + V_13 [ V_18 ] , V_57 ) ;
}
V_57 = F_4 ( V_113 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_57 , V_114 , V_115 ) ) {
V_57 = F_29 ( V_57 , V_114 , V_115 , 0 ) ;
F_3 ( V_113 + V_13 [ V_18 ] , V_57 ) ;
}
V_57 = F_4 ( V_116 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_57 , V_117 , V_117 ) ) {
V_57 = F_29 ( V_57 , V_117 , V_117 , 0 ) ;
F_3 ( V_116 + V_13 [ V_18 ] , V_57 ) ;
}
for ( V_92 = 0 ; V_92 < V_2 -> V_118 ; V_92 ++ ) {
V_57 = F_4 ( V_113 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_57 , V_114 , V_119 ) == 0 )
break;
F_27 ( 1 ) ;
}
V_57 = F_4 ( V_120 + V_13 [ V_18 ] ) ;
V_57 = F_29 ( V_57 , V_121 , V_122 , 0 ) ;
F_3 ( V_105 + V_13 [ V_18 ] , 1 ) ;
F_3 ( V_120 + V_13 [ V_18 ] , V_57 ) ;
F_3 ( V_105 + V_13 [ V_18 ] , 0 ) ;
V_106 = F_32 ( V_2 , V_18 ) ;
for ( V_92 = 0 ; V_92 < V_2 -> V_118 ; V_92 ++ ) {
if ( F_32 ( V_2 , V_18 ) != V_106 )
break;
F_27 ( 1 ) ;
}
}
}
F_3 ( V_123 , F_16 ( V_2 -> V_107 . V_108 ) ) ;
F_3 ( V_124 , F_17 ( V_2 -> V_107 . V_108 ) ) ;
F_3 ( V_100 , V_95 -> V_99 ) ;
F_33 ( 1 ) ;
F_3 ( V_98 , V_95 -> V_97 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
bool V_125 )
{
T_1 V_57 ;
V_57 = F_4 ( V_100 ) ;
if ( V_125 )
V_57 = F_29 ( V_57 , V_126 , V_127 , 0 ) ;
else
V_57 = F_29 ( V_57 , V_126 , V_127 , 1 ) ;
F_3 ( V_100 , V_57 ) ;
V_57 = F_4 ( V_98 ) ;
if ( V_125 )
V_57 = F_29 ( V_57 , V_101 , V_102 , 1 ) ;
else
V_57 = F_29 ( V_57 , V_101 , V_102 , 0 ) ;
F_3 ( V_98 , V_57 ) ;
}
static void F_35 ( struct V_128 * V_129 )
{
struct V_70 * V_71 = V_129 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_27 * V_27 = F_37 ( V_129 -> V_11 ) ;
struct V_73 * V_74 = F_38 ( V_129 ) ;
int V_132 = 0 ;
T_1 V_57 = 0 ;
enum V_133 V_134 = V_135 ;
if ( V_74 ) {
struct V_78 * V_78 = F_23 ( V_74 ) ;
V_132 = F_39 ( V_74 ) ;
V_134 = V_78 -> V_134 ;
}
if ( V_131 -> V_136 & V_137 )
return;
if ( ( V_131 -> V_138 == V_139 ) ||
( V_131 -> V_138 == V_140 ) )
return;
if ( V_132 == 0 )
return;
switch ( V_132 ) {
case 6 :
if ( V_134 == V_141 )
V_57 |= ( V_142 |
V_143 |
V_144 |
( 0 << V_145 ) ) ;
else
V_57 |= ( V_146 |
( 0 << V_147 ) ) ;
break;
case 8 :
if ( V_134 == V_141 )
V_57 |= ( V_142 |
V_143 |
V_148 |
V_144 |
( 1 << V_145 ) ) ;
else
V_57 |= ( V_146 |
( 1 << V_147 ) ) ;
break;
case 10 :
if ( V_134 == V_141 )
V_57 |= ( V_142 |
V_143 |
V_148 |
V_144 |
( 2 << V_145 ) ) ;
else
V_57 |= ( V_146 |
( 2 << V_147 ) ) ;
break;
default:
break;
}
F_3 ( V_149 + V_27 -> V_30 , V_57 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_27 * V_27 ,
struct V_150 * V_151 )
{
T_1 V_57 , V_152 , V_18 ;
T_1 V_153 = V_27 -> V_25 * 0x8 ;
if ( V_27 -> V_154 . V_155 && V_151 ) {
if ( V_151 -> V_156 < 1920 ) {
V_57 = 1 ;
V_152 = 2 ;
} else if ( V_151 -> V_156 < 2560 ) {
V_57 = 2 ;
V_152 = 2 ;
} else if ( V_151 -> V_156 < 4096 ) {
V_57 = 0 ;
V_152 = ( V_2 -> V_5 & V_157 ) ? 2 : 4 ;
} else {
F_41 ( L_1 ) ;
V_57 = 0 ;
V_152 = ( V_2 -> V_5 & V_157 ) ? 2 : 4 ;
}
} else {
V_57 = 1 ;
V_152 = 0 ;
}
F_3 ( V_158 + V_27 -> V_30 ,
( V_57 << V_159 ) |
( 0x6B0 << V_160 ) ) ;
F_3 ( V_161 + V_153 ,
( V_152 << V_162 ) ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_118 ; V_18 ++ ) {
if ( F_4 ( V_161 + V_153 ) &
V_163 )
break;
F_27 ( 1 ) ;
}
if ( V_27 -> V_154 . V_155 && V_151 ) {
switch ( V_57 ) {
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
T_1 V_57 = F_4 ( V_164 ) ;
switch ( ( V_57 & V_165 ) >> V_166 ) {
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
static T_1 F_43 ( struct V_167 * V_168 )
{
T_3 V_169 ;
T_3 V_170 , V_171 , V_172 ;
T_3 V_173 ;
V_173 . V_174 = F_44 ( 1000 ) ;
V_170 . V_174 = F_44 ( V_168 -> V_170 ) ;
V_170 . V_174 = F_45 ( V_170 , V_173 ) ;
V_171 . V_174 = F_44 ( V_168 -> V_171 * 4 ) ;
V_173 . V_174 = F_44 ( 10 ) ;
V_169 . V_174 = F_44 ( 7 ) ;
V_169 . V_174 = F_45 ( V_169 , V_173 ) ;
V_172 . V_174 = F_46 ( V_171 , V_170 ) ;
V_172 . V_174 = F_46 ( V_172 , V_169 ) ;
return F_47 ( V_172 ) ;
}
static T_1 F_48 ( struct V_167 * V_168 )
{
T_3 V_175 ;
T_3 V_170 , V_171 , V_172 ;
T_3 V_173 ;
V_173 . V_174 = F_44 ( 1000 ) ;
V_170 . V_174 = F_44 ( V_168 -> V_170 ) ;
V_170 . V_174 = F_45 ( V_170 , V_173 ) ;
V_171 . V_174 = F_44 ( V_168 -> V_171 * 4 ) ;
V_173 . V_174 = F_44 ( 10 ) ;
V_175 . V_174 = F_44 ( 3 ) ;
V_175 . V_174 = F_45 ( V_175 , V_173 ) ;
V_172 . V_174 = F_46 ( V_171 , V_170 ) ;
V_172 . V_174 = F_46 ( V_172 , V_175 ) ;
return F_47 ( V_172 ) ;
}
static T_1 F_49 ( struct V_167 * V_168 )
{
T_3 V_176 ;
T_3 V_177 , V_172 ;
T_3 V_173 ;
V_173 . V_174 = F_44 ( 1000 ) ;
V_177 . V_174 = F_44 ( V_168 -> V_177 ) ;
V_177 . V_174 = F_45 ( V_177 , V_173 ) ;
V_173 . V_174 = F_44 ( 10 ) ;
V_176 . V_174 = F_44 ( 8 ) ;
V_176 . V_174 = F_45 ( V_176 , V_173 ) ;
V_173 . V_174 = F_44 ( 32 ) ;
V_172 . V_174 = F_46 ( V_173 , V_177 ) ;
V_172 . V_174 = F_46 ( V_172 , V_176 ) ;
return F_47 ( V_172 ) ;
}
static T_1 F_50 ( struct V_167 * V_168 )
{
T_3 V_178 ;
T_3 V_179 , V_172 ;
T_3 V_173 , V_180 ;
V_173 . V_174 = F_44 ( 1000 ) ;
V_179 . V_174 = F_44 ( V_168 -> V_179 ) ;
V_179 . V_174 = F_45 ( V_179 , V_173 ) ;
V_173 . V_174 = F_44 ( 32 ) ;
V_180 . V_174 = F_46 ( V_173 , V_179 ) ;
V_173 . V_174 = F_44 ( 10 ) ;
V_178 . V_174 = F_44 ( 8 ) ;
V_178 . V_174 = F_45 ( V_178 , V_173 ) ;
V_172 . V_174 = F_46 ( V_180 , V_178 ) ;
return F_47 ( V_172 ) ;
}
static T_1 F_51 ( struct V_167 * V_168 )
{
T_1 V_181 = F_43 ( V_168 ) ;
T_1 V_182 = F_49 ( V_168 ) ;
T_1 V_183 = F_50 ( V_168 ) ;
return F_52 ( V_181 , F_52 ( V_182 , V_183 ) ) ;
}
static T_1 F_53 ( struct V_167 * V_168 )
{
T_3 V_184 ;
T_3 V_185 ;
T_3 V_186 ;
T_3 V_172 ;
T_3 V_173 ;
V_173 . V_174 = F_44 ( 1000 ) ;
V_185 . V_174 = F_44 ( V_168 -> V_187 + V_168 -> V_188 ) ;
V_185 . V_174 = F_45 ( V_185 , V_173 ) ;
V_184 . V_174 = F_44 ( V_168 -> V_189 ) ;
V_186 . V_174 = F_44 ( V_168 -> V_186 ) ;
V_172 . V_174 = F_46 ( V_186 , V_184 ) ;
V_172 . V_174 = F_46 ( V_172 , V_168 -> V_190 ) ;
V_172 . V_174 = F_45 ( V_172 , V_185 ) ;
return F_47 ( V_172 ) ;
}
static T_1 F_54 ( struct V_167 * V_168 )
{
T_1 V_191 = 2000 ;
T_1 V_192 = F_51 ( V_168 ) ;
T_1 V_193 = ( 512 * 8 * 1000 ) / V_192 ;
T_1 V_194 = ( 128 * 4 * 1000 ) / V_192 ;
T_1 V_195 = 40000000 / V_168 -> V_179 ;
T_1 V_196 = ( ( V_168 -> V_197 + 1 ) * V_193 ) +
( V_168 -> V_197 * V_194 ) ;
T_1 V_198 = V_191 + V_196 + V_195 ;
T_1 V_199 , V_200 , V_201 ;
T_1 V_57 , V_202 = 12288 ;
T_3 V_173 , V_180 , V_203 ;
if ( V_168 -> V_197 == 0 )
return 0 ;
V_173 . V_174 = F_44 ( 2 ) ;
V_180 . V_174 = F_44 ( 1 ) ;
if ( ( V_168 -> V_190 . V_174 > V_173 . V_174 ) ||
( ( V_168 -> V_190 . V_174 > V_180 . V_174 ) && ( V_168 -> V_204 >= 3 ) ) ||
( V_168 -> V_204 >= 5 ) ||
( ( V_168 -> V_190 . V_174 >= V_173 . V_174 ) && V_168 -> V_205 ) )
V_199 = 4 ;
else
V_199 = 2 ;
V_173 . V_174 = F_44 ( V_192 ) ;
V_180 . V_174 = F_44 ( V_168 -> V_197 ) ;
V_173 . V_174 = F_45 ( V_173 , V_180 ) ;
V_180 . V_174 = F_44 ( V_191 + 512 ) ;
V_203 . V_174 = F_44 ( V_168 -> V_179 ) ;
V_180 . V_174 = F_45 ( V_180 , V_203 ) ;
V_203 . V_174 = F_44 ( V_202 ) ;
V_180 . V_174 = F_45 ( V_203 , V_180 ) ;
V_57 = F_52 ( F_47 ( V_173 ) , F_47 ( V_180 ) ) ;
V_180 . V_174 = F_44 ( 1000 ) ;
V_203 . V_174 = F_44 ( V_168 -> V_179 ) ;
V_180 . V_174 = F_45 ( V_203 , V_180 ) ;
V_203 . V_174 = F_44 ( V_168 -> V_189 ) ;
V_180 . V_174 = F_46 ( V_180 , V_203 ) ;
V_200 = F_52 ( V_57 , F_47 ( V_180 ) ) ;
V_173 . V_174 = F_44 ( V_199 * V_168 -> V_186 * V_168 -> V_189 ) ;
V_180 . V_174 = F_44 ( 1000 ) ;
V_203 . V_174 = F_44 ( V_200 ) ;
V_180 . V_174 = F_45 ( V_203 , V_180 ) ;
V_173 . V_174 = F_45 ( V_173 , V_180 ) ;
V_201 = F_47 ( V_173 ) ;
if ( V_201 < V_168 -> V_187 )
return V_198 ;
else
return V_198 + ( V_201 - V_168 -> V_187 ) ;
}
static bool F_55 ( struct V_167 * V_168 )
{
if ( F_53 ( V_168 ) <=
( F_48 ( V_168 ) / V_168 -> V_197 ) )
return true ;
else
return false ;
}
static bool F_56 ( struct V_167 * V_168 )
{
if ( F_53 ( V_168 ) <=
( F_51 ( V_168 ) / V_168 -> V_197 ) )
return true ;
else
return false ;
}
static bool F_57 ( struct V_167 * V_168 )
{
T_1 V_206 = V_168 -> V_207 / V_168 -> V_186 ;
T_1 V_185 = V_168 -> V_187 + V_168 -> V_188 ;
T_1 V_208 ;
T_1 V_209 ;
T_3 V_173 ;
V_173 . V_174 = F_44 ( 1 ) ;
if ( V_168 -> V_190 . V_174 > V_173 . V_174 )
V_208 = 1 ;
else {
if ( V_206 <= ( V_168 -> V_204 + 1 ) )
V_208 = 1 ;
else
V_208 = 2 ;
}
V_209 = ( V_208 * V_185 + V_168 -> V_188 ) ;
if ( F_54 ( V_168 ) <= V_209 )
return true ;
else
return false ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_27 * V_27 ,
T_1 V_207 , T_1 V_197 )
{
struct V_150 * V_151 = & V_27 -> V_154 . V_151 ;
struct V_167 V_210 , V_211 ;
T_1 V_212 ;
T_1 V_185 = 0 ;
T_1 V_213 = 0 , V_214 = 0 ;
T_1 V_57 , V_215 , V_216 = 0 ;
if ( V_27 -> V_154 . V_155 && V_197 && V_151 ) {
V_212 = 1000000 / ( T_1 ) V_151 -> clock ;
V_185 = F_52 ( ( T_1 ) V_151 -> V_217 * V_212 , ( T_1 ) 65535 ) ;
if ( V_2 -> V_218 . V_219 ) {
V_211 . V_170 =
F_59 ( V_2 , false ) * 10 ;
V_211 . V_177 =
F_60 ( V_2 , false ) * 10 ;
} else {
V_211 . V_170 = V_2 -> V_218 . V_220 * 10 ;
V_211 . V_177 = V_2 -> V_218 . V_221 * 10 ;
}
V_211 . V_179 = V_151 -> clock ;
V_211 . V_186 = V_151 -> V_156 ;
V_211 . V_187 = V_151 -> V_156 * V_212 ;
V_211 . V_188 = V_185 - V_211 . V_187 ;
V_211 . V_205 = false ;
if ( V_151 -> V_5 & V_222 )
V_211 . V_205 = true ;
V_211 . V_190 = V_27 -> V_190 ;
V_211 . V_204 = 1 ;
if ( V_27 -> V_223 != V_224 )
V_211 . V_204 = 2 ;
V_211 . V_189 = 4 ;
V_211 . V_207 = V_207 ;
V_211 . V_171 = F_42 ( V_2 ) ;
V_211 . V_197 = V_197 ;
V_213 = F_52 ( F_54 ( & V_211 ) , ( T_1 ) 65535 ) ;
if ( ! F_55 ( & V_211 ) ||
! F_56 ( & V_211 ) ||
! F_57 ( & V_211 ) ||
( V_2 -> V_19 . V_225 == 2 ) ) {
F_41 ( L_2 ) ;
}
if ( V_2 -> V_218 . V_219 ) {
V_210 . V_170 =
F_59 ( V_2 , true ) * 10 ;
V_210 . V_177 =
F_60 ( V_2 , true ) * 10 ;
} else {
V_210 . V_170 = V_2 -> V_218 . V_220 * 10 ;
V_210 . V_177 = V_2 -> V_218 . V_221 * 10 ;
}
V_210 . V_179 = V_151 -> clock ;
V_210 . V_186 = V_151 -> V_156 ;
V_210 . V_187 = V_151 -> V_156 * V_212 ;
V_210 . V_188 = V_185 - V_210 . V_187 ;
V_210 . V_205 = false ;
if ( V_151 -> V_5 & V_222 )
V_210 . V_205 = true ;
V_210 . V_190 = V_27 -> V_190 ;
V_210 . V_204 = 1 ;
if ( V_27 -> V_223 != V_224 )
V_210 . V_204 = 2 ;
V_210 . V_189 = 4 ;
V_210 . V_207 = V_207 ;
V_210 . V_171 = F_42 ( V_2 ) ;
V_210 . V_197 = V_197 ;
V_214 = F_52 ( F_54 ( & V_210 ) , ( T_1 ) 65535 ) ;
if ( ! F_55 ( & V_210 ) ||
! F_56 ( & V_210 ) ||
! F_57 ( & V_210 ) ||
( V_2 -> V_19 . V_225 == 2 ) ) {
F_41 ( L_2 ) ;
}
V_216 = F_61 ( V_207 , V_151 -> V_156 ) ;
}
V_215 = F_4 ( V_226 + V_27 -> V_30 ) ;
V_57 = V_215 ;
V_57 &= ~ ( 3 << V_227 ) ;
V_57 |= ( 1 << V_227 ) ;
F_3 ( V_226 + V_27 -> V_30 , V_57 ) ;
F_3 ( V_228 + V_27 -> V_30 ,
( ( V_213 << V_229 ) |
( V_185 << V_230 ) ) ) ;
V_57 = F_4 ( V_226 + V_27 -> V_30 ) ;
V_57 &= ~ ( 3 << V_227 ) ;
V_57 |= ( 2 << V_227 ) ;
F_3 ( V_226 + V_27 -> V_30 , V_57 ) ;
F_3 ( V_228 + V_27 -> V_30 ,
( ( V_214 << V_229 ) |
( V_185 << V_230 ) ) ) ;
F_3 ( V_226 + V_27 -> V_30 , V_215 ) ;
V_27 -> V_185 = V_185 ;
V_27 -> V_211 = V_213 ;
V_27 -> V_210 = V_214 ;
V_27 -> V_216 = V_216 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_150 * V_151 = NULL ;
T_1 V_197 = 0 , V_207 ;
int V_18 ;
F_63 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_28 [ V_18 ] -> V_154 . V_155 )
V_197 ++ ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_151 = & V_2 -> V_19 . V_28 [ V_18 ] -> V_154 . V_151 ;
V_207 = F_40 ( V_2 , V_2 -> V_19 . V_28 [ V_18 ] , V_151 ) ;
F_58 ( V_2 , V_2 -> V_19 . V_28 [ V_18 ] ,
V_207 , V_197 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
int V_18 ;
T_1 V_231 , V_57 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
V_231 = V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_231 ;
V_57 = F_65 ( V_231 ,
V_235 ) ;
if ( ( ( V_57 &
V_236 ) >>
V_237 ) == 1 )
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_38 = false ;
else
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_38 = true ;
}
}
static struct V_238 * F_66 ( struct V_1 * V_2 )
{
int V_18 ;
F_64 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_38 )
return & V_2 -> V_19 . V_232 . V_234 [ V_18 ] ;
}
F_67 ( L_3 ) ;
return NULL ;
}
static void F_68 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
T_1 V_231 ;
if ( ! V_240 || ! V_240 -> V_242 || ! V_240 -> V_242 -> V_234 )
return;
V_231 = V_240 -> V_242 -> V_231 ;
F_3 ( V_243 + V_231 ,
( V_240 -> V_242 -> V_234 -> V_244 << V_245 ) ) ;
}
static void F_69 ( struct V_128 * V_129 ,
struct V_150 * V_151 )
{
struct V_1 * V_2 = V_129 -> V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
struct V_73 * V_74 ;
struct V_78 * V_78 = NULL ;
T_1 V_57 = 0 , V_231 ;
if ( ! V_240 || ! V_240 -> V_242 || ! V_240 -> V_242 -> V_234 )
return;
V_231 = V_240 -> V_242 -> V_234 -> V_231 ;
F_22 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_74 -> V_129 == V_129 ) {
V_78 = F_23 ( V_74 ) ;
break;
}
}
if ( ! V_78 ) {
F_67 ( L_4 ) ;
return;
}
if ( V_151 -> V_5 & V_222 ) {
if ( V_74 -> V_246 [ 1 ] )
V_57 =
( V_74 -> V_247 [ 1 ] <<
V_248 ) |
( V_74 -> V_249 [ 1 ] <<
V_250 ) ;
else
V_57 =
( 0 <<
V_248 ) |
( 0 <<
V_250 ) ;
} else {
if ( V_74 -> V_246 [ 0 ] )
V_57 =
( V_74 -> V_247 [ 0 ] <<
V_248 ) |
( V_74 -> V_249 [ 0 ] <<
V_250 ) ;
else
V_57 =
( 0 <<
V_248 ) |
( 0 <<
V_250 ) ;
}
F_70 ( V_231 , V_251 , V_57 ) ;
}
static void F_71 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
struct V_73 * V_74 ;
struct V_78 * V_78 = NULL ;
T_1 V_231 , V_57 ;
T_4 * V_252 = NULL ;
int V_253 ;
if ( ! V_240 || ! V_240 -> V_242 || ! V_240 -> V_242 -> V_234 )
return;
V_231 = V_240 -> V_242 -> V_234 -> V_231 ;
F_22 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_74 -> V_129 == V_129 ) {
V_78 = F_23 ( V_74 ) ;
break;
}
}
if ( ! V_78 ) {
F_67 ( L_4 ) ;
return;
}
V_253 = F_72 ( F_73 ( V_74 ) , & V_252 ) ;
if ( V_253 < 0 ) {
F_67 ( L_5 , V_253 ) ;
V_253 = 0 ;
}
V_57 = F_65 ( V_231 , V_254 ) ;
V_57 &= ~ ( V_255 |
V_256 ) ;
V_57 |= V_257 ;
if ( V_253 )
V_57 |= ( V_252 [ 0 ] << V_258 ) ;
else
V_57 |= ( 5 << V_258 ) ;
F_70 ( V_231 , V_254 , V_57 ) ;
F_74 ( V_252 ) ;
}
static void F_75 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
T_1 V_231 ;
struct V_73 * V_74 ;
struct V_78 * V_78 = NULL ;
struct V_259 * V_260 ;
int V_18 , V_253 ;
static const T_5 V_261 [] [ 2 ] = {
{ V_262 , V_263 } ,
{ V_264 , V_265 } ,
{ V_266 , V_267 } ,
{ V_268 , V_269 } ,
{ V_270 , V_271 } ,
{ V_272 , V_273 } ,
{ V_274 , V_275 } ,
{ V_276 , V_277 } ,
{ V_278 , V_279 } ,
{ V_280 , V_281 } ,
{ V_282 , V_283 } ,
{ V_284 , V_285 } ,
} ;
if ( ! V_240 || ! V_240 -> V_242 || ! V_240 -> V_242 -> V_234 )
return;
V_231 = V_240 -> V_242 -> V_234 -> V_231 ;
F_22 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_74 -> V_129 == V_129 ) {
V_78 = F_23 ( V_74 ) ;
break;
}
}
if ( ! V_78 ) {
F_67 ( L_4 ) ;
return;
}
V_253 = F_76 ( F_73 ( V_74 ) , & V_260 ) ;
if ( V_253 <= 0 ) {
F_67 ( L_6 , V_253 ) ;
return;
}
F_77 ( ! V_260 ) ;
for ( V_18 = 0 ; V_18 < F_78 ( V_261 ) ; V_18 ++ ) {
T_1 V_286 = 0 ;
T_4 V_287 = 0 ;
int V_288 = - 1 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_253 ; V_92 ++ ) {
struct V_259 * V_289 = & V_260 [ V_92 ] ;
if ( V_289 -> V_290 == V_261 [ V_18 ] [ 1 ] ) {
if ( V_289 -> V_291 > V_288 ) {
V_286 = ( V_289 -> V_291 <<
V_292 ) |
( V_289 -> V_293 <<
V_294 ) |
( V_289 -> V_295 <<
V_296 ) ;
V_288 = V_289 -> V_291 ;
}
if ( V_289 -> V_290 == V_263 )
V_287 |= V_289 -> V_295 ;
else
break;
}
}
V_286 |= ( V_287 <<
V_297 ) ;
F_70 ( V_231 , V_261 [ V_18 ] [ 0 ] , V_286 ) ;
}
F_74 ( V_260 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_238 * V_234 ,
bool V_298 )
{
if ( ! V_234 )
return;
F_70 ( V_234 -> V_231 , V_299 ,
V_298 ? V_300 : 0 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_18 ;
if ( ! V_301 )
return 0 ;
V_2 -> V_19 . V_232 . V_155 = true ;
if ( V_2 -> V_302 == V_303 )
V_2 -> V_19 . V_232 . V_233 = 7 ;
else if ( ( V_2 -> V_302 == V_304 ) ||
( V_2 -> V_302 == V_305 ) )
V_2 -> V_19 . V_232 . V_233 = 3 ;
else if ( ( V_2 -> V_302 == V_306 ) ||
( V_2 -> V_302 == V_307 ) )
V_2 -> V_19 . V_232 . V_233 = 7 ;
else
V_2 -> V_19 . V_232 . V_233 = 3 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_291 = - 1 ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_308 = - 1 ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_309 = - 1 ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_310 = 0 ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_311 = 0 ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_38 = false ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_231 = V_312 [ V_18 ] ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_244 = V_18 ;
F_79 ( V_2 , & V_2 -> V_19 . V_232 . V_234 [ V_18 ] , false ) ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
int V_18 ;
if ( ! V_2 -> V_19 . V_232 . V_155 )
return;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ )
F_79 ( V_2 , & V_2 -> V_19 . V_232 . V_234 [ V_18 ] , false ) ;
V_2 -> V_19 . V_232 . V_155 = false ;
}
static void F_82 ( struct V_128 * V_129 , T_6 clock )
{
struct V_70 * V_71 = V_129 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_313 V_314 = V_313 ( clock ) ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
T_6 V_231 = V_240 -> V_242 -> V_231 ;
F_3 ( V_315 + V_231 , ( V_314 . V_316 << V_317 ) ) ;
F_3 ( V_318 + V_231 , V_314 . V_319 ) ;
F_3 ( V_320 + V_231 , ( V_314 . V_321 << V_317 ) ) ;
F_3 ( V_322 + V_231 , V_314 . V_323 ) ;
F_3 ( V_324 + V_231 , ( V_314 . V_325 << V_326 ) ) ;
F_3 ( V_327 + V_231 , V_314 . V_328 ) ;
}
static void F_83 ( struct V_128 * V_129 ,
void * V_329 , T_7 V_330 )
{
struct V_70 * V_71 = V_129 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
T_6 V_231 = V_240 -> V_242 -> V_231 ;
T_8 * V_331 = V_329 + 3 ;
T_8 * V_332 = V_329 ;
F_3 ( V_333 + V_231 ,
V_331 [ 0x0 ] | ( V_331 [ 0x1 ] << 8 ) | ( V_331 [ 0x2 ] << 16 ) | ( V_331 [ 0x3 ] << 24 ) ) ;
F_3 ( V_334 + V_231 ,
V_331 [ 0x4 ] | ( V_331 [ 0x5 ] << 8 ) | ( V_331 [ 0x6 ] << 16 ) | ( V_331 [ 0x7 ] << 24 ) ) ;
F_3 ( V_335 + V_231 ,
V_331 [ 0x8 ] | ( V_331 [ 0x9 ] << 8 ) | ( V_331 [ 0xA ] << 16 ) | ( V_331 [ 0xB ] << 24 ) ) ;
F_3 ( V_336 + V_231 ,
V_331 [ 0xC ] | ( V_331 [ 0xD ] << 8 ) | ( V_332 [ 1 ] << 24 ) ) ;
}
static void F_84 ( struct V_128 * V_129 , T_1 clock )
{
struct V_70 * V_71 = V_129 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
struct V_27 * V_27 = F_37 ( V_129 -> V_11 ) ;
T_1 V_337 = 24 * 1000 ;
T_1 V_338 = clock ;
if ( ! V_240 || ! V_240 -> V_242 )
return;
F_3 ( V_339 , ( V_27 -> V_25 << V_340 ) ) ;
F_3 ( V_341 , V_337 ) ;
F_3 ( V_342 , V_338 ) ;
}
static void F_85 ( struct V_128 * V_129 ,
struct V_150 * V_151 )
{
struct V_70 * V_71 = V_129 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
struct V_73 * V_74 = F_38 ( V_129 ) ;
T_4 V_329 [ V_343 + V_344 ] ;
struct V_345 V_331 ;
T_6 V_231 , V_346 ;
T_9 V_347 ;
int V_132 = 8 ;
if ( ! V_240 || ! V_240 -> V_242 )
return;
if ( ! V_240 -> V_242 -> V_155 )
return;
V_231 = V_240 -> V_242 -> V_231 ;
if ( V_129 -> V_11 ) {
struct V_27 * V_27 = F_37 ( V_129 -> V_11 ) ;
V_132 = V_27 -> V_132 ;
}
V_240 -> V_242 -> V_234 = F_66 ( V_2 ) ;
F_79 ( V_2 , V_240 -> V_242 -> V_234 , false ) ;
F_84 ( V_129 , V_151 -> clock ) ;
F_3 ( V_348 + V_231 ,
V_349 ) ;
F_3 ( V_350 + V_231 , 0x1000 ) ;
V_346 = F_4 ( V_351 + V_231 ) ;
V_346 &= ~ V_352 ;
V_346 &= ~ V_353 ;
switch ( V_132 ) {
case 0 :
case 6 :
case 8 :
case 16 :
default:
F_86 ( L_7 ,
V_74 -> V_354 , V_132 ) ;
break;
case 10 :
V_346 |= V_352 ;
V_346 |= 1 << V_355 ;
F_86 ( L_8 ,
V_74 -> V_354 ) ;
break;
case 12 :
V_346 |= V_352 ;
V_346 |= 2 << V_355 ;
F_86 ( L_9 ,
V_74 -> V_354 ) ;
break;
}
F_3 ( V_351 + V_231 , V_346 ) ;
F_3 ( V_348 + V_231 ,
V_349 |
V_356 |
V_357 ) ;
F_3 ( V_358 + V_231 ,
V_359 |
V_360 ) ;
F_3 ( V_361 + V_231 ,
V_362 ) ;
F_3 ( V_363 + V_231 ,
( 2 << V_364 ) ) ;
F_3 ( V_365 + V_231 , 0 ) ;
F_3 ( V_366 + V_231 ,
( 1 << V_367 ) |
( 3 << V_368 ) ) ;
F_3 ( V_369 + V_231 ,
V_370 ) ;
if ( V_132 > 8 )
F_3 ( V_371 + V_231 ,
V_372 ) ;
else
F_3 ( V_371 + V_231 ,
V_373 |
V_372 ) ;
F_82 ( V_129 , V_151 -> clock ) ;
F_3 ( V_374 + V_231 ,
( 1 << V_375 ) ) ;
F_3 ( V_376 + V_231 ,
( 2 << V_377 ) ) ;
F_3 ( V_378 + V_231 ,
( 3 << V_379 ) |
( 4 << V_380 ) |
( 5 << V_381 ) |
( 6 << V_382 ) |
( 7 << V_383 ) |
( 8 << V_384 ) ) ;
F_71 ( V_129 ) ;
F_3 ( V_385 + V_231 ,
( 0xff << V_386 ) ) ;
F_68 ( V_129 ) ;
F_75 ( V_129 ) ;
F_69 ( V_129 , V_151 ) ;
V_347 = F_87 ( & V_331 , V_151 ) ;
if ( V_347 < 0 ) {
F_67 ( L_10 , V_347 ) ;
return;
}
V_347 = F_88 ( & V_331 , V_329 , sizeof( V_329 ) ) ;
if ( V_347 < 0 ) {
F_67 ( L_11 , V_347 ) ;
return;
}
F_83 ( V_129 , V_329 , sizeof( V_329 ) ) ;
F_89 ( V_358 + V_231 ,
V_387 |
V_387 ) ;
F_90 ( V_363 + V_231 ,
( 2 << V_388 ) ,
~ V_389 ) ;
F_89 ( V_369 + V_231 ,
V_390 ) ;
F_3 ( V_391 + V_231 , 0x00FFFFFF ) ;
F_3 ( V_392 + V_231 , 0x007FFFFF ) ;
F_3 ( V_393 + V_231 , 0x00000001 ) ;
F_3 ( V_394 + V_231 , 0x00000001 ) ;
F_79 ( V_2 , V_240 -> V_242 -> V_234 , true ) ;
}
static void F_91 ( struct V_128 * V_129 , bool V_298 )
{
struct V_70 * V_71 = V_129 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
if ( ! V_240 || ! V_240 -> V_242 )
return;
if ( V_298 && V_240 -> V_242 -> V_155 )
return;
if ( ! V_298 && ! V_240 -> V_242 -> V_155 )
return;
if ( ! V_298 && V_240 -> V_242 -> V_234 ) {
F_79 ( V_2 , V_240 -> V_242 -> V_234 , false ) ;
V_240 -> V_242 -> V_234 = NULL ;
}
V_240 -> V_242 -> V_155 = V_298 ;
F_86 ( L_12 ,
V_298 ? L_13 : L_14 , V_240 -> V_242 -> V_231 , V_131 -> V_138 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_395 ; V_18 ++ )
V_2 -> V_19 . V_242 [ V_18 ] = NULL ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_395 ; V_18 ++ ) {
V_2 -> V_19 . V_242 [ V_18 ] = F_93 ( sizeof( struct V_396 ) , V_397 ) ;
if ( V_2 -> V_19 . V_242 [ V_18 ] ) {
V_2 -> V_19 . V_242 [ V_18 ] -> V_231 = V_398 [ V_18 ] ;
V_2 -> V_19 . V_242 [ V_18 ] -> V_244 = V_18 ;
}
}
}
static void F_94 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_395 ; V_18 ++ ) {
F_74 ( V_2 -> V_19 . V_242 [ V_18 ] ) ;
V_2 -> V_19 . V_242 [ V_18 ] = NULL ;
}
}
static void F_95 ( struct V_399 * V_11 , bool V_298 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
T_1 V_400 ;
V_400 = F_4 ( V_401 [ V_27 -> V_25 ] ) & ~ 1 ;
if ( V_298 )
F_3 ( V_401 [ V_27 -> V_25 ] , V_400 | 1 ) ;
else
F_3 ( V_401 [ V_27 -> V_25 ] , V_400 ) ;
}
static void F_96 ( struct V_399 * V_11 , bool V_298 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
if ( V_298 )
F_3 ( V_402 + V_27 -> V_30 , 1 ) ;
else
F_3 ( V_402 + V_27 -> V_30 , 0 ) ;
}
static int F_97 ( struct V_399 * V_11 ,
struct V_403 * V_404 ,
int V_405 , int V_406 , int V_407 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_408 * V_409 ;
struct V_403 * V_410 ;
struct V_411 * V_412 ;
struct V_413 * V_414 ;
T_10 V_415 , V_416 ;
T_6 V_417 , V_418 ;
T_1 V_419 = ( V_420 << V_421 ) ;
T_1 V_422 ;
T_1 V_57 , V_423 , V_424 ;
int V_6 ;
bool V_425 = false ;
if ( ! V_407 && ! V_11 -> V_426 -> V_404 ) {
F_41 ( L_15 ) ;
return 0 ;
}
if ( V_407 ) {
V_409 = F_98 ( V_404 ) ;
V_410 = V_404 ;
}
else {
V_409 = F_98 ( V_11 -> V_426 -> V_404 ) ;
V_410 = V_11 -> V_426 -> V_404 ;
}
V_412 = V_409 -> V_412 ;
V_414 = F_99 ( V_412 ) ;
V_6 = F_100 ( V_414 , false ) ;
if ( F_101 ( V_6 != 0 ) )
return V_6 ;
if ( V_407 )
V_415 = F_102 ( V_414 ) ;
else {
V_6 = F_103 ( V_414 , V_427 , & V_415 ) ;
if ( F_101 ( V_6 != 0 ) ) {
F_104 ( V_414 ) ;
return - V_34 ;
}
}
F_105 ( V_414 , & V_416 ) ;
F_104 ( V_414 ) ;
V_422 = F_106 ( V_416 , V_428 ) ;
switch ( V_410 -> V_429 ) {
case V_430 :
V_417 = ( ( V_431 << V_432 ) |
( V_433 << V_434 ) ) ;
break;
case V_435 :
case V_436 :
V_417 = ( ( V_437 << V_432 ) |
( V_438 << V_434 ) ) ;
#ifdef F_107
V_419 = ( V_439 << V_421 ) ;
#endif
break;
case V_440 :
case V_441 :
V_417 = ( ( V_437 << V_432 ) |
( V_438 << V_434 ) ) ;
#ifdef F_107
V_419 = ( V_439 << V_421 ) ;
#endif
break;
case V_442 :
case V_443 :
V_417 = ( ( V_437 << V_432 ) |
( V_444 << V_434 ) ) ;
#ifdef F_107
V_419 = ( V_439 << V_421 ) ;
#endif
break;
case V_445 :
V_417 = ( ( V_437 << V_432 ) |
( V_446 << V_434 ) ) ;
#ifdef F_107
V_419 = ( V_439 << V_421 ) ;
#endif
break;
case V_447 :
case V_448 :
V_417 = ( ( V_449 << V_432 ) |
( V_450 << V_434 ) ) ;
#ifdef F_107
V_419 = ( V_451 << V_421 ) ;
#endif
break;
case V_452 :
case V_453 :
V_417 = ( ( V_449 << V_432 ) |
( V_454 << V_434 ) ) ;
#ifdef F_107
V_419 = ( V_451 << V_421 ) ;
#endif
V_425 = true ;
break;
case V_455 :
case V_456 :
V_417 = ( ( V_449 << V_432 ) |
( V_457 << V_434 ) ) ;
#ifdef F_107
V_419 = ( V_451 << V_421 ) ;
#endif
V_425 = true ;
break;
default:
F_67 ( L_16 ,
F_108 ( V_410 -> V_429 ) ) ;
return - V_34 ;
}
if ( F_106 ( V_416 , V_458 ) == V_459 ) {
unsigned V_460 , V_461 , V_462 , V_463 , V_464 ;
V_460 = F_106 ( V_416 , V_465 ) ;
V_461 = F_106 ( V_416 , V_466 ) ;
V_462 = F_106 ( V_416 , V_467 ) ;
V_463 = F_106 ( V_416 , V_468 ) ;
V_464 = F_106 ( V_416 , V_469 ) ;
V_417 |= ( V_464 << V_470 ) ;
V_417 |= ( V_471 << V_472 ) ;
V_417 |= ( V_463 << V_473 ) ;
V_417 |= ( V_460 << V_474 ) ;
V_417 |= ( V_461 << V_475 ) ;
V_417 |= ( V_462 << V_476 ) ;
V_417 |= ( V_477 << V_478 ) ;
} else if ( F_106 ( V_416 , V_458 ) == V_479 ) {
V_417 |= ( V_480 << V_472 ) ;
}
V_417 |= ( V_422 << V_481 ) ;
F_95 ( V_11 , false ) ;
F_3 ( V_29 + V_27 -> V_30 ,
F_16 ( V_415 ) ) ;
F_3 ( V_109 + V_27 -> V_30 ,
F_16 ( V_415 ) ) ;
F_3 ( V_31 + V_27 -> V_30 ,
( T_1 ) V_415 & V_482 ) ;
F_3 ( V_110 + V_27 -> V_30 ,
( T_1 ) V_415 & V_483 ) ;
F_3 ( V_484 + V_27 -> V_30 , V_417 ) ;
F_3 ( V_485 + V_27 -> V_30 , V_419 ) ;
F_90 ( V_486 + V_27 -> V_30 ,
( V_425 ? V_487 : 0 ) ,
~ V_487 ) ;
if ( V_425 )
F_41 ( L_17 ) ;
F_3 ( V_488 + V_27 -> V_30 , 0 ) ;
F_3 ( V_489 + V_27 -> V_30 , 0 ) ;
F_3 ( V_490 + V_27 -> V_30 , 0 ) ;
F_3 ( V_491 + V_27 -> V_30 , 0 ) ;
F_3 ( V_492 + V_27 -> V_30 , V_410 -> V_493 ) ;
F_3 ( V_494 + V_27 -> V_30 , V_410 -> V_495 ) ;
V_418 = V_410 -> V_496 [ 0 ] / ( V_410 -> V_497 / 8 ) ;
F_3 ( V_498 + V_27 -> V_30 , V_418 ) ;
F_96 ( V_11 , true ) ;
F_3 ( V_499 + V_27 -> V_30 ,
V_410 -> V_495 ) ;
V_405 &= ~ 3 ;
V_406 &= ~ 1 ;
F_3 ( V_500 + V_27 -> V_30 ,
( V_405 << 16 ) | V_406 ) ;
V_423 = V_11 -> V_151 . V_501 ;
V_424 = ( V_11 -> V_151 . V_502 + 1 ) & ~ 1 ;
F_3 ( V_503 + V_27 -> V_30 ,
( V_423 << 16 ) | V_424 ) ;
V_57 = F_4 ( V_504 + V_27 -> V_30 ) ;
V_57 &= ~ V_505 ;
F_3 ( V_504 + V_27 -> V_30 , V_57 ) ;
F_3 ( V_111 + V_27 -> V_30 , 3 ) ;
if ( ! V_407 && V_404 && V_404 != V_11 -> V_426 -> V_404 ) {
V_409 = F_98 ( V_404 ) ;
V_414 = F_99 ( V_409 -> V_412 ) ;
V_6 = F_100 ( V_414 , false ) ;
if ( F_101 ( V_6 != 0 ) )
return V_6 ;
F_109 ( V_414 ) ;
F_104 ( V_414 ) ;
}
F_62 ( V_2 ) ;
return 0 ;
}
static void F_110 ( struct V_399 * V_11 ,
struct V_150 * V_151 )
{
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_27 * V_27 = F_37 ( V_11 ) ;
if ( V_151 -> V_5 & V_222 )
F_3 ( V_506 + V_27 -> V_30 ,
V_507 ) ;
else
F_3 ( V_506 + V_27 -> V_30 , 0 ) ;
}
static void F_111 ( struct V_399 * V_11 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
int V_18 ;
F_41 ( L_18 , V_27 -> V_25 ) ;
F_3 ( V_508 + V_27 -> V_30 ,
( ( V_509 << V_510 ) |
( V_509 << V_511 ) ) ) ;
F_3 ( V_512 + V_27 -> V_30 ,
V_513 ) ;
F_3 ( V_514 + V_27 -> V_30 ,
V_515 ) ;
F_3 ( V_516 + V_27 -> V_30 ,
( ( V_517 << V_518 ) |
( V_517 << V_519 ) ) ) ;
F_3 ( V_520 + V_27 -> V_30 , 0 ) ;
F_3 ( V_521 + V_27 -> V_30 , 0 ) ;
F_3 ( V_522 + V_27 -> V_30 , 0 ) ;
F_3 ( V_523 + V_27 -> V_30 , 0 ) ;
F_3 ( V_524 + V_27 -> V_30 , 0xffff ) ;
F_3 ( V_525 + V_27 -> V_30 , 0xffff ) ;
F_3 ( V_526 + V_27 -> V_30 , 0xffff ) ;
F_3 ( V_527 + V_27 -> V_30 , 0 ) ;
F_3 ( V_528 + V_27 -> V_30 , 0x00000007 ) ;
F_3 ( V_529 + V_27 -> V_30 , 0 ) ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
F_3 ( V_530 + V_27 -> V_30 ,
( V_27 -> V_531 [ V_18 ] << 20 ) |
( V_27 -> V_532 [ V_18 ] << 10 ) |
( V_27 -> V_533 [ V_18 ] << 0 ) ) ;
}
F_3 ( V_534 + V_27 -> V_30 ,
( ( V_535 << V_536 ) |
( V_535 << V_537 ) |
( V_535 << V_538 ) ) ) ;
F_3 ( V_539 + V_27 -> V_30 ,
( ( V_540 << V_541 ) |
( V_540 << V_542 ) ) ) ;
F_3 ( V_543 + V_27 -> V_30 ,
( ( V_544 << V_545 ) |
( V_544 << V_546 ) ) ) ;
F_3 ( V_547 + V_27 -> V_30 ,
( ( V_548 << V_549 ) |
( V_548 << V_550 ) ) ) ;
F_3 ( 0x1a50 + V_27 -> V_30 , 0 ) ;
F_3 ( V_551 + V_27 -> V_30 ,
V_552 ) ;
}
static int F_112 ( struct V_128 * V_129 )
{
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 = V_131 -> V_241 ;
switch ( V_131 -> V_138 ) {
case V_553 :
if ( V_240 -> V_554 )
return 1 ;
else
return 0 ;
break;
case V_555 :
if ( V_240 -> V_554 )
return 3 ;
else
return 2 ;
break;
case V_556 :
if ( V_240 -> V_554 )
return 5 ;
else
return 4 ;
break;
case V_557 :
return 6 ;
break;
default:
F_67 ( L_19 , V_131 -> V_138 ) ;
return 0 ;
}
}
static T_1 F_113 ( struct V_399 * V_11 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
T_1 V_558 ;
int V_559 ;
if ( F_114 ( F_115 ( V_27 -> V_129 ) ) ) {
if ( V_2 -> clock . V_560 )
return V_561 ;
else {
V_559 = F_116 ( V_11 ) ;
if ( V_559 != V_561 )
return V_559 ;
}
} else {
V_559 = F_117 ( V_11 ) ;
if ( V_559 != V_561 )
return V_559 ;
}
if ( ( V_2 -> V_302 == V_304 ) ||
( V_2 -> V_302 == V_305 ) ) {
V_558 = F_118 ( V_11 ) ;
if ( ! ( V_558 & ( 1 << V_562 ) ) )
return V_562 ;
if ( ! ( V_558 & ( 1 << V_563 ) ) )
return V_563 ;
F_67 ( L_20 ) ;
return V_561 ;
} else {
V_558 = F_118 ( V_11 ) ;
if ( ! ( V_558 & ( 1 << V_562 ) ) )
return V_562 ;
if ( ! ( V_558 & ( 1 << V_563 ) ) )
return V_563 ;
if ( ! ( V_558 & ( 1 << V_564 ) ) )
return V_564 ;
F_67 ( L_20 ) ;
return V_561 ;
}
return V_561 ;
}
static void F_119 ( struct V_399 * V_11 , bool V_565 )
{
struct V_1 * V_2 = V_11 -> V_71 -> V_130 ;
struct V_27 * V_27 = F_37 ( V_11 ) ;
T_6 V_566 ;
V_566 = F_4 ( V_567 + V_27 -> V_30 ) ;
if ( V_565 )
V_566 |= V_568 ;
else
V_566 &= ~ V_568 ;
F_3 ( V_567 + V_27 -> V_30 , V_566 ) ;
}
static void F_120 ( struct V_399 * V_11 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_71 -> V_130 ;
F_121 ( V_569 + V_27 -> V_30 ,
( V_570 << V_571 ) |
( V_572 << V_573 ) ) ;
}
static void F_122 ( struct V_399 * V_11 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_71 -> V_130 ;
F_3 ( V_574 + V_27 -> V_30 ,
F_16 ( V_27 -> V_575 ) ) ;
F_3 ( V_576 + V_27 -> V_30 ,
F_17 ( V_27 -> V_575 ) ) ;
F_121 ( V_569 + V_27 -> V_30 ,
V_577 |
( V_570 << V_571 ) |
( V_572 << V_573 ) ) ;
}
static int F_123 ( struct V_399 * V_11 ,
int V_405 , int V_406 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_71 -> V_130 ;
int V_578 = 0 , V_579 = 0 ;
V_405 += V_11 -> V_405 ;
V_406 += V_11 -> V_406 ;
F_86 ( L_21 , V_405 , V_406 , V_11 -> V_405 , V_11 -> V_406 ) ;
if ( V_405 < 0 ) {
V_578 = F_52 ( - V_405 , V_27 -> V_580 - 1 ) ;
V_405 = 0 ;
}
if ( V_406 < 0 ) {
V_579 = F_52 ( - V_406 , V_27 -> V_581 - 1 ) ;
V_406 = 0 ;
}
F_3 ( V_582 + V_27 -> V_30 , ( V_405 << 16 ) | V_406 ) ;
F_3 ( V_583 + V_27 -> V_30 , ( V_578 << 16 ) | V_579 ) ;
F_3 ( V_584 + V_27 -> V_30 ,
( ( V_27 -> V_585 - 1 ) << 16 ) | ( V_27 -> V_586 - 1 ) ) ;
V_27 -> V_587 = V_405 ;
V_27 -> V_588 = V_406 ;
return 0 ;
}
static int F_124 ( struct V_399 * V_11 ,
int V_405 , int V_406 )
{
int V_589 ;
F_119 ( V_11 , true ) ;
V_589 = F_123 ( V_11 , V_405 , V_406 ) ;
F_119 ( V_11 , false ) ;
return V_589 ;
}
static int F_125 ( struct V_399 * V_11 ,
struct V_590 * V_591 ,
T_6 V_592 ,
T_6 V_493 ,
T_6 V_495 ,
T_11 V_593 ,
T_11 V_594 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_411 * V_412 ;
struct V_413 * V_595 ;
int V_589 ;
if ( ! V_592 ) {
F_120 ( V_11 ) ;
V_412 = NULL ;
goto V_596;
}
if ( ( V_493 > V_27 -> V_580 ) ||
( V_495 > V_27 -> V_581 ) ) {
F_67 ( L_22 , V_493 , V_495 ) ;
return - V_34 ;
}
V_412 = F_126 ( V_11 -> V_71 , V_591 , V_592 ) ;
if ( ! V_412 ) {
F_67 ( L_23 , V_592 , V_27 -> V_25 ) ;
return - V_597 ;
}
V_595 = F_99 ( V_412 ) ;
V_589 = F_100 ( V_595 , false ) ;
if ( V_589 != 0 ) {
F_127 ( V_412 ) ;
return V_589 ;
}
V_589 = F_103 ( V_595 , V_427 , & V_27 -> V_575 ) ;
F_104 ( V_595 ) ;
if ( V_589 ) {
F_67 ( L_24 , V_589 ) ;
F_127 ( V_412 ) ;
return V_589 ;
}
V_27 -> V_585 = V_493 ;
V_27 -> V_586 = V_495 ;
F_119 ( V_11 , true ) ;
if ( V_593 != V_27 -> V_598 ||
V_594 != V_27 -> V_599 ) {
int V_405 , V_406 ;
V_405 = V_27 -> V_587 + V_27 -> V_598 - V_593 ;
V_406 = V_27 -> V_588 + V_27 -> V_599 - V_594 ;
F_123 ( V_11 , V_405 , V_406 ) ;
V_27 -> V_598 = V_593 ;
V_27 -> V_599 = V_594 ;
}
F_122 ( V_11 ) ;
F_119 ( V_11 , false ) ;
V_596:
if ( V_27 -> V_600 ) {
struct V_413 * V_595 = F_99 ( V_27 -> V_600 ) ;
V_589 = F_100 ( V_595 , false ) ;
if ( F_128 ( V_589 == 0 ) ) {
F_109 ( V_595 ) ;
F_104 ( V_595 ) ;
}
F_127 ( V_27 -> V_600 ) ;
}
V_27 -> V_600 = V_412 ;
return 0 ;
}
static void F_129 ( struct V_399 * V_11 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
if ( V_27 -> V_600 ) {
F_119 ( V_11 , true ) ;
F_123 ( V_11 , V_27 -> V_587 ,
V_27 -> V_588 ) ;
F_122 ( V_11 ) ;
F_119 ( V_11 , false ) ;
}
}
static void F_130 ( struct V_399 * V_11 , T_5 * V_601 , T_5 * V_602 ,
T_5 * V_603 , T_6 V_604 , T_6 V_330 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
int V_605 = ( V_604 + V_330 > 256 ) ? 256 : V_604 + V_330 , V_18 ;
for ( V_18 = V_604 ; V_18 < V_605 ; V_18 ++ ) {
V_27 -> V_531 [ V_18 ] = V_601 [ V_18 ] >> 6 ;
V_27 -> V_532 [ V_18 ] = V_602 [ V_18 ] >> 6 ;
V_27 -> V_533 [ V_18 ] = V_603 [ V_18 ] >> 6 ;
}
F_111 ( V_11 ) ;
}
static void F_131 ( struct V_399 * V_11 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
F_132 ( V_11 ) ;
F_133 ( V_27 -> V_606 ) ;
F_74 ( V_27 ) ;
}
static void F_134 ( struct V_399 * V_11 , int V_151 )
{
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_27 * V_27 = F_37 ( V_11 ) ;
unsigned type ;
switch ( V_151 ) {
case V_607 :
V_27 -> V_155 = true ;
F_135 ( V_11 , V_608 ) ;
F_95 ( V_11 , true ) ;
F_136 ( V_11 , V_609 ) ;
F_95 ( V_11 , false ) ;
type = F_137 ( V_2 , V_27 -> V_25 ) ;
F_138 ( V_2 , & V_2 -> V_610 , type ) ;
F_138 ( V_2 , & V_2 -> V_24 , type ) ;
F_139 ( V_71 , V_27 -> V_25 ) ;
F_111 ( V_11 ) ;
break;
case V_611 :
case V_612 :
case V_613 :
F_140 ( V_71 , V_27 -> V_25 ) ;
if ( V_27 -> V_155 ) {
F_95 ( V_11 , true ) ;
F_136 ( V_11 , V_608 ) ;
F_95 ( V_11 , false ) ;
}
F_135 ( V_11 , V_609 ) ;
V_27 -> V_155 = false ;
break;
}
F_141 ( V_2 ) ;
}
static void F_142 ( struct V_399 * V_11 )
{
F_143 ( V_11 , V_609 ) ;
F_144 ( V_11 , V_608 ) ;
F_134 ( V_11 , V_613 ) ;
}
static void F_145 ( struct V_399 * V_11 )
{
F_134 ( V_11 , V_607 ) ;
F_144 ( V_11 , V_609 ) ;
}
static void F_146 ( struct V_399 * V_11 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
struct V_614 V_615 ;
int V_18 ;
F_134 ( V_11 , V_613 ) ;
if ( V_11 -> V_426 -> V_404 ) {
int V_6 ;
struct V_408 * V_409 ;
struct V_413 * V_414 ;
V_409 = F_98 ( V_11 -> V_426 -> V_404 ) ;
V_414 = F_99 ( V_409 -> V_412 ) ;
V_6 = F_100 ( V_414 , false ) ;
if ( F_101 ( V_6 ) )
F_67 ( L_25 ) ;
else {
F_109 ( V_414 ) ;
F_104 ( V_414 ) ;
}
}
F_96 ( V_11 , false ) ;
F_143 ( V_11 , V_608 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_28 [ V_18 ] &&
V_2 -> V_19 . V_28 [ V_18 ] -> V_155 &&
V_18 != V_27 -> V_25 &&
V_27 -> V_616 == V_2 -> V_19 . V_28 [ V_18 ] -> V_616 ) {
goto V_617;
}
}
switch ( V_27 -> V_616 ) {
case V_563 :
case V_562 :
F_147 ( V_11 , V_27 -> V_25 , V_27 -> V_616 ,
0 , 0 , V_609 , 0 , 0 , 0 , 0 , 0 , false , & V_615 ) ;
break;
case V_564 :
if ( ( V_2 -> V_302 == V_303 ) ||
( V_2 -> V_302 == V_306 ) ||
( V_2 -> V_302 == V_307 ) )
F_147 ( V_11 , V_27 -> V_25 , V_27 -> V_616 ,
0 , 0 , V_609 , 0 , 0 , 0 , 0 , 0 , false , & V_615 ) ;
break;
default:
break;
}
V_617:
V_27 -> V_616 = V_561 ;
V_27 -> V_618 = 0 ;
V_27 -> V_129 = NULL ;
V_27 -> V_74 = NULL ;
}
static int F_148 ( struct V_399 * V_11 ,
struct V_150 * V_151 ,
struct V_150 * V_619 ,
int V_405 , int V_406 , struct V_403 * V_620 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
if ( ! V_27 -> V_618 )
return - V_34 ;
F_149 ( V_11 , V_619 ) ;
F_150 ( V_11 , V_619 ) ;
F_97 ( V_11 , V_620 , V_405 , V_406 , 0 ) ;
F_151 ( V_11 , V_151 , V_619 ) ;
F_152 ( V_11 ) ;
F_129 ( V_11 ) ;
V_27 -> V_621 = * V_619 ;
return 0 ;
}
static bool F_153 ( struct V_399 * V_11 ,
const struct V_150 * V_151 ,
struct V_150 * V_619 )
{
struct V_27 * V_27 = F_37 ( V_11 ) ;
struct V_70 * V_71 = V_11 -> V_71 ;
struct V_128 * V_129 ;
F_22 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_129 -> V_11 == V_11 ) {
V_27 -> V_129 = V_129 ;
V_27 -> V_74 = F_38 ( V_129 ) ;
break;
}
}
if ( ( V_27 -> V_129 == NULL ) || ( V_27 -> V_74 == NULL ) ) {
V_27 -> V_129 = NULL ;
V_27 -> V_74 = NULL ;
return false ;
}
if ( ! F_154 ( V_11 , V_151 , V_619 ) )
return false ;
if ( F_155 ( V_11 , V_619 ) )
return false ;
V_27 -> V_616 = F_113 ( V_11 ) ;
if ( ( V_27 -> V_616 == V_561 ) &&
! F_114 ( F_115 ( V_27 -> V_129 ) ) )
return false ;
return true ;
}
static int F_156 ( struct V_399 * V_11 , int V_405 , int V_406 ,
struct V_403 * V_620 )
{
return F_97 ( V_11 , V_620 , V_405 , V_406 , 0 ) ;
}
static int F_157 ( struct V_399 * V_11 ,
struct V_403 * V_404 ,
int V_405 , int V_406 , enum V_622 V_623 )
{
return F_97 ( V_11 , V_404 , V_405 , V_406 , 1 ) ;
}
static int F_158 ( struct V_1 * V_2 , int V_624 )
{
struct V_27 * V_27 ;
int V_18 ;
V_27 = F_93 ( sizeof( struct V_27 ) +
( V_625 * sizeof( struct V_73 * ) ) , V_397 ) ;
if ( V_27 == NULL )
return - V_626 ;
F_159 ( V_2 -> V_72 , & V_27 -> V_154 , & V_627 ) ;
F_160 ( & V_27 -> V_154 , 256 ) ;
V_27 -> V_25 = V_624 ;
V_27 -> V_606 = F_161 ( L_26 ) ;
V_2 -> V_19 . V_28 [ V_624 ] = V_27 ;
V_27 -> V_580 = V_628 ;
V_27 -> V_581 = V_629 ;
V_2 -> V_72 -> V_630 . V_585 = V_27 -> V_580 ;
V_2 -> V_72 -> V_630 . V_586 = V_27 -> V_581 ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
V_27 -> V_531 [ V_18 ] = V_18 << 2 ;
V_27 -> V_532 [ V_18 ] = V_18 << 2 ;
V_27 -> V_533 [ V_18 ] = V_18 << 2 ;
}
V_27 -> V_30 = V_13 [ V_27 -> V_25 ] ;
V_27 -> V_616 = V_561 ;
V_27 -> V_618 = 0 ;
V_27 -> V_129 = NULL ;
V_27 -> V_74 = NULL ;
F_162 ( & V_27 -> V_154 , & V_631 ) ;
return 0 ;
}
static int F_163 ( void * V_592 )
{
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
V_2 -> V_632 = & F_1 ;
V_2 -> V_633 = & F_6 ;
F_164 ( V_2 ) ;
F_165 ( V_2 ) ;
switch ( V_2 -> V_302 ) {
case V_306 :
case V_307 :
V_2 -> V_19 . V_20 = 6 ;
V_2 -> V_19 . V_634 = 6 ;
V_2 -> V_19 . V_395 = 6 ;
break;
case V_303 :
V_2 -> V_19 . V_20 = 4 ;
V_2 -> V_19 . V_634 = 6 ;
V_2 -> V_19 . V_395 = 7 ;
break;
case V_304 :
case V_305 :
V_2 -> V_19 . V_20 = 2 ;
V_2 -> V_19 . V_634 = 6 ;
V_2 -> V_19 . V_395 = 6 ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_166 ( void * V_592 )
{
int V_6 , V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_6 = F_167 ( V_2 , V_18 + 1 , & V_2 -> V_610 ) ;
if ( V_6 )
return V_6 ;
}
for ( V_18 = 8 ; V_18 < 20 ; V_18 += 2 ) {
V_6 = F_167 ( V_2 , V_18 , & V_2 -> V_24 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_167 ( V_2 , 42 , & V_2 -> V_88 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_19 . V_635 = true ;
V_2 -> V_72 -> V_630 . V_636 = & V_637 ;
V_2 -> V_72 -> V_630 . V_638 = 16384 ;
V_2 -> V_72 -> V_630 . V_639 = 16384 ;
V_2 -> V_72 -> V_630 . V_640 = 24 ;
V_2 -> V_72 -> V_630 . V_641 = 1 ;
V_2 -> V_72 -> V_630 . V_642 = V_2 -> V_107 . V_643 ;
V_6 = F_168 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_72 -> V_630 . V_638 = 16384 ;
V_2 -> V_72 -> V_630 . V_639 = 16384 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_6 = F_158 ( V_2 , V_18 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_169 ( V_2 ) )
F_170 ( V_2 -> V_72 ) ;
else
return - V_34 ;
F_92 ( V_2 ) ;
V_6 = F_80 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_171 ( V_2 -> V_72 ) ;
return V_6 ;
}
static int F_172 ( void * V_592 )
{
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
F_74 ( V_2 -> V_19 . V_644 ) ;
F_173 ( V_2 -> V_72 ) ;
F_81 ( V_2 ) ;
F_94 ( V_2 ) ;
F_174 ( V_2 -> V_72 ) ;
V_2 -> V_19 . V_635 = false ;
return 0 ;
}
static int F_175 ( void * V_592 )
{
int V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
F_176 ( V_2 ) ;
F_177 ( V_2 , V_2 -> clock . V_645 ) ;
F_21 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
F_79 ( V_2 , & V_2 -> V_19 . V_232 . V_234 [ V_18 ] , false ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int F_178 ( void * V_592 )
{
int V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
F_24 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
F_79 ( V_2 , & V_2 -> V_19 . V_232 . V_234 [ V_18 ] , false ) ;
}
F_13 ( V_2 ) ;
return 0 ;
}
static int F_179 ( void * V_592 )
{
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
F_180 ( V_2 ) ;
return F_178 ( V_592 ) ;
}
static int F_181 ( void * V_592 )
{
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
int V_589 ;
V_589 = F_175 ( V_592 ) ;
F_182 ( V_2 ) ;
if ( V_2 -> V_19 . V_646 ) {
T_4 V_647 = F_183 ( V_2 ,
V_2 -> V_19 . V_646 ) ;
F_184 ( V_2 , V_2 -> V_19 . V_646 ,
V_647 ) ;
}
return V_589 ;
}
static bool F_185 ( void * V_592 )
{
return true ;
}
static int F_186 ( void * V_592 )
{
return 0 ;
}
static void F_187 ( void * V_592 )
{
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
F_188 ( V_2 -> V_71 , L_27 ) ;
}
static int F_189 ( void * V_592 )
{
T_1 V_648 = 0 , V_57 ;
struct V_1 * V_2 = (struct V_1 * ) V_592 ;
if ( F_26 ( V_2 ) )
V_648 |= V_649 ;
if ( V_648 ) {
F_187 ( ( void * ) V_2 ) ;
V_57 = F_4 ( V_650 ) ;
V_57 |= V_648 ;
F_188 ( V_2 -> V_71 , L_28 , V_57 ) ;
F_3 ( V_650 , V_57 ) ;
V_57 = F_4 ( V_650 ) ;
F_27 ( 50 ) ;
V_57 &= ~ V_648 ;
F_3 ( V_650 , V_57 ) ;
V_57 = F_4 ( V_650 ) ;
F_27 ( 50 ) ;
F_187 ( ( void * ) V_2 ) ;
}
return 0 ;
}
static void F_190 ( struct V_1 * V_2 ,
int V_11 ,
enum V_651 V_623 )
{
T_1 V_652 , V_653 ;
if ( V_11 >= V_2 -> V_19 . V_20 ) {
F_86 ( L_29 , V_11 ) ;
return;
}
switch ( V_11 ) {
case 0 :
V_652 = V_654 ;
break;
case 1 :
V_652 = V_655 ;
break;
case 2 :
V_652 = V_656 ;
break;
case 3 :
V_652 = V_657 ;
break;
case 4 :
V_652 = V_658 ;
break;
case 5 :
V_652 = V_659 ;
break;
default:
F_86 ( L_29 , V_11 ) ;
return;
}
switch ( V_623 ) {
case V_660 :
V_653 = F_4 ( V_661 + V_652 ) ;
V_653 &= ~ V_662 ;
F_3 ( V_661 + V_652 , V_653 ) ;
break;
case V_663 :
V_653 = F_4 ( V_661 + V_652 ) ;
V_653 |= V_662 ;
F_3 ( V_661 + V_652 , V_653 ) ;
break;
default:
break;
}
}
static void F_191 ( struct V_1 * V_2 ,
int V_11 ,
enum V_651 V_623 )
{
T_1 V_652 , V_653 ;
if ( V_11 >= V_2 -> V_19 . V_20 ) {
F_86 ( L_29 , V_11 ) ;
return;
}
switch ( V_11 ) {
case 0 :
V_652 = V_654 ;
break;
case 1 :
V_652 = V_655 ;
break;
case 2 :
V_652 = V_656 ;
break;
case 3 :
V_652 = V_657 ;
break;
case 4 :
V_652 = V_658 ;
break;
case 5 :
V_652 = V_659 ;
break;
default:
F_86 ( L_29 , V_11 ) ;
return;
}
switch ( V_623 ) {
case V_660 :
V_653 = F_4 ( V_661 + V_652 ) ;
V_653 &= ~ V_664 ;
F_3 ( V_661 + V_652 , V_653 ) ;
break;
case V_663 :
V_653 = F_4 ( V_661 + V_652 ) ;
V_653 |= V_664 ;
F_3 ( V_661 + V_652 , V_653 ) ;
break;
default:
break;
}
}
static int F_192 ( struct V_1 * V_2 ,
struct V_665 * V_666 ,
unsigned type ,
enum V_651 V_623 )
{
T_1 V_667 , V_668 ;
switch ( type ) {
case V_39 :
V_667 = V_58 ;
break;
case V_42 :
V_667 = V_60 ;
break;
case V_45 :
V_667 = V_62 ;
break;
case V_48 :
V_667 = V_64 ;
break;
case V_51 :
V_667 = V_66 ;
break;
case V_54 :
V_667 = V_68 ;
break;
default:
F_86 ( L_30 , type ) ;
return 0 ;
}
switch ( V_623 ) {
case V_660 :
V_668 = F_4 ( V_667 ) ;
V_668 &= ~ V_669 ;
F_3 ( V_667 , V_668 ) ;
break;
case V_663 :
V_668 = F_4 ( V_667 ) ;
V_668 |= V_669 ;
F_3 ( V_667 , V_668 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_193 ( struct V_1 * V_2 ,
struct V_665 * V_666 ,
unsigned type ,
enum V_651 V_623 )
{
switch ( type ) {
case V_670 :
F_190 ( V_2 , 0 , V_623 ) ;
break;
case V_671 :
F_190 ( V_2 , 1 , V_623 ) ;
break;
case V_672 :
F_190 ( V_2 , 2 , V_623 ) ;
break;
case V_673 :
F_190 ( V_2 , 3 , V_623 ) ;
break;
case V_674 :
F_190 ( V_2 , 4 , V_623 ) ;
break;
case V_675 :
F_190 ( V_2 , 5 , V_623 ) ;
break;
case V_676 :
F_191 ( V_2 , 0 , V_623 ) ;
break;
case V_677 :
F_191 ( V_2 , 1 , V_623 ) ;
break;
case V_678 :
F_191 ( V_2 , 2 , V_623 ) ;
break;
case V_679 :
F_191 ( V_2 , 3 , V_623 ) ;
break;
case V_680 :
F_191 ( V_2 , 4 , V_623 ) ;
break;
case V_681 :
F_191 ( V_2 , 5 , V_623 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_665 * V_682 ,
struct V_683 * V_684 )
{
unsigned V_11 = V_684 -> V_685 - 1 ;
T_6 V_686 = F_4 ( V_687 [ V_11 ] . V_4 ) ;
unsigned V_688 = F_137 ( V_2 , V_11 ) ;
switch ( V_684 -> V_689 ) {
case 0 :
if ( V_686 & V_687 [ V_11 ] . V_690 )
F_3 ( V_691 + V_13 [ V_11 ] , V_692 ) ;
else
F_86 ( L_31 ) ;
if ( F_195 ( V_2 , V_682 , V_688 ) ) {
F_196 ( V_2 -> V_72 , V_11 ) ;
}
F_86 ( L_32 , V_11 + 1 ) ;
break;
case 1 :
if ( V_686 & V_687 [ V_11 ] . V_693 )
F_3 ( V_694 + V_13 [ V_11 ] , V_695 ) ;
else
F_86 ( L_31 ) ;
F_86 ( L_33 , V_11 + 1 ) ;
break;
default:
F_86 ( L_34 , V_684 -> V_685 , V_684 -> V_689 ) ;
break;
}
return 0 ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_665 * V_666 ,
unsigned type ,
enum V_651 V_623 )
{
T_1 V_4 ;
if ( type >= V_2 -> V_19 . V_20 ) {
F_67 ( L_35 , type ) ;
return - V_34 ;
}
V_4 = F_4 ( V_696 + V_13 [ type ] ) ;
if ( V_623 == V_660 )
F_3 ( V_696 + V_13 [ type ] ,
V_4 & ~ V_697 ) ;
else
F_3 ( V_696 + V_13 [ type ] ,
V_4 | V_697 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 ,
struct V_665 * V_682 ,
struct V_683 * V_684 )
{
unsigned long V_5 ;
unsigned V_25 ;
struct V_27 * V_27 ;
struct V_698 * V_699 ;
V_25 = ( V_684 -> V_685 - 8 ) >> 1 ;
V_27 = V_2 -> V_19 . V_28 [ V_25 ] ;
if ( V_25 >= V_2 -> V_19 . V_20 ) {
F_67 ( L_35 , V_25 ) ;
return - V_34 ;
}
if ( F_4 ( V_700 + V_13 [ V_25 ] ) &
V_701 )
F_3 ( V_700 + V_13 [ V_25 ] ,
V_702 ) ;
if ( V_27 == NULL )
return 0 ;
F_2 ( & V_2 -> V_72 -> V_703 , V_5 ) ;
V_699 = V_27 -> V_704 ;
if ( V_27 -> V_705 != V_706 ) {
F_199 ( L_36
L_37 ,
V_27 -> V_705 ,
V_706 ) ;
F_5 ( & V_2 -> V_72 -> V_703 , V_5 ) ;
return 0 ;
}
V_27 -> V_705 = V_707 ;
V_27 -> V_704 = NULL ;
if ( V_699 -> V_708 )
F_200 ( V_2 -> V_72 , V_25 , V_699 -> V_708 ) ;
F_5 ( & V_2 -> V_72 -> V_703 , V_5 ) ;
F_201 ( V_2 -> V_72 , V_27 -> V_25 ) ;
F_202 ( V_27 -> V_606 , & V_699 -> V_709 ) ;
return 0 ;
}
static int F_203 ( struct V_1 * V_2 ,
struct V_665 * V_682 ,
struct V_683 * V_684 )
{
T_6 V_686 , V_710 , V_711 , V_57 ;
unsigned V_37 ;
if ( V_684 -> V_689 >= V_2 -> V_19 . V_634 ) {
F_86 ( L_34 , V_684 -> V_685 , V_684 -> V_689 ) ;
return 0 ;
}
V_37 = V_684 -> V_689 ;
V_686 = F_4 ( V_687 [ V_37 ] . V_4 ) ;
V_710 = V_687 [ V_37 ] . V_37 ;
V_711 = V_712 [ V_37 ] ;
if ( V_686 & V_710 ) {
V_57 = F_4 ( V_711 ) ;
V_57 |= V_713 ;
F_3 ( V_711 , V_57 ) ;
F_204 ( & V_2 -> V_714 ) ;
F_86 ( L_38 , V_37 + 1 ) ;
}
return 0 ;
}
static int F_205 ( void * V_592 ,
enum V_715 V_623 )
{
return 0 ;
}
static int F_206 ( void * V_592 ,
enum V_716 V_623 )
{
return 0 ;
}
static void
F_207 ( struct V_128 * V_129 ,
struct V_150 * V_151 ,
struct V_150 * V_619 )
{
struct V_131 * V_131 = F_36 ( V_129 ) ;
V_131 -> V_717 = V_619 -> clock ;
F_208 ( V_129 , V_613 ) ;
F_110 ( V_129 -> V_11 , V_151 ) ;
if ( F_115 ( V_129 ) == V_718 ) {
F_91 ( V_129 , true ) ;
F_85 ( V_129 , V_619 ) ;
}
}
static void F_209 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_71 -> V_130 ;
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_73 * V_74 = F_38 ( V_129 ) ;
if ( ( V_131 -> V_719 &
( V_720 | V_137 ) ) ||
( F_210 ( V_129 ) !=
V_721 ) ) {
struct V_239 * V_240 = V_131 -> V_241 ;
if ( V_240 ) {
V_240 -> V_722 = F_112 ( V_129 ) ;
if ( V_131 -> V_719 & V_720 )
V_240 -> V_242 = V_2 -> V_19 . V_242 [ V_240 -> V_722 ] ;
}
}
F_211 ( V_2 , true ) ;
if ( V_74 ) {
struct V_78 * V_78 = F_23 ( V_74 ) ;
if ( V_78 -> V_723 . V_724 )
F_212 ( V_78 ) ;
if ( V_74 -> V_79 == V_80 )
F_213 ( V_74 ,
V_725 ) ;
}
F_214 ( V_129 ) ;
F_35 ( V_129 ) ;
}
static void F_215 ( struct V_128 * V_129 )
{
struct V_70 * V_71 = V_129 -> V_71 ;
struct V_1 * V_2 = V_71 -> V_130 ;
F_208 ( V_129 , V_607 ) ;
F_211 ( V_2 , false ) ;
}
static void F_216 ( struct V_128 * V_129 )
{
struct V_131 * V_131 = F_36 ( V_129 ) ;
struct V_239 * V_240 ;
F_208 ( V_129 , V_613 ) ;
if ( F_217 ( V_129 ) ) {
if ( F_115 ( V_129 ) == V_718 )
F_91 ( V_129 , false ) ;
V_240 = V_131 -> V_241 ;
V_240 -> V_722 = - 1 ;
}
V_131 -> V_719 = 0 ;
}
static void F_218 ( struct V_128 * V_129 )
{
}
static void F_219 ( struct V_128 * V_129 )
{
}
static void
F_220 ( struct V_128 * V_129 ,
struct V_150 * V_151 ,
struct V_150 * V_619 )
{
}
static void F_221 ( struct V_128 * V_129 )
{
}
static void
F_222 ( struct V_128 * V_129 , int V_151 )
{
}
static bool F_223 ( struct V_128 * V_129 ,
const struct V_150 * V_151 ,
struct V_150 * V_619 )
{
return true ;
}
static void F_224 ( struct V_128 * V_129 )
{
struct V_131 * V_131 = F_36 ( V_129 ) ;
if ( V_131 -> V_136 & ( V_137 ) )
F_225 ( V_131 ) ;
F_74 ( V_131 -> V_241 ) ;
F_226 ( V_129 ) ;
F_74 ( V_131 ) ;
}
static void F_227 ( struct V_1 * V_2 ,
T_6 V_726 ,
T_6 V_727 ,
T_5 V_728 )
{
struct V_70 * V_71 = V_2 -> V_72 ;
struct V_128 * V_129 ;
struct V_131 * V_131 ;
F_22 (encoder, &dev->mode_config.encoder_list, head) {
V_131 = F_36 ( V_129 ) ;
if ( V_131 -> V_726 == V_726 ) {
V_131 -> V_136 |= V_727 ;
return;
}
}
V_131 = F_93 ( sizeof( struct V_131 ) , V_397 ) ;
if ( ! V_131 )
return;
V_129 = & V_131 -> V_154 ;
switch ( V_2 -> V_19 . V_20 ) {
case 1 :
V_129 -> V_729 = 0x1 ;
break;
case 2 :
default:
V_129 -> V_729 = 0x3 ;
break;
case 4 :
V_129 -> V_729 = 0xf ;
break;
case 6 :
V_129 -> V_729 = 0x3f ;
break;
}
V_131 -> V_241 = NULL ;
V_131 -> V_726 = V_726 ;
V_131 -> V_138 = ( V_726 & V_730 ) >> V_731 ;
V_131 -> V_136 = V_727 ;
V_131 -> V_223 = V_224 ;
V_131 -> V_732 = V_733 ;
V_131 -> V_734 = false ;
V_131 -> V_728 = V_728 ;
switch ( V_131 -> V_138 ) {
case V_139 :
case V_140 :
F_228 ( V_71 , V_129 , & V_735 ,
V_736 , NULL ) ;
F_229 ( V_129 , & V_737 ) ;
break;
case V_738 :
case V_553 :
case V_555 :
case V_556 :
case V_557 :
if ( V_131 -> V_136 & ( V_137 ) ) {
V_131 -> V_223 = V_739 ;
F_228 ( V_71 , V_129 , & V_735 ,
V_740 , NULL ) ;
V_131 -> V_241 = F_230 ( V_131 ) ;
} else if ( V_131 -> V_136 & ( V_741 ) ) {
F_228 ( V_71 , V_129 , & V_735 ,
V_736 , NULL ) ;
V_131 -> V_241 = F_231 ( V_131 ) ;
} else {
F_228 ( V_71 , V_129 , & V_735 ,
V_742 , NULL ) ;
V_131 -> V_241 = F_231 ( V_131 ) ;
}
F_229 ( V_129 , & V_743 ) ;
break;
case V_744 :
case V_745 :
case V_746 :
case V_747 :
case V_748 :
case V_749 :
case V_750 :
case V_751 :
case V_752 :
V_131 -> V_734 = true ;
if ( V_131 -> V_136 & ( V_137 ) )
F_228 ( V_71 , V_129 , & V_735 ,
V_740 , NULL ) ;
else if ( V_131 -> V_136 & ( V_741 ) )
F_228 ( V_71 , V_129 , & V_735 ,
V_736 , NULL ) ;
else
F_228 ( V_71 , V_129 , & V_735 ,
V_742 , NULL ) ;
F_229 ( V_129 , & V_753 ) ;
break;
}
}
static void F_164 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 . V_636 == NULL )
V_2 -> V_19 . V_636 = & V_754 ;
}
static void F_165 ( struct V_1 * V_2 )
{
V_2 -> V_610 . V_755 = V_756 ;
V_2 -> V_610 . V_636 = & V_757 ;
V_2 -> V_24 . V_755 = V_758 ;
V_2 -> V_24 . V_636 = & V_759 ;
V_2 -> V_88 . V_755 = V_760 ;
V_2 -> V_88 . V_636 = & V_761 ;
}
