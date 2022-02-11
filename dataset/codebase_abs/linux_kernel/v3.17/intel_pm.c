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
struct V_18 * V_18 = F_8 ( V_12 ) ;
int V_19 ;
int V_20 ;
T_1 V_6 ;
V_19 = V_4 -> V_21 . V_22 / V_23 ;
if ( V_14 -> V_24 [ 0 ] < V_19 )
V_19 = V_14 -> V_24 [ 0 ] ;
if ( F_9 ( V_2 ) )
V_19 = ( V_19 / 32 ) - 1 ;
else
V_19 = ( V_19 / 64 ) - 1 ;
for ( V_20 = 0 ; V_20 < ( V_23 / 32 ) + 1 ; V_20 ++ )
F_3 ( V_25 + ( V_20 * 4 ) , 0 ) ;
if ( F_10 ( V_2 ) ) {
T_1 V_26 ;
V_26 = V_27 | V_28 | V_29 ;
V_26 |= F_11 ( V_18 -> V_30 ) ;
F_3 ( V_31 , V_26 ) ;
F_3 ( V_32 , V_12 -> V_33 ) ;
}
V_6 = F_2 ( V_7 ) ;
V_6 &= 0x3fff << V_34 ;
V_6 |= V_8 | V_35 ;
if ( F_12 ( V_2 ) )
V_6 |= V_36 ;
V_6 |= ( V_19 & 0xff ) << V_37 ;
V_6 |= V_17 -> V_38 ;
F_3 ( V_7 , V_6 ) ;
F_5 ( L_3 ,
V_19 , V_12 -> V_33 , F_13 ( V_18 -> V_30 ) ) ;
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
struct V_18 * V_18 = F_8 ( V_12 ) ;
T_1 V_39 ;
V_39 = F_16 ( V_18 -> V_30 ) | V_40 ;
if ( F_17 ( V_14 -> V_41 , 0 ) == 2 )
V_39 |= V_42 ;
else
V_39 |= V_43 ;
V_39 |= V_44 | V_17 -> V_38 ;
F_3 ( V_45 , V_12 -> V_33 ) ;
F_3 ( V_46 , V_39 | V_47 ) ;
F_5 ( L_4 , F_13 ( V_18 -> V_30 ) ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_39 ;
V_39 = F_2 ( V_46 ) ;
if ( V_39 & V_47 ) {
V_39 &= ~ V_47 ;
F_3 ( V_46 , V_39 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_46 ) & V_47 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_48 ;
F_21 ( V_4 , V_49 ) ;
V_48 = F_2 ( V_50 ) ;
V_48 |= V_51 <<
V_52 ;
F_3 ( V_50 , V_48 ) ;
V_48 |= V_51 ;
F_3 ( V_50 , V_48 ) ;
V_48 &= ~ ( V_51 <<
V_52 ) ;
F_3 ( V_50 , V_48 ) ;
F_22 ( V_50 ) ;
F_23 ( V_4 , V_49 ) ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_15 -> V_14 ;
struct V_16 * V_17 = F_7 ( V_14 ) ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
T_1 V_39 ;
V_39 = F_16 ( V_18 -> V_30 ) ;
if ( F_17 ( V_14 -> V_41 , 0 ) == 2 )
V_4 -> V_21 . V_53 ++ ;
switch ( V_4 -> V_21 . V_53 ) {
case 4 :
case 3 :
V_39 |= V_54 ;
break;
case 2 :
V_39 |= V_42 ;
break;
case 1 :
V_39 |= V_43 ;
break;
}
V_39 |= V_44 ;
if ( F_25 ( V_2 ) )
V_39 |= V_17 -> V_38 ;
F_3 ( V_55 , V_12 -> V_33 ) ;
F_3 ( V_56 , F_26 ( V_17 ) | V_57 ) ;
F_3 ( V_58 , V_39 | V_47 ) ;
if ( F_27 ( V_2 ) ) {
F_3 ( V_59 ,
V_60 | V_17 -> V_38 ) ;
F_3 ( V_61 , V_12 -> V_33 ) ;
F_20 ( V_2 ) ;
}
F_5 ( L_4 , F_13 ( V_18 -> V_30 ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_39 ;
V_39 = F_2 ( V_58 ) ;
if ( V_39 & V_47 ) {
V_39 &= ~ V_47 ;
F_3 ( V_58 , V_39 ) ;
F_5 ( L_2 ) ;
}
}
static bool F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_58 ) & V_47 ;
}
static void F_30 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = V_12 -> V_15 -> V_14 ;
struct V_16 * V_17 = F_7 ( V_14 ) ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
T_1 V_39 ;
V_39 = F_31 ( V_18 -> V_30 ) ;
if ( F_17 ( V_14 -> V_41 , 0 ) == 2 )
V_4 -> V_21 . V_53 ++ ;
switch ( V_4 -> V_21 . V_53 ) {
case 4 :
case 3 :
V_39 |= V_54 ;
break;
case 2 :
V_39 |= V_42 ;
break;
case 1 :
V_39 |= V_43 ;
break;
}
V_39 |= V_62 ;
F_3 ( V_58 , V_39 | V_47 ) ;
if ( F_32 ( V_2 ) ) {
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 ) ;
} else {
F_3 ( F_33 ( V_18 -> V_65 ) ,
F_2 ( F_33 ( V_18 -> V_65 ) ) |
V_66 ) ;
}
F_3 ( V_59 ,
V_60 | V_17 -> V_38 ) ;
F_3 ( V_61 , V_12 -> V_33 ) ;
F_20 ( V_2 ) ;
F_5 ( L_4 , F_13 ( V_18 -> V_30 ) ) ;
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
if ( V_72 == V_4 -> V_21 . V_74 ) {
if ( V_72 -> V_12 -> V_15 -> V_14 == V_72 -> V_14 ) {
V_4 -> V_67 . V_75 ( V_72 -> V_12 ) ;
V_4 -> V_21 . V_30 = F_8 ( V_72 -> V_12 ) -> V_30 ;
V_4 -> V_21 . V_76 = V_72 -> V_12 -> V_15 -> V_14 -> V_77 . V_78 ;
V_4 -> V_21 . V_33 = V_72 -> V_12 -> V_33 ;
}
V_4 -> V_21 . V_74 = NULL ;
}
F_39 ( & V_2 -> V_73 ) ;
F_40 ( V_72 ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
if ( V_4 -> V_21 . V_74 == NULL )
return;
F_5 ( L_5 ) ;
if ( F_42 ( & V_4 -> V_21 . V_74 -> V_72 ) )
F_40 ( V_4 -> V_21 . V_74 ) ;
V_4 -> V_21 . V_74 = NULL ;
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
V_4 -> V_21 . V_74 = V_72 ;
F_47 ( & V_72 -> V_72 , F_48 ( 50 ) ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_41 ( V_4 ) ;
if ( ! V_4 -> V_67 . V_80 )
return;
V_4 -> V_67 . V_80 ( V_2 ) ;
V_4 -> V_21 . V_30 = - 1 ;
}
static bool F_50 ( struct V_3 * V_4 ,
enum V_81 V_82 )
{
if ( V_4 -> V_21 . V_81 == V_82 )
return false ;
V_4 -> V_21 . V_81 = V_82 ;
return true ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 = NULL , * V_83 ;
struct V_18 * V_18 ;
struct V_13 * V_14 ;
struct V_16 * V_17 ;
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
V_18 = F_8 ( V_12 ) ;
V_14 = V_12 -> V_15 -> V_14 ;
V_17 = F_7 ( V_14 ) ;
V_85 = & V_18 -> V_96 . V_85 ;
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
if ( F_55 ( V_2 ) -> V_102 >= 8 || F_56 ( V_2 ) ) {
V_86 = 4096 ;
V_87 = 4096 ;
} else if ( F_57 ( V_2 ) || F_55 ( V_2 ) -> V_102 >= 5 ) {
V_86 = 4096 ;
V_87 = 2048 ;
} else {
V_86 = 2048 ;
V_87 = 1536 ;
}
if ( V_18 -> V_96 . V_103 > V_86 ||
V_18 -> V_96 . V_104 > V_87 ) {
if ( F_50 ( V_4 , V_105 ) )
F_5 ( L_13 ) ;
goto V_94;
}
if ( ( F_55 ( V_2 ) -> V_102 < 4 || F_58 ( V_2 ) ) &&
V_18 -> V_30 != V_106 ) {
if ( F_50 ( V_4 , V_107 ) )
F_5 ( L_14 ) ;
goto V_94;
}
if ( V_17 -> V_108 != V_109 ||
V_17 -> V_38 == V_110 ) {
if ( F_50 ( V_4 , V_111 ) )
F_5 ( L_15 ) ;
goto V_94;
}
if ( F_59 () )
goto V_94;
if ( F_60 ( V_2 , V_17 -> V_77 . V_22 ,
F_17 ( V_14 -> V_41 , 0 ) ) ) {
if ( F_50 ( V_4 , V_112 ) )
F_5 ( L_16 ) ;
goto V_94;
}
if ( V_4 -> V_21 . V_30 == V_18 -> V_30 &&
V_4 -> V_21 . V_76 == V_14 -> V_77 . V_78 &&
V_4 -> V_21 . V_33 == V_12 -> V_33 )
return;
if ( F_34 ( V_2 ) ) {
F_5 ( L_17 ) ;
F_49 ( V_2 ) ;
}
F_43 ( V_12 ) ;
V_4 -> V_21 . V_81 = V_113 ;
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
int V_20 ;
if ( V_139 == 0 || V_140 == 0 )
return NULL ;
for ( V_20 = 0 ; V_20 < F_67 ( V_142 ) ; V_20 ++ ) {
V_141 = & V_142 [ V_20 ] ;
if ( V_138 == V_141 -> V_138 &&
V_128 == V_141 -> V_128 &&
V_139 == V_141 -> V_118 && V_140 == V_141 -> V_124 )
return V_141 ;
}
F_5 ( L_21 ) ;
return NULL ;
}
void F_68 ( struct V_3 * V_4 , bool V_143 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_144 ;
if ( F_69 ( V_2 ) ) {
F_3 ( V_145 , V_143 ? V_146 : 0 ) ;
} else if ( F_57 ( V_2 ) || F_70 ( V_2 ) ) {
F_3 ( V_147 , V_143 ? V_148 : 0 ) ;
} else if ( F_71 ( V_2 ) ) {
V_144 = F_2 ( V_149 ) & ~ V_150 ;
V_144 |= V_143 ? V_150 : 0 ;
F_3 ( V_149 , V_144 ) ;
} else if ( F_72 ( V_2 ) || F_12 ( V_2 ) ) {
V_144 = V_143 ? F_73 ( V_148 ) :
F_74 ( V_148 ) ;
F_3 ( V_147 , V_144 ) ;
} else if ( F_75 ( V_2 ) ) {
V_144 = V_143 ? F_73 ( V_151 ) :
F_74 ( V_151 ) ;
F_3 ( V_152 , V_144 ) ;
} else {
return;
}
F_5 ( L_22 ,
V_143 ? L_23 : L_24 ) ;
}
static int F_76 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_153 = F_2 ( V_154 ) ;
int V_22 ;
V_22 = V_153 & 0x7f ;
if ( V_30 )
V_22 = ( ( V_153 >> V_155 ) & 0x7f ) - V_22 ;
F_5 ( L_25 , V_153 ,
V_30 ? L_26 : L_27 , V_22 ) ;
return V_22 ;
}
static int F_77 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_153 = F_2 ( V_154 ) ;
int V_22 ;
V_22 = V_153 & 0x1ff ;
if ( V_30 )
V_22 = ( ( V_153 >> V_156 ) & 0x1ff ) - V_22 ;
V_22 >>= 1 ;
F_5 ( L_25 , V_153 ,
V_30 ? L_26 : L_27 , V_22 ) ;
return V_22 ;
}
static int F_78 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_153 = F_2 ( V_154 ) ;
int V_22 ;
V_22 = V_153 & 0x7f ;
V_22 >>= 2 ;
F_5 ( L_25 , V_153 ,
V_30 ? L_26 : L_27 ,
V_22 ) ;
return V_22 ;
}
static unsigned long F_79 ( unsigned long V_157 ,
const struct V_158 * V_159 ,
int V_160 ,
int V_161 ,
unsigned long V_162 )
{
long V_163 , V_164 ;
V_163 = ( ( V_157 / 1000 ) * V_161 * V_162 ) /
1000 ;
V_163 = F_80 ( V_163 , V_159 -> V_165 ) ;
F_5 ( L_28 , V_163 ) ;
V_164 = V_160 - ( V_163 + V_159 -> V_166 ) ;
F_5 ( L_29 , V_164 ) ;
if ( V_164 > ( long ) V_159 -> V_167 )
V_164 = V_159 -> V_167 ;
if ( V_164 <= 0 )
V_164 = V_159 -> V_168 ;
return V_164 ;
}
static struct V_11 * F_81 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_169 = NULL ;
F_53 (dev, crtc) {
if ( F_54 ( V_12 ) ) {
if ( V_169 )
return NULL ;
V_169 = V_12 ;
}
}
return V_169 ;
}
static void F_82 ( struct V_11 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_137 * V_141 ;
T_1 V_171 ;
unsigned long V_159 ;
V_141 = F_66 ( F_83 ( V_2 ) , V_4 -> V_128 ,
V_4 -> V_118 , V_4 -> V_124 ) ;
if ( ! V_141 ) {
F_5 ( L_21 ) ;
F_68 ( V_4 , false ) ;
return;
}
V_12 = F_81 ( V_2 ) ;
if ( V_12 ) {
const struct V_84 * V_85 ;
int V_161 = V_12 -> V_15 -> V_14 -> V_172 / 8 ;
int clock ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
clock = V_85 -> V_173 ;
V_159 = F_79 ( clock , & V_174 ,
V_174 . V_160 ,
V_161 , V_141 -> V_175 ) ;
V_171 = F_2 ( V_176 ) ;
V_171 &= ~ V_177 ;
V_171 |= V_159 << V_178 ;
F_3 ( V_176 , V_171 ) ;
F_5 ( L_30 , V_171 ) ;
V_159 = F_79 ( clock , & V_179 ,
V_174 . V_160 ,
V_161 , V_141 -> V_180 ) ;
V_171 = F_2 ( V_149 ) ;
V_171 &= ~ V_181 ;
V_171 |= ( V_159 & 0x3f ) << V_182 ;
F_3 ( V_149 , V_171 ) ;
V_159 = F_79 ( clock , & V_183 ,
V_183 . V_160 ,
V_161 , V_141 -> V_184 ) ;
V_171 = F_2 ( V_149 ) ;
V_171 &= ~ V_185 ;
V_171 |= V_159 & V_185 ;
F_3 ( V_149 , V_171 ) ;
V_159 = F_79 ( clock , & V_186 ,
V_183 . V_160 ,
V_161 , V_141 -> V_187 ) ;
V_171 = F_2 ( V_149 ) ;
V_171 &= ~ V_188 ;
V_171 |= ( V_159 & 0x3f ) << V_189 ;
F_3 ( V_149 , V_171 ) ;
F_5 ( L_31 , V_171 ) ;
F_68 ( V_4 , true ) ;
} else {
F_68 ( V_4 , false ) ;
}
}
static bool F_84 ( struct V_1 * V_2 ,
int V_30 ,
const struct V_158 * V_67 ,
int V_190 ,
const struct V_158 * V_191 ,
int V_192 ,
int * V_193 ,
int * V_194 )
{
struct V_11 * V_12 ;
const struct V_84 * V_85 ;
int V_195 , V_196 , clock , V_161 ;
int V_197 , V_198 ;
int V_199 , V_200 ;
V_12 = F_85 ( V_2 , V_30 ) ;
if ( ! F_54 ( V_12 ) ) {
* V_194 = V_191 -> V_166 ;
* V_193 = V_67 -> V_166 ;
return false ;
}
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
clock = V_85 -> V_173 ;
V_195 = V_85 -> V_201 ;
V_196 = F_8 ( V_12 ) -> V_96 . V_103 ;
V_161 = V_12 -> V_15 -> V_14 -> V_172 / 8 ;
V_199 = ( ( clock * V_161 / 1000 ) * V_190 ) / 1000 ;
V_200 = V_67 -> V_160 * V_67 -> V_165 - V_196 * 8 ;
if ( V_200 > 0 )
V_199 += V_200 ;
V_199 = F_80 ( V_199 , V_67 -> V_165 ) ;
* V_193 = V_199 + V_67 -> V_166 ;
if ( * V_193 > ( int ) V_67 -> V_167 )
* V_193 = V_67 -> V_167 ;
V_197 = F_86 ( V_195 * 1000 / clock , 1 ) ;
V_198 = ( V_192 / V_197 + 1000 ) / 1000 ;
V_199 = V_198 * F_8 ( V_12 ) -> V_202 * V_161 ;
V_200 = V_191 -> V_160 * V_191 -> V_165 - V_196 * 8 ;
if ( V_200 > 0 )
V_199 += V_200 ;
V_199 = F_80 ( V_199 , V_191 -> V_165 ) ;
* V_194 = V_199 + V_191 -> V_166 ;
if ( * V_194 > ( int ) V_191 -> V_167 )
* V_194 = ( int ) V_191 -> V_167 ;
return true ;
}
static bool F_87 ( struct V_1 * V_2 ,
int V_203 , int V_194 ,
const struct V_158 * V_67 ,
const struct V_158 * V_191 )
{
F_5 ( L_32 ,
V_203 , V_194 ) ;
if ( V_203 > V_67 -> V_167 ) {
F_5 ( L_33 ,
V_203 , V_67 -> V_167 ) ;
return false ;
}
if ( V_194 > V_191 -> V_167 ) {
F_5 ( L_34 ,
V_194 , V_191 -> V_167 ) ;
return false ;
}
if ( ! ( V_203 || V_194 ) ) {
F_5 ( L_35 ) ;
return false ;
}
return true ;
}
static bool F_88 ( struct V_1 * V_2 ,
int V_30 ,
int V_162 ,
const struct V_158 * V_67 ,
const struct V_158 * V_191 ,
int * V_203 , int * V_194 )
{
struct V_11 * V_12 ;
const struct V_84 * V_85 ;
int V_196 , V_195 , V_161 , clock ;
unsigned long V_197 ;
int V_198 , V_204 ;
int V_205 , V_206 ;
int V_199 ;
if ( ! V_162 ) {
* V_203 = * V_194 = 0 ;
return false ;
}
V_12 = F_85 ( V_2 , V_30 ) ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
clock = V_85 -> V_173 ;
V_195 = V_85 -> V_201 ;
V_196 = F_8 ( V_12 ) -> V_96 . V_103 ;
V_161 = V_12 -> V_15 -> V_14 -> V_172 / 8 ;
V_197 = F_86 ( V_195 * 1000 / clock , 1 ) ;
V_198 = ( V_162 / V_197 + 1000 ) / 1000 ;
V_204 = V_196 * V_161 ;
V_205 = ( ( clock * V_161 / 1000 ) * V_162 ) / 1000 ;
V_206 = V_198 * V_204 ;
V_199 = F_80 ( F_89 ( V_205 , V_206 ) , V_67 -> V_165 ) ;
* V_203 = V_199 + V_67 -> V_166 ;
V_199 = V_198 * V_161 * F_8 ( V_12 ) -> V_202 ;
V_199 = F_80 ( V_199 , V_191 -> V_165 ) ;
* V_194 = V_199 + V_191 -> V_166 ;
return F_87 ( V_2 ,
* V_203 , * V_194 ,
V_67 , V_191 ) ;
}
static bool F_90 ( struct V_1 * V_2 ,
int V_30 ,
int * V_207 ,
int * V_208 ,
int * V_209 ,
int * V_210 )
{
struct V_11 * V_12 ;
int clock , V_161 ;
int V_199 ;
V_12 = F_85 ( V_2 , V_30 ) ;
if ( ! F_54 ( V_12 ) )
return false ;
clock = F_8 ( V_12 ) -> V_96 . V_85 . V_173 ;
V_161 = V_12 -> V_15 -> V_14 -> V_172 / 8 ;
V_199 = ( clock / 1000 ) * V_161 ;
* V_207 = ( V_199 > 128 ) ?
V_211 : V_212 ;
* V_208 = ( 64 * ( * V_207 ) * 4 ) / V_199 ;
V_199 = ( clock / 1000 ) * 4 ;
* V_209 = ( V_199 > 128 ) ?
V_211 : V_212 ;
* V_210 = ( 64 * ( * V_209 ) * 4 ) / V_199 ;
return true ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_213 , V_214 , V_215 , V_216 ;
int V_217 , V_218 , V_219 , V_220 ;
int V_207 , V_209 ;
if ( F_90 ( V_2 , 0 , & V_207 , & V_214 ,
& V_209 , & V_218 ) ) {
V_217 = ( V_209 == V_212 ) ?
V_221 : V_222 ;
V_213 = ( V_207 == V_212 ) ?
V_223 : V_224 ;
F_3 ( V_225 , V_217 |
( V_218 << V_226 ) |
V_213 | V_214 ) ;
}
if ( F_90 ( V_2 , 1 , & V_207 , & V_216 ,
& V_209 , & V_220 ) ) {
V_219 = ( V_209 == V_212 ) ?
V_227 : V_228 ;
V_215 = ( V_207 == V_212 ) ?
V_229 : V_230 ;
F_3 ( V_231 , V_219 |
( V_220 << V_232 ) |
V_215 | V_216 ) ;
}
}
static void F_92 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_233 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_234 , V_235 , V_236 , V_237 ;
int V_238 , V_180 ;
int V_239 , V_240 ;
unsigned int V_169 = 0 ;
bool V_241 ;
F_91 ( V_2 ) ;
if ( F_84 ( V_2 , V_242 ,
& V_243 , V_162 ,
& V_244 , V_162 ,
& V_234 , & V_236 ) )
V_169 |= 1 << V_242 ;
if ( F_84 ( V_2 , V_245 ,
& V_243 , V_162 ,
& V_244 , V_162 ,
& V_235 , & V_237 ) )
V_169 |= 1 << V_245 ;
if ( F_93 ( V_169 ) &&
F_88 ( V_2 , F_94 ( V_169 ) - 1 ,
V_233 ,
& V_243 ,
& V_244 ,
& V_238 , & V_240 ) &&
F_88 ( V_2 , F_94 ( V_169 ) - 1 ,
2 * V_233 ,
& V_243 ,
& V_244 ,
& V_239 , & V_180 ) ) {
V_241 = true ;
} else {
V_241 = false ;
F_68 ( V_4 , false ) ;
V_238 = V_180 = 0 ;
}
F_5 ( L_36 ,
V_234 , V_236 ,
V_235 , V_237 ,
V_238 , V_180 ) ;
F_3 ( V_176 ,
( V_238 << V_178 ) |
( V_237 << V_246 ) |
( V_235 << V_247 ) |
V_234 ) ;
F_3 ( V_248 ,
( F_2 ( V_248 ) & ~ V_249 ) |
( V_236 << V_250 ) ) ;
F_3 ( V_149 ,
( F_2 ( V_149 ) & ~ V_181 ) |
( V_180 << V_182 ) ) ;
if ( V_241 )
F_68 ( V_4 , true ) ;
}
static void F_95 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_233 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_234 , V_235 , V_236 , V_237 ;
int V_238 , V_180 ;
unsigned int V_169 = 0 ;
bool V_241 ;
if ( F_84 ( V_2 , V_242 ,
& V_251 , V_162 ,
& V_252 , V_162 ,
& V_234 , & V_236 ) )
V_169 |= 1 << V_242 ;
if ( F_84 ( V_2 , V_245 ,
& V_251 , V_162 ,
& V_252 , V_162 ,
& V_235 , & V_237 ) )
V_169 |= 1 << V_245 ;
if ( F_93 ( V_169 ) &&
F_88 ( V_2 , F_94 ( V_169 ) - 1 ,
V_233 ,
& V_251 ,
& V_252 ,
& V_238 , & V_180 ) ) {
V_241 = true ;
} else {
V_241 = false ;
F_68 ( V_4 , false ) ;
V_238 = V_180 = 0 ;
}
F_5 ( L_36 ,
V_234 , V_236 ,
V_235 , V_237 ,
V_238 , V_180 ) ;
F_3 ( V_176 ,
( V_238 << V_178 ) |
( V_237 << V_246 ) |
( V_235 << V_247 ) |
V_234 ) ;
F_3 ( V_248 ,
( F_2 ( V_248 ) & ~ V_249 ) |
( V_236 << V_250 ) ) ;
F_3 ( V_149 ,
( F_2 ( V_149 ) & ~ ( V_253 | V_181 ) ) |
( V_180 << V_182 ) ) ;
if ( V_241 )
F_68 ( V_4 , true ) ;
}
static void F_96 ( struct V_11 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
int V_254 = 1 ;
int V_180 = 16 ;
bool V_241 ;
V_12 = F_81 ( V_2 ) ;
if ( V_12 ) {
static const int V_233 = 12000 ;
const struct V_84 * V_85 =
& F_8 ( V_12 ) -> V_96 . V_85 ;
int clock = V_85 -> V_173 ;
int V_195 = V_85 -> V_201 ;
int V_196 = F_8 ( V_12 ) -> V_96 . V_103 ;
int V_161 = V_12 -> V_15 -> V_14 -> V_172 / 8 ;
unsigned long V_197 ;
int V_199 ;
V_197 = F_86 ( V_195 * 1000 / clock , 1 ) ;
V_199 = ( ( ( V_233 / V_197 ) + 1000 ) / 1000 ) *
V_161 * V_196 ;
V_199 = F_80 ( V_199 , V_255 ) ;
V_254 = V_256 - V_199 ;
if ( V_254 < 0 )
V_254 = 1 ;
V_254 &= 0x1ff ;
F_5 ( L_37 ,
V_199 , V_254 ) ;
V_199 = ( ( ( V_233 / V_197 ) + 1000 ) / 1000 ) *
V_161 * F_8 ( V_12 ) -> V_202 ;
V_199 = F_80 ( V_199 ,
V_257 . V_165 ) ;
V_180 = V_257 . V_160 -
( V_199 + V_257 . V_166 ) ;
if ( V_180 > V_257 . V_167 )
V_180 = V_257 . V_167 ;
F_5 ( L_38
L_39 , V_254 , V_180 ) ;
V_241 = true ;
} else {
V_241 = false ;
F_68 ( V_4 , false ) ;
}
F_5 ( L_40 ,
V_254 ) ;
F_3 ( V_176 , ( V_254 << V_178 ) |
( 8 << 16 ) | ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_3 ( V_248 , ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_3 ( V_149 , ( V_180 << V_182 ) ) ;
if ( V_241 )
F_68 ( V_4 , true ) ;
}
static void F_97 ( struct V_11 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_158 * V_258 ;
T_3 V_259 ;
T_3 V_260 ;
int V_261 , V_254 = 1 ;
int V_160 ;
int V_234 , V_235 ;
struct V_11 * V_12 , * V_169 = NULL ;
if ( F_12 ( V_2 ) )
V_258 = & V_262 ;
else if ( ! F_9 ( V_2 ) )
V_258 = & V_263 ;
else
V_258 = & V_264 ;
V_160 = V_4 -> V_67 . V_265 ( V_2 , 0 ) ;
V_12 = F_85 ( V_2 , 0 ) ;
if ( F_54 ( V_12 ) ) {
const struct V_84 * V_85 ;
int V_266 = V_12 -> V_15 -> V_14 -> V_172 / 8 ;
if ( F_9 ( V_2 ) )
V_266 = 4 ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_234 = F_79 ( V_85 -> V_173 ,
V_258 , V_160 , V_266 ,
V_162 ) ;
V_169 = V_12 ;
} else
V_234 = V_160 - V_258 -> V_166 ;
V_160 = V_4 -> V_67 . V_265 ( V_2 , 1 ) ;
V_12 = F_85 ( V_2 , 1 ) ;
if ( F_54 ( V_12 ) ) {
const struct V_84 * V_85 ;
int V_266 = V_12 -> V_15 -> V_14 -> V_172 / 8 ;
if ( F_9 ( V_2 ) )
V_266 = 4 ;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_235 = F_79 ( V_85 -> V_173 ,
V_258 , V_160 , V_266 ,
V_162 ) ;
if ( V_169 == NULL )
V_169 = V_12 ;
else
V_169 = NULL ;
} else
V_235 = V_160 - V_258 -> V_166 ;
F_5 ( L_41 , V_234 , V_235 ) ;
if ( F_75 ( V_2 ) && V_169 ) {
struct V_16 * V_17 ;
V_17 = F_7 ( V_169 -> V_15 -> V_14 ) ;
if ( V_17 -> V_108 == V_267 )
V_169 = NULL ;
}
V_261 = 2 ;
F_68 ( V_4 , false ) ;
if ( F_98 ( V_2 ) && V_169 ) {
static const int V_233 = 6000 ;
const struct V_84 * V_85 =
& F_8 ( V_169 ) -> V_96 . V_85 ;
int clock = V_85 -> V_173 ;
int V_195 = V_85 -> V_201 ;
int V_196 = F_8 ( V_169 ) -> V_96 . V_103 ;
int V_161 = V_169 -> V_15 -> V_14 -> V_172 / 8 ;
unsigned long V_197 ;
int V_199 ;
V_197 = F_86 ( V_195 * 1000 / clock , 1 ) ;
V_199 = ( ( ( V_233 / V_197 ) + 1000 ) / 1000 ) *
V_161 * V_196 ;
V_199 = F_80 ( V_199 , V_258 -> V_165 ) ;
F_5 ( L_42 , V_199 ) ;
V_254 = V_258 -> V_160 - V_199 ;
if ( V_254 < 0 )
V_254 = 1 ;
if ( F_72 ( V_2 ) || F_12 ( V_2 ) )
F_3 ( V_147 ,
V_268 | ( V_254 & 0xff ) ) ;
else if ( F_75 ( V_2 ) )
F_3 ( V_147 , V_254 & 0x3f ) ;
}
F_5 ( L_43 ,
V_234 , V_235 , V_261 , V_254 ) ;
V_259 = ( ( V_235 & 0x3f ) << 16 ) | ( V_234 & 0x3f ) ;
V_260 = ( V_261 & 0x1f ) ;
V_259 = V_259 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_260 = V_260 | ( 1 << 8 ) ;
F_3 ( V_269 , V_259 ) ;
F_3 ( V_270 , V_260 ) ;
if ( V_169 )
F_68 ( V_4 , true ) ;
}
static void F_99 ( struct V_11 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_84 * V_85 ;
T_3 V_259 ;
int V_234 ;
V_12 = F_81 ( V_2 ) ;
if ( V_12 == NULL )
return;
V_85 = & F_8 ( V_12 ) -> V_96 . V_85 ;
V_234 = F_79 ( V_85 -> V_173 ,
& V_271 ,
V_4 -> V_67 . V_265 ( V_2 , 0 ) ,
4 , V_162 ) ;
V_259 = F_2 ( V_269 ) & ~ 0xfff ;
V_259 |= ( 3 << 8 ) | V_234 ;
F_5 ( L_44 , V_234 ) ;
F_3 ( V_269 , V_259 ) ;
}
static T_3 F_100 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_18 * V_18 = F_8 ( V_12 ) ;
T_3 V_272 ;
V_272 = V_18 -> V_96 . V_85 . V_173 ;
if ( V_18 -> V_96 . V_273 . V_169 ) {
T_4 V_274 , V_275 , V_276 , V_277 ;
T_3 V_278 = V_18 -> V_96 . V_273 . V_22 ;
V_274 = V_18 -> V_96 . V_103 ;
V_275 = V_18 -> V_96 . V_104 ;
V_276 = ( V_278 >> 16 ) & 0xFFFF ;
V_277 = V_278 & 0xFFFF ;
if ( V_274 < V_276 )
V_274 = V_276 ;
if ( V_275 < V_277 )
V_275 = V_277 ;
V_272 = F_101 ( ( T_4 ) V_272 * V_274 * V_275 ,
V_276 * V_277 ) ;
}
return V_272 ;
}
static T_3 F_102 ( T_3 V_272 , T_5 V_279 ,
T_3 V_141 )
{
T_4 V_280 ;
if ( F_103 ( V_141 == 0 , L_45 ) )
return V_281 ;
V_280 = ( T_4 ) V_272 * V_279 * V_141 ;
V_280 = F_104 ( V_280 , 64 * 10000 ) + 2 ;
return V_280 ;
}
static T_3 F_105 ( T_3 V_272 , T_3 V_282 ,
T_3 V_283 , T_5 V_279 ,
T_3 V_141 )
{
T_3 V_280 ;
if ( F_103 ( V_141 == 0 , L_45 ) )
return V_281 ;
V_280 = ( V_141 * V_272 ) / ( V_282 * 10000 ) ;
V_280 = ( V_280 + 1 ) * V_283 * V_279 ;
V_280 = F_80 ( V_280 , 64 ) + 2 ;
return V_280 ;
}
static T_3 F_106 ( T_3 V_284 , T_3 V_283 ,
T_5 V_279 )
{
return F_80 ( V_284 * 64 , V_283 * V_279 ) + 2 ;
}
static T_3 F_107 ( const struct V_285 * V_286 ,
T_3 V_287 ,
bool V_288 )
{
T_3 V_289 , V_290 ;
if ( ! V_286 -> V_291 || ! V_286 -> V_292 . V_169 )
return 0 ;
V_289 = F_102 ( V_286 -> V_272 ,
V_286 -> V_292 . V_279 ,
V_287 ) ;
if ( ! V_288 )
return V_289 ;
V_290 = F_105 ( V_286 -> V_272 ,
V_286 -> V_282 ,
V_286 -> V_292 . V_283 ,
V_286 -> V_292 . V_279 ,
V_287 ) ;
return F_89 ( V_289 , V_290 ) ;
}
static T_3 F_108 ( const struct V_285 * V_286 ,
T_3 V_287 )
{
T_3 V_289 , V_290 ;
if ( ! V_286 -> V_291 || ! V_286 -> V_293 . V_169 )
return 0 ;
V_289 = F_102 ( V_286 -> V_272 ,
V_286 -> V_293 . V_279 ,
V_287 ) ;
V_290 = F_105 ( V_286 -> V_272 ,
V_286 -> V_282 ,
V_286 -> V_293 . V_283 ,
V_286 -> V_293 . V_279 ,
V_287 ) ;
return F_89 ( V_289 , V_290 ) ;
}
static T_3 F_109 ( const struct V_285 * V_286 ,
T_3 V_287 )
{
if ( ! V_286 -> V_291 || ! V_286 -> V_294 . V_169 )
return 0 ;
return F_105 ( V_286 -> V_272 ,
V_286 -> V_282 ,
V_286 -> V_294 . V_283 ,
V_286 -> V_294 . V_279 ,
V_287 ) ;
}
static T_3 F_110 ( const struct V_285 * V_286 ,
T_3 V_284 )
{
if ( ! V_286 -> V_291 || ! V_286 -> V_292 . V_169 )
return 0 ;
return F_106 ( V_284 ,
V_286 -> V_292 . V_283 ,
V_286 -> V_292 . V_279 ) ;
}
static unsigned int F_111 ( const struct V_1 * V_2 )
{
if ( F_55 ( V_2 ) -> V_102 >= 8 )
return 3072 ;
else if ( F_55 ( V_2 ) -> V_102 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_112 ( const struct V_1 * V_2 ,
int V_295 , bool V_296 )
{
if ( F_55 ( V_2 ) -> V_102 >= 8 )
return V_295 == 0 ? 255 : 2047 ;
else if ( F_55 ( V_2 ) -> V_102 >= 7 )
return V_295 == 0 ? 127 : 1023 ;
else if ( ! V_296 )
return V_295 == 0 ? 127 : 511 ;
else
return V_295 == 0 ? 63 : 255 ;
}
static unsigned int F_113 ( const struct V_1 * V_2 ,
int V_295 )
{
if ( F_55 ( V_2 ) -> V_102 >= 7 )
return V_295 == 0 ? 63 : 255 ;
else
return V_295 == 0 ? 31 : 63 ;
}
static unsigned int F_114 ( const struct V_1 * V_2 )
{
if ( F_55 ( V_2 ) -> V_102 >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_115 ( const struct V_1 * V_2 ,
int V_295 ,
const struct V_297 * V_96 ,
enum V_298 V_299 ,
bool V_296 )
{
unsigned int V_160 = F_111 ( V_2 ) ;
if ( V_296 && ! V_96 -> V_300 )
return 0 ;
if ( V_295 == 0 || V_96 -> V_301 > 1 ) {
V_160 /= F_55 ( V_2 ) -> V_302 ;
if ( F_55 ( V_2 ) -> V_102 <= 6 )
V_160 /= 2 ;
}
if ( V_96 -> V_300 ) {
if ( V_295 > 0 && V_299 == V_303 ) {
if ( V_296 )
V_160 *= 5 ;
V_160 /= 6 ;
} else {
V_160 /= 2 ;
}
}
return F_89 ( V_160 , F_112 ( V_2 , V_295 , V_296 ) ) ;
}
static unsigned int F_116 ( const struct V_1 * V_2 ,
int V_295 ,
const struct V_297 * V_96 )
{
if ( V_295 > 0 && V_96 -> V_301 > 1 )
return 64 ;
return F_113 ( V_2 , V_295 ) ;
}
static void F_117 ( const struct V_1 * V_2 ,
int V_295 ,
const struct V_297 * V_96 ,
enum V_298 V_299 ,
struct V_304 * F_86 )
{
F_86 -> V_292 = F_115 ( V_2 , V_295 , V_96 , V_299 , false ) ;
F_86 -> V_293 = F_115 ( V_2 , V_295 , V_96 , V_299 , true ) ;
F_86 -> V_294 = F_116 ( V_2 , V_295 , V_96 ) ;
F_86 -> V_21 = F_114 ( V_2 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
int V_295 ,
struct V_304 * F_86 )
{
F_86 -> V_292 = F_112 ( V_2 , V_295 , false ) ;
F_86 -> V_293 = F_112 ( V_2 , V_295 , true ) ;
F_86 -> V_294 = F_113 ( V_2 , V_295 ) ;
F_86 -> V_21 = F_114 ( V_2 ) ;
}
static bool F_119 ( int V_295 ,
const struct V_304 * F_86 ,
struct V_305 * V_306 )
{
bool V_280 ;
if ( ! V_306 -> V_143 )
return false ;
V_306 -> V_143 = V_306 -> V_284 <= F_86 -> V_292 &&
V_306 -> V_307 <= F_86 -> V_293 &&
V_306 -> V_308 <= F_86 -> V_294 ;
V_280 = V_306 -> V_143 ;
if ( V_295 == 0 && ! V_306 -> V_143 ) {
if ( V_306 -> V_284 > F_86 -> V_292 )
F_5 ( L_46 ,
V_295 , V_306 -> V_284 , F_86 -> V_292 ) ;
if ( V_306 -> V_307 > F_86 -> V_293 )
F_5 ( L_47 ,
V_295 , V_306 -> V_307 , F_86 -> V_293 ) ;
if ( V_306 -> V_308 > F_86 -> V_294 )
F_5 ( L_48 ,
V_295 , V_306 -> V_308 , F_86 -> V_294 ) ;
V_306 -> V_284 = F_120 ( T_3 , V_306 -> V_284 , F_86 -> V_292 ) ;
V_306 -> V_307 = F_120 ( T_3 , V_306 -> V_307 , F_86 -> V_293 ) ;
V_306 -> V_308 = F_120 ( T_3 , V_306 -> V_308 , F_86 -> V_294 ) ;
V_306 -> V_143 = true ;
}
return V_280 ;
}
static void F_121 ( const struct V_3 * V_4 ,
int V_295 ,
const struct V_285 * V_309 ,
struct V_305 * V_306 )
{
T_6 V_310 = V_4 -> V_159 . V_310 [ V_295 ] ;
T_6 V_311 = V_4 -> V_159 . V_311 [ V_295 ] ;
T_6 V_312 = V_4 -> V_159 . V_312 [ V_295 ] ;
if ( V_295 > 0 ) {
V_310 *= 5 ;
V_311 *= 5 ;
V_312 *= 5 ;
}
V_306 -> V_284 = F_107 ( V_309 , V_310 , V_295 ) ;
V_306 -> V_307 = F_108 ( V_309 , V_311 ) ;
V_306 -> V_308 = F_109 ( V_309 , V_312 ) ;
V_306 -> V_313 = F_110 ( V_309 , V_306 -> V_284 ) ;
V_306 -> V_143 = true ;
}
static T_3
F_122 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
struct V_84 * V_314 = & V_18 -> V_96 . V_85 ;
T_1 V_315 , V_316 ;
if ( ! F_54 ( V_12 ) )
return 0 ;
V_315 = F_123 ( V_314 -> V_201 * 1000 * 8 ,
V_314 -> V_173 ) ;
V_316 = F_123 ( V_314 -> V_201 * 1000 * 8 ,
F_124 ( V_4 ) ) ;
return F_125 ( V_316 ) |
F_126 ( V_315 ) ;
}
static void F_127 ( struct V_1 * V_2 , T_6 V_159 [ 5 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_56 ( V_2 ) || F_128 ( V_2 ) ) {
T_4 V_317 = F_129 ( V_318 ) ;
V_159 [ 0 ] = ( V_317 >> 56 ) & 0xFF ;
if ( V_159 [ 0 ] == 0 )
V_159 [ 0 ] = V_317 & 0xF ;
V_159 [ 1 ] = ( V_317 >> 4 ) & 0xFF ;
V_159 [ 2 ] = ( V_317 >> 12 ) & 0xFF ;
V_159 [ 3 ] = ( V_317 >> 20 ) & 0x1FF ;
V_159 [ 4 ] = ( V_317 >> 32 ) & 0x1FF ;
} else if ( F_55 ( V_2 ) -> V_102 >= 6 ) {
T_3 V_317 = F_2 ( V_318 ) ;
V_159 [ 0 ] = ( V_317 >> V_319 ) & V_320 ;
V_159 [ 1 ] = ( V_317 >> V_321 ) & V_320 ;
V_159 [ 2 ] = ( V_317 >> V_322 ) & V_320 ;
V_159 [ 3 ] = ( V_317 >> V_323 ) & V_320 ;
} else if ( F_55 ( V_2 ) -> V_102 >= 5 ) {
T_3 V_324 = F_2 ( V_325 ) ;
V_159 [ 0 ] = 7 ;
V_159 [ 1 ] = ( V_324 >> V_326 ) & V_327 ;
V_159 [ 2 ] = ( V_324 >> V_328 ) & V_327 ;
}
}
static void F_130 ( struct V_1 * V_2 , T_6 V_159 [ 5 ] )
{
if ( F_55 ( V_2 ) -> V_102 == 5 )
V_159 [ 0 ] = 13 ;
}
static void F_131 ( struct V_1 * V_2 , T_6 V_159 [ 5 ] )
{
if ( F_55 ( V_2 ) -> V_102 == 5 )
V_159 [ 0 ] = 13 ;
if ( F_32 ( V_2 ) )
V_159 [ 3 ] *= 2 ;
}
int F_132 ( const struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) || F_128 ( V_2 ) )
return 4 ;
else if ( F_55 ( V_2 ) -> V_102 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_133 ( struct V_1 * V_2 ,
const char * V_329 ,
const T_6 V_159 [ 5 ] )
{
int V_295 , V_330 = F_132 ( V_2 ) ;
for ( V_295 = 0 ; V_295 <= V_330 ; V_295 ++ ) {
unsigned int V_141 = V_159 [ V_295 ] ;
if ( V_141 == 0 ) {
F_45 ( L_49 ,
V_329 , V_295 ) ;
continue;
}
if ( V_295 > 0 )
V_141 *= 5 ;
F_5 ( L_50 ,
V_329 , V_295 , V_159 [ V_295 ] ,
V_141 / 10 , V_141 % 10 ) ;
}
}
static bool F_134 ( struct V_3 * V_4 ,
T_6 V_159 [ 5 ] , T_6 F_89 )
{
int V_295 , V_330 = F_132 ( V_4 -> V_2 ) ;
if ( V_159 [ 0 ] >= F_89 )
return false ;
V_159 [ 0 ] = F_86 ( V_159 [ 0 ] , F_89 ) ;
for ( V_295 = 1 ; V_295 <= V_330 ; V_295 ++ )
V_159 [ V_295 ] = F_135 ( T_6 , V_159 [ V_295 ] , F_80 ( F_89 , 5 ) ) ;
return true ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_331 ;
V_331 = F_134 ( V_4 , V_4 -> V_159 . V_310 , 12 ) |
F_134 ( V_4 , V_4 -> V_159 . V_311 , 12 ) |
F_134 ( V_4 , V_4 -> V_159 . V_312 , 12 ) ;
if ( ! V_331 )
return;
F_5 ( L_51 ) ;
F_133 ( V_2 , L_52 , V_4 -> V_159 . V_310 ) ;
F_133 ( V_2 , L_53 , V_4 -> V_159 . V_311 ) ;
F_133 ( V_2 , L_54 , V_4 -> V_159 . V_312 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_127 ( V_2 , V_4 -> V_159 . V_310 ) ;
memcpy ( V_4 -> V_159 . V_311 , V_4 -> V_159 . V_310 ,
sizeof( V_4 -> V_159 . V_310 ) ) ;
memcpy ( V_4 -> V_159 . V_312 , V_4 -> V_159 . V_310 ,
sizeof( V_4 -> V_159 . V_310 ) ) ;
F_130 ( V_2 , V_4 -> V_159 . V_311 ) ;
F_131 ( V_2 , V_4 -> V_159 . V_312 ) ;
F_133 ( V_2 , L_52 , V_4 -> V_159 . V_310 ) ;
F_133 ( V_2 , L_53 , V_4 -> V_159 . V_311 ) ;
F_133 ( V_2 , L_54 , V_4 -> V_159 . V_312 ) ;
if ( F_27 ( V_2 ) )
F_136 ( V_2 ) ;
}
static void F_138 ( struct V_11 * V_12 ,
struct V_285 * V_309 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
enum V_65 V_65 = V_18 -> V_65 ;
struct V_332 * V_30 ;
if ( ! F_54 ( V_12 ) )
return;
V_309 -> V_291 = true ;
V_309 -> V_282 = V_18 -> V_96 . V_85 . V_201 ;
V_309 -> V_272 = F_100 ( V_2 , V_12 ) ;
V_309 -> V_292 . V_279 = V_12 -> V_15 -> V_14 -> V_172 / 8 ;
V_309 -> V_294 . V_279 = 4 ;
V_309 -> V_292 . V_283 = V_18 -> V_96 . V_103 ;
V_309 -> V_294 . V_283 = V_18 -> V_202 ;
V_309 -> V_292 . V_169 = true ;
V_309 -> V_294 . V_169 = true ;
F_139 (plane, &dev->mode_config.plane_list) {
struct V_333 * V_333 = F_140 ( V_30 ) ;
if ( V_333 -> V_65 == V_65 ) {
V_309 -> V_293 = V_333 -> V_159 ;
break;
}
}
}
static void F_141 ( struct V_1 * V_2 ,
struct V_297 * V_96 )
{
struct V_18 * V_18 ;
F_142 (dev, intel_crtc) {
const struct V_334 * V_159 = & V_18 -> V_159 . V_291 ;
if ( ! V_159 -> V_335 )
continue;
V_96 -> V_300 |= V_159 -> V_300 ;
V_96 -> V_336 |= V_159 -> V_336 ;
V_96 -> V_301 ++ ;
}
}
static bool F_143 ( struct V_11 * V_12 ,
const struct V_285 * V_286 ,
struct V_334 * V_337 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
int V_295 , V_330 = F_132 ( V_2 ) ;
struct V_297 V_96 = {
. V_301 = 1 ,
. V_300 = V_286 -> V_293 . V_169 ,
. V_336 = V_286 -> V_293 . V_338 ,
} ;
struct V_304 F_86 ;
V_337 -> V_335 = V_286 -> V_291 ;
V_337 -> V_300 = V_286 -> V_293 . V_169 ;
V_337 -> V_336 = V_286 -> V_293 . V_338 ;
if ( F_55 ( V_2 ) -> V_102 <= 6 && V_286 -> V_293 . V_169 )
V_330 = 1 ;
if ( V_286 -> V_293 . V_338 )
V_330 = 0 ;
F_121 ( V_4 , 0 , V_286 , & V_337 -> V_159 [ 0 ] ) ;
if ( F_56 ( V_2 ) || F_128 ( V_2 ) )
V_337 -> V_315 = F_122 ( V_2 , V_12 ) ;
F_117 ( V_2 , 0 , & V_96 , V_339 , & F_86 ) ;
if ( ! F_119 ( 0 , & F_86 , & V_337 -> V_159 [ 0 ] ) )
return false ;
F_118 ( V_2 , 1 , & F_86 ) ;
for ( V_295 = 1 ; V_295 <= V_330 ; V_295 ++ ) {
struct V_305 V_159 = {} ;
F_121 ( V_4 , V_295 , V_286 , & V_159 ) ;
if ( ! F_119 ( V_295 , & F_86 , & V_159 ) )
break;
V_337 -> V_159 [ V_295 ] = V_159 ;
}
return true ;
}
static void F_144 ( struct V_1 * V_2 ,
int V_295 ,
struct V_305 * V_340 )
{
const struct V_18 * V_18 ;
V_340 -> V_143 = true ;
F_142 (dev, intel_crtc) {
const struct V_334 * V_291 = & V_18 -> V_159 . V_291 ;
const struct V_305 * V_159 = & V_291 -> V_159 [ V_295 ] ;
if ( ! V_291 -> V_335 )
continue;
if ( ! V_159 -> V_143 )
V_340 -> V_143 = false ;
V_340 -> V_284 = F_86 ( V_340 -> V_284 , V_159 -> V_284 ) ;
V_340 -> V_307 = F_86 ( V_340 -> V_307 , V_159 -> V_307 ) ;
V_340 -> V_308 = F_86 ( V_340 -> V_308 , V_159 -> V_308 ) ;
V_340 -> V_313 = F_86 ( V_340 -> V_313 , V_159 -> V_313 ) ;
}
}
static void F_145 ( struct V_1 * V_2 ,
const struct V_297 * V_96 ,
const struct V_304 * F_86 ,
struct V_334 * V_341 )
{
int V_295 , V_330 = F_132 ( V_2 ) ;
int V_342 = V_330 ;
if ( ( F_55 ( V_2 ) -> V_102 <= 6 || F_32 ( V_2 ) ) &&
V_96 -> V_301 > 1 )
return;
V_341 -> V_343 = F_55 ( V_2 ) -> V_102 >= 6 ;
for ( V_295 = 1 ; V_295 <= V_330 ; V_295 ++ ) {
struct V_305 * V_159 = & V_341 -> V_159 [ V_295 ] ;
F_144 ( V_2 , V_295 , V_159 ) ;
if ( V_295 > V_342 )
V_159 -> V_143 = false ;
else if ( ! F_119 ( V_295 , F_86 , V_159 ) )
V_342 = V_295 - 1 ;
if ( V_159 -> V_313 > F_86 -> V_21 ) {
if ( V_159 -> V_143 )
V_341 -> V_343 = false ;
V_159 -> V_313 = 0 ;
}
}
if ( F_25 ( V_2 ) && ! V_341 -> V_343 && F_34 ( V_2 ) ) {
for ( V_295 = 2 ; V_295 <= V_330 ; V_295 ++ ) {
struct V_305 * V_159 = & V_341 -> V_159 [ V_295 ] ;
V_159 -> V_143 = false ;
}
}
}
static int F_146 ( int V_344 , const struct V_334 * V_337 )
{
return V_344 + ( V_344 >= 2 && V_337 -> V_159 [ 4 ] . V_143 ) ;
}
static unsigned int F_147 ( struct V_1 * V_2 , int V_295 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_56 ( V_2 ) || F_128 ( V_2 ) )
return 2 * V_295 ;
else
return V_4 -> V_159 . V_310 [ V_295 ] ;
}
static void F_148 ( struct V_1 * V_2 ,
const struct V_334 * V_341 ,
enum V_298 V_345 ,
struct V_346 * V_347 )
{
struct V_18 * V_18 ;
int V_295 , V_344 ;
V_347 -> V_348 = V_341 -> V_343 ;
V_347 -> V_345 = V_345 ;
for ( V_344 = 1 ; V_344 <= 3 ; V_344 ++ ) {
const struct V_305 * V_349 ;
V_295 = F_146 ( V_344 , V_341 ) ;
V_349 = & V_341 -> V_159 [ V_295 ] ;
V_347 -> V_344 [ V_344 - 1 ] =
( F_147 ( V_2 , V_295 ) << V_350 ) |
( V_349 -> V_284 << V_351 ) |
V_349 -> V_308 ;
if ( V_349 -> V_143 )
V_347 -> V_344 [ V_344 - 1 ] |= V_352 ;
if ( F_55 ( V_2 ) -> V_102 >= 8 )
V_347 -> V_344 [ V_344 - 1 ] |=
V_349 -> V_313 << V_353 ;
else
V_347 -> V_344 [ V_344 - 1 ] |=
V_349 -> V_313 << V_354 ;
if ( F_55 ( V_2 ) -> V_102 <= 6 && V_349 -> V_307 ) {
F_149 ( V_344 != 1 ) ;
V_347 -> V_355 [ V_344 - 1 ] = V_356 | V_349 -> V_307 ;
} else
V_347 -> V_355 [ V_344 - 1 ] = V_349 -> V_307 ;
}
F_142 (dev, intel_crtc) {
enum V_65 V_65 = V_18 -> V_65 ;
const struct V_305 * V_349 =
& V_18 -> V_159 . V_291 . V_159 [ 0 ] ;
if ( F_149 ( ! V_349 -> V_143 ) )
continue;
V_347 -> V_357 [ V_65 ] = V_18 -> V_159 . V_291 . V_315 ;
V_347 -> V_358 [ V_65 ] =
( V_349 -> V_284 << V_359 ) |
( V_349 -> V_307 << V_360 ) |
V_349 -> V_308 ;
}
}
static struct V_334 * F_150 ( struct V_1 * V_2 ,
struct V_334 * V_361 ,
struct V_334 * V_362 )
{
int V_295 , V_330 = F_132 ( V_2 ) ;
int V_363 = 0 , V_364 = 0 ;
for ( V_295 = 1 ; V_295 <= V_330 ; V_295 ++ ) {
if ( V_361 -> V_159 [ V_295 ] . V_143 )
V_363 = V_295 ;
if ( V_362 -> V_159 [ V_295 ] . V_143 )
V_364 = V_295 ;
}
if ( V_363 == V_364 ) {
if ( V_362 -> V_343 && ! V_361 -> V_343 )
return V_362 ;
else
return V_361 ;
} else if ( V_363 > V_364 ) {
return V_361 ;
} else {
return V_362 ;
}
}
static unsigned int F_151 ( struct V_1 * V_2 ,
const struct V_346 * V_365 ,
const struct V_346 * V_366 )
{
unsigned int V_367 = 0 ;
enum V_65 V_65 ;
int V_344 ;
F_152 (pipe) {
if ( V_365 -> V_357 [ V_65 ] != V_366 -> V_357 [ V_65 ] ) {
V_367 |= F_153 ( V_65 ) ;
V_367 |= V_368 ;
}
if ( V_365 -> V_358 [ V_65 ] != V_366 -> V_358 [ V_65 ] ) {
V_367 |= F_154 ( V_65 ) ;
V_367 |= V_368 ;
}
}
if ( V_365 -> V_348 != V_366 -> V_348 ) {
V_367 |= V_369 ;
V_367 |= V_368 ;
}
if ( V_365 -> V_345 != V_366 -> V_345 ) {
V_367 |= V_370 ;
V_367 |= V_368 ;
}
if ( V_367 & V_368 )
return V_367 ;
for ( V_344 = 1 ; V_344 <= 3 ; V_344 ++ ) {
if ( V_365 -> V_344 [ V_344 - 1 ] != V_366 -> V_344 [ V_344 - 1 ] ||
V_365 -> V_355 [ V_344 - 1 ] != V_366 -> V_355 [ V_344 - 1 ] )
break;
}
for (; V_344 <= 3 ; V_344 ++ )
V_367 |= F_155 ( V_344 ) ;
return V_367 ;
}
static bool F_156 ( struct V_3 * V_4 ,
unsigned int V_367 )
{
struct V_346 * V_371 = & V_4 -> V_159 . V_372 ;
bool V_331 = false ;
if ( V_367 & F_155 ( 3 ) && V_371 -> V_344 [ 2 ] & V_352 ) {
V_371 -> V_344 [ 2 ] &= ~ V_352 ;
F_3 ( V_373 , V_371 -> V_344 [ 2 ] ) ;
V_331 = true ;
}
if ( V_367 & F_155 ( 2 ) && V_371 -> V_344 [ 1 ] & V_352 ) {
V_371 -> V_344 [ 1 ] &= ~ V_352 ;
F_3 ( V_374 , V_371 -> V_344 [ 1 ] ) ;
V_331 = true ;
}
if ( V_367 & F_155 ( 1 ) && V_371 -> V_344 [ 0 ] & V_352 ) {
V_371 -> V_344 [ 0 ] &= ~ V_352 ;
F_3 ( V_375 , V_371 -> V_344 [ 0 ] ) ;
V_331 = true ;
}
return V_331 ;
}
static void F_157 ( struct V_3 * V_4 ,
struct V_346 * V_347 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_346 * V_371 = & V_4 -> V_159 . V_372 ;
unsigned int V_367 ;
T_3 V_144 ;
V_367 = F_151 ( V_2 , V_371 , V_347 ) ;
if ( ! V_367 )
return;
F_156 ( V_4 , V_367 ) ;
if ( V_367 & F_154 ( V_242 ) )
F_3 ( V_376 , V_347 -> V_358 [ 0 ] ) ;
if ( V_367 & F_154 ( V_245 ) )
F_3 ( V_377 , V_347 -> V_358 [ 1 ] ) ;
if ( V_367 & F_154 ( V_378 ) )
F_3 ( V_379 , V_347 -> V_358 [ 2 ] ) ;
if ( V_367 & F_153 ( V_242 ) )
F_3 ( F_158 ( V_242 ) , V_347 -> V_357 [ 0 ] ) ;
if ( V_367 & F_153 ( V_245 ) )
F_3 ( F_158 ( V_245 ) , V_347 -> V_357 [ 1 ] ) ;
if ( V_367 & F_153 ( V_378 ) )
F_3 ( F_158 ( V_378 ) , V_347 -> V_357 [ 2 ] ) ;
if ( V_367 & V_370 ) {
if ( F_56 ( V_2 ) || F_128 ( V_2 ) ) {
V_144 = F_2 ( V_380 ) ;
if ( V_347 -> V_345 == V_339 )
V_144 &= ~ V_381 ;
else
V_144 |= V_381 ;
F_3 ( V_380 , V_144 ) ;
} else {
V_144 = F_2 ( V_382 ) ;
if ( V_347 -> V_345 == V_339 )
V_144 &= ~ V_383 ;
else
V_144 |= V_383 ;
F_3 ( V_382 , V_144 ) ;
}
}
if ( V_367 & V_369 ) {
V_144 = F_2 ( V_384 ) ;
if ( V_347 -> V_348 )
V_144 &= ~ V_385 ;
else
V_144 |= V_385 ;
F_3 ( V_384 , V_144 ) ;
}
if ( V_367 & F_155 ( 1 ) &&
V_371 -> V_355 [ 0 ] != V_347 -> V_355 [ 0 ] )
F_3 ( V_386 , V_347 -> V_355 [ 0 ] ) ;
if ( F_55 ( V_2 ) -> V_102 >= 7 ) {
if ( V_367 & F_155 ( 2 ) && V_371 -> V_355 [ 1 ] != V_347 -> V_355 [ 1 ] )
F_3 ( V_387 , V_347 -> V_355 [ 1 ] ) ;
if ( V_367 & F_155 ( 3 ) && V_371 -> V_355 [ 2 ] != V_347 -> V_355 [ 2 ] )
F_3 ( V_388 , V_347 -> V_355 [ 2 ] ) ;
}
if ( V_367 & F_155 ( 1 ) && V_371 -> V_344 [ 0 ] != V_347 -> V_344 [ 0 ] )
F_3 ( V_375 , V_347 -> V_344 [ 0 ] ) ;
if ( V_367 & F_155 ( 2 ) && V_371 -> V_344 [ 1 ] != V_347 -> V_344 [ 1 ] )
F_3 ( V_374 , V_347 -> V_344 [ 1 ] ) ;
if ( V_367 & F_155 ( 3 ) && V_371 -> V_344 [ 2 ] != V_347 -> V_344 [ 2 ] )
F_3 ( V_373 , V_347 -> V_344 [ 2 ] ) ;
V_4 -> V_159 . V_372 = * V_347 ;
}
static bool F_159 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_156 ( V_4 , V_368 ) ;
}
static void F_160 ( struct V_11 * V_12 )
{
struct V_18 * V_18 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_304 F_86 ;
struct V_285 V_286 = {} ;
struct V_346 V_347 = {} ;
enum V_298 V_345 ;
struct V_334 V_337 = {} ;
struct V_334 V_389 = {} , V_390 = {} , * V_391 ;
struct V_297 V_96 = {} ;
F_138 ( V_12 , & V_286 ) ;
F_143 ( V_12 , & V_286 , & V_337 ) ;
if ( ! memcmp ( & V_18 -> V_159 . V_291 , & V_337 , sizeof( V_337 ) ) )
return;
V_18 -> V_159 . V_291 = V_337 ;
F_141 ( V_2 , & V_96 ) ;
F_117 ( V_2 , 1 , & V_96 , V_339 , & F_86 ) ;
F_145 ( V_2 , & V_96 , & F_86 , & V_389 ) ;
if ( F_55 ( V_2 ) -> V_102 >= 7 &&
V_96 . V_301 == 1 && V_96 . V_300 ) {
F_117 ( V_2 , 1 , & V_96 , V_303 , & F_86 ) ;
F_145 ( V_2 , & V_96 , & F_86 , & V_390 ) ;
V_391 = F_150 ( V_2 , & V_389 , & V_390 ) ;
} else {
V_391 = & V_389 ;
}
V_345 = ( V_391 == & V_389 ) ?
V_339 : V_303 ;
F_148 ( V_2 , V_391 , V_345 , & V_347 ) ;
F_157 ( V_4 , & V_347 ) ;
}
static void
F_161 ( struct V_332 * V_30 ,
struct V_11 * V_12 ,
T_3 V_392 , T_3 V_393 ,
int V_161 , bool V_169 , bool V_338 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_333 * V_333 = F_140 ( V_30 ) ;
V_333 -> V_159 . V_169 = V_169 ;
V_333 -> V_159 . V_338 = V_338 ;
V_333 -> V_159 . V_283 = V_392 ;
V_333 -> V_159 . V_394 = V_392 ;
V_333 -> V_159 . V_279 = V_161 ;
if ( F_32 ( V_2 ) && V_338 && F_159 ( V_2 ) )
F_162 ( V_2 , V_333 -> V_65 ) ;
F_160 ( V_12 ) ;
}
static void F_163 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_346 * V_372 = & V_4 -> V_159 . V_372 ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
struct V_334 * V_291 = & V_18 -> V_159 . V_291 ;
enum V_65 V_65 = V_18 -> V_65 ;
static const unsigned int V_395 [] = {
[ V_242 ] = V_376 ,
[ V_245 ] = V_377 ,
[ V_378 ] = V_379 ,
} ;
V_372 -> V_358 [ V_65 ] = F_2 ( V_395 [ V_65 ] ) ;
if ( F_56 ( V_2 ) || F_128 ( V_2 ) )
V_372 -> V_357 [ V_65 ] = F_2 ( F_158 ( V_65 ) ) ;
V_291 -> V_335 = F_54 ( V_12 ) ;
if ( V_291 -> V_335 ) {
T_1 V_114 = V_372 -> V_358 [ V_65 ] ;
V_291 -> V_159 [ 0 ] . V_143 = true ;
V_291 -> V_159 [ 0 ] . V_284 = ( V_114 & V_396 ) >> V_359 ;
V_291 -> V_159 [ 0 ] . V_307 = ( V_114 & V_397 ) >> V_360 ;
V_291 -> V_159 [ 0 ] . V_308 = V_114 & V_398 ;
V_291 -> V_315 = V_372 -> V_357 [ V_65 ] ;
} else {
int V_295 , V_330 = F_132 ( V_2 ) ;
for ( V_295 = 0 ; V_295 <= V_330 ; V_295 ++ )
V_291 -> V_159 [ V_295 ] . V_143 = true ;
}
}
void F_164 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_346 * V_372 = & V_4 -> V_159 . V_372 ;
struct V_11 * V_12 ;
F_53 (dev, crtc)
F_163 ( V_12 ) ;
V_372 -> V_344 [ 0 ] = F_2 ( V_375 ) ;
V_372 -> V_344 [ 1 ] = F_2 ( V_374 ) ;
V_372 -> V_344 [ 2 ] = F_2 ( V_373 ) ;
V_372 -> V_355 [ 0 ] = F_2 ( V_386 ) ;
if ( F_55 ( V_2 ) -> V_102 >= 7 ) {
V_372 -> V_355 [ 1 ] = F_2 ( V_387 ) ;
V_372 -> V_355 [ 2 ] = F_2 ( V_388 ) ;
}
if ( F_56 ( V_2 ) || F_128 ( V_2 ) )
V_372 -> V_345 = ( F_2 ( V_380 ) & V_381 ) ?
V_303 : V_339 ;
else if ( F_32 ( V_2 ) )
V_372 -> V_345 = ( F_2 ( V_382 ) & V_383 ) ?
V_303 : V_339 ;
V_372 -> V_348 =
! ( F_2 ( V_384 ) & V_385 ) ;
}
void F_165 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_2 -> V_5 ;
if ( V_4 -> V_67 . V_399 )
V_4 -> V_67 . V_399 ( V_12 ) ;
}
void F_166 ( struct V_332 * V_30 ,
struct V_11 * V_12 ,
T_3 V_392 ,
T_3 V_393 ,
int V_161 ,
bool V_169 , bool V_338 )
{
struct V_3 * V_4 = V_30 -> V_2 -> V_5 ;
if ( V_4 -> V_67 . V_400 )
V_4 -> V_67 . V_400 ( V_30 , V_12 ,
V_392 , V_393 ,
V_161 , V_169 , V_338 ) ;
}
static struct V_16 *
F_167 ( struct V_1 * V_2 )
{
struct V_16 * V_401 ;
int V_280 ;
F_149 ( ! F_168 ( & V_2 -> V_73 ) ) ;
V_401 = F_169 ( V_2 , 4096 ) ;
if ( ! V_401 ) {
F_170 ( L_55 ) ;
return NULL ;
}
V_280 = F_171 ( V_401 , 4096 , 0 ) ;
if ( V_280 ) {
F_45 ( L_56 , V_280 ) ;
goto V_402;
}
V_280 = F_172 ( V_401 , 1 ) ;
if ( V_280 ) {
F_45 ( L_57 , V_280 ) ;
goto V_403;
}
return V_401 ;
V_403:
F_173 ( V_401 ) ;
V_402:
F_174 ( & V_401 -> V_77 ) ;
return NULL ;
}
bool F_175 ( struct V_1 * V_2 , T_7 V_144 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_404 ;
F_176 ( & V_405 ) ;
V_404 = F_64 ( V_406 ) ;
if ( V_404 & V_407 ) {
F_170 ( L_58 ) ;
return false ;
}
V_404 = ( V_408 << V_409 ) |
( V_144 << V_410 ) | V_411 ;
F_177 ( V_406 , V_404 ) ;
F_178 ( V_406 ) ;
V_404 |= V_407 ;
F_177 ( V_406 , V_404 ) ;
return true ;
}
static void F_179 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_412 = F_2 ( V_413 ) ;
T_7 V_414 , V_415 , V_416 , V_417 ;
F_180 ( & V_405 ) ;
F_177 ( V_418 , F_2 ( V_418 ) | V_419 ) ;
F_177 ( V_420 , F_2 ( V_420 ) | V_421 ) ;
F_3 ( V_422 , 100000 ) ;
F_3 ( V_423 , 100000 ) ;
F_3 ( V_424 , 90000 ) ;
F_3 ( V_425 , 80000 ) ;
F_3 ( V_426 , 1 ) ;
V_414 = ( V_412 & V_427 ) >> V_428 ;
V_415 = ( V_412 & V_429 ) ;
V_416 = ( V_412 & V_430 ) >>
V_431 ;
V_417 = ( F_2 ( V_432 + ( V_416 * 4 ) ) & V_433 ) >>
V_434 ;
V_4 -> V_134 . V_414 = V_414 ;
V_4 -> V_134 . V_416 = V_416 ;
V_4 -> V_134 . V_435 = V_416 ;
V_4 -> V_134 . V_436 = V_415 ;
V_4 -> V_134 . V_437 = V_416 ;
F_65 ( L_59 ,
V_414 , V_415 , V_416 ) ;
F_3 ( V_438 , V_439 | V_440 ) ;
F_3 ( V_441 , V_417 ) ;
F_22 ( V_441 ) ;
V_412 |= V_442 ;
F_3 ( V_413 , V_412 ) ;
if ( F_181 ( ( F_2 ( V_406 ) & V_407 ) == 0 , 10 ) )
F_45 ( L_60 ) ;
F_182 ( 1 ) ;
F_175 ( V_2 , V_416 ) ;
V_4 -> V_134 . V_443 = F_2 ( 0x112e4 ) + F_2 ( 0x112e8 ) +
F_2 ( 0x112e0 ) ;
V_4 -> V_134 . V_444 = F_183 ( V_445 ) ;
V_4 -> V_134 . V_446 = F_2 ( 0x112f4 ) ;
V_4 -> V_134 . V_447 = F_184 () ;
F_185 ( & V_405 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_404 ;
F_180 ( & V_405 ) ;
V_404 = F_64 ( V_406 ) ;
F_3 ( V_438 , F_2 ( V_438 ) & ~ V_440 ) ;
F_3 ( V_448 , V_449 ) ;
F_3 ( V_450 , F_2 ( V_450 ) & ~ V_451 ) ;
F_3 ( V_452 , V_451 ) ;
F_3 ( V_453 , F_2 ( V_453 ) | V_451 ) ;
F_175 ( V_2 , V_4 -> V_134 . V_416 ) ;
F_182 ( 1 ) ;
V_404 |= V_407 ;
F_3 ( V_406 , V_404 ) ;
F_182 ( 1 ) ;
F_185 ( & V_405 ) ;
}
static T_1 F_187 ( struct V_3 * V_4 , T_7 V_144 )
{
T_1 V_454 ;
V_454 = V_4 -> V_455 . V_456 << 24 ;
if ( V_144 <= V_4 -> V_455 . V_457 )
V_454 |= V_4 -> V_455 . V_457 << 16 ;
return V_454 ;
}
static void F_188 ( struct V_3 * V_4 , T_7 V_144 )
{
int V_458 ;
V_458 = V_4 -> V_455 . V_459 ;
switch ( V_4 -> V_455 . V_459 ) {
case V_460 :
if ( V_144 > V_4 -> V_455 . V_461 + 1 && V_144 > V_4 -> V_455 . V_462 )
V_458 = V_463 ;
break;
case V_463 :
if ( V_144 <= V_4 -> V_455 . V_461 && V_144 < V_4 -> V_455 . V_462 )
V_458 = V_460 ;
else if ( V_144 >= V_4 -> V_455 . V_464 && V_144 > V_4 -> V_455 . V_462 )
V_458 = V_465 ;
break;
case V_465 :
if ( V_144 < ( V_4 -> V_455 . V_466 + V_4 -> V_455 . V_464 ) > > 1 && V_144 < V_4 -> V_455 . V_462 )
V_458 = V_463 ;
break;
}
if ( V_144 == V_4 -> V_455 . V_457 )
V_458 = V_460 ;
if ( V_144 == V_4 -> V_455 . V_456 )
V_458 = V_465 ;
if ( V_458 == V_4 -> V_455 . V_459 )
return;
switch ( V_458 ) {
case V_460 :
F_3 ( V_467 , 12500 ) ;
F_3 ( V_468 , 11800 ) ;
F_3 ( V_469 , 25000 ) ;
F_3 ( V_470 , 21250 ) ;
F_3 ( V_471 ,
V_472 |
V_473 |
V_474 |
V_475 |
V_476 |
V_477 ) ;
break;
case V_463 :
F_3 ( V_467 , 10250 ) ;
F_3 ( V_468 , 9225 ) ;
F_3 ( V_469 , 25000 ) ;
F_3 ( V_470 , 18750 ) ;
F_3 ( V_471 ,
V_472 |
V_473 |
V_474 |
V_475 |
V_476 |
V_477 ) ;
break;
case V_465 :
F_3 ( V_467 , 8000 ) ;
F_3 ( V_468 , 6800 ) ;
F_3 ( V_469 , 25000 ) ;
F_3 ( V_470 , 15000 ) ;
F_3 ( V_471 ,
V_472 |
V_473 |
V_474 |
V_475 |
V_476 |
V_477 ) ;
break;
}
V_4 -> V_455 . V_459 = V_458 ;
V_4 -> V_455 . V_478 = 0 ;
}
static T_1 F_189 ( struct V_3 * V_4 , T_7 V_144 )
{
T_1 V_479 = 0 ;
if ( V_144 > V_4 -> V_455 . V_457 )
V_479 |= V_480 | V_481 ;
if ( V_144 < V_4 -> V_455 . V_456 )
V_479 |= V_482 ;
V_479 |= V_4 -> V_483 & ( V_484 | V_485 ) ;
V_479 &= V_4 -> V_483 ;
if ( F_55 ( V_4 -> V_2 ) -> V_102 <= 7 && ! F_56 ( V_4 -> V_2 ) )
V_479 |= V_485 ;
if ( F_190 ( V_4 -> V_2 ) )
V_479 |= V_486 ;
return ~ V_479 ;
}
void F_191 ( struct V_1 * V_2 , T_7 V_144 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_149 ( ! F_168 ( & V_4 -> V_455 . V_487 ) ) ;
F_149 ( V_144 > V_4 -> V_455 . V_456 ) ;
F_149 ( V_144 < V_4 -> V_455 . V_457 ) ;
if ( V_144 != V_4 -> V_455 . V_462 ) {
F_188 ( V_4 , V_144 ) ;
if ( F_56 ( V_2 ) || F_128 ( V_2 ) )
F_3 ( V_488 ,
F_192 ( V_144 ) ) ;
else
F_3 ( V_488 ,
F_193 ( V_144 ) |
F_194 ( 0 ) |
V_489 ) ;
}
F_3 ( V_490 , F_187 ( V_4 , V_144 ) ) ;
F_3 ( V_491 , F_189 ( V_4 , V_144 ) ) ;
F_22 ( V_488 ) ;
V_4 -> V_455 . V_462 = V_144 ;
F_195 ( V_144 * 50 ) ;
}
static void F_196 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_2 -> V_492 -> V_493 >= 0xd ) {
F_197 ( V_4 -> V_2 , V_4 -> V_455 . V_457 ) ;
return;
}
if ( V_4 -> V_455 . V_462 <= V_4 -> V_455 . V_457 )
return;
F_3 ( V_491 , 0xffffffff ) ;
F_198 ( V_4 , true ) ;
V_4 -> V_455 . V_462 = V_4 -> V_455 . V_457 ;
F_199 ( V_4 , V_494 ,
V_4 -> V_455 . V_457 ) ;
if ( F_4 ( ( ( F_200 ( V_4 , V_495 ) )
& V_496 ) == 0 , 5 ) )
F_45 ( L_61 ) ;
F_198 ( V_4 , false ) ;
F_3 ( V_491 ,
F_189 ( V_4 , V_4 -> V_455 . V_462 ) ) ;
}
void F_201 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
if ( V_4 -> V_455 . V_169 ) {
if ( F_202 ( V_2 ) )
F_197 ( V_4 -> V_2 , V_4 -> V_455 . V_457 ) ;
else if ( F_69 ( V_2 ) )
F_196 ( V_4 ) ;
else
F_191 ( V_4 -> V_2 , V_4 -> V_455 . V_457 ) ;
V_4 -> V_455 . V_478 = 0 ;
}
F_39 ( & V_4 -> V_455 . V_487 ) ;
}
void F_203 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
if ( V_4 -> V_455 . V_169 ) {
if ( F_69 ( V_2 ) )
F_197 ( V_4 -> V_2 , V_4 -> V_455 . V_456 ) ;
else
F_191 ( V_4 -> V_2 , V_4 -> V_455 . V_456 ) ;
V_4 -> V_455 . V_478 = 0 ;
}
F_39 ( & V_4 -> V_455 . V_487 ) ;
}
void F_197 ( struct V_1 * V_2 , T_7 V_144 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_149 ( ! F_168 ( & V_4 -> V_455 . V_487 ) ) ;
F_149 ( V_144 > V_4 -> V_455 . V_456 ) ;
F_149 ( V_144 < V_4 -> V_455 . V_457 ) ;
F_65 ( L_62 ,
F_204 ( V_4 , V_4 -> V_455 . V_462 ) ,
V_4 -> V_455 . V_462 ,
F_204 ( V_4 , V_144 ) , V_144 ) ;
if ( V_144 != V_4 -> V_455 . V_462 )
F_199 ( V_4 , V_494 , V_144 ) ;
F_3 ( V_491 , F_189 ( V_4 , V_144 ) ) ;
V_4 -> V_455 . V_462 = V_144 ;
F_195 ( F_204 ( V_4 , V_144 ) ) ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_491 , ~ V_486 ) ;
F_3 ( F_206 ( 2 ) , F_2 ( F_206 ( 2 ) ) &
~ V_4 -> V_483 ) ;
F_180 ( & V_4 -> V_497 ) ;
V_4 -> V_455 . V_498 = 0 ;
F_185 ( & V_4 -> V_497 ) ;
F_3 ( F_207 ( 2 ) , V_4 -> V_483 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_491 , 0xffffffff ) ;
F_3 ( V_499 , F_2 ( V_499 ) &
~ V_4 -> V_483 ) ;
F_180 ( & V_4 -> V_497 ) ;
V_4 -> V_455 . V_498 = 0 ;
F_185 ( & V_4 -> V_497 ) ;
F_3 ( V_500 , V_4 -> V_483 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_501 , 0 ) ;
F_3 ( V_488 , 1 << 31 ) ;
if ( F_128 ( V_2 ) )
F_205 ( V_2 ) ;
else
F_208 ( V_2 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_501 , 0 ) ;
F_205 ( V_2 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_501 , 0 ) ;
F_208 ( V_2 ) ;
}
static void F_212 ( struct V_1 * V_2 , T_1 V_314 )
{
if ( F_69 ( V_2 ) ) {
if ( V_314 & ( V_502 | F_213 ( 1 ) ) )
V_314 = V_503 ;
else
V_314 = 0 ;
}
F_5 ( L_63 ,
( V_314 & V_503 ) ? L_64 : L_65 ,
( V_314 & V_504 ) ? L_64 : L_65 ,
( V_314 & V_505 ) ? L_64 : L_65 ) ;
}
static int F_214 ( const struct V_1 * V_2 , int V_506 )
{
if ( F_55 ( V_2 ) -> V_102 < 5 )
return 0 ;
if ( F_55 ( V_2 ) -> V_102 == 5 && ! F_215 ( V_2 ) )
return 0 ;
if ( V_506 >= 0 ) {
int V_479 ;
if ( F_55 ( V_2 ) -> V_102 == 6 || F_32 ( V_2 ) )
V_479 = V_507 | V_508 |
V_509 ;
else
V_479 = V_507 ;
if ( ( V_506 & V_479 ) != V_506 )
F_5 ( L_66 ,
V_506 & V_479 , V_506 , V_479 ) ;
return V_506 & V_479 ;
}
if ( F_55 ( V_2 ) -> V_102 == 5 )
return 0 ;
if ( F_32 ( V_2 ) )
return ( V_507 | V_508 ) ;
return V_507 ;
}
int F_216 ( const struct V_1 * V_2 )
{
return V_89 . V_506 ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_180 ( & V_4 -> V_497 ) ;
F_149 ( V_4 -> V_455 . V_498 ) ;
F_218 ( V_4 , V_4 -> V_483 ) ;
F_3 ( F_207 ( 2 ) , V_4 -> V_483 ) ;
F_185 ( & V_4 -> V_497 ) ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_180 ( & V_4 -> V_497 ) ;
F_149 ( V_4 -> V_455 . V_498 ) ;
F_220 ( V_4 , V_4 -> V_483 ) ;
F_3 ( V_500 , V_4 -> V_483 ) ;
F_185 ( & V_4 -> V_497 ) ;
}
static void F_221 ( struct V_3 * V_4 , T_1 V_510 )
{
V_4 -> V_455 . V_462 = 0 ;
V_4 -> V_455 . V_466 = ( V_510 >> 8 ) & 0xff ;
V_4 -> V_455 . V_464 = ( V_510 >> 0 ) & 0xff ;
V_4 -> V_455 . V_511 = ( V_510 >> 16 ) & 0xff ;
V_4 -> V_455 . V_461 = V_4 -> V_455 . V_466 ;
V_4 -> V_455 . V_512 = V_4 -> V_455 . V_464 ;
if ( V_4 -> V_455 . V_456 == 0 )
V_4 -> V_455 . V_456 = V_4 -> V_455 . V_512 ;
if ( V_4 -> V_455 . V_457 == 0 )
V_4 -> V_455 . V_457 = V_4 -> V_455 . V_511 ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_513 * V_514 ;
T_3 V_515 = 0 , V_510 ;
int V_516 ;
F_3 ( V_517 , 0 ) ;
F_21 ( V_4 , V_518 ) ;
F_3 ( V_501 , 0 ) ;
V_510 = F_2 ( V_519 ) ;
F_221 ( V_4 , V_510 ) ;
F_3 ( V_520 , 40 << 16 ) ;
F_3 ( V_521 , 125000 ) ;
F_3 ( V_522 , 25 ) ;
F_223 (ring, dev_priv, unused)
F_3 ( F_224 ( V_514 -> V_523 ) , 10 ) ;
F_3 ( V_524 , 0 ) ;
if ( F_128 ( V_2 ) )
F_3 ( V_525 , 625 ) ;
else
F_3 ( V_525 , 50000 ) ;
if ( F_216 ( V_2 ) & V_507 )
V_515 = V_503 ;
F_212 ( V_2 , V_515 ) ;
if ( F_128 ( V_2 ) )
F_3 ( V_501 , V_526 |
V_502 |
V_515 ) ;
else
F_3 ( V_501 , V_526 |
F_213 ( 1 ) |
V_515 ) ;
F_3 ( V_488 ,
F_192 ( V_4 -> V_455 . V_466 ) ) ;
F_3 ( V_527 ,
F_192 ( V_4 -> V_455 . V_466 ) ) ;
F_3 ( V_528 , 100000000 / 128 ) ;
F_3 ( V_490 ,
V_4 -> V_455 . V_456 << 24 |
V_4 -> V_455 . V_457 << 16 ) ;
F_3 ( V_468 , 7600000 / 128 ) ;
F_3 ( V_470 , 31300000 / 128 ) ;
F_3 ( V_467 , 66000 ) ;
F_3 ( V_469 , 350000 ) ;
F_3 ( V_529 , 10 ) ;
F_3 ( V_471 ,
V_472 |
V_473 |
V_474 |
V_475 |
V_476 |
V_477 ) ;
F_191 ( V_2 , ( F_2 ( V_530 ) & 0xff00 ) >> 8 ) ;
F_217 ( V_2 ) ;
F_23 ( V_4 , V_518 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_513 * V_514 ;
T_1 V_510 ;
T_1 V_531 ;
T_1 V_532 , V_533 = 0 , V_515 = 0 ;
T_1 V_534 ;
int V_535 ;
int V_20 , V_280 ;
F_149 ( ! F_168 ( & V_4 -> V_455 . V_487 ) ) ;
F_3 ( V_517 , 0 ) ;
if ( ( V_534 = F_2 ( V_536 ) ) ) {
F_45 ( L_67 , V_534 ) ;
F_3 ( V_536 , V_534 ) ;
}
F_21 ( V_4 , V_518 ) ;
V_510 = F_2 ( V_519 ) ;
V_531 = F_2 ( V_530 ) ;
F_221 ( V_4 , V_510 ) ;
F_3 ( V_501 , 0 ) ;
F_3 ( V_537 , 1000 << 16 ) ;
F_3 ( V_520 , 40 << 16 | 30 ) ;
F_3 ( V_538 , 30 ) ;
F_3 ( V_521 , 125000 ) ;
F_3 ( V_522 , 25 ) ;
F_223 (ring, dev_priv, i)
F_3 ( F_224 ( V_514 -> V_523 ) , 10 ) ;
F_3 ( V_524 , 0 ) ;
F_3 ( V_539 , 1000 ) ;
if ( F_32 ( V_2 ) )
F_3 ( V_525 , 125000 ) ;
else
F_3 ( V_525 , 50000 ) ;
F_3 ( V_540 , 150000 ) ;
F_3 ( V_541 , 64000 ) ;
V_535 = F_216 ( V_4 -> V_2 ) ;
if ( V_535 & V_507 )
V_515 |= V_503 ;
if ( ! F_56 ( V_2 ) ) {
if ( V_535 & V_508 )
V_515 |= V_504 ;
if ( V_535 & V_509 )
V_515 |= V_505 ;
}
F_212 ( V_2 , V_515 ) ;
F_3 ( V_501 ,
V_515 |
F_213 ( 1 ) |
V_526 ) ;
F_3 ( V_528 , 50000 ) ;
F_3 ( V_529 , 10 ) ;
V_280 = F_226 ( V_4 , V_542 , 0 ) ;
if ( V_280 )
F_65 ( L_68 ) ;
V_280 = F_227 ( V_4 , V_543 , & V_533 ) ;
if ( ! V_280 && ( V_533 & ( 1 << 31 ) ) ) {
F_65 ( L_69 ,
( V_4 -> V_455 . V_456 & 0xff ) * 50 ,
( V_533 & 0xff ) * 50 ) ;
V_4 -> V_455 . V_512 = V_533 & 0xff ;
}
V_4 -> V_455 . V_459 = V_465 ;
F_191 ( V_4 -> V_2 , V_4 -> V_455 . V_457 ) ;
F_219 ( V_2 ) ;
V_532 = 0 ;
V_280 = F_227 ( V_4 , V_544 , & V_532 ) ;
if ( F_27 ( V_2 ) && V_280 ) {
F_65 ( L_70 ) ;
} else if ( F_27 ( V_2 ) && ( F_228 ( V_532 & 0xff ) < 450 ) ) {
F_65 ( L_71 ,
F_228 ( V_532 & 0xff ) , 450 ) ;
V_532 &= 0xffff00 ;
V_532 |= F_229 ( 450 ) ;
V_280 = F_226 ( V_4 , V_545 , V_532 ) ;
if ( V_280 )
F_45 ( L_72 ) ;
}
F_23 ( V_4 , V_518 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_511 = 15 ;
unsigned int V_546 ;
unsigned int V_547 , V_548 ;
int V_549 = 180 ;
struct V_550 * V_551 ;
F_149 ( ! F_168 ( & V_4 -> V_455 . V_487 ) ) ;
V_551 = F_231 ( 0 ) ;
if ( V_551 ) {
V_547 = V_551 -> V_552 . V_512 ;
F_232 ( V_551 ) ;
} else {
V_547 = V_553 ;
}
V_547 /= 1000 ;
V_548 = F_2 ( V_554 ) & 0xf ;
V_548 = F_233 ( V_548 , 8 , 3 ) ;
for ( V_546 = V_4 -> V_455 . V_456 ; V_546 >= V_4 -> V_455 . V_457 ;
V_546 -- ) {
int V_555 = V_4 -> V_455 . V_456 - V_546 ;
unsigned int V_556 = 0 , V_557 = 0 ;
if ( F_55 ( V_2 ) -> V_102 >= 8 ) {
V_557 = F_86 ( V_548 , V_546 ) ;
} else if ( F_56 ( V_2 ) ) {
V_557 = F_233 ( V_546 , 5 , 4 ) ;
V_557 = F_86 ( V_548 , V_557 ) ;
} else {
if ( V_546 < V_511 )
V_556 = 800 ;
else
V_556 = V_547 - ( ( V_555 * V_549 ) / 2 ) ;
V_556 = F_123 ( V_556 , 100 ) ;
}
F_226 ( V_4 ,
V_542 ,
V_556 << V_558 |
V_557 << V_559 |
V_546 ) ;
}
}
void F_234 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_55 ( V_2 ) -> V_102 < 6 || F_69 ( V_2 ) )
return;
F_38 ( & V_4 -> V_455 . V_487 ) ;
F_230 ( V_2 ) ;
F_39 ( & V_4 -> V_455 . V_487 ) ;
}
static int F_235 ( struct V_3 * V_4 )
{
T_1 V_144 , V_560 ;
V_144 = F_200 ( V_4 , V_561 ) ;
V_560 = ( V_144 >> V_562 ) & V_563 ;
return V_560 ;
}
static int F_236 ( struct V_3 * V_4 )
{
T_1 V_144 , V_564 ;
V_144 = F_200 ( V_4 , V_565 ) ;
V_564 = ( V_144 >> V_566 ) & V_567 ;
return V_564 ;
}
static int F_237 ( struct V_3 * V_4 )
{
T_1 V_144 , V_568 ;
V_144 = F_200 ( V_4 , V_495 ) ;
V_568 = ( V_144 >> V_562 ) & V_563 ;
return V_568 ;
}
static int F_238 ( struct V_3 * V_4 )
{
T_1 V_144 , V_569 ;
V_144 = F_200 ( V_4 , V_561 ) ;
V_569 = ( V_144 >> V_570 ) & V_571 ;
return V_569 ;
}
static int F_239 ( struct V_3 * V_4 )
{
T_1 V_144 , V_568 ;
V_144 = F_240 ( V_4 , V_572 ) ;
V_568 = ( V_144 & V_573 ) >> V_574 ;
return V_568 ;
}
static int F_241 ( struct V_3 * V_4 )
{
T_1 V_144 , V_560 ;
V_144 = F_240 ( V_4 , V_572 ) ;
V_560 = ( V_144 & V_575 ) >> V_576 ;
V_560 = F_120 ( T_1 , V_560 , 0xea ) ;
return V_560 ;
}
static int F_242 ( struct V_3 * V_4 )
{
T_1 V_144 , V_564 ;
V_144 = F_240 ( V_4 , V_577 ) ;
V_564 = ( V_144 & V_578 ) >> V_579 ;
V_144 = F_240 ( V_4 , V_580 ) ;
V_564 |= ( V_144 & V_581 ) << 5 ;
return V_564 ;
}
static int F_243 ( struct V_3 * V_4 )
{
return F_200 ( V_4 , V_582 ) & 0xff ;
}
static void F_244 ( struct V_3 * V_4 )
{
unsigned long V_583 = F_2 ( V_584 ) & ~ 4095 ;
F_149 ( V_583 != V_4 -> V_585 . V_586 +
V_4 -> V_587 -> V_588 -> V_589 ) ;
}
static void F_245 ( struct V_3 * V_4 )
{
unsigned long V_583 = F_2 ( V_584 ) & ~ 4095 ;
F_149 ( ( V_583 >> V_590 ) == 0 ) ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_591 , V_592 ;
struct V_593 * V_594 = & V_4 -> V_594 ;
T_1 V_595 ;
int V_596 = 32 * 1024 ;
F_149 ( ! F_168 ( & V_2 -> V_73 ) ) ;
V_595 = F_2 ( V_584 ) ;
if ( ( V_595 >> V_590 ) == 0 ) {
V_592 = ( V_4 -> V_585 . V_586 +
( V_594 -> V_597 - V_596 ) ) ;
V_591 = ( V_592 & ( ~ 4095 ) ) ;
F_3 ( V_584 , V_591 ) ;
}
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_16 * V_598 ;
unsigned long V_591 ;
T_1 V_595 ;
int V_596 = 24 * 1024 ;
F_149 ( ! F_168 ( & V_2 -> V_73 ) ) ;
V_595 = F_2 ( V_584 ) ;
if ( V_595 ) {
int V_599 ;
V_599 = ( V_595 & ( ~ 4095 ) ) - V_4 -> V_585 . V_586 ;
V_598 = F_248 ( V_4 -> V_2 ,
V_599 ,
V_600 ,
V_596 ) ;
goto V_601;
}
V_598 = F_249 ( V_2 , V_596 ) ;
if ( ! V_598 ) {
F_170 ( L_73 ) ;
return;
}
V_591 = V_4 -> V_585 . V_586 + V_598 -> V_588 -> V_589 ;
F_3 ( V_584 , V_591 ) ;
V_601:
V_4 -> V_587 = V_598 ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_149 ( ! V_4 -> V_587 ) )
return;
F_174 ( & V_4 -> V_587 -> V_77 ) ;
V_4 -> V_587 = NULL ;
}
static void F_251 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_247 ( V_2 ) ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
V_4 -> V_455 . V_512 = F_241 ( V_4 ) ;
V_4 -> V_455 . V_464 = V_4 -> V_455 . V_512 ;
F_65 ( L_74 ,
F_204 ( V_4 , V_4 -> V_455 . V_512 ) ,
V_4 -> V_455 . V_512 ) ;
V_4 -> V_455 . V_461 = F_242 ( V_4 ) ;
F_65 ( L_75 ,
F_204 ( V_4 , V_4 -> V_455 . V_461 ) ,
V_4 -> V_455 . V_461 ) ;
V_4 -> V_455 . V_466 = F_239 ( V_4 ) ;
F_65 ( L_76 ,
F_204 ( V_4 , V_4 -> V_455 . V_466 ) ,
V_4 -> V_455 . V_466 ) ;
V_4 -> V_455 . V_511 = F_243 ( V_4 ) ;
F_65 ( L_77 ,
F_204 ( V_4 , V_4 -> V_455 . V_511 ) ,
V_4 -> V_455 . V_511 ) ;
if ( V_4 -> V_455 . V_456 == 0 )
V_4 -> V_455 . V_456 = V_4 -> V_455 . V_512 ;
if ( V_4 -> V_455 . V_457 == 0 )
V_4 -> V_455 . V_457 = V_4 -> V_455 . V_511 ;
F_39 ( & V_4 -> V_455 . V_487 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_246 ( V_2 ) ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
V_4 -> V_455 . V_512 = F_235 ( V_4 ) ;
V_4 -> V_455 . V_464 = V_4 -> V_455 . V_512 ;
F_65 ( L_74 ,
F_204 ( V_4 , V_4 -> V_455 . V_512 ) ,
V_4 -> V_455 . V_512 ) ;
V_4 -> V_455 . V_461 = F_236 ( V_4 ) ;
F_65 ( L_75 ,
F_204 ( V_4 , V_4 -> V_455 . V_461 ) ,
V_4 -> V_455 . V_461 ) ;
V_4 -> V_455 . V_466 = F_237 ( V_4 ) ;
F_65 ( L_78 ,
F_204 ( V_4 , V_4 -> V_455 . V_466 ) ,
V_4 -> V_455 . V_466 ) ;
V_4 -> V_455 . V_511 = F_238 ( V_4 ) ;
F_65 ( L_77 ,
F_204 ( V_4 , V_4 -> V_455 . V_511 ) ,
V_4 -> V_455 . V_511 ) ;
if ( V_4 -> V_455 . V_456 == 0 )
V_4 -> V_455 . V_456 = V_4 -> V_455 . V_512 ;
if ( V_4 -> V_455 . V_457 == 0 )
V_4 -> V_455 . V_457 = V_4 -> V_455 . V_511 ;
F_39 ( & V_4 -> V_455 . V_487 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
F_250 ( V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_513 * V_514 ;
T_1 V_534 , V_144 , V_535 = 0 , V_595 ;
int V_20 ;
F_149 ( ! F_168 ( & V_4 -> V_455 . V_487 ) ) ;
V_534 = F_2 ( V_536 ) ;
if ( V_534 ) {
F_65 ( L_67 ,
V_534 ) ;
F_3 ( V_536 , V_534 ) ;
}
F_245 ( V_4 ) ;
F_21 ( V_4 , V_518 ) ;
F_3 ( V_520 , 40 << 16 ) ;
F_3 ( V_521 , 125000 ) ;
F_3 ( V_522 , 25 ) ;
F_223 (ring, dev_priv, i)
F_3 ( F_224 ( V_514 -> V_523 ) , 10 ) ;
F_3 ( V_524 , 0 ) ;
F_3 ( V_525 , 50000 ) ;
F_3 ( V_602 ,
F_73 ( V_603 |
V_604 |
V_605 ) ) ;
V_595 = F_2 ( V_584 ) ;
F_65 ( L_79 , V_595 ) ;
if ( ( F_216 ( V_2 ) & V_507 ) &&
( V_595 >> V_590 ) )
V_535 = F_213 ( 1 ) ;
F_3 ( V_501 , V_535 ) ;
F_3 ( V_468 , 59400 ) ;
F_3 ( V_470 , 245000 ) ;
F_3 ( V_467 , 66000 ) ;
F_3 ( V_469 , 350000 ) ;
F_3 ( V_529 , 10 ) ;
F_3 ( 0xA80C , F_2 ( 0xA80C ) & 0x00ffffff ) ;
F_3 ( 0xA810 , F_2 ( 0xA810 ) & 0xffffff00 ) ;
F_3 ( V_471 ,
V_473 |
V_474 |
V_475 |
V_476 |
V_477 ) ;
V_144 = F_200 ( V_4 , V_495 ) ;
F_65 ( L_80 , V_144 & 0x10 ? L_81 : L_82 ) ;
F_65 ( L_83 , V_144 ) ;
V_4 -> V_455 . V_462 = ( V_144 >> 8 ) & 0xff ;
F_65 ( L_84 ,
F_204 ( V_4 , V_4 -> V_455 . V_462 ) ,
V_4 -> V_455 . V_462 ) ;
F_65 ( L_85 ,
F_204 ( V_4 , V_4 -> V_455 . V_461 ) ,
V_4 -> V_455 . V_461 ) ;
F_197 ( V_4 -> V_2 , V_4 -> V_455 . V_461 ) ;
F_217 ( V_2 ) ;
F_23 ( V_4 , V_518 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_513 * V_514 ;
T_1 V_534 , V_144 , V_535 = 0 ;
int V_20 ;
F_149 ( ! F_168 ( & V_4 -> V_455 . V_487 ) ) ;
F_244 ( V_4 ) ;
if ( ( V_534 = F_2 ( V_536 ) ) ) {
F_65 ( L_67 ,
V_534 ) ;
F_3 ( V_536 , V_534 ) ;
}
F_21 ( V_4 , V_518 ) ;
F_3 ( V_468 , 59400 ) ;
F_3 ( V_470 , 245000 ) ;
F_3 ( V_467 , 66000 ) ;
F_3 ( V_469 , 350000 ) ;
F_3 ( V_529 , 10 ) ;
F_3 ( V_528 , 0xf4240 ) ;
F_3 ( V_471 ,
V_472 |
V_473 |
V_474 |
V_475 |
V_476 |
V_606 ) ;
F_3 ( V_520 , 0x00280000 ) ;
F_3 ( V_521 , 125000 ) ;
F_3 ( V_522 , 25 ) ;
F_223 (ring, dev_priv, i)
F_3 ( F_224 ( V_514 -> V_523 ) , 10 ) ;
F_3 ( V_525 , 0x557 ) ;
F_3 ( V_602 ,
F_73 ( V_607 |
V_608 |
V_604 |
V_605 ) ) ;
if ( F_216 ( V_2 ) & V_507 )
V_535 = V_502 | V_609 ;
F_212 ( V_2 , V_535 ) ;
F_3 ( V_501 , V_535 ) ;
V_144 = F_200 ( V_4 , V_495 ) ;
F_65 ( L_80 , V_144 & 0x10 ? L_81 : L_82 ) ;
F_65 ( L_83 , V_144 ) ;
V_4 -> V_455 . V_462 = ( V_144 >> 8 ) & 0xff ;
F_65 ( L_84 ,
F_204 ( V_4 , V_4 -> V_455 . V_462 ) ,
V_4 -> V_455 . V_462 ) ;
F_65 ( L_85 ,
F_204 ( V_4 , V_4 -> V_455 . V_461 ) ,
V_4 -> V_455 . V_461 ) ;
F_197 ( V_4 -> V_2 , V_4 -> V_455 . V_461 ) ;
F_219 ( V_2 ) ;
F_23 ( V_4 , V_518 ) ;
}
void F_256 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_134 . V_610 ) {
F_173 ( V_4 -> V_134 . V_610 ) ;
F_174 ( & V_4 -> V_134 . V_610 -> V_77 ) ;
V_4 -> V_134 . V_610 = NULL ;
}
if ( V_4 -> V_134 . V_611 ) {
F_173 ( V_4 -> V_134 . V_611 ) ;
F_174 ( & V_4 -> V_134 . V_611 -> V_77 ) ;
V_4 -> V_134 . V_611 = NULL ;
}
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_2 ( V_612 ) ) {
F_3 ( V_613 , F_2 ( V_613 ) | V_614 ) ;
F_4 ( ( ( F_2 ( V_613 ) & V_615 ) == V_616 ) ,
50 ) ;
F_3 ( V_612 , 0 ) ;
F_22 ( V_612 ) ;
F_3 ( V_613 , F_2 ( V_613 ) & ~ V_614 ) ;
F_22 ( V_613 ) ;
}
}
static int F_258 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_134 . V_610 == NULL )
V_4 -> V_134 . V_610 = F_167 ( V_2 ) ;
if ( ! V_4 -> V_134 . V_610 )
return - V_617 ;
if ( V_4 -> V_134 . V_611 == NULL )
V_4 -> V_134 . V_611 = F_167 ( V_2 ) ;
if ( ! V_4 -> V_134 . V_611 ) {
F_256 ( V_2 ) ;
return - V_617 ;
}
return 0 ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_513 * V_514 = & V_4 -> V_514 [ V_618 ] ;
bool V_619 ;
int V_280 ;
if ( ! F_216 ( V_2 ) )
return;
F_149 ( ! F_168 ( & V_2 -> V_73 ) ) ;
V_280 = F_258 ( V_2 ) ;
if ( V_280 )
return;
V_619 = V_4 -> V_585 . V_620 ;
V_4 -> V_585 . V_620 = false ;
V_280 = F_260 ( V_514 , 6 ) ;
if ( V_280 ) {
F_256 ( V_2 ) ;
V_4 -> V_585 . V_620 = V_619 ;
return;
}
F_261 ( V_514 , V_621 | V_622 ) ;
F_261 ( V_514 , V_623 ) ;
F_261 ( V_514 , F_26 ( V_4 -> V_134 . V_610 ) |
V_624 |
V_625 |
V_626 |
V_627 ) ;
F_261 ( V_514 , V_621 ) ;
F_261 ( V_514 , V_628 ) ;
F_261 ( V_514 , V_629 ) ;
F_262 ( V_514 ) ;
V_280 = F_263 ( V_514 ) ;
V_4 -> V_585 . V_620 = V_619 ;
if ( V_280 ) {
F_45 ( L_86 ) ;
F_256 ( V_2 ) ;
return;
}
F_3 ( V_612 , F_26 ( V_4 -> V_134 . V_611 ) | V_630 ) ;
F_3 ( V_613 , F_2 ( V_613 ) & ~ V_614 ) ;
F_212 ( V_2 , V_503 ) ;
}
static unsigned long F_264 ( T_1 V_631 )
{
unsigned long V_632 ;
int div = ( V_631 & 0x3f0000 ) >> 16 ;
int V_633 = ( V_631 & 0x3000 ) >> 12 ;
int V_634 = ( V_631 & 0x7 ) ;
if ( ! V_634 )
return 0 ;
V_632 = ( ( div * 133333 ) / ( ( 1 << V_633 ) * V_634 ) ) ;
return V_632 ;
}
static unsigned long F_265 ( struct V_3 * V_4 )
{
T_8 V_635 , V_555 , V_280 ;
T_1 V_636 , V_637 , V_638 , V_639 = 0 , V_640 = 0 ;
unsigned long V_641 = F_183 ( V_445 ) , V_642 ;
int V_20 ;
F_176 ( & V_405 ) ;
V_642 = V_641 - V_4 -> V_134 . V_444 ;
if ( V_642 <= 10 )
return V_4 -> V_134 . V_643 ;
V_636 = F_2 ( V_644 ) ;
V_637 = F_2 ( V_645 ) ;
V_638 = F_2 ( V_646 ) ;
V_635 = V_636 + V_637 + V_638 ;
if ( V_635 < V_4 -> V_134 . V_443 ) {
V_555 = ~ 0UL - V_4 -> V_134 . V_443 ;
V_555 += V_635 ;
} else {
V_555 = V_635 - V_4 -> V_134 . V_443 ;
}
for ( V_20 = 0 ; V_20 < F_67 ( V_647 ) ; V_20 ++ ) {
if ( V_647 [ V_20 ] . V_20 == V_4 -> V_134 . V_136 &&
V_647 [ V_20 ] . V_648 == V_4 -> V_134 . V_135 ) {
V_639 = V_647 [ V_20 ] . V_639 ;
V_640 = V_647 [ V_20 ] . V_640 ;
break;
}
}
V_555 = F_101 ( V_555 , V_642 ) ;
V_280 = ( ( V_639 * V_555 ) + V_640 ) ;
V_280 = F_101 ( V_280 , 10 ) ;
V_4 -> V_134 . V_443 = V_635 ;
V_4 -> V_134 . V_444 = V_641 ;
V_4 -> V_134 . V_643 = V_280 ;
return V_280 ;
}
unsigned long F_266 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_144 ;
if ( F_55 ( V_2 ) -> V_102 != 5 )
return 0 ;
F_180 ( & V_405 ) ;
V_144 = F_265 ( V_4 ) ;
F_185 ( & V_405 ) ;
return V_144 ;
}
unsigned long F_267 ( struct V_3 * V_4 )
{
unsigned long V_639 , V_649 , V_650 ;
T_1 V_651 ;
V_651 = F_2 ( V_652 ) ;
V_639 = ( ( V_651 & V_653 ) >> V_654 ) ;
V_649 = F_268 ( V_655 ) ;
V_650 = V_651 & V_656 ;
return ( ( V_639 * V_649 ) / 127 ) - V_650 ;
}
static T_2 F_269 ( struct V_3 * V_4 , T_7 V_657 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
static const struct V_658 {
T_2 V_659 ;
T_2 V_660 ;
} V_658 [] = {
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
if ( F_55 ( V_2 ) -> V_661 )
return V_658 [ V_657 ] . V_660 ;
else
return V_658 [ V_657 ] . V_659 ;
}
static void F_270 ( struct V_3 * V_4 )
{
T_8 V_641 , V_555 , V_662 ;
T_1 V_663 ;
F_176 ( & V_405 ) ;
V_641 = F_184 () ;
V_662 = V_641 - V_4 -> V_134 . V_447 ;
F_271 ( V_662 , V_664 ) ;
if ( ! V_662 )
return;
V_663 = F_2 ( V_665 ) ;
if ( V_663 < V_4 -> V_134 . V_446 ) {
V_555 = ~ 0UL - V_4 -> V_134 . V_446 ;
V_555 += V_663 ;
} else {
V_555 = V_663 - V_4 -> V_134 . V_446 ;
}
V_4 -> V_134 . V_446 = V_663 ;
V_4 -> V_134 . V_447 = V_641 ;
V_555 = V_555 * 1181 ;
V_555 = F_101 ( V_555 , V_662 * 10 ) ;
V_4 -> V_134 . V_666 = V_555 ;
}
void F_272 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_55 ( V_2 ) -> V_102 != 5 )
return;
F_180 ( & V_405 ) ;
F_270 ( V_4 ) ;
F_185 ( & V_405 ) ;
}
static unsigned long F_273 ( struct V_3 * V_4 )
{
unsigned long V_648 , V_667 , V_668 , V_669 , V_670 ;
T_1 V_657 , V_671 ;
F_176 ( & V_405 ) ;
V_657 = F_2 ( V_432 + ( V_4 -> V_455 . V_462 * 4 ) ) ;
V_657 = ( V_657 >> 24 ) & 0x7f ;
V_671 = F_269 ( V_4 , V_657 ) ;
V_668 = V_671 ;
V_648 = F_267 ( V_4 ) ;
if ( V_648 > 80 )
V_667 = ( ( V_648 * 2349 ) + 135940 ) ;
else if ( V_648 >= 50 )
V_667 = ( ( V_648 * 964 ) + 29317 ) ;
else
V_667 = ( ( V_648 * 301 ) + 1004 ) ;
V_667 = V_667 * ( ( 150142 * V_668 ) / 10000 - 78642 ) ;
V_667 /= 100000 ;
V_669 = ( V_667 * V_4 -> V_134 . V_667 ) ;
V_670 = ( V_669 * V_668 ) / 10000 ;
V_670 /= 100 ;
F_270 ( V_4 ) ;
return V_4 -> V_134 . V_666 + V_670 ;
}
unsigned long F_274 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_144 ;
if ( F_55 ( V_2 ) -> V_102 != 5 )
return 0 ;
F_180 ( & V_405 ) ;
V_144 = F_273 ( V_4 ) ;
F_185 ( & V_405 ) ;
return V_144 ;
}
unsigned long F_275 ( void )
{
struct V_3 * V_4 ;
unsigned long V_672 , V_673 , V_280 = 0 ;
F_180 ( & V_405 ) ;
if ( ! V_674 )
goto V_675;
V_4 = V_674 ;
V_672 = F_265 ( V_4 ) ;
V_673 = F_273 ( V_4 ) ;
V_280 = V_672 + V_673 ;
V_675:
F_185 ( & V_405 ) ;
return V_280 ;
}
bool F_276 ( void )
{
struct V_3 * V_4 ;
bool V_280 = true ;
F_180 ( & V_405 ) ;
if ( ! V_674 ) {
V_280 = false ;
goto V_675;
}
V_4 = V_674 ;
if ( V_4 -> V_134 . V_435 > V_4 -> V_134 . V_414 )
V_4 -> V_134 . V_435 -- ;
V_675:
F_185 ( & V_405 ) ;
return V_280 ;
}
bool F_277 ( void )
{
struct V_3 * V_4 ;
bool V_280 = true ;
F_180 ( & V_405 ) ;
if ( ! V_674 ) {
V_280 = false ;
goto V_675;
}
V_4 = V_674 ;
if ( V_4 -> V_134 . V_435 < V_4 -> V_134 . V_436 )
V_4 -> V_134 . V_435 ++ ;
V_675:
F_185 ( & V_405 ) ;
return V_280 ;
}
bool F_278 ( void )
{
struct V_3 * V_4 ;
struct V_513 * V_514 ;
bool V_280 = false ;
int V_20 ;
F_180 ( & V_405 ) ;
if ( ! V_674 )
goto V_675;
V_4 = V_674 ;
F_223 (ring, dev_priv, i)
V_280 |= ! F_279 ( & V_514 -> V_676 ) ;
V_675:
F_185 ( & V_405 ) ;
return V_280 ;
}
bool F_280 ( void )
{
struct V_3 * V_4 ;
bool V_280 = true ;
F_180 ( & V_405 ) ;
if ( ! V_674 ) {
V_280 = false ;
goto V_675;
}
V_4 = V_674 ;
V_4 -> V_134 . V_435 = V_4 -> V_134 . V_416 ;
if ( ! F_175 ( V_4 -> V_2 , V_4 -> V_134 . V_416 ) )
V_280 = false ;
V_675:
F_185 ( & V_405 ) ;
return V_280 ;
}
static void
F_281 ( void )
{
void (* F_282)( void );
F_282 = F_283 ( V_677 ) ;
if ( F_282 ) {
F_282 () ;
F_284 ( V_677 ) ;
}
}
void F_285 ( struct V_3 * V_4 )
{
F_180 ( & V_405 ) ;
V_674 = V_4 ;
F_185 ( & V_405 ) ;
F_281 () ;
}
void F_286 ( void )
{
F_180 ( & V_405 ) ;
V_674 = NULL ;
F_185 ( & V_405 ) ;
}
static void F_287 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_678 ;
T_7 V_679 [ 16 ] ;
int V_20 ;
F_3 ( V_680 , 0 ) ;
F_22 ( V_680 ) ;
F_3 ( V_681 , 0x15040d00 ) ;
F_3 ( V_682 , 0x007f0000 ) ;
F_3 ( V_683 , 0x1e220004 ) ;
F_3 ( V_684 , 0x04000004 ) ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ )
F_3 ( V_685 + ( V_20 * 4 ) , 0 ) ;
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ )
F_3 ( V_686 + ( V_20 * 4 ) , 0 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ ) {
T_1 V_687 = F_2 ( V_432 + ( V_20 * 4 ) ) ;
unsigned long V_632 = F_264 ( V_687 ) ;
unsigned long V_688 = ( V_687 & V_433 ) >>
V_434 ;
unsigned long V_144 ;
V_144 = V_688 * V_688 ;
V_144 *= ( V_632 / 1000 ) ;
V_144 *= 255 ;
V_144 /= ( 127 * 127 * 900 ) ;
if ( V_144 > 0xff )
F_45 ( L_87 , V_144 ) ;
V_679 [ V_20 ] = V_144 ;
}
V_679 [ 14 ] = 0 ;
V_679 [ 15 ] = 0 ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
T_1 V_144 = ( V_679 [ V_20 * 4 ] << 24 ) | ( V_679 [ ( V_20 * 4 ) + 1 ] << 16 ) |
( V_679 [ ( V_20 * 4 ) + 2 ] << 8 ) | ( V_679 [ ( V_20 * 4 ) + 3 ] ) ;
F_3 ( V_689 + ( V_20 * 4 ) , V_144 ) ;
}
F_3 ( V_690 , 0 ) ;
F_3 ( V_691 , 0 ) ;
F_3 ( V_692 , 0x00007f00 ) ;
F_3 ( V_693 , 0x0000000e ) ;
F_3 ( V_694 , 0x000e0000 ) ;
F_3 ( V_695 , 0x68000300 ) ;
F_3 ( V_696 , 0x42000000 ) ;
F_3 ( V_697 , 0x00140031 ) ;
F_3 ( V_698 , 0 ) ;
F_3 ( V_699 , 0 ) ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
F_3 ( V_700 + ( V_20 * 4 ) , 0 ) ;
F_3 ( V_680 , 0x80000019 ) ;
V_678 = F_2 ( V_701 ) ;
V_4 -> V_134 . V_667 = ( V_678 & V_702 ) ;
}
void F_288 ( struct V_1 * V_2 )
{
V_89 . V_506 = F_214 ( V_2 , V_89 . V_506 ) ;
if ( F_202 ( V_2 ) )
F_252 ( V_2 ) ;
else if ( F_69 ( V_2 ) )
F_251 ( V_2 ) ;
}
void F_289 ( struct V_1 * V_2 )
{
if ( F_202 ( V_2 ) )
return;
else if ( F_69 ( V_2 ) )
F_253 ( V_2 ) ;
}
void F_290 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_149 ( F_291 ( V_4 ) ) ;
F_292 ( & V_4 -> V_455 . V_703 ) ;
F_293 ( & V_4 -> V_455 . V_72 ) ;
F_201 ( V_4 ) ;
}
void F_294 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_149 ( F_291 ( V_4 ) ) ;
if ( F_215 ( V_2 ) ) {
F_186 ( V_2 ) ;
F_257 ( V_2 ) ;
} else if ( F_55 ( V_2 ) -> V_102 >= 6 ) {
F_290 ( V_2 ) ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
if ( F_202 ( V_2 ) )
F_210 ( V_2 ) ;
else if ( F_69 ( V_2 ) )
F_211 ( V_2 ) ;
else
F_209 ( V_2 ) ;
V_4 -> V_455 . V_169 = false ;
F_39 ( & V_4 -> V_455 . V_487 ) ;
}
}
static void F_295 ( struct V_69 * V_72 )
{
struct V_3 * V_4 =
F_36 ( V_72 , struct V_3 ,
V_455 . V_703 . V_72 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
if ( F_202 ( V_2 ) ) {
F_254 ( V_2 ) ;
} else if ( F_69 ( V_2 ) ) {
F_255 ( V_2 ) ;
} else if ( F_128 ( V_2 ) ) {
F_222 ( V_2 ) ;
F_230 ( V_2 ) ;
} else {
F_225 ( V_2 ) ;
F_230 ( V_2 ) ;
}
V_4 -> V_455 . V_169 = true ;
F_39 ( & V_4 -> V_455 . V_487 ) ;
F_296 ( V_4 ) ;
}
void F_297 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_215 ( V_2 ) ) {
F_38 ( & V_2 -> V_73 ) ;
F_179 ( V_2 ) ;
F_259 ( V_2 ) ;
F_287 ( V_2 ) ;
F_39 ( & V_2 -> V_73 ) ;
} else if ( F_55 ( V_2 ) -> V_102 >= 6 ) {
if ( F_47 ( & V_4 -> V_455 . V_703 ,
F_298 ( V_704 ) ) )
F_299 ( V_4 ) ;
}
}
void F_300 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_455 . V_169 = false ;
F_297 ( V_2 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_705 , V_706 ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_65 ;
F_152 (pipe) {
F_3 ( F_303 ( V_65 ) ,
F_2 ( F_303 ( V_65 ) ) |
V_707 ) ;
F_304 ( V_4 , V_65 ) ;
}
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_373 , F_2 ( V_373 ) & ~ V_352 ) ;
F_3 ( V_374 , F_2 ( V_374 ) & ~ V_352 ) ;
F_3 ( V_375 , F_2 ( V_375 ) & ~ V_352 ) ;
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_708 = V_709 ;
V_708 |= V_710 |
V_711 |
V_712 ;
F_3 ( V_713 ,
V_714 |
V_715 ) ;
F_3 ( V_716 ,
V_717 ) ;
F_3 ( V_718 ,
( F_2 ( V_718 ) |
V_719 | V_720 ) ) ;
V_708 |= V_721 ;
F_3 ( V_384 ,
( F_2 ( V_384 ) |
V_385 ) ) ;
F_305 ( V_2 ) ;
if ( F_215 ( V_2 ) ) {
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 ) ;
F_3 ( V_718 ,
F_2 ( V_718 ) |
V_719 ) ;
}
F_3 ( V_722 , V_708 ) ;
F_3 ( V_718 ,
F_2 ( V_718 ) |
V_723 ) ;
F_3 ( V_724 ,
V_725 << 16 |
V_725 ) ;
F_3 ( V_726 ,
F_73 ( V_727 ) ) ;
F_3 ( V_726 , F_74 ( V_728 ) ) ;
F_302 ( V_2 ) ;
F_301 ( V_2 ) ;
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_65 ;
T_3 V_144 ;
F_3 ( V_705 , V_706 |
V_729 |
V_730 ) ;
F_3 ( V_731 , F_2 ( V_731 ) |
V_732 ) ;
F_152 (pipe) {
V_144 = F_2 ( F_308 ( V_65 ) ) ;
V_144 |= V_733 ;
V_144 &= ~ V_734 ;
if ( V_4 -> V_735 . V_736 )
V_144 |= V_734 ;
V_144 &= ~ V_737 ;
V_144 &= ~ V_738 ;
V_144 &= ~ V_739 ;
F_3 ( F_308 ( V_65 ) , V_144 ) ;
}
F_152 (pipe) {
F_3 ( F_309 ( V_65 ) ,
V_740 ) ;
}
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_114 ;
V_114 = F_2 ( V_318 ) ;
if ( ( V_114 & V_741 ) != V_742 )
F_5 ( L_88 ,
V_114 ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_708 = V_709 ;
F_3 ( V_722 , V_708 ) ;
F_3 ( V_718 ,
F_2 ( V_718 ) |
V_723 ) ;
F_3 ( V_743 ,
F_73 ( V_744 ) ) ;
if ( F_312 ( V_2 ) )
F_3 ( V_745 ,
F_73 ( V_746 ) ) ;
F_3 ( V_726 , F_74 ( V_728 ) ) ;
F_3 ( V_745 ,
V_747 | V_748 ) ;
F_305 ( V_2 ) ;
F_3 ( V_726 ,
F_74 ( V_749 ) ) ;
F_3 ( V_750 ,
F_2 ( V_750 ) |
V_751 |
V_752 ) ;
F_3 ( V_753 ,
V_754 |
V_755 ) ;
F_3 ( V_756 ,
F_73 ( V_757 ) ) ;
F_3 ( V_756 ,
F_73 ( V_758 ) ) ;
F_3 ( V_63 ,
F_2 ( V_63 ) |
V_64 | V_759 ) ;
F_3 ( V_718 ,
F_2 ( V_718 ) |
V_719 | V_720 ) ;
F_3 ( V_722 ,
F_2 ( V_722 ) |
V_721 |
V_712 ) ;
F_302 ( V_2 ) ;
F_307 ( V_2 ) ;
F_310 ( V_2 ) ;
}
static void F_313 ( struct V_3 * V_4 )
{
T_3 V_171 = F_2 ( V_760 ) ;
V_171 &= ~ V_761 ;
V_171 |= V_762 ;
V_171 |= V_763 ;
V_171 |= V_764 ;
F_3 ( V_760 , V_171 ) ;
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_765 == V_766 )
F_3 ( V_705 ,
F_2 ( V_705 ) |
V_767 ) ;
F_3 ( V_768 ,
F_2 ( V_768 ) |
V_740 ) ;
}
static void F_315 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_765 == V_766 ) {
T_3 V_144 = F_2 ( V_705 ) ;
V_144 &= ~ V_767 ;
F_3 ( V_705 , V_144 ) ;
}
}
static void F_316 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_65 V_65 ;
F_3 ( V_373 , 0 ) ;
F_3 ( V_374 , 0 ) ;
F_3 ( V_375 , 0 ) ;
F_3 ( V_769 ,
F_73 ( V_770 ) ) ;
F_3 ( V_769 ,
F_73 ( V_771 ) ) ;
F_3 ( V_772 ,
F_73 ( V_773 ) ) ;
F_3 ( V_772 ,
F_73 ( V_774 ) ) ;
F_3 ( V_775 , F_73 ( V_776 ) ) ;
F_3 ( V_756 ,
F_73 ( F_317 ( 2 ) ) ) ;
F_3 ( V_777 ,
F_73 ( V_778 ) ) ;
F_3 ( V_779 ,
F_73 ( V_780 ) ) ;
F_3 ( V_781 ,
F_73 ( V_782 ) ) ;
F_3 ( V_783 , F_2 ( V_783 ) | V_784 ) ;
F_3 ( V_785 ,
F_2 ( V_785 ) | V_786 ) ;
F_152 (pipe) {
F_3 ( F_33 ( V_65 ) ,
F_2 ( F_33 ( V_65 ) ) |
V_787 ) ;
}
F_3 ( V_788 ,
F_2 ( V_788 ) |
F_73 ( V_789 ) ) ;
F_3 ( V_760 ,
F_2 ( V_760 ) &
~ ( V_790 | V_791 ) ) ;
F_3 ( V_792 ,
V_747 | V_748 ) ;
F_3 ( V_793 ,
F_73 ( V_794 ) ) ;
F_3 ( V_795 , F_2 ( V_795 ) |
V_796 ) ;
F_3 ( V_797 ,
F_73 ( V_798 ) ) ;
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_305 ( V_2 ) ;
F_3 ( V_799 , V_800 ) ;
F_3 ( V_801 ,
F_73 ( V_802 ) ) ;
F_3 ( V_803 ,
F_2 ( V_803 ) |
V_804 ) ;
F_3 ( V_760 ,
F_2 ( V_760 ) & ~ V_791 ) ;
F_3 ( V_805 , F_74 ( V_728 ) ) ;
F_3 ( V_805 ,
F_74 ( V_806 ) ) ;
F_3 ( V_797 ,
F_73 ( V_807 ) ) ;
F_3 ( V_792 ,
V_747 | V_748 ) ;
F_3 ( V_783 , F_2 ( V_783 ) | V_784 ) ;
F_3 ( V_785 ,
F_2 ( V_785 ) | V_808 ) ;
F_314 ( V_2 ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_809 ;
F_305 ( V_2 ) ;
F_3 ( V_722 , V_709 ) ;
F_3 ( V_756 ,
F_73 ( V_810 ) ) ;
F_3 ( V_811 ,
V_812 |
V_813 ) ;
if ( F_320 ( V_2 ) )
F_3 ( V_779 ,
F_73 ( V_814 ) ) ;
F_3 ( V_805 , F_74 ( V_728 ) ) ;
F_3 ( V_815 ,
V_816 ) ;
F_3 ( V_817 ,
V_818 ) ;
F_3 ( V_819 ,
V_820 ) ;
if ( F_320 ( V_2 ) )
F_3 ( V_781 ,
F_73 ( V_782 ) ) ;
else {
F_3 ( V_781 ,
F_73 ( V_782 ) ) ;
F_3 ( V_821 ,
F_73 ( V_782 ) ) ;
}
F_3 ( V_822 , F_2 ( V_822 ) &
~ V_823 ) ;
F_3 ( V_753 ,
V_824 ) ;
F_3 ( V_803 ,
F_2 ( V_803 ) |
V_804 ) ;
F_302 ( V_2 ) ;
F_313 ( V_4 ) ;
if ( 0 ) {
F_3 ( V_805 ,
F_74 ( V_806 ) ) ;
}
F_3 ( V_797 ,
F_73 ( V_807 ) ) ;
F_3 ( V_792 ,
V_747 | V_748 ) ;
V_809 = F_2 ( V_825 ) ;
V_809 &= ~ V_826 ;
V_809 |= V_827 ;
F_3 ( V_825 , V_809 ) ;
if ( ! F_321 ( V_2 ) )
F_307 ( V_2 ) ;
F_310 ( V_2 ) ;
}
static void F_322 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_144 ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
V_144 = F_200 ( V_4 , V_495 ) ;
F_39 ( & V_4 -> V_455 . V_487 ) ;
switch ( ( V_144 >> 6 ) & 3 ) {
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
F_3 ( V_828 , V_829 ) ;
F_3 ( V_756 ,
F_73 ( V_810 ) ) ;
F_3 ( V_811 ,
V_812 |
V_813 ) ;
F_3 ( V_779 ,
F_73 ( V_830 |
V_814 ) ) ;
F_3 ( V_805 , F_74 ( V_728 ) ) ;
F_3 ( V_822 , F_2 ( V_822 ) &
~ V_823 ) ;
F_3 ( V_781 ,
F_73 ( V_782 ) ) ;
F_3 ( V_803 ,
F_2 ( V_803 ) |
V_804 ) ;
F_313 ( V_4 ) ;
F_3 ( V_753 ,
V_824 ) ;
F_3 ( V_831 ,
F_2 ( V_831 ) | V_832 ) ;
F_3 ( V_833 , V_834 ) ;
F_3 ( V_797 ,
F_73 ( V_807 ) ) ;
F_3 ( V_835 , V_836 ) ;
F_3 ( V_837 , V_838 ) ;
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_144 ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
V_144 = F_200 ( V_4 , V_839 ) ;
F_39 ( & V_4 -> V_455 . V_487 ) ;
switch ( ( V_144 >> 2 ) & 0x7 ) {
case 0 :
case 1 :
V_4 -> V_455 . V_840 = V_841 ;
V_4 -> V_124 = 1600 ;
break;
case 2 :
V_4 -> V_455 . V_840 = V_842 ;
V_4 -> V_124 = 1600 ;
break;
case 3 :
V_4 -> V_455 . V_840 = V_843 ;
V_4 -> V_124 = 2000 ;
break;
case 4 :
V_4 -> V_455 . V_840 = V_844 ;
V_4 -> V_124 = 1600 ;
break;
case 5 :
V_4 -> V_455 . V_840 = V_845 ;
V_4 -> V_124 = 1600 ;
break;
}
F_65 ( L_89 , V_4 -> V_124 ) ;
F_3 ( V_828 , V_829 ) ;
F_3 ( V_833 , V_834 ) ;
F_3 ( V_769 ,
F_73 ( V_770 ) ) ;
F_3 ( V_769 ,
F_73 ( V_771 ) ) ;
F_3 ( V_760 ,
F_2 ( V_760 ) &
~ ( V_790 | V_791 ) ) ;
F_3 ( V_793 ,
F_73 ( V_794 ) ) ;
F_3 ( V_750 , F_2 ( V_750 ) |
V_752 ) ;
F_3 ( V_795 , F_2 ( V_795 ) |
V_796 ) ;
F_3 ( V_772 ,
F_73 ( V_774 ) ) ;
F_3 ( V_837 , F_2 ( V_837 ) |
V_846 ) ;
F_3 ( V_793 ,
F_73 ( V_847 ) ) ;
F_3 ( V_781 ,
F_73 ( V_782 ) ) ;
F_3 ( V_750 , F_2 ( V_750 ) |
V_848 ) ;
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_708 ;
F_3 ( V_849 , 0 ) ;
F_3 ( V_850 , V_851 |
V_852 |
V_853 ) ;
F_3 ( V_854 , 0 ) ;
V_708 = V_829 |
V_855 |
V_856 ;
if ( F_325 ( V_2 ) )
V_708 |= V_857 ;
F_3 ( V_828 , V_708 ) ;
F_3 ( V_726 ,
F_73 ( V_727 ) ) ;
F_3 ( V_726 , F_74 ( V_728 ) ) ;
F_302 ( V_2 ) ;
}
static void F_326 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_849 , V_858 ) ;
F_3 ( V_850 , 0 ) ;
F_3 ( V_828 , 0 ) ;
F_3 ( V_854 , 0 ) ;
F_177 ( V_859 , 0 ) ;
F_3 ( V_860 ,
F_73 ( V_834 ) ) ;
F_3 ( V_726 , F_74 ( V_728 ) ) ;
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_849 , V_861 |
V_858 |
V_862 |
V_863 |
V_864 ) ;
F_3 ( V_850 , 0 ) ;
F_3 ( V_860 ,
F_73 ( V_834 ) ) ;
F_3 ( V_726 , F_74 ( V_728 ) ) ;
}
static void F_328 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_865 = F_2 ( V_866 ) ;
V_865 |= V_867 | V_868 |
V_869 ;
F_3 ( V_866 , V_865 ) ;
if ( F_71 ( V_2 ) )
F_3 ( V_870 , F_73 ( V_871 ) ) ;
F_3 ( V_870 , F_74 ( V_872 ) ) ;
F_3 ( V_152 , F_73 ( V_873 ) ) ;
F_3 ( V_860 , F_73 ( V_874 ) ) ;
}
static void F_329 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_849 , V_875 ) ;
F_3 ( V_876 , F_73 ( V_877 ) |
F_74 ( V_878 ) ) ;
}
static void F_330 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_828 , V_855 ) ;
}
void F_331 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_67 . V_879 ( V_2 ) ;
}
void F_332 ( struct V_1 * V_2 )
{
if ( F_333 ( V_2 ) )
F_315 ( V_2 ) ;
}
static bool F_334 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
return F_2 ( V_882 ) ==
( V_883 | V_884 ) ;
}
bool F_335 ( struct V_3 * V_4 ,
enum V_885 V_886 )
{
struct V_887 * V_888 ;
struct V_880 * V_881 ;
bool V_889 ;
int V_20 ;
if ( V_4 -> V_890 . V_891 )
return false ;
V_888 = & V_4 -> V_888 ;
V_889 = true ;
F_336 (i, power_well, BIT(domain), power_domains) {
if ( V_881 -> V_892 )
continue;
if ( ! V_881 -> V_893 ) {
V_889 = false ;
break;
}
}
return V_889 ;
}
bool F_337 ( struct V_3 * V_4 ,
enum V_885 V_886 )
{
struct V_887 * V_888 ;
bool V_280 ;
V_888 = & V_4 -> V_888 ;
F_38 ( & V_888 -> V_894 ) ;
V_280 = F_335 ( V_4 , V_886 ) ;
F_39 ( & V_888 -> V_894 ) ;
return V_280 ;
}
static void F_338 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_339 ( V_2 -> V_492 , V_895 ) ;
F_340 ( F_341 ( V_896 ) , V_897 ) ;
F_342 ( V_2 -> V_492 , V_895 ) ;
if ( F_128 ( V_2 ) )
F_343 ( V_4 ) ;
}
static void F_344 ( struct V_3 * V_4 ,
struct V_880 * V_881 , bool V_143 )
{
bool V_889 , V_898 ;
T_3 V_114 ;
V_114 = F_2 ( V_882 ) ;
V_889 = V_114 & V_884 ;
V_898 = V_114 & V_883 ;
if ( V_143 ) {
if ( ! V_898 )
F_3 ( V_882 ,
V_883 ) ;
if ( ! V_889 ) {
F_5 ( L_90 ) ;
if ( F_4 ( ( F_2 ( V_882 ) &
V_884 ) , 20 ) )
F_45 ( L_91 ) ;
}
F_338 ( V_4 ) ;
} else {
if ( V_898 ) {
F_3 ( V_882 , 0 ) ;
F_22 ( V_882 ) ;
F_5 ( L_92 ) ;
}
}
}
static void F_345 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_344 ( V_4 , V_881 , V_881 -> V_663 > 0 ) ;
if ( F_2 ( V_899 ) & V_883 )
F_3 ( V_899 , 0 ) ;
}
static void F_346 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_344 ( V_4 , V_881 , true ) ;
}
static void F_347 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_344 ( V_4 , V_881 , false ) ;
}
static void F_348 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
}
static bool F_349 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
return true ;
}
static void F_350 ( struct V_3 * V_4 ,
struct V_880 * V_881 , bool V_143 )
{
enum V_900 V_901 = V_881 -> V_902 ;
T_1 V_479 ;
T_1 V_903 ;
T_1 V_904 ;
V_479 = F_351 ( V_901 ) ;
V_903 = V_143 ? F_352 ( V_901 ) :
F_353 ( V_901 ) ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
#define F_354 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_354 )
goto V_601;
V_904 = F_200 ( V_4 , V_905 ) ;
V_904 &= ~ V_479 ;
V_904 |= V_903 ;
F_199 ( V_4 , V_905 , V_904 ) ;
if ( F_4 ( F_354 , 100 ) )
F_45 ( L_93 ,
V_903 ,
F_200 ( V_4 , V_905 ) ) ;
#undef F_354
V_601:
F_39 ( & V_4 -> V_455 . V_487 ) ;
}
static void F_355 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_350 ( V_4 , V_881 , V_881 -> V_663 > 0 ) ;
}
static void F_356 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_350 ( V_4 , V_881 , true ) ;
}
static void F_357 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_350 ( V_4 , V_881 , false ) ;
}
static bool F_358 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
int V_901 = V_881 -> V_902 ;
bool V_169 = false ;
T_1 V_479 ;
T_1 V_903 ;
T_1 V_904 ;
V_479 = F_351 ( V_901 ) ;
V_904 = F_352 ( V_901 ) ;
F_38 ( & V_4 -> V_455 . V_487 ) ;
V_903 = F_200 ( V_4 , V_906 ) & V_479 ;
F_149 ( V_903 != F_352 ( V_901 ) &&
V_903 != F_353 ( V_901 ) ) ;
if ( V_903 == V_904 )
V_169 = true ;
V_904 = F_200 ( V_4 , V_905 ) & V_479 ;
F_149 ( V_904 != V_903 ) ;
F_39 ( & V_4 -> V_455 . V_487 ) ;
return V_169 ;
}
static void F_359 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_360 ( V_881 -> V_902 != V_907 ) ;
F_350 ( V_4 , V_881 , true ) ;
F_180 ( & V_4 -> V_497 ) ;
F_361 ( V_4 ) ;
F_185 ( & V_4 -> V_497 ) ;
if ( V_4 -> V_888 . V_908 )
return;
F_362 ( V_4 -> V_2 ) ;
F_363 ( V_4 -> V_2 ) ;
}
static void F_364 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_360 ( V_881 -> V_902 != V_907 ) ;
F_180 ( & V_4 -> V_497 ) ;
F_365 ( V_4 ) ;
F_185 ( & V_4 -> V_497 ) ;
F_350 ( V_4 , V_881 , false ) ;
}
static void F_366 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
F_360 ( V_881 -> V_902 != V_909 ) ;
F_3 ( F_367 ( V_245 ) , F_2 ( F_367 ( V_245 ) ) |
V_910 | V_911 ) ;
F_368 ( 1 ) ;
F_350 ( V_4 , V_881 , true ) ;
F_3 ( V_912 , F_2 ( V_912 ) | V_913 ) ;
}
static void F_369 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_65 V_65 ;
F_360 ( V_881 -> V_902 != V_909 ) ;
F_152 (pipe)
F_370 ( V_4 , V_65 ) ;
F_3 ( V_912 , F_2 ( V_912 ) & ~ V_913 ) ;
F_350 ( V_4 , V_881 , false ) ;
}
static void F_371 ( struct V_3 * V_4 ,
struct V_880 * V_881 )
{
bool V_169 = V_881 -> V_914 -> V_889 ( V_4 , V_881 ) ;
if ( V_881 -> V_892 || ! V_89 . V_915 ) {
if ( ! V_169 )
goto V_916;
return;
}
if ( V_169 != ( V_881 -> V_663 > 0 ) )
goto V_916;
return;
V_916:
F_103 ( 1 , L_94 ,
V_881 -> V_329 , V_881 -> V_892 , V_169 ,
V_881 -> V_663 , V_89 . V_915 ) ;
}
void F_372 ( struct V_3 * V_4 ,
enum V_885 V_886 )
{
struct V_887 * V_888 ;
struct V_880 * V_881 ;
int V_20 ;
F_373 ( V_4 ) ;
V_888 = & V_4 -> V_888 ;
F_38 ( & V_888 -> V_894 ) ;
F_374 (i, power_well, BIT(domain), power_domains) {
if ( ! V_881 -> V_663 ++ ) {
F_5 ( L_95 , V_881 -> V_329 ) ;
V_881 -> V_914 -> V_143 ( V_4 , V_881 ) ;
V_881 -> V_893 = true ;
}
F_371 ( V_4 , V_881 ) ;
}
V_888 -> V_917 [ V_886 ] ++ ;
F_39 ( & V_888 -> V_894 ) ;
}
void F_375 ( struct V_3 * V_4 ,
enum V_885 V_886 )
{
struct V_887 * V_888 ;
struct V_880 * V_881 ;
int V_20 ;
V_888 = & V_4 -> V_888 ;
F_38 ( & V_888 -> V_894 ) ;
F_149 ( ! V_888 -> V_917 [ V_886 ] ) ;
V_888 -> V_917 [ V_886 ] -- ;
F_336 (i, power_well, BIT(domain), power_domains) {
F_149 ( ! V_881 -> V_663 ) ;
if ( ! -- V_881 -> V_663 && V_89 . V_915 ) {
F_5 ( L_96 , V_881 -> V_329 ) ;
V_881 -> V_893 = false ;
V_881 -> V_914 -> V_918 ( V_4 , V_881 ) ;
}
F_371 ( V_4 , V_881 ) ;
}
F_39 ( & V_888 -> V_894 ) ;
F_296 ( V_4 ) ;
}
int F_376 ( void )
{
struct V_3 * V_4 ;
if ( ! V_919 )
return - V_920 ;
V_4 = F_36 ( V_919 , struct V_3 ,
V_888 ) ;
F_372 ( V_4 , V_921 ) ;
return 0 ;
}
int F_377 ( void )
{
struct V_3 * V_4 ;
if ( ! V_919 )
return - V_920 ;
V_4 = F_36 ( V_919 , struct V_3 ,
V_888 ) ;
F_375 ( V_4 , V_921 ) ;
return 0 ;
}
int F_378 ( void )
{
struct V_3 * V_4 ;
if ( ! V_919 )
return - V_920 ;
V_4 = F_36 ( V_919 , struct V_3 ,
V_888 ) ;
return F_124 ( V_4 ) ;
}
static struct V_880 * F_379 ( struct V_3 * V_4 ,
enum V_900 V_901 )
{
struct V_887 * V_888 = & V_4 -> V_888 ;
struct V_880 * V_881 ;
int V_20 ;
F_374 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
if ( V_881 -> V_902 == V_901 )
return V_881 ;
}
return NULL ;
}
int F_380 ( struct V_3 * V_4 )
{
struct V_887 * V_888 = & V_4 -> V_888 ;
F_381 ( & V_888 -> V_894 ) ;
if ( F_56 ( V_4 -> V_2 ) ) {
F_382 ( V_888 , V_922 ) ;
V_919 = V_888 ;
} else if ( F_128 ( V_4 -> V_2 ) ) {
F_382 ( V_888 , V_923 ) ;
V_919 = V_888 ;
} else if ( F_69 ( V_4 -> V_2 ) ) {
F_382 ( V_888 , V_924 ) ;
} else {
F_382 ( V_888 , V_925 ) ;
}
return 0 ;
}
void F_383 ( struct V_3 * V_4 )
{
V_919 = NULL ;
}
static void F_384 ( struct V_3 * V_4 )
{
struct V_887 * V_888 = & V_4 -> V_888 ;
struct V_880 * V_881 ;
int V_20 ;
F_38 ( & V_888 -> V_894 ) ;
F_374 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_881 -> V_914 -> V_926 ( V_4 , V_881 ) ;
V_881 -> V_893 = V_881 -> V_914 -> V_889 ( V_4 ,
V_881 ) ;
}
F_39 ( & V_888 -> V_894 ) ;
}
static void F_385 ( struct V_3 * V_4 )
{
struct V_880 * V_927 =
F_379 ( V_4 , V_909 ) ;
struct V_880 * V_928 =
F_379 ( V_4 , V_907 ) ;
if ( ! V_927 -> V_914 -> V_889 ( V_4 , V_927 ) )
return;
if ( V_928 -> V_914 -> V_889 ( V_4 , V_928 ) &&
F_2 ( V_912 ) & V_913 )
return;
F_5 ( L_97 ) ;
V_928 -> V_914 -> V_143 ( V_4 , V_928 ) ;
V_927 -> V_914 -> V_918 ( V_4 , V_927 ) ;
}
void F_386 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_887 * V_888 = & V_4 -> V_888 ;
V_888 -> V_908 = true ;
if ( F_69 ( V_2 ) && ! F_202 ( V_2 ) ) {
F_38 ( & V_888 -> V_894 ) ;
F_385 ( V_4 ) ;
F_39 ( & V_888 -> V_894 ) ;
}
F_387 ( V_4 , true ) ;
F_384 ( V_4 ) ;
V_888 -> V_908 = false ;
}
void F_388 ( struct V_3 * V_4 )
{
F_373 ( V_4 ) ;
}
void F_389 ( struct V_3 * V_4 )
{
F_296 ( V_4 ) ;
}
void F_373 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_492 -> V_2 ;
if ( ! F_390 ( V_2 ) )
return;
F_391 ( V_929 ) ;
F_103 ( V_4 -> V_890 . V_891 , L_98 ) ;
}
void F_299 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_492 -> V_2 ;
if ( ! F_390 ( V_2 ) )
return;
F_103 ( V_4 -> V_890 . V_891 , L_99 ) ;
F_392 ( V_929 ) ;
}
void F_296 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_492 -> V_2 ;
if ( ! F_390 ( V_2 ) )
return;
F_393 ( V_929 ) ;
F_394 ( V_929 ) ;
}
void F_395 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_492 -> V_2 ;
if ( ! F_390 ( V_2 ) )
return;
F_396 ( V_929 ) ;
if ( ! F_216 ( V_2 ) ) {
F_397 ( L_100 ) ;
return;
}
F_398 ( V_929 , 10000 ) ;
F_393 ( V_929 ) ;
F_399 ( V_929 ) ;
F_394 ( V_929 ) ;
}
void F_400 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_492 -> V_2 ;
if ( ! F_390 ( V_2 ) )
return;
if ( ! F_216 ( V_2 ) )
return;
F_391 ( V_929 ) ;
F_401 ( V_929 ) ;
}
void F_402 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_52 ( V_2 ) ) {
if ( F_55 ( V_2 ) -> V_102 >= 7 ) {
V_4 -> V_67 . V_68 = F_29 ;
V_4 -> V_67 . V_75 = F_30 ;
V_4 -> V_67 . V_80 = F_28 ;
} else if ( F_55 ( V_2 ) -> V_102 >= 5 ) {
V_4 -> V_67 . V_68 = F_29 ;
V_4 -> V_67 . V_75 = F_24 ;
V_4 -> V_67 . V_80 = F_28 ;
} else if ( F_325 ( V_2 ) ) {
V_4 -> V_67 . V_68 = F_19 ;
V_4 -> V_67 . V_75 = F_15 ;
V_4 -> V_67 . V_80 = F_18 ;
} else {
V_4 -> V_67 . V_68 = F_14 ;
V_4 -> V_67 . V_75 = F_6 ;
V_4 -> V_67 . V_80 = F_1 ;
F_3 ( V_7 , 500 << V_34 ) ;
}
}
if ( F_71 ( V_2 ) )
F_62 ( V_2 ) ;
else if ( F_25 ( V_2 ) )
F_63 ( V_2 ) ;
if ( F_403 ( V_2 ) ) {
F_137 ( V_2 ) ;
if ( ( F_25 ( V_2 ) && V_4 -> V_159 . V_310 [ 1 ] &&
V_4 -> V_159 . V_311 [ 1 ] && V_4 -> V_159 . V_312 [ 1 ] ) ||
( ! F_25 ( V_2 ) && V_4 -> V_159 . V_310 [ 0 ] &&
V_4 -> V_159 . V_311 [ 0 ] && V_4 -> V_159 . V_312 [ 0 ] ) ) {
V_4 -> V_67 . V_399 = F_160 ;
V_4 -> V_67 . V_400 = F_161 ;
} else {
F_5 ( L_101
L_102 ) ;
}
if ( F_25 ( V_2 ) )
V_4 -> V_67 . V_879 = F_306 ;
else if ( F_27 ( V_2 ) )
V_4 -> V_67 . V_879 = F_311 ;
else if ( F_32 ( V_2 ) )
V_4 -> V_67 . V_879 = F_319 ;
else if ( F_56 ( V_2 ) )
V_4 -> V_67 . V_879 = F_318 ;
else if ( F_55 ( V_2 ) -> V_102 == 8 )
V_4 -> V_67 . V_879 = F_316 ;
} else if ( F_202 ( V_2 ) ) {
V_4 -> V_67 . V_399 = F_92 ;
V_4 -> V_67 . V_879 =
F_323 ;
} else if ( F_69 ( V_2 ) ) {
V_4 -> V_67 . V_399 = F_92 ;
V_4 -> V_67 . V_879 =
F_322 ;
} else if ( F_71 ( V_2 ) ) {
if ( ! F_66 ( F_83 ( V_2 ) ,
V_4 -> V_128 ,
V_4 -> V_118 ,
V_4 -> V_124 ) ) {
F_397 ( L_103
L_104
L_105 ,
( V_4 -> V_128 == 1 ) ? L_106 : L_107 ,
V_4 -> V_118 , V_4 -> V_124 ) ;
F_68 ( V_4 , false ) ;
V_4 -> V_67 . V_399 = NULL ;
} else
V_4 -> V_67 . V_399 = F_82 ;
V_4 -> V_67 . V_879 = F_328 ;
} else if ( F_57 ( V_2 ) ) {
V_4 -> V_67 . V_399 = F_95 ;
V_4 -> V_67 . V_879 = F_324 ;
} else if ( F_10 ( V_2 ) ) {
V_4 -> V_67 . V_399 = F_96 ;
if ( F_70 ( V_2 ) )
V_4 -> V_67 . V_879 = F_326 ;
else if ( F_404 ( V_2 ) )
V_4 -> V_67 . V_879 = F_327 ;
} else if ( F_405 ( V_2 ) ) {
V_4 -> V_67 . V_399 = F_97 ;
V_4 -> V_67 . V_265 = F_76 ;
V_4 -> V_67 . V_879 = F_328 ;
} else if ( F_9 ( V_2 ) ) {
if ( F_55 ( V_2 ) -> V_302 == 1 ) {
V_4 -> V_67 . V_399 = F_99 ;
V_4 -> V_67 . V_265 = F_78 ;
} else {
V_4 -> V_67 . V_399 = F_97 ;
V_4 -> V_67 . V_265 = F_77 ;
}
if ( F_406 ( V_2 ) || F_407 ( V_2 ) )
V_4 -> V_67 . V_879 = F_329 ;
else
V_4 -> V_67 . V_879 = F_330 ;
} else {
F_45 ( L_108 ) ;
}
}
int F_227 ( struct V_3 * V_4 , T_7 V_930 , T_1 * V_144 )
{
F_149 ( ! F_168 ( & V_4 -> V_455 . V_487 ) ) ;
if ( F_2 ( V_931 ) & V_932 ) {
F_65 ( L_109 ) ;
return - V_933 ;
}
F_3 ( V_934 , * V_144 ) ;
F_3 ( V_931 , V_932 | V_930 ) ;
if ( F_4 ( ( F_2 ( V_931 ) & V_932 ) == 0 ,
500 ) ) {
F_45 ( L_110 , V_930 ) ;
return - V_935 ;
}
* V_144 = F_2 ( V_934 ) ;
F_3 ( V_934 , 0 ) ;
return 0 ;
}
int F_226 ( struct V_3 * V_4 , T_7 V_930 , T_1 V_144 )
{
F_149 ( ! F_168 ( & V_4 -> V_455 . V_487 ) ) ;
if ( F_2 ( V_931 ) & V_932 ) {
F_65 ( L_111 ) ;
return - V_933 ;
}
F_3 ( V_934 , V_144 ) ;
F_3 ( V_931 , V_932 | V_930 ) ;
if ( F_4 ( ( F_2 ( V_931 ) & V_932 ) == 0 ,
500 ) ) {
F_45 ( L_112 , V_930 ) ;
return - V_935 ;
}
F_3 ( V_934 , 0 ) ;
return 0 ;
}
static int F_408 ( struct V_3 * V_4 , int V_144 )
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
return F_123 ( V_4 -> V_124 * ( V_144 + 6 - 0xbd ) , 4 * div ) ;
}
static int F_409 ( struct V_3 * V_4 , int V_144 )
{
int V_936 ;
switch ( V_4 -> V_124 ) {
case 800 :
V_936 = 10 ;
break;
case 1066 :
V_936 = 12 ;
break;
case 1333 :
V_936 = 16 ;
break;
default:
return - 1 ;
}
return F_123 ( 4 * V_936 * V_144 , V_4 -> V_124 ) + 0xbd - 6 ;
}
static int F_410 ( struct V_3 * V_4 , int V_144 )
{
int div , V_632 ;
switch ( V_4 -> V_455 . V_840 ) {
case 200 :
div = 5 ;
break;
case 267 :
div = 6 ;
break;
case 320 :
case 333 :
case 400 :
div = 8 ;
break;
default:
return - 1 ;
}
V_632 = ( F_123 ( ( V_4 -> V_455 . V_840 * V_144 ) , 2 * div ) / 2 ) ;
return V_632 ;
}
static int F_411 ( struct V_3 * V_4 , int V_144 )
{
int V_936 , V_937 ;
switch ( V_4 -> V_455 . V_840 ) {
case 200 :
V_936 = 5 ;
break;
case 267 :
V_936 = 6 ;
break;
case 320 :
case 333 :
case 400 :
V_936 = 8 ;
break;
default:
return - 1 ;
}
V_937 = ( F_123 ( ( V_144 * 2 * V_936 ) , V_4 -> V_455 . V_840 ) * 2 ) ;
return V_937 ;
}
int F_204 ( struct V_3 * V_4 , int V_144 )
{
int V_280 = - 1 ;
if ( F_202 ( V_4 -> V_2 ) )
V_280 = F_410 ( V_4 , V_144 ) ;
else if ( F_69 ( V_4 -> V_2 ) )
V_280 = F_408 ( V_4 , V_144 ) ;
return V_280 ;
}
int F_412 ( struct V_3 * V_4 , int V_144 )
{
int V_280 = - 1 ;
if ( F_202 ( V_4 -> V_2 ) )
V_280 = F_411 ( V_4 , V_144 ) ;
else if ( F_69 ( V_4 -> V_2 ) )
V_280 = F_409 ( V_4 , V_144 ) ;
return V_280 ;
}
void F_413 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_381 ( & V_4 -> V_455 . V_487 ) ;
F_46 ( & V_4 -> V_455 . V_703 ,
F_295 ) ;
V_4 -> V_890 . V_891 = false ;
V_4 -> V_890 . V_938 = false ;
}
