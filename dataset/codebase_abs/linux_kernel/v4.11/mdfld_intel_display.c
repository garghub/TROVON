void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
int V_10 , V_11 ;
switch ( V_3 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_2 ( L_1 ) ;
return;
}
F_3 ( V_2 ) ;
return;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_14 ) == 0 )
break;
}
}
void F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
int V_10 , V_11 ;
switch ( V_3 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_2 ( L_1 ) ;
return;
}
F_3 ( V_2 ) ;
return;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_14 ) == 1 )
break;
}
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_15 ;
V_15 = F_4 ( V_16 ) ;
if ( ( V_15 & V_17 ) == 0 )
return - 1 ;
return ( V_15 >> 29 ) & 0x3 ;
}
void F_7 ( int V_18 )
{
struct V_1 * V_2 = & V_19 ;
int V_20 = V_21 ;
T_1 V_22 ;
V_22 = F_4 ( V_20 ) ;
if ( V_18 ) {
V_22 &= ~ V_23 ;
V_22 |= V_24 ;
} else {
V_22 &= ~ V_24 ;
V_22 |= V_23 ;
}
F_8 ( V_20 , V_22 ) ;
}
static int F_9 ( struct V_25 * V_26 )
{
if ( ! V_26 )
return 0 ;
switch ( V_26 -> V_27 -> V_28 [ 0 ] * 8 ) {
case 8 :
case 16 :
case 24 :
case 32 :
return 0 ;
default:
F_2 ( L_2 ) ;
return - V_29 ;
}
}
static int F_10 ( struct V_30 * V_31 , int V_32 , int V_33 ,
struct V_25 * V_34 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_25 * V_26 = V_31 -> V_35 -> V_26 ;
struct V_36 * V_36 = F_11 ( V_31 ) ;
struct V_37 * V_38 = F_12 ( V_26 ) ;
int V_3 = V_36 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
unsigned long V_39 , V_40 ;
T_1 V_22 ;
int V_41 ;
memcpy ( & V_19 , V_2 , sizeof( struct V_1 ) ) ;
F_13 ( V_2 -> V_2 , L_3 , V_3 ) ;
if ( ! V_26 ) {
F_13 ( V_2 -> V_2 , L_4 ) ;
return 0 ;
}
V_41 = F_9 ( V_26 ) ;
if ( V_41 )
return V_41 ;
if ( V_3 > 2 ) {
F_2 ( L_1 ) ;
return - V_29 ;
}
if ( ! F_14 ( V_2 , true ) )
return 0 ;
V_39 = V_38 -> V_42 -> V_40 ;
V_40 = V_33 * V_26 -> V_43 [ 0 ] + V_32 * V_26 -> V_27 -> V_28 [ 0 ] ;
F_8 ( V_8 -> V_44 , V_26 -> V_43 [ 0 ] ) ;
V_22 = F_4 ( V_8 -> V_45 ) ;
V_22 &= ~ V_46 ;
switch ( V_26 -> V_27 -> V_28 [ 0 ] * 8 ) {
case 8 :
V_22 |= V_47 ;
break;
case 16 :
if ( V_26 -> V_27 -> V_48 == 15 )
V_22 |= V_49 ;
else
V_22 |= V_50 ;
break;
case 24 :
case 32 :
V_22 |= V_23 ;
break;
}
F_8 ( V_8 -> V_45 , V_22 ) ;
F_13 ( V_2 -> V_2 , L_5 ,
V_39 , V_40 , V_32 , V_33 ) ;
F_8 ( V_8 -> V_51 , V_40 ) ;
F_4 ( V_8 -> V_51 ) ;
F_8 ( V_8 -> V_52 , V_39 ) ;
F_4 ( V_8 -> V_52 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
T_1 V_11 ;
F_13 ( V_2 -> V_2 , L_6 , V_3 ) ;
if ( V_3 != 1 )
F_17 ( V_2 , F_18 ( V_3 ) ,
V_53 | V_54 ) ;
V_11 = F_4 ( V_8 -> V_45 ) ;
if ( ( V_11 & V_55 ) != 0 ) {
F_8 ( V_8 -> V_45 ,
V_11 & ~ V_55 ) ;
F_8 ( V_8 -> V_56 , F_4 ( V_8 -> V_56 ) ) ;
F_4 ( V_8 -> V_56 ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_57 ) != 0 ) {
V_11 &= ~ V_57 ;
V_11 |= V_58 | V_59 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_4 ( V_8 -> V_13 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_11 = F_4 ( V_8 -> V_60 ) ;
if ( V_11 & V_61 ) {
if ( ( V_3 != 1 &&
! ( ( F_4 ( V_62 ) | F_4 ( V_63 ) )
& V_57 ) ) || V_3 == 1 ) {
V_11 &= ~ ( V_61 ) ;
F_8 ( V_8 -> V_60 , V_11 ) ;
F_4 ( V_8 -> V_60 ) ;
F_19 ( 500 ) ;
if ( ! ( V_11 & V_64 ) ) {
F_8 ( V_8 -> V_60 , V_11 | V_64 ) ;
F_19 ( 5000 ) ;
}
}
}
}
static void F_20 ( struct V_30 * V_31 , int V_65 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_36 * V_36 = F_11 ( V_31 ) ;
int V_3 = V_36 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
T_1 V_66 = V_5 -> V_66 [ V_3 ] ;
T_1 V_11 ;
int V_67 = 0 ;
F_13 ( V_2 -> V_2 , L_7 , V_65 , V_3 ) ;
if ( ! F_14 ( V_2 , true ) )
return;
switch ( V_65 ) {
case V_68 :
case V_69 :
case V_70 :
V_11 = F_4 ( V_8 -> V_60 ) ;
if ( ( V_11 & V_61 ) == 0 ) {
if ( V_11 & V_64 ) {
V_11 &= ~ V_64 ;
F_8 ( V_8 -> V_60 , V_11 ) ;
F_19 ( 500 ) ;
}
F_8 ( V_8 -> V_60 , V_11 ) ;
F_4 ( V_8 -> V_60 ) ;
F_19 ( 500 ) ;
F_8 ( V_8 -> V_60 , V_11 | V_61 ) ;
F_4 ( V_8 -> V_60 ) ;
while ( ( V_3 != 2 ) && ( V_67 < 20000 ) &&
! ( F_4 ( V_8 -> V_13 ) & V_71 ) ) {
F_19 ( 150 ) ;
V_67 ++ ;
}
}
V_11 = F_4 ( V_8 -> V_45 ) ;
if ( ( V_11 & V_55 ) == 0 ) {
F_8 ( V_8 -> V_45 ,
V_11 | V_55 ) ;
F_8 ( V_8 -> V_56 , F_4 ( V_8 -> V_56 ) ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_57 ) == 0 ) {
F_8 ( V_8 -> V_13 , V_66 ) ;
F_5 ( V_2 , V_3 ) ;
}
if ( V_3 == 0 || V_3 == 2 ) {
F_8 ( V_8 -> V_72 , F_4 ( V_8 -> V_72 ) ) ;
F_21 ( 100 ) ;
if ( V_73 & F_4 ( V_8 -> V_72 ) )
F_13 ( V_2 -> V_2 , L_8 ) ;
else {
F_13 ( V_2 -> V_2 , L_9 ) ;
V_11 = F_4 ( V_8 -> V_45 ) ;
F_8 ( V_8 -> V_45 ,
V_11 & ~ V_55 ) ;
F_8 ( V_8 -> V_56 , F_4 ( V_8 -> V_56 ) ) ;
F_8 ( 0xb048 , 1 ) ;
F_21 ( 100 ) ;
V_11 = F_4 ( V_8 -> V_13 ) ;
V_11 &= ~ V_57 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_21 ( 100 ) ;
F_8 ( F_22 ( V_3 ) , 0 ) ;
F_21 ( 100 ) ;
F_8 ( 0xb004 , F_4 ( 0xb004 ) ) ;
F_8 ( F_22 ( V_3 ) , 1 ) ;
V_11 = F_4 ( V_8 -> V_45 ) ;
F_8 ( V_8 -> V_45 ,
V_11 | V_55 ) ;
F_8 ( V_8 -> V_56 , F_4 ( V_8 -> V_56 ) ) ;
F_8 ( 0xb048 , 2 ) ;
F_21 ( 100 ) ;
V_11 = F_4 ( V_8 -> V_13 ) ;
V_11 |= V_57 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
}
}
F_23 ( V_31 ) ;
break;
case V_74 :
if ( V_3 != 1 )
F_17 ( V_2 ,
F_18 ( V_3 ) ,
V_53 | V_54 ) ;
F_8 ( V_75 , V_76 ) ;
V_11 = F_4 ( V_8 -> V_45 ) ;
if ( ( V_11 & V_55 ) != 0 ) {
F_8 ( V_8 -> V_45 ,
V_11 & ~ V_55 ) ;
F_8 ( V_8 -> V_56 , F_4 ( V_8 -> V_56 ) ) ;
F_4 ( V_8 -> V_56 ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_57 ) != 0 ) {
V_11 &= ~ V_57 ;
V_11 |= V_58 | V_59 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_4 ( V_8 -> V_13 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_11 = F_4 ( V_8 -> V_60 ) ;
if ( V_11 & V_61 ) {
if ( ( V_3 != 1 && ! ( ( F_4 ( V_62 )
| F_4 ( V_63 ) ) & V_57 ) )
|| V_3 == 1 ) {
V_11 &= ~ ( V_61 ) ;
F_8 ( V_8 -> V_60 , V_11 ) ;
F_4 ( V_8 -> V_60 ) ;
F_19 ( 500 ) ;
}
}
break;
}
F_15 ( V_2 ) ;
}
static const struct V_77 * F_24 ( struct V_30 * V_31 )
{
const struct V_77 * V_78 = NULL ;
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_25 ( V_31 , V_79 )
|| F_25 ( V_31 , V_80 ) ) {
if ( ( V_81 == V_82 ) || ( V_81 == V_83 ) )
V_78 = & V_84 [ V_85 ] ;
else if ( V_81 == V_86 )
V_78 = & V_84 [ V_87 ] ;
else if ( ( V_81 == V_88 ) &&
( V_5 -> V_89 == 166 ) )
V_78 = & V_84 [ V_90 ] ;
else if ( ( V_81 == V_88 ) &&
( V_5 -> V_89 == 100 ||
V_5 -> V_89 == 200 ) )
V_78 = & V_84 [ V_91 ] ;
} else if ( F_25 ( V_31 , V_92 ) ) {
if ( ( V_81 == V_82 ) || ( V_81 == V_83 ) )
V_78 = & V_84 [ V_93 ] ;
else if ( V_81 == V_86 )
V_78 = & V_84 [ V_94 ] ;
else if ( ( V_81 == V_88 ) &&
( V_5 -> V_89 == 166 ) )
V_78 = & V_84 [ V_95 ] ;
else if ( ( V_81 == V_88 ) &&
( V_5 -> V_89 == 100 ||
V_5 -> V_89 == 200 ) )
V_78 = & V_84 [ V_96 ] ;
} else {
V_78 = NULL ;
F_13 ( V_2 -> V_2 , L_10 ) ;
}
return V_78 ;
}
static void F_26 ( int V_97 , struct V_98 * clock )
{
clock -> V_99 = ( V_97 * clock -> V_100 ) / clock -> V_101 ;
}
static bool
F_27 ( struct V_30 * V_31 , int V_102 , int V_97 ,
struct V_98 * V_103 )
{
struct V_98 clock ;
const struct V_77 * V_78 = F_24 ( V_31 ) ;
int V_104 = V_102 ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
for ( clock . V_100 = V_78 -> V_100 . V_105 ; clock . V_100 <= V_78 -> V_100 . V_106 ; clock . V_100 ++ ) {
for ( clock . V_101 = V_78 -> V_101 . V_105 ; clock . V_101 <= V_78 -> V_101 . V_106 ;
clock . V_101 ++ ) {
int V_107 ;
F_26 ( V_97 , & clock ) ;
V_107 = abs ( clock . V_99 - V_102 ) ;
if ( V_107 < V_104 ) {
* V_103 = clock ;
V_104 = V_107 ;
}
}
}
return V_104 != V_102 ;
}
static int F_28 ( struct V_30 * V_31 ,
struct V_108 * V_65 ,
struct V_108 * V_109 ,
int V_32 , int V_33 ,
struct V_25 * V_34 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_36 * V_36 = F_11 ( V_31 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_3 = V_36 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
int V_97 = 0 ;
int V_110 = 0 , V_111 = 0 , V_112 = 1 , V_113 = 0 , V_114 = 0 ,
V_115 = 0 ;
struct V_98 clock ;
bool V_116 ;
T_1 V_60 = 0 , V_117 = 0 ;
bool V_118 = false , V_119 = false , V_120 = false ;
struct V_121 * V_122 = & V_2 -> V_122 ;
struct V_123 * V_123 = NULL ;
T_2 V_124 = V_125 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
int V_67 = 0 ;
int V_41 ;
F_13 ( V_2 -> V_2 , L_11 , V_3 ) ;
#if 0
if (pipe == 1) {
if (!gma_power_begin(dev, true))
return 0;
android_hdmi_crtc_mode_set(crtc, mode, adjusted_mode,
x, y, old_fb);
goto mrst_crtc_mode_set_exit;
}
#endif
V_41 = F_9 ( V_31 -> V_35 -> V_26 ) ;
if ( V_41 )
return V_41 ;
F_13 ( V_2 -> V_2 , L_12 ,
V_109 -> V_130 ) ;
F_13 ( V_2 -> V_2 , L_13 ,
V_109 -> V_131 ) ;
F_13 ( V_2 -> V_2 , L_14 ,
V_109 -> V_132 ) ;
F_13 ( V_2 -> V_2 , L_15 ,
V_109 -> V_133 ) ;
F_13 ( V_2 -> V_2 , L_16 ,
V_109 -> V_134 ) ;
F_13 ( V_2 -> V_2 , L_17 ,
V_109 -> V_135 ) ;
F_13 ( V_2 -> V_2 , L_18 ,
V_109 -> V_136 ) ;
F_13 ( V_2 -> V_2 , L_19 ,
V_109 -> V_137 ) ;
F_13 ( V_2 -> V_2 , L_20 ,
V_109 -> clock ) ;
F_13 ( V_2 -> V_2 , L_21 ,
V_65 -> V_130 ) ;
F_13 ( V_2 -> V_2 , L_22 ,
V_65 -> V_131 ) ;
if ( ! F_14 ( V_2 , true ) )
return 0 ;
memcpy ( & V_36 -> V_138 , V_65 ,
sizeof( struct V_108 ) ) ;
memcpy ( & V_36 -> V_139 , V_109 ,
sizeof( struct V_108 ) ) ;
F_29 (connector, &mode_config->connector_list, head) {
if ( ! V_129 )
continue;
V_127 = V_129 -> V_127 ;
if ( ! V_127 )
continue;
if ( V_127 -> V_31 != V_31 )
continue;
V_123 = F_30 ( V_129 ) ;
switch ( V_123 -> type ) {
case V_79 :
V_118 = true ;
break;
case V_80 :
V_119 = true ;
break;
case V_92 :
V_120 = true ;
break;
}
}
F_8 ( V_75 , V_76 ) ;
if ( F_6 ( V_2 ) == V_3 )
F_8 ( V_16 , 0 ) ;
if ( V_3 == 1 ) {
F_8 ( V_8 -> V_140 , ( ( V_105 ( V_65 -> V_141 , V_109 -> V_141 ) - 1 ) << 16 )
| ( V_105 ( V_65 -> V_142 , V_109 -> V_142 ) - 1 ) ) ;
F_8 ( V_8 -> V_143 , ( ( V_65 -> V_142 - 1 ) << 16 )
| ( V_65 -> V_141 - 1 ) ) ;
} else {
F_8 ( V_8 -> V_140 ,
( ( V_65 -> V_141 - 1 ) << 16 ) |
( V_65 -> V_142 - 1 ) ) ;
F_8 ( V_8 -> V_143 ,
( ( V_65 -> V_142 - 1 ) << 16 ) |
( V_65 -> V_141 - 1 ) ) ;
}
F_8 ( V_8 -> V_144 , 0 ) ;
if ( V_123 )
F_31 ( & V_129 -> V_56 ,
V_2 -> V_122 . V_145 , & V_124 ) ;
if ( V_124 == V_146 ) {
int V_147 = 0 , V_148 = 0 ;
V_147 = ( V_109 -> V_142 -
V_65 -> V_142 ) / 2 ;
V_148 = ( V_109 -> V_141 -
V_65 -> V_141 ) / 2 ;
F_8 ( V_8 -> V_134 , ( V_65 -> V_142 - 1 ) |
( ( V_109 -> V_149 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_137 , ( V_65 -> V_141 - 1 ) |
( ( V_109 -> V_150 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_151 , ( V_109 -> V_152 -
V_147 - 1 ) |
( ( V_109 -> V_153 - V_147 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_154 , ( V_109 -> V_155 -
V_147 - 1 ) |
( ( V_109 -> V_156 - V_147 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_157 , ( V_109 -> V_158 -
V_148 - 1 ) |
( ( V_109 -> V_159 - V_148 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_160 , ( V_109 -> V_161 -
V_148 - 1 ) |
( ( V_109 -> V_162 - V_148 - 1 ) << 16 ) ) ;
} else {
F_8 ( V_8 -> V_134 , ( V_109 -> V_142 - 1 ) |
( ( V_109 -> V_149 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_137 , ( V_109 -> V_141 - 1 ) |
( ( V_109 -> V_150 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_151 , ( V_109 -> V_152 - 1 ) |
( ( V_109 -> V_153 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_154 , ( V_109 -> V_155 - 1 ) |
( ( V_109 -> V_156 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_157 , ( V_109 -> V_158 - 1 ) |
( ( V_109 -> V_159 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_160 , ( V_109 -> V_161 - 1 ) |
( ( V_109 -> V_162 - 1 ) << 16 ) ) ;
}
{
const struct V_163 * V_164 =
V_31 -> V_165 ;
V_164 -> V_166 ( V_31 , V_32 , V_33 , V_34 ) ;
}
V_5 -> V_66 [ V_3 ] = V_57 ;
V_5 -> V_22 [ V_3 ] = F_4 ( V_8 -> V_45 ) ;
V_5 -> V_22 [ V_3 ] |= V_3 << V_167 ;
V_5 -> V_22 [ V_3 ] |= V_55 ;
if ( V_119 )
goto V_168;
V_113 = V_109 -> clock ;
if ( V_120 ) {
if ( ( V_81 == V_82 ) || ( V_81 == V_83 ) ) {
V_97 = 19200 ;
if ( V_118 || V_119 )
V_110 = 1 , V_111 = 8 ;
else if ( V_120 )
V_110 = 1 , V_111 = 10 ;
} else if ( V_81 == V_86 ) {
V_97 = 25000 ;
if ( V_118 || V_119 )
V_110 = 1 , V_111 = 8 ;
else if ( V_120 )
V_110 = 1 , V_111 = 10 ;
} else if ( ( V_81 == V_88 ) &&
V_5 -> V_89 == 166 ) {
V_97 = 83000 ;
if ( V_118 || V_119 )
V_110 = 4 , V_111 = 8 ;
else if ( V_120 )
V_110 = 4 , V_111 = 10 ;
} else if ( ( V_81 == V_88 ) &&
( V_5 -> V_89 == 100 ||
V_5 -> V_89 == 200 ) ) {
V_97 = 100000 ;
if ( V_118 || V_119 )
V_110 = 4 , V_111 = 8 ;
else if ( V_120 )
V_110 = 4 , V_111 = 10 ;
}
if ( V_118 )
V_112 = V_5 -> V_169 / 8 ;
else if ( V_119 )
V_112 = V_5 -> V_170 / 8 ;
V_115 = V_113 * V_110 * V_111 * V_112 ;
F_13 ( V_2 -> V_2 , L_23 ,
V_113 , V_110 , V_111 ) ;
F_13 ( V_2 -> V_2 , L_24 ,
V_109 -> clock , V_115 ) ;
V_116 = F_27 ( V_31 , V_115 , V_97 , & clock ) ;
if ( ! V_116 ) {
F_2
( L_25 ) ;
} else {
V_114 = V_171 [ ( clock . V_100 - V_172 ) ] ;
F_13 ( V_2 -> V_2 , L_26
L_27 ,
clock . V_99 , clock . V_100 ,
clock . V_101 , V_114 ) ;
}
V_60 = F_4 ( V_8 -> V_60 ) ;
if ( V_60 & V_61 ) {
V_60 &= ~ V_61 ;
F_8 ( V_8 -> V_60 , V_60 ) ;
F_4 ( V_8 -> V_60 ) ;
F_19 ( 500 ) ;
F_8 ( V_8 -> V_173 , 0 ) ;
V_60 &= ~ V_174 ;
F_8 ( V_8 -> V_60 , V_60 ) ;
F_19 ( 500 ) ;
}
if ( V_60 & V_64 ) {
V_60 &= ~ V_64 ;
F_8 ( V_8 -> V_60 , V_60 ) ;
F_19 ( 500 ) ;
}
V_60 = 0 ;
#if 0
if (ksel == KSEL_CRYSTAL_19 || ksel == KSEL_BYPASS_19 ||
ksel == KSEL_BYPASS_25)
dpll &= ~MDFLD_INPUT_REF_SEL;
else if (ksel == KSEL_BYPASS_83_100)
dpll |= MDFLD_INPUT_REF_SEL;
#endif
if ( V_120 )
V_60 |= V_175 ;
V_117 = ( V_110 / 2 ) << 16 ;
V_117 |= V_114 ;
V_60 |= ( 1 << ( clock . V_101 - 2 ) ) << 17 ;
#if 0
dpll = 0x00050000;
fp = 0x000001be;
#endif
#if 0
dpll = 0x02010000;
fp = 0x000000d2;
#endif
} else {
#if 0
dpll = 0x00020000;
fp = 0x00000156;
#endif
V_60 = 0x00800000 ;
V_117 = 0x000000c1 ;
}
F_8 ( V_8 -> V_173 , V_117 ) ;
F_8 ( V_8 -> V_60 , V_60 ) ;
F_19 ( 500 ) ;
V_60 |= V_61 ;
F_8 ( V_8 -> V_60 , V_60 ) ;
F_4 ( V_8 -> V_60 ) ;
while ( V_67 < 20000 &&
! ( F_4 ( V_8 -> V_13 ) & V_71 ) ) {
F_19 ( 150 ) ;
V_67 ++ ;
}
if ( V_118 )
goto V_168;
F_13 ( V_2 -> V_2 , L_28 , V_118 ) ;
F_8 ( V_8 -> V_13 , V_5 -> V_66 [ V_3 ] ) ;
F_4 ( V_8 -> V_13 ) ;
F_8 ( V_8 -> V_45 , V_5 -> V_22 [ V_3 ] ) ;
F_3 ( V_2 ) ;
V_168:
F_15 ( V_2 ) ;
return 0 ;
}
