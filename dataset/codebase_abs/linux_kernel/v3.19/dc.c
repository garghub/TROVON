static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , unsigned int V_7 )
{
T_1 V_8 = V_9 << V_7 ;
F_4 ( V_6 , V_8 << 8 , V_10 ) ;
F_4 ( V_6 , V_8 , V_10 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
F_4 ( V_6 , V_11 << 8 , V_10 ) ;
F_4 ( V_6 , V_11 , V_10 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
F_4 ( V_6 , V_12 << 8 , V_10 ) ;
F_4 ( V_6 , V_12 , V_10 ) ;
}
static unsigned int F_7 ( T_2 V_13 , T_2 * V_14 )
{
if ( V_14 )
* V_14 = V_15 ;
switch ( V_13 ) {
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
if ( V_14 )
* V_14 = V_25 ;
return V_23 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
default:
break;
}
F_8 ( 1 , L_1 , V_13 ) ;
return V_19 ;
}
static bool F_9 ( unsigned int V_13 , bool * V_30 )
{
switch ( V_13 ) {
case V_23 :
case V_31 :
if ( V_30 )
* V_30 = false ;
return true ;
case V_27 :
case V_32 :
case V_29 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
if ( V_30 )
* V_30 = true ;
return true ;
}
return false ;
}
static inline T_1 F_10 ( unsigned int V_38 , unsigned int V_39 , bool V_40 ,
unsigned int V_41 )
{
T_3 V_42 = F_11 ( V_39 ) ;
T_3 V_43 = F_11 ( V_38 ) ;
T_1 V_44 ;
int V_45 ;
if ( V_40 )
V_45 = 15 ;
else {
switch ( V_41 ) {
case 2 :
V_45 = 8 ;
break;
default:
F_12 ( 1 ) ;
case 4 :
V_45 = 4 ;
break;
}
}
V_42 . V_46 = F_13 ( T_1 , V_42 . V_46 - F_14 ( 1 ) , F_14 ( 1 ) ) ;
V_43 . V_46 -= F_14 ( 1 ) ;
V_44 = F_15 ( V_43 , V_42 ) ;
V_44 = F_16 ( T_1 , V_44 , F_14 ( V_45 ) ) ;
return V_44 ;
}
static inline T_1 F_17 ( unsigned int V_38 )
{
T_3 V_43 = F_11 ( V_38 ) ;
return F_18 ( V_43 ) ;
}
static int F_19 ( struct V_5 * V_6 , unsigned int V_7 ,
const struct V_47 * V_48 )
{
unsigned V_49 , V_50 , V_51 , V_52 , V_53 , V_54 , V_41 ;
unsigned long V_8 , V_55 ;
bool V_56 , V_30 ;
V_56 = F_9 ( V_48 -> V_13 , & V_30 ) ;
if ( ! V_56 )
V_41 = V_48 -> V_57 / 8 ;
else
V_41 = V_30 ? 1 : 2 ;
F_20 ( & V_6 -> V_58 , V_55 ) ;
V_8 = V_59 << V_7 ;
F_4 ( V_6 , V_8 , V_60 ) ;
F_4 ( V_6 , V_48 -> V_13 , V_61 ) ;
F_4 ( V_6 , V_48 -> V_14 , V_62 ) ;
V_8 = F_21 ( V_48 -> V_63 . V_64 ) | F_22 ( V_48 -> V_63 . V_65 ) ;
F_4 ( V_6 , V_8 , V_66 ) ;
V_8 = F_23 ( V_48 -> V_63 . V_67 ) | F_24 ( V_48 -> V_63 . V_68 ) ;
F_4 ( V_6 , V_8 , V_69 ) ;
V_49 = V_48 -> V_70 . V_65 * V_41 ;
V_50 = V_48 -> V_70 . V_64 ;
V_51 = V_48 -> V_70 . V_68 * V_41 ;
V_52 = V_48 -> V_70 . V_67 ;
V_8 = F_25 ( V_52 ) | F_26 ( V_51 ) ;
F_4 ( V_6 , V_8 , V_71 ) ;
if ( V_56 && V_30 )
V_41 = 2 ;
V_53 = F_10 ( V_48 -> V_70 . V_68 , V_48 -> V_63 . V_68 , false , V_41 ) ;
V_54 = F_10 ( V_48 -> V_70 . V_67 , V_48 -> V_63 . V_67 , true , V_41 ) ;
V_8 = F_27 ( V_54 ) | F_28 ( V_53 ) ;
F_4 ( V_6 , V_8 , V_72 ) ;
V_53 = F_17 ( V_48 -> V_70 . V_65 ) ;
V_54 = F_17 ( V_48 -> V_70 . V_64 ) ;
F_4 ( V_6 , V_53 , V_73 ) ;
F_4 ( V_6 , V_54 , V_74 ) ;
F_4 ( V_6 , 0 , V_75 ) ;
F_4 ( V_6 , 0 , V_76 ) ;
F_4 ( V_6 , V_48 -> V_4 [ 0 ] , V_77 ) ;
if ( V_56 && V_30 ) {
F_4 ( V_6 , V_48 -> V_4 [ 1 ] , V_78 ) ;
F_4 ( V_6 , V_48 -> V_4 [ 2 ] , V_79 ) ;
V_8 = V_48 -> V_80 [ 1 ] << 16 | V_48 -> V_80 [ 0 ] ;
F_4 ( V_6 , V_8 , V_81 ) ;
} else {
F_4 ( V_6 , V_48 -> V_80 [ 0 ] , V_81 ) ;
}
if ( V_48 -> V_82 )
V_50 += V_48 -> V_70 . V_67 - 1 ;
F_4 ( V_6 , V_49 , V_83 ) ;
F_4 ( V_6 , V_50 , V_84 ) ;
if ( V_6 -> V_85 -> V_86 ) {
unsigned long V_87 = V_48 -> V_88 . V_8 ;
switch ( V_48 -> V_88 . V_89 ) {
case V_90 :
V_8 = V_91 ;
break;
case V_92 :
V_8 = V_93 ;
break;
case V_94 :
V_8 = F_29 ( V_87 ) |
V_95 ;
break;
}
F_4 ( V_6 , V_8 , V_96 ) ;
} else {
switch ( V_48 -> V_88 . V_89 ) {
case V_90 :
V_8 = V_97 |
V_98 ;
break;
case V_92 :
V_8 = V_99 |
V_100 ;
break;
case V_94 :
F_30 ( L_2 ) ;
F_31 ( & V_6 -> V_58 , V_55 ) ;
return - V_101 ;
}
F_4 ( V_6 , V_8 , V_102 ) ;
}
V_8 = V_103 ;
if ( V_56 ) {
F_4 ( V_6 , 0x00f0 , V_104 ) ;
F_4 ( V_6 , 0x012a , V_105 ) ;
F_4 ( V_6 , 0x0000 , V_106 ) ;
F_4 ( V_6 , 0x0198 , V_107 ) ;
F_4 ( V_6 , 0x039b , V_108 ) ;
F_4 ( V_6 , 0x032f , V_109 ) ;
F_4 ( V_6 , 0x0204 , V_110 ) ;
F_4 ( V_6 , 0x0000 , V_111 ) ;
V_8 |= V_112 ;
} else if ( V_48 -> V_57 < 24 ) {
V_8 |= V_113 ;
}
if ( V_48 -> V_82 )
V_8 |= V_114 ;
F_4 ( V_6 , V_8 , V_115 ) ;
F_4 ( V_6 , 0xffff00 , V_116 ) ;
F_4 ( V_6 , 0xffff00 , V_117 ) ;
switch ( V_7 ) {
case 0 :
F_4 ( V_6 , 0x000000 , V_118 ) ;
F_4 ( V_6 , 0x000000 , V_119 ) ;
F_4 ( V_6 , 0x000000 , V_120 ) ;
break;
case 1 :
F_4 ( V_6 , 0xffff00 , V_118 ) ;
F_4 ( V_6 , 0x000000 , V_119 ) ;
F_4 ( V_6 , 0x000000 , V_120 ) ;
break;
case 2 :
F_4 ( V_6 , 0xffff00 , V_118 ) ;
F_4 ( V_6 , 0xffff00 , V_119 ) ;
F_4 ( V_6 , 0xffff00 , V_120 ) ;
break;
}
F_3 ( V_6 , V_7 ) ;
F_31 ( & V_6 -> V_58 , V_55 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_33 ( V_3 -> V_121 ) ;
struct V_1 * V_122 = F_1 ( V_3 ) ;
unsigned long V_55 ;
T_1 V_8 ;
if ( ! V_3 -> V_121 )
return 0 ;
F_20 ( & V_6 -> V_58 , V_55 ) ;
V_8 = V_59 << V_122 -> V_7 ;
F_4 ( V_6 , V_8 , V_60 ) ;
V_8 = F_34 ( V_6 , V_115 ) ;
V_8 &= ~ V_103 ;
F_4 ( V_6 , V_8 , V_115 ) ;
F_3 ( V_6 , V_122 -> V_7 ) ;
F_31 ( & V_6 -> V_58 , V_55 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_122 = F_1 ( V_3 ) ;
F_36 ( V_3 ) ;
F_37 ( V_122 ) ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_123 * V_121 ,
struct V_124 * V_125 , int V_126 ,
int V_127 , unsigned int V_128 ,
unsigned int V_129 , T_2 V_130 ,
T_2 V_131 , T_2 V_132 ,
T_2 V_133 )
{
struct V_134 * V_135 = F_39 ( V_125 , 0 ) ;
struct V_1 * V_122 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_33 ( V_121 ) ;
struct V_47 V_48 ;
int V_136 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_70 . V_65 = V_130 >> 16 ;
V_48 . V_70 . V_64 = V_131 >> 16 ;
V_48 . V_70 . V_68 = V_132 >> 16 ;
V_48 . V_70 . V_67 = V_133 >> 16 ;
V_48 . V_63 . V_65 = V_126 ;
V_48 . V_63 . V_64 = V_127 ;
V_48 . V_63 . V_68 = V_128 ;
V_48 . V_63 . V_67 = V_129 ;
V_48 . V_13 = F_7 ( V_125 -> V_137 , & V_48 . V_14 ) ;
V_48 . V_57 = V_125 -> V_57 ;
V_48 . V_82 = F_40 ( V_125 ) ;
V_136 = F_41 ( V_125 , & V_48 . V_88 ) ;
if ( V_136 < 0 )
return V_136 ;
V_48 . V_4 [ 0 ] = V_135 -> V_138 + V_125 -> V_139 [ 0 ] ;
V_48 . V_80 [ 0 ] = V_125 -> V_140 [ 0 ] ;
V_136 = F_19 ( V_6 , V_122 -> V_7 , & V_48 ) ;
if ( V_136 < 0 )
return V_136 ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 )
{
F_32 ( V_3 ) ;
F_35 ( V_3 ) ;
}
static struct V_2 * F_43 ( struct V_141 * V_142 ,
struct V_5 * V_6 )
{
struct V_1 * V_3 ;
unsigned int V_143 ;
const T_1 * V_144 ;
int V_136 ;
V_3 = F_44 ( sizeof( * V_3 ) , V_145 ) ;
if ( ! V_3 )
return F_45 ( - V_146 ) ;
V_143 = F_46 ( V_147 ) ;
V_144 = V_147 ;
V_136 = F_47 ( V_142 , & V_3 -> V_4 , 1 << V_6 -> V_148 ,
& V_149 , V_144 ,
V_143 , V_150 ) ;
if ( V_136 < 0 ) {
F_37 ( V_3 ) ;
return F_45 ( V_136 ) ;
}
return & V_3 -> V_4 ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_123 * V_121 ,
struct V_124 * V_125 , int V_126 ,
int V_127 , unsigned int V_128 ,
unsigned int V_129 , T_2 V_130 ,
T_2 V_131 , T_2 V_132 ,
T_2 V_133 )
{
struct V_134 * V_135 = F_39 ( V_125 , 0 ) ;
struct V_5 * V_6 = F_33 ( V_121 ) ;
T_1 V_8 = V_151 ;
if ( ( V_132 >> 16 != V_128 ) || ( V_133 >> 16 != V_129 ) )
return - V_101 ;
if ( V_132 != V_133 )
return - V_101 ;
switch ( V_128 ) {
case 32 :
V_8 |= V_152 ;
break;
case 64 :
V_8 |= V_153 ;
break;
case 128 :
V_8 |= V_154 ;
break;
case 256 :
V_8 |= V_155 ;
break;
default:
return - V_101 ;
}
V_8 |= ( V_135 -> V_138 >> 10 ) & 0x3fffff ;
F_4 ( V_6 , V_8 , V_156 ) ;
#ifdef F_49
V_8 = ( V_135 -> V_138 >> 32 ) & 0x3 ;
F_4 ( V_6 , V_8 , V_157 ) ;
#endif
V_8 = F_34 ( V_6 , V_158 ) ;
V_8 |= V_159 ;
F_4 ( V_6 , V_8 , V_158 ) ;
V_8 = F_34 ( V_6 , V_160 ) ;
V_8 &= ~ V_161 ;
V_8 &= ~ V_162 ;
V_8 |= V_163 ;
V_8 |= V_164 ;
V_8 |= V_165 ;
V_8 |= V_166 ;
F_4 ( V_6 , V_8 , V_160 ) ;
V_8 = ( V_127 & 0x3fff ) << 16 | ( V_126 & 0x3fff ) ;
F_4 ( V_6 , V_8 , V_167 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_33 ( V_3 -> V_121 ) ;
T_1 V_8 ;
if ( ! V_3 -> V_121 )
return 0 ;
V_8 = F_34 ( V_6 , V_158 ) ;
V_8 &= ~ V_159 ;
F_4 ( V_6 , V_8 , V_158 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
static struct V_2 * F_51 ( struct V_141 * V_142 ,
struct V_5 * V_6 )
{
struct V_1 * V_3 ;
unsigned int V_143 ;
const T_1 * V_144 ;
int V_136 ;
V_3 = F_44 ( sizeof( * V_3 ) , V_145 ) ;
if ( ! V_3 )
return F_45 ( - V_146 ) ;
V_143 = F_46 ( V_168 ) ;
V_144 = V_168 ;
V_136 = F_47 ( V_142 , & V_3 -> V_4 , 1 << V_6 -> V_148 ,
& V_169 , V_144 ,
V_143 , V_170 ) ;
if ( V_136 < 0 ) {
F_37 ( V_3 ) ;
return F_45 ( V_136 ) ;
}
return & V_3 -> V_4 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_123 * V_121 ,
struct V_124 * V_125 , int V_126 ,
int V_127 , unsigned int V_128 ,
unsigned int V_129 , T_2 V_130 ,
T_2 V_131 , T_2 V_132 ,
T_2 V_133 )
{
struct V_1 * V_122 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_33 ( V_121 ) ;
struct V_47 V_48 ;
unsigned int V_171 ;
int V_136 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_70 . V_65 = V_130 >> 16 ;
V_48 . V_70 . V_64 = V_131 >> 16 ;
V_48 . V_70 . V_68 = V_132 >> 16 ;
V_48 . V_70 . V_67 = V_133 >> 16 ;
V_48 . V_63 . V_65 = V_126 ;
V_48 . V_63 . V_64 = V_127 ;
V_48 . V_63 . V_68 = V_128 ;
V_48 . V_63 . V_67 = V_129 ;
V_48 . V_13 = F_7 ( V_125 -> V_137 , & V_48 . V_14 ) ;
V_48 . V_57 = V_125 -> V_57 ;
V_48 . V_82 = F_40 ( V_125 ) ;
V_136 = F_41 ( V_125 , & V_48 . V_88 ) ;
if ( V_136 < 0 )
return V_136 ;
for ( V_171 = 0 ; V_171 < F_53 ( V_125 -> V_137 ) ; V_171 ++ ) {
struct V_134 * V_135 = F_39 ( V_125 , V_171 ) ;
V_48 . V_4 [ V_171 ] = V_135 -> V_138 + V_125 -> V_139 [ V_171 ] ;
if ( V_171 >= 2 ) {
if ( V_125 -> V_140 [ V_171 ] != V_48 . V_80 [ 1 ] )
F_30 ( L_3 ) ;
} else {
V_48 . V_80 [ V_171 ] = V_125 -> V_140 [ V_171 ] ;
}
}
return F_19 ( V_6 , V_122 -> V_7 , & V_48 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
F_32 ( V_3 ) ;
F_35 ( V_3 ) ;
}
static struct V_2 * F_55 ( struct V_141 * V_142 ,
struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_1 * V_3 ;
unsigned int V_143 ;
const T_1 * V_144 ;
int V_136 ;
V_3 = F_44 ( sizeof( * V_3 ) , V_145 ) ;
if ( ! V_3 )
return F_45 ( - V_146 ) ;
V_3 -> V_7 = V_7 ;
V_143 = F_46 ( V_172 ) ;
V_144 = V_172 ;
V_136 = F_47 ( V_142 , & V_3 -> V_4 , 1 << V_6 -> V_148 ,
& V_173 , V_144 ,
V_143 , V_174 ) ;
if ( V_136 < 0 ) {
F_37 ( V_3 ) ;
return F_45 ( V_136 ) ;
}
return & V_3 -> V_4 ;
}
static int F_56 ( struct V_141 * V_142 , struct V_5 * V_6 )
{
struct V_2 * V_3 ;
unsigned int V_171 ;
for ( V_171 = 0 ; V_171 < 2 ; V_171 ++ ) {
V_3 = F_55 ( V_142 , V_6 , 1 + V_171 ) ;
if ( F_57 ( V_3 ) )
return F_58 ( V_3 ) ;
}
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , int V_65 , int V_64 ,
struct V_124 * V_125 )
{
struct V_134 * V_135 = F_39 ( V_125 , 0 ) ;
unsigned int V_49 = 0 , V_50 = 0 ;
struct V_175 V_88 ;
unsigned long V_8 , V_55 ;
unsigned int V_13 , V_14 ;
int V_136 ;
V_136 = F_41 ( V_125 , & V_88 ) ;
if ( V_136 < 0 )
return V_136 ;
F_20 ( & V_6 -> V_58 , V_55 ) ;
F_4 ( V_6 , V_59 , V_60 ) ;
V_8 = V_125 -> V_139 [ 0 ] + V_64 * V_125 -> V_140 [ 0 ] +
V_65 * V_125 -> V_57 / 8 ;
F_4 ( V_6 , V_135 -> V_138 + V_8 , V_77 ) ;
F_4 ( V_6 , V_125 -> V_140 [ 0 ] , V_81 ) ;
V_13 = F_7 ( V_125 -> V_137 , & V_14 ) ;
F_4 ( V_6 , V_13 , V_61 ) ;
F_4 ( V_6 , V_14 , V_62 ) ;
if ( V_6 -> V_85 -> V_86 ) {
unsigned long V_87 = V_88 . V_8 ;
switch ( V_88 . V_89 ) {
case V_90 :
V_8 = V_91 ;
break;
case V_92 :
V_8 = V_93 ;
break;
case V_94 :
V_8 = F_29 ( V_87 ) |
V_95 ;
break;
}
F_4 ( V_6 , V_8 , V_96 ) ;
} else {
switch ( V_88 . V_89 ) {
case V_90 :
V_8 = V_97 |
V_98 ;
break;
case V_92 :
V_8 = V_99 |
V_100 ;
break;
case V_94 :
F_30 ( L_2 ) ;
F_31 ( & V_6 -> V_58 , V_55 ) ;
return - V_101 ;
}
F_4 ( V_6 , V_8 , V_102 ) ;
}
if ( F_40 ( V_125 ) ) {
V_8 = F_34 ( V_6 , V_115 ) ;
V_8 |= V_114 ;
F_4 ( V_6 , V_8 , V_115 ) ;
V_50 += V_125 -> V_87 - 1 ;
} else {
V_8 = F_34 ( V_6 , V_115 ) ;
V_8 &= ~ V_114 ;
F_4 ( V_6 , V_8 , V_115 ) ;
}
F_4 ( V_6 , V_49 , V_83 ) ;
F_4 ( V_6 , V_50 , V_84 ) ;
V_8 = V_12 | V_9 ;
F_4 ( V_6 , V_8 << 8 , V_10 ) ;
F_4 ( V_6 , V_8 , V_10 ) ;
F_31 ( & V_6 -> V_58 , V_55 ) ;
return 0 ;
}
void F_60 ( struct V_5 * V_6 )
{
unsigned long V_8 , V_55 ;
F_20 ( & V_6 -> V_58 , V_55 ) ;
V_8 = F_34 ( V_6 , V_176 ) ;
V_8 |= V_177 ;
F_4 ( V_6 , V_8 , V_176 ) ;
F_31 ( & V_6 -> V_58 , V_55 ) ;
}
void F_61 ( struct V_5 * V_6 )
{
unsigned long V_8 , V_55 ;
F_20 ( & V_6 -> V_58 , V_55 ) ;
V_8 = F_34 ( V_6 , V_176 ) ;
V_8 &= ~ V_177 ;
F_4 ( V_6 , V_8 , V_176 ) ;
F_31 ( & V_6 -> V_58 , V_55 ) ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_141 * V_142 = V_6 -> V_4 . V_178 ;
struct V_123 * V_121 = & V_6 -> V_4 ;
unsigned long V_55 , V_4 ;
struct V_134 * V_135 ;
F_20 ( & V_142 -> V_179 , V_55 ) ;
if ( ! V_6 -> V_180 ) {
F_31 ( & V_142 -> V_179 , V_55 ) ;
return;
}
V_135 = F_39 ( V_121 -> V_181 -> V_125 , 0 ) ;
F_20 ( & V_6 -> V_58 , V_55 ) ;
F_4 ( V_6 , V_59 , V_60 ) ;
F_4 ( V_6 , V_182 , V_183 ) ;
V_4 = F_34 ( V_6 , V_77 ) ;
F_4 ( V_6 , 0 , V_183 ) ;
F_31 ( & V_6 -> V_58 , V_55 ) ;
if ( V_4 == V_135 -> V_138 + V_121 -> V_181 -> V_125 -> V_139 [ 0 ] ) {
F_63 ( V_121 , V_6 -> V_180 ) ;
F_64 ( V_121 ) ;
V_6 -> V_180 = NULL ;
}
F_31 ( & V_142 -> V_179 , V_55 ) ;
}
void F_65 ( struct V_123 * V_121 , struct V_184 * V_185 )
{
struct V_5 * V_6 = F_33 ( V_121 ) ;
struct V_141 * V_142 = V_121 -> V_178 ;
unsigned long V_55 ;
F_20 ( & V_142 -> V_179 , V_55 ) ;
if ( V_6 -> V_180 && V_6 -> V_180 -> V_4 . V_186 == V_185 ) {
V_6 -> V_180 -> V_4 . V_187 ( & V_6 -> V_180 -> V_4 ) ;
F_64 ( V_121 ) ;
V_6 -> V_180 = NULL ;
}
F_31 ( & V_142 -> V_179 , V_55 ) ;
}
static int F_66 ( struct V_123 * V_121 , struct V_124 * V_125 ,
struct V_188 * V_180 , T_2 V_189 )
{
unsigned int V_148 = F_67 ( V_121 ) ;
struct V_5 * V_6 = F_33 ( V_121 ) ;
if ( V_6 -> V_180 )
return - V_190 ;
if ( V_180 ) {
V_180 -> V_148 = V_148 ;
V_6 -> V_180 = V_180 ;
F_68 ( V_121 ) ;
}
F_59 ( V_6 , 0 , 0 , V_125 ) ;
V_121 -> V_181 -> V_125 = V_125 ;
return 0 ;
}
static void F_69 ( struct V_123 * V_121 )
{
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
}
static void F_70 ( struct V_123 * V_121 )
{
F_71 ( V_121 ) ;
F_69 ( V_121 ) ;
}
static void F_72 ( struct V_123 * V_121 )
{
struct V_5 * V_6 = F_33 ( V_121 ) ;
struct V_141 * V_142 = V_121 -> V_178 ;
struct V_2 * V_3 ;
F_73 (plane, &drm->mode_config.plane_list) {
if ( V_3 -> V_121 == V_121 ) {
F_32 ( V_3 ) ;
V_3 -> V_121 = NULL ;
if ( V_3 -> V_125 ) {
F_74 ( V_3 -> V_125 ) ;
V_3 -> V_125 = NULL ;
}
}
}
F_75 ( V_121 ) ;
F_6 ( V_6 ) ;
}
static bool F_76 ( struct V_123 * V_121 ,
const struct V_191 * V_89 ,
struct V_191 * V_192 )
{
return true ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_191 * V_89 )
{
unsigned int V_193 = 1 ;
unsigned int V_194 = 1 ;
unsigned long V_8 ;
F_4 ( V_6 , 0x0 , V_195 ) ;
V_8 = ( V_194 << 16 ) | V_193 ;
F_4 ( V_6 , V_8 , V_196 ) ;
V_8 = ( ( V_89 -> V_197 - V_89 -> V_198 ) << 16 ) |
( ( V_89 -> V_199 - V_89 -> V_200 ) << 0 ) ;
F_4 ( V_6 , V_8 , V_201 ) ;
V_8 = ( ( V_89 -> V_202 - V_89 -> V_197 ) << 16 ) |
( ( V_89 -> V_203 - V_89 -> V_199 ) << 0 ) ;
F_4 ( V_6 , V_8 , V_204 ) ;
V_8 = ( ( V_89 -> V_198 - V_89 -> V_205 ) << 16 ) |
( ( V_89 -> V_200 - V_89 -> V_206 ) << 0 ) ;
F_4 ( V_6 , V_8 , V_207 ) ;
V_8 = ( V_89 -> V_205 << 16 ) | V_89 -> V_206 ;
F_4 ( V_6 , V_8 , V_208 ) ;
return 0 ;
}
static int F_78 ( struct V_123 * V_121 ,
struct V_191 * V_89 )
{
unsigned long V_209 = V_89 -> clock * 1000 ;
struct V_5 * V_6 = F_33 ( V_121 ) ;
struct V_210 * V_211 = NULL ;
struct V_212 * V_213 ;
unsigned int div ;
T_1 V_8 ;
long V_136 ;
F_79 (encoder, &crtc->dev->mode_config.encoder_list, head)
if ( V_213 -> V_121 == V_121 ) {
V_211 = F_80 ( V_213 ) ;
break;
}
if ( ! V_211 )
return - V_214 ;
V_136 = F_81 ( V_211 , V_6 -> V_215 , V_209 , & div ) ;
if ( V_136 < 0 ) {
F_82 ( V_6 -> V_178 , L_4 , V_136 ) ;
return V_136 ;
}
F_83 ( L_5 , F_84 ( V_6 -> V_215 ) , div ) ;
V_8 = F_85 ( div ) | V_216 ;
F_4 ( V_6 , V_8 , V_217 ) ;
return 0 ;
}
static int F_86 ( struct V_123 * V_121 ,
struct V_191 * V_89 ,
struct V_191 * V_192 ,
int V_65 , int V_64 , struct V_124 * V_218 )
{
struct V_134 * V_135 = F_39 ( V_121 -> V_181 -> V_125 , 0 ) ;
struct V_5 * V_6 = F_33 ( V_121 ) ;
struct V_47 V_48 ;
T_1 V_8 ;
int V_136 ;
V_136 = F_78 ( V_121 , V_89 ) ;
if ( V_136 ) {
F_82 ( V_6 -> V_178 , L_6 , V_136 ) ;
return V_136 ;
}
F_77 ( V_6 , V_89 ) ;
if ( V_6 -> V_85 -> V_219 ) {
V_8 = F_34 ( V_6 , V_220 ) ;
V_8 &= ~ V_221 ;
F_4 ( V_6 , V_8 , V_220 ) ;
}
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_70 . V_65 = 0 ;
V_48 . V_70 . V_64 = 0 ;
V_48 . V_70 . V_68 = V_89 -> V_206 ;
V_48 . V_70 . V_67 = V_89 -> V_205 ;
V_48 . V_63 . V_65 = 0 ;
V_48 . V_63 . V_64 = 0 ;
V_48 . V_63 . V_68 = V_89 -> V_206 ;
V_48 . V_63 . V_67 = V_89 -> V_205 ;
V_48 . V_13 = F_7 ( V_121 -> V_181 -> V_125 -> V_137 ,
& V_48 . V_14 ) ;
V_48 . V_57 = V_121 -> V_181 -> V_125 -> V_57 ;
V_48 . V_80 [ 0 ] = V_121 -> V_181 -> V_125 -> V_140 [ 0 ] ;
V_48 . V_4 [ 0 ] = V_135 -> V_138 ;
V_136 = F_19 ( V_6 , 0 , & V_48 ) ;
if ( V_136 < 0 )
F_82 ( V_6 -> V_178 , L_7 ) ;
return 0 ;
}
static int F_87 ( struct V_123 * V_121 , int V_65 , int V_64 ,
struct V_124 * V_218 )
{
struct V_5 * V_6 = F_33 ( V_121 ) ;
return F_59 ( V_6 , V_65 , V_64 , V_121 -> V_181 -> V_125 ) ;
}
static void F_88 ( struct V_123 * V_121 )
{
struct V_5 * V_6 = F_33 ( V_121 ) ;
unsigned int V_222 ;
unsigned long V_8 ;
F_75 ( V_121 ) ;
F_89 ( V_6 -> V_223 ) ;
F_90 ( 10000 , 20000 ) ;
if ( V_6 -> V_148 )
V_222 = V_224 ;
else
V_222 = V_225 ;
F_4 ( V_6 , 0x00000100 , V_226 ) ;
F_4 ( V_6 , 0x100 | V_222 , V_227 ) ;
V_8 = V_228 | V_229 | V_230 | V_231 ;
F_4 ( V_6 , V_8 , V_232 ) ;
V_8 = V_228 | V_229 | V_230 |
V_231 | V_233 | V_234 ;
F_4 ( V_6 , V_8 , V_235 ) ;
V_8 = F_91 ( 0 ) | F_92 ( 0x20 ) |
F_93 ( 0x20 ) | F_94 ( 0x20 ) ;
F_4 ( V_6 , V_8 , V_236 ) ;
V_8 = F_91 ( 0 ) | F_92 ( 1 ) |
F_93 ( 1 ) | F_94 ( 1 ) ;
F_4 ( V_6 , V_8 , V_237 ) ;
V_8 = V_177 | V_228 | V_229 | V_230 ;
F_4 ( V_6 , V_8 , V_238 ) ;
V_8 = V_228 | V_229 | V_230 ;
F_4 ( V_6 , V_8 , V_176 ) ;
}
static void F_95 ( struct V_123 * V_121 )
{
struct V_5 * V_6 = F_33 ( V_121 ) ;
F_96 ( V_121 ) ;
F_6 ( V_6 ) ;
}
static void F_97 ( struct V_123 * V_121 )
{
}
static T_4 F_98 ( int V_239 , void * V_240 )
{
struct V_5 * V_6 = V_240 ;
unsigned long V_241 ;
V_241 = F_34 ( V_6 , V_242 ) ;
F_4 ( V_6 , V_241 , V_242 ) ;
if ( V_241 & V_243 ) {
}
if ( V_241 & V_177 ) {
F_99 ( & V_6 -> V_4 ) ;
F_62 ( V_6 ) ;
}
if ( V_241 & ( V_228 | V_229 | V_230 ) ) {
}
return V_244 ;
}
static int F_100 ( struct V_245 * V_246 , void * V_240 )
{
struct V_247 * V_248 = V_246 -> V_249 ;
struct V_5 * V_6 = V_248 -> V_250 -> V_240 ;
#define F_101 ( T_5 ) \
seq_printf(s, "%-40s %#05x %08x\n", #name, name, \
tegra_dc_readl(dc, name))
F_101 ( V_251 ) ;
F_101 ( V_226 ) ;
F_101 ( V_252 ) ;
F_101 ( V_253 ) ;
F_101 ( V_254 ) ;
F_101 ( V_255 ) ;
F_101 ( V_256 ) ;
F_101 ( V_257 ) ;
F_101 ( V_258 ) ;
F_101 ( V_259 ) ;
F_101 ( V_260 ) ;
F_101 ( V_261 ) ;
F_101 ( V_227 ) ;
F_101 ( V_262 ) ;
F_101 ( V_263 ) ;
F_101 ( V_264 ) ;
F_101 ( V_265 ) ;
F_101 ( V_242 ) ;
F_101 ( V_176 ) ;
F_101 ( V_238 ) ;
F_101 ( V_232 ) ;
F_101 ( V_235 ) ;
F_101 ( V_266 ) ;
F_101 ( V_267 ) ;
F_101 ( V_268 ) ;
F_101 ( V_183 ) ;
F_101 ( V_10 ) ;
F_101 ( V_60 ) ;
F_101 ( V_269 ) ;
F_101 ( V_270 ) ;
F_101 ( V_271 ) ;
F_101 ( F_102 ( 0 ) ) ;
F_101 ( F_102 ( 1 ) ) ;
F_101 ( F_102 ( 2 ) ) ;
F_101 ( F_102 ( 3 ) ) ;
F_101 ( F_103 ( 0 ) ) ;
F_101 ( F_103 ( 1 ) ) ;
F_101 ( F_103 ( 2 ) ) ;
F_101 ( F_103 ( 3 ) ) ;
F_101 ( F_104 ( 0 ) ) ;
F_101 ( F_104 ( 1 ) ) ;
F_101 ( F_104 ( 2 ) ) ;
F_101 ( F_104 ( 3 ) ) ;
F_101 ( F_105 ( 0 ) ) ;
F_101 ( F_105 ( 1 ) ) ;
F_101 ( F_105 ( 2 ) ) ;
F_101 ( F_105 ( 3 ) ) ;
F_101 ( F_106 ( 0 ) ) ;
F_101 ( F_106 ( 1 ) ) ;
F_101 ( F_107 ( 0 ) ) ;
F_101 ( F_107 ( 1 ) ) ;
F_101 ( F_107 ( 2 ) ) ;
F_101 ( F_107 ( 3 ) ) ;
F_101 ( F_107 ( 4 ) ) ;
F_101 ( F_107 ( 5 ) ) ;
F_101 ( F_107 ( 6 ) ) ;
F_101 ( V_272 ) ;
F_101 ( V_273 ) ;
F_101 ( V_274 ) ;
F_101 ( V_275 ) ;
F_101 ( V_276 ) ;
F_101 ( V_277 ) ;
F_101 ( V_278 ) ;
F_101 ( V_279 ) ;
F_101 ( V_280 ) ;
F_101 ( V_281 ) ;
F_101 ( V_282 ) ;
F_101 ( V_283 ) ;
F_101 ( V_284 ) ;
F_101 ( V_285 ) ;
F_101 ( V_286 ) ;
F_101 ( V_287 ) ;
F_101 ( V_288 ) ;
F_101 ( V_158 ) ;
F_101 ( V_236 ) ;
F_101 ( V_237 ) ;
F_101 ( V_195 ) ;
F_101 ( V_196 ) ;
F_101 ( V_201 ) ;
F_101 ( V_204 ) ;
F_101 ( V_208 ) ;
F_101 ( V_207 ) ;
F_101 ( V_289 ) ;
F_101 ( V_290 ) ;
F_101 ( V_291 ) ;
F_101 ( V_292 ) ;
F_101 ( V_293 ) ;
F_101 ( V_294 ) ;
F_101 ( V_295 ) ;
F_101 ( V_296 ) ;
F_101 ( V_297 ) ;
F_101 ( V_298 ) ;
F_101 ( V_299 ) ;
F_101 ( V_300 ) ;
F_101 ( V_301 ) ;
F_101 ( V_302 ) ;
F_101 ( V_303 ) ;
F_101 ( V_304 ) ;
F_101 ( V_305 ) ;
F_101 ( V_306 ) ;
F_101 ( V_307 ) ;
F_101 ( V_308 ) ;
F_101 ( V_309 ) ;
F_101 ( V_310 ) ;
F_101 ( V_311 ) ;
F_101 ( V_312 ) ;
F_101 ( V_313 ) ;
F_101 ( V_314 ) ;
F_101 ( V_315 ) ;
F_101 ( V_316 ) ;
F_101 ( V_317 ) ;
F_101 ( V_318 ) ;
F_101 ( V_319 ) ;
F_101 ( V_320 ) ;
F_101 ( V_321 ) ;
F_101 ( V_322 ) ;
F_101 ( V_323 ) ;
F_101 ( V_217 ) ;
F_101 ( V_324 ) ;
F_101 ( V_325 ) ;
F_101 ( V_326 ) ;
F_101 ( V_327 ) ;
F_101 ( V_328 ) ;
F_101 ( V_329 ) ;
F_101 ( V_330 ) ;
F_101 ( V_331 ) ;
F_101 ( V_332 ) ;
F_101 ( V_333 ) ;
F_101 ( V_334 ) ;
F_101 ( V_335 ) ;
F_101 ( V_336 ) ;
F_101 ( V_156 ) ;
F_101 ( V_337 ) ;
F_101 ( V_167 ) ;
F_101 ( V_338 ) ;
F_101 ( V_339 ) ;
F_101 ( V_340 ) ;
F_101 ( V_341 ) ;
F_101 ( V_342 ) ;
F_101 ( V_343 ) ;
F_101 ( V_344 ) ;
F_101 ( V_345 ) ;
F_101 ( V_346 ) ;
F_101 ( V_347 ) ;
F_101 ( V_348 ) ;
F_101 ( V_349 ) ;
F_101 ( V_350 ) ;
F_101 ( V_351 ) ;
F_101 ( V_352 ) ;
F_101 ( F_108 ( 0 ) ) ;
F_101 ( F_108 ( 1 ) ) ;
F_101 ( F_108 ( 2 ) ) ;
F_101 ( F_108 ( 3 ) ) ;
F_101 ( F_108 ( 4 ) ) ;
F_101 ( F_108 ( 5 ) ) ;
F_101 ( F_108 ( 6 ) ) ;
F_101 ( F_108 ( 7 ) ) ;
F_101 ( F_108 ( 8 ) ) ;
F_101 ( V_353 ) ;
F_101 ( V_354 ) ;
F_101 ( F_109 ( 0 ) ) ;
F_101 ( F_109 ( 1 ) ) ;
F_101 ( F_109 ( 2 ) ) ;
F_101 ( F_109 ( 3 ) ) ;
F_101 ( F_109 ( 4 ) ) ;
F_101 ( F_109 ( 5 ) ) ;
F_101 ( F_109 ( 6 ) ) ;
F_101 ( F_109 ( 7 ) ) ;
F_101 ( F_110 ( 0 ) ) ;
F_101 ( F_110 ( 1 ) ) ;
F_101 ( F_110 ( 2 ) ) ;
F_101 ( F_110 ( 3 ) ) ;
F_101 ( V_355 ) ;
F_101 ( V_356 ) ;
F_101 ( V_357 ) ;
F_101 ( V_157 ) ;
F_101 ( V_160 ) ;
F_101 ( V_115 ) ;
F_101 ( V_62 ) ;
F_101 ( V_358 ) ;
F_101 ( V_61 ) ;
F_101 ( V_66 ) ;
F_101 ( V_69 ) ;
F_101 ( V_71 ) ;
F_101 ( V_73 ) ;
F_101 ( V_74 ) ;
F_101 ( V_72 ) ;
F_101 ( V_81 ) ;
F_101 ( V_76 ) ;
F_101 ( V_75 ) ;
F_101 ( V_102 ) ;
F_101 ( V_359 ) ;
F_101 ( V_116 ) ;
F_101 ( V_117 ) ;
F_101 ( V_118 ) ;
F_101 ( V_119 ) ;
F_101 ( V_120 ) ;
F_101 ( V_360 ) ;
F_101 ( V_77 ) ;
F_101 ( V_361 ) ;
F_101 ( V_78 ) ;
F_101 ( V_362 ) ;
F_101 ( V_79 ) ;
F_101 ( V_363 ) ;
F_101 ( V_83 ) ;
F_101 ( V_364 ) ;
F_101 ( V_84 ) ;
F_101 ( V_365 ) ;
F_101 ( V_366 ) ;
F_101 ( V_367 ) ;
F_101 ( V_368 ) ;
F_101 ( V_369 ) ;
#undef F_101
return 0 ;
}
static int F_111 ( struct V_5 * V_6 , struct V_370 * V_371 )
{
unsigned int V_171 ;
char * T_5 ;
int V_136 ;
T_5 = F_112 ( V_145 , L_8 , V_6 -> V_148 ) ;
V_6 -> V_372 = F_113 ( T_5 , V_371 -> V_373 ) ;
F_37 ( T_5 ) ;
if ( ! V_6 -> V_372 )
return - V_146 ;
V_6 -> V_374 = F_114 ( V_374 , sizeof( V_374 ) ,
V_145 ) ;
if ( ! V_6 -> V_374 ) {
V_136 = - V_146 ;
goto remove;
}
for ( V_171 = 0 ; V_171 < F_46 ( V_374 ) ; V_171 ++ )
V_6 -> V_374 [ V_171 ] . V_240 = V_6 ;
V_136 = F_115 ( V_6 -> V_374 ,
F_46 ( V_374 ) ,
V_6 -> V_372 , V_371 ) ;
if ( V_136 < 0 )
goto free;
V_6 -> V_371 = V_371 ;
return 0 ;
free:
F_37 ( V_6 -> V_374 ) ;
V_6 -> V_374 = NULL ;
remove:
F_116 ( V_6 -> V_372 ) ;
V_6 -> V_372 = NULL ;
return V_136 ;
}
static int F_117 ( struct V_5 * V_6 )
{
F_118 ( V_6 -> V_374 , F_46 ( V_374 ) ,
V_6 -> V_371 ) ;
V_6 -> V_371 = NULL ;
F_37 ( V_6 -> V_374 ) ;
V_6 -> V_374 = NULL ;
F_116 ( V_6 -> V_372 ) ;
V_6 -> V_372 = NULL ;
return 0 ;
}
static int F_119 ( struct V_375 * V_376 )
{
struct V_141 * V_142 = F_120 ( V_376 -> V_377 ) ;
struct V_5 * V_6 = F_121 ( V_376 ) ;
struct V_378 * V_379 = V_142 -> V_380 ;
struct V_2 * V_181 = NULL ;
struct V_2 * V_381 = NULL ;
int V_136 ;
if ( V_379 -> V_382 ) {
V_136 = F_122 ( V_379 -> V_382 , V_6 -> V_178 ) ;
if ( V_136 < 0 ) {
F_82 ( V_6 -> V_178 , L_9 ,
V_136 ) ;
return V_136 ;
}
V_6 -> V_382 = V_379 -> V_382 ;
}
V_181 = F_43 ( V_142 , V_6 ) ;
if ( F_57 ( V_181 ) ) {
V_136 = F_58 ( V_181 ) ;
goto V_383;
}
if ( V_6 -> V_85 -> V_384 ) {
V_381 = F_51 ( V_142 , V_6 ) ;
if ( F_57 ( V_381 ) ) {
V_136 = F_58 ( V_381 ) ;
goto V_383;
}
}
V_136 = F_123 ( V_142 , & V_6 -> V_4 , V_181 , V_381 ,
& V_385 ) ;
if ( V_136 < 0 )
goto V_383;
F_124 ( & V_6 -> V_4 , 256 ) ;
F_125 ( & V_6 -> V_4 , & V_386 ) ;
if ( V_6 -> V_85 -> V_387 > V_379 -> V_387 )
V_379 -> V_387 = V_6 -> V_85 -> V_387 ;
V_136 = F_126 ( V_142 , V_6 ) ;
if ( V_136 < 0 && V_136 != - V_214 ) {
F_82 ( V_6 -> V_178 , L_10 , V_136 ) ;
goto V_383;
}
V_136 = F_56 ( V_142 , V_6 ) ;
if ( V_136 < 0 )
goto V_383;
if ( F_127 ( V_388 ) ) {
V_136 = F_111 ( V_6 , V_142 -> V_181 ) ;
if ( V_136 < 0 )
F_82 ( V_6 -> V_178 , L_11 , V_136 ) ;
}
V_136 = F_128 ( V_6 -> V_178 , V_6 -> V_239 , F_98 , 0 ,
F_129 ( V_6 -> V_178 ) , V_6 ) ;
if ( V_136 < 0 ) {
F_82 ( V_6 -> V_178 , L_12 , V_6 -> V_239 ,
V_136 ) ;
goto V_383;
}
return 0 ;
V_383:
if ( V_381 )
F_36 ( V_381 ) ;
if ( V_181 )
F_36 ( V_181 ) ;
if ( V_379 -> V_382 ) {
F_130 ( V_379 -> V_382 , V_6 -> V_178 ) ;
V_6 -> V_382 = NULL ;
}
return V_136 ;
}
static int F_131 ( struct V_375 * V_376 )
{
struct V_5 * V_6 = F_121 ( V_376 ) ;
int V_136 ;
F_132 ( V_6 -> V_178 , V_6 -> V_239 , V_6 ) ;
if ( F_127 ( V_388 ) ) {
V_136 = F_117 ( V_6 ) ;
if ( V_136 < 0 )
F_82 ( V_6 -> V_178 , L_13 , V_136 ) ;
}
V_136 = F_133 ( V_6 ) ;
if ( V_136 ) {
F_82 ( V_6 -> V_178 , L_14 , V_136 ) ;
return V_136 ;
}
if ( V_6 -> V_382 ) {
F_130 ( V_6 -> V_382 , V_6 -> V_178 ) ;
V_6 -> V_382 = NULL ;
}
return 0 ;
}
static int F_134 ( struct V_5 * V_6 )
{
struct V_389 * V_390 ;
T_1 V_8 = 0 ;
int V_136 ;
V_136 = F_135 ( V_6 -> V_178 -> V_391 , L_15 , & V_8 ) ;
if ( V_136 < 0 ) {
F_82 ( V_6 -> V_178 , L_16 ) ;
F_136 (np, tegra_dc_of_match) {
if ( V_390 == V_6 -> V_178 -> V_391 )
break;
V_8 ++ ;
}
}
V_6 -> V_148 = V_8 ;
return 0 ;
}
static int F_137 ( struct V_392 * V_393 )
{
const struct V_394 * V_395 ;
struct V_396 * V_397 ;
struct V_5 * V_6 ;
int V_136 ;
V_6 = F_138 ( & V_393 -> V_178 , sizeof( * V_6 ) , V_145 ) ;
if ( ! V_6 )
return - V_146 ;
V_395 = F_139 ( V_398 , V_393 -> V_178 . V_391 ) ;
if ( ! V_395 )
return - V_214 ;
F_140 ( & V_6 -> V_58 ) ;
F_141 ( & V_6 -> V_399 ) ;
V_6 -> V_178 = & V_393 -> V_178 ;
V_6 -> V_85 = V_395 -> V_240 ;
V_136 = F_134 ( V_6 ) ;
if ( V_136 < 0 )
return V_136 ;
V_6 -> V_215 = F_142 ( & V_393 -> V_178 , NULL ) ;
if ( F_57 ( V_6 -> V_215 ) ) {
F_82 ( & V_393 -> V_178 , L_17 ) ;
return F_58 ( V_6 -> V_215 ) ;
}
V_6 -> V_223 = F_143 ( & V_393 -> V_178 , L_18 ) ;
if ( F_57 ( V_6 -> V_223 ) ) {
F_82 ( & V_393 -> V_178 , L_19 ) ;
return F_58 ( V_6 -> V_223 ) ;
}
if ( V_6 -> V_85 -> V_400 ) {
if ( V_6 -> V_148 == 0 )
V_6 -> V_401 = V_402 ;
else
V_6 -> V_401 = V_403 ;
V_136 = F_144 ( V_6 -> V_401 , V_6 -> V_215 ,
V_6 -> V_223 ) ;
if ( V_136 < 0 ) {
F_82 ( & V_393 -> V_178 , L_20 ,
V_136 ) ;
return V_136 ;
}
} else {
V_136 = F_145 ( V_6 -> V_215 ) ;
if ( V_136 < 0 ) {
F_82 ( & V_393 -> V_178 , L_21 ,
V_136 ) ;
return V_136 ;
}
V_136 = F_89 ( V_6 -> V_223 ) ;
if ( V_136 < 0 ) {
F_82 ( & V_393 -> V_178 , L_22 ,
V_136 ) ;
return V_136 ;
}
}
V_397 = F_146 ( V_393 , V_404 , 0 ) ;
V_6 -> V_397 = F_147 ( & V_393 -> V_178 , V_397 ) ;
if ( F_57 ( V_6 -> V_397 ) )
return F_58 ( V_6 -> V_397 ) ;
V_6 -> V_239 = F_148 ( V_393 , 0 ) ;
if ( V_6 -> V_239 < 0 ) {
F_82 ( & V_393 -> V_178 , L_23 ) ;
return - V_405 ;
}
F_141 ( & V_6 -> V_376 . V_399 ) ;
V_6 -> V_376 . V_406 = & V_407 ;
V_6 -> V_376 . V_178 = & V_393 -> V_178 ;
V_136 = F_149 ( V_6 ) ;
if ( V_136 < 0 && V_136 != - V_214 ) {
F_82 ( & V_393 -> V_178 , L_24 , V_136 ) ;
return V_136 ;
}
V_136 = F_150 ( & V_6 -> V_376 ) ;
if ( V_136 < 0 ) {
F_82 ( & V_393 -> V_178 , L_25 ,
V_136 ) ;
return V_136 ;
}
F_151 ( V_393 , V_6 ) ;
return 0 ;
}
static int F_152 ( struct V_392 * V_393 )
{
struct V_5 * V_6 = F_153 ( V_393 ) ;
int V_136 ;
V_136 = F_154 ( & V_6 -> V_376 ) ;
if ( V_136 < 0 ) {
F_82 ( & V_393 -> V_178 , L_26 ,
V_136 ) ;
return V_136 ;
}
V_136 = F_155 ( V_6 ) ;
if ( V_136 < 0 ) {
F_82 ( & V_393 -> V_178 , L_27 , V_136 ) ;
return V_136 ;
}
F_156 ( V_6 -> V_223 ) ;
if ( V_6 -> V_85 -> V_400 )
F_157 ( V_6 -> V_401 ) ;
F_158 ( V_6 -> V_215 ) ;
return 0 ;
}
