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
T_1 V_29 = F_4 ( V_30 + V_27 -> V_31 ) ;
int V_18 ;
V_29 |= V_32 ;
F_3 ( V_30 + V_27 -> V_31 , V_29 ) ;
F_3 ( V_33 + V_27 -> V_31 ,
F_16 ( V_26 ) ) ;
F_3 ( V_34 + V_27 -> V_31 ,
( T_1 ) V_26 ) ;
F_3 ( V_35 + V_27 -> V_31 ,
F_16 ( V_26 ) ) ;
F_3 ( V_36 + V_27 -> V_31 ,
( T_1 ) V_26 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_37 ; V_18 ++ ) {
if ( F_4 ( V_30 + V_27 -> V_31 ) &
V_38 )
break;
F_17 ( 1 ) ;
}
F_18 ( L_1 ) ;
V_29 &= ~ V_32 ;
F_3 ( V_30 + V_27 -> V_31 , V_29 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_11 ,
T_1 * V_39 , T_1 * V_40 )
{
if ( ( V_11 < 0 ) || ( V_11 >= V_2 -> V_19 . V_20 ) )
return - V_41 ;
* V_39 = F_4 ( V_42 + V_13 [ V_11 ] ) ;
* V_40 = F_4 ( V_17 + V_13 [ V_11 ] ) ;
return 0 ;
}
static bool F_20 ( struct V_1 * V_2 ,
enum V_43 V_44 )
{
bool V_45 = false ;
switch ( V_44 ) {
case V_46 :
if ( F_4 ( V_47 ) & V_48 )
V_45 = true ;
break;
case V_49 :
if ( F_4 ( V_50 ) & V_51 )
V_45 = true ;
break;
case V_52 :
if ( F_4 ( V_53 ) & V_54 )
V_45 = true ;
break;
case V_55 :
if ( F_4 ( V_56 ) & V_57 )
V_45 = true ;
break;
case V_58 :
if ( F_4 ( V_59 ) & V_60 )
V_45 = true ;
break;
case V_61 :
if ( F_4 ( V_62 ) & V_63 )
V_45 = true ;
break;
default:
break;
}
return V_45 ;
}
static void F_21 ( struct V_1 * V_2 ,
enum V_43 V_44 )
{
T_1 V_29 ;
bool V_45 = F_20 ( V_2 , V_44 ) ;
switch ( V_44 ) {
case V_46 :
V_29 = F_4 ( V_64 ) ;
if ( V_45 )
V_29 &= ~ V_65 ;
else
V_29 |= V_65 ;
F_3 ( V_64 , V_29 ) ;
break;
case V_49 :
V_29 = F_4 ( V_66 ) ;
if ( V_45 )
V_29 &= ~ V_67 ;
else
V_29 |= V_67 ;
F_3 ( V_66 , V_29 ) ;
break;
case V_52 :
V_29 = F_4 ( V_68 ) ;
if ( V_45 )
V_29 &= ~ V_69 ;
else
V_29 |= V_69 ;
F_3 ( V_68 , V_29 ) ;
break;
case V_55 :
V_29 = F_4 ( V_70 ) ;
if ( V_45 )
V_29 &= ~ V_71 ;
else
V_29 |= V_71 ;
F_3 ( V_70 , V_29 ) ;
break;
case V_58 :
V_29 = F_4 ( V_72 ) ;
if ( V_45 )
V_29 &= ~ V_73 ;
else
V_29 |= V_73 ;
F_3 ( V_72 , V_29 ) ;
break;
case V_61 :
V_29 = F_4 ( V_74 ) ;
if ( V_45 )
V_29 &= ~ V_75 ;
else
V_29 |= V_75 ;
F_3 ( V_74 , V_29 ) ;
break;
default:
break;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
struct V_79 * V_80 ;
T_1 V_29 = ( 0x9c4 << V_81 ) |
( 0xfa << V_82 ) |
V_83 ;
F_23 (connector, &dev->mode_config.connector_list, head) {
struct V_84 * V_84 = F_24 ( V_80 ) ;
if ( V_80 -> V_85 == V_86 ||
V_80 -> V_85 == V_87 ) {
continue;
}
switch ( V_84 -> V_44 . V_44 ) {
case V_46 :
F_3 ( V_88 , V_29 ) ;
break;
case V_49 :
F_3 ( V_89 , V_29 ) ;
break;
case V_52 :
F_3 ( V_90 , V_29 ) ;
break;
case V_55 :
F_3 ( V_91 , V_29 ) ;
break;
case V_58 :
F_3 ( V_92 , V_29 ) ;
break;
case V_61 :
F_3 ( V_93 , V_29 ) ;
break;
default:
break;
}
F_21 ( V_2 , V_84 -> V_44 . V_44 ) ;
F_12 ( V_2 , & V_2 -> V_94 , V_84 -> V_44 . V_44 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
struct V_79 * V_80 ;
F_23 (connector, &dev->mode_config.connector_list, head) {
struct V_84 * V_84 = F_24 ( V_80 ) ;
switch ( V_84 -> V_44 . V_44 ) {
case V_46 :
F_3 ( V_88 , 0 ) ;
break;
case V_49 :
F_3 ( V_89 , 0 ) ;
break;
case V_52 :
F_3 ( V_90 , 0 ) ;
break;
case V_55 :
F_3 ( V_91 , 0 ) ;
break;
case V_58 :
F_3 ( V_92 , 0 ) ;
break;
case V_61 :
F_3 ( V_93 , 0 ) ;
break;
default:
break;
}
F_14 ( V_2 , & V_2 -> V_94 , V_84 -> V_44 . V_44 ) ;
}
}
static T_1 F_26 ( struct V_1 * V_2 )
{
return V_95 ;
}
static bool F_27 ( struct V_1 * V_2 )
{
T_1 V_96 = 0 ;
T_1 V_97 [ 6 ] ;
T_1 V_18 , V_98 , V_29 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( F_4 ( V_21 + V_13 [ V_18 ] ) & V_22 ) {
V_97 [ V_18 ] = F_4 ( V_99 + V_13 [ V_18 ] ) ;
V_96 |= ( 1 << V_18 ) ;
}
}
for ( V_98 = 0 ; V_98 < 10 ; V_98 ++ ) {
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_96 & ( 1 << V_18 ) ) {
V_29 = F_4 ( V_99 + V_13 [ V_18 ] ) ;
if ( V_29 != V_97 [ V_18 ] )
V_96 &= ~ ( 1 << V_18 ) ;
}
}
if ( V_96 == 0 )
return false ;
F_17 ( 100 ) ;
}
return true ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
T_1 V_102 , V_29 ;
int V_18 ;
V_101 -> V_103 = F_4 ( V_104 ) ;
V_101 -> V_105 = F_4 ( V_106 ) ;
V_29 = F_4 ( V_104 ) ;
V_29 = F_29 ( V_29 , V_107 , V_108 , 0 ) ;
F_3 ( V_104 , V_29 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_102 = F_30 ( F_4 ( V_21 + V_13 [ V_18 ] ) ,
V_109 , V_110 ) ;
if ( V_102 ) {
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
F_3 ( V_111 + V_13 [ V_18 ] , 1 ) ;
V_29 = F_4 ( V_21 + V_13 [ V_18 ] ) ;
V_29 = F_29 ( V_29 , V_109 , V_110 , 0 ) ;
F_3 ( V_21 + V_13 [ V_18 ] , V_29 ) ;
F_3 ( V_111 + V_13 [ V_18 ] , 0 ) ;
V_101 -> V_102 [ V_18 ] = false ;
#endif
} else {
V_101 -> V_102 [ V_18 ] = false ;
}
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
T_1 V_29 , V_112 ;
int V_18 , V_98 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
F_3 ( V_35 + V_13 [ V_18 ] ,
F_16 ( V_2 -> V_113 . V_114 ) ) ;
F_3 ( V_33 + V_13 [ V_18 ] ,
F_16 ( V_2 -> V_113 . V_114 ) ) ;
F_3 ( V_36 + V_13 [ V_18 ] ,
( T_1 ) V_2 -> V_113 . V_114 ) ;
F_3 ( V_34 + V_13 [ V_18 ] ,
( T_1 ) V_2 -> V_113 . V_114 ) ;
if ( V_101 -> V_102 [ V_18 ] ) {
V_29 = F_4 ( V_115 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_29 , V_116 , V_116 ) != 3 ) {
V_29 = F_29 ( V_29 , V_116 , V_116 , 3 ) ;
F_3 ( V_115 + V_13 [ V_18 ] , V_29 ) ;
}
V_29 = F_4 ( V_30 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_29 , V_117 , V_118 ) ) {
V_29 = F_29 ( V_29 , V_117 , V_118 , 0 ) ;
F_3 ( V_30 + V_13 [ V_18 ] , V_29 ) ;
}
V_29 = F_4 ( V_119 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_29 , V_120 , V_120 ) ) {
V_29 = F_29 ( V_29 , V_120 , V_120 , 0 ) ;
F_3 ( V_119 + V_13 [ V_18 ] , V_29 ) ;
}
for ( V_98 = 0 ; V_98 < V_2 -> V_37 ; V_98 ++ ) {
V_29 = F_4 ( V_30 + V_13 [ V_18 ] ) ;
if ( F_30 ( V_29 , V_117 , V_121 ) == 0 )
break;
F_17 ( 1 ) ;
}
V_29 = F_4 ( V_122 + V_13 [ V_18 ] ) ;
V_29 = F_29 ( V_29 , V_123 , V_124 , 0 ) ;
F_3 ( V_111 + V_13 [ V_18 ] , 1 ) ;
F_3 ( V_122 + V_13 [ V_18 ] , V_29 ) ;
F_3 ( V_111 + V_13 [ V_18 ] , 0 ) ;
V_112 = F_32 ( V_2 , V_18 ) ;
for ( V_98 = 0 ; V_98 < V_2 -> V_37 ; V_98 ++ ) {
if ( F_32 ( V_2 , V_18 ) != V_112 )
break;
F_17 ( 1 ) ;
}
}
}
F_3 ( V_125 , F_16 ( V_2 -> V_113 . V_114 ) ) ;
F_3 ( V_126 , F_33 ( V_2 -> V_113 . V_114 ) ) ;
F_3 ( V_106 , V_101 -> V_105 ) ;
F_34 ( 1 ) ;
F_3 ( V_104 , V_101 -> V_103 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
bool V_127 )
{
T_1 V_29 ;
V_29 = F_4 ( V_106 ) ;
if ( V_127 )
V_29 = F_29 ( V_29 , V_128 , V_129 , 0 ) ;
else
V_29 = F_29 ( V_29 , V_128 , V_129 , 1 ) ;
F_3 ( V_106 , V_29 ) ;
V_29 = F_4 ( V_104 ) ;
if ( V_127 )
V_29 = F_29 ( V_29 , V_107 , V_108 , 1 ) ;
else
V_29 = F_29 ( V_29 , V_107 , V_108 , 0 ) ;
F_3 ( V_104 , V_29 ) ;
}
static void F_36 ( struct V_130 * V_131 )
{
struct V_76 * V_77 = V_131 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_27 * V_27 = F_38 ( V_131 -> V_11 ) ;
struct V_79 * V_80 = F_39 ( V_131 ) ;
int V_134 = 0 ;
T_1 V_29 = 0 ;
enum V_135 V_136 = V_137 ;
if ( V_80 ) {
struct V_84 * V_84 = F_24 ( V_80 ) ;
V_134 = F_40 ( V_80 ) ;
V_136 = V_84 -> V_136 ;
}
if ( V_133 -> V_138 & V_139 )
return;
if ( ( V_133 -> V_140 == V_141 ) ||
( V_133 -> V_140 == V_142 ) )
return;
if ( V_134 == 0 )
return;
switch ( V_134 ) {
case 6 :
if ( V_136 == V_143 )
V_29 |= ( V_144 |
V_145 |
V_146 |
( 0 << V_147 ) ) ;
else
V_29 |= ( V_148 |
( 0 << V_149 ) ) ;
break;
case 8 :
if ( V_136 == V_143 )
V_29 |= ( V_144 |
V_145 |
V_150 |
V_146 |
( 1 << V_147 ) ) ;
else
V_29 |= ( V_148 |
( 1 << V_149 ) ) ;
break;
case 10 :
if ( V_136 == V_143 )
V_29 |= ( V_144 |
V_145 |
V_150 |
V_146 |
( 2 << V_147 ) ) ;
else
V_29 |= ( V_148 |
( 2 << V_149 ) ) ;
break;
default:
break;
}
F_3 ( V_151 + V_27 -> V_31 , V_29 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_27 * V_27 ,
struct V_152 * V_153 )
{
T_1 V_29 , V_154 , V_18 ;
T_1 V_155 = V_27 -> V_25 * 0x8 ;
if ( V_27 -> V_156 . V_157 && V_153 ) {
if ( V_153 -> V_158 < 1920 ) {
V_29 = 1 ;
V_154 = 2 ;
} else if ( V_153 -> V_158 < 2560 ) {
V_29 = 2 ;
V_154 = 2 ;
} else if ( V_153 -> V_158 < 4096 ) {
V_29 = 0 ;
V_154 = ( V_2 -> V_5 & V_159 ) ? 2 : 4 ;
} else {
F_42 ( L_2 ) ;
V_29 = 0 ;
V_154 = ( V_2 -> V_5 & V_159 ) ? 2 : 4 ;
}
} else {
V_29 = 1 ;
V_154 = 0 ;
}
F_3 ( V_160 + V_27 -> V_31 ,
( V_29 << V_161 ) |
( 0x6B0 << V_162 ) ) ;
F_3 ( V_163 + V_155 ,
( V_154 << V_164 ) ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_37 ; V_18 ++ ) {
if ( F_4 ( V_163 + V_155 ) &
V_165 )
break;
F_17 ( 1 ) ;
}
if ( V_27 -> V_156 . V_157 && V_153 ) {
switch ( V_29 ) {
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
static T_1 F_43 ( struct V_1 * V_2 )
{
T_1 V_29 = F_4 ( V_166 ) ;
switch ( ( V_29 & V_167 ) >> V_168 ) {
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
static T_1 F_44 ( struct V_169 * V_170 )
{
T_3 V_171 ;
T_3 V_172 , V_173 , V_174 ;
T_3 V_175 ;
V_175 . V_176 = F_45 ( 1000 ) ;
V_172 . V_176 = F_45 ( V_170 -> V_172 ) ;
V_172 . V_176 = F_46 ( V_172 , V_175 ) ;
V_173 . V_176 = F_45 ( V_170 -> V_173 * 4 ) ;
V_175 . V_176 = F_45 ( 10 ) ;
V_171 . V_176 = F_45 ( 7 ) ;
V_171 . V_176 = F_46 ( V_171 , V_175 ) ;
V_174 . V_176 = F_47 ( V_173 , V_172 ) ;
V_174 . V_176 = F_47 ( V_174 , V_171 ) ;
return F_48 ( V_174 ) ;
}
static T_1 F_49 ( struct V_169 * V_170 )
{
T_3 V_177 ;
T_3 V_172 , V_173 , V_174 ;
T_3 V_175 ;
V_175 . V_176 = F_45 ( 1000 ) ;
V_172 . V_176 = F_45 ( V_170 -> V_172 ) ;
V_172 . V_176 = F_46 ( V_172 , V_175 ) ;
V_173 . V_176 = F_45 ( V_170 -> V_173 * 4 ) ;
V_175 . V_176 = F_45 ( 10 ) ;
V_177 . V_176 = F_45 ( 3 ) ;
V_177 . V_176 = F_46 ( V_177 , V_175 ) ;
V_174 . V_176 = F_47 ( V_173 , V_172 ) ;
V_174 . V_176 = F_47 ( V_174 , V_177 ) ;
return F_48 ( V_174 ) ;
}
static T_1 F_50 ( struct V_169 * V_170 )
{
T_3 V_178 ;
T_3 V_179 , V_174 ;
T_3 V_175 ;
V_175 . V_176 = F_45 ( 1000 ) ;
V_179 . V_176 = F_45 ( V_170 -> V_179 ) ;
V_179 . V_176 = F_46 ( V_179 , V_175 ) ;
V_175 . V_176 = F_45 ( 10 ) ;
V_178 . V_176 = F_45 ( 8 ) ;
V_178 . V_176 = F_46 ( V_178 , V_175 ) ;
V_175 . V_176 = F_45 ( 32 ) ;
V_174 . V_176 = F_47 ( V_175 , V_179 ) ;
V_174 . V_176 = F_47 ( V_174 , V_178 ) ;
return F_48 ( V_174 ) ;
}
static T_1 F_51 ( struct V_169 * V_170 )
{
T_3 V_180 ;
T_3 V_181 , V_174 ;
T_3 V_175 , V_182 ;
V_175 . V_176 = F_45 ( 1000 ) ;
V_181 . V_176 = F_45 ( V_170 -> V_181 ) ;
V_181 . V_176 = F_46 ( V_181 , V_175 ) ;
V_175 . V_176 = F_45 ( 32 ) ;
V_182 . V_176 = F_47 ( V_175 , V_181 ) ;
V_175 . V_176 = F_45 ( 10 ) ;
V_180 . V_176 = F_45 ( 8 ) ;
V_180 . V_176 = F_46 ( V_180 , V_175 ) ;
V_174 . V_176 = F_47 ( V_182 , V_180 ) ;
return F_48 ( V_174 ) ;
}
static T_1 F_52 ( struct V_169 * V_170 )
{
T_1 V_183 = F_44 ( V_170 ) ;
T_1 V_184 = F_50 ( V_170 ) ;
T_1 V_185 = F_51 ( V_170 ) ;
return F_53 ( V_183 , F_53 ( V_184 , V_185 ) ) ;
}
static T_1 F_54 ( struct V_169 * V_170 )
{
T_3 V_186 ;
T_3 V_187 ;
T_3 V_188 ;
T_3 V_174 ;
T_3 V_175 ;
V_175 . V_176 = F_45 ( 1000 ) ;
V_187 . V_176 = F_45 ( V_170 -> V_189 + V_170 -> V_190 ) ;
V_187 . V_176 = F_46 ( V_187 , V_175 ) ;
V_186 . V_176 = F_45 ( V_170 -> V_191 ) ;
V_188 . V_176 = F_45 ( V_170 -> V_188 ) ;
V_174 . V_176 = F_47 ( V_188 , V_186 ) ;
V_174 . V_176 = F_47 ( V_174 , V_170 -> V_192 ) ;
V_174 . V_176 = F_46 ( V_174 , V_187 ) ;
return F_48 ( V_174 ) ;
}
static T_1 F_55 ( struct V_169 * V_170 )
{
T_1 V_193 = 2000 ;
T_1 V_194 = F_52 ( V_170 ) ;
T_1 V_195 = ( 512 * 8 * 1000 ) / V_194 ;
T_1 V_196 = ( 128 * 4 * 1000 ) / V_194 ;
T_1 V_197 = 40000000 / V_170 -> V_181 ;
T_1 V_198 = ( ( V_170 -> V_199 + 1 ) * V_195 ) +
( V_170 -> V_199 * V_196 ) ;
T_1 V_200 = V_193 + V_198 + V_197 ;
T_1 V_201 , V_202 , V_203 ;
T_1 V_29 , V_204 = 12288 ;
T_3 V_175 , V_182 , V_205 ;
if ( V_170 -> V_199 == 0 )
return 0 ;
V_175 . V_176 = F_45 ( 2 ) ;
V_182 . V_176 = F_45 ( 1 ) ;
if ( ( V_170 -> V_192 . V_176 > V_175 . V_176 ) ||
( ( V_170 -> V_192 . V_176 > V_182 . V_176 ) && ( V_170 -> V_206 >= 3 ) ) ||
( V_170 -> V_206 >= 5 ) ||
( ( V_170 -> V_192 . V_176 >= V_175 . V_176 ) && V_170 -> V_207 ) )
V_201 = 4 ;
else
V_201 = 2 ;
V_175 . V_176 = F_45 ( V_194 ) ;
V_182 . V_176 = F_45 ( V_170 -> V_199 ) ;
V_175 . V_176 = F_46 ( V_175 , V_182 ) ;
V_182 . V_176 = F_45 ( V_193 + 512 ) ;
V_205 . V_176 = F_45 ( V_170 -> V_181 ) ;
V_182 . V_176 = F_46 ( V_182 , V_205 ) ;
V_205 . V_176 = F_45 ( V_204 ) ;
V_182 . V_176 = F_46 ( V_205 , V_182 ) ;
V_29 = F_53 ( F_48 ( V_175 ) , F_48 ( V_182 ) ) ;
V_182 . V_176 = F_45 ( 1000 ) ;
V_205 . V_176 = F_45 ( V_170 -> V_181 ) ;
V_182 . V_176 = F_46 ( V_205 , V_182 ) ;
V_205 . V_176 = F_45 ( V_170 -> V_191 ) ;
V_182 . V_176 = F_47 ( V_182 , V_205 ) ;
V_202 = F_53 ( V_29 , F_48 ( V_182 ) ) ;
V_175 . V_176 = F_45 ( V_201 * V_170 -> V_188 * V_170 -> V_191 ) ;
V_182 . V_176 = F_45 ( 1000 ) ;
V_205 . V_176 = F_45 ( V_202 ) ;
V_182 . V_176 = F_46 ( V_205 , V_182 ) ;
V_175 . V_176 = F_46 ( V_175 , V_182 ) ;
V_203 = F_48 ( V_175 ) ;
if ( V_203 < V_170 -> V_189 )
return V_200 ;
else
return V_200 + ( V_203 - V_170 -> V_189 ) ;
}
static bool F_56 ( struct V_169 * V_170 )
{
if ( F_54 ( V_170 ) <=
( F_49 ( V_170 ) / V_170 -> V_199 ) )
return true ;
else
return false ;
}
static bool F_57 ( struct V_169 * V_170 )
{
if ( F_54 ( V_170 ) <=
( F_52 ( V_170 ) / V_170 -> V_199 ) )
return true ;
else
return false ;
}
static bool F_58 ( struct V_169 * V_170 )
{
T_1 V_208 = V_170 -> V_209 / V_170 -> V_188 ;
T_1 V_187 = V_170 -> V_189 + V_170 -> V_190 ;
T_1 V_210 ;
T_1 V_211 ;
T_3 V_175 ;
V_175 . V_176 = F_45 ( 1 ) ;
if ( V_170 -> V_192 . V_176 > V_175 . V_176 )
V_210 = 1 ;
else {
if ( V_208 <= ( V_170 -> V_206 + 1 ) )
V_210 = 1 ;
else
V_210 = 2 ;
}
V_211 = ( V_210 * V_187 + V_170 -> V_190 ) ;
if ( F_55 ( V_170 ) <= V_211 )
return true ;
else
return false ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_27 * V_27 ,
T_1 V_209 , T_1 V_199 )
{
struct V_152 * V_153 = & V_27 -> V_156 . V_153 ;
struct V_169 V_212 , V_213 ;
T_1 V_214 ;
T_1 V_187 = 0 ;
T_1 V_215 = 0 , V_216 = 0 ;
T_1 V_29 , V_217 ;
if ( V_27 -> V_156 . V_157 && V_199 && V_153 ) {
V_214 = 1000000 / ( T_1 ) V_153 -> clock ;
V_187 = F_53 ( ( T_1 ) V_153 -> V_218 * V_214 , ( T_1 ) 65535 ) ;
if ( V_2 -> V_219 . V_220 ) {
V_213 . V_172 =
F_60 ( V_2 , false ) * 10 ;
V_213 . V_179 =
F_61 ( V_2 , false ) * 10 ;
} else {
V_213 . V_172 = V_2 -> V_219 . V_221 * 10 ;
V_213 . V_179 = V_2 -> V_219 . V_222 * 10 ;
}
V_213 . V_181 = V_153 -> clock ;
V_213 . V_188 = V_153 -> V_158 ;
V_213 . V_189 = V_153 -> V_158 * V_214 ;
V_213 . V_190 = V_187 - V_213 . V_189 ;
V_213 . V_207 = false ;
if ( V_153 -> V_5 & V_223 )
V_213 . V_207 = true ;
V_213 . V_192 = V_27 -> V_192 ;
V_213 . V_206 = 1 ;
if ( V_27 -> V_224 != V_225 )
V_213 . V_206 = 2 ;
V_213 . V_191 = 4 ;
V_213 . V_209 = V_209 ;
V_213 . V_173 = F_43 ( V_2 ) ;
V_213 . V_199 = V_199 ;
V_215 = F_53 ( F_55 ( & V_213 ) , ( T_1 ) 65535 ) ;
if ( ! F_56 ( & V_213 ) ||
! F_57 ( & V_213 ) ||
! F_58 ( & V_213 ) ||
( V_2 -> V_19 . V_226 == 2 ) ) {
F_42 ( L_3 ) ;
}
if ( V_2 -> V_219 . V_220 ) {
V_212 . V_172 =
F_60 ( V_2 , true ) * 10 ;
V_212 . V_179 =
F_61 ( V_2 , true ) * 10 ;
} else {
V_212 . V_172 = V_2 -> V_219 . V_221 * 10 ;
V_212 . V_179 = V_2 -> V_219 . V_222 * 10 ;
}
V_212 . V_181 = V_153 -> clock ;
V_212 . V_188 = V_153 -> V_158 ;
V_212 . V_189 = V_153 -> V_158 * V_214 ;
V_212 . V_190 = V_187 - V_212 . V_189 ;
V_212 . V_207 = false ;
if ( V_153 -> V_5 & V_223 )
V_212 . V_207 = true ;
V_212 . V_192 = V_27 -> V_192 ;
V_212 . V_206 = 1 ;
if ( V_27 -> V_224 != V_225 )
V_212 . V_206 = 2 ;
V_212 . V_191 = 4 ;
V_212 . V_209 = V_209 ;
V_212 . V_173 = F_43 ( V_2 ) ;
V_212 . V_199 = V_199 ;
V_216 = F_53 ( F_55 ( & V_212 ) , ( T_1 ) 65535 ) ;
if ( ! F_56 ( & V_212 ) ||
! F_57 ( & V_212 ) ||
! F_58 ( & V_212 ) ||
( V_2 -> V_19 . V_226 == 2 ) ) {
F_42 ( L_3 ) ;
}
}
V_217 = F_4 ( V_227 + V_27 -> V_31 ) ;
V_29 = V_217 ;
V_29 &= ~ ( 3 << V_228 ) ;
V_29 |= ( 1 << V_228 ) ;
F_3 ( V_227 + V_27 -> V_31 , V_29 ) ;
F_3 ( V_229 + V_27 -> V_31 ,
( ( V_215 << V_230 ) |
( V_187 << V_231 ) ) ) ;
V_29 = F_4 ( V_227 + V_27 -> V_31 ) ;
V_29 &= ~ ( 3 << V_228 ) ;
V_29 |= ( 2 << V_228 ) ;
F_3 ( V_227 + V_27 -> V_31 , V_29 ) ;
F_3 ( V_229 + V_27 -> V_31 ,
( ( V_216 << V_230 ) |
( V_187 << V_231 ) ) ) ;
F_3 ( V_227 + V_27 -> V_31 , V_217 ) ;
V_27 -> V_187 = V_187 ;
V_27 -> V_213 = V_215 ;
V_27 -> V_212 = V_216 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_152 * V_153 = NULL ;
T_1 V_199 = 0 , V_209 ;
int V_18 ;
F_63 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_28 [ V_18 ] -> V_156 . V_157 )
V_199 ++ ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_153 = & V_2 -> V_19 . V_28 [ V_18 ] -> V_156 . V_153 ;
V_209 = F_41 ( V_2 , V_2 -> V_19 . V_28 [ V_18 ] , V_153 ) ;
F_59 ( V_2 , V_2 -> V_19 . V_28 [ V_18 ] ,
V_209 , V_199 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
int V_18 ;
T_1 V_232 , V_29 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_233 . V_234 ; V_18 ++ ) {
V_232 = V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_232 ;
V_29 = F_65 ( V_232 ,
V_236 ) ;
if ( ( ( V_29 &
V_237 ) >>
V_238 ) == 1 )
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_45 = false ;
else
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_45 = true ;
}
}
static struct V_239 * F_66 ( struct V_1 * V_2 )
{
int V_18 ;
F_64 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_233 . V_234 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_45 )
return & V_2 -> V_19 . V_233 . V_235 [ V_18 ] ;
}
F_67 ( L_4 ) ;
return NULL ;
}
static void F_68 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = V_131 -> V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
T_1 V_232 ;
if ( ! V_241 || ! V_241 -> V_243 || ! V_241 -> V_243 -> V_235 )
return;
V_232 = V_241 -> V_243 -> V_232 ;
F_3 ( V_244 + V_232 ,
( V_241 -> V_243 -> V_235 -> V_245 << V_246 ) ) ;
}
static void F_69 ( struct V_130 * V_131 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = V_131 -> V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
struct V_79 * V_80 ;
struct V_84 * V_84 = NULL ;
T_1 V_29 = 0 , V_232 ;
if ( ! V_241 || ! V_241 -> V_243 || ! V_241 -> V_243 -> V_235 )
return;
V_232 = V_241 -> V_243 -> V_235 -> V_232 ;
F_23 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_80 -> V_131 == V_131 ) {
V_84 = F_24 ( V_80 ) ;
break;
}
}
if ( ! V_84 ) {
F_67 ( L_5 ) ;
return;
}
if ( V_153 -> V_5 & V_223 ) {
if ( V_80 -> V_247 [ 1 ] )
V_29 =
( V_80 -> V_248 [ 1 ] <<
V_249 ) |
( V_80 -> V_250 [ 1 ] <<
V_251 ) ;
else
V_29 =
( 0 <<
V_249 ) |
( 0 <<
V_251 ) ;
} else {
if ( V_80 -> V_247 [ 0 ] )
V_29 =
( V_80 -> V_248 [ 0 ] <<
V_249 ) |
( V_80 -> V_250 [ 0 ] <<
V_251 ) ;
else
V_29 =
( 0 <<
V_249 ) |
( 0 <<
V_251 ) ;
}
F_70 ( V_232 , V_252 , V_29 ) ;
}
static void F_71 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = V_131 -> V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
struct V_79 * V_80 ;
struct V_84 * V_84 = NULL ;
T_1 V_232 , V_29 ;
T_4 * V_253 = NULL ;
int V_254 ;
if ( ! V_241 || ! V_241 -> V_243 || ! V_241 -> V_243 -> V_235 )
return;
V_232 = V_241 -> V_243 -> V_235 -> V_232 ;
F_23 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_80 -> V_131 == V_131 ) {
V_84 = F_24 ( V_80 ) ;
break;
}
}
if ( ! V_84 ) {
F_67 ( L_5 ) ;
return;
}
V_254 = F_72 ( F_73 ( V_80 ) , & V_253 ) ;
if ( V_254 < 0 ) {
F_67 ( L_6 , V_254 ) ;
V_254 = 0 ;
}
V_29 = F_65 ( V_232 , V_255 ) ;
V_29 &= ~ ( V_256 |
V_257 ) ;
V_29 |= V_258 ;
if ( V_254 )
V_29 |= ( V_253 [ 0 ] << V_259 ) ;
else
V_29 |= ( 5 << V_259 ) ;
F_70 ( V_232 , V_255 , V_29 ) ;
F_74 ( V_253 ) ;
}
static void F_75 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = V_131 -> V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
T_1 V_232 ;
struct V_79 * V_80 ;
struct V_84 * V_84 = NULL ;
struct V_260 * V_261 ;
int V_18 , V_254 ;
static const T_5 V_262 [] [ 2 ] = {
{ V_263 , V_264 } ,
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
} ;
if ( ! V_241 || ! V_241 -> V_243 || ! V_241 -> V_243 -> V_235 )
return;
V_232 = V_241 -> V_243 -> V_235 -> V_232 ;
F_23 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_80 -> V_131 == V_131 ) {
V_84 = F_24 ( V_80 ) ;
break;
}
}
if ( ! V_84 ) {
F_67 ( L_5 ) ;
return;
}
V_254 = F_76 ( F_73 ( V_80 ) , & V_261 ) ;
if ( V_254 <= 0 ) {
F_67 ( L_7 , V_254 ) ;
return;
}
F_77 ( ! V_261 ) ;
for ( V_18 = 0 ; V_18 < F_78 ( V_262 ) ; V_18 ++ ) {
T_1 V_287 = 0 ;
T_4 V_288 = 0 ;
int V_289 = - 1 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_254 ; V_98 ++ ) {
struct V_260 * V_290 = & V_261 [ V_98 ] ;
if ( V_290 -> V_291 == V_262 [ V_18 ] [ 1 ] ) {
if ( V_290 -> V_292 > V_289 ) {
V_287 = ( V_290 -> V_292 <<
V_293 ) |
( V_290 -> V_294 <<
V_295 ) |
( V_290 -> V_296 <<
V_297 ) ;
V_289 = V_290 -> V_292 ;
}
if ( V_290 -> V_291 == V_264 )
V_288 |= V_290 -> V_296 ;
else
break;
}
}
V_287 |= ( V_288 <<
V_298 ) ;
F_70 ( V_232 , V_262 [ V_18 ] [ 0 ] , V_287 ) ;
}
F_74 ( V_261 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_239 * V_235 ,
bool V_299 )
{
if ( ! V_235 )
return;
F_70 ( V_235 -> V_232 , V_300 ,
V_299 ? V_301 : 0 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_18 ;
if ( ! V_302 )
return 0 ;
V_2 -> V_19 . V_233 . V_157 = true ;
if ( V_2 -> V_303 == V_304 )
V_2 -> V_19 . V_233 . V_234 = 7 ;
else if ( ( V_2 -> V_303 == V_305 ) ||
( V_2 -> V_303 == V_306 ) )
V_2 -> V_19 . V_233 . V_234 = 3 ;
else if ( ( V_2 -> V_303 == V_307 ) ||
( V_2 -> V_303 == V_308 ) )
V_2 -> V_19 . V_233 . V_234 = 7 ;
else
V_2 -> V_19 . V_233 . V_234 = 3 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_233 . V_234 ; V_18 ++ ) {
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_292 = - 1 ;
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_309 = - 1 ;
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_310 = - 1 ;
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_311 = 0 ;
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_312 = 0 ;
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_45 = false ;
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_232 = V_313 [ V_18 ] ;
V_2 -> V_19 . V_233 . V_235 [ V_18 ] . V_245 = V_18 ;
F_79 ( V_2 , & V_2 -> V_19 . V_233 . V_235 [ V_18 ] , false ) ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
int V_18 ;
if ( ! V_2 -> V_19 . V_233 . V_157 )
return;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_233 . V_234 ; V_18 ++ )
F_79 ( V_2 , & V_2 -> V_19 . V_233 . V_235 [ V_18 ] , false ) ;
V_2 -> V_19 . V_233 . V_157 = false ;
}
static void F_82 ( struct V_130 * V_131 , T_6 clock )
{
struct V_76 * V_77 = V_131 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_314 V_315 = V_314 ( clock ) ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
T_6 V_232 = V_241 -> V_243 -> V_232 ;
F_3 ( V_316 + V_232 , ( V_315 . V_317 << V_318 ) ) ;
F_3 ( V_319 + V_232 , V_315 . V_320 ) ;
F_3 ( V_321 + V_232 , ( V_315 . V_322 << V_318 ) ) ;
F_3 ( V_323 + V_232 , V_315 . V_324 ) ;
F_3 ( V_325 + V_232 , ( V_315 . V_326 << V_327 ) ) ;
F_3 ( V_328 + V_232 , V_315 . V_329 ) ;
}
static void F_83 ( struct V_130 * V_131 ,
void * V_330 , T_7 V_331 )
{
struct V_76 * V_77 = V_131 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
T_6 V_232 = V_241 -> V_243 -> V_232 ;
T_8 * V_332 = V_330 + 3 ;
T_8 * V_333 = V_330 ;
F_3 ( V_334 + V_232 ,
V_332 [ 0x0 ] | ( V_332 [ 0x1 ] << 8 ) | ( V_332 [ 0x2 ] << 16 ) | ( V_332 [ 0x3 ] << 24 ) ) ;
F_3 ( V_335 + V_232 ,
V_332 [ 0x4 ] | ( V_332 [ 0x5 ] << 8 ) | ( V_332 [ 0x6 ] << 16 ) | ( V_332 [ 0x7 ] << 24 ) ) ;
F_3 ( V_336 + V_232 ,
V_332 [ 0x8 ] | ( V_332 [ 0x9 ] << 8 ) | ( V_332 [ 0xA ] << 16 ) | ( V_332 [ 0xB ] << 24 ) ) ;
F_3 ( V_337 + V_232 ,
V_332 [ 0xC ] | ( V_332 [ 0xD ] << 8 ) | ( V_333 [ 1 ] << 24 ) ) ;
}
static void F_84 ( struct V_130 * V_131 , T_1 clock )
{
struct V_76 * V_77 = V_131 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
struct V_27 * V_27 = F_38 ( V_131 -> V_11 ) ;
T_1 V_338 = 24 * 1000 ;
T_1 V_339 = clock ;
if ( ! V_241 || ! V_241 -> V_243 )
return;
F_3 ( V_340 , ( V_27 -> V_25 << V_341 ) ) ;
F_3 ( V_342 , V_338 ) ;
F_3 ( V_343 , V_339 ) ;
}
static void F_85 ( struct V_130 * V_131 ,
struct V_152 * V_153 )
{
struct V_76 * V_77 = V_131 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
struct V_79 * V_80 = F_39 ( V_131 ) ;
T_4 V_330 [ V_344 + V_345 ] ;
struct V_346 V_332 ;
T_6 V_232 , V_347 ;
T_9 V_348 ;
int V_134 = 8 ;
if ( ! V_241 || ! V_241 -> V_243 )
return;
if ( ! V_241 -> V_243 -> V_157 )
return;
V_232 = V_241 -> V_243 -> V_232 ;
if ( V_131 -> V_11 ) {
struct V_27 * V_27 = F_38 ( V_131 -> V_11 ) ;
V_134 = V_27 -> V_134 ;
}
V_241 -> V_243 -> V_235 = F_66 ( V_2 ) ;
F_79 ( V_2 , V_241 -> V_243 -> V_235 , false ) ;
F_84 ( V_131 , V_153 -> clock ) ;
F_3 ( V_349 + V_232 ,
V_350 ) ;
F_3 ( V_351 + V_232 , 0x1000 ) ;
V_347 = F_4 ( V_352 + V_232 ) ;
V_347 &= ~ V_353 ;
V_347 &= ~ V_354 ;
switch ( V_134 ) {
case 0 :
case 6 :
case 8 :
case 16 :
default:
F_18 ( L_8 ,
V_80 -> V_355 , V_134 ) ;
break;
case 10 :
V_347 |= V_353 ;
V_347 |= 1 << V_356 ;
F_18 ( L_9 ,
V_80 -> V_355 ) ;
break;
case 12 :
V_347 |= V_353 ;
V_347 |= 2 << V_356 ;
F_18 ( L_10 ,
V_80 -> V_355 ) ;
break;
}
F_3 ( V_352 + V_232 , V_347 ) ;
F_3 ( V_349 + V_232 ,
V_350 |
V_357 |
V_358 ) ;
F_3 ( V_359 + V_232 ,
V_360 |
V_361 ) ;
F_3 ( V_362 + V_232 ,
V_363 ) ;
F_3 ( V_364 + V_232 ,
( 2 << V_365 ) ) ;
F_3 ( V_366 + V_232 , 0 ) ;
F_3 ( V_367 + V_232 ,
( 1 << V_368 ) |
( 3 << V_369 ) ) ;
F_3 ( V_370 + V_232 ,
V_371 ) ;
if ( V_134 > 8 )
F_3 ( V_372 + V_232 ,
V_373 ) ;
else
F_3 ( V_372 + V_232 ,
V_374 |
V_373 ) ;
F_82 ( V_131 , V_153 -> clock ) ;
F_3 ( V_375 + V_232 ,
( 1 << V_376 ) ) ;
F_3 ( V_377 + V_232 ,
( 2 << V_378 ) ) ;
F_3 ( V_379 + V_232 ,
( 3 << V_380 ) |
( 4 << V_381 ) |
( 5 << V_382 ) |
( 6 << V_383 ) |
( 7 << V_384 ) |
( 8 << V_385 ) ) ;
F_71 ( V_131 ) ;
F_3 ( V_386 + V_232 ,
( 0xff << V_387 ) ) ;
F_68 ( V_131 ) ;
F_75 ( V_131 ) ;
F_69 ( V_131 , V_153 ) ;
V_348 = F_86 ( & V_332 , V_153 ) ;
if ( V_348 < 0 ) {
F_67 ( L_11 , V_348 ) ;
return;
}
V_348 = F_87 ( & V_332 , V_330 , sizeof( V_330 ) ) ;
if ( V_348 < 0 ) {
F_67 ( L_12 , V_348 ) ;
return;
}
F_83 ( V_131 , V_330 , sizeof( V_330 ) ) ;
F_88 ( V_359 + V_232 ,
V_388 |
V_388 ) ;
F_89 ( V_364 + V_232 ,
( 2 << V_389 ) ,
~ V_390 ) ;
F_88 ( V_370 + V_232 ,
V_391 ) ;
F_3 ( V_392 + V_232 , 0x00FFFFFF ) ;
F_3 ( V_393 + V_232 , 0x007FFFFF ) ;
F_3 ( V_394 + V_232 , 0x00000001 ) ;
F_3 ( V_395 + V_232 , 0x00000001 ) ;
F_79 ( V_2 , V_241 -> V_243 -> V_235 , true ) ;
}
static void F_90 ( struct V_130 * V_131 , bool V_299 )
{
struct V_76 * V_77 = V_131 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
if ( ! V_241 || ! V_241 -> V_243 )
return;
if ( V_299 && V_241 -> V_243 -> V_157 )
return;
if ( ! V_299 && ! V_241 -> V_243 -> V_157 )
return;
if ( ! V_299 && V_241 -> V_243 -> V_235 ) {
F_79 ( V_2 , V_241 -> V_243 -> V_235 , false ) ;
V_241 -> V_243 -> V_235 = NULL ;
}
V_241 -> V_243 -> V_157 = V_299 ;
F_18 ( L_13 ,
V_299 ? L_14 : L_15 , V_241 -> V_243 -> V_232 , V_133 -> V_140 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_396 ; V_18 ++ )
V_2 -> V_19 . V_243 [ V_18 ] = NULL ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_396 ; V_18 ++ ) {
V_2 -> V_19 . V_243 [ V_18 ] = F_92 ( sizeof( struct V_397 ) , V_398 ) ;
if ( V_2 -> V_19 . V_243 [ V_18 ] ) {
V_2 -> V_19 . V_243 [ V_18 ] -> V_232 = V_399 [ V_18 ] ;
V_2 -> V_19 . V_243 [ V_18 ] -> V_245 = V_18 ;
}
}
}
static void F_93 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_396 ; V_18 ++ ) {
F_74 ( V_2 -> V_19 . V_243 [ V_18 ] ) ;
V_2 -> V_19 . V_243 [ V_18 ] = NULL ;
}
}
static void F_94 ( struct V_400 * V_11 , bool V_299 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
T_1 V_401 ;
V_401 = F_4 ( V_402 [ V_27 -> V_25 ] ) & ~ 1 ;
if ( V_299 )
F_3 ( V_402 [ V_27 -> V_25 ] , V_401 | 1 ) ;
else
F_3 ( V_402 [ V_27 -> V_25 ] , V_401 ) ;
}
static void F_95 ( struct V_400 * V_11 , bool V_299 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
if ( V_299 )
F_3 ( V_403 + V_27 -> V_31 , 1 ) ;
else
F_3 ( V_403 + V_27 -> V_31 , 0 ) ;
}
static int F_96 ( struct V_400 * V_11 ,
struct V_404 * V_405 ,
int V_406 , int V_407 , int V_408 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_409 * V_410 ;
struct V_404 * V_411 ;
struct V_412 * V_413 ;
struct V_414 * V_415 ;
T_10 V_416 , V_417 ;
T_6 V_418 , V_419 ;
T_1 V_420 = ( V_421 << V_422 ) ;
T_1 V_423 ;
T_1 V_29 , V_424 , V_425 ;
int V_6 ;
bool V_426 = false ;
if ( ! V_408 && ! V_11 -> V_427 -> V_405 ) {
F_42 ( L_16 ) ;
return 0 ;
}
if ( V_408 ) {
V_410 = F_97 ( V_405 ) ;
V_411 = V_405 ;
}
else {
V_410 = F_97 ( V_11 -> V_427 -> V_405 ) ;
V_411 = V_11 -> V_427 -> V_405 ;
}
V_413 = V_410 -> V_413 ;
V_415 = F_98 ( V_413 ) ;
V_6 = F_99 ( V_415 , false ) ;
if ( F_100 ( V_6 != 0 ) )
return V_6 ;
if ( V_408 )
V_416 = F_101 ( V_415 ) ;
else {
V_6 = F_102 ( V_415 , V_428 , & V_416 ) ;
if ( F_100 ( V_6 != 0 ) ) {
F_103 ( V_415 ) ;
return - V_41 ;
}
}
F_104 ( V_415 , & V_417 ) ;
F_103 ( V_415 ) ;
V_423 = F_105 ( V_417 , V_429 ) ;
switch ( V_411 -> V_430 ) {
case V_431 :
V_418 = ( ( V_432 << V_433 ) |
( V_434 << V_435 ) ) ;
break;
case V_436 :
case V_437 :
V_418 = ( ( V_438 << V_433 ) |
( V_439 << V_435 ) ) ;
#ifdef F_106
V_420 = ( V_440 << V_422 ) ;
#endif
break;
case V_441 :
case V_442 :
V_418 = ( ( V_438 << V_433 ) |
( V_439 << V_435 ) ) ;
#ifdef F_106
V_420 = ( V_440 << V_422 ) ;
#endif
break;
case V_443 :
case V_444 :
V_418 = ( ( V_438 << V_433 ) |
( V_445 << V_435 ) ) ;
#ifdef F_106
V_420 = ( V_440 << V_422 ) ;
#endif
break;
case V_446 :
V_418 = ( ( V_438 << V_433 ) |
( V_447 << V_435 ) ) ;
#ifdef F_106
V_420 = ( V_440 << V_422 ) ;
#endif
break;
case V_448 :
case V_449 :
V_418 = ( ( V_450 << V_433 ) |
( V_451 << V_435 ) ) ;
#ifdef F_106
V_420 = ( V_452 << V_422 ) ;
#endif
break;
case V_453 :
case V_454 :
V_418 = ( ( V_450 << V_433 ) |
( V_455 << V_435 ) ) ;
#ifdef F_106
V_420 = ( V_452 << V_422 ) ;
#endif
V_426 = true ;
break;
case V_456 :
case V_457 :
V_418 = ( ( V_450 << V_433 ) |
( V_458 << V_435 ) ) ;
#ifdef F_106
V_420 = ( V_452 << V_422 ) ;
#endif
V_426 = true ;
break;
default:
F_67 ( L_17 ,
F_107 ( V_411 -> V_430 ) ) ;
return - V_41 ;
}
if ( F_105 ( V_417 , V_459 ) == V_460 ) {
unsigned V_461 , V_462 , V_463 , V_464 , V_465 ;
V_461 = F_105 ( V_417 , V_466 ) ;
V_462 = F_105 ( V_417 , V_467 ) ;
V_463 = F_105 ( V_417 , V_468 ) ;
V_464 = F_105 ( V_417 , V_469 ) ;
V_465 = F_105 ( V_417 , V_470 ) ;
V_418 |= ( V_465 << V_471 ) ;
V_418 |= ( V_472 << V_473 ) ;
V_418 |= ( V_464 << V_474 ) ;
V_418 |= ( V_461 << V_475 ) ;
V_418 |= ( V_462 << V_476 ) ;
V_418 |= ( V_463 << V_477 ) ;
V_418 |= ( V_478 << V_479 ) ;
} else if ( F_105 ( V_417 , V_459 ) == V_480 ) {
V_418 |= ( V_481 << V_473 ) ;
}
V_418 |= ( V_423 << V_482 ) ;
F_94 ( V_11 , false ) ;
F_3 ( V_35 + V_27 -> V_31 ,
F_16 ( V_416 ) ) ;
F_3 ( V_33 + V_27 -> V_31 ,
F_16 ( V_416 ) ) ;
F_3 ( V_36 + V_27 -> V_31 ,
( T_1 ) V_416 & V_483 ) ;
F_3 ( V_34 + V_27 -> V_31 ,
( T_1 ) V_416 & V_484 ) ;
F_3 ( V_485 + V_27 -> V_31 , V_418 ) ;
F_3 ( V_486 + V_27 -> V_31 , V_420 ) ;
F_89 ( V_487 + V_27 -> V_31 ,
( V_426 ? V_488 : 0 ) ,
~ V_488 ) ;
if ( V_426 )
F_42 ( L_18 ) ;
F_3 ( V_489 + V_27 -> V_31 , 0 ) ;
F_3 ( V_490 + V_27 -> V_31 , 0 ) ;
F_3 ( V_491 + V_27 -> V_31 , 0 ) ;
F_3 ( V_492 + V_27 -> V_31 , 0 ) ;
F_3 ( V_493 + V_27 -> V_31 , V_411 -> V_494 ) ;
F_3 ( V_495 + V_27 -> V_31 , V_411 -> V_496 ) ;
V_419 = V_411 -> V_497 [ 0 ] / ( V_411 -> V_498 / 8 ) ;
F_3 ( V_499 + V_27 -> V_31 , V_419 ) ;
F_95 ( V_11 , true ) ;
F_3 ( V_500 + V_27 -> V_31 ,
V_411 -> V_496 ) ;
V_406 &= ~ 3 ;
V_407 &= ~ 1 ;
F_3 ( V_501 + V_27 -> V_31 ,
( V_406 << 16 ) | V_407 ) ;
V_424 = V_11 -> V_153 . V_502 ;
V_425 = ( V_11 -> V_153 . V_503 + 1 ) & ~ 1 ;
F_3 ( V_504 + V_27 -> V_31 ,
( V_424 << 16 ) | V_425 ) ;
V_29 = F_4 ( V_505 + V_27 -> V_31 ) ;
V_29 &= ~ V_506 ;
F_3 ( V_505 + V_27 -> V_31 , V_29 ) ;
F_3 ( V_115 + V_27 -> V_31 , 3 ) ;
if ( ! V_408 && V_405 && V_405 != V_11 -> V_427 -> V_405 ) {
V_410 = F_97 ( V_405 ) ;
V_415 = F_98 ( V_410 -> V_413 ) ;
V_6 = F_99 ( V_415 , false ) ;
if ( F_100 ( V_6 != 0 ) )
return V_6 ;
F_108 ( V_415 ) ;
F_103 ( V_415 ) ;
}
F_62 ( V_2 ) ;
return 0 ;
}
static void F_109 ( struct V_400 * V_11 ,
struct V_152 * V_153 )
{
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_27 * V_27 = F_38 ( V_11 ) ;
if ( V_153 -> V_5 & V_223 )
F_3 ( V_507 + V_27 -> V_31 ,
V_508 ) ;
else
F_3 ( V_507 + V_27 -> V_31 , 0 ) ;
}
static void F_110 ( struct V_400 * V_11 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
int V_18 ;
F_42 ( L_19 , V_27 -> V_25 ) ;
F_3 ( V_509 + V_27 -> V_31 ,
( ( V_510 << V_511 ) |
( V_510 << V_512 ) ) ) ;
F_3 ( V_513 + V_27 -> V_31 ,
V_514 ) ;
F_3 ( V_515 + V_27 -> V_31 ,
V_516 ) ;
F_3 ( V_517 + V_27 -> V_31 ,
( ( V_518 << V_519 ) |
( V_518 << V_520 ) ) ) ;
F_3 ( V_521 + V_27 -> V_31 , 0 ) ;
F_3 ( V_522 + V_27 -> V_31 , 0 ) ;
F_3 ( V_523 + V_27 -> V_31 , 0 ) ;
F_3 ( V_524 + V_27 -> V_31 , 0 ) ;
F_3 ( V_525 + V_27 -> V_31 , 0xffff ) ;
F_3 ( V_526 + V_27 -> V_31 , 0xffff ) ;
F_3 ( V_527 + V_27 -> V_31 , 0xffff ) ;
F_3 ( V_528 + V_27 -> V_31 , 0 ) ;
F_3 ( V_529 + V_27 -> V_31 , 0x00000007 ) ;
F_3 ( V_530 + V_27 -> V_31 , 0 ) ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
F_3 ( V_531 + V_27 -> V_31 ,
( V_27 -> V_532 [ V_18 ] << 20 ) |
( V_27 -> V_533 [ V_18 ] << 10 ) |
( V_27 -> V_534 [ V_18 ] << 0 ) ) ;
}
F_3 ( V_535 + V_27 -> V_31 ,
( ( V_536 << V_537 ) |
( V_536 << V_538 ) |
( V_536 << V_539 ) ) ) ;
F_3 ( V_540 + V_27 -> V_31 ,
( ( V_541 << V_542 ) |
( V_541 << V_543 ) ) ) ;
F_3 ( V_544 + V_27 -> V_31 ,
( ( V_545 << V_546 ) |
( V_545 << V_547 ) ) ) ;
F_3 ( V_548 + V_27 -> V_31 ,
( ( V_549 << V_550 ) |
( V_549 << V_551 ) ) ) ;
F_3 ( 0x1a50 + V_27 -> V_31 , 0 ) ;
F_3 ( V_552 + V_27 -> V_31 ,
V_553 ) ;
}
static int F_111 ( struct V_130 * V_131 )
{
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 = V_133 -> V_242 ;
switch ( V_133 -> V_140 ) {
case V_554 :
if ( V_241 -> V_555 )
return 1 ;
else
return 0 ;
break;
case V_556 :
if ( V_241 -> V_555 )
return 3 ;
else
return 2 ;
break;
case V_557 :
if ( V_241 -> V_555 )
return 5 ;
else
return 4 ;
break;
case V_558 :
return 6 ;
break;
default:
F_67 ( L_20 , V_133 -> V_140 ) ;
return 0 ;
}
}
static T_1 F_112 ( struct V_400 * V_11 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
T_1 V_559 ;
int V_560 ;
if ( F_113 ( F_114 ( V_27 -> V_131 ) ) ) {
if ( V_2 -> clock . V_561 )
return V_562 ;
else {
V_560 = F_115 ( V_11 ) ;
if ( V_560 != V_562 )
return V_560 ;
}
} else {
V_560 = F_116 ( V_11 ) ;
if ( V_560 != V_562 )
return V_560 ;
}
if ( ( V_2 -> V_303 == V_305 ) ||
( V_2 -> V_303 == V_306 ) ) {
V_559 = F_117 ( V_11 ) ;
if ( ! ( V_559 & ( 1 << V_563 ) ) )
return V_563 ;
if ( ! ( V_559 & ( 1 << V_564 ) ) )
return V_564 ;
F_67 ( L_21 ) ;
return V_562 ;
} else {
V_559 = F_117 ( V_11 ) ;
if ( ! ( V_559 & ( 1 << V_563 ) ) )
return V_563 ;
if ( ! ( V_559 & ( 1 << V_564 ) ) )
return V_564 ;
if ( ! ( V_559 & ( 1 << V_565 ) ) )
return V_565 ;
F_67 ( L_21 ) ;
return V_562 ;
}
return V_562 ;
}
static void F_118 ( struct V_400 * V_11 , bool V_566 )
{
struct V_1 * V_2 = V_11 -> V_77 -> V_132 ;
struct V_27 * V_27 = F_38 ( V_11 ) ;
T_6 V_567 ;
V_567 = F_4 ( V_568 + V_27 -> V_31 ) ;
if ( V_566 )
V_567 |= V_569 ;
else
V_567 &= ~ V_569 ;
F_3 ( V_568 + V_27 -> V_31 , V_567 ) ;
}
static void F_119 ( struct V_400 * V_11 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_77 -> V_132 ;
F_120 ( V_570 + V_27 -> V_31 ,
( V_571 << V_572 ) |
( V_573 << V_574 ) ) ;
}
static void F_121 ( struct V_400 * V_11 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_77 -> V_132 ;
F_120 ( V_570 + V_27 -> V_31 ,
V_575 |
( V_571 << V_572 ) |
( V_573 << V_574 ) ) ;
}
static void F_122 ( struct V_400 * V_11 , struct V_412 * V_413 ,
T_10 V_576 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_77 -> V_132 ;
F_3 ( V_577 + V_27 -> V_31 ,
F_16 ( V_576 ) ) ;
F_3 ( V_578 + V_27 -> V_31 ,
V_576 & 0xffffffff ) ;
}
static int F_123 ( struct V_400 * V_11 ,
int V_406 , int V_407 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_77 -> V_132 ;
int V_579 = 0 , V_580 = 0 ;
V_406 += V_11 -> V_406 ;
V_407 += V_11 -> V_407 ;
F_18 ( L_22 , V_406 , V_407 , V_11 -> V_406 , V_11 -> V_407 ) ;
if ( V_406 < 0 ) {
V_579 = F_53 ( - V_406 , V_27 -> V_581 - 1 ) ;
V_406 = 0 ;
}
if ( V_407 < 0 ) {
V_580 = F_53 ( - V_407 , V_27 -> V_582 - 1 ) ;
V_407 = 0 ;
}
F_118 ( V_11 , true ) ;
F_3 ( V_583 + V_27 -> V_31 , ( V_406 << 16 ) | V_407 ) ;
F_3 ( V_584 + V_27 -> V_31 , ( V_579 << 16 ) | V_580 ) ;
F_3 ( V_585 + V_27 -> V_31 ,
( ( V_27 -> V_586 - 1 ) << 16 ) | ( V_27 -> V_587 - 1 ) ) ;
F_118 ( V_11 , false ) ;
return 0 ;
}
static int F_124 ( struct V_400 * V_11 ,
struct V_588 * V_589 ,
T_6 V_590 ,
T_6 V_494 ,
T_6 V_496 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_412 * V_413 ;
struct V_414 * V_591 ;
T_10 V_576 ;
int V_592 ;
if ( ! V_590 ) {
F_119 ( V_11 ) ;
V_413 = NULL ;
goto V_593;
}
if ( ( V_494 > V_27 -> V_581 ) ||
( V_496 > V_27 -> V_582 ) ) {
F_67 ( L_23 , V_494 , V_496 ) ;
return - V_41 ;
}
V_413 = F_125 ( V_11 -> V_77 , V_589 , V_590 ) ;
if ( ! V_413 ) {
F_67 ( L_24 , V_590 , V_27 -> V_25 ) ;
return - V_594 ;
}
V_591 = F_98 ( V_413 ) ;
V_592 = F_99 ( V_591 , false ) ;
if ( F_100 ( V_592 != 0 ) )
goto V_595;
V_592 = F_126 ( V_591 , V_428 ,
0 , 0 , & V_576 ) ;
F_103 ( V_591 ) ;
if ( V_592 )
goto V_595;
V_27 -> V_586 = V_494 ;
V_27 -> V_587 = V_496 ;
F_118 ( V_11 , true ) ;
F_122 ( V_11 , V_413 , V_576 ) ;
F_121 ( V_11 ) ;
F_118 ( V_11 , false ) ;
V_593:
if ( V_27 -> V_596 ) {
V_591 = F_98 ( V_27 -> V_596 ) ;
V_592 = F_99 ( V_591 , false ) ;
if ( F_127 ( V_592 == 0 ) ) {
F_108 ( V_591 ) ;
F_103 ( V_591 ) ;
}
F_128 ( V_27 -> V_596 ) ;
}
V_27 -> V_596 = V_413 ;
return 0 ;
V_595:
F_128 ( V_413 ) ;
return V_592 ;
}
static void F_129 ( struct V_400 * V_11 , T_5 * V_597 , T_5 * V_598 ,
T_5 * V_599 , T_6 V_600 , T_6 V_331 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
int V_601 = ( V_600 + V_331 > 256 ) ? 256 : V_600 + V_331 , V_18 ;
for ( V_18 = V_600 ; V_18 < V_601 ; V_18 ++ ) {
V_27 -> V_532 [ V_18 ] = V_597 [ V_18 ] >> 6 ;
V_27 -> V_533 [ V_18 ] = V_598 [ V_18 ] >> 6 ;
V_27 -> V_534 [ V_18 ] = V_599 [ V_18 ] >> 6 ;
}
F_110 ( V_11 ) ;
}
static void F_130 ( struct V_400 * V_11 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
F_131 ( V_11 ) ;
F_132 ( V_27 -> V_602 ) ;
F_74 ( V_27 ) ;
}
static void F_133 ( struct V_400 * V_11 , int V_153 )
{
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_27 * V_27 = F_38 ( V_11 ) ;
unsigned type ;
switch ( V_153 ) {
case V_603 :
V_27 -> V_157 = true ;
F_134 ( V_11 , V_604 ) ;
F_94 ( V_11 , true ) ;
F_135 ( V_11 , V_605 ) ;
F_94 ( V_11 , false ) ;
type = F_136 ( V_2 , V_27 -> V_25 ) ;
F_137 ( V_2 , & V_2 -> V_606 , type ) ;
F_137 ( V_2 , & V_2 -> V_24 , type ) ;
F_138 ( V_77 , V_27 -> V_25 ) ;
F_110 ( V_11 ) ;
break;
case V_607 :
case V_608 :
case V_609 :
F_139 ( V_77 , V_27 -> V_25 ) ;
if ( V_27 -> V_157 ) {
F_94 ( V_11 , true ) ;
F_135 ( V_11 , V_604 ) ;
F_94 ( V_11 , false ) ;
}
F_134 ( V_11 , V_605 ) ;
V_27 -> V_157 = false ;
break;
}
F_140 ( V_2 ) ;
}
static void F_141 ( struct V_400 * V_11 )
{
F_142 ( V_11 , V_605 ) ;
F_143 ( V_11 , V_604 ) ;
F_133 ( V_11 , V_609 ) ;
}
static void F_144 ( struct V_400 * V_11 )
{
F_133 ( V_11 , V_603 ) ;
F_143 ( V_11 , V_605 ) ;
}
static void F_145 ( struct V_400 * V_11 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
struct V_610 V_611 ;
int V_18 ;
F_133 ( V_11 , V_609 ) ;
if ( V_11 -> V_427 -> V_405 ) {
int V_6 ;
struct V_409 * V_410 ;
struct V_414 * V_415 ;
V_410 = F_97 ( V_11 -> V_427 -> V_405 ) ;
V_415 = F_98 ( V_410 -> V_413 ) ;
V_6 = F_99 ( V_415 , false ) ;
if ( F_100 ( V_6 ) )
F_67 ( L_25 ) ;
else {
F_108 ( V_415 ) ;
F_103 ( V_415 ) ;
}
}
F_95 ( V_11 , false ) ;
F_142 ( V_11 , V_604 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_28 [ V_18 ] &&
V_2 -> V_19 . V_28 [ V_18 ] -> V_157 &&
V_18 != V_27 -> V_25 &&
V_27 -> V_612 == V_2 -> V_19 . V_28 [ V_18 ] -> V_612 ) {
goto V_613;
}
}
switch ( V_27 -> V_612 ) {
case V_564 :
case V_563 :
F_146 ( V_11 , V_27 -> V_25 , V_27 -> V_612 ,
0 , 0 , V_605 , 0 , 0 , 0 , 0 , 0 , false , & V_611 ) ;
break;
case V_565 :
if ( ( V_2 -> V_303 == V_304 ) ||
( V_2 -> V_303 == V_307 ) ||
( V_2 -> V_303 == V_308 ) )
F_146 ( V_11 , V_27 -> V_25 , V_27 -> V_612 ,
0 , 0 , V_605 , 0 , 0 , 0 , 0 , 0 , false , & V_611 ) ;
break;
default:
break;
}
V_613:
V_27 -> V_612 = V_562 ;
V_27 -> V_614 = 0 ;
V_27 -> V_131 = NULL ;
V_27 -> V_80 = NULL ;
}
static int F_147 ( struct V_400 * V_11 ,
struct V_152 * V_153 ,
struct V_152 * V_615 ,
int V_406 , int V_407 , struct V_404 * V_616 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
if ( ! V_27 -> V_614 )
return - V_41 ;
F_148 ( V_11 , V_615 ) ;
F_149 ( V_11 , V_615 ) ;
F_96 ( V_11 , V_616 , V_406 , V_407 , 0 ) ;
F_150 ( V_11 , V_153 , V_615 ) ;
F_151 ( V_11 ) ;
V_27 -> V_617 = * V_615 ;
return 0 ;
}
static bool F_152 ( struct V_400 * V_11 ,
const struct V_152 * V_153 ,
struct V_152 * V_615 )
{
struct V_27 * V_27 = F_38 ( V_11 ) ;
struct V_76 * V_77 = V_11 -> V_77 ;
struct V_130 * V_131 ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_131 -> V_11 == V_11 ) {
V_27 -> V_131 = V_131 ;
V_27 -> V_80 = F_39 ( V_131 ) ;
break;
}
}
if ( ( V_27 -> V_131 == NULL ) || ( V_27 -> V_80 == NULL ) ) {
V_27 -> V_131 = NULL ;
V_27 -> V_80 = NULL ;
return false ;
}
if ( ! F_153 ( V_11 , V_153 , V_615 ) )
return false ;
if ( F_154 ( V_11 , V_615 ) )
return false ;
V_27 -> V_612 = F_112 ( V_11 ) ;
if ( ( V_27 -> V_612 == V_562 ) &&
! F_113 ( F_114 ( V_27 -> V_131 ) ) )
return false ;
return true ;
}
static int F_155 ( struct V_400 * V_11 , int V_406 , int V_407 ,
struct V_404 * V_616 )
{
return F_96 ( V_11 , V_616 , V_406 , V_407 , 0 ) ;
}
static int F_156 ( struct V_400 * V_11 ,
struct V_404 * V_405 ,
int V_406 , int V_407 , enum V_618 V_619 )
{
return F_96 ( V_11 , V_405 , V_406 , V_407 , 1 ) ;
}
static int F_157 ( struct V_1 * V_2 , int V_620 )
{
struct V_27 * V_27 ;
int V_18 ;
V_27 = F_92 ( sizeof( struct V_27 ) +
( V_621 * sizeof( struct V_79 * ) ) , V_398 ) ;
if ( V_27 == NULL )
return - V_622 ;
F_158 ( V_2 -> V_78 , & V_27 -> V_156 , & V_623 ) ;
F_159 ( & V_27 -> V_156 , 256 ) ;
V_27 -> V_25 = V_620 ;
V_27 -> V_602 = F_160 ( L_26 ) ;
V_2 -> V_19 . V_28 [ V_620 ] = V_27 ;
V_27 -> V_581 = V_624 ;
V_27 -> V_582 = V_625 ;
V_2 -> V_78 -> V_626 . V_586 = V_27 -> V_581 ;
V_2 -> V_78 -> V_626 . V_587 = V_27 -> V_582 ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
V_27 -> V_532 [ V_18 ] = V_18 << 2 ;
V_27 -> V_533 [ V_18 ] = V_18 << 2 ;
V_27 -> V_534 [ V_18 ] = V_18 << 2 ;
}
V_27 -> V_31 = V_13 [ V_27 -> V_25 ] ;
V_27 -> V_612 = V_562 ;
V_27 -> V_614 = 0 ;
V_27 -> V_131 = NULL ;
V_27 -> V_80 = NULL ;
F_161 ( & V_27 -> V_156 , & V_627 ) ;
return 0 ;
}
static int F_162 ( void * V_590 )
{
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
V_2 -> V_628 = & F_1 ;
V_2 -> V_629 = & F_6 ;
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
switch ( V_2 -> V_303 ) {
case V_307 :
case V_308 :
V_2 -> V_19 . V_20 = 6 ;
V_2 -> V_19 . V_630 = 6 ;
V_2 -> V_19 . V_396 = 6 ;
break;
case V_304 :
V_2 -> V_19 . V_20 = 4 ;
V_2 -> V_19 . V_630 = 6 ;
V_2 -> V_19 . V_396 = 7 ;
break;
case V_305 :
case V_306 :
V_2 -> V_19 . V_20 = 2 ;
V_2 -> V_19 . V_630 = 6 ;
V_2 -> V_19 . V_396 = 6 ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_165 ( void * V_590 )
{
int V_6 , V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_6 = F_166 ( V_2 , V_18 + 1 , & V_2 -> V_606 ) ;
if ( V_6 )
return V_6 ;
}
for ( V_18 = 8 ; V_18 < 20 ; V_18 += 2 ) {
V_6 = F_166 ( V_2 , V_18 , & V_2 -> V_24 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_166 ( V_2 , 42 , & V_2 -> V_94 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_19 . V_631 = true ;
V_2 -> V_78 -> V_626 . V_632 = & V_633 ;
V_2 -> V_78 -> V_626 . V_634 = 16384 ;
V_2 -> V_78 -> V_626 . V_635 = 16384 ;
V_2 -> V_78 -> V_626 . V_636 = 24 ;
V_2 -> V_78 -> V_626 . V_637 = 1 ;
V_2 -> V_78 -> V_626 . V_638 = V_2 -> V_113 . V_639 ;
V_6 = F_167 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_78 -> V_626 . V_634 = 16384 ;
V_2 -> V_78 -> V_626 . V_635 = 16384 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_6 = F_157 ( V_2 , V_18 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_168 ( V_2 ) )
F_169 ( V_2 -> V_78 ) ;
else
return - V_41 ;
F_91 ( V_2 ) ;
V_6 = F_80 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_170 ( V_2 -> V_78 ) ;
return V_6 ;
}
static int F_171 ( void * V_590 )
{
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
F_74 ( V_2 -> V_19 . V_640 ) ;
F_172 ( V_2 -> V_78 ) ;
F_81 ( V_2 ) ;
F_93 ( V_2 ) ;
F_173 ( V_2 -> V_78 ) ;
V_2 -> V_19 . V_631 = false ;
return 0 ;
}
static int F_174 ( void * V_590 )
{
int V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
F_175 ( V_2 ) ;
F_176 ( V_2 , V_2 -> clock . V_641 ) ;
F_22 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_233 . V_234 ; V_18 ++ ) {
F_79 ( V_2 , & V_2 -> V_19 . V_233 . V_235 [ V_18 ] , false ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int F_177 ( void * V_590 )
{
int V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
F_25 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_233 . V_234 ; V_18 ++ ) {
F_79 ( V_2 , & V_2 -> V_19 . V_233 . V_235 [ V_18 ] , false ) ;
}
F_13 ( V_2 ) ;
return 0 ;
}
static int F_178 ( void * V_590 )
{
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
F_179 ( V_2 ) ;
F_25 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_180 ( void * V_590 )
{
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
F_181 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 , V_2 -> clock . V_641 ) ;
if ( V_2 -> V_19 . V_642 ) {
T_4 V_643 = F_182 ( V_2 ,
V_2 -> V_19 . V_642 ) ;
F_183 ( V_2 , V_2 -> V_19 . V_642 ,
V_643 ) ;
}
F_22 ( V_2 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static bool F_184 ( void * V_590 )
{
return true ;
}
static int F_185 ( void * V_590 )
{
return 0 ;
}
static void F_186 ( void * V_590 )
{
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
F_187 ( V_2 -> V_77 , L_27 ) ;
}
static int F_188 ( void * V_590 )
{
T_1 V_644 = 0 , V_29 ;
struct V_1 * V_2 = (struct V_1 * ) V_590 ;
if ( F_27 ( V_2 ) )
V_644 |= V_645 ;
if ( V_644 ) {
F_186 ( ( void * ) V_2 ) ;
V_29 = F_4 ( V_646 ) ;
V_29 |= V_644 ;
F_187 ( V_2 -> V_77 , L_28 , V_29 ) ;
F_3 ( V_646 , V_29 ) ;
V_29 = F_4 ( V_646 ) ;
F_17 ( 50 ) ;
V_29 &= ~ V_644 ;
F_3 ( V_646 , V_29 ) ;
V_29 = F_4 ( V_646 ) ;
F_17 ( 50 ) ;
F_186 ( ( void * ) V_2 ) ;
}
return 0 ;
}
static void F_189 ( struct V_1 * V_2 ,
int V_11 ,
enum V_647 V_619 )
{
T_1 V_648 , V_649 ;
if ( V_11 >= V_2 -> V_19 . V_20 ) {
F_18 ( L_29 , V_11 ) ;
return;
}
switch ( V_11 ) {
case 0 :
V_648 = V_650 ;
break;
case 1 :
V_648 = V_651 ;
break;
case 2 :
V_648 = V_652 ;
break;
case 3 :
V_648 = V_653 ;
break;
case 4 :
V_648 = V_654 ;
break;
case 5 :
V_648 = V_655 ;
break;
default:
F_18 ( L_29 , V_11 ) ;
return;
}
switch ( V_619 ) {
case V_656 :
V_649 = F_4 ( V_657 + V_648 ) ;
V_649 &= ~ V_658 ;
F_3 ( V_657 + V_648 , V_649 ) ;
break;
case V_659 :
V_649 = F_4 ( V_657 + V_648 ) ;
V_649 |= V_658 ;
F_3 ( V_657 + V_648 , V_649 ) ;
break;
default:
break;
}
}
static void F_190 ( struct V_1 * V_2 ,
int V_11 ,
enum V_647 V_619 )
{
T_1 V_648 , V_649 ;
if ( V_11 >= V_2 -> V_19 . V_20 ) {
F_18 ( L_29 , V_11 ) ;
return;
}
switch ( V_11 ) {
case 0 :
V_648 = V_650 ;
break;
case 1 :
V_648 = V_651 ;
break;
case 2 :
V_648 = V_652 ;
break;
case 3 :
V_648 = V_653 ;
break;
case 4 :
V_648 = V_654 ;
break;
case 5 :
V_648 = V_655 ;
break;
default:
F_18 ( L_29 , V_11 ) ;
return;
}
switch ( V_619 ) {
case V_656 :
V_649 = F_4 ( V_657 + V_648 ) ;
V_649 &= ~ V_660 ;
F_3 ( V_657 + V_648 , V_649 ) ;
break;
case V_659 :
V_649 = F_4 ( V_657 + V_648 ) ;
V_649 |= V_660 ;
F_3 ( V_657 + V_648 , V_649 ) ;
break;
default:
break;
}
}
static int F_191 ( struct V_1 * V_2 ,
struct V_661 * V_662 ,
unsigned type ,
enum V_647 V_619 )
{
T_1 V_663 , V_664 ;
switch ( type ) {
case V_46 :
V_663 = V_64 ;
break;
case V_49 :
V_663 = V_66 ;
break;
case V_52 :
V_663 = V_68 ;
break;
case V_55 :
V_663 = V_70 ;
break;
case V_58 :
V_663 = V_72 ;
break;
case V_61 :
V_663 = V_74 ;
break;
default:
F_18 ( L_30 , type ) ;
return 0 ;
}
switch ( V_619 ) {
case V_656 :
V_664 = F_4 ( V_663 ) ;
V_664 &= ~ V_665 ;
F_3 ( V_663 , V_664 ) ;
break;
case V_659 :
V_664 = F_4 ( V_663 ) ;
V_664 |= V_665 ;
F_3 ( V_663 , V_664 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_192 ( struct V_1 * V_2 ,
struct V_661 * V_662 ,
unsigned type ,
enum V_647 V_619 )
{
switch ( type ) {
case V_666 :
F_189 ( V_2 , 0 , V_619 ) ;
break;
case V_667 :
F_189 ( V_2 , 1 , V_619 ) ;
break;
case V_668 :
F_189 ( V_2 , 2 , V_619 ) ;
break;
case V_669 :
F_189 ( V_2 , 3 , V_619 ) ;
break;
case V_670 :
F_189 ( V_2 , 4 , V_619 ) ;
break;
case V_671 :
F_189 ( V_2 , 5 , V_619 ) ;
break;
case V_672 :
F_190 ( V_2 , 0 , V_619 ) ;
break;
case V_673 :
F_190 ( V_2 , 1 , V_619 ) ;
break;
case V_674 :
F_190 ( V_2 , 2 , V_619 ) ;
break;
case V_675 :
F_190 ( V_2 , 3 , V_619 ) ;
break;
case V_676 :
F_190 ( V_2 , 4 , V_619 ) ;
break;
case V_677 :
F_190 ( V_2 , 5 , V_619 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_193 ( struct V_1 * V_2 ,
struct V_661 * V_678 ,
struct V_679 * V_680 )
{
unsigned V_11 = V_680 -> V_681 - 1 ;
T_6 V_682 = F_4 ( V_683 [ V_11 ] . V_4 ) ;
unsigned V_684 = F_136 ( V_2 , V_11 ) ;
switch ( V_680 -> V_685 ) {
case 0 :
if ( V_682 & V_683 [ V_11 ] . V_686 )
F_3 ( V_687 + V_13 [ V_11 ] , V_688 ) ;
else
F_18 ( L_31 ) ;
if ( F_194 ( V_2 , V_678 , V_684 ) ) {
F_195 ( V_2 -> V_78 , V_11 ) ;
}
F_18 ( L_32 , V_11 + 1 ) ;
break;
case 1 :
if ( V_682 & V_683 [ V_11 ] . V_689 )
F_3 ( V_690 + V_13 [ V_11 ] , V_691 ) ;
else
F_18 ( L_31 ) ;
F_18 ( L_33 , V_11 + 1 ) ;
break;
default:
F_18 ( L_34 , V_680 -> V_681 , V_680 -> V_685 ) ;
break;
}
return 0 ;
}
static int F_196 ( struct V_1 * V_2 ,
struct V_661 * V_662 ,
unsigned type ,
enum V_647 V_619 )
{
T_1 V_4 , V_648 ;
switch ( type ) {
case V_692 :
V_648 = V_650 ;
break;
case V_693 :
V_648 = V_651 ;
break;
case V_694 :
V_648 = V_652 ;
break;
case V_695 :
V_648 = V_653 ;
break;
case V_696 :
V_648 = V_654 ;
break;
case V_697 :
V_648 = V_655 ;
break;
default:
F_67 ( L_35 , type ) ;
return - V_41 ;
}
V_4 = F_4 ( V_698 + V_648 ) ;
if ( V_619 == V_656 )
F_3 ( V_698 + V_648 , V_4 & ~ V_699 ) ;
else
F_3 ( V_698 + V_648 , V_4 | V_699 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_661 * V_678 ,
struct V_679 * V_680 )
{
int V_648 ;
unsigned long V_5 ;
unsigned V_25 ;
struct V_27 * V_27 ;
struct V_700 * V_701 ;
V_25 = ( V_680 -> V_681 - 8 ) >> 1 ;
V_27 = V_2 -> V_19 . V_28 [ V_25 ] ;
switch( V_25 ) {
case V_692 :
V_648 = V_650 ;
break;
case V_693 :
V_648 = V_651 ;
break;
case V_694 :
V_648 = V_652 ;
break;
case V_695 :
V_648 = V_653 ;
break;
case V_696 :
V_648 = V_654 ;
break;
case V_697 :
V_648 = V_655 ;
break;
default:
F_67 ( L_35 , V_25 ) ;
return - V_41 ;
}
if ( F_4 ( V_702 + V_648 ) & V_703 )
F_3 ( V_702 + V_648 , V_704 ) ;
if ( V_27 == NULL )
return 0 ;
F_2 ( & V_2 -> V_78 -> V_705 , V_5 ) ;
V_701 = V_27 -> V_706 ;
if ( V_27 -> V_707 != V_708 ) {
F_198 ( L_36
L_37 ,
V_27 -> V_707 ,
V_708 ) ;
F_5 ( & V_2 -> V_78 -> V_705 , V_5 ) ;
return 0 ;
}
V_27 -> V_707 = V_709 ;
V_27 -> V_706 = NULL ;
if ( V_701 -> V_710 )
F_199 ( V_2 -> V_78 , V_25 , V_701 -> V_710 ) ;
F_5 ( & V_2 -> V_78 -> V_705 , V_5 ) ;
F_200 ( V_2 -> V_78 , V_27 -> V_25 ) ;
F_201 ( V_27 -> V_602 , & V_701 -> V_711 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 ,
struct V_661 * V_678 ,
struct V_679 * V_680 )
{
T_6 V_682 , V_712 , V_713 , V_29 ;
unsigned V_44 ;
if ( V_680 -> V_685 >= V_2 -> V_19 . V_630 ) {
F_18 ( L_34 , V_680 -> V_681 , V_680 -> V_685 ) ;
return 0 ;
}
V_44 = V_680 -> V_685 ;
V_682 = F_4 ( V_683 [ V_44 ] . V_4 ) ;
V_712 = V_683 [ V_44 ] . V_44 ;
V_713 = V_714 [ V_44 ] ;
if ( V_682 & V_712 ) {
V_29 = F_4 ( V_713 ) ;
V_29 |= V_715 ;
F_3 ( V_713 , V_29 ) ;
F_203 ( & V_2 -> V_716 ) ;
F_18 ( L_38 , V_44 + 1 ) ;
}
return 0 ;
}
static int F_204 ( void * V_590 ,
enum V_717 V_619 )
{
return 0 ;
}
static int F_205 ( void * V_590 ,
enum V_718 V_619 )
{
return 0 ;
}
static void
F_206 ( struct V_130 * V_131 ,
struct V_152 * V_153 ,
struct V_152 * V_615 )
{
struct V_133 * V_133 = F_37 ( V_131 ) ;
V_133 -> V_719 = V_615 -> clock ;
F_207 ( V_131 , V_609 ) ;
F_109 ( V_131 -> V_11 , V_153 ) ;
if ( F_114 ( V_131 ) == V_720 ) {
F_90 ( V_131 , true ) ;
F_85 ( V_131 , V_615 ) ;
}
}
static void F_208 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = V_131 -> V_77 -> V_132 ;
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_79 * V_80 = F_39 ( V_131 ) ;
if ( ( V_133 -> V_721 &
( V_722 | V_139 ) ) ||
( F_209 ( V_131 ) !=
V_723 ) ) {
struct V_240 * V_241 = V_133 -> V_242 ;
if ( V_241 ) {
V_241 -> V_724 = F_111 ( V_131 ) ;
if ( V_133 -> V_721 & V_722 )
V_241 -> V_243 = V_2 -> V_19 . V_243 [ V_241 -> V_724 ] ;
}
}
F_210 ( V_2 , true ) ;
if ( V_80 ) {
struct V_84 * V_84 = F_24 ( V_80 ) ;
if ( V_84 -> V_725 . V_726 )
F_211 ( V_84 ) ;
if ( V_80 -> V_85 == V_86 )
F_212 ( V_80 ,
V_727 ) ;
}
F_213 ( V_131 ) ;
F_36 ( V_131 ) ;
}
static void F_214 ( struct V_130 * V_131 )
{
struct V_76 * V_77 = V_131 -> V_77 ;
struct V_1 * V_2 = V_77 -> V_132 ;
F_207 ( V_131 , V_603 ) ;
F_210 ( V_2 , false ) ;
}
static void F_215 ( struct V_130 * V_131 )
{
struct V_133 * V_133 = F_37 ( V_131 ) ;
struct V_240 * V_241 ;
F_207 ( V_131 , V_609 ) ;
if ( F_216 ( V_131 ) ) {
if ( F_114 ( V_131 ) == V_720 )
F_90 ( V_131 , false ) ;
V_241 = V_133 -> V_242 ;
V_241 -> V_724 = - 1 ;
}
V_133 -> V_721 = 0 ;
}
static void F_217 ( struct V_130 * V_131 )
{
}
static void F_218 ( struct V_130 * V_131 )
{
}
static void
F_219 ( struct V_130 * V_131 ,
struct V_152 * V_153 ,
struct V_152 * V_615 )
{
}
static void F_220 ( struct V_130 * V_131 )
{
}
static void
F_221 ( struct V_130 * V_131 , int V_153 )
{
}
static bool F_222 ( struct V_130 * V_131 ,
const struct V_152 * V_153 ,
struct V_152 * V_615 )
{
return true ;
}
static void F_223 ( struct V_130 * V_131 )
{
struct V_133 * V_133 = F_37 ( V_131 ) ;
if ( V_133 -> V_138 & ( V_139 ) )
F_224 ( V_133 ) ;
F_74 ( V_133 -> V_242 ) ;
F_225 ( V_131 ) ;
F_74 ( V_133 ) ;
}
static void F_226 ( struct V_1 * V_2 ,
T_6 V_728 ,
T_6 V_729 ,
T_5 V_730 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
struct V_130 * V_131 ;
struct V_133 * V_133 ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
V_133 = F_37 ( V_131 ) ;
if ( V_133 -> V_728 == V_728 ) {
V_133 -> V_138 |= V_729 ;
return;
}
}
V_133 = F_92 ( sizeof( struct V_133 ) , V_398 ) ;
if ( ! V_133 )
return;
V_131 = & V_133 -> V_156 ;
switch ( V_2 -> V_19 . V_20 ) {
case 1 :
V_131 -> V_731 = 0x1 ;
break;
case 2 :
default:
V_131 -> V_731 = 0x3 ;
break;
case 4 :
V_131 -> V_731 = 0xf ;
break;
case 6 :
V_131 -> V_731 = 0x3f ;
break;
}
V_133 -> V_242 = NULL ;
V_133 -> V_728 = V_728 ;
V_133 -> V_140 = ( V_728 & V_732 ) >> V_733 ;
V_133 -> V_138 = V_729 ;
V_133 -> V_224 = V_225 ;
V_133 -> V_734 = V_735 ;
V_133 -> V_736 = false ;
V_133 -> V_730 = V_730 ;
switch ( V_133 -> V_140 ) {
case V_141 :
case V_142 :
F_227 ( V_77 , V_131 , & V_737 ,
V_738 ) ;
F_228 ( V_131 , & V_739 ) ;
break;
case V_740 :
case V_554 :
case V_556 :
case V_557 :
case V_558 :
if ( V_133 -> V_138 & ( V_139 ) ) {
V_133 -> V_224 = V_741 ;
F_227 ( V_77 , V_131 , & V_737 ,
V_742 ) ;
V_133 -> V_242 = F_229 ( V_133 ) ;
} else if ( V_133 -> V_138 & ( V_743 ) ) {
F_227 ( V_77 , V_131 , & V_737 ,
V_738 ) ;
V_133 -> V_242 = F_230 ( V_133 ) ;
} else {
F_227 ( V_77 , V_131 , & V_737 ,
V_744 ) ;
V_133 -> V_242 = F_230 ( V_133 ) ;
}
F_228 ( V_131 , & V_745 ) ;
break;
case V_746 :
case V_747 :
case V_748 :
case V_749 :
case V_750 :
case V_751 :
case V_752 :
case V_753 :
case V_754 :
V_133 -> V_736 = true ;
if ( V_133 -> V_138 & ( V_139 ) )
F_227 ( V_77 , V_131 , & V_737 ,
V_742 ) ;
else if ( V_133 -> V_138 & ( V_743 ) )
F_227 ( V_77 , V_131 , & V_737 ,
V_738 ) ;
else
F_227 ( V_77 , V_131 , & V_737 ,
V_744 ) ;
F_228 ( V_131 , & V_755 ) ;
break;
}
}
static void F_163 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 . V_632 == NULL )
V_2 -> V_19 . V_632 = & V_756 ;
}
static void F_164 ( struct V_1 * V_2 )
{
V_2 -> V_606 . V_757 = V_758 ;
V_2 -> V_606 . V_632 = & V_759 ;
V_2 -> V_24 . V_757 = V_760 ;
V_2 -> V_24 . V_632 = & V_761 ;
V_2 -> V_94 . V_757 = V_762 ;
V_2 -> V_94 . V_632 = & V_763 ;
}
