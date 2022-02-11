static void F_1 ( unsigned long V_1 ,
bool V_2 ,
bool V_3 ,
bool V_4 ,
bool V_5 ,
bool V_6 )
{
int V_7 = 0 ;
if ( V_2 )
V_7 |= V_8 ;
if ( V_3 )
V_7 |= V_9 ;
if ( V_4 )
V_7 |= V_10 ;
if ( V_5 )
V_7 |= V_11 ;
if ( V_6 )
V_7 |= V_12 ;
F_2 ( V_7 , V_1 + V_13 ) ;
}
static void F_3 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned long V_19 = V_15 -> V_20 + V_21 ;
F_4 ( V_19 , 1 , 0 , V_22 | V_23 ) ;
F_4 ( V_19 , 1 , 1 , V_24 | V_23 ) ;
F_4 ( V_19 , 1 , 2 , V_24 | V_23 ) ;
F_5 ( 1 ) ;
F_6 ( V_19 , 1 , 2 , V_17 -> V_25 ) ;
F_6 ( V_19 , 1 , 1 , V_17 -> V_26 ) ;
}
static void F_7 ( struct V_14 * V_15 ,
enum V_27 V_28 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0x9 ;
switch ( V_28 ) {
case V_30 :
break;
case V_31 :
V_7 |= V_32 ;
break;
case V_33 :
V_7 |= V_34 ;
break;
}
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_9 ( struct V_14 * V_15 , bool V_35 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0x7 ;
if ( V_35 )
V_7 |= V_36 ;
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_10 ( struct V_14 * V_15 , bool V_37 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0xe ;
if ( V_37 )
V_7 |= V_38 ;
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_11 ( struct V_14 * V_15 ,
enum V_39 V_40 ,
enum V_41 V_42 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 >>= 4 ;
V_7 &= 0xc0 ;
if ( V_40 == V_43 )
V_7 |= V_44 ;
if ( V_42 == V_45 )
V_7 |= V_46 ;
F_2 ( V_7 , V_15 -> V_20 + V_47 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
unsigned long V_48 = V_15 -> V_20 + V_47 ;
F_2 ( 0 , V_48 ) ;
F_2 ( V_49 , V_48 ) ;
F_2 ( 0 , V_48 ) ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_1 ( V_17 -> V_52 , true , true , true ,
true , false ) ;
F_7 ( V_15 , V_30 ) ;
F_10 ( V_15 , false ) ;
F_12 ( V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_53 * V_54 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_55 ;
int error = 0 ;
int V_56 , V_57 ;
int V_58 ;
error |= F_15 ( & V_54 -> V_59 , V_60 ) ;
error |= F_15 ( & V_54 -> V_61 ,
V_62 | V_63 | V_64 ) ;
error |= F_15 ( & V_54 -> V_65 ,
V_62 | V_64 ) ;
error |= F_15 ( & V_54 -> V_66 , V_67 ) ;
error |= F_15 ( & V_54 -> V_68 ,
V_67 | V_69 ) ;
if ( error )
return 1 ;
error |= F_16 ( V_54 -> V_61 ) ;
error |= F_16 ( V_54 -> V_65 ) ;
error |= F_16 ( V_54 -> V_68 ) ;
if ( ( V_54 -> V_65 == V_62 ) &&
! ( ( V_54 -> V_61 == V_62 ) ||
( V_54 -> V_61 == V_63 ) ) )
error |= - V_70 ;
if ( ( V_54 -> V_65 == V_64 ) &&
! ( ( V_54 -> V_61 == V_64 ) ||
( V_54 -> V_61 == V_63 ) ) )
error |= - V_70 ;
if ( error )
return 2 ;
error |= F_17 ( & V_54 -> V_71 , 0 ) ;
if ( V_54 -> V_65 == V_62 )
error |= F_18 ( & V_54 -> V_72 ,
V_73 ) ;
else
error |= F_17 ( & V_54 -> V_72 , 0 ) ;
if ( V_54 -> V_61 == V_62 )
error |= F_18 ( & V_54 -> V_74 ,
V_73 ) ;
else
error |= F_17 ( & V_54 -> V_74 , 0 ) ;
error |= F_17 ( & V_54 -> V_75 ,
V_54 -> V_76 ) ;
if ( V_54 -> V_68 == V_67 )
error |= F_18 ( & V_54 -> V_77 , 1 ) ;
else
error |= F_17 ( & V_54 -> V_77 , 0 ) ;
if ( error )
return 3 ;
if ( V_54 -> V_65 == V_62 ) {
V_55 = V_54 -> V_72 ;
F_19 ( V_78 ,
& V_17 -> V_26 ,
& V_17 -> V_25 ,
& V_54 -> V_72 , V_54 -> V_7 ) ;
if ( V_55 != V_54 -> V_72 )
error ++ ;
}
if ( V_54 -> V_61 == V_62 ) {
unsigned int V_79 ;
unsigned int V_74 ;
unsigned int V_80 ;
V_79 = V_54 -> V_76 * V_54 -> V_72 ;
if ( V_54 -> V_74 != V_79 ) {
if ( V_79 < V_54 -> V_74 ) {
V_80 =
V_54 -> V_74 / V_79 ;
V_74 = V_80 * V_79 ;
if ( V_54 -> V_74 != V_74 ) {
V_54 -> V_74 = V_74 ;
error ++ ;
}
} else {
V_54 -> V_74 = V_79 ;
error ++ ;
}
}
}
if ( error )
return 4 ;
if ( V_54 -> V_81 ) {
V_56 = F_20 ( V_54 -> V_81 [ 0 ] ) ;
V_57 = F_21 ( V_54 -> V_81 [ 0 ] ) ;
if ( V_54 -> V_76 > 1 ) {
for ( V_58 = 0 ; V_58 < V_54 -> V_76 ; V_58 ++ ) {
if ( F_22 ( V_54 -> V_81 [ V_58 ] ) != V_58 ) {
F_23 ( V_15 ,
L_1
L_2 ) ;
error ++ ;
}
if ( F_20 ( V_54 -> V_81 [ V_58 ] ) != V_56 ) {
F_23 ( V_15 ,
L_3 ) ;
error ++ ;
}
if ( F_21 ( V_54 -> V_81 [ V_58 ] ) != V_57 ) {
F_23 ( V_15 ,
L_4 ) ;
error ++ ;
}
}
}
}
if ( error )
return 5 ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_53 * V_82 = & V_51 -> V_83 -> V_54 ;
if ( V_82 -> V_76 > 1 ) {
F_2 ( V_82 -> V_76 - 1 ,
V_15 -> V_20 + V_84 ) ;
F_10 ( V_15 , true ) ;
} else {
F_2 ( F_22 ( V_82 -> V_81 [ 0 ] ) ,
V_15 -> V_20 + V_84 ) ;
F_10 ( V_15 , false ) ;
}
F_2 ( F_20 ( V_82 -> V_81 [ 0 ] ) & V_85 ,
V_15 -> V_20 + V_86 ) ;
if ( V_82 -> V_68 == V_67 ) {
V_17 -> V_87 =
V_82 -> V_77 * V_82 -> V_76 ;
V_17 -> V_88 = 0 ;
} else {
V_17 -> V_87 = 0 ;
V_17 -> V_88 = 1 ;
}
V_17 -> V_89 = 0 ;
if ( V_82 -> V_65 == V_62 ) {
F_7 ( V_15 , V_30 ) ;
F_3 ( V_15 ) ;
F_12 ( V_15 ) ;
F_11 ( V_15 , V_43 ,
V_90 ) ;
F_7 ( V_15 , V_31 ) ;
F_1 ( V_17 -> V_52 , true , true ,
false , true , true ) ;
if ( V_82 -> V_61 == V_62 ) {
V_17 -> V_89 =
( V_82 -> V_74 /
( V_82 -> V_72 *
V_82 -> V_76 ) ) - 1 ;
}
} else {
F_7 ( V_15 , V_33 ) ;
F_12 ( V_15 ) ;
F_11 ( V_15 , V_43 ,
V_90 ) ;
F_1 ( V_17 -> V_52 , true , true ,
false , true , true ) ;
}
V_17 -> V_87 *= ( 1 + V_17 -> V_89 ) ;
V_17 -> V_76 = V_82 -> V_76 ;
V_17 -> V_91 = 0 ;
V_17 -> V_92 =
V_17 -> V_76 * ( 1 + V_17 -> V_89 ) ;
return 0 ;
}
static void F_25 ( struct V_14 * V_15 ,
struct V_50 * V_51 , void * V_93 ,
unsigned int V_94 ,
unsigned int V_95 )
{
unsigned short * V_96 = V_93 ;
unsigned int V_97 = V_51 -> V_97 ;
unsigned int V_98 = ( V_97 + 1 ) >> 1 ;
unsigned int V_99 = ( V_97 == 0xffff ) ? 0 : 4 ;
unsigned int V_100 = V_94 / sizeof( short ) ;
unsigned int V_58 ;
for ( V_58 = 0 ; V_58 < V_100 ; V_58 ++ )
V_96 [ V_58 ] = ( ( V_96 [ V_58 ] >> V_99 ) & V_97 ) ^ V_98 ;
}
static T_1 F_26 ( int V_101 , void * V_102 )
{
struct V_14 * V_15 = V_102 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_50 * V_51 = V_15 -> V_103 ;
struct V_104 * V_83 ;
unsigned int V_105 ;
unsigned long V_106 ;
unsigned char V_107 ;
if ( ! V_15 -> V_108 ) {
return V_109 ;
}
V_83 = V_51 -> V_83 ;
F_27 ( & V_15 -> V_110 , V_106 ) ;
V_107 = F_8 ( V_17 -> V_52 + V_13 ) ;
if ( ! ( ( ( V_107 & V_12 ) != 0 ) &&
( ( ( V_107 & V_111 ) == V_111 ) ||
( ( V_107 & V_112 ) == V_112 ) ) ) ) {
F_28 ( & V_15 -> V_110 , V_106 ) ;
return V_109 ;
}
if ( ( V_107 & V_111 ) == V_111 ) {
V_105 = F_8 ( V_15 -> V_20 + V_86 ) ;
if ( ! ( V_105 & V_113 ) ) {
F_28 ( & V_15 -> V_110 , V_106 ) ;
F_23 ( V_15 , V_114 L_5 ) ;
F_2 ( 0 , V_15 -> V_20 + V_115 ) ;
V_83 -> V_116 |= V_117 | V_118 ;
F_29 ( V_15 , V_51 ) ;
return V_119 ;
}
if ( ! ( V_105 & V_120 ) ) {
unsigned int V_100 ;
unsigned int V_121 = 0 ;
V_100 =
V_122 >
V_17 -> V_87
&& ! V_17 ->
V_88 ? V_17 -> V_87 :
V_122 ;
F_30 ( V_15 -> V_20 + V_123 ,
V_17 -> V_124 , V_100 ) ;
if ( V_17 -> V_89 < 1 ) {
V_121 =
F_31 ( V_51 ,
V_17 ->
V_124 ,
V_100 *
sizeof( short ) ) ;
} else {
int V_125 = 0 ;
int V_126 ;
while ( V_125 < V_100 ) {
if ( V_17 -> V_91 <
V_17 -> V_76 ) {
V_126 =
V_17 -> V_76 -
V_17 -> V_91 ;
if ( V_126 >
V_100 - V_125 )
V_126 =
V_100 -
V_125 ;
V_121 +=
F_31
( V_51 ,
V_17 -> V_124
+ V_125 ,
V_126 * sizeof( short ) ) ;
} else {
V_126 =
V_17 -> V_92
-
V_17 -> V_91 ;
if ( V_126 >
V_100 - V_125 )
V_126 =
V_100 -
V_125 ;
V_121 +=
sizeof( short ) * V_126 ;
}
V_125 += V_126 ;
V_17 -> V_91 += V_126 ;
if ( V_17 -> V_91 >=
V_17 -> V_92 )
V_17 -> V_91 = 0 ;
}
}
V_17 -> V_87 -=
V_121 / sizeof( short ) ;
}
}
if ( V_17 -> V_87 == 0 && ! V_17 -> V_88 )
V_83 -> V_116 |= V_118 ;
F_2 ( 0 , V_15 -> V_20 + V_115 ) ;
F_28 ( & V_15 -> V_110 , V_106 ) ;
F_29 ( V_15 , V_51 ) ;
return V_119 ;
}
static int F_32 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_127 * V_128 ,
unsigned long V_129 )
{
unsigned int V_105 ;
V_105 = F_8 ( V_15 -> V_20 + V_86 ) ;
if ( V_105 & V_130 )
return 0 ;
return - V_131 ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_127 * V_128 , unsigned int * V_93 )
{
unsigned int V_132 = F_22 ( V_128 -> V_133 ) ;
unsigned int V_56 = F_20 ( V_128 -> V_133 ) ;
unsigned int V_97 = V_51 -> V_97 ;
unsigned int V_98 = ( V_97 + 1 ) >> 1 ;
unsigned int V_99 = ( V_97 == 0xffff ) ? 0 : 4 ;
unsigned int V_105 ;
int V_134 ;
int V_58 ;
F_2 ( V_132 , V_15 -> V_20 + V_84 ) ;
V_105 = F_8 ( V_15 -> V_20 + V_86 ) ;
if ( ( V_105 & V_85 ) != V_56 ) {
F_2 ( V_56 & V_85 ,
V_15 -> V_20 + V_86 ) ;
}
F_12 ( V_15 ) ;
for ( V_58 = 0 ; V_58 < V_128 -> V_135 ; V_58 ++ ) {
F_2 ( 0 , V_15 -> V_20 + V_136 ) ;
V_134 = F_34 ( V_15 , V_51 , V_128 , F_32 , 0 ) ;
if ( V_134 ) {
F_12 ( V_15 ) ;
return V_134 ;
}
V_93 [ V_58 ] = F_35 ( V_15 -> V_20 + V_123 ) ;
V_93 [ V_58 ] = ( ( V_93 [ V_58 ] >> V_99 ) & V_97 ) ^ V_98 ;
}
return V_58 ;
}
static int F_36 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_127 * V_128 ,
unsigned int * V_93 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned int V_137 = 0 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_128 -> V_135 ; V_58 ++ ) {
V_137 = V_93 [ V_58 ] ;
F_37 ( V_137 , V_15 -> V_20 + V_138 ) ;
}
V_17 -> V_139 = V_137 ;
return V_128 -> V_135 ;
}
static int F_38 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_127 * V_128 ,
unsigned int * V_93 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_128 -> V_135 ; V_58 ++ )
V_93 [ V_58 ] = V_17 -> V_139 ;
return V_128 -> V_135 ;
}
static int F_39 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_127 * V_128 ,
unsigned int * V_93 )
{
V_93 [ 1 ] = F_35 ( V_15 -> V_20 + V_140 ) ;
return V_128 -> V_135 ;
}
static int F_40 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_127 * V_128 ,
unsigned int * V_93 )
{
if ( F_41 ( V_51 , V_93 ) )
F_37 ( V_51 -> V_141 , V_15 -> V_20 + V_140 ) ;
V_93 [ 1 ] = V_51 -> V_141 ;
return V_128 -> V_135 ;
}
static int F_42 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_1 ( V_17 -> V_52 , true , true , true ,
true , false ) ;
F_7 ( V_15 , V_30 ) ;
F_9 ( V_15 , false ) ;
F_10 ( V_15 , false ) ;
V_17 -> V_26 = 0 ;
V_17 -> V_25 = 0 ;
F_3 ( V_15 ) ;
return 0 ;
}
static int F_43 ( struct V_14 * V_15 ,
unsigned long V_142 )
{
struct V_143 * V_144 = F_44 ( V_15 ) ;
struct V_16 * V_17 ;
struct V_50 * V_51 ;
int V_134 ;
V_17 = F_45 ( V_15 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_145 ;
V_134 = F_46 ( V_15 ) ;
if ( V_134 )
return V_134 ;
V_17 -> V_52 = F_47 ( V_144 , 1 ) ;
V_15 -> V_20 = F_47 ( V_144 , 2 ) ;
F_42 ( V_15 ) ;
if ( V_144 -> V_101 ) {
V_134 = F_48 ( V_144 -> V_101 , F_26 ,
V_146 , V_15 -> V_147 , V_15 ) ;
if ( V_134 == 0 )
V_15 -> V_101 = V_144 -> V_101 ;
}
V_134 = F_49 ( V_15 , 4 ) ;
if ( V_134 )
return V_134 ;
V_51 = & V_15 -> V_148 [ 0 ] ;
V_51 -> type = V_149 ;
V_51 -> V_150 = V_151 | V_152 ;
V_51 -> V_153 = 16 ;
V_51 -> V_97 = 0xffff ;
V_51 -> V_154 = & V_155 ;
V_51 -> V_156 = F_33 ;
if ( V_15 -> V_101 ) {
V_15 -> V_103 = V_51 ;
V_51 -> V_150 |= V_157 ;
V_51 -> V_158 = V_51 -> V_153 ;
V_51 -> V_159 = F_14 ;
V_51 -> V_160 = F_24 ;
V_51 -> V_161 = F_13 ;
V_51 -> V_162 = F_25 ;
}
V_51 = & V_15 -> V_148 [ 1 ] ;
V_51 -> type = V_163 ;
V_51 -> V_150 = V_164 | V_152 ;
V_51 -> V_153 = 1 ;
V_51 -> V_97 = 0x0fff ;
V_51 -> V_158 = 1 ;
V_51 -> V_154 = & V_165 ;
V_51 -> V_166 = F_36 ;
V_51 -> V_156 = F_38 ;
V_51 = & V_15 -> V_148 [ 2 ] ;
V_51 -> type = V_167 ;
V_51 -> V_150 = V_151 ;
V_51 -> V_153 = 16 ;
V_51 -> V_97 = 1 ;
V_51 -> V_154 = & V_168 ;
V_51 -> V_169 = F_39 ;
V_51 = & V_15 -> V_148 [ 3 ] ;
V_51 -> type = V_170 ;
V_51 -> V_150 = V_151 | V_164 ;
V_51 -> V_153 = 16 ;
V_51 -> V_97 = 1 ;
V_51 -> V_154 = & V_168 ;
V_51 -> V_169 = F_40 ;
return 0 ;
}
static void F_50 ( struct V_14 * V_15 )
{
if ( V_15 -> V_20 )
F_42 ( V_15 ) ;
if ( V_15 -> V_101 != 0 )
F_51 ( V_15 -> V_101 , V_15 ) ;
F_52 ( V_15 ) ;
}
static int F_53 ( struct V_143 * V_15 ,
const struct V_171 * V_172 )
{
return F_54 ( V_15 , & V_173 ,
V_172 -> V_174 ) ;
}
