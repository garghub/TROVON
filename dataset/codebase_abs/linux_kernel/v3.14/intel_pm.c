static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_7 ) ;
if ( ( V_6 & V_8 ) == 0 )
return;
V_6 &= ~ V_8 ;
F_3 ( V_7 , V_6 ) ;
if ( F_4 ( ( F_2 ( V_9 ) & V_10 ) == 0 , 10 ) ) {
F_5 ( L_1 ) ;
return;
}
F_5 ( L_2 ) ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_7 ( V_14 ) ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_19 = F_8 ( V_12 ) ;
int V_20 ;
int V_21 , V_22 ;
T_1 V_6 ;
V_20 = V_4 -> V_23 . V_24 / V_25 ;
if ( V_14 -> V_26 [ 0 ] < V_20 )
V_20 = V_14 -> V_26 [ 0 ] ;
if ( F_9 ( V_2 ) )
V_20 = ( V_20 / 32 ) - 1 ;
else
V_20 = ( V_20 / 64 ) - 1 ;
V_21 = V_19 -> V_21 == 0 ? V_27 : V_28 ;
for ( V_22 = 0 ; V_22 < ( V_25 / 32 ) + 1 ; V_22 ++ )
F_3 ( V_29 + ( V_22 * 4 ) , 0 ) ;
if ( F_10 ( V_2 ) ) {
T_1 V_30 ;
V_30 = V_31 | V_32 | V_33 ;
V_30 |= V_21 ;
F_3 ( V_34 , V_30 ) ;
F_3 ( V_35 , V_12 -> V_36 ) ;
}
V_6 = F_2 ( V_7 ) ;
V_6 &= 0x3fff << V_37 ;
V_6 |= V_8 | V_38 ;
if ( F_11 ( V_2 ) )
V_6 |= V_39 ;
V_6 |= ( V_20 & 0xff ) << V_40 ;
V_6 |= V_18 -> V_41 ;
F_3 ( V_7 , V_6 ) ;
F_5 ( L_3 ,
V_20 , V_12 -> V_36 , F_12 ( V_19 -> V_21 ) ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_7 ) & V_8 ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_7 ( V_14 ) ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_19 = F_8 ( V_12 ) ;
int V_21 = V_19 -> V_21 == 0 ? V_42 : V_43 ;
T_1 V_44 ;
V_44 = V_21 | V_45 | V_46 ;
V_44 |= V_47 | V_18 -> V_41 ;
F_3 ( V_48 , V_49 ) ;
F_3 ( V_50 , V_12 -> V_36 ) ;
F_3 ( V_51 , F_2 ( V_51 ) | V_52 ) ;
F_5 ( L_4 , F_12 ( V_19 -> V_21 ) ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_44 ;
V_44 = F_2 ( V_51 ) ;
if ( V_44 & V_52 ) {
V_44 &= ~ V_52 ;
F_3 ( V_51 , V_44 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_51 ) & V_52 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_53 ;
F_18 ( V_4 , V_54 ) ;
V_53 = F_2 ( V_55 ) ;
V_53 |= V_56 <<
V_57 ;
F_3 ( V_55 , V_53 ) ;
V_53 |= V_56 ;
F_3 ( V_55 , V_53 ) ;
V_53 &= ~ ( V_56 <<
V_57 ) ;
F_3 ( V_55 , V_53 ) ;
F_19 ( V_55 ) ;
F_20 ( V_4 , V_54 ) ;
}
static void F_21 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_7 ( V_14 ) ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_19 = F_8 ( V_12 ) ;
int V_21 = V_19 -> V_21 == 0 ? V_42 : V_43 ;
T_1 V_44 ;
V_44 = F_2 ( V_58 ) ;
V_44 &= V_59 ;
V_44 |= ( V_21 | V_46 ) ;
V_44 |= V_60 ;
V_44 |= V_47 ;
if ( F_22 ( V_2 ) )
V_44 |= V_18 -> V_41 ;
F_3 ( V_61 , V_49 ) ;
F_3 ( V_62 , V_12 -> V_36 ) ;
F_3 ( V_63 , F_23 ( V_18 ) | V_64 ) ;
F_3 ( V_58 , V_44 | V_52 ) ;
if ( F_24 ( V_2 ) ) {
F_3 ( V_65 ,
V_66 | V_18 -> V_41 ) ;
F_3 ( V_67 , V_12 -> V_36 ) ;
F_17 ( V_2 ) ;
}
F_5 ( L_4 , F_12 ( V_19 -> V_21 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_44 ;
V_44 = F_2 ( V_58 ) ;
if ( V_44 & V_52 ) {
V_44 &= ~ V_52 ;
F_3 ( V_58 , V_44 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_58 ) & V_52 ;
}
static void F_27 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_7 ( V_14 ) ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_19 = F_8 ( V_12 ) ;
F_3 ( V_68 , F_23 ( V_18 ) ) ;
F_3 ( V_58 , V_52 | V_46 |
V_69 |
V_19 -> V_21 << V_70 ) ;
if ( F_28 ( V_2 ) ) {
F_3 ( V_71 , V_72 ) ;
} else {
F_3 ( F_29 ( V_19 -> V_73 ) ,
V_74 ) ;
}
F_3 ( V_65 ,
V_66 | V_18 -> V_41 ) ;
F_3 ( V_67 , V_12 -> V_36 ) ;
F_17 ( V_2 ) ;
F_5 ( L_4 , F_12 ( V_19 -> V_21 ) ) ;
}
bool F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_75 . V_76 )
return false ;
return V_4 -> V_75 . V_76 ( V_2 ) ;
}
static void F_31 ( struct V_77 * V_78 )
{
struct V_79 * V_80 =
F_32 ( F_33 ( V_78 ) ,
struct V_79 , V_80 ) ;
struct V_1 * V_2 = V_80 -> V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_34 ( & V_2 -> V_81 ) ;
if ( V_80 == V_4 -> V_23 . V_82 ) {
if ( V_80 -> V_12 -> V_14 == V_80 -> V_14 ) {
V_4 -> V_75 . V_83 ( V_80 -> V_12 ) ;
V_4 -> V_23 . V_21 = F_8 ( V_80 -> V_12 ) -> V_21 ;
V_4 -> V_23 . V_84 = V_80 -> V_12 -> V_14 -> V_85 . V_86 ;
V_4 -> V_23 . V_36 = V_80 -> V_12 -> V_36 ;
}
V_4 -> V_23 . V_82 = NULL ;
}
F_35 ( & V_2 -> V_81 ) ;
F_36 ( V_80 ) ;
}
static void F_37 ( struct V_3 * V_4 )
{
if ( V_4 -> V_23 . V_82 == NULL )
return;
F_5 ( L_5 ) ;
if ( F_38 ( & V_4 -> V_23 . V_82 -> V_80 ) )
F_36 ( V_4 -> V_23 . V_82 ) ;
V_4 -> V_23 . V_82 = NULL ;
}
static void F_39 ( struct V_11 * V_12 )
{
struct V_79 * V_80 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_75 . V_83 )
return;
F_37 ( V_4 ) ;
V_80 = F_40 ( sizeof( * V_80 ) , V_87 ) ;
if ( V_80 == NULL ) {
F_41 ( L_6 ) ;
V_4 -> V_75 . V_83 ( V_12 ) ;
return;
}
V_80 -> V_12 = V_12 ;
V_80 -> V_14 = V_12 -> V_14 ;
F_42 ( & V_80 -> V_80 , F_31 ) ;
V_4 -> V_23 . V_82 = V_80 ;
F_43 ( & V_80 -> V_80 , F_44 ( 50 ) ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_37 ( V_4 ) ;
if ( ! V_4 -> V_75 . V_88 )
return;
V_4 -> V_75 . V_88 ( V_2 ) ;
V_4 -> V_23 . V_21 = - 1 ;
}
static bool F_46 ( struct V_3 * V_4 ,
enum V_89 V_90 )
{
if ( V_4 -> V_23 . V_89 == V_90 )
return false ;
V_4 -> V_23 . V_89 = V_90 ;
return true ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 = NULL , * V_91 ;
struct V_19 * V_19 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
const struct V_92 * V_93 ;
unsigned int V_94 , V_95 ;
if ( ! F_48 ( V_2 ) ) {
F_46 ( V_4 , V_96 ) ;
return;
}
if ( ! V_97 ) {
if ( F_46 ( V_4 , V_98 ) )
F_5 ( L_7 ) ;
return;
}
F_49 (tmp_crtc, &dev->mode_config.crtc_list, head) {
if ( F_50 ( V_91 ) &&
F_8 ( V_91 ) -> V_99 ) {
if ( V_12 ) {
if ( F_46 ( V_4 , V_100 ) )
F_5 ( L_8 ) ;
goto V_101;
}
V_12 = V_91 ;
}
}
if ( ! V_12 || V_12 -> V_14 == NULL ) {
if ( F_46 ( V_4 , V_102 ) )
F_5 ( L_9 ) ;
goto V_101;
}
V_19 = F_8 ( V_12 ) ;
V_14 = V_12 -> V_14 ;
V_16 = F_7 ( V_14 ) ;
V_18 = V_16 -> V_18 ;
V_93 = & V_19 -> V_103 . V_93 ;
if ( V_104 < 0 &&
F_51 ( V_2 ) -> V_105 <= 7 && ! F_52 ( V_2 ) ) {
if ( F_46 ( V_4 , V_106 ) )
F_5 ( L_10 ) ;
goto V_101;
}
if ( ! V_104 ) {
if ( F_46 ( V_4 , V_98 ) )
F_5 ( L_7 ) ;
goto V_101;
}
if ( ( V_93 -> V_107 & V_108 ) ||
( V_93 -> V_107 & V_109 ) ) {
if ( F_46 ( V_4 , V_110 ) )
F_5 ( L_11
L_12 ) ;
goto V_101;
}
if ( F_53 ( V_2 ) || F_51 ( V_2 ) -> V_105 >= 5 ) {
V_94 = 4096 ;
V_95 = 2048 ;
} else {
V_94 = 2048 ;
V_95 = 1536 ;
}
if ( V_19 -> V_103 . V_111 > V_94 ||
V_19 -> V_103 . V_112 > V_95 ) {
if ( F_46 ( V_4 , V_113 ) )
F_5 ( L_13 ) ;
goto V_101;
}
if ( ( F_51 ( V_2 ) -> V_105 < 4 || F_52 ( V_2 ) ) &&
V_19 -> V_21 != V_114 ) {
if ( F_46 ( V_4 , V_115 ) )
F_5 ( L_14 ) ;
goto V_101;
}
if ( V_18 -> V_116 != V_117 ||
V_18 -> V_41 == V_118 ) {
if ( F_46 ( V_4 , V_119 ) )
F_5 ( L_15 ) ;
goto V_101;
}
if ( F_54 () )
goto V_101;
if ( F_55 ( V_2 , V_16 -> V_18 -> V_85 . V_24 ) ) {
if ( F_46 ( V_4 , V_120 ) )
F_5 ( L_16 ) ;
goto V_101;
}
if ( V_4 -> V_23 . V_21 == V_19 -> V_21 &&
V_4 -> V_23 . V_84 == V_14 -> V_85 . V_86 &&
V_4 -> V_23 . V_36 == V_12 -> V_36 )
return;
if ( F_30 ( V_2 ) ) {
F_5 ( L_17 ) ;
F_45 ( V_2 ) ;
}
F_39 ( V_12 ) ;
V_4 -> V_23 . V_89 = V_121 ;
return;
V_101:
if ( F_30 ( V_2 ) ) {
F_5 ( L_18 ) ;
F_45 ( V_2 ) ;
}
F_56 ( V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
T_1 V_122 ;
V_122 = F_2 ( V_123 ) ;
switch ( V_122 & V_124 ) {
case V_125 :
V_4 -> V_126 = 533 ;
break;
case V_127 :
V_4 -> V_126 = 800 ;
break;
case V_128 :
V_4 -> V_126 = 667 ;
break;
case V_129 :
V_4 -> V_126 = 400 ;
break;
}
switch ( V_122 & V_130 ) {
case V_131 :
V_4 -> V_132 = 533 ;
break;
case V_133 :
V_4 -> V_132 = 667 ;
break;
case V_134 :
V_4 -> V_132 = 800 ;
break;
}
V_122 = F_2 ( V_135 ) ;
V_4 -> V_136 = ( V_122 & V_137 ) ? 1 : 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
T_3 V_138 , V_139 ;
V_138 = F_59 ( V_140 ) ;
V_139 = F_59 ( V_141 ) ;
switch ( V_138 & 0xff ) {
case 0xc :
V_4 -> V_132 = 800 ;
break;
case 0x10 :
V_4 -> V_132 = 1066 ;
break;
case 0x14 :
V_4 -> V_132 = 1333 ;
break;
case 0x18 :
V_4 -> V_132 = 1600 ;
break;
default:
F_60 ( L_19 ,
V_138 & 0xff ) ;
V_4 -> V_132 = 0 ;
break;
}
V_4 -> V_142 . V_143 = V_4 -> V_132 ;
switch ( V_139 & 0x3ff ) {
case 0x00c :
V_4 -> V_126 = 3200 ;
break;
case 0x00e :
V_4 -> V_126 = 3733 ;
break;
case 0x010 :
V_4 -> V_126 = 4266 ;
break;
case 0x012 :
V_4 -> V_126 = 4800 ;
break;
case 0x014 :
V_4 -> V_126 = 5333 ;
break;
case 0x016 :
V_4 -> V_126 = 5866 ;
break;
case 0x018 :
V_4 -> V_126 = 6400 ;
break;
default:
F_60 ( L_20 ,
V_139 & 0x3ff ) ;
V_4 -> V_126 = 0 ;
break;
}
if ( V_4 -> V_126 == 3200 ) {
V_4 -> V_142 . V_144 = 0 ;
} else if ( V_4 -> V_126 > 3200 && V_4 -> V_126 <= 4800 ) {
V_4 -> V_142 . V_144 = 1 ;
} else {
V_4 -> V_142 . V_144 = 2 ;
}
}
static const struct V_145 * F_61 ( int V_146 ,
int V_136 ,
int V_147 ,
int V_148 )
{
const struct V_145 * V_149 ;
int V_22 ;
if ( V_147 == 0 || V_148 == 0 )
return NULL ;
for ( V_22 = 0 ; V_22 < F_62 ( V_150 ) ; V_22 ++ ) {
V_149 = & V_150 [ V_22 ] ;
if ( V_146 == V_149 -> V_146 &&
V_136 == V_149 -> V_136 &&
V_147 == V_149 -> V_126 && V_148 == V_149 -> V_132 )
return V_149 ;
}
F_5 ( L_21 ) ;
return NULL ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_151 , F_2 ( V_151 ) & ~ V_152 ) ;
}
static int F_64 ( struct V_1 * V_2 , int V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_153 = F_2 ( V_154 ) ;
int V_24 ;
V_24 = V_153 & 0x7f ;
if ( V_21 )
V_24 = ( ( V_153 >> V_155 ) & 0x7f ) - V_24 ;
F_5 ( L_22 , V_153 ,
V_21 ? L_23 : L_24 , V_24 ) ;
return V_24 ;
}
static int F_65 ( struct V_1 * V_2 , int V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_153 = F_2 ( V_154 ) ;
int V_24 ;
V_24 = V_153 & 0x1ff ;
if ( V_21 )
V_24 = ( ( V_153 >> V_156 ) & 0x1ff ) - V_24 ;
V_24 >>= 1 ;
F_5 ( L_22 , V_153 ,
V_21 ? L_23 : L_24 , V_24 ) ;
return V_24 ;
}
static int F_66 ( struct V_1 * V_2 , int V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_153 = F_2 ( V_154 ) ;
int V_24 ;
V_24 = V_153 & 0x7f ;
V_24 >>= 2 ;
F_5 ( L_22 , V_153 ,
V_21 ? L_23 : L_24 ,
V_24 ) ;
return V_24 ;
}
static unsigned long F_67 ( unsigned long V_157 ,
const struct V_158 * V_159 ,
int V_160 ,
int V_161 ,
unsigned long V_162 )
{
long V_163 , V_164 ;
V_163 = ( ( V_157 / 1000 ) * V_161 * V_162 ) /
1000 ;
V_163 = F_68 ( V_163 , V_159 -> V_165 ) ;
F_5 ( L_25 , V_163 ) ;
V_164 = V_160 - ( V_163 + V_159 -> V_166 ) ;
F_5 ( L_26 , V_164 ) ;
if ( V_164 > ( long ) V_159 -> V_167 )
V_164 = V_159 -> V_167 ;
if ( V_164 <= 0 )
V_164 = V_159 -> V_168 ;
return V_164 ;
}
static struct V_11 * F_69 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_169 = NULL ;
F_49 (crtc, &dev->mode_config.crtc_list, head) {
if ( F_50 ( V_12 ) ) {
if ( V_169 )
return NULL ;
V_169 = V_12 ;
}
}
return V_169 ;
}
static void F_70 ( struct V_11 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_145 * V_149 ;
T_1 V_171 ;
unsigned long V_159 ;
V_149 = F_61 ( F_71 ( V_2 ) , V_4 -> V_136 ,
V_4 -> V_126 , V_4 -> V_132 ) ;
if ( ! V_149 ) {
F_5 ( L_21 ) ;
F_63 ( V_2 ) ;
return;
}
V_12 = F_69 ( V_2 ) ;
if ( V_12 ) {
const struct V_92 * V_93 ;
int V_161 = V_12 -> V_14 -> V_172 / 8 ;
int clock ;
V_93 = & F_8 ( V_12 ) -> V_103 . V_93 ;
clock = V_93 -> V_173 ;
V_159 = F_67 ( clock , & V_174 ,
V_174 . V_160 ,
V_161 , V_149 -> V_175 ) ;
V_171 = F_2 ( V_176 ) ;
V_171 &= ~ V_177 ;
V_171 |= V_159 << V_178 ;
F_3 ( V_176 , V_171 ) ;
F_5 ( L_27 , V_171 ) ;
V_159 = F_67 ( clock , & V_179 ,
V_174 . V_160 ,
V_161 , V_149 -> V_180 ) ;
V_171 = F_2 ( V_151 ) ;
V_171 &= ~ V_181 ;
V_171 |= ( V_159 & 0x3f ) << V_182 ;
F_3 ( V_151 , V_171 ) ;
V_159 = F_67 ( clock , & V_183 ,
V_183 . V_160 ,
V_161 , V_149 -> V_184 ) ;
V_171 = F_2 ( V_151 ) ;
V_171 &= ~ V_185 ;
V_171 |= V_159 & V_185 ;
F_3 ( V_151 , V_171 ) ;
V_159 = F_67 ( clock , & V_186 ,
V_183 . V_160 ,
V_161 , V_149 -> V_187 ) ;
V_171 = F_2 ( V_151 ) ;
V_171 &= ~ V_188 ;
V_171 |= ( V_159 & 0x3f ) << V_189 ;
F_3 ( V_151 , V_171 ) ;
F_5 ( L_28 , V_171 ) ;
F_3 ( V_151 ,
F_2 ( V_151 ) | V_152 ) ;
F_5 ( L_29 ) ;
} else {
F_63 ( V_2 ) ;
F_5 ( L_30 ) ;
}
}
static bool F_72 ( struct V_1 * V_2 ,
int V_21 ,
const struct V_158 * V_75 ,
int V_190 ,
const struct V_158 * V_191 ,
int V_192 ,
int * V_193 ,
int * V_194 )
{
struct V_11 * V_12 ;
const struct V_92 * V_93 ;
int V_195 , V_196 , clock , V_161 ;
int V_197 , V_198 ;
int V_199 , V_200 ;
V_12 = F_73 ( V_2 , V_21 ) ;
if ( ! F_50 ( V_12 ) ) {
* V_194 = V_191 -> V_166 ;
* V_193 = V_75 -> V_166 ;
return false ;
}
V_93 = & F_8 ( V_12 ) -> V_103 . V_93 ;
clock = V_93 -> V_173 ;
V_195 = V_93 -> V_201 ;
V_196 = F_8 ( V_12 ) -> V_103 . V_111 ;
V_161 = V_12 -> V_14 -> V_172 / 8 ;
V_199 = ( ( clock * V_161 / 1000 ) * V_190 ) / 1000 ;
V_200 = V_75 -> V_160 * V_75 -> V_165 - V_196 * 8 ;
if ( V_200 > 0 )
V_199 += V_200 ;
V_199 = F_68 ( V_199 , V_75 -> V_165 ) ;
* V_193 = V_199 + V_75 -> V_166 ;
if ( * V_193 > ( int ) V_75 -> V_167 )
* V_193 = V_75 -> V_167 ;
V_197 = ( ( V_195 * 1000 ) / clock ) ;
V_198 = ( V_192 / V_197 + 1000 ) / 1000 ;
V_199 = V_198 * 64 * V_161 ;
V_200 = V_191 -> V_160 * V_191 -> V_165 - V_196 * 8 ;
if ( V_200 > 0 )
V_199 += V_200 ;
V_199 = F_68 ( V_199 , V_191 -> V_165 ) ;
* V_194 = V_199 + V_191 -> V_166 ;
if ( * V_194 > ( int ) V_191 -> V_167 )
* V_194 = ( int ) V_191 -> V_167 ;
return true ;
}
static bool F_74 ( struct V_1 * V_2 ,
int V_202 , int V_194 ,
const struct V_158 * V_75 ,
const struct V_158 * V_191 )
{
F_5 ( L_31 ,
V_202 , V_194 ) ;
if ( V_202 > V_75 -> V_167 ) {
F_5 ( L_32 ,
V_202 , V_75 -> V_167 ) ;
return false ;
}
if ( V_194 > V_191 -> V_167 ) {
F_5 ( L_33 ,
V_194 , V_191 -> V_167 ) ;
return false ;
}
if ( ! ( V_202 || V_194 ) ) {
F_5 ( L_34 ) ;
return false ;
}
return true ;
}
static bool F_75 ( struct V_1 * V_2 ,
int V_21 ,
int V_162 ,
const struct V_158 * V_75 ,
const struct V_158 * V_191 ,
int * V_202 , int * V_194 )
{
struct V_11 * V_12 ;
const struct V_92 * V_93 ;
int V_196 , V_195 , V_161 , clock ;
unsigned long V_197 ;
int V_198 , V_203 ;
int V_204 , V_205 ;
int V_199 ;
if ( ! V_162 ) {
* V_202 = * V_194 = 0 ;
return false ;
}
V_12 = F_73 ( V_2 , V_21 ) ;
V_93 = & F_8 ( V_12 ) -> V_103 . V_93 ;
clock = V_93 -> V_173 ;
V_195 = V_93 -> V_201 ;
V_196 = F_8 ( V_12 ) -> V_103 . V_111 ;
V_161 = V_12 -> V_14 -> V_172 / 8 ;
V_197 = ( V_195 * 1000 ) / clock ;
V_198 = ( V_162 / V_197 + 1000 ) / 1000 ;
V_203 = V_196 * V_161 ;
V_204 = ( ( clock * V_161 / 1000 ) * V_162 ) / 1000 ;
V_205 = V_198 * V_203 ;
V_199 = F_68 ( F_76 ( V_204 , V_205 ) , V_75 -> V_165 ) ;
* V_202 = V_199 + V_75 -> V_166 ;
V_199 = V_198 * V_161 * 64 ;
V_199 = F_68 ( V_199 , V_191 -> V_165 ) ;
* V_194 = V_199 + V_191 -> V_166 ;
return F_74 ( V_2 ,
* V_202 , * V_194 ,
V_75 , V_191 ) ;
}
static bool F_77 ( struct V_1 * V_2 ,
int V_21 ,
int * V_206 ,
int * V_207 ,
int * V_208 ,
int * V_209 )
{
struct V_11 * V_12 ;
int clock , V_161 ;
int V_199 ;
V_12 = F_73 ( V_2 , V_21 ) ;
if ( ! F_50 ( V_12 ) )
return false ;
clock = F_8 ( V_12 ) -> V_103 . V_93 . V_173 ;
V_161 = V_12 -> V_14 -> V_172 / 8 ;
V_199 = ( clock / 1000 ) * V_161 ;
* V_206 = ( V_199 > 256 ) ?
V_210 : V_211 ;
* V_207 = ( 64 * ( * V_206 ) * 4 ) / ( ( clock / 1000 ) *
V_161 ) ;
V_199 = ( clock / 1000 ) * 4 ;
* V_208 = ( V_199 > 256 ) ?
V_210 : V_211 ;
* V_209 = ( 64 * ( * V_208 ) * 4 ) / ( ( clock / 1000 ) * 4 ) ;
return true ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_212 , V_213 , V_214 , V_215 ;
int V_216 , V_217 , V_218 , V_219 ;
int V_206 , V_208 ;
if ( F_77 ( V_2 , 0 , & V_206 , & V_213 ,
& V_208 , & V_217 ) ) {
V_216 = ( V_208 == V_210 ) ?
V_220 : V_221 ;
V_212 = ( V_206 == V_210 ) ?
V_222 : V_223 ;
F_3 ( V_224 , V_216 |
( V_217 << V_225 ) |
V_212 | V_213 ) ;
}
if ( F_77 ( V_2 , 1 , & V_206 , & V_215 ,
& V_208 , & V_219 ) ) {
V_218 = ( V_208 == V_210 ) ?
V_226 : V_227 ;
V_214 = ( V_206 == V_210 ) ?
V_228 : V_229 ;
F_3 ( V_230 , V_218 |
( V_219 << V_231 ) |
V_214 | V_215 ) ;
}
}
static void F_79 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_232 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_233 , V_234 , V_235 , V_236 ;
int V_237 , V_180 ;
int V_238 , V_239 ;
unsigned int V_169 = 0 ;
F_78 ( V_2 ) ;
if ( F_72 ( V_2 , V_240 ,
& V_241 , V_162 ,
& V_242 , V_162 ,
& V_233 , & V_235 ) )
V_169 |= 1 << V_240 ;
if ( F_72 ( V_2 , V_243 ,
& V_241 , V_162 ,
& V_242 , V_162 ,
& V_234 , & V_236 ) )
V_169 |= 1 << V_243 ;
if ( F_80 ( V_169 ) &&
F_75 ( V_2 , F_81 ( V_169 ) - 1 ,
V_232 ,
& V_241 ,
& V_242 ,
& V_237 , & V_239 ) &&
F_75 ( V_2 , F_81 ( V_169 ) - 1 ,
2 * V_232 ,
& V_241 ,
& V_242 ,
& V_238 , & V_180 ) ) {
F_3 ( V_244 , V_245 ) ;
} else {
F_3 ( V_244 ,
F_2 ( V_244 ) & ~ V_245 ) ;
V_237 = V_180 = 0 ;
}
F_5 ( L_35 ,
V_233 , V_235 ,
V_234 , V_236 ,
V_237 , V_180 ) ;
F_3 ( V_176 ,
( V_237 << V_178 ) |
( V_236 << V_246 ) |
( V_234 << V_247 ) |
V_233 ) ;
F_3 ( V_248 ,
( F_2 ( V_248 ) & ~ V_249 ) |
( V_235 << V_250 ) ) ;
F_3 ( V_151 ,
( F_2 ( V_151 ) & ~ V_181 ) |
( V_180 << V_182 ) ) ;
}
static void F_82 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_232 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_233 , V_234 , V_235 , V_236 ;
int V_237 , V_180 ;
unsigned int V_169 = 0 ;
if ( F_72 ( V_2 , V_240 ,
& V_251 , V_162 ,
& V_252 , V_162 ,
& V_233 , & V_235 ) )
V_169 |= 1 << V_240 ;
if ( F_72 ( V_2 , V_243 ,
& V_251 , V_162 ,
& V_252 , V_162 ,
& V_234 , & V_236 ) )
V_169 |= 1 << V_243 ;
if ( F_80 ( V_169 ) &&
F_75 ( V_2 , F_81 ( V_169 ) - 1 ,
V_232 ,
& V_251 ,
& V_252 ,
& V_237 , & V_180 ) ) {
F_3 ( V_253 , V_254 ) ;
} else {
F_3 ( V_253 ,
F_2 ( V_253 ) & ~ V_254 ) ;
V_237 = V_180 = 0 ;
}
F_5 ( L_35 ,
V_233 , V_235 ,
V_234 , V_236 ,
V_237 , V_180 ) ;
F_3 ( V_176 ,
( V_237 << V_178 ) |
( V_236 << V_246 ) |
( V_234 << V_247 ) |
V_233 ) ;
F_3 ( V_248 ,
( F_2 ( V_248 ) & ~ V_249 ) |
( V_235 << V_250 ) ) ;
F_3 ( V_151 ,
( F_2 ( V_151 ) & ~ ( V_255 | V_181 ) ) |
( V_180 << V_182 ) ) ;
}
static void F_83 ( struct V_11 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
int V_256 = 1 ;
int V_180 = 16 ;
V_12 = F_69 ( V_2 ) ;
if ( V_12 ) {
static const int V_232 = 12000 ;
const struct V_92 * V_93 =
& F_8 ( V_12 ) -> V_103 . V_93 ;
int clock = V_93 -> V_173 ;
int V_195 = V_93 -> V_201 ;
int V_196 = F_8 ( V_12 ) -> V_103 . V_111 ;
int V_161 = V_12 -> V_14 -> V_172 / 8 ;
unsigned long V_197 ;
int V_199 ;
V_197 = ( ( V_195 * 1000 ) / clock ) ;
V_199 = ( ( ( V_232 / V_197 ) + 1000 ) / 1000 ) *
V_161 * V_196 ;
V_199 = F_68 ( V_199 , V_257 ) ;
V_256 = V_258 - V_199 ;
if ( V_256 < 0 )
V_256 = 1 ;
V_256 &= 0x1ff ;
F_5 ( L_36 ,
V_199 , V_256 ) ;
V_199 = ( ( ( V_232 / V_197 ) + 1000 ) / 1000 ) *
V_161 * 64 ;
V_199 = F_68 ( V_199 ,
V_259 . V_165 ) ;
V_180 = V_259 . V_160 -
( V_199 + V_259 . V_166 ) ;
if ( V_180 > V_259 . V_167 )
V_180 = V_259 . V_167 ;
F_5 ( L_37
L_38 , V_256 , V_180 ) ;
if ( F_84 ( V_2 ) )
F_3 ( V_253 , V_254 ) ;
} else {
if ( F_84 ( V_2 ) )
F_3 ( V_253 , F_2 ( V_253 )
& ~ V_254 ) ;
}
F_5 ( L_39 ,
V_256 ) ;
F_3 ( V_176 , ( V_256 << V_178 ) |
( 8 << 16 ) | ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_3 ( V_248 , ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_3 ( V_151 , ( V_180 << V_182 ) ) ;
}
static void F_85 ( struct V_11 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_158 * V_260 ;
T_4 V_261 ;
T_4 V_262 ;
int V_263 , V_256 = 1 ;
int V_160 ;
int V_233 , V_234 ;
struct V_11 * V_12 , * V_169 = NULL ;
if ( F_11 ( V_2 ) )
V_260 = & V_264 ;
else if ( ! F_9 ( V_2 ) )
V_260 = & V_265 ;
else
V_260 = & V_266 ;
V_160 = V_4 -> V_75 . V_267 ( V_2 , 0 ) ;
V_12 = F_73 ( V_2 , 0 ) ;
if ( F_50 ( V_12 ) ) {
const struct V_92 * V_93 ;
int V_268 = V_12 -> V_14 -> V_172 / 8 ;
if ( F_9 ( V_2 ) )
V_268 = 4 ;
V_93 = & F_8 ( V_12 ) -> V_103 . V_93 ;
V_233 = F_67 ( V_93 -> V_173 ,
V_260 , V_160 , V_268 ,
V_162 ) ;
V_169 = V_12 ;
} else
V_233 = V_160 - V_260 -> V_166 ;
V_160 = V_4 -> V_75 . V_267 ( V_2 , 1 ) ;
V_12 = F_73 ( V_2 , 1 ) ;
if ( F_50 ( V_12 ) ) {
const struct V_92 * V_93 ;
int V_268 = V_12 -> V_14 -> V_172 / 8 ;
if ( F_9 ( V_2 ) )
V_268 = 4 ;
V_93 = & F_8 ( V_12 ) -> V_103 . V_93 ;
V_234 = F_67 ( V_93 -> V_173 ,
V_260 , V_160 , V_268 ,
V_162 ) ;
if ( V_169 == NULL )
V_169 = V_12 ;
else
V_169 = NULL ;
} else
V_234 = V_160 - V_260 -> V_166 ;
F_5 ( L_40 , V_233 , V_234 ) ;
V_263 = 2 ;
if ( F_86 ( V_2 ) || F_11 ( V_2 ) )
F_3 ( V_253 , V_269 | 0 ) ;
else if ( F_87 ( V_2 ) )
F_3 ( V_270 , F_88 ( V_271 ) ) ;
if ( F_89 ( V_2 ) && V_169 ) {
static const int V_232 = 6000 ;
const struct V_92 * V_93 =
& F_8 ( V_169 ) -> V_103 . V_93 ;
int clock = V_93 -> V_173 ;
int V_195 = V_93 -> V_201 ;
int V_196 = F_8 ( V_169 ) -> V_103 . V_111 ;
int V_161 = V_169 -> V_14 -> V_172 / 8 ;
unsigned long V_197 ;
int V_199 ;
V_197 = ( V_195 * 1000 ) / clock ;
V_199 = ( ( ( V_232 / V_197 ) + 1000 ) / 1000 ) *
V_161 * V_196 ;
V_199 = F_68 ( V_199 , V_260 -> V_165 ) ;
F_5 ( L_41 , V_199 ) ;
V_256 = V_260 -> V_160 - V_199 ;
if ( V_256 < 0 )
V_256 = 1 ;
if ( F_86 ( V_2 ) || F_11 ( V_2 ) )
F_3 ( V_253 ,
V_272 | ( V_256 & 0xff ) ) ;
else if ( F_87 ( V_2 ) )
F_3 ( V_253 , V_256 & 0x3f ) ;
}
F_5 ( L_42 ,
V_233 , V_234 , V_263 , V_256 ) ;
V_261 = ( ( V_234 & 0x3f ) << 16 ) | ( V_233 & 0x3f ) ;
V_262 = ( V_263 & 0x1f ) ;
V_261 = V_261 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_262 = V_262 | ( 1 << 8 ) ;
F_3 ( V_273 , V_261 ) ;
F_3 ( V_274 , V_262 ) ;
if ( F_89 ( V_2 ) ) {
if ( V_169 ) {
if ( F_86 ( V_2 ) || F_11 ( V_2 ) )
F_3 ( V_253 ,
V_269 | V_254 ) ;
else if ( F_87 ( V_2 ) )
F_3 ( V_270 , F_90 ( V_271 ) ) ;
F_5 ( L_43 ) ;
} else
F_5 ( L_44 ) ;
}
}
static void F_91 ( struct V_11 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_92 * V_93 ;
T_4 V_261 ;
int V_233 ;
V_12 = F_69 ( V_2 ) ;
if ( V_12 == NULL )
return;
V_93 = & F_8 ( V_12 ) -> V_103 . V_93 ;
V_233 = F_67 ( V_93 -> V_173 ,
& V_275 ,
V_4 -> V_75 . V_267 ( V_2 , 0 ) ,
4 , V_162 ) ;
V_261 = F_2 ( V_273 ) & ~ 0xfff ;
V_261 |= ( 3 << 8 ) | V_233 ;
F_5 ( L_45 , V_233 ) ;
F_3 ( V_273 , V_261 ) ;
}
static T_4 F_92 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_19 * V_19 = F_8 ( V_12 ) ;
T_4 V_276 ;
V_276 = V_19 -> V_103 . V_93 . V_173 ;
if ( V_19 -> V_103 . V_277 . V_169 ) {
T_5 V_278 , V_279 , V_280 , V_281 ;
T_4 V_282 = V_19 -> V_103 . V_277 . V_24 ;
V_278 = V_19 -> V_103 . V_111 ;
V_279 = V_19 -> V_103 . V_112 ;
V_280 = ( V_282 >> 16 ) & 0xFFFF ;
V_281 = V_282 & 0xFFFF ;
if ( V_278 < V_280 )
V_278 = V_280 ;
if ( V_279 < V_281 )
V_279 = V_281 ;
V_276 = F_93 ( ( T_5 ) V_276 * V_278 * V_279 ,
V_280 * V_281 ) ;
}
return V_276 ;
}
static T_4 F_94 ( T_4 V_276 , T_6 V_283 ,
T_4 V_149 )
{
T_5 V_284 ;
if ( F_95 ( V_149 == 0 , L_46 ) )
return V_285 ;
V_284 = ( T_5 ) V_276 * V_283 * V_149 ;
V_284 = F_96 ( V_284 , 64 * 10000 ) + 2 ;
return V_284 ;
}
static T_4 F_97 ( T_4 V_276 , T_4 V_286 ,
T_4 V_287 , T_6 V_283 ,
T_4 V_149 )
{
T_4 V_284 ;
if ( F_95 ( V_149 == 0 , L_46 ) )
return V_285 ;
V_284 = ( V_149 * V_276 ) / ( V_286 * 10000 ) ;
V_284 = ( V_284 + 1 ) * V_287 * V_283 ;
V_284 = F_68 ( V_284 , 64 ) + 2 ;
return V_284 ;
}
static T_4 F_98 ( T_4 V_288 , T_4 V_287 ,
T_6 V_283 )
{
return F_68 ( V_288 * 64 , V_287 * V_283 ) + 2 ;
}
static T_4 F_99 ( const struct V_289 * V_290 ,
T_4 V_291 ,
bool V_292 )
{
T_4 V_293 , V_294 ;
if ( ! V_290 -> V_295 || ! V_290 -> V_296 . V_169 )
return 0 ;
V_293 = F_94 ( V_290 -> V_276 ,
V_290 -> V_296 . V_283 ,
V_291 ) ;
if ( ! V_292 )
return V_293 ;
V_294 = F_97 ( V_290 -> V_276 ,
V_290 -> V_286 ,
V_290 -> V_296 . V_287 ,
V_290 -> V_296 . V_283 ,
V_291 ) ;
return F_76 ( V_293 , V_294 ) ;
}
static T_4 F_100 ( const struct V_289 * V_290 ,
T_4 V_291 )
{
T_4 V_293 , V_294 ;
if ( ! V_290 -> V_295 || ! V_290 -> V_297 . V_169 )
return 0 ;
V_293 = F_94 ( V_290 -> V_276 ,
V_290 -> V_297 . V_283 ,
V_291 ) ;
V_294 = F_97 ( V_290 -> V_276 ,
V_290 -> V_286 ,
V_290 -> V_297 . V_287 ,
V_290 -> V_297 . V_283 ,
V_291 ) ;
return F_76 ( V_293 , V_294 ) ;
}
static T_4 F_101 ( const struct V_289 * V_290 ,
T_4 V_291 )
{
if ( ! V_290 -> V_295 || ! V_290 -> V_298 . V_169 )
return 0 ;
return F_97 ( V_290 -> V_276 ,
V_290 -> V_286 ,
V_290 -> V_298 . V_287 ,
V_290 -> V_298 . V_283 ,
V_291 ) ;
}
static T_4 F_102 ( const struct V_289 * V_290 ,
T_4 V_288 )
{
if ( ! V_290 -> V_295 || ! V_290 -> V_296 . V_169 )
return 0 ;
return F_98 ( V_288 ,
V_290 -> V_296 . V_287 ,
V_290 -> V_296 . V_283 ) ;
}
static unsigned int F_103 ( const struct V_1 * V_2 )
{
if ( F_51 ( V_2 ) -> V_105 >= 8 )
return 3072 ;
else if ( F_51 ( V_2 ) -> V_105 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_104 ( const struct V_1 * V_2 ,
int V_299 ,
const struct V_300 * V_103 ,
enum V_301 V_302 ,
bool V_303 )
{
unsigned int V_160 = F_103 ( V_2 ) ;
unsigned int V_304 ;
if ( V_303 && ! V_103 -> V_305 )
return 0 ;
if ( V_299 == 0 || V_103 -> V_306 > 1 ) {
V_160 /= F_51 ( V_2 ) -> V_307 ;
if ( F_51 ( V_2 ) -> V_105 <= 6 )
V_160 /= 2 ;
}
if ( V_103 -> V_305 ) {
if ( V_299 > 0 && V_302 == V_308 ) {
if ( V_303 )
V_160 *= 5 ;
V_160 /= 6 ;
} else {
V_160 /= 2 ;
}
}
if ( F_51 ( V_2 ) -> V_105 >= 8 )
V_304 = V_299 == 0 ? 255 : 2047 ;
else if ( F_51 ( V_2 ) -> V_105 >= 7 )
V_304 = V_299 == 0 ? 127 : 1023 ;
else if ( ! V_303 )
V_304 = V_299 == 0 ? 127 : 511 ;
else
V_304 = V_299 == 0 ? 63 : 255 ;
return F_76 ( V_160 , V_304 ) ;
}
static unsigned int F_105 ( const struct V_1 * V_2 ,
int V_299 ,
const struct V_300 * V_103 )
{
if ( V_299 > 0 && V_103 -> V_306 > 1 )
return 64 ;
if ( F_51 ( V_2 ) -> V_105 >= 7 )
return V_299 == 0 ? 63 : 255 ;
else
return V_299 == 0 ? 31 : 63 ;
}
static unsigned int F_106 ( struct V_1 * V_2 )
{
if ( F_51 ( V_2 ) -> V_105 >= 8 )
return 31 ;
else
return 15 ;
}
static void F_107 ( struct V_1 * V_2 ,
int V_299 ,
const struct V_300 * V_103 ,
enum V_301 V_302 ,
struct V_309 * V_304 )
{
V_304 -> V_296 = F_104 ( V_2 , V_299 , V_103 , V_302 , false ) ;
V_304 -> V_297 = F_104 ( V_2 , V_299 , V_103 , V_302 , true ) ;
V_304 -> V_298 = F_105 ( V_2 , V_299 , V_103 ) ;
V_304 -> V_23 = F_106 ( V_2 ) ;
}
static bool F_108 ( int V_299 ,
const struct V_309 * V_304 ,
struct V_310 * V_311 )
{
bool V_284 ;
if ( ! V_311 -> V_312 )
return false ;
V_311 -> V_312 = V_311 -> V_288 <= V_304 -> V_296 &&
V_311 -> V_313 <= V_304 -> V_297 &&
V_311 -> V_314 <= V_304 -> V_298 ;
V_284 = V_311 -> V_312 ;
if ( V_299 == 0 && ! V_311 -> V_312 ) {
if ( V_311 -> V_288 > V_304 -> V_296 )
F_5 ( L_47 ,
V_299 , V_311 -> V_288 , V_304 -> V_296 ) ;
if ( V_311 -> V_313 > V_304 -> V_297 )
F_5 ( L_48 ,
V_299 , V_311 -> V_313 , V_304 -> V_297 ) ;
if ( V_311 -> V_314 > V_304 -> V_298 )
F_5 ( L_49 ,
V_299 , V_311 -> V_314 , V_304 -> V_298 ) ;
V_311 -> V_288 = F_109 ( T_4 , V_311 -> V_288 , V_304 -> V_296 ) ;
V_311 -> V_313 = F_109 ( T_4 , V_311 -> V_313 , V_304 -> V_297 ) ;
V_311 -> V_314 = F_109 ( T_4 , V_311 -> V_314 , V_304 -> V_298 ) ;
V_311 -> V_312 = true ;
}
return V_284 ;
}
static void F_110 ( struct V_3 * V_4 ,
int V_299 ,
const struct V_289 * V_315 ,
struct V_310 * V_311 )
{
T_7 V_316 = V_4 -> V_159 . V_316 [ V_299 ] ;
T_7 V_317 = V_4 -> V_159 . V_317 [ V_299 ] ;
T_7 V_318 = V_4 -> V_159 . V_318 [ V_299 ] ;
if ( V_299 > 0 ) {
V_316 *= 5 ;
V_317 *= 5 ;
V_318 *= 5 ;
}
V_311 -> V_288 = F_99 ( V_315 , V_316 , V_299 ) ;
V_311 -> V_313 = F_100 ( V_315 , V_317 ) ;
V_311 -> V_314 = F_101 ( V_315 , V_318 ) ;
V_311 -> V_319 = F_102 ( V_315 , V_311 -> V_288 ) ;
V_311 -> V_312 = true ;
}
static T_4
F_111 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_19 = F_8 ( V_12 ) ;
struct V_92 * V_320 = & V_19 -> V_103 . V_93 ;
T_1 V_321 , V_322 ;
if ( ! F_50 ( V_12 ) )
return 0 ;
V_321 = F_112 ( V_320 -> V_201 * 1000 * 8 ,
V_320 -> V_173 ) ;
V_322 = F_112 ( V_320 -> V_201 * 1000 * 8 ,
F_113 ( V_4 ) ) ;
return F_114 ( V_322 ) |
F_115 ( V_321 ) ;
}
static void F_116 ( struct V_1 * V_2 , T_7 V_159 [ 5 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_52 ( V_2 ) || F_117 ( V_2 ) ) {
T_5 V_323 = F_118 ( V_324 ) ;
V_159 [ 0 ] = ( V_323 >> 56 ) & 0xFF ;
if ( V_159 [ 0 ] == 0 )
V_159 [ 0 ] = V_323 & 0xF ;
V_159 [ 1 ] = ( V_323 >> 4 ) & 0xFF ;
V_159 [ 2 ] = ( V_323 >> 12 ) & 0xFF ;
V_159 [ 3 ] = ( V_323 >> 20 ) & 0x1FF ;
V_159 [ 4 ] = ( V_323 >> 32 ) & 0x1FF ;
} else if ( F_51 ( V_2 ) -> V_105 >= 6 ) {
T_4 V_323 = F_2 ( V_324 ) ;
V_159 [ 0 ] = ( V_323 >> V_325 ) & V_326 ;
V_159 [ 1 ] = ( V_323 >> V_327 ) & V_326 ;
V_159 [ 2 ] = ( V_323 >> V_328 ) & V_326 ;
V_159 [ 3 ] = ( V_323 >> V_329 ) & V_326 ;
} else if ( F_51 ( V_2 ) -> V_105 >= 5 ) {
T_4 V_330 = F_2 ( V_331 ) ;
V_159 [ 0 ] = 7 ;
V_159 [ 1 ] = ( V_330 >> V_332 ) & V_333 ;
V_159 [ 2 ] = ( V_330 >> V_334 ) & V_333 ;
}
}
static void F_119 ( struct V_1 * V_2 , T_7 V_159 [ 5 ] )
{
if ( F_51 ( V_2 ) -> V_105 == 5 )
V_159 [ 0 ] = 13 ;
}
static void F_120 ( struct V_1 * V_2 , T_7 V_159 [ 5 ] )
{
if ( F_51 ( V_2 ) -> V_105 == 5 )
V_159 [ 0 ] = 13 ;
if ( F_28 ( V_2 ) )
V_159 [ 3 ] *= 2 ;
}
static int F_121 ( const struct V_1 * V_2 )
{
if ( F_52 ( V_2 ) || F_117 ( V_2 ) )
return 4 ;
else if ( F_51 ( V_2 ) -> V_105 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_122 ( struct V_1 * V_2 ,
const char * V_335 ,
const T_7 V_159 [ 5 ] )
{
int V_299 , V_336 = F_121 ( V_2 ) ;
for ( V_299 = 0 ; V_299 <= V_336 ; V_299 ++ ) {
unsigned int V_149 = V_159 [ V_299 ] ;
if ( V_149 == 0 ) {
F_41 ( L_50 ,
V_335 , V_299 ) ;
continue;
}
if ( V_299 > 0 )
V_149 *= 5 ;
F_5 ( L_51 ,
V_335 , V_299 , V_159 [ V_299 ] ,
V_149 / 10 , V_149 % 10 ) ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_116 ( V_2 , V_4 -> V_159 . V_316 ) ;
memcpy ( V_4 -> V_159 . V_317 , V_4 -> V_159 . V_316 ,
sizeof( V_4 -> V_159 . V_316 ) ) ;
memcpy ( V_4 -> V_159 . V_318 , V_4 -> V_159 . V_316 ,
sizeof( V_4 -> V_159 . V_316 ) ) ;
F_119 ( V_2 , V_4 -> V_159 . V_317 ) ;
F_120 ( V_2 , V_4 -> V_159 . V_318 ) ;
F_122 ( V_2 , L_52 , V_4 -> V_159 . V_316 ) ;
F_122 ( V_2 , L_53 , V_4 -> V_159 . V_317 ) ;
F_122 ( V_2 , L_54 , V_4 -> V_159 . V_318 ) ;
}
static void F_124 ( struct V_11 * V_12 ,
struct V_289 * V_315 ,
struct V_300 * V_103 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_19 * V_19 = F_8 ( V_12 ) ;
enum V_73 V_73 = V_19 -> V_73 ;
struct V_337 * V_21 ;
V_315 -> V_295 = F_50 ( V_12 ) ;
if ( V_315 -> V_295 ) {
V_315 -> V_286 = V_19 -> V_103 . V_93 . V_201 ;
V_315 -> V_276 = F_92 ( V_2 , V_12 ) ;
V_315 -> V_296 . V_283 = V_12 -> V_14 -> V_172 / 8 ;
V_315 -> V_298 . V_283 = 4 ;
V_315 -> V_296 . V_287 = V_19 -> V_103 . V_111 ;
V_315 -> V_298 . V_287 = 64 ;
V_315 -> V_296 . V_169 = true ;
V_315 -> V_298 . V_169 = true ;
}
F_49 (crtc, &dev->mode_config.crtc_list, head)
V_103 -> V_306 += F_50 ( V_12 ) ;
F_49 (plane, &dev->mode_config.plane_list, head) {
struct V_338 * V_338 = F_125 ( V_21 ) ;
if ( V_338 -> V_73 == V_73 )
V_315 -> V_297 = V_338 -> V_159 ;
V_103 -> V_305 |= V_338 -> V_159 . V_169 ;
V_103 -> V_339 |= V_338 -> V_159 . V_340 ;
}
}
static bool F_126 ( struct V_11 * V_12 ,
const struct V_289 * V_290 ,
struct V_341 * V_342 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_299 , V_336 = F_121 ( V_2 ) ;
struct V_300 V_103 = {
. V_306 = 1 ,
. V_305 = V_290 -> V_297 . V_169 ,
. V_339 = V_290 -> V_297 . V_340 ,
} ;
struct V_309 V_304 ;
F_107 ( V_2 , 0 , & V_103 , V_343 , & V_304 ) ;
if ( F_51 ( V_2 ) -> V_105 <= 6 && V_290 -> V_297 . V_169 )
V_336 = 1 ;
if ( V_290 -> V_297 . V_340 )
V_336 = 0 ;
for ( V_299 = 0 ; V_299 <= V_336 ; V_299 ++ )
F_110 ( V_4 , V_299 , V_290 ,
& V_342 -> V_159 [ V_299 ] ) ;
if ( F_52 ( V_2 ) || F_117 ( V_2 ) )
V_342 -> V_321 = F_111 ( V_2 , V_12 ) ;
return F_108 ( 0 , & V_304 , & V_342 -> V_159 [ 0 ] ) ;
}
static void F_127 ( struct V_1 * V_2 ,
int V_299 ,
struct V_310 * V_344 )
{
const struct V_19 * V_19 ;
F_49 (intel_crtc, &dev->mode_config.crtc_list, base.head) {
const struct V_310 * V_159 =
& V_19 -> V_159 . V_295 . V_159 [ V_299 ] ;
if ( ! V_159 -> V_312 )
return;
V_344 -> V_288 = V_304 ( V_344 -> V_288 , V_159 -> V_288 ) ;
V_344 -> V_313 = V_304 ( V_344 -> V_313 , V_159 -> V_313 ) ;
V_344 -> V_314 = V_304 ( V_344 -> V_314 , V_159 -> V_314 ) ;
V_344 -> V_319 = V_304 ( V_344 -> V_319 , V_159 -> V_319 ) ;
}
V_344 -> V_312 = true ;
}
static void F_128 ( struct V_1 * V_2 ,
const struct V_300 * V_103 ,
const struct V_309 * V_304 ,
struct V_341 * V_345 )
{
int V_299 , V_336 = F_121 ( V_2 ) ;
if ( ( F_51 ( V_2 ) -> V_105 <= 6 || F_28 ( V_2 ) ) &&
V_103 -> V_306 > 1 )
return;
V_345 -> V_346 = F_51 ( V_2 ) -> V_105 >= 6 ;
for ( V_299 = 1 ; V_299 <= V_336 ; V_299 ++ ) {
struct V_310 * V_159 = & V_345 -> V_159 [ V_299 ] ;
F_127 ( V_2 , V_299 , V_159 ) ;
if ( ! F_108 ( V_299 , V_304 , V_159 ) )
break;
if ( V_159 -> V_319 > V_304 -> V_23 ) {
V_345 -> V_346 = false ;
V_159 -> V_319 = 0 ;
}
}
if ( F_22 ( V_2 ) && ! V_345 -> V_346 && F_30 ( V_2 ) ) {
for ( V_299 = 2 ; V_299 <= V_336 ; V_299 ++ ) {
struct V_310 * V_159 = & V_345 -> V_159 [ V_299 ] ;
V_159 -> V_312 = false ;
}
}
}
static int F_129 ( int V_347 , const struct V_341 * V_342 )
{
return V_347 + ( V_347 >= 2 && V_342 -> V_159 [ 4 ] . V_312 ) ;
}
static unsigned int F_130 ( struct V_1 * V_2 , int V_299 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_52 ( V_2 ) || F_117 ( V_2 ) )
return 2 * V_299 ;
else
return V_4 -> V_159 . V_316 [ V_299 ] ;
}
static void F_131 ( struct V_1 * V_2 ,
const struct V_341 * V_345 ,
enum V_301 V_348 ,
struct V_349 * V_350 )
{
struct V_19 * V_19 ;
int V_299 , V_347 ;
V_350 -> V_351 = V_345 -> V_346 ;
V_350 -> V_348 = V_348 ;
for ( V_347 = 1 ; V_347 <= 3 ; V_347 ++ ) {
const struct V_310 * V_352 ;
V_299 = F_129 ( V_347 , V_345 ) ;
V_352 = & V_345 -> V_159 [ V_299 ] ;
if ( ! V_352 -> V_312 )
break;
V_350 -> V_347 [ V_347 - 1 ] = V_353 |
( F_130 ( V_2 , V_299 ) << V_354 ) |
( V_352 -> V_288 << V_355 ) |
V_352 -> V_314 ;
if ( F_51 ( V_2 ) -> V_105 >= 8 )
V_350 -> V_347 [ V_347 - 1 ] |=
V_352 -> V_319 << V_356 ;
else
V_350 -> V_347 [ V_347 - 1 ] |=
V_352 -> V_319 << V_357 ;
if ( F_51 ( V_2 ) -> V_105 <= 6 && V_352 -> V_313 ) {
F_132 ( V_347 != 1 ) ;
V_350 -> V_358 [ V_347 - 1 ] = V_359 | V_352 -> V_313 ;
} else
V_350 -> V_358 [ V_347 - 1 ] = V_352 -> V_313 ;
}
F_49 (intel_crtc, &dev->mode_config.crtc_list, base.head) {
enum V_73 V_73 = V_19 -> V_73 ;
const struct V_310 * V_352 =
& V_19 -> V_159 . V_295 . V_159 [ 0 ] ;
if ( F_132 ( ! V_352 -> V_312 ) )
continue;
V_350 -> V_360 [ V_73 ] = V_19 -> V_159 . V_295 . V_321 ;
V_350 -> V_361 [ V_73 ] =
( V_352 -> V_288 << V_362 ) |
( V_352 -> V_313 << V_363 ) |
V_352 -> V_314 ;
}
}
static struct V_341 * F_133 ( struct V_1 * V_2 ,
struct V_341 * V_364 ,
struct V_341 * V_365 )
{
int V_299 , V_336 = F_121 ( V_2 ) ;
int V_366 = 0 , V_367 = 0 ;
for ( V_299 = 1 ; V_299 <= V_336 ; V_299 ++ ) {
if ( V_364 -> V_159 [ V_299 ] . V_312 )
V_366 = V_299 ;
if ( V_365 -> V_159 [ V_299 ] . V_312 )
V_367 = V_299 ;
}
if ( V_366 == V_367 ) {
if ( V_365 -> V_346 && ! V_364 -> V_346 )
return V_365 ;
else
return V_364 ;
} else if ( V_366 > V_367 ) {
return V_364 ;
} else {
return V_365 ;
}
}
static unsigned int F_134 ( struct V_1 * V_2 ,
const struct V_349 * V_368 ,
const struct V_349 * V_369 )
{
unsigned int V_370 = 0 ;
enum V_73 V_73 ;
int V_347 ;
F_135 (pipe) {
if ( V_368 -> V_360 [ V_73 ] != V_369 -> V_360 [ V_73 ] ) {
V_370 |= F_136 ( V_73 ) ;
V_370 |= V_371 ;
}
if ( V_368 -> V_361 [ V_73 ] != V_369 -> V_361 [ V_73 ] ) {
V_370 |= F_137 ( V_73 ) ;
V_370 |= V_371 ;
}
}
if ( V_368 -> V_351 != V_369 -> V_351 ) {
V_370 |= V_372 ;
V_370 |= V_371 ;
}
if ( V_368 -> V_348 != V_369 -> V_348 ) {
V_370 |= V_373 ;
V_370 |= V_371 ;
}
if ( V_370 & V_371 )
return V_370 ;
for ( V_347 = 1 ; V_347 <= 3 ; V_347 ++ ) {
if ( V_368 -> V_347 [ V_347 - 1 ] != V_369 -> V_347 [ V_347 - 1 ] ||
V_368 -> V_358 [ V_347 - 1 ] != V_369 -> V_358 [ V_347 - 1 ] )
break;
}
for (; V_347 <= 3 ; V_347 ++ )
V_370 |= F_138 ( V_347 ) ;
return V_370 ;
}
static bool F_139 ( struct V_3 * V_4 ,
unsigned int V_370 )
{
struct V_349 * V_374 = & V_4 -> V_159 . V_375 ;
bool V_376 = false ;
if ( V_370 & F_138 ( 3 ) && V_374 -> V_347 [ 2 ] & V_377 ) {
V_374 -> V_347 [ 2 ] &= ~ V_377 ;
F_3 ( V_378 , V_374 -> V_347 [ 2 ] ) ;
V_376 = true ;
}
if ( V_370 & F_138 ( 2 ) && V_374 -> V_347 [ 1 ] & V_377 ) {
V_374 -> V_347 [ 1 ] &= ~ V_377 ;
F_3 ( V_379 , V_374 -> V_347 [ 1 ] ) ;
V_376 = true ;
}
if ( V_370 & F_138 ( 1 ) && V_374 -> V_347 [ 0 ] & V_377 ) {
V_374 -> V_347 [ 0 ] &= ~ V_377 ;
F_3 ( V_380 , V_374 -> V_347 [ 0 ] ) ;
V_376 = true ;
}
return V_376 ;
}
static void F_140 ( struct V_3 * V_4 ,
struct V_349 * V_350 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_349 * V_374 = & V_4 -> V_159 . V_375 ;
unsigned int V_370 ;
T_4 V_381 ;
V_370 = F_134 ( V_2 , V_374 , V_350 ) ;
if ( ! V_370 )
return;
F_139 ( V_4 , V_370 ) ;
if ( V_370 & F_137 ( V_240 ) )
F_3 ( V_382 , V_350 -> V_361 [ 0 ] ) ;
if ( V_370 & F_137 ( V_243 ) )
F_3 ( V_383 , V_350 -> V_361 [ 1 ] ) ;
if ( V_370 & F_137 ( V_384 ) )
F_3 ( V_385 , V_350 -> V_361 [ 2 ] ) ;
if ( V_370 & F_136 ( V_240 ) )
F_3 ( F_141 ( V_240 ) , V_350 -> V_360 [ 0 ] ) ;
if ( V_370 & F_136 ( V_243 ) )
F_3 ( F_141 ( V_243 ) , V_350 -> V_360 [ 1 ] ) ;
if ( V_370 & F_136 ( V_384 ) )
F_3 ( F_141 ( V_384 ) , V_350 -> V_360 [ 2 ] ) ;
if ( V_370 & V_373 ) {
if ( F_52 ( V_2 ) || F_117 ( V_2 ) ) {
V_381 = F_2 ( V_386 ) ;
if ( V_350 -> V_348 == V_343 )
V_381 &= ~ V_387 ;
else
V_381 |= V_387 ;
F_3 ( V_386 , V_381 ) ;
} else {
V_381 = F_2 ( V_388 ) ;
if ( V_350 -> V_348 == V_343 )
V_381 &= ~ V_389 ;
else
V_381 |= V_389 ;
F_3 ( V_388 , V_381 ) ;
}
}
if ( V_370 & V_372 ) {
V_381 = F_2 ( V_390 ) ;
if ( V_350 -> V_351 )
V_381 &= ~ V_391 ;
else
V_381 |= V_391 ;
F_3 ( V_390 , V_381 ) ;
}
if ( V_370 & F_138 ( 1 ) &&
V_374 -> V_358 [ 0 ] != V_350 -> V_358 [ 0 ] )
F_3 ( V_392 , V_350 -> V_358 [ 0 ] ) ;
if ( F_51 ( V_2 ) -> V_105 >= 7 ) {
if ( V_370 & F_138 ( 2 ) && V_374 -> V_358 [ 1 ] != V_350 -> V_358 [ 1 ] )
F_3 ( V_393 , V_350 -> V_358 [ 1 ] ) ;
if ( V_370 & F_138 ( 3 ) && V_374 -> V_358 [ 2 ] != V_350 -> V_358 [ 2 ] )
F_3 ( V_394 , V_350 -> V_358 [ 2 ] ) ;
}
if ( V_370 & F_138 ( 1 ) && V_374 -> V_347 [ 0 ] != V_350 -> V_347 [ 0 ] )
F_3 ( V_380 , V_350 -> V_347 [ 0 ] ) ;
if ( V_370 & F_138 ( 2 ) && V_374 -> V_347 [ 1 ] != V_350 -> V_347 [ 1 ] )
F_3 ( V_379 , V_350 -> V_347 [ 1 ] ) ;
if ( V_370 & F_138 ( 3 ) && V_374 -> V_347 [ 2 ] != V_350 -> V_347 [ 2 ] )
F_3 ( V_378 , V_350 -> V_347 [ 2 ] ) ;
V_4 -> V_159 . V_375 = * V_350 ;
}
static bool F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_139 ( V_4 , V_371 ) ;
}
static void F_143 ( struct V_11 * V_12 )
{
struct V_19 * V_19 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_309 V_304 ;
struct V_289 V_290 = {} ;
struct V_349 V_350 = {} ;
enum V_301 V_348 ;
struct V_341 V_342 = {} ;
struct V_341 V_395 = {} , V_396 = {} , * V_397 ;
struct V_300 V_103 = {} ;
F_124 ( V_12 , & V_290 , & V_103 ) ;
F_126 ( V_12 , & V_290 , & V_342 ) ;
if ( ! memcmp ( & V_19 -> V_159 . V_295 , & V_342 , sizeof( V_342 ) ) )
return;
V_19 -> V_159 . V_295 = V_342 ;
F_107 ( V_2 , 1 , & V_103 , V_343 , & V_304 ) ;
F_128 ( V_2 , & V_103 , & V_304 , & V_395 ) ;
if ( F_51 ( V_2 ) -> V_105 >= 7 &&
V_103 . V_306 == 1 && V_103 . V_305 ) {
F_107 ( V_2 , 1 , & V_103 , V_308 , & V_304 ) ;
F_128 ( V_2 , & V_103 , & V_304 , & V_396 ) ;
V_397 = F_133 ( V_2 , & V_395 , & V_396 ) ;
} else {
V_397 = & V_395 ;
}
V_348 = ( V_397 == & V_395 ) ?
V_343 : V_308 ;
F_131 ( V_2 , V_397 , V_348 , & V_350 ) ;
F_140 ( V_4 , & V_350 ) ;
}
static void F_144 ( struct V_337 * V_21 ,
struct V_11 * V_12 ,
T_4 V_398 , int V_161 ,
bool V_169 , bool V_340 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_338 * V_338 = F_125 ( V_21 ) ;
V_338 -> V_159 . V_169 = V_169 ;
V_338 -> V_159 . V_340 = V_340 ;
V_338 -> V_159 . V_287 = V_398 ;
V_338 -> V_159 . V_283 = V_161 ;
if ( F_28 ( V_2 ) && V_340 && F_142 ( V_2 ) )
F_145 ( V_2 , V_338 -> V_73 ) ;
F_143 ( V_12 ) ;
}
static void F_146 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_349 * V_375 = & V_4 -> V_159 . V_375 ;
struct V_19 * V_19 = F_8 ( V_12 ) ;
struct V_341 * V_295 = & V_19 -> V_159 . V_295 ;
enum V_73 V_73 = V_19 -> V_73 ;
static const unsigned int V_399 [] = {
[ V_240 ] = V_382 ,
[ V_243 ] = V_383 ,
[ V_384 ] = V_385 ,
} ;
V_375 -> V_361 [ V_73 ] = F_2 ( V_399 [ V_73 ] ) ;
if ( F_52 ( V_2 ) || F_117 ( V_2 ) )
V_375 -> V_360 [ V_73 ] = F_2 ( F_141 ( V_73 ) ) ;
if ( F_50 ( V_12 ) ) {
T_1 V_122 = V_375 -> V_361 [ V_73 ] ;
V_295 -> V_159 [ 0 ] . V_312 = true ;
V_295 -> V_159 [ 0 ] . V_288 = ( V_122 & V_400 ) >> V_362 ;
V_295 -> V_159 [ 0 ] . V_313 = ( V_122 & V_401 ) >> V_363 ;
V_295 -> V_159 [ 0 ] . V_314 = V_122 & V_402 ;
V_295 -> V_321 = V_375 -> V_360 [ V_73 ] ;
} else {
int V_299 , V_336 = F_121 ( V_2 ) ;
for ( V_299 = 0 ; V_299 <= V_336 ; V_299 ++ )
V_295 -> V_159 [ V_299 ] . V_312 = true ;
}
}
void F_147 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_349 * V_375 = & V_4 -> V_159 . V_375 ;
struct V_11 * V_12 ;
F_49 (crtc, &dev->mode_config.crtc_list, head)
F_146 ( V_12 ) ;
V_375 -> V_347 [ 0 ] = F_2 ( V_380 ) ;
V_375 -> V_347 [ 1 ] = F_2 ( V_379 ) ;
V_375 -> V_347 [ 2 ] = F_2 ( V_378 ) ;
V_375 -> V_358 [ 0 ] = F_2 ( V_392 ) ;
V_375 -> V_358 [ 1 ] = F_2 ( V_393 ) ;
V_375 -> V_358 [ 2 ] = F_2 ( V_394 ) ;
if ( F_52 ( V_2 ) || F_117 ( V_2 ) )
V_375 -> V_348 = ( F_2 ( V_386 ) & V_387 ) ?
V_308 : V_343 ;
else if ( F_28 ( V_2 ) )
V_375 -> V_348 = ( F_2 ( V_388 ) & V_389 ) ?
V_308 : V_343 ;
V_375 -> V_351 =
! ( F_2 ( V_390 ) & V_391 ) ;
}
void F_148 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_2 -> V_5 ;
if ( V_4 -> V_75 . V_403 )
V_4 -> V_75 . V_403 ( V_12 ) ;
}
void F_149 ( struct V_337 * V_21 ,
struct V_11 * V_12 ,
T_4 V_398 , int V_161 ,
bool V_169 , bool V_340 )
{
struct V_3 * V_4 = V_21 -> V_2 -> V_5 ;
if ( V_4 -> V_75 . V_404 )
V_4 -> V_75 . V_404 ( V_21 , V_12 , V_398 ,
V_161 , V_169 , V_340 ) ;
}
static struct V_17 *
F_150 ( struct V_1 * V_2 )
{
struct V_17 * V_405 ;
int V_284 ;
F_132 ( ! F_151 ( & V_2 -> V_81 ) ) ;
V_405 = F_152 ( V_2 , 4096 ) ;
if ( ! V_405 ) {
F_153 ( L_55 ) ;
return NULL ;
}
V_284 = F_154 ( V_405 , 4096 , true , false ) ;
if ( V_284 ) {
F_41 ( L_56 , V_284 ) ;
goto V_406;
}
V_284 = F_155 ( V_405 , 1 ) ;
if ( V_284 ) {
F_41 ( L_57 , V_284 ) ;
goto V_407;
}
return V_405 ;
V_407:
F_156 ( V_405 ) ;
V_406:
F_157 ( & V_405 -> V_85 ) ;
return NULL ;
}
bool F_158 ( struct V_1 * V_2 , T_8 V_381 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_408 ;
F_159 ( & V_409 ) ;
V_408 = F_59 ( V_410 ) ;
if ( V_408 & V_411 ) {
F_153 ( L_58 ) ;
return false ;
}
V_408 = ( V_412 << V_413 ) |
( V_381 << V_414 ) | V_415 ;
F_160 ( V_410 , V_408 ) ;
F_161 ( V_410 ) ;
V_408 |= V_411 ;
F_160 ( V_410 , V_408 ) ;
return true ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_416 = F_2 ( V_417 ) ;
T_8 V_418 , V_419 , V_420 , V_421 ;
F_163 ( & V_409 ) ;
F_160 ( V_422 , F_2 ( V_422 ) | V_423 ) ;
F_160 ( V_424 , F_2 ( V_424 ) | V_425 ) ;
F_3 ( V_426 , 100000 ) ;
F_3 ( V_427 , 100000 ) ;
F_3 ( V_428 , 90000 ) ;
F_3 ( V_429 , 80000 ) ;
F_3 ( V_430 , 1 ) ;
V_418 = ( V_416 & V_431 ) >> V_432 ;
V_419 = ( V_416 & V_433 ) ;
V_420 = ( V_416 & V_434 ) >>
V_435 ;
V_421 = ( F_2 ( V_436 + ( V_420 * 4 ) ) & V_437 ) >>
V_438 ;
V_4 -> V_142 . V_418 = V_418 ;
V_4 -> V_142 . V_420 = V_420 ;
V_4 -> V_142 . V_439 = V_420 ;
V_4 -> V_142 . V_440 = V_419 ;
V_4 -> V_142 . V_441 = V_420 ;
F_60 ( L_59 ,
V_418 , V_419 , V_420 ) ;
F_3 ( V_442 , V_443 | V_444 ) ;
F_3 ( V_445 , V_421 ) ;
F_19 ( V_445 ) ;
V_416 |= V_446 ;
F_3 ( V_417 , V_416 ) ;
if ( F_164 ( ( F_2 ( V_410 ) & V_411 ) == 0 , 10 ) )
F_41 ( L_60 ) ;
F_165 ( 1 ) ;
F_158 ( V_2 , V_420 ) ;
V_4 -> V_142 . V_447 = F_2 ( 0x112e4 ) + F_2 ( 0x112e8 ) +
F_2 ( 0x112e0 ) ;
V_4 -> V_142 . V_448 = F_166 ( V_449 ) ;
V_4 -> V_142 . V_450 = F_2 ( 0x112f4 ) ;
F_167 ( & V_4 -> V_142 . V_451 ) ;
F_168 ( & V_409 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_408 ;
F_163 ( & V_409 ) ;
V_408 = F_59 ( V_410 ) ;
F_3 ( V_442 , F_2 ( V_442 ) & ~ V_444 ) ;
F_3 ( V_452 , V_453 ) ;
F_3 ( V_454 , F_2 ( V_454 ) & ~ V_455 ) ;
F_3 ( V_456 , V_455 ) ;
F_3 ( V_457 , F_2 ( V_457 ) | V_455 ) ;
F_158 ( V_2 , V_4 -> V_142 . V_420 ) ;
F_165 ( 1 ) ;
V_408 |= V_411 ;
F_3 ( V_410 , V_408 ) ;
F_165 ( 1 ) ;
F_168 ( & V_409 ) ;
}
static T_1 F_170 ( struct V_3 * V_4 , T_8 V_381 )
{
T_1 V_458 ;
V_458 = V_4 -> V_459 . V_439 << 24 ;
if ( V_381 <= V_4 -> V_459 . V_440 )
V_458 |= V_4 -> V_459 . V_440 << 16 ;
return V_458 ;
}
static void F_171 ( struct V_3 * V_4 , T_8 V_381 )
{
int V_460 ;
V_460 = V_4 -> V_459 . V_461 ;
switch ( V_4 -> V_459 . V_461 ) {
case V_462 :
if ( V_381 > V_4 -> V_459 . V_463 + 1 && V_381 > V_4 -> V_459 . V_441 )
V_460 = V_464 ;
break;
case V_464 :
if ( V_381 <= V_4 -> V_459 . V_463 && V_381 < V_4 -> V_459 . V_441 )
V_460 = V_462 ;
else if ( V_381 >= V_4 -> V_459 . V_465 && V_381 > V_4 -> V_459 . V_441 )
V_460 = V_466 ;
break;
case V_466 :
if ( V_381 < ( V_4 -> V_459 . V_467 + V_4 -> V_459 . V_465 ) > > 1 && V_381 < V_4 -> V_459 . V_441 )
V_460 = V_464 ;
break;
}
if ( V_381 == V_4 -> V_459 . V_440 )
V_460 = V_462 ;
if ( V_381 == V_4 -> V_459 . V_439 )
V_460 = V_466 ;
if ( V_460 == V_4 -> V_459 . V_461 )
return;
switch ( V_460 ) {
case V_462 :
F_3 ( V_468 , 12500 ) ;
F_3 ( V_469 , 11800 ) ;
F_3 ( V_470 , 25000 ) ;
F_3 ( V_471 , 21250 ) ;
F_3 ( V_472 ,
V_473 |
V_474 |
V_475 |
V_476 |
V_477 |
V_478 ) ;
break;
case V_464 :
F_3 ( V_468 , 10250 ) ;
F_3 ( V_469 , 9225 ) ;
F_3 ( V_470 , 25000 ) ;
F_3 ( V_471 , 18750 ) ;
F_3 ( V_472 ,
V_473 |
V_474 |
V_475 |
V_476 |
V_477 |
V_478 ) ;
break;
case V_466 :
F_3 ( V_468 , 8000 ) ;
F_3 ( V_469 , 6800 ) ;
F_3 ( V_470 , 25000 ) ;
F_3 ( V_471 , 15000 ) ;
F_3 ( V_472 ,
V_473 |
V_474 |
V_475 |
V_476 |
V_477 |
V_478 ) ;
break;
}
V_4 -> V_459 . V_461 = V_460 ;
V_4 -> V_459 . V_479 = 0 ;
}
void F_172 ( struct V_1 * V_2 , T_8 V_381 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_132 ( ! F_151 ( & V_4 -> V_459 . V_480 ) ) ;
F_132 ( V_381 > V_4 -> V_459 . V_439 ) ;
F_132 ( V_381 < V_4 -> V_459 . V_440 ) ;
if ( V_381 == V_4 -> V_459 . V_441 )
return;
F_171 ( V_4 , V_381 ) ;
if ( F_52 ( V_2 ) )
F_3 ( V_481 ,
F_173 ( V_381 ) ) ;
else
F_3 ( V_481 ,
F_174 ( V_381 ) |
F_175 ( 0 ) |
V_482 ) ;
F_3 ( V_483 ,
F_170 ( V_4 , V_381 ) ) ;
F_19 ( V_481 ) ;
V_4 -> V_459 . V_441 = V_381 ;
F_176 ( V_381 * 50 ) ;
}
void F_177 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_34 ( & V_4 -> V_459 . V_480 ) ;
if ( V_4 -> V_459 . V_169 ) {
if ( F_178 ( V_2 ) )
F_179 ( V_4 -> V_2 , V_4 -> V_459 . V_440 ) ;
else
F_172 ( V_4 -> V_2 , V_4 -> V_459 . V_440 ) ;
V_4 -> V_459 . V_479 = 0 ;
}
F_35 ( & V_4 -> V_459 . V_480 ) ;
}
void F_180 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_34 ( & V_4 -> V_459 . V_480 ) ;
if ( V_4 -> V_459 . V_169 ) {
if ( F_178 ( V_2 ) )
F_179 ( V_4 -> V_2 , V_4 -> V_459 . V_439 ) ;
else
F_172 ( V_4 -> V_2 , V_4 -> V_459 . V_439 ) ;
V_4 -> V_459 . V_479 = 0 ;
}
F_35 ( & V_4 -> V_459 . V_480 ) ;
}
void F_179 ( struct V_1 * V_2 , T_8 V_381 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_132 ( ! F_151 ( & V_4 -> V_459 . V_480 ) ) ;
F_132 ( V_381 > V_4 -> V_459 . V_439 ) ;
F_132 ( V_381 < V_4 -> V_459 . V_440 ) ;
F_60 ( L_61 ,
F_181 ( V_4 , V_4 -> V_459 . V_441 ) ,
V_4 -> V_459 . V_441 ,
F_181 ( V_4 , V_381 ) , V_381 ) ;
if ( V_381 == V_4 -> V_459 . V_441 )
return;
F_182 ( V_4 , V_484 , V_381 ) ;
V_4 -> V_459 . V_441 = V_381 ;
F_176 ( F_181 ( V_4 , V_381 ) ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_485 , 0xffffffff ) ;
F_3 ( V_486 , F_2 ( V_486 ) & ~ V_487 ) ;
F_163 ( & V_4 -> V_488 ) ;
V_4 -> V_459 . V_489 = 0 ;
F_168 ( & V_4 -> V_488 ) ;
F_3 ( V_490 , V_487 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_491 , 0 ) ;
F_3 ( V_481 , 1 << 31 ) ;
F_183 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_491 , 0 ) ;
F_183 ( V_2 ) ;
if ( V_4 -> V_492 ) {
F_157 ( & V_4 -> V_492 -> V_85 ) ;
V_4 -> V_492 = NULL ;
}
}
static void F_186 ( struct V_1 * V_2 , T_1 V_320 )
{
if ( F_24 ( V_2 ) )
F_60 ( L_62 ) ;
if ( F_52 ( V_2 ) )
F_60 ( L_63 ) ;
F_187 ( L_64 ,
( V_320 & V_493 ) ? L_65 : L_66 ,
( V_320 & V_494 ) ? L_65 : L_66 ,
( V_320 & V_495 ) ? L_65 : L_66 ) ;
}
int F_188 ( const struct V_1 * V_2 )
{
if ( F_51 ( V_2 ) -> V_105 < 5 )
return 0 ;
if ( V_496 >= 0 )
return V_496 ;
if ( F_51 ( V_2 ) -> V_105 == 5 )
return 0 ;
if ( F_52 ( V_2 ) )
return V_497 ;
if ( F_51 ( V_2 ) -> V_105 == 6 )
return V_497 ;
return ( V_497 | V_498 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_499 ;
F_163 ( & V_4 -> V_488 ) ;
F_132 ( V_4 -> V_459 . V_489 ) ;
F_190 ( V_4 , V_487 ) ;
F_3 ( V_490 , V_487 ) ;
F_168 ( & V_4 -> V_488 ) ;
V_499 = V_487 ;
if ( F_51 ( V_2 ) -> V_105 <= 7 && ! F_52 ( V_2 ) )
V_499 |= V_500 ;
F_3 ( V_485 , ~ V_499 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_501 * V_502 ;
T_4 V_503 = 0 , V_504 ;
int V_505 ;
F_3 ( V_506 , 0 ) ;
F_18 ( V_4 , V_507 ) ;
F_3 ( V_491 , 0 ) ;
V_504 = F_2 ( V_508 ) ;
F_3 ( V_509 , 40 << 16 ) ;
F_3 ( V_510 , 125000 ) ;
F_3 ( V_511 , 25 ) ;
F_192 (ring, dev_priv, unused)
F_3 ( F_193 ( V_502 -> V_512 ) , 10 ) ;
F_3 ( V_513 , 0 ) ;
F_3 ( V_514 , 50000 ) ;
if ( F_188 ( V_2 ) & V_497 )
V_503 = V_493 ;
F_187 ( L_67 , ( V_503 & V_493 ) ? L_65 : L_66 ) ;
F_3 ( V_491 , V_515 |
F_194 ( 1 ) |
V_503 ) ;
F_3 ( V_481 , F_173 ( 10 ) ) ;
F_3 ( V_516 , F_173 ( 12 ) ) ;
F_3 ( V_517 , 100000000 / 128 ) ;
F_3 ( V_483 ,
V_4 -> V_459 . V_439 << 24 |
V_4 -> V_459 . V_440 << 16 ) ;
F_3 ( V_469 , 7600000 / 128 ) ;
F_3 ( V_471 , 31300000 / 128 ) ;
F_3 ( V_468 , 66000 ) ;
F_3 ( V_470 , 350000 ) ;
F_3 ( V_518 , 10 ) ;
F_3 ( V_472 ,
V_473 |
V_474 |
V_475 |
V_476 |
V_477 |
V_478 ) ;
F_172 ( V_2 , ( F_2 ( V_519 ) & 0xff00 ) >> 8 ) ;
F_189 ( V_2 ) ;
F_20 ( V_4 , V_507 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_501 * V_502 ;
T_1 V_504 ;
T_1 V_520 ;
T_1 V_521 , V_522 , V_503 = 0 ;
T_1 V_523 ;
int V_524 ;
int V_22 , V_284 ;
F_132 ( ! F_151 ( & V_4 -> V_459 . V_480 ) ) ;
F_3 ( V_506 , 0 ) ;
if ( ( V_523 = F_2 ( V_525 ) ) ) {
F_41 ( L_68 , V_523 ) ;
F_3 ( V_525 , V_523 ) ;
}
F_18 ( V_4 , V_507 ) ;
V_504 = F_2 ( V_508 ) ;
V_520 = F_2 ( V_519 ) ;
V_4 -> V_459 . V_526 = V_4 -> V_459 . V_439 = V_504 & 0xff ;
V_4 -> V_459 . V_440 = ( V_504 >> 16 ) & 0xff ;
V_4 -> V_459 . V_467 = ( V_504 >> 8 ) & 0xff ;
V_4 -> V_459 . V_465 = ( V_504 >> 0 ) & 0xff ;
V_4 -> V_459 . V_463 = V_4 -> V_459 . V_467 ;
V_4 -> V_459 . V_441 = 0 ;
F_3 ( V_491 , 0 ) ;
F_3 ( V_527 , 1000 << 16 ) ;
F_3 ( V_509 , 40 << 16 | 30 ) ;
F_3 ( V_528 , 30 ) ;
F_3 ( V_510 , 125000 ) ;
F_3 ( V_511 , 25 ) ;
F_192 (ring, dev_priv, i)
F_3 ( F_193 ( V_502 -> V_512 ) , 10 ) ;
F_3 ( V_513 , 0 ) ;
F_3 ( V_529 , 1000 ) ;
if ( F_28 ( V_2 ) )
F_3 ( V_514 , 125000 ) ;
else
F_3 ( V_514 , 50000 ) ;
F_3 ( V_530 , 150000 ) ;
F_3 ( V_531 , 64000 ) ;
V_524 = F_188 ( V_4 -> V_2 ) ;
if ( V_524 & V_497 )
V_503 |= V_493 ;
if ( ! F_52 ( V_2 ) ) {
if ( V_524 & V_498 )
V_503 |= V_494 ;
if ( V_524 & V_532 )
V_503 |= V_495 ;
}
F_186 ( V_2 , V_503 ) ;
F_3 ( V_491 ,
V_503 |
F_194 ( 1 ) |
V_515 ) ;
F_3 ( V_517 , 50000 ) ;
F_3 ( V_518 , 10 ) ;
V_284 = F_196 ( V_4 , V_533 , 0 ) ;
if ( ! V_284 ) {
V_522 = 0 ;
V_284 = F_197 ( V_4 , V_534 , & V_522 ) ;
if ( ! V_284 && ( V_522 & ( 1 << 31 ) ) ) {
F_60 ( L_69 ,
( V_4 -> V_459 . V_439 & 0xff ) * 50 ,
( V_522 & 0xff ) * 50 ) ;
V_4 -> V_459 . V_526 = V_522 & 0xff ;
}
} else {
F_60 ( L_70 ) ;
}
V_4 -> V_459 . V_461 = V_466 ;
F_172 ( V_4 -> V_2 , V_4 -> V_459 . V_440 ) ;
F_189 ( V_2 ) ;
V_521 = 0 ;
V_284 = F_197 ( V_4 , V_535 , & V_521 ) ;
if ( F_24 ( V_2 ) && V_284 ) {
F_60 ( L_71 ) ;
} else if ( F_24 ( V_2 ) && ( F_198 ( V_521 & 0xff ) < 450 ) ) {
F_60 ( L_72 ,
F_198 ( V_521 & 0xff ) , 450 ) ;
V_521 &= 0xffff00 ;
V_521 |= F_199 ( 450 ) ;
V_284 = F_196 ( V_4 , V_536 , V_521 ) ;
if ( V_284 )
F_41 ( L_73 ) ;
}
F_20 ( V_4 , V_507 ) ;
}
void F_200 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_537 = 15 ;
unsigned int V_538 ;
unsigned int V_539 , V_540 ;
int V_541 = 180 ;
struct V_542 * V_543 ;
F_132 ( ! F_151 ( & V_4 -> V_459 . V_480 ) ) ;
V_543 = F_201 ( 0 ) ;
if ( V_543 ) {
V_539 = V_543 -> V_544 . V_545 ;
F_202 ( V_543 ) ;
} else {
V_539 = V_546 ;
}
V_539 /= 1000 ;
V_540 = F_2 ( V_547 ) & 0xf ;
V_540 = F_203 ( V_540 , 8 , 3 ) ;
for ( V_538 = V_4 -> V_459 . V_439 ; V_538 >= V_4 -> V_459 . V_440 ;
V_538 -- ) {
int V_548 = V_4 -> V_459 . V_439 - V_538 ;
unsigned int V_549 = 0 , V_550 = 0 ;
if ( F_51 ( V_2 ) -> V_105 >= 8 ) {
V_550 = V_304 ( V_540 , V_538 ) ;
} else if ( F_52 ( V_2 ) ) {
V_550 = F_203 ( V_538 , 5 , 4 ) ;
V_550 = V_304 ( V_540 , V_550 ) ;
} else {
if ( V_538 < V_537 )
V_549 = 800 ;
else
V_549 = V_539 - ( ( V_548 * V_541 ) / 2 ) ;
V_549 = F_112 ( V_549 , 100 ) ;
}
F_196 ( V_4 ,
V_533 ,
V_549 << V_551 |
V_550 << V_552 |
V_538 ) ;
}
}
int F_204 ( struct V_3 * V_4 )
{
T_1 V_381 , V_553 ;
V_381 = F_205 ( V_4 , V_554 ) ;
V_553 = ( V_381 & V_555 ) >> V_556 ;
V_553 = F_109 ( T_1 , V_553 , 0xea ) ;
return V_553 ;
}
static int F_206 ( struct V_3 * V_4 )
{
T_1 V_381 , V_557 ;
V_381 = F_205 ( V_4 , V_558 ) ;
V_557 = ( V_381 & V_559 ) >> V_560 ;
V_381 = F_205 ( V_4 , V_561 ) ;
V_557 |= ( V_381 & V_562 ) << 5 ;
return V_557 ;
}
int F_207 ( struct V_3 * V_4 )
{
return F_208 ( V_4 , V_563 ) & 0xff ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_17 * V_564 ;
unsigned long V_565 ;
T_1 V_566 ;
int V_567 = 24 * 1024 ;
F_132 ( ! F_151 ( & V_2 -> V_81 ) ) ;
V_566 = F_2 ( V_568 ) ;
if ( V_566 ) {
int V_569 ;
V_569 = ( V_566 & ( ~ 4095 ) ) - V_4 -> V_570 . V_571 ;
V_564 = F_210 ( V_4 -> V_2 ,
V_569 ,
V_572 ,
V_567 ) ;
goto V_573;
}
V_564 = F_211 ( V_2 , V_567 ) ;
if ( ! V_564 ) {
F_153 ( L_74 ) ;
return;
}
V_565 = V_4 -> V_570 . V_571 + V_564 -> V_574 -> V_575 ;
F_3 ( V_568 , V_565 ) ;
V_573:
V_4 -> V_492 = V_564 ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_501 * V_502 ;
T_1 V_523 , V_381 , V_524 = 0 ;
int V_22 ;
F_132 ( ! F_151 ( & V_4 -> V_459 . V_480 ) ) ;
if ( ( V_523 = F_2 ( V_525 ) ) ) {
F_60 ( L_68 ,
V_523 ) ;
F_3 ( V_525 , V_523 ) ;
}
F_18 ( V_4 , V_507 ) ;
F_3 ( V_469 , 59400 ) ;
F_3 ( V_471 , 245000 ) ;
F_3 ( V_468 , 66000 ) ;
F_3 ( V_470 , 350000 ) ;
F_3 ( V_518 , 10 ) ;
F_3 ( V_472 ,
V_473 |
V_474 |
V_475 |
V_476 |
V_477 |
V_576 ) ;
F_3 ( V_509 , 0x00280000 ) ;
F_3 ( V_510 , 125000 ) ;
F_3 ( V_511 , 25 ) ;
F_192 (ring, dev_priv, i)
F_3 ( F_193 ( V_502 -> V_512 ) , 10 ) ;
F_3 ( V_514 , 0x557 ) ;
F_3 ( V_577 ,
F_90 ( V_578 |
V_579 |
V_580 ) ) ;
if ( F_188 ( V_2 ) & V_497 )
V_524 = V_581 | V_582 ;
F_186 ( V_2 , V_524 ) ;
F_3 ( V_491 , V_524 ) ;
V_381 = F_208 ( V_4 , V_583 ) ;
F_60 ( L_75 , V_381 & 0x10 ? L_76 : L_77 ) ;
F_60 ( L_78 , V_381 ) ;
V_4 -> V_459 . V_441 = ( V_381 >> 8 ) & 0xff ;
F_60 ( L_79 ,
F_181 ( V_4 , V_4 -> V_459 . V_441 ) ,
V_4 -> V_459 . V_441 ) ;
V_4 -> V_459 . V_439 = F_204 ( V_4 ) ;
V_4 -> V_459 . V_526 = V_4 -> V_459 . V_439 ;
F_60 ( L_80 ,
F_181 ( V_4 , V_4 -> V_459 . V_439 ) ,
V_4 -> V_459 . V_439 ) ;
V_4 -> V_459 . V_463 = F_206 ( V_4 ) ;
F_60 ( L_81 ,
F_181 ( V_4 , V_4 -> V_459 . V_463 ) ,
V_4 -> V_459 . V_463 ) ;
V_4 -> V_459 . V_440 = F_207 ( V_4 ) ;
F_60 ( L_82 ,
F_181 ( V_4 , V_4 -> V_459 . V_440 ) ,
V_4 -> V_459 . V_440 ) ;
F_60 ( L_83 ,
F_181 ( V_4 , V_4 -> V_459 . V_463 ) ,
V_4 -> V_459 . V_463 ) ;
F_179 ( V_4 -> V_2 , V_4 -> V_459 . V_463 ) ;
F_189 ( V_2 ) ;
F_20 ( V_4 , V_507 ) ;
}
void F_213 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_142 . V_584 ) {
F_156 ( V_4 -> V_142 . V_584 ) ;
F_157 ( & V_4 -> V_142 . V_584 -> V_85 ) ;
V_4 -> V_142 . V_584 = NULL ;
}
if ( V_4 -> V_142 . V_585 ) {
F_156 ( V_4 -> V_142 . V_585 ) ;
F_157 ( & V_4 -> V_142 . V_585 -> V_85 ) ;
V_4 -> V_142 . V_585 = NULL ;
}
}
static void F_214 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_2 ( V_586 ) ) {
F_3 ( V_587 , F_2 ( V_587 ) | V_588 ) ;
F_4 ( ( ( F_2 ( V_587 ) & V_589 ) == V_590 ) ,
50 ) ;
F_3 ( V_586 , 0 ) ;
F_19 ( V_586 ) ;
F_3 ( V_587 , F_2 ( V_587 ) & ~ V_588 ) ;
F_19 ( V_587 ) ;
}
}
static int F_215 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_142 . V_584 == NULL )
V_4 -> V_142 . V_584 = F_150 ( V_2 ) ;
if ( ! V_4 -> V_142 . V_584 )
return - V_591 ;
if ( V_4 -> V_142 . V_585 == NULL )
V_4 -> V_142 . V_585 = F_150 ( V_2 ) ;
if ( ! V_4 -> V_142 . V_585 ) {
F_213 ( V_2 ) ;
return - V_591 ;
}
return 0 ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_501 * V_502 = & V_4 -> V_502 [ V_592 ] ;
bool V_593 ;
int V_284 ;
if ( ! F_188 ( V_2 ) )
return;
F_132 ( ! F_151 ( & V_2 -> V_81 ) ) ;
V_284 = F_215 ( V_2 ) ;
if ( V_284 )
return;
V_593 = V_4 -> V_570 . V_594 ;
V_4 -> V_570 . V_594 = false ;
V_284 = F_217 ( V_502 , 6 ) ;
if ( V_284 ) {
F_213 ( V_2 ) ;
V_4 -> V_570 . V_594 = V_593 ;
return;
}
F_218 ( V_502 , V_595 | V_596 ) ;
F_218 ( V_502 , V_597 ) ;
F_218 ( V_502 , F_23 ( V_4 -> V_142 . V_584 ) |
V_598 |
V_599 |
V_600 |
V_601 ) ;
F_218 ( V_502 , V_595 ) ;
F_218 ( V_502 , V_602 ) ;
F_218 ( V_502 , V_603 ) ;
F_219 ( V_502 ) ;
V_284 = F_220 ( V_502 ) ;
V_4 -> V_570 . V_594 = V_593 ;
if ( V_284 ) {
F_41 ( L_84 ) ;
F_213 ( V_2 ) ;
return;
}
F_3 ( V_586 , F_23 ( V_4 -> V_142 . V_585 ) | V_604 ) ;
F_3 ( V_587 , F_2 ( V_587 ) & ~ V_588 ) ;
F_186 ( V_2 , V_497 ) ;
}
static unsigned long F_221 ( T_1 V_605 )
{
unsigned long V_606 ;
int div = ( V_605 & 0x3f0000 ) >> 16 ;
int V_607 = ( V_605 & 0x3000 ) >> 12 ;
int V_608 = ( V_605 & 0x7 ) ;
if ( ! V_608 )
return 0 ;
V_606 = ( ( div * 133333 ) / ( ( 1 << V_607 ) * V_608 ) ) ;
return V_606 ;
}
static unsigned long F_222 ( struct V_3 * V_4 )
{
T_9 V_609 , V_548 , V_284 ;
T_1 V_610 , V_611 , V_612 , V_613 = 0 , V_614 = 0 ;
unsigned long V_615 = F_166 ( V_449 ) , V_616 ;
int V_22 ;
F_159 ( & V_409 ) ;
V_616 = V_615 - V_4 -> V_142 . V_448 ;
if ( V_616 <= 10 )
return V_4 -> V_142 . V_617 ;
V_610 = F_2 ( V_618 ) ;
V_611 = F_2 ( V_619 ) ;
V_612 = F_2 ( V_620 ) ;
V_609 = V_610 + V_611 + V_612 ;
if ( V_609 < V_4 -> V_142 . V_447 ) {
V_548 = ~ 0UL - V_4 -> V_142 . V_447 ;
V_548 += V_609 ;
} else {
V_548 = V_609 - V_4 -> V_142 . V_447 ;
}
for ( V_22 = 0 ; V_22 < F_62 ( V_621 ) ; V_22 ++ ) {
if ( V_621 [ V_22 ] . V_22 == V_4 -> V_142 . V_144 &&
V_621 [ V_22 ] . V_622 == V_4 -> V_142 . V_143 ) {
V_613 = V_621 [ V_22 ] . V_613 ;
V_614 = V_621 [ V_22 ] . V_614 ;
break;
}
}
V_548 = F_93 ( V_548 , V_616 ) ;
V_284 = ( ( V_613 * V_548 ) + V_614 ) ;
V_284 = F_93 ( V_284 , 10 ) ;
V_4 -> V_142 . V_447 = V_609 ;
V_4 -> V_142 . V_448 = V_615 ;
V_4 -> V_142 . V_617 = V_284 ;
return V_284 ;
}
unsigned long F_223 ( struct V_3 * V_4 )
{
unsigned long V_381 ;
if ( V_4 -> V_623 -> V_105 != 5 )
return 0 ;
F_163 ( & V_409 ) ;
V_381 = F_222 ( V_4 ) ;
F_168 ( & V_409 ) ;
return V_381 ;
}
unsigned long F_224 ( struct V_3 * V_4 )
{
unsigned long V_613 , V_624 , V_625 ;
T_1 V_626 ;
V_626 = F_2 ( V_627 ) ;
V_613 = ( ( V_626 & V_628 ) >> V_629 ) ;
V_624 = F_225 ( V_630 ) ;
V_625 = V_626 & V_631 ;
return ( ( V_613 * V_624 ) / 127 ) - V_625 ;
}
static T_3 F_226 ( struct V_3 * V_4 , T_8 V_632 )
{
static const struct V_633 {
T_3 V_634 ;
T_3 V_635 ;
} V_633 [] = {
{ 0 , 0 , } ,
{ 375 , 0 , } ,
{ 500 , 0 , } ,
{ 625 , 0 , } ,
{ 750 , 0 , } ,
{ 875 , 0 , } ,
{ 1000 , 0 , } ,
{ 1125 , 0 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4125 , 3000 , } ,
{ 4250 , 3125 , } ,
{ 4375 , 3250 , } ,
{ 4500 , 3375 , } ,
{ 4625 , 3500 , } ,
{ 4750 , 3625 , } ,
{ 4875 , 3750 , } ,
{ 5000 , 3875 , } ,
{ 5125 , 4000 , } ,
{ 5250 , 4125 , } ,
{ 5375 , 4250 , } ,
{ 5500 , 4375 , } ,
{ 5625 , 4500 , } ,
{ 5750 , 4625 , } ,
{ 5875 , 4750 , } ,
{ 6000 , 4875 , } ,
{ 6125 , 5000 , } ,
{ 6250 , 5125 , } ,
{ 6375 , 5250 , } ,
{ 6500 , 5375 , } ,
{ 6625 , 5500 , } ,
{ 6750 , 5625 , } ,
{ 6875 , 5750 , } ,
{ 7000 , 5875 , } ,
{ 7125 , 6000 , } ,
{ 7250 , 6125 , } ,
{ 7375 , 6250 , } ,
{ 7500 , 6375 , } ,
{ 7625 , 6500 , } ,
{ 7750 , 6625 , } ,
{ 7875 , 6750 , } ,
{ 8000 , 6875 , } ,
{ 8125 , 7000 , } ,
{ 8250 , 7125 , } ,
{ 8375 , 7250 , } ,
{ 8500 , 7375 , } ,
{ 8625 , 7500 , } ,
{ 8750 , 7625 , } ,
{ 8875 , 7750 , } ,
{ 9000 , 7875 , } ,
{ 9125 , 8000 , } ,
{ 9250 , 8125 , } ,
{ 9375 , 8250 , } ,
{ 9500 , 8375 , } ,
{ 9625 , 8500 , } ,
{ 9750 , 8625 , } ,
{ 9875 , 8750 , } ,
{ 10000 , 8875 , } ,
{ 10125 , 9000 , } ,
{ 10250 , 9125 , } ,
{ 10375 , 9250 , } ,
{ 10500 , 9375 , } ,
{ 10625 , 9500 , } ,
{ 10750 , 9625 , } ,
{ 10875 , 9750 , } ,
{ 11000 , 9875 , } ,
{ 11125 , 10000 , } ,
{ 11250 , 10125 , } ,
{ 11375 , 10250 , } ,
{ 11500 , 10375 , } ,
{ 11625 , 10500 , } ,
{ 11750 , 10625 , } ,
{ 11875 , 10750 , } ,
{ 12000 , 10875 , } ,
{ 12125 , 11000 , } ,
{ 12250 , 11125 , } ,
{ 12375 , 11250 , } ,
{ 12500 , 11375 , } ,
{ 12625 , 11500 , } ,
{ 12750 , 11625 , } ,
{ 12875 , 11750 , } ,
{ 13000 , 11875 , } ,
{ 13125 , 12000 , } ,
{ 13250 , 12125 , } ,
{ 13375 , 12250 , } ,
{ 13500 , 12375 , } ,
{ 13625 , 12500 , } ,
{ 13750 , 12625 , } ,
{ 13875 , 12750 , } ,
{ 14000 , 12875 , } ,
{ 14125 , 13000 , } ,
{ 14250 , 13125 , } ,
{ 14375 , 13250 , } ,
{ 14500 , 13375 , } ,
{ 14625 , 13500 , } ,
{ 14750 , 13625 , } ,
{ 14875 , 13750 , } ,
{ 15000 , 13875 , } ,
{ 15125 , 14000 , } ,
{ 15250 , 14125 , } ,
{ 15375 , 14250 , } ,
{ 15500 , 14375 , } ,
{ 15625 , 14500 , } ,
{ 15750 , 14625 , } ,
{ 15875 , 14750 , } ,
{ 16000 , 14875 , } ,
{ 16125 , 15000 , } ,
} ;
if ( V_4 -> V_623 -> V_636 )
return V_633 [ V_632 ] . V_635 ;
else
return V_633 [ V_632 ] . V_634 ;
}
static void F_227 ( struct V_3 * V_4 )
{
struct V_637 V_615 , V_616 ;
T_9 V_548 ;
unsigned long V_638 ;
T_1 V_639 ;
F_159 ( & V_409 ) ;
F_167 ( & V_615 ) ;
V_616 = F_228 ( V_615 , V_4 -> V_142 . V_451 ) ;
V_638 = V_616 . V_640 * 1000 + V_616 . V_641 / 1000000 ;
if ( ! V_638 )
return;
V_639 = F_2 ( V_642 ) ;
if ( V_639 < V_4 -> V_142 . V_450 ) {
V_548 = ~ 0UL - V_4 -> V_142 . V_450 ;
V_548 += V_639 ;
} else {
V_548 = V_639 - V_4 -> V_142 . V_450 ;
}
V_4 -> V_142 . V_450 = V_639 ;
V_4 -> V_142 . V_451 = V_615 ;
V_548 = V_548 * 1181 ;
V_548 = F_93 ( V_548 , V_638 * 10 ) ;
V_4 -> V_142 . V_643 = V_548 ;
}
void F_229 ( struct V_3 * V_4 )
{
if ( V_4 -> V_623 -> V_105 != 5 )
return;
F_163 ( & V_409 ) ;
F_227 ( V_4 ) ;
F_168 ( & V_409 ) ;
}
static unsigned long F_230 ( struct V_3 * V_4 )
{
unsigned long V_622 , V_644 , V_645 , V_646 , V_647 ;
T_1 V_632 , V_648 ;
F_159 ( & V_409 ) ;
V_632 = F_2 ( V_436 + ( V_4 -> V_459 . V_441 * 4 ) ) ;
V_632 = ( V_632 >> 24 ) & 0x7f ;
V_648 = F_226 ( V_4 , V_632 ) ;
V_645 = V_648 ;
V_622 = F_224 ( V_4 ) ;
if ( V_622 > 80 )
V_644 = ( ( V_622 * 2349 ) + 135940 ) ;
else if ( V_622 >= 50 )
V_644 = ( ( V_622 * 964 ) + 29317 ) ;
else
V_644 = ( ( V_622 * 301 ) + 1004 ) ;
V_644 = V_644 * ( ( 150142 * V_645 ) / 10000 - 78642 ) ;
V_644 /= 100000 ;
V_646 = ( V_644 * V_4 -> V_142 . V_644 ) ;
V_647 = ( V_646 * V_645 ) / 10000 ;
V_647 /= 100 ;
F_227 ( V_4 ) ;
return V_4 -> V_142 . V_643 + V_647 ;
}
unsigned long F_231 ( struct V_3 * V_4 )
{
unsigned long V_381 ;
if ( V_4 -> V_623 -> V_105 != 5 )
return 0 ;
F_163 ( & V_409 ) ;
V_381 = F_230 ( V_4 ) ;
F_168 ( & V_409 ) ;
return V_381 ;
}
unsigned long F_232 ( void )
{
struct V_3 * V_4 ;
unsigned long V_649 , V_650 , V_284 = 0 ;
F_163 ( & V_409 ) ;
if ( ! V_651 )
goto V_652;
V_4 = V_651 ;
V_649 = F_222 ( V_4 ) ;
V_650 = F_230 ( V_4 ) ;
V_284 = V_649 + V_650 ;
V_652:
F_168 ( & V_409 ) ;
return V_284 ;
}
bool F_233 ( void )
{
struct V_3 * V_4 ;
bool V_284 = true ;
F_163 ( & V_409 ) ;
if ( ! V_651 ) {
V_284 = false ;
goto V_652;
}
V_4 = V_651 ;
if ( V_4 -> V_142 . V_439 > V_4 -> V_142 . V_418 )
V_4 -> V_142 . V_439 -- ;
V_652:
F_168 ( & V_409 ) ;
return V_284 ;
}
bool F_234 ( void )
{
struct V_3 * V_4 ;
bool V_284 = true ;
F_163 ( & V_409 ) ;
if ( ! V_651 ) {
V_284 = false ;
goto V_652;
}
V_4 = V_651 ;
if ( V_4 -> V_142 . V_439 < V_4 -> V_142 . V_440 )
V_4 -> V_142 . V_439 ++ ;
V_652:
F_168 ( & V_409 ) ;
return V_284 ;
}
bool F_235 ( void )
{
struct V_3 * V_4 ;
struct V_501 * V_502 ;
bool V_284 = false ;
int V_22 ;
F_163 ( & V_409 ) ;
if ( ! V_651 )
goto V_652;
V_4 = V_651 ;
F_192 (ring, dev_priv, i)
V_284 |= ! F_236 ( & V_502 -> V_653 ) ;
V_652:
F_168 ( & V_409 ) ;
return V_284 ;
}
bool F_237 ( void )
{
struct V_3 * V_4 ;
bool V_284 = true ;
F_163 ( & V_409 ) ;
if ( ! V_651 ) {
V_284 = false ;
goto V_652;
}
V_4 = V_651 ;
V_4 -> V_142 . V_439 = V_4 -> V_142 . V_420 ;
if ( ! F_158 ( V_4 -> V_2 , V_4 -> V_142 . V_420 ) )
V_284 = false ;
V_652:
F_168 ( & V_409 ) ;
return V_284 ;
}
static void
F_238 ( void )
{
void (* F_239)( void );
F_239 = F_240 ( V_654 ) ;
if ( F_239 ) {
F_239 () ;
F_241 ( V_654 ) ;
}
}
void F_242 ( struct V_3 * V_4 )
{
F_163 ( & V_409 ) ;
V_651 = V_4 ;
F_168 ( & V_409 ) ;
F_238 () ;
}
void F_243 ( void )
{
F_163 ( & V_409 ) ;
V_651 = NULL ;
F_168 ( & V_409 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_655 ;
T_8 V_656 [ 16 ] ;
int V_22 ;
F_3 ( V_657 , 0 ) ;
F_19 ( V_657 ) ;
F_3 ( V_658 , 0x15040d00 ) ;
F_3 ( V_659 , 0x007f0000 ) ;
F_3 ( V_660 , 0x1e220004 ) ;
F_3 ( V_661 , 0x04000004 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_3 ( V_662 + ( V_22 * 4 ) , 0 ) ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
F_3 ( V_663 + ( V_22 * 4 ) , 0 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ ) {
T_1 V_664 = F_2 ( V_436 + ( V_22 * 4 ) ) ;
unsigned long V_606 = F_221 ( V_664 ) ;
unsigned long V_665 = ( V_664 & V_437 ) >>
V_438 ;
unsigned long V_381 ;
V_381 = V_665 * V_665 ;
V_381 *= ( V_606 / 1000 ) ;
V_381 *= 255 ;
V_381 /= ( 127 * 127 * 900 ) ;
if ( V_381 > 0xff )
F_41 ( L_85 , V_381 ) ;
V_656 [ V_22 ] = V_381 ;
}
V_656 [ 14 ] = 0 ;
V_656 [ 15 ] = 0 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
T_1 V_381 = ( V_656 [ V_22 * 4 ] << 24 ) | ( V_656 [ ( V_22 * 4 ) + 1 ] << 16 ) |
( V_656 [ ( V_22 * 4 ) + 2 ] << 8 ) | ( V_656 [ ( V_22 * 4 ) + 3 ] ) ;
F_3 ( V_666 + ( V_22 * 4 ) , V_381 ) ;
}
F_3 ( V_667 , 0 ) ;
F_3 ( V_668 , 0 ) ;
F_3 ( V_669 , 0x00007f00 ) ;
F_3 ( V_670 , 0x0000000e ) ;
F_3 ( V_671 , 0x000e0000 ) ;
F_3 ( V_672 , 0x68000300 ) ;
F_3 ( V_673 , 0x42000000 ) ;
F_3 ( V_674 , 0x00140031 ) ;
F_3 ( V_675 , 0 ) ;
F_3 ( V_676 , 0 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_3 ( V_677 + ( V_22 * 4 ) , 0 ) ;
F_3 ( V_657 , 0x80000019 ) ;
V_655 = F_2 ( V_678 ) ;
V_4 -> V_142 . V_644 = ( V_655 & V_679 ) ;
}
void F_245 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_132 ( V_2 -> V_680 ) ;
if ( F_246 ( V_2 ) ) {
F_169 ( V_2 ) ;
F_214 ( V_2 ) ;
} else if ( F_51 ( V_2 ) -> V_105 >= 6 ) {
F_247 ( & V_4 -> V_459 . V_681 ) ;
F_248 ( & V_4 -> V_459 . V_80 ) ;
F_34 ( & V_4 -> V_459 . V_480 ) ;
if ( F_178 ( V_2 ) )
F_185 ( V_2 ) ;
else
F_184 ( V_2 ) ;
V_4 -> V_459 . V_169 = false ;
F_35 ( & V_4 -> V_459 . V_480 ) ;
}
}
static void F_249 ( struct V_77 * V_80 )
{
struct V_3 * V_4 =
F_32 ( V_80 , struct V_3 ,
V_459 . V_681 . V_80 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_34 ( & V_4 -> V_459 . V_480 ) ;
if ( F_178 ( V_2 ) ) {
F_212 ( V_2 ) ;
} else if ( F_117 ( V_2 ) ) {
F_191 ( V_2 ) ;
F_200 ( V_2 ) ;
} else {
F_195 ( V_2 ) ;
F_200 ( V_2 ) ;
}
V_4 -> V_459 . V_169 = true ;
F_35 ( & V_4 -> V_459 . V_480 ) ;
}
void F_250 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_246 ( V_2 ) ) {
F_162 ( V_2 ) ;
F_216 ( V_2 ) ;
F_244 ( V_2 ) ;
} else if ( F_24 ( V_2 ) || F_251 ( V_2 ) ) {
if ( F_178 ( V_2 ) )
F_209 ( V_2 ) ;
F_43 ( & V_4 -> V_459 . V_681 ,
F_252 ( V_682 ) ) ;
}
}
static void F_253 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_683 , V_684 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_73 ;
F_135 (pipe) {
F_3 ( F_255 ( V_73 ) ,
F_2 ( F_255 ( V_73 ) ) |
V_685 ) ;
F_256 ( V_4 , V_73 ) ;
}
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_378 , F_2 ( V_378 ) & ~ V_377 ) ;
F_3 ( V_379 , F_2 ( V_379 ) & ~ V_377 ) ;
F_3 ( V_380 , F_2 ( V_380 ) & ~ V_377 ) ;
}
static void F_258 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_686 = V_687 ;
V_686 |= V_688 |
V_689 |
V_690 ;
F_3 ( V_691 ,
V_692 |
V_693 ) ;
F_3 ( V_694 ,
V_695 ) ;
F_3 ( V_696 ,
( F_2 ( V_696 ) |
V_697 | V_698 ) ) ;
V_686 |= V_699 ;
F_3 ( V_390 ,
( F_2 ( V_390 ) |
V_391 ) ) ;
F_257 ( V_2 ) ;
if ( F_246 ( V_2 ) ) {
F_3 ( V_71 ,
F_2 ( V_71 ) |
V_72 ) ;
F_3 ( V_696 ,
F_2 ( V_696 ) |
V_697 ) ;
}
F_3 ( V_700 , V_686 ) ;
F_3 ( V_696 ,
F_2 ( V_696 ) |
V_701 ) ;
F_3 ( V_702 ,
V_703 << 16 |
V_703 ) ;
F_3 ( V_704 ,
F_90 ( V_705 ) ) ;
F_254 ( V_2 ) ;
F_253 ( V_2 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_73 ;
T_4 V_381 ;
F_3 ( V_683 , V_684 |
V_706 |
V_707 ) ;
F_3 ( V_708 , F_2 ( V_708 ) |
V_709 ) ;
F_135 (pipe) {
V_381 = F_2 ( F_260 ( V_73 ) ) ;
V_381 |= V_710 ;
V_381 &= ~ V_711 ;
if ( V_4 -> V_712 . V_713 )
V_381 |= V_711 ;
V_381 &= ~ V_714 ;
V_381 &= ~ V_715 ;
V_381 &= ~ V_716 ;
F_3 ( F_260 ( V_73 ) , V_381 ) ;
}
F_135 (pipe) {
F_3 ( F_261 ( V_73 ) ,
V_717 ) ;
}
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_122 ;
V_122 = F_2 ( V_324 ) ;
if ( ( V_122 & V_718 ) != V_719 ) {
F_187 ( L_86 , V_122 ) ;
F_187 ( L_87 ) ;
F_187 ( L_88 ) ;
}
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_686 = V_687 ;
F_3 ( V_700 , V_686 ) ;
F_3 ( V_696 ,
F_2 ( V_696 ) |
V_701 ) ;
F_3 ( V_720 ,
F_90 ( V_721 ) ) ;
if ( F_264 ( V_2 ) )
F_3 ( V_722 ,
F_90 ( V_723 ) ) ;
F_257 ( V_2 ) ;
F_3 ( V_704 ,
F_88 ( V_724 ) ) ;
F_3 ( V_725 ,
F_2 ( V_725 ) |
V_726 |
V_727 ) ;
F_3 ( V_728 ,
V_729 |
V_730 |
V_731 ) ;
F_3 ( V_732 , ( 0xFFFF << 16 ) |
V_733 ) ;
F_3 ( V_71 ,
F_2 ( V_71 ) |
V_72 | V_734 ) ;
F_3 ( V_696 ,
F_2 ( V_696 ) |
V_697 | V_698 ) ;
F_3 ( V_700 ,
F_2 ( V_700 ) |
V_699 |
V_690 ) ;
F_254 ( V_2 ) ;
F_3 ( V_722 , F_88 ( 0xffff ) ) ;
F_3 ( V_722 , F_90 ( V_735 ) ) ;
F_259 ( V_2 ) ;
F_262 ( V_2 ) ;
}
static void F_265 ( struct V_3 * V_4 )
{
T_4 V_171 = F_2 ( V_736 ) ;
V_171 &= ~ V_737 ;
V_171 |= V_738 ;
V_171 |= V_739 ;
V_171 |= V_740 ;
if ( F_52 ( V_4 -> V_2 ) )
V_171 &= ~ V_741 ;
F_3 ( V_736 , V_171 ) ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_742 == V_743 )
F_3 ( V_683 ,
F_2 ( V_683 ) |
V_744 ) ;
F_3 ( V_745 ,
F_2 ( V_745 ) |
V_717 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_742 == V_743 ) {
T_4 V_381 = F_2 ( V_683 ) ;
V_381 &= ~ V_744 ;
F_3 ( V_683 , V_381 ) ;
}
}
static void F_268 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_73 V_22 ;
F_3 ( V_378 , 0 ) ;
F_3 ( V_379 , 0 ) ;
F_3 ( V_380 , 0 ) ;
F_95 ( ! V_746 ,
L_89 ) ;
F_3 ( V_747 ,
F_90 ( V_748 ) ) ;
F_3 ( V_747 ,
F_90 ( V_749 ) ) ;
F_3 ( V_750 , F_90 ( V_751 ) ) ;
F_3 ( V_732 ,
F_269 ( 2 ) ) ;
F_3 ( V_752 ,
F_90 ( V_753 ) ) ;
F_3 ( V_754 ,
F_90 ( V_755 ) ) ;
F_3 ( V_756 , F_2 ( V_756 ) | V_757 ) ;
F_3 ( V_758 ,
F_2 ( V_758 ) | V_759 ) ;
F_135 (i) {
F_3 ( F_270 ( V_22 ) ,
F_2 ( F_270 ( V_22 ) |
V_760 ) ) ;
}
F_3 ( V_761 ,
F_2 ( V_761 ) |
F_90 ( V_762 ) ) ;
F_3 ( V_736 ,
F_2 ( V_736 ) &
~ ( V_763 | V_741 ) ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_257 ( V_2 ) ;
F_3 ( V_728 , V_764 ) ;
F_3 ( V_765 ,
V_766 ) ;
F_3 ( V_767 ,
V_768 ) ;
F_3 ( V_769 ,
V_770 ) ;
F_3 ( V_771 , V_772 ) ;
F_3 ( V_773 ,
F_90 ( V_774 ) ) ;
F_3 ( V_775 ,
F_2 ( V_775 ) |
V_776 ) ;
F_265 ( V_4 ) ;
F_3 ( V_777 ,
F_90 ( V_778 ) ) ;
F_3 ( V_756 , F_2 ( V_756 ) | V_757 ) ;
F_3 ( V_758 ,
F_2 ( V_758 ) | V_779 ) ;
F_266 ( V_2 ) ;
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_780 ;
F_257 ( V_2 ) ;
F_3 ( V_700 , V_687 ) ;
F_3 ( V_732 ,
F_90 ( V_781 ) ) ;
F_3 ( V_782 ,
V_783 |
V_784 ) ;
if ( F_273 ( V_2 ) )
F_3 ( V_754 ,
F_90 ( V_785 ) ) ;
else
F_3 ( V_786 ,
F_90 ( V_785 ) ) ;
F_3 ( V_765 ,
V_766 ) ;
F_3 ( V_767 ,
V_768 ) ;
F_3 ( V_769 ,
V_770 ) ;
if ( F_273 ( V_2 ) )
F_3 ( V_787 ,
F_90 ( V_788 ) ) ;
else
F_3 ( V_789 ,
F_90 ( V_788 ) ) ;
F_3 ( V_790 , F_2 ( V_790 ) &
~ V_791 ) ;
F_3 ( V_728 ,
V_764 |
V_731 ) ;
F_3 ( V_775 ,
F_2 ( V_775 ) |
V_776 ) ;
F_254 ( V_2 ) ;
F_265 ( V_4 ) ;
F_3 ( V_777 ,
F_90 ( V_778 ) ) ;
V_780 = F_2 ( V_792 ) ;
V_780 &= ~ V_793 ;
V_780 |= V_794 ;
F_3 ( V_792 , V_780 ) ;
if ( ! F_274 ( V_2 ) )
F_259 ( V_2 ) ;
F_262 ( V_2 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_381 ;
F_34 ( & V_4 -> V_459 . V_480 ) ;
V_381 = F_208 ( V_4 , V_583 ) ;
F_35 ( & V_4 -> V_459 . V_480 ) ;
switch ( ( V_381 >> 6 ) & 3 ) {
case 0 :
V_4 -> V_132 = 800 ;
break;
case 1 :
V_4 -> V_132 = 1066 ;
break;
case 2 :
V_4 -> V_132 = 1333 ;
break;
case 3 :
V_4 -> V_132 = 1333 ;
break;
}
F_60 ( L_90 , V_4 -> V_132 ) ;
F_3 ( V_795 , V_796 ) ;
F_3 ( V_732 ,
F_90 ( V_781 ) ) ;
F_3 ( V_782 ,
V_783 |
V_784 ) ;
F_3 ( V_754 ,
F_90 ( V_797 |
V_785 ) ) ;
F_3 ( V_765 ,
V_766 ) ;
F_3 ( V_767 , F_2 ( V_767 ) | V_798 ) ;
F_3 ( V_769 , V_770 ) ;
F_3 ( V_790 , F_2 ( V_790 ) &
~ V_791 ) ;
F_3 ( V_787 ,
F_90 ( V_788 ) ) ;
F_3 ( V_775 ,
F_2 ( V_775 ) |
V_776 ) ;
F_3 ( V_728 ,
V_729 |
V_799 |
V_764 |
V_730 |
V_731 ) ;
F_3 ( V_800 , V_801 ) ;
F_3 ( V_802 , V_803 ) ;
F_3 ( V_777 ,
F_90 ( V_778 ) ) ;
F_3 ( V_804 , 0xffffffff ) ;
F_3 ( 0x9400 , 0xffffffff ) ;
F_3 ( 0x9404 , 0xffffffff ) ;
F_3 ( 0x9408 , 0xffffffff ) ;
F_3 ( 0x940c , 0xffffffff ) ;
F_3 ( 0x9410 , 0xffffffff ) ;
F_3 ( 0x9414 , 0xffffffff ) ;
F_3 ( 0x9418 , 0xffffffff ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_686 ;
F_3 ( V_805 , 0 ) ;
F_3 ( V_806 , V_807 |
V_808 |
V_809 ) ;
F_3 ( V_810 , 0 ) ;
V_686 = V_796 |
V_811 |
V_812 ;
if ( F_277 ( V_2 ) )
V_686 |= V_813 ;
F_3 ( V_795 , V_686 ) ;
F_3 ( V_704 ,
F_90 ( V_705 ) ) ;
F_254 ( V_2 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_805 , V_814 ) ;
F_3 ( V_806 , 0 ) ;
F_3 ( V_795 , 0 ) ;
F_3 ( V_810 , 0 ) ;
F_160 ( V_815 , 0 ) ;
F_3 ( V_816 ,
F_90 ( V_803 ) ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_805 , V_817 |
V_814 |
V_818 |
V_819 |
V_820 ) ;
F_3 ( V_806 , 0 ) ;
F_3 ( V_816 ,
F_90 ( V_803 ) ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_821 = F_2 ( V_822 ) ;
V_821 |= V_823 | V_824 |
V_825 ;
F_3 ( V_822 , V_821 ) ;
if ( F_281 ( V_2 ) )
F_3 ( V_826 , F_90 ( V_827 ) ) ;
F_3 ( V_826 , F_88 ( V_828 ) ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_805 , V_829 ) ;
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_795 , V_811 ) ;
}
void F_284 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_75 . V_830 ( V_2 ) ;
}
void F_285 ( struct V_1 * V_2 )
{
if ( F_286 ( V_2 ) )
F_267 ( V_2 ) ;
}
static bool F_287 ( struct V_1 * V_2 ,
struct V_831 * V_832 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_833 ) ==
( V_834 | V_835 ) ;
}
bool F_288 ( struct V_1 * V_2 ,
enum V_836 V_837 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_838 * V_839 ;
V_839 = & V_4 -> V_839 ;
return V_839 -> V_840 [ V_837 ] ;
}
bool F_289 ( struct V_1 * V_2 ,
enum V_836 V_837 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_838 * V_839 ;
struct V_831 * V_832 ;
bool V_841 ;
int V_22 ;
V_839 = & V_4 -> V_839 ;
V_841 = true ;
F_34 ( & V_839 -> V_842 ) ;
F_290 (i, power_well, BIT(domain), power_domains) {
if ( V_832 -> V_843 )
continue;
if ( ! V_832 -> V_841 ( V_2 , V_832 ) ) {
V_841 = false ;
break;
}
}
F_35 ( & V_839 -> V_842 ) ;
return V_841 ;
}
static void F_291 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_844 ;
F_292 ( V_2 -> V_845 , V_846 ) ;
F_293 ( F_294 ( V_847 ) , V_848 ) ;
F_295 ( V_2 -> V_845 , V_846 ) ;
if ( F_117 ( V_2 ) ) {
F_296 ( & V_4 -> V_488 , V_844 ) ;
F_3 ( F_297 ( V_243 ) ,
V_4 -> V_849 [ V_243 ] ) ;
F_3 ( F_298 ( V_243 ) ,
~ V_4 -> V_849 [ V_243 ] |
V_850 ) ;
F_3 ( F_297 ( V_384 ) ,
V_4 -> V_849 [ V_384 ] ) ;
F_3 ( F_298 ( V_384 ) ,
~ V_4 -> V_849 [ V_384 ] |
V_850 ) ;
F_19 ( F_298 ( V_384 ) ) ;
F_299 ( & V_4 -> V_488 , V_844 ) ;
}
}
static void F_300 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_73 V_315 ;
unsigned long V_844 ;
F_296 ( & V_2 -> V_851 , V_844 ) ;
F_135 (p)
if ( V_315 != V_240 )
V_2 -> V_852 [ V_315 ] . V_853 = 0 ;
F_299 ( & V_2 -> V_851 , V_844 ) ;
}
static void F_301 ( struct V_1 * V_2 ,
struct V_831 * V_832 , bool V_312 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_841 , V_854 ;
T_4 V_122 ;
F_132 ( V_4 -> V_855 . V_169 ) ;
V_122 = F_2 ( V_833 ) ;
V_841 = V_122 & V_835 ;
V_854 = V_122 & V_834 ;
if ( V_312 ) {
if ( ! V_854 )
F_3 ( V_833 ,
V_834 ) ;
if ( ! V_841 ) {
F_5 ( L_91 ) ;
if ( F_4 ( ( F_2 ( V_833 ) &
V_835 ) , 20 ) )
F_41 ( L_92 ) ;
}
F_291 ( V_4 ) ;
} else {
if ( V_854 ) {
F_3 ( V_833 , 0 ) ;
F_19 ( V_833 ) ;
F_5 ( L_93 ) ;
F_300 ( V_4 ) ;
}
}
}
static void F_302 ( struct V_1 * V_2 ,
struct V_831 * V_832 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_832 -> V_639 ++ && V_832 -> V_856 ) {
F_303 ( V_4 ) ;
V_832 -> V_856 ( V_2 , V_832 , true ) ;
}
}
static void F_304 ( struct V_1 * V_2 ,
struct V_831 * V_832 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_132 ( ! V_832 -> V_639 ) ;
if ( ! -- V_832 -> V_639 && V_832 -> V_856 &&
V_857 ) {
V_832 -> V_856 ( V_2 , V_832 , false ) ;
F_305 ( V_4 ) ;
}
}
void F_306 ( struct V_1 * V_2 ,
enum V_836 V_837 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_838 * V_839 ;
struct V_831 * V_832 ;
int V_22 ;
V_839 = & V_4 -> V_839 ;
F_34 ( & V_839 -> V_842 ) ;
F_307 (i, power_well, BIT(domain), power_domains)
F_302 ( V_2 , V_832 ) ;
V_839 -> V_840 [ V_837 ] ++ ;
F_35 ( & V_839 -> V_842 ) ;
}
void F_308 ( struct V_1 * V_2 ,
enum V_836 V_837 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_838 * V_839 ;
struct V_831 * V_832 ;
int V_22 ;
V_839 = & V_4 -> V_839 ;
F_34 ( & V_839 -> V_842 ) ;
F_132 ( ! V_839 -> V_840 [ V_837 ] ) ;
V_839 -> V_840 [ V_837 ] -- ;
F_290 (i, power_well, BIT(domain), power_domains)
F_304 ( V_2 , V_832 ) ;
F_35 ( & V_839 -> V_842 ) ;
}
void F_309 ( void )
{
struct V_3 * V_4 ;
if ( F_132 ( ! V_858 ) )
return;
V_4 = F_32 ( V_858 , struct V_3 ,
V_839 ) ;
F_306 ( V_4 -> V_2 , V_859 ) ;
}
void F_310 ( void )
{
struct V_3 * V_4 ;
if ( F_132 ( ! V_858 ) )
return;
V_4 = F_32 ( V_858 , struct V_3 ,
V_839 ) ;
F_308 ( V_4 -> V_2 , V_859 ) ;
}
int F_311 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_838 * V_839 = & V_4 -> V_839 ;
F_312 ( & V_839 -> V_842 ) ;
if ( F_52 ( V_2 ) ) {
F_313 ( V_839 , V_860 ) ;
V_858 = V_839 ;
} else if ( F_117 ( V_2 ) ) {
F_313 ( V_839 , V_861 ) ;
V_858 = V_839 ;
} else {
F_313 ( V_839 , V_862 ) ;
}
return 0 ;
}
void F_314 ( struct V_1 * V_2 )
{
V_858 = NULL ;
}
static void F_315 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_838 * V_839 = & V_4 -> V_839 ;
struct V_831 * V_832 ;
int V_22 ;
F_34 ( & V_839 -> V_842 ) ;
F_307 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
if ( V_832 -> V_856 )
V_832 -> V_856 ( V_2 , V_832 , V_832 -> V_639 > 0 ) ;
}
F_35 ( & V_839 -> V_842 ) ;
}
void F_316 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_317 ( V_2 , true ) ;
F_315 ( V_2 ) ;
if ( ! ( F_52 ( V_2 ) || F_117 ( V_2 ) ) )
return;
if ( F_2 ( V_863 ) & V_834 )
F_3 ( V_863 , 0 ) ;
}
void F_318 ( struct V_3 * V_4 )
{
F_303 ( V_4 ) ;
}
void F_319 ( struct V_3 * V_4 )
{
F_305 ( V_4 ) ;
}
void F_320 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_864 * V_864 = & V_2 -> V_845 -> V_2 ;
if ( ! F_321 ( V_2 ) )
return;
F_322 ( V_864 ) ;
F_95 ( V_4 -> V_865 . V_866 , L_94 ) ;
}
void F_323 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_864 * V_864 = & V_2 -> V_845 -> V_2 ;
if ( ! F_321 ( V_2 ) )
return;
F_324 ( V_864 ) ;
F_325 ( V_864 ) ;
}
void F_326 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_864 * V_864 = & V_2 -> V_845 -> V_2 ;
V_4 -> V_865 . V_866 = false ;
if ( ! F_321 ( V_2 ) )
return;
F_327 ( V_864 ) ;
F_328 ( V_864 , 10000 ) ;
F_324 ( V_864 ) ;
F_329 ( V_864 ) ;
}
void F_330 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_864 * V_864 = & V_2 -> V_845 -> V_2 ;
if ( ! F_321 ( V_2 ) )
return;
F_322 ( V_864 ) ;
F_331 ( V_864 ) ;
}
void F_332 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_48 ( V_2 ) ) {
if ( F_51 ( V_2 ) -> V_105 >= 7 ) {
V_4 -> V_75 . V_76 = F_26 ;
V_4 -> V_75 . V_83 = F_27 ;
V_4 -> V_75 . V_88 = F_25 ;
} else if ( F_51 ( V_2 ) -> V_105 >= 5 ) {
V_4 -> V_75 . V_76 = F_26 ;
V_4 -> V_75 . V_83 = F_21 ;
V_4 -> V_75 . V_88 = F_25 ;
} else if ( F_277 ( V_2 ) ) {
V_4 -> V_75 . V_76 = F_16 ;
V_4 -> V_75 . V_83 = F_14 ;
V_4 -> V_75 . V_88 = F_15 ;
} else {
V_4 -> V_75 . V_76 = F_13 ;
V_4 -> V_75 . V_83 = F_6 ;
V_4 -> V_75 . V_88 = F_1 ;
F_3 ( V_7 , 500 << V_37 ) ;
}
}
if ( F_281 ( V_2 ) )
F_57 ( V_2 ) ;
else if ( F_22 ( V_2 ) )
F_58 ( V_2 ) ;
if ( F_333 ( V_2 ) ) {
F_123 ( V_2 ) ;
if ( ( F_22 ( V_2 ) && V_4 -> V_159 . V_316 [ 1 ] &&
V_4 -> V_159 . V_317 [ 1 ] && V_4 -> V_159 . V_318 [ 1 ] ) ||
( ! F_22 ( V_2 ) && V_4 -> V_159 . V_316 [ 0 ] &&
V_4 -> V_159 . V_317 [ 0 ] && V_4 -> V_159 . V_318 [ 0 ] ) ) {
V_4 -> V_75 . V_403 = F_143 ;
V_4 -> V_75 . V_404 = F_144 ;
} else {
F_5 ( L_95
L_96 ) ;
}
if ( F_22 ( V_2 ) )
V_4 -> V_75 . V_830 = F_258 ;
else if ( F_24 ( V_2 ) )
V_4 -> V_75 . V_830 = F_263 ;
else if ( F_28 ( V_2 ) )
V_4 -> V_75 . V_830 = F_272 ;
else if ( F_52 ( V_2 ) )
V_4 -> V_75 . V_830 = F_271 ;
else if ( F_51 ( V_2 ) -> V_105 == 8 )
V_4 -> V_75 . V_830 = F_268 ;
} else if ( F_178 ( V_2 ) ) {
V_4 -> V_75 . V_403 = F_79 ;
V_4 -> V_75 . V_830 =
F_275 ;
} else if ( F_281 ( V_2 ) ) {
if ( ! F_61 ( F_71 ( V_2 ) ,
V_4 -> V_136 ,
V_4 -> V_126 ,
V_4 -> V_132 ) ) {
F_187 ( L_97
L_98
L_99 ,
( V_4 -> V_136 == 1 ) ? L_100 : L_101 ,
V_4 -> V_126 , V_4 -> V_132 ) ;
F_63 ( V_2 ) ;
V_4 -> V_75 . V_403 = NULL ;
} else
V_4 -> V_75 . V_403 = F_70 ;
V_4 -> V_75 . V_830 = F_280 ;
} else if ( F_53 ( V_2 ) ) {
V_4 -> V_75 . V_403 = F_82 ;
V_4 -> V_75 . V_830 = F_276 ;
} else if ( F_10 ( V_2 ) ) {
V_4 -> V_75 . V_403 = F_83 ;
if ( F_84 ( V_2 ) )
V_4 -> V_75 . V_830 = F_278 ;
else if ( F_334 ( V_2 ) )
V_4 -> V_75 . V_830 = F_279 ;
} else if ( F_335 ( V_2 ) ) {
V_4 -> V_75 . V_403 = F_85 ;
V_4 -> V_75 . V_267 = F_64 ;
V_4 -> V_75 . V_830 = F_280 ;
} else if ( F_9 ( V_2 ) ) {
if ( F_51 ( V_2 ) -> V_307 == 1 ) {
V_4 -> V_75 . V_403 = F_91 ;
V_4 -> V_75 . V_267 = F_66 ;
} else {
V_4 -> V_75 . V_403 = F_85 ;
V_4 -> V_75 . V_267 = F_65 ;
}
if ( F_336 ( V_2 ) || F_337 ( V_2 ) )
V_4 -> V_75 . V_830 = F_282 ;
else
V_4 -> V_75 . V_830 = F_283 ;
} else {
F_41 ( L_102 ) ;
}
}
int F_197 ( struct V_3 * V_4 , T_8 V_867 , T_1 * V_381 )
{
F_132 ( ! F_151 ( & V_4 -> V_459 . V_480 ) ) ;
if ( F_2 ( V_868 ) & V_869 ) {
F_60 ( L_103 ) ;
return - V_870 ;
}
F_3 ( V_871 , * V_381 ) ;
F_3 ( V_868 , V_869 | V_867 ) ;
if ( F_4 ( ( F_2 ( V_868 ) & V_869 ) == 0 ,
500 ) ) {
F_41 ( L_104 , V_867 ) ;
return - V_872 ;
}
* V_381 = F_2 ( V_871 ) ;
F_3 ( V_871 , 0 ) ;
return 0 ;
}
int F_196 ( struct V_3 * V_4 , T_8 V_867 , T_1 V_381 )
{
F_132 ( ! F_151 ( & V_4 -> V_459 . V_480 ) ) ;
if ( F_2 ( V_868 ) & V_869 ) {
F_60 ( L_105 ) ;
return - V_870 ;
}
F_3 ( V_871 , V_381 ) ;
F_3 ( V_868 , V_869 | V_867 ) ;
if ( F_4 ( ( F_2 ( V_868 ) & V_869 ) == 0 ,
500 ) ) {
F_41 ( L_106 , V_867 ) ;
return - V_872 ;
}
F_3 ( V_871 , 0 ) ;
return 0 ;
}
int F_181 ( struct V_3 * V_4 , int V_381 )
{
int div ;
switch ( V_4 -> V_132 ) {
case 800 :
div = 10 ;
break;
case 1066 :
div = 12 ;
break;
case 1333 :
div = 16 ;
break;
default:
return - 1 ;
}
return F_112 ( V_4 -> V_132 * ( V_381 + 6 - 0xbd ) , 4 * div ) ;
}
int F_338 ( struct V_3 * V_4 , int V_381 )
{
int V_873 ;
switch ( V_4 -> V_132 ) {
case 800 :
V_873 = 10 ;
break;
case 1066 :
V_873 = 12 ;
break;
case 1333 :
V_873 = 16 ;
break;
default:
return - 1 ;
}
return F_112 ( 4 * V_873 * V_381 , V_4 -> V_132 ) + 0xbd - 6 ;
}
void F_339 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_312 ( & V_4 -> V_459 . V_480 ) ;
F_312 ( & V_4 -> V_855 . V_842 ) ;
V_4 -> V_855 . V_874 = false ;
V_4 -> V_855 . V_875 = false ;
V_4 -> V_855 . V_876 = false ;
V_4 -> V_855 . V_169 = false ;
V_4 -> V_855 . V_877 = 2 ;
F_42 ( & V_4 -> V_855 . V_878 , V_879 ) ;
F_42 ( & V_4 -> V_459 . V_681 ,
F_249 ) ;
}
