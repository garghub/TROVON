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
if ( F_23 ( V_2 ) || F_24 ( V_2 ) )
V_2 -> V_75 . V_77 . V_78 = V_56 ;
else if ( F_26 ( V_2 ) )
V_2 -> V_75 . V_79 . V_78 = V_56 ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
return V_74 ;
}
static void F_37 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_38 ( V_81 -> V_84 . V_83 ) ;
struct V_1 * V_2 = F_39 ( V_83 -> V_84 . V_85 ) ;
struct V_86 * V_87 = & V_81 -> V_75 . V_77 . V_87 ;
enum V_88 V_88 = V_83 -> V_88 ;
int V_89 , V_90 ;
switch ( V_88 ) {
T_3 V_91 , V_92 , V_93 ;
case V_94 :
V_91 = F_3 ( V_95 ) ;
V_92 = F_3 ( V_96 ) ;
V_89 = F_40 ( V_91 , V_92 , 0 , 0 ) ;
V_90 = F_40 ( V_91 , V_92 , 8 , 4 ) ;
break;
case V_97 :
V_91 = F_3 ( V_95 ) ;
V_92 = F_3 ( V_96 ) ;
V_89 = F_40 ( V_91 , V_92 , 16 , 8 ) ;
V_90 = F_40 ( V_91 , V_92 , 24 , 12 ) ;
break;
case V_98 :
V_92 = F_3 ( V_96 ) ;
V_93 = F_3 ( V_99 ) ;
V_89 = F_40 ( V_93 , V_92 , 0 , 16 ) ;
V_90 = F_40 ( V_93 , V_92 , 8 , 20 ) ;
break;
default:
F_41 ( V_88 ) ;
return;
}
V_87 -> V_100 [ V_101 ] = V_89 ;
V_87 -> V_100 [ V_102 ] = V_90 - V_89 ;
V_87 -> V_100 [ V_103 ] = 511 - V_90 ;
V_87 -> V_100 [ V_104 ] = 63 ;
}
static int F_42 ( struct V_1 * V_2 , int V_100 )
{
T_3 V_91 = F_3 ( V_95 ) ;
int V_105 ;
V_105 = V_91 & 0x7f ;
if ( V_100 )
V_105 = ( ( V_91 >> V_106 ) & 0x7f ) - V_105 ;
F_13 ( L_6 , V_91 ,
V_100 ? L_7 : L_8 , V_105 ) ;
return V_105 ;
}
static int F_43 ( struct V_1 * V_2 , int V_100 )
{
T_3 V_91 = F_3 ( V_95 ) ;
int V_105 ;
V_105 = V_91 & 0x1ff ;
if ( V_100 )
V_105 = ( ( V_91 >> V_107 ) & 0x1ff ) - V_105 ;
V_105 >>= 1 ;
F_13 ( L_6 , V_91 ,
V_100 ? L_7 : L_8 , V_105 ) ;
return V_105 ;
}
static int F_44 ( struct V_1 * V_2 , int V_100 )
{
T_3 V_91 = F_3 ( V_95 ) ;
int V_105 ;
V_105 = V_91 & 0x7f ;
V_105 >>= 2 ;
F_13 ( L_6 , V_91 ,
V_100 ? L_7 : L_8 ,
V_105 ) ;
return V_105 ;
}
static unsigned int F_45 ( unsigned int V_108 ,
unsigned int V_109 ,
unsigned int V_53 )
{
T_4 V_74 ;
V_74 = ( T_4 ) V_108 * V_109 * V_53 ;
V_74 = F_46 ( V_74 , 10000 ) ;
return V_74 ;
}
static unsigned int F_47 ( unsigned int V_108 ,
unsigned int V_110 ,
unsigned int V_111 ,
unsigned int V_109 ,
unsigned int V_53 )
{
unsigned int V_74 ;
if ( F_48 ( V_110 == 0 ) )
V_110 = 1 ;
V_74 = ( V_53 * V_108 ) / ( V_110 * 10000 ) ;
V_74 = ( V_74 + 1 ) * V_111 * V_109 ;
return V_74 ;
}
static unsigned int F_49 ( int V_108 ,
const struct V_112 * V_75 ,
int V_113 , int V_109 ,
unsigned int V_114 )
{
int V_115 , V_116 ;
V_115 = F_45 ( V_108 , V_109 ,
V_114 / 100 ) ;
V_115 = F_50 ( V_115 , V_75 -> V_117 ) +
V_75 -> V_118 ;
F_13 ( L_9 , V_115 ) ;
V_116 = V_113 - V_115 ;
F_13 ( L_10 , V_116 ) ;
if ( V_116 > V_75 -> V_119 )
V_116 = V_75 -> V_119 ;
if ( V_116 <= 0 )
V_116 = V_75 -> V_120 ;
if ( V_116 <= 8 )
V_116 = 8 ;
return V_116 ;
}
static bool F_51 ( int V_121 , int V_122 , int V_123 )
{
return V_121 >= V_123 && V_122 < V_123 ;
}
static bool F_52 ( int V_121 , int V_122 , int V_123 )
{
return V_121 < V_123 && V_122 >= V_123 ;
}
static int F_53 ( struct V_1 * V_2 )
{
return V_2 -> V_75 . V_124 + 1 ;
}
static bool F_54 ( const struct V_80 * V_81 ,
const struct V_125 * V_126 )
{
struct V_127 * V_100 = F_55 ( V_126 -> V_84 . V_100 ) ;
if ( ! V_81 -> V_84 . V_128 )
return false ;
if ( V_100 -> V_129 == V_104 )
return V_126 -> V_84 . V_130 != NULL ;
else
return V_126 -> V_84 . V_131 ;
}
static struct V_82 * F_56 ( struct V_1 * V_2 )
{
struct V_82 * V_83 , * V_132 = NULL ;
F_57 (&dev_priv->drm, crtc) {
if ( F_58 ( V_83 ) ) {
if ( V_132 )
return NULL ;
V_132 = V_83 ;
}
}
return V_132 ;
}
static void F_59 ( struct V_82 * V_133 )
{
struct V_1 * V_2 = F_39 ( V_133 -> V_84 . V_85 ) ;
struct V_82 * V_83 ;
const struct V_49 * V_53 ;
T_1 V_134 ;
unsigned int V_75 ;
V_53 = F_11 ( F_60 ( V_2 ) ,
V_2 -> V_40 ,
V_2 -> V_30 ,
V_2 -> V_36 ) ;
if ( ! V_53 ) {
F_13 ( L_3 ) ;
F_36 ( V_2 , false ) ;
return;
}
V_83 = F_56 ( V_2 ) ;
if ( V_83 ) {
const struct V_135 * V_136 =
& V_83 -> V_137 -> V_84 . V_136 ;
const struct V_138 * V_130 =
V_83 -> V_84 . V_139 -> V_140 -> V_130 ;
int V_109 = V_130 -> V_141 -> V_109 [ 0 ] ;
int clock = V_136 -> V_142 ;
V_75 = F_49 ( clock , & V_143 ,
V_143 . V_113 ,
V_109 , V_53 -> V_144 ) ;
V_134 = F_3 ( V_145 ) ;
V_134 &= ~ V_146 ;
V_134 |= F_61 ( V_75 , V_147 ) ;
F_2 ( V_145 , V_134 ) ;
F_13 ( L_11 , V_134 ) ;
V_75 = F_49 ( clock , & V_148 ,
V_143 . V_113 ,
4 , V_53 -> V_149 ) ;
V_134 = F_3 ( V_70 ) ;
V_134 &= ~ V_150 ;
V_134 |= F_61 ( V_75 , V_151 ) ;
F_2 ( V_70 , V_134 ) ;
V_75 = F_49 ( clock , & V_152 ,
V_152 . V_113 ,
V_109 , V_53 -> V_153 ) ;
V_134 = F_3 ( V_70 ) ;
V_134 &= ~ V_154 ;
V_134 |= F_61 ( V_75 , V_155 ) ;
F_2 ( V_70 , V_134 ) ;
V_75 = F_49 ( clock , & V_156 ,
V_152 . V_113 ,
4 , V_53 -> V_157 ) ;
V_134 = F_3 ( V_70 ) ;
V_134 &= ~ V_158 ;
V_134 |= F_61 ( V_75 , V_159 ) ;
F_2 ( V_70 , V_134 ) ;
F_13 ( L_12 , V_134 ) ;
F_36 ( V_2 , true ) ;
} else {
F_36 ( V_2 , false ) ;
}
}
static int F_62 ( int V_113 , int V_111 , int V_109 )
{
int V_160 = V_113 * 64 - V_111 * V_109 * 8 ;
return F_63 ( 0 , V_160 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
const struct V_161 * V_75 )
{
enum V_88 V_88 ;
F_65 (dev_priv, pipe)
F_66 ( F_67 ( V_2 , V_88 ) , V_75 ) ;
F_2 ( V_145 ,
F_61 ( V_75 -> V_162 . V_100 , V_147 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_104 ] , V_163 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_101 ] , V_164 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_101 ] , V_165 ) ) ;
F_2 ( V_166 ,
( V_75 -> V_167 ? V_168 : 0 ) |
F_61 ( V_75 -> V_162 . V_169 , V_170 ) |
F_61 ( V_75 -> V_171 . V_169 , V_172 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] , V_173 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_104 ] , V_174 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_102 ] , V_175 ) ) ;
F_2 ( V_70 ,
( V_75 -> V_176 ? V_177 : 0 ) |
F_61 ( V_75 -> V_162 . V_178 , V_151 ) |
F_61 ( V_75 -> V_171 . V_178 , V_159 ) |
F_61 ( V_75 -> V_171 . V_100 , V_155 ) ) ;
F_25 ( V_145 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
const struct V_179 * V_75 )
{
enum V_88 V_88 ;
F_65 (dev_priv, pipe) {
F_69 ( F_67 ( V_2 , V_88 ) , V_75 ) ;
F_2 ( F_70 ( V_88 ) ,
( V_75 -> V_180 [ V_88 ] . V_100 [ V_104 ] << V_181 ) |
( V_75 -> V_180 [ V_88 ] . V_100 [ V_103 ] << F_71 ( 1 ) ) |
( V_75 -> V_180 [ V_88 ] . V_100 [ V_102 ] << F_71 ( 0 ) ) |
( V_75 -> V_180 [ V_88 ] . V_100 [ V_101 ] << V_182 ) ) ;
}
F_2 ( V_183 , 0 ) ;
F_2 ( V_184 , 0 ) ;
F_2 ( V_185 , 0 ) ;
F_2 ( V_186 , 0 ) ;
F_2 ( V_187 , 0 ) ;
F_2 ( V_145 ,
F_61 ( V_75 -> V_162 . V_100 , V_147 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_104 ] , V_163 ) |
F_72 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_101 ] , V_164 ) |
F_72 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_101 ] , V_165 ) ) ;
F_2 ( V_166 ,
F_72 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_103 ] , V_173 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_104 ] , V_174 ) |
F_72 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_102 ] , V_175 ) ) ;
F_2 ( V_70 ,
F_61 ( V_75 -> V_162 . V_178 , V_151 ) ) ;
if ( F_24 ( V_2 ) ) {
F_2 ( V_188 ,
F_72 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_103 ] , V_189 ) |
F_72 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] , V_190 ) ) ;
F_2 ( V_191 ,
F_72 ( V_75 -> V_88 [ V_98 ] . V_100 [ V_103 ] , V_192 ) |
F_72 ( V_75 -> V_88 [ V_98 ] . V_100 [ V_102 ] , V_193 ) ) ;
F_2 ( V_194 ,
F_72 ( V_75 -> V_88 [ V_98 ] . V_100 [ V_101 ] , V_195 ) |
F_61 ( V_75 -> V_88 [ V_98 ] . V_100 [ V_104 ] , V_196 ) ) ;
F_2 ( V_183 ,
F_61 ( V_75 -> V_162 . V_100 >> 9 , V_197 ) |
F_61 ( V_75 -> V_88 [ V_98 ] . V_100 [ V_103 ] >> 8 , V_198 ) |
F_61 ( V_75 -> V_88 [ V_98 ] . V_100 [ V_102 ] >> 8 , V_199 ) |
F_61 ( V_75 -> V_88 [ V_98 ] . V_100 [ V_101 ] >> 8 , V_200 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_103 ] >> 8 , V_201 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] >> 8 , V_202 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_101 ] >> 8 , V_203 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_103 ] >> 8 , V_204 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_102 ] >> 8 , V_205 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_101 ] >> 8 , V_206 ) ) ;
} else {
F_2 ( V_207 ,
F_72 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_103 ] , V_189 ) |
F_72 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] , V_190 ) ) ;
F_2 ( V_183 ,
F_61 ( V_75 -> V_162 . V_100 >> 9 , V_197 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_103 ] >> 8 , V_201 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] >> 8 , V_202 ) |
F_61 ( V_75 -> V_88 [ V_97 ] . V_100 [ V_101 ] >> 8 , V_203 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_103 ] >> 8 , V_204 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_102 ] >> 8 , V_205 ) |
F_61 ( V_75 -> V_88 [ V_94 ] . V_100 [ V_101 ] >> 8 , V_206 ) ) ;
}
F_25 ( V_145 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
V_2 -> V_75 . V_208 [ V_209 ] = 5 ;
V_2 -> V_75 . V_208 [ V_210 ] = 12 ;
V_2 -> V_75 . V_208 [ V_211 ] = 35 ;
V_2 -> V_75 . V_124 = V_211 ;
}
static int F_74 ( enum V_212 V_212 , int V_213 )
{
switch ( V_212 ) {
case V_104 :
return 63 ;
case V_101 :
return V_213 == V_209 ? 127 : 511 ;
case V_102 :
return V_213 == V_209 ? 127 : 0 ;
default:
F_41 ( V_212 ) ;
return 0 ;
}
}
static int F_75 ( int V_213 )
{
switch ( V_213 ) {
case V_210 :
return 7 ;
case V_211 :
return 15 ;
default:
F_41 ( V_213 ) ;
return 0 ;
}
}
static T_5 F_76 ( const struct V_80 * V_81 ,
const struct V_125 * V_126 ,
int V_213 )
{
struct V_127 * V_100 = F_55 ( V_126 -> V_84 . V_100 ) ;
struct V_1 * V_2 = F_39 ( V_100 -> V_84 . V_85 ) ;
const struct V_135 * V_136 =
& V_81 -> V_84 . V_136 ;
int clock , V_110 , V_109 , V_111 , V_75 ;
int V_53 = V_2 -> V_75 . V_208 [ V_213 ] * 10 ;
if ( V_53 == 0 )
return V_214 ;
if ( ! F_54 ( V_81 , V_126 ) )
return 0 ;
if ( F_77 ( V_2 ) && V_100 -> V_129 == V_101 &&
V_213 != V_209 )
V_109 = 4 ;
else
V_109 = V_126 -> V_84 . V_130 -> V_141 -> V_109 [ 0 ] ;
clock = V_136 -> V_142 ;
V_110 = V_136 -> V_215 ;
if ( V_100 -> V_129 == V_104 )
V_111 = V_126 -> V_84 . V_216 ;
else
V_111 = F_78 ( & V_126 -> V_84 . V_217 ) ;
if ( V_100 -> V_129 == V_104 ) {
V_75 = F_47 ( clock , V_110 , V_111 , V_109 , V_53 ) ;
} else if ( V_100 -> V_129 == V_101 &&
V_213 == V_209 ) {
V_75 = F_45 ( clock , V_109 , V_53 ) ;
} else {
int V_218 , V_219 ;
V_218 = F_45 ( clock , V_109 , V_53 ) ;
V_219 = F_47 ( clock , V_110 , V_111 , V_109 , V_53 ) ;
V_75 = F_79 ( V_218 , V_219 ) ;
}
V_75 += F_62 ( F_74 ( V_100 -> V_129 , V_213 ) ,
V_111 , V_109 ) ;
V_75 = F_50 ( V_75 , 64 ) + 2 ;
return F_80 ( int , V_75 , V_214 ) ;
}
static bool F_81 ( struct V_80 * V_81 ,
int V_213 , enum V_212 V_212 , T_2 V_220 )
{
struct V_1 * V_2 = F_39 ( V_81 -> V_84 . V_83 -> V_85 ) ;
bool V_221 = false ;
for (; V_213 < F_53 ( V_2 ) ; V_213 ++ ) {
struct V_222 * V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
V_221 |= V_223 -> V_100 [ V_212 ] != V_220 ;
V_223 -> V_100 [ V_212 ] = V_220 ;
}
return V_221 ;
}
static bool F_82 ( struct V_80 * V_81 ,
int V_213 , T_2 V_220 )
{
struct V_1 * V_2 = F_39 ( V_81 -> V_84 . V_83 -> V_85 ) ;
bool V_221 = false ;
V_213 = F_63 ( V_213 , V_210 ) ;
for (; V_213 < F_53 ( V_2 ) ; V_213 ++ ) {
struct V_222 * V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
V_221 |= V_223 -> V_169 != V_220 ;
V_223 -> V_169 = V_220 ;
}
return V_221 ;
}
static bool F_83 ( struct V_80 * V_81 ,
const struct V_125 * V_126 )
{
struct V_127 * V_100 = F_55 ( V_126 -> V_84 . V_100 ) ;
int V_224 = F_53 ( F_39 ( V_100 -> V_84 . V_85 ) ) ;
enum V_212 V_212 = V_100 -> V_129 ;
bool V_221 = false ;
int V_213 ;
if ( ! F_54 ( V_81 , V_126 ) ) {
V_221 |= F_81 ( V_81 , 0 , V_212 , 0 ) ;
if ( V_212 == V_101 )
V_221 |= F_82 ( V_81 , 0 , 0 ) ;
goto V_225;
}
for ( V_213 = 0 ; V_213 < V_224 ; V_213 ++ ) {
struct V_222 * V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
int V_75 , V_119 ;
V_75 = F_76 ( V_81 , V_126 , V_213 ) ;
V_119 = F_74 ( V_212 , V_213 ) ;
if ( V_75 > V_119 )
break;
V_221 |= V_223 -> V_100 [ V_212 ] != V_75 ;
V_223 -> V_100 [ V_212 ] = V_75 ;
if ( V_212 != V_101 ||
V_213 == V_209 )
continue;
V_75 = F_84 ( V_81 , V_126 ,
V_223 -> V_100 [ V_212 ] ) ;
V_119 = F_75 ( V_213 ) ;
if ( V_75 > V_119 )
V_75 = V_214 ;
V_221 |= V_223 -> V_169 != V_75 ;
V_223 -> V_169 = V_75 ;
}
V_221 |= F_81 ( V_81 , V_213 , V_212 , V_214 ) ;
if ( V_212 == V_101 )
V_221 |= F_82 ( V_81 , V_213 , V_214 ) ;
V_225:
if ( V_221 ) {
F_13 ( L_13 ,
V_100 -> V_84 . V_226 ,
V_81 -> V_75 . V_79 . V_223 [ V_209 ] . V_100 [ V_212 ] ,
V_81 -> V_75 . V_79 . V_223 [ V_210 ] . V_100 [ V_212 ] ,
V_81 -> V_75 . V_79 . V_223 [ V_211 ] . V_100 [ V_212 ] ) ;
if ( V_212 == V_101 )
F_13 ( L_14 ,
V_81 -> V_75 . V_79 . V_223 [ V_210 ] . V_169 ,
V_81 -> V_75 . V_79 . V_223 [ V_211 ] . V_169 ) ;
}
return V_221 ;
}
static bool F_85 ( const struct V_80 * V_81 ,
enum V_212 V_212 , int V_213 )
{
const struct V_222 * V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
return V_223 -> V_100 [ V_212 ] <= F_74 ( V_212 , V_213 ) ;
}
static bool F_86 ( const struct V_80 * V_81 ,
int V_213 )
{
struct V_1 * V_2 = F_39 ( V_81 -> V_84 . V_83 -> V_85 ) ;
if ( V_213 > V_2 -> V_75 . V_124 )
return false ;
return F_85 ( V_81 , V_101 , V_213 ) &&
F_85 ( V_81 , V_102 , V_213 ) &&
F_85 ( V_81 , V_104 , V_213 ) ;
}
static void F_87 ( struct V_82 * V_83 ,
struct V_227 * V_228 , int V_213 )
{
if ( V_213 <= V_209 ) {
enum V_212 V_212 ;
F_88 (crtc, plane_id)
V_228 -> V_75 . V_100 [ V_212 ] = V_214 ;
}
if ( V_213 <= V_210 ) {
V_228 -> V_78 = false ;
V_228 -> V_162 . V_178 = V_214 ;
V_228 -> V_162 . V_100 = V_214 ;
V_228 -> V_162 . V_169 = V_214 ;
}
if ( V_213 <= V_211 ) {
V_228 -> V_176 = false ;
V_228 -> V_171 . V_178 = V_214 ;
V_228 -> V_171 . V_100 = V_214 ;
V_228 -> V_171 . V_169 = V_214 ;
}
}
static int F_89 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_38 ( V_81 -> V_84 . V_83 ) ;
struct V_229 * V_140 =
F_90 ( V_81 -> V_84 . V_140 ) ;
struct V_227 * V_228 = & V_81 -> V_75 . V_79 . V_230 ;
int V_231 = F_91 ( V_81 -> V_232 &
~ F_92 ( V_104 ) ) ;
const struct V_222 * V_223 ;
struct V_125 * V_126 ;
struct V_127 * V_100 ;
enum V_212 V_212 ;
int V_54 , V_213 ;
unsigned int V_221 = 0 ;
F_93 (state, plane, plane_state, i) {
const struct V_125 * V_233 =
F_94 ( V_100 -> V_84 . V_140 ) ;
if ( V_126 -> V_84 . V_83 != & V_83 -> V_84 &&
V_233 -> V_84 . V_83 != & V_83 -> V_84 )
continue;
if ( F_83 ( V_81 , V_126 ) )
V_221 |= F_92 ( V_100 -> V_129 ) ;
}
if ( ! V_221 )
return 0 ;
V_213 = V_209 ;
if ( ! F_86 ( V_81 , V_213 ) )
goto V_225;
V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
F_88 (crtc, plane_id)
V_228 -> V_75 . V_100 [ V_212 ] = V_223 -> V_100 [ V_212 ] ;
V_213 = V_210 ;
if ( ! F_86 ( V_81 , V_213 ) )
goto V_225;
V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
V_228 -> V_162 . V_100 = V_223 -> V_100 [ V_101 ] ;
V_228 -> V_162 . V_178 = V_223 -> V_100 [ V_104 ] ;
V_228 -> V_162 . V_169 = V_223 -> V_169 ;
V_228 -> V_78 = V_231 == F_92 ( V_101 ) ;
V_213 = V_211 ;
if ( ! F_86 ( V_81 , V_213 ) )
goto V_225;
V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
V_228 -> V_171 . V_100 = V_223 -> V_100 [ V_101 ] ;
V_228 -> V_171 . V_178 = V_223 -> V_100 [ V_104 ] ;
V_228 -> V_171 . V_169 = V_223 -> V_169 ;
V_228 -> V_176 = V_228 -> V_78 ;
V_213 ++ ;
V_225:
if ( V_213 == V_209 )
return - V_234 ;
F_87 ( V_83 , V_228 , V_213 ) ;
V_228 -> V_167 = V_213 > V_209 ;
if ( V_213 >= V_210 &&
V_228 -> V_162 . V_169 > F_75 ( V_210 ) )
V_228 -> V_167 = false ;
else if ( V_213 >= V_211 &&
V_228 -> V_171 . V_169 > F_75 ( V_211 ) )
V_228 -> V_167 = false ;
return 0 ;
}
static int F_95 ( struct V_235 * V_85 ,
struct V_82 * V_83 ,
struct V_80 * V_81 )
{
struct V_227 * V_236 = & V_81 -> V_75 . V_79 . V_236 ;
const struct V_227 * V_230 = & V_81 -> V_75 . V_79 . V_230 ;
const struct V_227 * V_128 = & V_83 -> V_75 . V_128 . V_79 ;
enum V_212 V_212 ;
V_236 -> V_78 = V_230 -> V_78 && V_128 -> V_78 &&
! V_81 -> V_237 ;
V_236 -> V_176 = V_230 -> V_176 && V_128 -> V_176 &&
! V_81 -> V_237 ;
V_236 -> V_167 = V_230 -> V_167 && V_128 -> V_167 ;
F_88 (crtc, plane_id) {
V_236 -> V_75 . V_100 [ V_212 ] =
F_63 ( V_230 -> V_75 . V_100 [ V_212 ] ,
V_128 -> V_75 . V_100 [ V_212 ] ) ;
F_96 ( V_236 -> V_75 . V_100 [ V_212 ] >
F_74 ( V_212 , V_209 ) ) ;
}
V_236 -> V_162 . V_100 = F_63 ( V_230 -> V_162 . V_100 ,
V_128 -> V_162 . V_100 ) ;
V_236 -> V_162 . V_178 = F_63 ( V_230 -> V_162 . V_178 ,
V_128 -> V_162 . V_178 ) ;
V_236 -> V_162 . V_169 = F_63 ( V_230 -> V_162 . V_169 ,
V_128 -> V_162 . V_169 ) ;
V_236 -> V_171 . V_100 = F_63 ( V_230 -> V_171 . V_100 ,
V_128 -> V_171 . V_100 ) ;
V_236 -> V_171 . V_178 = F_63 ( V_230 -> V_171 . V_178 ,
V_128 -> V_171 . V_178 ) ;
V_236 -> V_171 . V_169 = F_63 ( V_230 -> V_171 . V_169 ,
V_128 -> V_171 . V_169 ) ;
F_96 ( ( V_236 -> V_162 . V_100 >
F_74 ( V_101 , V_210 ) ||
V_236 -> V_162 . V_178 >
F_74 ( V_104 , V_210 ) ) &&
V_236 -> V_78 ) ;
F_96 ( ( V_236 -> V_162 . V_100 >
F_74 ( V_101 , V_211 ) ||
V_236 -> V_162 . V_178 >
F_74 ( V_104 , V_211 ) ) &&
V_236 -> V_176 ) ;
F_96 ( V_236 -> V_162 . V_169 > F_75 ( 1 ) &&
V_236 -> V_167 && V_236 -> V_78 ) ;
F_96 ( V_236 -> V_171 . V_169 > F_75 ( 2 ) &&
V_236 -> V_167 && V_236 -> V_176 ) ;
if ( memcmp ( V_236 , V_230 , sizeof( * V_236 ) ) != 0 )
V_81 -> V_75 . V_238 = true ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 ,
struct V_161 * V_75 )
{
struct V_82 * V_83 ;
int V_239 = 0 ;
V_75 -> V_78 = true ;
V_75 -> V_176 = true ;
V_75 -> V_167 = true ;
F_57 (&dev_priv->drm, crtc) {
const struct V_227 * V_228 = & V_83 -> V_75 . V_128 . V_79 ;
if ( ! V_83 -> V_128 )
continue;
if ( ! V_228 -> V_78 )
V_75 -> V_78 = false ;
if ( ! V_228 -> V_176 )
V_75 -> V_176 = false ;
if ( ! V_228 -> V_167 )
V_75 -> V_167 = false ;
V_239 ++ ;
}
if ( V_239 != 1 ) {
V_75 -> V_78 = false ;
V_75 -> V_176 = false ;
V_75 -> V_167 = false ;
}
F_57 (&dev_priv->drm, crtc) {
const struct V_227 * V_228 = & V_83 -> V_75 . V_128 . V_79 ;
enum V_88 V_88 = V_83 -> V_88 ;
V_75 -> V_88 [ V_88 ] = V_228 -> V_75 ;
if ( V_83 -> V_128 && V_75 -> V_78 )
V_75 -> V_162 = V_228 -> V_162 ;
if ( V_83 -> V_128 && V_75 -> V_176 )
V_75 -> V_171 = V_228 -> V_171 ;
}
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_161 * V_240 = & V_2 -> V_75 . V_79 ;
struct V_161 V_241 = {} ;
F_97 ( V_2 , & V_241 ) ;
if ( memcmp ( V_240 , & V_241 , sizeof( V_241 ) ) == 0 )
return;
if ( F_51 ( V_240 -> V_78 , V_241 . V_78 , true ) )
F_22 ( V_2 , false ) ;
F_64 ( V_2 , & V_241 ) ;
if ( F_52 ( V_240 -> V_78 , V_241 . V_78 , true ) )
F_22 ( V_2 , true ) ;
* V_240 = V_241 ;
}
static void F_99 ( struct V_229 * V_140 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_39 ( V_81 -> V_84 . V_83 -> V_85 ) ;
struct V_82 * V_83 = F_38 ( V_81 -> V_84 . V_83 ) ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_83 -> V_75 . V_128 . V_79 = V_81 -> V_75 . V_79 . V_236 ;
F_98 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_100 ( struct V_229 * V_140 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_39 ( V_81 -> V_84 . V_83 -> V_85 ) ;
struct V_82 * V_82 = F_38 ( V_81 -> V_84 . V_83 ) ;
if ( ! V_81 -> V_75 . V_238 )
return;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_82 -> V_75 . V_128 . V_79 = V_81 -> V_75 . V_79 . V_230 ;
F_98 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static unsigned int F_101 ( unsigned int V_108 ,
unsigned int V_110 ,
unsigned int V_111 ,
unsigned int V_109 ,
unsigned int V_53 )
{
unsigned int V_74 ;
V_74 = F_47 ( V_108 , V_110 ,
V_111 , V_109 , V_53 ) ;
V_74 = F_50 ( V_74 , 64 ) ;
return V_74 ;
}
static void F_102 ( struct V_1 * V_2 )
{
V_2 -> V_75 . V_208 [ V_242 ] = 3 ;
V_2 -> V_75 . V_124 = V_242 ;
if ( F_24 ( V_2 ) ) {
V_2 -> V_75 . V_208 [ V_243 ] = 12 ;
V_2 -> V_75 . V_208 [ V_244 ] = 33 ;
V_2 -> V_75 . V_124 = V_244 ;
}
}
static T_5 F_103 ( const struct V_80 * V_81 ,
const struct V_125 * V_126 ,
int V_213 )
{
struct V_127 * V_100 = F_55 ( V_126 -> V_84 . V_100 ) ;
struct V_1 * V_2 = F_39 ( V_100 -> V_84 . V_85 ) ;
const struct V_135 * V_136 =
& V_81 -> V_84 . V_136 ;
int clock , V_110 , V_109 , V_111 , V_75 ;
if ( V_2 -> V_75 . V_208 [ V_213 ] == 0 )
return V_214 ;
if ( ! F_54 ( V_81 , V_126 ) )
return 0 ;
V_109 = V_126 -> V_84 . V_130 -> V_141 -> V_109 [ 0 ] ;
clock = V_136 -> V_142 ;
V_110 = V_136 -> V_215 ;
V_111 = V_81 -> V_245 ;
if ( V_100 -> V_129 == V_104 ) {
V_75 = 63 ;
} else {
V_75 = F_101 ( clock , V_110 , V_111 , V_109 ,
V_2 -> V_75 . V_208 [ V_213 ] * 10 ) ;
}
return F_80 ( int , V_75 , V_214 ) ;
}
static bool F_104 ( unsigned int V_232 )
{
return ( V_232 & ( F_92 ( V_102 ) |
F_92 ( V_103 ) ) ) == F_92 ( V_103 ) ;
}
static int F_105 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_38 ( V_81 -> V_84 . V_83 ) ;
const struct V_222 * V_223 =
& V_81 -> V_75 . V_77 . V_223 [ V_242 ] ;
struct V_86 * V_87 = & V_81 -> V_75 . V_77 . V_87 ;
unsigned int V_232 = V_81 -> V_232 & ~ F_92 ( V_104 ) ;
int V_231 = F_91 ( V_232 ) ;
const int V_113 = 511 ;
int V_246 , V_247 = V_113 ;
int V_248 = 0 ;
unsigned int V_249 ;
enum V_212 V_212 ;
if ( F_104 ( V_232 ) )
V_248 = 1 ;
V_249 = V_223 -> V_100 [ V_101 ] +
V_223 -> V_100 [ V_102 ] +
V_223 -> V_100 [ V_103 ] +
V_248 ;
if ( V_249 > V_113 )
return - V_234 ;
if ( V_249 == 0 )
V_249 = 1 ;
F_88 (crtc, plane_id) {
unsigned int V_250 ;
if ( ( V_232 & F_92 ( V_212 ) ) == 0 ) {
V_87 -> V_100 [ V_212 ] = 0 ;
continue;
}
V_250 = V_223 -> V_100 [ V_212 ] ;
V_87 -> V_100 [ V_212 ] = V_113 * V_250 / V_249 ;
V_247 -= V_87 -> V_100 [ V_212 ] ;
}
V_87 -> V_100 [ V_102 ] += V_248 ;
V_247 -= V_248 ;
V_87 -> V_100 [ V_104 ] = 63 ;
V_246 = F_50 ( V_247 , V_231 ? : 1 ) ;
F_88 (crtc, plane_id) {
int V_251 ;
if ( V_247 == 0 )
break;
if ( ( V_232 & F_92 ( V_212 ) ) == 0 )
continue;
V_251 = F_79 ( V_246 , V_247 ) ;
V_87 -> V_100 [ V_212 ] += V_251 ;
V_247 -= V_251 ;
}
F_96 ( V_232 != 0 && V_247 != 0 ) ;
if ( V_232 == 0 ) {
F_96 ( V_247 != V_113 ) ;
V_87 -> V_100 [ V_101 ] = V_247 ;
}
return 0 ;
}
static void F_106 ( struct V_82 * V_83 ,
struct V_252 * V_228 , int V_213 )
{
struct V_1 * V_2 = F_39 ( V_83 -> V_84 . V_85 ) ;
for (; V_213 < F_53 ( V_2 ) ; V_213 ++ ) {
enum V_212 V_212 ;
F_88 (crtc, plane_id)
V_228 -> V_75 [ V_213 ] . V_100 [ V_212 ] = V_214 ;
V_228 -> V_162 [ V_213 ] . V_178 = V_214 ;
V_228 -> V_162 [ V_213 ] . V_100 = V_214 ;
}
}
static T_2 F_107 ( T_2 V_75 , T_2 V_113 )
{
if ( V_75 > V_113 )
return V_214 ;
else
return V_113 - V_75 ;
}
static bool F_108 ( struct V_80 * V_81 ,
int V_213 , enum V_212 V_212 , T_2 V_220 )
{
struct V_1 * V_2 = F_39 ( V_81 -> V_84 . V_83 -> V_85 ) ;
int V_224 = F_53 ( V_2 ) ;
bool V_221 = false ;
for (; V_213 < V_224 ; V_213 ++ ) {
struct V_222 * V_223 = & V_81 -> V_75 . V_77 . V_223 [ V_213 ] ;
V_221 |= V_223 -> V_100 [ V_212 ] != V_220 ;
V_223 -> V_100 [ V_212 ] = V_220 ;
}
return V_221 ;
}
static bool F_109 ( struct V_80 * V_81 ,
const struct V_125 * V_126 )
{
struct V_127 * V_100 = F_55 ( V_126 -> V_84 . V_100 ) ;
enum V_212 V_212 = V_100 -> V_129 ;
int V_224 = F_53 ( F_39 ( V_100 -> V_84 . V_85 ) ) ;
int V_213 ;
bool V_221 = false ;
if ( ! F_54 ( V_81 , V_126 ) ) {
V_221 |= F_108 ( V_81 , 0 , V_212 , 0 ) ;
goto V_225;
}
for ( V_213 = 0 ; V_213 < V_224 ; V_213 ++ ) {
struct V_222 * V_223 = & V_81 -> V_75 . V_77 . V_223 [ V_213 ] ;
int V_75 = F_103 ( V_81 , V_126 , V_213 ) ;
int V_119 = V_212 == V_104 ? 63 : 511 ;
if ( V_75 > V_119 )
break;
V_221 |= V_223 -> V_100 [ V_212 ] != V_75 ;
V_223 -> V_100 [ V_212 ] = V_75 ;
}
V_221 |= F_108 ( V_81 , V_213 , V_212 , V_214 ) ;
V_225:
if ( V_221 )
F_13 ( L_15 ,
V_100 -> V_84 . V_226 ,
V_81 -> V_75 . V_77 . V_223 [ V_242 ] . V_100 [ V_212 ] ,
V_81 -> V_75 . V_77 . V_223 [ V_243 ] . V_100 [ V_212 ] ,
V_81 -> V_75 . V_77 . V_223 [ V_244 ] . V_100 [ V_212 ] ) ;
return V_221 ;
}
static bool F_110 ( const struct V_80 * V_81 ,
enum V_212 V_212 , int V_213 )
{
const struct V_222 * V_223 =
& V_81 -> V_75 . V_77 . V_223 [ V_213 ] ;
const struct V_86 * V_87 =
& V_81 -> V_75 . V_77 . V_87 ;
return V_223 -> V_100 [ V_212 ] <= V_87 -> V_100 [ V_212 ] ;
}
static bool F_111 ( const struct V_80 * V_81 , int V_213 )
{
return F_110 ( V_81 , V_101 , V_213 ) &&
F_110 ( V_81 , V_102 , V_213 ) &&
F_110 ( V_81 , V_103 , V_213 ) &&
F_110 ( V_81 , V_104 , V_213 ) ;
}
static int F_112 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_38 ( V_81 -> V_84 . V_83 ) ;
struct V_1 * V_2 = F_39 ( V_83 -> V_84 . V_85 ) ;
struct V_229 * V_140 =
F_90 ( V_81 -> V_84 . V_140 ) ;
struct V_252 * V_228 = & V_81 -> V_75 . V_77 . V_230 ;
const struct V_86 * V_87 =
& V_81 -> V_75 . V_77 . V_87 ;
int V_231 = F_91 ( V_81 -> V_232 &
~ F_92 ( V_104 ) ) ;
bool V_253 = F_113 ( & V_81 -> V_84 ) ;
struct V_125 * V_126 ;
struct V_127 * V_100 ;
enum V_212 V_212 ;
int V_213 , V_74 , V_54 ;
unsigned int V_221 = 0 ;
F_93 (state, plane, plane_state, i) {
const struct V_125 * V_233 =
F_94 ( V_100 -> V_84 . V_140 ) ;
if ( V_126 -> V_84 . V_83 != & V_83 -> V_84 &&
V_233 -> V_84 . V_83 != & V_83 -> V_84 )
continue;
if ( F_109 ( V_81 , V_126 ) )
V_221 |= F_92 ( V_100 -> V_129 ) ;
}
if ( V_253 )
V_81 -> V_254 = true ;
if ( ! V_221 )
return 0 ;
if ( V_221 & ~ F_92 ( V_104 ) ) {
const struct V_80 * V_255 =
F_114 ( V_83 -> V_84 . V_140 ) ;
const struct V_86 * V_256 =
& V_255 -> V_75 . V_77 . V_87 ;
V_74 = F_105 ( V_81 ) ;
if ( V_74 )
return V_74 ;
if ( V_253 ||
memcmp ( V_256 , V_87 ,
sizeof( * V_87 ) ) != 0 )
V_81 -> V_254 = true ;
}
V_228 -> V_224 = F_53 ( V_2 ) ;
V_228 -> V_78 = V_83 -> V_88 != V_98 && V_231 == 1 ;
for ( V_213 = 0 ; V_213 < V_228 -> V_224 ; V_213 ++ ) {
const struct V_222 * V_223 = & V_81 -> V_75 . V_77 . V_223 [ V_213 ] ;
const int V_257 = F_115 ( V_2 ) -> V_258 * 512 - 1 ;
if ( ! F_111 ( V_81 , V_213 ) )
break;
F_88 (crtc, plane_id) {
V_228 -> V_75 [ V_213 ] . V_100 [ V_212 ] =
F_107 ( V_223 -> V_100 [ V_212 ] ,
V_87 -> V_100 [ V_212 ] ) ;
}
V_228 -> V_162 [ V_213 ] . V_100 =
F_107 ( F_116 ( V_223 -> V_100 [ V_101 ] ,
V_223 -> V_100 [ V_102 ] ,
V_223 -> V_100 [ V_103 ] ) ,
V_257 ) ;
V_228 -> V_162 [ V_213 ] . V_178 =
F_107 ( V_223 -> V_100 [ V_104 ] ,
63 ) ;
}
if ( V_213 == 0 )
return - V_234 ;
V_228 -> V_224 = V_213 ;
F_106 ( V_83 , V_228 , V_213 ) ;
return 0 ;
}
static void F_117 ( struct V_229 * V_140 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = F_38 ( V_81 -> V_84 . V_83 ) ;
struct V_1 * V_2 = F_39 ( V_83 -> V_84 . V_85 ) ;
const struct V_86 * V_87 =
& V_81 -> V_75 . V_77 . V_87 ;
int V_89 , V_90 , V_113 ;
if ( ! V_81 -> V_254 )
return;
V_89 = V_87 -> V_100 [ V_101 ] ;
V_90 = V_87 -> V_100 [ V_102 ] + V_89 ;
V_113 = V_87 -> V_100 [ V_103 ] + V_90 ;
F_96 ( V_87 -> V_100 [ V_104 ] != 63 ) ;
F_96 ( V_113 != 511 ) ;
F_118 ( V_83 , V_89 , V_90 , V_113 ) ;
F_119 ( & V_2 -> V_259 . V_260 ) ;
switch ( V_83 -> V_88 ) {
T_3 V_91 , V_92 , V_93 ;
case V_94 :
V_91 = F_120 ( V_95 ) ;
V_92 = F_120 ( V_96 ) ;
V_91 &= ~ ( F_121 ( V_175 , 0xff ) |
F_121 ( V_173 , 0xff ) ) ;
V_91 |= ( F_121 ( V_175 , V_89 ) |
F_121 ( V_173 , V_90 ) ) ;
V_92 &= ~ ( F_121 ( V_205 , 0x1 ) |
F_121 ( V_204 , 0x1 ) ) ;
V_92 |= ( F_121 ( V_205 , V_89 >> 8 ) |
F_121 ( V_204 , V_90 >> 8 ) ) ;
F_122 ( V_95 , V_91 ) ;
F_122 ( V_96 , V_92 ) ;
break;
case V_97 :
V_91 = F_120 ( V_95 ) ;
V_92 = F_120 ( V_96 ) ;
V_91 &= ~ ( F_121 ( V_190 , 0xff ) |
F_121 ( V_189 , 0xff ) ) ;
V_91 |= ( F_121 ( V_190 , V_89 ) |
F_121 ( V_189 , V_90 ) ) ;
V_92 &= ~ ( F_121 ( V_202 , 0xff ) |
F_121 ( V_201 , 0xff ) ) ;
V_92 |= ( F_121 ( V_202 , V_89 >> 8 ) |
F_121 ( V_201 , V_90 >> 8 ) ) ;
F_122 ( V_95 , V_91 ) ;
F_122 ( V_96 , V_92 ) ;
break;
case V_98 :
V_93 = F_120 ( V_99 ) ;
V_92 = F_120 ( V_96 ) ;
V_93 &= ~ ( F_121 ( V_193 , 0xff ) |
F_121 ( V_192 , 0xff ) ) ;
V_93 |= ( F_121 ( V_193 , V_89 ) |
F_121 ( V_192 , V_90 ) ) ;
V_92 &= ~ ( F_121 ( V_199 , 0xff ) |
F_121 ( V_198 , 0xff ) ) ;
V_92 |= ( F_121 ( V_199 , V_89 >> 8 ) |
F_121 ( V_198 , V_90 >> 8 ) ) ;
F_122 ( V_99 , V_93 ) ;
F_122 ( V_96 , V_92 ) ;
break;
default:
break;
}
F_123 ( V_95 ) ;
F_124 ( & V_2 -> V_259 . V_260 ) ;
}
static int F_125 ( struct V_235 * V_85 ,
struct V_82 * V_83 ,
struct V_80 * V_81 )
{
struct V_252 * V_236 = & V_81 -> V_75 . V_77 . V_236 ;
const struct V_252 * V_230 = & V_81 -> V_75 . V_77 . V_230 ;
const struct V_252 * V_128 = & V_83 -> V_75 . V_128 . V_77 ;
int V_213 ;
V_236 -> V_224 = F_79 ( V_230 -> V_224 , V_128 -> V_224 ) ;
V_236 -> V_78 = V_230 -> V_78 && V_128 -> V_78 &&
! V_81 -> V_237 ;
for ( V_213 = 0 ; V_213 < V_236 -> V_224 ; V_213 ++ ) {
enum V_212 V_212 ;
F_88 (crtc, plane_id) {
V_236 -> V_75 [ V_213 ] . V_100 [ V_212 ] =
F_79 ( V_230 -> V_75 [ V_213 ] . V_100 [ V_212 ] ,
V_128 -> V_75 [ V_213 ] . V_100 [ V_212 ] ) ;
}
V_236 -> V_162 [ V_213 ] . V_100 = F_79 ( V_230 -> V_162 [ V_213 ] . V_100 ,
V_128 -> V_162 [ V_213 ] . V_100 ) ;
V_236 -> V_162 [ V_213 ] . V_178 = F_79 ( V_230 -> V_162 [ V_213 ] . V_178 ,
V_128 -> V_162 [ V_213 ] . V_178 ) ;
}
F_106 ( V_83 , V_236 , V_213 ) ;
if ( memcmp ( V_236 , V_230 , sizeof( * V_236 ) ) != 0 )
V_81 -> V_75 . V_238 = true ;
return 0 ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_179 * V_75 )
{
struct V_82 * V_83 ;
int V_239 = 0 ;
V_75 -> V_213 = V_2 -> V_75 . V_124 ;
V_75 -> V_78 = true ;
F_57 (&dev_priv->drm, crtc) {
const struct V_252 * V_228 = & V_83 -> V_75 . V_128 . V_77 ;
if ( ! V_83 -> V_128 )
continue;
if ( ! V_228 -> V_78 )
V_75 -> V_78 = false ;
V_239 ++ ;
V_75 -> V_213 = F_80 ( int , V_75 -> V_213 , V_228 -> V_224 - 1 ) ;
}
if ( V_239 != 1 )
V_75 -> V_78 = false ;
if ( V_239 > 1 )
V_75 -> V_213 = V_242 ;
F_57 (&dev_priv->drm, crtc) {
const struct V_252 * V_228 = & V_83 -> V_75 . V_128 . V_77 ;
enum V_88 V_88 = V_83 -> V_88 ;
V_75 -> V_88 [ V_88 ] = V_228 -> V_75 [ V_75 -> V_213 ] ;
if ( V_83 -> V_128 && V_75 -> V_78 )
V_75 -> V_162 = V_228 -> V_162 [ V_75 -> V_213 ] ;
V_75 -> V_180 [ V_88 ] . V_100 [ V_101 ] = V_261 | 2 ;
V_75 -> V_180 [ V_88 ] . V_100 [ V_102 ] = V_261 | 2 ;
V_75 -> V_180 [ V_88 ] . V_100 [ V_103 ] = V_261 | 2 ;
V_75 -> V_180 [ V_88 ] . V_100 [ V_104 ] = V_261 | 2 ;
}
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_179 * V_240 = & V_2 -> V_75 . V_77 ;
struct V_179 V_241 = {} ;
F_126 ( V_2 , & V_241 ) ;
if ( memcmp ( V_240 , & V_241 , sizeof( V_241 ) ) == 0 )
return;
if ( F_51 ( V_240 -> V_213 , V_241 . V_213 , V_244 ) )
F_14 ( V_2 , false ) ;
if ( F_51 ( V_240 -> V_213 , V_241 . V_213 , V_243 ) )
F_21 ( V_2 , false ) ;
if ( F_51 ( V_240 -> V_78 , V_241 . V_78 , true ) )
F_22 ( V_2 , false ) ;
F_68 ( V_2 , & V_241 ) ;
if ( F_52 ( V_240 -> V_78 , V_241 . V_78 , true ) )
F_22 ( V_2 , true ) ;
if ( F_52 ( V_240 -> V_213 , V_241 . V_213 , V_243 ) )
F_21 ( V_2 , true ) ;
if ( F_52 ( V_240 -> V_213 , V_241 . V_213 , V_244 ) )
F_14 ( V_2 , true ) ;
* V_240 = V_241 ;
}
static void F_128 ( struct V_229 * V_140 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_39 ( V_81 -> V_84 . V_83 -> V_85 ) ;
struct V_82 * V_83 = F_38 ( V_81 -> V_84 . V_83 ) ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_83 -> V_75 . V_128 . V_77 = V_81 -> V_75 . V_77 . V_236 ;
F_127 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_129 ( struct V_229 * V_140 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_39 ( V_81 -> V_84 . V_83 -> V_85 ) ;
struct V_82 * V_82 = F_38 ( V_81 -> V_84 . V_83 ) ;
if ( ! V_81 -> V_75 . V_238 )
return;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_82 -> V_75 . V_128 . V_77 = V_81 -> V_75 . V_77 . V_230 ;
F_127 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_130 ( struct V_82 * V_133 )
{
struct V_1 * V_2 = F_39 ( V_133 -> V_84 . V_85 ) ;
struct V_82 * V_83 ;
int V_262 = 1 ;
int V_149 = 16 ;
bool V_263 ;
V_83 = F_56 ( V_2 ) ;
if ( V_83 ) {
static const int V_264 = 12000 ;
const struct V_135 * V_136 =
& V_83 -> V_137 -> V_84 . V_136 ;
const struct V_138 * V_130 =
V_83 -> V_84 . V_139 -> V_140 -> V_130 ;
int clock = V_136 -> V_142 ;
int V_110 = V_136 -> V_215 ;
int V_265 = V_83 -> V_137 -> V_245 ;
int V_109 = V_130 -> V_141 -> V_109 [ 0 ] ;
int V_115 ;
V_115 = F_47 ( clock , V_110 ,
V_265 , V_109 , V_264 / 100 ) ;
V_115 = F_50 ( V_115 , V_266 ) ;
V_262 = V_267 - V_115 ;
if ( V_262 < 0 )
V_262 = 1 ;
V_262 &= 0x1ff ;
F_13 ( L_16 ,
V_115 , V_262 ) ;
V_115 = F_47 ( clock , V_110 ,
V_83 -> V_84 . V_178 -> V_140 -> V_216 , 4 ,
V_264 / 100 ) ;
V_115 = F_50 ( V_115 ,
V_268 . V_117 ) +
V_268 . V_118 ;
V_149 = V_268 . V_113 - V_115 ;
if ( V_149 > V_268 . V_119 )
V_149 = V_268 . V_119 ;
F_13 ( L_17
L_18 , V_262 , V_149 ) ;
V_263 = true ;
} else {
V_263 = false ;
F_36 ( V_2 , false ) ;
}
F_13 ( L_19 ,
V_262 ) ;
F_2 ( V_145 , F_61 ( V_262 , V_147 ) |
F_61 ( 8 , V_163 ) |
F_61 ( 8 , V_164 ) |
F_61 ( 8 , V_165 ) ) ;
F_2 ( V_166 , F_61 ( 8 , V_174 ) |
F_61 ( 8 , V_269 ) ) ;
F_2 ( V_70 , F_61 ( V_149 , V_151 ) ) ;
if ( V_263 )
F_36 ( V_2 , true ) ;
}
static void F_131 ( struct V_82 * V_133 )
{
struct V_1 * V_2 = F_39 ( V_133 -> V_84 . V_85 ) ;
const struct V_112 * V_270 ;
T_3 V_271 ;
T_3 V_272 ;
int V_273 , V_262 = 1 ;
int V_113 ;
int V_274 , V_275 ;
struct V_82 * V_83 , * V_132 = NULL ;
if ( F_30 ( V_2 ) )
V_270 = & V_276 ;
else if ( ! F_132 ( V_2 ) )
V_270 = & V_277 ;
else
V_270 = & V_278 ;
V_113 = V_2 -> V_279 . V_280 ( V_2 , 0 ) ;
V_83 = F_133 ( V_2 , 0 ) ;
if ( F_58 ( V_83 ) ) {
const struct V_135 * V_136 =
& V_83 -> V_137 -> V_84 . V_136 ;
const struct V_138 * V_130 =
V_83 -> V_84 . V_139 -> V_140 -> V_130 ;
int V_109 ;
if ( F_132 ( V_2 ) )
V_109 = 4 ;
else
V_109 = V_130 -> V_141 -> V_109 [ 0 ] ;
V_274 = F_49 ( V_136 -> V_142 ,
V_270 , V_113 , V_109 ,
V_281 ) ;
V_132 = V_83 ;
} else {
V_274 = V_113 - V_270 -> V_118 ;
if ( V_274 > ( long ) V_270 -> V_119 )
V_274 = V_270 -> V_119 ;
}
if ( F_132 ( V_2 ) )
V_270 = & V_282 ;
V_113 = V_2 -> V_279 . V_280 ( V_2 , 1 ) ;
V_83 = F_133 ( V_2 , 1 ) ;
if ( F_58 ( V_83 ) ) {
const struct V_135 * V_136 =
& V_83 -> V_137 -> V_84 . V_136 ;
const struct V_138 * V_130 =
V_83 -> V_84 . V_139 -> V_140 -> V_130 ;
int V_109 ;
if ( F_132 ( V_2 ) )
V_109 = 4 ;
else
V_109 = V_130 -> V_141 -> V_109 [ 0 ] ;
V_275 = F_49 ( V_136 -> V_142 ,
V_270 , V_113 , V_109 ,
V_281 ) ;
if ( V_132 == NULL )
V_132 = V_83 ;
else
V_132 = NULL ;
} else {
V_275 = V_113 - V_270 -> V_118 ;
if ( V_275 > ( long ) V_270 -> V_119 )
V_275 = V_270 -> V_119 ;
}
F_13 ( L_20 , V_274 , V_275 ) ;
if ( F_33 ( V_2 ) && V_132 ) {
struct V_283 * V_284 ;
V_284 = F_134 ( V_132 -> V_84 . V_139 -> V_140 -> V_130 ) ;
if ( ! F_135 ( V_284 ) )
V_132 = NULL ;
}
V_273 = 2 ;
F_36 ( V_2 , false ) ;
if ( F_136 ( V_2 ) && V_132 ) {
static const int V_264 = 6000 ;
const struct V_135 * V_136 =
& V_132 -> V_137 -> V_84 . V_136 ;
const struct V_138 * V_130 =
V_132 -> V_84 . V_139 -> V_140 -> V_130 ;
int clock = V_136 -> V_142 ;
int V_110 = V_136 -> V_215 ;
int V_265 = V_132 -> V_137 -> V_245 ;
int V_109 ;
int V_115 ;
if ( F_33 ( V_2 ) || F_30 ( V_2 ) )
V_109 = 4 ;
else
V_109 = V_130 -> V_141 -> V_109 [ 0 ] ;
V_115 = F_47 ( clock , V_110 , V_265 , V_109 ,
V_264 / 100 ) ;
V_115 = F_50 ( V_115 , V_270 -> V_117 ) ;
F_13 ( L_21 , V_115 ) ;
V_262 = V_270 -> V_113 - V_115 ;
if ( V_262 < 0 )
V_262 = 1 ;
if ( F_29 ( V_2 ) || F_30 ( V_2 ) )
F_2 ( V_68 ,
V_285 | ( V_262 & 0xff ) ) ;
else
F_2 ( V_68 , V_262 & 0x3f ) ;
}
F_13 ( L_22 ,
V_274 , V_275 , V_273 , V_262 ) ;
V_271 = ( ( V_275 & 0x3f ) << 16 ) | ( V_274 & 0x3f ) ;
V_272 = ( V_273 & 0x1f ) ;
V_271 = V_271 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_272 = V_272 | ( 1 << 8 ) ;
F_2 ( V_286 , V_271 ) ;
F_2 ( V_287 , V_272 ) ;
if ( V_132 )
F_36 ( V_2 , true ) ;
}
static void F_137 ( struct V_82 * V_133 )
{
struct V_1 * V_2 = F_39 ( V_133 -> V_84 . V_85 ) ;
struct V_82 * V_83 ;
const struct V_135 * V_136 ;
T_3 V_271 ;
int V_274 ;
V_83 = F_56 ( V_2 ) ;
if ( V_83 == NULL )
return;
V_136 = & V_83 -> V_137 -> V_84 . V_136 ;
V_274 = F_49 ( V_136 -> V_142 ,
& V_288 ,
V_2 -> V_279 . V_280 ( V_2 , 0 ) ,
4 , V_281 ) ;
V_271 = F_3 ( V_286 ) & ~ 0xfff ;
V_271 |= ( 3 << 8 ) | V_274 ;
F_13 ( L_23 , V_274 ) ;
F_2 ( V_286 , V_271 ) ;
}
static unsigned int F_138 ( unsigned int V_108 ,
unsigned int V_109 ,
unsigned int V_53 )
{
unsigned int V_74 ;
V_74 = F_45 ( V_108 , V_109 , V_53 ) ;
V_74 = F_50 ( V_74 , 64 ) + 2 ;
return V_74 ;
}
static unsigned int F_139 ( unsigned int V_108 ,
unsigned int V_110 ,
unsigned int V_111 ,
unsigned int V_109 ,
unsigned int V_53 )
{
unsigned int V_74 ;
V_74 = F_47 ( V_108 , V_110 ,
V_111 , V_109 , V_53 ) ;
V_74 = F_50 ( V_74 , 64 ) + 2 ;
return V_74 ;
}
static T_3 F_140 ( T_3 V_289 , T_3 V_290 ,
T_6 V_109 )
{
if ( F_96 ( ! V_109 ) )
return 0 ;
if ( F_96 ( ! V_290 ) )
return 0 ;
return F_50 ( V_289 * 64 , V_290 * V_109 ) + 2 ;
}
static T_3 F_141 ( const struct V_80 * V_291 ,
const struct V_125 * V_292 ,
T_3 V_293 ,
bool V_294 )
{
T_3 V_295 , V_296 ;
int V_109 ;
if ( ! F_54 ( V_291 , V_292 ) )
return 0 ;
V_109 = V_292 -> V_84 . V_130 -> V_141 -> V_109 [ 0 ] ;
V_295 = F_138 ( V_291 -> V_108 , V_109 , V_293 ) ;
if ( ! V_294 )
return V_295 ;
V_296 = F_139 ( V_291 -> V_108 ,
V_291 -> V_84 . V_136 . V_215 ,
F_78 ( & V_292 -> V_84 . V_217 ) ,
V_109 , V_293 ) ;
return F_79 ( V_295 , V_296 ) ;
}
static T_3 F_142 ( const struct V_80 * V_291 ,
const struct V_125 * V_292 ,
T_3 V_293 )
{
T_3 V_295 , V_296 ;
int V_109 ;
if ( ! F_54 ( V_291 , V_292 ) )
return 0 ;
V_109 = V_292 -> V_84 . V_130 -> V_141 -> V_109 [ 0 ] ;
V_295 = F_138 ( V_291 -> V_108 , V_109 , V_293 ) ;
V_296 = F_139 ( V_291 -> V_108 ,
V_291 -> V_84 . V_136 . V_215 ,
F_78 ( & V_292 -> V_84 . V_217 ) ,
V_109 , V_293 ) ;
return F_79 ( V_295 , V_296 ) ;
}
static T_3 F_143 ( const struct V_80 * V_291 ,
const struct V_125 * V_292 ,
T_3 V_293 )
{
int V_109 ;
if ( ! F_54 ( V_291 , V_292 ) )
return 0 ;
V_109 = V_292 -> V_84 . V_130 -> V_141 -> V_109 [ 0 ] ;
return F_139 ( V_291 -> V_108 ,
V_291 -> V_84 . V_136 . V_215 ,
V_292 -> V_84 . V_216 , V_109 , V_293 ) ;
}
static T_3 F_84 ( const struct V_80 * V_291 ,
const struct V_125 * V_292 ,
T_3 V_289 )
{
int V_109 ;
if ( ! F_54 ( V_291 , V_292 ) )
return 0 ;
V_109 = V_292 -> V_84 . V_130 -> V_141 -> V_109 [ 0 ] ;
return F_140 ( V_289 , F_78 ( & V_292 -> V_84 . V_217 ) , V_109 ) ;
}
static unsigned int
F_144 ( const struct V_1 * V_2 )
{
if ( F_145 ( V_2 ) >= 8 )
return 3072 ;
else if ( F_145 ( V_2 ) >= 7 )
return 768 ;
else
return 512 ;
}
static unsigned int
F_146 ( const struct V_1 * V_2 ,
int V_213 , bool V_297 )
{
if ( F_145 ( V_2 ) >= 8 )
return V_213 == 0 ? 255 : 2047 ;
else if ( F_145 ( V_2 ) >= 7 )
return V_213 == 0 ? 127 : 1023 ;
else if ( ! V_297 )
return V_213 == 0 ? 127 : 511 ;
else
return V_213 == 0 ? 63 : 255 ;
}
static unsigned int
F_147 ( const struct V_1 * V_2 , int V_213 )
{
if ( F_145 ( V_2 ) >= 7 )
return V_213 == 0 ? 63 : 255 ;
else
return V_213 == 0 ? 31 : 63 ;
}
static unsigned int F_148 ( const struct V_1 * V_2 )
{
if ( F_145 ( V_2 ) >= 8 )
return 31 ;
else
return 15 ;
}
static unsigned int F_149 ( const struct V_235 * V_85 ,
int V_213 ,
const struct V_298 * V_137 ,
enum V_299 V_300 ,
bool V_297 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
unsigned int V_113 = F_144 ( V_2 ) ;
if ( V_297 && ! V_137 -> V_301 )
return 0 ;
if ( V_213 == 0 || V_137 -> V_302 > 1 ) {
V_113 /= F_115 ( V_2 ) -> V_258 ;
if ( F_145 ( V_2 ) <= 6 )
V_113 /= 2 ;
}
if ( V_137 -> V_301 ) {
if ( V_213 > 0 && V_300 == V_303 ) {
if ( V_297 )
V_113 *= 5 ;
V_113 /= 6 ;
} else {
V_113 /= 2 ;
}
}
return F_79 ( V_113 , F_146 ( V_2 , V_213 , V_297 ) ) ;
}
static unsigned int F_150 ( const struct V_235 * V_85 ,
int V_213 ,
const struct V_298 * V_137 )
{
if ( V_213 > 0 && V_137 -> V_302 > 1 )
return 64 ;
return F_147 ( F_39 ( V_85 ) , V_213 ) ;
}
static void F_151 ( const struct V_235 * V_85 ,
int V_213 ,
const struct V_298 * V_137 ,
enum V_299 V_300 ,
struct V_304 * F_63 )
{
F_63 -> V_305 = F_149 ( V_85 , V_213 , V_137 , V_300 , false ) ;
F_63 -> V_306 = F_149 ( V_85 , V_213 , V_137 , V_300 , true ) ;
F_63 -> V_307 = F_150 ( V_85 , V_213 , V_137 ) ;
F_63 -> V_169 = F_148 ( F_39 ( V_85 ) ) ;
}
static void F_152 ( const struct V_1 * V_2 ,
int V_213 ,
struct V_304 * F_63 )
{
F_63 -> V_305 = F_146 ( V_2 , V_213 , false ) ;
F_63 -> V_306 = F_146 ( V_2 , V_213 , true ) ;
F_63 -> V_307 = F_147 ( V_2 , V_213 ) ;
F_63 -> V_169 = F_148 ( V_2 ) ;
}
static bool F_153 ( int V_213 ,
const struct V_304 * F_63 ,
struct V_308 * V_309 )
{
bool V_74 ;
if ( ! V_309 -> V_56 )
return false ;
V_309 -> V_56 = V_309 -> V_289 <= F_63 -> V_305 &&
V_309 -> V_310 <= F_63 -> V_306 &&
V_309 -> V_311 <= F_63 -> V_307 ;
V_74 = V_309 -> V_56 ;
if ( V_213 == 0 && ! V_309 -> V_56 ) {
if ( V_309 -> V_289 > F_63 -> V_305 )
F_13 ( L_24 ,
V_213 , V_309 -> V_289 , F_63 -> V_305 ) ;
if ( V_309 -> V_310 > F_63 -> V_306 )
F_13 ( L_25 ,
V_213 , V_309 -> V_310 , F_63 -> V_306 ) ;
if ( V_309 -> V_311 > F_63 -> V_307 )
F_13 ( L_26 ,
V_213 , V_309 -> V_311 , F_63 -> V_307 ) ;
V_309 -> V_289 = F_80 ( T_3 , V_309 -> V_289 , F_63 -> V_305 ) ;
V_309 -> V_310 = F_80 ( T_3 , V_309 -> V_310 , F_63 -> V_306 ) ;
V_309 -> V_311 = F_80 ( T_3 , V_309 -> V_311 , F_63 -> V_307 ) ;
V_309 -> V_56 = true ;
}
return V_74 ;
}
static void F_154 ( const struct V_1 * V_2 ,
const struct V_82 * V_82 ,
int V_213 ,
struct V_80 * V_291 ,
struct V_125 * V_312 ,
struct V_125 * V_313 ,
struct V_125 * V_314 ,
struct V_308 * V_309 )
{
T_5 V_208 = V_2 -> V_75 . V_208 [ V_213 ] ;
T_5 V_315 = V_2 -> V_75 . V_315 [ V_213 ] ;
T_5 V_316 = V_2 -> V_75 . V_316 [ V_213 ] ;
if ( V_213 > 0 ) {
V_208 *= 5 ;
V_315 *= 5 ;
V_316 *= 5 ;
}
if ( V_312 ) {
V_309 -> V_289 = F_141 ( V_291 , V_312 ,
V_208 , V_213 ) ;
V_309 -> V_317 = F_84 ( V_291 , V_312 , V_309 -> V_289 ) ;
}
if ( V_313 )
V_309 -> V_310 = F_142 ( V_291 , V_313 , V_315 ) ;
if ( V_314 )
V_309 -> V_311 = F_143 ( V_291 , V_314 , V_316 ) ;
V_309 -> V_56 = true ;
}
static T_3
F_155 ( const struct V_80 * V_291 )
{
const struct V_229 * V_318 =
F_90 ( V_291 -> V_84 . V_140 ) ;
const struct V_135 * V_136 =
& V_291 -> V_84 . V_136 ;
T_1 V_319 , V_320 ;
if ( ! V_291 -> V_84 . V_128 )
return 0 ;
if ( F_96 ( V_136 -> V_142 == 0 ) )
return 0 ;
if ( F_96 ( V_318 -> V_321 . V_322 . V_321 == 0 ) )
return 0 ;
V_319 = F_156 ( V_136 -> V_215 * 1000 * 8 ,
V_136 -> V_142 ) ;
V_320 = F_156 ( V_136 -> V_215 * 1000 * 8 ,
V_318 -> V_321 . V_322 . V_321 ) ;
return F_157 ( V_320 ) |
F_158 ( V_319 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
T_5 V_75 [ 8 ] )
{
if ( F_160 ( V_2 ) ) {
T_3 V_21 ;
int V_74 , V_54 ;
int V_213 , V_124 = F_161 ( V_2 ) ;
V_21 = 0 ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_74 = F_162 ( V_2 ,
V_323 ,
& V_21 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
if ( V_74 ) {
F_19 ( L_27 , V_74 ) ;
return;
}
V_75 [ 0 ] = V_21 & V_324 ;
V_75 [ 1 ] = ( V_21 >> V_325 ) &
V_324 ;
V_75 [ 2 ] = ( V_21 >> V_326 ) &
V_324 ;
V_75 [ 3 ] = ( V_21 >> V_327 ) &
V_324 ;
V_21 = 1 ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_74 = F_162 ( V_2 ,
V_323 ,
& V_21 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
if ( V_74 ) {
F_19 ( L_27 , V_74 ) ;
return;
}
V_75 [ 4 ] = V_21 & V_324 ;
V_75 [ 5 ] = ( V_21 >> V_325 ) &
V_324 ;
V_75 [ 6 ] = ( V_21 >> V_326 ) &
V_324 ;
V_75 [ 7 ] = ( V_21 >> V_327 ) &
V_324 ;
for ( V_213 = 1 ; V_213 <= V_124 ; V_213 ++ ) {
if ( V_75 [ V_213 ] == 0 ) {
for ( V_54 = V_213 + 1 ; V_54 <= V_124 ; V_54 ++ )
V_75 [ V_54 ] = 0 ;
break;
}
}
if ( V_75 [ 0 ] == 0 ) {
V_75 [ 0 ] += 2 ;
for ( V_213 = 1 ; V_213 <= V_124 ; V_213 ++ ) {
if ( V_75 [ V_213 ] == 0 )
break;
V_75 [ V_213 ] += 2 ;
}
}
} else if ( F_163 ( V_2 ) || F_164 ( V_2 ) ) {
T_4 V_328 = F_165 ( V_329 ) ;
V_75 [ 0 ] = ( V_328 >> 56 ) & 0xFF ;
if ( V_75 [ 0 ] == 0 )
V_75 [ 0 ] = V_328 & 0xF ;
V_75 [ 1 ] = ( V_328 >> 4 ) & 0xFF ;
V_75 [ 2 ] = ( V_328 >> 12 ) & 0xFF ;
V_75 [ 3 ] = ( V_328 >> 20 ) & 0x1FF ;
V_75 [ 4 ] = ( V_328 >> 32 ) & 0x1FF ;
} else if ( F_145 ( V_2 ) >= 6 ) {
T_3 V_328 = F_3 ( V_329 ) ;
V_75 [ 0 ] = ( V_328 >> V_330 ) & V_331 ;
V_75 [ 1 ] = ( V_328 >> V_332 ) & V_331 ;
V_75 [ 2 ] = ( V_328 >> V_333 ) & V_331 ;
V_75 [ 3 ] = ( V_328 >> V_334 ) & V_331 ;
} else if ( F_145 ( V_2 ) >= 5 ) {
T_3 V_335 = F_3 ( V_336 ) ;
V_75 [ 0 ] = 7 ;
V_75 [ 1 ] = ( V_335 >> V_337 ) & V_338 ;
V_75 [ 2 ] = ( V_335 >> V_339 ) & V_338 ;
}
}
static void F_166 ( struct V_1 * V_2 ,
T_5 V_75 [ 5 ] )
{
if ( F_167 ( V_2 ) )
V_75 [ 0 ] = 13 ;
}
static void F_168 ( struct V_1 * V_2 ,
T_5 V_75 [ 5 ] )
{
if ( F_167 ( V_2 ) )
V_75 [ 0 ] = 13 ;
if ( F_169 ( V_2 ) )
V_75 [ 3 ] *= 2 ;
}
int F_161 ( const struct V_1 * V_2 )
{
if ( F_145 ( V_2 ) >= 9 )
return 7 ;
else if ( F_163 ( V_2 ) || F_164 ( V_2 ) )
return 4 ;
else if ( F_145 ( V_2 ) >= 6 )
return 3 ;
else
return 2 ;
}
static void F_170 ( struct V_1 * V_2 ,
const char * V_226 ,
const T_5 V_75 [ 8 ] )
{
int V_213 , V_124 = F_161 ( V_2 ) ;
for ( V_213 = 0 ; V_213 <= V_124 ; V_213 ++ ) {
unsigned int V_53 = V_75 [ V_213 ] ;
if ( V_53 == 0 ) {
F_19 ( L_28 ,
V_226 , V_213 ) ;
continue;
}
if ( F_160 ( V_2 ) )
V_53 *= 10 ;
else if ( V_213 > 0 )
V_53 *= 5 ;
F_13 ( L_29 ,
V_226 , V_213 , V_75 [ V_213 ] ,
V_53 / 10 , V_53 % 10 ) ;
}
}
static bool F_171 ( struct V_1 * V_2 ,
T_5 V_75 [ 5 ] , T_5 F_79 )
{
int V_213 , V_124 = F_161 ( V_2 ) ;
if ( V_75 [ 0 ] >= F_79 )
return false ;
V_75 [ 0 ] = F_63 ( V_75 [ 0 ] , F_79 ) ;
for ( V_213 = 1 ; V_213 <= V_124 ; V_213 ++ )
V_75 [ V_213 ] = F_172 ( T_5 , V_75 [ V_213 ] , F_50 ( F_79 , 5 ) ) ;
return true ;
}
static void F_173 ( struct V_1 * V_2 )
{
bool V_340 ;
V_340 = F_171 ( V_2 , V_2 -> V_75 . V_208 , 12 ) |
F_171 ( V_2 , V_2 -> V_75 . V_315 , 12 ) |
F_171 ( V_2 , V_2 -> V_75 . V_316 , 12 ) ;
if ( ! V_340 )
return;
F_13 ( L_30 ) ;
F_170 ( V_2 , L_31 , V_2 -> V_75 . V_208 ) ;
F_170 ( V_2 , L_32 , V_2 -> V_75 . V_315 ) ;
F_170 ( V_2 , L_33 , V_2 -> V_75 . V_316 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
F_159 ( V_2 , V_2 -> V_75 . V_208 ) ;
memcpy ( V_2 -> V_75 . V_315 , V_2 -> V_75 . V_208 ,
sizeof( V_2 -> V_75 . V_208 ) ) ;
memcpy ( V_2 -> V_75 . V_316 , V_2 -> V_75 . V_208 ,
sizeof( V_2 -> V_75 . V_208 ) ) ;
F_166 ( V_2 , V_2 -> V_75 . V_315 ) ;
F_168 ( V_2 , V_2 -> V_75 . V_316 ) ;
F_170 ( V_2 , L_31 , V_2 -> V_75 . V_208 ) ;
F_170 ( V_2 , L_32 , V_2 -> V_75 . V_315 ) ;
F_170 ( V_2 , L_33 , V_2 -> V_75 . V_316 ) ;
if ( F_175 ( V_2 ) )
F_173 ( V_2 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
F_159 ( V_2 , V_2 -> V_75 . V_341 ) ;
F_170 ( V_2 , L_34 , V_2 -> V_75 . V_341 ) ;
}
static bool F_177 ( struct V_235 * V_85 ,
struct V_342 * V_343 )
{
const struct V_298 V_137 = {
. V_302 = 1 ,
. V_301 = V_343 -> V_301 ,
. V_344 = V_343 -> V_344 ,
} ;
struct V_304 F_63 ;
F_151 ( V_85 , 0 , & V_137 , V_345 , & F_63 ) ;
if ( ! F_153 ( 0 , & F_63 , & V_343 -> V_75 [ 0 ] ) ) {
F_13 ( L_35 ) ;
return false ;
}
return true ;
}
static int F_178 ( struct V_80 * V_291 )
{
struct V_346 * V_140 = V_291 -> V_84 . V_140 ;
struct V_82 * V_82 = F_38 ( V_291 -> V_84 . V_83 ) ;
struct V_342 * V_343 ;
struct V_235 * V_85 = V_140 -> V_85 ;
const struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_127 * V_127 ;
struct V_125 * V_312 = NULL ;
struct V_125 * V_313 = NULL ;
struct V_125 * V_314 = NULL ;
int V_213 , V_124 = F_161 ( V_2 ) , V_347 ;
struct V_304 F_63 ;
V_343 = & V_291 -> V_75 . V_348 . V_230 ;
F_179 (dev, intel_crtc, intel_plane) {
struct V_125 * V_349 ;
V_349 = F_180 ( V_140 ,
V_127 ) ;
if ( ! V_349 )
continue;
if ( V_127 -> V_84 . type == V_350 )
V_312 = V_349 ;
else if ( V_127 -> V_84 . type == V_351 )
V_313 = V_349 ;
else if ( V_127 -> V_84 . type == V_352 )
V_314 = V_349 ;
}
V_343 -> V_353 = V_291 -> V_84 . V_128 ;
if ( V_313 ) {
V_343 -> V_301 = V_313 -> V_84 . V_131 ;
V_343 -> V_344 = V_313 -> V_84 . V_131 &&
( F_78 ( & V_313 -> V_84 . V_217 ) != F_78 ( & V_313 -> V_84 . V_354 ) >> 16 ||
F_181 ( & V_313 -> V_84 . V_217 ) != F_181 ( & V_313 -> V_84 . V_354 ) >> 16 ) ;
}
V_347 = V_124 ;
if ( F_145 ( V_2 ) <= 6 && V_343 -> V_301 )
V_347 = 1 ;
if ( V_343 -> V_344 )
V_347 = 0 ;
F_154 ( V_2 , V_82 , 0 , V_291 ,
V_312 , V_313 , V_314 , & V_343 -> V_355 [ 0 ] ) ;
memset ( & V_343 -> V_75 , 0 , sizeof( V_343 -> V_75 ) ) ;
V_343 -> V_75 [ 0 ] = V_343 -> V_355 [ 0 ] ;
if ( F_163 ( V_2 ) || F_164 ( V_2 ) )
V_343 -> V_319 = F_155 ( V_291 ) ;
if ( ! F_177 ( V_85 , V_343 ) )
return - V_234 ;
F_152 ( V_2 , 1 , & F_63 ) ;
for ( V_213 = 1 ; V_213 <= V_124 ; V_213 ++ ) {
struct V_308 * V_75 = & V_343 -> V_355 [ V_213 ] ;
F_154 ( V_2 , V_82 , V_213 , V_291 ,
V_312 , V_313 , V_314 , V_75 ) ;
if ( V_213 > V_347 )
continue;
if ( F_153 ( V_213 , & F_63 , V_75 ) )
V_343 -> V_75 [ V_213 ] = * V_75 ;
else
V_347 = V_213 ;
}
return 0 ;
}
static int F_182 ( struct V_235 * V_85 ,
struct V_82 * V_82 ,
struct V_80 * V_356 )
{
struct V_342 * V_357 = & V_356 -> V_75 . V_348 . V_236 ;
struct V_342 * V_358 = & V_82 -> V_75 . V_128 . V_348 ;
int V_213 , V_124 = F_161 ( F_39 ( V_85 ) ) ;
* V_357 = V_356 -> V_75 . V_348 . V_230 ;
V_357 -> V_353 |= V_358 -> V_353 ;
V_357 -> V_301 |= V_358 -> V_301 ;
V_357 -> V_344 |= V_358 -> V_344 ;
for ( V_213 = 0 ; V_213 <= V_124 ; V_213 ++ ) {
struct V_308 * V_359 = & V_357 -> V_75 [ V_213 ] ;
const struct V_308 * V_360 = & V_358 -> V_75 [ V_213 ] ;
V_359 -> V_56 &= V_360 -> V_56 ;
V_359 -> V_289 = F_63 ( V_359 -> V_289 , V_360 -> V_289 ) ;
V_359 -> V_310 = F_63 ( V_359 -> V_310 , V_360 -> V_310 ) ;
V_359 -> V_311 = F_63 ( V_359 -> V_311 , V_360 -> V_311 ) ;
V_359 -> V_317 = F_63 ( V_359 -> V_317 , V_360 -> V_317 ) ;
}
if ( ! F_177 ( V_85 , V_357 ) )
return - V_234 ;
if ( memcmp ( V_357 , & V_356 -> V_75 . V_348 . V_230 , sizeof( * V_357 ) ) != 0 )
V_356 -> V_75 . V_238 = true ;
return 0 ;
}
static void F_183 ( struct V_235 * V_85 ,
int V_213 ,
struct V_308 * V_361 )
{
const struct V_82 * V_82 ;
V_361 -> V_56 = true ;
F_57 (dev, intel_crtc) {
const struct V_342 * V_128 = & V_82 -> V_75 . V_128 . V_348 ;
const struct V_308 * V_75 = & V_128 -> V_75 [ V_213 ] ;
if ( ! V_128 -> V_353 )
continue;
if ( ! V_75 -> V_56 )
V_361 -> V_56 = false ;
V_361 -> V_289 = F_63 ( V_361 -> V_289 , V_75 -> V_289 ) ;
V_361 -> V_310 = F_63 ( V_361 -> V_310 , V_75 -> V_310 ) ;
V_361 -> V_311 = F_63 ( V_361 -> V_311 , V_75 -> V_311 ) ;
V_361 -> V_317 = F_63 ( V_361 -> V_317 , V_75 -> V_317 ) ;
}
}
static void F_184 ( struct V_235 * V_85 ,
const struct V_298 * V_137 ,
const struct V_304 * F_63 ,
struct V_342 * V_362 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
int V_213 , V_124 = F_161 ( V_2 ) ;
int V_363 = V_124 ;
if ( ( F_145 ( V_2 ) <= 6 || F_169 ( V_2 ) ) &&
V_137 -> V_302 > 1 )
V_363 = 0 ;
V_362 -> V_364 = F_145 ( V_2 ) >= 6 ;
for ( V_213 = 1 ; V_213 <= V_124 ; V_213 ++ ) {
struct V_308 * V_75 = & V_362 -> V_75 [ V_213 ] ;
F_183 ( V_85 , V_213 , V_75 ) ;
if ( V_213 > V_363 )
V_75 -> V_56 = false ;
else if ( ! F_153 ( V_213 , F_63 , V_75 ) )
V_363 = V_213 - 1 ;
if ( V_75 -> V_317 > F_63 -> V_169 ) {
if ( V_75 -> V_56 )
V_362 -> V_364 = false ;
V_75 -> V_317 = 0 ;
}
}
if ( F_167 ( V_2 ) && ! V_362 -> V_364 &&
F_185 ( V_2 ) ) {
for ( V_213 = 2 ; V_213 <= V_124 ; V_213 ++ ) {
struct V_308 * V_75 = & V_362 -> V_75 [ V_213 ] ;
V_75 -> V_56 = false ;
}
}
}
static int F_186 ( int V_365 , const struct V_342 * V_343 )
{
return V_365 + ( V_365 >= 2 && V_343 -> V_75 [ 4 ] . V_56 ) ;
}
static unsigned int F_187 ( struct V_235 * V_85 , int V_213 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
if ( F_163 ( V_2 ) || F_164 ( V_2 ) )
return 2 * V_213 ;
else
return V_2 -> V_75 . V_208 [ V_213 ] ;
}
static void F_188 ( struct V_235 * V_85 ,
const struct V_342 * V_362 ,
enum V_299 V_366 ,
struct V_367 * V_368 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_82 * V_82 ;
int V_213 , V_365 ;
V_368 -> V_369 = V_362 -> V_364 ;
V_368 -> V_366 = V_366 ;
for ( V_365 = 1 ; V_365 <= 3 ; V_365 ++ ) {
const struct V_308 * V_370 ;
V_213 = F_186 ( V_365 , V_362 ) ;
V_370 = & V_362 -> V_75 [ V_213 ] ;
V_368 -> V_365 [ V_365 - 1 ] =
( F_187 ( V_85 , V_213 ) << V_371 ) |
( V_370 -> V_289 << V_372 ) |
V_370 -> V_311 ;
if ( V_370 -> V_56 )
V_368 -> V_365 [ V_365 - 1 ] |= V_373 ;
if ( F_145 ( V_2 ) >= 8 )
V_368 -> V_365 [ V_365 - 1 ] |=
V_370 -> V_317 << V_374 ;
else
V_368 -> V_365 [ V_365 - 1 ] |=
V_370 -> V_317 << V_375 ;
if ( F_145 ( V_2 ) <= 6 && V_370 -> V_310 ) {
F_96 ( V_365 != 1 ) ;
V_368 -> V_376 [ V_365 - 1 ] = V_377 | V_370 -> V_310 ;
} else
V_368 -> V_376 [ V_365 - 1 ] = V_370 -> V_310 ;
}
F_57 (dev, intel_crtc) {
enum V_88 V_88 = V_82 -> V_88 ;
const struct V_308 * V_370 =
& V_82 -> V_75 . V_128 . V_348 . V_75 [ 0 ] ;
if ( F_96 ( ! V_370 -> V_56 ) )
continue;
V_368 -> V_378 [ V_88 ] = V_82 -> V_75 . V_128 . V_348 . V_319 ;
V_368 -> V_379 [ V_88 ] =
( V_370 -> V_289 << V_380 ) |
( V_370 -> V_310 << V_381 ) |
V_370 -> V_311 ;
}
}
static struct V_342 * F_189 ( struct V_235 * V_85 ,
struct V_342 * V_382 ,
struct V_342 * V_383 )
{
int V_213 , V_124 = F_161 ( F_39 ( V_85 ) ) ;
int V_384 = 0 , V_385 = 0 ;
for ( V_213 = 1 ; V_213 <= V_124 ; V_213 ++ ) {
if ( V_382 -> V_75 [ V_213 ] . V_56 )
V_384 = V_213 ;
if ( V_383 -> V_75 [ V_213 ] . V_56 )
V_385 = V_213 ;
}
if ( V_384 == V_385 ) {
if ( V_383 -> V_364 && ! V_382 -> V_364 )
return V_383 ;
else
return V_382 ;
} else if ( V_384 > V_385 ) {
return V_382 ;
} else {
return V_383 ;
}
}
static unsigned int F_190 ( struct V_1 * V_2 ,
const struct V_367 * V_121 ,
const struct V_367 * V_122 )
{
unsigned int V_221 = 0 ;
enum V_88 V_88 ;
int V_365 ;
F_65 (dev_priv, pipe) {
if ( V_121 -> V_378 [ V_88 ] != V_122 -> V_378 [ V_88 ] ) {
V_221 |= F_191 ( V_88 ) ;
V_221 |= V_386 ;
}
if ( V_121 -> V_379 [ V_88 ] != V_122 -> V_379 [ V_88 ] ) {
V_221 |= F_192 ( V_88 ) ;
V_221 |= V_386 ;
}
}
if ( V_121 -> V_369 != V_122 -> V_369 ) {
V_221 |= V_387 ;
V_221 |= V_386 ;
}
if ( V_121 -> V_366 != V_122 -> V_366 ) {
V_221 |= V_388 ;
V_221 |= V_386 ;
}
if ( V_221 & V_386 )
return V_221 ;
for ( V_365 = 1 ; V_365 <= 3 ; V_365 ++ ) {
if ( V_121 -> V_365 [ V_365 - 1 ] != V_122 -> V_365 [ V_365 - 1 ] ||
V_121 -> V_376 [ V_365 - 1 ] != V_122 -> V_376 [ V_365 - 1 ] )
break;
}
for (; V_365 <= 3 ; V_365 ++ )
V_221 |= F_193 ( V_365 ) ;
return V_221 ;
}
static bool F_194 ( struct V_1 * V_2 ,
unsigned int V_221 )
{
struct V_367 * V_389 = & V_2 -> V_75 . V_390 ;
bool V_340 = false ;
if ( V_221 & F_193 ( 3 ) && V_389 -> V_365 [ 2 ] & V_373 ) {
V_389 -> V_365 [ 2 ] &= ~ V_373 ;
F_2 ( V_391 , V_389 -> V_365 [ 2 ] ) ;
V_340 = true ;
}
if ( V_221 & F_193 ( 2 ) && V_389 -> V_365 [ 1 ] & V_373 ) {
V_389 -> V_365 [ 1 ] &= ~ V_373 ;
F_2 ( V_392 , V_389 -> V_365 [ 1 ] ) ;
V_340 = true ;
}
if ( V_221 & F_193 ( 1 ) && V_389 -> V_365 [ 0 ] & V_373 ) {
V_389 -> V_365 [ 0 ] &= ~ V_373 ;
F_2 ( V_393 , V_389 -> V_365 [ 0 ] ) ;
V_340 = true ;
}
return V_340 ;
}
static void F_195 ( struct V_1 * V_2 ,
struct V_367 * V_368 )
{
struct V_367 * V_389 = & V_2 -> V_75 . V_390 ;
unsigned int V_221 ;
T_3 V_21 ;
V_221 = F_190 ( V_2 , V_389 , V_368 ) ;
if ( ! V_221 )
return;
F_194 ( V_2 , V_221 ) ;
if ( V_221 & F_192 ( V_94 ) )
F_2 ( V_394 , V_368 -> V_379 [ 0 ] ) ;
if ( V_221 & F_192 ( V_97 ) )
F_2 ( V_395 , V_368 -> V_379 [ 1 ] ) ;
if ( V_221 & F_192 ( V_98 ) )
F_2 ( V_396 , V_368 -> V_379 [ 2 ] ) ;
if ( V_221 & F_191 ( V_94 ) )
F_2 ( F_196 ( V_94 ) , V_368 -> V_378 [ 0 ] ) ;
if ( V_221 & F_191 ( V_97 ) )
F_2 ( F_196 ( V_97 ) , V_368 -> V_378 [ 1 ] ) ;
if ( V_221 & F_191 ( V_98 ) )
F_2 ( F_196 ( V_98 ) , V_368 -> V_378 [ 2 ] ) ;
if ( V_221 & V_388 ) {
if ( F_163 ( V_2 ) || F_164 ( V_2 ) ) {
V_21 = F_3 ( V_397 ) ;
if ( V_368 -> V_366 == V_345 )
V_21 &= ~ V_398 ;
else
V_21 |= V_398 ;
F_2 ( V_397 , V_21 ) ;
} else {
V_21 = F_3 ( V_399 ) ;
if ( V_368 -> V_366 == V_345 )
V_21 &= ~ V_400 ;
else
V_21 |= V_400 ;
F_2 ( V_399 , V_21 ) ;
}
}
if ( V_221 & V_387 ) {
V_21 = F_3 ( V_9 ) ;
if ( V_368 -> V_369 )
V_21 &= ~ V_10 ;
else
V_21 |= V_10 ;
F_2 ( V_9 , V_21 ) ;
}
if ( V_221 & F_193 ( 1 ) &&
V_389 -> V_376 [ 0 ] != V_368 -> V_376 [ 0 ] )
F_2 ( V_401 , V_368 -> V_376 [ 0 ] ) ;
if ( F_145 ( V_2 ) >= 7 ) {
if ( V_221 & F_193 ( 2 ) && V_389 -> V_376 [ 1 ] != V_368 -> V_376 [ 1 ] )
F_2 ( V_402 , V_368 -> V_376 [ 1 ] ) ;
if ( V_221 & F_193 ( 3 ) && V_389 -> V_376 [ 2 ] != V_368 -> V_376 [ 2 ] )
F_2 ( V_403 , V_368 -> V_376 [ 2 ] ) ;
}
if ( V_221 & F_193 ( 1 ) && V_389 -> V_365 [ 0 ] != V_368 -> V_365 [ 0 ] )
F_2 ( V_393 , V_368 -> V_365 [ 0 ] ) ;
if ( V_221 & F_193 ( 2 ) && V_389 -> V_365 [ 1 ] != V_368 -> V_365 [ 1 ] )
F_2 ( V_392 , V_368 -> V_365 [ 1 ] ) ;
if ( V_221 & F_193 ( 3 ) && V_389 -> V_365 [ 2 ] != V_368 -> V_365 [ 2 ] )
F_2 ( V_391 , V_368 -> V_365 [ 2 ] ) ;
V_2 -> V_75 . V_390 = * V_368 ;
}
bool F_197 ( struct V_235 * V_85 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
return F_194 ( V_2 , V_386 ) ;
}
static bool F_198 ( struct V_229 * V_140 )
{
struct V_1 * V_2 = F_39 ( V_140 -> V_84 . V_85 ) ;
if ( F_199 ( V_2 ) || F_200 ( V_2 ) )
return true ;
return false ;
}
static bool
F_201 ( struct V_1 * V_2 )
{
if ( F_202 ( V_2 ) || F_203 ( V_2 ) )
return true ;
if ( F_204 ( V_2 ) &&
V_2 -> V_404 != V_405 )
return true ;
return false ;
}
int
F_205 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! F_201 ( V_2 ) )
return 0 ;
if ( V_2 -> V_404 == V_406 )
return 0 ;
F_13 ( L_36 ) ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_74 = F_206 ( V_2 , V_407 ,
V_408 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
if ( F_204 ( V_2 ) && V_74 == - V_409 ) {
F_10 ( L_37 ) ;
V_2 -> V_404 = V_405 ;
return 0 ;
} else if ( V_74 < 0 ) {
F_19 ( L_38 ) ;
return V_74 ;
}
V_2 -> V_404 = V_406 ;
return 0 ;
}
int
F_207 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! F_201 ( V_2 ) )
return 0 ;
if ( V_2 -> V_404 == V_410 )
return 0 ;
F_13 ( L_39 ) ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_74 = F_208 ( V_2 , V_407 ,
V_411 ,
V_412 , V_412 ,
1 ) ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
if ( F_204 ( V_2 ) && V_74 == - V_409 ) {
F_10 ( L_37 ) ;
V_2 -> V_404 = V_405 ;
return 0 ;
} else if ( V_74 < 0 ) {
F_19 ( L_40 , V_74 ) ;
return V_74 ;
}
V_2 -> V_404 = V_410 ;
return 0 ;
}
bool F_209 ( struct V_346 * V_140 )
{
struct V_235 * V_85 = V_140 -> V_85 ;
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_229 * V_318 = F_90 ( V_140 ) ;
struct V_82 * V_83 ;
struct V_127 * V_100 ;
struct V_80 * V_291 ;
enum V_88 V_88 ;
int V_213 , V_53 ;
if ( ! F_201 ( V_2 ) )
return false ;
if ( F_91 ( V_318 -> V_413 ) == 0 )
return true ;
else if ( F_91 ( V_318 -> V_413 ) > 1 )
return false ;
V_88 = F_210 ( V_318 -> V_413 ) - 1 ;
V_83 = F_67 ( V_2 , V_88 ) ;
V_291 = F_114 ( V_83 -> V_84 . V_140 ) ;
if ( V_83 -> V_84 . V_140 -> V_136 . V_414 & V_415 )
return false ;
F_179 (dev, crtc, plane) {
struct V_416 * V_75 =
& V_291 -> V_75 . V_417 . V_230 . V_418 [ V_100 -> V_129 ] ;
if ( ! V_75 -> V_75 [ 0 ] . V_419 )
continue;
for ( V_213 = F_161 ( V_2 ) ;
! V_75 -> V_75 [ V_213 ] . V_419 ; -- V_213 )
{ }
V_53 = V_2 -> V_75 . V_341 [ V_213 ] ;
if ( F_198 ( V_318 ) &&
V_100 -> V_84 . V_140 -> V_130 -> V_420 ==
V_421 )
V_53 += 15 ;
if ( V_53 < V_422 )
return false ;
}
return true ;
}
static void
F_211 ( struct V_235 * V_85 ,
const struct V_80 * V_291 ,
struct V_423 * V_424 ,
int * V_425 )
{
struct V_346 * V_140 = V_291 -> V_84 . V_140 ;
struct V_229 * V_318 = F_90 ( V_140 ) ;
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_426 * V_427 = V_291 -> V_84 . V_83 ;
unsigned int V_428 , V_429 ;
int V_430 ;
if ( F_96 ( ! V_140 ) || ! V_291 -> V_84 . V_128 ) {
V_424 -> V_431 = 0 ;
V_424 -> V_432 = 0 ;
* V_425 = F_91 ( V_2 -> V_413 ) ;
return;
}
if ( V_318 -> V_433 )
* V_425 = F_91 ( V_318 -> V_413 ) ;
else
* V_425 = F_91 ( V_2 -> V_413 ) ;
V_429 = F_115 ( V_2 ) -> V_429 ;
F_96 ( V_429 == 0 ) ;
V_429 -= 4 ;
if ( ! V_318 -> V_433 ) {
* V_424 = F_114 ( V_427 -> V_140 ) -> V_75 . V_417 . V_434 ;
return;
}
V_430 = F_91 ( V_318 -> V_413 &
( F_212 ( V_427 ) - 1 ) ) ;
V_428 = V_429 / F_91 ( V_318 -> V_413 ) ;
V_424 -> V_431 = V_430 * V_429 / * V_425 ;
V_424 -> V_432 = V_424 -> V_431 + V_428 ;
}
static unsigned int F_213 ( int V_425 )
{
if ( V_425 == 1 )
return 32 ;
return 8 ;
}
static void F_214 ( struct V_423 * V_435 , T_1 V_134 )
{
V_435 -> V_431 = V_134 & 0x3ff ;
V_435 -> V_432 = ( V_134 >> 16 ) & 0x3ff ;
if ( V_435 -> V_432 )
V_435 -> V_432 += 1 ;
}
void F_215 ( struct V_1 * V_2 ,
struct V_436 * V_434 )
{
struct V_82 * V_83 ;
memset ( V_434 , 0 , sizeof( * V_434 ) ) ;
F_57 (&dev_priv->drm, crtc) {
enum V_437 V_438 ;
enum V_212 V_212 ;
enum V_88 V_88 = V_83 -> V_88 ;
V_438 = F_216 ( V_88 ) ;
if ( ! F_217 ( V_2 , V_438 ) )
continue;
F_88 (crtc, plane_id) {
T_1 V_21 ;
if ( V_212 != V_104 )
V_21 = F_3 ( F_218 ( V_88 , V_212 ) ) ;
else
V_21 = F_3 ( F_219 ( V_88 ) ) ;
F_214 ( & V_434 -> V_100 [ V_88 ] [ V_212 ] , V_21 ) ;
}
F_220 ( V_2 , V_438 ) ;
}
}
static T_7
F_221 ( const struct V_80 * V_291 ,
const struct V_125 * V_292 )
{
struct V_127 * V_100 = F_55 ( V_292 -> V_84 . V_100 ) ;
T_3 V_439 , V_440 , V_441 , V_442 ;
T_7 V_443 , V_444 ;
T_7 V_445 , V_446 ;
if ( F_96 ( ! F_54 ( V_291 , V_292 ) ) )
return F_222 ( 0 ) ;
if ( V_100 -> V_129 == V_104 ) {
V_439 = V_292 -> V_84 . V_439 >> 16 ;
V_440 = V_292 -> V_84 . V_440 >> 16 ;
V_441 = V_292 -> V_84 . V_216 ;
V_442 = V_292 -> V_84 . V_447 ;
} else {
V_439 = F_78 ( & V_292 -> V_84 . V_354 ) >> 16 ;
V_440 = F_181 ( & V_292 -> V_84 . V_354 ) >> 16 ;
V_441 = F_78 ( & V_292 -> V_84 . V_217 ) ;
V_442 = F_181 ( & V_292 -> V_84 . V_217 ) ;
}
V_443 = F_223 ( V_439 , V_441 ) ;
V_444 = F_223 ( V_440 , V_442 ) ;
V_446 = F_224 ( V_443 , F_222 ( 1 ) ) ;
V_445 = F_224 ( V_444 , F_222 ( 1 ) ) ;
return F_225 ( V_446 , V_445 ) ;
}
static T_7
F_226 ( const struct V_80 * V_81 )
{
T_7 V_448 = F_222 ( 1 ) ;
if ( ! V_81 -> V_84 . V_56 )
return V_448 ;
if ( V_81 -> V_449 . V_132 ) {
T_3 V_439 , V_440 , V_441 , V_442 ;
T_3 V_450 = V_81 -> V_449 . V_105 ;
T_7 V_443 , V_444 ;
T_7 V_445 , V_446 ;
V_439 = V_81 -> V_245 ;
V_440 = V_81 -> V_451 ;
V_441 = V_450 >> 16 ;
V_442 = V_450 & 0xffff ;
if ( ! V_441 || ! V_442 )
return V_448 ;
V_443 = F_223 ( V_439 , V_441 ) ;
V_444 = F_223 ( V_440 , V_442 ) ;
V_446 = F_224 ( V_443 , F_222 ( 1 ) ) ;
V_445 = F_224 ( V_444 , F_222 ( 1 ) ) ;
V_448 = F_225 ( V_446 , V_445 ) ;
}
return V_448 ;
}
int F_227 ( struct V_82 * V_82 ,
struct V_80 * V_291 )
{
struct V_452 * V_81 = & V_291 -> V_84 ;
struct V_346 * V_140 = V_81 -> V_140 ;
struct V_453 * V_100 ;
const struct V_454 * V_292 ;
struct V_125 * V_455 ;
int V_142 , V_456 ;
T_3 V_457 ;
T_7 V_448 ;
T_7 V_458 = F_222 ( 1 ) ;
if ( ! V_291 -> V_84 . V_56 )
return 0 ;
F_228 (plane, pstate, crtc_state) {
T_7 V_459 ;
T_7 V_460 = F_223 ( 9 , 8 ) ;
int V_461 ;
if ( ! F_54 ( V_291 ,
F_94 ( V_292 ) ) )
continue;
if ( F_96 ( ! V_292 -> V_130 ) )
return - V_234 ;
V_455 = F_94 ( V_292 ) ;
V_459 = F_221 ( V_291 ,
V_455 ) ;
V_461 = V_292 -> V_130 -> V_141 -> V_109 [ 0 ] * 8 ;
if ( V_461 == 64 )
V_459 = F_225 ( V_459 ,
V_460 ) ;
V_458 = F_224 ( V_459 , V_458 ) ;
}
V_448 = F_226 ( V_291 ) ;
V_448 = F_225 ( V_448 , V_458 ) ;
V_142 = V_81 -> V_136 . V_142 ;
V_456 = F_90 ( V_140 ) -> V_321 . V_322 . V_321 ;
if ( F_229 ( F_39 ( V_82 -> V_84 . V_85 ) ) )
V_456 *= 2 ;
V_457 = F_230 ( V_456 , V_448 ) ;
if ( V_457 < V_142 ) {
F_13 ( L_41 ) ;
return - V_234 ;
}
return 0 ;
}
static unsigned int
F_231 ( const struct V_80 * V_291 ,
const struct V_454 * V_292 ,
int V_462 )
{
struct V_127 * V_100 = F_55 ( V_292 -> V_100 ) ;
struct V_125 * V_455 = F_94 ( V_292 ) ;
T_3 V_463 ;
T_3 V_111 = 0 , V_464 = 0 ;
struct V_138 * V_130 ;
T_1 V_141 ;
T_7 V_465 ;
if ( ! V_455 -> V_84 . V_131 )
return 0 ;
V_130 = V_292 -> V_130 ;
V_141 = V_130 -> V_141 -> V_141 ;
if ( V_100 -> V_129 == V_104 )
return 0 ;
if ( V_462 && V_141 != V_466 )
return 0 ;
V_111 = F_78 ( & V_455 -> V_84 . V_354 ) >> 16 ;
V_464 = F_181 ( & V_455 -> V_84 . V_354 ) >> 16 ;
if ( V_141 == V_466 ) {
if ( V_462 )
V_463 = V_111 * V_464 *
V_130 -> V_141 -> V_109 [ 0 ] ;
else
V_463 = ( V_111 / 2 ) * ( V_464 / 2 ) *
V_130 -> V_141 -> V_109 [ 1 ] ;
} else {
V_463 = V_111 * V_464 * V_130 -> V_141 -> V_109 [ 0 ] ;
}
V_465 = F_221 ( V_291 , V_455 ) ;
return F_232 ( V_463 , V_465 ) ;
}
static unsigned int
F_233 ( struct V_80 * V_467 ,
unsigned * V_468 ,
unsigned * V_469 )
{
struct V_452 * V_291 = & V_467 -> V_84 ;
struct V_346 * V_140 = V_291 -> V_140 ;
struct V_453 * V_100 ;
const struct V_454 * V_292 ;
unsigned int V_470 = 0 ;
if ( F_96 ( ! V_140 ) )
return 0 ;
F_228 (plane, pstate, cstate) {
enum V_212 V_212 = F_55 ( V_100 ) -> V_129 ;
unsigned int V_250 ;
V_250 = F_231 ( V_467 ,
V_292 , 0 ) ;
V_468 [ V_212 ] = V_250 ;
V_470 += V_250 ;
V_250 = F_231 ( V_467 ,
V_292 , 1 ) ;
V_469 [ V_212 ] = V_250 ;
V_470 += V_250 ;
}
return V_470 ;
}
static T_5
F_234 ( const struct V_454 * V_292 ,
const int V_462 )
{
struct V_138 * V_130 = V_292 -> V_130 ;
struct V_125 * V_455 = F_94 ( V_292 ) ;
T_3 V_439 , V_440 ;
T_3 V_471 = 8 ;
T_6 V_472 ;
if ( F_96 ( ! V_130 ) )
return 0 ;
if ( V_462 && V_130 -> V_141 -> V_141 != V_466 )
return 0 ;
if ( V_130 -> V_420 != V_473 &&
V_130 -> V_420 != V_474 )
return 8 ;
V_439 = F_78 ( & V_455 -> V_84 . V_354 ) >> 16 ;
V_440 = F_181 ( & V_455 -> V_84 . V_354 ) >> 16 ;
if ( V_130 -> V_141 -> V_141 == V_466 && ! V_462 ) {
V_439 /= 2 ;
V_440 /= 2 ;
}
if ( V_130 -> V_141 -> V_141 == V_466 && ! V_462 )
V_472 = V_130 -> V_141 -> V_109 [ 1 ] ;
else
V_472 = V_130 -> V_141 -> V_109 [ 0 ] ;
if ( F_235 ( V_292 -> V_475 ) ) {
switch ( V_472 ) {
case 1 :
V_471 = 32 ;
break;
case 2 :
V_471 = 16 ;
break;
case 4 :
V_471 = 8 ;
break;
case 8 :
V_471 = 4 ;
break;
default:
F_236 ( 1 , L_42 ,
V_472 ) ;
V_471 = 32 ;
}
}
return F_50 ( ( 4 * V_439 * V_472 ) , 512 ) * V_471 / 4 + 3 ;
}
static void
F_237 ( const struct V_80 * V_291 , int V_425 ,
T_5 * V_476 , T_5 * V_477 )
{
const struct V_454 * V_292 ;
struct V_453 * V_100 ;
F_228 (plane, pstate, &cstate->base) {
enum V_212 V_212 = F_55 ( V_100 ) -> V_129 ;
if ( V_212 == V_104 )
continue;
if ( ! V_292 -> V_131 )
continue;
V_476 [ V_212 ] = F_234 ( V_292 , 0 ) ;
V_477 [ V_212 ] = F_234 ( V_292 , 1 ) ;
}
V_476 [ V_104 ] = F_213 ( V_425 ) ;
}
static int
F_238 ( struct V_80 * V_291 ,
struct V_436 * V_434 )
{
struct V_346 * V_140 = V_291 -> V_84 . V_140 ;
struct V_426 * V_83 = V_291 -> V_84 . V_83 ;
struct V_235 * V_85 = V_83 -> V_85 ;
struct V_82 * V_82 = F_38 ( V_83 ) ;
enum V_88 V_88 = V_82 -> V_88 ;
struct V_423 * V_424 = & V_291 -> V_75 . V_417 . V_434 ;
T_5 V_478 , V_431 ;
T_5 V_476 [ V_479 ] = {} ;
T_5 V_477 [ V_479 ] = {} ;
unsigned int V_470 ;
enum V_212 V_212 ;
int V_425 ;
unsigned V_468 [ V_479 ] = {} ;
unsigned V_469 [ V_479 ] = {} ;
T_5 V_480 = 0 ;
memset ( V_434 -> V_100 [ V_88 ] , 0 , sizeof( V_434 -> V_100 [ V_88 ] ) ) ;
memset ( V_434 -> V_481 [ V_88 ] , 0 , sizeof( V_434 -> V_481 [ V_88 ] ) ) ;
if ( F_96 ( ! V_140 ) )
return 0 ;
if ( ! V_291 -> V_84 . V_128 ) {
V_424 -> V_431 = V_424 -> V_432 = 0 ;
return 0 ;
}
F_211 ( V_85 , V_291 , V_424 , & V_425 ) ;
V_478 = F_239 ( V_424 ) ;
if ( V_478 == 0 )
return 0 ;
F_237 ( V_291 , V_425 , V_476 , V_477 ) ;
F_88 (intel_crtc, plane_id) {
V_480 += V_476 [ V_212 ] ;
V_480 += V_477 [ V_212 ] ;
}
if ( V_480 > V_478 ) {
F_13 ( L_43 ) ;
F_13 ( L_44 , V_480 ,
V_478 ) ;
return - V_234 ;
}
V_478 -= V_480 ;
V_434 -> V_100 [ V_88 ] [ V_104 ] . V_431 = V_424 -> V_432 - V_476 [ V_104 ] ;
V_434 -> V_100 [ V_88 ] [ V_104 ] . V_432 = V_424 -> V_432 ;
V_470 = F_233 ( V_291 ,
V_468 ,
V_469 ) ;
if ( V_470 == 0 )
return 0 ;
V_431 = V_424 -> V_431 ;
F_88 (intel_crtc, plane_id) {
unsigned int V_463 , V_482 ;
T_5 V_483 , V_484 = 0 ;
if ( V_212 == V_104 )
continue;
V_463 = V_468 [ V_212 ] ;
V_483 = V_476 [ V_212 ] ;
V_483 += F_240 ( ( T_4 ) V_478 * V_463 ,
V_470 ) ;
if ( V_463 ) {
V_434 -> V_100 [ V_88 ] [ V_212 ] . V_431 = V_431 ;
V_434 -> V_100 [ V_88 ] [ V_212 ] . V_432 = V_431 + V_483 ;
}
V_431 += V_483 ;
V_482 = V_469 [ V_212 ] ;
V_484 = V_477 [ V_212 ] ;
V_484 += F_240 ( ( T_4 ) V_478 * V_482 ,
V_470 ) ;
if ( V_482 ) {
V_434 -> V_481 [ V_88 ] [ V_212 ] . V_431 = V_431 ;
V_434 -> V_481 [ V_88 ] [ V_212 ] . V_432 = V_431 + V_484 ;
}
V_431 += V_484 ;
}
return 0 ;
}
static T_7 F_241 ( T_3 V_108 , T_6 V_109 ,
T_3 V_53 )
{
T_3 V_485 ;
T_7 V_74 ;
if ( V_53 == 0 )
return V_486 ;
V_485 = V_53 * V_108 * V_109 ;
V_74 = F_242 ( V_485 , 1000 * 512 ) ;
return V_74 ;
}
static T_7 F_243 ( T_3 V_108 ,
T_3 V_487 ,
T_3 V_53 ,
T_7 V_488 )
{
T_3 V_485 ;
T_7 V_74 ;
if ( V_53 == 0 )
return V_486 ;
V_485 = V_53 * V_108 ;
V_485 = F_50 ( V_485 ,
V_487 * 1000 ) ;
V_74 = F_244 ( V_485 , V_488 ) ;
return V_74 ;
}
static T_7
F_245 ( struct V_80 * V_291 )
{
T_3 V_108 ;
T_3 V_215 ;
T_7 V_489 ;
if ( ! V_291 -> V_84 . V_128 )
return F_222 ( 0 ) ;
V_108 = V_291 -> V_108 ;
if ( F_96 ( V_108 == 0 ) )
return F_222 ( 0 ) ;
V_215 = V_291 -> V_84 . V_136 . V_215 ;
V_489 = F_242 ( V_215 * 1000 , V_108 ) ;
return V_489 ;
}
static T_3
F_246 ( const struct V_80 * V_291 ,
const struct V_125 * V_292 )
{
T_4 V_490 ;
T_7 V_491 ;
if ( F_96 ( ! F_54 ( V_291 , V_292 ) ) )
return 0 ;
V_490 = V_291 -> V_108 ;
V_491 = F_221 ( V_291 , V_292 ) ;
return F_232 ( V_490 ,
V_491 ) ;
}
static int F_247 ( const struct V_1 * V_2 ,
struct V_80 * V_291 ,
const struct V_125 * V_455 ,
T_5 V_492 ,
int V_213 ,
T_5 * V_493 ,
T_6 * V_494 ,
bool * V_132 )
{
struct V_127 * V_100 = F_55 ( V_455 -> V_84 . V_100 ) ;
const struct V_454 * V_292 = & V_455 -> V_84 ;
const struct V_138 * V_130 = V_292 -> V_130 ;
T_3 V_53 = V_2 -> V_75 . V_341 [ V_213 ] ;
T_7 V_295 , V_296 ;
T_7 V_488 ;
T_7 V_495 ;
T_3 V_496 ;
T_3 V_497 ;
T_3 V_498 , V_499 ;
T_6 V_109 ;
T_3 V_111 = 0 , V_464 = 0 ;
T_3 V_500 ;
T_7 V_501 ;
T_3 V_502 ;
struct V_229 * V_140 =
F_90 ( V_291 -> V_84 . V_140 ) ;
bool V_503 = F_198 ( V_140 ) ;
bool V_504 , V_505 ;
if ( V_53 == 0 ||
! F_54 ( V_291 , V_455 ) ) {
* V_132 = false ;
return 0 ;
}
V_504 = V_130 -> V_420 == V_473 ||
V_130 -> V_420 == V_474 ;
V_505 = V_130 -> V_420 == V_421 ;
if ( ( F_202 ( V_2 ) || F_203 ( V_2 ) ) &&
V_2 -> V_506 )
V_53 += 4 ;
if ( V_503 && V_505 )
V_53 += 15 ;
if ( V_100 -> V_129 == V_104 ) {
V_111 = V_455 -> V_84 . V_216 ;
V_464 = V_455 -> V_84 . V_447 ;
} else {
V_111 = F_78 ( & V_455 -> V_84 . V_354 ) >> 16 ;
V_464 = F_181 ( & V_455 -> V_84 . V_354 ) >> 16 ;
}
V_109 = V_130 -> V_141 -> V_109 [ 0 ] ;
V_500 = F_246 ( V_291 , V_455 ) ;
if ( F_235 ( V_292 -> V_475 ) ) {
int V_109 = ( V_130 -> V_141 -> V_141 == V_466 ) ?
V_130 -> V_141 -> V_109 [ 1 ] :
V_130 -> V_141 -> V_109 [ 0 ] ;
switch ( V_109 ) {
case 1 :
V_502 = 16 ;
break;
case 2 :
V_502 = 8 ;
break;
case 4 :
V_502 = 4 ;
break;
default:
F_41 ( V_109 ) ;
return - V_234 ;
}
} else {
V_502 = 4 ;
}
if ( V_503 )
V_502 *= 2 ;
V_497 = V_111 * V_109 ;
if ( V_504 ) {
V_496 = F_50 ( V_497 *
V_502 , 512 ) ;
V_488 = F_223 ( V_496 ,
V_502 ) ;
} else if ( V_505 ) {
V_496 = F_50 ( V_497 , 512 ) ;
V_488 = F_222 ( V_496 ) ;
} else {
V_496 = F_50 ( V_497 , 512 ) + 1 ;
V_488 = F_222 ( V_496 ) ;
}
V_295 = F_241 ( V_500 , V_109 , V_53 ) ;
V_296 = F_243 ( V_500 ,
V_291 -> V_84 . V_136 . V_215 ,
V_53 ,
V_488 ) ;
V_501 = F_244 ( V_502 ,
V_488 ) ;
if ( V_504 ) {
V_495 = F_224 ( V_296 , V_501 ) ;
} else {
T_3 V_489 ;
V_489 = F_248 (
F_245 ( V_291 ) ) ;
if ( ( V_109 * V_291 -> V_84 . V_136 . V_215 / 512 < 1 ) &&
( V_497 / 512 < 1 ) )
V_495 = V_296 ;
else if ( V_492 >=
F_248 ( V_488 ) )
V_495 = F_249 ( V_295 , V_296 ) ;
else if ( V_53 >= V_489 )
V_495 = F_249 ( V_295 , V_296 ) ;
else
V_495 = V_295 ;
}
V_498 = F_248 ( V_495 ) + 1 ;
V_499 = F_250 ( V_495 ,
V_488 ) ;
if ( V_213 >= 1 && V_213 <= 7 ) {
if ( V_504 ) {
V_498 += F_248 ( V_501 ) ;
V_499 += V_502 ;
} else {
V_498 ++ ;
}
}
if ( V_498 >= V_492 || V_499 > 31 ) {
* V_132 = false ;
if ( V_213 ) {
return 0 ;
} else {
struct V_453 * V_100 = V_292 -> V_100 ;
F_13 ( L_45 ) ;
F_13 ( L_46 ,
V_100 -> V_84 . V_129 , V_100 -> V_226 ,
V_498 , V_492 , V_499 ) ;
return - V_234 ;
}
}
* V_493 = V_498 ;
* V_494 = V_499 ;
* V_132 = true ;
return 0 ;
}
static int
F_251 ( const struct V_1 * V_2 ,
struct V_436 * V_434 ,
struct V_80 * V_291 ,
const struct V_125 * V_455 ,
struct V_416 * V_75 )
{
struct V_82 * V_82 = F_38 ( V_291 -> V_84 . V_83 ) ;
struct V_453 * V_100 = V_455 -> V_84 . V_100 ;
struct V_127 * V_127 = F_55 ( V_100 ) ;
T_5 V_507 ;
enum V_88 V_88 = V_82 -> V_88 ;
int V_213 , V_124 = F_161 ( V_2 ) ;
int V_74 ;
if ( F_96 ( ! V_455 -> V_84 . V_130 ) )
return - V_234 ;
V_507 = F_239 ( & V_434 -> V_100 [ V_88 ] [ V_127 -> V_129 ] ) ;
for ( V_213 = 0 ; V_213 <= V_124 ; V_213 ++ ) {
struct V_508 * V_309 = & V_75 -> V_75 [ V_213 ] ;
V_74 = F_247 ( V_2 ,
V_291 ,
V_455 ,
V_507 ,
V_213 ,
& V_309 -> V_509 ,
& V_309 -> V_510 ,
& V_309 -> V_419 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static T_3
F_252 ( struct V_80 * V_291 )
{
struct V_346 * V_140 = V_291 -> V_84 . V_140 ;
struct V_1 * V_2 = F_39 ( V_140 -> V_85 ) ;
T_7 V_489 ;
T_3 V_511 ;
V_489 = F_245 ( V_291 ) ;
if ( F_253 ( V_489 ) )
return 0 ;
V_511 = F_248 ( F_244 ( 8 ,
V_489 ) ) ;
if ( F_200 ( V_2 ) && V_2 -> V_506 )
V_511 = F_50 ( V_511 , 2 ) ;
return V_511 ;
}
static void F_254 ( struct V_80 * V_291 ,
struct V_508 * V_512 )
{
if ( ! V_291 -> V_84 . V_128 )
return;
V_512 -> V_419 = false ;
}
static int F_255 ( struct V_80 * V_291 ,
struct V_436 * V_434 ,
struct V_513 * V_343 )
{
struct V_235 * V_85 = V_291 -> V_84 . V_83 -> V_85 ;
struct V_452 * V_81 = & V_291 -> V_84 ;
const struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_453 * V_100 ;
const struct V_454 * V_292 ;
struct V_416 * V_75 ;
int V_74 ;
memset ( V_343 -> V_418 , 0 , sizeof( V_343 -> V_418 ) ) ;
F_228 (plane, pstate, crtc_state) {
const struct V_125 * V_455 =
F_94 ( V_292 ) ;
enum V_212 V_212 = F_55 ( V_100 ) -> V_129 ;
V_75 = & V_343 -> V_418 [ V_212 ] ;
V_74 = F_251 ( V_2 , V_434 , V_291 ,
V_455 , V_75 ) ;
if ( V_74 )
return V_74 ;
F_254 ( V_291 , & V_75 -> V_512 ) ;
}
V_343 -> V_319 = F_252 ( V_291 ) ;
return 0 ;
}
static void F_256 ( struct V_1 * V_2 ,
T_8 V_134 ,
const struct V_423 * V_435 )
{
if ( V_435 -> V_432 )
F_2 ( V_134 , ( V_435 -> V_432 - 1 ) << 16 | V_435 -> V_431 ) ;
else
F_2 ( V_134 , 0 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
T_8 V_134 ,
const struct V_508 * V_213 )
{
T_3 V_21 = 0 ;
if ( V_213 -> V_419 ) {
V_21 |= V_514 ;
V_21 |= V_213 -> V_509 ;
V_21 |= V_213 -> V_510 << V_515 ;
}
F_2 ( V_134 , V_21 ) ;
}
static void F_258 ( struct V_82 * V_82 ,
const struct V_416 * V_75 ,
const struct V_436 * V_434 ,
enum V_212 V_212 )
{
struct V_426 * V_83 = & V_82 -> V_84 ;
struct V_235 * V_85 = V_83 -> V_85 ;
struct V_1 * V_2 = F_39 ( V_85 ) ;
int V_213 , V_124 = F_161 ( V_2 ) ;
enum V_88 V_88 = V_82 -> V_88 ;
for ( V_213 = 0 ; V_213 <= V_124 ; V_213 ++ ) {
F_257 ( V_2 , F_259 ( V_88 , V_212 , V_213 ) ,
& V_75 -> V_75 [ V_213 ] ) ;
}
F_257 ( V_2 , F_260 ( V_88 , V_212 ) ,
& V_75 -> V_512 ) ;
F_256 ( V_2 , F_218 ( V_88 , V_212 ) ,
& V_434 -> V_100 [ V_88 ] [ V_212 ] ) ;
F_256 ( V_2 , F_261 ( V_88 , V_212 ) ,
& V_434 -> V_481 [ V_88 ] [ V_212 ] ) ;
}
static void F_262 ( struct V_82 * V_82 ,
const struct V_416 * V_75 ,
const struct V_436 * V_434 )
{
struct V_426 * V_83 = & V_82 -> V_84 ;
struct V_235 * V_85 = V_83 -> V_85 ;
struct V_1 * V_2 = F_39 ( V_85 ) ;
int V_213 , V_124 = F_161 ( V_2 ) ;
enum V_88 V_88 = V_82 -> V_88 ;
for ( V_213 = 0 ; V_213 <= V_124 ; V_213 ++ ) {
F_257 ( V_2 , F_263 ( V_88 , V_213 ) ,
& V_75 -> V_75 [ V_213 ] ) ;
}
F_257 ( V_2 , F_264 ( V_88 ) , & V_75 -> V_512 ) ;
F_256 ( V_2 , F_219 ( V_88 ) ,
& V_434 -> V_100 [ V_88 ] [ V_104 ] ) ;
}
bool F_265 ( const struct V_508 * V_516 ,
const struct V_508 * V_517 )
{
if ( V_516 -> V_419 != V_517 -> V_419 )
return false ;
if ( ! V_516 -> V_419 )
return true ;
return ( V_516 -> V_510 == V_517 -> V_510 &&
V_516 -> V_509 == V_517 -> V_509 ) ;
}
static inline bool F_266 ( const struct V_423 * V_357 ,
const struct V_423 * V_358 )
{
return V_357 -> V_431 < V_358 -> V_432 && V_358 -> V_431 < V_357 -> V_432 ;
}
bool F_267 ( const struct V_423 * * V_115 ,
const struct V_423 * V_434 ,
int V_518 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_519 ; V_54 ++ )
if ( V_54 != V_518 && V_115 [ V_54 ] &&
F_266 ( V_434 , V_115 [ V_54 ] ) )
return true ;
return false ;
}
static int F_268 ( struct V_452 * V_291 ,
const struct V_513 * V_520 ,
struct V_513 * V_343 ,
struct V_436 * V_434 ,
bool * V_340 )
{
struct V_80 * V_467 = F_114 ( V_291 ) ;
int V_74 ;
V_74 = F_255 ( V_467 , V_434 , V_343 ) ;
if ( V_74 )
return V_74 ;
if ( ! memcmp ( V_520 , V_343 , sizeof( * V_343 ) ) )
* V_340 = false ;
else
* V_340 = true ;
return 0 ;
}
static T_3
F_269 ( struct V_346 * V_140 )
{
struct V_426 * V_83 ;
struct V_452 * V_291 ;
T_3 V_54 , V_74 = 0 ;
F_270 (state, crtc, cstate, i)
V_74 |= F_212 ( V_83 ) ;
return V_74 ;
}
static int
F_271 ( struct V_80 * V_291 )
{
struct V_346 * V_140 = V_291 -> V_84 . V_140 ;
struct V_235 * V_85 = V_140 -> V_85 ;
struct V_426 * V_83 = V_291 -> V_84 . V_83 ;
struct V_82 * V_82 = F_38 ( V_83 ) ;
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_229 * V_318 = F_90 ( V_140 ) ;
struct V_436 * V_521 = & V_318 -> V_522 . V_434 ;
struct V_436 * V_523 = & V_2 -> V_75 . V_524 . V_434 ;
struct V_454 * V_126 ;
struct V_453 * V_100 ;
enum V_88 V_88 = V_82 -> V_88 ;
F_96 ( ! F_272 ( V_140 , V_83 ) ) ;
F_273 (plane, dev, cstate->base.plane_mask) {
enum V_212 V_212 = F_55 ( V_100 ) -> V_129 ;
if ( F_274 ( & V_523 -> V_100 [ V_88 ] [ V_212 ] ,
& V_521 -> V_100 [ V_88 ] [ V_212 ] ) &&
F_274 ( & V_523 -> V_481 [ V_88 ] [ V_212 ] ,
& V_521 -> V_481 [ V_88 ] [ V_212 ] ) )
continue;
V_126 = F_275 ( V_140 , V_100 ) ;
if ( F_276 ( V_126 ) )
return F_277 ( V_126 ) ;
}
return 0 ;
}
static int
F_278 ( struct V_346 * V_140 )
{
struct V_235 * V_85 = V_140 -> V_85 ;
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_229 * V_318 = F_90 ( V_140 ) ;
struct V_82 * V_82 ;
struct V_436 * V_434 = & V_318 -> V_522 . V_434 ;
T_3 V_525 = F_269 ( V_140 ) ;
int V_74 ;
if ( V_2 -> V_75 . V_526 ) {
V_74 = F_279 ( & V_85 -> V_527 . V_528 ,
V_140 -> V_529 ) ;
if ( V_74 )
return V_74 ;
V_318 -> V_433 = ~ 0 ;
if ( ! V_318 -> V_530 )
V_318 -> V_413 = V_2 -> V_413 ;
}
if ( V_318 -> V_433 ) {
V_525 = ~ 0 ;
V_318 -> V_522 . V_531 = ~ 0 ;
}
memcpy ( V_434 , & V_2 -> V_75 . V_524 . V_434 , sizeof( * V_434 ) ) ;
F_280 (dev, intel_crtc, realloc_pipes) {
struct V_80 * V_291 ;
V_291 = F_281 ( V_140 , V_82 ) ;
if ( F_276 ( V_291 ) )
return F_277 ( V_291 ) ;
V_74 = F_238 ( V_291 , V_434 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_271 ( V_291 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static void
F_282 ( struct V_532 * V_217 ,
struct V_532 * V_354 ,
enum V_88 V_88 )
{
memcpy ( V_217 -> V_434 . V_481 [ V_88 ] , V_354 -> V_434 . V_481 [ V_88 ] ,
sizeof( V_217 -> V_434 . V_481 [ V_88 ] ) ) ;
memcpy ( V_217 -> V_434 . V_100 [ V_88 ] , V_354 -> V_434 . V_100 [ V_88 ] ,
sizeof( V_217 -> V_434 . V_100 [ V_88 ] ) ) ;
}
static void
F_283 ( const struct V_346 * V_140 )
{
const struct V_235 * V_85 = V_140 -> V_85 ;
const struct V_1 * V_2 = F_39 ( V_85 ) ;
const struct V_229 * V_318 =
F_90 ( V_140 ) ;
const struct V_426 * V_83 ;
const struct V_452 * V_291 ;
const struct V_127 * V_127 ;
const struct V_436 * V_533 = & V_2 -> V_75 . V_524 . V_434 ;
const struct V_436 * V_521 = & V_318 -> V_522 . V_434 ;
int V_54 ;
F_270 (state, crtc, cstate, i) {
const struct V_82 * V_82 = F_38 ( V_83 ) ;
enum V_88 V_88 = V_82 -> V_88 ;
F_179 (dev, intel_crtc, intel_plane) {
enum V_212 V_212 = V_127 -> V_129 ;
const struct V_423 * V_121 , * V_122 ;
V_121 = & V_533 -> V_100 [ V_88 ] [ V_212 ] ;
V_122 = & V_521 -> V_100 [ V_88 ] [ V_212 ] ;
if ( F_274 ( V_121 , V_122 ) )
continue;
F_284 ( L_47 ,
V_127 -> V_84 . V_84 . V_129 ,
V_127 -> V_84 . V_226 ,
V_121 -> V_431 , V_121 -> V_432 ,
V_122 -> V_431 , V_122 -> V_432 ) ;
}
}
}
static int
F_285 ( struct V_346 * V_140 )
{
struct V_426 * V_83 ;
struct V_452 * V_291 ;
struct V_229 * V_318 = F_90 ( V_140 ) ;
struct V_532 * V_368 = & V_318 -> V_522 ;
struct V_235 * V_85 = V_140 -> V_85 ;
struct V_513 * V_343 ;
bool V_340 = false ;
int V_74 , V_54 ;
if ( F_39 ( V_85 ) -> V_75 . V_526 )
V_340 = true ;
F_270 (state, crtc, cstate, i)
V_340 = true ;
if ( ! V_340 )
return 0 ;
V_368 -> V_531 = 0 ;
V_74 = F_278 ( V_140 ) ;
if ( V_74 )
return V_74 ;
F_270 (state, crtc, cstate, i) {
struct V_80 * V_467 =
F_114 ( V_291 ) ;
const struct V_513 * V_520 =
& F_114 ( V_83 -> V_140 ) -> V_75 . V_417 . V_230 ;
V_343 = & V_467 -> V_75 . V_417 . V_230 ;
V_74 = F_268 ( V_291 , V_520 , V_343 ,
& V_368 -> V_434 , & V_340 ) ;
if ( V_74 )
return V_74 ;
if ( V_340 )
V_368 -> V_531 |= F_212 ( V_83 ) ;
if ( ( V_368 -> V_531 & F_212 ( V_83 ) ) == 0 )
continue;
V_467 -> V_534 = true ;
}
F_283 ( V_140 ) ;
return 0 ;
}
static void F_286 ( struct V_229 * V_140 ,
struct V_80 * V_291 )
{
struct V_82 * V_83 = F_38 ( V_291 -> V_84 . V_83 ) ;
struct V_1 * V_2 = F_39 ( V_140 -> V_84 . V_85 ) ;
struct V_513 * V_343 = & V_291 -> V_75 . V_417 . V_230 ;
const struct V_436 * V_434 = & V_140 -> V_522 . V_434 ;
enum V_88 V_88 = V_83 -> V_88 ;
enum V_212 V_212 ;
if ( ! ( V_140 -> V_522 . V_531 & F_212 ( & V_83 -> V_84 ) ) )
return;
F_2 ( F_196 ( V_88 ) , V_343 -> V_319 ) ;
F_88 (crtc, plane_id) {
if ( V_212 != V_104 )
F_258 ( V_83 , & V_343 -> V_418 [ V_212 ] ,
V_434 , V_212 ) ;
else
F_262 ( V_83 , & V_343 -> V_418 [ V_212 ] ,
V_434 ) ;
}
}
static void F_287 ( struct V_229 * V_140 ,
struct V_80 * V_291 )
{
struct V_82 * V_82 = F_38 ( V_291 -> V_84 . V_83 ) ;
struct V_235 * V_85 = V_82 -> V_84 . V_85 ;
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_532 * V_368 = & V_140 -> V_522 ;
struct V_532 * V_535 = & V_2 -> V_75 . V_524 ;
enum V_88 V_88 = V_82 -> V_88 ;
if ( ( V_368 -> V_531 & F_212 ( & V_82 -> V_84 ) ) == 0 )
return;
F_15 ( & V_2 -> V_75 . V_76 ) ;
if ( V_291 -> V_84 . V_536 )
F_286 ( V_140 , V_291 ) ;
F_282 ( V_535 , V_368 , V_88 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_288 ( struct V_235 * V_85 ,
struct V_298 * V_137 )
{
struct V_82 * V_83 ;
F_57 (dev, crtc) {
const struct V_342 * V_75 = & V_83 -> V_75 . V_128 . V_348 ;
if ( ! V_75 -> V_353 )
continue;
V_137 -> V_301 |= V_75 -> V_301 ;
V_137 -> V_344 |= V_75 -> V_344 ;
V_137 -> V_302 ++ ;
}
}
static void F_289 ( struct V_1 * V_2 )
{
struct V_235 * V_85 = & V_2 -> V_537 ;
struct V_342 V_538 = {} , V_539 = {} , * V_540 ;
struct V_304 F_63 ;
struct V_298 V_137 = {} ;
struct V_367 V_368 = {} ;
enum V_299 V_366 ;
F_288 ( V_85 , & V_137 ) ;
F_151 ( V_85 , 1 , & V_137 , V_345 , & F_63 ) ;
F_184 ( V_85 , & V_137 , & F_63 , & V_538 ) ;
if ( F_145 ( V_2 ) >= 7 &&
V_137 . V_302 == 1 && V_137 . V_301 ) {
F_151 ( V_85 , 1 , & V_137 , V_303 , & F_63 ) ;
F_184 ( V_85 , & V_137 , & F_63 , & V_539 ) ;
V_540 = F_189 ( V_85 , & V_538 , & V_539 ) ;
} else {
V_540 = & V_538 ;
}
V_366 = ( V_540 == & V_538 ) ?
V_345 : V_303 ;
F_188 ( V_85 , V_540 , V_366 , & V_368 ) ;
F_195 ( V_2 , & V_368 ) ;
}
static void F_290 ( struct V_229 * V_140 ,
struct V_80 * V_291 )
{
struct V_1 * V_2 = F_39 ( V_291 -> V_84 . V_83 -> V_85 ) ;
struct V_82 * V_82 = F_38 ( V_291 -> V_84 . V_83 ) ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
V_82 -> V_75 . V_128 . V_348 = V_291 -> V_75 . V_348 . V_236 ;
F_289 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_291 ( struct V_229 * V_140 ,
struct V_80 * V_291 )
{
struct V_1 * V_2 = F_39 ( V_291 -> V_84 . V_83 -> V_85 ) ;
struct V_82 * V_82 = F_38 ( V_291 -> V_84 . V_83 ) ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
if ( V_291 -> V_75 . V_238 ) {
V_82 -> V_75 . V_128 . V_348 = V_291 -> V_75 . V_348 . V_230 ;
F_289 ( V_2 ) ;
}
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
static inline void F_292 ( T_3 V_21 ,
struct V_508 * V_213 )
{
V_213 -> V_419 = V_21 & V_514 ;
V_213 -> V_509 = V_21 & V_541 ;
V_213 -> V_510 = ( V_21 >> V_515 ) &
V_542 ;
}
void F_293 ( struct V_426 * V_83 ,
struct V_513 * V_225 )
{
struct V_1 * V_2 = F_39 ( V_83 -> V_85 ) ;
struct V_82 * V_82 = F_38 ( V_83 ) ;
enum V_88 V_88 = V_82 -> V_88 ;
int V_213 , V_124 ;
enum V_212 V_212 ;
T_3 V_21 ;
V_124 = F_161 ( V_2 ) ;
F_88 (intel_crtc, plane_id) {
struct V_416 * V_75 = & V_225 -> V_418 [ V_212 ] ;
for ( V_213 = 0 ; V_213 <= V_124 ; V_213 ++ ) {
if ( V_212 != V_104 )
V_21 = F_3 ( F_259 ( V_88 , V_212 , V_213 ) ) ;
else
V_21 = F_3 ( F_263 ( V_88 , V_213 ) ) ;
F_292 ( V_21 , & V_75 -> V_75 [ V_213 ] ) ;
}
if ( V_212 != V_104 )
V_21 = F_3 ( F_260 ( V_88 , V_212 ) ) ;
else
V_21 = F_3 ( F_264 ( V_88 ) ) ;
F_292 ( V_21 , & V_75 -> V_512 ) ;
}
if ( ! V_82 -> V_128 )
return;
V_225 -> V_319 = F_3 ( F_196 ( V_88 ) ) ;
}
void F_294 ( struct V_235 * V_85 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_532 * V_390 = & V_2 -> V_75 . V_524 ;
struct V_436 * V_434 = & V_2 -> V_75 . V_524 . V_434 ;
struct V_426 * V_83 ;
struct V_82 * V_82 ;
struct V_80 * V_291 ;
F_215 ( V_2 , V_434 ) ;
F_295 (crtc, &dev->mode_config.crtc_list, head) {
V_82 = F_38 ( V_83 ) ;
V_291 = F_114 ( V_83 -> V_140 ) ;
F_293 ( V_83 , & V_291 -> V_75 . V_417 . V_230 ) ;
if ( V_82 -> V_128 )
V_390 -> V_531 |= F_212 ( V_83 ) ;
}
if ( V_2 -> V_413 ) {
V_2 -> V_75 . V_526 = true ;
} else {
memset ( V_434 , 0 , sizeof( * V_434 ) ) ;
}
}
static void F_296 ( struct V_426 * V_83 )
{
struct V_235 * V_85 = V_83 -> V_85 ;
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_367 * V_390 = & V_2 -> V_75 . V_390 ;
struct V_82 * V_82 = F_38 ( V_83 ) ;
struct V_80 * V_291 = F_114 ( V_83 -> V_140 ) ;
struct V_342 * V_128 = & V_291 -> V_75 . V_348 . V_230 ;
enum V_88 V_88 = V_82 -> V_88 ;
static const T_8 V_543 [] = {
[ V_94 ] = V_394 ,
[ V_97 ] = V_395 ,
[ V_98 ] = V_396 ,
} ;
V_390 -> V_379 [ V_88 ] = F_3 ( V_543 [ V_88 ] ) ;
if ( F_163 ( V_2 ) || F_164 ( V_2 ) )
V_390 -> V_378 [ V_88 ] = F_3 ( F_196 ( V_88 ) ) ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
V_128 -> V_353 = V_82 -> V_128 ;
if ( V_128 -> V_353 ) {
T_1 V_26 = V_390 -> V_379 [ V_88 ] ;
V_128 -> V_75 [ 0 ] . V_56 = true ;
V_128 -> V_75 [ 0 ] . V_289 = ( V_26 & V_544 ) >> V_380 ;
V_128 -> V_75 [ 0 ] . V_310 = ( V_26 & V_545 ) >> V_381 ;
V_128 -> V_75 [ 0 ] . V_311 = V_26 & V_546 ;
V_128 -> V_319 = V_390 -> V_378 [ V_88 ] ;
} else {
int V_213 , V_124 = F_161 ( V_2 ) ;
for ( V_213 = 0 ; V_213 <= V_124 ; V_213 ++ )
V_128 -> V_75 [ V_213 ] . V_56 = true ;
}
V_82 -> V_75 . V_128 . V_348 = * V_128 ;
}
static void F_297 ( struct V_1 * V_2 ,
struct V_161 * V_75 )
{
T_3 V_26 ;
V_26 = F_3 ( V_145 ) ;
V_75 -> V_162 . V_100 = F_298 ( V_26 , V_147 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_104 ] = F_298 ( V_26 , V_163 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_101 ] = F_298 ( V_26 , V_164 ) ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_101 ] = F_298 ( V_26 , V_165 ) ;
V_26 = F_3 ( V_166 ) ;
V_75 -> V_167 = V_26 & V_168 ;
V_75 -> V_162 . V_169 = F_298 ( V_26 , V_170 ) ;
V_75 -> V_171 . V_169 = F_298 ( V_26 , V_172 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] = F_298 ( V_26 , V_173 ) ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_104 ] = F_298 ( V_26 , V_174 ) ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_102 ] = F_298 ( V_26 , V_175 ) ;
V_26 = F_3 ( V_70 ) ;
V_75 -> V_176 = V_26 & V_177 ;
V_75 -> V_162 . V_178 = F_298 ( V_26 , V_151 ) ;
V_75 -> V_171 . V_178 = F_298 ( V_26 , V_159 ) ;
V_75 -> V_171 . V_100 = F_298 ( V_26 , V_155 ) ;
}
static void F_299 ( struct V_1 * V_2 ,
struct V_179 * V_75 )
{
enum V_88 V_88 ;
T_3 V_26 ;
F_65 (dev_priv, pipe) {
V_26 = F_3 ( F_70 ( V_88 ) ) ;
V_75 -> V_180 [ V_88 ] . V_100 [ V_101 ] =
( V_26 >> V_182 ) & ( V_261 | V_547 ) ;
V_75 -> V_180 [ V_88 ] . V_100 [ V_104 ] =
( V_26 >> V_181 ) & ( V_261 | V_547 ) ;
V_75 -> V_180 [ V_88 ] . V_100 [ V_102 ] =
( V_26 >> F_71 ( 0 ) ) & ( V_261 | V_547 ) ;
V_75 -> V_180 [ V_88 ] . V_100 [ V_103 ] =
( V_26 >> F_71 ( 1 ) ) & ( V_261 | V_547 ) ;
}
V_26 = F_3 ( V_145 ) ;
V_75 -> V_162 . V_100 = F_298 ( V_26 , V_147 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_104 ] = F_298 ( V_26 , V_163 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_101 ] = F_300 ( V_26 , V_164 ) ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_101 ] = F_300 ( V_26 , V_165 ) ;
V_26 = F_3 ( V_166 ) ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_103 ] = F_300 ( V_26 , V_173 ) ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_104 ] = F_298 ( V_26 , V_174 ) ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_102 ] = F_300 ( V_26 , V_175 ) ;
V_26 = F_3 ( V_70 ) ;
V_75 -> V_162 . V_178 = F_298 ( V_26 , V_151 ) ;
if ( F_24 ( V_2 ) ) {
V_26 = F_3 ( V_188 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_103 ] = F_300 ( V_26 , V_189 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] = F_300 ( V_26 , V_190 ) ;
V_26 = F_3 ( V_191 ) ;
V_75 -> V_88 [ V_98 ] . V_100 [ V_103 ] = F_300 ( V_26 , V_192 ) ;
V_75 -> V_88 [ V_98 ] . V_100 [ V_102 ] = F_300 ( V_26 , V_193 ) ;
V_26 = F_3 ( V_194 ) ;
V_75 -> V_88 [ V_98 ] . V_100 [ V_101 ] = F_300 ( V_26 , V_195 ) ;
V_75 -> V_88 [ V_98 ] . V_100 [ V_104 ] = F_298 ( V_26 , V_196 ) ;
V_26 = F_3 ( V_183 ) ;
V_75 -> V_162 . V_100 |= F_298 ( V_26 , V_197 ) << 9 ;
V_75 -> V_88 [ V_98 ] . V_100 [ V_103 ] |= F_298 ( V_26 , V_198 ) << 8 ;
V_75 -> V_88 [ V_98 ] . V_100 [ V_102 ] |= F_298 ( V_26 , V_199 ) << 8 ;
V_75 -> V_88 [ V_98 ] . V_100 [ V_101 ] |= F_298 ( V_26 , V_200 ) << 8 ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_103 ] |= F_298 ( V_26 , V_201 ) << 8 ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] |= F_298 ( V_26 , V_202 ) << 8 ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_101 ] |= F_298 ( V_26 , V_203 ) << 8 ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_103 ] |= F_298 ( V_26 , V_204 ) << 8 ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_102 ] |= F_298 ( V_26 , V_205 ) << 8 ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_101 ] |= F_298 ( V_26 , V_206 ) << 8 ;
} else {
V_26 = F_3 ( V_207 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_103 ] = F_300 ( V_26 , V_189 ) ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] = F_300 ( V_26 , V_190 ) ;
V_26 = F_3 ( V_183 ) ;
V_75 -> V_162 . V_100 |= F_298 ( V_26 , V_197 ) << 9 ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_103 ] |= F_298 ( V_26 , V_201 ) << 8 ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_102 ] |= F_298 ( V_26 , V_202 ) << 8 ;
V_75 -> V_88 [ V_97 ] . V_100 [ V_101 ] |= F_298 ( V_26 , V_203 ) << 8 ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_103 ] |= F_298 ( V_26 , V_204 ) << 8 ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_102 ] |= F_298 ( V_26 , V_205 ) << 8 ;
V_75 -> V_88 [ V_94 ] . V_100 [ V_101 ] |= F_298 ( V_26 , V_206 ) << 8 ;
}
}
void F_301 ( struct V_235 * V_85 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_161 * V_75 = & V_2 -> V_75 . V_79 ;
struct V_82 * V_83 ;
F_297 ( V_2 , V_75 ) ;
V_75 -> V_78 = F_3 ( V_68 ) & V_69 ;
F_57 (dev, crtc) {
struct V_80 * V_81 =
F_114 ( V_83 -> V_84 . V_140 ) ;
struct V_227 * V_128 = & V_83 -> V_75 . V_128 . V_79 ;
struct V_222 * V_223 ;
enum V_88 V_88 = V_83 -> V_88 ;
enum V_212 V_212 ;
int V_213 , V_124 ;
V_128 -> V_78 = V_75 -> V_78 ;
V_128 -> V_176 = V_75 -> V_176 ;
V_128 -> V_167 = V_75 -> V_167 ;
V_128 -> V_162 = V_75 -> V_162 ;
V_128 -> V_171 = V_75 -> V_171 ;
F_88 (crtc, plane_id) {
V_128 -> V_75 . V_100 [ V_212 ] =
V_75 -> V_88 [ V_88 ] . V_100 [ V_212 ] ;
}
if ( V_75 -> V_78 && V_75 -> V_176 )
V_124 = V_211 ;
else if ( V_75 -> V_78 )
V_124 = V_210 ;
else
V_124 = V_209 ;
V_213 = V_209 ;
V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
F_88 (crtc, plane_id)
V_223 -> V_100 [ V_212 ] = V_128 -> V_75 . V_100 [ V_212 ] ;
if ( ++ V_213 > V_124 )
goto V_225;
V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
V_223 -> V_100 [ V_101 ] = V_128 -> V_162 . V_100 ;
V_223 -> V_100 [ V_104 ] = V_128 -> V_162 . V_178 ;
V_223 -> V_100 [ V_102 ] = 0 ;
V_223 -> V_169 = V_128 -> V_162 . V_169 ;
if ( ++ V_213 > V_124 )
goto V_225;
V_223 = & V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
V_223 -> V_100 [ V_101 ] = V_128 -> V_171 . V_100 ;
V_223 -> V_100 [ V_104 ] = V_128 -> V_171 . V_178 ;
V_223 -> V_100 [ V_102 ] = 0 ;
V_223 -> V_169 = V_128 -> V_171 . V_169 ;
V_225:
F_88 (crtc, plane_id)
F_81 ( V_81 , V_213 ,
V_212 , V_214 ) ;
F_82 ( V_81 , V_213 , V_214 ) ;
V_81 -> V_75 . V_79 . V_230 = * V_128 ;
V_81 -> V_75 . V_79 . V_236 = * V_128 ;
F_13 ( L_48 ,
F_302 ( V_88 ) ,
V_75 -> V_88 [ V_88 ] . V_100 [ V_101 ] ,
V_75 -> V_88 [ V_88 ] . V_100 [ V_104 ] ,
V_75 -> V_88 [ V_88 ] . V_100 [ V_102 ] ) ;
}
F_13 ( L_49 ,
V_75 -> V_162 . V_100 , V_75 -> V_162 . V_178 , V_75 -> V_162 . V_169 ) ;
F_13 ( L_50 ,
V_75 -> V_171 . V_100 , V_75 -> V_171 . V_178 , V_75 -> V_171 . V_169 ) ;
F_13 ( L_51 ,
F_303 ( V_75 -> V_78 ) , F_303 ( V_75 -> V_176 ) , F_303 ( V_75 -> V_167 ) ) ;
}
void F_304 ( struct V_1 * V_2 )
{
struct V_127 * V_100 ;
struct V_82 * V_83 ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
F_305 (&dev_priv->drm, plane) {
struct V_82 * V_83 =
F_67 ( V_2 , V_100 -> V_88 ) ;
struct V_80 * V_81 =
F_114 ( V_83 -> V_84 . V_140 ) ;
struct V_125 * V_126 =
F_94 ( V_100 -> V_84 . V_140 ) ;
struct V_227 * V_228 = & V_81 -> V_75 . V_79 . V_230 ;
enum V_212 V_212 = V_100 -> V_129 ;
int V_213 ;
if ( V_126 -> V_84 . V_131 )
continue;
for ( V_213 = 0 ; V_213 < 3 ; V_213 ++ ) {
struct V_222 * V_223 =
& V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
V_223 -> V_100 [ V_212 ] = 0 ;
V_228 -> V_75 . V_100 [ V_212 ] = 0 ;
}
if ( V_212 == V_101 ) {
for ( V_213 = 0 ; V_213 < 3 ; V_213 ++ ) {
struct V_222 * V_223 =
& V_81 -> V_75 . V_79 . V_223 [ V_213 ] ;
V_223 -> V_169 = 0 ;
}
V_228 -> V_162 . V_169 = 0 ;
V_228 -> V_171 . V_169 = 0 ;
V_228 -> V_167 = false ;
}
}
F_57 (&dev_priv->drm, crtc) {
struct V_80 * V_81 =
F_114 ( V_83 -> V_84 . V_140 ) ;
V_81 -> V_75 . V_79 . V_236 =
V_81 -> V_75 . V_79 . V_230 ;
V_83 -> V_75 . V_128 . V_79 = V_81 -> V_75 . V_79 . V_230 ;
}
F_98 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
void F_306 ( struct V_235 * V_85 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_179 * V_75 = & V_2 -> V_75 . V_77 ;
struct V_82 * V_83 ;
T_1 V_21 ;
F_299 ( V_2 , V_75 ) ;
V_75 -> V_78 = F_3 ( V_66 ) & V_67 ;
V_75 -> V_213 = V_242 ;
if ( F_24 ( V_2 ) ) {
F_15 ( & V_2 -> V_57 . V_58 ) ;
V_21 = F_16 ( V_2 , V_63 ) ;
if ( V_21 & V_64 )
V_75 -> V_213 = V_243 ;
V_21 = F_16 ( V_2 , V_59 ) ;
V_21 |= V_62 ;
F_17 ( V_2 , V_59 , V_21 ) ;
if ( F_18 ( ( F_16 ( V_2 , V_59 ) &
V_62 ) == 0 , 3 ) ) {
F_13 ( L_52
L_53 ) ;
V_2 -> V_75 . V_124 = V_243 ;
} else {
V_21 = F_16 ( V_2 , V_59 ) ;
if ( ( V_21 & V_60 ) == 0 )
V_75 -> V_213 = V_244 ;
}
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
F_57 (dev, crtc) {
struct V_80 * V_81 =
F_114 ( V_83 -> V_84 . V_140 ) ;
struct V_252 * V_128 = & V_83 -> V_75 . V_128 . V_77 ;
const struct V_86 * V_87 =
& V_81 -> V_75 . V_77 . V_87 ;
enum V_88 V_88 = V_83 -> V_88 ;
enum V_212 V_212 ;
int V_213 ;
F_37 ( V_81 ) ;
V_128 -> V_224 = V_75 -> V_213 + 1 ;
V_128 -> V_78 = V_75 -> V_78 ;
for ( V_213 = 0 ; V_213 < V_128 -> V_224 ; V_213 ++ ) {
struct V_222 * V_223 =
& V_81 -> V_75 . V_77 . V_223 [ V_213 ] ;
V_128 -> V_162 [ V_213 ] . V_100 = V_75 -> V_162 . V_100 ;
V_128 -> V_162 [ V_213 ] . V_178 = V_75 -> V_162 . V_178 ;
F_88 (crtc, plane_id) {
V_128 -> V_75 [ V_213 ] . V_100 [ V_212 ] =
V_75 -> V_88 [ V_88 ] . V_100 [ V_212 ] ;
V_223 -> V_100 [ V_212 ] =
F_107 ( V_128 -> V_75 [ V_213 ] . V_100 [ V_212 ] ,
V_87 -> V_100 [ V_212 ] ) ;
}
}
F_88 (crtc, plane_id)
F_108 ( V_81 , V_213 ,
V_212 , V_214 ) ;
F_106 ( V_83 , V_128 , V_213 ) ;
V_81 -> V_75 . V_77 . V_230 = * V_128 ;
V_81 -> V_75 . V_77 . V_236 = * V_128 ;
F_13 ( L_54 ,
F_302 ( V_88 ) ,
V_75 -> V_88 [ V_88 ] . V_100 [ V_101 ] ,
V_75 -> V_88 [ V_88 ] . V_100 [ V_104 ] ,
V_75 -> V_88 [ V_88 ] . V_100 [ V_102 ] ,
V_75 -> V_88 [ V_88 ] . V_100 [ V_103 ] ) ;
}
F_13 ( L_55 ,
V_75 -> V_162 . V_100 , V_75 -> V_162 . V_178 , V_75 -> V_213 , V_75 -> V_78 ) ;
}
void F_307 ( struct V_1 * V_2 )
{
struct V_127 * V_100 ;
struct V_82 * V_83 ;
F_15 ( & V_2 -> V_75 . V_76 ) ;
F_305 (&dev_priv->drm, plane) {
struct V_82 * V_83 =
F_67 ( V_2 , V_100 -> V_88 ) ;
struct V_80 * V_81 =
F_114 ( V_83 -> V_84 . V_140 ) ;
struct V_125 * V_126 =
F_94 ( V_100 -> V_84 . V_140 ) ;
struct V_252 * V_228 = & V_81 -> V_75 . V_77 . V_230 ;
const struct V_86 * V_87 =
& V_81 -> V_75 . V_77 . V_87 ;
enum V_212 V_212 = V_100 -> V_129 ;
int V_213 ;
if ( V_126 -> V_84 . V_131 )
continue;
for ( V_213 = 0 ; V_213 < V_228 -> V_224 ; V_213 ++ ) {
struct V_222 * V_223 =
& V_81 -> V_75 . V_77 . V_223 [ V_213 ] ;
V_223 -> V_100 [ V_212 ] = 0 ;
V_228 -> V_75 [ V_213 ] . V_100 [ V_212 ] =
F_107 ( V_223 -> V_100 [ V_212 ] ,
V_87 -> V_100 [ V_212 ] ) ;
}
}
F_57 (&dev_priv->drm, crtc) {
struct V_80 * V_81 =
F_114 ( V_83 -> V_84 . V_140 ) ;
V_81 -> V_75 . V_77 . V_236 =
V_81 -> V_75 . V_77 . V_230 ;
V_83 -> V_75 . V_128 . V_77 = V_81 -> V_75 . V_77 . V_230 ;
}
F_127 ( V_2 ) ;
F_20 ( & V_2 -> V_75 . V_76 ) ;
}
void F_308 ( struct V_235 * V_85 )
{
struct V_1 * V_2 = F_39 ( V_85 ) ;
struct V_367 * V_390 = & V_2 -> V_75 . V_390 ;
struct V_426 * V_83 ;
F_309 (dev, crtc)
F_296 ( V_83 ) ;
V_390 -> V_365 [ 0 ] = F_3 ( V_393 ) ;
V_390 -> V_365 [ 1 ] = F_3 ( V_392 ) ;
V_390 -> V_365 [ 2 ] = F_3 ( V_391 ) ;
V_390 -> V_376 [ 0 ] = F_3 ( V_401 ) ;
if ( F_145 ( V_2 ) >= 7 ) {
V_390 -> V_376 [ 1 ] = F_3 ( V_402 ) ;
V_390 -> V_376 [ 2 ] = F_3 ( V_403 ) ;
}
if ( F_163 ( V_2 ) || F_164 ( V_2 ) )
V_390 -> V_366 = ( F_3 ( V_397 ) & V_398 ) ?
V_303 : V_345 ;
else if ( F_169 ( V_2 ) )
V_390 -> V_366 = ( F_3 ( V_399 ) & V_400 ) ?
V_303 : V_345 ;
V_390 -> V_369 =
! ( F_3 ( V_9 ) & V_10 ) ;
}
void F_310 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_39 ( V_83 -> V_84 . V_85 ) ;
if ( V_2 -> V_279 . V_548 )
V_2 -> V_279 . V_548 ( V_83 ) ;
}
bool F_311 ( struct V_1 * V_2 , T_9 V_21 )
{
T_2 V_549 ;
F_312 ( & V_550 ) ;
V_549 = F_9 ( V_551 ) ;
if ( V_549 & V_552 ) {
F_313 ( L_56 ) ;
return false ;
}
V_549 = ( V_553 << V_554 ) |
( V_21 << V_555 ) | V_556 ;
F_314 ( V_551 , V_549 ) ;
F_315 ( V_551 ) ;
V_549 |= V_552 ;
F_314 ( V_551 , V_549 ) ;
return true ;
}
static void F_316 ( struct V_1 * V_2 )
{
T_1 V_557 ;
T_9 V_558 , V_559 , V_560 , V_561 ;
F_317 ( & V_550 ) ;
V_557 = F_3 ( V_562 ) ;
F_314 ( V_563 , F_3 ( V_563 ) | V_564 ) ;
F_314 ( V_565 , F_3 ( V_565 ) | V_566 ) ;
F_2 ( V_567 , 100000 ) ;
F_2 ( V_568 , 100000 ) ;
F_2 ( V_569 , 90000 ) ;
F_2 ( V_570 , 80000 ) ;
F_2 ( V_571 , 1 ) ;
V_558 = ( V_557 & V_572 ) >> V_573 ;
V_559 = ( V_557 & V_574 ) ;
V_560 = ( V_557 & V_575 ) >>
V_576 ;
V_561 = ( F_3 ( F_318 ( V_560 ) ) & V_577 ) >>
V_578 ;
V_2 -> V_46 . V_558 = V_558 ;
V_2 -> V_46 . V_560 = V_560 ;
V_2 -> V_46 . V_579 = V_560 ;
V_2 -> V_46 . V_580 = V_559 ;
V_2 -> V_46 . V_581 = V_560 ;
F_10 ( L_57 ,
V_558 , V_559 , V_560 ) ;
F_2 ( V_582 , V_583 | V_584 ) ;
F_2 ( V_585 , V_561 ) ;
F_25 ( V_585 ) ;
V_557 |= V_586 ;
F_2 ( V_562 , V_557 ) ;
if ( F_319 ( ( F_3 ( V_551 ) & V_552 ) == 0 , 10 ) )
F_19 ( L_58 ) ;
F_320 ( 1 ) ;
F_311 ( V_2 , V_560 ) ;
V_2 -> V_46 . V_587 = F_3 ( V_588 ) +
F_3 ( V_589 ) + F_3 ( V_590 ) ;
V_2 -> V_46 . V_591 = F_321 ( V_592 ) ;
V_2 -> V_46 . V_593 = F_3 ( V_594 ) ;
V_2 -> V_46 . V_595 = F_322 () ;
F_323 ( & V_550 ) ;
}
static void F_324 ( struct V_1 * V_2 )
{
T_2 V_549 ;
F_317 ( & V_550 ) ;
V_549 = F_9 ( V_551 ) ;
F_2 ( V_582 , F_3 ( V_582 ) & ~ V_584 ) ;
F_2 ( V_596 , V_597 ) ;
F_2 ( V_598 , F_3 ( V_598 ) & ~ V_599 ) ;
F_2 ( V_600 , V_599 ) ;
F_2 ( V_601 , F_3 ( V_601 ) | V_599 ) ;
F_311 ( V_2 , V_2 -> V_46 . V_560 ) ;
F_320 ( 1 ) ;
V_549 |= V_552 ;
F_2 ( V_551 , V_549 ) ;
F_320 ( 1 ) ;
F_323 ( & V_550 ) ;
}
static T_1 F_325 ( struct V_1 * V_2 , T_9 V_21 )
{
T_1 V_602 ;
if ( F_160 ( V_2 ) ) {
V_602 = ( V_2 -> V_57 . V_603 ) << 23 ;
if ( V_21 <= V_2 -> V_57 . V_604 )
V_602 |= ( V_2 -> V_57 . V_604 ) << 14 ;
} else {
V_602 = V_2 -> V_57 . V_603 << 24 ;
if ( V_21 <= V_2 -> V_57 . V_604 )
V_602 |= V_2 -> V_57 . V_604 << 16 ;
}
return V_602 ;
}
static void F_326 ( struct V_1 * V_2 , T_9 V_21 )
{
int V_605 ;
T_1 V_606 = 0 , V_607 = 0 ;
T_1 V_608 = 0 , V_609 = 0 ;
V_605 = V_2 -> V_57 . V_610 ;
switch ( V_2 -> V_57 . V_610 ) {
case V_611 :
if ( V_21 > V_2 -> V_57 . V_612 + 1 &&
V_21 > V_2 -> V_57 . V_613 )
V_605 = V_614 ;
break;
case V_614 :
if ( V_21 <= V_2 -> V_57 . V_612 &&
V_21 < V_2 -> V_57 . V_613 )
V_605 = V_611 ;
else if ( V_21 >= V_2 -> V_57 . V_615 &&
V_21 > V_2 -> V_57 . V_613 )
V_605 = V_616 ;
break;
case V_616 :
if ( V_21 < ( V_2 -> V_57 . V_617 + V_2 -> V_57 . V_615 ) > > 1 &&
V_21 < V_2 -> V_57 . V_613 )
V_605 = V_614 ;
break;
}
if ( V_21 <= V_2 -> V_57 . V_604 )
V_605 = V_611 ;
if ( V_21 >= V_2 -> V_57 . V_603 )
V_605 = V_616 ;
if ( V_605 == V_2 -> V_57 . V_610 )
return;
switch ( V_605 ) {
case V_611 :
V_608 = 16000 ;
V_606 = 95 ;
V_609 = 32000 ;
V_607 = 85 ;
break;
case V_614 :
V_608 = 13000 ;
V_606 = 90 ;
V_609 = 32000 ;
V_607 = 75 ;
break;
case V_616 :
V_608 = 10000 ;
V_606 = 85 ;
V_609 = 32000 ;
V_607 = 60 ;
break;
}
if ( F_23 ( V_2 ) )
goto V_618;
F_2 ( V_619 ,
F_327 ( V_2 , V_608 ) ) ;
F_2 ( V_620 ,
F_327 ( V_2 ,
V_608 * V_606 / 100 ) ) ;
F_2 ( V_621 ,
F_327 ( V_2 , V_609 ) ) ;
F_2 ( V_622 ,
F_327 ( V_2 ,
V_609 * V_607 / 100 ) ) ;
F_2 ( V_623 ,
V_624 |
V_625 |
V_626 |
V_627 |
V_628 |
V_629 ) ;
V_618:
V_2 -> V_57 . V_610 = V_605 ;
V_2 -> V_57 . V_630 = V_606 ;
V_2 -> V_57 . V_631 = V_607 ;
V_2 -> V_57 . V_632 = 0 ;
}
static T_1 F_328 ( struct V_1 * V_2 , T_9 V_21 )
{
T_1 V_633 = 0 ;
if ( V_21 > V_2 -> V_57 . V_604 )
V_633 |= V_634 | V_635 | V_636 ;
if ( V_21 < V_2 -> V_57 . V_603 )
V_633 |= V_634 | V_637 ;
V_633 &= V_2 -> V_638 ;
return F_329 ( V_2 , ~ V_633 ) ;
}
static int F_330 ( struct V_1 * V_2 , T_9 V_21 )
{
if ( V_21 != V_2 -> V_57 . V_613 ) {
F_326 ( V_2 , V_21 ) ;
if ( F_160 ( V_2 ) )
F_2 ( V_639 ,
F_331 ( V_21 ) ) ;
else if ( F_163 ( V_2 ) || F_164 ( V_2 ) )
F_2 ( V_639 ,
F_332 ( V_21 ) ) ;
else
F_2 ( V_639 ,
F_333 ( V_21 ) |
F_334 ( 0 ) |
V_640 ) ;
}
F_2 ( V_641 , F_325 ( V_2 , V_21 ) ) ;
F_2 ( V_642 , F_328 ( V_2 , V_21 ) ) ;
V_2 -> V_57 . V_613 = V_21 ;
F_335 ( F_336 ( V_2 , V_21 ) ) ;
return 0 ;
}
static int F_337 ( struct V_1 * V_2 , T_9 V_21 )
{
int V_643 ;
if ( F_338 ( F_24 ( V_2 ) && ( V_21 & 1 ) ,
L_59 ) )
V_21 &= ~ 1 ;
F_2 ( V_642 , F_328 ( V_2 , V_21 ) ) ;
if ( V_21 != V_2 -> V_57 . V_613 ) {
V_643 = F_17 ( V_2 , V_644 , V_21 ) ;
if ( V_643 )
return V_643 ;
F_326 ( V_2 , V_21 ) ;
}
V_2 -> V_57 . V_613 = V_21 ;
F_335 ( F_336 ( V_2 , V_21 ) ) ;
return 0 ;
}
static void F_339 ( struct V_1 * V_2 )
{
T_1 V_21 = V_2 -> V_57 . V_645 ;
int V_643 ;
if ( V_2 -> V_57 . V_613 <= V_21 )
return;
F_340 ( V_2 , V_646 ) ;
V_643 = F_337 ( V_2 , V_21 ) ;
F_341 ( V_2 , V_646 ) ;
if ( V_643 )
F_19 ( L_60 ) ;
}
void F_342 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( V_2 -> V_57 . V_132 ) {
T_9 V_647 ;
if ( V_2 -> V_638 & V_634 )
F_343 ( V_2 ) ;
F_2 ( V_642 ,
F_328 ( V_2 , V_2 -> V_57 . V_613 ) ) ;
F_344 ( V_2 ) ;
V_647 = F_63 ( V_2 -> V_57 . V_613 ,
V_2 -> V_57 . V_612 ) ;
if ( F_345 ( V_2 ,
F_346 ( V_647 ,
V_2 -> V_57 . V_604 ,
V_2 -> V_57 . V_603 ) ) )
F_10 ( L_61 ) ;
}
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
void F_347 ( struct V_1 * V_2 )
{
F_348 ( V_2 ) ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( V_2 -> V_57 . V_132 ) {
if ( F_23 ( V_2 ) || F_24 ( V_2 ) )
F_339 ( V_2 ) ;
else
F_330 ( V_2 , V_2 -> V_57 . V_645 ) ;
V_2 -> V_57 . V_632 = 0 ;
F_2 ( V_642 ,
F_329 ( V_2 , ~ 0 ) ) ;
}
F_20 ( & V_2 -> V_57 . V_58 ) ;
F_119 ( & V_2 -> V_57 . V_648 ) ;
while ( ! F_349 ( & V_2 -> V_57 . V_649 ) )
F_350 ( V_2 -> V_57 . V_649 . V_650 ) ;
F_124 ( & V_2 -> V_57 . V_648 ) ;
}
void F_351 ( struct V_1 * V_2 ,
struct V_651 * V_57 ,
unsigned long V_652 )
{
if ( ! ( V_2 -> V_653 . V_654 &&
V_2 -> V_57 . V_132 &&
V_2 -> V_57 . V_613 < V_2 -> V_57 . V_655 ) )
return;
if ( V_57 && F_352 ( V_592 , V_652 + V_656 ) )
V_57 = NULL ;
F_119 ( & V_2 -> V_57 . V_648 ) ;
if ( V_57 == NULL || F_349 ( & V_57 -> V_657 ) ) {
F_317 ( & V_2 -> V_658 ) ;
if ( V_2 -> V_57 . V_659 ) {
V_2 -> V_57 . V_660 = true ;
F_353 ( & V_2 -> V_57 . V_661 ) ;
}
F_323 ( & V_2 -> V_658 ) ;
if ( V_57 != NULL ) {
F_354 ( & V_57 -> V_657 , & V_2 -> V_57 . V_649 ) ;
V_57 -> V_662 ++ ;
} else
V_2 -> V_57 . V_662 ++ ;
}
F_124 ( & V_2 -> V_57 . V_648 ) ;
}
int F_345 ( struct V_1 * V_2 , T_9 V_21 )
{
int V_643 ;
F_312 ( & V_2 -> V_57 . V_58 ) ;
F_355 ( V_21 > V_2 -> V_57 . V_663 ) ;
F_355 ( V_21 < V_2 -> V_57 . V_664 ) ;
if ( ! V_2 -> V_57 . V_132 ) {
V_2 -> V_57 . V_613 = V_21 ;
return 0 ;
}
if ( F_23 ( V_2 ) || F_24 ( V_2 ) )
V_643 = F_337 ( V_2 , V_21 ) ;
else
V_643 = F_330 ( V_2 , V_21 ) ;
return V_643 ;
}
static void F_356 ( struct V_1 * V_2 )
{
F_2 ( V_665 , 0 ) ;
F_2 ( V_666 , 0 ) ;
}
static void F_357 ( struct V_1 * V_2 )
{
F_2 ( V_623 , 0 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
F_2 ( V_665 , 0 ) ;
F_2 ( V_639 , 1 << 31 ) ;
F_2 ( V_623 , 0 ) ;
}
static void F_359 ( struct V_1 * V_2 )
{
F_2 ( V_665 , 0 ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
F_340 ( V_2 , V_667 ) ;
F_2 ( V_665 , 0 ) ;
F_341 ( V_2 , V_667 ) ;
}
static void F_361 ( struct V_1 * V_2 , T_1 V_668 )
{
if ( F_23 ( V_2 ) || F_24 ( V_2 ) ) {
if ( V_668 & ( V_669 | F_362 ( 1 ) ) )
V_668 = V_670 ;
else
V_668 = 0 ;
}
if ( F_363 ( V_2 ) )
F_10 ( L_62
L_63 ,
F_364 ( V_668 & V_670 ) ,
F_364 ( V_668 & V_671 ) ,
F_364 ( V_668 & V_672 ) ) ;
else
F_10 ( L_64 ,
F_364 ( V_668 & V_670 ) ) ;
}
static bool F_365 ( struct V_1 * V_2 )
{
struct V_673 * V_674 = & V_2 -> V_674 ;
bool V_675 = true ;
unsigned long V_676 ;
T_1 V_677 ;
int V_678 ;
V_677 = F_3 ( V_665 ) ;
V_678 = ( F_3 ( V_679 ) & V_680 ) >>
V_681 ;
F_10 ( L_65
L_66 ,
F_364 ( V_677 & V_682 ) ,
F_364 ( V_677 & V_670 ) ,
V_678 ) ;
if ( ! ( F_3 ( V_683 ) & V_684 ) ) {
F_10 ( L_67 ) ;
V_675 = false ;
}
V_676 = F_3 ( V_685 ) & V_686 ;
if ( ! ( ( V_676 >= V_674 -> V_687 ) &&
( V_676 + V_688 <= V_674 -> V_687 +
V_674 -> V_689 ) ) ) {
F_10 ( L_68 ) ;
V_675 = false ;
}
if ( ! ( ( ( F_3 ( V_690 ) & V_691 ) > 1 ) &&
( ( F_3 ( V_692 ) & V_691 ) > 1 ) &&
( ( F_3 ( V_693 ) & V_691 ) > 1 ) &&
( ( F_3 ( V_694 ) & V_691 ) > 1 ) ) ) {
F_10 ( L_69 ) ;
V_675 = false ;
}
if ( ! F_3 ( V_695 ) ||
! F_3 ( V_696 ) ||
! F_3 ( V_697 ) ) {
F_10 ( L_70 ) ;
V_675 = false ;
}
if ( ! F_3 ( V_698 ) ) {
F_10 ( L_71 ) ;
V_675 = false ;
}
if ( ! F_3 ( V_699 ) ) {
F_10 ( L_72 ) ;
V_675 = false ;
}
return V_675 ;
}
int F_366 ( struct V_1 * V_2 , int V_675 )
{
if ( F_115 ( V_2 ) -> V_700 < 6 )
return 0 ;
if ( ! V_675 )
return 0 ;
if ( F_367 ( V_2 ) && ! F_365 ( V_2 ) ) {
F_368 ( L_73 ) ;
return 0 ;
}
if ( V_675 >= 0 ) {
int V_633 ;
if ( F_363 ( V_2 ) )
V_633 = V_701 | V_702 |
V_703 ;
else
V_633 = V_701 ;
if ( ( V_675 & V_633 ) != V_675 )
F_10 ( L_74
L_75 ,
V_675 & V_633 , V_675 , V_633 ) ;
return V_675 & V_633 ;
}
if ( F_169 ( V_2 ) )
return ( V_701 | V_702 ) ;
return V_701 ;
}
static void F_369 ( struct V_1 * V_2 )
{
if ( F_367 ( V_2 ) ) {
T_1 V_704 = F_3 ( V_705 ) ;
V_2 -> V_57 . V_615 = ( V_704 >> 16 ) & 0xff ;
V_2 -> V_57 . V_617 = ( V_704 >> 8 ) & 0xff ;
V_2 -> V_57 . V_664 = ( V_704 >> 0 ) & 0xff ;
} else {
T_1 V_704 = F_3 ( V_706 ) ;
V_2 -> V_57 . V_615 = ( V_704 >> 0 ) & 0xff ;
V_2 -> V_57 . V_617 = ( V_704 >> 8 ) & 0xff ;
V_2 -> V_57 . V_664 = ( V_704 >> 16 ) & 0xff ;
}
V_2 -> V_57 . V_663 = V_2 -> V_57 . V_615 ;
V_2 -> V_57 . V_612 = V_2 -> V_57 . V_617 ;
if ( F_163 ( V_2 ) || F_164 ( V_2 ) ||
F_199 ( V_2 ) ) {
T_1 V_707 = 0 ;
if ( F_162 ( V_2 ,
V_708 ,
& V_707 ) == 0 )
V_2 -> V_57 . V_612 =
F_370 ( T_9 ,
( ( V_707 >> 8 ) & 0xff ) ,
V_2 -> V_57 . V_664 ,
V_2 -> V_57 . V_663 ) ;
}
if ( F_199 ( V_2 ) ) {
V_2 -> V_57 . V_615 *= V_709 ;
V_2 -> V_57 . V_617 *= V_709 ;
V_2 -> V_57 . V_664 *= V_709 ;
V_2 -> V_57 . V_663 *= V_709 ;
V_2 -> V_57 . V_612 *= V_709 ;
}
}
static void F_371 ( struct V_1 * V_2 ,
int (* F_372)( struct V_1 * , T_9 ) )
{
T_9 V_647 = V_2 -> V_57 . V_613 ;
V_2 -> V_57 . V_610 = - 1 ;
V_2 -> V_57 . V_613 = - 1 ;
if ( F_372 ( V_2 , V_647 ) )
F_19 ( L_76 ) ;
}
static void F_373 ( struct V_1 * V_2 )
{
F_340 ( V_2 , V_667 ) ;
F_2 ( V_710 ,
F_331 ( V_2 -> V_57 . V_617 ) ) ;
F_2 ( V_711 ,
F_327 ( V_2 , 1000000 ) ) ;
F_2 ( V_712 , 0xa ) ;
F_371 ( V_2 , F_330 ) ;
F_341 ( V_2 , V_667 ) ;
}
static void F_374 ( struct V_1 * V_2 )
{
struct V_713 * V_714 ;
enum V_715 V_129 ;
T_3 V_716 = 0 ;
F_2 ( V_679 , 0 ) ;
F_340 ( V_2 , V_667 ) ;
F_2 ( V_665 , 0 ) ;
if ( F_204 ( V_2 ) )
F_2 ( V_717 , 108 << 16 ) ;
else
F_2 ( V_717 , 54 << 16 ) ;
F_2 ( V_718 , 125000 ) ;
F_2 ( V_719 , 25 ) ;
F_375 (engine, dev_priv, id)
F_2 ( F_376 ( V_714 -> V_720 ) , 10 ) ;
if ( F_377 ( V_2 ) )
F_2 ( V_721 , 0xA ) ;
F_2 ( V_722 , 0 ) ;
F_2 ( V_723 , 25 ) ;
F_2 ( V_724 , 25 ) ;
if ( F_378 () & V_701 )
V_716 = V_670 ;
F_368 ( L_77 , F_364 ( V_716 & V_670 ) ) ;
F_2 ( V_725 , 37500 ) ;
F_2 ( V_665 ,
V_682 | F_362 ( 1 ) | V_716 ) ;
if ( F_379 ( V_2 ) )
F_2 ( V_666 , 0 ) ;
else
F_2 ( V_666 , ( V_716 & V_670 ) ?
( V_726 | V_727 ) : 0 ) ;
F_341 ( V_2 , V_667 ) ;
}
static void F_380 ( struct V_1 * V_2 )
{
struct V_713 * V_714 ;
enum V_715 V_129 ;
T_3 V_716 = 0 ;
F_2 ( V_679 , 0 ) ;
F_340 ( V_2 , V_667 ) ;
F_2 ( V_665 , 0 ) ;
F_2 ( V_717 , 40 << 16 ) ;
F_2 ( V_718 , 125000 ) ;
F_2 ( V_719 , 25 ) ;
F_375 (engine, dev_priv, id)
F_2 ( F_376 ( V_714 -> V_720 ) , 10 ) ;
F_2 ( V_722 , 0 ) ;
if ( F_164 ( V_2 ) )
F_2 ( V_725 , 625 ) ;
else
F_2 ( V_725 , 50000 ) ;
if ( F_378 () & V_701 )
V_716 = V_670 ;
F_361 ( V_2 , V_716 ) ;
if ( F_164 ( V_2 ) )
F_2 ( V_665 , V_682 |
V_669 |
V_716 ) ;
else
F_2 ( V_665 , V_682 |
F_362 ( 1 ) |
V_716 ) ;
F_2 ( V_639 ,
F_332 ( V_2 -> V_57 . V_617 ) ) ;
F_2 ( V_710 ,
F_332 ( V_2 -> V_57 . V_617 ) ) ;
F_2 ( V_711 , 100000000 / 128 ) ;
F_2 ( V_641 ,
V_2 -> V_57 . V_603 << 24 |
V_2 -> V_57 . V_604 << 16 ) ;
F_2 ( V_620 , 7600000 / 128 ) ;
F_2 ( V_622 , 31300000 / 128 ) ;
F_2 ( V_619 , 66000 ) ;
F_2 ( V_621 , 350000 ) ;
F_2 ( V_712 , 10 ) ;
F_2 ( V_623 ,
V_624 |
V_625 |
V_626 |
V_627 |
V_628 |
V_629 ) ;
F_371 ( V_2 , F_330 ) ;
F_341 ( V_2 , V_667 ) ;
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_713 * V_714 ;
enum V_715 V_129 ;
T_1 V_728 , V_716 = 0 ;
T_1 V_729 ;
int V_730 ;
int V_74 ;
F_96 ( ! F_382 ( & V_2 -> V_57 . V_58 ) ) ;
F_2 ( V_679 , 0 ) ;
V_729 = F_3 ( V_731 ) ;
if ( V_729 ) {
F_19 ( L_78 , V_729 ) ;
F_2 ( V_731 , V_729 ) ;
}
F_340 ( V_2 , V_667 ) ;
F_2 ( V_665 , 0 ) ;
F_2 ( V_732 , 1000 << 16 ) ;
F_2 ( V_717 , 40 << 16 | 30 ) ;
F_2 ( V_733 , 30 ) ;
F_2 ( V_718 , 125000 ) ;
F_2 ( V_719 , 25 ) ;
F_375 (engine, dev_priv, id)
F_2 ( F_376 ( V_714 -> V_720 ) , 10 ) ;
F_2 ( V_722 , 0 ) ;
F_2 ( V_734 , 1000 ) ;
if ( F_169 ( V_2 ) )
F_2 ( V_725 , 125000 ) ;
else
F_2 ( V_725 , 50000 ) ;
F_2 ( V_735 , 150000 ) ;
F_2 ( V_736 , 64000 ) ;
V_730 = F_378 () ;
if ( V_730 & V_701 )
V_716 |= V_670 ;
if ( ! F_163 ( V_2 ) ) {
if ( V_730 & V_702 )
V_716 |= V_671 ;
if ( V_730 & V_703 )
V_716 |= V_672 ;
}
F_361 ( V_2 , V_716 ) ;
F_2 ( V_665 ,
V_716 |
F_362 ( 1 ) |
V_682 ) ;
F_2 ( V_711 , 50000 ) ;
F_2 ( V_712 , 10 ) ;
F_371 ( V_2 , F_330 ) ;
V_728 = 0 ;
V_74 = F_162 ( V_2 , V_737 , & V_728 ) ;
if ( F_175 ( V_2 ) && V_74 ) {
F_10 ( L_79 ) ;
} else if ( F_175 ( V_2 ) && ( F_383 ( V_728 & 0xff ) < 450 ) ) {
F_10 ( L_80 ,
F_383 ( V_728 & 0xff ) , 450 ) ;
V_728 &= 0xffff00 ;
V_728 |= F_384 ( 450 ) ;
V_74 = F_206 ( V_2 , V_738 , V_728 ) ;
if ( V_74 )
F_19 ( L_81 ) ;
}
F_341 ( V_2 , V_667 ) ;
}
static void F_385 ( struct V_1 * V_2 )
{
int V_664 = 15 ;
unsigned int V_739 ;
unsigned int V_740 , V_741 ;
unsigned int V_742 , V_743 ;
int V_744 = 180 ;
struct V_745 * V_746 ;
F_96 ( ! F_382 ( & V_2 -> V_57 . V_58 ) ) ;
V_746 = F_386 ( 0 ) ;
if ( V_746 ) {
V_740 = V_746 -> V_747 . V_663 ;
F_387 ( V_746 ) ;
} else {
V_740 = V_748 ;
}
V_740 /= 1000 ;
V_741 = F_3 ( V_749 ) & 0xf ;
V_741 = F_388 ( V_741 , 8 , 3 ) ;
if ( F_199 ( V_2 ) ) {
V_743 = V_2 -> V_57 . V_664 / V_709 ;
V_742 = V_2 -> V_57 . V_663 / V_709 ;
} else {
V_743 = V_2 -> V_57 . V_664 ;
V_742 = V_2 -> V_57 . V_663 ;
}
for ( V_739 = V_742 ; V_739 >= V_743 ; V_739 -- ) {
int V_750 = V_742 - V_739 ;
unsigned int V_751 = 0 , V_752 = 0 ;
if ( F_199 ( V_2 ) ) {
V_752 = V_739 ;
} else if ( F_115 ( V_2 ) -> V_700 >= 8 ) {
V_752 = F_63 ( V_741 , V_739 ) ;
} else if ( F_163 ( V_2 ) ) {
V_752 = F_388 ( V_739 , 5 , 4 ) ;
V_752 = F_63 ( V_741 , V_752 ) ;
} else {
if ( V_739 < V_664 )
V_751 = 800 ;
else
V_751 = V_740 - ( ( V_750 * V_744 ) / 2 ) ;
V_751 = F_156 ( V_751 , 100 ) ;
}
F_206 ( V_2 ,
V_753 ,
V_751 << V_754 |
V_752 << V_755 |
V_739 ) ;
}
}
static int F_389 ( struct V_1 * V_2 )
{
T_1 V_21 , V_756 ;
V_21 = F_16 ( V_2 , V_757 ) ;
switch ( F_115 ( V_2 ) -> V_758 . V_759 ) {
case 8 :
V_756 = ( V_21 >> V_760 ) ;
break;
case 12 :
V_756 = ( V_21 >> V_761 ) ;
break;
case 16 :
default:
V_756 = ( V_21 >> V_762 ) ;
break;
}
V_756 = ( V_756 & V_763 ) ;
return V_756 ;
}
static int F_390 ( struct V_1 * V_2 )
{
T_1 V_21 , V_764 ;
V_21 = F_16 ( V_2 , V_765 ) ;
V_764 = ( V_21 >> V_766 ) & V_767 ;
return V_764 ;
}
static int F_391 ( struct V_1 * V_2 )
{
T_1 V_21 , V_768 ;
V_21 = F_16 ( V_2 , V_757 ) ;
V_768 = ( V_21 & V_763 ) ;
return V_768 ;
}
static T_1 F_392 ( struct V_1 * V_2 )
{
T_1 V_21 , V_769 ;
V_21 = F_16 ( V_2 , V_770 ) ;
V_769 = ( ( V_21 >> V_771 ) &
V_763 ) ;
return V_769 ;
}
static int F_393 ( struct V_1 * V_2 )
{
T_1 V_21 , V_768 ;
V_21 = F_394 ( V_2 , V_772 ) ;
V_768 = ( V_21 & V_773 ) >> V_774 ;
return V_768 ;
}
static int F_395 ( struct V_1 * V_2 )
{
T_1 V_21 , V_756 ;
V_21 = F_394 ( V_2 , V_772 ) ;
V_756 = ( V_21 & V_775 ) >> V_776 ;
V_756 = F_80 ( T_1 , V_756 , 0xea ) ;
return V_756 ;
}
static int F_396 ( struct V_1 * V_2 )
{
T_1 V_21 , V_764 ;
V_21 = F_394 ( V_2 , V_777 ) ;
V_764 = ( V_21 & V_778 ) >> V_779 ;
V_21 = F_394 ( V_2 , V_780 ) ;
V_764 |= ( V_21 & V_781 ) << 5 ;
return V_764 ;
}
static int F_397 ( struct V_1 * V_2 )
{
T_1 V_21 ;
V_21 = F_16 ( V_2 , V_782 ) & 0xff ;
return F_172 ( T_1 , V_21 , 0xc0 ) ;
}
static void F_398 ( struct V_1 * V_2 )
{
unsigned long V_783 = F_3 ( V_784 ) & ~ 4095 ;
F_96 ( V_783 != V_2 -> V_785 . V_786 +
V_2 -> V_787 -> V_788 -> V_431 ) ;
}
static void F_399 ( struct V_1 * V_2 )
{
unsigned long V_783 = F_3 ( V_784 ) & ~ 4095 ;
F_96 ( ( V_783 >> V_789 ) == 0 ) ;
}
static void F_400 ( struct V_1 * V_2 )
{
struct V_673 * V_674 = & V_2 -> V_674 ;
unsigned long V_790 , V_791 ;
T_1 V_792 ;
int V_793 = 32 * 1024 ;
V_792 = F_3 ( V_784 ) ;
if ( ( V_792 >> V_789 ) == 0 ) {
F_10 ( L_82 ) ;
V_791 = ( V_2 -> V_785 . V_786 +
( V_674 -> V_794 - V_793 ) ) ;
V_790 = ( V_791 & ( ~ 4095 ) ) ;
F_2 ( V_784 , V_790 ) ;
}
F_10 ( L_83 , F_3 ( V_784 ) ) ;
}
static void F_401 ( struct V_1 * V_2 )
{
struct V_283 * V_795 ;
unsigned long V_790 ;
T_1 V_792 ;
int V_793 = 24 * 1024 ;
V_792 = F_3 ( V_784 ) ;
if ( V_792 ) {
int V_796 ;
V_796 = ( V_792 & ( ~ 4095 ) ) - V_2 -> V_785 . V_786 ;
V_795 = F_402 ( V_2 ,
V_796 ,
V_797 ,
V_793 ) ;
goto V_225;
}
F_10 ( L_82 ) ;
V_795 = F_403 ( V_2 , V_793 ) ;
if ( ! V_795 ) {
F_313 ( L_84 ) ;
goto V_225;
}
V_790 = V_2 -> V_785 . V_786 + V_795 -> V_788 -> V_431 ;
F_2 ( V_784 , V_790 ) ;
V_225:
F_10 ( L_83 , F_3 ( V_784 ) ) ;
V_2 -> V_787 = V_795 ;
}
static void F_404 ( struct V_1 * V_2 )
{
if ( F_96 ( ! V_2 -> V_787 ) )
return;
F_405 ( V_2 -> V_787 ) ;
V_2 -> V_787 = NULL ;
}
static void F_406 ( struct V_1 * V_2 )
{
V_2 -> V_57 . V_798 =
F_407 ( V_2 , L_85 ,
V_799 ,
V_2 -> V_800 ) ;
F_10 ( L_86 ,
V_2 -> V_57 . V_798 ) ;
}
static void F_408 ( struct V_1 * V_2 )
{
T_1 V_21 ;
F_401 ( V_2 ) ;
F_406 ( V_2 ) ;
V_21 = F_16 ( V_2 , V_801 ) ;
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
F_10 ( L_87 , V_2 -> V_36 ) ;
V_2 -> V_57 . V_663 = F_395 ( V_2 ) ;
V_2 -> V_57 . V_615 = V_2 -> V_57 . V_663 ;
F_10 ( L_88 ,
F_336 ( V_2 , V_2 -> V_57 . V_663 ) ,
V_2 -> V_57 . V_663 ) ;
V_2 -> V_57 . V_612 = F_396 ( V_2 ) ;
F_10 ( L_89 ,
F_336 ( V_2 , V_2 -> V_57 . V_612 ) ,
V_2 -> V_57 . V_612 ) ;
V_2 -> V_57 . V_617 = F_393 ( V_2 ) ;
F_10 ( L_90 ,
F_336 ( V_2 , V_2 -> V_57 . V_617 ) ,
V_2 -> V_57 . V_617 ) ;
V_2 -> V_57 . V_664 = F_397 ( V_2 ) ;
F_10 ( L_91 ,
F_336 ( V_2 , V_2 -> V_57 . V_664 ) ,
V_2 -> V_57 . V_664 ) ;
}
static void F_409 ( struct V_1 * V_2 )
{
T_1 V_21 ;
F_400 ( V_2 ) ;
F_406 ( V_2 ) ;
F_15 ( & V_2 -> V_802 ) ;
V_21 = F_410 ( V_2 , V_803 ) ;
F_20 ( & V_2 -> V_802 ) ;
switch ( ( V_21 >> 2 ) & 0x7 ) {
case 3 :
V_2 -> V_36 = 2000 ;
break;
default:
V_2 -> V_36 = 1600 ;
break;
}
F_10 ( L_87 , V_2 -> V_36 ) ;
V_2 -> V_57 . V_663 = F_389 ( V_2 ) ;
V_2 -> V_57 . V_615 = V_2 -> V_57 . V_663 ;
F_10 ( L_88 ,
F_336 ( V_2 , V_2 -> V_57 . V_663 ) ,
V_2 -> V_57 . V_663 ) ;
V_2 -> V_57 . V_612 = F_390 ( V_2 ) ;
F_10 ( L_89 ,
F_336 ( V_2 , V_2 -> V_57 . V_612 ) ,
V_2 -> V_57 . V_612 ) ;
V_2 -> V_57 . V_617 = F_391 ( V_2 ) ;
F_10 ( L_92 ,
F_336 ( V_2 , V_2 -> V_57 . V_617 ) ,
V_2 -> V_57 . V_617 ) ;
V_2 -> V_57 . V_664 = F_392 ( V_2 ) ;
F_10 ( L_91 ,
F_336 ( V_2 , V_2 -> V_57 . V_664 ) ,
V_2 -> V_57 . V_664 ) ;
F_338 ( ( V_2 -> V_57 . V_663 |
V_2 -> V_57 . V_612 |
V_2 -> V_57 . V_617 |
V_2 -> V_57 . V_664 ) & 1 ,
L_93 ) ;
}
static void F_411 ( struct V_1 * V_2 )
{
F_404 ( V_2 ) ;
}
static void F_412 ( struct V_1 * V_2 )
{
struct V_713 * V_714 ;
enum V_715 V_129 ;
T_1 V_729 , V_21 , V_730 = 0 , V_792 ;
F_96 ( ! F_382 ( & V_2 -> V_57 . V_58 ) ) ;
V_729 = F_3 ( V_731 ) & ~ ( V_804 |
V_805 ) ;
if ( V_729 ) {
F_10 ( L_78 ,
V_729 ) ;
F_2 ( V_731 , V_729 ) ;
}
F_399 ( V_2 ) ;
F_340 ( V_2 , V_667 ) ;
F_2 ( V_665 , 0 ) ;
F_2 ( V_717 , 40 << 16 ) ;
F_2 ( V_718 , 125000 ) ;
F_2 ( V_719 , 25 ) ;
F_375 (engine, dev_priv, id)
F_2 ( F_376 ( V_714 -> V_720 ) , 10 ) ;
F_2 ( V_722 , 0 ) ;
F_2 ( V_725 , 0x186 ) ;
F_2 ( V_806 ,
F_31 ( V_807 |
V_808 |
V_809 ) ) ;
V_792 = F_3 ( V_784 ) ;
if ( ( F_378 () & V_701 ) &&
( V_792 >> V_789 ) )
V_730 = V_669 ;
F_2 ( V_665 , V_730 ) ;
F_2 ( V_711 , 1000000 ) ;
F_2 ( V_620 , 59400 ) ;
F_2 ( V_622 , 245000 ) ;
F_2 ( V_619 , 66000 ) ;
F_2 ( V_621 , 350000 ) ;
F_2 ( V_712 , 10 ) ;
F_2 ( V_623 ,
V_625 |
V_626 |
V_627 |
V_628 |
V_629 ) ;
V_21 = V_810 |
V_811 |
V_812 ;
F_17 ( V_2 , V_813 , V_21 ) ;
V_21 = F_16 ( V_2 , V_801 ) ;
F_338 ( ( V_21 & V_814 ) == 0 , L_94 ) ;
F_10 ( L_95 , F_303 ( V_21 & V_814 ) ) ;
F_10 ( L_96 , V_21 ) ;
F_371 ( V_2 , F_337 ) ;
F_341 ( V_2 , V_667 ) ;
}
static void F_413 ( struct V_1 * V_2 )
{
struct V_713 * V_714 ;
enum V_715 V_129 ;
T_1 V_729 , V_21 , V_730 = 0 ;
F_96 ( ! F_382 ( & V_2 -> V_57 . V_58 ) ) ;
F_398 ( V_2 ) ;
V_729 = F_3 ( V_731 ) ;
if ( V_729 ) {
F_10 ( L_78 ,
V_729 ) ;
F_2 ( V_731 , V_729 ) ;
}
F_340 ( V_2 , V_667 ) ;
F_2 ( V_665 , 0 ) ;
F_2 ( V_711 , 1000000 ) ;
F_2 ( V_620 , 59400 ) ;
F_2 ( V_622 , 245000 ) ;
F_2 ( V_619 , 66000 ) ;
F_2 ( V_621 , 350000 ) ;
F_2 ( V_712 , 10 ) ;
F_2 ( V_623 ,
V_624 |
V_625 |
V_626 |
V_627 |
V_628 |
V_815 ) ;
F_2 ( V_717 , 0x00280000 ) ;
F_2 ( V_718 , 125000 ) ;
F_2 ( V_719 , 25 ) ;
F_375 (engine, dev_priv, id)
F_2 ( F_376 ( V_714 -> V_720 ) , 10 ) ;
F_2 ( V_725 , 0x557 ) ;
F_2 ( V_806 ,
F_31 ( V_807 |
V_816 |
V_817 |
V_808 |
V_809 ) ) ;
if ( F_378 () & V_701 )
V_730 = V_669 | V_818 ;
F_361 ( V_2 , V_730 ) ;
F_2 ( V_665 , V_730 ) ;
V_21 = V_810 |
V_811 |
V_819 ;
F_17 ( V_2 , V_813 , V_21 ) ;
V_21 = F_16 ( V_2 , V_801 ) ;
F_338 ( ( V_21 & V_814 ) == 0 , L_94 ) ;
F_10 ( L_95 , F_303 ( V_21 & V_814 ) ) ;
F_10 ( L_96 , V_21 ) ;
F_371 ( V_2 , F_337 ) ;
F_341 ( V_2 , V_667 ) ;
}
static unsigned long F_414 ( T_1 V_820 )
{
unsigned long V_647 ;
int div = ( V_820 & 0x3f0000 ) >> 16 ;
int V_821 = ( V_820 & 0x3000 ) >> 12 ;
int V_822 = ( V_820 & 0x7 ) ;
if ( ! V_822 )
return 0 ;
V_647 = ( ( div * 133333 ) / ( ( 1 << V_821 ) * V_822 ) ) ;
return V_647 ;
}
static unsigned long F_415 ( struct V_1 * V_2 )
{
T_10 V_823 , V_750 , V_74 ;
T_1 V_824 , V_825 , V_826 , V_827 = 0 , V_828 = 0 ;
unsigned long V_829 = F_321 ( V_592 ) , V_830 ;
int V_54 ;
F_312 ( & V_550 ) ;
V_830 = V_829 - V_2 -> V_46 . V_591 ;
if ( V_830 <= 10 )
return V_2 -> V_46 . V_831 ;
V_824 = F_3 ( V_588 ) ;
V_825 = F_3 ( V_589 ) ;
V_826 = F_3 ( V_590 ) ;
V_823 = V_824 + V_825 + V_826 ;
if ( V_823 < V_2 -> V_46 . V_587 ) {
V_750 = ~ 0UL - V_2 -> V_46 . V_587 ;
V_750 += V_823 ;
} else {
V_750 = V_823 - V_2 -> V_46 . V_587 ;
}
for ( V_54 = 0 ; V_54 < F_12 ( V_832 ) ; V_54 ++ ) {
if ( V_832 [ V_54 ] . V_54 == V_2 -> V_46 . V_48 &&
V_832 [ V_54 ] . V_833 == V_2 -> V_46 . V_47 ) {
V_827 = V_832 [ V_54 ] . V_827 ;
V_828 = V_832 [ V_54 ] . V_828 ;
break;
}
}
V_750 = F_240 ( V_750 , V_830 ) ;
V_74 = ( ( V_827 * V_750 ) + V_828 ) ;
V_74 = F_240 ( V_74 , 10 ) ;
V_2 -> V_46 . V_587 = V_823 ;
V_2 -> V_46 . V_591 = V_829 ;
V_2 -> V_46 . V_831 = V_74 ;
return V_74 ;
}
unsigned long F_416 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
if ( F_115 ( V_2 ) -> V_700 != 5 )
return 0 ;
F_317 ( & V_550 ) ;
V_21 = F_415 ( V_2 ) ;
F_323 ( & V_550 ) ;
return V_21 ;
}
unsigned long F_417 ( struct V_1 * V_2 )
{
unsigned long V_827 , V_834 , V_358 ;
T_1 V_835 ;
V_835 = F_3 ( V_836 ) ;
V_827 = ( ( V_835 & V_837 ) >> V_838 ) ;
V_834 = F_418 ( V_839 ) ;
V_358 = V_835 & V_840 ;
return ( ( V_827 * V_834 ) / 127 ) - V_358 ;
}
static int F_419 ( T_9 V_841 )
{
if ( V_841 == 0 )
return 0 ;
if ( V_841 >= 8 && V_841 < 31 )
V_841 = 31 ;
return ( V_841 + 2 ) * 125 ;
}
static T_1 F_420 ( struct V_1 * V_2 , T_9 V_841 )
{
const int V_842 = F_419 ( V_841 ) ;
const int V_843 = V_842 - 1125 ;
if ( F_115 ( V_2 ) -> V_844 )
return V_843 > 0 ? V_843 : 0 ;
return V_842 ;
}
static void F_421 ( struct V_1 * V_2 )
{
T_10 V_829 , V_750 , V_845 ;
T_1 V_846 ;
F_312 ( & V_550 ) ;
V_829 = F_322 () ;
V_845 = V_829 - V_2 -> V_46 . V_595 ;
F_422 ( V_845 , V_847 ) ;
if ( ! V_845 )
return;
V_846 = F_3 ( V_594 ) ;
if ( V_846 < V_2 -> V_46 . V_593 ) {
V_750 = ~ 0UL - V_2 -> V_46 . V_593 ;
V_750 += V_846 ;
} else {
V_750 = V_846 - V_2 -> V_46 . V_593 ;
}
V_2 -> V_46 . V_593 = V_846 ;
V_2 -> V_46 . V_595 = V_829 ;
V_750 = V_750 * 1181 ;
V_750 = F_240 ( V_750 , V_845 * 10 ) ;
V_2 -> V_46 . V_848 = V_750 ;
}
void F_423 ( struct V_1 * V_2 )
{
if ( F_115 ( V_2 ) -> V_700 != 5 )
return;
F_317 ( & V_550 ) ;
F_421 ( V_2 ) ;
F_323 ( & V_550 ) ;
}
static unsigned long F_424 ( struct V_1 * V_2 )
{
unsigned long V_833 , V_849 , V_850 , V_851 , V_852 ;
T_1 V_841 , V_853 ;
F_312 ( & V_550 ) ;
V_841 = F_3 ( F_318 ( V_2 -> V_57 . V_613 ) ) ;
V_841 = ( V_841 >> 24 ) & 0x7f ;
V_853 = F_420 ( V_2 , V_841 ) ;
V_850 = V_853 ;
V_833 = F_417 ( V_2 ) ;
if ( V_833 > 80 )
V_849 = ( ( V_833 * 2349 ) + 135940 ) ;
else if ( V_833 >= 50 )
V_849 = ( ( V_833 * 964 ) + 29317 ) ;
else
V_849 = ( ( V_833 * 301 ) + 1004 ) ;
V_849 = V_849 * ( ( 150142 * V_850 ) / 10000 - 78642 ) ;
V_849 /= 100000 ;
V_851 = ( V_849 * V_2 -> V_46 . V_849 ) ;
V_852 = ( V_851 * V_850 ) / 10000 ;
V_852 /= 100 ;
F_421 ( V_2 ) ;
return V_2 -> V_46 . V_848 + V_852 ;
}
unsigned long F_425 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
if ( F_115 ( V_2 ) -> V_700 != 5 )
return 0 ;
F_317 ( & V_550 ) ;
V_21 = F_424 ( V_2 ) ;
F_323 ( & V_550 ) ;
return V_21 ;
}
unsigned long F_426 ( void )
{
struct V_1 * V_2 ;
unsigned long V_854 , V_855 , V_74 = 0 ;
F_317 ( & V_550 ) ;
if ( ! V_856 )
goto V_857;
V_2 = V_856 ;
V_854 = F_415 ( V_2 ) ;
V_855 = F_424 ( V_2 ) ;
V_74 = V_854 + V_855 ;
V_857:
F_323 ( & V_550 ) ;
return V_74 ;
}
bool F_427 ( void )
{
struct V_1 * V_2 ;
bool V_74 = true ;
F_317 ( & V_550 ) ;
if ( ! V_856 ) {
V_74 = false ;
goto V_857;
}
V_2 = V_856 ;
if ( V_2 -> V_46 . V_579 > V_2 -> V_46 . V_558 )
V_2 -> V_46 . V_579 -- ;
V_857:
F_323 ( & V_550 ) ;
return V_74 ;
}
bool F_428 ( void )
{
struct V_1 * V_2 ;
bool V_74 = true ;
F_317 ( & V_550 ) ;
if ( ! V_856 ) {
V_74 = false ;
goto V_857;
}
V_2 = V_856 ;
if ( V_2 -> V_46 . V_579 < V_2 -> V_46 . V_580 )
V_2 -> V_46 . V_579 ++ ;
V_857:
F_323 ( & V_550 ) ;
return V_74 ;
}
bool F_429 ( void )
{
bool V_74 = false ;
F_317 ( & V_550 ) ;
if ( V_856 )
V_74 = V_856 -> V_653 . V_654 ;
F_323 ( & V_550 ) ;
return V_74 ;
}
bool F_430 ( void )
{
struct V_1 * V_2 ;
bool V_74 = true ;
F_317 ( & V_550 ) ;
if ( ! V_856 ) {
V_74 = false ;
goto V_857;
}
V_2 = V_856 ;
V_2 -> V_46 . V_579 = V_2 -> V_46 . V_560 ;
if ( ! F_311 ( V_2 , V_2 -> V_46 . V_560 ) )
V_74 = false ;
V_857:
F_323 ( & V_550 ) ;
return V_74 ;
}
static void
F_431 ( void )
{
void (* V_657)( void );
V_657 = F_432 ( V_858 ) ;
if ( V_657 ) {
V_657 () ;
F_433 ( V_858 ) ;
}
}
void F_434 ( struct V_1 * V_2 )
{
F_317 ( & V_550 ) ;
V_856 = V_2 ;
F_323 ( & V_550 ) ;
F_431 () ;
}
void F_435 ( void )
{
F_317 ( & V_550 ) ;
V_856 = NULL ;
F_323 ( & V_550 ) ;
}
static void F_436 ( struct V_1 * V_2 )
{
T_1 V_859 ;
T_9 V_860 [ 16 ] ;
int V_54 ;
F_2 ( V_861 , 0 ) ;
F_25 ( V_861 ) ;
F_2 ( V_862 , 0x15040d00 ) ;
F_2 ( V_863 , 0x007f0000 ) ;
F_2 ( V_864 , 0x1e220004 ) ;
F_2 ( V_865 , 0x04000004 ) ;
for ( V_54 = 0 ; V_54 < 5 ; V_54 ++ )
F_2 ( F_437 ( V_54 ) , 0 ) ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ )
F_2 ( F_438 ( V_54 ) , 0 ) ;
for ( V_54 = 0 ; V_54 < 16 ; V_54 ++ ) {
T_1 V_866 = F_3 ( F_318 ( V_54 ) ) ;
unsigned long V_647 = F_414 ( V_866 ) ;
unsigned long V_867 = ( V_866 & V_577 ) >>
V_578 ;
unsigned long V_21 ;
V_21 = V_867 * V_867 ;
V_21 *= ( V_647 / 1000 ) ;
V_21 *= 255 ;
V_21 /= ( 127 * 127 * 900 ) ;
if ( V_21 > 0xff )
F_19 ( L_97 , V_21 ) ;
V_860 [ V_54 ] = V_21 ;
}
V_860 [ 14 ] = 0 ;
V_860 [ 15 ] = 0 ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
T_1 V_21 = ( V_860 [ V_54 * 4 ] << 24 ) | ( V_860 [ ( V_54 * 4 ) + 1 ] << 16 ) |
( V_860 [ ( V_54 * 4 ) + 2 ] << 8 ) | ( V_860 [ ( V_54 * 4 ) + 3 ] ) ;
F_2 ( F_439 ( V_54 ) , V_21 ) ;
}
F_2 ( V_868 , 0 ) ;
F_2 ( V_869 , 0 ) ;
F_2 ( V_870 , 0x00007f00 ) ;
F_2 ( V_871 , 0x0000000e ) ;
F_2 ( V_872 , 0x000e0000 ) ;
F_2 ( V_873 , 0x68000300 ) ;
F_2 ( V_874 , 0x42000000 ) ;
F_2 ( V_875 , 0x00140031 ) ;
F_2 ( V_876 , 0 ) ;
F_2 ( V_877 , 0 ) ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ )
F_2 ( F_440 ( V_54 ) , 0 ) ;
F_2 ( V_861 , 0x80000019 ) ;
V_859 = F_3 ( V_878 ) ;
V_2 -> V_46 . V_849 = ( V_859 & V_879 ) ;
}
void F_441 ( struct V_1 * V_2 )
{
if ( ! V_880 . V_675 ) {
F_368 ( L_98 ) ;
F_442 ( V_2 ) ;
}
F_15 ( & V_2 -> V_537 . V_881 ) ;
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( F_24 ( V_2 ) )
F_409 ( V_2 ) ;
else if ( F_23 ( V_2 ) )
F_408 ( V_2 ) ;
else if ( F_145 ( V_2 ) >= 6 )
F_369 ( V_2 ) ;
V_2 -> V_57 . V_645 = V_2 -> V_57 . V_664 ;
V_2 -> V_57 . V_613 = V_2 -> V_57 . V_645 ;
V_2 -> V_57 . V_603 = V_2 -> V_57 . V_663 ;
V_2 -> V_57 . V_604 = V_2 -> V_57 . V_664 ;
if ( F_163 ( V_2 ) || F_164 ( V_2 ) )
V_2 -> V_57 . V_604 =
F_172 ( int ,
V_2 -> V_57 . V_612 ,
F_443 ( V_2 , 450 ) ) ;
if ( F_175 ( V_2 ) ||
F_169 ( V_2 ) || F_163 ( V_2 ) ) {
T_1 V_882 = 0 ;
F_162 ( V_2 , V_883 , & V_882 ) ;
if ( V_882 & F_92 ( 31 ) ) {
F_10 ( L_99 ,
( V_2 -> V_57 . V_663 & 0xff ) * 50 ,
( V_882 & 0xff ) * 50 ) ;
V_2 -> V_57 . V_663 = V_882 & 0xff ;
}
}
V_2 -> V_57 . V_655 = V_2 -> V_57 . V_663 ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
F_20 ( & V_2 -> V_537 . V_881 ) ;
F_444 ( V_2 ) ;
}
void F_445 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) )
F_411 ( V_2 ) ;
if ( ! V_880 . V_675 )
F_446 ( V_2 ) ;
}
void F_447 ( struct V_1 * V_2 )
{
if ( F_145 ( V_2 ) < 6 )
return;
if ( F_448 ( & V_2 -> V_57 . V_884 ) )
F_446 ( V_2 ) ;
}
void F_449 ( struct V_1 * V_2 )
{
V_2 -> V_57 . V_132 = true ;
F_450 ( V_2 ) ;
F_451 ( V_2 ) ;
}
void F_450 ( struct V_1 * V_2 )
{
if ( ! F_452 ( V_2 -> V_57 . V_132 ) )
return;
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( F_145 ( V_2 ) >= 9 ) {
F_356 ( V_2 ) ;
F_357 ( V_2 ) ;
} else if ( F_24 ( V_2 ) ) {
F_359 ( V_2 ) ;
} else if ( F_23 ( V_2 ) ) {
F_360 ( V_2 ) ;
} else if ( F_145 ( V_2 ) >= 6 ) {
F_358 ( V_2 ) ;
} else if ( F_453 ( V_2 ) ) {
F_324 ( V_2 ) ;
}
V_2 -> V_57 . V_132 = false ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
void F_454 ( struct V_1 * V_2 )
{
if ( F_452 ( V_2 -> V_57 . V_132 ) )
return;
if ( F_455 ( V_2 ) )
return;
F_15 ( & V_2 -> V_57 . V_58 ) ;
if ( F_24 ( V_2 ) ) {
F_412 ( V_2 ) ;
} else if ( F_23 ( V_2 ) ) {
F_413 ( V_2 ) ;
} else if ( F_145 ( V_2 ) >= 9 ) {
F_374 ( V_2 ) ;
F_373 ( V_2 ) ;
if ( F_199 ( V_2 ) )
F_385 ( V_2 ) ;
} else if ( F_164 ( V_2 ) ) {
F_380 ( V_2 ) ;
F_385 ( V_2 ) ;
} else if ( F_145 ( V_2 ) >= 6 ) {
F_381 ( V_2 ) ;
F_385 ( V_2 ) ;
} else if ( F_453 ( V_2 ) ) {
F_316 ( V_2 ) ;
F_436 ( V_2 ) ;
}
F_96 ( V_2 -> V_57 . V_663 < V_2 -> V_57 . V_664 ) ;
F_96 ( V_2 -> V_57 . V_645 > V_2 -> V_57 . V_663 ) ;
F_96 ( V_2 -> V_57 . V_612 < V_2 -> V_57 . V_664 ) ;
F_96 ( V_2 -> V_57 . V_612 > V_2 -> V_57 . V_663 ) ;
V_2 -> V_57 . V_132 = true ;
F_20 ( & V_2 -> V_57 . V_58 ) ;
}
static void F_456 ( struct V_885 * V_661 )
{
struct V_1 * V_2 =
F_457 ( V_661 , F_458 ( * V_2 ) , V_57 . V_884 . V_661 ) ;
struct V_713 * V_886 ;
struct V_887 * V_888 ;
if ( F_452 ( V_2 -> V_57 . V_132 ) )
goto V_225;
V_886 = V_2 -> V_714 [ V_889 ] ;
if ( V_886 -> V_890 )
goto V_225;
if ( ! V_886 -> V_891 )
goto V_225;
F_15 ( & V_2 -> V_537 . V_881 ) ;
V_888 = F_459 ( V_886 , V_2 -> V_892 ) ;
if ( F_276 ( V_888 ) )
goto V_893;
if ( ! V_880 . V_894 && F_460 ( V_888 ) == 0 )
V_886 -> V_891 ( V_888 ) ;
F_461 ( V_888 ) ;
V_893:
F_20 ( & V_2 -> V_537 . V_881 ) ;
V_225:
F_446 ( V_2 ) ;
}
void F_444 ( struct V_1 * V_2 )
{
if ( F_452 ( V_2 -> V_57 . V_132 ) )
return;
if ( F_453 ( V_2 ) ) {
F_316 ( V_2 ) ;
F_436 ( V_2 ) ;
} else if ( F_115 ( V_2 ) -> V_700 >= 6 ) {
if ( F_462 ( V_2 -> V_895 ,
& V_2 -> V_57 . V_884 ,
F_463 ( V_896 ) ) )
F_464 ( V_2 ) ;
}
}
static void F_465 ( struct V_1 * V_2 )
{
F_2 ( V_897 , V_898 ) ;
}
static void F_466 ( struct V_1 * V_2 )
{
enum V_88 V_88 ;
F_65 (dev_priv, pipe) {
F_2 ( F_467 ( V_88 ) ,
F_3 ( F_467 ( V_88 ) ) |
V_899 ) ;
F_2 ( F_468 ( V_88 ) , F_3 ( F_468 ( V_88 ) ) ) ;
F_25 ( F_468 ( V_88 ) ) ;
}
}
static void F_469 ( struct V_1 * V_2 )
{
F_2 ( V_391 , F_3 ( V_391 ) & ~ V_373 ) ;
F_2 ( V_392 , F_3 ( V_392 ) & ~ V_373 ) ;
F_2 ( V_393 , F_3 ( V_393 ) & ~ V_373 ) ;
}
static void F_470 ( struct V_1 * V_2 )
{
T_3 V_900 = V_901 ;
V_900 |= V_902 |
V_903 |
V_904 ;
F_2 ( V_905 ,
V_906 |
V_907 ) ;
F_2 ( V_908 ,
V_909 ) ;
F_2 ( V_910 ,
( F_3 ( V_910 ) |
V_911 | V_912 ) ) ;
V_900 |= V_913 ;
F_2 ( V_9 ,
( F_3 ( V_9 ) |
V_10 ) ) ;
F_469 ( V_2 ) ;
if ( F_453 ( V_2 ) ) {
F_2 ( V_914 ,
F_3 ( V_914 ) |
V_915 ) ;
F_2 ( V_910 ,
F_3 ( V_910 ) |
V_911 ) ;
}
F_2 ( V_916 , V_900 ) ;
F_2 ( V_910 ,
F_3 ( V_910 ) |
V_917 ) ;
F_2 ( V_918 ,
V_919 << 16 |
V_919 ) ;
F_2 ( V_920 ,
F_31 ( V_921 ) ) ;
F_2 ( V_920 , F_32 ( V_922 ) ) ;
F_466 ( V_2 ) ;
F_465 ( V_2 ) ;
}
static void F_471 ( struct V_1 * V_2 )
{
int V_88 ;
T_3 V_21 ;
F_2 ( V_897 , V_898 |
V_923 |
V_924 ) ;
F_2 ( V_925 , F_3 ( V_925 ) |
V_926 ) ;
F_65 (dev_priv, pipe) {
V_21 = F_3 ( F_472 ( V_88 ) ) ;
V_21 |= V_927 ;
V_21 &= ~ V_928 ;
if ( V_2 -> V_929 . V_930 )
V_21 |= V_928 ;
V_21 &= ~ V_931 ;
V_21 &= ~ V_932 ;
V_21 &= ~ V_933 ;
F_2 ( F_472 ( V_88 ) , V_21 ) ;
}
F_65 (dev_priv, pipe) {
F_2 ( F_473 ( V_88 ) ,
V_934 ) ;
}
}
static void F_474 ( struct V_1 * V_2 )
{
T_3 V_26 ;
V_26 = F_3 ( V_329 ) ;
if ( ( V_26 & V_935 ) != V_936 )
F_13 ( L_100 ,
V_26 ) ;
}
static void F_475 ( struct V_1 * V_2 )
{
T_3 V_900 = V_901 ;
F_2 ( V_916 , V_900 ) ;
F_2 ( V_910 ,
F_3 ( V_910 ) |
V_917 ) ;
F_2 ( V_937 ,
F_31 ( V_938 ) ) ;
F_2 ( V_920 , F_32 ( V_922 ) ) ;
F_2 ( V_939 ,
F_476 ( V_940 , V_941 ) ) ;
F_469 ( V_2 ) ;
F_2 ( V_920 ,
F_32 ( V_942 ) ) ;
F_2 ( V_943 ,
F_3 ( V_943 ) |
V_944 |
V_945 ) ;
F_2 ( V_946 ,
V_947 |
V_948 ) ;
F_2 ( V_949 ,
F_31 ( V_950 ) ) ;
F_2 ( V_949 ,
F_31 ( V_951 ) ) ;
F_2 ( V_914 ,
F_3 ( V_914 ) |
V_915 | V_952 ) ;
F_2 ( V_910 ,
F_3 ( V_910 ) |
V_911 | V_912 ) ;
F_2 ( V_916 ,
F_3 ( V_916 ) |
V_913 |
V_904 ) ;
F_466 ( V_2 ) ;
F_471 ( V_2 ) ;
F_474 ( V_2 ) ;
}
static void F_477 ( struct V_1 * V_2 )
{
T_3 V_134 = F_3 ( V_953 ) ;
V_134 &= ~ V_954 ;
V_134 |= V_955 ;
V_134 |= V_956 ;
V_134 |= V_957 ;
F_2 ( V_953 , V_134 ) ;
}
static void F_478 ( struct V_1 * V_2 )
{
if ( F_479 ( V_2 ) )
F_2 ( V_897 ,
F_3 ( V_897 ) |
V_958 ) ;
F_2 ( F_473 ( V_94 ) ,
F_3 ( F_473 ( V_94 ) ) |
V_934 ) ;
}
static void F_480 ( struct V_1 * V_2 )
{
if ( F_479 ( V_2 ) ) {
T_3 V_21 = F_3 ( V_897 ) ;
V_21 &= ~ V_958 ;
F_2 ( V_897 , V_21 ) ;
}
}
static void F_481 ( struct V_1 * V_2 ,
int V_959 ,
int V_960 )
{
T_1 V_961 ;
V_961 = F_3 ( V_962 ) ;
F_2 ( V_962 , V_961 & ~ V_963 ) ;
F_2 ( V_964 ,
F_482 ( V_959 ) |
F_483 ( V_960 ) ) ;
F_25 ( V_964 ) ;
F_484 ( 1 ) ;
F_2 ( V_962 , V_961 ) ;
}
static void F_485 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
if ( F_486 ( V_2 , 0 , V_965 ) )
F_2 ( V_14 , F_3 ( V_14 ) |
V_15 ) ;
if ( F_486 ( V_2 , 0 , V_965 ) )
F_2 ( V_943 , F_3 ( V_943 ) |
V_966 ) ;
F_2 ( V_12 , F_3 ( V_12 ) |
V_967 ) ;
}
static void F_487 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_2 ( V_968 , F_3 ( V_968 ) |
V_969 ) ;
F_2 ( V_12 , F_3 ( V_12 ) |
V_967 ) ;
}
static void F_488 ( struct V_1 * V_2 )
{
enum V_88 V_88 ;
F_469 ( V_2 ) ;
F_2 ( V_970 , F_3 ( V_970 ) | V_971 ) ;
F_2 ( V_3 ,
F_3 ( V_3 ) | V_972 ) ;
F_65 (dev_priv, pipe) {
F_2 ( F_489 ( V_88 ) ,
F_3 ( F_489 ( V_88 ) ) |
V_973 ) ;
}
F_2 ( V_953 ,
F_3 ( V_953 ) &
~ ( V_974 | V_975 ) ) ;
F_2 ( V_976 ,
F_31 ( V_977 ) ) ;
F_2 ( V_14 , F_3 ( V_14 ) |
V_15 ) ;
F_481 ( V_2 , 30 , 2 ) ;
F_2 ( V_978 , V_979 ) ;
F_2 ( V_980 , F_3 ( V_980 )
| V_981 ) ;
F_478 ( V_2 ) ;
F_2 ( V_943 ,
F_3 ( V_943 ) | V_982 ) ;
}
static void F_490 ( struct V_1 * V_2 )
{
F_469 ( V_2 ) ;
F_2 ( V_983 , V_984 ) ;
F_2 ( V_985 ,
F_31 ( V_986 ) ) ;
F_2 ( V_987 ,
F_3 ( V_987 ) |
V_988 ) ;
F_2 ( V_953 ,
F_3 ( V_953 ) & ~ V_975 ) ;
F_2 ( V_989 , F_32 ( V_922 ) ) ;
F_2 ( V_989 ,
F_32 ( V_990 ) ) ;
F_2 ( V_991 ,
F_31 ( V_992 ) ) ;
F_2 ( V_993 ,
F_476 ( V_940 , V_941 ) ) ;
F_2 ( V_994 ,
F_31 ( V_995 ) ) ;
F_2 ( V_970 , F_3 ( V_970 ) | V_971 ) ;
F_2 ( V_3 ,
F_3 ( V_3 ) | V_996 ) ;
F_478 ( V_2 ) ;
}
static void F_491 ( struct V_1 * V_2 )
{
T_3 V_997 ;
F_469 ( V_2 ) ;
F_2 ( V_916 , V_901 ) ;
F_2 ( V_949 ,
F_31 ( V_998 ) ) ;
F_2 ( V_999 ,
V_1000 |
V_1001 ) ;
if ( F_492 ( V_2 ) )
F_2 ( V_1002 ,
F_31 ( V_1003 ) ) ;
F_2 ( V_989 , F_32 ( V_922 ) ) ;
F_2 ( V_1004 ,
V_1005 ) ;
F_2 ( V_1006 ,
V_1007 ) ;
F_2 ( V_1008 ,
V_1009 ) ;
if ( F_492 ( V_2 ) )
F_2 ( V_1010 ,
F_31 ( V_1011 ) ) ;
else {
F_2 ( V_1010 ,
F_31 ( V_1011 ) ) ;
F_2 ( V_1012 ,
F_31 ( V_1011 ) ) ;
}
F_2 ( V_1013 , F_3 ( V_1013 ) &
~ V_1014 ) ;
F_2 ( V_946 ,
V_1015 ) ;
F_2 ( V_987 ,
F_3 ( V_987 ) |
V_988 ) ;
F_466 ( V_2 ) ;
F_477 ( V_2 ) ;
if ( 0 ) {
F_2 ( V_989 ,
F_32 ( V_990 ) ) ;
}
F_2 ( V_991 ,
F_31 ( V_992 ) ) ;
F_2 ( V_993 ,
F_476 ( V_940 , V_941 ) ) ;
V_997 = F_3 ( V_1016 ) ;
V_997 &= ~ V_1017 ;
V_997 |= V_1018 ;
F_2 ( V_1016 , V_997 ) ;
if ( ! F_493 ( V_2 ) )
F_471 ( V_2 ) ;
F_474 ( V_2 ) ;
}
static void F_494 ( struct V_1 * V_2 )
{
F_2 ( V_949 ,
F_31 ( V_998 ) ) ;
F_2 ( V_999 ,
V_1000 |
V_1001 ) ;
F_2 ( V_1002 ,
F_31 ( V_1019 |
V_1003 ) ) ;
F_2 ( V_989 , F_32 ( V_922 ) ) ;
F_2 ( V_1013 , F_3 ( V_1013 ) &
~ V_1014 ) ;
F_2 ( V_1010 ,
F_31 ( V_1011 ) ) ;
F_2 ( V_987 ,
F_3 ( V_987 ) |
V_988 ) ;
F_477 ( V_2 ) ;
F_2 ( V_946 ,
V_1015 ) ;
F_2 ( V_1020 ,
F_3 ( V_1020 ) | V_1021 ) ;
F_2 ( V_991 ,
F_31 ( V_992 ) ) ;
F_2 ( V_993 ,
F_476 ( V_940 , V_941 ) ) ;
F_2 ( V_1022 , V_1023 ) ;
F_2 ( V_1024 , V_1025 ) ;
}
static void F_495 ( struct V_1 * V_2 )
{
F_2 ( V_953 ,
F_3 ( V_953 ) &
~ ( V_974 | V_975 ) ) ;
F_2 ( V_976 ,
F_31 ( V_977 ) ) ;
F_2 ( V_943 , F_3 ( V_943 ) |
V_945 ) ;
F_2 ( V_14 , F_3 ( V_14 ) |
V_15 ) ;
F_481 ( V_2 , 38 , 2 ) ;
F_2 ( V_978 , V_979 ) ;
}
static void F_496 ( struct V_1 * V_2 )
{
T_3 V_900 ;
F_2 ( V_1026 , 0 ) ;
F_2 ( V_1027 , V_1028 |
V_1029 |
V_1030 ) ;
F_2 ( V_1031 , 0 ) ;
V_900 = V_1032 |
V_1033 |
V_1034 ;
if ( F_77 ( V_2 ) )
V_900 |= V_1035 ;
F_2 ( V_1036 , V_900 ) ;
F_2 ( V_920 ,
F_31 ( V_921 ) ) ;
F_2 ( V_920 , F_32 ( V_922 ) ) ;
F_466 ( V_2 ) ;
}
static void F_497 ( struct V_1 * V_2 )
{
F_2 ( V_1026 , V_1037 ) ;
F_2 ( V_1027 , 0 ) ;
F_2 ( V_1036 , 0 ) ;
F_2 ( V_1031 , 0 ) ;
F_314 ( V_1038 , 0 ) ;
F_2 ( V_1039 ,
F_31 ( V_1040 ) ) ;
F_2 ( V_920 , F_32 ( V_922 ) ) ;
}
static void F_498 ( struct V_1 * V_2 )
{
F_2 ( V_1026 , V_1041 |
V_1037 |
V_1042 |
V_1043 |
V_1044 ) ;
F_2 ( V_1027 , 0 ) ;
F_2 ( V_1039 ,
F_31 ( V_1040 ) ) ;
F_2 ( V_920 , F_32 ( V_922 ) ) ;
}
static void F_499 ( struct V_1 * V_2 )
{
T_1 V_1045 = F_3 ( V_1046 ) ;
V_1045 |= V_1047 | V_1048 |
V_1049 ;
F_2 ( V_1046 , V_1045 ) ;
if ( F_28 ( V_2 ) )
F_2 ( V_1050 , F_31 ( V_1051 ) ) ;
F_2 ( V_1050 , F_32 ( V_1052 ) ) ;
F_2 ( V_72 , F_31 ( V_1053 ) ) ;
F_2 ( V_1039 , F_31 ( V_1054 ) ) ;
F_2 ( V_1039 ,
F_31 ( V_1040 ) ) ;
}
static void F_500 ( struct V_1 * V_2 )
{
F_2 ( V_1026 , V_1055 ) ;
F_2 ( V_1056 , F_31 ( V_1057 ) |
F_32 ( V_1058 ) ) ;
F_2 ( V_1059 ,
F_31 ( V_1060 ) ) ;
}
static void F_501 ( struct V_1 * V_2 )
{
F_2 ( V_1059 ,
F_31 ( V_1061 ) |
F_31 ( V_1062 ) ) ;
}
void F_502 ( struct V_1 * V_2 )
{
V_2 -> V_279 . V_1063 ( V_2 ) ;
}
void F_503 ( struct V_1 * V_2 )
{
if ( F_504 ( V_2 ) )
F_480 ( V_2 ) ;
}
static void F_505 ( struct V_1 * V_2 )
{
F_13 ( L_101 ) ;
}
void F_506 ( struct V_1 * V_2 )
{
if ( F_204 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_487 ;
else if ( F_202 ( V_2 ) || F_203 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_485 ;
else if ( F_200 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_4 ;
else if ( F_229 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_5 ;
else if ( F_164 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_488 ;
else if ( F_24 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_495 ;
else if ( F_163 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_490 ;
else if ( F_169 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_491 ;
else if ( F_23 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_494 ;
else if ( F_175 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_475 ;
else if ( F_167 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_470 ;
else if ( F_26 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_496 ;
else if ( F_27 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_497 ;
else if ( F_507 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_498 ;
else if ( F_508 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_499 ;
else if ( F_509 ( V_2 ) || F_510 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_500 ;
else if ( F_132 ( V_2 ) )
V_2 -> V_279 . V_1063 = F_501 ;
else {
F_41 ( F_511 ( V_2 ) ) ;
V_2 -> V_279 . V_1063 = F_505 ;
}
}
void F_512 ( struct V_1 * V_2 )
{
F_513 ( V_2 ) ;
if ( F_28 ( V_2 ) )
F_7 ( V_2 ) ;
else if ( F_167 ( V_2 ) )
F_8 ( V_2 ) ;
if ( F_145 ( V_2 ) >= 9 ) {
F_176 ( V_2 ) ;
V_2 -> V_279 . V_1064 = F_287 ;
V_2 -> V_279 . V_1065 = F_286 ;
V_2 -> V_279 . V_1066 = F_285 ;
} else if ( F_514 ( V_2 ) ) {
F_174 ( V_2 ) ;
if ( ( F_167 ( V_2 ) && V_2 -> V_75 . V_208 [ 1 ] &&
V_2 -> V_75 . V_315 [ 1 ] && V_2 -> V_75 . V_316 [ 1 ] ) ||
( ! F_167 ( V_2 ) && V_2 -> V_75 . V_208 [ 0 ] &&
V_2 -> V_75 . V_315 [ 0 ] && V_2 -> V_75 . V_316 [ 0 ] ) ) {
V_2 -> V_279 . V_1067 = F_178 ;
V_2 -> V_279 . V_1068 =
F_182 ;
V_2 -> V_279 . V_1064 =
F_290 ;
V_2 -> V_279 . V_1069 =
F_291 ;
} else {
F_13 ( L_102
L_103 ) ;
}
} else if ( F_23 ( V_2 ) || F_24 ( V_2 ) ) {
F_102 ( V_2 ) ;
V_2 -> V_279 . V_1067 = F_112 ;
V_2 -> V_279 . V_1068 = F_125 ;
V_2 -> V_279 . V_1064 = F_128 ;
V_2 -> V_279 . V_1069 = F_129 ;
V_2 -> V_279 . V_1065 = F_117 ;
} else if ( F_26 ( V_2 ) ) {
F_73 ( V_2 ) ;
V_2 -> V_279 . V_1067 = F_89 ;
V_2 -> V_279 . V_1068 = F_95 ;
V_2 -> V_279 . V_1064 = F_99 ;
V_2 -> V_279 . V_1069 = F_100 ;
} else if ( F_28 ( V_2 ) ) {
if ( ! F_11 ( F_60 ( V_2 ) ,
V_2 -> V_40 ,
V_2 -> V_30 ,
V_2 -> V_36 ) ) {
F_368 ( L_104
L_105
L_106 ,
( V_2 -> V_40 == 1 ) ? L_107 : L_108 ,
V_2 -> V_30 , V_2 -> V_36 ) ;
F_36 ( V_2 , false ) ;
V_2 -> V_279 . V_548 = NULL ;
} else
V_2 -> V_279 . V_548 = F_59 ;
} else if ( F_515 ( V_2 ) ) {
V_2 -> V_279 . V_548 = F_130 ;
} else if ( F_508 ( V_2 ) ) {
V_2 -> V_279 . V_548 = F_131 ;
V_2 -> V_279 . V_280 = F_42 ;
} else if ( F_132 ( V_2 ) ) {
if ( F_115 ( V_2 ) -> V_258 == 1 ) {
V_2 -> V_279 . V_548 = F_137 ;
V_2 -> V_279 . V_280 = F_44 ;
} else {
V_2 -> V_279 . V_548 = F_131 ;
V_2 -> V_279 . V_280 = F_43 ;
}
} else {
F_19 ( L_109 ) ;
}
}
static inline int F_516 ( struct V_1 * V_2 )
{
T_3 V_414 =
F_120 ( V_1070 ) & V_1071 ;
switch ( V_414 ) {
case V_1072 :
return 0 ;
case V_1073 :
case V_1074 :
return - V_409 ;
case V_1075 :
case V_1076 :
return - V_1077 ;
case V_1078 :
return - V_1079 ;
default:
F_41 ( V_414 ) ;
return 0 ;
}
}
static inline int F_517 ( struct V_1 * V_2 )
{
T_3 V_414 =
F_120 ( V_1070 ) & V_1071 ;
switch ( V_414 ) {
case V_1072 :
return 0 ;
case V_1074 :
return - V_409 ;
case V_1080 :
return - V_1079 ;
case V_1081 :
return - V_234 ;
case V_1076 :
return - V_1077 ;
default:
F_41 ( V_414 ) ;
return 0 ;
}
}
int F_162 ( struct V_1 * V_2 , T_1 V_1082 , T_1 * V_21 )
{
int V_1083 ;
F_96 ( ! F_382 ( & V_2 -> V_57 . V_58 ) ) ;
if ( F_120 ( V_1070 ) & V_1084 ) {
F_10 ( L_110 ) ;
return - V_1085 ;
}
F_122 ( V_1086 , * V_21 ) ;
F_122 ( V_1087 , 0 ) ;
F_122 ( V_1070 , V_1084 | V_1082 ) ;
if ( F_518 ( V_2 ,
V_1070 , V_1084 , 0 ,
500 , 0 , NULL ) ) {
F_19 ( L_111 , V_1082 ) ;
return - V_1079 ;
}
* V_21 = F_120 ( V_1086 ) ;
F_122 ( V_1086 , 0 ) ;
if ( F_145 ( V_2 ) > 6 )
V_1083 = F_517 ( V_2 ) ;
else
V_1083 = F_516 ( V_2 ) ;
if ( V_1083 ) {
F_10 ( L_112 ,
V_1083 ) ;
return V_1083 ;
}
return 0 ;
}
int F_206 ( struct V_1 * V_2 ,
T_1 V_1082 , T_1 V_21 )
{
int V_1083 ;
F_96 ( ! F_382 ( & V_2 -> V_57 . V_58 ) ) ;
if ( F_120 ( V_1070 ) & V_1084 ) {
F_10 ( L_113 ) ;
return - V_1085 ;
}
F_122 ( V_1086 , V_21 ) ;
F_122 ( V_1087 , 0 ) ;
F_122 ( V_1070 , V_1084 | V_1082 ) ;
if ( F_518 ( V_2 ,
V_1070 , V_1084 , 0 ,
500 , 0 , NULL ) ) {
F_19 ( L_114 , V_1082 ) ;
return - V_1079 ;
}
F_122 ( V_1086 , 0 ) ;
if ( F_145 ( V_2 ) > 6 )
V_1083 = F_517 ( V_2 ) ;
else
V_1083 = F_516 ( V_2 ) ;
if ( V_1083 ) {
F_10 ( L_115 ,
V_1083 ) ;
return V_1083 ;
}
return 0 ;
}
static bool F_519 ( struct V_1 * V_2 , T_1 V_1082 ,
T_1 V_1088 , T_1 V_1089 , T_1 V_1090 ,
T_1 * V_1083 )
{
T_1 V_21 = V_1088 ;
* V_1083 = F_162 ( V_2 , V_1082 , & V_21 ) ;
return * V_1083 || ( ( V_21 & V_1089 ) == V_1090 ) ;
}
int F_208 ( struct V_1 * V_2 , T_1 V_1082 , T_1 V_1088 ,
T_1 V_1089 , T_1 V_1090 , int V_1091 )
{
T_1 V_1083 ;
int V_74 ;
F_96 ( ! F_382 ( & V_2 -> V_57 . V_58 ) ) ;
#define F_520 skl_pcode_try_request(dev_priv, mbox, request, reply_mask, reply, \
&status)
if ( F_520 ) {
V_74 = 0 ;
goto V_225;
}
V_74 = F_521 ( F_520 , V_1091 * 1000 , 10 ) ;
if ( ! V_74 )
goto V_225;
F_13 ( L_116 ) ;
F_48 ( V_1091 > 3 ) ;
F_522 () ;
V_74 = F_319 ( F_520 , 50 ) ;
F_523 () ;
V_225:
return V_74 ? V_74 : V_1083 ;
#undef F_520
}
static int F_524 ( struct V_1 * V_2 , int V_21 )
{
return F_156 ( V_2 -> V_57 . V_798 * ( V_21 - 0xb7 ) , 1000 ) ;
}
static int F_525 ( struct V_1 * V_2 , int V_21 )
{
return F_156 ( 1000 * V_21 , V_2 -> V_57 . V_798 ) + 0xb7 ;
}
static int F_526 ( struct V_1 * V_2 , int V_21 )
{
return F_156 ( V_2 -> V_57 . V_798 * V_21 , 2 * 2 * 1000 ) ;
}
static int F_527 ( struct V_1 * V_2 , int V_21 )
{
return F_156 ( 2 * 1000 * V_21 , V_2 -> V_57 . V_798 ) * 2 ;
}
int F_336 ( struct V_1 * V_2 , int V_21 )
{
if ( F_160 ( V_2 ) )
return F_156 ( V_21 * V_1092 ,
V_709 ) ;
else if ( F_24 ( V_2 ) )
return F_526 ( V_2 , V_21 ) ;
else if ( F_23 ( V_2 ) )
return F_524 ( V_2 , V_21 ) ;
else
return V_21 * V_1092 ;
}
int F_443 ( struct V_1 * V_2 , int V_21 )
{
if ( F_160 ( V_2 ) )
return F_156 ( V_21 * V_709 ,
V_1092 ) ;
else if ( F_24 ( V_2 ) )
return F_527 ( V_2 , V_21 ) ;
else if ( F_23 ( V_2 ) )
return F_525 ( V_2 , V_21 ) ;
else
return F_156 ( V_21 , V_1092 ) ;
}
static void F_528 ( struct V_885 * V_661 )
{
struct V_1093 * V_1094 = F_457 ( V_661 , struct V_1093 , V_661 ) ;
struct V_887 * V_888 = V_1094 -> V_888 ;
if ( ! F_529 ( V_888 ) )
F_351 ( V_888 -> V_880 , NULL , V_888 -> V_1095 ) ;
F_530 ( V_888 ) ;
F_531 ( V_1094 ) ;
}
void F_532 ( struct V_887 * V_888 )
{
struct V_1093 * V_1094 ;
if ( V_888 == NULL || F_145 ( V_888 -> V_880 ) < 6 )
return;
if ( F_529 ( V_888 ) )
return;
V_1094 = F_533 ( sizeof( * V_1094 ) , V_1096 ) ;
if ( V_1094 == NULL )
return;
V_1094 -> V_888 = F_534 ( V_888 ) ;
F_535 ( & V_1094 -> V_661 , F_528 ) ;
F_536 ( V_888 -> V_880 -> V_895 , & V_1094 -> V_661 ) ;
}
void F_537 ( struct V_1 * V_2 )
{
F_538 ( & V_2 -> V_57 . V_58 ) ;
F_539 ( & V_2 -> V_57 . V_648 ) ;
F_540 ( & V_2 -> V_57 . V_884 ,
F_456 ) ;
F_541 ( & V_2 -> V_57 . V_649 ) ;
V_2 -> V_1097 . V_1098 = false ;
F_542 ( & V_2 -> V_1097 . V_1099 , 0 ) ;
}
static T_10 F_543 ( struct V_1 * V_2 ,
const T_8 V_134 )
{
T_1 V_1100 , V_1101 , V_26 ;
int V_1102 = 2 ;
F_317 ( & V_2 -> V_259 . V_260 ) ;
F_122 ( V_806 ,
F_31 ( V_807 ) ) ;
V_1101 = F_120 ( V_134 ) ;
do {
V_26 = V_1101 ;
F_122 ( V_806 ,
F_32 ( V_807 ) ) ;
V_1100 = F_120 ( V_134 ) ;
F_122 ( V_806 ,
F_31 ( V_807 ) ) ;
V_1101 = F_120 ( V_134 ) ;
} while ( V_1101 != V_26 && -- V_1102 );
F_323 ( & V_2 -> V_259 . V_260 ) ;
return V_1100 | ( T_10 ) V_1101 << 8 ;
}
T_10 F_544 ( struct V_1 * V_2 ,
const T_8 V_134 )
{
T_10 V_1103 , V_1104 , div ;
if ( ! F_378 () )
return 0 ;
F_442 ( V_2 ) ;
if ( F_23 ( V_2 ) || F_24 ( V_2 ) ) {
V_1104 = 1000 ;
div = V_2 -> V_800 ;
V_1103 = F_543 ( V_2 , V_134 ) ;
} else if ( F_367 ( V_2 ) ) {
V_1104 = 1000 ;
div = 1200 ;
V_1103 = F_3 ( V_134 ) ;
} else {
V_1104 = 128000 ;
div = 100000 ;
V_1103 = F_3 ( V_134 ) ;
}
F_446 ( V_2 ) ;
return F_46 ( V_1103 * V_1104 , div ) ;
}
