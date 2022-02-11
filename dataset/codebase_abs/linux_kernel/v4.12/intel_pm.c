static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ,
F_3 ( V_3 ) | V_4 ) ;
F_2 ( V_5 ,
F_3 ( V_5 ) | V_6 ) ;
F_2 ( V_7 ,
F_3 ( V_7 ) | V_8 ) ;
F_2 ( V_9 , F_3 ( V_9 ) |
V_10 |
V_11 ) ;
F_2 ( V_12 , F_3 ( V_12 ) |
V_13 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_2 ( V_14 , F_3 ( V_14 ) |
V_15 ) ;
F_2 ( V_14 , F_3 ( V_14 ) |
V_16 ) ;
F_2 ( V_17 , F_3 ( V_17 ) |
V_18 | V_19 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_2 ( V_17 , F_3 ( V_17 ) |
V_18 | V_19 ) ;
if ( F_6 ( V_2 , 0 , V_20 ) ) {
T_1 V_21 = F_3 ( V_22 ) ;
V_21 &= ~ ( V_23 |
V_24 |
V_25 ) ;
F_2 ( V_22 , V_21 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_26 ;
V_26 = F_3 ( V_27 ) ;
switch ( V_26 & V_28 ) {
case V_29 :
V_2 -> V_30 = 533 ;
break;
case V_31 :
V_2 -> V_30 = 800 ;
break;
case V_32 :
V_2 -> V_30 = 667 ;
break;
case V_33 :
V_2 -> V_30 = 400 ;
break;
}
switch ( V_26 & V_34 ) {
case V_35 :
V_2 -> V_36 = 533 ;
break;
case V_37 :
V_2 -> V_36 = 667 ;
break;
case V_38 :
V_2 -> V_36 = 800 ;
break;
}
V_26 = F_3 ( V_39 ) ;
V_2 -> V_40 = ( V_26 & V_41 ) ? 1 : 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_42 , V_43 ;
V_42 = F_9 ( V_44 ) ;
V_43 = F_9 ( V_45 ) ;
switch ( V_42 & 0xff ) {
case 0xc :
V_2 -> V_36 = 800 ;
break;
case 0x10 :
V_2 -> V_36 = 1066 ;
break;
case 0x14 :
V_2 -> V_36 = 1333 ;
break;
case 0x18 :
V_2 -> V_36 = 1600 ;
break;
default:
F_10 ( L_1 ,
V_42 & 0xff ) ;
V_2 -> V_36 = 0 ;
break;
}
V_2 -> V_46 . V_47 = V_2 -> V_36 ;
switch ( V_43 & 0x3ff ) {
case 0x00c :
V_2 -> V_30 = 3200 ;
break;
case 0x00e :
V_2 -> V_30 = 3733 ;
break;
case 0x010 :
V_2 -> V_30 = 4266 ;
break;
case 0x012 :
V_2 -> V_30 = 4800 ;
break;
case 0x014 :
V_2 -> V_30 = 5333 ;
break;
case 0x016 :
V_2 -> V_30 = 5866 ;
break;
case 0x018 :
V_2 -> V_30 = 6400 ;
break;
default:
F_10 ( L_2 ,
V_43 & 0x3ff ) ;
V_2 -> V_30 = 0 ;
break;
}
if ( V_2 -> V_30 == 3200 ) {
V_2 -> V_46 . V_48 = 0 ;
} else if ( V_2 -> V_30 > 3200 && V_2 -> V_30 <= 4800 ) {
V_2 -> V_46 . V_48 = 1 ;
} else {
V_2 -> V_46 . V_48 = 2 ;
}
}
static const struct V_49 * F_11 ( bool V_50 ,
bool V_40 ,
int V_51 ,
int V_52 )
{
const struct V_49 * V_53 ;
int V_54 ;
if ( V_51 == 0 || V_52 == 0 )
return NULL ;
for ( V_54 = 0 ; V_54 < F_12 ( V_55 ) ; V_54 ++ ) {
V_53 = & V_55 [ V_54 ] ;
if ( V_50 == V_53 -> V_50 &&
V_40 == V_53 -> V_40 &&
V_51 == V_53 -> V_30 && V_52 == V_53 -> V_36 )
return V_53 ;
}
F_13 ( L_3 ) ;
return NULL ;
}
static void F_14 ( struct V_1 * V_2 , bool V_56 )
{
T_1 V_21 ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_21 = F_16 ( V_2 , V_59 ) ;
if ( V_56 )
V_21 &= ~ V_60 ;
else
V_21 |= V_60 ;
V_21 &= ~ V_61 ;
V_21 |= V_62 ;
F_17 ( V_2 , V_59 , V_21 ) ;
if ( F_18 ( ( F_16 ( V_2 , V_59 ) &
V_62 ) == 0 , 3 ) )
F_19 ( L_4 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
static void F_21 ( struct V_1 * V_2 , bool V_56 )
{
T_1 V_21 ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_21 = F_16 ( V_2 , V_63 ) ;
if ( V_56 )
V_21 |= V_64 ;
else
V_21 &= ~ V_64 ;
F_17 ( V_2 , V_63 , V_21 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
static bool F_22 ( struct V_1 * V_2 , bool V_56 )
{
bool V_65 ;
T_1 V_21 ;
if ( F_23 ( V_2 ) || F_24 ( V_2 ) ) {
V_65 = F_3 ( V_66 ) & V_67 ;
F_2 ( V_66 , V_56 ? V_67 : 0 ) ;
F_25 ( V_66 ) ;
} else if ( F_26 ( V_2 ) || F_27 ( V_2 ) ) {
V_65 = F_3 ( V_68 ) & V_69 ;
F_2 ( V_68 , V_56 ? V_69 : 0 ) ;
F_25 ( V_68 ) ;
} else if ( F_28 ( V_2 ) ) {
V_21 = F_3 ( V_70 ) ;
V_65 = V_21 & V_71 ;
if ( V_56 )
V_21 |= V_71 ;
else
V_21 &= ~ V_71 ;
F_2 ( V_70 , V_21 ) ;
F_25 ( V_70 ) ;
} else if ( F_29 ( V_2 ) || F_30 ( V_2 ) ) {
V_65 = F_3 ( V_68 ) & V_69 ;
V_21 = V_56 ? F_31 ( V_69 ) :
F_32 ( V_69 ) ;
F_2 ( V_68 , V_21 ) ;
F_25 ( V_68 ) ;
} else if ( F_33 ( V_2 ) ) {
V_65 = F_3 ( V_72 ) & V_73 ;
V_21 = V_56 ? F_31 ( V_73 ) :
F_32 ( V_73 ) ;
F_2 ( V_72 , V_21 ) ;
F_25 ( V_72 ) ;
} else {
return false ;
}
F_34 ( V_2 , V_65 , V_56 ) ;
F_13 ( L_5 ,
F_35 ( V_56 ) ,
F_35 ( V_65 ) ) ;
return V_65 ;
}
bool F_36 ( struct V_1 * V_2 , bool V_56 )
{
bool V_74 ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_74 = F_22 ( V_2 , V_56 ) ;
V_2 -> V_75 . V_77 . V_78 = V_56 ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
return V_74 ;
}
static void F_37 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_38 ( V_80 -> V_83 . V_82 ) ;
struct V_1 * V_2 = F_39 ( V_82 -> V_83 . V_84 ) ;
struct V_85 * V_86 = & V_80 -> V_75 . V_77 . V_86 ;
enum V_87 V_87 = V_82 -> V_87 ;
int V_88 , V_89 ;
switch ( V_87 ) {
T_3 V_90 , V_91 , V_92 ;
case V_93 :
V_90 = F_3 ( V_94 ) ;
V_91 = F_3 ( V_95 ) ;
V_88 = F_40 ( V_90 , V_91 , 0 , 0 ) ;
V_89 = F_40 ( V_90 , V_91 , 8 , 4 ) ;
break;
case V_96 :
V_90 = F_3 ( V_94 ) ;
V_91 = F_3 ( V_95 ) ;
V_88 = F_40 ( V_90 , V_91 , 16 , 8 ) ;
V_89 = F_40 ( V_90 , V_91 , 24 , 12 ) ;
break;
case V_97 :
V_91 = F_3 ( V_95 ) ;
V_92 = F_3 ( V_98 ) ;
V_88 = F_40 ( V_92 , V_91 , 0 , 16 ) ;
V_89 = F_40 ( V_92 , V_91 , 8 , 20 ) ;
break;
default:
F_41 ( V_87 ) ;
return;
}
V_86 -> V_99 [ V_100 ] = V_88 ;
V_86 -> V_99 [ V_101 ] = V_89 - V_88 ;
V_86 -> V_99 [ V_102 ] = 511 - V_89 ;
V_86 -> V_99 [ V_103 ] = 63 ;
F_13 ( L_6 ,
F_42 ( V_87 ) ,
V_86 -> V_99 [ V_100 ] ,
V_86 -> V_99 [ V_101 ] ,
V_86 -> V_99 [ V_102 ] ,
V_86 -> V_99 [ V_103 ] ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_99 )
{
T_3 V_90 = F_3 ( V_94 ) ;
int V_104 ;
V_104 = V_90 & 0x7f ;
if ( V_99 )
V_104 = ( ( V_90 >> V_105 ) & 0x7f ) - V_104 ;
F_13 ( L_7 , V_90 ,
V_99 ? L_8 : L_9 , V_104 ) ;
return V_104 ;
}
static int F_44 ( struct V_1 * V_2 , int V_99 )
{
T_3 V_90 = F_3 ( V_94 ) ;
int V_104 ;
V_104 = V_90 & 0x1ff ;
if ( V_99 )
V_104 = ( ( V_90 >> V_106 ) & 0x1ff ) - V_104 ;
V_104 >>= 1 ;
F_13 ( L_7 , V_90 ,
V_99 ? L_8 : L_9 , V_104 ) ;
return V_104 ;
}
static int F_45 ( struct V_1 * V_2 , int V_99 )
{
T_3 V_90 = F_3 ( V_94 ) ;
int V_104 ;
V_104 = V_90 & 0x7f ;
V_104 >>= 2 ;
F_13 ( L_7 , V_90 ,
V_99 ? L_8 : L_9 ,
V_104 ) ;
return V_104 ;
}
static unsigned long F_46 ( unsigned long V_107 ,
const struct V_108 * V_75 ,
int V_109 , int V_110 ,
unsigned long V_111 )
{
long V_112 , V_113 ;
V_112 = ( ( V_107 / 1000 ) * V_110 * V_111 ) /
1000 ;
V_112 = F_47 ( V_112 , V_75 -> V_114 ) ;
F_13 ( L_10 , V_112 ) ;
V_113 = V_109 - ( V_112 + V_75 -> V_115 ) ;
F_13 ( L_11 , V_113 ) ;
if ( V_113 > ( long ) V_75 -> V_116 )
V_113 = V_75 -> V_116 ;
if ( V_113 <= 0 )
V_113 = V_75 -> V_117 ;
if ( V_113 <= 8 )
V_113 = 8 ;
return V_113 ;
}
static bool F_48 ( const struct V_79 * V_80 ,
const struct V_118 * V_119 )
{
struct V_120 * V_99 = F_49 ( V_119 -> V_83 . V_99 ) ;
if ( ! V_80 -> V_83 . V_121 )
return false ;
if ( V_99 -> V_122 == V_103 )
return V_119 -> V_83 . V_123 != NULL ;
else
return V_119 -> V_83 . V_124 ;
}
static struct V_81 * F_50 ( struct V_1 * V_2 )
{
struct V_81 * V_82 , * V_125 = NULL ;
F_51 (&dev_priv->drm, crtc) {
if ( F_52 ( V_82 ) ) {
if ( V_125 )
return NULL ;
V_125 = V_82 ;
}
}
return V_125 ;
}
static void F_53 ( struct V_81 * V_126 )
{
struct V_1 * V_2 = F_39 ( V_126 -> V_83 . V_84 ) ;
struct V_81 * V_82 ;
const struct V_49 * V_53 ;
T_1 V_127 ;
unsigned long V_75 ;
V_53 = F_11 ( F_54 ( V_2 ) ,
V_2 -> V_40 ,
V_2 -> V_30 ,
V_2 -> V_36 ) ;
if ( ! V_53 ) {
F_13 ( L_3 ) ;
F_36 ( V_2 , false ) ;
return;
}
V_82 = F_50 ( V_2 ) ;
if ( V_82 ) {
const struct V_128 * V_129 =
& V_82 -> V_130 -> V_83 . V_129 ;
const struct V_131 * V_123 =
V_82 -> V_83 . V_132 -> V_133 -> V_123 ;
int V_110 = V_123 -> V_134 -> V_110 [ 0 ] ;
int clock = V_129 -> V_135 ;
V_75 = F_46 ( clock , & V_136 ,
V_136 . V_109 ,
V_110 , V_53 -> V_137 ) ;
V_127 = F_3 ( V_138 ) ;
V_127 &= ~ V_139 ;
V_127 |= F_55 ( V_75 , V_140 ) ;
F_2 ( V_138 , V_127 ) ;
F_13 ( L_12 , V_127 ) ;
V_75 = F_46 ( clock , & V_141 ,
V_136 . V_109 ,
V_110 , V_53 -> V_142 ) ;
V_127 = F_3 ( V_70 ) ;
V_127 &= ~ V_143 ;
V_127 |= F_55 ( V_75 , V_144 ) ;
F_2 ( V_70 , V_127 ) ;
V_75 = F_46 ( clock , & V_145 ,
V_145 . V_109 ,
V_110 , V_53 -> V_146 ) ;
V_127 = F_3 ( V_70 ) ;
V_127 &= ~ V_147 ;
V_127 |= F_55 ( V_75 , V_148 ) ;
F_2 ( V_70 , V_127 ) ;
V_75 = F_46 ( clock , & V_149 ,
V_145 . V_109 ,
V_110 , V_53 -> V_150 ) ;
V_127 = F_3 ( V_70 ) ;
V_127 &= ~ V_151 ;
V_127 |= F_55 ( V_75 , V_152 ) ;
F_2 ( V_70 , V_127 ) ;
F_13 ( L_13 , V_127 ) ;
F_36 ( V_2 , true ) ;
} else {
F_36 ( V_2 , false ) ;
}
}
static bool F_56 ( struct V_1 * V_2 ,
int V_99 ,
const struct V_108 * V_153 ,
int V_154 ,
const struct V_108 * V_155 ,
int V_156 ,
int * V_157 ,
int * V_158 )
{
struct V_81 * V_82 ;
const struct V_128 * V_129 ;
const struct V_131 * V_123 ;
int V_159 , V_160 , clock , V_110 ;
int V_161 , V_162 ;
int V_163 , V_164 ;
V_82 = F_57 ( V_2 , V_99 ) ;
if ( ! F_52 ( V_82 ) ) {
* V_158 = V_155 -> V_115 ;
* V_157 = V_153 -> V_115 ;
return false ;
}
V_129 = & V_82 -> V_130 -> V_83 . V_129 ;
V_123 = V_82 -> V_83 . V_132 -> V_133 -> V_123 ;
clock = V_129 -> V_135 ;
V_159 = V_129 -> V_165 ;
V_160 = V_82 -> V_130 -> V_166 ;
V_110 = V_123 -> V_134 -> V_110 [ 0 ] ;
V_163 = ( ( clock * V_110 / 1000 ) * V_154 ) / 1000 ;
V_164 = V_153 -> V_109 * V_153 -> V_114 - V_160 * 8 ;
if ( V_164 > 0 )
V_163 += V_164 ;
V_163 = F_47 ( V_163 , V_153 -> V_114 ) ;
* V_157 = V_163 + V_153 -> V_115 ;
if ( * V_157 > ( int ) V_153 -> V_116 )
* V_157 = V_153 -> V_116 ;
V_161 = F_58 ( V_159 * 1000 / clock , 1 ) ;
V_162 = ( V_156 / V_161 + 1000 ) / 1000 ;
V_163 = V_162 * V_82 -> V_83 . V_155 -> V_133 -> V_167 * V_110 ;
V_164 = V_155 -> V_109 * V_155 -> V_114 - V_160 * 8 ;
if ( V_164 > 0 )
V_163 += V_164 ;
V_163 = F_47 ( V_163 , V_155 -> V_114 ) ;
* V_158 = V_163 + V_155 -> V_115 ;
if ( * V_158 > ( int ) V_155 -> V_116 )
* V_158 = ( int ) V_155 -> V_116 ;
return true ;
}
static bool F_59 ( struct V_1 * V_2 ,
int V_168 , int V_158 ,
const struct V_108 * V_153 ,
const struct V_108 * V_155 )
{
F_13 ( L_14 ,
V_168 , V_158 ) ;
if ( V_168 > V_153 -> V_116 ) {
F_13 ( L_15 ,
V_168 , V_153 -> V_116 ) ;
return false ;
}
if ( V_158 > V_155 -> V_116 ) {
F_13 ( L_16 ,
V_158 , V_155 -> V_116 ) ;
return false ;
}
if ( ! ( V_168 || V_158 ) ) {
F_13 ( L_17 ) ;
return false ;
}
return true ;
}
static bool F_60 ( struct V_1 * V_2 ,
int V_99 ,
int V_111 ,
const struct V_108 * V_153 ,
const struct V_108 * V_155 ,
int * V_168 , int * V_158 )
{
struct V_81 * V_82 ;
const struct V_128 * V_129 ;
const struct V_131 * V_123 ;
int V_160 , V_159 , V_110 , clock ;
unsigned long V_161 ;
int V_162 , V_169 ;
int V_170 , V_171 ;
int V_163 ;
if ( ! V_111 ) {
* V_168 = * V_158 = 0 ;
return false ;
}
V_82 = F_57 ( V_2 , V_99 ) ;
V_129 = & V_82 -> V_130 -> V_83 . V_129 ;
V_123 = V_82 -> V_83 . V_132 -> V_133 -> V_123 ;
clock = V_129 -> V_135 ;
V_159 = V_129 -> V_165 ;
V_160 = V_82 -> V_130 -> V_166 ;
V_110 = V_123 -> V_134 -> V_110 [ 0 ] ;
V_161 = F_58 ( V_159 * 1000 / clock , 1 ) ;
V_162 = ( V_111 / V_161 + 1000 ) / 1000 ;
V_169 = V_160 * V_110 ;
V_170 = ( ( clock * V_110 / 1000 ) * V_111 ) / 1000 ;
V_171 = V_162 * V_169 ;
V_163 = F_47 ( F_61 ( V_170 , V_171 ) , V_153 -> V_114 ) ;
* V_168 = V_163 + V_153 -> V_115 ;
V_163 = V_162 * V_110 * V_82 -> V_83 . V_155 -> V_133 -> V_167 ;
V_163 = F_47 ( V_163 , V_155 -> V_114 ) ;
* V_158 = V_163 + V_155 -> V_115 ;
return F_59 ( V_2 ,
* V_168 , * V_158 ,
V_153 , V_155 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
const struct V_172 * V_75 )
{
enum V_87 V_87 ;
F_63 (dev_priv, pipe) {
F_64 ( F_65 ( V_2 , V_87 ) , V_75 ) ;
F_2 ( F_66 ( V_87 ) ,
( V_75 -> V_173 [ V_87 ] . V_99 [ V_103 ] << V_174 ) |
( V_75 -> V_173 [ V_87 ] . V_99 [ V_102 ] << F_67 ( 1 ) ) |
( V_75 -> V_173 [ V_87 ] . V_99 [ V_101 ] << F_67 ( 0 ) ) |
( V_75 -> V_173 [ V_87 ] . V_99 [ V_100 ] << V_175 ) ) ;
}
F_2 ( V_176 , 0 ) ;
F_2 ( V_177 , 0 ) ;
F_2 ( V_178 , 0 ) ;
F_2 ( V_179 , 0 ) ;
F_2 ( V_180 , 0 ) ;
F_2 ( V_138 ,
F_55 ( V_75 -> V_181 . V_99 , V_140 ) |
F_55 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_103 ] , V_182 ) |
F_68 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_100 ] , V_183 ) |
F_68 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_100 ] , V_184 ) ) ;
F_2 ( V_185 ,
F_68 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_102 ] , V_186 ) |
F_55 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_103 ] , V_187 ) |
F_68 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_101 ] , V_188 ) ) ;
F_2 ( V_70 ,
F_55 ( V_75 -> V_181 . V_155 , V_144 ) ) ;
if ( F_24 ( V_2 ) ) {
F_2 ( V_189 ,
F_68 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_102 ] , V_190 ) |
F_68 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_101 ] , V_191 ) ) ;
F_2 ( V_192 ,
F_68 ( V_75 -> V_87 [ V_97 ] . V_99 [ V_102 ] , V_193 ) |
F_68 ( V_75 -> V_87 [ V_97 ] . V_99 [ V_101 ] , V_194 ) ) ;
F_2 ( V_195 ,
F_68 ( V_75 -> V_87 [ V_97 ] . V_99 [ V_100 ] , V_196 ) |
F_55 ( V_75 -> V_87 [ V_97 ] . V_99 [ V_103 ] , V_197 ) ) ;
F_2 ( V_176 ,
F_55 ( V_75 -> V_181 . V_99 >> 9 , V_198 ) |
F_55 ( V_75 -> V_87 [ V_97 ] . V_99 [ V_102 ] >> 8 , V_199 ) |
F_55 ( V_75 -> V_87 [ V_97 ] . V_99 [ V_101 ] >> 8 , V_200 ) |
F_55 ( V_75 -> V_87 [ V_97 ] . V_99 [ V_100 ] >> 8 , V_201 ) |
F_55 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_102 ] >> 8 , V_202 ) |
F_55 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_101 ] >> 8 , V_203 ) |
F_55 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_100 ] >> 8 , V_204 ) |
F_55 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_102 ] >> 8 , V_205 ) |
F_55 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_101 ] >> 8 , V_206 ) |
F_55 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_100 ] >> 8 , V_207 ) ) ;
} else {
F_2 ( V_208 ,
F_68 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_102 ] , V_190 ) |
F_68 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_101 ] , V_191 ) ) ;
F_2 ( V_176 ,
F_55 ( V_75 -> V_181 . V_99 >> 9 , V_198 ) |
F_55 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_102 ] >> 8 , V_202 ) |
F_55 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_101 ] >> 8 , V_203 ) |
F_55 ( V_75 -> V_87 [ V_96 ] . V_99 [ V_100 ] >> 8 , V_204 ) |
F_55 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_102 ] >> 8 , V_205 ) |
F_55 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_101 ] >> 8 , V_206 ) |
F_55 ( V_75 -> V_87 [ V_93 ] . V_99 [ V_100 ] >> 8 , V_207 ) ) ;
}
F_25 ( V_138 ) ;
}
static unsigned int F_69 ( unsigned int V_209 ,
unsigned int V_210 ,
unsigned int V_211 ,
unsigned int V_110 ,
unsigned int V_53 )
{
unsigned int V_74 ;
V_74 = ( V_53 * V_209 ) / ( V_210 * 10000 ) ;
V_74 = ( V_74 + 1 ) * V_211 * V_110 ;
V_74 = F_47 ( V_74 , 64 ) ;
return V_74 ;
}
static void F_70 ( struct V_1 * V_2 )
{
V_2 -> V_75 . V_212 [ V_213 ] = 3 ;
V_2 -> V_75 . V_214 = V_213 ;
if ( F_24 ( V_2 ) ) {
V_2 -> V_75 . V_212 [ V_215 ] = 12 ;
V_2 -> V_75 . V_212 [ V_216 ] = 33 ;
V_2 -> V_75 . V_214 = V_216 ;
}
}
static T_4 F_71 ( const struct V_79 * V_80 ,
const struct V_118 * V_119 ,
int V_217 )
{
struct V_120 * V_99 = F_49 ( V_119 -> V_83 . V_99 ) ;
struct V_1 * V_2 = F_39 ( V_99 -> V_83 . V_84 ) ;
const struct V_128 * V_129 =
& V_80 -> V_83 . V_129 ;
int clock , V_159 , V_110 , V_218 , V_75 ;
if ( V_2 -> V_75 . V_212 [ V_217 ] == 0 )
return V_219 ;
if ( ! V_119 -> V_83 . V_124 )
return 0 ;
V_110 = V_119 -> V_83 . V_123 -> V_134 -> V_110 [ 0 ] ;
clock = V_129 -> V_135 ;
V_159 = V_129 -> V_165 ;
V_218 = V_80 -> V_166 ;
if ( F_72 ( V_159 == 0 ) )
V_159 = 1 ;
if ( V_99 -> V_83 . type == V_220 ) {
V_75 = 63 ;
} else {
V_75 = F_69 ( clock , V_159 , V_218 , V_110 ,
V_2 -> V_75 . V_212 [ V_217 ] * 10 ) ;
}
return F_73 ( int , V_75 , V_219 ) ;
}
static bool F_74 ( unsigned int V_221 )
{
return ( V_221 & ( F_75 ( V_101 ) |
F_75 ( V_102 ) ) ) == F_75 ( V_102 ) ;
}
static int F_76 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_38 ( V_80 -> V_83 . V_82 ) ;
const struct V_222 * V_223 =
& V_80 -> V_75 . V_77 . V_223 [ V_213 ] ;
struct V_85 * V_86 = & V_80 -> V_75 . V_77 . V_86 ;
unsigned int V_221 = V_80 -> V_221 & ~ F_75 ( V_103 ) ;
int V_224 = F_77 ( V_221 ) ;
const int V_109 = 511 ;
int V_225 , V_226 = V_109 ;
int V_227 = 0 ;
unsigned int V_228 ;
enum V_229 V_229 ;
if ( F_74 ( V_221 ) )
V_227 = 1 ;
V_228 = V_223 -> V_99 [ V_100 ] +
V_223 -> V_99 [ V_101 ] +
V_223 -> V_99 [ V_102 ] +
V_227 ;
if ( V_228 > V_109 )
return - V_230 ;
if ( V_228 == 0 )
V_228 = 1 ;
F_78 (crtc, plane_id) {
unsigned int V_231 ;
if ( ( V_221 & F_75 ( V_229 ) ) == 0 ) {
V_86 -> V_99 [ V_229 ] = 0 ;
continue;
}
V_231 = V_223 -> V_99 [ V_229 ] ;
V_86 -> V_99 [ V_229 ] = V_109 * V_231 / V_228 ;
V_226 -= V_86 -> V_99 [ V_229 ] ;
}
V_86 -> V_99 [ V_101 ] += V_227 ;
V_226 -= V_227 ;
V_86 -> V_99 [ V_103 ] = 63 ;
V_225 = F_47 ( V_226 , V_224 ? : 1 ) ;
F_78 (crtc, plane_id) {
int V_232 ;
if ( V_226 == 0 )
break;
if ( ( V_221 & F_75 ( V_229 ) ) == 0 )
continue;
V_232 = F_61 ( V_225 , V_226 ) ;
V_86 -> V_99 [ V_229 ] += V_232 ;
V_226 -= V_232 ;
}
F_72 ( V_221 != 0 && V_226 != 0 ) ;
if ( V_221 == 0 ) {
F_72 ( V_226 != V_109 ) ;
V_86 -> V_99 [ V_100 ] = V_226 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
return V_2 -> V_75 . V_214 + 1 ;
}
static void F_80 ( struct V_81 * V_82 ,
struct V_233 * V_234 , int V_217 )
{
struct V_1 * V_2 = F_39 ( V_82 -> V_83 . V_84 ) ;
for (; V_217 < F_79 ( V_2 ) ; V_217 ++ ) {
enum V_229 V_229 ;
F_78 (crtc, plane_id)
V_234 -> V_75 [ V_217 ] . V_99 [ V_229 ] = V_219 ;
V_234 -> V_181 [ V_217 ] . V_155 = V_219 ;
V_234 -> V_181 [ V_217 ] . V_99 = V_219 ;
}
}
static T_2 F_81 ( T_2 V_75 , T_2 V_109 )
{
if ( V_75 > V_109 )
return V_219 ;
else
return V_109 - V_75 ;
}
static bool F_82 ( struct V_79 * V_80 ,
int V_217 , enum V_229 V_229 , T_2 V_235 )
{
struct V_1 * V_2 = F_39 ( V_80 -> V_83 . V_82 -> V_84 ) ;
int V_236 = F_79 ( V_2 ) ;
bool V_237 = false ;
for (; V_217 < V_236 ; V_217 ++ ) {
struct V_222 * V_223 = & V_80 -> V_75 . V_77 . V_223 [ V_217 ] ;
V_237 |= V_223 -> V_99 [ V_229 ] != V_235 ;
V_223 -> V_99 [ V_229 ] = V_235 ;
}
return V_237 ;
}
static bool F_83 ( struct V_79 * V_80 ,
const struct V_118 * V_119 )
{
struct V_120 * V_99 = F_49 ( V_119 -> V_83 . V_99 ) ;
enum V_229 V_229 = V_99 -> V_122 ;
int V_236 = F_79 ( F_39 ( V_99 -> V_83 . V_84 ) ) ;
int V_217 ;
bool V_237 = false ;
if ( ! V_119 -> V_83 . V_124 ) {
V_237 |= F_82 ( V_80 , 0 , V_229 , 0 ) ;
goto V_238;
}
for ( V_217 = 0 ; V_217 < V_236 ; V_217 ++ ) {
struct V_222 * V_223 = & V_80 -> V_75 . V_77 . V_223 [ V_217 ] ;
int V_75 = F_71 ( V_80 , V_119 , V_217 ) ;
int V_116 = V_229 == V_103 ? 63 : 511 ;
if ( V_75 > V_116 )
break;
V_237 |= V_223 -> V_99 [ V_229 ] != V_75 ;
V_223 -> V_99 [ V_229 ] = V_75 ;
}
V_237 |= F_82 ( V_80 , V_217 , V_229 , V_219 ) ;
V_238:
if ( V_237 )
F_13 ( L_18 ,
V_99 -> V_83 . V_239 ,
V_80 -> V_75 . V_77 . V_223 [ V_213 ] . V_99 [ V_229 ] ,
V_80 -> V_75 . V_77 . V_223 [ V_215 ] . V_99 [ V_229 ] ,
V_80 -> V_75 . V_77 . V_223 [ V_216 ] . V_99 [ V_229 ] ) ;
return V_237 ;
}
static bool F_84 ( const struct V_79 * V_80 ,
enum V_229 V_229 , int V_217 )
{
const struct V_222 * V_223 =
& V_80 -> V_75 . V_77 . V_223 [ V_217 ] ;
const struct V_85 * V_86 =
& V_80 -> V_75 . V_77 . V_86 ;
return V_223 -> V_99 [ V_229 ] <= V_86 -> V_99 [ V_229 ] ;
}
static bool F_85 ( const struct V_79 * V_80 , int V_217 )
{
return F_84 ( V_80 , V_100 , V_217 ) &&
F_84 ( V_80 , V_101 , V_217 ) &&
F_84 ( V_80 , V_102 , V_217 ) &&
F_84 ( V_80 , V_103 , V_217 ) ;
}
static int F_86 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_38 ( V_80 -> V_83 . V_82 ) ;
struct V_1 * V_2 = F_39 ( V_82 -> V_83 . V_84 ) ;
struct V_240 * V_133 =
F_87 ( V_80 -> V_83 . V_133 ) ;
struct V_233 * V_234 = & V_80 -> V_75 . V_77 . V_241 ;
const struct V_85 * V_86 =
& V_80 -> V_75 . V_77 . V_86 ;
int V_224 = F_77 ( V_80 -> V_221 &
~ F_75 ( V_103 ) ) ;
bool V_242 = F_88 ( & V_80 -> V_83 ) ;
struct V_118 * V_119 ;
struct V_120 * V_99 ;
enum V_229 V_229 ;
int V_217 , V_74 , V_54 ;
unsigned int V_237 = 0 ;
F_89 (state, plane, plane_state, i) {
const struct V_118 * V_243 =
F_90 ( V_99 -> V_83 . V_133 ) ;
if ( V_119 -> V_83 . V_82 != & V_82 -> V_83 &&
V_243 -> V_83 . V_82 != & V_82 -> V_83 )
continue;
if ( F_83 ( V_80 , V_119 ) )
V_237 |= F_75 ( V_99 -> V_122 ) ;
}
if ( V_242 )
V_80 -> V_244 = true ;
if ( ! V_237 )
return 0 ;
if ( V_237 & ~ F_75 ( V_103 ) ) {
const struct V_79 * V_245 =
F_91 ( V_82 -> V_83 . V_133 ) ;
const struct V_85 * V_246 =
& V_245 -> V_75 . V_77 . V_86 ;
V_74 = F_76 ( V_80 ) ;
if ( V_74 )
return V_74 ;
if ( V_242 ||
memcmp ( V_246 , V_86 ,
sizeof( * V_86 ) ) != 0 )
V_80 -> V_244 = true ;
}
V_234 -> V_236 = F_79 ( V_2 ) ;
V_234 -> V_78 = V_82 -> V_87 != V_97 && V_224 == 1 ;
for ( V_217 = 0 ; V_217 < V_234 -> V_236 ; V_217 ++ ) {
const struct V_222 * V_223 = & V_80 -> V_75 . V_77 . V_223 [ V_217 ] ;
const int V_247 = F_92 ( V_2 ) -> V_248 * 512 - 1 ;
if ( ! F_85 ( V_80 , V_217 ) )
break;
F_78 (crtc, plane_id) {
V_234 -> V_75 [ V_217 ] . V_99 [ V_229 ] =
F_81 ( V_223 -> V_99 [ V_229 ] ,
V_86 -> V_99 [ V_229 ] ) ;
}
V_234 -> V_181 [ V_217 ] . V_99 =
F_81 ( F_93 ( V_223 -> V_99 [ V_100 ] ,
V_223 -> V_99 [ V_101 ] ,
V_223 -> V_99 [ V_102 ] ) ,
V_247 ) ;
V_234 -> V_181 [ V_217 ] . V_155 =
F_81 ( V_223 -> V_99 [ V_103 ] ,
63 ) ;
}
if ( V_217 == 0 )
return - V_230 ;
V_234 -> V_236 = V_217 ;
F_80 ( V_82 , V_234 , V_217 ) ;
return 0 ;
}
static void F_94 ( struct V_240 * V_133 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = F_38 ( V_80 -> V_83 . V_82 ) ;
struct V_1 * V_2 = F_39 ( V_82 -> V_83 . V_84 ) ;
const struct V_85 * V_86 =
& V_80 -> V_75 . V_77 . V_86 ;
int V_88 , V_89 , V_109 ;
if ( ! V_80 -> V_244 )
return;
V_88 = V_86 -> V_99 [ V_100 ] ;
V_89 = V_86 -> V_99 [ V_101 ] + V_88 ;
V_109 = V_86 -> V_99 [ V_102 ] + V_89 ;
F_72 ( V_86 -> V_99 [ V_103 ] != 63 ) ;
F_72 ( V_109 != 511 ) ;
F_95 ( V_82 , V_88 , V_89 , V_109 ) ;
F_96 ( & V_2 -> V_249 . V_250 ) ;
switch ( V_82 -> V_87 ) {
T_3 V_90 , V_91 , V_92 ;
case V_93 :
V_90 = F_97 ( V_94 ) ;
V_91 = F_97 ( V_95 ) ;
V_90 &= ~ ( F_98 ( V_188 , 0xff ) |
F_98 ( V_186 , 0xff ) ) ;
V_90 |= ( F_98 ( V_188 , V_88 ) |
F_98 ( V_186 , V_89 ) ) ;
V_91 &= ~ ( F_98 ( V_206 , 0x1 ) |
F_98 ( V_205 , 0x1 ) ) ;
V_91 |= ( F_98 ( V_206 , V_88 >> 8 ) |
F_98 ( V_205 , V_89 >> 8 ) ) ;
F_99 ( V_94 , V_90 ) ;
F_99 ( V_95 , V_91 ) ;
break;
case V_96 :
V_90 = F_97 ( V_94 ) ;
V_91 = F_97 ( V_95 ) ;
V_90 &= ~ ( F_98 ( V_191 , 0xff ) |
F_98 ( V_190 , 0xff ) ) ;
V_90 |= ( F_98 ( V_191 , V_88 ) |
F_98 ( V_190 , V_89 ) ) ;
V_91 &= ~ ( F_98 ( V_203 , 0xff ) |
F_98 ( V_202 , 0xff ) ) ;
V_91 |= ( F_98 ( V_203 , V_88 >> 8 ) |
F_98 ( V_202 , V_89 >> 8 ) ) ;
F_99 ( V_94 , V_90 ) ;
F_99 ( V_95 , V_91 ) ;
break;
case V_97 :
V_92 = F_97 ( V_98 ) ;
V_91 = F_97 ( V_95 ) ;
V_92 &= ~ ( F_98 ( V_194 , 0xff ) |
F_98 ( V_193 , 0xff ) ) ;
V_92 |= ( F_98 ( V_194 , V_88 ) |
F_98 ( V_193 , V_89 ) ) ;
V_91 &= ~ ( F_98 ( V_200 , 0xff ) |
F_98 ( V_199 , 0xff ) ) ;
V_91 |= ( F_98 ( V_200 , V_88 >> 8 ) |
F_98 ( V_199 , V_89 >> 8 ) ) ;
F_99 ( V_98 , V_92 ) ;
F_99 ( V_95 , V_91 ) ;
break;
default:
break;
}
F_100 ( V_94 ) ;
F_101 ( & V_2 -> V_249 . V_250 ) ;
}
static int F_102 ( struct V_251 * V_84 ,
struct V_81 * V_82 ,
struct V_79 * V_80 )
{
struct V_233 * V_252 = & V_80 -> V_75 . V_77 . V_252 ;
const struct V_233 * V_241 = & V_80 -> V_75 . V_77 . V_241 ;
const struct V_233 * V_121 = & V_82 -> V_75 . V_121 . V_77 ;
int V_217 ;
V_252 -> V_236 = F_61 ( V_241 -> V_236 , V_121 -> V_236 ) ;
V_252 -> V_78 = V_241 -> V_78 && V_121 -> V_78 &&
! V_80 -> V_253 ;
for ( V_217 = 0 ; V_217 < V_252 -> V_236 ; V_217 ++ ) {
enum V_229 V_229 ;
F_78 (crtc, plane_id) {
V_252 -> V_75 [ V_217 ] . V_99 [ V_229 ] =
F_61 ( V_241 -> V_75 [ V_217 ] . V_99 [ V_229 ] ,
V_121 -> V_75 [ V_217 ] . V_99 [ V_229 ] ) ;
}
V_252 -> V_181 [ V_217 ] . V_99 = F_61 ( V_241 -> V_181 [ V_217 ] . V_99 ,
V_121 -> V_181 [ V_217 ] . V_99 ) ;
V_252 -> V_181 [ V_217 ] . V_155 = F_61 ( V_241 -> V_181 [ V_217 ] . V_155 ,
V_121 -> V_181 [ V_217 ] . V_155 ) ;
}
F_80 ( V_82 , V_252 , V_217 ) ;
if ( memcmp ( V_252 , V_241 , sizeof( * V_252 ) ) != 0 )
V_80 -> V_75 . V_254 = true ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_172 * V_75 )
{
struct V_81 * V_82 ;
int V_255 = 0 ;
V_75 -> V_217 = V_2 -> V_75 . V_214 ;
V_75 -> V_78 = true ;
F_51 (&dev_priv->drm, crtc) {
const struct V_233 * V_234 = & V_82 -> V_75 . V_121 . V_77 ;
if ( ! V_82 -> V_121 )
continue;
if ( ! V_234 -> V_78 )
V_75 -> V_78 = false ;
V_255 ++ ;
V_75 -> V_217 = F_73 ( int , V_75 -> V_217 , V_234 -> V_236 - 1 ) ;
}
if ( V_255 != 1 )
V_75 -> V_78 = false ;
if ( V_255 > 1 )
V_75 -> V_217 = V_213 ;
F_51 (&dev_priv->drm, crtc) {
const struct V_233 * V_234 = & V_82 -> V_75 . V_121 . V_77 ;
enum V_87 V_87 = V_82 -> V_87 ;
V_75 -> V_87 [ V_87 ] = V_234 -> V_75 [ V_75 -> V_217 ] ;
if ( V_82 -> V_121 && V_75 -> V_78 )
V_75 -> V_181 = V_234 -> V_181 [ V_75 -> V_217 ] ;
V_75 -> V_173 [ V_87 ] . V_99 [ V_100 ] = V_256 | 2 ;
V_75 -> V_173 [ V_87 ] . V_99 [ V_101 ] = V_256 | 2 ;
V_75 -> V_173 [ V_87 ] . V_99 [ V_102 ] = V_256 | 2 ;
V_75 -> V_173 [ V_87 ] . V_99 [ V_103 ] = V_256 | 2 ;
}
}
static bool F_104 ( int V_257 , int V_258 , int V_259 )
{
return V_257 >= V_259 && V_258 < V_259 ;
}
static bool F_105 ( int V_257 , int V_258 , int V_259 )
{
return V_257 < V_259 && V_258 >= V_259 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_172 * V_260 = & V_2 -> V_75 . V_77 ;
struct V_172 V_261 = {} ;
F_103 ( V_2 , & V_261 ) ;
if ( memcmp ( V_260 , & V_261 , sizeof( V_261 ) ) == 0 )
return;
if ( F_104 ( V_260 -> V_217 , V_261 . V_217 , V_216 ) )
F_14 ( V_2 , false ) ;
if ( F_104 ( V_260 -> V_217 , V_261 . V_217 , V_215 ) )
F_21 ( V_2 , false ) ;
if ( F_104 ( V_260 -> V_78 , V_261 . V_78 , true ) )
F_22 ( V_2 , false ) ;
F_62 ( V_2 , & V_261 ) ;
if ( F_105 ( V_260 -> V_78 , V_261 . V_78 , true ) )
F_22 ( V_2 , true ) ;
if ( F_105 ( V_260 -> V_217 , V_261 . V_217 , V_215 ) )
F_21 ( V_2 , true ) ;
if ( F_105 ( V_260 -> V_217 , V_261 . V_217 , V_216 ) )
F_14 ( V_2 , true ) ;
* V_260 = V_261 ;
}
static void F_107 ( struct V_240 * V_133 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_39 ( V_80 -> V_83 . V_82 -> V_84 ) ;
struct V_81 * V_82 = F_38 ( V_80 -> V_83 . V_82 ) ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_82 -> V_75 . V_121 . V_77 = V_80 -> V_75 . V_77 . V_252 ;
F_106 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_108 ( struct V_240 * V_133 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_39 ( V_80 -> V_83 . V_82 -> V_84 ) ;
struct V_81 * V_81 = F_38 ( V_80 -> V_83 . V_82 ) ;
if ( ! V_80 -> V_75 . V_254 )
return;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_81 -> V_75 . V_121 . V_77 = V_80 -> V_75 . V_77 . V_241 ;
F_106 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_109 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_39 ( V_82 -> V_83 . V_84 ) ;
static const int V_262 = 12000 ;
int V_263 , V_264 , V_265 , V_266 ;
int V_267 , V_142 ;
unsigned int V_125 = 0 ;
bool V_268 ;
if ( F_56 ( V_2 , V_93 ,
& V_269 , V_270 ,
& V_271 , V_270 ,
& V_263 , & V_265 ) )
V_125 |= 1 << V_93 ;
if ( F_56 ( V_2 , V_96 ,
& V_269 , V_270 ,
& V_271 , V_270 ,
& V_264 , & V_266 ) )
V_125 |= 1 << V_96 ;
if ( F_110 ( V_125 ) &&
F_60 ( V_2 , F_111 ( V_125 ) - 1 ,
V_262 ,
& V_269 ,
& V_271 ,
& V_267 , & V_142 ) ) {
V_268 = true ;
} else {
V_268 = false ;
F_36 ( V_2 , false ) ;
V_267 = V_142 = 0 ;
}
F_13 ( L_19
L_20 ,
V_263 , V_265 ,
V_264 , V_266 ,
V_267 , V_142 ) ;
F_2 ( V_138 ,
F_55 ( V_267 , V_140 ) |
F_55 ( V_266 , V_182 ) |
F_55 ( V_264 , V_183 ) |
F_55 ( V_263 , V_184 ) ) ;
F_2 ( V_185 ,
( F_3 ( V_185 ) & ~ V_272 ) |
F_55 ( V_265 , V_187 ) ) ;
F_2 ( V_70 ,
( F_3 ( V_70 ) & ~ ( V_273 | V_143 ) ) |
F_55 ( V_142 , V_144 ) ) ;
if ( V_268 )
F_36 ( V_2 , true ) ;
}
static void F_112 ( struct V_81 * V_126 )
{
struct V_1 * V_2 = F_39 ( V_126 -> V_83 . V_84 ) ;
struct V_81 * V_82 ;
int V_274 = 1 ;
int V_142 = 16 ;
bool V_268 ;
V_82 = F_50 ( V_2 ) ;
if ( V_82 ) {
static const int V_262 = 12000 ;
const struct V_128 * V_129 =
& V_82 -> V_130 -> V_83 . V_129 ;
const struct V_131 * V_123 =
V_82 -> V_83 . V_132 -> V_133 -> V_123 ;
int clock = V_129 -> V_135 ;
int V_159 = V_129 -> V_165 ;
int V_160 = V_82 -> V_130 -> V_166 ;
int V_110 = V_123 -> V_134 -> V_110 [ 0 ] ;
unsigned long V_161 ;
int V_163 ;
V_161 = F_58 ( V_159 * 1000 / clock , 1 ) ;
V_163 = ( ( ( V_262 / V_161 ) + 1000 ) / 1000 ) *
V_110 * V_160 ;
V_163 = F_47 ( V_163 , V_275 ) ;
V_274 = V_276 - V_163 ;
if ( V_274 < 0 )
V_274 = 1 ;
V_274 &= 0x1ff ;
F_13 ( L_21 ,
V_163 , V_274 ) ;
V_163 = ( ( ( V_262 / V_161 ) + 1000 ) / 1000 ) *
V_110 * V_82 -> V_83 . V_155 -> V_133 -> V_167 ;
V_163 = F_47 ( V_163 ,
V_277 . V_114 ) ;
V_142 = V_277 . V_109 -
( V_163 + V_277 . V_115 ) ;
if ( V_142 > V_277 . V_116 )
V_142 = V_277 . V_116 ;
F_13 ( L_22
L_23 , V_274 , V_142 ) ;
V_268 = true ;
} else {
V_268 = false ;
F_36 ( V_2 , false ) ;
}
F_13 ( L_24 ,
V_274 ) ;
F_2 ( V_138 , F_55 ( V_274 , V_140 ) |
F_55 ( 8 , V_182 ) |
F_55 ( 8 , V_183 ) |
F_55 ( 8 , V_184 ) ) ;
F_2 ( V_185 , F_55 ( 8 , V_187 ) |
F_55 ( 8 , V_278 ) ) ;
F_2 ( V_70 , F_55 ( V_142 , V_144 ) ) ;
if ( V_268 )
F_36 ( V_2 , true ) ;
}
static void F_113 ( struct V_81 * V_126 )
{
struct V_1 * V_2 = F_39 ( V_126 -> V_83 . V_84 ) ;
const struct V_108 * V_279 ;
T_3 V_280 ;
T_3 V_281 ;
int V_282 , V_274 = 1 ;
int V_109 ;
int V_263 , V_264 ;
struct V_81 * V_82 , * V_125 = NULL ;
if ( F_30 ( V_2 ) )
V_279 = & V_283 ;
else if ( ! F_114 ( V_2 ) )
V_279 = & V_284 ;
else
V_279 = & V_285 ;
V_109 = V_2 -> V_153 . V_286 ( V_2 , 0 ) ;
V_82 = F_57 ( V_2 , 0 ) ;
if ( F_52 ( V_82 ) ) {
const struct V_128 * V_129 =
& V_82 -> V_130 -> V_83 . V_129 ;
const struct V_131 * V_123 =
V_82 -> V_83 . V_132 -> V_133 -> V_123 ;
int V_110 ;
if ( F_114 ( V_2 ) )
V_110 = 4 ;
else
V_110 = V_123 -> V_134 -> V_110 [ 0 ] ;
V_263 = F_46 ( V_129 -> V_135 ,
V_279 , V_109 , V_110 ,
V_270 ) ;
V_125 = V_82 ;
} else {
V_263 = V_109 - V_279 -> V_115 ;
if ( V_263 > ( long ) V_279 -> V_116 )
V_263 = V_279 -> V_116 ;
}
if ( F_114 ( V_2 ) )
V_279 = & V_287 ;
V_109 = V_2 -> V_153 . V_286 ( V_2 , 1 ) ;
V_82 = F_57 ( V_2 , 1 ) ;
if ( F_52 ( V_82 ) ) {
const struct V_128 * V_129 =
& V_82 -> V_130 -> V_83 . V_129 ;
const struct V_131 * V_123 =
V_82 -> V_83 . V_132 -> V_133 -> V_123 ;
int V_110 ;
if ( F_114 ( V_2 ) )
V_110 = 4 ;
else
V_110 = V_123 -> V_134 -> V_110 [ 0 ] ;
V_264 = F_46 ( V_129 -> V_135 ,
V_279 , V_109 , V_110 ,
V_270 ) ;
if ( V_125 == NULL )
V_125 = V_82 ;
else
V_125 = NULL ;
} else {
V_264 = V_109 - V_279 -> V_115 ;
if ( V_264 > ( long ) V_279 -> V_116 )
V_264 = V_279 -> V_116 ;
}
F_13 ( L_25 , V_263 , V_264 ) ;
if ( F_33 ( V_2 ) && V_125 ) {
struct V_288 * V_289 ;
V_289 = F_115 ( V_125 -> V_83 . V_132 -> V_133 -> V_123 ) ;
if ( ! F_116 ( V_289 ) )
V_125 = NULL ;
}
V_282 = 2 ;
F_36 ( V_2 , false ) ;
if ( F_117 ( V_2 ) && V_125 ) {
static const int V_262 = 6000 ;
const struct V_128 * V_129 =
& V_125 -> V_130 -> V_83 . V_129 ;
const struct V_131 * V_123 =
V_125 -> V_83 . V_132 -> V_133 -> V_123 ;
int clock = V_129 -> V_135 ;
int V_159 = V_129 -> V_165 ;
int V_160 = V_125 -> V_130 -> V_166 ;
int V_110 ;
unsigned long V_161 ;
int V_163 ;
if ( F_33 ( V_2 ) || F_30 ( V_2 ) )
V_110 = 4 ;
else
V_110 = V_123 -> V_134 -> V_110 [ 0 ] ;
V_161 = F_58 ( V_159 * 1000 / clock , 1 ) ;
V_163 = ( ( ( V_262 / V_161 ) + 1000 ) / 1000 ) *
V_110 * V_160 ;
V_163 = F_47 ( V_163 , V_279 -> V_114 ) ;
F_13 ( L_26 , V_163 ) ;
V_274 = V_279 -> V_109 - V_163 ;
if ( V_274 < 0 )
V_274 = 1 ;
if ( F_29 ( V_2 ) || F_30 ( V_2 ) )
F_2 ( V_68 ,
V_290 | ( V_274 & 0xff ) ) ;
else
F_2 ( V_68 , V_274 & 0x3f ) ;
}
F_13 ( L_27 ,
V_263 , V_264 , V_282 , V_274 ) ;
V_280 = ( ( V_264 & 0x3f ) << 16 ) | ( V_263 & 0x3f ) ;
V_281 = ( V_282 & 0x1f ) ;
V_280 = V_280 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_281 = V_281 | ( 1 << 8 ) ;
F_2 ( V_291 , V_280 ) ;
F_2 ( V_292 , V_281 ) ;
if ( V_125 )
F_36 ( V_2 , true ) ;
}
static void F_118 ( struct V_81 * V_126 )
{
struct V_1 * V_2 = F_39 ( V_126 -> V_83 . V_84 ) ;
struct V_81 * V_82 ;
const struct V_128 * V_129 ;
T_3 V_280 ;
int V_263 ;
V_82 = F_50 ( V_2 ) ;
if ( V_82 == NULL )
return;
V_129 = & V_82 -> V_130 -> V_83 . V_129 ;
V_263 = F_46 ( V_129 -> V_135 ,
& V_293 ,
V_2 -> V_153 . V_286 ( V_2 , 0 ) ,
4 , V_270 ) ;
V_280 = F_3 ( V_291 ) & ~ 0xfff ;
V_280 |= ( 3 << 8 ) | V_263 ;
F_13 ( L_28 , V_263 ) ;
F_2 ( V_291 , V_280 ) ;
}
static T_3 F_119 ( T_3 V_209 , T_5 V_110 , T_3 V_53 )
{
T_6 V_74 ;
if ( F_120 ( V_53 == 0 , L_29 ) )
return V_294 ;
V_74 = ( T_6 ) V_209 * V_110 * V_53 ;
V_74 = F_121 ( V_74 , 64 * 10000 ) + 2 ;
return V_74 ;
}
static T_3 F_122 ( T_3 V_209 , T_3 V_210 ,
T_3 V_211 , T_5 V_110 ,
T_3 V_53 )
{
T_3 V_74 ;
if ( F_120 ( V_53 == 0 , L_29 ) )
return V_294 ;
if ( F_72 ( ! V_210 ) )
return V_294 ;
V_74 = ( V_53 * V_209 ) / ( V_210 * 10000 ) ;
V_74 = ( V_74 + 1 ) * V_211 * V_110 ;
V_74 = F_47 ( V_74 , 64 ) + 2 ;
return V_74 ;
}
static T_3 F_123 ( T_3 V_295 , T_3 V_211 ,
T_5 V_110 )
{
if ( F_72 ( ! V_110 ) )
return 0 ;
if ( F_72 ( ! V_211 ) )
return 0 ;
return F_47 ( V_295 * 64 , V_211 * V_110 ) + 2 ;
}
static T_3 F_124 ( const struct V_79 * V_296 ,
const struct V_118 * V_297 ,
T_3 V_298 ,
bool V_299 )
{
T_3 V_300 , V_301 ;
int V_110 ;
if ( ! F_48 ( V_296 , V_297 ) )
return 0 ;
V_110 = V_297 -> V_83 . V_123 -> V_134 -> V_110 [ 0 ] ;
V_300 = F_119 ( V_296 -> V_209 , V_110 , V_298 ) ;
if ( ! V_299 )
return V_300 ;
V_301 = F_122 ( V_296 -> V_209 ,
V_296 -> V_83 . V_129 . V_165 ,
F_125 ( & V_297 -> V_83 . V_302 ) ,
V_110 , V_298 ) ;
return F_61 ( V_300 , V_301 ) ;
}
static T_3 F_126 ( const struct V_79 * V_296 ,
const struct V_118 * V_297 ,
T_3 V_298 )
{
T_3 V_300 , V_301 ;
int V_110 ;
if ( ! F_48 ( V_296 , V_297 ) )
return 0 ;
V_110 = V_297 -> V_83 . V_123 -> V_134 -> V_110 [ 0 ] ;
V_300 = F_119 ( V_296 -> V_209 , V_110 , V_298 ) ;
V_301 = F_122 ( V_296 -> V_209 ,
V_296 -> V_83 . V_129 . V_165 ,
F_125 ( & V_297 -> V_83 . V_302 ) ,
V_110 , V_298 ) ;
return F_61 ( V_300 , V_301 ) ;
}
static T_3 F_127 ( const struct V_79 * V_296 ,
const struct V_118 * V_297 ,
T_3 V_298 )
{
int V_110 ;
if ( ! F_48 ( V_296 , V_297 ) )
return 0 ;
V_110 = V_297 -> V_83 . V_123 -> V_134 -> V_110 [ 0 ] ;
return F_122 ( V_296 -> V_209 ,
V_296 -> V_83 . V_129 . V_165 ,
V_297 -> V_83 . V_167 , V_110 , V_298 ) ;
}
static T_3 F_128 ( const struct V_79 * V_296 ,
const struct V_118 * V_297 ,
T_3 V_295 )
{
int V_110 ;
if ( ! F_48 ( V_296 , V_297 ) )
return 0 ;
V_110 = V_297 -> V_83 . V_123 -> V_134 -> V_110 [ 0 ] ;
return F_123 ( V_295 , F_125 ( & V_297 -> V_83 . V_302 ) , V_110 ) ;
}
static unsigned int
F_129 ( const struct V_1 * V_2 )
{
if ( F_130 ( V_2 ) >= 8 )
return 3072 ;
else if ( F_130 ( V_2 ) >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int
F_131 ( const struct V_1 * V_2 ,
int V_217 , bool V_303 )
{
if ( F_130 ( V_2 ) >= 8 )
return V_217 == 0 ? 255 : 2047 ;
else if ( F_130 ( V_2 ) >= 7 )
return V_217 == 0 ? 127 : 1023 ;
else if ( ! V_303 )
return V_217 == 0 ? 127 : 511 ;
else
return V_217 == 0 ? 63 : 255 ;
}
static unsigned int
F_132 ( const struct V_1 * V_2 , int V_217 )
{
if ( F_130 ( V_2 ) >= 7 )
return V_217 == 0 ? 63 : 255 ;
else
return V_217 == 0 ? 31 : 63 ;
}
static unsigned int F_133 ( const struct V_1 * V_2 )
{
if ( F_130 ( V_2 ) >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_134 ( const struct V_251 * V_84 ,
int V_217 ,
const struct V_304 * V_130 ,
enum V_305 V_306 ,
bool V_303 )
{
struct V_1 * V_2 = F_39 ( V_84 ) ;
unsigned int V_109 = F_129 ( V_2 ) ;
if ( V_303 && ! V_130 -> V_307 )
return 0 ;
if ( V_217 == 0 || V_130 -> V_308 > 1 ) {
V_109 /= F_92 ( V_2 ) -> V_248 ;
if ( F_130 ( V_2 ) <= 6 )
V_109 /= 2 ;
}
if ( V_130 -> V_307 ) {
if ( V_217 > 0 && V_306 == V_309 ) {
if ( V_303 )
V_109 *= 5 ;
V_109 /= 6 ;
} else {
V_109 /= 2 ;
}
}
return F_61 ( V_109 , F_131 ( V_2 , V_217 , V_303 ) ) ;
}
static unsigned int F_135 ( const struct V_251 * V_84 ,
int V_217 ,
const struct V_304 * V_130 )
{
if ( V_217 > 0 && V_130 -> V_308 > 1 )
return 64 ;
return F_132 ( F_39 ( V_84 ) , V_217 ) ;
}
static void F_136 ( const struct V_251 * V_84 ,
int V_217 ,
const struct V_304 * V_130 ,
enum V_305 V_306 ,
struct V_310 * F_58 )
{
F_58 -> V_311 = F_134 ( V_84 , V_217 , V_130 , V_306 , false ) ;
F_58 -> V_312 = F_134 ( V_84 , V_217 , V_130 , V_306 , true ) ;
F_58 -> V_313 = F_135 ( V_84 , V_217 , V_130 ) ;
F_58 -> V_314 = F_133 ( F_39 ( V_84 ) ) ;
}
static void F_137 ( const struct V_1 * V_2 ,
int V_217 ,
struct V_310 * F_58 )
{
F_58 -> V_311 = F_131 ( V_2 , V_217 , false ) ;
F_58 -> V_312 = F_131 ( V_2 , V_217 , true ) ;
F_58 -> V_313 = F_132 ( V_2 , V_217 ) ;
F_58 -> V_314 = F_133 ( V_2 ) ;
}
static bool F_138 ( int V_217 ,
const struct V_310 * F_58 ,
struct V_315 * V_316 )
{
bool V_74 ;
if ( ! V_316 -> V_56 )
return false ;
V_316 -> V_56 = V_316 -> V_295 <= F_58 -> V_311 &&
V_316 -> V_317 <= F_58 -> V_312 &&
V_316 -> V_318 <= F_58 -> V_313 ;
V_74 = V_316 -> V_56 ;
if ( V_217 == 0 && ! V_316 -> V_56 ) {
if ( V_316 -> V_295 > F_58 -> V_311 )
F_13 ( L_30 ,
V_217 , V_316 -> V_295 , F_58 -> V_311 ) ;
if ( V_316 -> V_317 > F_58 -> V_312 )
F_13 ( L_31 ,
V_217 , V_316 -> V_317 , F_58 -> V_312 ) ;
if ( V_316 -> V_318 > F_58 -> V_313 )
F_13 ( L_32 ,
V_217 , V_316 -> V_318 , F_58 -> V_313 ) ;
V_316 -> V_295 = F_73 ( T_3 , V_316 -> V_295 , F_58 -> V_311 ) ;
V_316 -> V_317 = F_73 ( T_3 , V_316 -> V_317 , F_58 -> V_312 ) ;
V_316 -> V_318 = F_73 ( T_3 , V_316 -> V_318 , F_58 -> V_313 ) ;
V_316 -> V_56 = true ;
}
return V_74 ;
}
static void F_139 ( const struct V_1 * V_2 ,
const struct V_81 * V_81 ,
int V_217 ,
struct V_79 * V_296 ,
struct V_118 * V_319 ,
struct V_118 * V_320 ,
struct V_118 * V_321 ,
struct V_315 * V_316 )
{
T_4 V_212 = V_2 -> V_75 . V_212 [ V_217 ] ;
T_4 V_322 = V_2 -> V_75 . V_322 [ V_217 ] ;
T_4 V_323 = V_2 -> V_75 . V_323 [ V_217 ] ;
if ( V_217 > 0 ) {
V_212 *= 5 ;
V_322 *= 5 ;
V_323 *= 5 ;
}
if ( V_319 ) {
V_316 -> V_295 = F_124 ( V_296 , V_319 ,
V_212 , V_217 ) ;
V_316 -> V_324 = F_128 ( V_296 , V_319 , V_316 -> V_295 ) ;
}
if ( V_320 )
V_316 -> V_317 = F_126 ( V_296 , V_320 , V_322 ) ;
if ( V_321 )
V_316 -> V_318 = F_127 ( V_296 , V_321 , V_323 ) ;
V_316 -> V_56 = true ;
}
static T_3
F_140 ( const struct V_79 * V_296 )
{
const struct V_240 * V_325 =
F_87 ( V_296 -> V_83 . V_133 ) ;
const struct V_128 * V_129 =
& V_296 -> V_83 . V_129 ;
T_1 V_326 , V_327 ;
if ( ! V_296 -> V_83 . V_121 )
return 0 ;
if ( F_72 ( V_129 -> V_135 == 0 ) )
return 0 ;
if ( F_72 ( V_325 -> V_328 . V_329 . V_328 == 0 ) )
return 0 ;
V_326 = F_141 ( V_129 -> V_165 * 1000 * 8 ,
V_129 -> V_135 ) ;
V_327 = F_141 ( V_129 -> V_165 * 1000 * 8 ,
V_325 -> V_328 . V_329 . V_328 ) ;
return F_142 ( V_327 ) |
F_143 ( V_326 ) ;
}
static void F_144 ( struct V_1 * V_2 ,
T_4 V_75 [ 8 ] )
{
if ( F_145 ( V_2 ) ) {
T_3 V_21 ;
int V_74 , V_54 ;
int V_217 , V_214 = F_146 ( V_2 ) ;
V_21 = 0 ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_74 = F_147 ( V_2 ,
V_330 ,
& V_21 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
if ( V_74 ) {
F_19 ( L_33 , V_74 ) ;
return;
}
V_75 [ 0 ] = V_21 & V_331 ;
V_75 [ 1 ] = ( V_21 >> V_332 ) &
V_331 ;
V_75 [ 2 ] = ( V_21 >> V_333 ) &
V_331 ;
V_75 [ 3 ] = ( V_21 >> V_334 ) &
V_331 ;
V_21 = 1 ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_74 = F_147 ( V_2 ,
V_330 ,
& V_21 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
if ( V_74 ) {
F_19 ( L_33 , V_74 ) ;
return;
}
V_75 [ 4 ] = V_21 & V_331 ;
V_75 [ 5 ] = ( V_21 >> V_332 ) &
V_331 ;
V_75 [ 6 ] = ( V_21 >> V_333 ) &
V_331 ;
V_75 [ 7 ] = ( V_21 >> V_334 ) &
V_331 ;
for ( V_217 = 1 ; V_217 <= V_214 ; V_217 ++ ) {
if ( V_75 [ V_217 ] == 0 ) {
for ( V_54 = V_217 + 1 ; V_54 <= V_214 ; V_54 ++ )
V_75 [ V_54 ] = 0 ;
break;
}
}
if ( V_75 [ 0 ] == 0 ) {
V_75 [ 0 ] += 2 ;
for ( V_217 = 1 ; V_217 <= V_214 ; V_217 ++ ) {
if ( V_75 [ V_217 ] == 0 )
break;
V_75 [ V_217 ] += 2 ;
}
}
} else if ( F_148 ( V_2 ) || F_149 ( V_2 ) ) {
T_6 V_335 = F_150 ( V_336 ) ;
V_75 [ 0 ] = ( V_335 >> 56 ) & 0xFF ;
if ( V_75 [ 0 ] == 0 )
V_75 [ 0 ] = V_335 & 0xF ;
V_75 [ 1 ] = ( V_335 >> 4 ) & 0xFF ;
V_75 [ 2 ] = ( V_335 >> 12 ) & 0xFF ;
V_75 [ 3 ] = ( V_335 >> 20 ) & 0x1FF ;
V_75 [ 4 ] = ( V_335 >> 32 ) & 0x1FF ;
} else if ( F_130 ( V_2 ) >= 6 ) {
T_3 V_335 = F_3 ( V_336 ) ;
V_75 [ 0 ] = ( V_335 >> V_337 ) & V_338 ;
V_75 [ 1 ] = ( V_335 >> V_339 ) & V_338 ;
V_75 [ 2 ] = ( V_335 >> V_340 ) & V_338 ;
V_75 [ 3 ] = ( V_335 >> V_341 ) & V_338 ;
} else if ( F_130 ( V_2 ) >= 5 ) {
T_3 V_342 = F_3 ( V_343 ) ;
V_75 [ 0 ] = 7 ;
V_75 [ 1 ] = ( V_342 >> V_344 ) & V_345 ;
V_75 [ 2 ] = ( V_342 >> V_346 ) & V_345 ;
}
}
static void F_151 ( struct V_1 * V_2 ,
T_4 V_75 [ 5 ] )
{
if ( F_152 ( V_2 ) )
V_75 [ 0 ] = 13 ;
}
static void F_153 ( struct V_1 * V_2 ,
T_4 V_75 [ 5 ] )
{
if ( F_152 ( V_2 ) )
V_75 [ 0 ] = 13 ;
if ( F_154 ( V_2 ) )
V_75 [ 3 ] *= 2 ;
}
int F_146 ( const struct V_1 * V_2 )
{
if ( F_130 ( V_2 ) >= 9 )
return 7 ;
else if ( F_148 ( V_2 ) || F_149 ( V_2 ) )
return 4 ;
else if ( F_130 ( V_2 ) >= 6 )
return 3 ;
else
return 2 ;
}
static void F_155 ( struct V_1 * V_2 ,
const char * V_239 ,
const T_4 V_75 [ 8 ] )
{
int V_217 , V_214 = F_146 ( V_2 ) ;
for ( V_217 = 0 ; V_217 <= V_214 ; V_217 ++ ) {
unsigned int V_53 = V_75 [ V_217 ] ;
if ( V_53 == 0 ) {
F_19 ( L_34 ,
V_239 , V_217 ) ;
continue;
}
if ( F_145 ( V_2 ) )
V_53 *= 10 ;
else if ( V_217 > 0 )
V_53 *= 5 ;
F_13 ( L_35 ,
V_239 , V_217 , V_75 [ V_217 ] ,
V_53 / 10 , V_53 % 10 ) ;
}
}
static bool F_156 ( struct V_1 * V_2 ,
T_4 V_75 [ 5 ] , T_4 F_61 )
{
int V_217 , V_214 = F_146 ( V_2 ) ;
if ( V_75 [ 0 ] >= F_61 )
return false ;
V_75 [ 0 ] = F_58 ( V_75 [ 0 ] , F_61 ) ;
for ( V_217 = 1 ; V_217 <= V_214 ; V_217 ++ )
V_75 [ V_217 ] = F_157 ( T_4 , V_75 [ V_217 ] , F_47 ( F_61 , 5 ) ) ;
return true ;
}
static void F_158 ( struct V_1 * V_2 )
{
bool V_347 ;
V_347 = F_156 ( V_2 , V_2 -> V_75 . V_212 , 12 ) |
F_156 ( V_2 , V_2 -> V_75 . V_322 , 12 ) |
F_156 ( V_2 , V_2 -> V_75 . V_323 , 12 ) ;
if ( ! V_347 )
return;
F_13 ( L_36 ) ;
F_155 ( V_2 , L_37 , V_2 -> V_75 . V_212 ) ;
F_155 ( V_2 , L_38 , V_2 -> V_75 . V_322 ) ;
F_155 ( V_2 , L_39 , V_2 -> V_75 . V_323 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_144 ( V_2 , V_2 -> V_75 . V_212 ) ;
memcpy ( V_2 -> V_75 . V_322 , V_2 -> V_75 . V_212 ,
sizeof( V_2 -> V_75 . V_212 ) ) ;
memcpy ( V_2 -> V_75 . V_323 , V_2 -> V_75 . V_212 ,
sizeof( V_2 -> V_75 . V_212 ) ) ;
F_151 ( V_2 , V_2 -> V_75 . V_322 ) ;
F_153 ( V_2 , V_2 -> V_75 . V_323 ) ;
F_155 ( V_2 , L_37 , V_2 -> V_75 . V_212 ) ;
F_155 ( V_2 , L_38 , V_2 -> V_75 . V_322 ) ;
F_155 ( V_2 , L_39 , V_2 -> V_75 . V_323 ) ;
if ( F_160 ( V_2 ) )
F_158 ( V_2 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_144 ( V_2 , V_2 -> V_75 . V_348 ) ;
F_155 ( V_2 , L_40 , V_2 -> V_75 . V_348 ) ;
}
static bool F_162 ( struct V_251 * V_84 ,
struct V_349 * V_350 )
{
const struct V_304 V_130 = {
. V_308 = 1 ,
. V_307 = V_350 -> V_307 ,
. V_351 = V_350 -> V_351 ,
} ;
struct V_310 F_58 ;
F_136 ( V_84 , 0 , & V_130 , V_352 , & F_58 ) ;
if ( ! F_138 ( 0 , & F_58 , & V_350 -> V_75 [ 0 ] ) ) {
F_13 ( L_41 ) ;
return false ;
}
return true ;
}
static int F_163 ( struct V_79 * V_296 )
{
struct V_353 * V_133 = V_296 -> V_83 . V_133 ;
struct V_81 * V_81 = F_38 ( V_296 -> V_83 . V_82 ) ;
struct V_349 * V_350 ;
struct V_251 * V_84 = V_133 -> V_84 ;
const struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_120 * V_120 ;
struct V_118 * V_319 = NULL ;
struct V_118 * V_320 = NULL ;
struct V_118 * V_321 = NULL ;
int V_217 , V_214 = F_146 ( V_2 ) , V_354 ;
struct V_310 F_58 ;
V_350 = & V_296 -> V_75 . V_355 . V_241 ;
F_164 (dev, intel_crtc, intel_plane) {
struct V_118 * V_356 ;
V_356 = F_165 ( V_133 ,
V_120 ) ;
if ( ! V_356 )
continue;
if ( V_120 -> V_83 . type == V_357 )
V_319 = V_356 ;
else if ( V_120 -> V_83 . type == V_358 )
V_320 = V_356 ;
else if ( V_120 -> V_83 . type == V_220 )
V_321 = V_356 ;
}
V_350 -> V_359 = V_296 -> V_83 . V_121 ;
if ( V_320 ) {
V_350 -> V_307 = V_320 -> V_83 . V_124 ;
V_350 -> V_351 = V_320 -> V_83 . V_124 &&
( F_125 ( & V_320 -> V_83 . V_302 ) != F_125 ( & V_320 -> V_83 . V_360 ) >> 16 ||
F_166 ( & V_320 -> V_83 . V_302 ) != F_166 ( & V_320 -> V_83 . V_360 ) >> 16 ) ;
}
V_354 = V_214 ;
if ( F_130 ( V_2 ) <= 6 && V_350 -> V_307 )
V_354 = 1 ;
if ( V_350 -> V_351 )
V_354 = 0 ;
F_139 ( V_2 , V_81 , 0 , V_296 ,
V_319 , V_320 , V_321 , & V_350 -> V_361 [ 0 ] ) ;
memset ( & V_350 -> V_75 , 0 , sizeof( V_350 -> V_75 ) ) ;
V_350 -> V_75 [ 0 ] = V_350 -> V_361 [ 0 ] ;
if ( F_148 ( V_2 ) || F_149 ( V_2 ) )
V_350 -> V_326 = F_140 ( V_296 ) ;
if ( ! F_162 ( V_84 , V_350 ) )
return - V_230 ;
F_137 ( V_2 , 1 , & F_58 ) ;
for ( V_217 = 1 ; V_217 <= V_214 ; V_217 ++ ) {
struct V_315 * V_75 = & V_350 -> V_361 [ V_217 ] ;
F_139 ( V_2 , V_81 , V_217 , V_296 ,
V_319 , V_320 , V_321 , V_75 ) ;
if ( V_217 > V_354 )
continue;
if ( F_138 ( V_217 , & F_58 , V_75 ) )
V_350 -> V_75 [ V_217 ] = * V_75 ;
else
V_354 = V_217 ;
}
return 0 ;
}
static int F_167 ( struct V_251 * V_84 ,
struct V_81 * V_81 ,
struct V_79 * V_362 )
{
struct V_349 * V_363 = & V_362 -> V_75 . V_355 . V_252 ;
struct V_349 * V_364 = & V_81 -> V_75 . V_121 . V_355 ;
int V_217 , V_214 = F_146 ( F_39 ( V_84 ) ) ;
* V_363 = V_362 -> V_75 . V_355 . V_241 ;
V_363 -> V_359 |= V_364 -> V_359 ;
V_363 -> V_307 |= V_364 -> V_307 ;
V_363 -> V_351 |= V_364 -> V_351 ;
for ( V_217 = 0 ; V_217 <= V_214 ; V_217 ++ ) {
struct V_315 * V_365 = & V_363 -> V_75 [ V_217 ] ;
const struct V_315 * V_366 = & V_364 -> V_75 [ V_217 ] ;
V_365 -> V_56 &= V_366 -> V_56 ;
V_365 -> V_295 = F_58 ( V_365 -> V_295 , V_366 -> V_295 ) ;
V_365 -> V_317 = F_58 ( V_365 -> V_317 , V_366 -> V_317 ) ;
V_365 -> V_318 = F_58 ( V_365 -> V_318 , V_366 -> V_318 ) ;
V_365 -> V_324 = F_58 ( V_365 -> V_324 , V_366 -> V_324 ) ;
}
if ( ! F_162 ( V_84 , V_363 ) )
return - V_230 ;
if ( memcmp ( V_363 , & V_362 -> V_75 . V_355 . V_241 , sizeof( * V_363 ) ) != 0 )
V_362 -> V_75 . V_254 = true ;
return 0 ;
}
static void F_168 ( struct V_251 * V_84 ,
int V_217 ,
struct V_315 * V_367 )
{
const struct V_81 * V_81 ;
V_367 -> V_56 = true ;
F_51 (dev, intel_crtc) {
const struct V_349 * V_121 = & V_81 -> V_75 . V_121 . V_355 ;
const struct V_315 * V_75 = & V_121 -> V_75 [ V_217 ] ;
if ( ! V_121 -> V_359 )
continue;
if ( ! V_75 -> V_56 )
V_367 -> V_56 = false ;
V_367 -> V_295 = F_58 ( V_367 -> V_295 , V_75 -> V_295 ) ;
V_367 -> V_317 = F_58 ( V_367 -> V_317 , V_75 -> V_317 ) ;
V_367 -> V_318 = F_58 ( V_367 -> V_318 , V_75 -> V_318 ) ;
V_367 -> V_324 = F_58 ( V_367 -> V_324 , V_75 -> V_324 ) ;
}
}
static void F_169 ( struct V_251 * V_84 ,
const struct V_304 * V_130 ,
const struct V_310 * F_58 ,
struct V_349 * V_368 )
{
struct V_1 * V_2 = F_39 ( V_84 ) ;
int V_217 , V_214 = F_146 ( V_2 ) ;
int V_369 = V_214 ;
if ( ( F_130 ( V_2 ) <= 6 || F_154 ( V_2 ) ) &&
V_130 -> V_308 > 1 )
V_369 = 0 ;
V_368 -> V_370 = F_130 ( V_2 ) >= 6 ;
for ( V_217 = 1 ; V_217 <= V_214 ; V_217 ++ ) {
struct V_315 * V_75 = & V_368 -> V_75 [ V_217 ] ;
F_168 ( V_84 , V_217 , V_75 ) ;
if ( V_217 > V_369 )
V_75 -> V_56 = false ;
else if ( ! F_138 ( V_217 , F_58 , V_75 ) )
V_369 = V_217 - 1 ;
if ( V_75 -> V_324 > F_58 -> V_314 ) {
if ( V_75 -> V_56 )
V_368 -> V_370 = false ;
V_75 -> V_324 = 0 ;
}
}
if ( F_152 ( V_2 ) && ! V_368 -> V_370 &&
F_170 ( V_2 ) ) {
for ( V_217 = 2 ; V_217 <= V_214 ; V_217 ++ ) {
struct V_315 * V_75 = & V_368 -> V_75 [ V_217 ] ;
V_75 -> V_56 = false ;
}
}
}
static int F_171 ( int V_371 , const struct V_349 * V_350 )
{
return V_371 + ( V_371 >= 2 && V_350 -> V_75 [ 4 ] . V_56 ) ;
}
static unsigned int F_172 ( struct V_251 * V_84 , int V_217 )
{
struct V_1 * V_2 = F_39 ( V_84 ) ;
if ( F_148 ( V_2 ) || F_149 ( V_2 ) )
return 2 * V_217 ;
else
return V_2 -> V_75 . V_212 [ V_217 ] ;
}
static void F_173 ( struct V_251 * V_84 ,
const struct V_349 * V_368 ,
enum V_305 V_372 ,
struct V_373 * V_374 )
{
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_81 * V_81 ;
int V_217 , V_371 ;
V_374 -> V_375 = V_368 -> V_370 ;
V_374 -> V_372 = V_372 ;
for ( V_371 = 1 ; V_371 <= 3 ; V_371 ++ ) {
const struct V_315 * V_376 ;
V_217 = F_171 ( V_371 , V_368 ) ;
V_376 = & V_368 -> V_75 [ V_217 ] ;
V_374 -> V_371 [ V_371 - 1 ] =
( F_172 ( V_84 , V_217 ) << V_377 ) |
( V_376 -> V_295 << V_378 ) |
V_376 -> V_318 ;
if ( V_376 -> V_56 )
V_374 -> V_371 [ V_371 - 1 ] |= V_379 ;
if ( F_130 ( V_2 ) >= 8 )
V_374 -> V_371 [ V_371 - 1 ] |=
V_376 -> V_324 << V_380 ;
else
V_374 -> V_371 [ V_371 - 1 ] |=
V_376 -> V_324 << V_381 ;
if ( F_130 ( V_2 ) <= 6 && V_376 -> V_317 ) {
F_72 ( V_371 != 1 ) ;
V_374 -> V_382 [ V_371 - 1 ] = V_383 | V_376 -> V_317 ;
} else
V_374 -> V_382 [ V_371 - 1 ] = V_376 -> V_317 ;
}
F_51 (dev, intel_crtc) {
enum V_87 V_87 = V_81 -> V_87 ;
const struct V_315 * V_376 =
& V_81 -> V_75 . V_121 . V_355 . V_75 [ 0 ] ;
if ( F_72 ( ! V_376 -> V_56 ) )
continue;
V_374 -> V_384 [ V_87 ] = V_81 -> V_75 . V_121 . V_355 . V_326 ;
V_374 -> V_385 [ V_87 ] =
( V_376 -> V_295 << V_386 ) |
( V_376 -> V_317 << V_387 ) |
V_376 -> V_318 ;
}
}
static struct V_349 * F_174 ( struct V_251 * V_84 ,
struct V_349 * V_388 ,
struct V_349 * V_389 )
{
int V_217 , V_214 = F_146 ( F_39 ( V_84 ) ) ;
int V_390 = 0 , V_391 = 0 ;
for ( V_217 = 1 ; V_217 <= V_214 ; V_217 ++ ) {
if ( V_388 -> V_75 [ V_217 ] . V_56 )
V_390 = V_217 ;
if ( V_389 -> V_75 [ V_217 ] . V_56 )
V_391 = V_217 ;
}
if ( V_390 == V_391 ) {
if ( V_389 -> V_370 && ! V_388 -> V_370 )
return V_389 ;
else
return V_388 ;
} else if ( V_390 > V_391 ) {
return V_388 ;
} else {
return V_389 ;
}
}
static unsigned int F_175 ( struct V_1 * V_2 ,
const struct V_373 * V_257 ,
const struct V_373 * V_258 )
{
unsigned int V_237 = 0 ;
enum V_87 V_87 ;
int V_371 ;
F_63 (dev_priv, pipe) {
if ( V_257 -> V_384 [ V_87 ] != V_258 -> V_384 [ V_87 ] ) {
V_237 |= F_176 ( V_87 ) ;
V_237 |= V_392 ;
}
if ( V_257 -> V_385 [ V_87 ] != V_258 -> V_385 [ V_87 ] ) {
V_237 |= F_177 ( V_87 ) ;
V_237 |= V_392 ;
}
}
if ( V_257 -> V_375 != V_258 -> V_375 ) {
V_237 |= V_393 ;
V_237 |= V_392 ;
}
if ( V_257 -> V_372 != V_258 -> V_372 ) {
V_237 |= V_394 ;
V_237 |= V_392 ;
}
if ( V_237 & V_392 )
return V_237 ;
for ( V_371 = 1 ; V_371 <= 3 ; V_371 ++ ) {
if ( V_257 -> V_371 [ V_371 - 1 ] != V_258 -> V_371 [ V_371 - 1 ] ||
V_257 -> V_382 [ V_371 - 1 ] != V_258 -> V_382 [ V_371 - 1 ] )
break;
}
for (; V_371 <= 3 ; V_371 ++ )
V_237 |= F_178 ( V_371 ) ;
return V_237 ;
}
static bool F_179 ( struct V_1 * V_2 ,
unsigned int V_237 )
{
struct V_373 * V_395 = & V_2 -> V_75 . V_396 ;
bool V_347 = false ;
if ( V_237 & F_178 ( 3 ) && V_395 -> V_371 [ 2 ] & V_379 ) {
V_395 -> V_371 [ 2 ] &= ~ V_379 ;
F_2 ( V_397 , V_395 -> V_371 [ 2 ] ) ;
V_347 = true ;
}
if ( V_237 & F_178 ( 2 ) && V_395 -> V_371 [ 1 ] & V_379 ) {
V_395 -> V_371 [ 1 ] &= ~ V_379 ;
F_2 ( V_398 , V_395 -> V_371 [ 1 ] ) ;
V_347 = true ;
}
if ( V_237 & F_178 ( 1 ) && V_395 -> V_371 [ 0 ] & V_379 ) {
V_395 -> V_371 [ 0 ] &= ~ V_379 ;
F_2 ( V_399 , V_395 -> V_371 [ 0 ] ) ;
V_347 = true ;
}
return V_347 ;
}
static void F_180 ( struct V_1 * V_2 ,
struct V_373 * V_374 )
{
struct V_373 * V_395 = & V_2 -> V_75 . V_396 ;
unsigned int V_237 ;
T_3 V_21 ;
V_237 = F_175 ( V_2 , V_395 , V_374 ) ;
if ( ! V_237 )
return;
F_179 ( V_2 , V_237 ) ;
if ( V_237 & F_177 ( V_93 ) )
F_2 ( V_400 , V_374 -> V_385 [ 0 ] ) ;
if ( V_237 & F_177 ( V_96 ) )
F_2 ( V_401 , V_374 -> V_385 [ 1 ] ) ;
if ( V_237 & F_177 ( V_97 ) )
F_2 ( V_402 , V_374 -> V_385 [ 2 ] ) ;
if ( V_237 & F_176 ( V_93 ) )
F_2 ( F_181 ( V_93 ) , V_374 -> V_384 [ 0 ] ) ;
if ( V_237 & F_176 ( V_96 ) )
F_2 ( F_181 ( V_96 ) , V_374 -> V_384 [ 1 ] ) ;
if ( V_237 & F_176 ( V_97 ) )
F_2 ( F_181 ( V_97 ) , V_374 -> V_384 [ 2 ] ) ;
if ( V_237 & V_394 ) {
if ( F_148 ( V_2 ) || F_149 ( V_2 ) ) {
V_21 = F_3 ( V_403 ) ;
if ( V_374 -> V_372 == V_352 )
V_21 &= ~ V_404 ;
else
V_21 |= V_404 ;
F_2 ( V_403 , V_21 ) ;
} else {
V_21 = F_3 ( V_405 ) ;
if ( V_374 -> V_372 == V_352 )
V_21 &= ~ V_406 ;
else
V_21 |= V_406 ;
F_2 ( V_405 , V_21 ) ;
}
}
if ( V_237 & V_393 ) {
V_21 = F_3 ( V_9 ) ;
if ( V_374 -> V_375 )
V_21 &= ~ V_10 ;
else
V_21 |= V_10 ;
F_2 ( V_9 , V_21 ) ;
}
if ( V_237 & F_178 ( 1 ) &&
V_395 -> V_382 [ 0 ] != V_374 -> V_382 [ 0 ] )
F_2 ( V_407 , V_374 -> V_382 [ 0 ] ) ;
if ( F_130 ( V_2 ) >= 7 ) {
if ( V_237 & F_178 ( 2 ) && V_395 -> V_382 [ 1 ] != V_374 -> V_382 [ 1 ] )
F_2 ( V_408 , V_374 -> V_382 [ 1 ] ) ;
if ( V_237 & F_178 ( 3 ) && V_395 -> V_382 [ 2 ] != V_374 -> V_382 [ 2 ] )
F_2 ( V_409 , V_374 -> V_382 [ 2 ] ) ;
}
if ( V_237 & F_178 ( 1 ) && V_395 -> V_371 [ 0 ] != V_374 -> V_371 [ 0 ] )
F_2 ( V_399 , V_374 -> V_371 [ 0 ] ) ;
if ( V_237 & F_178 ( 2 ) && V_395 -> V_371 [ 1 ] != V_374 -> V_371 [ 1 ] )
F_2 ( V_398 , V_374 -> V_371 [ 1 ] ) ;
if ( V_237 & F_178 ( 3 ) && V_395 -> V_371 [ 2 ] != V_374 -> V_371 [ 2 ] )
F_2 ( V_397 , V_374 -> V_371 [ 2 ] ) ;
V_2 -> V_75 . V_396 = * V_374 ;
}
bool F_182 ( struct V_251 * V_84 )
{
struct V_1 * V_2 = F_39 ( V_84 ) ;
return F_179 ( V_2 , V_392 ) ;
}
static bool F_183 ( struct V_240 * V_133 )
{
struct V_1 * V_2 = F_39 ( V_133 -> V_83 . V_84 ) ;
if ( F_184 ( V_2 ) || F_185 ( V_2 ) )
return true ;
return false ;
}
static bool
F_186 ( struct V_1 * V_2 )
{
if ( F_187 ( V_2 ) )
return true ;
if ( F_188 ( V_2 ) &&
V_2 -> V_410 != V_411 )
return true ;
return false ;
}
int
F_189 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! F_186 ( V_2 ) )
return 0 ;
if ( V_2 -> V_410 == V_412 )
return 0 ;
F_13 ( L_42 ) ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_74 = F_190 ( V_2 , V_413 ,
V_414 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
if ( F_188 ( V_2 ) && V_74 == - V_415 ) {
F_10 ( L_43 ) ;
V_2 -> V_410 = V_411 ;
return 0 ;
} else if ( V_74 < 0 ) {
F_19 ( L_44 ) ;
return V_74 ;
}
V_2 -> V_410 = V_412 ;
return 0 ;
}
int
F_191 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! F_186 ( V_2 ) )
return 0 ;
if ( V_2 -> V_410 == V_416 )
return 0 ;
F_13 ( L_45 ) ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_74 = F_192 ( V_2 , V_413 ,
V_417 ,
V_418 , V_418 ,
1 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
if ( F_188 ( V_2 ) && V_74 == - V_415 ) {
F_10 ( L_43 ) ;
V_2 -> V_410 = V_411 ;
return 0 ;
} else if ( V_74 < 0 ) {
F_19 ( L_46 , V_74 ) ;
return V_74 ;
}
V_2 -> V_410 = V_416 ;
return 0 ;
}
bool F_193 ( struct V_353 * V_133 )
{
struct V_251 * V_84 = V_133 -> V_84 ;
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_240 * V_325 = F_87 ( V_133 ) ;
struct V_81 * V_82 ;
struct V_120 * V_99 ;
struct V_79 * V_296 ;
enum V_87 V_87 ;
int V_217 , V_53 ;
if ( ! F_186 ( V_2 ) )
return false ;
if ( F_77 ( V_325 -> V_419 ) == 0 )
return true ;
else if ( F_77 ( V_325 -> V_419 ) > 1 )
return false ;
V_87 = F_111 ( V_325 -> V_419 ) - 1 ;
V_82 = F_65 ( V_2 , V_87 ) ;
V_296 = F_91 ( V_82 -> V_83 . V_133 ) ;
if ( V_82 -> V_83 . V_133 -> V_129 . V_420 & V_421 )
return false ;
F_164 (dev, crtc, plane) {
struct V_422 * V_75 =
& V_296 -> V_75 . V_423 . V_241 . V_424 [ V_99 -> V_122 ] ;
if ( ! V_75 -> V_75 [ 0 ] . V_425 )
continue;
for ( V_217 = F_146 ( V_2 ) ;
! V_75 -> V_75 [ V_217 ] . V_425 ; -- V_217 )
{ }
V_53 = V_2 -> V_75 . V_348 [ V_217 ] ;
if ( F_183 ( V_325 ) &&
V_99 -> V_83 . V_133 -> V_123 -> V_426 ==
V_427 )
V_53 += 15 ;
if ( V_53 < V_428 )
return false ;
}
return true ;
}
static void
F_194 ( struct V_251 * V_84 ,
const struct V_79 * V_296 ,
struct V_429 * V_430 ,
int * V_431 )
{
struct V_353 * V_133 = V_296 -> V_83 . V_133 ;
struct V_240 * V_325 = F_87 ( V_133 ) ;
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_432 * V_433 = V_296 -> V_83 . V_82 ;
unsigned int V_434 , V_435 ;
int V_436 ;
if ( F_72 ( ! V_133 ) || ! V_296 -> V_83 . V_121 ) {
V_430 -> V_437 = 0 ;
V_430 -> V_438 = 0 ;
* V_431 = F_77 ( V_2 -> V_419 ) ;
return;
}
if ( V_325 -> V_439 )
* V_431 = F_77 ( V_325 -> V_419 ) ;
else
* V_431 = F_77 ( V_2 -> V_419 ) ;
V_435 = F_92 ( V_2 ) -> V_435 ;
F_72 ( V_435 == 0 ) ;
V_435 -= 4 ;
if ( ! V_325 -> V_439 ) {
* V_430 = F_91 ( V_433 -> V_133 ) -> V_75 . V_423 . V_440 ;
return;
}
V_436 = F_77 ( V_325 -> V_419 &
( F_195 ( V_433 ) - 1 ) ) ;
V_434 = V_435 / F_77 ( V_325 -> V_419 ) ;
V_430 -> V_437 = V_436 * V_435 / * V_431 ;
V_430 -> V_438 = V_430 -> V_437 + V_434 ;
}
static unsigned int F_196 ( int V_431 )
{
if ( V_431 == 1 )
return 32 ;
return 8 ;
}
static void F_197 ( struct V_429 * V_441 , T_1 V_127 )
{
V_441 -> V_437 = V_127 & 0x3ff ;
V_441 -> V_438 = ( V_127 >> 16 ) & 0x3ff ;
if ( V_441 -> V_438 )
V_441 -> V_438 += 1 ;
}
void F_198 ( struct V_1 * V_2 ,
struct V_442 * V_440 )
{
struct V_81 * V_82 ;
memset ( V_440 , 0 , sizeof( * V_440 ) ) ;
F_51 (&dev_priv->drm, crtc) {
enum V_443 V_444 ;
enum V_229 V_229 ;
enum V_87 V_87 = V_82 -> V_87 ;
V_444 = F_199 ( V_87 ) ;
if ( ! F_200 ( V_2 , V_444 ) )
continue;
F_78 (crtc, plane_id) {
T_1 V_21 ;
if ( V_229 != V_103 )
V_21 = F_3 ( F_201 ( V_87 , V_229 ) ) ;
else
V_21 = F_3 ( F_202 ( V_87 ) ) ;
F_197 ( & V_440 -> V_99 [ V_87 ] [ V_229 ] , V_21 ) ;
}
F_203 ( V_2 , V_444 ) ;
}
}
static T_3
F_204 ( const struct V_79 * V_296 ,
const struct V_118 * V_297 )
{
struct V_120 * V_99 = F_49 ( V_297 -> V_83 . V_99 ) ;
T_3 V_445 , V_446 ;
T_3 V_447 , V_448 , V_449 , V_450 ;
if ( F_72 ( ! F_48 ( V_296 , V_297 ) ) )
return V_451 ;
if ( V_99 -> V_122 == V_103 ) {
V_447 = V_297 -> V_83 . V_447 ;
V_448 = V_297 -> V_83 . V_448 ;
V_449 = V_297 -> V_83 . V_167 ;
V_450 = V_297 -> V_83 . V_452 ;
} else {
V_447 = F_125 ( & V_297 -> V_83 . V_360 ) ;
V_448 = F_166 ( & V_297 -> V_83 . V_360 ) ;
V_449 = F_125 ( & V_297 -> V_83 . V_302 ) ;
V_450 = F_166 ( & V_297 -> V_83 . V_302 ) ;
}
V_445 = F_58 ( V_448 / V_450 , ( T_3 ) V_451 ) ;
V_446 = F_58 ( V_447 / V_449 , ( T_3 ) V_451 ) ;
return ( T_6 ) V_446 * V_445 >> 16 ;
}
static unsigned int
F_205 ( const struct V_79 * V_296 ,
const struct V_453 * V_297 ,
int V_454 )
{
struct V_120 * V_99 = F_49 ( V_297 -> V_99 ) ;
struct V_118 * V_455 = F_90 ( V_297 ) ;
T_3 V_456 , V_457 ;
T_3 V_218 = 0 , V_458 = 0 ;
struct V_131 * V_123 ;
T_1 V_134 ;
if ( ! V_455 -> V_83 . V_124 )
return 0 ;
V_123 = V_297 -> V_123 ;
V_134 = V_123 -> V_134 -> V_134 ;
if ( V_99 -> V_122 == V_103 )
return 0 ;
if ( V_454 && V_134 != V_459 )
return 0 ;
V_218 = F_125 ( & V_455 -> V_83 . V_360 ) >> 16 ;
V_458 = F_166 ( & V_455 -> V_83 . V_360 ) >> 16 ;
if ( V_134 == V_459 ) {
if ( V_454 )
V_457 = V_218 * V_458 *
V_123 -> V_134 -> V_110 [ 0 ] ;
else
V_457 = ( V_218 / 2 ) * ( V_458 / 2 ) *
V_123 -> V_134 -> V_110 [ 1 ] ;
} else {
V_457 = V_218 * V_458 * V_123 -> V_134 -> V_110 [ 0 ] ;
}
V_456 = F_204 ( V_296 , V_455 ) ;
return ( T_6 ) V_457 * V_456 >> 16 ;
}
static unsigned int
F_206 ( struct V_79 * V_460 ,
unsigned * V_461 ,
unsigned * V_462 )
{
struct V_463 * V_296 = & V_460 -> V_83 ;
struct V_353 * V_133 = V_296 -> V_133 ;
struct V_464 * V_99 ;
const struct V_453 * V_297 ;
unsigned int V_465 = 0 ;
if ( F_72 ( ! V_133 ) )
return 0 ;
F_207 (plane, pstate, cstate) {
enum V_229 V_229 = F_49 ( V_99 ) -> V_122 ;
unsigned int V_231 ;
V_231 = F_205 ( V_460 ,
V_297 , 0 ) ;
V_461 [ V_229 ] = V_231 ;
V_465 += V_231 ;
V_231 = F_205 ( V_460 ,
V_297 , 1 ) ;
V_462 [ V_229 ] = V_231 ;
V_465 += V_231 ;
}
return V_465 ;
}
static T_4
F_208 ( const struct V_453 * V_297 ,
const int V_454 )
{
struct V_131 * V_123 = V_297 -> V_123 ;
struct V_118 * V_455 = F_90 ( V_297 ) ;
T_3 V_447 , V_448 ;
T_3 V_466 = 8 ;
T_5 V_467 ;
if ( F_72 ( ! V_123 ) )
return 0 ;
if ( V_454 && V_123 -> V_134 -> V_134 != V_459 )
return 0 ;
if ( V_123 -> V_426 != V_468 &&
V_123 -> V_426 != V_469 )
return 8 ;
V_447 = F_125 ( & V_455 -> V_83 . V_360 ) >> 16 ;
V_448 = F_166 ( & V_455 -> V_83 . V_360 ) >> 16 ;
if ( V_123 -> V_134 -> V_134 == V_459 && ! V_454 ) {
V_447 /= 2 ;
V_448 /= 2 ;
}
if ( V_123 -> V_134 -> V_134 == V_459 && ! V_454 )
V_467 = V_123 -> V_134 -> V_110 [ 1 ] ;
else
V_467 = V_123 -> V_134 -> V_110 [ 0 ] ;
if ( F_209 ( V_297 -> V_470 ) ) {
switch ( V_467 ) {
case 1 :
V_466 = 32 ;
break;
case 2 :
V_466 = 16 ;
break;
case 4 :
V_466 = 8 ;
break;
case 8 :
V_466 = 4 ;
break;
default:
F_120 ( 1 , L_47 ,
V_467 ) ;
V_466 = 32 ;
}
}
return F_47 ( ( 4 * V_447 * V_467 ) , 512 ) * V_466 / 4 + 3 ;
}
static void
F_210 ( const struct V_79 * V_296 , int V_431 ,
T_4 * V_471 , T_4 * V_472 )
{
const struct V_453 * V_297 ;
struct V_464 * V_99 ;
F_207 (plane, pstate, &cstate->base) {
enum V_229 V_229 = F_49 ( V_99 ) -> V_122 ;
if ( V_229 == V_103 )
continue;
if ( ! V_297 -> V_124 )
continue;
V_471 [ V_229 ] = F_208 ( V_297 , 0 ) ;
V_472 [ V_229 ] = F_208 ( V_297 , 1 ) ;
}
V_471 [ V_103 ] = F_196 ( V_431 ) ;
}
static int
F_211 ( struct V_79 * V_296 ,
struct V_442 * V_440 )
{
struct V_353 * V_133 = V_296 -> V_83 . V_133 ;
struct V_432 * V_82 = V_296 -> V_83 . V_82 ;
struct V_251 * V_84 = V_82 -> V_84 ;
struct V_81 * V_81 = F_38 ( V_82 ) ;
enum V_87 V_87 = V_81 -> V_87 ;
struct V_429 * V_430 = & V_296 -> V_75 . V_423 . V_440 ;
T_4 V_473 , V_437 ;
T_4 V_471 [ V_474 ] = {} ;
T_4 V_472 [ V_474 ] = {} ;
unsigned int V_465 ;
enum V_229 V_229 ;
int V_431 ;
unsigned V_461 [ V_474 ] = {} ;
unsigned V_462 [ V_474 ] = {} ;
memset ( V_440 -> V_99 [ V_87 ] , 0 , sizeof( V_440 -> V_99 [ V_87 ] ) ) ;
memset ( V_440 -> V_475 [ V_87 ] , 0 , sizeof( V_440 -> V_475 [ V_87 ] ) ) ;
if ( F_72 ( ! V_133 ) )
return 0 ;
if ( ! V_296 -> V_83 . V_121 ) {
V_430 -> V_437 = V_430 -> V_438 = 0 ;
return 0 ;
}
F_194 ( V_84 , V_296 , V_430 , & V_431 ) ;
V_473 = F_212 ( V_430 ) ;
if ( V_473 == 0 ) {
memset ( V_440 -> V_99 [ V_87 ] , 0 , sizeof( V_440 -> V_99 [ V_87 ] ) ) ;
return 0 ;
}
F_210 ( V_296 , V_431 , V_471 , V_472 ) ;
F_78 (intel_crtc, plane_id) {
V_473 -= V_471 [ V_229 ] ;
V_473 -= V_472 [ V_229 ] ;
}
V_440 -> V_99 [ V_87 ] [ V_103 ] . V_437 = V_430 -> V_438 - V_471 [ V_103 ] ;
V_440 -> V_99 [ V_87 ] [ V_103 ] . V_438 = V_430 -> V_438 ;
V_465 = F_206 ( V_296 ,
V_461 ,
V_462 ) ;
if ( V_465 == 0 )
return 0 ;
V_437 = V_430 -> V_437 ;
F_78 (intel_crtc, plane_id) {
unsigned int V_457 , V_476 ;
T_4 V_477 , V_478 = 0 ;
if ( V_229 == V_103 )
continue;
V_457 = V_461 [ V_229 ] ;
V_477 = V_471 [ V_229 ] ;
V_477 += F_213 ( ( T_6 ) V_473 * V_457 ,
V_465 ) ;
if ( V_457 ) {
V_440 -> V_99 [ V_87 ] [ V_229 ] . V_437 = V_437 ;
V_440 -> V_99 [ V_87 ] [ V_229 ] . V_438 = V_437 + V_477 ;
}
V_437 += V_477 ;
V_476 = V_462 [ V_229 ] ;
V_478 = V_472 [ V_229 ] ;
V_478 += F_213 ( ( T_6 ) V_473 * V_476 ,
V_465 ) ;
if ( V_476 ) {
V_440 -> V_475 [ V_87 ] [ V_229 ] . V_437 = V_437 ;
V_440 -> V_475 [ V_87 ] [ V_229 ] . V_438 = V_437 + V_478 ;
}
V_437 += V_478 ;
}
return 0 ;
}
static T_7 F_214 ( T_3 V_209 , T_5 V_110 ,
T_3 V_53 )
{
T_3 V_479 ;
T_7 V_74 ;
if ( V_53 == 0 )
return V_480 ;
V_479 = V_53 * V_209 * V_110 ;
V_74 = F_215 ( V_479 , 1000 * 512 ) ;
return V_74 ;
}
static T_7 F_216 ( T_3 V_209 ,
T_3 V_210 ,
T_3 V_53 ,
T_7 V_481 )
{
T_3 V_479 ;
T_7 V_74 ;
if ( V_53 == 0 )
return V_480 ;
V_479 = V_53 * V_209 ;
V_479 = F_47 ( V_479 ,
V_210 * 1000 ) ;
V_74 = F_217 ( V_479 , V_481 ) ;
return V_74 ;
}
static T_3 F_218 ( const struct V_79 * V_296 ,
struct V_118 * V_297 )
{
T_6 V_482 ;
T_6 V_483 ;
T_6 V_209 ;
if ( F_72 ( ! F_48 ( V_296 , V_297 ) ) )
return 0 ;
V_482 = V_296 -> V_209 ;
V_483 = F_204 ( V_296 , V_297 ) ;
V_209 = V_482 * V_483 >> 16 ;
F_72 ( V_209 != F_219 ( T_3 , V_209 , 0 , ~ 0 ) ) ;
return V_209 ;
}
static int F_220 ( const struct V_1 * V_2 ,
struct V_79 * V_296 ,
struct V_118 * V_455 ,
T_4 V_484 ,
int V_217 ,
T_4 * V_485 ,
T_5 * V_486 ,
bool * V_125 )
{
struct V_120 * V_99 = F_49 ( V_455 -> V_83 . V_99 ) ;
struct V_453 * V_297 = & V_455 -> V_83 ;
struct V_131 * V_123 = V_297 -> V_123 ;
T_3 V_53 = V_2 -> V_75 . V_348 [ V_217 ] ;
T_7 V_300 , V_301 ;
T_7 V_481 ;
T_7 V_487 ;
T_3 V_488 ;
T_3 V_489 ;
T_3 V_490 , V_491 ;
T_5 V_110 ;
T_3 V_218 = 0 , V_458 = 0 ;
T_3 V_492 ;
T_7 V_493 ;
T_3 V_494 ;
struct V_240 * V_133 =
F_87 ( V_296 -> V_83 . V_133 ) ;
bool V_495 = F_183 ( V_133 ) ;
bool V_496 , V_497 ;
if ( V_53 == 0 ||
! F_48 ( V_296 , V_455 ) ) {
* V_125 = false ;
return 0 ;
}
V_496 = V_123 -> V_426 == V_468 ||
V_123 -> V_426 == V_469 ;
V_497 = V_123 -> V_426 == V_427 ;
if ( F_187 ( V_2 ) && V_2 -> V_498 )
V_53 += 4 ;
if ( V_495 && V_497 )
V_53 += 15 ;
if ( V_99 -> V_122 == V_103 ) {
V_218 = V_455 -> V_83 . V_167 ;
V_458 = V_455 -> V_83 . V_452 ;
} else {
V_218 = F_125 ( & V_455 -> V_83 . V_360 ) >> 16 ;
V_458 = F_166 ( & V_455 -> V_83 . V_360 ) >> 16 ;
}
V_110 = V_123 -> V_134 -> V_110 [ 0 ] ;
V_492 = F_218 ( V_296 , V_455 ) ;
if ( F_209 ( V_297 -> V_470 ) ) {
int V_110 = ( V_123 -> V_134 -> V_134 == V_459 ) ?
V_123 -> V_134 -> V_110 [ 1 ] :
V_123 -> V_134 -> V_110 [ 0 ] ;
switch ( V_110 ) {
case 1 :
V_494 = 16 ;
break;
case 2 :
V_494 = 8 ;
break;
case 4 :
V_494 = 4 ;
break;
default:
F_41 ( V_110 ) ;
return - V_230 ;
}
} else {
V_494 = 4 ;
}
if ( V_495 )
V_494 *= 2 ;
V_489 = V_218 * V_110 ;
if ( V_496 ) {
V_488 = F_47 ( V_489 *
V_494 , 512 ) ;
V_481 =
F_221 ( V_488 , V_494 ) ;
} else if ( V_497 ) {
V_488 = F_47 ( V_489 , 512 ) ;
V_481 = F_222 ( V_488 ) ;
} else {
V_488 = F_47 ( V_489 , 512 ) + 1 ;
V_481 = F_222 ( V_488 ) ;
}
V_300 = F_214 ( V_492 , V_110 , V_53 ) ;
V_301 = F_216 ( V_492 ,
V_296 -> V_83 . V_129 . V_165 ,
V_53 ,
V_481 ) ;
V_493 = F_217 ( V_494 ,
V_481 ) ;
if ( V_496 ) {
V_487 = F_223 ( V_301 , V_493 ) ;
} else {
if ( ( V_110 * V_296 -> V_83 . V_129 . V_165 / 512 < 1 ) &&
( V_489 / 512 < 1 ) )
V_487 = V_301 ;
else if ( ( V_484 /
F_224 ( V_481 ) ) >= 1 )
V_487 = F_225 ( V_300 , V_301 ) ;
else
V_487 = V_300 ;
}
V_490 = F_224 ( V_487 ) + 1 ;
V_491 = F_47 ( V_487 . V_21 ,
V_481 . V_21 ) ;
if ( V_217 >= 1 && V_217 <= 7 ) {
if ( V_496 ) {
V_490 += F_224 ( V_493 ) ;
V_491 += V_494 ;
} else {
V_490 ++ ;
}
}
if ( V_490 >= V_484 || V_491 > 31 ) {
* V_125 = false ;
if ( V_217 ) {
return 0 ;
} else {
struct V_464 * V_99 = V_297 -> V_99 ;
F_13 ( L_48 ) ;
F_13 ( L_49 ,
V_99 -> V_83 . V_122 , V_99 -> V_239 ,
V_490 , V_484 , V_491 ) ;
return - V_230 ;
}
}
* V_485 = V_490 ;
* V_486 = V_491 ;
* V_125 = true ;
return 0 ;
}
static int
F_226 ( const struct V_1 * V_2 ,
struct V_442 * V_440 ,
struct V_79 * V_296 ,
struct V_120 * V_120 ,
int V_217 ,
struct V_499 * V_316 )
{
struct V_353 * V_133 = V_296 -> V_83 . V_133 ;
struct V_81 * V_81 = F_38 ( V_296 -> V_83 . V_82 ) ;
struct V_464 * V_99 = & V_120 -> V_83 ;
struct V_118 * V_455 = NULL ;
T_4 V_500 ;
enum V_87 V_87 = V_81 -> V_87 ;
int V_74 ;
if ( V_133 )
V_455 =
F_165 ( V_133 ,
V_120 ) ;
if ( ! V_455 )
V_455 = F_90 ( V_99 -> V_133 ) ;
F_72 ( ! V_455 -> V_83 . V_123 ) ;
V_500 = F_212 ( & V_440 -> V_99 [ V_87 ] [ V_120 -> V_122 ] ) ;
V_74 = F_220 ( V_2 ,
V_296 ,
V_455 ,
V_500 ,
V_217 ,
& V_316 -> V_501 ,
& V_316 -> V_502 ,
& V_316 -> V_425 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static T_3
F_227 ( struct V_79 * V_296 )
{
struct V_353 * V_133 = V_296 -> V_83 . V_133 ;
struct V_1 * V_2 = F_39 ( V_133 -> V_84 ) ;
T_3 V_209 ;
T_3 V_503 ;
if ( ! V_296 -> V_83 . V_121 )
return 0 ;
V_209 = V_296 -> V_209 ;
if ( F_72 ( V_209 == 0 ) )
return 0 ;
V_503 = F_47 ( 8 * V_296 -> V_83 . V_129 . V_165 *
1000 , V_209 ) ;
if ( F_185 ( V_2 ) && V_2 -> V_498 )
V_503 = F_47 ( V_503 , 2 ) ;
return V_503 ;
}
static void F_228 ( struct V_79 * V_296 ,
struct V_499 * V_504 )
{
if ( ! V_296 -> V_83 . V_121 )
return;
V_504 -> V_425 = false ;
}
static int F_229 ( struct V_79 * V_296 ,
struct V_442 * V_440 ,
struct V_505 * V_350 )
{
struct V_251 * V_84 = V_296 -> V_83 . V_82 -> V_84 ;
const struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_120 * V_120 ;
struct V_422 * V_75 ;
int V_217 , V_214 = F_146 ( V_2 ) ;
int V_74 ;
memset ( V_350 -> V_424 , 0 , sizeof( V_350 -> V_424 ) ) ;
F_230 (&dev_priv->drm,
intel_plane,
cstate->base.plane_mask) {
V_75 = & V_350 -> V_424 [ V_120 -> V_122 ] ;
for ( V_217 = 0 ; V_217 <= V_214 ; V_217 ++ ) {
V_74 = F_226 ( V_2 , V_440 , V_296 ,
V_120 , V_217 ,
& V_75 -> V_75 [ V_217 ] ) ;
if ( V_74 )
return V_74 ;
}
F_228 ( V_296 , & V_75 -> V_504 ) ;
}
V_350 -> V_326 = F_227 ( V_296 ) ;
return 0 ;
}
static void F_231 ( struct V_1 * V_2 ,
T_8 V_127 ,
const struct V_429 * V_441 )
{
if ( V_441 -> V_438 )
F_2 ( V_127 , ( V_441 -> V_438 - 1 ) << 16 | V_441 -> V_437 ) ;
else
F_2 ( V_127 , 0 ) ;
}
static void F_232 ( struct V_1 * V_2 ,
T_8 V_127 ,
const struct V_499 * V_217 )
{
T_3 V_21 = 0 ;
if ( V_217 -> V_425 ) {
V_21 |= V_506 ;
V_21 |= V_217 -> V_501 ;
V_21 |= V_217 -> V_502 << V_507 ;
}
F_2 ( V_127 , V_21 ) ;
}
static void F_233 ( struct V_81 * V_81 ,
const struct V_422 * V_75 ,
const struct V_442 * V_440 ,
enum V_229 V_229 )
{
struct V_432 * V_82 = & V_81 -> V_83 ;
struct V_251 * V_84 = V_82 -> V_84 ;
struct V_1 * V_2 = F_39 ( V_84 ) ;
int V_217 , V_214 = F_146 ( V_2 ) ;
enum V_87 V_87 = V_81 -> V_87 ;
for ( V_217 = 0 ; V_217 <= V_214 ; V_217 ++ ) {
F_232 ( V_2 , F_234 ( V_87 , V_229 , V_217 ) ,
& V_75 -> V_75 [ V_217 ] ) ;
}
F_232 ( V_2 , F_235 ( V_87 , V_229 ) ,
& V_75 -> V_504 ) ;
F_231 ( V_2 , F_201 ( V_87 , V_229 ) ,
& V_440 -> V_99 [ V_87 ] [ V_229 ] ) ;
F_231 ( V_2 , F_236 ( V_87 , V_229 ) ,
& V_440 -> V_475 [ V_87 ] [ V_229 ] ) ;
}
static void F_237 ( struct V_81 * V_81 ,
const struct V_422 * V_75 ,
const struct V_442 * V_440 )
{
struct V_432 * V_82 = & V_81 -> V_83 ;
struct V_251 * V_84 = V_82 -> V_84 ;
struct V_1 * V_2 = F_39 ( V_84 ) ;
int V_217 , V_214 = F_146 ( V_2 ) ;
enum V_87 V_87 = V_81 -> V_87 ;
for ( V_217 = 0 ; V_217 <= V_214 ; V_217 ++ ) {
F_232 ( V_2 , F_238 ( V_87 , V_217 ) ,
& V_75 -> V_75 [ V_217 ] ) ;
}
F_232 ( V_2 , F_239 ( V_87 ) , & V_75 -> V_504 ) ;
F_231 ( V_2 , F_202 ( V_87 ) ,
& V_440 -> V_99 [ V_87 ] [ V_103 ] ) ;
}
bool F_240 ( const struct V_499 * V_508 ,
const struct V_499 * V_509 )
{
if ( V_508 -> V_425 != V_509 -> V_425 )
return false ;
if ( ! V_508 -> V_425 )
return true ;
return ( V_508 -> V_502 == V_509 -> V_502 &&
V_508 -> V_501 == V_509 -> V_501 ) ;
}
static inline bool F_241 ( const struct V_429 * V_363 ,
const struct V_429 * V_364 )
{
return V_363 -> V_437 < V_364 -> V_438 && V_364 -> V_437 < V_363 -> V_438 ;
}
bool F_242 ( const struct V_429 * * V_163 ,
const struct V_429 * V_440 ,
int V_510 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_511 ; V_54 ++ )
if ( V_54 != V_510 && V_163 [ V_54 ] &&
F_241 ( V_440 , V_163 [ V_54 ] ) )
return true ;
return false ;
}
static int F_243 ( struct V_463 * V_296 ,
const struct V_505 * V_512 ,
struct V_505 * V_350 ,
struct V_442 * V_440 ,
bool * V_347 )
{
struct V_79 * V_460 = F_91 ( V_296 ) ;
int V_74 ;
V_74 = F_229 ( V_460 , V_440 , V_350 ) ;
if ( V_74 )
return V_74 ;
if ( ! memcmp ( V_512 , V_350 , sizeof( * V_350 ) ) )
* V_347 = false ;
else
* V_347 = true ;
return 0 ;
}
static T_3
F_244 ( struct V_353 * V_133 )
{
struct V_432 * V_82 ;
struct V_463 * V_296 ;
T_3 V_54 , V_74 = 0 ;
F_245 (state, crtc, cstate, i)
V_74 |= F_195 ( V_82 ) ;
return V_74 ;
}
static int
F_246 ( struct V_79 * V_296 )
{
struct V_353 * V_133 = V_296 -> V_83 . V_133 ;
struct V_251 * V_84 = V_133 -> V_84 ;
struct V_432 * V_82 = V_296 -> V_83 . V_82 ;
struct V_81 * V_81 = F_38 ( V_82 ) ;
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_240 * V_325 = F_87 ( V_133 ) ;
struct V_442 * V_513 = & V_325 -> V_514 . V_440 ;
struct V_442 * V_515 = & V_2 -> V_75 . V_516 . V_440 ;
struct V_453 * V_119 ;
struct V_464 * V_99 ;
enum V_87 V_87 = V_81 -> V_87 ;
F_72 ( ! F_247 ( V_133 , V_82 ) ) ;
F_248 (plane, dev, cstate->base.plane_mask) {
enum V_229 V_229 = F_49 ( V_99 ) -> V_122 ;
if ( F_249 ( & V_515 -> V_99 [ V_87 ] [ V_229 ] ,
& V_513 -> V_99 [ V_87 ] [ V_229 ] ) &&
F_249 ( & V_515 -> V_475 [ V_87 ] [ V_229 ] ,
& V_513 -> V_475 [ V_87 ] [ V_229 ] ) )
continue;
V_119 = F_250 ( V_133 , V_99 ) ;
if ( F_251 ( V_119 ) )
return F_252 ( V_119 ) ;
}
return 0 ;
}
static int
F_253 ( struct V_353 * V_133 )
{
struct V_251 * V_84 = V_133 -> V_84 ;
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_240 * V_325 = F_87 ( V_133 ) ;
struct V_81 * V_81 ;
struct V_442 * V_440 = & V_325 -> V_514 . V_440 ;
T_3 V_517 = F_244 ( V_133 ) ;
int V_74 ;
if ( V_2 -> V_75 . V_518 ) {
V_74 = F_254 ( & V_84 -> V_519 . V_520 ,
V_133 -> V_521 ) ;
if ( V_74 )
return V_74 ;
V_325 -> V_439 = ~ 0 ;
if ( ! V_325 -> V_522 )
V_325 -> V_419 = V_2 -> V_419 ;
}
if ( V_325 -> V_439 ) {
V_517 = ~ 0 ;
V_325 -> V_514 . V_523 = ~ 0 ;
}
memcpy ( V_440 , & V_2 -> V_75 . V_516 . V_440 , sizeof( * V_440 ) ) ;
F_255 (dev, intel_crtc, realloc_pipes) {
struct V_79 * V_296 ;
V_296 = F_256 ( V_133 , V_81 ) ;
if ( F_251 ( V_296 ) )
return F_252 ( V_296 ) ;
V_74 = F_211 ( V_296 , V_440 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_246 ( V_296 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static void
F_257 ( struct V_524 * V_302 ,
struct V_524 * V_360 ,
enum V_87 V_87 )
{
memcpy ( V_302 -> V_440 . V_475 [ V_87 ] , V_360 -> V_440 . V_475 [ V_87 ] ,
sizeof( V_302 -> V_440 . V_475 [ V_87 ] ) ) ;
memcpy ( V_302 -> V_440 . V_99 [ V_87 ] , V_360 -> V_440 . V_99 [ V_87 ] ,
sizeof( V_302 -> V_440 . V_99 [ V_87 ] ) ) ;
}
static void
F_258 ( const struct V_353 * V_133 )
{
const struct V_251 * V_84 = V_133 -> V_84 ;
const struct V_1 * V_2 = F_39 ( V_84 ) ;
const struct V_240 * V_325 =
F_87 ( V_133 ) ;
const struct V_432 * V_82 ;
const struct V_463 * V_296 ;
const struct V_120 * V_120 ;
const struct V_442 * V_525 = & V_2 -> V_75 . V_516 . V_440 ;
const struct V_442 * V_513 = & V_325 -> V_514 . V_440 ;
int V_54 ;
F_245 (state, crtc, cstate, i) {
const struct V_81 * V_81 = F_38 ( V_82 ) ;
enum V_87 V_87 = V_81 -> V_87 ;
F_164 (dev, intel_crtc, intel_plane) {
enum V_229 V_229 = V_120 -> V_122 ;
const struct V_429 * V_257 , * V_258 ;
V_257 = & V_525 -> V_99 [ V_87 ] [ V_229 ] ;
V_258 = & V_513 -> V_99 [ V_87 ] [ V_229 ] ;
if ( F_249 ( V_257 , V_258 ) )
continue;
F_259 ( L_50 ,
V_120 -> V_83 . V_83 . V_122 ,
V_120 -> V_83 . V_239 ,
V_257 -> V_437 , V_257 -> V_438 ,
V_258 -> V_437 , V_258 -> V_438 ) ;
}
}
}
static int
F_260 ( struct V_353 * V_133 )
{
struct V_432 * V_82 ;
struct V_463 * V_296 ;
struct V_240 * V_325 = F_87 ( V_133 ) ;
struct V_524 * V_374 = & V_325 -> V_514 ;
struct V_251 * V_84 = V_133 -> V_84 ;
struct V_505 * V_350 ;
bool V_347 = false ;
int V_74 , V_54 ;
if ( F_39 ( V_84 ) -> V_75 . V_518 )
V_347 = true ;
F_245 (state, crtc, cstate, i)
V_347 = true ;
if ( ! V_347 )
return 0 ;
V_374 -> V_523 = 0 ;
V_74 = F_253 ( V_133 ) ;
if ( V_74 )
return V_74 ;
F_245 (state, crtc, cstate, i) {
struct V_79 * V_460 =
F_91 ( V_296 ) ;
const struct V_505 * V_512 =
& F_91 ( V_82 -> V_133 ) -> V_75 . V_423 . V_241 ;
V_350 = & V_460 -> V_75 . V_423 . V_241 ;
V_74 = F_243 ( V_296 , V_512 , V_350 ,
& V_374 -> V_440 , & V_347 ) ;
if ( V_74 )
return V_74 ;
if ( V_347 )
V_374 -> V_523 |= F_195 ( V_82 ) ;
if ( ( V_374 -> V_523 & F_195 ( V_82 ) ) == 0 )
continue;
V_460 -> V_526 = true ;
}
F_258 ( V_133 ) ;
return 0 ;
}
static void F_261 ( struct V_240 * V_133 ,
struct V_79 * V_296 )
{
struct V_81 * V_82 = F_38 ( V_296 -> V_83 . V_82 ) ;
struct V_1 * V_2 = F_39 ( V_133 -> V_83 . V_84 ) ;
struct V_505 * V_350 = & V_296 -> V_75 . V_423 . V_241 ;
const struct V_442 * V_440 = & V_133 -> V_514 . V_440 ;
enum V_87 V_87 = V_82 -> V_87 ;
enum V_229 V_229 ;
if ( ! ( V_133 -> V_514 . V_523 & F_195 ( & V_82 -> V_83 ) ) )
return;
F_2 ( F_181 ( V_87 ) , V_350 -> V_326 ) ;
F_78 (crtc, plane_id) {
if ( V_229 != V_103 )
F_233 ( V_82 , & V_350 -> V_424 [ V_229 ] ,
V_440 , V_229 ) ;
else
F_237 ( V_82 , & V_350 -> V_424 [ V_229 ] ,
V_440 ) ;
}
}
static void F_262 ( struct V_240 * V_133 ,
struct V_79 * V_296 )
{
struct V_81 * V_81 = F_38 ( V_296 -> V_83 . V_82 ) ;
struct V_251 * V_84 = V_81 -> V_83 . V_84 ;
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_524 * V_374 = & V_133 -> V_514 ;
struct V_524 * V_527 = & V_2 -> V_75 . V_516 ;
enum V_87 V_87 = V_81 -> V_87 ;
if ( ( V_374 -> V_523 & F_195 ( & V_81 -> V_83 ) ) == 0 )
return;
F_15 ( & V_2 -> V_75 . V_76 ) ;
if ( V_296 -> V_83 . V_528 )
F_261 ( V_133 , V_296 ) ;
F_257 ( V_527 , V_374 , V_87 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_263 ( struct V_251 * V_84 ,
struct V_304 * V_130 )
{
struct V_81 * V_82 ;
F_51 (dev, crtc) {
const struct V_349 * V_75 = & V_82 -> V_75 . V_121 . V_355 ;
if ( ! V_75 -> V_359 )
continue;
V_130 -> V_307 |= V_75 -> V_307 ;
V_130 -> V_351 |= V_75 -> V_351 ;
V_130 -> V_308 ++ ;
}
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_251 * V_84 = & V_2 -> V_529 ;
struct V_349 V_530 = {} , V_531 = {} , * V_532 ;
struct V_310 F_58 ;
struct V_304 V_130 = {} ;
struct V_373 V_374 = {} ;
enum V_305 V_372 ;
F_263 ( V_84 , & V_130 ) ;
F_136 ( V_84 , 1 , & V_130 , V_352 , & F_58 ) ;
F_169 ( V_84 , & V_130 , & F_58 , & V_530 ) ;
if ( F_130 ( V_2 ) >= 7 &&
V_130 . V_308 == 1 && V_130 . V_307 ) {
F_136 ( V_84 , 1 , & V_130 , V_309 , & F_58 ) ;
F_169 ( V_84 , & V_130 , & F_58 , & V_531 ) ;
V_532 = F_174 ( V_84 , & V_530 , & V_531 ) ;
} else {
V_532 = & V_530 ;
}
V_372 = ( V_532 == & V_530 ) ?
V_352 : V_309 ;
F_173 ( V_84 , V_532 , V_372 , & V_374 ) ;
F_180 ( V_2 , & V_374 ) ;
}
static void F_265 ( struct V_240 * V_133 ,
struct V_79 * V_296 )
{
struct V_1 * V_2 = F_39 ( V_296 -> V_83 . V_82 -> V_84 ) ;
struct V_81 * V_81 = F_38 ( V_296 -> V_83 . V_82 ) ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_81 -> V_75 . V_121 . V_355 = V_296 -> V_75 . V_355 . V_252 ;
F_264 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_266 ( struct V_240 * V_133 ,
struct V_79 * V_296 )
{
struct V_1 * V_2 = F_39 ( V_296 -> V_83 . V_82 -> V_84 ) ;
struct V_81 * V_81 = F_38 ( V_296 -> V_83 . V_82 ) ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
if ( V_296 -> V_75 . V_254 ) {
V_81 -> V_75 . V_121 . V_355 = V_296 -> V_75 . V_355 . V_241 ;
F_264 ( V_2 ) ;
}
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static inline void F_267 ( T_3 V_21 ,
struct V_499 * V_217 )
{
V_217 -> V_425 = V_21 & V_506 ;
V_217 -> V_501 = V_21 & V_533 ;
V_217 -> V_502 = ( V_21 >> V_507 ) &
V_534 ;
}
void F_268 ( struct V_432 * V_82 ,
struct V_505 * V_238 )
{
struct V_1 * V_2 = F_39 ( V_82 -> V_84 ) ;
struct V_81 * V_81 = F_38 ( V_82 ) ;
enum V_87 V_87 = V_81 -> V_87 ;
int V_217 , V_214 ;
enum V_229 V_229 ;
T_3 V_21 ;
V_214 = F_146 ( V_2 ) ;
F_78 (intel_crtc, plane_id) {
struct V_422 * V_75 = & V_238 -> V_424 [ V_229 ] ;
for ( V_217 = 0 ; V_217 <= V_214 ; V_217 ++ ) {
if ( V_229 != V_103 )
V_21 = F_3 ( F_234 ( V_87 , V_229 , V_217 ) ) ;
else
V_21 = F_3 ( F_238 ( V_87 , V_217 ) ) ;
F_267 ( V_21 , & V_75 -> V_75 [ V_217 ] ) ;
}
if ( V_229 != V_103 )
V_21 = F_3 ( F_235 ( V_87 , V_229 ) ) ;
else
V_21 = F_3 ( F_239 ( V_87 ) ) ;
F_267 ( V_21 , & V_75 -> V_504 ) ;
}
if ( ! V_81 -> V_121 )
return;
V_238 -> V_326 = F_3 ( F_181 ( V_87 ) ) ;
}
void F_269 ( struct V_251 * V_84 )
{
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_524 * V_396 = & V_2 -> V_75 . V_516 ;
struct V_442 * V_440 = & V_2 -> V_75 . V_516 . V_440 ;
struct V_432 * V_82 ;
struct V_81 * V_81 ;
struct V_79 * V_296 ;
F_198 ( V_2 , V_440 ) ;
F_270 (crtc, &dev->mode_config.crtc_list, head) {
V_81 = F_38 ( V_82 ) ;
V_296 = F_91 ( V_82 -> V_133 ) ;
F_268 ( V_82 , & V_296 -> V_75 . V_423 . V_241 ) ;
if ( V_81 -> V_121 )
V_396 -> V_523 |= F_195 ( V_82 ) ;
}
if ( V_2 -> V_419 ) {
V_2 -> V_75 . V_518 = true ;
} else {
memset ( V_440 , 0 , sizeof( * V_440 ) ) ;
}
}
static void F_271 ( struct V_432 * V_82 )
{
struct V_251 * V_84 = V_82 -> V_84 ;
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_373 * V_396 = & V_2 -> V_75 . V_396 ;
struct V_81 * V_81 = F_38 ( V_82 ) ;
struct V_79 * V_296 = F_91 ( V_82 -> V_133 ) ;
struct V_349 * V_121 = & V_296 -> V_75 . V_355 . V_241 ;
enum V_87 V_87 = V_81 -> V_87 ;
static const T_8 V_535 [] = {
[ V_93 ] = V_400 ,
[ V_96 ] = V_401 ,
[ V_97 ] = V_402 ,
} ;
V_396 -> V_385 [ V_87 ] = F_3 ( V_535 [ V_87 ] ) ;
if ( F_148 ( V_2 ) || F_149 ( V_2 ) )
V_396 -> V_384 [ V_87 ] = F_3 ( F_181 ( V_87 ) ) ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> V_359 = V_81 -> V_121 ;
if ( V_121 -> V_359 ) {
T_1 V_26 = V_396 -> V_385 [ V_87 ] ;
V_121 -> V_75 [ 0 ] . V_56 = true ;
V_121 -> V_75 [ 0 ] . V_295 = ( V_26 & V_536 ) >> V_386 ;
V_121 -> V_75 [ 0 ] . V_317 = ( V_26 & V_537 ) >> V_387 ;
V_121 -> V_75 [ 0 ] . V_318 = V_26 & V_538 ;
V_121 -> V_326 = V_396 -> V_384 [ V_87 ] ;
} else {
int V_217 , V_214 = F_146 ( V_2 ) ;
for ( V_217 = 0 ; V_217 <= V_214 ; V_217 ++ )
V_121 -> V_75 [ V_217 ] . V_56 = true ;
}
V_81 -> V_75 . V_121 . V_355 = * V_121 ;
}
static void F_272 ( struct V_1 * V_2 ,
struct V_172 * V_75 )
{
enum V_87 V_87 ;
T_3 V_26 ;
F_63 (dev_priv, pipe) {
V_26 = F_3 ( F_66 ( V_87 ) ) ;
V_75 -> V_173 [ V_87 ] . V_99 [ V_100 ] =
( V_26 >> V_175 ) & ( V_256 | V_539 ) ;
V_75 -> V_173 [ V_87 ] . V_99 [ V_103 ] =
( V_26 >> V_174 ) & ( V_256 | V_539 ) ;
V_75 -> V_173 [ V_87 ] . V_99 [ V_101 ] =
( V_26 >> F_67 ( 0 ) ) & ( V_256 | V_539 ) ;
V_75 -> V_173 [ V_87 ] . V_99 [ V_102 ] =
( V_26 >> F_67 ( 1 ) ) & ( V_256 | V_539 ) ;
}
V_26 = F_3 ( V_138 ) ;
V_75 -> V_181 . V_99 = F_273 ( V_26 , V_140 ) ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_103 ] = F_273 ( V_26 , V_182 ) ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_100 ] = F_274 ( V_26 , V_183 ) ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_100 ] = F_274 ( V_26 , V_184 ) ;
V_26 = F_3 ( V_185 ) ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_102 ] = F_274 ( V_26 , V_186 ) ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_103 ] = F_273 ( V_26 , V_187 ) ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_101 ] = F_274 ( V_26 , V_188 ) ;
V_26 = F_3 ( V_70 ) ;
V_75 -> V_181 . V_155 = F_273 ( V_26 , V_144 ) ;
if ( F_24 ( V_2 ) ) {
V_26 = F_3 ( V_189 ) ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_102 ] = F_274 ( V_26 , V_190 ) ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_101 ] = F_274 ( V_26 , V_191 ) ;
V_26 = F_3 ( V_192 ) ;
V_75 -> V_87 [ V_97 ] . V_99 [ V_102 ] = F_274 ( V_26 , V_193 ) ;
V_75 -> V_87 [ V_97 ] . V_99 [ V_101 ] = F_274 ( V_26 , V_194 ) ;
V_26 = F_3 ( V_195 ) ;
V_75 -> V_87 [ V_97 ] . V_99 [ V_100 ] = F_274 ( V_26 , V_196 ) ;
V_75 -> V_87 [ V_97 ] . V_99 [ V_103 ] = F_273 ( V_26 , V_197 ) ;
V_26 = F_3 ( V_176 ) ;
V_75 -> V_181 . V_99 |= F_273 ( V_26 , V_198 ) << 9 ;
V_75 -> V_87 [ V_97 ] . V_99 [ V_102 ] |= F_273 ( V_26 , V_199 ) << 8 ;
V_75 -> V_87 [ V_97 ] . V_99 [ V_101 ] |= F_273 ( V_26 , V_200 ) << 8 ;
V_75 -> V_87 [ V_97 ] . V_99 [ V_100 ] |= F_273 ( V_26 , V_201 ) << 8 ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_102 ] |= F_273 ( V_26 , V_202 ) << 8 ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_101 ] |= F_273 ( V_26 , V_203 ) << 8 ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_100 ] |= F_273 ( V_26 , V_204 ) << 8 ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_102 ] |= F_273 ( V_26 , V_205 ) << 8 ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_101 ] |= F_273 ( V_26 , V_206 ) << 8 ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_100 ] |= F_273 ( V_26 , V_207 ) << 8 ;
} else {
V_26 = F_3 ( V_208 ) ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_102 ] = F_274 ( V_26 , V_190 ) ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_101 ] = F_274 ( V_26 , V_191 ) ;
V_26 = F_3 ( V_176 ) ;
V_75 -> V_181 . V_99 |= F_273 ( V_26 , V_198 ) << 9 ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_102 ] |= F_273 ( V_26 , V_202 ) << 8 ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_101 ] |= F_273 ( V_26 , V_203 ) << 8 ;
V_75 -> V_87 [ V_96 ] . V_99 [ V_100 ] |= F_273 ( V_26 , V_204 ) << 8 ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_102 ] |= F_273 ( V_26 , V_205 ) << 8 ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_101 ] |= F_273 ( V_26 , V_206 ) << 8 ;
V_75 -> V_87 [ V_93 ] . V_99 [ V_100 ] |= F_273 ( V_26 , V_207 ) << 8 ;
}
}
void F_275 ( struct V_251 * V_84 )
{
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_172 * V_75 = & V_2 -> V_75 . V_77 ;
struct V_81 * V_82 ;
T_1 V_21 ;
F_272 ( V_2 , V_75 ) ;
V_75 -> V_78 = F_3 ( V_66 ) & V_67 ;
V_75 -> V_217 = V_213 ;
if ( F_24 ( V_2 ) ) {
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_21 = F_16 ( V_2 , V_63 ) ;
if ( V_21 & V_64 )
V_75 -> V_217 = V_215 ;
V_21 = F_16 ( V_2 , V_59 ) ;
V_21 |= V_62 ;
F_17 ( V_2 , V_59 , V_21 ) ;
if ( F_18 ( ( F_16 ( V_2 , V_59 ) &
V_62 ) == 0 , 3 ) ) {
F_13 ( L_51
L_52 ) ;
V_2 -> V_75 . V_214 = V_215 ;
} else {
V_21 = F_16 ( V_2 , V_59 ) ;
if ( ( V_21 & V_60 ) == 0 )
V_75 -> V_217 = V_216 ;
}
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
F_51 (dev, crtc) {
struct V_79 * V_80 =
F_91 ( V_82 -> V_83 . V_133 ) ;
struct V_233 * V_121 = & V_82 -> V_75 . V_121 . V_77 ;
const struct V_85 * V_86 =
& V_80 -> V_75 . V_77 . V_86 ;
enum V_87 V_87 = V_82 -> V_87 ;
enum V_229 V_229 ;
int V_217 ;
F_37 ( V_80 ) ;
V_121 -> V_236 = V_75 -> V_217 + 1 ;
V_121 -> V_78 = V_75 -> V_78 ;
for ( V_217 = 0 ; V_217 < V_121 -> V_236 ; V_217 ++ ) {
struct V_222 * V_223 =
& V_80 -> V_75 . V_77 . V_223 [ V_217 ] ;
V_121 -> V_181 [ V_217 ] . V_99 = V_75 -> V_181 . V_99 ;
V_121 -> V_181 [ V_217 ] . V_155 = V_75 -> V_181 . V_155 ;
F_78 (crtc, plane_id) {
V_121 -> V_75 [ V_217 ] . V_99 [ V_229 ] =
V_75 -> V_87 [ V_87 ] . V_99 [ V_229 ] ;
V_223 -> V_99 [ V_229 ] =
F_81 ( V_121 -> V_75 [ V_217 ] . V_99 [ V_229 ] ,
V_86 -> V_99 [ V_229 ] ) ;
}
}
F_78 (crtc, plane_id)
F_82 ( V_80 , V_217 ,
V_229 , V_219 ) ;
F_80 ( V_82 , V_121 , V_217 ) ;
V_80 -> V_75 . V_77 . V_241 = * V_121 ;
V_80 -> V_75 . V_77 . V_252 = * V_121 ;
F_13 ( L_53 ,
F_42 ( V_87 ) ,
V_75 -> V_87 [ V_87 ] . V_99 [ V_100 ] ,
V_75 -> V_87 [ V_87 ] . V_99 [ V_103 ] ,
V_75 -> V_87 [ V_87 ] . V_99 [ V_101 ] ,
V_75 -> V_87 [ V_87 ] . V_99 [ V_102 ] ) ;
}
F_13 ( L_54 ,
V_75 -> V_181 . V_99 , V_75 -> V_181 . V_155 , V_75 -> V_217 , V_75 -> V_78 ) ;
}
void F_276 ( struct V_1 * V_2 )
{
struct V_120 * V_99 ;
struct V_81 * V_82 ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
F_277 (&dev_priv->drm, plane) {
struct V_81 * V_82 =
F_65 ( V_2 , V_99 -> V_87 ) ;
struct V_79 * V_80 =
F_91 ( V_82 -> V_83 . V_133 ) ;
struct V_118 * V_119 =
F_90 ( V_99 -> V_83 . V_133 ) ;
struct V_233 * V_234 = & V_80 -> V_75 . V_77 . V_241 ;
const struct V_85 * V_86 =
& V_80 -> V_75 . V_77 . V_86 ;
enum V_229 V_229 = V_99 -> V_122 ;
int V_217 ;
if ( V_119 -> V_83 . V_124 )
continue;
for ( V_217 = 0 ; V_217 < V_234 -> V_236 ; V_217 ++ ) {
struct V_222 * V_223 =
& V_80 -> V_75 . V_77 . V_223 [ V_217 ] ;
V_223 -> V_99 [ V_229 ] = 0 ;
V_234 -> V_75 [ V_217 ] . V_99 [ V_229 ] =
F_81 ( V_223 -> V_99 [ V_229 ] ,
V_86 -> V_99 [ V_229 ] ) ;
}
}
F_51 (&dev_priv->drm, crtc) {
struct V_79 * V_80 =
F_91 ( V_82 -> V_83 . V_133 ) ;
V_80 -> V_75 . V_77 . V_252 =
V_80 -> V_75 . V_77 . V_241 ;
V_82 -> V_75 . V_121 . V_77 = V_80 -> V_75 . V_77 . V_241 ;
}
F_106 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
void F_278 ( struct V_251 * V_84 )
{
struct V_1 * V_2 = F_39 ( V_84 ) ;
struct V_373 * V_396 = & V_2 -> V_75 . V_396 ;
struct V_432 * V_82 ;
F_279 (dev, crtc)
F_271 ( V_82 ) ;
V_396 -> V_371 [ 0 ] = F_3 ( V_399 ) ;
V_396 -> V_371 [ 1 ] = F_3 ( V_398 ) ;
V_396 -> V_371 [ 2 ] = F_3 ( V_397 ) ;
V_396 -> V_382 [ 0 ] = F_3 ( V_407 ) ;
if ( F_130 ( V_2 ) >= 7 ) {
V_396 -> V_382 [ 1 ] = F_3 ( V_408 ) ;
V_396 -> V_382 [ 2 ] = F_3 ( V_409 ) ;
}
if ( F_148 ( V_2 ) || F_149 ( V_2 ) )
V_396 -> V_372 = ( F_3 ( V_403 ) & V_404 ) ?
V_309 : V_352 ;
else if ( F_154 ( V_2 ) )
V_396 -> V_372 = ( F_3 ( V_405 ) & V_406 ) ?
V_309 : V_352 ;
V_396 -> V_375 =
! ( F_3 ( V_9 ) & V_10 ) ;
}
void F_280 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_39 ( V_82 -> V_83 . V_84 ) ;
if ( V_2 -> V_153 . V_540 )
V_2 -> V_153 . V_540 ( V_82 ) ;
}
bool F_281 ( struct V_1 * V_2 , T_9 V_21 )
{
T_2 V_541 ;
F_282 ( & V_542 ) ;
V_541 = F_9 ( V_543 ) ;
if ( V_541 & V_544 ) {
F_283 ( L_55 ) ;
return false ;
}
V_541 = ( V_545 << V_546 ) |
( V_21 << V_547 ) | V_548 ;
F_284 ( V_543 , V_541 ) ;
F_285 ( V_543 ) ;
V_541 |= V_544 ;
F_284 ( V_543 , V_541 ) ;
return true ;
}
static void F_286 ( struct V_1 * V_2 )
{
T_1 V_549 ;
T_9 V_550 , V_551 , V_552 , V_553 ;
F_287 ( & V_542 ) ;
V_549 = F_3 ( V_554 ) ;
F_284 ( V_555 , F_3 ( V_555 ) | V_556 ) ;
F_284 ( V_557 , F_3 ( V_557 ) | V_558 ) ;
F_2 ( V_559 , 100000 ) ;
F_2 ( V_560 , 100000 ) ;
F_2 ( V_561 , 90000 ) ;
F_2 ( V_562 , 80000 ) ;
F_2 ( V_563 , 1 ) ;
V_550 = ( V_549 & V_564 ) >> V_565 ;
V_551 = ( V_549 & V_566 ) ;
V_552 = ( V_549 & V_567 ) >>
V_568 ;
V_553 = ( F_3 ( F_288 ( V_552 ) ) & V_569 ) >>
V_570 ;
V_2 -> V_46 . V_550 = V_550 ;
V_2 -> V_46 . V_552 = V_552 ;
V_2 -> V_46 . V_571 = V_552 ;
V_2 -> V_46 . V_572 = V_551 ;
V_2 -> V_46 . V_573 = V_552 ;
F_10 ( L_56 ,
V_550 , V_551 , V_552 ) ;
F_2 ( V_574 , V_575 | V_576 ) ;
F_2 ( V_577 , V_553 ) ;
F_25 ( V_577 ) ;
V_549 |= V_578 ;
F_2 ( V_554 , V_549 ) ;
if ( F_289 ( ( F_3 ( V_543 ) & V_544 ) == 0 , 10 ) )
F_19 ( L_57 ) ;
F_290 ( 1 ) ;
F_281 ( V_2 , V_552 ) ;
V_2 -> V_46 . V_579 = F_3 ( V_580 ) +
F_3 ( V_581 ) + F_3 ( V_582 ) ;
V_2 -> V_46 . V_583 = F_291 ( V_584 ) ;
V_2 -> V_46 . V_585 = F_3 ( V_586 ) ;
V_2 -> V_46 . V_587 = F_292 () ;
F_293 ( & V_542 ) ;
}
static void F_294 ( struct V_1 * V_2 )
{
T_2 V_541 ;
F_287 ( & V_542 ) ;
V_541 = F_9 ( V_543 ) ;
F_2 ( V_574 , F_3 ( V_574 ) & ~ V_576 ) ;
F_2 ( V_588 , V_589 ) ;
F_2 ( V_590 , F_3 ( V_590 ) & ~ V_591 ) ;
F_2 ( V_592 , V_591 ) ;
F_2 ( V_593 , F_3 ( V_593 ) | V_591 ) ;
F_281 ( V_2 , V_2 -> V_46 . V_552 ) ;
F_290 ( 1 ) ;
V_541 |= V_544 ;
F_2 ( V_543 , V_541 ) ;
F_290 ( 1 ) ;
F_293 ( & V_542 ) ;
}
static T_1 F_295 ( struct V_1 * V_2 , T_9 V_21 )
{
T_1 V_594 ;
if ( F_145 ( V_2 ) ) {
V_594 = ( V_2 -> V_57 . V_595 ) << 23 ;
if ( V_21 <= V_2 -> V_57 . V_596 )
V_594 |= ( V_2 -> V_57 . V_596 ) << 14 ;
} else {
V_594 = V_2 -> V_57 . V_595 << 24 ;
if ( V_21 <= V_2 -> V_57 . V_596 )
V_594 |= V_2 -> V_57 . V_596 << 16 ;
}
return V_594 ;
}
static void F_296 ( struct V_1 * V_2 , T_9 V_21 )
{
int V_597 ;
T_1 V_598 = 0 , V_599 = 0 ;
T_1 V_600 = 0 , V_601 = 0 ;
V_597 = V_2 -> V_57 . V_602 ;
switch ( V_2 -> V_57 . V_602 ) {
case V_603 :
if ( V_21 > V_2 -> V_57 . V_604 + 1 &&
V_21 > V_2 -> V_57 . V_605 )
V_597 = V_606 ;
break;
case V_606 :
if ( V_21 <= V_2 -> V_57 . V_604 &&
V_21 < V_2 -> V_57 . V_605 )
V_597 = V_603 ;
else if ( V_21 >= V_2 -> V_57 . V_607 &&
V_21 > V_2 -> V_57 . V_605 )
V_597 = V_608 ;
break;
case V_608 :
if ( V_21 < ( V_2 -> V_57 . V_609 + V_2 -> V_57 . V_607 ) > > 1 &&
V_21 < V_2 -> V_57 . V_605 )
V_597 = V_606 ;
break;
}
if ( V_21 <= V_2 -> V_57 . V_596 )
V_597 = V_603 ;
if ( V_21 >= V_2 -> V_57 . V_595 )
V_597 = V_608 ;
if ( V_597 == V_2 -> V_57 . V_602 )
return;
switch ( V_597 ) {
case V_603 :
V_600 = 16000 ;
V_598 = 95 ;
V_601 = 32000 ;
V_599 = 85 ;
break;
case V_606 :
V_600 = 13000 ;
V_598 = 90 ;
V_601 = 32000 ;
V_599 = 75 ;
break;
case V_608 :
V_600 = 10000 ;
V_598 = 85 ;
V_601 = 32000 ;
V_599 = 60 ;
break;
}
if ( F_23 ( V_2 ) )
goto V_610;
F_2 ( V_611 ,
F_297 ( V_2 , V_600 ) ) ;
F_2 ( V_612 ,
F_297 ( V_2 ,
V_600 * V_598 / 100 ) ) ;
F_2 ( V_613 ,
F_297 ( V_2 , V_601 ) ) ;
F_2 ( V_614 ,
F_297 ( V_2 ,
V_601 * V_599 / 100 ) ) ;
F_2 ( V_615 ,
V_616 |
V_617 |
V_618 |
V_619 |
V_620 |
V_621 ) ;
V_610:
V_2 -> V_57 . V_602 = V_597 ;
V_2 -> V_57 . V_622 = V_598 ;
V_2 -> V_57 . V_623 = V_599 ;
V_2 -> V_57 . V_624 = 0 ;
}
static T_1 F_298 ( struct V_1 * V_2 , T_9 V_21 )
{
T_1 V_625 = 0 ;
if ( V_21 > V_2 -> V_57 . V_596 )
V_625 |= V_626 | V_627 | V_628 ;
if ( V_21 < V_2 -> V_57 . V_595 )
V_625 |= V_626 | V_629 ;
V_625 &= V_2 -> V_630 ;
return F_299 ( V_2 , ~ V_625 ) ;
}
static int F_300 ( struct V_1 * V_2 , T_9 V_21 )
{
if ( V_21 != V_2 -> V_57 . V_605 ) {
F_296 ( V_2 , V_21 ) ;
if ( F_145 ( V_2 ) )
F_2 ( V_631 ,
F_301 ( V_21 ) ) ;
else if ( F_148 ( V_2 ) || F_149 ( V_2 ) )
F_2 ( V_631 ,
F_302 ( V_21 ) ) ;
else
F_2 ( V_631 ,
F_303 ( V_21 ) |
F_304 ( 0 ) |
V_632 ) ;
}
F_2 ( V_633 , F_295 ( V_2 , V_21 ) ) ;
F_2 ( V_634 , F_298 ( V_2 , V_21 ) ) ;
V_2 -> V_57 . V_605 = V_21 ;
F_305 ( F_306 ( V_2 , V_21 ) ) ;
return 0 ;
}
static int F_307 ( struct V_1 * V_2 , T_9 V_21 )
{
int V_635 ;
if ( F_308 ( F_24 ( V_2 ) && ( V_21 & 1 ) ,
L_58 ) )
V_21 &= ~ 1 ;
F_2 ( V_634 , F_298 ( V_2 , V_21 ) ) ;
if ( V_21 != V_2 -> V_57 . V_605 ) {
V_635 = F_17 ( V_2 , V_636 , V_21 ) ;
if ( V_635 )
return V_635 ;
F_296 ( V_2 , V_21 ) ;
}
V_2 -> V_57 . V_605 = V_21 ;
F_305 ( F_306 ( V_2 , V_21 ) ) ;
return 0 ;
}
static void F_309 ( struct V_1 * V_2 )
{
T_1 V_21 = V_2 -> V_57 . V_637 ;
int V_635 ;
if ( V_2 -> V_57 . V_605 <= V_21 )
return;
F_310 ( V_2 , V_638 ) ;
V_635 = F_307 ( V_2 , V_21 ) ;
F_311 ( V_2 , V_638 ) ;
if ( V_635 )
F_19 ( L_59 ) ;
}
void F_312 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( V_2 -> V_57 . V_125 ) {
T_9 V_639 ;
if ( V_2 -> V_630 & V_626 )
F_313 ( V_2 ) ;
F_2 ( V_634 ,
F_298 ( V_2 , V_2 -> V_57 . V_605 ) ) ;
F_314 ( V_2 ) ;
V_639 = F_58 ( V_2 -> V_57 . V_605 ,
V_2 -> V_57 . V_604 ) ;
if ( F_315 ( V_2 ,
F_316 ( V_639 ,
V_2 -> V_57 . V_596 ,
V_2 -> V_57 . V_595 ) ) )
F_10 ( L_60 ) ;
}
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
void F_317 ( struct V_1 * V_2 )
{
F_318 ( V_2 ) ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( V_2 -> V_57 . V_125 ) {
if ( F_23 ( V_2 ) || F_24 ( V_2 ) )
F_309 ( V_2 ) ;
else
F_300 ( V_2 , V_2 -> V_57 . V_637 ) ;
V_2 -> V_57 . V_624 = 0 ;
F_2 ( V_634 ,
F_299 ( V_2 , ~ 0 ) ) ;
}
F_20 ( & V_2 -> V_57 . V_58 ) ;
F_96 ( & V_2 -> V_57 . V_640 ) ;
while ( ! F_319 ( & V_2 -> V_57 . V_641 ) )
F_320 ( V_2 -> V_57 . V_641 . V_642 ) ;
F_101 ( & V_2 -> V_57 . V_640 ) ;
}
void F_321 ( struct V_1 * V_2 ,
struct V_643 * V_57 ,
unsigned long V_644 )
{
if ( ! ( V_2 -> V_645 . V_646 &&
V_2 -> V_57 . V_125 &&
V_2 -> V_57 . V_605 < V_2 -> V_57 . V_647 ) )
return;
if ( V_57 && F_322 ( V_584 , V_644 + V_648 ) )
V_57 = NULL ;
F_96 ( & V_2 -> V_57 . V_640 ) ;
if ( V_57 == NULL || F_319 ( & V_57 -> V_649 ) ) {
F_287 ( & V_2 -> V_650 ) ;
if ( V_2 -> V_57 . V_651 ) {
V_2 -> V_57 . V_652 = true ;
F_323 ( & V_2 -> V_57 . V_653 ) ;
}
F_293 ( & V_2 -> V_650 ) ;
if ( V_57 != NULL ) {
F_324 ( & V_57 -> V_649 , & V_2 -> V_57 . V_641 ) ;
V_57 -> V_654 ++ ;
} else
V_2 -> V_57 . V_654 ++ ;
}
F_101 ( & V_2 -> V_57 . V_640 ) ;
}
int F_315 ( struct V_1 * V_2 , T_9 V_21 )
{
int V_635 ;
F_282 ( & V_2 -> V_57 . V_58 ) ;
F_325 ( V_21 > V_2 -> V_57 . V_655 ) ;
F_325 ( V_21 < V_2 -> V_57 . V_656 ) ;
if ( ! V_2 -> V_57 . V_125 ) {
V_2 -> V_57 . V_605 = V_21 ;
return 0 ;
}
if ( F_23 ( V_2 ) || F_24 ( V_2 ) )
V_635 = F_307 ( V_2 , V_21 ) ;
else
V_635 = F_300 ( V_2 , V_21 ) ;
return V_635 ;
}
static void F_326 ( struct V_1 * V_2 )
{
F_2 ( V_657 , 0 ) ;
F_2 ( V_658 , 0 ) ;
}
static void F_327 ( struct V_1 * V_2 )
{
F_2 ( V_615 , 0 ) ;
}
static void F_328 ( struct V_1 * V_2 )
{
F_2 ( V_657 , 0 ) ;
F_2 ( V_631 , 1 << 31 ) ;
F_2 ( V_615 , 0 ) ;
}
static void F_329 ( struct V_1 * V_2 )
{
F_2 ( V_657 , 0 ) ;
}
static void F_330 ( struct V_1 * V_2 )
{
F_310 ( V_2 , V_659 ) ;
F_2 ( V_657 , 0 ) ;
F_311 ( V_2 , V_659 ) ;
}
static void F_331 ( struct V_1 * V_2 , T_1 V_660 )
{
if ( F_23 ( V_2 ) || F_24 ( V_2 ) ) {
if ( V_660 & ( V_661 | F_332 ( 1 ) ) )
V_660 = V_662 ;
else
V_660 = 0 ;
}
if ( F_333 ( V_2 ) )
F_10 ( L_61
L_62 ,
F_334 ( V_660 & V_662 ) ,
F_334 ( V_660 & V_663 ) ,
F_334 ( V_660 & V_664 ) ) ;
else
F_10 ( L_63 ,
F_334 ( V_660 & V_662 ) ) ;
}
static bool F_335 ( struct V_1 * V_2 )
{
struct V_665 * V_666 = & V_2 -> V_666 ;
bool V_667 = true ;
unsigned long V_668 ;
T_1 V_669 ;
int V_670 ;
V_669 = F_3 ( V_657 ) ;
V_670 = ( F_3 ( V_671 ) & V_672 ) >>
V_673 ;
F_10 ( L_64
L_65 ,
F_334 ( V_669 & V_674 ) ,
F_334 ( V_669 & V_662 ) ,
V_670 ) ;
if ( ! ( F_3 ( V_675 ) & V_676 ) ) {
F_10 ( L_66 ) ;
V_667 = false ;
}
V_668 = F_3 ( V_677 ) & V_678 ;
if ( ! ( ( V_668 >= V_666 -> V_679 ) &&
( V_668 + V_680 <= V_666 -> V_679 +
V_666 -> V_681 ) ) ) {
F_10 ( L_67 ) ;
V_667 = false ;
}
if ( ! ( ( ( F_3 ( V_682 ) & V_683 ) > 1 ) &&
( ( F_3 ( V_684 ) & V_683 ) > 1 ) &&
( ( F_3 ( V_685 ) & V_683 ) > 1 ) &&
( ( F_3 ( V_686 ) & V_683 ) > 1 ) ) ) {
F_10 ( L_68 ) ;
V_667 = false ;
}
if ( ! F_3 ( V_687 ) ||
! F_3 ( V_688 ) ||
! F_3 ( V_689 ) ) {
F_10 ( L_69 ) ;
V_667 = false ;
}
if ( ! F_3 ( V_690 ) ) {
F_10 ( L_70 ) ;
V_667 = false ;
}
if ( ! F_3 ( V_691 ) ) {
F_10 ( L_71 ) ;
V_667 = false ;
}
return V_667 ;
}
int F_336 ( struct V_1 * V_2 , int V_667 )
{
if ( F_92 ( V_2 ) -> V_692 < 6 )
return 0 ;
if ( ! V_667 )
return 0 ;
if ( F_337 ( V_2 ) && ! F_335 ( V_2 ) ) {
F_338 ( L_72 ) ;
return 0 ;
}
if ( V_667 >= 0 ) {
int V_625 ;
if ( F_333 ( V_2 ) )
V_625 = V_693 | V_694 |
V_695 ;
else
V_625 = V_693 ;
if ( ( V_667 & V_625 ) != V_667 )
F_10 ( L_73
L_74 ,
V_667 & V_625 , V_667 , V_625 ) ;
return V_667 & V_625 ;
}
if ( F_154 ( V_2 ) )
return ( V_693 | V_694 ) ;
return V_693 ;
}
static void F_339 ( struct V_1 * V_2 )
{
if ( F_337 ( V_2 ) ) {
T_1 V_696 = F_3 ( V_697 ) ;
V_2 -> V_57 . V_607 = ( V_696 >> 16 ) & 0xff ;
V_2 -> V_57 . V_609 = ( V_696 >> 8 ) & 0xff ;
V_2 -> V_57 . V_656 = ( V_696 >> 0 ) & 0xff ;
} else {
T_1 V_696 = F_3 ( V_698 ) ;
V_2 -> V_57 . V_607 = ( V_696 >> 0 ) & 0xff ;
V_2 -> V_57 . V_609 = ( V_696 >> 8 ) & 0xff ;
V_2 -> V_57 . V_656 = ( V_696 >> 16 ) & 0xff ;
}
V_2 -> V_57 . V_655 = V_2 -> V_57 . V_607 ;
V_2 -> V_57 . V_604 = V_2 -> V_57 . V_609 ;
if ( F_148 ( V_2 ) || F_149 ( V_2 ) ||
F_184 ( V_2 ) ) {
T_1 V_699 = 0 ;
if ( F_147 ( V_2 ,
V_700 ,
& V_699 ) == 0 )
V_2 -> V_57 . V_604 =
F_219 ( T_9 ,
( ( V_699 >> 8 ) & 0xff ) ,
V_2 -> V_57 . V_656 ,
V_2 -> V_57 . V_655 ) ;
}
if ( F_184 ( V_2 ) ) {
V_2 -> V_57 . V_607 *= V_701 ;
V_2 -> V_57 . V_609 *= V_701 ;
V_2 -> V_57 . V_656 *= V_701 ;
V_2 -> V_57 . V_655 *= V_701 ;
V_2 -> V_57 . V_604 *= V_701 ;
}
}
static void F_340 ( struct V_1 * V_2 ,
int (* F_341)( struct V_1 * , T_9 ) )
{
T_9 V_639 = V_2 -> V_57 . V_605 ;
V_2 -> V_57 . V_602 = - 1 ;
V_2 -> V_57 . V_605 = - 1 ;
if ( F_341 ( V_2 , V_639 ) )
F_19 ( L_75 ) ;
}
static void F_342 ( struct V_1 * V_2 )
{
F_310 ( V_2 , V_659 ) ;
F_2 ( V_702 ,
F_301 ( V_2 -> V_57 . V_609 ) ) ;
F_2 ( V_703 ,
F_297 ( V_2 , 1000000 ) ) ;
F_2 ( V_704 , 0xa ) ;
F_340 ( V_2 , F_300 ) ;
F_311 ( V_2 , V_659 ) ;
}
static void F_343 ( struct V_1 * V_2 )
{
struct V_705 * V_706 ;
enum V_707 V_122 ;
T_3 V_708 = 0 ;
F_2 ( V_671 , 0 ) ;
F_310 ( V_2 , V_659 ) ;
F_2 ( V_657 , 0 ) ;
if ( F_188 ( V_2 ) )
F_2 ( V_709 , 108 << 16 ) ;
else
F_2 ( V_709 , 54 << 16 ) ;
F_2 ( V_710 , 125000 ) ;
F_2 ( V_711 , 25 ) ;
F_344 (engine, dev_priv, id)
F_2 ( F_345 ( V_706 -> V_712 ) , 10 ) ;
if ( F_346 ( V_2 ) )
F_2 ( V_713 , 0xA ) ;
F_2 ( V_714 , 0 ) ;
F_2 ( V_715 , 25 ) ;
F_2 ( V_716 , 25 ) ;
if ( F_347 () & V_693 )
V_708 = V_662 ;
F_338 ( L_76 , F_334 ( V_708 & V_662 ) ) ;
F_2 ( V_717 , 37500 ) ;
F_2 ( V_657 ,
V_674 | F_332 ( 1 ) | V_708 ) ;
if ( F_348 ( V_2 ) )
F_2 ( V_658 , 0 ) ;
else
F_2 ( V_658 , ( V_708 & V_662 ) ?
( V_718 | V_719 ) : 0 ) ;
F_311 ( V_2 , V_659 ) ;
}
static void F_349 ( struct V_1 * V_2 )
{
struct V_705 * V_706 ;
enum V_707 V_122 ;
T_3 V_708 = 0 ;
F_2 ( V_671 , 0 ) ;
F_310 ( V_2 , V_659 ) ;
F_2 ( V_657 , 0 ) ;
F_2 ( V_709 , 40 << 16 ) ;
F_2 ( V_710 , 125000 ) ;
F_2 ( V_711 , 25 ) ;
F_344 (engine, dev_priv, id)
F_2 ( F_345 ( V_706 -> V_712 ) , 10 ) ;
F_2 ( V_714 , 0 ) ;
if ( F_149 ( V_2 ) )
F_2 ( V_717 , 625 ) ;
else
F_2 ( V_717 , 50000 ) ;
if ( F_347 () & V_693 )
V_708 = V_662 ;
F_331 ( V_2 , V_708 ) ;
if ( F_149 ( V_2 ) )
F_2 ( V_657 , V_674 |
V_661 |
V_708 ) ;
else
F_2 ( V_657 , V_674 |
F_332 ( 1 ) |
V_708 ) ;
F_2 ( V_631 ,
F_302 ( V_2 -> V_57 . V_609 ) ) ;
F_2 ( V_702 ,
F_302 ( V_2 -> V_57 . V_609 ) ) ;
F_2 ( V_703 , 100000000 / 128 ) ;
F_2 ( V_633 ,
V_2 -> V_57 . V_595 << 24 |
V_2 -> V_57 . V_596 << 16 ) ;
F_2 ( V_612 , 7600000 / 128 ) ;
F_2 ( V_614 , 31300000 / 128 ) ;
F_2 ( V_611 , 66000 ) ;
F_2 ( V_613 , 350000 ) ;
F_2 ( V_704 , 10 ) ;
F_2 ( V_615 ,
V_616 |
V_617 |
V_618 |
V_619 |
V_620 |
V_621 ) ;
F_340 ( V_2 , F_300 ) ;
F_311 ( V_2 , V_659 ) ;
}
static void F_350 ( struct V_1 * V_2 )
{
struct V_705 * V_706 ;
enum V_707 V_122 ;
T_1 V_720 , V_708 = 0 ;
T_1 V_721 ;
int V_722 ;
int V_74 ;
F_72 ( ! F_351 ( & V_2 -> V_57 . V_58 ) ) ;
F_2 ( V_671 , 0 ) ;
V_721 = F_3 ( V_723 ) ;
if ( V_721 ) {
F_19 ( L_77 , V_721 ) ;
F_2 ( V_723 , V_721 ) ;
}
F_310 ( V_2 , V_659 ) ;
F_2 ( V_657 , 0 ) ;
F_2 ( V_724 , 1000 << 16 ) ;
F_2 ( V_709 , 40 << 16 | 30 ) ;
F_2 ( V_725 , 30 ) ;
F_2 ( V_710 , 125000 ) ;
F_2 ( V_711 , 25 ) ;
F_344 (engine, dev_priv, id)
F_2 ( F_345 ( V_706 -> V_712 ) , 10 ) ;
F_2 ( V_714 , 0 ) ;
F_2 ( V_726 , 1000 ) ;
if ( F_154 ( V_2 ) )
F_2 ( V_717 , 125000 ) ;
else
F_2 ( V_717 , 50000 ) ;
F_2 ( V_727 , 150000 ) ;
F_2 ( V_728 , 64000 ) ;
V_722 = F_347 () ;
if ( V_722 & V_693 )
V_708 |= V_662 ;
if ( ! F_148 ( V_2 ) ) {
if ( V_722 & V_694 )
V_708 |= V_663 ;
if ( V_722 & V_695 )
V_708 |= V_664 ;
}
F_331 ( V_2 , V_708 ) ;
F_2 ( V_657 ,
V_708 |
F_332 ( 1 ) |
V_674 ) ;
F_2 ( V_703 , 50000 ) ;
F_2 ( V_704 , 10 ) ;
F_340 ( V_2 , F_300 ) ;
V_720 = 0 ;
V_74 = F_147 ( V_2 , V_729 , & V_720 ) ;
if ( F_160 ( V_2 ) && V_74 ) {
F_10 ( L_78 ) ;
} else if ( F_160 ( V_2 ) && ( F_352 ( V_720 & 0xff ) < 450 ) ) {
F_10 ( L_79 ,
F_352 ( V_720 & 0xff ) , 450 ) ;
V_720 &= 0xffff00 ;
V_720 |= F_353 ( 450 ) ;
V_74 = F_190 ( V_2 , V_730 , V_720 ) ;
if ( V_74 )
F_19 ( L_80 ) ;
}
F_311 ( V_2 , V_659 ) ;
}
static void F_354 ( struct V_1 * V_2 )
{
int V_656 = 15 ;
unsigned int V_731 ;
unsigned int V_732 , V_733 ;
unsigned int V_734 , V_735 ;
int V_736 = 180 ;
struct V_737 * V_738 ;
F_72 ( ! F_351 ( & V_2 -> V_57 . V_58 ) ) ;
V_738 = F_355 ( 0 ) ;
if ( V_738 ) {
V_732 = V_738 -> V_739 . V_655 ;
F_356 ( V_738 ) ;
} else {
V_732 = V_740 ;
}
V_732 /= 1000 ;
V_733 = F_3 ( V_741 ) & 0xf ;
V_733 = F_357 ( V_733 , 8 , 3 ) ;
if ( F_184 ( V_2 ) ) {
V_735 = V_2 -> V_57 . V_656 / V_701 ;
V_734 = V_2 -> V_57 . V_655 / V_701 ;
} else {
V_735 = V_2 -> V_57 . V_656 ;
V_734 = V_2 -> V_57 . V_655 ;
}
for ( V_731 = V_734 ; V_731 >= V_735 ; V_731 -- ) {
int V_742 = V_734 - V_731 ;
unsigned int V_743 = 0 , V_744 = 0 ;
if ( F_184 ( V_2 ) ) {
V_744 = V_731 ;
} else if ( F_92 ( V_2 ) -> V_692 >= 8 ) {
V_744 = F_58 ( V_733 , V_731 ) ;
} else if ( F_148 ( V_2 ) ) {
V_744 = F_357 ( V_731 , 5 , 4 ) ;
V_744 = F_58 ( V_733 , V_744 ) ;
} else {
if ( V_731 < V_656 )
V_743 = 800 ;
else
V_743 = V_732 - ( ( V_742 * V_736 ) / 2 ) ;
V_743 = F_141 ( V_743 , 100 ) ;
}
F_190 ( V_2 ,
V_745 ,
V_743 << V_746 |
V_744 << V_747 |
V_731 ) ;
}
}
static int F_358 ( struct V_1 * V_2 )
{
T_1 V_21 , V_748 ;
V_21 = F_16 ( V_2 , V_749 ) ;
switch ( F_92 ( V_2 ) -> V_750 . V_751 ) {
case 8 :
V_748 = ( V_21 >> V_752 ) ;
break;
case 12 :
V_748 = ( V_21 >> V_753 ) ;
break;
case 16 :
default:
V_748 = ( V_21 >> V_754 ) ;
break;
}
V_748 = ( V_748 & V_755 ) ;
return V_748 ;
}
static int F_359 ( struct V_1 * V_2 )
{
T_1 V_21 , V_756 ;
V_21 = F_16 ( V_2 , V_757 ) ;
V_756 = ( V_21 >> V_758 ) & V_759 ;
return V_756 ;
}
static int F_360 ( struct V_1 * V_2 )
{
T_1 V_21 , V_760 ;
V_21 = F_16 ( V_2 , V_749 ) ;
V_760 = ( V_21 & V_755 ) ;
return V_760 ;
}
static T_1 F_361 ( struct V_1 * V_2 )
{
T_1 V_21 , V_761 ;
V_21 = F_16 ( V_2 , V_762 ) ;
V_761 = ( ( V_21 >> V_763 ) &
V_755 ) ;
return V_761 ;
}
static int F_362 ( struct V_1 * V_2 )
{
T_1 V_21 , V_760 ;
V_21 = F_363 ( V_2 , V_764 ) ;
V_760 = ( V_21 & V_765 ) >> V_766 ;
return V_760 ;
}
static int F_364 ( struct V_1 * V_2 )
{
T_1 V_21 , V_748 ;
V_21 = F_363 ( V_2 , V_764 ) ;
V_748 = ( V_21 & V_767 ) >> V_768 ;
V_748 = F_73 ( T_1 , V_748 , 0xea ) ;
return V_748 ;
}
static int F_365 ( struct V_1 * V_2 )
{
T_1 V_21 , V_756 ;
V_21 = F_363 ( V_2 , V_769 ) ;
V_756 = ( V_21 & V_770 ) >> V_771 ;
V_21 = F_363 ( V_2 , V_772 ) ;
V_756 |= ( V_21 & V_773 ) << 5 ;
return V_756 ;
}
static int F_366 ( struct V_1 * V_2 )
{
T_1 V_21 ;
V_21 = F_16 ( V_2 , V_774 ) & 0xff ;
return F_157 ( T_1 , V_21 , 0xc0 ) ;
}
static void F_367 ( struct V_1 * V_2 )
{
unsigned long V_775 = F_3 ( V_776 ) & ~ 4095 ;
F_72 ( V_775 != V_2 -> V_777 . V_778 +
V_2 -> V_779 -> V_780 -> V_437 ) ;
}
static void F_368 ( struct V_1 * V_2 )
{
unsigned long V_775 = F_3 ( V_776 ) & ~ 4095 ;
F_72 ( ( V_775 >> V_781 ) == 0 ) ;
}
static void F_369 ( struct V_1 * V_2 )
{
struct V_665 * V_666 = & V_2 -> V_666 ;
unsigned long V_782 , V_783 ;
T_1 V_784 ;
int V_785 = 32 * 1024 ;
V_784 = F_3 ( V_776 ) ;
if ( ( V_784 >> V_781 ) == 0 ) {
F_10 ( L_81 ) ;
V_783 = ( V_2 -> V_777 . V_778 +
( V_666 -> V_786 - V_785 ) ) ;
V_782 = ( V_783 & ( ~ 4095 ) ) ;
F_2 ( V_776 , V_782 ) ;
}
F_10 ( L_82 , F_3 ( V_776 ) ) ;
}
static void F_370 ( struct V_1 * V_2 )
{
struct V_288 * V_787 ;
unsigned long V_782 ;
T_1 V_784 ;
int V_785 = 24 * 1024 ;
V_784 = F_3 ( V_776 ) ;
if ( V_784 ) {
int V_788 ;
V_788 = ( V_784 & ( ~ 4095 ) ) - V_2 -> V_777 . V_778 ;
V_787 = F_371 ( V_2 ,
V_788 ,
V_789 ,
V_785 ) ;
goto V_238;
}
F_10 ( L_81 ) ;
V_787 = F_372 ( V_2 , V_785 ) ;
if ( ! V_787 ) {
F_283 ( L_83 ) ;
goto V_238;
}
V_782 = V_2 -> V_777 . V_778 + V_787 -> V_780 -> V_437 ;
F_2 ( V_776 , V_782 ) ;
V_238:
F_10 ( L_82 , F_3 ( V_776 ) ) ;
V_2 -> V_779 = V_787 ;
}
static void F_373 ( struct V_1 * V_2 )
{
if ( F_72 ( ! V_2 -> V_779 ) )
return;
F_374 ( V_2 -> V_779 ) ;
V_2 -> V_779 = NULL ;
}
static void F_375 ( struct V_1 * V_2 )
{
V_2 -> V_57 . V_790 =
F_376 ( V_2 , L_84 ,
V_791 ,
V_2 -> V_792 ) ;
F_10 ( L_85 ,
V_2 -> V_57 . V_790 ) ;
}
static void F_377 ( struct V_1 * V_2 )
{
T_1 V_21 ;
F_370 ( V_2 ) ;
F_375 ( V_2 ) ;
V_21 = F_16 ( V_2 , V_793 ) ;
switch ( ( V_21 >> 6 ) & 3 ) {
case 0 :
case 1 :
V_2 -> V_36 = 800 ;
break;
case 2 :
V_2 -> V_36 = 1066 ;
break;
case 3 :
V_2 -> V_36 = 1333 ;
break;
}
F_10 ( L_86 , V_2 -> V_36 ) ;
V_2 -> V_57 . V_655 = F_364 ( V_2 ) ;
V_2 -> V_57 . V_607 = V_2 -> V_57 . V_655 ;
F_10 ( L_87 ,
F_306 ( V_2 , V_2 -> V_57 . V_655 ) ,
V_2 -> V_57 . V_655 ) ;
V_2 -> V_57 . V_604 = F_365 ( V_2 ) ;
F_10 ( L_88 ,
F_306 ( V_2 , V_2 -> V_57 . V_604 ) ,
V_2 -> V_57 . V_604 ) ;
V_2 -> V_57 . V_609 = F_362 ( V_2 ) ;
F_10 ( L_89 ,
F_306 ( V_2 , V_2 -> V_57 . V_609 ) ,
V_2 -> V_57 . V_609 ) ;
V_2 -> V_57 . V_656 = F_366 ( V_2 ) ;
F_10 ( L_90 ,
F_306 ( V_2 , V_2 -> V_57 . V_656 ) ,
V_2 -> V_57 . V_656 ) ;
}
static void F_378 ( struct V_1 * V_2 )
{
T_1 V_21 ;
F_369 ( V_2 ) ;
F_375 ( V_2 ) ;
F_15 ( & V_2 -> V_794 ) ;
V_21 = F_379 ( V_2 , V_795 ) ;
F_20 ( & V_2 -> V_794 ) ;
switch ( ( V_21 >> 2 ) & 0x7 ) {
case 3 :
V_2 -> V_36 = 2000 ;
break;
default:
V_2 -> V_36 = 1600 ;
break;
}
F_10 ( L_86 , V_2 -> V_36 ) ;
V_2 -> V_57 . V_655 = F_358 ( V_2 ) ;
V_2 -> V_57 . V_607 = V_2 -> V_57 . V_655 ;
F_10 ( L_87 ,
F_306 ( V_2 , V_2 -> V_57 . V_655 ) ,
V_2 -> V_57 . V_655 ) ;
V_2 -> V_57 . V_604 = F_359 ( V_2 ) ;
F_10 ( L_88 ,
F_306 ( V_2 , V_2 -> V_57 . V_604 ) ,
V_2 -> V_57 . V_604 ) ;
V_2 -> V_57 . V_609 = F_360 ( V_2 ) ;
F_10 ( L_91 ,
F_306 ( V_2 , V_2 -> V_57 . V_609 ) ,
V_2 -> V_57 . V_609 ) ;
V_2 -> V_57 . V_656 = F_361 ( V_2 ) ;
F_10 ( L_90 ,
F_306 ( V_2 , V_2 -> V_57 . V_656 ) ,
V_2 -> V_57 . V_656 ) ;
F_308 ( ( V_2 -> V_57 . V_655 |
V_2 -> V_57 . V_604 |
V_2 -> V_57 . V_609 |
V_2 -> V_57 . V_656 ) & 1 ,
L_92 ) ;
}
static void F_380 ( struct V_1 * V_2 )
{
F_373 ( V_2 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_705 * V_706 ;
enum V_707 V_122 ;
T_1 V_721 , V_21 , V_722 = 0 , V_784 ;
F_72 ( ! F_351 ( & V_2 -> V_57 . V_58 ) ) ;
V_721 = F_3 ( V_723 ) & ~ ( V_796 |
V_797 ) ;
if ( V_721 ) {
F_10 ( L_77 ,
V_721 ) ;
F_2 ( V_723 , V_721 ) ;
}
F_368 ( V_2 ) ;
F_310 ( V_2 , V_659 ) ;
F_2 ( V_657 , 0 ) ;
F_2 ( V_709 , 40 << 16 ) ;
F_2 ( V_710 , 125000 ) ;
F_2 ( V_711 , 25 ) ;
F_344 (engine, dev_priv, id)
F_2 ( F_345 ( V_706 -> V_712 ) , 10 ) ;
F_2 ( V_714 , 0 ) ;
F_2 ( V_717 , 0x186 ) ;
F_2 ( V_798 ,
F_31 ( V_799 |
V_800 |
V_801 ) ) ;
V_784 = F_3 ( V_776 ) ;
if ( ( F_347 () & V_693 ) &&
( V_784 >> V_781 ) )
V_722 = V_661 ;
F_2 ( V_657 , V_722 ) ;
F_2 ( V_703 , 1000000 ) ;
F_2 ( V_612 , 59400 ) ;
F_2 ( V_614 , 245000 ) ;
F_2 ( V_611 , 66000 ) ;
F_2 ( V_613 , 350000 ) ;
F_2 ( V_704 , 10 ) ;
F_2 ( V_615 ,
V_617 |
V_618 |
V_619 |
V_620 |
V_621 ) ;
V_21 = V_802 |
V_803 |
V_804 ;
F_17 ( V_2 , V_805 , V_21 ) ;
V_21 = F_16 ( V_2 , V_793 ) ;
F_308 ( ( V_21 & V_806 ) == 0 , L_93 ) ;
F_10 ( L_94 , F_382 ( V_21 & V_806 ) ) ;
F_10 ( L_95 , V_21 ) ;
F_340 ( V_2 , F_307 ) ;
F_311 ( V_2 , V_659 ) ;
}
static void F_383 ( struct V_1 * V_2 )
{
struct V_705 * V_706 ;
enum V_707 V_122 ;
T_1 V_721 , V_21 , V_722 = 0 ;
F_72 ( ! F_351 ( & V_2 -> V_57 . V_58 ) ) ;
F_367 ( V_2 ) ;
V_721 = F_3 ( V_723 ) ;
if ( V_721 ) {
F_10 ( L_77 ,
V_721 ) ;
F_2 ( V_723 , V_721 ) ;
}
F_310 ( V_2 , V_659 ) ;
F_2 ( V_657 , 0 ) ;
F_2 ( V_703 , 1000000 ) ;
F_2 ( V_612 , 59400 ) ;
F_2 ( V_614 , 245000 ) ;
F_2 ( V_611 , 66000 ) ;
F_2 ( V_613 , 350000 ) ;
F_2 ( V_704 , 10 ) ;
F_2 ( V_615 ,
V_616 |
V_617 |
V_618 |
V_619 |
V_620 |
V_807 ) ;
F_2 ( V_709 , 0x00280000 ) ;
F_2 ( V_710 , 125000 ) ;
F_2 ( V_711 , 25 ) ;
F_344 (engine, dev_priv, id)
F_2 ( F_345 ( V_706 -> V_712 ) , 10 ) ;
F_2 ( V_717 , 0x557 ) ;
F_2 ( V_798 ,
F_31 ( V_799 |
V_808 |
V_809 |
V_800 |
V_801 ) ) ;
if ( F_347 () & V_693 )
V_722 = V_661 | V_810 ;
F_331 ( V_2 , V_722 ) ;
F_2 ( V_657 , V_722 ) ;
V_21 = V_802 |
V_803 |
V_811 ;
F_17 ( V_2 , V_805 , V_21 ) ;
V_21 = F_16 ( V_2 , V_793 ) ;
F_308 ( ( V_21 & V_806 ) == 0 , L_93 ) ;
F_10 ( L_94 , F_382 ( V_21 & V_806 ) ) ;
F_10 ( L_95 , V_21 ) ;
F_340 ( V_2 , F_307 ) ;
F_311 ( V_2 , V_659 ) ;
}
static unsigned long F_384 ( T_1 V_812 )
{
unsigned long V_639 ;
int div = ( V_812 & 0x3f0000 ) >> 16 ;
int V_813 = ( V_812 & 0x3000 ) >> 12 ;
int V_814 = ( V_812 & 0x7 ) ;
if ( ! V_814 )
return 0 ;
V_639 = ( ( div * 133333 ) / ( ( 1 << V_813 ) * V_814 ) ) ;
return V_639 ;
}
static unsigned long F_385 ( struct V_1 * V_2 )
{
T_10 V_815 , V_742 , V_74 ;
T_1 V_816 , V_817 , V_818 , V_819 = 0 , V_820 = 0 ;
unsigned long V_821 = F_291 ( V_584 ) , V_822 ;
int V_54 ;
F_282 ( & V_542 ) ;
V_822 = V_821 - V_2 -> V_46 . V_583 ;
if ( V_822 <= 10 )
return V_2 -> V_46 . V_823 ;
V_816 = F_3 ( V_580 ) ;
V_817 = F_3 ( V_581 ) ;
V_818 = F_3 ( V_582 ) ;
V_815 = V_816 + V_817 + V_818 ;
if ( V_815 < V_2 -> V_46 . V_579 ) {
V_742 = ~ 0UL - V_2 -> V_46 . V_579 ;
V_742 += V_815 ;
} else {
V_742 = V_815 - V_2 -> V_46 . V_579 ;
}
for ( V_54 = 0 ; V_54 < F_12 ( V_824 ) ; V_54 ++ ) {
if ( V_824 [ V_54 ] . V_54 == V_2 -> V_46 . V_48 &&
V_824 [ V_54 ] . V_825 == V_2 -> V_46 . V_47 ) {
V_819 = V_824 [ V_54 ] . V_819 ;
V_820 = V_824 [ V_54 ] . V_820 ;
break;
}
}
V_742 = F_213 ( V_742 , V_822 ) ;
V_74 = ( ( V_819 * V_742 ) + V_820 ) ;
V_74 = F_213 ( V_74 , 10 ) ;
V_2 -> V_46 . V_579 = V_815 ;
V_2 -> V_46 . V_583 = V_821 ;
V_2 -> V_46 . V_823 = V_74 ;
return V_74 ;
}
unsigned long F_386 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
if ( F_92 ( V_2 ) -> V_692 != 5 )
return 0 ;
F_287 ( & V_542 ) ;
V_21 = F_385 ( V_2 ) ;
F_293 ( & V_542 ) ;
return V_21 ;
}
unsigned long F_387 ( struct V_1 * V_2 )
{
unsigned long V_819 , V_826 , V_364 ;
T_1 V_827 ;
V_827 = F_3 ( V_828 ) ;
V_819 = ( ( V_827 & V_829 ) >> V_830 ) ;
V_826 = F_388 ( V_831 ) ;
V_364 = V_827 & V_832 ;
return ( ( V_819 * V_826 ) / 127 ) - V_364 ;
}
static int F_389 ( T_9 V_833 )
{
if ( V_833 == 0 )
return 0 ;
if ( V_833 >= 8 && V_833 < 31 )
V_833 = 31 ;
return ( V_833 + 2 ) * 125 ;
}
static T_1 F_390 ( struct V_1 * V_2 , T_9 V_833 )
{
const int V_834 = F_389 ( V_833 ) ;
const int V_835 = V_834 - 1125 ;
if ( F_92 ( V_2 ) -> V_836 )
return V_835 > 0 ? V_835 : 0 ;
return V_834 ;
}
static void F_391 ( struct V_1 * V_2 )
{
T_10 V_821 , V_742 , V_837 ;
T_1 V_838 ;
F_282 ( & V_542 ) ;
V_821 = F_292 () ;
V_837 = V_821 - V_2 -> V_46 . V_587 ;
F_392 ( V_837 , V_839 ) ;
if ( ! V_837 )
return;
V_838 = F_3 ( V_586 ) ;
if ( V_838 < V_2 -> V_46 . V_585 ) {
V_742 = ~ 0UL - V_2 -> V_46 . V_585 ;
V_742 += V_838 ;
} else {
V_742 = V_838 - V_2 -> V_46 . V_585 ;
}
V_2 -> V_46 . V_585 = V_838 ;
V_2 -> V_46 . V_587 = V_821 ;
V_742 = V_742 * 1181 ;
V_742 = F_213 ( V_742 , V_837 * 10 ) ;
V_2 -> V_46 . V_840 = V_742 ;
}
void F_393 ( struct V_1 * V_2 )
{
if ( F_92 ( V_2 ) -> V_692 != 5 )
return;
F_287 ( & V_542 ) ;
F_391 ( V_2 ) ;
F_293 ( & V_542 ) ;
}
static unsigned long F_394 ( struct V_1 * V_2 )
{
unsigned long V_825 , V_841 , V_842 , V_843 , V_844 ;
T_1 V_833 , V_845 ;
F_282 ( & V_542 ) ;
V_833 = F_3 ( F_288 ( V_2 -> V_57 . V_605 ) ) ;
V_833 = ( V_833 >> 24 ) & 0x7f ;
V_845 = F_390 ( V_2 , V_833 ) ;
V_842 = V_845 ;
V_825 = F_387 ( V_2 ) ;
if ( V_825 > 80 )
V_841 = ( ( V_825 * 2349 ) + 135940 ) ;
else if ( V_825 >= 50 )
V_841 = ( ( V_825 * 964 ) + 29317 ) ;
else
V_841 = ( ( V_825 * 301 ) + 1004 ) ;
V_841 = V_841 * ( ( 150142 * V_842 ) / 10000 - 78642 ) ;
V_841 /= 100000 ;
V_843 = ( V_841 * V_2 -> V_46 . V_841 ) ;
V_844 = ( V_843 * V_842 ) / 10000 ;
V_844 /= 100 ;
F_391 ( V_2 ) ;
return V_2 -> V_46 . V_840 + V_844 ;
}
unsigned long F_395 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
if ( F_92 ( V_2 ) -> V_692 != 5 )
return 0 ;
F_287 ( & V_542 ) ;
V_21 = F_394 ( V_2 ) ;
F_293 ( & V_542 ) ;
return V_21 ;
}
unsigned long F_396 ( void )
{
struct V_1 * V_2 ;
unsigned long V_846 , V_847 , V_74 = 0 ;
F_287 ( & V_542 ) ;
if ( ! V_848 )
goto V_849;
V_2 = V_848 ;
V_846 = F_385 ( V_2 ) ;
V_847 = F_394 ( V_2 ) ;
V_74 = V_846 + V_847 ;
V_849:
F_293 ( & V_542 ) ;
return V_74 ;
}
bool F_397 ( void )
{
struct V_1 * V_2 ;
bool V_74 = true ;
F_287 ( & V_542 ) ;
if ( ! V_848 ) {
V_74 = false ;
goto V_849;
}
V_2 = V_848 ;
if ( V_2 -> V_46 . V_571 > V_2 -> V_46 . V_550 )
V_2 -> V_46 . V_571 -- ;
V_849:
F_293 ( & V_542 ) ;
return V_74 ;
}
bool F_398 ( void )
{
struct V_1 * V_2 ;
bool V_74 = true ;
F_287 ( & V_542 ) ;
if ( ! V_848 ) {
V_74 = false ;
goto V_849;
}
V_2 = V_848 ;
if ( V_2 -> V_46 . V_571 < V_2 -> V_46 . V_572 )
V_2 -> V_46 . V_571 ++ ;
V_849:
F_293 ( & V_542 ) ;
return V_74 ;
}
bool F_399 ( void )
{
bool V_74 = false ;
F_287 ( & V_542 ) ;
if ( V_848 )
V_74 = V_848 -> V_645 . V_646 ;
F_293 ( & V_542 ) ;
return V_74 ;
}
bool F_400 ( void )
{
struct V_1 * V_2 ;
bool V_74 = true ;
F_287 ( & V_542 ) ;
if ( ! V_848 ) {
V_74 = false ;
goto V_849;
}
V_2 = V_848 ;
V_2 -> V_46 . V_571 = V_2 -> V_46 . V_552 ;
if ( ! F_281 ( V_2 , V_2 -> V_46 . V_552 ) )
V_74 = false ;
V_849:
F_293 ( & V_542 ) ;
return V_74 ;
}
static void
F_401 ( void )
{
void (* V_649)( void );
V_649 = F_402 ( V_850 ) ;
if ( V_649 ) {
V_649 () ;
F_403 ( V_850 ) ;
}
}
void F_404 ( struct V_1 * V_2 )
{
F_287 ( & V_542 ) ;
V_848 = V_2 ;
F_293 ( & V_542 ) ;
F_401 () ;
}
void F_405 ( void )
{
F_287 ( & V_542 ) ;
V_848 = NULL ;
F_293 ( & V_542 ) ;
}
static void F_406 ( struct V_1 * V_2 )
{
T_1 V_851 ;
T_9 V_852 [ 16 ] ;
int V_54 ;
F_2 ( V_853 , 0 ) ;
F_25 ( V_853 ) ;
F_2 ( V_854 , 0x15040d00 ) ;
F_2 ( V_855 , 0x007f0000 ) ;
F_2 ( V_856 , 0x1e220004 ) ;
F_2 ( V_857 , 0x04000004 ) ;
for ( V_54 = 0 ; V_54 < 5 ; V_54 ++ )
F_2 ( F_407 ( V_54 ) , 0 ) ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ )
F_2 ( F_408 ( V_54 ) , 0 ) ;
for ( V_54 = 0 ; V_54 < 16 ; V_54 ++ ) {
T_1 V_858 = F_3 ( F_288 ( V_54 ) ) ;
unsigned long V_639 = F_384 ( V_858 ) ;
unsigned long V_859 = ( V_858 & V_569 ) >>
V_570 ;
unsigned long V_21 ;
V_21 = V_859 * V_859 ;
V_21 *= ( V_639 / 1000 ) ;
V_21 *= 255 ;
V_21 /= ( 127 * 127 * 900 ) ;
if ( V_21 > 0xff )
F_19 ( L_96 , V_21 ) ;
V_852 [ V_54 ] = V_21 ;
}
V_852 [ 14 ] = 0 ;
V_852 [ 15 ] = 0 ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
T_1 V_21 = ( V_852 [ V_54 * 4 ] << 24 ) | ( V_852 [ ( V_54 * 4 ) + 1 ] << 16 ) |
( V_852 [ ( V_54 * 4 ) + 2 ] << 8 ) | ( V_852 [ ( V_54 * 4 ) + 3 ] ) ;
F_2 ( F_409 ( V_54 ) , V_21 ) ;
}
F_2 ( V_860 , 0 ) ;
F_2 ( V_861 , 0 ) ;
F_2 ( V_862 , 0x00007f00 ) ;
F_2 ( V_863 , 0x0000000e ) ;
F_2 ( V_864 , 0x000e0000 ) ;
F_2 ( V_865 , 0x68000300 ) ;
F_2 ( V_866 , 0x42000000 ) ;
F_2 ( V_867 , 0x00140031 ) ;
F_2 ( V_868 , 0 ) ;
F_2 ( V_869 , 0 ) ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ )
F_2 ( F_410 ( V_54 ) , 0 ) ;
F_2 ( V_853 , 0x80000019 ) ;
V_851 = F_3 ( V_870 ) ;
V_2 -> V_46 . V_841 = ( V_851 & V_871 ) ;
}
void F_411 ( struct V_1 * V_2 )
{
if ( ! V_872 . V_667 ) {
F_338 ( L_97 ) ;
F_412 ( V_2 ) ;
}
F_15 ( & V_2 -> V_529 . V_873 ) ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( F_24 ( V_2 ) )
F_378 ( V_2 ) ;
else if ( F_23 ( V_2 ) )
F_377 ( V_2 ) ;
else if ( F_130 ( V_2 ) >= 6 )
F_339 ( V_2 ) ;
V_2 -> V_57 . V_637 = V_2 -> V_57 . V_656 ;
V_2 -> V_57 . V_605 = V_2 -> V_57 . V_637 ;
V_2 -> V_57 . V_595 = V_2 -> V_57 . V_655 ;
V_2 -> V_57 . V_596 = V_2 -> V_57 . V_656 ;
if ( F_148 ( V_2 ) || F_149 ( V_2 ) )
V_2 -> V_57 . V_596 =
F_157 ( int ,
V_2 -> V_57 . V_604 ,
F_413 ( V_2 , 450 ) ) ;
if ( F_160 ( V_2 ) ||
F_154 ( V_2 ) || F_148 ( V_2 ) ) {
T_1 V_874 = 0 ;
F_147 ( V_2 , V_875 , & V_874 ) ;
if ( V_874 & F_75 ( 31 ) ) {
F_10 ( L_98 ,
( V_2 -> V_57 . V_655 & 0xff ) * 50 ,
( V_874 & 0xff ) * 50 ) ;
V_2 -> V_57 . V_655 = V_874 & 0xff ;
}
}
V_2 -> V_57 . V_647 = V_2 -> V_57 . V_655 ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
F_20 ( & V_2 -> V_529 . V_873 ) ;
F_414 ( V_2 ) ;
}
void F_415 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) )
F_380 ( V_2 ) ;
if ( ! V_872 . V_667 )
F_416 ( V_2 ) ;
}
void F_417 ( struct V_1 * V_2 )
{
if ( F_130 ( V_2 ) < 6 )
return;
if ( F_418 ( & V_2 -> V_57 . V_876 ) )
F_416 ( V_2 ) ;
}
void F_419 ( struct V_1 * V_2 )
{
V_2 -> V_57 . V_125 = true ;
F_420 ( V_2 ) ;
F_421 ( V_2 ) ;
}
void F_420 ( struct V_1 * V_2 )
{
if ( ! F_422 ( V_2 -> V_57 . V_125 ) )
return;
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( F_130 ( V_2 ) >= 9 ) {
F_326 ( V_2 ) ;
F_327 ( V_2 ) ;
} else if ( F_24 ( V_2 ) ) {
F_329 ( V_2 ) ;
} else if ( F_23 ( V_2 ) ) {
F_330 ( V_2 ) ;
} else if ( F_130 ( V_2 ) >= 6 ) {
F_328 ( V_2 ) ;
} else if ( F_423 ( V_2 ) ) {
F_294 ( V_2 ) ;
}
V_2 -> V_57 . V_125 = false ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
void F_424 ( struct V_1 * V_2 )
{
if ( F_422 ( V_2 -> V_57 . V_125 ) )
return;
if ( F_425 ( V_2 ) )
return;
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( F_24 ( V_2 ) ) {
F_381 ( V_2 ) ;
} else if ( F_23 ( V_2 ) ) {
F_383 ( V_2 ) ;
} else if ( F_130 ( V_2 ) >= 9 ) {
F_343 ( V_2 ) ;
F_342 ( V_2 ) ;
if ( F_184 ( V_2 ) )
F_354 ( V_2 ) ;
} else if ( F_149 ( V_2 ) ) {
F_349 ( V_2 ) ;
F_354 ( V_2 ) ;
} else if ( F_130 ( V_2 ) >= 6 ) {
F_350 ( V_2 ) ;
F_354 ( V_2 ) ;
} else if ( F_423 ( V_2 ) ) {
F_286 ( V_2 ) ;
F_406 ( V_2 ) ;
}
F_72 ( V_2 -> V_57 . V_655 < V_2 -> V_57 . V_656 ) ;
F_72 ( V_2 -> V_57 . V_637 > V_2 -> V_57 . V_655 ) ;
F_72 ( V_2 -> V_57 . V_604 < V_2 -> V_57 . V_656 ) ;
F_72 ( V_2 -> V_57 . V_604 > V_2 -> V_57 . V_655 ) ;
V_2 -> V_57 . V_125 = true ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
static void F_426 ( struct V_877 * V_653 )
{
struct V_1 * V_2 =
F_427 ( V_653 , F_428 ( * V_2 ) , V_57 . V_876 . V_653 ) ;
struct V_705 * V_878 ;
struct V_879 * V_880 ;
if ( F_422 ( V_2 -> V_57 . V_125 ) )
goto V_238;
V_878 = V_2 -> V_706 [ V_881 ] ;
if ( V_878 -> V_882 )
goto V_238;
if ( ! V_878 -> V_883 )
goto V_238;
F_15 ( & V_2 -> V_529 . V_873 ) ;
V_880 = F_429 ( V_878 , V_2 -> V_884 ) ;
if ( F_251 ( V_880 ) )
goto V_885;
if ( ! V_872 . V_886 && F_430 ( V_880 ) == 0 )
V_878 -> V_883 ( V_880 ) ;
F_431 ( V_880 ) ;
V_885:
F_20 ( & V_2 -> V_529 . V_873 ) ;
V_238:
F_416 ( V_2 ) ;
}
void F_414 ( struct V_1 * V_2 )
{
if ( F_422 ( V_2 -> V_57 . V_125 ) )
return;
if ( F_423 ( V_2 ) ) {
F_286 ( V_2 ) ;
F_406 ( V_2 ) ;
} else if ( F_92 ( V_2 ) -> V_692 >= 6 ) {
if ( F_432 ( V_2 -> V_887 ,
& V_2 -> V_57 . V_876 ,
F_433 ( V_888 ) ) )
F_434 ( V_2 ) ;
}
}
static void F_435 ( struct V_1 * V_2 )
{
F_2 ( V_889 , V_890 ) ;
}
static void F_436 ( struct V_1 * V_2 )
{
enum V_87 V_87 ;
F_63 (dev_priv, pipe) {
F_2 ( F_437 ( V_87 ) ,
F_3 ( F_437 ( V_87 ) ) |
V_891 ) ;
F_2 ( F_438 ( V_87 ) , F_3 ( F_438 ( V_87 ) ) ) ;
F_25 ( F_438 ( V_87 ) ) ;
}
}
static void F_439 ( struct V_1 * V_2 )
{
F_2 ( V_397 , F_3 ( V_397 ) & ~ V_379 ) ;
F_2 ( V_398 , F_3 ( V_398 ) & ~ V_379 ) ;
F_2 ( V_399 , F_3 ( V_399 ) & ~ V_379 ) ;
}
static void F_440 ( struct V_1 * V_2 )
{
T_3 V_892 = V_893 ;
V_892 |= V_894 |
V_895 |
V_896 ;
F_2 ( V_897 ,
V_898 |
V_899 ) ;
F_2 ( V_900 ,
V_901 ) ;
F_2 ( V_902 ,
( F_3 ( V_902 ) |
V_903 | V_904 ) ) ;
V_892 |= V_905 ;
F_2 ( V_9 ,
( F_3 ( V_9 ) |
V_10 ) ) ;
F_439 ( V_2 ) ;
if ( F_423 ( V_2 ) ) {
F_2 ( V_906 ,
F_3 ( V_906 ) |
V_907 ) ;
F_2 ( V_902 ,
F_3 ( V_902 ) |
V_903 ) ;
}
F_2 ( V_908 , V_892 ) ;
F_2 ( V_902 ,
F_3 ( V_902 ) |
V_909 ) ;
F_2 ( V_910 ,
V_911 << 16 |
V_911 ) ;
F_2 ( V_912 ,
F_31 ( V_913 ) ) ;
F_2 ( V_912 , F_32 ( V_914 ) ) ;
F_436 ( V_2 ) ;
F_435 ( V_2 ) ;
}
static void F_441 ( struct V_1 * V_2 )
{
int V_87 ;
T_3 V_21 ;
F_2 ( V_889 , V_890 |
V_915 |
V_916 ) ;
F_2 ( V_917 , F_3 ( V_917 ) |
V_918 ) ;
F_63 (dev_priv, pipe) {
V_21 = F_3 ( F_442 ( V_87 ) ) ;
V_21 |= V_919 ;
V_21 &= ~ V_920 ;
if ( V_2 -> V_921 . V_922 )
V_21 |= V_920 ;
V_21 &= ~ V_923 ;
V_21 &= ~ V_924 ;
V_21 &= ~ V_925 ;
F_2 ( F_442 ( V_87 ) , V_21 ) ;
}
F_63 (dev_priv, pipe) {
F_2 ( F_443 ( V_87 ) ,
V_926 ) ;
}
}
static void F_444 ( struct V_1 * V_2 )
{
T_3 V_26 ;
V_26 = F_3 ( V_336 ) ;
if ( ( V_26 & V_927 ) != V_928 )
F_13 ( L_99 ,
V_26 ) ;
}
static void F_445 ( struct V_1 * V_2 )
{
T_3 V_892 = V_893 ;
F_2 ( V_908 , V_892 ) ;
F_2 ( V_902 ,
F_3 ( V_902 ) |
V_909 ) ;
F_2 ( V_929 ,
F_31 ( V_930 ) ) ;
F_2 ( V_912 , F_32 ( V_914 ) ) ;
F_2 ( V_931 ,
F_446 ( V_932 , V_933 ) ) ;
F_439 ( V_2 ) ;
F_2 ( V_912 ,
F_32 ( V_934 ) ) ;
F_2 ( V_935 ,
F_3 ( V_935 ) |
V_936 |
V_937 ) ;
F_2 ( V_938 ,
V_939 |
V_940 ) ;
F_2 ( V_941 ,
F_31 ( V_942 ) ) ;
F_2 ( V_941 ,
F_31 ( V_943 ) ) ;
F_2 ( V_906 ,
F_3 ( V_906 ) |
V_907 | V_944 ) ;
F_2 ( V_902 ,
F_3 ( V_902 ) |
V_903 | V_904 ) ;
F_2 ( V_908 ,
F_3 ( V_908 ) |
V_905 |
V_896 ) ;
F_436 ( V_2 ) ;
F_441 ( V_2 ) ;
F_444 ( V_2 ) ;
}
static void F_447 ( struct V_1 * V_2 )
{
T_3 V_127 = F_3 ( V_945 ) ;
V_127 &= ~ V_946 ;
V_127 |= V_947 ;
V_127 |= V_948 ;
V_127 |= V_949 ;
F_2 ( V_945 , V_127 ) ;
}
static void F_448 ( struct V_1 * V_2 )
{
if ( F_449 ( V_2 ) )
F_2 ( V_889 ,
F_3 ( V_889 ) |
V_950 ) ;
F_2 ( F_443 ( V_93 ) ,
F_3 ( F_443 ( V_93 ) ) |
V_926 ) ;
}
static void F_450 ( struct V_1 * V_2 )
{
if ( F_449 ( V_2 ) ) {
T_3 V_21 = F_3 ( V_889 ) ;
V_21 &= ~ V_950 ;
F_2 ( V_889 , V_21 ) ;
}
}
static void F_451 ( struct V_1 * V_2 ,
int V_951 ,
int V_952 )
{
T_1 V_953 ;
V_953 = F_3 ( V_954 ) ;
F_2 ( V_954 , V_953 & ~ V_955 ) ;
F_2 ( V_956 ,
F_452 ( V_951 ) |
F_453 ( V_952 ) ) ;
F_25 ( V_956 ) ;
F_454 ( 1 ) ;
F_2 ( V_954 , V_953 ) ;
}
static void F_455 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
if ( F_456 ( V_2 , 0 , V_957 ) )
F_2 ( V_14 , F_3 ( V_14 ) |
V_15 ) ;
if ( F_456 ( V_2 , 0 , V_957 ) )
F_2 ( V_935 , F_3 ( V_935 ) |
V_958 ) ;
F_2 ( V_12 , F_3 ( V_12 ) |
V_959 ) ;
}
static void F_457 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_2 ( V_960 , F_3 ( V_960 ) |
V_961 ) ;
F_2 ( V_12 , F_3 ( V_12 ) |
V_959 ) ;
}
static void F_458 ( struct V_1 * V_2 )
{
enum V_87 V_87 ;
F_439 ( V_2 ) ;
F_2 ( V_962 , F_3 ( V_962 ) | V_963 ) ;
F_2 ( V_3 ,
F_3 ( V_3 ) | V_964 ) ;
F_63 (dev_priv, pipe) {
F_2 ( F_459 ( V_87 ) ,
F_3 ( F_459 ( V_87 ) ) |
V_965 ) ;
}
F_2 ( V_945 ,
F_3 ( V_945 ) &
~ ( V_966 | V_967 ) ) ;
F_2 ( V_968 ,
F_31 ( V_969 ) ) ;
F_2 ( V_14 , F_3 ( V_14 ) |
V_15 ) ;
F_451 ( V_2 , 30 , 2 ) ;
F_2 ( V_970 , V_971 ) ;
F_2 ( V_972 , F_3 ( V_972 )
| V_973 ) ;
F_448 ( V_2 ) ;
F_2 ( V_935 ,
F_3 ( V_935 ) | V_974 ) ;
}
static void F_460 ( struct V_1 * V_2 )
{
F_439 ( V_2 ) ;
F_2 ( V_975 , V_976 ) ;
F_2 ( V_977 ,
F_31 ( V_978 ) ) ;
F_2 ( V_979 ,
F_3 ( V_979 ) |
V_980 ) ;
F_2 ( V_945 ,
F_3 ( V_945 ) & ~ V_967 ) ;
F_2 ( V_981 , F_32 ( V_914 ) ) ;
F_2 ( V_981 ,
F_32 ( V_982 ) ) ;
F_2 ( V_983 ,
F_31 ( V_984 ) ) ;
F_2 ( V_985 ,
F_446 ( V_932 , V_933 ) ) ;
F_2 ( V_986 ,
F_31 ( V_987 ) ) ;
F_2 ( V_962 , F_3 ( V_962 ) | V_963 ) ;
F_2 ( V_3 ,
F_3 ( V_3 ) | V_988 ) ;
F_448 ( V_2 ) ;
}
static void F_461 ( struct V_1 * V_2 )
{
T_3 V_989 ;
F_439 ( V_2 ) ;
F_2 ( V_908 , V_893 ) ;
F_2 ( V_941 ,
F_31 ( V_990 ) ) ;
F_2 ( V_991 ,
V_992 |
V_993 ) ;
if ( F_462 ( V_2 ) )
F_2 ( V_994 ,
F_31 ( V_995 ) ) ;
F_2 ( V_981 , F_32 ( V_914 ) ) ;
F_2 ( V_996 ,
V_997 ) ;
F_2 ( V_998 ,
V_999 ) ;
F_2 ( V_1000 ,
V_1001 ) ;
if ( F_462 ( V_2 ) )
F_2 ( V_1002 ,
F_31 ( V_1003 ) ) ;
else {
F_2 ( V_1002 ,
F_31 ( V_1003 ) ) ;
F_2 ( V_1004 ,
F_31 ( V_1003 ) ) ;
}
F_2 ( V_1005 , F_3 ( V_1005 ) &
~ V_1006 ) ;
F_2 ( V_938 ,
V_1007 ) ;
F_2 ( V_979 ,
F_3 ( V_979 ) |
V_980 ) ;
F_436 ( V_2 ) ;
F_447 ( V_2 ) ;
if ( 0 ) {
F_2 ( V_981 ,
F_32 ( V_982 ) ) ;
}
F_2 ( V_983 ,
F_31 ( V_984 ) ) ;
F_2 ( V_985 ,
F_446 ( V_932 , V_933 ) ) ;
V_989 = F_3 ( V_1008 ) ;
V_989 &= ~ V_1009 ;
V_989 |= V_1010 ;
F_2 ( V_1008 , V_989 ) ;
if ( ! F_463 ( V_2 ) )
F_441 ( V_2 ) ;
F_444 ( V_2 ) ;
}
static void F_464 ( struct V_1 * V_2 )
{
F_2 ( V_941 ,
F_31 ( V_990 ) ) ;
F_2 ( V_991 ,
V_992 |
V_993 ) ;
F_2 ( V_994 ,
F_31 ( V_1011 |
V_995 ) ) ;
F_2 ( V_981 , F_32 ( V_914 ) ) ;
F_2 ( V_1005 , F_3 ( V_1005 ) &
~ V_1006 ) ;
F_2 ( V_1002 ,
F_31 ( V_1003 ) ) ;
F_2 ( V_979 ,
F_3 ( V_979 ) |
V_980 ) ;
F_447 ( V_2 ) ;
F_2 ( V_938 ,
V_1007 ) ;
F_2 ( V_1012 ,
F_3 ( V_1012 ) | V_1013 ) ;
F_2 ( V_983 ,
F_31 ( V_984 ) ) ;
F_2 ( V_985 ,
F_446 ( V_932 , V_933 ) ) ;
F_2 ( V_1014 , V_1015 ) ;
F_2 ( V_1016 , V_1017 ) ;
}
static void F_465 ( struct V_1 * V_2 )
{
F_2 ( V_945 ,
F_3 ( V_945 ) &
~ ( V_966 | V_967 ) ) ;
F_2 ( V_968 ,
F_31 ( V_969 ) ) ;
F_2 ( V_935 , F_3 ( V_935 ) |
V_937 ) ;
F_2 ( V_14 , F_3 ( V_14 ) |
V_15 ) ;
F_451 ( V_2 , 38 , 2 ) ;
F_2 ( V_970 , V_971 ) ;
}
static void F_466 ( struct V_1 * V_2 )
{
T_3 V_892 ;
F_2 ( V_1018 , 0 ) ;
F_2 ( V_1019 , V_1020 |
V_1021 |
V_1022 ) ;
F_2 ( V_1023 , 0 ) ;
V_892 = V_1024 |
V_1025 |
V_1026 ;
if ( F_467 ( V_2 ) )
V_892 |= V_1027 ;
F_2 ( V_1028 , V_892 ) ;
F_2 ( V_912 ,
F_31 ( V_913 ) ) ;
F_2 ( V_912 , F_32 ( V_914 ) ) ;
F_436 ( V_2 ) ;
}
static void F_468 ( struct V_1 * V_2 )
{
F_2 ( V_1018 , V_1029 ) ;
F_2 ( V_1019 , 0 ) ;
F_2 ( V_1028 , 0 ) ;
F_2 ( V_1023 , 0 ) ;
F_284 ( V_1030 , 0 ) ;
F_2 ( V_1031 ,
F_31 ( V_1032 ) ) ;
F_2 ( V_912 , F_32 ( V_914 ) ) ;
}
static void F_469 ( struct V_1 * V_2 )
{
F_2 ( V_1018 , V_1033 |
V_1029 |
V_1034 |
V_1035 |
V_1036 ) ;
F_2 ( V_1019 , 0 ) ;
F_2 ( V_1031 ,
F_31 ( V_1032 ) ) ;
F_2 ( V_912 , F_32 ( V_914 ) ) ;
}
static void F_470 ( struct V_1 * V_2 )
{
T_1 V_1037 = F_3 ( V_1038 ) ;
V_1037 |= V_1039 | V_1040 |
V_1041 ;
F_2 ( V_1038 , V_1037 ) ;
if ( F_28 ( V_2 ) )
F_2 ( V_1042 , F_31 ( V_1043 ) ) ;
F_2 ( V_1042 , F_32 ( V_1044 ) ) ;
F_2 ( V_72 , F_31 ( V_1045 ) ) ;
F_2 ( V_1031 , F_31 ( V_1046 ) ) ;
F_2 ( V_1031 ,
F_31 ( V_1032 ) ) ;
}
static void F_471 ( struct V_1 * V_2 )
{
F_2 ( V_1018 , V_1047 ) ;
F_2 ( V_1048 , F_31 ( V_1049 ) |
F_32 ( V_1050 ) ) ;
F_2 ( V_1051 ,
F_31 ( V_1052 ) ) ;
}
static void F_472 ( struct V_1 * V_2 )
{
F_2 ( V_1051 ,
F_31 ( V_1053 ) |
F_31 ( V_1054 ) ) ;
}
void F_473 ( struct V_1 * V_2 )
{
V_2 -> V_153 . V_1055 ( V_2 ) ;
}
void F_474 ( struct V_1 * V_2 )
{
if ( F_475 ( V_2 ) )
F_450 ( V_2 ) ;
}
static void F_476 ( struct V_1 * V_2 )
{
F_13 ( L_100 ) ;
}
void F_477 ( struct V_1 * V_2 )
{
if ( F_188 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_457 ;
else if ( F_187 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_455 ;
else if ( F_185 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_4 ;
else if ( F_478 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_5 ;
else if ( F_149 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_458 ;
else if ( F_24 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_465 ;
else if ( F_148 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_460 ;
else if ( F_154 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_461 ;
else if ( F_23 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_464 ;
else if ( F_160 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_445 ;
else if ( F_152 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_440 ;
else if ( F_26 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_466 ;
else if ( F_27 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_468 ;
else if ( F_479 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_469 ;
else if ( F_480 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_470 ;
else if ( F_481 ( V_2 ) || F_482 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_471 ;
else if ( F_114 ( V_2 ) )
V_2 -> V_153 . V_1055 = F_472 ;
else {
F_41 ( F_483 ( V_2 ) ) ;
V_2 -> V_153 . V_1055 = F_476 ;
}
}
void F_484 ( struct V_1 * V_2 )
{
F_485 ( V_2 ) ;
if ( F_28 ( V_2 ) )
F_7 ( V_2 ) ;
else if ( F_152 ( V_2 ) )
F_8 ( V_2 ) ;
if ( F_130 ( V_2 ) >= 9 ) {
F_161 ( V_2 ) ;
V_2 -> V_153 . V_1056 = F_262 ;
V_2 -> V_153 . V_1057 = F_261 ;
V_2 -> V_153 . V_1058 = F_260 ;
} else if ( F_486 ( V_2 ) ) {
F_159 ( V_2 ) ;
if ( ( F_152 ( V_2 ) && V_2 -> V_75 . V_212 [ 1 ] &&
V_2 -> V_75 . V_322 [ 1 ] && V_2 -> V_75 . V_323 [ 1 ] ) ||
( ! F_152 ( V_2 ) && V_2 -> V_75 . V_212 [ 0 ] &&
V_2 -> V_75 . V_322 [ 0 ] && V_2 -> V_75 . V_323 [ 0 ] ) ) {
V_2 -> V_153 . V_1059 = F_163 ;
V_2 -> V_153 . V_1060 =
F_167 ;
V_2 -> V_153 . V_1056 =
F_265 ;
V_2 -> V_153 . V_1061 =
F_266 ;
} else {
F_13 ( L_101
L_102 ) ;
}
} else if ( F_23 ( V_2 ) || F_24 ( V_2 ) ) {
F_70 ( V_2 ) ;
V_2 -> V_153 . V_1059 = F_86 ;
V_2 -> V_153 . V_1060 = F_102 ;
V_2 -> V_153 . V_1056 = F_107 ;
V_2 -> V_153 . V_1061 = F_108 ;
V_2 -> V_153 . V_1057 = F_94 ;
} else if ( F_28 ( V_2 ) ) {
if ( ! F_11 ( F_54 ( V_2 ) ,
V_2 -> V_40 ,
V_2 -> V_30 ,
V_2 -> V_36 ) ) {
F_338 ( L_103
L_104
L_105 ,
( V_2 -> V_40 == 1 ) ? L_106 : L_107 ,
V_2 -> V_30 , V_2 -> V_36 ) ;
F_36 ( V_2 , false ) ;
V_2 -> V_153 . V_540 = NULL ;
} else
V_2 -> V_153 . V_540 = F_53 ;
} else if ( F_26 ( V_2 ) ) {
V_2 -> V_153 . V_540 = F_109 ;
} else if ( F_487 ( V_2 ) ) {
V_2 -> V_153 . V_540 = F_112 ;
} else if ( F_480 ( V_2 ) ) {
V_2 -> V_153 . V_540 = F_113 ;
V_2 -> V_153 . V_286 = F_43 ;
} else if ( F_114 ( V_2 ) ) {
if ( F_92 ( V_2 ) -> V_248 == 1 ) {
V_2 -> V_153 . V_540 = F_118 ;
V_2 -> V_153 . V_286 = F_45 ;
} else {
V_2 -> V_153 . V_540 = F_113 ;
V_2 -> V_153 . V_286 = F_44 ;
}
} else {
F_19 ( L_108 ) ;
}
}
static inline int F_488 ( struct V_1 * V_2 )
{
T_3 V_420 =
F_97 ( V_1062 ) & V_1063 ;
switch ( V_420 ) {
case V_1064 :
return 0 ;
case V_1065 :
case V_1066 :
return - V_415 ;
case V_1067 :
case V_1068 :
return - V_1069 ;
case V_1070 :
return - V_1071 ;
default:
F_41 ( V_420 ) ;
return 0 ;
}
}
static inline int F_489 ( struct V_1 * V_2 )
{
T_3 V_420 =
F_97 ( V_1062 ) & V_1063 ;
switch ( V_420 ) {
case V_1064 :
return 0 ;
case V_1066 :
return - V_415 ;
case V_1072 :
return - V_1071 ;
case V_1073 :
return - V_230 ;
case V_1068 :
return - V_1069 ;
default:
F_41 ( V_420 ) ;
return 0 ;
}
}
int F_147 ( struct V_1 * V_2 , T_1 V_1074 , T_1 * V_21 )
{
int V_1075 ;
F_72 ( ! F_351 ( & V_2 -> V_57 . V_58 ) ) ;
if ( F_97 ( V_1062 ) & V_1076 ) {
F_10 ( L_109 ) ;
return - V_1077 ;
}
F_99 ( V_1078 , * V_21 ) ;
F_99 ( V_1079 , 0 ) ;
F_99 ( V_1062 , V_1076 | V_1074 ) ;
if ( F_490 ( V_2 ,
V_1062 , V_1076 , 0 ,
500 ) ) {
F_19 ( L_110 , V_1074 ) ;
return - V_1071 ;
}
* V_21 = F_97 ( V_1078 ) ;
F_99 ( V_1078 , 0 ) ;
if ( F_130 ( V_2 ) > 6 )
V_1075 = F_489 ( V_2 ) ;
else
V_1075 = F_488 ( V_2 ) ;
if ( V_1075 ) {
F_10 ( L_111 ,
V_1075 ) ;
return V_1075 ;
}
return 0 ;
}
int F_190 ( struct V_1 * V_2 ,
T_1 V_1074 , T_1 V_21 )
{
int V_1075 ;
F_72 ( ! F_351 ( & V_2 -> V_57 . V_58 ) ) ;
if ( F_97 ( V_1062 ) & V_1076 ) {
F_10 ( L_112 ) ;
return - V_1077 ;
}
F_99 ( V_1078 , V_21 ) ;
F_99 ( V_1079 , 0 ) ;
F_99 ( V_1062 , V_1076 | V_1074 ) ;
if ( F_490 ( V_2 ,
V_1062 , V_1076 , 0 ,
500 ) ) {
F_19 ( L_113 , V_1074 ) ;
return - V_1071 ;
}
F_99 ( V_1078 , 0 ) ;
if ( F_130 ( V_2 ) > 6 )
V_1075 = F_489 ( V_2 ) ;
else
V_1075 = F_488 ( V_2 ) ;
if ( V_1075 ) {
F_10 ( L_114 ,
V_1075 ) ;
return V_1075 ;
}
return 0 ;
}
static bool F_491 ( struct V_1 * V_2 , T_1 V_1074 ,
T_1 V_1080 , T_1 V_1081 , T_1 V_1082 ,
T_1 * V_1075 )
{
T_1 V_21 = V_1080 ;
* V_1075 = F_147 ( V_2 , V_1074 , & V_21 ) ;
return * V_1075 || ( ( V_21 & V_1081 ) == V_1082 ) ;
}
int F_192 ( struct V_1 * V_2 , T_1 V_1074 , T_1 V_1080 ,
T_1 V_1081 , T_1 V_1082 , int V_1083 )
{
T_1 V_1075 ;
int V_74 ;
F_72 ( ! F_351 ( & V_2 -> V_57 . V_58 ) ) ;
#define F_492 skl_pcode_try_request(dev_priv, mbox, request, reply_mask, reply, \
&status)
if ( F_492 ) {
V_74 = 0 ;
goto V_238;
}
V_74 = F_493 ( F_492 , V_1083 * 1000 , 10 ) ;
if ( ! V_74 )
goto V_238;
F_13 ( L_115 ) ;
F_494 ( V_1083 > 3 ) ;
F_495 () ;
V_74 = F_289 ( F_492 , 50 ) ;
F_496 () ;
V_238:
return V_74 ? V_74 : V_1075 ;
#undef F_492
}
static int F_497 ( struct V_1 * V_2 , int V_21 )
{
return F_141 ( V_2 -> V_57 . V_790 * ( V_21 - 0xb7 ) , 1000 ) ;
}
static int F_498 ( struct V_1 * V_2 , int V_21 )
{
return F_141 ( 1000 * V_21 , V_2 -> V_57 . V_790 ) + 0xb7 ;
}
static int F_499 ( struct V_1 * V_2 , int V_21 )
{
return F_141 ( V_2 -> V_57 . V_790 * V_21 , 2 * 2 * 1000 ) ;
}
static int F_500 ( struct V_1 * V_2 , int V_21 )
{
return F_141 ( 2 * 1000 * V_21 , V_2 -> V_57 . V_790 ) * 2 ;
}
int F_306 ( struct V_1 * V_2 , int V_21 )
{
if ( F_145 ( V_2 ) )
return F_141 ( V_21 * V_1084 ,
V_701 ) ;
else if ( F_24 ( V_2 ) )
return F_499 ( V_2 , V_21 ) ;
else if ( F_23 ( V_2 ) )
return F_497 ( V_2 , V_21 ) ;
else
return V_21 * V_1084 ;
}
int F_413 ( struct V_1 * V_2 , int V_21 )
{
if ( F_145 ( V_2 ) )
return F_141 ( V_21 * V_701 ,
V_1084 ) ;
else if ( F_24 ( V_2 ) )
return F_500 ( V_2 , V_21 ) ;
else if ( F_23 ( V_2 ) )
return F_498 ( V_2 , V_21 ) ;
else
return F_141 ( V_21 , V_1084 ) ;
}
static void F_501 ( struct V_877 * V_653 )
{
struct V_1085 * V_1086 = F_427 ( V_653 , struct V_1085 , V_653 ) ;
struct V_879 * V_880 = V_1086 -> V_880 ;
if ( ! F_502 ( V_880 ) )
F_321 ( V_880 -> V_872 , NULL , V_880 -> V_1087 ) ;
F_503 ( V_880 ) ;
F_504 ( V_1086 ) ;
}
void F_505 ( struct V_879 * V_880 )
{
struct V_1085 * V_1086 ;
if ( V_880 == NULL || F_130 ( V_880 -> V_872 ) < 6 )
return;
if ( F_502 ( V_880 ) )
return;
V_1086 = F_506 ( sizeof( * V_1086 ) , V_1088 ) ;
if ( V_1086 == NULL )
return;
V_1086 -> V_880 = F_507 ( V_880 ) ;
F_508 ( & V_1086 -> V_653 , F_501 ) ;
F_509 ( V_880 -> V_872 -> V_887 , & V_1086 -> V_653 ) ;
}
void F_510 ( struct V_1 * V_2 )
{
F_511 ( & V_2 -> V_57 . V_58 ) ;
F_512 ( & V_2 -> V_57 . V_640 ) ;
F_513 ( & V_2 -> V_57 . V_876 ,
F_426 ) ;
F_514 ( & V_2 -> V_57 . V_641 ) ;
V_2 -> V_1089 . V_1090 = false ;
F_515 ( & V_2 -> V_1089 . V_1091 , 0 ) ;
}
static T_10 F_516 ( struct V_1 * V_2 ,
const T_8 V_127 )
{
T_1 V_1092 , V_1093 , V_26 ;
int V_1094 = 2 ;
F_287 ( & V_2 -> V_249 . V_250 ) ;
F_99 ( V_798 ,
F_31 ( V_799 ) ) ;
V_1093 = F_97 ( V_127 ) ;
do {
V_26 = V_1093 ;
F_99 ( V_798 ,
F_32 ( V_799 ) ) ;
V_1092 = F_97 ( V_127 ) ;
F_99 ( V_798 ,
F_31 ( V_799 ) ) ;
V_1093 = F_97 ( V_127 ) ;
} while ( V_1093 != V_26 && -- V_1094 );
F_293 ( & V_2 -> V_249 . V_250 ) ;
return V_1092 | ( T_10 ) V_1093 << 8 ;
}
T_10 F_517 ( struct V_1 * V_2 ,
const T_8 V_127 )
{
T_10 V_1095 , V_1096 , div ;
if ( ! F_347 () )
return 0 ;
F_412 ( V_2 ) ;
if ( F_23 ( V_2 ) || F_24 ( V_2 ) ) {
V_1096 = 1000 ;
div = V_2 -> V_792 ;
V_1095 = F_516 ( V_2 , V_127 ) ;
} else if ( F_337 ( V_2 ) ) {
V_1096 = 1000 ;
div = 1200 ;
V_1095 = F_3 ( V_127 ) ;
} else {
V_1096 = 128000 ;
div = 100000 ;
V_1095 = F_3 ( V_127 ) ;
}
F_416 ( V_2 ) ;
return F_121 ( V_1095 * V_1096 , div ) ;
}
