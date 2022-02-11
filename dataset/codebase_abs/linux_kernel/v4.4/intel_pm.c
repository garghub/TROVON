static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_9 ;
V_9 = F_3 ( V_10 ) ;
switch ( V_9 & V_11 ) {
case V_12 :
V_4 -> V_13 = 533 ;
break;
case V_14 :
V_4 -> V_13 = 800 ;
break;
case V_15 :
V_4 -> V_13 = 667 ;
break;
case V_16 :
V_4 -> V_13 = 400 ;
break;
}
switch ( V_9 & V_17 ) {
case V_18 :
V_4 -> V_19 = 533 ;
break;
case V_20 :
V_4 -> V_19 = 667 ;
break;
case V_21 :
V_4 -> V_19 = 800 ;
break;
}
V_9 = F_3 ( V_22 ) ;
V_4 -> V_23 = ( V_9 & V_24 ) ? 1 : 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_25 , V_26 ;
V_25 = F_6 ( V_27 ) ;
V_26 = F_6 ( V_28 ) ;
switch ( V_25 & 0xff ) {
case 0xc :
V_4 -> V_19 = 800 ;
break;
case 0x10 :
V_4 -> V_19 = 1066 ;
break;
case 0x14 :
V_4 -> V_19 = 1333 ;
break;
case 0x18 :
V_4 -> V_19 = 1600 ;
break;
default:
F_7 ( L_1 ,
V_25 & 0xff ) ;
V_4 -> V_19 = 0 ;
break;
}
V_4 -> V_29 . V_30 = V_4 -> V_19 ;
switch ( V_26 & 0x3ff ) {
case 0x00c :
V_4 -> V_13 = 3200 ;
break;
case 0x00e :
V_4 -> V_13 = 3733 ;
break;
case 0x010 :
V_4 -> V_13 = 4266 ;
break;
case 0x012 :
V_4 -> V_13 = 4800 ;
break;
case 0x014 :
V_4 -> V_13 = 5333 ;
break;
case 0x016 :
V_4 -> V_13 = 5866 ;
break;
case 0x018 :
V_4 -> V_13 = 6400 ;
break;
default:
F_7 ( L_2 ,
V_26 & 0x3ff ) ;
V_4 -> V_13 = 0 ;
break;
}
if ( V_4 -> V_13 == 3200 ) {
V_4 -> V_29 . V_31 = 0 ;
} else if ( V_4 -> V_13 > 3200 && V_4 -> V_13 <= 4800 ) {
V_4 -> V_29 . V_31 = 1 ;
} else {
V_4 -> V_29 . V_31 = 2 ;
}
}
static const struct V_32 * F_8 ( int V_33 ,
int V_23 ,
int V_34 ,
int V_35 )
{
const struct V_32 * V_36 ;
int V_37 ;
if ( V_34 == 0 || V_35 == 0 )
return NULL ;
for ( V_37 = 0 ; V_37 < F_9 ( V_38 ) ; V_37 ++ ) {
V_36 = & V_38 [ V_37 ] ;
if ( V_33 == V_36 -> V_33 &&
V_23 == V_36 -> V_23 &&
V_34 == V_36 -> V_13 && V_35 == V_36 -> V_19 )
return V_36 ;
}
F_10 ( L_3 ) ;
return NULL ;
}
static void F_11 ( struct V_3 * V_4 , bool V_39 )
{
T_1 V_40 ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
V_40 = F_13 ( V_4 , V_43 ) ;
if ( V_39 )
V_40 &= ~ V_44 ;
else
V_40 |= V_44 ;
V_40 &= ~ V_45 ;
V_40 |= V_46 ;
F_14 ( V_4 , V_43 , V_40 ) ;
if ( F_15 ( ( F_13 ( V_4 , V_43 ) &
V_46 ) == 0 , 3 ) )
F_16 ( L_4 ) ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
}
static void F_18 ( struct V_3 * V_4 , bool V_39 )
{
T_1 V_40 ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
V_40 = F_13 ( V_4 , V_47 ) ;
if ( V_39 )
V_40 |= V_48 ;
else
V_40 &= ~ V_48 ;
F_14 ( V_4 , V_47 , V_40 ) ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
}
void F_19 ( struct V_3 * V_4 , bool V_39 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_40 ;
if ( F_20 ( V_2 ) ) {
F_2 ( V_49 , V_39 ? V_50 : 0 ) ;
F_21 ( V_49 ) ;
V_4 -> V_51 . V_52 . V_53 = V_39 ;
} else if ( F_22 ( V_2 ) || F_23 ( V_2 ) ) {
F_2 ( V_54 , V_39 ? V_55 : 0 ) ;
F_21 ( V_54 ) ;
} else if ( F_24 ( V_2 ) ) {
V_40 = F_3 ( V_56 ) & ~ V_57 ;
V_40 |= V_39 ? V_57 : 0 ;
F_2 ( V_56 , V_40 ) ;
F_21 ( V_56 ) ;
} else if ( F_25 ( V_2 ) || F_26 ( V_2 ) ) {
V_40 = V_39 ? F_27 ( V_55 ) :
F_28 ( V_55 ) ;
F_2 ( V_54 , V_40 ) ;
F_21 ( V_54 ) ;
} else if ( F_29 ( V_2 ) ) {
V_40 = V_39 ? F_27 ( V_58 ) :
F_28 ( V_58 ) ;
F_2 ( V_59 , V_40 ) ;
F_21 ( V_59 ) ;
} else {
return;
}
F_10 ( L_5 ,
V_39 ? L_6 : L_7 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_60 V_60 , int V_61 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_62 , V_63 , V_64 ;
switch ( V_60 ) {
T_3 V_65 , V_66 , V_67 ;
case V_68 :
V_65 = F_3 ( V_69 ) ;
V_66 = F_3 ( V_70 ) ;
V_62 = F_31 ( V_65 , V_66 , 0 , 0 ) ;
V_63 = F_31 ( V_65 , V_66 , 8 , 4 ) ;
break;
case V_71 :
V_65 = F_3 ( V_69 ) ;
V_66 = F_3 ( V_70 ) ;
V_62 = F_31 ( V_65 , V_66 , 16 , 8 ) ;
V_63 = F_31 ( V_65 , V_66 , 24 , 12 ) ;
break;
case V_72 :
V_66 = F_3 ( V_70 ) ;
V_67 = F_3 ( V_73 ) ;
V_62 = F_31 ( V_67 , V_66 , 0 , 16 ) ;
V_63 = F_31 ( V_67 , V_66 , 8 , 20 ) ;
break;
default:
return 0 ;
}
switch ( V_61 ) {
case 0 :
V_64 = V_62 ;
break;
case 1 :
V_64 = V_63 - V_62 ;
break;
case 2 :
V_64 = 512 - 1 - V_63 ;
break;
default:
return 0 ;
}
F_10 ( L_8 ,
F_32 ( V_60 ) , V_61 == 0 ? L_9 : L_10 ,
V_61 == 0 ? F_33 ( V_60 ) : F_34 ( V_60 , V_61 - 1 ) ,
V_64 ) ;
return V_64 ;
}
static int F_35 ( struct V_1 * V_2 , int V_61 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_65 = F_3 ( V_69 ) ;
int V_64 ;
V_64 = V_65 & 0x7f ;
if ( V_61 )
V_64 = ( ( V_65 >> V_74 ) & 0x7f ) - V_64 ;
F_10 ( L_11 , V_65 ,
V_61 ? L_12 : L_13 , V_64 ) ;
return V_64 ;
}
static int F_36 ( struct V_1 * V_2 , int V_61 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_65 = F_3 ( V_69 ) ;
int V_64 ;
V_64 = V_65 & 0x1ff ;
if ( V_61 )
V_64 = ( ( V_65 >> V_75 ) & 0x1ff ) - V_64 ;
V_64 >>= 1 ;
F_10 ( L_11 , V_65 ,
V_61 ? L_12 : L_13 , V_64 ) ;
return V_64 ;
}
static int F_37 ( struct V_1 * V_2 , int V_61 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_65 = F_3 ( V_69 ) ;
int V_64 ;
V_64 = V_65 & 0x7f ;
V_64 >>= 2 ;
F_10 ( L_11 , V_65 ,
V_61 ? L_12 : L_13 ,
V_64 ) ;
return V_64 ;
}
static unsigned long F_38 ( unsigned long V_76 ,
const struct V_77 * V_51 ,
int V_78 ,
int V_79 ,
unsigned long V_80 )
{
long V_81 , V_82 ;
V_81 = ( ( V_76 / 1000 ) * V_79 * V_80 ) /
1000 ;
V_81 = F_39 ( V_81 , V_51 -> V_83 ) ;
F_10 ( L_14 , V_81 ) ;
V_82 = V_78 - ( V_81 + V_51 -> V_84 ) ;
F_10 ( L_15 , V_82 ) ;
if ( V_82 > ( long ) V_51 -> V_85 )
V_82 = V_51 -> V_85 ;
if ( V_82 <= 0 )
V_82 = V_51 -> V_86 ;
if ( V_82 <= 8 )
V_82 = 8 ;
return V_82 ;
}
static struct V_87 * F_40 ( struct V_1 * V_2 )
{
struct V_87 * V_88 , * V_89 = NULL ;
F_41 (dev, crtc) {
if ( F_42 ( V_88 ) ) {
if ( V_89 )
return NULL ;
V_89 = V_88 ;
}
}
return V_89 ;
}
static void F_43 ( struct V_87 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_87 * V_88 ;
const struct V_32 * V_36 ;
T_1 V_91 ;
unsigned long V_51 ;
V_36 = F_8 ( F_44 ( V_2 ) , V_4 -> V_23 ,
V_4 -> V_13 , V_4 -> V_19 ) ;
if ( ! V_36 ) {
F_10 ( L_3 ) ;
F_19 ( V_4 , false ) ;
return;
}
V_88 = F_40 ( V_2 ) ;
if ( V_88 ) {
const struct V_92 * V_93 = & F_45 ( V_88 ) -> V_94 -> V_95 . V_93 ;
int V_79 = V_88 -> V_96 -> V_97 -> V_98 -> V_99 / 8 ;
int clock = V_93 -> V_100 ;
V_51 = F_38 ( clock , & V_101 ,
V_101 . V_78 ,
V_79 , V_36 -> V_102 ) ;
V_91 = F_3 ( V_103 ) ;
V_91 &= ~ V_104 ;
V_91 |= F_46 ( V_51 , V_105 ) ;
F_2 ( V_103 , V_91 ) ;
F_10 ( L_16 , V_91 ) ;
V_51 = F_38 ( clock , & V_106 ,
V_101 . V_78 ,
V_79 , V_36 -> V_107 ) ;
V_91 = F_3 ( V_56 ) ;
V_91 &= ~ V_108 ;
V_91 |= F_46 ( V_51 , V_109 ) ;
F_2 ( V_56 , V_91 ) ;
V_51 = F_38 ( clock , & V_110 ,
V_110 . V_78 ,
V_79 , V_36 -> V_111 ) ;
V_91 = F_3 ( V_56 ) ;
V_91 &= ~ V_112 ;
V_91 |= F_46 ( V_51 , V_113 ) ;
F_2 ( V_56 , V_91 ) ;
V_51 = F_38 ( clock , & V_114 ,
V_110 . V_78 ,
V_79 , V_36 -> V_115 ) ;
V_91 = F_3 ( V_56 ) ;
V_91 &= ~ V_116 ;
V_91 |= F_46 ( V_51 , V_117 ) ;
F_2 ( V_56 , V_91 ) ;
F_10 ( L_17 , V_91 ) ;
F_19 ( V_4 , true ) ;
} else {
F_19 ( V_4 , false ) ;
}
}
static bool F_47 ( struct V_1 * V_2 ,
int V_61 ,
const struct V_77 * V_118 ,
int V_119 ,
const struct V_77 * V_120 ,
int V_121 ,
int * V_122 ,
int * V_123 )
{
struct V_87 * V_88 ;
const struct V_92 * V_93 ;
int V_124 , V_125 , clock , V_79 ;
int V_126 , V_127 ;
int V_128 , V_129 ;
V_88 = F_48 ( V_2 , V_61 ) ;
if ( ! F_42 ( V_88 ) ) {
* V_123 = V_120 -> V_84 ;
* V_122 = V_118 -> V_84 ;
return false ;
}
V_93 = & F_45 ( V_88 ) -> V_94 -> V_95 . V_93 ;
clock = V_93 -> V_100 ;
V_124 = V_93 -> V_130 ;
V_125 = F_45 ( V_88 ) -> V_94 -> V_131 ;
V_79 = V_88 -> V_96 -> V_97 -> V_98 -> V_99 / 8 ;
V_128 = ( ( clock * V_79 / 1000 ) * V_119 ) / 1000 ;
V_129 = V_118 -> V_78 * V_118 -> V_83 - V_125 * 8 ;
if ( V_129 > 0 )
V_128 += V_129 ;
V_128 = F_39 ( V_128 , V_118 -> V_83 ) ;
* V_122 = V_128 + V_118 -> V_84 ;
if ( * V_122 > ( int ) V_118 -> V_85 )
* V_122 = V_118 -> V_85 ;
V_126 = F_49 ( V_124 * 1000 / clock , 1 ) ;
V_127 = ( V_121 / V_126 + 1000 ) / 1000 ;
V_128 = V_127 * V_88 -> V_120 -> V_97 -> V_132 * V_79 ;
V_129 = V_120 -> V_78 * V_120 -> V_83 - V_125 * 8 ;
if ( V_129 > 0 )
V_128 += V_129 ;
V_128 = F_39 ( V_128 , V_120 -> V_83 ) ;
* V_123 = V_128 + V_120 -> V_84 ;
if ( * V_123 > ( int ) V_120 -> V_85 )
* V_123 = ( int ) V_120 -> V_85 ;
return true ;
}
static bool F_50 ( struct V_1 * V_2 ,
int V_133 , int V_123 ,
const struct V_77 * V_118 ,
const struct V_77 * V_120 )
{
F_10 ( L_18 ,
V_133 , V_123 ) ;
if ( V_133 > V_118 -> V_85 ) {
F_10 ( L_19 ,
V_133 , V_118 -> V_85 ) ;
return false ;
}
if ( V_123 > V_120 -> V_85 ) {
F_10 ( L_20 ,
V_123 , V_120 -> V_85 ) ;
return false ;
}
if ( ! ( V_133 || V_123 ) ) {
F_10 ( L_21 ) ;
return false ;
}
return true ;
}
static bool F_51 ( struct V_1 * V_2 ,
int V_61 ,
int V_80 ,
const struct V_77 * V_118 ,
const struct V_77 * V_120 ,
int * V_133 , int * V_123 )
{
struct V_87 * V_88 ;
const struct V_92 * V_93 ;
int V_125 , V_124 , V_79 , clock ;
unsigned long V_126 ;
int V_127 , V_134 ;
int V_135 , V_136 ;
int V_128 ;
if ( ! V_80 ) {
* V_133 = * V_123 = 0 ;
return false ;
}
V_88 = F_48 ( V_2 , V_61 ) ;
V_93 = & F_45 ( V_88 ) -> V_94 -> V_95 . V_93 ;
clock = V_93 -> V_100 ;
V_124 = V_93 -> V_130 ;
V_125 = F_45 ( V_88 ) -> V_94 -> V_131 ;
V_79 = V_88 -> V_96 -> V_97 -> V_98 -> V_99 / 8 ;
V_126 = F_49 ( V_124 * 1000 / clock , 1 ) ;
V_127 = ( V_80 / V_126 + 1000 ) / 1000 ;
V_134 = V_125 * V_79 ;
V_135 = ( ( clock * V_79 / 1000 ) * V_80 ) / 1000 ;
V_136 = V_127 * V_134 ;
V_128 = F_39 ( F_52 ( V_135 , V_136 ) , V_118 -> V_83 ) ;
* V_133 = V_128 + V_118 -> V_84 ;
V_128 = V_127 * V_79 * V_88 -> V_120 -> V_97 -> V_132 ;
V_128 = F_39 ( V_128 , V_120 -> V_83 ) ;
* V_123 = V_128 + V_120 -> V_84 ;
return F_50 ( V_2 ,
* V_133 , * V_123 ,
V_118 , V_120 ) ;
}
static void F_53 ( struct V_137 * V_88 ,
const struct V_138 * V_51 )
{
struct V_3 * V_4 = F_54 ( V_88 -> V_95 . V_2 ) ;
enum V_60 V_60 = V_88 -> V_60 ;
F_2 ( F_55 ( V_60 ) ,
( V_51 -> V_139 [ V_60 ] . V_120 << V_140 ) |
( V_51 -> V_139 [ V_60 ] . V_141 [ 1 ] << F_56 ( 1 ) ) |
( V_51 -> V_139 [ V_60 ] . V_141 [ 0 ] << F_56 ( 0 ) ) |
( V_51 -> V_139 [ V_60 ] . V_96 << V_142 ) ) ;
F_2 ( V_103 ,
F_46 ( V_51 -> V_143 . V_61 , V_105 ) |
F_46 ( V_51 -> V_60 [ V_71 ] . V_120 , V_144 ) |
F_57 ( V_51 -> V_60 [ V_71 ] . V_96 , V_145 ) |
F_57 ( V_51 -> V_60 [ V_68 ] . V_96 , V_146 ) ) ;
F_2 ( V_147 ,
F_57 ( V_51 -> V_60 [ V_68 ] . V_141 [ 1 ] , V_148 ) |
F_46 ( V_51 -> V_60 [ V_68 ] . V_120 , V_149 ) |
F_57 ( V_51 -> V_60 [ V_68 ] . V_141 [ 0 ] , V_150 ) ) ;
F_2 ( V_56 ,
F_46 ( V_51 -> V_143 . V_120 , V_109 ) ) ;
if ( F_58 ( V_4 ) ) {
F_2 ( V_151 ,
F_57 ( V_51 -> V_60 [ V_71 ] . V_141 [ 1 ] , V_152 ) |
F_57 ( V_51 -> V_60 [ V_71 ] . V_141 [ 0 ] , V_153 ) ) ;
F_2 ( V_154 ,
F_57 ( V_51 -> V_60 [ V_72 ] . V_141 [ 1 ] , V_155 ) |
F_57 ( V_51 -> V_60 [ V_72 ] . V_141 [ 0 ] , V_156 ) ) ;
F_2 ( V_157 ,
F_57 ( V_51 -> V_60 [ V_72 ] . V_96 , V_158 ) |
F_46 ( V_51 -> V_60 [ V_72 ] . V_120 , V_159 ) ) ;
F_2 ( V_160 ,
F_46 ( V_51 -> V_143 . V_61 >> 9 , V_161 ) |
F_46 ( V_51 -> V_60 [ V_72 ] . V_141 [ 1 ] >> 8 , V_162 ) |
F_46 ( V_51 -> V_60 [ V_72 ] . V_141 [ 0 ] >> 8 , V_163 ) |
F_46 ( V_51 -> V_60 [ V_72 ] . V_96 >> 8 , V_164 ) |
F_46 ( V_51 -> V_60 [ V_71 ] . V_141 [ 1 ] >> 8 , V_165 ) |
F_46 ( V_51 -> V_60 [ V_71 ] . V_141 [ 0 ] >> 8 , V_166 ) |
F_46 ( V_51 -> V_60 [ V_71 ] . V_96 >> 8 , V_167 ) |
F_46 ( V_51 -> V_60 [ V_68 ] . V_141 [ 1 ] >> 8 , V_168 ) |
F_46 ( V_51 -> V_60 [ V_68 ] . V_141 [ 0 ] >> 8 , V_169 ) |
F_46 ( V_51 -> V_60 [ V_68 ] . V_96 >> 8 , V_170 ) ) ;
} else {
F_2 ( V_171 ,
F_57 ( V_51 -> V_60 [ V_71 ] . V_141 [ 1 ] , V_152 ) |
F_57 ( V_51 -> V_60 [ V_71 ] . V_141 [ 0 ] , V_153 ) ) ;
F_2 ( V_160 ,
F_46 ( V_51 -> V_143 . V_61 >> 9 , V_161 ) |
F_46 ( V_51 -> V_60 [ V_71 ] . V_141 [ 1 ] >> 8 , V_165 ) |
F_46 ( V_51 -> V_60 [ V_71 ] . V_141 [ 0 ] >> 8 , V_166 ) |
F_46 ( V_51 -> V_60 [ V_71 ] . V_96 >> 8 , V_167 ) |
F_46 ( V_51 -> V_60 [ V_68 ] . V_141 [ 1 ] >> 8 , V_168 ) |
F_46 ( V_51 -> V_60 [ V_68 ] . V_141 [ 0 ] >> 8 , V_169 ) |
F_46 ( V_51 -> V_60 [ V_68 ] . V_96 >> 8 , V_170 ) ) ;
}
F_2 ( V_172 , 0 ) ;
F_2 ( V_173 , 0 ) ;
F_2 ( V_174 , 0 ) ;
F_2 ( V_175 , 0 ) ;
F_21 ( V_103 ) ;
}
static unsigned int F_59 ( unsigned int V_176 ,
unsigned int V_177 ,
unsigned int V_178 ,
unsigned int V_179 ,
unsigned int V_36 )
{
unsigned int V_180 ;
V_180 = ( V_36 * V_176 ) / ( V_177 * 10000 ) ;
V_180 = ( V_180 + 1 ) * V_178 * V_179 ;
V_180 = F_39 ( V_180 , 64 ) ;
return V_180 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_51 . V_181 [ V_182 ] = 3 ;
V_4 -> V_51 . V_183 = V_182 ;
if ( F_58 ( V_4 ) ) {
V_4 -> V_51 . V_181 [ V_184 ] = 12 ;
V_4 -> V_51 . V_181 [ V_185 ] = 33 ;
V_4 -> V_51 . V_183 = V_185 ;
}
}
static T_4 F_61 ( struct V_186 * V_61 ,
struct V_137 * V_88 ,
const struct V_187 * V_97 ,
int V_188 )
{
struct V_3 * V_4 = F_54 ( V_61 -> V_95 . V_2 ) ;
int clock , V_124 , V_79 , V_189 , V_51 ;
if ( V_4 -> V_51 . V_181 [ V_188 ] == 0 )
return V_190 ;
if ( ! V_97 -> V_191 )
return 0 ;
V_79 = F_62 ( V_97 -> V_95 . V_98 -> V_192 , 0 ) ;
clock = V_88 -> V_94 -> V_95 . V_93 . V_100 ;
V_124 = V_88 -> V_94 -> V_95 . V_93 . V_130 ;
V_189 = V_88 -> V_94 -> V_131 ;
if ( F_63 ( V_124 == 0 ) )
V_124 = 1 ;
if ( V_61 -> V_95 . type == V_193 ) {
V_51 = 63 ;
} else {
V_51 = F_59 ( clock , V_124 , V_189 , V_79 ,
V_4 -> V_51 . V_181 [ V_188 ] * 10 ) ;
}
return F_64 ( int , V_51 , V_190 ) ;
}
static void F_65 ( struct V_137 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_95 . V_2 ;
struct V_194 * V_195 = & V_88 -> V_195 ;
struct V_186 * V_61 ;
unsigned int V_196 = 0 ;
const int V_78 = 512 - 1 ;
int V_197 , V_198 = V_78 ;
F_66 (dev, crtc, plane) {
struct V_187 * V_97 =
F_67 ( V_61 -> V_95 . V_97 ) ;
if ( V_61 -> V_95 . type == V_193 )
continue;
if ( V_97 -> V_191 ) {
V_195 -> V_199 ++ ;
V_196 += F_62 ( V_97 -> V_95 . V_98 -> V_192 , 0 ) ;
}
}
F_66 (dev, crtc, plane) {
struct V_187 * V_97 =
F_67 ( V_61 -> V_95 . V_97 ) ;
unsigned int V_200 ;
if ( V_61 -> V_95 . type == V_193 ) {
V_61 -> V_51 . V_78 = 63 ;
continue;
}
if ( ! V_97 -> V_191 ) {
V_61 -> V_51 . V_78 = 0 ;
continue;
}
V_200 = F_62 ( V_97 -> V_95 . V_98 -> V_192 , 0 ) ;
V_61 -> V_51 . V_78 = V_78 * V_200 / V_196 ;
V_198 -= V_61 -> V_51 . V_78 ;
}
V_197 = F_39 ( V_198 , V_195 -> V_199 ? : 1 ) ;
F_66 (dev, crtc, plane) {
int V_201 ;
if ( V_198 == 0 )
break;
if ( V_61 -> V_95 . type == V_193 )
continue;
if ( V_61 -> V_51 . V_78 == 0 &&
V_195 -> V_199 )
continue;
V_201 = F_52 ( V_197 , V_198 ) ;
V_61 -> V_51 . V_78 += V_201 ;
V_198 -= V_201 ;
}
F_63 ( V_198 != 0 ) ;
}
static void F_68 ( struct V_137 * V_88 )
{
struct V_194 * V_195 = & V_88 -> V_195 ;
int V_188 ;
for ( V_188 = 0 ; V_188 < V_195 -> V_202 ; V_188 ++ ) {
struct V_1 * V_2 = V_88 -> V_95 . V_2 ;
const int V_203 = F_69 ( V_2 ) -> V_204 * 512 - 1 ;
struct V_186 * V_61 ;
V_195 -> V_143 [ V_188 ] . V_61 = V_203 - V_195 -> V_143 [ V_188 ] . V_61 ;
V_195 -> V_143 [ V_188 ] . V_120 = 63 - V_195 -> V_143 [ V_188 ] . V_120 ;
F_66 (dev, crtc, plane) {
switch ( V_61 -> V_95 . type ) {
int V_141 ;
case V_193 :
V_195 -> V_51 [ V_188 ] . V_120 = V_61 -> V_51 . V_78 -
V_195 -> V_51 [ V_188 ] . V_120 ;
break;
case V_205 :
V_195 -> V_51 [ V_188 ] . V_96 = V_61 -> V_51 . V_78 -
V_195 -> V_51 [ V_188 ] . V_96 ;
break;
case V_206 :
V_141 = V_61 -> V_61 ;
V_195 -> V_51 [ V_188 ] . V_141 [ V_141 ] = V_61 -> V_51 . V_78 -
V_195 -> V_51 [ V_188 ] . V_141 [ V_141 ] ;
break;
}
}
}
}
static void F_70 ( struct V_137 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_95 . V_2 ;
struct V_194 * V_195 = & V_88 -> V_195 ;
struct V_186 * V_61 ;
int V_203 = F_69 ( V_2 ) -> V_204 * 512 - 1 ;
int V_188 ;
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
V_195 -> V_53 = V_88 -> V_60 != V_72 && V_88 -> V_51 . V_207 ;
V_195 -> V_202 = F_54 ( V_2 ) -> V_51 . V_183 + 1 ;
V_195 -> V_199 = 0 ;
F_65 ( V_88 ) ;
if ( V_195 -> V_199 != 1 )
V_195 -> V_53 = false ;
if ( V_195 -> V_53 ) {
for ( V_188 = 0 ; V_188 < V_195 -> V_202 ; V_188 ++ ) {
V_195 -> V_143 [ V_188 ] . V_61 = V_203 ;
V_195 -> V_143 [ V_188 ] . V_120 = 63 ;
}
}
F_66 (dev, crtc, plane) {
struct V_187 * V_97 =
F_67 ( V_61 -> V_95 . V_97 ) ;
if ( ! V_97 -> V_191 )
continue;
for ( V_188 = 0 ; V_188 < V_195 -> V_202 ; V_188 ++ ) {
int V_51 = F_61 ( V_61 , V_88 , V_97 , V_188 ) ;
int V_85 = V_61 -> V_95 . type == V_193 ? 63 : 511 ;
if ( F_63 ( V_188 == 0 && V_51 > V_85 ) )
V_51 = V_85 ;
if ( V_51 > V_61 -> V_51 . V_78 )
break;
switch ( V_61 -> V_95 . type ) {
int V_141 ;
case V_193 :
V_195 -> V_51 [ V_188 ] . V_120 = V_51 ;
break;
case V_205 :
V_195 -> V_51 [ V_188 ] . V_96 = V_51 ;
break;
case V_206 :
V_141 = V_61 -> V_61 ;
V_195 -> V_51 [ V_188 ] . V_141 [ V_141 ] = V_51 ;
break;
}
}
V_195 -> V_202 = V_188 ;
if ( ! V_195 -> V_53 )
continue;
switch ( V_61 -> V_95 . type ) {
int V_141 , V_188 ;
case V_193 :
for ( V_188 = 0 ; V_188 < V_195 -> V_202 ; V_188 ++ )
V_195 -> V_143 [ V_188 ] . V_120 =
V_195 -> V_51 [ V_188 ] . V_120 ;
break;
case V_205 :
for ( V_188 = 0 ; V_188 < V_195 -> V_202 ; V_188 ++ )
V_195 -> V_143 [ V_188 ] . V_61 =
F_52 ( V_195 -> V_143 [ V_188 ] . V_61 ,
V_195 -> V_51 [ V_188 ] . V_96 ) ;
break;
case V_206 :
V_141 = V_61 -> V_61 ;
for ( V_188 = 0 ; V_188 < V_195 -> V_202 ; V_188 ++ )
V_195 -> V_143 [ V_188 ] . V_61 =
F_52 ( V_195 -> V_143 [ V_188 ] . V_61 ,
V_195 -> V_51 [ V_188 ] . V_141 [ V_141 ] ) ;
break;
}
}
for ( V_188 = V_195 -> V_202 ; V_188 < F_54 ( V_2 ) -> V_51 . V_183 + 1 ; V_188 ++ ) {
memset ( & V_195 -> V_51 [ V_188 ] , 0 , sizeof( V_195 -> V_51 [ V_188 ] ) ) ;
memset ( & V_195 -> V_143 [ V_188 ] , 0 , sizeof( V_195 -> V_143 [ V_188 ] ) ) ;
}
F_68 ( V_88 ) ;
}
static void F_71 ( struct V_137 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_95 . V_2 ;
struct V_3 * V_4 = F_54 ( V_2 ) ;
struct V_186 * V_61 ;
int V_62 = 0 , V_63 = 0 , V_78 = 0 ;
F_66 (dev, crtc, plane) {
if ( V_61 -> V_95 . type == V_193 ) {
F_63 ( V_61 -> V_51 . V_78 != 63 ) ;
continue;
}
if ( V_61 -> V_95 . type == V_205 )
V_62 = V_61 -> V_51 . V_78 ;
else if ( V_61 -> V_61 == 0 )
V_63 = V_62 + V_61 -> V_51 . V_78 ;
else
V_78 = V_63 + V_61 -> V_51 . V_78 ;
}
F_63 ( V_78 != 512 - 1 ) ;
F_10 ( L_22 ,
F_32 ( V_88 -> V_60 ) , V_62 ,
V_63 , V_78 ) ;
switch ( V_88 -> V_60 ) {
T_3 V_65 , V_66 , V_67 ;
case V_68 :
V_65 = F_3 ( V_69 ) ;
V_66 = F_3 ( V_70 ) ;
V_65 &= ~ ( F_72 ( V_150 , 0xff ) |
F_72 ( V_148 , 0xff ) ) ;
V_65 |= ( F_72 ( V_150 , V_62 ) |
F_72 ( V_148 , V_63 ) ) ;
V_66 &= ~ ( F_72 ( V_169 , 0x1 ) |
F_72 ( V_168 , 0x1 ) ) ;
V_66 |= ( F_72 ( V_169 , V_62 >> 8 ) |
F_72 ( V_168 , V_63 >> 8 ) ) ;
F_2 ( V_69 , V_65 ) ;
F_2 ( V_70 , V_66 ) ;
break;
case V_71 :
V_65 = F_3 ( V_69 ) ;
V_66 = F_3 ( V_70 ) ;
V_65 &= ~ ( F_72 ( V_153 , 0xff ) |
F_72 ( V_152 , 0xff ) ) ;
V_65 |= ( F_72 ( V_153 , V_62 ) |
F_72 ( V_152 , V_63 ) ) ;
V_66 &= ~ ( F_72 ( V_166 , 0xff ) |
F_72 ( V_165 , 0xff ) ) ;
V_66 |= ( F_72 ( V_166 , V_62 >> 8 ) |
F_72 ( V_165 , V_63 >> 8 ) ) ;
F_2 ( V_69 , V_65 ) ;
F_2 ( V_70 , V_66 ) ;
break;
case V_72 :
V_67 = F_3 ( V_73 ) ;
V_66 = F_3 ( V_70 ) ;
V_67 &= ~ ( F_72 ( V_156 , 0xff ) |
F_72 ( V_155 , 0xff ) ) ;
V_67 |= ( F_72 ( V_156 , V_62 ) |
F_72 ( V_155 , V_63 ) ) ;
V_66 &= ~ ( F_72 ( V_163 , 0xff ) |
F_72 ( V_162 , 0xff ) ) ;
V_66 |= ( F_72 ( V_163 , V_62 >> 8 ) |
F_72 ( V_162 , V_63 >> 8 ) ) ;
F_2 ( V_73 , V_67 ) ;
F_2 ( V_70 , V_66 ) ;
break;
default:
break;
}
}
static void F_73 ( struct V_1 * V_2 ,
struct V_138 * V_51 )
{
struct V_137 * V_88 ;
int V_208 = 0 ;
V_51 -> V_188 = F_54 ( V_2 ) -> V_51 . V_183 ;
V_51 -> V_53 = true ;
F_74 (dev, crtc) {
const struct V_194 * V_195 = & V_88 -> V_195 ;
if ( ! V_88 -> V_209 )
continue;
if ( ! V_195 -> V_53 )
V_51 -> V_53 = false ;
V_208 ++ ;
V_51 -> V_188 = F_64 ( int , V_51 -> V_188 , V_195 -> V_202 - 1 ) ;
}
if ( V_208 != 1 )
V_51 -> V_53 = false ;
if ( V_208 > 1 )
V_51 -> V_188 = V_182 ;
F_74 (dev, crtc) {
struct V_194 * V_195 = & V_88 -> V_195 ;
enum V_60 V_60 = V_88 -> V_60 ;
if ( ! V_88 -> V_209 )
continue;
V_51 -> V_60 [ V_60 ] = V_195 -> V_51 [ V_51 -> V_188 ] ;
if ( V_51 -> V_53 )
V_51 -> V_143 = V_195 -> V_143 [ V_51 -> V_188 ] ;
V_51 -> V_139 [ V_60 ] . V_96 = V_210 | 2 ;
V_51 -> V_139 [ V_60 ] . V_141 [ 0 ] = V_210 | 2 ;
V_51 -> V_139 [ V_60 ] . V_141 [ 1 ] = V_210 | 2 ;
V_51 -> V_139 [ V_60 ] . V_120 = V_210 | 2 ;
}
}
static void F_75 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_137 * V_137 = F_45 ( V_88 ) ;
enum V_60 V_60 = V_137 -> V_60 ;
struct V_138 V_51 = {} ;
F_70 ( V_137 ) ;
F_73 ( V_2 , & V_51 ) ;
if ( memcmp ( & V_4 -> V_51 . V_52 , & V_51 , sizeof( V_51 ) ) == 0 ) {
F_71 ( V_137 ) ;
return;
}
if ( V_51 . V_188 < V_185 &&
V_4 -> V_51 . V_52 . V_188 >= V_185 )
F_11 ( V_4 , false ) ;
if ( V_51 . V_188 < V_184 &&
V_4 -> V_51 . V_52 . V_188 >= V_184 )
F_18 ( V_4 , false ) ;
if ( ! V_51 . V_53 && V_4 -> V_51 . V_52 . V_53 )
F_19 ( V_4 , false ) ;
F_71 ( V_137 ) ;
F_53 ( V_137 , & V_51 ) ;
F_10 ( L_23
L_24 ,
F_32 ( V_60 ) , V_51 . V_60 [ V_60 ] . V_96 , V_51 . V_60 [ V_60 ] . V_120 ,
V_51 . V_60 [ V_60 ] . V_141 [ 0 ] , V_51 . V_60 [ V_60 ] . V_141 [ 1 ] ,
V_51 . V_143 . V_61 , V_51 . V_143 . V_120 , V_51 . V_188 , V_51 . V_53 ) ;
if ( V_51 . V_53 && ! V_4 -> V_51 . V_52 . V_53 )
F_19 ( V_4 , true ) ;
if ( V_51 . V_188 >= V_184 &&
V_4 -> V_51 . V_52 . V_188 < V_184 )
F_18 ( V_4 , true ) ;
if ( V_51 . V_188 >= V_185 &&
V_4 -> V_51 . V_52 . V_188 < V_185 )
F_11 ( V_4 , true ) ;
V_4 -> V_51 . V_52 = V_51 ;
}
static void F_76 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
static const int V_211 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_212 , V_213 , V_214 , V_215 ;
int V_216 , V_107 ;
unsigned int V_89 = 0 ;
bool V_217 ;
if ( F_47 ( V_2 , V_68 ,
& V_218 , V_219 ,
& V_220 , V_219 ,
& V_212 , & V_214 ) )
V_89 |= 1 << V_68 ;
if ( F_47 ( V_2 , V_71 ,
& V_218 , V_219 ,
& V_220 , V_219 ,
& V_213 , & V_215 ) )
V_89 |= 1 << V_71 ;
if ( F_77 ( V_89 ) &&
F_51 ( V_2 , F_78 ( V_89 ) - 1 ,
V_211 ,
& V_218 ,
& V_220 ,
& V_216 , & V_107 ) ) {
V_217 = true ;
} else {
V_217 = false ;
F_19 ( V_4 , false ) ;
V_216 = V_107 = 0 ;
}
F_10 ( L_25
L_26 ,
V_212 , V_214 ,
V_213 , V_215 ,
V_216 , V_107 ) ;
F_2 ( V_103 ,
F_46 ( V_216 , V_105 ) |
F_46 ( V_215 , V_144 ) |
F_46 ( V_213 , V_145 ) |
F_46 ( V_212 , V_146 ) ) ;
F_2 ( V_147 ,
( F_3 ( V_147 ) & ~ V_221 ) |
F_46 ( V_214 , V_149 ) ) ;
F_2 ( V_56 ,
( F_3 ( V_56 ) & ~ ( V_222 | V_108 ) ) |
F_46 ( V_107 , V_109 ) ) ;
if ( V_217 )
F_19 ( V_4 , true ) ;
}
static void F_79 ( struct V_87 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_87 * V_88 ;
int V_223 = 1 ;
int V_107 = 16 ;
bool V_217 ;
V_88 = F_40 ( V_2 ) ;
if ( V_88 ) {
static const int V_211 = 12000 ;
const struct V_92 * V_93 = & F_45 ( V_88 ) -> V_94 -> V_95 . V_93 ;
int clock = V_93 -> V_100 ;
int V_124 = V_93 -> V_130 ;
int V_125 = F_45 ( V_88 ) -> V_94 -> V_131 ;
int V_79 = V_88 -> V_96 -> V_97 -> V_98 -> V_99 / 8 ;
unsigned long V_126 ;
int V_128 ;
V_126 = F_49 ( V_124 * 1000 / clock , 1 ) ;
V_128 = ( ( ( V_211 / V_126 ) + 1000 ) / 1000 ) *
V_79 * V_125 ;
V_128 = F_39 ( V_128 , V_224 ) ;
V_223 = V_225 - V_128 ;
if ( V_223 < 0 )
V_223 = 1 ;
V_223 &= 0x1ff ;
F_10 ( L_27 ,
V_128 , V_223 ) ;
V_128 = ( ( ( V_211 / V_126 ) + 1000 ) / 1000 ) *
V_79 * V_88 -> V_120 -> V_97 -> V_132 ;
V_128 = F_39 ( V_128 ,
V_226 . V_83 ) ;
V_107 = V_226 . V_78 -
( V_128 + V_226 . V_84 ) ;
if ( V_107 > V_226 . V_85 )
V_107 = V_226 . V_85 ;
F_10 ( L_28
L_29 , V_223 , V_107 ) ;
V_217 = true ;
} else {
V_217 = false ;
F_19 ( V_4 , false ) ;
}
F_10 ( L_30 ,
V_223 ) ;
F_2 ( V_103 , F_46 ( V_223 , V_105 ) |
F_46 ( 8 , V_144 ) |
F_46 ( 8 , V_145 ) |
F_46 ( 8 , V_146 ) ) ;
F_2 ( V_147 , F_46 ( 8 , V_149 ) |
F_46 ( 8 , V_227 ) ) ;
F_2 ( V_56 , F_46 ( V_107 , V_109 ) ) ;
if ( V_217 )
F_19 ( V_4 , true ) ;
}
static void F_80 ( struct V_87 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_77 * V_228 ;
T_3 V_229 ;
T_3 V_230 ;
int V_231 , V_223 = 1 ;
int V_78 ;
int V_212 , V_213 ;
struct V_87 * V_88 , * V_89 = NULL ;
if ( F_26 ( V_2 ) )
V_228 = & V_232 ;
else if ( ! F_81 ( V_2 ) )
V_228 = & V_233 ;
else
V_228 = & V_234 ;
V_78 = V_4 -> V_118 . V_235 ( V_2 , 0 ) ;
V_88 = F_48 ( V_2 , 0 ) ;
if ( F_42 ( V_88 ) ) {
const struct V_92 * V_93 ;
int V_236 = V_88 -> V_96 -> V_97 -> V_98 -> V_99 / 8 ;
if ( F_81 ( V_2 ) )
V_236 = 4 ;
V_93 = & F_45 ( V_88 ) -> V_94 -> V_95 . V_93 ;
V_212 = F_38 ( V_93 -> V_100 ,
V_228 , V_78 , V_236 ,
V_219 ) ;
V_89 = V_88 ;
} else {
V_212 = V_78 - V_228 -> V_84 ;
if ( V_212 > ( long ) V_228 -> V_85 )
V_212 = V_228 -> V_85 ;
}
if ( F_81 ( V_2 ) )
V_228 = & V_237 ;
V_78 = V_4 -> V_118 . V_235 ( V_2 , 1 ) ;
V_88 = F_48 ( V_2 , 1 ) ;
if ( F_42 ( V_88 ) ) {
const struct V_92 * V_93 ;
int V_236 = V_88 -> V_96 -> V_97 -> V_98 -> V_99 / 8 ;
if ( F_81 ( V_2 ) )
V_236 = 4 ;
V_93 = & F_45 ( V_88 ) -> V_94 -> V_95 . V_93 ;
V_213 = F_38 ( V_93 -> V_100 ,
V_228 , V_78 , V_236 ,
V_219 ) ;
if ( V_89 == NULL )
V_89 = V_88 ;
else
V_89 = NULL ;
} else {
V_213 = V_78 - V_228 -> V_84 ;
if ( V_213 > ( long ) V_228 -> V_85 )
V_213 = V_228 -> V_85 ;
}
F_10 ( L_31 , V_212 , V_213 ) ;
if ( F_29 ( V_2 ) && V_89 ) {
struct V_238 * V_239 ;
V_239 = F_82 ( V_89 -> V_96 -> V_97 -> V_98 ) ;
if ( V_239 -> V_240 == V_241 )
V_89 = NULL ;
}
V_231 = 2 ;
F_19 ( V_4 , false ) ;
if ( F_83 ( V_2 ) && V_89 ) {
static const int V_211 = 6000 ;
const struct V_92 * V_93 = & F_45 ( V_89 ) -> V_94 -> V_95 . V_93 ;
int clock = V_93 -> V_100 ;
int V_124 = V_93 -> V_130 ;
int V_125 = F_45 ( V_89 ) -> V_94 -> V_131 ;
int V_79 = V_89 -> V_96 -> V_97 -> V_98 -> V_99 / 8 ;
unsigned long V_126 ;
int V_128 ;
V_126 = F_49 ( V_124 * 1000 / clock , 1 ) ;
V_128 = ( ( ( V_211 / V_126 ) + 1000 ) / 1000 ) *
V_79 * V_125 ;
V_128 = F_39 ( V_128 , V_228 -> V_83 ) ;
F_10 ( L_32 , V_128 ) ;
V_223 = V_228 -> V_78 - V_128 ;
if ( V_223 < 0 )
V_223 = 1 ;
if ( F_25 ( V_2 ) || F_26 ( V_2 ) )
F_2 ( V_54 ,
V_242 | ( V_223 & 0xff ) ) ;
else if ( F_29 ( V_2 ) )
F_2 ( V_54 , V_223 & 0x3f ) ;
}
F_10 ( L_33 ,
V_212 , V_213 , V_231 , V_223 ) ;
V_229 = ( ( V_213 & 0x3f ) << 16 ) | ( V_212 & 0x3f ) ;
V_230 = ( V_231 & 0x1f ) ;
V_229 = V_229 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_230 = V_230 | ( 1 << 8 ) ;
F_2 ( V_243 , V_229 ) ;
F_2 ( V_244 , V_230 ) ;
if ( V_89 )
F_19 ( V_4 , true ) ;
}
static void F_84 ( struct V_87 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_87 * V_88 ;
const struct V_92 * V_93 ;
T_3 V_229 ;
int V_212 ;
V_88 = F_40 ( V_2 ) ;
if ( V_88 == NULL )
return;
V_93 = & F_45 ( V_88 ) -> V_94 -> V_95 . V_93 ;
V_212 = F_38 ( V_93 -> V_100 ,
& V_245 ,
V_4 -> V_118 . V_235 ( V_2 , 0 ) ,
4 , V_219 ) ;
V_229 = F_3 ( V_243 ) & ~ 0xfff ;
V_229 |= ( 3 << 8 ) | V_212 ;
F_10 ( L_34 , V_212 ) ;
F_2 ( V_243 , V_229 ) ;
}
T_3 F_85 ( const struct V_246 * V_247 )
{
T_3 V_176 ;
V_176 = V_247 -> V_95 . V_93 . V_100 ;
if ( V_247 -> V_248 . V_89 ) {
T_5 V_249 , V_250 , V_251 , V_252 ;
T_3 V_253 = V_247 -> V_248 . V_64 ;
V_249 = V_247 -> V_131 ;
V_250 = V_247 -> V_254 ;
V_251 = ( V_253 >> 16 ) & 0xFFFF ;
V_252 = V_253 & 0xFFFF ;
if ( V_249 < V_251 )
V_249 = V_251 ;
if ( V_250 < V_252 )
V_250 = V_252 ;
V_176 = F_86 ( ( T_5 ) V_176 * V_249 * V_250 ,
V_251 * V_252 ) ;
}
return V_176 ;
}
static T_3 F_87 ( T_3 V_176 , T_6 V_179 ,
T_3 V_36 )
{
T_5 V_180 ;
if ( F_88 ( V_36 == 0 , L_35 ) )
return V_255 ;
V_180 = ( T_5 ) V_176 * V_179 * V_36 ;
V_180 = F_89 ( V_180 , 64 * 10000 ) + 2 ;
return V_180 ;
}
static T_3 F_90 ( T_3 V_176 , T_3 V_177 ,
T_3 V_178 , T_6 V_179 ,
T_3 V_36 )
{
T_3 V_180 ;
if ( F_88 ( V_36 == 0 , L_35 ) )
return V_255 ;
V_180 = ( V_36 * V_176 ) / ( V_177 * 10000 ) ;
V_180 = ( V_180 + 1 ) * V_178 * V_179 ;
V_180 = F_39 ( V_180 , 64 ) + 2 ;
return V_180 ;
}
static T_3 F_91 ( T_3 V_256 , T_3 V_178 ,
T_6 V_179 )
{
return F_39 ( V_256 * 64 , V_178 * V_179 ) + 2 ;
}
static T_3 F_92 ( const struct V_246 * V_257 ,
const struct V_187 * V_258 ,
T_3 V_259 ,
bool V_260 )
{
int V_261 = V_258 -> V_95 . V_98 ? V_258 -> V_95 . V_98 -> V_99 / 8 : 0 ;
T_3 V_262 , V_263 ;
if ( ! V_257 -> V_95 . V_209 || ! V_258 -> V_191 )
return 0 ;
V_262 = F_87 ( F_85 ( V_257 ) , V_261 , V_259 ) ;
if ( ! V_260 )
return V_262 ;
V_263 = F_90 ( F_85 ( V_257 ) ,
V_257 -> V_95 . V_93 . V_130 ,
F_93 ( & V_258 -> V_264 ) ,
V_261 ,
V_259 ) ;
return F_52 ( V_262 , V_263 ) ;
}
static T_3 F_94 ( const struct V_246 * V_257 ,
const struct V_187 * V_258 ,
T_3 V_259 )
{
int V_261 = V_258 -> V_95 . V_98 ? V_258 -> V_95 . V_98 -> V_99 / 8 : 0 ;
T_3 V_262 , V_263 ;
if ( ! V_257 -> V_95 . V_209 || ! V_258 -> V_191 )
return 0 ;
V_262 = F_87 ( F_85 ( V_257 ) , V_261 , V_259 ) ;
V_263 = F_90 ( F_85 ( V_257 ) ,
V_257 -> V_95 . V_93 . V_130 ,
F_93 ( & V_258 -> V_264 ) ,
V_261 ,
V_259 ) ;
return F_52 ( V_262 , V_263 ) ;
}
static T_3 F_95 ( const struct V_246 * V_257 ,
const struct V_187 * V_258 ,
T_3 V_259 )
{
int V_261 = V_258 -> V_95 . V_98 ? V_258 -> V_95 . V_98 -> V_99 / 8 : 0 ;
if ( ! V_257 -> V_95 . V_209 || ! V_258 -> V_191 )
return 0 ;
return F_90 ( F_85 ( V_257 ) ,
V_257 -> V_95 . V_93 . V_130 ,
F_93 ( & V_258 -> V_264 ) ,
V_261 ,
V_259 ) ;
}
static T_3 F_96 ( const struct V_246 * V_257 ,
const struct V_187 * V_258 ,
T_3 V_256 )
{
int V_261 = V_258 -> V_95 . V_98 ? V_258 -> V_95 . V_98 -> V_99 / 8 : 0 ;
if ( ! V_257 -> V_95 . V_209 || ! V_258 -> V_191 )
return 0 ;
return F_91 ( V_256 , F_93 ( & V_258 -> V_264 ) , V_261 ) ;
}
static unsigned int F_97 ( const struct V_1 * V_2 )
{
if ( F_69 ( V_2 ) -> V_265 >= 8 )
return 3072 ;
else if ( F_69 ( V_2 ) -> V_265 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_98 ( const struct V_1 * V_2 ,
int V_188 , bool V_266 )
{
if ( F_69 ( V_2 ) -> V_265 >= 8 )
return V_188 == 0 ? 255 : 2047 ;
else if ( F_69 ( V_2 ) -> V_265 >= 7 )
return V_188 == 0 ? 127 : 1023 ;
else if ( ! V_266 )
return V_188 == 0 ? 127 : 511 ;
else
return V_188 == 0 ? 63 : 255 ;
}
static unsigned int F_99 ( const struct V_1 * V_2 ,
int V_188 )
{
if ( F_69 ( V_2 ) -> V_265 >= 7 )
return V_188 == 0 ? 63 : 255 ;
else
return V_188 == 0 ? 31 : 63 ;
}
static unsigned int F_100 ( const struct V_1 * V_2 )
{
if ( F_69 ( V_2 ) -> V_265 >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_101 ( const struct V_1 * V_2 ,
int V_188 ,
const struct V_267 * V_94 ,
enum V_268 V_269 ,
bool V_266 )
{
unsigned int V_78 = F_97 ( V_2 ) ;
if ( V_266 && ! V_94 -> V_270 )
return 0 ;
if ( V_188 == 0 || V_94 -> V_271 > 1 ) {
V_78 /= F_69 ( V_2 ) -> V_204 ;
if ( F_69 ( V_2 ) -> V_265 <= 6 )
V_78 /= 2 ;
}
if ( V_94 -> V_270 ) {
if ( V_188 > 0 && V_269 == V_272 ) {
if ( V_266 )
V_78 *= 5 ;
V_78 /= 6 ;
} else {
V_78 /= 2 ;
}
}
return F_52 ( V_78 , F_98 ( V_2 , V_188 , V_266 ) ) ;
}
static unsigned int F_102 ( const struct V_1 * V_2 ,
int V_188 ,
const struct V_267 * V_94 )
{
if ( V_188 > 0 && V_94 -> V_271 > 1 )
return 64 ;
return F_99 ( V_2 , V_188 ) ;
}
static void F_103 ( const struct V_1 * V_2 ,
int V_188 ,
const struct V_267 * V_94 ,
enum V_268 V_269 ,
struct V_273 * F_49 )
{
F_49 -> V_274 = F_101 ( V_2 , V_188 , V_94 , V_269 , false ) ;
F_49 -> V_275 = F_101 ( V_2 , V_188 , V_94 , V_269 , true ) ;
F_49 -> V_276 = F_102 ( V_2 , V_188 , V_94 ) ;
F_49 -> V_277 = F_100 ( V_2 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
int V_188 ,
struct V_273 * F_49 )
{
F_49 -> V_274 = F_98 ( V_2 , V_188 , false ) ;
F_49 -> V_275 = F_98 ( V_2 , V_188 , true ) ;
F_49 -> V_276 = F_99 ( V_2 , V_188 ) ;
F_49 -> V_277 = F_100 ( V_2 ) ;
}
static bool F_105 ( int V_188 ,
const struct V_273 * F_49 ,
struct V_278 * V_279 )
{
bool V_180 ;
if ( ! V_279 -> V_39 )
return false ;
V_279 -> V_39 = V_279 -> V_256 <= F_49 -> V_274 &&
V_279 -> V_280 <= F_49 -> V_275 &&
V_279 -> V_281 <= F_49 -> V_276 ;
V_180 = V_279 -> V_39 ;
if ( V_188 == 0 && ! V_279 -> V_39 ) {
if ( V_279 -> V_256 > F_49 -> V_274 )
F_10 ( L_36 ,
V_188 , V_279 -> V_256 , F_49 -> V_274 ) ;
if ( V_279 -> V_280 > F_49 -> V_275 )
F_10 ( L_37 ,
V_188 , V_279 -> V_280 , F_49 -> V_275 ) ;
if ( V_279 -> V_281 > F_49 -> V_276 )
F_10 ( L_38 ,
V_188 , V_279 -> V_281 , F_49 -> V_276 ) ;
V_279 -> V_256 = F_64 ( T_3 , V_279 -> V_256 , F_49 -> V_274 ) ;
V_279 -> V_280 = F_64 ( T_3 , V_279 -> V_280 , F_49 -> V_275 ) ;
V_279 -> V_281 = F_64 ( T_3 , V_279 -> V_281 , F_49 -> V_276 ) ;
V_279 -> V_39 = true ;
}
return V_180 ;
}
static void F_106 ( const struct V_3 * V_4 ,
const struct V_137 * V_137 ,
int V_188 ,
struct V_246 * V_257 ,
struct V_278 * V_279 )
{
struct V_186 * V_186 ;
T_4 V_181 = V_4 -> V_51 . V_181 [ V_188 ] ;
T_4 V_282 = V_4 -> V_51 . V_282 [ V_188 ] ;
T_4 V_283 = V_4 -> V_51 . V_283 [ V_188 ] ;
if ( V_188 > 0 ) {
V_181 *= 5 ;
V_282 *= 5 ;
V_283 *= 5 ;
}
F_66 (dev_priv->dev, intel_crtc, intel_plane) {
struct V_187 * V_258 =
F_67 ( V_186 -> V_95 . V_97 ) ;
switch ( V_186 -> V_95 . type ) {
case V_205 :
V_279 -> V_256 = F_92 ( V_257 , V_258 ,
V_181 ,
V_188 ) ;
V_279 -> V_284 = F_96 ( V_257 , V_258 ,
V_279 -> V_256 ) ;
break;
case V_206 :
V_279 -> V_280 = F_94 ( V_257 , V_258 ,
V_282 ) ;
break;
case V_193 :
V_279 -> V_281 = F_95 ( V_257 , V_258 ,
V_283 ) ;
break;
}
}
V_279 -> V_39 = true ;
}
static T_3
F_107 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_137 * V_137 = F_45 ( V_88 ) ;
const struct V_92 * V_93 = & V_137 -> V_94 -> V_95 . V_93 ;
T_1 V_285 , V_286 ;
if ( ! V_137 -> V_209 )
return 0 ;
V_285 = F_108 ( V_93 -> V_130 * 1000 * 8 ,
V_93 -> V_100 ) ;
V_286 = F_108 ( V_93 -> V_130 * 1000 * 8 ,
V_4 -> V_287 ) ;
return F_109 ( V_286 ) |
F_110 ( V_285 ) ;
}
static void F_111 ( struct V_1 * V_2 , T_4 V_51 [ 8 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_112 ( V_2 ) ) {
T_3 V_40 ;
int V_180 , V_37 ;
int V_188 , V_183 = F_113 ( V_2 ) ;
V_40 = 0 ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
V_180 = F_114 ( V_4 ,
V_288 ,
& V_40 ) ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
if ( V_180 ) {
F_16 ( L_39 , V_180 ) ;
return;
}
V_51 [ 0 ] = V_40 & V_289 ;
V_51 [ 1 ] = ( V_40 >> V_290 ) &
V_289 ;
V_51 [ 2 ] = ( V_40 >> V_291 ) &
V_289 ;
V_51 [ 3 ] = ( V_40 >> V_292 ) &
V_289 ;
V_40 = 1 ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
V_180 = F_114 ( V_4 ,
V_288 ,
& V_40 ) ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
if ( V_180 ) {
F_16 ( L_39 , V_180 ) ;
return;
}
V_51 [ 4 ] = V_40 & V_289 ;
V_51 [ 5 ] = ( V_40 >> V_290 ) &
V_289 ;
V_51 [ 6 ] = ( V_40 >> V_291 ) &
V_289 ;
V_51 [ 7 ] = ( V_40 >> V_292 ) &
V_289 ;
V_51 [ 0 ] += 2 ;
for ( V_188 = 1 ; V_188 <= V_183 ; V_188 ++ )
if ( V_51 [ V_188 ] != 0 )
V_51 [ V_188 ] += 2 ;
else {
for ( V_37 = V_188 + 1 ; V_37 <= V_183 ; V_37 ++ )
V_51 [ V_37 ] = 0 ;
break;
}
} else if ( F_115 ( V_2 ) || F_116 ( V_2 ) ) {
T_5 V_293 = F_117 ( V_294 ) ;
V_51 [ 0 ] = ( V_293 >> 56 ) & 0xFF ;
if ( V_51 [ 0 ] == 0 )
V_51 [ 0 ] = V_293 & 0xF ;
V_51 [ 1 ] = ( V_293 >> 4 ) & 0xFF ;
V_51 [ 2 ] = ( V_293 >> 12 ) & 0xFF ;
V_51 [ 3 ] = ( V_293 >> 20 ) & 0x1FF ;
V_51 [ 4 ] = ( V_293 >> 32 ) & 0x1FF ;
} else if ( F_69 ( V_2 ) -> V_265 >= 6 ) {
T_3 V_293 = F_3 ( V_294 ) ;
V_51 [ 0 ] = ( V_293 >> V_295 ) & V_296 ;
V_51 [ 1 ] = ( V_293 >> V_297 ) & V_296 ;
V_51 [ 2 ] = ( V_293 >> V_298 ) & V_296 ;
V_51 [ 3 ] = ( V_293 >> V_299 ) & V_296 ;
} else if ( F_69 ( V_2 ) -> V_265 >= 5 ) {
T_3 V_300 = F_3 ( V_301 ) ;
V_51 [ 0 ] = 7 ;
V_51 [ 1 ] = ( V_300 >> V_302 ) & V_303 ;
V_51 [ 2 ] = ( V_300 >> V_304 ) & V_303 ;
}
}
static void F_118 ( struct V_1 * V_2 , T_4 V_51 [ 5 ] )
{
if ( F_69 ( V_2 ) -> V_265 == 5 )
V_51 [ 0 ] = 13 ;
}
static void F_119 ( struct V_1 * V_2 , T_4 V_51 [ 5 ] )
{
if ( F_69 ( V_2 ) -> V_265 == 5 )
V_51 [ 0 ] = 13 ;
if ( F_120 ( V_2 ) )
V_51 [ 3 ] *= 2 ;
}
int F_113 ( const struct V_1 * V_2 )
{
if ( F_69 ( V_2 ) -> V_265 >= 9 )
return 7 ;
else if ( F_115 ( V_2 ) || F_116 ( V_2 ) )
return 4 ;
else if ( F_69 ( V_2 ) -> V_265 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_121 ( struct V_1 * V_2 ,
const char * V_305 ,
const T_4 V_51 [ 8 ] )
{
int V_188 , V_183 = F_113 ( V_2 ) ;
for ( V_188 = 0 ; V_188 <= V_183 ; V_188 ++ ) {
unsigned int V_36 = V_51 [ V_188 ] ;
if ( V_36 == 0 ) {
F_16 ( L_40 ,
V_305 , V_188 ) ;
continue;
}
if ( F_112 ( V_2 ) )
V_36 *= 10 ;
else if ( V_188 > 0 )
V_36 *= 5 ;
F_10 ( L_41 ,
V_305 , V_188 , V_51 [ V_188 ] ,
V_36 / 10 , V_36 % 10 ) ;
}
}
static bool F_122 ( struct V_3 * V_4 ,
T_4 V_51 [ 5 ] , T_4 F_52 )
{
int V_188 , V_183 = F_113 ( V_4 -> V_2 ) ;
if ( V_51 [ 0 ] >= F_52 )
return false ;
V_51 [ 0 ] = F_49 ( V_51 [ 0 ] , F_52 ) ;
for ( V_188 = 1 ; V_188 <= V_183 ; V_188 ++ )
V_51 [ V_188 ] = F_123 ( T_4 , V_51 [ V_188 ] , F_39 ( F_52 , 5 ) ) ;
return true ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_306 ;
V_306 = F_122 ( V_4 , V_4 -> V_51 . V_181 , 12 ) |
F_122 ( V_4 , V_4 -> V_51 . V_282 , 12 ) |
F_122 ( V_4 , V_4 -> V_51 . V_283 , 12 ) ;
if ( ! V_306 )
return;
F_10 ( L_42 ) ;
F_121 ( V_2 , L_43 , V_4 -> V_51 . V_181 ) ;
F_121 ( V_2 , L_44 , V_4 -> V_51 . V_282 ) ;
F_121 ( V_2 , L_45 , V_4 -> V_51 . V_283 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_111 ( V_2 , V_4 -> V_51 . V_181 ) ;
memcpy ( V_4 -> V_51 . V_282 , V_4 -> V_51 . V_181 ,
sizeof( V_4 -> V_51 . V_181 ) ) ;
memcpy ( V_4 -> V_51 . V_283 , V_4 -> V_51 . V_181 ,
sizeof( V_4 -> V_51 . V_181 ) ) ;
F_118 ( V_2 , V_4 -> V_51 . V_282 ) ;
F_119 ( V_2 , V_4 -> V_51 . V_283 ) ;
F_121 ( V_2 , L_43 , V_4 -> V_51 . V_181 ) ;
F_121 ( V_2 , L_44 , V_4 -> V_51 . V_282 ) ;
F_121 ( V_2 , L_45 , V_4 -> V_51 . V_283 ) ;
if ( F_126 ( V_2 ) )
F_124 ( V_2 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_111 ( V_2 , V_4 -> V_51 . V_307 ) ;
F_121 ( V_2 , L_46 , V_4 -> V_51 . V_307 ) ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_267 * V_94 )
{
struct V_137 * V_137 ;
F_74 (dev, intel_crtc) {
const struct V_308 * V_51 = & V_137 -> V_51 . V_209 ;
if ( ! V_51 -> V_309 )
continue;
V_94 -> V_270 |= V_51 -> V_270 ;
V_94 -> V_310 |= V_51 -> V_310 ;
V_94 -> V_271 ++ ;
}
}
static bool F_129 ( struct V_246 * V_257 ,
struct V_308 * V_311 )
{
struct V_87 * V_88 = V_257 -> V_95 . V_88 ;
struct V_1 * V_2 = V_88 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_137 * V_137 = F_45 ( V_88 ) ;
struct V_186 * V_186 ;
struct V_187 * V_312 = NULL ;
int V_188 , V_183 = F_113 ( V_2 ) ;
struct V_267 V_94 = {
. V_271 = 1 ,
} ;
struct V_273 F_49 ;
F_66 (dev, intel_crtc, intel_plane) {
if ( V_186 -> V_95 . type == V_206 ) {
V_312 = F_67 ( V_186 -> V_95 . V_97 ) ;
break;
}
}
V_94 . V_270 = V_312 -> V_191 ;
V_94 . V_310 = V_312 -> V_191 &&
( F_93 ( & V_312 -> V_264 ) != F_93 ( & V_312 -> V_313 ) >> 16 ||
F_130 ( & V_312 -> V_264 ) != F_130 ( & V_312 -> V_313 ) >> 16 ) ;
V_311 -> V_309 = V_257 -> V_95 . V_209 ;
V_311 -> V_270 = V_312 -> V_191 ;
V_311 -> V_310 = V_94 . V_310 ;
if ( F_69 ( V_2 ) -> V_265 <= 6 && V_312 -> V_191 )
V_183 = 1 ;
if ( V_94 . V_310 )
V_183 = 0 ;
F_106 ( V_4 , V_137 , 0 , V_257 , & V_311 -> V_51 [ 0 ] ) ;
if ( F_115 ( V_2 ) || F_116 ( V_2 ) )
V_311 -> V_285 = F_107 ( V_2 , V_88 ) ;
F_103 ( V_2 , 0 , & V_94 , V_314 , & F_49 ) ;
if ( ! F_105 ( 0 , & F_49 , & V_311 -> V_51 [ 0 ] ) )
return false ;
F_104 ( V_2 , 1 , & F_49 ) ;
for ( V_188 = 1 ; V_188 <= V_183 ; V_188 ++ ) {
struct V_278 V_51 = {} ;
F_106 ( V_4 , V_137 , V_188 , V_257 , & V_51 ) ;
if ( ! F_105 ( V_188 , & F_49 , & V_51 ) )
break;
V_311 -> V_51 [ V_188 ] = V_51 ;
}
return true ;
}
static void F_131 ( struct V_1 * V_2 ,
int V_188 ,
struct V_278 * V_315 )
{
const struct V_137 * V_137 ;
V_315 -> V_39 = true ;
F_74 (dev, intel_crtc) {
const struct V_308 * V_209 = & V_137 -> V_51 . V_209 ;
const struct V_278 * V_51 = & V_209 -> V_51 [ V_188 ] ;
if ( ! V_209 -> V_309 )
continue;
if ( ! V_51 -> V_39 )
V_315 -> V_39 = false ;
V_315 -> V_256 = F_49 ( V_315 -> V_256 , V_51 -> V_256 ) ;
V_315 -> V_280 = F_49 ( V_315 -> V_280 , V_51 -> V_280 ) ;
V_315 -> V_281 = F_49 ( V_315 -> V_281 , V_51 -> V_281 ) ;
V_315 -> V_284 = F_49 ( V_315 -> V_284 , V_51 -> V_284 ) ;
}
}
static void F_132 ( struct V_1 * V_2 ,
const struct V_267 * V_94 ,
const struct V_273 * F_49 ,
struct V_308 * V_316 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_188 , V_183 = F_113 ( V_2 ) ;
int V_317 = V_183 ;
if ( ( F_69 ( V_2 ) -> V_265 <= 6 || F_120 ( V_2 ) ) &&
V_94 -> V_271 > 1 )
return;
V_316 -> V_318 = F_69 ( V_2 ) -> V_265 >= 6 ;
for ( V_188 = 1 ; V_188 <= V_183 ; V_188 ++ ) {
struct V_278 * V_51 = & V_316 -> V_51 [ V_188 ] ;
F_131 ( V_2 , V_188 , V_51 ) ;
if ( V_188 > V_317 )
V_51 -> V_39 = false ;
else if ( ! F_105 ( V_188 , F_49 , V_51 ) )
V_317 = V_188 - 1 ;
if ( V_51 -> V_284 > F_49 -> V_277 ) {
if ( V_51 -> V_39 )
V_316 -> V_318 = false ;
V_51 -> V_284 = 0 ;
}
}
if ( F_133 ( V_2 ) && ! V_316 -> V_318 &&
F_134 ( V_4 ) ) {
for ( V_188 = 2 ; V_188 <= V_183 ; V_188 ++ ) {
struct V_278 * V_51 = & V_316 -> V_51 [ V_188 ] ;
V_51 -> V_39 = false ;
}
}
}
static int F_135 ( int V_319 , const struct V_308 * V_311 )
{
return V_319 + ( V_319 >= 2 && V_311 -> V_51 [ 4 ] . V_39 ) ;
}
static unsigned int F_136 ( struct V_1 * V_2 , int V_188 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_115 ( V_2 ) || F_116 ( V_2 ) )
return 2 * V_188 ;
else
return V_4 -> V_51 . V_181 [ V_188 ] ;
}
static void F_137 ( struct V_1 * V_2 ,
const struct V_308 * V_316 ,
enum V_268 V_320 ,
struct V_321 * V_322 )
{
struct V_137 * V_137 ;
int V_188 , V_319 ;
V_322 -> V_323 = V_316 -> V_318 ;
V_322 -> V_320 = V_320 ;
for ( V_319 = 1 ; V_319 <= 3 ; V_319 ++ ) {
const struct V_278 * V_324 ;
V_188 = F_135 ( V_319 , V_316 ) ;
V_324 = & V_316 -> V_51 [ V_188 ] ;
V_322 -> V_319 [ V_319 - 1 ] =
( F_136 ( V_2 , V_188 ) << V_325 ) |
( V_324 -> V_256 << V_326 ) |
V_324 -> V_281 ;
if ( V_324 -> V_39 )
V_322 -> V_319 [ V_319 - 1 ] |= V_327 ;
if ( F_69 ( V_2 ) -> V_265 >= 8 )
V_322 -> V_319 [ V_319 - 1 ] |=
V_324 -> V_284 << V_328 ;
else
V_322 -> V_319 [ V_319 - 1 ] |=
V_324 -> V_284 << V_329 ;
if ( F_69 ( V_2 ) -> V_265 <= 6 && V_324 -> V_280 ) {
F_63 ( V_319 != 1 ) ;
V_322 -> V_330 [ V_319 - 1 ] = V_331 | V_324 -> V_280 ;
} else
V_322 -> V_330 [ V_319 - 1 ] = V_324 -> V_280 ;
}
F_74 (dev, intel_crtc) {
enum V_60 V_60 = V_137 -> V_60 ;
const struct V_278 * V_324 =
& V_137 -> V_51 . V_209 . V_51 [ 0 ] ;
if ( F_63 ( ! V_324 -> V_39 ) )
continue;
V_322 -> V_332 [ V_60 ] = V_137 -> V_51 . V_209 . V_285 ;
V_322 -> V_333 [ V_60 ] =
( V_324 -> V_256 << V_334 ) |
( V_324 -> V_280 << V_335 ) |
V_324 -> V_281 ;
}
}
static struct V_308 * F_138 ( struct V_1 * V_2 ,
struct V_308 * V_336 ,
struct V_308 * V_337 )
{
int V_188 , V_183 = F_113 ( V_2 ) ;
int V_338 = 0 , V_339 = 0 ;
for ( V_188 = 1 ; V_188 <= V_183 ; V_188 ++ ) {
if ( V_336 -> V_51 [ V_188 ] . V_39 )
V_338 = V_188 ;
if ( V_337 -> V_51 [ V_188 ] . V_39 )
V_339 = V_188 ;
}
if ( V_338 == V_339 ) {
if ( V_337 -> V_318 && ! V_336 -> V_318 )
return V_337 ;
else
return V_336 ;
} else if ( V_338 > V_339 ) {
return V_336 ;
} else {
return V_337 ;
}
}
static unsigned int F_139 ( struct V_3 * V_4 ,
const struct V_321 * V_340 ,
const struct V_321 * V_341 )
{
unsigned int V_342 = 0 ;
enum V_60 V_60 ;
int V_319 ;
F_140 (dev_priv, pipe) {
if ( V_340 -> V_332 [ V_60 ] != V_341 -> V_332 [ V_60 ] ) {
V_342 |= F_141 ( V_60 ) ;
V_342 |= V_343 ;
}
if ( V_340 -> V_333 [ V_60 ] != V_341 -> V_333 [ V_60 ] ) {
V_342 |= F_142 ( V_60 ) ;
V_342 |= V_343 ;
}
}
if ( V_340 -> V_323 != V_341 -> V_323 ) {
V_342 |= V_344 ;
V_342 |= V_343 ;
}
if ( V_340 -> V_320 != V_341 -> V_320 ) {
V_342 |= V_345 ;
V_342 |= V_343 ;
}
if ( V_342 & V_343 )
return V_342 ;
for ( V_319 = 1 ; V_319 <= 3 ; V_319 ++ ) {
if ( V_340 -> V_319 [ V_319 - 1 ] != V_341 -> V_319 [ V_319 - 1 ] ||
V_340 -> V_330 [ V_319 - 1 ] != V_341 -> V_330 [ V_319 - 1 ] )
break;
}
for (; V_319 <= 3 ; V_319 ++ )
V_342 |= F_143 ( V_319 ) ;
return V_342 ;
}
static bool F_144 ( struct V_3 * V_4 ,
unsigned int V_342 )
{
struct V_321 * V_346 = & V_4 -> V_51 . V_347 ;
bool V_306 = false ;
if ( V_342 & F_143 ( 3 ) && V_346 -> V_319 [ 2 ] & V_327 ) {
V_346 -> V_319 [ 2 ] &= ~ V_327 ;
F_2 ( V_348 , V_346 -> V_319 [ 2 ] ) ;
V_306 = true ;
}
if ( V_342 & F_143 ( 2 ) && V_346 -> V_319 [ 1 ] & V_327 ) {
V_346 -> V_319 [ 1 ] &= ~ V_327 ;
F_2 ( V_349 , V_346 -> V_319 [ 1 ] ) ;
V_306 = true ;
}
if ( V_342 & F_143 ( 1 ) && V_346 -> V_319 [ 0 ] & V_327 ) {
V_346 -> V_319 [ 0 ] &= ~ V_327 ;
F_2 ( V_350 , V_346 -> V_319 [ 0 ] ) ;
V_306 = true ;
}
return V_306 ;
}
static void F_145 ( struct V_3 * V_4 ,
struct V_321 * V_322 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_321 * V_346 = & V_4 -> V_51 . V_347 ;
unsigned int V_342 ;
T_3 V_40 ;
V_342 = F_139 ( V_4 , V_346 , V_322 ) ;
if ( ! V_342 )
return;
F_144 ( V_4 , V_342 ) ;
if ( V_342 & F_142 ( V_68 ) )
F_2 ( V_351 , V_322 -> V_333 [ 0 ] ) ;
if ( V_342 & F_142 ( V_71 ) )
F_2 ( V_352 , V_322 -> V_333 [ 1 ] ) ;
if ( V_342 & F_142 ( V_72 ) )
F_2 ( V_353 , V_322 -> V_333 [ 2 ] ) ;
if ( V_342 & F_141 ( V_68 ) )
F_2 ( F_146 ( V_68 ) , V_322 -> V_332 [ 0 ] ) ;
if ( V_342 & F_141 ( V_71 ) )
F_2 ( F_146 ( V_71 ) , V_322 -> V_332 [ 1 ] ) ;
if ( V_342 & F_141 ( V_72 ) )
F_2 ( F_146 ( V_72 ) , V_322 -> V_332 [ 2 ] ) ;
if ( V_342 & V_345 ) {
if ( F_115 ( V_2 ) || F_116 ( V_2 ) ) {
V_40 = F_3 ( V_354 ) ;
if ( V_322 -> V_320 == V_314 )
V_40 &= ~ V_355 ;
else
V_40 |= V_355 ;
F_2 ( V_354 , V_40 ) ;
} else {
V_40 = F_3 ( V_356 ) ;
if ( V_322 -> V_320 == V_314 )
V_40 &= ~ V_357 ;
else
V_40 |= V_357 ;
F_2 ( V_356 , V_40 ) ;
}
}
if ( V_342 & V_344 ) {
V_40 = F_3 ( V_358 ) ;
if ( V_322 -> V_323 )
V_40 &= ~ V_359 ;
else
V_40 |= V_359 ;
F_2 ( V_358 , V_40 ) ;
}
if ( V_342 & F_143 ( 1 ) &&
V_346 -> V_330 [ 0 ] != V_322 -> V_330 [ 0 ] )
F_2 ( V_360 , V_322 -> V_330 [ 0 ] ) ;
if ( F_69 ( V_2 ) -> V_265 >= 7 ) {
if ( V_342 & F_143 ( 2 ) && V_346 -> V_330 [ 1 ] != V_322 -> V_330 [ 1 ] )
F_2 ( V_361 , V_322 -> V_330 [ 1 ] ) ;
if ( V_342 & F_143 ( 3 ) && V_346 -> V_330 [ 2 ] != V_322 -> V_330 [ 2 ] )
F_2 ( V_362 , V_322 -> V_330 [ 2 ] ) ;
}
if ( V_342 & F_143 ( 1 ) && V_346 -> V_319 [ 0 ] != V_322 -> V_319 [ 0 ] )
F_2 ( V_350 , V_322 -> V_319 [ 0 ] ) ;
if ( V_342 & F_143 ( 2 ) && V_346 -> V_319 [ 1 ] != V_322 -> V_319 [ 1 ] )
F_2 ( V_349 , V_322 -> V_319 [ 1 ] ) ;
if ( V_342 & F_143 ( 3 ) && V_346 -> V_319 [ 2 ] != V_322 -> V_319 [ 2 ] )
F_2 ( V_348 , V_322 -> V_319 [ 2 ] ) ;
V_4 -> V_51 . V_347 = * V_322 ;
}
static bool F_147 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_144 ( V_4 , V_343 ) ;
}
static void
F_148 ( struct V_1 * V_2 ,
struct V_87 * V_363 ,
const struct V_267 * V_94 ,
const struct V_364 * V_365 ,
struct V_366 * V_367 )
{
struct V_87 * V_88 ;
unsigned int V_368 , V_369 ;
int V_370 ;
if ( ! V_365 -> V_209 ) {
V_367 -> V_371 = 0 ;
V_367 -> V_372 = 0 ;
return;
}
if ( F_149 ( V_2 ) )
V_369 = V_373 ;
else
V_369 = V_374 ;
V_369 -= 4 ;
V_370 = 0 ;
F_41 (dev, crtc) {
if ( ! F_45 ( V_88 ) -> V_209 )
continue;
if ( V_88 == V_363 )
break;
V_370 ++ ;
}
V_368 = V_369 / V_94 -> V_271 ;
V_367 -> V_371 = V_370 * V_369 / V_94 -> V_271 ;
V_367 -> V_372 = V_367 -> V_371 + V_368 ;
}
static unsigned int F_150 ( const struct V_267 * V_94 )
{
if ( V_94 -> V_271 == 1 )
return 32 ;
return 8 ;
}
static void F_151 ( struct V_366 * V_375 , T_1 V_91 )
{
V_375 -> V_371 = V_91 & 0x3ff ;
V_375 -> V_372 = ( V_91 >> 16 ) & 0x3ff ;
if ( V_375 -> V_372 )
V_375 -> V_372 += 1 ;
}
void F_152 ( struct V_3 * V_4 ,
struct V_376 * V_377 )
{
enum V_60 V_60 ;
int V_61 ;
T_1 V_40 ;
memset ( V_377 , 0 , sizeof( * V_377 ) ) ;
F_140 (dev_priv, pipe) {
if ( ! F_153 ( V_4 , F_154 ( V_60 ) ) )
continue;
F_155 (dev_priv, pipe, plane) {
V_40 = F_3 ( F_156 ( V_60 , V_61 ) ) ;
F_151 ( & V_377 -> V_61 [ V_60 ] [ V_61 ] ,
V_40 ) ;
}
V_40 = F_3 ( F_157 ( V_60 ) ) ;
F_151 ( & V_377 -> V_61 [ V_60 ] [ V_378 ] ,
V_40 ) ;
}
}
static unsigned int
F_158 ( const struct V_379 * V_380 , int V_381 )
{
if ( V_380 -> V_382 ) {
if ( V_381 )
return V_380 -> V_178 * V_380 -> V_383 * V_380 -> V_382 ;
else
return ( V_380 -> V_178 / 2 ) * ( V_380 -> V_383 / 2 ) * V_380 -> V_179 ;
}
return V_380 -> V_178 * V_380 -> V_383 * V_380 -> V_179 ;
}
static unsigned int
F_159 ( struct V_137 * V_137 ,
const struct V_364 * V_365 )
{
unsigned int V_384 = 0 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_160 ( V_137 ) ; V_61 ++ ) {
const struct V_379 * V_380 ;
V_380 = & V_365 -> V_61 [ V_61 ] ;
if ( ! V_380 -> V_89 )
continue;
V_384 += F_158 ( V_380 , 0 ) ;
if ( V_380 -> V_382 ) {
V_384 += F_158 ( V_380 , 1 ) ;
}
}
return V_384 ;
}
static void
F_161 ( struct V_87 * V_88 ,
const struct V_267 * V_94 ,
const struct V_364 * V_365 ,
struct V_376 * V_377 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_137 * V_137 = F_45 ( V_88 ) ;
enum V_60 V_60 = V_137 -> V_60 ;
struct V_366 * V_367 = & V_377 -> V_60 [ V_60 ] ;
T_4 V_385 , V_371 , V_386 ;
T_4 V_387 [ V_388 ] ;
T_4 V_389 [ V_388 ] ;
unsigned int V_384 ;
int V_61 ;
F_148 ( V_2 , V_88 , V_94 , V_365 , V_367 ) ;
V_385 = F_162 ( V_367 ) ;
if ( V_385 == 0 ) {
memset ( V_377 -> V_61 [ V_60 ] , 0 , sizeof( V_377 -> V_61 [ V_60 ] ) ) ;
memset ( & V_377 -> V_61 [ V_60 ] [ V_378 ] , 0 ,
sizeof( V_377 -> V_61 [ V_60 ] [ V_378 ] ) ) ;
return;
}
V_386 = F_150 ( V_94 ) ;
V_377 -> V_61 [ V_60 ] [ V_378 ] . V_371 = V_367 -> V_372 - V_386 ;
V_377 -> V_61 [ V_60 ] [ V_378 ] . V_372 = V_367 -> V_372 ;
V_385 -= V_386 ;
V_367 -> V_372 -= V_386 ;
F_155 (dev_priv, pipe, plane) {
const struct V_379 * V_380 ;
V_380 = & V_365 -> V_61 [ V_61 ] ;
if ( ! V_380 -> V_89 )
continue;
V_387 [ V_61 ] = 8 ;
V_385 -= V_387 [ V_61 ] ;
V_389 [ V_61 ] = V_380 -> V_382 ? 8 : 0 ;
V_385 -= V_389 [ V_61 ] ;
}
V_384 = F_159 ( V_137 , V_365 ) ;
V_371 = V_367 -> V_371 ;
for ( V_61 = 0 ; V_61 < F_160 ( V_137 ) ; V_61 ++ ) {
const struct V_379 * V_380 ;
unsigned int V_390 , V_391 ;
T_4 V_392 , V_393 = 0 ;
V_380 = & V_365 -> V_61 [ V_61 ] ;
if ( ! V_380 -> V_89 )
continue;
V_390 = F_158 ( V_380 , 0 ) ;
V_392 = V_387 [ V_61 ] ;
V_392 += F_86 ( ( T_5 ) V_385 * V_390 ,
V_384 ) ;
V_377 -> V_61 [ V_60 ] [ V_61 ] . V_371 = V_371 ;
V_377 -> V_61 [ V_60 ] [ V_61 ] . V_372 = V_371 + V_392 ;
V_371 += V_392 ;
if ( V_380 -> V_382 ) {
V_391 = F_158 ( V_380 , 1 ) ;
V_393 = V_389 [ V_61 ] ;
V_393 += F_86 ( ( T_5 ) V_385 * V_391 ,
V_384 ) ;
V_377 -> V_394 [ V_60 ] [ V_61 ] . V_371 = V_371 ;
V_377 -> V_394 [ V_60 ] [ V_61 ] . V_372 = V_371 + V_393 ;
V_371 += V_393 ;
}
}
}
static T_3 F_163 ( const struct V_246 * V_94 )
{
return V_94 -> V_95 . V_93 . V_100 ;
}
static T_3 F_164 ( T_3 V_176 , T_6 V_179 ,
T_3 V_36 )
{
T_3 V_395 , V_180 ;
if ( V_36 == 0 )
return V_255 ;
V_395 = V_36 * V_176 * V_179 / 512 ;
V_180 = F_39 ( V_395 , 1000 ) ;
return V_180 ;
}
static T_3 F_165 ( T_3 V_176 , T_3 V_177 ,
T_3 V_178 , T_6 V_179 ,
T_5 V_396 , T_3 V_36 )
{
T_3 V_180 ;
T_3 V_397 , V_398 ;
T_3 V_395 ;
if ( V_36 == 0 )
return V_255 ;
V_397 = V_178 * V_179 ;
if ( V_396 == V_399 ||
V_396 == V_400 ) {
V_397 *= 4 ;
V_398 = F_39 ( V_397 , 512 ) ;
V_398 /= 4 ;
} else {
V_398 = F_39 ( V_397 , 512 ) ;
}
V_395 = V_36 * V_176 ;
V_180 = F_39 ( V_395 , V_177 * 1000 ) *
V_398 ;
return V_180 ;
}
static bool F_166 ( const struct V_376 * V_401 ,
const struct V_137 * V_137 )
{
struct V_1 * V_2 = V_137 -> V_95 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_376 * V_402 = & V_4 -> V_51 . V_403 . V_377 ;
enum V_60 V_60 = V_137 -> V_60 ;
if ( memcmp ( V_401 -> V_61 [ V_60 ] , V_402 -> V_61 [ V_60 ] ,
sizeof( V_401 -> V_61 [ V_60 ] ) ) )
return true ;
if ( memcmp ( & V_401 -> V_61 [ V_60 ] [ V_378 ] , & V_402 -> V_61 [ V_60 ] [ V_378 ] ,
sizeof( V_401 -> V_61 [ V_60 ] [ V_378 ] ) ) )
return true ;
return false ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_267 * V_94 )
{
struct V_87 * V_88 ;
struct V_404 * V_61 ;
F_168 (crtc, &dev->mode_config.crtc_list, head)
V_94 -> V_271 += F_45 ( V_88 ) -> V_209 ;
F_168 (plane, &dev->mode_config.plane_list, head) {
struct V_186 * V_186 = F_169 ( V_61 ) ;
V_94 -> V_270 |= V_186 -> V_51 . V_89 ;
V_94 -> V_310 |= V_186 -> V_51 . V_405 ;
}
}
static void F_170 ( struct V_87 * V_88 ,
struct V_364 * V_380 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_137 * V_137 = F_45 ( V_88 ) ;
enum V_60 V_60 = V_137 -> V_60 ;
struct V_404 * V_61 ;
struct V_406 * V_98 ;
int V_37 = 1 ;
V_380 -> V_209 = V_137 -> V_209 ;
if ( V_380 -> V_209 ) {
V_380 -> V_177 = V_137 -> V_94 -> V_95 . V_93 . V_130 ;
V_380 -> V_176 = F_163 ( V_137 -> V_94 ) ;
V_98 = V_88 -> V_96 -> V_97 -> V_98 ;
if ( V_98 ) {
V_380 -> V_61 [ 0 ] . V_89 = true ;
V_380 -> V_61 [ 0 ] . V_179 = V_98 -> V_192 == V_407 ?
F_62 ( V_98 -> V_192 , 1 ) :
F_62 ( V_98 -> V_192 , 0 ) ;
V_380 -> V_61 [ 0 ] . V_382 = V_98 -> V_192 == V_407 ?
F_62 ( V_98 -> V_192 , 0 ) : 0 ;
V_380 -> V_61 [ 0 ] . V_396 = V_98 -> V_408 [ 0 ] ;
} else {
V_380 -> V_61 [ 0 ] . V_89 = false ;
V_380 -> V_61 [ 0 ] . V_179 = 0 ;
V_380 -> V_61 [ 0 ] . V_382 = 0 ;
V_380 -> V_61 [ 0 ] . V_396 = V_409 ;
}
V_380 -> V_61 [ 0 ] . V_178 = V_137 -> V_94 -> V_131 ;
V_380 -> V_61 [ 0 ] . V_383 = V_137 -> V_94 -> V_254 ;
V_380 -> V_61 [ 0 ] . V_410 = V_88 -> V_96 -> V_97 -> V_410 ;
V_98 = V_88 -> V_120 -> V_97 -> V_98 ;
V_380 -> V_61 [ V_378 ] . V_382 = 0 ;
if ( V_98 ) {
V_380 -> V_61 [ V_378 ] . V_89 = true ;
V_380 -> V_61 [ V_378 ] . V_179 = V_98 -> V_99 / 8 ;
V_380 -> V_61 [ V_378 ] . V_178 = V_88 -> V_120 -> V_97 -> V_132 ;
V_380 -> V_61 [ V_378 ] . V_383 = V_88 -> V_120 -> V_97 -> V_411 ;
} else {
V_380 -> V_61 [ V_378 ] . V_89 = false ;
V_380 -> V_61 [ V_378 ] . V_179 = 0 ;
V_380 -> V_61 [ V_378 ] . V_178 = 64 ;
V_380 -> V_61 [ V_378 ] . V_383 = 64 ;
}
}
F_168 (plane, &dev->mode_config.plane_list, head) {
struct V_186 * V_186 = F_169 ( V_61 ) ;
if ( V_186 -> V_60 == V_60 &&
V_61 -> type == V_206 )
V_380 -> V_61 [ V_37 ++ ] = V_186 -> V_51 ;
}
}
static bool F_171 ( const struct V_3 * V_4 ,
struct V_364 * V_380 ,
struct V_379 * V_412 ,
T_4 V_413 ,
int V_188 ,
T_4 * V_414 ,
T_6 * V_415 )
{
T_3 V_36 = V_4 -> V_51 . V_307 [ V_188 ] ;
T_3 V_262 , V_263 ;
T_3 V_397 , V_398 ;
T_3 V_416 , V_417 ;
T_3 V_418 ;
T_6 V_179 ;
if ( V_36 == 0 || ! V_380 -> V_209 || ! V_412 -> V_89 )
return false ;
V_179 = V_412 -> V_382 ?
V_412 -> V_382 :
V_412 -> V_179 ;
V_262 = F_164 ( V_380 -> V_176 ,
V_179 ,
V_36 ) ;
V_263 = F_165 ( V_380 -> V_176 ,
V_380 -> V_177 ,
V_412 -> V_178 ,
V_179 ,
V_412 -> V_396 ,
V_36 ) ;
V_397 = V_412 -> V_178 * V_179 ;
V_398 = F_39 ( V_397 , 512 ) ;
if ( V_412 -> V_396 == V_399 ||
V_412 -> V_396 == V_400 ) {
T_3 V_419 = 4 ;
T_3 V_420 ;
if ( F_172 ( V_412 -> V_410 ) ) {
switch ( V_412 -> V_179 ) {
case 1 :
V_419 = 16 ;
break;
case 2 :
V_419 = 8 ;
break;
case 8 :
F_88 ( 1 , L_47 ) ;
}
}
V_420 = V_398 * V_419 ;
V_418 = F_49 ( V_263 , V_420 ) ;
} else {
if ( ( V_413 / V_398 ) >= 1 )
V_418 = F_52 ( V_262 , V_263 ) ;
else
V_418 = V_262 ;
}
V_416 = V_418 + 1 ;
V_417 = F_39 ( V_418 , V_398 ) ;
if ( V_188 >= 1 && V_188 <= 7 ) {
if ( V_412 -> V_396 == V_399 ||
V_412 -> V_396 == V_400 )
V_417 += 4 ;
else
V_416 ++ ;
}
if ( V_416 >= V_413 || V_417 > 31 )
return false ;
* V_414 = V_416 ;
* V_415 = V_417 ;
return true ;
}
static void F_173 ( const struct V_3 * V_4 ,
struct V_376 * V_377 ,
struct V_364 * V_380 ,
enum V_60 V_60 ,
int V_188 ,
int V_421 ,
struct V_422 * V_279 )
{
T_4 V_423 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_421 ; V_37 ++ ) {
V_423 = F_162 ( & V_377 -> V_61 [ V_60 ] [ V_37 ] ) ;
V_279 -> V_424 [ V_37 ] = F_171 ( V_4 ,
V_380 , & V_380 -> V_61 [ V_37 ] ,
V_423 ,
V_188 ,
& V_279 -> V_425 [ V_37 ] ,
& V_279 -> V_426 [ V_37 ] ) ;
}
V_423 = F_162 ( & V_377 -> V_61 [ V_60 ] [ V_378 ] ) ;
V_279 -> V_424 [ V_378 ] = F_171 ( V_4 , V_380 ,
& V_380 -> V_61 [ V_378 ] ,
V_423 , V_188 ,
& V_279 -> V_425 [ V_378 ] ,
& V_279 -> V_426 [ V_378 ] ) ;
}
static T_3
F_174 ( struct V_87 * V_88 , struct V_364 * V_380 )
{
if ( ! F_45 ( V_88 ) -> V_209 )
return 0 ;
if ( F_63 ( V_380 -> V_176 == 0 ) )
return 0 ;
return F_39 ( 8 * V_380 -> V_177 * 1000 , V_380 -> V_176 ) ;
}
static void F_175 ( struct V_87 * V_88 ,
struct V_364 * V_365 ,
struct V_422 * V_427 )
{
struct V_137 * V_137 = F_45 ( V_88 ) ;
int V_37 ;
if ( ! V_365 -> V_209 )
return;
for ( V_37 = 0 ; V_37 < F_160 ( V_137 ) ; V_37 ++ )
V_427 -> V_424 [ V_37 ] = false ;
V_427 -> V_424 [ V_378 ] = false ;
}
static void F_176 ( struct V_87 * V_88 ,
struct V_376 * V_377 ,
struct V_364 * V_365 ,
struct V_428 * V_311 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_137 * V_137 = F_45 ( V_88 ) ;
int V_188 , V_183 = F_113 ( V_2 ) ;
for ( V_188 = 0 ; V_188 <= V_183 ; V_188 ++ ) {
F_173 ( V_4 , V_377 , V_365 , V_137 -> V_60 ,
V_188 , F_160 ( V_137 ) ,
& V_311 -> V_51 [ V_188 ] ) ;
}
V_311 -> V_285 = F_174 ( V_88 , V_365 ) ;
F_175 ( V_88 , V_365 , & V_311 -> V_427 ) ;
}
static void F_177 ( struct V_1 * V_2 ,
struct V_364 * V_380 ,
struct V_428 * V_429 ,
struct V_430 * V_324 ,
struct V_137 * V_137 )
{
int V_188 , V_183 = F_113 ( V_2 ) ;
enum V_60 V_60 = V_137 -> V_60 ;
T_3 V_431 ;
int V_37 ;
for ( V_188 = 0 ; V_188 <= V_183 ; V_188 ++ ) {
for ( V_37 = 0 ; V_37 < F_160 ( V_137 ) ; V_37 ++ ) {
V_431 = 0 ;
V_431 |= V_429 -> V_51 [ V_188 ] . V_426 [ V_37 ] <<
V_432 ;
V_431 |= V_429 -> V_51 [ V_188 ] . V_425 [ V_37 ] ;
if ( V_429 -> V_51 [ V_188 ] . V_424 [ V_37 ] )
V_431 |= V_433 ;
V_324 -> V_61 [ V_60 ] [ V_37 ] [ V_188 ] = V_431 ;
}
V_431 = 0 ;
V_431 |= V_429 -> V_51 [ V_188 ] . V_426 [ V_378 ] << V_432 ;
V_431 |= V_429 -> V_51 [ V_188 ] . V_425 [ V_378 ] ;
if ( V_429 -> V_51 [ V_188 ] . V_424 [ V_378 ] )
V_431 |= V_433 ;
V_324 -> V_61 [ V_60 ] [ V_378 ] [ V_188 ] = V_431 ;
}
for ( V_37 = 0 ; V_37 < F_160 ( V_137 ) ; V_37 ++ ) {
V_431 = 0 ;
V_431 |= V_429 -> V_427 . V_426 [ V_37 ] << V_432 ;
V_431 |= V_429 -> V_427 . V_425 [ V_37 ] ;
if ( V_429 -> V_427 . V_424 [ V_37 ] )
V_431 |= V_433 ;
V_324 -> V_434 [ V_60 ] [ V_37 ] = V_431 ;
}
V_431 = 0 ;
V_431 |= V_429 -> V_427 . V_426 [ V_378 ] << V_432 ;
V_431 |= V_429 -> V_427 . V_425 [ V_378 ] ;
if ( V_429 -> V_427 . V_424 [ V_378 ] )
V_431 |= V_433 ;
V_324 -> V_434 [ V_60 ] [ V_378 ] = V_431 ;
V_324 -> V_332 [ V_60 ] = V_429 -> V_285 ;
}
static void F_178 ( struct V_3 * V_4 , T_3 V_91 ,
const struct V_366 * V_375 )
{
if ( V_375 -> V_372 )
F_2 ( V_91 , ( V_375 -> V_372 - 1 ) << 16 | V_375 -> V_371 ) ;
else
F_2 ( V_91 , 0 ) ;
}
static void F_179 ( struct V_3 * V_4 ,
const struct V_430 * V_341 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_137 * V_88 ;
F_168 (crtc, &dev->mode_config.crtc_list, base.head) {
int V_37 , V_188 , V_183 = F_113 ( V_2 ) ;
enum V_60 V_60 = V_88 -> V_60 ;
if ( ! V_341 -> V_342 [ V_60 ] )
continue;
F_2 ( F_146 ( V_60 ) , V_341 -> V_332 [ V_60 ] ) ;
for ( V_188 = 0 ; V_188 <= V_183 ; V_188 ++ ) {
for ( V_37 = 0 ; V_37 < F_160 ( V_88 ) ; V_37 ++ )
F_2 ( F_180 ( V_60 , V_37 , V_188 ) ,
V_341 -> V_61 [ V_60 ] [ V_37 ] [ V_188 ] ) ;
F_2 ( F_181 ( V_60 , V_188 ) ,
V_341 -> V_61 [ V_60 ] [ V_378 ] [ V_188 ] ) ;
}
for ( V_37 = 0 ; V_37 < F_160 ( V_88 ) ; V_37 ++ )
F_2 ( F_182 ( V_60 , V_37 ) ,
V_341 -> V_434 [ V_60 ] [ V_37 ] ) ;
F_2 ( F_183 ( V_60 ) ,
V_341 -> V_434 [ V_60 ] [ V_378 ] ) ;
for ( V_37 = 0 ; V_37 < F_160 ( V_88 ) ; V_37 ++ ) {
F_178 ( V_4 ,
F_156 ( V_60 , V_37 ) ,
& V_341 -> V_377 . V_61 [ V_60 ] [ V_37 ] ) ;
F_178 ( V_4 ,
F_184 ( V_60 , V_37 ) ,
& V_341 -> V_377 . V_394 [ V_60 ] [ V_37 ] ) ;
}
F_178 ( V_4 , F_157 ( V_60 ) ,
& V_341 -> V_377 . V_61 [ V_60 ] [ V_378 ] ) ;
}
}
static void
F_185 ( struct V_3 * V_4 , enum V_60 V_60 , int V_435 )
{
int V_61 ;
F_10 ( L_48 , F_32 ( V_60 ) , V_435 ) ;
F_155 (dev_priv, pipe, plane) {
F_2 ( F_186 ( V_60 , V_61 ) ,
F_3 ( F_186 ( V_60 , V_61 ) ) ) ;
}
F_2 ( F_187 ( V_60 ) , F_3 ( F_187 ( V_60 ) ) ) ;
}
static bool
F_188 ( const struct V_376 * V_340 ,
const struct V_376 * V_341 ,
enum V_60 V_60 )
{
T_4 V_436 , V_437 ;
V_436 = F_162 ( & V_340 -> V_60 [ V_60 ] ) ;
V_437 = F_162 ( & V_341 -> V_60 [ V_60 ] ) ;
return V_436 != V_437 &&
V_341 -> V_60 [ V_60 ] . V_371 >= V_340 -> V_60 [ V_60 ] . V_371 &&
V_341 -> V_60 [ V_60 ] . V_372 <= V_340 -> V_60 [ V_60 ] . V_372 ;
}
static void F_189 ( struct V_3 * V_4 ,
struct V_430 * V_438 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_376 * V_402 , * V_401 ;
bool V_439 [ V_440 ] = {} ;
struct V_137 * V_88 ;
enum V_60 V_60 ;
V_401 = & V_438 -> V_377 ;
V_402 = & V_4 -> V_51 . V_403 . V_377 ;
F_74 (dev, crtc) {
if ( ! V_88 -> V_209 )
continue;
V_60 = V_88 -> V_60 ;
if ( ! F_188 ( V_402 , V_401 , V_60 ) )
continue;
F_185 ( V_4 , V_60 , 1 ) ;
F_190 ( V_2 , V_60 ) ;
V_439 [ V_60 ] = true ;
}
F_74 (dev, crtc) {
if ( ! V_88 -> V_209 )
continue;
V_60 = V_88 -> V_60 ;
if ( V_439 [ V_60 ] )
continue;
if ( F_162 ( & V_401 -> V_60 [ V_60 ] ) <
F_162 ( & V_402 -> V_60 [ V_60 ] ) ) {
F_185 ( V_4 , V_60 , 2 ) ;
F_190 ( V_2 , V_60 ) ;
V_439 [ V_60 ] = true ;
}
}
F_74 (dev, crtc) {
if ( ! V_88 -> V_209 )
continue;
V_60 = V_88 -> V_60 ;
if ( V_439 [ V_60 ] )
continue;
F_185 ( V_4 , V_60 , 3 ) ;
}
}
static bool F_191 ( struct V_87 * V_88 ,
struct V_364 * V_365 ,
struct V_267 * V_94 ,
struct V_376 * V_377 ,
struct V_428 * V_311 )
{
struct V_137 * V_137 = F_45 ( V_88 ) ;
F_170 ( V_88 , V_365 ) ;
F_161 ( V_88 , V_94 , V_365 , V_377 ) ;
F_176 ( V_88 , V_377 , V_365 , V_311 ) ;
if ( ! memcmp ( & V_137 -> V_51 . V_441 , V_311 , sizeof( * V_311 ) ) )
return false ;
V_137 -> V_51 . V_441 = * V_311 ;
return true ;
}
static void F_192 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_267 * V_94 ,
struct V_430 * V_324 )
{
struct V_137 * V_137 ;
struct V_137 * V_442 = F_45 ( V_88 ) ;
if ( ! F_166 ( & V_324 -> V_377 , V_442 ) )
return;
F_168 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
struct V_364 V_365 = {} ;
struct V_428 V_311 = {} ;
bool V_443 ;
if ( V_442 -> V_60 == V_137 -> V_60 )
continue;
if ( ! V_137 -> V_209 )
continue;
V_443 = F_191 ( & V_137 -> V_95 ,
& V_365 , V_94 ,
& V_324 -> V_377 , & V_311 ) ;
F_63 ( ! V_443 ) ;
F_177 ( V_2 , & V_365 , & V_311 , V_324 , V_137 ) ;
V_324 -> V_342 [ V_137 -> V_60 ] = true ;
}
}
static void F_193 ( struct V_430 * V_444 , enum V_60 V_60 )
{
V_444 -> V_332 [ V_60 ] = 0 ;
memset ( V_444 -> V_61 [ V_60 ] , 0 ,
sizeof( T_3 ) * 8 * V_388 ) ;
memset ( V_444 -> V_434 [ V_60 ] ,
0 , sizeof( T_3 ) * V_388 ) ;
V_444 -> V_434 [ V_60 ] [ V_378 ] = 0 ;
memset ( & V_444 -> V_377 . V_60 [ V_60 ] , 0 , sizeof( struct V_366 ) ) ;
memset ( & V_444 -> V_377 . V_61 [ V_60 ] , 0 ,
sizeof( struct V_366 ) * V_388 ) ;
memset ( & V_444 -> V_377 . V_394 [ V_60 ] , 0 ,
sizeof( struct V_366 ) * V_388 ) ;
memset ( & V_444 -> V_377 . V_61 [ V_60 ] [ V_378 ] , 0 ,
sizeof( struct V_366 ) ) ;
}
static void F_194 ( struct V_87 * V_88 )
{
struct V_137 * V_137 = F_45 ( V_88 ) ;
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_364 V_365 = {} ;
struct V_430 * V_322 = & V_4 -> V_51 . V_445 ;
struct V_428 V_311 = {} ;
struct V_267 V_94 = {} ;
memset ( V_322 -> V_342 , 0 , sizeof( bool ) * V_440 ) ;
F_193 ( V_322 , V_137 -> V_60 ) ;
F_167 ( V_2 , & V_94 ) ;
if ( ! F_191 ( V_88 , & V_365 , & V_94 ,
& V_322 -> V_377 , & V_311 ) )
return;
F_177 ( V_2 , & V_365 , & V_311 , V_322 , V_137 ) ;
V_322 -> V_342 [ V_137 -> V_60 ] = true ;
F_192 ( V_2 , V_88 , & V_94 , V_322 ) ;
F_179 ( V_4 , V_322 ) ;
F_189 ( V_4 , V_322 ) ;
V_4 -> V_51 . V_403 = * V_322 ;
}
static void
F_195 ( struct V_404 * V_61 , struct V_87 * V_88 ,
T_3 V_446 , T_3 V_447 ,
int V_79 , bool V_89 , bool V_405 )
{
struct V_186 * V_186 = F_169 ( V_61 ) ;
struct V_406 * V_98 = V_61 -> V_97 -> V_98 ;
V_186 -> V_51 . V_89 = V_89 ;
V_186 -> V_51 . V_405 = V_405 ;
V_186 -> V_51 . V_178 = V_446 ;
V_186 -> V_51 . V_383 = V_447 ;
V_186 -> V_51 . V_396 = V_409 ;
V_186 -> V_51 . V_179 =
( V_98 && V_98 -> V_192 == V_407 ) ?
F_62 ( V_61 -> V_97 -> V_98 -> V_192 , 1 ) : V_79 ;
V_186 -> V_51 . V_382 =
( V_98 && V_98 -> V_192 == V_407 ) ?
F_62 ( V_61 -> V_97 -> V_98 -> V_192 , 0 ) : 0 ;
if ( V_98 )
V_186 -> V_51 . V_396 = V_98 -> V_408 [ 0 ] ;
V_186 -> V_51 . V_410 = V_61 -> V_97 -> V_410 ;
F_194 ( V_88 ) ;
}
static void F_196 ( struct V_87 * V_88 )
{
struct V_137 * V_137 = F_45 ( V_88 ) ;
struct V_246 * V_257 = F_197 ( V_88 -> V_97 ) ;
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_273 F_49 ;
struct V_321 V_322 = {} ;
enum V_268 V_320 ;
struct V_308 V_311 = {} ;
struct V_308 V_448 = {} , V_449 = {} , * V_450 ;
struct V_267 V_94 = {} ;
F_63 ( V_257 -> V_95 . V_209 != V_137 -> V_209 ) ;
F_129 ( V_257 , & V_311 ) ;
if ( ! memcmp ( & V_137 -> V_51 . V_209 , & V_311 , sizeof( V_311 ) ) )
return;
V_137 -> V_51 . V_209 = V_311 ;
F_128 ( V_2 , & V_94 ) ;
F_103 ( V_2 , 1 , & V_94 , V_314 , & F_49 ) ;
F_132 ( V_2 , & V_94 , & F_49 , & V_448 ) ;
if ( F_69 ( V_2 ) -> V_265 >= 7 &&
V_94 . V_271 == 1 && V_94 . V_270 ) {
F_103 ( V_2 , 1 , & V_94 , V_272 , & F_49 ) ;
F_132 ( V_2 , & V_94 , & F_49 , & V_449 ) ;
V_450 = F_138 ( V_2 , & V_448 , & V_449 ) ;
} else {
V_450 = & V_448 ;
}
V_320 = ( V_450 == & V_448 ) ?
V_314 : V_272 ;
F_137 ( V_2 , V_450 , V_320 , & V_322 ) ;
F_145 ( V_4 , & V_322 ) ;
}
static void
F_198 ( struct V_404 * V_61 ,
struct V_87 * V_88 ,
T_3 V_446 , T_3 V_447 ,
int V_79 , bool V_89 , bool V_405 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_186 * V_186 = F_169 ( V_61 ) ;
if ( F_120 ( V_2 ) && V_405 && F_147 ( V_2 ) )
F_190 ( V_2 , V_186 -> V_60 ) ;
F_196 ( V_88 ) ;
}
static void F_199 ( T_3 V_40 ,
struct V_428 * V_209 ,
bool V_451 ,
bool V_452 ,
int V_37 ,
int V_188 )
{
bool V_453 = ( V_40 & V_433 ) != 0 ;
if ( ! V_451 ) {
if ( ! V_452 ) {
V_209 -> V_51 [ V_188 ] . V_424 [ V_37 ] = V_453 ;
V_209 -> V_51 [ V_188 ] . V_425 [ V_37 ] =
V_40 & V_454 ;
V_209 -> V_51 [ V_188 ] . V_426 [ V_37 ] =
( V_40 >> V_432 ) &
V_455 ;
} else {
V_209 -> V_51 [ V_188 ] . V_424 [ V_378 ] = V_453 ;
V_209 -> V_51 [ V_188 ] . V_425 [ V_378 ] =
V_40 & V_454 ;
V_209 -> V_51 [ V_188 ] . V_426 [ V_378 ] =
( V_40 >> V_432 ) &
V_455 ;
}
} else {
if ( ! V_452 ) {
V_209 -> V_427 . V_424 [ V_37 ] = V_453 ;
V_209 -> V_427 . V_425 [ V_37 ] =
V_40 & V_454 ;
V_209 -> V_427 . V_426 [ V_37 ] =
( V_40 >> V_432 ) &
V_455 ;
} else {
V_209 -> V_427 . V_424 [ V_378 ] = V_453 ;
V_209 -> V_427 . V_425 [ V_378 ] =
V_40 & V_454 ;
V_209 -> V_427 . V_426 [ V_378 ] =
( V_40 >> V_432 ) &
V_455 ;
}
}
}
static void F_200 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_430 * V_347 = & V_4 -> V_51 . V_403 ;
struct V_137 * V_137 = F_45 ( V_88 ) ;
struct V_428 * V_209 = & V_137 -> V_51 . V_441 ;
enum V_60 V_60 = V_137 -> V_60 ;
int V_188 , V_37 , V_183 ;
T_3 V_431 ;
V_183 = F_113 ( V_2 ) ;
V_347 -> V_332 [ V_60 ] = F_3 ( F_146 ( V_60 ) ) ;
for ( V_188 = 0 ; V_188 <= V_183 ; V_188 ++ ) {
for ( V_37 = 0 ; V_37 < F_160 ( V_137 ) ; V_37 ++ )
V_347 -> V_61 [ V_60 ] [ V_37 ] [ V_188 ] =
F_3 ( F_180 ( V_60 , V_37 , V_188 ) ) ;
V_347 -> V_61 [ V_60 ] [ V_378 ] [ V_188 ] = F_3 ( F_181 ( V_60 , V_188 ) ) ;
}
for ( V_37 = 0 ; V_37 < F_160 ( V_137 ) ; V_37 ++ )
V_347 -> V_434 [ V_60 ] [ V_37 ] = F_3 ( F_182 ( V_60 , V_37 ) ) ;
V_347 -> V_434 [ V_60 ] [ V_378 ] = F_3 ( F_183 ( V_60 ) ) ;
if ( ! V_137 -> V_209 )
return;
V_347 -> V_342 [ V_60 ] = true ;
V_209 -> V_285 = V_347 -> V_332 [ V_60 ] ;
for ( V_188 = 0 ; V_188 <= V_183 ; V_188 ++ ) {
for ( V_37 = 0 ; V_37 < F_160 ( V_137 ) ; V_37 ++ ) {
V_431 = V_347 -> V_61 [ V_60 ] [ V_37 ] [ V_188 ] ;
F_199 ( V_431 , V_209 , false ,
false , V_37 , V_188 ) ;
}
V_431 = V_347 -> V_61 [ V_60 ] [ V_378 ] [ V_188 ] ;
F_199 ( V_431 , V_209 , false , true , V_37 , V_188 ) ;
}
for ( V_37 = 0 ; V_37 < F_160 ( V_137 ) ; V_37 ++ ) {
V_431 = V_347 -> V_434 [ V_60 ] [ V_37 ] ;
F_199 ( V_431 , V_209 , true , false , V_37 , 0 ) ;
}
V_431 = V_347 -> V_434 [ V_60 ] [ V_378 ] ;
F_199 ( V_431 , V_209 , true , true , V_37 , 0 ) ;
}
void F_201 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_376 * V_377 = & V_4 -> V_51 . V_403 . V_377 ;
struct V_87 * V_88 ;
F_152 ( V_4 , V_377 ) ;
F_168 (crtc, &dev->mode_config.crtc_list, head)
F_200 ( V_88 ) ;
}
static void F_202 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_321 * V_347 = & V_4 -> V_51 . V_347 ;
struct V_137 * V_137 = F_45 ( V_88 ) ;
struct V_308 * V_209 = & V_137 -> V_51 . V_209 ;
enum V_60 V_60 = V_137 -> V_60 ;
static const unsigned int V_456 [] = {
[ V_68 ] = V_351 ,
[ V_71 ] = V_352 ,
[ V_72 ] = V_353 ,
} ;
V_347 -> V_333 [ V_60 ] = F_3 ( V_456 [ V_60 ] ) ;
if ( F_115 ( V_2 ) || F_116 ( V_2 ) )
V_347 -> V_332 [ V_60 ] = F_3 ( F_146 ( V_60 ) ) ;
V_209 -> V_309 = V_137 -> V_209 ;
if ( V_209 -> V_309 ) {
T_1 V_9 = V_347 -> V_333 [ V_60 ] ;
V_209 -> V_51 [ 0 ] . V_39 = true ;
V_209 -> V_51 [ 0 ] . V_256 = ( V_9 & V_457 ) >> V_334 ;
V_209 -> V_51 [ 0 ] . V_280 = ( V_9 & V_458 ) >> V_335 ;
V_209 -> V_51 [ 0 ] . V_281 = V_9 & V_459 ;
V_209 -> V_285 = V_347 -> V_332 [ V_60 ] ;
} else {
int V_188 , V_183 = F_113 ( V_2 ) ;
for ( V_188 = 0 ; V_188 <= V_183 ; V_188 ++ )
V_209 -> V_51 [ V_188 ] . V_39 = true ;
}
}
static void F_203 ( struct V_3 * V_4 ,
struct V_138 * V_51 )
{
enum V_60 V_60 ;
T_3 V_9 ;
F_140 (dev_priv, pipe) {
V_9 = F_3 ( F_55 ( V_60 ) ) ;
V_51 -> V_139 [ V_60 ] . V_96 =
( V_9 >> V_142 ) & ( V_210 | V_460 ) ;
V_51 -> V_139 [ V_60 ] . V_120 =
( V_9 >> V_140 ) & ( V_210 | V_460 ) ;
V_51 -> V_139 [ V_60 ] . V_141 [ 0 ] =
( V_9 >> F_56 ( 0 ) ) & ( V_210 | V_460 ) ;
V_51 -> V_139 [ V_60 ] . V_141 [ 1 ] =
( V_9 >> F_56 ( 1 ) ) & ( V_210 | V_460 ) ;
}
V_9 = F_3 ( V_103 ) ;
V_51 -> V_143 . V_61 = F_204 ( V_9 , V_105 ) ;
V_51 -> V_60 [ V_71 ] . V_120 = F_204 ( V_9 , V_144 ) ;
V_51 -> V_60 [ V_71 ] . V_96 = F_205 ( V_9 , V_145 ) ;
V_51 -> V_60 [ V_68 ] . V_96 = F_205 ( V_9 , V_146 ) ;
V_9 = F_3 ( V_147 ) ;
V_51 -> V_60 [ V_68 ] . V_141 [ 1 ] = F_205 ( V_9 , V_148 ) ;
V_51 -> V_60 [ V_68 ] . V_120 = F_204 ( V_9 , V_149 ) ;
V_51 -> V_60 [ V_68 ] . V_141 [ 0 ] = F_205 ( V_9 , V_150 ) ;
V_9 = F_3 ( V_56 ) ;
V_51 -> V_143 . V_120 = F_204 ( V_9 , V_109 ) ;
if ( F_58 ( V_4 ) ) {
V_9 = F_3 ( V_151 ) ;
V_51 -> V_60 [ V_71 ] . V_141 [ 1 ] = F_205 ( V_9 , V_152 ) ;
V_51 -> V_60 [ V_71 ] . V_141 [ 0 ] = F_205 ( V_9 , V_153 ) ;
V_9 = F_3 ( V_154 ) ;
V_51 -> V_60 [ V_72 ] . V_141 [ 1 ] = F_205 ( V_9 , V_155 ) ;
V_51 -> V_60 [ V_72 ] . V_141 [ 0 ] = F_205 ( V_9 , V_156 ) ;
V_9 = F_3 ( V_157 ) ;
V_51 -> V_60 [ V_72 ] . V_96 = F_205 ( V_9 , V_158 ) ;
V_51 -> V_60 [ V_72 ] . V_120 = F_204 ( V_9 , V_159 ) ;
V_9 = F_3 ( V_160 ) ;
V_51 -> V_143 . V_61 |= F_204 ( V_9 , V_161 ) << 9 ;
V_51 -> V_60 [ V_72 ] . V_141 [ 1 ] |= F_204 ( V_9 , V_162 ) << 8 ;
V_51 -> V_60 [ V_72 ] . V_141 [ 0 ] |= F_204 ( V_9 , V_163 ) << 8 ;
V_51 -> V_60 [ V_72 ] . V_96 |= F_204 ( V_9 , V_164 ) << 8 ;
V_51 -> V_60 [ V_71 ] . V_141 [ 1 ] |= F_204 ( V_9 , V_165 ) << 8 ;
V_51 -> V_60 [ V_71 ] . V_141 [ 0 ] |= F_204 ( V_9 , V_166 ) << 8 ;
V_51 -> V_60 [ V_71 ] . V_96 |= F_204 ( V_9 , V_167 ) << 8 ;
V_51 -> V_60 [ V_68 ] . V_141 [ 1 ] |= F_204 ( V_9 , V_168 ) << 8 ;
V_51 -> V_60 [ V_68 ] . V_141 [ 0 ] |= F_204 ( V_9 , V_169 ) << 8 ;
V_51 -> V_60 [ V_68 ] . V_96 |= F_204 ( V_9 , V_170 ) << 8 ;
} else {
V_9 = F_3 ( V_171 ) ;
V_51 -> V_60 [ V_71 ] . V_141 [ 1 ] = F_205 ( V_9 , V_152 ) ;
V_51 -> V_60 [ V_71 ] . V_141 [ 0 ] = F_205 ( V_9 , V_153 ) ;
V_9 = F_3 ( V_160 ) ;
V_51 -> V_143 . V_61 |= F_204 ( V_9 , V_161 ) << 9 ;
V_51 -> V_60 [ V_71 ] . V_141 [ 1 ] |= F_204 ( V_9 , V_165 ) << 8 ;
V_51 -> V_60 [ V_71 ] . V_141 [ 0 ] |= F_204 ( V_9 , V_166 ) << 8 ;
V_51 -> V_60 [ V_71 ] . V_96 |= F_204 ( V_9 , V_167 ) << 8 ;
V_51 -> V_60 [ V_68 ] . V_141 [ 1 ] |= F_204 ( V_9 , V_168 ) << 8 ;
V_51 -> V_60 [ V_68 ] . V_141 [ 0 ] |= F_204 ( V_9 , V_169 ) << 8 ;
V_51 -> V_60 [ V_68 ] . V_96 |= F_204 ( V_9 , V_170 ) << 8 ;
}
}
void F_206 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_54 ( V_2 ) ;
struct V_138 * V_51 = & V_4 -> V_51 . V_52 ;
struct V_186 * V_61 ;
enum V_60 V_60 ;
T_1 V_40 ;
F_203 ( V_4 , V_51 ) ;
F_207 (dev, plane) {
switch ( V_61 -> V_95 . type ) {
int V_141 ;
case V_193 :
V_61 -> V_51 . V_78 = 63 ;
break;
case V_205 :
V_61 -> V_51 . V_78 = F_30 ( V_2 , V_61 -> V_60 , 0 ) ;
break;
case V_206 :
V_141 = V_61 -> V_61 ;
V_61 -> V_51 . V_78 = F_30 ( V_2 , V_61 -> V_60 , V_141 + 1 ) ;
break;
}
}
V_51 -> V_53 = F_3 ( V_49 ) & V_50 ;
V_51 -> V_188 = V_182 ;
if ( F_58 ( V_4 ) ) {
F_12 ( & V_4 -> V_41 . V_42 ) ;
V_40 = F_13 ( V_4 , V_47 ) ;
if ( V_40 & V_48 )
V_51 -> V_188 = V_184 ;
V_40 = F_13 ( V_4 , V_43 ) ;
V_40 |= V_46 ;
F_14 ( V_4 , V_43 , V_40 ) ;
if ( F_15 ( ( F_13 ( V_4 , V_43 ) &
V_46 ) == 0 , 3 ) ) {
F_10 ( L_49
L_50 ) ;
V_4 -> V_51 . V_183 = V_184 ;
} else {
V_40 = F_13 ( V_4 , V_43 ) ;
if ( ( V_40 & V_44 ) == 0 )
V_51 -> V_188 = V_185 ;
}
F_17 ( & V_4 -> V_41 . V_42 ) ;
}
F_140 (dev_priv, pipe)
F_10 ( L_51 ,
F_32 ( V_60 ) , V_51 -> V_60 [ V_60 ] . V_96 , V_51 -> V_60 [ V_60 ] . V_120 ,
V_51 -> V_60 [ V_60 ] . V_141 [ 0 ] , V_51 -> V_60 [ V_60 ] . V_141 [ 1 ] ) ;
F_10 ( L_52 ,
V_51 -> V_143 . V_61 , V_51 -> V_143 . V_120 , V_51 -> V_188 , V_51 -> V_53 ) ;
}
void F_208 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_321 * V_347 = & V_4 -> V_51 . V_347 ;
struct V_87 * V_88 ;
F_41 (dev, crtc)
F_202 ( V_88 ) ;
V_347 -> V_319 [ 0 ] = F_3 ( V_350 ) ;
V_347 -> V_319 [ 1 ] = F_3 ( V_349 ) ;
V_347 -> V_319 [ 2 ] = F_3 ( V_348 ) ;
V_347 -> V_330 [ 0 ] = F_3 ( V_360 ) ;
if ( F_69 ( V_2 ) -> V_265 >= 7 ) {
V_347 -> V_330 [ 1 ] = F_3 ( V_361 ) ;
V_347 -> V_330 [ 2 ] = F_3 ( V_362 ) ;
}
if ( F_115 ( V_2 ) || F_116 ( V_2 ) )
V_347 -> V_320 = ( F_3 ( V_354 ) & V_355 ) ?
V_272 : V_314 ;
else if ( F_120 ( V_2 ) )
V_347 -> V_320 = ( F_3 ( V_356 ) & V_357 ) ?
V_272 : V_314 ;
V_347 -> V_323 =
! ( F_3 ( V_358 ) & V_359 ) ;
}
void F_209 ( struct V_87 * V_88 )
{
struct V_3 * V_4 = V_88 -> V_2 -> V_5 ;
if ( V_4 -> V_118 . V_461 )
V_4 -> V_118 . V_461 ( V_88 ) ;
}
void F_210 ( struct V_404 * V_61 ,
struct V_87 * V_88 ,
T_3 V_446 ,
T_3 V_447 ,
int V_79 ,
bool V_89 , bool V_405 )
{
struct V_3 * V_4 = V_61 -> V_2 -> V_5 ;
if ( V_4 -> V_118 . V_462 )
V_4 -> V_118 . V_462 ( V_61 , V_88 ,
V_446 , V_447 ,
V_79 , V_89 , V_405 ) ;
}
bool F_211 ( struct V_1 * V_2 , T_7 V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_463 ;
F_212 ( & V_464 ) ;
V_463 = F_6 ( V_465 ) ;
if ( V_463 & V_466 ) {
F_213 ( L_53 ) ;
return false ;
}
V_463 = ( V_467 << V_468 ) |
( V_40 << V_469 ) | V_470 ;
F_214 ( V_465 , V_463 ) ;
F_215 ( V_465 ) ;
V_463 |= V_466 ;
F_214 ( V_465 , V_463 ) ;
return true ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_471 = F_3 ( V_472 ) ;
T_7 V_473 , V_474 , V_475 , V_476 ;
F_217 ( & V_464 ) ;
F_214 ( V_477 , F_3 ( V_477 ) | V_478 ) ;
F_214 ( V_479 , F_3 ( V_479 ) | V_480 ) ;
F_2 ( V_481 , 100000 ) ;
F_2 ( V_482 , 100000 ) ;
F_2 ( V_483 , 90000 ) ;
F_2 ( V_484 , 80000 ) ;
F_2 ( V_485 , 1 ) ;
V_473 = ( V_471 & V_486 ) >> V_487 ;
V_474 = ( V_471 & V_488 ) ;
V_475 = ( V_471 & V_489 ) >>
V_490 ;
V_476 = ( F_3 ( F_218 ( V_475 ) ) & V_491 ) >>
V_492 ;
V_4 -> V_29 . V_473 = V_473 ;
V_4 -> V_29 . V_475 = V_475 ;
V_4 -> V_29 . V_493 = V_475 ;
V_4 -> V_29 . V_494 = V_474 ;
V_4 -> V_29 . V_495 = V_475 ;
F_7 ( L_54 ,
V_473 , V_474 , V_475 ) ;
F_2 ( V_496 , V_497 | V_498 ) ;
F_2 ( V_499 , V_476 ) ;
F_21 ( V_499 ) ;
V_471 |= V_500 ;
F_2 ( V_472 , V_471 ) ;
if ( F_219 ( ( F_3 ( V_465 ) & V_466 ) == 0 , 10 ) )
F_16 ( L_55 ) ;
F_220 ( 1 ) ;
F_211 ( V_2 , V_475 ) ;
V_4 -> V_29 . V_501 = F_3 ( V_502 ) +
F_3 ( V_503 ) + F_3 ( V_504 ) ;
V_4 -> V_29 . V_505 = F_221 ( V_506 ) ;
V_4 -> V_29 . V_507 = F_3 ( V_508 ) ;
V_4 -> V_29 . V_509 = F_222 () ;
F_223 ( & V_464 ) ;
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_463 ;
F_217 ( & V_464 ) ;
V_463 = F_6 ( V_465 ) ;
F_2 ( V_496 , F_3 ( V_496 ) & ~ V_498 ) ;
F_2 ( V_510 , V_511 ) ;
F_2 ( V_512 , F_3 ( V_512 ) & ~ V_513 ) ;
F_2 ( V_514 , V_513 ) ;
F_2 ( V_515 , F_3 ( V_515 ) | V_513 ) ;
F_211 ( V_2 , V_4 -> V_29 . V_475 ) ;
F_220 ( 1 ) ;
V_463 |= V_466 ;
F_2 ( V_465 , V_463 ) ;
F_220 ( 1 ) ;
F_223 ( & V_464 ) ;
}
static T_1 F_225 ( struct V_3 * V_4 , T_7 V_40 )
{
T_1 V_516 ;
if ( F_112 ( V_4 -> V_2 ) ) {
V_516 = ( V_4 -> V_41 . V_517 ) << 23 ;
if ( V_40 <= V_4 -> V_41 . V_518 )
V_516 |= ( V_4 -> V_41 . V_518 ) << 14 ;
} else {
V_516 = V_4 -> V_41 . V_517 << 24 ;
if ( V_40 <= V_4 -> V_41 . V_518 )
V_516 |= V_4 -> V_41 . V_518 << 16 ;
}
return V_516 ;
}
static void F_226 ( struct V_3 * V_4 , T_7 V_40 )
{
int V_519 ;
T_1 V_520 = 0 , V_521 = 0 ;
T_1 V_522 = 0 , V_523 = 0 ;
V_519 = V_4 -> V_41 . V_524 ;
switch ( V_4 -> V_41 . V_524 ) {
case V_525 :
if ( V_40 > V_4 -> V_41 . V_526 + 1 && V_40 > V_4 -> V_41 . V_527 )
V_519 = V_528 ;
break;
case V_528 :
if ( V_40 <= V_4 -> V_41 . V_526 && V_40 < V_4 -> V_41 . V_527 )
V_519 = V_525 ;
else if ( V_40 >= V_4 -> V_41 . V_529 && V_40 > V_4 -> V_41 . V_527 )
V_519 = V_530 ;
break;
case V_530 :
if ( V_40 < ( V_4 -> V_41 . V_531 + V_4 -> V_41 . V_529 ) > > 1 && V_40 < V_4 -> V_41 . V_527 )
V_519 = V_528 ;
break;
}
if ( V_40 <= V_4 -> V_41 . V_518 )
V_519 = V_525 ;
if ( V_40 >= V_4 -> V_41 . V_517 )
V_519 = V_530 ;
if ( V_519 == V_4 -> V_41 . V_524 )
return;
switch ( V_519 ) {
case V_525 :
V_522 = 16000 ;
V_520 = 95 ;
V_523 = 32000 ;
V_521 = 85 ;
break;
case V_528 :
V_522 = 13000 ;
V_520 = 90 ;
V_523 = 32000 ;
V_521 = 75 ;
break;
case V_530 :
V_522 = 10000 ;
V_520 = 85 ;
V_523 = 32000 ;
V_521 = 60 ;
break;
}
F_2 ( V_532 ,
F_227 ( V_4 , V_522 ) ) ;
F_2 ( V_533 ,
F_227 ( V_4 , ( V_522 * V_520 / 100 ) ) ) ;
F_2 ( V_534 ,
F_227 ( V_4 , V_523 ) ) ;
F_2 ( V_535 ,
F_227 ( V_4 , ( V_523 * V_521 / 100 ) ) ) ;
F_2 ( V_536 ,
V_537 |
V_538 |
V_539 |
V_540 |
V_541 |
V_542 ) ;
V_4 -> V_41 . V_524 = V_519 ;
V_4 -> V_41 . V_543 = V_520 ;
V_4 -> V_41 . V_544 = V_521 ;
V_4 -> V_41 . V_545 = 0 ;
}
static T_1 F_228 ( struct V_3 * V_4 , T_7 V_40 )
{
T_1 V_546 = 0 ;
if ( V_40 > V_4 -> V_41 . V_518 )
V_546 |= V_547 | V_548 | V_549 ;
if ( V_40 < V_4 -> V_41 . V_517 )
V_546 |= V_550 | V_551 ;
V_546 &= V_4 -> V_552 ;
return F_229 ( V_4 , ~ V_546 ) ;
}
static void F_230 ( struct V_1 * V_2 , T_7 V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_149 ( V_2 ) && ( F_231 ( V_2 ) < V_553 ) )
return;
F_63 ( ! F_232 ( & V_4 -> V_41 . V_42 ) ) ;
F_63 ( V_40 > V_4 -> V_41 . V_554 ) ;
F_63 ( V_40 < V_4 -> V_41 . V_555 ) ;
if ( V_40 != V_4 -> V_41 . V_527 ) {
F_226 ( V_4 , V_40 ) ;
if ( F_112 ( V_2 ) )
F_2 ( V_556 ,
F_233 ( V_40 ) ) ;
else if ( F_115 ( V_2 ) || F_116 ( V_2 ) )
F_2 ( V_556 ,
F_234 ( V_40 ) ) ;
else
F_2 ( V_556 ,
F_235 ( V_40 ) |
F_236 ( 0 ) |
V_557 ) ;
}
F_2 ( V_558 , F_225 ( V_4 , V_40 ) ) ;
F_2 ( V_559 , F_228 ( V_4 , V_40 ) ) ;
F_21 ( V_556 ) ;
V_4 -> V_41 . V_527 = V_40 ;
F_237 ( F_238 ( V_4 , V_40 ) ) ;
}
static void F_239 ( struct V_1 * V_2 , T_7 V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_63 ( ! F_232 ( & V_4 -> V_41 . V_42 ) ) ;
F_63 ( V_40 > V_4 -> V_41 . V_554 ) ;
F_63 ( V_40 < V_4 -> V_41 . V_555 ) ;
if ( F_240 ( F_58 ( V_2 ) && ( V_40 & 1 ) ,
L_56 ) )
V_40 &= ~ 1 ;
F_2 ( V_559 , F_228 ( V_4 , V_40 ) ) ;
if ( V_40 != V_4 -> V_41 . V_527 ) {
F_14 ( V_4 , V_560 , V_40 ) ;
if ( ! F_58 ( V_4 ) )
F_226 ( V_4 , V_40 ) ;
}
V_4 -> V_41 . V_527 = V_40 ;
F_237 ( F_238 ( V_4 , V_40 ) ) ;
}
static void F_241 ( struct V_3 * V_4 )
{
T_1 V_40 = V_4 -> V_41 . V_561 ;
if ( V_4 -> V_41 . V_527 <= V_40 )
return;
F_242 ( V_4 , V_562 ) ;
F_239 ( V_4 -> V_2 , V_40 ) ;
F_243 ( V_4 , V_562 ) ;
}
void F_244 ( struct V_3 * V_4 )
{
F_12 ( & V_4 -> V_41 . V_42 ) ;
if ( V_4 -> V_41 . V_89 ) {
if ( V_4 -> V_552 & ( V_547 | V_550 ) )
F_245 ( V_4 ) ;
F_2 ( V_559 ,
F_228 ( V_4 , V_4 -> V_41 . V_527 ) ) ;
}
F_17 ( & V_4 -> V_41 . V_42 ) ;
}
void F_246 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
if ( V_4 -> V_41 . V_89 ) {
if ( F_20 ( V_2 ) )
F_241 ( V_4 ) ;
else
F_230 ( V_4 -> V_2 , V_4 -> V_41 . V_561 ) ;
V_4 -> V_41 . V_545 = 0 ;
F_2 ( V_559 , 0xffffffff ) ;
}
F_17 ( & V_4 -> V_41 . V_42 ) ;
F_247 ( & V_4 -> V_41 . V_563 ) ;
while ( ! F_248 ( & V_4 -> V_41 . V_564 ) )
F_249 ( V_4 -> V_41 . V_564 . V_565 ) ;
F_250 ( & V_4 -> V_41 . V_563 ) ;
}
void F_251 ( struct V_3 * V_4 ,
struct V_566 * V_41 ,
unsigned long V_567 )
{
if ( ! ( V_4 -> V_568 . V_569 &&
V_4 -> V_41 . V_89 &&
V_4 -> V_41 . V_527 < V_4 -> V_41 . V_517 ) )
return;
if ( V_41 && F_252 ( V_506 , V_567 + V_570 ) )
V_41 = NULL ;
F_247 ( & V_4 -> V_41 . V_563 ) ;
if ( V_41 == NULL || F_248 ( & V_41 -> V_571 ) ) {
F_217 ( & V_4 -> V_572 ) ;
if ( V_4 -> V_41 . V_573 ) {
V_4 -> V_41 . V_574 = true ;
F_253 ( V_4 -> V_575 , & V_4 -> V_41 . V_576 ) ;
}
F_223 ( & V_4 -> V_572 ) ;
if ( V_41 != NULL ) {
F_254 ( & V_41 -> V_571 , & V_4 -> V_41 . V_564 ) ;
V_41 -> V_577 ++ ;
} else
V_4 -> V_41 . V_577 ++ ;
}
F_250 ( & V_4 -> V_41 . V_563 ) ;
}
void F_255 ( struct V_1 * V_2 , T_7 V_40 )
{
if ( F_20 ( V_2 ) )
F_239 ( V_2 , V_40 ) ;
else
F_230 ( V_2 , V_40 ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_578 , 0 ) ;
F_2 ( V_579 , 0 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_578 , 0 ) ;
F_2 ( V_556 , 1 << 31 ) ;
}
static void F_258 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_578 , 0 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_242 ( V_4 , V_580 ) ;
F_2 ( V_578 , 0 ) ;
F_243 ( V_4 , V_580 ) ;
}
static void F_260 ( struct V_1 * V_2 , T_1 V_581 )
{
if ( F_20 ( V_2 ) ) {
if ( V_581 & ( V_582 | F_261 ( 1 ) ) )
V_581 = V_583 ;
else
V_581 = 0 ;
}
if ( F_262 ( V_2 ) )
F_10 ( L_57 ,
( V_581 & V_583 ) ? L_58 : L_59 ,
( V_581 & V_584 ) ? L_58 : L_59 ,
( V_581 & V_585 ) ? L_58 : L_59 ) ;
else
F_10 ( L_60 ,
( V_581 & V_583 ) ? L_58 : L_59 ) ;
}
static int F_263 ( const struct V_1 * V_2 , int V_586 )
{
if ( F_69 ( V_2 ) -> V_265 < 6 )
return 0 ;
if ( V_586 >= 0 ) {
int V_546 ;
if ( F_262 ( V_2 ) )
V_546 = V_587 | V_588 |
V_589 ;
else
V_546 = V_587 ;
if ( ( V_586 & V_546 ) != V_586 )
F_10 ( L_61 ,
V_586 & V_546 , V_586 , V_546 ) ;
return V_586 & V_546 ;
}
if ( F_120 ( V_2 ) )
return ( V_587 | V_588 ) ;
return V_587 ;
}
int F_264 ( const struct V_1 * V_2 )
{
return V_590 . V_586 ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_591 ;
T_1 V_592 = 0 ;
int V_180 ;
V_4 -> V_41 . V_527 = 0 ;
if ( F_149 ( V_2 ) ) {
V_591 = F_3 ( V_593 ) ;
V_4 -> V_41 . V_529 = ( V_591 >> 16 ) & 0xff ;
V_4 -> V_41 . V_531 = ( V_591 >> 8 ) & 0xff ;
V_4 -> V_41 . V_555 = ( V_591 >> 0 ) & 0xff ;
} else {
V_591 = F_3 ( V_594 ) ;
V_4 -> V_41 . V_529 = ( V_591 >> 0 ) & 0xff ;
V_4 -> V_41 . V_531 = ( V_591 >> 8 ) & 0xff ;
V_4 -> V_41 . V_555 = ( V_591 >> 16 ) & 0xff ;
}
V_4 -> V_41 . V_554 = V_4 -> V_41 . V_529 ;
V_4 -> V_41 . V_526 = V_4 -> V_41 . V_531 ;
if ( F_115 ( V_2 ) || F_116 ( V_2 ) || F_266 ( V_2 ) ) {
V_180 = F_114 ( V_4 ,
V_595 ,
& V_592 ) ;
if ( 0 == V_180 )
V_4 -> V_41 . V_526 =
F_267 ( T_7 ,
( ( V_592 >> 8 ) & 0xff ) ,
V_4 -> V_41 . V_555 ,
V_4 -> V_41 . V_554 ) ;
}
if ( F_266 ( V_2 ) ) {
V_4 -> V_41 . V_529 *= V_596 ;
V_4 -> V_41 . V_531 *= V_596 ;
V_4 -> V_41 . V_555 *= V_596 ;
V_4 -> V_41 . V_554 *= V_596 ;
V_4 -> V_41 . V_526 *= V_596 ;
}
V_4 -> V_41 . V_561 = V_4 -> V_41 . V_555 ;
if ( V_4 -> V_41 . V_517 == 0 )
V_4 -> V_41 . V_517 = V_4 -> V_41 . V_554 ;
if ( V_4 -> V_41 . V_518 == 0 ) {
if ( F_115 ( V_2 ) || F_116 ( V_2 ) )
V_4 -> V_41 . V_518 =
F_123 ( int , V_4 -> V_41 . V_526 ,
F_268 ( V_4 , 450 ) ) ;
else
V_4 -> V_41 . V_518 =
V_4 -> V_41 . V_555 ;
}
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_242 ( V_4 , V_580 ) ;
F_265 ( V_2 ) ;
if ( F_149 ( V_2 ) && ( F_231 ( V_2 ) < V_553 ) ) {
F_243 ( V_4 , V_580 ) ;
return;
}
F_2 ( V_597 ,
F_233 ( V_4 -> V_41 . V_531 ) ) ;
F_2 ( V_598 ,
F_227 ( V_4 , 1000000 ) ) ;
F_2 ( V_599 , 0xa ) ;
V_4 -> V_41 . V_524 = V_530 ;
F_230 ( V_4 -> V_2 , V_4 -> V_41 . V_518 ) ;
F_243 ( V_4 , V_580 ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_600 * V_601 ;
T_3 V_602 = 0 ;
int V_603 ;
F_2 ( V_604 , 0 ) ;
F_242 ( V_4 , V_580 ) ;
F_2 ( V_578 , 0 ) ;
if ( F_266 ( V_2 ) )
F_2 ( V_605 , 108 << 16 ) ;
else
F_2 ( V_605 , 54 << 16 ) ;
F_2 ( V_606 , 125000 ) ;
F_2 ( V_607 , 25 ) ;
F_271 (ring, dev_priv, unused)
F_2 ( F_272 ( V_601 -> V_608 ) , 10 ) ;
if ( F_273 ( V_2 ) )
F_2 ( V_609 , 0xA ) ;
F_2 ( V_610 , 0 ) ;
F_2 ( V_611 , 25 ) ;
F_2 ( V_612 , 25 ) ;
if ( F_264 ( V_2 ) & V_587 )
V_602 = V_583 ;
F_274 ( L_62 , ( V_602 & V_583 ) ?
L_58 : L_59 ) ;
if ( ( F_266 ( V_2 ) && F_231 ( V_2 ) <= V_613 ) ||
( F_149 ( V_2 ) && F_231 ( V_2 ) <= V_614 ) ) {
F_2 ( V_615 , 625 ) ;
F_2 ( V_578 , V_616 |
V_582 |
V_602 ) ;
} else {
F_2 ( V_615 , 37500 ) ;
F_2 ( V_578 , V_616 |
F_261 ( 1 ) |
V_602 ) ;
}
if ( ( F_149 ( V_2 ) && ( F_231 ( V_2 ) < V_553 ) ) ||
( ( F_275 ( V_2 ) || F_276 ( V_2 ) ) && ( F_231 ( V_2 ) <= V_617 ) ) )
F_2 ( V_579 , 0 ) ;
else
F_2 ( V_579 , ( V_602 & V_583 ) ?
( V_618 | V_619 ) : 0 ) ;
F_243 ( V_4 , V_580 ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_600 * V_601 ;
T_3 V_602 = 0 ;
int V_603 ;
F_2 ( V_604 , 0 ) ;
F_242 ( V_4 , V_580 ) ;
F_2 ( V_578 , 0 ) ;
F_265 ( V_2 ) ;
F_2 ( V_605 , 40 << 16 ) ;
F_2 ( V_606 , 125000 ) ;
F_2 ( V_607 , 25 ) ;
F_271 (ring, dev_priv, unused)
F_2 ( F_272 ( V_601 -> V_608 ) , 10 ) ;
F_2 ( V_610 , 0 ) ;
if ( F_116 ( V_2 ) )
F_2 ( V_615 , 625 ) ;
else
F_2 ( V_615 , 50000 ) ;
if ( F_264 ( V_2 ) & V_587 )
V_602 = V_583 ;
F_260 ( V_2 , V_602 ) ;
if ( F_116 ( V_2 ) )
F_2 ( V_578 , V_616 |
V_582 |
V_602 ) ;
else
F_2 ( V_578 , V_616 |
F_261 ( 1 ) |
V_602 ) ;
F_2 ( V_556 ,
F_234 ( V_4 -> V_41 . V_531 ) ) ;
F_2 ( V_597 ,
F_234 ( V_4 -> V_41 . V_531 ) ) ;
F_2 ( V_598 , 100000000 / 128 ) ;
F_2 ( V_558 ,
V_4 -> V_41 . V_517 << 24 |
V_4 -> V_41 . V_518 << 16 ) ;
F_2 ( V_533 , 7600000 / 128 ) ;
F_2 ( V_535 , 31300000 / 128 ) ;
F_2 ( V_532 , 66000 ) ;
F_2 ( V_534 , 350000 ) ;
F_2 ( V_599 , 10 ) ;
F_2 ( V_536 ,
V_537 |
V_538 |
V_539 |
V_540 |
V_541 |
V_542 ) ;
V_4 -> V_41 . V_524 = V_530 ;
F_230 ( V_4 -> V_2 , V_4 -> V_41 . V_561 ) ;
F_243 ( V_4 , V_580 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_600 * V_601 ;
T_1 V_620 , V_621 = 0 , V_602 = 0 ;
T_1 V_622 ;
int V_623 ;
int V_37 , V_180 ;
F_63 ( ! F_232 ( & V_4 -> V_41 . V_42 ) ) ;
F_2 ( V_604 , 0 ) ;
if ( ( V_622 = F_3 ( V_624 ) ) ) {
F_16 ( L_63 , V_622 ) ;
F_2 ( V_624 , V_622 ) ;
}
F_242 ( V_4 , V_580 ) ;
F_265 ( V_2 ) ;
F_2 ( V_578 , 0 ) ;
F_2 ( V_625 , 1000 << 16 ) ;
F_2 ( V_605 , 40 << 16 | 30 ) ;
F_2 ( V_626 , 30 ) ;
F_2 ( V_606 , 125000 ) ;
F_2 ( V_607 , 25 ) ;
F_271 (ring, dev_priv, i)
F_2 ( F_272 ( V_601 -> V_608 ) , 10 ) ;
F_2 ( V_610 , 0 ) ;
F_2 ( V_627 , 1000 ) ;
if ( F_120 ( V_2 ) )
F_2 ( V_615 , 125000 ) ;
else
F_2 ( V_615 , 50000 ) ;
F_2 ( V_628 , 150000 ) ;
F_2 ( V_629 , 64000 ) ;
V_623 = F_264 ( V_4 -> V_2 ) ;
if ( V_623 & V_587 )
V_602 |= V_583 ;
if ( ! F_115 ( V_2 ) ) {
if ( V_623 & V_588 )
V_602 |= V_584 ;
if ( V_623 & V_589 )
V_602 |= V_585 ;
}
F_260 ( V_2 , V_602 ) ;
F_2 ( V_578 ,
V_602 |
F_261 ( 1 ) |
V_616 ) ;
F_2 ( V_598 , 50000 ) ;
F_2 ( V_599 , 10 ) ;
V_180 = F_279 ( V_4 , V_630 , 0 ) ;
if ( V_180 )
F_7 ( L_64 ) ;
V_180 = F_114 ( V_4 , V_631 , & V_621 ) ;
if ( ! V_180 && ( V_621 & ( 1 << 31 ) ) ) {
F_7 ( L_65 ,
( V_4 -> V_41 . V_517 & 0xff ) * 50 ,
( V_621 & 0xff ) * 50 ) ;
V_4 -> V_41 . V_554 = V_621 & 0xff ;
}
V_4 -> V_41 . V_524 = V_530 ;
F_230 ( V_4 -> V_2 , V_4 -> V_41 . V_561 ) ;
V_620 = 0 ;
V_180 = F_114 ( V_4 , V_632 , & V_620 ) ;
if ( F_126 ( V_2 ) && V_180 ) {
F_7 ( L_66 ) ;
} else if ( F_126 ( V_2 ) && ( F_280 ( V_620 & 0xff ) < 450 ) ) {
F_7 ( L_67 ,
F_280 ( V_620 & 0xff ) , 450 ) ;
V_620 &= 0xffff00 ;
V_620 |= F_281 ( 450 ) ;
V_180 = F_279 ( V_4 , V_633 , V_620 ) ;
if ( V_180 )
F_16 ( L_68 ) ;
}
F_243 ( V_4 , V_580 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_555 = 15 ;
unsigned int V_634 ;
unsigned int V_635 , V_636 ;
unsigned int V_637 , V_638 ;
int V_639 = 180 ;
struct V_640 * V_641 ;
F_63 ( ! F_232 ( & V_4 -> V_41 . V_42 ) ) ;
V_641 = F_283 ( 0 ) ;
if ( V_641 ) {
V_635 = V_641 -> V_642 . V_554 ;
F_284 ( V_641 ) ;
} else {
V_635 = V_643 ;
}
V_635 /= 1000 ;
V_636 = F_3 ( V_644 ) & 0xf ;
V_636 = F_285 ( V_636 , 8 , 3 ) ;
if ( F_266 ( V_2 ) ) {
V_638 = V_4 -> V_41 . V_555 / V_596 ;
V_637 = V_4 -> V_41 . V_554 / V_596 ;
} else {
V_638 = V_4 -> V_41 . V_555 ;
V_637 = V_4 -> V_41 . V_554 ;
}
for ( V_634 = V_637 ; V_634 >= V_638 ; V_634 -- ) {
int V_645 = V_637 - V_634 ;
unsigned int V_646 = 0 , V_647 = 0 ;
if ( F_266 ( V_2 ) ) {
V_647 = V_634 ;
} else if ( F_69 ( V_2 ) -> V_265 >= 8 ) {
V_647 = F_49 ( V_636 , V_634 ) ;
} else if ( F_115 ( V_2 ) ) {
V_647 = F_285 ( V_634 , 5 , 4 ) ;
V_647 = F_49 ( V_636 , V_647 ) ;
} else {
if ( V_634 < V_555 )
V_646 = 800 ;
else
V_646 = V_635 - ( ( V_645 * V_639 ) / 2 ) ;
V_646 = F_108 ( V_646 , 100 ) ;
}
F_279 ( V_4 ,
V_630 ,
V_646 << V_648 |
V_647 << V_649 |
V_634 ) ;
}
}
void F_286 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_287 ( V_2 ) )
return;
F_12 ( & V_4 -> V_41 . V_42 ) ;
F_282 ( V_2 ) ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
}
static int F_288 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_40 , V_650 ;
V_40 = F_13 ( V_4 , V_651 ) ;
switch ( F_69 ( V_2 ) -> V_652 ) {
case 8 :
V_650 = ( V_40 >> V_653 ) ;
break;
case 12 :
V_650 = ( V_40 >> V_654 ) ;
break;
case 16 :
default:
V_650 = ( V_40 >> V_655 ) ;
break;
}
V_650 = ( V_650 & V_656 ) ;
return V_650 ;
}
static int F_289 ( struct V_3 * V_4 )
{
T_1 V_40 , V_657 ;
V_40 = F_13 ( V_4 , V_658 ) ;
V_657 = ( V_40 >> V_659 ) & V_660 ;
return V_657 ;
}
static int F_290 ( struct V_3 * V_4 )
{
T_1 V_40 , V_661 ;
V_40 = F_13 ( V_4 , V_651 ) ;
V_661 = ( V_40 & V_656 ) ;
return V_661 ;
}
static int F_291 ( struct V_3 * V_4 )
{
T_1 V_40 , V_661 ;
V_40 = F_292 ( V_4 , V_662 ) ;
V_661 = ( V_40 & V_663 ) >> V_664 ;
return V_661 ;
}
static int F_293 ( struct V_3 * V_4 )
{
T_1 V_40 , V_650 ;
V_40 = F_292 ( V_4 , V_662 ) ;
V_650 = ( V_40 & V_665 ) >> V_666 ;
V_650 = F_64 ( T_1 , V_650 , 0xea ) ;
return V_650 ;
}
static int F_294 ( struct V_3 * V_4 )
{
T_1 V_40 , V_657 ;
V_40 = F_292 ( V_4 , V_667 ) ;
V_657 = ( V_40 & V_668 ) >> V_669 ;
V_40 = F_292 ( V_4 , V_670 ) ;
V_657 |= ( V_40 & V_671 ) << 5 ;
return V_657 ;
}
static int F_295 ( struct V_3 * V_4 )
{
return F_13 ( V_4 , V_672 ) & 0xff ;
}
static void F_296 ( struct V_3 * V_4 )
{
unsigned long V_673 = F_3 ( V_674 ) & ~ 4095 ;
F_63 ( V_673 != V_4 -> V_568 . V_675 +
V_4 -> V_676 -> V_677 -> V_371 ) ;
}
static void F_297 ( struct V_3 * V_4 )
{
unsigned long V_673 = F_3 ( V_674 ) & ~ 4095 ;
F_63 ( ( V_673 >> V_678 ) == 0 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_679 , V_680 ;
struct V_681 * V_682 = & V_4 -> V_682 ;
T_1 V_683 ;
int V_684 = 32 * 1024 ;
F_63 ( ! F_232 ( & V_2 -> V_685 ) ) ;
V_683 = F_3 ( V_674 ) ;
if ( ( V_683 >> V_678 ) == 0 ) {
F_7 ( L_69 ) ;
V_680 = ( V_4 -> V_568 . V_675 +
( V_682 -> V_686 - V_684 ) ) ;
V_679 = ( V_680 & ( ~ 4095 ) ) ;
F_2 ( V_674 , V_679 ) ;
}
F_7 ( L_70 , F_3 ( V_674 ) ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_238 * V_687 ;
unsigned long V_679 ;
T_1 V_683 ;
int V_684 = 24 * 1024 ;
F_63 ( ! F_232 ( & V_2 -> V_685 ) ) ;
V_683 = F_3 ( V_674 ) ;
if ( V_683 ) {
int V_688 ;
V_688 = ( V_683 & ( ~ 4095 ) ) - V_4 -> V_568 . V_675 ;
V_687 = F_300 ( V_4 -> V_2 ,
V_688 ,
V_689 ,
V_684 ) ;
goto V_690;
}
F_7 ( L_69 ) ;
V_687 = F_301 ( V_2 , V_684 ) ;
if ( ! V_687 ) {
F_213 ( L_71 ) ;
return;
}
V_679 = V_4 -> V_568 . V_675 + V_687 -> V_677 -> V_371 ;
F_2 ( V_674 , V_679 ) ;
V_690:
F_7 ( L_70 , F_3 ( V_674 ) ) ;
V_4 -> V_676 = V_687 ;
}
static void F_302 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_63 ( ! V_4 -> V_676 ) )
return;
F_303 ( & V_4 -> V_676 -> V_95 ) ;
V_4 -> V_676 = NULL ;
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_40 ;
F_299 ( V_2 ) ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
V_40 = F_13 ( V_4 , V_691 ) ;
switch ( ( V_40 >> 6 ) & 3 ) {
case 0 :
case 1 :
V_4 -> V_19 = 800 ;
break;
case 2 :
V_4 -> V_19 = 1066 ;
break;
case 3 :
V_4 -> V_19 = 1333 ;
break;
}
F_7 ( L_72 , V_4 -> V_19 ) ;
V_4 -> V_41 . V_554 = F_293 ( V_4 ) ;
V_4 -> V_41 . V_529 = V_4 -> V_41 . V_554 ;
F_7 ( L_73 ,
F_238 ( V_4 , V_4 -> V_41 . V_554 ) ,
V_4 -> V_41 . V_554 ) ;
V_4 -> V_41 . V_526 = F_294 ( V_4 ) ;
F_7 ( L_74 ,
F_238 ( V_4 , V_4 -> V_41 . V_526 ) ,
V_4 -> V_41 . V_526 ) ;
V_4 -> V_41 . V_531 = F_291 ( V_4 ) ;
F_7 ( L_75 ,
F_238 ( V_4 , V_4 -> V_41 . V_531 ) ,
V_4 -> V_41 . V_531 ) ;
V_4 -> V_41 . V_555 = F_295 ( V_4 ) ;
F_7 ( L_76 ,
F_238 ( V_4 , V_4 -> V_41 . V_555 ) ,
V_4 -> V_41 . V_555 ) ;
V_4 -> V_41 . V_561 = V_4 -> V_41 . V_555 ;
if ( V_4 -> V_41 . V_517 == 0 )
V_4 -> V_41 . V_517 = V_4 -> V_41 . V_554 ;
if ( V_4 -> V_41 . V_518 == 0 )
V_4 -> V_41 . V_518 = V_4 -> V_41 . V_555 ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_40 ;
F_298 ( V_2 ) ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
F_12 ( & V_4 -> V_692 ) ;
V_40 = F_306 ( V_4 , V_693 ) ;
F_17 ( & V_4 -> V_692 ) ;
switch ( ( V_40 >> 2 ) & 0x7 ) {
case 3 :
V_4 -> V_19 = 2000 ;
break;
default:
V_4 -> V_19 = 1600 ;
break;
}
F_7 ( L_72 , V_4 -> V_19 ) ;
V_4 -> V_41 . V_554 = F_288 ( V_4 ) ;
V_4 -> V_41 . V_529 = V_4 -> V_41 . V_554 ;
F_7 ( L_73 ,
F_238 ( V_4 , V_4 -> V_41 . V_554 ) ,
V_4 -> V_41 . V_554 ) ;
V_4 -> V_41 . V_526 = F_289 ( V_4 ) ;
F_7 ( L_74 ,
F_238 ( V_4 , V_4 -> V_41 . V_526 ) ,
V_4 -> V_41 . V_526 ) ;
V_4 -> V_41 . V_531 = F_290 ( V_4 ) ;
F_7 ( L_77 ,
F_238 ( V_4 , V_4 -> V_41 . V_531 ) ,
V_4 -> V_41 . V_531 ) ;
V_4 -> V_41 . V_555 = V_4 -> V_41 . V_526 ;
F_7 ( L_76 ,
F_238 ( V_4 , V_4 -> V_41 . V_555 ) ,
V_4 -> V_41 . V_555 ) ;
F_240 ( ( V_4 -> V_41 . V_554 |
V_4 -> V_41 . V_526 |
V_4 -> V_41 . V_531 |
V_4 -> V_41 . V_555 ) & 1 ,
L_78 ) ;
V_4 -> V_41 . V_561 = V_4 -> V_41 . V_555 ;
if ( V_4 -> V_41 . V_517 == 0 )
V_4 -> V_41 . V_517 = V_4 -> V_41 . V_554 ;
if ( V_4 -> V_41 . V_518 == 0 )
V_4 -> V_41 . V_518 = V_4 -> V_41 . V_555 ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
}
static void F_307 ( struct V_1 * V_2 )
{
F_302 ( V_2 ) ;
}
static void F_308 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_600 * V_601 ;
T_1 V_622 , V_40 , V_623 = 0 , V_683 ;
int V_37 ;
F_63 ( ! F_232 ( & V_4 -> V_41 . V_42 ) ) ;
V_622 = F_3 ( V_624 ) ;
if ( V_622 ) {
F_7 ( L_63 ,
V_622 ) ;
F_2 ( V_624 , V_622 ) ;
}
F_297 ( V_4 ) ;
F_242 ( V_4 , V_580 ) ;
F_2 ( V_578 , 0 ) ;
F_2 ( V_605 , 40 << 16 ) ;
F_2 ( V_606 , 125000 ) ;
F_2 ( V_607 , 25 ) ;
F_271 (ring, dev_priv, i)
F_2 ( F_272 ( V_601 -> V_608 ) , 10 ) ;
F_2 ( V_610 , 0 ) ;
F_2 ( V_615 , 0x186 ) ;
F_2 ( V_694 ,
F_27 ( V_695 |
V_696 |
V_697 ) ) ;
V_683 = F_3 ( V_674 ) ;
if ( ( F_264 ( V_2 ) & V_587 ) &&
( V_683 >> V_678 ) )
V_623 = V_582 ;
F_2 ( V_578 , V_623 ) ;
F_2 ( V_598 , 1000000 ) ;
F_2 ( V_533 , 59400 ) ;
F_2 ( V_535 , 245000 ) ;
F_2 ( V_532 , 66000 ) ;
F_2 ( V_534 , 350000 ) ;
F_2 ( V_599 , 10 ) ;
F_2 ( V_536 ,
V_538 |
V_539 |
V_540 |
V_541 |
V_542 ) ;
V_40 = V_698 |
V_699 |
V_700 ;
F_14 ( V_4 , V_701 , V_40 ) ;
V_40 = F_13 ( V_4 , V_691 ) ;
F_240 ( ( V_40 & V_702 ) == 0 , L_79 ) ;
F_7 ( L_80 , F_309 ( V_40 & V_702 ) ) ;
F_7 ( L_81 , V_40 ) ;
V_4 -> V_41 . V_527 = ( V_40 >> 8 ) & 0xff ;
F_7 ( L_82 ,
F_238 ( V_4 , V_4 -> V_41 . V_527 ) ,
V_4 -> V_41 . V_527 ) ;
F_7 ( L_83 ,
F_238 ( V_4 , V_4 -> V_41 . V_526 ) ,
V_4 -> V_41 . V_526 ) ;
F_239 ( V_4 -> V_2 , V_4 -> V_41 . V_526 ) ;
F_243 ( V_4 , V_580 ) ;
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_600 * V_601 ;
T_1 V_622 , V_40 , V_623 = 0 ;
int V_37 ;
F_63 ( ! F_232 ( & V_4 -> V_41 . V_42 ) ) ;
F_296 ( V_4 ) ;
if ( ( V_622 = F_3 ( V_624 ) ) ) {
F_7 ( L_63 ,
V_622 ) ;
F_2 ( V_624 , V_622 ) ;
}
F_242 ( V_4 , V_580 ) ;
F_2 ( V_578 , 0 ) ;
F_2 ( V_598 , 1000000 ) ;
F_2 ( V_533 , 59400 ) ;
F_2 ( V_535 , 245000 ) ;
F_2 ( V_532 , 66000 ) ;
F_2 ( V_534 , 350000 ) ;
F_2 ( V_599 , 10 ) ;
F_2 ( V_536 ,
V_537 |
V_538 |
V_539 |
V_540 |
V_541 |
V_703 ) ;
F_2 ( V_605 , 0x00280000 ) ;
F_2 ( V_606 , 125000 ) ;
F_2 ( V_607 , 25 ) ;
F_271 (ring, dev_priv, i)
F_2 ( F_272 ( V_601 -> V_608 ) , 10 ) ;
F_2 ( V_615 , 0x557 ) ;
F_2 ( V_694 ,
F_27 ( V_704 |
V_705 |
V_696 |
V_697 ) ) ;
if ( F_264 ( V_2 ) & V_587 )
V_623 = V_582 | V_706 ;
F_260 ( V_2 , V_623 ) ;
F_2 ( V_578 , V_623 ) ;
V_40 = V_698 |
V_699 |
V_707 ;
F_14 ( V_4 , V_701 , V_40 ) ;
V_40 = F_13 ( V_4 , V_691 ) ;
F_240 ( ( V_40 & V_702 ) == 0 , L_79 ) ;
F_7 ( L_80 , F_309 ( V_40 & V_702 ) ) ;
F_7 ( L_81 , V_40 ) ;
V_4 -> V_41 . V_527 = ( V_40 >> 8 ) & 0xff ;
F_7 ( L_82 ,
F_238 ( V_4 , V_4 -> V_41 . V_527 ) ,
V_4 -> V_41 . V_527 ) ;
F_7 ( L_83 ,
F_238 ( V_4 , V_4 -> V_41 . V_526 ) ,
V_4 -> V_41 . V_526 ) ;
F_239 ( V_4 -> V_2 , V_4 -> V_41 . V_526 ) ;
F_243 ( V_4 , V_580 ) ;
}
static unsigned long F_311 ( T_1 V_708 )
{
unsigned long V_709 ;
int div = ( V_708 & 0x3f0000 ) >> 16 ;
int V_710 = ( V_708 & 0x3000 ) >> 12 ;
int V_711 = ( V_708 & 0x7 ) ;
if ( ! V_711 )
return 0 ;
V_709 = ( ( div * 133333 ) / ( ( 1 << V_710 ) * V_711 ) ) ;
return V_709 ;
}
static unsigned long F_312 ( struct V_3 * V_4 )
{
T_8 V_712 , V_645 , V_180 ;
T_1 V_713 , V_714 , V_715 , V_716 = 0 , V_717 = 0 ;
unsigned long V_718 = F_221 ( V_506 ) , V_719 ;
int V_37 ;
F_212 ( & V_464 ) ;
V_719 = V_718 - V_4 -> V_29 . V_505 ;
if ( V_719 <= 10 )
return V_4 -> V_29 . V_720 ;
V_713 = F_3 ( V_502 ) ;
V_714 = F_3 ( V_503 ) ;
V_715 = F_3 ( V_504 ) ;
V_712 = V_713 + V_714 + V_715 ;
if ( V_712 < V_4 -> V_29 . V_501 ) {
V_645 = ~ 0UL - V_4 -> V_29 . V_501 ;
V_645 += V_712 ;
} else {
V_645 = V_712 - V_4 -> V_29 . V_501 ;
}
for ( V_37 = 0 ; V_37 < F_9 ( V_721 ) ; V_37 ++ ) {
if ( V_721 [ V_37 ] . V_37 == V_4 -> V_29 . V_31 &&
V_721 [ V_37 ] . V_722 == V_4 -> V_29 . V_30 ) {
V_716 = V_721 [ V_37 ] . V_716 ;
V_717 = V_721 [ V_37 ] . V_717 ;
break;
}
}
V_645 = F_86 ( V_645 , V_719 ) ;
V_180 = ( ( V_716 * V_645 ) + V_717 ) ;
V_180 = F_86 ( V_180 , 10 ) ;
V_4 -> V_29 . V_501 = V_712 ;
V_4 -> V_29 . V_505 = V_718 ;
V_4 -> V_29 . V_720 = V_180 ;
return V_180 ;
}
unsigned long F_313 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_40 ;
if ( F_69 ( V_2 ) -> V_265 != 5 )
return 0 ;
F_217 ( & V_464 ) ;
V_40 = F_312 ( V_4 ) ;
F_223 ( & V_464 ) ;
return V_40 ;
}
unsigned long F_314 ( struct V_3 * V_4 )
{
unsigned long V_716 , V_723 , V_724 ;
T_1 V_725 ;
V_725 = F_3 ( V_726 ) ;
V_716 = ( ( V_725 & V_727 ) >> V_728 ) ;
V_723 = F_315 ( V_729 ) ;
V_724 = V_725 & V_730 ;
return ( ( V_716 * V_723 ) / 127 ) - V_724 ;
}
static int F_316 ( T_7 V_731 )
{
if ( V_731 == 0 )
return 0 ;
if ( V_731 >= 8 && V_731 < 31 )
V_731 = 31 ;
return ( V_731 + 2 ) * 125 ;
}
static T_1 F_317 ( struct V_3 * V_4 , T_7 V_731 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
const int V_732 = F_316 ( V_731 ) ;
const int V_733 = V_732 - 1125 ;
if ( F_69 ( V_2 ) -> V_734 )
return V_733 > 0 ? V_733 : 0 ;
return V_732 ;
}
static void F_318 ( struct V_3 * V_4 )
{
T_8 V_718 , V_645 , V_735 ;
T_1 V_736 ;
F_212 ( & V_464 ) ;
V_718 = F_222 () ;
V_735 = V_718 - V_4 -> V_29 . V_509 ;
F_319 ( V_735 , V_737 ) ;
if ( ! V_735 )
return;
V_736 = F_3 ( V_508 ) ;
if ( V_736 < V_4 -> V_29 . V_507 ) {
V_645 = ~ 0UL - V_4 -> V_29 . V_507 ;
V_645 += V_736 ;
} else {
V_645 = V_736 - V_4 -> V_29 . V_507 ;
}
V_4 -> V_29 . V_507 = V_736 ;
V_4 -> V_29 . V_509 = V_718 ;
V_645 = V_645 * 1181 ;
V_645 = F_86 ( V_645 , V_735 * 10 ) ;
V_4 -> V_29 . V_738 = V_645 ;
}
void F_320 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_69 ( V_2 ) -> V_265 != 5 )
return;
F_217 ( & V_464 ) ;
F_318 ( V_4 ) ;
F_223 ( & V_464 ) ;
}
static unsigned long F_321 ( struct V_3 * V_4 )
{
unsigned long V_722 , V_739 , V_740 , V_741 , V_742 ;
T_1 V_731 , V_743 ;
F_212 ( & V_464 ) ;
V_731 = F_3 ( F_218 ( V_4 -> V_41 . V_527 ) ) ;
V_731 = ( V_731 >> 24 ) & 0x7f ;
V_743 = F_317 ( V_4 , V_731 ) ;
V_740 = V_743 ;
V_722 = F_314 ( V_4 ) ;
if ( V_722 > 80 )
V_739 = ( ( V_722 * 2349 ) + 135940 ) ;
else if ( V_722 >= 50 )
V_739 = ( ( V_722 * 964 ) + 29317 ) ;
else
V_739 = ( ( V_722 * 301 ) + 1004 ) ;
V_739 = V_739 * ( ( 150142 * V_740 ) / 10000 - 78642 ) ;
V_739 /= 100000 ;
V_741 = ( V_739 * V_4 -> V_29 . V_739 ) ;
V_742 = ( V_741 * V_740 ) / 10000 ;
V_742 /= 100 ;
F_318 ( V_4 ) ;
return V_4 -> V_29 . V_738 + V_742 ;
}
unsigned long F_322 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_40 ;
if ( F_69 ( V_2 ) -> V_265 != 5 )
return 0 ;
F_217 ( & V_464 ) ;
V_40 = F_321 ( V_4 ) ;
F_223 ( & V_464 ) ;
return V_40 ;
}
unsigned long F_323 ( void )
{
struct V_3 * V_4 ;
unsigned long V_744 , V_745 , V_180 = 0 ;
F_217 ( & V_464 ) ;
if ( ! V_746 )
goto V_747;
V_4 = V_746 ;
V_744 = F_312 ( V_4 ) ;
V_745 = F_321 ( V_4 ) ;
V_180 = V_744 + V_745 ;
V_747:
F_223 ( & V_464 ) ;
return V_180 ;
}
bool F_324 ( void )
{
struct V_3 * V_4 ;
bool V_180 = true ;
F_217 ( & V_464 ) ;
if ( ! V_746 ) {
V_180 = false ;
goto V_747;
}
V_4 = V_746 ;
if ( V_4 -> V_29 . V_493 > V_4 -> V_29 . V_473 )
V_4 -> V_29 . V_493 -- ;
V_747:
F_223 ( & V_464 ) ;
return V_180 ;
}
bool F_325 ( void )
{
struct V_3 * V_4 ;
bool V_180 = true ;
F_217 ( & V_464 ) ;
if ( ! V_746 ) {
V_180 = false ;
goto V_747;
}
V_4 = V_746 ;
if ( V_4 -> V_29 . V_493 < V_4 -> V_29 . V_494 )
V_4 -> V_29 . V_493 ++ ;
V_747:
F_223 ( & V_464 ) ;
return V_180 ;
}
bool F_326 ( void )
{
struct V_3 * V_4 ;
struct V_600 * V_601 ;
bool V_180 = false ;
int V_37 ;
F_217 ( & V_464 ) ;
if ( ! V_746 )
goto V_747;
V_4 = V_746 ;
F_271 (ring, dev_priv, i)
V_180 |= ! F_248 ( & V_601 -> V_748 ) ;
V_747:
F_223 ( & V_464 ) ;
return V_180 ;
}
bool F_327 ( void )
{
struct V_3 * V_4 ;
bool V_180 = true ;
F_217 ( & V_464 ) ;
if ( ! V_746 ) {
V_180 = false ;
goto V_747;
}
V_4 = V_746 ;
V_4 -> V_29 . V_493 = V_4 -> V_29 . V_475 ;
if ( ! F_211 ( V_4 -> V_2 , V_4 -> V_29 . V_475 ) )
V_180 = false ;
V_747:
F_223 ( & V_464 ) ;
return V_180 ;
}
static void
F_328 ( void )
{
void (* V_571)( void );
V_571 = F_329 ( V_749 ) ;
if ( V_571 ) {
V_571 () ;
F_330 ( V_749 ) ;
}
}
void F_331 ( struct V_3 * V_4 )
{
F_217 ( & V_464 ) ;
V_746 = V_4 ;
F_223 ( & V_464 ) ;
F_328 () ;
}
void F_332 ( void )
{
F_217 ( & V_464 ) ;
V_746 = NULL ;
F_223 ( & V_464 ) ;
}
static void F_333 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_750 ;
T_7 V_751 [ 16 ] ;
int V_37 ;
F_2 ( V_752 , 0 ) ;
F_21 ( V_752 ) ;
F_2 ( V_753 , 0x15040d00 ) ;
F_2 ( V_754 , 0x007f0000 ) ;
F_2 ( V_755 , 0x1e220004 ) ;
F_2 ( V_756 , 0x04000004 ) ;
for ( V_37 = 0 ; V_37 < 5 ; V_37 ++ )
F_2 ( F_334 ( V_37 ) , 0 ) ;
for ( V_37 = 0 ; V_37 < 3 ; V_37 ++ )
F_2 ( F_335 ( V_37 ) , 0 ) ;
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ ) {
T_1 V_757 = F_3 ( F_218 ( V_37 ) ) ;
unsigned long V_709 = F_311 ( V_757 ) ;
unsigned long V_758 = ( V_757 & V_491 ) >>
V_492 ;
unsigned long V_40 ;
V_40 = V_758 * V_758 ;
V_40 *= ( V_709 / 1000 ) ;
V_40 *= 255 ;
V_40 /= ( 127 * 127 * 900 ) ;
if ( V_40 > 0xff )
F_16 ( L_84 , V_40 ) ;
V_751 [ V_37 ] = V_40 ;
}
V_751 [ 14 ] = 0 ;
V_751 [ 15 ] = 0 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
T_1 V_40 = ( V_751 [ V_37 * 4 ] << 24 ) | ( V_751 [ ( V_37 * 4 ) + 1 ] << 16 ) |
( V_751 [ ( V_37 * 4 ) + 2 ] << 8 ) | ( V_751 [ ( V_37 * 4 ) + 3 ] ) ;
F_2 ( F_336 ( V_37 ) , V_40 ) ;
}
F_2 ( V_759 , 0 ) ;
F_2 ( V_760 , 0 ) ;
F_2 ( V_761 , 0x00007f00 ) ;
F_2 ( V_762 , 0x0000000e ) ;
F_2 ( V_763 , 0x000e0000 ) ;
F_2 ( V_764 , 0x68000300 ) ;
F_2 ( V_765 , 0x42000000 ) ;
F_2 ( V_766 , 0x00140031 ) ;
F_2 ( V_767 , 0 ) ;
F_2 ( V_768 , 0 ) ;
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ )
F_2 ( F_337 ( V_37 ) , 0 ) ;
F_2 ( V_752 , 0x80000019 ) ;
V_750 = F_3 ( V_769 ) ;
V_4 -> V_29 . V_739 = ( V_750 & V_770 ) ;
}
void F_338 ( struct V_1 * V_2 )
{
V_590 . V_586 = F_263 ( V_2 , V_590 . V_586 ) ;
if ( F_58 ( V_2 ) )
F_305 ( V_2 ) ;
else if ( F_20 ( V_2 ) )
F_304 ( V_2 ) ;
}
void F_339 ( struct V_1 * V_2 )
{
if ( F_58 ( V_2 ) )
return;
else if ( F_20 ( V_2 ) )
F_307 ( V_2 ) ;
}
static void F_340 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_341 ( & V_4 -> V_41 . V_771 ) ;
F_342 ( V_2 ) ;
}
void F_343 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_69 ( V_2 ) -> V_265 < 6 )
return;
F_340 ( V_2 ) ;
F_246 ( V_4 ) ;
}
void F_344 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_345 ( V_2 ) ) {
F_224 ( V_2 ) ;
} else if ( F_69 ( V_2 ) -> V_265 >= 6 ) {
F_343 ( V_2 ) ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
if ( F_69 ( V_2 ) -> V_265 >= 9 )
F_256 ( V_2 ) ;
else if ( F_58 ( V_2 ) )
F_258 ( V_2 ) ;
else if ( F_20 ( V_2 ) )
F_259 ( V_2 ) ;
else
F_257 ( V_2 ) ;
V_4 -> V_41 . V_89 = false ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
}
}
static void F_346 ( struct V_772 * V_576 )
{
struct V_3 * V_4 =
F_347 ( V_576 , struct V_3 ,
V_41 . V_771 . V_576 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_12 ( & V_4 -> V_41 . V_42 ) ;
F_348 ( V_2 ) ;
if ( F_58 ( V_2 ) ) {
F_308 ( V_2 ) ;
} else if ( F_20 ( V_2 ) ) {
F_310 ( V_2 ) ;
} else if ( F_69 ( V_2 ) -> V_265 >= 9 ) {
F_270 ( V_2 ) ;
F_269 ( V_2 ) ;
if ( F_266 ( V_2 ) )
F_282 ( V_2 ) ;
} else if ( F_116 ( V_2 ) ) {
F_277 ( V_2 ) ;
F_282 ( V_2 ) ;
} else {
F_278 ( V_2 ) ;
F_282 ( V_2 ) ;
}
F_63 ( V_4 -> V_41 . V_554 < V_4 -> V_41 . V_555 ) ;
F_63 ( V_4 -> V_41 . V_561 > V_4 -> V_41 . V_554 ) ;
F_63 ( V_4 -> V_41 . V_526 < V_4 -> V_41 . V_555 ) ;
F_63 ( V_4 -> V_41 . V_526 > V_4 -> V_41 . V_554 ) ;
V_4 -> V_41 . V_89 = true ;
F_349 ( V_2 ) ;
F_17 ( & V_4 -> V_41 . V_42 ) ;
F_350 ( V_4 ) ;
}
void F_351 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_352 ( V_2 ) )
return;
if ( F_345 ( V_2 ) ) {
F_12 ( & V_2 -> V_685 ) ;
F_216 ( V_2 ) ;
F_333 ( V_2 ) ;
F_17 ( & V_2 -> V_685 ) ;
} else if ( F_69 ( V_2 ) -> V_265 >= 6 ) {
if ( F_353 ( & V_4 -> V_41 . V_771 ,
F_354 ( V_773 ) ) )
F_355 ( V_4 ) ;
}
}
void F_356 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_69 ( V_2 ) -> V_265 < 6 )
return;
F_340 ( V_2 ) ;
V_4 -> V_41 . V_89 = false ;
}
static void F_357 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_774 , V_775 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_60 V_60 ;
F_140 (dev_priv, pipe) {
F_2 ( F_359 ( V_60 ) ,
F_3 ( F_359 ( V_60 ) ) |
V_776 ) ;
F_2 ( F_360 ( V_60 ) , F_3 ( F_360 ( V_60 ) ) ) ;
F_21 ( F_360 ( V_60 ) ) ;
}
}
static void F_361 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_348 , F_3 ( V_348 ) & ~ V_327 ) ;
F_2 ( V_349 , F_3 ( V_349 ) & ~ V_327 ) ;
F_2 ( V_350 , F_3 ( V_350 ) & ~ V_327 ) ;
}
static void F_362 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_777 = V_778 ;
V_777 |= V_779 |
V_780 |
V_781 ;
F_2 ( V_782 ,
V_783 |
V_784 ) ;
F_2 ( V_785 ,
V_786 ) ;
F_2 ( V_787 ,
( F_3 ( V_787 ) |
V_788 | V_789 ) ) ;
V_777 |= V_790 ;
F_2 ( V_358 ,
( F_3 ( V_358 ) |
V_359 ) ) ;
F_361 ( V_2 ) ;
if ( F_345 ( V_2 ) ) {
F_2 ( V_791 ,
F_3 ( V_791 ) |
V_792 ) ;
F_2 ( V_787 ,
F_3 ( V_787 ) |
V_788 ) ;
}
F_2 ( V_793 , V_777 ) ;
F_2 ( V_787 ,
F_3 ( V_787 ) |
V_794 ) ;
F_2 ( V_795 ,
V_796 << 16 |
V_796 ) ;
F_2 ( V_797 ,
F_27 ( V_798 ) ) ;
F_2 ( V_797 , F_28 ( V_799 ) ) ;
F_358 ( V_2 ) ;
F_357 ( V_2 ) ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_60 ;
T_3 V_40 ;
F_2 ( V_774 , V_775 |
V_800 |
V_801 ) ;
F_2 ( V_802 , F_3 ( V_802 ) |
V_803 ) ;
F_140 (dev_priv, pipe) {
V_40 = F_3 ( F_364 ( V_60 ) ) ;
V_40 |= V_804 ;
V_40 &= ~ V_805 ;
if ( V_4 -> V_806 . V_807 )
V_40 |= V_805 ;
V_40 &= ~ V_808 ;
V_40 &= ~ V_809 ;
V_40 &= ~ V_810 ;
F_2 ( F_364 ( V_60 ) , V_40 ) ;
}
F_140 (dev_priv, pipe) {
F_2 ( F_365 ( V_60 ) ,
V_811 ) ;
}
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_9 ;
V_9 = F_3 ( V_294 ) ;
if ( ( V_9 & V_812 ) != V_813 )
F_10 ( L_85 ,
V_9 ) ;
}
static void F_367 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_777 = V_778 ;
F_2 ( V_793 , V_777 ) ;
F_2 ( V_787 ,
F_3 ( V_787 ) |
V_794 ) ;
F_2 ( V_814 ,
F_27 ( V_815 ) ) ;
F_2 ( V_797 , F_28 ( V_799 ) ) ;
F_2 ( V_816 ,
F_368 ( V_817 , V_818 ) ) ;
F_361 ( V_2 ) ;
F_2 ( V_797 ,
F_28 ( V_819 ) ) ;
F_2 ( V_820 ,
F_3 ( V_820 ) |
V_821 |
V_822 ) ;
F_2 ( V_823 ,
V_824 |
V_825 ) ;
F_2 ( V_826 ,
F_27 ( V_827 ) ) ;
F_2 ( V_826 ,
F_27 ( V_828 ) ) ;
F_2 ( V_791 ,
F_3 ( V_791 ) |
V_792 | V_829 ) ;
F_2 ( V_787 ,
F_3 ( V_787 ) |
V_788 | V_789 ) ;
F_2 ( V_793 ,
F_3 ( V_793 ) |
V_790 |
V_781 ) ;
F_358 ( V_2 ) ;
F_363 ( V_2 ) ;
F_366 ( V_2 ) ;
}
static void F_369 ( struct V_3 * V_4 )
{
T_3 V_91 = F_3 ( V_830 ) ;
V_91 &= ~ V_831 ;
V_91 |= V_832 ;
V_91 |= V_833 ;
V_91 |= V_834 ;
F_2 ( V_830 , V_91 ) ;
}
static void F_370 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_371 ( V_2 ) )
F_2 ( V_774 ,
F_3 ( V_774 ) |
V_835 ) ;
F_2 ( F_365 ( V_68 ) ,
F_3 ( F_365 ( V_68 ) ) |
V_811 ) ;
}
static void F_372 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_371 ( V_2 ) ) {
T_3 V_40 = F_3 ( V_774 ) ;
V_40 &= ~ V_835 ;
F_2 ( V_774 , V_40 ) ;
}
}
static void F_373 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_60 V_60 ;
T_3 V_836 ;
F_361 ( V_2 ) ;
F_2 ( V_837 , F_3 ( V_837 ) | V_838 ) ;
F_2 ( V_839 ,
F_3 ( V_839 ) | V_840 ) ;
F_140 (dev_priv, pipe) {
F_2 ( F_374 ( V_60 ) ,
F_3 ( F_374 ( V_60 ) ) |
V_841 ) ;
}
F_2 ( V_830 ,
F_3 ( V_830 ) &
~ ( V_842 | V_843 ) ) ;
F_2 ( V_844 ,
F_27 ( V_845 ) ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
V_836 = F_3 ( V_846 ) ;
F_2 ( V_846 , V_836 & ~ V_847 ) ;
F_2 ( V_848 , V_849 ) ;
F_2 ( V_846 , V_836 ) ;
F_2 ( V_850 , V_851 ) ;
F_370 ( V_2 ) ;
}
static void F_375 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_361 ( V_2 ) ;
F_2 ( V_852 , V_853 ) ;
F_2 ( V_854 ,
F_27 ( V_855 ) ) ;
F_2 ( V_856 ,
F_3 ( V_856 ) |
V_857 ) ;
F_2 ( V_830 ,
F_3 ( V_830 ) & ~ V_843 ) ;
F_2 ( V_858 , F_28 ( V_799 ) ) ;
F_2 ( V_858 ,
F_28 ( V_859 ) ) ;
F_2 ( V_860 ,
F_27 ( V_861 ) ) ;
F_2 ( V_862 ,
F_368 ( V_817 , V_818 ) ) ;
F_2 ( V_863 ,
F_27 ( V_864 ) ) ;
F_2 ( V_837 , F_3 ( V_837 ) | V_838 ) ;
F_2 ( V_839 ,
F_3 ( V_839 ) | V_865 ) ;
F_370 ( V_2 ) ;
}
static void F_376 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_866 ;
F_361 ( V_2 ) ;
F_2 ( V_793 , V_778 ) ;
F_2 ( V_826 ,
F_27 ( V_867 ) ) ;
F_2 ( V_868 ,
V_869 |
V_870 ) ;
if ( F_377 ( V_2 ) )
F_2 ( V_871 ,
F_27 ( V_872 ) ) ;
F_2 ( V_858 , F_28 ( V_799 ) ) ;
F_2 ( V_873 ,
V_874 ) ;
F_2 ( V_875 ,
V_876 ) ;
F_2 ( V_877 ,
V_878 ) ;
if ( F_377 ( V_2 ) )
F_2 ( V_879 ,
F_27 ( V_880 ) ) ;
else {
F_2 ( V_879 ,
F_27 ( V_880 ) ) ;
F_2 ( V_881 ,
F_27 ( V_880 ) ) ;
}
F_2 ( V_882 , F_3 ( V_882 ) &
~ V_883 ) ;
F_2 ( V_823 ,
V_884 ) ;
F_2 ( V_856 ,
F_3 ( V_856 ) |
V_857 ) ;
F_358 ( V_2 ) ;
F_369 ( V_4 ) ;
if ( 0 ) {
F_2 ( V_858 ,
F_28 ( V_859 ) ) ;
}
F_2 ( V_860 ,
F_27 ( V_861 ) ) ;
F_2 ( V_862 ,
F_368 ( V_817 , V_818 ) ) ;
V_866 = F_3 ( V_885 ) ;
V_866 &= ~ V_886 ;
V_866 |= V_887 ;
F_2 ( V_885 , V_866 ) ;
if ( ! F_378 ( V_2 ) )
F_363 ( V_2 ) ;
F_366 ( V_2 ) ;
}
static void F_379 ( struct V_3 * V_4 )
{
F_2 ( V_888 , V_889 ) ;
F_2 ( V_890 , V_891 ) ;
F_2 ( V_892 , 0 ) ;
}
static void F_380 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_379 ( V_4 ) ;
F_2 ( V_826 ,
F_27 ( V_867 ) ) ;
F_2 ( V_868 ,
V_869 |
V_870 ) ;
F_2 ( V_871 ,
F_27 ( V_893 |
V_872 ) ) ;
F_2 ( V_858 , F_28 ( V_799 ) ) ;
F_2 ( V_882 , F_3 ( V_882 ) &
~ V_883 ) ;
F_2 ( V_879 ,
F_27 ( V_880 ) ) ;
F_2 ( V_856 ,
F_3 ( V_856 ) |
V_857 ) ;
F_369 ( V_4 ) ;
F_2 ( V_823 ,
V_884 ) ;
F_2 ( V_894 ,
F_3 ( V_894 ) | V_895 ) ;
F_2 ( V_860 ,
F_27 ( V_861 ) ) ;
F_2 ( V_862 ,
F_368 ( V_817 , V_818 ) ) ;
F_2 ( V_896 , V_897 ) ;
F_2 ( V_898 , V_899 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_379 ( V_4 ) ;
F_2 ( V_830 ,
F_3 ( V_830 ) &
~ ( V_842 | V_843 ) ) ;
F_2 ( V_844 ,
F_27 ( V_845 ) ) ;
F_2 ( V_820 , F_3 ( V_820 ) |
V_822 ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
F_2 ( V_850 , V_851 ) ;
}
static void F_382 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_777 ;
F_2 ( V_900 , 0 ) ;
F_2 ( V_901 , V_902 |
V_903 |
V_904 ) ;
F_2 ( V_905 , 0 ) ;
V_777 = V_889 |
V_906 |
V_907 ;
if ( F_383 ( V_2 ) )
V_777 |= V_908 ;
F_2 ( V_888 , V_777 ) ;
F_2 ( V_797 ,
F_27 ( V_798 ) ) ;
F_2 ( V_797 , F_28 ( V_799 ) ) ;
F_358 ( V_2 ) ;
}
static void F_384 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_900 , V_909 ) ;
F_2 ( V_901 , 0 ) ;
F_2 ( V_888 , 0 ) ;
F_2 ( V_905 , 0 ) ;
F_214 ( V_910 , 0 ) ;
F_2 ( V_911 ,
F_27 ( V_891 ) ) ;
F_2 ( V_797 , F_28 ( V_799 ) ) ;
}
static void F_385 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_900 , V_912 |
V_909 |
V_913 |
V_914 |
V_915 ) ;
F_2 ( V_901 , 0 ) ;
F_2 ( V_911 ,
F_27 ( V_891 ) ) ;
F_2 ( V_797 , F_28 ( V_799 ) ) ;
}
static void F_386 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_916 = F_3 ( V_917 ) ;
V_916 |= V_918 | V_919 |
V_920 ;
F_2 ( V_917 , V_916 ) ;
if ( F_24 ( V_2 ) )
F_2 ( V_921 , F_27 ( V_922 ) ) ;
F_2 ( V_921 , F_28 ( V_923 ) ) ;
F_2 ( V_59 , F_27 ( V_924 ) ) ;
F_2 ( V_911 , F_27 ( V_925 ) ) ;
F_2 ( V_911 ,
F_27 ( V_891 ) ) ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_900 , V_926 ) ;
F_2 ( V_927 , F_27 ( V_928 ) |
F_28 ( V_929 ) ) ;
F_2 ( V_930 ,
F_27 ( V_931 ) ) ;
}
static void F_388 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_888 , V_906 ) ;
F_2 ( V_930 ,
F_27 ( V_932 ) |
F_27 ( V_933 ) ) ;
}
void F_389 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_118 . V_934 )
V_4 -> V_118 . V_934 ( V_2 ) ;
}
void F_390 ( struct V_1 * V_2 )
{
if ( F_391 ( V_2 ) )
F_372 ( V_2 ) ;
}
void F_392 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_393 ( V_4 ) ;
if ( F_24 ( V_2 ) )
F_4 ( V_2 ) ;
else if ( F_133 ( V_2 ) )
F_5 ( V_2 ) ;
if ( F_69 ( V_2 ) -> V_265 >= 9 ) {
F_127 ( V_2 ) ;
if ( F_149 ( V_2 ) )
V_4 -> V_118 . V_934 =
F_1 ;
V_4 -> V_118 . V_461 = F_194 ;
V_4 -> V_118 . V_462 = F_195 ;
} else if ( F_394 ( V_2 ) ) {
F_125 ( V_2 ) ;
if ( ( F_133 ( V_2 ) && V_4 -> V_51 . V_181 [ 1 ] &&
V_4 -> V_51 . V_282 [ 1 ] && V_4 -> V_51 . V_283 [ 1 ] ) ||
( ! F_133 ( V_2 ) && V_4 -> V_51 . V_181 [ 0 ] &&
V_4 -> V_51 . V_282 [ 0 ] && V_4 -> V_51 . V_283 [ 0 ] ) ) {
V_4 -> V_118 . V_461 = F_196 ;
V_4 -> V_118 . V_462 = F_198 ;
} else {
F_10 ( L_86
L_87 ) ;
}
if ( F_133 ( V_2 ) )
V_4 -> V_118 . V_934 = F_362 ;
else if ( F_126 ( V_2 ) )
V_4 -> V_118 . V_934 = F_367 ;
else if ( F_120 ( V_2 ) )
V_4 -> V_118 . V_934 = F_376 ;
else if ( F_115 ( V_2 ) )
V_4 -> V_118 . V_934 = F_375 ;
else if ( F_69 ( V_2 ) -> V_265 == 8 )
V_4 -> V_118 . V_934 = F_373 ;
} else if ( F_58 ( V_2 ) ) {
F_60 ( V_2 ) ;
V_4 -> V_118 . V_461 = F_75 ;
V_4 -> V_118 . V_934 =
F_381 ;
} else if ( F_20 ( V_2 ) ) {
F_60 ( V_2 ) ;
V_4 -> V_118 . V_461 = F_75 ;
V_4 -> V_118 . V_934 =
F_380 ;
} else if ( F_24 ( V_2 ) ) {
if ( ! F_8 ( F_44 ( V_2 ) ,
V_4 -> V_23 ,
V_4 -> V_13 ,
V_4 -> V_19 ) ) {
F_274 ( L_88
L_89
L_90 ,
( V_4 -> V_23 == 1 ) ? L_91 : L_92 ,
V_4 -> V_13 , V_4 -> V_19 ) ;
F_19 ( V_4 , false ) ;
V_4 -> V_118 . V_461 = NULL ;
} else
V_4 -> V_118 . V_461 = F_43 ;
V_4 -> V_118 . V_934 = F_386 ;
} else if ( F_22 ( V_2 ) ) {
V_4 -> V_118 . V_461 = F_76 ;
V_4 -> V_118 . V_934 = F_382 ;
} else if ( F_395 ( V_2 ) ) {
V_4 -> V_118 . V_461 = F_79 ;
if ( F_23 ( V_2 ) )
V_4 -> V_118 . V_934 = F_384 ;
else if ( F_396 ( V_2 ) )
V_4 -> V_118 . V_934 = F_385 ;
} else if ( F_397 ( V_2 ) ) {
V_4 -> V_118 . V_461 = F_80 ;
V_4 -> V_118 . V_235 = F_35 ;
V_4 -> V_118 . V_934 = F_386 ;
} else if ( F_81 ( V_2 ) ) {
if ( F_69 ( V_2 ) -> V_204 == 1 ) {
V_4 -> V_118 . V_461 = F_84 ;
V_4 -> V_118 . V_235 = F_37 ;
} else {
V_4 -> V_118 . V_461 = F_80 ;
V_4 -> V_118 . V_235 = F_36 ;
}
if ( F_398 ( V_2 ) || F_399 ( V_2 ) )
V_4 -> V_118 . V_934 = F_387 ;
else
V_4 -> V_118 . V_934 = F_388 ;
} else {
F_16 ( L_93 ) ;
}
}
int F_114 ( struct V_3 * V_4 , T_1 V_935 , T_1 * V_40 )
{
F_63 ( ! F_232 ( & V_4 -> V_41 . V_42 ) ) ;
if ( F_3 ( V_936 ) & V_937 ) {
F_7 ( L_94 ) ;
return - V_938 ;
}
F_2 ( V_939 , * V_40 ) ;
F_2 ( V_940 , 0 ) ;
F_2 ( V_936 , V_937 | V_935 ) ;
if ( F_15 ( ( F_3 ( V_936 ) & V_937 ) == 0 ,
500 ) ) {
F_16 ( L_95 , V_935 ) ;
return - V_941 ;
}
* V_40 = F_3 ( V_939 ) ;
F_2 ( V_939 , 0 ) ;
return 0 ;
}
int F_279 ( struct V_3 * V_4 , T_1 V_935 , T_1 V_40 )
{
F_63 ( ! F_232 ( & V_4 -> V_41 . V_42 ) ) ;
if ( F_3 ( V_936 ) & V_937 ) {
F_7 ( L_96 ) ;
return - V_938 ;
}
F_2 ( V_939 , V_40 ) ;
F_2 ( V_936 , V_937 | V_935 ) ;
if ( F_15 ( ( F_3 ( V_936 ) & V_937 ) == 0 ,
500 ) ) {
F_16 ( L_97 , V_935 ) ;
return - V_941 ;
}
F_2 ( V_939 , 0 ) ;
return 0 ;
}
static int F_400 ( unsigned int V_942 )
{
switch ( V_942 ) {
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
static int F_401 ( struct V_3 * V_4 , int V_40 )
{
int div , V_942 = F_108 ( V_4 -> V_942 , 1000 ) ;
div = F_400 ( V_942 ) ;
if ( div < 0 )
return div ;
return F_108 ( V_942 * ( V_40 + 6 - 0xbd ) , div ) ;
}
static int F_402 ( struct V_3 * V_4 , int V_40 )
{
int V_943 , V_942 = F_108 ( V_4 -> V_942 , 1000 ) ;
V_943 = F_400 ( V_942 ) ;
if ( V_943 < 0 )
return V_943 ;
return F_108 ( V_943 * V_40 , V_942 ) + 0xbd - 6 ;
}
static int F_403 ( struct V_3 * V_4 , int V_40 )
{
int div , V_942 = F_108 ( V_4 -> V_942 , 1000 ) ;
div = F_400 ( V_942 ) / 2 ;
if ( div < 0 )
return div ;
return F_108 ( V_942 * V_40 , 2 * div ) / 2 ;
}
static int F_404 ( struct V_3 * V_4 , int V_40 )
{
int V_943 , V_942 = F_108 ( V_4 -> V_942 , 1000 ) ;
V_943 = F_400 ( V_942 ) / 2 ;
if ( V_943 < 0 )
return V_943 ;
return F_108 ( V_40 * 2 * V_943 , V_942 ) * 2 ;
}
int F_238 ( struct V_3 * V_4 , int V_40 )
{
if ( F_112 ( V_4 -> V_2 ) )
return F_108 ( V_40 * V_944 ,
V_596 ) ;
else if ( F_58 ( V_4 -> V_2 ) )
return F_403 ( V_4 , V_40 ) ;
else if ( F_20 ( V_4 -> V_2 ) )
return F_401 ( V_4 , V_40 ) ;
else
return V_40 * V_944 ;
}
int F_268 ( struct V_3 * V_4 , int V_40 )
{
if ( F_112 ( V_4 -> V_2 ) )
return F_108 ( V_40 * V_596 ,
V_944 ) ;
else if ( F_58 ( V_4 -> V_2 ) )
return F_404 ( V_4 , V_40 ) ;
else if ( F_20 ( V_4 -> V_2 ) )
return F_402 ( V_4 , V_40 ) ;
else
return F_108 ( V_40 , V_944 ) ;
}
static void F_405 ( struct V_772 * V_576 )
{
struct V_945 * V_946 = F_347 ( V_576 , struct V_945 , V_576 ) ;
struct V_947 * V_948 = V_946 -> V_948 ;
if ( ! F_406 ( V_948 , true ) )
F_251 ( F_54 ( V_948 -> V_601 -> V_2 ) , NULL ,
V_948 -> V_949 ) ;
F_407 ( V_948 ) ;
F_408 ( V_946 ) ;
}
void F_409 ( struct V_1 * V_2 ,
struct V_947 * V_948 )
{
struct V_945 * V_946 ;
if ( V_948 == NULL || F_69 ( V_2 ) -> V_265 < 6 )
return;
if ( F_406 ( V_948 , true ) )
return;
V_946 = F_410 ( sizeof( * V_946 ) , V_950 ) ;
if ( V_946 == NULL )
return;
F_411 ( V_948 ) ;
V_946 -> V_948 = V_948 ;
F_412 ( & V_946 -> V_576 , F_405 ) ;
F_253 ( F_54 ( V_2 ) -> V_575 , & V_946 -> V_576 ) ;
}
void F_413 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_414 ( & V_4 -> V_41 . V_42 ) ;
F_415 ( & V_4 -> V_41 . V_563 ) ;
F_416 ( & V_4 -> V_41 . V_771 ,
F_346 ) ;
F_417 ( & V_4 -> V_41 . V_564 ) ;
F_417 ( & V_4 -> V_41 . V_951 . V_571 ) ;
F_417 ( & V_4 -> V_41 . V_952 . V_571 ) ;
V_4 -> V_953 . V_954 = false ;
}
