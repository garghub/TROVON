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
if ( V_4 -> V_21 . V_63 )
V_39 |= V_64 ;
F_3 ( V_58 , V_39 | V_47 ) ;
if ( F_32 ( V_2 ) ) {
F_3 ( V_65 ,
F_2 ( V_65 ) |
V_66 ) ;
} else {
F_3 ( F_33 ( V_18 -> V_67 ) ,
F_2 ( F_33 ( V_18 -> V_67 ) ) |
V_68 ) ;
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
if ( ! V_4 -> V_69 . V_70 )
return false ;
return V_4 -> V_69 . V_70 ( V_2 ) ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_36 ( V_2 ) )
return;
F_3 ( V_72 , V_71 ) ;
}
static void F_37 ( struct V_73 * V_74 )
{
struct V_75 * V_76 =
F_38 ( F_39 ( V_74 ) ,
struct V_75 , V_76 ) ;
struct V_1 * V_2 = V_76 -> V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_40 ( & V_2 -> V_77 ) ;
if ( V_76 == V_4 -> V_21 . V_78 ) {
if ( V_76 -> V_12 -> V_15 -> V_14 == V_76 -> V_14 ) {
V_4 -> V_69 . V_79 ( V_76 -> V_12 ) ;
V_4 -> V_21 . V_30 = F_8 ( V_76 -> V_12 ) -> V_30 ;
V_4 -> V_21 . V_80 = V_76 -> V_12 -> V_15 -> V_14 -> V_81 . V_82 ;
V_4 -> V_21 . V_33 = V_76 -> V_12 -> V_33 ;
}
V_4 -> V_21 . V_78 = NULL ;
}
F_41 ( & V_2 -> V_77 ) ;
F_42 ( V_76 ) ;
}
static void F_43 ( struct V_3 * V_4 )
{
if ( V_4 -> V_21 . V_78 == NULL )
return;
F_5 ( L_5 ) ;
if ( F_44 ( & V_4 -> V_21 . V_78 -> V_76 ) )
F_42 ( V_4 -> V_21 . V_78 ) ;
V_4 -> V_21 . V_78 = NULL ;
}
static void F_45 ( struct V_11 * V_12 )
{
struct V_75 * V_76 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_69 . V_79 )
return;
F_43 ( V_4 ) ;
V_76 = F_46 ( sizeof( * V_76 ) , V_83 ) ;
if ( V_76 == NULL ) {
F_47 ( L_6 ) ;
V_4 -> V_69 . V_79 ( V_12 ) ;
return;
}
V_76 -> V_12 = V_12 ;
V_76 -> V_14 = V_12 -> V_15 -> V_14 ;
F_48 ( & V_76 -> V_76 , F_37 ) ;
V_4 -> V_21 . V_78 = V_76 ;
F_49 ( & V_76 -> V_76 , F_50 ( 50 ) ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_43 ( V_4 ) ;
if ( ! V_4 -> V_69 . V_84 )
return;
V_4 -> V_69 . V_84 ( V_2 ) ;
V_4 -> V_21 . V_30 = - 1 ;
}
static bool F_52 ( struct V_3 * V_4 ,
enum V_85 V_86 )
{
if ( V_4 -> V_21 . V_85 == V_86 )
return false ;
V_4 -> V_21 . V_85 = V_86 ;
return true ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 = NULL , * V_87 ;
struct V_18 * V_18 ;
struct V_13 * V_14 ;
struct V_16 * V_17 ;
const struct V_88 * V_89 ;
unsigned int V_90 , V_91 ;
if ( ! F_54 ( V_2 ) ) {
F_52 ( V_4 , V_92 ) ;
return;
}
if ( ! V_93 . V_94 ) {
if ( F_52 ( V_4 , V_95 ) )
F_5 ( L_7 ) ;
return;
}
F_55 (dev, tmp_crtc) {
if ( F_56 ( V_87 ) &&
F_8 ( V_87 ) -> V_96 ) {
if ( V_12 ) {
if ( F_52 ( V_4 , V_97 ) )
F_5 ( L_8 ) ;
goto V_98;
}
V_12 = V_87 ;
}
}
if ( ! V_12 || V_12 -> V_15 -> V_14 == NULL ) {
if ( F_52 ( V_4 , V_99 ) )
F_5 ( L_9 ) ;
goto V_98;
}
V_18 = F_8 ( V_12 ) ;
V_14 = V_12 -> V_15 -> V_14 ;
V_17 = F_7 ( V_14 ) ;
V_89 = & V_18 -> V_100 . V_89 ;
if ( V_93 . V_79 < 0 ) {
if ( F_52 ( V_4 , V_101 ) )
F_5 ( L_10 ) ;
goto V_98;
}
if ( ! V_93 . V_79 ) {
if ( F_52 ( V_4 , V_95 ) )
F_5 ( L_7 ) ;
goto V_98;
}
if ( ( V_89 -> V_102 & V_103 ) ||
( V_89 -> V_102 & V_104 ) ) {
if ( F_52 ( V_4 , V_105 ) )
F_5 ( L_11
L_12 ) ;
goto V_98;
}
if ( F_57 ( V_2 ) -> V_106 >= 8 || F_58 ( V_2 ) ) {
V_90 = 4096 ;
V_91 = 4096 ;
} else if ( F_59 ( V_2 ) || F_57 ( V_2 ) -> V_106 >= 5 ) {
V_90 = 4096 ;
V_91 = 2048 ;
} else {
V_90 = 2048 ;
V_91 = 1536 ;
}
if ( V_18 -> V_100 . V_107 > V_90 ||
V_18 -> V_100 . V_108 > V_91 ) {
if ( F_52 ( V_4 , V_109 ) )
F_5 ( L_13 ) ;
goto V_98;
}
if ( ( F_57 ( V_2 ) -> V_106 < 4 || F_60 ( V_2 ) ) &&
V_18 -> V_30 != V_110 ) {
if ( F_52 ( V_4 , V_111 ) )
F_5 ( L_14 ) ;
goto V_98;
}
if ( V_17 -> V_112 != V_113 ||
V_17 -> V_38 == V_114 ) {
if ( F_52 ( V_4 , V_115 ) )
F_5 ( L_15 ) ;
goto V_98;
}
if ( F_57 ( V_2 ) -> V_106 <= 4 && ! F_59 ( V_2 ) &&
F_61 ( V_12 -> V_15 ) -> V_116 != F_62 ( V_117 ) ) {
if ( F_52 ( V_4 , V_105 ) )
F_5 ( L_16 ) ;
goto V_98;
}
if ( F_63 () )
goto V_98;
if ( F_64 ( V_2 , V_17 -> V_81 . V_22 ,
F_17 ( V_14 -> V_41 , 0 ) ) ) {
if ( F_52 ( V_4 , V_118 ) )
F_5 ( L_17 ) ;
goto V_98;
}
if ( V_4 -> V_21 . V_30 == V_18 -> V_30 &&
V_4 -> V_21 . V_80 == V_14 -> V_81 . V_82 &&
V_4 -> V_21 . V_33 == V_12 -> V_33 )
return;
if ( F_34 ( V_2 ) ) {
F_5 ( L_18 ) ;
F_51 ( V_2 ) ;
}
F_45 ( V_12 ) ;
V_4 -> V_21 . V_85 = V_119 ;
return;
V_98:
if ( F_34 ( V_2 ) ) {
F_5 ( L_19 ) ;
F_51 ( V_2 ) ;
}
F_65 ( V_2 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_120 ;
V_120 = F_2 ( V_121 ) ;
switch ( V_120 & V_122 ) {
case V_123 :
V_4 -> V_124 = 533 ;
break;
case V_125 :
V_4 -> V_124 = 800 ;
break;
case V_126 :
V_4 -> V_124 = 667 ;
break;
case V_127 :
V_4 -> V_124 = 400 ;
break;
}
switch ( V_120 & V_128 ) {
case V_129 :
V_4 -> V_130 = 533 ;
break;
case V_131 :
V_4 -> V_130 = 667 ;
break;
case V_132 :
V_4 -> V_130 = 800 ;
break;
}
V_120 = F_2 ( V_133 ) ;
V_4 -> V_134 = ( V_120 & V_135 ) ? 1 : 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_136 , V_137 ;
V_136 = F_68 ( V_138 ) ;
V_137 = F_68 ( V_139 ) ;
switch ( V_136 & 0xff ) {
case 0xc :
V_4 -> V_130 = 800 ;
break;
case 0x10 :
V_4 -> V_130 = 1066 ;
break;
case 0x14 :
V_4 -> V_130 = 1333 ;
break;
case 0x18 :
V_4 -> V_130 = 1600 ;
break;
default:
F_69 ( L_20 ,
V_136 & 0xff ) ;
V_4 -> V_130 = 0 ;
break;
}
V_4 -> V_140 . V_141 = V_4 -> V_130 ;
switch ( V_137 & 0x3ff ) {
case 0x00c :
V_4 -> V_124 = 3200 ;
break;
case 0x00e :
V_4 -> V_124 = 3733 ;
break;
case 0x010 :
V_4 -> V_124 = 4266 ;
break;
case 0x012 :
V_4 -> V_124 = 4800 ;
break;
case 0x014 :
V_4 -> V_124 = 5333 ;
break;
case 0x016 :
V_4 -> V_124 = 5866 ;
break;
case 0x018 :
V_4 -> V_124 = 6400 ;
break;
default:
F_69 ( L_21 ,
V_137 & 0x3ff ) ;
V_4 -> V_124 = 0 ;
break;
}
if ( V_4 -> V_124 == 3200 ) {
V_4 -> V_140 . V_142 = 0 ;
} else if ( V_4 -> V_124 > 3200 && V_4 -> V_124 <= 4800 ) {
V_4 -> V_140 . V_142 = 1 ;
} else {
V_4 -> V_140 . V_142 = 2 ;
}
}
static const struct V_143 * F_70 ( int V_144 ,
int V_134 ,
int V_145 ,
int V_146 )
{
const struct V_143 * V_147 ;
int V_20 ;
if ( V_145 == 0 || V_146 == 0 )
return NULL ;
for ( V_20 = 0 ; V_20 < F_71 ( V_148 ) ; V_20 ++ ) {
V_147 = & V_148 [ V_20 ] ;
if ( V_144 == V_147 -> V_144 &&
V_134 == V_147 -> V_134 &&
V_145 == V_147 -> V_124 && V_146 == V_147 -> V_130 )
return V_147 ;
}
F_5 ( L_22 ) ;
return NULL ;
}
void F_72 ( struct V_3 * V_4 , bool V_149 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_150 ;
if ( F_73 ( V_2 ) ) {
F_3 ( V_151 , V_149 ? V_152 : 0 ) ;
} else if ( F_59 ( V_2 ) || F_74 ( V_2 ) ) {
F_3 ( V_153 , V_149 ? V_154 : 0 ) ;
} else if ( F_75 ( V_2 ) ) {
V_150 = F_2 ( V_155 ) & ~ V_156 ;
V_150 |= V_149 ? V_156 : 0 ;
F_3 ( V_155 , V_150 ) ;
} else if ( F_76 ( V_2 ) || F_12 ( V_2 ) ) {
V_150 = V_149 ? F_77 ( V_154 ) :
F_78 ( V_154 ) ;
F_3 ( V_153 , V_150 ) ;
} else if ( F_79 ( V_2 ) ) {
V_150 = V_149 ? F_77 ( V_157 ) :
F_78 ( V_157 ) ;
F_3 ( V_158 , V_150 ) ;
} else {
return;
}
F_5 ( L_23 ,
V_149 ? L_24 : L_25 ) ;
}
static int F_80 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_159 = F_2 ( V_160 ) ;
int V_22 ;
V_22 = V_159 & 0x7f ;
if ( V_30 )
V_22 = ( ( V_159 >> V_161 ) & 0x7f ) - V_22 ;
F_5 ( L_26 , V_159 ,
V_30 ? L_27 : L_28 , V_22 ) ;
return V_22 ;
}
static int F_81 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_159 = F_2 ( V_160 ) ;
int V_22 ;
V_22 = V_159 & 0x1ff ;
if ( V_30 )
V_22 = ( ( V_159 >> V_162 ) & 0x1ff ) - V_22 ;
V_22 >>= 1 ;
F_5 ( L_26 , V_159 ,
V_30 ? L_27 : L_28 , V_22 ) ;
return V_22 ;
}
static int F_82 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_159 = F_2 ( V_160 ) ;
int V_22 ;
V_22 = V_159 & 0x7f ;
V_22 >>= 2 ;
F_5 ( L_26 , V_159 ,
V_30 ? L_27 : L_28 ,
V_22 ) ;
return V_22 ;
}
static unsigned long F_83 ( unsigned long V_163 ,
const struct V_164 * V_165 ,
int V_166 ,
int V_167 ,
unsigned long V_168 )
{
long V_169 , V_170 ;
V_169 = ( ( V_163 / 1000 ) * V_167 * V_168 ) /
1000 ;
V_169 = F_84 ( V_169 , V_165 -> V_171 ) ;
F_5 ( L_29 , V_169 ) ;
V_170 = V_166 - ( V_169 + V_165 -> V_172 ) ;
F_5 ( L_30 , V_170 ) ;
if ( V_170 > ( long ) V_165 -> V_173 )
V_170 = V_165 -> V_173 ;
if ( V_170 <= 0 )
V_170 = V_165 -> V_174 ;
if ( V_170 <= 8 )
V_170 = 8 ;
return V_170 ;
}
static struct V_11 * F_85 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_175 = NULL ;
F_55 (dev, crtc) {
if ( F_56 ( V_12 ) ) {
if ( V_175 )
return NULL ;
V_175 = V_12 ;
}
}
return V_175 ;
}
static void F_86 ( struct V_11 * V_176 )
{
struct V_1 * V_2 = V_176 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_143 * V_147 ;
T_1 V_177 ;
unsigned long V_165 ;
V_147 = F_70 ( F_87 ( V_2 ) , V_4 -> V_134 ,
V_4 -> V_124 , V_4 -> V_130 ) ;
if ( ! V_147 ) {
F_5 ( L_22 ) ;
F_72 ( V_4 , false ) ;
return;
}
V_12 = F_85 ( V_2 ) ;
if ( V_12 ) {
const struct V_88 * V_89 ;
int V_167 = V_12 -> V_15 -> V_14 -> V_178 / 8 ;
int clock ;
V_89 = & F_8 ( V_12 ) -> V_100 . V_89 ;
clock = V_89 -> V_179 ;
V_165 = F_83 ( clock , & V_180 ,
V_180 . V_166 ,
V_167 , V_147 -> V_181 ) ;
V_177 = F_2 ( V_182 ) ;
V_177 &= ~ V_183 ;
V_177 |= V_165 << V_184 ;
F_3 ( V_182 , V_177 ) ;
F_5 ( L_31 , V_177 ) ;
V_165 = F_83 ( clock , & V_185 ,
V_180 . V_166 ,
V_167 , V_147 -> V_186 ) ;
V_177 = F_2 ( V_155 ) ;
V_177 &= ~ V_187 ;
V_177 |= ( V_165 & 0x3f ) << V_188 ;
F_3 ( V_155 , V_177 ) ;
V_165 = F_83 ( clock , & V_189 ,
V_189 . V_166 ,
V_167 , V_147 -> V_190 ) ;
V_177 = F_2 ( V_155 ) ;
V_177 &= ~ V_191 ;
V_177 |= V_165 & V_191 ;
F_3 ( V_155 , V_177 ) ;
V_165 = F_83 ( clock , & V_192 ,
V_189 . V_166 ,
V_167 , V_147 -> V_193 ) ;
V_177 = F_2 ( V_155 ) ;
V_177 &= ~ V_194 ;
V_177 |= ( V_165 & 0x3f ) << V_195 ;
F_3 ( V_155 , V_177 ) ;
F_5 ( L_32 , V_177 ) ;
F_72 ( V_4 , true ) ;
} else {
F_72 ( V_4 , false ) ;
}
}
static bool F_88 ( struct V_1 * V_2 ,
int V_30 ,
const struct V_164 * V_69 ,
int V_196 ,
const struct V_164 * V_197 ,
int V_198 ,
int * V_199 ,
int * V_200 )
{
struct V_11 * V_12 ;
const struct V_88 * V_89 ;
int V_201 , V_202 , clock , V_167 ;
int V_203 , V_204 ;
int V_205 , V_206 ;
V_12 = F_89 ( V_2 , V_30 ) ;
if ( ! F_56 ( V_12 ) ) {
* V_200 = V_197 -> V_172 ;
* V_199 = V_69 -> V_172 ;
return false ;
}
V_89 = & F_8 ( V_12 ) -> V_100 . V_89 ;
clock = V_89 -> V_179 ;
V_201 = V_89 -> V_207 ;
V_202 = F_8 ( V_12 ) -> V_100 . V_107 ;
V_167 = V_12 -> V_15 -> V_14 -> V_178 / 8 ;
V_205 = ( ( clock * V_167 / 1000 ) * V_196 ) / 1000 ;
V_206 = V_69 -> V_166 * V_69 -> V_171 - V_202 * 8 ;
if ( V_206 > 0 )
V_205 += V_206 ;
V_205 = F_84 ( V_205 , V_69 -> V_171 ) ;
* V_199 = V_205 + V_69 -> V_172 ;
if ( * V_199 > ( int ) V_69 -> V_173 )
* V_199 = V_69 -> V_173 ;
V_203 = F_90 ( V_201 * 1000 / clock , 1 ) ;
V_204 = ( V_198 / V_203 + 1000 ) / 1000 ;
V_205 = V_204 * F_8 ( V_12 ) -> V_208 * V_167 ;
V_206 = V_197 -> V_166 * V_197 -> V_171 - V_202 * 8 ;
if ( V_206 > 0 )
V_205 += V_206 ;
V_205 = F_84 ( V_205 , V_197 -> V_171 ) ;
* V_200 = V_205 + V_197 -> V_172 ;
if ( * V_200 > ( int ) V_197 -> V_173 )
* V_200 = ( int ) V_197 -> V_173 ;
return true ;
}
static bool F_91 ( struct V_1 * V_2 ,
int V_209 , int V_200 ,
const struct V_164 * V_69 ,
const struct V_164 * V_197 )
{
F_5 ( L_33 ,
V_209 , V_200 ) ;
if ( V_209 > V_69 -> V_173 ) {
F_5 ( L_34 ,
V_209 , V_69 -> V_173 ) ;
return false ;
}
if ( V_200 > V_197 -> V_173 ) {
F_5 ( L_35 ,
V_200 , V_197 -> V_173 ) ;
return false ;
}
if ( ! ( V_209 || V_200 ) ) {
F_5 ( L_36 ) ;
return false ;
}
return true ;
}
static bool F_92 ( struct V_1 * V_2 ,
int V_30 ,
int V_168 ,
const struct V_164 * V_69 ,
const struct V_164 * V_197 ,
int * V_209 , int * V_200 )
{
struct V_11 * V_12 ;
const struct V_88 * V_89 ;
int V_202 , V_201 , V_167 , clock ;
unsigned long V_203 ;
int V_204 , V_210 ;
int V_211 , V_212 ;
int V_205 ;
if ( ! V_168 ) {
* V_209 = * V_200 = 0 ;
return false ;
}
V_12 = F_89 ( V_2 , V_30 ) ;
V_89 = & F_8 ( V_12 ) -> V_100 . V_89 ;
clock = V_89 -> V_179 ;
V_201 = V_89 -> V_207 ;
V_202 = F_8 ( V_12 ) -> V_100 . V_107 ;
V_167 = V_12 -> V_15 -> V_14 -> V_178 / 8 ;
V_203 = F_90 ( V_201 * 1000 / clock , 1 ) ;
V_204 = ( V_168 / V_203 + 1000 ) / 1000 ;
V_210 = V_202 * V_167 ;
V_211 = ( ( clock * V_167 / 1000 ) * V_168 ) / 1000 ;
V_212 = V_204 * V_210 ;
V_205 = F_84 ( F_93 ( V_211 , V_212 ) , V_69 -> V_171 ) ;
* V_209 = V_205 + V_69 -> V_172 ;
V_205 = V_204 * V_167 * F_8 ( V_12 ) -> V_208 ;
V_205 = F_84 ( V_205 , V_197 -> V_171 ) ;
* V_200 = V_205 + V_197 -> V_172 ;
return F_91 ( V_2 ,
* V_209 , * V_200 ,
V_69 , V_197 ) ;
}
static bool F_94 ( struct V_11 * V_12 ,
int V_167 ,
int * V_213 ,
int * V_214 )
{
int V_205 ;
int clock = F_8 ( V_12 ) -> V_100 . V_89 . V_179 ;
if ( F_95 ( clock == 0 , L_37 ) )
return false ;
if ( F_95 ( V_167 == 0 , L_38 ) )
return false ;
V_205 = F_84 ( clock , 1000 ) * V_167 ;
* V_213 = ( V_205 > 128 ) ? V_215 :
V_216 ;
* V_214 = ( 64 * ( * V_213 ) * 4 ) / V_205 ;
if ( * V_214 > V_217 )
* V_214 = V_217 ;
return true ;
}
static void F_96 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_2 -> V_5 ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
int V_167 ;
int V_214 ;
enum V_67 V_67 = V_18 -> V_67 ;
int V_218 , V_213 , V_219 ;
V_219 = F_2 ( F_97 ( V_67 ) ) & ~ ( V_220 |
V_217 | V_221 |
( V_217 << V_222 ) ) ;
if ( ! F_56 ( V_12 ) ) {
F_3 ( F_97 ( V_67 ) , V_219 ) ;
return;
}
V_167 = V_12 -> V_15 -> V_14 -> V_178 / 8 ;
if ( F_94 ( V_12 , V_167 , & V_213 , & V_214 ) ) {
V_218 = ( V_213 == V_215 ) ?
V_220 :
V_223 ;
V_219 |= V_218 | V_214 ;
}
V_167 = 4 ;
if ( V_18 -> V_224 &&
F_94 ( V_12 , V_167 , & V_213 , & V_214 ) ) {
V_218 = ( V_213 == V_215 ) ?
V_221 :
V_225 ;
V_219 |= V_218 | ( V_214 << V_222 ) ;
}
F_3 ( F_97 ( V_67 ) , V_219 ) ;
}
static void F_98 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_226 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_227 , V_228 , V_229 , V_230 ;
int V_231 , V_186 ;
int V_232 , V_233 ;
unsigned int V_175 = 0 ;
bool V_234 ;
F_96 ( V_12 ) ;
if ( F_88 ( V_2 , V_235 ,
& V_236 , V_237 ,
& V_238 , V_237 ,
& V_227 , & V_229 ) )
V_175 |= 1 << V_235 ;
if ( F_88 ( V_2 , V_239 ,
& V_236 , V_237 ,
& V_238 , V_237 ,
& V_228 , & V_230 ) )
V_175 |= 1 << V_239 ;
if ( F_99 ( V_175 ) &&
F_92 ( V_2 , F_100 ( V_175 ) - 1 ,
V_226 ,
& V_236 ,
& V_238 ,
& V_231 , & V_233 ) &&
F_92 ( V_2 , F_100 ( V_175 ) - 1 ,
2 * V_226 ,
& V_236 ,
& V_238 ,
& V_232 , & V_186 ) ) {
V_234 = true ;
} else {
V_234 = false ;
F_72 ( V_4 , false ) ;
V_231 = V_186 = 0 ;
}
F_5 ( L_39
L_40 ,
V_227 , V_229 ,
V_228 , V_230 ,
V_231 , V_186 ) ;
F_3 ( V_182 ,
( V_231 << V_184 ) |
( V_230 << V_240 ) |
( V_228 << V_241 ) |
( V_227 << V_242 ) ) ;
F_3 ( V_243 ,
( F_2 ( V_243 ) & ~ V_244 ) |
( V_229 << V_245 ) ) ;
F_3 ( V_155 ,
( F_2 ( V_155 ) & ~ V_187 ) |
( V_186 << V_188 ) ) ;
if ( V_234 )
F_72 ( V_4 , true ) ;
}
static void F_101 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_226 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_227 , V_228 , V_246 ;
int V_229 , V_230 , V_247 ;
int V_231 , V_186 ;
int V_232 , V_233 ;
unsigned int V_175 = 0 ;
bool V_234 ;
F_96 ( V_12 ) ;
if ( F_88 ( V_2 , V_235 ,
& V_236 , V_237 ,
& V_238 , V_237 ,
& V_227 , & V_229 ) )
V_175 |= 1 << V_235 ;
if ( F_88 ( V_2 , V_239 ,
& V_236 , V_237 ,
& V_238 , V_237 ,
& V_228 , & V_230 ) )
V_175 |= 1 << V_239 ;
if ( F_88 ( V_2 , V_248 ,
& V_236 , V_237 ,
& V_238 , V_237 ,
& V_246 , & V_247 ) )
V_175 |= 1 << V_248 ;
if ( F_99 ( V_175 ) &&
F_92 ( V_2 , F_100 ( V_175 ) - 1 ,
V_226 ,
& V_236 ,
& V_238 ,
& V_231 , & V_233 ) &&
F_92 ( V_2 , F_100 ( V_175 ) - 1 ,
2 * V_226 ,
& V_236 ,
& V_238 ,
& V_232 , & V_186 ) ) {
V_234 = true ;
} else {
V_234 = false ;
F_72 ( V_4 , false ) ;
V_231 = V_186 = 0 ;
}
F_5 ( L_39
L_41
L_42 ,
V_227 , V_229 ,
V_228 , V_230 ,
V_246 , V_247 ,
V_231 , V_186 ) ;
F_3 ( V_182 ,
( V_231 << V_184 ) |
( V_230 << V_240 ) |
( V_228 << V_241 ) |
( V_227 << V_242 ) ) ;
F_3 ( V_243 ,
( F_2 ( V_243 ) & ~ V_244 ) |
( V_229 << V_245 ) ) ;
F_3 ( V_155 ,
( F_2 ( V_155 ) & ~ V_187 ) |
( V_186 << V_188 ) ) ;
F_3 ( V_249 ,
( F_2 ( V_249 ) & ~ ( V_250 |
V_251 ) ) |
( V_246 << V_252 ) |
( V_247 << V_253 ) ) ;
if ( V_234 )
F_72 ( V_4 , true ) ;
}
static void F_102 ( struct V_254 * V_30 ,
struct V_11 * V_12 ,
T_3 V_255 ,
T_3 V_256 ,
int V_167 ,
bool V_175 , bool V_257 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_67 = F_61 ( V_30 ) -> V_67 ;
int V_258 = F_61 ( V_30 ) -> V_30 ;
int V_214 ;
int V_218 ;
int V_259 ;
int V_213 ;
V_259 = F_2 ( F_97 ( V_67 ) ) & ~ ( F_103 ( V_258 ) |
( V_217 << F_104 ( V_258 ) ) ) ;
if ( V_175 && F_94 ( V_12 , V_167 , & V_213 ,
& V_214 ) ) {
V_218 = ( V_213 == V_215 ) ?
F_103 ( V_258 ) :
F_105 ( V_258 ) ;
V_259 |= V_218 |
( V_214 << F_104 ( V_258 ) ) ;
}
F_3 ( F_97 ( V_67 ) , V_259 ) ;
}
static void F_106 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
static const int V_226 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_227 , V_228 , V_229 , V_230 ;
int V_231 , V_186 ;
unsigned int V_175 = 0 ;
bool V_234 ;
if ( F_88 ( V_2 , V_235 ,
& V_260 , V_237 ,
& V_261 , V_237 ,
& V_227 , & V_229 ) )
V_175 |= 1 << V_235 ;
if ( F_88 ( V_2 , V_239 ,
& V_260 , V_237 ,
& V_261 , V_237 ,
& V_228 , & V_230 ) )
V_175 |= 1 << V_239 ;
if ( F_99 ( V_175 ) &&
F_92 ( V_2 , F_100 ( V_175 ) - 1 ,
V_226 ,
& V_260 ,
& V_261 ,
& V_231 , & V_186 ) ) {
V_234 = true ;
} else {
V_234 = false ;
F_72 ( V_4 , false ) ;
V_231 = V_186 = 0 ;
}
F_5 ( L_39
L_40 ,
V_227 , V_229 ,
V_228 , V_230 ,
V_231 , V_186 ) ;
F_3 ( V_182 ,
( V_231 << V_184 ) |
( V_230 << V_240 ) |
( V_228 << V_241 ) |
( V_227 << V_242 ) ) ;
F_3 ( V_243 ,
( F_2 ( V_243 ) & ~ V_244 ) |
( V_229 << V_245 ) ) ;
F_3 ( V_155 ,
( F_2 ( V_155 ) & ~ ( V_262 | V_187 ) ) |
( V_186 << V_188 ) ) ;
if ( V_234 )
F_72 ( V_4 , true ) ;
}
static void F_107 ( struct V_11 * V_176 )
{
struct V_1 * V_2 = V_176 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
int V_263 = 1 ;
int V_186 = 16 ;
bool V_234 ;
V_12 = F_85 ( V_2 ) ;
if ( V_12 ) {
static const int V_226 = 12000 ;
const struct V_88 * V_89 =
& F_8 ( V_12 ) -> V_100 . V_89 ;
int clock = V_89 -> V_179 ;
int V_201 = V_89 -> V_207 ;
int V_202 = F_8 ( V_12 ) -> V_100 . V_107 ;
int V_167 = V_12 -> V_15 -> V_14 -> V_178 / 8 ;
unsigned long V_203 ;
int V_205 ;
V_203 = F_90 ( V_201 * 1000 / clock , 1 ) ;
V_205 = ( ( ( V_226 / V_203 ) + 1000 ) / 1000 ) *
V_167 * V_202 ;
V_205 = F_84 ( V_205 , V_264 ) ;
V_263 = V_265 - V_205 ;
if ( V_263 < 0 )
V_263 = 1 ;
V_263 &= 0x1ff ;
F_5 ( L_43 ,
V_205 , V_263 ) ;
V_205 = ( ( ( V_226 / V_203 ) + 1000 ) / 1000 ) *
V_167 * F_8 ( V_12 ) -> V_208 ;
V_205 = F_84 ( V_205 ,
V_266 . V_171 ) ;
V_186 = V_266 . V_166 -
( V_205 + V_266 . V_172 ) ;
if ( V_186 > V_266 . V_173 )
V_186 = V_266 . V_173 ;
F_5 ( L_44
L_45 , V_263 , V_186 ) ;
V_234 = true ;
} else {
V_234 = false ;
F_72 ( V_4 , false ) ;
}
F_5 ( L_46 ,
V_263 ) ;
F_3 ( V_182 , ( V_263 << V_184 ) |
( 8 << V_240 ) |
( 8 << V_241 ) |
( 8 << V_242 ) ) ;
F_3 ( V_243 , ( 8 << V_245 ) |
( 8 << V_267 ) ) ;
F_3 ( V_155 , ( V_186 << V_188 ) ) ;
if ( V_234 )
F_72 ( V_4 , true ) ;
}
static void F_108 ( struct V_11 * V_176 )
{
struct V_1 * V_2 = V_176 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_164 * V_268 ;
T_3 V_269 ;
T_3 V_270 ;
int V_271 , V_263 = 1 ;
int V_166 ;
int V_227 , V_228 ;
struct V_11 * V_12 , * V_175 = NULL ;
if ( F_12 ( V_2 ) )
V_268 = & V_272 ;
else if ( ! F_9 ( V_2 ) )
V_268 = & V_273 ;
else
V_268 = & V_274 ;
V_166 = V_4 -> V_69 . V_275 ( V_2 , 0 ) ;
V_12 = F_89 ( V_2 , 0 ) ;
if ( F_56 ( V_12 ) ) {
const struct V_88 * V_89 ;
int V_276 = V_12 -> V_15 -> V_14 -> V_178 / 8 ;
if ( F_9 ( V_2 ) )
V_276 = 4 ;
V_89 = & F_8 ( V_12 ) -> V_100 . V_89 ;
V_227 = F_83 ( V_89 -> V_179 ,
V_268 , V_166 , V_276 ,
V_237 ) ;
V_175 = V_12 ;
} else {
V_227 = V_166 - V_268 -> V_172 ;
if ( V_227 > ( long ) V_268 -> V_173 )
V_227 = V_268 -> V_173 ;
}
if ( F_9 ( V_2 ) )
V_268 = & V_277 ;
V_166 = V_4 -> V_69 . V_275 ( V_2 , 1 ) ;
V_12 = F_89 ( V_2 , 1 ) ;
if ( F_56 ( V_12 ) ) {
const struct V_88 * V_89 ;
int V_276 = V_12 -> V_15 -> V_14 -> V_178 / 8 ;
if ( F_9 ( V_2 ) )
V_276 = 4 ;
V_89 = & F_8 ( V_12 ) -> V_100 . V_89 ;
V_228 = F_83 ( V_89 -> V_179 ,
V_268 , V_166 , V_276 ,
V_237 ) ;
if ( V_175 == NULL )
V_175 = V_12 ;
else
V_175 = NULL ;
} else {
V_228 = V_166 - V_268 -> V_172 ;
if ( V_228 > ( long ) V_268 -> V_173 )
V_228 = V_268 -> V_173 ;
}
F_5 ( L_47 , V_227 , V_228 ) ;
if ( F_79 ( V_2 ) && V_175 ) {
struct V_16 * V_17 ;
V_17 = F_7 ( V_175 -> V_15 -> V_14 ) ;
if ( V_17 -> V_112 == V_278 )
V_175 = NULL ;
}
V_271 = 2 ;
F_72 ( V_4 , false ) ;
if ( F_109 ( V_2 ) && V_175 ) {
static const int V_226 = 6000 ;
const struct V_88 * V_89 =
& F_8 ( V_175 ) -> V_100 . V_89 ;
int clock = V_89 -> V_179 ;
int V_201 = V_89 -> V_207 ;
int V_202 = F_8 ( V_175 ) -> V_100 . V_107 ;
int V_167 = V_175 -> V_15 -> V_14 -> V_178 / 8 ;
unsigned long V_203 ;
int V_205 ;
V_203 = F_90 ( V_201 * 1000 / clock , 1 ) ;
V_205 = ( ( ( V_226 / V_203 ) + 1000 ) / 1000 ) *
V_167 * V_202 ;
V_205 = F_84 ( V_205 , V_268 -> V_171 ) ;
F_5 ( L_48 , V_205 ) ;
V_263 = V_268 -> V_166 - V_205 ;
if ( V_263 < 0 )
V_263 = 1 ;
if ( F_76 ( V_2 ) || F_12 ( V_2 ) )
F_3 ( V_153 ,
V_279 | ( V_263 & 0xff ) ) ;
else if ( F_79 ( V_2 ) )
F_3 ( V_153 , V_263 & 0x3f ) ;
}
F_5 ( L_49 ,
V_227 , V_228 , V_271 , V_263 ) ;
V_269 = ( ( V_228 & 0x3f ) << 16 ) | ( V_227 & 0x3f ) ;
V_270 = ( V_271 & 0x1f ) ;
V_269 = V_269 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_270 = V_270 | ( 1 << 8 ) ;
F_3 ( V_280 , V_269 ) ;
F_3 ( V_281 , V_270 ) ;
if ( V_175 )
F_72 ( V_4 , true ) ;
}
static void F_110 ( struct V_11 * V_176 )
{
struct V_1 * V_2 = V_176 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 ;
const struct V_88 * V_89 ;
T_3 V_269 ;
int V_227 ;
V_12 = F_85 ( V_2 ) ;
if ( V_12 == NULL )
return;
V_89 = & F_8 ( V_12 ) -> V_100 . V_89 ;
V_227 = F_83 ( V_89 -> V_179 ,
& V_282 ,
V_4 -> V_69 . V_275 ( V_2 , 0 ) ,
4 , V_237 ) ;
V_269 = F_2 ( V_280 ) & ~ 0xfff ;
V_269 |= ( 3 << 8 ) | V_227 ;
F_5 ( L_50 , V_227 ) ;
F_3 ( V_280 , V_269 ) ;
}
static T_3 F_111 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_18 * V_18 = F_8 ( V_12 ) ;
T_3 V_283 ;
V_283 = V_18 -> V_100 . V_89 . V_179 ;
if ( V_18 -> V_100 . V_284 . V_175 ) {
T_4 V_285 , V_286 , V_287 , V_288 ;
T_3 V_289 = V_18 -> V_100 . V_284 . V_22 ;
V_285 = V_18 -> V_100 . V_107 ;
V_286 = V_18 -> V_100 . V_108 ;
V_287 = ( V_289 >> 16 ) & 0xFFFF ;
V_288 = V_289 & 0xFFFF ;
if ( V_285 < V_287 )
V_285 = V_287 ;
if ( V_286 < V_288 )
V_286 = V_288 ;
V_283 = F_112 ( ( T_4 ) V_283 * V_285 * V_286 ,
V_287 * V_288 ) ;
}
return V_283 ;
}
static T_3 F_113 ( T_3 V_283 , T_5 V_290 ,
T_3 V_147 )
{
T_4 V_291 ;
if ( F_95 ( V_147 == 0 , L_51 ) )
return V_292 ;
V_291 = ( T_4 ) V_283 * V_290 * V_147 ;
V_291 = F_114 ( V_291 , 64 * 10000 ) + 2 ;
return V_291 ;
}
static T_3 F_115 ( T_3 V_283 , T_3 V_293 ,
T_3 V_294 , T_5 V_290 ,
T_3 V_147 )
{
T_3 V_291 ;
if ( F_95 ( V_147 == 0 , L_51 ) )
return V_292 ;
V_291 = ( V_147 * V_283 ) / ( V_293 * 10000 ) ;
V_291 = ( V_291 + 1 ) * V_294 * V_290 ;
V_291 = F_84 ( V_291 , 64 ) + 2 ;
return V_291 ;
}
static T_3 F_116 ( T_3 V_295 , T_3 V_294 ,
T_5 V_290 )
{
return F_84 ( V_295 * 64 , V_294 * V_290 ) + 2 ;
}
static T_3 F_117 ( const struct V_296 * V_297 ,
T_3 V_298 ,
bool V_299 )
{
T_3 V_300 , V_301 ;
if ( ! V_297 -> V_302 || ! V_297 -> V_303 . V_175 )
return 0 ;
V_300 = F_113 ( V_297 -> V_283 ,
V_297 -> V_303 . V_290 ,
V_298 ) ;
if ( ! V_299 )
return V_300 ;
V_301 = F_115 ( V_297 -> V_283 ,
V_297 -> V_293 ,
V_297 -> V_303 . V_294 ,
V_297 -> V_303 . V_290 ,
V_298 ) ;
return F_93 ( V_300 , V_301 ) ;
}
static T_3 F_118 ( const struct V_296 * V_297 ,
T_3 V_298 )
{
T_3 V_300 , V_301 ;
if ( ! V_297 -> V_302 || ! V_297 -> V_304 . V_175 )
return 0 ;
V_300 = F_113 ( V_297 -> V_283 ,
V_297 -> V_304 . V_290 ,
V_298 ) ;
V_301 = F_115 ( V_297 -> V_283 ,
V_297 -> V_293 ,
V_297 -> V_304 . V_294 ,
V_297 -> V_304 . V_290 ,
V_298 ) ;
return F_93 ( V_300 , V_301 ) ;
}
static T_3 F_119 ( const struct V_296 * V_297 ,
T_3 V_298 )
{
if ( ! V_297 -> V_302 || ! V_297 -> V_305 . V_175 )
return 0 ;
return F_115 ( V_297 -> V_283 ,
V_297 -> V_293 ,
V_297 -> V_305 . V_294 ,
V_297 -> V_305 . V_290 ,
V_298 ) ;
}
static T_3 F_120 ( const struct V_296 * V_297 ,
T_3 V_295 )
{
if ( ! V_297 -> V_302 || ! V_297 -> V_303 . V_175 )
return 0 ;
return F_116 ( V_295 ,
V_297 -> V_303 . V_294 ,
V_297 -> V_303 . V_290 ) ;
}
static unsigned int F_121 ( const struct V_1 * V_2 )
{
if ( F_57 ( V_2 ) -> V_106 >= 8 )
return 3072 ;
else if ( F_57 ( V_2 ) -> V_106 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_122 ( const struct V_1 * V_2 ,
int V_306 , bool V_307 )
{
if ( F_57 ( V_2 ) -> V_106 >= 8 )
return V_306 == 0 ? 255 : 2047 ;
else if ( F_57 ( V_2 ) -> V_106 >= 7 )
return V_306 == 0 ? 127 : 1023 ;
else if ( ! V_307 )
return V_306 == 0 ? 127 : 511 ;
else
return V_306 == 0 ? 63 : 255 ;
}
static unsigned int F_123 ( const struct V_1 * V_2 ,
int V_306 )
{
if ( F_57 ( V_2 ) -> V_106 >= 7 )
return V_306 == 0 ? 63 : 255 ;
else
return V_306 == 0 ? 31 : 63 ;
}
static unsigned int F_124 ( const struct V_1 * V_2 )
{
if ( F_57 ( V_2 ) -> V_106 >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_125 ( const struct V_1 * V_2 ,
int V_306 ,
const struct V_308 * V_100 ,
enum V_309 V_310 ,
bool V_307 )
{
unsigned int V_166 = F_121 ( V_2 ) ;
if ( V_307 && ! V_100 -> V_311 )
return 0 ;
if ( V_306 == 0 || V_100 -> V_312 > 1 ) {
V_166 /= F_57 ( V_2 ) -> V_313 ;
if ( F_57 ( V_2 ) -> V_106 <= 6 )
V_166 /= 2 ;
}
if ( V_100 -> V_311 ) {
if ( V_306 > 0 && V_310 == V_314 ) {
if ( V_307 )
V_166 *= 5 ;
V_166 /= 6 ;
} else {
V_166 /= 2 ;
}
}
return F_93 ( V_166 , F_122 ( V_2 , V_306 , V_307 ) ) ;
}
static unsigned int F_126 ( const struct V_1 * V_2 ,
int V_306 ,
const struct V_308 * V_100 )
{
if ( V_306 > 0 && V_100 -> V_312 > 1 )
return 64 ;
return F_123 ( V_2 , V_306 ) ;
}
static void F_127 ( const struct V_1 * V_2 ,
int V_306 ,
const struct V_308 * V_100 ,
enum V_309 V_310 ,
struct V_315 * F_90 )
{
F_90 -> V_303 = F_125 ( V_2 , V_306 , V_100 , V_310 , false ) ;
F_90 -> V_304 = F_125 ( V_2 , V_306 , V_100 , V_310 , true ) ;
F_90 -> V_305 = F_126 ( V_2 , V_306 , V_100 ) ;
F_90 -> V_21 = F_124 ( V_2 ) ;
}
static void F_128 ( struct V_1 * V_2 ,
int V_306 ,
struct V_315 * F_90 )
{
F_90 -> V_303 = F_122 ( V_2 , V_306 , false ) ;
F_90 -> V_304 = F_122 ( V_2 , V_306 , true ) ;
F_90 -> V_305 = F_123 ( V_2 , V_306 ) ;
F_90 -> V_21 = F_124 ( V_2 ) ;
}
static bool F_129 ( int V_306 ,
const struct V_315 * F_90 ,
struct V_316 * V_317 )
{
bool V_291 ;
if ( ! V_317 -> V_149 )
return false ;
V_317 -> V_149 = V_317 -> V_295 <= F_90 -> V_303 &&
V_317 -> V_318 <= F_90 -> V_304 &&
V_317 -> V_319 <= F_90 -> V_305 ;
V_291 = V_317 -> V_149 ;
if ( V_306 == 0 && ! V_317 -> V_149 ) {
if ( V_317 -> V_295 > F_90 -> V_303 )
F_5 ( L_52 ,
V_306 , V_317 -> V_295 , F_90 -> V_303 ) ;
if ( V_317 -> V_318 > F_90 -> V_304 )
F_5 ( L_53 ,
V_306 , V_317 -> V_318 , F_90 -> V_304 ) ;
if ( V_317 -> V_319 > F_90 -> V_305 )
F_5 ( L_54 ,
V_306 , V_317 -> V_319 , F_90 -> V_305 ) ;
V_317 -> V_295 = F_130 ( T_3 , V_317 -> V_295 , F_90 -> V_303 ) ;
V_317 -> V_318 = F_130 ( T_3 , V_317 -> V_318 , F_90 -> V_304 ) ;
V_317 -> V_319 = F_130 ( T_3 , V_317 -> V_319 , F_90 -> V_305 ) ;
V_317 -> V_149 = true ;
}
return V_291 ;
}
static void F_131 ( const struct V_3 * V_4 ,
int V_306 ,
const struct V_296 * V_320 ,
struct V_316 * V_317 )
{
T_6 V_321 = V_4 -> V_165 . V_321 [ V_306 ] ;
T_6 V_322 = V_4 -> V_165 . V_322 [ V_306 ] ;
T_6 V_323 = V_4 -> V_165 . V_323 [ V_306 ] ;
if ( V_306 > 0 ) {
V_321 *= 5 ;
V_322 *= 5 ;
V_323 *= 5 ;
}
V_317 -> V_295 = F_117 ( V_320 , V_321 , V_306 ) ;
V_317 -> V_318 = F_118 ( V_320 , V_322 ) ;
V_317 -> V_319 = F_119 ( V_320 , V_323 ) ;
V_317 -> V_324 = F_120 ( V_320 , V_317 -> V_295 ) ;
V_317 -> V_149 = true ;
}
static T_3
F_132 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
struct V_88 * V_325 = & V_18 -> V_100 . V_89 ;
T_1 V_326 , V_327 ;
if ( ! F_56 ( V_12 ) )
return 0 ;
V_326 = F_133 ( V_325 -> V_207 * 1000 * 8 ,
V_325 -> V_179 ) ;
V_327 = F_133 ( V_325 -> V_207 * 1000 * 8 ,
F_134 ( V_4 ) ) ;
return F_135 ( V_327 ) |
F_136 ( V_326 ) ;
}
static void F_137 ( struct V_1 * V_2 , T_6 V_165 [ 5 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_58 ( V_2 ) || F_138 ( V_2 ) ) {
T_4 V_328 = F_139 ( V_329 ) ;
V_165 [ 0 ] = ( V_328 >> 56 ) & 0xFF ;
if ( V_165 [ 0 ] == 0 )
V_165 [ 0 ] = V_328 & 0xF ;
V_165 [ 1 ] = ( V_328 >> 4 ) & 0xFF ;
V_165 [ 2 ] = ( V_328 >> 12 ) & 0xFF ;
V_165 [ 3 ] = ( V_328 >> 20 ) & 0x1FF ;
V_165 [ 4 ] = ( V_328 >> 32 ) & 0x1FF ;
} else if ( F_57 ( V_2 ) -> V_106 >= 6 ) {
T_3 V_328 = F_2 ( V_329 ) ;
V_165 [ 0 ] = ( V_328 >> V_330 ) & V_331 ;
V_165 [ 1 ] = ( V_328 >> V_332 ) & V_331 ;
V_165 [ 2 ] = ( V_328 >> V_333 ) & V_331 ;
V_165 [ 3 ] = ( V_328 >> V_334 ) & V_331 ;
} else if ( F_57 ( V_2 ) -> V_106 >= 5 ) {
T_3 V_335 = F_2 ( V_336 ) ;
V_165 [ 0 ] = 7 ;
V_165 [ 1 ] = ( V_335 >> V_337 ) & V_338 ;
V_165 [ 2 ] = ( V_335 >> V_339 ) & V_338 ;
}
}
static void F_140 ( struct V_1 * V_2 , T_6 V_165 [ 5 ] )
{
if ( F_57 ( V_2 ) -> V_106 == 5 )
V_165 [ 0 ] = 13 ;
}
static void F_141 ( struct V_1 * V_2 , T_6 V_165 [ 5 ] )
{
if ( F_57 ( V_2 ) -> V_106 == 5 )
V_165 [ 0 ] = 13 ;
if ( F_32 ( V_2 ) )
V_165 [ 3 ] *= 2 ;
}
int F_142 ( const struct V_1 * V_2 )
{
if ( F_58 ( V_2 ) || F_138 ( V_2 ) )
return 4 ;
else if ( F_57 ( V_2 ) -> V_106 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_143 ( struct V_1 * V_2 ,
const char * V_340 ,
const T_6 V_165 [ 5 ] )
{
int V_306 , V_341 = F_142 ( V_2 ) ;
for ( V_306 = 0 ; V_306 <= V_341 ; V_306 ++ ) {
unsigned int V_147 = V_165 [ V_306 ] ;
if ( V_147 == 0 ) {
F_47 ( L_55 ,
V_340 , V_306 ) ;
continue;
}
if ( V_306 > 0 )
V_147 *= 5 ;
F_5 ( L_56 ,
V_340 , V_306 , V_165 [ V_306 ] ,
V_147 / 10 , V_147 % 10 ) ;
}
}
static bool F_144 ( struct V_3 * V_4 ,
T_6 V_165 [ 5 ] , T_6 F_93 )
{
int V_306 , V_341 = F_142 ( V_4 -> V_2 ) ;
if ( V_165 [ 0 ] >= F_93 )
return false ;
V_165 [ 0 ] = F_90 ( V_165 [ 0 ] , F_93 ) ;
for ( V_306 = 1 ; V_306 <= V_341 ; V_306 ++ )
V_165 [ V_306 ] = F_145 ( T_6 , V_165 [ V_306 ] , F_84 ( F_93 , 5 ) ) ;
return true ;
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_342 ;
V_342 = F_144 ( V_4 , V_4 -> V_165 . V_321 , 12 ) |
F_144 ( V_4 , V_4 -> V_165 . V_322 , 12 ) |
F_144 ( V_4 , V_4 -> V_165 . V_323 , 12 ) ;
if ( ! V_342 )
return;
F_5 ( L_57 ) ;
F_143 ( V_2 , L_58 , V_4 -> V_165 . V_321 ) ;
F_143 ( V_2 , L_59 , V_4 -> V_165 . V_322 ) ;
F_143 ( V_2 , L_60 , V_4 -> V_165 . V_323 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_137 ( V_2 , V_4 -> V_165 . V_321 ) ;
memcpy ( V_4 -> V_165 . V_322 , V_4 -> V_165 . V_321 ,
sizeof( V_4 -> V_165 . V_321 ) ) ;
memcpy ( V_4 -> V_165 . V_323 , V_4 -> V_165 . V_321 ,
sizeof( V_4 -> V_165 . V_321 ) ) ;
F_140 ( V_2 , V_4 -> V_165 . V_322 ) ;
F_141 ( V_2 , V_4 -> V_165 . V_323 ) ;
F_143 ( V_2 , L_58 , V_4 -> V_165 . V_321 ) ;
F_143 ( V_2 , L_59 , V_4 -> V_165 . V_322 ) ;
F_143 ( V_2 , L_60 , V_4 -> V_165 . V_323 ) ;
if ( F_27 ( V_2 ) )
F_146 ( V_2 ) ;
}
static void F_148 ( struct V_11 * V_12 ,
struct V_296 * V_320 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
enum V_67 V_67 = V_18 -> V_67 ;
struct V_254 * V_30 ;
if ( ! F_56 ( V_12 ) )
return;
V_320 -> V_302 = true ;
V_320 -> V_293 = V_18 -> V_100 . V_89 . V_207 ;
V_320 -> V_283 = F_111 ( V_2 , V_12 ) ;
V_320 -> V_303 . V_290 = V_12 -> V_15 -> V_14 -> V_178 / 8 ;
V_320 -> V_305 . V_290 = 4 ;
V_320 -> V_303 . V_294 = V_18 -> V_100 . V_107 ;
V_320 -> V_305 . V_294 = V_18 -> V_208 ;
V_320 -> V_303 . V_175 = true ;
V_320 -> V_305 . V_175 = true ;
F_149 (plane, &dev->mode_config.plane_list) {
struct V_343 * V_343 = F_61 ( V_30 ) ;
if ( V_343 -> V_67 == V_67 ) {
V_320 -> V_304 = V_343 -> V_165 ;
break;
}
}
}
static void F_150 ( struct V_1 * V_2 ,
struct V_308 * V_100 )
{
struct V_18 * V_18 ;
F_151 (dev, intel_crtc) {
const struct V_344 * V_165 = & V_18 -> V_165 . V_302 ;
if ( ! V_165 -> V_345 )
continue;
V_100 -> V_311 |= V_165 -> V_311 ;
V_100 -> V_346 |= V_165 -> V_346 ;
V_100 -> V_312 ++ ;
}
}
static bool F_152 ( struct V_11 * V_12 ,
const struct V_296 * V_297 ,
struct V_344 * V_347 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
int V_306 , V_341 = F_142 ( V_2 ) ;
struct V_308 V_100 = {
. V_312 = 1 ,
. V_311 = V_297 -> V_304 . V_175 ,
. V_346 = V_297 -> V_304 . V_257 ,
} ;
struct V_315 F_90 ;
V_347 -> V_345 = V_297 -> V_302 ;
V_347 -> V_311 = V_297 -> V_304 . V_175 ;
V_347 -> V_346 = V_297 -> V_304 . V_257 ;
if ( F_57 ( V_2 ) -> V_106 <= 6 && V_297 -> V_304 . V_175 )
V_341 = 1 ;
if ( V_297 -> V_304 . V_257 )
V_341 = 0 ;
F_131 ( V_4 , 0 , V_297 , & V_347 -> V_165 [ 0 ] ) ;
if ( F_58 ( V_2 ) || F_138 ( V_2 ) )
V_347 -> V_326 = F_132 ( V_2 , V_12 ) ;
F_127 ( V_2 , 0 , & V_100 , V_348 , & F_90 ) ;
if ( ! F_129 ( 0 , & F_90 , & V_347 -> V_165 [ 0 ] ) )
return false ;
F_128 ( V_2 , 1 , & F_90 ) ;
for ( V_306 = 1 ; V_306 <= V_341 ; V_306 ++ ) {
struct V_316 V_165 = {} ;
F_131 ( V_4 , V_306 , V_297 , & V_165 ) ;
if ( ! F_129 ( V_306 , & F_90 , & V_165 ) )
break;
V_347 -> V_165 [ V_306 ] = V_165 ;
}
return true ;
}
static void F_153 ( struct V_1 * V_2 ,
int V_306 ,
struct V_316 * V_349 )
{
const struct V_18 * V_18 ;
V_349 -> V_149 = true ;
F_151 (dev, intel_crtc) {
const struct V_344 * V_302 = & V_18 -> V_165 . V_302 ;
const struct V_316 * V_165 = & V_302 -> V_165 [ V_306 ] ;
if ( ! V_302 -> V_345 )
continue;
if ( ! V_165 -> V_149 )
V_349 -> V_149 = false ;
V_349 -> V_295 = F_90 ( V_349 -> V_295 , V_165 -> V_295 ) ;
V_349 -> V_318 = F_90 ( V_349 -> V_318 , V_165 -> V_318 ) ;
V_349 -> V_319 = F_90 ( V_349 -> V_319 , V_165 -> V_319 ) ;
V_349 -> V_324 = F_90 ( V_349 -> V_324 , V_165 -> V_324 ) ;
}
}
static void F_154 ( struct V_1 * V_2 ,
const struct V_308 * V_100 ,
const struct V_315 * F_90 ,
struct V_344 * V_350 )
{
int V_306 , V_341 = F_142 ( V_2 ) ;
int V_351 = V_341 ;
if ( ( F_57 ( V_2 ) -> V_106 <= 6 || F_32 ( V_2 ) ) &&
V_100 -> V_312 > 1 )
return;
V_350 -> V_352 = F_57 ( V_2 ) -> V_106 >= 6 ;
for ( V_306 = 1 ; V_306 <= V_341 ; V_306 ++ ) {
struct V_316 * V_165 = & V_350 -> V_165 [ V_306 ] ;
F_153 ( V_2 , V_306 , V_165 ) ;
if ( V_306 > V_351 )
V_165 -> V_149 = false ;
else if ( ! F_129 ( V_306 , F_90 , V_165 ) )
V_351 = V_306 - 1 ;
if ( V_165 -> V_324 > F_90 -> V_21 ) {
if ( V_165 -> V_149 )
V_350 -> V_352 = false ;
V_165 -> V_324 = 0 ;
}
}
if ( F_25 ( V_2 ) && ! V_350 -> V_352 && F_34 ( V_2 ) ) {
for ( V_306 = 2 ; V_306 <= V_341 ; V_306 ++ ) {
struct V_316 * V_165 = & V_350 -> V_165 [ V_306 ] ;
V_165 -> V_149 = false ;
}
}
}
static int F_155 ( int V_353 , const struct V_344 * V_347 )
{
return V_353 + ( V_353 >= 2 && V_347 -> V_165 [ 4 ] . V_149 ) ;
}
static unsigned int F_156 ( struct V_1 * V_2 , int V_306 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_58 ( V_2 ) || F_138 ( V_2 ) )
return 2 * V_306 ;
else
return V_4 -> V_165 . V_321 [ V_306 ] ;
}
static void F_157 ( struct V_1 * V_2 ,
const struct V_344 * V_350 ,
enum V_309 V_354 ,
struct V_355 * V_356 )
{
struct V_18 * V_18 ;
int V_306 , V_353 ;
V_356 -> V_357 = V_350 -> V_352 ;
V_356 -> V_354 = V_354 ;
for ( V_353 = 1 ; V_353 <= 3 ; V_353 ++ ) {
const struct V_316 * V_358 ;
V_306 = F_155 ( V_353 , V_350 ) ;
V_358 = & V_350 -> V_165 [ V_306 ] ;
V_356 -> V_353 [ V_353 - 1 ] =
( F_156 ( V_2 , V_306 ) << V_359 ) |
( V_358 -> V_295 << V_360 ) |
V_358 -> V_319 ;
if ( V_358 -> V_149 )
V_356 -> V_353 [ V_353 - 1 ] |= V_361 ;
if ( F_57 ( V_2 ) -> V_106 >= 8 )
V_356 -> V_353 [ V_353 - 1 ] |=
V_358 -> V_324 << V_362 ;
else
V_356 -> V_353 [ V_353 - 1 ] |=
V_358 -> V_324 << V_363 ;
if ( F_57 ( V_2 ) -> V_106 <= 6 && V_358 -> V_318 ) {
F_158 ( V_353 != 1 ) ;
V_356 -> V_364 [ V_353 - 1 ] = V_365 | V_358 -> V_318 ;
} else
V_356 -> V_364 [ V_353 - 1 ] = V_358 -> V_318 ;
}
F_151 (dev, intel_crtc) {
enum V_67 V_67 = V_18 -> V_67 ;
const struct V_316 * V_358 =
& V_18 -> V_165 . V_302 . V_165 [ 0 ] ;
if ( F_158 ( ! V_358 -> V_149 ) )
continue;
V_356 -> V_366 [ V_67 ] = V_18 -> V_165 . V_302 . V_326 ;
V_356 -> V_367 [ V_67 ] =
( V_358 -> V_295 << V_368 ) |
( V_358 -> V_318 << V_369 ) |
V_358 -> V_319 ;
}
}
static struct V_344 * F_159 ( struct V_1 * V_2 ,
struct V_344 * V_370 ,
struct V_344 * V_371 )
{
int V_306 , V_341 = F_142 ( V_2 ) ;
int V_372 = 0 , V_373 = 0 ;
for ( V_306 = 1 ; V_306 <= V_341 ; V_306 ++ ) {
if ( V_370 -> V_165 [ V_306 ] . V_149 )
V_372 = V_306 ;
if ( V_371 -> V_165 [ V_306 ] . V_149 )
V_373 = V_306 ;
}
if ( V_372 == V_373 ) {
if ( V_371 -> V_352 && ! V_370 -> V_352 )
return V_371 ;
else
return V_370 ;
} else if ( V_372 > V_373 ) {
return V_370 ;
} else {
return V_371 ;
}
}
static unsigned int F_160 ( struct V_3 * V_4 ,
const struct V_355 * V_374 ,
const struct V_355 * V_375 )
{
unsigned int V_376 = 0 ;
enum V_67 V_67 ;
int V_353 ;
F_161 (dev_priv, pipe) {
if ( V_374 -> V_366 [ V_67 ] != V_375 -> V_366 [ V_67 ] ) {
V_376 |= F_162 ( V_67 ) ;
V_376 |= V_377 ;
}
if ( V_374 -> V_367 [ V_67 ] != V_375 -> V_367 [ V_67 ] ) {
V_376 |= F_163 ( V_67 ) ;
V_376 |= V_377 ;
}
}
if ( V_374 -> V_357 != V_375 -> V_357 ) {
V_376 |= V_378 ;
V_376 |= V_377 ;
}
if ( V_374 -> V_354 != V_375 -> V_354 ) {
V_376 |= V_379 ;
V_376 |= V_377 ;
}
if ( V_376 & V_377 )
return V_376 ;
for ( V_353 = 1 ; V_353 <= 3 ; V_353 ++ ) {
if ( V_374 -> V_353 [ V_353 - 1 ] != V_375 -> V_353 [ V_353 - 1 ] ||
V_374 -> V_364 [ V_353 - 1 ] != V_375 -> V_364 [ V_353 - 1 ] )
break;
}
for (; V_353 <= 3 ; V_353 ++ )
V_376 |= F_164 ( V_353 ) ;
return V_376 ;
}
static bool F_165 ( struct V_3 * V_4 ,
unsigned int V_376 )
{
struct V_355 * V_380 = & V_4 -> V_165 . V_381 ;
bool V_342 = false ;
if ( V_376 & F_164 ( 3 ) && V_380 -> V_353 [ 2 ] & V_361 ) {
V_380 -> V_353 [ 2 ] &= ~ V_361 ;
F_3 ( V_382 , V_380 -> V_353 [ 2 ] ) ;
V_342 = true ;
}
if ( V_376 & F_164 ( 2 ) && V_380 -> V_353 [ 1 ] & V_361 ) {
V_380 -> V_353 [ 1 ] &= ~ V_361 ;
F_3 ( V_383 , V_380 -> V_353 [ 1 ] ) ;
V_342 = true ;
}
if ( V_376 & F_164 ( 1 ) && V_380 -> V_353 [ 0 ] & V_361 ) {
V_380 -> V_353 [ 0 ] &= ~ V_361 ;
F_3 ( V_384 , V_380 -> V_353 [ 0 ] ) ;
V_342 = true ;
}
return V_342 ;
}
static void F_166 ( struct V_3 * V_4 ,
struct V_355 * V_356 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_355 * V_380 = & V_4 -> V_165 . V_381 ;
unsigned int V_376 ;
T_3 V_150 ;
V_376 = F_160 ( V_4 , V_380 , V_356 ) ;
if ( ! V_376 )
return;
F_165 ( V_4 , V_376 ) ;
if ( V_376 & F_163 ( V_235 ) )
F_3 ( V_385 , V_356 -> V_367 [ 0 ] ) ;
if ( V_376 & F_163 ( V_239 ) )
F_3 ( V_386 , V_356 -> V_367 [ 1 ] ) ;
if ( V_376 & F_163 ( V_248 ) )
F_3 ( V_387 , V_356 -> V_367 [ 2 ] ) ;
if ( V_376 & F_162 ( V_235 ) )
F_3 ( F_167 ( V_235 ) , V_356 -> V_366 [ 0 ] ) ;
if ( V_376 & F_162 ( V_239 ) )
F_3 ( F_167 ( V_239 ) , V_356 -> V_366 [ 1 ] ) ;
if ( V_376 & F_162 ( V_248 ) )
F_3 ( F_167 ( V_248 ) , V_356 -> V_366 [ 2 ] ) ;
if ( V_376 & V_379 ) {
if ( F_58 ( V_2 ) || F_138 ( V_2 ) ) {
V_150 = F_2 ( V_388 ) ;
if ( V_356 -> V_354 == V_348 )
V_150 &= ~ V_389 ;
else
V_150 |= V_389 ;
F_3 ( V_388 , V_150 ) ;
} else {
V_150 = F_2 ( V_390 ) ;
if ( V_356 -> V_354 == V_348 )
V_150 &= ~ V_391 ;
else
V_150 |= V_391 ;
F_3 ( V_390 , V_150 ) ;
}
}
if ( V_376 & V_378 ) {
V_150 = F_2 ( V_392 ) ;
if ( V_356 -> V_357 )
V_150 &= ~ V_393 ;
else
V_150 |= V_393 ;
F_3 ( V_392 , V_150 ) ;
}
if ( V_376 & F_164 ( 1 ) &&
V_380 -> V_364 [ 0 ] != V_356 -> V_364 [ 0 ] )
F_3 ( V_394 , V_356 -> V_364 [ 0 ] ) ;
if ( F_57 ( V_2 ) -> V_106 >= 7 ) {
if ( V_376 & F_164 ( 2 ) && V_380 -> V_364 [ 1 ] != V_356 -> V_364 [ 1 ] )
F_3 ( V_395 , V_356 -> V_364 [ 1 ] ) ;
if ( V_376 & F_164 ( 3 ) && V_380 -> V_364 [ 2 ] != V_356 -> V_364 [ 2 ] )
F_3 ( V_396 , V_356 -> V_364 [ 2 ] ) ;
}
if ( V_376 & F_164 ( 1 ) && V_380 -> V_353 [ 0 ] != V_356 -> V_353 [ 0 ] )
F_3 ( V_384 , V_356 -> V_353 [ 0 ] ) ;
if ( V_376 & F_164 ( 2 ) && V_380 -> V_353 [ 1 ] != V_356 -> V_353 [ 1 ] )
F_3 ( V_383 , V_356 -> V_353 [ 1 ] ) ;
if ( V_376 & F_164 ( 3 ) && V_380 -> V_353 [ 2 ] != V_356 -> V_353 [ 2 ] )
F_3 ( V_382 , V_356 -> V_353 [ 2 ] ) ;
V_4 -> V_165 . V_381 = * V_356 ;
}
static bool F_168 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_165 ( V_4 , V_377 ) ;
}
static void F_169 ( struct V_11 * V_12 )
{
struct V_18 * V_18 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_315 F_90 ;
struct V_296 V_297 = {} ;
struct V_355 V_356 = {} ;
enum V_309 V_354 ;
struct V_344 V_347 = {} ;
struct V_344 V_397 = {} , V_398 = {} , * V_399 ;
struct V_308 V_100 = {} ;
F_148 ( V_12 , & V_297 ) ;
F_152 ( V_12 , & V_297 , & V_347 ) ;
if ( ! memcmp ( & V_18 -> V_165 . V_302 , & V_347 , sizeof( V_347 ) ) )
return;
V_18 -> V_165 . V_302 = V_347 ;
F_150 ( V_2 , & V_100 ) ;
F_127 ( V_2 , 1 , & V_100 , V_348 , & F_90 ) ;
F_154 ( V_2 , & V_100 , & F_90 , & V_397 ) ;
if ( F_57 ( V_2 ) -> V_106 >= 7 &&
V_100 . V_312 == 1 && V_100 . V_311 ) {
F_127 ( V_2 , 1 , & V_100 , V_314 , & F_90 ) ;
F_154 ( V_2 , & V_100 , & F_90 , & V_398 ) ;
V_399 = F_159 ( V_2 , & V_397 , & V_398 ) ;
} else {
V_399 = & V_397 ;
}
V_354 = ( V_399 == & V_397 ) ?
V_348 : V_314 ;
F_157 ( V_2 , V_399 , V_354 , & V_356 ) ;
F_166 ( V_4 , & V_356 ) ;
}
static void
F_170 ( struct V_254 * V_30 ,
struct V_11 * V_12 ,
T_3 V_255 , T_3 V_256 ,
int V_167 , bool V_175 , bool V_257 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_343 * V_343 = F_61 ( V_30 ) ;
V_343 -> V_165 . V_175 = V_175 ;
V_343 -> V_165 . V_257 = V_257 ;
V_343 -> V_165 . V_294 = V_255 ;
V_343 -> V_165 . V_400 = V_255 ;
V_343 -> V_165 . V_290 = V_167 ;
if ( F_32 ( V_2 ) && V_257 && F_168 ( V_2 ) )
F_171 ( V_2 , V_343 -> V_67 ) ;
F_169 ( V_12 ) ;
}
static void F_172 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_355 * V_381 = & V_4 -> V_165 . V_381 ;
struct V_18 * V_18 = F_8 ( V_12 ) ;
struct V_344 * V_302 = & V_18 -> V_165 . V_302 ;
enum V_67 V_67 = V_18 -> V_67 ;
static const unsigned int V_401 [] = {
[ V_235 ] = V_385 ,
[ V_239 ] = V_386 ,
[ V_248 ] = V_387 ,
} ;
V_381 -> V_367 [ V_67 ] = F_2 ( V_401 [ V_67 ] ) ;
if ( F_58 ( V_2 ) || F_138 ( V_2 ) )
V_381 -> V_366 [ V_67 ] = F_2 ( F_167 ( V_67 ) ) ;
V_302 -> V_345 = F_56 ( V_12 ) ;
if ( V_302 -> V_345 ) {
T_1 V_120 = V_381 -> V_367 [ V_67 ] ;
V_302 -> V_165 [ 0 ] . V_149 = true ;
V_302 -> V_165 [ 0 ] . V_295 = ( V_120 & V_402 ) >> V_368 ;
V_302 -> V_165 [ 0 ] . V_318 = ( V_120 & V_403 ) >> V_369 ;
V_302 -> V_165 [ 0 ] . V_319 = V_120 & V_404 ;
V_302 -> V_326 = V_381 -> V_366 [ V_67 ] ;
} else {
int V_306 , V_341 = F_142 ( V_2 ) ;
for ( V_306 = 0 ; V_306 <= V_341 ; V_306 ++ )
V_302 -> V_165 [ V_306 ] . V_149 = true ;
}
}
void F_173 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_355 * V_381 = & V_4 -> V_165 . V_381 ;
struct V_11 * V_12 ;
F_55 (dev, crtc)
F_172 ( V_12 ) ;
V_381 -> V_353 [ 0 ] = F_2 ( V_384 ) ;
V_381 -> V_353 [ 1 ] = F_2 ( V_383 ) ;
V_381 -> V_353 [ 2 ] = F_2 ( V_382 ) ;
V_381 -> V_364 [ 0 ] = F_2 ( V_394 ) ;
if ( F_57 ( V_2 ) -> V_106 >= 7 ) {
V_381 -> V_364 [ 1 ] = F_2 ( V_395 ) ;
V_381 -> V_364 [ 2 ] = F_2 ( V_396 ) ;
}
if ( F_58 ( V_2 ) || F_138 ( V_2 ) )
V_381 -> V_354 = ( F_2 ( V_388 ) & V_389 ) ?
V_314 : V_348 ;
else if ( F_32 ( V_2 ) )
V_381 -> V_354 = ( F_2 ( V_390 ) & V_391 ) ?
V_314 : V_348 ;
V_381 -> V_357 =
! ( F_2 ( V_392 ) & V_393 ) ;
}
void F_174 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_2 -> V_5 ;
if ( V_4 -> V_69 . V_405 )
V_4 -> V_69 . V_405 ( V_12 ) ;
}
void F_175 ( struct V_254 * V_30 ,
struct V_11 * V_12 ,
T_3 V_255 ,
T_3 V_256 ,
int V_167 ,
bool V_175 , bool V_257 )
{
struct V_3 * V_4 = V_30 -> V_2 -> V_5 ;
if ( V_4 -> V_69 . V_406 )
V_4 -> V_69 . V_406 ( V_30 , V_12 ,
V_255 , V_256 ,
V_167 , V_175 , V_257 ) ;
}
static struct V_16 *
F_176 ( struct V_1 * V_2 )
{
struct V_16 * V_407 ;
int V_291 ;
F_158 ( ! F_177 ( & V_2 -> V_77 ) ) ;
V_407 = F_178 ( V_2 , 4096 ) ;
if ( ! V_407 ) {
F_179 ( L_61 ) ;
return NULL ;
}
V_291 = F_180 ( V_407 , 4096 , 0 ) ;
if ( V_291 ) {
F_47 ( L_62 , V_291 ) ;
goto V_408;
}
V_291 = F_181 ( V_407 , 1 ) ;
if ( V_291 ) {
F_47 ( L_63 , V_291 ) ;
goto V_409;
}
return V_407 ;
V_409:
F_182 ( V_407 ) ;
V_408:
F_183 ( & V_407 -> V_81 ) ;
return NULL ;
}
bool F_184 ( struct V_1 * V_2 , T_7 V_150 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_410 ;
F_185 ( & V_411 ) ;
V_410 = F_68 ( V_412 ) ;
if ( V_410 & V_413 ) {
F_179 ( L_64 ) ;
return false ;
}
V_410 = ( V_414 << V_415 ) |
( V_150 << V_416 ) | V_417 ;
F_186 ( V_412 , V_410 ) ;
F_187 ( V_412 ) ;
V_410 |= V_413 ;
F_186 ( V_412 , V_410 ) ;
return true ;
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_418 = F_2 ( V_419 ) ;
T_7 V_420 , V_421 , V_422 , V_423 ;
F_189 ( & V_411 ) ;
F_186 ( V_424 , F_2 ( V_424 ) | V_425 ) ;
F_186 ( V_426 , F_2 ( V_426 ) | V_427 ) ;
F_3 ( V_428 , 100000 ) ;
F_3 ( V_429 , 100000 ) ;
F_3 ( V_430 , 90000 ) ;
F_3 ( V_431 , 80000 ) ;
F_3 ( V_432 , 1 ) ;
V_420 = ( V_418 & V_433 ) >> V_434 ;
V_421 = ( V_418 & V_435 ) ;
V_422 = ( V_418 & V_436 ) >>
V_437 ;
V_423 = ( F_2 ( V_438 + ( V_422 * 4 ) ) & V_439 ) >>
V_440 ;
V_4 -> V_140 . V_420 = V_420 ;
V_4 -> V_140 . V_422 = V_422 ;
V_4 -> V_140 . V_441 = V_422 ;
V_4 -> V_140 . V_442 = V_421 ;
V_4 -> V_140 . V_443 = V_422 ;
F_69 ( L_65 ,
V_420 , V_421 , V_422 ) ;
F_3 ( V_444 , V_445 | V_446 ) ;
F_3 ( V_447 , V_423 ) ;
F_22 ( V_447 ) ;
V_418 |= V_448 ;
F_3 ( V_419 , V_418 ) ;
if ( F_190 ( ( F_2 ( V_412 ) & V_413 ) == 0 , 10 ) )
F_47 ( L_66 ) ;
F_191 ( 1 ) ;
F_184 ( V_2 , V_422 ) ;
V_4 -> V_140 . V_449 = F_2 ( 0x112e4 ) + F_2 ( 0x112e8 ) +
F_2 ( 0x112e0 ) ;
V_4 -> V_140 . V_450 = F_192 ( V_451 ) ;
V_4 -> V_140 . V_452 = F_2 ( 0x112f4 ) ;
V_4 -> V_140 . V_453 = F_193 () ;
F_194 ( & V_411 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_410 ;
F_189 ( & V_411 ) ;
V_410 = F_68 ( V_412 ) ;
F_3 ( V_444 , F_2 ( V_444 ) & ~ V_446 ) ;
F_3 ( V_454 , V_455 ) ;
F_3 ( V_456 , F_2 ( V_456 ) & ~ V_457 ) ;
F_3 ( V_458 , V_457 ) ;
F_3 ( V_459 , F_2 ( V_459 ) | V_457 ) ;
F_184 ( V_2 , V_4 -> V_140 . V_422 ) ;
F_191 ( 1 ) ;
V_410 |= V_413 ;
F_3 ( V_412 , V_410 ) ;
F_191 ( 1 ) ;
F_194 ( & V_411 ) ;
}
static T_1 F_196 ( struct V_3 * V_4 , T_7 V_150 )
{
T_1 V_460 ;
V_460 = V_4 -> V_461 . V_462 << 24 ;
if ( V_150 <= V_4 -> V_461 . V_463 )
V_460 |= V_4 -> V_461 . V_463 << 16 ;
return V_460 ;
}
static void F_197 ( struct V_3 * V_4 , T_7 V_150 )
{
int V_464 ;
V_464 = V_4 -> V_461 . V_465 ;
switch ( V_4 -> V_461 . V_465 ) {
case V_466 :
if ( V_150 > V_4 -> V_461 . V_467 + 1 && V_150 > V_4 -> V_461 . V_468 )
V_464 = V_469 ;
break;
case V_469 :
if ( V_150 <= V_4 -> V_461 . V_467 && V_150 < V_4 -> V_461 . V_468 )
V_464 = V_466 ;
else if ( V_150 >= V_4 -> V_461 . V_470 && V_150 > V_4 -> V_461 . V_468 )
V_464 = V_471 ;
break;
case V_471 :
if ( V_150 < ( V_4 -> V_461 . V_472 + V_4 -> V_461 . V_470 ) > > 1 && V_150 < V_4 -> V_461 . V_468 )
V_464 = V_469 ;
break;
}
if ( V_150 == V_4 -> V_461 . V_463 )
V_464 = V_466 ;
if ( V_150 == V_4 -> V_461 . V_462 )
V_464 = V_471 ;
if ( V_464 == V_4 -> V_461 . V_465 )
return;
switch ( V_464 ) {
case V_466 :
F_3 ( V_473 , 12500 ) ;
F_3 ( V_474 , 11800 ) ;
F_3 ( V_475 , 25000 ) ;
F_3 ( V_476 , 21250 ) ;
F_3 ( V_477 ,
V_478 |
V_479 |
V_480 |
V_481 |
V_482 |
V_483 ) ;
break;
case V_469 :
F_3 ( V_473 , 10250 ) ;
F_3 ( V_474 , 9225 ) ;
F_3 ( V_475 , 25000 ) ;
F_3 ( V_476 , 18750 ) ;
F_3 ( V_477 ,
V_478 |
V_479 |
V_480 |
V_481 |
V_482 |
V_483 ) ;
break;
case V_471 :
F_3 ( V_473 , 8000 ) ;
F_3 ( V_474 , 6800 ) ;
F_3 ( V_475 , 25000 ) ;
F_3 ( V_476 , 15000 ) ;
F_3 ( V_477 ,
V_478 |
V_479 |
V_480 |
V_481 |
V_482 |
V_483 ) ;
break;
}
V_4 -> V_461 . V_465 = V_464 ;
V_4 -> V_461 . V_484 = 0 ;
}
static T_1 F_198 ( struct V_3 * V_4 , T_7 V_150 )
{
T_1 V_485 = 0 ;
if ( V_150 > V_4 -> V_461 . V_463 )
V_485 |= V_486 | V_487 ;
if ( V_150 < V_4 -> V_461 . V_462 )
V_485 |= V_488 ;
V_485 |= V_4 -> V_489 & ( V_490 | V_491 ) ;
V_485 &= V_4 -> V_489 ;
if ( F_57 ( V_4 -> V_2 ) -> V_106 <= 7 && ! F_58 ( V_4 -> V_2 ) )
V_485 |= V_491 ;
if ( F_36 ( V_4 -> V_2 ) )
V_485 |= V_492 ;
return ~ V_485 ;
}
void F_199 ( struct V_1 * V_2 , T_7 V_150 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_158 ( ! F_177 ( & V_4 -> V_461 . V_493 ) ) ;
F_158 ( V_150 > V_4 -> V_461 . V_462 ) ;
F_158 ( V_150 < V_4 -> V_461 . V_463 ) ;
if ( V_150 != V_4 -> V_461 . V_468 ) {
F_197 ( V_4 , V_150 ) ;
if ( F_58 ( V_2 ) || F_138 ( V_2 ) )
F_3 ( V_494 ,
F_200 ( V_150 ) ) ;
else
F_3 ( V_494 ,
F_201 ( V_150 ) |
F_202 ( 0 ) |
V_495 ) ;
}
F_3 ( V_496 , F_196 ( V_4 , V_150 ) ) ;
F_3 ( V_497 , F_198 ( V_4 , V_150 ) ) ;
F_22 ( V_494 ) ;
V_4 -> V_461 . V_468 = V_150 ;
F_203 ( V_150 * 50 ) ;
}
static void F_204 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_2 -> V_498 -> V_499 >= 0xd ) {
F_205 ( V_4 -> V_2 , V_4 -> V_461 . V_463 ) ;
return;
}
if ( V_4 -> V_461 . V_468 <= V_4 -> V_461 . V_463 )
return;
F_3 ( V_497 , 0xffffffff ) ;
F_206 ( V_4 , true ) ;
V_4 -> V_461 . V_468 = V_4 -> V_461 . V_463 ;
F_207 ( V_4 , V_500 ,
V_4 -> V_461 . V_463 ) ;
if ( F_4 ( ( ( F_208 ( V_4 , V_501 ) )
& V_502 ) == 0 , 5 ) )
F_47 ( L_67 ) ;
F_206 ( V_4 , false ) ;
F_3 ( V_497 ,
F_198 ( V_4 , V_4 -> V_461 . V_468 ) ) ;
}
void F_209 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
if ( V_4 -> V_461 . V_175 ) {
if ( F_210 ( V_2 ) )
F_205 ( V_4 -> V_2 , V_4 -> V_461 . V_463 ) ;
else if ( F_73 ( V_2 ) )
F_204 ( V_4 ) ;
else
F_199 ( V_4 -> V_2 , V_4 -> V_461 . V_463 ) ;
V_4 -> V_461 . V_484 = 0 ;
}
F_41 ( & V_4 -> V_461 . V_493 ) ;
}
void F_211 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
if ( V_4 -> V_461 . V_175 ) {
if ( F_73 ( V_2 ) )
F_205 ( V_4 -> V_2 , V_4 -> V_461 . V_462 ) ;
else
F_199 ( V_4 -> V_2 , V_4 -> V_461 . V_462 ) ;
V_4 -> V_461 . V_484 = 0 ;
}
F_41 ( & V_4 -> V_461 . V_493 ) ;
}
void F_205 ( struct V_1 * V_2 , T_7 V_150 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_158 ( ! F_177 ( & V_4 -> V_461 . V_493 ) ) ;
F_158 ( V_150 > V_4 -> V_461 . V_462 ) ;
F_158 ( V_150 < V_4 -> V_461 . V_463 ) ;
if ( F_212 ( F_210 ( V_2 ) && ( V_150 & 1 ) ,
L_68 ) )
V_150 &= ~ 1 ;
if ( V_150 != V_4 -> V_461 . V_468 ) {
F_69 ( L_69 ,
F_213 ( V_4 , V_4 -> V_461 . V_468 ) ,
V_4 -> V_461 . V_468 ,
F_213 ( V_4 , V_150 ) , V_150 ) ;
F_207 ( V_4 , V_500 , V_150 ) ;
}
F_3 ( V_497 , F_198 ( V_4 , V_150 ) ) ;
V_4 -> V_461 . V_468 = V_150 ;
F_203 ( F_213 ( V_4 , V_150 ) ) ;
}
static void F_214 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_497 , ~ V_492 ) ;
F_3 ( F_215 ( 2 ) , F_2 ( F_215 ( 2 ) ) &
~ V_4 -> V_489 ) ;
F_189 ( & V_4 -> V_503 ) ;
V_4 -> V_461 . V_504 = 0 ;
F_194 ( & V_4 -> V_503 ) ;
F_3 ( F_216 ( 2 ) , V_4 -> V_489 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_497 , 0xffffffff ) ;
F_3 ( V_505 , F_2 ( V_505 ) &
~ V_4 -> V_489 ) ;
F_189 ( & V_4 -> V_503 ) ;
V_4 -> V_461 . V_504 = 0 ;
F_194 ( & V_4 -> V_503 ) ;
F_3 ( V_506 , V_4 -> V_489 ) ;
}
static void F_218 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_507 , 0 ) ;
F_3 ( V_494 , 1 << 31 ) ;
if ( F_138 ( V_2 ) )
F_214 ( V_2 ) ;
else
F_217 ( V_2 ) ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_507 , 0 ) ;
F_214 ( V_2 ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_21 ( V_4 , V_508 ) ;
F_3 ( V_507 , 0 ) ;
F_23 ( V_4 , V_508 ) ;
F_217 ( V_2 ) ;
}
static void F_221 ( struct V_1 * V_2 , T_1 V_325 )
{
if ( F_73 ( V_2 ) ) {
if ( V_325 & ( V_509 | F_222 ( 1 ) ) )
V_325 = V_510 ;
else
V_325 = 0 ;
}
F_5 ( L_70 ,
( V_325 & V_510 ) ? L_71 : L_72 ,
( V_325 & V_511 ) ? L_71 : L_72 ,
( V_325 & V_512 ) ? L_71 : L_72 ) ;
}
static int F_223 ( const struct V_1 * V_2 , int V_513 )
{
if ( F_57 ( V_2 ) -> V_106 < 5 )
return 0 ;
if ( F_57 ( V_2 ) -> V_106 == 5 && ! F_224 ( V_2 ) )
return 0 ;
if ( V_513 >= 0 ) {
int V_485 ;
if ( F_57 ( V_2 ) -> V_106 == 6 || F_32 ( V_2 ) )
V_485 = V_514 | V_515 |
V_516 ;
else
V_485 = V_514 ;
if ( ( V_513 & V_485 ) != V_513 )
F_5 ( L_73 ,
V_513 & V_485 , V_513 , V_485 ) ;
return V_513 & V_485 ;
}
if ( F_57 ( V_2 ) -> V_106 == 5 )
return 0 ;
if ( F_32 ( V_2 ) )
return ( V_514 | V_515 ) ;
return V_514 ;
}
int F_225 ( const struct V_1 * V_2 )
{
return V_93 . V_513 ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_189 ( & V_4 -> V_503 ) ;
F_158 ( V_4 -> V_461 . V_504 ) ;
F_227 ( V_4 , V_4 -> V_489 ) ;
F_3 ( F_216 ( 2 ) , V_4 -> V_489 ) ;
F_194 ( & V_4 -> V_503 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_189 ( & V_4 -> V_503 ) ;
F_158 ( V_4 -> V_461 . V_504 ) ;
F_229 ( V_4 , V_4 -> V_489 ) ;
F_3 ( V_506 , V_4 -> V_489 ) ;
F_194 ( & V_4 -> V_503 ) ;
}
static void F_230 ( struct V_3 * V_4 , T_1 V_517 )
{
V_4 -> V_461 . V_468 = 0 ;
V_4 -> V_461 . V_472 = ( V_517 >> 8 ) & 0xff ;
V_4 -> V_461 . V_470 = ( V_517 >> 0 ) & 0xff ;
V_4 -> V_461 . V_518 = ( V_517 >> 16 ) & 0xff ;
V_4 -> V_461 . V_467 = V_4 -> V_461 . V_472 ;
V_4 -> V_461 . V_519 = V_4 -> V_461 . V_470 ;
if ( V_4 -> V_461 . V_462 == 0 )
V_4 -> V_461 . V_462 = V_4 -> V_461 . V_519 ;
if ( V_4 -> V_461 . V_463 == 0 )
V_4 -> V_461 . V_463 = V_4 -> V_461 . V_518 ;
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_520 * V_521 ;
T_3 V_522 = 0 , V_517 ;
int V_523 ;
F_3 ( V_524 , 0 ) ;
F_21 ( V_4 , V_508 ) ;
F_3 ( V_507 , 0 ) ;
V_517 = F_2 ( V_525 ) ;
F_230 ( V_4 , V_517 ) ;
F_3 ( V_526 , 40 << 16 ) ;
F_3 ( V_527 , 125000 ) ;
F_3 ( V_528 , 25 ) ;
F_232 (ring, dev_priv, unused)
F_3 ( F_233 ( V_521 -> V_529 ) , 10 ) ;
F_3 ( V_530 , 0 ) ;
if ( F_138 ( V_2 ) )
F_3 ( V_531 , 625 ) ;
else
F_3 ( V_531 , 50000 ) ;
if ( F_225 ( V_2 ) & V_514 )
V_522 = V_510 ;
F_221 ( V_2 , V_522 ) ;
if ( F_138 ( V_2 ) )
F_3 ( V_507 , V_532 |
V_509 |
V_522 ) ;
else
F_3 ( V_507 , V_532 |
F_222 ( 1 ) |
V_522 ) ;
F_3 ( V_494 ,
F_200 ( V_4 -> V_461 . V_472 ) ) ;
F_3 ( V_533 ,
F_200 ( V_4 -> V_461 . V_472 ) ) ;
F_3 ( V_534 , 100000000 / 128 ) ;
F_3 ( V_496 ,
V_4 -> V_461 . V_462 << 24 |
V_4 -> V_461 . V_463 << 16 ) ;
F_3 ( V_474 , 7600000 / 128 ) ;
F_3 ( V_476 , 31300000 / 128 ) ;
F_3 ( V_473 , 66000 ) ;
F_3 ( V_475 , 350000 ) ;
F_3 ( V_535 , 10 ) ;
F_3 ( V_477 ,
V_478 |
V_479 |
V_480 |
V_481 |
V_482 |
V_483 ) ;
F_199 ( V_2 , ( F_2 ( V_536 ) & 0xff00 ) >> 8 ) ;
F_226 ( V_2 ) ;
F_23 ( V_4 , V_508 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_520 * V_521 ;
T_1 V_517 ;
T_1 V_537 , V_538 = 0 , V_522 = 0 ;
T_1 V_539 ;
int V_540 ;
int V_20 , V_291 ;
F_158 ( ! F_177 ( & V_4 -> V_461 . V_493 ) ) ;
F_3 ( V_524 , 0 ) ;
if ( ( V_539 = F_2 ( V_541 ) ) ) {
F_47 ( L_74 , V_539 ) ;
F_3 ( V_541 , V_539 ) ;
}
F_21 ( V_4 , V_508 ) ;
V_517 = F_2 ( V_525 ) ;
F_230 ( V_4 , V_517 ) ;
F_3 ( V_507 , 0 ) ;
F_3 ( V_542 , 1000 << 16 ) ;
F_3 ( V_526 , 40 << 16 | 30 ) ;
F_3 ( V_543 , 30 ) ;
F_3 ( V_527 , 125000 ) ;
F_3 ( V_528 , 25 ) ;
F_232 (ring, dev_priv, i)
F_3 ( F_233 ( V_521 -> V_529 ) , 10 ) ;
F_3 ( V_530 , 0 ) ;
F_3 ( V_544 , 1000 ) ;
if ( F_32 ( V_2 ) )
F_3 ( V_531 , 125000 ) ;
else
F_3 ( V_531 , 50000 ) ;
F_3 ( V_545 , 150000 ) ;
F_3 ( V_546 , 64000 ) ;
V_540 = F_225 ( V_4 -> V_2 ) ;
if ( V_540 & V_514 )
V_522 |= V_510 ;
if ( ! F_58 ( V_2 ) ) {
if ( V_540 & V_515 )
V_522 |= V_511 ;
if ( V_540 & V_516 )
V_522 |= V_512 ;
}
F_221 ( V_2 , V_522 ) ;
F_3 ( V_507 ,
V_522 |
F_222 ( 1 ) |
V_532 ) ;
F_3 ( V_534 , 50000 ) ;
F_3 ( V_535 , 10 ) ;
V_291 = F_235 ( V_4 , V_547 , 0 ) ;
if ( V_291 )
F_69 ( L_75 ) ;
V_291 = F_236 ( V_4 , V_548 , & V_538 ) ;
if ( ! V_291 && ( V_538 & ( 1 << 31 ) ) ) {
F_69 ( L_76 ,
( V_4 -> V_461 . V_462 & 0xff ) * 50 ,
( V_538 & 0xff ) * 50 ) ;
V_4 -> V_461 . V_519 = V_538 & 0xff ;
}
V_4 -> V_461 . V_465 = V_471 ;
F_199 ( V_4 -> V_2 , V_4 -> V_461 . V_463 ) ;
F_228 ( V_2 ) ;
V_537 = 0 ;
V_291 = F_236 ( V_4 , V_549 , & V_537 ) ;
if ( F_27 ( V_2 ) && V_291 ) {
F_69 ( L_77 ) ;
} else if ( F_27 ( V_2 ) && ( F_237 ( V_537 & 0xff ) < 450 ) ) {
F_69 ( L_78 ,
F_237 ( V_537 & 0xff ) , 450 ) ;
V_537 &= 0xffff00 ;
V_537 |= F_238 ( 450 ) ;
V_291 = F_235 ( V_4 , V_550 , V_537 ) ;
if ( V_291 )
F_47 ( L_79 ) ;
}
F_23 ( V_4 , V_508 ) ;
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_518 = 15 ;
unsigned int V_551 ;
unsigned int V_552 , V_553 ;
int V_554 = 180 ;
struct V_555 * V_556 ;
F_158 ( ! F_177 ( & V_4 -> V_461 . V_493 ) ) ;
V_556 = F_240 ( 0 ) ;
if ( V_556 ) {
V_552 = V_556 -> V_557 . V_519 ;
F_241 ( V_556 ) ;
} else {
V_552 = V_558 ;
}
V_552 /= 1000 ;
V_553 = F_2 ( V_559 ) & 0xf ;
V_553 = F_242 ( V_553 , 8 , 3 ) ;
for ( V_551 = V_4 -> V_461 . V_462 ; V_551 >= V_4 -> V_461 . V_463 ;
V_551 -- ) {
int V_560 = V_4 -> V_461 . V_462 - V_551 ;
unsigned int V_561 = 0 , V_562 = 0 ;
if ( F_57 ( V_2 ) -> V_106 >= 8 ) {
V_562 = F_90 ( V_553 , V_551 ) ;
} else if ( F_58 ( V_2 ) ) {
V_562 = F_242 ( V_551 , 5 , 4 ) ;
V_562 = F_90 ( V_553 , V_562 ) ;
} else {
if ( V_551 < V_518 )
V_561 = 800 ;
else
V_561 = V_552 - ( ( V_560 * V_554 ) / 2 ) ;
V_561 = F_133 ( V_561 , 100 ) ;
}
F_235 ( V_4 ,
V_547 ,
V_561 << V_563 |
V_562 << V_564 |
V_551 ) ;
}
}
void F_243 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_57 ( V_2 ) -> V_106 < 6 || F_73 ( V_2 ) )
return;
F_40 ( & V_4 -> V_461 . V_493 ) ;
F_239 ( V_2 ) ;
F_41 ( & V_4 -> V_461 . V_493 ) ;
}
static int F_244 ( struct V_3 * V_4 )
{
T_1 V_150 , V_565 ;
V_150 = F_208 ( V_4 , V_566 ) ;
V_565 = ( V_150 >> V_567 ) & V_568 ;
return V_565 ;
}
static int F_245 ( struct V_3 * V_4 )
{
T_1 V_150 , V_569 ;
V_150 = F_208 ( V_4 , V_570 ) ;
V_569 = ( V_150 >> V_571 ) & V_572 ;
return V_569 ;
}
static int F_246 ( struct V_3 * V_4 )
{
T_1 V_150 , V_573 ;
V_150 = F_208 ( V_4 , V_501 ) ;
V_573 = ( V_150 >> V_567 ) & V_568 ;
return V_573 ;
}
static int F_247 ( struct V_3 * V_4 )
{
T_1 V_150 , V_574 ;
V_150 = F_208 ( V_4 , V_566 ) ;
V_574 = ( V_150 >> V_575 ) & V_576 ;
return V_574 ;
}
static int F_248 ( struct V_3 * V_4 )
{
T_1 V_150 , V_573 ;
V_150 = F_249 ( V_4 , V_577 ) ;
V_573 = ( V_150 & V_578 ) >> V_579 ;
return V_573 ;
}
static int F_250 ( struct V_3 * V_4 )
{
T_1 V_150 , V_565 ;
V_150 = F_249 ( V_4 , V_577 ) ;
V_565 = ( V_150 & V_580 ) >> V_581 ;
V_565 = F_130 ( T_1 , V_565 , 0xea ) ;
return V_565 ;
}
static int F_251 ( struct V_3 * V_4 )
{
T_1 V_150 , V_569 ;
V_150 = F_249 ( V_4 , V_582 ) ;
V_569 = ( V_150 & V_583 ) >> V_584 ;
V_150 = F_249 ( V_4 , V_585 ) ;
V_569 |= ( V_150 & V_586 ) << 5 ;
return V_569 ;
}
static int F_252 ( struct V_3 * V_4 )
{
return F_208 ( V_4 , V_587 ) & 0xff ;
}
static void F_253 ( struct V_3 * V_4 )
{
unsigned long V_588 = F_2 ( V_589 ) & ~ 4095 ;
F_158 ( V_588 != V_4 -> V_590 . V_591 +
V_4 -> V_592 -> V_593 -> V_594 ) ;
}
static void F_254 ( struct V_3 * V_4 )
{
unsigned long V_588 = F_2 ( V_589 ) & ~ 4095 ;
F_158 ( ( V_588 >> V_595 ) == 0 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_596 , V_597 ;
struct V_598 * V_599 = & V_4 -> V_599 ;
T_1 V_600 ;
int V_601 = 32 * 1024 ;
F_158 ( ! F_177 ( & V_2 -> V_77 ) ) ;
V_600 = F_2 ( V_589 ) ;
if ( ( V_600 >> V_595 ) == 0 ) {
V_597 = ( V_4 -> V_590 . V_591 +
( V_599 -> V_602 - V_601 ) ) ;
V_596 = ( V_597 & ( ~ 4095 ) ) ;
F_3 ( V_589 , V_596 ) ;
}
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_16 * V_603 ;
unsigned long V_596 ;
T_1 V_600 ;
int V_601 = 24 * 1024 ;
F_158 ( ! F_177 ( & V_2 -> V_77 ) ) ;
V_600 = F_2 ( V_589 ) ;
if ( V_600 ) {
int V_604 ;
V_604 = ( V_600 & ( ~ 4095 ) ) - V_4 -> V_590 . V_591 ;
V_603 = F_257 ( V_4 -> V_2 ,
V_604 ,
V_605 ,
V_601 ) ;
goto V_606;
}
V_603 = F_258 ( V_2 , V_601 ) ;
if ( ! V_603 ) {
F_179 ( L_80 ) ;
return;
}
V_596 = V_4 -> V_590 . V_591 + V_603 -> V_593 -> V_594 ;
F_3 ( V_589 , V_596 ) ;
V_606:
V_4 -> V_592 = V_603 ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_158 ( ! V_4 -> V_592 ) )
return;
F_183 ( & V_4 -> V_592 -> V_81 ) ;
V_4 -> V_592 = NULL ;
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_150 ;
F_256 ( V_2 ) ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
V_150 = F_208 ( V_4 , V_501 ) ;
switch ( ( V_150 >> 6 ) & 3 ) {
case 0 :
case 1 :
V_4 -> V_130 = 800 ;
break;
case 2 :
V_4 -> V_130 = 1066 ;
break;
case 3 :
V_4 -> V_130 = 1333 ;
break;
}
F_69 ( L_81 , V_4 -> V_130 ) ;
V_4 -> V_461 . V_519 = F_250 ( V_4 ) ;
V_4 -> V_461 . V_470 = V_4 -> V_461 . V_519 ;
F_69 ( L_82 ,
F_213 ( V_4 , V_4 -> V_461 . V_519 ) ,
V_4 -> V_461 . V_519 ) ;
V_4 -> V_461 . V_467 = F_251 ( V_4 ) ;
F_69 ( L_83 ,
F_213 ( V_4 , V_4 -> V_461 . V_467 ) ,
V_4 -> V_461 . V_467 ) ;
V_4 -> V_461 . V_472 = F_248 ( V_4 ) ;
F_69 ( L_84 ,
F_213 ( V_4 , V_4 -> V_461 . V_472 ) ,
V_4 -> V_461 . V_472 ) ;
V_4 -> V_461 . V_518 = F_252 ( V_4 ) ;
F_69 ( L_85 ,
F_213 ( V_4 , V_4 -> V_461 . V_518 ) ,
V_4 -> V_461 . V_518 ) ;
if ( V_4 -> V_461 . V_462 == 0 )
V_4 -> V_461 . V_462 = V_4 -> V_461 . V_519 ;
if ( V_4 -> V_461 . V_463 == 0 )
V_4 -> V_461 . V_463 = V_4 -> V_461 . V_518 ;
F_41 ( & V_4 -> V_461 . V_493 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_150 ;
F_255 ( V_2 ) ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
V_150 = F_208 ( V_4 , V_607 ) ;
switch ( ( V_150 >> 2 ) & 0x7 ) {
case 0 :
case 1 :
V_4 -> V_461 . V_608 = 200 ;
V_4 -> V_130 = 1600 ;
break;
case 2 :
V_4 -> V_461 . V_608 = 267 ;
V_4 -> V_130 = 1600 ;
break;
case 3 :
V_4 -> V_461 . V_608 = 333 ;
V_4 -> V_130 = 2000 ;
break;
case 4 :
V_4 -> V_461 . V_608 = 320 ;
V_4 -> V_130 = 1600 ;
break;
case 5 :
V_4 -> V_461 . V_608 = 400 ;
V_4 -> V_130 = 1600 ;
break;
}
F_69 ( L_81 , V_4 -> V_130 ) ;
V_4 -> V_461 . V_519 = F_244 ( V_4 ) ;
V_4 -> V_461 . V_470 = V_4 -> V_461 . V_519 ;
F_69 ( L_82 ,
F_213 ( V_4 , V_4 -> V_461 . V_519 ) ,
V_4 -> V_461 . V_519 ) ;
V_4 -> V_461 . V_467 = F_245 ( V_4 ) ;
F_69 ( L_83 ,
F_213 ( V_4 , V_4 -> V_461 . V_467 ) ,
V_4 -> V_461 . V_467 ) ;
V_4 -> V_461 . V_472 = F_246 ( V_4 ) ;
F_69 ( L_86 ,
F_213 ( V_4 , V_4 -> V_461 . V_472 ) ,
V_4 -> V_461 . V_472 ) ;
V_4 -> V_461 . V_518 = F_247 ( V_4 ) ;
F_69 ( L_85 ,
F_213 ( V_4 , V_4 -> V_461 . V_518 ) ,
V_4 -> V_461 . V_518 ) ;
F_212 ( ( V_4 -> V_461 . V_519 |
V_4 -> V_461 . V_467 |
V_4 -> V_461 . V_472 |
V_4 -> V_461 . V_518 ) & 1 ,
L_87 ) ;
if ( V_4 -> V_461 . V_462 == 0 )
V_4 -> V_461 . V_462 = V_4 -> V_461 . V_519 ;
if ( V_4 -> V_461 . V_463 == 0 )
V_4 -> V_461 . V_463 = V_4 -> V_461 . V_518 ;
F_41 ( & V_4 -> V_461 . V_493 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
F_259 ( V_2 ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_520 * V_521 ;
T_1 V_539 , V_150 , V_540 = 0 , V_600 ;
int V_20 ;
F_158 ( ! F_177 ( & V_4 -> V_461 . V_493 ) ) ;
V_539 = F_2 ( V_541 ) ;
if ( V_539 ) {
F_69 ( L_74 ,
V_539 ) ;
F_3 ( V_541 , V_539 ) ;
}
F_254 ( V_4 ) ;
F_21 ( V_4 , V_508 ) ;
F_3 ( V_526 , 40 << 16 ) ;
F_3 ( V_527 , 125000 ) ;
F_3 ( V_528 , 25 ) ;
F_232 (ring, dev_priv, i)
F_3 ( F_233 ( V_521 -> V_529 ) , 10 ) ;
F_3 ( V_530 , 0 ) ;
F_3 ( V_531 , 50000 ) ;
F_3 ( V_609 ,
F_77 ( V_610 |
V_611 |
V_612 ) ) ;
V_600 = F_2 ( V_589 ) ;
F_69 ( L_88 , V_600 ) ;
if ( ( F_225 ( V_2 ) & V_514 ) &&
( V_600 >> V_595 ) )
V_540 = F_222 ( 1 ) ;
F_3 ( V_507 , V_540 ) ;
F_3 ( V_474 , 59400 ) ;
F_3 ( V_476 , 245000 ) ;
F_3 ( V_473 , 66000 ) ;
F_3 ( V_475 , 350000 ) ;
F_3 ( V_535 , 10 ) ;
F_3 ( 0xA80C , F_2 ( 0xA80C ) & 0x00ffffff ) ;
F_3 ( 0xA810 , F_2 ( 0xA810 ) & 0xffffff00 ) ;
F_3 ( V_477 ,
V_479 |
V_480 |
V_481 |
V_482 |
V_483 ) ;
V_150 = F_208 ( V_4 , V_501 ) ;
F_69 ( L_89 , V_150 & 0x10 ? L_90 : L_91 ) ;
F_69 ( L_92 , V_150 ) ;
V_4 -> V_461 . V_468 = ( V_150 >> 8 ) & 0xff ;
F_69 ( L_93 ,
F_213 ( V_4 , V_4 -> V_461 . V_468 ) ,
V_4 -> V_461 . V_468 ) ;
F_69 ( L_94 ,
F_213 ( V_4 , V_4 -> V_461 . V_467 ) ,
V_4 -> V_461 . V_467 ) ;
F_205 ( V_4 -> V_2 , V_4 -> V_461 . V_467 ) ;
F_226 ( V_2 ) ;
F_23 ( V_4 , V_508 ) ;
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_520 * V_521 ;
T_1 V_539 , V_150 , V_540 = 0 ;
int V_20 ;
F_158 ( ! F_177 ( & V_4 -> V_461 . V_493 ) ) ;
F_253 ( V_4 ) ;
if ( ( V_539 = F_2 ( V_541 ) ) ) {
F_69 ( L_74 ,
V_539 ) ;
F_3 ( V_541 , V_539 ) ;
}
F_21 ( V_4 , V_508 ) ;
F_3 ( V_474 , 59400 ) ;
F_3 ( V_476 , 245000 ) ;
F_3 ( V_473 , 66000 ) ;
F_3 ( V_475 , 350000 ) ;
F_3 ( V_535 , 10 ) ;
F_3 ( V_534 , 0xf4240 ) ;
F_3 ( V_477 ,
V_478 |
V_479 |
V_480 |
V_481 |
V_482 |
V_613 ) ;
F_3 ( V_526 , 0x00280000 ) ;
F_3 ( V_527 , 125000 ) ;
F_3 ( V_528 , 25 ) ;
F_232 (ring, dev_priv, i)
F_3 ( F_233 ( V_521 -> V_529 ) , 10 ) ;
F_3 ( V_531 , 0x557 ) ;
F_3 ( V_609 ,
F_77 ( V_614 |
V_615 |
V_611 |
V_612 ) ) ;
if ( F_225 ( V_2 ) & V_514 )
V_540 = V_509 | V_616 ;
F_221 ( V_2 , V_540 ) ;
F_3 ( V_507 , V_540 ) ;
V_150 = F_208 ( V_4 , V_501 ) ;
F_69 ( L_89 , V_150 & 0x10 ? L_90 : L_91 ) ;
F_69 ( L_92 , V_150 ) ;
V_4 -> V_461 . V_468 = ( V_150 >> 8 ) & 0xff ;
F_69 ( L_93 ,
F_213 ( V_4 , V_4 -> V_461 . V_468 ) ,
V_4 -> V_461 . V_468 ) ;
F_69 ( L_94 ,
F_213 ( V_4 , V_4 -> V_461 . V_467 ) ,
V_4 -> V_461 . V_467 ) ;
F_205 ( V_4 -> V_2 , V_4 -> V_461 . V_467 ) ;
F_228 ( V_2 ) ;
F_23 ( V_4 , V_508 ) ;
}
void F_265 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_140 . V_617 ) {
F_182 ( V_4 -> V_140 . V_617 ) ;
F_183 ( & V_4 -> V_140 . V_617 -> V_81 ) ;
V_4 -> V_140 . V_617 = NULL ;
}
if ( V_4 -> V_140 . V_618 ) {
F_182 ( V_4 -> V_140 . V_618 ) ;
F_183 ( & V_4 -> V_140 . V_618 -> V_81 ) ;
V_4 -> V_140 . V_618 = NULL ;
}
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_2 ( V_619 ) ) {
F_3 ( V_620 , F_2 ( V_620 ) | V_621 ) ;
F_4 ( ( ( F_2 ( V_620 ) & V_622 ) == V_623 ) ,
50 ) ;
F_3 ( V_619 , 0 ) ;
F_22 ( V_619 ) ;
F_3 ( V_620 , F_2 ( V_620 ) & ~ V_621 ) ;
F_22 ( V_620 ) ;
}
}
static int F_267 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_140 . V_617 == NULL )
V_4 -> V_140 . V_617 = F_176 ( V_2 ) ;
if ( ! V_4 -> V_140 . V_617 )
return - V_624 ;
if ( V_4 -> V_140 . V_618 == NULL )
V_4 -> V_140 . V_618 = F_176 ( V_2 ) ;
if ( ! V_4 -> V_140 . V_618 ) {
F_265 ( V_2 ) ;
return - V_624 ;
}
return 0 ;
}
static void F_268 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_520 * V_521 = & V_4 -> V_521 [ V_625 ] ;
bool V_626 ;
int V_291 ;
if ( ! F_225 ( V_2 ) )
return;
F_158 ( ! F_177 ( & V_2 -> V_77 ) ) ;
V_291 = F_267 ( V_2 ) ;
if ( V_291 )
return;
V_626 = V_4 -> V_590 . V_627 ;
V_4 -> V_590 . V_627 = false ;
V_291 = F_269 ( V_521 , 6 ) ;
if ( V_291 ) {
F_265 ( V_2 ) ;
V_4 -> V_590 . V_627 = V_626 ;
return;
}
F_270 ( V_521 , V_628 | V_629 ) ;
F_270 ( V_521 , V_630 ) ;
F_270 ( V_521 , F_26 ( V_4 -> V_140 . V_617 ) |
V_631 |
V_632 |
V_633 |
V_634 ) ;
F_270 ( V_521 , V_628 ) ;
F_270 ( V_521 , V_635 ) ;
F_270 ( V_521 , V_636 ) ;
F_271 ( V_521 ) ;
V_291 = F_272 ( V_521 ) ;
V_4 -> V_590 . V_627 = V_626 ;
if ( V_291 ) {
F_47 ( L_95 ) ;
F_265 ( V_2 ) ;
return;
}
F_3 ( V_619 , F_26 ( V_4 -> V_140 . V_618 ) | V_637 ) ;
F_3 ( V_620 , F_2 ( V_620 ) & ~ V_621 ) ;
F_221 ( V_2 , V_510 ) ;
}
static unsigned long F_273 ( T_1 V_638 )
{
unsigned long V_639 ;
int div = ( V_638 & 0x3f0000 ) >> 16 ;
int V_640 = ( V_638 & 0x3000 ) >> 12 ;
int V_641 = ( V_638 & 0x7 ) ;
if ( ! V_641 )
return 0 ;
V_639 = ( ( div * 133333 ) / ( ( 1 << V_640 ) * V_641 ) ) ;
return V_639 ;
}
static unsigned long F_274 ( struct V_3 * V_4 )
{
T_8 V_642 , V_560 , V_291 ;
T_1 V_643 , V_644 , V_645 , V_646 = 0 , V_647 = 0 ;
unsigned long V_648 = F_192 ( V_451 ) , V_649 ;
int V_20 ;
F_185 ( & V_411 ) ;
V_649 = V_648 - V_4 -> V_140 . V_450 ;
if ( V_649 <= 10 )
return V_4 -> V_140 . V_650 ;
V_643 = F_2 ( V_651 ) ;
V_644 = F_2 ( V_652 ) ;
V_645 = F_2 ( V_653 ) ;
V_642 = V_643 + V_644 + V_645 ;
if ( V_642 < V_4 -> V_140 . V_449 ) {
V_560 = ~ 0UL - V_4 -> V_140 . V_449 ;
V_560 += V_642 ;
} else {
V_560 = V_642 - V_4 -> V_140 . V_449 ;
}
for ( V_20 = 0 ; V_20 < F_71 ( V_654 ) ; V_20 ++ ) {
if ( V_654 [ V_20 ] . V_20 == V_4 -> V_140 . V_142 &&
V_654 [ V_20 ] . V_655 == V_4 -> V_140 . V_141 ) {
V_646 = V_654 [ V_20 ] . V_646 ;
V_647 = V_654 [ V_20 ] . V_647 ;
break;
}
}
V_560 = F_112 ( V_560 , V_649 ) ;
V_291 = ( ( V_646 * V_560 ) + V_647 ) ;
V_291 = F_112 ( V_291 , 10 ) ;
V_4 -> V_140 . V_449 = V_642 ;
V_4 -> V_140 . V_450 = V_648 ;
V_4 -> V_140 . V_650 = V_291 ;
return V_291 ;
}
unsigned long F_275 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_150 ;
if ( F_57 ( V_2 ) -> V_106 != 5 )
return 0 ;
F_189 ( & V_411 ) ;
V_150 = F_274 ( V_4 ) ;
F_194 ( & V_411 ) ;
return V_150 ;
}
unsigned long F_276 ( struct V_3 * V_4 )
{
unsigned long V_646 , V_656 , V_657 ;
T_1 V_658 ;
V_658 = F_2 ( V_659 ) ;
V_646 = ( ( V_658 & V_660 ) >> V_661 ) ;
V_656 = F_277 ( V_662 ) ;
V_657 = V_658 & V_663 ;
return ( ( V_646 * V_656 ) / 127 ) - V_657 ;
}
static T_2 F_278 ( struct V_3 * V_4 , T_7 V_664 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
static const struct V_665 {
T_2 V_666 ;
T_2 V_667 ;
} V_665 [] = {
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
if ( F_57 ( V_2 ) -> V_668 )
return V_665 [ V_664 ] . V_667 ;
else
return V_665 [ V_664 ] . V_666 ;
}
static void F_279 ( struct V_3 * V_4 )
{
T_8 V_648 , V_560 , V_669 ;
T_1 V_670 ;
F_185 ( & V_411 ) ;
V_648 = F_193 () ;
V_669 = V_648 - V_4 -> V_140 . V_453 ;
F_280 ( V_669 , V_671 ) ;
if ( ! V_669 )
return;
V_670 = F_2 ( V_672 ) ;
if ( V_670 < V_4 -> V_140 . V_452 ) {
V_560 = ~ 0UL - V_4 -> V_140 . V_452 ;
V_560 += V_670 ;
} else {
V_560 = V_670 - V_4 -> V_140 . V_452 ;
}
V_4 -> V_140 . V_452 = V_670 ;
V_4 -> V_140 . V_453 = V_648 ;
V_560 = V_560 * 1181 ;
V_560 = F_112 ( V_560 , V_669 * 10 ) ;
V_4 -> V_140 . V_673 = V_560 ;
}
void F_281 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_57 ( V_2 ) -> V_106 != 5 )
return;
F_189 ( & V_411 ) ;
F_279 ( V_4 ) ;
F_194 ( & V_411 ) ;
}
static unsigned long F_282 ( struct V_3 * V_4 )
{
unsigned long V_655 , V_674 , V_675 , V_676 , V_677 ;
T_1 V_664 , V_678 ;
F_185 ( & V_411 ) ;
V_664 = F_2 ( V_438 + ( V_4 -> V_461 . V_468 * 4 ) ) ;
V_664 = ( V_664 >> 24 ) & 0x7f ;
V_678 = F_278 ( V_4 , V_664 ) ;
V_675 = V_678 ;
V_655 = F_276 ( V_4 ) ;
if ( V_655 > 80 )
V_674 = ( ( V_655 * 2349 ) + 135940 ) ;
else if ( V_655 >= 50 )
V_674 = ( ( V_655 * 964 ) + 29317 ) ;
else
V_674 = ( ( V_655 * 301 ) + 1004 ) ;
V_674 = V_674 * ( ( 150142 * V_675 ) / 10000 - 78642 ) ;
V_674 /= 100000 ;
V_676 = ( V_674 * V_4 -> V_140 . V_674 ) ;
V_677 = ( V_676 * V_675 ) / 10000 ;
V_677 /= 100 ;
F_279 ( V_4 ) ;
return V_4 -> V_140 . V_673 + V_677 ;
}
unsigned long F_283 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_150 ;
if ( F_57 ( V_2 ) -> V_106 != 5 )
return 0 ;
F_189 ( & V_411 ) ;
V_150 = F_282 ( V_4 ) ;
F_194 ( & V_411 ) ;
return V_150 ;
}
unsigned long F_284 ( void )
{
struct V_3 * V_4 ;
unsigned long V_679 , V_680 , V_291 = 0 ;
F_189 ( & V_411 ) ;
if ( ! V_681 )
goto V_682;
V_4 = V_681 ;
V_679 = F_274 ( V_4 ) ;
V_680 = F_282 ( V_4 ) ;
V_291 = V_679 + V_680 ;
V_682:
F_194 ( & V_411 ) ;
return V_291 ;
}
bool F_285 ( void )
{
struct V_3 * V_4 ;
bool V_291 = true ;
F_189 ( & V_411 ) ;
if ( ! V_681 ) {
V_291 = false ;
goto V_682;
}
V_4 = V_681 ;
if ( V_4 -> V_140 . V_441 > V_4 -> V_140 . V_420 )
V_4 -> V_140 . V_441 -- ;
V_682:
F_194 ( & V_411 ) ;
return V_291 ;
}
bool F_286 ( void )
{
struct V_3 * V_4 ;
bool V_291 = true ;
F_189 ( & V_411 ) ;
if ( ! V_681 ) {
V_291 = false ;
goto V_682;
}
V_4 = V_681 ;
if ( V_4 -> V_140 . V_441 < V_4 -> V_140 . V_442 )
V_4 -> V_140 . V_441 ++ ;
V_682:
F_194 ( & V_411 ) ;
return V_291 ;
}
bool F_287 ( void )
{
struct V_3 * V_4 ;
struct V_520 * V_521 ;
bool V_291 = false ;
int V_20 ;
F_189 ( & V_411 ) ;
if ( ! V_681 )
goto V_682;
V_4 = V_681 ;
F_232 (ring, dev_priv, i)
V_291 |= ! F_288 ( & V_521 -> V_683 ) ;
V_682:
F_194 ( & V_411 ) ;
return V_291 ;
}
bool F_289 ( void )
{
struct V_3 * V_4 ;
bool V_291 = true ;
F_189 ( & V_411 ) ;
if ( ! V_681 ) {
V_291 = false ;
goto V_682;
}
V_4 = V_681 ;
V_4 -> V_140 . V_441 = V_4 -> V_140 . V_422 ;
if ( ! F_184 ( V_4 -> V_2 , V_4 -> V_140 . V_422 ) )
V_291 = false ;
V_682:
F_194 ( & V_411 ) ;
return V_291 ;
}
static void
F_290 ( void )
{
void (* F_291)( void );
F_291 = F_292 ( V_684 ) ;
if ( F_291 ) {
F_291 () ;
F_293 ( V_684 ) ;
}
}
void F_294 ( struct V_3 * V_4 )
{
F_189 ( & V_411 ) ;
V_681 = V_4 ;
F_194 ( & V_411 ) ;
F_290 () ;
}
void F_295 ( void )
{
F_189 ( & V_411 ) ;
V_681 = NULL ;
F_194 ( & V_411 ) ;
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_685 ;
T_7 V_686 [ 16 ] ;
int V_20 ;
F_3 ( V_687 , 0 ) ;
F_22 ( V_687 ) ;
F_3 ( V_688 , 0x15040d00 ) ;
F_3 ( V_689 , 0x007f0000 ) ;
F_3 ( V_690 , 0x1e220004 ) ;
F_3 ( V_691 , 0x04000004 ) ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ )
F_3 ( V_692 + ( V_20 * 4 ) , 0 ) ;
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ )
F_3 ( V_693 + ( V_20 * 4 ) , 0 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ ) {
T_1 V_694 = F_2 ( V_438 + ( V_20 * 4 ) ) ;
unsigned long V_639 = F_273 ( V_694 ) ;
unsigned long V_695 = ( V_694 & V_439 ) >>
V_440 ;
unsigned long V_150 ;
V_150 = V_695 * V_695 ;
V_150 *= ( V_639 / 1000 ) ;
V_150 *= 255 ;
V_150 /= ( 127 * 127 * 900 ) ;
if ( V_150 > 0xff )
F_47 ( L_96 , V_150 ) ;
V_686 [ V_20 ] = V_150 ;
}
V_686 [ 14 ] = 0 ;
V_686 [ 15 ] = 0 ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
T_1 V_150 = ( V_686 [ V_20 * 4 ] << 24 ) | ( V_686 [ ( V_20 * 4 ) + 1 ] << 16 ) |
( V_686 [ ( V_20 * 4 ) + 2 ] << 8 ) | ( V_686 [ ( V_20 * 4 ) + 3 ] ) ;
F_3 ( V_696 + ( V_20 * 4 ) , V_150 ) ;
}
F_3 ( V_697 , 0 ) ;
F_3 ( V_698 , 0 ) ;
F_3 ( V_699 , 0x00007f00 ) ;
F_3 ( V_700 , 0x0000000e ) ;
F_3 ( V_701 , 0x000e0000 ) ;
F_3 ( V_702 , 0x68000300 ) ;
F_3 ( V_703 , 0x42000000 ) ;
F_3 ( V_704 , 0x00140031 ) ;
F_3 ( V_705 , 0 ) ;
F_3 ( V_706 , 0 ) ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
F_3 ( V_707 + ( V_20 * 4 ) , 0 ) ;
F_3 ( V_687 , 0x80000019 ) ;
V_685 = F_2 ( V_708 ) ;
V_4 -> V_140 . V_674 = ( V_685 & V_709 ) ;
}
void F_297 ( struct V_1 * V_2 )
{
V_93 . V_513 = F_223 ( V_2 , V_93 . V_513 ) ;
if ( F_210 ( V_2 ) )
F_261 ( V_2 ) ;
else if ( F_73 ( V_2 ) )
F_260 ( V_2 ) ;
}
void F_298 ( struct V_1 * V_2 )
{
if ( F_210 ( V_2 ) )
return;
else if ( F_73 ( V_2 ) )
F_262 ( V_2 ) ;
}
void F_299 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_158 ( F_300 ( V_4 ) ) ;
F_301 ( & V_4 -> V_461 . V_710 ) ;
F_302 ( & V_4 -> V_461 . V_76 ) ;
F_209 ( V_4 ) ;
}
void F_303 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_158 ( F_300 ( V_4 ) ) ;
if ( F_224 ( V_2 ) ) {
F_195 ( V_2 ) ;
F_266 ( V_2 ) ;
} else if ( F_57 ( V_2 ) -> V_106 >= 6 ) {
F_299 ( V_2 ) ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
if ( F_210 ( V_2 ) )
F_219 ( V_2 ) ;
else if ( F_73 ( V_2 ) )
F_220 ( V_2 ) ;
else
F_218 ( V_2 ) ;
V_4 -> V_461 . V_175 = false ;
F_41 ( & V_4 -> V_461 . V_493 ) ;
}
}
static void F_304 ( struct V_73 * V_76 )
{
struct V_3 * V_4 =
F_38 ( V_76 , struct V_3 ,
V_461 . V_710 . V_76 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
if ( F_210 ( V_2 ) ) {
F_263 ( V_2 ) ;
} else if ( F_73 ( V_2 ) ) {
F_264 ( V_2 ) ;
} else if ( F_138 ( V_2 ) ) {
F_231 ( V_2 ) ;
F_239 ( V_2 ) ;
} else {
F_234 ( V_2 ) ;
F_239 ( V_2 ) ;
}
V_4 -> V_461 . V_175 = true ;
F_41 ( & V_4 -> V_461 . V_493 ) ;
F_305 ( V_4 ) ;
}
void F_306 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_224 ( V_2 ) ) {
F_40 ( & V_2 -> V_77 ) ;
F_188 ( V_2 ) ;
F_268 ( V_2 ) ;
F_296 ( V_2 ) ;
F_41 ( & V_2 -> V_77 ) ;
} else if ( F_57 ( V_2 ) -> V_106 >= 6 ) {
if ( F_49 ( & V_4 -> V_461 . V_710 ,
F_307 ( V_711 ) ) )
F_308 ( V_4 ) ;
}
}
void F_309 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_461 . V_175 = false ;
F_306 ( V_2 ) ;
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_712 , V_713 ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_67 ;
F_161 (dev_priv, pipe) {
F_3 ( F_312 ( V_67 ) ,
F_2 ( F_312 ( V_67 ) ) |
V_714 ) ;
F_313 ( V_4 , V_67 ) ;
}
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_382 , F_2 ( V_382 ) & ~ V_361 ) ;
F_3 ( V_383 , F_2 ( V_383 ) & ~ V_361 ) ;
F_3 ( V_384 , F_2 ( V_384 ) & ~ V_361 ) ;
}
static void F_315 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_715 = V_716 ;
V_715 |= V_717 |
V_718 |
V_719 ;
F_3 ( V_720 ,
V_721 |
V_722 ) ;
F_3 ( V_723 ,
V_724 ) ;
F_3 ( V_725 ,
( F_2 ( V_725 ) |
V_726 | V_727 ) ) ;
V_715 |= V_728 ;
F_3 ( V_392 ,
( F_2 ( V_392 ) |
V_393 ) ) ;
F_314 ( V_2 ) ;
if ( F_224 ( V_2 ) ) {
F_3 ( V_65 ,
F_2 ( V_65 ) |
V_66 ) ;
F_3 ( V_725 ,
F_2 ( V_725 ) |
V_726 ) ;
}
F_3 ( V_729 , V_715 ) ;
F_3 ( V_725 ,
F_2 ( V_725 ) |
V_730 ) ;
F_3 ( V_731 ,
V_732 << 16 |
V_732 ) ;
F_3 ( V_733 ,
F_77 ( V_734 ) ) ;
F_3 ( V_733 , F_78 ( V_735 ) ) ;
F_311 ( V_2 ) ;
F_310 ( V_2 ) ;
}
static void F_316 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_67 ;
T_3 V_150 ;
F_3 ( V_712 , V_713 |
V_736 |
V_737 ) ;
F_3 ( V_738 , F_2 ( V_738 ) |
V_739 ) ;
F_161 (dev_priv, pipe) {
V_150 = F_2 ( F_317 ( V_67 ) ) ;
V_150 |= V_740 ;
V_150 &= ~ V_741 ;
if ( V_4 -> V_742 . V_743 )
V_150 |= V_741 ;
V_150 &= ~ V_744 ;
V_150 &= ~ V_745 ;
V_150 &= ~ V_746 ;
F_3 ( F_317 ( V_67 ) , V_150 ) ;
}
F_161 (dev_priv, pipe) {
F_3 ( F_318 ( V_67 ) ,
V_747 ) ;
}
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_120 ;
V_120 = F_2 ( V_329 ) ;
if ( ( V_120 & V_748 ) != V_749 )
F_5 ( L_97 ,
V_120 ) ;
}
static void F_320 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_715 = V_716 ;
F_3 ( V_729 , V_715 ) ;
F_3 ( V_725 ,
F_2 ( V_725 ) |
V_730 ) ;
F_3 ( V_750 ,
F_77 ( V_751 ) ) ;
F_3 ( V_733 , F_78 ( V_735 ) ) ;
F_3 ( V_752 ,
V_753 | V_754 ) ;
F_314 ( V_2 ) ;
F_3 ( V_733 ,
F_78 ( V_755 ) ) ;
F_3 ( V_756 ,
F_2 ( V_756 ) |
V_757 |
V_758 ) ;
F_3 ( V_759 ,
V_760 |
V_761 ) ;
F_3 ( V_762 ,
F_77 ( V_763 ) ) ;
F_3 ( V_762 ,
F_77 ( V_764 ) ) ;
F_3 ( V_65 ,
F_2 ( V_65 ) |
V_66 | V_765 ) ;
F_3 ( V_725 ,
F_2 ( V_725 ) |
V_726 | V_727 ) ;
F_3 ( V_729 ,
F_2 ( V_729 ) |
V_728 |
V_719 ) ;
F_311 ( V_2 ) ;
F_316 ( V_2 ) ;
F_319 ( V_2 ) ;
}
static void F_321 ( struct V_3 * V_4 )
{
T_3 V_177 = F_2 ( V_766 ) ;
V_177 &= ~ V_767 ;
V_177 |= V_768 ;
V_177 |= V_769 ;
V_177 |= V_770 ;
F_3 ( V_766 , V_177 ) ;
}
static void F_322 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_771 == V_772 )
F_3 ( V_712 ,
F_2 ( V_712 ) |
V_773 ) ;
F_3 ( V_774 ,
F_2 ( V_774 ) |
V_747 ) ;
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_771 == V_772 ) {
T_3 V_150 = F_2 ( V_712 ) ;
V_150 &= ~ V_773 ;
F_3 ( V_712 , V_150 ) ;
}
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_67 V_67 ;
F_3 ( V_382 , 0 ) ;
F_3 ( V_383 , 0 ) ;
F_3 ( V_384 , 0 ) ;
F_3 ( V_775 , F_77 ( V_776 ) ) ;
F_3 ( V_762 ,
F_77 ( F_325 ( 2 ) ) ) ;
F_3 ( V_777 , F_2 ( V_777 ) | V_778 ) ;
F_3 ( V_779 ,
F_2 ( V_779 ) | V_780 ) ;
F_161 (dev_priv, pipe) {
F_3 ( F_33 ( V_67 ) ,
F_2 ( F_33 ( V_67 ) ) |
V_781 ) ;
}
F_3 ( V_766 ,
F_2 ( V_766 ) &
~ ( V_782 | V_783 ) ) ;
F_3 ( V_784 ,
F_77 ( V_785 ) ) ;
F_3 ( V_786 , F_2 ( V_786 ) |
V_787 ) ;
F_322 ( V_2 ) ;
}
static void F_326 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_314 ( V_2 ) ;
F_3 ( V_788 , V_789 ) ;
F_3 ( V_790 ,
F_77 ( V_791 ) ) ;
F_3 ( V_792 ,
F_2 ( V_792 ) |
V_793 ) ;
F_3 ( V_766 ,
F_2 ( V_766 ) & ~ V_783 ) ;
F_3 ( V_794 , F_78 ( V_735 ) ) ;
F_3 ( V_794 ,
F_78 ( V_795 ) ) ;
F_3 ( V_796 ,
F_77 ( V_797 ) ) ;
F_3 ( V_798 ,
V_753 | V_754 ) ;
F_3 ( V_777 , F_2 ( V_777 ) | V_778 ) ;
F_3 ( V_779 ,
F_2 ( V_779 ) | V_799 ) ;
F_322 ( V_2 ) ;
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_800 ;
F_314 ( V_2 ) ;
F_3 ( V_729 , V_716 ) ;
F_3 ( V_762 ,
F_77 ( V_801 ) ) ;
F_3 ( V_802 ,
V_803 |
V_804 ) ;
if ( F_328 ( V_2 ) )
F_3 ( V_805 ,
F_77 ( V_806 ) ) ;
F_3 ( V_794 , F_78 ( V_735 ) ) ;
F_3 ( V_807 ,
V_808 ) ;
F_3 ( V_809 ,
V_810 ) ;
F_3 ( V_811 ,
V_812 ) ;
if ( F_328 ( V_2 ) )
F_3 ( V_813 ,
F_77 ( V_814 ) ) ;
else {
F_3 ( V_813 ,
F_77 ( V_814 ) ) ;
F_3 ( V_815 ,
F_77 ( V_814 ) ) ;
}
F_3 ( V_816 , F_2 ( V_816 ) &
~ V_817 ) ;
F_3 ( V_759 ,
V_818 ) ;
F_3 ( V_792 ,
F_2 ( V_792 ) |
V_793 ) ;
F_311 ( V_2 ) ;
F_321 ( V_4 ) ;
if ( 0 ) {
F_3 ( V_794 ,
F_78 ( V_795 ) ) ;
}
F_3 ( V_796 ,
F_77 ( V_797 ) ) ;
F_3 ( V_798 ,
V_753 | V_754 ) ;
V_800 = F_2 ( V_819 ) ;
V_800 &= ~ V_820 ;
V_800 |= V_821 ;
F_3 ( V_819 , V_800 ) ;
if ( ! F_329 ( V_2 ) )
F_316 ( V_2 ) ;
F_319 ( V_2 ) ;
}
static void F_330 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_822 , V_823 ) ;
F_3 ( V_762 ,
F_77 ( V_801 ) ) ;
F_3 ( V_802 ,
V_803 |
V_804 ) ;
F_3 ( V_805 ,
F_77 ( V_824 |
V_806 ) ) ;
F_3 ( V_794 , F_78 ( V_735 ) ) ;
F_3 ( V_816 , F_2 ( V_816 ) &
~ V_817 ) ;
F_3 ( V_813 ,
F_77 ( V_814 ) ) ;
F_3 ( V_792 ,
F_2 ( V_792 ) |
V_793 ) ;
F_321 ( V_4 ) ;
F_3 ( V_759 ,
V_818 ) ;
F_3 ( V_825 ,
F_2 ( V_825 ) | V_826 ) ;
F_3 ( V_827 , V_828 ) ;
F_3 ( V_796 ,
F_77 ( V_797 ) ) ;
F_3 ( V_829 , V_830 ) ;
F_3 ( V_831 , V_832 ) ;
}
static void F_331 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_822 , V_823 ) ;
F_3 ( V_827 , V_828 ) ;
F_3 ( V_766 ,
F_2 ( V_766 ) &
~ ( V_782 | V_783 ) ) ;
F_3 ( V_784 ,
F_77 ( V_785 ) ) ;
F_3 ( V_756 , F_2 ( V_756 ) |
V_758 ) ;
F_3 ( V_786 , F_2 ( V_786 ) |
V_787 ) ;
F_3 ( V_831 , F_2 ( V_831 ) |
V_833 ) ;
F_3 ( V_784 ,
F_77 ( V_834 ) ) ;
F_3 ( V_756 , F_2 ( V_756 ) |
V_835 ) ;
}
static void F_332 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_715 ;
F_3 ( V_836 , 0 ) ;
F_3 ( V_837 , V_838 |
V_839 |
V_840 ) ;
F_3 ( V_841 , 0 ) ;
V_715 = V_823 |
V_842 |
V_843 ;
if ( F_333 ( V_2 ) )
V_715 |= V_844 ;
F_3 ( V_822 , V_715 ) ;
F_3 ( V_733 ,
F_77 ( V_734 ) ) ;
F_3 ( V_733 , F_78 ( V_735 ) ) ;
F_311 ( V_2 ) ;
}
static void F_334 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_836 , V_845 ) ;
F_3 ( V_837 , 0 ) ;
F_3 ( V_822 , 0 ) ;
F_3 ( V_841 , 0 ) ;
F_186 ( V_846 , 0 ) ;
F_3 ( V_847 ,
F_77 ( V_828 ) ) ;
F_3 ( V_733 , F_78 ( V_735 ) ) ;
}
static void F_335 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_836 , V_848 |
V_845 |
V_849 |
V_850 |
V_851 ) ;
F_3 ( V_837 , 0 ) ;
F_3 ( V_847 ,
F_77 ( V_828 ) ) ;
F_3 ( V_733 , F_78 ( V_735 ) ) ;
}
static void F_336 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_852 = F_2 ( V_853 ) ;
V_852 |= V_854 | V_855 |
V_856 ;
F_3 ( V_853 , V_852 ) ;
if ( F_75 ( V_2 ) )
F_3 ( V_857 , F_77 ( V_858 ) ) ;
F_3 ( V_857 , F_78 ( V_859 ) ) ;
F_3 ( V_158 , F_77 ( V_860 ) ) ;
F_3 ( V_847 , F_77 ( V_861 ) ) ;
F_3 ( V_847 ,
F_77 ( V_828 ) ) ;
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_836 , V_862 ) ;
F_3 ( V_863 , F_77 ( V_864 ) |
F_78 ( V_865 ) ) ;
F_3 ( V_866 ,
F_77 ( V_867 ) ) ;
}
static void F_338 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_822 , V_842 ) ;
F_3 ( V_866 ,
F_77 ( V_868 ) |
F_77 ( V_869 ) ) ;
}
void F_339 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_69 . V_870 ( V_2 ) ;
}
void F_340 ( struct V_1 * V_2 )
{
if ( F_341 ( V_2 ) )
F_323 ( V_2 ) ;
}
static bool F_342 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
return F_2 ( V_873 ) ==
( V_874 | V_875 ) ;
}
bool F_343 ( struct V_3 * V_4 ,
enum V_876 V_877 )
{
struct V_878 * V_879 ;
struct V_871 * V_872 ;
bool V_880 ;
int V_20 ;
if ( V_4 -> V_881 . V_882 )
return false ;
V_879 = & V_4 -> V_879 ;
V_880 = true ;
F_344 (i, power_well, BIT(domain), power_domains) {
if ( V_872 -> V_883 )
continue;
if ( ! V_872 -> V_884 ) {
V_880 = false ;
break;
}
}
return V_880 ;
}
bool F_345 ( struct V_3 * V_4 ,
enum V_876 V_877 )
{
struct V_878 * V_879 ;
bool V_291 ;
V_879 = & V_4 -> V_879 ;
F_40 ( & V_879 -> V_885 ) ;
V_291 = F_343 ( V_4 , V_877 ) ;
F_41 ( & V_879 -> V_885 ) ;
return V_291 ;
}
static void F_346 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_347 ( V_2 -> V_498 , V_886 ) ;
F_348 ( F_349 ( V_887 ) , V_888 ) ;
F_350 ( V_2 -> V_498 , V_886 ) ;
if ( F_138 ( V_2 ) )
F_351 ( V_4 ) ;
}
static void F_352 ( struct V_3 * V_4 ,
struct V_871 * V_872 , bool V_149 )
{
bool V_880 , V_889 ;
T_3 V_120 ;
V_120 = F_2 ( V_873 ) ;
V_880 = V_120 & V_875 ;
V_889 = V_120 & V_874 ;
if ( V_149 ) {
if ( ! V_889 )
F_3 ( V_873 ,
V_874 ) ;
if ( ! V_880 ) {
F_5 ( L_98 ) ;
if ( F_4 ( ( F_2 ( V_873 ) &
V_875 ) , 20 ) )
F_47 ( L_99 ) ;
}
F_346 ( V_4 ) ;
} else {
if ( V_889 ) {
F_3 ( V_873 , 0 ) ;
F_22 ( V_873 ) ;
F_5 ( L_100 ) ;
}
}
}
static void F_353 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_352 ( V_4 , V_872 , V_872 -> V_670 > 0 ) ;
if ( F_2 ( V_890 ) & V_874 )
F_3 ( V_890 , 0 ) ;
}
static void F_354 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_352 ( V_4 , V_872 , true ) ;
}
static void F_355 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_352 ( V_4 , V_872 , false ) ;
}
static void F_356 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
}
static bool F_357 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
return true ;
}
static void F_358 ( struct V_3 * V_4 ,
struct V_871 * V_872 , bool V_149 )
{
enum V_891 V_892 = V_872 -> V_893 ;
T_1 V_485 ;
T_1 V_894 ;
T_1 V_895 ;
V_485 = F_359 ( V_892 ) ;
V_894 = V_149 ? F_360 ( V_892 ) :
F_361 ( V_892 ) ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
#define F_362 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_362 )
goto V_606;
V_895 = F_208 ( V_4 , V_896 ) ;
V_895 &= ~ V_485 ;
V_895 |= V_894 ;
F_207 ( V_4 , V_896 , V_895 ) ;
if ( F_4 ( F_362 , 100 ) )
F_47 ( L_101 ,
V_894 ,
F_208 ( V_4 , V_896 ) ) ;
#undef F_362
V_606:
F_41 ( & V_4 -> V_461 . V_493 ) ;
}
static void F_363 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_358 ( V_4 , V_872 , V_872 -> V_670 > 0 ) ;
}
static void F_364 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_358 ( V_4 , V_872 , true ) ;
}
static void F_365 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_358 ( V_4 , V_872 , false ) ;
}
static bool F_366 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
int V_892 = V_872 -> V_893 ;
bool V_175 = false ;
T_1 V_485 ;
T_1 V_894 ;
T_1 V_895 ;
V_485 = F_359 ( V_892 ) ;
V_895 = F_360 ( V_892 ) ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
V_894 = F_208 ( V_4 , V_897 ) & V_485 ;
F_158 ( V_894 != F_360 ( V_892 ) &&
V_894 != F_361 ( V_892 ) ) ;
if ( V_894 == V_895 )
V_175 = true ;
V_895 = F_208 ( V_4 , V_896 ) & V_485 ;
F_158 ( V_895 != V_894 ) ;
F_41 ( & V_4 -> V_461 . V_493 ) ;
return V_175 ;
}
static void F_367 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_368 ( V_872 -> V_893 != V_898 ) ;
F_358 ( V_4 , V_872 , true ) ;
F_189 ( & V_4 -> V_503 ) ;
F_369 ( V_4 ) ;
F_194 ( & V_4 -> V_503 ) ;
if ( V_4 -> V_879 . V_899 )
return;
F_370 ( V_4 -> V_2 ) ;
F_371 ( V_4 -> V_2 ) ;
}
static void F_372 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_368 ( V_872 -> V_893 != V_898 ) ;
F_189 ( & V_4 -> V_503 ) ;
F_373 ( V_4 ) ;
F_194 ( & V_4 -> V_503 ) ;
F_358 ( V_4 , V_872 , false ) ;
F_374 ( V_4 ) ;
}
static void F_375 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_368 ( V_872 -> V_893 != V_900 ) ;
F_3 ( F_376 ( V_239 ) , F_2 ( F_376 ( V_239 ) ) |
V_901 | V_902 ) ;
F_377 ( 1 ) ;
F_358 ( V_4 , V_872 , true ) ;
F_3 ( V_903 , F_2 ( V_903 ) | V_904 ) ;
}
static void F_378 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
enum V_67 V_67 ;
F_368 ( V_872 -> V_893 != V_900 ) ;
F_161 (dev_priv, pipe)
F_379 ( V_4 , V_67 ) ;
F_3 ( V_903 , F_2 ( V_903 ) & ~ V_904 ) ;
F_358 ( V_4 , V_872 , false ) ;
}
static void F_380 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
enum V_905 V_906 ;
F_368 ( V_872 -> V_893 != V_900 &&
V_872 -> V_893 != V_907 ) ;
if ( V_872 -> V_893 == V_900 ) {
V_906 = V_908 ;
F_3 ( F_376 ( V_239 ) , F_2 ( F_376 ( V_239 ) ) |
V_901 ) ;
F_3 ( F_376 ( V_239 ) , F_2 ( F_376 ( V_239 ) ) |
V_901 | V_902 ) ;
} else {
V_906 = V_909 ;
F_3 ( F_376 ( V_248 ) , F_2 ( F_376 ( V_248 ) ) |
V_901 | V_902 ) ;
}
F_377 ( 1 ) ;
F_358 ( V_4 , V_872 , true ) ;
if ( F_4 ( F_2 ( V_910 ) & F_381 ( V_906 ) , 1 ) )
F_47 ( L_102 , V_906 ) ;
F_3 ( V_911 , F_2 ( V_911 ) |
F_382 ( V_906 ) ) ;
}
static void F_383 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
enum V_905 V_906 ;
F_368 ( V_872 -> V_893 != V_900 &&
V_872 -> V_893 != V_907 ) ;
if ( V_872 -> V_893 == V_900 ) {
V_906 = V_908 ;
F_379 ( V_4 , V_235 ) ;
F_379 ( V_4 , V_239 ) ;
} else {
V_906 = V_909 ;
F_379 ( V_4 , V_248 ) ;
}
F_3 ( V_911 , F_2 ( V_911 ) &
~ F_382 ( V_906 ) ) ;
F_358 ( V_4 , V_872 , false ) ;
}
static bool F_384 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
enum V_67 V_67 = V_872 -> V_893 ;
bool V_175 ;
T_1 V_894 , V_895 ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
V_894 = F_208 ( V_4 , V_912 ) & F_385 ( V_67 ) ;
F_158 ( V_894 != F_386 ( V_67 ) && V_894 != F_387 ( V_67 ) ) ;
V_175 = V_894 == F_386 ( V_67 ) ;
V_895 = F_208 ( V_4 , V_912 ) & F_388 ( V_67 ) ;
F_158 ( V_895 << 16 != V_894 ) ;
F_41 ( & V_4 -> V_461 . V_493 ) ;
return V_175 ;
}
static void F_389 ( struct V_3 * V_4 ,
struct V_871 * V_872 ,
bool V_149 )
{
enum V_67 V_67 = V_872 -> V_893 ;
T_1 V_894 ;
T_1 V_895 ;
V_894 = V_149 ? F_386 ( V_67 ) : F_387 ( V_67 ) ;
F_40 ( & V_4 -> V_461 . V_493 ) ;
#define F_362 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_362 )
goto V_606;
V_895 = F_208 ( V_4 , V_912 ) ;
V_895 &= ~ F_388 ( V_67 ) ;
V_895 |= V_149 ? F_390 ( V_67 ) : F_391 ( V_67 ) ;
F_207 ( V_4 , V_912 , V_895 ) ;
if ( F_4 ( F_362 , 100 ) )
F_47 ( L_101 ,
V_894 ,
F_208 ( V_4 , V_912 ) ) ;
#undef F_362
V_606:
F_41 ( & V_4 -> V_461 . V_493 ) ;
}
static void F_392 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_389 ( V_4 , V_872 , V_872 -> V_670 > 0 ) ;
}
static void F_393 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_368 ( V_872 -> V_893 != V_235 &&
V_872 -> V_893 != V_239 &&
V_872 -> V_893 != V_248 ) ;
F_389 ( V_4 , V_872 , true ) ;
}
static void F_394 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
F_368 ( V_872 -> V_893 != V_235 &&
V_872 -> V_893 != V_239 &&
V_872 -> V_893 != V_248 ) ;
F_389 ( V_4 , V_872 , false ) ;
}
static void F_395 ( struct V_3 * V_4 ,
struct V_871 * V_872 )
{
bool V_175 = V_872 -> V_913 -> V_880 ( V_4 , V_872 ) ;
if ( V_872 -> V_883 || ! V_93 . V_914 ) {
if ( ! V_175 )
goto V_915;
return;
}
if ( V_175 != ( V_872 -> V_670 > 0 ) )
goto V_915;
return;
V_915:
F_95 ( 1 , L_103 ,
V_872 -> V_340 , V_872 -> V_883 , V_175 ,
V_872 -> V_670 , V_93 . V_914 ) ;
}
void F_396 ( struct V_3 * V_4 ,
enum V_876 V_877 )
{
struct V_878 * V_879 ;
struct V_871 * V_872 ;
int V_20 ;
F_397 ( V_4 ) ;
V_879 = & V_4 -> V_879 ;
F_40 ( & V_879 -> V_885 ) ;
F_398 (i, power_well, BIT(domain), power_domains) {
if ( ! V_872 -> V_670 ++ ) {
F_5 ( L_104 , V_872 -> V_340 ) ;
V_872 -> V_913 -> V_149 ( V_4 , V_872 ) ;
V_872 -> V_884 = true ;
}
F_395 ( V_4 , V_872 ) ;
}
V_879 -> V_916 [ V_877 ] ++ ;
F_41 ( & V_879 -> V_885 ) ;
}
void F_399 ( struct V_3 * V_4 ,
enum V_876 V_877 )
{
struct V_878 * V_879 ;
struct V_871 * V_872 ;
int V_20 ;
V_879 = & V_4 -> V_879 ;
F_40 ( & V_879 -> V_885 ) ;
F_158 ( ! V_879 -> V_916 [ V_877 ] ) ;
V_879 -> V_916 [ V_877 ] -- ;
F_344 (i, power_well, BIT(domain), power_domains) {
F_158 ( ! V_872 -> V_670 ) ;
if ( ! -- V_872 -> V_670 && V_93 . V_914 ) {
F_5 ( L_105 , V_872 -> V_340 ) ;
V_872 -> V_884 = false ;
V_872 -> V_913 -> V_917 ( V_4 , V_872 ) ;
}
F_395 ( V_4 , V_872 ) ;
}
F_41 ( & V_879 -> V_885 ) ;
F_305 ( V_4 ) ;
}
int F_400 ( void )
{
struct V_3 * V_4 ;
if ( ! V_918 )
return - V_919 ;
V_4 = F_38 ( V_918 , struct V_3 ,
V_879 ) ;
F_396 ( V_4 , V_920 ) ;
return 0 ;
}
int F_401 ( void )
{
struct V_3 * V_4 ;
if ( ! V_918 )
return - V_919 ;
V_4 = F_38 ( V_918 , struct V_3 ,
V_879 ) ;
F_399 ( V_4 , V_920 ) ;
return 0 ;
}
int F_402 ( void )
{
struct V_3 * V_4 ;
if ( ! V_918 )
return - V_919 ;
V_4 = F_38 ( V_918 , struct V_3 ,
V_879 ) ;
return F_134 ( V_4 ) ;
}
static struct V_871 * F_403 ( struct V_3 * V_4 ,
enum V_891 V_892 )
{
struct V_878 * V_879 = & V_4 -> V_879 ;
struct V_871 * V_872 ;
int V_20 ;
F_398 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
if ( V_872 -> V_893 == V_892 )
return V_872 ;
}
return NULL ;
}
int F_404 ( struct V_3 * V_4 )
{
struct V_878 * V_879 = & V_4 -> V_879 ;
F_405 ( & V_879 -> V_885 ) ;
if ( F_58 ( V_4 -> V_2 ) ) {
F_406 ( V_879 , V_921 ) ;
V_918 = V_879 ;
} else if ( F_138 ( V_4 -> V_2 ) ) {
F_406 ( V_879 , V_922 ) ;
V_918 = V_879 ;
} else if ( F_210 ( V_4 -> V_2 ) ) {
F_406 ( V_879 , V_923 ) ;
} else if ( F_73 ( V_4 -> V_2 ) ) {
F_406 ( V_879 , V_924 ) ;
} else {
F_406 ( V_879 , V_925 ) ;
}
return 0 ;
}
void F_407 ( struct V_3 * V_4 )
{
V_918 = NULL ;
}
static void F_408 ( struct V_3 * V_4 )
{
struct V_878 * V_879 = & V_4 -> V_879 ;
struct V_871 * V_872 ;
int V_20 ;
F_40 ( & V_879 -> V_885 ) ;
F_398 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_872 -> V_913 -> V_926 ( V_4 , V_872 ) ;
V_872 -> V_884 = V_872 -> V_913 -> V_880 ( V_4 ,
V_872 ) ;
}
F_41 ( & V_879 -> V_885 ) ;
}
static void F_409 ( struct V_3 * V_4 )
{
struct V_871 * V_927 =
F_403 ( V_4 , V_900 ) ;
struct V_871 * V_928 =
F_403 ( V_4 , V_898 ) ;
if ( ! V_927 -> V_913 -> V_880 ( V_4 , V_927 ) )
return;
if ( V_928 -> V_913 -> V_880 ( V_4 , V_928 ) &&
F_2 ( V_903 ) & V_904 )
return;
F_5 ( L_106 ) ;
V_928 -> V_913 -> V_149 ( V_4 , V_928 ) ;
V_927 -> V_913 -> V_917 ( V_4 , V_927 ) ;
}
void F_410 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_878 * V_879 = & V_4 -> V_879 ;
V_879 -> V_899 = true ;
if ( F_73 ( V_2 ) && ! F_210 ( V_2 ) ) {
F_40 ( & V_879 -> V_885 ) ;
F_409 ( V_4 ) ;
F_41 ( & V_879 -> V_885 ) ;
}
F_411 ( V_4 , true ) ;
F_408 ( V_4 ) ;
V_879 -> V_899 = false ;
}
void F_412 ( struct V_3 * V_4 )
{
F_397 ( V_4 ) ;
}
void F_413 ( struct V_3 * V_4 )
{
F_305 ( V_4 ) ;
}
void F_397 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_498 -> V_2 ;
if ( ! F_414 ( V_2 ) )
return;
F_415 ( V_929 ) ;
F_95 ( V_4 -> V_881 . V_882 , L_107 ) ;
}
void F_308 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_498 -> V_2 ;
if ( ! F_414 ( V_2 ) )
return;
F_95 ( V_4 -> V_881 . V_882 , L_108 ) ;
F_416 ( V_929 ) ;
}
void F_305 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_498 -> V_2 ;
if ( ! F_414 ( V_2 ) )
return;
F_417 ( V_929 ) ;
F_418 ( V_929 ) ;
}
void F_419 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_498 -> V_2 ;
if ( ! F_414 ( V_2 ) )
return;
F_420 ( V_929 ) ;
if ( ! F_225 ( V_2 ) ) {
F_421 ( L_109 ) ;
return;
}
F_422 ( V_929 , 10000 ) ;
F_417 ( V_929 ) ;
F_423 ( V_929 ) ;
F_418 ( V_929 ) ;
}
void F_424 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_929 * V_929 = & V_2 -> V_498 -> V_2 ;
if ( ! F_414 ( V_2 ) )
return;
if ( ! F_225 ( V_2 ) )
return;
F_415 ( V_929 ) ;
F_425 ( V_929 ) ;
}
void F_426 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_54 ( V_2 ) ) {
if ( F_57 ( V_2 ) -> V_106 >= 7 ) {
V_4 -> V_69 . V_70 = F_29 ;
V_4 -> V_69 . V_79 = F_30 ;
V_4 -> V_69 . V_84 = F_28 ;
} else if ( F_57 ( V_2 ) -> V_106 >= 5 ) {
V_4 -> V_69 . V_70 = F_29 ;
V_4 -> V_69 . V_79 = F_24 ;
V_4 -> V_69 . V_84 = F_28 ;
} else if ( F_333 ( V_2 ) ) {
V_4 -> V_69 . V_70 = F_19 ;
V_4 -> V_69 . V_79 = F_15 ;
V_4 -> V_69 . V_84 = F_18 ;
} else {
V_4 -> V_69 . V_70 = F_14 ;
V_4 -> V_69 . V_79 = F_6 ;
V_4 -> V_69 . V_84 = F_1 ;
F_3 ( V_7 , 500 << V_34 ) ;
}
}
if ( F_75 ( V_2 ) )
F_66 ( V_2 ) ;
else if ( F_25 ( V_2 ) )
F_67 ( V_2 ) ;
if ( F_427 ( V_2 ) ) {
F_147 ( V_2 ) ;
if ( ( F_25 ( V_2 ) && V_4 -> V_165 . V_321 [ 1 ] &&
V_4 -> V_165 . V_322 [ 1 ] && V_4 -> V_165 . V_323 [ 1 ] ) ||
( ! F_25 ( V_2 ) && V_4 -> V_165 . V_321 [ 0 ] &&
V_4 -> V_165 . V_322 [ 0 ] && V_4 -> V_165 . V_323 [ 0 ] ) ) {
V_4 -> V_69 . V_405 = F_169 ;
V_4 -> V_69 . V_406 = F_170 ;
} else {
F_5 ( L_110
L_111 ) ;
}
if ( F_25 ( V_2 ) )
V_4 -> V_69 . V_870 = F_315 ;
else if ( F_27 ( V_2 ) )
V_4 -> V_69 . V_870 = F_320 ;
else if ( F_32 ( V_2 ) )
V_4 -> V_69 . V_870 = F_327 ;
else if ( F_58 ( V_2 ) )
V_4 -> V_69 . V_870 = F_326 ;
else if ( F_57 ( V_2 ) -> V_106 == 8 )
V_4 -> V_69 . V_870 = F_324 ;
} else if ( F_210 ( V_2 ) ) {
V_4 -> V_69 . V_405 = F_101 ;
V_4 -> V_69 . V_406 = F_102 ;
V_4 -> V_69 . V_870 =
F_331 ;
} else if ( F_73 ( V_2 ) ) {
V_4 -> V_69 . V_405 = F_98 ;
V_4 -> V_69 . V_406 = F_102 ;
V_4 -> V_69 . V_870 =
F_330 ;
} else if ( F_75 ( V_2 ) ) {
if ( ! F_70 ( F_87 ( V_2 ) ,
V_4 -> V_134 ,
V_4 -> V_124 ,
V_4 -> V_130 ) ) {
F_421 ( L_112
L_113
L_114 ,
( V_4 -> V_134 == 1 ) ? L_115 : L_116 ,
V_4 -> V_124 , V_4 -> V_130 ) ;
F_72 ( V_4 , false ) ;
V_4 -> V_69 . V_405 = NULL ;
} else
V_4 -> V_69 . V_405 = F_86 ;
V_4 -> V_69 . V_870 = F_336 ;
} else if ( F_59 ( V_2 ) ) {
V_4 -> V_69 . V_405 = F_106 ;
V_4 -> V_69 . V_870 = F_332 ;
} else if ( F_10 ( V_2 ) ) {
V_4 -> V_69 . V_405 = F_107 ;
if ( F_74 ( V_2 ) )
V_4 -> V_69 . V_870 = F_334 ;
else if ( F_428 ( V_2 ) )
V_4 -> V_69 . V_870 = F_335 ;
} else if ( F_429 ( V_2 ) ) {
V_4 -> V_69 . V_405 = F_108 ;
V_4 -> V_69 . V_275 = F_80 ;
V_4 -> V_69 . V_870 = F_336 ;
} else if ( F_9 ( V_2 ) ) {
if ( F_57 ( V_2 ) -> V_313 == 1 ) {
V_4 -> V_69 . V_405 = F_110 ;
V_4 -> V_69 . V_275 = F_82 ;
} else {
V_4 -> V_69 . V_405 = F_108 ;
V_4 -> V_69 . V_275 = F_81 ;
}
if ( F_430 ( V_2 ) || F_431 ( V_2 ) )
V_4 -> V_69 . V_870 = F_337 ;
else
V_4 -> V_69 . V_870 = F_338 ;
} else {
F_47 ( L_117 ) ;
}
}
int F_236 ( struct V_3 * V_4 , T_7 V_930 , T_1 * V_150 )
{
F_158 ( ! F_177 ( & V_4 -> V_461 . V_493 ) ) ;
if ( F_2 ( V_931 ) & V_932 ) {
F_69 ( L_118 ) ;
return - V_933 ;
}
F_3 ( V_934 , * V_150 ) ;
F_3 ( V_931 , V_932 | V_930 ) ;
if ( F_4 ( ( F_2 ( V_931 ) & V_932 ) == 0 ,
500 ) ) {
F_47 ( L_119 , V_930 ) ;
return - V_935 ;
}
* V_150 = F_2 ( V_934 ) ;
F_3 ( V_934 , 0 ) ;
return 0 ;
}
int F_235 ( struct V_3 * V_4 , T_7 V_930 , T_1 V_150 )
{
F_158 ( ! F_177 ( & V_4 -> V_461 . V_493 ) ) ;
if ( F_2 ( V_931 ) & V_932 ) {
F_69 ( L_120 ) ;
return - V_933 ;
}
F_3 ( V_934 , V_150 ) ;
F_3 ( V_931 , V_932 | V_930 ) ;
if ( F_4 ( ( F_2 ( V_931 ) & V_932 ) == 0 ,
500 ) ) {
F_47 ( L_121 , V_930 ) ;
return - V_935 ;
}
F_3 ( V_934 , 0 ) ;
return 0 ;
}
static int F_432 ( struct V_3 * V_4 , int V_150 )
{
int div ;
switch ( V_4 -> V_130 ) {
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
return F_133 ( V_4 -> V_130 * ( V_150 + 6 - 0xbd ) , 4 * div ) ;
}
static int F_433 ( struct V_3 * V_4 , int V_150 )
{
int V_936 ;
switch ( V_4 -> V_130 ) {
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
return F_133 ( 4 * V_936 * V_150 , V_4 -> V_130 ) + 0xbd - 6 ;
}
static int F_434 ( struct V_3 * V_4 , int V_150 )
{
int div , V_639 ;
switch ( V_4 -> V_461 . V_608 ) {
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
V_639 = ( F_133 ( ( V_4 -> V_461 . V_608 * V_150 ) , 2 * div ) / 2 ) ;
return V_639 ;
}
static int F_435 ( struct V_3 * V_4 , int V_150 )
{
int V_936 , V_937 ;
switch ( V_4 -> V_461 . V_608 ) {
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
V_937 = ( F_133 ( ( V_150 * 2 * V_936 ) , V_4 -> V_461 . V_608 ) * 2 ) ;
return V_937 ;
}
int F_213 ( struct V_3 * V_4 , int V_150 )
{
int V_291 = - 1 ;
if ( F_210 ( V_4 -> V_2 ) )
V_291 = F_434 ( V_4 , V_150 ) ;
else if ( F_73 ( V_4 -> V_2 ) )
V_291 = F_432 ( V_4 , V_150 ) ;
return V_291 ;
}
int F_436 ( struct V_3 * V_4 , int V_150 )
{
int V_291 = - 1 ;
if ( F_210 ( V_4 -> V_2 ) )
V_291 = F_435 ( V_4 , V_150 ) ;
else if ( F_73 ( V_4 -> V_2 ) )
V_291 = F_433 ( V_4 , V_150 ) ;
return V_291 ;
}
void F_437 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_405 ( & V_4 -> V_461 . V_493 ) ;
F_48 ( & V_4 -> V_461 . V_710 ,
F_304 ) ;
V_4 -> V_881 . V_882 = false ;
V_4 -> V_881 . V_938 = false ;
}
