static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_8 ) ;
if ( F_4 ( V_4 , V_9 , V_10 ) )
F_2 ( V_11 , F_3 ( V_11 ) |
V_12 | V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_14 ;
V_14 = F_3 ( V_15 ) ;
switch ( V_14 & V_16 ) {
case V_17 :
V_4 -> V_18 = 533 ;
break;
case V_19 :
V_4 -> V_18 = 800 ;
break;
case V_20 :
V_4 -> V_18 = 667 ;
break;
case V_21 :
V_4 -> V_18 = 400 ;
break;
}
switch ( V_14 & V_22 ) {
case V_23 :
V_4 -> V_24 = 533 ;
break;
case V_25 :
V_4 -> V_24 = 667 ;
break;
case V_26 :
V_4 -> V_24 = 800 ;
break;
}
V_14 = F_3 ( V_27 ) ;
V_4 -> V_28 = ( V_14 & V_29 ) ? 1 : 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_30 , V_31 ;
V_30 = F_7 ( V_32 ) ;
V_31 = F_7 ( V_33 ) ;
switch ( V_30 & 0xff ) {
case 0xc :
V_4 -> V_24 = 800 ;
break;
case 0x10 :
V_4 -> V_24 = 1066 ;
break;
case 0x14 :
V_4 -> V_24 = 1333 ;
break;
case 0x18 :
V_4 -> V_24 = 1600 ;
break;
default:
F_8 ( L_1 ,
V_30 & 0xff ) ;
V_4 -> V_24 = 0 ;
break;
}
V_4 -> V_34 . V_35 = V_4 -> V_24 ;
switch ( V_31 & 0x3ff ) {
case 0x00c :
V_4 -> V_18 = 3200 ;
break;
case 0x00e :
V_4 -> V_18 = 3733 ;
break;
case 0x010 :
V_4 -> V_18 = 4266 ;
break;
case 0x012 :
V_4 -> V_18 = 4800 ;
break;
case 0x014 :
V_4 -> V_18 = 5333 ;
break;
case 0x016 :
V_4 -> V_18 = 5866 ;
break;
case 0x018 :
V_4 -> V_18 = 6400 ;
break;
default:
F_8 ( L_2 ,
V_31 & 0x3ff ) ;
V_4 -> V_18 = 0 ;
break;
}
if ( V_4 -> V_18 == 3200 ) {
V_4 -> V_34 . V_36 = 0 ;
} else if ( V_4 -> V_18 > 3200 && V_4 -> V_18 <= 4800 ) {
V_4 -> V_34 . V_36 = 1 ;
} else {
V_4 -> V_34 . V_36 = 2 ;
}
}
static const struct V_37 * F_9 ( int V_38 ,
int V_28 ,
int V_39 ,
int V_40 )
{
const struct V_37 * V_41 ;
int V_42 ;
if ( V_39 == 0 || V_40 == 0 )
return NULL ;
for ( V_42 = 0 ; V_42 < F_10 ( V_43 ) ; V_42 ++ ) {
V_41 = & V_43 [ V_42 ] ;
if ( V_38 == V_41 -> V_38 &&
V_28 == V_41 -> V_28 &&
V_39 == V_41 -> V_18 && V_40 == V_41 -> V_24 )
return V_41 ;
}
F_11 ( L_3 ) ;
return NULL ;
}
static void F_12 ( struct V_3 * V_4 , bool V_44 )
{
T_1 V_45 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_45 = F_14 ( V_4 , V_48 ) ;
if ( V_44 )
V_45 &= ~ V_49 ;
else
V_45 |= V_49 ;
V_45 &= ~ V_50 ;
V_45 |= V_51 ;
F_15 ( V_4 , V_48 , V_45 ) ;
if ( F_16 ( ( F_14 ( V_4 , V_48 ) &
V_51 ) == 0 , 3 ) )
F_17 ( L_4 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
static void F_19 ( struct V_3 * V_4 , bool V_44 )
{
T_1 V_45 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_45 = F_14 ( V_4 , V_52 ) ;
if ( V_44 )
V_45 |= V_53 ;
else
V_45 &= ~ V_53 ;
F_15 ( V_4 , V_52 , V_45 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
void F_20 ( struct V_3 * V_4 , bool V_44 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_45 ;
if ( F_21 ( V_2 ) || F_22 ( V_2 ) ) {
F_2 ( V_54 , V_44 ? V_55 : 0 ) ;
F_23 ( V_54 ) ;
V_4 -> V_56 . V_57 . V_58 = V_44 ;
} else if ( F_24 ( V_2 ) || F_25 ( V_2 ) ) {
F_2 ( V_59 , V_44 ? V_60 : 0 ) ;
F_23 ( V_59 ) ;
} else if ( F_26 ( V_2 ) ) {
V_45 = F_3 ( V_61 ) & ~ V_62 ;
V_45 |= V_44 ? V_62 : 0 ;
F_2 ( V_61 , V_45 ) ;
F_23 ( V_61 ) ;
} else if ( F_27 ( V_2 ) || F_28 ( V_2 ) ) {
V_45 = V_44 ? F_29 ( V_60 ) :
F_30 ( V_60 ) ;
F_2 ( V_59 , V_45 ) ;
F_23 ( V_59 ) ;
} else if ( F_31 ( V_2 ) ) {
V_45 = V_44 ? F_29 ( V_63 ) :
F_30 ( V_63 ) ;
F_2 ( V_64 , V_45 ) ;
F_23 ( V_64 ) ;
} else {
return;
}
F_11 ( L_5 ,
V_44 ? L_6 : L_7 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
enum V_65 V_65 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_67 , V_68 , V_69 ;
switch ( V_65 ) {
T_3 V_70 , V_71 , V_72 ;
case V_73 :
V_70 = F_3 ( V_74 ) ;
V_71 = F_3 ( V_75 ) ;
V_67 = F_33 ( V_70 , V_71 , 0 , 0 ) ;
V_68 = F_33 ( V_70 , V_71 , 8 , 4 ) ;
break;
case V_76 :
V_70 = F_3 ( V_74 ) ;
V_71 = F_3 ( V_75 ) ;
V_67 = F_33 ( V_70 , V_71 , 16 , 8 ) ;
V_68 = F_33 ( V_70 , V_71 , 24 , 12 ) ;
break;
case V_77 :
V_71 = F_3 ( V_75 ) ;
V_72 = F_3 ( V_78 ) ;
V_67 = F_33 ( V_72 , V_71 , 0 , 16 ) ;
V_68 = F_33 ( V_72 , V_71 , 8 , 20 ) ;
break;
default:
return 0 ;
}
switch ( V_66 ) {
case 0 :
V_69 = V_67 ;
break;
case 1 :
V_69 = V_68 - V_67 ;
break;
case 2 :
V_69 = 512 - 1 - V_68 ;
break;
default:
return 0 ;
}
F_11 ( L_8 ,
F_34 ( V_65 ) , V_66 == 0 ? L_9 : L_10 ,
V_66 == 0 ? F_35 ( V_65 ) : F_36 ( V_65 , V_66 - 1 ) ,
V_69 ) ;
return V_69 ;
}
static int F_37 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_70 = F_3 ( V_74 ) ;
int V_69 ;
V_69 = V_70 & 0x7f ;
if ( V_66 )
V_69 = ( ( V_70 >> V_79 ) & 0x7f ) - V_69 ;
F_11 ( L_11 , V_70 ,
V_66 ? L_12 : L_13 , V_69 ) ;
return V_69 ;
}
static int F_38 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_70 = F_3 ( V_74 ) ;
int V_69 ;
V_69 = V_70 & 0x1ff ;
if ( V_66 )
V_69 = ( ( V_70 >> V_80 ) & 0x1ff ) - V_69 ;
V_69 >>= 1 ;
F_11 ( L_11 , V_70 ,
V_66 ? L_12 : L_13 , V_69 ) ;
return V_69 ;
}
static int F_39 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_70 = F_3 ( V_74 ) ;
int V_69 ;
V_69 = V_70 & 0x7f ;
V_69 >>= 2 ;
F_11 ( L_11 , V_70 ,
V_66 ? L_12 : L_13 ,
V_69 ) ;
return V_69 ;
}
static unsigned long F_40 ( unsigned long V_81 ,
const struct V_82 * V_56 ,
int V_83 ,
int V_84 ,
unsigned long V_85 )
{
long V_86 , V_87 ;
V_86 = ( ( V_81 / 1000 ) * V_84 * V_85 ) /
1000 ;
V_86 = F_41 ( V_86 , V_56 -> V_88 ) ;
F_11 ( L_14 , V_86 ) ;
V_87 = V_83 - ( V_86 + V_56 -> V_89 ) ;
F_11 ( L_15 , V_87 ) ;
if ( V_87 > ( long ) V_56 -> V_90 )
V_87 = V_56 -> V_90 ;
if ( V_87 <= 0 )
V_87 = V_56 -> V_91 ;
if ( V_87 <= 8 )
V_87 = 8 ;
return V_87 ;
}
static struct V_92 * F_42 ( struct V_1 * V_2 )
{
struct V_92 * V_93 , * V_94 = NULL ;
F_43 (dev, crtc) {
if ( F_44 ( V_93 ) ) {
if ( V_94 )
return NULL ;
V_94 = V_93 ;
}
}
return V_94 ;
}
static void F_45 ( struct V_92 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_92 * V_93 ;
const struct V_37 * V_41 ;
T_1 V_96 ;
unsigned long V_56 ;
V_41 = F_9 ( F_46 ( V_2 ) , V_4 -> V_28 ,
V_4 -> V_18 , V_4 -> V_24 ) ;
if ( ! V_41 ) {
F_11 ( L_3 ) ;
F_20 ( V_4 , false ) ;
return;
}
V_93 = F_42 ( V_2 ) ;
if ( V_93 ) {
const struct V_97 * V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
int V_84 = V_93 -> V_101 -> V_102 -> V_103 -> V_104 / 8 ;
int clock = V_98 -> V_105 ;
V_56 = F_40 ( clock , & V_106 ,
V_106 . V_83 ,
V_84 , V_41 -> V_107 ) ;
V_96 = F_3 ( V_108 ) ;
V_96 &= ~ V_109 ;
V_96 |= F_48 ( V_56 , V_110 ) ;
F_2 ( V_108 , V_96 ) ;
F_11 ( L_16 , V_96 ) ;
V_56 = F_40 ( clock , & V_111 ,
V_106 . V_83 ,
V_84 , V_41 -> V_112 ) ;
V_96 = F_3 ( V_61 ) ;
V_96 &= ~ V_113 ;
V_96 |= F_48 ( V_56 , V_114 ) ;
F_2 ( V_61 , V_96 ) ;
V_56 = F_40 ( clock , & V_115 ,
V_115 . V_83 ,
V_84 , V_41 -> V_116 ) ;
V_96 = F_3 ( V_61 ) ;
V_96 &= ~ V_117 ;
V_96 |= F_48 ( V_56 , V_118 ) ;
F_2 ( V_61 , V_96 ) ;
V_56 = F_40 ( clock , & V_119 ,
V_115 . V_83 ,
V_84 , V_41 -> V_120 ) ;
V_96 = F_3 ( V_61 ) ;
V_96 &= ~ V_121 ;
V_96 |= F_48 ( V_56 , V_122 ) ;
F_2 ( V_61 , V_96 ) ;
F_11 ( L_17 , V_96 ) ;
F_20 ( V_4 , true ) ;
} else {
F_20 ( V_4 , false ) ;
}
}
static bool F_49 ( struct V_1 * V_2 ,
int V_66 ,
const struct V_82 * V_123 ,
int V_124 ,
const struct V_82 * V_125 ,
int V_126 ,
int * V_127 ,
int * V_128 )
{
struct V_92 * V_93 ;
const struct V_97 * V_98 ;
int V_129 , V_130 , clock , V_84 ;
int V_131 , V_132 ;
int V_133 , V_134 ;
V_93 = F_50 ( V_2 , V_66 ) ;
if ( ! F_44 ( V_93 ) ) {
* V_128 = V_125 -> V_89 ;
* V_127 = V_123 -> V_89 ;
return false ;
}
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
clock = V_98 -> V_105 ;
V_129 = V_98 -> V_135 ;
V_130 = F_47 ( V_93 ) -> V_99 -> V_136 ;
V_84 = V_93 -> V_101 -> V_102 -> V_103 -> V_104 / 8 ;
V_133 = ( ( clock * V_84 / 1000 ) * V_124 ) / 1000 ;
V_134 = V_123 -> V_83 * V_123 -> V_88 - V_130 * 8 ;
if ( V_134 > 0 )
V_133 += V_134 ;
V_133 = F_41 ( V_133 , V_123 -> V_88 ) ;
* V_127 = V_133 + V_123 -> V_89 ;
if ( * V_127 > ( int ) V_123 -> V_90 )
* V_127 = V_123 -> V_90 ;
V_131 = F_51 ( V_129 * 1000 / clock , 1 ) ;
V_132 = ( V_126 / V_131 + 1000 ) / 1000 ;
V_133 = V_132 * V_93 -> V_125 -> V_102 -> V_137 * V_84 ;
V_134 = V_125 -> V_83 * V_125 -> V_88 - V_130 * 8 ;
if ( V_134 > 0 )
V_133 += V_134 ;
V_133 = F_41 ( V_133 , V_125 -> V_88 ) ;
* V_128 = V_133 + V_125 -> V_89 ;
if ( * V_128 > ( int ) V_125 -> V_90 )
* V_128 = ( int ) V_125 -> V_90 ;
return true ;
}
static bool F_52 ( struct V_1 * V_2 ,
int V_138 , int V_128 ,
const struct V_82 * V_123 ,
const struct V_82 * V_125 )
{
F_11 ( L_18 ,
V_138 , V_128 ) ;
if ( V_138 > V_123 -> V_90 ) {
F_11 ( L_19 ,
V_138 , V_123 -> V_90 ) ;
return false ;
}
if ( V_128 > V_125 -> V_90 ) {
F_11 ( L_20 ,
V_128 , V_125 -> V_90 ) ;
return false ;
}
if ( ! ( V_138 || V_128 ) ) {
F_11 ( L_21 ) ;
return false ;
}
return true ;
}
static bool F_53 ( struct V_1 * V_2 ,
int V_66 ,
int V_85 ,
const struct V_82 * V_123 ,
const struct V_82 * V_125 ,
int * V_138 , int * V_128 )
{
struct V_92 * V_93 ;
const struct V_97 * V_98 ;
int V_130 , V_129 , V_84 , clock ;
unsigned long V_131 ;
int V_132 , V_139 ;
int V_140 , V_141 ;
int V_133 ;
if ( ! V_85 ) {
* V_138 = * V_128 = 0 ;
return false ;
}
V_93 = F_50 ( V_2 , V_66 ) ;
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
clock = V_98 -> V_105 ;
V_129 = V_98 -> V_135 ;
V_130 = F_47 ( V_93 ) -> V_99 -> V_136 ;
V_84 = V_93 -> V_101 -> V_102 -> V_103 -> V_104 / 8 ;
V_131 = F_51 ( V_129 * 1000 / clock , 1 ) ;
V_132 = ( V_85 / V_131 + 1000 ) / 1000 ;
V_139 = V_130 * V_84 ;
V_140 = ( ( clock * V_84 / 1000 ) * V_85 ) / 1000 ;
V_141 = V_132 * V_139 ;
V_133 = F_41 ( F_54 ( V_140 , V_141 ) , V_123 -> V_88 ) ;
* V_138 = V_133 + V_123 -> V_89 ;
V_133 = V_132 * V_84 * V_93 -> V_125 -> V_102 -> V_137 ;
V_133 = F_41 ( V_133 , V_125 -> V_88 ) ;
* V_128 = V_133 + V_125 -> V_89 ;
return F_52 ( V_2 ,
* V_138 , * V_128 ,
V_123 , V_125 ) ;
}
static void F_55 ( struct V_142 * V_93 ,
const struct V_143 * V_56 )
{
struct V_3 * V_4 = F_56 ( V_93 -> V_100 . V_2 ) ;
enum V_65 V_65 = V_93 -> V_65 ;
F_2 ( F_57 ( V_65 ) ,
( V_56 -> V_144 [ V_65 ] . V_125 << V_145 ) |
( V_56 -> V_144 [ V_65 ] . V_146 [ 1 ] << F_58 ( 1 ) ) |
( V_56 -> V_144 [ V_65 ] . V_146 [ 0 ] << F_58 ( 0 ) ) |
( V_56 -> V_144 [ V_65 ] . V_101 << V_147 ) ) ;
F_2 ( V_108 ,
F_48 ( V_56 -> V_148 . V_66 , V_110 ) |
F_48 ( V_56 -> V_65 [ V_76 ] . V_125 , V_149 ) |
F_59 ( V_56 -> V_65 [ V_76 ] . V_101 , V_150 ) |
F_59 ( V_56 -> V_65 [ V_73 ] . V_101 , V_151 ) ) ;
F_2 ( V_152 ,
F_59 ( V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] , V_153 ) |
F_48 ( V_56 -> V_65 [ V_73 ] . V_125 , V_154 ) |
F_59 ( V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] , V_155 ) ) ;
F_2 ( V_61 ,
F_48 ( V_56 -> V_148 . V_125 , V_114 ) ) ;
if ( F_22 ( V_4 ) ) {
F_2 ( V_156 ,
F_59 ( V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] , V_157 ) |
F_59 ( V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] , V_158 ) ) ;
F_2 ( V_159 ,
F_59 ( V_56 -> V_65 [ V_77 ] . V_146 [ 1 ] , V_160 ) |
F_59 ( V_56 -> V_65 [ V_77 ] . V_146 [ 0 ] , V_161 ) ) ;
F_2 ( V_162 ,
F_59 ( V_56 -> V_65 [ V_77 ] . V_101 , V_163 ) |
F_48 ( V_56 -> V_65 [ V_77 ] . V_125 , V_164 ) ) ;
F_2 ( V_165 ,
F_48 ( V_56 -> V_148 . V_66 >> 9 , V_166 ) |
F_48 ( V_56 -> V_65 [ V_77 ] . V_146 [ 1 ] >> 8 , V_167 ) |
F_48 ( V_56 -> V_65 [ V_77 ] . V_146 [ 0 ] >> 8 , V_168 ) |
F_48 ( V_56 -> V_65 [ V_77 ] . V_101 >> 8 , V_169 ) |
F_48 ( V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] >> 8 , V_170 ) |
F_48 ( V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] >> 8 , V_171 ) |
F_48 ( V_56 -> V_65 [ V_76 ] . V_101 >> 8 , V_172 ) |
F_48 ( V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] >> 8 , V_173 ) |
F_48 ( V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] >> 8 , V_174 ) |
F_48 ( V_56 -> V_65 [ V_73 ] . V_101 >> 8 , V_175 ) ) ;
} else {
F_2 ( V_176 ,
F_59 ( V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] , V_157 ) |
F_59 ( V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] , V_158 ) ) ;
F_2 ( V_165 ,
F_48 ( V_56 -> V_148 . V_66 >> 9 , V_166 ) |
F_48 ( V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] >> 8 , V_170 ) |
F_48 ( V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] >> 8 , V_171 ) |
F_48 ( V_56 -> V_65 [ V_76 ] . V_101 >> 8 , V_172 ) |
F_48 ( V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] >> 8 , V_173 ) |
F_48 ( V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] >> 8 , V_174 ) |
F_48 ( V_56 -> V_65 [ V_73 ] . V_101 >> 8 , V_175 ) ) ;
}
F_2 ( V_177 , 0 ) ;
F_2 ( V_178 , 0 ) ;
F_2 ( V_179 , 0 ) ;
F_2 ( V_180 , 0 ) ;
F_23 ( V_108 ) ;
}
static unsigned int F_60 ( unsigned int V_181 ,
unsigned int V_182 ,
unsigned int V_183 ,
unsigned int V_184 ,
unsigned int V_41 )
{
unsigned int V_185 ;
V_185 = ( V_41 * V_181 ) / ( V_182 * 10000 ) ;
V_185 = ( V_185 + 1 ) * V_183 * V_184 ;
V_185 = F_41 ( V_185 , 64 ) ;
return V_185 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_56 . V_186 [ V_187 ] = 3 ;
V_4 -> V_56 . V_188 = V_187 ;
if ( F_22 ( V_4 ) ) {
V_4 -> V_56 . V_186 [ V_189 ] = 12 ;
V_4 -> V_56 . V_186 [ V_190 ] = 33 ;
V_4 -> V_56 . V_188 = V_190 ;
}
}
static T_4 F_62 ( struct V_191 * V_66 ,
struct V_142 * V_93 ,
const struct V_192 * V_102 ,
int V_193 )
{
struct V_3 * V_4 = F_56 ( V_66 -> V_100 . V_2 ) ;
int clock , V_129 , V_84 , V_194 , V_56 ;
if ( V_4 -> V_56 . V_186 [ V_193 ] == 0 )
return V_195 ;
if ( ! V_102 -> V_196 )
return 0 ;
V_84 = F_63 ( V_102 -> V_100 . V_103 -> V_197 , 0 ) ;
clock = V_93 -> V_99 -> V_100 . V_98 . V_105 ;
V_129 = V_93 -> V_99 -> V_100 . V_98 . V_135 ;
V_194 = V_93 -> V_99 -> V_136 ;
if ( F_64 ( V_129 == 0 ) )
V_129 = 1 ;
if ( V_66 -> V_100 . type == V_198 ) {
V_56 = 63 ;
} else {
V_56 = F_60 ( clock , V_129 , V_194 , V_84 ,
V_4 -> V_56 . V_186 [ V_193 ] * 10 ) ;
}
return F_65 ( int , V_56 , V_195 ) ;
}
static void F_66 ( struct V_142 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_100 . V_2 ;
struct V_199 * V_200 = & V_93 -> V_200 ;
struct V_191 * V_66 ;
unsigned int V_201 = 0 ;
const int V_83 = 512 - 1 ;
int V_202 , V_203 = V_83 ;
F_67 (dev, crtc, plane) {
struct V_192 * V_102 =
F_68 ( V_66 -> V_100 . V_102 ) ;
if ( V_66 -> V_100 . type == V_198 )
continue;
if ( V_102 -> V_196 ) {
V_200 -> V_204 ++ ;
V_201 += F_63 ( V_102 -> V_100 . V_103 -> V_197 , 0 ) ;
}
}
F_67 (dev, crtc, plane) {
struct V_192 * V_102 =
F_68 ( V_66 -> V_100 . V_102 ) ;
unsigned int V_205 ;
if ( V_66 -> V_100 . type == V_198 ) {
V_66 -> V_56 . V_83 = 63 ;
continue;
}
if ( ! V_102 -> V_196 ) {
V_66 -> V_56 . V_83 = 0 ;
continue;
}
V_205 = F_63 ( V_102 -> V_100 . V_103 -> V_197 , 0 ) ;
V_66 -> V_56 . V_83 = V_83 * V_205 / V_201 ;
V_203 -= V_66 -> V_56 . V_83 ;
}
V_202 = F_41 ( V_203 , V_200 -> V_204 ? : 1 ) ;
F_67 (dev, crtc, plane) {
int V_206 ;
if ( V_203 == 0 )
break;
if ( V_66 -> V_100 . type == V_198 )
continue;
if ( V_66 -> V_56 . V_83 == 0 &&
V_200 -> V_204 )
continue;
V_206 = F_54 ( V_202 , V_203 ) ;
V_66 -> V_56 . V_83 += V_206 ;
V_203 -= V_206 ;
}
F_64 ( V_203 != 0 ) ;
}
static void F_69 ( struct V_142 * V_93 )
{
struct V_199 * V_200 = & V_93 -> V_200 ;
int V_193 ;
for ( V_193 = 0 ; V_193 < V_200 -> V_207 ; V_193 ++ ) {
struct V_1 * V_2 = V_93 -> V_100 . V_2 ;
const int V_208 = F_70 ( V_2 ) -> V_209 * 512 - 1 ;
struct V_191 * V_66 ;
V_200 -> V_148 [ V_193 ] . V_66 = V_208 - V_200 -> V_148 [ V_193 ] . V_66 ;
V_200 -> V_148 [ V_193 ] . V_125 = 63 - V_200 -> V_148 [ V_193 ] . V_125 ;
F_67 (dev, crtc, plane) {
switch ( V_66 -> V_100 . type ) {
int V_146 ;
case V_198 :
V_200 -> V_56 [ V_193 ] . V_125 = V_66 -> V_56 . V_83 -
V_200 -> V_56 [ V_193 ] . V_125 ;
break;
case V_210 :
V_200 -> V_56 [ V_193 ] . V_101 = V_66 -> V_56 . V_83 -
V_200 -> V_56 [ V_193 ] . V_101 ;
break;
case V_211 :
V_146 = V_66 -> V_66 ;
V_200 -> V_56 [ V_193 ] . V_146 [ V_146 ] = V_66 -> V_56 . V_83 -
V_200 -> V_56 [ V_193 ] . V_146 [ V_146 ] ;
break;
}
}
}
}
static void F_71 ( struct V_142 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_100 . V_2 ;
struct V_199 * V_200 = & V_93 -> V_200 ;
struct V_191 * V_66 ;
int V_208 = F_70 ( V_2 ) -> V_209 * 512 - 1 ;
int V_193 ;
memset ( V_200 , 0 , sizeof( * V_200 ) ) ;
V_200 -> V_58 = V_93 -> V_65 != V_77 && V_93 -> V_56 . V_212 ;
V_200 -> V_207 = F_56 ( V_2 ) -> V_56 . V_188 + 1 ;
V_200 -> V_204 = 0 ;
F_66 ( V_93 ) ;
if ( V_200 -> V_204 != 1 )
V_200 -> V_58 = false ;
if ( V_200 -> V_58 ) {
for ( V_193 = 0 ; V_193 < V_200 -> V_207 ; V_193 ++ ) {
V_200 -> V_148 [ V_193 ] . V_66 = V_208 ;
V_200 -> V_148 [ V_193 ] . V_125 = 63 ;
}
}
F_67 (dev, crtc, plane) {
struct V_192 * V_102 =
F_68 ( V_66 -> V_100 . V_102 ) ;
if ( ! V_102 -> V_196 )
continue;
for ( V_193 = 0 ; V_193 < V_200 -> V_207 ; V_193 ++ ) {
int V_56 = F_62 ( V_66 , V_93 , V_102 , V_193 ) ;
int V_90 = V_66 -> V_100 . type == V_198 ? 63 : 511 ;
if ( F_64 ( V_193 == 0 && V_56 > V_90 ) )
V_56 = V_90 ;
if ( V_56 > V_66 -> V_56 . V_83 )
break;
switch ( V_66 -> V_100 . type ) {
int V_146 ;
case V_198 :
V_200 -> V_56 [ V_193 ] . V_125 = V_56 ;
break;
case V_210 :
V_200 -> V_56 [ V_193 ] . V_101 = V_56 ;
break;
case V_211 :
V_146 = V_66 -> V_66 ;
V_200 -> V_56 [ V_193 ] . V_146 [ V_146 ] = V_56 ;
break;
}
}
V_200 -> V_207 = V_193 ;
if ( ! V_200 -> V_58 )
continue;
switch ( V_66 -> V_100 . type ) {
int V_146 , V_193 ;
case V_198 :
for ( V_193 = 0 ; V_193 < V_200 -> V_207 ; V_193 ++ )
V_200 -> V_148 [ V_193 ] . V_125 =
V_200 -> V_56 [ V_193 ] . V_125 ;
break;
case V_210 :
for ( V_193 = 0 ; V_193 < V_200 -> V_207 ; V_193 ++ )
V_200 -> V_148 [ V_193 ] . V_66 =
F_54 ( V_200 -> V_148 [ V_193 ] . V_66 ,
V_200 -> V_56 [ V_193 ] . V_101 ) ;
break;
case V_211 :
V_146 = V_66 -> V_66 ;
for ( V_193 = 0 ; V_193 < V_200 -> V_207 ; V_193 ++ )
V_200 -> V_148 [ V_193 ] . V_66 =
F_54 ( V_200 -> V_148 [ V_193 ] . V_66 ,
V_200 -> V_56 [ V_193 ] . V_146 [ V_146 ] ) ;
break;
}
}
for ( V_193 = V_200 -> V_207 ; V_193 < F_56 ( V_2 ) -> V_56 . V_188 + 1 ; V_193 ++ ) {
memset ( & V_200 -> V_56 [ V_193 ] , 0 , sizeof( V_200 -> V_56 [ V_193 ] ) ) ;
memset ( & V_200 -> V_148 [ V_193 ] , 0 , sizeof( V_200 -> V_148 [ V_193 ] ) ) ;
}
F_69 ( V_93 ) ;
}
static void F_72 ( struct V_142 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_100 . V_2 ;
struct V_3 * V_4 = F_56 ( V_2 ) ;
struct V_191 * V_66 ;
int V_67 = 0 , V_68 = 0 , V_83 = 0 ;
F_67 (dev, crtc, plane) {
if ( V_66 -> V_100 . type == V_198 ) {
F_64 ( V_66 -> V_56 . V_83 != 63 ) ;
continue;
}
if ( V_66 -> V_100 . type == V_210 )
V_67 = V_66 -> V_56 . V_83 ;
else if ( V_66 -> V_66 == 0 )
V_68 = V_67 + V_66 -> V_56 . V_83 ;
else
V_83 = V_68 + V_66 -> V_56 . V_83 ;
}
F_64 ( V_83 != 512 - 1 ) ;
F_11 ( L_22 ,
F_34 ( V_93 -> V_65 ) , V_67 ,
V_68 , V_83 ) ;
switch ( V_93 -> V_65 ) {
T_3 V_70 , V_71 , V_72 ;
case V_73 :
V_70 = F_3 ( V_74 ) ;
V_71 = F_3 ( V_75 ) ;
V_70 &= ~ ( F_73 ( V_155 , 0xff ) |
F_73 ( V_153 , 0xff ) ) ;
V_70 |= ( F_73 ( V_155 , V_67 ) |
F_73 ( V_153 , V_68 ) ) ;
V_71 &= ~ ( F_73 ( V_174 , 0x1 ) |
F_73 ( V_173 , 0x1 ) ) ;
V_71 |= ( F_73 ( V_174 , V_67 >> 8 ) |
F_73 ( V_173 , V_68 >> 8 ) ) ;
F_2 ( V_74 , V_70 ) ;
F_2 ( V_75 , V_71 ) ;
break;
case V_76 :
V_70 = F_3 ( V_74 ) ;
V_71 = F_3 ( V_75 ) ;
V_70 &= ~ ( F_73 ( V_158 , 0xff ) |
F_73 ( V_157 , 0xff ) ) ;
V_70 |= ( F_73 ( V_158 , V_67 ) |
F_73 ( V_157 , V_68 ) ) ;
V_71 &= ~ ( F_73 ( V_171 , 0xff ) |
F_73 ( V_170 , 0xff ) ) ;
V_71 |= ( F_73 ( V_171 , V_67 >> 8 ) |
F_73 ( V_170 , V_68 >> 8 ) ) ;
F_2 ( V_74 , V_70 ) ;
F_2 ( V_75 , V_71 ) ;
break;
case V_77 :
V_72 = F_3 ( V_78 ) ;
V_71 = F_3 ( V_75 ) ;
V_72 &= ~ ( F_73 ( V_161 , 0xff ) |
F_73 ( V_160 , 0xff ) ) ;
V_72 |= ( F_73 ( V_161 , V_67 ) |
F_73 ( V_160 , V_68 ) ) ;
V_71 &= ~ ( F_73 ( V_168 , 0xff ) |
F_73 ( V_167 , 0xff ) ) ;
V_71 |= ( F_73 ( V_168 , V_67 >> 8 ) |
F_73 ( V_167 , V_68 >> 8 ) ) ;
F_2 ( V_78 , V_72 ) ;
F_2 ( V_75 , V_71 ) ;
break;
default:
break;
}
}
static void F_74 ( struct V_1 * V_2 ,
struct V_143 * V_56 )
{
struct V_142 * V_93 ;
int V_213 = 0 ;
V_56 -> V_193 = F_56 ( V_2 ) -> V_56 . V_188 ;
V_56 -> V_58 = true ;
F_75 (dev, crtc) {
const struct V_199 * V_200 = & V_93 -> V_200 ;
if ( ! V_93 -> V_214 )
continue;
if ( ! V_200 -> V_58 )
V_56 -> V_58 = false ;
V_213 ++ ;
V_56 -> V_193 = F_65 ( int , V_56 -> V_193 , V_200 -> V_207 - 1 ) ;
}
if ( V_213 != 1 )
V_56 -> V_58 = false ;
if ( V_213 > 1 )
V_56 -> V_193 = V_187 ;
F_75 (dev, crtc) {
struct V_199 * V_200 = & V_93 -> V_200 ;
enum V_65 V_65 = V_93 -> V_65 ;
if ( ! V_93 -> V_214 )
continue;
V_56 -> V_65 [ V_65 ] = V_200 -> V_56 [ V_56 -> V_193 ] ;
if ( V_56 -> V_58 )
V_56 -> V_148 = V_200 -> V_148 [ V_56 -> V_193 ] ;
V_56 -> V_144 [ V_65 ] . V_101 = V_215 | 2 ;
V_56 -> V_144 [ V_65 ] . V_146 [ 0 ] = V_215 | 2 ;
V_56 -> V_144 [ V_65 ] . V_146 [ 1 ] = V_215 | 2 ;
V_56 -> V_144 [ V_65 ] . V_125 = V_215 | 2 ;
}
}
static void F_76 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
enum V_65 V_65 = V_142 -> V_65 ;
struct V_143 V_56 = {} ;
F_71 ( V_142 ) ;
F_74 ( V_2 , & V_56 ) ;
if ( memcmp ( & V_4 -> V_56 . V_57 , & V_56 , sizeof( V_56 ) ) == 0 ) {
F_72 ( V_142 ) ;
return;
}
if ( V_56 . V_193 < V_190 &&
V_4 -> V_56 . V_57 . V_193 >= V_190 )
F_12 ( V_4 , false ) ;
if ( V_56 . V_193 < V_189 &&
V_4 -> V_56 . V_57 . V_193 >= V_189 )
F_19 ( V_4 , false ) ;
if ( ! V_56 . V_58 && V_4 -> V_56 . V_57 . V_58 )
F_20 ( V_4 , false ) ;
F_72 ( V_142 ) ;
F_55 ( V_142 , & V_56 ) ;
F_11 ( L_23
L_24 ,
F_34 ( V_65 ) , V_56 . V_65 [ V_65 ] . V_101 , V_56 . V_65 [ V_65 ] . V_125 ,
V_56 . V_65 [ V_65 ] . V_146 [ 0 ] , V_56 . V_65 [ V_65 ] . V_146 [ 1 ] ,
V_56 . V_148 . V_66 , V_56 . V_148 . V_125 , V_56 . V_193 , V_56 . V_58 ) ;
if ( V_56 . V_58 && ! V_4 -> V_56 . V_57 . V_58 )
F_20 ( V_4 , true ) ;
if ( V_56 . V_193 >= V_189 &&
V_4 -> V_56 . V_57 . V_193 < V_189 )
F_19 ( V_4 , true ) ;
if ( V_56 . V_193 >= V_190 &&
V_4 -> V_56 . V_57 . V_193 < V_190 )
F_12 ( V_4 , true ) ;
V_4 -> V_56 . V_57 = V_56 ;
}
static void F_77 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
static const int V_216 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_217 , V_218 , V_219 , V_220 ;
int V_221 , V_112 ;
unsigned int V_94 = 0 ;
bool V_222 ;
if ( F_49 ( V_2 , V_73 ,
& V_223 , V_224 ,
& V_225 , V_224 ,
& V_217 , & V_219 ) )
V_94 |= 1 << V_73 ;
if ( F_49 ( V_2 , V_76 ,
& V_223 , V_224 ,
& V_225 , V_224 ,
& V_218 , & V_220 ) )
V_94 |= 1 << V_76 ;
if ( F_78 ( V_94 ) &&
F_53 ( V_2 , F_79 ( V_94 ) - 1 ,
V_216 ,
& V_223 ,
& V_225 ,
& V_221 , & V_112 ) ) {
V_222 = true ;
} else {
V_222 = false ;
F_20 ( V_4 , false ) ;
V_221 = V_112 = 0 ;
}
F_11 ( L_25
L_26 ,
V_217 , V_219 ,
V_218 , V_220 ,
V_221 , V_112 ) ;
F_2 ( V_108 ,
F_48 ( V_221 , V_110 ) |
F_48 ( V_220 , V_149 ) |
F_48 ( V_218 , V_150 ) |
F_48 ( V_217 , V_151 ) ) ;
F_2 ( V_152 ,
( F_3 ( V_152 ) & ~ V_226 ) |
F_48 ( V_219 , V_154 ) ) ;
F_2 ( V_61 ,
( F_3 ( V_61 ) & ~ ( V_227 | V_113 ) ) |
F_48 ( V_112 , V_114 ) ) ;
if ( V_222 )
F_20 ( V_4 , true ) ;
}
static void F_80 ( struct V_92 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_92 * V_93 ;
int V_228 = 1 ;
int V_112 = 16 ;
bool V_222 ;
V_93 = F_42 ( V_2 ) ;
if ( V_93 ) {
static const int V_216 = 12000 ;
const struct V_97 * V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
int clock = V_98 -> V_105 ;
int V_129 = V_98 -> V_135 ;
int V_130 = F_47 ( V_93 ) -> V_99 -> V_136 ;
int V_84 = V_93 -> V_101 -> V_102 -> V_103 -> V_104 / 8 ;
unsigned long V_131 ;
int V_133 ;
V_131 = F_51 ( V_129 * 1000 / clock , 1 ) ;
V_133 = ( ( ( V_216 / V_131 ) + 1000 ) / 1000 ) *
V_84 * V_130 ;
V_133 = F_41 ( V_133 , V_229 ) ;
V_228 = V_230 - V_133 ;
if ( V_228 < 0 )
V_228 = 1 ;
V_228 &= 0x1ff ;
F_11 ( L_27 ,
V_133 , V_228 ) ;
V_133 = ( ( ( V_216 / V_131 ) + 1000 ) / 1000 ) *
V_84 * V_93 -> V_125 -> V_102 -> V_137 ;
V_133 = F_41 ( V_133 ,
V_231 . V_88 ) ;
V_112 = V_231 . V_83 -
( V_133 + V_231 . V_89 ) ;
if ( V_112 > V_231 . V_90 )
V_112 = V_231 . V_90 ;
F_11 ( L_28
L_29 , V_228 , V_112 ) ;
V_222 = true ;
} else {
V_222 = false ;
F_20 ( V_4 , false ) ;
}
F_11 ( L_30 ,
V_228 ) ;
F_2 ( V_108 , F_48 ( V_228 , V_110 ) |
F_48 ( 8 , V_149 ) |
F_48 ( 8 , V_150 ) |
F_48 ( 8 , V_151 ) ) ;
F_2 ( V_152 , F_48 ( 8 , V_154 ) |
F_48 ( 8 , V_232 ) ) ;
F_2 ( V_61 , F_48 ( V_112 , V_114 ) ) ;
if ( V_222 )
F_20 ( V_4 , true ) ;
}
static void F_81 ( struct V_92 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_82 * V_233 ;
T_3 V_234 ;
T_3 V_235 ;
int V_236 , V_228 = 1 ;
int V_83 ;
int V_217 , V_218 ;
struct V_92 * V_93 , * V_94 = NULL ;
if ( F_28 ( V_2 ) )
V_233 = & V_237 ;
else if ( ! F_82 ( V_2 ) )
V_233 = & V_238 ;
else
V_233 = & V_239 ;
V_83 = V_4 -> V_123 . V_240 ( V_2 , 0 ) ;
V_93 = F_50 ( V_2 , 0 ) ;
if ( F_44 ( V_93 ) ) {
const struct V_97 * V_98 ;
int V_241 = V_93 -> V_101 -> V_102 -> V_103 -> V_104 / 8 ;
if ( F_82 ( V_2 ) )
V_241 = 4 ;
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
V_217 = F_40 ( V_98 -> V_105 ,
V_233 , V_83 , V_241 ,
V_224 ) ;
V_94 = V_93 ;
} else {
V_217 = V_83 - V_233 -> V_89 ;
if ( V_217 > ( long ) V_233 -> V_90 )
V_217 = V_233 -> V_90 ;
}
if ( F_82 ( V_2 ) )
V_233 = & V_242 ;
V_83 = V_4 -> V_123 . V_240 ( V_2 , 1 ) ;
V_93 = F_50 ( V_2 , 1 ) ;
if ( F_44 ( V_93 ) ) {
const struct V_97 * V_98 ;
int V_241 = V_93 -> V_101 -> V_102 -> V_103 -> V_104 / 8 ;
if ( F_82 ( V_2 ) )
V_241 = 4 ;
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
V_218 = F_40 ( V_98 -> V_105 ,
V_233 , V_83 , V_241 ,
V_224 ) ;
if ( V_94 == NULL )
V_94 = V_93 ;
else
V_94 = NULL ;
} else {
V_218 = V_83 - V_233 -> V_89 ;
if ( V_218 > ( long ) V_233 -> V_90 )
V_218 = V_233 -> V_90 ;
}
F_11 ( L_31 , V_217 , V_218 ) ;
if ( F_31 ( V_2 ) && V_94 ) {
struct V_243 * V_244 ;
V_244 = F_83 ( V_94 -> V_101 -> V_102 -> V_103 ) ;
if ( V_244 -> V_245 == V_246 )
V_94 = NULL ;
}
V_236 = 2 ;
F_20 ( V_4 , false ) ;
if ( F_84 ( V_2 ) && V_94 ) {
static const int V_216 = 6000 ;
const struct V_97 * V_98 = & F_47 ( V_94 ) -> V_99 -> V_100 . V_98 ;
int clock = V_98 -> V_105 ;
int V_129 = V_98 -> V_135 ;
int V_130 = F_47 ( V_94 ) -> V_99 -> V_136 ;
int V_84 = V_94 -> V_101 -> V_102 -> V_103 -> V_104 / 8 ;
unsigned long V_131 ;
int V_133 ;
V_131 = F_51 ( V_129 * 1000 / clock , 1 ) ;
V_133 = ( ( ( V_216 / V_131 ) + 1000 ) / 1000 ) *
V_84 * V_130 ;
V_133 = F_41 ( V_133 , V_233 -> V_88 ) ;
F_11 ( L_32 , V_133 ) ;
V_228 = V_233 -> V_83 - V_133 ;
if ( V_228 < 0 )
V_228 = 1 ;
if ( F_27 ( V_2 ) || F_28 ( V_2 ) )
F_2 ( V_59 ,
V_247 | ( V_228 & 0xff ) ) ;
else if ( F_31 ( V_2 ) )
F_2 ( V_59 , V_228 & 0x3f ) ;
}
F_11 ( L_33 ,
V_217 , V_218 , V_236 , V_228 ) ;
V_234 = ( ( V_218 & 0x3f ) << 16 ) | ( V_217 & 0x3f ) ;
V_235 = ( V_236 & 0x1f ) ;
V_234 = V_234 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_235 = V_235 | ( 1 << 8 ) ;
F_2 ( V_248 , V_234 ) ;
F_2 ( V_249 , V_235 ) ;
if ( V_94 )
F_20 ( V_4 , true ) ;
}
static void F_85 ( struct V_92 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_92 * V_93 ;
const struct V_97 * V_98 ;
T_3 V_234 ;
int V_217 ;
V_93 = F_42 ( V_2 ) ;
if ( V_93 == NULL )
return;
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
V_217 = F_40 ( V_98 -> V_105 ,
& V_250 ,
V_4 -> V_123 . V_240 ( V_2 , 0 ) ,
4 , V_224 ) ;
V_234 = F_3 ( V_248 ) & ~ 0xfff ;
V_234 |= ( 3 << 8 ) | V_217 ;
F_11 ( L_34 , V_217 ) ;
F_2 ( V_248 , V_234 ) ;
}
T_3 F_86 ( const struct V_251 * V_252 )
{
T_3 V_181 ;
V_181 = V_252 -> V_100 . V_98 . V_105 ;
if ( V_252 -> V_253 . V_94 ) {
T_5 V_254 , V_255 , V_256 , V_257 ;
T_3 V_258 = V_252 -> V_253 . V_69 ;
V_254 = V_252 -> V_136 ;
V_255 = V_252 -> V_259 ;
V_256 = ( V_258 >> 16 ) & 0xFFFF ;
V_257 = V_258 & 0xFFFF ;
if ( V_254 < V_256 )
V_254 = V_256 ;
if ( V_255 < V_257 )
V_255 = V_257 ;
V_181 = F_87 ( ( T_5 ) V_181 * V_254 * V_255 ,
V_256 * V_257 ) ;
}
return V_181 ;
}
static T_3 F_88 ( T_3 V_181 , T_6 V_184 ,
T_3 V_41 )
{
T_5 V_185 ;
if ( F_89 ( V_41 == 0 , L_35 ) )
return V_260 ;
V_185 = ( T_5 ) V_181 * V_184 * V_41 ;
V_185 = F_90 ( V_185 , 64 * 10000 ) + 2 ;
return V_185 ;
}
static T_3 F_91 ( T_3 V_181 , T_3 V_182 ,
T_3 V_183 , T_6 V_184 ,
T_3 V_41 )
{
T_3 V_185 ;
if ( F_89 ( V_41 == 0 , L_35 ) )
return V_260 ;
V_185 = ( V_41 * V_181 ) / ( V_182 * 10000 ) ;
V_185 = ( V_185 + 1 ) * V_183 * V_184 ;
V_185 = F_41 ( V_185 , 64 ) + 2 ;
return V_185 ;
}
static T_3 F_92 ( T_3 V_261 , T_3 V_183 ,
T_6 V_184 )
{
return F_41 ( V_261 * 64 , V_183 * V_184 ) + 2 ;
}
static T_3 F_93 ( const struct V_251 * V_262 ,
const struct V_192 * V_263 ,
T_3 V_264 ,
bool V_265 )
{
int V_266 = V_263 -> V_100 . V_103 ? V_263 -> V_100 . V_103 -> V_104 / 8 : 0 ;
T_3 V_267 , V_268 ;
if ( ! V_262 -> V_100 . V_214 || ! V_263 -> V_196 )
return 0 ;
V_267 = F_88 ( F_86 ( V_262 ) , V_266 , V_264 ) ;
if ( ! V_265 )
return V_267 ;
V_268 = F_91 ( F_86 ( V_262 ) ,
V_262 -> V_100 . V_98 . V_135 ,
F_94 ( & V_263 -> V_269 ) ,
V_266 ,
V_264 ) ;
return F_54 ( V_267 , V_268 ) ;
}
static T_3 F_95 ( const struct V_251 * V_262 ,
const struct V_192 * V_263 ,
T_3 V_264 )
{
int V_266 = V_263 -> V_100 . V_103 ? V_263 -> V_100 . V_103 -> V_104 / 8 : 0 ;
T_3 V_267 , V_268 ;
if ( ! V_262 -> V_100 . V_214 || ! V_263 -> V_196 )
return 0 ;
V_267 = F_88 ( F_86 ( V_262 ) , V_266 , V_264 ) ;
V_268 = F_91 ( F_86 ( V_262 ) ,
V_262 -> V_100 . V_98 . V_135 ,
F_94 ( & V_263 -> V_269 ) ,
V_266 ,
V_264 ) ;
return F_54 ( V_267 , V_268 ) ;
}
static T_3 F_96 ( const struct V_251 * V_262 ,
const struct V_192 * V_263 ,
T_3 V_264 )
{
int V_241 = 4 ;
int V_194 = V_263 -> V_196 ? V_263 -> V_100 . V_137 : 64 ;
if ( ! V_262 -> V_100 . V_214 )
return 0 ;
return F_91 ( F_86 ( V_262 ) ,
V_262 -> V_100 . V_98 . V_135 ,
V_194 , V_241 , V_264 ) ;
}
static T_3 F_97 ( const struct V_251 * V_262 ,
const struct V_192 * V_263 ,
T_3 V_261 )
{
int V_266 = V_263 -> V_100 . V_103 ? V_263 -> V_100 . V_103 -> V_104 / 8 : 0 ;
if ( ! V_262 -> V_100 . V_214 || ! V_263 -> V_196 )
return 0 ;
return F_92 ( V_261 , F_94 ( & V_263 -> V_269 ) , V_266 ) ;
}
static unsigned int F_98 ( const struct V_1 * V_2 )
{
if ( F_70 ( V_2 ) -> V_270 >= 8 )
return 3072 ;
else if ( F_70 ( V_2 ) -> V_270 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_99 ( const struct V_1 * V_2 ,
int V_193 , bool V_271 )
{
if ( F_70 ( V_2 ) -> V_270 >= 8 )
return V_193 == 0 ? 255 : 2047 ;
else if ( F_70 ( V_2 ) -> V_270 >= 7 )
return V_193 == 0 ? 127 : 1023 ;
else if ( ! V_271 )
return V_193 == 0 ? 127 : 511 ;
else
return V_193 == 0 ? 63 : 255 ;
}
static unsigned int F_100 ( const struct V_1 * V_2 ,
int V_193 )
{
if ( F_70 ( V_2 ) -> V_270 >= 7 )
return V_193 == 0 ? 63 : 255 ;
else
return V_193 == 0 ? 31 : 63 ;
}
static unsigned int F_101 ( const struct V_1 * V_2 )
{
if ( F_70 ( V_2 ) -> V_270 >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_102 ( const struct V_1 * V_2 ,
int V_193 ,
const struct V_272 * V_99 ,
enum V_273 V_274 ,
bool V_271 )
{
unsigned int V_83 = F_98 ( V_2 ) ;
if ( V_271 && ! V_99 -> V_275 )
return 0 ;
if ( V_193 == 0 || V_99 -> V_276 > 1 ) {
V_83 /= F_70 ( V_2 ) -> V_209 ;
if ( F_70 ( V_2 ) -> V_270 <= 6 )
V_83 /= 2 ;
}
if ( V_99 -> V_275 ) {
if ( V_193 > 0 && V_274 == V_277 ) {
if ( V_271 )
V_83 *= 5 ;
V_83 /= 6 ;
} else {
V_83 /= 2 ;
}
}
return F_54 ( V_83 , F_99 ( V_2 , V_193 , V_271 ) ) ;
}
static unsigned int F_103 ( const struct V_1 * V_2 ,
int V_193 ,
const struct V_272 * V_99 )
{
if ( V_193 > 0 && V_99 -> V_276 > 1 )
return 64 ;
return F_100 ( V_2 , V_193 ) ;
}
static void F_104 ( const struct V_1 * V_2 ,
int V_193 ,
const struct V_272 * V_99 ,
enum V_273 V_274 ,
struct V_278 * F_51 )
{
F_51 -> V_279 = F_102 ( V_2 , V_193 , V_99 , V_274 , false ) ;
F_51 -> V_280 = F_102 ( V_2 , V_193 , V_99 , V_274 , true ) ;
F_51 -> V_281 = F_103 ( V_2 , V_193 , V_99 ) ;
F_51 -> V_282 = F_101 ( V_2 ) ;
}
static void F_105 ( struct V_1 * V_2 ,
int V_193 ,
struct V_278 * F_51 )
{
F_51 -> V_279 = F_99 ( V_2 , V_193 , false ) ;
F_51 -> V_280 = F_99 ( V_2 , V_193 , true ) ;
F_51 -> V_281 = F_100 ( V_2 , V_193 ) ;
F_51 -> V_282 = F_101 ( V_2 ) ;
}
static bool F_106 ( int V_193 ,
const struct V_278 * F_51 ,
struct V_283 * V_284 )
{
bool V_185 ;
if ( ! V_284 -> V_44 )
return false ;
V_284 -> V_44 = V_284 -> V_261 <= F_51 -> V_279 &&
V_284 -> V_285 <= F_51 -> V_280 &&
V_284 -> V_286 <= F_51 -> V_281 ;
V_185 = V_284 -> V_44 ;
if ( V_193 == 0 && ! V_284 -> V_44 ) {
if ( V_284 -> V_261 > F_51 -> V_279 )
F_11 ( L_36 ,
V_193 , V_284 -> V_261 , F_51 -> V_279 ) ;
if ( V_284 -> V_285 > F_51 -> V_280 )
F_11 ( L_37 ,
V_193 , V_284 -> V_285 , F_51 -> V_280 ) ;
if ( V_284 -> V_286 > F_51 -> V_281 )
F_11 ( L_38 ,
V_193 , V_284 -> V_286 , F_51 -> V_281 ) ;
V_284 -> V_261 = F_65 ( T_3 , V_284 -> V_261 , F_51 -> V_279 ) ;
V_284 -> V_285 = F_65 ( T_3 , V_284 -> V_285 , F_51 -> V_280 ) ;
V_284 -> V_286 = F_65 ( T_3 , V_284 -> V_286 , F_51 -> V_281 ) ;
V_284 -> V_44 = true ;
}
return V_185 ;
}
static void F_107 ( const struct V_3 * V_4 ,
const struct V_142 * V_142 ,
int V_193 ,
struct V_251 * V_262 ,
struct V_192 * V_287 ,
struct V_192 * V_288 ,
struct V_192 * V_289 ,
struct V_283 * V_284 )
{
T_4 V_186 = V_4 -> V_56 . V_186 [ V_193 ] ;
T_4 V_290 = V_4 -> V_56 . V_290 [ V_193 ] ;
T_4 V_291 = V_4 -> V_56 . V_291 [ V_193 ] ;
if ( V_193 > 0 ) {
V_186 *= 5 ;
V_290 *= 5 ;
V_291 *= 5 ;
}
V_284 -> V_261 = F_93 ( V_262 , V_287 ,
V_186 , V_193 ) ;
V_284 -> V_285 = F_95 ( V_262 , V_288 , V_290 ) ;
V_284 -> V_286 = F_96 ( V_262 , V_289 , V_291 ) ;
V_284 -> V_292 = F_97 ( V_262 , V_287 , V_284 -> V_261 ) ;
V_284 -> V_44 = true ;
}
static T_3
F_108 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
const struct V_97 * V_98 = & V_142 -> V_99 -> V_100 . V_98 ;
T_1 V_293 , V_294 ;
if ( ! V_142 -> V_214 )
return 0 ;
V_293 = F_109 ( V_98 -> V_135 * 1000 * 8 ,
V_98 -> V_105 ) ;
V_294 = F_109 ( V_98 -> V_135 * 1000 * 8 ,
V_4 -> V_295 ) ;
return F_110 ( V_294 ) |
F_111 ( V_293 ) ;
}
static void F_112 ( struct V_1 * V_2 , T_4 V_56 [ 8 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_113 ( V_2 ) ) {
T_3 V_45 ;
int V_185 , V_42 ;
int V_193 , V_188 = F_114 ( V_2 ) ;
V_45 = 0 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_185 = F_115 ( V_4 ,
V_296 ,
& V_45 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
if ( V_185 ) {
F_17 ( L_39 , V_185 ) ;
return;
}
V_56 [ 0 ] = V_45 & V_297 ;
V_56 [ 1 ] = ( V_45 >> V_298 ) &
V_297 ;
V_56 [ 2 ] = ( V_45 >> V_299 ) &
V_297 ;
V_56 [ 3 ] = ( V_45 >> V_300 ) &
V_297 ;
V_45 = 1 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_185 = F_115 ( V_4 ,
V_296 ,
& V_45 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
if ( V_185 ) {
F_17 ( L_39 , V_185 ) ;
return;
}
V_56 [ 4 ] = V_45 & V_297 ;
V_56 [ 5 ] = ( V_45 >> V_298 ) &
V_297 ;
V_56 [ 6 ] = ( V_45 >> V_299 ) &
V_297 ;
V_56 [ 7 ] = ( V_45 >> V_300 ) &
V_297 ;
V_56 [ 0 ] += 2 ;
for ( V_193 = 1 ; V_193 <= V_188 ; V_193 ++ )
if ( V_56 [ V_193 ] != 0 )
V_56 [ V_193 ] += 2 ;
else {
for ( V_42 = V_193 + 1 ; V_42 <= V_188 ; V_42 ++ )
V_56 [ V_42 ] = 0 ;
break;
}
} else if ( F_116 ( V_2 ) || F_117 ( V_2 ) ) {
T_5 V_301 = F_118 ( V_302 ) ;
V_56 [ 0 ] = ( V_301 >> 56 ) & 0xFF ;
if ( V_56 [ 0 ] == 0 )
V_56 [ 0 ] = V_301 & 0xF ;
V_56 [ 1 ] = ( V_301 >> 4 ) & 0xFF ;
V_56 [ 2 ] = ( V_301 >> 12 ) & 0xFF ;
V_56 [ 3 ] = ( V_301 >> 20 ) & 0x1FF ;
V_56 [ 4 ] = ( V_301 >> 32 ) & 0x1FF ;
} else if ( F_70 ( V_2 ) -> V_270 >= 6 ) {
T_3 V_301 = F_3 ( V_302 ) ;
V_56 [ 0 ] = ( V_301 >> V_303 ) & V_304 ;
V_56 [ 1 ] = ( V_301 >> V_305 ) & V_304 ;
V_56 [ 2 ] = ( V_301 >> V_306 ) & V_304 ;
V_56 [ 3 ] = ( V_301 >> V_307 ) & V_304 ;
} else if ( F_70 ( V_2 ) -> V_270 >= 5 ) {
T_3 V_308 = F_3 ( V_309 ) ;
V_56 [ 0 ] = 7 ;
V_56 [ 1 ] = ( V_308 >> V_310 ) & V_311 ;
V_56 [ 2 ] = ( V_308 >> V_312 ) & V_311 ;
}
}
static void F_119 ( struct V_1 * V_2 , T_4 V_56 [ 5 ] )
{
if ( F_70 ( V_2 ) -> V_270 == 5 )
V_56 [ 0 ] = 13 ;
}
static void F_120 ( struct V_1 * V_2 , T_4 V_56 [ 5 ] )
{
if ( F_70 ( V_2 ) -> V_270 == 5 )
V_56 [ 0 ] = 13 ;
if ( F_121 ( V_2 ) )
V_56 [ 3 ] *= 2 ;
}
int F_114 ( const struct V_1 * V_2 )
{
if ( F_70 ( V_2 ) -> V_270 >= 9 )
return 7 ;
else if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
return 4 ;
else if ( F_70 ( V_2 ) -> V_270 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_122 ( struct V_1 * V_2 ,
const char * V_313 ,
const T_4 V_56 [ 8 ] )
{
int V_193 , V_188 = F_114 ( V_2 ) ;
for ( V_193 = 0 ; V_193 <= V_188 ; V_193 ++ ) {
unsigned int V_41 = V_56 [ V_193 ] ;
if ( V_41 == 0 ) {
F_17 ( L_40 ,
V_313 , V_193 ) ;
continue;
}
if ( F_113 ( V_2 ) )
V_41 *= 10 ;
else if ( V_193 > 0 )
V_41 *= 5 ;
F_11 ( L_41 ,
V_313 , V_193 , V_56 [ V_193 ] ,
V_41 / 10 , V_41 % 10 ) ;
}
}
static bool F_123 ( struct V_3 * V_4 ,
T_4 V_56 [ 5 ] , T_4 F_54 )
{
int V_193 , V_188 = F_114 ( V_4 -> V_2 ) ;
if ( V_56 [ 0 ] >= F_54 )
return false ;
V_56 [ 0 ] = F_51 ( V_56 [ 0 ] , F_54 ) ;
for ( V_193 = 1 ; V_193 <= V_188 ; V_193 ++ )
V_56 [ V_193 ] = F_124 ( T_4 , V_56 [ V_193 ] , F_41 ( F_54 , 5 ) ) ;
return true ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_314 ;
V_314 = F_123 ( V_4 , V_4 -> V_56 . V_186 , 12 ) |
F_123 ( V_4 , V_4 -> V_56 . V_290 , 12 ) |
F_123 ( V_4 , V_4 -> V_56 . V_291 , 12 ) ;
if ( ! V_314 )
return;
F_11 ( L_42 ) ;
F_122 ( V_2 , L_43 , V_4 -> V_56 . V_186 ) ;
F_122 ( V_2 , L_44 , V_4 -> V_56 . V_290 ) ;
F_122 ( V_2 , L_45 , V_4 -> V_56 . V_291 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_112 ( V_2 , V_4 -> V_56 . V_186 ) ;
memcpy ( V_4 -> V_56 . V_290 , V_4 -> V_56 . V_186 ,
sizeof( V_4 -> V_56 . V_186 ) ) ;
memcpy ( V_4 -> V_56 . V_291 , V_4 -> V_56 . V_186 ,
sizeof( V_4 -> V_56 . V_186 ) ) ;
F_119 ( V_2 , V_4 -> V_56 . V_290 ) ;
F_120 ( V_2 , V_4 -> V_56 . V_291 ) ;
F_122 ( V_2 , L_43 , V_4 -> V_56 . V_186 ) ;
F_122 ( V_2 , L_44 , V_4 -> V_56 . V_290 ) ;
F_122 ( V_2 , L_45 , V_4 -> V_56 . V_291 ) ;
if ( F_127 ( V_2 ) )
F_125 ( V_2 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_112 ( V_2 , V_4 -> V_56 . V_315 ) ;
F_122 ( V_2 , L_46 , V_4 -> V_56 . V_315 ) ;
}
static int F_129 ( struct V_142 * V_142 ,
struct V_316 * V_102 )
{
struct V_317 * V_318 ;
struct V_1 * V_2 = V_142 -> V_100 . V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_251 * V_262 = NULL ;
struct V_191 * V_191 ;
struct V_319 * V_320 ;
struct V_192 * V_287 = NULL ;
struct V_192 * V_288 = NULL ;
struct V_192 * V_289 = NULL ;
int V_193 , V_188 = F_114 ( V_2 ) ;
struct V_272 V_99 = {
. V_276 = 1 ,
} ;
struct V_278 F_51 ;
V_262 = F_130 ( V_102 , V_142 ) ;
if ( F_131 ( V_262 ) )
return F_132 ( V_262 ) ;
V_318 = & V_262 -> V_56 . V_321 . V_322 ;
F_67 (dev, intel_crtc, intel_plane) {
V_320 = F_133 ( V_102 ,
& V_191 -> V_100 ) ;
if ( F_131 ( V_320 ) )
return F_132 ( V_320 ) ;
if ( V_191 -> V_100 . type == V_210 )
V_287 = F_68 ( V_320 ) ;
else if ( V_191 -> V_100 . type == V_211 )
V_288 = F_68 ( V_320 ) ;
else if ( V_191 -> V_100 . type == V_198 )
V_289 = F_68 ( V_320 ) ;
}
V_99 . V_275 = V_288 -> V_196 ;
V_99 . V_323 = V_288 -> V_196 &&
( F_94 ( & V_288 -> V_269 ) != F_94 ( & V_288 -> V_324 ) >> 16 ||
F_134 ( & V_288 -> V_269 ) != F_134 ( & V_288 -> V_324 ) >> 16 ) ;
V_318 -> V_325 = V_262 -> V_100 . V_214 ;
V_318 -> V_275 = V_99 . V_275 ;
V_318 -> V_323 = V_99 . V_323 ;
if ( F_70 ( V_2 ) -> V_270 <= 6 && V_288 -> V_196 )
V_188 = 1 ;
if ( V_99 . V_323 )
V_188 = 0 ;
F_107 ( V_4 , V_142 , 0 , V_262 ,
V_287 , V_288 , V_289 , & V_318 -> V_56 [ 0 ] ) ;
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
V_318 -> V_293 = F_108 ( V_2 ,
& V_142 -> V_100 ) ;
F_104 ( V_2 , 0 , & V_99 , V_326 , & F_51 ) ;
if ( ! F_106 ( 0 , & F_51 , & V_318 -> V_56 [ 0 ] ) )
return - V_327 ;
F_105 ( V_2 , 1 , & F_51 ) ;
for ( V_193 = 1 ; V_193 <= V_188 ; V_193 ++ ) {
struct V_283 V_56 = {} ;
F_107 ( V_4 , V_142 , V_193 , V_262 ,
V_287 , V_288 , V_289 , & V_56 ) ;
if ( ! F_106 ( V_193 , & F_51 , & V_56 ) )
break;
V_318 -> V_56 [ V_193 ] = V_56 ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 ,
int V_193 ,
struct V_283 * V_328 )
{
const struct V_142 * V_142 ;
V_328 -> V_44 = true ;
F_75 (dev, intel_crtc) {
const struct V_251 * V_262 =
F_136 ( V_142 -> V_100 . V_102 ) ;
const struct V_317 * V_214 = & V_262 -> V_56 . V_321 . V_322 ;
const struct V_283 * V_56 = & V_214 -> V_56 [ V_193 ] ;
if ( ! V_214 -> V_325 )
continue;
if ( ! V_56 -> V_44 )
V_328 -> V_44 = false ;
V_328 -> V_261 = F_51 ( V_328 -> V_261 , V_56 -> V_261 ) ;
V_328 -> V_285 = F_51 ( V_328 -> V_285 , V_56 -> V_285 ) ;
V_328 -> V_286 = F_51 ( V_328 -> V_286 , V_56 -> V_286 ) ;
V_328 -> V_292 = F_51 ( V_328 -> V_292 , V_56 -> V_292 ) ;
}
}
static void F_137 ( struct V_1 * V_2 ,
const struct V_272 * V_99 ,
const struct V_278 * F_51 ,
struct V_317 * V_329 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_193 , V_188 = F_114 ( V_2 ) ;
int V_330 = V_188 ;
if ( ( F_70 ( V_2 ) -> V_270 <= 6 || F_121 ( V_2 ) ) &&
V_99 -> V_276 > 1 )
return;
V_329 -> V_331 = F_70 ( V_2 ) -> V_270 >= 6 ;
for ( V_193 = 1 ; V_193 <= V_188 ; V_193 ++ ) {
struct V_283 * V_56 = & V_329 -> V_56 [ V_193 ] ;
F_135 ( V_2 , V_193 , V_56 ) ;
if ( V_193 > V_330 )
V_56 -> V_44 = false ;
else if ( ! F_106 ( V_193 , F_51 , V_56 ) )
V_330 = V_193 - 1 ;
if ( V_56 -> V_292 > F_51 -> V_282 ) {
if ( V_56 -> V_44 )
V_329 -> V_331 = false ;
V_56 -> V_292 = 0 ;
}
}
if ( F_138 ( V_2 ) && ! V_329 -> V_331 &&
F_139 ( V_4 ) ) {
for ( V_193 = 2 ; V_193 <= V_188 ; V_193 ++ ) {
struct V_283 * V_56 = & V_329 -> V_56 [ V_193 ] ;
V_56 -> V_44 = false ;
}
}
}
static int F_140 ( int V_332 , const struct V_317 * V_318 )
{
return V_332 + ( V_332 >= 2 && V_318 -> V_56 [ 4 ] . V_44 ) ;
}
static unsigned int F_141 ( struct V_1 * V_2 , int V_193 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
return 2 * V_193 ;
else
return V_4 -> V_56 . V_186 [ V_193 ] ;
}
static void F_142 ( struct V_1 * V_2 ,
const struct V_317 * V_329 ,
enum V_273 V_333 ,
struct V_334 * V_335 )
{
struct V_142 * V_142 ;
int V_193 , V_332 ;
V_335 -> V_336 = V_329 -> V_331 ;
V_335 -> V_333 = V_333 ;
for ( V_332 = 1 ; V_332 <= 3 ; V_332 ++ ) {
const struct V_283 * V_337 ;
V_193 = F_140 ( V_332 , V_329 ) ;
V_337 = & V_329 -> V_56 [ V_193 ] ;
V_335 -> V_332 [ V_332 - 1 ] =
( F_141 ( V_2 , V_193 ) << V_338 ) |
( V_337 -> V_261 << V_339 ) |
V_337 -> V_286 ;
if ( V_337 -> V_44 )
V_335 -> V_332 [ V_332 - 1 ] |= V_340 ;
if ( F_70 ( V_2 ) -> V_270 >= 8 )
V_335 -> V_332 [ V_332 - 1 ] |=
V_337 -> V_292 << V_341 ;
else
V_335 -> V_332 [ V_332 - 1 ] |=
V_337 -> V_292 << V_342 ;
if ( F_70 ( V_2 ) -> V_270 <= 6 && V_337 -> V_285 ) {
F_64 ( V_332 != 1 ) ;
V_335 -> V_343 [ V_332 - 1 ] = V_344 | V_337 -> V_285 ;
} else
V_335 -> V_343 [ V_332 - 1 ] = V_337 -> V_285 ;
}
F_75 (dev, intel_crtc) {
const struct V_251 * V_262 =
F_136 ( V_142 -> V_100 . V_102 ) ;
enum V_65 V_65 = V_142 -> V_65 ;
const struct V_283 * V_337 = & V_262 -> V_56 . V_321 . V_322 . V_56 [ 0 ] ;
if ( F_64 ( ! V_337 -> V_44 ) )
continue;
V_335 -> V_345 [ V_65 ] = V_262 -> V_56 . V_321 . V_322 . V_293 ;
V_335 -> V_346 [ V_65 ] =
( V_337 -> V_261 << V_347 ) |
( V_337 -> V_285 << V_348 ) |
V_337 -> V_286 ;
}
}
static struct V_317 * F_143 ( struct V_1 * V_2 ,
struct V_317 * V_349 ,
struct V_317 * V_350 )
{
int V_193 , V_188 = F_114 ( V_2 ) ;
int V_351 = 0 , V_352 = 0 ;
for ( V_193 = 1 ; V_193 <= V_188 ; V_193 ++ ) {
if ( V_349 -> V_56 [ V_193 ] . V_44 )
V_351 = V_193 ;
if ( V_350 -> V_56 [ V_193 ] . V_44 )
V_352 = V_193 ;
}
if ( V_351 == V_352 ) {
if ( V_350 -> V_331 && ! V_349 -> V_331 )
return V_350 ;
else
return V_349 ;
} else if ( V_351 > V_352 ) {
return V_349 ;
} else {
return V_350 ;
}
}
static unsigned int F_144 ( struct V_3 * V_4 ,
const struct V_334 * V_353 ,
const struct V_334 * V_354 )
{
unsigned int V_355 = 0 ;
enum V_65 V_65 ;
int V_332 ;
F_145 (dev_priv, pipe) {
if ( V_353 -> V_345 [ V_65 ] != V_354 -> V_345 [ V_65 ] ) {
V_355 |= F_146 ( V_65 ) ;
V_355 |= V_356 ;
}
if ( V_353 -> V_346 [ V_65 ] != V_354 -> V_346 [ V_65 ] ) {
V_355 |= F_147 ( V_65 ) ;
V_355 |= V_356 ;
}
}
if ( V_353 -> V_336 != V_354 -> V_336 ) {
V_355 |= V_357 ;
V_355 |= V_356 ;
}
if ( V_353 -> V_333 != V_354 -> V_333 ) {
V_355 |= V_358 ;
V_355 |= V_356 ;
}
if ( V_355 & V_356 )
return V_355 ;
for ( V_332 = 1 ; V_332 <= 3 ; V_332 ++ ) {
if ( V_353 -> V_332 [ V_332 - 1 ] != V_354 -> V_332 [ V_332 - 1 ] ||
V_353 -> V_343 [ V_332 - 1 ] != V_354 -> V_343 [ V_332 - 1 ] )
break;
}
for (; V_332 <= 3 ; V_332 ++ )
V_355 |= F_148 ( V_332 ) ;
return V_355 ;
}
static bool F_149 ( struct V_3 * V_4 ,
unsigned int V_355 )
{
struct V_334 * V_359 = & V_4 -> V_56 . V_360 ;
bool V_314 = false ;
if ( V_355 & F_148 ( 3 ) && V_359 -> V_332 [ 2 ] & V_340 ) {
V_359 -> V_332 [ 2 ] &= ~ V_340 ;
F_2 ( V_361 , V_359 -> V_332 [ 2 ] ) ;
V_314 = true ;
}
if ( V_355 & F_148 ( 2 ) && V_359 -> V_332 [ 1 ] & V_340 ) {
V_359 -> V_332 [ 1 ] &= ~ V_340 ;
F_2 ( V_362 , V_359 -> V_332 [ 1 ] ) ;
V_314 = true ;
}
if ( V_355 & F_148 ( 1 ) && V_359 -> V_332 [ 0 ] & V_340 ) {
V_359 -> V_332 [ 0 ] &= ~ V_340 ;
F_2 ( V_363 , V_359 -> V_332 [ 0 ] ) ;
V_314 = true ;
}
return V_314 ;
}
static void F_150 ( struct V_3 * V_4 ,
struct V_334 * V_335 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_334 * V_359 = & V_4 -> V_56 . V_360 ;
unsigned int V_355 ;
T_3 V_45 ;
V_355 = F_144 ( V_4 , V_359 , V_335 ) ;
if ( ! V_355 )
return;
F_149 ( V_4 , V_355 ) ;
if ( V_355 & F_147 ( V_73 ) )
F_2 ( V_364 , V_335 -> V_346 [ 0 ] ) ;
if ( V_355 & F_147 ( V_76 ) )
F_2 ( V_365 , V_335 -> V_346 [ 1 ] ) ;
if ( V_355 & F_147 ( V_77 ) )
F_2 ( V_366 , V_335 -> V_346 [ 2 ] ) ;
if ( V_355 & F_146 ( V_73 ) )
F_2 ( F_151 ( V_73 ) , V_335 -> V_345 [ 0 ] ) ;
if ( V_355 & F_146 ( V_76 ) )
F_2 ( F_151 ( V_76 ) , V_335 -> V_345 [ 1 ] ) ;
if ( V_355 & F_146 ( V_77 ) )
F_2 ( F_151 ( V_77 ) , V_335 -> V_345 [ 2 ] ) ;
if ( V_355 & V_358 ) {
if ( F_116 ( V_2 ) || F_117 ( V_2 ) ) {
V_45 = F_3 ( V_367 ) ;
if ( V_335 -> V_333 == V_326 )
V_45 &= ~ V_368 ;
else
V_45 |= V_368 ;
F_2 ( V_367 , V_45 ) ;
} else {
V_45 = F_3 ( V_369 ) ;
if ( V_335 -> V_333 == V_326 )
V_45 &= ~ V_370 ;
else
V_45 |= V_370 ;
F_2 ( V_369 , V_45 ) ;
}
}
if ( V_355 & V_357 ) {
V_45 = F_3 ( V_371 ) ;
if ( V_335 -> V_336 )
V_45 &= ~ V_372 ;
else
V_45 |= V_372 ;
F_2 ( V_371 , V_45 ) ;
}
if ( V_355 & F_148 ( 1 ) &&
V_359 -> V_343 [ 0 ] != V_335 -> V_343 [ 0 ] )
F_2 ( V_373 , V_335 -> V_343 [ 0 ] ) ;
if ( F_70 ( V_2 ) -> V_270 >= 7 ) {
if ( V_355 & F_148 ( 2 ) && V_359 -> V_343 [ 1 ] != V_335 -> V_343 [ 1 ] )
F_2 ( V_374 , V_335 -> V_343 [ 1 ] ) ;
if ( V_355 & F_148 ( 3 ) && V_359 -> V_343 [ 2 ] != V_335 -> V_343 [ 2 ] )
F_2 ( V_375 , V_335 -> V_343 [ 2 ] ) ;
}
if ( V_355 & F_148 ( 1 ) && V_359 -> V_332 [ 0 ] != V_335 -> V_332 [ 0 ] )
F_2 ( V_363 , V_335 -> V_332 [ 0 ] ) ;
if ( V_355 & F_148 ( 2 ) && V_359 -> V_332 [ 1 ] != V_335 -> V_332 [ 1 ] )
F_2 ( V_362 , V_335 -> V_332 [ 1 ] ) ;
if ( V_355 & F_148 ( 3 ) && V_359 -> V_332 [ 2 ] != V_335 -> V_332 [ 2 ] )
F_2 ( V_361 , V_335 -> V_332 [ 2 ] ) ;
V_4 -> V_56 . V_360 = * V_335 ;
}
static bool F_152 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_149 ( V_4 , V_356 ) ;
}
static int
F_153 ( const struct V_191 * V_66 )
{
switch ( V_66 -> V_100 . type ) {
case V_210 :
return 0 ;
case V_198 :
return V_376 ;
case V_211 :
return V_66 -> V_66 + 1 ;
default:
F_154 ( V_66 -> V_100 . type ) ;
return V_66 -> V_66 ;
}
}
static void
F_155 ( struct V_1 * V_2 ,
const struct V_251 * V_262 ,
const struct V_272 * V_99 ,
struct V_377 * V_378 )
{
struct V_92 * V_379 = V_262 -> V_100 . V_93 ;
struct V_92 * V_93 ;
unsigned int V_380 , V_381 ;
int V_382 ;
if ( ! V_262 -> V_100 . V_214 ) {
V_378 -> V_383 = 0 ;
V_378 -> V_384 = 0 ;
return;
}
if ( F_156 ( V_2 ) )
V_381 = V_385 ;
else
V_381 = V_386 ;
V_381 -= 4 ;
V_382 = 0 ;
F_43 (dev, crtc) {
if ( ! F_47 ( V_93 ) -> V_214 )
continue;
if ( V_93 == V_379 )
break;
V_382 ++ ;
}
V_380 = V_381 / V_99 -> V_276 ;
V_378 -> V_383 = V_382 * V_381 / V_99 -> V_276 ;
V_378 -> V_384 = V_378 -> V_383 + V_380 ;
}
static unsigned int F_157 ( const struct V_272 * V_99 )
{
if ( V_99 -> V_276 == 1 )
return 32 ;
return 8 ;
}
static void F_158 ( struct V_377 * V_387 , T_1 V_96 )
{
V_387 -> V_383 = V_96 & 0x3ff ;
V_387 -> V_384 = ( V_96 >> 16 ) & 0x3ff ;
if ( V_387 -> V_384 )
V_387 -> V_384 += 1 ;
}
void F_159 ( struct V_3 * V_4 ,
struct V_388 * V_389 )
{
enum V_65 V_65 ;
int V_66 ;
T_1 V_45 ;
memset ( V_389 , 0 , sizeof( * V_389 ) ) ;
F_145 (dev_priv, pipe) {
enum V_390 V_391 ;
V_391 = F_160 ( V_65 ) ;
if ( ! F_161 ( V_4 , V_391 ) )
continue;
F_162 (dev_priv, pipe, plane) {
V_45 = F_3 ( F_163 ( V_65 , V_66 ) ) ;
F_158 ( & V_389 -> V_66 [ V_65 ] [ V_66 ] ,
V_45 ) ;
}
V_45 = F_3 ( F_164 ( V_65 ) ) ;
F_158 ( & V_389 -> V_66 [ V_65 ] [ V_376 ] ,
V_45 ) ;
F_165 ( V_4 , V_391 ) ;
}
}
static unsigned int
F_166 ( const struct V_251 * V_262 ,
const struct V_319 * V_263 ,
int V_392 )
{
struct V_142 * V_142 = F_47 ( V_262 -> V_100 . V_93 ) ;
struct V_393 * V_103 = V_263 -> V_103 ;
if ( V_103 -> V_197 == V_394 ) {
if ( V_392 )
return V_142 -> V_99 -> V_136 *
V_142 -> V_99 -> V_259 *
F_63 ( V_103 -> V_197 , 0 ) ;
else
return ( V_142 -> V_99 -> V_136 / 2 ) *
( V_142 -> V_99 -> V_259 / 2 ) *
F_63 ( V_103 -> V_197 , 1 ) ;
}
return V_142 -> V_99 -> V_136 *
V_142 -> V_99 -> V_259 *
F_63 ( V_103 -> V_197 , 0 ) ;
}
static unsigned int
F_167 ( const struct V_251 * V_262 )
{
struct V_142 * V_142 = F_47 ( V_262 -> V_100 . V_93 ) ;
struct V_1 * V_2 = V_142 -> V_100 . V_2 ;
const struct V_191 * V_191 ;
unsigned int V_395 = 0 ;
F_67 (dev, intel_crtc, intel_plane) {
const struct V_319 * V_263 = V_191 -> V_100 . V_102 ;
if ( V_263 -> V_103 == NULL )
continue;
if ( V_191 -> V_100 . type == V_198 )
continue;
V_395 += F_166 ( V_262 ,
V_263 ,
0 ) ;
if ( V_263 -> V_103 -> V_197 == V_394 )
V_395 += F_166 ( V_262 ,
V_263 ,
1 ) ;
}
return V_395 ;
}
static void
F_168 ( struct V_251 * V_262 ,
struct V_388 * V_389 )
{
struct V_92 * V_93 = V_262 -> V_100 . V_93 ;
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = F_56 ( V_2 ) ;
struct V_272 * V_99 = & V_4 -> V_56 . V_99 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_191 * V_191 ;
enum V_65 V_65 = V_142 -> V_65 ;
struct V_377 * V_378 = & V_389 -> V_65 [ V_65 ] ;
T_4 V_396 , V_383 , V_397 ;
T_4 V_398 [ V_399 ] ;
T_4 V_400 [ V_399 ] ;
unsigned int V_395 ;
F_155 ( V_2 , V_262 , V_99 , V_378 ) ;
V_396 = F_169 ( V_378 ) ;
if ( V_396 == 0 ) {
memset ( V_389 -> V_66 [ V_65 ] , 0 , sizeof( V_389 -> V_66 [ V_65 ] ) ) ;
memset ( & V_389 -> V_66 [ V_65 ] [ V_376 ] , 0 ,
sizeof( V_389 -> V_66 [ V_65 ] [ V_376 ] ) ) ;
return;
}
V_397 = F_157 ( V_99 ) ;
V_389 -> V_66 [ V_65 ] [ V_376 ] . V_383 = V_378 -> V_384 - V_397 ;
V_389 -> V_66 [ V_65 ] [ V_376 ] . V_384 = V_378 -> V_384 ;
V_396 -= V_397 ;
V_378 -> V_384 -= V_397 ;
F_67 (dev, intel_crtc, intel_plane) {
struct V_401 * V_66 = & V_191 -> V_100 ;
struct V_393 * V_103 = V_66 -> V_102 -> V_103 ;
int V_402 = F_153 ( V_191 ) ;
if ( V_103 == NULL )
continue;
if ( V_66 -> type == V_198 )
continue;
V_398 [ V_402 ] = 8 ;
V_396 -= V_398 [ V_402 ] ;
V_400 [ V_402 ] = ( V_103 -> V_197 == V_394 ) ? 8 : 0 ;
V_396 -= V_400 [ V_402 ] ;
}
V_395 = F_167 ( V_262 ) ;
V_383 = V_378 -> V_383 ;
F_67 (dev, intel_crtc, intel_plane) {
struct V_401 * V_66 = & V_191 -> V_100 ;
struct V_319 * V_263 = V_191 -> V_100 . V_102 ;
unsigned int V_403 , V_404 ;
T_4 V_405 , V_406 = 0 ;
int V_402 = F_153 ( V_191 ) ;
if ( V_263 -> V_103 == NULL )
continue;
if ( V_66 -> type == V_198 )
continue;
V_403 = F_166 ( V_262 , V_263 , 0 ) ;
V_405 = V_398 [ V_402 ] ;
V_405 += F_87 ( ( T_5 ) V_396 * V_403 ,
V_395 ) ;
V_389 -> V_66 [ V_65 ] [ V_402 ] . V_383 = V_383 ;
V_389 -> V_66 [ V_65 ] [ V_402 ] . V_384 = V_383 + V_405 ;
V_383 += V_405 ;
if ( V_263 -> V_103 -> V_197 == V_394 ) {
V_404 = F_166 ( V_262 ,
V_263 ,
1 ) ;
V_406 = V_400 [ V_402 ] ;
V_406 += F_87 ( ( T_5 ) V_396 * V_404 ,
V_395 ) ;
V_389 -> V_407 [ V_65 ] [ V_402 ] . V_383 = V_383 ;
V_389 -> V_407 [ V_65 ] [ V_402 ] . V_384 = V_383 + V_406 ;
V_383 += V_406 ;
}
}
}
static T_3 F_170 ( const struct V_251 * V_99 )
{
return V_99 -> V_100 . V_98 . V_105 ;
}
static T_3 F_171 ( T_3 V_181 , T_6 V_184 ,
T_3 V_41 )
{
T_3 V_408 , V_185 ;
if ( V_41 == 0 )
return V_260 ;
V_408 = V_41 * V_181 * V_184 / 512 ;
V_185 = F_41 ( V_408 , 1000 ) ;
return V_185 ;
}
static T_3 F_172 ( T_3 V_181 , T_3 V_182 ,
T_3 V_183 , T_6 V_184 ,
T_5 V_409 , T_3 V_41 )
{
T_3 V_185 ;
T_3 V_410 , V_411 ;
T_3 V_408 ;
if ( V_41 == 0 )
return V_260 ;
V_410 = V_183 * V_184 ;
if ( V_409 == V_412 ||
V_409 == V_413 ) {
V_410 *= 4 ;
V_411 = F_41 ( V_410 , 512 ) ;
V_411 /= 4 ;
} else {
V_411 = F_41 ( V_410 , 512 ) ;
}
V_408 = V_41 * V_181 ;
V_185 = F_41 ( V_408 , V_182 * 1000 ) *
V_411 ;
return V_185 ;
}
static bool F_173 ( const struct V_388 * V_414 ,
const struct V_142 * V_142 )
{
struct V_1 * V_2 = V_142 -> V_100 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_388 * V_415 = & V_4 -> V_56 . V_416 . V_389 ;
if ( memcmp ( V_414 -> V_65 , V_415 -> V_65 , sizeof( V_414 -> V_65 ) ) )
return true ;
return false ;
}
static bool F_174 ( const struct V_3 * V_4 ,
struct V_251 * V_262 ,
struct V_191 * V_191 ,
T_4 V_417 ,
int V_193 ,
T_4 * V_418 ,
T_6 * V_419 )
{
struct V_401 * V_66 = & V_191 -> V_100 ;
struct V_393 * V_103 = V_66 -> V_102 -> V_103 ;
T_3 V_41 = V_4 -> V_56 . V_315 [ V_193 ] ;
T_3 V_267 , V_268 ;
T_3 V_410 , V_411 ;
T_3 V_420 , V_421 ;
T_3 V_422 ;
T_6 V_184 ;
if ( V_41 == 0 || ! V_262 -> V_100 . V_214 || ! V_103 )
return false ;
V_184 = F_63 ( V_103 -> V_197 , 0 ) ;
V_267 = F_171 ( F_170 ( V_262 ) ,
V_184 ,
V_41 ) ;
V_268 = F_172 ( F_170 ( V_262 ) ,
V_262 -> V_100 . V_98 . V_135 ,
V_262 -> V_136 ,
V_184 ,
V_103 -> V_423 [ 0 ] ,
V_41 ) ;
V_410 = V_262 -> V_136 * V_184 ;
V_411 = F_41 ( V_410 , 512 ) ;
if ( V_103 -> V_423 [ 0 ] == V_412 ||
V_103 -> V_423 [ 0 ] == V_413 ) {
T_3 V_424 = 4 ;
T_3 V_425 ;
if ( F_175 ( V_66 -> V_102 -> V_426 ) ) {
int V_266 = ( V_103 -> V_197 == V_394 ) ?
F_63 ( V_103 -> V_197 , 1 ) :
F_63 ( V_103 -> V_197 , 0 ) ;
switch ( V_266 ) {
case 1 :
V_424 = 16 ;
break;
case 2 :
V_424 = 8 ;
break;
case 8 :
F_89 ( 1 , L_47 ) ;
}
}
V_425 = V_411 * V_424 ;
V_422 = F_51 ( V_268 , V_425 ) ;
} else {
if ( ( V_417 / V_411 ) >= 1 )
V_422 = F_54 ( V_267 , V_268 ) ;
else
V_422 = V_267 ;
}
V_420 = V_422 + 1 ;
V_421 = F_41 ( V_422 , V_411 ) ;
if ( V_193 >= 1 && V_193 <= 7 ) {
if ( V_103 -> V_423 [ 0 ] == V_412 ||
V_103 -> V_423 [ 0 ] == V_413 )
V_421 += 4 ;
else
V_420 ++ ;
}
if ( V_420 >= V_417 || V_421 > 31 )
return false ;
* V_418 = V_420 ;
* V_419 = V_421 ;
return true ;
}
static void F_176 ( const struct V_3 * V_4 ,
struct V_388 * V_389 ,
struct V_251 * V_262 ,
int V_193 ,
struct V_427 * V_284 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_142 * V_142 = F_47 ( V_262 -> V_100 . V_93 ) ;
struct V_191 * V_191 ;
T_4 V_428 ;
enum V_65 V_65 = V_142 -> V_65 ;
F_67 (dev, intel_crtc, intel_plane) {
int V_42 = F_153 ( V_191 ) ;
V_428 = F_169 ( & V_389 -> V_66 [ V_65 ] [ V_42 ] ) ;
V_284 -> V_429 [ V_42 ] = F_174 ( V_4 ,
V_262 ,
V_191 ,
V_428 ,
V_193 ,
& V_284 -> V_430 [ V_42 ] ,
& V_284 -> V_431 [ V_42 ] ) ;
}
}
static T_3
F_177 ( struct V_251 * V_262 )
{
if ( ! V_262 -> V_100 . V_214 )
return 0 ;
if ( F_64 ( F_170 ( V_262 ) == 0 ) )
return 0 ;
return F_41 ( 8 * V_262 -> V_100 . V_98 . V_135 * 1000 ,
F_170 ( V_262 ) ) ;
}
static void F_178 ( struct V_251 * V_262 ,
struct V_427 * V_432 )
{
struct V_92 * V_93 = V_262 -> V_100 . V_93 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_191 * V_191 ;
if ( ! V_262 -> V_100 . V_214 )
return;
F_67 (crtc->dev, intel_crtc, intel_plane) {
int V_42 = F_153 ( V_191 ) ;
V_432 -> V_429 [ V_42 ] = false ;
}
}
static void F_179 ( struct V_251 * V_262 ,
struct V_388 * V_389 ,
struct V_433 * V_318 )
{
struct V_1 * V_2 = V_262 -> V_100 . V_93 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
int V_193 , V_188 = F_114 ( V_2 ) ;
for ( V_193 = 0 ; V_193 <= V_188 ; V_193 ++ ) {
F_176 ( V_4 , V_389 , V_262 ,
V_193 , & V_318 -> V_56 [ V_193 ] ) ;
}
V_318 -> V_293 = F_177 ( V_262 ) ;
F_178 ( V_262 , & V_318 -> V_432 ) ;
}
static void F_180 ( struct V_1 * V_2 ,
struct V_433 * V_434 ,
struct V_435 * V_337 ,
struct V_142 * V_142 )
{
int V_193 , V_188 = F_114 ( V_2 ) ;
enum V_65 V_65 = V_142 -> V_65 ;
T_3 V_436 ;
int V_42 ;
for ( V_193 = 0 ; V_193 <= V_188 ; V_193 ++ ) {
for ( V_42 = 0 ; V_42 < F_181 ( V_142 ) ; V_42 ++ ) {
V_436 = 0 ;
V_436 |= V_434 -> V_56 [ V_193 ] . V_431 [ V_42 ] <<
V_437 ;
V_436 |= V_434 -> V_56 [ V_193 ] . V_430 [ V_42 ] ;
if ( V_434 -> V_56 [ V_193 ] . V_429 [ V_42 ] )
V_436 |= V_438 ;
V_337 -> V_66 [ V_65 ] [ V_42 ] [ V_193 ] = V_436 ;
}
V_436 = 0 ;
V_436 |= V_434 -> V_56 [ V_193 ] . V_431 [ V_376 ] << V_437 ;
V_436 |= V_434 -> V_56 [ V_193 ] . V_430 [ V_376 ] ;
if ( V_434 -> V_56 [ V_193 ] . V_429 [ V_376 ] )
V_436 |= V_438 ;
V_337 -> V_66 [ V_65 ] [ V_376 ] [ V_193 ] = V_436 ;
}
for ( V_42 = 0 ; V_42 < F_181 ( V_142 ) ; V_42 ++ ) {
V_436 = 0 ;
V_436 |= V_434 -> V_432 . V_431 [ V_42 ] << V_437 ;
V_436 |= V_434 -> V_432 . V_430 [ V_42 ] ;
if ( V_434 -> V_432 . V_429 [ V_42 ] )
V_436 |= V_438 ;
V_337 -> V_439 [ V_65 ] [ V_42 ] = V_436 ;
}
V_436 = 0 ;
V_436 |= V_434 -> V_432 . V_431 [ V_376 ] << V_437 ;
V_436 |= V_434 -> V_432 . V_430 [ V_376 ] ;
if ( V_434 -> V_432 . V_429 [ V_376 ] )
V_436 |= V_438 ;
V_337 -> V_439 [ V_65 ] [ V_376 ] = V_436 ;
V_337 -> V_345 [ V_65 ] = V_434 -> V_293 ;
}
static void F_182 ( struct V_3 * V_4 ,
T_7 V_96 ,
const struct V_377 * V_387 )
{
if ( V_387 -> V_384 )
F_2 ( V_96 , ( V_387 -> V_384 - 1 ) << 16 | V_387 -> V_383 ) ;
else
F_2 ( V_96 , 0 ) ;
}
static void F_183 ( struct V_3 * V_4 ,
const struct V_435 * V_354 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_142 * V_93 ;
F_75 (dev, crtc) {
int V_42 , V_193 , V_188 = F_114 ( V_2 ) ;
enum V_65 V_65 = V_93 -> V_65 ;
if ( ! V_354 -> V_355 [ V_65 ] )
continue;
F_2 ( F_151 ( V_65 ) , V_354 -> V_345 [ V_65 ] ) ;
for ( V_193 = 0 ; V_193 <= V_188 ; V_193 ++ ) {
for ( V_42 = 0 ; V_42 < F_181 ( V_93 ) ; V_42 ++ )
F_2 ( F_184 ( V_65 , V_42 , V_193 ) ,
V_354 -> V_66 [ V_65 ] [ V_42 ] [ V_193 ] ) ;
F_2 ( F_185 ( V_65 , V_193 ) ,
V_354 -> V_66 [ V_65 ] [ V_376 ] [ V_193 ] ) ;
}
for ( V_42 = 0 ; V_42 < F_181 ( V_93 ) ; V_42 ++ )
F_2 ( F_186 ( V_65 , V_42 ) ,
V_354 -> V_439 [ V_65 ] [ V_42 ] ) ;
F_2 ( F_187 ( V_65 ) ,
V_354 -> V_439 [ V_65 ] [ V_376 ] ) ;
for ( V_42 = 0 ; V_42 < F_181 ( V_93 ) ; V_42 ++ ) {
F_182 ( V_4 ,
F_163 ( V_65 , V_42 ) ,
& V_354 -> V_389 . V_66 [ V_65 ] [ V_42 ] ) ;
F_182 ( V_4 ,
F_188 ( V_65 , V_42 ) ,
& V_354 -> V_389 . V_407 [ V_65 ] [ V_42 ] ) ;
}
F_182 ( V_4 , F_164 ( V_65 ) ,
& V_354 -> V_389 . V_66 [ V_65 ] [ V_376 ] ) ;
}
}
static void
F_189 ( struct V_3 * V_4 , enum V_65 V_65 , int V_440 )
{
int V_66 ;
F_11 ( L_48 , F_34 ( V_65 ) , V_440 ) ;
F_162 (dev_priv, pipe, plane) {
F_2 ( F_190 ( V_65 , V_66 ) ,
F_3 ( F_190 ( V_65 , V_66 ) ) ) ;
}
F_2 ( F_191 ( V_65 ) , F_3 ( F_191 ( V_65 ) ) ) ;
}
static bool
F_192 ( const struct V_388 * V_353 ,
const struct V_388 * V_354 ,
enum V_65 V_65 )
{
T_4 V_441 , V_442 ;
V_441 = F_169 ( & V_353 -> V_65 [ V_65 ] ) ;
V_442 = F_169 ( & V_354 -> V_65 [ V_65 ] ) ;
return V_441 != V_442 &&
V_354 -> V_65 [ V_65 ] . V_383 >= V_353 -> V_65 [ V_65 ] . V_383 &&
V_354 -> V_65 [ V_65 ] . V_384 <= V_353 -> V_65 [ V_65 ] . V_384 ;
}
static void F_193 ( struct V_3 * V_4 ,
struct V_435 * V_443 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_388 * V_415 , * V_414 ;
bool V_444 [ V_445 ] = {} ;
struct V_142 * V_93 ;
enum V_65 V_65 ;
V_414 = & V_443 -> V_389 ;
V_415 = & V_4 -> V_56 . V_416 . V_389 ;
F_75 (dev, crtc) {
if ( ! V_93 -> V_214 )
continue;
V_65 = V_93 -> V_65 ;
if ( ! F_192 ( V_415 , V_414 , V_65 ) )
continue;
F_189 ( V_4 , V_65 , 1 ) ;
F_194 ( V_2 , V_65 ) ;
V_444 [ V_65 ] = true ;
}
F_75 (dev, crtc) {
if ( ! V_93 -> V_214 )
continue;
V_65 = V_93 -> V_65 ;
if ( V_444 [ V_65 ] )
continue;
if ( F_169 ( & V_414 -> V_65 [ V_65 ] ) <
F_169 ( & V_415 -> V_65 [ V_65 ] ) ) {
F_189 ( V_4 , V_65 , 2 ) ;
F_194 ( V_2 , V_65 ) ;
V_444 [ V_65 ] = true ;
}
}
F_75 (dev, crtc) {
if ( ! V_93 -> V_214 )
continue;
V_65 = V_93 -> V_65 ;
if ( V_444 [ V_65 ] )
continue;
F_189 ( V_4 , V_65 , 3 ) ;
}
}
static bool F_195 ( struct V_92 * V_93 ,
struct V_388 * V_389 ,
struct V_433 * V_318 )
{
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_251 * V_262 = F_136 ( V_93 -> V_102 ) ;
F_168 ( V_262 , V_389 ) ;
F_179 ( V_262 , V_389 , V_318 ) ;
if ( ! memcmp ( & V_142 -> V_56 . V_214 . V_446 , V_318 , sizeof( * V_318 ) ) )
return false ;
V_142 -> V_56 . V_214 . V_446 = * V_318 ;
return true ;
}
static void F_196 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_435 * V_337 )
{
struct V_142 * V_142 ;
struct V_142 * V_447 = F_47 ( V_93 ) ;
if ( ! F_173 ( & V_337 -> V_389 , V_447 ) )
return;
F_75 (dev, intel_crtc) {
struct V_433 V_318 = {} ;
bool V_448 ;
if ( V_447 -> V_65 == V_142 -> V_65 )
continue;
if ( ! V_142 -> V_214 )
continue;
V_448 = F_195 ( & V_142 -> V_100 ,
& V_337 -> V_389 , & V_318 ) ;
F_64 ( ! V_448 ) ;
F_180 ( V_2 , & V_318 , V_337 , V_142 ) ;
V_337 -> V_355 [ V_142 -> V_65 ] = true ;
}
}
static void F_197 ( struct V_435 * V_449 , enum V_65 V_65 )
{
V_449 -> V_345 [ V_65 ] = 0 ;
memset ( V_449 -> V_66 [ V_65 ] , 0 ,
sizeof( T_3 ) * 8 * V_399 ) ;
memset ( V_449 -> V_439 [ V_65 ] ,
0 , sizeof( T_3 ) * V_399 ) ;
V_449 -> V_439 [ V_65 ] [ V_376 ] = 0 ;
memset ( & V_449 -> V_389 . V_65 [ V_65 ] , 0 , sizeof( struct V_377 ) ) ;
memset ( & V_449 -> V_389 . V_66 [ V_65 ] , 0 ,
sizeof( struct V_377 ) * V_399 ) ;
memset ( & V_449 -> V_389 . V_407 [ V_65 ] , 0 ,
sizeof( struct V_377 ) * V_399 ) ;
memset ( & V_449 -> V_389 . V_66 [ V_65 ] [ V_376 ] , 0 ,
sizeof( struct V_377 ) ) ;
}
static void F_198 ( struct V_92 * V_93 )
{
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_435 * V_335 = & V_4 -> V_56 . V_450 ;
struct V_251 * V_262 = F_136 ( V_93 -> V_102 ) ;
struct V_433 * V_318 = & V_262 -> V_56 . V_321 . V_446 ;
memset ( V_335 -> V_355 , 0 , sizeof( bool ) * V_445 ) ;
F_197 ( V_335 , V_142 -> V_65 ) ;
if ( ! F_195 ( V_93 , & V_335 -> V_389 , V_318 ) )
return;
F_180 ( V_2 , V_318 , V_335 , V_142 ) ;
V_335 -> V_355 [ V_142 -> V_65 ] = true ;
F_196 ( V_2 , V_93 , V_335 ) ;
F_183 ( V_4 , V_335 ) ;
F_193 ( V_4 , V_335 ) ;
V_4 -> V_56 . V_416 = * V_335 ;
}
static void F_199 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_317 V_451 = {} , V_452 = {} , * V_453 ;
struct V_278 F_51 ;
struct V_272 * V_99 = & V_4 -> V_56 . V_99 ;
struct V_334 V_335 = {} ;
enum V_273 V_333 ;
F_104 ( V_2 , 1 , V_99 , V_326 , & F_51 ) ;
F_137 ( V_2 , V_99 , & F_51 , & V_451 ) ;
if ( F_70 ( V_2 ) -> V_270 >= 7 &&
V_99 -> V_276 == 1 && V_99 -> V_275 ) {
F_104 ( V_2 , 1 , V_99 , V_277 , & F_51 ) ;
F_137 ( V_2 , V_99 , & F_51 , & V_452 ) ;
V_453 = F_143 ( V_2 , & V_451 , & V_452 ) ;
} else {
V_453 = & V_451 ;
}
V_333 = ( V_453 == & V_451 ) ?
V_326 : V_277 ;
F_142 ( V_2 , V_453 , V_333 , & V_335 ) ;
F_150 ( V_4 , & V_335 ) ;
}
static void F_200 ( struct V_92 * V_93 )
{
struct V_3 * V_4 = F_56 ( V_93 -> V_2 ) ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_251 * V_262 = F_136 ( V_93 -> V_102 ) ;
F_64 ( V_262 -> V_100 . V_214 != V_142 -> V_214 ) ;
if ( V_262 -> V_454 ) {
F_152 ( V_93 -> V_2 ) ;
F_194 ( V_93 -> V_2 , V_142 -> V_65 ) ;
}
V_142 -> V_56 . V_214 . V_322 = V_262 -> V_56 . V_321 . V_322 ;
F_199 ( V_4 ) ;
}
static void F_201 ( T_3 V_45 ,
struct V_433 * V_214 ,
bool V_455 ,
bool V_456 ,
int V_42 ,
int V_193 )
{
bool V_457 = ( V_45 & V_438 ) != 0 ;
if ( ! V_455 ) {
if ( ! V_456 ) {
V_214 -> V_56 [ V_193 ] . V_429 [ V_42 ] = V_457 ;
V_214 -> V_56 [ V_193 ] . V_430 [ V_42 ] =
V_45 & V_458 ;
V_214 -> V_56 [ V_193 ] . V_431 [ V_42 ] =
( V_45 >> V_437 ) &
V_459 ;
} else {
V_214 -> V_56 [ V_193 ] . V_429 [ V_376 ] = V_457 ;
V_214 -> V_56 [ V_193 ] . V_430 [ V_376 ] =
V_45 & V_458 ;
V_214 -> V_56 [ V_193 ] . V_431 [ V_376 ] =
( V_45 >> V_437 ) &
V_459 ;
}
} else {
if ( ! V_456 ) {
V_214 -> V_432 . V_429 [ V_42 ] = V_457 ;
V_214 -> V_432 . V_430 [ V_42 ] =
V_45 & V_458 ;
V_214 -> V_432 . V_431 [ V_42 ] =
( V_45 >> V_437 ) &
V_459 ;
} else {
V_214 -> V_432 . V_429 [ V_376 ] = V_457 ;
V_214 -> V_432 . V_430 [ V_376 ] =
V_45 & V_458 ;
V_214 -> V_432 . V_431 [ V_376 ] =
( V_45 >> V_437 ) &
V_459 ;
}
}
}
static void F_202 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_435 * V_360 = & V_4 -> V_56 . V_416 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_251 * V_262 = F_136 ( V_93 -> V_102 ) ;
struct V_433 * V_214 = & V_262 -> V_56 . V_321 . V_446 ;
enum V_65 V_65 = V_142 -> V_65 ;
int V_193 , V_42 , V_188 ;
T_3 V_436 ;
V_188 = F_114 ( V_2 ) ;
V_360 -> V_345 [ V_65 ] = F_3 ( F_151 ( V_65 ) ) ;
for ( V_193 = 0 ; V_193 <= V_188 ; V_193 ++ ) {
for ( V_42 = 0 ; V_42 < F_181 ( V_142 ) ; V_42 ++ )
V_360 -> V_66 [ V_65 ] [ V_42 ] [ V_193 ] =
F_3 ( F_184 ( V_65 , V_42 , V_193 ) ) ;
V_360 -> V_66 [ V_65 ] [ V_376 ] [ V_193 ] = F_3 ( F_185 ( V_65 , V_193 ) ) ;
}
for ( V_42 = 0 ; V_42 < F_181 ( V_142 ) ; V_42 ++ )
V_360 -> V_439 [ V_65 ] [ V_42 ] = F_3 ( F_186 ( V_65 , V_42 ) ) ;
V_360 -> V_439 [ V_65 ] [ V_376 ] = F_3 ( F_187 ( V_65 ) ) ;
if ( ! V_142 -> V_214 )
return;
V_360 -> V_355 [ V_65 ] = true ;
V_214 -> V_293 = V_360 -> V_345 [ V_65 ] ;
for ( V_193 = 0 ; V_193 <= V_188 ; V_193 ++ ) {
for ( V_42 = 0 ; V_42 < F_181 ( V_142 ) ; V_42 ++ ) {
V_436 = V_360 -> V_66 [ V_65 ] [ V_42 ] [ V_193 ] ;
F_201 ( V_436 , V_214 , false ,
false , V_42 , V_193 ) ;
}
V_436 = V_360 -> V_66 [ V_65 ] [ V_376 ] [ V_193 ] ;
F_201 ( V_436 , V_214 , false , true , V_42 , V_193 ) ;
}
for ( V_42 = 0 ; V_42 < F_181 ( V_142 ) ; V_42 ++ ) {
V_436 = V_360 -> V_439 [ V_65 ] [ V_42 ] ;
F_201 ( V_436 , V_214 , true , false , V_42 , 0 ) ;
}
V_436 = V_360 -> V_439 [ V_65 ] [ V_376 ] ;
F_201 ( V_436 , V_214 , true , true , V_42 , 0 ) ;
V_142 -> V_56 . V_214 . V_446 = * V_214 ;
}
void F_203 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_388 * V_389 = & V_4 -> V_56 . V_416 . V_389 ;
struct V_92 * V_93 ;
F_159 ( V_4 , V_389 ) ;
F_204 (crtc, &dev->mode_config.crtc_list, head)
F_202 ( V_93 ) ;
}
static void F_205 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_334 * V_360 = & V_4 -> V_56 . V_360 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_251 * V_262 = F_136 ( V_93 -> V_102 ) ;
struct V_317 * V_214 = & V_262 -> V_56 . V_321 . V_322 ;
enum V_65 V_65 = V_142 -> V_65 ;
static const T_7 V_460 [] = {
[ V_73 ] = V_364 ,
[ V_76 ] = V_365 ,
[ V_77 ] = V_366 ,
} ;
V_360 -> V_346 [ V_65 ] = F_3 ( V_460 [ V_65 ] ) ;
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
V_360 -> V_345 [ V_65 ] = F_3 ( F_151 ( V_65 ) ) ;
V_214 -> V_325 = V_142 -> V_214 ;
if ( V_214 -> V_325 ) {
T_1 V_14 = V_360 -> V_346 [ V_65 ] ;
V_214 -> V_56 [ 0 ] . V_44 = true ;
V_214 -> V_56 [ 0 ] . V_261 = ( V_14 & V_461 ) >> V_347 ;
V_214 -> V_56 [ 0 ] . V_285 = ( V_14 & V_462 ) >> V_348 ;
V_214 -> V_56 [ 0 ] . V_286 = V_14 & V_463 ;
V_214 -> V_293 = V_360 -> V_345 [ V_65 ] ;
} else {
int V_193 , V_188 = F_114 ( V_2 ) ;
for ( V_193 = 0 ; V_193 <= V_188 ; V_193 ++ )
V_214 -> V_56 [ V_193 ] . V_44 = true ;
}
V_142 -> V_56 . V_214 . V_322 = * V_214 ;
}
static void F_206 ( struct V_3 * V_4 ,
struct V_143 * V_56 )
{
enum V_65 V_65 ;
T_3 V_14 ;
F_145 (dev_priv, pipe) {
V_14 = F_3 ( F_57 ( V_65 ) ) ;
V_56 -> V_144 [ V_65 ] . V_101 =
( V_14 >> V_147 ) & ( V_215 | V_464 ) ;
V_56 -> V_144 [ V_65 ] . V_125 =
( V_14 >> V_145 ) & ( V_215 | V_464 ) ;
V_56 -> V_144 [ V_65 ] . V_146 [ 0 ] =
( V_14 >> F_58 ( 0 ) ) & ( V_215 | V_464 ) ;
V_56 -> V_144 [ V_65 ] . V_146 [ 1 ] =
( V_14 >> F_58 ( 1 ) ) & ( V_215 | V_464 ) ;
}
V_14 = F_3 ( V_108 ) ;
V_56 -> V_148 . V_66 = F_207 ( V_14 , V_110 ) ;
V_56 -> V_65 [ V_76 ] . V_125 = F_207 ( V_14 , V_149 ) ;
V_56 -> V_65 [ V_76 ] . V_101 = F_208 ( V_14 , V_150 ) ;
V_56 -> V_65 [ V_73 ] . V_101 = F_208 ( V_14 , V_151 ) ;
V_14 = F_3 ( V_152 ) ;
V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] = F_208 ( V_14 , V_153 ) ;
V_56 -> V_65 [ V_73 ] . V_125 = F_207 ( V_14 , V_154 ) ;
V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] = F_208 ( V_14 , V_155 ) ;
V_14 = F_3 ( V_61 ) ;
V_56 -> V_148 . V_125 = F_207 ( V_14 , V_114 ) ;
if ( F_22 ( V_4 ) ) {
V_14 = F_3 ( V_156 ) ;
V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] = F_208 ( V_14 , V_157 ) ;
V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] = F_208 ( V_14 , V_158 ) ;
V_14 = F_3 ( V_159 ) ;
V_56 -> V_65 [ V_77 ] . V_146 [ 1 ] = F_208 ( V_14 , V_160 ) ;
V_56 -> V_65 [ V_77 ] . V_146 [ 0 ] = F_208 ( V_14 , V_161 ) ;
V_14 = F_3 ( V_162 ) ;
V_56 -> V_65 [ V_77 ] . V_101 = F_208 ( V_14 , V_163 ) ;
V_56 -> V_65 [ V_77 ] . V_125 = F_207 ( V_14 , V_164 ) ;
V_14 = F_3 ( V_165 ) ;
V_56 -> V_148 . V_66 |= F_207 ( V_14 , V_166 ) << 9 ;
V_56 -> V_65 [ V_77 ] . V_146 [ 1 ] |= F_207 ( V_14 , V_167 ) << 8 ;
V_56 -> V_65 [ V_77 ] . V_146 [ 0 ] |= F_207 ( V_14 , V_168 ) << 8 ;
V_56 -> V_65 [ V_77 ] . V_101 |= F_207 ( V_14 , V_169 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] |= F_207 ( V_14 , V_170 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] |= F_207 ( V_14 , V_171 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_101 |= F_207 ( V_14 , V_172 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] |= F_207 ( V_14 , V_173 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] |= F_207 ( V_14 , V_174 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_101 |= F_207 ( V_14 , V_175 ) << 8 ;
} else {
V_14 = F_3 ( V_176 ) ;
V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] = F_208 ( V_14 , V_157 ) ;
V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] = F_208 ( V_14 , V_158 ) ;
V_14 = F_3 ( V_165 ) ;
V_56 -> V_148 . V_66 |= F_207 ( V_14 , V_166 ) << 9 ;
V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] |= F_207 ( V_14 , V_170 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] |= F_207 ( V_14 , V_171 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_101 |= F_207 ( V_14 , V_172 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] |= F_207 ( V_14 , V_173 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] |= F_207 ( V_14 , V_174 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_101 |= F_207 ( V_14 , V_175 ) << 8 ;
}
}
void F_209 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_56 ( V_2 ) ;
struct V_143 * V_56 = & V_4 -> V_56 . V_57 ;
struct V_191 * V_66 ;
enum V_65 V_65 ;
T_1 V_45 ;
F_206 ( V_4 , V_56 ) ;
F_210 (dev, plane) {
switch ( V_66 -> V_100 . type ) {
int V_146 ;
case V_198 :
V_66 -> V_56 . V_83 = 63 ;
break;
case V_210 :
V_66 -> V_56 . V_83 = F_32 ( V_2 , V_66 -> V_65 , 0 ) ;
break;
case V_211 :
V_146 = V_66 -> V_66 ;
V_66 -> V_56 . V_83 = F_32 ( V_2 , V_66 -> V_65 , V_146 + 1 ) ;
break;
}
}
V_56 -> V_58 = F_3 ( V_54 ) & V_55 ;
V_56 -> V_193 = V_187 ;
if ( F_22 ( V_4 ) ) {
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_45 = F_14 ( V_4 , V_52 ) ;
if ( V_45 & V_53 )
V_56 -> V_193 = V_189 ;
V_45 = F_14 ( V_4 , V_48 ) ;
V_45 |= V_51 ;
F_15 ( V_4 , V_48 , V_45 ) ;
if ( F_16 ( ( F_14 ( V_4 , V_48 ) &
V_51 ) == 0 , 3 ) ) {
F_11 ( L_49
L_50 ) ;
V_4 -> V_56 . V_188 = V_189 ;
} else {
V_45 = F_14 ( V_4 , V_48 ) ;
if ( ( V_45 & V_49 ) == 0 )
V_56 -> V_193 = V_190 ;
}
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
F_145 (dev_priv, pipe)
F_11 ( L_51 ,
F_34 ( V_65 ) , V_56 -> V_65 [ V_65 ] . V_101 , V_56 -> V_65 [ V_65 ] . V_125 ,
V_56 -> V_65 [ V_65 ] . V_146 [ 0 ] , V_56 -> V_65 [ V_65 ] . V_146 [ 1 ] ) ;
F_11 ( L_52 ,
V_56 -> V_148 . V_66 , V_56 -> V_148 . V_125 , V_56 -> V_193 , V_56 -> V_58 ) ;
}
void F_211 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_334 * V_360 = & V_4 -> V_56 . V_360 ;
struct V_92 * V_93 ;
F_43 (dev, crtc)
F_205 ( V_93 ) ;
V_360 -> V_332 [ 0 ] = F_3 ( V_363 ) ;
V_360 -> V_332 [ 1 ] = F_3 ( V_362 ) ;
V_360 -> V_332 [ 2 ] = F_3 ( V_361 ) ;
V_360 -> V_343 [ 0 ] = F_3 ( V_373 ) ;
if ( F_70 ( V_2 ) -> V_270 >= 7 ) {
V_360 -> V_343 [ 1 ] = F_3 ( V_374 ) ;
V_360 -> V_343 [ 2 ] = F_3 ( V_375 ) ;
}
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
V_360 -> V_333 = ( F_3 ( V_367 ) & V_368 ) ?
V_277 : V_326 ;
else if ( F_121 ( V_2 ) )
V_360 -> V_333 = ( F_3 ( V_369 ) & V_370 ) ?
V_277 : V_326 ;
V_360 -> V_336 =
! ( F_3 ( V_371 ) & V_372 ) ;
}
void F_212 ( struct V_92 * V_93 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
if ( V_4 -> V_123 . V_465 )
V_4 -> V_123 . V_465 ( V_93 ) ;
}
bool F_213 ( struct V_1 * V_2 , T_8 V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_466 ;
F_214 ( & V_467 ) ;
V_466 = F_7 ( V_468 ) ;
if ( V_466 & V_469 ) {
F_215 ( L_53 ) ;
return false ;
}
V_466 = ( V_470 << V_471 ) |
( V_45 << V_472 ) | V_473 ;
F_216 ( V_468 , V_466 ) ;
F_217 ( V_468 ) ;
V_466 |= V_469 ;
F_216 ( V_468 , V_466 ) ;
return true ;
}
static void F_218 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_474 = F_3 ( V_475 ) ;
T_8 V_476 , V_477 , V_478 , V_479 ;
F_219 ( & V_467 ) ;
F_216 ( V_480 , F_3 ( V_480 ) | V_481 ) ;
F_216 ( V_482 , F_3 ( V_482 ) | V_483 ) ;
F_2 ( V_484 , 100000 ) ;
F_2 ( V_485 , 100000 ) ;
F_2 ( V_486 , 90000 ) ;
F_2 ( V_487 , 80000 ) ;
F_2 ( V_488 , 1 ) ;
V_476 = ( V_474 & V_489 ) >> V_490 ;
V_477 = ( V_474 & V_491 ) ;
V_478 = ( V_474 & V_492 ) >>
V_493 ;
V_479 = ( F_3 ( F_220 ( V_478 ) ) & V_494 ) >>
V_495 ;
V_4 -> V_34 . V_476 = V_476 ;
V_4 -> V_34 . V_478 = V_478 ;
V_4 -> V_34 . V_496 = V_478 ;
V_4 -> V_34 . V_497 = V_477 ;
V_4 -> V_34 . V_498 = V_478 ;
F_8 ( L_54 ,
V_476 , V_477 , V_478 ) ;
F_2 ( V_499 , V_500 | V_501 ) ;
F_2 ( V_502 , V_479 ) ;
F_23 ( V_502 ) ;
V_474 |= V_503 ;
F_2 ( V_475 , V_474 ) ;
if ( F_221 ( ( F_3 ( V_468 ) & V_469 ) == 0 , 10 ) )
F_17 ( L_55 ) ;
F_222 ( 1 ) ;
F_213 ( V_2 , V_478 ) ;
V_4 -> V_34 . V_504 = F_3 ( V_505 ) +
F_3 ( V_506 ) + F_3 ( V_507 ) ;
V_4 -> V_34 . V_508 = F_223 ( V_509 ) ;
V_4 -> V_34 . V_510 = F_3 ( V_511 ) ;
V_4 -> V_34 . V_512 = F_224 () ;
F_225 ( & V_467 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_466 ;
F_219 ( & V_467 ) ;
V_466 = F_7 ( V_468 ) ;
F_2 ( V_499 , F_3 ( V_499 ) & ~ V_501 ) ;
F_2 ( V_513 , V_514 ) ;
F_2 ( V_515 , F_3 ( V_515 ) & ~ V_516 ) ;
F_2 ( V_517 , V_516 ) ;
F_2 ( V_518 , F_3 ( V_518 ) | V_516 ) ;
F_213 ( V_2 , V_4 -> V_34 . V_478 ) ;
F_222 ( 1 ) ;
V_466 |= V_469 ;
F_2 ( V_468 , V_466 ) ;
F_222 ( 1 ) ;
F_225 ( & V_467 ) ;
}
static T_1 F_227 ( struct V_3 * V_4 , T_8 V_45 )
{
T_1 V_519 ;
if ( F_113 ( V_4 -> V_2 ) ) {
V_519 = ( V_4 -> V_46 . V_520 ) << 23 ;
if ( V_45 <= V_4 -> V_46 . V_521 )
V_519 |= ( V_4 -> V_46 . V_521 ) << 14 ;
} else {
V_519 = V_4 -> V_46 . V_520 << 24 ;
if ( V_45 <= V_4 -> V_46 . V_521 )
V_519 |= V_4 -> V_46 . V_521 << 16 ;
}
return V_519 ;
}
static void F_228 ( struct V_3 * V_4 , T_8 V_45 )
{
int V_522 ;
T_1 V_523 = 0 , V_524 = 0 ;
T_1 V_525 = 0 , V_526 = 0 ;
V_522 = V_4 -> V_46 . V_527 ;
switch ( V_4 -> V_46 . V_527 ) {
case V_528 :
if ( V_45 > V_4 -> V_46 . V_529 + 1 && V_45 > V_4 -> V_46 . V_530 )
V_522 = V_531 ;
break;
case V_531 :
if ( V_45 <= V_4 -> V_46 . V_529 && V_45 < V_4 -> V_46 . V_530 )
V_522 = V_528 ;
else if ( V_45 >= V_4 -> V_46 . V_532 && V_45 > V_4 -> V_46 . V_530 )
V_522 = V_533 ;
break;
case V_533 :
if ( V_45 < ( V_4 -> V_46 . V_534 + V_4 -> V_46 . V_532 ) > > 1 && V_45 < V_4 -> V_46 . V_530 )
V_522 = V_531 ;
break;
}
if ( V_45 <= V_4 -> V_46 . V_521 )
V_522 = V_528 ;
if ( V_45 >= V_4 -> V_46 . V_520 )
V_522 = V_533 ;
if ( V_522 == V_4 -> V_46 . V_527 )
return;
switch ( V_522 ) {
case V_528 :
V_525 = 16000 ;
V_523 = 95 ;
V_526 = 32000 ;
V_524 = 85 ;
break;
case V_531 :
V_525 = 13000 ;
V_523 = 90 ;
V_526 = 32000 ;
V_524 = 75 ;
break;
case V_533 :
V_525 = 10000 ;
V_523 = 85 ;
V_526 = 32000 ;
V_524 = 60 ;
break;
}
F_2 ( V_535 ,
F_229 ( V_4 , V_525 ) ) ;
F_2 ( V_536 ,
F_229 ( V_4 , ( V_525 * V_523 / 100 ) ) ) ;
F_2 ( V_537 ,
F_229 ( V_4 , V_526 ) ) ;
F_2 ( V_538 ,
F_229 ( V_4 , ( V_526 * V_524 / 100 ) ) ) ;
F_2 ( V_539 ,
V_540 |
V_541 |
V_542 |
V_543 |
V_544 |
V_545 ) ;
V_4 -> V_46 . V_527 = V_522 ;
V_4 -> V_46 . V_546 = V_523 ;
V_4 -> V_46 . V_547 = V_524 ;
V_4 -> V_46 . V_548 = 0 ;
}
static T_1 F_230 ( struct V_3 * V_4 , T_8 V_45 )
{
T_1 V_549 = 0 ;
if ( V_45 > V_4 -> V_46 . V_521 )
V_549 |= V_550 | V_551 | V_552 ;
if ( V_45 < V_4 -> V_46 . V_520 )
V_549 |= V_553 | V_554 ;
V_549 &= V_4 -> V_555 ;
return F_231 ( V_4 , ~ V_549 ) ;
}
static void F_232 ( struct V_1 * V_2 , T_8 V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_4 ( V_2 , 0 , V_556 ) )
return;
F_64 ( ! F_233 ( & V_4 -> V_46 . V_47 ) ) ;
F_64 ( V_45 > V_4 -> V_46 . V_557 ) ;
F_64 ( V_45 < V_4 -> V_46 . V_558 ) ;
if ( V_45 != V_4 -> V_46 . V_530 ) {
F_228 ( V_4 , V_45 ) ;
if ( F_113 ( V_2 ) )
F_2 ( V_559 ,
F_234 ( V_45 ) ) ;
else if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
F_2 ( V_559 ,
F_235 ( V_45 ) ) ;
else
F_2 ( V_559 ,
F_236 ( V_45 ) |
F_237 ( 0 ) |
V_560 ) ;
}
F_2 ( V_561 , F_227 ( V_4 , V_45 ) ) ;
F_2 ( V_562 , F_230 ( V_4 , V_45 ) ) ;
F_23 ( V_559 ) ;
V_4 -> V_46 . V_530 = V_45 ;
F_238 ( F_239 ( V_4 , V_45 ) ) ;
}
static void F_240 ( struct V_1 * V_2 , T_8 V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_64 ( ! F_233 ( & V_4 -> V_46 . V_47 ) ) ;
F_64 ( V_45 > V_4 -> V_46 . V_557 ) ;
F_64 ( V_45 < V_4 -> V_46 . V_558 ) ;
if ( F_241 ( F_22 ( V_2 ) && ( V_45 & 1 ) ,
L_56 ) )
V_45 &= ~ 1 ;
F_2 ( V_562 , F_230 ( V_4 , V_45 ) ) ;
if ( V_45 != V_4 -> V_46 . V_530 ) {
F_15 ( V_4 , V_563 , V_45 ) ;
if ( ! F_22 ( V_4 ) )
F_228 ( V_4 , V_45 ) ;
}
V_4 -> V_46 . V_530 = V_45 ;
F_238 ( F_239 ( V_4 , V_45 ) ) ;
}
static void F_242 ( struct V_3 * V_4 )
{
T_1 V_45 = V_4 -> V_46 . V_564 ;
if ( V_4 -> V_46 . V_530 <= V_45 )
return;
F_243 ( V_4 , V_565 ) ;
F_240 ( V_4 -> V_2 , V_45 ) ;
F_244 ( V_4 , V_565 ) ;
}
void F_245 ( struct V_3 * V_4 )
{
F_13 ( & V_4 -> V_46 . V_47 ) ;
if ( V_4 -> V_46 . V_94 ) {
if ( V_4 -> V_555 & ( V_550 | V_553 ) )
F_246 ( V_4 ) ;
F_2 ( V_562 ,
F_230 ( V_4 , V_4 -> V_46 . V_530 ) ) ;
}
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
void F_247 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
if ( V_4 -> V_46 . V_94 ) {
if ( F_21 ( V_2 ) || F_22 ( V_2 ) )
F_242 ( V_4 ) ;
else
F_232 ( V_4 -> V_2 , V_4 -> V_46 . V_564 ) ;
V_4 -> V_46 . V_548 = 0 ;
F_2 ( V_562 , 0xffffffff ) ;
}
F_18 ( & V_4 -> V_46 . V_47 ) ;
F_248 ( & V_4 -> V_46 . V_566 ) ;
while ( ! F_249 ( & V_4 -> V_46 . V_567 ) )
F_250 ( V_4 -> V_46 . V_567 . V_568 ) ;
F_251 ( & V_4 -> V_46 . V_566 ) ;
}
void F_252 ( struct V_3 * V_4 ,
struct V_569 * V_46 ,
unsigned long V_570 )
{
if ( ! ( V_4 -> V_571 . V_572 &&
V_4 -> V_46 . V_94 &&
V_4 -> V_46 . V_530 < V_4 -> V_46 . V_520 ) )
return;
if ( V_46 && F_253 ( V_509 , V_570 + V_573 ) )
V_46 = NULL ;
F_248 ( & V_4 -> V_46 . V_566 ) ;
if ( V_46 == NULL || F_249 ( & V_46 -> V_574 ) ) {
F_219 ( & V_4 -> V_575 ) ;
if ( V_4 -> V_46 . V_576 ) {
V_4 -> V_46 . V_577 = true ;
F_254 ( V_4 -> V_578 , & V_4 -> V_46 . V_579 ) ;
}
F_225 ( & V_4 -> V_575 ) ;
if ( V_46 != NULL ) {
F_255 ( & V_46 -> V_574 , & V_4 -> V_46 . V_567 ) ;
V_46 -> V_580 ++ ;
} else
V_4 -> V_46 . V_580 ++ ;
}
F_251 ( & V_4 -> V_46 . V_566 ) ;
}
void F_256 ( struct V_1 * V_2 , T_8 V_45 )
{
if ( F_21 ( V_2 ) || F_22 ( V_2 ) )
F_240 ( V_2 , V_45 ) ;
else
F_232 ( V_2 , V_45 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_581 , 0 ) ;
F_2 ( V_582 , 0 ) ;
}
static void F_258 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_581 , 0 ) ;
F_2 ( V_559 , 1 << 31 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_581 , 0 ) ;
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_243 ( V_4 , V_583 ) ;
F_2 ( V_581 , 0 ) ;
F_244 ( V_4 , V_583 ) ;
}
static void F_261 ( struct V_1 * V_2 , T_1 V_584 )
{
if ( F_21 ( V_2 ) || F_22 ( V_2 ) ) {
if ( V_584 & ( V_585 | F_262 ( 1 ) ) )
V_584 = V_586 ;
else
V_584 = 0 ;
}
if ( F_263 ( V_2 ) )
F_11 ( L_57 ,
( V_584 & V_586 ) ? L_58 : L_59 ,
( V_584 & V_587 ) ? L_58 : L_59 ,
( V_584 & V_588 ) ? L_58 : L_59 ) ;
else
F_11 ( L_60 ,
( V_584 & V_586 ) ? L_58 : L_59 ) ;
}
static int F_264 ( const struct V_1 * V_2 , int V_589 )
{
if ( F_70 ( V_2 ) -> V_270 < 6 )
return 0 ;
if ( V_589 >= 0 ) {
int V_549 ;
if ( F_263 ( V_2 ) )
V_549 = V_590 | V_591 |
V_592 ;
else
V_549 = V_590 ;
if ( ( V_589 & V_549 ) != V_589 )
F_11 ( L_61 ,
V_589 & V_549 , V_589 , V_549 ) ;
return V_589 & V_549 ;
}
if ( F_121 ( V_2 ) )
return ( V_590 | V_591 ) ;
return V_590 ;
}
int F_265 ( const struct V_1 * V_2 )
{
return V_593 . V_589 ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_594 ;
T_1 V_595 = 0 ;
int V_185 ;
V_4 -> V_46 . V_530 = 0 ;
if ( F_156 ( V_2 ) ) {
V_594 = F_3 ( V_596 ) ;
V_4 -> V_46 . V_532 = ( V_594 >> 16 ) & 0xff ;
V_4 -> V_46 . V_534 = ( V_594 >> 8 ) & 0xff ;
V_4 -> V_46 . V_558 = ( V_594 >> 0 ) & 0xff ;
} else {
V_594 = F_3 ( V_597 ) ;
V_4 -> V_46 . V_532 = ( V_594 >> 0 ) & 0xff ;
V_4 -> V_46 . V_534 = ( V_594 >> 8 ) & 0xff ;
V_4 -> V_46 . V_558 = ( V_594 >> 16 ) & 0xff ;
}
V_4 -> V_46 . V_557 = V_4 -> V_46 . V_532 ;
V_4 -> V_46 . V_529 = V_4 -> V_46 . V_534 ;
if ( F_116 ( V_2 ) || F_117 ( V_2 ) ||
F_267 ( V_2 ) || F_268 ( V_2 ) ) {
V_185 = F_115 ( V_4 ,
V_598 ,
& V_595 ) ;
if ( 0 == V_185 )
V_4 -> V_46 . V_529 =
F_269 ( T_8 ,
( ( V_595 >> 8 ) & 0xff ) ,
V_4 -> V_46 . V_558 ,
V_4 -> V_46 . V_557 ) ;
}
if ( F_267 ( V_2 ) || F_268 ( V_2 ) ) {
V_4 -> V_46 . V_532 *= V_599 ;
V_4 -> V_46 . V_534 *= V_599 ;
V_4 -> V_46 . V_558 *= V_599 ;
V_4 -> V_46 . V_557 *= V_599 ;
V_4 -> V_46 . V_529 *= V_599 ;
}
V_4 -> V_46 . V_564 = V_4 -> V_46 . V_558 ;
if ( V_4 -> V_46 . V_520 == 0 )
V_4 -> V_46 . V_520 = V_4 -> V_46 . V_557 ;
if ( V_4 -> V_46 . V_521 == 0 ) {
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
V_4 -> V_46 . V_521 =
F_124 ( int , V_4 -> V_46 . V_529 ,
F_270 ( V_4 , 450 ) ) ;
else
V_4 -> V_46 . V_521 =
V_4 -> V_46 . V_558 ;
}
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_243 ( V_4 , V_583 ) ;
F_266 ( V_2 ) ;
if ( F_4 ( V_2 , 0 , V_556 ) ) {
F_244 ( V_4 , V_583 ) ;
return;
}
F_2 ( V_600 ,
F_234 ( V_4 -> V_46 . V_534 ) ) ;
F_2 ( V_601 ,
F_229 ( V_4 , 1000000 ) ) ;
F_2 ( V_602 , 0xa ) ;
V_4 -> V_46 . V_527 = V_533 ;
F_232 ( V_4 -> V_2 , V_4 -> V_46 . V_521 ) ;
F_244 ( V_4 , V_583 ) ;
}
static void F_272 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_603 * V_604 ;
T_3 V_605 = 0 ;
int V_606 ;
F_2 ( V_607 , 0 ) ;
F_243 ( V_4 , V_583 ) ;
F_2 ( V_581 , 0 ) ;
if ( F_267 ( V_2 ) )
F_2 ( V_608 , 108 << 16 ) ;
else
F_2 ( V_608 , 54 << 16 ) ;
F_2 ( V_609 , 125000 ) ;
F_2 ( V_610 , 25 ) ;
F_273 (ring, dev_priv, unused)
F_2 ( F_274 ( V_604 -> V_611 ) , 10 ) ;
if ( F_275 ( V_2 ) )
F_2 ( V_612 , 0xA ) ;
F_2 ( V_613 , 0 ) ;
F_2 ( V_614 , 25 ) ;
F_2 ( V_615 , 25 ) ;
if ( F_265 ( V_2 ) & V_590 )
V_605 = V_586 ;
F_276 ( L_62 , ( V_605 & V_586 ) ?
L_58 : L_59 ) ;
if ( F_277 ( V_2 , 0 , V_616 ) ||
F_4 ( V_2 , 0 , V_556 ) ) {
F_2 ( V_617 , 625 ) ;
F_2 ( V_581 , V_618 |
V_585 |
V_605 ) ;
} else {
F_2 ( V_617 , 37500 ) ;
F_2 ( V_581 , V_618 |
F_262 ( 1 ) |
V_605 ) ;
}
if ( ( F_156 ( V_2 ) && ( F_278 ( V_2 ) < V_9 ) ) ||
( ( F_279 ( V_2 ) || F_280 ( V_2 ) ) && ( F_278 ( V_2 ) <= V_619 ) ) )
F_2 ( V_582 , 0 ) ;
else
F_2 ( V_582 , ( V_605 & V_586 ) ?
( V_620 | V_621 ) : 0 ) ;
F_244 ( V_4 , V_583 ) ;
}
static void F_281 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_603 * V_604 ;
T_3 V_605 = 0 ;
int V_606 ;
F_2 ( V_607 , 0 ) ;
F_243 ( V_4 , V_583 ) ;
F_2 ( V_581 , 0 ) ;
F_266 ( V_2 ) ;
F_2 ( V_608 , 40 << 16 ) ;
F_2 ( V_609 , 125000 ) ;
F_2 ( V_610 , 25 ) ;
F_273 (ring, dev_priv, unused)
F_2 ( F_274 ( V_604 -> V_611 ) , 10 ) ;
F_2 ( V_613 , 0 ) ;
if ( F_117 ( V_2 ) )
F_2 ( V_617 , 625 ) ;
else
F_2 ( V_617 , 50000 ) ;
if ( F_265 ( V_2 ) & V_590 )
V_605 = V_586 ;
F_261 ( V_2 , V_605 ) ;
if ( F_117 ( V_2 ) )
F_2 ( V_581 , V_618 |
V_585 |
V_605 ) ;
else
F_2 ( V_581 , V_618 |
F_262 ( 1 ) |
V_605 ) ;
F_2 ( V_559 ,
F_235 ( V_4 -> V_46 . V_534 ) ) ;
F_2 ( V_600 ,
F_235 ( V_4 -> V_46 . V_534 ) ) ;
F_2 ( V_601 , 100000000 / 128 ) ;
F_2 ( V_561 ,
V_4 -> V_46 . V_520 << 24 |
V_4 -> V_46 . V_521 << 16 ) ;
F_2 ( V_536 , 7600000 / 128 ) ;
F_2 ( V_538 , 31300000 / 128 ) ;
F_2 ( V_535 , 66000 ) ;
F_2 ( V_537 , 350000 ) ;
F_2 ( V_602 , 10 ) ;
F_2 ( V_539 ,
V_540 |
V_541 |
V_542 |
V_543 |
V_544 |
V_545 ) ;
V_4 -> V_46 . V_527 = V_533 ;
F_232 ( V_4 -> V_2 , V_4 -> V_46 . V_564 ) ;
F_244 ( V_4 , V_583 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_603 * V_604 ;
T_1 V_622 , V_623 = 0 , V_605 = 0 ;
T_1 V_624 ;
int V_625 ;
int V_42 , V_185 ;
F_64 ( ! F_233 ( & V_4 -> V_46 . V_47 ) ) ;
F_2 ( V_607 , 0 ) ;
if ( ( V_624 = F_3 ( V_626 ) ) ) {
F_17 ( L_63 , V_624 ) ;
F_2 ( V_626 , V_624 ) ;
}
F_243 ( V_4 , V_583 ) ;
F_266 ( V_2 ) ;
F_2 ( V_581 , 0 ) ;
F_2 ( V_627 , 1000 << 16 ) ;
F_2 ( V_608 , 40 << 16 | 30 ) ;
F_2 ( V_628 , 30 ) ;
F_2 ( V_609 , 125000 ) ;
F_2 ( V_610 , 25 ) ;
F_273 (ring, dev_priv, i)
F_2 ( F_274 ( V_604 -> V_611 ) , 10 ) ;
F_2 ( V_613 , 0 ) ;
F_2 ( V_629 , 1000 ) ;
if ( F_121 ( V_2 ) )
F_2 ( V_617 , 125000 ) ;
else
F_2 ( V_617 , 50000 ) ;
F_2 ( V_630 , 150000 ) ;
F_2 ( V_631 , 64000 ) ;
V_625 = F_265 ( V_4 -> V_2 ) ;
if ( V_625 & V_590 )
V_605 |= V_586 ;
if ( ! F_116 ( V_2 ) ) {
if ( V_625 & V_591 )
V_605 |= V_587 ;
if ( V_625 & V_592 )
V_605 |= V_588 ;
}
F_261 ( V_2 , V_605 ) ;
F_2 ( V_581 ,
V_605 |
F_262 ( 1 ) |
V_618 ) ;
F_2 ( V_601 , 50000 ) ;
F_2 ( V_602 , 10 ) ;
V_185 = F_283 ( V_4 , V_632 , 0 ) ;
if ( V_185 )
F_8 ( L_64 ) ;
V_185 = F_115 ( V_4 , V_633 , & V_623 ) ;
if ( ! V_185 && ( V_623 & ( 1 << 31 ) ) ) {
F_8 ( L_65 ,
( V_4 -> V_46 . V_520 & 0xff ) * 50 ,
( V_623 & 0xff ) * 50 ) ;
V_4 -> V_46 . V_557 = V_623 & 0xff ;
}
V_4 -> V_46 . V_527 = V_533 ;
F_232 ( V_4 -> V_2 , V_4 -> V_46 . V_564 ) ;
V_622 = 0 ;
V_185 = F_115 ( V_4 , V_634 , & V_622 ) ;
if ( F_127 ( V_2 ) && V_185 ) {
F_8 ( L_66 ) ;
} else if ( F_127 ( V_2 ) && ( F_284 ( V_622 & 0xff ) < 450 ) ) {
F_8 ( L_67 ,
F_284 ( V_622 & 0xff ) , 450 ) ;
V_622 &= 0xffff00 ;
V_622 |= F_285 ( 450 ) ;
V_185 = F_283 ( V_4 , V_635 , V_622 ) ;
if ( V_185 )
F_17 ( L_68 ) ;
}
F_244 ( V_4 , V_583 ) ;
}
static void F_286 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_558 = 15 ;
unsigned int V_636 ;
unsigned int V_637 , V_638 ;
unsigned int V_639 , V_640 ;
int V_641 = 180 ;
struct V_642 * V_643 ;
F_64 ( ! F_233 ( & V_4 -> V_46 . V_47 ) ) ;
V_643 = F_287 ( 0 ) ;
if ( V_643 ) {
V_637 = V_643 -> V_644 . V_557 ;
F_288 ( V_643 ) ;
} else {
V_637 = V_645 ;
}
V_637 /= 1000 ;
V_638 = F_3 ( V_646 ) & 0xf ;
V_638 = F_289 ( V_638 , 8 , 3 ) ;
if ( F_267 ( V_2 ) || F_268 ( V_2 ) ) {
V_640 = V_4 -> V_46 . V_558 / V_599 ;
V_639 = V_4 -> V_46 . V_557 / V_599 ;
} else {
V_640 = V_4 -> V_46 . V_558 ;
V_639 = V_4 -> V_46 . V_557 ;
}
for ( V_636 = V_639 ; V_636 >= V_640 ; V_636 -- ) {
int V_647 = V_639 - V_636 ;
unsigned int V_648 = 0 , V_649 = 0 ;
if ( F_267 ( V_2 ) || F_268 ( V_2 ) ) {
V_649 = V_636 ;
} else if ( F_70 ( V_2 ) -> V_270 >= 8 ) {
V_649 = F_51 ( V_638 , V_636 ) ;
} else if ( F_116 ( V_2 ) ) {
V_649 = F_289 ( V_636 , 5 , 4 ) ;
V_649 = F_51 ( V_638 , V_649 ) ;
} else {
if ( V_636 < V_558 )
V_648 = 800 ;
else
V_648 = V_637 - ( ( V_647 * V_641 ) / 2 ) ;
V_648 = F_109 ( V_648 , 100 ) ;
}
F_283 ( V_4 ,
V_632 ,
V_648 << V_650 |
V_649 << V_651 |
V_636 ) ;
}
}
void F_290 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_291 ( V_2 ) )
return;
F_13 ( & V_4 -> V_46 . V_47 ) ;
F_286 ( V_2 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
static int F_292 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_45 , V_652 ;
V_45 = F_14 ( V_4 , V_653 ) ;
switch ( F_70 ( V_2 ) -> V_654 ) {
case 8 :
V_652 = ( V_45 >> V_655 ) ;
break;
case 12 :
V_652 = ( V_45 >> V_656 ) ;
break;
case 16 :
default:
V_652 = ( V_45 >> V_657 ) ;
break;
}
V_652 = ( V_652 & V_658 ) ;
return V_652 ;
}
static int F_293 ( struct V_3 * V_4 )
{
T_1 V_45 , V_659 ;
V_45 = F_14 ( V_4 , V_660 ) ;
V_659 = ( V_45 >> V_661 ) & V_662 ;
return V_659 ;
}
static int F_294 ( struct V_3 * V_4 )
{
T_1 V_45 , V_663 ;
V_45 = F_14 ( V_4 , V_653 ) ;
V_663 = ( V_45 & V_658 ) ;
return V_663 ;
}
static int F_295 ( struct V_3 * V_4 )
{
T_1 V_45 , V_663 ;
V_45 = F_296 ( V_4 , V_664 ) ;
V_663 = ( V_45 & V_665 ) >> V_666 ;
return V_663 ;
}
static int F_297 ( struct V_3 * V_4 )
{
T_1 V_45 , V_652 ;
V_45 = F_296 ( V_4 , V_664 ) ;
V_652 = ( V_45 & V_667 ) >> V_668 ;
V_652 = F_65 ( T_1 , V_652 , 0xea ) ;
return V_652 ;
}
static int F_298 ( struct V_3 * V_4 )
{
T_1 V_45 , V_659 ;
V_45 = F_296 ( V_4 , V_669 ) ;
V_659 = ( V_45 & V_670 ) >> V_671 ;
V_45 = F_296 ( V_4 , V_672 ) ;
V_659 |= ( V_45 & V_673 ) << 5 ;
return V_659 ;
}
static int F_299 ( struct V_3 * V_4 )
{
T_1 V_45 ;
V_45 = F_14 ( V_4 , V_674 ) & 0xff ;
return F_124 ( T_1 , V_45 , 0xc0 ) ;
}
static void F_300 ( struct V_3 * V_4 )
{
unsigned long V_675 = F_3 ( V_676 ) & ~ 4095 ;
F_64 ( V_675 != V_4 -> V_571 . V_677 +
V_4 -> V_678 -> V_679 -> V_383 ) ;
}
static void F_301 ( struct V_3 * V_4 )
{
unsigned long V_675 = F_3 ( V_676 ) & ~ 4095 ;
F_64 ( ( V_675 >> V_680 ) == 0 ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_681 , V_682 ;
struct V_683 * V_684 = & V_4 -> V_684 ;
T_1 V_685 ;
int V_686 = 32 * 1024 ;
F_64 ( ! F_233 ( & V_2 -> V_687 ) ) ;
V_685 = F_3 ( V_676 ) ;
if ( ( V_685 >> V_680 ) == 0 ) {
F_8 ( L_69 ) ;
V_682 = ( V_4 -> V_571 . V_677 +
( V_684 -> V_688 - V_686 ) ) ;
V_681 = ( V_682 & ( ~ 4095 ) ) ;
F_2 ( V_676 , V_681 ) ;
}
F_8 ( L_70 , F_3 ( V_676 ) ) ;
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_243 * V_689 ;
unsigned long V_681 ;
T_1 V_685 ;
int V_686 = 24 * 1024 ;
F_64 ( ! F_233 ( & V_2 -> V_687 ) ) ;
V_685 = F_3 ( V_676 ) ;
if ( V_685 ) {
int V_690 ;
V_690 = ( V_685 & ( ~ 4095 ) ) - V_4 -> V_571 . V_677 ;
V_689 = F_304 ( V_4 -> V_2 ,
V_690 ,
V_691 ,
V_686 ) ;
goto V_692;
}
F_8 ( L_69 ) ;
V_689 = F_305 ( V_2 , V_686 ) ;
if ( ! V_689 ) {
F_215 ( L_71 ) ;
return;
}
V_681 = V_4 -> V_571 . V_677 + V_689 -> V_679 -> V_383 ;
F_2 ( V_676 , V_681 ) ;
V_692:
F_8 ( L_70 , F_3 ( V_676 ) ) ;
V_4 -> V_678 = V_689 ;
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_64 ( ! V_4 -> V_678 ) )
return;
F_307 ( & V_4 -> V_678 -> V_100 ) ;
V_4 -> V_678 = NULL ;
}
static void F_308 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_45 ;
F_303 ( V_2 ) ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_45 = F_14 ( V_4 , V_693 ) ;
switch ( ( V_45 >> 6 ) & 3 ) {
case 0 :
case 1 :
V_4 -> V_24 = 800 ;
break;
case 2 :
V_4 -> V_24 = 1066 ;
break;
case 3 :
V_4 -> V_24 = 1333 ;
break;
}
F_8 ( L_72 , V_4 -> V_24 ) ;
V_4 -> V_46 . V_557 = F_297 ( V_4 ) ;
V_4 -> V_46 . V_532 = V_4 -> V_46 . V_557 ;
F_8 ( L_73 ,
F_239 ( V_4 , V_4 -> V_46 . V_557 ) ,
V_4 -> V_46 . V_557 ) ;
V_4 -> V_46 . V_529 = F_298 ( V_4 ) ;
F_8 ( L_74 ,
F_239 ( V_4 , V_4 -> V_46 . V_529 ) ,
V_4 -> V_46 . V_529 ) ;
V_4 -> V_46 . V_534 = F_295 ( V_4 ) ;
F_8 ( L_75 ,
F_239 ( V_4 , V_4 -> V_46 . V_534 ) ,
V_4 -> V_46 . V_534 ) ;
V_4 -> V_46 . V_558 = F_299 ( V_4 ) ;
F_8 ( L_76 ,
F_239 ( V_4 , V_4 -> V_46 . V_558 ) ,
V_4 -> V_46 . V_558 ) ;
V_4 -> V_46 . V_564 = V_4 -> V_46 . V_558 ;
if ( V_4 -> V_46 . V_520 == 0 )
V_4 -> V_46 . V_520 = V_4 -> V_46 . V_557 ;
if ( V_4 -> V_46 . V_521 == 0 )
V_4 -> V_46 . V_521 = V_4 -> V_46 . V_558 ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_45 ;
F_302 ( V_2 ) ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
F_13 ( & V_4 -> V_694 ) ;
V_45 = F_310 ( V_4 , V_695 ) ;
F_18 ( & V_4 -> V_694 ) ;
switch ( ( V_45 >> 2 ) & 0x7 ) {
case 3 :
V_4 -> V_24 = 2000 ;
break;
default:
V_4 -> V_24 = 1600 ;
break;
}
F_8 ( L_72 , V_4 -> V_24 ) ;
V_4 -> V_46 . V_557 = F_292 ( V_4 ) ;
V_4 -> V_46 . V_532 = V_4 -> V_46 . V_557 ;
F_8 ( L_73 ,
F_239 ( V_4 , V_4 -> V_46 . V_557 ) ,
V_4 -> V_46 . V_557 ) ;
V_4 -> V_46 . V_529 = F_293 ( V_4 ) ;
F_8 ( L_74 ,
F_239 ( V_4 , V_4 -> V_46 . V_529 ) ,
V_4 -> V_46 . V_529 ) ;
V_4 -> V_46 . V_534 = F_294 ( V_4 ) ;
F_8 ( L_77 ,
F_239 ( V_4 , V_4 -> V_46 . V_534 ) ,
V_4 -> V_46 . V_534 ) ;
V_4 -> V_46 . V_558 = V_4 -> V_46 . V_529 ;
F_8 ( L_76 ,
F_239 ( V_4 , V_4 -> V_46 . V_558 ) ,
V_4 -> V_46 . V_558 ) ;
F_241 ( ( V_4 -> V_46 . V_557 |
V_4 -> V_46 . V_529 |
V_4 -> V_46 . V_534 |
V_4 -> V_46 . V_558 ) & 1 ,
L_78 ) ;
V_4 -> V_46 . V_564 = V_4 -> V_46 . V_558 ;
if ( V_4 -> V_46 . V_520 == 0 )
V_4 -> V_46 . V_520 = V_4 -> V_46 . V_557 ;
if ( V_4 -> V_46 . V_521 == 0 )
V_4 -> V_46 . V_521 = V_4 -> V_46 . V_558 ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
F_306 ( V_2 ) ;
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_603 * V_604 ;
T_1 V_624 , V_45 , V_625 = 0 , V_685 ;
int V_42 ;
F_64 ( ! F_233 ( & V_4 -> V_46 . V_47 ) ) ;
V_624 = F_3 ( V_626 ) ;
if ( V_624 ) {
F_8 ( L_63 ,
V_624 ) ;
F_2 ( V_626 , V_624 ) ;
}
F_301 ( V_4 ) ;
F_243 ( V_4 , V_583 ) ;
F_2 ( V_581 , 0 ) ;
F_2 ( V_608 , 40 << 16 ) ;
F_2 ( V_609 , 125000 ) ;
F_2 ( V_610 , 25 ) ;
F_273 (ring, dev_priv, i)
F_2 ( F_274 ( V_604 -> V_611 ) , 10 ) ;
F_2 ( V_613 , 0 ) ;
F_2 ( V_617 , 0x186 ) ;
F_2 ( V_696 ,
F_29 ( V_697 |
V_698 |
V_699 ) ) ;
V_685 = F_3 ( V_676 ) ;
if ( ( F_265 ( V_2 ) & V_590 ) &&
( V_685 >> V_680 ) )
V_625 = V_585 ;
F_2 ( V_581 , V_625 ) ;
F_2 ( V_601 , 1000000 ) ;
F_2 ( V_536 , 59400 ) ;
F_2 ( V_538 , 245000 ) ;
F_2 ( V_535 , 66000 ) ;
F_2 ( V_537 , 350000 ) ;
F_2 ( V_602 , 10 ) ;
F_2 ( V_539 ,
V_541 |
V_542 |
V_543 |
V_544 |
V_545 ) ;
V_45 = V_700 |
V_701 |
V_702 ;
F_15 ( V_4 , V_703 , V_45 ) ;
V_45 = F_14 ( V_4 , V_693 ) ;
F_241 ( ( V_45 & V_704 ) == 0 , L_79 ) ;
F_8 ( L_80 , F_313 ( V_45 & V_704 ) ) ;
F_8 ( L_81 , V_45 ) ;
V_4 -> V_46 . V_530 = ( V_45 >> 8 ) & 0xff ;
F_8 ( L_82 ,
F_239 ( V_4 , V_4 -> V_46 . V_530 ) ,
V_4 -> V_46 . V_530 ) ;
F_8 ( L_83 ,
F_239 ( V_4 , V_4 -> V_46 . V_529 ) ,
V_4 -> V_46 . V_529 ) ;
F_240 ( V_4 -> V_2 , V_4 -> V_46 . V_529 ) ;
F_244 ( V_4 , V_583 ) ;
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_603 * V_604 ;
T_1 V_624 , V_45 , V_625 = 0 ;
int V_42 ;
F_64 ( ! F_233 ( & V_4 -> V_46 . V_47 ) ) ;
F_300 ( V_4 ) ;
if ( ( V_624 = F_3 ( V_626 ) ) ) {
F_8 ( L_63 ,
V_624 ) ;
F_2 ( V_626 , V_624 ) ;
}
F_243 ( V_4 , V_583 ) ;
F_2 ( V_581 , 0 ) ;
F_2 ( V_601 , 1000000 ) ;
F_2 ( V_536 , 59400 ) ;
F_2 ( V_538 , 245000 ) ;
F_2 ( V_535 , 66000 ) ;
F_2 ( V_537 , 350000 ) ;
F_2 ( V_602 , 10 ) ;
F_2 ( V_539 ,
V_540 |
V_541 |
V_542 |
V_543 |
V_544 |
V_705 ) ;
F_2 ( V_608 , 0x00280000 ) ;
F_2 ( V_609 , 125000 ) ;
F_2 ( V_610 , 25 ) ;
F_273 (ring, dev_priv, i)
F_2 ( F_274 ( V_604 -> V_611 ) , 10 ) ;
F_2 ( V_617 , 0x557 ) ;
F_2 ( V_696 ,
F_29 ( V_706 |
V_707 |
V_698 |
V_699 ) ) ;
if ( F_265 ( V_2 ) & V_590 )
V_625 = V_585 | V_708 ;
F_261 ( V_2 , V_625 ) ;
F_2 ( V_581 , V_625 ) ;
V_45 = V_700 |
V_701 |
V_709 ;
F_15 ( V_4 , V_703 , V_45 ) ;
V_45 = F_14 ( V_4 , V_693 ) ;
F_241 ( ( V_45 & V_704 ) == 0 , L_79 ) ;
F_8 ( L_80 , F_313 ( V_45 & V_704 ) ) ;
F_8 ( L_81 , V_45 ) ;
V_4 -> V_46 . V_530 = ( V_45 >> 8 ) & 0xff ;
F_8 ( L_82 ,
F_239 ( V_4 , V_4 -> V_46 . V_530 ) ,
V_4 -> V_46 . V_530 ) ;
F_8 ( L_83 ,
F_239 ( V_4 , V_4 -> V_46 . V_529 ) ,
V_4 -> V_46 . V_529 ) ;
F_240 ( V_4 -> V_2 , V_4 -> V_46 . V_529 ) ;
F_244 ( V_4 , V_583 ) ;
}
static unsigned long F_315 ( T_1 V_710 )
{
unsigned long V_711 ;
int div = ( V_710 & 0x3f0000 ) >> 16 ;
int V_712 = ( V_710 & 0x3000 ) >> 12 ;
int V_713 = ( V_710 & 0x7 ) ;
if ( ! V_713 )
return 0 ;
V_711 = ( ( div * 133333 ) / ( ( 1 << V_712 ) * V_713 ) ) ;
return V_711 ;
}
static unsigned long F_316 ( struct V_3 * V_4 )
{
T_9 V_714 , V_647 , V_185 ;
T_1 V_715 , V_716 , V_717 , V_718 = 0 , V_719 = 0 ;
unsigned long V_720 = F_223 ( V_509 ) , V_721 ;
int V_42 ;
F_214 ( & V_467 ) ;
V_721 = V_720 - V_4 -> V_34 . V_508 ;
if ( V_721 <= 10 )
return V_4 -> V_34 . V_722 ;
V_715 = F_3 ( V_505 ) ;
V_716 = F_3 ( V_506 ) ;
V_717 = F_3 ( V_507 ) ;
V_714 = V_715 + V_716 + V_717 ;
if ( V_714 < V_4 -> V_34 . V_504 ) {
V_647 = ~ 0UL - V_4 -> V_34 . V_504 ;
V_647 += V_714 ;
} else {
V_647 = V_714 - V_4 -> V_34 . V_504 ;
}
for ( V_42 = 0 ; V_42 < F_10 ( V_723 ) ; V_42 ++ ) {
if ( V_723 [ V_42 ] . V_42 == V_4 -> V_34 . V_36 &&
V_723 [ V_42 ] . V_724 == V_4 -> V_34 . V_35 ) {
V_718 = V_723 [ V_42 ] . V_718 ;
V_719 = V_723 [ V_42 ] . V_719 ;
break;
}
}
V_647 = F_87 ( V_647 , V_721 ) ;
V_185 = ( ( V_718 * V_647 ) + V_719 ) ;
V_185 = F_87 ( V_185 , 10 ) ;
V_4 -> V_34 . V_504 = V_714 ;
V_4 -> V_34 . V_508 = V_720 ;
V_4 -> V_34 . V_722 = V_185 ;
return V_185 ;
}
unsigned long F_317 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_45 ;
if ( F_70 ( V_2 ) -> V_270 != 5 )
return 0 ;
F_219 ( & V_467 ) ;
V_45 = F_316 ( V_4 ) ;
F_225 ( & V_467 ) ;
return V_45 ;
}
unsigned long F_318 ( struct V_3 * V_4 )
{
unsigned long V_718 , V_725 , V_726 ;
T_1 V_727 ;
V_727 = F_3 ( V_728 ) ;
V_718 = ( ( V_727 & V_729 ) >> V_730 ) ;
V_725 = F_319 ( V_731 ) ;
V_726 = V_727 & V_732 ;
return ( ( V_718 * V_725 ) / 127 ) - V_726 ;
}
static int F_320 ( T_8 V_733 )
{
if ( V_733 == 0 )
return 0 ;
if ( V_733 >= 8 && V_733 < 31 )
V_733 = 31 ;
return ( V_733 + 2 ) * 125 ;
}
static T_1 F_321 ( struct V_3 * V_4 , T_8 V_733 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
const int V_734 = F_320 ( V_733 ) ;
const int V_735 = V_734 - 1125 ;
if ( F_70 ( V_2 ) -> V_736 )
return V_735 > 0 ? V_735 : 0 ;
return V_734 ;
}
static void F_322 ( struct V_3 * V_4 )
{
T_9 V_720 , V_647 , V_737 ;
T_1 V_738 ;
F_214 ( & V_467 ) ;
V_720 = F_224 () ;
V_737 = V_720 - V_4 -> V_34 . V_512 ;
F_323 ( V_737 , V_739 ) ;
if ( ! V_737 )
return;
V_738 = F_3 ( V_511 ) ;
if ( V_738 < V_4 -> V_34 . V_510 ) {
V_647 = ~ 0UL - V_4 -> V_34 . V_510 ;
V_647 += V_738 ;
} else {
V_647 = V_738 - V_4 -> V_34 . V_510 ;
}
V_4 -> V_34 . V_510 = V_738 ;
V_4 -> V_34 . V_512 = V_720 ;
V_647 = V_647 * 1181 ;
V_647 = F_87 ( V_647 , V_737 * 10 ) ;
V_4 -> V_34 . V_740 = V_647 ;
}
void F_324 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_70 ( V_2 ) -> V_270 != 5 )
return;
F_219 ( & V_467 ) ;
F_322 ( V_4 ) ;
F_225 ( & V_467 ) ;
}
static unsigned long F_325 ( struct V_3 * V_4 )
{
unsigned long V_724 , V_741 , V_742 , V_743 , V_744 ;
T_1 V_733 , V_745 ;
F_214 ( & V_467 ) ;
V_733 = F_3 ( F_220 ( V_4 -> V_46 . V_530 ) ) ;
V_733 = ( V_733 >> 24 ) & 0x7f ;
V_745 = F_321 ( V_4 , V_733 ) ;
V_742 = V_745 ;
V_724 = F_318 ( V_4 ) ;
if ( V_724 > 80 )
V_741 = ( ( V_724 * 2349 ) + 135940 ) ;
else if ( V_724 >= 50 )
V_741 = ( ( V_724 * 964 ) + 29317 ) ;
else
V_741 = ( ( V_724 * 301 ) + 1004 ) ;
V_741 = V_741 * ( ( 150142 * V_742 ) / 10000 - 78642 ) ;
V_741 /= 100000 ;
V_743 = ( V_741 * V_4 -> V_34 . V_741 ) ;
V_744 = ( V_743 * V_742 ) / 10000 ;
V_744 /= 100 ;
F_322 ( V_4 ) ;
return V_4 -> V_34 . V_740 + V_744 ;
}
unsigned long F_326 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_45 ;
if ( F_70 ( V_2 ) -> V_270 != 5 )
return 0 ;
F_219 ( & V_467 ) ;
V_45 = F_325 ( V_4 ) ;
F_225 ( & V_467 ) ;
return V_45 ;
}
unsigned long F_327 ( void )
{
struct V_3 * V_4 ;
unsigned long V_746 , V_747 , V_185 = 0 ;
F_219 ( & V_467 ) ;
if ( ! V_748 )
goto V_749;
V_4 = V_748 ;
V_746 = F_316 ( V_4 ) ;
V_747 = F_325 ( V_4 ) ;
V_185 = V_746 + V_747 ;
V_749:
F_225 ( & V_467 ) ;
return V_185 ;
}
bool F_328 ( void )
{
struct V_3 * V_4 ;
bool V_185 = true ;
F_219 ( & V_467 ) ;
if ( ! V_748 ) {
V_185 = false ;
goto V_749;
}
V_4 = V_748 ;
if ( V_4 -> V_34 . V_496 > V_4 -> V_34 . V_476 )
V_4 -> V_34 . V_496 -- ;
V_749:
F_225 ( & V_467 ) ;
return V_185 ;
}
bool F_329 ( void )
{
struct V_3 * V_4 ;
bool V_185 = true ;
F_219 ( & V_467 ) ;
if ( ! V_748 ) {
V_185 = false ;
goto V_749;
}
V_4 = V_748 ;
if ( V_4 -> V_34 . V_496 < V_4 -> V_34 . V_497 )
V_4 -> V_34 . V_496 ++ ;
V_749:
F_225 ( & V_467 ) ;
return V_185 ;
}
bool F_330 ( void )
{
struct V_3 * V_4 ;
struct V_603 * V_604 ;
bool V_185 = false ;
int V_42 ;
F_219 ( & V_467 ) ;
if ( ! V_748 )
goto V_749;
V_4 = V_748 ;
F_273 (ring, dev_priv, i)
V_185 |= ! F_249 ( & V_604 -> V_750 ) ;
V_749:
F_225 ( & V_467 ) ;
return V_185 ;
}
bool F_331 ( void )
{
struct V_3 * V_4 ;
bool V_185 = true ;
F_219 ( & V_467 ) ;
if ( ! V_748 ) {
V_185 = false ;
goto V_749;
}
V_4 = V_748 ;
V_4 -> V_34 . V_496 = V_4 -> V_34 . V_478 ;
if ( ! F_213 ( V_4 -> V_2 , V_4 -> V_34 . V_478 ) )
V_185 = false ;
V_749:
F_225 ( & V_467 ) ;
return V_185 ;
}
static void
F_332 ( void )
{
void (* V_574)( void );
V_574 = F_333 ( V_751 ) ;
if ( V_574 ) {
V_574 () ;
F_334 ( V_751 ) ;
}
}
void F_335 ( struct V_3 * V_4 )
{
F_219 ( & V_467 ) ;
V_748 = V_4 ;
F_225 ( & V_467 ) ;
F_332 () ;
}
void F_336 ( void )
{
F_219 ( & V_467 ) ;
V_748 = NULL ;
F_225 ( & V_467 ) ;
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_752 ;
T_8 V_753 [ 16 ] ;
int V_42 ;
F_2 ( V_754 , 0 ) ;
F_23 ( V_754 ) ;
F_2 ( V_755 , 0x15040d00 ) ;
F_2 ( V_756 , 0x007f0000 ) ;
F_2 ( V_757 , 0x1e220004 ) ;
F_2 ( V_758 , 0x04000004 ) ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ )
F_2 ( F_338 ( V_42 ) , 0 ) ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ )
F_2 ( F_339 ( V_42 ) , 0 ) ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ ) {
T_1 V_759 = F_3 ( F_220 ( V_42 ) ) ;
unsigned long V_711 = F_315 ( V_759 ) ;
unsigned long V_760 = ( V_759 & V_494 ) >>
V_495 ;
unsigned long V_45 ;
V_45 = V_760 * V_760 ;
V_45 *= ( V_711 / 1000 ) ;
V_45 *= 255 ;
V_45 /= ( 127 * 127 * 900 ) ;
if ( V_45 > 0xff )
F_17 ( L_84 , V_45 ) ;
V_753 [ V_42 ] = V_45 ;
}
V_753 [ 14 ] = 0 ;
V_753 [ 15 ] = 0 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
T_1 V_45 = ( V_753 [ V_42 * 4 ] << 24 ) | ( V_753 [ ( V_42 * 4 ) + 1 ] << 16 ) |
( V_753 [ ( V_42 * 4 ) + 2 ] << 8 ) | ( V_753 [ ( V_42 * 4 ) + 3 ] ) ;
F_2 ( F_340 ( V_42 ) , V_45 ) ;
}
F_2 ( V_761 , 0 ) ;
F_2 ( V_762 , 0 ) ;
F_2 ( V_763 , 0x00007f00 ) ;
F_2 ( V_764 , 0x0000000e ) ;
F_2 ( V_765 , 0x000e0000 ) ;
F_2 ( V_766 , 0x68000300 ) ;
F_2 ( V_767 , 0x42000000 ) ;
F_2 ( V_768 , 0x00140031 ) ;
F_2 ( V_769 , 0 ) ;
F_2 ( V_770 , 0 ) ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ )
F_2 ( F_341 ( V_42 ) , 0 ) ;
F_2 ( V_754 , 0x80000019 ) ;
V_752 = F_3 ( V_771 ) ;
V_4 -> V_34 . V_741 = ( V_752 & V_772 ) ;
}
void F_342 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_593 . V_589 = F_264 ( V_2 , V_593 . V_589 ) ;
if ( ! V_593 . V_589 ) {
F_276 ( L_85 ) ;
F_343 ( V_4 ) ;
}
if ( F_22 ( V_2 ) )
F_309 ( V_2 ) ;
else if ( F_21 ( V_2 ) )
F_308 ( V_2 ) ;
}
void F_344 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_22 ( V_2 ) )
return;
else if ( F_21 ( V_2 ) )
F_311 ( V_2 ) ;
if ( ! V_593 . V_589 )
F_345 ( V_4 ) ;
}
static void F_346 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_347 ( & V_4 -> V_46 . V_773 ) ;
F_348 ( V_2 ) ;
}
void F_349 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_70 ( V_2 ) -> V_270 < 6 )
return;
F_346 ( V_2 ) ;
F_247 ( V_4 ) ;
}
void F_350 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_351 ( V_2 ) ) {
F_226 ( V_2 ) ;
} else if ( F_70 ( V_2 ) -> V_270 >= 6 ) {
F_349 ( V_2 ) ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
if ( F_70 ( V_2 ) -> V_270 >= 9 )
F_257 ( V_2 ) ;
else if ( F_22 ( V_2 ) )
F_259 ( V_2 ) ;
else if ( F_21 ( V_2 ) )
F_260 ( V_2 ) ;
else
F_258 ( V_2 ) ;
V_4 -> V_46 . V_94 = false ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
}
static void F_352 ( struct V_774 * V_579 )
{
struct V_3 * V_4 =
F_353 ( V_579 , struct V_3 ,
V_46 . V_773 . V_579 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
F_354 ( V_2 ) ;
if ( F_22 ( V_2 ) ) {
F_312 ( V_2 ) ;
} else if ( F_21 ( V_2 ) ) {
F_314 ( V_2 ) ;
} else if ( F_70 ( V_2 ) -> V_270 >= 9 ) {
F_272 ( V_2 ) ;
F_271 ( V_2 ) ;
if ( F_267 ( V_2 ) || F_268 ( V_2 ) )
F_286 ( V_2 ) ;
} else if ( F_117 ( V_2 ) ) {
F_281 ( V_2 ) ;
F_286 ( V_2 ) ;
} else {
F_282 ( V_2 ) ;
F_286 ( V_2 ) ;
}
F_64 ( V_4 -> V_46 . V_557 < V_4 -> V_46 . V_558 ) ;
F_64 ( V_4 -> V_46 . V_564 > V_4 -> V_46 . V_557 ) ;
F_64 ( V_4 -> V_46 . V_529 < V_4 -> V_46 . V_558 ) ;
F_64 ( V_4 -> V_46 . V_529 > V_4 -> V_46 . V_557 ) ;
V_4 -> V_46 . V_94 = true ;
F_355 ( V_2 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
F_345 ( V_4 ) ;
}
void F_356 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_357 ( V_2 ) )
return;
if ( F_351 ( V_2 ) ) {
F_13 ( & V_2 -> V_687 ) ;
F_218 ( V_2 ) ;
F_337 ( V_2 ) ;
F_18 ( & V_2 -> V_687 ) ;
} else if ( F_70 ( V_2 ) -> V_270 >= 6 ) {
if ( F_358 ( & V_4 -> V_46 . V_773 ,
F_359 ( V_775 ) ) )
F_360 ( V_4 ) ;
}
}
void F_361 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_70 ( V_2 ) -> V_270 < 6 )
return;
F_346 ( V_2 ) ;
V_4 -> V_46 . V_94 = false ;
}
static void F_362 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_776 , V_777 ) ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_65 V_65 ;
F_145 (dev_priv, pipe) {
F_2 ( F_364 ( V_65 ) ,
F_3 ( F_364 ( V_65 ) ) |
V_778 ) ;
F_2 ( F_365 ( V_65 ) , F_3 ( F_365 ( V_65 ) ) ) ;
F_23 ( F_365 ( V_65 ) ) ;
}
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_361 , F_3 ( V_361 ) & ~ V_340 ) ;
F_2 ( V_362 , F_3 ( V_362 ) & ~ V_340 ) ;
F_2 ( V_363 , F_3 ( V_363 ) & ~ V_340 ) ;
}
static void F_367 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_779 = V_780 ;
V_779 |= V_781 |
V_782 |
V_783 ;
F_2 ( V_784 ,
V_785 |
V_786 ) ;
F_2 ( V_787 ,
V_788 ) ;
F_2 ( V_789 ,
( F_3 ( V_789 ) |
V_790 | V_791 ) ) ;
V_779 |= V_792 ;
F_2 ( V_371 ,
( F_3 ( V_371 ) |
V_372 ) ) ;
F_366 ( V_2 ) ;
if ( F_351 ( V_2 ) ) {
F_2 ( V_793 ,
F_3 ( V_793 ) |
V_794 ) ;
F_2 ( V_789 ,
F_3 ( V_789 ) |
V_790 ) ;
}
F_2 ( V_795 , V_779 ) ;
F_2 ( V_789 ,
F_3 ( V_789 ) |
V_796 ) ;
F_2 ( V_797 ,
V_798 << 16 |
V_798 ) ;
F_2 ( V_799 ,
F_29 ( V_800 ) ) ;
F_2 ( V_799 , F_30 ( V_801 ) ) ;
F_363 ( V_2 ) ;
F_362 ( V_2 ) ;
}
static void F_368 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_65 ;
T_3 V_45 ;
F_2 ( V_776 , V_777 |
V_802 |
V_803 ) ;
F_2 ( V_804 , F_3 ( V_804 ) |
V_805 ) ;
F_145 (dev_priv, pipe) {
V_45 = F_3 ( F_369 ( V_65 ) ) ;
V_45 |= V_806 ;
V_45 &= ~ V_807 ;
if ( V_4 -> V_808 . V_809 )
V_45 |= V_807 ;
V_45 &= ~ V_810 ;
V_45 &= ~ V_811 ;
V_45 &= ~ V_812 ;
F_2 ( F_369 ( V_65 ) , V_45 ) ;
}
F_145 (dev_priv, pipe) {
F_2 ( F_370 ( V_65 ) ,
V_813 ) ;
}
}
static void F_371 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_14 ;
V_14 = F_3 ( V_302 ) ;
if ( ( V_14 & V_814 ) != V_815 )
F_11 ( L_86 ,
V_14 ) ;
}
static void F_372 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_779 = V_780 ;
F_2 ( V_795 , V_779 ) ;
F_2 ( V_789 ,
F_3 ( V_789 ) |
V_796 ) ;
F_2 ( V_816 ,
F_29 ( V_817 ) ) ;
F_2 ( V_799 , F_30 ( V_801 ) ) ;
F_2 ( V_818 ,
F_373 ( V_819 , V_820 ) ) ;
F_366 ( V_2 ) ;
F_2 ( V_799 ,
F_30 ( V_821 ) ) ;
F_2 ( V_822 ,
F_3 ( V_822 ) |
V_823 |
V_824 ) ;
F_2 ( V_825 ,
V_826 |
V_827 ) ;
F_2 ( V_828 ,
F_29 ( V_829 ) ) ;
F_2 ( V_828 ,
F_29 ( V_830 ) ) ;
F_2 ( V_793 ,
F_3 ( V_793 ) |
V_794 | V_831 ) ;
F_2 ( V_789 ,
F_3 ( V_789 ) |
V_790 | V_791 ) ;
F_2 ( V_795 ,
F_3 ( V_795 ) |
V_792 |
V_783 ) ;
F_363 ( V_2 ) ;
F_368 ( V_2 ) ;
F_371 ( V_2 ) ;
}
static void F_374 ( struct V_3 * V_4 )
{
T_3 V_96 = F_3 ( V_832 ) ;
V_96 &= ~ V_833 ;
V_96 |= V_834 ;
V_96 |= V_835 ;
V_96 |= V_836 ;
F_2 ( V_832 , V_96 ) ;
}
static void F_375 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_376 ( V_2 ) )
F_2 ( V_776 ,
F_3 ( V_776 ) |
V_837 ) ;
F_2 ( F_370 ( V_73 ) ,
F_3 ( F_370 ( V_73 ) ) |
V_813 ) ;
}
static void F_377 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_376 ( V_2 ) ) {
T_3 V_45 = F_3 ( V_776 ) ;
V_45 &= ~ V_837 ;
F_2 ( V_776 , V_45 ) ;
}
}
static void F_378 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_65 V_65 ;
T_3 V_838 ;
F_366 ( V_2 ) ;
F_2 ( V_839 , F_3 ( V_839 ) | V_840 ) ;
F_2 ( V_841 ,
F_3 ( V_841 ) | V_842 ) ;
F_145 (dev_priv, pipe) {
F_2 ( F_379 ( V_65 ) ,
F_3 ( F_379 ( V_65 ) ) |
V_843 ) ;
}
F_2 ( V_832 ,
F_3 ( V_832 ) &
~ ( V_844 | V_845 ) ) ;
F_2 ( V_846 ,
F_29 ( V_847 ) ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
V_838 = F_3 ( V_848 ) ;
F_2 ( V_848 , V_838 & ~ V_849 ) ;
F_2 ( V_850 , V_851 ) ;
F_2 ( V_848 , V_838 ) ;
F_2 ( V_852 , V_853 ) ;
F_375 ( V_2 ) ;
}
static void F_380 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_366 ( V_2 ) ;
F_2 ( V_854 , V_855 ) ;
F_2 ( V_856 ,
F_29 ( V_857 ) ) ;
F_2 ( V_858 ,
F_3 ( V_858 ) |
V_859 ) ;
F_2 ( V_832 ,
F_3 ( V_832 ) & ~ V_845 ) ;
F_2 ( V_860 , F_30 ( V_801 ) ) ;
F_2 ( V_860 ,
F_30 ( V_861 ) ) ;
F_2 ( V_862 ,
F_29 ( V_863 ) ) ;
F_2 ( V_864 ,
F_373 ( V_819 , V_820 ) ) ;
F_2 ( V_865 ,
F_29 ( V_866 ) ) ;
F_2 ( V_839 , F_3 ( V_839 ) | V_840 ) ;
F_2 ( V_841 ,
F_3 ( V_841 ) | V_867 ) ;
F_375 ( V_2 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_868 ;
F_366 ( V_2 ) ;
F_2 ( V_795 , V_780 ) ;
F_2 ( V_828 ,
F_29 ( V_869 ) ) ;
F_2 ( V_870 ,
V_871 |
V_872 ) ;
if ( F_382 ( V_2 ) )
F_2 ( V_873 ,
F_29 ( V_874 ) ) ;
F_2 ( V_860 , F_30 ( V_801 ) ) ;
F_2 ( V_875 ,
V_876 ) ;
F_2 ( V_877 ,
V_878 ) ;
F_2 ( V_879 ,
V_880 ) ;
if ( F_382 ( V_2 ) )
F_2 ( V_881 ,
F_29 ( V_882 ) ) ;
else {
F_2 ( V_881 ,
F_29 ( V_882 ) ) ;
F_2 ( V_883 ,
F_29 ( V_882 ) ) ;
}
F_2 ( V_884 , F_3 ( V_884 ) &
~ V_885 ) ;
F_2 ( V_825 ,
V_886 ) ;
F_2 ( V_858 ,
F_3 ( V_858 ) |
V_859 ) ;
F_363 ( V_2 ) ;
F_374 ( V_4 ) ;
if ( 0 ) {
F_2 ( V_860 ,
F_30 ( V_861 ) ) ;
}
F_2 ( V_862 ,
F_29 ( V_863 ) ) ;
F_2 ( V_864 ,
F_373 ( V_819 , V_820 ) ) ;
V_868 = F_3 ( V_887 ) ;
V_868 &= ~ V_888 ;
V_868 |= V_889 ;
F_2 ( V_887 , V_868 ) ;
if ( ! F_383 ( V_2 ) )
F_368 ( V_2 ) ;
F_371 ( V_2 ) ;
}
static void F_384 ( struct V_3 * V_4 )
{
F_2 ( V_890 , V_891 ) ;
F_2 ( V_892 , V_893 ) ;
F_2 ( V_894 , 0 ) ;
}
static void F_385 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_384 ( V_4 ) ;
F_2 ( V_828 ,
F_29 ( V_869 ) ) ;
F_2 ( V_870 ,
V_871 |
V_872 ) ;
F_2 ( V_873 ,
F_29 ( V_895 |
V_874 ) ) ;
F_2 ( V_860 , F_30 ( V_801 ) ) ;
F_2 ( V_884 , F_3 ( V_884 ) &
~ V_885 ) ;
F_2 ( V_881 ,
F_29 ( V_882 ) ) ;
F_2 ( V_858 ,
F_3 ( V_858 ) |
V_859 ) ;
F_374 ( V_4 ) ;
F_2 ( V_825 ,
V_886 ) ;
F_2 ( V_896 ,
F_3 ( V_896 ) | V_897 ) ;
F_2 ( V_862 ,
F_29 ( V_863 ) ) ;
F_2 ( V_864 ,
F_373 ( V_819 , V_820 ) ) ;
F_2 ( V_898 , V_899 ) ;
F_2 ( V_900 , V_901 ) ;
}
static void F_386 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_384 ( V_4 ) ;
F_2 ( V_832 ,
F_3 ( V_832 ) &
~ ( V_844 | V_845 ) ) ;
F_2 ( V_846 ,
F_29 ( V_847 ) ) ;
F_2 ( V_822 , F_3 ( V_822 ) |
V_824 ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
F_2 ( V_852 , V_853 ) ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_779 ;
F_2 ( V_902 , 0 ) ;
F_2 ( V_903 , V_904 |
V_905 |
V_906 ) ;
F_2 ( V_907 , 0 ) ;
V_779 = V_891 |
V_908 |
V_909 ;
if ( F_388 ( V_2 ) )
V_779 |= V_910 ;
F_2 ( V_890 , V_779 ) ;
F_2 ( V_799 ,
F_29 ( V_800 ) ) ;
F_2 ( V_799 , F_30 ( V_801 ) ) ;
F_363 ( V_2 ) ;
}
static void F_389 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_902 , V_911 ) ;
F_2 ( V_903 , 0 ) ;
F_2 ( V_890 , 0 ) ;
F_2 ( V_907 , 0 ) ;
F_216 ( V_912 , 0 ) ;
F_2 ( V_913 ,
F_29 ( V_893 ) ) ;
F_2 ( V_799 , F_30 ( V_801 ) ) ;
}
static void F_390 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_902 , V_914 |
V_911 |
V_915 |
V_916 |
V_917 ) ;
F_2 ( V_903 , 0 ) ;
F_2 ( V_913 ,
F_29 ( V_893 ) ) ;
F_2 ( V_799 , F_30 ( V_801 ) ) ;
}
static void F_391 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_918 = F_3 ( V_919 ) ;
V_918 |= V_920 | V_921 |
V_922 ;
F_2 ( V_919 , V_918 ) ;
if ( F_26 ( V_2 ) )
F_2 ( V_923 , F_29 ( V_924 ) ) ;
F_2 ( V_923 , F_30 ( V_925 ) ) ;
F_2 ( V_64 , F_29 ( V_926 ) ) ;
F_2 ( V_913 , F_29 ( V_927 ) ) ;
F_2 ( V_913 ,
F_29 ( V_893 ) ) ;
}
static void F_392 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_902 , V_928 ) ;
F_2 ( V_929 , F_29 ( V_930 ) |
F_30 ( V_931 ) ) ;
F_2 ( V_932 ,
F_29 ( V_933 ) ) ;
}
static void F_393 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_890 , V_908 ) ;
F_2 ( V_932 ,
F_29 ( V_934 ) |
F_29 ( V_935 ) ) ;
}
void F_394 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_123 . V_936 )
V_4 -> V_123 . V_936 ( V_2 ) ;
}
void F_395 ( struct V_1 * V_2 )
{
if ( F_396 ( V_2 ) )
F_377 ( V_2 ) ;
}
void F_397 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_398 ( V_4 ) ;
if ( F_26 ( V_2 ) )
F_5 ( V_2 ) ;
else if ( F_138 ( V_2 ) )
F_6 ( V_2 ) ;
if ( F_70 ( V_2 ) -> V_270 >= 9 ) {
F_128 ( V_2 ) ;
if ( F_156 ( V_2 ) )
V_4 -> V_123 . V_936 =
F_1 ;
V_4 -> V_123 . V_465 = F_198 ;
} else if ( F_399 ( V_2 ) ) {
F_126 ( V_2 ) ;
if ( ( F_138 ( V_2 ) && V_4 -> V_56 . V_186 [ 1 ] &&
V_4 -> V_56 . V_290 [ 1 ] && V_4 -> V_56 . V_291 [ 1 ] ) ||
( ! F_138 ( V_2 ) && V_4 -> V_56 . V_186 [ 0 ] &&
V_4 -> V_56 . V_290 [ 0 ] && V_4 -> V_56 . V_291 [ 0 ] ) ) {
V_4 -> V_123 . V_465 = F_200 ;
V_4 -> V_123 . V_937 = F_129 ;
} else {
F_11 ( L_87
L_88 ) ;
}
if ( F_138 ( V_2 ) )
V_4 -> V_123 . V_936 = F_367 ;
else if ( F_127 ( V_2 ) )
V_4 -> V_123 . V_936 = F_372 ;
else if ( F_121 ( V_2 ) )
V_4 -> V_123 . V_936 = F_381 ;
else if ( F_116 ( V_2 ) )
V_4 -> V_123 . V_936 = F_380 ;
else if ( F_70 ( V_2 ) -> V_270 == 8 )
V_4 -> V_123 . V_936 = F_378 ;
} else if ( F_22 ( V_2 ) ) {
F_61 ( V_2 ) ;
V_4 -> V_123 . V_465 = F_76 ;
V_4 -> V_123 . V_936 =
F_386 ;
} else if ( F_21 ( V_2 ) ) {
F_61 ( V_2 ) ;
V_4 -> V_123 . V_465 = F_76 ;
V_4 -> V_123 . V_936 =
F_385 ;
} else if ( F_26 ( V_2 ) ) {
if ( ! F_9 ( F_46 ( V_2 ) ,
V_4 -> V_28 ,
V_4 -> V_18 ,
V_4 -> V_24 ) ) {
F_276 ( L_89
L_90
L_91 ,
( V_4 -> V_28 == 1 ) ? L_92 : L_93 ,
V_4 -> V_18 , V_4 -> V_24 ) ;
F_20 ( V_4 , false ) ;
V_4 -> V_123 . V_465 = NULL ;
} else
V_4 -> V_123 . V_465 = F_45 ;
V_4 -> V_123 . V_936 = F_391 ;
} else if ( F_24 ( V_2 ) ) {
V_4 -> V_123 . V_465 = F_77 ;
V_4 -> V_123 . V_936 = F_387 ;
} else if ( F_400 ( V_2 ) ) {
V_4 -> V_123 . V_465 = F_80 ;
if ( F_25 ( V_2 ) )
V_4 -> V_123 . V_936 = F_389 ;
else if ( F_401 ( V_2 ) )
V_4 -> V_123 . V_936 = F_390 ;
} else if ( F_402 ( V_2 ) ) {
V_4 -> V_123 . V_465 = F_81 ;
V_4 -> V_123 . V_240 = F_37 ;
V_4 -> V_123 . V_936 = F_391 ;
} else if ( F_82 ( V_2 ) ) {
if ( F_70 ( V_2 ) -> V_209 == 1 ) {
V_4 -> V_123 . V_465 = F_85 ;
V_4 -> V_123 . V_240 = F_39 ;
} else {
V_4 -> V_123 . V_465 = F_81 ;
V_4 -> V_123 . V_240 = F_38 ;
}
if ( F_403 ( V_2 ) || F_404 ( V_2 ) )
V_4 -> V_123 . V_936 = F_392 ;
else
V_4 -> V_123 . V_936 = F_393 ;
} else {
F_17 ( L_94 ) ;
}
}
int F_115 ( struct V_3 * V_4 , T_1 V_938 , T_1 * V_45 )
{
F_64 ( ! F_233 ( & V_4 -> V_46 . V_47 ) ) ;
if ( F_3 ( V_939 ) & V_940 ) {
F_8 ( L_95 ) ;
return - V_941 ;
}
F_2 ( V_942 , * V_45 ) ;
F_2 ( V_943 , 0 ) ;
F_2 ( V_939 , V_940 | V_938 ) ;
if ( F_16 ( ( F_3 ( V_939 ) & V_940 ) == 0 ,
500 ) ) {
F_17 ( L_96 , V_938 ) ;
return - V_944 ;
}
* V_45 = F_3 ( V_942 ) ;
F_2 ( V_942 , 0 ) ;
return 0 ;
}
int F_283 ( struct V_3 * V_4 , T_1 V_938 , T_1 V_45 )
{
F_64 ( ! F_233 ( & V_4 -> V_46 . V_47 ) ) ;
if ( F_3 ( V_939 ) & V_940 ) {
F_8 ( L_97 ) ;
return - V_941 ;
}
F_2 ( V_942 , V_45 ) ;
F_2 ( V_939 , V_940 | V_938 ) ;
if ( F_16 ( ( F_3 ( V_939 ) & V_940 ) == 0 ,
500 ) ) {
F_17 ( L_98 , V_938 ) ;
return - V_944 ;
}
F_2 ( V_942 , 0 ) ;
return 0 ;
}
static int F_405 ( unsigned int V_945 )
{
switch ( V_945 ) {
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
static int F_406 ( struct V_3 * V_4 , int V_45 )
{
int div , V_945 = F_109 ( V_4 -> V_945 , 1000 ) ;
div = F_405 ( V_945 ) ;
if ( div < 0 )
return div ;
return F_109 ( V_945 * ( V_45 + 6 - 0xbd ) , div ) ;
}
static int F_407 ( struct V_3 * V_4 , int V_45 )
{
int V_946 , V_945 = F_109 ( V_4 -> V_945 , 1000 ) ;
V_946 = F_405 ( V_945 ) ;
if ( V_946 < 0 )
return V_946 ;
return F_109 ( V_946 * V_45 , V_945 ) + 0xbd - 6 ;
}
static int F_408 ( struct V_3 * V_4 , int V_45 )
{
int div , V_945 = F_109 ( V_4 -> V_945 , 1000 ) ;
div = F_405 ( V_945 ) / 2 ;
if ( div < 0 )
return div ;
return F_109 ( V_945 * V_45 , 2 * div ) / 2 ;
}
static int F_409 ( struct V_3 * V_4 , int V_45 )
{
int V_946 , V_945 = F_109 ( V_4 -> V_945 , 1000 ) ;
V_946 = F_405 ( V_945 ) / 2 ;
if ( V_946 < 0 )
return V_946 ;
return F_109 ( V_45 * 2 * V_946 , V_945 ) * 2 ;
}
int F_239 ( struct V_3 * V_4 , int V_45 )
{
if ( F_113 ( V_4 -> V_2 ) )
return F_109 ( V_45 * V_947 ,
V_599 ) ;
else if ( F_22 ( V_4 -> V_2 ) )
return F_408 ( V_4 , V_45 ) ;
else if ( F_21 ( V_4 -> V_2 ) )
return F_406 ( V_4 , V_45 ) ;
else
return V_45 * V_947 ;
}
int F_270 ( struct V_3 * V_4 , int V_45 )
{
if ( F_113 ( V_4 -> V_2 ) )
return F_109 ( V_45 * V_599 ,
V_947 ) ;
else if ( F_22 ( V_4 -> V_2 ) )
return F_409 ( V_4 , V_45 ) ;
else if ( F_21 ( V_4 -> V_2 ) )
return F_407 ( V_4 , V_45 ) ;
else
return F_109 ( V_45 , V_947 ) ;
}
static void F_410 ( struct V_774 * V_579 )
{
struct V_948 * V_949 = F_353 ( V_579 , struct V_948 , V_579 ) ;
struct V_950 * V_951 = V_949 -> V_951 ;
if ( ! F_411 ( V_951 , true ) )
F_252 ( F_56 ( V_951 -> V_604 -> V_2 ) , NULL ,
V_951 -> V_952 ) ;
F_412 ( V_951 ) ;
F_413 ( V_949 ) ;
}
void F_414 ( struct V_1 * V_2 ,
struct V_950 * V_951 )
{
struct V_948 * V_949 ;
if ( V_951 == NULL || F_70 ( V_2 ) -> V_270 < 6 )
return;
if ( F_411 ( V_951 , true ) )
return;
V_949 = F_415 ( sizeof( * V_949 ) , V_953 ) ;
if ( V_949 == NULL )
return;
F_416 ( V_951 ) ;
V_949 -> V_951 = V_951 ;
F_417 ( & V_949 -> V_579 , F_410 ) ;
F_254 ( F_56 ( V_2 ) -> V_578 , & V_949 -> V_579 ) ;
}
void F_418 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_419 ( & V_4 -> V_46 . V_47 ) ;
F_420 ( & V_4 -> V_46 . V_566 ) ;
F_421 ( & V_4 -> V_46 . V_773 ,
F_352 ) ;
F_422 ( & V_4 -> V_46 . V_567 ) ;
F_422 ( & V_4 -> V_46 . V_954 . V_574 ) ;
F_422 ( & V_4 -> V_46 . V_955 . V_574 ) ;
V_4 -> V_956 . V_957 = false ;
F_423 ( & V_4 -> V_956 . V_958 , 0 ) ;
F_423 ( & V_4 -> V_956 . V_959 , 0 ) ;
}
