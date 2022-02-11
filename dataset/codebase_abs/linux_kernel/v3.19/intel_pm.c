static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
F_2 ( V_8 ,
F_3 ( V_8 ) &
~ V_9 ) ;
F_2 ( V_10 ,
F_4 ( V_11 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_12 ;
V_4 -> V_13 . V_14 = false ;
V_12 = F_3 ( V_15 ) ;
if ( ( V_12 & V_16 ) == 0 )
return;
V_12 &= ~ V_16 ;
F_2 ( V_15 , V_12 ) ;
if ( F_6 ( ( F_3 ( V_17 ) & V_18 ) == 0 , 10 ) ) {
F_7 ( L_1 ) ;
return;
}
F_7 ( L_2 ) ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_22 ;
struct V_24 * V_25 = F_9 ( V_22 ) ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
int V_27 ;
int V_28 ;
T_1 V_12 ;
V_4 -> V_13 . V_14 = true ;
V_27 = V_4 -> V_13 . V_29 / V_30 ;
if ( V_22 -> V_31 [ 0 ] < V_27 )
V_27 = V_22 -> V_31 [ 0 ] ;
if ( F_11 ( V_2 ) )
V_27 = ( V_27 / 32 ) - 1 ;
else
V_27 = ( V_27 / 64 ) - 1 ;
for ( V_28 = 0 ; V_28 < ( V_30 / 32 ) + 1 ; V_28 ++ )
F_2 ( V_32 + ( V_28 * 4 ) , 0 ) ;
if ( F_12 ( V_2 ) ) {
T_1 V_33 ;
V_33 = V_34 | V_35 | V_36 ;
V_33 |= F_13 ( V_26 -> V_37 ) ;
F_2 ( V_38 , V_33 ) ;
F_2 ( V_39 , V_20 -> V_40 ) ;
}
V_12 = F_3 ( V_15 ) ;
V_12 &= 0x3fff << V_41 ;
V_12 |= V_16 | V_42 ;
if ( F_14 ( V_2 ) )
V_12 |= V_43 ;
V_12 |= ( V_27 & 0xff ) << V_44 ;
V_12 |= V_25 -> V_45 ;
F_2 ( V_15 , V_12 ) ;
F_7 ( L_3 ,
V_27 , V_20 -> V_40 , F_15 ( V_26 -> V_37 ) ) ;
}
static bool F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_15 ) & V_16 ;
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_22 ;
struct V_24 * V_25 = F_9 ( V_22 ) ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
T_1 V_46 ;
V_4 -> V_13 . V_14 = true ;
V_46 = F_18 ( V_26 -> V_37 ) | V_47 ;
if ( F_19 ( V_22 -> V_48 , 0 ) == 2 )
V_46 |= V_49 ;
else
V_46 |= V_50 ;
V_46 |= V_51 | V_25 -> V_45 ;
F_2 ( V_52 , V_20 -> V_40 ) ;
F_2 ( V_53 , V_46 | V_54 ) ;
F_7 ( L_4 , F_15 ( V_26 -> V_37 ) ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_46 ;
V_4 -> V_13 . V_14 = false ;
V_46 = F_3 ( V_53 ) ;
if ( V_46 & V_54 ) {
V_46 &= ~ V_54 ;
F_2 ( V_53 , V_46 ) ;
F_7 ( L_2 ) ;
}
}
static bool F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_53 ) & V_54 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_55 ;
F_23 ( V_4 , V_56 ) ;
V_55 = F_3 ( V_57 ) ;
V_55 |= V_58 <<
V_59 ;
F_2 ( V_57 , V_55 ) ;
V_55 |= V_58 ;
F_2 ( V_57 , V_55 ) ;
V_55 &= ~ ( V_58 <<
V_59 ) ;
F_2 ( V_57 , V_55 ) ;
F_24 ( V_57 ) ;
F_25 ( V_4 , V_56 ) ;
}
static void F_26 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_22 ;
struct V_24 * V_25 = F_9 ( V_22 ) ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
T_1 V_46 ;
V_4 -> V_13 . V_14 = true ;
V_46 = F_18 ( V_26 -> V_37 ) ;
if ( F_19 ( V_22 -> V_48 , 0 ) == 2 )
V_4 -> V_13 . V_60 ++ ;
switch ( V_4 -> V_13 . V_60 ) {
case 4 :
case 3 :
V_46 |= V_61 ;
break;
case 2 :
V_46 |= V_49 ;
break;
case 1 :
V_46 |= V_50 ;
break;
}
V_46 |= V_51 ;
if ( F_27 ( V_2 ) )
V_46 |= V_25 -> V_45 ;
F_2 ( V_62 , V_20 -> V_40 ) ;
F_2 ( V_63 , F_28 ( V_25 ) | V_64 ) ;
F_2 ( V_65 , V_46 | V_54 ) ;
if ( F_29 ( V_2 ) ) {
F_2 ( V_66 ,
V_67 | V_25 -> V_45 ) ;
F_2 ( V_68 , V_20 -> V_40 ) ;
F_22 ( V_2 ) ;
}
F_7 ( L_4 , F_15 ( V_26 -> V_37 ) ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_46 ;
V_4 -> V_13 . V_14 = false ;
V_46 = F_3 ( V_65 ) ;
if ( V_46 & V_54 ) {
V_46 &= ~ V_54 ;
F_2 ( V_65 , V_46 ) ;
F_7 ( L_2 ) ;
}
}
static bool F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_65 ) & V_54 ;
}
static void F_32 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_22 ;
struct V_24 * V_25 = F_9 ( V_22 ) ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
T_1 V_46 ;
V_4 -> V_13 . V_14 = true ;
V_46 = F_33 ( V_26 -> V_37 ) ;
if ( F_19 ( V_22 -> V_48 , 0 ) == 2 )
V_4 -> V_13 . V_60 ++ ;
switch ( V_4 -> V_13 . V_60 ) {
case 4 :
case 3 :
V_46 |= V_61 ;
break;
case 2 :
V_46 |= V_49 ;
break;
case 1 :
V_46 |= V_50 ;
break;
}
V_46 |= V_69 ;
if ( V_4 -> V_13 . V_70 )
V_46 |= V_71 ;
F_2 ( V_65 , V_46 | V_54 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( V_72 ,
F_3 ( V_72 ) |
V_73 ) ;
} else {
F_2 ( F_35 ( V_26 -> V_74 ) ,
F_3 ( F_35 ( V_26 -> V_74 ) ) |
V_75 ) ;
}
F_2 ( V_66 ,
V_67 | V_25 -> V_45 ) ;
F_2 ( V_68 , V_20 -> V_40 ) ;
F_22 ( V_2 ) ;
F_7 ( L_4 , F_15 ( V_26 -> V_37 ) ) ;
}
bool F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_13 . V_14 ;
}
void F_37 ( struct V_1 * V_2 , T_1 V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_38 ( V_2 ) )
return;
if ( ! F_36 ( V_2 ) )
return;
F_2 ( V_77 , V_76 ) ;
}
static void F_39 ( struct V_78 * V_79 )
{
struct V_80 * V_81 =
F_40 ( F_41 ( V_79 ) ,
struct V_80 , V_81 ) ;
struct V_1 * V_2 = V_81 -> V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_42 ( & V_2 -> V_82 ) ;
if ( V_81 == V_4 -> V_13 . V_83 ) {
if ( V_81 -> V_20 -> V_23 -> V_22 == V_81 -> V_22 ) {
V_4 -> V_84 . V_85 ( V_81 -> V_20 ) ;
V_4 -> V_13 . V_37 = F_10 ( V_81 -> V_20 ) -> V_37 ;
V_4 -> V_13 . V_86 = V_81 -> V_20 -> V_23 -> V_22 -> V_87 . V_88 ;
V_4 -> V_13 . V_40 = V_81 -> V_20 -> V_40 ;
}
V_4 -> V_13 . V_83 = NULL ;
}
F_43 ( & V_2 -> V_82 ) ;
F_44 ( V_81 ) ;
}
static void F_45 ( struct V_3 * V_4 )
{
if ( V_4 -> V_13 . V_83 == NULL )
return;
F_7 ( L_5 ) ;
if ( F_46 ( & V_4 -> V_13 . V_83 -> V_81 ) )
F_44 ( V_4 -> V_13 . V_83 ) ;
V_4 -> V_13 . V_83 = NULL ;
}
static void F_47 ( struct V_19 * V_20 )
{
struct V_80 * V_81 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_84 . V_85 )
return;
F_45 ( V_4 ) ;
V_81 = F_48 ( sizeof( * V_81 ) , V_89 ) ;
if ( V_81 == NULL ) {
F_49 ( L_6 ) ;
V_4 -> V_84 . V_85 ( V_20 ) ;
return;
}
V_81 -> V_20 = V_20 ;
V_81 -> V_22 = V_20 -> V_23 -> V_22 ;
F_50 ( & V_81 -> V_81 , F_39 ) ;
V_4 -> V_13 . V_83 = V_81 ;
F_51 ( & V_81 -> V_81 , F_52 ( 50 ) ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_45 ( V_4 ) ;
if ( ! V_4 -> V_84 . V_90 )
return;
V_4 -> V_84 . V_90 ( V_2 ) ;
V_4 -> V_13 . V_37 = - 1 ;
}
static bool F_54 ( struct V_3 * V_4 ,
enum V_91 V_92 )
{
if ( V_4 -> V_13 . V_91 == V_92 )
return false ;
V_4 -> V_13 . V_91 = V_92 ;
return true ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_20 = NULL , * V_93 ;
struct V_26 * V_26 ;
struct V_21 * V_22 ;
struct V_24 * V_25 ;
const struct V_94 * V_95 ;
unsigned int V_96 , V_97 ;
if ( ! F_56 ( V_2 ) ) {
F_54 ( V_4 , V_98 ) ;
return;
}
if ( ! V_99 . V_100 ) {
if ( F_54 ( V_4 , V_101 ) )
F_7 ( L_7 ) ;
return;
}
F_57 (dev, tmp_crtc) {
if ( F_58 ( V_93 ) &&
F_10 ( V_93 ) -> V_102 ) {
if ( V_20 ) {
if ( F_54 ( V_4 , V_103 ) )
F_7 ( L_8 ) ;
goto V_104;
}
V_20 = V_93 ;
}
}
if ( ! V_20 || V_20 -> V_23 -> V_22 == NULL ) {
if ( F_54 ( V_4 , V_105 ) )
F_7 ( L_9 ) ;
goto V_104;
}
V_26 = F_10 ( V_20 ) ;
V_22 = V_20 -> V_23 -> V_22 ;
V_25 = F_9 ( V_22 ) ;
V_95 = & V_26 -> V_106 . V_95 ;
if ( V_99 . V_85 < 0 ) {
if ( F_54 ( V_4 , V_107 ) )
F_7 ( L_10 ) ;
goto V_104;
}
if ( ! V_99 . V_85 ) {
if ( F_54 ( V_4 , V_101 ) )
F_7 ( L_7 ) ;
goto V_104;
}
if ( ( V_95 -> V_108 & V_109 ) ||
( V_95 -> V_108 & V_110 ) ) {
if ( F_54 ( V_4 , V_111 ) )
F_7 ( L_11
L_12 ) ;
goto V_104;
}
if ( F_59 ( V_2 ) -> V_112 >= 8 || F_60 ( V_2 ) ) {
V_96 = 4096 ;
V_97 = 4096 ;
} else if ( F_61 ( V_2 ) || F_59 ( V_2 ) -> V_112 >= 5 ) {
V_96 = 4096 ;
V_97 = 2048 ;
} else {
V_96 = 2048 ;
V_97 = 1536 ;
}
if ( V_26 -> V_106 . V_113 > V_96 ||
V_26 -> V_106 . V_114 > V_97 ) {
if ( F_54 ( V_4 , V_115 ) )
F_7 ( L_13 ) ;
goto V_104;
}
if ( ( F_59 ( V_2 ) -> V_112 < 4 || F_62 ( V_2 ) ) &&
V_26 -> V_37 != V_116 ) {
if ( F_54 ( V_4 , V_117 ) )
F_7 ( L_14 ) ;
goto V_104;
}
if ( V_25 -> V_118 != V_119 ||
V_25 -> V_45 == V_120 ) {
if ( F_54 ( V_4 , V_121 ) )
F_7 ( L_15 ) ;
goto V_104;
}
if ( F_59 ( V_2 ) -> V_112 <= 4 && ! F_61 ( V_2 ) &&
F_63 ( V_20 -> V_23 ) -> V_122 != F_64 ( V_123 ) ) {
if ( F_54 ( V_4 , V_111 ) )
F_7 ( L_16 ) ;
goto V_104;
}
if ( F_65 () )
goto V_104;
if ( F_66 ( V_2 , V_25 -> V_87 . V_29 ,
F_19 ( V_22 -> V_48 , 0 ) ) ) {
if ( F_54 ( V_4 , V_124 ) )
F_7 ( L_17 ) ;
goto V_104;
}
if ( V_4 -> V_13 . V_37 == V_26 -> V_37 &&
V_4 -> V_13 . V_86 == V_22 -> V_87 . V_88 &&
V_4 -> V_13 . V_40 == V_20 -> V_40 )
return;
if ( F_36 ( V_2 ) ) {
F_7 ( L_18 ) ;
F_53 ( V_2 ) ;
}
F_47 ( V_20 ) ;
V_4 -> V_13 . V_91 = V_125 ;
return;
V_104:
if ( F_36 ( V_2 ) ) {
F_7 ( L_19 ) ;
F_53 ( V_2 ) ;
}
F_67 ( V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_126 ;
V_126 = F_3 ( V_127 ) ;
switch ( V_126 & V_128 ) {
case V_129 :
V_4 -> V_130 = 533 ;
break;
case V_131 :
V_4 -> V_130 = 800 ;
break;
case V_132 :
V_4 -> V_130 = 667 ;
break;
case V_133 :
V_4 -> V_130 = 400 ;
break;
}
switch ( V_126 & V_134 ) {
case V_135 :
V_4 -> V_136 = 533 ;
break;
case V_137 :
V_4 -> V_136 = 667 ;
break;
case V_138 :
V_4 -> V_136 = 800 ;
break;
}
V_126 = F_3 ( V_139 ) ;
V_4 -> V_140 = ( V_126 & V_141 ) ? 1 : 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_142 , V_143 ;
V_142 = F_70 ( V_144 ) ;
V_143 = F_70 ( V_145 ) ;
switch ( V_142 & 0xff ) {
case 0xc :
V_4 -> V_136 = 800 ;
break;
case 0x10 :
V_4 -> V_136 = 1066 ;
break;
case 0x14 :
V_4 -> V_136 = 1333 ;
break;
case 0x18 :
V_4 -> V_136 = 1600 ;
break;
default:
F_71 ( L_20 ,
V_142 & 0xff ) ;
V_4 -> V_136 = 0 ;
break;
}
V_4 -> V_146 . V_147 = V_4 -> V_136 ;
switch ( V_143 & 0x3ff ) {
case 0x00c :
V_4 -> V_130 = 3200 ;
break;
case 0x00e :
V_4 -> V_130 = 3733 ;
break;
case 0x010 :
V_4 -> V_130 = 4266 ;
break;
case 0x012 :
V_4 -> V_130 = 4800 ;
break;
case 0x014 :
V_4 -> V_130 = 5333 ;
break;
case 0x016 :
V_4 -> V_130 = 5866 ;
break;
case 0x018 :
V_4 -> V_130 = 6400 ;
break;
default:
F_71 ( L_21 ,
V_143 & 0x3ff ) ;
V_4 -> V_130 = 0 ;
break;
}
if ( V_4 -> V_130 == 3200 ) {
V_4 -> V_146 . V_148 = 0 ;
} else if ( V_4 -> V_130 > 3200 && V_4 -> V_130 <= 4800 ) {
V_4 -> V_146 . V_148 = 1 ;
} else {
V_4 -> V_146 . V_148 = 2 ;
}
}
static const struct V_149 * F_72 ( int V_150 ,
int V_140 ,
int V_151 ,
int V_152 )
{
const struct V_149 * V_153 ;
int V_28 ;
if ( V_151 == 0 || V_152 == 0 )
return NULL ;
for ( V_28 = 0 ; V_28 < F_73 ( V_154 ) ; V_28 ++ ) {
V_153 = & V_154 [ V_28 ] ;
if ( V_150 == V_153 -> V_150 &&
V_140 == V_153 -> V_140 &&
V_151 == V_153 -> V_130 && V_152 == V_153 -> V_136 )
return V_153 ;
}
F_7 ( L_22 ) ;
return NULL ;
}
void F_74 ( struct V_3 * V_4 , bool V_155 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_156 ;
if ( F_75 ( V_2 ) ) {
F_2 ( V_157 , V_155 ? V_158 : 0 ) ;
} else if ( F_61 ( V_2 ) || F_76 ( V_2 ) ) {
F_2 ( V_159 , V_155 ? V_160 : 0 ) ;
} else if ( F_77 ( V_2 ) ) {
V_156 = F_3 ( V_161 ) & ~ V_162 ;
V_156 |= V_155 ? V_162 : 0 ;
F_2 ( V_161 , V_156 ) ;
} else if ( F_78 ( V_2 ) || F_14 ( V_2 ) ) {
V_156 = V_155 ? F_4 ( V_160 ) :
F_79 ( V_160 ) ;
F_2 ( V_159 , V_156 ) ;
} else if ( F_80 ( V_2 ) ) {
V_156 = V_155 ? F_4 ( V_163 ) :
F_79 ( V_163 ) ;
F_2 ( V_164 , V_156 ) ;
} else {
return;
}
F_7 ( L_23 ,
V_155 ? L_24 : L_25 ) ;
}
static int F_81 ( struct V_1 * V_2 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_165 = F_3 ( V_166 ) ;
int V_29 ;
V_29 = V_165 & 0x7f ;
if ( V_37 )
V_29 = ( ( V_165 >> V_167 ) & 0x7f ) - V_29 ;
F_7 ( L_26 , V_165 ,
V_37 ? L_27 : L_28 , V_29 ) ;
return V_29 ;
}
static int F_82 ( struct V_1 * V_2 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_165 = F_3 ( V_166 ) ;
int V_29 ;
V_29 = V_165 & 0x1ff ;
if ( V_37 )
V_29 = ( ( V_165 >> V_168 ) & 0x1ff ) - V_29 ;
V_29 >>= 1 ;
F_7 ( L_26 , V_165 ,
V_37 ? L_27 : L_28 , V_29 ) ;
return V_29 ;
}
static int F_83 ( struct V_1 * V_2 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_165 = F_3 ( V_166 ) ;
int V_29 ;
V_29 = V_165 & 0x7f ;
V_29 >>= 2 ;
F_7 ( L_26 , V_165 ,
V_37 ? L_27 : L_28 ,
V_29 ) ;
return V_29 ;
}
static unsigned long F_84 ( unsigned long V_169 ,
const struct V_170 * V_171 ,
int V_172 ,
int V_173 ,
unsigned long V_174 )
{
long V_175 , V_176 ;
V_175 = ( ( V_169 / 1000 ) * V_173 * V_174 ) /
1000 ;
V_175 = F_85 ( V_175 , V_171 -> V_177 ) ;
F_7 ( L_29 , V_175 ) ;
V_176 = V_172 - ( V_175 + V_171 -> V_178 ) ;
F_7 ( L_30 , V_176 ) ;
if ( V_176 > ( long ) V_171 -> V_179 )
V_176 = V_171 -> V_179 ;
if ( V_176 <= 0 )
V_176 = V_171 -> V_180 ;
if ( V_176 <= 8 )
V_176 = 8 ;
return V_176 ;
}
static struct V_19 * F_86 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_14 = NULL ;
F_57 (dev, crtc) {
if ( F_58 ( V_20 ) ) {
if ( V_14 )
return NULL ;
V_14 = V_20 ;
}
}
return V_14 ;
}
static void F_87 ( struct V_19 * V_181 )
{
struct V_1 * V_2 = V_181 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_20 ;
const struct V_149 * V_153 ;
T_1 V_182 ;
unsigned long V_171 ;
V_153 = F_72 ( F_88 ( V_2 ) , V_4 -> V_140 ,
V_4 -> V_130 , V_4 -> V_136 ) ;
if ( ! V_153 ) {
F_7 ( L_22 ) ;
F_74 ( V_4 , false ) ;
return;
}
V_20 = F_86 ( V_2 ) ;
if ( V_20 ) {
const struct V_94 * V_95 ;
int V_173 = V_20 -> V_23 -> V_22 -> V_183 / 8 ;
int clock ;
V_95 = & F_10 ( V_20 ) -> V_106 . V_95 ;
clock = V_95 -> V_184 ;
V_171 = F_84 ( clock , & V_185 ,
V_185 . V_172 ,
V_173 , V_153 -> V_186 ) ;
V_182 = F_3 ( V_187 ) ;
V_182 &= ~ V_188 ;
V_182 |= V_171 << V_189 ;
F_2 ( V_187 , V_182 ) ;
F_7 ( L_31 , V_182 ) ;
V_171 = F_84 ( clock , & V_190 ,
V_185 . V_172 ,
V_173 , V_153 -> V_191 ) ;
V_182 = F_3 ( V_161 ) ;
V_182 &= ~ V_192 ;
V_182 |= ( V_171 & 0x3f ) << V_193 ;
F_2 ( V_161 , V_182 ) ;
V_171 = F_84 ( clock , & V_194 ,
V_194 . V_172 ,
V_173 , V_153 -> V_195 ) ;
V_182 = F_3 ( V_161 ) ;
V_182 &= ~ V_196 ;
V_182 |= V_171 & V_196 ;
F_2 ( V_161 , V_182 ) ;
V_171 = F_84 ( clock , & V_197 ,
V_194 . V_172 ,
V_173 , V_153 -> V_198 ) ;
V_182 = F_3 ( V_161 ) ;
V_182 &= ~ V_199 ;
V_182 |= ( V_171 & 0x3f ) << V_200 ;
F_2 ( V_161 , V_182 ) ;
F_7 ( L_32 , V_182 ) ;
F_74 ( V_4 , true ) ;
} else {
F_74 ( V_4 , false ) ;
}
}
static bool F_89 ( struct V_1 * V_2 ,
int V_37 ,
const struct V_170 * V_84 ,
int V_201 ,
const struct V_170 * V_202 ,
int V_203 ,
int * V_204 ,
int * V_205 )
{
struct V_19 * V_20 ;
const struct V_94 * V_95 ;
int V_206 , V_207 , clock , V_173 ;
int V_208 , V_209 ;
int V_210 , V_211 ;
V_20 = F_90 ( V_2 , V_37 ) ;
if ( ! F_58 ( V_20 ) ) {
* V_205 = V_202 -> V_178 ;
* V_204 = V_84 -> V_178 ;
return false ;
}
V_95 = & F_10 ( V_20 ) -> V_106 . V_95 ;
clock = V_95 -> V_184 ;
V_206 = V_95 -> V_212 ;
V_207 = F_10 ( V_20 ) -> V_106 . V_113 ;
V_173 = V_20 -> V_23 -> V_22 -> V_183 / 8 ;
V_210 = ( ( clock * V_173 / 1000 ) * V_201 ) / 1000 ;
V_211 = V_84 -> V_172 * V_84 -> V_177 - V_207 * 8 ;
if ( V_211 > 0 )
V_210 += V_211 ;
V_210 = F_85 ( V_210 , V_84 -> V_177 ) ;
* V_204 = V_210 + V_84 -> V_178 ;
if ( * V_204 > ( int ) V_84 -> V_179 )
* V_204 = V_84 -> V_179 ;
V_208 = F_91 ( V_206 * 1000 / clock , 1 ) ;
V_209 = ( V_203 / V_208 + 1000 ) / 1000 ;
V_210 = V_209 * F_10 ( V_20 ) -> V_213 * V_173 ;
V_211 = V_202 -> V_172 * V_202 -> V_177 - V_207 * 8 ;
if ( V_211 > 0 )
V_210 += V_211 ;
V_210 = F_85 ( V_210 , V_202 -> V_177 ) ;
* V_205 = V_210 + V_202 -> V_178 ;
if ( * V_205 > ( int ) V_202 -> V_179 )
* V_205 = ( int ) V_202 -> V_179 ;
return true ;
}
static bool F_92 ( struct V_1 * V_2 ,
int V_214 , int V_205 ,
const struct V_170 * V_84 ,
const struct V_170 * V_202 )
{
F_7 ( L_33 ,
V_214 , V_205 ) ;
if ( V_214 > V_84 -> V_179 ) {
F_7 ( L_34 ,
V_214 , V_84 -> V_179 ) ;
return false ;
}
if ( V_205 > V_202 -> V_179 ) {
F_7 ( L_35 ,
V_205 , V_202 -> V_179 ) ;
return false ;
}
if ( ! ( V_214 || V_205 ) ) {
F_7 ( L_36 ) ;
return false ;
}
return true ;
}
static bool F_93 ( struct V_1 * V_2 ,
int V_37 ,
int V_174 ,
const struct V_170 * V_84 ,
const struct V_170 * V_202 ,
int * V_214 , int * V_205 )
{
struct V_19 * V_20 ;
const struct V_94 * V_95 ;
int V_207 , V_206 , V_173 , clock ;
unsigned long V_208 ;
int V_209 , V_215 ;
int V_216 , V_217 ;
int V_210 ;
if ( ! V_174 ) {
* V_214 = * V_205 = 0 ;
return false ;
}
V_20 = F_90 ( V_2 , V_37 ) ;
V_95 = & F_10 ( V_20 ) -> V_106 . V_95 ;
clock = V_95 -> V_184 ;
V_206 = V_95 -> V_212 ;
V_207 = F_10 ( V_20 ) -> V_106 . V_113 ;
V_173 = V_20 -> V_23 -> V_22 -> V_183 / 8 ;
V_208 = F_91 ( V_206 * 1000 / clock , 1 ) ;
V_209 = ( V_174 / V_208 + 1000 ) / 1000 ;
V_215 = V_207 * V_173 ;
V_216 = ( ( clock * V_173 / 1000 ) * V_174 ) / 1000 ;
V_217 = V_209 * V_215 ;
V_210 = F_85 ( F_94 ( V_216 , V_217 ) , V_84 -> V_177 ) ;
* V_214 = V_210 + V_84 -> V_178 ;
V_210 = V_209 * V_173 * F_10 ( V_20 ) -> V_213 ;
V_210 = F_85 ( V_210 , V_202 -> V_177 ) ;
* V_205 = V_210 + V_202 -> V_178 ;
return F_92 ( V_2 ,
* V_214 , * V_205 ,
V_84 , V_202 ) ;
}
static bool F_95 ( struct V_19 * V_20 ,
int V_173 ,
int * V_218 ,
int * V_219 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_210 ;
int clock = F_10 ( V_20 ) -> V_106 . V_95 . V_184 ;
if ( F_96 ( clock == 0 , L_37 ) )
return false ;
if ( F_96 ( V_173 == 0 , L_38 ) )
return false ;
V_210 = F_85 ( clock , 1000 ) * V_173 ;
if ( F_97 ( V_2 ) )
* V_218 = ( V_210 > 128 ) ? V_220 :
V_221 ;
else
* V_218 = ( V_210 > 128 ) ? V_222 :
V_220 ;
* V_219 = ( 64 * ( * V_218 ) * 4 ) / V_210 ;
if ( * V_219 > V_223 )
* V_219 = V_223 ;
return true ;
}
static void F_98 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
int V_173 ;
int V_219 ;
enum V_74 V_74 = V_26 -> V_74 ;
int V_224 , V_218 , V_225 ;
const int V_226 = F_97 ( V_2 ) ?
V_220 : V_222 ;
V_225 = F_3 ( F_99 ( V_74 ) ) & ~ ( V_227 |
V_223 | V_228 |
( V_223 << V_229 ) ) ;
if ( ! F_58 ( V_20 ) ) {
F_2 ( F_99 ( V_74 ) , V_225 ) ;
return;
}
V_173 = V_20 -> V_23 -> V_22 -> V_183 / 8 ;
if ( F_95 ( V_20 , V_173 , & V_218 , & V_219 ) ) {
V_224 = ( V_218 == V_226 ) ?
V_227 :
V_230 ;
V_225 |= V_224 | V_219 ;
}
V_173 = 4 ;
if ( V_26 -> V_231 &&
F_95 ( V_20 , V_173 , & V_218 , & V_219 ) ) {
V_224 = ( V_218 == V_226 ) ?
V_228 :
V_232 ;
V_225 |= V_224 | ( V_219 << V_229 ) ;
}
F_2 ( F_99 ( V_74 ) , V_225 ) ;
}
static void F_100 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
static const int V_233 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_234 , V_235 , V_236 , V_237 ;
int V_238 , V_191 ;
int V_239 , V_240 ;
unsigned int V_14 = 0 ;
bool V_241 ;
F_98 ( V_20 ) ;
if ( F_89 ( V_2 , V_242 ,
& V_243 , V_244 ,
& V_245 , V_244 ,
& V_234 , & V_236 ) )
V_14 |= 1 << V_242 ;
if ( F_89 ( V_2 , V_246 ,
& V_243 , V_244 ,
& V_245 , V_244 ,
& V_235 , & V_237 ) )
V_14 |= 1 << V_246 ;
if ( F_101 ( V_14 ) &&
F_93 ( V_2 , F_102 ( V_14 ) - 1 ,
V_233 ,
& V_243 ,
& V_245 ,
& V_238 , & V_240 ) &&
F_93 ( V_2 , F_102 ( V_14 ) - 1 ,
2 * V_233 ,
& V_243 ,
& V_245 ,
& V_239 , & V_191 ) ) {
V_241 = true ;
} else {
V_241 = false ;
F_74 ( V_4 , false ) ;
V_238 = V_191 = 0 ;
}
F_7 ( L_39
L_40 ,
V_234 , V_236 ,
V_235 , V_237 ,
V_238 , V_191 ) ;
F_2 ( V_187 ,
( V_238 << V_189 ) |
( V_237 << V_247 ) |
( V_235 << V_248 ) |
( V_234 << V_249 ) ) ;
F_2 ( V_250 ,
( F_3 ( V_250 ) & ~ V_251 ) |
( V_236 << V_252 ) ) ;
F_2 ( V_161 ,
( F_3 ( V_161 ) & ~ V_192 ) |
( V_191 << V_193 ) ) ;
if ( V_241 )
F_74 ( V_4 , true ) ;
}
static void F_103 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
static const int V_233 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_234 , V_235 , V_253 ;
int V_236 , V_237 , V_254 ;
int V_238 , V_191 ;
int V_239 , V_240 ;
unsigned int V_14 = 0 ;
bool V_241 ;
F_98 ( V_20 ) ;
if ( F_89 ( V_2 , V_242 ,
& V_243 , V_244 ,
& V_245 , V_244 ,
& V_234 , & V_236 ) )
V_14 |= 1 << V_242 ;
if ( F_89 ( V_2 , V_246 ,
& V_243 , V_244 ,
& V_245 , V_244 ,
& V_235 , & V_237 ) )
V_14 |= 1 << V_246 ;
if ( F_89 ( V_2 , V_255 ,
& V_243 , V_244 ,
& V_245 , V_244 ,
& V_253 , & V_254 ) )
V_14 |= 1 << V_255 ;
if ( F_101 ( V_14 ) &&
F_93 ( V_2 , F_102 ( V_14 ) - 1 ,
V_233 ,
& V_243 ,
& V_245 ,
& V_238 , & V_240 ) &&
F_93 ( V_2 , F_102 ( V_14 ) - 1 ,
2 * V_233 ,
& V_243 ,
& V_245 ,
& V_239 , & V_191 ) ) {
V_241 = true ;
} else {
V_241 = false ;
F_74 ( V_4 , false ) ;
V_238 = V_191 = 0 ;
}
F_7 ( L_39
L_41
L_42 ,
V_234 , V_236 ,
V_235 , V_237 ,
V_253 , V_254 ,
V_238 , V_191 ) ;
F_2 ( V_187 ,
( V_238 << V_189 ) |
( V_237 << V_247 ) |
( V_235 << V_248 ) |
( V_234 << V_249 ) ) ;
F_2 ( V_250 ,
( F_3 ( V_250 ) & ~ V_251 ) |
( V_236 << V_252 ) ) ;
F_2 ( V_161 ,
( F_3 ( V_161 ) & ~ V_192 ) |
( V_191 << V_193 ) ) ;
F_2 ( V_256 ,
( F_3 ( V_256 ) & ~ ( V_257 |
V_258 ) ) |
( V_253 << V_259 ) |
( V_254 << V_260 ) ) ;
if ( V_241 )
F_74 ( V_4 , true ) ;
}
static void F_104 ( struct V_261 * V_37 ,
struct V_19 * V_20 ,
T_3 V_262 ,
T_3 V_263 ,
int V_173 ,
bool V_14 , bool V_264 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_74 = F_63 ( V_37 ) -> V_74 ;
int V_265 = F_63 ( V_37 ) -> V_37 ;
int V_219 ;
int V_224 ;
int V_266 ;
int V_218 ;
const int V_226 = F_97 ( V_2 ) ?
V_220 : V_222 ;
V_266 = F_3 ( F_99 ( V_74 ) ) & ~ ( F_105 ( V_265 ) |
( V_223 << F_106 ( V_265 ) ) ) ;
if ( V_14 && F_95 ( V_20 , V_173 , & V_218 ,
& V_219 ) ) {
V_224 = ( V_218 == V_226 ) ?
F_105 ( V_265 ) :
F_107 ( V_265 ) ;
V_266 |= V_224 |
( V_219 << F_106 ( V_265 ) ) ;
}
F_2 ( F_99 ( V_74 ) , V_266 ) ;
}
static void F_108 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
static const int V_233 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_234 , V_235 , V_236 , V_237 ;
int V_238 , V_191 ;
unsigned int V_14 = 0 ;
bool V_241 ;
if ( F_89 ( V_2 , V_242 ,
& V_267 , V_244 ,
& V_268 , V_244 ,
& V_234 , & V_236 ) )
V_14 |= 1 << V_242 ;
if ( F_89 ( V_2 , V_246 ,
& V_267 , V_244 ,
& V_268 , V_244 ,
& V_235 , & V_237 ) )
V_14 |= 1 << V_246 ;
if ( F_101 ( V_14 ) &&
F_93 ( V_2 , F_102 ( V_14 ) - 1 ,
V_233 ,
& V_267 ,
& V_268 ,
& V_238 , & V_191 ) ) {
V_241 = true ;
} else {
V_241 = false ;
F_74 ( V_4 , false ) ;
V_238 = V_191 = 0 ;
}
F_7 ( L_39
L_40 ,
V_234 , V_236 ,
V_235 , V_237 ,
V_238 , V_191 ) ;
F_2 ( V_187 ,
( V_238 << V_189 ) |
( V_237 << V_247 ) |
( V_235 << V_248 ) |
( V_234 << V_249 ) ) ;
F_2 ( V_250 ,
( F_3 ( V_250 ) & ~ V_251 ) |
( V_236 << V_252 ) ) ;
F_2 ( V_161 ,
( F_3 ( V_161 ) & ~ ( V_269 | V_192 ) ) |
( V_191 << V_193 ) ) ;
if ( V_241 )
F_74 ( V_4 , true ) ;
}
static void F_109 ( struct V_19 * V_181 )
{
struct V_1 * V_2 = V_181 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_20 ;
int V_270 = 1 ;
int V_191 = 16 ;
bool V_241 ;
V_20 = F_86 ( V_2 ) ;
if ( V_20 ) {
static const int V_233 = 12000 ;
const struct V_94 * V_95 =
& F_10 ( V_20 ) -> V_106 . V_95 ;
int clock = V_95 -> V_184 ;
int V_206 = V_95 -> V_212 ;
int V_207 = F_10 ( V_20 ) -> V_106 . V_113 ;
int V_173 = V_20 -> V_23 -> V_22 -> V_183 / 8 ;
unsigned long V_208 ;
int V_210 ;
V_208 = F_91 ( V_206 * 1000 / clock , 1 ) ;
V_210 = ( ( ( V_233 / V_208 ) + 1000 ) / 1000 ) *
V_173 * V_207 ;
V_210 = F_85 ( V_210 , V_271 ) ;
V_270 = V_272 - V_210 ;
if ( V_270 < 0 )
V_270 = 1 ;
V_270 &= 0x1ff ;
F_7 ( L_43 ,
V_210 , V_270 ) ;
V_210 = ( ( ( V_233 / V_208 ) + 1000 ) / 1000 ) *
V_173 * F_10 ( V_20 ) -> V_213 ;
V_210 = F_85 ( V_210 ,
V_273 . V_177 ) ;
V_191 = V_273 . V_172 -
( V_210 + V_273 . V_178 ) ;
if ( V_191 > V_273 . V_179 )
V_191 = V_273 . V_179 ;
F_7 ( L_44
L_45 , V_270 , V_191 ) ;
V_241 = true ;
} else {
V_241 = false ;
F_74 ( V_4 , false ) ;
}
F_7 ( L_46 ,
V_270 ) ;
F_2 ( V_187 , ( V_270 << V_189 ) |
( 8 << V_247 ) |
( 8 << V_248 ) |
( 8 << V_249 ) ) ;
F_2 ( V_250 , ( 8 << V_252 ) |
( 8 << V_274 ) ) ;
F_2 ( V_161 , ( V_191 << V_193 ) ) ;
if ( V_241 )
F_74 ( V_4 , true ) ;
}
static void F_110 ( struct V_19 * V_181 )
{
struct V_1 * V_2 = V_181 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_170 * V_275 ;
T_3 V_276 ;
T_3 V_277 ;
int V_278 , V_270 = 1 ;
int V_172 ;
int V_234 , V_235 ;
struct V_19 * V_20 , * V_14 = NULL ;
if ( F_14 ( V_2 ) )
V_275 = & V_279 ;
else if ( ! F_11 ( V_2 ) )
V_275 = & V_280 ;
else
V_275 = & V_281 ;
V_172 = V_4 -> V_84 . V_282 ( V_2 , 0 ) ;
V_20 = F_90 ( V_2 , 0 ) ;
if ( F_58 ( V_20 ) ) {
const struct V_94 * V_95 ;
int V_283 = V_20 -> V_23 -> V_22 -> V_183 / 8 ;
if ( F_11 ( V_2 ) )
V_283 = 4 ;
V_95 = & F_10 ( V_20 ) -> V_106 . V_95 ;
V_234 = F_84 ( V_95 -> V_184 ,
V_275 , V_172 , V_283 ,
V_244 ) ;
V_14 = V_20 ;
} else {
V_234 = V_172 - V_275 -> V_178 ;
if ( V_234 > ( long ) V_275 -> V_179 )
V_234 = V_275 -> V_179 ;
}
if ( F_11 ( V_2 ) )
V_275 = & V_284 ;
V_172 = V_4 -> V_84 . V_282 ( V_2 , 1 ) ;
V_20 = F_90 ( V_2 , 1 ) ;
if ( F_58 ( V_20 ) ) {
const struct V_94 * V_95 ;
int V_283 = V_20 -> V_23 -> V_22 -> V_183 / 8 ;
if ( F_11 ( V_2 ) )
V_283 = 4 ;
V_95 = & F_10 ( V_20 ) -> V_106 . V_95 ;
V_235 = F_84 ( V_95 -> V_184 ,
V_275 , V_172 , V_283 ,
V_244 ) ;
if ( V_14 == NULL )
V_14 = V_20 ;
else
V_14 = NULL ;
} else {
V_235 = V_172 - V_275 -> V_178 ;
if ( V_235 > ( long ) V_275 -> V_179 )
V_235 = V_275 -> V_179 ;
}
F_7 ( L_47 , V_234 , V_235 ) ;
if ( F_80 ( V_2 ) && V_14 ) {
struct V_24 * V_25 ;
V_25 = F_9 ( V_14 -> V_23 -> V_22 ) ;
if ( V_25 -> V_118 == V_285 )
V_14 = NULL ;
}
V_278 = 2 ;
F_74 ( V_4 , false ) ;
if ( F_111 ( V_2 ) && V_14 ) {
static const int V_233 = 6000 ;
const struct V_94 * V_95 =
& F_10 ( V_14 ) -> V_106 . V_95 ;
int clock = V_95 -> V_184 ;
int V_206 = V_95 -> V_212 ;
int V_207 = F_10 ( V_14 ) -> V_106 . V_113 ;
int V_173 = V_14 -> V_23 -> V_22 -> V_183 / 8 ;
unsigned long V_208 ;
int V_210 ;
V_208 = F_91 ( V_206 * 1000 / clock , 1 ) ;
V_210 = ( ( ( V_233 / V_208 ) + 1000 ) / 1000 ) *
V_173 * V_207 ;
V_210 = F_85 ( V_210 , V_275 -> V_177 ) ;
F_7 ( L_48 , V_210 ) ;
V_270 = V_275 -> V_172 - V_210 ;
if ( V_270 < 0 )
V_270 = 1 ;
if ( F_78 ( V_2 ) || F_14 ( V_2 ) )
F_2 ( V_159 ,
V_286 | ( V_270 & 0xff ) ) ;
else if ( F_80 ( V_2 ) )
F_2 ( V_159 , V_270 & 0x3f ) ;
}
F_7 ( L_49 ,
V_234 , V_235 , V_278 , V_270 ) ;
V_276 = ( ( V_235 & 0x3f ) << 16 ) | ( V_234 & 0x3f ) ;
V_277 = ( V_278 & 0x1f ) ;
V_276 = V_276 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_277 = V_277 | ( 1 << 8 ) ;
F_2 ( V_287 , V_276 ) ;
F_2 ( V_288 , V_277 ) ;
if ( V_14 )
F_74 ( V_4 , true ) ;
}
static void F_112 ( struct V_19 * V_181 )
{
struct V_1 * V_2 = V_181 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_20 ;
const struct V_94 * V_95 ;
T_3 V_276 ;
int V_234 ;
V_20 = F_86 ( V_2 ) ;
if ( V_20 == NULL )
return;
V_95 = & F_10 ( V_20 ) -> V_106 . V_95 ;
V_234 = F_84 ( V_95 -> V_184 ,
& V_289 ,
V_4 -> V_84 . V_282 ( V_2 , 0 ) ,
4 , V_244 ) ;
V_276 = F_3 ( V_287 ) & ~ 0xfff ;
V_276 |= ( 3 << 8 ) | V_234 ;
F_7 ( L_50 , V_234 ) ;
F_2 ( V_287 , V_276 ) ;
}
static T_3 F_113 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_26 * V_26 = F_10 ( V_20 ) ;
T_3 V_290 ;
V_290 = V_26 -> V_106 . V_95 . V_184 ;
if ( V_26 -> V_106 . V_291 . V_14 ) {
T_4 V_292 , V_293 , V_294 , V_295 ;
T_3 V_296 = V_26 -> V_106 . V_291 . V_29 ;
V_292 = V_26 -> V_106 . V_113 ;
V_293 = V_26 -> V_106 . V_114 ;
V_294 = ( V_296 >> 16 ) & 0xFFFF ;
V_295 = V_296 & 0xFFFF ;
if ( V_292 < V_294 )
V_292 = V_294 ;
if ( V_293 < V_295 )
V_293 = V_295 ;
V_290 = F_114 ( ( T_4 ) V_290 * V_292 * V_293 ,
V_294 * V_295 ) ;
}
return V_290 ;
}
static T_3 F_115 ( T_3 V_290 , T_5 V_297 ,
T_3 V_153 )
{
T_4 V_298 ;
if ( F_96 ( V_153 == 0 , L_51 ) )
return V_299 ;
V_298 = ( T_4 ) V_290 * V_297 * V_153 ;
V_298 = F_116 ( V_298 , 64 * 10000 ) + 2 ;
return V_298 ;
}
static T_3 F_117 ( T_3 V_290 , T_3 V_300 ,
T_3 V_301 , T_5 V_297 ,
T_3 V_153 )
{
T_3 V_298 ;
if ( F_96 ( V_153 == 0 , L_51 ) )
return V_299 ;
V_298 = ( V_153 * V_290 ) / ( V_300 * 10000 ) ;
V_298 = ( V_298 + 1 ) * V_301 * V_297 ;
V_298 = F_85 ( V_298 , 64 ) + 2 ;
return V_298 ;
}
static T_3 F_118 ( T_3 V_302 , T_3 V_301 ,
T_5 V_297 )
{
return F_85 ( V_302 * 64 , V_301 * V_297 ) + 2 ;
}
static T_3 F_119 ( const struct V_303 * V_304 ,
T_3 V_305 ,
bool V_306 )
{
T_3 V_307 , V_308 ;
if ( ! V_304 -> V_309 || ! V_304 -> V_310 . V_14 )
return 0 ;
V_307 = F_115 ( V_304 -> V_290 ,
V_304 -> V_310 . V_297 ,
V_305 ) ;
if ( ! V_306 )
return V_307 ;
V_308 = F_117 ( V_304 -> V_290 ,
V_304 -> V_300 ,
V_304 -> V_310 . V_301 ,
V_304 -> V_310 . V_297 ,
V_305 ) ;
return F_94 ( V_307 , V_308 ) ;
}
static T_3 F_120 ( const struct V_303 * V_304 ,
T_3 V_305 )
{
T_3 V_307 , V_308 ;
if ( ! V_304 -> V_309 || ! V_304 -> V_311 . V_14 )
return 0 ;
V_307 = F_115 ( V_304 -> V_290 ,
V_304 -> V_311 . V_297 ,
V_305 ) ;
V_308 = F_117 ( V_304 -> V_290 ,
V_304 -> V_300 ,
V_304 -> V_311 . V_301 ,
V_304 -> V_311 . V_297 ,
V_305 ) ;
return F_94 ( V_307 , V_308 ) ;
}
static T_3 F_121 ( const struct V_303 * V_304 ,
T_3 V_305 )
{
if ( ! V_304 -> V_309 || ! V_304 -> V_312 . V_14 )
return 0 ;
return F_117 ( V_304 -> V_290 ,
V_304 -> V_300 ,
V_304 -> V_312 . V_301 ,
V_304 -> V_312 . V_297 ,
V_305 ) ;
}
static T_3 F_122 ( const struct V_303 * V_304 ,
T_3 V_302 )
{
if ( ! V_304 -> V_309 || ! V_304 -> V_310 . V_14 )
return 0 ;
return F_118 ( V_302 ,
V_304 -> V_310 . V_301 ,
V_304 -> V_310 . V_297 ) ;
}
static unsigned int F_123 ( const struct V_1 * V_2 )
{
if ( F_59 ( V_2 ) -> V_112 >= 8 )
return 3072 ;
else if ( F_59 ( V_2 ) -> V_112 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_124 ( const struct V_1 * V_2 ,
int V_313 , bool V_314 )
{
if ( F_59 ( V_2 ) -> V_112 >= 8 )
return V_313 == 0 ? 255 : 2047 ;
else if ( F_59 ( V_2 ) -> V_112 >= 7 )
return V_313 == 0 ? 127 : 1023 ;
else if ( ! V_314 )
return V_313 == 0 ? 127 : 511 ;
else
return V_313 == 0 ? 63 : 255 ;
}
static unsigned int F_125 ( const struct V_1 * V_2 ,
int V_313 )
{
if ( F_59 ( V_2 ) -> V_112 >= 7 )
return V_313 == 0 ? 63 : 255 ;
else
return V_313 == 0 ? 31 : 63 ;
}
static unsigned int F_126 ( const struct V_1 * V_2 )
{
if ( F_59 ( V_2 ) -> V_112 >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_127 ( const struct V_1 * V_2 ,
int V_313 ,
const struct V_315 * V_106 ,
enum V_316 V_317 ,
bool V_314 )
{
unsigned int V_172 = F_123 ( V_2 ) ;
if ( V_314 && ! V_106 -> V_318 )
return 0 ;
if ( V_313 == 0 || V_106 -> V_319 > 1 ) {
V_172 /= F_59 ( V_2 ) -> V_320 ;
if ( F_59 ( V_2 ) -> V_112 <= 6 )
V_172 /= 2 ;
}
if ( V_106 -> V_318 ) {
if ( V_313 > 0 && V_317 == V_321 ) {
if ( V_314 )
V_172 *= 5 ;
V_172 /= 6 ;
} else {
V_172 /= 2 ;
}
}
return F_94 ( V_172 , F_124 ( V_2 , V_313 , V_314 ) ) ;
}
static unsigned int F_128 ( const struct V_1 * V_2 ,
int V_313 ,
const struct V_315 * V_106 )
{
if ( V_313 > 0 && V_106 -> V_319 > 1 )
return 64 ;
return F_125 ( V_2 , V_313 ) ;
}
static void F_129 ( const struct V_1 * V_2 ,
int V_313 ,
const struct V_315 * V_106 ,
enum V_316 V_317 ,
struct V_322 * F_91 )
{
F_91 -> V_310 = F_127 ( V_2 , V_313 , V_106 , V_317 , false ) ;
F_91 -> V_311 = F_127 ( V_2 , V_313 , V_106 , V_317 , true ) ;
F_91 -> V_312 = F_128 ( V_2 , V_313 , V_106 ) ;
F_91 -> V_13 = F_126 ( V_2 ) ;
}
static void F_130 ( struct V_1 * V_2 ,
int V_313 ,
struct V_322 * F_91 )
{
F_91 -> V_310 = F_124 ( V_2 , V_313 , false ) ;
F_91 -> V_311 = F_124 ( V_2 , V_313 , true ) ;
F_91 -> V_312 = F_125 ( V_2 , V_313 ) ;
F_91 -> V_13 = F_126 ( V_2 ) ;
}
static bool F_131 ( int V_313 ,
const struct V_322 * F_91 ,
struct V_323 * V_324 )
{
bool V_298 ;
if ( ! V_324 -> V_155 )
return false ;
V_324 -> V_155 = V_324 -> V_302 <= F_91 -> V_310 &&
V_324 -> V_325 <= F_91 -> V_311 &&
V_324 -> V_326 <= F_91 -> V_312 ;
V_298 = V_324 -> V_155 ;
if ( V_313 == 0 && ! V_324 -> V_155 ) {
if ( V_324 -> V_302 > F_91 -> V_310 )
F_7 ( L_52 ,
V_313 , V_324 -> V_302 , F_91 -> V_310 ) ;
if ( V_324 -> V_325 > F_91 -> V_311 )
F_7 ( L_53 ,
V_313 , V_324 -> V_325 , F_91 -> V_311 ) ;
if ( V_324 -> V_326 > F_91 -> V_312 )
F_7 ( L_54 ,
V_313 , V_324 -> V_326 , F_91 -> V_312 ) ;
V_324 -> V_302 = F_132 ( T_3 , V_324 -> V_302 , F_91 -> V_310 ) ;
V_324 -> V_325 = F_132 ( T_3 , V_324 -> V_325 , F_91 -> V_311 ) ;
V_324 -> V_326 = F_132 ( T_3 , V_324 -> V_326 , F_91 -> V_312 ) ;
V_324 -> V_155 = true ;
}
return V_298 ;
}
static void F_133 ( const struct V_3 * V_4 ,
int V_313 ,
const struct V_303 * V_327 ,
struct V_323 * V_324 )
{
T_6 V_328 = V_4 -> V_171 . V_328 [ V_313 ] ;
T_6 V_329 = V_4 -> V_171 . V_329 [ V_313 ] ;
T_6 V_330 = V_4 -> V_171 . V_330 [ V_313 ] ;
if ( V_313 > 0 ) {
V_328 *= 5 ;
V_329 *= 5 ;
V_330 *= 5 ;
}
V_324 -> V_302 = F_119 ( V_327 , V_328 , V_313 ) ;
V_324 -> V_325 = F_120 ( V_327 , V_329 ) ;
V_324 -> V_326 = F_121 ( V_327 , V_330 ) ;
V_324 -> V_331 = F_122 ( V_327 , V_324 -> V_302 ) ;
V_324 -> V_155 = true ;
}
static T_3
F_134 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
struct V_94 * V_332 = & V_26 -> V_106 . V_95 ;
T_1 V_333 , V_334 ;
if ( ! F_58 ( V_20 ) )
return 0 ;
V_333 = F_135 ( V_332 -> V_212 * 1000 * 8 ,
V_332 -> V_184 ) ;
V_334 = F_135 ( V_332 -> V_212 * 1000 * 8 ,
F_136 ( V_4 ) ) ;
return F_137 ( V_334 ) |
F_138 ( V_333 ) ;
}
static void F_139 ( struct V_1 * V_2 , T_6 V_171 [ 8 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_140 ( V_2 ) ) {
T_3 V_156 ;
int V_298 , V_28 ;
int V_313 , V_335 = F_141 ( V_2 ) ;
V_156 = 0 ;
F_42 ( & V_4 -> V_336 . V_337 ) ;
V_298 = F_142 ( V_4 ,
V_338 ,
& V_156 ) ;
F_43 ( & V_4 -> V_336 . V_337 ) ;
if ( V_298 ) {
F_49 ( L_55 , V_298 ) ;
return;
}
V_171 [ 0 ] = V_156 & V_339 ;
V_171 [ 1 ] = ( V_156 >> V_340 ) &
V_339 ;
V_171 [ 2 ] = ( V_156 >> V_341 ) &
V_339 ;
V_171 [ 3 ] = ( V_156 >> V_342 ) &
V_339 ;
V_156 = 1 ;
F_42 ( & V_4 -> V_336 . V_337 ) ;
V_298 = F_142 ( V_4 ,
V_338 ,
& V_156 ) ;
F_43 ( & V_4 -> V_336 . V_337 ) ;
if ( V_298 ) {
F_49 ( L_55 , V_298 ) ;
return;
}
V_171 [ 4 ] = V_156 & V_339 ;
V_171 [ 5 ] = ( V_156 >> V_340 ) &
V_339 ;
V_171 [ 6 ] = ( V_156 >> V_341 ) &
V_339 ;
V_171 [ 7 ] = ( V_156 >> V_342 ) &
V_339 ;
V_171 [ 0 ] += 2 ;
for ( V_313 = 1 ; V_313 <= V_335 ; V_313 ++ )
if ( V_171 [ V_313 ] != 0 )
V_171 [ V_313 ] += 2 ;
else {
for ( V_28 = V_313 + 1 ; V_28 <= V_335 ; V_28 ++ )
V_171 [ V_28 ] = 0 ;
break;
}
} else if ( F_60 ( V_2 ) || F_143 ( V_2 ) ) {
T_4 V_343 = F_144 ( V_344 ) ;
V_171 [ 0 ] = ( V_343 >> 56 ) & 0xFF ;
if ( V_171 [ 0 ] == 0 )
V_171 [ 0 ] = V_343 & 0xF ;
V_171 [ 1 ] = ( V_343 >> 4 ) & 0xFF ;
V_171 [ 2 ] = ( V_343 >> 12 ) & 0xFF ;
V_171 [ 3 ] = ( V_343 >> 20 ) & 0x1FF ;
V_171 [ 4 ] = ( V_343 >> 32 ) & 0x1FF ;
} else if ( F_59 ( V_2 ) -> V_112 >= 6 ) {
T_3 V_343 = F_3 ( V_344 ) ;
V_171 [ 0 ] = ( V_343 >> V_345 ) & V_346 ;
V_171 [ 1 ] = ( V_343 >> V_347 ) & V_346 ;
V_171 [ 2 ] = ( V_343 >> V_348 ) & V_346 ;
V_171 [ 3 ] = ( V_343 >> V_349 ) & V_346 ;
} else if ( F_59 ( V_2 ) -> V_112 >= 5 ) {
T_3 V_350 = F_3 ( V_351 ) ;
V_171 [ 0 ] = 7 ;
V_171 [ 1 ] = ( V_350 >> V_352 ) & V_353 ;
V_171 [ 2 ] = ( V_350 >> V_354 ) & V_353 ;
}
}
static void F_145 ( struct V_1 * V_2 , T_6 V_171 [ 5 ] )
{
if ( F_59 ( V_2 ) -> V_112 == 5 )
V_171 [ 0 ] = 13 ;
}
static void F_146 ( struct V_1 * V_2 , T_6 V_171 [ 5 ] )
{
if ( F_59 ( V_2 ) -> V_112 == 5 )
V_171 [ 0 ] = 13 ;
if ( F_34 ( V_2 ) )
V_171 [ 3 ] *= 2 ;
}
int F_141 ( const struct V_1 * V_2 )
{
if ( F_140 ( V_2 ) )
return 7 ;
else if ( F_60 ( V_2 ) || F_143 ( V_2 ) )
return 4 ;
else if ( F_59 ( V_2 ) -> V_112 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_147 ( struct V_1 * V_2 ,
const char * V_355 ,
const T_6 V_171 [ 8 ] )
{
int V_313 , V_335 = F_141 ( V_2 ) ;
for ( V_313 = 0 ; V_313 <= V_335 ; V_313 ++ ) {
unsigned int V_153 = V_171 [ V_313 ] ;
if ( V_153 == 0 ) {
F_49 ( L_56 ,
V_355 , V_313 ) ;
continue;
}
if ( F_140 ( V_2 ) )
V_153 *= 10 ;
else if ( V_313 > 0 )
V_153 *= 5 ;
F_7 ( L_57 ,
V_355 , V_313 , V_171 [ V_313 ] ,
V_153 / 10 , V_153 % 10 ) ;
}
}
static bool F_148 ( struct V_3 * V_4 ,
T_6 V_171 [ 5 ] , T_6 F_94 )
{
int V_313 , V_335 = F_141 ( V_4 -> V_2 ) ;
if ( V_171 [ 0 ] >= F_94 )
return false ;
V_171 [ 0 ] = F_91 ( V_171 [ 0 ] , F_94 ) ;
for ( V_313 = 1 ; V_313 <= V_335 ; V_313 ++ )
V_171 [ V_313 ] = F_149 ( T_6 , V_171 [ V_313 ] , F_85 ( F_94 , 5 ) ) ;
return true ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_356 ;
V_356 = F_148 ( V_4 , V_4 -> V_171 . V_328 , 12 ) |
F_148 ( V_4 , V_4 -> V_171 . V_329 , 12 ) |
F_148 ( V_4 , V_4 -> V_171 . V_330 , 12 ) ;
if ( ! V_356 )
return;
F_7 ( L_58 ) ;
F_147 ( V_2 , L_59 , V_4 -> V_171 . V_328 ) ;
F_147 ( V_2 , L_60 , V_4 -> V_171 . V_329 ) ;
F_147 ( V_2 , L_61 , V_4 -> V_171 . V_330 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_139 ( V_2 , V_4 -> V_171 . V_328 ) ;
memcpy ( V_4 -> V_171 . V_329 , V_4 -> V_171 . V_328 ,
sizeof( V_4 -> V_171 . V_328 ) ) ;
memcpy ( V_4 -> V_171 . V_330 , V_4 -> V_171 . V_328 ,
sizeof( V_4 -> V_171 . V_328 ) ) ;
F_145 ( V_2 , V_4 -> V_171 . V_329 ) ;
F_146 ( V_2 , V_4 -> V_171 . V_330 ) ;
F_147 ( V_2 , L_59 , V_4 -> V_171 . V_328 ) ;
F_147 ( V_2 , L_60 , V_4 -> V_171 . V_329 ) ;
F_147 ( V_2 , L_61 , V_4 -> V_171 . V_330 ) ;
if ( F_29 ( V_2 ) )
F_150 ( V_2 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_139 ( V_2 , V_4 -> V_171 . V_357 ) ;
F_147 ( V_2 , L_62 , V_4 -> V_171 . V_357 ) ;
}
static void F_153 ( struct V_19 * V_20 ,
struct V_303 * V_327 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
enum V_74 V_74 = V_26 -> V_74 ;
struct V_261 * V_37 ;
if ( ! F_58 ( V_20 ) )
return;
V_327 -> V_309 = true ;
V_327 -> V_300 = V_26 -> V_106 . V_95 . V_212 ;
V_327 -> V_290 = F_113 ( V_2 , V_20 ) ;
V_327 -> V_310 . V_297 = V_20 -> V_23 -> V_22 -> V_183 / 8 ;
V_327 -> V_312 . V_297 = 4 ;
V_327 -> V_310 . V_301 = V_26 -> V_106 . V_113 ;
V_327 -> V_312 . V_301 = V_26 -> V_213 ;
V_327 -> V_310 . V_14 = true ;
V_327 -> V_312 . V_14 = true ;
F_154 (plane, &dev->mode_config.plane_list) {
struct V_358 * V_358 = F_63 ( V_37 ) ;
if ( V_358 -> V_74 == V_74 ) {
V_327 -> V_311 = V_358 -> V_171 ;
break;
}
}
}
static void F_155 ( struct V_1 * V_2 ,
struct V_315 * V_106 )
{
struct V_26 * V_26 ;
F_156 (dev, intel_crtc) {
const struct V_359 * V_171 = & V_26 -> V_171 . V_309 ;
if ( ! V_171 -> V_360 )
continue;
V_106 -> V_318 |= V_171 -> V_318 ;
V_106 -> V_361 |= V_171 -> V_361 ;
V_106 -> V_319 ++ ;
}
}
static bool F_157 ( struct V_19 * V_20 ,
const struct V_303 * V_304 ,
struct V_359 * V_362 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
int V_313 , V_335 = F_141 ( V_2 ) ;
struct V_315 V_106 = {
. V_319 = 1 ,
. V_318 = V_304 -> V_311 . V_14 ,
. V_361 = V_304 -> V_311 . V_264 ,
} ;
struct V_322 F_91 ;
V_362 -> V_360 = V_304 -> V_309 ;
V_362 -> V_318 = V_304 -> V_311 . V_14 ;
V_362 -> V_361 = V_304 -> V_311 . V_264 ;
if ( F_59 ( V_2 ) -> V_112 <= 6 && V_304 -> V_311 . V_14 )
V_335 = 1 ;
if ( V_304 -> V_311 . V_264 )
V_335 = 0 ;
F_133 ( V_4 , 0 , V_304 , & V_362 -> V_171 [ 0 ] ) ;
if ( F_60 ( V_2 ) || F_143 ( V_2 ) )
V_362 -> V_333 = F_134 ( V_2 , V_20 ) ;
F_129 ( V_2 , 0 , & V_106 , V_363 , & F_91 ) ;
if ( ! F_131 ( 0 , & F_91 , & V_362 -> V_171 [ 0 ] ) )
return false ;
F_130 ( V_2 , 1 , & F_91 ) ;
for ( V_313 = 1 ; V_313 <= V_335 ; V_313 ++ ) {
struct V_323 V_171 = {} ;
F_133 ( V_4 , V_313 , V_304 , & V_171 ) ;
if ( ! F_131 ( V_313 , & F_91 , & V_171 ) )
break;
V_362 -> V_171 [ V_313 ] = V_171 ;
}
return true ;
}
static void F_158 ( struct V_1 * V_2 ,
int V_313 ,
struct V_323 * V_364 )
{
const struct V_26 * V_26 ;
V_364 -> V_155 = true ;
F_156 (dev, intel_crtc) {
const struct V_359 * V_309 = & V_26 -> V_171 . V_309 ;
const struct V_323 * V_171 = & V_309 -> V_171 [ V_313 ] ;
if ( ! V_309 -> V_360 )
continue;
if ( ! V_171 -> V_155 )
V_364 -> V_155 = false ;
V_364 -> V_302 = F_91 ( V_364 -> V_302 , V_171 -> V_302 ) ;
V_364 -> V_325 = F_91 ( V_364 -> V_325 , V_171 -> V_325 ) ;
V_364 -> V_326 = F_91 ( V_364 -> V_326 , V_171 -> V_326 ) ;
V_364 -> V_331 = F_91 ( V_364 -> V_331 , V_171 -> V_331 ) ;
}
}
static void F_159 ( struct V_1 * V_2 ,
const struct V_315 * V_106 ,
const struct V_322 * F_91 ,
struct V_359 * V_365 )
{
int V_313 , V_335 = F_141 ( V_2 ) ;
int V_366 = V_335 ;
if ( ( F_59 ( V_2 ) -> V_112 <= 6 || F_34 ( V_2 ) ) &&
V_106 -> V_319 > 1 )
return;
V_365 -> V_367 = F_59 ( V_2 ) -> V_112 >= 6 ;
for ( V_313 = 1 ; V_313 <= V_335 ; V_313 ++ ) {
struct V_323 * V_171 = & V_365 -> V_171 [ V_313 ] ;
F_158 ( V_2 , V_313 , V_171 ) ;
if ( V_313 > V_366 )
V_171 -> V_155 = false ;
else if ( ! F_131 ( V_313 , F_91 , V_171 ) )
V_366 = V_313 - 1 ;
if ( V_171 -> V_331 > F_91 -> V_13 ) {
if ( V_171 -> V_155 )
V_365 -> V_367 = false ;
V_171 -> V_331 = 0 ;
}
}
if ( F_27 ( V_2 ) && ! V_365 -> V_367 && F_36 ( V_2 ) ) {
for ( V_313 = 2 ; V_313 <= V_335 ; V_313 ++ ) {
struct V_323 * V_171 = & V_365 -> V_171 [ V_313 ] ;
V_171 -> V_155 = false ;
}
}
}
static int F_160 ( int V_368 , const struct V_359 * V_362 )
{
return V_368 + ( V_368 >= 2 && V_362 -> V_171 [ 4 ] . V_155 ) ;
}
static unsigned int F_161 ( struct V_1 * V_2 , int V_313 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_60 ( V_2 ) || F_143 ( V_2 ) )
return 2 * V_313 ;
else
return V_4 -> V_171 . V_328 [ V_313 ] ;
}
static void F_162 ( struct V_1 * V_2 ,
const struct V_359 * V_365 ,
enum V_316 V_369 ,
struct V_370 * V_371 )
{
struct V_26 * V_26 ;
int V_313 , V_368 ;
V_371 -> V_372 = V_365 -> V_367 ;
V_371 -> V_369 = V_369 ;
for ( V_368 = 1 ; V_368 <= 3 ; V_368 ++ ) {
const struct V_323 * V_373 ;
V_313 = F_160 ( V_368 , V_365 ) ;
V_373 = & V_365 -> V_171 [ V_313 ] ;
V_371 -> V_368 [ V_368 - 1 ] =
( F_161 ( V_2 , V_313 ) << V_374 ) |
( V_373 -> V_302 << V_375 ) |
V_373 -> V_326 ;
if ( V_373 -> V_155 )
V_371 -> V_368 [ V_368 - 1 ] |= V_376 ;
if ( F_59 ( V_2 ) -> V_112 >= 8 )
V_371 -> V_368 [ V_368 - 1 ] |=
V_373 -> V_331 << V_377 ;
else
V_371 -> V_368 [ V_368 - 1 ] |=
V_373 -> V_331 << V_378 ;
if ( F_59 ( V_2 ) -> V_112 <= 6 && V_373 -> V_325 ) {
F_163 ( V_368 != 1 ) ;
V_371 -> V_379 [ V_368 - 1 ] = V_380 | V_373 -> V_325 ;
} else
V_371 -> V_379 [ V_368 - 1 ] = V_373 -> V_325 ;
}
F_156 (dev, intel_crtc) {
enum V_74 V_74 = V_26 -> V_74 ;
const struct V_323 * V_373 =
& V_26 -> V_171 . V_309 . V_171 [ 0 ] ;
if ( F_163 ( ! V_373 -> V_155 ) )
continue;
V_371 -> V_381 [ V_74 ] = V_26 -> V_171 . V_309 . V_333 ;
V_371 -> V_382 [ V_74 ] =
( V_373 -> V_302 << V_383 ) |
( V_373 -> V_325 << V_384 ) |
V_373 -> V_326 ;
}
}
static struct V_359 * F_164 ( struct V_1 * V_2 ,
struct V_359 * V_385 ,
struct V_359 * V_386 )
{
int V_313 , V_335 = F_141 ( V_2 ) ;
int V_387 = 0 , V_388 = 0 ;
for ( V_313 = 1 ; V_313 <= V_335 ; V_313 ++ ) {
if ( V_385 -> V_171 [ V_313 ] . V_155 )
V_387 = V_313 ;
if ( V_386 -> V_171 [ V_313 ] . V_155 )
V_388 = V_313 ;
}
if ( V_387 == V_388 ) {
if ( V_386 -> V_367 && ! V_385 -> V_367 )
return V_386 ;
else
return V_385 ;
} else if ( V_387 > V_388 ) {
return V_385 ;
} else {
return V_386 ;
}
}
static unsigned int F_165 ( struct V_3 * V_4 ,
const struct V_370 * V_389 ,
const struct V_370 * V_390 )
{
unsigned int V_391 = 0 ;
enum V_74 V_74 ;
int V_368 ;
F_166 (dev_priv, pipe) {
if ( V_389 -> V_381 [ V_74 ] != V_390 -> V_381 [ V_74 ] ) {
V_391 |= F_167 ( V_74 ) ;
V_391 |= V_392 ;
}
if ( V_389 -> V_382 [ V_74 ] != V_390 -> V_382 [ V_74 ] ) {
V_391 |= F_168 ( V_74 ) ;
V_391 |= V_392 ;
}
}
if ( V_389 -> V_372 != V_390 -> V_372 ) {
V_391 |= V_393 ;
V_391 |= V_392 ;
}
if ( V_389 -> V_369 != V_390 -> V_369 ) {
V_391 |= V_394 ;
V_391 |= V_392 ;
}
if ( V_391 & V_392 )
return V_391 ;
for ( V_368 = 1 ; V_368 <= 3 ; V_368 ++ ) {
if ( V_389 -> V_368 [ V_368 - 1 ] != V_390 -> V_368 [ V_368 - 1 ] ||
V_389 -> V_379 [ V_368 - 1 ] != V_390 -> V_379 [ V_368 - 1 ] )
break;
}
for (; V_368 <= 3 ; V_368 ++ )
V_391 |= F_169 ( V_368 ) ;
return V_391 ;
}
static bool F_170 ( struct V_3 * V_4 ,
unsigned int V_391 )
{
struct V_370 * V_395 = & V_4 -> V_171 . V_396 ;
bool V_356 = false ;
if ( V_391 & F_169 ( 3 ) && V_395 -> V_368 [ 2 ] & V_376 ) {
V_395 -> V_368 [ 2 ] &= ~ V_376 ;
F_2 ( V_397 , V_395 -> V_368 [ 2 ] ) ;
V_356 = true ;
}
if ( V_391 & F_169 ( 2 ) && V_395 -> V_368 [ 1 ] & V_376 ) {
V_395 -> V_368 [ 1 ] &= ~ V_376 ;
F_2 ( V_398 , V_395 -> V_368 [ 1 ] ) ;
V_356 = true ;
}
if ( V_391 & F_169 ( 1 ) && V_395 -> V_368 [ 0 ] & V_376 ) {
V_395 -> V_368 [ 0 ] &= ~ V_376 ;
F_2 ( V_399 , V_395 -> V_368 [ 0 ] ) ;
V_356 = true ;
}
return V_356 ;
}
static void F_171 ( struct V_3 * V_4 ,
struct V_370 * V_371 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_370 * V_395 = & V_4 -> V_171 . V_396 ;
unsigned int V_391 ;
T_3 V_156 ;
V_391 = F_165 ( V_4 , V_395 , V_371 ) ;
if ( ! V_391 )
return;
F_170 ( V_4 , V_391 ) ;
if ( V_391 & F_168 ( V_242 ) )
F_2 ( V_400 , V_371 -> V_382 [ 0 ] ) ;
if ( V_391 & F_168 ( V_246 ) )
F_2 ( V_401 , V_371 -> V_382 [ 1 ] ) ;
if ( V_391 & F_168 ( V_255 ) )
F_2 ( V_402 , V_371 -> V_382 [ 2 ] ) ;
if ( V_391 & F_167 ( V_242 ) )
F_2 ( F_172 ( V_242 ) , V_371 -> V_381 [ 0 ] ) ;
if ( V_391 & F_167 ( V_246 ) )
F_2 ( F_172 ( V_246 ) , V_371 -> V_381 [ 1 ] ) ;
if ( V_391 & F_167 ( V_255 ) )
F_2 ( F_172 ( V_255 ) , V_371 -> V_381 [ 2 ] ) ;
if ( V_391 & V_394 ) {
if ( F_60 ( V_2 ) || F_143 ( V_2 ) ) {
V_156 = F_3 ( V_403 ) ;
if ( V_371 -> V_369 == V_363 )
V_156 &= ~ V_404 ;
else
V_156 |= V_404 ;
F_2 ( V_403 , V_156 ) ;
} else {
V_156 = F_3 ( V_405 ) ;
if ( V_371 -> V_369 == V_363 )
V_156 &= ~ V_406 ;
else
V_156 |= V_406 ;
F_2 ( V_405 , V_156 ) ;
}
}
if ( V_391 & V_393 ) {
V_156 = F_3 ( V_407 ) ;
if ( V_371 -> V_372 )
V_156 &= ~ V_408 ;
else
V_156 |= V_408 ;
F_2 ( V_407 , V_156 ) ;
}
if ( V_391 & F_169 ( 1 ) &&
V_395 -> V_379 [ 0 ] != V_371 -> V_379 [ 0 ] )
F_2 ( V_409 , V_371 -> V_379 [ 0 ] ) ;
if ( F_59 ( V_2 ) -> V_112 >= 7 ) {
if ( V_391 & F_169 ( 2 ) && V_395 -> V_379 [ 1 ] != V_371 -> V_379 [ 1 ] )
F_2 ( V_410 , V_371 -> V_379 [ 1 ] ) ;
if ( V_391 & F_169 ( 3 ) && V_395 -> V_379 [ 2 ] != V_371 -> V_379 [ 2 ] )
F_2 ( V_411 , V_371 -> V_379 [ 2 ] ) ;
}
if ( V_391 & F_169 ( 1 ) && V_395 -> V_368 [ 0 ] != V_371 -> V_368 [ 0 ] )
F_2 ( V_399 , V_371 -> V_368 [ 0 ] ) ;
if ( V_391 & F_169 ( 2 ) && V_395 -> V_368 [ 1 ] != V_371 -> V_368 [ 1 ] )
F_2 ( V_398 , V_371 -> V_368 [ 1 ] ) ;
if ( V_391 & F_169 ( 3 ) && V_395 -> V_368 [ 2 ] != V_371 -> V_368 [ 2 ] )
F_2 ( V_397 , V_371 -> V_368 [ 2 ] ) ;
V_4 -> V_171 . V_396 = * V_371 ;
}
static bool F_173 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_170 ( V_4 , V_392 ) ;
}
static void
F_174 ( struct V_1 * V_2 ,
struct V_19 * V_412 ,
const struct V_315 * V_106 ,
const struct V_413 * V_304 ,
struct V_414 * V_415 )
{
struct V_19 * V_20 ;
unsigned int V_416 , V_417 ;
int V_418 ;
if ( ! V_304 -> V_309 ) {
V_415 -> V_419 = 0 ;
V_415 -> V_420 = 0 ;
return;
}
V_417 = V_421 ;
V_417 -= 4 ;
V_418 = 0 ;
F_57 (dev, crtc) {
if ( ! F_58 ( V_20 ) )
continue;
if ( V_20 == V_412 )
break;
V_418 ++ ;
}
V_416 = V_417 / V_106 -> V_319 ;
V_415 -> V_419 = V_418 * V_417 / V_106 -> V_319 ;
V_415 -> V_420 = V_415 -> V_419 + V_416 ;
}
static unsigned int F_175 ( const struct V_315 * V_106 )
{
if ( V_106 -> V_319 == 1 )
return 32 ;
return 8 ;
}
static void F_176 ( struct V_414 * V_422 , T_1 V_182 )
{
V_422 -> V_419 = V_182 & 0x3ff ;
V_422 -> V_420 = ( V_182 >> 16 ) & 0x3ff ;
if ( V_422 -> V_420 )
V_422 -> V_420 += 1 ;
}
void F_177 ( struct V_3 * V_4 ,
struct V_423 * V_424 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_74 V_74 ;
int V_37 ;
T_1 V_156 ;
F_166 (dev_priv, pipe) {
F_178 (pipe, plane) {
V_156 = F_3 ( F_179 ( V_74 , V_37 ) ) ;
F_176 ( & V_424 -> V_37 [ V_74 ] [ V_37 ] ,
V_156 ) ;
}
V_156 = F_3 ( F_180 ( V_74 ) ) ;
F_176 ( & V_424 -> V_202 [ V_74 ] , V_156 ) ;
}
}
static unsigned int
F_181 ( const struct V_425 * V_327 )
{
return V_327 -> V_301 * V_327 -> V_426 * V_327 -> V_297 ;
}
static unsigned int
F_182 ( struct V_26 * V_26 ,
const struct V_413 * V_304 )
{
unsigned int V_427 = 0 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < F_183 ( V_26 ) ; V_37 ++ ) {
const struct V_425 * V_327 ;
V_327 = & V_304 -> V_37 [ V_37 ] ;
if ( ! V_327 -> V_14 )
continue;
V_427 += F_181 ( V_327 ) ;
}
return V_427 ;
}
static void
F_184 ( struct V_19 * V_20 ,
const struct V_315 * V_106 ,
const struct V_413 * V_304 ,
struct V_423 * V_424 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
enum V_74 V_74 = V_26 -> V_74 ;
struct V_414 * V_415 = & V_424 -> V_74 [ V_74 ] ;
T_6 V_428 , V_419 , V_429 ;
unsigned int V_427 ;
int V_37 ;
F_174 ( V_2 , V_20 , V_106 , V_304 , V_415 ) ;
V_428 = F_185 ( V_415 ) ;
if ( V_428 == 0 ) {
memset ( V_424 -> V_37 [ V_74 ] , 0 , sizeof( V_424 -> V_37 [ V_74 ] ) ) ;
memset ( & V_424 -> V_202 [ V_74 ] , 0 , sizeof( V_424 -> V_202 [ V_74 ] ) ) ;
return;
}
V_429 = F_175 ( V_106 ) ;
V_424 -> V_202 [ V_74 ] . V_419 = V_415 -> V_420 - V_429 ;
V_424 -> V_202 [ V_74 ] . V_420 = V_415 -> V_420 ;
V_428 -= V_429 ;
V_415 -> V_420 -= V_429 ;
V_427 = F_182 ( V_26 , V_304 ) ;
V_419 = V_415 -> V_419 ;
for ( V_37 = 0 ; V_37 < F_183 ( V_26 ) ; V_37 ++ ) {
const struct V_425 * V_327 ;
unsigned int V_430 ;
T_6 V_431 ;
V_327 = & V_304 -> V_37 [ V_37 ] ;
if ( ! V_327 -> V_14 )
continue;
V_430 = F_181 ( V_327 ) ;
V_431 = F_114 ( ( T_4 ) V_428 * V_430 ,
V_427 ) ;
V_424 -> V_37 [ V_74 ] [ V_37 ] . V_419 = V_419 ;
V_424 -> V_37 [ V_74 ] [ V_37 ] . V_420 = V_419 + V_431 ;
V_419 += V_431 ;
}
}
static T_3 F_186 ( const struct V_432 * V_106 )
{
return V_106 -> V_95 . V_184 ;
}
static T_3 F_187 ( T_3 V_290 , T_5 V_297 ,
T_3 V_153 )
{
T_3 V_433 , V_298 ;
if ( V_153 == 0 )
return V_299 ;
V_433 = V_153 * V_290 * V_297 ;
V_298 = F_85 ( V_433 , 1000 ) ;
return V_298 ;
}
static T_3 F_188 ( T_3 V_290 , T_3 V_300 ,
T_3 V_301 , T_5 V_297 ,
T_3 V_153 )
{
T_3 V_298 , V_434 , V_433 ;
if ( V_153 == 0 )
return V_299 ;
V_434 = V_301 * V_297 ;
V_433 = V_153 * V_290 ;
V_298 = F_85 ( V_433 , V_300 * 1000 ) *
V_434 ;
return V_298 ;
}
static bool F_189 ( const struct V_423 * V_435 ,
const struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_87 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_423 * V_436 = & V_4 -> V_171 . V_437 . V_424 ;
enum V_74 V_74 = V_26 -> V_74 ;
if ( memcmp ( V_435 -> V_37 [ V_74 ] , V_436 -> V_37 [ V_74 ] ,
sizeof( V_435 -> V_37 [ V_74 ] ) ) )
return true ;
if ( memcmp ( & V_435 -> V_202 [ V_74 ] , & V_436 -> V_202 [ V_74 ] ,
sizeof( V_435 -> V_202 [ V_74 ] ) ) )
return true ;
return false ;
}
static void F_190 ( struct V_1 * V_2 ,
struct V_315 * V_106 )
{
struct V_19 * V_20 ;
struct V_261 * V_37 ;
F_191 (crtc, &dev->mode_config.crtc_list, head)
V_106 -> V_319 += F_58 ( V_20 ) ;
F_191 (plane, &dev->mode_config.plane_list, head) {
struct V_358 * V_358 = F_63 ( V_37 ) ;
V_106 -> V_318 |= V_358 -> V_171 . V_14 ;
V_106 -> V_361 |= V_358 -> V_171 . V_264 ;
}
}
static void F_192 ( struct V_19 * V_20 ,
struct V_413 * V_327 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
enum V_74 V_74 = V_26 -> V_74 ;
struct V_261 * V_37 ;
int V_28 = 1 ;
V_327 -> V_309 = F_58 ( V_20 ) ;
if ( V_327 -> V_309 ) {
V_327 -> V_300 = V_26 -> V_106 . V_95 . V_212 ;
V_327 -> V_290 = F_186 ( & V_26 -> V_106 ) ;
V_327 -> V_37 [ 0 ] . V_14 = true ;
V_327 -> V_37 [ 0 ] . V_297 =
V_20 -> V_23 -> V_22 -> V_183 / 8 ;
V_327 -> V_37 [ 0 ] . V_301 = V_26 -> V_106 . V_113 ;
V_327 -> V_37 [ 0 ] . V_426 = V_26 -> V_106 . V_114 ;
V_327 -> V_202 . V_14 = true ;
V_327 -> V_202 . V_297 = 4 ;
V_327 -> V_202 . V_301 = V_26 -> V_213 ?
V_26 -> V_213 : 64 ;
}
F_191 (plane, &dev->mode_config.plane_list, head) {
struct V_358 * V_358 = F_63 ( V_37 ) ;
if ( V_358 -> V_74 == V_74 )
V_327 -> V_37 [ V_28 ++ ] = V_358 -> V_171 ;
}
}
static bool F_193 ( struct V_413 * V_327 ,
struct V_425 * V_438 ,
T_6 V_439 ,
T_3 V_305 ,
T_6 * V_440 ,
T_5 * V_441 )
{
T_3 V_307 , V_308 , V_434 , V_442 , V_443 ;
T_3 V_444 ;
if ( V_305 == 0 || ! V_327 -> V_309 || ! V_438 -> V_14 )
return false ;
V_307 = F_187 ( V_327 -> V_290 ,
V_438 -> V_297 ,
V_305 ) ;
V_308 = F_188 ( V_327 -> V_290 ,
V_327 -> V_300 ,
V_438 -> V_301 ,
V_438 -> V_297 ,
V_305 ) ;
V_434 = V_438 -> V_301 *
V_438 -> V_297 ;
if ( ( ( V_439 * 512 ) / V_434 ) >= 1 )
V_444 = F_94 ( V_307 , V_308 ) ;
else
V_444 = V_307 ;
V_442 = F_85 ( V_444 , 512 ) + 1 ;
V_443 = F_85 ( V_444 , V_434 ) ;
if ( V_442 > V_439 || V_443 > 31 )
return false ;
* V_440 = V_442 ;
* V_441 = V_443 ;
return true ;
}
static void F_194 ( const struct V_3 * V_4 ,
struct V_423 * V_424 ,
struct V_413 * V_327 ,
enum V_74 V_74 ,
int V_313 ,
int V_445 ,
struct V_446 * V_324 )
{
T_6 V_153 = V_4 -> V_171 . V_357 [ V_313 ] ;
T_6 V_447 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_445 ; V_28 ++ ) {
V_447 = F_185 ( & V_424 -> V_37 [ V_74 ] [ V_28 ] ) ;
V_324 -> V_448 [ V_28 ] = F_193 ( V_327 , & V_327 -> V_37 [ V_28 ] ,
V_447 ,
V_153 ,
& V_324 -> V_449 [ V_28 ] ,
& V_324 -> V_450 [ V_28 ] ) ;
}
V_447 = F_185 ( & V_424 -> V_202 [ V_74 ] ) ;
V_324 -> V_451 = F_193 ( V_327 , & V_327 -> V_202 , V_447 ,
V_153 , & V_324 -> V_452 ,
& V_324 -> V_453 ) ;
}
static T_3
F_195 ( struct V_19 * V_20 , struct V_413 * V_327 )
{
if ( ! F_58 ( V_20 ) )
return 0 ;
return F_85 ( 8 * V_327 -> V_300 * 1000 , V_327 -> V_290 ) ;
}
static void F_196 ( struct V_19 * V_20 ,
struct V_413 * V_304 ,
struct V_446 * V_454 )
{
struct V_26 * V_26 = F_10 ( V_20 ) ;
int V_28 ;
if ( ! V_304 -> V_309 )
return;
for ( V_28 = 0 ; V_28 < F_183 ( V_26 ) ; V_28 ++ )
V_454 -> V_448 [ V_28 ] = false ;
V_454 -> V_451 = false ;
}
static void F_197 ( struct V_19 * V_20 ,
struct V_423 * V_424 ,
struct V_413 * V_304 ,
struct V_455 * V_362 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
int V_313 , V_335 = F_141 ( V_2 ) ;
for ( V_313 = 0 ; V_313 <= V_335 ; V_313 ++ ) {
F_194 ( V_4 , V_424 , V_304 , V_26 -> V_74 ,
V_313 , F_183 ( V_26 ) ,
& V_362 -> V_171 [ V_313 ] ) ;
}
V_362 -> V_333 = F_195 ( V_20 , V_304 ) ;
F_196 ( V_20 , V_304 , & V_362 -> V_454 ) ;
}
static void F_198 ( struct V_1 * V_2 ,
struct V_413 * V_327 ,
struct V_455 * V_456 ,
struct V_457 * V_373 ,
struct V_26 * V_26 )
{
int V_313 , V_335 = F_141 ( V_2 ) ;
enum V_74 V_74 = V_26 -> V_74 ;
T_3 V_458 ;
int V_28 ;
for ( V_313 = 0 ; V_313 <= V_335 ; V_313 ++ ) {
for ( V_28 = 0 ; V_28 < F_183 ( V_26 ) ; V_28 ++ ) {
V_458 = 0 ;
V_458 |= V_456 -> V_171 [ V_313 ] . V_450 [ V_28 ] <<
V_459 ;
V_458 |= V_456 -> V_171 [ V_313 ] . V_449 [ V_28 ] ;
if ( V_456 -> V_171 [ V_313 ] . V_448 [ V_28 ] )
V_458 |= V_460 ;
V_373 -> V_37 [ V_74 ] [ V_28 ] [ V_313 ] = V_458 ;
}
V_458 = 0 ;
V_458 |= V_456 -> V_171 [ V_313 ] . V_453 << V_459 ;
V_458 |= V_456 -> V_171 [ V_313 ] . V_452 ;
if ( V_456 -> V_171 [ V_313 ] . V_451 )
V_458 |= V_460 ;
V_373 -> V_202 [ V_74 ] [ V_313 ] = V_458 ;
}
for ( V_28 = 0 ; V_28 < F_183 ( V_26 ) ; V_28 ++ ) {
V_458 = 0 ;
V_458 |= V_456 -> V_454 . V_450 [ V_28 ] << V_459 ;
V_458 |= V_456 -> V_454 . V_449 [ V_28 ] ;
if ( V_456 -> V_454 . V_448 [ V_28 ] )
V_458 |= V_460 ;
V_373 -> V_461 [ V_74 ] [ V_28 ] = V_458 ;
}
V_458 = 0 ;
V_458 |= V_456 -> V_454 . V_453 << V_459 ;
V_458 |= V_456 -> V_454 . V_452 ;
if ( V_456 -> V_454 . V_451 )
V_458 |= V_460 ;
V_373 -> V_462 [ V_74 ] = V_458 ;
V_373 -> V_381 [ V_74 ] = V_456 -> V_333 ;
}
static void F_199 ( struct V_3 * V_4 , T_3 V_182 ,
const struct V_414 * V_422 )
{
if ( V_422 -> V_420 )
F_2 ( V_182 , ( V_422 -> V_420 - 1 ) << 16 | V_422 -> V_419 ) ;
else
F_2 ( V_182 , 0 ) ;
}
static void F_200 ( struct V_3 * V_4 ,
const struct V_457 * V_390 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_26 * V_20 ;
F_191 (crtc, &dev->mode_config.crtc_list, base.head) {
int V_28 , V_313 , V_335 = F_141 ( V_2 ) ;
enum V_74 V_74 = V_20 -> V_74 ;
if ( ! V_390 -> V_391 [ V_74 ] )
continue;
F_2 ( F_172 ( V_74 ) , V_390 -> V_381 [ V_74 ] ) ;
for ( V_313 = 0 ; V_313 <= V_335 ; V_313 ++ ) {
for ( V_28 = 0 ; V_28 < F_183 ( V_20 ) ; V_28 ++ )
F_2 ( F_201 ( V_74 , V_28 , V_313 ) ,
V_390 -> V_37 [ V_74 ] [ V_28 ] [ V_313 ] ) ;
F_2 ( F_202 ( V_74 , V_313 ) ,
V_390 -> V_202 [ V_74 ] [ V_313 ] ) ;
}
for ( V_28 = 0 ; V_28 < F_183 ( V_20 ) ; V_28 ++ )
F_2 ( F_203 ( V_74 , V_28 ) ,
V_390 -> V_461 [ V_74 ] [ V_28 ] ) ;
F_2 ( F_204 ( V_74 ) , V_390 -> V_462 [ V_74 ] ) ;
for ( V_28 = 0 ; V_28 < F_183 ( V_20 ) ; V_28 ++ )
F_199 ( V_4 ,
F_179 ( V_74 , V_28 ) ,
& V_390 -> V_424 . V_37 [ V_74 ] [ V_28 ] ) ;
F_199 ( V_4 , F_180 ( V_74 ) ,
& V_390 -> V_424 . V_202 [ V_74 ] ) ;
}
}
static void
F_205 ( struct V_3 * V_4 , enum V_74 V_74 , int V_463 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_37 ;
F_7 ( L_63 , F_206 ( V_74 ) , V_463 ) ;
F_178 (pipe, plane) {
F_2 ( F_207 ( V_74 , V_37 ) ,
F_3 ( F_207 ( V_74 , V_37 ) ) ) ;
}
F_2 ( F_208 ( V_74 ) , F_3 ( F_208 ( V_74 ) ) ) ;
}
static bool
F_209 ( const struct V_423 * V_389 ,
const struct V_423 * V_390 ,
enum V_74 V_74 )
{
T_6 V_464 , V_465 ;
V_464 = F_185 ( & V_389 -> V_74 [ V_74 ] ) ;
V_465 = F_185 ( & V_390 -> V_74 [ V_74 ] ) ;
return V_464 != V_465 &&
V_390 -> V_74 [ V_74 ] . V_419 >= V_389 -> V_74 [ V_74 ] . V_419 &&
V_390 -> V_74 [ V_74 ] . V_420 <= V_389 -> V_74 [ V_74 ] . V_420 ;
}
static void F_210 ( struct V_3 * V_4 ,
struct V_457 * V_466 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_423 * V_436 , * V_435 ;
bool V_467 [ V_468 ] = { false , false , false } ;
struct V_26 * V_20 ;
enum V_74 V_74 ;
V_435 = & V_466 -> V_424 ;
V_436 = & V_4 -> V_171 . V_437 . V_424 ;
F_156 (dev, crtc) {
if ( ! V_20 -> V_309 )
continue;
V_74 = V_20 -> V_74 ;
if ( ! F_209 ( V_436 , V_435 , V_74 ) )
continue;
F_205 ( V_4 , V_74 , 1 ) ;
F_211 ( V_2 , V_74 ) ;
V_467 [ V_74 ] = true ;
}
F_156 (dev, crtc) {
if ( ! V_20 -> V_309 )
continue;
V_74 = V_20 -> V_74 ;
if ( V_467 [ V_74 ] )
continue;
if ( F_185 ( & V_435 -> V_74 [ V_74 ] ) <
F_185 ( & V_436 -> V_74 [ V_74 ] ) ) {
F_205 ( V_4 , V_74 , 2 ) ;
F_211 ( V_2 , V_74 ) ;
}
V_467 [ V_74 ] = true ;
}
F_156 (dev, crtc) {
if ( ! V_20 -> V_309 )
continue;
V_74 = V_20 -> V_74 ;
if ( V_467 [ V_74 ] )
continue;
F_205 ( V_4 , V_74 , 3 ) ;
}
}
static bool F_212 ( struct V_19 * V_20 ,
struct V_413 * V_304 ,
struct V_315 * V_106 ,
struct V_423 * V_424 ,
struct V_455 * V_362 )
{
struct V_26 * V_26 = F_10 ( V_20 ) ;
F_192 ( V_20 , V_304 ) ;
F_184 ( V_20 , V_106 , V_304 , V_424 ) ;
F_197 ( V_20 , V_424 , V_304 , V_362 ) ;
if ( ! memcmp ( & V_26 -> V_171 . V_469 , V_362 , sizeof( * V_362 ) ) )
return false ;
V_26 -> V_171 . V_469 = * V_362 ;
return true ;
}
static void F_213 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_315 * V_106 ,
struct V_457 * V_373 )
{
struct V_26 * V_26 ;
struct V_26 * V_470 = F_10 ( V_20 ) ;
if ( ! F_189 ( & V_373 -> V_424 , V_470 ) )
return;
F_191 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
struct V_413 V_304 = {} ;
struct V_455 V_362 = {} ;
bool V_471 ;
if ( V_470 -> V_74 == V_26 -> V_74 )
continue;
if ( ! V_26 -> V_309 )
continue;
V_471 = F_212 ( & V_26 -> V_87 ,
& V_304 , V_106 ,
& V_373 -> V_424 , & V_362 ) ;
F_163 ( ! V_471 ) ;
F_198 ( V_2 , & V_304 , & V_362 , V_373 , V_26 ) ;
V_373 -> V_391 [ V_26 -> V_74 ] = true ;
}
}
static void F_214 ( struct V_19 * V_20 )
{
struct V_26 * V_26 = F_10 ( V_20 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_413 V_304 = {} ;
struct V_457 * V_371 = & V_4 -> V_171 . V_472 ;
struct V_455 V_362 = {} ;
struct V_315 V_106 = {} ;
memset ( V_371 , 0 , sizeof( * V_371 ) ) ;
F_190 ( V_2 , & V_106 ) ;
if ( ! F_212 ( V_20 , & V_304 , & V_106 ,
& V_371 -> V_424 , & V_362 ) )
return;
F_198 ( V_2 , & V_304 , & V_362 , V_371 , V_26 ) ;
V_371 -> V_391 [ V_26 -> V_74 ] = true ;
F_213 ( V_2 , V_20 , & V_106 , V_371 ) ;
F_200 ( V_4 , V_371 ) ;
F_210 ( V_4 , V_371 ) ;
V_4 -> V_171 . V_437 = * V_371 ;
}
static void
F_215 ( struct V_261 * V_37 , struct V_19 * V_20 ,
T_3 V_262 , T_3 V_263 ,
int V_173 , bool V_14 , bool V_264 )
{
struct V_358 * V_358 = F_63 ( V_37 ) ;
V_358 -> V_171 . V_14 = V_14 ;
V_358 -> V_171 . V_264 = V_264 ;
V_358 -> V_171 . V_301 = V_262 ;
V_358 -> V_171 . V_426 = V_263 ;
V_358 -> V_171 . V_297 = V_173 ;
F_214 ( V_20 ) ;
}
static void F_216 ( struct V_19 * V_20 )
{
struct V_26 * V_26 = F_10 ( V_20 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_322 F_91 ;
struct V_303 V_304 = {} ;
struct V_370 V_371 = {} ;
enum V_316 V_369 ;
struct V_359 V_362 = {} ;
struct V_359 V_473 = {} , V_474 = {} , * V_475 ;
struct V_315 V_106 = {} ;
F_153 ( V_20 , & V_304 ) ;
F_157 ( V_20 , & V_304 , & V_362 ) ;
if ( ! memcmp ( & V_26 -> V_171 . V_309 , & V_362 , sizeof( V_362 ) ) )
return;
V_26 -> V_171 . V_309 = V_362 ;
F_155 ( V_2 , & V_106 ) ;
F_129 ( V_2 , 1 , & V_106 , V_363 , & F_91 ) ;
F_159 ( V_2 , & V_106 , & F_91 , & V_473 ) ;
if ( F_59 ( V_2 ) -> V_112 >= 7 &&
V_106 . V_319 == 1 && V_106 . V_318 ) {
F_129 ( V_2 , 1 , & V_106 , V_321 , & F_91 ) ;
F_159 ( V_2 , & V_106 , & F_91 , & V_474 ) ;
V_475 = F_164 ( V_2 , & V_473 , & V_474 ) ;
} else {
V_475 = & V_473 ;
}
V_369 = ( V_475 == & V_473 ) ?
V_363 : V_321 ;
F_162 ( V_2 , V_475 , V_369 , & V_371 ) ;
F_171 ( V_4 , & V_371 ) ;
}
static void
F_217 ( struct V_261 * V_37 ,
struct V_19 * V_20 ,
T_3 V_262 , T_3 V_263 ,
int V_173 , bool V_14 , bool V_264 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_358 * V_358 = F_63 ( V_37 ) ;
V_358 -> V_171 . V_14 = V_14 ;
V_358 -> V_171 . V_264 = V_264 ;
V_358 -> V_171 . V_301 = V_262 ;
V_358 -> V_171 . V_426 = V_262 ;
V_358 -> V_171 . V_297 = V_173 ;
if ( F_34 ( V_2 ) && V_264 && F_173 ( V_2 ) )
F_211 ( V_2 , V_358 -> V_74 ) ;
F_216 ( V_20 ) ;
}
static void F_218 ( T_3 V_156 ,
struct V_455 * V_309 ,
bool V_476 ,
bool V_477 ,
int V_28 ,
int V_313 )
{
bool V_478 = ( V_156 & V_460 ) != 0 ;
if ( ! V_476 ) {
if ( ! V_477 ) {
V_309 -> V_171 [ V_313 ] . V_448 [ V_28 ] = V_478 ;
V_309 -> V_171 [ V_313 ] . V_449 [ V_28 ] =
V_156 & V_479 ;
V_309 -> V_171 [ V_313 ] . V_450 [ V_28 ] =
( V_156 >> V_459 ) &
V_480 ;
} else {
V_309 -> V_171 [ V_313 ] . V_451 = V_478 ;
V_309 -> V_171 [ V_313 ] . V_452 =
V_156 & V_479 ;
V_309 -> V_171 [ V_313 ] . V_453 =
( V_156 >> V_459 ) &
V_480 ;
}
} else {
if ( ! V_477 ) {
V_309 -> V_454 . V_448 [ V_28 ] = V_478 ;
V_309 -> V_454 . V_449 [ V_28 ] =
V_156 & V_479 ;
V_309 -> V_454 . V_450 [ V_28 ] =
( V_156 >> V_459 ) &
V_480 ;
} else {
V_309 -> V_454 . V_451 = V_478 ;
V_309 -> V_454 . V_452 =
V_156 & V_479 ;
V_309 -> V_454 . V_453 =
( V_156 >> V_459 ) &
V_480 ;
}
}
}
static void F_219 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_457 * V_396 = & V_4 -> V_171 . V_437 ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
struct V_455 * V_309 = & V_26 -> V_171 . V_469 ;
enum V_74 V_74 = V_26 -> V_74 ;
int V_313 , V_28 , V_335 ;
T_3 V_458 ;
V_335 = F_141 ( V_2 ) ;
V_396 -> V_381 [ V_74 ] = F_3 ( F_172 ( V_74 ) ) ;
for ( V_313 = 0 ; V_313 <= V_335 ; V_313 ++ ) {
for ( V_28 = 0 ; V_28 < F_183 ( V_26 ) ; V_28 ++ )
V_396 -> V_37 [ V_74 ] [ V_28 ] [ V_313 ] =
F_3 ( F_201 ( V_74 , V_28 , V_313 ) ) ;
V_396 -> V_202 [ V_74 ] [ V_313 ] = F_3 ( F_202 ( V_74 , V_313 ) ) ;
}
for ( V_28 = 0 ; V_28 < F_183 ( V_26 ) ; V_28 ++ )
V_396 -> V_461 [ V_74 ] [ V_28 ] = F_3 ( F_203 ( V_74 , V_28 ) ) ;
V_396 -> V_462 [ V_74 ] = F_3 ( F_204 ( V_74 ) ) ;
if ( ! F_58 ( V_20 ) )
return;
V_396 -> V_391 [ V_74 ] = true ;
V_309 -> V_333 = V_396 -> V_381 [ V_74 ] ;
for ( V_313 = 0 ; V_313 <= V_335 ; V_313 ++ ) {
for ( V_28 = 0 ; V_28 < F_183 ( V_26 ) ; V_28 ++ ) {
V_458 = V_396 -> V_37 [ V_74 ] [ V_28 ] [ V_313 ] ;
F_218 ( V_458 , V_309 , false ,
false , V_28 , V_313 ) ;
}
V_458 = V_396 -> V_202 [ V_74 ] [ V_313 ] ;
F_218 ( V_458 , V_309 , false , true , V_28 , V_313 ) ;
}
for ( V_28 = 0 ; V_28 < F_183 ( V_26 ) ; V_28 ++ ) {
V_458 = V_396 -> V_461 [ V_74 ] [ V_28 ] ;
F_218 ( V_458 , V_309 , true , false , V_28 , 0 ) ;
}
V_458 = V_396 -> V_462 [ V_74 ] ;
F_218 ( V_458 , V_309 , true , true , V_28 , 0 ) ;
}
void F_220 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_423 * V_424 = & V_4 -> V_171 . V_437 . V_424 ;
struct V_19 * V_20 ;
F_177 ( V_4 , V_424 ) ;
F_191 (crtc, &dev->mode_config.crtc_list, head)
F_219 ( V_20 ) ;
}
static void F_221 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_370 * V_396 = & V_4 -> V_171 . V_396 ;
struct V_26 * V_26 = F_10 ( V_20 ) ;
struct V_359 * V_309 = & V_26 -> V_171 . V_309 ;
enum V_74 V_74 = V_26 -> V_74 ;
static const unsigned int V_481 [] = {
[ V_242 ] = V_400 ,
[ V_246 ] = V_401 ,
[ V_255 ] = V_402 ,
} ;
V_396 -> V_382 [ V_74 ] = F_3 ( V_481 [ V_74 ] ) ;
if ( F_60 ( V_2 ) || F_143 ( V_2 ) )
V_396 -> V_381 [ V_74 ] = F_3 ( F_172 ( V_74 ) ) ;
V_309 -> V_360 = F_58 ( V_20 ) ;
if ( V_309 -> V_360 ) {
T_1 V_126 = V_396 -> V_382 [ V_74 ] ;
V_309 -> V_171 [ 0 ] . V_155 = true ;
V_309 -> V_171 [ 0 ] . V_302 = ( V_126 & V_482 ) >> V_383 ;
V_309 -> V_171 [ 0 ] . V_325 = ( V_126 & V_483 ) >> V_384 ;
V_309 -> V_171 [ 0 ] . V_326 = V_126 & V_484 ;
V_309 -> V_333 = V_396 -> V_381 [ V_74 ] ;
} else {
int V_313 , V_335 = F_141 ( V_2 ) ;
for ( V_313 = 0 ; V_313 <= V_335 ; V_313 ++ )
V_309 -> V_171 [ V_313 ] . V_155 = true ;
}
}
void F_222 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_370 * V_396 = & V_4 -> V_171 . V_396 ;
struct V_19 * V_20 ;
F_57 (dev, crtc)
F_221 ( V_20 ) ;
V_396 -> V_368 [ 0 ] = F_3 ( V_399 ) ;
V_396 -> V_368 [ 1 ] = F_3 ( V_398 ) ;
V_396 -> V_368 [ 2 ] = F_3 ( V_397 ) ;
V_396 -> V_379 [ 0 ] = F_3 ( V_409 ) ;
if ( F_59 ( V_2 ) -> V_112 >= 7 ) {
V_396 -> V_379 [ 1 ] = F_3 ( V_410 ) ;
V_396 -> V_379 [ 2 ] = F_3 ( V_411 ) ;
}
if ( F_60 ( V_2 ) || F_143 ( V_2 ) )
V_396 -> V_369 = ( F_3 ( V_403 ) & V_404 ) ?
V_321 : V_363 ;
else if ( F_34 ( V_2 ) )
V_396 -> V_369 = ( F_3 ( V_405 ) & V_406 ) ?
V_321 : V_363 ;
V_396 -> V_372 =
! ( F_3 ( V_407 ) & V_408 ) ;
}
void F_223 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = V_20 -> V_2 -> V_5 ;
if ( V_4 -> V_84 . V_485 )
V_4 -> V_84 . V_485 ( V_20 ) ;
}
void F_224 ( struct V_261 * V_37 ,
struct V_19 * V_20 ,
T_3 V_262 ,
T_3 V_263 ,
int V_173 ,
bool V_14 , bool V_264 )
{
struct V_3 * V_4 = V_37 -> V_2 -> V_5 ;
if ( V_4 -> V_84 . V_486 )
V_4 -> V_84 . V_486 ( V_37 , V_20 ,
V_262 , V_263 ,
V_173 , V_14 , V_264 ) ;
}
static struct V_24 *
F_225 ( struct V_1 * V_2 )
{
struct V_24 * V_487 ;
int V_298 ;
F_163 ( ! F_226 ( & V_2 -> V_82 ) ) ;
V_487 = F_227 ( V_2 , 4096 ) ;
if ( ! V_487 ) {
F_228 ( L_64 ) ;
return NULL ;
}
V_298 = F_229 ( V_487 , 4096 , 0 ) ;
if ( V_298 ) {
F_49 ( L_65 , V_298 ) ;
goto V_488;
}
V_298 = F_230 ( V_487 , 1 ) ;
if ( V_298 ) {
F_49 ( L_66 , V_298 ) ;
goto V_489;
}
return V_487 ;
V_489:
F_231 ( V_487 ) ;
V_488:
F_232 ( & V_487 -> V_87 ) ;
return NULL ;
}
bool F_233 ( struct V_1 * V_2 , T_7 V_156 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_490 ;
F_234 ( & V_491 ) ;
V_490 = F_70 ( V_492 ) ;
if ( V_490 & V_493 ) {
F_228 ( L_67 ) ;
return false ;
}
V_490 = ( V_494 << V_495 ) |
( V_156 << V_496 ) | V_497 ;
F_235 ( V_492 , V_490 ) ;
F_236 ( V_492 ) ;
V_490 |= V_493 ;
F_235 ( V_492 , V_490 ) ;
return true ;
}
static void F_237 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_498 = F_3 ( V_499 ) ;
T_7 V_500 , V_501 , V_502 , V_503 ;
F_238 ( & V_491 ) ;
F_235 ( V_504 , F_3 ( V_504 ) | V_505 ) ;
F_235 ( V_506 , F_3 ( V_506 ) | V_507 ) ;
F_2 ( V_508 , 100000 ) ;
F_2 ( V_509 , 100000 ) ;
F_2 ( V_510 , 90000 ) ;
F_2 ( V_511 , 80000 ) ;
F_2 ( V_512 , 1 ) ;
V_500 = ( V_498 & V_513 ) >> V_514 ;
V_501 = ( V_498 & V_515 ) ;
V_502 = ( V_498 & V_516 ) >>
V_517 ;
V_503 = ( F_3 ( V_518 + ( V_502 * 4 ) ) & V_519 ) >>
V_520 ;
V_4 -> V_146 . V_500 = V_500 ;
V_4 -> V_146 . V_502 = V_502 ;
V_4 -> V_146 . V_521 = V_502 ;
V_4 -> V_146 . V_522 = V_501 ;
V_4 -> V_146 . V_523 = V_502 ;
F_71 ( L_68 ,
V_500 , V_501 , V_502 ) ;
F_2 ( V_524 , V_525 | V_526 ) ;
F_2 ( V_527 , V_503 ) ;
F_24 ( V_527 ) ;
V_498 |= V_528 ;
F_2 ( V_499 , V_498 ) ;
if ( F_239 ( ( F_3 ( V_492 ) & V_493 ) == 0 , 10 ) )
F_49 ( L_69 ) ;
F_240 ( 1 ) ;
F_233 ( V_2 , V_502 ) ;
V_4 -> V_146 . V_529 = F_3 ( 0x112e4 ) + F_3 ( 0x112e8 ) +
F_3 ( 0x112e0 ) ;
V_4 -> V_146 . V_530 = F_241 ( V_531 ) ;
V_4 -> V_146 . V_532 = F_3 ( 0x112f4 ) ;
V_4 -> V_146 . V_533 = F_242 () ;
F_243 ( & V_491 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_490 ;
F_238 ( & V_491 ) ;
V_490 = F_70 ( V_492 ) ;
F_2 ( V_524 , F_3 ( V_524 ) & ~ V_526 ) ;
F_2 ( V_534 , V_535 ) ;
F_2 ( V_536 , F_3 ( V_536 ) & ~ V_537 ) ;
F_2 ( V_538 , V_537 ) ;
F_2 ( V_539 , F_3 ( V_539 ) | V_537 ) ;
F_233 ( V_2 , V_4 -> V_146 . V_502 ) ;
F_240 ( 1 ) ;
V_490 |= V_493 ;
F_2 ( V_492 , V_490 ) ;
F_240 ( 1 ) ;
F_243 ( & V_491 ) ;
}
static T_1 F_245 ( struct V_3 * V_4 , T_7 V_156 )
{
T_1 V_540 ;
V_540 = V_4 -> V_336 . V_541 << 24 ;
if ( V_156 <= V_4 -> V_336 . V_542 )
V_540 |= V_4 -> V_336 . V_542 << 16 ;
return V_540 ;
}
static void F_246 ( struct V_3 * V_4 , T_7 V_156 )
{
int V_543 ;
V_543 = V_4 -> V_336 . V_544 ;
switch ( V_4 -> V_336 . V_544 ) {
case V_545 :
if ( V_156 > V_4 -> V_336 . V_546 + 1 && V_156 > V_4 -> V_336 . V_547 )
V_543 = V_548 ;
break;
case V_548 :
if ( V_156 <= V_4 -> V_336 . V_546 && V_156 < V_4 -> V_336 . V_547 )
V_543 = V_545 ;
else if ( V_156 >= V_4 -> V_336 . V_549 && V_156 > V_4 -> V_336 . V_547 )
V_543 = V_550 ;
break;
case V_550 :
if ( V_156 < ( V_4 -> V_336 . V_551 + V_4 -> V_336 . V_549 ) > > 1 && V_156 < V_4 -> V_336 . V_547 )
V_543 = V_548 ;
break;
}
if ( V_156 == V_4 -> V_336 . V_542 )
V_543 = V_545 ;
if ( V_156 == V_4 -> V_336 . V_541 )
V_543 = V_550 ;
if ( V_543 == V_4 -> V_336 . V_544 )
return;
switch ( V_543 ) {
case V_545 :
F_2 ( V_552 , 12500 ) ;
F_2 ( V_553 , 11800 ) ;
F_2 ( V_554 , 25000 ) ;
F_2 ( V_555 , 21250 ) ;
F_2 ( V_556 ,
V_557 |
V_558 |
V_559 |
V_560 |
V_561 |
V_562 ) ;
break;
case V_548 :
F_2 ( V_552 , 10250 ) ;
F_2 ( V_553 , 9225 ) ;
F_2 ( V_554 , 25000 ) ;
F_2 ( V_555 , 18750 ) ;
F_2 ( V_556 ,
V_557 |
V_558 |
V_559 |
V_560 |
V_561 |
V_562 ) ;
break;
case V_550 :
F_2 ( V_552 , 8000 ) ;
F_2 ( V_553 , 6800 ) ;
F_2 ( V_554 , 25000 ) ;
F_2 ( V_555 , 15000 ) ;
F_2 ( V_556 ,
V_557 |
V_558 |
V_559 |
V_560 |
V_561 |
V_562 ) ;
break;
}
V_4 -> V_336 . V_544 = V_543 ;
V_4 -> V_336 . V_563 = 0 ;
}
static T_1 F_247 ( struct V_3 * V_4 , T_7 V_156 )
{
T_1 V_564 = 0 ;
if ( V_156 > V_4 -> V_336 . V_542 )
V_564 |= V_565 | V_566 ;
if ( V_156 < V_4 -> V_336 . V_541 )
V_564 |= V_567 ;
V_564 |= V_4 -> V_568 & ( V_569 | V_570 ) ;
V_564 &= V_4 -> V_568 ;
return F_248 ( V_4 , ~ V_564 ) ;
}
void F_249 ( struct V_1 * V_2 , T_7 V_156 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_163 ( ! F_226 ( & V_4 -> V_336 . V_337 ) ) ;
F_163 ( V_156 > V_4 -> V_336 . V_541 ) ;
F_163 ( V_156 < V_4 -> V_336 . V_542 ) ;
if ( V_156 != V_4 -> V_336 . V_547 ) {
F_246 ( V_4 , V_156 ) ;
if ( F_60 ( V_2 ) || F_143 ( V_2 ) )
F_2 ( V_571 ,
F_250 ( V_156 ) ) ;
else
F_2 ( V_571 ,
F_251 ( V_156 ) |
F_252 ( 0 ) |
V_572 ) ;
}
F_2 ( V_573 , F_245 ( V_4 , V_156 ) ) ;
F_2 ( V_574 , F_247 ( V_4 , V_156 ) ) ;
F_24 ( V_571 ) ;
V_4 -> V_336 . V_547 = V_156 ;
F_253 ( V_156 * 50 ) ;
}
static void F_254 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_2 -> V_575 -> V_576 >= 0xd ) {
F_255 ( V_4 -> V_2 , V_4 -> V_336 . V_542 ) ;
return;
}
if ( V_4 -> V_336 . V_547 <= V_4 -> V_336 . V_542 )
return;
F_2 ( V_574 ,
F_248 ( V_4 , ~ 0 ) ) ;
F_256 ( V_4 , true ) ;
V_4 -> V_336 . V_547 = V_4 -> V_336 . V_542 ;
F_257 ( V_4 , V_577 ,
V_4 -> V_336 . V_542 ) ;
if ( F_6 ( ( ( F_258 ( V_4 , V_578 ) )
& V_579 ) == 0 , 100 ) )
F_49 ( L_70 ) ;
F_256 ( V_4 , false ) ;
F_2 ( V_574 ,
F_247 ( V_4 , V_4 -> V_336 . V_547 ) ) ;
}
void F_259 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_42 ( & V_4 -> V_336 . V_337 ) ;
if ( V_4 -> V_336 . V_14 ) {
if ( F_97 ( V_2 ) )
F_255 ( V_4 -> V_2 , V_4 -> V_336 . V_542 ) ;
else if ( F_75 ( V_2 ) )
F_254 ( V_4 ) ;
else
F_249 ( V_4 -> V_2 , V_4 -> V_336 . V_542 ) ;
V_4 -> V_336 . V_563 = 0 ;
}
F_43 ( & V_4 -> V_336 . V_337 ) ;
}
void F_260 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_42 ( & V_4 -> V_336 . V_337 ) ;
if ( V_4 -> V_336 . V_14 ) {
if ( F_75 ( V_2 ) )
F_255 ( V_4 -> V_2 , V_4 -> V_336 . V_541 ) ;
else
F_249 ( V_4 -> V_2 , V_4 -> V_336 . V_541 ) ;
V_4 -> V_336 . V_563 = 0 ;
}
F_43 ( & V_4 -> V_336 . V_337 ) ;
}
void F_255 ( struct V_1 * V_2 , T_7 V_156 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_163 ( ! F_226 ( & V_4 -> V_336 . V_337 ) ) ;
F_163 ( V_156 > V_4 -> V_336 . V_541 ) ;
F_163 ( V_156 < V_4 -> V_336 . V_542 ) ;
if ( F_261 ( F_97 ( V_2 ) && ( V_156 & 1 ) ,
L_71 ) )
V_156 &= ~ 1 ;
if ( V_156 != V_4 -> V_336 . V_547 )
F_257 ( V_4 , V_577 , V_156 ) ;
F_2 ( V_574 , F_247 ( V_4 , V_156 ) ) ;
V_4 -> V_336 . V_547 = V_156 ;
F_253 ( F_262 ( V_4 , V_156 ) ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_580 , 0 ) ;
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_580 , 0 ) ;
F_2 ( V_571 , 1 << 31 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_580 , 0 ) ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_4 , V_581 ) ;
F_2 ( V_580 , 0 ) ;
F_25 ( V_4 , V_581 ) ;
}
static void F_267 ( struct V_1 * V_2 , T_1 V_332 )
{
if ( F_75 ( V_2 ) ) {
if ( V_332 & ( V_582 | F_268 ( 1 ) ) )
V_332 = V_583 ;
else
V_332 = 0 ;
}
if ( F_269 ( V_2 ) )
F_7 ( L_72 ,
( V_332 & V_583 ) ? L_73 : L_74 ,
( V_332 & V_584 ) ? L_73 : L_74 ,
( V_332 & V_585 ) ? L_73 : L_74 ) ;
else
F_7 ( L_75 ,
( V_332 & V_583 ) ? L_73 : L_74 ) ;
}
static int F_270 ( const struct V_1 * V_2 , int V_586 )
{
if ( F_59 ( V_2 ) -> V_112 < 5 )
return 0 ;
if ( F_59 ( V_2 ) -> V_112 == 5 && ! F_271 ( V_2 ) )
return 0 ;
if ( V_586 >= 0 ) {
int V_564 ;
if ( F_269 ( V_2 ) )
V_564 = V_587 | V_588 |
V_589 ;
else
V_564 = V_587 ;
if ( ( V_586 & V_564 ) != V_586 )
F_7 ( L_76 ,
V_586 & V_564 , V_586 , V_564 ) ;
return V_586 & V_564 ;
}
if ( F_59 ( V_2 ) -> V_112 == 5 )
return 0 ;
if ( F_34 ( V_2 ) )
return ( V_587 | V_588 ) ;
return V_587 ;
}
int F_272 ( const struct V_1 * V_2 )
{
return V_99 . V_586 ;
}
static void F_273 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_590 ;
T_1 V_591 = 0 ;
int V_298 ;
V_590 = F_3 ( V_592 ) ;
V_4 -> V_336 . V_547 = 0 ;
V_4 -> V_336 . V_549 = ( V_590 >> 0 ) & 0xff ;
V_4 -> V_336 . V_551 = ( V_590 >> 8 ) & 0xff ;
V_4 -> V_336 . V_593 = ( V_590 >> 16 ) & 0xff ;
V_4 -> V_336 . V_594 = V_4 -> V_336 . V_549 ;
V_4 -> V_336 . V_546 = V_4 -> V_336 . V_551 ;
if ( F_60 ( V_2 ) || F_143 ( V_2 ) ) {
V_298 = F_142 ( V_4 ,
V_595 ,
& V_591 ) ;
if ( 0 == V_298 )
V_4 -> V_336 . V_546 =
( V_591 >> 8 ) & 0xff ;
}
if ( V_4 -> V_336 . V_541 == 0 )
V_4 -> V_336 . V_541 = V_4 -> V_336 . V_594 ;
if ( V_4 -> V_336 . V_542 == 0 ) {
if ( F_60 ( V_2 ) || F_143 ( V_2 ) )
V_4 -> V_336 . V_542 =
F_91 ( V_4 -> V_336 . V_546 , ( T_7 ) 9 ) ;
else
V_4 -> V_336 . V_542 =
V_4 -> V_336 . V_593 ;
}
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_596 * V_597 ;
T_3 V_598 = 0 ;
int V_599 ;
F_2 ( V_600 , 0 ) ;
F_23 ( V_4 , V_581 ) ;
F_2 ( V_580 , 0 ) ;
F_2 ( V_601 , 54 << 16 ) ;
F_2 ( V_602 , 125000 ) ;
F_2 ( V_603 , 25 ) ;
F_275 (ring, dev_priv, unused)
F_2 ( F_276 ( V_597 -> V_604 ) , 10 ) ;
F_2 ( V_605 , 0 ) ;
F_2 ( V_606 , 37500 ) ;
if ( F_272 ( V_2 ) & V_587 )
V_598 = V_583 ;
F_277 ( L_77 , ( V_598 & V_583 ) ?
L_73 : L_74 ) ;
F_2 ( V_580 , V_607 |
F_268 ( 1 ) |
V_598 ) ;
F_25 ( V_4 , V_581 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_596 * V_597 ;
T_3 V_598 = 0 ;
int V_599 ;
F_2 ( V_600 , 0 ) ;
F_23 ( V_4 , V_581 ) ;
F_2 ( V_580 , 0 ) ;
F_273 ( V_2 ) ;
F_2 ( V_601 , 40 << 16 ) ;
F_2 ( V_602 , 125000 ) ;
F_2 ( V_603 , 25 ) ;
F_275 (ring, dev_priv, unused)
F_2 ( F_276 ( V_597 -> V_604 ) , 10 ) ;
F_2 ( V_605 , 0 ) ;
if ( F_143 ( V_2 ) )
F_2 ( V_606 , 625 ) ;
else
F_2 ( V_606 , 50000 ) ;
if ( F_272 ( V_2 ) & V_587 )
V_598 = V_583 ;
F_267 ( V_2 , V_598 ) ;
if ( F_143 ( V_2 ) )
F_2 ( V_580 , V_607 |
V_582 |
V_598 ) ;
else
F_2 ( V_580 , V_607 |
F_268 ( 1 ) |
V_598 ) ;
F_2 ( V_571 ,
F_250 ( V_4 -> V_336 . V_551 ) ) ;
F_2 ( V_608 ,
F_250 ( V_4 -> V_336 . V_551 ) ) ;
F_2 ( V_609 , 100000000 / 128 ) ;
F_2 ( V_573 ,
V_4 -> V_336 . V_541 << 24 |
V_4 -> V_336 . V_542 << 16 ) ;
F_2 ( V_553 , 7600000 / 128 ) ;
F_2 ( V_555 , 31300000 / 128 ) ;
F_2 ( V_552 , 66000 ) ;
F_2 ( V_554 , 350000 ) ;
F_2 ( V_610 , 10 ) ;
F_2 ( V_556 ,
V_557 |
V_558 |
V_559 |
V_560 |
V_561 |
V_562 ) ;
V_4 -> V_336 . V_544 = V_550 ;
F_249 ( V_4 -> V_2 , V_4 -> V_336 . V_542 ) ;
F_25 ( V_4 , V_581 ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_596 * V_597 ;
T_1 V_611 , V_612 = 0 , V_598 = 0 ;
T_1 V_613 ;
int V_614 ;
int V_28 , V_298 ;
F_163 ( ! F_226 ( & V_4 -> V_336 . V_337 ) ) ;
F_2 ( V_600 , 0 ) ;
if ( ( V_613 = F_3 ( V_615 ) ) ) {
F_49 ( L_78 , V_613 ) ;
F_2 ( V_615 , V_613 ) ;
}
F_23 ( V_4 , V_581 ) ;
F_273 ( V_2 ) ;
F_2 ( V_580 , 0 ) ;
F_2 ( V_616 , 1000 << 16 ) ;
F_2 ( V_601 , 40 << 16 | 30 ) ;
F_2 ( V_617 , 30 ) ;
F_2 ( V_602 , 125000 ) ;
F_2 ( V_603 , 25 ) ;
F_275 (ring, dev_priv, i)
F_2 ( F_276 ( V_597 -> V_604 ) , 10 ) ;
F_2 ( V_605 , 0 ) ;
F_2 ( V_618 , 1000 ) ;
if ( F_34 ( V_2 ) )
F_2 ( V_606 , 125000 ) ;
else
F_2 ( V_606 , 50000 ) ;
F_2 ( V_619 , 150000 ) ;
F_2 ( V_620 , 64000 ) ;
V_614 = F_272 ( V_4 -> V_2 ) ;
if ( V_614 & V_587 )
V_598 |= V_583 ;
if ( ! F_60 ( V_2 ) ) {
if ( V_614 & V_588 )
V_598 |= V_584 ;
if ( V_614 & V_589 )
V_598 |= V_585 ;
}
F_267 ( V_2 , V_598 ) ;
F_2 ( V_580 ,
V_598 |
F_268 ( 1 ) |
V_607 ) ;
F_2 ( V_609 , 50000 ) ;
F_2 ( V_610 , 10 ) ;
V_298 = F_280 ( V_4 , V_621 , 0 ) ;
if ( V_298 )
F_71 ( L_79 ) ;
V_298 = F_142 ( V_4 , V_622 , & V_612 ) ;
if ( ! V_298 && ( V_612 & ( 1 << 31 ) ) ) {
F_71 ( L_80 ,
( V_4 -> V_336 . V_541 & 0xff ) * 50 ,
( V_612 & 0xff ) * 50 ) ;
V_4 -> V_336 . V_594 = V_612 & 0xff ;
}
V_4 -> V_336 . V_544 = V_550 ;
F_249 ( V_4 -> V_2 , V_4 -> V_336 . V_542 ) ;
V_611 = 0 ;
V_298 = F_142 ( V_4 , V_623 , & V_611 ) ;
if ( F_29 ( V_2 ) && V_298 ) {
F_71 ( L_81 ) ;
} else if ( F_29 ( V_2 ) && ( F_281 ( V_611 & 0xff ) < 450 ) ) {
F_71 ( L_82 ,
F_281 ( V_611 & 0xff ) , 450 ) ;
V_611 &= 0xffff00 ;
V_611 |= F_282 ( 450 ) ;
V_298 = F_280 ( V_4 , V_624 , V_611 ) ;
if ( V_298 )
F_49 ( L_83 ) ;
}
F_25 ( V_4 , V_581 ) ;
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_593 = 15 ;
unsigned int V_625 ;
unsigned int V_626 , V_627 ;
int V_628 = 180 ;
struct V_629 * V_630 ;
F_163 ( ! F_226 ( & V_4 -> V_336 . V_337 ) ) ;
V_630 = F_284 ( 0 ) ;
if ( V_630 ) {
V_626 = V_630 -> V_631 . V_594 ;
F_285 ( V_630 ) ;
} else {
V_626 = V_632 ;
}
V_626 /= 1000 ;
V_627 = F_3 ( V_633 ) & 0xf ;
V_627 = F_286 ( V_627 , 8 , 3 ) ;
for ( V_625 = V_4 -> V_336 . V_594 ; V_625 >= V_4 -> V_336 . V_593 ;
V_625 -- ) {
int V_634 = V_4 -> V_336 . V_594 - V_625 ;
unsigned int V_635 = 0 , V_636 = 0 ;
if ( F_59 ( V_2 ) -> V_112 >= 8 ) {
V_636 = F_91 ( V_627 , V_625 ) ;
} else if ( F_60 ( V_2 ) ) {
V_636 = F_286 ( V_625 , 5 , 4 ) ;
V_636 = F_91 ( V_627 , V_636 ) ;
} else {
if ( V_625 < V_593 )
V_635 = 800 ;
else
V_635 = V_626 - ( ( V_634 * V_628 ) / 2 ) ;
V_635 = F_135 ( V_635 , 100 ) ;
}
F_280 ( V_4 ,
V_621 ,
V_635 << V_637 |
V_636 << V_638 |
V_625 ) ;
}
}
void F_287 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_59 ( V_2 ) -> V_112 < 6 || F_75 ( V_2 ) )
return;
F_42 ( & V_4 -> V_336 . V_337 ) ;
F_283 ( V_2 ) ;
F_43 ( & V_4 -> V_336 . V_337 ) ;
}
static int F_288 ( struct V_3 * V_4 )
{
T_1 V_156 , V_639 ;
V_156 = F_258 ( V_4 , V_640 ) ;
V_639 = ( V_156 >> V_641 ) & V_642 ;
return V_639 ;
}
static int F_289 ( struct V_3 * V_4 )
{
T_1 V_156 , V_643 ;
V_156 = F_258 ( V_4 , V_644 ) ;
V_643 = ( V_156 >> V_645 ) & V_646 ;
return V_643 ;
}
static int F_290 ( struct V_3 * V_4 )
{
T_1 V_156 , V_647 ;
V_156 = F_258 ( V_4 , V_578 ) ;
V_647 = ( V_156 >> V_641 ) & V_642 ;
return V_647 ;
}
static int F_291 ( struct V_3 * V_4 )
{
T_1 V_156 , V_648 ;
V_156 = F_258 ( V_4 , V_640 ) ;
V_648 = ( V_156 >> V_649 ) & V_650 ;
return V_648 ;
}
static int F_292 ( struct V_3 * V_4 )
{
T_1 V_156 , V_647 ;
V_156 = F_293 ( V_4 , V_651 ) ;
V_647 = ( V_156 & V_652 ) >> V_653 ;
return V_647 ;
}
static int F_294 ( struct V_3 * V_4 )
{
T_1 V_156 , V_639 ;
V_156 = F_293 ( V_4 , V_651 ) ;
V_639 = ( V_156 & V_654 ) >> V_655 ;
V_639 = F_132 ( T_1 , V_639 , 0xea ) ;
return V_639 ;
}
static int F_295 ( struct V_3 * V_4 )
{
T_1 V_156 , V_643 ;
V_156 = F_293 ( V_4 , V_656 ) ;
V_643 = ( V_156 & V_657 ) >> V_658 ;
V_156 = F_293 ( V_4 , V_659 ) ;
V_643 |= ( V_156 & V_660 ) << 5 ;
return V_643 ;
}
static int F_296 ( struct V_3 * V_4 )
{
return F_258 ( V_4 , V_661 ) & 0xff ;
}
static void F_297 ( struct V_3 * V_4 )
{
unsigned long V_662 = F_3 ( V_663 ) & ~ 4095 ;
F_163 ( V_662 != V_4 -> V_664 . V_665 +
V_4 -> V_666 -> V_667 -> V_419 ) ;
}
static void F_298 ( struct V_3 * V_4 )
{
unsigned long V_662 = F_3 ( V_663 ) & ~ 4095 ;
F_163 ( ( V_662 >> V_668 ) == 0 ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_669 , V_670 ;
struct V_671 * V_672 = & V_4 -> V_672 ;
T_1 V_673 ;
int V_674 = 32 * 1024 ;
F_163 ( ! F_226 ( & V_2 -> V_82 ) ) ;
V_673 = F_3 ( V_663 ) ;
if ( ( V_673 >> V_668 ) == 0 ) {
F_71 ( L_84 ) ;
V_670 = ( V_4 -> V_664 . V_665 +
( V_672 -> V_675 - V_674 ) ) ;
V_669 = ( V_670 & ( ~ 4095 ) ) ;
F_2 ( V_663 , V_669 ) ;
}
F_71 ( L_85 , F_3 ( V_663 ) ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_24 * V_676 ;
unsigned long V_669 ;
T_1 V_673 ;
int V_674 = 24 * 1024 ;
F_163 ( ! F_226 ( & V_2 -> V_82 ) ) ;
V_673 = F_3 ( V_663 ) ;
if ( V_673 ) {
int V_677 ;
V_677 = ( V_673 & ( ~ 4095 ) ) - V_4 -> V_664 . V_665 ;
V_676 = F_301 ( V_4 -> V_2 ,
V_677 ,
V_678 ,
V_674 ) ;
goto V_679;
}
F_71 ( L_84 ) ;
V_676 = F_302 ( V_2 , V_674 ) ;
if ( ! V_676 ) {
F_228 ( L_86 ) ;
return;
}
V_669 = V_4 -> V_664 . V_665 + V_676 -> V_667 -> V_419 ;
F_2 ( V_663 , V_669 ) ;
V_679:
F_71 ( L_85 , F_3 ( V_663 ) ) ;
V_4 -> V_666 = V_676 ;
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_163 ( ! V_4 -> V_666 ) )
return;
F_232 ( & V_4 -> V_666 -> V_87 ) ;
V_4 -> V_666 = NULL ;
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_156 ;
F_300 ( V_2 ) ;
F_42 ( & V_4 -> V_336 . V_337 ) ;
V_156 = F_258 ( V_4 , V_578 ) ;
switch ( ( V_156 >> 6 ) & 3 ) {
case 0 :
case 1 :
V_4 -> V_136 = 800 ;
break;
case 2 :
V_4 -> V_136 = 1066 ;
break;
case 3 :
V_4 -> V_136 = 1333 ;
break;
}
F_71 ( L_87 , V_4 -> V_136 ) ;
V_4 -> V_336 . V_594 = F_294 ( V_4 ) ;
V_4 -> V_336 . V_549 = V_4 -> V_336 . V_594 ;
F_71 ( L_88 ,
F_262 ( V_4 , V_4 -> V_336 . V_594 ) ,
V_4 -> V_336 . V_594 ) ;
V_4 -> V_336 . V_546 = F_295 ( V_4 ) ;
F_71 ( L_89 ,
F_262 ( V_4 , V_4 -> V_336 . V_546 ) ,
V_4 -> V_336 . V_546 ) ;
V_4 -> V_336 . V_551 = F_292 ( V_4 ) ;
F_71 ( L_90 ,
F_262 ( V_4 , V_4 -> V_336 . V_551 ) ,
V_4 -> V_336 . V_551 ) ;
V_4 -> V_336 . V_593 = F_296 ( V_4 ) ;
F_71 ( L_91 ,
F_262 ( V_4 , V_4 -> V_336 . V_593 ) ,
V_4 -> V_336 . V_593 ) ;
if ( V_4 -> V_336 . V_541 == 0 )
V_4 -> V_336 . V_541 = V_4 -> V_336 . V_594 ;
if ( V_4 -> V_336 . V_542 == 0 )
V_4 -> V_336 . V_542 = V_4 -> V_336 . V_593 ;
F_43 ( & V_4 -> V_336 . V_337 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_156 ;
F_299 ( V_2 ) ;
F_42 ( & V_4 -> V_336 . V_337 ) ;
F_42 ( & V_4 -> V_680 ) ;
V_156 = F_306 ( V_4 , V_681 ) ;
F_43 ( & V_4 -> V_680 ) ;
switch ( ( V_156 >> 2 ) & 0x7 ) {
case 0 :
case 1 :
V_4 -> V_336 . V_682 = 200 ;
V_4 -> V_136 = 1600 ;
break;
case 2 :
V_4 -> V_336 . V_682 = 267 ;
V_4 -> V_136 = 1600 ;
break;
case 3 :
V_4 -> V_336 . V_682 = 333 ;
V_4 -> V_136 = 2000 ;
break;
case 4 :
V_4 -> V_336 . V_682 = 320 ;
V_4 -> V_136 = 1600 ;
break;
case 5 :
V_4 -> V_336 . V_682 = 400 ;
V_4 -> V_136 = 1600 ;
break;
}
F_71 ( L_87 , V_4 -> V_136 ) ;
V_4 -> V_336 . V_594 = F_288 ( V_4 ) ;
V_4 -> V_336 . V_549 = V_4 -> V_336 . V_594 ;
F_71 ( L_88 ,
F_262 ( V_4 , V_4 -> V_336 . V_594 ) ,
V_4 -> V_336 . V_594 ) ;
V_4 -> V_336 . V_546 = F_289 ( V_4 ) ;
F_71 ( L_89 ,
F_262 ( V_4 , V_4 -> V_336 . V_546 ) ,
V_4 -> V_336 . V_546 ) ;
V_4 -> V_336 . V_551 = F_290 ( V_4 ) ;
F_71 ( L_92 ,
F_262 ( V_4 , V_4 -> V_336 . V_551 ) ,
V_4 -> V_336 . V_551 ) ;
V_4 -> V_336 . V_593 = F_291 ( V_4 ) ;
F_71 ( L_91 ,
F_262 ( V_4 , V_4 -> V_336 . V_593 ) ,
V_4 -> V_336 . V_593 ) ;
F_261 ( ( V_4 -> V_336 . V_594 |
V_4 -> V_336 . V_546 |
V_4 -> V_336 . V_551 |
V_4 -> V_336 . V_593 ) & 1 ,
L_93 ) ;
if ( V_4 -> V_336 . V_541 == 0 )
V_4 -> V_336 . V_541 = V_4 -> V_336 . V_594 ;
if ( V_4 -> V_336 . V_542 == 0 )
V_4 -> V_336 . V_542 = V_4 -> V_336 . V_593 ;
F_43 ( & V_4 -> V_336 . V_337 ) ;
}
static void F_307 ( struct V_1 * V_2 )
{
F_303 ( V_2 ) ;
}
static void F_308 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_596 * V_597 ;
T_1 V_613 , V_156 , V_614 = 0 , V_673 ;
int V_28 ;
F_163 ( ! F_226 ( & V_4 -> V_336 . V_337 ) ) ;
V_613 = F_3 ( V_615 ) ;
if ( V_613 ) {
F_71 ( L_78 ,
V_613 ) ;
F_2 ( V_615 , V_613 ) ;
}
F_298 ( V_4 ) ;
F_23 ( V_4 , V_581 ) ;
F_2 ( V_601 , 40 << 16 ) ;
F_2 ( V_602 , 125000 ) ;
F_2 ( V_603 , 25 ) ;
F_275 (ring, dev_priv, i)
F_2 ( F_276 ( V_597 -> V_604 ) , 10 ) ;
F_2 ( V_605 , 0 ) ;
F_2 ( V_606 , 50000 ) ;
F_2 ( V_683 ,
F_4 ( V_684 |
V_685 |
V_686 ) ) ;
V_673 = F_3 ( V_663 ) ;
if ( ( F_272 ( V_2 ) & V_587 ) &&
( V_673 >> V_668 ) )
V_614 = F_268 ( 1 ) ;
F_2 ( V_580 , V_614 ) ;
F_2 ( V_553 , 59400 ) ;
F_2 ( V_555 , 245000 ) ;
F_2 ( V_552 , 66000 ) ;
F_2 ( V_554 , 350000 ) ;
F_2 ( V_610 , 10 ) ;
F_2 ( 0xA80C , F_3 ( 0xA80C ) & 0x00ffffff ) ;
F_2 ( 0xA810 , F_3 ( 0xA810 ) & 0xffffff00 ) ;
F_2 ( V_556 ,
V_558 |
V_559 |
V_560 |
V_561 |
V_562 ) ;
V_156 = F_258 ( V_4 , V_578 ) ;
F_261 ( ( V_156 & V_687 ) == 0 , L_94 ) ;
F_71 ( L_95 , V_156 & V_687 ? L_96 : L_97 ) ;
F_71 ( L_98 , V_156 ) ;
V_4 -> V_336 . V_547 = ( V_156 >> 8 ) & 0xff ;
F_71 ( L_99 ,
F_262 ( V_4 , V_4 -> V_336 . V_547 ) ,
V_4 -> V_336 . V_547 ) ;
F_71 ( L_100 ,
F_262 ( V_4 , V_4 -> V_336 . V_546 ) ,
V_4 -> V_336 . V_546 ) ;
F_255 ( V_4 -> V_2 , V_4 -> V_336 . V_546 ) ;
F_25 ( V_4 , V_581 ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_596 * V_597 ;
T_1 V_613 , V_156 , V_614 = 0 ;
int V_28 ;
F_163 ( ! F_226 ( & V_4 -> V_336 . V_337 ) ) ;
F_297 ( V_4 ) ;
if ( ( V_613 = F_3 ( V_615 ) ) ) {
F_71 ( L_78 ,
V_613 ) ;
F_2 ( V_615 , V_613 ) ;
}
F_23 ( V_4 , V_581 ) ;
F_2 ( V_553 , 59400 ) ;
F_2 ( V_555 , 245000 ) ;
F_2 ( V_552 , 66000 ) ;
F_2 ( V_554 , 350000 ) ;
F_2 ( V_610 , 10 ) ;
F_2 ( V_609 , 0xf4240 ) ;
F_2 ( V_556 ,
V_557 |
V_558 |
V_559 |
V_560 |
V_561 |
V_688 ) ;
F_2 ( V_601 , 0x00280000 ) ;
F_2 ( V_602 , 125000 ) ;
F_2 ( V_603 , 25 ) ;
F_275 (ring, dev_priv, i)
F_2 ( F_276 ( V_597 -> V_604 ) , 10 ) ;
F_2 ( V_606 , 0x557 ) ;
F_2 ( V_683 ,
F_4 ( V_689 |
V_690 |
V_685 |
V_686 ) ) ;
if ( F_272 ( V_2 ) & V_587 )
V_614 = V_582 | V_691 ;
F_267 ( V_2 , V_614 ) ;
F_2 ( V_580 , V_614 ) ;
V_156 = F_258 ( V_4 , V_578 ) ;
F_261 ( ( V_156 & V_687 ) == 0 , L_94 ) ;
F_71 ( L_95 , V_156 & V_687 ? L_96 : L_97 ) ;
F_71 ( L_98 , V_156 ) ;
V_4 -> V_336 . V_547 = ( V_156 >> 8 ) & 0xff ;
F_71 ( L_99 ,
F_262 ( V_4 , V_4 -> V_336 . V_547 ) ,
V_4 -> V_336 . V_547 ) ;
F_71 ( L_100 ,
F_262 ( V_4 , V_4 -> V_336 . V_546 ) ,
V_4 -> V_336 . V_546 ) ;
F_255 ( V_4 -> V_2 , V_4 -> V_336 . V_546 ) ;
F_25 ( V_4 , V_581 ) ;
}
void F_310 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_146 . V_692 ) {
F_231 ( V_4 -> V_146 . V_692 ) ;
F_232 ( & V_4 -> V_146 . V_692 -> V_87 ) ;
V_4 -> V_146 . V_692 = NULL ;
}
if ( V_4 -> V_146 . V_693 ) {
F_231 ( V_4 -> V_146 . V_693 ) ;
F_232 ( & V_4 -> V_146 . V_693 -> V_87 ) ;
V_4 -> V_146 . V_693 = NULL ;
}
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_694 ) ) {
F_2 ( V_695 , F_3 ( V_695 ) | V_696 ) ;
F_6 ( ( ( F_3 ( V_695 ) & V_697 ) == V_698 ) ,
50 ) ;
F_2 ( V_694 , 0 ) ;
F_24 ( V_694 ) ;
F_2 ( V_695 , F_3 ( V_695 ) & ~ V_696 ) ;
F_24 ( V_695 ) ;
}
}
static int F_312 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_146 . V_692 == NULL )
V_4 -> V_146 . V_692 = F_225 ( V_2 ) ;
if ( ! V_4 -> V_146 . V_692 )
return - V_699 ;
if ( V_4 -> V_146 . V_693 == NULL )
V_4 -> V_146 . V_693 = F_225 ( V_2 ) ;
if ( ! V_4 -> V_146 . V_693 ) {
F_310 ( V_2 ) ;
return - V_699 ;
}
return 0 ;
}
static void F_313 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_596 * V_597 = & V_4 -> V_597 [ V_700 ] ;
bool V_701 ;
int V_298 ;
if ( ! F_272 ( V_2 ) )
return;
F_163 ( ! F_226 ( & V_2 -> V_82 ) ) ;
V_298 = F_312 ( V_2 ) ;
if ( V_298 )
return;
V_701 = V_4 -> V_664 . V_702 ;
V_4 -> V_664 . V_702 = false ;
V_298 = F_314 ( V_597 , 6 ) ;
if ( V_298 ) {
F_310 ( V_2 ) ;
V_4 -> V_664 . V_702 = V_701 ;
return;
}
F_315 ( V_597 , V_703 | V_704 ) ;
F_315 ( V_597 , V_705 ) ;
F_315 ( V_597 , F_28 ( V_4 -> V_146 . V_692 ) |
V_706 |
V_707 |
V_708 |
V_709 ) ;
F_315 ( V_597 , V_703 ) ;
F_315 ( V_597 , V_710 ) ;
F_315 ( V_597 , V_711 ) ;
F_316 ( V_597 ) ;
V_298 = F_317 ( V_597 ) ;
V_4 -> V_664 . V_702 = V_701 ;
if ( V_298 ) {
F_49 ( L_101 ) ;
F_310 ( V_2 ) ;
return;
}
F_2 ( V_694 , F_28 ( V_4 -> V_146 . V_693 ) | V_712 ) ;
F_2 ( V_695 , F_3 ( V_695 ) & ~ V_696 ) ;
F_267 ( V_2 , V_583 ) ;
}
static unsigned long F_318 ( T_1 V_713 )
{
unsigned long V_714 ;
int div = ( V_713 & 0x3f0000 ) >> 16 ;
int V_715 = ( V_713 & 0x3000 ) >> 12 ;
int V_716 = ( V_713 & 0x7 ) ;
if ( ! V_716 )
return 0 ;
V_714 = ( ( div * 133333 ) / ( ( 1 << V_715 ) * V_716 ) ) ;
return V_714 ;
}
static unsigned long F_319 ( struct V_3 * V_4 )
{
T_8 V_717 , V_634 , V_298 ;
T_1 V_718 , V_719 , V_720 , V_721 = 0 , V_722 = 0 ;
unsigned long V_723 = F_241 ( V_531 ) , V_724 ;
int V_28 ;
F_234 ( & V_491 ) ;
V_724 = V_723 - V_4 -> V_146 . V_530 ;
if ( V_724 <= 10 )
return V_4 -> V_146 . V_725 ;
V_718 = F_3 ( V_726 ) ;
V_719 = F_3 ( V_727 ) ;
V_720 = F_3 ( V_728 ) ;
V_717 = V_718 + V_719 + V_720 ;
if ( V_717 < V_4 -> V_146 . V_529 ) {
V_634 = ~ 0UL - V_4 -> V_146 . V_529 ;
V_634 += V_717 ;
} else {
V_634 = V_717 - V_4 -> V_146 . V_529 ;
}
for ( V_28 = 0 ; V_28 < F_73 ( V_729 ) ; V_28 ++ ) {
if ( V_729 [ V_28 ] . V_28 == V_4 -> V_146 . V_148 &&
V_729 [ V_28 ] . V_730 == V_4 -> V_146 . V_147 ) {
V_721 = V_729 [ V_28 ] . V_721 ;
V_722 = V_729 [ V_28 ] . V_722 ;
break;
}
}
V_634 = F_114 ( V_634 , V_724 ) ;
V_298 = ( ( V_721 * V_634 ) + V_722 ) ;
V_298 = F_114 ( V_298 , 10 ) ;
V_4 -> V_146 . V_529 = V_717 ;
V_4 -> V_146 . V_530 = V_723 ;
V_4 -> V_146 . V_725 = V_298 ;
return V_298 ;
}
unsigned long F_320 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_156 ;
if ( F_59 ( V_2 ) -> V_112 != 5 )
return 0 ;
F_238 ( & V_491 ) ;
V_156 = F_319 ( V_4 ) ;
F_243 ( & V_491 ) ;
return V_156 ;
}
unsigned long F_321 ( struct V_3 * V_4 )
{
unsigned long V_721 , V_731 , V_732 ;
T_1 V_733 ;
V_733 = F_3 ( V_734 ) ;
V_721 = ( ( V_733 & V_735 ) >> V_736 ) ;
V_731 = F_322 ( V_737 ) ;
V_732 = V_733 & V_738 ;
return ( ( V_721 * V_731 ) / 127 ) - V_732 ;
}
static T_2 F_323 ( struct V_3 * V_4 , T_7 V_739 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
static const struct V_740 {
T_2 V_741 ;
T_2 V_742 ;
} V_740 [] = {
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
if ( F_59 ( V_2 ) -> V_743 )
return V_740 [ V_739 ] . V_742 ;
else
return V_740 [ V_739 ] . V_741 ;
}
static void F_324 ( struct V_3 * V_4 )
{
T_8 V_723 , V_634 , V_744 ;
T_1 V_745 ;
F_234 ( & V_491 ) ;
V_723 = F_242 () ;
V_744 = V_723 - V_4 -> V_146 . V_533 ;
F_325 ( V_744 , V_746 ) ;
if ( ! V_744 )
return;
V_745 = F_3 ( V_747 ) ;
if ( V_745 < V_4 -> V_146 . V_532 ) {
V_634 = ~ 0UL - V_4 -> V_146 . V_532 ;
V_634 += V_745 ;
} else {
V_634 = V_745 - V_4 -> V_146 . V_532 ;
}
V_4 -> V_146 . V_532 = V_745 ;
V_4 -> V_146 . V_533 = V_723 ;
V_634 = V_634 * 1181 ;
V_634 = F_114 ( V_634 , V_744 * 10 ) ;
V_4 -> V_146 . V_748 = V_634 ;
}
void F_326 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_59 ( V_2 ) -> V_112 != 5 )
return;
F_238 ( & V_491 ) ;
F_324 ( V_4 ) ;
F_243 ( & V_491 ) ;
}
static unsigned long F_327 ( struct V_3 * V_4 )
{
unsigned long V_730 , V_749 , V_750 , V_751 , V_752 ;
T_1 V_739 , V_753 ;
F_234 ( & V_491 ) ;
V_739 = F_3 ( V_518 + ( V_4 -> V_336 . V_547 * 4 ) ) ;
V_739 = ( V_739 >> 24 ) & 0x7f ;
V_753 = F_323 ( V_4 , V_739 ) ;
V_750 = V_753 ;
V_730 = F_321 ( V_4 ) ;
if ( V_730 > 80 )
V_749 = ( ( V_730 * 2349 ) + 135940 ) ;
else if ( V_730 >= 50 )
V_749 = ( ( V_730 * 964 ) + 29317 ) ;
else
V_749 = ( ( V_730 * 301 ) + 1004 ) ;
V_749 = V_749 * ( ( 150142 * V_750 ) / 10000 - 78642 ) ;
V_749 /= 100000 ;
V_751 = ( V_749 * V_4 -> V_146 . V_749 ) ;
V_752 = ( V_751 * V_750 ) / 10000 ;
V_752 /= 100 ;
F_324 ( V_4 ) ;
return V_4 -> V_146 . V_748 + V_752 ;
}
unsigned long F_328 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_156 ;
if ( F_59 ( V_2 ) -> V_112 != 5 )
return 0 ;
F_238 ( & V_491 ) ;
V_156 = F_327 ( V_4 ) ;
F_243 ( & V_491 ) ;
return V_156 ;
}
unsigned long F_329 ( void )
{
struct V_3 * V_4 ;
unsigned long V_754 , V_755 , V_298 = 0 ;
F_238 ( & V_491 ) ;
if ( ! V_756 )
goto V_757;
V_4 = V_756 ;
V_754 = F_319 ( V_4 ) ;
V_755 = F_327 ( V_4 ) ;
V_298 = V_754 + V_755 ;
V_757:
F_243 ( & V_491 ) ;
return V_298 ;
}
bool F_330 ( void )
{
struct V_3 * V_4 ;
bool V_298 = true ;
F_238 ( & V_491 ) ;
if ( ! V_756 ) {
V_298 = false ;
goto V_757;
}
V_4 = V_756 ;
if ( V_4 -> V_146 . V_521 > V_4 -> V_146 . V_500 )
V_4 -> V_146 . V_521 -- ;
V_757:
F_243 ( & V_491 ) ;
return V_298 ;
}
bool F_331 ( void )
{
struct V_3 * V_4 ;
bool V_298 = true ;
F_238 ( & V_491 ) ;
if ( ! V_756 ) {
V_298 = false ;
goto V_757;
}
V_4 = V_756 ;
if ( V_4 -> V_146 . V_521 < V_4 -> V_146 . V_522 )
V_4 -> V_146 . V_521 ++ ;
V_757:
F_243 ( & V_491 ) ;
return V_298 ;
}
bool F_332 ( void )
{
struct V_3 * V_4 ;
struct V_596 * V_597 ;
bool V_298 = false ;
int V_28 ;
F_238 ( & V_491 ) ;
if ( ! V_756 )
goto V_757;
V_4 = V_756 ;
F_275 (ring, dev_priv, i)
V_298 |= ! F_333 ( & V_597 -> V_758 ) ;
V_757:
F_243 ( & V_491 ) ;
return V_298 ;
}
bool F_334 ( void )
{
struct V_3 * V_4 ;
bool V_298 = true ;
F_238 ( & V_491 ) ;
if ( ! V_756 ) {
V_298 = false ;
goto V_757;
}
V_4 = V_756 ;
V_4 -> V_146 . V_521 = V_4 -> V_146 . V_502 ;
if ( ! F_233 ( V_4 -> V_2 , V_4 -> V_146 . V_502 ) )
V_298 = false ;
V_757:
F_243 ( & V_491 ) ;
return V_298 ;
}
static void
F_335 ( void )
{
void (* F_336)( void );
F_336 = F_337 ( V_759 ) ;
if ( F_336 ) {
F_336 () ;
F_338 ( V_759 ) ;
}
}
void F_339 ( struct V_3 * V_4 )
{
F_238 ( & V_491 ) ;
V_756 = V_4 ;
F_243 ( & V_491 ) ;
F_335 () ;
}
void F_340 ( void )
{
F_238 ( & V_491 ) ;
V_756 = NULL ;
F_243 ( & V_491 ) ;
}
static void F_341 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_760 ;
T_7 V_761 [ 16 ] ;
int V_28 ;
F_2 ( V_762 , 0 ) ;
F_24 ( V_762 ) ;
F_2 ( V_763 , 0x15040d00 ) ;
F_2 ( V_764 , 0x007f0000 ) ;
F_2 ( V_765 , 0x1e220004 ) ;
F_2 ( V_766 , 0x04000004 ) ;
for ( V_28 = 0 ; V_28 < 5 ; V_28 ++ )
F_2 ( V_767 + ( V_28 * 4 ) , 0 ) ;
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ )
F_2 ( V_768 + ( V_28 * 4 ) , 0 ) ;
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ ) {
T_1 V_769 = F_3 ( V_518 + ( V_28 * 4 ) ) ;
unsigned long V_714 = F_318 ( V_769 ) ;
unsigned long V_770 = ( V_769 & V_519 ) >>
V_520 ;
unsigned long V_156 ;
V_156 = V_770 * V_770 ;
V_156 *= ( V_714 / 1000 ) ;
V_156 *= 255 ;
V_156 /= ( 127 * 127 * 900 ) ;
if ( V_156 > 0xff )
F_49 ( L_102 , V_156 ) ;
V_761 [ V_28 ] = V_156 ;
}
V_761 [ 14 ] = 0 ;
V_761 [ 15 ] = 0 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
T_1 V_156 = ( V_761 [ V_28 * 4 ] << 24 ) | ( V_761 [ ( V_28 * 4 ) + 1 ] << 16 ) |
( V_761 [ ( V_28 * 4 ) + 2 ] << 8 ) | ( V_761 [ ( V_28 * 4 ) + 3 ] ) ;
F_2 ( V_771 + ( V_28 * 4 ) , V_156 ) ;
}
F_2 ( V_772 , 0 ) ;
F_2 ( V_773 , 0 ) ;
F_2 ( V_774 , 0x00007f00 ) ;
F_2 ( V_775 , 0x0000000e ) ;
F_2 ( V_776 , 0x000e0000 ) ;
F_2 ( V_777 , 0x68000300 ) ;
F_2 ( V_778 , 0x42000000 ) ;
F_2 ( V_779 , 0x00140031 ) ;
F_2 ( V_780 , 0 ) ;
F_2 ( V_781 , 0 ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
F_2 ( V_782 + ( V_28 * 4 ) , 0 ) ;
F_2 ( V_762 , 0x80000019 ) ;
V_760 = F_3 ( V_783 ) ;
V_4 -> V_146 . V_749 = ( V_760 & V_784 ) ;
}
void F_342 ( struct V_1 * V_2 )
{
V_99 . V_586 = F_270 ( V_2 , V_99 . V_586 ) ;
if ( F_97 ( V_2 ) )
F_305 ( V_2 ) ;
else if ( F_75 ( V_2 ) )
F_304 ( V_2 ) ;
}
void F_343 ( struct V_1 * V_2 )
{
if ( F_97 ( V_2 ) )
return;
else if ( F_75 ( V_2 ) )
F_307 ( V_2 ) ;
}
static void F_344 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_345 ( & V_4 -> V_336 . V_785 ) ;
if ( F_59 ( V_2 ) -> V_112 < 9 )
F_346 ( V_2 ) ;
}
void F_347 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_59 ( V_2 ) -> V_112 < 6 )
return;
F_344 ( V_2 ) ;
F_259 ( V_4 ) ;
}
void F_348 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_271 ( V_2 ) ) {
F_244 ( V_2 ) ;
F_311 ( V_2 ) ;
} else if ( F_59 ( V_2 ) -> V_112 >= 6 ) {
F_347 ( V_2 ) ;
F_42 ( & V_4 -> V_336 . V_337 ) ;
if ( F_59 ( V_2 ) -> V_112 >= 9 )
F_263 ( V_2 ) ;
else if ( F_97 ( V_2 ) )
F_265 ( V_2 ) ;
else if ( F_75 ( V_2 ) )
F_266 ( V_2 ) ;
else
F_264 ( V_2 ) ;
V_4 -> V_336 . V_14 = false ;
F_43 ( & V_4 -> V_336 . V_337 ) ;
}
}
static void F_349 ( struct V_78 * V_81 )
{
struct V_3 * V_4 =
F_40 ( V_81 , struct V_3 ,
V_336 . V_785 . V_81 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_42 ( & V_4 -> V_336 . V_337 ) ;
if ( F_59 ( V_2 ) -> V_112 < 9 )
F_350 ( V_2 ) ;
if ( F_97 ( V_2 ) ) {
F_308 ( V_2 ) ;
} else if ( F_75 ( V_2 ) ) {
F_309 ( V_2 ) ;
} else if ( F_59 ( V_2 ) -> V_112 >= 9 ) {
F_274 ( V_2 ) ;
} else if ( F_143 ( V_2 ) ) {
F_278 ( V_2 ) ;
F_283 ( V_2 ) ;
} else {
F_279 ( V_2 ) ;
F_283 ( V_2 ) ;
}
V_4 -> V_336 . V_14 = true ;
if ( F_59 ( V_2 ) -> V_112 < 9 )
F_351 ( V_2 ) ;
F_43 ( & V_4 -> V_336 . V_337 ) ;
F_352 ( V_4 ) ;
}
void F_353 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_271 ( V_2 ) ) {
F_42 ( & V_2 -> V_82 ) ;
F_237 ( V_2 ) ;
F_313 ( V_2 ) ;
F_341 ( V_2 ) ;
F_43 ( & V_2 -> V_82 ) ;
} else if ( F_59 ( V_2 ) -> V_112 >= 6 ) {
if ( F_51 ( & V_4 -> V_336 . V_785 ,
F_354 ( V_786 ) ) )
F_355 ( V_4 ) ;
}
}
void F_356 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_59 ( V_2 ) -> V_112 < 6 )
return;
F_344 ( V_2 ) ;
V_4 -> V_336 . V_14 = false ;
}
static void F_357 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_787 , V_788 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_74 ;
F_166 (dev_priv, pipe) {
F_2 ( F_359 ( V_74 ) ,
F_3 ( F_359 ( V_74 ) ) |
V_789 ) ;
F_360 ( V_4 , V_74 ) ;
}
}
static void F_361 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_397 , F_3 ( V_397 ) & ~ V_376 ) ;
F_2 ( V_398 , F_3 ( V_398 ) & ~ V_376 ) ;
F_2 ( V_399 , F_3 ( V_399 ) & ~ V_376 ) ;
}
static void F_362 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_790 = V_791 ;
V_790 |= V_792 |
V_793 |
V_794 ;
F_2 ( V_795 ,
V_796 |
V_797 ) ;
F_2 ( V_798 ,
V_799 ) ;
F_2 ( V_800 ,
( F_3 ( V_800 ) |
V_801 | V_802 ) ) ;
V_790 |= V_803 ;
F_2 ( V_407 ,
( F_3 ( V_407 ) |
V_408 ) ) ;
F_361 ( V_2 ) ;
if ( F_271 ( V_2 ) ) {
F_2 ( V_72 ,
F_3 ( V_72 ) |
V_73 ) ;
F_2 ( V_800 ,
F_3 ( V_800 ) |
V_801 ) ;
}
F_2 ( V_804 , V_790 ) ;
F_2 ( V_800 ,
F_3 ( V_800 ) |
V_805 ) ;
F_2 ( V_806 ,
V_807 << 16 |
V_807 ) ;
F_2 ( V_808 ,
F_4 ( V_809 ) ) ;
F_2 ( V_808 , F_79 ( V_810 ) ) ;
F_358 ( V_2 ) ;
F_357 ( V_2 ) ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_74 ;
T_3 V_156 ;
F_2 ( V_787 , V_788 |
V_811 |
V_812 ) ;
F_2 ( V_813 , F_3 ( V_813 ) |
V_814 ) ;
F_166 (dev_priv, pipe) {
V_156 = F_3 ( F_364 ( V_74 ) ) ;
V_156 |= V_815 ;
V_156 &= ~ V_816 ;
if ( V_4 -> V_817 . V_818 )
V_156 |= V_816 ;
V_156 &= ~ V_819 ;
V_156 &= ~ V_820 ;
V_156 &= ~ V_821 ;
F_2 ( F_364 ( V_74 ) , V_156 ) ;
}
F_166 (dev_priv, pipe) {
F_2 ( F_365 ( V_74 ) ,
V_822 ) ;
}
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_126 ;
V_126 = F_3 ( V_344 ) ;
if ( ( V_126 & V_823 ) != V_824 )
F_7 ( L_103 ,
V_126 ) ;
}
static void F_367 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_790 = V_791 ;
F_2 ( V_804 , V_790 ) ;
F_2 ( V_800 ,
F_3 ( V_800 ) |
V_805 ) ;
F_2 ( V_825 ,
F_4 ( V_826 ) ) ;
F_2 ( V_808 , F_79 ( V_810 ) ) ;
F_2 ( V_827 ,
F_368 ( V_828 , V_829 ) ) ;
F_361 ( V_2 ) ;
F_2 ( V_808 ,
F_79 ( V_830 ) ) ;
F_2 ( V_831 ,
F_3 ( V_831 ) |
V_832 |
V_833 ) ;
F_2 ( V_834 ,
V_835 |
V_836 ) ;
F_2 ( V_837 ,
F_4 ( V_838 ) ) ;
F_2 ( V_837 ,
F_4 ( V_839 ) ) ;
F_2 ( V_72 ,
F_3 ( V_72 ) |
V_73 | V_840 ) ;
F_2 ( V_800 ,
F_3 ( V_800 ) |
V_801 | V_802 ) ;
F_2 ( V_804 ,
F_3 ( V_804 ) |
V_803 |
V_794 ) ;
F_358 ( V_2 ) ;
F_363 ( V_2 ) ;
F_366 ( V_2 ) ;
}
static void F_369 ( struct V_3 * V_4 )
{
T_3 V_182 = F_3 ( V_841 ) ;
V_182 &= ~ V_842 ;
V_182 |= V_843 ;
V_182 |= V_844 ;
V_182 |= V_845 ;
F_2 ( V_841 , V_182 ) ;
}
static void F_370 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_846 == V_847 )
F_2 ( V_787 ,
F_3 ( V_787 ) |
V_848 ) ;
F_2 ( V_849 ,
F_3 ( V_849 ) |
V_822 ) ;
}
static void F_371 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_846 == V_847 ) {
T_3 V_156 = F_3 ( V_787 ) ;
V_156 &= ~ V_848 ;
F_2 ( V_787 , V_156 ) ;
}
}
static void F_372 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_74 V_74 ;
F_2 ( V_397 , 0 ) ;
F_2 ( V_398 , 0 ) ;
F_2 ( V_399 , 0 ) ;
F_2 ( V_850 , F_3 ( V_850 ) | V_851 ) ;
F_2 ( V_852 ,
F_3 ( V_852 ) | V_853 ) ;
F_166 (dev_priv, pipe) {
F_2 ( F_35 ( V_74 ) ,
F_3 ( F_35 ( V_74 ) ) |
V_854 ) ;
}
F_2 ( V_841 ,
F_3 ( V_841 ) &
~ ( V_855 | V_856 ) ) ;
F_2 ( V_857 ,
F_4 ( V_858 ) ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
F_370 ( V_2 ) ;
}
static void F_373 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_361 ( V_2 ) ;
F_2 ( V_859 , V_860 ) ;
F_2 ( V_861 ,
F_4 ( V_862 ) ) ;
F_2 ( V_863 ,
F_3 ( V_863 ) |
V_864 ) ;
F_2 ( V_841 ,
F_3 ( V_841 ) & ~ V_856 ) ;
F_2 ( V_865 , F_79 ( V_810 ) ) ;
F_2 ( V_865 ,
F_79 ( V_866 ) ) ;
F_2 ( V_10 ,
F_4 ( V_867 ) ) ;
F_2 ( V_868 ,
F_368 ( V_828 , V_829 ) ) ;
F_2 ( V_850 , F_3 ( V_850 ) | V_851 ) ;
F_2 ( V_852 ,
F_3 ( V_852 ) | V_869 ) ;
F_370 ( V_2 ) ;
}
static void F_374 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_870 ;
F_361 ( V_2 ) ;
F_2 ( V_804 , V_791 ) ;
F_2 ( V_837 ,
F_4 ( V_871 ) ) ;
F_2 ( V_872 ,
V_873 |
V_874 ) ;
if ( F_375 ( V_2 ) )
F_2 ( V_875 ,
F_4 ( V_876 ) ) ;
F_2 ( V_865 , F_79 ( V_810 ) ) ;
F_2 ( V_877 ,
V_878 ) ;
F_2 ( V_879 ,
V_880 ) ;
F_2 ( V_881 ,
V_882 ) ;
if ( F_375 ( V_2 ) )
F_2 ( V_883 ,
F_4 ( V_884 ) ) ;
else {
F_2 ( V_883 ,
F_4 ( V_884 ) ) ;
F_2 ( V_885 ,
F_4 ( V_884 ) ) ;
}
F_2 ( V_886 , F_3 ( V_886 ) &
~ V_887 ) ;
F_2 ( V_834 ,
V_888 ) ;
F_2 ( V_863 ,
F_3 ( V_863 ) |
V_864 ) ;
F_358 ( V_2 ) ;
F_369 ( V_4 ) ;
if ( 0 ) {
F_2 ( V_865 ,
F_79 ( V_866 ) ) ;
}
F_2 ( V_10 ,
F_4 ( V_867 ) ) ;
F_2 ( V_868 ,
F_368 ( V_828 , V_829 ) ) ;
V_870 = F_3 ( V_889 ) ;
V_870 &= ~ V_890 ;
V_870 |= V_891 ;
F_2 ( V_889 , V_870 ) ;
if ( ! F_376 ( V_2 ) )
F_363 ( V_2 ) ;
F_366 ( V_2 ) ;
}
static void F_377 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_892 , V_893 ) ;
F_2 ( V_837 ,
F_4 ( V_871 ) ) ;
F_2 ( V_872 ,
V_873 |
V_874 ) ;
F_2 ( V_875 ,
F_4 ( V_894 |
V_876 ) ) ;
F_2 ( V_865 , F_79 ( V_810 ) ) ;
F_2 ( V_886 , F_3 ( V_886 ) &
~ V_887 ) ;
F_2 ( V_883 ,
F_4 ( V_884 ) ) ;
F_2 ( V_863 ,
F_3 ( V_863 ) |
V_864 ) ;
F_369 ( V_4 ) ;
F_2 ( V_834 ,
V_888 ) ;
F_2 ( V_895 ,
F_3 ( V_895 ) | V_896 ) ;
F_2 ( V_897 , V_898 ) ;
F_2 ( V_10 ,
F_4 ( V_867 ) ) ;
F_2 ( V_899 , V_900 ) ;
F_2 ( V_901 , V_902 ) ;
}
static void F_378 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_892 , V_893 ) ;
F_2 ( V_897 , V_898 ) ;
F_2 ( V_841 ,
F_3 ( V_841 ) &
~ ( V_855 | V_856 ) ) ;
F_2 ( V_857 ,
F_4 ( V_858 ) ) ;
F_2 ( V_831 , F_3 ( V_831 ) |
V_833 ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
}
static void F_379 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_790 ;
F_2 ( V_903 , 0 ) ;
F_2 ( V_904 , V_905 |
V_906 |
V_907 ) ;
F_2 ( V_908 , 0 ) ;
V_790 = V_893 |
V_909 |
V_910 ;
if ( F_380 ( V_2 ) )
V_790 |= V_911 ;
F_2 ( V_892 , V_790 ) ;
F_2 ( V_808 ,
F_4 ( V_809 ) ) ;
F_2 ( V_808 , F_79 ( V_810 ) ) ;
F_358 ( V_2 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_903 , V_912 ) ;
F_2 ( V_904 , 0 ) ;
F_2 ( V_892 , 0 ) ;
F_2 ( V_908 , 0 ) ;
F_235 ( V_913 , 0 ) ;
F_2 ( V_914 ,
F_4 ( V_898 ) ) ;
F_2 ( V_808 , F_79 ( V_810 ) ) ;
}
static void F_382 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_903 , V_915 |
V_912 |
V_916 |
V_917 |
V_918 ) ;
F_2 ( V_904 , 0 ) ;
F_2 ( V_914 ,
F_4 ( V_898 ) ) ;
F_2 ( V_808 , F_79 ( V_810 ) ) ;
}
static void F_383 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_919 = F_3 ( V_920 ) ;
V_919 |= V_921 | V_922 |
V_923 ;
F_2 ( V_920 , V_919 ) ;
if ( F_77 ( V_2 ) )
F_2 ( V_924 , F_4 ( V_925 ) ) ;
F_2 ( V_924 , F_79 ( V_926 ) ) ;
F_2 ( V_164 , F_4 ( V_927 ) ) ;
F_2 ( V_914 , F_4 ( V_928 ) ) ;
F_2 ( V_914 ,
F_4 ( V_898 ) ) ;
}
static void F_384 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_903 , V_929 ) ;
F_2 ( V_930 , F_4 ( V_931 ) |
F_79 ( V_932 ) ) ;
F_2 ( V_933 ,
F_4 ( V_934 ) ) ;
}
static void F_385 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_892 , V_909 ) ;
F_2 ( V_933 ,
F_4 ( V_935 ) |
F_4 ( V_936 ) ) ;
}
void F_386 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_84 . V_937 ( V_2 ) ;
}
void F_387 ( struct V_1 * V_2 )
{
if ( F_388 ( V_2 ) )
F_371 ( V_2 ) ;
}
static void F_389 ( struct V_3 * V_4 )
{
if ( ! F_56 ( V_4 ) ) {
V_4 -> V_13 . V_14 = false ;
return;
}
if ( F_59 ( V_4 ) -> V_112 >= 7 ) {
V_4 -> V_84 . V_938 = F_31 ;
V_4 -> V_84 . V_85 = F_32 ;
V_4 -> V_84 . V_90 = F_30 ;
} else if ( F_59 ( V_4 ) -> V_112 >= 5 ) {
V_4 -> V_84 . V_938 = F_31 ;
V_4 -> V_84 . V_85 = F_26 ;
V_4 -> V_84 . V_90 = F_30 ;
} else if ( F_380 ( V_4 ) ) {
V_4 -> V_84 . V_938 = F_21 ;
V_4 -> V_84 . V_85 = F_17 ;
V_4 -> V_84 . V_90 = F_20 ;
} else {
V_4 -> V_84 . V_938 = F_16 ;
V_4 -> V_84 . V_85 = F_8 ;
V_4 -> V_84 . V_90 = F_5 ;
F_2 ( V_15 , 500 << V_41 ) ;
}
V_4 -> V_13 . V_14 = V_4 -> V_84 . V_938 ( V_4 -> V_2 ) ;
}
void F_390 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_389 ( V_4 ) ;
if ( F_77 ( V_2 ) )
F_68 ( V_2 ) ;
else if ( F_27 ( V_2 ) )
F_69 ( V_2 ) ;
if ( F_59 ( V_2 ) -> V_112 >= 9 ) {
F_152 ( V_2 ) ;
V_4 -> V_84 . V_937 = F_1 ;
V_4 -> V_84 . V_485 = F_214 ;
V_4 -> V_84 . V_486 = F_215 ;
} else if ( F_391 ( V_2 ) ) {
F_151 ( V_2 ) ;
if ( ( F_27 ( V_2 ) && V_4 -> V_171 . V_328 [ 1 ] &&
V_4 -> V_171 . V_329 [ 1 ] && V_4 -> V_171 . V_330 [ 1 ] ) ||
( ! F_27 ( V_2 ) && V_4 -> V_171 . V_328 [ 0 ] &&
V_4 -> V_171 . V_329 [ 0 ] && V_4 -> V_171 . V_330 [ 0 ] ) ) {
V_4 -> V_84 . V_485 = F_216 ;
V_4 -> V_84 . V_486 = F_217 ;
} else {
F_7 ( L_104
L_105 ) ;
}
if ( F_27 ( V_2 ) )
V_4 -> V_84 . V_937 = F_362 ;
else if ( F_29 ( V_2 ) )
V_4 -> V_84 . V_937 = F_367 ;
else if ( F_34 ( V_2 ) )
V_4 -> V_84 . V_937 = F_374 ;
else if ( F_60 ( V_2 ) )
V_4 -> V_84 . V_937 = F_373 ;
else if ( F_59 ( V_2 ) -> V_112 == 8 )
V_4 -> V_84 . V_937 = F_372 ;
} else if ( F_97 ( V_2 ) ) {
V_4 -> V_84 . V_485 = F_103 ;
V_4 -> V_84 . V_486 = F_104 ;
V_4 -> V_84 . V_937 =
F_378 ;
} else if ( F_75 ( V_2 ) ) {
V_4 -> V_84 . V_485 = F_100 ;
V_4 -> V_84 . V_486 = F_104 ;
V_4 -> V_84 . V_937 =
F_377 ;
} else if ( F_77 ( V_2 ) ) {
if ( ! F_72 ( F_88 ( V_2 ) ,
V_4 -> V_140 ,
V_4 -> V_130 ,
V_4 -> V_136 ) ) {
F_277 ( L_106
L_107
L_108 ,
( V_4 -> V_140 == 1 ) ? L_109 : L_110 ,
V_4 -> V_130 , V_4 -> V_136 ) ;
F_74 ( V_4 , false ) ;
V_4 -> V_84 . V_485 = NULL ;
} else
V_4 -> V_84 . V_485 = F_87 ;
V_4 -> V_84 . V_937 = F_383 ;
} else if ( F_61 ( V_2 ) ) {
V_4 -> V_84 . V_485 = F_108 ;
V_4 -> V_84 . V_937 = F_379 ;
} else if ( F_12 ( V_2 ) ) {
V_4 -> V_84 . V_485 = F_109 ;
if ( F_76 ( V_2 ) )
V_4 -> V_84 . V_937 = F_381 ;
else if ( F_392 ( V_2 ) )
V_4 -> V_84 . V_937 = F_382 ;
} else if ( F_393 ( V_2 ) ) {
V_4 -> V_84 . V_485 = F_110 ;
V_4 -> V_84 . V_282 = F_81 ;
V_4 -> V_84 . V_937 = F_383 ;
} else if ( F_11 ( V_2 ) ) {
if ( F_59 ( V_2 ) -> V_320 == 1 ) {
V_4 -> V_84 . V_485 = F_112 ;
V_4 -> V_84 . V_282 = F_83 ;
} else {
V_4 -> V_84 . V_485 = F_110 ;
V_4 -> V_84 . V_282 = F_82 ;
}
if ( F_394 ( V_2 ) || F_395 ( V_2 ) )
V_4 -> V_84 . V_937 = F_384 ;
else
V_4 -> V_84 . V_937 = F_385 ;
} else {
F_49 ( L_111 ) ;
}
}
int F_142 ( struct V_3 * V_4 , T_1 V_939 , T_1 * V_156 )
{
F_163 ( ! F_226 ( & V_4 -> V_336 . V_337 ) ) ;
if ( F_3 ( V_940 ) & V_941 ) {
F_71 ( L_112 ) ;
return - V_942 ;
}
F_2 ( V_943 , * V_156 ) ;
F_2 ( V_944 , 0 ) ;
F_2 ( V_940 , V_941 | V_939 ) ;
if ( F_6 ( ( F_3 ( V_940 ) & V_941 ) == 0 ,
500 ) ) {
F_49 ( L_113 , V_939 ) ;
return - V_945 ;
}
* V_156 = F_3 ( V_943 ) ;
F_2 ( V_943 , 0 ) ;
return 0 ;
}
int F_280 ( struct V_3 * V_4 , T_1 V_939 , T_1 V_156 )
{
F_163 ( ! F_226 ( & V_4 -> V_336 . V_337 ) ) ;
if ( F_3 ( V_940 ) & V_941 ) {
F_71 ( L_114 ) ;
return - V_942 ;
}
F_2 ( V_943 , V_156 ) ;
F_2 ( V_940 , V_941 | V_939 ) ;
if ( F_6 ( ( F_3 ( V_940 ) & V_941 ) == 0 ,
500 ) ) {
F_49 ( L_115 , V_939 ) ;
return - V_945 ;
}
F_2 ( V_943 , 0 ) ;
return 0 ;
}
static int F_396 ( unsigned int V_946 )
{
switch ( V_946 ) {
case 200 :
return 10 ;
case 267 :
return 12 ;
case 320 :
case 333 :
return 16 ;
case 400 :
return 20 ;
default:
return - 1 ;
}
}
static int F_397 ( struct V_3 * V_4 , int V_156 )
{
int div , V_946 = F_135 ( V_4 -> V_136 , 4 ) ;
div = F_396 ( V_946 ) ;
if ( div < 0 )
return div ;
return F_135 ( V_946 * ( V_156 + 6 - 0xbd ) , div ) ;
}
static int F_398 ( struct V_3 * V_4 , int V_156 )
{
int V_947 , V_946 = F_135 ( V_4 -> V_136 , 4 ) ;
V_947 = F_396 ( V_946 ) ;
if ( V_947 < 0 )
return V_947 ;
return F_135 ( V_947 * V_156 , V_946 ) + 0xbd - 6 ;
}
static int F_399 ( struct V_3 * V_4 , int V_156 )
{
int div , V_946 = V_4 -> V_336 . V_682 ;
div = F_396 ( V_946 ) / 2 ;
if ( div < 0 )
return div ;
return F_135 ( V_946 * V_156 , 2 * div ) / 2 ;
}
static int F_400 ( struct V_3 * V_4 , int V_156 )
{
int V_947 , V_946 = V_4 -> V_336 . V_682 ;
V_947 = F_396 ( V_946 ) / 2 ;
if ( V_947 < 0 )
return V_947 ;
return F_135 ( V_156 * 2 * V_947 , V_946 ) * 2 ;
}
int F_262 ( struct V_3 * V_4 , int V_156 )
{
int V_298 = - 1 ;
if ( F_97 ( V_4 -> V_2 ) )
V_298 = F_399 ( V_4 , V_156 ) ;
else if ( F_75 ( V_4 -> V_2 ) )
V_298 = F_397 ( V_4 , V_156 ) ;
return V_298 ;
}
int F_401 ( struct V_3 * V_4 , int V_156 )
{
int V_298 = - 1 ;
if ( F_97 ( V_4 -> V_2 ) )
V_298 = F_400 ( V_4 , V_156 ) ;
else if ( F_75 ( V_4 -> V_2 ) )
V_298 = F_398 ( V_4 , V_156 ) ;
return V_298 ;
}
void F_402 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_403 ( & V_4 -> V_336 . V_337 ) ;
F_50 ( & V_4 -> V_336 . V_785 ,
F_349 ) ;
V_4 -> V_948 . V_949 = false ;
}
