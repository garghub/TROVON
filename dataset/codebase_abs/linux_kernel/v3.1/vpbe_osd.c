static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 = V_2 ;
return F_2 ( V_4 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_3 )
{
struct V_1 * V_4 = V_2 ;
F_4 ( V_6 , V_4 -> V_5 + V_3 ) ;
return V_6 ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_3 )
{
struct V_1 * V_4 = V_2 ;
T_1 V_8 = V_4 -> V_5 + V_3 ;
T_1 V_6 = F_2 ( V_8 ) | V_7 ;
F_4 ( V_6 , V_8 ) ;
return V_6 ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_3 )
{
struct V_1 * V_4 = V_2 ;
T_1 V_8 = V_4 -> V_5 + V_3 ;
T_1 V_6 = F_2 ( V_8 ) & ~ V_7 ;
F_4 ( V_6 , V_8 ) ;
return V_6 ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_6 ,
T_1 V_3 )
{
struct V_1 * V_4 = V_2 ;
T_1 V_8 = V_4 -> V_5 + V_3 ;
T_1 V_9 = ( F_2 ( V_8 ) & ~ V_7 ) | ( V_6 & V_7 ) ;
F_4 ( V_9 , V_8 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_10 ,
unsigned long V_11 ,
const struct V_12 * V_13 )
{
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) V_2 -> V_16 -> V_17 ;
if ( V_15 -> V_18 ) {
if ( ! V_10 || ! V_13 -> V_19 ) {
F_3 ( V_2 , V_11 & ~ 0x1F , V_20 ) ;
F_3 ( V_2 , V_11 & ~ 0x1F , V_21 ) ;
F_7 ( V_2 , V_22 | V_23 , 0 ,
V_24 ) ;
return 0 ;
} else {
unsigned V_25 = V_23 ;
F_3 ( V_2 ,
( V_11 & ~ 0x1F ) - V_13 -> V_26 ,
V_20 ) ;
F_3 ( V_2 ,
( V_11 & ~ 0x1F ) + V_13 -> V_26 ,
V_21 ) ;
F_7 ( V_2 ,
V_22 | V_23 , V_25 ,
V_24 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , int V_27 )
{
unsigned V_28 = 0 ;
if ( V_27 )
V_28 = V_29 ;
F_7 ( V_2 , V_29 , V_28 , V_30 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_27 ,
enum V_31 V_32 )
{
T_1 V_33 = 0 ;
if ( V_27 ) {
V_33 |= V_34 ;
V_33 |= V_32 << V_35 ;
}
F_7 ( V_2 , V_36 | V_34 , V_33 ,
V_37 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
enum V_38 V_39 )
{
if ( V_39 == V_40 )
F_6 ( V_2 , V_41 , V_24 ) ;
else
F_5 ( V_2 , V_41 , V_24 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
enum V_42 V_43 ,
unsigned char V_44 ,
unsigned char V_45 ,
enum V_46 V_47 )
{
static const int V_48 [] = { 0 , 5 , 10 , 15 } ;
static const int V_49 [] = { 0 , 15 } ;
int V_50 ;
int V_51 ;
int V_52 ;
int V_53 ;
switch ( V_47 ) {
case V_54 :
V_53 = V_49 [ V_44 & 0x1 ] ;
break;
case V_55 :
V_53 = V_48 [ V_44 & 0x3 ] ;
break;
case V_56 :
V_53 = V_44 & 0xf ;
break;
default:
return;
}
switch ( V_43 ) {
case V_57 :
V_50 = V_58 + ( V_53 >> 1 ) * sizeof( T_1 ) ;
break;
case V_59 :
V_50 = V_60 + ( V_53 >> 1 ) * sizeof( T_1 ) ;
break;
default:
return;
}
if ( V_53 & 1 ) {
V_51 = 8 ;
V_52 = 0xff << 8 ;
} else {
V_51 = 0 ;
V_52 = 0xff ;
}
F_7 ( V_2 , V_52 , V_45 << V_51 , V_50 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
enum V_42 V_43 , int V_27 )
{
switch ( V_43 ) {
case V_57 :
F_7 ( V_2 , V_61 ,
V_27 ? V_61 : 0 ,
V_62 ) ;
break;
case V_59 :
F_7 ( V_2 , V_63 ,
V_27 ? V_63 : 0 ,
V_64 ) ;
break;
}
}
static void F_14 ( struct V_1 * V_2 ,
enum V_42 V_43 ,
enum V_65 V_66 )
{
switch ( V_43 ) {
case V_57 :
F_7 ( V_2 , V_67 ,
V_66 << V_68 , V_62 ) ;
break;
case V_59 :
F_7 ( V_2 , V_69 ,
V_66 << V_70 , V_64 ) ;
break;
}
}
static void F_15 ( struct V_1 * V_2 ,
enum V_42 V_43 ,
unsigned V_71 ,
enum V_46 V_47 )
{
switch ( V_47 ) {
case V_72 :
F_3 ( V_2 , V_71 & V_73 ,
V_74 ) ;
break;
default:
break;
}
switch ( V_43 ) {
case V_57 :
F_5 ( V_2 , V_75 , V_62 ) ;
break;
case V_59 :
F_5 ( V_2 , V_76 , V_64 ) ;
break;
}
}
static void F_16 ( struct V_1 * V_2 ,
enum V_42 V_43 )
{
switch ( V_43 ) {
case V_57 :
F_6 ( V_2 , V_75 , V_62 ) ;
break;
case V_59 :
F_6 ( V_2 , V_76 , V_64 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
enum V_42 V_43 ,
enum V_77 V_78 )
{
T_1 V_79 = 0 ;
switch ( V_43 ) {
case V_57 :
if ( V_78 == V_80 )
V_79 |= V_81 ;
F_7 ( V_2 , V_81 , V_79 , V_62 ) ;
break;
case V_59 :
if ( V_78 == V_80 )
V_79 |= V_82 ;
F_7 ( V_2 , V_82 , V_79 , V_64 ) ;
break;
}
}
static void F_18 ( struct V_1 * V_2 , enum V_83 V_84 ,
enum V_85 V_86 ,
enum V_85 V_87 )
{
T_1 V_79 = 0 ;
switch ( V_84 ) {
case V_88 :
V_79 |= ( V_86 << V_89 ) ;
V_79 |= ( V_87 << V_90 ) ;
F_7 ( V_2 , V_91 | V_92 , V_79 ,
V_62 ) ;
break;
case V_93 :
V_79 |= ( V_86 << V_94 ) ;
V_79 |= ( V_87 << V_95 ) ;
F_7 ( V_2 , V_96 | V_97 , V_79 ,
V_98 ) ;
break;
case V_99 :
V_79 |= ( V_86 << V_100 ) ;
V_79 |= ( V_87 << V_101 ) ;
F_7 ( V_2 , V_102 | V_103 , V_79 ,
V_64 ) ;
break;
case V_104 :
V_79 |= ( V_86 << V_105 ) ;
V_79 |= ( V_87 << V_106 ) ;
F_7 ( V_2 , V_107 | V_108 , V_79 ,
V_98 ) ;
break;
}
}
static void F_19 ( struct V_1 * V_2 , enum V_83 V_84 )
{
switch ( V_84 ) {
case V_88 :
F_6 ( V_2 , V_109 , V_62 ) ;
break;
case V_93 :
F_6 ( V_2 , V_110 , V_98 ) ;
break;
case V_99 :
F_6 ( V_2 , V_111 | V_112 ,
V_64 ) ;
break;
case V_104 :
F_6 ( V_2 , V_113 , V_98 ) ;
break;
}
}
static void F_20 ( struct V_1 * V_2 , enum V_83 V_84 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
unsigned long V_116 ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
if ( ! V_115 -> V_118 ) {
F_22 ( & V_4 -> V_117 , V_116 ) ;
return;
}
V_115 -> V_118 = 0 ;
F_19 ( V_2 , V_84 ) ;
F_22 ( & V_4 -> V_117 , V_116 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_111 , V_64 ) ;
}
static void F_24 ( struct V_1 * V_2 , enum V_83 V_84 )
{
switch ( V_84 ) {
case V_88 :
F_5 ( V_2 , V_109 , V_62 ) ;
break;
case V_93 :
F_5 ( V_2 , V_110 , V_98 ) ;
break;
case V_99 :
F_7 ( V_2 , V_111 | V_112 ,
V_112 , V_64 ) ;
break;
case V_104 :
F_5 ( V_2 , V_113 , V_98 ) ;
break;
}
}
static int F_25 ( struct V_1 * V_2 , enum V_83 V_84 ,
int V_119 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
struct V_12 * V_120 = & V_115 -> V_13 ;
unsigned long V_116 ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
if ( ! V_119 && ( ! V_115 -> V_121 ||
! V_115 -> V_11 ||
! V_120 -> V_26 ||
! V_120 -> V_122 ||
! V_120 -> V_123 ) ) {
F_22 ( & V_4 -> V_117 , V_116 ) ;
return - 1 ;
}
if ( V_115 -> V_118 ) {
F_22 ( & V_4 -> V_117 , V_116 ) ;
return 0 ;
}
V_115 -> V_118 = 1 ;
if ( V_120 -> V_47 != V_124 )
F_24 ( V_2 , V_84 ) ;
else {
F_23 ( V_2 ) ;
F_10 ( V_2 , V_4 -> V_125 , V_4 -> V_32 ) ;
}
F_22 ( & V_4 -> V_117 , V_116 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , enum V_83 V_84 ,
unsigned long V_11 ,
unsigned long V_126 )
{
switch ( V_84 ) {
case V_88 :
F_3 ( V_2 , V_11 & ~ 0x1F , V_127 ) ;
break;
case V_93 :
F_3 ( V_2 , V_11 & ~ 0x1F , V_20 ) ;
break;
case V_99 :
F_3 ( V_2 , V_11 & ~ 0x1F , V_128 ) ;
break;
case V_104 :
F_3 ( V_2 , V_11 & ~ 0x1F , V_129 ) ;
break;
}
}
static void F_27 ( struct V_1 * V_2 , enum V_83 V_84 ,
unsigned long V_11 ,
unsigned long V_126 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
struct V_12 * V_120 = & V_115 -> V_13 ;
unsigned long V_116 ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
V_115 -> V_11 = V_11 & ~ 0x1F ;
F_26 ( V_2 , V_84 , V_11 , V_126 ) ;
if ( V_84 == V_93 ) {
V_4 -> V_130 =
F_8 ( V_2 , V_4 -> V_10 ,
V_115 -> V_11 ,
V_120 ) ;
}
F_22 ( & V_4 -> V_117 , V_116 ) ;
}
static void F_28 ( struct V_1 * V_2 , enum V_83 V_84 ,
struct V_12 * V_13 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
unsigned long V_116 ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
* V_13 = V_115 -> V_13 ;
F_22 ( & V_4 -> V_117 , V_116 ) ;
}
static int F_29 ( struct V_1 * V_2 , enum V_83 V_84 ,
struct V_12 * V_13 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
int V_131 ;
switch ( V_13 -> V_47 ) {
case V_54 :
case V_55 :
case V_56 :
case V_132 :
case V_72 :
V_131 = ! F_30 ( V_84 ) ;
break;
case V_133 :
case V_134 :
V_131 = ! F_31 ( V_84 ) ;
break;
case V_135 :
V_131 = ! F_31 ( V_84 ) ;
break;
case V_136 :
V_131 = 1 ;
break;
case V_124 :
V_131 = ( V_84 != V_99 ) ;
break;
default:
V_131 = 1 ;
break;
}
if ( V_131 ) {
* V_13 = V_115 -> V_13 ;
return V_131 ;
}
if ( F_30 ( V_84 ) && F_32 ( V_13 -> V_47 ) ) {
enum V_46 V_47 ;
if ( V_84 == V_88 )
V_47 = V_4 -> V_115 [ V_99 ] . V_13 . V_47 ;
else
V_47 = V_4 -> V_115 [ V_88 ] . V_13 . V_47 ;
if ( F_32 ( V_47 ) ) {
* V_13 = V_115 -> V_13 ;
return 1 ;
}
}
if ( F_31 ( V_84 ) && V_13 -> V_47 == V_135 ) {
enum V_46 V_47 ;
if ( V_84 == V_93 )
V_47 = V_4 -> V_115 [ V_104 ] . V_13 . V_47 ;
else
V_47 = V_4 -> V_115 [ V_93 ] . V_13 . V_47 ;
if ( V_47 == V_135 ) {
* V_13 = V_115 -> V_13 ;
return 1 ;
}
}
if ( ! V_13 -> V_26 || ! V_13 -> V_122 || ! V_13 -> V_123 ) {
* V_13 = V_115 -> V_13 ;
return 1 ;
}
V_13 -> V_26 = ( ( V_13 -> V_26 + 31 ) / 32 ) * 32 ;
V_13 -> V_26 =
F_33 ( V_13 -> V_26 , ( unsigned ) V_137 ) ;
V_13 -> V_122 = F_33 ( V_13 -> V_122 , ( unsigned ) V_138 ) ;
V_13 -> V_123 = F_33 ( V_13 -> V_123 , ( unsigned ) V_138 ) ;
V_13 -> V_139 = F_33 ( V_13 -> V_139 , ( unsigned ) V_138 ) ;
V_13 -> V_140 = F_33 ( V_13 -> V_140 , ( unsigned ) V_138 ) ;
V_13 -> V_19 = ( V_13 -> V_19 != 0 ) ;
if ( V_13 -> V_19 ) {
V_13 -> V_123 &= ~ 1 ;
V_13 -> V_140 &= ~ 1 ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_141 , V_24 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
enum V_83 V_84 )
{
if ( V_84 == V_93 ) {
F_7 ( V_2 , V_141 | V_142 ,
V_141 , V_24 ) ;
} else if ( V_84 == V_104 ) {
F_7 ( V_2 , V_141 | V_142 ,
V_141 | V_142 ,
V_24 ) ;
}
}
static void F_36 ( struct V_1 * V_2 ,
enum V_46 V_47 )
{
if ( V_47 == V_133 )
F_6 ( V_2 , V_143 , V_30 ) ;
else if ( V_47 == V_134 )
F_5 ( V_2 , V_143 , V_30 ) ;
}
static void F_37 ( struct V_1 * V_2 , enum V_83 V_84 ,
const struct V_12 * V_13 )
{
T_1 V_79 = 0 , V_144 = 0 , V_145 = 0 ;
F_36 ( V_2 , V_13 -> V_47 ) ;
switch ( V_84 ) {
case V_88 :
V_144 |= V_146 ;
if ( V_13 -> V_47 == V_72 )
V_79 |= V_146 ;
V_144 |= V_147 | V_148 ;
switch ( V_13 -> V_47 ) {
case V_54 :
V_145 = 0 ;
break;
case V_55 :
V_145 = 1 ;
break;
case V_56 :
V_145 = 2 ;
break;
case V_132 :
V_145 = 3 ;
break;
default:
break;
}
V_79 |= ( V_145 << V_149 ) ;
if ( V_13 -> V_19 )
V_79 |= V_148 ;
F_7 ( V_2 , V_144 , V_79 , V_62 ) ;
F_3 ( V_2 , V_13 -> V_26 >> 5 , V_150 ) ;
F_3 ( V_2 , V_13 -> V_139 , V_151 ) ;
F_3 ( V_2 , V_13 -> V_122 , V_152 ) ;
if ( V_13 -> V_19 ) {
F_3 ( V_2 , V_13 -> V_140 >> 1 , V_153 ) ;
F_3 ( V_2 , V_13 -> V_123 >> 1 , V_154 ) ;
} else {
F_3 ( V_2 , V_13 -> V_140 , V_153 ) ;
F_3 ( V_2 , V_13 -> V_123 , V_154 ) ;
}
break;
case V_93 :
V_144 |= V_155 ;
if ( V_13 -> V_19 )
V_79 |= V_155 ;
F_7 ( V_2 , V_144 , V_79 , V_98 ) ;
F_3 ( V_2 , V_13 -> V_26 >> 5 , V_156 ) ;
F_3 ( V_2 , V_13 -> V_139 , V_157 ) ;
F_3 ( V_2 , V_13 -> V_122 , V_158 ) ;
if ( V_13 -> V_19 ) {
F_3 ( V_2 , V_13 -> V_140 >> 1 , V_159 ) ;
F_3 ( V_2 , V_13 -> V_123 >> 1 , V_160 ) ;
} else {
F_3 ( V_2 , V_13 -> V_140 , V_159 ) ;
F_3 ( V_2 , V_13 -> V_123 , V_160 ) ;
}
break;
case V_99 :
if ( V_13 -> V_47 == V_124 ) {
V_144 |=
V_63 | V_161 |
V_82 |
V_69 | V_76 ;
} else {
V_144 |= V_161 ;
if ( V_13 -> V_47 == V_72 )
V_79 |= V_161 ;
V_144 |= V_162 ;
switch ( V_13 -> V_47 ) {
case V_54 :
V_145 = 0 ;
break;
case V_55 :
V_145 = 1 ;
break;
case V_56 :
V_145 = 2 ;
break;
case V_132 :
V_145 = 3 ;
break;
default:
break;
}
V_79 |= ( V_145 << V_163 ) ;
}
V_144 |= V_164 ;
if ( V_13 -> V_19 )
V_79 |= V_164 ;
F_7 ( V_2 , V_144 , V_79 , V_64 ) ;
F_3 ( V_2 , V_13 -> V_26 >> 5 , V_165 ) ;
F_3 ( V_2 , V_13 -> V_139 , V_166 ) ;
F_3 ( V_2 , V_13 -> V_122 , V_167 ) ;
if ( V_13 -> V_19 ) {
F_3 ( V_2 , V_13 -> V_140 >> 1 , V_168 ) ;
F_3 ( V_2 , V_13 -> V_123 >> 1 , V_169 ) ;
} else {
F_3 ( V_2 , V_13 -> V_140 , V_168 ) ;
F_3 ( V_2 , V_13 -> V_123 , V_169 ) ;
}
break;
case V_104 :
V_144 |= V_170 ;
if ( V_13 -> V_19 )
V_79 |= V_170 ;
F_7 ( V_2 , V_144 , V_79 , V_98 ) ;
F_3 ( V_2 , V_13 -> V_26 >> 5 , V_171 ) ;
F_3 ( V_2 , V_13 -> V_139 , V_172 ) ;
F_3 ( V_2 , V_13 -> V_122 , V_173 ) ;
F_7 ( V_2 , V_174 , ~ V_174 ,
V_24 ) ;
if ( V_13 -> V_19 ) {
F_3 ( V_2 , V_13 -> V_140 >> 1 , V_175 ) ;
F_3 ( V_2 , V_13 -> V_123 >> 1 , V_176 ) ;
} else {
F_3 ( V_2 , V_13 -> V_140 , V_175 ) ;
F_3 ( V_2 , V_13 -> V_123 , V_176 ) ;
}
break;
}
}
static int F_38 ( struct V_1 * V_2 , enum V_83 V_84 ,
struct V_12 * V_13 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
struct V_12 * V_120 = & V_115 -> V_13 ;
unsigned long V_116 ;
int V_177 ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
V_177 = F_29 ( V_2 , V_84 , V_13 ) ;
if ( V_177 ) {
F_22 ( & V_4 -> V_117 , V_116 ) ;
return V_177 ;
}
if ( F_39 ( V_13 -> V_47 ) )
V_4 -> V_178 = V_13 -> V_47 ;
if ( V_84 == V_99 ) {
if ( ( ( V_13 -> V_47 == V_124 ) &&
( V_120 -> V_47 != V_124 ) ) ||
( ( V_13 -> V_47 != V_124 ) &&
( V_120 -> V_47 == V_124 ) ) ) {
V_115 -> V_118 = 0 ;
F_19 ( V_2 , V_84 ) ;
}
}
F_37 ( V_2 , V_84 , V_13 ) ;
if ( V_84 == V_99 ) {
struct V_179 * V_180 =
& V_4 -> V_43 [ V_59 ] ;
if ( ( V_13 -> V_47 != V_124 ) &&
( V_120 -> V_47 == V_124 ) ) {
F_17 ( V_2 , V_59 ,
V_180 -> V_78 ) ;
F_14 ( V_2 , V_59 ,
V_180 -> V_66 ) ;
if ( V_180 -> V_181 ) {
F_15 ( V_2 , V_59 ,
V_180 ->
V_71 ,
V_13 -> V_47 ) ;
} else
F_16 ( V_2 , V_59 ) ;
F_13 ( V_2 , V_59 ,
V_180 ->
V_182 ) ;
} else if ( ( V_13 -> V_47 == V_124 ) &&
( V_120 -> V_47 != V_124 ) ) {
F_10 ( V_2 , V_4 -> V_125 ,
V_4 -> V_32 ) ;
}
}
if ( ( V_13 -> V_47 != V_120 -> V_47 ) &&
( ( V_13 -> V_47 == V_54 ) ||
( V_13 -> V_47 == V_55 ) ||
( V_13 -> V_47 == V_56 ) ) ) {
enum V_42 V_43 =
( ( V_84 == V_88 ) ? V_57 : V_59 ) ;
struct V_179 * V_180 =
& V_4 -> V_43 [ V_43 ] ;
unsigned char V_45 ;
unsigned char V_183 = 0 ;
switch ( V_13 -> V_47 ) {
case V_54 :
V_183 = 2 ;
break;
case V_55 :
V_183 = 4 ;
break;
case V_56 :
V_183 = 16 ;
break;
default:
break;
}
for ( V_45 = 0 ; V_45 < 16 ; V_45 ++ ) {
V_180 -> V_184 [ V_45 ] = V_45 ;
if ( V_45 < V_183 ) {
F_12 ( V_2 , V_43 , V_45 ,
V_45 ,
V_13 -> V_47 ) ;
}
}
}
* V_120 = * V_13 ;
if ( V_4 -> V_115 [ V_93 ] . V_13 . V_47 == V_135 )
F_35 ( V_2 , V_93 ) ;
else if ( V_4 -> V_115 [ V_104 ] . V_13 . V_47 == V_135 )
F_35 ( V_2 , V_104 ) ;
else
F_34 ( V_2 ) ;
if ( V_84 == V_93 ) {
V_4 -> V_130 =
F_8 ( V_2 , V_4 -> V_10 ,
V_115 -> V_11 ,
V_120 ) ;
}
F_22 ( & V_4 -> V_117 , V_116 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , enum V_83 V_84 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
enum V_42 V_43 ;
struct V_179 * V_180 ;
struct V_12 * V_120 = & V_115 -> V_13 ;
unsigned long V_116 ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
V_115 -> V_118 = 0 ;
F_19 ( V_2 , V_84 ) ;
V_115 -> V_86 = V_185 ;
V_115 -> V_87 = V_185 ;
F_18 ( V_2 , V_84 , V_115 -> V_86 , V_115 -> V_87 ) ;
V_115 -> V_11 = 0 ;
F_26 ( V_2 , V_84 , V_115 -> V_11 , 0 ) ;
V_120 -> V_26 = 0 ;
V_120 -> V_122 = 0 ;
V_120 -> V_123 = 0 ;
V_120 -> V_139 = 0 ;
V_120 -> V_140 = 0 ;
V_120 -> V_19 = 0 ;
switch ( V_84 ) {
case V_88 :
case V_99 :
V_43 = ( V_84 == V_88 ) ? V_57 : V_59 ;
V_180 = & V_4 -> V_43 [ V_43 ] ;
V_120 -> V_47 = V_132 ;
F_37 ( V_2 , V_84 , V_120 ) ;
V_180 -> V_78 = V_80 ;
F_17 ( V_2 , V_43 , V_180 -> V_78 ) ;
V_180 -> V_181 = 0 ;
F_16 ( V_2 , V_43 ) ;
V_180 -> V_66 = V_186 ;
F_14 ( V_2 , V_43 , V_180 -> V_66 ) ;
V_180 -> V_182 = 0 ;
F_13 ( V_2 , V_43 ,
V_180 ->
V_182 ) ;
if ( V_43 == V_59 ) {
V_4 -> V_125 = 0 ;
V_4 -> V_32 = V_187 ;
}
break;
case V_93 :
case V_104 :
V_120 -> V_47 = V_4 -> V_178 ;
F_37 ( V_2 , V_84 , V_120 ) ;
break;
}
F_22 ( & V_4 -> V_117 , V_116 ) ;
}
static void F_41 ( struct V_1 * V_2 , enum V_83 V_84 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
unsigned long V_116 ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
if ( ! V_115 -> V_121 ) {
F_22 ( & V_4 -> V_117 , V_116 ) ;
return;
}
F_22 ( & V_4 -> V_117 , V_116 ) ;
F_40 ( V_2 , V_84 ) ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
V_115 -> V_121 = 0 ;
F_22 ( & V_4 -> V_117 , V_116 ) ;
}
static int F_42 ( struct V_1 * V_2 , enum V_83 V_84 )
{
struct V_1 * V_4 = V_2 ;
struct V_114 * V_115 = & V_4 -> V_115 [ V_84 ] ;
unsigned long V_116 ;
F_21 ( & V_4 -> V_117 , V_116 ) ;
if ( V_115 -> V_121 ) {
F_22 ( & V_4 -> V_117 , V_116 ) ;
return - 1 ;
}
V_115 -> V_121 = 1 ;
F_22 ( & V_4 -> V_117 , V_116 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0 , V_30 ) ;
F_3 ( V_2 , 0 , V_98 ) ;
F_3 ( V_2 , 0 , V_62 ) ;
F_3 ( V_2 , 0 , V_64 ) ;
F_3 ( V_2 , 0 , V_188 ) ;
F_3 ( V_2 , 0 , V_24 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_6 )
{
F_3 ( V_2 , V_6 , V_189 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_6 )
{
F_3 ( V_2 , V_6 , V_190 ) ;
}
static int F_46 ( struct V_1 * V_4 )
{
if ( V_4 == NULL )
return - V_191 ;
F_43 ( V_4 ) ;
V_4 -> V_178 = V_133 ;
F_9 ( V_4 , V_4 -> V_10 ) ;
F_11 ( V_4 , V_4 -> V_39 ) ;
F_40 ( V_4 , V_88 ) ;
F_40 ( V_4 , V_93 ) ;
F_40 ( V_4 , V_99 ) ;
F_40 ( V_4 , V_104 ) ;
return 0 ;
}
static int F_47 ( struct V_192 * V_193 )
{
struct V_14 * V_15 ;
struct V_1 * V_4 ;
struct V_194 * V_195 ;
int V_196 = 0 ;
V_4 = F_48 ( sizeof( struct V_1 ) , V_197 ) ;
if ( V_4 == NULL )
return - V_198 ;
V_4 -> V_16 = & V_193 -> V_16 ;
V_15 = (struct V_14 * ) V_193 -> V_16 . V_17 ;
V_4 -> V_199 = (enum V_200 ) V_15 -> V_199 ;
if ( NULL == V_193 -> V_16 . V_17 ) {
F_49 ( V_4 -> V_16 , L_1
L_2 ) ;
V_196 = - V_201 ;
goto V_202;
}
V_195 = F_50 ( V_193 , V_203 , 0 ) ;
if ( ! V_195 ) {
F_49 ( V_4 -> V_16 , L_3 ) ;
V_196 = - V_191 ;
goto V_202;
}
V_4 -> V_204 = V_195 -> V_205 ;
V_4 -> V_206 = V_195 -> V_207 - V_195 -> V_205 + 1 ;
if ( ! F_51 ( V_4 -> V_204 , V_4 -> V_206 ,
V_208 ) ) {
F_49 ( V_4 -> V_16 , L_4 ) ;
V_196 = - V_191 ;
goto V_202;
}
V_4 -> V_5 = ( unsigned long ) F_52 ( V_195 -> V_205 ,
V_4 -> V_206 ) ;
if ( ! V_4 -> V_5 ) {
F_49 ( V_4 -> V_16 , L_5 ) ;
V_196 = - V_191 ;
goto V_209;
}
F_53 ( & V_4 -> V_117 ) ;
V_4 -> V_210 = V_211 ;
F_54 ( V_193 , V_4 ) ;
F_55 ( V_4 -> V_16 , L_6 ) ;
return V_196 ;
V_209:
V_209 ( V_4 -> V_204 , V_4 -> V_206 ) ;
V_202:
F_56 ( V_4 ) ;
return V_196 ;
}
static int F_57 ( struct V_192 * V_193 )
{
struct V_1 * V_4 = F_58 ( V_193 ) ;
F_59 ( ( void * ) V_4 -> V_5 ) ;
V_209 ( V_4 -> V_204 , V_4 -> V_206 ) ;
F_56 ( V_4 ) ;
return 0 ;
}
static int F_60 ( void )
{
if ( F_61 ( & V_212 ) ) {
F_62 ( V_213 L_7 ) ;
return - V_191 ;
}
return 0 ;
}
static void F_63 ( void )
{
F_64 ( & V_212 ) ;
}
