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
switch ( V_26 -> V_27 ) {
case 8 :
case 16 :
case 24 :
case 32 :
return 0 ;
default:
F_2 ( L_2 ) ;
return - V_28 ;
}
}
static int F_10 ( struct V_29 * V_30 , int V_31 , int V_32 ,
struct V_25 * V_33 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_34 * V_34 = F_11 ( V_30 ) ;
struct V_35 * V_36 = F_12 ( V_30 -> V_37 -> V_26 ) ;
int V_3 = V_34 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
unsigned long V_38 , V_39 ;
T_1 V_22 ;
int V_40 ;
memcpy ( & V_19 , V_2 , sizeof( struct V_1 ) ) ;
F_13 ( V_2 -> V_2 , L_3 , V_3 ) ;
if ( ! V_30 -> V_37 -> V_26 ) {
F_13 ( V_2 -> V_2 , L_4 ) ;
return 0 ;
}
V_40 = F_9 ( V_30 -> V_37 -> V_26 ) ;
if ( V_40 )
return V_40 ;
if ( V_3 > 2 ) {
F_2 ( L_1 ) ;
return - V_28 ;
}
if ( ! F_14 ( V_2 , true ) )
return 0 ;
V_38 = V_36 -> V_41 -> V_39 ;
V_39 = V_32 * V_30 -> V_37 -> V_26 -> V_42 [ 0 ] + V_31 * ( V_30 -> V_37 -> V_26 -> V_27 / 8 ) ;
F_8 ( V_8 -> V_43 , V_30 -> V_37 -> V_26 -> V_42 [ 0 ] ) ;
V_22 = F_4 ( V_8 -> V_44 ) ;
V_22 &= ~ V_45 ;
switch ( V_30 -> V_37 -> V_26 -> V_27 ) {
case 8 :
V_22 |= V_46 ;
break;
case 16 :
if ( V_30 -> V_37 -> V_26 -> V_47 == 15 )
V_22 |= V_48 ;
else
V_22 |= V_49 ;
break;
case 24 :
case 32 :
V_22 |= V_23 ;
break;
}
F_8 ( V_8 -> V_44 , V_22 ) ;
F_13 ( V_2 -> V_2 , L_5 ,
V_38 , V_39 , V_31 , V_32 ) ;
F_8 ( V_8 -> V_50 , V_39 ) ;
F_4 ( V_8 -> V_50 ) ;
F_8 ( V_8 -> V_51 , V_38 ) ;
F_4 ( V_8 -> V_51 ) ;
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
V_52 | V_53 ) ;
V_11 = F_4 ( V_8 -> V_44 ) ;
if ( ( V_11 & V_54 ) != 0 ) {
F_8 ( V_8 -> V_44 ,
V_11 & ~ V_54 ) ;
F_8 ( V_8 -> V_55 , F_4 ( V_8 -> V_55 ) ) ;
F_4 ( V_8 -> V_55 ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_56 ) != 0 ) {
V_11 &= ~ V_56 ;
V_11 |= V_57 | V_58 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_4 ( V_8 -> V_13 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_11 = F_4 ( V_8 -> V_59 ) ;
if ( V_11 & V_60 ) {
if ( ( V_3 != 1 &&
! ( ( F_4 ( V_61 ) | F_4 ( V_62 ) )
& V_56 ) ) || V_3 == 1 ) {
V_11 &= ~ ( V_60 ) ;
F_8 ( V_8 -> V_59 , V_11 ) ;
F_4 ( V_8 -> V_59 ) ;
F_19 ( 500 ) ;
if ( ! ( V_11 & V_63 ) ) {
F_8 ( V_8 -> V_59 , V_11 | V_63 ) ;
F_19 ( 5000 ) ;
}
}
}
}
static void F_20 ( struct V_29 * V_30 , int V_64 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_34 * V_34 = F_11 ( V_30 ) ;
int V_3 = V_34 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
T_1 V_65 = V_5 -> V_65 [ V_3 ] ;
T_1 V_11 ;
int V_66 = 0 ;
F_13 ( V_2 -> V_2 , L_7 , V_64 , V_3 ) ;
if ( ! F_14 ( V_2 , true ) )
return;
switch ( V_64 ) {
case V_67 :
case V_68 :
case V_69 :
V_11 = F_4 ( V_8 -> V_59 ) ;
if ( ( V_11 & V_60 ) == 0 ) {
if ( V_11 & V_63 ) {
V_11 &= ~ V_63 ;
F_8 ( V_8 -> V_59 , V_11 ) ;
F_19 ( 500 ) ;
}
F_8 ( V_8 -> V_59 , V_11 ) ;
F_4 ( V_8 -> V_59 ) ;
F_19 ( 500 ) ;
F_8 ( V_8 -> V_59 , V_11 | V_60 ) ;
F_4 ( V_8 -> V_59 ) ;
while ( ( V_3 != 2 ) && ( V_66 < 20000 ) &&
! ( F_4 ( V_8 -> V_13 ) & V_70 ) ) {
F_19 ( 150 ) ;
V_66 ++ ;
}
}
V_11 = F_4 ( V_8 -> V_44 ) ;
if ( ( V_11 & V_54 ) == 0 ) {
F_8 ( V_8 -> V_44 ,
V_11 | V_54 ) ;
F_8 ( V_8 -> V_55 , F_4 ( V_8 -> V_55 ) ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_56 ) == 0 ) {
F_8 ( V_8 -> V_13 , V_65 ) ;
F_5 ( V_2 , V_3 ) ;
}
if ( V_3 == 0 || V_3 == 2 ) {
F_8 ( V_8 -> V_71 , F_4 ( V_8 -> V_71 ) ) ;
F_21 ( 100 ) ;
if ( V_72 & F_4 ( V_8 -> V_71 ) )
F_13 ( V_2 -> V_2 , L_8 ) ;
else {
F_13 ( V_2 -> V_2 , L_9 ) ;
V_11 = F_4 ( V_8 -> V_44 ) ;
F_8 ( V_8 -> V_44 ,
V_11 & ~ V_54 ) ;
F_8 ( V_8 -> V_55 , F_4 ( V_8 -> V_55 ) ) ;
F_8 ( 0xb048 , 1 ) ;
F_21 ( 100 ) ;
V_11 = F_4 ( V_8 -> V_13 ) ;
V_11 &= ~ V_56 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_21 ( 100 ) ;
F_8 ( F_22 ( V_3 ) , 0 ) ;
F_21 ( 100 ) ;
F_8 ( 0xb004 , F_4 ( 0xb004 ) ) ;
F_8 ( F_22 ( V_3 ) , 1 ) ;
V_11 = F_4 ( V_8 -> V_44 ) ;
F_8 ( V_8 -> V_44 ,
V_11 | V_54 ) ;
F_8 ( V_8 -> V_55 , F_4 ( V_8 -> V_55 ) ) ;
F_8 ( 0xb048 , 2 ) ;
F_21 ( 100 ) ;
V_11 = F_4 ( V_8 -> V_13 ) ;
V_11 |= V_56 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
}
}
F_23 ( V_30 ) ;
break;
case V_73 :
if ( V_3 != 1 )
F_17 ( V_2 ,
F_18 ( V_3 ) ,
V_52 | V_53 ) ;
F_8 ( V_74 , V_75 ) ;
V_11 = F_4 ( V_8 -> V_44 ) ;
if ( ( V_11 & V_54 ) != 0 ) {
F_8 ( V_8 -> V_44 ,
V_11 & ~ V_54 ) ;
F_8 ( V_8 -> V_55 , F_4 ( V_8 -> V_55 ) ) ;
F_4 ( V_8 -> V_55 ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_56 ) != 0 ) {
V_11 &= ~ V_56 ;
V_11 |= V_57 | V_58 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_4 ( V_8 -> V_13 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_11 = F_4 ( V_8 -> V_59 ) ;
if ( V_11 & V_60 ) {
if ( ( V_3 != 1 && ! ( ( F_4 ( V_61 )
| F_4 ( V_62 ) ) & V_56 ) )
|| V_3 == 1 ) {
V_11 &= ~ ( V_60 ) ;
F_8 ( V_8 -> V_59 , V_11 ) ;
F_4 ( V_8 -> V_59 ) ;
F_19 ( 500 ) ;
}
}
break;
}
F_15 ( V_2 ) ;
}
static const struct V_76 * F_24 ( struct V_29 * V_30 )
{
const struct V_76 * V_77 = NULL ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_25 ( V_30 , V_78 )
|| F_25 ( V_30 , V_79 ) ) {
if ( ( V_80 == V_81 ) || ( V_80 == V_82 ) )
V_77 = & V_83 [ V_84 ] ;
else if ( V_80 == V_85 )
V_77 = & V_83 [ V_86 ] ;
else if ( ( V_80 == V_87 ) &&
( V_5 -> V_88 == 166 ) )
V_77 = & V_83 [ V_89 ] ;
else if ( ( V_80 == V_87 ) &&
( V_5 -> V_88 == 100 ||
V_5 -> V_88 == 200 ) )
V_77 = & V_83 [ V_90 ] ;
} else if ( F_25 ( V_30 , V_91 ) ) {
if ( ( V_80 == V_81 ) || ( V_80 == V_82 ) )
V_77 = & V_83 [ V_92 ] ;
else if ( V_80 == V_85 )
V_77 = & V_83 [ V_93 ] ;
else if ( ( V_80 == V_87 ) &&
( V_5 -> V_88 == 166 ) )
V_77 = & V_83 [ V_94 ] ;
else if ( ( V_80 == V_87 ) &&
( V_5 -> V_88 == 100 ||
V_5 -> V_88 == 200 ) )
V_77 = & V_83 [ V_95 ] ;
} else {
V_77 = NULL ;
F_13 ( V_2 -> V_2 , L_10 ) ;
}
return V_77 ;
}
static void F_26 ( int V_96 , struct V_97 * clock )
{
clock -> V_98 = ( V_96 * clock -> V_99 ) / clock -> V_100 ;
}
static bool
F_27 ( struct V_29 * V_30 , int V_101 , int V_96 ,
struct V_97 * V_102 )
{
struct V_97 clock ;
const struct V_76 * V_77 = F_24 ( V_30 ) ;
int V_103 = V_101 ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
for ( clock . V_99 = V_77 -> V_99 . V_104 ; clock . V_99 <= V_77 -> V_99 . V_105 ; clock . V_99 ++ ) {
for ( clock . V_100 = V_77 -> V_100 . V_104 ; clock . V_100 <= V_77 -> V_100 . V_105 ;
clock . V_100 ++ ) {
int V_106 ;
F_26 ( V_96 , & clock ) ;
V_106 = abs ( clock . V_98 - V_101 ) ;
if ( V_106 < V_103 ) {
* V_102 = clock ;
V_103 = V_106 ;
}
}
}
return V_103 != V_101 ;
}
static int F_28 ( struct V_29 * V_30 ,
struct V_107 * V_64 ,
struct V_107 * V_108 ,
int V_31 , int V_32 ,
struct V_25 * V_33 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_34 * V_34 = F_11 ( V_30 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_3 = V_34 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
int V_96 = 0 ;
int V_109 = 0 , V_110 = 0 , V_111 = 1 , V_112 = 0 , V_113 = 0 ,
V_114 = 0 ;
struct V_97 clock ;
bool V_115 ;
T_1 V_59 = 0 , V_116 = 0 ;
bool V_117 = false , V_118 = false , V_119 = false ;
struct V_120 * V_121 = & V_2 -> V_121 ;
struct V_122 * V_122 = NULL ;
T_2 V_123 = V_124 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
int V_66 = 0 ;
int V_40 ;
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
V_40 = F_9 ( V_30 -> V_37 -> V_26 ) ;
if ( V_40 )
return V_40 ;
F_13 ( V_2 -> V_2 , L_12 ,
V_108 -> V_129 ) ;
F_13 ( V_2 -> V_2 , L_13 ,
V_108 -> V_130 ) ;
F_13 ( V_2 -> V_2 , L_14 ,
V_108 -> V_131 ) ;
F_13 ( V_2 -> V_2 , L_15 ,
V_108 -> V_132 ) ;
F_13 ( V_2 -> V_2 , L_16 ,
V_108 -> V_133 ) ;
F_13 ( V_2 -> V_2 , L_17 ,
V_108 -> V_134 ) ;
F_13 ( V_2 -> V_2 , L_18 ,
V_108 -> V_135 ) ;
F_13 ( V_2 -> V_2 , L_19 ,
V_108 -> V_136 ) ;
F_13 ( V_2 -> V_2 , L_20 ,
V_108 -> clock ) ;
F_13 ( V_2 -> V_2 , L_21 ,
V_64 -> V_129 ) ;
F_13 ( V_2 -> V_2 , L_22 ,
V_64 -> V_130 ) ;
if ( ! F_14 ( V_2 , true ) )
return 0 ;
memcpy ( & V_34 -> V_137 , V_64 ,
sizeof( struct V_107 ) ) ;
memcpy ( & V_34 -> V_138 , V_108 ,
sizeof( struct V_107 ) ) ;
F_29 (connector, &mode_config->connector_list, head) {
if ( ! V_128 )
continue;
V_126 = V_128 -> V_126 ;
if ( ! V_126 )
continue;
if ( V_126 -> V_30 != V_30 )
continue;
V_122 = F_30 ( V_128 ) ;
switch ( V_122 -> type ) {
case V_78 :
V_117 = true ;
break;
case V_79 :
V_118 = true ;
break;
case V_91 :
V_119 = true ;
break;
}
}
F_8 ( V_74 , V_75 ) ;
if ( F_6 ( V_2 ) == V_3 )
F_8 ( V_16 , 0 ) ;
if ( V_3 == 1 ) {
F_8 ( V_8 -> V_139 , ( ( V_104 ( V_64 -> V_140 , V_108 -> V_140 ) - 1 ) << 16 )
| ( V_104 ( V_64 -> V_141 , V_108 -> V_141 ) - 1 ) ) ;
F_8 ( V_8 -> V_142 , ( ( V_64 -> V_141 - 1 ) << 16 )
| ( V_64 -> V_140 - 1 ) ) ;
} else {
F_8 ( V_8 -> V_139 ,
( ( V_64 -> V_140 - 1 ) << 16 ) |
( V_64 -> V_141 - 1 ) ) ;
F_8 ( V_8 -> V_142 ,
( ( V_64 -> V_141 - 1 ) << 16 ) |
( V_64 -> V_140 - 1 ) ) ;
}
F_8 ( V_8 -> V_143 , 0 ) ;
if ( V_122 )
F_31 ( & V_128 -> V_55 ,
V_2 -> V_121 . V_144 , & V_123 ) ;
if ( V_123 == V_145 ) {
int V_146 = 0 , V_147 = 0 ;
V_146 = ( V_108 -> V_141 -
V_64 -> V_141 ) / 2 ;
V_147 = ( V_108 -> V_140 -
V_64 -> V_140 ) / 2 ;
F_8 ( V_8 -> V_133 , ( V_64 -> V_141 - 1 ) |
( ( V_108 -> V_148 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_136 , ( V_64 -> V_140 - 1 ) |
( ( V_108 -> V_149 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_150 , ( V_108 -> V_151 -
V_146 - 1 ) |
( ( V_108 -> V_152 - V_146 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_153 , ( V_108 -> V_154 -
V_146 - 1 ) |
( ( V_108 -> V_155 - V_146 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_156 , ( V_108 -> V_157 -
V_147 - 1 ) |
( ( V_108 -> V_158 - V_147 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_159 , ( V_108 -> V_160 -
V_147 - 1 ) |
( ( V_108 -> V_161 - V_147 - 1 ) << 16 ) ) ;
} else {
F_8 ( V_8 -> V_133 , ( V_108 -> V_141 - 1 ) |
( ( V_108 -> V_148 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_136 , ( V_108 -> V_140 - 1 ) |
( ( V_108 -> V_149 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_150 , ( V_108 -> V_151 - 1 ) |
( ( V_108 -> V_152 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_153 , ( V_108 -> V_154 - 1 ) |
( ( V_108 -> V_155 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_156 , ( V_108 -> V_157 - 1 ) |
( ( V_108 -> V_158 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_159 , ( V_108 -> V_160 - 1 ) |
( ( V_108 -> V_161 - 1 ) << 16 ) ) ;
}
{
struct V_162 * V_163 =
V_30 -> V_164 ;
V_163 -> V_165 ( V_30 , V_31 , V_32 , V_33 ) ;
}
V_5 -> V_65 [ V_3 ] = V_56 ;
V_5 -> V_22 [ V_3 ] = F_4 ( V_8 -> V_44 ) ;
V_5 -> V_22 [ V_3 ] |= V_3 << V_166 ;
V_5 -> V_22 [ V_3 ] |= V_54 ;
if ( V_118 )
goto V_167;
V_112 = V_108 -> clock ;
if ( V_119 ) {
if ( ( V_80 == V_81 ) || ( V_80 == V_82 ) ) {
V_96 = 19200 ;
if ( V_117 || V_118 )
V_109 = 1 , V_110 = 8 ;
else if ( V_119 )
V_109 = 1 , V_110 = 10 ;
} else if ( V_80 == V_85 ) {
V_96 = 25000 ;
if ( V_117 || V_118 )
V_109 = 1 , V_110 = 8 ;
else if ( V_119 )
V_109 = 1 , V_110 = 10 ;
} else if ( ( V_80 == V_87 ) &&
V_5 -> V_88 == 166 ) {
V_96 = 83000 ;
if ( V_117 || V_118 )
V_109 = 4 , V_110 = 8 ;
else if ( V_119 )
V_109 = 4 , V_110 = 10 ;
} else if ( ( V_80 == V_87 ) &&
( V_5 -> V_88 == 100 ||
V_5 -> V_88 == 200 ) ) {
V_96 = 100000 ;
if ( V_117 || V_118 )
V_109 = 4 , V_110 = 8 ;
else if ( V_119 )
V_109 = 4 , V_110 = 10 ;
}
if ( V_117 )
V_111 = V_5 -> V_168 / 8 ;
else if ( V_118 )
V_111 = V_5 -> V_169 / 8 ;
V_114 = V_112 * V_109 * V_110 * V_111 ;
F_13 ( V_2 -> V_2 , L_23 ,
V_112 , V_109 , V_110 ) ;
F_13 ( V_2 -> V_2 , L_24 ,
V_108 -> clock , V_114 ) ;
V_115 = F_27 ( V_30 , V_114 , V_96 , & clock ) ;
if ( ! V_115 ) {
F_2
( L_25 ) ;
} else {
V_113 = V_170 [ ( clock . V_99 - V_171 ) ] ;
F_13 ( V_2 -> V_2 , L_26
L_27 ,
clock . V_98 , clock . V_99 ,
clock . V_100 , V_113 ) ;
}
V_59 = F_4 ( V_8 -> V_59 ) ;
if ( V_59 & V_60 ) {
V_59 &= ~ V_60 ;
F_8 ( V_8 -> V_59 , V_59 ) ;
F_4 ( V_8 -> V_59 ) ;
F_19 ( 500 ) ;
F_8 ( V_8 -> V_172 , 0 ) ;
V_59 &= ~ V_173 ;
F_8 ( V_8 -> V_59 , V_59 ) ;
F_19 ( 500 ) ;
}
if ( V_59 & V_63 ) {
V_59 &= ~ V_63 ;
F_8 ( V_8 -> V_59 , V_59 ) ;
F_19 ( 500 ) ;
}
V_59 = 0 ;
#if 0
if (ksel == KSEL_CRYSTAL_19 || ksel == KSEL_BYPASS_19 ||
ksel == KSEL_BYPASS_25)
dpll &= ~MDFLD_INPUT_REF_SEL;
else if (ksel == KSEL_BYPASS_83_100)
dpll |= MDFLD_INPUT_REF_SEL;
#endif
if ( V_119 )
V_59 |= V_174 ;
V_116 = ( V_109 / 2 ) << 16 ;
V_116 |= V_113 ;
V_59 |= ( 1 << ( clock . V_100 - 2 ) ) << 17 ;
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
V_59 = 0x00800000 ;
V_116 = 0x000000c1 ;
}
F_8 ( V_8 -> V_172 , V_116 ) ;
F_8 ( V_8 -> V_59 , V_59 ) ;
F_19 ( 500 ) ;
V_59 |= V_60 ;
F_8 ( V_8 -> V_59 , V_59 ) ;
F_4 ( V_8 -> V_59 ) ;
while ( V_66 < 20000 &&
! ( F_4 ( V_8 -> V_13 ) & V_70 ) ) {
F_19 ( 150 ) ;
V_66 ++ ;
}
if ( V_117 )
goto V_167;
F_13 ( V_2 -> V_2 , L_28 , V_117 ) ;
F_8 ( V_8 -> V_13 , V_5 -> V_65 [ V_3 ] ) ;
F_4 ( V_8 -> V_13 ) ;
F_8 ( V_8 -> V_44 , V_5 -> V_22 [ V_3 ] ) ;
F_3 ( V_2 ) ;
V_167:
F_15 ( V_2 ) ;
return 0 ;
}
