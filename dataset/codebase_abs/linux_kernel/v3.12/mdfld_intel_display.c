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
struct V_35 * V_36 = F_12 ( V_30 -> V_26 ) ;
int V_3 = V_34 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
unsigned long V_37 , V_38 ;
T_1 V_22 ;
int V_39 ;
memcpy ( & V_19 , V_2 , sizeof( struct V_1 ) ) ;
F_13 ( V_2 -> V_2 , L_3 , V_3 ) ;
if ( ! V_30 -> V_26 ) {
F_13 ( V_2 -> V_2 , L_4 ) ;
return 0 ;
}
V_39 = F_9 ( V_30 -> V_26 ) ;
if ( V_39 )
return V_39 ;
if ( V_3 > 2 ) {
F_2 ( L_1 ) ;
return - V_28 ;
}
if ( ! F_14 ( V_2 , true ) )
return 0 ;
V_37 = V_36 -> V_40 -> V_38 ;
V_38 = V_32 * V_30 -> V_26 -> V_41 [ 0 ] + V_31 * ( V_30 -> V_26 -> V_27 / 8 ) ;
F_8 ( V_8 -> V_42 , V_30 -> V_26 -> V_41 [ 0 ] ) ;
V_22 = F_4 ( V_8 -> V_43 ) ;
V_22 &= ~ V_44 ;
switch ( V_30 -> V_26 -> V_27 ) {
case 8 :
V_22 |= V_45 ;
break;
case 16 :
if ( V_30 -> V_26 -> V_46 == 15 )
V_22 |= V_47 ;
else
V_22 |= V_48 ;
break;
case 24 :
case 32 :
V_22 |= V_23 ;
break;
}
F_8 ( V_8 -> V_43 , V_22 ) ;
F_13 ( V_2 -> V_2 , L_5 ,
V_37 , V_38 , V_31 , V_32 ) ;
F_8 ( V_8 -> V_49 , V_38 ) ;
F_4 ( V_8 -> V_49 ) ;
F_8 ( V_8 -> V_50 , V_37 ) ;
F_4 ( V_8 -> V_50 ) ;
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
V_51 | V_52 ) ;
V_11 = F_4 ( V_8 -> V_43 ) ;
if ( ( V_11 & V_53 ) != 0 ) {
F_8 ( V_8 -> V_43 ,
V_11 & ~ V_53 ) ;
F_8 ( V_8 -> V_54 , F_4 ( V_8 -> V_54 ) ) ;
F_4 ( V_8 -> V_54 ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_55 ) != 0 ) {
V_11 &= ~ V_55 ;
V_11 |= V_56 | V_57 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_4 ( V_8 -> V_13 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_11 = F_4 ( V_8 -> V_58 ) ;
if ( V_11 & V_59 ) {
if ( ( V_3 != 1 &&
! ( ( F_4 ( V_60 ) | F_4 ( V_61 ) )
& V_55 ) ) || V_3 == 1 ) {
V_11 &= ~ ( V_59 ) ;
F_8 ( V_8 -> V_58 , V_11 ) ;
F_4 ( V_8 -> V_58 ) ;
F_19 ( 500 ) ;
if ( ! ( V_11 & V_62 ) ) {
F_8 ( V_8 -> V_58 , V_11 | V_62 ) ;
F_19 ( 5000 ) ;
}
}
}
}
static void F_20 ( struct V_29 * V_30 , int V_63 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_34 * V_34 = F_11 ( V_30 ) ;
int V_3 = V_34 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
T_1 V_64 = V_5 -> V_64 [ V_3 ] ;
T_1 V_11 ;
int V_65 = 0 ;
F_13 ( V_2 -> V_2 , L_7 , V_63 , V_3 ) ;
if ( ! F_14 ( V_2 , true ) )
return;
switch ( V_63 ) {
case V_66 :
case V_67 :
case V_68 :
V_11 = F_4 ( V_8 -> V_58 ) ;
if ( ( V_11 & V_59 ) == 0 ) {
if ( V_11 & V_62 ) {
V_11 &= ~ V_62 ;
F_8 ( V_8 -> V_58 , V_11 ) ;
F_19 ( 500 ) ;
}
F_8 ( V_8 -> V_58 , V_11 ) ;
F_4 ( V_8 -> V_58 ) ;
F_19 ( 500 ) ;
F_8 ( V_8 -> V_58 , V_11 | V_59 ) ;
F_4 ( V_8 -> V_58 ) ;
while ( ( V_3 != 2 ) && ( V_65 < 20000 ) &&
! ( F_4 ( V_8 -> V_13 ) & V_69 ) ) {
F_19 ( 150 ) ;
V_65 ++ ;
}
}
V_11 = F_4 ( V_8 -> V_43 ) ;
if ( ( V_11 & V_53 ) == 0 ) {
F_8 ( V_8 -> V_43 ,
V_11 | V_53 ) ;
F_8 ( V_8 -> V_54 , F_4 ( V_8 -> V_54 ) ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_55 ) == 0 ) {
F_8 ( V_8 -> V_13 , V_64 ) ;
F_5 ( V_2 , V_3 ) ;
}
if ( V_3 == 0 || V_3 == 2 ) {
F_8 ( V_8 -> V_70 , F_4 ( V_8 -> V_70 ) ) ;
F_21 ( 100 ) ;
if ( V_71 & F_4 ( V_8 -> V_70 ) )
F_13 ( V_2 -> V_2 , L_8 ) ;
else {
F_13 ( V_2 -> V_2 , L_9 ) ;
V_11 = F_4 ( V_8 -> V_43 ) ;
F_8 ( V_8 -> V_43 ,
V_11 & ~ V_53 ) ;
F_8 ( V_8 -> V_54 , F_4 ( V_8 -> V_54 ) ) ;
F_8 ( 0xb048 , 1 ) ;
F_21 ( 100 ) ;
V_11 = F_4 ( V_8 -> V_13 ) ;
V_11 &= ~ V_55 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_21 ( 100 ) ;
F_8 ( F_22 ( V_3 ) , 0 ) ;
F_21 ( 100 ) ;
F_8 ( 0xb004 , F_4 ( 0xb004 ) ) ;
F_8 ( F_22 ( V_3 ) , 1 ) ;
V_11 = F_4 ( V_8 -> V_43 ) ;
F_8 ( V_8 -> V_43 ,
V_11 | V_53 ) ;
F_8 ( V_8 -> V_54 , F_4 ( V_8 -> V_54 ) ) ;
F_8 ( 0xb048 , 2 ) ;
F_21 ( 100 ) ;
V_11 = F_4 ( V_8 -> V_13 ) ;
V_11 |= V_55 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
}
}
F_23 ( V_30 ) ;
break;
case V_72 :
if ( V_3 != 1 )
F_17 ( V_2 ,
F_18 ( V_3 ) ,
V_51 | V_52 ) ;
F_8 ( V_73 , V_74 ) ;
V_11 = F_4 ( V_8 -> V_43 ) ;
if ( ( V_11 & V_53 ) != 0 ) {
F_8 ( V_8 -> V_43 ,
V_11 & ~ V_53 ) ;
F_8 ( V_8 -> V_54 , F_4 ( V_8 -> V_54 ) ) ;
F_4 ( V_8 -> V_54 ) ;
}
V_11 = F_4 ( V_8 -> V_13 ) ;
if ( ( V_11 & V_55 ) != 0 ) {
V_11 &= ~ V_55 ;
V_11 |= V_56 | V_57 ;
F_8 ( V_8 -> V_13 , V_11 ) ;
F_4 ( V_8 -> V_13 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_11 = F_4 ( V_8 -> V_58 ) ;
if ( V_11 & V_59 ) {
if ( ( V_3 != 1 && ! ( ( F_4 ( V_60 )
| F_4 ( V_61 ) ) & V_55 ) )
|| V_3 == 1 ) {
V_11 &= ~ ( V_59 ) ;
F_8 ( V_8 -> V_58 , V_11 ) ;
F_4 ( V_8 -> V_58 ) ;
F_19 ( 500 ) ;
}
}
break;
}
F_15 ( V_2 ) ;
}
static const struct V_75 * F_24 ( struct V_29 * V_30 )
{
const struct V_75 * V_76 = NULL ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_25 ( V_30 , V_77 )
|| F_25 ( V_30 , V_78 ) ) {
if ( ( V_79 == V_80 ) || ( V_79 == V_81 ) )
V_76 = & V_82 [ V_83 ] ;
else if ( V_79 == V_84 )
V_76 = & V_82 [ V_85 ] ;
else if ( ( V_79 == V_86 ) &&
( V_5 -> V_87 == 166 ) )
V_76 = & V_82 [ V_88 ] ;
else if ( ( V_79 == V_86 ) &&
( V_5 -> V_87 == 100 ||
V_5 -> V_87 == 200 ) )
V_76 = & V_82 [ V_89 ] ;
} else if ( F_25 ( V_30 , V_90 ) ) {
if ( ( V_79 == V_80 ) || ( V_79 == V_81 ) )
V_76 = & V_82 [ V_91 ] ;
else if ( V_79 == V_84 )
V_76 = & V_82 [ V_92 ] ;
else if ( ( V_79 == V_86 ) &&
( V_5 -> V_87 == 166 ) )
V_76 = & V_82 [ V_93 ] ;
else if ( ( V_79 == V_86 ) &&
( V_5 -> V_87 == 100 ||
V_5 -> V_87 == 200 ) )
V_76 = & V_82 [ V_94 ] ;
} else {
V_76 = NULL ;
F_13 ( V_2 -> V_2 , L_10 ) ;
}
return V_76 ;
}
static void F_26 ( int V_95 , struct V_96 * clock )
{
clock -> V_97 = ( V_95 * clock -> V_98 ) / clock -> V_99 ;
}
static bool
F_27 ( struct V_29 * V_30 , int V_100 , int V_95 ,
struct V_96 * V_101 )
{
struct V_96 clock ;
const struct V_75 * V_76 = F_24 ( V_30 ) ;
int V_102 = V_100 ;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
for ( clock . V_98 = V_76 -> V_98 . V_103 ; clock . V_98 <= V_76 -> V_98 . V_104 ; clock . V_98 ++ ) {
for ( clock . V_99 = V_76 -> V_99 . V_103 ; clock . V_99 <= V_76 -> V_99 . V_104 ;
clock . V_99 ++ ) {
int V_105 ;
F_26 ( V_95 , & clock ) ;
V_105 = abs ( clock . V_97 - V_100 ) ;
if ( V_105 < V_102 ) {
* V_101 = clock ;
V_102 = V_105 ;
}
}
}
return V_102 != V_100 ;
}
static int F_28 ( struct V_29 * V_30 ,
struct V_106 * V_63 ,
struct V_106 * V_107 ,
int V_31 , int V_32 ,
struct V_25 * V_33 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_34 * V_34 = F_11 ( V_30 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_3 = V_34 -> V_3 ;
const struct V_7 * V_8 = & V_5 -> V_9 [ V_3 ] ;
int V_95 = 0 ;
int V_108 = 0 , V_109 = 0 , V_110 = 1 , V_111 = 0 , V_112 = 0 ,
V_113 = 0 ;
struct V_96 clock ;
bool V_114 ;
T_1 V_58 = 0 , V_115 = 0 ;
bool V_116 = false , V_117 = false , V_118 = false ;
struct V_119 * V_120 = & V_2 -> V_120 ;
struct V_121 * V_121 = NULL ;
T_2 V_122 = V_123 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
int V_65 = 0 ;
int V_39 ;
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
V_39 = F_9 ( V_30 -> V_26 ) ;
if ( V_39 )
return V_39 ;
F_13 ( V_2 -> V_2 , L_12 ,
V_107 -> V_128 ) ;
F_13 ( V_2 -> V_2 , L_13 ,
V_107 -> V_129 ) ;
F_13 ( V_2 -> V_2 , L_14 ,
V_107 -> V_130 ) ;
F_13 ( V_2 -> V_2 , L_15 ,
V_107 -> V_131 ) ;
F_13 ( V_2 -> V_2 , L_16 ,
V_107 -> V_132 ) ;
F_13 ( V_2 -> V_2 , L_17 ,
V_107 -> V_133 ) ;
F_13 ( V_2 -> V_2 , L_18 ,
V_107 -> V_134 ) ;
F_13 ( V_2 -> V_2 , L_19 ,
V_107 -> V_135 ) ;
F_13 ( V_2 -> V_2 , L_20 ,
V_107 -> clock ) ;
F_13 ( V_2 -> V_2 , L_21 ,
V_63 -> V_128 ) ;
F_13 ( V_2 -> V_2 , L_22 ,
V_63 -> V_129 ) ;
if ( ! F_14 ( V_2 , true ) )
return 0 ;
memcpy ( & V_34 -> V_136 , V_63 ,
sizeof( struct V_106 ) ) ;
memcpy ( & V_34 -> V_137 , V_107 ,
sizeof( struct V_106 ) ) ;
F_29 (connector, &mode_config->connector_list, head) {
if ( ! V_127 )
continue;
V_125 = V_127 -> V_125 ;
if ( ! V_125 )
continue;
if ( V_125 -> V_30 != V_30 )
continue;
V_121 = F_30 ( V_127 ) ;
switch ( V_121 -> type ) {
case V_77 :
V_116 = true ;
break;
case V_78 :
V_117 = true ;
break;
case V_90 :
V_118 = true ;
break;
}
}
F_8 ( V_73 , V_74 ) ;
if ( F_6 ( V_2 ) == V_3 )
F_8 ( V_16 , 0 ) ;
if ( V_3 == 1 ) {
F_8 ( V_8 -> V_138 , ( ( V_103 ( V_63 -> V_139 , V_107 -> V_139 ) - 1 ) << 16 )
| ( V_103 ( V_63 -> V_140 , V_107 -> V_140 ) - 1 ) ) ;
F_8 ( V_8 -> V_141 , ( ( V_63 -> V_140 - 1 ) << 16 )
| ( V_63 -> V_139 - 1 ) ) ;
} else {
F_8 ( V_8 -> V_138 ,
( ( V_63 -> V_139 - 1 ) << 16 ) |
( V_63 -> V_140 - 1 ) ) ;
F_8 ( V_8 -> V_141 ,
( ( V_63 -> V_140 - 1 ) << 16 ) |
( V_63 -> V_139 - 1 ) ) ;
}
F_8 ( V_8 -> V_142 , 0 ) ;
if ( V_121 )
F_31 ( & V_127 -> V_54 ,
V_2 -> V_120 . V_143 , & V_122 ) ;
if ( V_122 == V_144 ) {
int V_145 = 0 , V_146 = 0 ;
V_145 = ( V_107 -> V_140 -
V_63 -> V_140 ) / 2 ;
V_146 = ( V_107 -> V_139 -
V_63 -> V_139 ) / 2 ;
F_8 ( V_8 -> V_132 , ( V_63 -> V_140 - 1 ) |
( ( V_107 -> V_147 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_135 , ( V_63 -> V_139 - 1 ) |
( ( V_107 -> V_148 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_149 , ( V_107 -> V_150 -
V_145 - 1 ) |
( ( V_107 -> V_151 - V_145 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_152 , ( V_107 -> V_153 -
V_145 - 1 ) |
( ( V_107 -> V_154 - V_145 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_155 , ( V_107 -> V_156 -
V_146 - 1 ) |
( ( V_107 -> V_157 - V_146 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_158 , ( V_107 -> V_159 -
V_146 - 1 ) |
( ( V_107 -> V_160 - V_146 - 1 ) << 16 ) ) ;
} else {
F_8 ( V_8 -> V_132 , ( V_107 -> V_140 - 1 ) |
( ( V_107 -> V_147 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_135 , ( V_107 -> V_139 - 1 ) |
( ( V_107 -> V_148 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_149 , ( V_107 -> V_150 - 1 ) |
( ( V_107 -> V_151 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_152 , ( V_107 -> V_153 - 1 ) |
( ( V_107 -> V_154 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_155 , ( V_107 -> V_156 - 1 ) |
( ( V_107 -> V_157 - 1 ) << 16 ) ) ;
F_8 ( V_8 -> V_158 , ( V_107 -> V_159 - 1 ) |
( ( V_107 -> V_160 - 1 ) << 16 ) ) ;
}
{
struct V_161 * V_162 =
V_30 -> V_163 ;
V_162 -> V_164 ( V_30 , V_31 , V_32 , V_33 ) ;
}
V_5 -> V_64 [ V_3 ] = V_55 ;
V_5 -> V_22 [ V_3 ] = F_4 ( V_8 -> V_43 ) ;
V_5 -> V_22 [ V_3 ] |= V_3 << V_165 ;
V_5 -> V_22 [ V_3 ] |= V_53 ;
if ( V_117 )
goto V_166;
V_111 = V_107 -> clock ;
if ( V_118 ) {
if ( ( V_79 == V_80 ) || ( V_79 == V_81 ) ) {
V_95 = 19200 ;
if ( V_116 || V_117 )
V_108 = 1 , V_109 = 8 ;
else if ( V_118 )
V_108 = 1 , V_109 = 10 ;
} else if ( V_79 == V_84 ) {
V_95 = 25000 ;
if ( V_116 || V_117 )
V_108 = 1 , V_109 = 8 ;
else if ( V_118 )
V_108 = 1 , V_109 = 10 ;
} else if ( ( V_79 == V_86 ) &&
V_5 -> V_87 == 166 ) {
V_95 = 83000 ;
if ( V_116 || V_117 )
V_108 = 4 , V_109 = 8 ;
else if ( V_118 )
V_108 = 4 , V_109 = 10 ;
} else if ( ( V_79 == V_86 ) &&
( V_5 -> V_87 == 100 ||
V_5 -> V_87 == 200 ) ) {
V_95 = 100000 ;
if ( V_116 || V_117 )
V_108 = 4 , V_109 = 8 ;
else if ( V_118 )
V_108 = 4 , V_109 = 10 ;
}
if ( V_116 )
V_110 = V_5 -> V_167 / 8 ;
else if ( V_117 )
V_110 = V_5 -> V_168 / 8 ;
V_113 = V_111 * V_108 * V_109 * V_110 ;
F_13 ( V_2 -> V_2 , L_23 ,
V_111 , V_108 , V_109 ) ;
F_13 ( V_2 -> V_2 , L_24 ,
V_107 -> clock , V_113 ) ;
V_114 = F_27 ( V_30 , V_113 , V_95 , & clock ) ;
if ( ! V_114 ) {
F_2
( L_25 ) ;
} else {
V_112 = V_169 [ ( clock . V_98 - V_170 ) ] ;
F_13 ( V_2 -> V_2 , L_26
L_27 ,
clock . V_97 , clock . V_98 ,
clock . V_99 , V_112 ) ;
}
V_58 = F_4 ( V_8 -> V_58 ) ;
if ( V_58 & V_59 ) {
V_58 &= ~ V_59 ;
F_8 ( V_8 -> V_58 , V_58 ) ;
F_4 ( V_8 -> V_58 ) ;
F_19 ( 500 ) ;
F_8 ( V_8 -> V_171 , 0 ) ;
V_58 &= ~ V_172 ;
F_8 ( V_8 -> V_58 , V_58 ) ;
F_19 ( 500 ) ;
}
if ( V_58 & V_62 ) {
V_58 &= ~ V_62 ;
F_8 ( V_8 -> V_58 , V_58 ) ;
F_19 ( 500 ) ;
}
V_58 = 0 ;
#if 0
if (ksel == KSEL_CRYSTAL_19 || ksel == KSEL_BYPASS_19 ||
ksel == KSEL_BYPASS_25)
dpll &= ~MDFLD_INPUT_REF_SEL;
else if (ksel == KSEL_BYPASS_83_100)
dpll |= MDFLD_INPUT_REF_SEL;
#endif
if ( V_118 )
V_58 |= V_173 ;
V_115 = ( V_108 / 2 ) << 16 ;
V_115 |= V_112 ;
V_58 |= ( 1 << ( clock . V_99 - 2 ) ) << 17 ;
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
V_58 = 0x00800000 ;
V_115 = 0x000000c1 ;
}
F_8 ( V_8 -> V_171 , V_115 ) ;
F_8 ( V_8 -> V_58 , V_58 ) ;
F_19 ( 500 ) ;
V_58 |= V_59 ;
F_8 ( V_8 -> V_58 , V_58 ) ;
F_4 ( V_8 -> V_58 ) ;
while ( V_65 < 20000 &&
! ( F_4 ( V_8 -> V_13 ) & V_69 ) ) {
F_19 ( 150 ) ;
V_65 ++ ;
}
if ( V_116 )
goto V_166;
F_13 ( V_2 -> V_2 , L_28 , V_116 ) ;
F_8 ( V_8 -> V_13 , V_5 -> V_64 [ V_3 ] ) ;
F_4 ( V_8 -> V_13 ) ;
F_8 ( V_8 -> V_43 , V_5 -> V_22 [ V_3 ] ) ;
F_3 ( V_2 ) ;
V_166:
F_15 ( V_2 ) ;
return 0 ;
}
