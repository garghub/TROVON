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
F_53 (dev, tmp_crtc) {
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
if ( V_89 . V_75 < 0 ) {
if ( F_50 ( V_4 , V_97 ) )
F_5 ( L_10 ) ;
goto V_94;
}
if ( ! V_89 . V_75 ) {
if ( F_50 ( V_4 , V_91 ) )
F_5 ( L_7 ) ;
goto V_94;
}
if ( ( V_85 -> V_98 & V_99 ) ||
( V_85 -> V_98 & V_100 ) ) {
if ( F_50 ( V_4 , V_101 ) )
F_5 ( L_11
L_12 ) ;
goto V_94;
}
if ( F_55 ( V_2 ) || F_56 ( V_2 ) -> V_102 >= 5 ) {
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
if ( ( F_56 ( V_2 ) -> V_102 < 4 || F_57 ( V_2 ) ) &&
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
if ( F_58 () )
goto V_94;
if ( F_59 ( V_2 , V_17 -> V_19 -> V_77 . V_24 ) ) {
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
F_60 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
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
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_130 , V_131 ;
V_130 = F_63 ( V_132 ) ;
V_131 = F_63 ( V_133 ) ;
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
F_64 ( L_19 ,
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
F_64 ( L_20 ,
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
static const struct V_137 * F_65 ( int V_138 ,
int V_128 ,
int V_139 ,
int V_140 )
{
const struct V_137 * V_141 ;
int V_22 ;
if ( V_139 == 0 || V_140 == 0 )
return NULL ;
for ( V_22 = 0 ; V_22 < F_66 ( V_142 ) ; V_22 ++ ) {
V_141 = & V_142 [ V_22 ] ;
if ( V_138 == V_141 -> V_138 &&
V_128 == V_141 -> V_128 &&
V_139 == V_141 -> V_118 && V_140 == V_141 -> V_124 )
return V_141 ;
}
F_5 ( L_21 ) ;
return NULL ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_143 , F_2 ( V_143 ) & ~ V_144 ) ;
}
static int F_68 ( struct V_1 * V_2 , int V_32 )
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
static int F_69 ( struct V_1 * V_2 , int V_32 )
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
static int F_70 ( struct V_1 * V_2 , int V_32 )
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
static unsigned long F_71 ( unsigned long V_149 ,
const struct V_150 * V_151 ,
int V_152 ,
int V_153 ,
unsigned long V_154 )
{
long V_155 , V_156 ;
V_155 = ( ( V_149 / 1000 ) * V_153 * V_154 ) /
1000 ;
V_155 = F_72 ( V_155 , V_151 -> V_157 ) ;
F_5 ( L_25 , V_155 ) ;
V_156 = V_152 - ( V_155 + V_151 -> V_158 ) ;
F_5 ( L_26 , V_156 ) ;
if ( V_156 > ( long ) V_151 -> V_159 )
V_156 = V_151 -> V_159 ;
if ( V_156 <= 0 )
V_156 = V_151 -> V_160 ;
return V_156 ;
}
static struct V_11 * F_73 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_161 = NULL ;
F_53 (dev, crtc) {
if ( F_54 ( V_12 ) ) {
if ( V_161 )
return NULL ;
V_161 = V_12 ;
}
}
return V_161 ;
}
static void F_74 ( struct V_11 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_137 * V_141 ;
T_1 V_163 ;
unsigned long V_151 ;
V_141 = F_65 ( F_75 ( V_2 ) , V_4 -> V_128 ,
V_4 -> V_118 , V_4 -> V_124 ) ;
if ( ! V_141 ) {
F_5 ( L_21 ) ;
F_67 ( V_2 ) ;
return;
}
V_12 = F_73 ( V_2 ) ;
if ( V_12 ) {
const struct V_84 * V_85 ;
int V_153 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
int clock ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
clock = V_85 -> V_165 ;
V_151 = F_71 ( clock , & V_166 ,
V_166 . V_152 ,
V_153 , V_141 -> V_167 ) ;
V_163 = F_2 ( V_168 ) ;
V_163 &= ~ V_169 ;
V_163 |= V_151 << V_170 ;
F_3 ( V_168 , V_163 ) ;
F_5 ( L_27 , V_163 ) ;
V_151 = F_71 ( clock , & V_171 ,
V_166 . V_152 ,
V_153 , V_141 -> V_172 ) ;
V_163 = F_2 ( V_143 ) ;
V_163 &= ~ V_173 ;
V_163 |= ( V_151 & 0x3f ) << V_174 ;
F_3 ( V_143 , V_163 ) ;
V_151 = F_71 ( clock , & V_175 ,
V_175 . V_152 ,
V_153 , V_141 -> V_176 ) ;
V_163 = F_2 ( V_143 ) ;
V_163 &= ~ V_177 ;
V_163 |= V_151 & V_177 ;
F_3 ( V_143 , V_163 ) ;
V_151 = F_71 ( clock , & V_178 ,
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
F_67 ( V_2 ) ;
F_5 ( L_30 ) ;
}
}
static bool F_76 ( struct V_1 * V_2 ,
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
V_12 = F_77 ( V_2 , V_32 ) ;
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
V_191 = F_72 ( V_191 , V_67 -> V_157 ) ;
* V_185 = V_191 + V_67 -> V_158 ;
if ( * V_185 > ( int ) V_67 -> V_159 )
* V_185 = V_67 -> V_159 ;
V_189 = F_78 ( V_187 * 1000 / clock , 1 ) ;
V_190 = ( V_184 / V_189 + 1000 ) / 1000 ;
V_191 = V_190 * F_8 ( V_12 ) -> V_194 * V_153 ;
V_192 = V_183 -> V_152 * V_183 -> V_157 - V_188 * 8 ;
if ( V_192 > 0 )
V_191 += V_192 ;
V_191 = F_72 ( V_191 , V_183 -> V_157 ) ;
* V_186 = V_191 + V_183 -> V_158 ;
if ( * V_186 > ( int ) V_183 -> V_159 )
* V_186 = ( int ) V_183 -> V_159 ;
return true ;
}
static bool F_79 ( struct V_1 * V_2 ,
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
static bool F_80 ( struct V_1 * V_2 ,
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
V_12 = F_77 ( V_2 , V_32 ) ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
clock = V_85 -> V_165 ;
V_187 = V_85 -> V_193 ;
V_188 = F_8 ( V_12 ) -> V_96 . V_103 ;
V_153 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
V_189 = F_78 ( V_187 * 1000 / clock , 1 ) ;
V_190 = ( V_154 / V_189 + 1000 ) / 1000 ;
V_196 = V_188 * V_153 ;
V_197 = ( ( clock * V_153 / 1000 ) * V_154 ) / 1000 ;
V_198 = V_190 * V_196 ;
V_191 = F_72 ( F_81 ( V_197 , V_198 ) , V_67 -> V_157 ) ;
* V_195 = V_191 + V_67 -> V_158 ;
V_191 = V_190 * V_153 * F_8 ( V_12 ) -> V_194 ;
V_191 = F_72 ( V_191 , V_183 -> V_157 ) ;
* V_186 = V_191 + V_183 -> V_158 ;
return F_79 ( V_2 ,
* V_195 , * V_186 ,
V_67 , V_183 ) ;
}
static bool F_82 ( struct V_1 * V_2 ,
int V_32 ,
int * V_199 ,
int * V_200 ,
int * V_201 ,
int * V_202 )
{
struct V_11 * V_12 ;
int clock , V_153 ;
int V_191 ;
V_12 = F_77 ( V_2 , V_32 ) ;
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
static void F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_205 , V_206 , V_207 , V_208 ;
int V_209 , V_210 , V_211 , V_212 ;
int V_199 , V_201 ;
if ( F_82 ( V_2 , 0 , & V_199 , & V_206 ,
& V_201 , & V_210 ) ) {
V_209 = ( V_201 == V_203 ) ?
V_213 : V_214 ;
V_205 = ( V_199 == V_203 ) ?
V_215 : V_216 ;
F_3 ( V_217 , V_209 |
( V_210 << V_218 ) |
V_205 | V_206 ) ;
}
if ( F_82 ( V_2 , 1 , & V_199 , & V_208 ,
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
static void F_84 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_225 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_226 , V_227 , V_228 , V_229 ;
int V_230 , V_172 ;
int V_231 , V_232 ;
unsigned int V_161 = 0 ;
F_83 ( V_2 ) ;
if ( F_76 ( V_2 , V_233 ,
& V_234 , V_154 ,
& V_235 , V_154 ,
& V_226 , & V_228 ) )
V_161 |= 1 << V_233 ;
if ( F_76 ( V_2 , V_236 ,
& V_234 , V_154 ,
& V_235 , V_154 ,
& V_227 , & V_229 ) )
V_161 |= 1 << V_236 ;
if ( F_85 ( V_161 ) &&
F_80 ( V_2 , F_86 ( V_161 ) - 1 ,
V_225 ,
& V_234 ,
& V_235 ,
& V_230 , & V_232 ) &&
F_80 ( V_2 , F_86 ( V_161 ) - 1 ,
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
static void F_87 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_225 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_226 , V_227 , V_228 , V_229 ;
int V_230 , V_172 ;
unsigned int V_161 = 0 ;
if ( F_76 ( V_2 , V_233 ,
& V_244 , V_154 ,
& V_245 , V_154 ,
& V_226 , & V_228 ) )
V_161 |= 1 << V_233 ;
if ( F_76 ( V_2 , V_236 ,
& V_244 , V_154 ,
& V_245 , V_154 ,
& V_227 , & V_229 ) )
V_161 |= 1 << V_236 ;
if ( F_85 ( V_161 ) &&
F_80 ( V_2 , F_86 ( V_161 ) - 1 ,
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
static void F_88 ( struct V_11 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
int V_249 = 1 ;
int V_172 = 16 ;
V_12 = F_73 ( V_2 ) ;
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
V_189 = F_78 ( V_187 * 1000 / clock , 1 ) ;
V_191 = ( ( ( V_225 / V_189 ) + 1000 ) / 1000 ) *
V_153 * V_188 ;
V_191 = F_72 ( V_191 , V_250 ) ;
V_249 = V_251 - V_191 ;
if ( V_249 < 0 )
V_249 = 1 ;
V_249 &= 0x1ff ;
F_5 ( L_36 ,
V_191 , V_249 ) ;
V_191 = ( ( ( V_225 / V_189 ) + 1000 ) / 1000 ) *
V_153 * F_8 ( V_12 ) -> V_194 ;
V_191 = F_72 ( V_191 ,
V_252 . V_157 ) ;
V_172 = V_252 . V_152 -
( V_191 + V_252 . V_158 ) ;
if ( V_172 > V_252 . V_159 )
V_172 = V_252 . V_159 ;
F_5 ( L_37
L_38 , V_249 , V_172 ) ;
if ( F_89 ( V_2 ) )
F_3 ( V_246 , V_247 ) ;
} else {
if ( F_89 ( V_2 ) )
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
static void F_90 ( struct V_11 * V_162 )
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
V_12 = F_77 ( V_2 , 0 ) ;
if ( F_54 ( V_12 ) ) {
const struct V_84 * V_85 ;
int V_261 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
if ( F_9 ( V_2 ) )
V_261 = 4 ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_226 = F_71 ( V_85 -> V_165 ,
V_253 , V_152 , V_261 ,
V_154 ) ;
V_161 = V_12 ;
} else
V_226 = V_152 - V_253 -> V_158 ;
V_152 = V_4 -> V_67 . V_260 ( V_2 , 1 ) ;
V_12 = F_77 ( V_2 , 1 ) ;
if ( F_54 ( V_12 ) ) {
const struct V_84 * V_85 ;
int V_261 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
if ( F_9 ( V_2 ) )
V_261 = 4 ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_227 = F_71 ( V_85 -> V_165 ,
V_253 , V_152 , V_261 ,
V_154 ) ;
if ( V_161 == NULL )
V_161 = V_12 ;
else
V_161 = NULL ;
} else
V_227 = V_152 - V_253 -> V_158 ;
F_5 ( L_40 , V_226 , V_227 ) ;
if ( F_91 ( V_2 ) && V_161 ) {
struct V_16 * V_14 ;
V_14 = F_7 ( V_161 -> V_15 -> V_14 ) ;
if ( V_14 -> V_19 -> V_108 == V_262 )
V_161 = NULL ;
}
V_256 = 2 ;
if ( F_92 ( V_2 ) || F_12 ( V_2 ) )
F_3 ( V_246 , V_263 | 0 ) ;
else if ( F_91 ( V_2 ) )
F_3 ( V_264 , F_93 ( V_265 ) ) ;
if ( F_94 ( V_2 ) && V_161 ) {
static const int V_225 = 6000 ;
const struct V_84 * V_85 =
& F_8 ( V_161 ) -> V_96 . V_85 ;
int clock = V_85 -> V_165 ;
int V_187 = V_85 -> V_193 ;
int V_188 = F_8 ( V_161 ) -> V_96 . V_103 ;
int V_153 = V_161 -> V_15 -> V_14 -> V_164 / 8 ;
unsigned long V_189 ;
int V_191 ;
V_189 = F_78 ( V_187 * 1000 / clock , 1 ) ;
V_191 = ( ( ( V_225 / V_189 ) + 1000 ) / 1000 ) *
V_153 * V_188 ;
V_191 = F_72 ( V_191 , V_253 -> V_157 ) ;
F_5 ( L_41 , V_191 ) ;
V_249 = V_253 -> V_152 - V_191 ;
if ( V_249 < 0 )
V_249 = 1 ;
if ( F_92 ( V_2 ) || F_12 ( V_2 ) )
F_3 ( V_246 ,
V_266 | ( V_249 & 0xff ) ) ;
else if ( F_91 ( V_2 ) )
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
if ( F_94 ( V_2 ) ) {
if ( V_161 ) {
if ( F_92 ( V_2 ) || F_12 ( V_2 ) )
F_3 ( V_246 ,
V_263 | V_247 ) ;
else if ( F_91 ( V_2 ) )
F_3 ( V_264 , F_95 ( V_265 ) ) ;
F_5 ( L_43 ) ;
} else
F_5 ( L_44 ) ;
}
}
static void F_96 ( struct V_11 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_84 * V_85 ;
T_3 V_254 ;
int V_226 ;
V_12 = F_73 ( V_2 ) ;
if ( V_12 == NULL )
return;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_226 = F_71 ( V_85 -> V_165 ,
& V_269 ,
V_4 -> V_67 . V_260 ( V_2 , 0 ) ,
4 , V_154 ) ;
V_254 = F_2 ( V_267 ) & ~ 0xfff ;
V_254 |= ( 3 << 8 ) | V_226 ;
F_5 ( L_45 , V_226 ) ;
F_3 ( V_267 , V_254 ) ;
}
static T_3 F_97 ( struct V_1 * V_2 ,
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
V_270 = F_98 ( ( T_4 ) V_270 * V_272 * V_273 ,
V_274 * V_275 ) ;
}
return V_270 ;
}
static T_3 F_99 ( T_3 V_270 , T_5 V_277 ,
T_3 V_141 )
{
T_4 V_278 ;
if ( F_100 ( V_141 == 0 , L_46 ) )
return V_279 ;
V_278 = ( T_4 ) V_270 * V_277 * V_141 ;
V_278 = F_101 ( V_278 , 64 * 10000 ) + 2 ;
return V_278 ;
}
static T_3 F_102 ( T_3 V_270 , T_3 V_280 ,
T_3 V_281 , T_5 V_277 ,
T_3 V_141 )
{
T_3 V_278 ;
if ( F_100 ( V_141 == 0 , L_46 ) )
return V_279 ;
V_278 = ( V_141 * V_270 ) / ( V_280 * 10000 ) ;
V_278 = ( V_278 + 1 ) * V_281 * V_277 ;
V_278 = F_72 ( V_278 , 64 ) + 2 ;
return V_278 ;
}
static T_3 F_103 ( T_3 V_282 , T_3 V_281 ,
T_5 V_277 )
{
return F_72 ( V_282 * 64 , V_281 * V_277 ) + 2 ;
}
static T_3 F_104 ( const struct V_283 * V_284 ,
T_3 V_285 ,
bool V_286 )
{
T_3 V_287 , V_288 ;
if ( ! V_284 -> V_289 || ! V_284 -> V_290 . V_161 )
return 0 ;
V_287 = F_99 ( V_284 -> V_270 ,
V_284 -> V_290 . V_277 ,
V_285 ) ;
if ( ! V_286 )
return V_287 ;
V_288 = F_102 ( V_284 -> V_270 ,
V_284 -> V_280 ,
V_284 -> V_290 . V_281 ,
V_284 -> V_290 . V_277 ,
V_285 ) ;
return F_81 ( V_287 , V_288 ) ;
}
static T_3 F_105 ( const struct V_283 * V_284 ,
T_3 V_285 )
{
T_3 V_287 , V_288 ;
if ( ! V_284 -> V_289 || ! V_284 -> V_291 . V_161 )
return 0 ;
V_287 = F_99 ( V_284 -> V_270 ,
V_284 -> V_291 . V_277 ,
V_285 ) ;
V_288 = F_102 ( V_284 -> V_270 ,
V_284 -> V_280 ,
V_284 -> V_291 . V_281 ,
V_284 -> V_291 . V_277 ,
V_285 ) ;
return F_81 ( V_287 , V_288 ) ;
}
static T_3 F_106 ( const struct V_283 * V_284 ,
T_3 V_285 )
{
if ( ! V_284 -> V_289 || ! V_284 -> V_292 . V_161 )
return 0 ;
return F_102 ( V_284 -> V_270 ,
V_284 -> V_280 ,
V_284 -> V_292 . V_281 ,
V_284 -> V_292 . V_277 ,
V_285 ) ;
}
static T_3 F_107 ( const struct V_283 * V_284 ,
T_3 V_282 )
{
if ( ! V_284 -> V_289 || ! V_284 -> V_290 . V_161 )
return 0 ;
return F_103 ( V_282 ,
V_284 -> V_290 . V_281 ,
V_284 -> V_290 . V_277 ) ;
}
static unsigned int F_108 ( const struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) -> V_102 >= 8 )
return 3072 ;
else if ( F_56 ( V_2 ) -> V_102 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_109 ( const struct V_1 * V_2 ,
int V_293 , bool V_294 )
{
if ( F_56 ( V_2 ) -> V_102 >= 8 )
return V_293 == 0 ? 255 : 2047 ;
else if ( F_56 ( V_2 ) -> V_102 >= 7 )
return V_293 == 0 ? 127 : 1023 ;
else if ( ! V_294 )
return V_293 == 0 ? 127 : 511 ;
else
return V_293 == 0 ? 63 : 255 ;
}
static unsigned int F_110 ( const struct V_1 * V_2 ,
int V_293 )
{
if ( F_56 ( V_2 ) -> V_102 >= 7 )
return V_293 == 0 ? 63 : 255 ;
else
return V_293 == 0 ? 31 : 63 ;
}
static unsigned int F_111 ( const struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) -> V_102 >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_112 ( const struct V_1 * V_2 ,
int V_293 ,
const struct V_295 * V_96 ,
enum V_296 V_297 ,
bool V_294 )
{
unsigned int V_152 = F_108 ( V_2 ) ;
if ( V_294 && ! V_96 -> V_298 )
return 0 ;
if ( V_293 == 0 || V_96 -> V_299 > 1 ) {
V_152 /= F_56 ( V_2 ) -> V_300 ;
if ( F_56 ( V_2 ) -> V_102 <= 6 )
V_152 /= 2 ;
}
if ( V_96 -> V_298 ) {
if ( V_293 > 0 && V_297 == V_301 ) {
if ( V_294 )
V_152 *= 5 ;
V_152 /= 6 ;
} else {
V_152 /= 2 ;
}
}
return F_81 ( V_152 , F_109 ( V_2 , V_293 , V_294 ) ) ;
}
static unsigned int F_113 ( const struct V_1 * V_2 ,
int V_293 ,
const struct V_295 * V_96 )
{
if ( V_293 > 0 && V_96 -> V_299 > 1 )
return 64 ;
return F_110 ( V_2 , V_293 ) ;
}
static void F_114 ( const struct V_1 * V_2 ,
int V_293 ,
const struct V_295 * V_96 ,
enum V_296 V_297 ,
struct V_302 * F_78 )
{
F_78 -> V_290 = F_112 ( V_2 , V_293 , V_96 , V_297 , false ) ;
F_78 -> V_291 = F_112 ( V_2 , V_293 , V_96 , V_297 , true ) ;
F_78 -> V_292 = F_113 ( V_2 , V_293 , V_96 ) ;
F_78 -> V_23 = F_111 ( V_2 ) ;
}
static void F_115 ( struct V_1 * V_2 ,
int V_293 ,
struct V_302 * F_78 )
{
F_78 -> V_290 = F_109 ( V_2 , V_293 , false ) ;
F_78 -> V_291 = F_109 ( V_2 , V_293 , true ) ;
F_78 -> V_292 = F_110 ( V_2 , V_293 ) ;
F_78 -> V_23 = F_111 ( V_2 ) ;
}
static bool F_116 ( int V_293 ,
const struct V_302 * F_78 ,
struct V_303 * V_304 )
{
bool V_278 ;
if ( ! V_304 -> V_305 )
return false ;
V_304 -> V_305 = V_304 -> V_282 <= F_78 -> V_290 &&
V_304 -> V_306 <= F_78 -> V_291 &&
V_304 -> V_307 <= F_78 -> V_292 ;
V_278 = V_304 -> V_305 ;
if ( V_293 == 0 && ! V_304 -> V_305 ) {
if ( V_304 -> V_282 > F_78 -> V_290 )
F_5 ( L_47 ,
V_293 , V_304 -> V_282 , F_78 -> V_290 ) ;
if ( V_304 -> V_306 > F_78 -> V_291 )
F_5 ( L_48 ,
V_293 , V_304 -> V_306 , F_78 -> V_291 ) ;
if ( V_304 -> V_307 > F_78 -> V_292 )
F_5 ( L_49 ,
V_293 , V_304 -> V_307 , F_78 -> V_292 ) ;
V_304 -> V_282 = F_117 ( T_3 , V_304 -> V_282 , F_78 -> V_290 ) ;
V_304 -> V_306 = F_117 ( T_3 , V_304 -> V_306 , F_78 -> V_291 ) ;
V_304 -> V_307 = F_117 ( T_3 , V_304 -> V_307 , F_78 -> V_292 ) ;
V_304 -> V_305 = true ;
}
return V_278 ;
}
static void F_118 ( const struct V_3 * V_4 ,
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
V_304 -> V_282 = F_104 ( V_308 , V_309 , V_293 ) ;
V_304 -> V_306 = F_105 ( V_308 , V_310 ) ;
V_304 -> V_307 = F_106 ( V_308 , V_311 ) ;
V_304 -> V_312 = F_107 ( V_308 , V_304 -> V_282 ) ;
V_304 -> V_305 = true ;
}
static T_3
F_119 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
struct V_84 * V_313 = & V_20 -> V_96 . V_85 ;
T_1 V_314 , V_315 ;
if ( ! F_54 ( V_12 ) )
return 0 ;
V_314 = F_120 ( V_313 -> V_193 * 1000 * 8 ,
V_313 -> V_165 ) ;
V_315 = F_120 ( V_313 -> V_193 * 1000 * 8 ,
F_121 ( V_4 ) ) ;
return F_122 ( V_315 ) |
F_123 ( V_314 ) ;
}
static void F_124 ( struct V_1 * V_2 , T_6 V_151 [ 5 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_125 ( V_2 ) || F_126 ( V_2 ) ) {
T_4 V_316 = F_127 ( V_317 ) ;
V_151 [ 0 ] = ( V_316 >> 56 ) & 0xFF ;
if ( V_151 [ 0 ] == 0 )
V_151 [ 0 ] = V_316 & 0xF ;
V_151 [ 1 ] = ( V_316 >> 4 ) & 0xFF ;
V_151 [ 2 ] = ( V_316 >> 12 ) & 0xFF ;
V_151 [ 3 ] = ( V_316 >> 20 ) & 0x1FF ;
V_151 [ 4 ] = ( V_316 >> 32 ) & 0x1FF ;
} else if ( F_56 ( V_2 ) -> V_102 >= 6 ) {
T_3 V_316 = F_2 ( V_317 ) ;
V_151 [ 0 ] = ( V_316 >> V_318 ) & V_319 ;
V_151 [ 1 ] = ( V_316 >> V_320 ) & V_319 ;
V_151 [ 2 ] = ( V_316 >> V_321 ) & V_319 ;
V_151 [ 3 ] = ( V_316 >> V_322 ) & V_319 ;
} else if ( F_56 ( V_2 ) -> V_102 >= 5 ) {
T_3 V_323 = F_2 ( V_324 ) ;
V_151 [ 0 ] = 7 ;
V_151 [ 1 ] = ( V_323 >> V_325 ) & V_326 ;
V_151 [ 2 ] = ( V_323 >> V_327 ) & V_326 ;
}
}
static void F_128 ( struct V_1 * V_2 , T_6 V_151 [ 5 ] )
{
if ( F_56 ( V_2 ) -> V_102 == 5 )
V_151 [ 0 ] = 13 ;
}
static void F_129 ( struct V_1 * V_2 , T_6 V_151 [ 5 ] )
{
if ( F_56 ( V_2 ) -> V_102 == 5 )
V_151 [ 0 ] = 13 ;
if ( F_32 ( V_2 ) )
V_151 [ 3 ] *= 2 ;
}
int F_130 ( const struct V_1 * V_2 )
{
if ( F_125 ( V_2 ) || F_126 ( V_2 ) )
return 4 ;
else if ( F_56 ( V_2 ) -> V_102 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_131 ( struct V_1 * V_2 ,
const char * V_328 ,
const T_6 V_151 [ 5 ] )
{
int V_293 , V_329 = F_130 ( V_2 ) ;
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
static bool F_132 ( struct V_3 * V_4 ,
T_6 V_151 [ 5 ] , T_6 F_81 )
{
int V_293 , V_329 = F_130 ( V_4 -> V_2 ) ;
if ( V_151 [ 0 ] >= F_81 )
return false ;
V_151 [ 0 ] = F_78 ( V_151 [ 0 ] , F_81 ) ;
for ( V_293 = 1 ; V_293 <= V_329 ; V_293 ++ )
V_151 [ V_293 ] = F_133 ( T_6 , V_151 [ V_293 ] , F_72 ( F_81 , 5 ) ) ;
return true ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_330 ;
V_330 = F_132 ( V_4 , V_4 -> V_151 . V_309 , 12 ) |
F_132 ( V_4 , V_4 -> V_151 . V_310 , 12 ) |
F_132 ( V_4 , V_4 -> V_151 . V_311 , 12 ) ;
if ( ! V_330 )
return;
F_5 ( L_52 ) ;
F_131 ( V_2 , L_53 , V_4 -> V_151 . V_309 ) ;
F_131 ( V_2 , L_54 , V_4 -> V_151 . V_310 ) ;
F_131 ( V_2 , L_55 , V_4 -> V_151 . V_311 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_124 ( V_2 , V_4 -> V_151 . V_309 ) ;
memcpy ( V_4 -> V_151 . V_310 , V_4 -> V_151 . V_309 ,
sizeof( V_4 -> V_151 . V_309 ) ) ;
memcpy ( V_4 -> V_151 . V_311 , V_4 -> V_151 . V_309 ,
sizeof( V_4 -> V_151 . V_309 ) ) ;
F_128 ( V_2 , V_4 -> V_151 . V_310 ) ;
F_129 ( V_2 , V_4 -> V_151 . V_311 ) ;
F_131 ( V_2 , L_53 , V_4 -> V_151 . V_309 ) ;
F_131 ( V_2 , L_54 , V_4 -> V_151 . V_310 ) ;
F_131 ( V_2 , L_55 , V_4 -> V_151 . V_311 ) ;
if ( F_27 ( V_2 ) )
F_134 ( V_2 ) ;
}
static void F_136 ( struct V_11 * V_12 ,
struct V_283 * V_308 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
enum V_65 V_65 = V_20 -> V_65 ;
struct V_331 * V_32 ;
if ( ! F_54 ( V_12 ) )
return;
V_308 -> V_289 = true ;
V_308 -> V_280 = V_20 -> V_96 . V_85 . V_193 ;
V_308 -> V_270 = F_97 ( V_2 , V_12 ) ;
V_308 -> V_290 . V_277 = V_12 -> V_15 -> V_14 -> V_164 / 8 ;
V_308 -> V_292 . V_277 = 4 ;
V_308 -> V_290 . V_281 = V_20 -> V_96 . V_103 ;
V_308 -> V_292 . V_281 = V_20 -> V_194 ;
V_308 -> V_290 . V_161 = true ;
V_308 -> V_292 . V_161 = true ;
F_137 (plane, &dev->mode_config.plane_list) {
struct V_332 * V_332 = F_138 ( V_32 ) ;
if ( V_332 -> V_65 == V_65 ) {
V_308 -> V_291 = V_332 -> V_151 ;
break;
}
}
}
static void F_139 ( struct V_1 * V_2 ,
struct V_295 * V_96 )
{
struct V_20 * V_20 ;
F_140 (dev, intel_crtc) {
const struct V_333 * V_151 = & V_20 -> V_151 . V_289 ;
if ( ! V_151 -> V_334 )
continue;
V_96 -> V_298 |= V_151 -> V_298 ;
V_96 -> V_335 |= V_151 -> V_335 ;
V_96 -> V_299 ++ ;
}
}
static bool F_141 ( struct V_11 * V_12 ,
const struct V_283 * V_284 ,
struct V_333 * V_336 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
int V_293 , V_329 = F_130 ( V_2 ) ;
struct V_295 V_96 = {
. V_299 = 1 ,
. V_298 = V_284 -> V_291 . V_161 ,
. V_335 = V_284 -> V_291 . V_337 ,
} ;
struct V_302 F_78 ;
V_336 -> V_334 = V_284 -> V_289 ;
V_336 -> V_298 = V_284 -> V_291 . V_161 ;
V_336 -> V_335 = V_284 -> V_291 . V_337 ;
if ( F_56 ( V_2 ) -> V_102 <= 6 && V_284 -> V_291 . V_161 )
V_329 = 1 ;
if ( V_284 -> V_291 . V_337 )
V_329 = 0 ;
F_118 ( V_4 , 0 , V_284 , & V_336 -> V_151 [ 0 ] ) ;
if ( F_125 ( V_2 ) || F_126 ( V_2 ) )
V_336 -> V_314 = F_119 ( V_2 , V_12 ) ;
F_114 ( V_2 , 0 , & V_96 , V_338 , & F_78 ) ;
if ( ! F_116 ( 0 , & F_78 , & V_336 -> V_151 [ 0 ] ) )
return false ;
F_115 ( V_2 , 1 , & F_78 ) ;
for ( V_293 = 1 ; V_293 <= V_329 ; V_293 ++ ) {
struct V_303 V_151 = {} ;
F_118 ( V_4 , V_293 , V_284 , & V_151 ) ;
if ( ! F_116 ( V_293 , & F_78 , & V_151 ) )
break;
V_336 -> V_151 [ V_293 ] = V_151 ;
}
return true ;
}
static void F_142 ( struct V_1 * V_2 ,
int V_293 ,
struct V_303 * V_339 )
{
const struct V_20 * V_20 ;
V_339 -> V_305 = true ;
F_140 (dev, intel_crtc) {
const struct V_333 * V_289 = & V_20 -> V_151 . V_289 ;
const struct V_303 * V_151 = & V_289 -> V_151 [ V_293 ] ;
if ( ! V_289 -> V_334 )
continue;
if ( ! V_151 -> V_305 )
V_339 -> V_305 = false ;
V_339 -> V_282 = F_78 ( V_339 -> V_282 , V_151 -> V_282 ) ;
V_339 -> V_306 = F_78 ( V_339 -> V_306 , V_151 -> V_306 ) ;
V_339 -> V_307 = F_78 ( V_339 -> V_307 , V_151 -> V_307 ) ;
V_339 -> V_312 = F_78 ( V_339 -> V_312 , V_151 -> V_312 ) ;
}
}
static void F_143 ( struct V_1 * V_2 ,
const struct V_295 * V_96 ,
const struct V_302 * F_78 ,
struct V_333 * V_340 )
{
int V_293 , V_329 = F_130 ( V_2 ) ;
int V_341 = V_329 ;
if ( ( F_56 ( V_2 ) -> V_102 <= 6 || F_32 ( V_2 ) ) &&
V_96 -> V_299 > 1 )
return;
V_340 -> V_342 = F_56 ( V_2 ) -> V_102 >= 6 ;
for ( V_293 = 1 ; V_293 <= V_329 ; V_293 ++ ) {
struct V_303 * V_151 = & V_340 -> V_151 [ V_293 ] ;
F_142 ( V_2 , V_293 , V_151 ) ;
if ( V_293 > V_341 )
V_151 -> V_305 = false ;
else if ( ! F_116 ( V_293 , F_78 , V_151 ) )
V_341 = V_293 - 1 ;
if ( V_151 -> V_312 > F_78 -> V_23 ) {
if ( V_151 -> V_305 )
V_340 -> V_342 = false ;
V_151 -> V_312 = 0 ;
}
}
if ( F_25 ( V_2 ) && ! V_340 -> V_342 && F_34 ( V_2 ) ) {
for ( V_293 = 2 ; V_293 <= V_329 ; V_293 ++ ) {
struct V_303 * V_151 = & V_340 -> V_151 [ V_293 ] ;
V_151 -> V_305 = false ;
}
}
}
static int F_144 ( int V_343 , const struct V_333 * V_336 )
{
return V_343 + ( V_343 >= 2 && V_336 -> V_151 [ 4 ] . V_305 ) ;
}
static unsigned int F_145 ( struct V_1 * V_2 , int V_293 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_125 ( V_2 ) || F_126 ( V_2 ) )
return 2 * V_293 ;
else
return V_4 -> V_151 . V_309 [ V_293 ] ;
}
static void F_146 ( struct V_1 * V_2 ,
const struct V_333 * V_340 ,
enum V_296 V_344 ,
struct V_345 * V_346 )
{
struct V_20 * V_20 ;
int V_293 , V_343 ;
V_346 -> V_347 = V_340 -> V_342 ;
V_346 -> V_344 = V_344 ;
for ( V_343 = 1 ; V_343 <= 3 ; V_343 ++ ) {
const struct V_303 * V_348 ;
V_293 = F_144 ( V_343 , V_340 ) ;
V_348 = & V_340 -> V_151 [ V_293 ] ;
V_346 -> V_343 [ V_343 - 1 ] =
( F_145 ( V_2 , V_293 ) << V_349 ) |
( V_348 -> V_282 << V_350 ) |
V_348 -> V_307 ;
if ( V_348 -> V_305 )
V_346 -> V_343 [ V_343 - 1 ] |= V_351 ;
if ( F_56 ( V_2 ) -> V_102 >= 8 )
V_346 -> V_343 [ V_343 - 1 ] |=
V_348 -> V_312 << V_352 ;
else
V_346 -> V_343 [ V_343 - 1 ] |=
V_348 -> V_312 << V_353 ;
if ( F_56 ( V_2 ) -> V_102 <= 6 && V_348 -> V_306 ) {
F_147 ( V_343 != 1 ) ;
V_346 -> V_354 [ V_343 - 1 ] = V_355 | V_348 -> V_306 ;
} else
V_346 -> V_354 [ V_343 - 1 ] = V_348 -> V_306 ;
}
F_140 (dev, intel_crtc) {
enum V_65 V_65 = V_20 -> V_65 ;
const struct V_303 * V_348 =
& V_20 -> V_151 . V_289 . V_151 [ 0 ] ;
if ( F_147 ( ! V_348 -> V_305 ) )
continue;
V_346 -> V_356 [ V_65 ] = V_20 -> V_151 . V_289 . V_314 ;
V_346 -> V_357 [ V_65 ] =
( V_348 -> V_282 << V_358 ) |
( V_348 -> V_306 << V_359 ) |
V_348 -> V_307 ;
}
}
static struct V_333 * F_148 ( struct V_1 * V_2 ,
struct V_333 * V_360 ,
struct V_333 * V_361 )
{
int V_293 , V_329 = F_130 ( V_2 ) ;
int V_362 = 0 , V_363 = 0 ;
for ( V_293 = 1 ; V_293 <= V_329 ; V_293 ++ ) {
if ( V_360 -> V_151 [ V_293 ] . V_305 )
V_362 = V_293 ;
if ( V_361 -> V_151 [ V_293 ] . V_305 )
V_363 = V_293 ;
}
if ( V_362 == V_363 ) {
if ( V_361 -> V_342 && ! V_360 -> V_342 )
return V_361 ;
else
return V_360 ;
} else if ( V_362 > V_363 ) {
return V_360 ;
} else {
return V_361 ;
}
}
static unsigned int F_149 ( struct V_1 * V_2 ,
const struct V_345 * V_364 ,
const struct V_345 * V_365 )
{
unsigned int V_366 = 0 ;
enum V_65 V_65 ;
int V_343 ;
F_150 (pipe) {
if ( V_364 -> V_356 [ V_65 ] != V_365 -> V_356 [ V_65 ] ) {
V_366 |= F_151 ( V_65 ) ;
V_366 |= V_367 ;
}
if ( V_364 -> V_357 [ V_65 ] != V_365 -> V_357 [ V_65 ] ) {
V_366 |= F_152 ( V_65 ) ;
V_366 |= V_367 ;
}
}
if ( V_364 -> V_347 != V_365 -> V_347 ) {
V_366 |= V_368 ;
V_366 |= V_367 ;
}
if ( V_364 -> V_344 != V_365 -> V_344 ) {
V_366 |= V_369 ;
V_366 |= V_367 ;
}
if ( V_366 & V_367 )
return V_366 ;
for ( V_343 = 1 ; V_343 <= 3 ; V_343 ++ ) {
if ( V_364 -> V_343 [ V_343 - 1 ] != V_365 -> V_343 [ V_343 - 1 ] ||
V_364 -> V_354 [ V_343 - 1 ] != V_365 -> V_354 [ V_343 - 1 ] )
break;
}
for (; V_343 <= 3 ; V_343 ++ )
V_366 |= F_153 ( V_343 ) ;
return V_366 ;
}
static bool F_154 ( struct V_3 * V_4 ,
unsigned int V_366 )
{
struct V_345 * V_370 = & V_4 -> V_151 . V_371 ;
bool V_330 = false ;
if ( V_366 & F_153 ( 3 ) && V_370 -> V_343 [ 2 ] & V_351 ) {
V_370 -> V_343 [ 2 ] &= ~ V_351 ;
F_3 ( V_372 , V_370 -> V_343 [ 2 ] ) ;
V_330 = true ;
}
if ( V_366 & F_153 ( 2 ) && V_370 -> V_343 [ 1 ] & V_351 ) {
V_370 -> V_343 [ 1 ] &= ~ V_351 ;
F_3 ( V_373 , V_370 -> V_343 [ 1 ] ) ;
V_330 = true ;
}
if ( V_366 & F_153 ( 1 ) && V_370 -> V_343 [ 0 ] & V_351 ) {
V_370 -> V_343 [ 0 ] &= ~ V_351 ;
F_3 ( V_374 , V_370 -> V_343 [ 0 ] ) ;
V_330 = true ;
}
return V_330 ;
}
static void F_155 ( struct V_3 * V_4 ,
struct V_345 * V_346 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_345 * V_370 = & V_4 -> V_151 . V_371 ;
unsigned int V_366 ;
T_3 V_375 ;
V_366 = F_149 ( V_2 , V_370 , V_346 ) ;
if ( ! V_366 )
return;
F_154 ( V_4 , V_366 ) ;
if ( V_366 & F_152 ( V_233 ) )
F_3 ( V_376 , V_346 -> V_357 [ 0 ] ) ;
if ( V_366 & F_152 ( V_236 ) )
F_3 ( V_377 , V_346 -> V_357 [ 1 ] ) ;
if ( V_366 & F_152 ( V_378 ) )
F_3 ( V_379 , V_346 -> V_357 [ 2 ] ) ;
if ( V_366 & F_151 ( V_233 ) )
F_3 ( F_156 ( V_233 ) , V_346 -> V_356 [ 0 ] ) ;
if ( V_366 & F_151 ( V_236 ) )
F_3 ( F_156 ( V_236 ) , V_346 -> V_356 [ 1 ] ) ;
if ( V_366 & F_151 ( V_378 ) )
F_3 ( F_156 ( V_378 ) , V_346 -> V_356 [ 2 ] ) ;
if ( V_366 & V_369 ) {
if ( F_125 ( V_2 ) || F_126 ( V_2 ) ) {
V_375 = F_2 ( V_380 ) ;
if ( V_346 -> V_344 == V_338 )
V_375 &= ~ V_381 ;
else
V_375 |= V_381 ;
F_3 ( V_380 , V_375 ) ;
} else {
V_375 = F_2 ( V_382 ) ;
if ( V_346 -> V_344 == V_338 )
V_375 &= ~ V_383 ;
else
V_375 |= V_383 ;
F_3 ( V_382 , V_375 ) ;
}
}
if ( V_366 & V_368 ) {
V_375 = F_2 ( V_384 ) ;
if ( V_346 -> V_347 )
V_375 &= ~ V_385 ;
else
V_375 |= V_385 ;
F_3 ( V_384 , V_375 ) ;
}
if ( V_366 & F_153 ( 1 ) &&
V_370 -> V_354 [ 0 ] != V_346 -> V_354 [ 0 ] )
F_3 ( V_386 , V_346 -> V_354 [ 0 ] ) ;
if ( F_56 ( V_2 ) -> V_102 >= 7 ) {
if ( V_366 & F_153 ( 2 ) && V_370 -> V_354 [ 1 ] != V_346 -> V_354 [ 1 ] )
F_3 ( V_387 , V_346 -> V_354 [ 1 ] ) ;
if ( V_366 & F_153 ( 3 ) && V_370 -> V_354 [ 2 ] != V_346 -> V_354 [ 2 ] )
F_3 ( V_388 , V_346 -> V_354 [ 2 ] ) ;
}
if ( V_366 & F_153 ( 1 ) && V_370 -> V_343 [ 0 ] != V_346 -> V_343 [ 0 ] )
F_3 ( V_374 , V_346 -> V_343 [ 0 ] ) ;
if ( V_366 & F_153 ( 2 ) && V_370 -> V_343 [ 1 ] != V_346 -> V_343 [ 1 ] )
F_3 ( V_373 , V_346 -> V_343 [ 1 ] ) ;
if ( V_366 & F_153 ( 3 ) && V_370 -> V_343 [ 2 ] != V_346 -> V_343 [ 2 ] )
F_3 ( V_372 , V_346 -> V_343 [ 2 ] ) ;
V_4 -> V_151 . V_371 = * V_346 ;
}
static bool F_157 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_154 ( V_4 , V_367 ) ;
}
static void F_158 ( struct V_11 * V_12 )
{
struct V_20 * V_20 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_302 F_78 ;
struct V_283 V_284 = {} ;
struct V_345 V_346 = {} ;
enum V_296 V_344 ;
struct V_333 V_336 = {} ;
struct V_333 V_389 = {} , V_390 = {} , * V_391 ;
struct V_295 V_96 = {} ;
F_136 ( V_12 , & V_284 ) ;
F_141 ( V_12 , & V_284 , & V_336 ) ;
if ( ! memcmp ( & V_20 -> V_151 . V_289 , & V_336 , sizeof( V_336 ) ) )
return;
V_20 -> V_151 . V_289 = V_336 ;
F_139 ( V_2 , & V_96 ) ;
F_114 ( V_2 , 1 , & V_96 , V_338 , & F_78 ) ;
F_143 ( V_2 , & V_96 , & F_78 , & V_389 ) ;
if ( F_56 ( V_2 ) -> V_102 >= 7 &&
V_96 . V_299 == 1 && V_96 . V_298 ) {
F_114 ( V_2 , 1 , & V_96 , V_301 , & F_78 ) ;
F_143 ( V_2 , & V_96 , & F_78 , & V_390 ) ;
V_391 = F_148 ( V_2 , & V_389 , & V_390 ) ;
} else {
V_391 = & V_389 ;
}
V_344 = ( V_391 == & V_389 ) ?
V_338 : V_301 ;
F_146 ( V_2 , V_391 , V_344 , & V_346 ) ;
F_155 ( V_4 , & V_346 ) ;
}
static void F_159 ( struct V_331 * V_32 ,
struct V_11 * V_12 ,
T_3 V_392 , int V_153 ,
bool V_161 , bool V_337 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_332 * V_332 = F_138 ( V_32 ) ;
V_332 -> V_151 . V_161 = V_161 ;
V_332 -> V_151 . V_337 = V_337 ;
V_332 -> V_151 . V_281 = V_392 ;
V_332 -> V_151 . V_277 = V_153 ;
if ( F_32 ( V_2 ) && V_337 && F_157 ( V_2 ) )
F_160 ( V_2 , V_332 -> V_65 ) ;
F_158 ( V_12 ) ;
}
static void F_161 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_345 * V_371 = & V_4 -> V_151 . V_371 ;
struct V_20 * V_20 = F_8 ( V_12 ) ;
struct V_333 * V_289 = & V_20 -> V_151 . V_289 ;
enum V_65 V_65 = V_20 -> V_65 ;
static const unsigned int V_393 [] = {
[ V_233 ] = V_376 ,
[ V_236 ] = V_377 ,
[ V_378 ] = V_379 ,
} ;
V_371 -> V_357 [ V_65 ] = F_2 ( V_393 [ V_65 ] ) ;
if ( F_125 ( V_2 ) || F_126 ( V_2 ) )
V_371 -> V_356 [ V_65 ] = F_2 ( F_156 ( V_65 ) ) ;
V_289 -> V_334 = F_54 ( V_12 ) ;
if ( V_289 -> V_334 ) {
T_1 V_114 = V_371 -> V_357 [ V_65 ] ;
V_289 -> V_151 [ 0 ] . V_305 = true ;
V_289 -> V_151 [ 0 ] . V_282 = ( V_114 & V_394 ) >> V_358 ;
V_289 -> V_151 [ 0 ] . V_306 = ( V_114 & V_395 ) >> V_359 ;
V_289 -> V_151 [ 0 ] . V_307 = V_114 & V_396 ;
V_289 -> V_314 = V_371 -> V_356 [ V_65 ] ;
} else {
int V_293 , V_329 = F_130 ( V_2 ) ;
for ( V_293 = 0 ; V_293 <= V_329 ; V_293 ++ )
V_289 -> V_151 [ V_293 ] . V_305 = true ;
}
}
void F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_345 * V_371 = & V_4 -> V_151 . V_371 ;
struct V_11 * V_12 ;
F_53 (dev, crtc)
F_161 ( V_12 ) ;
V_371 -> V_343 [ 0 ] = F_2 ( V_374 ) ;
V_371 -> V_343 [ 1 ] = F_2 ( V_373 ) ;
V_371 -> V_343 [ 2 ] = F_2 ( V_372 ) ;
V_371 -> V_354 [ 0 ] = F_2 ( V_386 ) ;
if ( F_56 ( V_2 ) -> V_102 >= 7 ) {
V_371 -> V_354 [ 1 ] = F_2 ( V_387 ) ;
V_371 -> V_354 [ 2 ] = F_2 ( V_388 ) ;
}
if ( F_125 ( V_2 ) || F_126 ( V_2 ) )
V_371 -> V_344 = ( F_2 ( V_380 ) & V_381 ) ?
V_301 : V_338 ;
else if ( F_32 ( V_2 ) )
V_371 -> V_344 = ( F_2 ( V_382 ) & V_383 ) ?
V_301 : V_338 ;
V_371 -> V_347 =
! ( F_2 ( V_384 ) & V_385 ) ;
}
void F_163 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_2 -> V_5 ;
if ( V_4 -> V_67 . V_397 )
V_4 -> V_67 . V_397 ( V_12 ) ;
}
void F_164 ( struct V_331 * V_32 ,
struct V_11 * V_12 ,
T_3 V_392 , int V_153 ,
bool V_161 , bool V_337 )
{
struct V_3 * V_4 = V_32 -> V_2 -> V_5 ;
if ( V_4 -> V_67 . V_398 )
V_4 -> V_67 . V_398 ( V_32 , V_12 , V_392 ,
V_153 , V_161 , V_337 ) ;
}
static struct V_18 *
F_165 ( struct V_1 * V_2 )
{
struct V_18 * V_399 ;
int V_278 ;
F_147 ( ! F_166 ( & V_2 -> V_73 ) ) ;
V_399 = F_167 ( V_2 , 4096 ) ;
if ( ! V_399 ) {
F_168 ( L_56 ) ;
return NULL ;
}
V_278 = F_169 ( V_399 , 4096 , 0 ) ;
if ( V_278 ) {
F_45 ( L_57 , V_278 ) ;
goto V_400;
}
V_278 = F_170 ( V_399 , 1 ) ;
if ( V_278 ) {
F_45 ( L_58 , V_278 ) ;
goto V_401;
}
return V_399 ;
V_401:
F_171 ( V_399 ) ;
V_400:
F_172 ( & V_399 -> V_77 ) ;
return NULL ;
}
bool F_173 ( struct V_1 * V_2 , T_7 V_375 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_402 ;
F_174 ( & V_403 ) ;
V_402 = F_63 ( V_404 ) ;
if ( V_402 & V_405 ) {
F_168 ( L_59 ) ;
return false ;
}
V_402 = ( V_406 << V_407 ) |
( V_375 << V_408 ) | V_409 ;
F_175 ( V_404 , V_402 ) ;
F_176 ( V_404 ) ;
V_402 |= V_405 ;
F_175 ( V_404 , V_402 ) ;
return true ;
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_410 = F_2 ( V_411 ) ;
T_7 V_412 , V_413 , V_414 , V_415 ;
F_178 ( & V_403 ) ;
F_175 ( V_416 , F_2 ( V_416 ) | V_417 ) ;
F_175 ( V_418 , F_2 ( V_418 ) | V_419 ) ;
F_3 ( V_420 , 100000 ) ;
F_3 ( V_421 , 100000 ) ;
F_3 ( V_422 , 90000 ) ;
F_3 ( V_423 , 80000 ) ;
F_3 ( V_424 , 1 ) ;
V_412 = ( V_410 & V_425 ) >> V_426 ;
V_413 = ( V_410 & V_427 ) ;
V_414 = ( V_410 & V_428 ) >>
V_429 ;
V_415 = ( F_2 ( V_430 + ( V_414 * 4 ) ) & V_431 ) >>
V_432 ;
V_4 -> V_134 . V_412 = V_412 ;
V_4 -> V_134 . V_414 = V_414 ;
V_4 -> V_134 . V_433 = V_414 ;
V_4 -> V_134 . V_434 = V_413 ;
V_4 -> V_134 . V_435 = V_414 ;
F_64 ( L_60 ,
V_412 , V_413 , V_414 ) ;
F_3 ( V_436 , V_437 | V_438 ) ;
F_3 ( V_439 , V_415 ) ;
F_22 ( V_439 ) ;
V_410 |= V_440 ;
F_3 ( V_411 , V_410 ) ;
if ( F_179 ( ( F_2 ( V_404 ) & V_405 ) == 0 , 10 ) )
F_45 ( L_61 ) ;
F_180 ( 1 ) ;
F_173 ( V_2 , V_414 ) ;
V_4 -> V_134 . V_441 = F_2 ( 0x112e4 ) + F_2 ( 0x112e8 ) +
F_2 ( 0x112e0 ) ;
V_4 -> V_134 . V_442 = F_181 ( V_443 ) ;
V_4 -> V_134 . V_444 = F_2 ( 0x112f4 ) ;
F_182 ( & V_4 -> V_134 . V_445 ) ;
F_183 ( & V_403 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_402 ;
F_178 ( & V_403 ) ;
V_402 = F_63 ( V_404 ) ;
F_3 ( V_436 , F_2 ( V_436 ) & ~ V_438 ) ;
F_3 ( V_446 , V_447 ) ;
F_3 ( V_448 , F_2 ( V_448 ) & ~ V_449 ) ;
F_3 ( V_450 , V_449 ) ;
F_3 ( V_451 , F_2 ( V_451 ) | V_449 ) ;
F_173 ( V_2 , V_4 -> V_134 . V_414 ) ;
F_180 ( 1 ) ;
V_402 |= V_405 ;
F_3 ( V_404 , V_402 ) ;
F_180 ( 1 ) ;
F_183 ( & V_403 ) ;
}
static T_1 F_185 ( struct V_3 * V_4 , T_7 V_375 )
{
T_1 V_452 ;
V_452 = V_4 -> V_453 . V_454 << 24 ;
if ( V_375 <= V_4 -> V_453 . V_455 )
V_452 |= V_4 -> V_453 . V_455 << 16 ;
return V_452 ;
}
static void F_186 ( struct V_3 * V_4 , T_7 V_375 )
{
int V_456 ;
V_456 = V_4 -> V_453 . V_457 ;
switch ( V_4 -> V_453 . V_457 ) {
case V_458 :
if ( V_375 > V_4 -> V_453 . V_459 + 1 && V_375 > V_4 -> V_453 . V_460 )
V_456 = V_461 ;
break;
case V_461 :
if ( V_375 <= V_4 -> V_453 . V_459 && V_375 < V_4 -> V_453 . V_460 )
V_456 = V_458 ;
else if ( V_375 >= V_4 -> V_453 . V_462 && V_375 > V_4 -> V_453 . V_460 )
V_456 = V_463 ;
break;
case V_463 :
if ( V_375 < ( V_4 -> V_453 . V_464 + V_4 -> V_453 . V_462 ) > > 1 && V_375 < V_4 -> V_453 . V_460 )
V_456 = V_461 ;
break;
}
if ( V_375 == V_4 -> V_453 . V_455 )
V_456 = V_458 ;
if ( V_375 == V_4 -> V_453 . V_454 )
V_456 = V_463 ;
if ( V_456 == V_4 -> V_453 . V_457 )
return;
switch ( V_456 ) {
case V_458 :
F_3 ( V_465 , 12500 ) ;
F_3 ( V_466 , 11800 ) ;
F_3 ( V_467 , 25000 ) ;
F_3 ( V_468 , 21250 ) ;
F_3 ( V_469 ,
V_470 |
V_471 |
V_472 |
V_473 |
V_474 |
V_475 ) ;
break;
case V_461 :
F_3 ( V_465 , 10250 ) ;
F_3 ( V_466 , 9225 ) ;
F_3 ( V_467 , 25000 ) ;
F_3 ( V_468 , 18750 ) ;
F_3 ( V_469 ,
V_470 |
V_471 |
V_472 |
V_473 |
V_474 |
V_475 ) ;
break;
case V_463 :
F_3 ( V_465 , 8000 ) ;
F_3 ( V_466 , 6800 ) ;
F_3 ( V_467 , 25000 ) ;
F_3 ( V_468 , 15000 ) ;
F_3 ( V_469 ,
V_470 |
V_471 |
V_472 |
V_473 |
V_474 |
V_475 ) ;
break;
}
V_4 -> V_453 . V_457 = V_456 ;
V_4 -> V_453 . V_476 = 0 ;
}
static T_1 F_187 ( struct V_3 * V_4 , T_7 V_375 )
{
T_1 V_477 = 0 ;
if ( V_375 > V_4 -> V_453 . V_455 )
V_477 |= V_478 | V_479 ;
if ( V_375 < V_4 -> V_453 . V_454 )
V_477 |= V_480 ;
if ( F_56 ( V_4 -> V_2 ) -> V_102 <= 7 && ! F_125 ( V_4 -> V_2 ) )
V_477 |= V_481 ;
if ( F_188 ( V_4 -> V_2 ) )
V_477 |= V_482 ;
return ~ V_477 ;
}
void F_189 ( struct V_1 * V_2 , T_7 V_375 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_147 ( ! F_166 ( & V_4 -> V_453 . V_483 ) ) ;
F_147 ( V_375 > V_4 -> V_453 . V_454 ) ;
F_147 ( V_375 < V_4 -> V_453 . V_455 ) ;
if ( V_375 != V_4 -> V_453 . V_460 ) {
F_186 ( V_4 , V_375 ) ;
if ( F_125 ( V_2 ) || F_126 ( V_2 ) )
F_3 ( V_484 ,
F_190 ( V_375 ) ) ;
else
F_3 ( V_484 ,
F_191 ( V_375 ) |
F_192 ( 0 ) |
V_485 ) ;
}
F_3 ( V_486 , F_185 ( V_4 , V_375 ) ) ;
F_3 ( V_487 , F_187 ( V_4 , V_375 ) ) ;
F_22 ( V_484 ) ;
V_4 -> V_453 . V_460 = V_375 ;
F_193 ( V_375 * 50 ) ;
}
static void F_194 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_2 -> V_488 -> V_489 >= 0xd ) {
F_195 ( V_4 -> V_2 , V_4 -> V_453 . V_455 ) ;
return;
}
if ( V_4 -> V_453 . V_460 <= V_4 -> V_453 . V_455 )
return;
F_3 ( V_487 , 0xffffffff ) ;
F_196 ( V_4 , true ) ;
V_4 -> V_453 . V_460 = V_4 -> V_453 . V_455 ;
F_197 ( V_4 , V_490 ,
V_4 -> V_453 . V_455 ) ;
if ( F_4 ( ( ( F_198 ( V_4 , V_491 ) )
& V_492 ) == 0 , 5 ) )
F_45 ( L_62 ) ;
F_196 ( V_4 , false ) ;
F_3 ( V_487 ,
F_187 ( V_4 , V_4 -> V_453 . V_460 ) ) ;
}
void F_199 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_453 . V_483 ) ;
if ( V_4 -> V_453 . V_161 ) {
if ( F_200 ( V_2 ) )
F_194 ( V_4 ) ;
else
F_189 ( V_4 -> V_2 , V_4 -> V_453 . V_455 ) ;
V_4 -> V_453 . V_476 = 0 ;
}
F_39 ( & V_4 -> V_453 . V_483 ) ;
}
void F_201 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_453 . V_483 ) ;
if ( V_4 -> V_453 . V_161 ) {
if ( F_200 ( V_2 ) )
F_195 ( V_4 -> V_2 , V_4 -> V_453 . V_454 ) ;
else
F_189 ( V_4 -> V_2 , V_4 -> V_453 . V_454 ) ;
V_4 -> V_453 . V_476 = 0 ;
}
F_39 ( & V_4 -> V_453 . V_483 ) ;
}
void F_195 ( struct V_1 * V_2 , T_7 V_375 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_147 ( ! F_166 ( & V_4 -> V_453 . V_483 ) ) ;
F_147 ( V_375 > V_4 -> V_453 . V_454 ) ;
F_147 ( V_375 < V_4 -> V_453 . V_455 ) ;
F_64 ( L_63 ,
F_202 ( V_4 , V_4 -> V_453 . V_460 ) ,
V_4 -> V_453 . V_460 ,
F_202 ( V_4 , V_375 ) , V_375 ) ;
if ( V_375 != V_4 -> V_453 . V_460 )
F_197 ( V_4 , V_490 , V_375 ) ;
F_3 ( V_487 , F_187 ( V_4 , V_375 ) ) ;
V_4 -> V_453 . V_460 = V_375 ;
F_193 ( F_202 ( V_4 , V_375 ) ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_487 , ~ V_482 ) ;
F_3 ( F_204 ( 2 ) , F_2 ( F_204 ( 2 ) ) &
~ V_4 -> V_493 ) ;
F_178 ( & V_4 -> V_494 ) ;
V_4 -> V_453 . V_495 = 0 ;
F_183 ( & V_4 -> V_494 ) ;
F_3 ( F_205 ( 2 ) , V_4 -> V_493 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_487 , 0xffffffff ) ;
F_3 ( V_496 , F_2 ( V_496 ) &
~ V_4 -> V_493 ) ;
F_178 ( & V_4 -> V_494 ) ;
V_4 -> V_453 . V_495 = 0 ;
F_183 ( & V_4 -> V_494 ) ;
F_3 ( V_497 , V_4 -> V_493 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_498 , 0 ) ;
F_3 ( V_484 , 1 << 31 ) ;
if ( F_126 ( V_2 ) )
F_203 ( V_2 ) ;
else
F_206 ( V_2 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_498 , 0 ) ;
F_206 ( V_2 ) ;
}
static void F_209 ( struct V_1 * V_2 , T_1 V_313 )
{
if ( F_200 ( V_2 ) ) {
if ( V_313 & ( V_499 | F_210 ( 1 ) ) )
V_313 = V_500 ;
else
V_313 = 0 ;
}
F_211 ( L_64 ,
( V_313 & V_500 ) ? L_65 : L_66 ,
( V_313 & V_501 ) ? L_65 : L_66 ,
( V_313 & V_502 ) ? L_65 : L_66 ) ;
}
static int F_212 ( const struct V_1 * V_2 , int V_503 )
{
if ( F_56 ( V_2 ) -> V_102 < 5 )
return 0 ;
if ( F_56 ( V_2 ) -> V_102 == 5 && ! F_213 ( V_2 ) )
return 0 ;
if ( V_503 >= 0 ) {
int V_477 ;
if ( F_56 ( V_2 ) -> V_102 == 6 || F_32 ( V_2 ) )
V_477 = V_504 | V_505 |
V_506 ;
else
V_477 = V_504 ;
if ( ( V_503 & V_477 ) != V_503 )
F_211 ( L_67 ,
V_503 & V_477 , V_503 , V_477 ) ;
return V_503 & V_477 ;
}
if ( F_56 ( V_2 ) -> V_102 == 5 )
return 0 ;
if ( F_32 ( V_2 ) )
return ( V_504 | V_505 ) ;
return V_504 ;
}
int F_214 ( const struct V_1 * V_2 )
{
return V_89 . V_503 ;
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_178 ( & V_4 -> V_494 ) ;
F_147 ( V_4 -> V_453 . V_495 ) ;
F_216 ( V_4 , V_4 -> V_493 ) ;
F_3 ( F_205 ( 2 ) , V_4 -> V_493 ) ;
F_183 ( & V_4 -> V_494 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_178 ( & V_4 -> V_494 ) ;
F_147 ( V_4 -> V_453 . V_495 ) ;
F_218 ( V_4 , V_4 -> V_493 ) ;
F_3 ( V_497 , V_4 -> V_493 ) ;
F_183 ( & V_4 -> V_494 ) ;
}
static void F_219 ( struct V_3 * V_4 , T_1 V_507 )
{
V_4 -> V_453 . V_460 = 0 ;
V_4 -> V_453 . V_464 = ( V_507 >> 8 ) & 0xff ;
V_4 -> V_453 . V_462 = ( V_507 >> 0 ) & 0xff ;
V_4 -> V_453 . V_508 = ( V_507 >> 16 ) & 0xff ;
V_4 -> V_453 . V_459 = V_4 -> V_453 . V_464 ;
V_4 -> V_453 . V_509 = V_4 -> V_453 . V_462 ;
if ( V_4 -> V_453 . V_454 == 0 )
V_4 -> V_453 . V_454 = V_4 -> V_453 . V_509 ;
if ( V_4 -> V_453 . V_455 == 0 )
V_4 -> V_453 . V_455 = V_4 -> V_453 . V_508 ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_510 * V_511 ;
T_3 V_512 = 0 , V_507 ;
int V_513 ;
F_3 ( V_514 , 0 ) ;
F_21 ( V_4 , V_515 ) ;
F_3 ( V_498 , 0 ) ;
V_507 = F_2 ( V_516 ) ;
F_219 ( V_4 , V_507 ) ;
F_3 ( V_517 , 40 << 16 ) ;
F_3 ( V_518 , 125000 ) ;
F_3 ( V_519 , 25 ) ;
F_221 (ring, dev_priv, unused)
F_3 ( F_222 ( V_511 -> V_520 ) , 10 ) ;
F_3 ( V_521 , 0 ) ;
F_3 ( V_522 , 50000 ) ;
if ( F_214 ( V_2 ) & V_504 )
V_512 = V_500 ;
F_209 ( V_2 , V_512 ) ;
F_3 ( V_498 , V_523 |
F_210 ( 1 ) |
V_512 ) ;
F_3 ( V_484 ,
F_190 ( V_4 -> V_453 . V_464 ) ) ;
F_3 ( V_524 ,
F_190 ( V_4 -> V_453 . V_464 ) ) ;
F_3 ( V_525 , 100000000 / 128 ) ;
F_3 ( V_486 ,
V_4 -> V_453 . V_454 << 24 |
V_4 -> V_453 . V_455 << 16 ) ;
F_3 ( V_466 , 7600000 / 128 ) ;
F_3 ( V_468 , 31300000 / 128 ) ;
F_3 ( V_465 , 66000 ) ;
F_3 ( V_467 , 350000 ) ;
F_3 ( V_526 , 10 ) ;
F_3 ( V_469 ,
V_470 |
V_471 |
V_472 |
V_473 |
V_474 |
V_475 ) ;
F_189 ( V_2 , ( F_2 ( V_527 ) & 0xff00 ) >> 8 ) ;
F_215 ( V_2 ) ;
F_23 ( V_4 , V_515 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_510 * V_511 ;
T_1 V_507 ;
T_1 V_528 ;
T_1 V_529 , V_530 = 0 , V_512 = 0 ;
T_1 V_531 ;
int V_532 ;
int V_22 , V_278 ;
F_147 ( ! F_166 ( & V_4 -> V_453 . V_483 ) ) ;
F_3 ( V_514 , 0 ) ;
if ( ( V_531 = F_2 ( V_533 ) ) ) {
F_45 ( L_68 , V_531 ) ;
F_3 ( V_533 , V_531 ) ;
}
F_21 ( V_4 , V_515 ) ;
V_507 = F_2 ( V_516 ) ;
V_528 = F_2 ( V_527 ) ;
F_219 ( V_4 , V_507 ) ;
F_3 ( V_498 , 0 ) ;
F_3 ( V_534 , 1000 << 16 ) ;
F_3 ( V_517 , 40 << 16 | 30 ) ;
F_3 ( V_535 , 30 ) ;
F_3 ( V_518 , 125000 ) ;
F_3 ( V_519 , 25 ) ;
F_221 (ring, dev_priv, i)
F_3 ( F_222 ( V_511 -> V_520 ) , 10 ) ;
F_3 ( V_521 , 0 ) ;
F_3 ( V_536 , 1000 ) ;
if ( F_32 ( V_2 ) )
F_3 ( V_522 , 125000 ) ;
else
F_3 ( V_522 , 50000 ) ;
F_3 ( V_537 , 150000 ) ;
F_3 ( V_538 , 64000 ) ;
V_532 = F_214 ( V_4 -> V_2 ) ;
if ( V_532 & V_504 )
V_512 |= V_500 ;
if ( ! F_125 ( V_2 ) ) {
if ( V_532 & V_505 )
V_512 |= V_501 ;
if ( V_532 & V_506 )
V_512 |= V_502 ;
}
F_209 ( V_2 , V_512 ) ;
F_3 ( V_498 ,
V_512 |
F_210 ( 1 ) |
V_523 ) ;
F_3 ( V_525 , 50000 ) ;
F_3 ( V_526 , 10 ) ;
V_278 = F_224 ( V_4 , V_539 , 0 ) ;
if ( V_278 )
F_64 ( L_69 ) ;
V_278 = F_225 ( V_4 , V_540 , & V_530 ) ;
if ( ! V_278 && ( V_530 & ( 1 << 31 ) ) ) {
F_64 ( L_70 ,
( V_4 -> V_453 . V_454 & 0xff ) * 50 ,
( V_530 & 0xff ) * 50 ) ;
V_4 -> V_453 . V_509 = V_530 & 0xff ;
}
V_4 -> V_453 . V_457 = V_463 ;
F_189 ( V_4 -> V_2 , V_4 -> V_453 . V_455 ) ;
F_217 ( V_2 ) ;
V_529 = 0 ;
V_278 = F_225 ( V_4 , V_541 , & V_529 ) ;
if ( F_27 ( V_2 ) && V_278 ) {
F_64 ( L_71 ) ;
} else if ( F_27 ( V_2 ) && ( F_226 ( V_529 & 0xff ) < 450 ) ) {
F_64 ( L_72 ,
F_226 ( V_529 & 0xff ) , 450 ) ;
V_529 &= 0xffff00 ;
V_529 |= F_227 ( 450 ) ;
V_278 = F_224 ( V_4 , V_542 , V_529 ) ;
if ( V_278 )
F_45 ( L_73 ) ;
}
F_23 ( V_4 , V_515 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_508 = 15 ;
unsigned int V_543 ;
unsigned int V_544 , V_545 ;
int V_546 = 180 ;
struct V_547 * V_548 ;
F_147 ( ! F_166 ( & V_4 -> V_453 . V_483 ) ) ;
V_548 = F_229 ( 0 ) ;
if ( V_548 ) {
V_544 = V_548 -> V_549 . V_509 ;
F_230 ( V_548 ) ;
} else {
V_544 = V_550 ;
}
V_544 /= 1000 ;
V_545 = F_2 ( V_551 ) & 0xf ;
V_545 = F_231 ( V_545 , 8 , 3 ) ;
for ( V_543 = V_4 -> V_453 . V_454 ; V_543 >= V_4 -> V_453 . V_455 ;
V_543 -- ) {
int V_552 = V_4 -> V_453 . V_454 - V_543 ;
unsigned int V_553 = 0 , V_554 = 0 ;
if ( F_56 ( V_2 ) -> V_102 >= 8 ) {
V_554 = F_78 ( V_545 , V_543 ) ;
} else if ( F_125 ( V_2 ) ) {
V_554 = F_231 ( V_543 , 5 , 4 ) ;
V_554 = F_78 ( V_545 , V_554 ) ;
} else {
if ( V_543 < V_508 )
V_553 = 800 ;
else
V_553 = V_544 - ( ( V_552 * V_546 ) / 2 ) ;
V_553 = F_120 ( V_553 , 100 ) ;
}
F_224 ( V_4 ,
V_539 ,
V_553 << V_555 |
V_554 << V_556 |
V_543 ) ;
}
}
void F_232 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_56 ( V_2 ) -> V_102 < 6 || F_200 ( V_2 ) )
return;
F_38 ( & V_4 -> V_453 . V_483 ) ;
F_228 ( V_2 ) ;
F_39 ( & V_4 -> V_453 . V_483 ) ;
}
int F_233 ( struct V_3 * V_4 )
{
T_1 V_375 , V_557 ;
V_375 = F_234 ( V_4 , V_558 ) ;
V_557 = ( V_375 & V_559 ) >> V_560 ;
V_557 = F_117 ( T_1 , V_557 , 0xea ) ;
return V_557 ;
}
static int F_235 ( struct V_3 * V_4 )
{
T_1 V_375 , V_561 ;
V_375 = F_234 ( V_4 , V_562 ) ;
V_561 = ( V_375 & V_563 ) >> V_564 ;
V_375 = F_234 ( V_4 , V_565 ) ;
V_561 |= ( V_375 & V_566 ) << 5 ;
return V_561 ;
}
int F_236 ( struct V_3 * V_4 )
{
return F_198 ( V_4 , V_567 ) & 0xff ;
}
static void F_237 ( struct V_3 * V_4 )
{
unsigned long V_568 = F_2 ( V_569 ) & ~ 4095 ;
F_147 ( V_568 != V_4 -> V_570 . V_571 +
V_4 -> V_572 -> V_573 -> V_574 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_575 ;
unsigned long V_576 ;
T_1 V_577 ;
int V_578 = 24 * 1024 ;
F_147 ( ! F_166 ( & V_2 -> V_73 ) ) ;
V_577 = F_2 ( V_569 ) ;
if ( V_577 ) {
int V_579 ;
V_579 = ( V_577 & ( ~ 4095 ) ) - V_4 -> V_570 . V_571 ;
V_575 = F_239 ( V_4 -> V_2 ,
V_579 ,
V_580 ,
V_578 ) ;
goto V_581;
}
V_575 = F_240 ( V_2 , V_578 ) ;
if ( ! V_575 ) {
F_168 ( L_74 ) ;
return;
}
V_576 = V_4 -> V_570 . V_571 + V_575 -> V_573 -> V_574 ;
F_3 ( V_569 , V_576 ) ;
V_581:
V_4 -> V_572 = V_575 ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_147 ( ! V_4 -> V_572 ) )
return;
F_172 ( & V_4 -> V_572 -> V_77 ) ;
V_4 -> V_572 = NULL ;
}
static void F_242 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_238 ( V_2 ) ;
F_38 ( & V_4 -> V_453 . V_483 ) ;
V_4 -> V_453 . V_509 = F_233 ( V_4 ) ;
V_4 -> V_453 . V_462 = V_4 -> V_453 . V_509 ;
F_64 ( L_75 ,
F_202 ( V_4 , V_4 -> V_453 . V_509 ) ,
V_4 -> V_453 . V_509 ) ;
V_4 -> V_453 . V_459 = F_235 ( V_4 ) ;
F_64 ( L_76 ,
F_202 ( V_4 , V_4 -> V_453 . V_459 ) ,
V_4 -> V_453 . V_459 ) ;
V_4 -> V_453 . V_508 = F_236 ( V_4 ) ;
F_64 ( L_77 ,
F_202 ( V_4 , V_4 -> V_453 . V_508 ) ,
V_4 -> V_453 . V_508 ) ;
if ( V_4 -> V_453 . V_454 == 0 )
V_4 -> V_453 . V_454 = V_4 -> V_453 . V_509 ;
if ( V_4 -> V_453 . V_455 == 0 )
V_4 -> V_453 . V_455 = V_4 -> V_453 . V_508 ;
F_39 ( & V_4 -> V_453 . V_483 ) ;
}
static void F_243 ( struct V_1 * V_2 )
{
F_241 ( V_2 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_510 * V_511 ;
T_1 V_531 , V_375 , V_532 = 0 ;
int V_22 ;
F_147 ( ! F_166 ( & V_4 -> V_453 . V_483 ) ) ;
F_237 ( V_4 ) ;
if ( ( V_531 = F_2 ( V_533 ) ) ) {
F_64 ( L_68 ,
V_531 ) ;
F_3 ( V_533 , V_531 ) ;
}
F_21 ( V_4 , V_515 ) ;
F_3 ( V_466 , 59400 ) ;
F_3 ( V_468 , 245000 ) ;
F_3 ( V_465 , 66000 ) ;
F_3 ( V_467 , 350000 ) ;
F_3 ( V_526 , 10 ) ;
F_3 ( V_469 ,
V_470 |
V_471 |
V_472 |
V_473 |
V_474 |
V_582 ) ;
F_3 ( V_517 , 0x00280000 ) ;
F_3 ( V_518 , 125000 ) ;
F_3 ( V_519 , 25 ) ;
F_221 (ring, dev_priv, i)
F_3 ( F_222 ( V_511 -> V_520 ) , 10 ) ;
F_3 ( V_522 , 0x557 ) ;
F_3 ( V_583 ,
F_95 ( V_584 |
V_585 |
V_586 ) ) ;
if ( F_214 ( V_2 ) & V_504 )
V_532 = V_499 | V_587 ;
F_209 ( V_2 , V_532 ) ;
F_3 ( V_498 , V_532 ) ;
V_375 = F_198 ( V_4 , V_491 ) ;
F_64 ( L_78 , V_375 & 0x10 ? L_79 : L_80 ) ;
F_64 ( L_81 , V_375 ) ;
V_4 -> V_453 . V_460 = ( V_375 >> 8 ) & 0xff ;
F_64 ( L_82 ,
F_202 ( V_4 , V_4 -> V_453 . V_460 ) ,
V_4 -> V_453 . V_460 ) ;
F_64 ( L_83 ,
F_202 ( V_4 , V_4 -> V_453 . V_459 ) ,
V_4 -> V_453 . V_459 ) ;
F_195 ( V_4 -> V_2 , V_4 -> V_453 . V_459 ) ;
F_217 ( V_2 ) ;
F_23 ( V_4 , V_515 ) ;
}
void F_245 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_134 . V_588 ) {
F_171 ( V_4 -> V_134 . V_588 ) ;
F_172 ( & V_4 -> V_134 . V_588 -> V_77 ) ;
V_4 -> V_134 . V_588 = NULL ;
}
if ( V_4 -> V_134 . V_589 ) {
F_171 ( V_4 -> V_134 . V_589 ) ;
F_172 ( & V_4 -> V_134 . V_589 -> V_77 ) ;
V_4 -> V_134 . V_589 = NULL ;
}
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_2 ( V_590 ) ) {
F_3 ( V_591 , F_2 ( V_591 ) | V_592 ) ;
F_4 ( ( ( F_2 ( V_591 ) & V_593 ) == V_594 ) ,
50 ) ;
F_3 ( V_590 , 0 ) ;
F_22 ( V_590 ) ;
F_3 ( V_591 , F_2 ( V_591 ) & ~ V_592 ) ;
F_22 ( V_591 ) ;
}
}
static int F_247 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_134 . V_588 == NULL )
V_4 -> V_134 . V_588 = F_165 ( V_2 ) ;
if ( ! V_4 -> V_134 . V_588 )
return - V_595 ;
if ( V_4 -> V_134 . V_589 == NULL )
V_4 -> V_134 . V_589 = F_165 ( V_2 ) ;
if ( ! V_4 -> V_134 . V_589 ) {
F_245 ( V_2 ) ;
return - V_595 ;
}
return 0 ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_510 * V_511 = & V_4 -> V_511 [ V_596 ] ;
bool V_597 ;
int V_278 ;
if ( ! F_214 ( V_2 ) )
return;
F_147 ( ! F_166 ( & V_2 -> V_73 ) ) ;
V_278 = F_247 ( V_2 ) ;
if ( V_278 )
return;
V_597 = V_4 -> V_570 . V_598 ;
V_4 -> V_570 . V_598 = false ;
V_278 = F_249 ( V_511 , 6 ) ;
if ( V_278 ) {
F_245 ( V_2 ) ;
V_4 -> V_570 . V_598 = V_597 ;
return;
}
F_250 ( V_511 , V_599 | V_600 ) ;
F_250 ( V_511 , V_601 ) ;
F_250 ( V_511 , F_26 ( V_4 -> V_134 . V_588 ) |
V_602 |
V_603 |
V_604 |
V_605 ) ;
F_250 ( V_511 , V_599 ) ;
F_250 ( V_511 , V_606 ) ;
F_250 ( V_511 , V_607 ) ;
F_251 ( V_511 ) ;
V_278 = F_252 ( V_511 ) ;
V_4 -> V_570 . V_598 = V_597 ;
if ( V_278 ) {
F_45 ( L_84 ) ;
F_245 ( V_2 ) ;
return;
}
F_3 ( V_590 , F_26 ( V_4 -> V_134 . V_589 ) | V_608 ) ;
F_3 ( V_591 , F_2 ( V_591 ) & ~ V_592 ) ;
F_209 ( V_2 , V_500 ) ;
}
static unsigned long F_253 ( T_1 V_609 )
{
unsigned long V_610 ;
int div = ( V_609 & 0x3f0000 ) >> 16 ;
int V_611 = ( V_609 & 0x3000 ) >> 12 ;
int V_612 = ( V_609 & 0x7 ) ;
if ( ! V_612 )
return 0 ;
V_610 = ( ( div * 133333 ) / ( ( 1 << V_611 ) * V_612 ) ) ;
return V_610 ;
}
static unsigned long F_254 ( struct V_3 * V_4 )
{
T_8 V_613 , V_552 , V_278 ;
T_1 V_614 , V_615 , V_616 , V_617 = 0 , V_618 = 0 ;
unsigned long V_619 = F_181 ( V_443 ) , V_620 ;
int V_22 ;
F_174 ( & V_403 ) ;
V_620 = V_619 - V_4 -> V_134 . V_442 ;
if ( V_620 <= 10 )
return V_4 -> V_134 . V_621 ;
V_614 = F_2 ( V_622 ) ;
V_615 = F_2 ( V_623 ) ;
V_616 = F_2 ( V_624 ) ;
V_613 = V_614 + V_615 + V_616 ;
if ( V_613 < V_4 -> V_134 . V_441 ) {
V_552 = ~ 0UL - V_4 -> V_134 . V_441 ;
V_552 += V_613 ;
} else {
V_552 = V_613 - V_4 -> V_134 . V_441 ;
}
for ( V_22 = 0 ; V_22 < F_66 ( V_625 ) ; V_22 ++ ) {
if ( V_625 [ V_22 ] . V_22 == V_4 -> V_134 . V_136 &&
V_625 [ V_22 ] . V_626 == V_4 -> V_134 . V_135 ) {
V_617 = V_625 [ V_22 ] . V_617 ;
V_618 = V_625 [ V_22 ] . V_618 ;
break;
}
}
V_552 = F_98 ( V_552 , V_620 ) ;
V_278 = ( ( V_617 * V_552 ) + V_618 ) ;
V_278 = F_98 ( V_278 , 10 ) ;
V_4 -> V_134 . V_441 = V_613 ;
V_4 -> V_134 . V_442 = V_619 ;
V_4 -> V_134 . V_621 = V_278 ;
return V_278 ;
}
unsigned long F_255 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_375 ;
if ( F_56 ( V_2 ) -> V_102 != 5 )
return 0 ;
F_178 ( & V_403 ) ;
V_375 = F_254 ( V_4 ) ;
F_183 ( & V_403 ) ;
return V_375 ;
}
unsigned long F_256 ( struct V_3 * V_4 )
{
unsigned long V_617 , V_627 , V_628 ;
T_1 V_629 ;
V_629 = F_2 ( V_630 ) ;
V_617 = ( ( V_629 & V_631 ) >> V_632 ) ;
V_627 = F_257 ( V_633 ) ;
V_628 = V_629 & V_634 ;
return ( ( V_617 * V_627 ) / 127 ) - V_628 ;
}
static T_2 F_258 ( struct V_3 * V_4 , T_7 V_635 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
static const struct V_636 {
T_2 V_637 ;
T_2 V_638 ;
} V_636 [] = {
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
if ( F_56 ( V_2 ) -> V_639 )
return V_636 [ V_635 ] . V_638 ;
else
return V_636 [ V_635 ] . V_637 ;
}
static void F_259 ( struct V_3 * V_4 )
{
struct V_640 V_619 , V_620 ;
T_8 V_552 ;
unsigned long V_641 ;
T_1 V_642 ;
F_174 ( & V_403 ) ;
F_182 ( & V_619 ) ;
V_620 = F_260 ( V_619 , V_4 -> V_134 . V_445 ) ;
V_641 = V_620 . V_643 * 1000 + V_620 . V_644 / 1000000 ;
if ( ! V_641 )
return;
V_642 = F_2 ( V_645 ) ;
if ( V_642 < V_4 -> V_134 . V_444 ) {
V_552 = ~ 0UL - V_4 -> V_134 . V_444 ;
V_552 += V_642 ;
} else {
V_552 = V_642 - V_4 -> V_134 . V_444 ;
}
V_4 -> V_134 . V_444 = V_642 ;
V_4 -> V_134 . V_445 = V_619 ;
V_552 = V_552 * 1181 ;
V_552 = F_98 ( V_552 , V_641 * 10 ) ;
V_4 -> V_134 . V_646 = V_552 ;
}
void F_261 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_56 ( V_2 ) -> V_102 != 5 )
return;
F_178 ( & V_403 ) ;
F_259 ( V_4 ) ;
F_183 ( & V_403 ) ;
}
static unsigned long F_262 ( struct V_3 * V_4 )
{
unsigned long V_626 , V_647 , V_648 , V_649 , V_650 ;
T_1 V_635 , V_651 ;
F_174 ( & V_403 ) ;
V_635 = F_2 ( V_430 + ( V_4 -> V_453 . V_460 * 4 ) ) ;
V_635 = ( V_635 >> 24 ) & 0x7f ;
V_651 = F_258 ( V_4 , V_635 ) ;
V_648 = V_651 ;
V_626 = F_256 ( V_4 ) ;
if ( V_626 > 80 )
V_647 = ( ( V_626 * 2349 ) + 135940 ) ;
else if ( V_626 >= 50 )
V_647 = ( ( V_626 * 964 ) + 29317 ) ;
else
V_647 = ( ( V_626 * 301 ) + 1004 ) ;
V_647 = V_647 * ( ( 150142 * V_648 ) / 10000 - 78642 ) ;
V_647 /= 100000 ;
V_649 = ( V_647 * V_4 -> V_134 . V_647 ) ;
V_650 = ( V_649 * V_648 ) / 10000 ;
V_650 /= 100 ;
F_259 ( V_4 ) ;
return V_4 -> V_134 . V_646 + V_650 ;
}
unsigned long F_263 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_375 ;
if ( F_56 ( V_2 ) -> V_102 != 5 )
return 0 ;
F_178 ( & V_403 ) ;
V_375 = F_262 ( V_4 ) ;
F_183 ( & V_403 ) ;
return V_375 ;
}
unsigned long F_264 ( void )
{
struct V_3 * V_4 ;
unsigned long V_652 , V_653 , V_278 = 0 ;
F_178 ( & V_403 ) ;
if ( ! V_654 )
goto V_655;
V_4 = V_654 ;
V_652 = F_254 ( V_4 ) ;
V_653 = F_262 ( V_4 ) ;
V_278 = V_652 + V_653 ;
V_655:
F_183 ( & V_403 ) ;
return V_278 ;
}
bool F_265 ( void )
{
struct V_3 * V_4 ;
bool V_278 = true ;
F_178 ( & V_403 ) ;
if ( ! V_654 ) {
V_278 = false ;
goto V_655;
}
V_4 = V_654 ;
if ( V_4 -> V_134 . V_433 > V_4 -> V_134 . V_412 )
V_4 -> V_134 . V_433 -- ;
V_655:
F_183 ( & V_403 ) ;
return V_278 ;
}
bool F_266 ( void )
{
struct V_3 * V_4 ;
bool V_278 = true ;
F_178 ( & V_403 ) ;
if ( ! V_654 ) {
V_278 = false ;
goto V_655;
}
V_4 = V_654 ;
if ( V_4 -> V_134 . V_433 < V_4 -> V_134 . V_434 )
V_4 -> V_134 . V_433 ++ ;
V_655:
F_183 ( & V_403 ) ;
return V_278 ;
}
bool F_267 ( void )
{
struct V_3 * V_4 ;
struct V_510 * V_511 ;
bool V_278 = false ;
int V_22 ;
F_178 ( & V_403 ) ;
if ( ! V_654 )
goto V_655;
V_4 = V_654 ;
F_221 (ring, dev_priv, i)
V_278 |= ! F_268 ( & V_511 -> V_656 ) ;
V_655:
F_183 ( & V_403 ) ;
return V_278 ;
}
bool F_269 ( void )
{
struct V_3 * V_4 ;
bool V_278 = true ;
F_178 ( & V_403 ) ;
if ( ! V_654 ) {
V_278 = false ;
goto V_655;
}
V_4 = V_654 ;
V_4 -> V_134 . V_433 = V_4 -> V_134 . V_414 ;
if ( ! F_173 ( V_4 -> V_2 , V_4 -> V_134 . V_414 ) )
V_278 = false ;
V_655:
F_183 ( & V_403 ) ;
return V_278 ;
}
static void
F_270 ( void )
{
void (* F_271)( void );
F_271 = F_272 ( V_657 ) ;
if ( F_271 ) {
F_271 () ;
F_273 ( V_657 ) ;
}
}
void F_274 ( struct V_3 * V_4 )
{
F_178 ( & V_403 ) ;
V_654 = V_4 ;
F_183 ( & V_403 ) ;
F_270 () ;
}
void F_275 ( void )
{
F_178 ( & V_403 ) ;
V_654 = NULL ;
F_183 ( & V_403 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_658 ;
T_7 V_659 [ 16 ] ;
int V_22 ;
F_3 ( V_660 , 0 ) ;
F_22 ( V_660 ) ;
F_3 ( V_661 , 0x15040d00 ) ;
F_3 ( V_662 , 0x007f0000 ) ;
F_3 ( V_663 , 0x1e220004 ) ;
F_3 ( V_664 , 0x04000004 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_3 ( V_665 + ( V_22 * 4 ) , 0 ) ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
F_3 ( V_666 + ( V_22 * 4 ) , 0 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ ) {
T_1 V_667 = F_2 ( V_430 + ( V_22 * 4 ) ) ;
unsigned long V_610 = F_253 ( V_667 ) ;
unsigned long V_668 = ( V_667 & V_431 ) >>
V_432 ;
unsigned long V_375 ;
V_375 = V_668 * V_668 ;
V_375 *= ( V_610 / 1000 ) ;
V_375 *= 255 ;
V_375 /= ( 127 * 127 * 900 ) ;
if ( V_375 > 0xff )
F_45 ( L_85 , V_375 ) ;
V_659 [ V_22 ] = V_375 ;
}
V_659 [ 14 ] = 0 ;
V_659 [ 15 ] = 0 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
T_1 V_375 = ( V_659 [ V_22 * 4 ] << 24 ) | ( V_659 [ ( V_22 * 4 ) + 1 ] << 16 ) |
( V_659 [ ( V_22 * 4 ) + 2 ] << 8 ) | ( V_659 [ ( V_22 * 4 ) + 3 ] ) ;
F_3 ( V_669 + ( V_22 * 4 ) , V_375 ) ;
}
F_3 ( V_670 , 0 ) ;
F_3 ( V_671 , 0 ) ;
F_3 ( V_672 , 0x00007f00 ) ;
F_3 ( V_673 , 0x0000000e ) ;
F_3 ( V_674 , 0x000e0000 ) ;
F_3 ( V_675 , 0x68000300 ) ;
F_3 ( V_676 , 0x42000000 ) ;
F_3 ( V_677 , 0x00140031 ) ;
F_3 ( V_678 , 0 ) ;
F_3 ( V_679 , 0 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_3 ( V_680 + ( V_22 * 4 ) , 0 ) ;
F_3 ( V_660 , 0x80000019 ) ;
V_658 = F_2 ( V_681 ) ;
V_4 -> V_134 . V_647 = ( V_658 & V_682 ) ;
}
void F_277 ( struct V_1 * V_2 )
{
V_89 . V_503 = F_212 ( V_2 , V_89 . V_503 ) ;
if ( F_200 ( V_2 ) )
F_242 ( V_2 ) ;
}
void F_278 ( struct V_1 * V_2 )
{
if ( F_200 ( V_2 ) )
F_243 ( V_2 ) ;
}
void F_279 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_147 ( V_2 -> V_683 ) ;
if ( F_213 ( V_2 ) ) {
F_184 ( V_2 ) ;
F_246 ( V_2 ) ;
} else if ( F_27 ( V_2 ) || F_280 ( V_2 ) || F_126 ( V_2 ) ) {
if ( F_281 ( & V_4 -> V_453 . V_684 ) )
F_282 ( V_4 ) ;
F_283 ( & V_4 -> V_453 . V_72 ) ;
F_38 ( & V_4 -> V_453 . V_483 ) ;
if ( F_200 ( V_2 ) )
F_208 ( V_2 ) ;
else
F_207 ( V_2 ) ;
V_4 -> V_453 . V_161 = false ;
F_39 ( & V_4 -> V_453 . V_483 ) ;
}
}
static void F_284 ( struct V_69 * V_72 )
{
struct V_3 * V_4 =
F_36 ( V_72 , struct V_3 ,
V_453 . V_684 . V_72 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_453 . V_483 ) ;
if ( F_200 ( V_2 ) ) {
F_244 ( V_2 ) ;
} else if ( F_126 ( V_2 ) ) {
F_220 ( V_2 ) ;
F_228 ( V_2 ) ;
} else {
F_223 ( V_2 ) ;
F_228 ( V_2 ) ;
}
V_4 -> V_453 . V_161 = true ;
F_39 ( & V_4 -> V_453 . V_483 ) ;
F_282 ( V_4 ) ;
}
void F_285 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_213 ( V_2 ) ) {
F_38 ( & V_2 -> V_73 ) ;
F_177 ( V_2 ) ;
F_248 ( V_2 ) ;
F_276 ( V_2 ) ;
F_39 ( & V_2 -> V_73 ) ;
} else if ( F_27 ( V_2 ) || F_280 ( V_2 ) || F_126 ( V_2 ) ) {
if ( F_47 ( & V_4 -> V_453 . V_684 ,
F_286 ( V_685 ) ) )
F_287 ( V_4 ) ;
}
}
void F_288 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_453 . V_161 = false ;
F_285 ( V_2 ) ;
}
static void F_289 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_686 , V_687 ) ;
}
static void F_290 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_65 ;
F_150 (pipe) {
F_3 ( F_291 ( V_65 ) ,
F_2 ( F_291 ( V_65 ) ) |
V_688 ) ;
F_292 ( V_4 , V_65 ) ;
}
}
static void F_293 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_372 , F_2 ( V_372 ) & ~ V_351 ) ;
F_3 ( V_373 , F_2 ( V_373 ) & ~ V_351 ) ;
F_3 ( V_374 , F_2 ( V_374 ) & ~ V_351 ) ;
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_689 = V_690 ;
V_689 |= V_691 |
V_692 |
V_693 ;
F_3 ( V_694 ,
V_695 |
V_696 ) ;
F_3 ( V_697 ,
V_698 ) ;
F_3 ( V_699 ,
( F_2 ( V_699 ) |
V_700 | V_701 ) ) ;
V_689 |= V_702 ;
F_3 ( V_384 ,
( F_2 ( V_384 ) |
V_385 ) ) ;
F_293 ( V_2 ) ;
if ( F_213 ( V_2 ) ) {
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 ) ;
F_3 ( V_699 ,
F_2 ( V_699 ) |
V_700 ) ;
}
F_3 ( V_703 , V_689 ) ;
F_3 ( V_699 ,
F_2 ( V_699 ) |
V_704 ) ;
F_3 ( V_705 ,
V_706 << 16 |
V_706 ) ;
F_3 ( V_707 ,
F_95 ( V_708 ) ) ;
F_3 ( V_707 , F_93 ( V_709 ) ) ;
F_290 ( V_2 ) ;
F_289 ( V_2 ) ;
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_65 ;
T_3 V_375 ;
F_3 ( V_686 , V_687 |
V_710 |
V_711 ) ;
F_3 ( V_712 , F_2 ( V_712 ) |
V_713 ) ;
F_150 (pipe) {
V_375 = F_2 ( F_296 ( V_65 ) ) ;
V_375 |= V_714 ;
V_375 &= ~ V_715 ;
if ( V_4 -> V_716 . V_717 )
V_375 |= V_715 ;
V_375 &= ~ V_718 ;
V_375 &= ~ V_719 ;
V_375 &= ~ V_720 ;
F_3 ( F_296 ( V_65 ) , V_375 ) ;
}
F_150 (pipe) {
F_3 ( F_297 ( V_65 ) ,
V_721 ) ;
}
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_114 ;
V_114 = F_2 ( V_317 ) ;
if ( ( V_114 & V_722 ) != V_723 ) {
F_211 ( L_86 , V_114 ) ;
F_211 ( L_87 ) ;
F_211 ( L_88 ) ;
}
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_689 = V_690 ;
F_3 ( V_703 , V_689 ) ;
F_3 ( V_699 ,
F_2 ( V_699 ) |
V_704 ) ;
F_3 ( V_724 ,
F_95 ( V_725 ) ) ;
if ( F_300 ( V_2 ) )
F_3 ( V_726 ,
F_95 ( V_727 ) ) ;
F_3 ( V_707 , F_93 ( V_709 ) ) ;
F_3 ( V_726 ,
V_728 | V_729 ) ;
F_293 ( V_2 ) ;
F_3 ( V_707 ,
F_93 ( V_730 ) ) ;
F_3 ( V_731 ,
F_2 ( V_731 ) |
V_732 |
V_733 ) ;
F_3 ( V_734 ,
V_735 |
V_736 ) ;
F_3 ( V_737 ,
F_95 ( V_738 ) ) ;
F_3 ( V_737 ,
F_95 ( V_739 ) ) ;
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 | V_740 ) ;
F_3 ( V_699 ,
F_2 ( V_699 ) |
V_700 | V_701 ) ;
F_3 ( V_703 ,
F_2 ( V_703 ) |
V_702 |
V_693 ) ;
F_290 ( V_2 ) ;
F_295 ( V_2 ) ;
F_298 ( V_2 ) ;
}
static void F_301 ( struct V_3 * V_4 )
{
T_3 V_163 = F_2 ( V_741 ) ;
V_163 &= ~ V_742 ;
V_163 |= V_743 ;
V_163 |= V_744 ;
V_163 |= V_745 ;
F_3 ( V_741 , V_163 ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_746 == V_747 )
F_3 ( V_686 ,
F_2 ( V_686 ) |
V_748 ) ;
F_3 ( V_749 ,
F_2 ( V_749 ) |
V_721 ) ;
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_746 == V_747 ) {
T_3 V_375 = F_2 ( V_686 ) ;
V_375 &= ~ V_748 ;
F_3 ( V_686 , V_375 ) ;
}
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_65 V_65 ;
F_3 ( V_372 , 0 ) ;
F_3 ( V_373 , 0 ) ;
F_3 ( V_374 , 0 ) ;
F_3 ( V_750 ,
F_95 ( V_751 ) ) ;
F_3 ( V_750 ,
F_95 ( V_752 ) ) ;
F_3 ( V_753 ,
F_95 ( V_754 ) ) ;
F_3 ( V_753 ,
F_95 ( V_755 ) ) ;
F_3 ( V_756 , F_95 ( V_757 ) ) ;
F_3 ( V_737 ,
F_305 ( 2 ) ) ;
F_3 ( V_758 ,
F_95 ( V_759 ) ) ;
F_3 ( V_760 ,
F_95 ( V_761 ) ) ;
F_3 ( V_762 ,
F_95 ( V_763 ) ) ;
F_3 ( V_764 , F_2 ( V_764 ) | V_765 ) ;
F_3 ( V_766 ,
F_2 ( V_766 ) | V_767 ) ;
F_150 (pipe) {
F_3 ( F_33 ( V_65 ) ,
F_2 ( F_33 ( V_65 ) ) |
V_768 ) ;
}
F_3 ( V_769 ,
F_2 ( V_769 ) |
F_95 ( V_770 ) ) ;
F_3 ( V_741 ,
F_2 ( V_741 ) &
~ ( V_771 | V_772 ) ) ;
F_3 ( V_773 ,
V_728 | V_729 ) ;
F_3 ( V_774 ,
F_95 ( V_775 ) ) ;
F_3 ( V_776 , F_2 ( V_776 ) |
V_777 ) ;
F_3 ( V_778 ,
F_95 ( V_779 ) ) ;
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_293 ( V_2 ) ;
F_3 ( V_780 , V_781 ) ;
F_3 ( V_782 ,
F_95 ( V_783 ) ) ;
F_3 ( V_784 ,
F_2 ( V_784 ) |
V_785 ) ;
F_3 ( V_741 ,
F_2 ( V_741 ) & ~ V_772 ) ;
F_3 ( V_786 , F_93 ( V_709 ) ) ;
F_3 ( V_786 ,
F_93 ( V_787 ) ) ;
F_3 ( V_778 ,
F_95 ( V_788 ) ) ;
F_3 ( V_773 ,
V_728 | V_729 ) ;
F_3 ( V_764 , F_2 ( V_764 ) | V_765 ) ;
F_3 ( V_766 ,
F_2 ( V_766 ) | V_789 ) ;
F_302 ( V_2 ) ;
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_790 ;
F_293 ( V_2 ) ;
F_3 ( V_703 , V_690 ) ;
F_3 ( V_737 ,
F_95 ( V_791 ) ) ;
F_3 ( V_792 ,
V_793 |
V_794 ) ;
if ( F_308 ( V_2 ) )
F_3 ( V_760 ,
F_95 ( V_795 ) ) ;
F_3 ( V_786 , F_93 ( V_709 ) ) ;
F_3 ( V_796 ,
V_797 ) ;
F_3 ( V_798 ,
V_799 ) ;
F_3 ( V_800 ,
V_801 ) ;
if ( F_308 ( V_2 ) )
F_3 ( V_762 ,
F_95 ( V_763 ) ) ;
else {
F_3 ( V_762 ,
F_95 ( V_763 ) ) ;
F_3 ( V_802 ,
F_95 ( V_763 ) ) ;
}
F_3 ( V_803 , F_2 ( V_803 ) &
~ V_804 ) ;
F_3 ( V_734 ,
V_805 ) ;
F_3 ( V_784 ,
F_2 ( V_784 ) |
V_785 ) ;
F_290 ( V_2 ) ;
F_301 ( V_4 ) ;
if ( 0 ) {
F_3 ( V_786 ,
F_93 ( V_787 ) ) ;
}
F_3 ( V_778 ,
F_95 ( V_788 ) ) ;
F_3 ( V_773 ,
V_728 | V_729 ) ;
V_790 = F_2 ( V_806 ) ;
V_790 &= ~ V_807 ;
V_790 |= V_808 ;
F_3 ( V_806 , V_790 ) ;
if ( ! F_309 ( V_2 ) )
F_295 ( V_2 ) ;
F_298 ( V_2 ) ;
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_375 ;
F_38 ( & V_4 -> V_453 . V_483 ) ;
V_375 = F_198 ( V_4 , V_491 ) ;
F_39 ( & V_4 -> V_453 . V_483 ) ;
switch ( ( V_375 >> 6 ) & 3 ) {
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
F_64 ( L_89 , V_4 -> V_124 ) ;
V_4 -> V_809 = F_311 ( V_4 ) ;
F_64 ( L_90 ,
V_4 -> V_809 ) ;
F_3 ( V_810 , V_811 ) ;
F_3 ( V_737 ,
F_95 ( V_791 ) ) ;
F_3 ( V_792 ,
V_793 |
V_794 ) ;
F_3 ( V_760 ,
F_95 ( V_812 |
V_795 ) ) ;
F_3 ( V_786 , F_93 ( V_709 ) ) ;
F_3 ( V_803 , F_2 ( V_803 ) &
~ V_804 ) ;
F_3 ( V_762 ,
F_95 ( V_763 ) ) ;
F_3 ( V_784 ,
F_2 ( V_784 ) |
V_785 ) ;
F_301 ( V_4 ) ;
F_3 ( V_734 ,
V_805 ) ;
F_3 ( V_813 ,
F_2 ( V_813 ) | V_814 ) ;
F_3 ( V_815 , V_816 ) ;
F_3 ( V_778 ,
F_95 ( V_788 ) ) ;
F_3 ( V_817 , V_818 ) ;
F_3 ( V_819 , V_820 ) ;
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_810 , V_811 ) ;
F_3 ( V_815 , V_816 ) ;
F_3 ( V_750 ,
F_95 ( V_751 ) ) ;
F_3 ( V_750 ,
F_95 ( V_752 ) ) ;
F_3 ( V_741 ,
F_2 ( V_741 ) &
~ ( V_771 | V_772 ) ) ;
F_3 ( V_774 ,
F_95 ( V_775 ) ) ;
F_3 ( V_731 , F_2 ( V_731 ) |
V_733 ) ;
F_3 ( V_776 , F_2 ( V_776 ) |
V_777 ) ;
F_3 ( V_753 ,
F_95 ( V_755 ) ) ;
F_3 ( V_819 , F_2 ( V_819 ) |
V_821 ) ;
F_3 ( V_774 ,
F_95 ( V_822 ) ) ;
F_3 ( V_762 ,
F_95 ( V_763 ) ) ;
F_3 ( V_731 , F_2 ( V_731 ) |
V_823 ) ;
}
static void F_313 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_689 ;
F_3 ( V_824 , 0 ) ;
F_3 ( V_825 , V_826 |
V_827 |
V_828 ) ;
F_3 ( V_829 , 0 ) ;
V_689 = V_811 |
V_830 |
V_831 ;
if ( F_314 ( V_2 ) )
V_689 |= V_832 ;
F_3 ( V_810 , V_689 ) ;
F_3 ( V_707 ,
F_95 ( V_708 ) ) ;
F_3 ( V_707 , F_93 ( V_709 ) ) ;
F_290 ( V_2 ) ;
}
static void F_315 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_824 , V_833 ) ;
F_3 ( V_825 , 0 ) ;
F_3 ( V_810 , 0 ) ;
F_3 ( V_829 , 0 ) ;
F_175 ( V_834 , 0 ) ;
F_3 ( V_835 ,
F_95 ( V_816 ) ) ;
F_3 ( V_707 , F_93 ( V_709 ) ) ;
}
static void F_316 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_824 , V_836 |
V_833 |
V_837 |
V_838 |
V_839 ) ;
F_3 ( V_825 , 0 ) ;
F_3 ( V_835 ,
F_95 ( V_816 ) ) ;
F_3 ( V_707 , F_93 ( V_709 ) ) ;
}
static void F_317 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_840 = F_2 ( V_841 ) ;
V_840 |= V_842 | V_843 |
V_844 ;
F_3 ( V_841 , V_840 ) ;
if ( F_318 ( V_2 ) )
F_3 ( V_845 , F_95 ( V_846 ) ) ;
F_3 ( V_845 , F_93 ( V_847 ) ) ;
F_3 ( V_264 , F_95 ( V_848 ) ) ;
F_3 ( V_835 , F_95 ( V_849 ) ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_824 , V_850 ) ;
F_3 ( V_851 , F_95 ( V_852 ) |
F_93 ( V_853 ) ) ;
}
static void F_320 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_810 , V_830 ) ;
}
void F_321 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_67 . V_854 ( V_2 ) ;
}
void F_322 ( struct V_1 * V_2 )
{
if ( F_323 ( V_2 ) )
F_303 ( V_2 ) ;
}
static bool F_324 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
return F_2 ( V_857 ) ==
( V_858 | V_859 ) ;
}
bool F_325 ( struct V_3 * V_4 ,
enum V_860 V_861 )
{
struct V_862 * V_863 ;
struct V_855 * V_856 ;
bool V_864 ;
int V_22 ;
if ( V_4 -> V_865 . V_866 )
return false ;
V_863 = & V_4 -> V_863 ;
V_864 = true ;
F_326 (i, power_well, BIT(domain), power_domains) {
if ( V_856 -> V_867 )
continue;
if ( ! V_856 -> V_868 ) {
V_864 = false ;
break;
}
}
return V_864 ;
}
bool F_327 ( struct V_3 * V_4 ,
enum V_860 V_861 )
{
struct V_862 * V_863 ;
bool V_278 ;
V_863 = & V_4 -> V_863 ;
F_38 ( & V_863 -> V_869 ) ;
V_278 = F_325 ( V_4 , V_861 ) ;
F_39 ( & V_863 -> V_869 ) ;
return V_278 ;
}
static void F_328 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_870 ;
F_329 ( V_2 -> V_488 , V_871 ) ;
F_330 ( F_331 ( V_872 ) , V_873 ) ;
F_332 ( V_2 -> V_488 , V_871 ) ;
if ( F_126 ( V_2 ) ) {
F_333 ( & V_4 -> V_494 , V_870 ) ;
F_3 ( F_334 ( V_236 ) ,
V_4 -> V_874 [ V_236 ] ) ;
F_3 ( F_335 ( V_236 ) ,
~ V_4 -> V_874 [ V_236 ] |
V_875 ) ;
F_3 ( F_334 ( V_378 ) ,
V_4 -> V_874 [ V_378 ] ) ;
F_3 ( F_335 ( V_378 ) ,
~ V_4 -> V_874 [ V_378 ] |
V_875 ) ;
F_22 ( F_335 ( V_378 ) ) ;
F_336 ( & V_4 -> V_494 , V_870 ) ;
}
}
static void F_337 ( struct V_3 * V_4 ,
struct V_855 * V_856 , bool V_305 )
{
bool V_864 , V_876 ;
T_3 V_114 ;
V_114 = F_2 ( V_857 ) ;
V_864 = V_114 & V_859 ;
V_876 = V_114 & V_858 ;
if ( V_305 ) {
if ( ! V_876 )
F_3 ( V_857 ,
V_858 ) ;
if ( ! V_864 ) {
F_5 ( L_91 ) ;
if ( F_4 ( ( F_2 ( V_857 ) &
V_859 ) , 20 ) )
F_45 ( L_92 ) ;
}
F_328 ( V_4 ) ;
} else {
if ( V_876 ) {
F_3 ( V_857 , 0 ) ;
F_22 ( V_857 ) ;
F_5 ( L_93 ) ;
}
}
}
static void F_338 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
F_337 ( V_4 , V_856 , V_856 -> V_642 > 0 ) ;
if ( F_2 ( V_877 ) & V_858 )
F_3 ( V_877 , 0 ) ;
}
static void F_339 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
F_337 ( V_4 , V_856 , true ) ;
}
static void F_340 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
F_337 ( V_4 , V_856 , false ) ;
}
static void F_341 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
}
static bool F_342 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
return true ;
}
void F_343 ( struct V_3 * V_4 ,
enum V_878 V_879 , bool V_305 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_477 ;
T_1 V_880 ;
T_1 V_881 ;
enum V_65 V_65 ;
if ( V_879 == V_882 ) {
if ( V_305 ) {
F_3 ( F_344 ( V_236 ) , F_2 ( F_344 ( V_236 ) ) |
V_883 |
V_884 ) ;
F_345 ( 1 ) ;
} else {
F_150 (pipe)
F_346 ( V_4 , V_65 ) ;
F_3 ( V_885 , F_2 ( V_885 ) &
~ V_886 ) ;
}
}
V_477 = F_347 ( V_879 ) ;
V_880 = V_305 ? F_348 ( V_879 ) :
F_349 ( V_879 ) ;
F_38 ( & V_4 -> V_453 . V_483 ) ;
#define F_350 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_350 )
goto V_581;
V_881 = F_198 ( V_4 , V_887 ) ;
V_881 &= ~ V_477 ;
V_881 |= V_880 ;
F_197 ( V_4 , V_887 , V_881 ) ;
if ( F_4 ( F_350 , 100 ) )
F_45 ( L_94 ,
V_880 ,
F_198 ( V_4 , V_887 ) ) ;
#undef F_350
V_581:
F_39 ( & V_4 -> V_453 . V_483 ) ;
if ( V_879 == V_882 && V_305 )
F_3 ( V_885 , F_2 ( V_885 ) | V_886 ) ;
}
static void F_351 ( struct V_3 * V_4 ,
struct V_855 * V_856 , bool V_305 )
{
enum V_878 V_879 = V_856 -> V_888 ;
F_343 ( V_4 , V_879 , V_305 ) ;
}
static void F_352 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
F_351 ( V_4 , V_856 , V_856 -> V_642 > 0 ) ;
}
static void F_353 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
F_351 ( V_4 , V_856 , true ) ;
}
static void F_354 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
F_351 ( V_4 , V_856 , false ) ;
}
static bool F_355 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
int V_879 = V_856 -> V_888 ;
bool V_161 = false ;
T_1 V_477 ;
T_1 V_880 ;
T_1 V_881 ;
V_477 = F_347 ( V_879 ) ;
V_881 = F_348 ( V_879 ) ;
F_38 ( & V_4 -> V_453 . V_483 ) ;
V_880 = F_198 ( V_4 , V_889 ) & V_477 ;
F_147 ( V_880 != F_348 ( V_879 ) &&
V_880 != F_349 ( V_879 ) ) ;
if ( V_880 == V_881 )
V_161 = true ;
V_881 = F_198 ( V_4 , V_887 ) & V_477 ;
F_147 ( V_881 != V_880 ) ;
F_39 ( & V_4 -> V_453 . V_483 ) ;
return V_161 ;
}
static void F_356 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
F_357 ( V_856 -> V_888 != V_890 ) ;
F_351 ( V_4 , V_856 , true ) ;
F_178 ( & V_4 -> V_494 ) ;
F_358 ( V_4 ) ;
F_183 ( & V_4 -> V_494 ) ;
if ( V_4 -> V_863 . V_891 )
return;
F_359 ( V_4 -> V_2 ) ;
F_360 ( V_4 -> V_2 ) ;
}
static void F_361 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
F_357 ( V_856 -> V_888 != V_890 ) ;
F_178 ( & V_4 -> V_494 ) ;
F_362 ( V_4 ) ;
F_183 ( & V_4 -> V_494 ) ;
F_351 ( V_4 , V_856 , false ) ;
}
static void F_363 ( struct V_3 * V_4 ,
struct V_855 * V_856 )
{
bool V_161 = V_856 -> V_892 -> V_864 ( V_4 , V_856 ) ;
if ( V_856 -> V_867 || ! V_89 . V_893 ) {
if ( ! V_161 )
goto V_894;
return;
}
if ( V_161 != ( V_856 -> V_642 > 0 ) )
goto V_894;
return;
V_894:
F_100 ( 1 , L_95 ,
V_856 -> V_328 , V_856 -> V_867 , V_161 ,
V_856 -> V_642 , V_89 . V_893 ) ;
}
void F_364 ( struct V_3 * V_4 ,
enum V_860 V_861 )
{
struct V_862 * V_863 ;
struct V_855 * V_856 ;
int V_22 ;
F_365 ( V_4 ) ;
V_863 = & V_4 -> V_863 ;
F_38 ( & V_863 -> V_869 ) ;
F_366 (i, power_well, BIT(domain), power_domains) {
if ( ! V_856 -> V_642 ++ ) {
F_5 ( L_96 , V_856 -> V_328 ) ;
V_856 -> V_892 -> V_305 ( V_4 , V_856 ) ;
V_856 -> V_868 = true ;
}
F_363 ( V_4 , V_856 ) ;
}
V_863 -> V_895 [ V_861 ] ++ ;
F_39 ( & V_863 -> V_869 ) ;
}
void F_367 ( struct V_3 * V_4 ,
enum V_860 V_861 )
{
struct V_862 * V_863 ;
struct V_855 * V_856 ;
int V_22 ;
V_863 = & V_4 -> V_863 ;
F_38 ( & V_863 -> V_869 ) ;
F_147 ( ! V_863 -> V_895 [ V_861 ] ) ;
V_863 -> V_895 [ V_861 ] -- ;
F_326 (i, power_well, BIT(domain), power_domains) {
F_147 ( ! V_856 -> V_642 ) ;
if ( ! -- V_856 -> V_642 && V_89 . V_893 ) {
F_5 ( L_97 , V_856 -> V_328 ) ;
V_856 -> V_868 = false ;
V_856 -> V_892 -> V_896 ( V_4 , V_856 ) ;
}
F_363 ( V_4 , V_856 ) ;
}
F_39 ( & V_863 -> V_869 ) ;
F_282 ( V_4 ) ;
}
int F_368 ( void )
{
struct V_3 * V_4 ;
if ( ! V_897 )
return - V_898 ;
V_4 = F_36 ( V_897 , struct V_3 ,
V_863 ) ;
F_364 ( V_4 , V_899 ) ;
return 0 ;
}
int F_369 ( void )
{
struct V_3 * V_4 ;
if ( ! V_897 )
return - V_898 ;
V_4 = F_36 ( V_897 , struct V_3 ,
V_863 ) ;
F_367 ( V_4 , V_899 ) ;
return 0 ;
}
int F_370 ( void )
{
struct V_3 * V_4 ;
if ( ! V_897 )
return - V_898 ;
V_4 = F_36 ( V_897 , struct V_3 ,
V_863 ) ;
return F_121 ( V_4 ) ;
}
int F_371 ( struct V_3 * V_4 )
{
struct V_862 * V_863 = & V_4 -> V_863 ;
F_372 ( & V_863 -> V_869 ) ;
if ( F_125 ( V_4 -> V_2 ) ) {
F_373 ( V_863 , V_900 ) ;
V_897 = V_863 ;
} else if ( F_126 ( V_4 -> V_2 ) ) {
F_373 ( V_863 , V_901 ) ;
V_897 = V_863 ;
} else if ( F_200 ( V_4 -> V_2 ) ) {
F_373 ( V_863 , V_902 ) ;
} else {
F_373 ( V_863 , V_903 ) ;
}
return 0 ;
}
void F_374 ( struct V_3 * V_4 )
{
V_897 = NULL ;
}
static void F_375 ( struct V_3 * V_4 )
{
struct V_862 * V_863 = & V_4 -> V_863 ;
struct V_855 * V_856 ;
int V_22 ;
F_38 ( & V_863 -> V_869 ) ;
F_366 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_856 -> V_892 -> V_904 ( V_4 , V_856 ) ;
V_856 -> V_868 = V_856 -> V_892 -> V_864 ( V_4 ,
V_856 ) ;
}
F_39 ( & V_863 -> V_869 ) ;
}
void F_376 ( struct V_3 * V_4 )
{
struct V_862 * V_863 = & V_4 -> V_863 ;
V_863 -> V_891 = true ;
F_377 ( V_4 , true ) ;
F_375 ( V_4 ) ;
V_863 -> V_891 = false ;
}
void F_378 ( struct V_3 * V_4 )
{
F_365 ( V_4 ) ;
}
void F_379 ( struct V_3 * V_4 )
{
F_282 ( V_4 ) ;
}
void F_365 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_905 * V_905 = & V_2 -> V_488 -> V_2 ;
if ( ! F_380 ( V_2 ) )
return;
F_381 ( V_905 ) ;
F_100 ( V_4 -> V_865 . V_866 , L_98 ) ;
}
void F_287 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_905 * V_905 = & V_2 -> V_488 -> V_2 ;
if ( ! F_380 ( V_2 ) )
return;
F_100 ( V_4 -> V_865 . V_866 , L_99 ) ;
F_382 ( V_905 ) ;
}
void F_282 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_905 * V_905 = & V_2 -> V_488 -> V_2 ;
if ( ! F_380 ( V_2 ) )
return;
F_383 ( V_905 ) ;
F_384 ( V_905 ) ;
}
void F_385 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_905 * V_905 = & V_2 -> V_488 -> V_2 ;
if ( ! F_380 ( V_2 ) )
return;
F_386 ( V_905 ) ;
if ( ! F_214 ( V_2 ) ) {
F_211 ( L_100 ) ;
return;
}
F_387 ( V_905 , 10000 ) ;
F_383 ( V_905 ) ;
F_388 ( V_905 ) ;
F_384 ( V_905 ) ;
}
void F_389 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_905 * V_905 = & V_2 -> V_488 -> V_2 ;
if ( ! F_380 ( V_2 ) )
return;
if ( ! F_214 ( V_2 ) )
return;
F_381 ( V_905 ) ;
F_390 ( V_905 ) ;
}
void F_391 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_52 ( V_2 ) ) {
if ( F_56 ( V_2 ) -> V_102 >= 7 ) {
V_4 -> V_67 . V_68 = F_29 ;
V_4 -> V_67 . V_75 = F_30 ;
V_4 -> V_67 . V_80 = F_28 ;
} else if ( F_56 ( V_2 ) -> V_102 >= 5 ) {
V_4 -> V_67 . V_68 = F_29 ;
V_4 -> V_67 . V_75 = F_24 ;
V_4 -> V_67 . V_80 = F_28 ;
} else if ( F_314 ( V_2 ) ) {
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
if ( F_318 ( V_2 ) )
F_61 ( V_2 ) ;
else if ( F_25 ( V_2 ) )
F_62 ( V_2 ) ;
if ( F_392 ( V_2 ) ) {
F_135 ( V_2 ) ;
if ( ( F_25 ( V_2 ) && V_4 -> V_151 . V_309 [ 1 ] &&
V_4 -> V_151 . V_310 [ 1 ] && V_4 -> V_151 . V_311 [ 1 ] ) ||
( ! F_25 ( V_2 ) && V_4 -> V_151 . V_309 [ 0 ] &&
V_4 -> V_151 . V_310 [ 0 ] && V_4 -> V_151 . V_311 [ 0 ] ) ) {
V_4 -> V_67 . V_397 = F_158 ;
V_4 -> V_67 . V_398 = F_159 ;
} else {
F_5 ( L_101
L_102 ) ;
}
if ( F_25 ( V_2 ) )
V_4 -> V_67 . V_854 = F_294 ;
else if ( F_27 ( V_2 ) )
V_4 -> V_67 . V_854 = F_299 ;
else if ( F_32 ( V_2 ) )
V_4 -> V_67 . V_854 = F_307 ;
else if ( F_125 ( V_2 ) )
V_4 -> V_67 . V_854 = F_306 ;
else if ( F_56 ( V_2 ) -> V_102 == 8 )
V_4 -> V_67 . V_854 = F_304 ;
} else if ( F_393 ( V_2 ) ) {
V_4 -> V_67 . V_397 = F_84 ;
V_4 -> V_67 . V_854 =
F_312 ;
} else if ( F_200 ( V_2 ) ) {
V_4 -> V_67 . V_397 = F_84 ;
V_4 -> V_67 . V_854 =
F_310 ;
} else if ( F_318 ( V_2 ) ) {
if ( ! F_65 ( F_75 ( V_2 ) ,
V_4 -> V_128 ,
V_4 -> V_118 ,
V_4 -> V_124 ) ) {
F_211 ( L_103
L_104
L_105 ,
( V_4 -> V_128 == 1 ) ? L_106 : L_107 ,
V_4 -> V_118 , V_4 -> V_124 ) ;
F_67 ( V_2 ) ;
V_4 -> V_67 . V_397 = NULL ;
} else
V_4 -> V_67 . V_397 = F_74 ;
V_4 -> V_67 . V_854 = F_317 ;
} else if ( F_55 ( V_2 ) ) {
V_4 -> V_67 . V_397 = F_87 ;
V_4 -> V_67 . V_854 = F_313 ;
} else if ( F_10 ( V_2 ) ) {
V_4 -> V_67 . V_397 = F_88 ;
if ( F_89 ( V_2 ) )
V_4 -> V_67 . V_854 = F_315 ;
else if ( F_394 ( V_2 ) )
V_4 -> V_67 . V_854 = F_316 ;
} else if ( F_395 ( V_2 ) ) {
V_4 -> V_67 . V_397 = F_90 ;
V_4 -> V_67 . V_260 = F_68 ;
V_4 -> V_67 . V_854 = F_317 ;
} else if ( F_9 ( V_2 ) ) {
if ( F_56 ( V_2 ) -> V_300 == 1 ) {
V_4 -> V_67 . V_397 = F_96 ;
V_4 -> V_67 . V_260 = F_70 ;
} else {
V_4 -> V_67 . V_397 = F_90 ;
V_4 -> V_67 . V_260 = F_69 ;
}
if ( F_396 ( V_2 ) || F_397 ( V_2 ) )
V_4 -> V_67 . V_854 = F_319 ;
else
V_4 -> V_67 . V_854 = F_320 ;
} else {
F_45 ( L_108 ) ;
}
}
int F_225 ( struct V_3 * V_4 , T_7 V_906 , T_1 * V_375 )
{
F_147 ( ! F_166 ( & V_4 -> V_453 . V_483 ) ) ;
if ( F_2 ( V_907 ) & V_908 ) {
F_64 ( L_109 ) ;
return - V_909 ;
}
F_3 ( V_910 , * V_375 ) ;
F_3 ( V_907 , V_908 | V_906 ) ;
if ( F_4 ( ( F_2 ( V_907 ) & V_908 ) == 0 ,
500 ) ) {
F_45 ( L_110 , V_906 ) ;
return - V_911 ;
}
* V_375 = F_2 ( V_910 ) ;
F_3 ( V_910 , 0 ) ;
return 0 ;
}
int F_224 ( struct V_3 * V_4 , T_7 V_906 , T_1 V_375 )
{
F_147 ( ! F_166 ( & V_4 -> V_453 . V_483 ) ) ;
if ( F_2 ( V_907 ) & V_908 ) {
F_64 ( L_111 ) ;
return - V_909 ;
}
F_3 ( V_910 , V_375 ) ;
F_3 ( V_907 , V_908 | V_906 ) ;
if ( F_4 ( ( F_2 ( V_907 ) & V_908 ) == 0 ,
500 ) ) {
F_45 ( L_112 , V_906 ) ;
return - V_911 ;
}
F_3 ( V_910 , 0 ) ;
return 0 ;
}
int F_202 ( struct V_3 * V_4 , int V_375 )
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
return F_120 ( V_4 -> V_124 * ( V_375 + 6 - 0xbd ) , 4 * div ) ;
}
int F_398 ( struct V_3 * V_4 , int V_375 )
{
int V_912 ;
switch ( V_4 -> V_124 ) {
case 800 :
V_912 = 10 ;
break;
case 1066 :
V_912 = 12 ;
break;
case 1333 :
V_912 = 16 ;
break;
default:
return - 1 ;
}
return F_120 ( 4 * V_912 * V_375 , V_4 -> V_124 ) + 0xbd - 6 ;
}
void F_399 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_372 ( & V_4 -> V_453 . V_483 ) ;
F_46 ( & V_4 -> V_453 . V_684 ,
F_284 ) ;
V_4 -> V_865 . V_866 = false ;
V_4 -> V_865 . V_913 = false ;
}
