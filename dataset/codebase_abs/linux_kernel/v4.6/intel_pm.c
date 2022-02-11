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
int V_83 , int V_84 ,
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
int V_84 = F_48 ( V_93 -> V_101 -> V_102 -> V_103 -> V_104 , 0 ) ;
int clock = V_98 -> V_105 ;
V_56 = F_40 ( clock , & V_106 ,
V_106 . V_83 ,
V_84 , V_41 -> V_107 ) ;
V_96 = F_3 ( V_108 ) ;
V_96 &= ~ V_109 ;
V_96 |= F_49 ( V_56 , V_110 ) ;
F_2 ( V_108 , V_96 ) ;
F_11 ( L_16 , V_96 ) ;
V_56 = F_40 ( clock , & V_111 ,
V_106 . V_83 ,
V_84 , V_41 -> V_112 ) ;
V_96 = F_3 ( V_61 ) ;
V_96 &= ~ V_113 ;
V_96 |= F_49 ( V_56 , V_114 ) ;
F_2 ( V_61 , V_96 ) ;
V_56 = F_40 ( clock , & V_115 ,
V_115 . V_83 ,
V_84 , V_41 -> V_116 ) ;
V_96 = F_3 ( V_61 ) ;
V_96 &= ~ V_117 ;
V_96 |= F_49 ( V_56 , V_118 ) ;
F_2 ( V_61 , V_96 ) ;
V_56 = F_40 ( clock , & V_119 ,
V_115 . V_83 ,
V_84 , V_41 -> V_120 ) ;
V_96 = F_3 ( V_61 ) ;
V_96 &= ~ V_121 ;
V_96 |= F_49 ( V_56 , V_122 ) ;
F_2 ( V_61 , V_96 ) ;
F_11 ( L_17 , V_96 ) ;
F_20 ( V_4 , true ) ;
} else {
F_20 ( V_4 , false ) ;
}
}
static bool F_50 ( struct V_1 * V_2 ,
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
V_93 = F_51 ( V_2 , V_66 ) ;
if ( ! F_44 ( V_93 ) ) {
* V_128 = V_125 -> V_89 ;
* V_127 = V_123 -> V_89 ;
return false ;
}
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
clock = V_98 -> V_105 ;
V_129 = V_98 -> V_135 ;
V_130 = F_47 ( V_93 ) -> V_99 -> V_136 ;
V_84 = F_48 ( V_93 -> V_101 -> V_102 -> V_103 -> V_104 , 0 ) ;
V_133 = ( ( clock * V_84 / 1000 ) * V_124 ) / 1000 ;
V_134 = V_123 -> V_83 * V_123 -> V_88 - V_130 * 8 ;
if ( V_134 > 0 )
V_133 += V_134 ;
V_133 = F_41 ( V_133 , V_123 -> V_88 ) ;
* V_127 = V_133 + V_123 -> V_89 ;
if ( * V_127 > ( int ) V_123 -> V_90 )
* V_127 = V_123 -> V_90 ;
V_131 = F_52 ( V_129 * 1000 / clock , 1 ) ;
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
static bool F_53 ( struct V_1 * V_2 ,
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
static bool F_54 ( struct V_1 * V_2 ,
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
V_93 = F_51 ( V_2 , V_66 ) ;
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
clock = V_98 -> V_105 ;
V_129 = V_98 -> V_135 ;
V_130 = F_47 ( V_93 ) -> V_99 -> V_136 ;
V_84 = F_48 ( V_93 -> V_101 -> V_102 -> V_103 -> V_104 , 0 ) ;
V_131 = F_52 ( V_129 * 1000 / clock , 1 ) ;
V_132 = ( V_85 / V_131 + 1000 ) / 1000 ;
V_139 = V_130 * V_84 ;
V_140 = ( ( clock * V_84 / 1000 ) * V_85 ) / 1000 ;
V_141 = V_132 * V_139 ;
V_133 = F_41 ( F_55 ( V_140 , V_141 ) , V_123 -> V_88 ) ;
* V_138 = V_133 + V_123 -> V_89 ;
V_133 = V_132 * V_84 * V_93 -> V_125 -> V_102 -> V_137 ;
V_133 = F_41 ( V_133 , V_125 -> V_88 ) ;
* V_128 = V_133 + V_125 -> V_89 ;
return F_53 ( V_2 ,
* V_138 , * V_128 ,
V_123 , V_125 ) ;
}
static void F_56 ( struct V_142 * V_93 ,
const struct V_143 * V_56 )
{
struct V_3 * V_4 = F_57 ( V_93 -> V_100 . V_2 ) ;
enum V_65 V_65 = V_93 -> V_65 ;
F_2 ( F_58 ( V_65 ) ,
( V_56 -> V_144 [ V_65 ] . V_125 << V_145 ) |
( V_56 -> V_144 [ V_65 ] . V_146 [ 1 ] << F_59 ( 1 ) ) |
( V_56 -> V_144 [ V_65 ] . V_146 [ 0 ] << F_59 ( 0 ) ) |
( V_56 -> V_144 [ V_65 ] . V_101 << V_147 ) ) ;
F_2 ( V_108 ,
F_49 ( V_56 -> V_148 . V_66 , V_110 ) |
F_49 ( V_56 -> V_65 [ V_76 ] . V_125 , V_149 ) |
F_60 ( V_56 -> V_65 [ V_76 ] . V_101 , V_150 ) |
F_60 ( V_56 -> V_65 [ V_73 ] . V_101 , V_151 ) ) ;
F_2 ( V_152 ,
F_60 ( V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] , V_153 ) |
F_49 ( V_56 -> V_65 [ V_73 ] . V_125 , V_154 ) |
F_60 ( V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] , V_155 ) ) ;
F_2 ( V_61 ,
F_49 ( V_56 -> V_148 . V_125 , V_114 ) ) ;
if ( F_22 ( V_4 ) ) {
F_2 ( V_156 ,
F_60 ( V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] , V_157 ) |
F_60 ( V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] , V_158 ) ) ;
F_2 ( V_159 ,
F_60 ( V_56 -> V_65 [ V_77 ] . V_146 [ 1 ] , V_160 ) |
F_60 ( V_56 -> V_65 [ V_77 ] . V_146 [ 0 ] , V_161 ) ) ;
F_2 ( V_162 ,
F_60 ( V_56 -> V_65 [ V_77 ] . V_101 , V_163 ) |
F_49 ( V_56 -> V_65 [ V_77 ] . V_125 , V_164 ) ) ;
F_2 ( V_165 ,
F_49 ( V_56 -> V_148 . V_66 >> 9 , V_166 ) |
F_49 ( V_56 -> V_65 [ V_77 ] . V_146 [ 1 ] >> 8 , V_167 ) |
F_49 ( V_56 -> V_65 [ V_77 ] . V_146 [ 0 ] >> 8 , V_168 ) |
F_49 ( V_56 -> V_65 [ V_77 ] . V_101 >> 8 , V_169 ) |
F_49 ( V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] >> 8 , V_170 ) |
F_49 ( V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] >> 8 , V_171 ) |
F_49 ( V_56 -> V_65 [ V_76 ] . V_101 >> 8 , V_172 ) |
F_49 ( V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] >> 8 , V_173 ) |
F_49 ( V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] >> 8 , V_174 ) |
F_49 ( V_56 -> V_65 [ V_73 ] . V_101 >> 8 , V_175 ) ) ;
} else {
F_2 ( V_176 ,
F_60 ( V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] , V_157 ) |
F_60 ( V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] , V_158 ) ) ;
F_2 ( V_165 ,
F_49 ( V_56 -> V_148 . V_66 >> 9 , V_166 ) |
F_49 ( V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] >> 8 , V_170 ) |
F_49 ( V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] >> 8 , V_171 ) |
F_49 ( V_56 -> V_65 [ V_76 ] . V_101 >> 8 , V_172 ) |
F_49 ( V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] >> 8 , V_173 ) |
F_49 ( V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] >> 8 , V_174 ) |
F_49 ( V_56 -> V_65 [ V_73 ] . V_101 >> 8 , V_175 ) ) ;
}
F_2 ( V_177 , 0 ) ;
F_2 ( V_178 , 0 ) ;
F_2 ( V_179 , 0 ) ;
F_2 ( V_180 , 0 ) ;
F_23 ( V_108 ) ;
}
static unsigned int F_61 ( unsigned int V_181 ,
unsigned int V_182 ,
unsigned int V_183 ,
unsigned int V_84 ,
unsigned int V_41 )
{
unsigned int V_184 ;
V_184 = ( V_41 * V_181 ) / ( V_182 * 10000 ) ;
V_184 = ( V_184 + 1 ) * V_183 * V_84 ;
V_184 = F_41 ( V_184 , 64 ) ;
return V_184 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_56 . V_185 [ V_186 ] = 3 ;
V_4 -> V_56 . V_187 = V_186 ;
if ( F_22 ( V_4 ) ) {
V_4 -> V_56 . V_185 [ V_188 ] = 12 ;
V_4 -> V_56 . V_185 [ V_189 ] = 33 ;
V_4 -> V_56 . V_187 = V_189 ;
}
}
static T_4 F_63 ( struct V_190 * V_66 ,
struct V_142 * V_93 ,
const struct V_191 * V_102 ,
int V_192 )
{
struct V_3 * V_4 = F_57 ( V_66 -> V_100 . V_2 ) ;
int clock , V_129 , V_84 , V_193 , V_56 ;
if ( V_4 -> V_56 . V_185 [ V_192 ] == 0 )
return V_194 ;
if ( ! V_102 -> V_195 )
return 0 ;
V_84 = F_48 ( V_102 -> V_100 . V_103 -> V_104 , 0 ) ;
clock = V_93 -> V_99 -> V_100 . V_98 . V_105 ;
V_129 = V_93 -> V_99 -> V_100 . V_98 . V_135 ;
V_193 = V_93 -> V_99 -> V_136 ;
if ( F_64 ( V_129 == 0 ) )
V_129 = 1 ;
if ( V_66 -> V_100 . type == V_196 ) {
V_56 = 63 ;
} else {
V_56 = F_61 ( clock , V_129 , V_193 , V_84 ,
V_4 -> V_56 . V_185 [ V_192 ] * 10 ) ;
}
return F_65 ( int , V_56 , V_194 ) ;
}
static void F_66 ( struct V_142 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_100 . V_2 ;
struct V_197 * V_198 = & V_93 -> V_198 ;
struct V_190 * V_66 ;
unsigned int V_199 = 0 ;
const int V_83 = 512 - 1 ;
int V_200 , V_201 = V_83 ;
F_67 (dev, crtc, plane) {
struct V_191 * V_102 =
F_68 ( V_66 -> V_100 . V_102 ) ;
if ( V_66 -> V_100 . type == V_196 )
continue;
if ( V_102 -> V_195 ) {
V_198 -> V_202 ++ ;
V_199 += F_48 ( V_102 -> V_100 . V_103 -> V_104 , 0 ) ;
}
}
F_67 (dev, crtc, plane) {
struct V_191 * V_102 =
F_68 ( V_66 -> V_100 . V_102 ) ;
unsigned int V_203 ;
if ( V_66 -> V_100 . type == V_196 ) {
V_66 -> V_56 . V_83 = 63 ;
continue;
}
if ( ! V_102 -> V_195 ) {
V_66 -> V_56 . V_83 = 0 ;
continue;
}
V_203 = F_48 ( V_102 -> V_100 . V_103 -> V_104 , 0 ) ;
V_66 -> V_56 . V_83 = V_83 * V_203 / V_199 ;
V_201 -= V_66 -> V_56 . V_83 ;
}
V_200 = F_41 ( V_201 , V_198 -> V_202 ? : 1 ) ;
F_67 (dev, crtc, plane) {
int V_204 ;
if ( V_201 == 0 )
break;
if ( V_66 -> V_100 . type == V_196 )
continue;
if ( V_66 -> V_56 . V_83 == 0 &&
V_198 -> V_202 )
continue;
V_204 = F_55 ( V_200 , V_201 ) ;
V_66 -> V_56 . V_83 += V_204 ;
V_201 -= V_204 ;
}
F_64 ( V_201 != 0 ) ;
}
static void F_69 ( struct V_142 * V_93 )
{
struct V_197 * V_198 = & V_93 -> V_198 ;
int V_192 ;
for ( V_192 = 0 ; V_192 < V_198 -> V_205 ; V_192 ++ ) {
struct V_1 * V_2 = V_93 -> V_100 . V_2 ;
const int V_206 = F_70 ( V_2 ) -> V_207 * 512 - 1 ;
struct V_190 * V_66 ;
V_198 -> V_148 [ V_192 ] . V_66 = V_206 - V_198 -> V_148 [ V_192 ] . V_66 ;
V_198 -> V_148 [ V_192 ] . V_125 = 63 - V_198 -> V_148 [ V_192 ] . V_125 ;
F_67 (dev, crtc, plane) {
switch ( V_66 -> V_100 . type ) {
int V_146 ;
case V_196 :
V_198 -> V_56 [ V_192 ] . V_125 = V_66 -> V_56 . V_83 -
V_198 -> V_56 [ V_192 ] . V_125 ;
break;
case V_208 :
V_198 -> V_56 [ V_192 ] . V_101 = V_66 -> V_56 . V_83 -
V_198 -> V_56 [ V_192 ] . V_101 ;
break;
case V_209 :
V_146 = V_66 -> V_66 ;
V_198 -> V_56 [ V_192 ] . V_146 [ V_146 ] = V_66 -> V_56 . V_83 -
V_198 -> V_56 [ V_192 ] . V_146 [ V_146 ] ;
break;
}
}
}
}
static void F_71 ( struct V_142 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_100 . V_2 ;
struct V_197 * V_198 = & V_93 -> V_198 ;
struct V_190 * V_66 ;
int V_206 = F_70 ( V_2 ) -> V_207 * 512 - 1 ;
int V_192 ;
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
V_198 -> V_58 = V_93 -> V_65 != V_77 && V_93 -> V_56 . V_210 ;
V_198 -> V_205 = F_57 ( V_2 ) -> V_56 . V_187 + 1 ;
V_198 -> V_202 = 0 ;
F_66 ( V_93 ) ;
if ( V_198 -> V_202 != 1 )
V_198 -> V_58 = false ;
if ( V_198 -> V_58 ) {
for ( V_192 = 0 ; V_192 < V_198 -> V_205 ; V_192 ++ ) {
V_198 -> V_148 [ V_192 ] . V_66 = V_206 ;
V_198 -> V_148 [ V_192 ] . V_125 = 63 ;
}
}
F_67 (dev, crtc, plane) {
struct V_191 * V_102 =
F_68 ( V_66 -> V_100 . V_102 ) ;
if ( ! V_102 -> V_195 )
continue;
for ( V_192 = 0 ; V_192 < V_198 -> V_205 ; V_192 ++ ) {
int V_56 = F_63 ( V_66 , V_93 , V_102 , V_192 ) ;
int V_90 = V_66 -> V_100 . type == V_196 ? 63 : 511 ;
if ( F_64 ( V_192 == 0 && V_56 > V_90 ) )
V_56 = V_90 ;
if ( V_56 > V_66 -> V_56 . V_83 )
break;
switch ( V_66 -> V_100 . type ) {
int V_146 ;
case V_196 :
V_198 -> V_56 [ V_192 ] . V_125 = V_56 ;
break;
case V_208 :
V_198 -> V_56 [ V_192 ] . V_101 = V_56 ;
break;
case V_209 :
V_146 = V_66 -> V_66 ;
V_198 -> V_56 [ V_192 ] . V_146 [ V_146 ] = V_56 ;
break;
}
}
V_198 -> V_205 = V_192 ;
if ( ! V_198 -> V_58 )
continue;
switch ( V_66 -> V_100 . type ) {
int V_146 , V_192 ;
case V_196 :
for ( V_192 = 0 ; V_192 < V_198 -> V_205 ; V_192 ++ )
V_198 -> V_148 [ V_192 ] . V_125 =
V_198 -> V_56 [ V_192 ] . V_125 ;
break;
case V_208 :
for ( V_192 = 0 ; V_192 < V_198 -> V_205 ; V_192 ++ )
V_198 -> V_148 [ V_192 ] . V_66 =
F_55 ( V_198 -> V_148 [ V_192 ] . V_66 ,
V_198 -> V_56 [ V_192 ] . V_101 ) ;
break;
case V_209 :
V_146 = V_66 -> V_66 ;
for ( V_192 = 0 ; V_192 < V_198 -> V_205 ; V_192 ++ )
V_198 -> V_148 [ V_192 ] . V_66 =
F_55 ( V_198 -> V_148 [ V_192 ] . V_66 ,
V_198 -> V_56 [ V_192 ] . V_146 [ V_146 ] ) ;
break;
}
}
for ( V_192 = V_198 -> V_205 ; V_192 < F_57 ( V_2 ) -> V_56 . V_187 + 1 ; V_192 ++ ) {
memset ( & V_198 -> V_56 [ V_192 ] , 0 , sizeof( V_198 -> V_56 [ V_192 ] ) ) ;
memset ( & V_198 -> V_148 [ V_192 ] , 0 , sizeof( V_198 -> V_148 [ V_192 ] ) ) ;
}
F_69 ( V_93 ) ;
}
static void F_72 ( struct V_142 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_100 . V_2 ;
struct V_3 * V_4 = F_57 ( V_2 ) ;
struct V_190 * V_66 ;
int V_67 = 0 , V_68 = 0 , V_83 = 0 ;
F_67 (dev, crtc, plane) {
if ( V_66 -> V_100 . type == V_196 ) {
F_64 ( V_66 -> V_56 . V_83 != 63 ) ;
continue;
}
if ( V_66 -> V_100 . type == V_208 )
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
int V_211 = 0 ;
V_56 -> V_192 = F_57 ( V_2 ) -> V_56 . V_187 ;
V_56 -> V_58 = true ;
F_75 (dev, crtc) {
const struct V_197 * V_198 = & V_93 -> V_198 ;
if ( ! V_93 -> V_212 )
continue;
if ( ! V_198 -> V_58 )
V_56 -> V_58 = false ;
V_211 ++ ;
V_56 -> V_192 = F_65 ( int , V_56 -> V_192 , V_198 -> V_205 - 1 ) ;
}
if ( V_211 != 1 )
V_56 -> V_58 = false ;
if ( V_211 > 1 )
V_56 -> V_192 = V_186 ;
F_75 (dev, crtc) {
struct V_197 * V_198 = & V_93 -> V_198 ;
enum V_65 V_65 = V_93 -> V_65 ;
if ( ! V_93 -> V_212 )
continue;
V_56 -> V_65 [ V_65 ] = V_198 -> V_56 [ V_56 -> V_192 ] ;
if ( V_56 -> V_58 )
V_56 -> V_148 = V_198 -> V_148 [ V_56 -> V_192 ] ;
V_56 -> V_144 [ V_65 ] . V_101 = V_213 | 2 ;
V_56 -> V_144 [ V_65 ] . V_146 [ 0 ] = V_213 | 2 ;
V_56 -> V_144 [ V_65 ] . V_146 [ 1 ] = V_213 | 2 ;
V_56 -> V_144 [ V_65 ] . V_125 = V_213 | 2 ;
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
if ( V_56 . V_192 < V_189 &&
V_4 -> V_56 . V_57 . V_192 >= V_189 )
F_12 ( V_4 , false ) ;
if ( V_56 . V_192 < V_188 &&
V_4 -> V_56 . V_57 . V_192 >= V_188 )
F_19 ( V_4 , false ) ;
if ( ! V_56 . V_58 && V_4 -> V_56 . V_57 . V_58 )
F_20 ( V_4 , false ) ;
F_72 ( V_142 ) ;
F_56 ( V_142 , & V_56 ) ;
F_11 ( L_23
L_24 ,
F_34 ( V_65 ) , V_56 . V_65 [ V_65 ] . V_101 , V_56 . V_65 [ V_65 ] . V_125 ,
V_56 . V_65 [ V_65 ] . V_146 [ 0 ] , V_56 . V_65 [ V_65 ] . V_146 [ 1 ] ,
V_56 . V_148 . V_66 , V_56 . V_148 . V_125 , V_56 . V_192 , V_56 . V_58 ) ;
if ( V_56 . V_58 && ! V_4 -> V_56 . V_57 . V_58 )
F_20 ( V_4 , true ) ;
if ( V_56 . V_192 >= V_188 &&
V_4 -> V_56 . V_57 . V_192 < V_188 )
F_19 ( V_4 , true ) ;
if ( V_56 . V_192 >= V_189 &&
V_4 -> V_56 . V_57 . V_192 < V_189 )
F_12 ( V_4 , true ) ;
V_4 -> V_56 . V_57 = V_56 ;
}
static void F_77 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
static const int V_214 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_215 , V_216 , V_217 , V_218 ;
int V_219 , V_112 ;
unsigned int V_94 = 0 ;
bool V_220 ;
if ( F_50 ( V_2 , V_73 ,
& V_221 , V_222 ,
& V_223 , V_222 ,
& V_215 , & V_217 ) )
V_94 |= 1 << V_73 ;
if ( F_50 ( V_2 , V_76 ,
& V_221 , V_222 ,
& V_223 , V_222 ,
& V_216 , & V_218 ) )
V_94 |= 1 << V_76 ;
if ( F_78 ( V_94 ) &&
F_54 ( V_2 , F_79 ( V_94 ) - 1 ,
V_214 ,
& V_221 ,
& V_223 ,
& V_219 , & V_112 ) ) {
V_220 = true ;
} else {
V_220 = false ;
F_20 ( V_4 , false ) ;
V_219 = V_112 = 0 ;
}
F_11 ( L_25
L_26 ,
V_215 , V_217 ,
V_216 , V_218 ,
V_219 , V_112 ) ;
F_2 ( V_108 ,
F_49 ( V_219 , V_110 ) |
F_49 ( V_218 , V_149 ) |
F_49 ( V_216 , V_150 ) |
F_49 ( V_215 , V_151 ) ) ;
F_2 ( V_152 ,
( F_3 ( V_152 ) & ~ V_224 ) |
F_49 ( V_217 , V_154 ) ) ;
F_2 ( V_61 ,
( F_3 ( V_61 ) & ~ ( V_225 | V_113 ) ) |
F_49 ( V_112 , V_114 ) ) ;
if ( V_220 )
F_20 ( V_4 , true ) ;
}
static void F_80 ( struct V_92 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_92 * V_93 ;
int V_226 = 1 ;
int V_112 = 16 ;
bool V_220 ;
V_93 = F_42 ( V_2 ) ;
if ( V_93 ) {
static const int V_214 = 12000 ;
const struct V_97 * V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
int clock = V_98 -> V_105 ;
int V_129 = V_98 -> V_135 ;
int V_130 = F_47 ( V_93 ) -> V_99 -> V_136 ;
int V_84 = F_48 ( V_93 -> V_101 -> V_102 -> V_103 -> V_104 , 0 ) ;
unsigned long V_131 ;
int V_133 ;
V_131 = F_52 ( V_129 * 1000 / clock , 1 ) ;
V_133 = ( ( ( V_214 / V_131 ) + 1000 ) / 1000 ) *
V_84 * V_130 ;
V_133 = F_41 ( V_133 , V_227 ) ;
V_226 = V_228 - V_133 ;
if ( V_226 < 0 )
V_226 = 1 ;
V_226 &= 0x1ff ;
F_11 ( L_27 ,
V_133 , V_226 ) ;
V_133 = ( ( ( V_214 / V_131 ) + 1000 ) / 1000 ) *
V_84 * V_93 -> V_125 -> V_102 -> V_137 ;
V_133 = F_41 ( V_133 ,
V_229 . V_88 ) ;
V_112 = V_229 . V_83 -
( V_133 + V_229 . V_89 ) ;
if ( V_112 > V_229 . V_90 )
V_112 = V_229 . V_90 ;
F_11 ( L_28
L_29 , V_226 , V_112 ) ;
V_220 = true ;
} else {
V_220 = false ;
F_20 ( V_4 , false ) ;
}
F_11 ( L_30 ,
V_226 ) ;
F_2 ( V_108 , F_49 ( V_226 , V_110 ) |
F_49 ( 8 , V_149 ) |
F_49 ( 8 , V_150 ) |
F_49 ( 8 , V_151 ) ) ;
F_2 ( V_152 , F_49 ( 8 , V_154 ) |
F_49 ( 8 , V_230 ) ) ;
F_2 ( V_61 , F_49 ( V_112 , V_114 ) ) ;
if ( V_220 )
F_20 ( V_4 , true ) ;
}
static void F_81 ( struct V_92 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_82 * V_231 ;
T_3 V_232 ;
T_3 V_233 ;
int V_234 , V_226 = 1 ;
int V_83 ;
int V_215 , V_216 ;
struct V_92 * V_93 , * V_94 = NULL ;
if ( F_28 ( V_2 ) )
V_231 = & V_235 ;
else if ( ! F_82 ( V_2 ) )
V_231 = & V_236 ;
else
V_231 = & V_237 ;
V_83 = V_4 -> V_123 . V_238 ( V_2 , 0 ) ;
V_93 = F_51 ( V_2 , 0 ) ;
if ( F_44 ( V_93 ) ) {
const struct V_97 * V_98 ;
int V_84 = F_48 ( V_93 -> V_101 -> V_102 -> V_103 -> V_104 , 0 ) ;
if ( F_82 ( V_2 ) )
V_84 = 4 ;
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
V_215 = F_40 ( V_98 -> V_105 ,
V_231 , V_83 , V_84 ,
V_222 ) ;
V_94 = V_93 ;
} else {
V_215 = V_83 - V_231 -> V_89 ;
if ( V_215 > ( long ) V_231 -> V_90 )
V_215 = V_231 -> V_90 ;
}
if ( F_82 ( V_2 ) )
V_231 = & V_239 ;
V_83 = V_4 -> V_123 . V_238 ( V_2 , 1 ) ;
V_93 = F_51 ( V_2 , 1 ) ;
if ( F_44 ( V_93 ) ) {
const struct V_97 * V_98 ;
int V_84 = F_48 ( V_93 -> V_101 -> V_102 -> V_103 -> V_104 , 0 ) ;
if ( F_82 ( V_2 ) )
V_84 = 4 ;
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
V_216 = F_40 ( V_98 -> V_105 ,
V_231 , V_83 , V_84 ,
V_222 ) ;
if ( V_94 == NULL )
V_94 = V_93 ;
else
V_94 = NULL ;
} else {
V_216 = V_83 - V_231 -> V_89 ;
if ( V_216 > ( long ) V_231 -> V_90 )
V_216 = V_231 -> V_90 ;
}
F_11 ( L_31 , V_215 , V_216 ) ;
if ( F_31 ( V_2 ) && V_94 ) {
struct V_240 * V_241 ;
V_241 = F_83 ( V_94 -> V_101 -> V_102 -> V_103 ) ;
if ( V_241 -> V_242 == V_243 )
V_94 = NULL ;
}
V_234 = 2 ;
F_20 ( V_4 , false ) ;
if ( F_84 ( V_2 ) && V_94 ) {
static const int V_214 = 6000 ;
const struct V_97 * V_98 = & F_47 ( V_94 ) -> V_99 -> V_100 . V_98 ;
int clock = V_98 -> V_105 ;
int V_129 = V_98 -> V_135 ;
int V_130 = F_47 ( V_94 ) -> V_99 -> V_136 ;
int V_84 = F_48 ( V_94 -> V_101 -> V_102 -> V_103 -> V_104 , 0 ) ;
unsigned long V_131 ;
int V_133 ;
V_131 = F_52 ( V_129 * 1000 / clock , 1 ) ;
V_133 = ( ( ( V_214 / V_131 ) + 1000 ) / 1000 ) *
V_84 * V_130 ;
V_133 = F_41 ( V_133 , V_231 -> V_88 ) ;
F_11 ( L_32 , V_133 ) ;
V_226 = V_231 -> V_83 - V_133 ;
if ( V_226 < 0 )
V_226 = 1 ;
if ( F_27 ( V_2 ) || F_28 ( V_2 ) )
F_2 ( V_59 ,
V_244 | ( V_226 & 0xff ) ) ;
else if ( F_31 ( V_2 ) )
F_2 ( V_59 , V_226 & 0x3f ) ;
}
F_11 ( L_33 ,
V_215 , V_216 , V_234 , V_226 ) ;
V_232 = ( ( V_216 & 0x3f ) << 16 ) | ( V_215 & 0x3f ) ;
V_233 = ( V_234 & 0x1f ) ;
V_232 = V_232 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_233 = V_233 | ( 1 << 8 ) ;
F_2 ( V_245 , V_232 ) ;
F_2 ( V_246 , V_233 ) ;
if ( V_94 )
F_20 ( V_4 , true ) ;
}
static void F_85 ( struct V_92 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_92 * V_93 ;
const struct V_97 * V_98 ;
T_3 V_232 ;
int V_215 ;
V_93 = F_42 ( V_2 ) ;
if ( V_93 == NULL )
return;
V_98 = & F_47 ( V_93 ) -> V_99 -> V_100 . V_98 ;
V_215 = F_40 ( V_98 -> V_105 ,
& V_247 ,
V_4 -> V_123 . V_238 ( V_2 , 0 ) ,
4 , V_222 ) ;
V_232 = F_3 ( V_245 ) & ~ 0xfff ;
V_232 |= ( 3 << 8 ) | V_215 ;
F_11 ( L_34 , V_215 ) ;
F_2 ( V_245 , V_232 ) ;
}
T_3 F_86 ( const struct V_248 * V_249 )
{
T_3 V_181 ;
V_181 = V_249 -> V_100 . V_98 . V_105 ;
if ( V_249 -> V_250 . V_94 ) {
T_5 V_251 , V_252 , V_253 , V_254 ;
T_3 V_255 = V_249 -> V_250 . V_69 ;
V_251 = V_249 -> V_136 ;
V_252 = V_249 -> V_256 ;
V_253 = ( V_255 >> 16 ) & 0xFFFF ;
V_254 = V_255 & 0xFFFF ;
if ( V_251 < V_253 )
V_251 = V_253 ;
if ( V_252 < V_254 )
V_252 = V_254 ;
if ( F_64 ( ! V_253 || ! V_254 ) )
return V_181 ;
V_181 = F_87 ( ( T_5 ) V_181 * V_251 * V_252 ,
V_253 * V_254 ) ;
}
return V_181 ;
}
static T_3 F_88 ( T_3 V_181 , T_6 V_84 , T_3 V_41 )
{
T_5 V_184 ;
if ( F_89 ( V_41 == 0 , L_35 ) )
return V_257 ;
V_184 = ( T_5 ) V_181 * V_84 * V_41 ;
V_184 = F_90 ( V_184 , 64 * 10000 ) + 2 ;
return V_184 ;
}
static T_3 F_91 ( T_3 V_181 , T_3 V_182 ,
T_3 V_183 , T_6 V_84 ,
T_3 V_41 )
{
T_3 V_184 ;
if ( F_89 ( V_41 == 0 , L_35 ) )
return V_257 ;
if ( F_64 ( ! V_182 ) )
return V_257 ;
V_184 = ( V_41 * V_181 ) / ( V_182 * 10000 ) ;
V_184 = ( V_184 + 1 ) * V_183 * V_84 ;
V_184 = F_41 ( V_184 , 64 ) + 2 ;
return V_184 ;
}
static T_3 F_92 ( T_3 V_258 , T_3 V_183 ,
T_6 V_84 )
{
if ( F_64 ( ! V_84 ) )
return 0 ;
if ( F_64 ( ! V_183 ) )
return 0 ;
return F_41 ( V_258 * 64 , V_183 * V_84 ) + 2 ;
}
static T_3 F_93 ( const struct V_248 * V_259 ,
const struct V_191 * V_260 ,
T_3 V_261 ,
bool V_262 )
{
int V_84 = V_260 -> V_100 . V_103 ?
F_48 ( V_260 -> V_100 . V_103 -> V_104 , 0 ) : 0 ;
T_3 V_263 , V_264 ;
if ( ! V_259 -> V_100 . V_212 || ! V_260 -> V_195 )
return 0 ;
V_263 = F_88 ( F_86 ( V_259 ) , V_84 , V_261 ) ;
if ( ! V_262 )
return V_263 ;
V_264 = F_91 ( F_86 ( V_259 ) ,
V_259 -> V_100 . V_98 . V_135 ,
F_94 ( & V_260 -> V_265 ) ,
V_84 , V_261 ) ;
return F_55 ( V_263 , V_264 ) ;
}
static T_3 F_95 ( const struct V_248 * V_259 ,
const struct V_191 * V_260 ,
T_3 V_261 )
{
int V_84 = V_260 -> V_100 . V_103 ?
F_48 ( V_260 -> V_100 . V_103 -> V_104 , 0 ) : 0 ;
T_3 V_263 , V_264 ;
if ( ! V_259 -> V_100 . V_212 || ! V_260 -> V_195 )
return 0 ;
V_263 = F_88 ( F_86 ( V_259 ) , V_84 , V_261 ) ;
V_264 = F_91 ( F_86 ( V_259 ) ,
V_259 -> V_100 . V_98 . V_135 ,
F_94 ( & V_260 -> V_265 ) ,
V_84 , V_261 ) ;
return F_55 ( V_263 , V_264 ) ;
}
static T_3 F_96 ( const struct V_248 * V_259 ,
const struct V_191 * V_260 ,
T_3 V_261 )
{
int V_84 = 4 ;
int V_193 = V_260 -> V_195 ? V_260 -> V_100 . V_137 : 64 ;
if ( ! V_259 -> V_100 . V_212 )
return 0 ;
return F_91 ( F_86 ( V_259 ) ,
V_259 -> V_100 . V_98 . V_135 ,
V_193 , V_84 , V_261 ) ;
}
static T_3 F_97 ( const struct V_248 * V_259 ,
const struct V_191 * V_260 ,
T_3 V_258 )
{
int V_84 = V_260 -> V_100 . V_103 ?
F_48 ( V_260 -> V_100 . V_103 -> V_104 , 0 ) : 0 ;
if ( ! V_259 -> V_100 . V_212 || ! V_260 -> V_195 )
return 0 ;
return F_92 ( V_258 , F_94 ( & V_260 -> V_265 ) , V_84 ) ;
}
static unsigned int F_98 ( const struct V_1 * V_2 )
{
if ( F_70 ( V_2 ) -> V_266 >= 8 )
return 3072 ;
else if ( F_70 ( V_2 ) -> V_266 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_99 ( const struct V_1 * V_2 ,
int V_192 , bool V_267 )
{
if ( F_70 ( V_2 ) -> V_266 >= 8 )
return V_192 == 0 ? 255 : 2047 ;
else if ( F_70 ( V_2 ) -> V_266 >= 7 )
return V_192 == 0 ? 127 : 1023 ;
else if ( ! V_267 )
return V_192 == 0 ? 127 : 511 ;
else
return V_192 == 0 ? 63 : 255 ;
}
static unsigned int F_100 ( const struct V_1 * V_2 ,
int V_192 )
{
if ( F_70 ( V_2 ) -> V_266 >= 7 )
return V_192 == 0 ? 63 : 255 ;
else
return V_192 == 0 ? 31 : 63 ;
}
static unsigned int F_101 ( const struct V_1 * V_2 )
{
if ( F_70 ( V_2 ) -> V_266 >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_102 ( const struct V_1 * V_2 ,
int V_192 ,
const struct V_268 * V_99 ,
enum V_269 V_270 ,
bool V_267 )
{
unsigned int V_83 = F_98 ( V_2 ) ;
if ( V_267 && ! V_99 -> V_271 )
return 0 ;
if ( V_192 == 0 || V_99 -> V_272 > 1 ) {
V_83 /= F_70 ( V_2 ) -> V_207 ;
if ( F_70 ( V_2 ) -> V_266 <= 6 )
V_83 /= 2 ;
}
if ( V_99 -> V_271 ) {
if ( V_192 > 0 && V_270 == V_273 ) {
if ( V_267 )
V_83 *= 5 ;
V_83 /= 6 ;
} else {
V_83 /= 2 ;
}
}
return F_55 ( V_83 , F_99 ( V_2 , V_192 , V_267 ) ) ;
}
static unsigned int F_103 ( const struct V_1 * V_2 ,
int V_192 ,
const struct V_268 * V_99 )
{
if ( V_192 > 0 && V_99 -> V_272 > 1 )
return 64 ;
return F_100 ( V_2 , V_192 ) ;
}
static void F_104 ( const struct V_1 * V_2 ,
int V_192 ,
const struct V_268 * V_99 ,
enum V_269 V_270 ,
struct V_274 * F_52 )
{
F_52 -> V_275 = F_102 ( V_2 , V_192 , V_99 , V_270 , false ) ;
F_52 -> V_276 = F_102 ( V_2 , V_192 , V_99 , V_270 , true ) ;
F_52 -> V_277 = F_103 ( V_2 , V_192 , V_99 ) ;
F_52 -> V_278 = F_101 ( V_2 ) ;
}
static void F_105 ( struct V_1 * V_2 ,
int V_192 ,
struct V_274 * F_52 )
{
F_52 -> V_275 = F_99 ( V_2 , V_192 , false ) ;
F_52 -> V_276 = F_99 ( V_2 , V_192 , true ) ;
F_52 -> V_277 = F_100 ( V_2 , V_192 ) ;
F_52 -> V_278 = F_101 ( V_2 ) ;
}
static bool F_106 ( int V_192 ,
const struct V_274 * F_52 ,
struct V_279 * V_280 )
{
bool V_184 ;
if ( ! V_280 -> V_44 )
return false ;
V_280 -> V_44 = V_280 -> V_258 <= F_52 -> V_275 &&
V_280 -> V_281 <= F_52 -> V_276 &&
V_280 -> V_282 <= F_52 -> V_277 ;
V_184 = V_280 -> V_44 ;
if ( V_192 == 0 && ! V_280 -> V_44 ) {
if ( V_280 -> V_258 > F_52 -> V_275 )
F_11 ( L_36 ,
V_192 , V_280 -> V_258 , F_52 -> V_275 ) ;
if ( V_280 -> V_281 > F_52 -> V_276 )
F_11 ( L_37 ,
V_192 , V_280 -> V_281 , F_52 -> V_276 ) ;
if ( V_280 -> V_282 > F_52 -> V_277 )
F_11 ( L_38 ,
V_192 , V_280 -> V_282 , F_52 -> V_277 ) ;
V_280 -> V_258 = F_65 ( T_3 , V_280 -> V_258 , F_52 -> V_275 ) ;
V_280 -> V_281 = F_65 ( T_3 , V_280 -> V_281 , F_52 -> V_276 ) ;
V_280 -> V_282 = F_65 ( T_3 , V_280 -> V_282 , F_52 -> V_277 ) ;
V_280 -> V_44 = true ;
}
return V_184 ;
}
static void F_107 ( const struct V_3 * V_4 ,
const struct V_142 * V_142 ,
int V_192 ,
struct V_248 * V_259 ,
struct V_191 * V_283 ,
struct V_191 * V_284 ,
struct V_191 * V_285 ,
struct V_279 * V_280 )
{
T_4 V_185 = V_4 -> V_56 . V_185 [ V_192 ] ;
T_4 V_286 = V_4 -> V_56 . V_286 [ V_192 ] ;
T_4 V_287 = V_4 -> V_56 . V_287 [ V_192 ] ;
if ( V_192 > 0 ) {
V_185 *= 5 ;
V_286 *= 5 ;
V_287 *= 5 ;
}
V_280 -> V_258 = F_93 ( V_259 , V_283 ,
V_185 , V_192 ) ;
V_280 -> V_281 = F_95 ( V_259 , V_284 , V_286 ) ;
V_280 -> V_282 = F_96 ( V_259 , V_285 , V_287 ) ;
V_280 -> V_288 = F_97 ( V_259 , V_283 , V_280 -> V_258 ) ;
V_280 -> V_44 = true ;
}
static T_3
F_108 ( struct V_1 * V_2 ,
struct V_248 * V_259 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_97 * V_98 =
& V_259 -> V_100 . V_98 ;
T_1 V_289 , V_290 ;
if ( ! V_259 -> V_100 . V_212 )
return 0 ;
if ( F_64 ( V_98 -> V_105 == 0 ) )
return 0 ;
if ( F_64 ( V_4 -> V_291 == 0 ) )
return 0 ;
V_289 = F_109 ( V_98 -> V_135 * 1000 * 8 ,
V_98 -> V_105 ) ;
V_290 = F_109 ( V_98 -> V_135 * 1000 * 8 ,
V_4 -> V_291 ) ;
return F_110 ( V_290 ) |
F_111 ( V_289 ) ;
}
static void F_112 ( struct V_1 * V_2 , T_4 V_56 [ 8 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_113 ( V_2 ) ) {
T_3 V_45 ;
int V_184 , V_42 ;
int V_192 , V_187 = F_114 ( V_2 ) ;
V_45 = 0 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_184 = F_115 ( V_4 ,
V_292 ,
& V_45 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
if ( V_184 ) {
F_17 ( L_39 , V_184 ) ;
return;
}
V_56 [ 0 ] = V_45 & V_293 ;
V_56 [ 1 ] = ( V_45 >> V_294 ) &
V_293 ;
V_56 [ 2 ] = ( V_45 >> V_295 ) &
V_293 ;
V_56 [ 3 ] = ( V_45 >> V_296 ) &
V_293 ;
V_45 = 1 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_184 = F_115 ( V_4 ,
V_292 ,
& V_45 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
if ( V_184 ) {
F_17 ( L_39 , V_184 ) ;
return;
}
V_56 [ 4 ] = V_45 & V_293 ;
V_56 [ 5 ] = ( V_45 >> V_294 ) &
V_293 ;
V_56 [ 6 ] = ( V_45 >> V_295 ) &
V_293 ;
V_56 [ 7 ] = ( V_45 >> V_296 ) &
V_293 ;
V_56 [ 0 ] += 2 ;
for ( V_192 = 1 ; V_192 <= V_187 ; V_192 ++ )
if ( V_56 [ V_192 ] != 0 )
V_56 [ V_192 ] += 2 ;
else {
for ( V_42 = V_192 + 1 ; V_42 <= V_187 ; V_42 ++ )
V_56 [ V_42 ] = 0 ;
break;
}
} else if ( F_116 ( V_2 ) || F_117 ( V_2 ) ) {
T_5 V_297 = F_118 ( V_298 ) ;
V_56 [ 0 ] = ( V_297 >> 56 ) & 0xFF ;
if ( V_56 [ 0 ] == 0 )
V_56 [ 0 ] = V_297 & 0xF ;
V_56 [ 1 ] = ( V_297 >> 4 ) & 0xFF ;
V_56 [ 2 ] = ( V_297 >> 12 ) & 0xFF ;
V_56 [ 3 ] = ( V_297 >> 20 ) & 0x1FF ;
V_56 [ 4 ] = ( V_297 >> 32 ) & 0x1FF ;
} else if ( F_70 ( V_2 ) -> V_266 >= 6 ) {
T_3 V_297 = F_3 ( V_298 ) ;
V_56 [ 0 ] = ( V_297 >> V_299 ) & V_300 ;
V_56 [ 1 ] = ( V_297 >> V_301 ) & V_300 ;
V_56 [ 2 ] = ( V_297 >> V_302 ) & V_300 ;
V_56 [ 3 ] = ( V_297 >> V_303 ) & V_300 ;
} else if ( F_70 ( V_2 ) -> V_266 >= 5 ) {
T_3 V_304 = F_3 ( V_305 ) ;
V_56 [ 0 ] = 7 ;
V_56 [ 1 ] = ( V_304 >> V_306 ) & V_307 ;
V_56 [ 2 ] = ( V_304 >> V_308 ) & V_307 ;
}
}
static void F_119 ( struct V_1 * V_2 , T_4 V_56 [ 5 ] )
{
if ( F_70 ( V_2 ) -> V_266 == 5 )
V_56 [ 0 ] = 13 ;
}
static void F_120 ( struct V_1 * V_2 , T_4 V_56 [ 5 ] )
{
if ( F_70 ( V_2 ) -> V_266 == 5 )
V_56 [ 0 ] = 13 ;
if ( F_121 ( V_2 ) )
V_56 [ 3 ] *= 2 ;
}
int F_114 ( const struct V_1 * V_2 )
{
if ( F_70 ( V_2 ) -> V_266 >= 9 )
return 7 ;
else if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
return 4 ;
else if ( F_70 ( V_2 ) -> V_266 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_122 ( struct V_1 * V_2 ,
const char * V_309 ,
const T_4 V_56 [ 8 ] )
{
int V_192 , V_187 = F_114 ( V_2 ) ;
for ( V_192 = 0 ; V_192 <= V_187 ; V_192 ++ ) {
unsigned int V_41 = V_56 [ V_192 ] ;
if ( V_41 == 0 ) {
F_17 ( L_40 ,
V_309 , V_192 ) ;
continue;
}
if ( F_113 ( V_2 ) )
V_41 *= 10 ;
else if ( V_192 > 0 )
V_41 *= 5 ;
F_11 ( L_41 ,
V_309 , V_192 , V_56 [ V_192 ] ,
V_41 / 10 , V_41 % 10 ) ;
}
}
static bool F_123 ( struct V_3 * V_4 ,
T_4 V_56 [ 5 ] , T_4 F_55 )
{
int V_192 , V_187 = F_114 ( V_4 -> V_2 ) ;
if ( V_56 [ 0 ] >= F_55 )
return false ;
V_56 [ 0 ] = F_52 ( V_56 [ 0 ] , F_55 ) ;
for ( V_192 = 1 ; V_192 <= V_187 ; V_192 ++ )
V_56 [ V_192 ] = F_124 ( T_4 , V_56 [ V_192 ] , F_41 ( F_55 , 5 ) ) ;
return true ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_310 ;
V_310 = F_123 ( V_4 , V_4 -> V_56 . V_185 , 12 ) |
F_123 ( V_4 , V_4 -> V_56 . V_286 , 12 ) |
F_123 ( V_4 , V_4 -> V_56 . V_287 , 12 ) ;
if ( ! V_310 )
return;
F_11 ( L_42 ) ;
F_122 ( V_2 , L_43 , V_4 -> V_56 . V_185 ) ;
F_122 ( V_2 , L_44 , V_4 -> V_56 . V_286 ) ;
F_122 ( V_2 , L_45 , V_4 -> V_56 . V_287 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_112 ( V_2 , V_4 -> V_56 . V_185 ) ;
memcpy ( V_4 -> V_56 . V_286 , V_4 -> V_56 . V_185 ,
sizeof( V_4 -> V_56 . V_185 ) ) ;
memcpy ( V_4 -> V_56 . V_287 , V_4 -> V_56 . V_185 ,
sizeof( V_4 -> V_56 . V_185 ) ) ;
F_119 ( V_2 , V_4 -> V_56 . V_286 ) ;
F_120 ( V_2 , V_4 -> V_56 . V_287 ) ;
F_122 ( V_2 , L_43 , V_4 -> V_56 . V_185 ) ;
F_122 ( V_2 , L_44 , V_4 -> V_56 . V_286 ) ;
F_122 ( V_2 , L_45 , V_4 -> V_56 . V_287 ) ;
if ( F_127 ( V_2 ) )
F_125 ( V_2 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_112 ( V_2 , V_4 -> V_56 . V_311 ) ;
F_122 ( V_2 , L_46 , V_4 -> V_56 . V_311 ) ;
}
static int F_129 ( struct V_142 * V_142 ,
struct V_312 * V_102 )
{
struct V_313 * V_314 ;
struct V_1 * V_2 = V_142 -> V_100 . V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_248 * V_259 = NULL ;
struct V_190 * V_190 ;
struct V_315 * V_316 ;
struct V_191 * V_283 = NULL ;
struct V_191 * V_284 = NULL ;
struct V_191 * V_285 = NULL ;
int V_192 , V_187 = F_114 ( V_2 ) ;
struct V_268 V_99 = {
. V_272 = 1 ,
} ;
struct V_274 F_52 ;
V_259 = F_130 ( V_102 , V_142 ) ;
if ( F_131 ( V_259 ) )
return F_132 ( V_259 ) ;
V_314 = & V_259 -> V_56 . V_317 . V_318 ;
memset ( V_314 , 0 , sizeof( * V_314 ) ) ;
F_67 (dev, intel_crtc, intel_plane) {
V_316 = F_133 ( V_102 ,
& V_190 -> V_100 ) ;
if ( F_131 ( V_316 ) )
return F_132 ( V_316 ) ;
if ( V_190 -> V_100 . type == V_208 )
V_283 = F_68 ( V_316 ) ;
else if ( V_190 -> V_100 . type == V_209 )
V_284 = F_68 ( V_316 ) ;
else if ( V_190 -> V_100 . type == V_196 )
V_285 = F_68 ( V_316 ) ;
}
V_99 . V_271 = V_284 -> V_195 ;
V_99 . V_319 = V_284 -> V_195 &&
( F_94 ( & V_284 -> V_265 ) != F_94 ( & V_284 -> V_320 ) >> 16 ||
F_134 ( & V_284 -> V_265 ) != F_134 ( & V_284 -> V_320 ) >> 16 ) ;
V_314 -> V_321 = V_259 -> V_100 . V_212 ;
V_314 -> V_271 = V_99 . V_271 ;
V_314 -> V_319 = V_99 . V_319 ;
if ( F_70 ( V_2 ) -> V_266 <= 6 && V_284 -> V_195 )
V_187 = 1 ;
if ( V_99 . V_319 )
V_187 = 0 ;
F_107 ( V_4 , V_142 , 0 , V_259 ,
V_283 , V_284 , V_285 , & V_314 -> V_56 [ 0 ] ) ;
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
V_314 -> V_289 = F_108 ( V_2 , V_259 ) ;
F_104 ( V_2 , 0 , & V_99 , V_322 , & F_52 ) ;
if ( ! F_106 ( 0 , & F_52 , & V_314 -> V_56 [ 0 ] ) )
return - V_323 ;
F_105 ( V_2 , 1 , & F_52 ) ;
for ( V_192 = 1 ; V_192 <= V_187 ; V_192 ++ ) {
struct V_279 V_56 = {} ;
F_107 ( V_4 , V_142 , V_192 , V_259 ,
V_283 , V_284 , V_285 , & V_56 ) ;
if ( ! F_106 ( V_192 , & F_52 , & V_56 ) )
break;
V_314 -> V_56 [ V_192 ] = V_56 ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 ,
int V_192 ,
struct V_279 * V_324 )
{
const struct V_142 * V_142 ;
V_324 -> V_44 = true ;
F_75 (dev, intel_crtc) {
const struct V_248 * V_259 =
F_136 ( V_142 -> V_100 . V_102 ) ;
const struct V_313 * V_212 = & V_259 -> V_56 . V_317 . V_318 ;
const struct V_279 * V_56 = & V_212 -> V_56 [ V_192 ] ;
if ( ! V_212 -> V_321 )
continue;
if ( ! V_56 -> V_44 )
V_324 -> V_44 = false ;
V_324 -> V_258 = F_52 ( V_324 -> V_258 , V_56 -> V_258 ) ;
V_324 -> V_281 = F_52 ( V_324 -> V_281 , V_56 -> V_281 ) ;
V_324 -> V_282 = F_52 ( V_324 -> V_282 , V_56 -> V_282 ) ;
V_324 -> V_288 = F_52 ( V_324 -> V_288 , V_56 -> V_288 ) ;
}
}
static void F_137 ( struct V_1 * V_2 ,
const struct V_268 * V_99 ,
const struct V_274 * F_52 ,
struct V_313 * V_325 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_192 , V_187 = F_114 ( V_2 ) ;
int V_326 = V_187 ;
if ( ( F_70 ( V_2 ) -> V_266 <= 6 || F_121 ( V_2 ) ) &&
V_99 -> V_272 > 1 )
return;
V_325 -> V_327 = F_70 ( V_2 ) -> V_266 >= 6 ;
for ( V_192 = 1 ; V_192 <= V_187 ; V_192 ++ ) {
struct V_279 * V_56 = & V_325 -> V_56 [ V_192 ] ;
F_135 ( V_2 , V_192 , V_56 ) ;
if ( V_192 > V_326 )
V_56 -> V_44 = false ;
else if ( ! F_106 ( V_192 , F_52 , V_56 ) )
V_326 = V_192 - 1 ;
if ( V_56 -> V_288 > F_52 -> V_278 ) {
if ( V_56 -> V_44 )
V_325 -> V_327 = false ;
V_56 -> V_288 = 0 ;
}
}
if ( F_138 ( V_2 ) && ! V_325 -> V_327 &&
F_139 ( V_4 ) ) {
for ( V_192 = 2 ; V_192 <= V_187 ; V_192 ++ ) {
struct V_279 * V_56 = & V_325 -> V_56 [ V_192 ] ;
V_56 -> V_44 = false ;
}
}
}
static int F_140 ( int V_328 , const struct V_313 * V_314 )
{
return V_328 + ( V_328 >= 2 && V_314 -> V_56 [ 4 ] . V_44 ) ;
}
static unsigned int F_141 ( struct V_1 * V_2 , int V_192 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
return 2 * V_192 ;
else
return V_4 -> V_56 . V_185 [ V_192 ] ;
}
static void F_142 ( struct V_1 * V_2 ,
const struct V_313 * V_325 ,
enum V_269 V_329 ,
struct V_330 * V_331 )
{
struct V_142 * V_142 ;
int V_192 , V_328 ;
V_331 -> V_332 = V_325 -> V_327 ;
V_331 -> V_329 = V_329 ;
for ( V_328 = 1 ; V_328 <= 3 ; V_328 ++ ) {
const struct V_279 * V_333 ;
V_192 = F_140 ( V_328 , V_325 ) ;
V_333 = & V_325 -> V_56 [ V_192 ] ;
V_331 -> V_328 [ V_328 - 1 ] =
( F_141 ( V_2 , V_192 ) << V_334 ) |
( V_333 -> V_258 << V_335 ) |
V_333 -> V_282 ;
if ( V_333 -> V_44 )
V_331 -> V_328 [ V_328 - 1 ] |= V_336 ;
if ( F_70 ( V_2 ) -> V_266 >= 8 )
V_331 -> V_328 [ V_328 - 1 ] |=
V_333 -> V_288 << V_337 ;
else
V_331 -> V_328 [ V_328 - 1 ] |=
V_333 -> V_288 << V_338 ;
if ( F_70 ( V_2 ) -> V_266 <= 6 && V_333 -> V_281 ) {
F_64 ( V_328 != 1 ) ;
V_331 -> V_339 [ V_328 - 1 ] = V_340 | V_333 -> V_281 ;
} else
V_331 -> V_339 [ V_328 - 1 ] = V_333 -> V_281 ;
}
F_75 (dev, intel_crtc) {
const struct V_248 * V_259 =
F_136 ( V_142 -> V_100 . V_102 ) ;
enum V_65 V_65 = V_142 -> V_65 ;
const struct V_279 * V_333 = & V_259 -> V_56 . V_317 . V_318 . V_56 [ 0 ] ;
if ( F_64 ( ! V_333 -> V_44 ) )
continue;
V_331 -> V_341 [ V_65 ] = V_259 -> V_56 . V_317 . V_318 . V_289 ;
V_331 -> V_342 [ V_65 ] =
( V_333 -> V_258 << V_343 ) |
( V_333 -> V_281 << V_344 ) |
V_333 -> V_282 ;
}
}
static struct V_313 * F_143 ( struct V_1 * V_2 ,
struct V_313 * V_345 ,
struct V_313 * V_346 )
{
int V_192 , V_187 = F_114 ( V_2 ) ;
int V_347 = 0 , V_348 = 0 ;
for ( V_192 = 1 ; V_192 <= V_187 ; V_192 ++ ) {
if ( V_345 -> V_56 [ V_192 ] . V_44 )
V_347 = V_192 ;
if ( V_346 -> V_56 [ V_192 ] . V_44 )
V_348 = V_192 ;
}
if ( V_347 == V_348 ) {
if ( V_346 -> V_327 && ! V_345 -> V_327 )
return V_346 ;
else
return V_345 ;
} else if ( V_347 > V_348 ) {
return V_345 ;
} else {
return V_346 ;
}
}
static unsigned int F_144 ( struct V_3 * V_4 ,
const struct V_330 * V_349 ,
const struct V_330 * V_350 )
{
unsigned int V_351 = 0 ;
enum V_65 V_65 ;
int V_328 ;
F_145 (dev_priv, pipe) {
if ( V_349 -> V_341 [ V_65 ] != V_350 -> V_341 [ V_65 ] ) {
V_351 |= F_146 ( V_65 ) ;
V_351 |= V_352 ;
}
if ( V_349 -> V_342 [ V_65 ] != V_350 -> V_342 [ V_65 ] ) {
V_351 |= F_147 ( V_65 ) ;
V_351 |= V_352 ;
}
}
if ( V_349 -> V_332 != V_350 -> V_332 ) {
V_351 |= V_353 ;
V_351 |= V_352 ;
}
if ( V_349 -> V_329 != V_350 -> V_329 ) {
V_351 |= V_354 ;
V_351 |= V_352 ;
}
if ( V_351 & V_352 )
return V_351 ;
for ( V_328 = 1 ; V_328 <= 3 ; V_328 ++ ) {
if ( V_349 -> V_328 [ V_328 - 1 ] != V_350 -> V_328 [ V_328 - 1 ] ||
V_349 -> V_339 [ V_328 - 1 ] != V_350 -> V_339 [ V_328 - 1 ] )
break;
}
for (; V_328 <= 3 ; V_328 ++ )
V_351 |= F_148 ( V_328 ) ;
return V_351 ;
}
static bool F_149 ( struct V_3 * V_4 ,
unsigned int V_351 )
{
struct V_330 * V_355 = & V_4 -> V_56 . V_356 ;
bool V_310 = false ;
if ( V_351 & F_148 ( 3 ) && V_355 -> V_328 [ 2 ] & V_336 ) {
V_355 -> V_328 [ 2 ] &= ~ V_336 ;
F_2 ( V_357 , V_355 -> V_328 [ 2 ] ) ;
V_310 = true ;
}
if ( V_351 & F_148 ( 2 ) && V_355 -> V_328 [ 1 ] & V_336 ) {
V_355 -> V_328 [ 1 ] &= ~ V_336 ;
F_2 ( V_358 , V_355 -> V_328 [ 1 ] ) ;
V_310 = true ;
}
if ( V_351 & F_148 ( 1 ) && V_355 -> V_328 [ 0 ] & V_336 ) {
V_355 -> V_328 [ 0 ] &= ~ V_336 ;
F_2 ( V_359 , V_355 -> V_328 [ 0 ] ) ;
V_310 = true ;
}
return V_310 ;
}
static void F_150 ( struct V_3 * V_4 ,
struct V_330 * V_331 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_330 * V_355 = & V_4 -> V_56 . V_356 ;
unsigned int V_351 ;
T_3 V_45 ;
V_351 = F_144 ( V_4 , V_355 , V_331 ) ;
if ( ! V_351 )
return;
F_149 ( V_4 , V_351 ) ;
if ( V_351 & F_147 ( V_73 ) )
F_2 ( V_360 , V_331 -> V_342 [ 0 ] ) ;
if ( V_351 & F_147 ( V_76 ) )
F_2 ( V_361 , V_331 -> V_342 [ 1 ] ) ;
if ( V_351 & F_147 ( V_77 ) )
F_2 ( V_362 , V_331 -> V_342 [ 2 ] ) ;
if ( V_351 & F_146 ( V_73 ) )
F_2 ( F_151 ( V_73 ) , V_331 -> V_341 [ 0 ] ) ;
if ( V_351 & F_146 ( V_76 ) )
F_2 ( F_151 ( V_76 ) , V_331 -> V_341 [ 1 ] ) ;
if ( V_351 & F_146 ( V_77 ) )
F_2 ( F_151 ( V_77 ) , V_331 -> V_341 [ 2 ] ) ;
if ( V_351 & V_354 ) {
if ( F_116 ( V_2 ) || F_117 ( V_2 ) ) {
V_45 = F_3 ( V_363 ) ;
if ( V_331 -> V_329 == V_322 )
V_45 &= ~ V_364 ;
else
V_45 |= V_364 ;
F_2 ( V_363 , V_45 ) ;
} else {
V_45 = F_3 ( V_365 ) ;
if ( V_331 -> V_329 == V_322 )
V_45 &= ~ V_366 ;
else
V_45 |= V_366 ;
F_2 ( V_365 , V_45 ) ;
}
}
if ( V_351 & V_353 ) {
V_45 = F_3 ( V_367 ) ;
if ( V_331 -> V_332 )
V_45 &= ~ V_368 ;
else
V_45 |= V_368 ;
F_2 ( V_367 , V_45 ) ;
}
if ( V_351 & F_148 ( 1 ) &&
V_355 -> V_339 [ 0 ] != V_331 -> V_339 [ 0 ] )
F_2 ( V_369 , V_331 -> V_339 [ 0 ] ) ;
if ( F_70 ( V_2 ) -> V_266 >= 7 ) {
if ( V_351 & F_148 ( 2 ) && V_355 -> V_339 [ 1 ] != V_331 -> V_339 [ 1 ] )
F_2 ( V_370 , V_331 -> V_339 [ 1 ] ) ;
if ( V_351 & F_148 ( 3 ) && V_355 -> V_339 [ 2 ] != V_331 -> V_339 [ 2 ] )
F_2 ( V_371 , V_331 -> V_339 [ 2 ] ) ;
}
if ( V_351 & F_148 ( 1 ) && V_355 -> V_328 [ 0 ] != V_331 -> V_328 [ 0 ] )
F_2 ( V_359 , V_331 -> V_328 [ 0 ] ) ;
if ( V_351 & F_148 ( 2 ) && V_355 -> V_328 [ 1 ] != V_331 -> V_328 [ 1 ] )
F_2 ( V_358 , V_331 -> V_328 [ 1 ] ) ;
if ( V_351 & F_148 ( 3 ) && V_355 -> V_328 [ 2 ] != V_331 -> V_328 [ 2 ] )
F_2 ( V_357 , V_331 -> V_328 [ 2 ] ) ;
V_4 -> V_56 . V_356 = * V_331 ;
}
static bool F_152 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_149 ( V_4 , V_352 ) ;
}
static int
F_153 ( const struct V_190 * V_66 )
{
switch ( V_66 -> V_100 . type ) {
case V_208 :
return 0 ;
case V_196 :
return V_372 ;
case V_209 :
return V_66 -> V_66 + 1 ;
default:
F_154 ( V_66 -> V_100 . type ) ;
return V_66 -> V_66 ;
}
}
static void
F_155 ( struct V_1 * V_2 ,
const struct V_248 * V_259 ,
const struct V_268 * V_99 ,
struct V_373 * V_374 )
{
struct V_92 * V_375 = V_259 -> V_100 . V_93 ;
struct V_92 * V_93 ;
unsigned int V_376 , V_377 ;
int V_378 ;
if ( ! V_259 -> V_100 . V_212 ) {
V_374 -> V_379 = 0 ;
V_374 -> V_380 = 0 ;
return;
}
if ( F_156 ( V_2 ) )
V_377 = V_381 ;
else
V_377 = V_382 ;
V_377 -= 4 ;
V_378 = 0 ;
F_43 (dev, crtc) {
if ( ! F_47 ( V_93 ) -> V_212 )
continue;
if ( V_93 == V_375 )
break;
V_378 ++ ;
}
V_376 = V_377 / V_99 -> V_272 ;
V_374 -> V_379 = V_378 * V_377 / V_99 -> V_272 ;
V_374 -> V_380 = V_374 -> V_379 + V_376 ;
}
static unsigned int F_157 ( const struct V_268 * V_99 )
{
if ( V_99 -> V_272 == 1 )
return 32 ;
return 8 ;
}
static void F_158 ( struct V_373 * V_383 , T_1 V_96 )
{
V_383 -> V_379 = V_96 & 0x3ff ;
V_383 -> V_380 = ( V_96 >> 16 ) & 0x3ff ;
if ( V_383 -> V_380 )
V_383 -> V_380 += 1 ;
}
void F_159 ( struct V_3 * V_4 ,
struct V_384 * V_385 )
{
enum V_65 V_65 ;
int V_66 ;
T_1 V_45 ;
memset ( V_385 , 0 , sizeof( * V_385 ) ) ;
F_145 (dev_priv, pipe) {
enum V_386 V_387 ;
V_387 = F_160 ( V_65 ) ;
if ( ! F_161 ( V_4 , V_387 ) )
continue;
F_162 (dev_priv, pipe, plane) {
V_45 = F_3 ( F_163 ( V_65 , V_66 ) ) ;
F_158 ( & V_385 -> V_66 [ V_65 ] [ V_66 ] ,
V_45 ) ;
}
V_45 = F_3 ( F_164 ( V_65 ) ) ;
F_158 ( & V_385 -> V_66 [ V_65 ] [ V_372 ] ,
V_45 ) ;
F_165 ( V_4 , V_387 ) ;
}
}
static unsigned int
F_166 ( const struct V_248 * V_259 ,
const struct V_315 * V_260 ,
int V_388 )
{
struct V_191 * V_389 = F_68 ( V_260 ) ;
struct V_390 * V_103 = V_260 -> V_103 ;
T_3 V_193 = 0 , V_391 = 0 ;
V_193 = F_94 ( & V_389 -> V_320 ) >> 16 ;
V_391 = F_134 ( & V_389 -> V_320 ) >> 16 ;
if ( F_167 ( V_260 -> V_392 ) )
F_168 ( V_193 , V_391 ) ;
if ( V_103 -> V_104 == V_393 ) {
if ( V_388 )
return V_193 * V_391 *
F_48 ( V_103 -> V_104 , 0 ) ;
else
return ( V_193 / 2 ) * ( V_391 / 2 ) *
F_48 ( V_103 -> V_104 , 1 ) ;
}
return V_193 * V_391 * F_48 ( V_103 -> V_104 , 0 ) ;
}
static unsigned int
F_169 ( const struct V_248 * V_259 )
{
struct V_142 * V_142 = F_47 ( V_259 -> V_100 . V_93 ) ;
struct V_1 * V_2 = V_142 -> V_100 . V_2 ;
const struct V_190 * V_190 ;
unsigned int V_394 = 0 ;
F_67 (dev, intel_crtc, intel_plane) {
const struct V_315 * V_260 = V_190 -> V_100 . V_102 ;
if ( V_260 -> V_103 == NULL )
continue;
if ( V_190 -> V_100 . type == V_196 )
continue;
V_394 += F_166 ( V_259 ,
V_260 ,
0 ) ;
if ( V_260 -> V_103 -> V_104 == V_393 )
V_394 += F_166 ( V_259 ,
V_260 ,
1 ) ;
}
return V_394 ;
}
static void
F_170 ( struct V_248 * V_259 ,
struct V_384 * V_385 )
{
struct V_92 * V_93 = V_259 -> V_100 . V_93 ;
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = F_57 ( V_2 ) ;
struct V_268 * V_99 = & V_4 -> V_56 . V_99 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_190 * V_190 ;
enum V_65 V_65 = V_142 -> V_65 ;
struct V_373 * V_374 = & V_385 -> V_65 [ V_65 ] ;
T_4 V_395 , V_379 , V_396 ;
T_4 V_397 [ V_398 ] ;
T_4 V_399 [ V_398 ] ;
unsigned int V_394 ;
F_155 ( V_2 , V_259 , V_99 , V_374 ) ;
V_395 = F_171 ( V_374 ) ;
if ( V_395 == 0 ) {
memset ( V_385 -> V_66 [ V_65 ] , 0 , sizeof( V_385 -> V_66 [ V_65 ] ) ) ;
memset ( & V_385 -> V_66 [ V_65 ] [ V_372 ] , 0 ,
sizeof( V_385 -> V_66 [ V_65 ] [ V_372 ] ) ) ;
return;
}
V_396 = F_157 ( V_99 ) ;
V_385 -> V_66 [ V_65 ] [ V_372 ] . V_379 = V_374 -> V_380 - V_396 ;
V_385 -> V_66 [ V_65 ] [ V_372 ] . V_380 = V_374 -> V_380 ;
V_395 -= V_396 ;
V_374 -> V_380 -= V_396 ;
F_67 (dev, intel_crtc, intel_plane) {
struct V_400 * V_66 = & V_190 -> V_100 ;
struct V_390 * V_103 = V_66 -> V_102 -> V_103 ;
int V_401 = F_153 ( V_190 ) ;
if ( ! F_68 ( V_66 -> V_102 ) -> V_195 )
continue;
if ( V_66 -> type == V_196 )
continue;
V_397 [ V_401 ] = 8 ;
V_395 -= V_397 [ V_401 ] ;
V_399 [ V_401 ] = ( V_103 -> V_104 == V_393 ) ? 8 : 0 ;
V_395 -= V_399 [ V_401 ] ;
}
V_394 = F_169 ( V_259 ) ;
V_379 = V_374 -> V_379 ;
F_67 (dev, intel_crtc, intel_plane) {
struct V_400 * V_66 = & V_190 -> V_100 ;
struct V_315 * V_260 = V_190 -> V_100 . V_102 ;
unsigned int V_402 , V_403 ;
T_4 V_404 , V_405 = 0 ;
int V_401 = F_153 ( V_190 ) ;
if ( ! F_68 ( V_260 ) -> V_195 )
continue;
if ( V_66 -> type == V_196 )
continue;
V_402 = F_166 ( V_259 , V_260 , 0 ) ;
V_404 = V_397 [ V_401 ] ;
V_404 += F_87 ( ( T_5 ) V_395 * V_402 ,
V_394 ) ;
V_385 -> V_66 [ V_65 ] [ V_401 ] . V_379 = V_379 ;
V_385 -> V_66 [ V_65 ] [ V_401 ] . V_380 = V_379 + V_404 ;
V_379 += V_404 ;
if ( V_260 -> V_103 -> V_104 == V_393 ) {
V_403 = F_166 ( V_259 ,
V_260 ,
1 ) ;
V_405 = V_399 [ V_401 ] ;
V_405 += F_87 ( ( T_5 ) V_395 * V_403 ,
V_394 ) ;
V_385 -> V_406 [ V_65 ] [ V_401 ] . V_379 = V_379 ;
V_385 -> V_406 [ V_65 ] [ V_401 ] . V_380 = V_379 + V_405 ;
V_379 += V_405 ;
}
}
}
static T_3 F_172 ( const struct V_248 * V_99 )
{
return V_99 -> V_100 . V_98 . V_105 ;
}
static T_3 F_173 ( T_3 V_181 , T_6 V_84 , T_3 V_41 )
{
T_3 V_407 , V_184 ;
if ( V_41 == 0 )
return V_257 ;
V_407 = V_41 * V_181 * V_84 / 512 ;
V_184 = F_41 ( V_407 , 1000 ) ;
return V_184 ;
}
static T_3 F_174 ( T_3 V_181 , T_3 V_182 ,
T_3 V_183 , T_6 V_84 ,
T_5 V_408 , T_3 V_41 )
{
T_3 V_184 ;
T_3 V_409 , V_410 ;
T_3 V_407 ;
if ( V_41 == 0 )
return V_257 ;
V_409 = V_183 * V_84 ;
if ( V_408 == V_411 ||
V_408 == V_412 ) {
V_409 *= 4 ;
V_410 = F_41 ( V_409 , 512 ) ;
V_410 /= 4 ;
} else {
V_410 = F_41 ( V_409 , 512 ) ;
}
V_407 = V_41 * V_181 ;
V_184 = F_41 ( V_407 , V_182 * 1000 ) *
V_410 ;
return V_184 ;
}
static bool F_175 ( const struct V_384 * V_413 ,
const struct V_142 * V_142 )
{
struct V_1 * V_2 = V_142 -> V_100 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_384 * V_414 = & V_4 -> V_56 . V_415 . V_385 ;
if ( memcmp ( V_413 -> V_65 , V_414 -> V_65 , sizeof( V_413 -> V_65 ) ) )
return true ;
return false ;
}
static bool F_176 ( const struct V_3 * V_4 ,
struct V_248 * V_259 ,
struct V_190 * V_190 ,
T_4 V_416 ,
int V_192 ,
T_4 * V_417 ,
T_6 * V_418 )
{
struct V_400 * V_66 = & V_190 -> V_100 ;
struct V_390 * V_103 = V_66 -> V_102 -> V_103 ;
struct V_191 * V_389 =
F_68 ( V_66 -> V_102 ) ;
T_3 V_41 = V_4 -> V_56 . V_311 [ V_192 ] ;
T_3 V_263 , V_264 ;
T_3 V_409 , V_410 ;
T_3 V_419 , V_420 ;
T_3 V_421 ;
T_6 V_84 ;
T_3 V_193 = 0 , V_391 = 0 ;
if ( V_41 == 0 || ! V_259 -> V_100 . V_212 || ! V_389 -> V_195 )
return false ;
V_193 = F_94 ( & V_389 -> V_320 ) >> 16 ;
V_391 = F_134 ( & V_389 -> V_320 ) >> 16 ;
if ( F_167 ( V_66 -> V_102 -> V_392 ) )
F_168 ( V_193 , V_391 ) ;
V_84 = F_48 ( V_103 -> V_104 , 0 ) ;
V_263 = F_173 ( F_172 ( V_259 ) ,
V_84 , V_41 ) ;
V_264 = F_174 ( F_172 ( V_259 ) ,
V_259 -> V_100 . V_98 . V_135 ,
V_193 ,
V_84 ,
V_103 -> V_422 [ 0 ] ,
V_41 ) ;
V_409 = V_193 * V_84 ;
V_410 = F_41 ( V_409 , 512 ) ;
if ( V_103 -> V_422 [ 0 ] == V_411 ||
V_103 -> V_422 [ 0 ] == V_412 ) {
T_3 V_423 = 4 ;
T_3 V_424 ;
if ( F_167 ( V_66 -> V_102 -> V_392 ) ) {
int V_84 = ( V_103 -> V_104 == V_393 ) ?
F_48 ( V_103 -> V_104 , 1 ) :
F_48 ( V_103 -> V_104 , 0 ) ;
switch ( V_84 ) {
case 1 :
V_423 = 16 ;
break;
case 2 :
V_423 = 8 ;
break;
case 8 :
F_89 ( 1 , L_47 ) ;
}
}
V_424 = V_410 * V_423 ;
V_421 = F_52 ( V_264 , V_424 ) ;
} else {
if ( ( V_416 / V_410 ) >= 1 )
V_421 = F_55 ( V_263 , V_264 ) ;
else
V_421 = V_263 ;
}
V_419 = V_421 + 1 ;
V_420 = F_41 ( V_421 , V_410 ) ;
if ( V_192 >= 1 && V_192 <= 7 ) {
if ( V_103 -> V_422 [ 0 ] == V_411 ||
V_103 -> V_422 [ 0 ] == V_412 )
V_420 += 4 ;
else
V_419 ++ ;
}
if ( V_419 >= V_416 || V_420 > 31 )
return false ;
* V_417 = V_419 ;
* V_418 = V_420 ;
return true ;
}
static void F_177 ( const struct V_3 * V_4 ,
struct V_384 * V_385 ,
struct V_248 * V_259 ,
int V_192 ,
struct V_425 * V_280 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_142 * V_142 = F_47 ( V_259 -> V_100 . V_93 ) ;
struct V_190 * V_190 ;
T_4 V_426 ;
enum V_65 V_65 = V_142 -> V_65 ;
F_67 (dev, intel_crtc, intel_plane) {
int V_42 = F_153 ( V_190 ) ;
V_426 = F_171 ( & V_385 -> V_66 [ V_65 ] [ V_42 ] ) ;
V_280 -> V_427 [ V_42 ] = F_176 ( V_4 ,
V_259 ,
V_190 ,
V_426 ,
V_192 ,
& V_280 -> V_428 [ V_42 ] ,
& V_280 -> V_429 [ V_42 ] ) ;
}
}
static T_3
F_178 ( struct V_248 * V_259 )
{
if ( ! V_259 -> V_100 . V_212 )
return 0 ;
if ( F_64 ( F_172 ( V_259 ) == 0 ) )
return 0 ;
return F_41 ( 8 * V_259 -> V_100 . V_98 . V_135 * 1000 ,
F_172 ( V_259 ) ) ;
}
static void F_179 ( struct V_248 * V_259 ,
struct V_425 * V_430 )
{
struct V_92 * V_93 = V_259 -> V_100 . V_93 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_190 * V_190 ;
if ( ! V_259 -> V_100 . V_212 )
return;
F_67 (crtc->dev, intel_crtc, intel_plane) {
int V_42 = F_153 ( V_190 ) ;
V_430 -> V_427 [ V_42 ] = false ;
}
}
static void F_180 ( struct V_248 * V_259 ,
struct V_384 * V_385 ,
struct V_431 * V_314 )
{
struct V_1 * V_2 = V_259 -> V_100 . V_93 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
int V_192 , V_187 = F_114 ( V_2 ) ;
for ( V_192 = 0 ; V_192 <= V_187 ; V_192 ++ ) {
F_177 ( V_4 , V_385 , V_259 ,
V_192 , & V_314 -> V_56 [ V_192 ] ) ;
}
V_314 -> V_289 = F_178 ( V_259 ) ;
F_179 ( V_259 , & V_314 -> V_430 ) ;
}
static void F_181 ( struct V_1 * V_2 ,
struct V_431 * V_432 ,
struct V_433 * V_333 ,
struct V_142 * V_142 )
{
int V_192 , V_187 = F_114 ( V_2 ) ;
enum V_65 V_65 = V_142 -> V_65 ;
T_3 V_434 ;
int V_42 ;
for ( V_192 = 0 ; V_192 <= V_187 ; V_192 ++ ) {
for ( V_42 = 0 ; V_42 < F_182 ( V_142 ) ; V_42 ++ ) {
V_434 = 0 ;
V_434 |= V_432 -> V_56 [ V_192 ] . V_429 [ V_42 ] <<
V_435 ;
V_434 |= V_432 -> V_56 [ V_192 ] . V_428 [ V_42 ] ;
if ( V_432 -> V_56 [ V_192 ] . V_427 [ V_42 ] )
V_434 |= V_436 ;
V_333 -> V_66 [ V_65 ] [ V_42 ] [ V_192 ] = V_434 ;
}
V_434 = 0 ;
V_434 |= V_432 -> V_56 [ V_192 ] . V_429 [ V_372 ] << V_435 ;
V_434 |= V_432 -> V_56 [ V_192 ] . V_428 [ V_372 ] ;
if ( V_432 -> V_56 [ V_192 ] . V_427 [ V_372 ] )
V_434 |= V_436 ;
V_333 -> V_66 [ V_65 ] [ V_372 ] [ V_192 ] = V_434 ;
}
for ( V_42 = 0 ; V_42 < F_182 ( V_142 ) ; V_42 ++ ) {
V_434 = 0 ;
V_434 |= V_432 -> V_430 . V_429 [ V_42 ] << V_435 ;
V_434 |= V_432 -> V_430 . V_428 [ V_42 ] ;
if ( V_432 -> V_430 . V_427 [ V_42 ] )
V_434 |= V_436 ;
V_333 -> V_437 [ V_65 ] [ V_42 ] = V_434 ;
}
V_434 = 0 ;
V_434 |= V_432 -> V_430 . V_429 [ V_372 ] << V_435 ;
V_434 |= V_432 -> V_430 . V_428 [ V_372 ] ;
if ( V_432 -> V_430 . V_427 [ V_372 ] )
V_434 |= V_436 ;
V_333 -> V_437 [ V_65 ] [ V_372 ] = V_434 ;
V_333 -> V_341 [ V_65 ] = V_432 -> V_289 ;
}
static void F_183 ( struct V_3 * V_4 ,
T_7 V_96 ,
const struct V_373 * V_383 )
{
if ( V_383 -> V_380 )
F_2 ( V_96 , ( V_383 -> V_380 - 1 ) << 16 | V_383 -> V_379 ) ;
else
F_2 ( V_96 , 0 ) ;
}
static void F_184 ( struct V_3 * V_4 ,
const struct V_433 * V_350 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_142 * V_93 ;
F_75 (dev, crtc) {
int V_42 , V_192 , V_187 = F_114 ( V_2 ) ;
enum V_65 V_65 = V_93 -> V_65 ;
if ( ! V_350 -> V_351 [ V_65 ] )
continue;
F_2 ( F_151 ( V_65 ) , V_350 -> V_341 [ V_65 ] ) ;
for ( V_192 = 0 ; V_192 <= V_187 ; V_192 ++ ) {
for ( V_42 = 0 ; V_42 < F_182 ( V_93 ) ; V_42 ++ )
F_2 ( F_185 ( V_65 , V_42 , V_192 ) ,
V_350 -> V_66 [ V_65 ] [ V_42 ] [ V_192 ] ) ;
F_2 ( F_186 ( V_65 , V_192 ) ,
V_350 -> V_66 [ V_65 ] [ V_372 ] [ V_192 ] ) ;
}
for ( V_42 = 0 ; V_42 < F_182 ( V_93 ) ; V_42 ++ )
F_2 ( F_187 ( V_65 , V_42 ) ,
V_350 -> V_437 [ V_65 ] [ V_42 ] ) ;
F_2 ( F_188 ( V_65 ) ,
V_350 -> V_437 [ V_65 ] [ V_372 ] ) ;
for ( V_42 = 0 ; V_42 < F_182 ( V_93 ) ; V_42 ++ ) {
F_183 ( V_4 ,
F_163 ( V_65 , V_42 ) ,
& V_350 -> V_385 . V_66 [ V_65 ] [ V_42 ] ) ;
F_183 ( V_4 ,
F_189 ( V_65 , V_42 ) ,
& V_350 -> V_385 . V_406 [ V_65 ] [ V_42 ] ) ;
}
F_183 ( V_4 , F_164 ( V_65 ) ,
& V_350 -> V_385 . V_66 [ V_65 ] [ V_372 ] ) ;
}
}
static void
F_190 ( struct V_3 * V_4 , enum V_65 V_65 , int V_438 )
{
int V_66 ;
F_11 ( L_48 , F_34 ( V_65 ) , V_438 ) ;
F_162 (dev_priv, pipe, plane) {
F_2 ( F_191 ( V_65 , V_66 ) ,
F_3 ( F_191 ( V_65 , V_66 ) ) ) ;
}
F_2 ( F_192 ( V_65 ) , F_3 ( F_192 ( V_65 ) ) ) ;
}
static bool
F_193 ( const struct V_384 * V_349 ,
const struct V_384 * V_350 ,
enum V_65 V_65 )
{
T_4 V_439 , V_440 ;
V_439 = F_171 ( & V_349 -> V_65 [ V_65 ] ) ;
V_440 = F_171 ( & V_350 -> V_65 [ V_65 ] ) ;
return V_439 != V_440 &&
V_350 -> V_65 [ V_65 ] . V_379 >= V_349 -> V_65 [ V_65 ] . V_379 &&
V_350 -> V_65 [ V_65 ] . V_380 <= V_349 -> V_65 [ V_65 ] . V_380 ;
}
static void F_194 ( struct V_3 * V_4 ,
struct V_433 * V_441 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_384 * V_414 , * V_413 ;
bool V_442 [ V_443 ] = {} ;
struct V_142 * V_93 ;
enum V_65 V_65 ;
V_413 = & V_441 -> V_385 ;
V_414 = & V_4 -> V_56 . V_415 . V_385 ;
F_75 (dev, crtc) {
if ( ! V_93 -> V_212 )
continue;
V_65 = V_93 -> V_65 ;
if ( ! F_193 ( V_414 , V_413 , V_65 ) )
continue;
F_190 ( V_4 , V_65 , 1 ) ;
F_195 ( V_2 , V_65 ) ;
V_442 [ V_65 ] = true ;
}
F_75 (dev, crtc) {
if ( ! V_93 -> V_212 )
continue;
V_65 = V_93 -> V_65 ;
if ( V_442 [ V_65 ] )
continue;
if ( F_171 ( & V_413 -> V_65 [ V_65 ] ) <
F_171 ( & V_414 -> V_65 [ V_65 ] ) ) {
F_190 ( V_4 , V_65 , 2 ) ;
F_195 ( V_2 , V_65 ) ;
V_442 [ V_65 ] = true ;
}
}
F_75 (dev, crtc) {
if ( ! V_93 -> V_212 )
continue;
V_65 = V_93 -> V_65 ;
if ( V_442 [ V_65 ] )
continue;
F_190 ( V_4 , V_65 , 3 ) ;
}
}
static bool F_196 ( struct V_92 * V_93 ,
struct V_384 * V_385 ,
struct V_431 * V_314 )
{
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_248 * V_259 = F_136 ( V_93 -> V_102 ) ;
F_170 ( V_259 , V_385 ) ;
F_180 ( V_259 , V_385 , V_314 ) ;
if ( ! memcmp ( & V_142 -> V_56 . V_212 . V_444 , V_314 , sizeof( * V_314 ) ) )
return false ;
V_142 -> V_56 . V_212 . V_444 = * V_314 ;
return true ;
}
static void F_197 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_433 * V_333 )
{
struct V_142 * V_142 ;
struct V_142 * V_445 = F_47 ( V_93 ) ;
if ( ! F_175 ( & V_333 -> V_385 , V_445 ) )
return;
F_75 (dev, intel_crtc) {
struct V_431 V_314 = {} ;
bool V_446 ;
if ( V_445 -> V_65 == V_142 -> V_65 )
continue;
if ( ! V_142 -> V_212 )
continue;
V_446 = F_196 ( & V_142 -> V_100 ,
& V_333 -> V_385 , & V_314 ) ;
F_64 ( ! V_446 ) ;
F_181 ( V_2 , & V_314 , V_333 , V_142 ) ;
V_333 -> V_351 [ V_142 -> V_65 ] = true ;
}
}
static void F_198 ( struct V_433 * V_447 , enum V_65 V_65 )
{
V_447 -> V_341 [ V_65 ] = 0 ;
memset ( V_447 -> V_66 [ V_65 ] , 0 ,
sizeof( T_3 ) * 8 * V_398 ) ;
memset ( V_447 -> V_437 [ V_65 ] ,
0 , sizeof( T_3 ) * V_398 ) ;
V_447 -> V_437 [ V_65 ] [ V_372 ] = 0 ;
memset ( & V_447 -> V_385 . V_65 [ V_65 ] , 0 , sizeof( struct V_373 ) ) ;
memset ( & V_447 -> V_385 . V_66 [ V_65 ] , 0 ,
sizeof( struct V_373 ) * V_398 ) ;
memset ( & V_447 -> V_385 . V_406 [ V_65 ] , 0 ,
sizeof( struct V_373 ) * V_398 ) ;
memset ( & V_447 -> V_385 . V_66 [ V_65 ] [ V_372 ] , 0 ,
sizeof( struct V_373 ) ) ;
}
static void F_199 ( struct V_92 * V_93 )
{
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_433 * V_331 = & V_4 -> V_56 . V_448 ;
struct V_248 * V_259 = F_136 ( V_93 -> V_102 ) ;
struct V_431 * V_314 = & V_259 -> V_56 . V_317 . V_444 ;
memset ( V_331 -> V_351 , 0 , sizeof( bool ) * V_443 ) ;
F_198 ( V_331 , V_142 -> V_65 ) ;
if ( ! F_196 ( V_93 , & V_331 -> V_385 , V_314 ) )
return;
F_181 ( V_2 , V_314 , V_331 , V_142 ) ;
V_331 -> V_351 [ V_142 -> V_65 ] = true ;
F_197 ( V_2 , V_93 , V_331 ) ;
F_184 ( V_4 , V_331 ) ;
F_194 ( V_4 , V_331 ) ;
V_4 -> V_56 . V_415 = * V_331 ;
}
static void F_200 ( struct V_1 * V_2 ,
struct V_268 * V_99 )
{
struct V_142 * V_93 ;
F_75 (dev, crtc) {
const struct V_313 * V_56 = & V_93 -> V_56 . V_212 . V_318 ;
if ( ! V_56 -> V_321 )
continue;
V_99 -> V_271 |= V_56 -> V_271 ;
V_99 -> V_319 |= V_56 -> V_319 ;
V_99 -> V_272 ++ ;
}
}
static void F_201 ( struct V_248 * V_259 )
{
struct V_92 * V_93 = V_259 -> V_100 . V_93 ;
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = F_57 ( V_2 ) ;
struct V_313 V_449 = {} , V_450 = {} , * V_451 ;
struct V_274 F_52 ;
struct V_268 V_99 = {} ;
struct V_330 V_331 = {} ;
enum V_269 V_329 ;
F_200 ( V_2 , & V_99 ) ;
F_104 ( V_2 , 1 , & V_99 , V_322 , & F_52 ) ;
F_137 ( V_2 , & V_99 , & F_52 , & V_449 ) ;
if ( F_70 ( V_2 ) -> V_266 >= 7 &&
V_99 . V_272 == 1 && V_99 . V_271 ) {
F_104 ( V_2 , 1 , & V_99 , V_273 , & F_52 ) ;
F_137 ( V_2 , & V_99 , & F_52 , & V_450 ) ;
V_451 = F_143 ( V_2 , & V_449 , & V_450 ) ;
} else {
V_451 = & V_449 ;
}
V_329 = ( V_451 == & V_449 ) ?
V_322 : V_273 ;
F_142 ( V_2 , V_451 , V_329 , & V_331 ) ;
F_150 ( V_4 , & V_331 ) ;
}
static void F_202 ( struct V_92 * V_93 )
{
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_248 * V_259 = F_136 ( V_93 -> V_102 ) ;
F_64 ( V_259 -> V_100 . V_212 != V_142 -> V_212 ) ;
if ( V_259 -> V_452 ) {
F_152 ( V_93 -> V_2 ) ;
F_195 ( V_93 -> V_2 , V_142 -> V_65 ) ;
}
V_142 -> V_56 . V_212 . V_318 = V_259 -> V_56 . V_317 . V_318 ;
F_201 ( V_259 ) ;
}
static void F_203 ( T_3 V_45 ,
struct V_431 * V_212 ,
bool V_453 ,
bool V_454 ,
int V_42 ,
int V_192 )
{
bool V_455 = ( V_45 & V_436 ) != 0 ;
if ( ! V_453 ) {
if ( ! V_454 ) {
V_212 -> V_56 [ V_192 ] . V_427 [ V_42 ] = V_455 ;
V_212 -> V_56 [ V_192 ] . V_428 [ V_42 ] =
V_45 & V_456 ;
V_212 -> V_56 [ V_192 ] . V_429 [ V_42 ] =
( V_45 >> V_435 ) &
V_457 ;
} else {
V_212 -> V_56 [ V_192 ] . V_427 [ V_372 ] = V_455 ;
V_212 -> V_56 [ V_192 ] . V_428 [ V_372 ] =
V_45 & V_456 ;
V_212 -> V_56 [ V_192 ] . V_429 [ V_372 ] =
( V_45 >> V_435 ) &
V_457 ;
}
} else {
if ( ! V_454 ) {
V_212 -> V_430 . V_427 [ V_42 ] = V_455 ;
V_212 -> V_430 . V_428 [ V_42 ] =
V_45 & V_456 ;
V_212 -> V_430 . V_429 [ V_42 ] =
( V_45 >> V_435 ) &
V_457 ;
} else {
V_212 -> V_430 . V_427 [ V_372 ] = V_455 ;
V_212 -> V_430 . V_428 [ V_372 ] =
V_45 & V_456 ;
V_212 -> V_430 . V_429 [ V_372 ] =
( V_45 >> V_435 ) &
V_457 ;
}
}
}
static void F_204 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_433 * V_356 = & V_4 -> V_56 . V_415 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_248 * V_259 = F_136 ( V_93 -> V_102 ) ;
struct V_431 * V_212 = & V_259 -> V_56 . V_317 . V_444 ;
enum V_65 V_65 = V_142 -> V_65 ;
int V_192 , V_42 , V_187 ;
T_3 V_434 ;
V_187 = F_114 ( V_2 ) ;
V_356 -> V_341 [ V_65 ] = F_3 ( F_151 ( V_65 ) ) ;
for ( V_192 = 0 ; V_192 <= V_187 ; V_192 ++ ) {
for ( V_42 = 0 ; V_42 < F_182 ( V_142 ) ; V_42 ++ )
V_356 -> V_66 [ V_65 ] [ V_42 ] [ V_192 ] =
F_3 ( F_185 ( V_65 , V_42 , V_192 ) ) ;
V_356 -> V_66 [ V_65 ] [ V_372 ] [ V_192 ] = F_3 ( F_186 ( V_65 , V_192 ) ) ;
}
for ( V_42 = 0 ; V_42 < F_182 ( V_142 ) ; V_42 ++ )
V_356 -> V_437 [ V_65 ] [ V_42 ] = F_3 ( F_187 ( V_65 , V_42 ) ) ;
V_356 -> V_437 [ V_65 ] [ V_372 ] = F_3 ( F_188 ( V_65 ) ) ;
if ( ! V_142 -> V_212 )
return;
V_356 -> V_351 [ V_65 ] = true ;
V_212 -> V_289 = V_356 -> V_341 [ V_65 ] ;
for ( V_192 = 0 ; V_192 <= V_187 ; V_192 ++ ) {
for ( V_42 = 0 ; V_42 < F_182 ( V_142 ) ; V_42 ++ ) {
V_434 = V_356 -> V_66 [ V_65 ] [ V_42 ] [ V_192 ] ;
F_203 ( V_434 , V_212 , false ,
false , V_42 , V_192 ) ;
}
V_434 = V_356 -> V_66 [ V_65 ] [ V_372 ] [ V_192 ] ;
F_203 ( V_434 , V_212 , false , true , V_42 , V_192 ) ;
}
for ( V_42 = 0 ; V_42 < F_182 ( V_142 ) ; V_42 ++ ) {
V_434 = V_356 -> V_437 [ V_65 ] [ V_42 ] ;
F_203 ( V_434 , V_212 , true , false , V_42 , 0 ) ;
}
V_434 = V_356 -> V_437 [ V_65 ] [ V_372 ] ;
F_203 ( V_434 , V_212 , true , true , V_42 , 0 ) ;
V_142 -> V_56 . V_212 . V_444 = * V_212 ;
}
void F_205 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_384 * V_385 = & V_4 -> V_56 . V_415 . V_385 ;
struct V_92 * V_93 ;
F_159 ( V_4 , V_385 ) ;
F_206 (crtc, &dev->mode_config.crtc_list, head)
F_204 ( V_93 ) ;
}
static void F_207 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_330 * V_356 = & V_4 -> V_56 . V_356 ;
struct V_142 * V_142 = F_47 ( V_93 ) ;
struct V_248 * V_259 = F_136 ( V_93 -> V_102 ) ;
struct V_313 * V_212 = & V_259 -> V_56 . V_317 . V_318 ;
enum V_65 V_65 = V_142 -> V_65 ;
static const T_7 V_458 [] = {
[ V_73 ] = V_360 ,
[ V_76 ] = V_361 ,
[ V_77 ] = V_362 ,
} ;
V_356 -> V_342 [ V_65 ] = F_3 ( V_458 [ V_65 ] ) ;
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
V_356 -> V_341 [ V_65 ] = F_3 ( F_151 ( V_65 ) ) ;
V_212 -> V_321 = V_142 -> V_212 ;
if ( V_212 -> V_321 ) {
T_1 V_14 = V_356 -> V_342 [ V_65 ] ;
V_212 -> V_56 [ 0 ] . V_44 = true ;
V_212 -> V_56 [ 0 ] . V_258 = ( V_14 & V_459 ) >> V_343 ;
V_212 -> V_56 [ 0 ] . V_281 = ( V_14 & V_460 ) >> V_344 ;
V_212 -> V_56 [ 0 ] . V_282 = V_14 & V_461 ;
V_212 -> V_289 = V_356 -> V_341 [ V_65 ] ;
} else {
int V_192 , V_187 = F_114 ( V_2 ) ;
for ( V_192 = 0 ; V_192 <= V_187 ; V_192 ++ )
V_212 -> V_56 [ V_192 ] . V_44 = true ;
}
V_142 -> V_56 . V_212 . V_318 = * V_212 ;
}
static void F_208 ( struct V_3 * V_4 ,
struct V_143 * V_56 )
{
enum V_65 V_65 ;
T_3 V_14 ;
F_145 (dev_priv, pipe) {
V_14 = F_3 ( F_58 ( V_65 ) ) ;
V_56 -> V_144 [ V_65 ] . V_101 =
( V_14 >> V_147 ) & ( V_213 | V_462 ) ;
V_56 -> V_144 [ V_65 ] . V_125 =
( V_14 >> V_145 ) & ( V_213 | V_462 ) ;
V_56 -> V_144 [ V_65 ] . V_146 [ 0 ] =
( V_14 >> F_59 ( 0 ) ) & ( V_213 | V_462 ) ;
V_56 -> V_144 [ V_65 ] . V_146 [ 1 ] =
( V_14 >> F_59 ( 1 ) ) & ( V_213 | V_462 ) ;
}
V_14 = F_3 ( V_108 ) ;
V_56 -> V_148 . V_66 = F_209 ( V_14 , V_110 ) ;
V_56 -> V_65 [ V_76 ] . V_125 = F_209 ( V_14 , V_149 ) ;
V_56 -> V_65 [ V_76 ] . V_101 = F_210 ( V_14 , V_150 ) ;
V_56 -> V_65 [ V_73 ] . V_101 = F_210 ( V_14 , V_151 ) ;
V_14 = F_3 ( V_152 ) ;
V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] = F_210 ( V_14 , V_153 ) ;
V_56 -> V_65 [ V_73 ] . V_125 = F_209 ( V_14 , V_154 ) ;
V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] = F_210 ( V_14 , V_155 ) ;
V_14 = F_3 ( V_61 ) ;
V_56 -> V_148 . V_125 = F_209 ( V_14 , V_114 ) ;
if ( F_22 ( V_4 ) ) {
V_14 = F_3 ( V_156 ) ;
V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] = F_210 ( V_14 , V_157 ) ;
V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] = F_210 ( V_14 , V_158 ) ;
V_14 = F_3 ( V_159 ) ;
V_56 -> V_65 [ V_77 ] . V_146 [ 1 ] = F_210 ( V_14 , V_160 ) ;
V_56 -> V_65 [ V_77 ] . V_146 [ 0 ] = F_210 ( V_14 , V_161 ) ;
V_14 = F_3 ( V_162 ) ;
V_56 -> V_65 [ V_77 ] . V_101 = F_210 ( V_14 , V_163 ) ;
V_56 -> V_65 [ V_77 ] . V_125 = F_209 ( V_14 , V_164 ) ;
V_14 = F_3 ( V_165 ) ;
V_56 -> V_148 . V_66 |= F_209 ( V_14 , V_166 ) << 9 ;
V_56 -> V_65 [ V_77 ] . V_146 [ 1 ] |= F_209 ( V_14 , V_167 ) << 8 ;
V_56 -> V_65 [ V_77 ] . V_146 [ 0 ] |= F_209 ( V_14 , V_168 ) << 8 ;
V_56 -> V_65 [ V_77 ] . V_101 |= F_209 ( V_14 , V_169 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] |= F_209 ( V_14 , V_170 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] |= F_209 ( V_14 , V_171 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_101 |= F_209 ( V_14 , V_172 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] |= F_209 ( V_14 , V_173 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] |= F_209 ( V_14 , V_174 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_101 |= F_209 ( V_14 , V_175 ) << 8 ;
} else {
V_14 = F_3 ( V_176 ) ;
V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] = F_210 ( V_14 , V_157 ) ;
V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] = F_210 ( V_14 , V_158 ) ;
V_14 = F_3 ( V_165 ) ;
V_56 -> V_148 . V_66 |= F_209 ( V_14 , V_166 ) << 9 ;
V_56 -> V_65 [ V_76 ] . V_146 [ 1 ] |= F_209 ( V_14 , V_170 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_146 [ 0 ] |= F_209 ( V_14 , V_171 ) << 8 ;
V_56 -> V_65 [ V_76 ] . V_101 |= F_209 ( V_14 , V_172 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_146 [ 1 ] |= F_209 ( V_14 , V_173 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_146 [ 0 ] |= F_209 ( V_14 , V_174 ) << 8 ;
V_56 -> V_65 [ V_73 ] . V_101 |= F_209 ( V_14 , V_175 ) << 8 ;
}
}
void F_211 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_57 ( V_2 ) ;
struct V_143 * V_56 = & V_4 -> V_56 . V_57 ;
struct V_190 * V_66 ;
enum V_65 V_65 ;
T_1 V_45 ;
F_208 ( V_4 , V_56 ) ;
F_212 (dev, plane) {
switch ( V_66 -> V_100 . type ) {
int V_146 ;
case V_196 :
V_66 -> V_56 . V_83 = 63 ;
break;
case V_208 :
V_66 -> V_56 . V_83 = F_32 ( V_2 , V_66 -> V_65 , 0 ) ;
break;
case V_209 :
V_146 = V_66 -> V_66 ;
V_66 -> V_56 . V_83 = F_32 ( V_2 , V_66 -> V_65 , V_146 + 1 ) ;
break;
}
}
V_56 -> V_58 = F_3 ( V_54 ) & V_55 ;
V_56 -> V_192 = V_186 ;
if ( F_22 ( V_4 ) ) {
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_45 = F_14 ( V_4 , V_52 ) ;
if ( V_45 & V_53 )
V_56 -> V_192 = V_188 ;
V_45 = F_14 ( V_4 , V_48 ) ;
V_45 |= V_51 ;
F_15 ( V_4 , V_48 , V_45 ) ;
if ( F_16 ( ( F_14 ( V_4 , V_48 ) &
V_51 ) == 0 , 3 ) ) {
F_11 ( L_49
L_50 ) ;
V_4 -> V_56 . V_187 = V_188 ;
} else {
V_45 = F_14 ( V_4 , V_48 ) ;
if ( ( V_45 & V_49 ) == 0 )
V_56 -> V_192 = V_189 ;
}
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
F_145 (dev_priv, pipe)
F_11 ( L_51 ,
F_34 ( V_65 ) , V_56 -> V_65 [ V_65 ] . V_101 , V_56 -> V_65 [ V_65 ] . V_125 ,
V_56 -> V_65 [ V_65 ] . V_146 [ 0 ] , V_56 -> V_65 [ V_65 ] . V_146 [ 1 ] ) ;
F_11 ( L_52 ,
V_56 -> V_148 . V_66 , V_56 -> V_148 . V_125 , V_56 -> V_192 , V_56 -> V_58 ) ;
}
void F_213 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_330 * V_356 = & V_4 -> V_56 . V_356 ;
struct V_92 * V_93 ;
F_43 (dev, crtc)
F_207 ( V_93 ) ;
V_356 -> V_328 [ 0 ] = F_3 ( V_359 ) ;
V_356 -> V_328 [ 1 ] = F_3 ( V_358 ) ;
V_356 -> V_328 [ 2 ] = F_3 ( V_357 ) ;
V_356 -> V_339 [ 0 ] = F_3 ( V_369 ) ;
if ( F_70 ( V_2 ) -> V_266 >= 7 ) {
V_356 -> V_339 [ 1 ] = F_3 ( V_370 ) ;
V_356 -> V_339 [ 2 ] = F_3 ( V_371 ) ;
}
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
V_356 -> V_329 = ( F_3 ( V_363 ) & V_364 ) ?
V_273 : V_322 ;
else if ( F_121 ( V_2 ) )
V_356 -> V_329 = ( F_3 ( V_365 ) & V_366 ) ?
V_273 : V_322 ;
V_356 -> V_332 =
! ( F_3 ( V_367 ) & V_368 ) ;
}
void F_214 ( struct V_92 * V_93 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
if ( V_4 -> V_123 . V_463 )
V_4 -> V_123 . V_463 ( V_93 ) ;
}
bool F_215 ( struct V_1 * V_2 , T_8 V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_464 ;
F_216 ( & V_465 ) ;
V_464 = F_7 ( V_466 ) ;
if ( V_464 & V_467 ) {
F_217 ( L_53 ) ;
return false ;
}
V_464 = ( V_468 << V_469 ) |
( V_45 << V_470 ) | V_471 ;
F_218 ( V_466 , V_464 ) ;
F_219 ( V_466 ) ;
V_464 |= V_467 ;
F_218 ( V_466 , V_464 ) ;
return true ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_472 ;
T_8 V_473 , V_474 , V_475 , V_476 ;
F_221 ( & V_465 ) ;
V_472 = F_3 ( V_477 ) ;
F_218 ( V_478 , F_3 ( V_478 ) | V_479 ) ;
F_218 ( V_480 , F_3 ( V_480 ) | V_481 ) ;
F_2 ( V_482 , 100000 ) ;
F_2 ( V_483 , 100000 ) ;
F_2 ( V_484 , 90000 ) ;
F_2 ( V_485 , 80000 ) ;
F_2 ( V_486 , 1 ) ;
V_473 = ( V_472 & V_487 ) >> V_488 ;
V_474 = ( V_472 & V_489 ) ;
V_475 = ( V_472 & V_490 ) >>
V_491 ;
V_476 = ( F_3 ( F_222 ( V_475 ) ) & V_492 ) >>
V_493 ;
V_4 -> V_34 . V_473 = V_473 ;
V_4 -> V_34 . V_475 = V_475 ;
V_4 -> V_34 . V_494 = V_475 ;
V_4 -> V_34 . V_495 = V_474 ;
V_4 -> V_34 . V_496 = V_475 ;
F_8 ( L_54 ,
V_473 , V_474 , V_475 ) ;
F_2 ( V_497 , V_498 | V_499 ) ;
F_2 ( V_500 , V_476 ) ;
F_23 ( V_500 ) ;
V_472 |= V_501 ;
F_2 ( V_477 , V_472 ) ;
if ( F_223 ( ( F_3 ( V_466 ) & V_467 ) == 0 , 10 ) )
F_17 ( L_55 ) ;
F_224 ( 1 ) ;
F_215 ( V_2 , V_475 ) ;
V_4 -> V_34 . V_502 = F_3 ( V_503 ) +
F_3 ( V_504 ) + F_3 ( V_505 ) ;
V_4 -> V_34 . V_506 = F_225 ( V_507 ) ;
V_4 -> V_34 . V_508 = F_3 ( V_509 ) ;
V_4 -> V_34 . V_510 = F_226 () ;
F_227 ( & V_465 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_464 ;
F_221 ( & V_465 ) ;
V_464 = F_7 ( V_466 ) ;
F_2 ( V_497 , F_3 ( V_497 ) & ~ V_499 ) ;
F_2 ( V_511 , V_512 ) ;
F_2 ( V_513 , F_3 ( V_513 ) & ~ V_514 ) ;
F_2 ( V_515 , V_514 ) ;
F_2 ( V_516 , F_3 ( V_516 ) | V_514 ) ;
F_215 ( V_2 , V_4 -> V_34 . V_475 ) ;
F_224 ( 1 ) ;
V_464 |= V_467 ;
F_2 ( V_466 , V_464 ) ;
F_224 ( 1 ) ;
F_227 ( & V_465 ) ;
}
static T_1 F_229 ( struct V_3 * V_4 , T_8 V_45 )
{
T_1 V_517 ;
if ( F_113 ( V_4 -> V_2 ) ) {
V_517 = ( V_4 -> V_46 . V_518 ) << 23 ;
if ( V_45 <= V_4 -> V_46 . V_519 )
V_517 |= ( V_4 -> V_46 . V_519 ) << 14 ;
} else {
V_517 = V_4 -> V_46 . V_518 << 24 ;
if ( V_45 <= V_4 -> V_46 . V_519 )
V_517 |= V_4 -> V_46 . V_519 << 16 ;
}
return V_517 ;
}
static void F_230 ( struct V_3 * V_4 , T_8 V_45 )
{
int V_520 ;
T_1 V_521 = 0 , V_522 = 0 ;
T_1 V_523 = 0 , V_524 = 0 ;
V_520 = V_4 -> V_46 . V_525 ;
switch ( V_4 -> V_46 . V_525 ) {
case V_526 :
if ( V_45 > V_4 -> V_46 . V_527 + 1 && V_45 > V_4 -> V_46 . V_528 )
V_520 = V_529 ;
break;
case V_529 :
if ( V_45 <= V_4 -> V_46 . V_527 && V_45 < V_4 -> V_46 . V_528 )
V_520 = V_526 ;
else if ( V_45 >= V_4 -> V_46 . V_530 && V_45 > V_4 -> V_46 . V_528 )
V_520 = V_531 ;
break;
case V_531 :
if ( V_45 < ( V_4 -> V_46 . V_532 + V_4 -> V_46 . V_530 ) > > 1 && V_45 < V_4 -> V_46 . V_528 )
V_520 = V_529 ;
break;
}
if ( V_45 <= V_4 -> V_46 . V_519 )
V_520 = V_526 ;
if ( V_45 >= V_4 -> V_46 . V_518 )
V_520 = V_531 ;
if ( V_520 == V_4 -> V_46 . V_525 )
return;
switch ( V_520 ) {
case V_526 :
V_523 = 16000 ;
V_521 = 95 ;
V_524 = 32000 ;
V_522 = 85 ;
break;
case V_529 :
V_523 = 13000 ;
V_521 = 90 ;
V_524 = 32000 ;
V_522 = 75 ;
break;
case V_531 :
V_523 = 10000 ;
V_521 = 85 ;
V_524 = 32000 ;
V_522 = 60 ;
break;
}
F_2 ( V_533 ,
F_231 ( V_4 , V_523 ) ) ;
F_2 ( V_534 ,
F_231 ( V_4 , ( V_523 * V_521 / 100 ) ) ) ;
F_2 ( V_535 ,
F_231 ( V_4 , V_524 ) ) ;
F_2 ( V_536 ,
F_231 ( V_4 , ( V_524 * V_522 / 100 ) ) ) ;
F_2 ( V_537 ,
V_538 |
V_539 |
V_540 |
V_541 |
V_542 |
V_543 ) ;
V_4 -> V_46 . V_525 = V_520 ;
V_4 -> V_46 . V_544 = V_521 ;
V_4 -> V_46 . V_545 = V_522 ;
V_4 -> V_46 . V_546 = 0 ;
}
static T_1 F_232 ( struct V_3 * V_4 , T_8 V_45 )
{
T_1 V_547 = 0 ;
if ( V_45 > V_4 -> V_46 . V_519 )
V_547 |= V_548 | V_549 | V_550 ;
if ( V_45 < V_4 -> V_46 . V_518 )
V_547 |= V_551 | V_552 ;
V_547 &= V_4 -> V_553 ;
return F_233 ( V_4 , ~ V_547 ) ;
}
static void F_234 ( struct V_1 * V_2 , T_8 V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_4 ( V_2 , 0 , V_554 ) )
return;
F_64 ( ! F_235 ( & V_4 -> V_46 . V_47 ) ) ;
F_64 ( V_45 > V_4 -> V_46 . V_555 ) ;
F_64 ( V_45 < V_4 -> V_46 . V_556 ) ;
if ( V_45 != V_4 -> V_46 . V_528 ) {
F_230 ( V_4 , V_45 ) ;
if ( F_113 ( V_2 ) )
F_2 ( V_557 ,
F_236 ( V_45 ) ) ;
else if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
F_2 ( V_557 ,
F_237 ( V_45 ) ) ;
else
F_2 ( V_557 ,
F_238 ( V_45 ) |
F_239 ( 0 ) |
V_558 ) ;
}
F_2 ( V_559 , F_229 ( V_4 , V_45 ) ) ;
F_2 ( V_560 , F_232 ( V_4 , V_45 ) ) ;
F_23 ( V_557 ) ;
V_4 -> V_46 . V_528 = V_45 ;
F_240 ( F_241 ( V_4 , V_45 ) ) ;
}
static void F_242 ( struct V_1 * V_2 , T_8 V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_64 ( ! F_235 ( & V_4 -> V_46 . V_47 ) ) ;
F_64 ( V_45 > V_4 -> V_46 . V_555 ) ;
F_64 ( V_45 < V_4 -> V_46 . V_556 ) ;
if ( F_243 ( F_22 ( V_2 ) && ( V_45 & 1 ) ,
L_56 ) )
V_45 &= ~ 1 ;
F_2 ( V_560 , F_232 ( V_4 , V_45 ) ) ;
if ( V_45 != V_4 -> V_46 . V_528 ) {
F_15 ( V_4 , V_561 , V_45 ) ;
if ( ! F_22 ( V_4 ) )
F_230 ( V_4 , V_45 ) ;
}
V_4 -> V_46 . V_528 = V_45 ;
F_240 ( F_241 ( V_4 , V_45 ) ) ;
}
static void F_244 ( struct V_3 * V_4 )
{
T_1 V_45 = V_4 -> V_46 . V_562 ;
if ( V_4 -> V_46 . V_528 <= V_45 )
return;
F_245 ( V_4 , V_563 ) ;
F_242 ( V_4 -> V_2 , V_45 ) ;
F_246 ( V_4 , V_563 ) ;
}
void F_247 ( struct V_3 * V_4 )
{
F_13 ( & V_4 -> V_46 . V_47 ) ;
if ( V_4 -> V_46 . V_94 ) {
if ( V_4 -> V_553 & ( V_548 | V_551 ) )
F_248 ( V_4 ) ;
F_2 ( V_560 ,
F_232 ( V_4 , V_4 -> V_46 . V_528 ) ) ;
}
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
void F_249 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
if ( V_4 -> V_46 . V_94 ) {
if ( F_21 ( V_2 ) || F_22 ( V_2 ) )
F_244 ( V_4 ) ;
else
F_234 ( V_4 -> V_2 , V_4 -> V_46 . V_562 ) ;
V_4 -> V_46 . V_546 = 0 ;
F_2 ( V_560 , 0xffffffff ) ;
}
F_18 ( & V_4 -> V_46 . V_47 ) ;
F_250 ( & V_4 -> V_46 . V_564 ) ;
while ( ! F_251 ( & V_4 -> V_46 . V_565 ) )
F_252 ( V_4 -> V_46 . V_565 . V_566 ) ;
F_253 ( & V_4 -> V_46 . V_564 ) ;
}
void F_254 ( struct V_3 * V_4 ,
struct V_567 * V_46 ,
unsigned long V_568 )
{
if ( ! ( V_4 -> V_569 . V_570 &&
V_4 -> V_46 . V_94 &&
V_4 -> V_46 . V_528 < V_4 -> V_46 . V_518 ) )
return;
if ( V_46 && F_255 ( V_507 , V_568 + V_571 ) )
V_46 = NULL ;
F_250 ( & V_4 -> V_46 . V_564 ) ;
if ( V_46 == NULL || F_251 ( & V_46 -> V_572 ) ) {
F_221 ( & V_4 -> V_573 ) ;
if ( V_4 -> V_46 . V_574 ) {
V_4 -> V_46 . V_575 = true ;
F_256 ( V_4 -> V_576 , & V_4 -> V_46 . V_577 ) ;
}
F_227 ( & V_4 -> V_573 ) ;
if ( V_46 != NULL ) {
F_257 ( & V_46 -> V_572 , & V_4 -> V_46 . V_565 ) ;
V_46 -> V_578 ++ ;
} else
V_4 -> V_46 . V_578 ++ ;
}
F_253 ( & V_4 -> V_46 . V_564 ) ;
}
void F_258 ( struct V_1 * V_2 , T_8 V_45 )
{
if ( F_21 ( V_2 ) || F_22 ( V_2 ) )
F_242 ( V_2 , V_45 ) ;
else
F_234 ( V_2 , V_45 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_579 , 0 ) ;
F_2 ( V_580 , 0 ) ;
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_579 , 0 ) ;
F_2 ( V_557 , 1 << 31 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_579 , 0 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_245 ( V_4 , V_581 ) ;
F_2 ( V_579 , 0 ) ;
F_246 ( V_4 , V_581 ) ;
}
static void F_263 ( struct V_1 * V_2 , T_1 V_582 )
{
if ( F_21 ( V_2 ) || F_22 ( V_2 ) ) {
if ( V_582 & ( V_583 | F_264 ( 1 ) ) )
V_582 = V_584 ;
else
V_582 = 0 ;
}
if ( F_265 ( V_2 ) )
F_11 ( L_57 ,
F_266 ( V_582 & V_584 ) ,
F_266 ( V_582 & V_585 ) ,
F_266 ( V_582 & V_586 ) ) ;
else
F_11 ( L_58 ,
F_266 ( V_582 & V_584 ) ) ;
}
static bool F_267 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_587 = true ;
unsigned long V_588 ;
if ( ! ( F_3 ( V_589 ) & V_590 ) ) {
F_11 ( L_59 ) ;
V_587 = false ;
}
V_588 = F_3 ( V_591 ) & V_592 ;
if ( ! ( ( V_588 >= V_4 -> V_593 . V_594 ) &&
( V_588 + V_595 <= V_4 -> V_593 . V_594 +
V_4 -> V_593 . V_596 ) ) ) {
F_11 ( L_60 ) ;
V_587 = false ;
}
if ( ! ( ( ( F_3 ( V_597 ) & V_598 ) > 1 ) &&
( ( F_3 ( V_599 ) & V_598 ) > 1 ) &&
( ( F_3 ( V_600 ) & V_598 ) > 1 ) &&
( ( F_3 ( V_601 ) & V_598 ) > 1 ) ) ) {
F_11 ( L_61 ) ;
V_587 = false ;
}
if ( ! ( F_3 ( V_579 ) & ( V_584 |
V_602 ) ) &&
( ( F_3 ( V_579 ) & V_602 ) ||
! ( F_3 ( V_603 ) & V_604 ) ) ) {
F_11 ( L_62 ) ;
V_587 = false ;
}
return V_587 ;
}
int F_268 ( const struct V_1 * V_2 , int V_587 )
{
if ( F_70 ( V_2 ) -> V_266 < 6 )
return 0 ;
if ( ! V_587 )
return 0 ;
if ( F_156 ( V_2 ) && ! F_267 ( V_2 ) ) {
F_269 ( L_63 ) ;
return 0 ;
}
if ( V_587 >= 0 ) {
int V_547 ;
if ( F_265 ( V_2 ) )
V_547 = V_605 | V_606 |
V_607 ;
else
V_547 = V_605 ;
if ( ( V_587 & V_547 ) != V_587 )
F_11 ( L_64 ,
V_587 & V_547 , V_587 , V_547 ) ;
return V_587 & V_547 ;
}
if ( F_121 ( V_2 ) )
return ( V_605 | V_606 ) ;
return V_605 ;
}
int F_270 ( const struct V_1 * V_2 )
{
return V_608 . V_587 ;
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_609 ;
T_1 V_610 = 0 ;
int V_184 ;
V_4 -> V_46 . V_528 = 0 ;
if ( F_156 ( V_2 ) ) {
V_609 = F_3 ( V_611 ) ;
V_4 -> V_46 . V_530 = ( V_609 >> 16 ) & 0xff ;
V_4 -> V_46 . V_532 = ( V_609 >> 8 ) & 0xff ;
V_4 -> V_46 . V_556 = ( V_609 >> 0 ) & 0xff ;
} else {
V_609 = F_3 ( V_612 ) ;
V_4 -> V_46 . V_530 = ( V_609 >> 0 ) & 0xff ;
V_4 -> V_46 . V_532 = ( V_609 >> 8 ) & 0xff ;
V_4 -> V_46 . V_556 = ( V_609 >> 16 ) & 0xff ;
}
V_4 -> V_46 . V_555 = V_4 -> V_46 . V_530 ;
V_4 -> V_46 . V_527 = V_4 -> V_46 . V_532 ;
if ( F_116 ( V_2 ) || F_117 ( V_2 ) ||
F_272 ( V_2 ) || F_273 ( V_2 ) ) {
V_184 = F_115 ( V_4 ,
V_613 ,
& V_610 ) ;
if ( 0 == V_184 )
V_4 -> V_46 . V_527 =
F_274 ( T_8 ,
( ( V_610 >> 8 ) & 0xff ) ,
V_4 -> V_46 . V_556 ,
V_4 -> V_46 . V_555 ) ;
}
if ( F_272 ( V_2 ) || F_273 ( V_2 ) ) {
V_4 -> V_46 . V_530 *= V_614 ;
V_4 -> V_46 . V_532 *= V_614 ;
V_4 -> V_46 . V_556 *= V_614 ;
V_4 -> V_46 . V_555 *= V_614 ;
V_4 -> V_46 . V_527 *= V_614 ;
}
V_4 -> V_46 . V_562 = V_4 -> V_46 . V_556 ;
if ( V_4 -> V_46 . V_518 == 0 )
V_4 -> V_46 . V_518 = V_4 -> V_46 . V_555 ;
if ( V_4 -> V_46 . V_519 == 0 ) {
if ( F_116 ( V_2 ) || F_117 ( V_2 ) )
V_4 -> V_46 . V_519 =
F_124 ( int , V_4 -> V_46 . V_527 ,
F_275 ( V_4 , 450 ) ) ;
else
V_4 -> V_46 . V_519 =
V_4 -> V_46 . V_556 ;
}
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_245 ( V_4 , V_581 ) ;
F_271 ( V_2 ) ;
if ( F_4 ( V_2 , 0 , V_554 ) ) {
F_246 ( V_4 , V_581 ) ;
return;
}
F_2 ( V_615 ,
F_236 ( V_4 -> V_46 . V_532 ) ) ;
F_2 ( V_616 ,
F_231 ( V_4 , 1000000 ) ) ;
F_2 ( V_617 , 0xa ) ;
V_4 -> V_46 . V_525 = V_531 ;
F_234 ( V_4 -> V_2 , V_4 -> V_46 . V_519 ) ;
F_246 ( V_4 , V_581 ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_618 * V_619 ;
T_3 V_620 = 0 ;
int V_621 ;
F_2 ( V_603 , 0 ) ;
F_245 ( V_4 , V_581 ) ;
F_2 ( V_579 , 0 ) ;
if ( F_272 ( V_2 ) )
F_2 ( V_622 , 108 << 16 ) ;
else
F_2 ( V_622 , 54 << 16 ) ;
F_2 ( V_623 , 125000 ) ;
F_2 ( V_624 , 25 ) ;
F_278 (ring, dev_priv, unused)
F_2 ( F_279 ( V_619 -> V_625 ) , 10 ) ;
if ( F_280 ( V_2 ) )
F_2 ( V_626 , 0xA ) ;
F_2 ( V_627 , 0 ) ;
F_2 ( V_628 , 25 ) ;
F_2 ( V_629 , 25 ) ;
if ( F_270 ( V_2 ) & V_605 )
V_620 = V_584 ;
F_269 ( L_65 , F_266 ( V_620 & V_584 ) ) ;
if ( F_281 ( V_2 , 0 , V_630 ) ||
F_4 ( V_2 , 0 , V_554 ) ) {
F_2 ( V_631 , 625 ) ;
F_2 ( V_579 , V_602 |
V_583 |
V_620 ) ;
} else {
F_2 ( V_631 , 37500 ) ;
F_2 ( V_579 , V_602 |
F_264 ( 1 ) |
V_620 ) ;
}
if ( F_282 ( V_2 ) )
F_2 ( V_580 , 0 ) ;
else
F_2 ( V_580 , ( V_620 & V_584 ) ?
( V_632 | V_633 ) : 0 ) ;
F_246 ( V_4 , V_581 ) ;
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_618 * V_619 ;
T_3 V_620 = 0 ;
int V_621 ;
F_2 ( V_603 , 0 ) ;
F_245 ( V_4 , V_581 ) ;
F_2 ( V_579 , 0 ) ;
F_271 ( V_2 ) ;
F_2 ( V_622 , 40 << 16 ) ;
F_2 ( V_623 , 125000 ) ;
F_2 ( V_624 , 25 ) ;
F_278 (ring, dev_priv, unused)
F_2 ( F_279 ( V_619 -> V_625 ) , 10 ) ;
F_2 ( V_627 , 0 ) ;
if ( F_117 ( V_2 ) )
F_2 ( V_631 , 625 ) ;
else
F_2 ( V_631 , 50000 ) ;
if ( F_270 ( V_2 ) & V_605 )
V_620 = V_584 ;
F_263 ( V_2 , V_620 ) ;
if ( F_117 ( V_2 ) )
F_2 ( V_579 , V_602 |
V_583 |
V_620 ) ;
else
F_2 ( V_579 , V_602 |
F_264 ( 1 ) |
V_620 ) ;
F_2 ( V_557 ,
F_237 ( V_4 -> V_46 . V_532 ) ) ;
F_2 ( V_615 ,
F_237 ( V_4 -> V_46 . V_532 ) ) ;
F_2 ( V_616 , 100000000 / 128 ) ;
F_2 ( V_559 ,
V_4 -> V_46 . V_518 << 24 |
V_4 -> V_46 . V_519 << 16 ) ;
F_2 ( V_534 , 7600000 / 128 ) ;
F_2 ( V_536 , 31300000 / 128 ) ;
F_2 ( V_533 , 66000 ) ;
F_2 ( V_535 , 350000 ) ;
F_2 ( V_617 , 10 ) ;
F_2 ( V_537 ,
V_538 |
V_539 |
V_540 |
V_541 |
V_542 |
V_543 ) ;
V_4 -> V_46 . V_525 = V_531 ;
F_234 ( V_4 -> V_2 , V_4 -> V_46 . V_562 ) ;
F_246 ( V_4 , V_581 ) ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_618 * V_619 ;
T_1 V_634 , V_635 = 0 , V_620 = 0 ;
T_1 V_636 ;
int V_637 ;
int V_42 , V_184 ;
F_64 ( ! F_235 ( & V_4 -> V_46 . V_47 ) ) ;
F_2 ( V_603 , 0 ) ;
if ( ( V_636 = F_3 ( V_638 ) ) ) {
F_17 ( L_66 , V_636 ) ;
F_2 ( V_638 , V_636 ) ;
}
F_245 ( V_4 , V_581 ) ;
F_271 ( V_2 ) ;
F_2 ( V_579 , 0 ) ;
F_2 ( V_639 , 1000 << 16 ) ;
F_2 ( V_622 , 40 << 16 | 30 ) ;
F_2 ( V_640 , 30 ) ;
F_2 ( V_623 , 125000 ) ;
F_2 ( V_624 , 25 ) ;
F_278 (ring, dev_priv, i)
F_2 ( F_279 ( V_619 -> V_625 ) , 10 ) ;
F_2 ( V_627 , 0 ) ;
F_2 ( V_641 , 1000 ) ;
if ( F_121 ( V_2 ) )
F_2 ( V_631 , 125000 ) ;
else
F_2 ( V_631 , 50000 ) ;
F_2 ( V_642 , 150000 ) ;
F_2 ( V_643 , 64000 ) ;
V_637 = F_270 ( V_4 -> V_2 ) ;
if ( V_637 & V_605 )
V_620 |= V_584 ;
if ( ! F_116 ( V_2 ) ) {
if ( V_637 & V_606 )
V_620 |= V_585 ;
if ( V_637 & V_607 )
V_620 |= V_586 ;
}
F_263 ( V_2 , V_620 ) ;
F_2 ( V_579 ,
V_620 |
F_264 ( 1 ) |
V_602 ) ;
F_2 ( V_616 , 50000 ) ;
F_2 ( V_617 , 10 ) ;
V_184 = F_285 ( V_4 , V_644 , 0 ) ;
if ( V_184 )
F_8 ( L_67 ) ;
V_184 = F_115 ( V_4 , V_645 , & V_635 ) ;
if ( ! V_184 && ( V_635 & ( 1 << 31 ) ) ) {
F_8 ( L_68 ,
( V_4 -> V_46 . V_518 & 0xff ) * 50 ,
( V_635 & 0xff ) * 50 ) ;
V_4 -> V_46 . V_555 = V_635 & 0xff ;
}
V_4 -> V_46 . V_525 = V_531 ;
F_234 ( V_4 -> V_2 , V_4 -> V_46 . V_562 ) ;
V_634 = 0 ;
V_184 = F_115 ( V_4 , V_646 , & V_634 ) ;
if ( F_127 ( V_2 ) && V_184 ) {
F_8 ( L_69 ) ;
} else if ( F_127 ( V_2 ) && ( F_286 ( V_634 & 0xff ) < 450 ) ) {
F_8 ( L_70 ,
F_286 ( V_634 & 0xff ) , 450 ) ;
V_634 &= 0xffff00 ;
V_634 |= F_287 ( 450 ) ;
V_184 = F_285 ( V_4 , V_647 , V_634 ) ;
if ( V_184 )
F_17 ( L_71 ) ;
}
F_246 ( V_4 , V_581 ) ;
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_556 = 15 ;
unsigned int V_648 ;
unsigned int V_649 , V_650 ;
unsigned int V_651 , V_652 ;
int V_653 = 180 ;
struct V_654 * V_655 ;
F_64 ( ! F_235 ( & V_4 -> V_46 . V_47 ) ) ;
V_655 = F_289 ( 0 ) ;
if ( V_655 ) {
V_649 = V_655 -> V_656 . V_555 ;
F_290 ( V_655 ) ;
} else {
V_649 = V_657 ;
}
V_649 /= 1000 ;
V_650 = F_3 ( V_658 ) & 0xf ;
V_650 = F_291 ( V_650 , 8 , 3 ) ;
if ( F_272 ( V_2 ) || F_273 ( V_2 ) ) {
V_652 = V_4 -> V_46 . V_556 / V_614 ;
V_651 = V_4 -> V_46 . V_555 / V_614 ;
} else {
V_652 = V_4 -> V_46 . V_556 ;
V_651 = V_4 -> V_46 . V_555 ;
}
for ( V_648 = V_651 ; V_648 >= V_652 ; V_648 -- ) {
int V_659 = V_651 - V_648 ;
unsigned int V_660 = 0 , V_661 = 0 ;
if ( F_272 ( V_2 ) || F_273 ( V_2 ) ) {
V_661 = V_648 ;
} else if ( F_70 ( V_2 ) -> V_266 >= 8 ) {
V_661 = F_52 ( V_650 , V_648 ) ;
} else if ( F_116 ( V_2 ) ) {
V_661 = F_291 ( V_648 , 5 , 4 ) ;
V_661 = F_52 ( V_650 , V_661 ) ;
} else {
if ( V_648 < V_556 )
V_660 = 800 ;
else
V_660 = V_649 - ( ( V_659 * V_653 ) / 2 ) ;
V_660 = F_109 ( V_660 , 100 ) ;
}
F_285 ( V_4 ,
V_644 ,
V_660 << V_662 |
V_661 << V_663 |
V_648 ) ;
}
}
void F_292 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_293 ( V_2 ) )
return;
F_13 ( & V_4 -> V_46 . V_47 ) ;
F_288 ( V_2 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
static int F_294 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_45 , V_664 ;
V_45 = F_14 ( V_4 , V_665 ) ;
switch ( F_70 ( V_2 ) -> V_666 ) {
case 8 :
V_664 = ( V_45 >> V_667 ) ;
break;
case 12 :
V_664 = ( V_45 >> V_668 ) ;
break;
case 16 :
default:
V_664 = ( V_45 >> V_669 ) ;
break;
}
V_664 = ( V_664 & V_670 ) ;
return V_664 ;
}
static int F_295 ( struct V_3 * V_4 )
{
T_1 V_45 , V_671 ;
V_45 = F_14 ( V_4 , V_672 ) ;
V_671 = ( V_45 >> V_673 ) & V_674 ;
return V_671 ;
}
static int F_296 ( struct V_3 * V_4 )
{
T_1 V_45 , V_675 ;
V_45 = F_14 ( V_4 , V_665 ) ;
V_675 = ( V_45 & V_670 ) ;
return V_675 ;
}
static int F_297 ( struct V_3 * V_4 )
{
T_1 V_45 , V_675 ;
V_45 = F_298 ( V_4 , V_676 ) ;
V_675 = ( V_45 & V_677 ) >> V_678 ;
return V_675 ;
}
static int F_299 ( struct V_3 * V_4 )
{
T_1 V_45 , V_664 ;
V_45 = F_298 ( V_4 , V_676 ) ;
V_664 = ( V_45 & V_679 ) >> V_680 ;
V_664 = F_65 ( T_1 , V_664 , 0xea ) ;
return V_664 ;
}
static int F_300 ( struct V_3 * V_4 )
{
T_1 V_45 , V_671 ;
V_45 = F_298 ( V_4 , V_681 ) ;
V_671 = ( V_45 & V_682 ) >> V_683 ;
V_45 = F_298 ( V_4 , V_684 ) ;
V_671 |= ( V_45 & V_685 ) << 5 ;
return V_671 ;
}
static int F_301 ( struct V_3 * V_4 )
{
T_1 V_45 ;
V_45 = F_14 ( V_4 , V_686 ) & 0xff ;
return F_124 ( T_1 , V_45 , 0xc0 ) ;
}
static void F_302 ( struct V_3 * V_4 )
{
unsigned long V_687 = F_3 ( V_688 ) & ~ 4095 ;
F_64 ( V_687 != V_4 -> V_569 . V_689 +
V_4 -> V_690 -> V_691 -> V_379 ) ;
}
static void F_303 ( struct V_3 * V_4 )
{
unsigned long V_687 = F_3 ( V_688 ) & ~ 4095 ;
F_64 ( ( V_687 >> V_692 ) == 0 ) ;
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_693 , V_694 ;
struct V_695 * V_593 = & V_4 -> V_593 ;
T_1 V_696 ;
int V_697 = 32 * 1024 ;
V_696 = F_3 ( V_688 ) ;
if ( ( V_696 >> V_692 ) == 0 ) {
F_8 ( L_72 ) ;
V_694 = ( V_4 -> V_569 . V_689 +
( V_593 -> V_698 - V_697 ) ) ;
V_693 = ( V_694 & ( ~ 4095 ) ) ;
F_2 ( V_688 , V_693 ) ;
}
F_8 ( L_73 , F_3 ( V_688 ) ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_240 * V_699 ;
unsigned long V_693 ;
T_1 V_696 ;
int V_697 = 24 * 1024 ;
F_13 ( & V_2 -> V_700 ) ;
V_696 = F_3 ( V_688 ) ;
if ( V_696 ) {
int V_701 ;
V_701 = ( V_696 & ( ~ 4095 ) ) - V_4 -> V_569 . V_689 ;
V_699 = F_306 ( V_4 -> V_2 ,
V_701 ,
V_702 ,
V_697 ) ;
goto V_703;
}
F_8 ( L_72 ) ;
V_699 = F_307 ( V_2 , V_697 ) ;
if ( ! V_699 ) {
F_217 ( L_74 ) ;
goto V_703;
}
V_693 = V_4 -> V_569 . V_689 + V_699 -> V_691 -> V_379 ;
F_2 ( V_688 , V_693 ) ;
V_703:
F_8 ( L_73 , F_3 ( V_688 ) ) ;
V_4 -> V_690 = V_699 ;
F_18 ( & V_2 -> V_700 ) ;
}
static void F_308 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_64 ( ! V_4 -> V_690 ) )
return;
F_309 ( & V_4 -> V_690 -> V_100 ) ;
V_4 -> V_690 = NULL ;
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_45 ;
F_305 ( V_2 ) ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
V_45 = F_14 ( V_4 , V_704 ) ;
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
F_8 ( L_75 , V_4 -> V_24 ) ;
V_4 -> V_46 . V_555 = F_299 ( V_4 ) ;
V_4 -> V_46 . V_530 = V_4 -> V_46 . V_555 ;
F_8 ( L_76 ,
F_241 ( V_4 , V_4 -> V_46 . V_555 ) ,
V_4 -> V_46 . V_555 ) ;
V_4 -> V_46 . V_527 = F_300 ( V_4 ) ;
F_8 ( L_77 ,
F_241 ( V_4 , V_4 -> V_46 . V_527 ) ,
V_4 -> V_46 . V_527 ) ;
V_4 -> V_46 . V_532 = F_297 ( V_4 ) ;
F_8 ( L_78 ,
F_241 ( V_4 , V_4 -> V_46 . V_532 ) ,
V_4 -> V_46 . V_532 ) ;
V_4 -> V_46 . V_556 = F_301 ( V_4 ) ;
F_8 ( L_79 ,
F_241 ( V_4 , V_4 -> V_46 . V_556 ) ,
V_4 -> V_46 . V_556 ) ;
V_4 -> V_46 . V_562 = V_4 -> V_46 . V_556 ;
if ( V_4 -> V_46 . V_518 == 0 )
V_4 -> V_46 . V_518 = V_4 -> V_46 . V_555 ;
if ( V_4 -> V_46 . V_519 == 0 )
V_4 -> V_46 . V_519 = V_4 -> V_46 . V_556 ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_45 ;
F_304 ( V_2 ) ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
F_13 ( & V_4 -> V_705 ) ;
V_45 = F_312 ( V_4 , V_706 ) ;
F_18 ( & V_4 -> V_705 ) ;
switch ( ( V_45 >> 2 ) & 0x7 ) {
case 3 :
V_4 -> V_24 = 2000 ;
break;
default:
V_4 -> V_24 = 1600 ;
break;
}
F_8 ( L_75 , V_4 -> V_24 ) ;
V_4 -> V_46 . V_555 = F_294 ( V_4 ) ;
V_4 -> V_46 . V_530 = V_4 -> V_46 . V_555 ;
F_8 ( L_76 ,
F_241 ( V_4 , V_4 -> V_46 . V_555 ) ,
V_4 -> V_46 . V_555 ) ;
V_4 -> V_46 . V_527 = F_295 ( V_4 ) ;
F_8 ( L_77 ,
F_241 ( V_4 , V_4 -> V_46 . V_527 ) ,
V_4 -> V_46 . V_527 ) ;
V_4 -> V_46 . V_532 = F_296 ( V_4 ) ;
F_8 ( L_80 ,
F_241 ( V_4 , V_4 -> V_46 . V_532 ) ,
V_4 -> V_46 . V_532 ) ;
V_4 -> V_46 . V_556 = V_4 -> V_46 . V_527 ;
F_8 ( L_79 ,
F_241 ( V_4 , V_4 -> V_46 . V_556 ) ,
V_4 -> V_46 . V_556 ) ;
F_243 ( ( V_4 -> V_46 . V_555 |
V_4 -> V_46 . V_527 |
V_4 -> V_46 . V_532 |
V_4 -> V_46 . V_556 ) & 1 ,
L_81 ) ;
V_4 -> V_46 . V_562 = V_4 -> V_46 . V_556 ;
if ( V_4 -> V_46 . V_518 == 0 )
V_4 -> V_46 . V_518 = V_4 -> V_46 . V_555 ;
if ( V_4 -> V_46 . V_519 == 0 )
V_4 -> V_46 . V_519 = V_4 -> V_46 . V_556 ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
static void F_313 ( struct V_1 * V_2 )
{
F_308 ( V_2 ) ;
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_618 * V_619 ;
T_1 V_636 , V_45 , V_637 = 0 , V_696 ;
int V_42 ;
F_64 ( ! F_235 ( & V_4 -> V_46 . V_47 ) ) ;
V_636 = F_3 ( V_638 ) ;
if ( V_636 ) {
F_8 ( L_66 ,
V_636 ) ;
F_2 ( V_638 , V_636 ) ;
}
F_303 ( V_4 ) ;
F_245 ( V_4 , V_581 ) ;
F_2 ( V_579 , 0 ) ;
F_2 ( V_622 , 40 << 16 ) ;
F_2 ( V_623 , 125000 ) ;
F_2 ( V_624 , 25 ) ;
F_278 (ring, dev_priv, i)
F_2 ( F_279 ( V_619 -> V_625 ) , 10 ) ;
F_2 ( V_627 , 0 ) ;
F_2 ( V_631 , 0x186 ) ;
F_2 ( V_707 ,
F_29 ( V_708 |
V_709 |
V_710 ) ) ;
V_696 = F_3 ( V_688 ) ;
if ( ( F_270 ( V_2 ) & V_605 ) &&
( V_696 >> V_692 ) )
V_637 = V_583 ;
F_2 ( V_579 , V_637 ) ;
F_2 ( V_616 , 1000000 ) ;
F_2 ( V_534 , 59400 ) ;
F_2 ( V_536 , 245000 ) ;
F_2 ( V_533 , 66000 ) ;
F_2 ( V_535 , 350000 ) ;
F_2 ( V_617 , 10 ) ;
F_2 ( V_537 ,
V_539 |
V_540 |
V_541 |
V_542 |
V_543 ) ;
V_45 = V_711 |
V_712 |
V_713 ;
F_15 ( V_4 , V_714 , V_45 ) ;
V_45 = F_14 ( V_4 , V_704 ) ;
F_243 ( ( V_45 & V_715 ) == 0 , L_82 ) ;
F_8 ( L_83 , F_315 ( V_45 & V_715 ) ) ;
F_8 ( L_84 , V_45 ) ;
V_4 -> V_46 . V_528 = ( V_45 >> 8 ) & 0xff ;
F_8 ( L_85 ,
F_241 ( V_4 , V_4 -> V_46 . V_528 ) ,
V_4 -> V_46 . V_528 ) ;
F_8 ( L_86 ,
F_241 ( V_4 , V_4 -> V_46 . V_527 ) ,
V_4 -> V_46 . V_527 ) ;
F_242 ( V_4 -> V_2 , V_4 -> V_46 . V_527 ) ;
F_246 ( V_4 , V_581 ) ;
}
static void F_316 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_618 * V_619 ;
T_1 V_636 , V_45 , V_637 = 0 ;
int V_42 ;
F_64 ( ! F_235 ( & V_4 -> V_46 . V_47 ) ) ;
F_302 ( V_4 ) ;
if ( ( V_636 = F_3 ( V_638 ) ) ) {
F_8 ( L_66 ,
V_636 ) ;
F_2 ( V_638 , V_636 ) ;
}
F_245 ( V_4 , V_581 ) ;
F_2 ( V_579 , 0 ) ;
F_2 ( V_616 , 1000000 ) ;
F_2 ( V_534 , 59400 ) ;
F_2 ( V_536 , 245000 ) ;
F_2 ( V_533 , 66000 ) ;
F_2 ( V_535 , 350000 ) ;
F_2 ( V_617 , 10 ) ;
F_2 ( V_537 ,
V_538 |
V_539 |
V_540 |
V_541 |
V_542 |
V_716 ) ;
F_2 ( V_622 , 0x00280000 ) ;
F_2 ( V_623 , 125000 ) ;
F_2 ( V_624 , 25 ) ;
F_278 (ring, dev_priv, i)
F_2 ( F_279 ( V_619 -> V_625 ) , 10 ) ;
F_2 ( V_631 , 0x557 ) ;
F_2 ( V_707 ,
F_29 ( V_717 |
V_718 |
V_709 |
V_710 ) ) ;
if ( F_270 ( V_2 ) & V_605 )
V_637 = V_583 | V_719 ;
F_263 ( V_2 , V_637 ) ;
F_2 ( V_579 , V_637 ) ;
V_45 = V_711 |
V_712 |
V_720 ;
F_15 ( V_4 , V_714 , V_45 ) ;
V_45 = F_14 ( V_4 , V_704 ) ;
F_243 ( ( V_45 & V_715 ) == 0 , L_82 ) ;
F_8 ( L_83 , F_315 ( V_45 & V_715 ) ) ;
F_8 ( L_84 , V_45 ) ;
V_4 -> V_46 . V_528 = ( V_45 >> 8 ) & 0xff ;
F_8 ( L_85 ,
F_241 ( V_4 , V_4 -> V_46 . V_528 ) ,
V_4 -> V_46 . V_528 ) ;
F_8 ( L_86 ,
F_241 ( V_4 , V_4 -> V_46 . V_527 ) ,
V_4 -> V_46 . V_527 ) ;
F_242 ( V_4 -> V_2 , V_4 -> V_46 . V_527 ) ;
F_246 ( V_4 , V_581 ) ;
}
static unsigned long F_317 ( T_1 V_721 )
{
unsigned long V_722 ;
int div = ( V_721 & 0x3f0000 ) >> 16 ;
int V_723 = ( V_721 & 0x3000 ) >> 12 ;
int V_724 = ( V_721 & 0x7 ) ;
if ( ! V_724 )
return 0 ;
V_722 = ( ( div * 133333 ) / ( ( 1 << V_723 ) * V_724 ) ) ;
return V_722 ;
}
static unsigned long F_318 ( struct V_3 * V_4 )
{
T_9 V_725 , V_659 , V_184 ;
T_1 V_726 , V_727 , V_728 , V_729 = 0 , V_730 = 0 ;
unsigned long V_731 = F_225 ( V_507 ) , V_732 ;
int V_42 ;
F_216 ( & V_465 ) ;
V_732 = V_731 - V_4 -> V_34 . V_506 ;
if ( V_732 <= 10 )
return V_4 -> V_34 . V_733 ;
V_726 = F_3 ( V_503 ) ;
V_727 = F_3 ( V_504 ) ;
V_728 = F_3 ( V_505 ) ;
V_725 = V_726 + V_727 + V_728 ;
if ( V_725 < V_4 -> V_34 . V_502 ) {
V_659 = ~ 0UL - V_4 -> V_34 . V_502 ;
V_659 += V_725 ;
} else {
V_659 = V_725 - V_4 -> V_34 . V_502 ;
}
for ( V_42 = 0 ; V_42 < F_10 ( V_734 ) ; V_42 ++ ) {
if ( V_734 [ V_42 ] . V_42 == V_4 -> V_34 . V_36 &&
V_734 [ V_42 ] . V_735 == V_4 -> V_34 . V_35 ) {
V_729 = V_734 [ V_42 ] . V_729 ;
V_730 = V_734 [ V_42 ] . V_730 ;
break;
}
}
V_659 = F_87 ( V_659 , V_732 ) ;
V_184 = ( ( V_729 * V_659 ) + V_730 ) ;
V_184 = F_87 ( V_184 , 10 ) ;
V_4 -> V_34 . V_502 = V_725 ;
V_4 -> V_34 . V_506 = V_731 ;
V_4 -> V_34 . V_733 = V_184 ;
return V_184 ;
}
unsigned long F_319 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_45 ;
if ( F_70 ( V_2 ) -> V_266 != 5 )
return 0 ;
F_221 ( & V_465 ) ;
V_45 = F_318 ( V_4 ) ;
F_227 ( & V_465 ) ;
return V_45 ;
}
unsigned long F_320 ( struct V_3 * V_4 )
{
unsigned long V_729 , V_736 , V_737 ;
T_1 V_738 ;
V_738 = F_3 ( V_739 ) ;
V_729 = ( ( V_738 & V_740 ) >> V_741 ) ;
V_736 = F_321 ( V_742 ) ;
V_737 = V_738 & V_743 ;
return ( ( V_729 * V_736 ) / 127 ) - V_737 ;
}
static int F_322 ( T_8 V_744 )
{
if ( V_744 == 0 )
return 0 ;
if ( V_744 >= 8 && V_744 < 31 )
V_744 = 31 ;
return ( V_744 + 2 ) * 125 ;
}
static T_1 F_323 ( struct V_3 * V_4 , T_8 V_744 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
const int V_745 = F_322 ( V_744 ) ;
const int V_746 = V_745 - 1125 ;
if ( F_70 ( V_2 ) -> V_747 )
return V_746 > 0 ? V_746 : 0 ;
return V_745 ;
}
static void F_324 ( struct V_3 * V_4 )
{
T_9 V_731 , V_659 , V_748 ;
T_1 V_749 ;
F_216 ( & V_465 ) ;
V_731 = F_226 () ;
V_748 = V_731 - V_4 -> V_34 . V_510 ;
F_325 ( V_748 , V_750 ) ;
if ( ! V_748 )
return;
V_749 = F_3 ( V_509 ) ;
if ( V_749 < V_4 -> V_34 . V_508 ) {
V_659 = ~ 0UL - V_4 -> V_34 . V_508 ;
V_659 += V_749 ;
} else {
V_659 = V_749 - V_4 -> V_34 . V_508 ;
}
V_4 -> V_34 . V_508 = V_749 ;
V_4 -> V_34 . V_510 = V_731 ;
V_659 = V_659 * 1181 ;
V_659 = F_87 ( V_659 , V_748 * 10 ) ;
V_4 -> V_34 . V_751 = V_659 ;
}
void F_326 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_70 ( V_2 ) -> V_266 != 5 )
return;
F_221 ( & V_465 ) ;
F_324 ( V_4 ) ;
F_227 ( & V_465 ) ;
}
static unsigned long F_327 ( struct V_3 * V_4 )
{
unsigned long V_735 , V_752 , V_753 , V_754 , V_755 ;
T_1 V_744 , V_756 ;
F_216 ( & V_465 ) ;
V_744 = F_3 ( F_222 ( V_4 -> V_46 . V_528 ) ) ;
V_744 = ( V_744 >> 24 ) & 0x7f ;
V_756 = F_323 ( V_4 , V_744 ) ;
V_753 = V_756 ;
V_735 = F_320 ( V_4 ) ;
if ( V_735 > 80 )
V_752 = ( ( V_735 * 2349 ) + 135940 ) ;
else if ( V_735 >= 50 )
V_752 = ( ( V_735 * 964 ) + 29317 ) ;
else
V_752 = ( ( V_735 * 301 ) + 1004 ) ;
V_752 = V_752 * ( ( 150142 * V_753 ) / 10000 - 78642 ) ;
V_752 /= 100000 ;
V_754 = ( V_752 * V_4 -> V_34 . V_752 ) ;
V_755 = ( V_754 * V_753 ) / 10000 ;
V_755 /= 100 ;
F_324 ( V_4 ) ;
return V_4 -> V_34 . V_751 + V_755 ;
}
unsigned long F_328 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_45 ;
if ( F_70 ( V_2 ) -> V_266 != 5 )
return 0 ;
F_221 ( & V_465 ) ;
V_45 = F_327 ( V_4 ) ;
F_227 ( & V_465 ) ;
return V_45 ;
}
unsigned long F_329 ( void )
{
struct V_3 * V_4 ;
unsigned long V_757 , V_758 , V_184 = 0 ;
F_221 ( & V_465 ) ;
if ( ! V_759 )
goto V_760;
V_4 = V_759 ;
V_757 = F_318 ( V_4 ) ;
V_758 = F_327 ( V_4 ) ;
V_184 = V_757 + V_758 ;
V_760:
F_227 ( & V_465 ) ;
return V_184 ;
}
bool F_330 ( void )
{
struct V_3 * V_4 ;
bool V_184 = true ;
F_221 ( & V_465 ) ;
if ( ! V_759 ) {
V_184 = false ;
goto V_760;
}
V_4 = V_759 ;
if ( V_4 -> V_34 . V_494 > V_4 -> V_34 . V_473 )
V_4 -> V_34 . V_494 -- ;
V_760:
F_227 ( & V_465 ) ;
return V_184 ;
}
bool F_331 ( void )
{
struct V_3 * V_4 ;
bool V_184 = true ;
F_221 ( & V_465 ) ;
if ( ! V_759 ) {
V_184 = false ;
goto V_760;
}
V_4 = V_759 ;
if ( V_4 -> V_34 . V_494 < V_4 -> V_34 . V_495 )
V_4 -> V_34 . V_494 ++ ;
V_760:
F_227 ( & V_465 ) ;
return V_184 ;
}
bool F_332 ( void )
{
struct V_3 * V_4 ;
struct V_618 * V_619 ;
bool V_184 = false ;
int V_42 ;
F_221 ( & V_465 ) ;
if ( ! V_759 )
goto V_760;
V_4 = V_759 ;
F_278 (ring, dev_priv, i)
V_184 |= ! F_251 ( & V_619 -> V_761 ) ;
V_760:
F_227 ( & V_465 ) ;
return V_184 ;
}
bool F_333 ( void )
{
struct V_3 * V_4 ;
bool V_184 = true ;
F_221 ( & V_465 ) ;
if ( ! V_759 ) {
V_184 = false ;
goto V_760;
}
V_4 = V_759 ;
V_4 -> V_34 . V_494 = V_4 -> V_34 . V_475 ;
if ( ! F_215 ( V_4 -> V_2 , V_4 -> V_34 . V_475 ) )
V_184 = false ;
V_760:
F_227 ( & V_465 ) ;
return V_184 ;
}
static void
F_334 ( void )
{
void (* V_572)( void );
V_572 = F_335 ( V_762 ) ;
if ( V_572 ) {
V_572 () ;
F_336 ( V_762 ) ;
}
}
void F_337 ( struct V_3 * V_4 )
{
F_221 ( & V_465 ) ;
V_759 = V_4 ;
F_227 ( & V_465 ) ;
F_334 () ;
}
void F_338 ( void )
{
F_221 ( & V_465 ) ;
V_759 = NULL ;
F_227 ( & V_465 ) ;
}
static void F_339 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_763 ;
T_8 V_764 [ 16 ] ;
int V_42 ;
F_2 ( V_765 , 0 ) ;
F_23 ( V_765 ) ;
F_2 ( V_766 , 0x15040d00 ) ;
F_2 ( V_767 , 0x007f0000 ) ;
F_2 ( V_768 , 0x1e220004 ) ;
F_2 ( V_769 , 0x04000004 ) ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ )
F_2 ( F_340 ( V_42 ) , 0 ) ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ )
F_2 ( F_341 ( V_42 ) , 0 ) ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ ) {
T_1 V_770 = F_3 ( F_222 ( V_42 ) ) ;
unsigned long V_722 = F_317 ( V_770 ) ;
unsigned long V_771 = ( V_770 & V_492 ) >>
V_493 ;
unsigned long V_45 ;
V_45 = V_771 * V_771 ;
V_45 *= ( V_722 / 1000 ) ;
V_45 *= 255 ;
V_45 /= ( 127 * 127 * 900 ) ;
if ( V_45 > 0xff )
F_17 ( L_87 , V_45 ) ;
V_764 [ V_42 ] = V_45 ;
}
V_764 [ 14 ] = 0 ;
V_764 [ 15 ] = 0 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
T_1 V_45 = ( V_764 [ V_42 * 4 ] << 24 ) | ( V_764 [ ( V_42 * 4 ) + 1 ] << 16 ) |
( V_764 [ ( V_42 * 4 ) + 2 ] << 8 ) | ( V_764 [ ( V_42 * 4 ) + 3 ] ) ;
F_2 ( F_342 ( V_42 ) , V_45 ) ;
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
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ )
F_2 ( F_343 ( V_42 ) , 0 ) ;
F_2 ( V_765 , 0x80000019 ) ;
V_763 = F_3 ( V_782 ) ;
V_4 -> V_34 . V_752 = ( V_763 & V_783 ) ;
}
void F_344 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_608 . V_587 ) {
F_269 ( L_88 ) ;
F_345 ( V_4 ) ;
}
if ( F_22 ( V_2 ) )
F_311 ( V_2 ) ;
else if ( F_21 ( V_2 ) )
F_310 ( V_2 ) ;
}
void F_346 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_22 ( V_2 ) )
return;
else if ( F_21 ( V_2 ) )
F_313 ( V_2 ) ;
if ( ! V_608 . V_587 )
F_347 ( V_4 ) ;
}
static void F_348 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_349 ( & V_4 -> V_46 . V_784 ) ;
F_350 ( V_2 ) ;
}
void F_351 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_70 ( V_2 ) -> V_266 < 6 )
return;
F_348 ( V_2 ) ;
F_249 ( V_4 ) ;
}
void F_352 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_353 ( V_2 ) ) {
F_228 ( V_2 ) ;
} else if ( F_70 ( V_2 ) -> V_266 >= 6 ) {
F_351 ( V_2 ) ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
if ( F_70 ( V_2 ) -> V_266 >= 9 )
F_259 ( V_2 ) ;
else if ( F_22 ( V_2 ) )
F_261 ( V_2 ) ;
else if ( F_21 ( V_2 ) )
F_262 ( V_2 ) ;
else
F_260 ( V_2 ) ;
V_4 -> V_46 . V_94 = false ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
}
}
static void F_354 ( struct V_785 * V_577 )
{
struct V_3 * V_4 =
F_355 ( V_577 , struct V_3 ,
V_46 . V_784 . V_577 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_13 ( & V_4 -> V_46 . V_47 ) ;
F_356 ( V_2 ) ;
if ( F_22 ( V_2 ) ) {
F_314 ( V_2 ) ;
} else if ( F_21 ( V_2 ) ) {
F_316 ( V_2 ) ;
} else if ( F_70 ( V_2 ) -> V_266 >= 9 ) {
F_277 ( V_2 ) ;
F_276 ( V_2 ) ;
if ( F_272 ( V_2 ) || F_273 ( V_2 ) )
F_288 ( V_2 ) ;
} else if ( F_117 ( V_2 ) ) {
F_283 ( V_2 ) ;
F_288 ( V_2 ) ;
} else {
F_284 ( V_2 ) ;
F_288 ( V_2 ) ;
}
F_64 ( V_4 -> V_46 . V_555 < V_4 -> V_46 . V_556 ) ;
F_64 ( V_4 -> V_46 . V_562 > V_4 -> V_46 . V_555 ) ;
F_64 ( V_4 -> V_46 . V_527 < V_4 -> V_46 . V_556 ) ;
F_64 ( V_4 -> V_46 . V_527 > V_4 -> V_46 . V_555 ) ;
V_4 -> V_46 . V_94 = true ;
F_357 ( V_2 ) ;
F_18 ( & V_4 -> V_46 . V_47 ) ;
F_347 ( V_4 ) ;
}
void F_358 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_359 ( V_2 ) )
return;
if ( F_353 ( V_2 ) ) {
F_220 ( V_2 ) ;
F_13 ( & V_2 -> V_700 ) ;
F_339 ( V_2 ) ;
F_18 ( & V_2 -> V_700 ) ;
} else if ( F_70 ( V_2 ) -> V_266 >= 6 ) {
if ( F_360 ( & V_4 -> V_46 . V_784 ,
F_361 ( V_786 ) ) )
F_362 ( V_4 ) ;
}
}
void F_363 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_70 ( V_2 ) -> V_266 < 6 )
return;
F_348 ( V_2 ) ;
V_4 -> V_46 . V_94 = false ;
}
static void F_364 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_787 , V_788 ) ;
}
static void F_365 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_65 V_65 ;
F_145 (dev_priv, pipe) {
F_2 ( F_366 ( V_65 ) ,
F_3 ( F_366 ( V_65 ) ) |
V_789 ) ;
F_2 ( F_367 ( V_65 ) , F_3 ( F_367 ( V_65 ) ) ) ;
F_23 ( F_367 ( V_65 ) ) ;
}
}
static void F_368 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_357 , F_3 ( V_357 ) & ~ V_336 ) ;
F_2 ( V_358 , F_3 ( V_358 ) & ~ V_336 ) ;
F_2 ( V_359 , F_3 ( V_359 ) & ~ V_336 ) ;
}
static void F_369 ( struct V_1 * V_2 )
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
F_2 ( V_367 ,
( F_3 ( V_367 ) |
V_368 ) ) ;
F_368 ( V_2 ) ;
if ( F_353 ( V_2 ) ) {
F_2 ( V_804 ,
F_3 ( V_804 ) |
V_805 ) ;
F_2 ( V_800 ,
F_3 ( V_800 ) |
V_801 ) ;
}
F_2 ( V_806 , V_790 ) ;
F_2 ( V_800 ,
F_3 ( V_800 ) |
V_807 ) ;
F_2 ( V_808 ,
V_809 << 16 |
V_809 ) ;
F_2 ( V_810 ,
F_29 ( V_811 ) ) ;
F_2 ( V_810 , F_30 ( V_812 ) ) ;
F_365 ( V_2 ) ;
F_364 ( V_2 ) ;
}
static void F_370 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_65 ;
T_3 V_45 ;
F_2 ( V_787 , V_788 |
V_813 |
V_814 ) ;
F_2 ( V_815 , F_3 ( V_815 ) |
V_816 ) ;
F_145 (dev_priv, pipe) {
V_45 = F_3 ( F_371 ( V_65 ) ) ;
V_45 |= V_817 ;
V_45 &= ~ V_818 ;
if ( V_4 -> V_819 . V_820 )
V_45 |= V_818 ;
V_45 &= ~ V_821 ;
V_45 &= ~ V_822 ;
V_45 &= ~ V_823 ;
F_2 ( F_371 ( V_65 ) , V_45 ) ;
}
F_145 (dev_priv, pipe) {
F_2 ( F_372 ( V_65 ) ,
V_824 ) ;
}
}
static void F_373 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_14 ;
V_14 = F_3 ( V_298 ) ;
if ( ( V_14 & V_825 ) != V_826 )
F_11 ( L_89 ,
V_14 ) ;
}
static void F_374 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_790 = V_791 ;
F_2 ( V_806 , V_790 ) ;
F_2 ( V_800 ,
F_3 ( V_800 ) |
V_807 ) ;
F_2 ( V_827 ,
F_29 ( V_828 ) ) ;
F_2 ( V_810 , F_30 ( V_812 ) ) ;
F_2 ( V_829 ,
F_375 ( V_830 , V_831 ) ) ;
F_368 ( V_2 ) ;
F_2 ( V_810 ,
F_30 ( V_832 ) ) ;
F_2 ( V_833 ,
F_3 ( V_833 ) |
V_834 |
V_835 ) ;
F_2 ( V_836 ,
V_837 |
V_838 ) ;
F_2 ( V_839 ,
F_29 ( V_840 ) ) ;
F_2 ( V_839 ,
F_29 ( V_841 ) ) ;
F_2 ( V_804 ,
F_3 ( V_804 ) |
V_805 | V_842 ) ;
F_2 ( V_800 ,
F_3 ( V_800 ) |
V_801 | V_802 ) ;
F_2 ( V_806 ,
F_3 ( V_806 ) |
V_803 |
V_794 ) ;
F_365 ( V_2 ) ;
F_370 ( V_2 ) ;
F_373 ( V_2 ) ;
}
static void F_376 ( struct V_3 * V_4 )
{
T_3 V_96 = F_3 ( V_843 ) ;
V_96 &= ~ V_844 ;
V_96 |= V_845 ;
V_96 |= V_846 ;
V_96 |= V_847 ;
F_2 ( V_843 , V_96 ) ;
}
static void F_377 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_378 ( V_2 ) )
F_2 ( V_787 ,
F_3 ( V_787 ) |
V_848 ) ;
F_2 ( F_372 ( V_73 ) ,
F_3 ( F_372 ( V_73 ) ) |
V_824 ) ;
}
static void F_379 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_378 ( V_2 ) ) {
T_3 V_45 = F_3 ( V_787 ) ;
V_45 &= ~ V_848 ;
F_2 ( V_787 , V_45 ) ;
}
}
static void F_380 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_65 V_65 ;
T_3 V_849 ;
F_368 ( V_2 ) ;
F_2 ( V_850 , F_3 ( V_850 ) | V_851 ) ;
F_2 ( V_852 ,
F_3 ( V_852 ) | V_853 ) ;
F_145 (dev_priv, pipe) {
F_2 ( F_381 ( V_65 ) ,
F_3 ( F_381 ( V_65 ) ) |
V_854 ) ;
}
F_2 ( V_843 ,
F_3 ( V_843 ) &
~ ( V_855 | V_856 ) ) ;
F_2 ( V_857 ,
F_29 ( V_858 ) ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
V_849 = F_3 ( V_859 ) ;
F_2 ( V_859 , V_849 & ~ V_860 ) ;
F_2 ( V_861 , V_862 ) ;
F_23 ( V_861 ) ;
F_382 ( 1 ) ;
F_2 ( V_859 , V_849 ) ;
F_2 ( V_863 , V_864 ) ;
F_377 ( V_2 ) ;
}
static void F_383 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_368 ( V_2 ) ;
F_2 ( V_865 , V_866 ) ;
F_2 ( V_867 ,
F_29 ( V_868 ) ) ;
F_2 ( V_869 ,
F_3 ( V_869 ) |
V_870 ) ;
F_2 ( V_843 ,
F_3 ( V_843 ) & ~ V_856 ) ;
F_2 ( V_871 , F_30 ( V_812 ) ) ;
F_2 ( V_871 ,
F_30 ( V_872 ) ) ;
F_2 ( V_873 ,
F_29 ( V_874 ) ) ;
F_2 ( V_875 ,
F_375 ( V_830 , V_831 ) ) ;
F_2 ( V_876 ,
F_29 ( V_877 ) ) ;
F_2 ( V_850 , F_3 ( V_850 ) | V_851 ) ;
F_2 ( V_852 ,
F_3 ( V_852 ) | V_878 ) ;
F_377 ( V_2 ) ;
}
static void F_384 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_879 ;
F_368 ( V_2 ) ;
F_2 ( V_806 , V_791 ) ;
F_2 ( V_839 ,
F_29 ( V_880 ) ) ;
F_2 ( V_881 ,
V_882 |
V_883 ) ;
if ( F_385 ( V_2 ) )
F_2 ( V_884 ,
F_29 ( V_885 ) ) ;
F_2 ( V_871 , F_30 ( V_812 ) ) ;
F_2 ( V_886 ,
V_887 ) ;
F_2 ( V_888 ,
V_889 ) ;
F_2 ( V_890 ,
V_891 ) ;
if ( F_385 ( V_2 ) )
F_2 ( V_892 ,
F_29 ( V_893 ) ) ;
else {
F_2 ( V_892 ,
F_29 ( V_893 ) ) ;
F_2 ( V_894 ,
F_29 ( V_893 ) ) ;
}
F_2 ( V_895 , F_3 ( V_895 ) &
~ V_896 ) ;
F_2 ( V_836 ,
V_897 ) ;
F_2 ( V_869 ,
F_3 ( V_869 ) |
V_870 ) ;
F_365 ( V_2 ) ;
F_376 ( V_4 ) ;
if ( 0 ) {
F_2 ( V_871 ,
F_30 ( V_872 ) ) ;
}
F_2 ( V_873 ,
F_29 ( V_874 ) ) ;
F_2 ( V_875 ,
F_375 ( V_830 , V_831 ) ) ;
V_879 = F_3 ( V_898 ) ;
V_879 &= ~ V_899 ;
V_879 |= V_900 ;
F_2 ( V_898 , V_879 ) ;
if ( ! F_386 ( V_2 ) )
F_370 ( V_2 ) ;
F_373 ( V_2 ) ;
}
static void F_387 ( struct V_3 * V_4 )
{
F_2 ( V_901 , V_902 ) ;
F_2 ( V_903 , V_904 ) ;
F_2 ( V_905 , 0 ) ;
}
static void F_388 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_387 ( V_4 ) ;
F_2 ( V_839 ,
F_29 ( V_880 ) ) ;
F_2 ( V_881 ,
V_882 |
V_883 ) ;
F_2 ( V_884 ,
F_29 ( V_906 |
V_885 ) ) ;
F_2 ( V_871 , F_30 ( V_812 ) ) ;
F_2 ( V_895 , F_3 ( V_895 ) &
~ V_896 ) ;
F_2 ( V_892 ,
F_29 ( V_893 ) ) ;
F_2 ( V_869 ,
F_3 ( V_869 ) |
V_870 ) ;
F_376 ( V_4 ) ;
F_2 ( V_836 ,
V_897 ) ;
F_2 ( V_907 ,
F_3 ( V_907 ) | V_908 ) ;
F_2 ( V_873 ,
F_29 ( V_874 ) ) ;
F_2 ( V_875 ,
F_375 ( V_830 , V_831 ) ) ;
F_2 ( V_909 , V_910 ) ;
F_2 ( V_911 , V_912 ) ;
}
static void F_389 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_387 ( V_4 ) ;
F_2 ( V_843 ,
F_3 ( V_843 ) &
~ ( V_855 | V_856 ) ) ;
F_2 ( V_857 ,
F_29 ( V_858 ) ) ;
F_2 ( V_833 , F_3 ( V_833 ) |
V_835 ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
F_2 ( V_863 , V_864 ) ;
}
static void F_390 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_790 ;
F_2 ( V_913 , 0 ) ;
F_2 ( V_914 , V_915 |
V_916 |
V_917 ) ;
F_2 ( V_918 , 0 ) ;
V_790 = V_902 |
V_919 |
V_920 ;
if ( F_391 ( V_2 ) )
V_790 |= V_921 ;
F_2 ( V_901 , V_790 ) ;
F_2 ( V_810 ,
F_29 ( V_811 ) ) ;
F_2 ( V_810 , F_30 ( V_812 ) ) ;
F_365 ( V_2 ) ;
}
static void F_392 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_913 , V_922 ) ;
F_2 ( V_914 , 0 ) ;
F_2 ( V_901 , 0 ) ;
F_2 ( V_918 , 0 ) ;
F_218 ( V_923 , 0 ) ;
F_2 ( V_924 ,
F_29 ( V_904 ) ) ;
F_2 ( V_810 , F_30 ( V_812 ) ) ;
}
static void F_393 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_913 , V_925 |
V_922 |
V_926 |
V_927 |
V_928 ) ;
F_2 ( V_914 , 0 ) ;
F_2 ( V_924 ,
F_29 ( V_904 ) ) ;
F_2 ( V_810 , F_30 ( V_812 ) ) ;
}
static void F_394 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_929 = F_3 ( V_930 ) ;
V_929 |= V_931 | V_932 |
V_933 ;
F_2 ( V_930 , V_929 ) ;
if ( F_26 ( V_2 ) )
F_2 ( V_934 , F_29 ( V_935 ) ) ;
F_2 ( V_934 , F_30 ( V_936 ) ) ;
F_2 ( V_64 , F_29 ( V_937 ) ) ;
F_2 ( V_924 , F_29 ( V_938 ) ) ;
F_2 ( V_924 ,
F_29 ( V_904 ) ) ;
}
static void F_395 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_913 , V_939 ) ;
F_2 ( V_940 , F_29 ( V_941 ) |
F_30 ( V_942 ) ) ;
F_2 ( V_943 ,
F_29 ( V_944 ) ) ;
}
static void F_396 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_901 , V_919 ) ;
F_2 ( V_943 ,
F_29 ( V_945 ) |
F_29 ( V_946 ) ) ;
}
void F_397 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_123 . V_947 )
V_4 -> V_123 . V_947 ( V_2 ) ;
}
void F_398 ( struct V_1 * V_2 )
{
if ( F_399 ( V_2 ) )
F_379 ( V_2 ) ;
}
void F_400 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_401 ( V_4 ) ;
if ( F_26 ( V_2 ) )
F_5 ( V_2 ) ;
else if ( F_138 ( V_2 ) )
F_6 ( V_2 ) ;
if ( F_70 ( V_2 ) -> V_266 >= 9 ) {
F_128 ( V_2 ) ;
if ( F_156 ( V_2 ) )
V_4 -> V_123 . V_947 =
F_1 ;
V_4 -> V_123 . V_463 = F_199 ;
} else if ( F_402 ( V_2 ) ) {
F_126 ( V_2 ) ;
if ( ( F_138 ( V_2 ) && V_4 -> V_56 . V_185 [ 1 ] &&
V_4 -> V_56 . V_286 [ 1 ] && V_4 -> V_56 . V_287 [ 1 ] ) ||
( ! F_138 ( V_2 ) && V_4 -> V_56 . V_185 [ 0 ] &&
V_4 -> V_56 . V_286 [ 0 ] && V_4 -> V_56 . V_287 [ 0 ] ) ) {
V_4 -> V_123 . V_463 = F_202 ;
V_4 -> V_123 . V_948 = F_129 ;
V_4 -> V_123 . V_949 = F_201 ;
} else {
F_11 ( L_90
L_91 ) ;
}
if ( F_138 ( V_2 ) )
V_4 -> V_123 . V_947 = F_369 ;
else if ( F_127 ( V_2 ) )
V_4 -> V_123 . V_947 = F_374 ;
else if ( F_121 ( V_2 ) )
V_4 -> V_123 . V_947 = F_384 ;
else if ( F_116 ( V_2 ) )
V_4 -> V_123 . V_947 = F_383 ;
else if ( F_70 ( V_2 ) -> V_266 == 8 )
V_4 -> V_123 . V_947 = F_380 ;
} else if ( F_22 ( V_2 ) ) {
F_62 ( V_2 ) ;
V_4 -> V_123 . V_463 = F_76 ;
V_4 -> V_123 . V_947 =
F_389 ;
} else if ( F_21 ( V_2 ) ) {
F_62 ( V_2 ) ;
V_4 -> V_123 . V_463 = F_76 ;
V_4 -> V_123 . V_947 =
F_388 ;
} else if ( F_26 ( V_2 ) ) {
if ( ! F_9 ( F_46 ( V_2 ) ,
V_4 -> V_28 ,
V_4 -> V_18 ,
V_4 -> V_24 ) ) {
F_269 ( L_92
L_93
L_94 ,
( V_4 -> V_28 == 1 ) ? L_95 : L_96 ,
V_4 -> V_18 , V_4 -> V_24 ) ;
F_20 ( V_4 , false ) ;
V_4 -> V_123 . V_463 = NULL ;
} else
V_4 -> V_123 . V_463 = F_45 ;
V_4 -> V_123 . V_947 = F_394 ;
} else if ( F_24 ( V_2 ) ) {
V_4 -> V_123 . V_463 = F_77 ;
V_4 -> V_123 . V_947 = F_390 ;
} else if ( F_403 ( V_2 ) ) {
V_4 -> V_123 . V_463 = F_80 ;
if ( F_25 ( V_2 ) )
V_4 -> V_123 . V_947 = F_392 ;
else if ( F_404 ( V_2 ) )
V_4 -> V_123 . V_947 = F_393 ;
} else if ( F_405 ( V_2 ) ) {
V_4 -> V_123 . V_463 = F_81 ;
V_4 -> V_123 . V_238 = F_37 ;
V_4 -> V_123 . V_947 = F_394 ;
} else if ( F_82 ( V_2 ) ) {
if ( F_70 ( V_2 ) -> V_207 == 1 ) {
V_4 -> V_123 . V_463 = F_85 ;
V_4 -> V_123 . V_238 = F_39 ;
} else {
V_4 -> V_123 . V_463 = F_81 ;
V_4 -> V_123 . V_238 = F_38 ;
}
if ( F_406 ( V_2 ) || F_407 ( V_2 ) )
V_4 -> V_123 . V_947 = F_395 ;
else
V_4 -> V_123 . V_947 = F_396 ;
} else {
F_17 ( L_97 ) ;
}
}
int F_115 ( struct V_3 * V_4 , T_1 V_950 , T_1 * V_45 )
{
F_64 ( ! F_235 ( & V_4 -> V_46 . V_47 ) ) ;
if ( F_3 ( V_951 ) & V_952 ) {
F_8 ( L_98 ) ;
return - V_953 ;
}
F_2 ( V_954 , * V_45 ) ;
F_2 ( V_955 , 0 ) ;
F_2 ( V_951 , V_952 | V_950 ) ;
if ( F_16 ( ( F_3 ( V_951 ) & V_952 ) == 0 ,
500 ) ) {
F_17 ( L_99 , V_950 ) ;
return - V_956 ;
}
* V_45 = F_3 ( V_954 ) ;
F_2 ( V_954 , 0 ) ;
return 0 ;
}
int F_285 ( struct V_3 * V_4 , T_1 V_950 , T_1 V_45 )
{
F_64 ( ! F_235 ( & V_4 -> V_46 . V_47 ) ) ;
if ( F_3 ( V_951 ) & V_952 ) {
F_8 ( L_100 ) ;
return - V_953 ;
}
F_2 ( V_954 , V_45 ) ;
F_2 ( V_951 , V_952 | V_950 ) ;
if ( F_16 ( ( F_3 ( V_951 ) & V_952 ) == 0 ,
500 ) ) {
F_17 ( L_101 , V_950 ) ;
return - V_956 ;
}
F_2 ( V_954 , 0 ) ;
return 0 ;
}
static int F_408 ( unsigned int V_957 )
{
switch ( V_957 ) {
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
static int F_409 ( struct V_3 * V_4 , int V_45 )
{
int div , V_957 = F_109 ( V_4 -> V_957 , 1000 ) ;
div = F_408 ( V_957 ) ;
if ( div < 0 )
return div ;
return F_109 ( V_957 * ( V_45 + 6 - 0xbd ) , div ) ;
}
static int F_410 ( struct V_3 * V_4 , int V_45 )
{
int V_958 , V_957 = F_109 ( V_4 -> V_957 , 1000 ) ;
V_958 = F_408 ( V_957 ) ;
if ( V_958 < 0 )
return V_958 ;
return F_109 ( V_958 * V_45 , V_957 ) + 0xbd - 6 ;
}
static int F_411 ( struct V_3 * V_4 , int V_45 )
{
int div , V_957 = F_109 ( V_4 -> V_957 , 1000 ) ;
div = F_408 ( V_957 ) ;
if ( div < 0 )
return div ;
div /= 2 ;
return F_109 ( V_957 * V_45 , 2 * div ) / 2 ;
}
static int F_412 ( struct V_3 * V_4 , int V_45 )
{
int V_958 , V_957 = F_109 ( V_4 -> V_957 , 1000 ) ;
V_958 = F_408 ( V_957 ) ;
if ( V_958 < 0 )
return V_958 ;
V_958 /= 2 ;
return F_109 ( V_45 * 2 * V_958 , V_957 ) * 2 ;
}
int F_241 ( struct V_3 * V_4 , int V_45 )
{
if ( F_113 ( V_4 -> V_2 ) )
return F_109 ( V_45 * V_959 ,
V_614 ) ;
else if ( F_22 ( V_4 -> V_2 ) )
return F_411 ( V_4 , V_45 ) ;
else if ( F_21 ( V_4 -> V_2 ) )
return F_409 ( V_4 , V_45 ) ;
else
return V_45 * V_959 ;
}
int F_275 ( struct V_3 * V_4 , int V_45 )
{
if ( F_113 ( V_4 -> V_2 ) )
return F_109 ( V_45 * V_614 ,
V_959 ) ;
else if ( F_22 ( V_4 -> V_2 ) )
return F_412 ( V_4 , V_45 ) ;
else if ( F_21 ( V_4 -> V_2 ) )
return F_410 ( V_4 , V_45 ) ;
else
return F_109 ( V_45 , V_959 ) ;
}
static void F_413 ( struct V_785 * V_577 )
{
struct V_960 * V_961 = F_355 ( V_577 , struct V_960 , V_577 ) ;
struct V_962 * V_963 = V_961 -> V_963 ;
if ( ! F_414 ( V_963 , true ) )
F_254 ( F_57 ( V_963 -> V_619 -> V_2 ) , NULL ,
V_963 -> V_964 ) ;
F_415 ( V_963 ) ;
F_416 ( V_961 ) ;
}
void F_417 ( struct V_1 * V_2 ,
struct V_962 * V_963 )
{
struct V_960 * V_961 ;
if ( V_963 == NULL || F_70 ( V_2 ) -> V_266 < 6 )
return;
if ( F_414 ( V_963 , true ) )
return;
V_961 = F_418 ( sizeof( * V_961 ) , V_965 ) ;
if ( V_961 == NULL )
return;
F_419 ( V_963 ) ;
V_961 -> V_963 = V_963 ;
F_420 ( & V_961 -> V_577 , F_413 ) ;
F_256 ( F_57 ( V_2 ) -> V_576 , & V_961 -> V_577 ) ;
}
void F_421 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_422 ( & V_4 -> V_46 . V_47 ) ;
F_423 ( & V_4 -> V_46 . V_564 ) ;
F_424 ( & V_4 -> V_46 . V_784 ,
F_354 ) ;
F_425 ( & V_4 -> V_46 . V_565 ) ;
F_425 ( & V_4 -> V_46 . V_966 . V_572 ) ;
F_425 ( & V_4 -> V_46 . V_967 . V_572 ) ;
V_4 -> V_968 . V_969 = false ;
F_426 ( & V_4 -> V_968 . V_970 , 0 ) ;
F_426 ( & V_4 -> V_968 . V_971 , 0 ) ;
}
