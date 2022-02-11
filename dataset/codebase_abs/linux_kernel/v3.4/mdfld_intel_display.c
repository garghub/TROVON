void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
T_1 V_6 = V_7 ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_6 = V_8 ;
break;
case 2 :
V_6 = V_9 ;
break;
default:
F_2 ( L_1 ) ;
return;
}
F_3 ( V_2 ) ;
return;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_11 ) == 0 )
break;
}
}
void F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
T_1 V_6 = V_7 ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_6 = V_8 ;
break;
case 2 :
V_6 = V_9 ;
break;
default:
F_2 ( L_1 ) ;
return;
}
F_3 ( V_2 ) ;
return;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_11 ) == 1 )
break;
}
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
V_15 -> V_17 ( V_13 , V_18 ) ;
}
static void F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
V_15 -> V_17 ( V_13 , V_19 ) ;
}
static bool F_8 ( struct V_12 * V_13 ,
struct V_20 * V_21 ,
struct V_20 * V_22 )
{
return true ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_23 ;
V_23 = F_4 ( V_24 ) ;
if ( ( V_23 & V_25 ) == 0 )
return - 1 ;
return ( V_23 >> 29 ) & 0x3 ;
}
void F_10 ( int V_26 )
{
struct V_1 * V_2 = & V_27 ;
int V_28 = V_29 ;
T_1 V_30 ;
V_30 = F_4 ( V_28 ) ;
if ( V_26 ) {
V_30 &= ~ V_31 ;
V_30 |= V_32 ;
} else {
V_30 &= ~ V_32 ;
V_30 |= V_31 ;
}
F_11 ( V_28 , V_30 ) ;
}
static int F_12 ( struct V_33 * V_34 )
{
if ( ! V_34 )
return 0 ;
switch ( V_34 -> V_35 ) {
case 8 :
case 16 :
case 24 :
case 32 :
return 0 ;
default:
F_2 ( L_2 ) ;
return - V_36 ;
}
}
static int F_13 ( struct V_12 * V_13 , int V_37 , int V_38 ,
struct V_33 * V_39 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_40 * V_40 = F_14 ( V_13 ) ;
struct V_41 * V_42 = F_15 ( V_13 -> V_34 ) ;
int V_3 = V_40 -> V_3 ;
unsigned long V_43 , V_44 ;
int V_45 = V_46 ;
int V_47 = V_48 ;
int V_49 = V_50 ;
int V_28 = V_29 ;
T_1 V_30 ;
int V_51 ;
memcpy ( & V_27 , V_2 , sizeof( struct V_1 ) ) ;
F_16 ( V_2 -> V_2 , L_3 , V_3 ) ;
if ( ! V_13 -> V_34 ) {
F_16 ( V_2 -> V_2 , L_4 ) ;
return 0 ;
}
V_51 = F_12 ( V_13 -> V_34 ) ;
if ( V_51 )
return V_51 ;
switch ( V_3 ) {
case 0 :
V_45 = V_46 ;
break;
case 1 :
V_45 = V_52 ;
V_47 = V_53 ;
V_49 = V_54 ;
V_28 = V_55 ;
break;
case 2 :
V_45 = V_56 ;
V_47 = V_57 ;
V_49 = V_58 ;
V_28 = V_59 ;
break;
default:
F_2 ( L_1 ) ;
return - V_36 ;
}
if ( ! F_17 ( V_2 , true ) )
return 0 ;
V_43 = V_42 -> V_60 -> V_44 ;
V_44 = V_38 * V_13 -> V_34 -> V_61 [ 0 ] + V_37 * ( V_13 -> V_34 -> V_35 / 8 ) ;
F_11 ( V_49 , V_13 -> V_34 -> V_61 [ 0 ] ) ;
V_30 = F_4 ( V_28 ) ;
V_30 &= ~ V_62 ;
switch ( V_13 -> V_34 -> V_35 ) {
case 8 :
V_30 |= V_63 ;
break;
case 16 :
if ( V_13 -> V_34 -> V_64 == 15 )
V_30 |= V_65 ;
else
V_30 |= V_66 ;
break;
case 24 :
case 32 :
V_30 |= V_31 ;
break;
}
F_11 ( V_28 , V_30 ) ;
F_16 ( V_2 -> V_2 , L_5 ,
V_43 , V_44 , V_37 , V_38 ) ;
F_11 ( V_45 , V_44 ) ;
F_4 ( V_45 ) ;
F_11 ( V_47 , V_43 ) ;
F_4 ( V_47 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 , int V_3 )
{
int V_67 = V_68 ;
int V_28 = V_29 ;
int V_69 = V_70 ;
int V_6 = V_7 ;
T_1 V_5 ;
F_16 ( V_2 -> V_2 , L_6 , V_3 ) ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_67 = V_71 ;
V_28 = V_55 ;
V_69 = V_53 ;
V_6 = V_8 ;
break;
case 2 :
V_67 = V_68 ;
V_28 = V_59 ;
V_69 = V_72 ;
V_6 = V_9 ;
break;
default:
F_2 ( L_1 ) ;
return;
}
if ( V_3 != 1 )
F_20 ( V_2 , F_21 ( V_3 ) ,
V_73 | V_74 ) ;
V_5 = F_4 ( V_28 ) ;
if ( ( V_5 & V_75 ) != 0 ) {
F_11 ( V_28 ,
V_5 & ~ V_75 ) ;
F_11 ( V_69 , F_4 ( V_69 ) ) ;
F_4 ( V_69 ) ;
}
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_76 ) != 0 ) {
V_5 &= ~ V_76 ;
V_5 |= V_77 | V_78 ;
F_11 ( V_6 , V_5 ) ;
F_4 ( V_6 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_5 = F_4 ( V_67 ) ;
if ( V_5 & V_79 ) {
if ( ( V_3 != 1 &&
! ( ( F_4 ( V_7 ) | F_4 ( V_9 ) )
& V_76 ) ) || V_3 == 1 ) {
V_5 &= ~ ( V_79 ) ;
F_11 ( V_67 , V_5 ) ;
F_4 ( V_67 ) ;
F_22 ( 500 ) ;
if ( ! ( V_5 & V_80 ) ) {
F_11 ( V_67 , V_5 | V_80 ) ;
F_22 ( 5000 ) ;
}
}
}
}
static void F_23 ( struct V_12 * V_13 , int V_21 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_81 * V_82 = V_2 -> V_83 ;
struct V_40 * V_40 = F_14 ( V_13 ) ;
int V_3 = V_40 -> V_3 ;
int V_67 = V_68 ;
int V_28 = V_29 ;
int V_69 = V_70 ;
int V_6 = V_7 ;
T_1 V_84 = V_85 ;
T_1 V_86 = V_82 -> V_86 [ V_3 ] ;
T_1 V_5 ;
int V_87 = 0 ;
F_16 ( V_2 -> V_2 , L_7 , V_21 , V_3 ) ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_67 = V_88 ;
V_28 = V_55 ;
V_69 = V_89 ;
V_6 = V_8 ;
V_67 = V_71 ;
break;
case 2 :
V_67 = V_68 ;
V_28 = V_59 ;
V_69 = V_72 ;
V_6 = V_9 ;
V_84 = V_90 ;
break;
default:
F_2 ( L_1 ) ;
return;
}
if ( ! F_17 ( V_2 , true ) )
return;
switch ( V_21 ) {
case V_19 :
case V_91 :
case V_92 :
V_5 = F_4 ( V_67 ) ;
if ( ( V_5 & V_79 ) == 0 ) {
if ( V_5 & V_80 ) {
V_5 &= ~ V_80 ;
F_11 ( V_67 , V_5 ) ;
F_22 ( 500 ) ;
}
F_11 ( V_67 , V_5 ) ;
F_4 ( V_67 ) ;
F_22 ( 500 ) ;
F_11 ( V_67 , V_5 | V_79 ) ;
F_4 ( V_67 ) ;
while ( ( V_3 != 2 ) && ( V_87 < 20000 ) &&
! ( F_4 ( V_6 ) & V_93 ) ) {
F_22 ( 150 ) ;
V_87 ++ ;
}
}
V_5 = F_4 ( V_28 ) ;
if ( ( V_5 & V_75 ) == 0 ) {
F_11 ( V_28 ,
V_5 | V_75 ) ;
F_11 ( V_69 , F_4 ( V_69 ) ) ;
}
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_76 ) == 0 ) {
F_11 ( V_6 , V_86 ) ;
F_5 ( V_2 , V_3 ) ;
}
if ( V_3 == 0 || V_3 == 2 ) {
F_11 ( V_84 , F_4 ( V_84 ) ) ;
F_24 ( 100 ) ;
if ( V_94 & F_4 ( V_84 ) )
F_16 ( V_2 -> V_2 , L_8 ) ;
else {
F_16 ( V_2 -> V_2 , L_9 ) ;
V_5 = F_4 ( V_28 ) ;
F_11 ( V_28 ,
V_5 & ~ V_75 ) ;
F_11 ( V_69 , F_4 ( V_69 ) ) ;
F_11 ( 0xb048 , 1 ) ;
F_24 ( 100 ) ;
V_5 = F_4 ( V_6 ) ;
V_5 &= ~ V_76 ;
F_11 ( V_6 , V_5 ) ;
F_24 ( 100 ) ;
F_11 ( F_25 ( V_3 ) , 0 ) ;
F_24 ( 100 ) ;
F_11 ( 0xb004 , F_4 ( 0xb004 ) ) ;
F_11 ( F_25 ( V_3 ) , 1 ) ;
V_5 = F_4 ( V_28 ) ;
F_11 ( V_28 ,
V_5 | V_75 ) ;
F_11 ( V_69 , F_4 ( V_69 ) ) ;
F_11 ( 0xb048 , 2 ) ;
F_24 ( 100 ) ;
V_5 = F_4 ( V_6 ) ;
V_5 |= V_76 ;
F_11 ( V_6 , V_5 ) ;
}
}
F_26 ( V_13 ) ;
break;
case V_18 :
if ( V_3 != 1 )
F_20 ( V_2 ,
F_21 ( V_3 ) ,
V_73 | V_74 ) ;
F_11 ( V_95 , V_96 ) ;
V_5 = F_4 ( V_28 ) ;
if ( ( V_5 & V_75 ) != 0 ) {
F_11 ( V_28 ,
V_5 & ~ V_75 ) ;
F_11 ( V_69 , F_4 ( V_69 ) ) ;
F_4 ( V_69 ) ;
}
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_76 ) != 0 ) {
V_5 &= ~ V_76 ;
V_5 |= V_77 | V_78 ;
F_11 ( V_6 , V_5 ) ;
F_4 ( V_6 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_5 = F_4 ( V_67 ) ;
if ( V_5 & V_79 ) {
if ( ( V_3 != 1 && ! ( ( F_4 ( V_7 )
| F_4 ( V_9 ) ) & V_76 ) )
|| V_3 == 1 ) {
V_5 &= ~ ( V_79 ) ;
F_11 ( V_67 , V_5 ) ;
F_4 ( V_67 ) ;
F_22 ( 500 ) ;
}
}
break;
}
F_18 ( V_2 ) ;
}
static const struct V_97 * F_27 ( struct V_12 * V_13 )
{
const struct V_97 * V_98 = NULL ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_81 * V_82 = V_2 -> V_83 ;
if ( F_28 ( V_13 , V_99 )
|| F_28 ( V_13 , V_100 ) ) {
if ( ( V_101 == V_102 ) || ( V_101 == V_103 ) )
V_98 = & V_104 [ V_105 ] ;
else if ( V_101 == V_106 )
V_98 = & V_104 [ V_107 ] ;
else if ( ( V_101 == V_108 ) &&
( V_82 -> V_109 == 166 ) )
V_98 = & V_104 [ V_110 ] ;
else if ( ( V_101 == V_108 ) &&
( V_82 -> V_109 == 100 ||
V_82 -> V_109 == 200 ) )
V_98 = & V_104 [ V_111 ] ;
} else if ( F_28 ( V_13 , V_112 ) ) {
if ( ( V_101 == V_102 ) || ( V_101 == V_103 ) )
V_98 = & V_104 [ V_113 ] ;
else if ( V_101 == V_106 )
V_98 = & V_104 [ V_114 ] ;
else if ( ( V_101 == V_108 ) &&
( V_82 -> V_109 == 166 ) )
V_98 = & V_104 [ V_115 ] ;
else if ( ( V_101 == V_108 ) &&
( V_82 -> V_109 == 100 ||
V_82 -> V_109 == 200 ) )
V_98 = & V_104 [ V_116 ] ;
} else {
V_98 = NULL ;
F_16 ( V_2 -> V_2 , L_10 ) ;
}
return V_98 ;
}
static void F_29 ( int V_117 , struct V_118 * clock )
{
clock -> V_119 = ( V_117 * clock -> V_120 ) / clock -> V_121 ;
}
static bool
F_30 ( struct V_12 * V_13 , int V_122 , int V_117 ,
struct V_118 * V_123 )
{
struct V_118 clock ;
const struct V_97 * V_98 = F_27 ( V_13 ) ;
int V_124 = V_122 ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
for ( clock . V_120 = V_98 -> V_120 . V_125 ; clock . V_120 <= V_98 -> V_120 . V_126 ; clock . V_120 ++ ) {
for ( clock . V_121 = V_98 -> V_121 . V_125 ; clock . V_121 <= V_98 -> V_121 . V_126 ;
clock . V_121 ++ ) {
int V_127 ;
F_29 ( V_117 , & clock ) ;
V_127 = abs ( clock . V_119 - V_122 ) ;
if ( V_127 < V_124 ) {
* V_123 = clock ;
V_124 = V_127 ;
}
}
}
return V_124 != V_122 ;
}
static int F_31 ( struct V_12 * V_13 ,
struct V_20 * V_21 ,
struct V_20 * V_22 ,
int V_37 , int V_38 ,
struct V_33 * V_39 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_40 * V_40 = F_14 ( V_13 ) ;
struct V_81 * V_82 = V_2 -> V_83 ;
int V_3 = V_40 -> V_3 ;
int V_128 = V_129 ;
int V_67 = V_68 ;
int V_28 = V_29 ;
int V_6 = V_7 ;
int V_130 = V_131 ;
int V_132 = V_133 ;
int V_134 = V_135 ;
int V_136 = V_137 ;
int V_138 = V_139 ;
int V_140 = V_141 ;
int V_142 = V_143 ;
int V_144 = V_145 ;
int V_146 = V_147 ;
T_1 * V_86 = & V_82 -> V_86 [ V_3 ] ;
T_1 * V_30 = & V_82 -> V_30 [ V_3 ] ;
int V_117 = 0 ;
int V_148 = 0 , V_149 = 0 , V_150 = 1 , V_151 = 0 , V_152 = 0 ,
V_153 = 0 ;
struct V_118 clock ;
bool V_154 ;
T_1 V_155 = 0 , V_156 = 0 ;
bool V_157 = false , V_158 = false , V_159 = false ;
struct V_160 * V_161 = & V_2 -> V_161 ;
struct V_162 * V_162 = NULL ;
T_2 V_163 = V_164 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
int V_87 = 0 ;
int V_51 ;
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
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_128 = V_169 ;
V_67 = V_88 ;
V_28 = V_55 ;
V_6 = V_8 ;
V_130 = V_170 ;
V_132 = V_171 ;
V_134 = V_172 ;
V_136 = V_173 ;
V_138 = V_174 ;
V_140 = V_175 ;
V_142 = V_176 ;
V_144 = V_177 ;
V_146 = V_178 ;
V_128 = V_179 ;
V_67 = V_71 ;
break;
case 2 :
V_67 = V_68 ;
V_28 = V_59 ;
V_6 = V_9 ;
V_130 = V_180 ;
V_132 = V_181 ;
V_134 = V_182 ;
V_136 = V_183 ;
V_138 = V_184 ;
V_140 = V_185 ;
V_142 = V_186 ;
V_144 = V_187 ;
V_146 = V_188 ;
break;
default:
F_2 ( L_1 ) ;
return 0 ;
}
V_51 = F_12 ( V_13 -> V_34 ) ;
if ( V_51 )
return V_51 ;
F_16 ( V_2 -> V_2 , L_12 ,
V_22 -> V_189 ) ;
F_16 ( V_2 -> V_2 , L_13 ,
V_22 -> V_190 ) ;
F_16 ( V_2 -> V_2 , L_14 ,
V_22 -> V_191 ) ;
F_16 ( V_2 -> V_2 , L_15 ,
V_22 -> V_192 ) ;
F_16 ( V_2 -> V_2 , L_16 ,
V_22 -> V_193 ) ;
F_16 ( V_2 -> V_2 , L_17 ,
V_22 -> V_194 ) ;
F_16 ( V_2 -> V_2 , L_18 ,
V_22 -> V_195 ) ;
F_16 ( V_2 -> V_2 , L_19 ,
V_22 -> V_196 ) ;
F_16 ( V_2 -> V_2 , L_20 ,
V_22 -> clock ) ;
F_16 ( V_2 -> V_2 , L_21 ,
V_21 -> V_189 ) ;
F_16 ( V_2 -> V_2 , L_22 ,
V_21 -> V_190 ) ;
if ( ! F_17 ( V_2 , true ) )
return 0 ;
memcpy ( & V_40 -> V_197 , V_21 ,
sizeof( struct V_20 ) ) ;
memcpy ( & V_40 -> V_198 , V_22 ,
sizeof( struct V_20 ) ) ;
F_32 (connector, &mode_config->connector_list, head) {
if ( ! V_168 )
continue;
V_166 = V_168 -> V_166 ;
if ( ! V_166 )
continue;
if ( V_166 -> V_13 != V_13 )
continue;
V_162 = F_33 ( V_168 ) ;
switch ( V_162 -> type ) {
case V_99 :
V_157 = true ;
break;
case V_100 :
V_158 = true ;
break;
case V_112 :
V_159 = true ;
break;
}
}
F_11 ( V_95 , V_96 ) ;
if ( F_9 ( V_2 ) == V_3 )
F_11 ( V_24 , 0 ) ;
if ( V_3 == 1 ) {
F_11 ( V_142 , ( ( V_125 ( V_21 -> V_199 , V_22 -> V_199 ) - 1 ) << 16 )
| ( V_125 ( V_21 -> V_200 , V_22 -> V_200 ) - 1 ) ) ;
F_11 ( V_146 , ( ( V_21 -> V_200 - 1 ) << 16 )
| ( V_21 -> V_199 - 1 ) ) ;
} else {
F_11 ( V_142 ,
( ( V_21 -> V_199 - 1 ) << 16 ) |
( V_21 -> V_200 - 1 ) ) ;
F_11 ( V_146 ,
( ( V_21 -> V_200 - 1 ) << 16 ) |
( V_21 -> V_199 - 1 ) ) ;
}
F_11 ( V_144 , 0 ) ;
if ( V_162 )
F_34 ( V_168 ,
V_2 -> V_161 . V_201 , & V_163 ) ;
if ( V_163 == V_202 ) {
int V_203 = 0 , V_204 = 0 ;
V_203 = ( V_22 -> V_200 -
V_21 -> V_200 ) / 2 ;
V_204 = ( V_22 -> V_199 -
V_21 -> V_199 ) / 2 ;
F_11 ( V_130 , ( V_21 -> V_200 - 1 ) |
( ( V_22 -> V_205 - 1 ) << 16 ) ) ;
F_11 ( V_136 , ( V_21 -> V_199 - 1 ) |
( ( V_22 -> V_206 - 1 ) << 16 ) ) ;
F_11 ( V_132 , ( V_22 -> V_207 -
V_203 - 1 ) |
( ( V_22 -> V_208 - V_203 - 1 ) << 16 ) ) ;
F_11 ( V_134 , ( V_22 -> V_209 -
V_203 - 1 ) |
( ( V_22 -> V_210 - V_203 - 1 ) << 16 ) ) ;
F_11 ( V_138 , ( V_22 -> V_211 -
V_204 - 1 ) |
( ( V_22 -> V_212 - V_204 - 1 ) << 16 ) ) ;
F_11 ( V_140 , ( V_22 -> V_213 -
V_204 - 1 ) |
( ( V_22 -> V_214 - V_204 - 1 ) << 16 ) ) ;
} else {
F_11 ( V_130 , ( V_22 -> V_200 - 1 ) |
( ( V_22 -> V_205 - 1 ) << 16 ) ) ;
F_11 ( V_136 , ( V_22 -> V_199 - 1 ) |
( ( V_22 -> V_206 - 1 ) << 16 ) ) ;
F_11 ( V_132 , ( V_22 -> V_207 - 1 ) |
( ( V_22 -> V_208 - 1 ) << 16 ) ) ;
F_11 ( V_134 , ( V_22 -> V_209 - 1 ) |
( ( V_22 -> V_210 - 1 ) << 16 ) ) ;
F_11 ( V_138 , ( V_22 -> V_211 - 1 ) |
( ( V_22 -> V_212 - 1 ) << 16 ) ) ;
F_11 ( V_140 , ( V_22 -> V_213 - 1 ) |
( ( V_22 -> V_214 - 1 ) << 16 ) ) ;
}
{
struct V_14 * V_15 =
V_13 -> V_16 ;
V_15 -> V_215 ( V_13 , V_37 , V_38 , V_39 ) ;
}
* V_86 = V_76 ;
* V_30 = F_4 ( V_28 ) ;
* V_30 |= V_3 << V_216 ;
* V_30 |= V_75 ;
if ( V_158 )
goto V_217;
V_151 = V_22 -> clock ;
if ( V_159 ) {
if ( ( V_101 == V_102 ) || ( V_101 == V_103 ) ) {
V_117 = 19200 ;
if ( V_157 || V_158 )
V_148 = 1 , V_149 = 8 ;
else if ( V_159 )
V_148 = 1 , V_149 = 10 ;
} else if ( V_101 == V_106 ) {
V_117 = 25000 ;
if ( V_157 || V_158 )
V_148 = 1 , V_149 = 8 ;
else if ( V_159 )
V_148 = 1 , V_149 = 10 ;
} else if ( ( V_101 == V_108 ) &&
V_82 -> V_109 == 166 ) {
V_117 = 83000 ;
if ( V_157 || V_158 )
V_148 = 4 , V_149 = 8 ;
else if ( V_159 )
V_148 = 4 , V_149 = 10 ;
} else if ( ( V_101 == V_108 ) &&
( V_82 -> V_109 == 100 ||
V_82 -> V_109 == 200 ) ) {
V_117 = 100000 ;
if ( V_157 || V_158 )
V_148 = 4 , V_149 = 8 ;
else if ( V_159 )
V_148 = 4 , V_149 = 10 ;
}
if ( V_157 )
V_150 = V_82 -> V_218 / 8 ;
else if ( V_158 )
V_150 = V_82 -> V_219 / 8 ;
V_153 = V_151 * V_148 * V_149 * V_150 ;
F_16 ( V_2 -> V_2 , L_23 ,
V_151 , V_148 , V_149 ) ;
F_16 ( V_2 -> V_2 , L_24 ,
V_22 -> clock , V_153 ) ;
V_154 = F_30 ( V_13 , V_153 , V_117 , & clock ) ;
if ( ! V_154 ) {
F_2
( L_25 ) ;
} else {
V_152 = V_220 [ ( clock . V_120 - V_221 ) ] ;
F_16 ( V_2 -> V_2 , L_26
L_27 ,
clock . V_119 , clock . V_120 ,
clock . V_121 , V_152 ) ;
}
V_155 = F_4 ( V_67 ) ;
if ( V_155 & V_79 ) {
V_155 &= ~ V_79 ;
F_11 ( V_67 , V_155 ) ;
F_4 ( V_67 ) ;
F_22 ( 500 ) ;
F_11 ( V_128 , 0 ) ;
V_155 &= ~ V_222 ;
F_11 ( V_67 , V_155 ) ;
F_22 ( 500 ) ;
}
if ( V_155 & V_80 ) {
V_155 &= ~ V_80 ;
F_11 ( V_67 , V_155 ) ;
F_22 ( 500 ) ;
}
V_155 = 0 ;
#if 0
if (ksel == KSEL_CRYSTAL_19 || ksel == KSEL_BYPASS_19 ||
ksel == KSEL_BYPASS_25)
dpll &= ~MDFLD_INPUT_REF_SEL;
else if (ksel == KSEL_BYPASS_83_100)
dpll |= MDFLD_INPUT_REF_SEL;
#endif
if ( V_159 )
V_155 |= V_223 ;
V_156 = ( V_148 / 2 ) << 16 ;
V_156 |= V_152 ;
V_155 |= ( 1 << ( clock . V_121 - 2 ) ) << 17 ;
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
V_155 = 0x00800000 ;
V_156 = 0x000000c1 ;
}
F_11 ( V_128 , V_156 ) ;
F_11 ( V_67 , V_155 ) ;
F_22 ( 500 ) ;
V_155 |= V_79 ;
F_11 ( V_67 , V_155 ) ;
F_4 ( V_67 ) ;
while ( V_87 < 20000 &&
! ( F_4 ( V_6 ) & V_93 ) ) {
F_22 ( 150 ) ;
V_87 ++ ;
}
if ( V_157 )
goto V_217;
F_16 ( V_2 -> V_2 , L_28 , V_157 ) ;
F_11 ( V_6 , * V_86 ) ;
F_4 ( V_6 ) ;
F_11 ( V_28 , * V_30 ) ;
F_3 ( V_2 ) ;
V_217:
F_18 ( V_2 ) ;
return 0 ;
}
