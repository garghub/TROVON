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
static void F_11 ( struct V_1 * V_2 ,
int V_24 , T_2 V_25 )
{
struct V_26 * V_26 = V_2 -> V_19 . V_27 [ V_24 ] ;
T_1 V_28 = F_4 ( V_29 + V_26 -> V_30 ) ;
int V_18 ;
V_28 |= V_31 ;
F_3 ( V_29 + V_26 -> V_30 , V_28 ) ;
F_3 ( V_32 + V_26 -> V_30 ,
F_12 ( V_25 ) ) ;
F_3 ( V_33 + V_26 -> V_30 ,
( T_1 ) V_25 ) ;
F_3 ( V_34 + V_26 -> V_30 ,
F_12 ( V_25 ) ) ;
F_3 ( V_35 + V_26 -> V_30 ,
( T_1 ) V_25 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_36 ; V_18 ++ ) {
if ( F_4 ( V_29 + V_26 -> V_30 ) &
V_37 )
break;
F_13 ( 1 ) ;
}
F_14 ( L_1 ) ;
V_28 &= ~ V_31 ;
F_3 ( V_29 + V_26 -> V_30 , V_28 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_11 ,
T_1 * V_38 , T_1 * V_39 )
{
if ( ( V_11 < 0 ) || ( V_11 >= V_2 -> V_19 . V_20 ) )
return - V_40 ;
* V_38 = F_4 ( V_41 + V_13 [ V_11 ] ) ;
* V_39 = F_4 ( V_17 + V_13 [ V_11 ] ) ;
return 0 ;
}
static bool F_16 ( struct V_1 * V_2 ,
enum V_42 V_43 )
{
bool V_44 = false ;
switch ( V_43 ) {
case V_45 :
if ( F_4 ( V_46 ) & V_47 )
V_44 = true ;
break;
case V_48 :
if ( F_4 ( V_49 ) & V_50 )
V_44 = true ;
break;
case V_51 :
if ( F_4 ( V_52 ) & V_53 )
V_44 = true ;
break;
case V_54 :
if ( F_4 ( V_55 ) & V_56 )
V_44 = true ;
break;
case V_57 :
if ( F_4 ( V_58 ) & V_59 )
V_44 = true ;
break;
case V_60 :
if ( F_4 ( V_61 ) & V_62 )
V_44 = true ;
break;
default:
break;
}
return V_44 ;
}
static void F_17 ( struct V_1 * V_2 ,
enum V_42 V_43 )
{
T_1 V_28 ;
bool V_44 = F_16 ( V_2 , V_43 ) ;
switch ( V_43 ) {
case V_45 :
V_28 = F_4 ( V_63 ) ;
if ( V_44 )
V_28 &= ~ V_64 ;
else
V_28 |= V_64 ;
F_3 ( V_63 , V_28 ) ;
break;
case V_48 :
V_28 = F_4 ( V_65 ) ;
if ( V_44 )
V_28 &= ~ V_66 ;
else
V_28 |= V_66 ;
F_3 ( V_65 , V_28 ) ;
break;
case V_51 :
V_28 = F_4 ( V_67 ) ;
if ( V_44 )
V_28 &= ~ V_68 ;
else
V_28 |= V_68 ;
F_3 ( V_67 , V_28 ) ;
break;
case V_54 :
V_28 = F_4 ( V_69 ) ;
if ( V_44 )
V_28 &= ~ V_70 ;
else
V_28 |= V_70 ;
F_3 ( V_69 , V_28 ) ;
break;
case V_57 :
V_28 = F_4 ( V_71 ) ;
if ( V_44 )
V_28 &= ~ V_72 ;
else
V_28 |= V_72 ;
F_3 ( V_71 , V_28 ) ;
break;
case V_60 :
V_28 = F_4 ( V_73 ) ;
if ( V_44 )
V_28 &= ~ V_74 ;
else
V_28 |= V_74 ;
F_3 ( V_73 , V_28 ) ;
break;
default:
break;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
struct V_78 * V_79 ;
T_1 V_28 = ( 0x9c4 << V_80 ) |
( 0xfa << V_81 ) |
V_82 ;
F_19 (connector, &dev->mode_config.connector_list, head) {
struct V_83 * V_83 = F_20 ( V_79 ) ;
if ( V_79 -> V_84 == V_85 ||
V_79 -> V_84 == V_86 ) {
continue;
}
switch ( V_83 -> V_43 . V_43 ) {
case V_45 :
F_3 ( V_87 , V_28 ) ;
break;
case V_48 :
F_3 ( V_88 , V_28 ) ;
break;
case V_51 :
F_3 ( V_89 , V_28 ) ;
break;
case V_54 :
F_3 ( V_90 , V_28 ) ;
break;
case V_57 :
F_3 ( V_91 , V_28 ) ;
break;
case V_60 :
F_3 ( V_92 , V_28 ) ;
break;
default:
break;
}
F_17 ( V_2 , V_83 -> V_43 . V_43 ) ;
F_21 ( V_2 , & V_2 -> V_93 , V_83 -> V_43 . V_43 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
struct V_78 * V_79 ;
F_19 (connector, &dev->mode_config.connector_list, head) {
struct V_83 * V_83 = F_20 ( V_79 ) ;
switch ( V_83 -> V_43 . V_43 ) {
case V_45 :
F_3 ( V_87 , 0 ) ;
break;
case V_48 :
F_3 ( V_88 , 0 ) ;
break;
case V_51 :
F_3 ( V_89 , 0 ) ;
break;
case V_54 :
F_3 ( V_90 , 0 ) ;
break;
case V_57 :
F_3 ( V_91 , 0 ) ;
break;
case V_60 :
F_3 ( V_92 , 0 ) ;
break;
default:
break;
}
F_23 ( V_2 , & V_2 -> V_93 , V_83 -> V_43 . V_43 ) ;
}
}
static T_1 F_24 ( struct V_1 * V_2 )
{
return V_94 ;
}
static bool F_25 ( struct V_1 * V_2 )
{
T_1 V_95 = 0 ;
T_1 V_96 [ 6 ] ;
T_1 V_18 , V_97 , V_28 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( F_4 ( V_21 + V_13 [ V_18 ] ) & V_22 ) {
V_96 [ V_18 ] = F_4 ( V_98 + V_13 [ V_18 ] ) ;
V_95 |= ( 1 << V_18 ) ;
}
}
for ( V_97 = 0 ; V_97 < 10 ; V_97 ++ ) {
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_95 & ( 1 << V_18 ) ) {
V_28 = F_4 ( V_98 + V_13 [ V_18 ] ) ;
if ( V_28 != V_96 [ V_18 ] )
V_95 &= ~ ( 1 << V_18 ) ;
}
}
if ( V_95 == 0 )
return false ;
F_13 ( 100 ) ;
}
return true ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_99 * V_100 )
{
T_1 V_101 , V_28 ;
int V_18 ;
V_100 -> V_102 = F_4 ( V_103 ) ;
V_100 -> V_104 = F_4 ( V_105 ) ;
V_28 = F_4 ( V_103 ) ;
V_28 = F_27 ( V_28 , V_106 , V_107 , 0 ) ;
F_3 ( V_103 , V_28 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_101 = F_28 ( F_4 ( V_21 + V_13 [ V_18 ] ) ,
V_108 , V_109 ) ;
if ( V_101 ) {
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
F_3 ( V_110 + V_13 [ V_18 ] , 1 ) ;
V_28 = F_4 ( V_21 + V_13 [ V_18 ] ) ;
V_28 = F_27 ( V_28 , V_108 , V_109 , 0 ) ;
F_3 ( V_21 + V_13 [ V_18 ] , V_28 ) ;
F_3 ( V_110 + V_13 [ V_18 ] , 0 ) ;
V_100 -> V_101 [ V_18 ] = false ;
#endif
} else {
V_100 -> V_101 [ V_18 ] = false ;
}
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_99 * V_100 )
{
T_1 V_28 , V_111 ;
int V_18 , V_97 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
F_3 ( V_34 + V_13 [ V_18 ] ,
F_12 ( V_2 -> V_112 . V_113 ) ) ;
F_3 ( V_32 + V_13 [ V_18 ] ,
F_12 ( V_2 -> V_112 . V_113 ) ) ;
F_3 ( V_35 + V_13 [ V_18 ] ,
( T_1 ) V_2 -> V_112 . V_113 ) ;
F_3 ( V_33 + V_13 [ V_18 ] ,
( T_1 ) V_2 -> V_112 . V_113 ) ;
if ( V_100 -> V_101 [ V_18 ] ) {
V_28 = F_4 ( V_114 + V_13 [ V_18 ] ) ;
if ( F_28 ( V_28 , V_115 , V_115 ) != 3 ) {
V_28 = F_27 ( V_28 , V_115 , V_115 , 3 ) ;
F_3 ( V_114 + V_13 [ V_18 ] , V_28 ) ;
}
V_28 = F_4 ( V_29 + V_13 [ V_18 ] ) ;
if ( F_28 ( V_28 , V_116 , V_117 ) ) {
V_28 = F_27 ( V_28 , V_116 , V_117 , 0 ) ;
F_3 ( V_29 + V_13 [ V_18 ] , V_28 ) ;
}
V_28 = F_4 ( V_118 + V_13 [ V_18 ] ) ;
if ( F_28 ( V_28 , V_119 , V_119 ) ) {
V_28 = F_27 ( V_28 , V_119 , V_119 , 0 ) ;
F_3 ( V_118 + V_13 [ V_18 ] , V_28 ) ;
}
for ( V_97 = 0 ; V_97 < V_2 -> V_36 ; V_97 ++ ) {
V_28 = F_4 ( V_29 + V_13 [ V_18 ] ) ;
if ( F_28 ( V_28 , V_116 , V_120 ) == 0 )
break;
F_13 ( 1 ) ;
}
V_28 = F_4 ( V_121 + V_13 [ V_18 ] ) ;
V_28 = F_27 ( V_28 , V_122 , V_123 , 0 ) ;
F_3 ( V_110 + V_13 [ V_18 ] , 1 ) ;
F_3 ( V_121 + V_13 [ V_18 ] , V_28 ) ;
F_3 ( V_110 + V_13 [ V_18 ] , 0 ) ;
V_111 = F_30 ( V_2 , V_18 ) ;
for ( V_97 = 0 ; V_97 < V_2 -> V_36 ; V_97 ++ ) {
if ( F_30 ( V_2 , V_18 ) != V_111 )
break;
F_13 ( 1 ) ;
}
}
}
F_3 ( V_124 , F_12 ( V_2 -> V_112 . V_113 ) ) ;
F_3 ( V_125 , F_31 ( V_2 -> V_112 . V_113 ) ) ;
F_3 ( V_105 , V_100 -> V_104 ) ;
F_32 ( 1 ) ;
F_3 ( V_103 , V_100 -> V_102 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
bool V_126 )
{
T_1 V_28 ;
V_28 = F_4 ( V_105 ) ;
if ( V_126 )
V_28 = F_27 ( V_28 , V_127 , V_128 , 0 ) ;
else
V_28 = F_27 ( V_28 , V_127 , V_128 , 1 ) ;
F_3 ( V_105 , V_28 ) ;
V_28 = F_4 ( V_103 ) ;
if ( V_126 )
V_28 = F_27 ( V_28 , V_106 , V_107 , 1 ) ;
else
V_28 = F_27 ( V_28 , V_106 , V_107 , 0 ) ;
F_3 ( V_103 , V_28 ) ;
}
static void F_34 ( struct V_129 * V_130 )
{
struct V_75 * V_76 = V_130 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_26 * V_26 = F_36 ( V_130 -> V_11 ) ;
struct V_78 * V_79 = F_37 ( V_130 ) ;
int V_133 = 0 ;
T_1 V_28 = 0 ;
enum V_134 V_135 = V_136 ;
if ( V_79 ) {
struct V_83 * V_83 = F_20 ( V_79 ) ;
V_133 = F_38 ( V_79 ) ;
V_135 = V_83 -> V_135 ;
}
if ( V_132 -> V_137 & V_138 )
return;
if ( ( V_132 -> V_139 == V_140 ) ||
( V_132 -> V_139 == V_141 ) )
return;
if ( V_133 == 0 )
return;
switch ( V_133 ) {
case 6 :
if ( V_135 == V_142 )
V_28 |= ( V_143 |
V_144 |
V_145 |
( 0 << V_146 ) ) ;
else
V_28 |= ( V_147 |
( 0 << V_148 ) ) ;
break;
case 8 :
if ( V_135 == V_142 )
V_28 |= ( V_143 |
V_144 |
V_149 |
V_145 |
( 1 << V_146 ) ) ;
else
V_28 |= ( V_147 |
( 1 << V_148 ) ) ;
break;
case 10 :
if ( V_135 == V_142 )
V_28 |= ( V_143 |
V_144 |
V_149 |
V_145 |
( 2 << V_146 ) ) ;
else
V_28 |= ( V_147 |
( 2 << V_148 ) ) ;
break;
default:
break;
}
F_3 ( V_150 + V_26 -> V_30 , V_28 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_26 * V_26 ,
struct V_151 * V_152 )
{
T_1 V_28 , V_153 , V_18 ;
T_1 V_154 = V_26 -> V_24 * 0x8 ;
if ( V_26 -> V_155 . V_156 && V_152 ) {
if ( V_152 -> V_157 < 1920 ) {
V_28 = 1 ;
V_153 = 2 ;
} else if ( V_152 -> V_157 < 2560 ) {
V_28 = 2 ;
V_153 = 2 ;
} else if ( V_152 -> V_157 < 4096 ) {
V_28 = 0 ;
V_153 = ( V_2 -> V_5 & V_158 ) ? 2 : 4 ;
} else {
F_40 ( L_2 ) ;
V_28 = 0 ;
V_153 = ( V_2 -> V_5 & V_158 ) ? 2 : 4 ;
}
} else {
V_28 = 1 ;
V_153 = 0 ;
}
F_3 ( V_159 + V_26 -> V_30 ,
( V_28 << V_160 ) |
( 0x6B0 << V_161 ) ) ;
F_3 ( V_162 + V_154 ,
( V_153 << V_163 ) ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_36 ; V_18 ++ ) {
if ( F_4 ( V_162 + V_154 ) &
V_164 )
break;
F_13 ( 1 ) ;
}
if ( V_26 -> V_155 . V_156 && V_152 ) {
switch ( V_28 ) {
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
static T_1 F_41 ( struct V_1 * V_2 )
{
T_1 V_28 = F_4 ( V_165 ) ;
switch ( ( V_28 & V_166 ) >> V_167 ) {
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
static T_1 F_42 ( struct V_168 * V_169 )
{
T_3 V_170 ;
T_3 V_171 , V_172 , V_173 ;
T_3 V_174 ;
V_174 . V_175 = F_43 ( 1000 ) ;
V_171 . V_175 = F_43 ( V_169 -> V_171 ) ;
V_171 . V_175 = F_44 ( V_171 , V_174 ) ;
V_172 . V_175 = F_43 ( V_169 -> V_172 * 4 ) ;
V_174 . V_175 = F_43 ( 10 ) ;
V_170 . V_175 = F_43 ( 7 ) ;
V_170 . V_175 = F_44 ( V_170 , V_174 ) ;
V_173 . V_175 = F_45 ( V_172 , V_171 ) ;
V_173 . V_175 = F_45 ( V_173 , V_170 ) ;
return F_46 ( V_173 ) ;
}
static T_1 F_47 ( struct V_168 * V_169 )
{
T_3 V_176 ;
T_3 V_171 , V_172 , V_173 ;
T_3 V_174 ;
V_174 . V_175 = F_43 ( 1000 ) ;
V_171 . V_175 = F_43 ( V_169 -> V_171 ) ;
V_171 . V_175 = F_44 ( V_171 , V_174 ) ;
V_172 . V_175 = F_43 ( V_169 -> V_172 * 4 ) ;
V_174 . V_175 = F_43 ( 10 ) ;
V_176 . V_175 = F_43 ( 3 ) ;
V_176 . V_175 = F_44 ( V_176 , V_174 ) ;
V_173 . V_175 = F_45 ( V_172 , V_171 ) ;
V_173 . V_175 = F_45 ( V_173 , V_176 ) ;
return F_46 ( V_173 ) ;
}
static T_1 F_48 ( struct V_168 * V_169 )
{
T_3 V_177 ;
T_3 V_178 , V_173 ;
T_3 V_174 ;
V_174 . V_175 = F_43 ( 1000 ) ;
V_178 . V_175 = F_43 ( V_169 -> V_178 ) ;
V_178 . V_175 = F_44 ( V_178 , V_174 ) ;
V_174 . V_175 = F_43 ( 10 ) ;
V_177 . V_175 = F_43 ( 8 ) ;
V_177 . V_175 = F_44 ( V_177 , V_174 ) ;
V_174 . V_175 = F_43 ( 32 ) ;
V_173 . V_175 = F_45 ( V_174 , V_178 ) ;
V_173 . V_175 = F_45 ( V_173 , V_177 ) ;
return F_46 ( V_173 ) ;
}
static T_1 F_49 ( struct V_168 * V_169 )
{
T_3 V_179 ;
T_3 V_180 , V_173 ;
T_3 V_174 , V_181 ;
V_174 . V_175 = F_43 ( 1000 ) ;
V_180 . V_175 = F_43 ( V_169 -> V_180 ) ;
V_180 . V_175 = F_44 ( V_180 , V_174 ) ;
V_174 . V_175 = F_43 ( 32 ) ;
V_181 . V_175 = F_45 ( V_174 , V_180 ) ;
V_174 . V_175 = F_43 ( 10 ) ;
V_179 . V_175 = F_43 ( 8 ) ;
V_179 . V_175 = F_44 ( V_179 , V_174 ) ;
V_173 . V_175 = F_45 ( V_181 , V_179 ) ;
return F_46 ( V_173 ) ;
}
static T_1 F_50 ( struct V_168 * V_169 )
{
T_1 V_182 = F_42 ( V_169 ) ;
T_1 V_183 = F_48 ( V_169 ) ;
T_1 V_184 = F_49 ( V_169 ) ;
return F_51 ( V_182 , F_51 ( V_183 , V_184 ) ) ;
}
static T_1 F_52 ( struct V_168 * V_169 )
{
T_3 V_185 ;
T_3 V_186 ;
T_3 V_187 ;
T_3 V_173 ;
T_3 V_174 ;
V_174 . V_175 = F_43 ( 1000 ) ;
V_186 . V_175 = F_43 ( V_169 -> V_188 + V_169 -> V_189 ) ;
V_186 . V_175 = F_44 ( V_186 , V_174 ) ;
V_185 . V_175 = F_43 ( V_169 -> V_190 ) ;
V_187 . V_175 = F_43 ( V_169 -> V_187 ) ;
V_173 . V_175 = F_45 ( V_187 , V_185 ) ;
V_173 . V_175 = F_45 ( V_173 , V_169 -> V_191 ) ;
V_173 . V_175 = F_44 ( V_173 , V_186 ) ;
return F_46 ( V_173 ) ;
}
static T_1 F_53 ( struct V_168 * V_169 )
{
T_1 V_192 = 2000 ;
T_1 V_193 = F_50 ( V_169 ) ;
T_1 V_194 = ( 512 * 8 * 1000 ) / V_193 ;
T_1 V_195 = ( 128 * 4 * 1000 ) / V_193 ;
T_1 V_196 = 40000000 / V_169 -> V_180 ;
T_1 V_197 = ( ( V_169 -> V_198 + 1 ) * V_194 ) +
( V_169 -> V_198 * V_195 ) ;
T_1 V_199 = V_192 + V_197 + V_196 ;
T_1 V_200 , V_201 , V_202 ;
T_1 V_28 , V_203 = 12288 ;
T_3 V_174 , V_181 , V_204 ;
if ( V_169 -> V_198 == 0 )
return 0 ;
V_174 . V_175 = F_43 ( 2 ) ;
V_181 . V_175 = F_43 ( 1 ) ;
if ( ( V_169 -> V_191 . V_175 > V_174 . V_175 ) ||
( ( V_169 -> V_191 . V_175 > V_181 . V_175 ) && ( V_169 -> V_205 >= 3 ) ) ||
( V_169 -> V_205 >= 5 ) ||
( ( V_169 -> V_191 . V_175 >= V_174 . V_175 ) && V_169 -> V_206 ) )
V_200 = 4 ;
else
V_200 = 2 ;
V_174 . V_175 = F_43 ( V_193 ) ;
V_181 . V_175 = F_43 ( V_169 -> V_198 ) ;
V_174 . V_175 = F_44 ( V_174 , V_181 ) ;
V_181 . V_175 = F_43 ( V_192 + 512 ) ;
V_204 . V_175 = F_43 ( V_169 -> V_180 ) ;
V_181 . V_175 = F_44 ( V_181 , V_204 ) ;
V_204 . V_175 = F_43 ( V_203 ) ;
V_181 . V_175 = F_44 ( V_204 , V_181 ) ;
V_28 = F_51 ( F_46 ( V_174 ) , F_46 ( V_181 ) ) ;
V_181 . V_175 = F_43 ( 1000 ) ;
V_204 . V_175 = F_43 ( V_169 -> V_180 ) ;
V_181 . V_175 = F_44 ( V_204 , V_181 ) ;
V_204 . V_175 = F_43 ( V_169 -> V_190 ) ;
V_181 . V_175 = F_45 ( V_181 , V_204 ) ;
V_201 = F_51 ( V_28 , F_46 ( V_181 ) ) ;
V_174 . V_175 = F_43 ( V_200 * V_169 -> V_187 * V_169 -> V_190 ) ;
V_181 . V_175 = F_43 ( 1000 ) ;
V_204 . V_175 = F_43 ( V_201 ) ;
V_181 . V_175 = F_44 ( V_204 , V_181 ) ;
V_174 . V_175 = F_44 ( V_174 , V_181 ) ;
V_202 = F_46 ( V_174 ) ;
if ( V_202 < V_169 -> V_188 )
return V_199 ;
else
return V_199 + ( V_202 - V_169 -> V_188 ) ;
}
static bool F_54 ( struct V_168 * V_169 )
{
if ( F_52 ( V_169 ) <=
( F_47 ( V_169 ) / V_169 -> V_198 ) )
return true ;
else
return false ;
}
static bool F_55 ( struct V_168 * V_169 )
{
if ( F_52 ( V_169 ) <=
( F_50 ( V_169 ) / V_169 -> V_198 ) )
return true ;
else
return false ;
}
static bool F_56 ( struct V_168 * V_169 )
{
T_1 V_207 = V_169 -> V_208 / V_169 -> V_187 ;
T_1 V_186 = V_169 -> V_188 + V_169 -> V_189 ;
T_1 V_209 ;
T_1 V_210 ;
T_3 V_174 ;
V_174 . V_175 = F_43 ( 1 ) ;
if ( V_169 -> V_191 . V_175 > V_174 . V_175 )
V_209 = 1 ;
else {
if ( V_207 <= ( V_169 -> V_205 + 1 ) )
V_209 = 1 ;
else
V_209 = 2 ;
}
V_210 = ( V_209 * V_186 + V_169 -> V_189 ) ;
if ( F_53 ( V_169 ) <= V_210 )
return true ;
else
return false ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_26 * V_26 ,
T_1 V_208 , T_1 V_198 )
{
struct V_151 * V_152 = & V_26 -> V_155 . V_152 ;
struct V_168 V_211 , V_212 ;
T_1 V_213 ;
T_1 V_186 = 0 ;
T_1 V_214 = 0 , V_215 = 0 ;
T_1 V_28 , V_216 ;
if ( V_26 -> V_155 . V_156 && V_198 && V_152 ) {
V_213 = 1000000 / ( T_1 ) V_152 -> clock ;
V_186 = F_51 ( ( T_1 ) V_152 -> V_217 * V_213 , ( T_1 ) 65535 ) ;
if ( V_2 -> V_218 . V_219 ) {
V_212 . V_171 =
F_58 ( V_2 , false ) * 10 ;
V_212 . V_178 =
F_59 ( V_2 , false ) * 10 ;
} else {
V_212 . V_171 = V_2 -> V_218 . V_220 * 10 ;
V_212 . V_178 = V_2 -> V_218 . V_221 * 10 ;
}
V_212 . V_180 = V_152 -> clock ;
V_212 . V_187 = V_152 -> V_157 ;
V_212 . V_188 = V_152 -> V_157 * V_213 ;
V_212 . V_189 = V_186 - V_212 . V_188 ;
V_212 . V_206 = false ;
if ( V_152 -> V_5 & V_222 )
V_212 . V_206 = true ;
V_212 . V_191 = V_26 -> V_191 ;
V_212 . V_205 = 1 ;
if ( V_26 -> V_223 != V_224 )
V_212 . V_205 = 2 ;
V_212 . V_190 = 4 ;
V_212 . V_208 = V_208 ;
V_212 . V_172 = F_41 ( V_2 ) ;
V_212 . V_198 = V_198 ;
V_214 = F_51 ( F_53 ( & V_212 ) , ( T_1 ) 65535 ) ;
if ( ! F_54 ( & V_212 ) ||
! F_55 ( & V_212 ) ||
! F_56 ( & V_212 ) ||
( V_2 -> V_19 . V_225 == 2 ) ) {
F_40 ( L_3 ) ;
}
if ( V_2 -> V_218 . V_219 ) {
V_211 . V_171 =
F_58 ( V_2 , true ) * 10 ;
V_211 . V_178 =
F_59 ( V_2 , true ) * 10 ;
} else {
V_211 . V_171 = V_2 -> V_218 . V_220 * 10 ;
V_211 . V_178 = V_2 -> V_218 . V_221 * 10 ;
}
V_211 . V_180 = V_152 -> clock ;
V_211 . V_187 = V_152 -> V_157 ;
V_211 . V_188 = V_152 -> V_157 * V_213 ;
V_211 . V_189 = V_186 - V_211 . V_188 ;
V_211 . V_206 = false ;
if ( V_152 -> V_5 & V_222 )
V_211 . V_206 = true ;
V_211 . V_191 = V_26 -> V_191 ;
V_211 . V_205 = 1 ;
if ( V_26 -> V_223 != V_224 )
V_211 . V_205 = 2 ;
V_211 . V_190 = 4 ;
V_211 . V_208 = V_208 ;
V_211 . V_172 = F_41 ( V_2 ) ;
V_211 . V_198 = V_198 ;
V_215 = F_51 ( F_53 ( & V_211 ) , ( T_1 ) 65535 ) ;
if ( ! F_54 ( & V_211 ) ||
! F_55 ( & V_211 ) ||
! F_56 ( & V_211 ) ||
( V_2 -> V_19 . V_225 == 2 ) ) {
F_40 ( L_3 ) ;
}
}
V_216 = F_4 ( V_226 + V_26 -> V_30 ) ;
V_28 = V_216 ;
V_28 &= ~ ( 3 << V_227 ) ;
V_28 |= ( 1 << V_227 ) ;
F_3 ( V_226 + V_26 -> V_30 , V_28 ) ;
F_3 ( V_228 + V_26 -> V_30 ,
( ( V_214 << V_229 ) |
( V_186 << V_230 ) ) ) ;
V_28 = F_4 ( V_226 + V_26 -> V_30 ) ;
V_28 &= ~ ( 3 << V_227 ) ;
V_28 |= ( 2 << V_227 ) ;
F_3 ( V_226 + V_26 -> V_30 , V_28 ) ;
F_3 ( V_228 + V_26 -> V_30 ,
( ( V_215 << V_229 ) |
( V_186 << V_230 ) ) ) ;
F_3 ( V_226 + V_26 -> V_30 , V_216 ) ;
V_26 -> V_186 = V_186 ;
V_26 -> V_212 = V_214 ;
V_26 -> V_211 = V_215 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = NULL ;
T_1 V_198 = 0 , V_208 ;
int V_18 ;
F_61 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_27 [ V_18 ] -> V_155 . V_156 )
V_198 ++ ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_152 = & V_2 -> V_19 . V_27 [ V_18 ] -> V_155 . V_152 ;
V_208 = F_39 ( V_2 , V_2 -> V_19 . V_27 [ V_18 ] , V_152 ) ;
F_57 ( V_2 , V_2 -> V_19 . V_27 [ V_18 ] ,
V_208 , V_198 ) ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
int V_18 ;
T_1 V_231 , V_28 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
V_231 = V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_231 ;
V_28 = F_63 ( V_231 ,
V_235 ) ;
if ( ( ( V_28 &
V_236 ) >>
V_237 ) == 1 )
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_44 = false ;
else
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_44 = true ;
}
}
static struct V_238 * F_64 ( struct V_1 * V_2 )
{
int V_18 ;
F_62 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_44 )
return & V_2 -> V_19 . V_232 . V_234 [ V_18 ] ;
}
F_65 ( L_4 ) ;
return NULL ;
}
static void F_66 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
T_1 V_231 ;
if ( ! V_240 || ! V_240 -> V_242 || ! V_240 -> V_242 -> V_234 )
return;
V_231 = V_240 -> V_242 -> V_231 ;
F_3 ( V_243 + V_231 ,
( V_240 -> V_242 -> V_234 -> V_244 << V_245 ) ) ;
}
static void F_67 ( struct V_129 * V_130 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = V_130 -> V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
struct V_78 * V_79 ;
struct V_83 * V_83 = NULL ;
T_1 V_28 = 0 , V_231 ;
if ( ! V_240 || ! V_240 -> V_242 || ! V_240 -> V_242 -> V_234 )
return;
V_231 = V_240 -> V_242 -> V_234 -> V_231 ;
F_19 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_79 -> V_130 == V_130 ) {
V_83 = F_20 ( V_79 ) ;
break;
}
}
if ( ! V_83 ) {
F_65 ( L_5 ) ;
return;
}
if ( V_152 -> V_5 & V_222 ) {
if ( V_79 -> V_246 [ 1 ] )
V_28 =
( V_79 -> V_247 [ 1 ] <<
V_248 ) |
( V_79 -> V_249 [ 1 ] <<
V_250 ) ;
else
V_28 =
( 0 <<
V_248 ) |
( 0 <<
V_250 ) ;
} else {
if ( V_79 -> V_246 [ 0 ] )
V_28 =
( V_79 -> V_247 [ 0 ] <<
V_248 ) |
( V_79 -> V_249 [ 0 ] <<
V_250 ) ;
else
V_28 =
( 0 <<
V_248 ) |
( 0 <<
V_250 ) ;
}
F_68 ( V_231 , V_251 , V_28 ) ;
}
static void F_69 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
struct V_78 * V_79 ;
struct V_83 * V_83 = NULL ;
T_1 V_231 , V_28 ;
T_4 * V_252 = NULL ;
int V_253 ;
if ( ! V_240 || ! V_240 -> V_242 || ! V_240 -> V_242 -> V_234 )
return;
V_231 = V_240 -> V_242 -> V_234 -> V_231 ;
F_19 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_79 -> V_130 == V_130 ) {
V_83 = F_20 ( V_79 ) ;
break;
}
}
if ( ! V_83 ) {
F_65 ( L_5 ) ;
return;
}
V_253 = F_70 ( F_71 ( V_79 ) , & V_252 ) ;
if ( V_253 < 0 ) {
F_65 ( L_6 , V_253 ) ;
V_253 = 0 ;
}
V_28 = F_63 ( V_231 , V_254 ) ;
V_28 &= ~ ( V_255 |
V_256 ) ;
V_28 |= V_257 ;
if ( V_253 )
V_28 |= ( V_252 [ 0 ] << V_258 ) ;
else
V_28 |= ( 5 << V_258 ) ;
F_68 ( V_231 , V_254 , V_28 ) ;
F_72 ( V_252 ) ;
}
static void F_73 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
T_1 V_231 ;
struct V_78 * V_79 ;
struct V_83 * V_83 = NULL ;
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
F_19 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_79 -> V_130 == V_130 ) {
V_83 = F_20 ( V_79 ) ;
break;
}
}
if ( ! V_83 ) {
F_65 ( L_5 ) ;
return;
}
V_253 = F_74 ( F_71 ( V_79 ) , & V_260 ) ;
if ( V_253 <= 0 ) {
F_65 ( L_7 , V_253 ) ;
return;
}
F_75 ( ! V_260 ) ;
for ( V_18 = 0 ; V_18 < F_76 ( V_261 ) ; V_18 ++ ) {
T_1 V_286 = 0 ;
T_4 V_287 = 0 ;
int V_288 = - 1 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_253 ; V_97 ++ ) {
struct V_259 * V_289 = & V_260 [ V_97 ] ;
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
F_68 ( V_231 , V_261 [ V_18 ] [ 0 ] , V_286 ) ;
}
F_72 ( V_260 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_238 * V_234 ,
bool V_298 )
{
if ( ! V_234 )
return;
F_68 ( V_234 -> V_231 , V_299 ,
V_298 ? V_300 : 0 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_18 ;
if ( ! V_301 )
return 0 ;
V_2 -> V_19 . V_232 . V_156 = true ;
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
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_44 = false ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_231 = V_312 [ V_18 ] ;
V_2 -> V_19 . V_232 . V_234 [ V_18 ] . V_244 = V_18 ;
F_77 ( V_2 , & V_2 -> V_19 . V_232 . V_234 [ V_18 ] , false ) ;
}
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
int V_18 ;
if ( ! V_2 -> V_19 . V_232 . V_156 )
return;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ )
F_77 ( V_2 , & V_2 -> V_19 . V_232 . V_234 [ V_18 ] , false ) ;
V_2 -> V_19 . V_232 . V_156 = false ;
}
static void F_80 ( struct V_129 * V_130 , T_6 clock )
{
struct V_75 * V_76 = V_130 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_313 V_314 = V_313 ( clock ) ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
T_6 V_231 = V_240 -> V_242 -> V_231 ;
F_3 ( V_315 + V_231 , ( V_314 . V_316 << V_317 ) ) ;
F_3 ( V_318 + V_231 , V_314 . V_319 ) ;
F_3 ( V_320 + V_231 , ( V_314 . V_321 << V_317 ) ) ;
F_3 ( V_322 + V_231 , V_314 . V_323 ) ;
F_3 ( V_324 + V_231 , ( V_314 . V_325 << V_326 ) ) ;
F_3 ( V_327 + V_231 , V_314 . V_328 ) ;
}
static void F_81 ( struct V_129 * V_130 ,
void * V_329 , T_7 V_330 )
{
struct V_75 * V_76 = V_130 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
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
static void F_82 ( struct V_129 * V_130 , T_1 clock )
{
struct V_75 * V_76 = V_130 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
struct V_26 * V_26 = F_36 ( V_130 -> V_11 ) ;
T_1 V_337 = 24 * 1000 ;
T_1 V_338 = clock ;
if ( ! V_240 || ! V_240 -> V_242 )
return;
F_3 ( V_339 , ( V_26 -> V_24 << V_340 ) ) ;
F_3 ( V_341 , V_337 ) ;
F_3 ( V_342 , V_338 ) ;
}
static void F_83 ( struct V_129 * V_130 ,
struct V_151 * V_152 )
{
struct V_75 * V_76 = V_130 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
struct V_78 * V_79 = F_37 ( V_130 ) ;
T_4 V_329 [ V_343 + V_344 ] ;
struct V_345 V_331 ;
T_6 V_231 , V_346 ;
T_9 V_347 ;
int V_133 = 8 ;
if ( ! V_240 || ! V_240 -> V_242 )
return;
if ( ! V_240 -> V_242 -> V_156 )
return;
V_231 = V_240 -> V_242 -> V_231 ;
if ( V_130 -> V_11 ) {
struct V_26 * V_26 = F_36 ( V_130 -> V_11 ) ;
V_133 = V_26 -> V_133 ;
}
V_240 -> V_242 -> V_234 = F_64 ( V_2 ) ;
F_77 ( V_2 , V_240 -> V_242 -> V_234 , false ) ;
F_82 ( V_130 , V_152 -> clock ) ;
F_3 ( V_348 + V_231 ,
V_349 ) ;
F_3 ( V_350 + V_231 , 0x1000 ) ;
V_346 = F_4 ( V_351 + V_231 ) ;
V_346 &= ~ V_352 ;
V_346 &= ~ V_353 ;
switch ( V_133 ) {
case 0 :
case 6 :
case 8 :
case 16 :
default:
F_14 ( L_8 ,
V_79 -> V_354 , V_133 ) ;
break;
case 10 :
V_346 |= V_352 ;
V_346 |= 1 << V_355 ;
F_14 ( L_9 ,
V_79 -> V_354 ) ;
break;
case 12 :
V_346 |= V_352 ;
V_346 |= 2 << V_355 ;
F_14 ( L_10 ,
V_79 -> V_354 ) ;
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
if ( V_133 > 8 )
F_3 ( V_371 + V_231 ,
V_372 ) ;
else
F_3 ( V_371 + V_231 ,
V_373 |
V_372 ) ;
F_80 ( V_130 , V_152 -> clock ) ;
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
F_69 ( V_130 ) ;
F_3 ( V_385 + V_231 ,
( 0xff << V_386 ) ) ;
F_66 ( V_130 ) ;
F_73 ( V_130 ) ;
F_67 ( V_130 , V_152 ) ;
V_347 = F_84 ( & V_331 , V_152 ) ;
if ( V_347 < 0 ) {
F_65 ( L_11 , V_347 ) ;
return;
}
V_347 = F_85 ( & V_331 , V_329 , sizeof( V_329 ) ) ;
if ( V_347 < 0 ) {
F_65 ( L_12 , V_347 ) ;
return;
}
F_81 ( V_130 , V_329 , sizeof( V_329 ) ) ;
F_86 ( V_358 + V_231 ,
V_387 |
V_387 ) ;
F_87 ( V_363 + V_231 ,
( 2 << V_388 ) ,
~ V_389 ) ;
F_86 ( V_369 + V_231 ,
V_390 ) ;
F_3 ( V_391 + V_231 , 0x00FFFFFF ) ;
F_3 ( V_392 + V_231 , 0x007FFFFF ) ;
F_3 ( V_393 + V_231 , 0x00000001 ) ;
F_3 ( V_394 + V_231 , 0x00000001 ) ;
F_77 ( V_2 , V_240 -> V_242 -> V_234 , true ) ;
}
static void F_88 ( struct V_129 * V_130 , bool V_298 )
{
struct V_75 * V_76 = V_130 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
if ( ! V_240 || ! V_240 -> V_242 )
return;
if ( V_298 && V_240 -> V_242 -> V_156 )
return;
if ( ! V_298 && ! V_240 -> V_242 -> V_156 )
return;
if ( ! V_298 && V_240 -> V_242 -> V_234 ) {
F_77 ( V_2 , V_240 -> V_242 -> V_234 , false ) ;
V_240 -> V_242 -> V_234 = NULL ;
}
V_240 -> V_242 -> V_156 = V_298 ;
F_14 ( L_13 ,
V_298 ? L_14 : L_15 , V_240 -> V_242 -> V_231 , V_132 -> V_139 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_395 ; V_18 ++ )
V_2 -> V_19 . V_242 [ V_18 ] = NULL ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_395 ; V_18 ++ ) {
V_2 -> V_19 . V_242 [ V_18 ] = F_90 ( sizeof( struct V_396 ) , V_397 ) ;
if ( V_2 -> V_19 . V_242 [ V_18 ] ) {
V_2 -> V_19 . V_242 [ V_18 ] -> V_231 = V_398 [ V_18 ] ;
V_2 -> V_19 . V_242 [ V_18 ] -> V_244 = V_18 ;
}
}
}
static void F_91 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_395 ; V_18 ++ ) {
F_72 ( V_2 -> V_19 . V_242 [ V_18 ] ) ;
V_2 -> V_19 . V_242 [ V_18 ] = NULL ;
}
}
static void F_92 ( struct V_399 * V_11 , bool V_298 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
T_1 V_400 ;
V_400 = F_4 ( V_401 [ V_26 -> V_24 ] ) & ~ 1 ;
if ( V_298 )
F_3 ( V_401 [ V_26 -> V_24 ] , V_400 | 1 ) ;
else
F_3 ( V_401 [ V_26 -> V_24 ] , V_400 ) ;
}
static void F_93 ( struct V_399 * V_11 , bool V_298 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
if ( V_298 )
F_3 ( V_402 + V_26 -> V_30 , 1 ) ;
else
F_3 ( V_402 + V_26 -> V_30 , 0 ) ;
}
static int F_94 ( struct V_399 * V_11 ,
struct V_403 * V_404 ,
int V_405 , int V_406 , int V_407 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_408 * V_409 ;
struct V_403 * V_410 ;
struct V_411 * V_412 ;
struct V_413 * V_414 ;
T_10 V_415 , V_416 ;
T_6 V_417 , V_418 ;
T_1 V_419 = ( V_420 << V_421 ) ;
T_1 V_422 ;
T_1 V_28 , V_423 , V_424 ;
int V_6 ;
bool V_425 = false ;
if ( ! V_407 && ! V_11 -> V_426 -> V_404 ) {
F_40 ( L_16 ) ;
return 0 ;
}
if ( V_407 ) {
V_409 = F_95 ( V_404 ) ;
V_410 = V_404 ;
}
else {
V_409 = F_95 ( V_11 -> V_426 -> V_404 ) ;
V_410 = V_11 -> V_426 -> V_404 ;
}
V_412 = V_409 -> V_412 ;
V_414 = F_96 ( V_412 ) ;
V_6 = F_97 ( V_414 , false ) ;
if ( F_98 ( V_6 != 0 ) )
return V_6 ;
if ( V_407 )
V_415 = F_99 ( V_414 ) ;
else {
V_6 = F_100 ( V_414 , V_427 , & V_415 ) ;
if ( F_98 ( V_6 != 0 ) ) {
F_101 ( V_414 ) ;
return - V_40 ;
}
}
F_102 ( V_414 , & V_416 ) ;
F_101 ( V_414 ) ;
V_422 = F_103 ( V_416 , V_428 ) ;
switch ( V_410 -> V_429 ) {
case V_430 :
V_417 = ( ( V_431 << V_432 ) |
( V_433 << V_434 ) ) ;
break;
case V_435 :
case V_436 :
V_417 = ( ( V_437 << V_432 ) |
( V_438 << V_434 ) ) ;
#ifdef F_104
V_419 = ( V_439 << V_421 ) ;
#endif
break;
case V_440 :
case V_441 :
V_417 = ( ( V_437 << V_432 ) |
( V_438 << V_434 ) ) ;
#ifdef F_104
V_419 = ( V_439 << V_421 ) ;
#endif
break;
case V_442 :
case V_443 :
V_417 = ( ( V_437 << V_432 ) |
( V_444 << V_434 ) ) ;
#ifdef F_104
V_419 = ( V_439 << V_421 ) ;
#endif
break;
case V_445 :
V_417 = ( ( V_437 << V_432 ) |
( V_446 << V_434 ) ) ;
#ifdef F_104
V_419 = ( V_439 << V_421 ) ;
#endif
break;
case V_447 :
case V_448 :
V_417 = ( ( V_449 << V_432 ) |
( V_450 << V_434 ) ) ;
#ifdef F_104
V_419 = ( V_451 << V_421 ) ;
#endif
break;
case V_452 :
case V_453 :
V_417 = ( ( V_449 << V_432 ) |
( V_454 << V_434 ) ) ;
#ifdef F_104
V_419 = ( V_451 << V_421 ) ;
#endif
V_425 = true ;
break;
case V_455 :
case V_456 :
V_417 = ( ( V_449 << V_432 ) |
( V_457 << V_434 ) ) ;
#ifdef F_104
V_419 = ( V_451 << V_421 ) ;
#endif
V_425 = true ;
break;
default:
F_65 ( L_17 ,
F_105 ( V_410 -> V_429 ) ) ;
return - V_40 ;
}
if ( F_103 ( V_416 , V_458 ) == V_459 ) {
unsigned V_460 , V_461 , V_462 , V_463 , V_464 ;
V_460 = F_103 ( V_416 , V_465 ) ;
V_461 = F_103 ( V_416 , V_466 ) ;
V_462 = F_103 ( V_416 , V_467 ) ;
V_463 = F_103 ( V_416 , V_468 ) ;
V_464 = F_103 ( V_416 , V_469 ) ;
V_417 |= ( V_464 << V_470 ) ;
V_417 |= ( V_471 << V_472 ) ;
V_417 |= ( V_463 << V_473 ) ;
V_417 |= ( V_460 << V_474 ) ;
V_417 |= ( V_461 << V_475 ) ;
V_417 |= ( V_462 << V_476 ) ;
V_417 |= ( V_477 << V_478 ) ;
} else if ( F_103 ( V_416 , V_458 ) == V_479 ) {
V_417 |= ( V_480 << V_472 ) ;
}
V_417 |= ( V_422 << V_481 ) ;
F_92 ( V_11 , false ) ;
F_3 ( V_34 + V_26 -> V_30 ,
F_12 ( V_415 ) ) ;
F_3 ( V_32 + V_26 -> V_30 ,
F_12 ( V_415 ) ) ;
F_3 ( V_35 + V_26 -> V_30 ,
( T_1 ) V_415 & V_482 ) ;
F_3 ( V_33 + V_26 -> V_30 ,
( T_1 ) V_415 & V_483 ) ;
F_3 ( V_484 + V_26 -> V_30 , V_417 ) ;
F_3 ( V_485 + V_26 -> V_30 , V_419 ) ;
F_87 ( V_486 + V_26 -> V_30 ,
( V_425 ? V_487 : 0 ) ,
~ V_487 ) ;
if ( V_425 )
F_40 ( L_18 ) ;
F_3 ( V_488 + V_26 -> V_30 , 0 ) ;
F_3 ( V_489 + V_26 -> V_30 , 0 ) ;
F_3 ( V_490 + V_26 -> V_30 , 0 ) ;
F_3 ( V_491 + V_26 -> V_30 , 0 ) ;
F_3 ( V_492 + V_26 -> V_30 , V_410 -> V_493 ) ;
F_3 ( V_494 + V_26 -> V_30 , V_410 -> V_495 ) ;
V_418 = V_410 -> V_496 [ 0 ] / ( V_410 -> V_497 / 8 ) ;
F_3 ( V_498 + V_26 -> V_30 , V_418 ) ;
F_93 ( V_11 , true ) ;
F_3 ( V_499 + V_26 -> V_30 ,
V_410 -> V_495 ) ;
V_405 &= ~ 3 ;
V_406 &= ~ 1 ;
F_3 ( V_500 + V_26 -> V_30 ,
( V_405 << 16 ) | V_406 ) ;
V_423 = V_11 -> V_152 . V_501 ;
V_424 = ( V_11 -> V_152 . V_502 + 1 ) & ~ 1 ;
F_3 ( V_503 + V_26 -> V_30 ,
( V_423 << 16 ) | V_424 ) ;
V_28 = F_4 ( V_504 + V_26 -> V_30 ) ;
V_28 &= ~ V_505 ;
F_3 ( V_504 + V_26 -> V_30 , V_28 ) ;
F_3 ( V_114 + V_26 -> V_30 , 3 ) ;
if ( ! V_407 && V_404 && V_404 != V_11 -> V_426 -> V_404 ) {
V_409 = F_95 ( V_404 ) ;
V_414 = F_96 ( V_409 -> V_412 ) ;
V_6 = F_97 ( V_414 , false ) ;
if ( F_98 ( V_6 != 0 ) )
return V_6 ;
F_106 ( V_414 ) ;
F_101 ( V_414 ) ;
}
F_60 ( V_2 ) ;
return 0 ;
}
static void F_107 ( struct V_399 * V_11 ,
struct V_151 * V_152 )
{
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_26 * V_26 = F_36 ( V_11 ) ;
if ( V_152 -> V_5 & V_222 )
F_3 ( V_506 + V_26 -> V_30 ,
V_507 ) ;
else
F_3 ( V_506 + V_26 -> V_30 , 0 ) ;
}
static void F_108 ( struct V_399 * V_11 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
int V_18 ;
F_40 ( L_19 , V_26 -> V_24 ) ;
F_3 ( V_508 + V_26 -> V_30 ,
( ( V_509 << V_510 ) |
( V_509 << V_511 ) ) ) ;
F_3 ( V_512 + V_26 -> V_30 ,
V_513 ) ;
F_3 ( V_514 + V_26 -> V_30 ,
V_515 ) ;
F_3 ( V_516 + V_26 -> V_30 ,
( ( V_517 << V_518 ) |
( V_517 << V_519 ) ) ) ;
F_3 ( V_520 + V_26 -> V_30 , 0 ) ;
F_3 ( V_521 + V_26 -> V_30 , 0 ) ;
F_3 ( V_522 + V_26 -> V_30 , 0 ) ;
F_3 ( V_523 + V_26 -> V_30 , 0 ) ;
F_3 ( V_524 + V_26 -> V_30 , 0xffff ) ;
F_3 ( V_525 + V_26 -> V_30 , 0xffff ) ;
F_3 ( V_526 + V_26 -> V_30 , 0xffff ) ;
F_3 ( V_527 + V_26 -> V_30 , 0 ) ;
F_3 ( V_528 + V_26 -> V_30 , 0x00000007 ) ;
F_3 ( V_529 + V_26 -> V_30 , 0 ) ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
F_3 ( V_530 + V_26 -> V_30 ,
( V_26 -> V_531 [ V_18 ] << 20 ) |
( V_26 -> V_532 [ V_18 ] << 10 ) |
( V_26 -> V_533 [ V_18 ] << 0 ) ) ;
}
F_3 ( V_534 + V_26 -> V_30 ,
( ( V_535 << V_536 ) |
( V_535 << V_537 ) |
( V_535 << V_538 ) ) ) ;
F_3 ( V_539 + V_26 -> V_30 ,
( ( V_540 << V_541 ) |
( V_540 << V_542 ) ) ) ;
F_3 ( V_543 + V_26 -> V_30 ,
( ( V_544 << V_545 ) |
( V_544 << V_546 ) ) ) ;
F_3 ( V_547 + V_26 -> V_30 ,
( ( V_548 << V_549 ) |
( V_548 << V_550 ) ) ) ;
F_3 ( 0x1a50 + V_26 -> V_30 , 0 ) ;
F_3 ( V_551 + V_26 -> V_30 ,
V_552 ) ;
}
static int F_109 ( struct V_129 * V_130 )
{
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 = V_132 -> V_241 ;
switch ( V_132 -> V_139 ) {
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
F_65 ( L_20 , V_132 -> V_139 ) ;
return 0 ;
}
}
static T_1 F_110 ( struct V_399 * V_11 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
T_1 V_558 ;
int V_559 ;
if ( F_111 ( F_112 ( V_26 -> V_130 ) ) ) {
if ( V_2 -> clock . V_560 )
return V_561 ;
else {
V_559 = F_113 ( V_11 ) ;
if ( V_559 != V_561 )
return V_559 ;
}
} else {
V_559 = F_114 ( V_11 ) ;
if ( V_559 != V_561 )
return V_559 ;
}
if ( ( V_2 -> V_302 == V_304 ) ||
( V_2 -> V_302 == V_305 ) ) {
V_558 = F_115 ( V_11 ) ;
if ( ! ( V_558 & ( 1 << V_562 ) ) )
return V_562 ;
if ( ! ( V_558 & ( 1 << V_563 ) ) )
return V_563 ;
F_65 ( L_21 ) ;
return V_561 ;
} else {
V_558 = F_115 ( V_11 ) ;
if ( ! ( V_558 & ( 1 << V_562 ) ) )
return V_562 ;
if ( ! ( V_558 & ( 1 << V_563 ) ) )
return V_563 ;
if ( ! ( V_558 & ( 1 << V_564 ) ) )
return V_564 ;
F_65 ( L_21 ) ;
return V_561 ;
}
return V_561 ;
}
static void F_116 ( struct V_399 * V_11 , bool V_565 )
{
struct V_1 * V_2 = V_11 -> V_76 -> V_131 ;
struct V_26 * V_26 = F_36 ( V_11 ) ;
T_6 V_566 ;
V_566 = F_4 ( V_567 + V_26 -> V_30 ) ;
if ( V_565 )
V_566 |= V_568 ;
else
V_566 &= ~ V_568 ;
F_3 ( V_567 + V_26 -> V_30 , V_566 ) ;
}
static void F_117 ( struct V_399 * V_11 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_76 -> V_131 ;
F_118 ( V_569 + V_26 -> V_30 ,
( V_570 << V_571 ) |
( V_572 << V_573 ) ) ;
}
static void F_119 ( struct V_399 * V_11 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_76 -> V_131 ;
F_118 ( V_569 + V_26 -> V_30 ,
V_574 |
( V_570 << V_571 ) |
( V_572 << V_573 ) ) ;
}
static void F_120 ( struct V_399 * V_11 , struct V_411 * V_412 ,
T_10 V_575 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_76 -> V_131 ;
F_3 ( V_576 + V_26 -> V_30 ,
F_12 ( V_575 ) ) ;
F_3 ( V_577 + V_26 -> V_30 ,
V_575 & 0xffffffff ) ;
}
static int F_121 ( struct V_399 * V_11 ,
int V_405 , int V_406 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_76 -> V_131 ;
int V_578 = 0 , V_579 = 0 ;
V_405 += V_11 -> V_405 ;
V_406 += V_11 -> V_406 ;
F_14 ( L_22 , V_405 , V_406 , V_11 -> V_405 , V_11 -> V_406 ) ;
if ( V_405 < 0 ) {
V_578 = F_51 ( - V_405 , V_26 -> V_580 - 1 ) ;
V_405 = 0 ;
}
if ( V_406 < 0 ) {
V_579 = F_51 ( - V_406 , V_26 -> V_581 - 1 ) ;
V_406 = 0 ;
}
F_116 ( V_11 , true ) ;
F_3 ( V_582 + V_26 -> V_30 , ( V_405 << 16 ) | V_406 ) ;
F_3 ( V_583 + V_26 -> V_30 , ( V_578 << 16 ) | V_579 ) ;
F_3 ( V_584 + V_26 -> V_30 ,
( ( V_26 -> V_585 - 1 ) << 16 ) | ( V_26 -> V_586 - 1 ) ) ;
F_116 ( V_11 , false ) ;
return 0 ;
}
static int F_122 ( struct V_399 * V_11 ,
struct V_587 * V_588 ,
T_6 V_589 ,
T_6 V_493 ,
T_6 V_495 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_411 * V_412 ;
struct V_413 * V_590 ;
T_10 V_575 ;
int V_591 ;
if ( ! V_589 ) {
F_117 ( V_11 ) ;
V_412 = NULL ;
goto V_592;
}
if ( ( V_493 > V_26 -> V_580 ) ||
( V_495 > V_26 -> V_581 ) ) {
F_65 ( L_23 , V_493 , V_495 ) ;
return - V_40 ;
}
V_412 = F_123 ( V_11 -> V_76 , V_588 , V_589 ) ;
if ( ! V_412 ) {
F_65 ( L_24 , V_589 , V_26 -> V_24 ) ;
return - V_593 ;
}
V_590 = F_96 ( V_412 ) ;
V_591 = F_97 ( V_590 , false ) ;
if ( F_98 ( V_591 != 0 ) )
goto V_594;
V_591 = F_124 ( V_590 , V_427 ,
0 , 0 , & V_575 ) ;
F_101 ( V_590 ) ;
if ( V_591 )
goto V_594;
V_26 -> V_585 = V_493 ;
V_26 -> V_586 = V_495 ;
F_116 ( V_11 , true ) ;
F_120 ( V_11 , V_412 , V_575 ) ;
F_119 ( V_11 ) ;
F_116 ( V_11 , false ) ;
V_592:
if ( V_26 -> V_595 ) {
V_590 = F_96 ( V_26 -> V_595 ) ;
V_591 = F_97 ( V_590 , false ) ;
if ( F_125 ( V_591 == 0 ) ) {
F_106 ( V_590 ) ;
F_101 ( V_590 ) ;
}
F_126 ( V_26 -> V_595 ) ;
}
V_26 -> V_595 = V_412 ;
return 0 ;
V_594:
F_126 ( V_412 ) ;
return V_591 ;
}
static void F_127 ( struct V_399 * V_11 , T_5 * V_596 , T_5 * V_597 ,
T_5 * V_598 , T_6 V_599 , T_6 V_330 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
int V_600 = ( V_599 + V_330 > 256 ) ? 256 : V_599 + V_330 , V_18 ;
for ( V_18 = V_599 ; V_18 < V_600 ; V_18 ++ ) {
V_26 -> V_531 [ V_18 ] = V_596 [ V_18 ] >> 6 ;
V_26 -> V_532 [ V_18 ] = V_597 [ V_18 ] >> 6 ;
V_26 -> V_533 [ V_18 ] = V_598 [ V_18 ] >> 6 ;
}
F_108 ( V_11 ) ;
}
static void F_128 ( struct V_399 * V_11 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
F_129 ( V_11 ) ;
F_130 ( V_26 -> V_601 ) ;
F_72 ( V_26 ) ;
}
static void F_131 ( struct V_399 * V_11 , int V_152 )
{
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_26 * V_26 = F_36 ( V_11 ) ;
unsigned type ;
switch ( V_152 ) {
case V_602 :
V_26 -> V_156 = true ;
F_132 ( V_11 , V_603 ) ;
F_92 ( V_11 , true ) ;
F_133 ( V_11 , V_604 ) ;
F_92 ( V_11 , false ) ;
type = F_134 ( V_2 , V_26 -> V_24 ) ;
F_135 ( V_2 , & V_2 -> V_605 , type ) ;
F_136 ( V_76 , V_26 -> V_24 ) ;
F_108 ( V_11 ) ;
break;
case V_606 :
case V_607 :
case V_608 :
F_137 ( V_76 , V_26 -> V_24 ) ;
if ( V_26 -> V_156 ) {
F_92 ( V_11 , true ) ;
F_133 ( V_11 , V_603 ) ;
F_92 ( V_11 , false ) ;
}
F_132 ( V_11 , V_604 ) ;
V_26 -> V_156 = false ;
break;
}
F_138 ( V_2 ) ;
}
static void F_139 ( struct V_399 * V_11 )
{
F_140 ( V_11 , V_604 ) ;
F_141 ( V_11 , V_603 ) ;
F_131 ( V_11 , V_608 ) ;
}
static void F_142 ( struct V_399 * V_11 )
{
F_131 ( V_11 , V_602 ) ;
F_141 ( V_11 , V_604 ) ;
}
static void F_143 ( struct V_399 * V_11 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
struct V_609 V_610 ;
int V_18 ;
F_131 ( V_11 , V_608 ) ;
if ( V_11 -> V_426 -> V_404 ) {
int V_6 ;
struct V_408 * V_409 ;
struct V_413 * V_414 ;
V_409 = F_95 ( V_11 -> V_426 -> V_404 ) ;
V_414 = F_96 ( V_409 -> V_412 ) ;
V_6 = F_97 ( V_414 , false ) ;
if ( F_98 ( V_6 ) )
F_65 ( L_25 ) ;
else {
F_106 ( V_414 ) ;
F_101 ( V_414 ) ;
}
}
F_93 ( V_11 , false ) ;
F_140 ( V_11 , V_603 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
if ( V_2 -> V_19 . V_27 [ V_18 ] &&
V_2 -> V_19 . V_27 [ V_18 ] -> V_156 &&
V_18 != V_26 -> V_24 &&
V_26 -> V_611 == V_2 -> V_19 . V_27 [ V_18 ] -> V_611 ) {
goto V_612;
}
}
switch ( V_26 -> V_611 ) {
case V_563 :
case V_562 :
F_144 ( V_11 , V_26 -> V_24 , V_26 -> V_611 ,
0 , 0 , V_604 , 0 , 0 , 0 , 0 , 0 , false , & V_610 ) ;
break;
case V_564 :
if ( ( V_2 -> V_302 == V_303 ) ||
( V_2 -> V_302 == V_306 ) ||
( V_2 -> V_302 == V_307 ) )
F_144 ( V_11 , V_26 -> V_24 , V_26 -> V_611 ,
0 , 0 , V_604 , 0 , 0 , 0 , 0 , 0 , false , & V_610 ) ;
break;
default:
break;
}
V_612:
V_26 -> V_611 = V_561 ;
V_26 -> V_613 = 0 ;
V_26 -> V_130 = NULL ;
V_26 -> V_79 = NULL ;
}
static int F_145 ( struct V_399 * V_11 ,
struct V_151 * V_152 ,
struct V_151 * V_614 ,
int V_405 , int V_406 , struct V_403 * V_615 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
if ( ! V_26 -> V_613 )
return - V_40 ;
F_146 ( V_11 , V_614 ) ;
F_147 ( V_11 , V_614 ) ;
F_94 ( V_11 , V_615 , V_405 , V_406 , 0 ) ;
F_148 ( V_11 , V_152 , V_614 ) ;
F_149 ( V_11 ) ;
V_26 -> V_616 = * V_614 ;
return 0 ;
}
static bool F_150 ( struct V_399 * V_11 ,
const struct V_151 * V_152 ,
struct V_151 * V_614 )
{
struct V_26 * V_26 = F_36 ( V_11 ) ;
struct V_75 * V_76 = V_11 -> V_76 ;
struct V_129 * V_130 ;
F_19 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_130 -> V_11 == V_11 ) {
V_26 -> V_130 = V_130 ;
V_26 -> V_79 = F_37 ( V_130 ) ;
break;
}
}
if ( ( V_26 -> V_130 == NULL ) || ( V_26 -> V_79 == NULL ) ) {
V_26 -> V_130 = NULL ;
V_26 -> V_79 = NULL ;
return false ;
}
if ( ! F_151 ( V_11 , V_152 , V_614 ) )
return false ;
if ( F_152 ( V_11 , V_614 ) )
return false ;
V_26 -> V_611 = F_110 ( V_11 ) ;
if ( ( V_26 -> V_611 == V_561 ) &&
! F_111 ( F_112 ( V_26 -> V_130 ) ) )
return false ;
return true ;
}
static int F_153 ( struct V_399 * V_11 , int V_405 , int V_406 ,
struct V_403 * V_615 )
{
return F_94 ( V_11 , V_615 , V_405 , V_406 , 0 ) ;
}
static int F_154 ( struct V_399 * V_11 ,
struct V_403 * V_404 ,
int V_405 , int V_406 , enum V_617 V_618 )
{
return F_94 ( V_11 , V_404 , V_405 , V_406 , 1 ) ;
}
static int F_155 ( struct V_1 * V_2 , int V_619 )
{
struct V_26 * V_26 ;
int V_18 ;
V_26 = F_90 ( sizeof( struct V_26 ) +
( V_620 * sizeof( struct V_78 * ) ) , V_397 ) ;
if ( V_26 == NULL )
return - V_621 ;
F_156 ( V_2 -> V_77 , & V_26 -> V_155 , & V_622 ) ;
F_157 ( & V_26 -> V_155 , 256 ) ;
V_26 -> V_24 = V_619 ;
V_26 -> V_601 = F_158 ( L_26 ) ;
V_2 -> V_19 . V_27 [ V_619 ] = V_26 ;
V_26 -> V_580 = V_623 ;
V_26 -> V_581 = V_624 ;
V_2 -> V_77 -> V_625 . V_585 = V_26 -> V_580 ;
V_2 -> V_77 -> V_625 . V_586 = V_26 -> V_581 ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
V_26 -> V_531 [ V_18 ] = V_18 << 2 ;
V_26 -> V_532 [ V_18 ] = V_18 << 2 ;
V_26 -> V_533 [ V_18 ] = V_18 << 2 ;
}
V_26 -> V_30 = V_13 [ V_26 -> V_24 ] ;
V_26 -> V_611 = V_561 ;
V_26 -> V_613 = 0 ;
V_26 -> V_130 = NULL ;
V_26 -> V_79 = NULL ;
F_159 ( & V_26 -> V_155 , & V_626 ) ;
return 0 ;
}
static int F_160 ( void * V_589 )
{
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
V_2 -> V_627 = & F_1 ;
V_2 -> V_628 = & F_6 ;
F_161 ( V_2 ) ;
F_162 ( V_2 ) ;
switch ( V_2 -> V_302 ) {
case V_306 :
case V_307 :
V_2 -> V_19 . V_20 = 6 ;
V_2 -> V_19 . V_629 = 6 ;
V_2 -> V_19 . V_395 = 6 ;
break;
case V_303 :
V_2 -> V_19 . V_20 = 4 ;
V_2 -> V_19 . V_629 = 6 ;
V_2 -> V_19 . V_395 = 7 ;
break;
case V_304 :
case V_305 :
V_2 -> V_19 . V_20 = 2 ;
V_2 -> V_19 . V_629 = 6 ;
V_2 -> V_19 . V_395 = 6 ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static int F_163 ( void * V_589 )
{
int V_6 , V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_6 = F_164 ( V_2 , V_18 + 1 , & V_2 -> V_605 ) ;
if ( V_6 )
return V_6 ;
}
for ( V_18 = 8 ; V_18 < 20 ; V_18 += 2 ) {
V_6 = F_164 ( V_2 , V_18 , & V_2 -> V_630 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_164 ( V_2 , 42 , & V_2 -> V_93 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_19 . V_631 = true ;
V_2 -> V_77 -> V_625 . V_632 = & V_633 ;
V_2 -> V_77 -> V_625 . V_634 = 16384 ;
V_2 -> V_77 -> V_625 . V_635 = 16384 ;
V_2 -> V_77 -> V_625 . V_636 = 24 ;
V_2 -> V_77 -> V_625 . V_637 = 1 ;
V_2 -> V_77 -> V_625 . V_638 = V_2 -> V_112 . V_639 ;
V_6 = F_165 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_77 -> V_625 . V_634 = 16384 ;
V_2 -> V_77 -> V_625 . V_635 = 16384 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_20 ; V_18 ++ ) {
V_6 = F_155 ( V_2 , V_18 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_166 ( V_2 ) )
F_167 ( V_2 -> V_77 ) ;
else
return - V_40 ;
F_89 ( V_2 ) ;
V_6 = F_78 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_168 ( V_2 -> V_77 ) ;
return V_6 ;
}
static int F_169 ( void * V_589 )
{
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
F_72 ( V_2 -> V_19 . V_640 ) ;
F_170 ( V_2 -> V_77 ) ;
F_79 ( V_2 ) ;
F_91 ( V_2 ) ;
F_171 ( V_2 -> V_77 ) ;
V_2 -> V_19 . V_631 = false ;
return 0 ;
}
static int F_172 ( void * V_589 )
{
int V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
F_173 ( V_2 ) ;
F_174 ( V_2 , V_2 -> clock . V_641 ) ;
F_18 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
F_77 ( V_2 , & V_2 -> V_19 . V_232 . V_234 [ V_18 ] , false ) ;
}
return 0 ;
}
static int F_175 ( void * V_589 )
{
int V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
F_22 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 . V_232 . V_233 ; V_18 ++ ) {
F_77 ( V_2 , & V_2 -> V_19 . V_232 . V_234 [ V_18 ] , false ) ;
}
return 0 ;
}
static int F_176 ( void * V_589 )
{
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
F_177 ( V_2 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_178 ( void * V_589 )
{
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
F_179 ( V_2 ) ;
F_173 ( V_2 ) ;
F_174 ( V_2 , V_2 -> clock . V_641 ) ;
if ( V_2 -> V_19 . V_642 ) {
T_4 V_643 = F_180 ( V_2 ,
V_2 -> V_19 . V_642 ) ;
F_181 ( V_2 , V_2 -> V_19 . V_642 ,
V_643 ) ;
}
F_18 ( V_2 ) ;
return 0 ;
}
static bool F_182 ( void * V_589 )
{
return true ;
}
static int F_183 ( void * V_589 )
{
return 0 ;
}
static void F_184 ( void * V_589 )
{
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
F_185 ( V_2 -> V_76 , L_27 ) ;
}
static int F_186 ( void * V_589 )
{
T_1 V_644 = 0 , V_28 ;
struct V_1 * V_2 = (struct V_1 * ) V_589 ;
if ( F_25 ( V_2 ) )
V_644 |= V_645 ;
if ( V_644 ) {
F_184 ( ( void * ) V_2 ) ;
V_28 = F_4 ( V_646 ) ;
V_28 |= V_644 ;
F_185 ( V_2 -> V_76 , L_28 , V_28 ) ;
F_3 ( V_646 , V_28 ) ;
V_28 = F_4 ( V_646 ) ;
F_13 ( 50 ) ;
V_28 &= ~ V_644 ;
F_3 ( V_646 , V_28 ) ;
V_28 = F_4 ( V_646 ) ;
F_13 ( 50 ) ;
F_184 ( ( void * ) V_2 ) ;
}
return 0 ;
}
static void F_187 ( struct V_1 * V_2 ,
int V_11 ,
enum V_647 V_618 )
{
T_1 V_648 , V_649 ;
if ( V_11 >= V_2 -> V_19 . V_20 ) {
F_14 ( L_29 , V_11 ) ;
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
F_14 ( L_29 , V_11 ) ;
return;
}
switch ( V_618 ) {
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
static void F_188 ( struct V_1 * V_2 ,
int V_11 ,
enum V_647 V_618 )
{
T_1 V_648 , V_649 ;
if ( V_11 >= V_2 -> V_19 . V_20 ) {
F_14 ( L_29 , V_11 ) ;
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
F_14 ( L_29 , V_11 ) ;
return;
}
switch ( V_618 ) {
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
static int F_189 ( struct V_1 * V_2 ,
struct V_661 * V_662 ,
unsigned type ,
enum V_647 V_618 )
{
T_1 V_663 , V_664 ;
switch ( type ) {
case V_45 :
V_663 = V_63 ;
break;
case V_48 :
V_663 = V_65 ;
break;
case V_51 :
V_663 = V_67 ;
break;
case V_54 :
V_663 = V_69 ;
break;
case V_57 :
V_663 = V_71 ;
break;
case V_60 :
V_663 = V_73 ;
break;
default:
F_14 ( L_30 , type ) ;
return 0 ;
}
switch ( V_618 ) {
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
static int F_190 ( struct V_1 * V_2 ,
struct V_661 * V_662 ,
unsigned type ,
enum V_647 V_618 )
{
switch ( type ) {
case V_666 :
F_187 ( V_2 , 0 , V_618 ) ;
break;
case V_667 :
F_187 ( V_2 , 1 , V_618 ) ;
break;
case V_668 :
F_187 ( V_2 , 2 , V_618 ) ;
break;
case V_669 :
F_187 ( V_2 , 3 , V_618 ) ;
break;
case V_670 :
F_187 ( V_2 , 4 , V_618 ) ;
break;
case V_671 :
F_187 ( V_2 , 5 , V_618 ) ;
break;
case V_672 :
F_188 ( V_2 , 0 , V_618 ) ;
break;
case V_673 :
F_188 ( V_2 , 1 , V_618 ) ;
break;
case V_674 :
F_188 ( V_2 , 2 , V_618 ) ;
break;
case V_675 :
F_188 ( V_2 , 3 , V_618 ) ;
break;
case V_676 :
F_188 ( V_2 , 4 , V_618 ) ;
break;
case V_677 :
F_188 ( V_2 , 5 , V_618 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_191 ( struct V_1 * V_2 ,
struct V_661 * V_678 ,
struct V_679 * V_680 )
{
unsigned V_11 = V_680 -> V_681 - 1 ;
T_6 V_682 = F_4 ( V_683 [ V_11 ] . V_4 ) ;
unsigned V_684 = F_134 ( V_2 , V_11 ) ;
switch ( V_680 -> V_685 ) {
case 0 :
if ( V_682 & V_683 [ V_11 ] . V_686 )
F_3 ( V_687 + V_13 [ V_11 ] , V_688 ) ;
else
F_14 ( L_31 ) ;
if ( F_192 ( V_2 , V_678 , V_684 ) ) {
F_193 ( V_2 -> V_77 , V_11 ) ;
}
F_14 ( L_32 , V_11 + 1 ) ;
break;
case 1 :
if ( V_682 & V_683 [ V_11 ] . V_689 )
F_3 ( V_690 + V_13 [ V_11 ] , V_691 ) ;
else
F_14 ( L_31 ) ;
F_14 ( L_33 , V_11 + 1 ) ;
break;
default:
F_14 ( L_34 , V_680 -> V_681 , V_680 -> V_685 ) ;
break;
}
return 0 ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_661 * V_662 ,
unsigned type ,
enum V_647 V_618 )
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
F_65 ( L_35 , type ) ;
return - V_40 ;
}
V_4 = F_4 ( V_698 + V_648 ) ;
if ( V_618 == V_656 )
F_3 ( V_698 + V_648 , V_4 & ~ V_699 ) ;
else
F_3 ( V_698 + V_648 , V_4 | V_699 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 ,
struct V_661 * V_678 ,
struct V_679 * V_680 )
{
int V_648 ;
unsigned long V_5 ;
unsigned V_24 ;
struct V_26 * V_26 ;
struct V_700 * V_701 ;
V_24 = ( V_680 -> V_681 - 8 ) >> 1 ;
V_26 = V_2 -> V_19 . V_27 [ V_24 ] ;
switch( V_24 ) {
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
F_65 ( L_35 , V_24 ) ;
return - V_40 ;
}
if ( F_4 ( V_702 + V_648 ) & V_703 )
F_3 ( V_702 + V_648 , V_704 ) ;
if ( V_26 == NULL )
return 0 ;
F_2 ( & V_2 -> V_77 -> V_705 , V_5 ) ;
V_701 = V_26 -> V_706 ;
if ( V_26 -> V_707 != V_708 ) {
F_196 ( L_36
L_37 ,
V_26 -> V_707 ,
V_708 ) ;
F_5 ( & V_2 -> V_77 -> V_705 , V_5 ) ;
return 0 ;
}
V_26 -> V_707 = V_709 ;
V_26 -> V_706 = NULL ;
if ( V_701 -> V_710 )
F_197 ( V_2 -> V_77 , V_24 , V_701 -> V_710 ) ;
F_5 ( & V_2 -> V_77 -> V_705 , V_5 ) ;
F_198 ( V_2 -> V_77 , V_26 -> V_24 ) ;
F_23 ( V_2 , & V_2 -> V_630 , V_24 ) ;
F_199 ( V_26 -> V_601 , & V_701 -> V_711 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_661 * V_678 ,
struct V_679 * V_680 )
{
T_6 V_682 , V_712 , V_713 , V_28 ;
unsigned V_43 ;
if ( V_680 -> V_685 >= V_2 -> V_19 . V_629 ) {
F_14 ( L_34 , V_680 -> V_681 , V_680 -> V_685 ) ;
return 0 ;
}
V_43 = V_680 -> V_685 ;
V_682 = F_4 ( V_683 [ V_43 ] . V_4 ) ;
V_712 = V_683 [ V_43 ] . V_43 ;
V_713 = V_714 [ V_43 ] ;
if ( V_682 & V_712 ) {
V_28 = F_4 ( V_713 ) ;
V_28 |= V_715 ;
F_3 ( V_713 , V_28 ) ;
F_201 ( & V_2 -> V_716 ) ;
F_14 ( L_38 , V_43 + 1 ) ;
}
return 0 ;
}
static int F_202 ( void * V_589 ,
enum V_717 V_618 )
{
return 0 ;
}
static int F_203 ( void * V_589 ,
enum V_718 V_618 )
{
return 0 ;
}
static void
F_204 ( struct V_129 * V_130 ,
struct V_151 * V_152 ,
struct V_151 * V_614 )
{
struct V_132 * V_132 = F_35 ( V_130 ) ;
V_132 -> V_719 = V_614 -> clock ;
F_205 ( V_130 , V_608 ) ;
F_107 ( V_130 -> V_11 , V_152 ) ;
if ( F_112 ( V_130 ) == V_720 ) {
F_88 ( V_130 , true ) ;
F_83 ( V_130 , V_614 ) ;
}
}
static void F_206 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_76 -> V_131 ;
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_78 * V_79 = F_37 ( V_130 ) ;
if ( ( V_132 -> V_721 &
( V_722 | V_138 ) ) ||
( F_207 ( V_130 ) !=
V_723 ) ) {
struct V_239 * V_240 = V_132 -> V_241 ;
if ( V_240 ) {
V_240 -> V_724 = F_109 ( V_130 ) ;
if ( V_132 -> V_721 & V_722 )
V_240 -> V_242 = V_2 -> V_19 . V_242 [ V_240 -> V_724 ] ;
}
}
F_208 ( V_2 , true ) ;
if ( V_79 ) {
struct V_83 * V_83 = F_20 ( V_79 ) ;
if ( V_83 -> V_725 . V_726 )
F_209 ( V_83 ) ;
if ( V_79 -> V_84 == V_85 )
F_210 ( V_79 ,
V_727 ) ;
}
F_211 ( V_130 ) ;
F_34 ( V_130 ) ;
}
static void F_212 ( struct V_129 * V_130 )
{
struct V_75 * V_76 = V_130 -> V_76 ;
struct V_1 * V_2 = V_76 -> V_131 ;
F_205 ( V_130 , V_602 ) ;
F_208 ( V_2 , false ) ;
}
static void F_213 ( struct V_129 * V_130 )
{
struct V_132 * V_132 = F_35 ( V_130 ) ;
struct V_239 * V_240 ;
F_205 ( V_130 , V_608 ) ;
if ( F_214 ( V_130 ) ) {
if ( F_112 ( V_130 ) == V_720 )
F_88 ( V_130 , false ) ;
V_240 = V_132 -> V_241 ;
V_240 -> V_724 = - 1 ;
}
V_132 -> V_721 = 0 ;
}
static void F_215 ( struct V_129 * V_130 )
{
}
static void F_216 ( struct V_129 * V_130 )
{
}
static void
F_217 ( struct V_129 * V_130 ,
struct V_151 * V_152 ,
struct V_151 * V_614 )
{
}
static void F_218 ( struct V_129 * V_130 )
{
}
static void
F_219 ( struct V_129 * V_130 , int V_152 )
{
}
static bool F_220 ( struct V_129 * V_130 ,
const struct V_151 * V_152 ,
struct V_151 * V_614 )
{
return true ;
}
static void F_221 ( struct V_129 * V_130 )
{
struct V_132 * V_132 = F_35 ( V_130 ) ;
if ( V_132 -> V_137 & ( V_138 ) )
F_222 ( V_132 ) ;
F_72 ( V_132 -> V_241 ) ;
F_223 ( V_130 ) ;
F_72 ( V_132 ) ;
}
static void F_224 ( struct V_1 * V_2 ,
T_6 V_728 ,
T_6 V_729 ,
T_5 V_730 )
{
struct V_75 * V_76 = V_2 -> V_77 ;
struct V_129 * V_130 ;
struct V_132 * V_132 ;
F_19 (encoder, &dev->mode_config.encoder_list, head) {
V_132 = F_35 ( V_130 ) ;
if ( V_132 -> V_728 == V_728 ) {
V_132 -> V_137 |= V_729 ;
return;
}
}
V_132 = F_90 ( sizeof( struct V_132 ) , V_397 ) ;
if ( ! V_132 )
return;
V_130 = & V_132 -> V_155 ;
switch ( V_2 -> V_19 . V_20 ) {
case 1 :
V_130 -> V_731 = 0x1 ;
break;
case 2 :
default:
V_130 -> V_731 = 0x3 ;
break;
case 4 :
V_130 -> V_731 = 0xf ;
break;
case 6 :
V_130 -> V_731 = 0x3f ;
break;
}
V_132 -> V_241 = NULL ;
V_132 -> V_728 = V_728 ;
V_132 -> V_139 = ( V_728 & V_732 ) >> V_733 ;
V_132 -> V_137 = V_729 ;
V_132 -> V_223 = V_224 ;
V_132 -> V_734 = V_735 ;
V_132 -> V_736 = false ;
V_132 -> V_730 = V_730 ;
switch ( V_132 -> V_139 ) {
case V_140 :
case V_141 :
F_225 ( V_76 , V_130 , & V_737 ,
V_738 ) ;
F_226 ( V_130 , & V_739 ) ;
break;
case V_740 :
case V_553 :
case V_555 :
case V_556 :
case V_557 :
if ( V_132 -> V_137 & ( V_138 ) ) {
V_132 -> V_223 = V_741 ;
F_225 ( V_76 , V_130 , & V_737 ,
V_742 ) ;
V_132 -> V_241 = F_227 ( V_132 ) ;
} else if ( V_132 -> V_137 & ( V_743 ) ) {
F_225 ( V_76 , V_130 , & V_737 ,
V_738 ) ;
V_132 -> V_241 = F_228 ( V_132 ) ;
} else {
F_225 ( V_76 , V_130 , & V_737 ,
V_744 ) ;
V_132 -> V_241 = F_228 ( V_132 ) ;
}
F_226 ( V_130 , & V_745 ) ;
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
V_132 -> V_736 = true ;
if ( V_132 -> V_137 & ( V_138 ) )
F_225 ( V_76 , V_130 , & V_737 ,
V_742 ) ;
else if ( V_132 -> V_137 & ( V_743 ) )
F_225 ( V_76 , V_130 , & V_737 ,
V_738 ) ;
else
F_225 ( V_76 , V_130 , & V_737 ,
V_744 ) ;
F_226 ( V_130 , & V_755 ) ;
break;
}
}
static void F_161 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 . V_632 == NULL )
V_2 -> V_19 . V_632 = & V_756 ;
}
static void F_162 ( struct V_1 * V_2 )
{
V_2 -> V_605 . V_757 = V_758 ;
V_2 -> V_605 . V_632 = & V_759 ;
V_2 -> V_630 . V_757 = V_760 ;
V_2 -> V_630 . V_632 = & V_761 ;
V_2 -> V_93 . V_757 = V_762 ;
V_2 -> V_93 . V_632 = & V_763 ;
}
