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
static void F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
V_18 -> V_20 ( V_16 , V_21 ) ;
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
V_18 -> V_20 ( V_16 , V_22 ) ;
}
static bool F_8 ( struct V_15 * V_16 ,
struct V_23 * V_24 ,
struct V_23 * V_25 )
{
return true ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_26 ;
V_26 = F_4 ( V_27 ) ;
if ( ( V_26 & V_28 ) == 0 )
return - 1 ;
return ( V_26 >> 29 ) & 0x3 ;
}
void F_10 ( int V_29 )
{
struct V_1 * V_2 = & V_30 ;
int V_31 = V_32 ;
T_1 V_33 ;
V_33 = F_4 ( V_31 ) ;
if ( V_29 ) {
V_33 &= ~ V_34 ;
V_33 |= V_35 ;
} else {
V_33 &= ~ V_35 ;
V_33 |= V_34 ;
}
F_11 ( V_31 , V_33 ) ;
}
static int F_12 ( struct V_36 * V_37 )
{
if ( ! V_37 )
return 0 ;
switch ( V_37 -> V_38 ) {
case 8 :
case 16 :
case 24 :
case 32 :
return 0 ;
default:
F_2 ( L_2 ) ;
return - V_39 ;
}
}
static int F_13 ( struct V_15 * V_16 , int V_40 , int V_41 ,
struct V_36 * V_42 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_43 * V_43 = F_14 ( V_16 ) ;
struct V_44 * V_45 = F_15 ( V_16 -> V_37 ) ;
int V_3 = V_43 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
unsigned long V_46 , V_47 ;
T_1 V_33 ;
int V_48 ;
memcpy ( & V_30 , V_2 , sizeof( struct V_1 ) ) ;
F_16 ( V_2 -> V_2 , L_3 , V_3 ) ;
if ( ! V_16 -> V_37 ) {
F_16 ( V_2 -> V_2 , L_4 ) ;
return 0 ;
}
V_48 = F_12 ( V_16 -> V_37 ) ;
if ( V_48 )
return V_48 ;
if ( V_3 > 2 ) {
F_2 ( L_1 ) ;
return - V_39 ;
}
if ( ! F_17 ( V_2 , true ) )
return 0 ;
V_46 = V_45 -> V_49 -> V_47 ;
V_47 = V_41 * V_16 -> V_37 -> V_50 [ 0 ] + V_40 * ( V_16 -> V_37 -> V_38 / 8 ) ;
F_11 ( V_8 -> V_51 , V_16 -> V_37 -> V_50 [ 0 ] ) ;
V_33 = F_4 ( V_8 -> V_52 ) ;
V_33 &= ~ V_53 ;
switch ( V_16 -> V_37 -> V_38 ) {
case 8 :
V_33 |= V_54 ;
break;
case 16 :
if ( V_16 -> V_37 -> V_55 == 15 )
V_33 |= V_56 ;
else
V_33 |= V_57 ;
break;
case 24 :
case 32 :
V_33 |= V_34 ;
break;
}
F_11 ( V_8 -> V_52 , V_33 ) ;
F_16 ( V_2 -> V_2 , L_5 ,
V_46 , V_47 , V_40 , V_41 ) ;
F_11 ( V_8 -> V_58 , V_47 ) ;
F_4 ( V_8 -> V_58 ) ;
F_11 ( V_8 -> V_59 , V_46 ) ;
F_4 ( V_8 -> V_59 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
T_1 V_11 ;
F_16 ( V_2 -> V_2 , L_6 , V_3 ) ;
if ( V_3 != 1 )
F_20 ( V_2 , F_21 ( V_3 ) ,
V_60 | V_61 ) ;
V_11 = F_4 ( V_8 -> V_52 ) ;
if ( ( V_11 & V_62 ) != 0 ) {
F_11 ( V_8 -> V_52 ,
V_11 & ~ V_62 ) ;
F_11 ( V_8 -> V_63 , F_4 ( V_8 -> V_63 ) ) ;
F_4 ( V_8 -> V_63 ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_64 ) != 0 ) {
V_11 &= ~ V_64 ;
V_11 |= V_65 | V_66 ;
F_11 ( V_8 -> V_13 , V_11 ) ;
F_4 ( V_8 -> V_13 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_11 = F_4 ( V_8 -> V_67 ) ;
if ( V_11 & V_68 ) {
if ( ( V_3 != 1 &&
! ( ( F_4 ( V_69 ) | F_4 ( V_70 ) )
& V_64 ) ) || V_3 == 1 ) {
V_11 &= ~ ( V_68 ) ;
F_11 ( V_8 -> V_67 , V_11 ) ;
F_4 ( V_8 -> V_67 ) ;
F_22 ( 500 ) ;
if ( ! ( V_11 & V_71 ) ) {
F_11 ( V_8 -> V_67 , V_11 | V_71 ) ;
F_22 ( 5000 ) ;
}
}
}
}
static void F_23 ( struct V_15 * V_16 , int V_24 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_43 * V_43 = F_14 ( V_16 ) ;
int V_3 = V_43 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
T_1 V_72 = V_5 -> V_72 [ V_3 ] ;
T_1 V_11 ;
int V_73 = 0 ;
F_16 ( V_2 -> V_2 , L_7 , V_24 , V_3 ) ;
if ( ! F_17 ( V_2 , true ) )
return;
switch ( V_24 ) {
case V_22 :
case V_74 :
case V_75 :
V_11 = F_4 ( V_8 -> V_67 ) ;
if ( ( V_11 & V_68 ) == 0 ) {
if ( V_11 & V_71 ) {
V_11 &= ~ V_71 ;
F_11 ( V_8 -> V_67 , V_11 ) ;
F_22 ( 500 ) ;
}
F_11 ( V_8 -> V_67 , V_11 ) ;
F_4 ( V_8 -> V_67 ) ;
F_22 ( 500 ) ;
F_11 ( V_8 -> V_67 , V_11 | V_68 ) ;
F_4 ( V_8 -> V_67 ) ;
while ( ( V_3 != 2 ) && ( V_73 < 20000 ) &&
! ( F_4 ( V_8 -> V_13 ) & V_76 ) ) {
F_22 ( 150 ) ;
V_73 ++ ;
}
}
V_11 = F_4 ( V_8 -> V_52 ) ;
if ( ( V_11 & V_62 ) == 0 ) {
F_11 ( V_8 -> V_52 ,
V_11 | V_62 ) ;
F_11 ( V_8 -> V_63 , F_4 ( V_8 -> V_63 ) ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_64 ) == 0 ) {
F_11 ( V_8 -> V_13 , V_72 ) ;
F_5 ( V_2 , V_3 ) ;
}
if ( V_3 == 0 || V_3 == 2 ) {
F_11 ( V_8 -> V_77 , F_4 ( V_8 -> V_77 ) ) ;
F_24 ( 100 ) ;
if ( V_78 & F_4 ( V_8 -> V_77 ) )
F_16 ( V_2 -> V_2 , L_8 ) ;
else {
F_16 ( V_2 -> V_2 , L_9 ) ;
V_11 = F_4 ( V_8 -> V_52 ) ;
F_11 ( V_8 -> V_52 ,
V_11 & ~ V_62 ) ;
F_11 ( V_8 -> V_63 , F_4 ( V_8 -> V_63 ) ) ;
F_11 ( 0xb048 , 1 ) ;
F_24 ( 100 ) ;
V_11 = F_4 ( V_8 -> V_13 ) ;
V_11 &= ~ V_64 ;
F_11 ( V_8 -> V_13 , V_11 ) ;
F_24 ( 100 ) ;
F_11 ( F_25 ( V_3 ) , 0 ) ;
F_24 ( 100 ) ;
F_11 ( 0xb004 , F_4 ( 0xb004 ) ) ;
F_11 ( F_25 ( V_3 ) , 1 ) ;
V_11 = F_4 ( V_8 -> V_52 ) ;
F_11 ( V_8 -> V_52 ,
V_11 | V_62 ) ;
F_11 ( V_8 -> V_63 , F_4 ( V_8 -> V_63 ) ) ;
F_11 ( 0xb048 , 2 ) ;
F_24 ( 100 ) ;
V_11 = F_4 ( V_8 -> V_13 ) ;
V_11 |= V_64 ;
F_11 ( V_8 -> V_13 , V_11 ) ;
}
}
F_26 ( V_16 ) ;
break;
case V_21 :
if ( V_3 != 1 )
F_20 ( V_2 ,
F_21 ( V_3 ) ,
V_60 | V_61 ) ;
F_11 ( V_79 , V_80 ) ;
V_11 = F_4 ( V_8 -> V_52 ) ;
if ( ( V_11 & V_62 ) != 0 ) {
F_11 ( V_8 -> V_52 ,
V_11 & ~ V_62 ) ;
F_11 ( V_8 -> V_63 , F_4 ( V_8 -> V_63 ) ) ;
F_4 ( V_8 -> V_63 ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_64 ) != 0 ) {
V_11 &= ~ V_64 ;
V_11 |= V_65 | V_66 ;
F_11 ( V_8 -> V_13 , V_11 ) ;
F_4 ( V_8 -> V_13 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_11 = F_4 ( V_8 -> V_67 ) ;
if ( V_11 & V_68 ) {
if ( ( V_3 != 1 && ! ( ( F_4 ( V_69 )
| F_4 ( V_70 ) ) & V_64 ) )
|| V_3 == 1 ) {
V_11 &= ~ ( V_68 ) ;
F_11 ( V_8 -> V_67 , V_11 ) ;
F_4 ( V_8 -> V_67 ) ;
F_22 ( 500 ) ;
}
}
break;
}
F_18 ( V_2 ) ;
}
static const struct V_81 * F_27 ( struct V_15 * V_16 )
{
const struct V_81 * V_82 = NULL ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_28 ( V_16 , V_83 )
|| F_28 ( V_16 , V_84 ) ) {
if ( ( V_85 == V_86 ) || ( V_85 == V_87 ) )
V_82 = & V_88 [ V_89 ] ;
else if ( V_85 == V_90 )
V_82 = & V_88 [ V_91 ] ;
else if ( ( V_85 == V_92 ) &&
( V_5 -> V_93 == 166 ) )
V_82 = & V_88 [ V_94 ] ;
else if ( ( V_85 == V_92 ) &&
( V_5 -> V_93 == 100 ||
V_5 -> V_93 == 200 ) )
V_82 = & V_88 [ V_95 ] ;
} else if ( F_28 ( V_16 , V_96 ) ) {
if ( ( V_85 == V_86 ) || ( V_85 == V_87 ) )
V_82 = & V_88 [ V_97 ] ;
else if ( V_85 == V_90 )
V_82 = & V_88 [ V_98 ] ;
else if ( ( V_85 == V_92 ) &&
( V_5 -> V_93 == 166 ) )
V_82 = & V_88 [ V_99 ] ;
else if ( ( V_85 == V_92 ) &&
( V_5 -> V_93 == 100 ||
V_5 -> V_93 == 200 ) )
V_82 = & V_88 [ V_100 ] ;
} else {
V_82 = NULL ;
F_16 ( V_2 -> V_2 , L_10 ) ;
}
return V_82 ;
}
static void F_29 ( int V_101 , struct V_102 * clock )
{
clock -> V_103 = ( V_101 * clock -> V_104 ) / clock -> V_105 ;
}
static bool
F_30 ( struct V_15 * V_16 , int V_106 , int V_101 ,
struct V_102 * V_107 )
{
struct V_102 clock ;
const struct V_81 * V_82 = F_27 ( V_16 ) ;
int V_108 = V_106 ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
for ( clock . V_104 = V_82 -> V_104 . V_109 ; clock . V_104 <= V_82 -> V_104 . V_110 ; clock . V_104 ++ ) {
for ( clock . V_105 = V_82 -> V_105 . V_109 ; clock . V_105 <= V_82 -> V_105 . V_110 ;
clock . V_105 ++ ) {
int V_111 ;
F_29 ( V_101 , & clock ) ;
V_111 = abs ( clock . V_103 - V_106 ) ;
if ( V_111 < V_108 ) {
* V_107 = clock ;
V_108 = V_111 ;
}
}
}
return V_108 != V_106 ;
}
static int F_31 ( struct V_15 * V_16 ,
struct V_23 * V_24 ,
struct V_23 * V_25 ,
int V_40 , int V_41 ,
struct V_36 * V_42 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_43 * V_43 = F_14 ( V_16 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_3 = V_43 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
int V_101 = 0 ;
int V_112 = 0 , V_113 = 0 , V_114 = 1 , V_115 = 0 , V_116 = 0 ,
V_117 = 0 ;
struct V_102 clock ;
bool V_118 ;
T_1 V_67 = 0 , V_119 = 0 ;
bool V_120 = false , V_121 = false , V_122 = false ;
struct V_123 * V_124 = & V_2 -> V_124 ;
struct V_125 * V_125 = NULL ;
T_2 V_126 = V_127 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
int V_73 = 0 ;
int V_48 ;
F_16 ( V_2 -> V_2 , L_11 , V_3 ) ;
#if 0
if (pipe == 1) {
if (!gma_power_begin(dev, true))
return 0;
android_hdmi_crtc_mode_set(crtc, mode, adjusted_mode,
x, y, old_fb);
goto mrst_crtc_mode_set_exit;
}
#endif
V_48 = F_12 ( V_16 -> V_37 ) ;
if ( V_48 )
return V_48 ;
F_16 ( V_2 -> V_2 , L_12 ,
V_25 -> V_132 ) ;
F_16 ( V_2 -> V_2 , L_13 ,
V_25 -> V_133 ) ;
F_16 ( V_2 -> V_2 , L_14 ,
V_25 -> V_134 ) ;
F_16 ( V_2 -> V_2 , L_15 ,
V_25 -> V_135 ) ;
F_16 ( V_2 -> V_2 , L_16 ,
V_25 -> V_136 ) ;
F_16 ( V_2 -> V_2 , L_17 ,
V_25 -> V_137 ) ;
F_16 ( V_2 -> V_2 , L_18 ,
V_25 -> V_138 ) ;
F_16 ( V_2 -> V_2 , L_19 ,
V_25 -> V_139 ) ;
F_16 ( V_2 -> V_2 , L_20 ,
V_25 -> clock ) ;
F_16 ( V_2 -> V_2 , L_21 ,
V_24 -> V_132 ) ;
F_16 ( V_2 -> V_2 , L_22 ,
V_24 -> V_133 ) ;
if ( ! F_17 ( V_2 , true ) )
return 0 ;
memcpy ( & V_43 -> V_140 , V_24 ,
sizeof( struct V_23 ) ) ;
memcpy ( & V_43 -> V_141 , V_25 ,
sizeof( struct V_23 ) ) ;
F_32 (connector, &mode_config->connector_list, head) {
if ( ! V_131 )
continue;
V_129 = V_131 -> V_129 ;
if ( ! V_129 )
continue;
if ( V_129 -> V_16 != V_16 )
continue;
V_125 = F_33 ( V_131 ) ;
switch ( V_125 -> type ) {
case V_83 :
V_120 = true ;
break;
case V_84 :
V_121 = true ;
break;
case V_96 :
V_122 = true ;
break;
}
}
F_11 ( V_79 , V_80 ) ;
if ( F_9 ( V_2 ) == V_3 )
F_11 ( V_27 , 0 ) ;
if ( V_3 == 1 ) {
F_11 ( V_8 -> V_142 , ( ( V_109 ( V_24 -> V_143 , V_25 -> V_143 ) - 1 ) << 16 )
| ( V_109 ( V_24 -> V_144 , V_25 -> V_144 ) - 1 ) ) ;
F_11 ( V_8 -> V_145 , ( ( V_24 -> V_144 - 1 ) << 16 )
| ( V_24 -> V_143 - 1 ) ) ;
} else {
F_11 ( V_8 -> V_142 ,
( ( V_24 -> V_143 - 1 ) << 16 ) |
( V_24 -> V_144 - 1 ) ) ;
F_11 ( V_8 -> V_145 ,
( ( V_24 -> V_144 - 1 ) << 16 ) |
( V_24 -> V_143 - 1 ) ) ;
}
F_11 ( V_8 -> V_146 , 0 ) ;
if ( V_125 )
F_34 ( V_131 ,
V_2 -> V_124 . V_147 , & V_126 ) ;
if ( V_126 == V_148 ) {
int V_149 = 0 , V_150 = 0 ;
V_149 = ( V_25 -> V_144 -
V_24 -> V_144 ) / 2 ;
V_150 = ( V_25 -> V_143 -
V_24 -> V_143 ) / 2 ;
F_11 ( V_8 -> V_136 , ( V_24 -> V_144 - 1 ) |
( ( V_25 -> V_151 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_139 , ( V_24 -> V_143 - 1 ) |
( ( V_25 -> V_152 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_153 , ( V_25 -> V_154 -
V_149 - 1 ) |
( ( V_25 -> V_155 - V_149 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_156 , ( V_25 -> V_157 -
V_149 - 1 ) |
( ( V_25 -> V_158 - V_149 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_159 , ( V_25 -> V_160 -
V_150 - 1 ) |
( ( V_25 -> V_161 - V_150 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_162 , ( V_25 -> V_163 -
V_150 - 1 ) |
( ( V_25 -> V_164 - V_150 - 1 ) << 16 ) ) ;
} else {
F_11 ( V_8 -> V_136 , ( V_25 -> V_144 - 1 ) |
( ( V_25 -> V_151 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_139 , ( V_25 -> V_143 - 1 ) |
( ( V_25 -> V_152 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_153 , ( V_25 -> V_154 - 1 ) |
( ( V_25 -> V_155 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_156 , ( V_25 -> V_157 - 1 ) |
( ( V_25 -> V_158 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_159 , ( V_25 -> V_160 - 1 ) |
( ( V_25 -> V_161 - 1 ) << 16 ) ) ;
F_11 ( V_8 -> V_162 , ( V_25 -> V_163 - 1 ) |
( ( V_25 -> V_164 - 1 ) << 16 ) ) ;
}
{
struct V_17 * V_18 =
V_16 -> V_19 ;
V_18 -> V_165 ( V_16 , V_40 , V_41 , V_42 ) ;
}
V_5 -> V_72 [ V_3 ] = V_64 ;
V_5 -> V_33 [ V_3 ] = F_4 ( V_8 -> V_52 ) ;
V_5 -> V_33 [ V_3 ] |= V_3 << V_166 ;
V_5 -> V_33 [ V_3 ] |= V_62 ;
if ( V_121 )
goto V_167;
V_115 = V_25 -> clock ;
if ( V_122 ) {
if ( ( V_85 == V_86 ) || ( V_85 == V_87 ) ) {
V_101 = 19200 ;
if ( V_120 || V_121 )
V_112 = 1 , V_113 = 8 ;
else if ( V_122 )
V_112 = 1 , V_113 = 10 ;
} else if ( V_85 == V_90 ) {
V_101 = 25000 ;
if ( V_120 || V_121 )
V_112 = 1 , V_113 = 8 ;
else if ( V_122 )
V_112 = 1 , V_113 = 10 ;
} else if ( ( V_85 == V_92 ) &&
V_5 -> V_93 == 166 ) {
V_101 = 83000 ;
if ( V_120 || V_121 )
V_112 = 4 , V_113 = 8 ;
else if ( V_122 )
V_112 = 4 , V_113 = 10 ;
} else if ( ( V_85 == V_92 ) &&
( V_5 -> V_93 == 100 ||
V_5 -> V_93 == 200 ) ) {
V_101 = 100000 ;
if ( V_120 || V_121 )
V_112 = 4 , V_113 = 8 ;
else if ( V_122 )
V_112 = 4 , V_113 = 10 ;
}
if ( V_120 )
V_114 = V_5 -> V_168 / 8 ;
else if ( V_121 )
V_114 = V_5 -> V_169 / 8 ;
V_117 = V_115 * V_112 * V_113 * V_114 ;
F_16 ( V_2 -> V_2 , L_23 ,
V_115 , V_112 , V_113 ) ;
F_16 ( V_2 -> V_2 , L_24 ,
V_25 -> clock , V_117 ) ;
V_118 = F_30 ( V_16 , V_117 , V_101 , & clock ) ;
if ( ! V_118 ) {
F_2
( L_25 ) ;
} else {
V_116 = V_170 [ ( clock . V_104 - V_171 ) ] ;
F_16 ( V_2 -> V_2 , L_26
L_27 ,
clock . V_103 , clock . V_104 ,
clock . V_105 , V_116 ) ;
}
V_67 = F_4 ( V_8 -> V_67 ) ;
if ( V_67 & V_68 ) {
V_67 &= ~ V_68 ;
F_11 ( V_8 -> V_67 , V_67 ) ;
F_4 ( V_8 -> V_67 ) ;
F_22 ( 500 ) ;
F_11 ( V_8 -> V_172 , 0 ) ;
V_67 &= ~ V_173 ;
F_11 ( V_8 -> V_67 , V_67 ) ;
F_22 ( 500 ) ;
}
if ( V_67 & V_71 ) {
V_67 &= ~ V_71 ;
F_11 ( V_8 -> V_67 , V_67 ) ;
F_22 ( 500 ) ;
}
V_67 = 0 ;
#if 0
if (ksel == KSEL_CRYSTAL_19 || ksel == KSEL_BYPASS_19 ||
ksel == KSEL_BYPASS_25)
dpll &= ~MDFLD_INPUT_REF_SEL;
else if (ksel == KSEL_BYPASS_83_100)
dpll |= MDFLD_INPUT_REF_SEL;
#endif
if ( V_122 )
V_67 |= V_174 ;
V_119 = ( V_112 / 2 ) << 16 ;
V_119 |= V_116 ;
V_67 |= ( 1 << ( clock . V_105 - 2 ) ) << 17 ;
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
V_67 = 0x00800000 ;
V_119 = 0x000000c1 ;
}
F_11 ( V_8 -> V_172 , V_119 ) ;
F_11 ( V_8 -> V_67 , V_67 ) ;
F_22 ( 500 ) ;
V_67 |= V_68 ;
F_11 ( V_8 -> V_67 , V_67 ) ;
F_4 ( V_8 -> V_67 ) ;
while ( V_73 < 20000 &&
! ( F_4 ( V_8 -> V_13 ) & V_76 ) ) {
F_22 ( 150 ) ;
V_73 ++ ;
}
if ( V_120 )
goto V_167;
F_16 ( V_2 -> V_2 , L_28 , V_120 ) ;
F_11 ( V_8 -> V_13 , V_5 -> V_72 [ V_3 ] ) ;
F_4 ( V_8 -> V_13 ) ;
F_11 ( V_8 -> V_52 , V_5 -> V_33 [ V_3 ] ) ;
F_3 ( V_2 ) ;
V_167:
F_18 ( V_2 ) ;
return 0 ;
}
