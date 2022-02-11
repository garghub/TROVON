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
struct V_13 * V_14 = V_12 -> V_15 -> V_14 ;
struct V_16 * V_17 = F_7 ( V_14 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
int V_21 ;
int V_22 ;
T_1 V_6 ;
V_21 = V_4 -> V_23 . V_24 / V_25 ;
if ( V_14 -> V_26 [ 0 ] < V_21 )
V_21 = V_14 -> V_26 [ 0 ] ;
if ( F_9 ( V_2 ) )
V_21 = ( V_21 / 32 ) - 1 ;
else
V_21 = ( V_21 / 64 ) - 1 ;
for ( V_22 = 0 ; V_22 < ( V_25 / 32 ) + 1 ; V_22 ++ )
F_3 ( V_27 + ( V_22 * 4 ) , 0 ) ;
if ( F_10 ( V_2 ) ) {
T_1 V_28 ;
V_28 = V_29 | V_30 | V_31 ;
V_28 |= F_11 ( V_20 -> V_32 ) ;
F_3 ( V_33 , V_28 ) ;
F_3 ( V_34 , V_12 -> V_35 ) ;
}
V_6 = F_2 ( V_7 ) ;
V_6 &= 0x3fff << V_36 ;
V_6 |= V_8 | V_37 ;
if ( F_12 ( V_2 ) )
V_6 |= V_38 ;
V_6 |= ( V_21 & 0xff ) << V_39 ;
V_6 |= V_19 -> V_40 ;
F_3 ( V_7 , V_6 ) ;
F_5 ( L_3 ,
V_21 , V_12 -> V_35 , F_13 ( V_20 -> V_32 ) ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_7 ) & V_8 ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_15 -> V_14 ;
struct V_16 * V_17 = F_7 ( V_14 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
T_1 V_41 ;
V_41 = F_16 ( V_20 -> V_32 ) | V_42 ;
if ( F_17 ( V_14 -> V_43 , 0 ) == 2 )
V_41 |= V_44 ;
else
V_41 |= V_45 ;
V_41 |= V_46 | V_19 -> V_40 ;
F_3 ( V_47 , V_12 -> V_35 ) ;
F_3 ( V_48 , V_41 | V_49 ) ;
F_5 ( L_4 , F_13 ( V_20 -> V_32 ) ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_41 ;
V_41 = F_2 ( V_48 ) ;
if ( V_41 & V_49 ) {
V_41 &= ~ V_49 ;
F_3 ( V_48 , V_41 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_48 ) & V_49 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_50 ;
F_21 ( V_4 , V_51 ) ;
V_50 = F_2 ( V_52 ) ;
V_50 |= V_53 <<
V_54 ;
F_3 ( V_52 , V_50 ) ;
V_50 |= V_53 ;
F_3 ( V_52 , V_50 ) ;
V_50 &= ~ ( V_53 <<
V_54 ) ;
F_3 ( V_52 , V_50 ) ;
F_22 ( V_52 ) ;
F_23 ( V_4 , V_51 ) ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_15 -> V_14 ;
struct V_16 * V_17 = F_7 ( V_14 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
T_1 V_41 ;
V_41 = F_16 ( V_20 -> V_32 ) ;
if ( F_17 ( V_14 -> V_43 , 0 ) == 2 )
V_41 |= V_44 ;
else
V_41 |= V_45 ;
V_41 |= V_46 ;
if ( F_25 ( V_2 ) )
V_41 |= V_19 -> V_40 ;
F_3 ( V_55 , V_12 -> V_35 ) ;
F_3 ( V_56 , F_26 ( V_19 ) | V_57 ) ;
F_3 ( V_58 , V_41 | V_49 ) ;
if ( F_27 ( V_2 ) ) {
F_3 ( V_59 ,
V_60 | V_19 -> V_40 ) ;
F_3 ( V_61 , V_12 -> V_35 ) ;
F_20 ( V_2 ) ;
}
F_5 ( L_4 , F_13 ( V_20 -> V_32 ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_41 ;
V_41 = F_2 ( V_58 ) ;
if ( V_41 & V_49 ) {
V_41 &= ~ V_49 ;
F_3 ( V_58 , V_41 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_58 ) & V_49 ;
}
static void F_30 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_15 -> V_14 ;
struct V_16 * V_17 = F_7 ( V_14 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
T_1 V_41 ;
V_41 = F_31 ( V_20 -> V_32 ) ;
if ( F_17 ( V_14 -> V_43 , 0 ) == 2 )
V_41 |= V_44 ;
else
V_41 |= V_45 ;
V_41 |= V_62 ;
F_3 ( V_58 , V_41 | V_49 ) ;
if ( F_32 ( V_2 ) ) {
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 ) ;
} else {
F_3 ( F_33 ( V_20 -> V_65 ) ,
F_2 ( F_33 ( V_20 -> V_65 ) ) |
V_66 ) ;
}
F_3 ( V_59 ,
V_60 | V_19 -> V_40 ) ;
F_3 ( V_61 , V_12 -> V_35 ) ;
F_20 ( V_2 ) ;
F_5 ( L_4 , F_13 ( V_20 -> V_32 ) ) ;
}
bool F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_67 . V_68 )
return false ;
return V_4 -> V_67 . V_68 ( V_2 ) ;
}
static void F_35 ( struct V_69 * V_70 )
{
struct V_71 * V_72 =
F_36 ( F_37 ( V_70 ) ,
struct V_71 , V_72 ) ;
struct V_1 * V_2 = V_72 -> V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_38 ( & V_2 -> V_73 ) ;
if ( V_72 == V_4 -> V_23 . V_74 ) {
if ( V_72 -> V_12 -> V_15 -> V_14 == V_72 -> V_14 ) {
V_4 -> V_67 . V_75 ( V_72 -> V_12 ) ;
V_4 -> V_23 . V_32 = F_8 ( V_72 -> V_12 ) -> V_32 ;
V_4 -> V_23 . V_76 = V_72 -> V_12 -> V_15 -> V_14 -> V_77 . V_78 ;
V_4 -> V_23 . V_35 = V_72 -> V_12 -> V_35 ;
}
V_4 -> V_23 . V_74 = NULL ;
}
F_39 ( & V_2 -> V_73 ) ;
F_40 ( V_72 ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
if ( V_4 -> V_23 . V_74 == NULL )
return;
F_5 ( L_5 ) ;
if ( F_42 ( & V_4 -> V_23 . V_74 -> V_72 ) )
F_40 ( V_4 -> V_23 . V_74 ) ;
V_4 -> V_23 . V_74 = NULL ;
}
static void F_43 ( struct V_11 * V_12 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_67 . V_75 )
return;
F_41 ( V_4 ) ;
V_72 = F_44 ( sizeof( * V_72 ) , V_79 ) ;
if ( V_72 == NULL ) {
F_45 ( L_6 ) ;
V_4 -> V_67 . V_75 ( V_12 ) ;
return;
}
V_72 -> V_12 = V_12 ;
V_72 -> V_14 = V_12 -> V_15 -> V_14 ;
F_46 ( & V_72 -> V_72 , F_35 ) ;
V_4 -> V_23 . V_74 = V_72 ;
F_47 ( & V_72 -> V_72 , F_48 ( 50 ) ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_41 ( V_4 ) ;
if ( ! V_4 -> V_67 . V_80 )
return;
V_4 -> V_67 . V_80 ( V_2 ) ;
V_4 -> V_23 . V_32 = - 1 ;
}
static bool F_50 ( struct V_3 * V_4 ,
enum V_81 V_82 )
{
if ( V_4 -> V_23 . V_81 == V_82 )
return false ;
V_4 -> V_23 . V_81 = V_82 ;
return true ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 = NULL , * V_83 ;
struct V_20 * V_20 ;
struct V_13 * V_14 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
const struct V_84 * V_85 ;
unsigned int V_86 , V_87 ;
if ( ! F_52 ( V_2 ) ) {
F_50 ( V_4 , V_88 ) ;
return;
}
if ( ! V_89 . V_90 ) {
if ( F_50 ( V_4 , V_91 ) )
F_5 ( L_7 ) ;
return;
}
F_53 (tmp_crtc, &dev->mode_config.crtc_list, head) {
if ( F_54 ( V_83 ) &&
F_8 ( V_83 ) -> V_92 ) {
if ( V_12 ) {
if ( F_50 ( V_4 , V_93 ) )
F_5 ( L_8 ) ;
goto V_94;
}
V_12 = V_83 ;
}
}
if ( ! V_12 || V_12 -> V_15 -> V_14 == NULL ) {
if ( F_50 ( V_4 , V_95 ) )
F_5 ( L_9 ) ;
goto V_94;
}
V_20 = F_8 ( V_12 ) ;
V_14 = V_12 -> V_15 -> V_14 ;
V_17 = F_7 ( V_14 ) ;
V_19 = V_17 -> V_19 ;
V_85 = & V_20 -> V_96 . V_85 ;
if ( V_89 . V_75 < 0 &&
F_55 ( V_2 ) -> V_97 <= 7 && ! F_56 ( V_2 ) ) {
if ( F_50 ( V_4 , V_98 ) )
F_5 ( L_10 ) ;
goto V_94;
}
if ( ! V_89 . V_75 ) {
if ( F_50 ( V_4 , V_91 ) )
F_5 ( L_7 ) ;
goto V_94;
}
if ( ( V_85 -> V_99 & V_100 ) ||
( V_85 -> V_99 & V_101 ) ) {
if ( F_50 ( V_4 , V_102 ) )
F_5 ( L_11
L_12 ) ;
goto V_94;
}
if ( F_57 ( V_2 ) || F_55 ( V_2 ) -> V_97 >= 5 ) {
V_86 = 4096 ;
V_87 = 2048 ;
} else {
V_86 = 2048 ;
V_87 = 1536 ;
}
if ( V_20 -> V_96 . V_103 > V_86 ||
V_20 -> V_96 . V_104 > V_87 ) {
if ( F_50 ( V_4 , V_105 ) )
F_5 ( L_13 ) ;
goto V_94;
}
if ( ( F_55 ( V_2 ) -> V_97 < 4 || F_58 ( V_2 ) ) &&
V_20 -> V_32 != V_106 ) {
if ( F_50 ( V_4 , V_107 ) )
F_5 ( L_14 ) ;
goto V_94;
}
if ( V_19 -> V_108 != V_109 ||
V_19 -> V_40 == V_110 ) {
if ( F_50 ( V_4 , V_111 ) )
F_5 ( L_15 ) ;
goto V_94;
}
if ( F_59 () )
goto V_94;
if ( F_60 ( V_2 , V_17 -> V_19 -> V_77 . V_24 ) ) {
if ( F_50 ( V_4 , V_112 ) )
F_5 ( L_16 ) ;
goto V_94;
}
if ( V_4 -> V_23 . V_32 == V_20 -> V_32 &&
V_4 -> V_23 . V_76 == V_14 -> V_77 . V_78 &&
V_4 -> V_23 . V_35 == V_12 -> V_35 )
return;
if ( F_34 ( V_2 ) ) {
F_5 ( L_17 ) ;
F_49 ( V_2 ) ;
}
F_43 ( V_12 ) ;
V_4 -> V_23 . V_81 = V_113 ;
return;
V_94:
if ( F_34 ( V_2 ) ) {
F_5 ( L_18 ) ;
F_49 ( V_2 ) ;
}
F_61 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_114 ;
V_114 = F_2 ( V_115 ) ;
switch ( V_114 & V_116 ) {
case V_117 :
V_4 -> V_118 = 533 ;
break;
case V_119 :
V_4 -> V_118 = 800 ;
break;
case V_120 :
V_4 -> V_118 = 667 ;
break;
case V_121 :
V_4 -> V_118 = 400 ;
break;
}
switch ( V_114 & V_122 ) {
case V_123 :
V_4 -> V_124 = 533 ;
break;
case V_125 :
V_4 -> V_124 = 667 ;
break;
case V_126 :
V_4 -> V_124 = 800 ;
break;
}
V_114 = F_2 ( V_127 ) ;
V_4 -> V_128 = ( V_114 & V_129 ) ? 1 : 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_130 , V_131 ;
V_130 = F_64 ( V_132 ) ;
V_131 = F_64 ( V_133 ) ;
switch ( V_130 & 0xff ) {
case 0xc :
V_4 -> V_124 = 800 ;
break;
case 0x10 :
V_4 -> V_124 = 1066 ;
break;
case 0x14 :
V_4 -> V_124 = 1333 ;
break;
case 0x18 :
V_4 -> V_124 = 1600 ;
break;
default:
F_65 ( L_19 ,
V_130 & 0xff ) ;
V_4 -> V_124 = 0 ;
break;
}
V_4 -> V_134 . V_135 = V_4 -> V_124 ;
switch ( V_131 & 0x3ff ) {
case 0x00c :
V_4 -> V_118 = 3200 ;
break;
case 0x00e :
V_4 -> V_118 = 3733 ;
break;
case 0x010 :
V_4 -> V_118 = 4266 ;
break;
case 0x012 :
V_4 -> V_118 = 4800 ;
break;
case 0x014 :
V_4 -> V_118 = 5333 ;
break;
case 0x016 :
V_4 -> V_118 = 5866 ;
break;
case 0x018 :
V_4 -> V_118 = 6400 ;
break;
default:
F_65 ( L_20 ,
V_131 & 0x3ff ) ;
V_4 -> V_118 = 0 ;
break;
}
if ( V_4 -> V_118 == 3200 ) {
V_4 -> V_134 . V_136 = 0 ;
} else if ( V_4 -> V_118 > 3200 && V_4 -> V_118 <= 4800 ) {
V_4 -> V_134 . V_136 = 1 ;
} else {
V_4 -> V_134 . V_136 = 2 ;
}
}
static const struct V_137 * F_66 ( int V_138 ,
int V_128 ,
int V_139 ,
int V_140 )
{
const struct V_137 * V_141 ;
int V_22 ;
if ( V_139 == 0 || V_140 == 0 )
return NULL ;
for ( V_22 = 0 ; V_22 < F_67 ( V_142 ) ; V_22 ++ ) {
V_141 = & V_142 [ V_22 ] ;
if ( V_138 == V_141 -> V_138 &&
V_128 == V_141 -> V_128 &&
V_139 == V_141 -> V_118 && V_140 == V_141 -> V_124 )
return V_141 ;
}
F_5 ( L_21 ) ;
return NULL ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_143 , F_2 ( V_143 ) & ~ V_144 ) ;
}
static int F_69 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_145 = F_2 ( V_146 ) ;
int V_24 ;
V_24 = V_145 & 0x7f ;
if ( V_32 )
V_24 = ( ( V_145 >> V_147 ) & 0x7f ) - V_24 ;
F_5 ( L_22 , V_145 ,
V_32 ? L_23 : L_24 , V_24 ) ;
return V_24 ;
}
static int F_70 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_145 = F_2 ( V_146 ) ;
int V_24 ;
V_24 = V_145 & 0x1ff ;
if ( V_32 )
V_24 = ( ( V_145 >> V_148 ) & 0x1ff ) - V_24 ;
V_24 >>= 1 ;
F_5 ( L_22 , V_145 ,
V_32 ? L_23 : L_24 , V_24 ) ;
return V_24 ;
}
static int F_71 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_145 = F_2 ( V_146 ) ;
int V_24 ;
V_24 = V_145 & 0x7f ;
V_24 >>= 2 ;
F_5 ( L_22 , V_145 ,
V_32 ? L_23 : L_24 ,
V_24 ) ;
return V_24 ;
}
static unsigned long F_72 ( unsigned long V_149 ,
const struct V_150 * V_151 ,
int V_152 ,
int V_153 ,
unsigned long V_154 )
{
long V_155 , V_156 ;
V_155 = ( ( V_149 / 1000 ) * V_153 * V_154 ) /
1000 ;
V_155 = F_73 ( V_155 , V_151 -> V_157 ) ;
F_5 ( L_25 , V_155 ) ;
V_156 = V_152 - ( V_155 + V_151 -> V_158 ) ;
F_5 ( L_26 , V_156 ) ;
if ( V_156 > ( long ) V_151 -> V_159 )
V_156 = V_151 -> V_159 ;
if ( V_156 <= 0 )
V_156 = V_151 -> V_160 ;
return V_156 ;
}
static struct V_11 * F_74 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_161 = NULL ;
F_53 (crtc, &dev->mode_config.crtc_list, head) {
if ( F_54 ( V_12 ) ) {
if ( V_161 )
return NULL ;
V_161 = V_12 ;
}
}
return V_161 ;
}
static void F_75 ( struct V_11 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_137 * V_141 ;
T_1 V_163 ;
unsigned long V_151 ;
V_141 = F_66 ( F_76 ( V_2 ) , V_4 -> V_128 ,
V_4 -> V_118 , V_4 -> V_124 ) ;
if ( ! V_141 ) {
F_5 ( L_21 ) ;
F_68 ( V_2 ) ;
return;
}
V_12 = F_74 ( V_2 ) ;
if ( V_12 ) {
const struct V_84 * V_85 ;
int V_153 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
int clock ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
clock = V_85 -> V_165 ;
V_151 = F_72 ( clock , & V_166 ,
V_166 . V_152 ,
V_153 , V_141 -> V_167 ) ;
V_163 = F_2 ( V_168 ) ;
V_163 &= ~ V_169 ;
V_163 |= V_151 << V_170 ;
F_3 ( V_168 , V_163 ) ;
F_5 ( L_27 , V_163 ) ;
V_151 = F_72 ( clock , & V_171 ,
V_166 . V_152 ,
V_153 , V_141 -> V_172 ) ;
V_163 = F_2 ( V_143 ) ;
V_163 &= ~ V_173 ;
V_163 |= ( V_151 & 0x3f ) << V_174 ;
F_3 ( V_143 , V_163 ) ;
V_151 = F_72 ( clock , & V_175 ,
V_175 . V_152 ,
V_153 , V_141 -> V_176 ) ;
V_163 = F_2 ( V_143 ) ;
V_163 &= ~ V_177 ;
V_163 |= V_151 & V_177 ;
F_3 ( V_143 , V_163 ) ;
V_151 = F_72 ( clock , & V_178 ,
V_175 . V_152 ,
V_153 , V_141 -> V_179 ) ;
V_163 = F_2 ( V_143 ) ;
V_163 &= ~ V_180 ;
V_163 |= ( V_151 & 0x3f ) << V_181 ;
F_3 ( V_143 , V_163 ) ;
F_5 ( L_28 , V_163 ) ;
F_3 ( V_143 ,
F_2 ( V_143 ) | V_144 ) ;
F_5 ( L_29 ) ;
} else {
F_68 ( V_2 ) ;
F_5 ( L_30 ) ;
}
}
static bool F_77 ( struct V_1 * V_2 ,
int V_32 ,
const struct V_150 * V_67 ,
int V_182 ,
const struct V_150 * V_183 ,
int V_184 ,
int * V_185 ,
int * V_186 )
{
struct V_11 * V_12 ;
const struct V_84 * V_85 ;
int V_187 , V_188 , clock , V_153 ;
int V_189 , V_190 ;
int V_191 , V_192 ;
V_12 = F_78 ( V_2 , V_32 ) ;
if ( ! F_54 ( V_12 ) ) {
* V_186 = V_183 -> V_158 ;
* V_185 = V_67 -> V_158 ;
return false ;
}
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
clock = V_85 -> V_165 ;
V_187 = V_85 -> V_193 ;
V_188 = F_8 ( V_12 ) -> V_96 . V_103 ;
V_153 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
V_191 = ( ( clock * V_153 / 1000 ) * V_182 ) / 1000 ;
V_192 = V_67 -> V_152 * V_67 -> V_157 - V_188 * 8 ;
if ( V_192 > 0 )
V_191 += V_192 ;
V_191 = F_73 ( V_191 , V_67 -> V_157 ) ;
* V_185 = V_191 + V_67 -> V_158 ;
if ( * V_185 > ( int ) V_67 -> V_159 )
* V_185 = V_67 -> V_159 ;
V_189 = F_79 ( V_187 * 1000 / clock , 1 ) ;
V_190 = ( V_184 / V_189 + 1000 ) / 1000 ;
V_191 = V_190 * F_8 ( V_12 ) -> V_194 * V_153 ;
V_192 = V_183 -> V_152 * V_183 -> V_157 - V_188 * 8 ;
if ( V_192 > 0 )
V_191 += V_192 ;
V_191 = F_73 ( V_191 , V_183 -> V_157 ) ;
* V_186 = V_191 + V_183 -> V_158 ;
if ( * V_186 > ( int ) V_183 -> V_159 )
* V_186 = ( int ) V_183 -> V_159 ;
return true ;
}
static bool F_80 ( struct V_1 * V_2 ,
int V_195 , int V_186 ,
const struct V_150 * V_67 ,
const struct V_150 * V_183 )
{
F_5 ( L_31 ,
V_195 , V_186 ) ;
if ( V_195 > V_67 -> V_159 ) {
F_5 ( L_32 ,
V_195 , V_67 -> V_159 ) ;
return false ;
}
if ( V_186 > V_183 -> V_159 ) {
F_5 ( L_33 ,
V_186 , V_183 -> V_159 ) ;
return false ;
}
if ( ! ( V_195 || V_186 ) ) {
F_5 ( L_34 ) ;
return false ;
}
return true ;
}
static bool F_81 ( struct V_1 * V_2 ,
int V_32 ,
int V_154 ,
const struct V_150 * V_67 ,
const struct V_150 * V_183 ,
int * V_195 , int * V_186 )
{
struct V_11 * V_12 ;
const struct V_84 * V_85 ;
int V_188 , V_187 , V_153 , clock ;
unsigned long V_189 ;
int V_190 , V_196 ;
int V_197 , V_198 ;
int V_191 ;
if ( ! V_154 ) {
* V_195 = * V_186 = 0 ;
return false ;
}
V_12 = F_78 ( V_2 , V_32 ) ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
clock = V_85 -> V_165 ;
V_187 = V_85 -> V_193 ;
V_188 = F_8 ( V_12 ) -> V_96 . V_103 ;
V_153 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
V_189 = F_79 ( V_187 * 1000 / clock , 1 ) ;
V_190 = ( V_154 / V_189 + 1000 ) / 1000 ;
V_196 = V_188 * V_153 ;
V_197 = ( ( clock * V_153 / 1000 ) * V_154 ) / 1000 ;
V_198 = V_190 * V_196 ;
V_191 = F_73 ( F_82 ( V_197 , V_198 ) , V_67 -> V_157 ) ;
* V_195 = V_191 + V_67 -> V_158 ;
V_191 = V_190 * V_153 * F_8 ( V_12 ) -> V_194 ;
V_191 = F_73 ( V_191 , V_183 -> V_157 ) ;
* V_186 = V_191 + V_183 -> V_158 ;
return F_80 ( V_2 ,
* V_195 , * V_186 ,
V_67 , V_183 ) ;
}
static bool F_83 ( struct V_1 * V_2 ,
int V_32 ,
int * V_199 ,
int * V_200 ,
int * V_201 ,
int * V_202 )
{
struct V_11 * V_12 ;
int clock , V_153 ;
int V_191 ;
V_12 = F_78 ( V_2 , V_32 ) ;
if ( ! F_54 ( V_12 ) )
return false ;
clock = F_8 ( V_12 ) -> V_96 . V_85 . V_165 ;
V_153 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
V_191 = ( clock / 1000 ) * V_153 ;
* V_199 = ( V_191 > 256 ) ?
V_203 : V_204 ;
* V_200 = ( 64 * ( * V_199 ) * 4 ) / ( ( clock / 1000 ) *
V_153 ) ;
V_191 = ( clock / 1000 ) * 4 ;
* V_201 = ( V_191 > 256 ) ?
V_203 : V_204 ;
* V_202 = ( 64 * ( * V_201 ) * 4 ) / ( ( clock / 1000 ) * 4 ) ;
return true ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_205 , V_206 , V_207 , V_208 ;
int V_209 , V_210 , V_211 , V_212 ;
int V_199 , V_201 ;
if ( F_83 ( V_2 , 0 , & V_199 , & V_206 ,
& V_201 , & V_210 ) ) {
V_209 = ( V_201 == V_203 ) ?
V_213 : V_214 ;
V_205 = ( V_199 == V_203 ) ?
V_215 : V_216 ;
F_3 ( V_217 , V_209 |
( V_210 << V_218 ) |
V_205 | V_206 ) ;
}
if ( F_83 ( V_2 , 1 , & V_199 , & V_208 ,
& V_201 , & V_212 ) ) {
V_211 = ( V_201 == V_203 ) ?
V_219 : V_220 ;
V_207 = ( V_199 == V_203 ) ?
V_221 : V_222 ;
F_3 ( V_223 , V_211 |
( V_212 << V_224 ) |
V_207 | V_208 ) ;
}
}
static void F_85 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_225 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_226 , V_227 , V_228 , V_229 ;
int V_230 , V_172 ;
int V_231 , V_232 ;
unsigned int V_161 = 0 ;
F_84 ( V_2 ) ;
if ( F_77 ( V_2 , V_233 ,
& V_234 , V_154 ,
& V_235 , V_154 ,
& V_226 , & V_228 ) )
V_161 |= 1 << V_233 ;
if ( F_77 ( V_2 , V_236 ,
& V_234 , V_154 ,
& V_235 , V_154 ,
& V_227 , & V_229 ) )
V_161 |= 1 << V_236 ;
if ( F_86 ( V_161 ) &&
F_81 ( V_2 , F_87 ( V_161 ) - 1 ,
V_225 ,
& V_234 ,
& V_235 ,
& V_230 , & V_232 ) &&
F_81 ( V_2 , F_87 ( V_161 ) - 1 ,
2 * V_225 ,
& V_234 ,
& V_235 ,
& V_231 , & V_172 ) ) {
F_3 ( V_237 , V_238 ) ;
} else {
F_3 ( V_237 ,
F_2 ( V_237 ) & ~ V_238 ) ;
V_230 = V_172 = 0 ;
}
F_5 ( L_35 ,
V_226 , V_228 ,
V_227 , V_229 ,
V_230 , V_172 ) ;
F_3 ( V_168 ,
( V_230 << V_170 ) |
( V_229 << V_239 ) |
( V_227 << V_240 ) |
V_226 ) ;
F_3 ( V_241 ,
( F_2 ( V_241 ) & ~ V_242 ) |
( V_228 << V_243 ) ) ;
F_3 ( V_143 ,
( F_2 ( V_143 ) & ~ V_173 ) |
( V_172 << V_174 ) ) ;
}
static void F_88 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_225 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_226 , V_227 , V_228 , V_229 ;
int V_230 , V_172 ;
unsigned int V_161 = 0 ;
if ( F_77 ( V_2 , V_233 ,
& V_244 , V_154 ,
& V_245 , V_154 ,
& V_226 , & V_228 ) )
V_161 |= 1 << V_233 ;
if ( F_77 ( V_2 , V_236 ,
& V_244 , V_154 ,
& V_245 , V_154 ,
& V_227 , & V_229 ) )
V_161 |= 1 << V_236 ;
if ( F_86 ( V_161 ) &&
F_81 ( V_2 , F_87 ( V_161 ) - 1 ,
V_225 ,
& V_244 ,
& V_245 ,
& V_230 , & V_172 ) ) {
F_3 ( V_246 , V_247 ) ;
} else {
F_3 ( V_246 ,
F_2 ( V_246 ) & ~ V_247 ) ;
V_230 = V_172 = 0 ;
}
F_5 ( L_35 ,
V_226 , V_228 ,
V_227 , V_229 ,
V_230 , V_172 ) ;
F_3 ( V_168 ,
( V_230 << V_170 ) |
( V_229 << V_239 ) |
( V_227 << V_240 ) |
V_226 ) ;
F_3 ( V_241 ,
( F_2 ( V_241 ) & ~ V_242 ) |
( V_228 << V_243 ) ) ;
F_3 ( V_143 ,
( F_2 ( V_143 ) & ~ ( V_248 | V_173 ) ) |
( V_172 << V_174 ) ) ;
}
static void F_89 ( struct V_11 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
int V_249 = 1 ;
int V_172 = 16 ;
V_12 = F_74 ( V_2 ) ;
if ( V_12 ) {
static const int V_225 = 12000 ;
const struct V_84 * V_85 =
& F_8 ( V_12 ) -> V_96 . V_85 ;
int clock = V_85 -> V_165 ;
int V_187 = V_85 -> V_193 ;
int V_188 = F_8 ( V_12 ) -> V_96 . V_103 ;
int V_153 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
unsigned long V_189 ;
int V_191 ;
V_189 = F_79 ( V_187 * 1000 / clock , 1 ) ;
V_191 = ( ( ( V_225 / V_189 ) + 1000 ) / 1000 ) *
V_153 * V_188 ;
V_191 = F_73 ( V_191 , V_250 ) ;
V_249 = V_251 - V_191 ;
if ( V_249 < 0 )
V_249 = 1 ;
V_249 &= 0x1ff ;
F_5 ( L_36 ,
V_191 , V_249 ) ;
V_191 = ( ( ( V_225 / V_189 ) + 1000 ) / 1000 ) *
V_153 * F_8 ( V_12 ) -> V_194 ;
V_191 = F_73 ( V_191 ,
V_252 . V_157 ) ;
V_172 = V_252 . V_152 -
( V_191 + V_252 . V_158 ) ;
if ( V_172 > V_252 . V_159 )
V_172 = V_252 . V_159 ;
F_5 ( L_37
L_38 , V_249 , V_172 ) ;
if ( F_90 ( V_2 ) )
F_3 ( V_246 , V_247 ) ;
} else {
if ( F_90 ( V_2 ) )
F_3 ( V_246 , F_2 ( V_246 )
& ~ V_247 ) ;
}
F_5 ( L_39 ,
V_249 ) ;
F_3 ( V_168 , ( V_249 << V_170 ) |
( 8 << 16 ) | ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_3 ( V_241 , ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_3 ( V_143 , ( V_172 << V_174 ) ) ;
}
static void F_91 ( struct V_11 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_150 * V_253 ;
T_3 V_254 ;
T_3 V_255 ;
int V_256 , V_249 = 1 ;
int V_152 ;
int V_226 , V_227 ;
struct V_11 * V_12 , * V_161 = NULL ;
if ( F_12 ( V_2 ) )
V_253 = & V_257 ;
else if ( ! F_9 ( V_2 ) )
V_253 = & V_258 ;
else
V_253 = & V_259 ;
V_152 = V_4 -> V_67 . V_260 ( V_2 , 0 ) ;
V_12 = F_78 ( V_2 , 0 ) ;
if ( F_54 ( V_12 ) ) {
const struct V_84 * V_85 ;
int V_261 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
if ( F_9 ( V_2 ) )
V_261 = 4 ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_226 = F_72 ( V_85 -> V_165 ,
V_253 , V_152 , V_261 ,
V_154 ) ;
V_161 = V_12 ;
} else
V_226 = V_152 - V_253 -> V_158 ;
V_152 = V_4 -> V_67 . V_260 ( V_2 , 1 ) ;
V_12 = F_78 ( V_2 , 1 ) ;
if ( F_54 ( V_12 ) ) {
const struct V_84 * V_85 ;
int V_261 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
if ( F_9 ( V_2 ) )
V_261 = 4 ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_227 = F_72 ( V_85 -> V_165 ,
V_253 , V_152 , V_261 ,
V_154 ) ;
if ( V_161 == NULL )
V_161 = V_12 ;
else
V_161 = NULL ;
} else
V_227 = V_152 - V_253 -> V_158 ;
F_5 ( L_40 , V_226 , V_227 ) ;
if ( F_92 ( V_2 ) && V_161 ) {
struct V_16 * V_14 ;
V_14 = F_7 ( V_161 -> V_15 -> V_14 ) ;
if ( V_14 -> V_19 -> V_108 == V_262 )
V_161 = NULL ;
}
V_256 = 2 ;
if ( F_93 ( V_2 ) || F_12 ( V_2 ) )
F_3 ( V_246 , V_263 | 0 ) ;
else if ( F_92 ( V_2 ) )
F_3 ( V_264 , F_94 ( V_265 ) ) ;
if ( F_95 ( V_2 ) && V_161 ) {
static const int V_225 = 6000 ;
const struct V_84 * V_85 =
& F_8 ( V_161 ) -> V_96 . V_85 ;
int clock = V_85 -> V_165 ;
int V_187 = V_85 -> V_193 ;
int V_188 = F_8 ( V_161 ) -> V_96 . V_103 ;
int V_153 = V_161 -> V_15 -> V_14 -> V_164 / 8 ;
unsigned long V_189 ;
int V_191 ;
V_189 = F_79 ( V_187 * 1000 / clock , 1 ) ;
V_191 = ( ( ( V_225 / V_189 ) + 1000 ) / 1000 ) *
V_153 * V_188 ;
V_191 = F_73 ( V_191 , V_253 -> V_157 ) ;
F_5 ( L_41 , V_191 ) ;
V_249 = V_253 -> V_152 - V_191 ;
if ( V_249 < 0 )
V_249 = 1 ;
if ( F_93 ( V_2 ) || F_12 ( V_2 ) )
F_3 ( V_246 ,
V_266 | ( V_249 & 0xff ) ) ;
else if ( F_92 ( V_2 ) )
F_3 ( V_246 , V_249 & 0x3f ) ;
}
F_5 ( L_42 ,
V_226 , V_227 , V_256 , V_249 ) ;
V_254 = ( ( V_227 & 0x3f ) << 16 ) | ( V_226 & 0x3f ) ;
V_255 = ( V_256 & 0x1f ) ;
V_254 = V_254 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_255 = V_255 | ( 1 << 8 ) ;
F_3 ( V_267 , V_254 ) ;
F_3 ( V_268 , V_255 ) ;
if ( F_95 ( V_2 ) ) {
if ( V_161 ) {
if ( F_93 ( V_2 ) || F_12 ( V_2 ) )
F_3 ( V_246 ,
V_263 | V_247 ) ;
else if ( F_92 ( V_2 ) )
F_3 ( V_264 , F_96 ( V_265 ) ) ;
F_5 ( L_43 ) ;
} else
F_5 ( L_44 ) ;
}
}
static void F_97 ( struct V_11 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_84 * V_85 ;
T_3 V_254 ;
int V_226 ;
V_12 = F_74 ( V_2 ) ;
if ( V_12 == NULL )
return;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_226 = F_72 ( V_85 -> V_165 ,
& V_269 ,
V_4 -> V_67 . V_260 ( V_2 , 0 ) ,
4 , V_154 ) ;
V_254 = F_2 ( V_267 ) & ~ 0xfff ;
V_254 |= ( 3 << 8 ) | V_226 ;
F_5 ( L_45 , V_226 ) ;
F_3 ( V_267 , V_254 ) ;
}
static T_3 F_98 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_20 * V_20 = F_8 ( V_12 ) ;
T_3 V_270 ;
V_270 = V_20 -> V_96 . V_85 . V_165 ;
if ( V_20 -> V_96 . V_271 . V_161 ) {
T_4 V_272 , V_273 , V_274 , V_275 ;
T_3 V_276 = V_20 -> V_96 . V_271 . V_24 ;
V_272 = V_20 -> V_96 . V_103 ;
V_273 = V_20 -> V_96 . V_104 ;
V_274 = ( V_276 >> 16 ) & 0xFFFF ;
V_275 = V_276 & 0xFFFF ;
if ( V_272 < V_274 )
V_272 = V_274 ;
if ( V_273 < V_275 )
V_273 = V_275 ;
V_270 = F_99 ( ( T_4 ) V_270 * V_272 * V_273 ,
V_274 * V_275 ) ;
}
return V_270 ;
}
static T_3 F_100 ( T_3 V_270 , T_5 V_277 ,
T_3 V_141 )
{
T_4 V_278 ;
if ( F_101 ( V_141 == 0 , L_46 ) )
return V_279 ;
V_278 = ( T_4 ) V_270 * V_277 * V_141 ;
V_278 = F_102 ( V_278 , 64 * 10000 ) + 2 ;
return V_278 ;
}
static T_3 F_103 ( T_3 V_270 , T_3 V_280 ,
T_3 V_281 , T_5 V_277 ,
T_3 V_141 )
{
T_3 V_278 ;
if ( F_101 ( V_141 == 0 , L_46 ) )
return V_279 ;
V_278 = ( V_141 * V_270 ) / ( V_280 * 10000 ) ;
V_278 = ( V_278 + 1 ) * V_281 * V_277 ;
V_278 = F_73 ( V_278 , 64 ) + 2 ;
return V_278 ;
}
static T_3 F_104 ( T_3 V_282 , T_3 V_281 ,
T_5 V_277 )
{
return F_73 ( V_282 * 64 , V_281 * V_277 ) + 2 ;
}
static T_3 F_105 ( const struct V_283 * V_284 ,
T_3 V_285 ,
bool V_286 )
{
T_3 V_287 , V_288 ;
if ( ! V_284 -> V_289 || ! V_284 -> V_290 . V_161 )
return 0 ;
V_287 = F_100 ( V_284 -> V_270 ,
V_284 -> V_290 . V_277 ,
V_285 ) ;
if ( ! V_286 )
return V_287 ;
V_288 = F_103 ( V_284 -> V_270 ,
V_284 -> V_280 ,
V_284 -> V_290 . V_281 ,
V_284 -> V_290 . V_277 ,
V_285 ) ;
return F_82 ( V_287 , V_288 ) ;
}
static T_3 F_106 ( const struct V_283 * V_284 ,
T_3 V_285 )
{
T_3 V_287 , V_288 ;
if ( ! V_284 -> V_289 || ! V_284 -> V_291 . V_161 )
return 0 ;
V_287 = F_100 ( V_284 -> V_270 ,
V_284 -> V_291 . V_277 ,
V_285 ) ;
V_288 = F_103 ( V_284 -> V_270 ,
V_284 -> V_280 ,
V_284 -> V_291 . V_281 ,
V_284 -> V_291 . V_277 ,
V_285 ) ;
return F_82 ( V_287 , V_288 ) ;
}
static T_3 F_107 ( const struct V_283 * V_284 ,
T_3 V_285 )
{
if ( ! V_284 -> V_289 || ! V_284 -> V_292 . V_161 )
return 0 ;
return F_103 ( V_284 -> V_270 ,
V_284 -> V_280 ,
V_284 -> V_292 . V_281 ,
V_284 -> V_292 . V_277 ,
V_285 ) ;
}
static T_3 F_108 ( const struct V_283 * V_284 ,
T_3 V_282 )
{
if ( ! V_284 -> V_289 || ! V_284 -> V_290 . V_161 )
return 0 ;
return F_104 ( V_282 ,
V_284 -> V_290 . V_281 ,
V_284 -> V_290 . V_277 ) ;
}
static unsigned int F_109 ( const struct V_1 * V_2 )
{
if ( F_55 ( V_2 ) -> V_97 >= 8 )
return 3072 ;
else if ( F_55 ( V_2 ) -> V_97 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_110 ( const struct V_1 * V_2 ,
int V_293 ,
const struct V_294 * V_96 ,
enum V_295 V_296 ,
bool V_297 )
{
unsigned int V_152 = F_109 ( V_2 ) ;
unsigned int F_79 ;
if ( V_297 && ! V_96 -> V_298 )
return 0 ;
if ( V_293 == 0 || V_96 -> V_299 > 1 ) {
V_152 /= F_55 ( V_2 ) -> V_300 ;
if ( F_55 ( V_2 ) -> V_97 <= 6 )
V_152 /= 2 ;
}
if ( V_96 -> V_298 ) {
if ( V_293 > 0 && V_296 == V_301 ) {
if ( V_297 )
V_152 *= 5 ;
V_152 /= 6 ;
} else {
V_152 /= 2 ;
}
}
if ( F_55 ( V_2 ) -> V_97 >= 8 )
F_79 = V_293 == 0 ? 255 : 2047 ;
else if ( F_55 ( V_2 ) -> V_97 >= 7 )
F_79 = V_293 == 0 ? 127 : 1023 ;
else if ( ! V_297 )
F_79 = V_293 == 0 ? 127 : 511 ;
else
F_79 = V_293 == 0 ? 63 : 255 ;
return F_82 ( V_152 , F_79 ) ;
}
static unsigned int F_111 ( const struct V_1 * V_2 ,
int V_293 ,
const struct V_294 * V_96 )
{
if ( V_293 > 0 && V_96 -> V_299 > 1 )
return 64 ;
if ( F_55 ( V_2 ) -> V_97 >= 7 )
return V_293 == 0 ? 63 : 255 ;
else
return V_293 == 0 ? 31 : 63 ;
}
static unsigned int F_112 ( const struct V_1 * V_2 )
{
if ( F_55 ( V_2 ) -> V_97 >= 8 )
return 31 ;
else
return 15 ;
}
static void F_113 ( const struct V_1 * V_2 ,
int V_293 ,
const struct V_294 * V_96 ,
enum V_295 V_296 ,
struct V_302 * F_79 )
{
F_79 -> V_290 = F_110 ( V_2 , V_293 , V_96 , V_296 , false ) ;
F_79 -> V_291 = F_110 ( V_2 , V_293 , V_96 , V_296 , true ) ;
F_79 -> V_292 = F_111 ( V_2 , V_293 , V_96 ) ;
F_79 -> V_23 = F_112 ( V_2 ) ;
}
static bool F_114 ( int V_293 ,
const struct V_302 * F_79 ,
struct V_303 * V_304 )
{
bool V_278 ;
if ( ! V_304 -> V_305 )
return false ;
V_304 -> V_305 = V_304 -> V_282 <= F_79 -> V_290 &&
V_304 -> V_306 <= F_79 -> V_291 &&
V_304 -> V_307 <= F_79 -> V_292 ;
V_278 = V_304 -> V_305 ;
if ( V_293 == 0 && ! V_304 -> V_305 ) {
if ( V_304 -> V_282 > F_79 -> V_290 )
F_5 ( L_47 ,
V_293 , V_304 -> V_282 , F_79 -> V_290 ) ;
if ( V_304 -> V_306 > F_79 -> V_291 )
F_5 ( L_48 ,
V_293 , V_304 -> V_306 , F_79 -> V_291 ) ;
if ( V_304 -> V_307 > F_79 -> V_292 )
F_5 ( L_49 ,
V_293 , V_304 -> V_307 , F_79 -> V_292 ) ;
V_304 -> V_282 = F_115 ( T_3 , V_304 -> V_282 , F_79 -> V_290 ) ;
V_304 -> V_306 = F_115 ( T_3 , V_304 -> V_306 , F_79 -> V_291 ) ;
V_304 -> V_307 = F_115 ( T_3 , V_304 -> V_307 , F_79 -> V_292 ) ;
V_304 -> V_305 = true ;
}
return V_278 ;
}
static void F_116 ( const struct V_3 * V_4 ,
int V_293 ,
const struct V_283 * V_308 ,
struct V_303 * V_304 )
{
T_6 V_309 = V_4 -> V_151 . V_309 [ V_293 ] ;
T_6 V_310 = V_4 -> V_151 . V_310 [ V_293 ] ;
T_6 V_311 = V_4 -> V_151 . V_311 [ V_293 ] ;
if ( V_293 > 0 ) {
V_309 *= 5 ;
V_310 *= 5 ;
V_311 *= 5 ;
}
V_304 -> V_282 = F_105 ( V_308 , V_309 , V_293 ) ;
V_304 -> V_306 = F_106 ( V_308 , V_310 ) ;
V_304 -> V_307 = F_107 ( V_308 , V_311 ) ;
V_304 -> V_312 = F_108 ( V_308 , V_304 -> V_282 ) ;
V_304 -> V_305 = true ;
}
static T_3
F_117 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
struct V_84 * V_313 = & V_20 -> V_96 . V_85 ;
T_1 V_314 , V_315 ;
if ( ! F_54 ( V_12 ) )
return 0 ;
V_314 = F_118 ( V_313 -> V_193 * 1000 * 8 ,
V_313 -> V_165 ) ;
V_315 = F_118 ( V_313 -> V_193 * 1000 * 8 ,
F_119 ( V_4 ) ) ;
return F_120 ( V_315 ) |
F_121 ( V_314 ) ;
}
static void F_122 ( struct V_1 * V_2 , T_6 V_151 [ 5 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_56 ( V_2 ) || F_123 ( V_2 ) ) {
T_4 V_316 = F_124 ( V_317 ) ;
V_151 [ 0 ] = ( V_316 >> 56 ) & 0xFF ;
if ( V_151 [ 0 ] == 0 )
V_151 [ 0 ] = V_316 & 0xF ;
V_151 [ 1 ] = ( V_316 >> 4 ) & 0xFF ;
V_151 [ 2 ] = ( V_316 >> 12 ) & 0xFF ;
V_151 [ 3 ] = ( V_316 >> 20 ) & 0x1FF ;
V_151 [ 4 ] = ( V_316 >> 32 ) & 0x1FF ;
} else if ( F_55 ( V_2 ) -> V_97 >= 6 ) {
T_3 V_316 = F_2 ( V_317 ) ;
V_151 [ 0 ] = ( V_316 >> V_318 ) & V_319 ;
V_151 [ 1 ] = ( V_316 >> V_320 ) & V_319 ;
V_151 [ 2 ] = ( V_316 >> V_321 ) & V_319 ;
V_151 [ 3 ] = ( V_316 >> V_322 ) & V_319 ;
} else if ( F_55 ( V_2 ) -> V_97 >= 5 ) {
T_3 V_323 = F_2 ( V_324 ) ;
V_151 [ 0 ] = 7 ;
V_151 [ 1 ] = ( V_323 >> V_325 ) & V_326 ;
V_151 [ 2 ] = ( V_323 >> V_327 ) & V_326 ;
}
}
static void F_125 ( struct V_1 * V_2 , T_6 V_151 [ 5 ] )
{
if ( F_55 ( V_2 ) -> V_97 == 5 )
V_151 [ 0 ] = 13 ;
}
static void F_126 ( struct V_1 * V_2 , T_6 V_151 [ 5 ] )
{
if ( F_55 ( V_2 ) -> V_97 == 5 )
V_151 [ 0 ] = 13 ;
if ( F_32 ( V_2 ) )
V_151 [ 3 ] *= 2 ;
}
static int F_127 ( const struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) || F_123 ( V_2 ) )
return 4 ;
else if ( F_55 ( V_2 ) -> V_97 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_128 ( struct V_1 * V_2 ,
const char * V_328 ,
const T_6 V_151 [ 5 ] )
{
int V_293 , V_329 = F_127 ( V_2 ) ;
for ( V_293 = 0 ; V_293 <= V_329 ; V_293 ++ ) {
unsigned int V_141 = V_151 [ V_293 ] ;
if ( V_141 == 0 ) {
F_45 ( L_50 ,
V_328 , V_293 ) ;
continue;
}
if ( V_293 > 0 )
V_141 *= 5 ;
F_5 ( L_51 ,
V_328 , V_293 , V_151 [ V_293 ] ,
V_141 / 10 , V_141 % 10 ) ;
}
}
static bool F_129 ( struct V_3 * V_4 ,
T_6 V_151 [ 5 ] , T_6 F_82 )
{
int V_293 , V_329 = F_127 ( V_4 -> V_2 ) ;
if ( V_151 [ 0 ] >= F_82 )
return false ;
V_151 [ 0 ] = F_79 ( V_151 [ 0 ] , F_82 ) ;
for ( V_293 = 1 ; V_293 <= V_329 ; V_293 ++ )
V_151 [ V_293 ] = F_130 ( T_6 , V_151 [ V_293 ] , F_73 ( F_82 , 5 ) ) ;
return true ;
}
static void F_131 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_330 ;
V_330 = F_129 ( V_4 , V_4 -> V_151 . V_309 , 12 ) |
F_129 ( V_4 , V_4 -> V_151 . V_310 , 12 ) |
F_129 ( V_4 , V_4 -> V_151 . V_311 , 12 ) ;
if ( ! V_330 )
return;
F_5 ( L_52 ) ;
F_128 ( V_2 , L_53 , V_4 -> V_151 . V_309 ) ;
F_128 ( V_2 , L_54 , V_4 -> V_151 . V_310 ) ;
F_128 ( V_2 , L_55 , V_4 -> V_151 . V_311 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_122 ( V_2 , V_4 -> V_151 . V_309 ) ;
memcpy ( V_4 -> V_151 . V_310 , V_4 -> V_151 . V_309 ,
sizeof( V_4 -> V_151 . V_309 ) ) ;
memcpy ( V_4 -> V_151 . V_311 , V_4 -> V_151 . V_309 ,
sizeof( V_4 -> V_151 . V_309 ) ) ;
F_125 ( V_2 , V_4 -> V_151 . V_310 ) ;
F_126 ( V_2 , V_4 -> V_151 . V_311 ) ;
F_128 ( V_2 , L_53 , V_4 -> V_151 . V_309 ) ;
F_128 ( V_2 , L_54 , V_4 -> V_151 . V_310 ) ;
F_128 ( V_2 , L_55 , V_4 -> V_151 . V_311 ) ;
if ( F_27 ( V_2 ) )
F_131 ( V_2 ) ;
}
static void F_133 ( struct V_11 * V_12 ,
struct V_283 * V_308 ,
struct V_294 * V_96 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
enum V_65 V_65 = V_20 -> V_65 ;
struct V_331 * V_32 ;
V_308 -> V_289 = F_54 ( V_12 ) ;
if ( V_308 -> V_289 ) {
V_308 -> V_280 = V_20 -> V_96 . V_85 . V_193 ;
V_308 -> V_270 = F_98 ( V_2 , V_12 ) ;
V_308 -> V_290 . V_277 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
V_308 -> V_292 . V_277 = 4 ;
V_308 -> V_290 . V_281 = V_20 -> V_96 . V_103 ;
V_308 -> V_292 . V_281 = V_20 -> V_194 ;
V_308 -> V_290 . V_161 = true ;
V_308 -> V_292 . V_161 = true ;
}
F_53 (crtc, &dev->mode_config.crtc_list, head)
V_96 -> V_299 += F_54 ( V_12 ) ;
F_134 (plane, &dev->mode_config.plane_list) {
struct V_332 * V_332 = F_135 ( V_32 ) ;
if ( V_332 -> V_65 == V_65 )
V_308 -> V_291 = V_332 -> V_151 ;
V_96 -> V_298 |= V_332 -> V_151 . V_161 ;
V_96 -> V_333 |= V_332 -> V_151 . V_334 ;
}
}
static bool F_136 ( struct V_11 * V_12 ,
const struct V_283 * V_284 ,
struct V_335 * V_336 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
int V_293 , V_329 = F_127 ( V_2 ) ;
struct V_294 V_96 = {
. V_299 = 1 ,
. V_298 = V_284 -> V_291 . V_161 ,
. V_333 = V_284 -> V_291 . V_334 ,
} ;
struct V_302 F_79 ;
F_113 ( V_2 , 0 , & V_96 , V_337 , & F_79 ) ;
if ( F_55 ( V_2 ) -> V_97 <= 6 && V_284 -> V_291 . V_161 )
V_329 = 1 ;
if ( V_284 -> V_291 . V_334 )
V_329 = 0 ;
for ( V_293 = 0 ; V_293 <= V_329 ; V_293 ++ )
F_116 ( V_4 , V_293 , V_284 ,
& V_336 -> V_151 [ V_293 ] ) ;
if ( F_56 ( V_2 ) || F_123 ( V_2 ) )
V_336 -> V_314 = F_117 ( V_2 , V_12 ) ;
return F_114 ( 0 , & F_79 , & V_336 -> V_151 [ 0 ] ) ;
}
static void F_137 ( struct V_1 * V_2 ,
int V_293 ,
struct V_303 * V_338 )
{
const struct V_20 * V_20 ;
F_53 (intel_crtc, &dev->mode_config.crtc_list, base.head) {
const struct V_303 * V_151 =
& V_20 -> V_151 . V_289 . V_151 [ V_293 ] ;
if ( ! V_151 -> V_305 )
return;
V_338 -> V_282 = F_79 ( V_338 -> V_282 , V_151 -> V_282 ) ;
V_338 -> V_306 = F_79 ( V_338 -> V_306 , V_151 -> V_306 ) ;
V_338 -> V_307 = F_79 ( V_338 -> V_307 , V_151 -> V_307 ) ;
V_338 -> V_312 = F_79 ( V_338 -> V_312 , V_151 -> V_312 ) ;
}
V_338 -> V_305 = true ;
}
static void F_138 ( struct V_1 * V_2 ,
const struct V_294 * V_96 ,
const struct V_302 * F_79 ,
struct V_335 * V_339 )
{
int V_293 , V_329 = F_127 ( V_2 ) ;
if ( ( F_55 ( V_2 ) -> V_97 <= 6 || F_32 ( V_2 ) ) &&
V_96 -> V_299 > 1 )
return;
V_339 -> V_340 = F_55 ( V_2 ) -> V_97 >= 6 ;
for ( V_293 = 1 ; V_293 <= V_329 ; V_293 ++ ) {
struct V_303 * V_151 = & V_339 -> V_151 [ V_293 ] ;
F_137 ( V_2 , V_293 , V_151 ) ;
if ( ! F_114 ( V_293 , F_79 , V_151 ) )
break;
if ( V_151 -> V_312 > F_79 -> V_23 ) {
V_339 -> V_340 = false ;
V_151 -> V_312 = 0 ;
}
}
if ( F_25 ( V_2 ) && ! V_339 -> V_340 && F_34 ( V_2 ) ) {
for ( V_293 = 2 ; V_293 <= V_329 ; V_293 ++ ) {
struct V_303 * V_151 = & V_339 -> V_151 [ V_293 ] ;
V_151 -> V_305 = false ;
}
}
}
static int F_139 ( int V_341 , const struct V_335 * V_336 )
{
return V_341 + ( V_341 >= 2 && V_336 -> V_151 [ 4 ] . V_305 ) ;
}
static unsigned int F_140 ( struct V_1 * V_2 , int V_293 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_56 ( V_2 ) || F_123 ( V_2 ) )
return 2 * V_293 ;
else
return V_4 -> V_151 . V_309 [ V_293 ] ;
}
static void F_141 ( struct V_1 * V_2 ,
const struct V_335 * V_339 ,
enum V_295 V_342 ,
struct V_343 * V_344 )
{
struct V_20 * V_20 ;
int V_293 , V_341 ;
V_344 -> V_345 = V_339 -> V_340 ;
V_344 -> V_342 = V_342 ;
for ( V_341 = 1 ; V_341 <= 3 ; V_341 ++ ) {
const struct V_303 * V_346 ;
V_293 = F_139 ( V_341 , V_339 ) ;
V_346 = & V_339 -> V_151 [ V_293 ] ;
if ( ! V_346 -> V_305 )
break;
V_344 -> V_341 [ V_341 - 1 ] = V_347 |
( F_140 ( V_2 , V_293 ) << V_348 ) |
( V_346 -> V_282 << V_349 ) |
V_346 -> V_307 ;
if ( F_55 ( V_2 ) -> V_97 >= 8 )
V_344 -> V_341 [ V_341 - 1 ] |=
V_346 -> V_312 << V_350 ;
else
V_344 -> V_341 [ V_341 - 1 ] |=
V_346 -> V_312 << V_351 ;
if ( F_55 ( V_2 ) -> V_97 <= 6 && V_346 -> V_306 ) {
F_142 ( V_341 != 1 ) ;
V_344 -> V_352 [ V_341 - 1 ] = V_353 | V_346 -> V_306 ;
} else
V_344 -> V_352 [ V_341 - 1 ] = V_346 -> V_306 ;
}
F_53 (intel_crtc, &dev->mode_config.crtc_list, base.head) {
enum V_65 V_65 = V_20 -> V_65 ;
const struct V_303 * V_346 =
& V_20 -> V_151 . V_289 . V_151 [ 0 ] ;
if ( F_142 ( ! V_346 -> V_305 ) )
continue;
V_344 -> V_354 [ V_65 ] = V_20 -> V_151 . V_289 . V_314 ;
V_344 -> V_355 [ V_65 ] =
( V_346 -> V_282 << V_356 ) |
( V_346 -> V_306 << V_357 ) |
V_346 -> V_307 ;
}
}
static struct V_335 * F_143 ( struct V_1 * V_2 ,
struct V_335 * V_358 ,
struct V_335 * V_359 )
{
int V_293 , V_329 = F_127 ( V_2 ) ;
int V_360 = 0 , V_361 = 0 ;
for ( V_293 = 1 ; V_293 <= V_329 ; V_293 ++ ) {
if ( V_358 -> V_151 [ V_293 ] . V_305 )
V_360 = V_293 ;
if ( V_359 -> V_151 [ V_293 ] . V_305 )
V_361 = V_293 ;
}
if ( V_360 == V_361 ) {
if ( V_359 -> V_340 && ! V_358 -> V_340 )
return V_359 ;
else
return V_358 ;
} else if ( V_360 > V_361 ) {
return V_358 ;
} else {
return V_359 ;
}
}
static unsigned int F_144 ( struct V_1 * V_2 ,
const struct V_343 * V_362 ,
const struct V_343 * V_363 )
{
unsigned int V_364 = 0 ;
enum V_65 V_65 ;
int V_341 ;
F_145 (pipe) {
if ( V_362 -> V_354 [ V_65 ] != V_363 -> V_354 [ V_65 ] ) {
V_364 |= F_146 ( V_65 ) ;
V_364 |= V_365 ;
}
if ( V_362 -> V_355 [ V_65 ] != V_363 -> V_355 [ V_65 ] ) {
V_364 |= F_147 ( V_65 ) ;
V_364 |= V_365 ;
}
}
if ( V_362 -> V_345 != V_363 -> V_345 ) {
V_364 |= V_366 ;
V_364 |= V_365 ;
}
if ( V_362 -> V_342 != V_363 -> V_342 ) {
V_364 |= V_367 ;
V_364 |= V_365 ;
}
if ( V_364 & V_365 )
return V_364 ;
for ( V_341 = 1 ; V_341 <= 3 ; V_341 ++ ) {
if ( V_362 -> V_341 [ V_341 - 1 ] != V_363 -> V_341 [ V_341 - 1 ] ||
V_362 -> V_352 [ V_341 - 1 ] != V_363 -> V_352 [ V_341 - 1 ] )
break;
}
for (; V_341 <= 3 ; V_341 ++ )
V_364 |= F_148 ( V_341 ) ;
return V_364 ;
}
static bool F_149 ( struct V_3 * V_4 ,
unsigned int V_364 )
{
struct V_343 * V_368 = & V_4 -> V_151 . V_369 ;
bool V_330 = false ;
if ( V_364 & F_148 ( 3 ) && V_368 -> V_341 [ 2 ] & V_370 ) {
V_368 -> V_341 [ 2 ] &= ~ V_370 ;
F_3 ( V_371 , V_368 -> V_341 [ 2 ] ) ;
V_330 = true ;
}
if ( V_364 & F_148 ( 2 ) && V_368 -> V_341 [ 1 ] & V_370 ) {
V_368 -> V_341 [ 1 ] &= ~ V_370 ;
F_3 ( V_372 , V_368 -> V_341 [ 1 ] ) ;
V_330 = true ;
}
if ( V_364 & F_148 ( 1 ) && V_368 -> V_341 [ 0 ] & V_370 ) {
V_368 -> V_341 [ 0 ] &= ~ V_370 ;
F_3 ( V_373 , V_368 -> V_341 [ 0 ] ) ;
V_330 = true ;
}
return V_330 ;
}
static void F_150 ( struct V_3 * V_4 ,
struct V_343 * V_344 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_343 * V_368 = & V_4 -> V_151 . V_369 ;
unsigned int V_364 ;
T_3 V_374 ;
V_364 = F_144 ( V_2 , V_368 , V_344 ) ;
if ( ! V_364 )
return;
F_149 ( V_4 , V_364 ) ;
if ( V_364 & F_147 ( V_233 ) )
F_3 ( V_375 , V_344 -> V_355 [ 0 ] ) ;
if ( V_364 & F_147 ( V_236 ) )
F_3 ( V_376 , V_344 -> V_355 [ 1 ] ) ;
if ( V_364 & F_147 ( V_377 ) )
F_3 ( V_378 , V_344 -> V_355 [ 2 ] ) ;
if ( V_364 & F_146 ( V_233 ) )
F_3 ( F_151 ( V_233 ) , V_344 -> V_354 [ 0 ] ) ;
if ( V_364 & F_146 ( V_236 ) )
F_3 ( F_151 ( V_236 ) , V_344 -> V_354 [ 1 ] ) ;
if ( V_364 & F_146 ( V_377 ) )
F_3 ( F_151 ( V_377 ) , V_344 -> V_354 [ 2 ] ) ;
if ( V_364 & V_367 ) {
if ( F_56 ( V_2 ) || F_123 ( V_2 ) ) {
V_374 = F_2 ( V_379 ) ;
if ( V_344 -> V_342 == V_337 )
V_374 &= ~ V_380 ;
else
V_374 |= V_380 ;
F_3 ( V_379 , V_374 ) ;
} else {
V_374 = F_2 ( V_381 ) ;
if ( V_344 -> V_342 == V_337 )
V_374 &= ~ V_382 ;
else
V_374 |= V_382 ;
F_3 ( V_381 , V_374 ) ;
}
}
if ( V_364 & V_366 ) {
V_374 = F_2 ( V_383 ) ;
if ( V_344 -> V_345 )
V_374 &= ~ V_384 ;
else
V_374 |= V_384 ;
F_3 ( V_383 , V_374 ) ;
}
if ( V_364 & F_148 ( 1 ) &&
V_368 -> V_352 [ 0 ] != V_344 -> V_352 [ 0 ] )
F_3 ( V_385 , V_344 -> V_352 [ 0 ] ) ;
if ( F_55 ( V_2 ) -> V_97 >= 7 ) {
if ( V_364 & F_148 ( 2 ) && V_368 -> V_352 [ 1 ] != V_344 -> V_352 [ 1 ] )
F_3 ( V_386 , V_344 -> V_352 [ 1 ] ) ;
if ( V_364 & F_148 ( 3 ) && V_368 -> V_352 [ 2 ] != V_344 -> V_352 [ 2 ] )
F_3 ( V_387 , V_344 -> V_352 [ 2 ] ) ;
}
if ( V_364 & F_148 ( 1 ) && V_368 -> V_341 [ 0 ] != V_344 -> V_341 [ 0 ] )
F_3 ( V_373 , V_344 -> V_341 [ 0 ] ) ;
if ( V_364 & F_148 ( 2 ) && V_368 -> V_341 [ 1 ] != V_344 -> V_341 [ 1 ] )
F_3 ( V_372 , V_344 -> V_341 [ 1 ] ) ;
if ( V_364 & F_148 ( 3 ) && V_368 -> V_341 [ 2 ] != V_344 -> V_341 [ 2 ] )
F_3 ( V_371 , V_344 -> V_341 [ 2 ] ) ;
V_4 -> V_151 . V_369 = * V_344 ;
}
static bool F_152 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_149 ( V_4 , V_365 ) ;
}
static void F_153 ( struct V_11 * V_12 )
{
struct V_20 * V_20 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_302 F_79 ;
struct V_283 V_284 = {} ;
struct V_343 V_344 = {} ;
enum V_295 V_342 ;
struct V_335 V_336 = {} ;
struct V_335 V_388 = {} , V_389 = {} , * V_390 ;
struct V_294 V_96 = {} ;
F_133 ( V_12 , & V_284 , & V_96 ) ;
F_136 ( V_12 , & V_284 , & V_336 ) ;
if ( ! memcmp ( & V_20 -> V_151 . V_289 , & V_336 , sizeof( V_336 ) ) )
return;
V_20 -> V_151 . V_289 = V_336 ;
F_113 ( V_2 , 1 , & V_96 , V_337 , & F_79 ) ;
F_138 ( V_2 , & V_96 , & F_79 , & V_388 ) ;
if ( F_55 ( V_2 ) -> V_97 >= 7 &&
V_96 . V_299 == 1 && V_96 . V_298 ) {
F_113 ( V_2 , 1 , & V_96 , V_301 , & F_79 ) ;
F_138 ( V_2 , & V_96 , & F_79 , & V_389 ) ;
V_390 = F_143 ( V_2 , & V_388 , & V_389 ) ;
} else {
V_390 = & V_388 ;
}
V_342 = ( V_390 == & V_388 ) ?
V_337 : V_301 ;
F_141 ( V_2 , V_390 , V_342 , & V_344 ) ;
F_150 ( V_4 , & V_344 ) ;
}
static void F_154 ( struct V_331 * V_32 ,
struct V_11 * V_12 ,
T_3 V_391 , int V_153 ,
bool V_161 , bool V_334 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_332 * V_332 = F_135 ( V_32 ) ;
V_332 -> V_151 . V_161 = V_161 ;
V_332 -> V_151 . V_334 = V_334 ;
V_332 -> V_151 . V_281 = V_391 ;
V_332 -> V_151 . V_277 = V_153 ;
if ( F_32 ( V_2 ) && V_334 && F_152 ( V_2 ) )
F_155 ( V_2 , V_332 -> V_65 ) ;
F_153 ( V_12 ) ;
}
static void F_156 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_343 * V_369 = & V_4 -> V_151 . V_369 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
struct V_335 * V_289 = & V_20 -> V_151 . V_289 ;
enum V_65 V_65 = V_20 -> V_65 ;
static const unsigned int V_392 [] = {
[ V_233 ] = V_375 ,
[ V_236 ] = V_376 ,
[ V_377 ] = V_378 ,
} ;
V_369 -> V_355 [ V_65 ] = F_2 ( V_392 [ V_65 ] ) ;
if ( F_56 ( V_2 ) || F_123 ( V_2 ) )
V_369 -> V_354 [ V_65 ] = F_2 ( F_151 ( V_65 ) ) ;
if ( F_54 ( V_12 ) ) {
T_1 V_114 = V_369 -> V_355 [ V_65 ] ;
V_289 -> V_151 [ 0 ] . V_305 = true ;
V_289 -> V_151 [ 0 ] . V_282 = ( V_114 & V_393 ) >> V_356 ;
V_289 -> V_151 [ 0 ] . V_306 = ( V_114 & V_394 ) >> V_357 ;
V_289 -> V_151 [ 0 ] . V_307 = V_114 & V_395 ;
V_289 -> V_314 = V_369 -> V_354 [ V_65 ] ;
} else {
int V_293 , V_329 = F_127 ( V_2 ) ;
for ( V_293 = 0 ; V_293 <= V_329 ; V_293 ++ )
V_289 -> V_151 [ V_293 ] . V_305 = true ;
}
}
void F_157 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_343 * V_369 = & V_4 -> V_151 . V_369 ;
struct V_11 * V_12 ;
F_53 (crtc, &dev->mode_config.crtc_list, head)
F_156 ( V_12 ) ;
V_369 -> V_341 [ 0 ] = F_2 ( V_373 ) ;
V_369 -> V_341 [ 1 ] = F_2 ( V_372 ) ;
V_369 -> V_341 [ 2 ] = F_2 ( V_371 ) ;
V_369 -> V_352 [ 0 ] = F_2 ( V_385 ) ;
V_369 -> V_352 [ 1 ] = F_2 ( V_386 ) ;
V_369 -> V_352 [ 2 ] = F_2 ( V_387 ) ;
if ( F_56 ( V_2 ) || F_123 ( V_2 ) )
V_369 -> V_342 = ( F_2 ( V_379 ) & V_380 ) ?
V_301 : V_337 ;
else if ( F_32 ( V_2 ) )
V_369 -> V_342 = ( F_2 ( V_381 ) & V_382 ) ?
V_301 : V_337 ;
V_369 -> V_345 =
! ( F_2 ( V_383 ) & V_384 ) ;
}
void F_158 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_2 -> V_5 ;
if ( V_4 -> V_67 . V_396 )
V_4 -> V_67 . V_396 ( V_12 ) ;
}
void F_159 ( struct V_331 * V_32 ,
struct V_11 * V_12 ,
T_3 V_391 , int V_153 ,
bool V_161 , bool V_334 )
{
struct V_3 * V_4 = V_32 -> V_2 -> V_5 ;
if ( V_4 -> V_67 . V_397 )
V_4 -> V_67 . V_397 ( V_32 , V_12 , V_391 ,
V_153 , V_161 , V_334 ) ;
}
static struct V_18 *
F_160 ( struct V_1 * V_2 )
{
struct V_18 * V_398 ;
int V_278 ;
F_142 ( ! F_161 ( & V_2 -> V_73 ) ) ;
V_398 = F_162 ( V_2 , 4096 ) ;
if ( ! V_398 ) {
F_163 ( L_56 ) ;
return NULL ;
}
V_278 = F_164 ( V_398 , 4096 , 0 ) ;
if ( V_278 ) {
F_45 ( L_57 , V_278 ) ;
goto V_399;
}
V_278 = F_165 ( V_398 , 1 ) ;
if ( V_278 ) {
F_45 ( L_58 , V_278 ) ;
goto V_400;
}
return V_398 ;
V_400:
F_166 ( V_398 ) ;
V_399:
F_167 ( & V_398 -> V_77 ) ;
return NULL ;
}
bool F_168 ( struct V_1 * V_2 , T_7 V_374 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_401 ;
F_169 ( & V_402 ) ;
V_401 = F_64 ( V_403 ) ;
if ( V_401 & V_404 ) {
F_163 ( L_59 ) ;
return false ;
}
V_401 = ( V_405 << V_406 ) |
( V_374 << V_407 ) | V_408 ;
F_170 ( V_403 , V_401 ) ;
F_171 ( V_403 ) ;
V_401 |= V_404 ;
F_170 ( V_403 , V_401 ) ;
return true ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_409 = F_2 ( V_410 ) ;
T_7 V_411 , V_412 , V_413 , V_414 ;
F_173 ( & V_402 ) ;
F_170 ( V_415 , F_2 ( V_415 ) | V_416 ) ;
F_170 ( V_417 , F_2 ( V_417 ) | V_418 ) ;
F_3 ( V_419 , 100000 ) ;
F_3 ( V_420 , 100000 ) ;
F_3 ( V_421 , 90000 ) ;
F_3 ( V_422 , 80000 ) ;
F_3 ( V_423 , 1 ) ;
V_411 = ( V_409 & V_424 ) >> V_425 ;
V_412 = ( V_409 & V_426 ) ;
V_413 = ( V_409 & V_427 ) >>
V_428 ;
V_414 = ( F_2 ( V_429 + ( V_413 * 4 ) ) & V_430 ) >>
V_431 ;
V_4 -> V_134 . V_411 = V_411 ;
V_4 -> V_134 . V_413 = V_413 ;
V_4 -> V_134 . V_432 = V_413 ;
V_4 -> V_134 . V_433 = V_412 ;
V_4 -> V_134 . V_434 = V_413 ;
F_65 ( L_60 ,
V_411 , V_412 , V_413 ) ;
F_3 ( V_435 , V_436 | V_437 ) ;
F_3 ( V_438 , V_414 ) ;
F_22 ( V_438 ) ;
V_409 |= V_439 ;
F_3 ( V_410 , V_409 ) ;
if ( F_174 ( ( F_2 ( V_403 ) & V_404 ) == 0 , 10 ) )
F_45 ( L_61 ) ;
F_175 ( 1 ) ;
F_168 ( V_2 , V_413 ) ;
V_4 -> V_134 . V_440 = F_2 ( 0x112e4 ) + F_2 ( 0x112e8 ) +
F_2 ( 0x112e0 ) ;
V_4 -> V_134 . V_441 = F_176 ( V_442 ) ;
V_4 -> V_134 . V_443 = F_2 ( 0x112f4 ) ;
F_177 ( & V_4 -> V_134 . V_444 ) ;
F_178 ( & V_402 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_401 ;
F_173 ( & V_402 ) ;
V_401 = F_64 ( V_403 ) ;
F_3 ( V_435 , F_2 ( V_435 ) & ~ V_437 ) ;
F_3 ( V_445 , V_446 ) ;
F_3 ( V_447 , F_2 ( V_447 ) & ~ V_448 ) ;
F_3 ( V_449 , V_448 ) ;
F_3 ( V_450 , F_2 ( V_450 ) | V_448 ) ;
F_168 ( V_2 , V_4 -> V_134 . V_413 ) ;
F_175 ( 1 ) ;
V_401 |= V_404 ;
F_3 ( V_403 , V_401 ) ;
F_175 ( 1 ) ;
F_178 ( & V_402 ) ;
}
static T_1 F_180 ( struct V_3 * V_4 , T_7 V_374 )
{
T_1 V_451 ;
V_451 = V_4 -> V_452 . V_453 << 24 ;
if ( V_374 <= V_4 -> V_452 . V_454 )
V_451 |= V_4 -> V_452 . V_454 << 16 ;
return V_451 ;
}
static void F_181 ( struct V_3 * V_4 , T_7 V_374 )
{
int V_455 ;
V_455 = V_4 -> V_452 . V_456 ;
switch ( V_4 -> V_452 . V_456 ) {
case V_457 :
if ( V_374 > V_4 -> V_452 . V_458 + 1 && V_374 > V_4 -> V_452 . V_459 )
V_455 = V_460 ;
break;
case V_460 :
if ( V_374 <= V_4 -> V_452 . V_458 && V_374 < V_4 -> V_452 . V_459 )
V_455 = V_457 ;
else if ( V_374 >= V_4 -> V_452 . V_461 && V_374 > V_4 -> V_452 . V_459 )
V_455 = V_462 ;
break;
case V_462 :
if ( V_374 < ( V_4 -> V_452 . V_463 + V_4 -> V_452 . V_461 ) > > 1 && V_374 < V_4 -> V_452 . V_459 )
V_455 = V_460 ;
break;
}
if ( V_374 == V_4 -> V_452 . V_454 )
V_455 = V_457 ;
if ( V_374 == V_4 -> V_452 . V_453 )
V_455 = V_462 ;
if ( V_455 == V_4 -> V_452 . V_456 )
return;
switch ( V_455 ) {
case V_457 :
F_3 ( V_464 , 12500 ) ;
F_3 ( V_465 , 11800 ) ;
F_3 ( V_466 , 25000 ) ;
F_3 ( V_467 , 21250 ) ;
F_3 ( V_468 ,
V_469 |
V_470 |
V_471 |
V_472 |
V_473 |
V_474 ) ;
break;
case V_460 :
F_3 ( V_464 , 10250 ) ;
F_3 ( V_465 , 9225 ) ;
F_3 ( V_466 , 25000 ) ;
F_3 ( V_467 , 18750 ) ;
F_3 ( V_468 ,
V_469 |
V_470 |
V_471 |
V_472 |
V_473 |
V_474 ) ;
break;
case V_462 :
F_3 ( V_464 , 8000 ) ;
F_3 ( V_465 , 6800 ) ;
F_3 ( V_466 , 25000 ) ;
F_3 ( V_467 , 15000 ) ;
F_3 ( V_468 ,
V_469 |
V_470 |
V_471 |
V_472 |
V_473 |
V_474 ) ;
break;
}
V_4 -> V_452 . V_456 = V_455 ;
V_4 -> V_452 . V_475 = 0 ;
}
static T_1 F_182 ( struct V_3 * V_4 , T_7 V_374 )
{
T_1 V_476 = 0 ;
if ( V_374 > V_4 -> V_452 . V_454 )
V_476 |= V_477 | V_478 ;
if ( V_374 < V_4 -> V_452 . V_453 )
V_476 |= V_479 ;
if ( F_55 ( V_4 -> V_2 ) -> V_97 <= 7 && ! F_56 ( V_4 -> V_2 ) )
V_476 |= V_480 ;
return ~ V_476 ;
}
void F_183 ( struct V_1 * V_2 , T_7 V_374 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_142 ( ! F_161 ( & V_4 -> V_452 . V_481 ) ) ;
F_142 ( V_374 > V_4 -> V_452 . V_453 ) ;
F_142 ( V_374 < V_4 -> V_452 . V_454 ) ;
if ( V_374 != V_4 -> V_452 . V_459 ) {
F_181 ( V_4 , V_374 ) ;
if ( F_56 ( V_2 ) )
F_3 ( V_482 ,
F_184 ( V_374 ) ) ;
else
F_3 ( V_482 ,
F_185 ( V_374 ) |
F_186 ( 0 ) |
V_483 ) ;
}
F_3 ( V_484 , F_180 ( V_4 , V_374 ) ) ;
F_3 ( V_485 , F_182 ( V_4 , V_374 ) ) ;
F_22 ( V_482 ) ;
V_4 -> V_452 . V_459 = V_374 ;
F_187 ( V_374 * 50 ) ;
}
static void F_188 ( struct V_3 * V_4 )
{
if ( V_4 -> V_452 . V_459 <= V_4 -> V_452 . V_454 )
return;
F_3 ( V_485 , 0xffffffff ) ;
F_3 ( V_486 ,
F_2 ( V_486 ) |
V_487 ) ;
if ( F_4 ( ( ( V_488 &
F_2 ( V_486 ) ) != 0 ) , 5 ) ) {
F_45 ( L_62 ) ;
return;
}
V_4 -> V_452 . V_459 = V_4 -> V_452 . V_454 ;
F_189 ( V_4 , V_489 ,
V_4 -> V_452 . V_454 ) ;
if ( F_4 ( ( ( F_190 ( V_4 , V_490 ) )
& V_491 ) == 0 , 5 ) )
F_45 ( L_63 ) ;
F_3 ( V_486 ,
F_2 ( V_486 ) &
~ V_487 ) ;
F_3 ( V_485 ,
F_182 ( V_4 , V_4 -> V_452 . V_459 ) ) ;
}
void F_191 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_452 . V_481 ) ;
if ( V_4 -> V_452 . V_161 ) {
if ( F_192 ( V_2 ) )
F_188 ( V_4 ) ;
else
F_183 ( V_4 -> V_2 , V_4 -> V_452 . V_454 ) ;
V_4 -> V_452 . V_475 = 0 ;
}
F_39 ( & V_4 -> V_452 . V_481 ) ;
}
void F_193 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_452 . V_481 ) ;
if ( V_4 -> V_452 . V_161 ) {
if ( F_192 ( V_2 ) )
F_194 ( V_4 -> V_2 , V_4 -> V_452 . V_453 ) ;
else
F_183 ( V_4 -> V_2 , V_4 -> V_452 . V_453 ) ;
V_4 -> V_452 . V_475 = 0 ;
}
F_39 ( & V_4 -> V_452 . V_481 ) ;
}
void F_194 ( struct V_1 * V_2 , T_7 V_374 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_142 ( ! F_161 ( & V_4 -> V_452 . V_481 ) ) ;
F_142 ( V_374 > V_4 -> V_452 . V_453 ) ;
F_142 ( V_374 < V_4 -> V_452 . V_454 ) ;
F_65 ( L_64 ,
F_195 ( V_4 , V_4 -> V_452 . V_459 ) ,
V_4 -> V_452 . V_459 ,
F_195 ( V_4 , V_374 ) , V_374 ) ;
if ( V_374 != V_4 -> V_452 . V_459 )
F_189 ( V_4 , V_489 , V_374 ) ;
F_3 ( V_485 , F_182 ( V_4 , V_374 ) ) ;
V_4 -> V_452 . V_459 = V_374 ;
F_187 ( F_195 ( V_4 , V_374 ) ) ;
}
static void F_196 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_485 , 0xffffffff ) ;
F_3 ( V_492 , F_2 ( V_492 ) &
~ V_4 -> V_493 ) ;
F_173 ( & V_4 -> V_494 ) ;
V_4 -> V_452 . V_495 = 0 ;
F_178 ( & V_4 -> V_494 ) ;
F_3 ( V_496 , V_4 -> V_493 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_497 , 0 ) ;
F_3 ( V_482 , 1 << 31 ) ;
F_196 ( V_2 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_497 , 0 ) ;
F_196 ( V_2 ) ;
}
static void F_199 ( struct V_1 * V_2 , T_1 V_313 )
{
F_200 ( L_65 ,
( V_313 & V_498 ) ? L_66 : L_67 ,
( V_313 & V_499 ) ? L_66 : L_67 ,
( V_313 & V_500 ) ? L_66 : L_67 ) ;
}
int F_201 ( const struct V_1 * V_2 )
{
if ( F_55 ( V_2 ) -> V_97 < 5 )
return 0 ;
if ( V_89 . V_501 >= 0 )
return V_89 . V_501 ;
if ( F_55 ( V_2 ) -> V_97 == 5 )
return 0 ;
if ( F_32 ( V_2 ) )
return ( V_502 | V_503 ) ;
return V_502 ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_173 ( & V_4 -> V_494 ) ;
F_142 ( V_4 -> V_452 . V_495 ) ;
F_203 ( V_4 , V_4 -> V_493 ) ;
F_3 ( V_496 , V_4 -> V_493 ) ;
F_178 ( & V_4 -> V_494 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_504 * V_505 ;
T_3 V_506 = 0 , V_507 ;
int V_508 ;
F_3 ( V_509 , 0 ) ;
F_21 ( V_4 , V_510 ) ;
F_3 ( V_497 , 0 ) ;
V_507 = F_2 ( V_511 ) ;
F_3 ( V_512 , 40 << 16 ) ;
F_3 ( V_513 , 125000 ) ;
F_3 ( V_514 , 25 ) ;
F_205 (ring, dev_priv, unused)
F_3 ( F_206 ( V_505 -> V_515 ) , 10 ) ;
F_3 ( V_516 , 0 ) ;
F_3 ( V_517 , 50000 ) ;
if ( F_201 ( V_2 ) & V_502 )
V_506 = V_498 ;
F_199 ( V_2 , V_506 ) ;
F_3 ( V_497 , V_518 |
F_207 ( 1 ) |
V_506 ) ;
F_3 ( V_482 , F_184 ( 10 ) ) ;
F_3 ( V_519 , F_184 ( 12 ) ) ;
F_3 ( V_520 , 100000000 / 128 ) ;
F_3 ( V_484 ,
V_4 -> V_452 . V_453 << 24 |
V_4 -> V_452 . V_454 << 16 ) ;
F_3 ( V_465 , 7600000 / 128 ) ;
F_3 ( V_467 , 31300000 / 128 ) ;
F_3 ( V_464 , 66000 ) ;
F_3 ( V_466 , 350000 ) ;
F_3 ( V_521 , 10 ) ;
F_3 ( V_468 ,
V_469 |
V_470 |
V_471 |
V_472 |
V_473 |
V_474 ) ;
F_183 ( V_2 , ( F_2 ( V_522 ) & 0xff00 ) >> 8 ) ;
F_202 ( V_2 ) ;
F_23 ( V_4 , V_510 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_504 * V_505 ;
T_1 V_507 ;
T_1 V_523 ;
T_1 V_524 , V_525 = 0 , V_506 = 0 ;
T_1 V_526 ;
int V_527 ;
int V_22 , V_278 ;
F_142 ( ! F_161 ( & V_4 -> V_452 . V_481 ) ) ;
F_3 ( V_509 , 0 ) ;
if ( ( V_526 = F_2 ( V_528 ) ) ) {
F_45 ( L_68 , V_526 ) ;
F_3 ( V_528 , V_526 ) ;
}
F_21 ( V_4 , V_510 ) ;
V_507 = F_2 ( V_511 ) ;
V_523 = F_2 ( V_522 ) ;
V_4 -> V_452 . V_459 = 0 ;
V_4 -> V_452 . V_463 = ( V_507 >> 8 ) & 0xff ;
V_4 -> V_452 . V_461 = ( V_507 >> 0 ) & 0xff ;
V_4 -> V_452 . V_529 = ( V_507 >> 16 ) & 0xff ;
V_4 -> V_452 . V_458 = V_4 -> V_452 . V_463 ;
V_4 -> V_452 . V_530 = V_4 -> V_452 . V_461 ;
if ( V_4 -> V_452 . V_453 == 0 )
V_4 -> V_452 . V_453 = V_4 -> V_452 . V_530 ;
if ( V_4 -> V_452 . V_454 == 0 )
V_4 -> V_452 . V_454 = V_4 -> V_452 . V_529 ;
F_3 ( V_497 , 0 ) ;
F_3 ( V_531 , 1000 << 16 ) ;
F_3 ( V_512 , 40 << 16 | 30 ) ;
F_3 ( V_532 , 30 ) ;
F_3 ( V_513 , 125000 ) ;
F_3 ( V_514 , 25 ) ;
F_205 (ring, dev_priv, i)
F_3 ( F_206 ( V_505 -> V_515 ) , 10 ) ;
F_3 ( V_516 , 0 ) ;
F_3 ( V_533 , 1000 ) ;
if ( F_32 ( V_2 ) )
F_3 ( V_517 , 125000 ) ;
else
F_3 ( V_517 , 50000 ) ;
F_3 ( V_534 , 150000 ) ;
F_3 ( V_535 , 64000 ) ;
V_527 = F_201 ( V_4 -> V_2 ) ;
if ( V_527 & V_502 )
V_506 |= V_498 ;
if ( ! F_56 ( V_2 ) ) {
if ( V_527 & V_503 )
V_506 |= V_499 ;
if ( V_527 & V_536 )
V_506 |= V_500 ;
}
F_199 ( V_2 , V_506 ) ;
F_3 ( V_497 ,
V_506 |
F_207 ( 1 ) |
V_518 ) ;
F_3 ( V_520 , 50000 ) ;
F_3 ( V_521 , 10 ) ;
V_278 = F_209 ( V_4 , V_537 , 0 ) ;
if ( V_278 )
F_65 ( L_69 ) ;
V_278 = F_210 ( V_4 , V_538 , & V_525 ) ;
if ( ! V_278 && ( V_525 & ( 1 << 31 ) ) ) {
F_65 ( L_70 ,
( V_4 -> V_452 . V_453 & 0xff ) * 50 ,
( V_525 & 0xff ) * 50 ) ;
V_4 -> V_452 . V_530 = V_525 & 0xff ;
}
V_4 -> V_452 . V_456 = V_462 ;
F_183 ( V_4 -> V_2 , V_4 -> V_452 . V_454 ) ;
F_202 ( V_2 ) ;
V_524 = 0 ;
V_278 = F_210 ( V_4 , V_539 , & V_524 ) ;
if ( F_27 ( V_2 ) && V_278 ) {
F_65 ( L_71 ) ;
} else if ( F_27 ( V_2 ) && ( F_211 ( V_524 & 0xff ) < 450 ) ) {
F_65 ( L_72 ,
F_211 ( V_524 & 0xff ) , 450 ) ;
V_524 &= 0xffff00 ;
V_524 |= F_212 ( 450 ) ;
V_278 = F_209 ( V_4 , V_540 , V_524 ) ;
if ( V_278 )
F_45 ( L_73 ) ;
}
F_23 ( V_4 , V_510 ) ;
}
void F_213 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_529 = 15 ;
unsigned int V_541 ;
unsigned int V_542 , V_543 ;
int V_544 = 180 ;
struct V_545 * V_546 ;
F_142 ( ! F_161 ( & V_4 -> V_452 . V_481 ) ) ;
V_546 = F_214 ( 0 ) ;
if ( V_546 ) {
V_542 = V_546 -> V_547 . V_530 ;
F_215 ( V_546 ) ;
} else {
V_542 = V_548 ;
}
V_542 /= 1000 ;
V_543 = F_2 ( V_549 ) & 0xf ;
V_543 = F_216 ( V_543 , 8 , 3 ) ;
for ( V_541 = V_4 -> V_452 . V_453 ; V_541 >= V_4 -> V_452 . V_454 ;
V_541 -- ) {
int V_550 = V_4 -> V_452 . V_453 - V_541 ;
unsigned int V_551 = 0 , V_552 = 0 ;
if ( F_55 ( V_2 ) -> V_97 >= 8 ) {
V_552 = F_79 ( V_543 , V_541 ) ;
} else if ( F_56 ( V_2 ) ) {
V_552 = F_216 ( V_541 , 5 , 4 ) ;
V_552 = F_79 ( V_543 , V_552 ) ;
} else {
if ( V_541 < V_529 )
V_551 = 800 ;
else
V_551 = V_542 - ( ( V_550 * V_544 ) / 2 ) ;
V_551 = F_118 ( V_551 , 100 ) ;
}
F_209 ( V_4 ,
V_537 ,
V_551 << V_553 |
V_552 << V_554 |
V_541 ) ;
}
}
int F_217 ( struct V_3 * V_4 )
{
T_1 V_374 , V_555 ;
V_374 = F_218 ( V_4 , V_556 ) ;
V_555 = ( V_374 & V_557 ) >> V_558 ;
V_555 = F_115 ( T_1 , V_555 , 0xea ) ;
return V_555 ;
}
static int F_219 ( struct V_3 * V_4 )
{
T_1 V_374 , V_559 ;
V_374 = F_218 ( V_4 , V_560 ) ;
V_559 = ( V_374 & V_561 ) >> V_562 ;
V_374 = F_218 ( V_4 , V_563 ) ;
V_559 |= ( V_374 & V_564 ) << 5 ;
return V_559 ;
}
int F_220 ( struct V_3 * V_4 )
{
return F_190 ( V_4 , V_565 ) & 0xff ;
}
static void F_221 ( struct V_3 * V_4 )
{
unsigned long V_566 = F_2 ( V_567 ) & ~ 4095 ;
F_142 ( V_566 != V_4 -> V_568 . V_569 +
V_4 -> V_570 -> V_571 -> V_572 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_573 ;
unsigned long V_574 ;
T_1 V_575 ;
int V_576 = 24 * 1024 ;
F_142 ( ! F_161 ( & V_2 -> V_73 ) ) ;
V_575 = F_2 ( V_567 ) ;
if ( V_575 ) {
int V_577 ;
V_577 = ( V_575 & ( ~ 4095 ) ) - V_4 -> V_568 . V_569 ;
V_573 = F_223 ( V_4 -> V_2 ,
V_577 ,
V_578 ,
V_576 ) ;
goto V_579;
}
V_573 = F_224 ( V_2 , V_576 ) ;
if ( ! V_573 ) {
F_163 ( L_74 ) ;
return;
}
V_574 = V_4 -> V_568 . V_569 + V_573 -> V_571 -> V_572 ;
F_3 ( V_567 , V_574 ) ;
V_579:
V_4 -> V_570 = V_573 ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_142 ( ! V_4 -> V_570 ) )
return;
F_167 ( & V_4 -> V_570 -> V_77 ) ;
V_4 -> V_570 = NULL ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_504 * V_505 ;
T_1 V_526 , V_374 , V_527 = 0 ;
int V_22 ;
F_142 ( ! F_161 ( & V_4 -> V_452 . V_481 ) ) ;
F_221 ( V_4 ) ;
if ( ( V_526 = F_2 ( V_528 ) ) ) {
F_65 ( L_68 ,
V_526 ) ;
F_3 ( V_528 , V_526 ) ;
}
F_21 ( V_4 , V_510 ) ;
F_3 ( V_465 , 59400 ) ;
F_3 ( V_467 , 245000 ) ;
F_3 ( V_464 , 66000 ) ;
F_3 ( V_466 , 350000 ) ;
F_3 ( V_521 , 10 ) ;
F_3 ( V_468 ,
V_469 |
V_470 |
V_471 |
V_472 |
V_473 |
V_580 ) ;
F_3 ( V_512 , 0x00280000 ) ;
F_3 ( V_513 , 125000 ) ;
F_3 ( V_514 , 25 ) ;
F_205 (ring, dev_priv, i)
F_3 ( F_206 ( V_505 -> V_515 ) , 10 ) ;
F_3 ( V_517 , 0x557 ) ;
F_3 ( V_581 ,
F_96 ( V_582 |
V_583 |
V_584 ) ) ;
if ( F_201 ( V_2 ) & V_502 )
V_527 = V_585 | V_586 ;
F_199 ( V_2 , V_527 ) ;
F_3 ( V_497 , V_527 ) ;
V_374 = F_190 ( V_4 , V_490 ) ;
F_65 ( L_75 , V_374 & 0x10 ? L_76 : L_77 ) ;
F_65 ( L_78 , V_374 ) ;
V_4 -> V_452 . V_459 = ( V_374 >> 8 ) & 0xff ;
F_65 ( L_79 ,
F_195 ( V_4 , V_4 -> V_452 . V_459 ) ,
V_4 -> V_452 . V_459 ) ;
V_4 -> V_452 . V_530 = F_217 ( V_4 ) ;
V_4 -> V_452 . V_461 = V_4 -> V_452 . V_530 ;
F_65 ( L_80 ,
F_195 ( V_4 , V_4 -> V_452 . V_530 ) ,
V_4 -> V_452 . V_530 ) ;
V_4 -> V_452 . V_458 = F_219 ( V_4 ) ;
F_65 ( L_81 ,
F_195 ( V_4 , V_4 -> V_452 . V_458 ) ,
V_4 -> V_452 . V_458 ) ;
V_4 -> V_452 . V_529 = F_220 ( V_4 ) ;
F_65 ( L_82 ,
F_195 ( V_4 , V_4 -> V_452 . V_529 ) ,
V_4 -> V_452 . V_529 ) ;
if ( V_4 -> V_452 . V_453 == 0 )
V_4 -> V_452 . V_453 = V_4 -> V_452 . V_530 ;
if ( V_4 -> V_452 . V_454 == 0 )
V_4 -> V_452 . V_454 = V_4 -> V_452 . V_529 ;
F_65 ( L_83 ,
F_195 ( V_4 , V_4 -> V_452 . V_458 ) ,
V_4 -> V_452 . V_458 ) ;
F_194 ( V_4 -> V_2 , V_4 -> V_452 . V_458 ) ;
F_202 ( V_2 ) ;
F_23 ( V_4 , V_510 ) ;
}
void F_227 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_134 . V_587 ) {
F_166 ( V_4 -> V_134 . V_587 ) ;
F_167 ( & V_4 -> V_134 . V_587 -> V_77 ) ;
V_4 -> V_134 . V_587 = NULL ;
}
if ( V_4 -> V_134 . V_588 ) {
F_166 ( V_4 -> V_134 . V_588 ) ;
F_167 ( & V_4 -> V_134 . V_588 -> V_77 ) ;
V_4 -> V_134 . V_588 = NULL ;
}
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_2 ( V_589 ) ) {
F_3 ( V_590 , F_2 ( V_590 ) | V_591 ) ;
F_4 ( ( ( F_2 ( V_590 ) & V_592 ) == V_593 ) ,
50 ) ;
F_3 ( V_589 , 0 ) ;
F_22 ( V_589 ) ;
F_3 ( V_590 , F_2 ( V_590 ) & ~ V_591 ) ;
F_22 ( V_590 ) ;
}
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_134 . V_587 == NULL )
V_4 -> V_134 . V_587 = F_160 ( V_2 ) ;
if ( ! V_4 -> V_134 . V_587 )
return - V_594 ;
if ( V_4 -> V_134 . V_588 == NULL )
V_4 -> V_134 . V_588 = F_160 ( V_2 ) ;
if ( ! V_4 -> V_134 . V_588 ) {
F_227 ( V_2 ) ;
return - V_594 ;
}
return 0 ;
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_504 * V_505 = & V_4 -> V_505 [ V_595 ] ;
bool V_596 ;
int V_278 ;
if ( ! F_201 ( V_2 ) )
return;
F_142 ( ! F_161 ( & V_2 -> V_73 ) ) ;
V_278 = F_229 ( V_2 ) ;
if ( V_278 )
return;
V_596 = V_4 -> V_568 . V_597 ;
V_4 -> V_568 . V_597 = false ;
V_278 = F_231 ( V_505 , 6 ) ;
if ( V_278 ) {
F_227 ( V_2 ) ;
V_4 -> V_568 . V_597 = V_596 ;
return;
}
F_232 ( V_505 , V_598 | V_599 ) ;
F_232 ( V_505 , V_600 ) ;
F_232 ( V_505 , F_26 ( V_4 -> V_134 . V_587 ) |
V_601 |
V_602 |
V_603 |
V_604 ) ;
F_232 ( V_505 , V_598 ) ;
F_232 ( V_505 , V_605 ) ;
F_232 ( V_505 , V_606 ) ;
F_233 ( V_505 ) ;
V_278 = F_234 ( V_505 ) ;
V_4 -> V_568 . V_597 = V_596 ;
if ( V_278 ) {
F_45 ( L_84 ) ;
F_227 ( V_2 ) ;
return;
}
F_3 ( V_589 , F_26 ( V_4 -> V_134 . V_588 ) | V_607 ) ;
F_3 ( V_590 , F_2 ( V_590 ) & ~ V_591 ) ;
F_199 ( V_2 , V_502 ) ;
}
static unsigned long F_235 ( T_1 V_608 )
{
unsigned long V_609 ;
int div = ( V_608 & 0x3f0000 ) >> 16 ;
int V_610 = ( V_608 & 0x3000 ) >> 12 ;
int V_611 = ( V_608 & 0x7 ) ;
if ( ! V_611 )
return 0 ;
V_609 = ( ( div * 133333 ) / ( ( 1 << V_610 ) * V_611 ) ) ;
return V_609 ;
}
static unsigned long F_236 ( struct V_3 * V_4 )
{
T_8 V_612 , V_550 , V_278 ;
T_1 V_613 , V_614 , V_615 , V_616 = 0 , V_617 = 0 ;
unsigned long V_618 = F_176 ( V_442 ) , V_619 ;
int V_22 ;
F_169 ( & V_402 ) ;
V_619 = V_618 - V_4 -> V_134 . V_441 ;
if ( V_619 <= 10 )
return V_4 -> V_134 . V_620 ;
V_613 = F_2 ( V_621 ) ;
V_614 = F_2 ( V_622 ) ;
V_615 = F_2 ( V_623 ) ;
V_612 = V_613 + V_614 + V_615 ;
if ( V_612 < V_4 -> V_134 . V_440 ) {
V_550 = ~ 0UL - V_4 -> V_134 . V_440 ;
V_550 += V_612 ;
} else {
V_550 = V_612 - V_4 -> V_134 . V_440 ;
}
for ( V_22 = 0 ; V_22 < F_67 ( V_624 ) ; V_22 ++ ) {
if ( V_624 [ V_22 ] . V_22 == V_4 -> V_134 . V_136 &&
V_624 [ V_22 ] . V_625 == V_4 -> V_134 . V_135 ) {
V_616 = V_624 [ V_22 ] . V_616 ;
V_617 = V_624 [ V_22 ] . V_617 ;
break;
}
}
V_550 = F_99 ( V_550 , V_619 ) ;
V_278 = ( ( V_616 * V_550 ) + V_617 ) ;
V_278 = F_99 ( V_278 , 10 ) ;
V_4 -> V_134 . V_440 = V_612 ;
V_4 -> V_134 . V_441 = V_618 ;
V_4 -> V_134 . V_620 = V_278 ;
return V_278 ;
}
unsigned long F_237 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_374 ;
if ( F_55 ( V_2 ) -> V_97 != 5 )
return 0 ;
F_173 ( & V_402 ) ;
V_374 = F_236 ( V_4 ) ;
F_178 ( & V_402 ) ;
return V_374 ;
}
unsigned long F_238 ( struct V_3 * V_4 )
{
unsigned long V_616 , V_626 , V_627 ;
T_1 V_628 ;
V_628 = F_2 ( V_629 ) ;
V_616 = ( ( V_628 & V_630 ) >> V_631 ) ;
V_626 = F_239 ( V_632 ) ;
V_627 = V_628 & V_633 ;
return ( ( V_616 * V_626 ) / 127 ) - V_627 ;
}
static T_2 F_240 ( struct V_3 * V_4 , T_7 V_634 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
static const struct V_635 {
T_2 V_636 ;
T_2 V_637 ;
} V_635 [] = {
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
if ( F_55 ( V_2 ) -> V_638 )
return V_635 [ V_634 ] . V_637 ;
else
return V_635 [ V_634 ] . V_636 ;
}
static void F_241 ( struct V_3 * V_4 )
{
struct V_639 V_618 , V_619 ;
T_8 V_550 ;
unsigned long V_640 ;
T_1 V_641 ;
F_169 ( & V_402 ) ;
F_177 ( & V_618 ) ;
V_619 = F_242 ( V_618 , V_4 -> V_134 . V_444 ) ;
V_640 = V_619 . V_642 * 1000 + V_619 . V_643 / 1000000 ;
if ( ! V_640 )
return;
V_641 = F_2 ( V_644 ) ;
if ( V_641 < V_4 -> V_134 . V_443 ) {
V_550 = ~ 0UL - V_4 -> V_134 . V_443 ;
V_550 += V_641 ;
} else {
V_550 = V_641 - V_4 -> V_134 . V_443 ;
}
V_4 -> V_134 . V_443 = V_641 ;
V_4 -> V_134 . V_444 = V_618 ;
V_550 = V_550 * 1181 ;
V_550 = F_99 ( V_550 , V_640 * 10 ) ;
V_4 -> V_134 . V_645 = V_550 ;
}
void F_243 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_55 ( V_2 ) -> V_97 != 5 )
return;
F_173 ( & V_402 ) ;
F_241 ( V_4 ) ;
F_178 ( & V_402 ) ;
}
static unsigned long F_244 ( struct V_3 * V_4 )
{
unsigned long V_625 , V_646 , V_647 , V_648 , V_649 ;
T_1 V_634 , V_650 ;
F_169 ( & V_402 ) ;
V_634 = F_2 ( V_429 + ( V_4 -> V_452 . V_459 * 4 ) ) ;
V_634 = ( V_634 >> 24 ) & 0x7f ;
V_650 = F_240 ( V_4 , V_634 ) ;
V_647 = V_650 ;
V_625 = F_238 ( V_4 ) ;
if ( V_625 > 80 )
V_646 = ( ( V_625 * 2349 ) + 135940 ) ;
else if ( V_625 >= 50 )
V_646 = ( ( V_625 * 964 ) + 29317 ) ;
else
V_646 = ( ( V_625 * 301 ) + 1004 ) ;
V_646 = V_646 * ( ( 150142 * V_647 ) / 10000 - 78642 ) ;
V_646 /= 100000 ;
V_648 = ( V_646 * V_4 -> V_134 . V_646 ) ;
V_649 = ( V_648 * V_647 ) / 10000 ;
V_649 /= 100 ;
F_241 ( V_4 ) ;
return V_4 -> V_134 . V_645 + V_649 ;
}
unsigned long F_245 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_374 ;
if ( F_55 ( V_2 ) -> V_97 != 5 )
return 0 ;
F_173 ( & V_402 ) ;
V_374 = F_244 ( V_4 ) ;
F_178 ( & V_402 ) ;
return V_374 ;
}
unsigned long F_246 ( void )
{
struct V_3 * V_4 ;
unsigned long V_651 , V_652 , V_278 = 0 ;
F_173 ( & V_402 ) ;
if ( ! V_653 )
goto V_654;
V_4 = V_653 ;
V_651 = F_236 ( V_4 ) ;
V_652 = F_244 ( V_4 ) ;
V_278 = V_651 + V_652 ;
V_654:
F_178 ( & V_402 ) ;
return V_278 ;
}
bool F_247 ( void )
{
struct V_3 * V_4 ;
bool V_278 = true ;
F_173 ( & V_402 ) ;
if ( ! V_653 ) {
V_278 = false ;
goto V_654;
}
V_4 = V_653 ;
if ( V_4 -> V_134 . V_432 > V_4 -> V_134 . V_411 )
V_4 -> V_134 . V_432 -- ;
V_654:
F_178 ( & V_402 ) ;
return V_278 ;
}
bool F_248 ( void )
{
struct V_3 * V_4 ;
bool V_278 = true ;
F_173 ( & V_402 ) ;
if ( ! V_653 ) {
V_278 = false ;
goto V_654;
}
V_4 = V_653 ;
if ( V_4 -> V_134 . V_432 < V_4 -> V_134 . V_433 )
V_4 -> V_134 . V_432 ++ ;
V_654:
F_178 ( & V_402 ) ;
return V_278 ;
}
bool F_249 ( void )
{
struct V_3 * V_4 ;
struct V_504 * V_505 ;
bool V_278 = false ;
int V_22 ;
F_173 ( & V_402 ) ;
if ( ! V_653 )
goto V_654;
V_4 = V_653 ;
F_205 (ring, dev_priv, i)
V_278 |= ! F_250 ( & V_505 -> V_655 ) ;
V_654:
F_178 ( & V_402 ) ;
return V_278 ;
}
bool F_251 ( void )
{
struct V_3 * V_4 ;
bool V_278 = true ;
F_173 ( & V_402 ) ;
if ( ! V_653 ) {
V_278 = false ;
goto V_654;
}
V_4 = V_653 ;
V_4 -> V_134 . V_432 = V_4 -> V_134 . V_413 ;
if ( ! F_168 ( V_4 -> V_2 , V_4 -> V_134 . V_413 ) )
V_278 = false ;
V_654:
F_178 ( & V_402 ) ;
return V_278 ;
}
static void
F_252 ( void )
{
void (* F_253)( void );
F_253 = F_254 ( V_656 ) ;
if ( F_253 ) {
F_253 () ;
F_255 ( V_656 ) ;
}
}
void F_256 ( struct V_3 * V_4 )
{
F_173 ( & V_402 ) ;
V_653 = V_4 ;
F_178 ( & V_402 ) ;
F_252 () ;
}
void F_257 ( void )
{
F_173 ( & V_402 ) ;
V_653 = NULL ;
F_178 ( & V_402 ) ;
}
static void F_258 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_657 ;
T_7 V_658 [ 16 ] ;
int V_22 ;
F_3 ( V_659 , 0 ) ;
F_22 ( V_659 ) ;
F_3 ( V_660 , 0x15040d00 ) ;
F_3 ( V_661 , 0x007f0000 ) ;
F_3 ( V_662 , 0x1e220004 ) ;
F_3 ( V_663 , 0x04000004 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_3 ( V_664 + ( V_22 * 4 ) , 0 ) ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
F_3 ( V_665 + ( V_22 * 4 ) , 0 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ ) {
T_1 V_666 = F_2 ( V_429 + ( V_22 * 4 ) ) ;
unsigned long V_609 = F_235 ( V_666 ) ;
unsigned long V_667 = ( V_666 & V_430 ) >>
V_431 ;
unsigned long V_374 ;
V_374 = V_667 * V_667 ;
V_374 *= ( V_609 / 1000 ) ;
V_374 *= 255 ;
V_374 /= ( 127 * 127 * 900 ) ;
if ( V_374 > 0xff )
F_45 ( L_85 , V_374 ) ;
V_658 [ V_22 ] = V_374 ;
}
V_658 [ 14 ] = 0 ;
V_658 [ 15 ] = 0 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
T_1 V_374 = ( V_658 [ V_22 * 4 ] << 24 ) | ( V_658 [ ( V_22 * 4 ) + 1 ] << 16 ) |
( V_658 [ ( V_22 * 4 ) + 2 ] << 8 ) | ( V_658 [ ( V_22 * 4 ) + 3 ] ) ;
F_3 ( V_668 + ( V_22 * 4 ) , V_374 ) ;
}
F_3 ( V_669 , 0 ) ;
F_3 ( V_670 , 0 ) ;
F_3 ( V_671 , 0x00007f00 ) ;
F_3 ( V_672 , 0x0000000e ) ;
F_3 ( V_673 , 0x000e0000 ) ;
F_3 ( V_674 , 0x68000300 ) ;
F_3 ( V_675 , 0x42000000 ) ;
F_3 ( V_676 , 0x00140031 ) ;
F_3 ( V_677 , 0 ) ;
F_3 ( V_678 , 0 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_3 ( V_679 + ( V_22 * 4 ) , 0 ) ;
F_3 ( V_659 , 0x80000019 ) ;
V_657 = F_2 ( V_680 ) ;
V_4 -> V_134 . V_646 = ( V_657 & V_681 ) ;
}
void F_259 ( struct V_1 * V_2 )
{
if ( F_192 ( V_2 ) )
F_222 ( V_2 ) ;
}
void F_260 ( struct V_1 * V_2 )
{
if ( F_192 ( V_2 ) )
F_225 ( V_2 ) ;
}
void F_261 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_142 ( V_2 -> V_682 ) ;
if ( F_262 ( V_2 ) ) {
F_179 ( V_2 ) ;
F_228 ( V_2 ) ;
} else if ( F_55 ( V_2 ) -> V_97 >= 6 ) {
F_263 ( & V_4 -> V_452 . V_683 ) ;
F_264 ( & V_4 -> V_452 . V_72 ) ;
F_38 ( & V_4 -> V_452 . V_481 ) ;
if ( F_192 ( V_2 ) )
F_198 ( V_2 ) ;
else
F_197 ( V_2 ) ;
V_4 -> V_452 . V_161 = false ;
F_39 ( & V_4 -> V_452 . V_481 ) ;
}
}
static void F_265 ( struct V_69 * V_72 )
{
struct V_3 * V_4 =
F_36 ( V_72 , struct V_3 ,
V_452 . V_683 . V_72 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_452 . V_481 ) ;
if ( F_192 ( V_2 ) ) {
F_226 ( V_2 ) ;
} else if ( F_123 ( V_2 ) ) {
F_204 ( V_2 ) ;
F_213 ( V_2 ) ;
} else {
F_208 ( V_2 ) ;
F_213 ( V_2 ) ;
}
V_4 -> V_452 . V_161 = true ;
F_39 ( & V_4 -> V_452 . V_481 ) ;
}
void F_266 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_262 ( V_2 ) ) {
F_172 ( V_2 ) ;
F_230 ( V_2 ) ;
F_258 ( V_2 ) ;
} else if ( F_27 ( V_2 ) || F_267 ( V_2 ) ) {
F_47 ( & V_4 -> V_452 . V_683 ,
F_268 ( V_684 ) ) ;
}
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_685 , V_686 ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_65 ;
F_145 (pipe) {
F_3 ( F_271 ( V_65 ) ,
F_2 ( F_271 ( V_65 ) ) |
V_687 ) ;
F_272 ( V_4 , V_65 ) ;
}
}
static void F_273 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_371 , F_2 ( V_371 ) & ~ V_370 ) ;
F_3 ( V_372 , F_2 ( V_372 ) & ~ V_370 ) ;
F_3 ( V_373 , F_2 ( V_373 ) & ~ V_370 ) ;
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_688 = V_689 ;
V_688 |= V_690 |
V_691 |
V_692 ;
F_3 ( V_693 ,
V_694 |
V_695 ) ;
F_3 ( V_696 ,
V_697 ) ;
F_3 ( V_698 ,
( F_2 ( V_698 ) |
V_699 | V_700 ) ) ;
V_688 |= V_701 ;
F_3 ( V_383 ,
( F_2 ( V_383 ) |
V_384 ) ) ;
F_273 ( V_2 ) ;
if ( F_262 ( V_2 ) ) {
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 ) ;
F_3 ( V_698 ,
F_2 ( V_698 ) |
V_699 ) ;
}
F_3 ( V_702 , V_688 ) ;
F_3 ( V_698 ,
F_2 ( V_698 ) |
V_703 ) ;
F_3 ( V_704 ,
V_705 << 16 |
V_705 ) ;
F_3 ( V_706 ,
F_96 ( V_707 ) ) ;
F_270 ( V_2 ) ;
F_269 ( V_2 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_65 ;
T_3 V_374 ;
F_3 ( V_685 , V_686 |
V_708 |
V_709 ) ;
F_3 ( V_710 , F_2 ( V_710 ) |
V_711 ) ;
F_145 (pipe) {
V_374 = F_2 ( F_276 ( V_65 ) ) ;
V_374 |= V_712 ;
V_374 &= ~ V_713 ;
if ( V_4 -> V_714 . V_715 )
V_374 |= V_713 ;
V_374 &= ~ V_716 ;
V_374 &= ~ V_717 ;
V_374 &= ~ V_718 ;
F_3 ( F_276 ( V_65 ) , V_374 ) ;
}
F_145 (pipe) {
F_3 ( F_277 ( V_65 ) ,
V_719 ) ;
}
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_114 ;
V_114 = F_2 ( V_317 ) ;
if ( ( V_114 & V_720 ) != V_721 ) {
F_200 ( L_86 , V_114 ) ;
F_200 ( L_87 ) ;
F_200 ( L_88 ) ;
}
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_688 = V_689 ;
F_3 ( V_702 , V_688 ) ;
F_3 ( V_698 ,
F_2 ( V_698 ) |
V_703 ) ;
F_3 ( V_722 ,
F_96 ( V_723 ) ) ;
if ( F_280 ( V_2 ) )
F_3 ( V_724 ,
F_96 ( V_725 ) ) ;
F_3 ( V_724 ,
V_726 | V_727 ) ;
F_273 ( V_2 ) ;
F_3 ( V_706 ,
F_94 ( V_728 ) ) ;
F_3 ( V_729 ,
F_2 ( V_729 ) |
V_730 |
V_731 ) ;
F_3 ( V_732 ,
V_733 |
V_734 ) ;
F_3 ( V_735 ,
F_96 ( V_736 ) ) ;
F_3 ( V_735 ,
F_96 ( V_737 ) ) ;
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 | V_738 ) ;
F_3 ( V_698 ,
F_2 ( V_698 ) |
V_699 | V_700 ) ;
F_3 ( V_702 ,
F_2 ( V_702 ) |
V_701 |
V_692 ) ;
F_270 ( V_2 ) ;
F_275 ( V_2 ) ;
F_278 ( V_2 ) ;
}
static void F_281 ( struct V_3 * V_4 )
{
T_3 V_163 = F_2 ( V_739 ) ;
V_163 &= ~ V_740 ;
V_163 |= V_741 ;
V_163 |= V_742 ;
V_163 |= V_743 ;
F_3 ( V_739 , V_163 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_744 == V_745 )
F_3 ( V_685 ,
F_2 ( V_685 ) |
V_746 ) ;
F_3 ( V_747 ,
F_2 ( V_747 ) |
V_719 ) ;
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_744 == V_745 ) {
T_3 V_374 = F_2 ( V_685 ) ;
V_374 &= ~ V_746 ;
F_3 ( V_685 , V_374 ) ;
}
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_65 V_65 ;
F_3 ( V_371 , 0 ) ;
F_3 ( V_372 , 0 ) ;
F_3 ( V_373 , 0 ) ;
F_3 ( V_748 ,
F_96 ( V_749 ) ) ;
F_3 ( V_748 ,
F_96 ( V_750 ) ) ;
F_3 ( V_751 ,
F_96 ( V_752 ) ) ;
F_3 ( V_751 ,
F_96 ( V_753 ) ) ;
F_3 ( V_754 , F_96 ( V_755 ) ) ;
F_3 ( V_735 ,
F_285 ( 2 ) ) ;
F_3 ( V_756 ,
F_96 ( V_757 ) ) ;
F_3 ( V_758 ,
F_96 ( V_759 ) ) ;
F_3 ( V_760 , F_2 ( V_760 ) | V_761 ) ;
F_3 ( V_762 ,
F_2 ( V_762 ) | V_763 ) ;
F_145 (pipe) {
F_3 ( F_33 ( V_65 ) ,
F_2 ( F_33 ( V_65 ) ) |
V_764 ) ;
}
F_3 ( V_765 ,
F_2 ( V_765 ) |
F_96 ( V_766 ) ) ;
F_3 ( V_739 ,
F_2 ( V_739 ) &
~ ( V_767 | V_768 ) ) ;
F_3 ( V_769 ,
V_726 | V_727 ) ;
F_3 ( V_770 ,
F_96 ( V_771 ) ) ;
F_3 ( V_772 , F_2 ( V_772 ) |
V_773 ) ;
F_3 ( V_774 ,
F_96 ( V_775 ) ) ;
}
static void F_286 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_273 ( V_2 ) ;
F_3 ( V_776 , V_777 ) ;
F_3 ( V_778 ,
F_96 ( V_779 ) ) ;
F_3 ( V_780 ,
F_2 ( V_780 ) |
V_781 ) ;
F_3 ( V_739 ,
F_2 ( V_739 ) & ~ V_768 ) ;
F_3 ( V_782 ,
F_94 ( V_783 ) ) ;
F_3 ( V_774 ,
F_96 ( V_784 ) ) ;
F_3 ( V_769 ,
V_726 | V_727 ) ;
F_3 ( V_760 , F_2 ( V_760 ) | V_761 ) ;
F_3 ( V_762 ,
F_2 ( V_762 ) | V_785 ) ;
F_282 ( V_2 ) ;
}
static void F_287 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_786 ;
F_273 ( V_2 ) ;
F_3 ( V_702 , V_689 ) ;
F_3 ( V_735 ,
F_96 ( V_787 ) ) ;
F_3 ( V_788 ,
V_789 |
V_790 ) ;
if ( F_288 ( V_2 ) )
F_3 ( V_758 ,
F_96 ( V_791 ) ) ;
F_3 ( V_792 ,
V_793 ) ;
F_3 ( V_794 ,
V_795 ) ;
F_3 ( V_796 ,
V_797 ) ;
if ( F_288 ( V_2 ) )
F_3 ( V_798 ,
F_96 ( V_799 ) ) ;
else {
F_3 ( V_798 ,
F_96 ( V_799 ) ) ;
F_3 ( V_800 ,
F_96 ( V_799 ) ) ;
}
F_3 ( V_801 , F_2 ( V_801 ) &
~ V_802 ) ;
F_3 ( V_732 ,
V_803 ) ;
F_3 ( V_780 ,
F_2 ( V_780 ) |
V_781 ) ;
F_270 ( V_2 ) ;
F_281 ( V_4 ) ;
if ( 0 ) {
F_3 ( V_782 ,
F_94 ( V_783 ) ) ;
}
F_3 ( V_774 ,
F_96 ( V_784 ) ) ;
F_3 ( V_769 ,
V_726 | V_727 ) ;
V_786 = F_2 ( V_804 ) ;
V_786 &= ~ V_805 ;
V_786 |= V_806 ;
F_3 ( V_804 , V_786 ) ;
if ( ! F_289 ( V_2 ) )
F_275 ( V_2 ) ;
F_278 ( V_2 ) ;
}
static void F_290 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_374 ;
F_38 ( & V_4 -> V_452 . V_481 ) ;
V_374 = F_190 ( V_4 , V_490 ) ;
F_39 ( & V_4 -> V_452 . V_481 ) ;
switch ( ( V_374 >> 6 ) & 3 ) {
case 0 :
case 1 :
V_4 -> V_124 = 800 ;
break;
case 2 :
V_4 -> V_124 = 1066 ;
break;
case 3 :
V_4 -> V_124 = 1333 ;
break;
}
F_65 ( L_89 , V_4 -> V_124 ) ;
F_3 ( V_807 , V_808 ) ;
F_3 ( V_735 ,
F_96 ( V_787 ) ) ;
F_3 ( V_788 ,
V_789 |
V_790 ) ;
F_3 ( V_758 ,
F_96 ( V_809 |
V_791 ) ) ;
F_3 ( V_801 , F_2 ( V_801 ) &
~ V_802 ) ;
F_3 ( V_798 ,
F_96 ( V_799 ) ) ;
F_3 ( V_780 ,
F_2 ( V_780 ) |
V_781 ) ;
F_281 ( V_4 ) ;
F_3 ( V_732 ,
V_803 ) ;
F_3 ( V_810 , V_811 ) ;
F_3 ( V_812 , V_813 ) ;
F_3 ( V_774 ,
F_96 ( V_784 ) ) ;
F_3 ( V_814 , V_815 ) ;
F_3 ( V_816 , V_817 ) ;
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_688 ;
F_3 ( V_818 , 0 ) ;
F_3 ( V_819 , V_820 |
V_821 |
V_822 ) ;
F_3 ( V_823 , 0 ) ;
V_688 = V_808 |
V_824 |
V_825 ;
if ( F_292 ( V_2 ) )
V_688 |= V_826 ;
F_3 ( V_807 , V_688 ) ;
F_3 ( V_706 ,
F_96 ( V_707 ) ) ;
F_270 ( V_2 ) ;
}
static void F_293 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_818 , V_827 ) ;
F_3 ( V_819 , 0 ) ;
F_3 ( V_807 , 0 ) ;
F_3 ( V_823 , 0 ) ;
F_170 ( V_828 , 0 ) ;
F_3 ( V_829 ,
F_96 ( V_813 ) ) ;
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_818 , V_830 |
V_827 |
V_831 |
V_832 |
V_833 ) ;
F_3 ( V_819 , 0 ) ;
F_3 ( V_829 ,
F_96 ( V_813 ) ) ;
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_834 = F_2 ( V_835 ) ;
V_834 |= V_836 | V_837 |
V_838 ;
F_3 ( V_835 , V_834 ) ;
if ( F_296 ( V_2 ) )
F_3 ( V_839 , F_96 ( V_840 ) ) ;
F_3 ( V_839 , F_94 ( V_841 ) ) ;
}
static void F_297 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_818 , V_842 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_807 , V_824 ) ;
}
void F_299 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_67 . V_843 ( V_2 ) ;
}
void F_300 ( struct V_1 * V_2 )
{
if ( F_301 ( V_2 ) )
F_283 ( V_2 ) ;
}
static bool F_302 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
return F_2 ( V_846 ) ==
( V_847 | V_848 ) ;
}
bool F_303 ( struct V_3 * V_4 ,
enum V_849 V_850 )
{
struct V_851 * V_852 ;
V_852 = & V_4 -> V_852 ;
return V_852 -> V_853 [ V_850 ] ;
}
bool F_304 ( struct V_3 * V_4 ,
enum V_849 V_850 )
{
struct V_851 * V_852 ;
struct V_844 * V_845 ;
bool V_854 ;
int V_22 ;
if ( V_4 -> V_855 . V_856 )
return false ;
V_852 = & V_4 -> V_852 ;
V_854 = true ;
F_38 ( & V_852 -> V_857 ) ;
F_305 (i, power_well, BIT(domain), power_domains) {
if ( V_845 -> V_858 )
continue;
if ( ! V_845 -> V_859 -> V_854 ( V_4 , V_845 ) ) {
V_854 = false ;
break;
}
}
F_39 ( & V_852 -> V_857 ) ;
return V_854 ;
}
static void F_306 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_860 ;
F_307 ( V_2 -> V_861 , V_862 ) ;
F_308 ( F_309 ( V_863 ) , V_864 ) ;
F_310 ( V_2 -> V_861 , V_862 ) ;
if ( F_123 ( V_2 ) ) {
F_311 ( & V_4 -> V_494 , V_860 ) ;
F_3 ( F_312 ( V_236 ) ,
V_4 -> V_865 [ V_236 ] ) ;
F_3 ( F_313 ( V_236 ) ,
~ V_4 -> V_865 [ V_236 ] |
V_866 ) ;
F_3 ( F_312 ( V_377 ) ,
V_4 -> V_865 [ V_377 ] ) ;
F_3 ( F_313 ( V_377 ) ,
~ V_4 -> V_865 [ V_377 ] |
V_866 ) ;
F_22 ( F_313 ( V_377 ) ) ;
F_314 ( & V_4 -> V_494 , V_860 ) ;
}
}
static void F_315 ( struct V_1 * V_2 , enum V_65 V_65 )
{
F_169 ( & V_2 -> V_867 ) ;
V_2 -> V_868 [ V_65 ] . V_869 = 0 ;
}
static void F_316 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_65 V_65 ;
unsigned long V_860 ;
F_311 ( & V_2 -> V_867 , V_860 ) ;
F_145 (pipe)
if ( V_65 != V_233 )
F_315 ( V_2 , V_65 ) ;
F_314 ( & V_2 -> V_867 , V_860 ) ;
}
static void F_317 ( struct V_3 * V_4 ,
struct V_844 * V_845 , bool V_305 )
{
bool V_854 , V_870 ;
T_3 V_114 ;
V_114 = F_2 ( V_846 ) ;
V_854 = V_114 & V_848 ;
V_870 = V_114 & V_847 ;
if ( V_305 ) {
if ( ! V_870 )
F_3 ( V_846 ,
V_847 ) ;
if ( ! V_854 ) {
F_5 ( L_90 ) ;
if ( F_4 ( ( F_2 ( V_846 ) &
V_848 ) , 20 ) )
F_45 ( L_91 ) ;
}
F_306 ( V_4 ) ;
} else {
if ( V_870 ) {
F_3 ( V_846 , 0 ) ;
F_22 ( V_846 ) ;
F_5 ( L_92 ) ;
F_316 ( V_4 ) ;
}
}
}
static void F_318 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
F_317 ( V_4 , V_845 , V_845 -> V_641 > 0 ) ;
if ( F_2 ( V_871 ) & V_847 )
F_3 ( V_871 , 0 ) ;
}
static void F_319 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
F_317 ( V_4 , V_845 , true ) ;
}
static void F_320 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
F_317 ( V_4 , V_845 , false ) ;
}
static void F_321 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
}
static bool F_322 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
return true ;
}
static void F_323 ( struct V_3 * V_4 ,
struct V_844 * V_845 , bool V_305 )
{
enum V_872 V_873 = V_845 -> V_874 ;
T_1 V_476 ;
T_1 V_875 ;
T_1 V_876 ;
V_476 = F_324 ( V_873 ) ;
V_875 = V_305 ? F_325 ( V_873 ) :
F_326 ( V_873 ) ;
F_38 ( & V_4 -> V_452 . V_481 ) ;
#define F_327 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_327 )
goto V_579;
V_876 = F_190 ( V_4 , V_877 ) ;
V_876 &= ~ V_476 ;
V_876 |= V_875 ;
F_189 ( V_4 , V_877 , V_876 ) ;
if ( F_4 ( F_327 , 100 ) )
F_45 ( L_93 ,
V_875 ,
F_190 ( V_4 , V_877 ) ) ;
#undef F_327
V_579:
F_39 ( & V_4 -> V_452 . V_481 ) ;
}
static void F_328 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
F_323 ( V_4 , V_845 , V_845 -> V_641 > 0 ) ;
}
static void F_329 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
F_323 ( V_4 , V_845 , true ) ;
}
static void F_330 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
F_323 ( V_4 , V_845 , false ) ;
}
static bool F_331 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
int V_873 = V_845 -> V_874 ;
bool V_161 = false ;
T_1 V_476 ;
T_1 V_875 ;
T_1 V_876 ;
V_476 = F_324 ( V_873 ) ;
V_876 = F_325 ( V_873 ) ;
F_38 ( & V_4 -> V_452 . V_481 ) ;
V_875 = F_190 ( V_4 , V_878 ) & V_476 ;
F_142 ( V_875 != F_325 ( V_873 ) &&
V_875 != F_326 ( V_873 ) ) ;
if ( V_875 == V_876 )
V_161 = true ;
V_876 = F_190 ( V_4 , V_877 ) & V_476 ;
F_142 ( V_876 != V_875 ) ;
F_39 ( & V_4 -> V_452 . V_481 ) ;
return V_161 ;
}
static void F_332 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
F_333 ( V_845 -> V_874 != V_879 ) ;
F_323 ( V_4 , V_845 , true ) ;
F_173 ( & V_4 -> V_494 ) ;
F_334 ( V_4 ) ;
F_178 ( & V_4 -> V_494 ) ;
if ( V_4 -> V_880 )
F_335 ( V_4 -> V_2 ) ;
F_336 ( V_4 -> V_2 ) ;
}
static void F_337 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_65 V_65 ;
F_333 ( V_845 -> V_874 != V_879 ) ;
F_173 ( & V_4 -> V_494 ) ;
F_145 (pipe)
F_338 ( V_2 , V_65 , false ) ;
F_339 ( V_4 ) ;
F_178 ( & V_4 -> V_494 ) ;
F_173 ( & V_2 -> V_867 ) ;
F_145 (pipe)
F_315 ( V_2 , V_65 ) ;
F_178 ( & V_2 -> V_867 ) ;
F_323 ( V_4 , V_845 , false ) ;
}
static void F_340 ( struct V_3 * V_4 ,
struct V_844 * V_845 )
{
bool V_161 = V_845 -> V_859 -> V_854 ( V_4 , V_845 ) ;
if ( V_845 -> V_858 || ! V_89 . V_881 ) {
if ( ! V_161 )
goto V_882;
return;
}
if ( V_161 != ( V_845 -> V_641 > 0 ) )
goto V_882;
return;
V_882:
F_101 ( 1 , L_94 ,
V_845 -> V_328 , V_845 -> V_858 , V_161 ,
V_845 -> V_641 , V_89 . V_881 ) ;
}
void F_341 ( struct V_3 * V_4 ,
enum V_849 V_850 )
{
struct V_851 * V_852 ;
struct V_844 * V_845 ;
int V_22 ;
F_342 ( V_4 ) ;
V_852 = & V_4 -> V_852 ;
F_38 ( & V_852 -> V_857 ) ;
F_343 (i, power_well, BIT(domain), power_domains) {
if ( ! V_845 -> V_641 ++ ) {
F_5 ( L_95 , V_845 -> V_328 ) ;
V_845 -> V_859 -> V_305 ( V_4 , V_845 ) ;
}
F_340 ( V_4 , V_845 ) ;
}
V_852 -> V_853 [ V_850 ] ++ ;
F_39 ( & V_852 -> V_857 ) ;
}
void F_344 ( struct V_3 * V_4 ,
enum V_849 V_850 )
{
struct V_851 * V_852 ;
struct V_844 * V_845 ;
int V_22 ;
V_852 = & V_4 -> V_852 ;
F_38 ( & V_852 -> V_857 ) ;
F_142 ( ! V_852 -> V_853 [ V_850 ] ) ;
V_852 -> V_853 [ V_850 ] -- ;
F_305 (i, power_well, BIT(domain), power_domains) {
F_142 ( ! V_845 -> V_641 ) ;
if ( ! -- V_845 -> V_641 && V_89 . V_881 ) {
F_5 ( L_96 , V_845 -> V_328 ) ;
V_845 -> V_859 -> V_883 ( V_4 , V_845 ) ;
}
F_340 ( V_4 , V_845 ) ;
}
F_39 ( & V_852 -> V_857 ) ;
F_345 ( V_4 ) ;
}
void F_346 ( void )
{
struct V_3 * V_4 ;
if ( F_142 ( ! V_884 ) )
return;
V_4 = F_36 ( V_884 , struct V_3 ,
V_852 ) ;
F_341 ( V_4 , V_885 ) ;
}
void F_347 ( void )
{
struct V_3 * V_4 ;
if ( F_142 ( ! V_884 ) )
return;
V_4 = F_36 ( V_884 , struct V_3 ,
V_852 ) ;
F_344 ( V_4 , V_885 ) ;
}
int F_348 ( struct V_3 * V_4 )
{
struct V_851 * V_852 = & V_4 -> V_852 ;
F_349 ( & V_852 -> V_857 ) ;
if ( F_56 ( V_4 -> V_2 ) ) {
F_350 ( V_852 , V_886 ) ;
V_884 = V_852 ;
} else if ( F_123 ( V_4 -> V_2 ) ) {
F_350 ( V_852 , V_887 ) ;
V_884 = V_852 ;
} else if ( F_192 ( V_4 -> V_2 ) ) {
F_350 ( V_852 , V_888 ) ;
} else {
F_350 ( V_852 , V_889 ) ;
}
return 0 ;
}
void F_351 ( struct V_3 * V_4 )
{
V_884 = NULL ;
}
static void F_352 ( struct V_3 * V_4 )
{
struct V_851 * V_852 = & V_4 -> V_852 ;
struct V_844 * V_845 ;
int V_22 ;
F_38 ( & V_852 -> V_857 ) ;
F_343 (i, power_well, POWER_DOMAIN_MASK, power_domains)
V_845 -> V_859 -> V_890 ( V_4 , V_845 ) ;
F_39 ( & V_852 -> V_857 ) ;
}
void F_353 ( struct V_3 * V_4 )
{
F_354 ( V_4 , true ) ;
F_352 ( V_4 ) ;
}
void F_355 ( struct V_3 * V_4 )
{
F_342 ( V_4 ) ;
}
void F_356 ( struct V_3 * V_4 )
{
F_345 ( V_4 ) ;
}
void F_342 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_891 * V_891 = & V_2 -> V_861 -> V_2 ;
if ( ! F_357 ( V_2 ) )
return;
F_358 ( V_891 ) ;
F_101 ( V_4 -> V_855 . V_856 , L_97 ) ;
}
void F_345 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_891 * V_891 = & V_2 -> V_861 -> V_2 ;
if ( ! F_357 ( V_2 ) )
return;
F_359 ( V_891 ) ;
F_360 ( V_891 ) ;
}
void F_361 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_891 * V_891 = & V_2 -> V_861 -> V_2 ;
if ( ! F_357 ( V_2 ) )
return;
F_362 ( V_891 ) ;
F_363 ( V_891 , 10000 ) ;
F_359 ( V_891 ) ;
F_364 ( V_891 ) ;
F_360 ( V_891 ) ;
}
void F_365 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_891 * V_891 = & V_2 -> V_861 -> V_2 ;
if ( ! F_357 ( V_2 ) )
return;
F_358 ( V_891 ) ;
F_366 ( V_891 ) ;
}
void F_367 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_52 ( V_2 ) ) {
if ( F_55 ( V_2 ) -> V_97 >= 7 ) {
V_4 -> V_67 . V_68 = F_29 ;
V_4 -> V_67 . V_75 = F_30 ;
V_4 -> V_67 . V_80 = F_28 ;
} else if ( F_55 ( V_2 ) -> V_97 >= 5 ) {
V_4 -> V_67 . V_68 = F_29 ;
V_4 -> V_67 . V_75 = F_24 ;
V_4 -> V_67 . V_80 = F_28 ;
} else if ( F_292 ( V_2 ) ) {
V_4 -> V_67 . V_68 = F_19 ;
V_4 -> V_67 . V_75 = F_15 ;
V_4 -> V_67 . V_80 = F_18 ;
} else {
V_4 -> V_67 . V_68 = F_14 ;
V_4 -> V_67 . V_75 = F_6 ;
V_4 -> V_67 . V_80 = F_1 ;
F_3 ( V_7 , 500 << V_36 ) ;
}
}
if ( F_296 ( V_2 ) )
F_62 ( V_2 ) ;
else if ( F_25 ( V_2 ) )
F_63 ( V_2 ) ;
if ( F_368 ( V_2 ) ) {
F_132 ( V_2 ) ;
if ( ( F_25 ( V_2 ) && V_4 -> V_151 . V_309 [ 1 ] &&
V_4 -> V_151 . V_310 [ 1 ] && V_4 -> V_151 . V_311 [ 1 ] ) ||
( ! F_25 ( V_2 ) && V_4 -> V_151 . V_309 [ 0 ] &&
V_4 -> V_151 . V_310 [ 0 ] && V_4 -> V_151 . V_311 [ 0 ] ) ) {
V_4 -> V_67 . V_396 = F_153 ;
V_4 -> V_67 . V_397 = F_154 ;
} else {
F_5 ( L_98
L_99 ) ;
}
if ( F_25 ( V_2 ) )
V_4 -> V_67 . V_843 = F_274 ;
else if ( F_27 ( V_2 ) )
V_4 -> V_67 . V_843 = F_279 ;
else if ( F_32 ( V_2 ) )
V_4 -> V_67 . V_843 = F_287 ;
else if ( F_56 ( V_2 ) )
V_4 -> V_67 . V_843 = F_286 ;
else if ( F_55 ( V_2 ) -> V_97 == 8 )
V_4 -> V_67 . V_843 = F_284 ;
} else if ( F_192 ( V_2 ) ) {
V_4 -> V_67 . V_396 = F_85 ;
V_4 -> V_67 . V_843 =
F_290 ;
} else if ( F_296 ( V_2 ) ) {
if ( ! F_66 ( F_76 ( V_2 ) ,
V_4 -> V_128 ,
V_4 -> V_118 ,
V_4 -> V_124 ) ) {
F_200 ( L_100
L_101
L_102 ,
( V_4 -> V_128 == 1 ) ? L_103 : L_104 ,
V_4 -> V_118 , V_4 -> V_124 ) ;
F_68 ( V_2 ) ;
V_4 -> V_67 . V_396 = NULL ;
} else
V_4 -> V_67 . V_396 = F_75 ;
V_4 -> V_67 . V_843 = F_295 ;
} else if ( F_57 ( V_2 ) ) {
V_4 -> V_67 . V_396 = F_88 ;
V_4 -> V_67 . V_843 = F_291 ;
} else if ( F_10 ( V_2 ) ) {
V_4 -> V_67 . V_396 = F_89 ;
if ( F_90 ( V_2 ) )
V_4 -> V_67 . V_843 = F_293 ;
else if ( F_369 ( V_2 ) )
V_4 -> V_67 . V_843 = F_294 ;
} else if ( F_370 ( V_2 ) ) {
V_4 -> V_67 . V_396 = F_91 ;
V_4 -> V_67 . V_260 = F_69 ;
V_4 -> V_67 . V_843 = F_295 ;
} else if ( F_9 ( V_2 ) ) {
if ( F_55 ( V_2 ) -> V_300 == 1 ) {
V_4 -> V_67 . V_396 = F_97 ;
V_4 -> V_67 . V_260 = F_71 ;
} else {
V_4 -> V_67 . V_396 = F_91 ;
V_4 -> V_67 . V_260 = F_70 ;
}
if ( F_371 ( V_2 ) || F_372 ( V_2 ) )
V_4 -> V_67 . V_843 = F_297 ;
else
V_4 -> V_67 . V_843 = F_298 ;
} else {
F_45 ( L_105 ) ;
}
}
int F_210 ( struct V_3 * V_4 , T_7 V_892 , T_1 * V_374 )
{
F_142 ( ! F_161 ( & V_4 -> V_452 . V_481 ) ) ;
if ( F_2 ( V_893 ) & V_894 ) {
F_65 ( L_106 ) ;
return - V_895 ;
}
F_3 ( V_896 , * V_374 ) ;
F_3 ( V_893 , V_894 | V_892 ) ;
if ( F_4 ( ( F_2 ( V_893 ) & V_894 ) == 0 ,
500 ) ) {
F_45 ( L_107 , V_892 ) ;
return - V_897 ;
}
* V_374 = F_2 ( V_896 ) ;
F_3 ( V_896 , 0 ) ;
return 0 ;
}
int F_209 ( struct V_3 * V_4 , T_7 V_892 , T_1 V_374 )
{
F_142 ( ! F_161 ( & V_4 -> V_452 . V_481 ) ) ;
if ( F_2 ( V_893 ) & V_894 ) {
F_65 ( L_108 ) ;
return - V_895 ;
}
F_3 ( V_896 , V_374 ) ;
F_3 ( V_893 , V_894 | V_892 ) ;
if ( F_4 ( ( F_2 ( V_893 ) & V_894 ) == 0 ,
500 ) ) {
F_45 ( L_109 , V_892 ) ;
return - V_897 ;
}
F_3 ( V_896 , 0 ) ;
return 0 ;
}
int F_195 ( struct V_3 * V_4 , int V_374 )
{
int div ;
switch ( V_4 -> V_124 ) {
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
return F_118 ( V_4 -> V_124 * ( V_374 + 6 - 0xbd ) , 4 * div ) ;
}
int F_373 ( struct V_3 * V_4 , int V_374 )
{
int V_898 ;
switch ( V_4 -> V_124 ) {
case 800 :
V_898 = 10 ;
break;
case 1066 :
V_898 = 12 ;
break;
case 1333 :
V_898 = 16 ;
break;
default:
return - 1 ;
}
return F_118 ( 4 * V_898 * V_374 , V_4 -> V_124 ) + 0xbd - 6 ;
}
void F_374 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_349 ( & V_4 -> V_452 . V_481 ) ;
F_46 ( & V_4 -> V_452 . V_683 ,
F_265 ) ;
V_4 -> V_855 . V_856 = false ;
V_4 -> V_855 . V_899 = false ;
}
