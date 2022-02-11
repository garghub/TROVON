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
V_12 = F_3 ( V_13 ) ;
switch ( V_12 & V_14 ) {
case V_15 :
V_4 -> V_16 = 533 ;
break;
case V_17 :
V_4 -> V_16 = 800 ;
break;
case V_18 :
V_4 -> V_16 = 667 ;
break;
case V_19 :
V_4 -> V_16 = 400 ;
break;
}
switch ( V_12 & V_20 ) {
case V_21 :
V_4 -> V_22 = 533 ;
break;
case V_23 :
V_4 -> V_22 = 667 ;
break;
case V_24 :
V_4 -> V_22 = 800 ;
break;
}
V_12 = F_3 ( V_25 ) ;
V_4 -> V_26 = ( V_12 & V_27 ) ? 1 : 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_28 , V_29 ;
V_28 = F_7 ( V_30 ) ;
V_29 = F_7 ( V_31 ) ;
switch ( V_28 & 0xff ) {
case 0xc :
V_4 -> V_22 = 800 ;
break;
case 0x10 :
V_4 -> V_22 = 1066 ;
break;
case 0x14 :
V_4 -> V_22 = 1333 ;
break;
case 0x18 :
V_4 -> V_22 = 1600 ;
break;
default:
F_8 ( L_1 ,
V_28 & 0xff ) ;
V_4 -> V_22 = 0 ;
break;
}
V_4 -> V_32 . V_33 = V_4 -> V_22 ;
switch ( V_29 & 0x3ff ) {
case 0x00c :
V_4 -> V_16 = 3200 ;
break;
case 0x00e :
V_4 -> V_16 = 3733 ;
break;
case 0x010 :
V_4 -> V_16 = 4266 ;
break;
case 0x012 :
V_4 -> V_16 = 4800 ;
break;
case 0x014 :
V_4 -> V_16 = 5333 ;
break;
case 0x016 :
V_4 -> V_16 = 5866 ;
break;
case 0x018 :
V_4 -> V_16 = 6400 ;
break;
default:
F_8 ( L_2 ,
V_29 & 0x3ff ) ;
V_4 -> V_16 = 0 ;
break;
}
if ( V_4 -> V_16 == 3200 ) {
V_4 -> V_32 . V_34 = 0 ;
} else if ( V_4 -> V_16 > 3200 && V_4 -> V_16 <= 4800 ) {
V_4 -> V_32 . V_34 = 1 ;
} else {
V_4 -> V_32 . V_34 = 2 ;
}
}
static const struct V_35 * F_9 ( int V_36 ,
int V_26 ,
int V_37 ,
int V_38 )
{
const struct V_35 * V_39 ;
int V_40 ;
if ( V_37 == 0 || V_38 == 0 )
return NULL ;
for ( V_40 = 0 ; V_40 < F_10 ( V_41 ) ; V_40 ++ ) {
V_39 = & V_41 [ V_40 ] ;
if ( V_36 == V_39 -> V_36 &&
V_26 == V_39 -> V_26 &&
V_37 == V_39 -> V_16 && V_38 == V_39 -> V_22 )
return V_39 ;
}
F_11 ( L_3 ) ;
return NULL ;
}
void F_12 ( struct V_3 * V_4 , bool V_42 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_43 ;
if ( F_13 ( V_2 ) ) {
F_2 ( V_44 , V_42 ? V_45 : 0 ) ;
} else if ( F_14 ( V_2 ) || F_15 ( V_2 ) ) {
F_2 ( V_46 , V_42 ? V_47 : 0 ) ;
} else if ( F_16 ( V_2 ) ) {
V_43 = F_3 ( V_48 ) & ~ V_49 ;
V_43 |= V_42 ? V_49 : 0 ;
F_2 ( V_48 , V_43 ) ;
} else if ( F_17 ( V_2 ) || F_18 ( V_2 ) ) {
V_43 = V_42 ? F_4 ( V_47 ) :
F_19 ( V_47 ) ;
F_2 ( V_46 , V_43 ) ;
} else if ( F_20 ( V_2 ) ) {
V_43 = V_42 ? F_4 ( V_50 ) :
F_19 ( V_50 ) ;
F_2 ( V_51 , V_43 ) ;
} else {
return;
}
F_11 ( L_4 ,
V_42 ? L_5 : L_6 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_53 = F_3 ( V_54 ) ;
int V_55 ;
V_55 = V_53 & 0x7f ;
if ( V_52 )
V_55 = ( ( V_53 >> V_56 ) & 0x7f ) - V_55 ;
F_11 ( L_7 , V_53 ,
V_52 ? L_8 : L_9 , V_55 ) ;
return V_55 ;
}
static int F_22 ( struct V_1 * V_2 , int V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_53 = F_3 ( V_54 ) ;
int V_55 ;
V_55 = V_53 & 0x1ff ;
if ( V_52 )
V_55 = ( ( V_53 >> V_57 ) & 0x1ff ) - V_55 ;
V_55 >>= 1 ;
F_11 ( L_7 , V_53 ,
V_52 ? L_8 : L_9 , V_55 ) ;
return V_55 ;
}
static int F_23 ( struct V_1 * V_2 , int V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_53 = F_3 ( V_54 ) ;
int V_55 ;
V_55 = V_53 & 0x7f ;
V_55 >>= 2 ;
F_11 ( L_7 , V_53 ,
V_52 ? L_8 : L_9 ,
V_55 ) ;
return V_55 ;
}
static unsigned long F_24 ( unsigned long V_58 ,
const struct V_59 * V_60 ,
int V_61 ,
int V_62 ,
unsigned long V_63 )
{
long V_64 , V_65 ;
V_64 = ( ( V_58 / 1000 ) * V_62 * V_63 ) /
1000 ;
V_64 = F_25 ( V_64 , V_60 -> V_66 ) ;
F_11 ( L_10 , V_64 ) ;
V_65 = V_61 - ( V_64 + V_60 -> V_67 ) ;
F_11 ( L_11 , V_65 ) ;
if ( V_65 > ( long ) V_60 -> V_68 )
V_65 = V_60 -> V_68 ;
if ( V_65 <= 0 )
V_65 = V_60 -> V_69 ;
if ( V_65 <= 8 )
V_65 = 8 ;
return V_65 ;
}
static struct V_70 * F_26 ( struct V_1 * V_2 )
{
struct V_70 * V_71 , * V_72 = NULL ;
F_27 (dev, crtc) {
if ( F_28 ( V_71 ) ) {
if ( V_72 )
return NULL ;
V_72 = V_71 ;
}
}
return V_72 ;
}
static void F_29 ( struct V_70 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_70 * V_71 ;
const struct V_35 * V_39 ;
T_1 V_74 ;
unsigned long V_60 ;
V_39 = F_9 ( F_30 ( V_2 ) , V_4 -> V_26 ,
V_4 -> V_16 , V_4 -> V_22 ) ;
if ( ! V_39 ) {
F_11 ( L_3 ) ;
F_12 ( V_4 , false ) ;
return;
}
V_71 = F_26 ( V_2 ) ;
if ( V_71 ) {
const struct V_75 * V_76 ;
int V_62 = V_71 -> V_77 -> V_78 -> V_79 / 8 ;
int clock ;
V_76 = & F_31 ( V_71 ) -> V_80 -> V_81 . V_76 ;
clock = V_76 -> V_82 ;
V_60 = F_24 ( clock , & V_83 ,
V_83 . V_61 ,
V_62 , V_39 -> V_84 ) ;
V_74 = F_3 ( V_85 ) ;
V_74 &= ~ V_86 ;
V_74 |= V_60 << V_87 ;
F_2 ( V_85 , V_74 ) ;
F_11 ( L_12 , V_74 ) ;
V_60 = F_24 ( clock , & V_88 ,
V_83 . V_61 ,
V_62 , V_39 -> V_89 ) ;
V_74 = F_3 ( V_48 ) ;
V_74 &= ~ V_90 ;
V_74 |= ( V_60 & 0x3f ) << V_91 ;
F_2 ( V_48 , V_74 ) ;
V_60 = F_24 ( clock , & V_92 ,
V_92 . V_61 ,
V_62 , V_39 -> V_93 ) ;
V_74 = F_3 ( V_48 ) ;
V_74 &= ~ V_94 ;
V_74 |= V_60 & V_94 ;
F_2 ( V_48 , V_74 ) ;
V_60 = F_24 ( clock , & V_95 ,
V_92 . V_61 ,
V_62 , V_39 -> V_96 ) ;
V_74 = F_3 ( V_48 ) ;
V_74 &= ~ V_97 ;
V_74 |= ( V_60 & 0x3f ) << V_98 ;
F_2 ( V_48 , V_74 ) ;
F_11 ( L_13 , V_74 ) ;
F_12 ( V_4 , true ) ;
} else {
F_12 ( V_4 , false ) ;
}
}
static bool F_32 ( struct V_1 * V_2 ,
int V_52 ,
const struct V_59 * V_99 ,
int V_100 ,
const struct V_59 * V_101 ,
int V_102 ,
int * V_103 ,
int * V_104 )
{
struct V_70 * V_71 ;
const struct V_75 * V_76 ;
int V_105 , V_106 , clock , V_62 ;
int V_107 , V_108 ;
int V_109 , V_110 ;
V_71 = F_33 ( V_2 , V_52 ) ;
if ( ! F_28 ( V_71 ) ) {
* V_104 = V_101 -> V_67 ;
* V_103 = V_99 -> V_67 ;
return false ;
}
V_76 = & F_31 ( V_71 ) -> V_80 -> V_81 . V_76 ;
clock = V_76 -> V_82 ;
V_105 = V_76 -> V_111 ;
V_106 = F_31 ( V_71 ) -> V_80 -> V_112 ;
V_62 = V_71 -> V_77 -> V_78 -> V_79 / 8 ;
V_109 = ( ( clock * V_62 / 1000 ) * V_100 ) / 1000 ;
V_110 = V_99 -> V_61 * V_99 -> V_66 - V_106 * 8 ;
if ( V_110 > 0 )
V_109 += V_110 ;
V_109 = F_25 ( V_109 , V_99 -> V_66 ) ;
* V_103 = V_109 + V_99 -> V_67 ;
if ( * V_103 > ( int ) V_99 -> V_68 )
* V_103 = V_99 -> V_68 ;
V_107 = F_34 ( V_105 * 1000 / clock , 1 ) ;
V_108 = ( V_102 / V_107 + 1000 ) / 1000 ;
V_109 = V_108 * F_31 ( V_71 ) -> V_113 * V_62 ;
V_110 = V_101 -> V_61 * V_101 -> V_66 - V_106 * 8 ;
if ( V_110 > 0 )
V_109 += V_110 ;
V_109 = F_25 ( V_109 , V_101 -> V_66 ) ;
* V_104 = V_109 + V_101 -> V_67 ;
if ( * V_104 > ( int ) V_101 -> V_68 )
* V_104 = ( int ) V_101 -> V_68 ;
return true ;
}
static bool F_35 ( struct V_1 * V_2 ,
int V_114 , int V_104 ,
const struct V_59 * V_99 ,
const struct V_59 * V_101 )
{
F_11 ( L_14 ,
V_114 , V_104 ) ;
if ( V_114 > V_99 -> V_68 ) {
F_11 ( L_15 ,
V_114 , V_99 -> V_68 ) ;
return false ;
}
if ( V_104 > V_101 -> V_68 ) {
F_11 ( L_16 ,
V_104 , V_101 -> V_68 ) ;
return false ;
}
if ( ! ( V_114 || V_104 ) ) {
F_11 ( L_17 ) ;
return false ;
}
return true ;
}
static bool F_36 ( struct V_1 * V_2 ,
int V_52 ,
int V_63 ,
const struct V_59 * V_99 ,
const struct V_59 * V_101 ,
int * V_114 , int * V_104 )
{
struct V_70 * V_71 ;
const struct V_75 * V_76 ;
int V_106 , V_105 , V_62 , clock ;
unsigned long V_107 ;
int V_108 , V_115 ;
int V_116 , V_117 ;
int V_109 ;
if ( ! V_63 ) {
* V_114 = * V_104 = 0 ;
return false ;
}
V_71 = F_33 ( V_2 , V_52 ) ;
V_76 = & F_31 ( V_71 ) -> V_80 -> V_81 . V_76 ;
clock = V_76 -> V_82 ;
V_105 = V_76 -> V_111 ;
V_106 = F_31 ( V_71 ) -> V_80 -> V_112 ;
V_62 = V_71 -> V_77 -> V_78 -> V_79 / 8 ;
V_107 = F_34 ( V_105 * 1000 / clock , 1 ) ;
V_108 = ( V_63 / V_107 + 1000 ) / 1000 ;
V_115 = V_106 * V_62 ;
V_116 = ( ( clock * V_62 / 1000 ) * V_63 ) / 1000 ;
V_117 = V_108 * V_115 ;
V_109 = F_25 ( F_37 ( V_116 , V_117 ) , V_99 -> V_66 ) ;
* V_114 = V_109 + V_99 -> V_67 ;
V_109 = V_108 * V_62 * F_31 ( V_71 ) -> V_113 ;
V_109 = F_25 ( V_109 , V_101 -> V_66 ) ;
* V_104 = V_109 + V_101 -> V_67 ;
return F_35 ( V_2 ,
* V_114 , * V_104 ,
V_99 , V_101 ) ;
}
static bool F_38 ( struct V_70 * V_71 ,
int V_62 ,
int * V_118 ,
int * V_119 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
int V_109 ;
int clock = F_31 ( V_71 ) -> V_80 -> V_81 . V_76 . V_82 ;
if ( F_39 ( clock == 0 , L_18 ) )
return false ;
if ( F_39 ( V_62 == 0 , L_19 ) )
return false ;
V_109 = F_25 ( clock , 1000 ) * V_62 ;
if ( F_40 ( V_2 ) )
* V_118 = ( V_109 > 128 ) ? V_120 :
V_121 ;
else
* V_118 = ( V_109 > 128 ) ? V_122 :
V_120 ;
* V_119 = ( 64 * ( * V_118 ) * 4 ) / V_109 ;
if ( * V_119 > V_123 )
* V_119 = V_123 ;
return true ;
}
static void F_41 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_31 ( V_71 ) ;
int V_62 ;
int V_119 ;
enum V_125 V_125 = V_124 -> V_125 ;
int V_126 , V_118 , V_127 ;
const int V_128 = F_40 ( V_2 ) ?
V_120 : V_122 ;
V_127 = F_3 ( F_42 ( V_125 ) ) & ~ ( V_129 |
V_123 | V_130 |
( V_123 << V_131 ) ) ;
if ( ! F_28 ( V_71 ) ) {
F_2 ( F_42 ( V_125 ) , V_127 ) ;
return;
}
V_62 = V_71 -> V_77 -> V_78 -> V_79 / 8 ;
if ( F_38 ( V_71 , V_62 , & V_118 , & V_119 ) ) {
V_126 = ( V_118 == V_128 ) ?
V_129 :
V_132 ;
V_127 |= V_126 | V_119 ;
}
V_62 = 4 ;
if ( V_124 -> V_133 &&
F_38 ( V_71 , V_62 , & V_118 , & V_119 ) ) {
V_126 = ( V_118 == V_128 ) ?
V_130 :
V_134 ;
V_127 |= V_126 | ( V_119 << V_131 ) ;
}
F_2 ( F_42 ( V_125 ) , V_127 ) ;
}
static void F_43 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
static const int V_135 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_136 , V_137 , V_138 , V_139 ;
int V_140 , V_89 ;
int V_141 , V_142 ;
unsigned int V_72 = 0 ;
bool V_143 ;
F_41 ( V_71 ) ;
if ( F_32 ( V_2 , V_144 ,
& V_145 , V_146 ,
& V_147 , V_146 ,
& V_136 , & V_138 ) )
V_72 |= 1 << V_144 ;
if ( F_32 ( V_2 , V_148 ,
& V_145 , V_146 ,
& V_147 , V_146 ,
& V_137 , & V_139 ) )
V_72 |= 1 << V_148 ;
if ( F_44 ( V_72 ) &&
F_36 ( V_2 , F_45 ( V_72 ) - 1 ,
V_135 ,
& V_145 ,
& V_147 ,
& V_140 , & V_142 ) &&
F_36 ( V_2 , F_45 ( V_72 ) - 1 ,
2 * V_135 ,
& V_145 ,
& V_147 ,
& V_141 , & V_89 ) ) {
V_143 = true ;
} else {
V_143 = false ;
F_12 ( V_4 , false ) ;
V_140 = V_89 = 0 ;
}
F_11 ( L_20
L_21 ,
V_136 , V_138 ,
V_137 , V_139 ,
V_140 , V_89 ) ;
F_2 ( V_85 ,
( V_140 << V_87 ) |
( V_139 << V_149 ) |
( V_137 << V_150 ) |
( V_136 << V_151 ) ) ;
F_2 ( V_152 ,
( F_3 ( V_152 ) & ~ V_153 ) |
( V_138 << V_154 ) ) ;
F_2 ( V_48 ,
( F_3 ( V_48 ) & ~ V_90 ) |
( V_89 << V_91 ) ) ;
if ( V_143 )
F_12 ( V_4 , true ) ;
}
static void F_46 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
static const int V_135 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_136 , V_137 , V_155 ;
int V_138 , V_139 , V_156 ;
int V_140 , V_89 ;
int V_141 , V_142 ;
unsigned int V_72 = 0 ;
bool V_143 ;
F_41 ( V_71 ) ;
if ( F_32 ( V_2 , V_144 ,
& V_145 , V_146 ,
& V_147 , V_146 ,
& V_136 , & V_138 ) )
V_72 |= 1 << V_144 ;
if ( F_32 ( V_2 , V_148 ,
& V_145 , V_146 ,
& V_147 , V_146 ,
& V_137 , & V_139 ) )
V_72 |= 1 << V_148 ;
if ( F_32 ( V_2 , V_157 ,
& V_145 , V_146 ,
& V_147 , V_146 ,
& V_155 , & V_156 ) )
V_72 |= 1 << V_157 ;
if ( F_44 ( V_72 ) &&
F_36 ( V_2 , F_45 ( V_72 ) - 1 ,
V_135 ,
& V_145 ,
& V_147 ,
& V_140 , & V_142 ) &&
F_36 ( V_2 , F_45 ( V_72 ) - 1 ,
2 * V_135 ,
& V_145 ,
& V_147 ,
& V_141 , & V_89 ) ) {
V_143 = true ;
} else {
V_143 = false ;
F_12 ( V_4 , false ) ;
V_140 = V_89 = 0 ;
}
F_11 ( L_20
L_22
L_23 ,
V_136 , V_138 ,
V_137 , V_139 ,
V_155 , V_156 ,
V_140 , V_89 ) ;
F_2 ( V_85 ,
( V_140 << V_87 ) |
( V_139 << V_149 ) |
( V_137 << V_150 ) |
( V_136 << V_151 ) ) ;
F_2 ( V_152 ,
( F_3 ( V_152 ) & ~ V_153 ) |
( V_138 << V_154 ) ) ;
F_2 ( V_48 ,
( F_3 ( V_48 ) & ~ V_90 ) |
( V_89 << V_91 ) ) ;
F_2 ( V_158 ,
( F_3 ( V_158 ) & ~ ( V_159 |
V_160 ) ) |
( V_155 << V_161 ) |
( V_156 << V_162 ) ) ;
if ( V_143 )
F_12 ( V_4 , true ) ;
}
static void F_47 ( struct V_163 * V_52 ,
struct V_70 * V_71 ,
T_3 V_164 ,
T_3 V_165 ,
int V_62 ,
bool V_72 , bool V_166 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_125 = F_48 ( V_52 ) -> V_125 ;
int V_167 = F_48 ( V_52 ) -> V_52 ;
int V_119 ;
int V_126 ;
int V_168 ;
int V_118 ;
const int V_128 = F_40 ( V_2 ) ?
V_120 : V_122 ;
V_168 = F_3 ( F_42 ( V_125 ) ) & ~ ( F_49 ( V_167 ) |
( V_123 << F_50 ( V_167 ) ) ) ;
if ( V_72 && F_38 ( V_71 , V_62 , & V_118 ,
& V_119 ) ) {
V_126 = ( V_118 == V_128 ) ?
F_49 ( V_167 ) :
F_51 ( V_167 ) ;
V_168 |= V_126 |
( V_119 << F_50 ( V_167 ) ) ;
}
F_2 ( F_42 ( V_125 ) , V_168 ) ;
}
static void F_52 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
static const int V_135 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_136 , V_137 , V_138 , V_139 ;
int V_140 , V_89 ;
unsigned int V_72 = 0 ;
bool V_143 ;
if ( F_32 ( V_2 , V_144 ,
& V_169 , V_146 ,
& V_170 , V_146 ,
& V_136 , & V_138 ) )
V_72 |= 1 << V_144 ;
if ( F_32 ( V_2 , V_148 ,
& V_169 , V_146 ,
& V_170 , V_146 ,
& V_137 , & V_139 ) )
V_72 |= 1 << V_148 ;
if ( F_44 ( V_72 ) &&
F_36 ( V_2 , F_45 ( V_72 ) - 1 ,
V_135 ,
& V_169 ,
& V_170 ,
& V_140 , & V_89 ) ) {
V_143 = true ;
} else {
V_143 = false ;
F_12 ( V_4 , false ) ;
V_140 = V_89 = 0 ;
}
F_11 ( L_20
L_21 ,
V_136 , V_138 ,
V_137 , V_139 ,
V_140 , V_89 ) ;
F_2 ( V_85 ,
( V_140 << V_87 ) |
( V_139 << V_149 ) |
( V_137 << V_150 ) |
( V_136 << V_151 ) ) ;
F_2 ( V_152 ,
( F_3 ( V_152 ) & ~ V_153 ) |
( V_138 << V_154 ) ) ;
F_2 ( V_48 ,
( F_3 ( V_48 ) & ~ ( V_171 | V_90 ) ) |
( V_89 << V_91 ) ) ;
if ( V_143 )
F_12 ( V_4 , true ) ;
}
static void F_53 ( struct V_70 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_70 * V_71 ;
int V_172 = 1 ;
int V_89 = 16 ;
bool V_143 ;
V_71 = F_26 ( V_2 ) ;
if ( V_71 ) {
static const int V_135 = 12000 ;
const struct V_75 * V_76 =
& F_31 ( V_71 ) -> V_80 -> V_81 . V_76 ;
int clock = V_76 -> V_82 ;
int V_105 = V_76 -> V_111 ;
int V_106 = F_31 ( V_71 ) -> V_80 -> V_112 ;
int V_62 = V_71 -> V_77 -> V_78 -> V_79 / 8 ;
unsigned long V_107 ;
int V_109 ;
V_107 = F_34 ( V_105 * 1000 / clock , 1 ) ;
V_109 = ( ( ( V_135 / V_107 ) + 1000 ) / 1000 ) *
V_62 * V_106 ;
V_109 = F_25 ( V_109 , V_173 ) ;
V_172 = V_174 - V_109 ;
if ( V_172 < 0 )
V_172 = 1 ;
V_172 &= 0x1ff ;
F_11 ( L_24 ,
V_109 , V_172 ) ;
V_109 = ( ( ( V_135 / V_107 ) + 1000 ) / 1000 ) *
V_62 * F_31 ( V_71 ) -> V_113 ;
V_109 = F_25 ( V_109 ,
V_175 . V_66 ) ;
V_89 = V_175 . V_61 -
( V_109 + V_175 . V_67 ) ;
if ( V_89 > V_175 . V_68 )
V_89 = V_175 . V_68 ;
F_11 ( L_25
L_26 , V_172 , V_89 ) ;
V_143 = true ;
} else {
V_143 = false ;
F_12 ( V_4 , false ) ;
}
F_11 ( L_27 ,
V_172 ) ;
F_2 ( V_85 , ( V_172 << V_87 ) |
( 8 << V_149 ) |
( 8 << V_150 ) |
( 8 << V_151 ) ) ;
F_2 ( V_152 , ( 8 << V_154 ) |
( 8 << V_176 ) ) ;
F_2 ( V_48 , ( V_89 << V_91 ) ) ;
if ( V_143 )
F_12 ( V_4 , true ) ;
}
static void F_54 ( struct V_70 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_59 * V_177 ;
T_3 V_178 ;
T_3 V_179 ;
int V_180 , V_172 = 1 ;
int V_61 ;
int V_136 , V_137 ;
struct V_70 * V_71 , * V_72 = NULL ;
if ( F_18 ( V_2 ) )
V_177 = & V_181 ;
else if ( ! F_55 ( V_2 ) )
V_177 = & V_182 ;
else
V_177 = & V_183 ;
V_61 = V_4 -> V_99 . V_184 ( V_2 , 0 ) ;
V_71 = F_33 ( V_2 , 0 ) ;
if ( F_28 ( V_71 ) ) {
const struct V_75 * V_76 ;
int V_185 = V_71 -> V_77 -> V_78 -> V_79 / 8 ;
if ( F_55 ( V_2 ) )
V_185 = 4 ;
V_76 = & F_31 ( V_71 ) -> V_80 -> V_81 . V_76 ;
V_136 = F_24 ( V_76 -> V_82 ,
V_177 , V_61 , V_185 ,
V_146 ) ;
V_72 = V_71 ;
} else {
V_136 = V_61 - V_177 -> V_67 ;
if ( V_136 > ( long ) V_177 -> V_68 )
V_136 = V_177 -> V_68 ;
}
if ( F_55 ( V_2 ) )
V_177 = & V_186 ;
V_61 = V_4 -> V_99 . V_184 ( V_2 , 1 ) ;
V_71 = F_33 ( V_2 , 1 ) ;
if ( F_28 ( V_71 ) ) {
const struct V_75 * V_76 ;
int V_185 = V_71 -> V_77 -> V_78 -> V_79 / 8 ;
if ( F_55 ( V_2 ) )
V_185 = 4 ;
V_76 = & F_31 ( V_71 ) -> V_80 -> V_81 . V_76 ;
V_137 = F_24 ( V_76 -> V_82 ,
V_177 , V_61 , V_185 ,
V_146 ) ;
if ( V_72 == NULL )
V_72 = V_71 ;
else
V_72 = NULL ;
} else {
V_137 = V_61 - V_177 -> V_67 ;
if ( V_137 > ( long ) V_177 -> V_68 )
V_137 = V_177 -> V_68 ;
}
F_11 ( L_28 , V_136 , V_137 ) ;
if ( F_20 ( V_2 ) && V_72 ) {
struct V_187 * V_188 ;
V_188 = F_56 ( V_72 -> V_77 -> V_78 ) ;
if ( V_188 -> V_189 == V_190 )
V_72 = NULL ;
}
V_180 = 2 ;
F_12 ( V_4 , false ) ;
if ( F_57 ( V_2 ) && V_72 ) {
static const int V_135 = 6000 ;
const struct V_75 * V_76 =
& F_31 ( V_72 ) -> V_80 -> V_81 . V_76 ;
int clock = V_76 -> V_82 ;
int V_105 = V_76 -> V_111 ;
int V_106 = F_31 ( V_72 ) -> V_80 -> V_112 ;
int V_62 = V_72 -> V_77 -> V_78 -> V_79 / 8 ;
unsigned long V_107 ;
int V_109 ;
V_107 = F_34 ( V_105 * 1000 / clock , 1 ) ;
V_109 = ( ( ( V_135 / V_107 ) + 1000 ) / 1000 ) *
V_62 * V_106 ;
V_109 = F_25 ( V_109 , V_177 -> V_66 ) ;
F_11 ( L_29 , V_109 ) ;
V_172 = V_177 -> V_61 - V_109 ;
if ( V_172 < 0 )
V_172 = 1 ;
if ( F_17 ( V_2 ) || F_18 ( V_2 ) )
F_2 ( V_46 ,
V_191 | ( V_172 & 0xff ) ) ;
else if ( F_20 ( V_2 ) )
F_2 ( V_46 , V_172 & 0x3f ) ;
}
F_11 ( L_30 ,
V_136 , V_137 , V_180 , V_172 ) ;
V_178 = ( ( V_137 & 0x3f ) << 16 ) | ( V_136 & 0x3f ) ;
V_179 = ( V_180 & 0x1f ) ;
V_178 = V_178 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_179 = V_179 | ( 1 << 8 ) ;
F_2 ( V_192 , V_178 ) ;
F_2 ( V_193 , V_179 ) ;
if ( V_72 )
F_12 ( V_4 , true ) ;
}
static void F_58 ( struct V_70 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_70 * V_71 ;
const struct V_75 * V_76 ;
T_3 V_178 ;
int V_136 ;
V_71 = F_26 ( V_2 ) ;
if ( V_71 == NULL )
return;
V_76 = & F_31 ( V_71 ) -> V_80 -> V_81 . V_76 ;
V_136 = F_24 ( V_76 -> V_82 ,
& V_194 ,
V_4 -> V_99 . V_184 ( V_2 , 0 ) ,
4 , V_146 ) ;
V_178 = F_3 ( V_192 ) & ~ 0xfff ;
V_178 |= ( 3 << 8 ) | V_136 ;
F_11 ( L_31 , V_136 ) ;
F_2 ( V_192 , V_178 ) ;
}
static T_3 F_59 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_124 * V_124 = F_31 ( V_71 ) ;
T_3 V_195 ;
V_195 = V_124 -> V_80 -> V_81 . V_76 . V_82 ;
if ( V_124 -> V_80 -> V_196 . V_72 ) {
T_4 V_197 , V_198 , V_199 , V_200 ;
T_3 V_201 = V_124 -> V_80 -> V_196 . V_55 ;
V_197 = V_124 -> V_80 -> V_112 ;
V_198 = V_124 -> V_80 -> V_202 ;
V_199 = ( V_201 >> 16 ) & 0xFFFF ;
V_200 = V_201 & 0xFFFF ;
if ( V_197 < V_199 )
V_197 = V_199 ;
if ( V_198 < V_200 )
V_198 = V_200 ;
V_195 = F_60 ( ( T_4 ) V_195 * V_197 * V_198 ,
V_199 * V_200 ) ;
}
return V_195 ;
}
static T_3 F_61 ( T_3 V_195 , T_5 V_203 ,
T_3 V_39 )
{
T_4 V_204 ;
if ( F_39 ( V_39 == 0 , L_32 ) )
return V_205 ;
V_204 = ( T_4 ) V_195 * V_203 * V_39 ;
V_204 = F_62 ( V_204 , 64 * 10000 ) + 2 ;
return V_204 ;
}
static T_3 F_63 ( T_3 V_195 , T_3 V_206 ,
T_3 V_207 , T_5 V_203 ,
T_3 V_39 )
{
T_3 V_204 ;
if ( F_39 ( V_39 == 0 , L_32 ) )
return V_205 ;
V_204 = ( V_39 * V_195 ) / ( V_206 * 10000 ) ;
V_204 = ( V_204 + 1 ) * V_207 * V_203 ;
V_204 = F_25 ( V_204 , 64 ) + 2 ;
return V_204 ;
}
static T_3 F_64 ( T_3 V_208 , T_3 V_207 ,
T_5 V_203 )
{
return F_25 ( V_208 * 64 , V_207 * V_203 ) + 2 ;
}
static T_3 F_65 ( const struct V_209 * V_210 ,
T_3 V_211 ,
bool V_212 )
{
T_3 V_213 , V_214 ;
if ( ! V_210 -> V_215 || ! V_210 -> V_216 . V_72 )
return 0 ;
V_213 = F_61 ( V_210 -> V_195 ,
V_210 -> V_216 . V_203 ,
V_211 ) ;
if ( ! V_212 )
return V_213 ;
V_214 = F_63 ( V_210 -> V_195 ,
V_210 -> V_206 ,
V_210 -> V_216 . V_207 ,
V_210 -> V_216 . V_203 ,
V_211 ) ;
return F_37 ( V_213 , V_214 ) ;
}
static T_3 F_66 ( const struct V_209 * V_210 ,
T_3 V_211 )
{
T_3 V_213 , V_214 ;
if ( ! V_210 -> V_215 || ! V_210 -> V_217 . V_72 )
return 0 ;
V_213 = F_61 ( V_210 -> V_195 ,
V_210 -> V_217 . V_203 ,
V_211 ) ;
V_214 = F_63 ( V_210 -> V_195 ,
V_210 -> V_206 ,
V_210 -> V_217 . V_207 ,
V_210 -> V_217 . V_203 ,
V_211 ) ;
return F_37 ( V_213 , V_214 ) ;
}
static T_3 F_67 ( const struct V_209 * V_210 ,
T_3 V_211 )
{
if ( ! V_210 -> V_215 || ! V_210 -> V_218 . V_72 )
return 0 ;
return F_63 ( V_210 -> V_195 ,
V_210 -> V_206 ,
V_210 -> V_218 . V_207 ,
V_210 -> V_218 . V_203 ,
V_211 ) ;
}
static T_3 F_68 ( const struct V_209 * V_210 ,
T_3 V_208 )
{
if ( ! V_210 -> V_215 || ! V_210 -> V_216 . V_72 )
return 0 ;
return F_64 ( V_208 ,
V_210 -> V_216 . V_207 ,
V_210 -> V_216 . V_203 ) ;
}
static unsigned int F_69 ( const struct V_1 * V_2 )
{
if ( F_70 ( V_2 ) -> V_219 >= 8 )
return 3072 ;
else if ( F_70 ( V_2 ) -> V_219 >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int F_71 ( const struct V_1 * V_2 ,
int V_220 , bool V_221 )
{
if ( F_70 ( V_2 ) -> V_219 >= 8 )
return V_220 == 0 ? 255 : 2047 ;
else if ( F_70 ( V_2 ) -> V_219 >= 7 )
return V_220 == 0 ? 127 : 1023 ;
else if ( ! V_221 )
return V_220 == 0 ? 127 : 511 ;
else
return V_220 == 0 ? 63 : 255 ;
}
static unsigned int F_72 ( const struct V_1 * V_2 ,
int V_220 )
{
if ( F_70 ( V_2 ) -> V_219 >= 7 )
return V_220 == 0 ? 63 : 255 ;
else
return V_220 == 0 ? 31 : 63 ;
}
static unsigned int F_73 ( const struct V_1 * V_2 )
{
if ( F_70 ( V_2 ) -> V_219 >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_74 ( const struct V_1 * V_2 ,
int V_220 ,
const struct V_222 * V_80 ,
enum V_223 V_224 ,
bool V_221 )
{
unsigned int V_61 = F_69 ( V_2 ) ;
if ( V_221 && ! V_80 -> V_225 )
return 0 ;
if ( V_220 == 0 || V_80 -> V_226 > 1 ) {
V_61 /= F_70 ( V_2 ) -> V_227 ;
if ( F_70 ( V_2 ) -> V_219 <= 6 )
V_61 /= 2 ;
}
if ( V_80 -> V_225 ) {
if ( V_220 > 0 && V_224 == V_228 ) {
if ( V_221 )
V_61 *= 5 ;
V_61 /= 6 ;
} else {
V_61 /= 2 ;
}
}
return F_37 ( V_61 , F_71 ( V_2 , V_220 , V_221 ) ) ;
}
static unsigned int F_75 ( const struct V_1 * V_2 ,
int V_220 ,
const struct V_222 * V_80 )
{
if ( V_220 > 0 && V_80 -> V_226 > 1 )
return 64 ;
return F_72 ( V_2 , V_220 ) ;
}
static void F_76 ( const struct V_1 * V_2 ,
int V_220 ,
const struct V_222 * V_80 ,
enum V_223 V_224 ,
struct V_229 * F_34 )
{
F_34 -> V_216 = F_74 ( V_2 , V_220 , V_80 , V_224 , false ) ;
F_34 -> V_217 = F_74 ( V_2 , V_220 , V_80 , V_224 , true ) ;
F_34 -> V_218 = F_75 ( V_2 , V_220 , V_80 ) ;
F_34 -> V_230 = F_73 ( V_2 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
int V_220 ,
struct V_229 * F_34 )
{
F_34 -> V_216 = F_71 ( V_2 , V_220 , false ) ;
F_34 -> V_217 = F_71 ( V_2 , V_220 , true ) ;
F_34 -> V_218 = F_72 ( V_2 , V_220 ) ;
F_34 -> V_230 = F_73 ( V_2 ) ;
}
static bool F_78 ( int V_220 ,
const struct V_229 * F_34 ,
struct V_231 * V_232 )
{
bool V_204 ;
if ( ! V_232 -> V_42 )
return false ;
V_232 -> V_42 = V_232 -> V_208 <= F_34 -> V_216 &&
V_232 -> V_233 <= F_34 -> V_217 &&
V_232 -> V_234 <= F_34 -> V_218 ;
V_204 = V_232 -> V_42 ;
if ( V_220 == 0 && ! V_232 -> V_42 ) {
if ( V_232 -> V_208 > F_34 -> V_216 )
F_11 ( L_33 ,
V_220 , V_232 -> V_208 , F_34 -> V_216 ) ;
if ( V_232 -> V_233 > F_34 -> V_217 )
F_11 ( L_34 ,
V_220 , V_232 -> V_233 , F_34 -> V_217 ) ;
if ( V_232 -> V_234 > F_34 -> V_218 )
F_11 ( L_35 ,
V_220 , V_232 -> V_234 , F_34 -> V_218 ) ;
V_232 -> V_208 = F_79 ( T_3 , V_232 -> V_208 , F_34 -> V_216 ) ;
V_232 -> V_233 = F_79 ( T_3 , V_232 -> V_233 , F_34 -> V_217 ) ;
V_232 -> V_234 = F_79 ( T_3 , V_232 -> V_234 , F_34 -> V_218 ) ;
V_232 -> V_42 = true ;
}
return V_204 ;
}
static void F_80 ( const struct V_3 * V_4 ,
int V_220 ,
const struct V_209 * V_235 ,
struct V_231 * V_232 )
{
T_6 V_236 = V_4 -> V_60 . V_236 [ V_220 ] ;
T_6 V_237 = V_4 -> V_60 . V_237 [ V_220 ] ;
T_6 V_238 = V_4 -> V_60 . V_238 [ V_220 ] ;
if ( V_220 > 0 ) {
V_236 *= 5 ;
V_237 *= 5 ;
V_238 *= 5 ;
}
V_232 -> V_208 = F_65 ( V_235 , V_236 , V_220 ) ;
V_232 -> V_233 = F_66 ( V_235 , V_237 ) ;
V_232 -> V_234 = F_67 ( V_235 , V_238 ) ;
V_232 -> V_239 = F_68 ( V_235 , V_232 -> V_208 ) ;
V_232 -> V_42 = true ;
}
static T_3
F_81 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_31 ( V_71 ) ;
struct V_75 * V_240 = & V_124 -> V_80 -> V_81 . V_76 ;
T_1 V_241 , V_242 ;
if ( ! F_28 ( V_71 ) )
return 0 ;
V_241 = F_82 ( V_240 -> V_111 * 1000 * 8 ,
V_240 -> V_82 ) ;
V_242 = F_82 ( V_240 -> V_111 * 1000 * 8 ,
F_83 ( V_4 ) ) ;
return F_84 ( V_242 ) |
F_85 ( V_241 ) ;
}
static void F_86 ( struct V_1 * V_2 , T_6 V_60 [ 8 ] )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_87 ( V_2 ) ) {
T_3 V_43 ;
int V_204 , V_40 ;
int V_220 , V_243 = F_88 ( V_2 ) ;
V_43 = 0 ;
F_89 ( & V_4 -> V_244 . V_245 ) ;
V_204 = F_90 ( V_4 ,
V_246 ,
& V_43 ) ;
F_91 ( & V_4 -> V_244 . V_245 ) ;
if ( V_204 ) {
F_92 ( L_36 , V_204 ) ;
return;
}
V_60 [ 0 ] = V_43 & V_247 ;
V_60 [ 1 ] = ( V_43 >> V_248 ) &
V_247 ;
V_60 [ 2 ] = ( V_43 >> V_249 ) &
V_247 ;
V_60 [ 3 ] = ( V_43 >> V_250 ) &
V_247 ;
V_43 = 1 ;
F_89 ( & V_4 -> V_244 . V_245 ) ;
V_204 = F_90 ( V_4 ,
V_246 ,
& V_43 ) ;
F_91 ( & V_4 -> V_244 . V_245 ) ;
if ( V_204 ) {
F_92 ( L_36 , V_204 ) ;
return;
}
V_60 [ 4 ] = V_43 & V_247 ;
V_60 [ 5 ] = ( V_43 >> V_248 ) &
V_247 ;
V_60 [ 6 ] = ( V_43 >> V_249 ) &
V_247 ;
V_60 [ 7 ] = ( V_43 >> V_250 ) &
V_247 ;
V_60 [ 0 ] += 2 ;
for ( V_220 = 1 ; V_220 <= V_243 ; V_220 ++ )
if ( V_60 [ V_220 ] != 0 )
V_60 [ V_220 ] += 2 ;
else {
for ( V_40 = V_220 + 1 ; V_40 <= V_243 ; V_40 ++ )
V_60 [ V_40 ] = 0 ;
break;
}
} else if ( F_93 ( V_2 ) || F_94 ( V_2 ) ) {
T_4 V_251 = F_95 ( V_252 ) ;
V_60 [ 0 ] = ( V_251 >> 56 ) & 0xFF ;
if ( V_60 [ 0 ] == 0 )
V_60 [ 0 ] = V_251 & 0xF ;
V_60 [ 1 ] = ( V_251 >> 4 ) & 0xFF ;
V_60 [ 2 ] = ( V_251 >> 12 ) & 0xFF ;
V_60 [ 3 ] = ( V_251 >> 20 ) & 0x1FF ;
V_60 [ 4 ] = ( V_251 >> 32 ) & 0x1FF ;
} else if ( F_70 ( V_2 ) -> V_219 >= 6 ) {
T_3 V_251 = F_3 ( V_252 ) ;
V_60 [ 0 ] = ( V_251 >> V_253 ) & V_254 ;
V_60 [ 1 ] = ( V_251 >> V_255 ) & V_254 ;
V_60 [ 2 ] = ( V_251 >> V_256 ) & V_254 ;
V_60 [ 3 ] = ( V_251 >> V_257 ) & V_254 ;
} else if ( F_70 ( V_2 ) -> V_219 >= 5 ) {
T_3 V_258 = F_3 ( V_259 ) ;
V_60 [ 0 ] = 7 ;
V_60 [ 1 ] = ( V_258 >> V_260 ) & V_261 ;
V_60 [ 2 ] = ( V_258 >> V_262 ) & V_261 ;
}
}
static void F_96 ( struct V_1 * V_2 , T_6 V_60 [ 5 ] )
{
if ( F_70 ( V_2 ) -> V_219 == 5 )
V_60 [ 0 ] = 13 ;
}
static void F_97 ( struct V_1 * V_2 , T_6 V_60 [ 5 ] )
{
if ( F_70 ( V_2 ) -> V_219 == 5 )
V_60 [ 0 ] = 13 ;
if ( F_98 ( V_2 ) )
V_60 [ 3 ] *= 2 ;
}
int F_88 ( const struct V_1 * V_2 )
{
if ( F_87 ( V_2 ) )
return 7 ;
else if ( F_93 ( V_2 ) || F_94 ( V_2 ) )
return 4 ;
else if ( F_70 ( V_2 ) -> V_219 >= 6 )
return 3 ;
else
return 2 ;
}
static void F_99 ( struct V_1 * V_2 ,
const char * V_263 ,
const T_6 V_60 [ 8 ] )
{
int V_220 , V_243 = F_88 ( V_2 ) ;
for ( V_220 = 0 ; V_220 <= V_243 ; V_220 ++ ) {
unsigned int V_39 = V_60 [ V_220 ] ;
if ( V_39 == 0 ) {
F_92 ( L_37 ,
V_263 , V_220 ) ;
continue;
}
if ( F_87 ( V_2 ) )
V_39 *= 10 ;
else if ( V_220 > 0 )
V_39 *= 5 ;
F_11 ( L_38 ,
V_263 , V_220 , V_60 [ V_220 ] ,
V_39 / 10 , V_39 % 10 ) ;
}
}
static bool F_100 ( struct V_3 * V_4 ,
T_6 V_60 [ 5 ] , T_6 F_37 )
{
int V_220 , V_243 = F_88 ( V_4 -> V_2 ) ;
if ( V_60 [ 0 ] >= F_37 )
return false ;
V_60 [ 0 ] = F_34 ( V_60 [ 0 ] , F_37 ) ;
for ( V_220 = 1 ; V_220 <= V_243 ; V_220 ++ )
V_60 [ V_220 ] = F_101 ( T_6 , V_60 [ V_220 ] , F_25 ( F_37 , 5 ) ) ;
return true ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_264 ;
V_264 = F_100 ( V_4 , V_4 -> V_60 . V_236 , 12 ) |
F_100 ( V_4 , V_4 -> V_60 . V_237 , 12 ) |
F_100 ( V_4 , V_4 -> V_60 . V_238 , 12 ) ;
if ( ! V_264 )
return;
F_11 ( L_39 ) ;
F_99 ( V_2 , L_40 , V_4 -> V_60 . V_236 ) ;
F_99 ( V_2 , L_41 , V_4 -> V_60 . V_237 ) ;
F_99 ( V_2 , L_42 , V_4 -> V_60 . V_238 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_86 ( V_2 , V_4 -> V_60 . V_236 ) ;
memcpy ( V_4 -> V_60 . V_237 , V_4 -> V_60 . V_236 ,
sizeof( V_4 -> V_60 . V_236 ) ) ;
memcpy ( V_4 -> V_60 . V_238 , V_4 -> V_60 . V_236 ,
sizeof( V_4 -> V_60 . V_236 ) ) ;
F_96 ( V_2 , V_4 -> V_60 . V_237 ) ;
F_97 ( V_2 , V_4 -> V_60 . V_238 ) ;
F_99 ( V_2 , L_40 , V_4 -> V_60 . V_236 ) ;
F_99 ( V_2 , L_41 , V_4 -> V_60 . V_237 ) ;
F_99 ( V_2 , L_42 , V_4 -> V_60 . V_238 ) ;
if ( F_104 ( V_2 ) )
F_102 ( V_2 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_86 ( V_2 , V_4 -> V_60 . V_265 ) ;
F_99 ( V_2 , L_43 , V_4 -> V_60 . V_265 ) ;
}
static void F_106 ( struct V_70 * V_71 ,
struct V_209 * V_235 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_124 * V_124 = F_31 ( V_71 ) ;
enum V_125 V_125 = V_124 -> V_125 ;
struct V_163 * V_52 ;
if ( ! F_28 ( V_71 ) )
return;
V_235 -> V_215 = true ;
V_235 -> V_206 = V_124 -> V_80 -> V_81 . V_76 . V_111 ;
V_235 -> V_195 = F_59 ( V_2 , V_71 ) ;
V_235 -> V_216 . V_203 = V_71 -> V_77 -> V_78 -> V_79 / 8 ;
V_235 -> V_218 . V_203 = 4 ;
V_235 -> V_216 . V_207 = V_124 -> V_80 -> V_112 ;
V_235 -> V_218 . V_207 = V_124 -> V_113 ;
V_235 -> V_216 . V_72 = true ;
V_235 -> V_218 . V_72 = true ;
F_107 (plane, &dev->mode_config.plane_list) {
struct V_266 * V_266 = F_48 ( V_52 ) ;
if ( V_266 -> V_125 == V_125 ) {
V_235 -> V_217 = V_266 -> V_60 ;
break;
}
}
}
static void F_108 ( struct V_1 * V_2 ,
struct V_222 * V_80 )
{
struct V_124 * V_124 ;
F_109 (dev, intel_crtc) {
const struct V_267 * V_60 = & V_124 -> V_60 . V_215 ;
if ( ! V_60 -> V_268 )
continue;
V_80 -> V_225 |= V_60 -> V_225 ;
V_80 -> V_269 |= V_60 -> V_269 ;
V_80 -> V_226 ++ ;
}
}
static bool F_110 ( struct V_70 * V_71 ,
const struct V_209 * V_210 ,
struct V_267 * V_270 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
int V_220 , V_243 = F_88 ( V_2 ) ;
struct V_222 V_80 = {
. V_226 = 1 ,
. V_225 = V_210 -> V_217 . V_72 ,
. V_269 = V_210 -> V_217 . V_166 ,
} ;
struct V_229 F_34 ;
V_270 -> V_268 = V_210 -> V_215 ;
V_270 -> V_225 = V_210 -> V_217 . V_72 ;
V_270 -> V_269 = V_210 -> V_217 . V_166 ;
if ( F_70 ( V_2 ) -> V_219 <= 6 && V_210 -> V_217 . V_72 )
V_243 = 1 ;
if ( V_210 -> V_217 . V_166 )
V_243 = 0 ;
F_80 ( V_4 , 0 , V_210 , & V_270 -> V_60 [ 0 ] ) ;
if ( F_93 ( V_2 ) || F_94 ( V_2 ) )
V_270 -> V_241 = F_81 ( V_2 , V_71 ) ;
F_76 ( V_2 , 0 , & V_80 , V_271 , & F_34 ) ;
if ( ! F_78 ( 0 , & F_34 , & V_270 -> V_60 [ 0 ] ) )
return false ;
F_77 ( V_2 , 1 , & F_34 ) ;
for ( V_220 = 1 ; V_220 <= V_243 ; V_220 ++ ) {
struct V_231 V_60 = {} ;
F_80 ( V_4 , V_220 , V_210 , & V_60 ) ;
if ( ! F_78 ( V_220 , & F_34 , & V_60 ) )
break;
V_270 -> V_60 [ V_220 ] = V_60 ;
}
return true ;
}
static void F_111 ( struct V_1 * V_2 ,
int V_220 ,
struct V_231 * V_272 )
{
const struct V_124 * V_124 ;
V_272 -> V_42 = true ;
F_109 (dev, intel_crtc) {
const struct V_267 * V_215 = & V_124 -> V_60 . V_215 ;
const struct V_231 * V_60 = & V_215 -> V_60 [ V_220 ] ;
if ( ! V_215 -> V_268 )
continue;
if ( ! V_60 -> V_42 )
V_272 -> V_42 = false ;
V_272 -> V_208 = F_34 ( V_272 -> V_208 , V_60 -> V_208 ) ;
V_272 -> V_233 = F_34 ( V_272 -> V_233 , V_60 -> V_233 ) ;
V_272 -> V_234 = F_34 ( V_272 -> V_234 , V_60 -> V_234 ) ;
V_272 -> V_239 = F_34 ( V_272 -> V_239 , V_60 -> V_239 ) ;
}
}
static void F_112 ( struct V_1 * V_2 ,
const struct V_222 * V_80 ,
const struct V_229 * F_34 ,
struct V_267 * V_273 )
{
int V_220 , V_243 = F_88 ( V_2 ) ;
int V_274 = V_243 ;
if ( ( F_70 ( V_2 ) -> V_219 <= 6 || F_98 ( V_2 ) ) &&
V_80 -> V_226 > 1 )
return;
V_273 -> V_275 = F_70 ( V_2 ) -> V_219 >= 6 ;
for ( V_220 = 1 ; V_220 <= V_243 ; V_220 ++ ) {
struct V_231 * V_60 = & V_273 -> V_60 [ V_220 ] ;
F_111 ( V_2 , V_220 , V_60 ) ;
if ( V_220 > V_274 )
V_60 -> V_42 = false ;
else if ( ! F_78 ( V_220 , F_34 , V_60 ) )
V_274 = V_220 - 1 ;
if ( V_60 -> V_239 > F_34 -> V_230 ) {
if ( V_60 -> V_42 )
V_273 -> V_275 = false ;
V_60 -> V_239 = 0 ;
}
}
if ( F_113 ( V_2 ) && ! V_273 -> V_275 && F_114 ( V_2 ) ) {
for ( V_220 = 2 ; V_220 <= V_243 ; V_220 ++ ) {
struct V_231 * V_60 = & V_273 -> V_60 [ V_220 ] ;
V_60 -> V_42 = false ;
}
}
}
static int F_115 ( int V_276 , const struct V_267 * V_270 )
{
return V_276 + ( V_276 >= 2 && V_270 -> V_60 [ 4 ] . V_42 ) ;
}
static unsigned int F_116 ( struct V_1 * V_2 , int V_220 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_93 ( V_2 ) || F_94 ( V_2 ) )
return 2 * V_220 ;
else
return V_4 -> V_60 . V_236 [ V_220 ] ;
}
static void F_117 ( struct V_1 * V_2 ,
const struct V_267 * V_273 ,
enum V_223 V_277 ,
struct V_278 * V_279 )
{
struct V_124 * V_124 ;
int V_220 , V_276 ;
V_279 -> V_280 = V_273 -> V_275 ;
V_279 -> V_277 = V_277 ;
for ( V_276 = 1 ; V_276 <= 3 ; V_276 ++ ) {
const struct V_231 * V_281 ;
V_220 = F_115 ( V_276 , V_273 ) ;
V_281 = & V_273 -> V_60 [ V_220 ] ;
V_279 -> V_276 [ V_276 - 1 ] =
( F_116 ( V_2 , V_220 ) << V_282 ) |
( V_281 -> V_208 << V_283 ) |
V_281 -> V_234 ;
if ( V_281 -> V_42 )
V_279 -> V_276 [ V_276 - 1 ] |= V_284 ;
if ( F_70 ( V_2 ) -> V_219 >= 8 )
V_279 -> V_276 [ V_276 - 1 ] |=
V_281 -> V_239 << V_285 ;
else
V_279 -> V_276 [ V_276 - 1 ] |=
V_281 -> V_239 << V_286 ;
if ( F_70 ( V_2 ) -> V_219 <= 6 && V_281 -> V_233 ) {
F_118 ( V_276 != 1 ) ;
V_279 -> V_287 [ V_276 - 1 ] = V_288 | V_281 -> V_233 ;
} else
V_279 -> V_287 [ V_276 - 1 ] = V_281 -> V_233 ;
}
F_109 (dev, intel_crtc) {
enum V_125 V_125 = V_124 -> V_125 ;
const struct V_231 * V_281 =
& V_124 -> V_60 . V_215 . V_60 [ 0 ] ;
if ( F_118 ( ! V_281 -> V_42 ) )
continue;
V_279 -> V_289 [ V_125 ] = V_124 -> V_60 . V_215 . V_241 ;
V_279 -> V_290 [ V_125 ] =
( V_281 -> V_208 << V_291 ) |
( V_281 -> V_233 << V_292 ) |
V_281 -> V_234 ;
}
}
static struct V_267 * F_119 ( struct V_1 * V_2 ,
struct V_267 * V_293 ,
struct V_267 * V_294 )
{
int V_220 , V_243 = F_88 ( V_2 ) ;
int V_295 = 0 , V_296 = 0 ;
for ( V_220 = 1 ; V_220 <= V_243 ; V_220 ++ ) {
if ( V_293 -> V_60 [ V_220 ] . V_42 )
V_295 = V_220 ;
if ( V_294 -> V_60 [ V_220 ] . V_42 )
V_296 = V_220 ;
}
if ( V_295 == V_296 ) {
if ( V_294 -> V_275 && ! V_293 -> V_275 )
return V_294 ;
else
return V_293 ;
} else if ( V_295 > V_296 ) {
return V_293 ;
} else {
return V_294 ;
}
}
static unsigned int F_120 ( struct V_3 * V_4 ,
const struct V_278 * V_297 ,
const struct V_278 * V_298 )
{
unsigned int V_299 = 0 ;
enum V_125 V_125 ;
int V_276 ;
F_121 (dev_priv, pipe) {
if ( V_297 -> V_289 [ V_125 ] != V_298 -> V_289 [ V_125 ] ) {
V_299 |= F_122 ( V_125 ) ;
V_299 |= V_300 ;
}
if ( V_297 -> V_290 [ V_125 ] != V_298 -> V_290 [ V_125 ] ) {
V_299 |= F_123 ( V_125 ) ;
V_299 |= V_300 ;
}
}
if ( V_297 -> V_280 != V_298 -> V_280 ) {
V_299 |= V_301 ;
V_299 |= V_300 ;
}
if ( V_297 -> V_277 != V_298 -> V_277 ) {
V_299 |= V_302 ;
V_299 |= V_300 ;
}
if ( V_299 & V_300 )
return V_299 ;
for ( V_276 = 1 ; V_276 <= 3 ; V_276 ++ ) {
if ( V_297 -> V_276 [ V_276 - 1 ] != V_298 -> V_276 [ V_276 - 1 ] ||
V_297 -> V_287 [ V_276 - 1 ] != V_298 -> V_287 [ V_276 - 1 ] )
break;
}
for (; V_276 <= 3 ; V_276 ++ )
V_299 |= F_124 ( V_276 ) ;
return V_299 ;
}
static bool F_125 ( struct V_3 * V_4 ,
unsigned int V_299 )
{
struct V_278 * V_303 = & V_4 -> V_60 . V_304 ;
bool V_264 = false ;
if ( V_299 & F_124 ( 3 ) && V_303 -> V_276 [ 2 ] & V_284 ) {
V_303 -> V_276 [ 2 ] &= ~ V_284 ;
F_2 ( V_305 , V_303 -> V_276 [ 2 ] ) ;
V_264 = true ;
}
if ( V_299 & F_124 ( 2 ) && V_303 -> V_276 [ 1 ] & V_284 ) {
V_303 -> V_276 [ 1 ] &= ~ V_284 ;
F_2 ( V_306 , V_303 -> V_276 [ 1 ] ) ;
V_264 = true ;
}
if ( V_299 & F_124 ( 1 ) && V_303 -> V_276 [ 0 ] & V_284 ) {
V_303 -> V_276 [ 0 ] &= ~ V_284 ;
F_2 ( V_307 , V_303 -> V_276 [ 0 ] ) ;
V_264 = true ;
}
return V_264 ;
}
static void F_126 ( struct V_3 * V_4 ,
struct V_278 * V_279 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_278 * V_303 = & V_4 -> V_60 . V_304 ;
unsigned int V_299 ;
T_3 V_43 ;
V_299 = F_120 ( V_4 , V_303 , V_279 ) ;
if ( ! V_299 )
return;
F_125 ( V_4 , V_299 ) ;
if ( V_299 & F_123 ( V_144 ) )
F_2 ( V_308 , V_279 -> V_290 [ 0 ] ) ;
if ( V_299 & F_123 ( V_148 ) )
F_2 ( V_309 , V_279 -> V_290 [ 1 ] ) ;
if ( V_299 & F_123 ( V_157 ) )
F_2 ( V_310 , V_279 -> V_290 [ 2 ] ) ;
if ( V_299 & F_122 ( V_144 ) )
F_2 ( F_127 ( V_144 ) , V_279 -> V_289 [ 0 ] ) ;
if ( V_299 & F_122 ( V_148 ) )
F_2 ( F_127 ( V_148 ) , V_279 -> V_289 [ 1 ] ) ;
if ( V_299 & F_122 ( V_157 ) )
F_2 ( F_127 ( V_157 ) , V_279 -> V_289 [ 2 ] ) ;
if ( V_299 & V_302 ) {
if ( F_93 ( V_2 ) || F_94 ( V_2 ) ) {
V_43 = F_3 ( V_311 ) ;
if ( V_279 -> V_277 == V_271 )
V_43 &= ~ V_312 ;
else
V_43 |= V_312 ;
F_2 ( V_311 , V_43 ) ;
} else {
V_43 = F_3 ( V_313 ) ;
if ( V_279 -> V_277 == V_271 )
V_43 &= ~ V_314 ;
else
V_43 |= V_314 ;
F_2 ( V_313 , V_43 ) ;
}
}
if ( V_299 & V_301 ) {
V_43 = F_3 ( V_315 ) ;
if ( V_279 -> V_280 )
V_43 &= ~ V_316 ;
else
V_43 |= V_316 ;
F_2 ( V_315 , V_43 ) ;
}
if ( V_299 & F_124 ( 1 ) &&
V_303 -> V_287 [ 0 ] != V_279 -> V_287 [ 0 ] )
F_2 ( V_317 , V_279 -> V_287 [ 0 ] ) ;
if ( F_70 ( V_2 ) -> V_219 >= 7 ) {
if ( V_299 & F_124 ( 2 ) && V_303 -> V_287 [ 1 ] != V_279 -> V_287 [ 1 ] )
F_2 ( V_318 , V_279 -> V_287 [ 1 ] ) ;
if ( V_299 & F_124 ( 3 ) && V_303 -> V_287 [ 2 ] != V_279 -> V_287 [ 2 ] )
F_2 ( V_319 , V_279 -> V_287 [ 2 ] ) ;
}
if ( V_299 & F_124 ( 1 ) && V_303 -> V_276 [ 0 ] != V_279 -> V_276 [ 0 ] )
F_2 ( V_307 , V_279 -> V_276 [ 0 ] ) ;
if ( V_299 & F_124 ( 2 ) && V_303 -> V_276 [ 1 ] != V_279 -> V_276 [ 1 ] )
F_2 ( V_306 , V_279 -> V_276 [ 1 ] ) ;
if ( V_299 & F_124 ( 3 ) && V_303 -> V_276 [ 2 ] != V_279 -> V_276 [ 2 ] )
F_2 ( V_305 , V_279 -> V_276 [ 2 ] ) ;
V_4 -> V_60 . V_304 = * V_279 ;
}
static bool F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_125 ( V_4 , V_300 ) ;
}
static void
F_129 ( struct V_1 * V_2 ,
struct V_70 * V_320 ,
const struct V_222 * V_80 ,
const struct V_321 * V_210 ,
struct V_322 * V_323 )
{
struct V_70 * V_71 ;
unsigned int V_324 , V_325 ;
int V_326 ;
if ( ! V_210 -> V_215 ) {
V_323 -> V_327 = 0 ;
V_323 -> V_328 = 0 ;
return;
}
V_325 = V_329 ;
V_325 -= 4 ;
V_326 = 0 ;
F_27 (dev, crtc) {
if ( ! F_28 ( V_71 ) )
continue;
if ( V_71 == V_320 )
break;
V_326 ++ ;
}
V_324 = V_325 / V_80 -> V_226 ;
V_323 -> V_327 = V_326 * V_325 / V_80 -> V_226 ;
V_323 -> V_328 = V_323 -> V_327 + V_324 ;
}
static unsigned int F_130 ( const struct V_222 * V_80 )
{
if ( V_80 -> V_226 == 1 )
return 32 ;
return 8 ;
}
static void F_131 ( struct V_322 * V_330 , T_1 V_74 )
{
V_330 -> V_327 = V_74 & 0x3ff ;
V_330 -> V_328 = ( V_74 >> 16 ) & 0x3ff ;
if ( V_330 -> V_328 )
V_330 -> V_328 += 1 ;
}
void F_132 ( struct V_3 * V_4 ,
struct V_331 * V_332 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_125 V_125 ;
int V_52 ;
T_1 V_43 ;
F_121 (dev_priv, pipe) {
F_133 (pipe, plane) {
V_43 = F_3 ( F_134 ( V_125 , V_52 ) ) ;
F_131 ( & V_332 -> V_52 [ V_125 ] [ V_52 ] ,
V_43 ) ;
}
V_43 = F_3 ( F_135 ( V_125 ) ) ;
F_131 ( & V_332 -> V_101 [ V_125 ] , V_43 ) ;
}
}
static unsigned int
F_136 ( const struct V_333 * V_235 )
{
return V_235 -> V_207 * V_235 -> V_334 * V_235 -> V_203 ;
}
static unsigned int
F_137 ( struct V_124 * V_124 ,
const struct V_321 * V_210 )
{
unsigned int V_335 = 0 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < F_138 ( V_124 ) ; V_52 ++ ) {
const struct V_333 * V_235 ;
V_235 = & V_210 -> V_52 [ V_52 ] ;
if ( ! V_235 -> V_72 )
continue;
V_335 += F_136 ( V_235 ) ;
}
return V_335 ;
}
static void
F_139 ( struct V_70 * V_71 ,
const struct V_222 * V_80 ,
const struct V_321 * V_210 ,
struct V_331 * V_332 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_124 * V_124 = F_31 ( V_71 ) ;
enum V_125 V_125 = V_124 -> V_125 ;
struct V_322 * V_323 = & V_332 -> V_125 [ V_125 ] ;
T_6 V_336 , V_327 , V_337 ;
unsigned int V_335 ;
int V_52 ;
F_129 ( V_2 , V_71 , V_80 , V_210 , V_323 ) ;
V_336 = F_140 ( V_323 ) ;
if ( V_336 == 0 ) {
memset ( V_332 -> V_52 [ V_125 ] , 0 , sizeof( V_332 -> V_52 [ V_125 ] ) ) ;
memset ( & V_332 -> V_101 [ V_125 ] , 0 , sizeof( V_332 -> V_101 [ V_125 ] ) ) ;
return;
}
V_337 = F_130 ( V_80 ) ;
V_332 -> V_101 [ V_125 ] . V_327 = V_323 -> V_328 - V_337 ;
V_332 -> V_101 [ V_125 ] . V_328 = V_323 -> V_328 ;
V_336 -= V_337 ;
V_323 -> V_328 -= V_337 ;
V_335 = F_137 ( V_124 , V_210 ) ;
V_327 = V_323 -> V_327 ;
for ( V_52 = 0 ; V_52 < F_138 ( V_124 ) ; V_52 ++ ) {
const struct V_333 * V_235 ;
unsigned int V_338 ;
T_6 V_339 ;
V_235 = & V_210 -> V_52 [ V_52 ] ;
if ( ! V_235 -> V_72 )
continue;
V_338 = F_136 ( V_235 ) ;
V_339 = F_60 ( ( T_4 ) V_336 * V_338 ,
V_335 ) ;
V_332 -> V_52 [ V_125 ] [ V_52 ] . V_327 = V_327 ;
V_332 -> V_52 [ V_125 ] [ V_52 ] . V_328 = V_327 + V_339 ;
V_327 += V_339 ;
}
}
static T_3 F_141 ( const struct V_340 * V_80 )
{
return V_80 -> V_81 . V_76 . V_82 ;
}
static T_3 F_142 ( T_3 V_195 , T_5 V_203 ,
T_3 V_39 )
{
T_3 V_341 , V_204 ;
if ( V_39 == 0 )
return V_205 ;
V_341 = V_39 * V_195 * V_203 ;
V_204 = F_25 ( V_341 , 1000 ) ;
return V_204 ;
}
static T_3 F_143 ( T_3 V_195 , T_3 V_206 ,
T_3 V_207 , T_5 V_203 ,
T_3 V_39 )
{
T_3 V_204 , V_342 , V_341 ;
if ( V_39 == 0 )
return V_205 ;
V_342 = V_207 * V_203 ;
V_341 = V_39 * V_195 ;
V_204 = F_25 ( V_341 , V_206 * 1000 ) *
V_342 ;
return V_204 ;
}
static bool F_144 ( const struct V_331 * V_343 ,
const struct V_124 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_81 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_331 * V_344 = & V_4 -> V_60 . V_345 . V_332 ;
enum V_125 V_125 = V_124 -> V_125 ;
if ( memcmp ( V_343 -> V_52 [ V_125 ] , V_344 -> V_52 [ V_125 ] ,
sizeof( V_343 -> V_52 [ V_125 ] ) ) )
return true ;
if ( memcmp ( & V_343 -> V_101 [ V_125 ] , & V_344 -> V_101 [ V_125 ] ,
sizeof( V_343 -> V_101 [ V_125 ] ) ) )
return true ;
return false ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_222 * V_80 )
{
struct V_70 * V_71 ;
struct V_163 * V_52 ;
F_146 (crtc, &dev->mode_config.crtc_list, head)
V_80 -> V_226 += F_28 ( V_71 ) ;
F_146 (plane, &dev->mode_config.plane_list, head) {
struct V_266 * V_266 = F_48 ( V_52 ) ;
V_80 -> V_225 |= V_266 -> V_60 . V_72 ;
V_80 -> V_269 |= V_266 -> V_60 . V_166 ;
}
}
static void F_147 ( struct V_70 * V_71 ,
struct V_321 * V_235 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_124 * V_124 = F_31 ( V_71 ) ;
enum V_125 V_125 = V_124 -> V_125 ;
struct V_163 * V_52 ;
int V_40 = 1 ;
V_235 -> V_215 = F_28 ( V_71 ) ;
if ( V_235 -> V_215 ) {
V_235 -> V_206 = V_124 -> V_80 -> V_81 . V_76 . V_111 ;
V_235 -> V_195 = F_141 ( V_124 -> V_80 ) ;
V_235 -> V_52 [ 0 ] . V_72 = true ;
V_235 -> V_52 [ 0 ] . V_203 =
V_71 -> V_77 -> V_78 -> V_79 / 8 ;
V_235 -> V_52 [ 0 ] . V_207 = V_124 -> V_80 -> V_112 ;
V_235 -> V_52 [ 0 ] . V_334 = V_124 -> V_80 -> V_202 ;
V_235 -> V_101 . V_72 = true ;
V_235 -> V_101 . V_203 = 4 ;
V_235 -> V_101 . V_207 = V_124 -> V_113 ?
V_124 -> V_113 : 64 ;
}
F_146 (plane, &dev->mode_config.plane_list, head) {
struct V_266 * V_266 = F_48 ( V_52 ) ;
if ( V_266 -> V_125 == V_125 &&
V_52 -> type == V_346 )
V_235 -> V_52 [ V_40 ++ ] = V_266 -> V_60 ;
}
}
static bool F_148 ( struct V_321 * V_235 ,
struct V_333 * V_347 ,
T_6 V_348 ,
T_3 V_211 ,
T_6 * V_349 ,
T_5 * V_350 )
{
T_3 V_213 , V_214 , V_342 , V_351 , V_352 ;
T_3 V_353 ;
if ( V_211 == 0 || ! V_235 -> V_215 || ! V_347 -> V_72 )
return false ;
V_213 = F_142 ( V_235 -> V_195 ,
V_347 -> V_203 ,
V_211 ) ;
V_214 = F_143 ( V_235 -> V_195 ,
V_235 -> V_206 ,
V_347 -> V_207 ,
V_347 -> V_203 ,
V_211 ) ;
V_342 = V_347 -> V_207 *
V_347 -> V_203 ;
if ( ( ( V_348 * 512 ) / V_342 ) >= 1 )
V_353 = F_37 ( V_213 , V_214 ) ;
else
V_353 = V_213 ;
V_351 = F_25 ( V_353 , 512 ) + 1 ;
V_352 = F_25 ( V_353 , V_342 ) ;
if ( V_351 > V_348 || V_352 > 31 )
return false ;
* V_349 = V_351 ;
* V_350 = V_352 ;
return true ;
}
static void F_149 ( const struct V_3 * V_4 ,
struct V_331 * V_332 ,
struct V_321 * V_235 ,
enum V_125 V_125 ,
int V_220 ,
int V_354 ,
struct V_355 * V_232 )
{
T_6 V_39 = V_4 -> V_60 . V_265 [ V_220 ] ;
T_6 V_356 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_354 ; V_40 ++ ) {
V_356 = F_140 ( & V_332 -> V_52 [ V_125 ] [ V_40 ] ) ;
V_232 -> V_357 [ V_40 ] = F_148 ( V_235 , & V_235 -> V_52 [ V_40 ] ,
V_356 ,
V_39 ,
& V_232 -> V_358 [ V_40 ] ,
& V_232 -> V_359 [ V_40 ] ) ;
}
V_356 = F_140 ( & V_332 -> V_101 [ V_125 ] ) ;
V_232 -> V_360 = F_148 ( V_235 , & V_235 -> V_101 , V_356 ,
V_39 , & V_232 -> V_361 ,
& V_232 -> V_362 ) ;
}
static T_3
F_150 ( struct V_70 * V_71 , struct V_321 * V_235 )
{
if ( ! F_28 ( V_71 ) )
return 0 ;
return F_25 ( 8 * V_235 -> V_206 * 1000 , V_235 -> V_195 ) ;
}
static void F_151 ( struct V_70 * V_71 ,
struct V_321 * V_210 ,
struct V_355 * V_363 )
{
struct V_124 * V_124 = F_31 ( V_71 ) ;
int V_40 ;
if ( ! V_210 -> V_215 )
return;
for ( V_40 = 0 ; V_40 < F_138 ( V_124 ) ; V_40 ++ )
V_363 -> V_357 [ V_40 ] = false ;
V_363 -> V_360 = false ;
}
static void F_152 ( struct V_70 * V_71 ,
struct V_331 * V_332 ,
struct V_321 * V_210 ,
struct V_364 * V_270 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_31 ( V_71 ) ;
int V_220 , V_243 = F_88 ( V_2 ) ;
for ( V_220 = 0 ; V_220 <= V_243 ; V_220 ++ ) {
F_149 ( V_4 , V_332 , V_210 , V_124 -> V_125 ,
V_220 , F_138 ( V_124 ) ,
& V_270 -> V_60 [ V_220 ] ) ;
}
V_270 -> V_241 = F_150 ( V_71 , V_210 ) ;
F_151 ( V_71 , V_210 , & V_270 -> V_363 ) ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_321 * V_235 ,
struct V_364 * V_365 ,
struct V_366 * V_281 ,
struct V_124 * V_124 )
{
int V_220 , V_243 = F_88 ( V_2 ) ;
enum V_125 V_125 = V_124 -> V_125 ;
T_3 V_367 ;
int V_40 ;
for ( V_220 = 0 ; V_220 <= V_243 ; V_220 ++ ) {
for ( V_40 = 0 ; V_40 < F_138 ( V_124 ) ; V_40 ++ ) {
V_367 = 0 ;
V_367 |= V_365 -> V_60 [ V_220 ] . V_359 [ V_40 ] <<
V_368 ;
V_367 |= V_365 -> V_60 [ V_220 ] . V_358 [ V_40 ] ;
if ( V_365 -> V_60 [ V_220 ] . V_357 [ V_40 ] )
V_367 |= V_369 ;
V_281 -> V_52 [ V_125 ] [ V_40 ] [ V_220 ] = V_367 ;
}
V_367 = 0 ;
V_367 |= V_365 -> V_60 [ V_220 ] . V_362 << V_368 ;
V_367 |= V_365 -> V_60 [ V_220 ] . V_361 ;
if ( V_365 -> V_60 [ V_220 ] . V_360 )
V_367 |= V_369 ;
V_281 -> V_101 [ V_125 ] [ V_220 ] = V_367 ;
}
for ( V_40 = 0 ; V_40 < F_138 ( V_124 ) ; V_40 ++ ) {
V_367 = 0 ;
V_367 |= V_365 -> V_363 . V_359 [ V_40 ] << V_368 ;
V_367 |= V_365 -> V_363 . V_358 [ V_40 ] ;
if ( V_365 -> V_363 . V_357 [ V_40 ] )
V_367 |= V_369 ;
V_281 -> V_370 [ V_125 ] [ V_40 ] = V_367 ;
}
V_367 = 0 ;
V_367 |= V_365 -> V_363 . V_362 << V_368 ;
V_367 |= V_365 -> V_363 . V_361 ;
if ( V_365 -> V_363 . V_360 )
V_367 |= V_369 ;
V_281 -> V_371 [ V_125 ] = V_367 ;
V_281 -> V_289 [ V_125 ] = V_365 -> V_241 ;
}
static void F_154 ( struct V_3 * V_4 , T_3 V_74 ,
const struct V_322 * V_330 )
{
if ( V_330 -> V_328 )
F_2 ( V_74 , ( V_330 -> V_328 - 1 ) << 16 | V_330 -> V_327 ) ;
else
F_2 ( V_74 , 0 ) ;
}
static void F_155 ( struct V_3 * V_4 ,
const struct V_366 * V_298 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_124 * V_71 ;
F_146 (crtc, &dev->mode_config.crtc_list, base.head) {
int V_40 , V_220 , V_243 = F_88 ( V_2 ) ;
enum V_125 V_125 = V_71 -> V_125 ;
if ( ! V_298 -> V_299 [ V_125 ] )
continue;
F_2 ( F_127 ( V_125 ) , V_298 -> V_289 [ V_125 ] ) ;
for ( V_220 = 0 ; V_220 <= V_243 ; V_220 ++ ) {
for ( V_40 = 0 ; V_40 < F_138 ( V_71 ) ; V_40 ++ )
F_2 ( F_156 ( V_125 , V_40 , V_220 ) ,
V_298 -> V_52 [ V_125 ] [ V_40 ] [ V_220 ] ) ;
F_2 ( F_157 ( V_125 , V_220 ) ,
V_298 -> V_101 [ V_125 ] [ V_220 ] ) ;
}
for ( V_40 = 0 ; V_40 < F_138 ( V_71 ) ; V_40 ++ )
F_2 ( F_158 ( V_125 , V_40 ) ,
V_298 -> V_370 [ V_125 ] [ V_40 ] ) ;
F_2 ( F_159 ( V_125 ) , V_298 -> V_371 [ V_125 ] ) ;
for ( V_40 = 0 ; V_40 < F_138 ( V_71 ) ; V_40 ++ )
F_154 ( V_4 ,
F_134 ( V_125 , V_40 ) ,
& V_298 -> V_332 . V_52 [ V_125 ] [ V_40 ] ) ;
F_154 ( V_4 , F_135 ( V_125 ) ,
& V_298 -> V_332 . V_101 [ V_125 ] ) ;
}
}
static void
F_160 ( struct V_3 * V_4 , enum V_125 V_125 , int V_372 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_52 ;
F_11 ( L_44 , F_161 ( V_125 ) , V_372 ) ;
F_133 (pipe, plane) {
F_2 ( F_162 ( V_125 , V_52 ) ,
F_3 ( F_162 ( V_125 , V_52 ) ) ) ;
}
F_2 ( F_163 ( V_125 ) , F_3 ( F_163 ( V_125 ) ) ) ;
}
static bool
F_164 ( const struct V_331 * V_297 ,
const struct V_331 * V_298 ,
enum V_125 V_125 )
{
T_6 V_373 , V_374 ;
V_373 = F_140 ( & V_297 -> V_125 [ V_125 ] ) ;
V_374 = F_140 ( & V_298 -> V_125 [ V_125 ] ) ;
return V_373 != V_374 &&
V_298 -> V_125 [ V_125 ] . V_327 >= V_297 -> V_125 [ V_125 ] . V_327 &&
V_298 -> V_125 [ V_125 ] . V_328 <= V_297 -> V_125 [ V_125 ] . V_328 ;
}
static void F_165 ( struct V_3 * V_4 ,
struct V_366 * V_375 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_331 * V_344 , * V_343 ;
bool V_376 [ V_377 ] = { false , false , false } ;
struct V_124 * V_71 ;
enum V_125 V_125 ;
V_343 = & V_375 -> V_332 ;
V_344 = & V_4 -> V_60 . V_345 . V_332 ;
F_109 (dev, crtc) {
if ( ! V_71 -> V_215 )
continue;
V_125 = V_71 -> V_125 ;
if ( ! F_164 ( V_344 , V_343 , V_125 ) )
continue;
F_160 ( V_4 , V_125 , 1 ) ;
F_166 ( V_2 , V_125 ) ;
V_376 [ V_125 ] = true ;
}
F_109 (dev, crtc) {
if ( ! V_71 -> V_215 )
continue;
V_125 = V_71 -> V_125 ;
if ( V_376 [ V_125 ] )
continue;
if ( F_140 ( & V_343 -> V_125 [ V_125 ] ) <
F_140 ( & V_344 -> V_125 [ V_125 ] ) ) {
F_160 ( V_4 , V_125 , 2 ) ;
F_166 ( V_2 , V_125 ) ;
V_376 [ V_125 ] = true ;
}
}
F_109 (dev, crtc) {
if ( ! V_71 -> V_215 )
continue;
V_125 = V_71 -> V_125 ;
if ( V_376 [ V_125 ] )
continue;
F_160 ( V_4 , V_125 , 3 ) ;
}
}
static bool F_167 ( struct V_70 * V_71 ,
struct V_321 * V_210 ,
struct V_222 * V_80 ,
struct V_331 * V_332 ,
struct V_364 * V_270 )
{
struct V_124 * V_124 = F_31 ( V_71 ) ;
F_147 ( V_71 , V_210 ) ;
F_139 ( V_71 , V_80 , V_210 , V_332 ) ;
F_152 ( V_71 , V_332 , V_210 , V_270 ) ;
if ( ! memcmp ( & V_124 -> V_60 . V_378 , V_270 , sizeof( * V_270 ) ) )
return false ;
V_124 -> V_60 . V_378 = * V_270 ;
return true ;
}
static void F_168 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
struct V_222 * V_80 ,
struct V_366 * V_281 )
{
struct V_124 * V_124 ;
struct V_124 * V_379 = F_31 ( V_71 ) ;
if ( ! F_144 ( & V_281 -> V_332 , V_379 ) )
return;
F_146 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
struct V_321 V_210 = {} ;
struct V_364 V_270 = {} ;
bool V_380 ;
if ( V_379 -> V_125 == V_124 -> V_125 )
continue;
if ( ! V_124 -> V_215 )
continue;
V_380 = F_167 ( & V_124 -> V_81 ,
& V_210 , V_80 ,
& V_281 -> V_332 , & V_270 ) ;
F_118 ( ! V_380 ) ;
F_153 ( V_2 , & V_210 , & V_270 , V_281 , V_124 ) ;
V_281 -> V_299 [ V_124 -> V_125 ] = true ;
}
}
static void F_169 ( struct V_70 * V_71 )
{
struct V_124 * V_124 = F_31 ( V_71 ) ;
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_321 V_210 = {} ;
struct V_366 * V_279 = & V_4 -> V_60 . V_381 ;
struct V_364 V_270 = {} ;
struct V_222 V_80 = {} ;
memset ( V_279 , 0 , sizeof( * V_279 ) ) ;
F_145 ( V_2 , & V_80 ) ;
if ( ! F_167 ( V_71 , & V_210 , & V_80 ,
& V_279 -> V_332 , & V_270 ) )
return;
F_153 ( V_2 , & V_210 , & V_270 , V_279 , V_124 ) ;
V_279 -> V_299 [ V_124 -> V_125 ] = true ;
F_168 ( V_2 , V_71 , & V_80 , V_279 ) ;
F_155 ( V_4 , V_279 ) ;
F_165 ( V_4 , V_279 ) ;
V_4 -> V_60 . V_345 = * V_279 ;
}
static void
F_170 ( struct V_163 * V_52 , struct V_70 * V_71 ,
T_3 V_164 , T_3 V_165 ,
int V_62 , bool V_72 , bool V_166 )
{
struct V_266 * V_266 = F_48 ( V_52 ) ;
V_266 -> V_60 . V_72 = V_72 ;
V_266 -> V_60 . V_166 = V_166 ;
V_266 -> V_60 . V_207 = V_164 ;
V_266 -> V_60 . V_334 = V_165 ;
V_266 -> V_60 . V_203 = V_62 ;
F_169 ( V_71 ) ;
}
static void F_171 ( struct V_70 * V_71 )
{
struct V_124 * V_124 = F_31 ( V_71 ) ;
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_229 F_34 ;
struct V_209 V_210 = {} ;
struct V_278 V_279 = {} ;
enum V_223 V_277 ;
struct V_267 V_270 = {} ;
struct V_267 V_382 = {} , V_383 = {} , * V_384 ;
struct V_222 V_80 = {} ;
F_106 ( V_71 , & V_210 ) ;
F_110 ( V_71 , & V_210 , & V_270 ) ;
if ( ! memcmp ( & V_124 -> V_60 . V_215 , & V_270 , sizeof( V_270 ) ) )
return;
V_124 -> V_60 . V_215 = V_270 ;
F_108 ( V_2 , & V_80 ) ;
F_76 ( V_2 , 1 , & V_80 , V_271 , & F_34 ) ;
F_112 ( V_2 , & V_80 , & F_34 , & V_382 ) ;
if ( F_70 ( V_2 ) -> V_219 >= 7 &&
V_80 . V_226 == 1 && V_80 . V_225 ) {
F_76 ( V_2 , 1 , & V_80 , V_228 , & F_34 ) ;
F_112 ( V_2 , & V_80 , & F_34 , & V_383 ) ;
V_384 = F_119 ( V_2 , & V_382 , & V_383 ) ;
} else {
V_384 = & V_382 ;
}
V_277 = ( V_384 == & V_382 ) ?
V_271 : V_228 ;
F_117 ( V_2 , V_384 , V_277 , & V_279 ) ;
F_126 ( V_4 , & V_279 ) ;
}
static void
F_172 ( struct V_163 * V_52 ,
struct V_70 * V_71 ,
T_3 V_164 , T_3 V_165 ,
int V_62 , bool V_72 , bool V_166 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_266 * V_266 = F_48 ( V_52 ) ;
V_266 -> V_60 . V_72 = V_72 ;
V_266 -> V_60 . V_166 = V_166 ;
V_266 -> V_60 . V_207 = V_164 ;
V_266 -> V_60 . V_334 = V_164 ;
V_266 -> V_60 . V_203 = V_62 ;
if ( F_98 ( V_2 ) && V_166 && F_128 ( V_2 ) )
F_166 ( V_2 , V_266 -> V_125 ) ;
F_171 ( V_71 ) ;
}
static void F_173 ( T_3 V_43 ,
struct V_364 * V_215 ,
bool V_385 ,
bool V_386 ,
int V_40 ,
int V_220 )
{
bool V_387 = ( V_43 & V_369 ) != 0 ;
if ( ! V_385 ) {
if ( ! V_386 ) {
V_215 -> V_60 [ V_220 ] . V_357 [ V_40 ] = V_387 ;
V_215 -> V_60 [ V_220 ] . V_358 [ V_40 ] =
V_43 & V_388 ;
V_215 -> V_60 [ V_220 ] . V_359 [ V_40 ] =
( V_43 >> V_368 ) &
V_389 ;
} else {
V_215 -> V_60 [ V_220 ] . V_360 = V_387 ;
V_215 -> V_60 [ V_220 ] . V_361 =
V_43 & V_388 ;
V_215 -> V_60 [ V_220 ] . V_362 =
( V_43 >> V_368 ) &
V_389 ;
}
} else {
if ( ! V_386 ) {
V_215 -> V_363 . V_357 [ V_40 ] = V_387 ;
V_215 -> V_363 . V_358 [ V_40 ] =
V_43 & V_388 ;
V_215 -> V_363 . V_359 [ V_40 ] =
( V_43 >> V_368 ) &
V_389 ;
} else {
V_215 -> V_363 . V_360 = V_387 ;
V_215 -> V_363 . V_361 =
V_43 & V_388 ;
V_215 -> V_363 . V_362 =
( V_43 >> V_368 ) &
V_389 ;
}
}
}
static void F_174 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_366 * V_304 = & V_4 -> V_60 . V_345 ;
struct V_124 * V_124 = F_31 ( V_71 ) ;
struct V_364 * V_215 = & V_124 -> V_60 . V_378 ;
enum V_125 V_125 = V_124 -> V_125 ;
int V_220 , V_40 , V_243 ;
T_3 V_367 ;
V_243 = F_88 ( V_2 ) ;
V_304 -> V_289 [ V_125 ] = F_3 ( F_127 ( V_125 ) ) ;
for ( V_220 = 0 ; V_220 <= V_243 ; V_220 ++ ) {
for ( V_40 = 0 ; V_40 < F_138 ( V_124 ) ; V_40 ++ )
V_304 -> V_52 [ V_125 ] [ V_40 ] [ V_220 ] =
F_3 ( F_156 ( V_125 , V_40 , V_220 ) ) ;
V_304 -> V_101 [ V_125 ] [ V_220 ] = F_3 ( F_157 ( V_125 , V_220 ) ) ;
}
for ( V_40 = 0 ; V_40 < F_138 ( V_124 ) ; V_40 ++ )
V_304 -> V_370 [ V_125 ] [ V_40 ] = F_3 ( F_158 ( V_125 , V_40 ) ) ;
V_304 -> V_371 [ V_125 ] = F_3 ( F_159 ( V_125 ) ) ;
if ( ! F_28 ( V_71 ) )
return;
V_304 -> V_299 [ V_125 ] = true ;
V_215 -> V_241 = V_304 -> V_289 [ V_125 ] ;
for ( V_220 = 0 ; V_220 <= V_243 ; V_220 ++ ) {
for ( V_40 = 0 ; V_40 < F_138 ( V_124 ) ; V_40 ++ ) {
V_367 = V_304 -> V_52 [ V_125 ] [ V_40 ] [ V_220 ] ;
F_173 ( V_367 , V_215 , false ,
false , V_40 , V_220 ) ;
}
V_367 = V_304 -> V_101 [ V_125 ] [ V_220 ] ;
F_173 ( V_367 , V_215 , false , true , V_40 , V_220 ) ;
}
for ( V_40 = 0 ; V_40 < F_138 ( V_124 ) ; V_40 ++ ) {
V_367 = V_304 -> V_370 [ V_125 ] [ V_40 ] ;
F_173 ( V_367 , V_215 , true , false , V_40 , 0 ) ;
}
V_367 = V_304 -> V_371 [ V_125 ] ;
F_173 ( V_367 , V_215 , true , true , V_40 , 0 ) ;
}
void F_175 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_331 * V_332 = & V_4 -> V_60 . V_345 . V_332 ;
struct V_70 * V_71 ;
F_132 ( V_4 , V_332 ) ;
F_146 (crtc, &dev->mode_config.crtc_list, head)
F_174 ( V_71 ) ;
}
static void F_176 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_278 * V_304 = & V_4 -> V_60 . V_304 ;
struct V_124 * V_124 = F_31 ( V_71 ) ;
struct V_267 * V_215 = & V_124 -> V_60 . V_215 ;
enum V_125 V_125 = V_124 -> V_125 ;
static const unsigned int V_390 [] = {
[ V_144 ] = V_308 ,
[ V_148 ] = V_309 ,
[ V_157 ] = V_310 ,
} ;
V_304 -> V_290 [ V_125 ] = F_3 ( V_390 [ V_125 ] ) ;
if ( F_93 ( V_2 ) || F_94 ( V_2 ) )
V_304 -> V_289 [ V_125 ] = F_3 ( F_127 ( V_125 ) ) ;
V_215 -> V_268 = F_28 ( V_71 ) ;
if ( V_215 -> V_268 ) {
T_1 V_12 = V_304 -> V_290 [ V_125 ] ;
V_215 -> V_60 [ 0 ] . V_42 = true ;
V_215 -> V_60 [ 0 ] . V_208 = ( V_12 & V_391 ) >> V_291 ;
V_215 -> V_60 [ 0 ] . V_233 = ( V_12 & V_392 ) >> V_292 ;
V_215 -> V_60 [ 0 ] . V_234 = V_12 & V_393 ;
V_215 -> V_241 = V_304 -> V_289 [ V_125 ] ;
} else {
int V_220 , V_243 = F_88 ( V_2 ) ;
for ( V_220 = 0 ; V_220 <= V_243 ; V_220 ++ )
V_215 -> V_60 [ V_220 ] . V_42 = true ;
}
}
void F_177 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_278 * V_304 = & V_4 -> V_60 . V_304 ;
struct V_70 * V_71 ;
F_27 (dev, crtc)
F_176 ( V_71 ) ;
V_304 -> V_276 [ 0 ] = F_3 ( V_307 ) ;
V_304 -> V_276 [ 1 ] = F_3 ( V_306 ) ;
V_304 -> V_276 [ 2 ] = F_3 ( V_305 ) ;
V_304 -> V_287 [ 0 ] = F_3 ( V_317 ) ;
if ( F_70 ( V_2 ) -> V_219 >= 7 ) {
V_304 -> V_287 [ 1 ] = F_3 ( V_318 ) ;
V_304 -> V_287 [ 2 ] = F_3 ( V_319 ) ;
}
if ( F_93 ( V_2 ) || F_94 ( V_2 ) )
V_304 -> V_277 = ( F_3 ( V_311 ) & V_312 ) ?
V_228 : V_271 ;
else if ( F_98 ( V_2 ) )
V_304 -> V_277 = ( F_3 ( V_313 ) & V_314 ) ?
V_228 : V_271 ;
V_304 -> V_280 =
! ( F_3 ( V_315 ) & V_316 ) ;
}
void F_178 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = V_71 -> V_2 -> V_5 ;
if ( V_4 -> V_99 . V_394 )
V_4 -> V_99 . V_394 ( V_71 ) ;
}
void F_179 ( struct V_163 * V_52 ,
struct V_70 * V_71 ,
T_3 V_164 ,
T_3 V_165 ,
int V_62 ,
bool V_72 , bool V_166 )
{
struct V_3 * V_4 = V_52 -> V_2 -> V_5 ;
if ( V_4 -> V_99 . V_395 )
V_4 -> V_99 . V_395 ( V_52 , V_71 ,
V_164 , V_165 ,
V_62 , V_72 , V_166 ) ;
}
static struct V_187 *
F_180 ( struct V_1 * V_2 )
{
struct V_187 * V_396 ;
int V_204 ;
F_118 ( ! F_181 ( & V_2 -> V_397 ) ) ;
V_396 = F_182 ( V_2 , 4096 ) ;
if ( ! V_396 ) {
F_183 ( L_45 ) ;
return NULL ;
}
V_204 = F_184 ( V_396 , 4096 , 0 ) ;
if ( V_204 ) {
F_92 ( L_46 , V_204 ) ;
goto V_398;
}
V_204 = F_185 ( V_396 , 1 ) ;
if ( V_204 ) {
F_92 ( L_47 , V_204 ) ;
goto V_399;
}
return V_396 ;
V_399:
F_186 ( V_396 ) ;
V_398:
F_187 ( & V_396 -> V_81 ) ;
return NULL ;
}
bool F_188 ( struct V_1 * V_2 , T_7 V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_400 ;
F_189 ( & V_401 ) ;
V_400 = F_7 ( V_402 ) ;
if ( V_400 & V_403 ) {
F_183 ( L_48 ) ;
return false ;
}
V_400 = ( V_404 << V_405 ) |
( V_43 << V_406 ) | V_407 ;
F_190 ( V_402 , V_400 ) ;
F_191 ( V_402 ) ;
V_400 |= V_403 ;
F_190 ( V_402 , V_400 ) ;
return true ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_408 = F_3 ( V_409 ) ;
T_7 V_410 , V_411 , V_412 , V_413 ;
F_193 ( & V_401 ) ;
F_190 ( V_414 , F_3 ( V_414 ) | V_415 ) ;
F_190 ( V_416 , F_3 ( V_416 ) | V_417 ) ;
F_2 ( V_418 , 100000 ) ;
F_2 ( V_419 , 100000 ) ;
F_2 ( V_420 , 90000 ) ;
F_2 ( V_421 , 80000 ) ;
F_2 ( V_422 , 1 ) ;
V_410 = ( V_408 & V_423 ) >> V_424 ;
V_411 = ( V_408 & V_425 ) ;
V_412 = ( V_408 & V_426 ) >>
V_427 ;
V_413 = ( F_3 ( V_428 + ( V_412 * 4 ) ) & V_429 ) >>
V_430 ;
V_4 -> V_32 . V_410 = V_410 ;
V_4 -> V_32 . V_412 = V_412 ;
V_4 -> V_32 . V_431 = V_412 ;
V_4 -> V_32 . V_432 = V_411 ;
V_4 -> V_32 . V_433 = V_412 ;
F_8 ( L_49 ,
V_410 , V_411 , V_412 ) ;
F_2 ( V_434 , V_435 | V_436 ) ;
F_2 ( V_437 , V_413 ) ;
F_194 ( V_437 ) ;
V_408 |= V_438 ;
F_2 ( V_409 , V_408 ) ;
if ( F_195 ( ( F_3 ( V_402 ) & V_403 ) == 0 , 10 ) )
F_92 ( L_50 ) ;
F_196 ( 1 ) ;
F_188 ( V_2 , V_412 ) ;
V_4 -> V_32 . V_439 = F_3 ( 0x112e4 ) + F_3 ( 0x112e8 ) +
F_3 ( 0x112e0 ) ;
V_4 -> V_32 . V_440 = F_197 ( V_441 ) ;
V_4 -> V_32 . V_442 = F_3 ( 0x112f4 ) ;
V_4 -> V_32 . V_443 = F_198 () ;
F_199 ( & V_401 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_400 ;
F_193 ( & V_401 ) ;
V_400 = F_7 ( V_402 ) ;
F_2 ( V_434 , F_3 ( V_434 ) & ~ V_436 ) ;
F_2 ( V_444 , V_445 ) ;
F_2 ( V_446 , F_3 ( V_446 ) & ~ V_447 ) ;
F_2 ( V_448 , V_447 ) ;
F_2 ( V_449 , F_3 ( V_449 ) | V_447 ) ;
F_188 ( V_2 , V_4 -> V_32 . V_412 ) ;
F_196 ( 1 ) ;
V_400 |= V_403 ;
F_2 ( V_402 , V_400 ) ;
F_196 ( 1 ) ;
F_199 ( & V_401 ) ;
}
static T_1 F_201 ( struct V_3 * V_4 , T_7 V_43 )
{
T_1 V_450 ;
V_450 = V_4 -> V_244 . V_451 << 24 ;
if ( V_43 <= V_4 -> V_244 . V_452 )
V_450 |= V_4 -> V_244 . V_452 << 16 ;
return V_450 ;
}
static void F_202 ( struct V_3 * V_4 , T_7 V_43 )
{
int V_453 ;
V_453 = V_4 -> V_244 . V_454 ;
switch ( V_4 -> V_244 . V_454 ) {
case V_455 :
if ( V_43 > V_4 -> V_244 . V_456 + 1 && V_43 > V_4 -> V_244 . V_457 )
V_453 = V_458 ;
break;
case V_458 :
if ( V_43 <= V_4 -> V_244 . V_456 && V_43 < V_4 -> V_244 . V_457 )
V_453 = V_455 ;
else if ( V_43 >= V_4 -> V_244 . V_459 && V_43 > V_4 -> V_244 . V_457 )
V_453 = V_460 ;
break;
case V_460 :
if ( V_43 < ( V_4 -> V_244 . V_461 + V_4 -> V_244 . V_459 ) > > 1 && V_43 < V_4 -> V_244 . V_457 )
V_453 = V_458 ;
break;
}
if ( V_43 == V_4 -> V_244 . V_452 )
V_453 = V_455 ;
if ( V_43 == V_4 -> V_244 . V_451 )
V_453 = V_460 ;
if ( V_453 == V_4 -> V_244 . V_454 )
return;
switch ( V_453 ) {
case V_455 :
F_2 ( V_462 , 12500 ) ;
F_2 ( V_463 , 11800 ) ;
F_2 ( V_464 , 25000 ) ;
F_2 ( V_465 , 21250 ) ;
F_2 ( V_466 ,
V_467 |
V_468 |
V_469 |
V_470 |
V_471 |
V_472 ) ;
break;
case V_458 :
F_2 ( V_462 , 10250 ) ;
F_2 ( V_463 , 9225 ) ;
F_2 ( V_464 , 25000 ) ;
F_2 ( V_465 , 18750 ) ;
F_2 ( V_466 ,
V_467 |
V_468 |
V_469 |
V_470 |
V_471 |
V_472 ) ;
break;
case V_460 :
F_2 ( V_462 , 8000 ) ;
F_2 ( V_463 , 6800 ) ;
F_2 ( V_464 , 25000 ) ;
F_2 ( V_465 , 15000 ) ;
F_2 ( V_466 ,
V_467 |
V_468 |
V_469 |
V_470 |
V_471 |
V_472 ) ;
break;
}
V_4 -> V_244 . V_454 = V_453 ;
V_4 -> V_244 . V_473 = 0 ;
}
static T_1 F_203 ( struct V_3 * V_4 , T_7 V_43 )
{
T_1 V_474 = 0 ;
if ( V_43 > V_4 -> V_244 . V_452 )
V_474 |= V_475 | V_476 ;
if ( V_43 < V_4 -> V_244 . V_451 )
V_474 |= V_477 ;
V_474 |= V_4 -> V_478 & ( V_479 | V_480 ) ;
V_474 &= V_4 -> V_478 ;
return F_204 ( V_4 , ~ V_474 ) ;
}
void F_205 ( struct V_1 * V_2 , T_7 V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_118 ( ! F_181 ( & V_4 -> V_244 . V_245 ) ) ;
F_118 ( V_43 > V_4 -> V_244 . V_451 ) ;
F_118 ( V_43 < V_4 -> V_244 . V_452 ) ;
if ( V_43 != V_4 -> V_244 . V_457 ) {
F_202 ( V_4 , V_43 ) ;
if ( F_93 ( V_2 ) || F_94 ( V_2 ) )
F_2 ( V_481 ,
F_206 ( V_43 ) ) ;
else
F_2 ( V_481 ,
F_207 ( V_43 ) |
F_208 ( 0 ) |
V_482 ) ;
}
F_2 ( V_483 , F_201 ( V_4 , V_43 ) ) ;
F_2 ( V_484 , F_203 ( V_4 , V_43 ) ) ;
F_194 ( V_481 ) ;
V_4 -> V_244 . V_457 = V_43 ;
F_209 ( V_43 * 50 ) ;
}
static void F_210 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_40 ( V_2 ) || V_2 -> V_485 -> V_486 >= 0xd ) {
F_211 ( V_4 -> V_2 , V_4 -> V_244 . V_452 ) ;
return;
}
if ( V_4 -> V_244 . V_457 <= V_4 -> V_244 . V_452 )
return;
F_2 ( V_484 ,
F_204 ( V_4 , ~ 0 ) ) ;
F_212 ( V_4 , true ) ;
V_4 -> V_244 . V_457 = V_4 -> V_244 . V_452 ;
F_213 ( V_4 , V_487 ,
V_4 -> V_244 . V_452 ) ;
if ( F_214 ( ( ( F_215 ( V_4 , V_488 ) )
& V_489 ) == 0 , 100 ) )
F_92 ( L_51 ) ;
F_212 ( V_4 , false ) ;
F_2 ( V_484 ,
F_203 ( V_4 , V_4 -> V_244 . V_457 ) ) ;
}
void F_216 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_89 ( & V_4 -> V_244 . V_245 ) ;
if ( V_4 -> V_244 . V_72 ) {
if ( F_13 ( V_2 ) )
F_210 ( V_4 ) ;
else
F_205 ( V_4 -> V_2 , V_4 -> V_244 . V_452 ) ;
V_4 -> V_244 . V_473 = 0 ;
}
F_91 ( & V_4 -> V_244 . V_245 ) ;
}
void F_217 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_89 ( & V_4 -> V_244 . V_245 ) ;
if ( V_4 -> V_244 . V_72 ) {
if ( F_13 ( V_2 ) )
F_211 ( V_4 -> V_2 , V_4 -> V_244 . V_451 ) ;
else
F_205 ( V_4 -> V_2 , V_4 -> V_244 . V_451 ) ;
V_4 -> V_244 . V_473 = 0 ;
}
F_91 ( & V_4 -> V_244 . V_245 ) ;
}
void F_211 ( struct V_1 * V_2 , T_7 V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_118 ( ! F_181 ( & V_4 -> V_244 . V_245 ) ) ;
F_118 ( V_43 > V_4 -> V_244 . V_451 ) ;
F_118 ( V_43 < V_4 -> V_244 . V_452 ) ;
if ( F_218 ( F_40 ( V_2 ) && ( V_43 & 1 ) ,
L_52 ) )
V_43 &= ~ 1 ;
if ( V_43 != V_4 -> V_244 . V_457 )
F_213 ( V_4 , V_487 , V_43 ) ;
F_2 ( V_484 , F_203 ( V_4 , V_43 ) ) ;
V_4 -> V_244 . V_457 = V_43 ;
F_209 ( F_219 ( V_4 , V_43 ) ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_490 , 0 ) ;
F_2 ( V_491 , 0 ) ;
}
static void F_221 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_490 , 0 ) ;
F_2 ( V_481 , 1 << 31 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_490 , 0 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_224 ( V_4 , V_492 ) ;
F_2 ( V_490 , 0 ) ;
F_225 ( V_4 , V_492 ) ;
}
static void F_226 ( struct V_1 * V_2 , T_1 V_240 )
{
if ( F_13 ( V_2 ) ) {
if ( V_240 & ( V_493 | F_227 ( 1 ) ) )
V_240 = V_494 ;
else
V_240 = 0 ;
}
if ( F_228 ( V_2 ) )
F_11 ( L_53 ,
( V_240 & V_494 ) ? L_54 : L_55 ,
( V_240 & V_495 ) ? L_54 : L_55 ,
( V_240 & V_496 ) ? L_54 : L_55 ) ;
else
F_11 ( L_56 ,
( V_240 & V_494 ) ? L_54 : L_55 ) ;
}
static int F_229 ( const struct V_1 * V_2 , int V_497 )
{
if ( F_70 ( V_2 ) -> V_219 < 5 )
return 0 ;
if ( F_70 ( V_2 ) -> V_219 == 5 && ! F_230 ( V_2 ) )
return 0 ;
if ( V_497 >= 0 ) {
int V_474 ;
if ( F_228 ( V_2 ) )
V_474 = V_498 | V_499 |
V_500 ;
else
V_474 = V_498 ;
if ( ( V_497 & V_474 ) != V_497 )
F_11 ( L_57 ,
V_497 & V_474 , V_497 , V_474 ) ;
return V_497 & V_474 ;
}
if ( F_70 ( V_2 ) -> V_219 == 5 )
return 0 ;
if ( F_98 ( V_2 ) )
return ( V_498 | V_499 ) ;
return V_498 ;
}
int F_231 ( const struct V_1 * V_2 )
{
return V_501 . V_497 ;
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_502 ;
T_1 V_503 = 0 ;
int V_204 ;
V_502 = F_3 ( V_504 ) ;
V_4 -> V_244 . V_457 = 0 ;
V_4 -> V_244 . V_459 = ( V_502 >> 0 ) & 0xff ;
V_4 -> V_244 . V_461 = ( V_502 >> 8 ) & 0xff ;
V_4 -> V_244 . V_505 = ( V_502 >> 16 ) & 0xff ;
V_4 -> V_244 . V_506 = V_4 -> V_244 . V_459 ;
V_4 -> V_244 . V_456 = V_4 -> V_244 . V_461 ;
if ( F_93 ( V_2 ) || F_94 ( V_2 ) ) {
V_204 = F_90 ( V_4 ,
V_507 ,
& V_503 ) ;
if ( 0 == V_204 )
V_4 -> V_244 . V_456 =
F_233 ( T_7 ,
( ( V_503 >> 8 ) & 0xff ) ,
V_4 -> V_244 . V_505 ,
V_4 -> V_244 . V_506 ) ;
}
if ( V_4 -> V_244 . V_451 == 0 )
V_4 -> V_244 . V_451 = V_4 -> V_244 . V_506 ;
if ( V_4 -> V_244 . V_452 == 0 ) {
if ( F_93 ( V_2 ) || F_94 ( V_2 ) )
V_4 -> V_244 . V_452 =
F_34 ( V_4 -> V_244 . V_456 , ( T_7 ) 9 ) ;
else
V_4 -> V_244 . V_452 =
V_4 -> V_244 . V_505 ;
}
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_224 ( V_4 , V_492 ) ;
F_232 ( V_2 ) ;
F_2 ( V_481 , 0xc800000 ) ;
F_2 ( V_508 , 0xc800000 ) ;
F_2 ( V_509 , 0xf4240 ) ;
F_2 ( V_483 , 0x12060000 ) ;
F_2 ( V_463 , 0xe808 ) ;
F_2 ( V_465 , 0x3bd08 ) ;
F_2 ( V_462 , 0x101d0 ) ;
F_2 ( V_464 , 0x55730 ) ;
F_2 ( V_510 , 0xa ) ;
F_2 ( V_484 , 0x6 ) ;
F_2 ( V_466 , V_467 |
V_511 | V_469 |
V_470 | V_471 |
V_472 ) ;
F_235 ( V_2 ) ;
F_225 ( V_4 , V_492 ) ;
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_512 * V_513 ;
T_3 V_514 = 0 ;
int V_515 ;
F_2 ( V_516 , 0 ) ;
F_224 ( V_4 , V_492 ) ;
F_2 ( V_490 , 0 ) ;
F_2 ( V_517 , 54 << 16 ) ;
F_2 ( V_518 , 125000 ) ;
F_2 ( V_519 , 25 ) ;
F_237 (ring, dev_priv, unused)
F_2 ( F_238 ( V_513 -> V_520 ) , 10 ) ;
F_2 ( V_521 , 0 ) ;
F_2 ( V_522 , 37500 ) ;
F_2 ( V_523 , 25 ) ;
F_2 ( V_524 , 25 ) ;
if ( F_231 ( V_2 ) & V_498 )
V_514 = V_494 ;
F_239 ( L_58 , ( V_514 & V_494 ) ?
L_54 : L_55 ) ;
F_2 ( V_490 , V_525 |
F_227 ( 1 ) |
V_514 ) ;
F_2 ( V_491 , ( V_514 & V_494 ) ? 3 : 0 ) ;
F_225 ( V_4 , V_492 ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_512 * V_513 ;
T_3 V_514 = 0 ;
int V_515 ;
F_2 ( V_516 , 0 ) ;
F_224 ( V_4 , V_492 ) ;
F_2 ( V_490 , 0 ) ;
F_232 ( V_2 ) ;
F_2 ( V_517 , 40 << 16 ) ;
F_2 ( V_518 , 125000 ) ;
F_2 ( V_519 , 25 ) ;
F_237 (ring, dev_priv, unused)
F_2 ( F_238 ( V_513 -> V_520 ) , 10 ) ;
F_2 ( V_521 , 0 ) ;
if ( F_94 ( V_2 ) )
F_2 ( V_522 , 625 ) ;
else
F_2 ( V_522 , 50000 ) ;
if ( F_231 ( V_2 ) & V_498 )
V_514 = V_494 ;
F_226 ( V_2 , V_514 ) ;
if ( F_94 ( V_2 ) )
F_2 ( V_490 , V_525 |
V_493 |
V_514 ) ;
else
F_2 ( V_490 , V_525 |
F_227 ( 1 ) |
V_514 ) ;
F_2 ( V_481 ,
F_206 ( V_4 -> V_244 . V_461 ) ) ;
F_2 ( V_508 ,
F_206 ( V_4 -> V_244 . V_461 ) ) ;
F_2 ( V_509 , 100000000 / 128 ) ;
F_2 ( V_483 ,
V_4 -> V_244 . V_451 << 24 |
V_4 -> V_244 . V_452 << 16 ) ;
F_2 ( V_463 , 7600000 / 128 ) ;
F_2 ( V_465 , 31300000 / 128 ) ;
F_2 ( V_462 , 66000 ) ;
F_2 ( V_464 , 350000 ) ;
F_2 ( V_510 , 10 ) ;
F_2 ( V_466 ,
V_467 |
V_468 |
V_469 |
V_470 |
V_471 |
V_472 ) ;
V_4 -> V_244 . V_454 = V_460 ;
F_205 ( V_4 -> V_2 , V_4 -> V_244 . V_452 ) ;
F_225 ( V_4 , V_492 ) ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_512 * V_513 ;
T_1 V_526 , V_527 = 0 , V_514 = 0 ;
T_1 V_528 ;
int V_529 ;
int V_40 , V_204 ;
F_118 ( ! F_181 ( & V_4 -> V_244 . V_245 ) ) ;
F_2 ( V_516 , 0 ) ;
if ( ( V_528 = F_3 ( V_530 ) ) ) {
F_92 ( L_59 , V_528 ) ;
F_2 ( V_530 , V_528 ) ;
}
F_224 ( V_4 , V_492 ) ;
F_232 ( V_2 ) ;
F_2 ( V_490 , 0 ) ;
F_2 ( V_531 , 1000 << 16 ) ;
F_2 ( V_517 , 40 << 16 | 30 ) ;
F_2 ( V_532 , 30 ) ;
F_2 ( V_518 , 125000 ) ;
F_2 ( V_519 , 25 ) ;
F_237 (ring, dev_priv, i)
F_2 ( F_238 ( V_513 -> V_520 ) , 10 ) ;
F_2 ( V_521 , 0 ) ;
F_2 ( V_533 , 1000 ) ;
if ( F_98 ( V_2 ) )
F_2 ( V_522 , 125000 ) ;
else
F_2 ( V_522 , 50000 ) ;
F_2 ( V_534 , 150000 ) ;
F_2 ( V_535 , 64000 ) ;
V_529 = F_231 ( V_4 -> V_2 ) ;
if ( V_529 & V_498 )
V_514 |= V_494 ;
if ( ! F_93 ( V_2 ) ) {
if ( V_529 & V_499 )
V_514 |= V_495 ;
if ( V_529 & V_500 )
V_514 |= V_496 ;
}
F_226 ( V_2 , V_514 ) ;
F_2 ( V_490 ,
V_514 |
F_227 ( 1 ) |
V_525 ) ;
F_2 ( V_509 , 50000 ) ;
F_2 ( V_510 , 10 ) ;
V_204 = F_242 ( V_4 , V_536 , 0 ) ;
if ( V_204 )
F_8 ( L_60 ) ;
V_204 = F_90 ( V_4 , V_537 , & V_527 ) ;
if ( ! V_204 && ( V_527 & ( 1 << 31 ) ) ) {
F_8 ( L_61 ,
( V_4 -> V_244 . V_451 & 0xff ) * 50 ,
( V_527 & 0xff ) * 50 ) ;
V_4 -> V_244 . V_506 = V_527 & 0xff ;
}
V_4 -> V_244 . V_454 = V_460 ;
F_205 ( V_4 -> V_2 , V_4 -> V_244 . V_452 ) ;
V_526 = 0 ;
V_204 = F_90 ( V_4 , V_538 , & V_526 ) ;
if ( F_104 ( V_2 ) && V_204 ) {
F_8 ( L_62 ) ;
} else if ( F_104 ( V_2 ) && ( F_243 ( V_526 & 0xff ) < 450 ) ) {
F_8 ( L_63 ,
F_243 ( V_526 & 0xff ) , 450 ) ;
V_526 &= 0xffff00 ;
V_526 |= F_244 ( 450 ) ;
V_204 = F_242 ( V_4 , V_539 , V_526 ) ;
if ( V_204 )
F_92 ( L_64 ) ;
}
F_225 ( V_4 , V_492 ) ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_505 = 15 ;
unsigned int V_540 ;
unsigned int V_541 , V_542 ;
int V_543 = 180 ;
struct V_544 * V_545 ;
F_118 ( ! F_181 ( & V_4 -> V_244 . V_245 ) ) ;
V_545 = F_246 ( 0 ) ;
if ( V_545 ) {
V_541 = V_545 -> V_546 . V_506 ;
F_247 ( V_545 ) ;
} else {
V_541 = V_547 ;
}
V_541 /= 1000 ;
V_542 = F_3 ( V_548 ) & 0xf ;
V_542 = F_248 ( V_542 , 8 , 3 ) ;
for ( V_540 = V_4 -> V_244 . V_506 ; V_540 >= V_4 -> V_244 . V_505 ;
V_540 -- ) {
int V_549 = V_4 -> V_244 . V_506 - V_540 ;
unsigned int V_550 = 0 , V_551 = 0 ;
if ( F_70 ( V_2 ) -> V_219 >= 8 ) {
V_551 = F_34 ( V_542 , V_540 ) ;
} else if ( F_93 ( V_2 ) ) {
V_551 = F_248 ( V_540 , 5 , 4 ) ;
V_551 = F_34 ( V_542 , V_551 ) ;
} else {
if ( V_540 < V_505 )
V_550 = 800 ;
else
V_550 = V_541 - ( ( V_549 * V_543 ) / 2 ) ;
V_550 = F_82 ( V_550 , 100 ) ;
}
F_242 ( V_4 ,
V_536 ,
V_550 << V_552 |
V_551 << V_553 |
V_540 ) ;
}
}
void F_249 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_70 ( V_2 ) -> V_219 < 6 || F_13 ( V_2 ) )
return;
F_89 ( & V_4 -> V_244 . V_245 ) ;
F_245 ( V_2 ) ;
F_91 ( & V_4 -> V_244 . V_245 ) ;
}
static int F_250 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_43 , V_554 ;
if ( V_2 -> V_485 -> V_486 >= 0x20 ) {
V_43 = F_215 ( V_4 , V_555 ) ;
switch ( F_70 ( V_2 ) -> V_556 ) {
case 8 :
V_554 = ( V_43 >> V_557 ) ;
break;
case 12 :
V_554 = ( V_43 >> V_558 ) ;
break;
case 16 :
default:
V_554 = ( V_43 >> V_559 ) ;
break;
}
V_554 = ( V_554 & V_560 ) ;
} else {
V_43 = F_215 ( V_4 , V_561 ) ;
V_554 = ( V_43 >> V_562 ) &
V_563 ;
}
return V_554 ;
}
static int F_251 ( struct V_3 * V_4 )
{
T_1 V_43 , V_564 ;
V_43 = F_215 ( V_4 , V_565 ) ;
V_564 = ( V_43 >> V_566 ) & V_567 ;
return V_564 ;
}
static int F_252 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_43 , V_568 ;
if ( V_2 -> V_485 -> V_486 >= 0x20 ) {
V_43 = F_215 ( V_4 , V_555 ) ;
V_568 = ( V_43 & V_560 ) ;
} else {
V_43 = F_215 ( V_4 , V_488 ) ;
V_568 = ( ( V_43 >> V_562 ) &
V_563 ) ;
}
return V_568 ;
}
static int F_253 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_43 , V_569 ;
if ( V_2 -> V_485 -> V_486 >= 0x20 ) {
V_43 = F_215 ( V_4 , V_570 ) ;
V_569 = ( ( V_43 >> V_571 ) &
V_560 ) ;
} else {
V_43 = F_215 ( V_4 , V_561 ) ;
V_569 = ( ( V_43 >> V_572 ) &
V_573 ) ;
}
return V_569 ;
}
static int F_254 ( struct V_3 * V_4 )
{
T_1 V_43 , V_568 ;
V_43 = F_255 ( V_4 , V_574 ) ;
V_568 = ( V_43 & V_575 ) >> V_576 ;
return V_568 ;
}
static int F_256 ( struct V_3 * V_4 )
{
T_1 V_43 , V_554 ;
V_43 = F_255 ( V_4 , V_574 ) ;
V_554 = ( V_43 & V_577 ) >> V_578 ;
V_554 = F_79 ( T_1 , V_554 , 0xea ) ;
return V_554 ;
}
static int F_257 ( struct V_3 * V_4 )
{
T_1 V_43 , V_564 ;
V_43 = F_255 ( V_4 , V_579 ) ;
V_564 = ( V_43 & V_580 ) >> V_581 ;
V_43 = F_255 ( V_4 , V_582 ) ;
V_564 |= ( V_43 & V_583 ) << 5 ;
return V_564 ;
}
static int F_258 ( struct V_3 * V_4 )
{
return F_215 ( V_4 , V_584 ) & 0xff ;
}
static void F_259 ( struct V_3 * V_4 )
{
unsigned long V_585 = F_3 ( V_586 ) & ~ 4095 ;
F_118 ( V_585 != V_4 -> V_587 . V_588 +
V_4 -> V_589 -> V_590 -> V_327 ) ;
}
static void F_260 ( struct V_3 * V_4 )
{
unsigned long V_585 = F_3 ( V_586 ) & ~ 4095 ;
F_118 ( ( V_585 >> V_591 ) == 0 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_592 , V_593 ;
struct V_594 * V_595 = & V_4 -> V_595 ;
T_1 V_596 ;
int V_597 = 32 * 1024 ;
F_118 ( ! F_181 ( & V_2 -> V_397 ) ) ;
V_596 = F_3 ( V_586 ) ;
if ( ( V_596 >> V_591 ) == 0 ) {
F_8 ( L_65 ) ;
V_593 = ( V_4 -> V_587 . V_588 +
( V_595 -> V_598 - V_597 ) ) ;
V_592 = ( V_593 & ( ~ 4095 ) ) ;
F_2 ( V_586 , V_592 ) ;
}
F_8 ( L_66 , F_3 ( V_586 ) ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_187 * V_599 ;
unsigned long V_592 ;
T_1 V_596 ;
int V_597 = 24 * 1024 ;
F_118 ( ! F_181 ( & V_2 -> V_397 ) ) ;
V_596 = F_3 ( V_586 ) ;
if ( V_596 ) {
int V_600 ;
V_600 = ( V_596 & ( ~ 4095 ) ) - V_4 -> V_587 . V_588 ;
V_599 = F_263 ( V_4 -> V_2 ,
V_600 ,
V_601 ,
V_597 ) ;
goto V_602;
}
F_8 ( L_65 ) ;
V_599 = F_264 ( V_2 , V_597 ) ;
if ( ! V_599 ) {
F_183 ( L_67 ) ;
return;
}
V_592 = V_4 -> V_587 . V_588 + V_599 -> V_590 -> V_327 ;
F_2 ( V_586 , V_592 ) ;
V_602:
F_8 ( L_66 , F_3 ( V_586 ) ) ;
V_4 -> V_589 = V_599 ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_118 ( ! V_4 -> V_589 ) )
return;
F_187 ( & V_4 -> V_589 -> V_81 ) ;
V_4 -> V_589 = NULL ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_43 ;
F_262 ( V_2 ) ;
F_89 ( & V_4 -> V_244 . V_245 ) ;
V_43 = F_215 ( V_4 , V_488 ) ;
switch ( ( V_43 >> 6 ) & 3 ) {
case 0 :
case 1 :
V_4 -> V_22 = 800 ;
break;
case 2 :
V_4 -> V_22 = 1066 ;
break;
case 3 :
V_4 -> V_22 = 1333 ;
break;
}
F_8 ( L_68 , V_4 -> V_22 ) ;
V_4 -> V_244 . V_506 = F_256 ( V_4 ) ;
V_4 -> V_244 . V_459 = V_4 -> V_244 . V_506 ;
F_8 ( L_69 ,
F_219 ( V_4 , V_4 -> V_244 . V_506 ) ,
V_4 -> V_244 . V_506 ) ;
V_4 -> V_244 . V_456 = F_257 ( V_4 ) ;
F_8 ( L_70 ,
F_219 ( V_4 , V_4 -> V_244 . V_456 ) ,
V_4 -> V_244 . V_456 ) ;
V_4 -> V_244 . V_461 = F_254 ( V_4 ) ;
F_8 ( L_71 ,
F_219 ( V_4 , V_4 -> V_244 . V_461 ) ,
V_4 -> V_244 . V_461 ) ;
V_4 -> V_244 . V_505 = F_258 ( V_4 ) ;
F_8 ( L_72 ,
F_219 ( V_4 , V_4 -> V_244 . V_505 ) ,
V_4 -> V_244 . V_505 ) ;
if ( V_4 -> V_244 . V_451 == 0 )
V_4 -> V_244 . V_451 = V_4 -> V_244 . V_506 ;
if ( V_4 -> V_244 . V_452 == 0 )
V_4 -> V_244 . V_452 = V_4 -> V_244 . V_505 ;
F_91 ( & V_4 -> V_244 . V_245 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_43 ;
F_261 ( V_2 ) ;
F_89 ( & V_4 -> V_244 . V_245 ) ;
F_89 ( & V_4 -> V_603 ) ;
V_43 = F_268 ( V_4 , V_604 ) ;
F_91 ( & V_4 -> V_603 ) ;
switch ( ( V_43 >> 2 ) & 0x7 ) {
case 0 :
case 1 :
V_4 -> V_244 . V_605 = 200 ;
V_4 -> V_22 = 1600 ;
break;
case 2 :
V_4 -> V_244 . V_605 = 267 ;
V_4 -> V_22 = 1600 ;
break;
case 3 :
V_4 -> V_244 . V_605 = 333 ;
V_4 -> V_22 = 2000 ;
break;
case 4 :
V_4 -> V_244 . V_605 = 320 ;
V_4 -> V_22 = 1600 ;
break;
case 5 :
V_4 -> V_244 . V_605 = 400 ;
V_4 -> V_22 = 1600 ;
break;
}
F_8 ( L_68 , V_4 -> V_22 ) ;
V_4 -> V_244 . V_506 = F_250 ( V_4 ) ;
V_4 -> V_244 . V_459 = V_4 -> V_244 . V_506 ;
F_8 ( L_69 ,
F_219 ( V_4 , V_4 -> V_244 . V_506 ) ,
V_4 -> V_244 . V_506 ) ;
V_4 -> V_244 . V_456 = F_251 ( V_4 ) ;
F_8 ( L_70 ,
F_219 ( V_4 , V_4 -> V_244 . V_456 ) ,
V_4 -> V_244 . V_456 ) ;
V_4 -> V_244 . V_461 = F_252 ( V_4 ) ;
F_8 ( L_73 ,
F_219 ( V_4 , V_4 -> V_244 . V_461 ) ,
V_4 -> V_244 . V_461 ) ;
V_4 -> V_244 . V_505 = F_253 ( V_4 ) ;
F_8 ( L_72 ,
F_219 ( V_4 , V_4 -> V_244 . V_505 ) ,
V_4 -> V_244 . V_505 ) ;
F_218 ( ( V_4 -> V_244 . V_506 |
V_4 -> V_244 . V_456 |
V_4 -> V_244 . V_461 |
V_4 -> V_244 . V_505 ) & 1 ,
L_74 ) ;
if ( V_4 -> V_244 . V_451 == 0 )
V_4 -> V_244 . V_451 = V_4 -> V_244 . V_506 ;
if ( V_4 -> V_244 . V_452 == 0 )
V_4 -> V_244 . V_452 = V_4 -> V_244 . V_505 ;
F_91 ( & V_4 -> V_244 . V_245 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
F_265 ( V_2 ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_512 * V_513 ;
T_1 V_528 , V_43 , V_529 = 0 , V_596 ;
int V_40 ;
F_118 ( ! F_181 ( & V_4 -> V_244 . V_245 ) ) ;
V_528 = F_3 ( V_530 ) ;
if ( V_528 ) {
F_8 ( L_59 ,
V_528 ) ;
F_2 ( V_530 , V_528 ) ;
}
F_260 ( V_4 ) ;
F_224 ( V_4 , V_492 ) ;
F_2 ( V_490 , 0 ) ;
F_2 ( V_517 , 40 << 16 ) ;
F_2 ( V_518 , 125000 ) ;
F_2 ( V_519 , 25 ) ;
F_237 (ring, dev_priv, i)
F_2 ( F_238 ( V_513 -> V_520 ) , 10 ) ;
F_2 ( V_521 , 0 ) ;
F_2 ( V_522 , 0x557 ) ;
F_2 ( V_606 ,
F_4 ( V_607 |
V_608 |
V_609 ) ) ;
V_596 = F_3 ( V_586 ) ;
if ( ( F_231 ( V_2 ) & V_498 ) &&
( V_596 >> V_591 ) )
V_529 = V_493 ;
F_2 ( V_490 , V_529 ) ;
F_2 ( V_509 , 1000000 ) ;
F_2 ( V_463 , 59400 ) ;
F_2 ( V_465 , 245000 ) ;
F_2 ( V_462 , 66000 ) ;
F_2 ( V_464 , 350000 ) ;
F_2 ( V_510 , 10 ) ;
F_2 ( V_466 ,
V_468 |
V_469 |
V_470 |
V_471 |
V_472 ) ;
V_43 = F_215 ( V_4 , V_488 ) ;
F_218 ( ( V_43 & V_610 ) == 0 , L_75 ) ;
F_8 ( L_76 , V_43 & V_610 ? L_77 : L_78 ) ;
F_8 ( L_79 , V_43 ) ;
V_4 -> V_244 . V_457 = ( V_43 >> 8 ) & 0xff ;
F_8 ( L_80 ,
F_219 ( V_4 , V_4 -> V_244 . V_457 ) ,
V_4 -> V_244 . V_457 ) ;
F_8 ( L_81 ,
F_219 ( V_4 , V_4 -> V_244 . V_456 ) ,
V_4 -> V_244 . V_456 ) ;
F_211 ( V_4 -> V_2 , V_4 -> V_244 . V_456 ) ;
F_225 ( V_4 , V_492 ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_512 * V_513 ;
T_1 V_528 , V_43 , V_529 = 0 ;
int V_40 ;
F_118 ( ! F_181 ( & V_4 -> V_244 . V_245 ) ) ;
F_259 ( V_4 ) ;
if ( ( V_528 = F_3 ( V_530 ) ) ) {
F_8 ( L_59 ,
V_528 ) ;
F_2 ( V_530 , V_528 ) ;
}
F_224 ( V_4 , V_492 ) ;
F_2 ( V_490 , 0 ) ;
F_2 ( V_509 , 1000000 ) ;
F_2 ( V_463 , 59400 ) ;
F_2 ( V_465 , 245000 ) ;
F_2 ( V_462 , 66000 ) ;
F_2 ( V_464 , 350000 ) ;
F_2 ( V_510 , 10 ) ;
F_2 ( V_466 ,
V_467 |
V_468 |
V_469 |
V_470 |
V_471 |
V_611 ) ;
F_2 ( V_517 , 0x00280000 ) ;
F_2 ( V_518 , 125000 ) ;
F_2 ( V_519 , 25 ) ;
F_237 (ring, dev_priv, i)
F_2 ( F_238 ( V_513 -> V_520 ) , 10 ) ;
F_2 ( V_522 , 0x557 ) ;
F_2 ( V_606 ,
F_4 ( V_612 |
V_613 |
V_608 |
V_609 ) ) ;
if ( F_231 ( V_2 ) & V_498 )
V_529 = V_493 | V_614 ;
F_226 ( V_2 , V_529 ) ;
F_2 ( V_490 , V_529 ) ;
V_43 = F_215 ( V_4 , V_488 ) ;
F_218 ( ( V_43 & V_610 ) == 0 , L_75 ) ;
F_8 ( L_76 , V_43 & V_610 ? L_77 : L_78 ) ;
F_8 ( L_79 , V_43 ) ;
V_4 -> V_244 . V_457 = ( V_43 >> 8 ) & 0xff ;
F_8 ( L_80 ,
F_219 ( V_4 , V_4 -> V_244 . V_457 ) ,
V_4 -> V_244 . V_457 ) ;
F_8 ( L_81 ,
F_219 ( V_4 , V_4 -> V_244 . V_456 ) ,
V_4 -> V_244 . V_456 ) ;
F_211 ( V_4 -> V_2 , V_4 -> V_244 . V_456 ) ;
F_225 ( V_4 , V_492 ) ;
}
void F_272 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_32 . V_615 ) {
F_186 ( V_4 -> V_32 . V_615 ) ;
F_187 ( & V_4 -> V_32 . V_615 -> V_81 ) ;
V_4 -> V_32 . V_615 = NULL ;
}
if ( V_4 -> V_32 . V_616 ) {
F_186 ( V_4 -> V_32 . V_616 ) ;
F_187 ( & V_4 -> V_32 . V_616 -> V_81 ) ;
V_4 -> V_32 . V_616 = NULL ;
}
}
static void F_273 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_617 ) ) {
F_2 ( V_618 , F_3 ( V_618 ) | V_619 ) ;
F_214 ( ( ( F_3 ( V_618 ) & V_620 ) == V_621 ) ,
50 ) ;
F_2 ( V_617 , 0 ) ;
F_194 ( V_617 ) ;
F_2 ( V_618 , F_3 ( V_618 ) & ~ V_619 ) ;
F_194 ( V_618 ) ;
}
}
static int F_274 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_32 . V_615 == NULL )
V_4 -> V_32 . V_615 = F_180 ( V_2 ) ;
if ( ! V_4 -> V_32 . V_615 )
return - V_622 ;
if ( V_4 -> V_32 . V_616 == NULL )
V_4 -> V_32 . V_616 = F_180 ( V_2 ) ;
if ( ! V_4 -> V_32 . V_616 ) {
F_272 ( V_2 ) ;
return - V_622 ;
}
return 0 ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_512 * V_513 = & V_4 -> V_513 [ V_623 ] ;
bool V_624 ;
int V_204 ;
if ( ! F_231 ( V_2 ) )
return;
F_118 ( ! F_181 ( & V_2 -> V_397 ) ) ;
V_204 = F_274 ( V_2 ) ;
if ( V_204 )
return;
V_624 = V_4 -> V_587 . V_625 ;
V_4 -> V_587 . V_625 = false ;
V_204 = F_276 ( V_513 , 6 ) ;
if ( V_204 ) {
F_272 ( V_2 ) ;
V_4 -> V_587 . V_625 = V_624 ;
return;
}
F_277 ( V_513 , V_626 | V_627 ) ;
F_277 ( V_513 , V_628 ) ;
F_277 ( V_513 , F_278 ( V_4 -> V_32 . V_615 ) |
V_629 |
V_630 |
V_631 |
V_632 ) ;
F_277 ( V_513 , V_626 ) ;
F_277 ( V_513 , V_633 ) ;
F_277 ( V_513 , V_634 ) ;
F_279 ( V_513 ) ;
V_204 = F_280 ( V_513 ) ;
V_4 -> V_587 . V_625 = V_624 ;
if ( V_204 ) {
F_92 ( L_82 ) ;
F_272 ( V_2 ) ;
return;
}
F_2 ( V_617 , F_278 ( V_4 -> V_32 . V_616 ) | V_635 ) ;
F_2 ( V_618 , F_3 ( V_618 ) & ~ V_619 ) ;
F_226 ( V_2 , V_494 ) ;
}
static unsigned long F_281 ( T_1 V_636 )
{
unsigned long V_637 ;
int div = ( V_636 & 0x3f0000 ) >> 16 ;
int V_638 = ( V_636 & 0x3000 ) >> 12 ;
int V_639 = ( V_636 & 0x7 ) ;
if ( ! V_639 )
return 0 ;
V_637 = ( ( div * 133333 ) / ( ( 1 << V_638 ) * V_639 ) ) ;
return V_637 ;
}
static unsigned long F_282 ( struct V_3 * V_4 )
{
T_8 V_640 , V_549 , V_204 ;
T_1 V_641 , V_642 , V_643 , V_644 = 0 , V_645 = 0 ;
unsigned long V_646 = F_197 ( V_441 ) , V_647 ;
int V_40 ;
F_189 ( & V_401 ) ;
V_647 = V_646 - V_4 -> V_32 . V_440 ;
if ( V_647 <= 10 )
return V_4 -> V_32 . V_648 ;
V_641 = F_3 ( V_649 ) ;
V_642 = F_3 ( V_650 ) ;
V_643 = F_3 ( V_651 ) ;
V_640 = V_641 + V_642 + V_643 ;
if ( V_640 < V_4 -> V_32 . V_439 ) {
V_549 = ~ 0UL - V_4 -> V_32 . V_439 ;
V_549 += V_640 ;
} else {
V_549 = V_640 - V_4 -> V_32 . V_439 ;
}
for ( V_40 = 0 ; V_40 < F_10 ( V_652 ) ; V_40 ++ ) {
if ( V_652 [ V_40 ] . V_40 == V_4 -> V_32 . V_34 &&
V_652 [ V_40 ] . V_653 == V_4 -> V_32 . V_33 ) {
V_644 = V_652 [ V_40 ] . V_644 ;
V_645 = V_652 [ V_40 ] . V_645 ;
break;
}
}
V_549 = F_60 ( V_549 , V_647 ) ;
V_204 = ( ( V_644 * V_549 ) + V_645 ) ;
V_204 = F_60 ( V_204 , 10 ) ;
V_4 -> V_32 . V_439 = V_640 ;
V_4 -> V_32 . V_440 = V_646 ;
V_4 -> V_32 . V_648 = V_204 ;
return V_204 ;
}
unsigned long F_283 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_43 ;
if ( F_70 ( V_2 ) -> V_219 != 5 )
return 0 ;
F_193 ( & V_401 ) ;
V_43 = F_282 ( V_4 ) ;
F_199 ( & V_401 ) ;
return V_43 ;
}
unsigned long F_284 ( struct V_3 * V_4 )
{
unsigned long V_644 , V_654 , V_655 ;
T_1 V_656 ;
V_656 = F_3 ( V_657 ) ;
V_644 = ( ( V_656 & V_658 ) >> V_659 ) ;
V_654 = F_285 ( V_660 ) ;
V_655 = V_656 & V_661 ;
return ( ( V_644 * V_654 ) / 127 ) - V_655 ;
}
static int F_286 ( T_7 V_662 )
{
if ( V_662 == 0 )
return 0 ;
if ( V_662 >= 8 && V_662 < 31 )
V_662 = 31 ;
return ( V_662 + 2 ) * 125 ;
}
static T_1 F_287 ( struct V_3 * V_4 , T_7 V_662 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
const int V_663 = F_286 ( V_662 ) ;
const int V_664 = V_663 - 1125 ;
if ( F_70 ( V_2 ) -> V_665 )
return V_664 > 0 ? V_664 : 0 ;
return V_663 ;
}
static void F_288 ( struct V_3 * V_4 )
{
T_8 V_646 , V_549 , V_666 ;
T_1 V_667 ;
F_189 ( & V_401 ) ;
V_646 = F_198 () ;
V_666 = V_646 - V_4 -> V_32 . V_443 ;
F_289 ( V_666 , V_668 ) ;
if ( ! V_666 )
return;
V_667 = F_3 ( V_669 ) ;
if ( V_667 < V_4 -> V_32 . V_442 ) {
V_549 = ~ 0UL - V_4 -> V_32 . V_442 ;
V_549 += V_667 ;
} else {
V_549 = V_667 - V_4 -> V_32 . V_442 ;
}
V_4 -> V_32 . V_442 = V_667 ;
V_4 -> V_32 . V_443 = V_646 ;
V_549 = V_549 * 1181 ;
V_549 = F_60 ( V_549 , V_666 * 10 ) ;
V_4 -> V_32 . V_670 = V_549 ;
}
void F_290 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_70 ( V_2 ) -> V_219 != 5 )
return;
F_193 ( & V_401 ) ;
F_288 ( V_4 ) ;
F_199 ( & V_401 ) ;
}
static unsigned long F_291 ( struct V_3 * V_4 )
{
unsigned long V_653 , V_671 , V_672 , V_673 , V_674 ;
T_1 V_662 , V_675 ;
F_189 ( & V_401 ) ;
V_662 = F_3 ( V_428 + ( V_4 -> V_244 . V_457 * 4 ) ) ;
V_662 = ( V_662 >> 24 ) & 0x7f ;
V_675 = F_287 ( V_4 , V_662 ) ;
V_672 = V_675 ;
V_653 = F_284 ( V_4 ) ;
if ( V_653 > 80 )
V_671 = ( ( V_653 * 2349 ) + 135940 ) ;
else if ( V_653 >= 50 )
V_671 = ( ( V_653 * 964 ) + 29317 ) ;
else
V_671 = ( ( V_653 * 301 ) + 1004 ) ;
V_671 = V_671 * ( ( 150142 * V_672 ) / 10000 - 78642 ) ;
V_671 /= 100000 ;
V_673 = ( V_671 * V_4 -> V_32 . V_671 ) ;
V_674 = ( V_673 * V_672 ) / 10000 ;
V_674 /= 100 ;
F_288 ( V_4 ) ;
return V_4 -> V_32 . V_670 + V_674 ;
}
unsigned long F_292 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_43 ;
if ( F_70 ( V_2 ) -> V_219 != 5 )
return 0 ;
F_193 ( & V_401 ) ;
V_43 = F_291 ( V_4 ) ;
F_199 ( & V_401 ) ;
return V_43 ;
}
unsigned long F_293 ( void )
{
struct V_3 * V_4 ;
unsigned long V_676 , V_677 , V_204 = 0 ;
F_193 ( & V_401 ) ;
if ( ! V_678 )
goto V_679;
V_4 = V_678 ;
V_676 = F_282 ( V_4 ) ;
V_677 = F_291 ( V_4 ) ;
V_204 = V_676 + V_677 ;
V_679:
F_199 ( & V_401 ) ;
return V_204 ;
}
bool F_294 ( void )
{
struct V_3 * V_4 ;
bool V_204 = true ;
F_193 ( & V_401 ) ;
if ( ! V_678 ) {
V_204 = false ;
goto V_679;
}
V_4 = V_678 ;
if ( V_4 -> V_32 . V_431 > V_4 -> V_32 . V_410 )
V_4 -> V_32 . V_431 -- ;
V_679:
F_199 ( & V_401 ) ;
return V_204 ;
}
bool F_295 ( void )
{
struct V_3 * V_4 ;
bool V_204 = true ;
F_193 ( & V_401 ) ;
if ( ! V_678 ) {
V_204 = false ;
goto V_679;
}
V_4 = V_678 ;
if ( V_4 -> V_32 . V_431 < V_4 -> V_32 . V_432 )
V_4 -> V_32 . V_431 ++ ;
V_679:
F_199 ( & V_401 ) ;
return V_204 ;
}
bool F_296 ( void )
{
struct V_3 * V_4 ;
struct V_512 * V_513 ;
bool V_204 = false ;
int V_40 ;
F_193 ( & V_401 ) ;
if ( ! V_678 )
goto V_679;
V_4 = V_678 ;
F_237 (ring, dev_priv, i)
V_204 |= ! F_297 ( & V_513 -> V_680 ) ;
V_679:
F_199 ( & V_401 ) ;
return V_204 ;
}
bool F_298 ( void )
{
struct V_3 * V_4 ;
bool V_204 = true ;
F_193 ( & V_401 ) ;
if ( ! V_678 ) {
V_204 = false ;
goto V_679;
}
V_4 = V_678 ;
V_4 -> V_32 . V_431 = V_4 -> V_32 . V_412 ;
if ( ! F_188 ( V_4 -> V_2 , V_4 -> V_32 . V_412 ) )
V_204 = false ;
V_679:
F_199 ( & V_401 ) ;
return V_204 ;
}
static void
F_299 ( void )
{
void (* F_300)( void );
F_300 = F_301 ( V_681 ) ;
if ( F_300 ) {
F_300 () ;
F_302 ( V_681 ) ;
}
}
void F_303 ( struct V_3 * V_4 )
{
F_193 ( & V_401 ) ;
V_678 = V_4 ;
F_199 ( & V_401 ) ;
F_299 () ;
}
void F_304 ( void )
{
F_193 ( & V_401 ) ;
V_678 = NULL ;
F_199 ( & V_401 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_682 ;
T_7 V_683 [ 16 ] ;
int V_40 ;
F_2 ( V_684 , 0 ) ;
F_194 ( V_684 ) ;
F_2 ( V_685 , 0x15040d00 ) ;
F_2 ( V_686 , 0x007f0000 ) ;
F_2 ( V_687 , 0x1e220004 ) ;
F_2 ( V_688 , 0x04000004 ) ;
for ( V_40 = 0 ; V_40 < 5 ; V_40 ++ )
F_2 ( V_689 + ( V_40 * 4 ) , 0 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ )
F_2 ( V_690 + ( V_40 * 4 ) , 0 ) ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ ) {
T_1 V_691 = F_3 ( V_428 + ( V_40 * 4 ) ) ;
unsigned long V_637 = F_281 ( V_691 ) ;
unsigned long V_692 = ( V_691 & V_429 ) >>
V_430 ;
unsigned long V_43 ;
V_43 = V_692 * V_692 ;
V_43 *= ( V_637 / 1000 ) ;
V_43 *= 255 ;
V_43 /= ( 127 * 127 * 900 ) ;
if ( V_43 > 0xff )
F_92 ( L_83 , V_43 ) ;
V_683 [ V_40 ] = V_43 ;
}
V_683 [ 14 ] = 0 ;
V_683 [ 15 ] = 0 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
T_1 V_43 = ( V_683 [ V_40 * 4 ] << 24 ) | ( V_683 [ ( V_40 * 4 ) + 1 ] << 16 ) |
( V_683 [ ( V_40 * 4 ) + 2 ] << 8 ) | ( V_683 [ ( V_40 * 4 ) + 3 ] ) ;
F_2 ( V_693 + ( V_40 * 4 ) , V_43 ) ;
}
F_2 ( V_694 , 0 ) ;
F_2 ( V_695 , 0 ) ;
F_2 ( V_696 , 0x00007f00 ) ;
F_2 ( V_697 , 0x0000000e ) ;
F_2 ( V_698 , 0x000e0000 ) ;
F_2 ( V_699 , 0x68000300 ) ;
F_2 ( V_700 , 0x42000000 ) ;
F_2 ( V_701 , 0x00140031 ) ;
F_2 ( V_702 , 0 ) ;
F_2 ( V_703 , 0 ) ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ )
F_2 ( V_704 + ( V_40 * 4 ) , 0 ) ;
F_2 ( V_684 , 0x80000019 ) ;
V_682 = F_3 ( V_705 ) ;
V_4 -> V_32 . V_671 = ( V_682 & V_706 ) ;
}
void F_306 ( struct V_1 * V_2 )
{
V_501 . V_497 = F_229 ( V_2 , V_501 . V_497 ) ;
if ( F_40 ( V_2 ) )
F_267 ( V_2 ) ;
else if ( F_13 ( V_2 ) )
F_266 ( V_2 ) ;
}
void F_307 ( struct V_1 * V_2 )
{
if ( F_40 ( V_2 ) )
return;
else if ( F_13 ( V_2 ) )
F_269 ( V_2 ) ;
}
static void F_308 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_309 ( & V_4 -> V_244 . V_707 ) ;
if ( F_70 ( V_2 ) -> V_219 < 9 )
F_310 ( V_2 ) ;
}
void F_311 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_70 ( V_2 ) -> V_219 < 6 )
return;
F_308 ( V_2 ) ;
F_216 ( V_4 ) ;
}
void F_312 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_230 ( V_2 ) ) {
F_200 ( V_2 ) ;
F_273 ( V_2 ) ;
} else if ( F_70 ( V_2 ) -> V_219 >= 6 ) {
F_311 ( V_2 ) ;
F_89 ( & V_4 -> V_244 . V_245 ) ;
if ( F_70 ( V_2 ) -> V_219 >= 9 )
F_220 ( V_2 ) ;
else if ( F_40 ( V_2 ) )
F_222 ( V_2 ) ;
else if ( F_13 ( V_2 ) )
F_223 ( V_2 ) ;
else
F_221 ( V_2 ) ;
V_4 -> V_244 . V_72 = false ;
F_91 ( & V_4 -> V_244 . V_245 ) ;
}
}
static void F_313 ( struct V_708 * V_709 )
{
struct V_3 * V_4 =
F_314 ( V_709 , struct V_3 ,
V_244 . V_707 . V_709 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_89 ( & V_4 -> V_244 . V_245 ) ;
if ( F_70 ( V_2 ) -> V_219 < 9 )
F_315 ( V_2 ) ;
if ( F_40 ( V_2 ) ) {
F_270 ( V_2 ) ;
} else if ( F_13 ( V_2 ) ) {
F_271 ( V_2 ) ;
} else if ( F_70 ( V_2 ) -> V_219 >= 9 ) {
F_236 ( V_2 ) ;
F_234 ( V_2 ) ;
F_245 ( V_2 ) ;
} else if ( F_94 ( V_2 ) ) {
F_240 ( V_2 ) ;
F_245 ( V_2 ) ;
} else {
F_241 ( V_2 ) ;
F_245 ( V_2 ) ;
}
V_4 -> V_244 . V_72 = true ;
if ( F_70 ( V_2 ) -> V_219 < 9 )
F_235 ( V_2 ) ;
F_91 ( & V_4 -> V_244 . V_245 ) ;
F_316 ( V_4 ) ;
}
void F_317 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_230 ( V_2 ) ) {
F_89 ( & V_2 -> V_397 ) ;
F_192 ( V_2 ) ;
F_275 ( V_2 ) ;
F_305 ( V_2 ) ;
F_91 ( & V_2 -> V_397 ) ;
} else if ( F_70 ( V_2 ) -> V_219 >= 6 ) {
if ( F_318 ( & V_4 -> V_244 . V_707 ,
F_319 ( V_710 ) ) )
F_320 ( V_4 ) ;
}
}
void F_321 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_70 ( V_2 ) -> V_219 < 6 )
return;
F_308 ( V_2 ) ;
V_4 -> V_244 . V_72 = false ;
}
static void F_322 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_711 , V_712 ) ;
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_125 ;
F_121 (dev_priv, pipe) {
F_2 ( F_324 ( V_125 ) ,
F_3 ( F_324 ( V_125 ) ) |
V_713 ) ;
F_325 ( V_4 , V_125 ) ;
}
}
static void F_326 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_305 , F_3 ( V_305 ) & ~ V_284 ) ;
F_2 ( V_306 , F_3 ( V_306 ) & ~ V_284 ) ;
F_2 ( V_307 , F_3 ( V_307 ) & ~ V_284 ) ;
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_714 = V_715 ;
V_714 |= V_716 |
V_717 |
V_718 ;
F_2 ( V_719 ,
V_720 |
V_721 ) ;
F_2 ( V_722 ,
V_723 ) ;
F_2 ( V_724 ,
( F_3 ( V_724 ) |
V_725 | V_726 ) ) ;
V_714 |= V_727 ;
F_2 ( V_315 ,
( F_3 ( V_315 ) |
V_316 ) ) ;
F_326 ( V_2 ) ;
if ( F_230 ( V_2 ) ) {
F_2 ( V_728 ,
F_3 ( V_728 ) |
V_729 ) ;
F_2 ( V_724 ,
F_3 ( V_724 ) |
V_725 ) ;
}
F_2 ( V_730 , V_714 ) ;
F_2 ( V_724 ,
F_3 ( V_724 ) |
V_731 ) ;
F_2 ( V_732 ,
V_733 << 16 |
V_733 ) ;
F_2 ( V_734 ,
F_4 ( V_735 ) ) ;
F_2 ( V_734 , F_19 ( V_736 ) ) ;
F_323 ( V_2 ) ;
F_322 ( V_2 ) ;
}
static void F_328 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_125 ;
T_3 V_43 ;
F_2 ( V_711 , V_712 |
V_737 |
V_738 ) ;
F_2 ( V_739 , F_3 ( V_739 ) |
V_740 ) ;
F_121 (dev_priv, pipe) {
V_43 = F_3 ( F_329 ( V_125 ) ) ;
V_43 |= V_741 ;
V_43 &= ~ V_742 ;
if ( V_4 -> V_743 . V_744 )
V_43 |= V_742 ;
V_43 &= ~ V_745 ;
V_43 &= ~ V_746 ;
V_43 &= ~ V_747 ;
F_2 ( F_329 ( V_125 ) , V_43 ) ;
}
F_121 (dev_priv, pipe) {
F_2 ( F_330 ( V_125 ) ,
V_748 ) ;
}
}
static void F_331 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_12 ;
V_12 = F_3 ( V_252 ) ;
if ( ( V_12 & V_749 ) != V_750 )
F_11 ( L_84 ,
V_12 ) ;
}
static void F_332 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_714 = V_715 ;
F_2 ( V_730 , V_714 ) ;
F_2 ( V_724 ,
F_3 ( V_724 ) |
V_731 ) ;
F_2 ( V_751 ,
F_4 ( V_752 ) ) ;
F_2 ( V_734 , F_19 ( V_736 ) ) ;
F_2 ( V_753 ,
F_333 ( V_754 , V_755 ) ) ;
F_326 ( V_2 ) ;
F_2 ( V_734 ,
F_19 ( V_756 ) ) ;
F_2 ( V_757 ,
F_3 ( V_757 ) |
V_758 |
V_759 ) ;
F_2 ( V_760 ,
V_761 |
V_762 ) ;
F_2 ( V_763 ,
F_4 ( V_764 ) ) ;
F_2 ( V_763 ,
F_4 ( V_765 ) ) ;
F_2 ( V_728 ,
F_3 ( V_728 ) |
V_729 | V_766 ) ;
F_2 ( V_724 ,
F_3 ( V_724 ) |
V_725 | V_726 ) ;
F_2 ( V_730 ,
F_3 ( V_730 ) |
V_727 |
V_718 ) ;
F_323 ( V_2 ) ;
F_328 ( V_2 ) ;
F_331 ( V_2 ) ;
}
static void F_334 ( struct V_3 * V_4 )
{
T_3 V_74 = F_3 ( V_767 ) ;
V_74 &= ~ V_768 ;
V_74 |= V_769 ;
V_74 |= V_770 ;
V_74 |= V_771 ;
F_2 ( V_767 , V_74 ) ;
}
static void F_335 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_772 == V_773 )
F_2 ( V_711 ,
F_3 ( V_711 ) |
V_774 ) ;
F_2 ( V_775 ,
F_3 ( V_775 ) |
V_748 ) ;
}
static void F_336 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_772 == V_773 ) {
T_3 V_43 = F_3 ( V_711 ) ;
V_43 &= ~ V_774 ;
F_2 ( V_711 , V_43 ) ;
}
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_125 V_125 ;
F_2 ( V_305 , 0 ) ;
F_2 ( V_306 , 0 ) ;
F_2 ( V_307 , 0 ) ;
F_2 ( V_776 , F_3 ( V_776 ) | V_777 ) ;
F_2 ( V_778 ,
F_3 ( V_778 ) | V_779 ) ;
F_121 (dev_priv, pipe) {
F_2 ( F_338 ( V_125 ) ,
F_3 ( F_338 ( V_125 ) ) |
V_780 ) ;
}
F_2 ( V_767 ,
F_3 ( V_767 ) &
~ ( V_781 | V_782 ) ) ;
F_2 ( V_783 ,
F_4 ( V_784 ) ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
F_335 ( V_2 ) ;
}
static void F_339 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_326 ( V_2 ) ;
F_2 ( V_785 , V_786 ) ;
F_2 ( V_787 ,
F_4 ( V_788 ) ) ;
F_2 ( V_789 ,
F_3 ( V_789 ) |
V_790 ) ;
F_2 ( V_767 ,
F_3 ( V_767 ) & ~ V_782 ) ;
F_2 ( V_791 , F_19 ( V_736 ) ) ;
F_2 ( V_791 ,
F_19 ( V_792 ) ) ;
F_2 ( V_10 ,
F_4 ( V_793 ) ) ;
F_2 ( V_794 ,
F_333 ( V_754 , V_755 ) ) ;
F_2 ( V_795 ,
F_4 ( V_796 ) ) ;
F_2 ( V_776 , F_3 ( V_776 ) | V_777 ) ;
F_2 ( V_778 ,
F_3 ( V_778 ) | V_797 ) ;
F_335 ( V_2 ) ;
}
static void F_340 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_798 ;
F_326 ( V_2 ) ;
F_2 ( V_730 , V_715 ) ;
F_2 ( V_763 ,
F_4 ( V_799 ) ) ;
F_2 ( V_800 ,
V_801 |
V_802 ) ;
if ( F_341 ( V_2 ) )
F_2 ( V_803 ,
F_4 ( V_804 ) ) ;
F_2 ( V_791 , F_19 ( V_736 ) ) ;
F_2 ( V_805 ,
V_806 ) ;
F_2 ( V_807 ,
V_808 ) ;
F_2 ( V_809 ,
V_810 ) ;
if ( F_341 ( V_2 ) )
F_2 ( V_811 ,
F_4 ( V_812 ) ) ;
else {
F_2 ( V_811 ,
F_4 ( V_812 ) ) ;
F_2 ( V_813 ,
F_4 ( V_812 ) ) ;
}
F_2 ( V_814 , F_3 ( V_814 ) &
~ V_815 ) ;
F_2 ( V_760 ,
V_816 ) ;
F_2 ( V_789 ,
F_3 ( V_789 ) |
V_790 ) ;
F_323 ( V_2 ) ;
F_334 ( V_4 ) ;
if ( 0 ) {
F_2 ( V_791 ,
F_19 ( V_792 ) ) ;
}
F_2 ( V_10 ,
F_4 ( V_793 ) ) ;
F_2 ( V_794 ,
F_333 ( V_754 , V_755 ) ) ;
V_798 = F_3 ( V_817 ) ;
V_798 &= ~ V_818 ;
V_798 |= V_819 ;
F_2 ( V_817 , V_798 ) ;
if ( ! F_342 ( V_2 ) )
F_328 ( V_2 ) ;
F_331 ( V_2 ) ;
}
static void F_343 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_820 , V_821 ) ;
F_2 ( V_763 ,
F_4 ( V_799 ) ) ;
F_2 ( V_800 ,
V_801 |
V_802 ) ;
F_2 ( V_803 ,
F_4 ( V_822 |
V_804 ) ) ;
F_2 ( V_791 , F_19 ( V_736 ) ) ;
F_2 ( V_814 , F_3 ( V_814 ) &
~ V_815 ) ;
F_2 ( V_811 ,
F_4 ( V_812 ) ) ;
F_2 ( V_789 ,
F_3 ( V_789 ) |
V_790 ) ;
F_334 ( V_4 ) ;
F_2 ( V_760 ,
V_816 ) ;
F_2 ( V_823 ,
F_3 ( V_823 ) | V_824 ) ;
F_2 ( V_825 , V_826 ) ;
F_2 ( V_10 ,
F_4 ( V_793 ) ) ;
F_2 ( V_794 ,
F_333 ( V_754 , V_755 ) ) ;
F_2 ( V_827 , V_828 ) ;
F_2 ( V_829 , V_830 ) ;
}
static void F_344 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_820 , V_821 ) ;
F_2 ( V_825 , V_826 ) ;
F_2 ( V_767 ,
F_3 ( V_767 ) &
~ ( V_781 | V_782 ) ) ;
F_2 ( V_783 ,
F_4 ( V_784 ) ) ;
F_2 ( V_757 , F_3 ( V_757 ) |
V_759 ) ;
F_2 ( V_6 , F_3 ( V_6 ) |
V_7 ) ;
}
static void F_345 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_714 ;
F_2 ( V_831 , 0 ) ;
F_2 ( V_832 , V_833 |
V_834 |
V_835 ) ;
F_2 ( V_836 , 0 ) ;
V_714 = V_821 |
V_837 |
V_838 ;
if ( F_346 ( V_2 ) )
V_714 |= V_839 ;
F_2 ( V_820 , V_714 ) ;
F_2 ( V_734 ,
F_4 ( V_735 ) ) ;
F_2 ( V_734 , F_19 ( V_736 ) ) ;
F_323 ( V_2 ) ;
}
static void F_347 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_831 , V_840 ) ;
F_2 ( V_832 , 0 ) ;
F_2 ( V_820 , 0 ) ;
F_2 ( V_836 , 0 ) ;
F_190 ( V_841 , 0 ) ;
F_2 ( V_842 ,
F_4 ( V_826 ) ) ;
F_2 ( V_734 , F_19 ( V_736 ) ) ;
}
static void F_348 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_831 , V_843 |
V_840 |
V_844 |
V_845 |
V_846 ) ;
F_2 ( V_832 , 0 ) ;
F_2 ( V_842 ,
F_4 ( V_826 ) ) ;
F_2 ( V_734 , F_19 ( V_736 ) ) ;
}
static void F_349 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_847 = F_3 ( V_848 ) ;
V_847 |= V_849 | V_850 |
V_851 ;
F_2 ( V_848 , V_847 ) ;
if ( F_16 ( V_2 ) )
F_2 ( V_852 , F_4 ( V_853 ) ) ;
F_2 ( V_852 , F_19 ( V_854 ) ) ;
F_2 ( V_51 , F_4 ( V_855 ) ) ;
F_2 ( V_842 , F_4 ( V_856 ) ) ;
F_2 ( V_842 ,
F_4 ( V_826 ) ) ;
}
static void F_350 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_831 , V_857 ) ;
F_2 ( V_858 , F_4 ( V_859 ) |
F_19 ( V_860 ) ) ;
F_2 ( V_861 ,
F_4 ( V_862 ) ) ;
}
static void F_351 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_820 , V_837 ) ;
F_2 ( V_861 ,
F_4 ( V_863 ) |
F_4 ( V_864 ) ) ;
}
void F_352 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_99 . V_865 ( V_2 ) ;
}
void F_353 ( struct V_1 * V_2 )
{
if ( F_354 ( V_2 ) )
F_336 ( V_2 ) ;
}
void F_355 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_356 ( V_4 ) ;
if ( F_16 ( V_2 ) )
F_5 ( V_2 ) ;
else if ( F_113 ( V_2 ) )
F_6 ( V_2 ) ;
if ( F_70 ( V_2 ) -> V_219 >= 9 ) {
F_105 ( V_2 ) ;
V_4 -> V_99 . V_865 = F_1 ;
V_4 -> V_99 . V_394 = F_169 ;
V_4 -> V_99 . V_395 = F_170 ;
} else if ( F_357 ( V_2 ) ) {
F_103 ( V_2 ) ;
if ( ( F_113 ( V_2 ) && V_4 -> V_60 . V_236 [ 1 ] &&
V_4 -> V_60 . V_237 [ 1 ] && V_4 -> V_60 . V_238 [ 1 ] ) ||
( ! F_113 ( V_2 ) && V_4 -> V_60 . V_236 [ 0 ] &&
V_4 -> V_60 . V_237 [ 0 ] && V_4 -> V_60 . V_238 [ 0 ] ) ) {
V_4 -> V_99 . V_394 = F_171 ;
V_4 -> V_99 . V_395 = F_172 ;
} else {
F_11 ( L_85
L_86 ) ;
}
if ( F_113 ( V_2 ) )
V_4 -> V_99 . V_865 = F_327 ;
else if ( F_104 ( V_2 ) )
V_4 -> V_99 . V_865 = F_332 ;
else if ( F_98 ( V_2 ) )
V_4 -> V_99 . V_865 = F_340 ;
else if ( F_93 ( V_2 ) )
V_4 -> V_99 . V_865 = F_339 ;
else if ( F_70 ( V_2 ) -> V_219 == 8 )
V_4 -> V_99 . V_865 = F_337 ;
} else if ( F_40 ( V_2 ) ) {
V_4 -> V_99 . V_394 = F_46 ;
V_4 -> V_99 . V_395 = F_47 ;
V_4 -> V_99 . V_865 =
F_344 ;
} else if ( F_13 ( V_2 ) ) {
V_4 -> V_99 . V_394 = F_43 ;
V_4 -> V_99 . V_395 = F_47 ;
V_4 -> V_99 . V_865 =
F_343 ;
} else if ( F_16 ( V_2 ) ) {
if ( ! F_9 ( F_30 ( V_2 ) ,
V_4 -> V_26 ,
V_4 -> V_16 ,
V_4 -> V_22 ) ) {
F_239 ( L_87
L_88
L_89 ,
( V_4 -> V_26 == 1 ) ? L_90 : L_91 ,
V_4 -> V_16 , V_4 -> V_22 ) ;
F_12 ( V_4 , false ) ;
V_4 -> V_99 . V_394 = NULL ;
} else
V_4 -> V_99 . V_394 = F_29 ;
V_4 -> V_99 . V_865 = F_349 ;
} else if ( F_14 ( V_2 ) ) {
V_4 -> V_99 . V_394 = F_52 ;
V_4 -> V_99 . V_865 = F_345 ;
} else if ( F_358 ( V_2 ) ) {
V_4 -> V_99 . V_394 = F_53 ;
if ( F_15 ( V_2 ) )
V_4 -> V_99 . V_865 = F_347 ;
else if ( F_359 ( V_2 ) )
V_4 -> V_99 . V_865 = F_348 ;
} else if ( F_360 ( V_2 ) ) {
V_4 -> V_99 . V_394 = F_54 ;
V_4 -> V_99 . V_184 = F_21 ;
V_4 -> V_99 . V_865 = F_349 ;
} else if ( F_55 ( V_2 ) ) {
if ( F_70 ( V_2 ) -> V_227 == 1 ) {
V_4 -> V_99 . V_394 = F_58 ;
V_4 -> V_99 . V_184 = F_23 ;
} else {
V_4 -> V_99 . V_394 = F_54 ;
V_4 -> V_99 . V_184 = F_22 ;
}
if ( F_361 ( V_2 ) || F_362 ( V_2 ) )
V_4 -> V_99 . V_865 = F_350 ;
else
V_4 -> V_99 . V_865 = F_351 ;
} else {
F_92 ( L_92 ) ;
}
}
int F_90 ( struct V_3 * V_4 , T_1 V_866 , T_1 * V_43 )
{
F_118 ( ! F_181 ( & V_4 -> V_244 . V_245 ) ) ;
if ( F_3 ( V_867 ) & V_868 ) {
F_8 ( L_93 ) ;
return - V_869 ;
}
F_2 ( V_870 , * V_43 ) ;
F_2 ( V_871 , 0 ) ;
F_2 ( V_867 , V_868 | V_866 ) ;
if ( F_214 ( ( F_3 ( V_867 ) & V_868 ) == 0 ,
500 ) ) {
F_92 ( L_94 , V_866 ) ;
return - V_872 ;
}
* V_43 = F_3 ( V_870 ) ;
F_2 ( V_870 , 0 ) ;
return 0 ;
}
int F_242 ( struct V_3 * V_4 , T_1 V_866 , T_1 V_43 )
{
F_118 ( ! F_181 ( & V_4 -> V_244 . V_245 ) ) ;
if ( F_3 ( V_867 ) & V_868 ) {
F_8 ( L_95 ) ;
return - V_869 ;
}
F_2 ( V_870 , V_43 ) ;
F_2 ( V_867 , V_868 | V_866 ) ;
if ( F_214 ( ( F_3 ( V_867 ) & V_868 ) == 0 ,
500 ) ) {
F_92 ( L_96 , V_866 ) ;
return - V_872 ;
}
F_2 ( V_870 , 0 ) ;
return 0 ;
}
static int F_363 ( unsigned int V_873 )
{
switch ( V_873 ) {
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
static int F_364 ( struct V_3 * V_4 , int V_43 )
{
int div , V_873 = F_82 ( V_4 -> V_22 , 4 ) ;
div = F_363 ( V_873 ) ;
if ( div < 0 )
return div ;
return F_82 ( V_873 * ( V_43 + 6 - 0xbd ) , div ) ;
}
static int F_365 ( struct V_3 * V_4 , int V_43 )
{
int V_874 , V_873 = F_82 ( V_4 -> V_22 , 4 ) ;
V_874 = F_363 ( V_873 ) ;
if ( V_874 < 0 )
return V_874 ;
return F_82 ( V_874 * V_43 , V_873 ) + 0xbd - 6 ;
}
static int F_366 ( struct V_3 * V_4 , int V_43 )
{
int div , V_873 = V_4 -> V_244 . V_605 ;
div = F_363 ( V_873 ) / 2 ;
if ( div < 0 )
return div ;
return F_82 ( V_873 * V_43 , 2 * div ) / 2 ;
}
static int F_367 ( struct V_3 * V_4 , int V_43 )
{
int V_874 , V_873 = V_4 -> V_244 . V_605 ;
V_874 = F_363 ( V_873 ) / 2 ;
if ( V_874 < 0 )
return V_874 ;
return F_82 ( V_43 * 2 * V_874 , V_873 ) * 2 ;
}
int F_219 ( struct V_3 * V_4 , int V_43 )
{
if ( F_40 ( V_4 -> V_2 ) )
return F_366 ( V_4 , V_43 ) ;
else if ( F_13 ( V_4 -> V_2 ) )
return F_364 ( V_4 , V_43 ) ;
else
return V_43 * V_875 ;
}
int F_368 ( struct V_3 * V_4 , int V_43 )
{
if ( F_40 ( V_4 -> V_2 ) )
return F_367 ( V_4 , V_43 ) ;
else if ( F_13 ( V_4 -> V_2 ) )
return F_365 ( V_4 , V_43 ) ;
else
return V_43 / V_875 ;
}
void F_369 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_370 ( & V_4 -> V_244 . V_245 ) ;
F_371 ( & V_4 -> V_244 . V_707 ,
F_313 ) ;
V_4 -> V_876 . V_877 = false ;
}
